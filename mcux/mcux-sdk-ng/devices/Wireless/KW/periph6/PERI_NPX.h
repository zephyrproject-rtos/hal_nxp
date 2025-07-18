/*
** ###################################################################
**     Processors:          KW47B42Z83AFTA_cm33_core0
**                          KW47B42Z83AFTA_cm33_core1
**                          KW47B42Z96AFTA_cm33_core0
**                          KW47B42Z96AFTA_cm33_core1
**                          KW47B42Z97AFTA_cm33_core0
**                          KW47B42Z97AFTA_cm33_core1
**                          KW47B42ZB2AFTA_cm33_core0
**                          KW47B42ZB2AFTA_cm33_core1
**                          KW47B42ZB3AFTA_cm33_core0
**                          KW47B42ZB3AFTA_cm33_core1
**                          KW47B42ZB6AFTA_cm33_core0
**                          KW47B42ZB6AFTA_cm33_core1
**                          KW47B42ZB7AFTA_cm33_core0
**                          KW47B42ZB7AFTA_cm33_core1
**                          KW47Z42082AFTA
**                          KW47Z42092AFTA
**                          KW47Z420B2AFTA
**                          KW47Z420B3AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NPX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NPX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NPX
 *
 * CMSIS Peripheral Access Layer for NPX
 */

