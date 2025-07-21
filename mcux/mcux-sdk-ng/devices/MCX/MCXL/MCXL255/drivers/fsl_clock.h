/*
 * Copyright 2025 NXP
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
/*! @brief CLOCK driver version 1.1.0. */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(1, 1, 0))
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

/* Definition for delay API in clock driver, users can redefine it to the real application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#if __CORTEX_M == 33
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (96000000U)
#else
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (10000000U)
#endif
#endif

/*! @brief External XTAL32/EXTAL32 clock frequency.
 *
 * The XTAL32/EXTAL32 clock frequency in Hz. When the clock is set up, use the
 * function CLOCK_SetXtal32Freq to set the value in the clock driver.
 *
 * This is important for the multicore platforms where only one core needs to set up
 * the clock. All other cores need to call the CLOCK_SetXtal32Freq
 * to get a valid clock frequency.
 */
extern volatile uint32_t g_xtal32Freq;

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
/*------------------------------------------------------------------------------
 clock_ip_name_t definition:
------------------------------------------------------------------------------*/
/*! @brief The offset of the registers MRCC_GLB_PR0 and MRCC_GLB_PR1. */
#define CLK_GATE_REG_PR_OFFSET(value) ((((uint32_t)(value)) >> 16U) & 0x000000FFU)
/*! @brief The offset of the registers MRCC_GLB_CC0 and MRCC_GLB_CC1. */
#define CLK_GATE_REG_CC_OFFSET(value) ((((uint32_t)(value)) >> 8U) & 0x000000FFU)
/*! @brief Bit definitions for the peripherals in MRCC_GLB_PR and MRCC_GLB_CC */
#define CLK_PERIPHERAL_BIT_SHIFT(value) (((uint32_t)(value)) & 0x000000FFU)
/*! @brief True when clock gate belongs to AON domain */
#define CLK_OF_AON(value) (((uint32_t)(value)) & (1U<<24U))

#define REG_PWM0SUBCTL (250U)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
#if __CORTEX_M == (33U) /* Building on the main core */

    /* Check syscon mrcc reg, in RM */
    kCLOCK_InputMux          = (0xFFFFFFF0U),                          /*!< Clock gate name: INPUTMUX0 + AON_INPUTMUX1 */
    kCLOCK_GateINPUTMUX0     = (0x00U | (0U)),                         /*!< Clock gate name: INPUTMUX0      */
    kCLOCK_GateCTIMER0       = (0x00U | (1U)),                         /*!< Clock gate name: CTIMER0        */
    kCLOCK_GateCTIMER1       = (0x00U | (2U)),                         /*!< Clock gate name: CTIMER1        */
    kCLOCK_GateCTIMER2       = (0x00U | (3U)),                         /*!< Clock gate name: CTIMER2        */
    kCLOCK_GateFREQME        = (0x00U | (4U)),                         /*!< Clock gate name: FREQME         */
    kCLOCK_GateUTICK0        = (0x00U | (5U)),                         /*!< Clock gate name: UTICK0         */
    kCLOCK_GateWWDT0         = (0x00U | (6U)),                         /*!< Clock gate name: WWDT0          */
    kCLOCK_GateDMA0          = (0x00U | (7U)),                         /*!< Clock gate name: DMA0           */
    kCLOCK_GateAOI0          = (0x00U | (8U)),                         /*!< Clock gate name: AOI0           */
    kCLOCK_GateCrc           = (0x00U | (9U)),                         /*!< Clock gate name: CRC            */
    kCLOCK_Crc0              = (0x00U | (9U)),                         /*!< Clock gate name: CRC (Alias)    */
    kCLOCK_GateERM0          = (0x00U | (10U)),                        /*!< Clock gate name: ERM0           */
    kCLOCK_GateLPI2C0        = (0x00U | (14U)),                        /*!< Clock gate name: LPI2C0         */
    kCLOCK_GateLPI2C1        = (0x00U | (15U)),                        /*!< Clock gate name: LPI2C0         */
    kCLOCK_GateLPSPI0        = (0x00U | (16U)),                        /*!< Clock gate name: LPSPI0         */
    kCLOCK_GateLPSPI1        = (0x00U | (17U)),                        /*!< Clock gate name: LPSPI1         */
    kCLOCK_GateLPUART0       = (0x00U | (18U)),                        /*!< Clock gate name: LPUART0        */
    kCLOCK_GateADC0          = (0x00U | (19U)),                        /*!< Clock gate name: ADC0           */
    kCLOCK_GateATX0          = (0x00U | (20U)),                        /*!< Clock gate name: ATX0           */
    kCLOCK_GateCMP0          = (0x00U | (21U)),                        /*!< Clock gate name: CMP0           */
    kCLOCK_GateDMA1          = (0x00U | (22U)),                        /*!< Clock gate name: DMA1           */
    kCLOCK_GateSRAMA0A1      = (0x00U | (23U)),                        /*!< Clock gate name: SRAMA0A1       */
    kCLOCK_GateGPIO1         = (0x00U | (24U)),                        /*!< Clock gate name: GPIO1          */
    kCLOCK_GateGPIO2         = (0x00U | (25U)),                        /*!< Clock gate name: GPIO2          */
    kCLOCK_GateGPIO3         = (0x00U | (26U)),                        /*!< Clock gate name: GPIO3          */
    kCLOCK_GateLPUART1       = (0x00U | (27U)),                        /*!< Clock gate name: LPUART1        */
    kCLOCK_GateMTR           = (0x00U | (28U)),                        /*!< Clock gate name: MTR            */
    kCLOCK_GateOSTIMER0      = (0x00U | (29U)),                        /*!< Clock gate name: OSTIMER0       */
    kCLOCK_GatePERIPH_GROUP0 = (0x00U | (30U)),                        /*!< Clock gate name: PERIPH_GROUP_0 */
    kCLOCK_GatePERIPH_GROUP1 = (0x00U | (31U)),                        /*!< Clock gate name: PERIPH_GROUP_1 */

    kCLOCK_GatePKC0          = ((0x4U << 16U) | (0x10U << 8U) | (0U)), /*!< Clock gate name: PKC0           */
    kCLOCK_GatePORT1         = ((0x4U << 16U) | (0x10U << 8U) | (1U)), /*!< Clock gate name: PORT1          */
    kCLOCK_GatePORT2         = ((0x4U << 16U) | (0x10U << 8U) | (2U)), /*!< Clock gate name: PORT2          */
    kCLOCK_GatePORT3         = ((0x4U << 16U) | (0x10U << 8U) | (3U)), /*!< Clock gate name: PORT3          */
    kCLOCK_GateROMCP         = ((0x4U << 16U) | (0x10U << 8U) | (4U)), /*!< Clock gate name: ROMCP          */
    kCLOCK_GateSGIO0         = ((0x4U << 16U) | (0x10U << 8U) | (5U)), /*!< Clock gate name: SGIO0          */
    kCLOCK_GateSGLCD         = ((0x4U << 16U) | (0x10U << 8U) | (6U)), /*!< Clock gate name: SGLCD          */
    kCLOCK_GateTCU           = ((0x4U << 16U) | (0x10U << 8U) | (7U)), /*!< Clock gate name: TCU            */
    kCLOCK_GateTRNG0         = ((0x4U << 16U) | (0x10U << 8U) | (8U)), /*!< Clock gate name: TRNG0          */
    kCLOCK_GateUDF0          = ((0x4U << 16U) | (0x10U << 8U) | (9U)), /*!< Clock gate name: UDF0           */
