/*
** ###################################################################
**     Processors:          KW47B42Z83AFTA_cm33_core0
**                          KW47B42Z83AFTA_cm33_core1
**                          KW47B42Z96AFTA_cm33_core0
**                          KW47B42Z96AFTA_cm33_core1
**                          KW47B42Z97AFTA_cm33_core0
**                          KW47B42Z97AFTA_cm33_core1
**                          KW47B42ZB2AFTA_cm33_core0
**                          KW47B42ZB2AFTA_cm33_core1
**                          KW47B42ZB3AFTA_cm33_core0
**                          KW47B42ZB3AFTA_cm33_core1
**                          KW47B42ZB6AFTA_cm33_core0
**                          KW47B42ZB6AFTA_cm33_core1
**                          KW47B42ZB7AFTA_cm33_core0
**                          KW47B42ZB7AFTA_cm33_core1
**                          KW47Z42082AFTA
**                          KW47Z42092AFTA
**                          KW47Z420B2AFTA
**                          KW47Z420B3AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
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
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VREF.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VREF
 *
 * CMSIS Peripheral Access Layer for VREF
 */

#if !defined(PERI_VREF_H_)
#define PERI_VREF_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW47B42Z83AFTA_cm33_core0))
#include "KW47B42Z83_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z83AFTA_cm33_core1))
#include "KW47B42Z83_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core0))
#include "KW47B42Z96_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core1))
#include "KW47B42Z96_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core0))
#include "KW47B42Z97_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core1))
#include "KW47B42Z97_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core0))
#include "KW47B42ZB2_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core1))
#include "KW47B42ZB2_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core0))
#include "KW47B42ZB3_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core1))
#include "KW47B42ZB3_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core0))
#include "KW47B42ZB6_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core1))
#include "KW47B42ZB6_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0))
#include "KW47B42ZB7_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1))
#include "KW47B42ZB7_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47Z42082AFTA))
#include "KW47Z42082_COMMON.h"
#elif (defined(CPU_KW47Z42092AFTA))
#include "KW47Z42092_COMMON.h"
#elif (defined(CPU_KW47Z420B2AFTA))
#include "KW47Z420B2_COMMON.h"
#elif (defined(CPU_KW47Z420B3AFTA))
#include "KW47Z420B3_COMMON.h"
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
  __IO uint32_t CSR;                               /**< Control and Status, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t UTRIM;                             /**< User Trim, offset: 0x10 */
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
/*! FEATURE - Feature Specification Number */
#define VREF_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_VERID_FEATURE_SHIFT)) & VREF_VERID_FEATURE_MASK)

#define VREF_VERID_MINOR_MASK                    (0xFF0000U)
#define VREF_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define VREF_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_VERID_MINOR_SHIFT)) & VREF_VERID_MINOR_MASK)

#define VREF_VERID_MAJOR_MASK                    (0xFF000000U)
#define VREF_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define VREF_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_VERID_MAJOR_SHIFT)) & VREF_VERID_MAJOR_MASK)
/*! @} */

/*! @name CSR - Control and Status */
/*! @{ */

