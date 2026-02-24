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
**         CMSIS Peripheral Access Layer for locald23
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
 * @file PERI_locald23.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald23
 *
 * CMSIS Peripheral Access Layer for locald23
 */

#if !defined(PERI_LOCALD23_H_)
#define PERI_LOCALD23_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald23 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald23_Peripheral_Access_Layer locald23 Peripheral Access Layer
 * @{
 */

/** locald23 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDRG05C;                           /**< ldrgbreg05c, offset: 0x0 */
  __IO uint32_t LDRG05D;                           /**< ldrgbreg05d, offset: 0x4 */
  __IO uint32_t LDRG05E;                           /**< ldrgbreg05e, offset: 0x8 */
  __IO uint32_t LDRG05F;                           /**< ldrgbreg05f, offset: 0xC */
  __IO uint32_t LDRG060;                           /**< ldrgbreg060, offset: 0x10 */
} locald23_Type;

/* ----------------------------------------------------------------------------
   -- locald23 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald23_Register_Masks locald23 Register Masks
 * @{
 */

/*! @name LDRG05C - ldrgbreg05c */
/*! @{ */

#define locald23_LDRG05C_maxlvfhy_MASK           (0xFFU)
#define locald23_LDRG05C_maxlvfhy_SHIFT          (0U)
/*! maxlvfhy - maxlvf_hyst */
#define locald23_LDRG05C_maxlvfhy(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05C_maxlvfhy_SHIFT)) & locald23_LDRG05C_maxlvfhy_MASK)

#define locald23_LDRG05C_maxlvfth_MASK           (0xFFFFFF00U)
#define locald23_LDRG05C_maxlvfth_SHIFT          (8U)
/*! maxlvfth - maxlvf_th */
#define locald23_LDRG05C_maxlvfth(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05C_maxlvfth_SHIFT)) & locald23_LDRG05C_maxlvfth_MASK)
/*! @} */

/*! @name LDRG05D - ldrgbreg05d */
/*! @{ */

#define locald23_LDRG05D_passhst_MASK            (0x3FFFU)
#define locald23_LDRG05D_passhst_SHIFT           (0U)
/*! passhst - pass_hstart */
#define locald23_LDRG05D_passhst(x)              (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05D_passhst_SHIFT)) & locald23_LDRG05D_passhst_MASK)

#define locald23_LDRG05D_passvst_MASK            (0x3FFF0000U)
#define locald23_LDRG05D_passvst_SHIFT           (16U)
/*! passvst - pass_vstart */
#define locald23_LDRG05D_passvst(x)              (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05D_passvst_SHIFT)) & locald23_LDRG05D_passvst_MASK)
/*! @} */

/*! @name LDRG05E - ldrgbreg05e */
/*! @{ */

#define locald23_LDRG05E_passhsi_MASK            (0x3FFFU)
#define locald23_LDRG05E_passhsi_SHIFT           (0U)
/*! passhsi - pass_hsize */
#define locald23_LDRG05E_passhsi(x)              (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05E_passhsi_SHIFT)) & locald23_LDRG05E_passhsi_MASK)

#define locald23_LDRG05E_passvsi_MASK            (0x3FFF0000U)
#define locald23_LDRG05E_passvsi_SHIFT           (16U)
/*! passvsi - pass_vsize */
#define locald23_LDRG05E_passvsi(x)              (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05E_passvsi_SHIFT)) & locald23_LDRG05E_passvsi_MASK)
/*! @} */

/*! @name LDRG05F - ldrgbreg05f */
/*! @{ */

#define locald23_LDRG05F_makinen_MASK            (0x1U)
#define locald23_LDRG05F_makinen_SHIFT           (0U)
/*! makinen - maskin_en */
#define locald23_LDRG05F_makinen(x)              (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05F_makinen_SHIFT)) & locald23_LDRG05F_makinen_MASK)

#define locald23_LDRG05F_makininv_MASK           (0x2U)
#define locald23_LDRG05F_makininv_SHIFT          (1U)
/*! makininv - maskin_inv */
#define locald23_LDRG05F_makininv(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05F_makininv_SHIFT)) & locald23_LDRG05F_makininv_MASK)

#define locald23_LDRG05F_makinsel_MASK           (0x4U)
#define locald23_LDRG05F_makinsel_SHIFT          (2U)
/*! makinsel - maskin_sel */
#define locald23_LDRG05F_makinsel(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG05F_makinsel_SHIFT)) & locald23_LDRG05F_makinsel_MASK)
/*! @} */

/*! @name LDRG060 - ldrgbreg060 */
/*! @{ */

#define locald23_LDRG060_maxlvfmv_MASK           (0xFFFU)
#define locald23_LDRG060_maxlvfmv_SHIFT          (0U)
/*! maxlvfmv - maxlvf_mvth */
#define locald23_LDRG060_maxlvfmv(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG060_maxlvfmv_SHIFT)) & locald23_LDRG060_maxlvfmv_MASK)

#define locald23_LDRG060_maxlvfbt_MASK           (0xFFF000U)
#define locald23_LDRG060_maxlvfbt_SHIFT          (12U)
/*! maxlvfbt - maxlvf_bth */
#define locald23_LDRG060_maxlvfbt(x)             (((uint32_t)(((uint32_t)(x)) << locald23_LDRG060_maxlvfbt_SHIFT)) & locald23_LDRG060_maxlvfbt_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald23_Register_Masks */


/*!
 * @}
 */ /* end of group locald23_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD23_H_ */

