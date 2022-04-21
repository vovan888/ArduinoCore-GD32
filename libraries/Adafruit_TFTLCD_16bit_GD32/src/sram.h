#ifndef _SRAM_H_
#define _SRAM_H_

#include <stdint.h>

#include "gd32f20x_exmc.h"
#include "gd32f20x_gpio.h"
#include "gd32f20x_rcu.h"

#ifdef __cplusplus
extern "C"{
#endif

//#define FSMC_BANK1                      ((void*)0x60000000) 



/*
 * SRAM/NOR Flash routines
 */
extern volatile uint16_t *fsmcData;
extern volatile uint16_t *fsmcCommand;


void fsmc_lcd_init(void);

static void HAL_FSMC_MspInit(void);

static void FSMC_Init(void);

uint8_t read8_(void);


#ifdef __cplusplus
} /* extern "C" */
#endif


#endif