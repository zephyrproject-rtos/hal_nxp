/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRGMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(TRGMUX_SOURCE_T_)
#define TRGMUX_SOURCE_T_
/*!
 * @addtogroup trgmux_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Structure for the TRGMUX source
 *
 * Defines the structure for the TRGMUX source collections.
 */
typedef enum _trgmux_source
{
    kTRGMUX_SourceDisabled          = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourceVdd               = 1U,          /**< VDD is selected */
    kTRGMUX_SourceTriggerMuxInput0  = 2U,          /**< Trigger Mux input 0 is selected */
    kTRGMUX_SourceTriggerMuxInput1  = 3U,          /**< Trigger Mux input 1 is selected */
    kTRGMUX_SourceTriggerMuxInput2  = 4U,          /**< Trigger Mux input 2 is selected */
    kTRGMUX_SourceTriggerMuxInput3  = 5U,          /**< Trigger Mux input 3 is selected */
    kTRGMUX_SourceTriggerMuxInput4  = 6U,          /**< Trigger Mux input 4 is selected */
    kTRGMUX_SourceTriggerMuxInput5  = 7U,          /**< Trigger Mux input 5 is selected */
    kTRGMUX_SourceTriggerMuxInput6  = 8U,          /**< Trigger Mux input 6 is selected */
    kTRGMUX_SourceTriggerMuxInput7  = 9U,          /**< Trigger Mux input 7 is selected */
    kTRGMUX_SourceTriggerMuxInput8  = 10U,         /**< Trigger Mux input 8 is selected */
    kTRGMUX_SourceTriggerMuxInput9  = 11U,         /**< Trigger Mux input 9 is selected */
    kTRGMUX_SourceTriggerMuxInput10 = 12U,         /**< Trigger Mux input 10 is selected */
    kTRGMUX_SourceTriggerMuxInput11 = 13U,         /**< Trigger Mux input 11 is selected */
    kTRGMUX_SourceCmp0Output        = 14U,         /**< CMP0 Output is selected */
    kTRGMUX_SourceLpitCh0           = 17U,         /**< LPIT Channel0 is selected */
    kTRGMUX_SourceLpitCh1           = 18U,         /**< LPIT Channel1 is selected */
    kTRGMUX_SourceLpitCh2           = 19U,         /**< LPIT Channel2 is selected */
    kTRGMUX_SourceLpitCh3           = 20U,         /**< LPIT Channel3 is selected */
    kTRGMUX_SourceLptmr0            = 21U,         /**< LPTMR0 input is selected */
    kTRGMUX_SourceFtm0InitTrg       = 22U,         /**< FTM0 init trigger is selected */
    kTRGMUX_SourceFtm0ExtTrg        = 23U,         /**< FTM0 external trigger is selected */
    kTRGMUX_SourceFtm1InitTrg       = 24U,         /**< FTM1 init trigger is selected */
    kTRGMUX_SourceFtm1ExtTrg        = 25U,         /**< FTM1 external trigger is selected */
    kTRGMUX_SourceFtm2InitTrg       = 26U,         /**< FTM2 init trigger is selected */
    kTRGMUX_SourceFtm2ExtTrg        = 27U,         /**< FTM2 external trigger is selected */
    kTRGMUX_SourceFtm3InitTrg       = 28U,         /**< FTM3 init trigger is selected */
    kTRGMUX_SourceFtm3ExtTrg        = 29U,         /**< FTM3 external trigger is selected */
    kTRGMUX_SourceAdc0CocoA         = 30U,         /**< ADC0 COCOA is selected */
    kTRGMUX_SourceAdc0CocoB         = 31U,         /**< ADC0 COCOB is selected */
    kTRGMUX_SourceAdc1CocoA         = 32U,         /**< ADC1 COCOA is selected */
    kTRGMUX_SourceAdc1CocoB         = 33U,         /**< ADC1 COCOB is selected */
    kTRGMUX_SourcePdb0Ch0Trg        = 34U,         /**< PDB0 Channel0 trigger is selected */
    kTRGMUX_SourcePdb0PulseOut      = 36U,         /**< PDB0 pulse out is selected */
    kTRGMUX_SourcePdb1Ch0Trg        = 37U,         /**< PDB1 Channel0 trigger is selected */
    kTRGMUX_SourcePdb1PulseOut      = 39U,         /**< PDB1 pulse out is selected */
    kTRGMUX_SourceRtcAlarm          = 43U,         /**< RTC Alarm input is selected */
    kTRGMUX_SourceRtcSecond         = 44U,         /**< RTC Alarm input is selected */
    kTRGMUX_SourceFlexIOTrg0        = 45U,         /**< FLEXIO Trigger 0 is selected */
    kTRGMUX_SourceFlexIOTrg1        = 46U,         /**< FLEXIO Trigger 1 is selected */
    kTRGMUX_SourceFlexIOTrg2        = 47U,         /**< FLEXIO Trigger 2 is selected */
    kTRGMUX_SourceFlexIOTrg3        = 48U,         /**< FLEXIO Trigger 3 is selected */
    kTRGMUX_SourceLpuart0RxData     = 49U,         /**< LPUART0 RX Data is selected */
    kTRGMUX_SourceLpuart0TxData     = 50U,         /**< LPUART0 TX Data is selected */
    kTRGMUX_SourceLpuart0Idle       = 51U,         /**< LPUART0 Idle is selected */
    kTRGMUX_SourceLpuart1RxData     = 52U,         /**< LPUART1 RX Data is selected */
    kTRGMUX_SourceLpuart1TxData     = 53U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 54U,         /**< LPUART1 RX Idle is selected */
    kTRGMUX_SourceLpi2c0MasterTrg   = 55U,         /**< LPI2C0 Master trigger is selected */
    kTRGMUX_SourceLpi2c0SlaveTrg    = 56U,         /**< LPI2C0 Slave trigger is selected */
    kTRGMUX_SourceLpspi0Frame       = 59U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_SourceLpspi0RxData      = 60U,         /**< LPSPI0 RX Data is selected */
    kTRGMUX_SourceLpspi1Frame       = 61U,         /**< LPSPI1 Frame is selected */
    kTRGMUX_SourceLpspi1RxData      = 62U,         /**< LPSPI1 RX Data is selected */
    kTRGMUX_SourceSimSwTrg          = 63U,         /**< SIM SW trigger is selected */
    kTRGMUX_SourceLpi2c1MasterTrg   = 67U,         /**< LPI2C1 Master trigger is selected */
    kTRGMUX_SourceLpi2c1SlaveTrg    = 68U,         /**< LPI2C1 Slave trigger is selected */
    kTRGMUX_SourceFtm4InitTrg       = 69U,         /**< FTM4 init trigger is selected */
    kTRGMUX_SourceFtm4ExtTrg        = 70U,         /**< FTM4 external trigger is selected */
    kTRGMUX_SourceFtm5InitTrg       = 71U,         /**< FTM5 init trigger is selected */
    kTRGMUX_SourceFtm5ExtTrg        = 72U,         /**< FTM5 external trigger is selected */
    kTRGMUX_SourceFtm6InitTrg       = 73U,         /**< FTM6 init trigger is selected */
    kTRGMUX_SourceFtm6ExtTrg        = 74U,         /**< FTM6 external trigger is selected */
    kTRGMUX_SourceFtm7InitTrg       = 75U,         /**< FTM7 init trigger is selected */
    kTRGMUX_SourceFtm7ExtTrg        = 76U,         /**< FTM7 external trigger is selected */
} trgmux_source_t;
#endif /* TRGMUX_SOURCE_T_ */

