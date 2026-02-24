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
**         CMSIS Peripheral Access Layer for locald37
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
 * @file PERI_locald37.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald37
 *
 * CMSIS Peripheral Access Layer for locald37
 */

#if !defined(PERI_LOCALD37_H_)
#define PERI_LOCALD37_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald37 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald37_Peripheral_Access_Layer locald37 Peripheral Access Layer
 * @{
 */

/** locald37 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR140;                          /**< ldprofilereg140, offset: 0x0 */
  __IO uint32_t LDPRR141;                          /**< ldprofilereg141, offset: 0x4 */
  __IO uint32_t LDPRR142;                          /**< ldprofilereg142, offset: 0x8 */
  __IO uint32_t LDPRR143;                          /**< ldprofilereg143, offset: 0xC */
  __IO uint32_t LDPRR144;                          /**< ldprofilereg144, offset: 0x10 */
  __IO uint32_t LDPRR145;                          /**< ldprofilereg145, offset: 0x14 */
  __IO uint32_t LDPRR146;                          /**< ldprofilereg146, offset: 0x18 */
  __IO uint32_t LDPRR147;                          /**< ldprofilereg147, offset: 0x1C */
  __IO uint32_t LDPRR148;                          /**< ldprofilereg148, offset: 0x20 */
  __IO uint32_t LDPRR149;                          /**< ldprofilereg149, offset: 0x24 */
  __IO uint32_t LDPRR14A;                          /**< ldprofilereg14a, offset: 0x28 */
  __IO uint32_t LDPRR14B;                          /**< ldprofilereg14b, offset: 0x2C */
  __IO uint32_t LDPRR14C;                          /**< ldprofilereg14c, offset: 0x30 */
  __IO uint32_t LDPRR14D;                          /**< ldprofilereg14d, offset: 0x34 */
  __IO uint32_t LDPRR14E;                          /**< ldprofilereg14e, offset: 0x38 */
  __IO uint32_t LDPRR14F;                          /**< ldprofilereg14f, offset: 0x3C */
  __IO uint32_t LDPRR150;                          /**< ldprofilereg150, offset: 0x40 */
  __IO uint32_t LDPRR151;                          /**< ldprofilereg151, offset: 0x44 */
  __IO uint32_t LDPRR152;                          /**< ldprofilereg152, offset: 0x48 */
  __IO uint32_t LDPRR153;                          /**< ldprofilereg153, offset: 0x4C */
  __IO uint32_t LDPRR154;                          /**< ldprofilereg154, offset: 0x50 */
  __IO uint32_t LDPRR155;                          /**< ldprofilereg155, offset: 0x54 */
  __IO uint32_t LDPRR156;                          /**< ldprofilereg156, offset: 0x58 */
  __IO uint32_t LDPRR157;                          /**< ldprofilereg157, offset: 0x5C */
} locald37_Type;

/* ----------------------------------------------------------------------------
   -- locald37 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald37_Register_Masks locald37 Register Masks
 * @{
 */

/*! @name LDPRR140 - ldprofilereg140 */
/*! @{ */

#define locald37_LDPRR140_lumd481_MASK           (0x3FFU)
#define locald37_LDPRR140_lumd481_SHIFT          (0U)
/*! lumd481 - lumdat_481 */
#define locald37_LDPRR140_lumd481(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR140_lumd481_SHIFT)) & locald37_LDPRR140_lumd481_MASK)

#define locald37_LDPRR140_lumd480_MASK           (0x3FF0000U)
#define locald37_LDPRR140_lumd480_SHIFT          (16U)
/*! lumd480 - lumdat_480 */
#define locald37_LDPRR140_lumd480(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR140_lumd480_SHIFT)) & locald37_LDPRR140_lumd480_MASK)
/*! @} */

/*! @name LDPRR141 - ldprofilereg141 */
/*! @{ */

#define locald37_LDPRR141_lumd483_MASK           (0x3FFU)
#define locald37_LDPRR141_lumd483_SHIFT          (0U)
/*! lumd483 - lumdat_483 */
#define locald37_LDPRR141_lumd483(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR141_lumd483_SHIFT)) & locald37_LDPRR141_lumd483_MASK)

#define locald37_LDPRR141_lumd482_MASK           (0x3FF0000U)
#define locald37_LDPRR141_lumd482_SHIFT          (16U)
/*! lumd482 - lumdat_482 */
#define locald37_LDPRR141_lumd482(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR141_lumd482_SHIFT)) & locald37_LDPRR141_lumd482_MASK)
/*! @} */