#if !defined(PERI_NPX_H_)
#define PERI_NPX_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW47B42Z83AFTA_cm33_core0))
#include "KW47B42Z83_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z83AFTA_cm33_core1))
#include "KW47B42Z83_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core0))
#include "KW47B42Z96_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core1))
#include "KW47B42Z96_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core0))
#include "KW47B42Z97_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core1))
#include "KW47B42Z97_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core0))
#include "KW47B42ZB2_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core1))
#include "KW47B42ZB2_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core0))
#include "KW47B42ZB3_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core1))
#include "KW47B42ZB3_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core0))
#include "KW47B42ZB6_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core1))
#include "KW47B42ZB6_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0))
#include "KW47B42ZB7_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1))
#include "KW47B42ZB7_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47Z42082AFTA))
#include "KW47Z42082_COMMON.h"
#elif (defined(CPU_KW47Z42092AFTA))
#include "KW47Z42092_COMMON.h"
#elif (defined(CPU_KW47Z420B2AFTA))
#include "KW47Z420B2_COMMON.h"
#elif (defined(CPU_KW47Z420B3AFTA))
#include "KW47Z420B3_COMMON.h"
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
   -- NPX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPX_Peripheral_Access_Layer NPX Peripheral Access Layer
 * @{
 */

/** NPX - Size of Registers Arrays */
#define NPX_NPX_REGION_COUNT                      4u

/** NPX - Register Layout Typedef */
typedef struct {
  __IO uint32_t NPXCR;                             /**< NPX Control Register, offset: 0x0 */
  __I  uint32_t NPXSR;                             /**< NPX Status Register, offset: 0x4 */
       uint8_t RESERVED_0[248];
  struct {                                         /* offset: 0x100, array step: 0x40 */
    __O  uint32_t MRMASKEDKEYWORD0;                  /**< Memory Region 0, Masked Key Word 0..Memory Region 3, Masked Key Word 0, array offset: 0x100, array step: 0x40 */
    __O  uint32_t MRMASKEDKEYWORD1;                  /**< Memory Region 0, Masked Key Word 1..Memory Region 3, Masked Key Word 1, array offset: 0x104, array step: 0x40 */
    __O  uint32_t MRMASKEDKEYWORD2;                  /**< Memory Region 0, Masked Key Word 2..Memory Region 3, Masked Key Word 2, array offset: 0x108, array step: 0x40 */
    __O  uint32_t MRMASKEDKEYWORD3;                  /**< Memory Region 0, Masked Key Word 3..Memory Region 3, Masked Key Word 3, array offset: 0x10C, array step: 0x40 */
    __O  uint32_t MRMASKFORKEYWORD0;                 /**< Memory Region 0, Mask for Key Word 0..Memory Region 3, Mask for Key Word 0, array offset: 0x110, array step: 0x40 */
    __O  uint32_t MRMASKFORKEYWORD1;                 /**< Memory Region 0, Mask for Key Word 1..Memory Region 3, Mask for Key Word 1, array offset: 0x114, array step: 0x40 */
    __O  uint32_t MRMASKFORKEYWORD2;                 /**< Memory Region 0, Mask for Key Word 2..Memory Region 3, Mask for Key Word 2, array offset: 0x118, array step: 0x40 */
    __O  uint32_t MRMASKFORKEYWORD3;                 /**< Memory Region 0, Mask for Key Word 3..Memory Region 3, Mask for Key Word 3, array offset: 0x11C, array step: 0x40 */
    __O  uint32_t MRSTARTADDR;                       /**< Memory Region 0 Start Address..Memory Region 3 Start Address, array offset: 0x120, array step: 0x40 */
    __O  uint32_t MRENDADDR;                         /**< Memory Region 0 End Address..Memory Region 3 End Address, array offset: 0x124, array step: 0x40 */
         uint8_t RESERVED_0[24];
  } NPX_REGION[NPX_NPX_REGION_COUNT];
} NPX_Type;

/* ----------------------------------------------------------------------------
   -- NPX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPX_Register_Masks NPX Register Masks
 * @{
 */

/*! @name NPXCR - NPX Control Register */
/*! @{ */

#define NPX_NPXCR_GEE_MASK                       (0x7U)
#define NPX_NPXCR_GEE_SHIFT                      (0U)
/*! GEE - Global Encryption Enable
 *  0b010..Global encryption enabled. NPX on-the-fly encryption is enabled if the flash access hits in a valid
 *         memory region. Subsequent reads return 010b.
 *  0b101..Global encryption disabled. NPX on-the-fly encryption is disabled. Subsequent reads return 000b.
 */
#define NPX_NPXCR_GEE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GEE_SHIFT)) & NPX_NPXCR_GEE_MASK)

#define NPX_NPXCR_GDE_MASK                       (0x70U)
#define NPX_NPXCR_GDE_SHIFT                      (4U)
/*! GDE - Global Decryption Enable
 *  0b010..Global decryption enabled. NPX on-the-fly decryption is globally enabled. Subsequent reads return 010b.
 *  0b101..Global decryption disabled. NPX on-the-fly decryption is globally disabled. Subsequent reads return 000b.
 */
#define NPX_NPXCR_GDE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GDE_SHIFT)) & NPX_NPXCR_GDE_MASK)

#define NPX_NPXCR_SLK_MASK                       (0x700U)
#define NPX_NPXCR_SLK_SHIFT                      (8U)
/*! SLK - System Lock Enable
 *  0b010..Lock enabled: cannot write (via IPS) to keys, masks, regions, NPXCR (NPX Control Register), NPXSR (NPX
 *         Status Register). Subsequent reads return 010b.
 *  0b101..Lock disabled Subsequent reads return 000b.
 */
#define NPX_NPXCR_SLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_SLK_SHIFT)) & NPX_NPXCR_SLK_MASK)

#define NPX_NPXCR_GLK_MASK                       (0x7000U)
#define NPX_NPXCR_GLK_SHIFT                      (12U)
/*! GLK - Global Lock Enable
 *  0b010..Lock enabled: cannot write to keys, masks, regions, NPXCR (NPX Control Register), NPXSR (NPX Status Register). Subsequent reads return 010b.
 *  0b101..Lock disabled. Subsequent reads return 000b.
 */
#define NPX_NPXCR_GLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GLK_SHIFT)) & NPX_NPXCR_GLK_MASK)
/*! @} */

/*! @name NPXSR - NPX Status Register */
/*! @{ */

#define NPX_NPXSR_NRGD_MASK                      (0xFU)
#define NPX_NPXSR_NRGD_SHIFT                     (0U)
/*! NRGD - Number of implemented memory regions
 *  0b0000..No (zero) implemented memory regions
 *  0b0001..1 implemented memory region
 *  0b0010..2 implemented memory regions
 *  0b0011..3 implemented memory regions
 *  0b0100..4 implemented memory regions
 */
#define NPX_NPXSR_NRGD(x)                        (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_NRGD_SHIFT)) & NPX_NPXSR_NRGD_MASK)

#define NPX_NPXSR_V0_MASK                        (0x100U)
#define NPX_NPXSR_V0_SHIFT                       (8U)
/*! V0 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V0(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V0_SHIFT)) & NPX_NPXSR_V0_MASK)

#define NPX_NPXSR_V1_MASK                        (0x200U)
#define NPX_NPXSR_V1_SHIFT                       (9U)
/*! V1 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V1(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V1_SHIFT)) & NPX_NPXSR_V1_MASK)

#define NPX_NPXSR_V2_MASK                        (0x400U)
#define NPX_NPXSR_V2_SHIFT                       (10U)
/*! V2 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V2(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V2_SHIFT)) & NPX_NPXSR_V2_MASK)

#define NPX_NPXSR_V3_MASK                        (0x800U)
#define NPX_NPXSR_V3_SHIFT                       (11U)
/*! V3 - Key n Valid
 *  0b0..Not valid
 *  0b1..Valid
 */
#define NPX_NPXSR_V3(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V3_SHIFT)) & NPX_NPXSR_V3_MASK)
/*! @} */

/*! @name MRMASKEDKEYWORD0 - Memory Region 0, Masked Key Word 0..Memory Region 3, Masked Key Word 0 */
/*! @{ */

#define NPX_MRMASKEDKEYWORD0_MASKEDKEY0WORD0_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY0WORD0_SHIFT (0U)
/*! MASKEDKEY0WORD0 - Masked Key Word 0 */
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY0WORD0(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD0_MASKEDKEY0WORD0_SHIFT)) & NPX_MRMASKEDKEYWORD0_MASKEDKEY0WORD0_MASK)

