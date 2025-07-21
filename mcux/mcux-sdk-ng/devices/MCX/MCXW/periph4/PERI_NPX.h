/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
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

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
#define NPX_NPX_REGION_KEY_DIR_COUNT              4u

/** NPX - Register Layout Typedef */
typedef struct {
  __IO uint32_t NPXCR;                             /**< NPX Control Register, offset: 0x0 */
  __I  uint32_t NPXSR;                             /**< NPX Status Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __O  uint32_t BMAPCTX[NPX_NPX_REGION_KEY_DIR_COUNT]; /**< Bitmap Control for Memory Context 0..Bitmap Control for Memory Context 3, array offset: 0x10, array step: 0x4 */
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

#define NPX_NPXCR_GEE_MASK                       (0x2U)
#define NPX_NPXCR_GEE_SHIFT                      (1U)
/*! GEE - Global Encryption Enable
 *  0b0..Global encryption disabled. NPX on-the-fly encryption is disabled. Subsequent reads return 0.
 *  0b1..Global encryption enabled. NPX on-the-fly encryption is enabled if the flash access hits in a valid
 *       memory region. Subsequent reads return 1.
 */
#define NPX_NPXCR_GEE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GEE_SHIFT)) & NPX_NPXCR_GEE_MASK)

#define NPX_NPXCR_GDE_MASK                       (0x20U)
#define NPX_NPXCR_GDE_SHIFT                      (5U)
/*! GDE - Global Decryption Enable
 *  0b0..Global decryption disabled. NPX on-the-fly decryption is globally disabled. Subsequent reads return 0.
 *  0b1..Global decryption enabled. NPX on-the-fly decryption is globally enabled. Subsequent reads return 1.
 */
#define NPX_NPXCR_GDE(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GDE_SHIFT)) & NPX_NPXCR_GDE_MASK)

#define NPX_NPXCR_SLK_MASK                       (0x200U)
#define NPX_NPXCR_SLK_SHIFT                      (9U)
/*! SLK - System Lock Enable
 *  0b0..System lock disabled. Subsequent reads return 0.
 *  0b1..System lock enabled: cannot write (via IPS) to keys, masks, regions, NPXCR (NPX Control Register), NPXSR
 *       (NPX Status Register). Subsequent reads return 1.
 */
#define NPX_NPXCR_SLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_SLK_SHIFT)) & NPX_NPXCR_SLK_MASK)

#define NPX_NPXCR_GLK_MASK                       (0x2000U)
#define NPX_NPXCR_GLK_SHIFT                      (13U)
/*! GLK - Global Lock Enable
 *  0b0..Global lock disabled. Subsequent reads return 0.
 *  0b1..Global lock enabled: cannot write to keys, masks, regions, NPXCR (NPX Control Register), NPXSR (NPX
 *       Status Register). Subsequent reads return 1.
 */
#define NPX_NPXCR_GLK(x)                         (((uint32_t)(((uint32_t)(x)) << NPX_NPXCR_GLK_SHIFT)) & NPX_NPXCR_GLK_MASK)
/*! @} */

/*! @name NPXSR - NPX Status Register */
/*! @{ */

#define NPX_NPXSR_NUMCTX_MASK                    (0xFU)
#define NPX_NPXSR_NUMCTX_SHIFT                   (0U)
/*! NUMCTX - Number of implemented memory contexts
 *  0b0000..No (zero) implemented memory contexts
 *  0b0001..1 implemented memory contexts
 *  0b0010..2 implemented memory contexts
 *  0b0011..3 implemented memory contexts
 *  0b0100..4 implemented memory contexts
 */
#define NPX_NPXSR_NUMCTX(x)                      (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_NUMCTX_SHIFT)) & NPX_NPXSR_NUMCTX_MASK)

#define NPX_NPXSR_V0_MASK                        (0x100U)
#define NPX_NPXSR_V0_SHIFT                       (8U)
/*! V0 - Key n Valid
 *  0b0..Key n is not valid
 *  0b1..Key n is valid
 */
#define NPX_NPXSR_V0(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V0_SHIFT)) & NPX_NPXSR_V0_MASK)

#define NPX_NPXSR_V1_MASK                        (0x200U)
#define NPX_NPXSR_V1_SHIFT                       (9U)
/*! V1 - Key n Valid
 *  0b0..Key n is not valid
 *  0b1..Key n is valid
 */
#define NPX_NPXSR_V1(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V1_SHIFT)) & NPX_NPXSR_V1_MASK)

#define NPX_NPXSR_V2_MASK                        (0x400U)
#define NPX_NPXSR_V2_SHIFT                       (10U)
/*! V2 - Key n Valid
 *  0b0..Key n is not valid
 *  0b1..Key n is valid
 */
#define NPX_NPXSR_V2(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V2_SHIFT)) & NPX_NPXSR_V2_MASK)

#define NPX_NPXSR_V3_MASK                        (0x800U)
#define NPX_NPXSR_V3_SHIFT                       (11U)
/*! V3 - Key n Valid
 *  0b0..Key n is not valid
 *  0b1..Key n is valid
 */
#define NPX_NPXSR_V3(x)                          (((uint32_t)(((uint32_t)(x)) << NPX_NPXSR_V3_SHIFT)) & NPX_NPXSR_V3_MASK)
/*! @} */

/*! @name NPX_REGION_KEY_DIR_BMAPCTX - Bitmap Control for Memory Context 0..Bitmap Control for Memory Context 3 */
/*! @{ */

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_MASK (0x1U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_SHIFT (0U)
/*! BEN0 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN0(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN0_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_MASK (0x2U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_SHIFT (1U)
/*! BEN1 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN1(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN1_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_MASK (0x4U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_SHIFT (2U)
/*! BEN2 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN2(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN2_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_MASK (0x8U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_SHIFT (3U)
/*! BEN3 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN3(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN3_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_MASK (0x10U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_SHIFT (4U)
/*! BEN4 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN4(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN4_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_MASK (0x20U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_SHIFT (5U)
/*! BEN5 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN5(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN5_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_MASK (0x40U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_SHIFT (6U)
/*! BEN6 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN6(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN6_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_MASK (0x80U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_SHIFT (7U)
/*! BEN7 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN7(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN7_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_MASK (0x100U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_SHIFT (8U)
/*! BEN8 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN8(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN8_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_MASK (0x200U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_SHIFT (9U)
/*! BEN9 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN9(x)   (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN9_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_MASK (0x400U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_SHIFT (10U)
/*! BEN10 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN10(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN10_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_MASK (0x800U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_SHIFT (11U)
/*! BEN11 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN11(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN11_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_MASK (0x1000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_SHIFT (12U)
/*! BEN12 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN12(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN12_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_MASK (0x2000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_SHIFT (13U)
/*! BEN13 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN13(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN13_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_MASK (0x4000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_SHIFT (14U)
/*! BEN14 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN14(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN14_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_MASK (0x8000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_SHIFT (15U)
/*! BEN15 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN15(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN15_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_MASK (0x10000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_SHIFT (16U)
/*! BEN16 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN16(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN16_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_MASK (0x20000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_SHIFT (17U)
/*! BEN17 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN17(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN17_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_MASK (0x40000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_SHIFT (18U)
/*! BEN18 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN18(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN18_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_MASK (0x80000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_SHIFT (19U)
/*! BEN19 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN19(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN19_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_MASK (0x100000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_SHIFT (20U)
/*! BEN20 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN20(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN20_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_MASK (0x200000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_SHIFT (21U)
/*! BEN21 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN21(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN21_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_MASK (0x400000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_SHIFT (22U)
/*! BEN22 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN22(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN22_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_MASK (0x800000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_SHIFT (23U)
/*! BEN23 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN23(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN23_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_MASK (0x1000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_SHIFT (24U)
/*! BEN24 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN24(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN24_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_MASK (0x2000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_SHIFT (25U)
/*! BEN25 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN25(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN25_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_MASK (0x4000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_SHIFT (26U)
/*! BEN26 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN26(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN26_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_MASK (0x8000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_SHIFT (27U)
/*! BEN27 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN27(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN27_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_MASK (0x10000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_SHIFT (28U)
/*! BEN28 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN28(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN28_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_MASK (0x20000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_SHIFT (29U)
/*! BEN29 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN29(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN29_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_MASK (0x40000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_SHIFT (30U)
/*! BEN30 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN30(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN30_MASK)

#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_MASK (0x80000000U)
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_SHIFT (31U)
/*! BEN31 - Block enable for encryption/decryption
 *  0b0..Disable encryption/decryption
 *  0b1..Enable encryption/decryption
 */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN31(x)  (((uint32_t)(((uint32_t)(x)) << NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_SHIFT)) & NPX_NPX_REGION_KEY_DIR_BMAPCTX_BEN31_MASK)
/*! @} */

/* The count of NPX_NPX_REGION_KEY_DIR_BMAPCTX */
#define NPX_NPX_REGION_KEY_DIR_BMAPCTX_COUNT     (4U)


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

