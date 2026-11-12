/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_CLOCK_H_
#define _FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.0.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @brief Configure whether driver controls clock
 *
 * When set to 0, peripheral drivers will enable clock in initialize function
 * and disable clock in de-initialize function. When set to 1, peripheral
 * driver will not control the clock, application could control the clock out of
 * the driver.
 *
 * @note All drivers share this feature switcher. If it is set to 1, application
 * should handle clock enable and disable for all drivers.
 */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
#define FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL 0U
#endif

/*!
 * @brief User-defined the size of cache for CLOCK_PllGetConfig() function.
 *
 * Once define this MACRO to be non-zero value, CLOCK_PllGetConfig() function
 * would cache the recent calulation and accelerate the execution to get the
 * right settings.
 */
#ifndef CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT
#define CLOCK_USR_CFG_PLL_CONFIG_CACHE_COUNT 2U
#endif

/* Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (96000000U)
#endif

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/
#define CLK_GATE_REG_OFFSET(value) (((uint32_t)(value)) >> 16U)
#define CLK_GATE_BIT_SHIFT(value)  (((uint32_t)(value)) & 0x0000FFFFU)

#define REG_PWM0SUBCTL (250U)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_GateXBAR0    = ((0x00U << 16U) | (0U)),          /*!< Clock gate name: XBAR0     */
    kCLOCK_GateFREQME   = ((0x00U << 16U) | (1U)),          /*!< Clock gate name: FREQME    */
    kCLOCK_GatePWT0     = ((0x00U << 16U) | (5U)),          /*!< Clock gate name: PWT0      */
    kCLOCK_GatePWT1     = ((0x00U << 16U) | (6U)),          /*!< Clock gate name: PWT1      */
    kCLOCK_GateWWDT0    = ((0x00U << 16U) | (8U)),          /*!< Clock gate name: WWDT0     */
    kCLOCK_GateDMA0     = ((0x00U << 16U) | (10U)),         /*!< Clock gate name: DMA0      */
    kCLOCK_GatePIT0     = ((0x00U << 16U) | (11U)),         /*!< Clock gate name: PIT0      */
    kCLOCK_GateCRC0     = ((0x00U << 16U) | (12U)),         /*!< Clock gate name: CRC0      */
    kCLOCK_Crc0         = ((0x00U << 16U) | (12U)),         /*!< Clock gate name: CRC0      */
    kCLOCK_GateEIM0     = ((0x00U << 16U) | (13U)),         /*!< Clock gate name: EIM0      */
    kCLOCK_GateERM0     = ((0x00U << 16U) | (14U)),         /*!< Clock gate name: ERM0      */
    kCLOCK_GateFTM0     = ((0x00U << 16U) | (22U)),         /*!< Clock gate name: FTM0      */
    kCLOCK_GateQTMR0    = ((0x00U << 16U) | (24U)),         /*!< Clock gate name: QTMR0     */
    kCLOCK_GateAOI0     = ((0x00U << 16U) | (26U)),         /*!< Clock gate name: AOI0      */
    kCLOCK_GateFLEXPWM0 = ((0x00U << 16U) | (30U)),         /*!< Clock gate name: FLEXPWM0  */

    kCLOCK_GateLPI2C0  = ((0x10U << 16U) | (0U)),           /*!< Clock gate name: LPI2C0    */
    kCLOCK_GateLPI2C1  = ((0x10U << 16U) | (1U)),           /*!< Clock gate name: LPI2C1    */
    kCLOCK_GateLPSPI0  = ((0x10U << 16U) | (4U)),           /*!< Clock gate name: LPSPI0    */
    kCLOCK_GateLPUART0 = ((0x10U << 16U) | (8U)),           /*!< Clock gate name: LPUART0   */
    kCLOCK_GateLPUART1 = ((0x10U << 16U) | (9U)),           /*!< Clock gate name: LPUART1   */
    kCLOCK_GatePHD0    = ((0x10U << 16U) | (14U)),          /*!< Clock gate name: PHD0      */
    kCLOCK_GateADC0    = ((0x10U << 16U) | (16U)),          /*!< Clock gate name: ADC0      */
    kCLOCK_GateCMP0    = ((0x10U << 16U) | (20U)),          /*!< Clock gate name: CMP0      */
    kCLOCK_GateCMP1    = ((0x10U << 16U) | (21U)),          /*!< Clock gate name: CMP1      */
    kCLOCK_GateOPAMP0  = ((0x10U << 16U) | (25U)),          /*!< Clock gate name: OPAMP0    */

    kCLOCK_GatePORT0  = ((0x20U << 16U) | (0U)),            /*!< Clock gate name: PORT0     */
    kCLOCK_GatePORT1  = ((0x20U << 16U) | (1U)),            /*!< Clock gate name: PORT1     */
    kCLOCK_GatePORT2  = ((0x20U << 16U) | (2U)),            /*!< Clock gate name: PORT2     */
    kCLOCK_GatePORT3  = ((0x20U << 16U) | (3U)),            /*!< Clock gate name: PORT3     */
    kCLOCK_GateGPIO0  = ((0x20U << 16U) | (6U)),            /*!< Clock gate name: GPIO0     */
    kCLOCK_GateGPIO1  = ((0x20U << 16U) | (7U)),            /*!< Clock gate name: GPIO1     */
    kCLOCK_GateGPIO2  = ((0x20U << 16U) | (8U)),            /*!< Clock gate name: GPIO2     */
    kCLOCK_GateGPIO3  = ((0x20U << 16U) | (9U)),            /*!< Clock gate name: GPIO3     */
    kCLOCK_GateRAMA   = ((0x20U << 16U) | (12U)),           /*!< Clock gate name: RAMA      */
    kCLOCK_GateSECCON = ((0x20U << 16U) | (26U)),           /*!< Clock gate name: SECCON    */
    kCLOCK_GateMAU0   = ((0x20U << 16U) | (27U)),           /*!< Clock gate name: MAU0      */

    kCLOCK_GatePWM0SM0  = ((REG_PWM0SUBCTL << 16U) | (0U)), /*!< Clock gate name: PWM0 SM0  */
    kCLOCK_GatePWM0SM1  = ((REG_PWM0SUBCTL << 16U) | (1U)), /*!< Clock gate name: PWM0 SM1  */
    kCLOCK_GatePWM0SM2  = ((REG_PWM0SUBCTL << 16U) | (2U)), /*!< Clock gate name: PWM0 SM2  */
    kCLOCK_GatePWM0SM3  = ((REG_PWM0SUBCTL << 16U) | (3U)), /*!< Clock gate name: PWM0 SM3  */
    kCLOCK_GateNotAvail = (0xFFFFFFFFU),                    /*!< Clock gate name: None      */
} clock_ip_name_t;

