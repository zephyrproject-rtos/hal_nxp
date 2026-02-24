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
**         CMSIS Peripheral Access Layer for locald14
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
 * @file PERI_locald14.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald14
 *
 * CMSIS Peripheral Access Layer for locald14
 */

#if !defined(PERI_LOCALD14_H_)
#define PERI_LOCALD14_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald14 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald14_Peripheral_Access_Layer locald14 Peripheral Access Layer
 * @{
 */

/** locald14 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDLED026;                          /**< ldledreg026, offset: 0x0 */
  __IO uint32_t LDLED027;                          /**< ldledreg027, offset: 0x4 */
  __IO uint32_t LDLED028;                          /**< ldledreg028, offset: 0x8 */
  __IO uint32_t LDLED029;                          /**< ldledreg029, offset: 0xC */
  __IO uint32_t LDLED02A;                          /**< ldledreg02a, offset: 0x10 */
  __IO uint32_t LDLED02B;                          /**< ldledreg02b, offset: 0x14 */
  __IO uint32_t LDLED02C;                          /**< ldledreg02c, offset: 0x18 */
  __IO uint32_t LDLED02D;                          /**< ldledreg02d, offset: 0x1C */
  __IO uint32_t LDLED02E;                          /**< ldledreg02e, offset: 0x20 */
  __IO uint32_t LDLED02F;                          /**< ldledreg02f, offset: 0x24 */
  __IO uint32_t LDLED030;                          /**< ldledreg030, offset: 0x28 */
  __IO uint32_t LDLED031;                          /**< ldledreg031, offset: 0x2C */
  __IO uint32_t LDLED032;                          /**< ldledreg032, offset: 0x30 */
  __IO uint32_t LDLED033;                          /**< ldledreg033, offset: 0x34 */
} locald14_Type;

/* ----------------------------------------------------------------------------
   -- locald14 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald14_Register_Masks locald14 Register Masks
 * @{
 */

/*! @name LDLED026 - ldledreg026 */
/*! @{ */

#define locald14_LDLED026_tfth2on_MASK           (0x1U)
#define locald14_LDLED026_tfth2on_SHIFT          (0U)
/*! tfth2on - tfth2on */
#define locald14_LDLED026_tfth2on(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED026_tfth2on_SHIFT)) & locald14_LDLED026_tfth2on_MASK)

#define locald14_LDLED026_stfcoef2_MASK          (0x3F0000U)
#define locald14_LDLED026_stfcoef2_SHIFT         (16U)
/*! stfcoef2 - stfcoef2 */
#define locald14_LDLED026_stfcoef2(x)            (((uint32_t)(((uint32_t)(x)) << locald14_LDLED026_stfcoef2_SHIFT)) & locald14_LDLED026_stfcoef2_MASK)

#define locald14_LDLED026_stfcoef1_MASK          (0x3F000000U)
#define locald14_LDLED026_stfcoef1_SHIFT         (24U)
/*! stfcoef1 - stfcoef1 */
#define locald14_LDLED026_stfcoef1(x)            (((uint32_t)(((uint32_t)(x)) << locald14_LDLED026_stfcoef1_SHIFT)) & locald14_LDLED026_stfcoef1_MASK)
/*! @} */

/*! @name LDLED027 - ldledreg027 */
/*! @{ */

#define locald14_LDLED027_tfmdon_MASK            (0x1U)
#define locald14_LDLED027_tfmdon_SHIFT           (0U)
/*! tfmdon - tfmdon */
#define locald14_LDLED027_tfmdon(x)              (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_tfmdon_SHIFT)) & locald14_LDLED027_tfmdon_MASK)

#define locald14_LDLED027_ldscene_MASK           (0x10U)
#define locald14_LDLED027_ldscene_SHIFT          (4U)
/*! ldscene - ldsceneon */
#define locald14_LDLED027_ldscene(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_ldscene_SHIFT)) & locald14_LDLED027_ldscene_MASK)

#define locald14_LDLED027_ldavesel_MASK          (0x20U)
#define locald14_LDLED027_ldavesel_SHIFT         (5U)
/*! ldavesel - ldavesel */
#define locald14_LDLED027_ldavesel(x)            (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_ldavesel_SHIFT)) & locald14_LDLED027_ldavesel_MASK)

#define locald14_LDLED027_tfth2_MASK             (0xFF00U)
#define locald14_LDLED027_tfth2_SHIFT            (8U)
/*! tfth2 - tfth2 */
#define locald14_LDLED027_tfth2(x)               (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_tfth2_SHIFT)) & locald14_LDLED027_tfth2_MASK)

