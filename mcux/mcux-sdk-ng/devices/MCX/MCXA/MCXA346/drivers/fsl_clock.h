/*
 * Copyright 2023, NXP
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
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (180000000U)
#endif

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/
#define CLK_GATE_REG_OFFSET(value) (((uint32_t)(value)) >> 16U)
#define CLK_GATE_BIT_SHIFT(value)  (((uint32_t)(value)) & 0x0000FFFFU)

#define REG_PWM0SUBCTL (250U)
#define REG_PWM1SUBCTL (240U)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_InputMux      = ((0x00U << 16U) | (0U)),          /*!< Clock gate name: INPUTMUX0 */
    kCLOCK_GateINPUTMUX0 = ((0x00U << 16U) | (0U)),          /*!< Clock gate name: INPUTMUX0 */
    kCLOCK_GateI3C0      = ((0x00U << 16U) | (1U)),          /*!< Clock gate name: I3C0      */
    kCLOCK_GateCTIMER0   = ((0x00U << 16U) | (2U)),          /*!< Clock gate name: CTIMER0   */
    kCLOCK_GateCTIMER1   = ((0x00U << 16U) | (3U)),          /*!< Clock gate name: CTIMER1   */
    kCLOCK_GateCTIMER2   = ((0x00U << 16U) | (4U)),          /*!< Clock gate name: CTIMER2   */
    kCLOCK_GateCTIMER3   = ((0x00U << 16U) | (5U)),          /*!< Clock gate name: CTIMER3   */
    kCLOCK_GateCTIMER4   = ((0x00U << 16U) | (6U)),          /*!< Clock gate name: CTIMER4   */
    kCLOCK_GateFREQME    = ((0x00U << 16U) | (7U)),          /*!< Clock gate name: FREQME    */
    kCLOCK_GateUTICK0    = ((0x00U << 16U) | (8U)),          /*!< Clock gate name: UTICK0    */
    kCLOCK_GateWWDT0     = ((0x00U << 16U) | (9U)),          /*!< Clock gate name: WWDT0     */
    kCLOCK_Smartdma      = ((0x00U << 16U) | (10U)),         /*!< Clock gate name: SMARTDMA0 */
    kCLOCK_GateDMA0      = ((0x00U << 16U) | (11U)),         /*!< Clock gate name: DMA0      */
    kCLOCK_GateAOI0      = ((0x00U << 16U) | (12U)),         /*!< Clock gate name: AOI0      */
    kCLOCK_GateCRC0      = ((0x00U << 16U) | (13U)),         /*!< Clock gate name: CRC0      */
    kCLOCK_Crc0          = ((0x00U << 16U) | (13U)),         /*!< Clock gate name: CRC0      */
    kCLOCK_GateEIM0      = ((0x00U << 16U) | (14U)),         /*!< Clock gate name: EIM0      */
    kCLOCK_GateERM0      = ((0x00U << 16U) | (15U)),         /*!< Clock gate name: ERM0      */
    kCLOCK_GateFMC       = ((0x00U << 16U) | (16U)),         /*!< Clock gate name: FMC       */
    kCLOCK_GateAOI1      = ((0x00U << 16U) | (17U)),         /*!< Clock gate name: AOI1      */
    kCLOCK_GateFLEXIO0   = ((0x00U << 16U) | (18U)),         /*!< Clock gate name: FLEXIO0   */
    kCLOCK_GateLPI2C0    = ((0x00U << 16U) | (19U)),         /*!< Clock gate name: LPI2C0    */
    kCLOCK_GateLPI2C1    = ((0x00U << 16U) | (20U)),         /*!< Clock gate name: LPI2C1    */
    kCLOCK_GateLPSPI0    = ((0x00U << 16U) | (21U)),         /*!< Clock gate name: LPSPI0    */
    kCLOCK_GateLPSPI1    = ((0x00U << 16U) | (22U)),         /*!< Clock gate name: LPSPI1    */
    kCLOCK_GateLPUART0   = ((0x00U << 16U) | (23U)),         /*!< Clock gate name: LPUART0   */
    kCLOCK_GateLPUART1   = ((0x00U << 16U) | (24U)),         /*!< Clock gate name: LPUART1   */
    kCLOCK_GateLPUART2   = ((0x00U << 16U) | (25U)),         /*!< Clock gate name: LPUART2   */
    kCLOCK_GateLPUART3   = ((0x00U << 16U) | (26U)),         /*!< Clock gate name: LPUART3   */
    kCLOCK_GateLPUART4   = ((0x00U << 16U) | (27U)),         /*!< Clock gate name: LPUART4   */
    kCLOCK_GateUSB0      = ((0x00U << 16U) | (28U)),         /*!< Clock gate name: USB0      */
    kCLOCK_GateQDC0      = ((0x00U << 16U) | (29U)),         /*!< Clock gate name: QDC0      */
    kCLOCK_GateQDC1      = ((0x00U << 16U) | (30U)),         /*!< Clock gate name: QDC1      */
    kCLOCK_GateFLEXPWM0  = ((0x00U << 16U) | (31U)),         /*!< Clock gate name: FLEXPWM0  */
    kCLOCK_GateFLEXPWM1  = ((0x10U << 16U) | (0U)),          /*!< Clock gate name: FLEXPWM1  */
    kCLOCK_GateOSTIMER0  = ((0x10U << 16U) | (1U)),          /*!< Clock gate name: OSTIMER0  */
    kCLOCK_GateADC0      = ((0x10U << 16U) | (2U)),          /*!< Clock gate name: ADC0      */
    kCLOCK_GateADC1      = ((0x10U << 16U) | (3U)),          /*!< Clock gate name: ADC1      */
    kCLOCK_GateCMP0      = ((0x10U << 16U) | (4U)),          /*!< Clock gate name: CMP0      */
    kCLOCK_GateCMP1      = ((0x10U << 16U) | (5U)),          /*!< Clock gate name: CMP1      */
    kCLOCK_GateCMP2      = ((0x10U << 16U) | (6U)),          /*!< Clock gate name: CMP2      */
    kCLOCK_GateDAC0      = ((0x10U << 16U) | (7U)),          /*!< Clock gate name: DAC0      */
    kCLOCK_GateOPAMP0    = ((0x10U << 16U) | (8U)),          /*!< Clock gate name: OPAMP0    */
    kCLOCK_GateOPAMP1    = ((0x10U << 16U) | (9U)),          /*!< Clock gate name: OPAMP1    */
    kCLOCK_GateOPAMP2    = ((0x10U << 16U) | (10U)),         /*!< Clock gate name: OPAMP2    */
    kCLOCK_GateOPAMP3    = ((0x10U << 16U) | (11U)),         /*!< Clock gate name: OPAMP3    */
    kCLOCK_GatePORT0     = ((0x10U << 16U) | (12U)),         /*!< Clock gate name: PORT0     */
    kCLOCK_GatePORT1     = ((0x10U << 16U) | (13U)),         /*!< Clock gate name: PORT1     */
    kCLOCK_GatePORT2     = ((0x10U << 16U) | (14U)),         /*!< Clock gate name: PORT2     */
    kCLOCK_GatePORT3     = ((0x10U << 16U) | (15U)),         /*!< Clock gate name: PORT3     */
    kCLOCK_GatePORT4     = ((0x10U << 16U) | (16U)),         /*!< Clock gate name: PORT4     */
    kCLOCK_GateSLCD0     = ((0x10U << 16U) | (17U)),         /*!< Clock gate name: SLCD0     */
    kCLOCK_GateFLEXCAN0  = ((0x10U << 16U) | (18U)),         /*!< Clock gate name: FLEXCAN0  */
    kCLOCK_GateFLEXCAN1  = ((0x10U << 16U) | (19U)),         /*!< Clock gate name: FLEXCAN1  */
    kCLOCK_GateLPI2C2    = ((0x10U << 16U) | (20U)),         /*!< Clock gate name: LPI2C2    */
    kCLOCK_GateLPI2C3    = ((0x10U << 16U) | (21U)),         /*!< Clock gate name: LPI2C3    */
    kCLOCK_GateLPUART5   = ((0x10U << 16U) | (22U)),         /*!< Clock gate name: LPUART5   */
    kCLOCK_GateTDET0     = ((0x10U << 16U) | (23U)),         /*!< Clock gate name: TDET0     */
    kCLOCK_GatePKC0      = ((0x10U << 16U) | (24U)),         /*!< Clock gate name: PKC0      */
    kCLOCK_GateSGI0      = ((0x10U << 16U) | (25U)),         /*!< Clock gate name: SGI0      */
    kCLOCK_GateTRNG0     = ((0x10U << 16U) | (26U)),         /*!< Clock gate name: TRNG0     */
    kCLOCK_GateUDF0      = ((0x10U << 16U) | (27U)),         /*!< Clock gate name: UDF0      */
    kCLOCK_GateADC2      = ((0x10U << 16U) | (28U)),         /*!< Clock gate name: ADC2      */
    kCLOCK_GateADC3      = ((0x10U << 16U) | (29U)),         /*!< Clock gate name: ADC3      */
    kCLOCK_GateRAMA      = ((0x20U << 16U) | (1U)),          /*!< Clock gate name: RAMA      */
    kCLOCK_GateRAMB      = ((0x20U << 16U) | (2U)),          /*!< Clock gate name: RAMB      */
    kCLOCK_GateRAMC      = ((0x20U << 16U) | (3U)),          /*!< Clock gate name: RAMC      */
    kCLOCK_GateGPIO0     = ((0x20U << 16U) | (4U)),          /*!< Clock gate name: GPIO0     */
    kCLOCK_GateGPIO1     = ((0x20U << 16U) | (5U)),          /*!< Clock gate name: GPIO1     */
    kCLOCK_GateGPIO2     = ((0x20U << 16U) | (6U)),          /*!< Clock gate name: GPIO2     */
    kCLOCK_GateGPIO3     = ((0x20U << 16U) | (7U)),          /*!< Clock gate name: GPIO3     */
    kCLOCK_GateGPIO4     = ((0x20U << 16U) | (8U)),          /*!< Clock gate name: GPIO4     */
    kCLOCK_GateMAU0      = ((0x20U << 16U) | (9U)),          /*!< Clock gate name: MAU0      */
    kCLOCK_GateROMC      = ((0x20U << 16U) | (10U)),         /*!< Clock gate name: ROMC      */
    kCLOCK_GatePWM0SM0   = ((REG_PWM0SUBCTL << 16U) | (0U)), /*!< Clock gate name: PWM0 SM0  */
    kCLOCK_GatePWM0SM1   = ((REG_PWM0SUBCTL << 16U) | (1U)), /*!< Clock gate name: PWM0 SM1  */
    kCLOCK_GatePWM0SM2   = ((REG_PWM0SUBCTL << 16U) | (2U)), /*!< Clock gate name: PWM0 SM2  */
    kCLOCK_GatePWM0SM3   = ((REG_PWM0SUBCTL << 16U) | (3U)), /*!< Clock gate name: PWM0 SM3  */
    kCLOCK_GatePWM1SM0   = ((REG_PWM1SUBCTL << 16U) | (0U)), /*!< Clock gate name: PWM1 SM0  */
    kCLOCK_GatePWM1SM1   = ((REG_PWM1SUBCTL << 16U) | (1U)), /*!< Clock gate name: PWM1 SM1  */
    kCLOCK_GatePWM1SM2   = ((REG_PWM1SUBCTL << 16U) | (2U)), /*!< Clock gate name: PWM1 SM2  */
    kCLOCK_GatePWM1SM3   = ((REG_PWM1SUBCTL << 16U) | (3U)), /*!< Clock gate name: PWM1 SM3  */
    kCLOCK_GateNotAvail  = (0xFFFFFFFFU),                    /*!< Clock gate name: None      */
} clock_ip_name_t;

