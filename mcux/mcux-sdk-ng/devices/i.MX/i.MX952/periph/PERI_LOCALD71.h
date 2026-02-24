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
**         CMSIS Peripheral Access Layer for locald71
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
 * @file PERI_locald71.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald71
 *
 * CMSIS Peripheral Access Layer for locald71
 */

#if !defined(PERI_LOCALD71_H_)
#define PERI_LOCALD71_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald71 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald71_Peripheral_Access_Layer locald71 Peripheral Access Layer
 * @{
 */

/** locald71 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDPRR580;                          /**< ldprofilereg580, offset: 0x0 */
  __IO uint32_t LDPRR581;                          /**< ldprofilereg581, offset: 0x4 */
  __IO uint32_t LDPRR582;                          /**< ldprofilereg582, offset: 0x8 */
  __IO uint32_t LDPRR583;                          /**< ldprofilereg583, offset: 0xC */
  __IO uint32_t LDPRR584;                          /**< ldprofilereg584, offset: 0x10 */
  __IO uint32_t LDPRR585;                          /**< ldprofilereg585, offset: 0x14 */
  __IO uint32_t LDPRR586;                          /**< ldprofilereg586, offset: 0x18 */
  __IO uint32_t LDPRR587;                          /**< ldprofilereg587, offset: 0x1C */
  __IO uint32_t LDPRR588;                          /**< ldprofilereg588, offset: 0x20 */
  __IO uint32_t LDPRR589;                          /**< ldprofilereg589, offset: 0x24 */
  __IO uint32_t LDPRR58A;                          /**< ldprofilereg58a, offset: 0x28 */
  __IO uint32_t LDPRR58B;                          /**< ldprofilereg58b, offset: 0x2C */
  __IO uint32_t LDPRR58C;                          /**< ldprofilereg58c, offset: 0x30 */
  __IO uint32_t LDPRR58D;                          /**< ldprofilereg58d, offset: 0x34 */
  __IO uint32_t LDPRR58E;                          /**< ldprofilereg58e, offset: 0x38 */
  __IO uint32_t LDPRR58F;                          /**< ldprofilereg58f, offset: 0x3C */
  __IO uint32_t LDPRR590;                          /**< ldprofilereg590, offset: 0x40 */
  __IO uint32_t LDPRR591;                          /**< ldprofilereg591, offset: 0x44 */
  __IO uint32_t LDPRR592;                          /**< ldprofilereg592, offset: 0x48 */
  __IO uint32_t LDPRR593;                          /**< ldprofilereg593, offset: 0x4C */
  __IO uint32_t LDPRR594;                          /**< ldprofilereg594, offset: 0x50 */
  __IO uint32_t LDPRR595;                          /**< ldprofilereg595, offset: 0x54 */
  __IO uint32_t LDPRR596;                          /**< ldprofilereg596, offset: 0x58 */
  __IO uint32_t LDPRR597;                          /**< ldprofilereg597, offset: 0x5C */
} locald71_Type;

/* ----------------------------------------------------------------------------
   -- locald71 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald71_Register_Masks locald71 Register Masks
 * @{
 */

/*! @name LDPRR580 - ldprofilereg580 */
/*! @{ */

#define locald71_LDPRR580_lumd2113_MASK          (0x3FFU)
#define locald71_LDPRR580_lumd2113_SHIFT         (0U)
/*! lumd2113 - lumdat_2113 */
#define locald71_LDPRR580_lumd2113(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR580_lumd2113_SHIFT)) & locald71_LDPRR580_lumd2113_MASK)

#define locald71_LDPRR580_lumd2112_MASK          (0x3FF0000U)
#define locald71_LDPRR580_lumd2112_SHIFT         (16U)
/*! lumd2112 - lumdat_2112 */
#define locald71_LDPRR580_lumd2112(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR580_lumd2112_SHIFT)) & locald71_LDPRR580_lumd2112_MASK)
/*! @} */

/*! @name LDPRR581 - ldprofilereg581 */
/*! @{ */

#define locald71_LDPRR581_lumd2115_MASK          (0x3FFU)
#define locald71_LDPRR581_lumd2115_SHIFT         (0U)
/*! lumd2115 - lumdat_2115 */
#define locald71_LDPRR581_lumd2115(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR581_lumd2115_SHIFT)) & locald71_LDPRR581_lumd2115_MASK)

#define locald71_LDPRR581_lumd2114_MASK          (0x3FF0000U)
#define locald71_LDPRR581_lumd2114_SHIFT         (16U)
/*! lumd2114 - lumdat_2114 */
#define locald71_LDPRR581_lumd2114(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR581_lumd2114_SHIFT)) & locald71_LDPRR581_lumd2114_MASK)
/*! @} */

