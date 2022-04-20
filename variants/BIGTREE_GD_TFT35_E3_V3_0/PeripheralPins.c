/* mbed Microcontroller Library
 * Copyright (c) 2018 GigaDevice Semiconductor Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PeripheralPins.h"


/*  void pin_function(PinName pin, int function);
    configure the speed, mode,and remap function of pins
    the parameter function contains the configuration information,show as below
    bit 0:2   gpio mode
    bit 3:8   remap
    bit 9:10  gpio speed
    bit 11:15 adc  /timer channel
*/
const int GD_GPIO_REMAP[] = {
        0x00000000,
        GPIO_SPI0_REMAP,               /* 1 */
        GPIO_I2C0_REMAP,               /* 2 */
        GPIO_USART0_REMAP,             /* 3 */
        GPIO_USART1_REMAP,             /* 4 */
        GPIO_USART2_PARTIAL_REMAP,     /* 5 */
        GPIO_USART2_FULL_REMAP,        /* 6 */
        GPIO_TIMER0_PARTIAL_REMAP,     /* 7 */
        GPIO_TIMER0_FULL_REMAP,        /* 8 */
        GPIO_TIMER1_PARTIAL_REMAP0,    /* 9 */
        GPIO_TIMER1_PARTIAL_REMAP1,    /* 10 */
        GPIO_TIMER1_FULL_REMAP,        /* 11 */
        GPIO_TIMER2_PARTIAL_REMAP,     /* 12 */
        GPIO_TIMER2_FULL_REMAP,        /* 13 */
        GPIO_TIMER3_REMAP,             /* 14 */
        GPIO_CAN0_PARTIAL_REMAP,       /* 15 */
        GPIO_CAN0_FULL_REMAP,          /* 16 */
        GPIO_PD01_REMAP,               /* 17 */
        GPIO_TIMER4CH3_IREMAP,         /* 18 */
        GPIO_ADC0_ETRGINS_REMAP,       /* 19 */
        GPIO_ADC0_ETRGREG_REMAP,       /* 20 */
        GPIO_ADC1_ETRGINS_REMAP,       /* 21 */
        GPIO_ADC1_ETRGREG_REMAP,       /* 22 */
        GPIO_ENET_REMAP,               /* 23 */
        GPIO_CAN1_REMAP,               /* 24 */
        GPIO_SWJ_NONJTRST_REMAP,       /* 25 */
        GPIO_SWJ_SWDPENABLE_REMAP,     /* 26 */
        GPIO_SWJ_DISABLE_REMAP,        /* 27 */
        GPIO_SPI2_REMAP,               /* 28 */
        GPIO_TIMER1ITI1_REMAP,         /* 29 */
        GPIO_PTP_PPS_REMAP,            /* 30 */
        GPIO_TIMER8_REMAP,             /* 31 */
        GPIO_TIMER9_REMAP,             /* 32 */
        GPIO_TIMER10_REMAP,            /* 33 */
        GPIO_TIMER12_REMAP,            /* 34 */
        GPIO_TIMER13_REMAP,            /* 35 */
        GPIO_EXMC_NADV_REMAP,          /* 36 */
};

/* GPIO MODE, see enum GD32PinMode for index values */
const int GD_GPIO_MODE[] = {
        GPIO_MODE_AIN,                /* 0 PIN_MODE_AIN */
        GPIO_MODE_IN_FLOATING,        /* 1 PIN_MODE_IN_FLOATING */
        GPIO_MODE_IPD,                /* 2 PIN_MODE_IPD */
        GPIO_MODE_IPU,                /* 3 PIN_MODE_IPU */
        GPIO_MODE_OUT_OD,             /* 4 PIN_MODE_OUT_OD */
        GPIO_MODE_OUT_PP,             /* 5 PIN_MODE_OUT_PP */
        GPIO_MODE_AF_OD,              /* 6 PIN_MODE_AF_OD */
        GPIO_MODE_AF_PP,              /* 7 PIN_MODE_AF_PP */
};

/* GPIO SPEED */
const int GD_GPIO_SPEED[] = {
        GPIO_OSPEED_50MHZ,            /* 0 */
        GPIO_OSPEED_10MHZ,            /* 1 */
        GPIO_OSPEED_2MHZ,             /* 2 */
};