typedef enum _pit_count_clock_source
{
    /* This part is used for PIT driver. */
    kPIT_CountClockSource0 = 0U, /*!< PIT count clock sourced from IP bus clock (SYSTEM_CLK) */
    kPIT_CountClockSource1 = 1U, /*!< PIT count clock sourced from alternate clock 1 (FRO_HF_DIV) */
    kPIT_CountClockSource2 = 2U, /*!< PIT count clock sourced from alternate clock 2 (FRO_LF_DIV) */
    kPIT_CountClockSource3 = 3U, /*!< PIT count clock sourced from alternate clock 3 (CLK_1M) */
    /* This part is used for users. */
    kPIT_CountBusClk      = kPIT_CountClockSource0, /*!< PIT count clock sourced from SYSTEM_CLK */
    kPIT_CountFroHfDivClk = kPIT_CountClockSource1, /*!< PIT count clock sourced from FRO_HF_DIV (alt_clk1) */
    kPIT_CountFroLfDivClk = kPIT_CountClockSource2, /*!< PIT count clock sourced from FRO_LF_DIV (alt_clk2) */
    kPIT_CountClk1MClk    = kPIT_CountClockSource3, /*!< PIT count clock sourced from CLK_1M (alt_clk3) */
} pit_count_clock_source_t;