#define locald14_LDLED027_tfth_MASK              (0xFF0000U)
#define locald14_LDLED027_tfth_SHIFT             (16U)
/*! tfth - tfth */
#define locald14_LDLED027_tfth(x)                (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_tfth_SHIFT)) & locald14_LDLED027_tfth_MASK)

#define locald14_LDLED027_tfcoefm_MASK           (0x3F000000U)
#define locald14_LDLED027_tfcoefm_SHIFT          (24U)
/*! tfcoefm - tfcoefm */
#define locald14_LDLED027_tfcoefm(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED027_tfcoefm_SHIFT)) & locald14_LDLED027_tfcoefm_MASK)
/*! @} */

/*! @name LDLED028 - ldledreg028 */
/*! @{ */

#define locald14_LDLED028_start_MASK             (0xFFU)
#define locald14_LDLED028_start_SHIFT            (0U)
/*! start - start */
#define locald14_LDLED028_start(x)               (((uint32_t)(((uint32_t)(x)) << locald14_LDLED028_start_SHIFT)) & locald14_LDLED028_start_MASK)

#define locald14_LDLED028_gain_MASK              (0xF00U)
#define locald14_LDLED028_gain_SHIFT             (8U)
/*! gain - gain */
#define locald14_LDLED028_gain(x)                (((uint32_t)(((uint32_t)(x)) << locald14_LDLED028_gain_SHIFT)) & locald14_LDLED028_gain_MASK)

#define locald14_LDLED028_limitl_MASK            (0x3F0000U)
#define locald14_LDLED028_limitl_SHIFT           (16U)
/*! limitl - limit_l */
#define locald14_LDLED028_limitl(x)              (((uint32_t)(((uint32_t)(x)) << locald14_LDLED028_limitl_SHIFT)) & locald14_LDLED028_limitl_MASK)

#define locald14_LDLED028_tfcoefp_MASK           (0x3F000000U)
#define locald14_LDLED028_tfcoefp_SHIFT          (24U)
/*! tfcoefp - tfcoefp */
#define locald14_LDLED028_tfcoefp(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED028_tfcoefp_SHIFT)) & locald14_LDLED028_tfcoefp_MASK)
/*! @} */

/*! @name LDLED029 - ldledreg029 */
/*! @{ */

#define locald14_LDLED029_ledsel_MASK            (0x300U)
#define locald14_LDLED029_ledsel_SHIFT           (8U)
/*! ledsel - ledsel */
#define locald14_LDLED029_ledsel(x)              (((uint32_t)(((uint32_t)(x)) << locald14_LDLED029_ledsel_SHIFT)) & locald14_LDLED029_ledsel_MASK)
/*! @} */

/*! @name LDLED02A - ldledreg02a */
/*! @{ */

#define locald14_LDLED02A_ldleddet_MASK          (0x1U)
#define locald14_LDLED02A_ldleddet_SHIFT         (0U)
/*! ldleddet - ldleddetwoff */
#define locald14_LDLED02A_ldleddet(x)            (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02A_ldleddet_SHIFT)) & locald14_LDLED02A_ldleddet_MASK)
/*! @} */

/*! @name LDLED02B - ldledreg02b */
/*! @{ */

#define locald14_LDLED02B_aledon0_MASK           (0x1U)
#define locald14_LDLED02B_aledon0_SHIFT          (0U)
/*! aledon0 - aledon_0 */
#define locald14_LDLED02B_aledon0(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon0_SHIFT)) & locald14_LDLED02B_aledon0_MASK)

#define locald14_LDLED02B_aledon1_MASK           (0x2U)
#define locald14_LDLED02B_aledon1_SHIFT          (1U)
/*! aledon1 - aledon_1 */
#define locald14_LDLED02B_aledon1(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon1_SHIFT)) & locald14_LDLED02B_aledon1_MASK)

#define locald14_LDLED02B_aledon2_MASK           (0x4U)
#define locald14_LDLED02B_aledon2_SHIFT          (2U)
/*! aledon2 - aledon_2 */
#define locald14_LDLED02B_aledon2(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon2_SHIFT)) & locald14_LDLED02B_aledon2_MASK)

#define locald14_LDLED02B_aledon3_MASK           (0x8U)
#define locald14_LDLED02B_aledon3_SHIFT          (3U)
/*! aledon3 - aledon_3 */
#define locald14_LDLED02B_aledon3(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon3_SHIFT)) & locald14_LDLED02B_aledon3_MASK)