#define VREF_CSR_HCBGEN_MASK                     (0x1U)
#define VREF_CSR_HCBGEN_SHIFT                    (0U)
/*! HCBGEN - HC Bandgap Enabled
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_HCBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_HCBGEN_SHIFT)) & VREF_CSR_HCBGEN_MASK)

#define VREF_CSR_LPBGEN_MASK                     (0x2U)
#define VREF_CSR_LPBGEN_SHIFT                    (1U)
/*! LPBGEN - Low-Power Bandgap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_LPBGEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_LPBGEN_SHIFT)) & VREF_CSR_LPBGEN_MASK)

#define VREF_CSR_LPBG_BUF_EN_MASK                (0x4U)
#define VREF_CSR_LPBG_BUF_EN_SHIFT               (2U)
/*! LPBG_BUF_EN - Low-Power Bandgap Buffer Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_LPBG_BUF_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VREF_CSR_LPBG_BUF_EN_SHIFT)) & VREF_CSR_LPBG_BUF_EN_MASK)

#define VREF_CSR_CHOPEN_MASK                     (0x8U)
#define VREF_CSR_CHOPEN_SHIFT                    (3U)
/*! CHOPEN - Chop Oscillator Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_CHOPEN(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_CHOPEN_SHIFT)) & VREF_CSR_CHOPEN_MASK)

#define VREF_CSR_ICOMPEN_MASK                    (0x10U)
#define VREF_CSR_ICOMPEN_SHIFT                   (4U)
/*! ICOMPEN - Current Compensation Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_ICOMPEN(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_CSR_ICOMPEN_SHIFT)) & VREF_CSR_ICOMPEN_MASK)

#define VREF_CSR_REGEN_MASK                      (0x20U)
#define VREF_CSR_REGEN_SHIFT                     (5U)
/*! REGEN - Regulator Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_REGEN(x)                        (((uint32_t)(((uint32_t)(x)) << VREF_CSR_REGEN_SHIFT)) & VREF_CSR_REGEN_MASK)

#define VREF_CSR_REFCHSELN_EN_MASK               (0x40U)
#define VREF_CSR_REFCHSELN_EN_SHIFT              (6U)
/*! REFCHSELN_EN - Reference Channel Select Negative Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_REFCHSELN_EN(x)                 (((uint32_t)(((uint32_t)(x)) << VREF_CSR_REFCHSELN_EN_SHIFT)) & VREF_CSR_REFCHSELN_EN_MASK)

#define VREF_CSR_REFCHSELP_EN_MASK               (0x80U)
#define VREF_CSR_REFCHSELP_EN_SHIFT              (7U)
/*! REFCHSELP_EN - Reference Channel Select Positive Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_REFCHSELP_EN(x)                 (((uint32_t)(((uint32_t)(x)) << VREF_CSR_REFCHSELP_EN_SHIFT)) & VREF_CSR_REFCHSELP_EN_MASK)

#define VREF_CSR_HI_PWR_LV_MASK                  (0x800U)
#define VREF_CSR_HI_PWR_LV_SHIFT                 (11U)
/*! HI_PWR_LV - High-Power Level
 *  0b0..Low-power
 *  0b1..High-power
 */
#define VREF_CSR_HI_PWR_LV(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_CSR_HI_PWR_LV_SHIFT)) & VREF_CSR_HI_PWR_LV_MASK)

#define VREF_CSR_BUF21EN_MASK                    (0x10000U)
#define VREF_CSR_BUF21EN_SHIFT                   (16U)
/*! BUF21EN - Internal Buffer21 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VREF_CSR_BUF21EN(x)                      (((uint32_t)(((uint32_t)(x)) << VREF_CSR_BUF21EN_SHIFT)) & VREF_CSR_BUF21EN_MASK)

#define VREF_CSR_VREFST_MASK                     (0x80000000U)
#define VREF_CSR_VREFST_SHIFT                    (31U)
/*! VREFST - Internal HC Voltage Reference Stable
 *  0b0..Disabled and unstable
 *  0b1..Stable
 */
#define VREF_CSR_VREFST(x)                       (((uint32_t)(((uint32_t)(x)) << VREF_CSR_VREFST_SHIFT)) & VREF_CSR_VREFST_MASK)
/*! @} */

/*! @name UTRIM - User Trim */
/*! @{ */

#define VREF_UTRIM_TRIM2V1_MASK                  (0xFU)
#define VREF_UTRIM_TRIM2V1_SHIFT                 (0U)
/*! TRIM2V1 - VREF 2.1 V Trim */
#define VREF_UTRIM_TRIM2V1(x)                    (((uint32_t)(((uint32_t)(x)) << VREF_UTRIM_TRIM2V1_SHIFT)) & VREF_UTRIM_TRIM2V1_MASK)

#define VREF_UTRIM_VREFTRIM_MASK                 (0x3F00U)
#define VREF_UTRIM_VREFTRIM_SHIFT                (8U)
/*! VREFTRIM - VREF Trim */
#define VREF_UTRIM_VREFTRIM(x)                   (((uint32_t)(((uint32_t)(x)) << VREF_UTRIM_VREFTRIM_SHIFT)) & VREF_UTRIM_VREFTRIM_MASK)
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

