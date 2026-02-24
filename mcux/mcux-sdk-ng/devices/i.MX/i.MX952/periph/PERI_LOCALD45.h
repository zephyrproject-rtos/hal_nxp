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
**         CMSIS Peripheral Access Layer for locald45
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
 * @file PERI_locald45.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald45
 *
 * CMSIS Peripheral Access Layer for locald45
 */

#if !defined(PERI_LOCALD45_H_)
#define PERI_LOCALD45_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald45 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald45_Peripheral_Access_Layer locald45 Peripheral Access Layer
 * @{
 */

/** locald45 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR240;                          /**< ldprofilereg240, offset: 0x0 */
  __IO uint32_t LDPRR241;                          /**< ldprofilereg241, offset: 0x4 */
  __IO uint32_t LDPRR242;                          /**< ldprofilereg242, offset: 0x8 */
  __IO uint32_t LDPRR243;                          /**< ldprofilereg243, offset: 0xC */
  __IO uint32_t LDPRR244;                          /**< ldprofilereg244, offset: 0x10 */
  __IO uint32_t LDPRR245;                          /**< ldprofilereg245, offset: 0x14 */
  __IO uint32_t LDPRR246;                          /**< ldprofilereg246, offset: 0x18 */
  __IO uint32_t LDPRR247;                          /**< ldprofilereg247, offset: 0x1C */
  __IO uint32_t LDPRR248;                          /**< ldprofilereg248, offset: 0x20 */
  __IO uint32_t LDPRR249;                          /**< ldprofilereg249, offset: 0x24 */
  __IO uint32_t LDPRR24A;                          /**< ldprofilereg24a, offset: 0x28 */
  __IO uint32_t LDPRR24B;                          /**< ldprofilereg24b, offset: 0x2C */
  __IO uint32_t LDPRR24C;                          /**< ldprofilereg24c, offset: 0x30 */
  __IO uint32_t LDPRR24D;                          /**< ldprofilereg24d, offset: 0x34 */
  __IO uint32_t LDPRR24E;                          /**< ldprofilereg24e, offset: 0x38 */
  __IO uint32_t LDPRR24F;                          /**< ldprofilereg24f, offset: 0x3C */
  __IO uint32_t LDPRR250;                          /**< ldprofilereg250, offset: 0x40 */
  __IO uint32_t LDPRR251;                          /**< ldprofilereg251, offset: 0x44 */
  __IO uint32_t LDPRR252;                          /**< ldprofilereg252, offset: 0x48 */
  __IO uint32_t LDPRR253;                          /**< ldprofilereg253, offset: 0x4C */
  __IO uint32_t LDPRR254;                          /**< ldprofilereg254, offset: 0x50 */
  __IO uint32_t LDPRR255;                          /**< ldprofilereg255, offset: 0x54 */
  __IO uint32_t LDPRR256;                          /**< ldprofilereg256, offset: 0x58 */
  __IO uint32_t LDPRR257;                          /**< ldprofilereg257, offset: 0x5C */
} locald45_Type;

/* ----------------------------------------------------------------------------
   -- locald45 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald45_Register_Masks locald45 Register Masks
 * @{
 */

/*! @name LDPRR240 - ldprofilereg240 */
/*! @{ */

#define locald45_LDPRR240_lumd865_MASK           (0x3FFU)
#define locald45_LDPRR240_lumd865_SHIFT          (0U)
/*! lumd865 - lumdat_865 */
#define locald45_LDPRR240_lumd865(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR240_lumd865_SHIFT)) & locald45_LDPRR240_lumd865_MASK)

#define locald45_LDPRR240_lumd864_MASK           (0x3FF0000U)
#define locald45_LDPRR240_lumd864_SHIFT          (16U)
/*! lumd864 - lumdat_864 */
#define locald45_LDPRR240_lumd864(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR240_lumd864_SHIFT)) & locald45_LDPRR240_lumd864_MASK)
/*! @} */

/*! @name LDPRR241 - ldprofilereg241 */
/*! @{ */

#define locald45_LDPRR241_lumd867_MASK           (0x3FFU)
#define locald45_LDPRR241_lumd867_SHIFT          (0U)
/*! lumd867 - lumdat_867 */
#define locald45_LDPRR241_lumd867(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR241_lumd867_SHIFT)) & locald45_LDPRR241_lumd867_MASK)