#define locald14_LDLED02B_aledon4_MASK           (0x10U)
#define locald14_LDLED02B_aledon4_SHIFT          (4U)
/*! aledon4 - aledon_4 */
#define locald14_LDLED02B_aledon4(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon4_SHIFT)) & locald14_LDLED02B_aledon4_MASK)

#define locald14_LDLED02B_aledon5_MASK           (0x20U)
#define locald14_LDLED02B_aledon5_SHIFT          (5U)
/*! aledon5 - aledon_5 */
#define locald14_LDLED02B_aledon5(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon5_SHIFT)) & locald14_LDLED02B_aledon5_MASK)

#define locald14_LDLED02B_aledon6_MASK           (0x40U)
#define locald14_LDLED02B_aledon6_SHIFT          (6U)
/*! aledon6 - aledon_6 */
#define locald14_LDLED02B_aledon6(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon6_SHIFT)) & locald14_LDLED02B_aledon6_MASK)

#define locald14_LDLED02B_aledon7_MASK           (0x80U)
#define locald14_LDLED02B_aledon7_SHIFT          (7U)
/*! aledon7 - aledon_7 */
#define locald14_LDLED02B_aledon7(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledon7_SHIFT)) & locald14_LDLED02B_aledon7_MASK)

#define locald14_LDLED02B_aledlv_MASK            (0xFFF0000U)
#define locald14_LDLED02B_aledlv_SHIFT           (16U)
/*! aledlv - aledlv */
#define locald14_LDLED02B_aledlv(x)              (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02B_aledlv_SHIFT)) & locald14_LDLED02B_aledlv_MASK)
/*! @} */

/*! @name LDLED02C - ldledreg02c */
/*! @{ */

#define locald14_LDLED02C_aledve0_MASK           (0x1FU)
#define locald14_LDLED02C_aledve0_SHIFT          (0U)
/*! aledve0 - aledve_0 */
#define locald14_LDLED02C_aledve0(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02C_aledve0_SHIFT)) & locald14_LDLED02C_aledve0_MASK)

#define locald14_LDLED02C_aledvs0_MASK           (0x1F00U)
#define locald14_LDLED02C_aledvs0_SHIFT          (8U)
/*! aledvs0 - aledvs_0 */
#define locald14_LDLED02C_aledvs0(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02C_aledvs0_SHIFT)) & locald14_LDLED02C_aledvs0_MASK)

#define locald14_LDLED02C_aledhe0_MASK           (0x3F0000U)
#define locald14_LDLED02C_aledhe0_SHIFT          (16U)
/*! aledhe0 - aledhe_0 */
#define locald14_LDLED02C_aledhe0(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02C_aledhe0_SHIFT)) & locald14_LDLED02C_aledhe0_MASK)

#define locald14_LDLED02C_aledhs0_MASK           (0x3F000000U)
#define locald14_LDLED02C_aledhs0_SHIFT          (24U)
/*! aledhs0 - aledhs_0 */
#define locald14_LDLED02C_aledhs0(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02C_aledhs0_SHIFT)) & locald14_LDLED02C_aledhs0_MASK)
/*! @} */

/*! @name LDLED02D - ldledreg02d */
/*! @{ */

#define locald14_LDLED02D_aledve1_MASK           (0x1FU)
#define locald14_LDLED02D_aledve1_SHIFT          (0U)
/*! aledve1 - aledve_1 */
#define locald14_LDLED02D_aledve1(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02D_aledve1_SHIFT)) & locald14_LDLED02D_aledve1_MASK)

#define locald14_LDLED02D_aledvs1_MASK           (0x1F00U)
#define locald14_LDLED02D_aledvs1_SHIFT          (8U)
/*! aledvs1 - aledvs_1 */
#define locald14_LDLED02D_aledvs1(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02D_aledvs1_SHIFT)) & locald14_LDLED02D_aledvs1_MASK)

#define locald14_LDLED02D_aledhe1_MASK           (0x3F0000U)
#define locald14_LDLED02D_aledhe1_SHIFT          (16U)
/*! aledhe1 - aledhe_1 */
#define locald14_LDLED02D_aledhe1(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02D_aledhe1_SHIFT)) & locald14_LDLED02D_aledhe1_MASK)

#define locald14_LDLED02D_aledhs1_MASK           (0x3F000000U)
#define locald14_LDLED02D_aledhs1_SHIFT          (24U)
/*! aledhs1 - aledhs_1 */
#define locald14_LDLED02D_aledhs1(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02D_aledhs1_SHIFT)) & locald14_LDLED02D_aledhs1_MASK)
/*! @} */

