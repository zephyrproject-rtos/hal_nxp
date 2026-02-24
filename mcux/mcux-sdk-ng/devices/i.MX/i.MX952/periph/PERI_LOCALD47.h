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
**         CMSIS Peripheral Access Layer for locald47
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
 * @file PERI_locald47.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald47
 *
 * CMSIS Peripheral Access Layer for locald47
 */

#if !defined(PERI_LOCALD47_H_)
#define PERI_LOCALD47_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald47 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald47_Peripheral_Access_Layer locald47 Peripheral Access Layer
 * @{
 */

/** locald47 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR280;                          /**< ldprofilereg280, offset: 0x0 */
  __IO uint32_t LDPRR281;                          /**< ldprofilereg281, offset: 0x4 */
  __IO uint32_t LDPRR282;                          /**< ldprofilereg282, offset: 0x8 */
  __IO uint32_t LDPRR283;                          /**< ldprofilereg283, offset: 0xC */
  __IO uint32_t LDPRR284;                          /**< ldprofilereg284, offset: 0x10 */
  __IO uint32_t LDPRR285;                          /**< ldprofilereg285, offset: 0x14 */
  __IO uint32_t LDPRR286;                          /**< ldprofilereg286, offset: 0x18 */
  __IO uint32_t LDPRR287;                          /**< ldprofilereg287, offset: 0x1C */
  __IO uint32_t LDPRR288;                          /**< ldprofilereg288, offset: 0x20 */
  __IO uint32_t LDPRR289;                          /**< ldprofilereg289, offset: 0x24 */
  __IO uint32_t LDPRR28A;                          /**< ldprofilereg28a, offset: 0x28 */
  __IO uint32_t LDPRR28B;                          /**< ldprofilereg28b, offset: 0x2C */
  __IO uint32_t LDPRR28C;                          /**< ldprofilereg28c, offset: 0x30 */
  __IO uint32_t LDPRR28D;                          /**< ldprofilereg28d, offset: 0x34 */
  __IO uint32_t LDPRR28E;                          /**< ldprofilereg28e, offset: 0x38 */
  __IO uint32_t LDPRR28F;                          /**< ldprofilereg28f, offset: 0x3C */
  __IO uint32_t LDPRR290;                          /**< ldprofilereg290, offset: 0x40 */
  __IO uint32_t LDPRR291;                          /**< ldprofilereg291, offset: 0x44 */
  __IO uint32_t LDPRR292;                          /**< ldprofilereg292, offset: 0x48 */
  __IO uint32_t LDPRR293;                          /**< ldprofilereg293, offset: 0x4C */
  __IO uint32_t LDPRR294;                          /**< ldprofilereg294, offset: 0x50 */
  __IO uint32_t LDPRR295;                          /**< ldprofilereg295, offset: 0x54 */
  __IO uint32_t LDPRR296;                          /**< ldprofilereg296, offset: 0x58 */
  __IO uint32_t LDPRR297;                          /**< ldprofilereg297, offset: 0x5C */
} locald47_Type;

/* ----------------------------------------------------------------------------
   -- locald47 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald47_Register_Masks locald47 Register Masks
 * @{
 */

/*! @name LDPRR280 - ldprofilereg280 */
/*! @{ */

#define locald47_LDPRR280_lumd961_MASK           (0x3FFU)
#define locald47_LDPRR280_lumd961_SHIFT          (0U)
/*! lumd961 - lumdat_961 */
#define locald47_LDPRR280_lumd961(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR280_lumd961_SHIFT)) & locald47_LDPRR280_lumd961_MASK)

#define locald47_LDPRR280_lumd960_MASK           (0x3FF0000U)
#define locald47_LDPRR280_lumd960_SHIFT          (16U)
/*! lumd960 - lumdat_960 */
#define locald47_LDPRR280_lumd960(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR280_lumd960_SHIFT)) & locald47_LDPRR280_lumd960_MASK)
/*! @} */

/*! @name LDPRR281 - ldprofilereg281 */
/*! @{ */

#define locald47_LDPRR281_lumd963_MASK           (0x3FFU)
#define locald47_LDPRR281_lumd963_SHIFT          (0U)
/*! lumd963 - lumdat_963 */
#define locald47_LDPRR281_lumd963(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR281_lumd963_SHIFT)) & locald47_LDPRR281_lumd963_MASK)

#define locald47_LDPRR281_lumd962_MASK           (0x3FF0000U)
#define locald47_LDPRR281_lumd962_SHIFT          (16U)
/*! lumd962 - lumdat_962 */
#define locald47_LDPRR281_lumd962(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR281_lumd962_SHIFT)) & locald47_LDPRR281_lumd962_MASK)
/*! @} */

/*! @name LDPRR282 - ldprofilereg282 */
/*! @{ */

#define locald47_LDPRR282_lumd965_MASK           (0x3FFU)
#define locald47_LDPRR282_lumd965_SHIFT          (0U)
/*! lumd965 - lumdat_965 */
#define locald47_LDPRR282_lumd965(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR282_lumd965_SHIFT)) & locald47_LDPRR282_lumd965_MASK)

#define locald47_LDPRR282_lumd964_MASK           (0x3FF0000U)
#define locald47_LDPRR282_lumd964_SHIFT          (16U)
/*! lumd964 - lumdat_964 */
#define locald47_LDPRR282_lumd964(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR282_lumd964_SHIFT)) & locald47_LDPRR282_lumd964_MASK)
/*! @} */

/*! @name LDPRR283 - ldprofilereg283 */
/*! @{ */

#define locald47_LDPRR283_lumd967_MASK           (0x3FFU)
#define locald47_LDPRR283_lumd967_SHIFT          (0U)
/*! lumd967 - lumdat_967 */
#define locald47_LDPRR283_lumd967(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR283_lumd967_SHIFT)) & locald47_LDPRR283_lumd967_MASK)

#define locald47_LDPRR283_lumd966_MASK           (0x3FF0000U)
#define locald47_LDPRR283_lumd966_SHIFT          (16U)
/*! lumd966 - lumdat_966 */
#define locald47_LDPRR283_lumd966(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR283_lumd966_SHIFT)) & locald47_LDPRR283_lumd966_MASK)
/*! @} */

/*! @name LDPRR284 - ldprofilereg284 */
/*! @{ */

#define locald47_LDPRR284_lumd969_MASK           (0x3FFU)
#define locald47_LDPRR284_lumd969_SHIFT          (0U)
/*! lumd969 - lumdat_969 */
#define locald47_LDPRR284_lumd969(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR284_lumd969_SHIFT)) & locald47_LDPRR284_lumd969_MASK)

#define locald47_LDPRR284_lumd968_MASK           (0x3FF0000U)
#define locald47_LDPRR284_lumd968_SHIFT          (16U)
/*! lumd968 - lumdat_968 */
#define locald47_LDPRR284_lumd968(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR284_lumd968_SHIFT)) & locald47_LDPRR284_lumd968_MASK)
/*! @} */

/*! @name LDPRR285 - ldprofilereg285 */
/*! @{ */

#define locald47_LDPRR285_lumd971_MASK           (0x3FFU)
#define locald47_LDPRR285_lumd971_SHIFT          (0U)
/*! lumd971 - lumdat_971 */
#define locald47_LDPRR285_lumd971(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR285_lumd971_SHIFT)) & locald47_LDPRR285_lumd971_MASK)

#define locald47_LDPRR285_lumd970_MASK           (0x3FF0000U)
#define locald47_LDPRR285_lumd970_SHIFT          (16U)
/*! lumd970 - lumdat_970 */
#define locald47_LDPRR285_lumd970(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR285_lumd970_SHIFT)) & locald47_LDPRR285_lumd970_MASK)
/*! @} */

/*! @name LDPRR286 - ldprofilereg286 */
/*! @{ */

#define locald47_LDPRR286_lumd973_MASK           (0x3FFU)
#define locald47_LDPRR286_lumd973_SHIFT          (0U)
/*! lumd973 - lumdat_973 */
#define locald47_LDPRR286_lumd973(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR286_lumd973_SHIFT)) & locald47_LDPRR286_lumd973_MASK)

#define locald47_LDPRR286_lumd972_MASK           (0x3FF0000U)
#define locald47_LDPRR286_lumd972_SHIFT          (16U)
/*! lumd972 - lumdat_972 */
#define locald47_LDPRR286_lumd972(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR286_lumd972_SHIFT)) & locald47_LDPRR286_lumd972_MASK)
/*! @} */

/*! @name LDPRR287 - ldprofilereg287 */
/*! @{ */

#define locald47_LDPRR287_lumd975_MASK           (0x3FFU)
#define locald47_LDPRR287_lumd975_SHIFT          (0U)
/*! lumd975 - lumdat_975 */
#define locald47_LDPRR287_lumd975(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR287_lumd975_SHIFT)) & locald47_LDPRR287_lumd975_MASK)

#define locald47_LDPRR287_lumd974_MASK           (0x3FF0000U)
#define locald47_LDPRR287_lumd974_SHIFT          (16U)
/*! lumd974 - lumdat_974 */
#define locald47_LDPRR287_lumd974(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR287_lumd974_SHIFT)) & locald47_LDPRR287_lumd974_MASK)
/*! @} */

/*! @name LDPRR288 - ldprofilereg288 */
/*! @{ */

#define locald47_LDPRR288_lumd977_MASK           (0x3FFU)
#define locald47_LDPRR288_lumd977_SHIFT          (0U)
/*! lumd977 - lumdat_977 */
#define locald47_LDPRR288_lumd977(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR288_lumd977_SHIFT)) & locald47_LDPRR288_lumd977_MASK)

#define locald47_LDPRR288_lumd976_MASK           (0x3FF0000U)
#define locald47_LDPRR288_lumd976_SHIFT          (16U)
/*! lumd976 - lumdat_976 */
#define locald47_LDPRR288_lumd976(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR288_lumd976_SHIFT)) & locald47_LDPRR288_lumd976_MASK)
/*! @} */

/*! @name LDPRR289 - ldprofilereg289 */
/*! @{ */

#define locald47_LDPRR289_lumd979_MASK           (0x3FFU)
#define locald47_LDPRR289_lumd979_SHIFT          (0U)
/*! lumd979 - lumdat_979 */
#define locald47_LDPRR289_lumd979(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR289_lumd979_SHIFT)) & locald47_LDPRR289_lumd979_MASK)

#define locald47_LDPRR289_lumd978_MASK           (0x3FF0000U)
#define locald47_LDPRR289_lumd978_SHIFT          (16U)
/*! lumd978 - lumdat_978 */
#define locald47_LDPRR289_lumd978(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR289_lumd978_SHIFT)) & locald47_LDPRR289_lumd978_MASK)
/*! @} */

/*! @name LDPRR28A - ldprofilereg28a */
/*! @{ */

#define locald47_LDPRR28A_lumd981_MASK           (0x3FFU)
#define locald47_LDPRR28A_lumd981_SHIFT          (0U)
/*! lumd981 - lumdat_981 */
#define locald47_LDPRR28A_lumd981(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28A_lumd981_SHIFT)) & locald47_LDPRR28A_lumd981_MASK)

#define locald47_LDPRR28A_lumd980_MASK           (0x3FF0000U)
#define locald47_LDPRR28A_lumd980_SHIFT          (16U)
/*! lumd980 - lumdat_980 */
#define locald47_LDPRR28A_lumd980(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28A_lumd980_SHIFT)) & locald47_LDPRR28A_lumd980_MASK)
/*! @} */

/*! @name LDPRR28B - ldprofilereg28b */
/*! @{ */

#define locald47_LDPRR28B_lumd983_MASK           (0x3FFU)
#define locald47_LDPRR28B_lumd983_SHIFT          (0U)
/*! lumd983 - lumdat_983 */
#define locald47_LDPRR28B_lumd983(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28B_lumd983_SHIFT)) & locald47_LDPRR28B_lumd983_MASK)

#define locald47_LDPRR28B_lumd982_MASK           (0x3FF0000U)
#define locald47_LDPRR28B_lumd982_SHIFT          (16U)
/*! lumd982 - lumdat_982 */
#define locald47_LDPRR28B_lumd982(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28B_lumd982_SHIFT)) & locald47_LDPRR28B_lumd982_MASK)
/*! @} */

/*! @name LDPRR28C - ldprofilereg28c */
/*! @{ */

#define locald47_LDPRR28C_lumd985_MASK           (0x3FFU)
#define locald47_LDPRR28C_lumd985_SHIFT          (0U)
/*! lumd985 - lumdat_985 */
#define locald47_LDPRR28C_lumd985(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28C_lumd985_SHIFT)) & locald47_LDPRR28C_lumd985_MASK)

#define locald47_LDPRR28C_lumd984_MASK           (0x3FF0000U)
#define locald47_LDPRR28C_lumd984_SHIFT          (16U)
/*! lumd984 - lumdat_984 */
#define locald47_LDPRR28C_lumd984(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28C_lumd984_SHIFT)) & locald47_LDPRR28C_lumd984_MASK)
/*! @} */

/*! @name LDPRR28D - ldprofilereg28d */
/*! @{ */

#define locald47_LDPRR28D_lumd987_MASK           (0x3FFU)
#define locald47_LDPRR28D_lumd987_SHIFT          (0U)
/*! lumd987 - lumdat_987 */
#define locald47_LDPRR28D_lumd987(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28D_lumd987_SHIFT)) & locald47_LDPRR28D_lumd987_MASK)

#define locald47_LDPRR28D_lumd986_MASK           (0x3FF0000U)
#define locald47_LDPRR28D_lumd986_SHIFT          (16U)
/*! lumd986 - lumdat_986 */
#define locald47_LDPRR28D_lumd986(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28D_lumd986_SHIFT)) & locald47_LDPRR28D_lumd986_MASK)
/*! @} */

/*! @name LDPRR28E - ldprofilereg28e */
/*! @{ */

#define locald47_LDPRR28E_lumd989_MASK           (0x3FFU)
#define locald47_LDPRR28E_lumd989_SHIFT          (0U)
/*! lumd989 - lumdat_989 */
#define locald47_LDPRR28E_lumd989(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28E_lumd989_SHIFT)) & locald47_LDPRR28E_lumd989_MASK)

#define locald47_LDPRR28E_lumd988_MASK           (0x3FF0000U)
#define locald47_LDPRR28E_lumd988_SHIFT          (16U)
/*! lumd988 - lumdat_988 */
#define locald47_LDPRR28E_lumd988(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28E_lumd988_SHIFT)) & locald47_LDPRR28E_lumd988_MASK)
/*! @} */

/*! @name LDPRR28F - ldprofilereg28f */
/*! @{ */

#define locald47_LDPRR28F_lumd991_MASK           (0x3FFU)
#define locald47_LDPRR28F_lumd991_SHIFT          (0U)
/*! lumd991 - lumdat_991 */
#define locald47_LDPRR28F_lumd991(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28F_lumd991_SHIFT)) & locald47_LDPRR28F_lumd991_MASK)

#define locald47_LDPRR28F_lumd990_MASK           (0x3FF0000U)
#define locald47_LDPRR28F_lumd990_SHIFT          (16U)
/*! lumd990 - lumdat_990 */
#define locald47_LDPRR28F_lumd990(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR28F_lumd990_SHIFT)) & locald47_LDPRR28F_lumd990_MASK)
/*! @} */

/*! @name LDPRR290 - ldprofilereg290 */
/*! @{ */

#define locald47_LDPRR290_lumd993_MASK           (0x3FFU)
#define locald47_LDPRR290_lumd993_SHIFT          (0U)
/*! lumd993 - lumdat_993 */
#define locald47_LDPRR290_lumd993(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR290_lumd993_SHIFT)) & locald47_LDPRR290_lumd993_MASK)

#define locald47_LDPRR290_lumd992_MASK           (0x3FF0000U)
#define locald47_LDPRR290_lumd992_SHIFT          (16U)
/*! lumd992 - lumdat_992 */
#define locald47_LDPRR290_lumd992(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR290_lumd992_SHIFT)) & locald47_LDPRR290_lumd992_MASK)
/*! @} */

/*! @name LDPRR291 - ldprofilereg291 */
/*! @{ */

#define locald47_LDPRR291_lumd995_MASK           (0x3FFU)
#define locald47_LDPRR291_lumd995_SHIFT          (0U)
/*! lumd995 - lumdat_995 */
#define locald47_LDPRR291_lumd995(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR291_lumd995_SHIFT)) & locald47_LDPRR291_lumd995_MASK)

#define locald47_LDPRR291_lumd994_MASK           (0x3FF0000U)
#define locald47_LDPRR291_lumd994_SHIFT          (16U)
/*! lumd994 - lumdat_994 */
#define locald47_LDPRR291_lumd994(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR291_lumd994_SHIFT)) & locald47_LDPRR291_lumd994_MASK)
/*! @} */

/*! @name LDPRR292 - ldprofilereg292 */
/*! @{ */

#define locald47_LDPRR292_lumd997_MASK           (0x3FFU)
#define locald47_LDPRR292_lumd997_SHIFT          (0U)
/*! lumd997 - lumdat_997 */
#define locald47_LDPRR292_lumd997(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR292_lumd997_SHIFT)) & locald47_LDPRR292_lumd997_MASK)

