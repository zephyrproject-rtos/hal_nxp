/*
 * Copyright 2025-2026 NXP
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
/*! @brief CLOCK driver version 2.0.1. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
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
    kCLOCK_InputMux      = ((0x00U << 16U) | (0U)),         /*!< Clock gate name: INPUTMUX0 */
    kCLOCK_GateINPUTMUX0 = ((0x00U << 16U) | (0U)),         /*!< Clock gate name: INPUTMUX0 */
    kCLOCK_GateFREQME    = ((0x00U << 16U) | (1U)),         /*!< Clock gate name: FREQME    */
    kCLOCK_GateCTIMER0   = ((0x00U << 16U) | (2U)),         /*!< Clock gate name: CTIMER0   */
    kCLOCK_GateCTIMER1   = ((0x00U << 16U) | (3U)),         /*!< Clock gate name: CTIMER1   */
    kCLOCK_GateWWDT0     = ((0x00U << 16U) | (8U)),         /*!< Clock gate name: WWDT0     */
    kCLOCK_GateWWDT1     = ((0x00U << 16U) | (9U)),         /*!< Clock gate name: WWDT1     */
    kCLOCK_GateDMA0      = ((0x00U << 16U) | (10U)),        /*!< Clock gate name: DMA0      */
    kCLOCK_GateCRC0      = ((0x00U << 16U) | (12U)),        /*!< Clock gate name: CRC0      */
    kCLOCK_Crc0          = ((0x00U << 16U) | (12U)),        /*!< Clock gate name: CRC0      */
    kCLOCK_GateEIM0      = ((0x00U << 16U) | (13U)),        /*!< Clock gate name: EIM0      */
    kCLOCK_GateERM0      = ((0x00U << 16U) | (14U)),        /*!< Clock gate name: ERM0      */
    kCLOCK_GateFLEXPWM0  = ((0x00U << 16U) | (30U)),        /*!< Clock gate name: FLEXPWM0  */

    kCLOCK_GateLPI2C0  = ((0x10U << 16U) | (0U)),           /*!< Clock gate name: LPI2C0    */
    kCLOCK_GateLPSPI0  = ((0x10U << 16U) | (4U)),           /*!< Clock gate name: LPSPI0    */
    kCLOCK_GateLPUART0 = ((0x10U << 16U) | (8U)),           /*!< Clock gate name: LPUART0   */
    kCLOCK_GateLPUART1 = ((0x10U << 16U) | (9U)),           /*!< Clock gate name: LPUART1   */
    kCLOCK_GateLPUART2 = ((0x10U << 16U) | (10U)),          /*!< Clock gate name: LPUART2   */
    kCLOCK_GateLPUART3 = ((0x10U << 16U) | (11U)),          /*!< Clock gate name: LPUART3   */
    kCLOCK_GateADC0    = ((0x10U << 16U) | (16U)),          /*!< Clock gate name: ADC0      */
    kCLOCK_GateCMP0    = ((0x10U << 16U) | (20U)),          /*!< Clock gate name: CMP0      */
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
    kCLOCK_GateTRNG0  = ((0x20U << 16U) | (25U)),           /*!< Clock gate name: TRNG0     */
    kCLOCK_GateSECCON = ((0x20U << 16U) | (26U)),           /*!< Clock gate name: SECCON    */

    kCLOCK_GatePWM0SM0  = ((REG_PWM0SUBCTL << 16U) | (0U)), /*!< Clock gate name: PWM0 SM0  */
    kCLOCK_GatePWM0SM1  = ((REG_PWM0SUBCTL << 16U) | (1U)), /*!< Clock gate name: PWM0 SM1  */
    kCLOCK_GatePWM0SM2  = ((REG_PWM0SUBCTL << 16U) | (2U)), /*!< Clock gate name: PWM0 SM2  */
    kCLOCK_GateNotAvail = (0xFFFFFFFFU),                    /*!< Clock gate name: None      */
} clock_ip_name_t;