#else
    kCLOCK_InputMux          = ((1U<<24U) | (16U)),                    /*!< Clock gate name: AON INPUTMUX  (only)*/
#endif /* Building on the main core */

    /* Check AON CGU PER_CLK_EN in RM */
    kCLOCK_GateAonUART       = ((1U<<24U) | (0U)),                     /*!< Clock gate name: AON UART       */
    kCLOCK_GateAonI2C        = ((1U<<24U) | (1U)),                     /*!< Clock gate name: AON I2C        */
    kCLOCK_GateAonAPB        = ((1U<<24U) | (2U)),                     /*!< Clock gate name: AON APB        */
    kCLOCK_GateAonPORT       = ((1U<<24U) | (5U)),                     /*!< Clock gate name: AON PORT       */
    kCLOCK_GateAonGPIO       = ((1U<<24U) | (6U)),                     /*!< Clock gate name: AON GPIO       */
    kCLOCK_GateAonQTMR0      = ((1U<<24U) | (7U)),                     /*!< Clock gate name: AON QTMR0      */
    kCLOCK_GateAonQTMR1      = ((1U<<24U) | (7U)),                     /*!< Clock gate name: AON QTMR1      */
    kCLOCK_GateAonLPTMR      = ((1U<<24U) | (9U)),                     /*!< Clock gate name: AON LPTMR      */
    kCLOCK_GateAonKPP        = ((1U<<24U) | (10U)),                    /*!< Clock gate name: AON KPP        */
    kCLOCK_GateAonLPADC      = ((1U<<24U) | (11U)),                    /*!< Clock gate name: AON LPADC      */
    kCLOCK_GateAonSYS        = ((1U<<24U) | (12U)),                    /*!< Clock gate name: AON SYS (tick) */
    kCLOCK_GateAonCMP0       = ((1U<<24U) | (13U)),                    /*!< Clock gate name: AON comparator */
    kCLOCK_GateAonLCD        = ((1U<<24U) | (14U)),                    /*!< Clock gate name: AON LCD        */
    kCLOCK_GateAonAVDC2P0    = ((1U<<24U) | (15U)),                    /*!< Clock gate name: AON AVDC2P0    */
    kCLOCK_GateAonINPUTMUX1   = ((1U<<24U) | (16U)),                    /*!< Clock gate name: AON INPUTMUX   */

    kCLOCK_GateNotAvail      = (0xFFFFFFFFU),                          /**< Clock gate name: None           */
} clock_ip_name_t;

/*! @brief Clock ip name array for SLCD. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define SLCD_FAULT_DETECT_CLOCKS \
    {                            \
        kCLOCK_GateSGLCD         \
    }
#else
#define SLCD_FAULT_DETECT_CLOCKS \
    {                            \
        kCLOCK_GateNotAvail      \
    }
#endif
#define SLCD_CONTROL_CLOCKS \
    {                       \
        kCLOCK_GateAonLCD   \
    }

/*! @brief Clock ip name array for AOI. */
#define AOI_CLOCKS      \
    {                   \
        kCLOCK_GateNotAvail \
    }
/*! @brief Clock ip name array for ATX. */
#define ATX_CLOCKS      \
    {                   \
        kCLOCK_GateNotAvail \
    }
/*! @brief Clock ip name array for CRC. */
#define CRC_CLOCKS  \
    {               \
        kCLOCK_GateNotAvail \
    }
/*! @brief Clock ip name array for CTIMER. */
#define CTIMER_CLOCKS                                              \
    {                                                              \
        kCLOCK_GateCTIMER0, kCLOCK_GateCTIMER1, kCLOCK_GateCTIMER2 \
    }
/*! @brief Clock ip name array for DMA. */
#define DMA_CLOCKS     \
    {                  \
        kCLOCK_GateDMA0, kCLOCK_GateDMA1 \
    }
#define ERM_CLOCKS     \
    {                  \
        kCLOCK_GateERM0 \
    }
/*! @brief Clock gate name array for EDMA. */
#define EDMA_CLOCKS    \
    {                  \
        kCLOCK_GateDMA0, kCLOCK_GateDMA1 \
    }
/*! @brief Clock ip name array for EZRAMC_RAMA. */
#define EZRAMC_CLOCKS          \
    {                          \
        kCLOCK_GateEZRAMC_RAMA \
    }
/*! @brief Clock ip name array for FREQME. */
#define FREQME_CLOCKS     \
    {                     \
        kCLOCK_GateFREQME \
    }
/*! @brief Clock ip name array for GPIO. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define GPIO_CLOCKS                        \
    {                                      \
        kCLOCK_GateAonGPIO, kCLOCK_GateGPIO1, kCLOCK_GateGPIO2, kCLOCK_GateGPIO3 \
    }
#else
#define GPIO_CLOCKS                        \
    {                                      \
        kCLOCK_GateAonGPIO \
    }
#endif
/*! @brief Clock ip name array for INPUTMUX. */ 
#if __CORTEX_M == (33U) /* Building on the main core */
#define INPUTMUX_CLOCKS      \
    {                        \
        kCLOCK_GateINPUTMUX0, kCLOCK_GateAonINPUTMUX1 \
    }
#else
#define INPUTMUX_CLOCKS      \
    {                        \
        kCLOCK_GateNotAvail, kCLOCK_GateAonINPUTMUX1 \
    }
#endif

/*! @brief Clock ip name array for LPCMP. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define LPCMP_CLOCKS                        \
    {                                       \
        kCLOCK_GateAonCMP0, kCLOCK_GateCMP0 \
    }
#else
    #define LPCMP_CLOCKS                    \
    {                                       \
        kCLOCK_GateAonCMP0                  \
    }
#endif

/*! @brief Clock ip name array for LPADC. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define LPADC_CLOCKS    \
    {                   \
         kCLOCK_GateADC0 \
    }
#endif
    
/*! @brief Clock ip name array for LPADC. */
#define AON_LPADC_CLOCKS    \
    {                   \
         kCLOCK_GateAonLPADC \
    }

/*! @brief Clock ip name array for LPUART. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define LPUART_CLOCKS                          \
    {                                          \
        kCLOCK_GateLPUART0, kCLOCK_GateLPUART1, kCLOCK_GateAonUART \
    }
#else
#define LPUART_CLOCKS                          \
    {                                          \
        kCLOCK_GateNotAvail, kCLOCK_GateNotAvail, kCLOCK_GateAonUART \
    }
#endif


/*! @brief Clock ip name array for LPI2C. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define LPI2C_CLOCKS      \
    {                     \
        kCLOCK_GateLPI2C0, kCLOCK_GateLPI2C1, kCLOCK_GateAonI2C \
    }
#else
#define LPI2C_CLOCKS      \
    {                     \
        kCLOCK_GateNotAvail, kCLOCK_GateNotAvail, kCLOCK_GateAonI2C \
    }
#endif

/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                         \
    {                                        \
        kCLOCK_GateLPSPI0, kCLOCK_GateLPSPI1 \
    }
/*! @brief Clock ip name array for MTR. */
#define MTR_CLOCKS     \
    {                  \
        kCLOCK_GateMTR \
    }
