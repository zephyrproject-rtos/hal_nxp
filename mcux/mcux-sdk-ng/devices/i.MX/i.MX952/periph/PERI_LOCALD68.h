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
**         CMSIS Peripheral Access Layer for locald68
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
 * @file PERI_locald68.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald68
 *
 * CMSIS Peripheral Access Layer for locald68
 */

#if !defined(PERI_LOCALD68_H_)
#define PERI_LOCALD68_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald68 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald68_Peripheral_Access_Layer locald68 Peripheral Access Layer
 * @{
 */

/** locald68 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR520;                          /**< ldprofilereg520, offset: 0x0 */
  __IO uint32_t LDPRR521;                          /**< ldprofilereg521, offset: 0x4 */
  __IO uint32_t LDPRR522;                          /**< ldprofilereg522, offset: 0x8 */
  __IO uint32_t LDPRR523;                          /**< ldprofilereg523, offset: 0xC */
  __IO uint32_t LDPRR524;                          /**< ldprofilereg524, offset: 0x10 */
  __IO uint32_t LDPRR525;                          /**< ldprofilereg525, offset: 0x14 */
  __IO uint32_t LDPRR526;                          /**< ldprofilereg526, offset: 0x18 */
  __IO uint32_t LDPRR527;                          /**< ldprofilereg527, offset: 0x1C */
  __IO uint32_t LDPRR528;                          /**< ldprofilereg528, offset: 0x20 */
  __IO uint32_t LDPRR529;                          /**< ldprofilereg529, offset: 0x24 */
  __IO uint32_t LDPRR52A;                          /**< ldprofilereg52a, offset: 0x28 */
  __IO uint32_t LDPRR52B;                          /**< ldprofilereg52b, offset: 0x2C */
  __IO uint32_t LDPRR52C;                          /**< ldprofilereg52c, offset: 0x30 */
  __IO uint32_t LDPRR52D;                          /**< ldprofilereg52d, offset: 0x34 */
  __IO uint32_t LDPRR52E;                          /**< ldprofilereg52e, offset: 0x38 */
  __IO uint32_t LDPRR52F;                          /**< ldprofilereg52f, offset: 0x3C */
  __IO uint32_t LDPRR530;                          /**< ldprofilereg530, offset: 0x40 */
  __IO uint32_t LDPRR531;                          /**< ldprofilereg531, offset: 0x44 */
  __IO uint32_t LDPRR532;                          /**< ldprofilereg532, offset: 0x48 */
  __IO uint32_t LDPRR533;                          /**< ldprofilereg533, offset: 0x4C */
  __IO uint32_t LDPRR534;                          /**< ldprofilereg534, offset: 0x50 */
  __IO uint32_t LDPRR535;                          /**< ldprofilereg535, offset: 0x54 */
  __IO uint32_t LDPRR536;                          /**< ldprofilereg536, offset: 0x58 */
  __IO uint32_t LDPRR537;                          /**< ldprofilereg537, offset: 0x5C */
} locald68_Type;

/* ----------------------------------------------------------------------------
   -- locald68 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald68_Register_Masks locald68 Register Masks
 * @{
 */

/*! @name LDPRR520 - ldprofilereg520 */
/*! @{ */

#define locald68_LDPRR520_lumd1969_MASK          (0x3FFU)
#define locald68_LDPRR520_lumd1969_SHIFT         (0U)
/*! lumd1969 - lumdat_1969 */
#define locald68_LDPRR520_lumd1969(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR520_lumd1969_SHIFT)) & locald68_LDPRR520_lumd1969_MASK)

#define locald68_LDPRR520_lumd1968_MASK          (0x3FF0000U)
#define locald68_LDPRR520_lumd1968_SHIFT         (16U)
/*! lumd1968 - lumdat_1968 */
#define locald68_LDPRR520_lumd1968(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR520_lumd1968_SHIFT)) & locald68_LDPRR520_lumd1968_MASK)
/*! @} */

/*! @name LDPRR521 - ldprofilereg521 */
/*! @{ */

#define locald68_LDPRR521_lumd1971_MASK          (0x3FFU)
#define locald68_LDPRR521_lumd1971_SHIFT         (0U)
/*! lumd1971 - lumdat_1971 */
#define locald68_LDPRR521_lumd1971(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR521_lumd1971_SHIFT)) & locald68_LDPRR521_lumd1971_MASK)

#define locald68_LDPRR521_lumd1970_MASK          (0x3FF0000U)
#define locald68_LDPRR521_lumd1970_SHIFT         (16U)
/*! lumd1970 - lumdat_1970 */
#define locald68_LDPRR521_lumd1970(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR521_lumd1970_SHIFT)) & locald68_LDPRR521_lumd1970_MASK)
/*! @} */