/*! @brief Clock ip name array for AOI. */
#define AOI_CLOCKS                       \
    {                                    \
        kCLOCK_GateAOI0, kCLOCK_GateAOI1 \
    }
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS      \
    {                   \
        kCLOCK_GateCRC0 \
    }
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS                                                                                      \
    {                                                                                                      \
        kCLOCK_GateCTIMER0, kCLOCK_GateCTIMER1, kCLOCK_GateCTIMER2, kCLOCK_GateCTIMER3, kCLOCK_GateCTIMER4 \
    }
/*! @brief Clock ip name array for DAC. */
#define LPDAC_CLOCKS    \
    {                   \
        kCLOCK_GateDAC0 \
    }
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS      \
    {                   \
        kCLOCK_GateDMA0 \
    }
/*! @brief Clock gate name array for EDMA. */
#define EDMA_CLOCKS     \
    {                   \
        kCLOCK_GateDMA0 \
    }
/*! @brief Clock ip name array for ERM. */
#define ERM_CLOCKS      \
    {                   \
        kCLOCK_GateERM0 \
    }
/*! @brief Clock ip name array for EIM. */
#define EIM_CLOCKS      \
    {                   \
        kCLOCK_GateEIM0 \
    }
/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                           \
    {                                            \
        kCLOCK_GateFLEXCAN0, kCLOCK_GateFLEXCAN1 \
    }
/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS      \
    {                      \
        kCLOCK_GateFLEXIO0 \
    }
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS     \
    {                     \
        kCLOCK_GateFREQME \
    }
/*! @brief Clock ip name array for GPIO. */
#define GPIO_CLOCKS                                                                              \
    {                                                                                            \
        kCLOCK_GateGPIO0, kCLOCK_GateGPIO1, kCLOCK_GateGPIO2, kCLOCK_GateGPIO3, kCLOCK_GateGPIO4 \
    }
/*! @brief Clock ip name array for I3C */
#define I3C_CLOCKS      \
    {                   \
        kCLOCK_GateI3C0 \
    }
/*! @brief Clock ip name array for INPUTMUX. */
#define INPUTMUX_CLOCKS      \
    {                        \
        kCLOCK_GateINPUTMUX0 \
    }
/*! @brief Clock ip name array for GPIO. */
#define LPCMP_CLOCKS                                      \
    {                                                     \
        kCLOCK_GateCMP0, kCLOCK_GateCMP1, kCLOCK_GateCMP2 \
    }
/*! @brief Clock ip name array for LPADC. */
#define LPADC_CLOCKS                                                       \
    {                                                                      \
        kCLOCK_GateADC0, kCLOCK_GateADC1, kCLOCK_GateADC2, kCLOCK_GateADC3 \
    }
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                       \
    {                                                                                                       \
        kCLOCK_GateLPUART0, kCLOCK_GateLPUART1, kCLOCK_GateLPUART2, kCLOCK_GateLPUART3, kCLOCK_GateLPUART4, \
            kCLOCK_GateLPUART5                                                                              \
    }
/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                                                               \
    {                                                                              \
        kCLOCK_GateLPI2C0, kCLOCK_GateLPI2C1, kCLOCK_GateLPI2C2, kCLOCK_GateLPI2C3 \
    }
/*! @brief Clock ip name array for LSPI. */
#define LPSPI_CLOCKS                         \
    {                                        \
        kCLOCK_GateLPSPI0, kCLOCK_GateLPSPI1 \
    }
/*! @brief Clock ip name array for MAU. */
#define MAU_CLOCKS      \
    {                   \
        kCLOCK_GateMAU0 \
    }
/*! @brief Clock ip name array for OSTIMER. */
#define OSTIMER_CLOCKS      \
    {                       \
        kCLOCK_GateOSTIMER0 \
    }
/*! @brief Clock ip name array for DAC. */
#define OPAMP_CLOCKS                                                               \
    {                                                                              \
        kCLOCK_GateOPAMP0, kCLOCK_GateOPAMP1, kCLOCK_GateOPAMP2, kCLOCK_GateOPAMP3 \
    }
/*! @brief Clock ip name array for PWM. */
#define PWM_CLOCKS                                                                         \
    {                                                                                      \
        {kCLOCK_GatePWM0SM0, kCLOCK_GatePWM0SM1, kCLOCK_GatePWM0SM2, kCLOCK_GatePWM0SM3},  \
        {                                                                                  \
            kCLOCK_GatePWM1SM0, kCLOCK_GatePWM1SM1, kCLOCK_GatePWM1SM2, kCLOCK_GatePWM1SM3 \
        }                                                                                  \
    }
