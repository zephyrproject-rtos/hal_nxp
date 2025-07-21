/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CLOCK_H_
#define FSL_CLOCK_H_

#include "fsl_common.h"

/*! @addtogroup clock */
/*! @{ */

/*! @file */

/*******************************************************************************
 * Definitions
 *****************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief CLOCK driver version 2.1.0 */
#define FSL_CLOCK_DRIVER_VERSION (MAKE_VERSION(2, 1, 0))
/*@}*/

/* Definition for delay API in clock driver, users can redefine it to the real
 * application. */
#ifndef SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY
#define SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY (160000000UL)
#endif /* SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY */

#ifndef CLOCK_FIRC_CLK_FREQ
#define CLOCK_FIRC_CLK_FREQ (48000000U)
#endif

#ifndef CLOCK_SIRC_CLK_FREQ
#define CLOCK_SIRC_CLK_FREQ (32000U)
#endif
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
#ifndef CLOCK_SXOSC_CLK_FREQ
#define CLOCK_SXOSC_CLK_FREQ (32768U)
#endif /* CLOCK_SXOSC_CLK_FREQ */
#endif /* FSL_FEATURE_MC_CGM_HAS_SXOSC */

/*! @brief driver feature definition */
#if defined(QUADSPI)
#define FSL_FEATURE_CLOCK_HAS_QSPI (1U)
#endif
#if defined(EMAC)
#define FSL_FEATURE_CLOCK_HAS_EMAC (1U)
#endif

/*! @brief External XTAL0 (FXOSC) clock frequency.
 *
 * The XTAL0/EXTAL0 (FXOSC) clock frequency in Hz. When the clock is set up, use the
 * function CLOCK_InitFxosc to set the value in the clock driver. For example,
 * if XTAL0 is 8 MHz:
 * @code
 * Set up the FXOSC
 * CLOCK_InitFxosc(...);
 * @endcode
 *
 */
extern volatile uint32_t g_xtal0Freq;

/******************************************************************************
 * MC_MCG clock sources mapping
 *******************************************************************************/
#define CLOCK_FIRC_CLK  0U         /*!< FIRC clock*/
#define CLOCK_SIRC_CLK  1U         /*!< SIRC clock*/
#define CLOCK_FXOSC_CLK 2U         /*!< FXOSC clock*/
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
#define CLOCK_SXOSC_CLK 4U         /*!< SXOSC clock*/
#endif
#define CLOCK_PLL_PHI0_CLK  8U     /*!< PLL PHI0 clock*/
#define CLOCK_PLL_PHI1_CLK  9U     /*!< PLL PHI1 clock*/
#define CLOCK_CORE_CLK      16U    /*!< M7 core clock*/
#define CLOCK_HSE_CLK       19U    /*!< HSE clock*/
#define CLOCK_AIPS_PLAT_CLK 22U    /*!< SRAM/AXBS clock*/
#define CLOCK_AIPS_SLOW_CLK 23U    /*!< peripheral clock*/
#if defined(FSL_FEATURE_CLOCK_HAS_EMAC) && (FSL_FEATURE_CLOCK_HAS_EMAC != 0U)
#define CLOCK_EMAC_RMII_TX_CLK 24U /*!< Ethernet MAC RMII transmit clock*/
#define CLOCK_EMAC_RX_CLK      25U /*!< Ethernet MAC Receive clock*/
#endif                             /* FSL_FEATURE_CLOCK_HAS_EMAC */
#define CLOCK_CLKOUT_RUN_CLK 50U   /*!< Clock output in RUN mode*/

/*! @brief Clock ip name array for TEMPSENSE. */
#define TEMPSENSOR_CLOCKS \
    {                     \
        kCLOCK_TempSensor \
    }

/*! @brief Clock ip name array for BCTU. */
#define BCTU_CLOCKS \
    {               \
        kCLOCK_Bctu \
    }

/*! @brief Clock ip name array for ADC. */
#if defined(FSL_FEATURE_SOC_ADC_COUNT) && (FSL_FEATURE_SOC_ADC_COUNT > 2U)
#define ADC_CLOCKS                            \
    {                                         \
        kCLOCK_Adc0, kCLOCK_Adc1, kCLOCK_Adc2 \
    }
#else
#define ADC_CLOCKS               \
    {                            \
        kCLOCK_Adc0, kCLOCK_Adc1 \
    }
#endif /* FSL_FEATURE_SOC_ADC_COUNT */

/*! @brief Clock ip name array for DMAMUX. */
#define DMAMUX_CLOCKS                  \
    {                                  \
        kCLOCK_Dmamux0, kCLOCK_Dmamux1 \
    }

/*! @brief Clock ip name array for EDMA. */
#define EDMA_CLOCKS \
    {               \
        kCLOCK_Edma \
    }

/*! @brief Clock ip name array for EIM. */
#define EIM_CLOCKS \
    {              \
        kCLOCK_Eim \
    }

/*! @brief Clock ip name array for EMIOS. */
#if defined(FSL_FEATURE_SOC_EMIOS_COUNT) && (FSL_FEATURE_SOC_EMIOS_COUNT > 2U)
#define EMIOS_CLOCKS                                \
    {                                               \
        kCLOCK_Emios0, kCLOCK_Emios1, kCLOCK_Emios2 \
    }
#else
#define EMIOS_CLOCKS                 \
    {                                \
        kCLOCK_Emios0, kCLOCK_Emios1 \
    }
#endif

/*! @brief Clock ip name array for ERM. */
#define ERM_CLOCKS \
    {              \
        kCLOCK_Erm \
    }

#if defined(FSL_FEATURE_SOC_FLEXCAN_COUNT) && (FSL_FEATURE_SOC_FLEXCAN_COUNT == 6U)
/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                                                                                        \
    {                                                                                                         \
        kCLOCK_Flexcan0, kCLOCK_Flexcan1, kCLOCK_Flexcan2, kCLOCK_Flexcan3, kCLOCK_Flexcan4, kCLOCK_Flexcan5, \
    }
#else
/*! @brief Clock ip name array for FLEXCAN. */
#define FLEXCAN_CLOCKS                                    \
    {                                                     \
        kCLOCK_Flexcan0, kCLOCK_Flexcan1, kCLOCK_Flexcan2 \
    }
#endif /* FSL_FEATURE_SOC_FLEXCAN_COUNT */

/*! @brief Clock ip name array for FLEXIO. */
#define FLEXIO_CLOCKS \
    {                 \
        kCLOCK_Flexio \
    }

#if defined(FSL_FEATURE_SOC_QuadSPI_COUNT) && (FSL_FEATURE_SOC_QuadSPI_COUNT != 0U)
/*! @brief Clock ip name array for QSPI. */
#define QSPI_CLOCKS \
    {               \
        kCLOCK_Qspi \
    }
#endif /* FSL_FEATURE_SOC_QuadSPI_COUNT */

/*! @brief Clock ip name array for LCU. */
#define LCU_CLOCKS               \
    {                            \
        kCLOCK_Lcu0, kCLOCK_Lcu1 \
    }

/*! @brief Clock ip name array for LPCMP. */
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT == 3U)
#define LPCMP_CLOCKS                                 \
    {                                                \
        kCLOCK_Lpcmp0, kCLOCK_Lpcmp1, kCLOCK_Lpcmp2, \
    }
#elif defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT == 2U)
#define LPCMP_CLOCKS                 \
    {                                \
        kCLOCK_Lpcmp0, kCLOCK_Lpcmp1 \
    }
#else
#define LPCMP_CLOCKS  \
    {                 \
        kCLOCK_Lpcmp0 \
    }
#endif /* FSL_FEATURE_SOC_LPCMP_COUNT */

/*! @brief Clock ip name array for LPI2C. */
#define LPI2C_CLOCKS                 \
    {                                \
        kCLOCK_Lpi2c0, kCLOCK_Lpi2c1 \
    }

#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT == 16U)
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                         \
    {                                                                                                         \
        kCLOCK_Lpuart0, kCLOCK_Lpuart1, kCLOCK_Lpuart2, kCLOCK_Lpuart3, kCLOCK_Lpuart4, kCLOCK_Lpuart5,       \
            kCLOCK_Lpuart6, kCLOCK_Lpuart7, kCLOCK_Lpuart8, kCLOCK_Lpuart9, kCLOCK_Lpuart10, kCLOCK_Lpuart11, \
            kCLOCK_Lpuart12, kCLOCK_Lpuart13, kCLOCK_Lpuart14, kCLOCK_Lpuart15                                \
    }
#elif (FSL_FEATURE_SOC_LPUART_COUNT == 8U)
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                                                   \
    {                                                                                                   \
        kCLOCK_Lpuart0, kCLOCK_Lpuart1, kCLOCK_Lpuart2, kCLOCK_Lpuart3, kCLOCK_Lpuart4, kCLOCK_Lpuart5, \
            kCLOCK_Lpuart6, kCLOCK_Lpuart7                                                              \
    }
#else
/*! @brief Clock ip name array for LPUART. */
#define LPUART_CLOCKS                                                  \
    {                                                                  \
        kCLOCK_Lpuart0, kCLOCK_Lpuart1, kCLOCK_Lpuart2, kCLOCK_Lpuart3 \
    }
#endif
#if defined(FSL_FEATURE_SOC_LPSPI_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT == 6U)
/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                                                             \
    {                                                                                            \
        kCLOCK_Lpspi0, kCLOCK_Lpspi1, kCLOCK_Lpspi2, kCLOCK_Lpspi3, kCLOCK_Lpspi4, kCLOCK_Lpspi5 \
    }