/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS {kCLOCK_GateCRC0}
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS {kCLOCK_GateCTIMER0, kCLOCK_GateCTIMER1}
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS {kCLOCK_GateDMA0}
/*! @brief Clock gate name array for EDMA. */
#define EDMA_CLOCKS {kCLOCK_GateDMA0}
/*! @brief Clock ip name array for ERM. */
#define ERM_CLOCKS {kCLOCK_GateERM0}
/*! @brief Clock ip name array for EIM. */
#define EIM_CLOCKS {kCLOCK_GateEIM0}
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS {kCLOCK_GateFREQME}
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS {kCLOCK_GateGPIO0, kCLOCK_GateGPIO1, kCLOCK_GateGPIO2, kCLOCK_GateGPIO3}
/*! @brief Clock ip name array for INPUTMUX. */
#define INPUTMUX_CLOCKS {kCLOCK_GateINPUTMUX0}
/*! @brief Clock ip name array for LPCMP. */
#define LPCMP_CLOCKS {kCLOCK_GateCMP0}
/*! @brief Clock ip name array for LPADC. */
#define LPADC_CLOCKS {kCLOCK_GateADC0}
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS {kCLOCK_GateLPUART0, kCLOCK_GateLPUART1, kCLOCK_GateLPUART2, kCLOCK_GateLPUART3}
/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS {kCLOCK_GateLPI2C0}
/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS {kCLOCK_GateLPSPI0}
/*! @brief Clock ip name array for OPAMP. */
#define OPAMP_CLOCKS {kCLOCK_GateOPAMP0}
/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS {kCLOCK_GatePORT0, kCLOCK_GatePORT1, kCLOCK_GatePORT2, kCLOCK_GatePORT3}
/*! @brief Clock ip name array for TRNG. */
#define TRNG_CLOCKS {kCLOCK_GateTRNG0}
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS {kCLOCK_GateWWDT0, kCLOCK_GateWWDT1}
/*! @brief Clock ip name array for FLEXPWM. */
#define FLEXPWM_CLOCKS {kCLOCK_GateFLEXPWM0}
/*! @brief Clock ip name array for RAMA. */
#define RAMA_CLOCKS {kCLOCK_GateRAMA}
/*! @brief Clock ip name array for SECCON. */
#define SECCON_CLOCKS {kCLOCK_GateSECCON}
/*! @brief Clock ip name array for ATX. */
#define ATX_CLOCKS {kCLOCK_GateATX0}
/*! @brief Clock ip name array for TCU. */
#define TCU_CLOCKS {kCLOCK_GateTCU}
/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS                                                    \
    {                                                                 \
        {kCLOCK_GatePWM0SM0, kCLOCK_GatePWM0SM1, kCLOCK_GatePWM0SM2}, \
    }

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_MainClk,    /*!< MAIN_CLK                   */
    kCLOCK_CoreSysClk, /*!< Core/system clock(CPU_CLK) */
    kCLOCK_SYSTEM_CLK, /*!< SYSTEM clock/AHB_BUS       */
    kCLOCK_BusClk,     /*!< SYSTEM clock               */
    kCLOCK_ExtClk,     /*!< External Clock             */
    kCLOCK_FroHf,      /*!< FRO192                     */
    kCLOCK_FroHfDiv,   /*!< Divided by FRO192          */
    kCLOCK_Fro12M,     /*!< FRO12M                     */
    kCLOCK_Fro12MDiv,  /*!< FRO12MDiv                  */
    kCLOCK_Clk1M,      /*!< CLK1M                      */
    kCLOCK_Fro16K,     /*!< FRO16K                     */
    kCLOCK_Clk16K0,    /*!< CLK16K[0]                  */
    kCLOCK_Clk16K1,    /*!< CLK16K[1]                  */
    kCLOCK_Osc32K0,    /*!< OSC32K[0]                  */
    kCLOCK_Osc32K1,    /*!< OSC32K[1]                  */
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
    kCLOCK_SelCTIMER0 = (0x100U), /*!< CTIMER0 clock selection */
    kCLOCK_SelCTIMER1 = (0x108U), /*!< CTIMER1 clock selection */
    kCLOCK_SelWWDT1   = (0x118U), /*!< WWDT1   clock selection */
    kCLOCK_SelLPI2C0  = (0x120U), /*!< LPI2C0  clock selection */
    kCLOCK_SelLPSPI0  = (0x128U), /*!< LPSPI0  clock selection */
    kCLOCK_SelLPUART0 = (0x130U), /*!< LPUART0 clock selection */
    kCLOCK_SelLPUART1 = (0x138U), /*!< LPUART1 clock selection */
    kCLOCK_SelLPUART2 = (0x140U), /*!< LPUART2 clock selection */
    kCLOCK_SelLPUART3 = (0x148U), /*!< LPUART3 clock selection */
    kCLOCK_SelLPTMR0  = (0x150U), /*!< LPTMR0  clock selection */
    kCLOCK_SelADC     = (0x158U), /*!< ADC     clock selection */
    kCLOCK_SelCMP0    = (0x168U), /*!< CMP0    clock selection */
    kCLOCK_SelTRACE   = (0x170U), /*!< TRACE   clock selection */
    kCLOCK_SelCLKOUT  = (0x178U), /*!< CLKOUT  clock selection */
    kCLOCK_SelSYSTICK = (0x180U), /*!< SYSTICK clock selection */
    kCLOCK_SelSCGSCS  = (0x200U), /*!< SCG SCS clock selection */
    kCLOCK_SelMax     = (0x200U), /*!< MAX     clock selection */
} clock_select_name_t;