#define locald45_LDPRR241_lumd866_MASK           (0x3FF0000U)
#define locald45_LDPRR241_lumd866_SHIFT          (16U)
/*! lumd866 - lumdat_866 */
#define locald45_LDPRR241_lumd866(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR241_lumd866_SHIFT)) & locald45_LDPRR241_lumd866_MASK)
/*! @} */

/*! @name LDPRR242 - ldprofilereg242 */
/*! @{ */

#define locald45_LDPRR242_lumd869_MASK           (0x3FFU)
#define locald45_LDPRR242_lumd869_SHIFT          (0U)
/*! lumd869 - lumdat_869 */
#define locald45_LDPRR242_lumd869(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR242_lumd869_SHIFT)) & locald45_LDPRR242_lumd869_MASK)

#define locald45_LDPRR242_lumd868_MASK           (0x3FF0000U)
#define locald45_LDPRR242_lumd868_SHIFT          (16U)
/*! lumd868 - lumdat_868 */
#define locald45_LDPRR242_lumd868(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR242_lumd868_SHIFT)) & locald45_LDPRR242_lumd868_MASK)
/*! @} */

/*! @name LDPRR243 - ldprofilereg243 */
/*! @{ */

#define locald45_LDPRR243_lumd871_MASK           (0x3FFU)
#define locald45_LDPRR243_lumd871_SHIFT          (0U)
/*! lumd871 - lumdat_871 */
#define locald45_LDPRR243_lumd871(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR243_lumd871_SHIFT)) & locald45_LDPRR243_lumd871_MASK)

#define locald45_LDPRR243_lumd870_MASK           (0x3FF0000U)
#define locald45_LDPRR243_lumd870_SHIFT          (16U)
/*! lumd870 - lumdat_870 */
#define locald45_LDPRR243_lumd870(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR243_lumd870_SHIFT)) & locald45_LDPRR243_lumd870_MASK)
/*! @} */

/*! @name LDPRR244 - ldprofilereg244 */
/*! @{ */

#define locald45_LDPRR244_lumd873_MASK           (0x3FFU)
#define locald45_LDPRR244_lumd873_SHIFT          (0U)
/*! lumd873 - lumdat_873 */
#define locald45_LDPRR244_lumd873(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR244_lumd873_SHIFT)) & locald45_LDPRR244_lumd873_MASK)

#define locald45_LDPRR244_lumd872_MASK           (0x3FF0000U)
#define locald45_LDPRR244_lumd872_SHIFT          (16U)
/*! lumd872 - lumdat_872 */
#define locald45_LDPRR244_lumd872(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR244_lumd872_SHIFT)) & locald45_LDPRR244_lumd872_MASK)
/*! @} */

/*! @name LDPRR245 - ldprofilereg245 */
/*! @{ */

#define locald45_LDPRR245_lumd875_MASK           (0x3FFU)
#define locald45_LDPRR245_lumd875_SHIFT          (0U)
/*! lumd875 - lumdat_875 */
#define locald45_LDPRR245_lumd875(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR245_lumd875_SHIFT)) & locald45_LDPRR245_lumd875_MASK)

#define locald45_LDPRR245_lumd874_MASK           (0x3FF0000U)
#define locald45_LDPRR245_lumd874_SHIFT          (16U)
/*! lumd874 - lumdat_874 */
#define locald45_LDPRR245_lumd874(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR245_lumd874_SHIFT)) & locald45_LDPRR245_lumd874_MASK)
/*! @} */

/*! @name LDPRR246 - ldprofilereg246 */
/*! @{ */

#define locald45_LDPRR246_lumd877_MASK           (0x3FFU)
#define locald45_LDPRR246_lumd877_SHIFT          (0U)
/*! lumd877 - lumdat_877 */
#define locald45_LDPRR246_lumd877(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR246_lumd877_SHIFT)) & locald45_LDPRR246_lumd877_MASK)

#define locald45_LDPRR246_lumd876_MASK           (0x3FF0000U)
#define locald45_LDPRR246_lumd876_SHIFT          (16U)
/*! lumd876 - lumdat_876 */
#define locald45_LDPRR246_lumd876(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR246_lumd876_SHIFT)) & locald45_LDPRR246_lumd876_MASK)
/*! @} */

/*! @name LDPRR247 - ldprofilereg247 */
/*! @{ */