#else
/*! @brief Clock ip name array for LPSPI. */
#define LPSPI_CLOCKS                                               \
    {                                                              \
        kCLOCK_Lpspi0, kCLOCK_Lpspi1, kCLOCK_Lpspi2, kCLOCK_Lpspi3 \
    }
#endif

#if defined(FSL_FEATURE_SOC_PIT_COUNT) && (FSL_FEATURE_SOC_PIT_COUNT == 3U)
/*! @brief Clock ip name array for PIT. */
#define PIT_CLOCKS                            \
    {                                         \
        kCLOCK_Pit0, kCLOCK_Pit1, kCLOCK_Pit2 \
    }
#else
/*! @brief Clock ip name array for PIT. */
#define PIT_CLOCKS               \
    {                            \
        kCLOCK_Pit0, kCLOCK_Pit1 \
    }
#endif

#if defined(FSL_FEATURE_SOC_I2S_COUNT) && (FSL_FEATURE_SOC_I2S_COUNT == 2U)
/*! @brief Clock ip name array for SAI. */
#define SAI_CLOCKS               \
    {                            \
        kCLOCK_Sai0, kCLOCK_Sai1 \
    }
#endif /* FSL_FEATURE_SOC_I2S_COUNT */

#if defined(FSL_FEATURE_SOC_SEMA42_COUNT) && (FSL_FEATURE_SOC_SEMA42_COUNT != 0U)
/*! @brief Clock ip name array for SEMA42. */
#define SEMA42_CLOCKS \
    {                 \
        kCLOCK_Sema42 \
    }
#endif /* FSL_FEATURE_SOC_SEMA42_COUNT */

/*! @brief Clock ip name array for STM. */
#if defined(FSL_FEATURE_SOC_STM_COUNT) && (FSL_FEATURE_SOC_STM_COUNT == 2U)
#define STM_CLOCKS               \
    {                            \
        kCLOCK_Stm0, kCLOCK_Stm1 \
    }
#else
#define STM_CLOCKS  \
    {               \
        kCLOCK_Stm0 \
    }
#endif /* FSL_FEATURE_SOC_STM_COUNT */

/*! @brief Clock ip name array for SWT. */
#define SWT_CLOCKS   \
    {                \
        kCLOCK_Swt0, \
    }

/*! @brief Clock ip name array for TSPC. */
#define TSPC_CLOCKS  \
    {                \
        kCLOCK_Tspc, \
    }

#define MC_ME_TUPLE_PRTN_MASK  (0x0FFF0000U)
#define MC_ME_TUPLE_PRTN_SHIFT (16U)
#define MC_ME_TUPLE_BIT_MASK   (0x1FU)
/*! Help macro, bit16 to bit 28 is COFB register offset, bit0 to bit4 is bitfield. */
#define MC_ME_COFB_TUPLE(reg, bit)   (((reg) << MC_ME_TUPLE_PRTN_SHIFT) | (bit))
#define MC_ME_COFB_STAT_CLKEN_OFFSET (0x20U)
#define MC_ME_COFB_OFFSET(tuple)     (((tuple)&MC_ME_TUPLE_PRTN_MASK) >> MC_ME_TUPLE_PRTN_SHIFT)
#define MC_ME_PRTN_PCONF_REG(tuple) \
    (*((volatile uint32_t *)(((uint32_t)MC_ME + MC_ME_COFB_OFFSET(tuple)) & 0xFFFFFF00U)))
#define MC_ME_PRTN_PUPD_REG(tuple) \
    (*((volatile uint32_t *)((((uint32_t)MC_ME + MC_ME_COFB_OFFSET(tuple)) & 0xFFFFFF00U) + 4U)))
#define MC_ME_COFB_CLKEN_REG(tuple) (*((volatile uint32_t *)((uint32_t)MC_ME + MC_ME_COFB_OFFSET(tuple))))
#define MC_ME_COFB_STAT_REG(tuple) \
    (*((volatile uint32_t *)((uint32_t)MC_ME + MC_ME_COFB_OFFSET(tuple) - MC_ME_COFB_STAT_CLKEN_OFFSET)))
#define MC_ME_COFB_CLKEN_BIT(tuple) ((tuple)&MC_ME_TUPLE_BIT_MASK)