/*!
 * @brief The enumerator of clock attach Id.
 */
typedef enum _clock_attach_id
{
    kCLK_IN_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 1U),    /*!< Attach clk_in to MAIN_CLK.     */
    kFRO12M_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 2U),    /*!< Attach FRO_12M to MAIN_CLK.    */
    kFRO_HF_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 3U),    /*!< Attach FRO_HF to MAIN_CLK.     */
    kCLK_32K_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 4U),    /*!< Attach CLK_32K[1] to MAIN_CLK. */
    kNONE_to_MAIN_CLK    = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 7U),    /*!< Attach NONE to MAIN_CLK.       */

    kFRO_LF_DIV_to_CTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 0U), /*!< Attach FRO_LF_DIV to CTIMER0. */
    kFRO_HF_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 1U), /*!< Attach FRO_HF to CTIMER0.     */
    kCLK_IN_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 3U), /*!< Attach CLK_IN to CTIMER0.     */
    kCLK_16K_to_CTIMER0    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 4U), /*!< Attach CLK_16K to CTIMER0.    */
    kCLK_1M_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 5U), /*!< Attach CLK_1M to CTIMER0.     */
    kNONE_to_CTIMER0       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 7U), /*!< Attach NONE to CTIMER0.       */

    kFRO_LF_DIV_to_CTIMER1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 0U), /*!< Attach FRO_LF_DIV to CTIMER1. */
    kFRO_HF_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 1U), /*!< Attach FRO_HF to CTIMER1.     */
    kCLK_IN_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 3U), /*!< Attach CLK_IN to CTIMER1.     */
    kCLK_16K_to_CTIMER1    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 4U), /*!< Attach CLK_16K to CTIMER1.    */
    kCLK_1M_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 5U), /*!< Attach CLK_1M to CTIMER1.     */
    kNONE_to_CTIMER1       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 7U), /*!< Attach NONE to CTIMER1.       */

    kFRO_LF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 0U),   /*!< Attach FRO_LF_DIV to LPI2C0. */
    kFRO_HF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 2U),   /*!< Attach FRO_HF_DIV to LPI2C0. */
    kCLK_IN_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 3U),   /*!< Attach CLK_IN to LPI2C0.     */
    kCLK_1M_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 5U),   /*!< Attach CLK_1M to LPI2C0.     */
    kNONE_to_LPI2C0       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 7U),   /*!< Attach NONE to LPI2C0.       */

    kFRO_LF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 0U),   /*!< Attach FRO_LF_DIV to LPSPI0. */
    kFRO_HF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 2U),   /*!< Attach FRO_HF_DIV to LPSPI0. */
    kCLK_IN_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 3U),   /*!< Attach CLK_IN to LPSPI0.     */
    kCLK_1M_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 5U),   /*!< Attach CLK_1M to LPSPI0.     */
    kNONE_to_LPSPI0       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 7U),   /*!< Attach NONE to LPSPI0.       */

    kFRO_LF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 0U), /*!< Attach FRO_LF_DIV to LPUART0. */
    kFRO_HF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 2U), /*!< Attach FRO_HF_DIV to LPUART0. */
    kCLK_IN_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 3U), /*!< Attach CLK_IN to LPUART0.     */
    kCLK_32K_to_LPUART0    = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 4U), /*!< Attach CLK_16K to LPUART0.    */
    kCLK_1M_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 5U), /*!< Attach CLK_1M to LPUART0.     */
    kNONE_to_LPUART0       = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 7U), /*!< Attach NONE to LPUART0.       */

    kFRO_LF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 0U), /*!< Attach FRO_LF_DIV to LPUART1. */
    kFRO_HF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 2U), /*!< Attach FRO_HF_DIV to LPUART1. */
    kCLK_IN_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 3U), /*!< Attach CLK_IN to LPUART1.     */
    kCLK_32K_to_LPUART1    = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 4U), /*!< Attach CLK_16K to LPUART1.    */
    kCLK_1M_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 5U), /*!< Attach CLK_1M to LPUART1.     */
    kNONE_to_LPUART1       = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 7U), /*!< Attach NONE to LPUART1.       */

    kFRO_LF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 0U), /*!< Attach FRO_LF_DIV to LPUART2. */
    kFRO_HF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 2U), /*!< Attach FRO_HF_DIV to LPUART2. */
    kCLK_IN_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 3U), /*!< Attach CLK_IN to LPUART2.     */
    kCLK_32K_to_LPUART2    = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 4U), /*!< Attach CLK_16K to LPUART2.    */
    kCLK_1M_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 5U), /*!< Attach CLK_1M to LPUART2.     */
    kNONE_to_LPUART2       = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 7U), /*!< Attach NONE to LPUART2.       */

    kFRO_LF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 0U), /*!< Attach FRO_LF_DIV to LPUART2. */
    kFRO_HF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 2U), /*!< Attach FRO_HF_DIV to LPUART2. */
    kCLK_IN_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 3U), /*!< Attach CLK_IN to LPUART2.     */
    kCLK_32K_to_LPUART3    = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 4U), /*!< Attach CLK_16K to LPUART2.    */
    kCLK_1M_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 5U), /*!< Attach CLK_1M to LPUART2.     */
    kNONE_to_LPUART3       = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 7U), /*!< Attach NONE to LPUART2.       */

    kFRO_LF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 0U),   /*!< Attach FRO_LF_DIV to LPTMR0. */
    kFRO_HF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 2U),   /*!< Attach FRO_HF_DIV to LPTMR0. */
    kCLK_IN_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 3U),   /*!< Attach CLK_IN to LPTMR0.     */
    kCLK_1M_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 5U),   /*!< Attach CLK_1M to LPTMR0.     */
    kNONE_to_LPTMR0       = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 7U),   /*!< Attach NONE to LPTMR0.       */

    kFRO_LF_DIV_to_ADC = CLK_ATTACH_MUX(kCLOCK_SelADC, 0U),         /*!< Attach FRO_LF_DIV to ADC. */
    kFRO_HF_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 1U),         /*!< Attach FRO_HF to ADC.     */
    kCLK_IN_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 3U),         /*!< Attach CLK_IN to ADC.     */
    kCLK_1M_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 5U),         /*!< Attach CLK_1M to ADC.     */
    kNONE_to_ADC       = CLK_ATTACH_MUX(kCLOCK_SelADC, 7U),         /*!< Attach NONE to ADC.       */

    kFRO_LF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0, 0U),       /*!< Attach FRO_LF_DIV to CMP0. */
    kFRO_HF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0, 2U),       /*!< Attach FRO_HF_DIV to CMP0. */
    kCLK_IN_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0, 3U),       /*!< Attach CLK_IN to CMP0.     */
    kCLK_1M_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0, 5U),       /*!< Attach CLK_1M to CMP0.     */
    kNONE_to_CMP0       = CLK_ATTACH_MUX(kCLOCK_SelCMP0, 7U),       /*!< Attach NONE to CMP0.       */

    kCPU_CLK_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 0U),        /*!< Attach CPU_CLK to TRACE. */
    kCLK_1M_to_TRACE  = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 1U),        /*!< Attach CLK_1M to TRACE.  */
    kCLK_16K_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 2U),        /*!< Attach CLK_16K to TRACE. */
    kNONE_to_TRACE    = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 3U),        /*!< Attach NONE to TRACE.    */

    kFRO12M_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 0U),   /*!< Attach FRO_12M to CLKOUT.    */
    kFRO_HF_DIV_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 1U),   /*!< Attach FRO_HF_DIV to CLKOUT. */
    kCLK_IN_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 2U),   /*!< Attach CLK_IN to CLKOUT.     */
    kCLK_16K_to_CLKOUT    = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 3U),   /*!< Attach CLK_16K to CLKOUT.    */
    kSLOW_CLK_to_CLKOUT   = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 6U),   /*!< Attach SLOW_CLK to CLKOUT.   */
    kNONE_to_CLKOUT       = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 7U),   /*!< Attach NONE to CLKOUT.       */

    kCPU_CLK_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 0U),    /*!< Attach CPU_CLK to SYSTICK. */
    kCLK_1M_to_SYSTICK  = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 1U),    /*!< Attach CLK_1M to SYSTICK.  */
    kCLK_16K_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 2U),    /*!< Attach CLK_16K to SYSTICK. */
    kNONE_to_SYSTICK    = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 3U),    /*!< Attach NONE to SYSTICK.    */

    kCLK_16K_to_WWDT1    = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 0U),     /*!< Attach CLK_16K to WWDT1. */
    kFRO_HF_DIV_to_WWDT1 = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 1U),     /*!< Attach FRO_HF_DIV to WWDT1.  */
    kCLK_1M_to_WWDT1     = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 2U),     /*!< Attach CLK_1M to WWDT1. */
    kNONE_to_WWDT1       = CLK_ATTACH_MUX(kCLOCK_SelWWDT1, 3U),     /*!< Attach NONE to WWDT1.    */

    kNONE_to_NONE = (0xFFFFFFFFU),                                  /*!< Attach NONE to NONE. */

} clock_attach_id_t;