/*! @brief Clock ip name array for OSTIMER. */
#define OSTIMER_CLOCKS      \
    {                       \
        kCLOCK_GateOSTIMER0 \
    }
/*! @brief Clock ip name array for PERIPH_GROUP. */
#define PERIPHGROUP_CLOCKS                                 \
    {                                                      \
        kCLOCK_GatePERIPH_GROUP0, kCLOCK_GatePERIPH_GROUP1 \
    }
/*! @brief Clock ip name array for PORT. */
#if __CORTEX_M == (33U) /* Building on the main core */
#define PORT_CLOCKS                        \
    {                                      \
        kCLOCK_GateAonPORT, kCLOCK_GatePORT1, kCLOCK_GatePORT2, kCLOCK_GatePORT3  \
    }
#else
#define PORT_CLOCKS        \
    {                      \
        kCLOCK_GateAonPORT \
    }
#endif
/*! @brief Clock ip name array for ROMCP. */
#define ROMCP_CLOCKS     \
    {                    \
        kCLOCK_GateROMCP \
    }
/*! @brief Clock ip name array for TCU. */
#define TCU_CLOCKS     \
    {                  \
        kCLOCK_GateTCU \
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
/*! @brief Peripherals clock source definition. */
#define BUS_CLK kCLOCK_BusClk
/*! @brief Clock ip name array for QTMRs. */
#define TMR_CLOCKS      \
    {                    \
        kCLOCK_GateAonQTMR0, kCLOCK_GateAonQTMR1 \
    }
/*! @brief Clock ip name array for QTMRs. */
#define KPP_CLOCKS      \
    {                    \
        kCLOCK_GateAonKPP \
    }


/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_name
{
#if __CORTEX_M == (33U) /* Building on the main core */
    kCLOCK_MainClk,    /*!< MAIN_CLK                   */
    kCLOCK_CoreSysClk, /*!< Core/system clock(CPU_CLK) */
    kCLOCK_SYSTEM_CLK, /*!< AHB clock                  */
    kCLOCK_BusClk,     /*!< Bus clock (AHB clock)      */
    kCLOCK_FlashCLK,   /*!< Flash clock                */
    kCLOCK_FroHf,      /*!< FRO192                     */
    kCLOCK_FroHfDiv,   /*!< Divided by FRO192          */
    kCLOCK_Fro12M,     /*!< FRO12M  (SIRC)             */
    kCLOCK_Clk1M,      /*!< CLK1M                      */
    kCLOCK_Clk16K,     /*!< CLK16K[0] clock from ROSC  */
    kCLOCK_SLOW_CLK,   /*!< SYSTEM_CLK divided by 4    */
#endif
    kCLOCK_RtcOscClk,  /*!< RTC OSC clock.             */
    kCLOCK_Fro16k,     /*!< AON PAC and SMM clock.     */
    kCLOKC_FroAON      /*!< AON free runnin clock.     */
} clock_name_t;

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

/* Use following on value returned from CLK_ATTACH_REG_OFFSET */
#define CLK_OF_AON_SEL(value) (((uint32_t)(value)) & (1U << 15U))
#define CLK_AON_SEL_REG_OFFSET(value) ((((uint32_t)(value)) >> 12U) & 7U)
#define CLK_AON_SEL_SHIFT(value)      ((((uint32_t)(value)) >> 8U) & 0xFU)
#define CLK_AON_SEL_MASK(value)       (((uint32_t)(value)) & 0xFFU)
#define CLK_AON_SEL(reg, shift, mask) ( (1U                  << 15U) |\
                                        (((uint32_t)(reg))   << 12U) |\
                                        (((uint32_t)(shift)) <<  8U) |\
                                        (((uint32_t)(mask))) )

/*! @brief Clock name used to get clock frequency. */
typedef enum _clock_select_name
{
#if __CORTEX_M == (33U) /* Building on the main core */
    kCLOCK_SelCTIMERg0      = (0x0A0U), /*!< CTIMER0  (grp0) clock selection  */
    kCLOCK_SelCTIMERg1      = (0x0A8U), /*!< CTIMER1,2 (grp1) clock selection */
    kCLOCK_SelUTICK0        = (0x0B0U), /*!< UTICK0    clock selection        */
    kCLOCK_SelOSTIMER0      = (0x0E8U), /*!< OSTIMER0  clock selection        */
    kCLOCK_SelADC0          = (0x0C0U), /*!< ADC0      clock selection        */
    kCLOCK_SelCMP0_RR       = (0x0D0U), /*!< CMP0_RR   clock selection        */
    kCLOCK_SelCLKOUT        = (0x0E0U), /*!< CLKOUT    clock selection        */
    kCLOCK_SelPERIPH_GROUP0 = (0x0F0U), /*!< PERIPH_GROUP_0 clock selection   */
    kCLOCK_SelPERIPH_GROUP1 = (0x0F8U), /*!< PERIPH_GROUP_1 clock selection   */
    kCLOCK_SelSYSTICK       = (0x100U), /*!< SYSTICK   clock selection        */
    kCLOCK_SelSCGSCS        = (0x200U), /*!< SCG SCS   clock selection        */
    kCLOCK_SelFIRC          = (0x300U), /*!< FIRC Divider clock selection     */
#endif

    kCLOKC_SelAonROOT_AUX   = CLK_AON_SEL(0U,  4U, 1U), /*!< AON ROOT_AUX clock selection          */
    kCLOKC_SelAonROOT       = CLK_AON_SEL(0U,  2U, 3U), /*!< AON ROOT clock selection              */
    kCLOKC_SelAonACMP0      = CLK_AON_SEL(4U, 13U, 3U), /*!< AON ACMP0 clock selection             */
    kCLOKC_SelAonLCD        = CLK_AON_SEL(4U, 12U, 1U), /*!< AON LCD clock selection               */
    kCLOKC_SelAonLPADC      = CLK_AON_SEL(4U,  9U, 7U), /*!< AON LPADC clock selection             */
    kCLOKC_SelAonSYSTICK    = CLK_AON_SEL(4U,  7U, 3U), /*!< AON SYS tick clock selection          */
    kCLOKC_SelAonKPP        = CLK_AON_SEL(4U,  6U, 1U), /*!< AON KPP clock selection               */
    kCLOKC_SelAonLPTMR      = CLK_AON_SEL(4U,  4U, 3U), /*!< AON LPTMR GRP clock selection         */
    kCLOKC_SelAonTMR        = CLK_AON_SEL(4U,  2U, 3U), /*!< AON TMR GRP clock selection           */
    kCLOKC_SelAonCOM        = CLK_AON_SEL(4U,  0U, 3U), /*!< AON COM comaprator (aon_per_clk) clock selection */
} clock_select_name_t;

/*!
 * @brief The enumerator of clock attach Id.
 */

