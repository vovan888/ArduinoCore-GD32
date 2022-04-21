#include "sram.h"

static uint32_t FSMC_Initialized = 0;

volatile uint16_t *fsmcCommand;
volatile uint16_t *fsmcData;

#define LCD_COMMAND_BASE  ((uint32_t)(0x60FFFFFE))
#define LCD_DATA_BASE  ((uint32_t)(0x61000000))

void fsmc_lcd_init() {

//    fsmcCommand    =  FSMC_NORSRAM_BANK1; // clears A23
//    fsmcData       =  (fsmcCommand+(1<<23)); // sets A23	

    fsmcCommand = ((uint16_t *) LCD_COMMAND_BASE); // clears A23
    fsmcData = ((uint16_t *) LCD_DATA_BASE); // sets A23

    HAL_FSMC_MspInit();
    FSMC_Init();
}

//read data from fmsc
uint8_t read8_(void) {
    return (*(uint8_t *) LCD_DATA_BASE);
}

static void HAL_FSMC_MspInit(void) {
    if (FSMC_Initialized) {
        return;
    }
    FSMC_Initialized = 1;

    /* Peripheral clock enable */
    rcu_periph_clock_enable(RCU_EXMC);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_GPIOE);

    /** FSMC GPIO Configuration
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
    */

    gpio_init(GPIOE, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,
              GPIO_PIN_2 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9
              | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15);

    gpio_init(GPIOD, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,
              GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_14
              | GPIO_PIN_15 | GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7);
}

static void HAL_FSMC_MspDeInit(void) {
    if (!FSMC_Initialized) {
        return;
    }
    FSMC_Initialized = 0;
}

/* FSMC initialization function */
static void FSMC_Init(void) {

    static exmc_norsram_timing_parameter_struct read_write_timing = {
            .asyn_access_mode = EXMC_ACCESS_MODE_A,
            .syn_data_latency = EXMC_DATALAT_2_CLK,
            .syn_clk_division = EXMC_SYN_CLOCK_RATIO_DISABLE,
            .bus_latency = 1,
            .asyn_data_setuptime = 0x0f,
            .asyn_address_holdtime = 0x02,
            .asyn_address_setuptime = 0x01,
    };

    static exmc_norsram_parameter_struct exmc_norsram_init_struct = {
            .norsram_region = EXMC_BANK0_NORSRAM_REGION0,
            .write_mode = EXMC_ASYN_WRITE,
            .extended_mode = DISABLE,
            .asyn_wait = DISABLE,
            .nwait_signal = DISABLE,
            .memory_write = ENABLE,
            .nwait_config = EXMC_NWAIT_CONFIG_BEFORE,
            .wrap_burst_mode = DISABLE,
            .nwait_polarity = EXMC_NWAIT_POLARITY_LOW,
            .burst_mode = DISABLE,
            .databus_width = EXMC_NOR_DATABUS_WIDTH_16B,
            .memory_type = EXMC_MEMORY_TYPE_SRAM,
            .address_data_mux = DISABLE,
            .read_write_timing = &read_write_timing,
            .write_timing = NULL,
    };

    exmc_norsram_init(&exmc_norsram_init_struct);

    exmc_norsram_enable(EXMC_BANK0_NORSRAM_REGION0);
}

static void FSMC_DeInit(void) {
    exmc_norsram_disable(EXMC_BANK0_NORSRAM_REGION0);
    exmc_norsram_deinit(EXMC_BANK0_NORSRAM_REGION0);
}