/*! @brief Clock dividers */
typedef enum _clock_div_name
{
    /* CLKDIV in SYSCON */
    kCLOCK_DivAHBCLK  = (0x80U), /*!< AHBCLK    clock divider */
    kCLOCK_DivSLOWCLK = (0x88U), /*!< SLOWCLK   clock divider */
    kCLOCK_DivFRO_HF  = (0x90U), /*!< FROHF     clock divider */
    kCLOCK_DivFRO_LF  = (0x94U), /*!< FROLF     clock divider */
    /* CLKDIV in MRCC */
    kCLOCK_DivCTIMER0   = (0x104U + 0x800U), /*!< CTIMER0   clock divider */
    kCLOCK_DivCTIMER1   = (0x10CU + 0x800U), /*!< CTIMER1   clock divider */
    kCLOCK_DivWWDT0     = (0x114U + 0x800U), /*!< WWDT0     clock divider */
    kCLOCK_DivWWDT1     = (0x11CU + 0x800U), /*!< WWDT1     clock divider */
    kCLOCK_DivLPI2C0    = (0x124U + 0x800U), /*!< LPI2C0    clock divider */
    kCLOCK_DivLPSPI0    = (0x12CU + 0x800U), /*!< LPSPI0    clock divider */
    kCLOCK_DivLPUART0   = (0x134U + 0x800U), /*!< LPUART0   clock divider */
    kCLOCK_DivLPUART1   = (0x13CU + 0x800U), /*!< LPUART1   clock divider */
    kCLOCK_DivLPUART2   = (0x144U + 0x800U), /*!< LPUART2   clock divider */
    kCLOCK_DivLPUART3   = (0x14CU + 0x800U), /*!< LPUART3   clock divider */
    kCLOCK_DivLPTMR0    = (0x154U + 0x800U), /*!< LPTMR0    clock divider */
    kCLOCK_DivADC       = (0x15CU + 0x800U), /*!< ADC       clock divider */
    kCLOCK_DivCMP0_FUNC = (0x164U + 0x800U), /*!< CMP0_FUNC clock divider */
    kCLOCK_DivCMP0_RR   = (0x16CU + 0x800U), /*!< CMP0_RR   clock divider */
    kCLOCK_DivTRACE     = (0x174U + 0x800U), /*!< TRACE     clock divider */
    kCLOCK_DivCLKOUT    = (0x17CU + 0x800U), /*!< CLKOUT    clock divider */
    kCLOCK_DivSYSTICK   = (0x184U + 0x800U), /*!< SYSTICK   clock divider */
    kCLOCK_DivMax       = (0x184U + 0x800U), /*!< MAX       clock divider */
} clock_div_name_t;

