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
**         CMSIS Peripheral Access Layer for splanar
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
 * @file PERI_splanar.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for splanar
 *
 * CMSIS Peripheral Access Layer for splanar
 */

#if !defined(PERI_SPLANAR_H_)
#define PERI_SPLANAR_H_                          /**< Symbol preventing repeated inclusion */

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
   -- splanar Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar_Peripheral_Access_Layer splanar Peripheral Access Layer
 * @{
 */

/** splanar - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t STATCON;                           /**< StaticControl, offset: 0x8 */
  __IO uint32_t BURBUFMA;                          /**< BurstBufferManagement, offset: 0xC */
  __IO uint32_t RINBSA;                            /**< RingBufStartAddr, offset: 0x10 */
  __IO uint32_t RINBSAMS;                          /**< RingBufStartAddrMSB, offset: 0x14 */
  __IO uint32_t RINBWA;                            /**< RingBufWrapAddr, offset: 0x18 */
  __IO uint32_t RINBWAMS;                          /**< RingBufWrapAddrMSB, offset: 0x1C */
  __IO uint32_t BASEA0;                            /**< BaseAddress0, offset: 0x20 */
  __IO uint32_t BASAMSB0;                          /**< BaseAddressMSB0, offset: 0x24 */
  __IO uint32_t AUTOUBA0;                          /**< AutoUpdateBaseAddress0, offset: 0x28 */
  __IO uint32_t AUTUBAM0;                          /**< AutoUpdateBaseAddressMSB0, offset: 0x2C */
  __IO uint32_t DESBUFA0;                          /**< DestinationBufferAttributes0, offset: 0x30 */
} splanar_Type;

/* ----------------------------------------------------------------------------
   -- splanar Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup splanar_Register_Masks splanar Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define splanar_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define splanar_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define splanar_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << splanar_LU_LkUn_SHIFT)) & splanar_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define splanar_LOCKS_LkSus_MASK                 (0x1U)
#define splanar_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define splanar_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << splanar_LOCKS_LkSus_SHIFT)) & splanar_LOCKS_LkSus_MASK)

#define splanar_LOCKS_PriSt_MASK                 (0x10U)
#define splanar_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define splanar_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << splanar_LOCKS_PriSt_SHIFT)) & splanar_LOCKS_PriSt_MASK)

#define splanar_LOCKS_FreezeS_MASK               (0x100U)
#define splanar_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define splanar_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << splanar_LOCKS_FreezeS_SHIFT)) & splanar_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name STATCON - StaticControl */
/*! @{ */

#define splanar_STATCON_ShdEn_MASK               (0x1U)
#define splanar_STATCON_ShdEn_SHIFT              (0U)
/*! ShdEn - ShdEn */
#define splanar_STATCON_ShdEn(x)                 (((uint32_t)(((uint32_t)(x)) << splanar_STATCON_ShdEn_SHIFT)) & splanar_STATCON_ShdEn_MASK)

#define splanar_STATCON_BaAdAU_MASK              (0x100U)
#define splanar_STATCON_BaAdAU_SHIFT             (8U)
/*! BaAdAU - BaseAddressAutoUpdate */
#define splanar_STATCON_BaAdAU(x)                (((uint32_t)(((uint32_t)(x)) << splanar_STATCON_BaAdAU_SHIFT)) & splanar_STATCON_BaAdAU_MASK)
/*! @} */

/*! @name BURBUFMA - BurstBufferManagement */
/*! @{ */

#define splanar_BURBUFMA_SetBL_MASK              (0x1F00U)
#define splanar_BURBUFMA_SetBL_SHIFT             (8U)
/*! SetBL - SetBurstLength */
#define splanar_BURBUFMA_SetBL(x)                (((uint32_t)(((uint32_t)(x)) << splanar_BURBUFMA_SetBL_SHIFT)) & splanar_BURBUFMA_SetBL_MASK)

#define splanar_BURBUFMA_FlexBLM_MASK            (0x1FE000U)
#define splanar_BURBUFMA_FlexBLM_SHIFT           (13U)
/*! FlexBLM - FlexibleBurstLengthMax */
#define splanar_BURBUFMA_FlexBLM(x)              (((uint32_t)(((uint32_t)(x)) << splanar_BURBUFMA_FlexBLM_SHIFT)) & splanar_BURBUFMA_FlexBLM_MASK)

