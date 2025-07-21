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
**         CMSIS Peripheral Access Layer for VREF
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
 * @file PERI_VREF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VREF
 *
 * CMSIS Peripheral Access Layer for VREF
 */

#if !defined(PERI_VREF_H_)
#define PERI_VREF_H_                             /**< Symbol preventing repeated inclusion */

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
   -- VREF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Peripheral_Access_Layer VREF Peripheral Access Layer
 * @{
 */

/** VREF - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CSR;                               /**< Control and Status Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t UTRIM;                             /**< User Trim, offset: 0x10 */
       uint8_t RESERVED_2[8];
  __IO uint32_t TEST_UNLOCK;                       /**< Test Unlock, offset: 0x1C */
       uint8_t RESERVED_3[4];
  __IO uint32_t TRIM0;                             /**< Test Trim 0, offset: 0x24 */
} VREF_Type;

/* ----------------------------------------------------------------------------
   -- VREF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VREF_Register_Masks VREF Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VREF_VERID_FEATURE_MASK                  (0xFFFFU)
#define VREF_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - FEATURE */
#define VREF_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_VERID_FEATURE_SHIFT)) & VREF_VERID_FEATURE_MASK)

#define VREF_VERID_MINOR_MASK                    (0xFF0000U)
#define VREF_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - MINOR */
#define VREF_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_VERID_MINOR_SHIFT)) & VREF_VERID_MINOR_MASK)

#define VREF_VERID_MAJOR_MASK                    (0xFF000000U)
#define VREF_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - MAJOR */
#define VREF_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_VERID_MAJOR_SHIFT)) & VREF_VERID_MAJOR_MASK)
/*! @} */

/*! @name CSR - Control and Status Register */
/*! @{ */

#define VREF_CSR_HCBGEN_MASK                     (0x1U)
#define VREF_CSR_HCBGEN_SHIFT                    (0U)
/*! HCBGEN - High Accuracy Bandgap enabled
 *  0b0..HC Bandgap is disabled
 *  0b1..HC Bandgap is enabled
 */
#define VREF_CSR_HCBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_HCBGEN_SHIFT)) & VREF_CSR_HCBGEN_MASK)

#define VREF_CSR_LPBGEN_MASK                     (0x2U)
#define VREF_CSR_LPBGEN_SHIFT                    (1U)
/*! LPBGEN - Low Power Bandgap enable
 *  0b0..LP Bandgap is disabled
 *  0b1..LP Bandgap is enabled
 */
#define VREF_CSR_LPBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_LPBGEN_SHIFT)) & VREF_CSR_LPBGEN_MASK)

#define VREF_CSR_CHOPEN_MASK                     (0x8U)
#define VREF_CSR_CHOPEN_SHIFT                    (3U)
/*! CHOPEN - Chop oscillator enable. When set, the internal chopping operation is enabled and the
 *    internal analog offset will be minimized.
 *  0b0..Chop oscillator is disabled.
 *  0b1..Chop oscillator is enabled.
 */
#define VREF_CSR_CHOPEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_CHOPEN_SHIFT)) & VREF_CSR_CHOPEN_MASK)

#define VREF_CSR_ICOMPEN_MASK                    (0x10U)
#define VREF_CSR_ICOMPEN_SHIFT                   (4U)
/*! ICOMPEN - Second order curvature compensation enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define VREF_CSR_ICOMPEN(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_CSR_ICOMPEN_SHIFT)) & VREF_CSR_ICOMPEN_MASK)

#define VREF_CSR_REGEN_MASK                      (0x20U)
#define VREF_CSR_REGEN_SHIFT                     (5U)
/*! REGEN - Regulator enable
 *  0b0..Internal 1.75 V regulator is disabled.
 *  0b1..Internal 1.75 V regulator is enabled.
 */
#define VREF_CSR_REGEN(x)                        (((uint32_t)(((uint32_t)(x)) << VREF_CSR_REGEN_SHIFT)) & VREF_CSR_REGEN_MASK)

#define VREF_CSR_HI_PWR_LV_MASK                  (0x800U)
#define VREF_CSR_HI_PWR_LV_SHIFT                 (11U)
/*! HI_PWR_LV
 *  0b0..buffer is in low power mode
 *  0b1..buffer is in high power mode
 */
#define VREF_CSR_HI_PWR_LV(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_CSR_HI_PWR_LV_SHIFT)) & VREF_CSR_HI_PWR_LV_MASK)

#define VREF_CSR_BUF21EN_MASK                    (0x10000U)
#define VREF_CSR_BUF21EN_SHIFT                   (16U)
/*! Buf21EN - Internal buffer enable
 *  0b0..buffer is disabled
 *  0b1..buffer is enabled
 */
#define VREF_CSR_BUF21EN(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_CSR_BUF21EN_SHIFT)) & VREF_CSR_BUF21EN_MASK)