/*!
 * @brief CLK16K clock gate.
 */
typedef enum _clk16k_clk_gate_id
{
    kCLKE_16K_SYSTEM          = VBAT_FROCLKE_CLKE(1U), /*!< CLK16K[0] to SYSTEM domain.      */
    kCLKE_16K_COREMAIN        = VBAT_FROCLKE_CLKE(2U), /*!< CLK16K[1] to CORE domain.        */
    kCLOCK_Clk16kToSys        = VBAT_FROCLKE_CLKE(1U), /*!< CLK16K[0] to SYSTEM domain.      */
    kCLOCK_Clk16kToCore       = VBAT_FROCLKE_CLKE(2U), /*!< CLK16K[1] to CORE domain.        */
    kCLOCK_Clk16kToSysAndCore = VBAT_FROCLKE_CLKE(3U), /*!< CLK16K to SYSTEM and CORE domain.*/
} _clk16k_clk_gate_id;

/*!
 * @brief SCG status return codes.
 */
enum _scg_status
{
    kStatus_SCG_Busy       = MAKE_STATUS(kStatusGroup_SCG, 1), /*!< Clock is busy.  */
    kStatus_SCG_InvalidSrc = MAKE_STATUS(kStatusGroup_SCG, 2)  /*!< Invalid source. */
};

/*!
 * @brief sirc trim mode.
 */
typedef enum _sirc_trim_mode
{
    kSCG_SircTrimNonUpdate = SCG_SIRCCSR_SIRCTREN_MASK,
    /*!< Trim enable but not enable trim value update. In this mode, the
     trim value is fixed to the initialized value which is defined by
     trimCoar and trimFine in configure structure \ref sirc_trim_mode_t.*/

    kSCG_SircTrimUpdate = SCG_SIRCCSR_SIRCTREN_MASK | SCG_SIRCCSR_SIRCTRUP_MASK
    /*!< Trim enable and trim value update enable. In this mode, the trim
     value is auto update. */

} sirc_trim_mode_t;

/*!
 * @brief sirc trim source.
 */
typedef enum _sirc_trim_src
{
    kNoTrimSrc             = 0, /*!< No external tirm source.    */
    kSCG_SircTrimSrcSysOsc = 2U /*!< System OSC.                 */
} sirc_trim_src_t;

/*!
 * @brief sirc trim configuration.
 */