/*! @brief Clock ip name array for ADC. */
#define ADC_CLOCKS {kCLOCK_GateADC0}
/*! @brief Clock ip name array for AOI. */
#define AOI_CLOCKS {kCLOCK_GateAOI0}
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS {kCLOCK_GateCRC0}
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS {kCLOCK_GateDMA0}
/*! @brief Clock gate name array for EDMA. */
#define EDMA_CLOCKS {kCLOCK_GateDMA0}
/*! @brief Clock ip name array for EIM. */
#define EIM_CLOCKS {kCLOCK_GateEIM0}
/*! @brief Clock ip name array for ERM. */
#define ERM_CLOCKS {kCLOCK_GateERM0}
/*! @brief Clock ip name array for FLEXPWM. */
#define FLEXPWM_CLOCKS {kCLOCK_GateFLEXPWM0}
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS {kCLOCK_GateFREQME}
/*! @brief Clock ip name array for FTM. */
#define FTM_CLOCKS {kCLOCK_GateFTM0}
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS {kCLOCK_GateGPIO0, kCLOCK_GateGPIO1, kCLOCK_GateGPIO2, kCLOCK_GateGPIO3}
/*! @brief Clock ip name array for HSCMP. */
#define HSCMP_CLOCKS {kCLOCK_GateCMP0, kCLOCK_GateCMP1}
/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS {kCLOCK_GateLPI2C0, kCLOCK_GateLPI2C1}
/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS {kCLOCK_GateLPSPI0}
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS {kCLOCK_GateLPUART0, kCLOCK_GateLPUART1}
/*! @brief Clock ip name array for MAU. */
#define MAU_CLOCKS {kCLOCK_GateMAU0}
/*! @brief Clock ip name array for OPAMP. */
#define OPAMP_CLOCKS {kCLOCK_GateOPAMP0}
/*! @brief Clock ip name array for PHD. */
#define PHD_CLOCKS {kCLOCK_GatePHD0}
/*! @brief Clock ip name array for PIT. */
#define PIT_CLOCKS {kCLOCK_GatePIT0}
/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS {kCLOCK_GatePORT0, kCLOCK_GatePORT1, kCLOCK_GatePORT2, kCLOCK_GatePORT3}
/*! @brief Clock ip name array for PWT. */
#define PWT_CLOCKS {kCLOCK_GatePWT0, kCLOCK_GatePWT1}
/*! @brief Clock ip name array for QTMR. */
#define TMR_CLOCKS {kCLOCK_GateQTMR0}
/*! @brief Clock ip name array for RAMA. */
#define RAMA_CLOCKS {kCLOCK_GateRAMA}
/*! @brief Clock ip name array for SECCON. */
#define SECCON_CLOCKS {kCLOCK_GateSECCON}
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS {kCLOCK_GateWWDT0}
/*! @brief Clock ip name array for XBAR. */
#define XBAR_CLOCKS {kCLOCK_GateNotAvail, kCLOCK_GateXBAR0}
/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS                                                                        \
    {                                                                                     \
        {kCLOCK_GatePWM0SM0, kCLOCK_GatePWM0SM1, kCLOCK_GatePWM0SM2, kCLOCK_GatePWM0SM3}, \
    }

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_MainClk,    /*!< MAIN_CLK                   */
    kCLOCK_CoreSysClk, /*!< Core/system clock(CPU_CLK) */
    kCLOCK_SYSTEM_CLK, /*!< SYSTEM clock/AHB_BUS       */
    kCLOCK_BusClk,     /*!< SYSTEM clock               */
    kCLOCK_ExtClk,     /*!< External Clock             */
    kCLOCK_FroHf,      /*!< FroHf                      */
    kCLOCK_FroHfDiv,   /*!< FroHfDiv                   */
    kCLOCK_Fro12M,     /*!< FRO12M                     */
    kCLOCK_Fro12MDiv,  /*!< FRO12MDiv                  */
    kCLOCK_Clk1M,      /*!< CLK1M                      */
    kCLOCK_Fro16K,     /*!< FRO16K                     */
    kCLOCK_Clk16K0,    /*!< CLK16K[0]                  */
    kCLOCK_Clk16K1,    /*!< CLK16K[1]                  */
    kCLOCK_SLOW_CLK,   /*!< SYSTEM_CLK divided by 4    */
} clock_name_t;

/*! @brief Peripherals clock source definition. */
#define BUS_CLK kCLOCK_BusClk

/*! @brief Clock Mux Switches
 *  The encoding is as follows each connection identified is 32bits wide while 24bits are valuable
 *  starting from LSB upwards
 *
 *  [4 bits for choice, 0 means invalid choice] [8 bits mux ID]*
 *
 */

#define CLK_ATTACH_REG_OFFSET(value) (((uint32_t)(value)) >> 16U)
#define CLK_ATTACH_CLK_SEL(value)    (((uint32_t)(value)) & 0x0000FFFFU)
#define CLK_ATTACH_MUX(reg, sel)     ((((uint32_t)(reg)) << 16U) | (sel))

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_select_name
{
    kCLOCK_SelLPI2C0      = (0x100U), /*!< LPI2C0      clock selection */
    kCLOCK_SelLPI2C1      = (0x108U), /*!< LPI2C1      clock selection */
    kCLOCK_SelLPSPI0      = (0x110U), /*!< LPSPI0      clock selection */
    kCLOCK_SelLPUART0     = (0x118U), /*!< LPUART0     clock selection */
    kCLOCK_SelLPUART1     = (0x120U), /*!< LPUART1     clock selection */
    kCLOCK_SelFTM0_EXTCLK = (0x128U), /*!< FTM0_EXTCLK clock selection */
    kCLOCK_SelFTM0_FIXCLK = (0x130U), /*!< FTM0_FIXCLK clock selection */
    kCLOCK_SelPWT0_ALTCLK = (0x138U), /*!< PWT0_ALTCLK clock selection */
    kCLOCK_SelPWT1_ALTCLK = (0x140U), /*!< PWT1_ALTCLK clock selection */
    kCLOCK_SelADC0        = (0x148U), /*!< ADC0        clock selection */
    kCLOCK_SelCMP0_RR     = (0x158U), /*!< CMP0_RR     clock selection */
    kCLOCK_SelCMP1_RR     = (0x168U), /*!< CMP1_RR     clock selection */
    kCLOCK_SelPHD0        = (0x170U), /*!< PHD0        clock selection */
    kCLOCK_SelWWDT0       = (0x178U), /*!< WWDT0       clock selection */
    kCLOCK_SelTRACE       = (0x180U), /*!< TRACE       clock selection */
    kCLOCK_SelCLKOUT      = (0x188U), /*!< CLKOUT      clock selection */
    kCLOCK_SelSYSTICK     = (0x190U), /*!< SYSTICK     clock selection */
    kCLOCK_SelSCGSCS      = (0x200U), /*!< SCG SCS     clock selection */
    kCLOCK_SelMax         = (0x200U), /*!< MAX         clock selection */
} clock_select_name_t;

