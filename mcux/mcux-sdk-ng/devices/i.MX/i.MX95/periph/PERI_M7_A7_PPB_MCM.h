/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for M7_A7_PPB_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file M7_A7_PPB_MCM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for M7_A7_PPB_MCM
 *
 * CMSIS Peripheral Access Layer for M7_A7_PPB_MCM
 */

#if !defined(M7_A7_PPB_MCM_H_)
#define M7_A7_PPB_MCM_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- M7_A7_PPB_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_A7_PPB_MCM_Peripheral_Access_Layer M7_A7_PPB_MCM Peripheral Access Layer
 * @{
 */

/** M7_A7_PPB_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
  __IO uint32_t CFGSTCALIB;                        /**< SysTick Calibration Register, offset: 0x14 */
  __IO uint32_t PID;                               /**< Process ID, offset: 0x18 */
} M7_A7_PPB_MCM_Type;

/* ----------------------------------------------------------------------------
   -- M7_A7_PPB_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_A7_PPB_MCM_Register_Masks M7_A7_PPB_MCM Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define M7_A7_PPB_MCM_ISCR_WABS_MASK             (0x20U)
#define M7_A7_PPB_MCM_ISCR_WABS_SHIFT            (5U)
/*! WABS - Write Abort on Slave
 *  0b0..No abort
 *  0b1..Abort
 */
#define M7_A7_PPB_MCM_ISCR_WABS(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_WABS_SHIFT)) & M7_A7_PPB_MCM_ISCR_WABS_MASK)

#define M7_A7_PPB_MCM_ISCR_WABSO_MASK            (0x40U)
#define M7_A7_PPB_MCM_ISCR_WABSO_SHIFT           (6U)
/*! WABSO - Write Abort on Slave Overrun
 *  0b0..No write abort overrun
 *  0b1..Write abort overrun occurred
 */
#define M7_A7_PPB_MCM_ISCR_WABSO(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_WABSO_SHIFT)) & M7_A7_PPB_MCM_ISCR_WABSO_MASK)

#define M7_A7_PPB_MCM_ISCR_FIOC_MASK             (0x100U)
#define M7_A7_PPB_MCM_ISCR_FIOC_SHIFT            (8U)
/*! FIOC - FPU Invalid Operation interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FIOC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIOC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIOC_MASK)

#define M7_A7_PPB_MCM_ISCR_FDZC_MASK             (0x200U)
#define M7_A7_PPB_MCM_ISCR_FDZC_SHIFT            (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FDZC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FDZC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FDZC_MASK)

#define M7_A7_PPB_MCM_ISCR_FOFC_MASK             (0x400U)
#define M7_A7_PPB_MCM_ISCR_FOFC_SHIFT            (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FOFC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FOFC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FOFC_MASK)

#define M7_A7_PPB_MCM_ISCR_FUFC_MASK             (0x800U)
#define M7_A7_PPB_MCM_ISCR_FUFC_SHIFT            (11U)
/*! FUFC - FPU Underflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FUFC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FUFC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FUFC_MASK)

#define M7_A7_PPB_MCM_ISCR_FIXC_MASK             (0x1000U)
#define M7_A7_PPB_MCM_ISCR_FIXC_SHIFT            (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FIXC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIXC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIXC_MASK)

#define M7_A7_PPB_MCM_ISCR_FIDC_MASK             (0x8000U)
#define M7_A7_PPB_MCM_ISCR_FIDC_SHIFT            (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_A7_PPB_MCM_ISCR_FIDC(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIDC_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIDC_MASK)

#define M7_A7_PPB_MCM_ISCR_WABE_MASK             (0x200000U)
#define M7_A7_PPB_MCM_ISCR_WABE_SHIFT            (21U)
/*! WABE - TCM Write Abort Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_WABE(x)               (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_WABE_SHIFT)) & M7_A7_PPB_MCM_ISCR_WABE_MASK)

#define M7_A7_PPB_MCM_ISCR_FIOCE_MASK            (0x1000000U)
#define M7_A7_PPB_MCM_ISCR_FIOCE_SHIFT           (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FIOCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIOCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIOCE_MASK)

#define M7_A7_PPB_MCM_ISCR_FDZCE_MASK            (0x2000000U)
#define M7_A7_PPB_MCM_ISCR_FDZCE_SHIFT           (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FDZCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FDZCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FDZCE_MASK)

#define M7_A7_PPB_MCM_ISCR_FOFCE_MASK            (0x4000000U)
#define M7_A7_PPB_MCM_ISCR_FOFCE_SHIFT           (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FOFCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FOFCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FOFCE_MASK)

#define M7_A7_PPB_MCM_ISCR_FUFCE_MASK            (0x8000000U)
#define M7_A7_PPB_MCM_ISCR_FUFCE_SHIFT           (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FUFCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FUFCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FUFCE_MASK)

#define M7_A7_PPB_MCM_ISCR_FIXCE_MASK            (0x10000000U)
#define M7_A7_PPB_MCM_ISCR_FIXCE_SHIFT           (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FIXCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIXCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIXCE_MASK)

#define M7_A7_PPB_MCM_ISCR_FIDCE_MASK            (0x80000000U)
#define M7_A7_PPB_MCM_ISCR_FIDCE_SHIFT           (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_A7_PPB_MCM_ISCR_FIDCE(x)              (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_ISCR_FIDCE_SHIFT)) & M7_A7_PPB_MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name CFGSTCALIB - SysTick Calibration Register */
/*! @{ */