/*! @name LDPRR522 - ldprofilereg522 */
/*! @{ */

#define locald68_LDPRR522_lumd1973_MASK          (0x3FFU)
#define locald68_LDPRR522_lumd1973_SHIFT         (0U)
/*! lumd1973 - lumdat_1973 */
#define locald68_LDPRR522_lumd1973(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR522_lumd1973_SHIFT)) & locald68_LDPRR522_lumd1973_MASK)

#define locald68_LDPRR522_lumd1972_MASK          (0x3FF0000U)
#define locald68_LDPRR522_lumd1972_SHIFT         (16U)
/*! lumd1972 - lumdat_1972 */
#define locald68_LDPRR522_lumd1972(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR522_lumd1972_SHIFT)) & locald68_LDPRR522_lumd1972_MASK)
/*! @} */

/*! @name LDPRR523 - ldprofilereg523 */
/*! @{ */

#define locald68_LDPRR523_lumd1975_MASK          (0x3FFU)
#define locald68_LDPRR523_lumd1975_SHIFT         (0U)
/*! lumd1975 - lumdat_1975 */
#define locald68_LDPRR523_lumd1975(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR523_lumd1975_SHIFT)) & locald68_LDPRR523_lumd1975_MASK)

#define locald68_LDPRR523_lumd1974_MASK          (0x3FF0000U)
#define locald68_LDPRR523_lumd1974_SHIFT         (16U)
/*! lumd1974 - lumdat_1974 */
#define locald68_LDPRR523_lumd1974(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR523_lumd1974_SHIFT)) & locald68_LDPRR523_lumd1974_MASK)
/*! @} */

/*! @name LDPRR524 - ldprofilereg524 */
/*! @{ */

#define locald68_LDPRR524_lumd1977_MASK          (0x3FFU)
#define locald68_LDPRR524_lumd1977_SHIFT         (0U)
/*! lumd1977 - lumdat_1977 */
#define locald68_LDPRR524_lumd1977(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR524_lumd1977_SHIFT)) & locald68_LDPRR524_lumd1977_MASK)

#define locald68_LDPRR524_lumd1976_MASK          (0x3FF0000U)
#define locald68_LDPRR524_lumd1976_SHIFT         (16U)
/*! lumd1976 - lumdat_1976 */
#define locald68_LDPRR524_lumd1976(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR524_lumd1976_SHIFT)) & locald68_LDPRR524_lumd1976_MASK)
/*! @} */

/*! @name LDPRR525 - ldprofilereg525 */
/*! @{ */

#define locald68_LDPRR525_lumd1979_MASK          (0x3FFU)
#define locald68_LDPRR525_lumd1979_SHIFT         (0U)
/*! lumd1979 - lumdat_1979 */
#define locald68_LDPRR525_lumd1979(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR525_lumd1979_SHIFT)) & locald68_LDPRR525_lumd1979_MASK)

#define locald68_LDPRR525_lumd1978_MASK          (0x3FF0000U)
#define locald68_LDPRR525_lumd1978_SHIFT         (16U)
/*! lumd1978 - lumdat_1978 */
#define locald68_LDPRR525_lumd1978(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR525_lumd1978_SHIFT)) & locald68_LDPRR525_lumd1978_MASK)
/*! @} */

/*! @name LDPRR526 - ldprofilereg526 */
/*! @{ */

#define locald68_LDPRR526_lumd1981_MASK          (0x3FFU)
#define locald68_LDPRR526_lumd1981_SHIFT         (0U)
/*! lumd1981 - lumdat_1981 */
#define locald68_LDPRR526_lumd1981(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR526_lumd1981_SHIFT)) & locald68_LDPRR526_lumd1981_MASK)

#define locald68_LDPRR526_lumd1980_MASK          (0x3FF0000U)
#define locald68_LDPRR526_lumd1980_SHIFT         (16U)
/*! lumd1980 - lumdat_1980 */
#define locald68_LDPRR526_lumd1980(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR526_lumd1980_SHIFT)) & locald68_LDPRR526_lumd1980_MASK)
/*! @} */

/*! @name LDPRR527 - ldprofilereg527 */
/*! @{ */

#define locald68_LDPRR527_lumd1983_MASK          (0x3FFU)
#define locald68_LDPRR527_lumd1983_SHIFT         (0U)
/*! lumd1983 - lumdat_1983 */
#define locald68_LDPRR527_lumd1983(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR527_lumd1983_SHIFT)) & locald68_LDPRR527_lumd1983_MASK)

