/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for M7_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_M7_MCM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for M7_MCM
 *
 * CMSIS Peripheral Access Layer for M7_MCM
 */

#if !defined(PERI_M7_MCM_H_)
#define PERI_M7_MCM_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- M7_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_MCM_Peripheral_Access_Layer M7_MCM Peripheral Access Layer
 * @{
 */

/** M7_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
  __IO uint32_t CFGSTCALIB;                        /**< SysTick Calibration Register, offset: 0x14 */
  __IO uint32_t PID;                               /**< Process ID, offset: 0x18 */
} M7_MCM_Type;

/* ----------------------------------------------------------------------------
   -- M7_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup M7_MCM_Register_Masks M7_MCM Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define M7_MCM_ISCR_WABS_MASK                    (0x20U)
#define M7_MCM_ISCR_WABS_SHIFT                   (5U)
/*! WABS - Write Abort on Slave
 *  0b0..No abort
 *  0b1..Abort
 */
#define M7_MCM_ISCR_WABS(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_WABS_SHIFT)) & M7_MCM_ISCR_WABS_MASK)

#define M7_MCM_ISCR_WABSO_MASK                   (0x40U)
#define M7_MCM_ISCR_WABSO_SHIFT                  (6U)
/*! WABSO - Write Abort on Slave Overrun
 *  0b0..No write abort overrun
 *  0b1..Write abort overrun occurred
 */
#define M7_MCM_ISCR_WABSO(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_WABSO_SHIFT)) & M7_MCM_ISCR_WABSO_MASK)

#define M7_MCM_ISCR_FIOC_MASK                    (0x100U)
#define M7_MCM_ISCR_FIOC_SHIFT                   (8U)
/*! FIOC - FPU Invalid Operation interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FIOC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIOC_SHIFT)) & M7_MCM_ISCR_FIOC_MASK)

#define M7_MCM_ISCR_FDZC_MASK                    (0x200U)
#define M7_MCM_ISCR_FDZC_SHIFT                   (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FDZC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FDZC_SHIFT)) & M7_MCM_ISCR_FDZC_MASK)

#define M7_MCM_ISCR_FOFC_MASK                    (0x400U)
#define M7_MCM_ISCR_FOFC_SHIFT                   (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FOFC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FOFC_SHIFT)) & M7_MCM_ISCR_FOFC_MASK)

#define M7_MCM_ISCR_FUFC_MASK                    (0x800U)
#define M7_MCM_ISCR_FUFC_SHIFT                   (11U)
/*! FUFC - FPU Underflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FUFC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FUFC_SHIFT)) & M7_MCM_ISCR_FUFC_MASK)

#define M7_MCM_ISCR_FIXC_MASK                    (0x1000U)
#define M7_MCM_ISCR_FIXC_SHIFT                   (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FIXC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIXC_SHIFT)) & M7_MCM_ISCR_FIXC_MASK)

#define M7_MCM_ISCR_FIDC_MASK                    (0x8000U)
#define M7_MCM_ISCR_FIDC_SHIFT                   (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define M7_MCM_ISCR_FIDC(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIDC_SHIFT)) & M7_MCM_ISCR_FIDC_MASK)

#define M7_MCM_ISCR_WABE_MASK                    (0x200000U)
#define M7_MCM_ISCR_WABE_SHIFT                   (21U)
/*! WABE - TCM Write Abort Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_WABE(x)                      (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_WABE_SHIFT)) & M7_MCM_ISCR_WABE_MASK)

#define M7_MCM_ISCR_FIOCE_MASK                   (0x1000000U)
#define M7_MCM_ISCR_FIOCE_SHIFT                  (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FIOCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIOCE_SHIFT)) & M7_MCM_ISCR_FIOCE_MASK)

#define M7_MCM_ISCR_FDZCE_MASK                   (0x2000000U)
#define M7_MCM_ISCR_FDZCE_SHIFT                  (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FDZCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FDZCE_SHIFT)) & M7_MCM_ISCR_FDZCE_MASK)

#define M7_MCM_ISCR_FOFCE_MASK                   (0x4000000U)
#define M7_MCM_ISCR_FOFCE_SHIFT                  (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FOFCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FOFCE_SHIFT)) & M7_MCM_ISCR_FOFCE_MASK)

#define M7_MCM_ISCR_FUFCE_MASK                   (0x8000000U)
#define M7_MCM_ISCR_FUFCE_SHIFT                  (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FUFCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FUFCE_SHIFT)) & M7_MCM_ISCR_FUFCE_MASK)

#define M7_MCM_ISCR_FIXCE_MASK                   (0x10000000U)
#define M7_MCM_ISCR_FIXCE_SHIFT                  (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FIXCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIXCE_SHIFT)) & M7_MCM_ISCR_FIXCE_MASK)

#define M7_MCM_ISCR_FIDCE_MASK                   (0x80000000U)
#define M7_MCM_ISCR_FIDCE_SHIFT                  (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define M7_MCM_ISCR_FIDCE(x)                     (((uint32_t)(((uint32_t)(x)) << M7_MCM_ISCR_FIDCE_SHIFT)) & M7_MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name CFGSTCALIB - SysTick Calibration Register */
/*! @{ */

#define M7_MCM_CFGSTCALIB_TENMS_MASK             (0xFFFFFFU)
#define M7_MCM_CFGSTCALIB_TENMS_SHIFT            (0U)
/*! TENMS - Ten milliseconds */
#define M7_MCM_CFGSTCALIB_TENMS(x)               (((uint32_t)(((uint32_t)(x)) << M7_MCM_CFGSTCALIB_TENMS_SHIFT)) & M7_MCM_CFGSTCALIB_TENMS_MASK)

#define M7_MCM_CFGSTCALIB_SKEW_MASK              (0x1000000U)
#define M7_MCM_CFGSTCALIB_SKEW_SHIFT             (24U)
/*! SKEW - Clock Skew
 *  0b0..No clock skew
 *  0b1..Having clock skew
 */
#define M7_MCM_CFGSTCALIB_SKEW(x)                (((uint32_t)(((uint32_t)(x)) << M7_MCM_CFGSTCALIB_SKEW_SHIFT)) & M7_MCM_CFGSTCALIB_SKEW_MASK)

#define M7_MCM_CFGSTCALIB_NOREF_MASK             (0x2000000U)
#define M7_MCM_CFGSTCALIB_NOREF_SHIFT            (25U)
/*! NOREF - No Reference Clock */
#define M7_MCM_CFGSTCALIB_NOREF(x)               (((uint32_t)(((uint32_t)(x)) << M7_MCM_CFGSTCALIB_NOREF_SHIFT)) & M7_MCM_CFGSTCALIB_NOREF_MASK)
/*! @} */

/*! @name PID - Process ID */
/*! @{ */

#define M7_MCM_PID_PID_MASK                      (0xFFU)
#define M7_MCM_PID_PID_SHIFT                     (0U)
/*! PID - Process ID */
#define M7_MCM_PID_PID(x)                        (((uint32_t)(((uint32_t)(x)) << M7_MCM_PID_PID_SHIFT)) & M7_MCM_PID_PID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group M7_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group M7_MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_M7_MCM_H_ */