#define GD_PIN_FUNCTION(mode,remap,speed,channel) ((int)((mode) & PIN_MODE_MASK) \
                        | (((remap) & PIN_REMAP_MASK) << PIN_REMAP_SHIFT)        \
                        | (((speed) & PIN_SPEED_MASK) << PIN_SPEED_SHIFT)        \
                        | (((channel) & PIN_CHANNEL_MASK) << PIN_CHANNEL_SHIFT))
#define GD_PIN_FUNCTION_ANALOG(CHN)  GD_PIN_FUNCTION(PIN_MODE_AIN, 0, 0, CHN)
#define GD_PIN_FUNCTION_REMAP(mode, remap)  GD_PIN_FUNCTION(mode, remap, 2, 0)


/* ADC PinMap */
const PinMap PinMap_ADC[] = {
        {PORTA_0, ADC0, GD_PIN_FUNCTION_ANALOG(0)},    /* ADC0_IN0 */
        {PORTA_1, ADC0, GD_PIN_FUNCTION_ANALOG(1)},    /* ADC0_IN1 */
        {PORTA_2, ADC0, GD_PIN_FUNCTION_ANALOG(2)},    /* ADC0_IN2 */
        {PORTA_3, ADC0, GD_PIN_FUNCTION_ANALOG(3)},    /* ADC0_IN3 */
        {PORTA_4, ADC0, GD_PIN_FUNCTION_ANALOG(4)},    /* ADC0_IN4 */
        {PORTA_5, ADC0, GD_PIN_FUNCTION_ANALOG(5)},    /* ADC0_IN5 */
        {PORTA_6, ADC0, GD_PIN_FUNCTION_ANALOG(6)},    /* ADC0_IN6 */
        {PORTA_7, ADC0, GD_PIN_FUNCTION_ANALOG(7)},    /* ADC0_IN7 */
        {PORTB_0, ADC0, GD_PIN_FUNCTION_ANALOG(8)},    /* ADC0_IN8 */
        {PORTB_1, ADC0, GD_PIN_FUNCTION_ANALOG(9)},    /* ADC0_IN9 */
        {PORTC_0, ADC0, GD_PIN_FUNCTION_ANALOG(10)},   /* ADC0_IN10 */
        {PORTC_1, ADC0, GD_PIN_FUNCTION_ANALOG(11)},   /* ADC0_IN11 */
        {PORTC_2, ADC0, GD_PIN_FUNCTION_ANALOG(12)},   /* ADC0_IN12 */
        {PORTC_3, ADC0, GD_PIN_FUNCTION_ANALOG(13)},   /* ADC0_IN13 */
        {PORTC_4, ADC0, GD_PIN_FUNCTION_ANALOG(14)},   /* ADC0_IN14 */
        {PORTC_5, ADC0, GD_PIN_FUNCTION_ANALOG(15)},   /* ADC0_IN15 */
        {ADC_TEMP, ADC0, GD_PIN_FUNCTION_ANALOG(16)},  /* ADC0_IN16 */
        {ADC_VREF, ADC0, GD_PIN_FUNCTION_ANALOG(17)},  /* ADC0_IN17 */

        {PORTA_0, ADC1, GD_PIN_FUNCTION_ANALOG(0)},   /* ADC1_IN0 */
        {PORTA_1, ADC1, GD_PIN_FUNCTION_ANALOG(1)},   /* ADC1_IN1 */
        {PORTA_2, ADC1, GD_PIN_FUNCTION_ANALOG(2)},   /* ADC1_IN2 */
        {PORTA_3, ADC1, GD_PIN_FUNCTION_ANALOG(3)},   /* ADC1_IN3 */
        {PORTA_4, ADC1, GD_PIN_FUNCTION_ANALOG(4)},   /* ADC1_IN4 */
        {PORTA_5, ADC1, GD_PIN_FUNCTION_ANALOG(5)},   /* ADC1_IN5 */
        {PORTA_6, ADC1, GD_PIN_FUNCTION_ANALOG(6)},   /* ADC1_IN6 */
        {PORTA_7, ADC1, GD_PIN_FUNCTION_ANALOG(7)},   /* ADC1_IN7 */
        {PORTB_0, ADC1, GD_PIN_FUNCTION_ANALOG(8)},   /* ADC1_IN8 */
        {PORTB_1, ADC1, GD_PIN_FUNCTION_ANALOG(9)},   /* ADC1_IN9 */
        {PORTC_0, ADC1, GD_PIN_FUNCTION_ANALOG(10)},  /* ADC1_IN10 */
        {PORTC_1, ADC1, GD_PIN_FUNCTION_ANALOG(11)},  /* ADC1_IN11 */
        {PORTC_2, ADC1, GD_PIN_FUNCTION_ANALOG(12)},  /* ADC1_IN12 */
        {PORTC_3, ADC1, GD_PIN_FUNCTION_ANALOG(13)},  /* ADC1_IN13 */
        {PORTC_4, ADC1, GD_PIN_FUNCTION_ANALOG(14)},  /* ADC1_IN14 */
        {PORTC_5, ADC1, GD_PIN_FUNCTION_ANALOG(15)},  /* ADC1_IN15 */

        {PORTA_0, ADC2, GD_PIN_FUNCTION_ANALOG(0)},   /* ADC2_IN0 */
        {PORTA_1, ADC2, GD_PIN_FUNCTION_ANALOG(1)},   /* ADC2_IN1 */
        {PORTA_2, ADC2, GD_PIN_FUNCTION_ANALOG(2)},   /* ADC2_IN2 */
        {PORTA_3, ADC2, GD_PIN_FUNCTION_ANALOG(3)},   /* ADC2_IN3 */
        {PORTA_4, ADC2, GD_PIN_FUNCTION_ANALOG(4)},   /* ADC2_IN4 */
        {PORTA_5, ADC2, GD_PIN_FUNCTION_ANALOG(5)},   /* ADC2_IN5 */
        {PORTA_6, ADC2, GD_PIN_FUNCTION_ANALOG(6)},   /* ADC2_IN6 */
        {PORTA_7, ADC2, GD_PIN_FUNCTION_ANALOG(7)},   /* ADC2_IN7 */
        {PORTB_0, ADC2, GD_PIN_FUNCTION_ANALOG(8)},   /* ADC2_IN8 */
        {PORTB_1, ADC2, GD_PIN_FUNCTION_ANALOG(9)},   /* ADC2_IN9 */
        {PORTC_0, ADC2, GD_PIN_FUNCTION_ANALOG(10)},  /* ADC2_IN10 */
        {PORTC_1, ADC2, GD_PIN_FUNCTION_ANALOG(11)},  /* ADC2_IN11 */
        {PORTC_2, ADC2, GD_PIN_FUNCTION_ANALOG(12)},  /* ADC2_IN12 */
        {PORTC_3, ADC2, GD_PIN_FUNCTION_ANALOG(13)},  /* ADC2_IN13 */
        {PORTC_4, ADC2, GD_PIN_FUNCTION_ANALOG(14)},  /* ADC2_IN14 */
        {PORTC_5, ADC2, GD_PIN_FUNCTION_ANALOG(15)},  /* ADC2_IN15 */
        {NC,   NC,    0}
};