/*! @name LDLED02E - ldledreg02e */
/*! @{ */

#define locald14_LDLED02E_aledve2_MASK           (0x1FU)
#define locald14_LDLED02E_aledve2_SHIFT          (0U)
/*! aledve2 - aledve_2 */
#define locald14_LDLED02E_aledve2(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02E_aledve2_SHIFT)) & locald14_LDLED02E_aledve2_MASK)

#define locald14_LDLED02E_aledvs2_MASK           (0x1F00U)
#define locald14_LDLED02E_aledvs2_SHIFT          (8U)
/*! aledvs2 - aledvs_2 */
#define locald14_LDLED02E_aledvs2(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02E_aledvs2_SHIFT)) & locald14_LDLED02E_aledvs2_MASK)

#define locald14_LDLED02E_aledhe2_MASK           (0x3F0000U)
#define locald14_LDLED02E_aledhe2_SHIFT          (16U)
/*! aledhe2 - aledhe_2 */
#define locald14_LDLED02E_aledhe2(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02E_aledhe2_SHIFT)) & locald14_LDLED02E_aledhe2_MASK)

#define locald14_LDLED02E_aledhs2_MASK           (0x3F000000U)
#define locald14_LDLED02E_aledhs2_SHIFT          (24U)
/*! aledhs2 - aledhs_2 */
#define locald14_LDLED02E_aledhs2(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02E_aledhs2_SHIFT)) & locald14_LDLED02E_aledhs2_MASK)
/*! @} */

/*! @name LDLED02F - ldledreg02f */
/*! @{ */

#define locald14_LDLED02F_aledve3_MASK           (0x1FU)
#define locald14_LDLED02F_aledve3_SHIFT          (0U)
/*! aledve3 - aledve_3 */
#define locald14_LDLED02F_aledve3(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02F_aledve3_SHIFT)) & locald14_LDLED02F_aledve3_MASK)

#define locald14_LDLED02F_aledvs3_MASK           (0x1F00U)
#define locald14_LDLED02F_aledvs3_SHIFT          (8U)
/*! aledvs3 - aledvs_3 */
#define locald14_LDLED02F_aledvs3(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02F_aledvs3_SHIFT)) & locald14_LDLED02F_aledvs3_MASK)

#define locald14_LDLED02F_aledhe3_MASK           (0x3F0000U)
#define locald14_LDLED02F_aledhe3_SHIFT          (16U)
/*! aledhe3 - aledhe_3 */
#define locald14_LDLED02F_aledhe3(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02F_aledhe3_SHIFT)) & locald14_LDLED02F_aledhe3_MASK)

#define locald14_LDLED02F_aledhs3_MASK           (0x3F000000U)
#define locald14_LDLED02F_aledhs3_SHIFT          (24U)
/*! aledhs3 - aledhs_3 */
#define locald14_LDLED02F_aledhs3(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED02F_aledhs3_SHIFT)) & locald14_LDLED02F_aledhs3_MASK)
/*! @} */

/*! @name LDLED030 - ldledreg030 */
/*! @{ */

#define locald14_LDLED030_aledve4_MASK           (0x1FU)
#define locald14_LDLED030_aledve4_SHIFT          (0U)
/*! aledve4 - aledve_4 */
#define locald14_LDLED030_aledve4(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED030_aledve4_SHIFT)) & locald14_LDLED030_aledve4_MASK)

#define locald14_LDLED030_aledvs4_MASK           (0x1F00U)
#define locald14_LDLED030_aledvs4_SHIFT          (8U)
/*! aledvs4 - aledvs_4 */
#define locald14_LDLED030_aledvs4(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED030_aledvs4_SHIFT)) & locald14_LDLED030_aledvs4_MASK)

#define locald14_LDLED030_aledhe4_MASK           (0x3F0000U)
#define locald14_LDLED030_aledhe4_SHIFT          (16U)
/*! aledhe4 - aledhe_4 */
#define locald14_LDLED030_aledhe4(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED030_aledhe4_SHIFT)) & locald14_LDLED030_aledhe4_MASK)

#define locald14_LDLED030_aledhs4_MASK           (0x3F000000U)
#define locald14_LDLED030_aledhs4_SHIFT          (24U)
/*! aledhs4 - aledhs_4 */
#define locald14_LDLED030_aledhs4(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED030_aledhs4_SHIFT)) & locald14_LDLED030_aledhs4_MASK)
/*! @} */