typedef enum _clock_attach_id
{
    kXTAL32K_to_AON_ROOT_AUX     = CLK_ATTACH_MUX(kCLOKC_SelAonROOT_AUX, 0U),         /*!< Attach XTAL32K to AON AUX.   */
    kAUX_to_AON_ROOT_AUX      = CLK_ATTACH_MUX(kCLOKC_SelAonROOT_AUX, 1U),         /*!< Attach AUX to AON AUX.    */

    kFROdiv1_to_AON_CPU     = CLK_ATTACH_MUX(kCLOKC_SelAonROOT, 0U),         /*!< Attach FRO div 1 to AON_CPU.   */
    kFROdiv2_to_AON_CPU     = CLK_ATTACH_MUX(kCLOKC_SelAonROOT, 1U),         /*!< Attach FRO div 2 to AON_CPU.   */
    kFROdiv4_to_AON_CPU     = CLK_ATTACH_MUX(kCLOKC_SelAonROOT, 2U),         /*!< Attach FRO div 4 to AON_CPU.   */
    kROOT_AUX_to_AON_CPU    = CLK_ATTACH_MUX(kCLOKC_SelAonROOT, 3U),         /*!< Attach ROOT AUX to AON_CPU.    */

    kFROdiv1_to_AON_CMP0     = CLK_ATTACH_MUX(kCLOKC_SelAonACMP0, 0U),         /*!< Attach FRO div 1 to AON ACMP0.   */
    kFROdiv2_to_AON_CMP0     = CLK_ATTACH_MUX(kCLOKC_SelAonACMP0, 1U),         /*!< Attach FRO div 2 to AON ACMP0.   */
    kFROdiv4_to_AON_CMP0     = CLK_ATTACH_MUX(kCLOKC_SelAonACMP0, 2U),         /*!< Attach FRO div 4 to AON ACMP0.   */
    kROOT_AUX_to_AON_CMP0    = CLK_ATTACH_MUX(kCLOKC_SelAonACMP0, 3U),         /*!< Attach ROOT AUX to AON ACMP0.    */

    kCLK_16K_to_AON_LCD     = CLK_ATTACH_MUX(kCLOKC_SelAonLCD, 0U),         /*!< Attach FRO clk_16k to AON LCD.   */
    kFRO16K_to_AON_LCD      = CLK_ATTACH_MUX(kCLOKC_SelAonLCD, 1U),         /*!< Attach FRO fro16k to AON LCD.   */

    kFROdiv1_to_AON_LPADC     = CLK_ATTACH_MUX(kCLOKC_SelAonLPADC, 0U),         /*!< Attach FRO div 1 to AON LPADC.   */
    kFROdiv2_to_AON_LPADC     = CLK_ATTACH_MUX(kCLOKC_SelAonLPADC, 1U),         /*!< Attach FRO div 2 to AON LPADC.   */
    kFROdiv4_to_AON_LPADC     = CLK_ATTACH_MUX(kCLOKC_SelAonLPADC, 2U),         /*!< Attach FRO div 4 to AON LPADC.   */
    kROOT_AUX_to_AON_LPADC    = CLK_ATTACH_MUX(kCLOKC_SelAonLPADC, 3U),         /*!< Attach ROOT AUX to AON LPADC.    */
    kXTAL32K_to_AON_LPADC     = CLK_ATTACH_MUX(kCLOKC_SelAonLCD,   4U),         /*!< Attach FRO RTC to AON LPADC.     */
    kFRO16K_to_AON_LPADC      = CLK_ATTACH_MUX(kCLOKC_SelAonLCD,   5U),         /*!< Attach FRO fro16k to AON LPADC.  */

    kFROdiv1_to_AON_SYSTICK     = CLK_ATTACH_MUX(kCLOKC_SelAonSYSTICK, 0U),     /*!< Attach FRO div 1 to AON SYSTICK.   */
    kFROdiv2_to_AON_SYSTICK     = CLK_ATTACH_MUX(kCLOKC_SelAonSYSTICK, 1U),     /*!< Attach FRO div 2 to AON SYSTICK.   */
    kFROdiv4_to_AON_SYSTICK     = CLK_ATTACH_MUX(kCLOKC_SelAonSYSTICK, 2U),     /*!< Attach FRO div 4 to AON SYSTICK.   */
    kROOT_AUX_to_AON_SYSTICK    = CLK_ATTACH_MUX(kCLOKC_SelAonSYSTICK, 3U),     /*!< Attach ROOT AUX to AON SYSTICK.    */

    kXTAL32K_to_AON_KPP     = CLK_ATTACH_MUX(kCLOKC_SelAonKPP, 0U),         /*!< Attach XTAL32K to AON KPP.   */
    kFRO16K_to_AON_KPP      = CLK_ATTACH_MUX(kCLOKC_SelAonKPP, 1U),         /*!< Attach FRO fro16k to AON KPP.   */

    AON_TMR_to_AON_LPTMR    = CLK_ATTACH_MUX(kCLOKC_SelAonLPTMR, 0U),       /*!< Attach AON TIMER CLK to AON LPTMR GRP.*/
    kFRO16K_to_AON_LPTMR    = CLK_ATTACH_MUX(kCLOKC_SelAonLPTMR, 1U),       /*!< Attach FRO16K to AON LPTMR GRP.*/
    kCLK_16K_to_AON_LPTMR   = CLK_ATTACH_MUX(kCLOKC_SelAonLPTMR, 2U),       /*!< Attach CLK_16K to AON LPTMR GRP.*/

    kFROdiv1_to_AON_TMR     = CLK_ATTACH_MUX(kCLOKC_SelAonTMR, 0U),         /*!< Attach FRO div 1 to AON TMR GRP.*/
    kFROdiv2_to_AON_TMR     = CLK_ATTACH_MUX(kCLOKC_SelAonTMR, 1U),         /*!< Attach FRO div 2 to AON TMR GRP.*/
    kFROdiv4_to_AON_TMR     = CLK_ATTACH_MUX(kCLOKC_SelAonTMR, 2U),         /*!< Attach FRO div 4 to AON TMR GRP.*/
    kROOT_AUX_to_AON_TMR    = CLK_ATTACH_MUX(kCLOKC_SelAonTMR, 3U),         /*!< Attach ROOT AUX to AON TMR GRP. */

    kFROdiv1_to_AON_COM     = CLK_ATTACH_MUX(kCLOKC_SelAonCOM, 0U),         /*!< Attach FRO div 1 to AON COM GRP.*/
    kFROdiv2_to_AON_COM     = CLK_ATTACH_MUX(kCLOKC_SelAonCOM, 1U),         /*!< Attach FRO div 2 to AON COM GRP.*/
    kFROdiv4_to_AON_COM     = CLK_ATTACH_MUX(kCLOKC_SelAonCOM, 2U),         /*!< Attach FRO div 4 to AON COM GRP.*/
    kROOT_AUX_to_AON_COM    = CLK_ATTACH_MUX(kCLOKC_SelAonCOM, 3U),         /*!< Attach ROOT AUX to AON COM GRP. */

#if __CORTEX_M == (33U) /* Building on the main core */
    /* MAIN domain below: */

    kSOSC_to_MAIN_CLK   = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 1U),             /*!< Attach SOSC to MAIN_CLK.   */
    kSIRC_to_MAIN_CLK   = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 2U),             /*!< Attach SIRC to MAIN_CLK.   */
    kFIRC_to_MAIN_CLK   = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 3U),             /*!< Attach FIRC to MAIN_CLK.   */
    kROSC_to_MAIN_CLK   = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 4U),             /*!< Attach ROSC to MAIN_CLK.   */
    kPMUIRC_to_MAIN_CLK = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS, 9U),             /*!< Attach PMUIRC to MAIN_CLK. */
    kLPIRC_to_MAIN_CLK  = CLK_ATTACH_MUX(kCLOCK_SelSCGSCS,10U),             /*!< Attach LPIRC to MAIN_CLK.  */

    kFIRC_to_FRO_HF     = CLK_ATTACH_MUX(kCLOCK_SelFIRC, 0U),               /*!< Attach FIRC to FRO_HF.      */
    kFIRC_DIV_to_FRO_HF = CLK_ATTACH_MUX(kCLOCK_SelFIRC, 1U),               /*!< Attach FIRC_DIV to FRO_HF.  */

    kFRO12M_to_CTIMERg0     = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg0, 0U),       /*!< Attach FRO12M to CTIMER0.     */
    kXTAL32K_to_CTIMERg0    = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg0, 1U),       /*!< Attach XTAL32K to CTIMER0.    */
    kCLK_16K_to_CTIMERg0    = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg0, 2U),       /*!< Attach CLK_16K to CTIMER0.    */
    kFRO_HF_DIV_to_CTIMERg0 = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg0, 3U),       /*!< Attach FRO_HF_DIV to CTIMER0. */

    kFRO12M_to_CTIMERg1     = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg1, 0U),       /*!< Attach FRO12M to CTIMER1,2.     */
    kXTAL32K_to_CTIMERg1    = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg1, 1U),       /*!< Attach XTAL32K to CTIMER1,2.    */
    kCLK_16K_to_CTIMERg1    = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg1, 2U),       /*!< Attach CLK_16K to CTIMER1,2.    */
    kFRO_HF_DIV_to_CTIMERg1 = CLK_ATTACH_MUX(kCLOCK_SelCTIMERg1, 3U),       /*!< Attach FRO_HF_DIV to CTIMER1,2. */

    kFRO12M_to_UTICK0  = CLK_ATTACH_MUX(kCLOCK_SelUTICK0, 0U),              /*!< Attach FRO12M to UTICK0.  */
    kCLK_1M_to_UTICK0  = CLK_ATTACH_MUX(kCLOCK_SelUTICK0, 1U),              /*!< Attach CLK_1M to UTICK0.  */
    kCLK_16K_to_UTICK0 = CLK_ATTACH_MUX(kCLOCK_SelUTICK0, 2U),              /*!< Attach CLK_16K to UTICK0. */

    kCLK_16K_to_OSTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 0U),          /*!< Attach CLK_16K to OSTIMER0. */
    kFRO_16k_to_OSTIMER0 = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 1U),          /*!< Attach FRO_16K to OSTIMER0. */
    kCLK_1M_to_OSTIMER0  = CLK_ATTACH_MUX(kCLOCK_SelOSTIMER0, 2U),          /*!< Attach CLK_1M to OSTIMER0.  */

    kFRO12M_to_ADC0     = CLK_ATTACH_MUX(kCLOCK_SelADC0, 0U),               /*!< Attach FRO12M to ADC0.     */
    kXTAL32K_to_ADC0    = CLK_ATTACH_MUX(kCLOCK_SelADC0, 1U),               /*!< Attach XTAL32K to ADC0.    */
    kFRO_HF_DIV_to_ADC0 = CLK_ATTACH_MUX(kCLOCK_SelADC0, 3U),               /*!< Attach FRO_HF_DIV to ADC0. */

    kFRO12M_to_CMP0     = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 0U),            /*!< Attach FRO12M to CMP0.     */
    kXTAL32K_to_CMP0    = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 1U),            /*!< Attach XTAL32K to CMP0. */
    kFRO_HF_DIV_to_CMP0 = CLK_ATTACH_MUX(kCLOCK_SelCMP0_RR, 3U),            /*!< Attach FRO_HF_DIV to CMP0. */

    kFRO12M_to_CLKOUT     = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 0U),           /*!< Attach FRO12M to CLKOUT.     */
    kSLOW_CLK_to_CLKOUT   = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 1U),           /*!< Attach SLOW_CLK to CLKOUT.   */
    kCLK_16K_to_CLKOUT    = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 3U),           /*!< Attach CLK_16K to CLKOUT.    */
    kFRO_HF_DIV_to_CLKOUT = CLK_ATTACH_MUX(kCLOCK_SelCLKOUT, 7U),           /*!< Attach FRO_HF_DIV to CLKOUT. */

    kFRO12M_to_PERIPH_GROUP0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 0U), /*!< Attach FRO12M to PERIPH_GROUP_0.   */
    kXTAL32K_to_PERIPH_GROUP0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 1U),/*!< Attach XTAL32K to PERIPH_GROUP_0.  */
    kCLK_16K_to_PERIPH_GROUP0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 2U), /*!< Attach kCLK_16K to PERIPH_GROUP_0. */
    kFRO_HF_DIV_to_PERIPH_GROUP0 =
        CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 3U),                        /*!< Attach FRO_HF_DIV to PERIPH_GROUP_0. */

    kFRO12M_to_PERIPH_GROUP1 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 0U), /*!< Attach FRO12M to PERIPH_GROUP_1.   */
    kXTAL32K_to_PERIPH_GROUP1 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 1U),/*!< Attach XTAL32K to PERIPH_GROUP_1.  */
    kCLK_16K_to_PERIPH_GROUP1 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 2U), /*!< Attach kCLK_16K to PERIPH_GROUP_1. */
    kFRO_HF_DIV_to_PERIPH_GROUP1 =
        CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 3U),                        /*!< Attach FRO_HF_DIV to PERIPH_GROUP_1. */

    kFRO12M_to_LPI2C0     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 0U),  /*!< Attach FRO12M to LPI2C0.     */
    kXTAL32K_to_LPI2C0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 1U),  /*!< Attach XTAL32K to LPI2C0.    */
    kCLK_16K_to_LPI2C0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 2U),  /*!< Attach kCLK_16K to LPI2C0.   */
    kFRO_HF_DIV_to_LPI2C0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 3U),  /*!< Attach FRO_HF_DIV to LPI2C0. */

    kFRO12M_to_LPUART0     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 0U), /*!< Attach FRO12M to LPUART0.     */
    kXTAL32K_to_LPUART0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 1U), /*!< Attach XTAL32K to LPUART0.    */
    kCLK_16K_to_LPUART0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 2U), /*!< Attach kCLK_16K to LPUART0.   */
    kFRO_HF_DIV_to_LPUART0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 3U), /*!< Attach FRO_HF_DIV to LPUART0. */

    kFRO12M_to_LPUART1     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 0U), /*!< Attach FRO12M to LPUART1.     */
    kXTAL32K_to_LPUART1    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 1U), /*!< Attach XTAL32K to LPUART1.    */
    kCLK_16K_to_LPUART1    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 2U), /*!< Attach kCLK_16K to LPUART1.   */
    kFRO_HF_DIV_to_LPUART1 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 3U), /*!< Attach FRO_HF_DIV to LPUART1. */

    kFRO12M_to_LPUART2     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 0U), /*!< Attach FRO12M to LPUART2.     */
    kXTAL32K_to_LPUART2    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 1U), /*!< Attach XTAL32K to LPUART2.    */
    kCLK_16K_to_LPUART2    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 2U), /*!< Attach kCLK_16K to LPUART2.   */
    kFRO_HF_DIV_to_LPUART2 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 3U), /*!< Attach FRO_HF_DIV to LPUART2. */

    kFRO12M_to_LPSPI0     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 0U),  /*!< Attach FRO12M to LPSPI0.     */
    kXTAL32K_to_LPSPI0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 1U),  /*!< Attach XTAL32K to LPSPI0.    */
    kCLK_16K_to_LPSPI0    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 2U),  /*!< Attach kCLK_16K to LPSPI0.   */
    kFRO_HF_DIV_to_LPSPI0 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP0, 3U),  /*!< Attach FRO_HF_DIV to LPSPI0. */

    kFRO12M_to_LPSPI1     = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 0U),  /*!< Attach FRO12M to LPSPI1.     */
    kXTAL32K_to_LPSPI1    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 1U),  /*!< Attach XTAL32K to LPSPI1.    */
    kCLK_16K_to_LPSPI1    = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 2U),  /*!< Attach kCLK_16K to LPSPI1.   */
    kFRO_HF_DIV_to_LPSPI1 = CLK_ATTACH_MUX(kCLOCK_SelPERIPH_GROUP1, 3U),  /*!< Attach FRO_HF_DIV to LPSPI1. */

    kCPU_CLK_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 0U),          /*!< Attach CPU_CLK to SYSTICK.  */
    kCLK_1M_to_SYSTICK  = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 1U),          /*!< Attach CLK_1M to SYSTICK.   */
    kCLK_16K_to_SYSTICK = CLK_ATTACH_MUX(kCLOCK_SelSYSTICK, 2U),          /*!< Attach kCLK_16K to SYSTICK. */
