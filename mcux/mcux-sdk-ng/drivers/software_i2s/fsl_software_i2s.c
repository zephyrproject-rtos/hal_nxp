/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_software_i2s.h"

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.software_i2s"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address
 *
 * @param base SOFTWARE_I2S (SCTimer) peripheral base address
 *
 * @return The SOFTWARE_I2S (SCTimer) instance
 */
static uint32_t SOFTWARE_I2S_GetInstance(SCT_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to SOFTWARE_I2S (SCT) bases for each instance. */
static SOFTWARE_I2S_Type *const s_software_i2sBases[] = SOFTWARE_I2S_BASE_PTRS;

/*! @brief software i2s fifo for each instance. */
software_i2s_fifo_t i2s_fifo_rd = {0};

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t SOFTWARE_I2S_GetInstance(SOFTWARE_I2S_Type *base)
{
    uint32_t instance;
    uint32_t software_i2sArrayCount = (sizeof(s_software_i2sBases) / sizeof(s_software_i2sBases[0]));

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < software_i2sArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_software_i2sBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < software_i2sArrayCount);

    return instance;
}

static void SOFTWARE_I2S_SPI_Slave_Start(bool enable)
{
    spi_slave_config_t slaveConfig = {0};

    if (enable)
    {
        SPI_SlaveGetDefaultConfig(&slaveConfig);
        slaveConfig.sselPol   = (spi_spol_t)SOFTWARE_I2S_SPI_SPOL;
        slaveConfig.dataWidth = kSPI_Data16Bits;
#if defined(SPH0645LM4H) || defined(SAMPLING_MODE_FALLING)
        slaveConfig.polarity = kSPI_ClockPolarityActiveLow;
#elif defined(ICS_43432) || defined(SAMPLING_MODE_RISING)
        slaveConfig.polarity = kSPI_ClockPolarityActiveHigh;
#else
#error "You MUST define the Microphone type in Keil like this: SAMPLING_MODE_RISING or SAMPLING_MODE_FALLING"
#endif
        slaveConfig.rxWatermark = kSPI_RxFifo7;
        SPI_SlaveInit(SOFTWARE_I2S_SPI_SLAVE, &slaveConfig);
        EnableIRQ(SOFTWARE_I2S_SPI_SLAVE_IRQ);
        SPI_EnableInterrupts(SOFTWARE_I2S_SPI_SLAVE, kSPI_RxLvlIrq | kSPI_TxLvlIrq);
    }
    else
    {
        SPI_DisableInterrupts(SOFTWARE_I2S_SPI_SLAVE, kSPI_RxLvlIrq | kSPI_TxLvlIrq);
        DisableIRQ(SOFTWARE_I2S_SPI_SLAVE_IRQ);
        SPI_Deinit(SOFTWARE_I2S_SPI_SLAVE);
        i2s_fifo_rd.LowHalfWord = false;
    }
}

/*!
 * @brief Gets an available pre-defined settings for initial configuration.
 *
 * Initializes the default configuration structure with a minimal settings.
 * The default values are:
 * @code
 *   config->bck_speed = kI2S_BCLK_1MHz;
 *   config->ws_speed = kI2S_WS_CLK_16KHZ;
 *   config->bck_pin = SOFTWARE_I2S_BCK_PIN_OUT;
 *   config->ws_pin = SOFTWARE_I2S_WS_PIN_OUT;
 * @endcode
 * @param config Pointer to configuration structure.
 */
/*!
 * brief Gets an available pre-defined settings for initial configuration.
 *
 * Initializes the default configuration structure with a minimal settings.
 * The default values are:
 * code
 *   config->bck_speed = kI2S_BCLK_1MHz;
 *   config->ws_speed = kI2S_WS_CLK_16KHZ;
 *   config->bck_pin = SOFTWARE_I2S_BCK_PIN_OUT;
 *   config->ws_pin = SOFTWARE_I2S_WS_PIN_OUT;
 * endcode
 * param config Pointer to configuration structure.
 */
void SOFTWARE_I2S_GetDefaultConfig(software_i2s_config_t *config)
{
    assert(config);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    sctimer_config_t *sct_config = &(config->sct_config);
    SCTIMER_GetDefaultConfig(sct_config);

    /* Switch to two 16-bit counter mode */
    sct_config->enableCounterUnify = false;
    sct_config->prescale_h         = 0;
    sct_config->prescale_l         = 0;
    config->bck_speed              = kI2S_BCLK_1MHz;
    config->ws_speed               = kI2S_WS_CLK_16KHZ;
    /*
     * As default, Pin07 (kSCTIMER_Out_2/SOFTWARE_I2S_BCK_PIN_OUT) is for i2s bit clock pin,
     * Pin06 (kSCTIMER_Out_3/SOFTWARE_I2S_WS_PIN_OUT) is for i2s ws output pin.
     */
    config->bck_pin = SOFTWARE_I2S_BCK_PIN_OUT;
    config->ws_pin  = SOFTWARE_I2S_WS_PIN_OUT;
}

/*!
 * @brief Initialize the Software I2S Master module.
 *
 * This function initializes the Software I2S module, including:
 *  - Enable Software I2S module clock.
 *  - Reset Software I2S module.
 *  - Configure the Software I2S with user configuration.
 *
 * @param base Software I2S peripheral base address.
 * @param config Pointer to configuration structure, see to #software_i2s_config_t.
 *
 * @return kStatus_Success indicates success; Else indicates failure.
 */
/*!
 * brief Initialize the Software I2S Master module.
 *
 * This function initializes the Software I2S module, including:
 *  - Enable Software I2S module clock.
 *  - Reset Software I2S module.
 *  - Configure the Software I2S with user configuration.
 *
 * param base Software I2S peripheral base address.
 * param config Pointer to configuration structure, see to #software_i2s_config_t.
 *
 * return kStatus_Success indicates success; Else indicates failure.
 */
status_t SOFTWARE_I2S_Init(SOFTWARE_I2S_Type *base, const software_i2s_config_t *config)
{
    assert(config);

    status_t i2s_status;
    uint32_t eventCounterL, eventCounterH;
    uint32_t matchValueL, matchValueH;
    uint32_t sctimerClock;
    const sctimer_config_t *sct_config = &(config->sct_config);

    /* FIX ME! Here is a BUG: sctimerClock should be 32MHz, but it returns 16MHz */
    sctimerClock = CLOCK_GetFreq(kCLOCK_BusClk);

    /*
     * MatchH -> bck: 4MHz, MatchL -> ws: 62--64kHz
     * MatchH -> bck: 2MHz, MatchL -> ws: 31--32kHz
     * MatchH -> bck: 1MHz, MatchL -> ws: 15--16kHz
     */
    matchValueH = (SOFTWARE_I2S_CYCLE_MAGIC / config->bck_speed) * (sctimerClock / 16000000) - 1;
    matchValueL = (SOFTWARE_I2S_CYCLE_MAGIC / config->bck_speed) * 64 * (sctimerClock / 16000000) - 1;

    i2s_status = SCTIMER_Init(base, sct_config);
    if (i2s_status != kStatus_Success)
        return i2s_status;

    /* Schedule a match event for Counter L every xxx useconds */
    i2s_status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, matchValueL, 0, SOFTWARE_I2S_WS_COUNTER,
                                                &eventCounterL);
    if (i2s_status != kStatus_Success)
    {
        return i2s_status;
    }
    /* Toggle bck output pin when Counter L event occurs */
    SCTIMER_SetupOutputToggleAction(base, config->ws_pin, eventCounterL);
    /* Reset Counter L when Counter L event occurs */
    SCTIMER_SetupCounterLimitAction(SCT0, SOFTWARE_I2S_WS_COUNTER, eventCounterL);

    /* Schedule a match event for Counter H every yyy useconds */
    i2s_status = SCTIMER_CreateAndScheduleEvent(base, kSCTIMER_MatchEventOnly, matchValueH, 0, SOFTWARE_I2S_BCK_COUNTER,
                                                &eventCounterH);
    if (i2s_status != kStatus_Success)
    {
        return i2s_status;
    }
    /* Toggle ws output pin when Counter H event occurs */
    SCTIMER_SetupOutputToggleAction(base, config->bck_pin, eventCounterH);
    /* Reset Counter H when Counter H event occurs */
    SCTIMER_SetupCounterLimitAction(base, SOFTWARE_I2S_BCK_COUNTER, eventCounterH);

    return kStatus_Success;
}

/*!
 * @brief Deinitialize the Software I2S module.
 *
 * This function de-nitializes the Software I2S module, including:
 *  - Disable the Software I2S module clock.
 *
 * @param base Software I2S peripheral base address.
 */
/*!
 * brief Deinitialize the Software I2S module.
 *
 * This function de-nitializes the Software I2S module, including:
 *  - Disable the Software I2S module clock.
 *
 * param base Software I2S peripheral base address.
 */
