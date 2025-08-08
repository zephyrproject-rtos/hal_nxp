/*
** ###################################################################
**     Processors:          MKE14Z128VLH7
**                          MKE14Z128VLL7
**                          MKE14Z256VLH7
**                          MKE14Z256VLL7
**                          MKE15Z128VLH7
**                          MKE15Z128VLL7
**                          MKE15Z256VLH7
**                          MKE15Z256VLL7
**
**     Version:             rev. 7.0, 2024-10-29
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
**     - rev. 1.0 (2015-08-19)
**         Initial version.
**     - rev. 2.0 (2015-09-22)
**         Based on rev0final RDP, add PCC/TRGMUX.
**     - rev. 3.0 (2015-12-29)
**         Align LPFLL register names.
**     - rev. 4.0 (2016-02-19)
**         Based on rev1final RDP.
**     - rev. 5.0 (2016-08-02)
**         Based on rev1.x RDP.
**     - rev. 6.0 (2016-09-20)
**         Based on rev2 RDP.
**     - rev. 7.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 7.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE14Z128VLH7) || defined(CPU_MKE14Z128VLL7) || defined(CPU_MKE14Z256VLH7) || defined(CPU_MKE14Z256VLL7))
#include "MKE14Z7_COMMON.h"
#elif (defined(CPU_MKE15Z128VLH7) || defined(CPU_MKE15Z128VLL7) || defined(CPU_MKE15Z256VLH7) || defined(CPU_MKE15Z256VLL7))
#include "MKE15Z7_COMMON.h"
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
    kTRGMUX_SourceDisabled0         = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourceTriggerMuxInput1  = 1U,          /**< Trigger Mux input 1 is selected */
    kTRGMUX_SourceDisabled1         = 1U,          /**< Trigger function is disabled */
    kTRGMUX_SourceTriggerMuxInput2  = 2U,          /**< Trigger Mux input 2 is selected */
    kTRGMUX_SimSoftwareTrigger      = 2U,          /**< SIM Software Trigger is selected */
    kTRGMUX_SourceTriggerMuxInput3  = 3U,          /**< Trigger Mux input 3 is selected */
    kTRGMUX_SourceTriggerMuxInput4  = 3U,          /**< Trigger Mux input 4 is selected */
    kTRGMUX_SourceRtcSeconds        = 4U,          /**< RTC Seconds input is selected */
    kTRGMUX_SourceTriggerMuxInput5  = 4U,          /**< Trigger Mux input 5 is selected */
    kTRGMUX_SourceRtcAlarm          = 5U,          /**< RTC Alarm input is selected */
    kTRGMUX_SourceTriggerMuxInput6  = 5U,          /**< Trigger Mux input 6 is selected */
    kTRGMUX_SourceLptmr0            = 6U,          /**< LPTMR0 input is selected */
    kTRGMUX_SourceTriggerMuxInput7  = 6U,          /**< Trigger Mux input 7 is selected */
    kTRGMUX_SourceLpit0Ch0          = 7U,          /**< LPIT0 Channel0 is selected */
    kTRGMUX_SourceLpuart0RxData     = 7U,          /**< LPUART0 RX Data is selected */
    kTRGMUX_SourceLpit0Ch1          = 8U,          /**< LPIT0 Channel1 is selected */
    kTRGMUX_SourceLpuart0TxData     = 8U,          /**< LPUART0 TX Data is selected */
    kTRGMUX_SourceLpit0Ch2          = 9U,          /**< LPIT0 Channel2 is selected */
    kTRGMUX_SourceLpuart0Idle       = 9U,          /**< LPUART0 Idle is selected */
    kTRGMUX_SourceLpit0Ch3          = 10U,         /**< LPIT0 Channel3 is selected */
    kTRGMUX_SourceLpi2c0MasterStop  = 10U,         /**< LPI2C0 Master STOP is selected */
    kTRGMUX_SourceFtm0              = 11U,         /**< FTM0 is selected */
    kTRGMUX_SourceLpi2c0SlaveStop   = 11U,         /**< LPI2C0 Slave STOP is selected */
    kTRGMUX_SourceFtm1              = 12U,         /**< FTM1 is selected */
    kTRGMUX_SourceLpspi0Frame       = 12U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_SourceFtm2              = 13U,         /**< FTM2 is selected */
    kTRGMUX_SourceLpspi0RxData      = 13U,         /**< LPSPI0 RX Data is selected */
    kTRGMUX_SourceAdc0CocoA         = 15U,         /**< ADC0 COCOA is selected */
    kTRGMUX_SourceLpuart1TxData     = 15U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_SourceAdc0CocoB         = 16U,         /**< ADC0 COCOB is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 16U,         /**< LPUART1 RX Idle is selected */
    kTRGMUX_SourceCmp0Output        = 17U,         /**< CMP0 Output is selected */
    kTRGMUX_SourceLpi2c1MasterStop  = 17U,         /**< LPI2C1 Master STOP is selected */
    kTRGMUX_SourceCmp1Output        = 18U,         /**< CMP1 Output is selected */
    kTRGMUX_SourceLpi2c1SlaveStop   = 18U,         /**< LPI2C1 Slave STOP is selected */
    kTRGMUX_SourceFlexIOTimer0      = 20U,         /**< FLEXIO Trigger 0 is selected */
    kTRGMUX_SourceLpspi1RxData      = 20U,         /**< LPSPI1 RX Data is selected */
    kTRGMUX_SourceFlexIOTimer1      = 21U,         /**< FLEXIO Trigger 1 is selected */
    kTRGMUX_SourceAdc1CocoA         = 21U,         /**< ADC1 COCOA is selected */
    kTRGMUX_SourceFlexIOTimer2      = 22U,         /**< FLEXIO Trigger 2 is selected */
    kTRGMUX_SourceAdc1CocoB         = 22U,         /**< ADC1 COCOB is selected */
    kTRGMUX_SourceFlexIOTimer3      = 23U,         /**< FLEXIO Trigger 3 is selected */
    kTRGMUX_SourcePdb0Pulse0        = 23U,         /**< PDB0 Pulse0 is selected */
    kTRGMUX_SourceTrgmux1Output0    = 24U,         /**< TRGMUX1 Output 0 is selected */
    kTRGMUX_SourcePdb0Pulse1        = 24U,         /**< PDB0 Pulse1 is selected */
    kTRGMUX_SourceTrgmux1Output1    = 25U,         /**< TRGMUX1 Output 1 is selected */
    kTRGMUX_SourceTrgmux1Output2    = 26U,         /**< TRGMUX1 Output 2 is selected */
    kTRGMUX_SourceTrgmux1Output3    = 27U,         /**< TRGMUX1 Output 3 is selected */
    kTRGMUX_SourceTrgmux1Output4    = 28U,         /**< TRGMUX1 Output 4 is selected */
    kTRGMUX_SourceTrgmux1Output5    = 29U,         /**< TRGMUX1 Output 5 is selected */
    kTRGMUX_SourceTrgmux1Output6    = 30U,         /**< TRGMUX1 Output 6 is selected */
    kTRGMUX_SourceTrgmux1Output7    = 31U,         /**< TRGMUX1 Output 7 is selected */
    kTRGMUX_SourceLpuart1RxData     = 14U,         /**< LPUART1 RX Data is selected */
    kTRGMUX_SourceLpspi1Frame       = 19U,         /**< LPSPI1 Frame is selected */
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
    kTRGMUX_Ctrl0                   = 0U,          /**< CTRL0 device trigger input */
    kTRGMUX_ExtOut0_3               = 1U,          /**< EXTOUT0 device trigger input */
    kTRGMUX_Ctrl1                   = 1U,          /**< CTRL1 device trigger input */
    kTRGMUX_ExtOut4_7               = 2U,          /**< EXTOUT1 device trigger input */
    kTRGMUX_Adc0                    = 3U,          /**< ADC0 device trigger input */
    kTRGMUX_Adc1                    = 4U,          /**< ADC1 device trigger input */
    kTRGMUX_Cmp0                    = 7U,          /**< CMP0 device trigger input */
    kTRGMUX_Cmp1                    = 8U,          /**< CMP1 device trigger input */
    kTRGMUX_Ftm0                    = 10U,         /**< FTM0 device trigger input */
    kTRGMUX_Ftm1                    = 11U,         /**< FTM1 device trigger input */
    kTRGMUX_Ftm2                    = 12U,         /**< FTM2 device trigger input */
    kTRGMUX_Pdb0                    = 14U,         /**< PDB0 device trigger input */
    kTRGMUX_Flexio                  = 17U,         /**< FLEXIO device trigger input */
    kTRGMUX_Lpit                    = 18U,         /**< LPIT device trigger input */
    kTRGMUX_Lpuart0                 = 19U,         /**< LPUART0 device trigger input */
    kTRGMUX_Lpuart1                 = 20U,         /**< LPUART1 device trigger input */
    kTRGMUX_Lpi2c0                  = 21U,         /**< LPI2C0 device trigger input */
    kTRGMUX_Lpi2c1                  = 22U,         /**< LPI2C1 device trigger input */
    kTRGMUX_Lpspi0                  = 23U,         /**< LPSPI0 device trigger input */
    kTRGMUX_Lpspi1                  = 24U,         /**< LPSPI1 device trigger input */
    kTRGMUX_Lptmr0                  = 25U,         /**< LPTMR0 device trigger input */
    kTRGMUX_Pwt                     = 27U,         /**< PWT device trigger input */
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
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x3FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x3F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x3F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x3F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - Enable
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