#endif

    kNONE_to_NONE = (0xFFFFFFFFU),                                        /*!< Attach NONE to NONE. */

} clock_attach_id_t;

/*! @brief Clock dividers */
typedef enum _clock_div_name
{
#if __CORTEX_M == (33U) /* Building on the main core */
    kCLOCK_DivCTIMER0      = (0x0A4U), /*!< CTIMER0    clock divider */
    kCLOCK_DivCTIMER1      = (0x0ACU), /*!< CTIMER1    clock divider */
    kCLOCK_DivWWDT0        = (0x0BCU), /*!< WWDT0      clock divider */
    kCLOCK_DivADC0         = (0x0C4U), /*!< ADC0       clock divider */
    kCLOCK_DivCMP0_FUNC    = (0x0CCU), /*!< CMP0_FUNC  clock divider */
    kCLOCK_DivCMP0_RR      = (0x0D4U), /*!< CMP0_RR    clock divider */
    kCLOCK_DivTRACE        = (0x0DCU), /*!< DBG_TRACE  clock divider */
    kCLOCK_DivCLKOUT       = (0x0E4U), /*!< CLKOUT     clock divider */
    kCLOCK_DivPeriphGroup0 = (0x0F4U), /*!< PeriphGroup0 clock divider*/
    kCLOCK_DivLPI2C0       = (0x0F4U), /*!< LPI2C0      clock divider */
    kCLOCK_DivLPSPI0       = (0x0F4U), /*!< LPSPI0      clock divider*/
    kCLOCK_DivLPUART0      = (0x0F4U), /*!< LPUART0     clock divider*/
    kCLOCK_DivPeriphGroup1 = (0x0FCU), /*!< PeriphGroup1 clock divider*/
    kCLOCK_DivLPSPI1       = (0x0FCU), /*!< LPSPI1      clock divider */
    kCLOCK_DivLPUART1      = (0x0FCU), /*!< LPUART1     clock divider*/
    kCLOCK_DivLPUART2      = (0x0FCU), /*!< LPUART2     clock divider*/
    kCLOCK_DivSYSTICK      = (0x104U), /*!< SYSTICK    clock divider */
    kCLOCK_DivFRO_HF_DIV   = (0x10CU), /*!< FRO_HF_DIV clock divider */
    kCLOCK_DivAHBAIPSCLK   = (0x378U), /*!< AHB2AIPS   clock divider */
    kCLOCK_DivAHBCLK       = (0x380U), /*!< System     clock divider */
#endif
    kCLOCK_DIVAonCPU       = (0x400U), /*!< Aon CPU    clock divider */
    kCLOCK_DIVAonCMP       = (0x401U), /*!< Aon Comp grp clock divider */
    kCLOCK_DIVAonSYS       = (0x402U), /*!< Aon SYSTICK clock divider */
    kCLOCK_DIVAonCMP0CLK0  = (0x410U), /*!< Aon CMP0 CLK0 clock divider */
    kCLOCK_DIVAonCMP0CLK1  = (0x411U), /*!< Aon CMP0 CLK1 clock divider */
    kCLOCK_DivMax          = (0x411U), /*!< MAX        clock divider */
} clock_div_name_t;