/*! @brief Clock gate name used for CLOCK_EnableClock/CLOCK_DisableClock. */
typedef enum _clock_ip_name
{
    kCLOCK_IpInvalid = 0U, /*!< Invalid Ip Name. */

    /* PRTN0_COFB1_CLKEN Bit Fields */
    kCLOCK_Trgmux = MC_ME_COFB_TUPLE(0x134U, 0), /*!< Trigger Multiplexing Control (PRTN0_COFB1) */
    kCLOCK_Bctu   = MC_ME_COFB_TUPLE(0x134U, 1), /*!< Body Cross Triggering Unit (PRTN0_COFB1) */
    kCLOCK_Emios0 = MC_ME_COFB_TUPLE(0x134U, 2), /*!< EMIOS 0 (PRTN0_COFB1) */
    kCLOCK_Emios1 = MC_ME_COFB_TUPLE(0x134U, 3), /*!< EMIOS 1 (PRTN0_COFB1) */
#if defined(FSL_FEATURE_SOC_EMIOS_COUNT) && (FSL_FEATURE_SOC_EMIOS_COUNT > 2U)
    kCLOCK_Emios2 = MC_ME_COFB_TUPLE(0x134U, 4), /*!< EMIOS 2 (PRTN0_COFB1) */
#endif                                           /* FSL_FEATURE_SOC_EMIOS_COUNT */
    kCLOCK_Lcu0 = MC_ME_COFB_TUPLE(0x134U, 6),   /*!< Logic Control Unit 0 (PRTN0_COFB1) */
    kCLOCK_Lcu1 = MC_ME_COFB_TUPLE(0x134U, 7),   /*!< Logic Control Unit 1 (PRTN0_COFB1) */
    kCLOCK_Adc0 = MC_ME_COFB_TUPLE(0x134U, 8),   /*!< Analog-to-digital converter 0 (PRTN0_COFB1) */
    kCLOCK_Adc1 = MC_ME_COFB_TUPLE(0x134U, 9),   /*!< Analog-to-digital converter 1 (PRTN0_COFB1) */
#if defined(FSL_FEATURE_SOC_ADC_COUNT) && (FSL_FEATURE_SOC_ADC_COUNT > 2U)
    kCLOCK_Adc2 = MC_ME_COFB_TUPLE(0x134U, 10),  /*!< Analog-to-digital converter 2 (PRTN0_COFB1) */
#endif                                           /* FSL_FEATURE_SOC_ADC_COUNT */
    kCLOCK_Pit0 = MC_ME_COFB_TUPLE(0x134U, 12),  /*!< Programmable Interrupt Timer 0 (PRTN0_COFB1) */
    kCLOCK_Pit1 = MC_ME_COFB_TUPLE(0x134U, 13),  /*!< Programmable Interrupt Timer 1 (PRTN0_COFB1) */
    /* PRTN1_COFB0_CLKEN Bit Fields */
    kCLOCK_Edma  = MC_ME_COFB_TUPLE(0x330U, 3),  /*!< EDMA control & status (MP_CSR; MP_ES; MP_HRS) (PRTN1_COFB0) */
    kCLOCK_Tcd0  = MC_ME_COFB_TUPLE(0x330U, 4),  /*!< EDMA transfer control descriptor 0 (PRTN1_COFB0) */
    kCLOCK_Tcd1  = MC_ME_COFB_TUPLE(0x330U, 5),  /*!< EDMA transfer control descriptor 1 (PRTN1_COFB0) */
    kCLOCK_Tcd2  = MC_ME_COFB_TUPLE(0x330U, 6),  /*!< EDMA transfer control descriptor 2 (PRTN1_COFB0) */
    kCLOCK_Tcd3  = MC_ME_COFB_TUPLE(0x330U, 7),  /*!< EDMA transfer control descriptor 3 (PRTN1_COFB0) */
    kCLOCK_Tcd4  = MC_ME_COFB_TUPLE(0x330U, 8),  /*!< EDMA transfer control descriptor 4 (PRTN1_COFB0) */
    kCLOCK_Tcd5  = MC_ME_COFB_TUPLE(0x330U, 9),  /*!< EDMA transfer control descriptor 5 (PRTN1_COFB0) */
    kCLOCK_Tcd6  = MC_ME_COFB_TUPLE(0x330U, 10), /*!< EDMA transfer control descriptor 6 (PRTN1_COFB0) */
    kCLOCK_Tcd7  = MC_ME_COFB_TUPLE(0x330U, 11), /*!< EDMA transfer control descriptor 7 (PRTN1_COFB0) */
    kCLOCK_Tcd8  = MC_ME_COFB_TUPLE(0x330U, 12), /*!< EDMA transfer control descriptor 8 (PRTN1_COFB0) */
    kCLOCK_Tcd9  = MC_ME_COFB_TUPLE(0x330U, 13), /*!< EDMA transfer control descriptor 9 (PRTN1_COFB0) */
    kCLOCK_Tcd10 = MC_ME_COFB_TUPLE(0x330U, 14), /*!< EDMA transfer control descriptor 10 (PRTN1_COFB0) */
    kCLOCK_Tcd11 = MC_ME_COFB_TUPLE(0x330U, 15), /*!< EDMA transfer control descriptor 11 (PRTN1_COFB0) */
    kCLOCK_Sda   = MC_ME_COFB_TUPLE(0x330U, 21), /*!< SDA-AP (PRTN1_COFB0) */
    kCLOCK_Eim   = MC_ME_COFB_TUPLE(0x330U, 22), /*!< EIM (PRTN1_COFB0) */
    kCLOCK_Erm   = MC_ME_COFB_TUPLE(0x330U, 23), /*!< ERM (PRTN1_COFB0) */
    kCLOCK_Mscm  = MC_ME_COFB_TUPLE(0x330U, 24), /*!< MSCM (PRTN1_COFB0) */
    kCLOCK_Swt0  = MC_ME_COFB_TUPLE(0x330U, 28), /*!< Software Watchdog 0 (PRTN1_COFB0) */
    kCLOCK_Stm0  = MC_ME_COFB_TUPLE(0x330U, 29), /*!< System Timer Module 0 (PRTN1_COFB0) */
    kCLOCK_Intm  = MC_ME_COFB_TUPLE(0x330U, 31), /*!< Interrupt Monitor (PRTN1_COFB0) */
    /* PRTN1_COFB1_CLKEN Bit Fields */
    kCLOCK_Dmamux0 = MC_ME_COFB_TUPLE(0x334U, 0),  /*!< DMA Channel Multiplexer 0 (PRTN1_COFB1) */
    kCLOCK_Dmamux1 = MC_ME_COFB_TUPLE(0x334U, 1),  /*!< DMA Channel Multiplexer 1 (PRTN1_COFB1) */
    kCLOCK_Rtc     = MC_ME_COFB_TUPLE(0x334U, 2),  /*!< Real-time clock (PRTN1_COFB1) */
    kCLOCK_Vwrap   = MC_ME_COFB_TUPLE(0x334U, 10), /*!< SIUL2_VIRTWRAPPER (PRTN1_COFB1) */
    kCLOCK_Wkup    = MC_ME_COFB_TUPLE(0x334U, 13), /*!< Wakeup Unit (PRTN1_COFB1) */
    kCLOCK_Cmu05   = MC_ME_COFB_TUPLE(0x334U, 15), /*!< CMU 0-5 (PRTN1_COFB1) */
    kCLOCK_Tspc    = MC_ME_COFB_TUPLE(0x334U, 17), /*!< Touch Sensing Coupling Controller (PRTN1_COFB1) */
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
    kCLOCK_Sxosc = MC_ME_COFB_TUPLE(0x334U, 19U),  /*!< 32 kHz Slow External Crystal Oscillator (PRTN1_COFB1) */
#endif                                             /* FSL_FEATURE_MC_CGM_HAS_SXOSC */
    kCLOCK_Fxosc = MC_ME_COFB_TUPLE(0x334U, 21U),  /*!< 8-40 MHz Fast External Crystal Oscillator (PRTN1_COFB1) */
    kCLOCK_Pll   = MC_ME_COFB_TUPLE(0x334U, 24U),  /*!< Frequency Modulated Phase-Locked Loop (PRTN1_COFB1) */
#if defined(FSL_FEATURE_SOC_PIT_COUNT) && (FSL_FEATURE_SOC_PIT_COUNT > 2U)
    kCLOCK_Pit2 = MC_ME_COFB_TUPLE(0x334U, 31U),   /*!< Programmable Interrupt Timer 2 (PRTN1_COFB1) */
#endif                                             /* FSL_FEATURE_SOC_PIT_COUNT */
    /* PRTN1_COFB2_CLKEN Bit Fields */
    kCLOCK_Flexcan0 = MC_ME_COFB_TUPLE(0x338U, 1),    /*!< FlexCAN 0 (PRTN1_COFB2) */
    kCLOCK_Flexcan1 = MC_ME_COFB_TUPLE(0x338U, 2),    /*!< FlexCAN 1 (PRTN1_COFB2) */
    kCLOCK_Flexcan2 = MC_ME_COFB_TUPLE(0x338U, 3),    /*!< FlexCAN 2 (PRTN1_COFB2) */
#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_4) && (FSL_FEATURE_MC_CGM_HAS_MUX_4 != 0U)
    kCLOCK_Flexcan3 = MC_ME_COFB_TUPLE(0x338U, 4),    /*!< FlexCAN 3 (PRTN1_COFB2) */
    kCLOCK_Flexcan4 = MC_ME_COFB_TUPLE(0x338U, 5),    /*!< FlexCAN 4 (PRTN1_COFB2) */
    kCLOCK_Flexcan5 = MC_ME_COFB_TUPLE(0x338U, 6),    /*!< FlexCAN 5 (PRTN1_COFB2) */
#endif                                                /* FSL_FEATURE_MC_CGM_HAS_MUX_4 */
    kCLOCK_Flexio  = MC_ME_COFB_TUPLE(0x338U, 9),     /*!< Flexible IO (PRTN1_COFB2) */
    kCLOCK_Lpuart0 = MC_ME_COFB_TUPLE(0x338U, 10U),   /*!< Low Power UART 0 (PRTN1_COFB2) */
    kCLOCK_Lpuart1 = MC_ME_COFB_TUPLE(0x338U, 11U),   /*!< Low Power UART 1 (PRTN1_COFB2) */
    kCLOCK_Lpuart2 = MC_ME_COFB_TUPLE(0x338U, 12U),   /*!< Low Power UART 2 (PRTN1_COFB2) */
    kCLOCK_Lpuart3 = MC_ME_COFB_TUPLE(0x338U, 13U),   /*!< Low Power UART 3 (PRTN1_COFB2) */
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 4U)
    kCLOCK_Lpuart4 = MC_ME_COFB_TUPLE(0x338U, 14U),   /*!< Low Power UART 4 (PRTN1_COFB2) */
    kCLOCK_Lpuart5 = MC_ME_COFB_TUPLE(0x338U, 15U),   /*!< Low Power UART 5 (PRTN1_COFB2) */
    kCLOCK_Lpuart6 = MC_ME_COFB_TUPLE(0x338U, 16U),   /*!< Low Power UART 6 (PRTN1_COFB2) */
    kCLOCK_Lpuart7 = MC_ME_COFB_TUPLE(0x338U, 17U),   /*!< Low Power UART 7 (PRTN1_COFB2) */
#endif
    kCLOCK_Lpi2c0 = MC_ME_COFB_TUPLE(0x338U, 20U),    /*!< Low Power I2C 0 (PRTN1_COFB2) */
    kCLOCK_Lpi2c1 = MC_ME_COFB_TUPLE(0x338U, 21U),    /*!< Low Power I2C 1 (PRTN1_COFB2) */
    kCLOCK_Lpspi0 = MC_ME_COFB_TUPLE(0x338U, 22U),    /*!< Low Power SPI 0 (PRTN1_COFB2) */
    kCLOCK_Lpspi1 = MC_ME_COFB_TUPLE(0x338U, 23U),    /*!< Low Power SPI 1 (PRTN1_COFB2) */
    kCLOCK_Lpspi2 = MC_ME_COFB_TUPLE(0x338U, 24U),    /*!< Low Power SPI 2 (PRTN1_COFB2) */
    kCLOCK_Lpspi3 = MC_ME_COFB_TUPLE(0x338U, 25U),    /*!< Low Power SPI 3 (PRTN1_COFB2) */
#if defined(FSL_FEATURE_SOC_I2S_COUNT)
    kCLOCK_Sai0 = MC_ME_COFB_TUPLE(0x338U, 27),       /*!< Synchronous Audio Interface 0 (PRTN1_COFB2) */
#endif
    kCLOCK_Lpcmp0 = MC_ME_COFB_TUPLE(0x338U, 28),     /*!< Low Power CMP 0 (PRTN1_COFB2) */
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT > 1U)
    kCLOCK_Lpcmp1 = MC_ME_COFB_TUPLE(0x338U, 29),     /*!< Low Power CMP 1 (PRTN1_COFB2) */
#endif                                                /* FSL_FEATURE_SOC_LPCMP_COUNT */
    kCLOCK_TempSensor = MC_ME_COFB_TUPLE(0x338U, 31), /*!< TMU Temperature Sensor Unit (PRTN1_COFB2) */
    /* PRTN1_COFB3_CLKEN Bit Fields */
    kCLOCK_Crc0 = MC_ME_COFB_TUPLE(0x33CU, 0), /*!< CRC (PRTN1_COFB3) */