typedef struct _sirc_trim_config
{
    sirc_trim_mode_t trimMode; /*!< Trim mode.       */
    sirc_trim_src_t trimSrc;   /*!< Trim source.     */
    uint16_t trimDiv;          /*!< Divider of SOSC. */
    uint8_t cltrim;            /*!< Trim coarse value; Irrelevant if trimMode is kSCG_TrimUpdate. */
    uint8_t ccotrim;           /*!< Trim fine value; Irrelevant if trimMode is kSCG_TrimUpdate. */
} sirc_trim_config_t;

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
    kSD_Mode, /*!< SD Mode */
} run_mode_t;

/*! @brief OSC32K clock gate */
typedef enum _osc32k_clk_gate_id
{
    kCLOCK_Osc32kToSys        = 0x1, /*!< OSC32K[0] to SYSTEM domain.      */
    kCLOCK_Osc32kToCore       = 0x2, /*!< OSC32K[1] to CORE domain.        */
    kCLOCK_Osc32kToSysAndCore = 0x3, /*!< OSC32K to SYSTEM and CORE domain.*/
} osc32k_clk_gate_id_t;

/*!
 * @brief The enumerator of internal capacitance of OSC's XTAL pin.
 */
typedef enum _vbat_osc_xtal_cap
{
    kVBAT_OscXtal0pFCap  = 0x0U, /*!< The internal capacitance for XTAL pin is 0pF. */
    kVBAT_OscXtal2pFCap  = 0x1U, /*!< The internal capacitance for XTAL pin is 2pF. */
    kVBAT_OscXtal4pFCap  = 0x2U, /*!< The internal capacitance for XTAL pin is 4pF. */
    kVBAT_OscXtal6pFCap  = 0x3U, /*!< The internal capacitance for XTAL pin is 6pF. */
    kVBAT_OscXtal8pFCap  = 0x4U, /*!< The internal capacitance for XTAL pin is 8pF. */
    kVBAT_OscXtal10pFCap = 0x5U, /*!< The internal capacitance for XTAL pin is 10pF. */
    kVBAT_OscXtal12pFCap = 0x6U, /*!< The internal capacitance for XTAL pin is 12pF. */
    kVBAT_OscXtal14pFCap = 0x7U, /*!< The internal capacitance for XTAL pin is 14pF. */
    kVBAT_OscXtal16pFCap = 0x8U, /*!< The internal capacitance for XTAL pin is 16pF. */
    kVBAT_OscXtal18pFCap = 0x9U, /*!< The internal capacitance for XTAL pin is 18pF. */
    kVBAT_OscXtal20pFCap = 0xAU, /*!< The internal capacitance for XTAL pin is 20pF. */
    kVBAT_OscXtal22pFCap = 0xBU, /*!< The internal capacitance for XTAL pin is 22pF. */
    kVBAT_OscXtal24pFCap = 0xCU, /*!< The internal capacitance for XTAL pin is 24pF. */
    kVBAT_OscXtal26pFCap = 0xDU, /*!< The internal capacitance for XTAL pin is 26pF. */
    kVBAT_OscXtal28pFCap = 0xEU, /*!< The internal capacitance for XTAL pin is 28pF. */
    kVBAT_OscXtal30pFCap = 0xFU, /*!< The internal capacitance for XTAL pin is 30pF. */
} vbat_osc_xtal_cap_t;

/*!
 * @brief The enumerator of internal capacitance of OSC's EXTAL pin.
 */
typedef enum _vbat_osc_extal_cap
{
    kVBAT_OscExtal0pFCap  = 0x0U, /*!< The internal capacitance for EXTAL pin is 0pF. */
    kVBAT_OscExtal2pFCap  = 0x1U, /*!< The internal capacitance for EXTAL pin is 2pF. */
    kVBAT_OscExtal4pFCap  = 0x2U, /*!< The internal capacitance for EXTAL pin is 4pF. */
    kVBAT_OscExtal6pFCap  = 0x3U, /*!< The internal capacitance for EXTAL pin is 6pF. */
    kVBAT_OscExtal8pFCap  = 0x4U, /*!< The internal capacitance for EXTAL pin is 8pF. */
    kVBAT_OscExtal10pFCap = 0x5U, /*!< The internal capacitance for EXTAL pin is 10pF. */
    kVBAT_OscExtal12pFCap = 0x6U, /*!< The internal capacitance for EXTAL pin is 12pF. */
    kVBAT_OscExtal14pFCap = 0x7U, /*!< The internal capacitance for EXTAL pin is 14pF. */
    kVBAT_OscExtal16pFCap = 0x8U, /*!< The internal capacitance for EXTAL pin is 16pF. */
    kVBAT_OscExtal18pFCap = 0x9U, /*!< The internal capacitance for EXTAL pin is 18pF. */
    kVBAT_OscExtal20pFCap = 0xAU, /*!< The internal capacitance for EXTAL pin is 20pF. */
    kVBAT_OscExtal22pFCap = 0xBU, /*!< The internal capacitance for EXTAL pin is 22pF. */
    kVBAT_OscExtal24pFCap = 0xCU, /*!< The internal capacitance for EXTAL pin is 24pF. */
    kVBAT_OscExtal26pFCap = 0xDU, /*!< The internal capacitance for EXTAL pin is 26pF. */
    kVBAT_OscExtal28pFCap = 0xEU, /*!< The internal capacitance for EXTAL pin is 28pF. */
    kVBAT_OscExtal30pFCap = 0xFU, /*!< The internal capacitance for EXTAL pin is 30pF. */
} vbat_osc_extal_cap_t;

