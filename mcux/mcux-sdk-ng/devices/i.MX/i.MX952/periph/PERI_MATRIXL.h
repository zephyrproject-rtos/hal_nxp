/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for matrixl
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_matrixl.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for matrixl
 *
 * CMSIS Peripheral Access Layer for matrixl
 */

#if !defined(PERI_MATRIXL_H_)
#define PERI_MATRIXL_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- matrixl Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrixl_Peripheral_Access_Layer matrixl Peripheral Access Layer
 * @{
 */

/** matrixl - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t CONTR;                             /**< Control, offset: 0xC */
  __IO uint32_t RED0;                              /**< Red0, offset: 0x10 */
  __IO uint32_t RED1;                              /**< Red1, offset: 0x14 */
  __IO uint32_t GREEN0;                            /**< Green0, offset: 0x18 */
  __IO uint32_t GREEN1;                            /**< Green1, offset: 0x1C */
  __IO uint32_t BLUE0;                             /**< Blue0, offset: 0x20 */
  __IO uint32_t BLUE1;                             /**< Blue1, offset: 0x24 */
} matrixl_Type;

/* ----------------------------------------------------------------------------
   -- matrixl Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup matrixl_Register_Masks matrixl Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define matrixl_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define matrixl_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define matrixl_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << matrixl_LU_LkUn_SHIFT)) & matrixl_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define matrixl_LOCKS_LkSus_MASK                 (0x1U)
#define matrixl_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define matrixl_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << matrixl_LOCKS_LkSus_SHIFT)) & matrixl_LOCKS_LkSus_MASK)

#define matrixl_LOCKS_PriSt_MASK                 (0x10U)
#define matrixl_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define matrixl_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << matrixl_LOCKS_PriSt_SHIFT)) & matrixl_LOCKS_PriSt_MASK)

#define matrixl_LOCKS_FreezeS_MASK               (0x100U)
#define matrixl_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define matrixl_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << matrixl_LOCKS_FreezeS_SHIFT)) & matrixl_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define matrixl_STATCON_ShdEn_MASK               (0x1U)
#define matrixl_STATCON_ShdEn_SHIFT              (0U)
/*! ShdEn - ShdEn */
#define matrixl_STATCON_ShdEn(x)                 (((uint32_t)(((uint32_t)(x)) << matrixl_STATCON_ShdEn_SHIFT)) & matrixl_STATCON_ShdEn_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define matrixl_CONTR_MODE2_MASK                 (0x3U)
#define matrixl_CONTR_MODE2_SHIFT                (0U)
/*! MODE2 - MODE
 *  0b00..Module in neutral mode, input data is bypassed
 *  0b01..Module in matrix mode, input data is multiplied with matrix values
 *  0b10..Reserved, do not use
 *  0b11..Reserved, do not use
 */
#define matrixl_CONTR_MODE2(x)                   (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_MODE2_SHIFT)) & matrixl_CONTR_MODE2_MASK)

#define matrixl_CONTR_makinen_MASK               (0x1000000U)
#define matrixl_CONTR_makinen_SHIFT              (24U)
/*! makinen - maskin_en
 *  0b0..disable external masking.
 *  0b1..enable external masking.
 */
#define matrixl_CONTR_makinen(x)                 (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_makinen_SHIFT)) & matrixl_CONTR_makinen_MASK)

#define matrixl_CONTR_makinsel_MASK              (0x2000000U)
#define matrixl_CONTR_makinsel_SHIFT             (25U)
/*! makinsel - maskin_sel
 *  0b0..mask signal 0 is used.
 *  0b1..mask signal 1 is used.
 */
#define matrixl_CONTR_makinsel(x)                (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_makinsel_SHIFT)) & matrixl_CONTR_makinsel_MASK)

#define matrixl_CONTR_makininv_MASK              (0x4000000U)
#define matrixl_CONTR_makininv_SHIFT             (26U)
/*! makininv - maskin_inv
 *  0b0..bypassed when the related mask input signal is high.
 *  0b1..bypassed when the related mask input signal is low.
 */
#define matrixl_CONTR_makininv(x)                (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_makininv_SHIFT)) & matrixl_CONTR_makininv_MASK)

#define matrixl_CONTR_pxwinon0_MASK              (0x10000000U)
#define matrixl_CONTR_pxwinon0_SHIFT             (28U)
/*! pxwinon0 - pixwinon
 *  0b0..disable internal masking.
 *  0b1..enable internal masking.
 */
#define matrixl_CONTR_pxwinon0(x)                (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_pxwinon0_SHIFT)) & matrixl_CONTR_pxwinon0_MASK)

