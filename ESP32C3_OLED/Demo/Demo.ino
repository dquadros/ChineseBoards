/*
  Demo for ESP32-C3 mini board with 0.42" OLED Display
  Daniel Quadros May/25

  Select board ESP32C3 Dev Module
*/

#include <Wire.h>
#include "display.h"

Display_042 display;

void setup() {
  Serial.begin(115200);
  delay(3000);
  Wire.begin(5, 6, 200000);
  display.begin();
  delay(1000);
  display.clearDisplay();
  display.drawPixel(0,0);
  display.drawPixel(71,0);
  display.drawPixel(0,39);
  display.drawPixel(71,39);
  display.update();
  delay(3000);
  display.clearDisplay();
  display.drawRect(0, 0, 72, 40);
  display.printText(1, 3, (char *)"DQSoft");
  display.update();
  delay(3000);
  display.clearDisplay(Display_042::WHITE);
  display.drawRect(0, 0, 72, 40, Display_042::BLACK);
  display.printText(1, 3, (char *)"DQSoft", Display_042::BLACK);
  display.update();
  delay(3000);
}

void loop() {
  display.clearDisplay();
  display.update();
  for (int c = 0; c < 30; c++) {
    uint8_t x = random(72);
    display.drawLine(x, 0, 71-x, 39);
    display.update();
    delay(100);
    if (c & 1) {
      uint8_t y = random(40);
      display.drawLine(0, y, 71, 39-y);
      display.update();
      delay(100);
    }
  }
}
