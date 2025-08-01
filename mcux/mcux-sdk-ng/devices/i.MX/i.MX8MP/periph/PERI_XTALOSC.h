/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XTALOSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XTALOSC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XTALOSC
 *
 * CMSIS Peripheral Access Layer for XTALOSC
 */

#if !defined(PERI_XTALOSC_H_)
#define PERI_XTALOSC_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- XTALOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XTALOSC_Peripheral_Access_Layer XTALOSC Peripheral Access Layer
 * @{
 */

/** XTALOSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SYS_OSCNML_CTL0;                   /**< OSC Normal Clock Generation Control Register0, offset: 0x0 */
  __IO uint32_t SYS_OSCNML_CTL1;                   /**< OSC Normal Clock Generation Control Register1, offset: 0x4 */
} XTALOSC_Type;

/* ----------------------------------------------------------------------------
   -- XTALOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XTALOSC_Register_Masks XTALOSC Register Masks
 * @{
 */

/*! @name SYS_OSCNML_CTL0 - OSC Normal Clock Generation Control Register0 */
/*! @{ */

#define XTALOSC_SYS_OSCNML_CTL0_SF0_MASK         (0x1U)
#define XTALOSC_SYS_OSCNML_CTL0_SF0_SHIFT        (0U)
#define XTALOSC_SYS_OSCNML_CTL0_SF0(x)           (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL0_SF0_SHIFT)) & XTALOSC_SYS_OSCNML_CTL0_SF0_MASK)

#define XTALOSC_SYS_OSCNML_CTL0_SF1_MASK         (0x2U)
#define XTALOSC_SYS_OSCNML_CTL0_SF1_SHIFT        (1U)
#define XTALOSC_SYS_OSCNML_CTL0_SF1(x)           (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL0_SF1_SHIFT)) & XTALOSC_SYS_OSCNML_CTL0_SF1_MASK)

#define XTALOSC_SYS_OSCNML_CTL0_SP_MASK          (0x4U)
#define XTALOSC_SYS_OSCNML_CTL0_SP_SHIFT         (2U)
#define XTALOSC_SYS_OSCNML_CTL0_SP(x)            (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL0_SP_SHIFT)) & XTALOSC_SYS_OSCNML_CTL0_SP_MASK)

#define XTALOSC_SYS_OSCNML_CTL0_RTO_MASK         (0x10U)
#define XTALOSC_SYS_OSCNML_CTL0_RTO_SHIFT        (4U)
#define XTALOSC_SYS_OSCNML_CTL0_RTO(x)           (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL0_RTO_SHIFT)) & XTALOSC_SYS_OSCNML_CTL0_RTO_MASK)

#define XTALOSC_SYS_OSCNML_CTL0_EN_MASK          (0x80000000U)
#define XTALOSC_SYS_OSCNML_CTL0_EN_SHIFT         (31U)
#define XTALOSC_SYS_OSCNML_CTL0_EN(x)            (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL0_EN_SHIFT)) & XTALOSC_SYS_OSCNML_CTL0_EN_MASK)
/*! @} */

/*! @name SYS_OSCNML_CTL1 - OSC Normal Clock Generation Control Register1 */
/*! @{ */

#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_OVERRIDE_MASK (0x2U)
#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_OVERRIDE_SHIFT (1U)
#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_OVERRIDE_SHIFT)) & XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_OVERRIDE_MASK)

#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_MASK     (0x4U)
#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_SHIFT    (2U)
#define XTALOSC_SYS_OSCNML_CTL1_CLK_CKE(x)       (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_SHIFT)) & XTALOSC_SYS_OSCNML_CTL1_CLK_CKE_MASK)

#define XTALOSC_SYS_OSCNML_CTL1_LOCK_COUNT_MASK  (0xFF0U)
#define XTALOSC_SYS_OSCNML_CTL1_LOCK_COUNT_SHIFT (4U)
#define XTALOSC_SYS_OSCNML_CTL1_LOCK_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << XTALOSC_SYS_OSCNML_CTL1_LOCK_COUNT_SHIFT)) & XTALOSC_SYS_OSCNML_CTL1_LOCK_COUNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XTALOSC_Register_Masks */


/*!
 * @}
 */ /* end of group XTALOSC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_XTALOSC_H_ */

