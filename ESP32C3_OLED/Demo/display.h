/*
  Mini driver for 0.42" OLED Display
*/

#ifndef _DISPLAY_042_H

#define _DISPLAY_042_H

class Display_042 {
  public:
    static const bool WHITE=true;
    static const bool BLACK=false;

    Display_042(uint8_t w = 72, uint8_t h = 40, uint8_t off_x = 28, uint8_t off_y = 24, uint8_t addr=0x3C, TwoWire *twi = &Wire);
    void begin();
    void clearDisplay(bool color=BLACK);
    void update();
    void drawPixel(uint8_t x, uint8_t y, bool color=WHITE);
    void drawLine(uint8_t x1, uint8_t y1,  uint8_t x2, uint8_t y2, bool color=WHITE);
    void drawRect(uint8_t x, uint8_t y,  uint8_t dx, uint8_t dy, bool color=WHITE);
    void printChar(uint8_t l, uint8_t c, char car, bool color=WHITE);
    void printText(uint8_t l, uint8_t c, char*text, bool color=WHITE);
    bool getPixel(uint8_t x, uint8_t y);

  protected:
    uint bufsize;
    uint8_t *buffer;
    uint8_t width;
    uint8_t height;
    uint8_t offset_x;
    uint8_t offset_y;
    uint8_t i2c_addr;
    TwoWire *i2c;

    void sendCmd (const uint8_t *cmd, int nCmds);
    void sendCmd(uint8_t cmd);
};

#endif