/*! @name LDPRR582 - ldprofilereg582 */
/*! @{ */

#define locald71_LDPRR582_lumd2117_MASK          (0x3FFU)
#define locald71_LDPRR582_lumd2117_SHIFT         (0U)
/*! lumd2117 - lumdat_2117 */
#define locald71_LDPRR582_lumd2117(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR582_lumd2117_SHIFT)) & locald71_LDPRR582_lumd2117_MASK)

#define locald71_LDPRR582_lumd2116_MASK          (0x3FF0000U)
#define locald71_LDPRR582_lumd2116_SHIFT         (16U)
/*! lumd2116 - lumdat_2116 */
#define locald71_LDPRR582_lumd2116(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR582_lumd2116_SHIFT)) & locald71_LDPRR582_lumd2116_MASK)
/*! @} */

/*! @name LDPRR583 - ldprofilereg583 */
/*! @{ */

#define locald71_LDPRR583_lumd2119_MASK          (0x3FFU)
#define locald71_LDPRR583_lumd2119_SHIFT         (0U)
/*! lumd2119 - lumdat_2119 */
#define locald71_LDPRR583_lumd2119(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR583_lumd2119_SHIFT)) & locald71_LDPRR583_lumd2119_MASK)

#define locald71_LDPRR583_lumd2118_MASK          (0x3FF0000U)
#define locald71_LDPRR583_lumd2118_SHIFT         (16U)
/*! lumd2118 - lumdat_2118 */
#define locald71_LDPRR583_lumd2118(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR583_lumd2118_SHIFT)) & locald71_LDPRR583_lumd2118_MASK)
/*! @} */

/*! @name LDPRR584 - ldprofilereg584 */
/*! @{ */

#define locald71_LDPRR584_lumd2121_MASK          (0x3FFU)
#define locald71_LDPRR584_lumd2121_SHIFT         (0U)
/*! lumd2121 - lumdat_2121 */
#define locald71_LDPRR584_lumd2121(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR584_lumd2121_SHIFT)) & locald71_LDPRR584_lumd2121_MASK)

#define locald71_LDPRR584_lumd2120_MASK          (0x3FF0000U)
#define locald71_LDPRR584_lumd2120_SHIFT         (16U)
/*! lumd2120 - lumdat_2120 */
#define locald71_LDPRR584_lumd2120(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR584_lumd2120_SHIFT)) & locald71_LDPRR584_lumd2120_MASK)
/*! @} */

/*! @name LDPRR585 - ldprofilereg585 */
/*! @{ */

#define locald71_LDPRR585_lumd2123_MASK          (0x3FFU)
#define locald71_LDPRR585_lumd2123_SHIFT         (0U)
/*! lumd2123 - lumdat_2123 */
#define locald71_LDPRR585_lumd2123(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR585_lumd2123_SHIFT)) & locald71_LDPRR585_lumd2123_MASK)

#define locald71_LDPRR585_lumd2122_MASK          (0x3FF0000U)
#define locald71_LDPRR585_lumd2122_SHIFT         (16U)
/*! lumd2122 - lumdat_2122 */
#define locald71_LDPRR585_lumd2122(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR585_lumd2122_SHIFT)) & locald71_LDPRR585_lumd2122_MASK)
/*! @} */

/*! @name LDPRR586 - ldprofilereg586 */
/*! @{ */

#define locald71_LDPRR586_lumd2125_MASK          (0x3FFU)
#define locald71_LDPRR586_lumd2125_SHIFT         (0U)
/*! lumd2125 - lumdat_2125 */
#define locald71_LDPRR586_lumd2125(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR586_lumd2125_SHIFT)) & locald71_LDPRR586_lumd2125_MASK)

#define locald71_LDPRR586_lumd2124_MASK          (0x3FF0000U)
#define locald71_LDPRR586_lumd2124_SHIFT         (16U)
/*! lumd2124 - lumdat_2124 */
#define locald71_LDPRR586_lumd2124(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR586_lumd2124_SHIFT)) & locald71_LDPRR586_lumd2124_MASK)
/*! @} */

/*! @name LDPRR587 - ldprofilereg587 */
/*! @{ */

#define locald71_LDPRR587_lumd2127_MASK          (0x3FFU)
#define locald71_LDPRR587_lumd2127_SHIFT         (0U)
/*! lumd2127 - lumdat_2127 */
#define locald71_LDPRR587_lumd2127(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR587_lumd2127_SHIFT)) & locald71_LDPRR587_lumd2127_MASK)