#if defined(FSL_FEATURE_MC_ME_HAS_PRTN2) && (FSL_FEATURE_MC_ME_HAS_PRTN2 != 0U)
    /* PRTN2_COFB0_CLKEN Bit Fields */
    kCLOCK_Tcd12  = MC_ME_COFB_TUPLE(0x530U, 4),  /*!< EDMA transfer control descriptor 12 (PRTN2_COFB0) */
    kCLOCK_Tcd13  = MC_ME_COFB_TUPLE(0x530U, 5),  /*!< EDMA transfer control descriptor 13 (PRTN2_COFB0) */
    kCLOCK_Tcd14  = MC_ME_COFB_TUPLE(0x530U, 6),  /*!< EDMA transfer control descriptor 14 (PRTN2_COFB0) */
    kCLOCK_Tcd15  = MC_ME_COFB_TUPLE(0x530U, 7),  /*!< EDMA transfer control descriptor 15 (PRTN2_COFB0) */
    kCLOCK_Tcd16  = MC_ME_COFB_TUPLE(0x530U, 8),  /*!< EDMA transfer control descriptor 16 (PRTN2_COFB0) */
    kCLOCK_Tcd17  = MC_ME_COFB_TUPLE(0x530U, 9),  /*!< EDMA transfer control descriptor 17 (PRTN2_COFB0) */
    kCLOCK_Tcd18  = MC_ME_COFB_TUPLE(0x530U, 10), /*!< EDMA transfer control descriptor 18 (PRTN2_COFB0) */
    kCLOCK_Tcd19  = MC_ME_COFB_TUPLE(0x530U, 11), /*!< EDMA transfer control descriptor 19 (PRTN2_COFB0) */
    kCLOCK_Tcd20  = MC_ME_COFB_TUPLE(0x530U, 12), /*!< EDMA transfer control descriptor 20 (PRTN2_COFB0) */
    kCLOCK_Tcd21  = MC_ME_COFB_TUPLE(0x530U, 13), /*!< EDMA transfer control descriptor 21 (PRTN2_COFB0) */
    kCLOCK_Tcd22  = MC_ME_COFB_TUPLE(0x530U, 14), /*!< EDMA transfer control descriptor 22 (PRTN2_COFB0) */
    kCLOCK_Tcd23  = MC_ME_COFB_TUPLE(0x530U, 15), /*!< EDMA transfer control descriptor 23 (PRTN2_COFB0) */
    kCLOCK_Tcd24  = MC_ME_COFB_TUPLE(0x530U, 16), /*!< EDMA transfer control descriptor 24 (PRTN2_COFB0) */
    kCLOCK_Tcd25  = MC_ME_COFB_TUPLE(0x530U, 17), /*!< EDMA transfer control descriptor 25 (PRTN2_COFB0) */
    kCLOCK_Tcd26  = MC_ME_COFB_TUPLE(0x530U, 18), /*!< EDMA transfer control descriptor 26 (PRTN2_COFB0) */
    kCLOCK_Tcd27  = MC_ME_COFB_TUPLE(0x530U, 19), /*!< EDMA transfer control descriptor 27 (PRTN2_COFB0) */
    kCLOCK_Tcd28  = MC_ME_COFB_TUPLE(0x530U, 20), /*!< EDMA transfer control descriptor 28 (PRTN2_COFB0) */
    kCLOCK_Tcd29  = MC_ME_COFB_TUPLE(0x530U, 21), /*!< EDMA transfer control descriptor 29 (PRTN2_COFB0) */
    kCLOCK_Tcd30  = MC_ME_COFB_TUPLE(0x530U, 22), /*!< EDMA transfer control descriptor 30 (PRTN2_COFB0) */
    kCLOCK_Tcd31  = MC_ME_COFB_TUPLE(0x530U, 23), /*!< EDMA transfer control descriptor 31 (PRTN2_COFB0) */
    kCLOCK_Sema42 = MC_ME_COFB_TUPLE(0x530U, 24), /*!< Semaphores2 (PRTN2_COFB0) */
    kCLOCK_Stm1   = MC_ME_COFB_TUPLE(0x530U, 29), /*!< System Timer Module 1 (PRTN2_COFB0) */
    /* PRTN2_COFB1_CLKEN Bit Fields */
    kCLOCK_Enet     = MC_ME_COFB_TUPLE(0x534U, 0),   /*!< ENET (PRTN2_COFB1) */
    kCLOCK_Lpuart8  = MC_ME_COFB_TUPLE(0x534U, 3U),  /*!< Low Power UART 8 (PRTN2_COFB1). */
    kCLOCK_Lpuart9  = MC_ME_COFB_TUPLE(0x534U, 4U),  /*!< Low Power UART 9 (PRTN2_COFB1). */
    kCLOCK_Lpuart10 = MC_ME_COFB_TUPLE(0x534U, 5U),  /*!< Low Power UART 10 (PRTN2_COFB1). */
    kCLOCK_Lpuart11 = MC_ME_COFB_TUPLE(0x534U, 6U),  /*!< Low Power UART 11 (PRTN2_COFB1). */
    kCLOCK_Lpuart12 = MC_ME_COFB_TUPLE(0x534U, 7U),  /*!< Low Power UART 12 (PRTN2_COFB1). */
    kCLOCK_Lpuart13 = MC_ME_COFB_TUPLE(0x534U, 8U),  /*!< Low Power UART 13 (PRTN2_COFB1). */
    kCLOCK_Lpuart14 = MC_ME_COFB_TUPLE(0x534U, 9U),  /*!< Low Power UART 14 (PRTN2_COFB1). */
    kCLOCK_Lpuart15 = MC_ME_COFB_TUPLE(0x534U, 10U), /*!< Low Power UART 15 (PRTN2_COFB1). */
    kCLOCK_Lpspi4   = MC_ME_COFB_TUPLE(0x534U, 15U), /*!< Low Power SPI 4 (PRTN2_COFB1). */
    kCLOCK_Lpspi5   = MC_ME_COFB_TUPLE(0x534U, 16U), /*!< Low Power SPI 5 (PRTN2_COFB1). */
    kCLOCK_Qspi     = MC_ME_COFB_TUPLE(0x534U, 19),  /*!< QuadSPI (PRTN2_COFB1) */
    kCLOCK_Sai1     = MC_ME_COFB_TUPLE(0x534U, 23),  /*!< Synchronous Audio Interface 1 (PRTN2_COFB1) */
    kCLOCK_Lpcmp2   = MC_ME_COFB_TUPLE(0x534U, 26),  /*!< Low Power CMP 2 (PRTN2_COFB1) */
    kCLOCK_Tcm0     = MC_ME_COFB_TUPLE(0x534U, 30),  /*!< Core0 TCM (PRTN2_COFB1) */
    kCLOCK_Tcm1     = MC_ME_COFB_TUPLE(0x534U, 31),  /*!< Core1 TCM (PRTN2_COFB1) */
#endif                                               /* FSL_FEATURE_MC_ME_HAS_PRTN2 */
} clock_ip_name_t;

#define CLOCK_DIV_TUPLE(mux, dc) ((mux << 8U) | dc)
#define CLOCK_TUPLE_DIV_DC_REG(tuple)                                                                \
    (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_DC_0)) + ((tuple & 0xFF00U) >> 8U) * 0x40U + \
                             (tuple & 0xFF) * 4U)))
#define CLOCK_TUPLE_DIV_UPD_STAT_REG(tuple) \
    (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_DIV_UPD_STAT)) + ((tuple & 0xFF00U) >> 8U) * 0x40U)))

/* clock mux, dc0-6 */
/*! @brief Clock dividers */
typedef enum _clock_div_name
{
    kCLOCK_DivCoreClk     = CLOCK_DIV_TUPLE(0U, 0U),      /*!< CLOCK MUX0, divider control 0. */
    kCLOCK_DivAipsPlatClk = CLOCK_DIV_TUPLE(0U, 1U),      /*!< CLOCK MUX0, divider control 1. */
    kCLOCK_DivAipsSlowClk = CLOCK_DIV_TUPLE(0U, 2U),      /*!< CLOCK MUX0, divider control 2. */
    kCLOCK_DivHseClk      = CLOCK_DIV_TUPLE(0U, 3U),      /*!< CLOCK MUX0, divider control 3. */
    kCLOCK_DivDcmClk      = CLOCK_DIV_TUPLE(0U, 4U),      /*!< CLOCK MUX0, divider control 4. */
#if defined(FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV) && (FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV != 0U)
    kCLOCK_DivLbistClk = CLOCK_DIV_TUPLE(0U, 5U),         /*!< CLOCK MUX0, divider control 5. */
#endif                                                    /* FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV */
#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
    kCLOCK_DivQspiClk = CLOCK_DIV_TUPLE(0U, 6U),          /*!< CLOCK MUX0, divider control 6. */
#endif                                                    /* FSL_FEATURE_CLOCK_HAS_QSPI */
    kCLOCK_DivStm0Clk = CLOCK_DIV_TUPLE(1U, 0U),          /*!< CLOCK MUX1, divider control 0. */
#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_2) && (FSL_FEATURE_MC_CGM_HAS_MUX_2 != 0U)
    kCLOCK_DivStm1Clk = CLOCK_DIV_TUPLE(2U, 0U),          /*!< CLOCK MUX2, divider control 0. */
#endif                                                    /* FSL_FEATURE_MC_CGM_HAS_MUX_2 */
    kCLOCK_DivFlexcan012PeClk = CLOCK_DIV_TUPLE(3U, 0U),  /*!< CLOCK MUX3, divider control 0. */
#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_4) && (FSL_FEATURE_MC_CGM_HAS_MUX_4 != 0U)
    kCLOCK_DivFlexcan345PeClk = CLOCK_DIV_TUPLE(4U, 0U),  /*!< CLOCK MUX4, divider control 0. */
#endif                                                    /* FSL_FEATURE_MC_CGM_HAS_MUX_4 */
    kCLOCK_DivClkoutStandbyClk = CLOCK_DIV_TUPLE(5U, 0U), /*!< CLOCK MUX5, divider control 0. */
    kCLOCK_DivClkoutRunClk     = CLOCK_DIV_TUPLE(6U, 0U), /*!< CLOCK MUX6, divider control 0. */
#if defined(FSL_FEATURE_CLOCK_HAS_EMAC) && (FSL_FEATURE_CLOCK_HAS_EMAC != 0U)
    kCLOCK_DivEmacRxClk = CLOCK_DIV_TUPLE(7U, 0U),        /*!< CLOCK MUX7, divider control 0. */
    kCLOCK_DivEmacTxClk = CLOCK_DIV_TUPLE(8U, 0U),        /*!< CLOCK MUX8, divider control 0. */
    kCLOCK_DivEmacTsClk = CLOCK_DIV_TUPLE(9U, 0U),        /*!< CLOCK MUX9, divider control 0. */
#endif                                                    /* FSL_FEATURE_CLOCK_HAS_EMAC */
#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
    kCLOCK_DivQspiSfckClk = CLOCK_DIV_TUPLE(10U, 0U),     /*!< CLOCK MUX10, divider control 0. */
#endif                                                    /* FSL_FEATURE_CLOCK_HAS_QSPI */
    kCLOCK_DivTraceClk = CLOCK_DIV_TUPLE(11U, 0U),        /*!< CLOCK MUX11, divider control 0. */
} clock_div_name_t;