#define VREF_CSR_VREFST_MASK                     (0x80000000U)
#define VREF_CSR_VREFST_SHIFT                    (31U)
/*! VREFST - Internal High Accuracy Voltage Reference stable
 *  0b0..The module is disabled or not stable.
 *  0b1..The module is stable.
 */
#define VREF_CSR_VREFST(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_VREFST_SHIFT)) & VREF_CSR_VREFST_MASK)
/*! @} */

/*! @name UTRIM - User Trim */
/*! @{ */

#define VREF_UTRIM_VREFTRIM_MASK                 (0x3F00U)
#define VREF_UTRIM_VREFTRIM_SHIFT                (8U)
/*! VREFTRIM - VREF Trim bits
 *  0b000000..default-32*0.5*(4/3) mV
 *  0b100000..default
 *  0b111111..default+31*0.5*(4/3) mV
 *  *..see the value options above as example for calculation
 */
#define VREF_UTRIM_VREFTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << VREF_UTRIM_VREFTRIM_SHIFT)) & VREF_UTRIM_VREFTRIM_MASK)
/*! @} */

/*! @name TEST_UNLOCK - Test Unlock */
/*! @{ */

#define VREF_TEST_UNLOCK_TEST_UNLOCK_MASK        (0x1U)
#define VREF_TEST_UNLOCK_TEST_UNLOCK_SHIFT       (0U)
/*! TEST_UNLOCK - Test_unlock status bit
 *  0b0..Lock read/write into test register
 *  0b1..Unlock read/write into test register
 */
#define VREF_TEST_UNLOCK_TEST_UNLOCK(x)          (((uint32_t)(((uint32_t)(x)) << VREF_TEST_UNLOCK_TEST_UNLOCK_SHIFT)) & VREF_TEST_UNLOCK_TEST_UNLOCK_MASK)

#define VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_MASK  (0xFFFEU)
#define VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_SHIFT (1U)
/*! TEST_UNLOCK_VALUE - Test unlock value */
#define VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_SHIFT)) & VREF_TEST_UNLOCK_TEST_UNLOCK_VALUE_MASK)
/*! @} */

/*! @name TRIM0 - Test Trim 0 */
/*! @{ */

#define VREF_TRIM0_COMPLSB_MASK                  (0x7U)
#define VREF_TRIM0_COMPLSB_SHIFT                 (0U)
/*! COMPLSB - COMPLSB */
#define VREF_TRIM0_COMPLSB(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_COMPLSB_SHIFT)) & VREF_TRIM0_COMPLSB_MASK)

#define VREF_TRIM0_COMPMSB_MASK                  (0xE0U)
#define VREF_TRIM0_COMPMSB_SHIFT                 (5U)
/*! COMPMSB - COMPMSB */
#define VREF_TRIM0_COMPMSB(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_COMPMSB_SHIFT)) & VREF_TRIM0_COMPMSB_MASK)

#define VREF_TRIM0_BPLSB_MASK                    (0xF00U)
#define VREF_TRIM0_BPLSB_SHIFT                   (8U)
/*! BPLSB - BPLSB */
#define VREF_TRIM0_BPLSB(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_BPLSB_SHIFT)) & VREF_TRIM0_BPLSB_MASK)

#define VREF_TRIM0_BPMSB_MASK                    (0xE000U)
#define VREF_TRIM0_BPMSB_SHIFT                   (13U)
/*! BPMSB - BPMSB */
#define VREF_TRIM0_BPMSB(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_BPMSB_SHIFT)) & VREF_TRIM0_BPMSB_MASK)

#define VREF_TRIM0_CHOPOSCTRIM_MASK              (0xF0000U)
#define VREF_TRIM0_CHOPOSCTRIM_SHIFT             (16U)
/*! CHOPOSCTRIM - CHOPOSCTRIM */
#define VREF_TRIM0_CHOPOSCTRIM(x)                (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_CHOPOSCTRIM_SHIFT)) & VREF_TRIM0_CHOPOSCTRIM_MASK)

#define VREF_TRIM0_P7_TRIM_MASK                  (0xF000000U)
#define VREF_TRIM0_P7_TRIM_SHIFT                 (24U)
/*! P7_TRIM - P7_TRIM */
#define VREF_TRIM0_P7_TRIM(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_P7_TRIM_SHIFT)) & VREF_TRIM0_P7_TRIM_MASK)

#define VREF_TRIM0_FLIP_MASK                     (0x80000000U)
#define VREF_TRIM0_FLIP_SHIFT                    (31U)
/*! FLIP - Amplifier Polarity */
#define VREF_TRIM0_FLIP(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_TRIM0_FLIP_SHIFT)) & VREF_TRIM0_FLIP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VREF_Register_Masks */


/*!
 * @}
 */ /* end of group VREF_Peripheral_Access_Layer */


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


#endif  /* PERI_VREF_H_ */

