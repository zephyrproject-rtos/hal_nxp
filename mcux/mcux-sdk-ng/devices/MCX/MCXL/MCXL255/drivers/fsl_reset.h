/*
 * Copyright 2024-2025 NXP
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
/*! @brief reset driver version 2.5.0 */
#define FSL_RESET_DRIVER_VERSION (MAKE_VERSION(2, 5, 0))
/*@}*/

/*!
 * @brief Enumeration for peripheral reset control bits
 *
 * Defines the enumeration for peripheral reset control bits in PRESETCTRL/ASYNCPRESETCTRL registers
 */
typedef enum _SYSCON_RSTn
{
#if __CORTEX_M == (33U) /* Building on the main core */
    /* Check syscon mrcc CGLB_RST0 in RM */
    kINPUTMUX0_RST_SHIFT_RSTn = (0U | (0U)),          /*!< INPUTMUX0    reset control */
    kCTIMER0_RST_SHIFT_RSTn   = (0U | (1U)),          /*!< CTIMER0      reset control */
    kCTIMER1_RST_SHIFT_RSTn   = (0U | (2U)),          /*!< CTIMER1      reset control */
    kCTIMER2_RST_SHIFT_RSTn   = (0U | (3U)),          /*!< CTIMER2      reset control */
    kFREQME_RST_SHIFT_RSTn    = (0U | (4U)),          /*!< FREQME       reset control */
    kUTICK0_RST_SHIFT_RSTn    = (0U | (5U)),          /*!< UTICK0       reset control */
    kDMA0_RST_SHIFT_RSTn      = (0U | (7U)),          /*!< DMA0         reset control */
    kAOI0_RST_SHIFT_RSTn      = (0U | (8U)),          /*!< AOI0         reset control */
    kCRC_RST_SHIFT_RSTn       = (0U | (9U)),          /*!< CRC          reset control */
    kERM0_RST_SHIFT_RSTn      = (0U | (10U)),         /*!< ERM0         reset control */
    kLPI2C0_RST_SHIFT_RSTn    = (0U | (14U)),         /*!< LPI2C0       reset control */
    kLPI2C1_RST_SHIFT_RSTn    = (0U | (15U)),         /*!< LPI2C1       reset control */
    kLPSPI0_RST_SHIFT_RSTn    = (0U | (16U)),         /*!< LPSPI0       reset control */
    kLPSPI1_RST_SHIFT_RSTn    = (0U | (17U)),         /*!< LPSPI1       reset control */
    kLPUART0_RST_SHIFT_RSTn   = (0U | (18U)),         /*!< LPUART0      reset control */
    kADC0_RST_SHIFT_RSTn      = (0U | (19U)),         /*!< ADC0         reset control */
    kATX0_RST_SHIFT_RSTn      = (0U | (20U)),         /*!< ATX0         reset control */
    kCMP0_RST_SHIFT_RSTn      = (0U | (21U)),         /*!< CMP0         reset control */
    kDMA1_RST_SHIFT_RSTn      = (0U | (22U)),         /*!< DMA1         reset control */
    kGPIO1_RST_SHIFT_RSTn     = (0U | (24U)),         /*!< GPIO1        reset control */
    kGPIO2_RST_SHIFT_RSTn     = (0U | (25U)),         /*!< GPIO2        reset control */
    kGPIO3_RST_SHIFT_RSTn     = (0U | (26U)),         /*!< GPIO3        reset control */
    kLPUART1_RST_SHIFT_RSTn   = (0U | (27U)),         /*!< LPUART1      reset control */
    kOSTIMER0_RST_SHIFT_RSTn  = (0U | (29U)),         /*!< OSTIMER0     reset control */

    /* Check syscon mrcc CGLB_RST1 in RM */
    kPKC0_RST_SHIFT_RSTn      = ((1U << 8) | (0U)),   /*!< PKC0         reset control */
    kPORT1_RST_SHIFT_RSTn     = ((1U << 8) | (1U)),   /*!< PORT1        reset control */
    kPORT2_RST_SHIFT_RSTn     = ((1U << 8) | (2U)),   /*!< PORT2        reset control */
    kPORT3_RST_SHIFT_RSTn     = ((1U << 8) | (3U)),   /*!< PORT3        reset control */
    kSGLCD0_RST_SHIFT_RSTn    = ((1U << 8) | (6U)),   /*!< SGLCD0       reset control */
    kTRNG0_RST_SHIFT_RSTn     = ((1U << 8) | (8U)),   /*!< TRNG0        reset control */
#endif /* Building on the main core */

    /* Check AON CGU RST_SUB_BLK in RM */
    kAonUART_RST_SHIFT_RSTn    = ((2U << 8) | (0U)),  /*!< AON UART    reset control */
    kAonI2C_RST_SHIFT_RSTn     = ((2U << 8) | (1U)),  /*!< AON I2C     reset control */
    kAonCAL_RST_SHIFT_RSTn     = ((2U << 8) | (2U)),  /*!< AON CAL     reset control */
    kAonQTMR0_RST_SHIFT_RSTn   = ((2U << 8) | (5U)),  /*!< AON QTMR0   reset control */
    kAonLPTMR_RST_SHIFT_RSTn   = ((2U << 8) | (7U)),  /*!< AON LPTMR   reset control */
    kAonKPP_RST_SHIFT_RSTn     = ((2U << 8) | (8U)),  /*!< AON KPP     reset control */
    kAonLPADC_RST_SHIFT_RSTn   = ((2U << 8) | (9U)),  /*!< AON LPADC   reset control */
    kAonLCD_RST_SHIFT_RSTn     = ((2U << 8) | (10U)), /*!< AON LCD     reset control */
    kAonCMP0_RST_SHIFT_RSTn    = ((2U << 8) | (12U)), /*!< AON ACMP    reset control */
    kAonADVC2P0_RST_SHIFT_RSTn = ((2U << 8) | (13U)), /*!< AON ADVC2P0 reset control */

    NotAvail_RSTn              = (0xFFFFU),            /*!< No          reset control */
} SYSCON_RSTn_t;