#if !defined(TRGMUX_DEVICE_T_)
#define TRGMUX_DEVICE_T_
/*!
 * @brief Structure for the TRGMUX device
 *
 * Defines the structure for the TRGMUX device collections.
 */
typedef enum _trgmux_device
{
    kTRGMUX_Dmamux0                 = 0U,          /**< DMAMUX0 device trigger input */
    kTRGMUX_ExtOut0                 = 1U,          /**< EXTOUT0 device trigger input */
    kTRGMUX_ExtOut1                 = 2U,          /**< EXTOUT1 device trigger input */
    kTRGMUX_Adc0                    = 3U,          /**< ADC0 device trigger input */
    kTRGMUX_Adc1                    = 4U,          /**< ADC1 device trigger input */
    kTRGMUX_Cmp0                    = 7U,          /**< CMP0 device trigger input */
    kTRGMUX_Ftm0                    = 10U,         /**< FTM0 device trigger input */
    kTRGMUX_Ftm1                    = 11U,         /**< FTM1 device trigger input */
    kTRGMUX_Ftm2                    = 12U,         /**< FTM2 device trigger input */
    kTRGMUX_Ftm3                    = 13U,         /**< FTM3 device trigger input */
    kTRGMUX_Pdb0                    = 14U,         /**< PDB0 device trigger input */
    kTRGMUX_Pdb1                    = 15U,         /**< PDB1 device trigger input */
    kTRGMUX_Flexio                  = 17U,         /**< FLEXIO device trigger input */
    kTRGMUX_Lpit0                   = 18U,         /**< LPIT0 device trigger input */
    kTRGMUX_Lpuart0                 = 19U,         /**< LPUART0 device trigger input */
    kTRGMUX_Lpuart1                 = 20U,         /**< LPUART1 device trigger input */
    kTRGMUX_Lpi2c0                  = 21U,         /**< LPI2C0 device trigger input */
    kTRGMUX_Lpspi0                  = 23U,         /**< LPSPI0 device trigger input */
    kTRGMUX_Lpspi1                  = 24U,         /**< LPSPI1 device trigger input */
    kTRGMUX_Lptmr0                  = 25U,         /**< LPTMR0 device trigger input */
    kTRGMUX_Lpi2c1                  = 27U,         /**< LPI2C1 device trigger input */
    kTRGMUX_Ftm4                    = 28U,         /**< FTM4 device trigger input */
    kTRGMUX_Ftm5                    = 29U,         /**< FTM5 device trigger input */
    kTRGMUX_Ftm6                    = 30U,         /**< FTM6 device trigger input */
    kTRGMUX_Ftm7                    = 31U,         /**< FTM7 device trigger input */
} trgmux_device_t;