#define locald68_LDPRR527_lumd1982_MASK          (0x3FF0000U)
#define locald68_LDPRR527_lumd1982_SHIFT         (16U)
/*! lumd1982 - lumdat_1982 */
#define locald68_LDPRR527_lumd1982(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR527_lumd1982_SHIFT)) & locald68_LDPRR527_lumd1982_MASK)
/*! @} */

/*! @name LDPRR528 - ldprofilereg528 */
/*! @{ */

#define locald68_LDPRR528_lumd1985_MASK          (0x3FFU)
#define locald68_LDPRR528_lumd1985_SHIFT         (0U)
/*! lumd1985 - lumdat_1985 */
#define locald68_LDPRR528_lumd1985(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR528_lumd1985_SHIFT)) & locald68_LDPRR528_lumd1985_MASK)

#define locald68_LDPRR528_lumd1984_MASK          (0x3FF0000U)
#define locald68_LDPRR528_lumd1984_SHIFT         (16U)
/*! lumd1984 - lumdat_1984 */
#define locald68_LDPRR528_lumd1984(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR528_lumd1984_SHIFT)) & locald68_LDPRR528_lumd1984_MASK)
/*! @} */

/*! @name LDPRR529 - ldprofilereg529 */
/*! @{ */

#define locald68_LDPRR529_lumd1987_MASK          (0x3FFU)
#define locald68_LDPRR529_lumd1987_SHIFT         (0U)
/*! lumd1987 - lumdat_1987 */
#define locald68_LDPRR529_lumd1987(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR529_lumd1987_SHIFT)) & locald68_LDPRR529_lumd1987_MASK)

#define locald68_LDPRR529_lumd1986_MASK          (0x3FF0000U)
#define locald68_LDPRR529_lumd1986_SHIFT         (16U)
/*! lumd1986 - lumdat_1986 */
#define locald68_LDPRR529_lumd1986(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR529_lumd1986_SHIFT)) & locald68_LDPRR529_lumd1986_MASK)
/*! @} */

/*! @name LDPRR52A - ldprofilereg52a */
/*! @{ */

#define locald68_LDPRR52A_lumd1989_MASK          (0x3FFU)
#define locald68_LDPRR52A_lumd1989_SHIFT         (0U)
/*! lumd1989 - lumdat_1989 */
#define locald68_LDPRR52A_lumd1989(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52A_lumd1989_SHIFT)) & locald68_LDPRR52A_lumd1989_MASK)

#define locald68_LDPRR52A_lumd1988_MASK          (0x3FF0000U)
#define locald68_LDPRR52A_lumd1988_SHIFT         (16U)
/*! lumd1988 - lumdat_1988 */
#define locald68_LDPRR52A_lumd1988(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52A_lumd1988_SHIFT)) & locald68_LDPRR52A_lumd1988_MASK)
/*! @} */

/*! @name LDPRR52B - ldprofilereg52b */
/*! @{ */

#define locald68_LDPRR52B_lumd1991_MASK          (0x3FFU)
#define locald68_LDPRR52B_lumd1991_SHIFT         (0U)
/*! lumd1991 - lumdat_1991 */
#define locald68_LDPRR52B_lumd1991(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52B_lumd1991_SHIFT)) & locald68_LDPRR52B_lumd1991_MASK)

#define locald68_LDPRR52B_lumd1990_MASK          (0x3FF0000U)
#define locald68_LDPRR52B_lumd1990_SHIFT         (16U)
/*! lumd1990 - lumdat_1990 */
#define locald68_LDPRR52B_lumd1990(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52B_lumd1990_SHIFT)) & locald68_LDPRR52B_lumd1990_MASK)
/*! @} */

/*! @name LDPRR52C - ldprofilereg52c */
/*! @{ */

#define locald68_LDPRR52C_lumd1993_MASK          (0x3FFU)
#define locald68_LDPRR52C_lumd1993_SHIFT         (0U)
/*! lumd1993 - lumdat_1993 */
#define locald68_LDPRR52C_lumd1993(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52C_lumd1993_SHIFT)) & locald68_LDPRR52C_lumd1993_MASK)

#define locald68_LDPRR52C_lumd1992_MASK          (0x3FF0000U)
#define locald68_LDPRR52C_lumd1992_SHIFT         (16U)
/*! lumd1992 - lumdat_1992 */
#define locald68_LDPRR52C_lumd1992(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52C_lumd1992_SHIFT)) & locald68_LDPRR52C_lumd1992_MASK)
/*! @} */

