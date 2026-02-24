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
**         CMSIS Peripheral Access Layer for locald24
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
 * @file PERI_locald24.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald24
 *
 * CMSIS Peripheral Access Layer for locald24
 */

#if !defined(PERI_LOCALD24_H_)
#define PERI_LOCALD24_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald24 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald24_Peripheral_Access_Layer locald24 Peripheral Access Layer
 * @{
 */

/** locald24 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDRG061;                           /**< ldrgbreg061, offset: 0x0 */
  __IO uint32_t LDRG062;                           /**< ldrgbreg062, offset: 0x4 */
  __IO uint32_t LDRG063;                           /**< ldrgbreg063, offset: 0x8 */
  __IO uint32_t LDRG064;                           /**< ldrgbreg064, offset: 0xC */
  __IO uint32_t LDRG065;                           /**< ldrgbreg065, offset: 0x10 */
  __IO uint32_t LDRG066;                           /**< ldrgbreg066, offset: 0x14 */
  __IO uint32_t LDRG067;                           /**< ldrgbreg067, offset: 0x18 */
  __IO uint32_t LDRG068;                           /**< ldrgbreg068, offset: 0x1C */
  __IO uint32_t LDRG069;                           /**< ldrgbreg069, offset: 0x20 */
  __IO uint32_t LDRG06A;                           /**< ldrgbreg06a, offset: 0x24 */
  __IO uint32_t LDRG06B;                           /**< ldrgbreg06b, offset: 0x28 */
  __IO uint32_t LDRG06C;                           /**< ldrgbreg06c, offset: 0x2C */
  __IO uint32_t LDRG06D;                           /**< ldrgbreg06d, offset: 0x30 */
  __IO uint32_t LDRG06E;                           /**< ldrgbreg06e, offset: 0x34 */
  __IO uint32_t LDRG06F;                           /**< ldrgbreg06f, offset: 0x38 */
  __IO uint32_t LDRG070;                           /**< ldrgbreg070, offset: 0x3C */
  __IO uint32_t LDRG071;                           /**< ldrgbreg071, offset: 0x40 */
} locald24_Type;

/* ----------------------------------------------------------------------------
   -- locald24 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald24_Register_Masks locald24 Register Masks
 * @{
 */

/*! @name LDRG061 - ldrgbreg061 */
/*! @{ */

#define locald24_LDRG061_rgbl331_MASK            (0xFFFU)
#define locald24_LDRG061_rgbl331_SHIFT           (0U)
/*! rgbl331 - rgboelut33_1 */
#define locald24_LDRG061_rgbl331(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG061_rgbl331_SHIFT)) & locald24_LDRG061_rgbl331_MASK)

#define locald24_LDRG061_rgbl330_MASK            (0xFFF0000U)
#define locald24_LDRG061_rgbl330_SHIFT           (16U)
/*! rgbl330 - rgboelut33_0 */
#define locald24_LDRG061_rgbl330(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG061_rgbl330_SHIFT)) & locald24_LDRG061_rgbl330_MASK)
/*! @} */

/*! @name LDRG062 - ldrgbreg062 */
/*! @{ */

#define locald24_LDRG062_rgbl333_MASK            (0xFFFU)
#define locald24_LDRG062_rgbl333_SHIFT           (0U)
/*! rgbl333 - rgboelut33_3 */
#define locald24_LDRG062_rgbl333(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG062_rgbl333_SHIFT)) & locald24_LDRG062_rgbl333_MASK)

#define locald24_LDRG062_rgbl332_MASK            (0xFFF0000U)
#define locald24_LDRG062_rgbl332_SHIFT           (16U)
/*! rgbl332 - rgboelut33_2 */
#define locald24_LDRG062_rgbl332(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG062_rgbl332_SHIFT)) & locald24_LDRG062_rgbl332_MASK)
/*! @} */

/*! @name LDRG063 - ldrgbreg063 */
/*! @{ */