/*! @brief Clock ip name array for PKC. */
#define PKC_CLOCKS        \
    {                     \
        kCLOCK_GatePKC0 \ \
    }
/*! @brief Clock ip name array for PORT. */
#define PORT_CLOCKS                                                                                \
    {                                                                                              \
        kCLOCK_GatePORT0, kCLOCK_GatePORT1, kCLOCK_GatePORT2, kCLOCK_GatePORT3, kCLOCK_GatePORT4 \ \
    }
/*! @brief Clock ip name array for QDC. */
#define QDC_CLOCKS                       \
    {                                    \
        kCLOCK_GateQDC0, kCLOCK_GateQDC1 \
    }
/*! @brief Clock ip name array for SGI. */
#define SGI_CLOCKS      \
    {                   \
        kCLOCK_GateSGI0 \
    }
/*! @brief Clock ip name array for SLCD. */
#define SLCD_CLOCKS      \
    {                    \
        kCLOCK_GateSLCD0 \
    }
/*! @brief Clock ip name array for SMARTDMA. */
#define SMARTDMA_CLOCKS      \
    {                        \
        kCLOCK_Smartdma \
    }
/*! @brief Clock ip name array for TDET. */
#define TDET_CLOCKS      \
    {                    \
        kCLOCK_GateTDET0 \
    }
/*! @brief Clock ip name array for TDET. */
#define TRNG_CLOCKS      \
    {                    \
        kCLOCK_GateTRNG0 \
    }
/*! @brief Clock ip name array for UTICK. */
#define UTICK_CLOCKS      \
    {                     \
        kCLOCK_GateUTICK0 \
    }
/*! @brief Clock ip name array for WWDT. */
#define WWDT_CLOCKS      \
    {                    \
        kCLOCK_GateWWDT0 \
    }

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
    kCLOCK_MainClk,    /*!< MAIN_CLK                   */
    kCLOCK_CoreSysClk, /*!< Core/system clock(CPU_CLK) */
    kCLOCK_SYSTEM_CLK, /*!< SYSTEM clock/AHB_BUS       */
    kCLOCK_BusClk,     /*!< SYSTEM clock divided by 2  */
    kCLOCK_ExtClk,     /*!< External Clock             */
    kCLOCK_FroHf,      /*!< FRO192                     */
    kCLOCK_FroHfDiv,   /*!< Divided by FRO192          */
    kCLOCK_Clk45M,     /*!< CLK45M                     */
    kCLOCK_Pll1Clk,    /*!< Pll1Clk                    */
    kCLOCK_Pll1ClkDiv, /*!< Pll1CkDiv                  */
    kCLOCK_Fro12M,     /*!< FRO12M                     */
    kCLOCK_Fro12MDiv,  /*!< FRO12MDiv                  */
    kCLOCK_Clk1M,      /*!< CLK1M                      */
    kCLOCK_Fro16K,     /*!< FRO16K                     */
    kCLOCK_Clk16K0,    /*!< CLK16K[0]                  */
    kCLOCK_Clk16K1,    /*!< CLK16K[1]                  */
    kCLOCK_SLOW_CLK,   /*!< SYSTEM_CLK divided by 6    */
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
    kCLOCK_SelI3C0_FCLK = (0x0A0U), /*!< I3C0_FCLK clock selection */
    kCLOCK_SelCTIMER0   = (0x0A8U), /*!< CTIMER0   clock selection */
    kCLOCK_SelCTIMER1   = (0x0B0U), /*!< CTIMER1   clock selection */
    kCLOCK_SelCTIMER2   = (0x0B8U), /*!< CTIMER2   clock selection */
    kCLOCK_SelCTIMER3   = (0x0C0U), /*!< CTIMER3   clock selection */
    kCLOCK_SelCTIMER4   = (0x0C8U), /*!< CTIMER4   clock selection */
    kCLOCK_SelFLEXIO0   = (0x0D8U), /*!< FLEXIO0   clock selection */
    kCLOCK_SelLPI2C0    = (0x0E0U), /*!< LPI2C0    clock selection */
    kCLOCK_SelLPI2C1    = (0x0E8U), /*!< LPI2C1    clock selection */
    kCLOCK_SelLPSPI0    = (0x0F0U), /*!< LPSPI0    clock selection */
    kCLOCK_SelLPSPI1    = (0x0F8U), /*!< LPSPI1    clock selection */
    kCLOCK_SelLPUART0   = (0x100U), /*!< LPUART0   clock selection */
    kCLOCK_SelLPUART1   = (0x108U), /*!< LPUART1   clock selection */
    kCLOCK_SelLPUART2   = (0x110U), /*!< LPUART2   clock selection */
    kCLOCK_SelLPUART3   = (0x118U), /*!< LPUART3   clock selection */
    kCLOCK_SelLPUART4   = (0x120U), /*!< LPUART4   clock selection */
    kCLOCK_SelUSB0      = (0x128U), /*!< USB0      clock selection */
    kCLOCK_SelLPTMR0    = (0x130U), /*!< LPTMR0    clock selection */
    kCLOCK_SelOSTIMER0  = (0x138U), /*!< OSTIMER0  clock selection */
    kCLOCK_SelADC       = (0x140U), /*!< ADC0      clock selection */
    kCLOCK_SelCMP0_RR   = (0x150U), /*!< CMP0_RR   clock selection */
    kCLOCK_SelCMP1_RR   = (0x160U), /*!< CMP1_RR   clock selection */
    kCLOCK_SelCMP2_RR   = (0x170U), /*!< CMP2_RR   clock selection */
    kCLOCK_SelDAC0      = (0x178U), /*!< DAC0      clock selection */
    kCLOCK_SelFLEXCAN0  = (0x180U), /*!< FLEXCAN0  clock selection */
    kCLOCK_SelFLEXCAN1  = (0x188U), /*!< FLEXCAN1  clock selection */
    kCLOCK_SelLPI2C2    = (0x190U), /*!< LPI2C2    clock selection */
    kCLOCK_SelLPI2C3    = (0x198U), /*!< LPI2C3    clock selection */
    kCLOCK_SelLPUART5   = (0x1A0U), /*!< LPUART5   clock selection */
    kCLOCK_SelTRACE     = (0x1A8U), /*!< TRACE     clock selection */
    kCLOCK_SelCLKOUT    = (0x1B0U), /*!< CLKOUT    clock selection */
    kCLOCK_SelSYSTICK   = (0x1B8U), /*!< SYSTICK   clock selection */
    kCLOCK_SelSCGSCS    = (0x200U), /*!< SCG SCS   clock selection */
    kCLOCK_SelMax       = (0x200U), /*!< MAX       clock selection */
} clock_select_name_t;

/*!
 * @brief The enumerator of clock attach Id.
 */