#define splanar_BURBUFMA_BurTimeE_MASK           (0x800000U)
#define splanar_BURBUFMA_BurTimeE_SHIFT          (23U)
/*! BurTimeE - BurstTimerEn */
#define splanar_BURBUFMA_BurTimeE(x)             (((uint32_t)(((uint32_t)(x)) << splanar_BURBUFMA_BurTimeE_SHIFT)) & splanar_BURBUFMA_BurTimeE_MASK)

#define splanar_BURBUFMA_BurTimeo_MASK           (0xFF000000U)
#define splanar_BURBUFMA_BurTimeo_SHIFT          (24U)
/*! BurTimeo - BurstTimeout */
#define splanar_BURBUFMA_BurTimeo(x)             (((uint32_t)(((uint32_t)(x)) << splanar_BURBUFMA_BurTimeo_SHIFT)) & splanar_BURBUFMA_BurTimeo_MASK)
/*! @} */

/*! @name RINBSA - RingBufStartAddr */
/*! @{ */

#define splanar_RINBSA_RBStAd_MASK               (0xFFFFFFFFU)
#define splanar_RINBSA_RBStAd_SHIFT              (0U)
/*! RBStAd - RingBufStartAddr */
#define splanar_RINBSA_RBStAd(x)                 (((uint32_t)(((uint32_t)(x)) << splanar_RINBSA_RBStAd_SHIFT)) & splanar_RINBSA_RBStAd_MASK)
/*! @} */

/*! @name RINBSAMS - RingBufStartAddrMSB */
/*! @{ */

#define splanar_RINBSAMS_RBStAdM_MASK            (0xFFU)
#define splanar_RINBSAMS_RBStAdM_SHIFT           (0U)
/*! RBStAdM - RingBufStartAddrMSB */
#define splanar_RINBSAMS_RBStAdM(x)              (((uint32_t)(((uint32_t)(x)) << splanar_RINBSAMS_RBStAdM_SHIFT)) & splanar_RINBSAMS_RBStAdM_MASK)
/*! @} */

/*! @name RINBWA - RingBufWrapAddr */
/*! @{ */

#define splanar_RINBWA_RBWrAd_MASK               (0xFFFFFFFFU)
#define splanar_RINBWA_RBWrAd_SHIFT              (0U)
/*! RBWrAd - RingBufWrapAddr */
#define splanar_RINBWA_RBWrAd(x)                 (((uint32_t)(((uint32_t)(x)) << splanar_RINBWA_RBWrAd_SHIFT)) & splanar_RINBWA_RBWrAd_MASK)
/*! @} */

/*! @name RINBWAMS - RingBufWrapAddrMSB */
/*! @{ */

#define splanar_RINBWAMS_RBWrAdM_MASK            (0xFFU)
#define splanar_RINBWAMS_RBWrAdM_SHIFT           (0U)
/*! RBWrAdM - RingBufWrapAddrMSB */
#define splanar_RINBWAMS_RBWrAdM(x)              (((uint32_t)(((uint32_t)(x)) << splanar_RINBWAMS_RBWrAdM_SHIFT)) & splanar_RINBWAMS_RBWrAdM_MASK)
/*! @} */

/*! @name BASEA0 - BaseAddress0 */
/*! @{ */

#define splanar_BASEA0_BaseAdd0_MASK             (0xFFFFFFFFU)
#define splanar_BASEA0_BaseAdd0_SHIFT            (0U)
/*! BaseAdd0 - BaseAddress0 */
#define splanar_BASEA0_BaseAdd0(x)               (((uint32_t)(((uint32_t)(x)) << splanar_BASEA0_BaseAdd0_SHIFT)) & splanar_BASEA0_BaseAdd0_MASK)
/*! @} */

/*! @name BASAMSB0 - BaseAddressMSB0 */
/*! @{ */

#define splanar_BASAMSB0_BaAdMB0_MASK            (0xFFU)
#define splanar_BASAMSB0_BaAdMB0_SHIFT           (0U)
/*! BaAdMB0 - BaseAddressMSB0 */
#define splanar_BASAMSB0_BaAdMB0(x)              (((uint32_t)(((uint32_t)(x)) << splanar_BASAMSB0_BaAdMB0_SHIFT)) & splanar_BASAMSB0_BaAdMB0_MASK)
/*! @} */