#if __CORTEX_M == (33U) /* Building on the main core */
/*!
 * @brief firc trim mode.
 */
typedef enum _firc_trim_mode
{
    kSCG_FircTrimNonUpdate = SCG_FIRCCSR_FIRCTREN_MASK,
    /*!< Trim enable but not enable trim value update. In this mode, the
     trim value is fixed to the initialized value which is defined by
     trimCoar and trimFine in configure structure \ref firc_trim_config_t.*/

    kSCG_FircTrimUpdate = SCG_FIRCCSR_FIRCTREN_MASK | SCG_FIRCCSR_FIRCTRUP_MASK
    /*!< Trim enable and trim value update enable. In this mode, the trim
     value is auto update. */

} firc_trim_mode_t;

/*!
 * @brief firc trim source.
 */
typedef enum _firc_trim_src
{
    kSCG_FircTrimSrcRtcOsc = SCG_FIRCTCFG_TRIMSRC_MASK, /*!< RTC OSC (32.768 kHz)    */
} firc_trim_src_t;

/*!
 * @brief firc trim configuration.
 */
typedef struct _firc_trim_config
{
    firc_trim_mode_t trimMode; /*!< Trim mode.   */
    firc_trim_src_t trimSrc;   /*!< Trim source. */

    uint8_t trimCoar;          /*!< Trim coarse value; Irrelevant if trimMode is kSCG_TrimUpdate. */
    uint8_t trimFine;          /*!< Trim fine value; Irrelevant if trimMode is kSCG_TrimUpdate. */
} firc_trim_config_t;

/*!
 * @brief sirc trim mode.
 */
typedef enum _sirc_trim_mode
{
    kSCG_SircTrimNonUpdate = SCG_SIRCCSR_SIRCTREN_MASK,
    /*!< Trim enable but not enable trim value update. In this mode, the
     trim value is fixed to the initialized value which is defined by
     trimCoar and trimFine in configure structure \ref sirc_trim_config_t.*/

    kSCG_SircTrimUpdate = SCG_SIRCCSR_SIRCTREN_MASK | SCG_SIRCCSR_SIRCTRUP_MASK
    /*!< Trim enable and trim value update enable. In this mode, the trim
     value is auto update. */

} sirc_trim_mode_t;