#define CLOCK_TUPLE_MUX_CSC_REG(tuple) \
    (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_CSC)) + ((tuple & 0xFF00U) >> 8U) * 0x40U)))
#define CLOCK_TUPLE_MUX_CSS_REG(tuple) \
    (*((volatile uint32_t *)((uint32_t)(&(MC_CGM->MUX_0_CSS)) + ((tuple & 0xFF00U) >> 8U) * 0x40U)))

/*!
 * @brief The enumerator of clock attach Id.
 */
typedef enum _clock_attach_id
{
    kFIRC_CLK_to_MUX0 = CLOCK_DIV_TUPLE(0U, CLOCK_FIRC_CLK),   /*!< Select FIRC as CLOCK MUX0 clock source. */
    kPLL_PHI0_CLK_to_MUX0 =
        CLOCK_DIV_TUPLE(0U, CLOCK_PLL_PHI0_CLK),               /*!< Select PLL_PHI0_CLK as CLOCK MUX0 clock source. */

    kFIRC_CLK_to_STM0  = CLOCK_DIV_TUPLE(1U, CLOCK_FIRC_CLK),  /*!< Select FIRC as STM0 clock source. */
    kFXOSC_CLK_to_STM0 = CLOCK_DIV_TUPLE(1U, CLOCK_FXOSC_CLK), /*!< Select FXOSC as STM0 clock source. */
    kAIPS_PLAT_CLK_to_STM0 =
        CLOCK_DIV_TUPLE(1U, CLOCK_AIPS_PLAT_CLK),              /*!< Select AIPS_PLAT_CLK as STM0 clock source. */

#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_2) && (FSL_FEATURE_MC_CGM_HAS_MUX_2 != 0U)
    kFIRC_CLK_to_STM1  = CLOCK_DIV_TUPLE(2U, CLOCK_FIRC_CLK),  /*!< Select FIRC as STM1 clock source. */
    kFXOSC_CLK_to_STM1 = CLOCK_DIV_TUPLE(2U, CLOCK_FXOSC_CLK), /*!< Select FXOSC as STM1 clock source. */
    kAIPS_PLAT_CLK_to_STM1 =
        CLOCK_DIV_TUPLE(2U, CLOCK_AIPS_PLAT_CLK),              /*!< Select AIPS_PLAT_CLK as STM1 clock source. */
#endif                                                         /* FSL_FEATURE_MC_CGM_HAS_MUX_2 */

    kFIRC_CLK_to_FLEXCAN012_PE =
        CLOCK_DIV_TUPLE(3U, CLOCK_FIRC_CLK),      /*!< Select FIRC as FLEXCAN0,1,2_PE clock source. */
    kFXOSC_CLK_to_FLEXCAN012_PE =
        CLOCK_DIV_TUPLE(3U, CLOCK_FXOSC_CLK),     /*!< Select FXOSC as FLEXCAN0,1,2_PE clock source. */
    kAIPS_PLAT_CLK_to_FLEXCAN012_PE =
        CLOCK_DIV_TUPLE(3U, CLOCK_AIPS_PLAT_CLK), /*!< Select AIPS_PLAT_CLK as FLEXCAN0,1,2_PE clock source. */

#if defined(FSL_FEATURE_MC_CGM_HAS_MUX_4) && (FSL_FEATURE_MC_CGM_HAS_MUX_4 != 0U)
    kFIRC_CLK_to_FLEXCAN345_PE =
        CLOCK_DIV_TUPLE(4U, CLOCK_FIRC_CLK),      /*!< Select FIRC as FLEXCAN3,4,5_PE clock source. */
    kFXOSC_CLK_to_FLEXCAN345_PE =
        CLOCK_DIV_TUPLE(4U, CLOCK_FXOSC_CLK),     /*!< Select FXOSC as FLEXCAN3,4,5_PE clock source. */
    kAIPS_PLAT_CLK_to_FLEXCAN345_PE =
        CLOCK_DIV_TUPLE(4U, CLOCK_AIPS_PLAT_CLK), /*!< Select AIPS_PLAT_CLK as FLEXCAN3,4,5_PE clock source. */
#endif                                            /* FSL_FEATURE_MC_CGM_HAS_MUX_4 */

    kFIRC_CLK_to_CLKOUT_STANDBY =
        CLOCK_DIV_TUPLE(5U, CLOCK_FIRC_CLK),  /*!< Select FIRC as CLKOUT_STANDBY mode clock source. */
    kSIRC_CLK_to_CLKOUT_STANDBY =
        CLOCK_DIV_TUPLE(5U, CLOCK_SIRC_CLK),  /*!< Select SIRC as CLKOUT_STANDBY mode clock source. */
    kFXOSC_CLK_to_CLKOUT_STANDBY =
        CLOCK_DIV_TUPLE(5U, CLOCK_FXOSC_CLK), /*!< Select FXOSC as CLKOUT_STANDBY mode clock source. */
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
    kSXOSC_CLK_to_CLKOUT_STANDBY =
        CLOCK_DIV_TUPLE(5U, CLOCK_SXOSC_CLK),     /*!< Select SXOSC as CLKOUT_STANDBY mode clock source. */
#endif                                            /* FSL_FEATURE_MC_CGM_HAS_SXOSC */
    kAIPS_SLOW_CLK_to_CLKOUT_STANDBY =
        CLOCK_DIV_TUPLE(5U, CLOCK_AIPS_SLOW_CLK), /*!< Select AIPS_SLOW_CLK as CLKOUT_STANDBY mode clock source. */

    kFIRC_CLK_to_CLKOUT_RUN = CLOCK_DIV_TUPLE(6U, CLOCK_FIRC_CLK), /*!< Select FIRC as CLKOUT_RUN mode clock source. */
    kSIRC_CLK_to_CLKOUT_RUN = CLOCK_DIV_TUPLE(6U, CLOCK_SIRC_CLK), /*!< Select SIRC as CLKOUT_RUN mode clock source. */
    kFXOSC_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_FXOSC_CLK),                      /*!< Select FXOSC as CLKOUT_RUN mode clock source. */
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
    kSXOSC_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_SXOSC_CLK),    /*!< Select SXOSC as CLKOUT_RUN mode clock source. */
#endif                                           /* FSL_FEATURE_MC_CGM_HAS_SXOSC */
    kPLL_PHI0_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_PLL_PHI0_CLK), /*!< Select PLL_PHI0_CLK as CLKOUT_RUN mode clock source. */
    kPLL_PHI1_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_PLL_PHI1_CLK), /*!< Select PLL_PHI1_CLK as CLKOUT_RUN mode clock source. */
    kCORE_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_CORE_CLK),     /*!< Select CORE_CLK as CLKOUT_RUN mode clock source. */
    kHSE_CLK_to_CLKOUT_RUN = CLOCK_DIV_TUPLE(6U, CLOCK_HSE_CLK), /*!< Select HSE_CLK as CLKOUT_RUN mode clock source. */
    kAIPS_PLAT_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_AIPS_PLAT_CLK), /*!< Select AIPS_PLAT as CLKOUT_RUN mode clock source. */
    kAIPS_SLOW_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_AIPS_SLOW_CLK), /*!< Select AIPS_SLOW as CLKOUT_RUN mode clock source. */
#if defined(FSL_FEATURE_CLOCK_HAS_EMAC) && (FSL_FEATURE_CLOCK_HAS_EMAC != 0U)
    kEMAC_RMII_TX_CLK_to_CLKOUT_RUN = CLOCK_DIV_TUPLE(
        6U, CLOCK_EMAC_RMII_TX_CLK),            /*!< Select EMAC_RMII_TX_CLK(pin) as CLKOUT_RUN mode clock source. */
    kEMAC_RX_CLK_to_CLKOUT_RUN =
        CLOCK_DIV_TUPLE(6U, CLOCK_EMAC_RX_CLK), /*!< Select EMAC_RX_CLK(pin) as CLKOUT_RUN mode clock source. */

    kFIRC_CLK_to_EMAC_RX = CLOCK_DIV_TUPLE(7U, CLOCK_FIRC_CLK), /*!< Select FIRC as EMAC_RX_CLK clock source. */
    kEMAC_RMII_TX_CLK_to_EMAC_RX =
        CLOCK_DIV_TUPLE(7U, CLOCK_EMAC_RMII_TX_CLK), /*!< Select EMAC_RMII_TX_CLK(pin) as EMAC_RX_CLK  clock source. */
    kEMAC_RX_CLK_to_EMAC_RX =
        CLOCK_DIV_TUPLE(7U, CLOCK_EMAC_RX_CLK),      /*!< Select EMAC_RX_CLK(pin) as EMAC_RX_CLK clock source. */

    kFIRC_CLK_to_EMAC_TX = CLOCK_DIV_TUPLE(8U, CLOCK_FIRC_CLK), /*!< Select FIRC as EMAC_TX_CLK clock source. */
    kEMAC_RMII_TX_CLK_to_EMAC_TX =
        CLOCK_DIV_TUPLE(8U, CLOCK_EMAC_RMII_TX_CLK), /*!< Select EMAC_RMII_TX_CLK(pin) as EMAC_TX_CLK  clock source. */

    kFIRC_CLK_to_EMAC_TS = CLOCK_DIV_TUPLE(9U, CLOCK_FIRC_CLK), /*!< Select FIRC as EMAC_TS_CLK clock source. */
    kEMAC_RMII_TX_CLK_to_EMAC_TS =
        CLOCK_DIV_TUPLE(9U, CLOCK_EMAC_RMII_TX_CLK), /*!< Select EMAC_RMII_TX_CLK(pin) as EMAC_TS_CLK  clock source. */
    kEMAC_RX_CLK_to_EMAC_TS =
        CLOCK_DIV_TUPLE(9U, CLOCK_EMAC_RX_CLK),      /*!< Select EMAC_RX_CLK(pin) as EMAC_TS_CLK clock source. */