typedef enum _clock_attach_id
{
    kCLK_IN_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 1U),       /*!< Attach clk_in to MAIN_CLK.     */
    kFRO12M_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 2U),       /*!< Attach FRO_12M to MAIN_CLK.    */
    kFRO_HF_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 3U),       /*!< Attach FRO_HF to MAIN_CLK.     */
    kCLK_16K_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 4U),       /*!< Attach CLK_16K[1] to MAIN_CLK. */
    kPll1Clk_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 6U),       /*!< Attach Pll1Clk to MAIN_CLK.    */
    kNONE_to_MAIN_CLK    = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 7U),       /*!< Attach NONE to MAIN_CLK.       */

    kFRO_LF_DIV_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 0U), /*!< Attach FRO_LF_DIV to I3C0FCLK. */
    kFRO_HF_DIV_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 2U), /*!< Attach FRO_HF_DIV to I3C0FCLK. */
    kCLK_IN_to_I3C0FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 3U), /*!< Attach CLK_IN to I3C0FCLK.     */
    kCLK_1M_to_I3C0FCLK     = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 5U), /*!< Attach CLK_1M to I3C0FCLK.     */
    kPll1ClkDiv_to_I3C0FCLK = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 6U), /*!< Attach Pll1ClkDiv to I3C0FCLK. */
    kNONE_to_I3C0FCLK       = CLK_ATTACH_MUX(kCLOCK_SelI3C0_FCLK, 7U), /*!< Attach NONE to I3C0FCLK.       */

    kFRO_LF_DIV_to_CTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 0U),    /*!< Attach FRO_LF_DIV to CTIMER0. */
    kFRO_HF_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 1U),    /*!< Attach FRO_HF to CTIMER0.     */
    kCLK_IN_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 3U),    /*!< Attach CLK_IN to CTIMER0.     */
    kCLK_16K_to_CTIMER0    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 4U),    /*!< Attach CLK_16K to CTIMER0.    */
    kCLK_1M_to_CTIMER0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 5U),    /*!< Attach CLK_1M to CTIMER0.     */
    kPll1ClkDiv_to_CTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 6U),    /*!< Attach Pll1ClkDiv to CTIMER0. */
    kNONE_to_CTIMER0       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER0, 7U),    /*!< Attach NONE to CTIMER0.       */

    kFRO_LF_DIV_to_CTIMER1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 0U),    /*!< Attach FRO_LF_DIV to CTIMER1. */
    kFRO_HF_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 1U),    /*!< Attach FRO_HF to CTIMER1.     */
    kCLK_IN_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 3U),    /*!< Attach CLK_IN to CTIMER1.     */
    kCLK_16K_to_CTIMER1    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 4U),    /*!< Attach CLK_16K to CTIMER1.    */
    kCLK_1M_to_CTIMER1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 5U),    /*!< Attach CLK_1M to CTIMER1.     */
    kPll1ClkDiv_to_CTIMER1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 6U),    /*!< Attach Pll1ClkDiv to CTIMER1. */
    kNONE_to_CTIMER1       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER1, 7U),    /*!< Attach NONE to CTIMER1.       */

    kFRO_LF_DIV_to_CTIMER2 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 0U),    /*!< Attach FRO_LF_DIV to CTIMER2. */
    kFRO_HF_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 1U),    /*!< Attach FRO_HF to CTIMER2.     */
    kCLK_IN_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 3U),    /*!< Attach CLK_IN to CTIMER2.     */
    kCLK_16K_to_CTIMER2    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 4U),    /*!< Attach CLK_16K to CTIMER2.    */
    kCLK_1M_to_CTIMER2     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 5U),    /*!< Attach CLK_1M to CTIMER2.     */
    kPll1ClkDiv_to_CTIMER2 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 6U),    /*!< Attach Pll1ClkDiv to CTIMER2. */
    kNONE_to_CTIMER2       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER2, 7U),    /*!< Attach NONE to CTIMER2.       */

    kFRO_LF_DIV_to_CTIMER3 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 0U),    /*!< Attach FRO_LF_DIV to CTIMER3. */
    kFRO_HF_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 1U),    /*!< Attach FRO_HF to CTIMER3.     */
    kCLK_IN_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 3U),    /*!< Attach CLK_IN to CTIMER3.     */
    kCLK_16K_to_CTIMER3    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 4U),    /*!< Attach CLK_16K to CTIMER3.    */
    kCLK_1M_to_CTIMER3     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 5U),    /*!< Attach CLK_1M to CTIMER3.     */
    kPll1ClkDiv_to_CTIMER3 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 6U),    /*!< Attach Pll1ClkDiv to CTIMER3. */
    kNONE_to_CTIMER3       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER3, 7U),    /*!< Attach NONE to CTIMER3.       */

    kFRO_LF_DIV_to_CTIMER4 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 0U),    /*!< Attach FRO_LF_DIV to CTIMER4. */
    kFRO_HF_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 1U),    /*!< Attach FRO_HF to CTIMER4.     */
    kCLK_IN_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 3U),    /*!< Attach CLK_IN to CTIMER4.     */
    kCLK_16K_to_CTIMER4    = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 4U),    /*!< Attach CLK_16K to CTIMER4.    */
    kCLK_1M_to_CTIMER4     = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 5U),    /*!< Attach CLK_1M to CTIMER4.     */
    kPll1ClkDiv_to_CTIMER4 = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 6U),    /*!< Attach Pll1ClkDiv to CTIMER4. */
    kNONE_to_CTIMER4       = CLK_ATTACH_MUX(kCLOCK_SelCTIMER4, 7U),    /*!< Attach NONE to CTIMER4.       */

    kFRO_LF_DIV_to_FLEXIO0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 0U),    /*!< Attach FRO_LF_DIV to FLEXIO0. */
    kFRO_HF_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 1U),    /*!< Attach FRO_HF to FLEXIO0.     */
    kCLK_IN_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 3U),    /*!< Attach CLK_IN to FLEXIO0.     */
    kCLK_1M_to_FLEXIO0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 5U),    /*!< Attach CLK_1M to FLEXIO0.     */
    kPll1ClkDiv_to_FLEXIO0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 6U),    /*!< Attach Pll1ClkDiv to FLEXIO0. */
    kNONE_to_FLEXIO0       = CLK_ATTACH_MUX(kCLOCK_SelFLEXIO0, 7U),    /*!< Attach NONE to FLEXIO0.       */

    kFRO_HF_to_FLEXCAN0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 1U),  /*!< Attach FRO_HF to FLEXCAN0.     */
    kFRO_HF_DIV_to_FLEXCAN0 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 2U),  /*!< Attach FRO_HF_DIV to FLEXCAN0. */
    kCLK_IN_to_FLEXCAN0     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 3U),  /*!< Attach CLK_IN to FLEXCAN0.     */
    kPll1Clk_to_FLEXCAN0    = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 6U),  /*!< Attach Pll1Clk to FLEXCAN0.    */
    kNONE_to_FLEXCAN0       = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN0, 7U),  /*!< Attach NONE to FLEXCAN0.       */

    kFRO_HF_to_FLEXCAN1     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 1U),  /*!< Attach FRO_HF to FLEXCAN1.     */
    kFRO_HF_DIV_to_FLEXCAN1 = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 2U),  /*!< Attach FRO_HF_DIV to FLEXCAN1. */
    kCLK_IN_to_FLEXCAN1     = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 3U),  /*!< Attach CLK_IN to FLEXCAN1.     */
    kPll1Clk_to_FLEXCAN1    = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 6U),  /*!< Attach Pll1Clk to FLEXCAN1.    */
    kNONE_to_FLEXCAN1       = CLK_ATTACH_MUX(kCLOCK_SelFLEXCAN1, 7U),  /*!< Attach NONE to FLEXCAN1.       */

    kFRO_LF_DIV_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 0U),          /*!< Attach FRO_LF_DIV to DAC0.  */
    kFRO_HF_DIV_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 2U),          /*!< Attach FRO_HF_DIV to DAC0.  */
    kCLK_IN_to_DAC0     = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 3U),          /*!< Attach CLK_IN to DAC0.      */
    kCLK_1M_to_DAC0     = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 5U),          /*!< Attach CLK_1M to DAC0.      */
    kPll1ClkDiv_to_DAC0 = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 6U),          /*!< Attach Pll1ClkDiv to DAC0.  */
    kNONE_to_DAC0       = CLK_ATTACH_MUX(kCLOCK_SelDAC0, 7U),          /*!< Attach NONE to DAC0.        */

    kFRO_LF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 0U),      /*!< Attach FRO_LF_DIV to LPI2C0. */
    kFRO_HF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 2U),      /*!< Attach FRO_HF_DIV to LPI2C0. */
    kCLK_IN_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 3U),      /*!< Attach CLK_IN to LPI2C0.     */
    kCLK_1M_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 5U),      /*!< Attach CLK_1M to LPI2C0.     */
    kPll1ClkDiv_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 6U),      /*!< Attach Pll1ClkDiv to LPI2C0. */
    kNONE_to_LPI2C0       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C0, 7U),      /*!< Attach NONE to LPI2C0.       */

    kFRO_LF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 0U),      /*!< Attach FRO_LF_DIV to LPI2C1. */
    kFRO_HF_DIV_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 2U),      /*!< Attach FRO_HF_DIV to LPI2C1. */
    kCLK_IN_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 3U),      /*!< Attach CLK_IN to LPI2C1.     */
    kCLK_1M_to_LPI2C1     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 5U),      /*!< Attach CLK_1M to LPI2C1.     */
    kPll1ClkDiv_to_LPI2C1 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 6U),      /*!< Attach Pll1ClkDiv to LPI2C1. */
    kNONE_to_LPI2C1       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C1, 7U),      /*!< Attach NONE to LPI2C1.       */

    kFRO_LF_DIV_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 0U),      /*!< Attach FRO_LF_DIV to LPI2C2. */
    kFRO_HF_DIV_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 2U),      /*!< Attach FRO_HF_DIV to LPI2C2. */
    kCLK_IN_to_LPI2C2     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 3U),      /*!< Attach CLK_IN to LPI2C2.     */
    kCLK_1M_to_LPI2C2     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 5U),      /*!< Attach CLK_1M to LPI2C2.     */
    kPll1ClkDiv_to_LPI2C2 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 6U),      /*!< Attach Pll1ClkDiv to LPI2C2. */
    kNONE_to_LPI2C2       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C2, 7U),      /*!< Attach NONE to LPI2C2.       */

    kFRO_LF_DIV_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 0U),      /*!< Attach FRO_LF_DIV to LPI2C3. */
    kFRO_HF_DIV_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 2U),      /*!< Attach FRO_HF_DIV to LPI2C3. */
    kCLK_IN_to_LPI2C3     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 3U),      /*!< Attach CLK_IN to LPI2C3.     */
    kCLK_1M_to_LPI2C3     = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 5U),      /*!< Attach CLK_1M to LPI2C3.     */
    kPll1ClkDiv_to_LPI2C3 = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 6U),      /*!< Attach Pll1ClkDiv to LPI2C3. */
    kNONE_to_LPI2C3       = CLK_ATTACH_MUX(kCLOCK_SelLPI2C3, 7U),      /*!< Attach NONE to LPI2C3.       */

    kFRO_LF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 0U),      /*!< Attach FRO_LF_DIV to LPSPI0. */
    kFRO_HF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 2U),      /*!< Attach FRO_HF_DIV to LPSPI0. */
    kCLK_IN_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 3U),      /*!< Attach CLK_IN to LPSPI0.     */
    kCLK_1M_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 5U),      /*!< Attach CLK_1M to LPSPI0.     */
    kPll1ClkDiv_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 6U),      /*!< Attach Pll1ClkDiv to LPSPI0. */
    kNONE_to_LPSPI0       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI0, 7U),      /*!< Attach NONE to LPSPI0.       */

    kFRO_LF_DIV_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 0U),      /*!< Attach FRO_LF_DIV to LPSPI1. */
    kFRO_HF_DIV_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 2U),      /*!< Attach FRO_HF_DIV to LPSPI1. */
    kCLK_IN_to_LPSPI1     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 3U),      /*!< Attach CLK_IN to LPSPI1.     */
    kCLK_1M_to_LPSPI1     = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 5U),      /*!< Attach CLK_1M to LPSPI1.     */
    kPll1ClkDiv_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 6U),      /*!< Attach Pll1ClkDiv to LPSPI1. */
    kNONE_to_LPSPI1       = CLK_ATTACH_MUX(kCLOCK_SelLPSPI1, 7U),      /*!< Attach NONE to LPSPI1.       */

    kFRO_LF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 0U),    /*!< Attach FRO_LF_DIV to LPUART0. */
    kFRO_HF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 2U),    /*!< Attach FRO_HF_DIV to LPUART0. */
    kCLK_IN_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 3U),    /*!< Attach CLK_IN to LPUART0.     */
    kCLK_16K_to_LPUART0    = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 4U),    /*!< Attach CLK_16K to LPUART0.    */
    kCLK_1M_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 5U),    /*!< Attach CLK_1M to LPUART0.     */
    kPll1ClkDiv_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 6U),    /*!< Attach Pll1ClkDiv to LPUART0. */
    kNONE_to_LPUART0       = CLK_ATTACH_MUX(kCLOCK_SelLPUART0, 7U),    /*!< Attach NONE to LPUART0.       */

    kFRO_LF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 0U),    /*!< Attach FRO_LF_DIV to LPUART1. */
    kFRO_HF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 2U),    /*!< Attach FRO_HF_DIV to LPUART1. */
    kCLK_IN_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 3U),    /*!< Attach CLK_IN to LPUART1.     */
    kCLK_16K_to_LPUART1    = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 4U),    /*!< Attach CLK_16K to LPUART1.    */
    kCLK_1M_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 5U),    /*!< Attach CLK_1M to LPUART1.     */
    kPll1ClkDiv_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 6U),    /*!< Attach Pll1ClkDiv to LPUART1. */
    kNONE_to_LPUART1       = CLK_ATTACH_MUX(kCLOCK_SelLPUART1, 7U),    /*!< Attach NONE to LPUART1.       */

    kFRO_LF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 0U),    /*!< Attach FRO_LF_DIV to LPUART2. */
    kFRO_HF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 2U),    /*!< Attach FRO_HF_DIV to LPUART2. */
    kCLK_IN_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 3U),    /*!< Attach CLK_IN to LPUART2.     */
    kCLK_16K_to_LPUART2    = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 4U),    /*!< Attach CLK_16K to LPUART2.    */
    kCLK_1M_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 5U),    /*!< Attach CLK_1M to LPUART2.     */
    kPll1ClkDiv_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 6U),    /*!< Attach Pll1ClkDiv to LPUART2. */
    kNONE_to_LPUART2       = CLK_ATTACH_MUX(kCLOCK_SelLPUART2, 7U),    /*!< Attach NONE to LPUART2.       */

    kFRO_LF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 0U),    /*!< Attach FRO_LF_DIV to LPUART2. */
    kFRO_HF_DIV_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 2U),    /*!< Attach FRO_HF_DIV to LPUART2. */
    kCLK_IN_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 3U),    /*!< Attach CLK_IN to LPUART2.     */
    kCLK_16K_to_LPUART3    = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 4U),    /*!< Attach CLK_16K to LPUART2.    */
    kCLK_1M_to_LPUART3     = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 5U),    /*!< Attach CLK_1M to LPUART2.     */
    kPll1ClkDiv_to_LPUART3 = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 6U),    /*!< Attach Pll1ClkDiv to LPUART3. */
    kNONE_to_LPUART3       = CLK_ATTACH_MUX(kCLOCK_SelLPUART3, 7U),    /*!< Attach NONE to LPUART2.       */

    kFRO_LF_DIV_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 0U),    /*!< Attach FRO_LF_DIV to LPUART4. */
    kFRO_HF_DIV_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 2U),    /*!< Attach FRO_HF_DIV to LPUART4. */
    kCLK_IN_to_LPUART4     = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 3U),    /*!< Attach CLK_IN to LPUART4.     */
    kCLK_16K_to_LPUART4    = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 4U),    /*!< Attach CLK_16K to LPUART4.    */
    kCLK_1M_to_LPUART4     = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 5U),    /*!< Attach CLK_1M to LPUART4.     */
    kPll1ClkDiv_to_LPUART4 = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 6U),    /*!< Attach Pll1ClkDiv to LPUART4. */
    kNONE_to_LPUART4       = CLK_ATTACH_MUX(kCLOCK_SelLPUART4, 7U),    /*!< Attach NONE to LPUART4.       */

    kFRO_LF_DIV_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 0U),    /*!< Attach FRO_LF_DIV to LPUART5. */
    kFRO_HF_DIV_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 2U),    /*!< Attach FRO_HF_DIV to LPUART5. */
    kCLK_IN_to_LPUART5     = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 3U),    /*!< Attach CLK_IN to LPUART5.     */
    kCLK_16K_to_LPUART5    = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 4U),    /*!< Attach CLK_16K to LPUART5.    */
    kCLK_1M_to_LPUART5     = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 5U),    /*!< Attach CLK_1M to LPUART5.     */
    kPll1ClkDiv_to_LPUART5 = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 6U),    /*!< Attach Pll1ClkDiv to LPUART5. */
    kNONE_to_LPUART5       = CLK_ATTACH_MUX(kCLOCK_SelLPUART5, 7U),    /*!< Attach NONE to LPUART5.       */

    kPll1Clk_to_USB0 = CLK_ATTACH_MUX(kCLOCK_SelUSB0, 0U),             /*!< Attach Pll1Clk to USB0. */
    kCLK_45M_to_USB0 = CLK_ATTACH_MUX(kCLOCK_SelUSB0, 1U),             /*!< Attach FRO_HF to USB0.  */
    kCLK_IN_to_USB0  = CLK_ATTACH_MUX(kCLOCK_SelUSB0, 2U),             /*!< Attach CLK_IN to USB0.  */
    kNONE_to_USB0    = CLK_ATTACH_MUX(kCLOCK_SelUSB0, 3U),             /*!< Attach NONE to USB0.    */

    kFRO_LF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 0U),      /*!< Attach FRO_LF_DIV to LPTMR0. */
    kFRO_HF_DIV_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 2U),      /*!< Attach FRO_HF_DIV to LPTMR0. */
    kCLK_IN_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 3U),      /*!< Attach CLK_IN to LPTMR0.     */
    kCLK_1M_to_LPTMR0     = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 5U),      /*!< Attach CLK_1M to LPTMR0.     */
    kPll1ClkDiv_to_LPTMR0 = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 6U),      /*!< Attach Pll1ClkDiv to LPTMR0. */
    kNONE_to_LPTMR0       = CLK_ATTACH_MUX(kCLOCK_SelLPTMR0, 7U),      /*!< Attach NONE to LPTMR0.       */

    kCLK_16K_to_OSTIMER = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 0U),      /*!< Attach FRO16K to OSTIMER0. */
    kCLK_1M_to_OSTIMER  = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 2U),      /*!< Attach CLK_1M to OSTIMER0. */
    kNONE_to_OSTIMER    = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 3U),      /*!< Attach NONE to OSTIMER0.   */

    kFRO_LF_DIV_to_ADC = CLK_ATTACH_MUX(kCLOCK_SelADC, 0U),            /*!< Attach FRO_LF_DIV to ADC. */
    kFRO_HF_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 1U),            /*!< Attach FRO_HF to ADC.     */
    kCLK_IN_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 3U),            /*!< Attach CLK_IN to ADC.     */
    kCLK_1M_to_ADC     = CLK_ATTACH_MUX(kCLOCK_SelADC, 5U),            /*!< Attach CLK_1M to ADC.     */
    kPll1ClkDiv_to_ADC = CLK_ATTACH_MUX(kCLOCK_SelADC, 6U),            /*!< Attach Pll1ClkDiv to ADC. */
    kNONE_to_ADC       = CLK_ATTACH_MUX(kCLOCK_SelADC, 7U),            /*!< Attach NONE to ADC.       */

    kFRO_LF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 0U),       /*!< Attach FRO_LF_DIV to CMP0. */
    kFRO_HF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 2U),       /*!< Attach FRO_HF_DIV to CMP0. */
    kCLK_IN_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 3U),       /*!< Attach CLK_IN to CMP0.     */
    kCLK_1M_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 5U),       /*!< Attach CLK_1M to CMP0.     */
    kPll1ClkDiv_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 6U),       /*!< Attach Pll1ClkDiv to CMP0. */
    kNONE_to_CMP0       = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 7U),       /*!< Attach NONE to CMP0.       */

    kFRO_LF_DIV_to_CMP1 = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 0U),       /*!< Attach FRO_LF_DIV to CMP1. */
    kFRO_HF_DIV_to_CMP1 = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 2U),       /*!< Attach FRO_HF_DIV to CMP1. */
    kCLK_IN_to_CMP1     = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 3U),       /*!< Attach CLK_IN to CMP1.     */
    kCLK_1M_to_CMP1     = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 5U),       /*!< Attach CLK_1M to CMP1.     */
    kPll1ClkDiv_to_CMP1 = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 6U),       /*!< Attach Pll1ClkDiv to CMP1. */
    kNONE_to_CMP1       = CLK_ATTACH_MUX(kCLOCK_SelCMP1_RR, 7U),       /*!< Attach NONE to CMP1.       */

    kFRO_LF_DIV_to_CMP2 = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 0U),       /*!< Attach FRO_LF_DIV to CMP2. */
    kFRO_HF_DIV_to_CMP2 = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 2U),       /*!< Attach FRO_HF_DIV to CMP2. */
    kCLK_IN_to_CMP2     = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 3U),       /*!< Attach CLK_IN to CMP2.     */
    kCLK_1M_to_CMP2     = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 5U),       /*!< Attach CLK_1M to CMP2.     */
    kPll1ClkDiv_to_CMP2 = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 6U),       /*!< Attach Pll1ClkDiv to CMP2. */
    kNONE_to_CMP2       = CLK_ATTACH_MUX(kCLOCK_SelCMP2_RR, 7U),       /*!< Attach NONE to CMP2.       */

    kCPU_CLK_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 0U),           /*!< Attach CPU_CLK to TRACE. */
    kCLK_1M_to_TRACE  = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 1U),           /*!< Attach CLK_1M to TRACE.  */
    kCLK_16K_to_TRACE = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 2U),           /*!< Attach CLK_16K to TRACE. */
    kNONE_to_TRACE    = CLK_ATTACH_MUX(kCLOCK_SelTRACE, 3U),           /*!< Attach NONE to TRACE.    */

    kFRO12M_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 0U),      /*!< Attach FRO_12M to CLKOUT.    */
    kFRO_HF_DIV_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 1U),      /*!< Attach FRO_HF_DIV to CLKOUT. */
    kCLK_IN_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 2U),      /*!< Attach CLK_IN to CLKOUT.     */
    kCLK_16K_to_CLKOUT    = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 3U),      /*!< Attach CLK_16K to CLKOUT.    */
    kPll1Clk_to_CLKOUT    = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 5U),      /*!< Attach Pll1Clk to CLKOUT.    */
    kSLOW_CLK_to_CLKOUT   = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 6U),      /*!< Attach SLOW_CLK to CLKOUT.   */
    kNONE_to_CLKOUT       = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 7U),      /*!< Attach NONE to CLKOUT.       */

    kCPU_CLK_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 0U),       /*!< Attach CPU_CLK to SYSTICK. */
    kCLK_1M_to_SYSTICK  = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 1U),       /*!< Attach CLK_1M to SYSTICK.  */
    kCLK_16K_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 2U),       /*!< Attach CLK_16K to SYSTICK. */
    kNONE_to_SYSTICK    = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 3U),       /*!< Attach NONE to SYSTICK.    */

    kNONE_to_NONE = (0xFFFFFFFFU),                                     /*!< Attach NONE to NONE. */

} clock_attach_id_t;