#define NPX_MRMASKEDKEYWORD0_MASKEDKEY1WORD0_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY1WORD0_SHIFT (0U)
/*! MASKEDKEY1WORD0 - Masked Key Word 1 */
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY1WORD0(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD0_MASKEDKEY1WORD0_SHIFT)) & NPX_MRMASKEDKEYWORD0_MASKEDKEY1WORD0_MASK)

#define NPX_MRMASKEDKEYWORD0_MASKEDKEY2WORD0_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY2WORD0_SHIFT (0U)
/*! MASKEDKEY2WORD0 - Masked Key Word 2 */
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY2WORD0(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD0_MASKEDKEY2WORD0_SHIFT)) & NPX_MRMASKEDKEYWORD0_MASKEDKEY2WORD0_MASK)

#define NPX_MRMASKEDKEYWORD0_MASKEDKEY3WORD0_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY3WORD0_SHIFT (0U)
/*! MASKEDKEY3WORD0 - Masked Key Word 3 */
#define NPX_MRMASKEDKEYWORD0_MASKEDKEY3WORD0(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD0_MASKEDKEY3WORD0_SHIFT)) & NPX_MRMASKEDKEYWORD0_MASKEDKEY3WORD0_MASK)
/*! @} */

/* The count of NPX_MRMASKEDKEYWORD0 */
#define NPX_MRMASKEDKEYWORD0_COUNT               (4U)

/*! @name MRMASKEDKEYWORD1 - Memory Region 0, Masked Key Word 1..Memory Region 3, Masked Key Word 1 */
/*! @{ */

#define NPX_MRMASKEDKEYWORD1_MASKEDKEY0WORD1_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY0WORD1_SHIFT (0U)
/*! MASKEDKEY0WORD1 - Masked Key Word 1 */
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY0WORD1(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD1_MASKEDKEY0WORD1_SHIFT)) & NPX_MRMASKEDKEYWORD1_MASKEDKEY0WORD1_MASK)

#define NPX_MRMASKEDKEYWORD1_MASKEDKEY1WORD1_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY1WORD1_SHIFT (0U)
/*! MASKEDKEY1WORD1 - Masked Key Word 1 */
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY1WORD1(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD1_MASKEDKEY1WORD1_SHIFT)) & NPX_MRMASKEDKEYWORD1_MASKEDKEY1WORD1_MASK)

#define NPX_MRMASKEDKEYWORD1_MASKEDKEY2WORD1_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY2WORD1_SHIFT (0U)
/*! MASKEDKEY2WORD1 - Masked Key Word 1 */
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY2WORD1(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD1_MASKEDKEY2WORD1_SHIFT)) & NPX_MRMASKEDKEYWORD1_MASKEDKEY2WORD1_MASK)

#define NPX_MRMASKEDKEYWORD1_MASKEDKEY3WORD1_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY3WORD1_SHIFT (0U)
/*! MASKEDKEY3WORD1 - Masked Key Word 1 */
#define NPX_MRMASKEDKEYWORD1_MASKEDKEY3WORD1(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD1_MASKEDKEY3WORD1_SHIFT)) & NPX_MRMASKEDKEYWORD1_MASKEDKEY3WORD1_MASK)
/*! @} */