#endif                                               /* FSL_FEATURE_CLOCK_HAS_EMAC */

#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
    kFIRC_CLK_to_QSPI_SFCK  = CLOCK_DIV_TUPLE(10U, CLOCK_FIRC_CLK),  /*!< Select FIRC as QSPI_SFCK clock source. */
    kFXOSC_CLK_to_QSPI_SFCK = CLOCK_DIV_TUPLE(10U, CLOCK_FXOSC_CLK), /*!< Select FXOSC as QSPI_SFCK clock source. */
    kPLL_PHI0_CLK_to_QSPI_SFCK =
        CLOCK_DIV_TUPLE(10U, CLOCK_PLL_PHI0_CLK),     /*!< Select PLL_PHI0_CLK as QSPI_SFCK clock source. */
    kPLL_PHI1_CLK_to_QSPI_SFCK =
        CLOCK_DIV_TUPLE(10U, CLOCK_PLL_PHI1_CLK),     /*!< Select PLL_PHI1_CLK as QSPI_SFCK clock source. */
    kEMAC_RMII_TX_CLK_to_QSPI_SFCK =
        CLOCK_DIV_TUPLE(10U, CLOCK_EMAC_RMII_TX_CLK), /*!< Select EMAC_RMII_TX_CLK(pin) as QSPI_SFCKe clock source. */
    kEMAC_RX_CLK_to_QSPI_SFCK =
        CLOCK_DIV_TUPLE(10U, CLOCK_EMAC_RX_CLK),      /*!< Select EMAC_RX_CLK(pin) as QSPI_SFCK clock source. */
#endif                                                /* FSL_FEATURE_CLOCK_HAS_QSPI */

    kFIRC_CLK_to_TRACE  = CLOCK_DIV_TUPLE(11U, CLOCK_FIRC_CLK),  /*!< Select FIRC as TRACE clock source. */
    kFXOSC_CLK_to_TRACE = CLOCK_DIV_TUPLE(11U, CLOCK_FXOSC_CLK), /*!< Select FXOSC as TRACE clock source. */
    kPLL_PHI0_CLK_to_TRACE =
        CLOCK_DIV_TUPLE(11U, CLOCK_PLL_PHI0_CLK),                /*!< Select PLL_PHI0_CLK as TRACE clock source. */
    kPLL_PHI1_CLK_to_TRACE =
        CLOCK_DIV_TUPLE(11U, CLOCK_PLL_PHI1_CLK),                /*!< Select PLL_PHI1_CLK as TRACE clock source. */

} clock_attach_id_t;

/*!
 * @brief Clock name.
 */
typedef enum _clock_name
{
    /* --------------------- System layer clock --------------------- */
    kCLOCK_CoreSysClk,  /*!< Core clock.   */
    kCLOCK_AipsPlatClk, /*!< AIPS_PLAT clock. */
    kCLOCK_AipsSlowClk, /*!< AIPS_SLOW clock. */
    kCLOCK_HseClk,      /*!< HSE clock. */
    kCLOCK_DcmClk,      /*!< DCM clock. */
#if defined(FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV) && (FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV != 0U)
    kCLOCK_LbistClk,    /*!< LBIST clock. */
#endif                  /* FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV */
#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
    kCLOCK_QspiClk,     /*!< QSPI clock. */
#endif                  /* FSL_FEATURE_CLOCK_HAS_QSPI */

    /* --------------------- MC_CGM clock --------------------- */
    kCLOCK_FircClk,    /*!< Firc clock. */
    kCLOCK_SircClk,    /*!< SIRC clock. */
    kCLOCK_FxoscClk,   /*!< FXOSC clock. */
#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
    kCLOCK_SxoscClk,   /*!< SXOSC clock. */
#endif                 /* FSL_FEATURE_MC_CGM_HAS_SXOSC */
    kCLOCK_PllPhi0Clk, /*!< PLL_PHI0_CLK clock. */
    kCLOCK_PllPhi1Clk, /*!< PLL_PHI0_CLK clock. */

    /* --------------------- Peripheral clock --------------------- */
    kCLOCK_Adc0Clk,     /*!< ADC0 clock. */
    kCLOCK_Adc1Clk,     /*!< ADC1 clock. */
#if defined(FSL_FEATURE_SOC_ADC_COUNT) && (FSL_FEATURE_SOC_ADC_COUNT > 2U)
    kCLOCK_Adc2Clk,     /*!< ADC2 clock. */
#endif                  /* FSL_FEATURE_SOC_ADC_COUNT */
    kCLOCK_BctuClk,     /*!< Bctu clock. */
    kCLOCK_Cmp0Clk,     /*!< CMP0 clock. */
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT > 1U)
    kCLOCK_Cmp1Clk,     /*!< CMP1 clock. */
#endif                  /* FSL_FEATURE_SOC_LPCMP_COUNT */
#if defined(FSL_FEATURE_SOC_LPCMP_COUNT) && (FSL_FEATURE_SOC_LPCMP_COUNT > 2U)
    kCLOCK_Cmp2Clk,     /*!< CMP2 clock. */
#endif                  /* FSL_FEATURE_SOC_LPCMP_COUNT */
    kCLOCK_EmiosClk,    /*!< EMIOS clock. */
    kCLOCK_Flexcan0Clk, /*!< FLEXCAN0/1/2_PE clock. */
    kCLOCK_Flexcan1Clk, /*!< FLEXCAN0/1/2_PE clock. */
    kCLOCK_Flexcan2Clk, /*!< FLEXCAN0/1/2_PE clock. */
#if defined(FSL_FEATURE_SOC_FLEXCAN_COUNT) && (FSL_FEATURE_SOC_FLEXCAN_COUNT > 3U)
    kCLOCK_Flexcan3Clk, /*!< FLEXCAN3/4/5_PE clock. */
    kCLOCK_Flexcan4Clk, /*!< FLEXCAN3/4/5_PE clock. */
    kCLOCK_Flexcan5Clk, /*!< FLEXCAN3/4/5_PE clock. */
#endif                  /* FSL_FEATURE_SOC_FLEXCAN_COUNT */
    kCLOCK_FlexioClk,   /*!< FLEXIO clock. */

    kCLOCK_Lpi2c0Clk,   /*!< LPI2C0 clock. */
    kCLOCK_Lpi2c1Clk,   /*!< LPI2C0 clock. */

    kCLOCK_Lpspi0Clk,   /*!< LPSPI0 clock. */
    kCLOCK_Lpspi1Clk,   /*!< LPSPI1 clock. */
    kCLOCK_Lpspi2Clk,   /*!< LPSPI2 clock. */
    kCLOCK_Lpspi3Clk,   /*!< LPSPI3 clock. */
#if defined(FSL_FEATURE_SOC_LPSPI_COUNT) && (FSL_FEATURE_SOC_LPSPI_COUNT > 4U)
    kCLOCK_Lpspi4Clk,   /*!< LPSPI4 clock. */
    kCLOCK_Lpspi5Clk,   /*!< LPSPI5 clock. */
#endif                  /* FSL_FEATURE_SOC_LPSPI_COUNT */

    kCLOCK_Lpuart0Clk,  /*!< LPUART0 clock. */
    kCLOCK_Lpuart1Clk,  /*!< LPUART1 clock. */
    kCLOCK_Lpuart2Clk,  /*!< LPUART2 clock. */
    kCLOCK_Lpuart3Clk,  /*!< LPUART3 clock. */
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 4U)
    kCLOCK_Lpuart4Clk,  /*!< LPUART4 clock. */
    kCLOCK_Lpuart5Clk,  /*!< LPUART5 clock. */
    kCLOCK_Lpuart6Clk,  /*!< LPUART6 clock. */
    kCLOCK_Lpuart7Clk,  /*!< LPUART7 clock. */
#endif                  /* FSL_FEATURE_SOC_LPUART_COUNT */
#if defined(FSL_FEATURE_SOC_LPUART_COUNT) && (FSL_FEATURE_SOC_LPUART_COUNT > 8U)
    kCLOCK_Lpuart8Clk,  /*!< LPUART8 clock. */
    kCLOCK_Lpuart9Clk,  /*!< LPUART9 clock. */
    kCLOCK_Lpuart10Clk, /*!< LPUART10 clock. */
    kCLOCK_Lpuart11Clk, /*!< LPUART11 clock. */
    kCLOCK_Lpuart12Clk, /*!< LPUART12 clock. */
    kCLOCK_Lpuart13Clk, /*!< LPUART13 clock. */
    kCLOCK_Lpuart14Clk, /*!< LPUART14 clock. */
    kCLOCK_Lpuart15Clk, /*!< LPUART15 clock. */