#define locald45_LDPRR247_lumd879_MASK           (0x3FFU)
#define locald45_LDPRR247_lumd879_SHIFT          (0U)
/*! lumd879 - lumdat_879 */
#define locald45_LDPRR247_lumd879(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR247_lumd879_SHIFT)) & locald45_LDPRR247_lumd879_MASK)

#define locald45_LDPRR247_lumd878_MASK           (0x3FF0000U)
#define locald45_LDPRR247_lumd878_SHIFT          (16U)
/*! lumd878 - lumdat_878 */
#define locald45_LDPRR247_lumd878(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR247_lumd878_SHIFT)) & locald45_LDPRR247_lumd878_MASK)
/*! @} */

/*! @name LDPRR248 - ldprofilereg248 */
/*! @{ */

#define locald45_LDPRR248_lumd881_MASK           (0x3FFU)
#define locald45_LDPRR248_lumd881_SHIFT          (0U)
/*! lumd881 - lumdat_881 */
#define locald45_LDPRR248_lumd881(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR248_lumd881_SHIFT)) & locald45_LDPRR248_lumd881_MASK)

#define locald45_LDPRR248_lumd880_MASK           (0x3FF0000U)
#define locald45_LDPRR248_lumd880_SHIFT          (16U)
/*! lumd880 - lumdat_880 */
#define locald45_LDPRR248_lumd880(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR248_lumd880_SHIFT)) & locald45_LDPRR248_lumd880_MASK)
/*! @} */

/*! @name LDPRR249 - ldprofilereg249 */
/*! @{ */

#define locald45_LDPRR249_lumd883_MASK           (0x3FFU)
#define locald45_LDPRR249_lumd883_SHIFT          (0U)
/*! lumd883 - lumdat_883 */
#define locald45_LDPRR249_lumd883(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR249_lumd883_SHIFT)) & locald45_LDPRR249_lumd883_MASK)

#define locald45_LDPRR249_lumd882_MASK           (0x3FF0000U)
#define locald45_LDPRR249_lumd882_SHIFT          (16U)
/*! lumd882 - lumdat_882 */
#define locald45_LDPRR249_lumd882(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR249_lumd882_SHIFT)) & locald45_LDPRR249_lumd882_MASK)
/*! @} */

/*! @name LDPRR24A - ldprofilereg24a */
/*! @{ */

#define locald45_LDPRR24A_lumd885_MASK           (0x3FFU)
#define locald45_LDPRR24A_lumd885_SHIFT          (0U)
/*! lumd885 - lumdat_885 */
#define locald45_LDPRR24A_lumd885(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24A_lumd885_SHIFT)) & locald45_LDPRR24A_lumd885_MASK)

#define locald45_LDPRR24A_lumd884_MASK           (0x3FF0000U)
#define locald45_LDPRR24A_lumd884_SHIFT          (16U)
/*! lumd884 - lumdat_884 */
#define locald45_LDPRR24A_lumd884(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24A_lumd884_SHIFT)) & locald45_LDPRR24A_lumd884_MASK)
/*! @} */

/*! @name LDPRR24B - ldprofilereg24b */
/*! @{ */

#define locald45_LDPRR24B_lumd887_MASK           (0x3FFU)
#define locald45_LDPRR24B_lumd887_SHIFT          (0U)
/*! lumd887 - lumdat_887 */
#define locald45_LDPRR24B_lumd887(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24B_lumd887_SHIFT)) & locald45_LDPRR24B_lumd887_MASK)

#define locald45_LDPRR24B_lumd886_MASK           (0x3FF0000U)
#define locald45_LDPRR24B_lumd886_SHIFT          (16U)
/*! lumd886 - lumdat_886 */
#define locald45_LDPRR24B_lumd886(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24B_lumd886_SHIFT)) & locald45_LDPRR24B_lumd886_MASK)
/*! @} */

/*! @name LDPRR24C - ldprofilereg24c */
/*! @{ */

#define locald45_LDPRR24C_lumd889_MASK           (0x3FFU)
#define locald45_LDPRR24C_lumd889_SHIFT          (0U)
/*! lumd889 - lumdat_889 */
#define locald45_LDPRR24C_lumd889(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24C_lumd889_SHIFT)) & locald45_LDPRR24C_lumd889_MASK)

#define locald45_LDPRR24C_lumd888_MASK           (0x3FF0000U)
#define locald45_LDPRR24C_lumd888_SHIFT          (16U)
/*! lumd888 - lumdat_888 */
#define locald45_LDPRR24C_lumd888(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24C_lumd888_SHIFT)) & locald45_LDPRR24C_lumd888_MASK)
/*! @} */