#define locald24_LDRG063_rgbl335_MASK            (0xFFFU)
#define locald24_LDRG063_rgbl335_SHIFT           (0U)
/*! rgbl335 - rgboelut33_5 */
#define locald24_LDRG063_rgbl335(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG063_rgbl335_SHIFT)) & locald24_LDRG063_rgbl335_MASK)

#define locald24_LDRG063_rgbl334_MASK            (0xFFF0000U)
#define locald24_LDRG063_rgbl334_SHIFT           (16U)
/*! rgbl334 - rgboelut33_4 */
#define locald24_LDRG063_rgbl334(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG063_rgbl334_SHIFT)) & locald24_LDRG063_rgbl334_MASK)
/*! @} */

/*! @name LDRG064 - ldrgbreg064 */
/*! @{ */

#define locald24_LDRG064_rgbl337_MASK            (0xFFFU)
#define locald24_LDRG064_rgbl337_SHIFT           (0U)
/*! rgbl337 - rgboelut33_7 */
#define locald24_LDRG064_rgbl337(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG064_rgbl337_SHIFT)) & locald24_LDRG064_rgbl337_MASK)

#define locald24_LDRG064_rgbl336_MASK            (0xFFF0000U)
#define locald24_LDRG064_rgbl336_SHIFT           (16U)
/*! rgbl336 - rgboelut33_6 */
#define locald24_LDRG064_rgbl336(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG064_rgbl336_SHIFT)) & locald24_LDRG064_rgbl336_MASK)
/*! @} */

/*! @name LDRG065 - ldrgbreg065 */
/*! @{ */

#define locald24_LDRG065_rgbl339_MASK            (0xFFFU)
#define locald24_LDRG065_rgbl339_SHIFT           (0U)
/*! rgbl339 - rgboelut33_9 */
#define locald24_LDRG065_rgbl339(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG065_rgbl339_SHIFT)) & locald24_LDRG065_rgbl339_MASK)

#define locald24_LDRG065_rgbl338_MASK            (0xFFF0000U)
#define locald24_LDRG065_rgbl338_SHIFT           (16U)
/*! rgbl338 - rgboelut33_8 */
#define locald24_LDRG065_rgbl338(x)              (((uint32_t)(((uint32_t)(x)) << locald24_LDRG065_rgbl338_SHIFT)) & locald24_LDRG065_rgbl338_MASK)
/*! @} */

/*! @name LDRG066 - ldrgbreg066 */
/*! @{ */

#define locald24_LDRG066_rgbl3311_MASK           (0xFFFU)
#define locald24_LDRG066_rgbl3311_SHIFT          (0U)
/*! rgbl3311 - rgboelut33_11 */
#define locald24_LDRG066_rgbl3311(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG066_rgbl3311_SHIFT)) & locald24_LDRG066_rgbl3311_MASK)

#define locald24_LDRG066_rgbl3310_MASK           (0xFFF0000U)
#define locald24_LDRG066_rgbl3310_SHIFT          (16U)
/*! rgbl3310 - rgboelut33_10 */
#define locald24_LDRG066_rgbl3310(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG066_rgbl3310_SHIFT)) & locald24_LDRG066_rgbl3310_MASK)
/*! @} */

/*! @name LDRG067 - ldrgbreg067 */
/*! @{ */

#define locald24_LDRG067_rgbl3313_MASK           (0xFFFU)
#define locald24_LDRG067_rgbl3313_SHIFT          (0U)
/*! rgbl3313 - rgboelut33_13 */
#define locald24_LDRG067_rgbl3313(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG067_rgbl3313_SHIFT)) & locald24_LDRG067_rgbl3313_MASK)

#define locald24_LDRG067_rgbl3312_MASK           (0xFFF0000U)
#define locald24_LDRG067_rgbl3312_SHIFT          (16U)
/*! rgbl3312 - rgboelut33_12 */
#define locald24_LDRG067_rgbl3312(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG067_rgbl3312_SHIFT)) & locald24_LDRG067_rgbl3312_MASK)
/*! @} */

/*! @name LDRG068 - ldrgbreg068 */
/*! @{ */