/*! @name LDPRR142 - ldprofilereg142 */
/*! @{ */

#define locald37_LDPRR142_lumd485_MASK           (0x3FFU)
#define locald37_LDPRR142_lumd485_SHIFT          (0U)
/*! lumd485 - lumdat_485 */
#define locald37_LDPRR142_lumd485(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR142_lumd485_SHIFT)) & locald37_LDPRR142_lumd485_MASK)

#define locald37_LDPRR142_lumd484_MASK           (0x3FF0000U)
#define locald37_LDPRR142_lumd484_SHIFT          (16U)
/*! lumd484 - lumdat_484 */
#define locald37_LDPRR142_lumd484(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR142_lumd484_SHIFT)) & locald37_LDPRR142_lumd484_MASK)
/*! @} */

/*! @name LDPRR143 - ldprofilereg143 */
/*! @{ */

#define locald37_LDPRR143_lumd487_MASK           (0x3FFU)
#define locald37_LDPRR143_lumd487_SHIFT          (0U)
/*! lumd487 - lumdat_487 */
#define locald37_LDPRR143_lumd487(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR143_lumd487_SHIFT)) & locald37_LDPRR143_lumd487_MASK)

#define locald37_LDPRR143_lumd486_MASK           (0x3FF0000U)
#define locald37_LDPRR143_lumd486_SHIFT          (16U)
/*! lumd486 - lumdat_486 */
#define locald37_LDPRR143_lumd486(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR143_lumd486_SHIFT)) & locald37_LDPRR143_lumd486_MASK)
/*! @} */

/*! @name LDPRR144 - ldprofilereg144 */
/*! @{ */

#define locald37_LDPRR144_lumd489_MASK           (0x3FFU)
#define locald37_LDPRR144_lumd489_SHIFT          (0U)
/*! lumd489 - lumdat_489 */
#define locald37_LDPRR144_lumd489(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR144_lumd489_SHIFT)) & locald37_LDPRR144_lumd489_MASK)

#define locald37_LDPRR144_lumd488_MASK           (0x3FF0000U)
#define locald37_LDPRR144_lumd488_SHIFT          (16U)
/*! lumd488 - lumdat_488 */
#define locald37_LDPRR144_lumd488(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR144_lumd488_SHIFT)) & locald37_LDPRR144_lumd488_MASK)
/*! @} */

/*! @name LDPRR145 - ldprofilereg145 */
/*! @{ */

#define locald37_LDPRR145_lumd491_MASK           (0x3FFU)
#define locald37_LDPRR145_lumd491_SHIFT          (0U)
/*! lumd491 - lumdat_491 */
#define locald37_LDPRR145_lumd491(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR145_lumd491_SHIFT)) & locald37_LDPRR145_lumd491_MASK)

#define locald37_LDPRR145_lumd490_MASK           (0x3FF0000U)
#define locald37_LDPRR145_lumd490_SHIFT          (16U)
/*! lumd490 - lumdat_490 */
#define locald37_LDPRR145_lumd490(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR145_lumd490_SHIFT)) & locald37_LDPRR145_lumd490_MASK)
/*! @} */

/*! @name LDPRR146 - ldprofilereg146 */
/*! @{ */

#define locald37_LDPRR146_lumd493_MASK           (0x3FFU)
#define locald37_LDPRR146_lumd493_SHIFT          (0U)
/*! lumd493 - lumdat_493 */
#define locald37_LDPRR146_lumd493(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR146_lumd493_SHIFT)) & locald37_LDPRR146_lumd493_MASK)

#define locald37_LDPRR146_lumd492_MASK           (0x3FF0000U)
#define locald37_LDPRR146_lumd492_SHIFT          (16U)
/*! lumd492 - lumdat_492 */
#define locald37_LDPRR146_lumd492(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR146_lumd492_SHIFT)) & locald37_LDPRR146_lumd492_MASK)
/*! @} */

/*! @name LDPRR147 - ldprofilereg147 */
/*! @{ */

#define locald37_LDPRR147_lumd495_MASK           (0x3FFU)
#define locald37_LDPRR147_lumd495_SHIFT          (0U)
/*! lumd495 - lumdat_495 */
#define locald37_LDPRR147_lumd495(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR147_lumd495_SHIFT)) & locald37_LDPRR147_lumd495_MASK)