/*! @name LDPRR24D - ldprofilereg24d */
/*! @{ */

#define locald45_LDPRR24D_lumd891_MASK           (0x3FFU)
#define locald45_LDPRR24D_lumd891_SHIFT          (0U)
/*! lumd891 - lumdat_891 */
#define locald45_LDPRR24D_lumd891(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24D_lumd891_SHIFT)) & locald45_LDPRR24D_lumd891_MASK)

#define locald45_LDPRR24D_lumd890_MASK           (0x3FF0000U)
#define locald45_LDPRR24D_lumd890_SHIFT          (16U)
/*! lumd890 - lumdat_890 */
#define locald45_LDPRR24D_lumd890(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24D_lumd890_SHIFT)) & locald45_LDPRR24D_lumd890_MASK)
/*! @} */

/*! @name LDPRR24E - ldprofilereg24e */
/*! @{ */

#define locald45_LDPRR24E_lumd893_MASK           (0x3FFU)
#define locald45_LDPRR24E_lumd893_SHIFT          (0U)
/*! lumd893 - lumdat_893 */
#define locald45_LDPRR24E_lumd893(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24E_lumd893_SHIFT)) & locald45_LDPRR24E_lumd893_MASK)

#define locald45_LDPRR24E_lumd892_MASK           (0x3FF0000U)
#define locald45_LDPRR24E_lumd892_SHIFT          (16U)
/*! lumd892 - lumdat_892 */
#define locald45_LDPRR24E_lumd892(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24E_lumd892_SHIFT)) & locald45_LDPRR24E_lumd892_MASK)
/*! @} */

/*! @name LDPRR24F - ldprofilereg24f */
/*! @{ */

#define locald45_LDPRR24F_lumd895_MASK           (0x3FFU)
#define locald45_LDPRR24F_lumd895_SHIFT          (0U)
/*! lumd895 - lumdat_895 */
#define locald45_LDPRR24F_lumd895(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24F_lumd895_SHIFT)) & locald45_LDPRR24F_lumd895_MASK)

#define locald45_LDPRR24F_lumd894_MASK           (0x3FF0000U)
#define locald45_LDPRR24F_lumd894_SHIFT          (16U)
/*! lumd894 - lumdat_894 */
#define locald45_LDPRR24F_lumd894(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR24F_lumd894_SHIFT)) & locald45_LDPRR24F_lumd894_MASK)
/*! @} */

/*! @name LDPRR250 - ldprofilereg250 */
/*! @{ */

#define locald45_LDPRR250_lumd897_MASK           (0x3FFU)
#define locald45_LDPRR250_lumd897_SHIFT          (0U)
/*! lumd897 - lumdat_897 */
#define locald45_LDPRR250_lumd897(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR250_lumd897_SHIFT)) & locald45_LDPRR250_lumd897_MASK)

#define locald45_LDPRR250_lumd896_MASK           (0x3FF0000U)
#define locald45_LDPRR250_lumd896_SHIFT          (16U)
/*! lumd896 - lumdat_896 */
#define locald45_LDPRR250_lumd896(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR250_lumd896_SHIFT)) & locald45_LDPRR250_lumd896_MASK)
/*! @} */

/*! @name LDPRR251 - ldprofilereg251 */
/*! @{ */

#define locald45_LDPRR251_lumd899_MASK           (0x3FFU)
#define locald45_LDPRR251_lumd899_SHIFT          (0U)
/*! lumd899 - lumdat_899 */
#define locald45_LDPRR251_lumd899(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR251_lumd899_SHIFT)) & locald45_LDPRR251_lumd899_MASK)

#define locald45_LDPRR251_lumd898_MASK           (0x3FF0000U)
#define locald45_LDPRR251_lumd898_SHIFT          (16U)
/*! lumd898 - lumdat_898 */
#define locald45_LDPRR251_lumd898(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR251_lumd898_SHIFT)) & locald45_LDPRR251_lumd898_MASK)
/*! @} */

/*! @name LDPRR252 - ldprofilereg252 */
/*! @{ */

#define locald45_LDPRR252_lumd901_MASK           (0x3FFU)
#define locald45_LDPRR252_lumd901_SHIFT          (0U)
/*! lumd901 - lumdat_901 */
#define locald45_LDPRR252_lumd901(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR252_lumd901_SHIFT)) & locald45_LDPRR252_lumd901_MASK)