/* @} */
#endif /* TRGMUX_DEVICE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGCFG_COUNT                       32u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX DMAMUX0 Register..TRGMUX FTM7 Register, array offset: 0x0, array step: 0x4, valid indices: [0-4, 7, 10-15, 17-21, 23-25, 27-31] */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX DMAMUX0 Register..TRGMUX FTM7 Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x7F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x7F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x7F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - TRGMUX register lock.
 *  0b0..Register can be written.
 *  0b1..Register cannot be written until the next system Reset.
 */
#define TRGMUX_TRGCFG_LK(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_LK_SHIFT)) & TRGMUX_TRGCFG_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */

#define TRGMUX_PERIPHERAL_MASK                    0xFFF
#define TRGMUX_PERIPHERAL_SHIFT                   0

#define TRGMUX_DMAMUX0_INDEX                     (0U)
#define TRGMUX_EXTOUT0_INDEX                     (1U)
#define TRGMUX_EXTOUT1_INDEX                     (2U)
#define TRGMUX_ADC0_INDEX                        (3U)
#define TRGMUX_ADC1_INDEX                        (4U)
#define TRGMUX_CMP0_INDEX                        (7U)
#define TRGMUX_FTM0_INDEX                        (10U)
#define TRGMUX_FTM1_INDEX                        (11U)
#define TRGMUX_FTM2_INDEX                        (12U)
#define TRGMUX_FTM3_INDEX                        (13U)
#define TRGMUX_PDB0_INDEX                        (14U)
#define TRGMUX_PDB1_INDEX                        (15U)
#define TRGMUX_FLEXIO_INDEX                      (17U)
#define TRGMUX_LPIT_INDEX                        (18U)
#define TRGMUX_LPUART0_INDEX                     (19U)
#define TRGMUX_LPUART1_INDEX                     (20U)
#define TRGMUX_LPI2C0_INDEX                      (21U)
#define TRGMUX_LPSPI0_INDEX                      (23U)
#define TRGMUX_LPSPI1_INDEX                      (24U)
#define TRGMUX_LPTMR0_INDEX                      (25U)
#define TRGMUX_LPI2C1_INDEX                      (27U)
#define TRGMUX_FTM4_INDEX                        (28U)
#define TRGMUX_FTM5_INDEX                        (29U)
#define TRGMUX_FTM6_INDEX                        (30U)
#define TRGMUX_FTM7_INDEX                        (31U)


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_TRGMUX_H_ */

