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
**         CMSIS Peripheral Access Layer for locald12
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
 * @file PERI_locald12.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald12
 *
 * CMSIS Peripheral Access Layer for locald12
 */

#if !defined(PERI_LOCALD12_H_)
#define PERI_LOCALD12_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald12 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald12_Peripheral_Access_Layer locald12 Peripheral Access Layer
 * @{
 */

/** locald12 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDLEDR08;                          /**< ldledreg008, offset: 0x0 */
  __IO uint32_t LDLEDR09;                          /**< ldledreg009, offset: 0x4 */
  __IO uint32_t LDLEDR0A;                          /**< ldledreg00a, offset: 0x8 */
  __IO uint32_t LDLEDR0B;                          /**< ldledreg00b, offset: 0xC */
  __IO uint32_t LDLEDR0C;                          /**< ldledreg00c, offset: 0x10 */
  __IO uint32_t LDLEDR0D;                          /**< ldledreg00d, offset: 0x14 */
  __IO uint32_t LDLEDR0E;                          /**< ldledreg00e, offset: 0x18 */
} locald12_Type;

/* ----------------------------------------------------------------------------
   -- locald12 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald12_Register_Masks locald12 Register Masks
 * @{
 */

/*! @name LDLEDR08 - ldledreg008 */
/*! @{ */

#define locald12_LDLEDR08_disstart_MASK          (0xFFU)
#define locald12_LDLEDR08_disstart_SHIFT         (0U)
/*! disstart - disstart */
#define locald12_LDLEDR08_disstart(x)            (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR08_disstart_SHIFT)) & locald12_LDLEDR08_disstart_MASK)

#define locald12_LDLEDR08_disliml_MASK           (0xFF00U)
#define locald12_LDLEDR08_disliml_SHIFT          (8U)
/*! disliml - dislimit_l */
#define locald12_LDLEDR08_disliml(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR08_disliml_SHIFT)) & locald12_LDLEDR08_disliml_MASK)

#define locald12_LDLEDR08_disgain_MASK           (0xF0000U)
#define locald12_LDLEDR08_disgain_SHIFT          (16U)
/*! disgain - disgain */
#define locald12_LDLEDR08_disgain(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR08_disgain_SHIFT)) & locald12_LDLEDR08_disgain_MASK)
/*! @} */

/*! @name LDLEDR09 - ldledreg009 */
/*! @{ */

#define locald12_LDLEDR09_mixcoef_MASK           (0x1FFU)
#define locald12_LDLEDR09_mixcoef_SHIFT          (0U)
/*! mixcoef - mixcoef */
#define locald12_LDLEDR09_mixcoef(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR09_mixcoef_SHIFT)) & locald12_LDLEDR09_mixcoef_MASK)
/*! @} */

/*! @name LDLEDR0A - ldledreg00a */
/*! @{ */

#define locald12_LDLEDR0A_tapsel_MASK            (0x10000U)
#define locald12_LDLEDR0A_tapsel_SHIFT           (16U)
/*! tapsel - tapsel */
#define locald12_LDLEDR0A_tapsel(x)              (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0A_tapsel_SHIFT)) & locald12_LDLEDR0A_tapsel_MASK)
/*! @} */

/*! @name LDLEDR0B - ldledreg00b */
/*! @{ */

#define locald12_LDLEDR0B_ledadjo_MASK           (0x1U)
#define locald12_LDLEDR0B_ledadjo_SHIFT          (0U)
/*! ledadjo - ledadjon */
#define locald12_LDLEDR0B_ledadjo(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0B_ledadjo_SHIFT)) & locald12_LDLEDR0B_ledadjo_MASK)

#define locald12_LDLEDR0B_aplgon_MASK            (0x10U)
#define locald12_LDLEDR0B_aplgon_SHIFT           (4U)
/*! aplgon - aplgon */
#define locald12_LDLEDR0B_aplgon(x)              (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0B_aplgon_SHIFT)) & locald12_LDLEDR0B_aplgon_MASK)

#define locald12_LDLEDR0B_apllmon_MASK           (0x100U)
#define locald12_LDLEDR0B_apllmon_SHIFT          (8U)
/*! apllmon - apllmon */
#define locald12_LDLEDR0B_apllmon(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0B_apllmon_SHIFT)) & locald12_LDLEDR0B_apllmon_MASK)
/*! @} */

/*! @name LDLEDR0C - ldledreg00c */
/*! @{ */

#define locald12_LDLEDR0C_ledoffs_MASK           (0xFFFU)
#define locald12_LDLEDR0C_ledoffs_SHIFT          (0U)
/*! ledoffs - ledoffset */
#define locald12_LDLEDR0C_ledoffs(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0C_ledoffs_SHIFT)) & locald12_LDLEDR0C_ledoffs_MASK)

#define locald12_LDLEDR0C_ledgain_MASK           (0xFFF0000U)
#define locald12_LDLEDR0C_ledgain_SHIFT          (16U)
/*! ledgain - ledgain */
#define locald12_LDLEDR0C_ledgain(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0C_ledgain_SHIFT)) & locald12_LDLEDR0C_ledgain_MASK)
/*! @} */

/*! @name LDLEDR0D - ldledreg00d */
/*! @{ */

#define locald12_LDLEDR0D_aplgst_MASK            (0xFFU)
#define locald12_LDLEDR0D_aplgst_SHIFT           (0U)
/*! aplgst - aplgst */
#define locald12_LDLEDR0D_aplgst(x)              (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0D_aplgst_SHIFT)) & locald12_LDLEDR0D_aplgst_MASK)

#define locald12_LDLEDR0D_aplgg_MASK             (0xFF00U)
#define locald12_LDLEDR0D_aplgg_SHIFT            (8U)
/*! aplgg - aplgg */
#define locald12_LDLEDR0D_aplgg(x)               (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0D_aplgg_SHIFT)) & locald12_LDLEDR0D_aplgg_MASK)

#define locald12_LDLEDR0D_aplglmt_MASK           (0xFF0000U)
#define locald12_LDLEDR0D_aplglmt_SHIFT          (16U)
/*! aplglmt - aplglmt */
#define locald12_LDLEDR0D_aplglmt(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0D_aplglmt_SHIFT)) & locald12_LDLEDR0D_aplglmt_MASK)
/*! @} */

/*! @name LDLEDR0E - ldledreg00e */
/*! @{ */

#define locald12_LDLEDR0E_apllmst_MASK           (0xFFU)
#define locald12_LDLEDR0E_apllmst_SHIFT          (0U)
/*! apllmst - apllmst */
#define locald12_LDLEDR0E_apllmst(x)             (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0E_apllmst_SHIFT)) & locald12_LDLEDR0E_apllmst_MASK)

#define locald12_LDLEDR0E_apllmg_MASK            (0xFF00U)
#define locald12_LDLEDR0E_apllmg_SHIFT           (8U)
/*! apllmg - apllmg */
#define locald12_LDLEDR0E_apllmg(x)              (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0E_apllmg_SHIFT)) & locald12_LDLEDR0E_apllmg_MASK)

#define locald12_LDLEDR0E_apllmlmt_MASK          (0xFFF0000U)
#define locald12_LDLEDR0E_apllmlmt_SHIFT         (16U)
/*! apllmlmt - apllmlmt */
#define locald12_LDLEDR0E_apllmlmt(x)            (((uint32_t)(((uint32_t)(x)) << locald12_LDLEDR0E_apllmlmt_SHIFT)) & locald12_LDLEDR0E_apllmlmt_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald12_Register_Masks */


/*!
 * @}
 */ /* end of group locald12_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD12_H_ */