/*! @brief Clock dividers */
typedef enum _clock_div_name
{
    kCLOCK_DivI3C0_FCLK = (0x0A4U), /*!< I3C0_FCLK clock divider */
    kCLOCK_DivCTIMER0   = (0x0ACU), /*!< CTIMER0   clock divider */
    kCLOCK_DivCTIMER1   = (0x0B4U), /*!< CTIMER1   clock divider */
    kCLOCK_DivCTIMER2   = (0x0BCU), /*!< CTIMER2   clock divider */
    kCLOCK_DivCTIMER3   = (0x0C4U), /*!< CTIMER3   clock divider */
    kCLOCK_DivCTIMER4   = (0x0CCU), /*!< CTIMER4   clock divider */
    kCLOCK_DivWWDT0     = (0x0D4U), /*!< WWDT0     clock divider */
    kCLOCK_DivFLEXIO0   = (0x0DCU), /*!< FLEXIO0   clock divider */
    kCLOCK_DivLPI2C0    = (0x0E4U), /*!< LPI2C0    clock divider */
    kCLOCK_DivLPI2C1    = (0x0ECU), /*!< LPI2C1    clock divider */
    kCLOCK_DivLPSPI0    = (0x0F4U), /*!< LPSPI0    clock divider */
    kCLOCK_DivLPSPI1    = (0x0FCU), /*!< LPSPI1    clock divider */
    kCLOCK_DivLPUART0   = (0x104U), /*!< LPUART0   clock divider */
    kCLOCK_DivLPUART1   = (0x10CU), /*!< LPUART1   clock divider */
    kCLOCK_DivLPUART2   = (0x114U), /*!< LPUART2   clock divider */
    kCLOCK_DivLPUART3   = (0x11CU), /*!< LPUART3   clock divider */
    kCLOCK_DivLPUART4   = (0x124U), /*!< LPUART4   clock divider */
    kCLOCK_DivUSB0      = (0x12CU), /*!< USB0      clock divider */
    kCLOCK_DivLPTMR0    = (0x134U), /*!< LPTMR0    clock divider */
    kCLOCK_DivADC       = (0x144U), /*!< ADC       clock divider */
    kCLOCK_DivCMP0_FUNC = (0x14CU), /*!< CMP0_FUNC clock divider */
    kCLOCK_DivCMP0_RR   = (0x154U), /*!< CMP0_RR   clock divider */
    kCLOCK_DivCMP1_FUNC = (0x15CU), /*!< CMP1_FUNC clock divider */
    kCLOCK_DivCMP1_RR   = (0x164U), /*!< CMP1_RR   clock divider */
    kCLOCK_DivCMP2_FUNC = (0x16CU), /*!< CMP2_FUNC clock divider */
    kCLOCK_DivCMP2_RR   = (0x174U), /*!< CMP2_RR   clock divider */
    kCLOCK_DivDAC0      = (0x17CU), /*!< DAC0      clock divider */
    kCLOCK_DivFLEXCAN0  = (0x184U), /*!< FLEXCAN0  clock divider */
    kCLOCK_DivFLEXCAN1  = (0x18CU), /*!< FLEXCAN1  clock divider */
    kCLOCK_DivLPI2C2    = (0x194U), /*!< LPI2C2    clock divider */
    kCLOCK_DivLPI2C3    = (0x19CU), /*!< LPI2C3    clock divider */
    kCLOCK_DivLPUART5   = (0x1A4U), /*!< LPUART5   clock divider */
    kCLOCK_DivTRACE     = (0x1ACU), /*!< DBG_TRACE clock divider */
    kCLOCK_DivCLKOUT    = (0x1B4U), /*!< CLKOUT    clock divider */
    kCLOCK_DivSYSTICK   = (0x1BCU), /*!< SYSTICK   clock divider */
    kCLOCK_DivSLOWCLK   = (0x378U), /*!< SLOWCLK   clock divider */
    kCLOCK_DivBUSCLK    = (0x37CU), /*!< BUSCLK    clock divider */
    kCLOCK_DivAHBCLK    = (0x380U), /*!< AHBCLK    clock divider */
    kCLOCK_DivFRO_HF    = (0x388U), /*!< FROHF     clock divider */
    kCLOCK_DivFRO_LF    = (0x38CU), /*!< FROLF     clock divider */
    kCLOCK_DivPLL1CLK   = (0x3E4U), /*!< PLL1CLK   clock divider */
    kCLOCK_DivMax       = (0x3E4U), /*!< MAX       clock divider */
} clock_div_name_t;