#if __CORTEX_M == (33U) /* Building on the main core */

/** Array initializers with peripheral reset bits **/
#define AOI_RSTS             \
    {                        \
        kAOI0_RST_SHIFT_RSTn \
    } /* Reset bits for AOI peripheral */
#define ADC_RSTS             \
    {                        \
        kADC0_RST_SHIFT_RSTn \
    } /* Reset bits for ADC peripheral */
#define AON_LPADC_RSTS             \
    {                        \
        kAonLPADC_RST_SHIFT_RSTn \
    } /* Reset bits for AON_LPADC peripheral */
#define CRC_RSTS            \
    {                       \
        kCRC_RST_SHIFT_RSTn \
    } /* Reset bits for CRC peripheral */
#define CTIMER_RSTS                                                               \
    {                                                                             \
        kCTIMER0_RST_SHIFT_RSTn, kCTIMER1_RST_SHIFT_RSTn, kCTIMER2_RST_SHIFT_RSTn \
    } /* Reset bits for CTIMER peripheral */
#define DMA_RSTS_N          \
    {                       \
        kDMA0_RST_SHIFT_RSTn, kDMA1_RST_SHIFT_RSTn \
    } /* Reset bits for DMA peripheral */
#define FREQME_RSTS_N          \
    {                          \
        kFREQME_RST_SHIFT_RSTn \
    } /* Reset bits for FREQME peripheral */
#define GPIO_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn, kGPIO1_RST_SHIFT_RSTn, kGPIO2_RST_SHIFT_RSTn, kGPIO3_RST_SHIFT_RSTn \
    } /* Reset bits for GPIO peripheral */
#define INPUTMUX_RSTS             \
    {                             \
        kINPUTMUX0_RST_SHIFT_RSTn, NotAvail_RSTn \
    } /* Reset bits for INPUTMUX peripheral */
#define LPUART_RSTS                                      \
    {                                                    \
        kLPUART0_RST_SHIFT_RSTn, kLPUART1_RST_SHIFT_RSTn, kAonUART_RST_SHIFT_RSTn \
    } /* Reset bits for LPUART peripheral */
#define LPSPI_RSTS                                     \
    {                                                  \
        kLPSPI0_RST_SHIFT_RSTn, kLPSPI1_RST_SHIFT_RSTn \
    } /* Reset bits for LPSPI peripheral */
#define LPI2C_RSTS             \
    {                          \
        kLPI2C0_RST_SHIFT_RSTn, kLPI2C1_RST_SHIFT_RSTn, kAonI2C_RST_SHIFT_RSTn \
    } /* Reset bits for LPI2C peripheral */
#define CMP_RSTS                          \
    {                                       \
        kAonCMP0_RST_SHIFT_RSTn, kCMP0_RST_SHIFT_RSTn \
    } /* Reset bits for CMP peripherals */
#define LPACMP_RSTS                          \
    {                                       \
        NotAvail_RSTn \
    } /* Reset bits for LPCMP peripheral */
#define OSTIMER_RSTS             \
    {                            \
        kOSTIMER0_RST_SHIFT_RSTn \
    } /* Reset bits for OSTIMER peripheral */
#define PORT_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn, kPORT0_RST_SHIFT_RSTn, kPORT1_RST_SHIFT_RSTn, kPORT2_RST_SHIFT_RSTn \
    } /* Reset bits for PORT peripheral */
#define UTICK_RSTS             \
    {                          \
        kUTICK0_RST_SHIFT_RSTn \
    } /* Reset bits for UTICK peripheral */

#elif __CORTEX_M == (0U) /* Building on the AON core */

#define LPUART_RSTS                                      \
    {                                                    \
        NotAvail_RSTn, NotAvail_RSTn, kAonUART_RST_SHIFT_RSTn \
    } /* Reset bits for LPUART peripheral */
#define LPI2C_RSTS             \
    {                          \
        NotAvail_RSTn, NotAvail_RSTn, kAonI2C_RST_SHIFT_RSTn \
    } /* Reset bits for LPI2C peripheral */
#define CTIMER_RSTS                                         \
    {                                                       \
        kAonQTMR0_RST_SHIFT_RSTn, kAonLPTMR_RST_SHIFT_RSTn  \
    } /* Reset bits for CTIMER peripheral */
#define PORT_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn                                \
    } /* Reset bits for PORT peripheral */
#define GPIO_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn                                \
    } /* Reset bits for GPIO peripheral */
#define CMP_RSTS                          \
    {                                       \
        kAonCMP0_RST_SHIFT_RSTn, NotAvail_RSTn \
    } /* Reset bits for CMP peripherals */
#define LPACMP_RSTS                         \
    {                                       \
        NotAvail_RSTn                       \
    } /* Reset bits for LPCMP peripheral */
#define PORT_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn                                \
    } /* Reset bits for PORT peripheral */
#define GPIO_RSTS_N                                  \
    {                                                \
        NotAvail_RSTn                                \
    } /* Reset bits for GPIO peripheral */
#define AON_LPADC_RSTS             \
    {                        \
        kAonLPADC_RST_SHIFT_RSTn \
    } /* Reset bits for AON_LPADC peripheral */
#endif /* Building on the AON core */

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
    RESET_ClearPeripheralReset(peripheral);
}

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* _FSL_RESET_H_ */