/*! @name LDPRR52D - ldprofilereg52d */
/*! @{ */

#define locald68_LDPRR52D_lumd1995_MASK          (0x3FFU)
#define locald68_LDPRR52D_lumd1995_SHIFT         (0U)
/*! lumd1995 - lumdat_1995 */
#define locald68_LDPRR52D_lumd1995(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52D_lumd1995_SHIFT)) & locald68_LDPRR52D_lumd1995_MASK)

#define locald68_LDPRR52D_lumd1994_MASK          (0x3FF0000U)
#define locald68_LDPRR52D_lumd1994_SHIFT         (16U)
/*! lumd1994 - lumdat_1994 */
#define locald68_LDPRR52D_lumd1994(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52D_lumd1994_SHIFT)) & locald68_LDPRR52D_lumd1994_MASK)
/*! @} */

/*! @name LDPRR52E - ldprofilereg52e */
/*! @{ */

#define locald68_LDPRR52E_lumd1997_MASK          (0x3FFU)
#define locald68_LDPRR52E_lumd1997_SHIFT         (0U)
/*! lumd1997 - lumdat_1997 */
#define locald68_LDPRR52E_lumd1997(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52E_lumd1997_SHIFT)) & locald68_LDPRR52E_lumd1997_MASK)

#define locald68_LDPRR52E_lumd1996_MASK          (0x3FF0000U)
#define locald68_LDPRR52E_lumd1996_SHIFT         (16U)
/*! lumd1996 - lumdat_1996 */
#define locald68_LDPRR52E_lumd1996(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52E_lumd1996_SHIFT)) & locald68_LDPRR52E_lumd1996_MASK)
/*! @} */

/*! @name LDPRR52F - ldprofilereg52f */
/*! @{ */

#define locald68_LDPRR52F_lumd1999_MASK          (0x3FFU)
#define locald68_LDPRR52F_lumd1999_SHIFT         (0U)
/*! lumd1999 - lumdat_1999 */
#define locald68_LDPRR52F_lumd1999(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52F_lumd1999_SHIFT)) & locald68_LDPRR52F_lumd1999_MASK)

#define locald68_LDPRR52F_lumd1998_MASK          (0x3FF0000U)
#define locald68_LDPRR52F_lumd1998_SHIFT         (16U)
/*! lumd1998 - lumdat_1998 */
#define locald68_LDPRR52F_lumd1998(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR52F_lumd1998_SHIFT)) & locald68_LDPRR52F_lumd1998_MASK)
/*! @} */

/*! @name LDPRR530 - ldprofilereg530 */
/*! @{ */

#define locald68_LDPRR530_lumd2001_MASK          (0x3FFU)
#define locald68_LDPRR530_lumd2001_SHIFT         (0U)
/*! lumd2001 - lumdat_2001 */
#define locald68_LDPRR530_lumd2001(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR530_lumd2001_SHIFT)) & locald68_LDPRR530_lumd2001_MASK)

#define locald68_LDPRR530_lumd2000_MASK          (0x3FF0000U)
#define locald68_LDPRR530_lumd2000_SHIFT         (16U)
/*! lumd2000 - lumdat_2000 */
#define locald68_LDPRR530_lumd2000(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR530_lumd2000_SHIFT)) & locald68_LDPRR530_lumd2000_MASK)
/*! @} */

/*! @name LDPRR531 - ldprofilereg531 */
/*! @{ */

#define locald68_LDPRR531_lumd2003_MASK          (0x3FFU)
#define locald68_LDPRR531_lumd2003_SHIFT         (0U)
/*! lumd2003 - lumdat_2003 */
#define locald68_LDPRR531_lumd2003(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR531_lumd2003_SHIFT)) & locald68_LDPRR531_lumd2003_MASK)

#define locald68_LDPRR531_lumd2002_MASK          (0x3FF0000U)
#define locald68_LDPRR531_lumd2002_SHIFT         (16U)
/*! lumd2002 - lumdat_2002 */
#define locald68_LDPRR531_lumd2002(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR531_lumd2002_SHIFT)) & locald68_LDPRR531_lumd2002_MASK)
/*! @} */

/*! @name LDPRR532 - ldprofilereg532 */
/*! @{ */

#define locald68_LDPRR532_lumd2005_MASK          (0x3FFU)
#define locald68_LDPRR532_lumd2005_SHIFT         (0U)
/*! lumd2005 - lumdat_2005 */
#define locald68_LDPRR532_lumd2005(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR532_lumd2005_SHIFT)) & locald68_LDPRR532_lumd2005_MASK)