#define TRGMUX_DMAMUX0_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 0)
#define TRGMUX_EXTOUT0_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 1)
#define TRGMUX_EXTOUT1_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 2)
#define TRGMUX_ADC0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 3)
#define TRGMUX_ADC1_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 4)
#define TRGMUX_CMP0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 7)
#define TRGMUX_CMP1_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 8)
#define TRGMUX_FTM0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 10)
#define TRGMUX_FTM1_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 11)
#define TRGMUX_FTM2_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 12)
#define TRGMUX_PDB0_INDEX                        ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 14)
#define TRGMUX_FLEXIO_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 17)
#define TRGMUX_LPIT0_INDEX                       ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 18)
#define TRGMUX_LPUART0_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 19)
#define TRGMUX_LPUART1_INDEX                     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 20)
#define TRGMUX_LPI2C0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 21)
#define TRGMUX_LPI2C1_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 22)
#define TRGMUX_LPSPI0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 23)
#define TRGMUX_LPSPI1_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 24)
#define TRGMUX_LPTMR0_INDEX                      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 25)
#define TRGMUX_TSI_INDEX                         ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 26)
#define TRGMUX_PWT_INDEX                         ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 27)
#define TRGMUX_CTRL0_INDEX                       ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 0)
#define TRGMUX_CTRL1_INDEX                       ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 1)


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