#define M7_A7_PPB_MCM_CFGSTCALIB_TENMS_MASK      (0xFFFFFFU)
#define M7_A7_PPB_MCM_CFGSTCALIB_TENMS_SHIFT     (0U)
/*! TENMS - Ten milliseconds */
#define M7_A7_PPB_MCM_CFGSTCALIB_TENMS(x)        (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_CFGSTCALIB_TENMS_SHIFT)) & M7_A7_PPB_MCM_CFGSTCALIB_TENMS_MASK)

#define M7_A7_PPB_MCM_CFGSTCALIB_SKEW_MASK       (0x1000000U)
#define M7_A7_PPB_MCM_CFGSTCALIB_SKEW_SHIFT      (24U)
/*! SKEW - Clock Skew
 *  0b0..No clock skew
 *  0b1..Having clock skew
 */
#define M7_A7_PPB_MCM_CFGSTCALIB_SKEW(x)         (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_CFGSTCALIB_SKEW_SHIFT)) & M7_A7_PPB_MCM_CFGSTCALIB_SKEW_MASK)

#define M7_A7_PPB_MCM_CFGSTCALIB_NOREF_MASK      (0x2000000U)
#define M7_A7_PPB_MCM_CFGSTCALIB_NOREF_SHIFT     (25U)
/*! NOREF - No Reference Clock */
#define M7_A7_PPB_MCM_CFGSTCALIB_NOREF(x)        (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_CFGSTCALIB_NOREF_SHIFT)) & M7_A7_PPB_MCM_CFGSTCALIB_NOREF_MASK)
/*! @} */

/*! @name PID - Process ID */
/*! @{ */

#define M7_A7_PPB_MCM_PID_PID_MASK               (0xFFU)
#define M7_A7_PPB_MCM_PID_PID_SHIFT              (0U)
/*! PID - Process ID */
#define M7_A7_PPB_MCM_PID_PID(x)                 (((uint32_t)(((uint32_t)(x)) << M7_A7_PPB_MCM_PID_PID_SHIFT)) & M7_A7_PPB_MCM_PID_PID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group M7_A7_PPB_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group M7_A7_PPB_MCM_Peripheral_Access_Layer */


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


#endif  /* M7_A7_PPB_MCM_H_ */