/*! @name AUTOUBA0 - AutoUpdateBaseAddress0 */
/*! @{ */

#define splanar_AUTOUBA0_AutoUBA0_MASK           (0xFFFFFFFFU)
#define splanar_AUTOUBA0_AutoUBA0_SHIFT          (0U)
/*! AutoUBA0 - AutoUpdateBaseAddress0 */
#define splanar_AUTOUBA0_AutoUBA0(x)             (((uint32_t)(((uint32_t)(x)) << splanar_AUTOUBA0_AutoUBA0_SHIFT)) & splanar_AUTOUBA0_AutoUBA0_MASK)
/*! @} */

/*! @name AUTUBAM0 - AutoUpdateBaseAddressMSB0 */
/*! @{ */

#define splanar_AUTUBAM0_AutoUBM0_MASK           (0xFFU)
#define splanar_AUTUBAM0_AutoUBM0_SHIFT          (0U)
/*! AutoUBM0 - AutoUpdateBaseAddressMSB0 */
#define splanar_AUTUBAM0_AutoUBM0(x)             (((uint32_t)(((uint32_t)(x)) << splanar_AUTUBAM0_AutoUBM0_SHIFT)) & splanar_AUTUBAM0_AutoUBM0_MASK)
/*! @} */

/*! @name DESBUFA0 - DestinationBufferAttributes0 */
/*! @{ */

#define splanar_DESBUFA0_Stride0_MASK            (0x1FFFFU)
#define splanar_DESBUFA0_Stride0_SHIFT           (0U)
/*! Stride0 - Stride0 */
#define splanar_DESBUFA0_Stride0(x)              (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_Stride0_SHIFT)) & splanar_DESBUFA0_Stride0_MASK)

#define splanar_DESBUFA0_AlphaE0_MASK            (0x100000U)
#define splanar_DESBUFA0_AlphaE0_SHIFT           (20U)
/*! AlphaE0 - AlphaEnable0 */
#define splanar_DESBUFA0_AlphaE0(x)              (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_AlphaE0_SHIFT)) & splanar_DESBUFA0_AlphaE0_MASK)

#define splanar_DESBUFA0_RedEn0_MASK             (0x200000U)
#define splanar_DESBUFA0_RedEn0_SHIFT            (21U)
/*! RedEn0 - RedEnable0 */
#define splanar_DESBUFA0_RedEn0(x)               (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_RedEn0_SHIFT)) & splanar_DESBUFA0_RedEn0_MASK)

#define splanar_DESBUFA0_GreenEn0_MASK           (0x400000U)
#define splanar_DESBUFA0_GreenEn0_SHIFT          (22U)
/*! GreenEn0 - GreenEnable0 */
#define splanar_DESBUFA0_GreenEn0(x)             (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_GreenEn0_SHIFT)) & splanar_DESBUFA0_GreenEn0_MASK)

#define splanar_DESBUFA0_BlueE0_MASK             (0x800000U)
#define splanar_DESBUFA0_BlueE0_SHIFT            (23U)
/*! BlueE0 - BlueEnable0 */
#define splanar_DESBUFA0_BlueE0(x)               (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_BlueE0_SHIFT)) & splanar_DESBUFA0_BlueE0_MASK)

#define splanar_DESBUFA0_BitsPP0_MASK            (0x7F000000U)
#define splanar_DESBUFA0_BitsPP0_SHIFT           (24U)
/*! BitsPP0 - BitsPerPixel0 */
#define splanar_DESBUFA0_BitsPP0(x)              (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_BitsPP0_SHIFT)) & splanar_DESBUFA0_BitsPP0_MASK)

#define splanar_DESBUFA0_DWBS0_MASK              (0x80000000U)
#define splanar_DESBUFA0_DWBS0_SHIFT             (31U)
/*! DWBS0 - DWordByteSwap0 */
#define splanar_DESBUFA0_DWBS0(x)                (((uint32_t)(((uint32_t)(x)) << splanar_DESBUFA0_DWBS0_SHIFT)) & splanar_DESBUFA0_DWBS0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group splanar_Register_Masks */


/*!
 * @}
 */ /* end of group splanar_Peripheral_Access_Layer */


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


#endif  /* PERI_SPLANAR_H_ */