#define locald37_LDPRR147_lumd494_MASK           (0x3FF0000U)
#define locald37_LDPRR147_lumd494_SHIFT          (16U)
/*! lumd494 - lumdat_494 */
#define locald37_LDPRR147_lumd494(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR147_lumd494_SHIFT)) & locald37_LDPRR147_lumd494_MASK)
/*! @} */

/*! @name LDPRR148 - ldprofilereg148 */
/*! @{ */

#define locald37_LDPRR148_lumd497_MASK           (0x3FFU)
#define locald37_LDPRR148_lumd497_SHIFT          (0U)
/*! lumd497 - lumdat_497 */
#define locald37_LDPRR148_lumd497(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR148_lumd497_SHIFT)) & locald37_LDPRR148_lumd497_MASK)

#define locald37_LDPRR148_lumd496_MASK           (0x3FF0000U)
#define locald37_LDPRR148_lumd496_SHIFT          (16U)
/*! lumd496 - lumdat_496 */
#define locald37_LDPRR148_lumd496(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR148_lumd496_SHIFT)) & locald37_LDPRR148_lumd496_MASK)
/*! @} */

/*! @name LDPRR149 - ldprofilereg149 */
/*! @{ */

#define locald37_LDPRR149_lumd499_MASK           (0x3FFU)
#define locald37_LDPRR149_lumd499_SHIFT          (0U)
/*! lumd499 - lumdat_499 */
#define locald37_LDPRR149_lumd499(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR149_lumd499_SHIFT)) & locald37_LDPRR149_lumd499_MASK)

#define locald37_LDPRR149_lumd498_MASK           (0x3FF0000U)
#define locald37_LDPRR149_lumd498_SHIFT          (16U)
/*! lumd498 - lumdat_498 */
#define locald37_LDPRR149_lumd498(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR149_lumd498_SHIFT)) & locald37_LDPRR149_lumd498_MASK)
/*! @} */

/*! @name LDPRR14A - ldprofilereg14a */
/*! @{ */

#define locald37_LDPRR14A_lumd501_MASK           (0x3FFU)
#define locald37_LDPRR14A_lumd501_SHIFT          (0U)
/*! lumd501 - lumdat_501 */
#define locald37_LDPRR14A_lumd501(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14A_lumd501_SHIFT)) & locald37_LDPRR14A_lumd501_MASK)

#define locald37_LDPRR14A_lumd500_MASK           (0x3FF0000U)
#define locald37_LDPRR14A_lumd500_SHIFT          (16U)
/*! lumd500 - lumdat_500 */
#define locald37_LDPRR14A_lumd500(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14A_lumd500_SHIFT)) & locald37_LDPRR14A_lumd500_MASK)
/*! @} */

/*! @name LDPRR14B - ldprofilereg14b */
/*! @{ */

#define locald37_LDPRR14B_lumd503_MASK           (0x3FFU)
#define locald37_LDPRR14B_lumd503_SHIFT          (0U)
/*! lumd503 - lumdat_503 */
#define locald37_LDPRR14B_lumd503(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14B_lumd503_SHIFT)) & locald37_LDPRR14B_lumd503_MASK)

#define locald37_LDPRR14B_lumd502_MASK           (0x3FF0000U)
#define locald37_LDPRR14B_lumd502_SHIFT          (16U)
/*! lumd502 - lumdat_502 */
#define locald37_LDPRR14B_lumd502(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14B_lumd502_SHIFT)) & locald37_LDPRR14B_lumd502_MASK)
/*! @} */

/*! @name LDPRR14C - ldprofilereg14c */
/*! @{ */

#define locald37_LDPRR14C_lumd505_MASK           (0x3FFU)
#define locald37_LDPRR14C_lumd505_SHIFT          (0U)
/*! lumd505 - lumdat_505 */
#define locald37_LDPRR14C_lumd505(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14C_lumd505_SHIFT)) & locald37_LDPRR14C_lumd505_MASK)

#define locald37_LDPRR14C_lumd504_MASK           (0x3FF0000U)
#define locald37_LDPRR14C_lumd504_SHIFT          (16U)
/*! lumd504 - lumdat_504 */
#define locald37_LDPRR14C_lumd504(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14C_lumd504_SHIFT)) & locald37_LDPRR14C_lumd504_MASK)
/*! @} */