#endif                  /* FSL_FEATURE_SOC_LPUART_COUNT */

    kCLOCK_Pit0Clk,     /*!< PIT0 clock. */
    kCLOCK_Pit1Clk,     /*!< PIT1 clock. */
#if defined(FSL_FEATURE_SOC_PIT_COUNT) && (FSL_FEATURE_SOC_PIT_COUNT > 2U)
    kCLOCK_Pit2Clk,     /*!< PIT2 clock. */
#endif                  /* FSL_FEATURE_SOC_PIT_COUNT */

#if defined(FSL_FEATURE_SOC_I2S_COUNT) && (FSL_FEATURE_SOC_I2S_COUNT != 0U)
    kCLOCK_Sai0Clk, /*!< SAI0 clock. */
    kCLOCK_Sai1Clk, /*!< SAI0 clock. */
#endif

    kCLOCK_Stm0Clk, /*!< STM0 clock. */
#if defined(FSL_FEATURE_SOC_STM_COUNT) && (FSL_FEATURE_SOC_STM_COUNT > 1U)
    kCLOCK_Stm1Clk, /*!< STM0 clock. */
#endif              /* FSL_FEATURE_SOC_STM_COUNT */

#if defined(FSL_FEATURE_MC_ME_HAS_PRTN2) && (FSL_FEATURE_MC_ME_HAS_PRTN2 != 0U)
    kCLOCK_QspiSfClk, /*!< QSPI_SF clock. */
    kCLOCK_EmacRxClk, /*!< EMAC RX clock. */
    kCLOCK_EmacTxClk, /*!< EMAC TX clock. */
    kCLOCK_EmacTsClk, /*!< EMAC TS clock. */
#endif                /* FSL_FEATURE_MC_ME_HAS_PRTN2 */
} clock_name_t;

/** @brief Clock ip trigger divider type. */
typedef enum _clock_trigger_div_type
{
    KCLOCK_ImmediateUpdate     = 0U, /*!< Immediate divider update. */
    KCLOCK_CommonTriggerUpdate = 1U, /*!< Common trigger divider update.  */

} clock_trigger_div_type_t;

/** @brief Clock switch trigger source. */
typedef enum _clock_switch_trigger_src
{
    kCLOCK_SwitchReserved      = 0U, /*!< Reserved.  */
    kCLOCK_SwitchSuccessPerReq = 1U, /*!< Common trigger divider update.  */
    kCLOCK_SwitchFailedInactiveTarget =
        2U, /*!< Switch after the request failed because of an inactive target clock and the current clock is FIRC. */
    kCLOCK_SwitchFailedInactiveCurrent =
        3U, /*!< Switch after the request failed because of an inactive current clock and the current clock is FIRC.*/
    kCLOCK_SwitchSafeReq               = 4U, /*!< Switch to FIRC because of a safe clock request or reset succeeded.  */
    kCLOCK_SwitchSafeReqInactivePreClk = 5U, /*!< Switch to FIRC because of a safe clock request or reset succeeded, but
                                                the previous current clock source was inactive. */
} clock_switch_trigger_src_t;

/*! @brief The FIRC divider. */
typedef enum clock_firc_div
{
    kFIRC_DividedBy2  = 1U, /*!< FIRC clock divided by 2. */
    kFIRC_DividedBy16 = 2U, /*!< FIRC clock divided by 16. */
    kFIRC_Undivided   = 3U, /*!< FIRC clock undivided. */
} clock_firc_div_t;

/*! @brief The FXOSC work mode. */
typedef enum _fxosc_mode
{
    kFXOSC_ModeCrystal = FXOSC_CTRL_COMP_EN_MASK,                           /*!< Crystal mode. */
    kFXOSC_ModeBypass  = FXOSC_CTRL_COMP_EN_MASK | FXOSC_CTRL_OSC_BYP_MASK, /*!< Use external clock.   */
} fxosc_mode_t;

/*!
 * @brief OSC Initialization Configuration Structure
 *
 * Defines the configuration data structure to initialize the FXOSC.
 */
typedef struct _fxosc_config
{
    uint32_t freqHz;       /*!< Frequency in Herz. */
    fxosc_mode_t workMode; /*!< FXOSC work mode setting.       */
    uint8_t startupDelay; /*!< Specifies the end-of-count. Runs on crystal clock divided by 4 and counts to startupDelay
                           * 128. */
    uint8_t overdriveProtect; /*! < Crystal overdrive protection. Depends on crystal spec, referring datasheet. */
} fxosc_config_t;

/*! @brief The PLL work mode. */
typedef enum pll_mode
{
    kPLL_ModeInteger = 0U, /*!< PLL operates in integer-only mode. */
    kPLL_ModeFractional,   /*!< PLL operates in fractional mode. */
    kPLL_ModeSSCG,         /*!< PLL operates in Frequency Modulation mode. */
} pll_mode_t;

/*! @brief The PLL unlock accuracy. */
typedef enum pll_unlock_accuracy
{
    kPLL_UnlockAccuracy9 =
        0U, /*!< Unlock range = Expected value deviates by 9 (recommended when PLLFM[SSCGBYP] = 1). */
    kPLL_UnlockAccuracy17 =
        1U, /*!< Unlock range = Expected value deviates by 17 (recommended when PLLFM[SSCGBYP] = 1). */
    kPLL_UnlockAccuracy33 = 2U, /*!< Unlock range = Expected value deviates by 33. */
    kPLL_UnlockAccuracy5  = 3U, /*!< Unlock range = Expected value deviates by 5. */
} pll_unlock_accuracy_t;

/*!
 * @brief PLL Initialization Configuration Structure
 *
 * Defines the configuration data structure to initialize the PLL.
 * When porting to a new board, set the following members
 */
typedef struct _pll_config
{
    pll_mode_t workMode;  /*!< PLL work mode setting.       */
    uint8_t preDiv;       /*!< Input Clock Predivider. */
    uint8_t postDiv;      /*!< VCO clock post divider for driving the PHI output clock. */

    uint8_t multiplier;   /*!< Multiplication factor applied to the reference frequency. */
    uint16_t fracLoopDiv; /*!< Numerator Of Fractional Loop Division Factor.Value should less than 18432. Used for
                             Fractional Mode only. */

    uint16_t stepSize;    /*!< For SSCG mode. Frequency Modulation Step Size. */
    uint16_t stepNum;     /*!< For SSCG mode. Number Of Steps Of Modulation Period Or Frequency Modulation. */

    pll_unlock_accuracy_t accuracy;    /*!< PLL unlock accuracy. */
    uint8_t outDiv[PLL_PLLODIV_COUNT]; /*!< PLL Output Divider. */
} pll_config_t;

/*!
 * @brief Clock Source PCFS configuration structure.
 */
typedef struct _clock_pcfs_config_t
{
    uint32_t maxAllowableIDDchange; /*!< Maximum variation of current per time (mA/microsec) -  max allowable IDD change
                                       is determined by the user's power supply design. */
    uint32_t stepDuration;          /*!< Step duration of each PCFS step (time per step in us). */
    uint32_t clkSrcFreq; /*!< Frequency of the clock source from which ramp-down and to which ramp-up are processed. */
} clock_pcfs_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Starts the hardware processes for the partition(s) clock change sequence.
 * @return  Nothing
 */
inline static void CLOCK_McmeEnterKey(void)
{
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0x5AF0U);
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0xA50FU);
}

#if defined(FSL_FEATURE_CLOCK_HAS_EMAC)
/**
 * @brief API used to tell clock driver the clock frequency on the EMAC_RMII_MII_TX_CLK pin.
 * @param freq Frequency in herz.
 * @return  Nothing
 */
void CLOCK_SetEmacRmiiTxClkFreq(uint32_t freq);

/**
 * @brief API used to tell clock driver the clock frequency on the EMAC_RX_CLK pin.
 * @param freq Frequency in herz.
 * @return  Nothing
 */
void CLOCK_SetEmacRxClkFreq(uint32_t freq);
#endif /* FSL_FEATURE_CLOCK_HAS_EMAC */

/**
 * @brief Enable the clock for specific IP.
 * @param clk : Clock to be enabled.
 * @return  Nothing
 */
void CLOCK_EnableClock(clock_ip_name_t clk);

/**
 * @brief Disable the clock for specific IP.
 * @param clk : Clock to be disabled.
 * @return  Nothing
 */
void CLOCK_DisableClock(clock_ip_name_t clk);

/**
 * @brief   Setup peripheral clock dividers trigger type.
 *     selects whether the dividers associated with clock mux 0 are updated immediately on writing to the corresponding
 * divider configuration register (referred to as immediate divider update) or only on writing to the
 * MC_CGM_MUX_0_DIV_TRIG register (referred to as common trigger update)
 * @param   div_name    : Clock divider name
 * @param   type     :
 * @return  Nothing
 */
inline static void CLOCK_SetClkMux0DivTriggerType(clock_trigger_div_type_t type)
{
    if (type == KCLOCK_CommonTriggerUpdate)
    {
        MC_CGM->MUX_0_DIV_TRIG_CTRL |= MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK;
    }
    else
    {
        MC_CGM->MUX_0_DIV_TRIG_CTRL &= ~MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK;
    }
}

