/*
** ###################################################################
**     Processors:          MKE14Z32VFP4
**                          MKE14Z32VLD4
**                          MKE14Z32VLF4
**                          MKE14Z64VFP4
**                          MKE14Z64VLD4
**                          MKE14Z64VLF4
**                          MKE15Z32VFP4
**                          MKE15Z32VLD4
**                          MKE15Z32VLF4
**                          MKE15Z64VFP4
**                          MKE15Z64VLD4
**                          MKE15Z64VLF4
**                          MKE16Z32VLD4
**                          MKE16Z32VLF4
**                          MKE16Z64VLD4
**                          MKE16Z64VLF4
**
**     Version:             rev. 4.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2018-05-09)
**         Initial version.
**     - rev. 2.0 (2018-09-17)
**         Based on rev1 RM.
**     - rev. 3.0 (2020-01-22)
**         Add 40 pins part numbers.
**     - rev. 4.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 4.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z32VFP4) || defined(CPU_MKE14Z32VLD4) || defined(CPU_MKE14Z32VLF4) || defined(CPU_MKE14Z64VFP4) || defined(CPU_MKE14Z64VLD4) || defined(CPU_MKE14Z64VLF4))
#include "MKE14Z4_COMMON.h"
#elif (defined(CPU_MKE15Z32VFP4) || defined(CPU_MKE15Z32VLD4) || defined(CPU_MKE15Z32VLF4) || defined(CPU_MKE15Z64VFP4) || defined(CPU_MKE15Z64VLD4) || defined(CPU_MKE15Z64VLF4))
#include "MKE15Z4_COMMON.h"
#elif (defined(CPU_MKE16Z32VLD4) || defined(CPU_MKE16Z32VLF4) || defined(CPU_MKE16Z64VLD4) || defined(CPU_MKE16Z64VLF4))
#include "MKE16Z4_COMMON.h"
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
    kTRGMUX_SourceTriggerMuxInput0  = 0U,          /**< Trigger Mux input 0 is selected */
    kTRGMUX_SourceVss               = 0U,          /**< VSS is disabled */
    kTRGMUX_SourceTriggerMuxInput1  = 1U,          /**< Trigger Mux input 1 is selected */
    kTRGMUX_SourceVdd               = 1U,          /**< VDD is disabled */
    kTRGMUX_SourceTriggerMuxInput2  = 2U,          /**< Trigger Mux input 2 is selected */
    kTRGMUX_SimSoftwareTrigger      = 2U,          /**< SIM Software Trigger is selected */
    kTRGMUX_SourceTriggerMuxInput3  = 3U,          /**< Trigger Mux input 3 is selected */
    kTRGMUX_SourceRtcSeconds        = 4U,          /**< RTC Seconds input is selected */
    kTRGMUX_SourceRtcAlarm          = 5U,          /**< RTC Alarm input is selected */
    kTRGMUX_SourceLptmr0            = 6U,          /**< LPTMR0 input is selected */
    kTRGMUX_SourceLpit0Ch0          = 7U,          /**< LPIT0 Channel0 is selected */
    kTRGMUX_SourceLpuart0RxData     = 7U,          /**< LPUART0 RX Data is selected */
    kTRGMUX_SourceLpit0Ch1          = 8U,          /**< LPIT0 Channel1 is selected */
    kTRGMUX_SourceLpuart0TxData     = 8U,          /**< LPUART0 TX Data is selected */
    kTRGMUX_SourceFtm0              = 11U,         /**< FTM0 is selected */
    kTRGMUX_SourceLpi2c0SlaveStop   = 11U,         /**< LPI2C0 Slave STOP is selected */
    kTRGMUX_SourceFtm1              = 12U,         /**< FTM1 is selected */
    kTRGMUX_SourceLpspi0Frame       = 12U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_SourceAdc0CocoA         = 15U,         /**< ADC0 COCOA is selected */
    kTRGMUX_SourceLpuart1TxData     = 15U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_SourceAdc0CocoB         = 16U,         /**< ADC0 COCOB is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 16U,         /**< LPUART1 RX Idle is selected */
    kTRGMUX_SourceCmp0Output        = 17U,         /**< CMP0 Output is selected */
    kTRGMUX_SourceTrgmux1Output0    = 24U,         /**< TRGMUX1 Output 0 is selected */
    kTRGMUX_SourceTrgmux1Output1    = 25U,         /**< TRGMUX1 Output 1 is selected */
    kTRGMUX_SourceTrgmux1Output2    = 26U,         /**< TRGMUX1 Output 2 is selected */
    kTRGMUX_SourceTrgmux1Output3    = 27U,         /**< TRGMUX1 Output 3 is selected */
    kTRGMUX_SourceLpuart0Idle       = 9U,          /**< LPUART0 Idle is selected */
    kTRGMUX_SourceLpi2c0MasterStop  = 10U,         /**< LPI2C0 Master STOP is selected */
    kTRGMUX_SourceLpspi0RxData      = 13U,         /**< LPSPI0 RX Data is selected */
    kTRGMUX_SourceLpuart1RxData     = 14U,         /**< LPUART1 RX Data is selected */
    kTRGMUX_SourcePdb0Pulse0        = 23U,         /**< PDB0 Pulse0 is selected */
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
    kTRGMUX_ExtOut0_3               = 1U,          /**< EXTOUT0 device trigger input */
    kTRGMUX_Adc0                    = 3U,          /**< ADC0 device trigger input */
    kTRGMUX_Cmp0                    = 7U,          /**< CMP0 device trigger input */
    kTRGMUX_Ftm0                    = 10U,         /**< FTM0 device trigger input */
    kTRGMUX_Ftm1                    = 11U,         /**< FTM1 device trigger input */
    kTRGMUX_Pdb0                    = 14U,         /**< PDB0 device trigger input */
    kTRGMUX_Lpit                    = 18U,         /**< LPIT device trigger input */
    kTRGMUX_Lpuart0                 = 19U,         /**< LPUART0 device trigger input */
    kTRGMUX_Lpuart1                 = 20U,         /**< LPUART1 device trigger input */
    kTRGMUX_Lpi2c0                  = 21U,         /**< LPI2C0 device trigger input */
    kTRGMUX_Lpspi0                  = 23U,         /**< LPSPI0 device trigger input */
    kTRGMUX_Lptmr0                  = 25U,         /**< LPTMR0 device trigger input */
    kTRGMUX_Pwt                     = 27U,         /**< PWT device trigger input */
    kTRGMUX_Ctrl0                   = 0U,          /**< CTRL0 device trigger input */
    kTRGMUX_Tsi                     = 26U,         /**< TSI device trigger input */
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
#define TRGMUX_TRGCFG_COUNT                       28u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX CTRL0 Register..TRGMUX PWT Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX CTRL0 Register..TRGMUX PWT Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x1FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x1F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x1F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x1F000000U)
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

#define TRGMUX_INSTANCE_MASK                      0xF
#define TRGMUX_INSTANCE_SHIFT                     12
#define TRGMUX_PERIPHERAL_MASK                    0xFFF
#define TRGMUX_PERIPHERAL_SHIFT                   0
#define TRGMUX_INSTANCE_0                         0
#define TRGMUX_INSTANCE_1                         1

#define TRGMUX_EXTOUT0_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 1)
#define TRGMUX_ADC0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 3)
#define TRGMUX_CMP0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 7)
#define TRGMUX_FTM0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 10)
#define TRGMUX_FTM1_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 11)
#define TRGMUX_PDB0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 14)
#define TRGMUX_LPIT0_INDEX                       ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 18)
#define TRGMUX_LPUART0_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 19)
#define TRGMUX_LPUART1_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 20)
#define TRGMUX_LPI2C0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 21)
#define TRGMUX_LPSPI0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 23)
#define TRGMUX_LPTMR0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 25)
#define TRGMUX_TSI_INDEX                         ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 26)
#define TRGMUX_PWT_INDEX                         ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 27)
#define TRGMUX_CTRL0_INDEX                       ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 0)


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
#elif defined(__CWCC__)
  #pragma pop
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