/*! @name LDPRR14D - ldprofilereg14d */
/*! @{ */

#define locald37_LDPRR14D_lumd507_MASK           (0x3FFU)
#define locald37_LDPRR14D_lumd507_SHIFT          (0U)
/*! lumd507 - lumdat_507 */
#define locald37_LDPRR14D_lumd507(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14D_lumd507_SHIFT)) & locald37_LDPRR14D_lumd507_MASK)

#define locald37_LDPRR14D_lumd506_MASK           (0x3FF0000U)
#define locald37_LDPRR14D_lumd506_SHIFT          (16U)
/*! lumd506 - lumdat_506 */
#define locald37_LDPRR14D_lumd506(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14D_lumd506_SHIFT)) & locald37_LDPRR14D_lumd506_MASK)
/*! @} */

/*! @name LDPRR14E - ldprofilereg14e */
/*! @{ */

#define locald37_LDPRR14E_lumd509_MASK           (0x3FFU)
#define locald37_LDPRR14E_lumd509_SHIFT          (0U)
/*! lumd509 - lumdat_509 */
#define locald37_LDPRR14E_lumd509(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14E_lumd509_SHIFT)) & locald37_LDPRR14E_lumd509_MASK)

#define locald37_LDPRR14E_lumd508_MASK           (0x3FF0000U)
#define locald37_LDPRR14E_lumd508_SHIFT          (16U)
/*! lumd508 - lumdat_508 */
#define locald37_LDPRR14E_lumd508(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14E_lumd508_SHIFT)) & locald37_LDPRR14E_lumd508_MASK)
/*! @} */

/*! @name LDPRR14F - ldprofilereg14f */
/*! @{ */

#define locald37_LDPRR14F_lumd511_MASK           (0x3FFU)
#define locald37_LDPRR14F_lumd511_SHIFT          (0U)
/*! lumd511 - lumdat_511 */
#define locald37_LDPRR14F_lumd511(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14F_lumd511_SHIFT)) & locald37_LDPRR14F_lumd511_MASK)

#define locald37_LDPRR14F_lumd510_MASK           (0x3FF0000U)
#define locald37_LDPRR14F_lumd510_SHIFT          (16U)
/*! lumd510 - lumdat_510 */
#define locald37_LDPRR14F_lumd510(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR14F_lumd510_SHIFT)) & locald37_LDPRR14F_lumd510_MASK)
/*! @} */

/*! @name LDPRR150 - ldprofilereg150 */
/*! @{ */

#define locald37_LDPRR150_lumd513_MASK           (0x3FFU)
#define locald37_LDPRR150_lumd513_SHIFT          (0U)
/*! lumd513 - lumdat_513 */
#define locald37_LDPRR150_lumd513(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR150_lumd513_SHIFT)) & locald37_LDPRR150_lumd513_MASK)

#define locald37_LDPRR150_lumd512_MASK           (0x3FF0000U)
#define locald37_LDPRR150_lumd512_SHIFT          (16U)
/*! lumd512 - lumdat_512 */
#define locald37_LDPRR150_lumd512(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR150_lumd512_SHIFT)) & locald37_LDPRR150_lumd512_MASK)
/*! @} */

/*! @name LDPRR151 - ldprofilereg151 */
/*! @{ */

#define locald37_LDPRR151_lumd515_MASK           (0x3FFU)
#define locald37_LDPRR151_lumd515_SHIFT          (0U)
/*! lumd515 - lumdat_515 */
#define locald37_LDPRR151_lumd515(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR151_lumd515_SHIFT)) & locald37_LDPRR151_lumd515_MASK)

#define locald37_LDPRR151_lumd514_MASK           (0x3FF0000U)
#define locald37_LDPRR151_lumd514_SHIFT          (16U)
/*! lumd514 - lumdat_514 */
#define locald37_LDPRR151_lumd514(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR151_lumd514_SHIFT)) & locald37_LDPRR151_lumd514_MASK)
/*! @} */

/*! @name LDPRR152 - ldprofilereg152 */
/*! @{ */

#define locald37_LDPRR152_lumd517_MASK           (0x3FFU)
#define locald37_LDPRR152_lumd517_SHIFT          (0U)
/*! lumd517 - lumdat_517 */
#define locald37_LDPRR152_lumd517(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR152_lumd517_SHIFT)) & locald37_LDPRR152_lumd517_MASK)