/*!
 * @brief The enumerator of clock attach Id.
 */
typedef enum _clock_attach_id
{
    kCLK_IN_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 1U),          /*!< Attach clk_in to MAIN_CLK.     */
    kFRO12M_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 2U),          /*!< Attach FRO_12M to MAIN_CLK.    */
    kFRO_HF_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 3U),          /*!< Attach FRO_HF to MAIN_CLK.     */
    kCLK_16K_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 4U),          /*!< Attach CLK_16K to MAIN_CLK.    */
    kNONE_to_MAIN_CLK    = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 7U),          /*!< Attach NONE to MAIN_CLK.       */

    kFRO_LF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 0U),         /*!< Attach FRO_LF_DIV to LPI2C0. */
    kFRO_HF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 2U),         /*!< Attach FRO_HF_DIV to LPI2C0. */
    kCLK_IN_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 3U),         /*!< Attach CLK_IN to LPI2C0.     */
    kCLK_1M_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 5U),         /*!< Attach CLK_1M to LPI2C0.     */
    kNONE_to_LPI2C0       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 7U),         /*!< Attach NONE to LPI2C0.       */

    kFRO_LF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 0U),         /*!< Attach FRO_LF_DIV to LPI2C1. */
    kFRO_HF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 2U),         /*!< Attach FRO_HF_DIV to LPI2C1. */
    kCLK_IN_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 3U),         /*!< Attach CLK_IN to LPI2C1.     */
    kCLK_1M_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 5U),         /*!< Attach CLK_1M to LPI2C1.     */
    kNONE_to_LPI2C1       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 7U),         /*!< Attach NONE to LPI2C1.       */

    kFRO_LF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 0U),         /*!< Attach FRO_LF_DIV to LPSPI0. */
    kFRO_HF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 2U),         /*!< Attach FRO_HF_DIV to LPSPI0. */
    kCLK_IN_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 3U),         /*!< Attach CLK_IN to LPSPI0.     */
    kCLK_1M_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 5U),         /*!< Attach CLK_1M to LPSPI0.     */
    kNONE_to_LPSPI0       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 7U),         /*!< Attach NONE to LPSPI0.       */

    kFRO_LF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 0U),       /*!< Attach FRO_LF_DIV to LPUART0. */
    kFRO_HF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 2U),       /*!< Attach FRO_HF_DIV to LPUART0. */
    kCLK_IN_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 3U),       /*!< Attach CLK_IN to LPUART0.     */
    kCLK_16K_to_LPUART0    = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 4U),       /*!< Attach CLK_16K to LPUART0.    */
    kCLK_1M_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 5U),       /*!< Attach CLK_1M to LPUART0.     */
    kNONE_to_LPUART0       = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 7U),       /*!< Attach NONE to LPUART0.       */

    kFRO_LF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 0U),       /*!< Attach FRO_LF_DIV to LPUART1. */
    kFRO_HF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 2U),       /*!< Attach FRO_HF_DIV to LPUART1. */
    kCLK_IN_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 3U),       /*!< Attach CLK_IN to LPUART1.     */
    kCLK_16K_to_LPUART1    = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 4U),       /*!< Attach CLK_16K to LPUART1.    */
    kCLK_1M_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 5U),       /*!< Attach CLK_1M to LPUART1.     */
    kNONE_to_LPUART1       = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 7U),       /*!< Attach NONE to LPUART1.       */

    kALT_CLK0_to_FTM0_EXTCLK = CLK_ATTACH_MUX(kCLOCK_SelFTM0_EXTCLK, 0U), /*!< Attach ALT_CLK0 to FTM0_EXTCLK. */
    kALT_CLK1_to_FTM0_EXTCLK = CLK_ATTACH_MUX(kCLOCK_SelFTM0_EXTCLK, 1U), /*!< Attach ALT_CLK1 to FTM0_EXTCLK. */
    kALT_CLK2_to_FTM0_EXTCLK = CLK_ATTACH_MUX(kCLOCK_SelFTM0_EXTCLK, 2U), /*!< Attach ALT_CLK2 to FTM0_EXTCLK. */
    kALT_CLK3_to_FTM0_EXTCLK = CLK_ATTACH_MUX(kCLOCK_SelFTM0_EXTCLK, 3U), /*!< Attach ALT_CLK3 to FTM0_EXTCLK. */

    kCLK_48M_to_FTM0_FIXCLK  = CLK_ATTACH_MUX(kCLOCK_SelFTM0_FIXCLK, 0U), /*!< Attach CLK_48M to FTM0_FIXCLK. */
    kFRO_12M_to_FTM0_FIXCLK  = CLK_ATTACH_MUX(kCLOCK_SelFTM0_FIXCLK, 1U), /*!< Attach FRO_12M to FTM0_FIXCLK. */
    kCLK_1M_to_FTM0_FIXCLK   = CLK_ATTACH_MUX(kCLOCK_SelFTM0_FIXCLK, 2U), /*!< Attach CLK_1M to FTM0_FIXCLK.  */
    kSLOW_CLK_to_FTM0_FIXCLK = CLK_ATTACH_MUX(kCLOCK_SelFTM0_FIXCLK, 3U), /*!< Attach SLOW_CLK to FTM0_FIXCLK. */

    kALT_CLK0_to_PWT0_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT0_ALTCLK, 0U), /*!< Attach ALT_CLK0 to PWT0_ALTCLK. */
    kALT_CLK1_to_PWT0_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT0_ALTCLK, 1U), /*!< Attach ALT_CLK1 to PWT0_ALTCLK. */
    kALT_CLK2_to_PWT0_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT0_ALTCLK, 2U), /*!< Attach ALT_CLK2 to PWT0_ALTCLK. */
    kALT_CLK3_to_PWT0_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT0_ALTCLK, 3U), /*!< Attach ALT_CLK3 to PWT0_ALTCLK. */

    kALT_CLK0_to_PWT1_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT1_ALTCLK, 0U), /*!< Attach ALT_CLK0 to PWT1_ALTCLK. */
    kALT_CLK1_to_PWT1_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT1_ALTCLK, 1U), /*!< Attach ALT_CLK1 to PWT1_ALTCLK. */
    kALT_CLK2_to_PWT1_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT1_ALTCLK, 2U), /*!< Attach ALT_CLK2 to PWT1_ALTCLK. */
    kALT_CLK3_to_PWT1_ALTCLK = CLK_ATTACH_MUX(kCLOCK_SelPWT1_ALTCLK, 3U), /*!< Attach ALT_CLK3 to PWT1_ALTCLK. */

    kFRO_LF_DIV_to_ADC0   = CLK_ATTACH_MUX(kCLOCK_SelADC0, 0U),           /*!< Attach FRO_LF_DIV to ADC0.    */
    kFRO_HF_to_ADC0       = CLK_ATTACH_MUX(kCLOCK_SelADC0, 1U),           /*!< Attach FRO_HF to ADC0.        */
    kCLK_IN_to_ADC0       = CLK_ATTACH_MUX(kCLOCK_SelADC0, 3U),           /*!< Attach CLK_IN to ADC0.        */
    kCLK_48M_to_ADC0      = CLK_ATTACH_MUX(kCLOCK_SelADC0, 4U),           /*!< Attach CLK_48M to ADC0.       */
    kCLK_1M_to_ADC0       = CLK_ATTACH_MUX(kCLOCK_SelADC0, 5U),           /*!< Attach CLK_1M to ADC0.        */
    kNONE_to_ADC0         = CLK_ATTACH_MUX(kCLOCK_SelADC0, 7U),           /*!< Attach NONE to ADC0.          */

    kFRO_LF_DIV_to_CMP0_RR = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 0U),       /*!< Attach FRO_LF_DIV to CMP0_RR. */
    kFRO_HF_DIV_to_CMP0_RR = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 2U),       /*!< Attach FRO_HF_DIV to CMP0_RR. */
    kCLK_IN_to_CMP0_RR     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 3U),       /*!< Attach CLK_IN to CMP0_RR.     */
    kCLK_1M_to_CMP0_RR     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 5U),       /*!< Attach CLK_1M to CMP0_RR.     */
    kNONE_to_CMP0_RR       = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 7U),       /*!< Attach NONE to CMP0_RR.       */

    kFRO_LF_DIV_to_CMP1_RR = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 0U),       /*!< Attach FRO_LF_DIV to CMP1_RR. */
    kFRO_HF_DIV_to_CMP1_RR = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 2U),       /*!< Attach FRO_HF_DIV to CMP1_RR. */
    kCLK_IN_to_CMP1_RR     = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 3U),       /*!< Attach CLK_IN to CMP1_RR.     */
    kCLK_1M_to_CMP1_RR     = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 5U),       /*!< Attach CLK_1M to CMP1_RR.     */
    kNONE_to_CMP1_RR       = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 7U),       /*!< Attach NONE to CMP1_RR.       */

    kFRO_LF_DIV_to_PHD0 = CLK_ATTACH_MUX(kCLOCK_SelPHD0, 0U),             /*!< Attach FRO_LF_DIV to PHD0. */
    kFRO_HF_DIV_to_PHD0 = CLK_ATTACH_MUX(kCLOCK_SelPHD0, 2U),             /*!< Attach FRO_HF_DIV to PHD0. */
    kCLK_IN_to_PHD0     = CLK_ATTACH_MUX(kCLOCK_SelPHD0, 3U),             /*!< Attach CLK_IN to PHD0.     */
    kCLK_1M_to_PHD0     = CLK_ATTACH_MUX(kCLOCK_SelPHD0, 5U),             /*!< Attach CLK_1M to PHD0.     */
    kNONE_to_PHD0       = CLK_ATTACH_MUX(kCLOCK_SelPHD0, 7U),             /*!< Attach NONE to PHD0.       */

    kCLK_16K_to_WWDT0    = CLK_ATTACH_MUX(kCLOCK_SelWWDT0, 0U),           /*!< Attach CLK_16K to WWDT0.      */
    kFRO_HF_DIV_to_WWDT0 = CLK_ATTACH_MUX(kCLOCK_SelWWDT0, 1U),           /*!< Attach FRO_HF_DIV to WWDT0.   */
    kCLK_1M_to_WWDT0     = CLK_ATTACH_MUX(kCLOCK_SelWWDT0, 2U),           /*!< Attach CLK_1M to WWDT0.       */

    kCPU_CLK_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 0U),              /*!< Attach CPU_CLK to TRACE. */
    kCLK_1M_to_TRACE  = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 1U),              /*!< Attach CLK_1M to TRACE.  */
    kCLK_16K_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 2U),              /*!< Attach CLK_16K to TRACE. */
    kNONE_to_TRACE    = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 3U),              /*!< Attach NONE to TRACE.    */

    kFRO12M_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 0U),         /*!< Attach FRO_12M to CLKOUT.    */
    kFRO_HF_DIV_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 1U),         /*!< Attach FRO_HF_DIV to CLKOUT. */
    kCLK_IN_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 2U),         /*!< Attach CLK_IN to CLKOUT.     */
    kCLK_16K_to_CLKOUT    = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 3U),         /*!< Attach CLK_16K to CLKOUT.    */
    kSLOW_CLK_to_CLKOUT   = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 6U),         /*!< Attach SLOW_CLK to CLKOUT.   */
    kNONE_to_CLKOUT       = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 7U),         /*!< Attach NONE to CLKOUT.       */

    kCPU_CLK_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 0U),          /*!< Attach CPU_CLK to SYSTICK. */
    kCLK_1M_to_SYSTICK  = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 1U),          /*!< Attach CLK_1M to SYSTICK.  */
    kCLK_16K_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 2U),          /*!< Attach CLK_16K to SYSTICK. */
    kNONE_to_SYSTICK    = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 3U),          /*!< Attach NONE to SYSTICK.    */

    kNONE_to_NONE = (0xFFFFFFFFU),                                        /*!< Attach NONE to NONE. */

} clock_attach_id_t;