/*!
 * @brief firc trim source.
 */
typedef enum _clke_16k
{
    kCLKE_16K_SYSTEM   = VBAT_FROCLKE_CLKE(1U), /*!< To VSYS domain.     */
    kCLKE_16K_COREMAIN = VBAT_FROCLKE_CLKE(2U)  /*!< To VDD_CORE domain. */
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
 * @brief SCG PLL1 monitor mode.
 */
typedef enum _scg_pll1_monitor_mode
{
    kSCG_Pll1MonitorDisable = 0U,                           /*!< Monitor disabled. */
    kSCG_Pll1MonitorInt     = SCG_SPLLCSR_SPLLCM_MASK,      /*!< Interrupt when the PLL1 Clock error is detected. */
    kSCG_Pll1MonitorReset =
        SCG_SPLLCSR_SPLLCM_MASK | SCG_SPLLCSR_SPLLCMRE_MASK /*!< Reset when the PLL1 Clock error is detected. */
} scg_pll1_monitor_mode_t;

/*!
 * @brief The active run mode (voltage level).
 */
typedef enum _run_mode
{
    kMD_Mode, /*!< Mid voltage (1.0 V).       */
    kOD_Mode, /*!< Overdrive voltage (1.2 V). */
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
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0_SET)) + reg_offset);

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
    else if (reg_offset == REG_PWM1SUBCTL)
    {
        SYSCON->PWM1SUBCTL |= (1UL << bit_shift);
        MRCC0->MRCC_GLB_CC1_SET = MRCC_MRCC_GLB_CC1_FLEXPWM1_MASK;
    }
    else
    {
        *pClkCtrl = (1UL << bit_shift);
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
    volatile uint32_t *pClkCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC0->MRCC_GLB_CC0_CLR)) + reg_offset);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_UNLOCK_MASK;

    if (reg_offset == REG_PWM0SUBCTL)
    {
        SYSCON->PWM0SUBCTL &= ~(1UL << bit_shift);

        if (0U == (SYSCON->PWM0SUBCTL & 0xFU))
        {
            MRCC0->MRCC_GLB_CC0_CLR = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
        }
    }
    else if (reg_offset == REG_PWM1SUBCTL)
    {
        SYSCON->PWM1SUBCTL &= ~(1UL << bit_shift);

        if (0U == (SYSCON->PWM1SUBCTL & 0xFU))
        {
            MRCC0->MRCC_GLB_CC1_CLR = MRCC_MRCC_GLB_CC1_FLEXPWM1_MASK;
        }
    }
    else
    {
        *pClkCtrl = (1UL << bit_shift);
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

/*! @brief  Return Frequency of I3C FCLK
 *  @return Frequency of I3C FCLK.
 */
uint32_t CLOCK_GetI3CFClkFreq(void);

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

/*! @brief  Return Frequency of OSTIMER
 *  @return Frequency of OSTIMER Clock
 */
uint32_t CLOCK_GetOstimerClkFreq(void);

/*! @brief  Return Frequency of Adc Clock
 *  @return Frequency of Adc.
 */
uint32_t CLOCK_GetAdcClkFreq(uint32_t id);

/*! @brief  Return Frequency of Dac Clock
 *  @return Frequency of Dac.
 */
uint32_t CLOCK_GetDacClkFreq(void);

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

/*! @brief  Return Frequency of FLEXIO FCLK
 *  @return Frequency of FLEXIO FCLK.
 */
uint32_t CLOCK_GetFlexioClkFreq(void);

/*! @brief  Return Frequency of FlexCAN FCLK
 *  @return Frequency of FlexCAN FCLK.
 */
uint32_t CLOCK_GetFlexcanClkFreq(uint32_t id);

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

/*! brief Enable USB FS clock.
 * Enable USB Full Speed clock.
 */
bool CLOCK_EnableUsbfsClock(void);

/*!
 * @brief   Set the additional number of wait-states added to account for the ratio of system clock period to flash
 * access time during full speed power mode.
 * @param   system_freq_hz  : Input frequency
 * @param   mode            : Active run mode (voltage level).
 * @return  success or fail status
 */
status_t CLOCK_SetFLASHAccessCyclesForFreq(uint32_t system_freq_hz, run_mode_t mode);

/*!
 * @brief Sets the PLL1 monitor mode.
 *
 * This function sets the PLL1 monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetPll1MonitorMode(scg_pll1_monitor_mode_t mode);

/*! @brief    Return  PLL1 input clock rate
 *  @return    PLL1 input clock rate
 */
uint32_t CLOCK_GetPLL1InClockRate(void);

/*! @brief  Check if PLL1 is locked or not
 *  @return true if the PLL1 is locked, false if not locked
 */
__STATIC_INLINE bool CLOCK_IsPLL1Locked(void)
{
    return (bool)((SCG0->SPLLCSR & SCG_SPLLCSR_SPLL_LOCK_MASK) != 0UL);
}

/*! @brief PLL configuration structure flags for 'flags' field
 * These flags control how the PLL configuration function sets up the PLL setup structure.<br>
 *
 * When the PLL_CONFIGFLAG_FORCENOFRACT flag is selected, the PLL hardware for the
 * automatic bandwidth selection, Spread Spectrum (SS) support, and fractional M-divider
 * are not used.<br>
 */
#define PLL_CONFIGFLAG_FORCENOFRACT (1U << 2U)
/*!< Force non-fractional output mode, PLL output will not use the fractional, automatic bandwidth, or SS hardware */

/*!
 * @brief PLL clock source.
 */
typedef enum _pll_clk_src
{
    kPll_ClkSrcSysOsc = (0 << 25), /*!< System OSC. */
    kPll_ClkSrcFirc   = (1 << 25), /*!< Fast IRC.   */
    kPll_ClkSrcSirc   = (3 << 25), /*!< Slow IRC. */
} pll_clk_src_t;

/*! @brief PLL Spread Spectrum (SS) Programmable modulation frequency
 * See (MF) field in the PLL0SSCG1 register in the UM.
 */
typedef enum _ss_progmodfm
{
    kSS_MF_512 = (0 << 2), /*!< Nss =  512 (fm ~= 3.9  - 7.8   kHz) */
    kSS_MF_384 = (1 << 2), /*!< Nss ~= 384 (fm ~= 5.2  - 10.4  kHz) */
    kSS_MF_256 = (2 << 2), /*!< Nss =  256 (fm ~= 7.8  - 15.6  kHz) */
    kSS_MF_128 = (3 << 2), /*!< Nss =  128 (fm ~= 15.6 - 31.3  kHz) */
    kSS_MF_64  = (4 << 2), /*!< Nss =  64  (fm ~= 32.3 - 64.5  kHz) */
    kSS_MF_32  = (5 << 2), /*!< Nss =  32  (fm ~= 62.5 - 125   kHz) */
    kSS_MF_24  = (6 << 2), /*!< Nss ~= 24  (fm ~= 83.3 - 166.6 kHz) */
    kSS_MF_16  = (7 << 2)  /*!< Nss =  16  (fm ~= 125  - 250   kHz) */
} ss_progmodfm_t;

/*! @brief PLL Spread Spectrum (SS) Programmable frequency modulation depth
 * See (MR) field in the PLL0SSCG1 register in the UM.
 */
typedef enum _ss_progmoddp
{
    kSS_MR_K0   = (0 << 5), /*!< k =  0 (no spread spectrum) */
    kSS_MR_K1   = (1 << 5), /*!< k ~= 1                      */
    kSS_MR_K1_5 = (2 << 5), /*!< k ~= 1.5                    */
    kSS_MR_K2   = (3 << 5), /*!< k ~= 2                      */
    kSS_MR_K3   = (4 << 5), /*!< k ~= 3                      */
    kSS_MR_K4   = (5 << 5), /*!< k ~= 4                      */
    kSS_MR_K6   = (6 << 5), /*!< k ~= 6                      */
    kSS_MR_K8   = (7 << 5)  /*!< k ~= 8                      */
} ss_progmoddp_t;

/*! @brief PLL Spread Spectrum (SS) Modulation waveform control
 * See (MC) field in the PLL0SSCG1 register in the UM.<br>
 * Compensation for low pass filtering of the PLL to get a triangular
 * modulation at the output of the PLL, giving a flat frequency spectrum.
 */
typedef enum _ss_modwvctrl
{
    kSS_MC_NOC  = (0 << 8), /*!< no compensation */
    kSS_MC_RECC = (2 << 8), /*!< recommended setting */
    kSS_MC_MAXC = (3 << 8), /*!< max. compensation */
} ss_modwvctrl_t;

/*! @brief PLL configuration structure
 *
 * This structure can be used to configure the settings for a PLL
 * setup structure. Fill in the desired configuration for the PLL
 * and call the PLL setup function to fill in a PLL setup structure.
 */
typedef struct _pll_config
{
    uint32_t desiredRate; /*!< Desired PLL rate in Hz */
    uint32_t inputSource; /*!< PLL input source */
    uint32_t flags;       /*!< PLL configuration flags, Or'ed value of PLL_CONFIGFLAG_* definitions */
    ss_progmodfm_t ss_mf; /*!< SS Programmable modulation frequency, only applicable when not using
                             PLL_CONFIGFLAG_FORCENOFRACT flag */
    ss_progmoddp_t ss_mr; /*!< SS Programmable frequency modulation depth, only applicable when not using
                             PLL_CONFIGFLAG_FORCENOFRACT flag */
    ss_modwvctrl_t
        ss_mc;     /*!< SS Modulation waveform control, only applicable when not using PLL_CONFIGFLAG_FORCENOFRACT flag
                    */
    bool mfDither; /*!< false for fixed modulation frequency or true for dithering, only applicable when not using
                      PLL_CONFIGFLAG_FORCENOFRACT flag */

} pll_config_t;

/*! @brief PLL0 setup structure
 * This structure can be used to pre-build a PLL setup configuration
 * at run-time and quickly set the PLL to the configuration. It can be
 * populated with the PLL setup function. If powering up or waiting
 * for PLL lock, the PLL input clock source should be configured prior
 * to PLL setup.
 */
typedef struct _pll_setup
{
    uint32_t pllctrl;    /*!< PLL Control register APLLCTRL */
    uint32_t pllndiv;    /*!< PLL N Divider register APLLNDIV */
    uint32_t pllpdiv;    /*!< PLL P Divider register APLLPDIV */
    uint32_t pllmdiv;    /*!< PLL M Divider register APLLMDIV */
    uint32_t pllsscg[2]; /*!< PLL Spread Spectrum Control registers APLLSSCG*/
    uint32_t pllRate;    /*!< Acutal PLL rate */
} pll_setup_t;

/*! @brief PLL status definitions
 */
typedef enum _pll_error
{
    kStatus_PLL_Success         = MAKE_STATUS(kStatusGroup_Generic, 0), /*!< PLL operation was successful */
    kStatus_PLL_OutputTooLow    = MAKE_STATUS(kStatusGroup_Generic, 1), /*!< PLL output rate request was too low */
    kStatus_PLL_OutputTooHigh   = MAKE_STATUS(kStatusGroup_Generic, 2), /*!< PLL output rate request was too high */
    kStatus_PLL_OutputError     = MAKE_STATUS(kStatusGroup_Generic, 3), /*!< PLL output rate error */
    kStatus_PLL_InputTooLow     = MAKE_STATUS(kStatusGroup_Generic, 4), /*!< PLL input rate is too low */
    kStatus_PLL_InputTooHigh    = MAKE_STATUS(kStatusGroup_Generic, 5), /*!< PLL input rate is too high */
    kStatus_PLL_OutsideIntLimit = MAKE_STATUS(kStatusGroup_Generic, 6), /*!< Requested output rate isn't possible */
    kStatus_PLL_CCOTooLow       = MAKE_STATUS(kStatusGroup_Generic, 7), /*!< Requested CCO rate isn't possible */
    kStatus_PLL_CCOTooHigh      = MAKE_STATUS(kStatusGroup_Generic, 8)  /*!< Requested CCO rate isn't possible */
} pll_error_t;

/*! @brief    Return PLL0 output clock rate from setup structure
 *  @param    pSetup : Pointer to a PLL setup structure
 *  @return   System PLL output clock rate the setup structure will generate
 */
uint32_t CLOCK_GetPLLOutFromSetup(pll_setup_t *pSetup);

/*! @brief    Set PLL output based on the passed PLL setup data
 *  @param    pControl    : Pointer to populated PLL control structure to generate setup with
 *  @param    pSetup      : Pointer to PLL setup structure to be filled
 *  @return   PLL_ERROR_SUCCESS on success, or PLL setup error code
 *  @note Actual frequency for setup may vary from the desired frequency based on the
 *  accuracy of input clocks, rounding, non-fractional PLL mode, etc.
 */
pll_error_t CLOCK_SetupPLLData(pll_config_t *pControl, pll_setup_t *pSetup);

/**
 * @brief Set PLL output from PLL setup structure (precise frequency)
 * @param pSetup  : Pointer to populated PLL setup structure
 * @return    kStatus_PLL_Success on success, or PLL setup error code
 * @note  This function will power off the PLL, setup the PLL with the
 * new setup data, and then optionally powerup the PLL, wait for PLL lock,
 * and adjust system voltages to the new PLL rate. The function will not
 * alter any source clocks (ie, main systen clock) that may use the PLL,
 * so these should be setup prior to and after exiting the function.
 */
pll_error_t CLOCK_SetPLL1Freq(const pll_setup_t *pSetup);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */
