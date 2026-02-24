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
**         CMSIS Peripheral Access Layer for locald67
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
 * @file PERI_locald67.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald67
 *
 * CMSIS Peripheral Access Layer for locald67
 */

#if !defined(PERI_LOCALD67_H_)
#define PERI_LOCALD67_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald67 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald67_Peripheral_Access_Layer locald67 Peripheral Access Layer
 * @{
 */

/** locald67 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR500;                          /**< ldprofilereg500, offset: 0x0 */
  __IO uint32_t LDPRR501;                          /**< ldprofilereg501, offset: 0x4 */
  __IO uint32_t LDPRR502;                          /**< ldprofilereg502, offset: 0x8 */
  __IO uint32_t LDPRR503;                          /**< ldprofilereg503, offset: 0xC */
  __IO uint32_t LDPRR504;                          /**< ldprofilereg504, offset: 0x10 */
  __IO uint32_t LDPRR505;                          /**< ldprofilereg505, offset: 0x14 */
  __IO uint32_t LDPRR506;                          /**< ldprofilereg506, offset: 0x18 */
  __IO uint32_t LDPRR507;                          /**< ldprofilereg507, offset: 0x1C */
  __IO uint32_t LDPRR508;                          /**< ldprofilereg508, offset: 0x20 */
  __IO uint32_t LDPRR509;                          /**< ldprofilereg509, offset: 0x24 */
  __IO uint32_t LDPRR50A;                          /**< ldprofilereg50a, offset: 0x28 */
  __IO uint32_t LDPRR50B;                          /**< ldprofilereg50b, offset: 0x2C */
  __IO uint32_t LDPRR50C;                          /**< ldprofilereg50c, offset: 0x30 */
  __IO uint32_t LDPRR50D;                          /**< ldprofilereg50d, offset: 0x34 */
  __IO uint32_t LDPRR50E;                          /**< ldprofilereg50e, offset: 0x38 */
  __IO uint32_t LDPRR50F;                          /**< ldprofilereg50f, offset: 0x3C */
  __IO uint32_t LDPRR510;                          /**< ldprofilereg510, offset: 0x40 */
  __IO uint32_t LDPRR511;                          /**< ldprofilereg511, offset: 0x44 */
  __IO uint32_t LDPRR512;                          /**< ldprofilereg512, offset: 0x48 */
  __IO uint32_t LDPRR513;                          /**< ldprofilereg513, offset: 0x4C */
  __IO uint32_t LDPRR514;                          /**< ldprofilereg514, offset: 0x50 */
  __IO uint32_t LDPRR515;                          /**< ldprofilereg515, offset: 0x54 */
  __IO uint32_t LDPRR516;                          /**< ldprofilereg516, offset: 0x58 */
  __IO uint32_t LDPRR517;                          /**< ldprofilereg517, offset: 0x5C */
} locald67_Type;

/* ----------------------------------------------------------------------------
   -- locald67 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald67_Register_Masks locald67 Register Masks
 * @{
 */

/*! @name LDPRR500 - ldprofilereg500 */
/*! @{ */

#define locald67_LDPRR500_lumd1921_MASK          (0x3FFU)
#define locald67_LDPRR500_lumd1921_SHIFT         (0U)
/*! lumd1921 - lumdat_1921 */
#define locald67_LDPRR500_lumd1921(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR500_lumd1921_SHIFT)) & locald67_LDPRR500_lumd1921_MASK)

#define locald67_LDPRR500_lumd1920_MASK          (0x3FF0000U)
#define locald67_LDPRR500_lumd1920_SHIFT         (16U)
/*! lumd1920 - lumdat_1920 */
#define locald67_LDPRR500_lumd1920(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR500_lumd1920_SHIFT)) & locald67_LDPRR500_lumd1920_MASK)
/*! @} */

/*! @name LDPRR501 - ldprofilereg501 */
/*! @{ */

#define locald67_LDPRR501_lumd1923_MASK          (0x3FFU)
#define locald67_LDPRR501_lumd1923_SHIFT         (0U)
/*! lumd1923 - lumdat_1923 */
#define locald67_LDPRR501_lumd1923(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR501_lumd1923_SHIFT)) & locald67_LDPRR501_lumd1923_MASK)

#define locald67_LDPRR501_lumd1922_MASK          (0x3FF0000U)
#define locald67_LDPRR501_lumd1922_SHIFT         (16U)
/*! lumd1922 - lumdat_1922 */
#define locald67_LDPRR501_lumd1922(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR501_lumd1922_SHIFT)) & locald67_LDPRR501_lumd1922_MASK)
/*! @} */

/*! @name LDPRR502 - ldprofilereg502 */
/*! @{ */

#define locald67_LDPRR502_lumd1925_MASK          (0x3FFU)
#define locald67_LDPRR502_lumd1925_SHIFT         (0U)
/*! lumd1925 - lumdat_1925 */
#define locald67_LDPRR502_lumd1925(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR502_lumd1925_SHIFT)) & locald67_LDPRR502_lumd1925_MASK)

#define locald67_LDPRR502_lumd1924_MASK          (0x3FF0000U)
#define locald67_LDPRR502_lumd1924_SHIFT         (16U)
/*! lumd1924 - lumdat_1924 */
#define locald67_LDPRR502_lumd1924(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR502_lumd1924_SHIFT)) & locald67_LDPRR502_lumd1924_MASK)
/*! @} */

/*! @name LDPRR503 - ldprofilereg503 */
/*! @{ */

#define locald67_LDPRR503_lumd1927_MASK          (0x3FFU)
#define locald67_LDPRR503_lumd1927_SHIFT         (0U)
/*! lumd1927 - lumdat_1927 */
#define locald67_LDPRR503_lumd1927(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR503_lumd1927_SHIFT)) & locald67_LDPRR503_lumd1927_MASK)

#define locald67_LDPRR503_lumd1926_MASK          (0x3FF0000U)
#define locald67_LDPRR503_lumd1926_SHIFT         (16U)
/*! lumd1926 - lumdat_1926 */
#define locald67_LDPRR503_lumd1926(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR503_lumd1926_SHIFT)) & locald67_LDPRR503_lumd1926_MASK)
/*! @} */

/*! @name LDPRR504 - ldprofilereg504 */
/*! @{ */

#define locald67_LDPRR504_lumd1929_MASK          (0x3FFU)
#define locald67_LDPRR504_lumd1929_SHIFT         (0U)
/*! lumd1929 - lumdat_1929 */
#define locald67_LDPRR504_lumd1929(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR504_lumd1929_SHIFT)) & locald67_LDPRR504_lumd1929_MASK)

#define locald67_LDPRR504_lumd1928_MASK          (0x3FF0000U)
#define locald67_LDPRR504_lumd1928_SHIFT         (16U)
/*! lumd1928 - lumdat_1928 */
#define locald67_LDPRR504_lumd1928(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR504_lumd1928_SHIFT)) & locald67_LDPRR504_lumd1928_MASK)
/*! @} */

/*! @name LDPRR505 - ldprofilereg505 */
/*! @{ */

#define locald67_LDPRR505_lumd1931_MASK          (0x3FFU)
#define locald67_LDPRR505_lumd1931_SHIFT         (0U)
/*! lumd1931 - lumdat_1931 */
#define locald67_LDPRR505_lumd1931(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR505_lumd1931_SHIFT)) & locald67_LDPRR505_lumd1931_MASK)

#define locald67_LDPRR505_lumd1930_MASK          (0x3FF0000U)
#define locald67_LDPRR505_lumd1930_SHIFT         (16U)
/*! lumd1930 - lumdat_1930 */
#define locald67_LDPRR505_lumd1930(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR505_lumd1930_SHIFT)) & locald67_LDPRR505_lumd1930_MASK)
/*! @} */

/*! @name LDPRR506 - ldprofilereg506 */
/*! @{ */

#define locald67_LDPRR506_lumd1933_MASK          (0x3FFU)
#define locald67_LDPRR506_lumd1933_SHIFT         (0U)
/*! lumd1933 - lumdat_1933 */
#define locald67_LDPRR506_lumd1933(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR506_lumd1933_SHIFT)) & locald67_LDPRR506_lumd1933_MASK)

#define locald67_LDPRR506_lumd1932_MASK          (0x3FF0000U)
#define locald67_LDPRR506_lumd1932_SHIFT         (16U)
/*! lumd1932 - lumdat_1932 */
#define locald67_LDPRR506_lumd1932(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR506_lumd1932_SHIFT)) & locald67_LDPRR506_lumd1932_MASK)
/*! @} */

/*! @name LDPRR507 - ldprofilereg507 */
/*! @{ */

#define locald67_LDPRR507_lumd1935_MASK          (0x3FFU)
#define locald67_LDPRR507_lumd1935_SHIFT         (0U)
/*! lumd1935 - lumdat_1935 */
#define locald67_LDPRR507_lumd1935(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR507_lumd1935_SHIFT)) & locald67_LDPRR507_lumd1935_MASK)

#define locald67_LDPRR507_lumd1934_MASK          (0x3FF0000U)
#define locald67_LDPRR507_lumd1934_SHIFT         (16U)
/*! lumd1934 - lumdat_1934 */
#define locald67_LDPRR507_lumd1934(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR507_lumd1934_SHIFT)) & locald67_LDPRR507_lumd1934_MASK)
/*! @} */

/*! @name LDPRR508 - ldprofilereg508 */
/*! @{ */

#define locald67_LDPRR508_lumd1937_MASK          (0x3FFU)
#define locald67_LDPRR508_lumd1937_SHIFT         (0U)
/*! lumd1937 - lumdat_1937 */
#define locald67_LDPRR508_lumd1937(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR508_lumd1937_SHIFT)) & locald67_LDPRR508_lumd1937_MASK)

#define locald67_LDPRR508_lumd1936_MASK          (0x3FF0000U)
#define locald67_LDPRR508_lumd1936_SHIFT         (16U)
/*! lumd1936 - lumdat_1936 */
#define locald67_LDPRR508_lumd1936(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR508_lumd1936_SHIFT)) & locald67_LDPRR508_lumd1936_MASK)
/*! @} */

/*! @name LDPRR509 - ldprofilereg509 */
/*! @{ */

#define locald67_LDPRR509_lumd1939_MASK          (0x3FFU)
#define locald67_LDPRR509_lumd1939_SHIFT         (0U)
/*! lumd1939 - lumdat_1939 */
#define locald67_LDPRR509_lumd1939(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR509_lumd1939_SHIFT)) & locald67_LDPRR509_lumd1939_MASK)

#define locald67_LDPRR509_lumd1938_MASK          (0x3FF0000U)
#define locald67_LDPRR509_lumd1938_SHIFT         (16U)
/*! lumd1938 - lumdat_1938 */
#define locald67_LDPRR509_lumd1938(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR509_lumd1938_SHIFT)) & locald67_LDPRR509_lumd1938_MASK)
/*! @} */

/*! @name LDPRR50A - ldprofilereg50a */
/*! @{ */

#define locald67_LDPRR50A_lumd1941_MASK          (0x3FFU)
#define locald67_LDPRR50A_lumd1941_SHIFT         (0U)
/*! lumd1941 - lumdat_1941 */
#define locald67_LDPRR50A_lumd1941(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50A_lumd1941_SHIFT)) & locald67_LDPRR50A_lumd1941_MASK)

#define locald67_LDPRR50A_lumd1940_MASK          (0x3FF0000U)
#define locald67_LDPRR50A_lumd1940_SHIFT         (16U)
/*! lumd1940 - lumdat_1940 */
#define locald67_LDPRR50A_lumd1940(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50A_lumd1940_SHIFT)) & locald67_LDPRR50A_lumd1940_MASK)
/*! @} */

/*! @name LDPRR50B - ldprofilereg50b */
/*! @{ */

#define locald67_LDPRR50B_lumd1943_MASK          (0x3FFU)
#define locald67_LDPRR50B_lumd1943_SHIFT         (0U)
/*! lumd1943 - lumdat_1943 */
#define locald67_LDPRR50B_lumd1943(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50B_lumd1943_SHIFT)) & locald67_LDPRR50B_lumd1943_MASK)

#define locald67_LDPRR50B_lumd1942_MASK          (0x3FF0000U)
#define locald67_LDPRR50B_lumd1942_SHIFT         (16U)
/*! lumd1942 - lumdat_1942 */
#define locald67_LDPRR50B_lumd1942(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50B_lumd1942_SHIFT)) & locald67_LDPRR50B_lumd1942_MASK)
/*! @} */

/*! @name LDPRR50C - ldprofilereg50c */
/*! @{ */

#define locald67_LDPRR50C_lumd1945_MASK          (0x3FFU)
#define locald67_LDPRR50C_lumd1945_SHIFT         (0U)
/*! lumd1945 - lumdat_1945 */
#define locald67_LDPRR50C_lumd1945(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50C_lumd1945_SHIFT)) & locald67_LDPRR50C_lumd1945_MASK)

#define locald67_LDPRR50C_lumd1944_MASK          (0x3FF0000U)
#define locald67_LDPRR50C_lumd1944_SHIFT         (16U)
/*! lumd1944 - lumdat_1944 */
#define locald67_LDPRR50C_lumd1944(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50C_lumd1944_SHIFT)) & locald67_LDPRR50C_lumd1944_MASK)
/*! @} */

/*! @name LDPRR50D - ldprofilereg50d */
/*! @{ */

#define locald67_LDPRR50D_lumd1947_MASK          (0x3FFU)
#define locald67_LDPRR50D_lumd1947_SHIFT         (0U)
/*! lumd1947 - lumdat_1947 */
#define locald67_LDPRR50D_lumd1947(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50D_lumd1947_SHIFT)) & locald67_LDPRR50D_lumd1947_MASK)

#define locald67_LDPRR50D_lumd1946_MASK          (0x3FF0000U)
#define locald67_LDPRR50D_lumd1946_SHIFT         (16U)
/*! lumd1946 - lumdat_1946 */
#define locald67_LDPRR50D_lumd1946(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50D_lumd1946_SHIFT)) & locald67_LDPRR50D_lumd1946_MASK)
/*! @} */

/*! @name LDPRR50E - ldprofilereg50e */
/*! @{ */

#define locald67_LDPRR50E_lumd1949_MASK          (0x3FFU)
#define locald67_LDPRR50E_lumd1949_SHIFT         (0U)
/*! lumd1949 - lumdat_1949 */
#define locald67_LDPRR50E_lumd1949(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50E_lumd1949_SHIFT)) & locald67_LDPRR50E_lumd1949_MASK)

#define locald67_LDPRR50E_lumd1948_MASK          (0x3FF0000U)
#define locald67_LDPRR50E_lumd1948_SHIFT         (16U)
/*! lumd1948 - lumdat_1948 */
#define locald67_LDPRR50E_lumd1948(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50E_lumd1948_SHIFT)) & locald67_LDPRR50E_lumd1948_MASK)
/*! @} */

/*! @name LDPRR50F - ldprofilereg50f */
/*! @{ */

#define locald67_LDPRR50F_lumd1951_MASK          (0x3FFU)
#define locald67_LDPRR50F_lumd1951_SHIFT         (0U)
/*! lumd1951 - lumdat_1951 */
#define locald67_LDPRR50F_lumd1951(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50F_lumd1951_SHIFT)) & locald67_LDPRR50F_lumd1951_MASK)

#define locald67_LDPRR50F_lumd1950_MASK          (0x3FF0000U)
#define locald67_LDPRR50F_lumd1950_SHIFT         (16U)
/*! lumd1950 - lumdat_1950 */
#define locald67_LDPRR50F_lumd1950(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR50F_lumd1950_SHIFT)) & locald67_LDPRR50F_lumd1950_MASK)
/*! @} */

/*! @name LDPRR510 - ldprofilereg510 */
/*! @{ */

#define locald67_LDPRR510_lumd1953_MASK          (0x3FFU)
#define locald67_LDPRR510_lumd1953_SHIFT         (0U)
/*! lumd1953 - lumdat_1953 */
#define locald67_LDPRR510_lumd1953(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR510_lumd1953_SHIFT)) & locald67_LDPRR510_lumd1953_MASK)

#define locald67_LDPRR510_lumd1952_MASK          (0x3FF0000U)
#define locald67_LDPRR510_lumd1952_SHIFT         (16U)
/*! lumd1952 - lumdat_1952 */
#define locald67_LDPRR510_lumd1952(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR510_lumd1952_SHIFT)) & locald67_LDPRR510_lumd1952_MASK)
/*! @} */

/*! @name LDPRR511 - ldprofilereg511 */
/*! @{ */

#define locald67_LDPRR511_lumd1955_MASK          (0x3FFU)
#define locald67_LDPRR511_lumd1955_SHIFT         (0U)
/*! lumd1955 - lumdat_1955 */
#define locald67_LDPRR511_lumd1955(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR511_lumd1955_SHIFT)) & locald67_LDPRR511_lumd1955_MASK)

#define locald67_LDPRR511_lumd1954_MASK          (0x3FF0000U)
#define locald67_LDPRR511_lumd1954_SHIFT         (16U)
/*! lumd1954 - lumdat_1954 */
#define locald67_LDPRR511_lumd1954(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR511_lumd1954_SHIFT)) & locald67_LDPRR511_lumd1954_MASK)
/*! @} */

/*! @name LDPRR512 - ldprofilereg512 */
/*! @{ */

#define locald67_LDPRR512_lumd1957_MASK          (0x3FFU)
#define locald67_LDPRR512_lumd1957_SHIFT         (0U)
/*! lumd1957 - lumdat_1957 */
#define locald67_LDPRR512_lumd1957(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR512_lumd1957_SHIFT)) & locald67_LDPRR512_lumd1957_MASK)

#define locald67_LDPRR512_lumd1956_MASK          (0x3FF0000U)
#define locald67_LDPRR512_lumd1956_SHIFT         (16U)
/*! lumd1956 - lumdat_1956 */
#define locald67_LDPRR512_lumd1956(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR512_lumd1956_SHIFT)) & locald67_LDPRR512_lumd1956_MASK)
/*! @} */

/*! @name LDPRR513 - ldprofilereg513 */
/*! @{ */

#define locald67_LDPRR513_lumd1959_MASK          (0x3FFU)
#define locald67_LDPRR513_lumd1959_SHIFT         (0U)
/*! lumd1959 - lumdat_1959 */
#define locald67_LDPRR513_lumd1959(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR513_lumd1959_SHIFT)) & locald67_LDPRR513_lumd1959_MASK)

#define locald67_LDPRR513_lumd1958_MASK          (0x3FF0000U)
#define locald67_LDPRR513_lumd1958_SHIFT         (16U)
/*! lumd1958 - lumdat_1958 */
#define locald67_LDPRR513_lumd1958(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR513_lumd1958_SHIFT)) & locald67_LDPRR513_lumd1958_MASK)
/*! @} */

/*! @name LDPRR514 - ldprofilereg514 */
/*! @{ */

#define locald67_LDPRR514_lumd1961_MASK          (0x3FFU)
#define locald67_LDPRR514_lumd1961_SHIFT         (0U)
/*! lumd1961 - lumdat_1961 */
#define locald67_LDPRR514_lumd1961(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR514_lumd1961_SHIFT)) & locald67_LDPRR514_lumd1961_MASK)

#define locald67_LDPRR514_lumd1960_MASK          (0x3FF0000U)
#define locald67_LDPRR514_lumd1960_SHIFT         (16U)
/*! lumd1960 - lumdat_1960 */
#define locald67_LDPRR514_lumd1960(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR514_lumd1960_SHIFT)) & locald67_LDPRR514_lumd1960_MASK)
/*! @} */

/*! @name LDPRR515 - ldprofilereg515 */
/*! @{ */

#define locald67_LDPRR515_lumd1963_MASK          (0x3FFU)
#define locald67_LDPRR515_lumd1963_SHIFT         (0U)
/*! lumd1963 - lumdat_1963 */
#define locald67_LDPRR515_lumd1963(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR515_lumd1963_SHIFT)) & locald67_LDPRR515_lumd1963_MASK)

#define locald67_LDPRR515_lumd1962_MASK          (0x3FF0000U)
#define locald67_LDPRR515_lumd1962_SHIFT         (16U)
/*! lumd1962 - lumdat_1962 */
#define locald67_LDPRR515_lumd1962(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR515_lumd1962_SHIFT)) & locald67_LDPRR515_lumd1962_MASK)
/*! @} */

/*! @name LDPRR516 - ldprofilereg516 */
/*! @{ */

#define locald67_LDPRR516_lumd1965_MASK          (0x3FFU)
#define locald67_LDPRR516_lumd1965_SHIFT         (0U)
/*! lumd1965 - lumdat_1965 */
#define locald67_LDPRR516_lumd1965(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR516_lumd1965_SHIFT)) & locald67_LDPRR516_lumd1965_MASK)

#define locald67_LDPRR516_lumd1964_MASK          (0x3FF0000U)
#define locald67_LDPRR516_lumd1964_SHIFT         (16U)
/*! lumd1964 - lumdat_1964 */
#define locald67_LDPRR516_lumd1964(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR516_lumd1964_SHIFT)) & locald67_LDPRR516_lumd1964_MASK)
/*! @} */

/*! @name LDPRR517 - ldprofilereg517 */
/*! @{ */

#define locald67_LDPRR517_lumd1967_MASK          (0x3FFU)
#define locald67_LDPRR517_lumd1967_SHIFT         (0U)
/*! lumd1967 - lumdat_1967 */
#define locald67_LDPRR517_lumd1967(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR517_lumd1967_SHIFT)) & locald67_LDPRR517_lumd1967_MASK)

#define locald67_LDPRR517_lumd1966_MASK          (0x3FF0000U)
#define locald67_LDPRR517_lumd1966_SHIFT         (16U)
/*! lumd1966 - lumdat_1966 */
#define locald67_LDPRR517_lumd1966(x)            (((uint32_t)(((uint32_t)(x)) << locald67_LDPRR517_lumd1966_SHIFT)) & locald67_LDPRR517_lumd1966_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald67_Register_Masks */


/*!
 * @}
 */ /* end of group locald67_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD67_H_ */