#define locald37_LDPRR152_lumd516_MASK           (0x3FF0000U)
#define locald37_LDPRR152_lumd516_SHIFT          (16U)
/*! lumd516 - lumdat_516 */
#define locald37_LDPRR152_lumd516(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR152_lumd516_SHIFT)) & locald37_LDPRR152_lumd516_MASK)
/*! @} */

/*! @name LDPRR153 - ldprofilereg153 */
/*! @{ */

#define locald37_LDPRR153_lumd519_MASK           (0x3FFU)
#define locald37_LDPRR153_lumd519_SHIFT          (0U)
/*! lumd519 - lumdat_519 */
#define locald37_LDPRR153_lumd519(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR153_lumd519_SHIFT)) & locald37_LDPRR153_lumd519_MASK)

#define locald37_LDPRR153_lumd518_MASK           (0x3FF0000U)
#define locald37_LDPRR153_lumd518_SHIFT          (16U)
/*! lumd518 - lumdat_518 */
#define locald37_LDPRR153_lumd518(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR153_lumd518_SHIFT)) & locald37_LDPRR153_lumd518_MASK)
/*! @} */

/*! @name LDPRR154 - ldprofilereg154 */
/*! @{ */

#define locald37_LDPRR154_lumd521_MASK           (0x3FFU)
#define locald37_LDPRR154_lumd521_SHIFT          (0U)
/*! lumd521 - lumdat_521 */
#define locald37_LDPRR154_lumd521(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR154_lumd521_SHIFT)) & locald37_LDPRR154_lumd521_MASK)

#define locald37_LDPRR154_lumd520_MASK           (0x3FF0000U)
#define locald37_LDPRR154_lumd520_SHIFT          (16U)
/*! lumd520 - lumdat_520 */
#define locald37_LDPRR154_lumd520(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR154_lumd520_SHIFT)) & locald37_LDPRR154_lumd520_MASK)
/*! @} */

/*! @name LDPRR155 - ldprofilereg155 */
/*! @{ */

#define locald37_LDPRR155_lumd523_MASK           (0x3FFU)
#define locald37_LDPRR155_lumd523_SHIFT          (0U)
/*! lumd523 - lumdat_523 */
#define locald37_LDPRR155_lumd523(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR155_lumd523_SHIFT)) & locald37_LDPRR155_lumd523_MASK)

#define locald37_LDPRR155_lumd522_MASK           (0x3FF0000U)
#define locald37_LDPRR155_lumd522_SHIFT          (16U)
/*! lumd522 - lumdat_522 */
#define locald37_LDPRR155_lumd522(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR155_lumd522_SHIFT)) & locald37_LDPRR155_lumd522_MASK)
/*! @} */

/*! @name LDPRR156 - ldprofilereg156 */
/*! @{ */

#define locald37_LDPRR156_lumd525_MASK           (0x3FFU)
#define locald37_LDPRR156_lumd525_SHIFT          (0U)
/*! lumd525 - lumdat_525 */
#define locald37_LDPRR156_lumd525(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR156_lumd525_SHIFT)) & locald37_LDPRR156_lumd525_MASK)

#define locald37_LDPRR156_lumd524_MASK           (0x3FF0000U)
#define locald37_LDPRR156_lumd524_SHIFT          (16U)
/*! lumd524 - lumdat_524 */
#define locald37_LDPRR156_lumd524(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR156_lumd524_SHIFT)) & locald37_LDPRR156_lumd524_MASK)
/*! @} */

/*! @name LDPRR157 - ldprofilereg157 */
/*! @{ */

#define locald37_LDPRR157_lumd527_MASK           (0x3FFU)
#define locald37_LDPRR157_lumd527_SHIFT          (0U)
/*! lumd527 - lumdat_527 */
#define locald37_LDPRR157_lumd527(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR157_lumd527_SHIFT)) & locald37_LDPRR157_lumd527_MASK)

#define locald37_LDPRR157_lumd526_MASK           (0x3FF0000U)
#define locald37_LDPRR157_lumd526_SHIFT          (16U)
/*! lumd526 - lumdat_526 */
#define locald37_LDPRR157_lumd526(x)             (((uint32_t)(((uint32_t)(x)) << locald37_LDPRR157_lumd526_SHIFT)) & locald37_LDPRR157_lumd526_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald37_Register_Masks */


/*!
 * @}
 */ /* end of group locald37_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD37_H_ */

