# GD32 Arduino Core for BIGTREE_GD_TFT35_E3_V3_0 board


This is a fork of the Arduino core for GD32 MCUs (https://github.com/CommunityGD32Cores/ArduinoCore-GD32)
with support for BIGTREE_GD_TFT35_E3_V3_0 board (https://github.com/bigtreetech/BTT-TFT35-E3-V3.0) which is based on GD32F205 MCU.

Additional resources:
- [GD32F20x User Manual](http://www.gd32mcu.com/download/down/document_id/191/path_type/1)

# Table of Contents

<!-- MarkdownTOC autolink="true" levels="1,2" -->

- [Installation](#installation)
- [Using board hardware](#using-board-hardware)
- [Board Hardware](#board-hardware)
    - [Serial interface](#serial-interface)
    - [I2C interface](#i2c-interface)
    - [Buzzer](#buzzer)
    - [LCD](#lcd)
    - [Touchscreen](#touchscreen)
    - [SDcard Connector](#sdcard-connector)
    - [W25Q64 flash](#w25q64-flash)
    - [Rotary encoder](#rotary-encoder)
    - [USB port](#usb-port)
    - [WS2812](#ws2812)

<!-- /MarkdownTOC -->

## Installation

To compile for this core with the Arduino IDE, add the following URL to the boards manager.

`https://raw.githubusercontent.com/vovan888/ArduinoCore-GD32/main/package_gd32_index.json`

This will install the core and compiler toolchain against the 'main' git branch.

![grafik](https://user-images.githubusercontent.com/26485477/122646653-8b3b2580-d120-11eb-8261-735e0caf00bb.png)


# Using board hardware

Original description: https://github.com/bigtreetech/BTT-TFT35-E3-V3.0/tree/master/Hardware
Pins that can be used in projects can be found in [BTT TFT35-E3 V3.0PIN.pdf](https://github.com/bigtreetech/BTT-TFT35-E3-V3.0/blob/master/Hardware/BTT%20TFT35-E3%20V3.0PIN.pdf).
(Please note that all connectors are displayed on the LCD side)

Some board hardware pins can be found on board connectors (EXP1, EXP2, EXP3), so if you us them as digital outputs you can't use board hardware connected to them.

Board supports flashing over ST-LINK debugger and programmer over SWD interface.  
(https://www.st.com/en/development-tools/st-link-v2.html)  
Driver (https://www.st.com/en/development-tools/stsw-link009.html)  
ST-LINK utility (https://www.st.com/en/development-tools/stsw-link004.html)

You need to connect ST-LINK programmer (pins GND, SWDIO, SWCLK, 3.3V) to SWD connector on the board.
Board can be powered from ST-LINK programmer via 3.3V pin without external power adapter for programming purposes.
When using external power adapter you should disconnect 3.3V pin.

**Warning! Before flashing board with Arduino backup your board flash with ST-LINK utility.
After flashing sketches you will not be able to restore board's original firmware from SD card because original board's bootloader will be overwritten.
Use ST-LINK to restore it if you need to go back to the original firmware.**

How to backup board's flash:
```
1. Connect board to ST-LINK programmer and run ST-LINK utility.
2. Click "Target" -> "Connect" 
3. In field "Address" you should see "0x08000000" . In field "Size" paste "0x40000" and press enter.
4. After that ST-LINK reads controller flash memory to ST-LINK Utility.
5. Now save memory to file. Click "File" -> "Save file as..". Paste filename and press "Save" button.

```


# Board Hardware
## Serial interface
Board has 4 hardware serial outputs. Default Arduino's 'Serial' output is configured to UART4(RX4,TX4) connector on the board. This default can be changed, for example, to the RS232 port by changing "#define SERIAL_UART_INSTANCE 4" to “#define SERIAL_UART_INSTANCE 2” in the variant.h file (i.e. On Windows 10 this file is locate at %AppData%\Local\Arduino15\packages\STM32\hardware\stm32\1.9.0\variants\BIGTREE_F207VCT6 directory).

| Arduino instance   | MCU interface | Board connector | Board pins                                                                                                     |
|--------------------|---------------|-----------------|----------------------------------------------------------------------------------------------------------------|
| Serial1            | USART0        | WIFI            | RX1 and TX1                                                                                                    |
| Serial2 and Serial | USART1        | RS232           | RX2 and TX2 (pins may be labelled wrongly, if this port does not work - try to switch RX2 and TX2 pins around) |
| Serial3            | USART2        | UART3           | RX3 and TX3                                                                                                    |
| Serial4            | UART3         | UART4           | RX4 and TX4                                                                                                    |

Pins:
```
PA10 SERIAL_RX1
PA9 SERIAL_TX1

PA3 SERIAL_RX2
PA2 SERIAL_TX2

PB11 SERIAL_RX3
PB10 SERIAL_TX3

PC11 SERIAL_RX4
PC10 SERIAL_TX4
```

Can be used as standard [Arduino serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/) ports:
```
Serial.begin(115200);   
Serial.println("Test");  

//for other serial outputs use instance Serial1 .. Serial4:
// Serial1.begin(115200);
// Serial1.print("Test");
```

## I2C interface
I2C interface uses the same pins as Serial3. So both USART2 and I2C1 cannot be used at the same time.
```
PIN_WIRE_SDA            PB11
PIN_WIRE_SCL            PB10
```
Use builtin library [Wire](https://www.arduino.cc/en/reference/wire).

## Buzzer
Pin:
```
PD13 BUZZER_PIN 
```
Standard Arduino function [tone()](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/) can be used:
```
tone(PD13, Note, noteDuration);
```

Example:
```
tone(PD13, 440, 500);   // play 440Hz for 500ms
```

## LCD
LCD is connected to 16-bit parallel port in EXMC (External Memory Controller) mode. For more details see "GD32F20x User Manual"

Pins:
```
PD12 LED_BUILTIN # LCD backlight brightness control
```
Brightness can be controlled by :
 ```
 int brightness = xx; where xx from 0 to 255
 pinMode(PD12, OUTPUT);
 analogWrite(PD12, brightness);
 or 
 digitalwrite(PD12, HIGH); for 100% brightness
```
Board is supported by modified Adafruit_TFTLCD_16bit_GD32 (embedded into the platform, no installation needed).
Adafruit_TFTLCD_16bit_GD32 library uses [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) (This is the core graphics library for all Adafruit displays, providing a common set of graphics primitives (points, lines, circles, etc.). So you can easy migrate your sketches with Adafruit displays to this board.

Original library:
[Adafruit_TFTLCD_16bit_STM32](https://github.com/stevstrong/Adafruit_TFTLCD_16bit_STM32)  

### 1. Adafruit_TFTLCD_16bit_STM32

Install "Adafruit GFX" and "Adafruit BusIO" libraries from Arduino Library Manager. And use Adafruit_TFTLCD_16bit_GD32 library.

Example:  
[TFT35-E3-graphicstest.ino](libraries/Adafruit_TFTLCD_16bit_GD32/examples/TFT35-E3-graphicstest/TFT35-E3-graphicstest.ino)


### FSMC GPIO Configuration

The following pins are already configured in libraries and they can`t be used in sketches:
 ```
  PE2   ------> FSMC_A23
  PE7   ------> FSMC_D4
  PE8   ------> FSMC_D5
  PE9   ------> FSMC_D6
  PE10   ------> FSMC_D7
  PE11   ------> FSMC_D8
  PE12   ------> FSMC_D9
  PE13   ------> FSMC_D10
  PE14   ------> FSMC_D11
  PE15   ------> FSMC_D12
  PD8   ------> FSMC_D13
  PD9   ------> FSMC_D14
  PD10   ------> FSMC_D15
  PD14   ------> FSMC_D0
  PD15   ------> FSMC_D1
  PD0   ------> FSMC_D2
  PD1   ------> FSMC_D3
  PD4   ------> FSMC_NOE
  PD5   ------> FSMC_NWE
  PD7   ------> FSMC_NE1
 ```

## Touchscreen
Touchscreen is connected to XPT2046 chip via software SPI interface.

Install library [SoftSPIB](https://github.com/red-scorp/SoftSPIB) from Arduino Library Manager.
Use library [XPT2046_Touchscreen_SWSPI](libraries/XPT2046_Touchscreen_SWSPI) (fork of XPT2046_Touchscreen library by Paul Stoffregen https://github.com/PaulStoffregen/XPT2046_Touchscreen). This library is embedded into the platform, no additional installation needed.

Example:  
[TouchTest.ino](libraries/XPT2046_Touchscreen_SWSPI/examples/TouchTest/TouchTest.ino)

Pins: (can be used in other libraries or sketches if touchscreen is not used)
```
PC13  XPT2046_TPEN 	
PE3   XPT2046_MOSI
PE4   XPT2046_MISO
PE5   XPT2046_SCK 
PE6   XPT2046_CS 
```

## SDcard Connector
Install library 'Adafruit_SPIFlash' from Arduino Library Manager ("SdFat_-_Adafruit_Fork" library will also be installed).
SD card can work with standard Arduino library ["SD"](https://www.arduino.cc/en/reference/SD) via default "SPI" interface.

Note: Card must be formatted in FAT16 or FAT32 filesystem. Use SDcard formatter from utilites [SDCardFormatterv5_WinEN](utilites/SDCardFormatterv5_WinEN.zip)


Pins:
```
PC4  CARD DETECT PIN
PA4  SPI CS_PIN
PA5  SPI SCK_PIN 
PA6  SPI MISO_PIN 
PA7  SPI MOSI_PIN 
```

Using SPI interface in Adafruit_SPIFlash library:
```
SdFat sd(&SPI);
#define SD_CS PA4
...
//some code
...
sd.begin(SD_CS, SD_SCK_MHZ(50));
```



## W25Q64 flash

Flash chip is connected via hardware SPI3 interface.  
The chip is BoyaMicro BY25Q64AS 8MByte SPI flash. Use Adafruit_SPIFlash library which is embedded into this platform, no additional installation needed.

Pins:
```
PB6 PIN_SPI_SS              
PB5 PIN_SPI_MOSI            
PB4 PIN_SPI_MISO            
PB3 PIN_SPI_SCK             
```

Using SPI interface in Adafruit_SPIFlash library:
 ```
 //define spi interface and flash transport
 SPIClass mflashSPI(PB5, PB4, PB3);
 Adafruit_FlashTransport_SPI flashTransport(PB6, &mflashSPI);
 
 // now you can use flash
 Adafruit_SPIFlash flash(&flashTransport);
 ```

Examples:
- [flash_info.ino](libraries/Adafruit_SPIFlash/examples/flash_info/flash_info.ino)


## Rotary encoder

Pins:
```
PC8 Button
PA8 ENCA 
PC9 ENCB 
```

Example:
[encoder_test.ino](https://github.com/ns96/BTuino/blob/master/examples/encoder_test/encoder_test.ino)


## USB port

Core supports GD32 as a USB host, with FatFs support. Just use embedded FatFs library.

To use USB as default 'Serial' port:
1. Select Tools -> USB Support -> USB Host

Example: [FatFsTest.ino](libraries/FatFs/examples/FatFsTest/FatFsTest.ino)

## WS2812
Board has 2 NEOPIXEL RGB LEDs located under the rotary encoder's knob.

Pin:
 ```
 PC7 
 ```
Use embedded "Adafruit_NeoPixel" library, no additional installation needed.
Define pin and number of neopixels.
 ```
 // Which pin on the Arduino is connected to the NeoPixels?
#define PIN        PC7 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 4 // Popular NeoPixel ring size
 ```
Example:
[neopixel-simple.ino](https://github.com/ns96/BTuino/blob/master/examples/neopixel-simple/neopixel-simple.ino)