#define locald24_LDRG068_rgbl3315_MASK           (0xFFFU)
#define locald24_LDRG068_rgbl3315_SHIFT          (0U)
/*! rgbl3315 - rgboelut33_15 */
#define locald24_LDRG068_rgbl3315(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG068_rgbl3315_SHIFT)) & locald24_LDRG068_rgbl3315_MASK)

#define locald24_LDRG068_rgbl3314_MASK           (0xFFF0000U)
#define locald24_LDRG068_rgbl3314_SHIFT          (16U)
/*! rgbl3314 - rgboelut33_14 */
#define locald24_LDRG068_rgbl3314(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG068_rgbl3314_SHIFT)) & locald24_LDRG068_rgbl3314_MASK)
/*! @} */

/*! @name LDRG069 - ldrgbreg069 */
/*! @{ */

#define locald24_LDRG069_rgbl3317_MASK           (0xFFFU)
#define locald24_LDRG069_rgbl3317_SHIFT          (0U)
/*! rgbl3317 - rgboelut33_17 */
#define locald24_LDRG069_rgbl3317(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG069_rgbl3317_SHIFT)) & locald24_LDRG069_rgbl3317_MASK)

#define locald24_LDRG069_rgbl3316_MASK           (0xFFF0000U)
#define locald24_LDRG069_rgbl3316_SHIFT          (16U)
/*! rgbl3316 - rgboelut33_16 */
#define locald24_LDRG069_rgbl3316(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG069_rgbl3316_SHIFT)) & locald24_LDRG069_rgbl3316_MASK)
/*! @} */

/*! @name LDRG06A - ldrgbreg06a */
/*! @{ */

#define locald24_LDRG06A_rgbl3319_MASK           (0xFFFU)
#define locald24_LDRG06A_rgbl3319_SHIFT          (0U)
/*! rgbl3319 - rgboelut33_19 */
#define locald24_LDRG06A_rgbl3319(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06A_rgbl3319_SHIFT)) & locald24_LDRG06A_rgbl3319_MASK)

#define locald24_LDRG06A_rgbl3318_MASK           (0xFFF0000U)
#define locald24_LDRG06A_rgbl3318_SHIFT          (16U)
/*! rgbl3318 - rgboelut33_18 */
#define locald24_LDRG06A_rgbl3318(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06A_rgbl3318_SHIFT)) & locald24_LDRG06A_rgbl3318_MASK)
/*! @} */

/*! @name LDRG06B - ldrgbreg06b */
/*! @{ */

#define locald24_LDRG06B_rgbl3321_MASK           (0xFFFU)
#define locald24_LDRG06B_rgbl3321_SHIFT          (0U)
/*! rgbl3321 - rgboelut33_21 */
#define locald24_LDRG06B_rgbl3321(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06B_rgbl3321_SHIFT)) & locald24_LDRG06B_rgbl3321_MASK)

#define locald24_LDRG06B_rgbl3320_MASK           (0xFFF0000U)
#define locald24_LDRG06B_rgbl3320_SHIFT          (16U)
/*! rgbl3320 - rgboelut33_20 */
#define locald24_LDRG06B_rgbl3320(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06B_rgbl3320_SHIFT)) & locald24_LDRG06B_rgbl3320_MASK)
/*! @} */

/*! @name LDRG06C - ldrgbreg06c */
/*! @{ */

#define locald24_LDRG06C_rgbl3323_MASK           (0xFFFU)
#define locald24_LDRG06C_rgbl3323_SHIFT          (0U)
/*! rgbl3323 - rgboelut33_23 */
#define locald24_LDRG06C_rgbl3323(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06C_rgbl3323_SHIFT)) & locald24_LDRG06C_rgbl3323_MASK)

#define locald24_LDRG06C_rgbl3322_MASK           (0xFFF0000U)
#define locald24_LDRG06C_rgbl3322_SHIFT          (16U)
/*! rgbl3322 - rgboelut33_22 */
#define locald24_LDRG06C_rgbl3322(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06C_rgbl3322_SHIFT)) & locald24_LDRG06C_rgbl3322_MASK)
/*! @} */