/*! @brief Clock dividers */
typedef enum _clock_div_name
{
    kCLOCK_DivAHBCLK    = (0x80U),          /*!< AHBCLK    clock divider */
    kCLOCK_DivSLOWCLK   = (0x88U),          /*!< SLOWCLK   clock divider */
    kCLOCK_DivFRO_HF    = (0x90U),          /*!< FROHF     clock divider */
    kCLOCK_DivFRO_LF    = (0x94U),          /*!< FROLF     clock divider */
    kCLOCK_DivLPI2C0    = (0x104U + 0x800), /*!< LPI2C0    clock divider */
    kCLOCK_DivLPI2C1    = (0x10CU + 0x800), /*!< LPI2C1    clock divider */
    kCLOCK_DivLPSPI0    = (0x114U + 0x800), /*!< LPSPI0    clock divider */
    kCLOCK_DivLPUART0   = (0x11CU + 0x800), /*!< LPUART0   clock divider */
    kCLOCK_DivLPUART1   = (0x124U + 0x800), /*!< LPUART1   clock divider */
    kCLOCK_DivADC0      = (0x14CU + 0x800), /*!< ADC0      clock divider */
    kCLOCK_DivCMP0_FUNC = (0x154U + 0x800), /*!< CMP0_FUNC clock divider */
    kCLOCK_DivCMP0_RR   = (0x15CU + 0x800), /*!< CMP0_RR   clock divider */
    kCLOCK_DivCMP1_FUNC = (0x164U + 0x800), /*!< CMP1_FUNC clock divider */
    kCLOCK_DivCMP1_RR   = (0x16CU + 0x800), /*!< CMP1_RR   clock divider */
    kCLOCK_DivPHD0      = (0x174U + 0x800), /*!< PHD0      clock divider */
    kCLOCK_DivWWDT0     = (0x17CU + 0x800), /*!< WWDT0     clock divider */
    kCLOCK_DivTRACE     = (0x184U + 0x800), /*!< TRACE     clock divider */
    kCLOCK_DivCLKOUT    = (0x18CU + 0x800), /*!< CLKOUT    clock divider */
    kCLOCK_DivSYSTICK   = (0x194U + 0x800), /*!< SYSTICK   clock divider */
    kCLOCK_DivMax       = (0x194U + 0x800), /*!< MAX       clock divider */
} clock_div_name_t;