#define locald45_LDPRR252_lumd900_MASK           (0x3FF0000U)
#define locald45_LDPRR252_lumd900_SHIFT          (16U)
/*! lumd900 - lumdat_900 */
#define locald45_LDPRR252_lumd900(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR252_lumd900_SHIFT)) & locald45_LDPRR252_lumd900_MASK)
/*! @} */

/*! @name LDPRR253 - ldprofilereg253 */
/*! @{ */

#define locald45_LDPRR253_lumd903_MASK           (0x3FFU)
#define locald45_LDPRR253_lumd903_SHIFT          (0U)
/*! lumd903 - lumdat_903 */
#define locald45_LDPRR253_lumd903(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR253_lumd903_SHIFT)) & locald45_LDPRR253_lumd903_MASK)

#define locald45_LDPRR253_lumd902_MASK           (0x3FF0000U)
#define locald45_LDPRR253_lumd902_SHIFT          (16U)
/*! lumd902 - lumdat_902 */
#define locald45_LDPRR253_lumd902(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR253_lumd902_SHIFT)) & locald45_LDPRR253_lumd902_MASK)
/*! @} */

/*! @name LDPRR254 - ldprofilereg254 */
/*! @{ */

#define locald45_LDPRR254_lumd905_MASK           (0x3FFU)
#define locald45_LDPRR254_lumd905_SHIFT          (0U)
/*! lumd905 - lumdat_905 */
#define locald45_LDPRR254_lumd905(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR254_lumd905_SHIFT)) & locald45_LDPRR254_lumd905_MASK)

#define locald45_LDPRR254_lumd904_MASK           (0x3FF0000U)
#define locald45_LDPRR254_lumd904_SHIFT          (16U)
/*! lumd904 - lumdat_904 */
#define locald45_LDPRR254_lumd904(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR254_lumd904_SHIFT)) & locald45_LDPRR254_lumd904_MASK)
/*! @} */

/*! @name LDPRR255 - ldprofilereg255 */
/*! @{ */

#define locald45_LDPRR255_lumd907_MASK           (0x3FFU)
#define locald45_LDPRR255_lumd907_SHIFT          (0U)
/*! lumd907 - lumdat_907 */
#define locald45_LDPRR255_lumd907(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR255_lumd907_SHIFT)) & locald45_LDPRR255_lumd907_MASK)

#define locald45_LDPRR255_lumd906_MASK           (0x3FF0000U)
#define locald45_LDPRR255_lumd906_SHIFT          (16U)
/*! lumd906 - lumdat_906 */
#define locald45_LDPRR255_lumd906(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR255_lumd906_SHIFT)) & locald45_LDPRR255_lumd906_MASK)
/*! @} */

/*! @name LDPRR256 - ldprofilereg256 */
/*! @{ */

#define locald45_LDPRR256_lumd909_MASK           (0x3FFU)
#define locald45_LDPRR256_lumd909_SHIFT          (0U)
/*! lumd909 - lumdat_909 */
#define locald45_LDPRR256_lumd909(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR256_lumd909_SHIFT)) & locald45_LDPRR256_lumd909_MASK)

#define locald45_LDPRR256_lumd908_MASK           (0x3FF0000U)
#define locald45_LDPRR256_lumd908_SHIFT          (16U)
/*! lumd908 - lumdat_908 */
#define locald45_LDPRR256_lumd908(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR256_lumd908_SHIFT)) & locald45_LDPRR256_lumd908_MASK)
/*! @} */

/*! @name LDPRR257 - ldprofilereg257 */
/*! @{ */

#define locald45_LDPRR257_lumd911_MASK           (0x3FFU)
#define locald45_LDPRR257_lumd911_SHIFT          (0U)
/*! lumd911 - lumdat_911 */
#define locald45_LDPRR257_lumd911(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR257_lumd911_SHIFT)) & locald45_LDPRR257_lumd911_MASK)

#define locald45_LDPRR257_lumd910_MASK           (0x3FF0000U)
#define locald45_LDPRR257_lumd910_SHIFT          (16U)
/*! lumd910 - lumdat_910 */
#define locald45_LDPRR257_lumd910(x)             (((uint32_t)(((uint32_t)(x)) << locald45_LDPRR257_lumd910_SHIFT)) & locald45_LDPRR257_lumd910_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald45_Register_Masks */


/*!
 * @}
 */ /* end of group locald45_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD45_H_ */

