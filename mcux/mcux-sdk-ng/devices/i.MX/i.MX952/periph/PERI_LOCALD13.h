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
**         CMSIS Peripheral Access Layer for locald13
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
 * @file PERI_locald13.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald13
 *
 * CMSIS Peripheral Access Layer for locald13
 */

#if !defined(PERI_LOCALD13_H_)
#define PERI_LOCALD13_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald13 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald13_Peripheral_Access_Layer locald13 Peripheral Access Layer
 * @{
 */

/** locald13 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDLED014;                          /**< ldledreg014, offset: 0x0 */
  __IO uint32_t LDLED015;                          /**< ldledreg015, offset: 0x4 */
  __IO uint32_t LDLED016;                          /**< ldledreg016, offset: 0x8 */
  __IO uint32_t LDLED017;                          /**< ldledreg017, offset: 0xC */
  __IO uint32_t LDLED018;                          /**< ldledreg018, offset: 0x10 */
  __IO uint32_t LDLED019;                          /**< ldledreg019, offset: 0x14 */
  __IO uint32_t LDLED01A;                          /**< ldledreg01a, offset: 0x18 */
  __IO uint32_t LDLED01B;                          /**< ldledreg01b, offset: 0x1C */
} locald13_Type;

/* ----------------------------------------------------------------------------
   -- locald13 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald13_Register_Masks locald13 Register Masks
 * @{
 */

/*! @name LDLED014 - ldledreg014 */
/*! @{ */

#define locald13_LDLED014_c01_MASK               (0x1FFU)
#define locald13_LDLED014_c01_SHIFT              (0U)
/*! c01 - c_1 */
#define locald13_LDLED014_c01(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED014_c01_SHIFT)) & locald13_LDLED014_c01_MASK)

#define locald13_LDLED014_c0_MASK                (0x1FF0000U)
#define locald13_LDLED014_c0_SHIFT               (16U)
/*! c0 - c_0 */
#define locald13_LDLED014_c0(x)                  (((uint32_t)(((uint32_t)(x)) << locald13_LDLED014_c0_SHIFT)) & locald13_LDLED014_c0_MASK)
/*! @} */

/*! @name LDLED015 - ldledreg015 */
/*! @{ */

#define locald13_LDLED015_c03_MASK               (0x1FFU)
#define locald13_LDLED015_c03_SHIFT              (0U)
/*! c03 - c_3 */
#define locald13_LDLED015_c03(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED015_c03_SHIFT)) & locald13_LDLED015_c03_MASK)

#define locald13_LDLED015_c02_MASK               (0x1FF0000U)
#define locald13_LDLED015_c02_SHIFT              (16U)
/*! c02 - c_2 */
#define locald13_LDLED015_c02(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED015_c02_SHIFT)) & locald13_LDLED015_c02_MASK)
/*! @} */

/*! @name LDLED016 - ldledreg016 */
/*! @{ */

#define locald13_LDLED016_c05_MASK               (0x1FFU)
#define locald13_LDLED016_c05_SHIFT              (0U)
/*! c05 - c_5 */
#define locald13_LDLED016_c05(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED016_c05_SHIFT)) & locald13_LDLED016_c05_MASK)

#define locald13_LDLED016_c04_MASK               (0x1FF0000U)
#define locald13_LDLED016_c04_SHIFT              (16U)
/*! c04 - c_4 */
#define locald13_LDLED016_c04(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED016_c04_SHIFT)) & locald13_LDLED016_c04_MASK)
/*! @} */

/*! @name LDLED017 - ldledreg017 */
/*! @{ */

#define locald13_LDLED017_c7_MASK                (0x1FFU)
#define locald13_LDLED017_c7_SHIFT               (0U)
/*! c7 - c_7 */
#define locald13_LDLED017_c7(x)                  (((uint32_t)(((uint32_t)(x)) << locald13_LDLED017_c7_SHIFT)) & locald13_LDLED017_c7_MASK)

#define locald13_LDLED017_c6_MASK                (0x1FF0000U)
#define locald13_LDLED017_c6_SHIFT               (16U)
/*! c6 - c_6 */
#define locald13_LDLED017_c6(x)                  (((uint32_t)(((uint32_t)(x)) << locald13_LDLED017_c6_SHIFT)) & locald13_LDLED017_c6_MASK)
/*! @} */

/*! @name LDLED018 - ldledreg018 */
/*! @{ */

#define locald13_LDLED018_c9_MASK                (0x1FFU)
#define locald13_LDLED018_c9_SHIFT               (0U)
/*! c9 - c_9 */
#define locald13_LDLED018_c9(x)                  (((uint32_t)(((uint32_t)(x)) << locald13_LDLED018_c9_SHIFT)) & locald13_LDLED018_c9_MASK)

#define locald13_LDLED018_c8_MASK                (0x1FF0000U)
#define locald13_LDLED018_c8_SHIFT               (16U)
/*! c8 - c_8 */
#define locald13_LDLED018_c8(x)                  (((uint32_t)(((uint32_t)(x)) << locald13_LDLED018_c8_SHIFT)) & locald13_LDLED018_c8_MASK)
/*! @} */

/*! @name LDLED019 - ldledreg019 */
/*! @{ */

#define locald13_LDLED019_c11_MASK               (0x1FFU)
#define locald13_LDLED019_c11_SHIFT              (0U)
/*! c11 - c_11 */
#define locald13_LDLED019_c11(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED019_c11_SHIFT)) & locald13_LDLED019_c11_MASK)

#define locald13_LDLED019_c10_MASK               (0x1FF0000U)
#define locald13_LDLED019_c10_SHIFT              (16U)
/*! c10 - c_10 */
#define locald13_LDLED019_c10(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED019_c10_SHIFT)) & locald13_LDLED019_c10_MASK)
/*! @} */

/*! @name LDLED01A - ldledreg01a */
/*! @{ */

#define locald13_LDLED01A_c13_MASK               (0x1FFU)
#define locald13_LDLED01A_c13_SHIFT              (0U)
/*! c13 - c_13 */
#define locald13_LDLED01A_c13(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED01A_c13_SHIFT)) & locald13_LDLED01A_c13_MASK)

#define locald13_LDLED01A_c12_MASK               (0x1FF0000U)
#define locald13_LDLED01A_c12_SHIFT              (16U)
/*! c12 - c_12 */
#define locald13_LDLED01A_c12(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED01A_c12_SHIFT)) & locald13_LDLED01A_c12_MASK)
/*! @} */

/*! @name LDLED01B - ldledreg01b */
/*! @{ */

#define locald13_LDLED01B_c15_MASK               (0x1FFU)
#define locald13_LDLED01B_c15_SHIFT              (0U)
/*! c15 - c_15 */
#define locald13_LDLED01B_c15(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED01B_c15_SHIFT)) & locald13_LDLED01B_c15_MASK)

#define locald13_LDLED01B_c14_MASK               (0x1FF0000U)
#define locald13_LDLED01B_c14_SHIFT              (16U)
/*! c14 - c_14 */
#define locald13_LDLED01B_c14(x)                 (((uint32_t)(((uint32_t)(x)) << locald13_LDLED01B_c14_SHIFT)) & locald13_LDLED01B_c14_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald13_Register_Masks */


/*!
 * @}
 */ /* end of group locald13_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD13_H_ */