/*!
 * @brief sirc trim source.
 */
typedef enum _sirc_trim_src
{
    kNoTrimSrc             = 0U,                        /*!< No external tirm source. */
    kSCG_SircTrimSrcRtcOsc = SCG_SIRCTCFG_TRIMSRC_MASK, /*!< RTC OSC (32.768 kHz)     */
} sirc_trim_src_t;

/*!
 * @brief sirc trim configuration.
 */
typedef struct _sirc_trim_config
{
    sirc_trim_mode_t trimMode; /*!< Trim mode.   */
    sirc_trim_src_t trimSrc;   /*!< Trim source. */

    uint8_t cltrim;            /*!< Trim coarse value; Irrelevant if trimMode is kSCG_TrimUpdate. */
    uint8_t ccotrim;           /*!< Trim fine value; Irrelevant if trimMode is kSCG_TrimUpdate. */
} sirc_trim_config_t;

/*!
 * @brief SCG ROSC monitor mode.
 */
typedef enum _scg_rosc_monitor_mode
{
    kSCG_RoscMonitorDisable = 0U,                           /*!< Monitor disabled. */
    kSCG_RoscMonitorInt     = SCG_ROSCCSR_ROSCCM_MASK,      /*!< Interrupt when the RTC OSC error is detected. */
    kSCG_RoscMonitorReset =
        SCG_ROSCCSR_ROSCCM_MASK | SCG_ROSCCSR_ROSCCMRE_MASK /*!< Reset when the RTC OSC error is detected. */
} scg_rosc_monitor_mode_t;

/*!
 * @brief SCG ROSC configuration.
 */
typedef struct _scg_rosc_config
{
    scg_rosc_monitor_mode_t monitorMode; /*!< Clock monitor mode selected.     */
} scg_rosc_config_t;

#endif /* Building on the main core */

/*!
 * @brief AON FRO trim configuration.
 */
typedef struct _aon_fro_trim_config
{
    uint8_t fs_bp;       /*!< Replica voltage fs_bp. 0-7 */
    uint8_t fs_vcco;     /*!< Replica voltage fs_vcco. 0-3 */
    uint8_t tf;          /*!< Relationship between the frequency and temperature. 0-7 */

    uint8_t cltrim;      /*!< Trim coarse freq value; 0-63 */
    uint8_t ccotrim;     /*!< Trim fine freq value; 0-63 */
} aon_fro_trim_config_t;

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
    const uint32_t bit_shift = CLK_PERIPHERAL_BIT_SHIFT(clk);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }
 
#if __CORTEX_M == (33U) /* Building on the main core */
    if (clk == kCLOCK_InputMux) /* Workaround for inputmux driver */
    {
        CLOCK_EnableClock(kCLOCK_GateAonINPUTMUX1);
        CLOCK_EnableClock(kCLOCK_GateINPUTMUX0);
        return;
    }
#endif    

    if (CLK_OF_AON(clk))
    {
        if(clk == kCLOCK_GateAonINPUTMUX1) 
        {
            AON__SYSCON_AON->PINMUXCLKCTRL = SYSCON_AON_PINMUXCLKCTRL_PINMUX_CLK_CTRL(0);
        }
        else
        {
            AON__CGU->PER_CLK_EN |= (1UL << bit_shift);
        }
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        uint32_t reg_cc_offset               = CLK_GATE_REG_CC_OFFSET(clk);
        uint32_t reg_pr_offset               = CLK_GATE_REG_PR_OFFSET(clk);

        volatile uint32_t *pClkCtrl          = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_CCSET0)) + reg_cc_offset);
        volatile uint32_t *pPeripheralEnCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_PR0)) + reg_pr_offset);

        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        if (clk != kCLOCK_InputMux && clk != kCLOCK_GateWWDT0 && clk != kCLOCK_GateSRAMA0A1 && clk != kCLOCK_GateROMCP )
        {
            *pPeripheralEnCtrl |= (1UL << bit_shift);
        }

        if (reg_cc_offset == REG_PWM0SUBCTL)
        {
            SYSCON->PWM0SUBCTL |= (1UL << bit_shift);
            //MRCC->MRCC_GLB_PR0 |= MRCC_MRCC_GLB_PR0_FLEXPWM0_MASK;
            //MRCC->MRCC_GLB_CCSET0 = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK; FIXME
        }
        else
        {
            *pClkCtrl = (1UL << bit_shift);
        }

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
    }

#endif /* Building on the main core */
}

/**
 * @brief Disable the clock for specific IP.
 * @param clk : Clock to be Disabled.
 * @return  Nothing
 */
static inline void CLOCK_DisableClock(clock_ip_name_t clk)
{
    const uint32_t bit_shift = CLK_PERIPHERAL_BIT_SHIFT(clk);

    if (clk == kCLOCK_GateNotAvail)
    {
        return;
    }

    if (CLK_OF_AON(clk))
    {
        AON__CGU->PER_CLK_EN &= ~(1UL << bit_shift);
    }
#if __CORTEX_M == (33U) /* Building on the main core */
    else
    {
        uint32_t reg_cc_offset               = CLK_GATE_REG_CC_OFFSET(clk);
        uint32_t reg_pr_offset               = CLK_GATE_REG_PR_OFFSET(clk);

        volatile uint32_t *pClkCtrl          = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_CCCLR0)) + reg_cc_offset);
        volatile uint32_t *pPeripheralEnCtrl = (volatile uint32_t *)((uint32_t)(&(MRCC->GLB_PR0)) + reg_pr_offset);

        /* Unlock clock configuration */
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        if (reg_cc_offset == REG_PWM0SUBCTL)
        {
            SYSCON->PWM0SUBCTL &= ~(1UL << bit_shift);

            /*if (0U == (SYSCON->PWM0SUBCTL & 0xFU))
            {
                MRCC->MRCC_GLB_CCCLR0 = MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK;
                MRCC->MRCC_GLB_PR0 &= ~(MRCC_MRCC_GLB_PR0_FLEXPWM0_MASK);
            }FIXME */
        }
        else
        {
            *pClkCtrl = (1UL << bit_shift);
        }

        if (clk != kCLOCK_InputMux && clk != kCLOCK_GateWWDT0 && clk != kCLOCK_GateSRAMA0A1 && clk != kCLOCK_GateROMCP)
        {
            *pPeripheralEnCtrl &= ~(1UL << bit_shift);
        }
        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;
    }
#endif /* Building on the main core */
}

/**
 * @brief   Configure the clock selection muxes.
 * @param   connection  : Clock to be configured.
 * @return  Nothing
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
 * @param   sel_name  : Clock select.
 * @param   value     : value to be set.
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
 * @param   div_name    : Clock divider name
 * @param   value       : Value to be divided
 * @return  Nothing
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
 * @return  Nothing
 */
void CLOCK_HaltClockDiv(clock_div_name_t div_name);