#define locald47_LDPRR292_lumd996_MASK           (0x3FF0000U)
#define locald47_LDPRR292_lumd996_SHIFT          (16U)
/*! lumd996 - lumdat_996 */
#define locald47_LDPRR292_lumd996(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR292_lumd996_SHIFT)) & locald47_LDPRR292_lumd996_MASK)
/*! @} */

/*! @name LDPRR293 - ldprofilereg293 */
/*! @{ */

#define locald47_LDPRR293_lumd999_MASK           (0x3FFU)
#define locald47_LDPRR293_lumd999_SHIFT          (0U)
/*! lumd999 - lumdat_999 */
#define locald47_LDPRR293_lumd999(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR293_lumd999_SHIFT)) & locald47_LDPRR293_lumd999_MASK)

#define locald47_LDPRR293_lumd998_MASK           (0x3FF0000U)
#define locald47_LDPRR293_lumd998_SHIFT          (16U)
/*! lumd998 - lumdat_998 */
#define locald47_LDPRR293_lumd998(x)             (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR293_lumd998_SHIFT)) & locald47_LDPRR293_lumd998_MASK)
/*! @} */

/*! @name LDPRR294 - ldprofilereg294 */
/*! @{ */

#define locald47_LDPRR294_lumd1001_MASK          (0x3FFU)
#define locald47_LDPRR294_lumd1001_SHIFT         (0U)
/*! lumd1001 - lumdat_1001 */
#define locald47_LDPRR294_lumd1001(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR294_lumd1001_SHIFT)) & locald47_LDPRR294_lumd1001_MASK)

#define locald47_LDPRR294_lumd1000_MASK          (0x3FF0000U)
#define locald47_LDPRR294_lumd1000_SHIFT         (16U)
/*! lumd1000 - lumdat_1000 */
#define locald47_LDPRR294_lumd1000(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR294_lumd1000_SHIFT)) & locald47_LDPRR294_lumd1000_MASK)
/*! @} */

/*! @name LDPRR295 - ldprofilereg295 */
/*! @{ */

#define locald47_LDPRR295_lumd1003_MASK          (0x3FFU)
#define locald47_LDPRR295_lumd1003_SHIFT         (0U)
/*! lumd1003 - lumdat_1003 */
#define locald47_LDPRR295_lumd1003(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR295_lumd1003_SHIFT)) & locald47_LDPRR295_lumd1003_MASK)

#define locald47_LDPRR295_lumd1002_MASK          (0x3FF0000U)
#define locald47_LDPRR295_lumd1002_SHIFT         (16U)
/*! lumd1002 - lumdat_1002 */
#define locald47_LDPRR295_lumd1002(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR295_lumd1002_SHIFT)) & locald47_LDPRR295_lumd1002_MASK)
/*! @} */

/*! @name LDPRR296 - ldprofilereg296 */
/*! @{ */

#define locald47_LDPRR296_lumd1005_MASK          (0x3FFU)
#define locald47_LDPRR296_lumd1005_SHIFT         (0U)
/*! lumd1005 - lumdat_1005 */
#define locald47_LDPRR296_lumd1005(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR296_lumd1005_SHIFT)) & locald47_LDPRR296_lumd1005_MASK)

#define locald47_LDPRR296_lumd1004_MASK          (0x3FF0000U)
#define locald47_LDPRR296_lumd1004_SHIFT         (16U)
/*! lumd1004 - lumdat_1004 */
#define locald47_LDPRR296_lumd1004(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR296_lumd1004_SHIFT)) & locald47_LDPRR296_lumd1004_MASK)
/*! @} */

/*! @name LDPRR297 - ldprofilereg297 */
/*! @{ */

#define locald47_LDPRR297_lumd1007_MASK          (0x3FFU)
#define locald47_LDPRR297_lumd1007_SHIFT         (0U)
/*! lumd1007 - lumdat_1007 */
#define locald47_LDPRR297_lumd1007(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR297_lumd1007_SHIFT)) & locald47_LDPRR297_lumd1007_MASK)

#define locald47_LDPRR297_lumd1006_MASK          (0x3FF0000U)
#define locald47_LDPRR297_lumd1006_SHIFT         (16U)
/*! lumd1006 - lumdat_1006 */
#define locald47_LDPRR297_lumd1006(x)            (((uint32_t)(((uint32_t)(x)) << locald47_LDPRR297_lumd1006_SHIFT)) & locald47_LDPRR297_lumd1006_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald47_Register_Masks */


/*!
 * @}
 */ /* end of group locald47_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD47_H_ */

