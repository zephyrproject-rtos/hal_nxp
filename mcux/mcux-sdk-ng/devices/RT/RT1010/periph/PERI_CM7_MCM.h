/*
** ###################################################################
**     Processors:          MIMXRT1011CAE4A
**                          MIMXRT1011DAE5A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CM7_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-02-14)
**         Initial version.
**     - rev. 1.0 (2019-08-01)
**         Rev.0 Header GA
**     - rev. 1.1 (2019-08-06)
**         Update header files to align with IMXRT1010RM Rev.B.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1010RM Rev.1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CM7_MCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CM7_MCM
 *
 * CMSIS Peripheral Access Layer for CM7_MCM
 */

#if !defined(PERI_CM7_MCM_H_)
#define PERI_CM7_MCM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1011CAE4A) || defined(CPU_MIMXRT1011DAE5A))
#include "MIMXRT1011_COMMON.h"
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
   -- CM7_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CM7_MCM_Peripheral_Access_Layer CM7_MCM Peripheral Access Layer
 * @{
 */

/** CM7_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
} CM7_MCM_Type;

/* ----------------------------------------------------------------------------
   -- CM7_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CM7_MCM_Register_Masks CM7_MCM Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define CM7_MCM_ISCR_WABS_MASK                   (0x20U)
#define CM7_MCM_ISCR_WABS_SHIFT                  (5U)
/*! WABS - Write Abort on Slave
 *  0b0..No abort
 *  0b1..Abort
 */
#define CM7_MCM_ISCR_WABS(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_WABS_SHIFT)) & CM7_MCM_ISCR_WABS_MASK)

#define CM7_MCM_ISCR_WABSO_MASK                  (0x40U)
#define CM7_MCM_ISCR_WABSO_SHIFT                 (6U)
/*! WABSO - Write Abort on Slave Overrun
 *  0b0..No write abort overrun
 *  0b1..Write abort overrun occurred
 */
#define CM7_MCM_ISCR_WABSO(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_WABSO_SHIFT)) & CM7_MCM_ISCR_WABSO_MASK)

#define CM7_MCM_ISCR_FIOC_MASK                   (0x100U)
#define CM7_MCM_ISCR_FIOC_SHIFT                  (8U)
/*! FIOC - FPU Invalid Operation interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FIOC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIOC_SHIFT)) & CM7_MCM_ISCR_FIOC_MASK)

#define CM7_MCM_ISCR_FDZC_MASK                   (0x200U)
#define CM7_MCM_ISCR_FDZC_SHIFT                  (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FDZC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FDZC_SHIFT)) & CM7_MCM_ISCR_FDZC_MASK)

#define CM7_MCM_ISCR_FOFC_MASK                   (0x400U)
#define CM7_MCM_ISCR_FOFC_SHIFT                  (10U)
/*! FOFC - FPU Overflow interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FOFC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FOFC_SHIFT)) & CM7_MCM_ISCR_FOFC_MASK)

#define CM7_MCM_ISCR_FUFC_MASK                   (0x800U)
#define CM7_MCM_ISCR_FUFC_SHIFT                  (11U)
/*! FUFC - FPU Underflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FUFC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FUFC_SHIFT)) & CM7_MCM_ISCR_FUFC_MASK)

#define CM7_MCM_ISCR_FIXC_MASK                   (0x1000U)
#define CM7_MCM_ISCR_FIXC_SHIFT                  (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FIXC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIXC_SHIFT)) & CM7_MCM_ISCR_FIXC_MASK)

#define CM7_MCM_ISCR_FIDC_MASK                   (0x8000U)
#define CM7_MCM_ISCR_FIDC_SHIFT                  (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occured
 */
#define CM7_MCM_ISCR_FIDC(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIDC_SHIFT)) & CM7_MCM_ISCR_FIDC_MASK)

#define CM7_MCM_ISCR_WABE_MASK                   (0x200000U)
#define CM7_MCM_ISCR_WABE_SHIFT                  (21U)
/*! WABE - TCM Write Abort Interrupt enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_WABE(x)                     (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_WABE_SHIFT)) & CM7_MCM_ISCR_WABE_MASK)

#define CM7_MCM_ISCR_FIOCE_MASK                  (0x1000000U)
#define CM7_MCM_ISCR_FIOCE_SHIFT                 (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FIOCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIOCE_SHIFT)) & CM7_MCM_ISCR_FIOCE_MASK)

#define CM7_MCM_ISCR_FDZCE_MASK                  (0x2000000U)
#define CM7_MCM_ISCR_FDZCE_SHIFT                 (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FDZCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FDZCE_SHIFT)) & CM7_MCM_ISCR_FDZCE_MASK)

#define CM7_MCM_ISCR_FOFCE_MASK                  (0x4000000U)
#define CM7_MCM_ISCR_FOFCE_SHIFT                 (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FOFCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FOFCE_SHIFT)) & CM7_MCM_ISCR_FOFCE_MASK)

#define CM7_MCM_ISCR_FUFCE_MASK                  (0x8000000U)
#define CM7_MCM_ISCR_FUFCE_SHIFT                 (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FUFCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FUFCE_SHIFT)) & CM7_MCM_ISCR_FUFCE_MASK)

#define CM7_MCM_ISCR_FIXCE_MASK                  (0x10000000U)
#define CM7_MCM_ISCR_FIXCE_SHIFT                 (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FIXCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIXCE_SHIFT)) & CM7_MCM_ISCR_FIXCE_MASK)

#define CM7_MCM_ISCR_FIDCE_MASK                  (0x80000000U)
#define CM7_MCM_ISCR_FIDCE_SHIFT                 (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define CM7_MCM_ISCR_FIDCE(x)                    (((uint32_t)(((uint32_t)(x)) << CM7_MCM_ISCR_FIDCE_SHIFT)) & CM7_MCM_ISCR_FIDCE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CM7_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group CM7_MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CM7_MCM_H_ */