/*! @name LDLED031 - ldledreg031 */
/*! @{ */

#define locald14_LDLED031_aledve5_MASK           (0x1FU)
#define locald14_LDLED031_aledve5_SHIFT          (0U)
/*! aledve5 - aledve_5 */
#define locald14_LDLED031_aledve5(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED031_aledve5_SHIFT)) & locald14_LDLED031_aledve5_MASK)

#define locald14_LDLED031_aledvs5_MASK           (0x1F00U)
#define locald14_LDLED031_aledvs5_SHIFT          (8U)
/*! aledvs5 - aledvs_5 */
#define locald14_LDLED031_aledvs5(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED031_aledvs5_SHIFT)) & locald14_LDLED031_aledvs5_MASK)

#define locald14_LDLED031_aledhe5_MASK           (0x3F0000U)
#define locald14_LDLED031_aledhe5_SHIFT          (16U)
/*! aledhe5 - aledhe_5 */
#define locald14_LDLED031_aledhe5(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED031_aledhe5_SHIFT)) & locald14_LDLED031_aledhe5_MASK)

#define locald14_LDLED031_aledhs5_MASK           (0x3F000000U)
#define locald14_LDLED031_aledhs5_SHIFT          (24U)
/*! aledhs5 - aledhs_5 */
#define locald14_LDLED031_aledhs5(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED031_aledhs5_SHIFT)) & locald14_LDLED031_aledhs5_MASK)
/*! @} */

/*! @name LDLED032 - ldledreg032 */
/*! @{ */

#define locald14_LDLED032_aledve6_MASK           (0x1FU)
#define locald14_LDLED032_aledve6_SHIFT          (0U)
/*! aledve6 - aledve_6 */
#define locald14_LDLED032_aledve6(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED032_aledve6_SHIFT)) & locald14_LDLED032_aledve6_MASK)

#define locald14_LDLED032_aledvs6_MASK           (0x1F00U)
#define locald14_LDLED032_aledvs6_SHIFT          (8U)
/*! aledvs6 - aledvs_6 */
#define locald14_LDLED032_aledvs6(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED032_aledvs6_SHIFT)) & locald14_LDLED032_aledvs6_MASK)

#define locald14_LDLED032_aledhe6_MASK           (0x3F0000U)
#define locald14_LDLED032_aledhe6_SHIFT          (16U)
/*! aledhe6 - aledhe_6 */
#define locald14_LDLED032_aledhe6(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED032_aledhe6_SHIFT)) & locald14_LDLED032_aledhe6_MASK)

#define locald14_LDLED032_aledhs6_MASK           (0x3F000000U)
#define locald14_LDLED032_aledhs6_SHIFT          (24U)
/*! aledhs6 - aledhs_6 */
#define locald14_LDLED032_aledhs6(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED032_aledhs6_SHIFT)) & locald14_LDLED032_aledhs6_MASK)
/*! @} */

/*! @name LDLED033 - ldledreg033 */
/*! @{ */

#define locald14_LDLED033_aledve7_MASK           (0x1FU)
#define locald14_LDLED033_aledve7_SHIFT          (0U)
/*! aledve7 - aledve_7 */
#define locald14_LDLED033_aledve7(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED033_aledve7_SHIFT)) & locald14_LDLED033_aledve7_MASK)

#define locald14_LDLED033_aledvs7_MASK           (0x1F00U)
#define locald14_LDLED033_aledvs7_SHIFT          (8U)
/*! aledvs7 - aledvs_7 */
#define locald14_LDLED033_aledvs7(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED033_aledvs7_SHIFT)) & locald14_LDLED033_aledvs7_MASK)

#define locald14_LDLED033_aledhe7_MASK           (0x3F0000U)
#define locald14_LDLED033_aledhe7_SHIFT          (16U)
/*! aledhe7 - aledhe_7 */
#define locald14_LDLED033_aledhe7(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED033_aledhe7_SHIFT)) & locald14_LDLED033_aledhe7_MASK)

#define locald14_LDLED033_aledhs7_MASK           (0x3F000000U)
#define locald14_LDLED033_aledhs7_SHIFT          (24U)
/*! aledhs7 - aledhs_7 */
#define locald14_LDLED033_aledhs7(x)             (((uint32_t)(((uint32_t)(x)) << locald14_LDLED033_aledhs7_SHIFT)) & locald14_LDLED033_aledhs7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald14_Register_Masks */


/*!
 * @}
 */ /* end of group locald14_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD14_H_ */

