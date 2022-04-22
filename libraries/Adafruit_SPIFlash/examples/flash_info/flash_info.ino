// The MIT License (MIT)
// Copyright (c) 2019 Ha Thach for Adafruit Industries

#define EXTERNAL_FLASH_USE_SPI
#define EXTERNAL_FLASH_USE_CS PB6


#include <SPI.h>
#include "SdFat.h"
#include "Adafruit_SPIFlash.h"

#if defined(GD32F20x)
static SPIClass mflashSPI(PORTB_5,PORTB_4,PORTB_3);
#elif defined(STM32F2xx)
static SPIClass mflashSPI(PB5,PB4,PB3);
#else
#error Unsupported platform!
#endif
Adafruit_FlashTransport_SPI flashTransport(PB6, &mflashSPI);

// On-board external flash (QSPI or SPI) macros should already
// defined in your board variant if supported
// - EXTERNAL_FLASH_USE_QSPI
// - EXTERNAL_FLASH_USE_CS/EXTERNAL_FLASH_USE_SPI


Adafruit_SPIFlash flash(&flashTransport);

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(115200);
    while ( !Serial ) delay(10);   // wait for native usb

    flash.begin();

    Serial.println("Adafruit Serial Flash Info example");
    Serial.print("JEDEC ID: "); Serial.println(flash.getJEDECID(), HEX);
    Serial.print("Flash size: "); Serial.println(flash.size());
}

void loop()
{
    // nothing to do
}