#define locald68_LDPRR532_lumd2004_MASK          (0x3FF0000U)
#define locald68_LDPRR532_lumd2004_SHIFT         (16U)
/*! lumd2004 - lumdat_2004 */
#define locald68_LDPRR532_lumd2004(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR532_lumd2004_SHIFT)) & locald68_LDPRR532_lumd2004_MASK)
/*! @} */

/*! @name LDPRR533 - ldprofilereg533 */
/*! @{ */

#define locald68_LDPRR533_lumd2007_MASK          (0x3FFU)
#define locald68_LDPRR533_lumd2007_SHIFT         (0U)
/*! lumd2007 - lumdat_2007 */
#define locald68_LDPRR533_lumd2007(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR533_lumd2007_SHIFT)) & locald68_LDPRR533_lumd2007_MASK)

#define locald68_LDPRR533_lumd2006_MASK          (0x3FF0000U)
#define locald68_LDPRR533_lumd2006_SHIFT         (16U)
/*! lumd2006 - lumdat_2006 */
#define locald68_LDPRR533_lumd2006(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR533_lumd2006_SHIFT)) & locald68_LDPRR533_lumd2006_MASK)
/*! @} */

/*! @name LDPRR534 - ldprofilereg534 */
/*! @{ */

#define locald68_LDPRR534_lumd2009_MASK          (0x3FFU)
#define locald68_LDPRR534_lumd2009_SHIFT         (0U)
/*! lumd2009 - lumdat_2009 */
#define locald68_LDPRR534_lumd2009(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR534_lumd2009_SHIFT)) & locald68_LDPRR534_lumd2009_MASK)

#define locald68_LDPRR534_lumd2008_MASK          (0x3FF0000U)
#define locald68_LDPRR534_lumd2008_SHIFT         (16U)
/*! lumd2008 - lumdat_2008 */
#define locald68_LDPRR534_lumd2008(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR534_lumd2008_SHIFT)) & locald68_LDPRR534_lumd2008_MASK)
/*! @} */

/*! @name LDPRR535 - ldprofilereg535 */
/*! @{ */

#define locald68_LDPRR535_lumd2011_MASK          (0x3FFU)
#define locald68_LDPRR535_lumd2011_SHIFT         (0U)
/*! lumd2011 - lumdat_2011 */
#define locald68_LDPRR535_lumd2011(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR535_lumd2011_SHIFT)) & locald68_LDPRR535_lumd2011_MASK)

#define locald68_LDPRR535_lumd2010_MASK          (0x3FF0000U)
#define locald68_LDPRR535_lumd2010_SHIFT         (16U)
/*! lumd2010 - lumdat_2010 */
#define locald68_LDPRR535_lumd2010(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR535_lumd2010_SHIFT)) & locald68_LDPRR535_lumd2010_MASK)
/*! @} */

/*! @name LDPRR536 - ldprofilereg536 */
/*! @{ */

#define locald68_LDPRR536_lumd2013_MASK          (0x3FFU)
#define locald68_LDPRR536_lumd2013_SHIFT         (0U)
/*! lumd2013 - lumdat_2013 */
#define locald68_LDPRR536_lumd2013(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR536_lumd2013_SHIFT)) & locald68_LDPRR536_lumd2013_MASK)

#define locald68_LDPRR536_lumd2012_MASK          (0x3FF0000U)
#define locald68_LDPRR536_lumd2012_SHIFT         (16U)
/*! lumd2012 - lumdat_2012 */
#define locald68_LDPRR536_lumd2012(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR536_lumd2012_SHIFT)) & locald68_LDPRR536_lumd2012_MASK)
/*! @} */

/*! @name LDPRR537 - ldprofilereg537 */
/*! @{ */

#define locald68_LDPRR537_lumd2015_MASK          (0x3FFU)
#define locald68_LDPRR537_lumd2015_SHIFT         (0U)
/*! lumd2015 - lumdat_2015 */
#define locald68_LDPRR537_lumd2015(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR537_lumd2015_SHIFT)) & locald68_LDPRR537_lumd2015_MASK)

#define locald68_LDPRR537_lumd2014_MASK          (0x3FF0000U)
#define locald68_LDPRR537_lumd2014_SHIFT         (16U)
/*! lumd2014 - lumdat_2014 */
#define locald68_LDPRR537_lumd2014(x)            (((uint32_t)(((uint32_t)(x)) << locald68_LDPRR537_lumd2014_SHIFT)) & locald68_LDPRR537_lumd2014_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald68_Register_Masks */


/*!
 * @}
 */ /* end of group locald68_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD68_H_ */

