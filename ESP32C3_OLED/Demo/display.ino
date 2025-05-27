/*
  Mini driver for 0.42" OLED Display
*/

#include "font_6x8.h"

// Commands
#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Bit mask to get the bit associated to pixel at y
#define PIXEL_MASK(y) (1 << (y & 7))

const uint8_t cmdInit[] =
{
  SSD1306_DISPLAYOFF,
  SSD1306_SETDISPLAYCLOCKDIV, 0x80,
  SSD1306_SETMULTIPLEX, 0x3F,
  SSD1306_SETDISPLAYOFFSET, 0x00,
  SSD1306_SETSTARTLINE | 0x0,
  SSD1306_CHARGEPUMP, 0x14,
  SSD1306_MEMORYMODE, 0x00,
  SSD1306_SEGREMAP | 0x1,
  SSD1306_COMSCANDEC,
  SSD1306_SETCOMPINS, 0x12,
  SSD1306_SETCONTRAST, 0xCF,
  SSD1306_SETPRECHARGE, 0xF1,
  SSD1306_SETVCOMDETECT, 0x40,
  SSD1306_DISPLAYALLON_RESUME,
  SSD1306_NORMALDISPLAY,
  SSD1306_DISPLAYON
};

// Constructor
Display_042::Display_042(uint8_t w, uint8_t h, uint8_t off_x, uint8_t off_y, uint8_t addr, TwoWire *twi) {
  width = w;
  height = h;
  offset_x = off_x;
  offset_y = off_y;
  i2c_addr = addr;
  i2c = twi;
  bufsize = w*h/8;
  buffer = (uint8_t *) malloc (bufsize);
}

// Initialize display controller
void Display_042::begin() {
  sendCmd(SSD1306_DISPLAYOFF);
  sendCmd(cmdInit, sizeof(cmdInit));
  clearDisplay(BLACK);
  update();
}

// Clear display buffer
void Display_042::clearDisplay(bool color) {
  memset (buffer, color? 0xFF : 0, bufsize);
}

// Update screen from buffer
void Display_042::update() {
  for (uint8_t page = 0; page < height/8; page++) {
    sendCmd (SSD1306_COLUMNADDR);
    sendCmd (offset_x);
    sendCmd (offset_x+width-1);
    sendCmd (SSD1306_PAGEADDR);
    sendCmd (page+offset_y/8);
    sendCmd (page+offset_y/8);
    for (uint8_t x = 0; x < width; ) {
      i2c->beginTransmission(i2c_addr);
      i2c->write (0x40);  // Co = 0, DC = 1
      for (uint8_t i = 0; i < 8; i++) {
        i2c->write(buffer[page*width+x]);
        x++;
      }
      i2c->endTransmission();
    }
  }
}

// Draw a pixel at (x, y)
void Display_042::drawPixel(uint8_t x, uint8_t y, bool color) {
  uint pos = (y>>3)*width+x;
  if (color) {
    buffer[pos] |= PIXEL_MASK(y);
  } else {
    buffer[pos] &= ~PIXEL_MASK(y);
  }
}

// Draw a line from (x1, y1) to (x2, y2)
void Display_042::drawLine(uint8_t x1, uint8_t y1,  uint8_t x2, uint8_t y2, bool color) {
  uint8_t aux;

  if (y1 == y2) {
    // Horizontal line
    if (x1 > x2) {
      aux = x1; x1 = x2; x2 = aux;
    }
    uint pos = (y1>>3)*width+x1;
    uint8_t mask = PIXEL_MASK(y1);
    while (x1 <= x2) {
      buffer[pos] = color? (buffer[pos] | mask) : (buffer[pos] & ~mask);
      pos++;
      x1++;
    }
  } else if (x1 == x2) {
    // Vertical line
    if (y1 > y2) {
      aux = y1; y1 = y2; y2 = aux;
    }
    while (y1 <= y2) {
      uint pos = (y1>>3)*width+x1;
      uint8_t mask = PIXEL_MASK(y1);
      buffer[pos] = color? (buffer[pos] | mask) : (buffer[pos] & ~mask);
      y1++;
    }
  } else {
    // Bresenham algorithm, adapted from PC Assembler - Graficos e Sons
    if (x1 > x2) {
      aux = x1; x1 = x2; x2 = aux;
      aux = y1; y1 = y2; y2 = aux;
    }
    int dx = x2-x1;
    int dy = y2-y1;
    int x = x1;
    int y = y1;
    int stepy, incx, incy;
    if (dy < 0) {
      dy = -dy;
      stepy = -1;
    } else {
      stepy = 1;
    }
    if (dx >= dy) {
      int d = (dy << 1) - dx;
      incx = dy << 1;
      incy = incx - (dx << 1);
      while (true) {
        drawPixel(x, y, color);
        if (x == x2) {
          break;
        }
        x++;
        if (d >= 0) {
          y += stepy;
          d += incy;
        } else {
          d += incx;
        }
      }
    } else {
      int d = (dx << 1) - dy;
      incy = dx << 1;
      incx = incy - (dy << 1);
      while (true) {
        drawPixel(x, y, color);
        if (y == y2) {
          break;
        }
        y += stepy;
        if (d >= 0) {
          x++;
          d += incx;
        } else {
          d += incy;
        }
      }
    }
  }
 
}

// Draw a rectangle starting at (x, y) with size (dx, dy)
void Display_042::drawRect(uint8_t x, uint8_t y,  uint8_t dx, uint8_t dy, bool color) {
  drawLine(x, y, x+dx-1, y, color);
  drawLine(x, y+dy-1, x+dx-1, y+dy-1, color);
  drawLine(x, y, x, y+dy-1, color);
  drawLine(x+dx-1, y, x+dx-1, y+dy-1, color);
}

// Print a char using 8x8 font starting at l*8, c*8
void Display_042::printChar(uint8_t l, uint8_t c, char car, bool color) {
  const uint8_t *gc = &fontdata[(car-0x20)*6];
  uint8_t *pos = buffer+l*width+c*6;
  for (uint8_t x = 0;  x < 6; x++) 
  {
    *pos = color? (*pos | *gc) : (*pos & ~*gc);
    pos++;
    gc++;
  }
}
// Print text using 6x8 font starting at l*8, c*6
void Display_042::printText(uint8_t l, uint8_t c, char*text, bool color) {
  while (*text) {
    printChar(l, c, *text, color);
    text++;
    if (++c == width/6) {
      c = 0;
      if (++l == height/8) {
        l = 0;
      }
    }
  }
}

bool Display_042::getPixel(uint8_t x, uint8_t y) {
  uint pos = (y>>3)*width+x;
  return (buffer[pos] & (1 << (y & 7))) != 0;
}

// Envia sequência de comandos ao display
void Display_042::sendCmd (const uint8_t *cmd, int nCmds)
{
  //Serial.print("SendCmds {");
  i2c->beginTransmission(i2c_addr);
  i2c->write (0);  // Co= 0. DC = 0
  for (int i = 0; i < nCmds; i++)
  {
    //Serial.print(cmd[i], HEX);
    //Serial.print(' ');
    i2c->write(cmd[i]);
  }
  i2c->endTransmission();
  //Serial.println("}");
}

// Envia um byte de comando ao display
void Display_042::sendCmd (uint8_t cmd)
{
  //Serial.print("SendCmd: ");
  //Serial.println(cmd, HEX);
  i2c->beginTransmission(i2c_addr);
  i2c->write (0x00);  // Co= 1. DC = 0
  i2c->write(cmd);
  i2c->endTransmission();
}