/* The count of NPX_MRMASKEDKEYWORD1 */
#define NPX_MRMASKEDKEYWORD1_COUNT               (4U)

/*! @name MRMASKEDKEYWORD2 - Memory Region 0, Masked Key Word 2..Memory Region 3, Masked Key Word 2 */
/*! @{ */

#define NPX_MRMASKEDKEYWORD2_MASKEDKEY0WORD2_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY0WORD2_SHIFT (0U)
/*! MASKEDKEY0WORD2 - Masked Key Word 2 */
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY0WORD2(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD2_MASKEDKEY0WORD2_SHIFT)) & NPX_MRMASKEDKEYWORD2_MASKEDKEY0WORD2_MASK)

#define NPX_MRMASKEDKEYWORD2_MASKEDKEY1WORD2_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY1WORD2_SHIFT (0U)
/*! MASKEDKEY1WORD2 - Masked Key Word 2 */
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY1WORD2(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD2_MASKEDKEY1WORD2_SHIFT)) & NPX_MRMASKEDKEYWORD2_MASKEDKEY1WORD2_MASK)

#define NPX_MRMASKEDKEYWORD2_MASKEDKEY2WORD2_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY2WORD2_SHIFT (0U)
/*! MASKEDKEY2WORD2 - Masked Key Word 2 */
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY2WORD2(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD2_MASKEDKEY2WORD2_SHIFT)) & NPX_MRMASKEDKEYWORD2_MASKEDKEY2WORD2_MASK)

#define NPX_MRMASKEDKEYWORD2_MASKEDKEY3WORD2_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY3WORD2_SHIFT (0U)
/*! MASKEDKEY3WORD2 - Masked Key Word 2 */
#define NPX_MRMASKEDKEYWORD2_MASKEDKEY3WORD2(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD2_MASKEDKEY3WORD2_SHIFT)) & NPX_MRMASKEDKEYWORD2_MASKEDKEY3WORD2_MASK)
/*! @} */

/* The count of NPX_MRMASKEDKEYWORD2 */
#define NPX_MRMASKEDKEYWORD2_COUNT               (4U)

/*! @name MRMASKEDKEYWORD3 - Memory Region 0, Masked Key Word 3..Memory Region 3, Masked Key Word 3 */
/*! @{ */

#define NPX_MRMASKEDKEYWORD3_MASKEDKEY0WORD3_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY0WORD3_SHIFT (0U)
/*! MASKEDKEY0WORD3 - Masked Key Word 3 */
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY0WORD3(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD3_MASKEDKEY0WORD3_SHIFT)) & NPX_MRMASKEDKEYWORD3_MASKEDKEY0WORD3_MASK)

#define NPX_MRMASKEDKEYWORD3_MASKEDKEY1WORD3_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY1WORD3_SHIFT (0U)
/*! MASKEDKEY1WORD3 - Masked Key Word 3 */
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY1WORD3(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD3_MASKEDKEY1WORD3_SHIFT)) & NPX_MRMASKEDKEYWORD3_MASKEDKEY1WORD3_MASK)

#define NPX_MRMASKEDKEYWORD3_MASKEDKEY2WORD3_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY2WORD3_SHIFT (0U)
/*! MASKEDKEY2WORD3 - Masked Key Word 3 */
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY2WORD3(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD3_MASKEDKEY2WORD3_SHIFT)) & NPX_MRMASKEDKEYWORD3_MASKEDKEY2WORD3_MASK)

#define NPX_MRMASKEDKEYWORD3_MASKEDKEY3WORD3_MASK (0xFFFFFFFFU)
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY3WORD3_SHIFT (0U)
/*! MASKEDKEY3WORD3 - Masked Key Word 3 */
#define NPX_MRMASKEDKEYWORD3_MASKEDKEY3WORD3(x)  (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKEDKEYWORD3_MASKEDKEY3WORD3_SHIFT)) & NPX_MRMASKEDKEYWORD3_MASKEDKEY3WORD3_MASK)
/*! @} */

/* The count of NPX_MRMASKEDKEYWORD3 */
#define NPX_MRMASKEDKEYWORD3_COUNT               (4U)

/*! @name MRMASKFORKEYWORD0 - Memory Region 0, Mask for Key Word 0..Memory Region 3, Mask for Key Word 0 */
/*! @{ */