/*! @name LDRG06D - ldrgbreg06d */
/*! @{ */

#define locald24_LDRG06D_rgbl3325_MASK           (0xFFFU)
#define locald24_LDRG06D_rgbl3325_SHIFT          (0U)
/*! rgbl3325 - rgboelut33_25 */
#define locald24_LDRG06D_rgbl3325(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06D_rgbl3325_SHIFT)) & locald24_LDRG06D_rgbl3325_MASK)

#define locald24_LDRG06D_rgbl3324_MASK           (0xFFF0000U)
#define locald24_LDRG06D_rgbl3324_SHIFT          (16U)
/*! rgbl3324 - rgboelut33_24 */
#define locald24_LDRG06D_rgbl3324(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06D_rgbl3324_SHIFT)) & locald24_LDRG06D_rgbl3324_MASK)
/*! @} */

/*! @name LDRG06E - ldrgbreg06e */
/*! @{ */

#define locald24_LDRG06E_rgbl3327_MASK           (0xFFFU)
#define locald24_LDRG06E_rgbl3327_SHIFT          (0U)
/*! rgbl3327 - rgboelut33_27 */
#define locald24_LDRG06E_rgbl3327(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06E_rgbl3327_SHIFT)) & locald24_LDRG06E_rgbl3327_MASK)

#define locald24_LDRG06E_rgbl3326_MASK           (0xFFF0000U)
#define locald24_LDRG06E_rgbl3326_SHIFT          (16U)
/*! rgbl3326 - rgboelut33_26 */
#define locald24_LDRG06E_rgbl3326(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06E_rgbl3326_SHIFT)) & locald24_LDRG06E_rgbl3326_MASK)
/*! @} */

/*! @name LDRG06F - ldrgbreg06f */
/*! @{ */

#define locald24_LDRG06F_rgbl3329_MASK           (0xFFFU)
#define locald24_LDRG06F_rgbl3329_SHIFT          (0U)
/*! rgbl3329 - rgboelut33_29 */
#define locald24_LDRG06F_rgbl3329(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06F_rgbl3329_SHIFT)) & locald24_LDRG06F_rgbl3329_MASK)

#define locald24_LDRG06F_rgbl3328_MASK           (0xFFF0000U)
#define locald24_LDRG06F_rgbl3328_SHIFT          (16U)
/*! rgbl3328 - rgboelut33_28 */
#define locald24_LDRG06F_rgbl3328(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG06F_rgbl3328_SHIFT)) & locald24_LDRG06F_rgbl3328_MASK)
/*! @} */

/*! @name LDRG070 - ldrgbreg070 */
/*! @{ */

#define locald24_LDRG070_rgbl3331_MASK           (0xFFFU)
#define locald24_LDRG070_rgbl3331_SHIFT          (0U)
/*! rgbl3331 - rgboelut33_31 */
#define locald24_LDRG070_rgbl3331(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG070_rgbl3331_SHIFT)) & locald24_LDRG070_rgbl3331_MASK)

#define locald24_LDRG070_rgbl3330_MASK           (0xFFF0000U)
#define locald24_LDRG070_rgbl3330_SHIFT          (16U)
/*! rgbl3330 - rgboelut33_30 */
#define locald24_LDRG070_rgbl3330(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG070_rgbl3330_SHIFT)) & locald24_LDRG070_rgbl3330_MASK)
/*! @} */

/*! @name LDRG071 - ldrgbreg071 */
/*! @{ */

#define locald24_LDRG071_rgbl3332_MASK           (0x1FFF0000U)
#define locald24_LDRG071_rgbl3332_SHIFT          (16U)
/*! rgbl3332 - rgboelut33_32 */
#define locald24_LDRG071_rgbl3332(x)             (((uint32_t)(((uint32_t)(x)) << locald24_LDRG071_rgbl3332_SHIFT)) & locald24_LDRG071_rgbl3332_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald24_Register_Masks */


/*!
 * @}
 */ /* end of group locald24_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD24_H_ */

