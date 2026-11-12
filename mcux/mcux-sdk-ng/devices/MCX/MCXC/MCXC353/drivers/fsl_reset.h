/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_RESET_H_
#define _FSL_RESET_H_

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "fsl_device_registers.h"

/*!
 * @addtogroup reset
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief reset driver version 2.4.0 */
#define FSL_RESET_DRIVER_VERSION (MAKE_VERSION(2, 4, 0))
/*@}*/

/*!
 * @brief Enumeration for peripheral reset control bits
 *
 * Defines the enumeration for peripheral reset control bits in PRESETCTRL/ASYNCPRESETCTRL registers
 */
typedef enum _SYSCON_RSTn
{
    kXBAR0_RST_SHIFT_RSTn    = ((0U << 8U) | 0U),  /*!< XBAR0     reset control */
    kFREQME_RST_SHIFT_RSTn   = ((0U << 8U) | 1U),  /*!< FREQME    reset control */
    kPWT0_RST_SHIFT_RSTn     = ((0U << 8U) | 5U),  /*!< PWT0      reset control */
    kPWT1_RST_SHIFT_RSTn     = ((0U << 8U) | 6U),  /*!< PWT1      reset control */
    kDMA0_RST_SHIFT_RSTn     = ((0U << 8U) | 10U), /*!< DMA0      reset control */
    kPIT0_RST_SHIFT_RSTn     = ((0U << 8U) | 11U), /*!< PIT0      reset control */
    kCRC0_RST_SHIFT_RSTn     = ((0U << 8U) | 12U), /*!< CRC0      reset control */
    kEIM0_RST_SHIFT_RSTn     = ((0U << 8U) | 13U), /*!< EIM0      reset control */
    kERM0_RST_SHIFT_RSTn     = ((0U << 8U) | 14U), /*!< ERM0      reset control */
    kFTM0_RST_SHIFT_RSTn     = ((0U << 8U) | 22U), /*!< FTM0      reset control */
    kQTMR0_RST_SHIFT_RSTn    = ((0U << 8U) | 24U), /*!< QTMR0     reset control */
    kAOI0_RST_SHIFT_RSTn     = ((0U << 8U) | 26U), /*!< AOI0      reset control */
    kFLEXPWM0_RST_SHIFT_RSTn = ((0U << 8U) | 30U), /*!< FLEXPWM0  reset control */
    kLPI2C0_RST_SHIFT_RSTn   = ((1U << 8U) | 0U),  /*!< LPI2C0    reset control */
    kLPI2C1_RST_SHIFT_RSTn   = ((1U << 8U) | 1U),  /*!< LPI2C1    reset control */
    kLPSPI0_RST_SHIFT_RSTn   = ((1U << 8U) | 4U),  /*!< LPSPI0    reset control */
    kLPUART0_RST_SHIFT_RSTn  = ((1U << 8U) | 8U),  /*!< LPUART0   reset control */
    kLPUART1_RST_SHIFT_RSTn  = ((1U << 8U) | 9U),  /*!< LPUART1   reset control */
    kPHD0_RST_SHIFT_RSTn     = ((1U << 8U) | 14U), /*!< PHD0      reset control */
    kADC0_RST_SHIFT_RSTn     = ((1U << 8U) | 16U), /*!< ADC0      reset control */
    kCMP0_RST_SHIFT_RSTn     = ((1U << 8U) | 20U), /*!< CMP0      reset control */
    kCMP1_RST_SHIFT_RSTn     = ((1U << 8U) | 21U), /*!< CMP1      reset control */
    kOPAMP0_RST_SHIFT_RSTn   = ((1U << 8U) | 25U), /*!< OPAMP0    reset control */
    kPORT0_RST_SHIFT_RSTn    = ((2U << 8U) | 0U),  /*!< PORT0     reset control */
    kPORT1_RST_SHIFT_RSTn    = ((2U << 8U) | 1U),  /*!< PORT1     reset control */
    kPORT2_RST_SHIFT_RSTn    = ((2U << 8U) | 2U),  /*!< PORT2     reset control */
    kPORT3_RST_SHIFT_RSTn    = ((2U << 8U) | 3U),  /*!< PORT3     reset control */
    kGPIO0_RST_SHIFT_RSTn    = ((2U << 8U) | 6U),  /*!< GPIO0     reset control */
    kGPIO1_RST_SHIFT_RSTn    = ((2U << 8U) | 7U),  /*!< GPIO1     reset control */
    kGPIO2_RST_SHIFT_RSTn    = ((2U << 8U) | 8U),  /*!< GPIO2     reset control */
    kGPIO3_RST_SHIFT_RSTn    = ((2U << 8U) | 9U),  /*!< GPIO3     reset control */
    kMAU0_RST_SHIFT_RSTn     = ((2U << 8U) | 27U), /*!< MAU0      reset control */
    NotAvail_RSTn            = (0xFFFFU),          /*!< No        reset control */
} SYSCON_RSTn_t;