#define NPX_MRMASKFORKEYWORD0_MASK0WORD0_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD0_MASK0WORD0_SHIFT   (0U)
/*! MASK0WORD0 - Mask for Key Word 0 */
#define NPX_MRMASKFORKEYWORD0_MASK0WORD0(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD0_MASK0WORD0_SHIFT)) & NPX_MRMASKFORKEYWORD0_MASK0WORD0_MASK)

#define NPX_MRMASKFORKEYWORD0_MASK1WORD0_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD0_MASK1WORD0_SHIFT   (0U)
/*! MASK1WORD0 - Mask for Key Word 0 */
#define NPX_MRMASKFORKEYWORD0_MASK1WORD0(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD0_MASK1WORD0_SHIFT)) & NPX_MRMASKFORKEYWORD0_MASK1WORD0_MASK)

#define NPX_MRMASKFORKEYWORD0_MASK2WORD0_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD0_MASK2WORD0_SHIFT   (0U)
/*! MASK2WORD0 - Mask for Key Word 0 */
#define NPX_MRMASKFORKEYWORD0_MASK2WORD0(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD0_MASK2WORD0_SHIFT)) & NPX_MRMASKFORKEYWORD0_MASK2WORD0_MASK)

#define NPX_MRMASKFORKEYWORD0_MASK3WORD0_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD0_MASK3WORD0_SHIFT   (0U)
/*! MASK3WORD0 - Mask for Key Word 0 */
#define NPX_MRMASKFORKEYWORD0_MASK3WORD0(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD0_MASK3WORD0_SHIFT)) & NPX_MRMASKFORKEYWORD0_MASK3WORD0_MASK)
/*! @} */

/* The count of NPX_MRMASKFORKEYWORD0 */
#define NPX_MRMASKFORKEYWORD0_COUNT              (4U)

/*! @name MRMASKFORKEYWORD1 - Memory Region 0, Mask for Key Word 1..Memory Region 3, Mask for Key Word 1 */
/*! @{ */

#define NPX_MRMASKFORKEYWORD1_MASK0WORD1_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD1_MASK0WORD1_SHIFT   (0U)
/*! MASK0WORD1 - Mask for Key Word 1 */
#define NPX_MRMASKFORKEYWORD1_MASK0WORD1(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD1_MASK0WORD1_SHIFT)) & NPX_MRMASKFORKEYWORD1_MASK0WORD1_MASK)

#define NPX_MRMASKFORKEYWORD1_MASK1WORD1_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD1_MASK1WORD1_SHIFT   (0U)
/*! MASK1WORD1 - Mask for Key Word 1 */
#define NPX_MRMASKFORKEYWORD1_MASK1WORD1(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD1_MASK1WORD1_SHIFT)) & NPX_MRMASKFORKEYWORD1_MASK1WORD1_MASK)

#define NPX_MRMASKFORKEYWORD1_MASK2WORD1_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD1_MASK2WORD1_SHIFT   (0U)
/*! MASK2WORD1 - Mask for Key Word 1 */
#define NPX_MRMASKFORKEYWORD1_MASK2WORD1(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD1_MASK2WORD1_SHIFT)) & NPX_MRMASKFORKEYWORD1_MASK2WORD1_MASK)

#define NPX_MRMASKFORKEYWORD1_MASK3WORD1_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD1_MASK3WORD1_SHIFT   (0U)
/*! MASK3WORD1 - Mask for Key Word 1 */
#define NPX_MRMASKFORKEYWORD1_MASK3WORD1(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD1_MASK3WORD1_SHIFT)) & NPX_MRMASKFORKEYWORD1_MASK3WORD1_MASK)
/*! @} */

/* The count of NPX_MRMASKFORKEYWORD1 */
#define NPX_MRMASKFORKEYWORD1_COUNT              (4U)

/*! @name MRMASKFORKEYWORD2 - Memory Region 0, Mask for Key Word 2..Memory Region 3, Mask for Key Word 2 */
/*! @{ */

#define NPX_MRMASKFORKEYWORD2_MASK0WORD2_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD2_MASK0WORD2_SHIFT   (0U)
/*! MASK0WORD2 - Mask for Key Word 2 */
#define NPX_MRMASKFORKEYWORD2_MASK0WORD2(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD2_MASK0WORD2_SHIFT)) & NPX_MRMASKFORKEYWORD2_MASK0WORD2_MASK)