/*!
 * @brief The enumerator of osc amplifier gain fine adjustment.
 * Changes the oscillator amplitude by modifying the automatic gain control (AGC).
 */
typedef enum _vbat_osc_fine_adjustment_value
{
    kVBAT_OscCoarseAdjustment05 = 0U,
    kVBAT_OscCoarseAdjustment10 = 1U,
    kVBAT_OscCoarseAdjustment18 = 2U,
    kVBAT_OscCoarseAdjustment33 = 3U,
} vbat_osc_coarse_adjustment_value_t;

/*!
 * @brief The structure of oscillator configuration.
 */
typedef struct _vbat_osc_config
{
    bool enableInternalCapBank;         /*!< enable/disable the internal capacitance bank. */

    bool enableCrystalOscillatorBypass; /*!< enable/disable the crystal oscillator bypass. */

    vbat_osc_xtal_cap_t xtalCap;        /*!< The internal capacitance for the OSC XTAL pin from the capacitor bank,
                                                  only useful when the internal capacitance bank is enabled. */
    vbat_osc_extal_cap_t extalCap; /*!< The internal capacitance for the OSC EXTAL pin from the capacitor bank, only
                                      useful when the internal capacitance bank is enabled. */
    vbat_osc_coarse_adjustment_value_t
        coarseAdjustment;          /*!< 32kHz crystal oscillator amplifier coarse adjustment value. */
} vbat_osc_config_t;

/*!
 * @brief The enumerator of Initialization Trim.
 */
typedef enum _vbat_osc_init_trim
{
    kVBAT_OscInitTrim8000ms = 0x0U, /*!< Configures the start-up time of the oscillator to 8s. */
    kVBAT_OscInitTrim4000ms = 0x1U, /*!< Configures the start-up time of the oscillator to 4s. */
    kVBAT_OscInitTrim2000ms = 0x2U, /*!< Configures the start-up time of the oscillator to 2s. */
    kVBAT_OscInitTrim1000ms = 0x3U, /*!< Configures the start-up time of the oscillator to 1s. */
    kVBAT_OscInitTrim500ms  = 0x4U, /*!< Configures the start-up time of the oscillator to 0.5s. */
    kVBAT_OscInitTrim250ms  = 0x5U, /*!< Configures the start-up time of the oscillator to 0.25s. */
    kVBAT_OscInitTrim125ms  = 0x6U, /*!< Configures the start-up time of the oscillator to 0.125s. */
    kVBAT_OscInitTrimHalfms = 0x7U, /*!< Configures the start-up time of the oscillator to 0.5ms. */
} vbat_osc_init_trim_t;

/*!
 * @brief The enumerator of Capacitor Trim.
 */
typedef enum _vbat_osc_cap_trim
{
    kVBAT_OscCapTrimDefault    = 0x0U,
    kVBAT_OscCapTrim1us        = 0x1U,
    kVBAT_OscCapTrim2us        = 0x2U,
    kVBAT_OscCapTrim2andhalfus = 0x3U,
} vbat_osc_cap_trim_t;

/*!
 * @brief The enumerator of Delay Trim.
 */
typedef enum _vbat_osc_dly_trim
{
    kVBAT_OscDlyTrim0 = 0x0U, /*!< P current 9(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim1 = 0x1U, /*!< P current 13(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim3 = 0x3U, /*!< P current 4(nA) and N Current 6(nA). */
    kVBAT_OscDlyTrim4 = 0x4U, /*!< P current 9(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim5 = 0x5U, /*!< P current 13(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim6 = 0x6U, /*!< P current 4(nA) and N Current 4(nA). */
    kVBAT_OscDlyTrim7 = 0x7U, /*!< P current 9(nA) and N Current 2(nA). */
    kVBAT_OscDlyTrim8 = 0x8U, /*!< P current 13(nA) and N Current 2(nA). */
    kVBAT_OscDlyTrim9 = 0x9U, /*!< P current 4(nA) and N Current 2(nA). */
} vbat_osc_dly_trim_t;

/*!
 * @brief The enumerator of CAP2_TRIM.
 */
