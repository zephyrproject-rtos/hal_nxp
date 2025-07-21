/*
** ###################################################################
**     Processors:          MKE12Z512VLH9
**                          MKE12Z512VLL9
**                          MKE13Z512VLH9
**                          MKE13Z512VLL9
**                          MKE17Z512VLH9
**                          MKE17Z512VLL9
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PCC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-03-01)
**         Initial version.
**     - rev. 2.0 (2023-10-08)
**         Based on Rev.1 RM.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PCC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PCC
 *
 * CMSIS Peripheral Access Layer for PCC
 */

#if !defined(PERI_PCC_H_)
#define PERI_PCC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE12Z512VLH9) || defined(CPU_MKE12Z512VLL9))
#include "MKE12Z9_COMMON.h"
#elif (defined(CPU_MKE13Z512VLH9) || defined(CPU_MKE13Z512VLL9))
#include "MKE13Z9_COMMON.h"
#elif (defined(CPU_MKE17Z512VLH9) || defined(CPU_MKE17Z512VLL9))
#include "MKE17Z9_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

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
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */

/** PCC - Size of Registers Arrays */
#define PCC_CLKCFG_COUNT                          116u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CLKCFG[PCC_CLKCFG_COUNT];          /**< PCC DMA..PCC CMP0, array offset: 0x0, array step: 0x4, valid indices: [8, 32-33, 44-45, 50, 55-59, 61, 64, 69, 71, 73-77, 86, 90, 97-99, 102-103, 106-110, 115] */
} PCC_Type;

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/*! @name CLKCFG - PCC DMA..PCC CMP0 */
/*! @{ */

#define PCC_CLKCFG_PCD_MASK                      (0xFFFFU)
#define PCC_CLKCFG_PCD_SHIFT                     (0U)
/*! PCD - Peripheral Clock Divider Select
 *  0b0000000000000000..Divide by 1.
 *  0b0000000000000001..Divide by 2.
 *  0b0000000000000010..Divide by 3.
 *  0b0000000000000011..Divide by 4.
 *  0b0000000000000100..Divide by 5.
 *  0b0000000000000101..Divide by 6.
 *  0b0000000000000110..Divide by 7.
 *  0b0000000000000111..Divide by 8.
 */
#define PCC_CLKCFG_PCD(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCD_SHIFT)) & PCC_CLKCFG_PCD_MASK)

#define PCC_CLKCFG_FRAC_MASK                     (0x10000U)
#define PCC_CLKCFG_FRAC_SHIFT                    (16U)
/*! FRAC - Peripheral Clock Divider Fraction
 *  0b0..Fractional value is 0.
 *  0b1..Fractional value is 1.
 */
#define PCC_CLKCFG_FRAC(x)                       (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_FRAC_SHIFT)) & PCC_CLKCFG_FRAC_MASK)

#define PCC_CLKCFG_PCS_MASK                      (0x7000000U)
#define PCC_CLKCFG_PCS_SHIFT                     (24U)
/*! PCS - Peripheral Clock Source Select
 *  0b000..Clock is off.
 *  0b001..Clock option 1
 *  0b010..Clock option 2
 *  0b011..Clock option 3
 *  0b100..Clock option 4
 *  0b101..Clock option 5
 *  0b110..Clock option 6
 *  0b111..Clock option 7
 */
#define PCC_CLKCFG_PCS(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PCS_SHIFT)) & PCC_CLKCFG_PCS_MASK)

#define PCC_CLKCFG_CGC_MASK                      (0x40000000U)
#define PCC_CLKCFG_CGC_SHIFT                     (30U)
/*! CGC - Clock Gate Control
 *  0b0..Disables the clock. The current clock selection and divider options are not locked and can be modified.
 *  0b1..Enables the clock. The current clock selection and divider options are locked and cannot be modified.
 */
#define PCC_CLKCFG_CGC(x)                        (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_CGC_SHIFT)) & PCC_CLKCFG_CGC_MASK)

#define PCC_CLKCFG_PR_MASK                       (0x80000000U)
#define PCC_CLKCFG_PR_SHIFT                      (31U)
/*! PR - Present
 *  0b0..Peripheral is not present.
 *  0b1..Peripheral is present.
 */
#define PCC_CLKCFG_PR(x)                         (((uint32_t)(((uint32_t)(x)) << PCC_CLKCFG_PR_SHIFT)) & PCC_CLKCFG_PR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PCC_Register_Masks */

#define PCC_INSTANCE_MASK      0xF
#define PCC_INSTANCE_SHIFT     12
#define PCC_PERIPHERAL_MASK    0xFFF
#define PCC_PERIPHERAL_SHIFT   0
#define PCC_INSTANCE_0         0

#define PCC_DMA0_INDEX                           8
#define PCC_FLASH_INDEX                          32
#define PCC_DMAMUX0_INDEX                        33
#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_CRC_INDEX                            50
#define PCC_LPIT0_INDEX                          55
#define PCC_FLEXTMR0_INDEX                       56
#define PCC_FLEXTMR1_INDEX                       57
#define PCC_FLEXTMR2_INDEX                       58
#define PCC_ADC0_INDEX                           59
#define PCC_RTC_INDEX                            61
#define PCC_LPTMR0_INDEX                         64
#define PCC_TSI0_INDEX                           69
#define PCC_TSI1_INDEX                           71
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_PWT_INDEX                            86
#define PCC_FLEXIO_INDEX                         90
#define PCC_EWM_INDEX                            97
#define PCC_FLEXIOTRIG0_INDEX                    98
#define PCC_FLEXIOTRIG1_INDEX                    99
#define PCC_LPI2C0_INDEX                         102
#define PCC_LPI2C1_INDEX                         103
#define PCC_LPUART0_INDEX                        106
#define PCC_LPUART1_INDEX                        107
#define PCC_LPUART2_INDEX                        108
#define PCC_UART0_INDEX                          109
#define PCC_UART1_INDEX                          110
#define PCC_CMP0_INDEX                           115


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */


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


#endif  /* PERI_PCC_H_ */