/*!
 * @brief firc trim source.
 */
typedef enum _clke_16k
{
    kCLKE_16K_SYSTEM   = VBAT_FROCLKE_CLKE(1U), /*!< To VSYS domain.     */
    kCLKE_16K_COREMAIN = VBAT_FROCLKE_CLKE(2U), /*!< To VDD_CORE domain. */
    kCLKE_16K_ALL      = VBAT_FROCLKE_CLKE(3U)  /*!< To all domains.     */
} clke_16k_t;

/*!
 * @brief SCG status return codes.
 */
enum _scg_status
{
    kStatus_SCG_Busy       = MAKE_STATUS(kStatusGroup_SCG, 1), /*!< Clock is busy.  */
    kStatus_SCG_InvalidSrc = MAKE_STATUS(kStatusGroup_SCG, 2)  /*!< Invalid source. */
};

/*!
 * @brief SCG system OSC monitor mode.
 */
typedef enum _scg_sosc_monitor_mode
{
    kSCG_SysOscMonitorDisable = 0U,                         /*!< Monitor disabled. */
    kSCG_SysOscMonitorInt     = SCG_SOSCCSR_SOSCCM_MASK,    /*!< Interrupt when the SOSC error is detected. */
    kSCG_SysOscMonitorReset =
        SCG_SOSCCSR_SOSCCM_MASK | SCG_SOSCCSR_SOSCCMRE_MASK /*!< Reset when the SOSC error is detected.     */
} scg_sosc_monitor_mode_t;

/*!
 * @brief The active run mode (voltage level).
 */
typedef enum _run_mode
{
    kOD_Mode, /*!< OD Mode */
} run_mode_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Enable the clock for specific IP.
 * @param clk : Clock to be enabled.
 * @return  Nothing
 */
static inline void CLOCK_EnableClock(clock_ip_name_t clk)
{
    uint32_t reg_offset         = CLK_GATE_REG_OFFSET(clk);
    uint32_t bit_shift          = CLK_GATE_BIT_SHIFT(clk);
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC->MRCC_GLB_CC0_SET)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_LOCK_MASK;

    if (reg_offset == REG_PWM0SUBCTL)
    {
        SYSCON->PWM0SUBCTL |= (1UL << bit_shift);
        MRCC->MRCC_GLB_CC0_SET = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
    }
    else
    {
        *pClkCtrl = (1UL << bit_shift);
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_LOCK_MASK;
}

/**
 * @brief Disable the clock for specific IP.
 * @param clk : Clock to be Disabled.
 * @return  Nothing
 */
static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
    uint32_t reg_offset         = CLK_GATE_REG_OFFSET(clk);
    uint32_t bit_shift          = CLK_GATE_BIT_SHIFT(clk);
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC->MRCC_GLB_CC0_CLR)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_LOCK_MASK;

    if (reg_offset == REG_PWM0SUBCTL)
    {
        SYSCON->PWM0SUBCTL &= ~(1UL << bit_shift);

        if (0U == (SYSCON->PWM0SUBCTL & 0xFU))
        {
            MRCC->MRCC_GLB_CC0_CLR = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
        }
    }
    else
    {
        *pClkCtrl = (1UL << bit_shift);
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_LOCK_MASK;
}

/**
 * @brief   Configure the clock selection muxes.
 * @param   connection  : Clock to be configured.
 */
void CLOCK_AttachClk(clock_attach_id_t connection);

/**
 * @brief   Get the actual clock attach id.
 * This fuction uses the offset in input attach id, then it reads the actual source value in
 * the register and combine the offset to obtain an actual attach id.
 * @param   connection  : Clock attach id to get.
 * @return  Clock source value.
 */
clock_attach_id_t CLOCK_GetClockAttachId(clock_attach_id_t connection);

/**
 * @brief   Set the clock select value.
 * This fuction set the peripheral clock select value.
 * @param   sel_name : Clock select.
 * @param   value    : value to be set.
 */
void CLOCK_SetClockSelect(clock_select_name_t sel_name, uint32_t value);

/**
 * @brief   Get the clock select value.
 * This fuction get the peripheral clock select value.
 * @param   sel_name  : Clock select.
 * @return  Clock source value.
 */
uint32_t CLOCK_GetClockSelect(clock_select_name_t sel_name);

/**
 * @brief   Setup peripheral clock dividers.
 * @param   div_name : Clock divider name
 * @param   value    : Value to be divided
 */
void CLOCK_SetClockDiv(clock_div_name_t div_name, uint32_t value);

/**
 * @brief   Get peripheral clock dividers.
 * @param   div_name    : Clock divider name
 * @return  peripheral clock dividers
 */
uint32_t CLOCK_GetClockDiv(clock_div_name_t div_name);

/**
 * @brief   Halt peripheral clock dividers.
 * @param   div_name    : Clock divider name
 */
void CLOCK_HaltClockDiv(clock_div_name_t div_name);

/**
 * @brief   Initialize the FROHF to given frequency (48, 64, 96, 192).
 * This function turns on FIRC and select the given frequency as the source of fro_hf
 * @param   iFreq   : Desired frequency.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq);

/**
 * @brief   Initialize the FRO16K.
 * This function turns on FRO16K.
 * @param   clk_16k_enable_mask: 0-3
 *             0b00: disable both clk_16k0 and clk_16k1
 *             0b01: only enable clk_16k0
 *             0b10: only enable clk_16k1
 *             0b11: enable both clk_16k0 and clk_16k1
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFRO16KClocking(uint8_t clk_16k_enable_mask);

/**
 * @brief   Initialize the external osc clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtClocking(uint32_t iFreq);

/**
 * @brief   Initialize the external reference clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtRefClocking(uint32_t iFreq);

/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*! @brief  Return Frequency of core
 *  @return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*! @brief  Return Frequency of LPI2C0 functional Clock
 *  @return Frequency of LPI2C0 functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPSPI functional Clock
 *  @return Frequency of LPSPI functional Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPUART functional Clock
 *  @return Frequency of LPUART functional Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id);

/*! @brief  Return Frequency of Adc Clock
 *  @return Frequency of Adc.
 */
uint32_t CLOCK_GetAdcClkFreq(uint32_t id);

/*! @brief  Return Frequency of CMP Function Clock
 *  @return Frequency of CMP Function.
 */
uint32_t CLOCK_GetCmpFClkFreq(uint32_t id);

/*! @brief  Return Frequency of CMP Round Robin Clock
 *  @return Frequency of CMP Round Robin.
 */
uint32_t CLOCK_GetCmpRRClkFreq(uint32_t id);

/*! @brief  Return Frequency of Trace Clock
 *  @return Frequency of Trace.
 */
uint32_t CLOCK_GetTraceClkFreq(void);

/*! @brief  Return Frequency of CLKOUT Clock
 *  @return Frequency of CLKOUT.
 */
uint32_t CLOCK_GetClkoutClkFreq(void);

/*! @brief  Return Frequency of Systick Clock
 *  @return Frequency of Systick.
 */
uint32_t CLOCK_GetSystickClkFreq(void);

/*! brief  Return Frequency of Systick Clock
 *  return Frequency of Systick.
 */
uint32_t CLOCK_GetWwdtClkFreq(void);

/*!
 * @brief Sets the system OSC monitor mode.
 *
 * This function sets the system OSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetSysOscMonitorMode(scg_sosc_monitor_mode_t mode);

/*!
 * @brief   Set the additional number of wait-states added to account for the ratio of system clock period to flash
 * access time during full speed power mode.
 * @param   system_freq_hz  : Input frequency
 * @param   mode            : Active run mode (voltage level).
 * @return  success or fail status
 */
status_t CLOCK_SetFLASHAccessCyclesForFreq(uint32_t system_freq_hz, run_mode_t mode);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