/**
 * @brief   Initialize the AON FRO to given frequency..
 * @param   iFreq   : Desired frequency (10M,2M,0=off).
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROAonClocking(uint32_t iFreq);

#if __CORTEX_M == (33U) /* Building on the main core */
/**
 * @brief   Initialize the FROHF to given frequency.
 * This function turns on FIRC and select the given frequency
 * by-2-divider or by-4-divider as the source of fro_hf.
 * @param   iFreq   : Desired frequency.
 * @param   div_sel : Divider value to be Selected.
 *             0b0  : FIRC clock selected .
 *             0b1  : FIRC 2-divider clock selected.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFROHFClocking(uint32_t iFreq, uint8_t div_sel);

/**
 * @brief   Initialize the FRO12M.
 * This function turns on FRO12M.
 * @return  returns success or fail status.
 */
status_t CLOCK_SetupFRO12MClocking(void);

/*!
 * brief Initializes the SCG ROSC.
 *
 * This function enables the SCG ROSC clock according to the
 * configuration.
 *
 * param config   Pointer to the configuration structure.
 * retval kStatus_Success ROSC is initialized.
 * retval kStatus_SCG_Busy ROSC has been enabled and is used by the system clock.
 * retval kStatus_ReadOnly ROSC control register is locked.
 *
 * note This function can't detect whether the system OSC has been enabled and
 * used by an IP.
 */
status_t CLOCK_InitRosc(const scg_rosc_config_t *config);

/*!
 * brief De-initializes the SCG ROSC.
 *
 * This function disables the SCG ROSC clock.
 *
 * retval kStatus_Success System OSC is deinitialized.
 * retval kStatus_SCG_Busy System OSC is used by the system clock.
 * retval kStatus_ReadOnly System OSC control register is locked.
 *
 * note This function can't detect whether the ROSC is used by an IP.
 */
status_t CLOCK_DeinitRosc(void);

#endif /* Building on the main core */

/*! @brief  Return Frequency of selected clock
 *  @return Frequency of selected clock
 */
uint32_t CLOCK_GetFreq(clock_name_t clockName);

#if __CORTEX_M == (33U) /* Building on the main core */
/*! @brief  Return Frequency of core
 *  @return Frequency of the core
 */
uint32_t CLOCK_GetCoreSysClkFreq(void);

/*! brief  Return Frequency of flash clock
 *  return Frequency of flash 12M clock
 */
uint32_t CLOCK_GetFlashClkFreq(void);

/*! @brief  Return Frequency of CTimer functional Clock
 *  @return Frequency of CTimer functional Clock
 */
uint32_t CLOCK_GetCTimerClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPSPI functional Clock
 *  @return Frequency of LPSPI functional Clock
 */
uint32_t CLOCK_GetLpspiClkFreq(uint32_t id);
#endif /* Building on the main core */

/*! @brief  Return Frequency of LPI2C functional Clock
 *  @return Frequency of LPI2C functional Clock
 */
uint32_t CLOCK_GetLpi2cClkFreq(uint32_t id);

/*! @brief  Return Frequency of LPUART functional Clock
 *  @return Frequency of LPUART functional Clock
 */
uint32_t CLOCK_GetLpuartClkFreq(uint32_t id);

#if __CORTEX_M == (33U) /* Building on the main core */
/*!
 *  @brief  Return Frequency of UTICK0 functional Clock
 *  @return Frequency of UTICK0 functional Clock
 */
uint32_t CLOCK_GetUtickClkFreq(void);

/*!
 *  @brief  Return Frequency of WWDT0 functional Clock
 *  @return Frequency of WWDT0 functional Clock
 */
uint32_t CLOCK_GetWwdtClkFreq(void);

/*!
 *  @brief  Return Frequency of LPTMR functional Clock
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
uint32_t CLOCK_GetAdcClkFreq(void);

/*! @brief  Return Frequency of CMP Function Clock
 *  @return Frequency of CMP Function.
 */
uint32_t CLOCK_GetCmpFClkFreq(void);

/*! @brief  Return Frequency of CMP Round Robin Clock
 *  @return Frequency of CMP Round Robin.
 */
uint32_t CLOCK_GetCmpRRClkFreq(void);

/*! @brief  Return Frequency of Trace Clock
 *  @return Frequency of Trace.
 */
uint32_t CLOCK_GetTraceClkFreq(void);

/*! @brief  Return Frequency of CLKOUT Clock
 *  @return Frequency of CLKOUT.
 */
uint32_t CLOCK_GetClkoutClkFreq(void);

/*! @brief  Return Frequency of Periph Group functional Clock
 *  @return Frequency of Periph Group functional Clock
 */
uint32_t CLOCK_GetPeriphGroupClkFreq(uint32_t id);

/*! @brief  Return Frequency of Systick Clock
 *  @return Frequency of Systick.
 */
uint32_t CLOCK_GetSystickClkFreq(void);

/**
 * @brief   Setup FROHF trim.
 * @param   config   : FROHF trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FROHFTrimConfig(firc_trim_config_t config);

/**
 * @brief   Setup FRO 12M trim.
 * @param   config   : FRO 12M trim value
 * @return  returns success or fail status.
 */
status_t CLOCK_FRO12MTrimConfig(sirc_trim_config_t config);

#endif /* Building on the main core */

/**
 * @brief   Sets AON FRO 10M or 2M trim.
 * @param   is_fro2m : 0 for FRO10M, 1 for FRO2M
 * @param   config   : trim value
 */
void CLOCK_AON_FRO_Trim_Set(uint8_t is_fro2m, aon_fro_trim_config_t config);

/**
 * @brief   Reads AON FRO 10M or 2M trim values.
 * @param   is_fro2m : 0 for FRO10M, 1 for FRO2M
 * @param   config   : ptr to aon_fro_trim_config_t struct.
 */
void CLOCK_AON_FRO_Trim_Get(uint8_t is_fro2m, aon_fro_trim_config_t * config);

#if __CORTEX_M == (33U) /* Building on the main core */

/*!
 * @brief Sets the ROSC monitor mode.
 *
 * This function sets the ROSC monitor mode. The mode can be disabled,
 * it can generate an interrupt when the error is disabled, or reset when the error is detected.
 *
 * @param mode Monitor mode to set.
 */
void CLOCK_SetRoscMonitorMode(scg_rosc_monitor_mode_t mode);

/*! @brief Enable the clock for OSTIMER.
 */
void CLOCK_EnableOstimer32kClock(void);

/*!
 * @brief Checks whether the ROSC clock is valid.
 *
 * @return  True if clock is valid, false if not.
 */
static inline bool CLOCK_IsRoscValid(void)
{
    return (bool)(SCG0->ROSCCSR & SCG_ROSCCSR_ROSCVLD_MASK);
}

/*!
 * @brief Unlock the ROSCCSR control status register.
 */
static inline void CLOCK_UnlockRoscControlStatusReg(void)
{
    SCG0->ROSCCSR &= ~(SCG_ROSCCSR_LK_MASK);
}

/*!
 * @brief Lock the ROSCCSR control status register.
 */
static inline void CLOCK_LockRoscControlStatusReg(void)
{
    SCG0->ROSCCSR |= SCG_ROSCCSR_LK_MASK;
}

#endif /* Building on the main core */

/*!
 * @brief Sets the XTAL32 frequency based on board settings.
 *
 * @param freq The XTAL32/EXTAL32 input clock frequency in Hz.
 */
static inline void CLOCK_SetXtal32Freq(uint32_t freq)
{
    g_xtal32Freq = freq;
}


#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_CLOCK_H_ */

