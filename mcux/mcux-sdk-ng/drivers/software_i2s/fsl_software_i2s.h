/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SOFTWARE_I2S_H_
#define FSL_SOFTWARE_I2S_H_

#include <stdint.h>
#include <stdbool.h>
#include "fsl_common.h"
#include "fsl_spi.h"
#include "fsl_sctimer.h"

/*!
 * @addtogroup software_i2s
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*! @{ */
/*! @brief Software I2S Master driver version 2.0.0. */
#define FSL_SOFTWARE_I2S_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * Select polarities of the used and unused chip selects.
 * Used Chip Select polarity:
 * CS0 - Active LOW
 * Unused Chip Select polarities :
 * CS1 - Active LOW
 * CS2 - Active HIGH
 * CS3 - Active HIGH
 */
#define SOFTWARE_I2S_SPI_SPOL      (kSPI_SpolActiveAllLow | kSPI_Spol2ActiveHigh | kSPI_Spol3ActiveHigh)
#define SOFTWARE_I2S_SPI_SLAVE     SPI0
#define SOFTWARE_I2S_SPI_SLAVE_IRQ FLEXCOMM2_IRQn
#define SOFTWARE_I2S_SPI_SSEL      0 /* SSEL PinMux == 0XC00 */
#define SOFTWARE_I2S_IRQHandler    FLEXCOMM2_IRQHandler

#define MEMS_MIC_IS_16BIT        TRUE
#define SOFTWARE_I2S_WS_PIN_OUT  kSCTIMER_Out_3
#define SOFTWARE_I2S_BCK_PIN_OUT kSCTIMER_Out_2
/* Each FIFO entry is 16bit or 32bit, FIFO SIZE should be multiple of 4, and smaller than RAM Size */
#define SOFTWARE_I2S_FIFO_SIZE            (1024)
#define SOFTWARE_I2S_DELAY_FOR_MIC_WAKEUP 1600000

/* Please don't change below lines */
#define SOFTWARE_I2S_WS_COUNTER  kSCTIMER_Counter_L
#define SOFTWARE_I2S_BCK_COUNTER kSCTIMER_Counter_H

#define SOFTWARE_I2S_Type        SCT_Type
#define SOFTWARE_I2S_BASE_PTRS   SCT_BASE_PTRS
#define SOFTWARE_I2S_CYCLE_MAGIC 8U

/* The count of SOFTWARE_I2S is equal to the count of SCT */
#define SOFTWARE_I2S0 SCT0

/*!
 * @brief Clock source.
 */
typedef enum _software_i2s_bclk
{
    kI2S_BCLK_1MHz = 1U, /*!< I2S bit clock 1 MHz */
    kI2S_BCLK_2MHz = 2U, /*!< I2S bit clock 2 MHz */
    kI2S_BCLK_4MHz = 4U, /*!< I2S bit clock 4 MHz */
} software_i2s_bclk_t;

/*!
 * @brief ws - means word select clock or channel select clock, ws = bclk/64.
 */
typedef enum _software_i2s_ws
{
    kI2S_WS_CLK_16KHZ = 0U, /*!< I2S WS Clock 16 kHz */
    kI2S_WS_CLK_32KHZ,      /*!< I2S WS Clock 32 kHz */
    kI2S_WS_CLK_64KHZ,      /*!< I2S WS Clock 64 kHz */
} software_i2s_ws_t;

/*!
 * @brief Define structure for configuring the block
 */
typedef struct _software_i2s_config_t
{
    sctimer_config_t sct_config;   /*!< SCT config on which software i2s depends */
    software_i2s_bclk_t bck_speed; /*!< I2S bit clock speed */
    software_i2s_ws_t ws_speed;    /*!< I2S ws clock speed */
    sctimer_out_t bck_pin;         /*!< I2S bit clock pin */
    sctimer_out_t ws_pin;          /*!< I2S ws pin */
} software_i2s_config_t;

/*!
 * @brief Define software i2s fifo structure
 */
typedef struct _i2s_fifo
{
/*
 * I2S FIFO size and width.
 * use micro definition rather than an union to reduce memory.
 */
#if defined(MEMS_MIC_IS_32BIT) && (MEMS_MIC_IS_32BIT == TRUE)
    uint32_t fifo[SOFTWARE_I2S_FIFO_SIZE]; /*!< 32bit FIFO */
#elif defined(MEMS_MIC_IS_16BIT) && (MEMS_MIC_IS_16BIT == TRUE)
    uint16_t fifo[SOFTWARE_I2S_FIFO_SIZE]; /*!< 16bit FIFO */
#else
#error "This CPU doesn't support this MEMS MIC format"
#endif
    uint32_t rp;                          /*!< FIFO read pointer */
    uint32_t wp;                          /*!< FIFO write pointer */
    bool i2s_stash_finish_cmd_and_status; /*!< Software i2s stash finish command and finish status */
    bool LowHalfWord; /*!< Software I2S data format supports upto 32 bits, this field marks low/high half word */
    bool is_newline;  /*!< word wrap flag */
} software_i2s_fifo_t;

/* Globle variables list */
extern software_i2s_fifo_t i2s_fifo_rd;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

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
void SOFTWARE_I2S_GetDefaultConfig(software_i2s_config_t *config);

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
status_t SOFTWARE_I2S_Init(SOFTWARE_I2S_Type *base, const software_i2s_config_t *config);

/*!
 * @brief Deinitialize the Software I2S module.
 *
 * This function de-nitializes the Software I2S module, including:
 *  - Disable the Software I2S module clock.
 *
 * @param base Software I2S peripheral base address.
 */
void SOFTWARE_I2S_Deinit(SOFTWARE_I2S_Type *base);

/*!
 * @brief Enable/Disable the Software I2S Master.
 *
 * @param base     Software I2S peripheral base address.
 * @param enable   true to enable the Software I2S, false to disable.
 */
void SOFTWARE_I2S_Enable(SOFTWARE_I2S_Type *base, bool enable);

/*! @}*/

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_SOFTWARE_I2S_H_ */