void SOFTWARE_I2S_Deinit(SOFTWARE_I2S_Type *base)
{
    /* Disable the clock to save power consumption */
    SCTIMER_Deinit(base);
}

/*!
 * @brief Enable/Disable the Software I2S Master.
 *
 * @param base     Software I2S peripheral base address.
 * @param enable   true to enable the Software I2S, false to disable.
 */
/*!
 * brief Enable/Disable the Software I2S Master.
 *
 * param base     Software I2S peripheral base address.
 * param enable   true to enable the Software I2S, false to disable.
 */
void SOFTWARE_I2S_Enable(SOFTWARE_I2S_Type *base, bool enable)
{
    uint32_t sctimerClock = CLOCK_GetFreq(kCLOCK_BusClk);

    if (enable)
    {
        SCTIMER_StartTimer(base, SOFTWARE_I2S_BCK_COUNTER);
        /* below codes need an optimization */
        if (16000000 == sctimerClock)
        {
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
        }
        else if (32000000 == sctimerClock)
        {
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
            __asm("NOP");
        }
        else
        {
            /* "this MCU frequency is not verified, so you need your own timing" */
        }
        /* start ws clock */
        SCTIMER_StartTimer(base, SOFTWARE_I2S_WS_COUNTER);
        for (volatile uint32_t x = 0; x < SOFTWARE_I2S_DELAY_FOR_MIC_WAKEUP; x++)
        {
            ;
        }
        SOFTWARE_I2S_SPI_Slave_Start(enable);
    }
    else
    {
        SOFTWARE_I2S_SPI_Slave_Start(enable);
        SCTIMER_StopTimer(base, SOFTWARE_I2S_WS_COUNTER);
        SCTIMER_StopTimer(base, SOFTWARE_I2S_BCK_COUNTER);
    }
}

void SOFTWARE_I2S_IRQHandler(void)
{
    while ((SPI_GetStatusFlags(SOFTWARE_I2S_SPI_SLAVE) & kSPI_RxNotEmptyFlag))
    {
#if defined(MEMS_MIC_IS_16BIT) && (MEMS_MIC_IS_16BIT == TRUE)
        if (!i2s_fifo_rd.LowHalfWord)
        {
            i2s_fifo_rd.fifo[i2s_fifo_rd.wp++] = SPI_ReadData(SOFTWARE_I2S_SPI_SLAVE) << 1;
        }
        else
        {
            /* in 16bit MEMS MIC scenario, drop tail 16bit */
            SPI_ReadData(SOFTWARE_I2S_SPI_SLAVE);
        }
        i2s_fifo_rd.LowHalfWord = !i2s_fifo_rd.LowHalfWord;
#elif defined(MEMS_MIC_IS_32BIT) && (MEMS_MIC_IS_32BIT == TRUE)
        uint16_t *p          = (uint16_t *)&i2s_fifo_rd.fifo[i2s_fifo_rd.wp];
        if (!i2s_fifo_rd.LowHalfWord)
        {
            /* in 32bit MEMS MIC scenario, stash all 32bit, belows are the MSB 16bit of MIC */
            *(p + 1) = SPI_ReadData(SOFTWARE_I2S_SPI_SLAVE);
        }
        else
        {
            /* in 32bit MEMS MIC scenario, stash all 32bit, belows are the LSB 16bit of MIC*/
            *(p)                               = SPI_ReadData(SOFTWARE_I2S_SPI_SLAVE);
            i2s_fifo_rd.fifo[i2s_fifo_rd.wp++] = *((uint32_t *)p) << 1;
        }
        i2s_fifo_rd.LowHalfWord = !i2s_fifo_rd.LowHalfWord;
#endif
        /* This is a loop FIFO, wrap automatically */
        if (i2s_fifo_rd.wp >= SOFTWARE_I2S_FIFO_SIZE)
        {
            i2s_fifo_rd.wp         = 0;
            i2s_fifo_rd.is_newline = true;
        }
    }
    while ((SPI_GetStatusFlags(SOFTWARE_I2S_SPI_SLAVE) & kSPI_TxNotFullFlag))
    {
        SPI_WriteData(SOFTWARE_I2S_SPI_SLAVE, 0, 0);
    }

    if (i2s_fifo_rd.i2s_stash_finish_cmd_and_status)
    {
        SPI_DisableInterrupts(SOFTWARE_I2S_SPI_SLAVE, kSPI_RxLvlIrq | kSPI_TxLvlIrq);
    }
    SDK_ISR_EXIT_BARRIER;
}