#define NPX_MRMASKFORKEYWORD2_MASK1WORD2_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD2_MASK1WORD2_SHIFT   (0U)
/*! MASK1WORD2 - Mask for Key Word 2 */
#define NPX_MRMASKFORKEYWORD2_MASK1WORD2(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD2_MASK1WORD2_SHIFT)) & NPX_MRMASKFORKEYWORD2_MASK1WORD2_MASK)

#define NPX_MRMASKFORKEYWORD2_MASK2WORD2_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD2_MASK2WORD2_SHIFT   (0U)
/*! MASK2WORD2 - Mask for Key Word 2 */
#define NPX_MRMASKFORKEYWORD2_MASK2WORD2(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD2_MASK2WORD2_SHIFT)) & NPX_MRMASKFORKEYWORD2_MASK2WORD2_MASK)

#define NPX_MRMASKFORKEYWORD2_MASK3WORD2_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD2_MASK3WORD2_SHIFT   (0U)
/*! MASK3WORD2 - Mask for Key Word 2 */
#define NPX_MRMASKFORKEYWORD2_MASK3WORD2(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD2_MASK3WORD2_SHIFT)) & NPX_MRMASKFORKEYWORD2_MASK3WORD2_MASK)
/*! @} */

/* The count of NPX_MRMASKFORKEYWORD2 */
#define NPX_MRMASKFORKEYWORD2_COUNT              (4U)

/*! @name MRMASKFORKEYWORD3 - Memory Region 0, Mask for Key Word 3..Memory Region 3, Mask for Key Word 3 */
/*! @{ */

#define NPX_MRMASKFORKEYWORD3_MASK0WORD3_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD3_MASK0WORD3_SHIFT   (0U)
/*! MASK0WORD3 - Mask for Key Word 3 */
#define NPX_MRMASKFORKEYWORD3_MASK0WORD3(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD3_MASK0WORD3_SHIFT)) & NPX_MRMASKFORKEYWORD3_MASK0WORD3_MASK)

#define NPX_MRMASKFORKEYWORD3_MASK1WORD3_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD3_MASK1WORD3_SHIFT   (0U)
/*! MASK1WORD3 - Mask for Key Word 3 */
#define NPX_MRMASKFORKEYWORD3_MASK1WORD3(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD3_MASK1WORD3_SHIFT)) & NPX_MRMASKFORKEYWORD3_MASK1WORD3_MASK)

#define NPX_MRMASKFORKEYWORD3_MASK2WORD3_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD3_MASK2WORD3_SHIFT   (0U)
/*! MASK2WORD3 - Mask for Key Word 3 */
#define NPX_MRMASKFORKEYWORD3_MASK2WORD3(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD3_MASK2WORD3_SHIFT)) & NPX_MRMASKFORKEYWORD3_MASK2WORD3_MASK)

#define NPX_MRMASKFORKEYWORD3_MASK3WORD3_MASK    (0xFFFFFFFFU)
#define NPX_MRMASKFORKEYWORD3_MASK3WORD3_SHIFT   (0U)
/*! MASK3WORD3 - Mask for Key Word 3 */
#define NPX_MRMASKFORKEYWORD3_MASK3WORD3(x)      (((uint32_t)(((uint32_t)(x)) << NPX_MRMASKFORKEYWORD3_MASK3WORD3_SHIFT)) & NPX_MRMASKFORKEYWORD3_MASK3WORD3_MASK)
/*! @} */

/* The count of NPX_MRMASKFORKEYWORD3 */
#define NPX_MRMASKFORKEYWORD3_COUNT              (4U)

/*! @name MRSTARTADDR - Memory Region 0 Start Address..Memory Region 3 Start Address */
/*! @{ */

#define NPX_MRSTARTADDR_SRTADDR0_MASK            (0xFFFFFE00U)
#define NPX_MRSTARTADDR_SRTADDR0_SHIFT           (9U)
/*! SRTADDR0 - Start Address for Memory Region 0 */
#define NPX_MRSTARTADDR_SRTADDR0(x)              (((uint32_t)(((uint32_t)(x)) << NPX_MRSTARTADDR_SRTADDR0_SHIFT)) & NPX_MRSTARTADDR_SRTADDR0_MASK)

#define NPX_MRSTARTADDR_SRTADDR1_MASK            (0xFFFFFE00U)
#define NPX_MRSTARTADDR_SRTADDR1_SHIFT           (9U)
/*! SRTADDR1 - Start Address for Memory Region 1 */
#define NPX_MRSTARTADDR_SRTADDR1(x)              (((uint32_t)(((uint32_t)(x)) << NPX_MRSTARTADDR_SRTADDR1_SHIFT)) & NPX_MRSTARTADDR_SRTADDR1_MASK)