#define locald71_LDPRR587_lumd2126_MASK          (0x3FF0000U)
#define locald71_LDPRR587_lumd2126_SHIFT         (16U)
/*! lumd2126 - lumdat_2126 */
#define locald71_LDPRR587_lumd2126(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR587_lumd2126_SHIFT)) & locald71_LDPRR587_lumd2126_MASK)
/*! @} */

/*! @name LDPRR588 - ldprofilereg588 */
/*! @{ */

#define locald71_LDPRR588_lumd2129_MASK          (0x3FFU)
#define locald71_LDPRR588_lumd2129_SHIFT         (0U)
/*! lumd2129 - lumdat_2129 */
#define locald71_LDPRR588_lumd2129(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR588_lumd2129_SHIFT)) & locald71_LDPRR588_lumd2129_MASK)

#define locald71_LDPRR588_lumd2128_MASK          (0x3FF0000U)
#define locald71_LDPRR588_lumd2128_SHIFT         (16U)
/*! lumd2128 - lumdat_2128 */
#define locald71_LDPRR588_lumd2128(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR588_lumd2128_SHIFT)) & locald71_LDPRR588_lumd2128_MASK)
/*! @} */

/*! @name LDPRR589 - ldprofilereg589 */
/*! @{ */

#define locald71_LDPRR589_lumd2131_MASK          (0x3FFU)
#define locald71_LDPRR589_lumd2131_SHIFT         (0U)
/*! lumd2131 - lumdat_2131 */
#define locald71_LDPRR589_lumd2131(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR589_lumd2131_SHIFT)) & locald71_LDPRR589_lumd2131_MASK)

#define locald71_LDPRR589_lumd2130_MASK          (0x3FF0000U)
#define locald71_LDPRR589_lumd2130_SHIFT         (16U)
/*! lumd2130 - lumdat_2130 */
#define locald71_LDPRR589_lumd2130(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR589_lumd2130_SHIFT)) & locald71_LDPRR589_lumd2130_MASK)
/*! @} */

/*! @name LDPRR58A - ldprofilereg58a */
/*! @{ */

#define locald71_LDPRR58A_lumd2133_MASK          (0x3FFU)
#define locald71_LDPRR58A_lumd2133_SHIFT         (0U)
/*! lumd2133 - lumdat_2133 */
#define locald71_LDPRR58A_lumd2133(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58A_lumd2133_SHIFT)) & locald71_LDPRR58A_lumd2133_MASK)

#define locald71_LDPRR58A_lumd2132_MASK          (0x3FF0000U)
#define locald71_LDPRR58A_lumd2132_SHIFT         (16U)
/*! lumd2132 - lumdat_2132 */
#define locald71_LDPRR58A_lumd2132(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58A_lumd2132_SHIFT)) & locald71_LDPRR58A_lumd2132_MASK)
/*! @} */

/*! @name LDPRR58B - ldprofilereg58b */
/*! @{ */

#define locald71_LDPRR58B_lumd2135_MASK          (0x3FFU)
#define locald71_LDPRR58B_lumd2135_SHIFT         (0U)
/*! lumd2135 - lumdat_2135 */
#define locald71_LDPRR58B_lumd2135(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58B_lumd2135_SHIFT)) & locald71_LDPRR58B_lumd2135_MASK)

#define locald71_LDPRR58B_lumd2134_MASK          (0x3FF0000U)
#define locald71_LDPRR58B_lumd2134_SHIFT         (16U)
/*! lumd2134 - lumdat_2134 */
#define locald71_LDPRR58B_lumd2134(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58B_lumd2134_SHIFT)) & locald71_LDPRR58B_lumd2134_MASK)
/*! @} */

/*! @name LDPRR58C - ldprofilereg58c */
/*! @{ */

#define locald71_LDPRR58C_lumd2137_MASK          (0x3FFU)
#define locald71_LDPRR58C_lumd2137_SHIFT         (0U)
/*! lumd2137 - lumdat_2137 */
#define locald71_LDPRR58C_lumd2137(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58C_lumd2137_SHIFT)) & locald71_LDPRR58C_lumd2137_MASK)

#define locald71_LDPRR58C_lumd2136_MASK          (0x3FF0000U)
#define locald71_LDPRR58C_lumd2136_SHIFT         (16U)
/*! lumd2136 - lumdat_2136 */
#define locald71_LDPRR58C_lumd2136(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58C_lumd2136_SHIFT)) & locald71_LDPRR58C_lumd2136_MASK)
/*! @} */