/** Array initializers with peripheral reset bits **/
/*! @brief Reset bits for ADC peripheral */
#define ADC_RSTS   {kADC0_RST_SHIFT_RSTn}
#define ADC_RSTS_N ADC_RSTS
/*! @brief Reset bits for AOI peripheral */
#define AOI_RSTS   {kAOI0_RST_SHIFT_RSTn}
#define AOI_RSTS_N AOI_RSTS
/*! @brief Reset bits for CMP peripheral */
#define HSCMP_RSTS   {kCMP0_RST_SHIFT_RSTn, kCMP1_RST_SHIFT_RSTn}
#define HSCMP_RSTS_N HSCMP_RSTS
/*! @brief Reset bits for CRC peripheral */
#define CRC_RSTS   {kCRC0_RST_SHIFT_RSTn}
#define CRC_RSTS_N CRC_RSTS
/*! @brief Reset bits for DMA peripheral */
#define DMA_RSTS   {kDMA0_RST_SHIFT_RSTn}
#define DMA_RSTS_N DMA_RSTS
/*! @brief Reset bits for EIM peripheral */
#define EIM_RSTS   {kEIM0_RST_SHIFT_RSTn}
#define EIM_RSTS_N EIM_RSTS
/*! @brief Reset bits for ERM peripheral */
#define ERM_RSTS   {kERM0_RST_SHIFT_RSTn}
#define ERM_RSTS_N ERM_RSTS
/*! @brief Reset bits for FLEXPWM peripheral */
#define FLEXPWM_RSTS   {kFLEXPWM0_RST_SHIFT_RSTn}
#define FLEXPWM_RSTS_N FLEXPWM_RSTS
/*! @brief Reset bits for FREQME peripheral */
#define FREQME_RSTS   {kFREQME_RST_SHIFT_RSTn}
#define FREQME_RSTS_N FREQME_RSTS
/*! @brief Reset bits for FTM peripheral */
#define FTM_RSTS   {kFTM0_RST_SHIFT_RSTn}
#define FTM_RSTS_N FTM_RSTS
/*! @brief Reset bits for GPIO peripheral */
#define GPIO_RSTS   {kGPIO0_RST_SHIFT_RSTn, kGPIO1_RST_SHIFT_RSTn, kGPIO2_RST_SHIFT_RSTn, kGPIO3_RST_SHIFT_RSTn}
#define GPIO_RSTS_N GPIO_RSTS
/*! @brief Reset bits for LPI2C peripheral */
#define LPI2C_RSTS   {kLPI2C0_RST_SHIFT_RSTn, kLPI2C1_RST_SHIFT_RSTn}
#define LPI2C_RSTS_N LPI2C_RSTS
/*! @brief Reset bits for LPSPI peripheral */
#define LPSPI_RSTS   {kLPSPI0_RST_SHIFT_RSTn}
#define LPSPI_RSTS_N LPSPI_RSTS
/*! @brief Reset bits for LPUART peripheral */
#define LPUART_RSTS   {kLPUART0_RST_SHIFT_RSTn, kLPUART1_RST_SHIFT_RSTn}
#define LPUART_RSTS_N LPUART_RSTS
/*! @brief Reset bits for MAU peripheral */
#define MAU_RSTS   {kMAU0_RST_SHIFT_RSTn}
#define MAU_RSTS_N MAU_RSTS
/*! @brief Reset bits for OPAMP peripheral */
#define OPAMP_RSTS   {kOPAMP0_RST_SHIFT_RSTn}
#define OPAMP_RSTS_N OPAMP_RSTS
/*! @brief Reset bits for PHD peripheral */
#define PHD_RSTS   {kPHD0_RST_SHIFT_RSTn}
#define PHD_RSTS_N PHD_RSTS
/*! @brief Reset bits for PIT peripheral */
#define PIT_RSTS   {kPIT0_RST_SHIFT_RSTn}
#define PIT_RSTS_N PIT_RSTS
/*! @brief Reset bits for PORT peripheral */
#define PORT_RSTS   {kPORT0_RST_SHIFT_RSTn, kPORT1_RST_SHIFT_RSTn, kPORT2_RST_SHIFT_RSTn, kPORT3_RST_SHIFT_RSTn}
#define PORT_RSTS_N PORT_RSTS
/*! @brief Reset bits for PWT peripheral */
#define PWT_RSTS   {kPWT0_RST_SHIFT_RSTn, kPWT1_RST_SHIFT_RSTn}
#define PWT_RSTS_N PWT_RSTS
/*! @brief Reset bits for QTMR peripheral */
#define QTMR_RSTS   {kQTMR0_RST_SHIFT_RSTn}
#define QTMR_RSTS_N QTMR_RSTS
/*! @brief Reset bits for XBAR peripheral */
#define XBAR_RSTS   {kXBAR0_RST_SHIFT_RSTn}
#define XBAR_RSTS_N XBAR_RSTS

typedef SYSCON_RSTn_t reset_ip_name_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * @param peripheral Assert reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_SetPeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * @param peripheral Clear reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_ClearPeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * @param peripheral Peripheral to reset. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral);

/*!
 * @brief Release peripheral module.
 *
 * Release peripheral module.
 *
 * @param peripheral Peripheral to release. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
static inline void RESET_ReleasePeripheralReset(reset_ip_name_t peripheral)
{
    RESET_SetPeripheralReset(peripheral);
}

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_RESET_H_ */