inline static void CLOCK_CommonTriggerClkMux0DivUpdate(void)
{
    MC_CGM->MUX_0_DIV_TRIG_CTRL = MC_CGM_MUX_0_DIV_TRIG_CTRL_TCTL_MASK | MC_CGM_MUX_0_DIV_TRIG_CTRL_HHEN_MASK;
    MC_CGM->MUX_0_DIV_TRIG      = MC_CGM_MUX_0_DIV_TRIG_TRIGGER(1u);

    /* Trigger clock transition for MC_CGM_MUX0 */
    while ((MC_CGM->MUX_0_DIV_UPD_STAT & MC_CGM_MUX_0_DIV_UPD_STAT_DIV_STAT_MASK) != 0)
    {
    }
}

/**
 * @brief   Setup FIRC clock divider.
 * @param   divider Value to be divided. Defined by clock_firc_div_t.
 * @retval kStatus_Success FIRC divider set succeed.
 * @retval kStatus_Fail FIRC divider set failed.
 */
status_t CLOCK_SetFircDiv(clock_firc_div_t divider);

/**
 * @brief   Setup peripheral clock dividers.
 * @param   div_name    : Clock divider name
 * @param   divider     : Value to be divided. Divider value 0 will disable the divider.
 * Undivided clock frequency / divider.
 * @return  Nothing
 */
void CLOCK_SetClkDiv(clock_div_name_t div_name, uint32_t divider);

/**
 * @brief Enable FIRC in standby mode.
 * @return  Nothing
 */
inline static void CLOCK_EnableFircInStandbyMode(void)
{
    FIRC->STDBY_ENABLE |= FIRC_STDBY_ENABLE_STDBY_EN_MASK;
}

/**
 * @brief Disable FIRC in standby mode.
 * @return  Nothing
 */
inline static void CLOCK_DisableFircInStandbyMode(void)
{
    FIRC->STDBY_ENABLE &= ~FIRC_STDBY_ENABLE_STDBY_EN_MASK;
}

/**
 * @brief Enable SIRC in standby mode.
 * @return  Nothing
 */
inline static void CLOCK_EnableSircInStandbyMode(void)
{
    SIRC->MISCELLANEOUS_IN |= SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_MASK;
}

/**
 * @brief Disable SIRC in standby mode.
 * @return  Nothing
 */
inline static void CLOCK_DisableSircInStandbyMode(void)
{
    SIRC->MISCELLANEOUS_IN &= ~SIRC_MISCELLANEOUS_IN_STANDBY_ENABLE_MASK;
}

/**
 * @brief Configure the clock selection muxes.
 * @param  connection  : Clock to be configured.
 * @return  Nothing
 */
void CLOCK_AttachClk(clock_attach_id_t connection);

/**
 * @brief Request safe clock switch to FIRC.
 * @param  connection  : Clock to be configured.
 * @return  Nothing
 */
void CLOCK_SelectSafeClock(clock_attach_id_t connection);

/**
 * @brief Configure the Progressive Clock Frequency Switch(PCFS) for MC_CGM MUX0.
 * @param  connection  : Clock to be configured. Only MUX_0 clock supports PCFS, kPLL_PHI0_CLK_to_MUX0.
 * @param  config : PCFS configuration.
 * @return  Nothing
 */
void CLOCK_ProgressiveClockFrequencySwitch(clock_attach_id_t connection, clock_pcfs_config_t const *config);

/**
 * @brief Get the clock selection status.
 * @param  connection  : Clock to be configured.
 * @return  clock selection status
 */
uint32_t CLOCK_GetClkSelectState(clock_attach_id_t connection);

/**
 * @brief Get the clock switch trigger source for hardware-controlled selector.
 * @param  connection  : Clock to be configured.
 * @return  clock selection status @ref clock_switch_trigger_src_t.
 */
uint32_t CLOCK_GetClkSwitchTriggerCause(clock_attach_id_t connection);

/*!
 * @brief Initialize the FXOSC.
 * @code
 *   fxosc_config_t config =
 *   {
 *     .freqHz = 16000000U,
 *     .workMode = kFXOSC_ModeCrystal,
 *     .startupDelay = 49U,
 *     .overdriveProtect = 12U,
 *   };
 *
 *   CLOCK_InitFxosc(&config);
 * @endcode
 * @param config The FXOSC configuration structure, @ref fxosc_config_t.
 */
void CLOCK_InitFxosc(const fxosc_config_t *config);

#if defined(FSL_FEATURE_MC_CGM_HAS_SXOSC) && (FSL_FEATURE_MC_CGM_HAS_SXOSC != 0U)
/*!
 * @brief Initialize the SXOSC.
 * @param enable Enable or disable the SXOSC.
 * @param startupDelay The oscillator counter runs on a divided crystal clock (divide by 4) and counts up to 128
times the EOCV value (EOCV * 128).
 */
void CLOCK_InitSxosc(bool enable, uint8_t startupDelay);
#endif /* FSL_FEATURE_MC_CGM_HAS_SXOSC */

/*!
 * @brief Disable FXOSC.
 */
static inline void CLOCK_DinitFxosc(void)
{
    FXOSC->CTRL &= ~FXOSC_CTRL_OSCON_MASK;
    g_xtal0Freq = 0U;
}

/*!
 * @brief Initialize the PLL.
 * @code
 *   pll_config_t config =
 *   {
 *     .workMode = kPLL_ModeInteger,
 *     .preDiv = 2U,
 *     .postDiv = 2U,
 *     .multiplier = 120U,
 *     .accuracy = kPLL_UnlockAccuracy9,
 *     .outDiv[0] = 3U,
 *     .outDiv[1] = 3U,
 *   };
 *
 *   CLOCK_InitPll(&pllConfig);
 * @endcode
 * @param config The PLL configuration structure, @ref pll_config_t.
 */

void CLOCK_InitPll(const pll_config_t *config);

/*!
 * @brief Deinit and disable the PLL.
 */
inline static void CLOCK_DeinitPll(void)
{
    uint32_t i = 0U;
    for (i = 0U; i < PLL_PLLODIV_COUNT; i++)
    {
        PLL->PLLODIV[i] &= ~PLL_PLLODIV_DE_MASK;
    }

    PLL->PLLCR |= PLL_PLLCR_PLLPD_MASK;
}

/*!
 * @brief Check whether the PLL is loss of lock.
 * @return true: Loss of lock is detected, false: No loss of lock detected.
 */
inline static bool CLOCK_IsPllLossOfLock(void)
{
    return ((PLL->PLLSR & PLL_PLLSR_LOL_MASK) != 0U) ? true : false;
}

/*!
 * @brief Gets the clock frequency for a specific clock name.
 *
 * This function checks the current clock configurations and then calculates
 * the clock frequency for a specific clock name defined in clock_name_t.
 *
 * @param name Clock names defined in clock_name_t
 * @return Clock frequency value in hertz
 */
uint32_t CLOCK_GetFreq(clock_name_t name);

/*!
 * @brief Get the Core clock frequency.
 * @return core clock frequency in HZ.
 */
uint32_t CLOCK_GetCoreClkFreq(void);

/*!
 * @brief Get the FIRC clock frequency.
 * @return FIRC frequency in HZ.
 */
uint32_t CLOCK_GetFircClkFreq(void);

/*!
 * @brief Get the FXOSC clock frequency.
 * @return FXOSC frequency in HZ.
 */
uint32_t CLOCK_GetFxoscFreq(void);

/*!
 * @brief Get the AIPS_PLAT_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetAipsPlatClkFreq(void);

/*!
 * @brief Get the AIPS_SLOW_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetAipsSlowClkFreq(void);

/*!
 * @brief Get the HSE_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetHseClkFreq(void);

/*!
 * @brief Get the DCM_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetDcmClkFreq(void);

#if defined(FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV) && (FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV != 0U)
/*!
 * @brief Get the LBIST_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetLbistClkFreq(void);
#endif /* FSL_FEATURE_MC_CGM_HAS_LBIST_CLK_DIV */

#if defined(FSL_FEATURE_CLOCK_HAS_QSPI) && (FSL_FEATURE_CLOCK_HAS_QSPI != 0U)
/*!
 * @brief Get the QSPI_CLK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetQspiClkFreq(void);

/*!
 * @brief Get the QSPI_SFCK clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetQspiSfckFreq(void);
#endif /* FSL_FEATURE_CLOCK_HAS_QSPI */

/*!
 * @brief Get the PLL_PHI clock frequency.
 * @param index The PHI index.
 * @return PLL_PHIx frequency in HZ.
 */
uint32_t CLOCK_GetPllPhiClkFreq(uint32_t index);

/*!
 * @brief Get the FLEXCAN PE clock frequency.
 * @param index The FLEXCAN index.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetFlexcanPeClkFreq(uint32_t index);

/*!
 * @brief Get the STM clock frequency.
 * @param index The STM index.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetStmClkFreq(uint32_t index);

#if defined(FSL_FEATURE_CLOCK_HAS_EMAC) && (FSL_FEATURE_CLOCK_HAS_EMAC != 0U)
/*!
 * @brief Get the EMAC RX clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetEmacRxClkFreq(void);

/*!
 * @brief Get the EMAC TX clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetEmacTxClkFreq(void);

/*!
 * @brief Get the EMAC TS clock frequency.
 * @return frequency in HZ.
 */
uint32_t CLOCK_GetEmacTsClkFreq(void);
#endif /* FSL_FEATURE_CLOCK_HAS_EMAC */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_CLOCK_H_ */
