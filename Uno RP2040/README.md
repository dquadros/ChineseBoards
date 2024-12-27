# Uno RP2040

## English

This is an UNO factor board with a RP2040 microcontroller. No brand, no schematic. "Inspired" by Adafruit's Metro RP2040 board (https://www.adafruit.com/product/5786)?

### Notes

The board can be powered from

* USB-C connector
* DC jack barrel (6V to 12V according the ad)
* Li battery (board includes charger chip)

On the connector there is a VHI pin where the Uno has the 5V pin. This pin will have 5V if the board is powered by the USB-C or DC jack; if it is powered by a battery this pin will have the battery voltage.

There is an On/Off switch, but it will not affect the voltage on the connectors!

The board has a SD card slot, see the pinout for the GPIO connections. The SDIO pins are connected, but software support for it is still experimental.

All signals on the connectors are 3.3V.

The digital pins at the connector follow the GPIO numbered (D2 = GPIO2, D3 = GPIO3, etc) with the following caveats:

* The RP2040 has only 4 analog inputs (GPIO26 to GPIO29), this are connected to A0 to A3 pins in the connectors.
* Where the Uno has A4 ao A5 analog inputs, this board has two digital pins (GPIO24 and GPIO25).
* A switch can exchange GPIO0 and GPIO1 on the connector. The reason behind this is that in the Uno D0 is the UART Rx and and D1 is the UART Tx pin. On the RP2040, GIPO0 is Tx and GPIO1 is Rx.

There are two LED under software control. The first is a normal LED connected to GIPO13. The second is a WS2812B RGB LED connected to GIPO14.

### Files

* Photo and pinout from AliExpress ad.

### Links

Bought from AliExpress: https://pt.aliexpress.com/item/1005007213399267.html

### My Comments

Quality was not great on the boards I bought (connectors were not soldered straight) and the project has its quirks.

Can be a good option if you want to use an Arduino Shield that is compatible with 3.3V signals and does not use the A4/A5 analog inputs.

## Portugues