/* DAC PinMap */
const PinMap PinMap_DAC[] = {
        {PORTA_4,       DAC0, GD_PIN_FUNCTION_ANALOG(0)},    /* DAC_OUT0 */
        {PORTA_5,       DAC1, GD_PIN_FUNCTION_ANALOG(1)},    /* DAC_OUT1 */
        {NC, NC, 0}
};


/* I2C PinMap */
const PinMap PinMap_I2C_SDA[] = {
        {PORTB_7,  I2C0, 6},
        {PORTB_9,  I2C0, 6 | (2 << 3)},    /* GPIO_I2C0_REMAP */
        {PORTB_11, I2C1, 6},
        {PORTC_9,  I2C2, 6 | (43 << 3)},    /* GPIO_PCF5_I2C2_REMAP1 */
        {NC,    NC,    0}
};

const PinMap PinMap_I2C_SCL[] = {
        {PORTB_6,  I2C0, 6},
        {PORTB_8,  I2C0, 6 | (2 << 3)},    /* GPIO_I2C0_REMAP */
        {PORTB_10, I2C1, 6},
        {PORTA_8,  I2C2, 6 | (43 << 3)},   /* GPIO_PCF5_I2C2_REMAP1 */
        {NC,    NC,    0}
};

/* PWM PinMap */
// FIXME
const PinMap PinMap_PWM[] = {
        {PORTA_8,  TIMER0, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER0_CH0 - Default */
        {PORTA_9,  TIMER0, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER0_CH1 - Default */
        {PORTA_10, TIMER0, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER0_CH2 - Default */
        {PORTA_11, TIMER0, 7 | (3 << PIN_CHANNEL_SHIFT)},                      /* TIMER0_CH3 - Default */
        {PORTE_9,  TIMER0, 7 | (8 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},           /* TIMER0_CH0 - GPIO_TIMER0_FULL_REMAP */
        {PORTE_11, TIMER0, 7 | (8 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},           /* TIMER0_CH1 - GPIO_TIMER0_FULL_REMAP */
        {PORTE_13, TIMER0, 7 | (8 << PIN_REMAP_SHIFT) | (2 << PIN_CHANNEL_SHIFT)},           /* TIMER0_CH2 - GPIO_TIMER0_FULL_REMAP */
        {PORTE_14, TIMER0, 7 | (8 << PIN_REMAP_SHIFT) | (3 << PIN_CHANNEL_SHIFT)},           /* TIMER0_CH3 - GPIO_TIMER0_FULL_REMAP */

        {PORTA_0,  TIMER1, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER1_CH0_ETI - Default */
        {PORTA_1,  TIMER1, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER1_CH1_ETI - Default */
        {PORTA_2,  TIMER1, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER1_CH2_ETI - Default */
        {PORTA_3,  TIMER1, 7 | (3 << PIN_OUTPUT_MODE_SHIFT)},                      /* TIMER1_CH3_ETI - Default */
        {PORTA_15, TIMER1, 7 | (9 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},           /* TIMER1_CH0_ETI- GPIO_TIMER1_PARTIAL_REMAP0 */
        {PORTB_3,  TIMER1, 7 | (9 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},           /* TIMER1_CH1 - GPIO_TIMER1_PARTIAL_REMAP0 */
        {PORTB_10, TIMER1, 7 | (10 << PIN_REMAP_SHIFT) | (2 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH2 - GPIO_TIMER1_PARTIAL_REMAP1 */
        {PORTB_11, TIMER1, 7 | (10 << PIN_REMAP_SHIFT) | (3 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH3 - GPIO_TIMER1_PARTIAL_REMAP1 */
        {PORTA_15, TIMER1, 7 | (11 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH0_ETI - GPIO_TIMER1_FULL_REMAP */
        {PORTB_3,  TIMER1, 7 | (11 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH1 - GPIO_TIMER1_FULL_REMAP */
        {PORTB_10, TIMER1, 7 | (11 << PIN_REMAP_SHIFT) | (2 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH2 - GPIO_TIMER1_FULL_REMAP */
        {PORTB_11, TIMER1, 7 | (11 << PIN_REMAP_SHIFT) | (3 << PIN_CHANNEL_SHIFT)},          /* TIMER1_CH3 - GPIO_TIMER1_FULL_REMAP */

        {PORTA_6,  TIMER2, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER2_CH0 - Default */
        {PORTA_7,  TIMER2, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER2_CH1 - Default */
        {PORTB_0,  TIMER2, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER2_CH2 - Default */
        {PORTB_1,  TIMER2, 7 | (3 << PIN_CHANNEL_SHIFT)},                      /* TIMER2_CH3 - Default */
        {PORTB_4,  TIMER2, 7 | (12 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH0 - GPIO_TIMER2_PARTIAL_REMAP */
        {PORTB_5,  TIMER2, 7 | (12 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH1 - GPIO_TIMER2_PARTIAL_REMAP */
        {PORTC_6,  TIMER2, 7 | (13 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH0 - GPIO_TIMER2_FULL_REMAP */
        {PORTC_7,  TIMER2, 7 | (13 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH1 - GPIO_TIMER2_FULL_REMAP */
        {PORTC_8,  TIMER2, 7 | (13 << PIN_REMAP_SHIFT) | (2 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH2 - GPIO_TIMER2_FULL_REMAP */
        {PORTC_9,  TIMER2, 7 | (13 << PIN_REMAP_SHIFT) | (3 << PIN_CHANNEL_SHIFT)},          /* TIMER2_CH3 - GPIO_TIMER2_FULL_REMAP */

        {PORTB_6,  TIMER3, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER3_CH0 - Default */
        {PORTB_7,  TIMER3, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER3_CH1 - Default */
        {PORTB_8,  TIMER3, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER3_CH2 - Default */
        {PORTB_9,  TIMER3, 7 | (3 << PIN_CHANNEL_SHIFT)},                      /* TIMER3_CH3 - Default */
        {PORTD_12, TIMER3, 7 | (14 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},          /* TIMER3_CH0 - GPIO_TIMER3_REMAP */
        {PORTD_13, TIMER3, 7 | (14 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},          /* TIMER3_CH1 - GPIO_TIMER3_REMAP */
        {PORTD_14, TIMER3, 7 | (14 << PIN_REMAP_SHIFT) | (2 << PIN_CHANNEL_SHIFT)},          /* TIMER3_CH2 - GPIO_TIMER3_REMAP */
        {PORTD_15, TIMER3, 7 | (14 << PIN_REMAP_SHIFT) | (3 << PIN_CHANNEL_SHIFT)},          /* TIMER3_CH3 - GPIO_TIMER3_REMAP */

        {PORTA_0,  TIMER4, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER4_CH0 - Default */
        {PORTA_1,  TIMER4, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER4_CH1 - Default */
        {PORTA_2,  TIMER4, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER4_CH2 - Default */
        {PORTA_3,  TIMER4, 7 | (3 << PIN_CHANNEL_SHIFT)},                      /* TIMER4_CH3 - Default */

        {PORTC_6,  TIMER7, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER7_CH0 - Default */
        {PORTC_7,  TIMER7, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER7_CH1 - Default */
        {PORTC_8,  TIMER7, 7 | (2 << PIN_CHANNEL_SHIFT)},                      /* TIMER7_CH2 - Default */
        {PORTC_9,  TIMER7, 7 | (3 << PIN_CHANNEL_SHIFT)},                      /* TIMER7_CH3 - Default */

        {PORTA_2,  TIMER8, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER8_CH0 - Default */
        {PORTA_3,  TIMER8, 7 | (1 << PIN_CHANNEL_SHIFT)},                      /* TIMER8_CH1 - Default */
        {PORTE_5,  TIMER8, 7 | (33 << PIN_REMAP_SHIFT) | (0 << PIN_CHANNEL_SHIFT)},                     /* TIMER8_CH0 - GPIO_TIMER8_REMAP */
        {PORTE_6,  TIMER8, 7 | (33 << PIN_REMAP_SHIFT) | (1 << PIN_CHANNEL_SHIFT)},          /* TIMER8_CH1 - GPIO_TIMER8_REMAP */

        {PORTB_8,  TIMER9, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER9_CH0 - Default */
        {PORTB_9,  TIMER9, 7 | (0 << PIN_CHANNEL_SHIFT)},                      /* TIMER10_CH0 - Default */
        {PORTB_14,  TIMER11, 7 | (0 << PIN_CHANNEL_SHIFT)},                    /* TIMER11_CH0 - Default */
        {PORTB_15,  TIMER11, 7 | (1 << PIN_CHANNEL_SHIFT)},                    /* TIMER11_CH1 - Default */
        {NC,    NC,    0}
};

/* USART PinMap */
const PinMap PinMap_UART_TX[] = {
        {PORTA_9,  USART0, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 0)},
        {PORTA_2,  USART1, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 0)},
        {PORTD_5,  USART1, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 4)},   /* GPIO_USART1_REMAP */
        {PORTB_10, USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 0)},
        {PORTC_10, USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 5)},   /* GPIO_USART2_PARTIAL_REMAP */
        {PORTD_8,  USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 6)},   /* GPIO_USART2_FULL_REMAP */
        {PORTC_10, UART3, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 0)},
        {NC,    NC,     0}
};

const PinMap PinMap_UART_RX[] = {
        {PORTA_10, USART0, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 0)},
        {PORTA_3,  USART1, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 0)},
        {PORTD_6,  USART1, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 4)},   /* GPIO_USART1_REMAP */
        {PORTB_11, USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 0)},
        {PORTC_11, USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 5)},   /* GPIO_USART2_PARTIAL_REMAP */
        {PORTD_9,  USART2, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 6)},   /* GPIO_USART2_FULL_REMAP */
        {PORTC_11,  UART3, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 0)},
        {NC,    NC,     0}
};

// FIXME
const PinMap PinMap_UART_RTS[] = {
        {PORTA_12, USART0, 7},
        {PORTA_1,  USART1, 7},
        // {PORTD_4,  UART_1, 7 | (4 << PIN_REMAP_SHIFT)},   /* GPIO_USART1_RTS_REMAP */
        // {PORTB_14, UART_2, 7},
        // {PORTD_12, UART_2, 7 | (6 << 3)},   /* GPIO_USART2_RTS_FULL_REMAP */
        {NC,    NC,    0}
};

// FIXME
const PinMap PinMap_UART_CTS[] = {
        {PORTA_11, USART0, 7},
        {PORTA_0,  USART1, 7},
        // {PORTD_3,  UART_1, 7 | (4 << 3)},   /* GPIO_USART1_CTS_REMAP */
        // {PORTB_13, UART_2, 7},
        // {PORTD_11, UART_2, 7 | (6 << 3)},   /* GPIO_USART2_CTS_FULL_REMAP */
        {NC,    NC,    0}
};

/* SPI PinMap */
const PinMap PinMap_SPI_MOSI[] = {
        {PORTA_7,  SPI0, PIN_MODE_AF_PP},
        {PORTB_15, SPI1, PIN_MODE_AF_PP},
        {PORTC_3, SPI1, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 45)},  /* FIXME: GPIO_PCF5_SPI1_IO_REMAP1 */
        {PORTB_5, SPI2, PIN_MODE_AF_PP},
        {NC,    NC,    0}
};

const PinMap PinMap_SPI_MISO[] = {
        {PORTA_6,  SPI0, PIN_MODE_IN_FLOATING},
        {PORTB_14, SPI1, PIN_MODE_IN_FLOATING},
        {PORTB_4, SPI2, GD_PIN_FUNCTION_REMAP(PIN_MODE_IN_FLOATING, 26)}, /* GPIO_SWJ_SWDPENABLE_REMAP */
        {NC,    NC,    0}
};

const PinMap PinMap_SPI_SCLK[] = {
        {PORTA_5,  SPI0, PIN_MODE_AF_PP},
        {PORTB_13, SPI1, PIN_MODE_AF_PP},
        {PORTB_3, SPI2, GD_PIN_FUNCTION_REMAP(PIN_MODE_AF_PP, 26)}, /* GPIO_SWJ_SWDPENABLE_REMAP */
        {NC,    NC,    0}
};

const PinMap PinMap_SPI_SSEL[] = {
        {PORTA_4,  SPI0, PIN_MODE_AF_PP},
        {PORTA_15, SPI0, PIN_MODE_AF_PP | (1 << PIN_REMAP_SHIFT)},    /* GPIO_SPI0_REMAP */
        {PORTB_12, SPI1, PIN_MODE_AF_PP},
        {PORTB_6, SPI2, PIN_MODE_AF_PP},
        {NC,    NC,    0}
};

/* CAN PinMap */
const PinMap PinMap_CAN_RD[] = {
        {PORTA_11, CAN0, 3},
        {PORTB_8,  CAN0, 3 | (26 << PIN_REMAP_SHIFT)},    /* GPIO_CAN0_PARTIAL_REMAP */
        {PORTD_0,  CAN0, 3 | (27 << PIN_REMAP_SHIFT)},    /* GPIO_CAN0_FULL_REMAP */
        {PORTB_12, CAN1, 3},
        {PORTB_5,  CAN1, 3 | (29 << PIN_REMAP_SHIFT)},    /* GPIO_CAN1_REMAP */
        {NC,    NC,    0}
};

const PinMap PinMap_CAN_TD[] = {
        {PORTA_12, CAN0, 7},
        {PORTB_9,  CAN0, 7 | (26 << PIN_REMAP_SHIFT)},    /* GPIO_CAN0_PARTIAL_REMAP */
        {PORTD_1,  CAN0, 7 | (27 << PIN_REMAP_SHIFT)},    /* GPIO_CAN0_FULL_REMAP */
        {PORTB_13, CAN1, 7},
        {PORTB_6,  CAN1, 7 | (29 << PIN_REMAP_SHIFT)},    /* GPIO_CAN1_REMAP */
        {NC,    NC,    0}
};
