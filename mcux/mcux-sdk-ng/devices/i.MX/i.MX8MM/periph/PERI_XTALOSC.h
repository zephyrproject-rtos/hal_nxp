/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 4.0, 2019-02-18
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XTALOSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**
** ###################################################################
*/

/*!
 * @file XTALOSC.h
 * @version 4.0
 * @date 2019-02-18
 * @brief CMSIS Peripheral Access Layer for XTALOSC
 *
 * CMSIS Peripheral Access Layer for XTALOSC
 */

#if !defined(XTALOSC_H_)
#define XTALOSC_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* XTALOSC_H_ */