#define matrixl_CONTR_pxwininv_MASK              (0x20000000U)
#define matrixl_CONTR_pxwininv_SHIFT             (29U)
/*! pxwininv - pixwin_inv
 *  0b0..input pixels inside the defined window will be bypassed.
 *  0b1..input pixels outside the defined window will be bypassed.
 */
#define matrixl_CONTR_pxwininv(x)                (((uint32_t)(((uint32_t)(x)) << matrixl_CONTR_pxwininv_SHIFT)) & matrixl_CONTR_pxwininv_MASK)
/*! @} */

/*! @name RED0 - Red0 */
/*! @{ */

#define matrixl_RED0_A11_MASK                    (0x1FFFU)
#define matrixl_RED0_A11_SHIFT                   (0U)
/*! A11 - A11 */
#define matrixl_RED0_A11(x)                      (((uint32_t)(((uint32_t)(x)) << matrixl_RED0_A11_SHIFT)) & matrixl_RED0_A11_MASK)

#define matrixl_RED0_A12_MASK                    (0x1FFF0000U)
#define matrixl_RED0_A12_SHIFT                   (16U)
/*! A12 - A12 */
#define matrixl_RED0_A12(x)                      (((uint32_t)(((uint32_t)(x)) << matrixl_RED0_A12_SHIFT)) & matrixl_RED0_A12_MASK)
/*! @} */

/*! @name RED1 - Red1 */
/*! @{ */

#define matrixl_RED1_A13_MASK                    (0x1FFFU)
#define matrixl_RED1_A13_SHIFT                   (0U)
/*! A13 - A13 */
#define matrixl_RED1_A13(x)                      (((uint32_t)(((uint32_t)(x)) << matrixl_RED1_A13_SHIFT)) & matrixl_RED1_A13_MASK)
/*! @} */

/*! @name GREEN0 - Green0 */
/*! @{ */

#define matrixl_GREEN0_A21_MASK                  (0x1FFFU)
#define matrixl_GREEN0_A21_SHIFT                 (0U)
/*! A21 - A21 */
#define matrixl_GREEN0_A21(x)                    (((uint32_t)(((uint32_t)(x)) << matrixl_GREEN0_A21_SHIFT)) & matrixl_GREEN0_A21_MASK)

#define matrixl_GREEN0_A22_MASK                  (0x1FFF0000U)
#define matrixl_GREEN0_A22_SHIFT                 (16U)
/*! A22 - A22 */
#define matrixl_GREEN0_A22(x)                    (((uint32_t)(((uint32_t)(x)) << matrixl_GREEN0_A22_SHIFT)) & matrixl_GREEN0_A22_MASK)
/*! @} */

/*! @name GREEN1 - Green1 */
/*! @{ */

#define matrixl_GREEN1_A23_MASK                  (0x1FFFU)
#define matrixl_GREEN1_A23_SHIFT                 (0U)
/*! A23 - A23 */
#define matrixl_GREEN1_A23(x)                    (((uint32_t)(((uint32_t)(x)) << matrixl_GREEN1_A23_SHIFT)) & matrixl_GREEN1_A23_MASK)
/*! @} */

/*! @name BLUE0 - Blue0 */
/*! @{ */

#define matrixl_BLUE0_A31_MASK                   (0x1FFFU)
#define matrixl_BLUE0_A31_SHIFT                  (0U)
/*! A31 - A31 */
#define matrixl_BLUE0_A31(x)                     (((uint32_t)(((uint32_t)(x)) << matrixl_BLUE0_A31_SHIFT)) & matrixl_BLUE0_A31_MASK)

#define matrixl_BLUE0_A32_MASK                   (0x1FFF0000U)
#define matrixl_BLUE0_A32_SHIFT                  (16U)
/*! A32 - A32 */
#define matrixl_BLUE0_A32(x)                     (((uint32_t)(((uint32_t)(x)) << matrixl_BLUE0_A32_SHIFT)) & matrixl_BLUE0_A32_MASK)
/*! @} */

/*! @name BLUE1 - Blue1 */
/*! @{ */

#define matrixl_BLUE1_A33_MASK                   (0x1FFFU)
#define matrixl_BLUE1_A33_SHIFT                  (0U)
/*! A33 - A33 */
#define matrixl_BLUE1_A33(x)                     (((uint32_t)(((uint32_t)(x)) << matrixl_BLUE1_A33_SHIFT)) & matrixl_BLUE1_A33_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group matrixl_Register_Masks */


/*!
 * @}
 */ /* end of group matrixl_Peripheral_Access_Layer */


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


#endif  /* PERI_MATRIXL_H_ */

