/*
    Copyright (c) 2020, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software without
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/

#ifndef _VARIANT_
#define _VARIANT_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/


#define   PC7    0
#define   PC6    1
#define   PB13    2
#define   PB14    3
#define   PB15    4
#define   PB12    5
#define   PD13    6
#define   PC8    7
#define   PC4    8
#define   PC9    9
#define   PA7    10
#define   PA8    11
#define   PA4    12
#define   PA6    13
#define   PA5    14
#define   PA9    15
#define   PD3    16
#define   PD2    17
#define   PA10    18
#define   PA2    19
#define   PA3    20
#define   PC12    21
#define   PC11    22
#define   PC10    23
#define   PA15    24
#define   PB11    25
#define   PB10    26
#define   PD12    27
#define   PD7    28
#define   PE2    29
#define   PD4    30
#define   PD5    31
#define   PB1    32

//XPT2046 pins
#define   PC13    33
#define   PE3    34
#define   PE4    35
#define   PE5    36
#define   PE6    37

//SPI FLASH , SPI2
#define   PB3    38
#define   PB4    39
#define   PB5    40
#define   PB6    41

#define DIGITAL_PINS_NUM        42
#define ANALOG_PINS_NUM         2
#define ANALOG_PINS_START       19
#define ANALOG_PINS_LAST        20

// On-board user button
#define USER_BTN                PC8

// LCD backlight brightness control
#define LED_BUILTIN             PD12


//SD card
#define SD_DETECT_PIN           PC4

// SPI Definitions

#define PIN_SPI_SS              PA4
#define PIN_SPI_MOSI            PA7
#define PIN_SPI_MISO            PA6
#define PIN_SPI_SCK             PA5

/*
#define PIN_SPI_SS              PB6
#define PIN_SPI_MOSI            PB5
#define PIN_SPI_MISO            PB4
#define PIN_SPI_SCK             PB3
*/


// I2C Definitions
#define USE_I2C       1
// I2C1 interface
// (the same pins as USART2)
#define PIN_WIRE_SDA            PB11
#define PIN_WIRE_SCL            PB10

// Timer Definitions
#define TIMER_TONE              TIMER2

// UART Definitions
// hardware: UART3, Arduino: Serial
//#define USE_USART0_SERIAL
#define PIN_SERIAL_RX            PC11
#define PIN_SERIAL_TX            PC10
//#define SERIAL0_RX               PIN_SERIAL_RX
//#define SERIAL0_TX               PIN_SERIAL_TX
//#define SERIAL0_UART_INDEX       (3)

// hardware: USART0, Arduino: Serial1
#define USE_USART1_SERIAL
#define PIN_SERIAL1_RX           PA10
#define PIN_SERIAL1_TX           PA9
#define SERIAL1_RX               PIN_SERIAL1_RX
#define SERIAL1_TX               PIN_SERIAL1_TX
#define SERIAL1_UART_INDEX       (0)

// hardware USART1, Arduino: Serial2
#define USE_USART2_SERIAL
#define PIN_SERIAL2_RX           PA3
#define PIN_SERIAL2_TX           PA2
#define RX2                      PIN_SERIAL2_RX
#define TX2                      PIN_SERIAL2_TX
#define SERIAL2_UART_INDEX       (1)

// hardware USART2, Arduino: Serial3
#define USE_USART3_SERIAL
#define PIN_SERIAL3_RX           PB11
#define PIN_SERIAL3_TX           PB10
#define RX3                      PIN_SERIAL3_RX
#define TX3                      PIN_SERIAL3_TX
#define SERIAL3_UART_INDEX       (2)

// hardware UART3, Arduino: Serial4
#define USE_USART4_SERIAL
#define PIN_SERIAL4_RX           PC11
#define PIN_SERIAL4_TX           PC10
#define RX4                      PIN_SERIAL4_RX
#define TX4                      PIN_SERIAL4_TX
#define SERIAL4_UART_INDEX       (3)

// use Serial2 as default Serial
#define Serial                   Serial2

/* ADC definitions */
#define ADC_RESOLUTION          10
#define DAC_RESOLUTION          12


/* USB host definitions */
// VBUS switching not used on this board
//#define HOST_POWERSW_PORT      GPIOD
//#define HOST_POWERSW_VBUS      GPIO_PIN_2
//#define HOST_POWERSW_PORT_RCC  RCU_GPIOD


#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
/* Port which normally prints to the Arduino Serial Monitor */
#define SERIAL_PORT_MONITOR     Serial
/* Hardware serial port, physical RX & TX pins. */
#define SERIAL_PORT_HARDWARE    Serial1
#endif

#endif /* _VARIANT_ */