typedef enum _vbat_osc_cap2_trim
{
    kVBAT_OscCap2Trim0 = 0x0U,
    kVBAT_OscCap2Trim1 = 0x1U,
} vbat_osc_cap2_trim_t;

/*!
 * @brief The enumerator of Comparator Trim.
 */
typedef enum _vbat_osc_cmp_trim
{
    kVBAT_OscCmpTrim760mv = 0x0U,
    kVBAT_OscCmpTrim770mv = 0x1U,
    kVBAT_OscCmpTrim740mv = 0x3U,
} vbat_osc_cmp_trim_t;

/*!
 * @brief The enumerator of configures Crystal Oscillator mode..
 */
typedef enum _vbat_osc_mode_en
{
    kVBAT_OscNormalModeEnable   = 0x0U,
    kVBAT_OscStartupModeEnable  = 0x1U,
    kVBAT_OscLowpowerModeEnable = 0x3U,
} vbat_osc_mode_en_t;

/*!
 * @brief The structure of oscillator configuration.
 */
typedef struct _osc_32k_config
{
    vbat_osc_init_trim_t initTrim;
    vbat_osc_cap_trim_t capTrim;
    vbat_osc_dly_trim_t dlyTrim;
    vbat_osc_cap2_trim_t cap2Trim;
    vbat_osc_cmp_trim_t cmpTrim;

    vbat_osc_mode_en_t mode;
    vbat_osc_xtal_cap_t xtalCap;
    vbat_osc_extal_cap_t extalCap;
    vbat_osc_coarse_adjustment_value_t ampGain;

    osc32k_clk_gate_id_t id;
} osc_32k_config_t;

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
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    if (reg_offset == REG_PWM0SUBCTL)
    {
        SYSCON->PWM0SUBCTL |= (1UL << bit_shift);
        MRCC0->MRCC_GLB_CC0_SET = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
    }
    else
    {
        *pClkCtrl = *pClkCtrl | (1UL << bit_shift);
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
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
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    if (reg_offset == REG_PWM0SUBCTL)
    {
        SYSCON->PWM0SUBCTL &= ~(1UL << bit_shift);

        if (0U == (SYSCON->PWM0SUBCTL & 0x7U))
        {
            MRCC0->MRCC_GLB_CC0_CLR = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
        }
    }
    else
    {
        *pClkCtrl = *pClkCtrl & ~(1UL << bit_shift);
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_UNLOCK_MASK;
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
status_t CLOCK_SetClockSelect(clock_select_name_t sel_name, uint32_t value);

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
 * @brief   Initialize the FROHF to given frequency (48,64,96,192).
 * This function turns on FIRC and select the given frequency as the source of fro_hf
 * @param   iFreq   : Desired frequency.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq);

/**
 * @brief   Initialize the FRO12M.
 * This function turns on FRO12M.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFRO12MClocking(void);

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
 * @brief   Initialize the external reference clock to given frequency.
 * @param   iFreq   : Desired frequency (must be equal to exact rate in Hz)
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupExtRefClocking(uint32_t iFreq);

/**
 * @brief   Initialize the XTAL32/EXTAL32 input clock to given frequency.
 * @param   id   : OSC 32 kHz output clock to specified modules, it should use osc32k_clk_gate_id_t value
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClocking(uint32_t id);

/**
 * @brief   Get default XTAL32/EXTAL32 clock configuration structure.
 * This function initializes the osc 32k configuration structure to a default value. The default
 * values are:
 *   config->initTrim = kVBAT_OscInitTrim500ms;
 *   config->capTrim  = kVBAT_OscCapTrimDefault;
 *   config->dlyTrim  = kVBAT_OscDlyTrim5;
 *   config->cap2Trim = kVBAT_OscCap2Trim0;
 *   config->cmpTrim  = kVBAT_OscCmpTrim760mv;
 *   config->mode     = kVBAT_OscNormalModeEnable;
 *   config->xtalCap  = kVBAT_OscXtal24pFCap;
 *   config->extalCap = kVBAT_OscExtal22pFCap;
 *   config->ampGain  = kVBAT_OscCoarseAdjustment05;
 *   config->id       = kCLOCK_Osc32kToVbat;
 * @param   config: Pointer to a configuration structure
 */
void CLOCK_GetDefaultOsc32KConfig(osc_32k_config_t *config);

/**
 * @brief   Initialize the OSC 32K with user-defined settings.
 * @param   config   : OSC 32K configuration structure
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupOsc32KClockingConfig(osc_32k_config_t config);

/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

/*! @brief  Return Frequency of core
 *  @return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*! @brief  Return Frequency of CTimer functional Clock
 *  @return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id);

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

/*! @brief  Return Frequency of LPTMR functional Clock
 *  @return Frequency of LPTMR functional Clock
 */
uint32_t CLOCK_GetLptmrClkFreq(void);

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

/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config);

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