#define NPX_MRSTARTADDR_SRTADDR2_MASK            (0xFFFFFE00U)
#define NPX_MRSTARTADDR_SRTADDR2_SHIFT           (9U)
/*! SRTADDR2 - Start Address for Memory Region 2 */
#define NPX_MRSTARTADDR_SRTADDR2(x)              (((uint32_t)(((uint32_t)(x)) << NPX_MRSTARTADDR_SRTADDR2_SHIFT)) & NPX_MRSTARTADDR_SRTADDR2_MASK)

#define NPX_MRSTARTADDR_SRTADDR3_MASK            (0xFFFFFE00U)
#define NPX_MRSTARTADDR_SRTADDR3_SHIFT           (9U)
/*! SRTADDR3 - Start Address for Memory Region 3 */
#define NPX_MRSTARTADDR_SRTADDR3(x)              (((uint32_t)(((uint32_t)(x)) << NPX_MRSTARTADDR_SRTADDR3_SHIFT)) & NPX_MRSTARTADDR_SRTADDR3_MASK)
/*! @} */

/* The count of NPX_MRSTARTADDR */
#define NPX_MRSTARTADDR_COUNT                    (4U)

/*! @name MRENDADDR - Memory Region 0 End Address..Memory Region 3 End Address */
/*! @{ */

#define NPX_MRENDADDR_V_MASK                     (0x7U)
#define NPX_MRENDADDR_V_SHIFT                    (0U)
/*! V - Memory Region 3 is Valid
 *  0b010..Memory Region 0 is valid. Subsequent reads return 111b.
 *  0b101..Memory Region 0 is not valid.
 */
#define NPX_MRENDADDR_V(x)                       (((uint32_t)(((uint32_t)(x)) << NPX_MRENDADDR_V_SHIFT)) & NPX_MRENDADDR_V_MASK)

#define NPX_MRENDADDR_ENDADDR0_MASK              (0xFFFFFE00U)
#define NPX_MRENDADDR_ENDADDR0_SHIFT             (9U)
/*! ENDADDR0 - End Address for Memory Region 0 */
#define NPX_MRENDADDR_ENDADDR0(x)                (((uint32_t)(((uint32_t)(x)) << NPX_MRENDADDR_ENDADDR0_SHIFT)) & NPX_MRENDADDR_ENDADDR0_MASK)

#define NPX_MRENDADDR_ENDADDR1_MASK              (0xFFFFFE00U)
#define NPX_MRENDADDR_ENDADDR1_SHIFT             (9U)
/*! ENDADDR1 - End Address for Memory Region 1 */
#define NPX_MRENDADDR_ENDADDR1(x)                (((uint32_t)(((uint32_t)(x)) << NPX_MRENDADDR_ENDADDR1_SHIFT)) & NPX_MRENDADDR_ENDADDR1_MASK)

#define NPX_MRENDADDR_ENDADDR2_MASK              (0xFFFFFE00U)
#define NPX_MRENDADDR_ENDADDR2_SHIFT             (9U)
/*! ENDADDR2 - End Address for Memory Region 2 */
#define NPX_MRENDADDR_ENDADDR2(x)                (((uint32_t)(((uint32_t)(x)) << NPX_MRENDADDR_ENDADDR2_SHIFT)) & NPX_MRENDADDR_ENDADDR2_MASK)

#define NPX_MRENDADDR_ENDADDR3_MASK              (0xFFFFFE00U)
#define NPX_MRENDADDR_ENDADDR3_SHIFT             (9U)
/*! ENDADDR3 - End Address for Memory Region 3 */
#define NPX_MRENDADDR_ENDADDR3(x)                (((uint32_t)(((uint32_t)(x)) << NPX_MRENDADDR_ENDADDR3_SHIFT)) & NPX_MRENDADDR_ENDADDR3_MASK)
/*! @} */

/* The count of NPX_MRENDADDR */
#define NPX_MRENDADDR_COUNT                      (4U)


/*!
 * @}
 */ /* end of group NPX_Register_Masks */


/*!
 * @}
 */ /* end of group NPX_Peripheral_Access_Layer */


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


#endif  /* PERI_NPX_H_ */