/*! @name LDPRR58D - ldprofilereg58d */
/*! @{ */

#define locald71_LDPRR58D_lumd2139_MASK          (0x3FFU)
#define locald71_LDPRR58D_lumd2139_SHIFT         (0U)
/*! lumd2139 - lumdat_2139 */
#define locald71_LDPRR58D_lumd2139(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58D_lumd2139_SHIFT)) & locald71_LDPRR58D_lumd2139_MASK)

#define locald71_LDPRR58D_lumd2138_MASK          (0x3FF0000U)
#define locald71_LDPRR58D_lumd2138_SHIFT         (16U)
/*! lumd2138 - lumdat_2138 */
#define locald71_LDPRR58D_lumd2138(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58D_lumd2138_SHIFT)) & locald71_LDPRR58D_lumd2138_MASK)
/*! @} */

/*! @name LDPRR58E - ldprofilereg58e */
/*! @{ */

#define locald71_LDPRR58E_lumd2141_MASK          (0x3FFU)
#define locald71_LDPRR58E_lumd2141_SHIFT         (0U)
/*! lumd2141 - lumdat_2141 */
#define locald71_LDPRR58E_lumd2141(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58E_lumd2141_SHIFT)) & locald71_LDPRR58E_lumd2141_MASK)

#define locald71_LDPRR58E_lumd2140_MASK          (0x3FF0000U)
#define locald71_LDPRR58E_lumd2140_SHIFT         (16U)
/*! lumd2140 - lumdat_2140 */
#define locald71_LDPRR58E_lumd2140(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58E_lumd2140_SHIFT)) & locald71_LDPRR58E_lumd2140_MASK)
/*! @} */

/*! @name LDPRR58F - ldprofilereg58f */
/*! @{ */

#define locald71_LDPRR58F_lumd2143_MASK          (0x3FFU)
#define locald71_LDPRR58F_lumd2143_SHIFT         (0U)
/*! lumd2143 - lumdat_2143 */
#define locald71_LDPRR58F_lumd2143(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58F_lumd2143_SHIFT)) & locald71_LDPRR58F_lumd2143_MASK)

#define locald71_LDPRR58F_lumd2142_MASK          (0x3FF0000U)
#define locald71_LDPRR58F_lumd2142_SHIFT         (16U)
/*! lumd2142 - lumdat_2142 */
#define locald71_LDPRR58F_lumd2142(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR58F_lumd2142_SHIFT)) & locald71_LDPRR58F_lumd2142_MASK)
/*! @} */

/*! @name LDPRR590 - ldprofilereg590 */
/*! @{ */

#define locald71_LDPRR590_lumd2145_MASK          (0x3FFU)
#define locald71_LDPRR590_lumd2145_SHIFT         (0U)
/*! lumd2145 - lumdat_2145 */
#define locald71_LDPRR590_lumd2145(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR590_lumd2145_SHIFT)) & locald71_LDPRR590_lumd2145_MASK)

#define locald71_LDPRR590_lumd2144_MASK          (0x3FF0000U)
#define locald71_LDPRR590_lumd2144_SHIFT         (16U)
/*! lumd2144 - lumdat_2144 */
#define locald71_LDPRR590_lumd2144(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR590_lumd2144_SHIFT)) & locald71_LDPRR590_lumd2144_MASK)
/*! @} */

/*! @name LDPRR591 - ldprofilereg591 */
/*! @{ */

#define locald71_LDPRR591_lumd2147_MASK          (0x3FFU)
#define locald71_LDPRR591_lumd2147_SHIFT         (0U)
/*! lumd2147 - lumdat_2147 */
#define locald71_LDPRR591_lumd2147(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR591_lumd2147_SHIFT)) & locald71_LDPRR591_lumd2147_MASK)

#define locald71_LDPRR591_lumd2146_MASK          (0x3FF0000U)
#define locald71_LDPRR591_lumd2146_SHIFT         (16U)
/*! lumd2146 - lumdat_2146 */
#define locald71_LDPRR591_lumd2146(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR591_lumd2146_SHIFT)) & locald71_LDPRR591_lumd2146_MASK)
/*! @} */

/*! @name LDPRR592 - ldprofilereg592 */
/*! @{ */

#define locald71_LDPRR592_lumd2149_MASK          (0x3FFU)
#define locald71_LDPRR592_lumd2149_SHIFT         (0U)
/*! lumd2149 - lumdat_2149 */
#define locald71_LDPRR592_lumd2149(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR592_lumd2149_SHIFT)) & locald71_LDPRR592_lumd2149_MASK)

#define locald71_LDPRR592_lumd2148_MASK          (0x3FF0000U)
#define locald71_LDPRR592_lumd2148_SHIFT         (16U)
/*! lumd2148 - lumdat_2148 */
#define locald71_LDPRR592_lumd2148(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR592_lumd2148_SHIFT)) & locald71_LDPRR592_lumd2148_MASK)
/*! @} */

/*! @name LDPRR593 - ldprofilereg593 */
/*! @{ */

#define locald71_LDPRR593_lumd2151_MASK          (0x3FFU)
#define locald71_LDPRR593_lumd2151_SHIFT         (0U)
/*! lumd2151 - lumdat_2151 */
#define locald71_LDPRR593_lumd2151(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR593_lumd2151_SHIFT)) & locald71_LDPRR593_lumd2151_MASK)

#define locald71_LDPRR593_lumd2150_MASK          (0x3FF0000U)
#define locald71_LDPRR593_lumd2150_SHIFT         (16U)
/*! lumd2150 - lumdat_2150 */
#define locald71_LDPRR593_lumd2150(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR593_lumd2150_SHIFT)) & locald71_LDPRR593_lumd2150_MASK)
/*! @} */

/*! @name LDPRR594 - ldprofilereg594 */
/*! @{ */

#define locald71_LDPRR594_lumd2153_MASK          (0x3FFU)
#define locald71_LDPRR594_lumd2153_SHIFT         (0U)
/*! lumd2153 - lumdat_2153 */
#define locald71_LDPRR594_lumd2153(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR594_lumd2153_SHIFT)) & locald71_LDPRR594_lumd2153_MASK)

#define locald71_LDPRR594_lumd2152_MASK          (0x3FF0000U)
#define locald71_LDPRR594_lumd2152_SHIFT         (16U)
/*! lumd2152 - lumdat_2152 */
#define locald71_LDPRR594_lumd2152(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR594_lumd2152_SHIFT)) & locald71_LDPRR594_lumd2152_MASK)
/*! @} */

/*! @name LDPRR595 - ldprofilereg595 */
/*! @{ */

#define locald71_LDPRR595_lumd2155_MASK          (0x3FFU)
#define locald71_LDPRR595_lumd2155_SHIFT         (0U)
/*! lumd2155 - lumdat_2155 */
#define locald71_LDPRR595_lumd2155(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR595_lumd2155_SHIFT)) & locald71_LDPRR595_lumd2155_MASK)

#define locald71_LDPRR595_lumd2154_MASK          (0x3FF0000U)
#define locald71_LDPRR595_lumd2154_SHIFT         (16U)
/*! lumd2154 - lumdat_2154 */
#define locald71_LDPRR595_lumd2154(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR595_lumd2154_SHIFT)) & locald71_LDPRR595_lumd2154_MASK)
/*! @} */

/*! @name LDPRR596 - ldprofilereg596 */
/*! @{ */

#define locald71_LDPRR596_lumd2157_MASK          (0x3FFU)
#define locald71_LDPRR596_lumd2157_SHIFT         (0U)
/*! lumd2157 - lumdat_2157 */
#define locald71_LDPRR596_lumd2157(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR596_lumd2157_SHIFT)) & locald71_LDPRR596_lumd2157_MASK)

#define locald71_LDPRR596_lumd2156_MASK          (0x3FF0000U)
#define locald71_LDPRR596_lumd2156_SHIFT         (16U)
/*! lumd2156 - lumdat_2156 */
#define locald71_LDPRR596_lumd2156(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR596_lumd2156_SHIFT)) & locald71_LDPRR596_lumd2156_MASK)
/*! @} */

/*! @name LDPRR597 - ldprofilereg597 */
/*! @{ */

#define locald71_LDPRR597_lumd2159_MASK          (0x3FFU)
#define locald71_LDPRR597_lumd2159_SHIFT         (0U)
/*! lumd2159 - lumdat_2159 */
#define locald71_LDPRR597_lumd2159(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR597_lumd2159_SHIFT)) & locald71_LDPRR597_lumd2159_MASK)

#define locald71_LDPRR597_lumd2158_MASK          (0x3FF0000U)
#define locald71_LDPRR597_lumd2158_SHIFT         (16U)
/*! lumd2158 - lumdat_2158 */
#define locald71_LDPRR597_lumd2158(x)            (((uint32_t)(((uint32_t)(x)) << locald71_LDPRR597_lumd2158_SHIFT)) & locald71_LDPRR597_lumd2158_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald71_Register_Masks */


/*!
 * @}
 */ /* end of group locald71_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD71_H_ */

