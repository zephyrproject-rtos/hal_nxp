/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC
 *
 * CMSIS Peripheral Access Layer for GPC
 */

#if !defined(PERI_GPC_H_)
#define PERI_GPC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- GPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Peripheral_Access_Layer GPC Peripheral Access Layer
 * @{
 */

/** GPC - Size of Registers Arrays */
#define GPC_IMR_CORE0_A53_COUNT                   4u
#define GPC_IMR_CORE1_A53_COUNT                   4u
#define GPC_IMR_M7_COUNT                          4u
#define GPC_ISR_A53_COUNT                         4u
#define GPC_ISR_M7_COUNT                          4u
#define GPC_A53_MIX_PGC_PUP_STATUS_COUNT          3u
#define GPC_M7_MIX_PGC_PUP_STATUS_COUNT           3u
#define GPC_A53_PU_PGC_PUP_STATUS_COUNT           3u
#define GPC_M7_PU_PGC_PUP_STATUS_COUNT            3u
#define GPC_A53_MIX_PGC_PDN_STATUS_COUNT          3u
#define GPC_M7_MIX_PGC_PDN_STATUS_COUNT           3u
#define GPC_A53_PU_PGC_PDN_STATUS_COUNT           3u
#define GPC_M7_PU_PGC_PDN_STATUS_COUNT            3u
#define GPC_IMR_CORE2_A53_COUNT                   4u
#define GPC_IMR_CORE3_A53_COUNT                   4u
#define GPC_SLT_CFG_PU_COUNT                      20u

/** GPC - Register Layout Typedef */
typedef struct {
  __IO uint32_t LPCR_A53_BSC;                      /**< Basic Low power control register of A53 platform, offset: 0x0 */
  __IO uint32_t LPCR_A53_AD;                       /**< Advanced Low power control register of A53 platform, offset: 0x4 */
  __IO uint32_t LPCR_M7;                           /**< Low power control register of CPU1, offset: 0x8 */
       uint8_t RESERVED_0[8];
  __IO uint32_t SLPCR;                             /**< System low power control register, offset: 0x14 */
  __IO uint32_t MST_CPU_MAPPING;                   /**< MASTER LPM Handshake, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MLPCR;                             /**< Memory low power control register, offset: 0x20 */
  __IO uint32_t PGC_ACK_SEL_A53;                   /**< PGC acknowledge signal selection of A53 platform, offset: 0x24 */
  __IO uint32_t PGC_ACK_SEL_M7;                    /**< PGC acknowledge signal selection of M7 platform, offset: 0x28 */
  __IO uint32_t MISC;                              /**< GPC Miscellaneous register, offset: 0x2C */
  __IO uint32_t IMR_CORE0_A53[GPC_IMR_CORE0_A53_COUNT]; /**< IRQ masking register 1 of A53 core0..IRQ masking register 4 of A53 core0, array offset: 0x30, array step: 0x4 */
  __IO uint32_t IMR_CORE1_A53[GPC_IMR_CORE1_A53_COUNT]; /**< IRQ masking register 1 of A53 core1..IRQ masking register 4 of A53 core1, array offset: 0x40, array step: 0x4 */
  __IO uint32_t IMR_M7[GPC_IMR_M7_COUNT];          /**< IRQ masking register 1 of M7..IRQ masking register 4 of M7, array offset: 0x50, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __I  uint32_t ISR_A53[GPC_ISR_A53_COUNT];        /**< IRQ status register 1 of A53..IRQ status register 4 of A53, array offset: 0x70, array step: 0x4 */
  __I  uint32_t ISR_M7[GPC_ISR_M7_COUNT];          /**< IRQ status register 1 of M7..IRQ status register 4 of M7, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_3[32];
  __IO uint32_t SLT0_CFG;                          /**< Slot configure register for CPUs, offset: 0xB0 */
  __IO uint32_t SLT1_CFG;                          /**< Slot configure register for CPUs, offset: 0xB4 */
  __IO uint32_t SLT2_CFG;                          /**< Slot configure register for CPUs, offset: 0xB8 */
  __IO uint32_t SLT3_CFG;                          /**< Slot configure register for CPUs, offset: 0xBC */
  __IO uint32_t SLT4_CFG;                          /**< Slot configure register for CPUs, offset: 0xC0 */
  __IO uint32_t SLT5_CFG;                          /**< Slot configure register for CPUs, offset: 0xC4 */
  __IO uint32_t SLT6_CFG;                          /**< Slot configure register for CPUs, offset: 0xC8 */
  __IO uint32_t SLT7_CFG;                          /**< Slot configure register for CPUs, offset: 0xCC */
  __IO uint32_t SLT8_CFG;                          /**< Slot configure register for CPUs, offset: 0xD0 */
  __IO uint32_t SLT9_CFG;                          /**< Slot configure register for CPUs, offset: 0xD4 */
  __IO uint32_t SLT10_CFG;                         /**< Slot configure register for CPUs, offset: 0xD8 */
  __IO uint32_t SLT11_CFG;                         /**< Slot configure register for CPUs, offset: 0xDC */
  __IO uint32_t SLT12_CFG;                         /**< Slot configure register for CPUs, offset: 0xE0 */
  __IO uint32_t SLT13_CFG;                         /**< Slot configure register for CPUs, offset: 0xE4 */
  __IO uint32_t SLT14_CFG;                         /**< Slot configure register for CPUs, offset: 0xE8 */
  __IO uint32_t PGC_CPU_0_1_MAPPING;               /**< PGC CPU mapping, offset: 0xEC */
  __IO uint32_t CPU_PGC_SW_PUP_REQ;                /**< CPU PGC software power up trigger, offset: 0xF0 */
  __IO uint32_t MIX_PGC_SW_PUP_REQ;                /**< MIX PGC software power up trigger, offset: 0xF4 */
  __IO uint32_t PU_PGC_SW_PUP_REQ;                 /**< PU PGC software up trigger, offset: 0xF8 */
  __IO uint32_t CPU_PGC_SW_PDN_REQ;                /**< CPU PGC software down trigger, offset: 0xFC */
  __IO uint32_t MIX_PGC_SW_PDN_REQ;                /**< MIX PGC software power down trigger, offset: 0x100 */
  __IO uint32_t PU_PGC_SW_PDN_REQ;                 /**< PU PGC software down trigger, offset: 0x104 */
  __IO uint32_t LPCR_A53_BSC2;                     /**< Basic Low power control register of A53 platform, offset: 0x108 */
       uint8_t RESERVED_4[36];
  __I  uint32_t CPU_PGC_PUP_STATUS1;               /**< CPU PGC software up trigger status1, offset: 0x130 */
  __I  uint32_t A53_MIX_PGC_PUP_STATUS[GPC_A53_MIX_PGC_PUP_STATUS_COUNT]; /**< A53 MIX software up trigger status register, array offset: 0x134, array step: 0x4 */
  __I  uint32_t M7_MIX_PGC_PUP_STATUS[GPC_M7_MIX_PGC_PUP_STATUS_COUNT]; /**< M7 MIX PGC software up trigger status register, array offset: 0x140, array step: 0x4 */
  __I  uint32_t A53_PU_PGC_PUP_STATUS[GPC_A53_PU_PGC_PUP_STATUS_COUNT]; /**< A53 PU software up trigger status register, array offset: 0x14C, array step: 0x4 */
  __I  uint32_t M7_PU_PGC_PUP_STATUS[GPC_M7_PU_PGC_PUP_STATUS_COUNT]; /**< M7 PU PGC software up trigger status register, array offset: 0x158, array step: 0x4 */
       uint8_t RESERVED_5[12];
  __I  uint32_t CPU_PGC_PDN_STATUS1;               /**< CPU PGC software dn trigger status1, offset: 0x170 */
  __I  uint32_t A53_MIX_PGC_PDN_STATUS[GPC_A53_MIX_PGC_PDN_STATUS_COUNT]; /**< A53 MIX software down trigger status register, array offset: 0x174, array step: 0x4 */
  __I  uint32_t M7_MIX_PGC_PDN_STATUS[GPC_M7_MIX_PGC_PDN_STATUS_COUNT]; /**< M7 MIX PGC software power down trigger status register, array offset: 0x180, array step: 0x4 */
  __I  uint32_t A53_PU_PGC_PDN_STATUS[GPC_A53_PU_PGC_PDN_STATUS_COUNT]; /**< A53 PU PGC software down trigger status, array offset: 0x18C, array step: 0x4 */
  __I  uint32_t M7_PU_PGC_PDN_STATUS[GPC_M7_PU_PGC_PDN_STATUS_COUNT]; /**< M7 PU PGC software down trigger status, array offset: 0x198, array step: 0x4 */
       uint8_t RESERVED_6[12];
  __IO uint32_t A53_MIX_PDN_FLG;                   /**< A53 MIX PDN FLG, offset: 0x1B0 */
  __IO uint32_t A53_PU_PDN_FLG;                    /**< A53 PU PDN FLG, offset: 0x1B4 */
  __IO uint32_t M7_MIX_PDN_FLG;                    /**< M7 MIX PDN FLG, offset: 0x1B8 */
  __IO uint32_t M7_PU_PDN_FLG;                     /**< M7 PU PDN FLG, offset: 0x1BC */
  __IO uint32_t IMR_CORE2_A53[GPC_IMR_CORE2_A53_COUNT]; /**< IRQ masking register 1 of A53 core2..IRQ masking register 4 of A53 core2, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t IMR_CORE3_A53[GPC_IMR_CORE3_A53_COUNT]; /**< IRQ masking register 1 of A53 core3..IRQ masking register 4 of A53 core3, array offset: 0x1D0, array step: 0x4 */
  __IO uint32_t ACK_SEL_A53_PU;                    /**< PGC acknowledge signal selection of A53 platform for PUs, offset: 0x1E0 */
  __IO uint32_t ACK_SEL_M7_PU;                     /**< PGC acknowledge signal selection of M7 platform for PUs, offset: 0x1E4 */
  __IO uint32_t SLT15_CFG;                         /**< Slot configure register for PGC CPUs, offset: 0x1E8 */
  __IO uint32_t SLT16_CFG;                         /**< Slot configure register for PGC CPUs, offset: 0x1EC */
  __IO uint32_t SLT17_CFG;                         /**< Slot configure register for PGC CPUs, offset: 0x1F0 */
  __IO uint32_t SLT18_CFG;                         /**< Slot configure register for PGC CPUs, offset: 0x1F4 */
  __IO uint32_t SLT19_CFG;                         /**< Slot configure register for PGC CPUs, offset: 0x1F8 */
  __IO uint32_t PU_PWRHSK;                         /**< Power handshake register, offset: 0x1FC */
  __IO uint32_t SLT_CFG_PU[GPC_SLT_CFG_PU_COUNT];  /**< Slot configure register for PGC PUs, array offset: 0x200, array step: 0x4 */
} GPC_Type;

/* ----------------------------------------------------------------------------
   -- GPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Register_Masks GPC Register Masks
 * @{
 */

/*! @name LPCR_A53_BSC - Basic Low power control register of A53 platform */
/*! @{ */

#define GPC_LPCR_A53_BSC_LPM0_MASK               (0x3U)
#define GPC_LPCR_A53_BSC_LPM0_SHIFT              (0U)
/*! LPM0
 *  0b00..Remain in RUN mode
 *  0b01..Transfer to WAIT mode
 *  0b10..Transfer to STOP mode
 *  0b11..Reserved
 */
#define GPC_LPCR_A53_BSC_LPM0(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_LPM0_SHIFT)) & GPC_LPCR_A53_BSC_LPM0_MASK)

#define GPC_LPCR_A53_BSC_LPM1_MASK               (0xCU)
#define GPC_LPCR_A53_BSC_LPM1_SHIFT              (2U)
/*! LPM1
 *  0b00..Remain in RUN mode
 *  0b01..Transfer to WAIT mode
 *  0b10..Transfer to STOP mode
 *  0b11..Reserved
 */
#define GPC_LPCR_A53_BSC_LPM1(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_LPM1_SHIFT)) & GPC_LPCR_A53_BSC_LPM1_MASK)

#define GPC_LPCR_A53_BSC_MST0_LPM_HSK_MASK_MASK  (0x40U)
#define GPC_LPCR_A53_BSC_MST0_LPM_HSK_MASK_SHIFT (6U)
/*! MST0_LPM_HSK_MASK - MASTER0 LPM handshake mask
 *  0b0..enable MASTER0 LPM handshake, wait ACK from MASTER0
 *  0b1..disable MASTER0 LPM handshake, mask ACK from MASTER0
 */
#define GPC_LPCR_A53_BSC_MST0_LPM_HSK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MST0_LPM_HSK_MASK_SHIFT)) & GPC_LPCR_A53_BSC_MST0_LPM_HSK_MASK_MASK)

#define GPC_LPCR_A53_BSC_MST1_LPM_HSK_MASK_MASK  (0x80U)
#define GPC_LPCR_A53_BSC_MST1_LPM_HSK_MASK_SHIFT (7U)
/*! MST1_LPM_HSK_MASK - MASTER1 LPM handshake mask
 *  0b0..enable MASTER1 LPM handshake, wait ACK from MASTER1
 *  0b1..disable MASTER1 LPM handshake, mask ACK from MASTER1
 */
#define GPC_LPCR_A53_BSC_MST1_LPM_HSK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MST1_LPM_HSK_MASK_SHIFT)) & GPC_LPCR_A53_BSC_MST1_LPM_HSK_MASK_MASK)

#define GPC_LPCR_A53_BSC_MST2_LPM_HSK_MASK_MASK  (0x100U)
#define GPC_LPCR_A53_BSC_MST2_LPM_HSK_MASK_SHIFT (8U)
/*! MST2_LPM_HSK_MASK - MASTER2 LPM handshake mask
 *  0b0..enable MASTER2 LPM handshake, wait ACK from MASTER2
 *  0b1..disable MASTER2 LPM handshake, mask ACK from MASTER2
 */
#define GPC_LPCR_A53_BSC_MST2_LPM_HSK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MST2_LPM_HSK_MASK_SHIFT)) & GPC_LPCR_A53_BSC_MST2_LPM_HSK_MASK_MASK)

#define GPC_LPCR_A53_BSC_MST3_LPM_HSK_MASK_MASK  (0x200U)
#define GPC_LPCR_A53_BSC_MST3_LPM_HSK_MASK_SHIFT (9U)
/*! MST3_LPM_HSK_MASK - MASTER3 LPM handshake mask
 *  0b0..enable MASTER3 LPM handshake, wait ACK from MASTER3
 *  0b1..disable MASTER3 LPM handshake, mask ACK from MASTER3
 */
#define GPC_LPCR_A53_BSC_MST3_LPM_HSK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MST3_LPM_HSK_MASK_SHIFT)) & GPC_LPCR_A53_BSC_MST3_LPM_HSK_MASK_MASK)

#define GPC_LPCR_A53_BSC_MST4_LPM_HSK_MASK_MASK  (0x400U)
#define GPC_LPCR_A53_BSC_MST4_LPM_HSK_MASK_SHIFT (10U)
/*! MST4_LPM_HSK_MASK - MASTER4 LPM handshake mask
 *  0b0..enable MASTER4 LPM handshake, wait ACK from MASTER4
 *  0b1..disable MASTER4 LPM handshake, mask ACK from MASTER4
 */
#define GPC_LPCR_A53_BSC_MST4_LPM_HSK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MST4_LPM_HSK_MASK_SHIFT)) & GPC_LPCR_A53_BSC_MST4_LPM_HSK_MASK_MASK)

#define GPC_LPCR_A53_BSC_CPU_CLK_ON_LPM_MASK     (0x4000U)
#define GPC_LPCR_A53_BSC_CPU_CLK_ON_LPM_SHIFT    (14U)
/*! CPU_CLK_ON_LPM
 *  0b0..A53 clock disabled on wait/stop mode
 *  0b1..A53 clock enabled on wait/stop mode
 */
#define GPC_LPCR_A53_BSC_CPU_CLK_ON_LPM(x)       (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_CPU_CLK_ON_LPM_SHIFT)) & GPC_LPCR_A53_BSC_CPU_CLK_ON_LPM_MASK)

#define GPC_LPCR_A53_BSC_MASK_CORE0_WFI_MASK     (0x10000U)
#define GPC_LPCR_A53_BSC_MASK_CORE0_WFI_SHIFT    (16U)
/*! MASK_CORE0_WFI
 *  0b0..WFI for CORE0 is not masked
 *  0b1..WFI for CORE0 is masked
 */
#define GPC_LPCR_A53_BSC_MASK_CORE0_WFI(x)       (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_CORE0_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_CORE0_WFI_MASK)

#define GPC_LPCR_A53_BSC_MASK_CORE1_WFI_MASK     (0x20000U)
#define GPC_LPCR_A53_BSC_MASK_CORE1_WFI_SHIFT    (17U)
/*! MASK_CORE1_WFI
 *  0b0..WFI for CORE1 is not masked
 *  0b1..WFI for CORE1 is masked
 */
#define GPC_LPCR_A53_BSC_MASK_CORE1_WFI(x)       (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_CORE1_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_CORE1_WFI_MASK)

#define GPC_LPCR_A53_BSC_MASK_CORE2_WFI_MASK     (0x40000U)
#define GPC_LPCR_A53_BSC_MASK_CORE2_WFI_SHIFT    (18U)
/*! MASK_CORE2_WFI
 *  0b0..WFI for CORE2 is not masked
 *  0b1..WFI for CORE2 is masked
 */
#define GPC_LPCR_A53_BSC_MASK_CORE2_WFI(x)       (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_CORE2_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_CORE2_WFI_MASK)

#define GPC_LPCR_A53_BSC_MASK_CORE3_WFI_MASK     (0x80000U)
#define GPC_LPCR_A53_BSC_MASK_CORE3_WFI_SHIFT    (19U)
/*! MASK_CORE3_WFI
 *  0b0..WFI for CORE3 is not masked
 *  0b1..WFI for CORE3 is masked
 */
#define GPC_LPCR_A53_BSC_MASK_CORE3_WFI(x)       (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_CORE3_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_CORE3_WFI_MASK)

#define GPC_LPCR_A53_BSC_IRQ_SRC_C2_MASK         (0x400000U)
#define GPC_LPCR_A53_BSC_IRQ_SRC_C2_SHIFT        (22U)
/*! IRQ_SRC_C2
 *  0b0..core2 wakeup source from external INT[127:0], masked by IMR1. See Power Up Process for A53 Platform for more specific information.
 *  0b1..core2 wakeup source from external GIC(nFIQ[1]/nIRQ[1]), SCU should not be powered down during low power mode when this bit is set to 1'b1.
 */
#define GPC_LPCR_A53_BSC_IRQ_SRC_C2(x)           (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_IRQ_SRC_C2_SHIFT)) & GPC_LPCR_A53_BSC_IRQ_SRC_C2_MASK)

#define GPC_LPCR_A53_BSC_IRQ_SRC_C3_MASK         (0x800000U)
#define GPC_LPCR_A53_BSC_IRQ_SRC_C3_SHIFT        (23U)
/*! IRQ_SRC_C3
 *  0b0..core3 wakeup source from external INT[127:0], masked by IMR1. See Power Up Process for A53 Platform for more specific information.
 *  0b1..core3 wakeup source from external GIC(nFIQ[1]/nIRQ[1]), SCU should not be powered down during low power mode when this bit is set to 1'b1.
 */
#define GPC_LPCR_A53_BSC_IRQ_SRC_C3(x)           (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_IRQ_SRC_C3_SHIFT)) & GPC_LPCR_A53_BSC_IRQ_SRC_C3_MASK)

#define GPC_LPCR_A53_BSC_MASK_SCU_WFI_MASK       (0x1000000U)
#define GPC_LPCR_A53_BSC_MASK_SCU_WFI_SHIFT      (24U)
/*! MASK_SCU_WFI
 *  0b0..WFI for SCU is not masked
 *  0b1..WFI for SCU is masked
 */
#define GPC_LPCR_A53_BSC_MASK_SCU_WFI(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_SCU_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_SCU_WFI_MASK)

#define GPC_LPCR_A53_BSC_MASK_L2CC_WFI_MASK      (0x4000000U)
#define GPC_LPCR_A53_BSC_MASK_L2CC_WFI_SHIFT     (26U)
/*! MASK_L2CC_WFI
 *  0b0..WFI for L2 cache controller is not masked
 *  0b1..WFI for L2 cache controller is masked
 */
#define GPC_LPCR_A53_BSC_MASK_L2CC_WFI(x)        (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_L2CC_WFI_SHIFT)) & GPC_LPCR_A53_BSC_MASK_L2CC_WFI_MASK)

#define GPC_LPCR_A53_BSC_IRQ_SRC_C0_MASK         (0x10000000U)
#define GPC_LPCR_A53_BSC_IRQ_SRC_C0_SHIFT        (28U)
/*! IRQ_SRC_C0
 *  0b0..core0 wakeup source from external INT[127:0], masked by IMR0 refer to "Power up process for A53 platform" for more specific information
 *  0b1..core0 wakeup source from GIC(nFIQ[0]/nIRQ[0] ), SCU should not be power down during low power mode when this bit is set to 1'b1
 */
#define GPC_LPCR_A53_BSC_IRQ_SRC_C0(x)           (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_IRQ_SRC_C0_SHIFT)) & GPC_LPCR_A53_BSC_IRQ_SRC_C0_MASK)

#define GPC_LPCR_A53_BSC_IRQ_SRC_C1_MASK         (0x20000000U)
#define GPC_LPCR_A53_BSC_IRQ_SRC_C1_SHIFT        (29U)
/*! IRQ_SRC_C1
 *  0b0..core1 wakeup source from external INT[127:0], masked by IMR1 refer to "Power up process for A53 platform" for more specific information
 *  0b1..core1 wakeup source from GIC(nFIQ[1]/nIRQ[1] ), SCU should not be power down during low power mode when this bit is set to 1'b1
 */
#define GPC_LPCR_A53_BSC_IRQ_SRC_C1(x)           (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_IRQ_SRC_C1_SHIFT)) & GPC_LPCR_A53_BSC_IRQ_SRC_C1_MASK)

#define GPC_LPCR_A53_BSC_IRQ_SRC_A53_WUP_MASK    (0x40000000U)
#define GPC_LPCR_A53_BSC_IRQ_SRC_A53_WUP_SHIFT   (30U)
/*! IRQ_SRC_A53_WUP
 *  0b0..LPM wakeup source be "OR" result of
 *       LPCR_A53_BSC[IRQ_SRC_C0]/LPCR_A53_BSC[IRQ_SRC_C1]/LPCR_A53_BSC[IRQ_SRC_C2]/LPCR_A53_BSC[IRQ_SRC_C3] setting
 *  0b1..LPM wakeup source from external INT[127:0], masked by IMR0
 */
#define GPC_LPCR_A53_BSC_IRQ_SRC_A53_WUP(x)      (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_IRQ_SRC_A53_WUP_SHIFT)) & GPC_LPCR_A53_BSC_IRQ_SRC_A53_WUP_MASK)

#define GPC_LPCR_A53_BSC_MASK_DSM_TRIGGER_MASK   (0x80000000U)
#define GPC_LPCR_A53_BSC_MASK_DSM_TRIGGER_SHIFT  (31U)
/*! MASK_DSM_TRIGGER
 *  0b0..DSM trigger of A53 platform will not be masked
 *  0b1..DSM trigger of A53 platform will be masked
 */
#define GPC_LPCR_A53_BSC_MASK_DSM_TRIGGER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC_MASK_DSM_TRIGGER_SHIFT)) & GPC_LPCR_A53_BSC_MASK_DSM_TRIGGER_MASK)
/*! @} */

/*! @name LPCR_A53_AD - Advanced Low power control register of A53 platform */
/*! @{ */

#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN_MASK       (0x1U)
#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN_SHIFT      (0U)
/*! EN_C0_WFI_PDN
 *  0b0..CORE0 will not be power down with WFI request
 *  0b1..CORE0 will be power down with WFI request
 */
#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C0_WFI_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C0_WFI_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C0_PDN_MASK           (0x2U)
#define GPC_LPCR_A53_AD_EN_C0_PDN_SHIFT          (1U)
/*! EN_C0_PDN
 *  0b0..CORE0 will not be power down with low power mode request
 *  0b1..CORE0 will be power down with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C0_PDN(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C0_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C0_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN_MASK       (0x4U)
#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN_SHIFT      (2U)
/*! EN_C1_WFI_PDN
 *  0b0..CORE1 will not be power down with WFI request
 *  0b1..CORE1 will be power down with WFI request
 */
#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C1_WFI_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C1_WFI_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C1_PDN_MASK           (0x8U)
#define GPC_LPCR_A53_AD_EN_C1_PDN_SHIFT          (3U)
/*! EN_C1_PDN
 *  0b0..CORE1 will not be power down with low power mode request
 *  0b1..CORE1 will be power down with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C1_PDN(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C1_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C1_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_PLAT_PDN_MASK         (0x10U)
#define GPC_LPCR_A53_AD_EN_PLAT_PDN_SHIFT        (4U)
/*! EN_PLAT_PDN
 *  0b0..SCU and L2 cache RAM will not be power down with low power mode request
 *  0b1..SCU and L2 cache RAM will be power down with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_PLAT_PDN(x)           (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_PLAT_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_PLAT_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_L2_WFI_PDN_MASK       (0x20U)
#define GPC_LPCR_A53_AD_EN_L2_WFI_PDN_SHIFT      (5U)
/*! EN_L2_WFI_PDN
 *  0b0..SCU and L2 will not be power down with WFI request
 *  0b1..SCU and L2 will be power down with WFI request (default)
 */
#define GPC_LPCR_A53_AD_EN_L2_WFI_PDN(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_L2_WFI_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_L2_WFI_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C0_IRQ_PUP_MASK       (0x100U)
#define GPC_LPCR_A53_AD_EN_C0_IRQ_PUP_SHIFT      (8U)
/*! EN_C0_IRQ_PUP
 *  0b0..CORE0 will not power up with IRQ request
 *  0b1..CORE0 will power up with IRQ request
 */
#define GPC_LPCR_A53_AD_EN_C0_IRQ_PUP(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C0_IRQ_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C0_IRQ_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C0_PUP_MASK           (0x200U)
#define GPC_LPCR_A53_AD_EN_C0_PUP_SHIFT          (9U)
/*! EN_C0_PUP
 *  0b0..CORE0 will not power up with low power mode request
 *  0b1..CORE0 will power up with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C0_PUP(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C0_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C0_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C1_IRQ_PUP_MASK       (0x400U)
#define GPC_LPCR_A53_AD_EN_C1_IRQ_PUP_SHIFT      (10U)
/*! EN_C1_IRQ_PUP
 *  0b0..CORE1 will not power up with IRQ request
 *  0b1..CORE1 will power up with IRQ request
 */
#define GPC_LPCR_A53_AD_EN_C1_IRQ_PUP(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C1_IRQ_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C1_IRQ_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C1_PUP_MASK           (0x800U)
#define GPC_LPCR_A53_AD_EN_C1_PUP_SHIFT          (11U)
/*! EN_C1_PUP
 *  0b0..CORE1 will not power up with low power mode request (only used wake up from CPU01_OFF mode)
 *  0b1..CORE1 will power up with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C1_PUP(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C1_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C1_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN_MASK       (0x10000U)
#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN_SHIFT      (16U)
/*! EN_C2_WFI_PDN
 *  0b0..CORE2 will not be power down with WFI request
 *  0b1..CORE2 will be power down with WFI request
 */
#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C2_WFI_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C2_WFI_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C2_PDN_MASK           (0x20000U)
#define GPC_LPCR_A53_AD_EN_C2_PDN_SHIFT          (17U)
/*! EN_C2_PDN
 *  0b0..CORE2 will not be power down with low power mode request
 *  0b1..CORE2 will be power down with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C2_PDN(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C2_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C2_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN_MASK       (0x40000U)
#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN_SHIFT      (18U)
/*! EN_C3_WFI_PDN
 *  0b0..CORE3 will not be power down with WFI request
 *  0b1..CORE3 will be power down with WFI request
 */
#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C3_WFI_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C3_WFI_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C3_PDN_MASK           (0x80000U)
#define GPC_LPCR_A53_AD_EN_C3_PDN_SHIFT          (19U)
/*! EN_C3_PDN
 *  0b0..CORE3 will not be power down with low power mode request
 *  0b1..CORE3 will be power down with low power mode request
 */
#define GPC_LPCR_A53_AD_EN_C3_PDN(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C3_PDN_SHIFT)) & GPC_LPCR_A53_AD_EN_C3_PDN_MASK)

#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN_DIS_MASK   (0x100000U)
#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN_DIS_SHIFT  (20U)
/*! EN_C0_WFI_PDN_DIS
 *  0b0..Disable WIFI power down core0
 *  0b1..Enable WIFI power down core0
 */
#define GPC_LPCR_A53_AD_EN_C0_WFI_PDN_DIS(x)     (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C0_WFI_PDN_DIS_SHIFT)) & GPC_LPCR_A53_AD_EN_C0_WFI_PDN_DIS_MASK)

#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN_DIS_MASK   (0x200000U)
#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN_DIS_SHIFT  (21U)
/*! EN_C1_WFI_PDN_DIS
 *  0b0..Disable WIFI power down core1
 *  0b1..Enable WIFI power down core1
 */
#define GPC_LPCR_A53_AD_EN_C1_WFI_PDN_DIS(x)     (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C1_WFI_PDN_DIS_SHIFT)) & GPC_LPCR_A53_AD_EN_C1_WFI_PDN_DIS_MASK)

#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN_DIS_MASK   (0x400000U)
#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN_DIS_SHIFT  (22U)
/*! EN_C2_WFI_PDN_DIS
 *  0b0..Disable WIFI power down core2
 *  0b1..Enable WIFI power down core2
 */
#define GPC_LPCR_A53_AD_EN_C2_WFI_PDN_DIS(x)     (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C2_WFI_PDN_DIS_SHIFT)) & GPC_LPCR_A53_AD_EN_C2_WFI_PDN_DIS_MASK)

#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN_DIS_MASK   (0x800000U)
#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN_DIS_SHIFT  (23U)
/*! EN_C3_WFI_PDN_DIS
 *  0b0..Disable WFI power down core3
 *  0b1..Enable WFI power down core3
 */
#define GPC_LPCR_A53_AD_EN_C3_WFI_PDN_DIS(x)     (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C3_WFI_PDN_DIS_SHIFT)) & GPC_LPCR_A53_AD_EN_C3_WFI_PDN_DIS_MASK)

#define GPC_LPCR_A53_AD_EN_C2_IRQ_PUP_MASK       (0x1000000U)
#define GPC_LPCR_A53_AD_EN_C2_IRQ_PUP_SHIFT      (24U)
/*! EN_C2_IRQ_PUP
 *  0b0..CORE2 will not power up with IRQ request
 *  0b1..CORE2 will power up with IRQ request
 */
#define GPC_LPCR_A53_AD_EN_C2_IRQ_PUP(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C2_IRQ_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C2_IRQ_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C2_PUP_MASK           (0x2000000U)
#define GPC_LPCR_A53_AD_EN_C2_PUP_SHIFT          (25U)
/*! EN_C2_PUP
 *  0b0..CORE2 will not power up with lower power mode request
 *  0b1..CORE2 will power up with low power mode request (only used wake up from CPU_OFF)
 */
#define GPC_LPCR_A53_AD_EN_C2_PUP(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C2_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C2_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C3_IRQ_PUP_MASK       (0x4000000U)
#define GPC_LPCR_A53_AD_EN_C3_IRQ_PUP_SHIFT      (26U)
/*! EN_C3_IRQ_PUP
 *  0b0..CORE3 will not power up with IRQ request
 *  0b1..CORE3 will power up with IRQ request
 */
#define GPC_LPCR_A53_AD_EN_C3_IRQ_PUP(x)         (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C3_IRQ_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C3_IRQ_PUP_MASK)

#define GPC_LPCR_A53_AD_EN_C3_PUP_MASK           (0x8000000U)
#define GPC_LPCR_A53_AD_EN_C3_PUP_SHIFT          (27U)
/*! EN_C3_PUP
 *  0b0..CORE3 will not power up with lower power mode request
 *  0b1..CORE3 will power up with low power mode request (only used wake up from CPU_OFF)
 */
#define GPC_LPCR_A53_AD_EN_C3_PUP(x)             (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_EN_C3_PUP_SHIFT)) & GPC_LPCR_A53_AD_EN_C3_PUP_MASK)

#define GPC_LPCR_A53_AD_L2PGE_MASK               (0x80000000U)
#define GPC_LPCR_A53_AD_L2PGE_SHIFT              (31U)
/*! L2PGE
 *  0b0..L2 cache RAM will power down with SCU power domain in A53 platform (used for ALL_OFF mode)
 *  0b1..L2 cache RAM will not power down with SCU power domain in A53 platform (used for ALL_OFF mode)
 */
#define GPC_LPCR_A53_AD_L2PGE(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_AD_L2PGE_SHIFT)) & GPC_LPCR_A53_AD_L2PGE_MASK)
/*! @} */

/*! @name LPCR_M7 - Low power control register of CPU1 */
/*! @{ */

#define GPC_LPCR_M7_LPM0_MASK                    (0x3U)
#define GPC_LPCR_M7_LPM0_SHIFT                   (0U)
/*! LPM0
 *  0b00..Remain in RUN mode
 *  0b01..Transfer to WAIT mode
 *  0b10..Transfer to STOP mode
 *  0b11..Reserved
 */
#define GPC_LPCR_M7_LPM0(x)                      (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_LPM0_SHIFT)) & GPC_LPCR_M7_LPM0_MASK)

#define GPC_LPCR_M7_EN_M7_PDN_MASK               (0x4U)
#define GPC_LPCR_M7_EN_M7_PDN_SHIFT              (2U)
#define GPC_LPCR_M7_EN_M7_PDN(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_EN_M7_PDN_SHIFT)) & GPC_LPCR_M7_EN_M7_PDN_MASK)

#define GPC_LPCR_M7_EN_M7_PUP_MASK               (0x8U)
#define GPC_LPCR_M7_EN_M7_PUP_SHIFT              (3U)
#define GPC_LPCR_M7_EN_M7_PUP(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_EN_M7_PUP_SHIFT)) & GPC_LPCR_M7_EN_M7_PUP_MASK)

#define GPC_LPCR_M7_CPU_CLK_ON_LPM_MASK          (0x4000U)
#define GPC_LPCR_M7_CPU_CLK_ON_LPM_SHIFT         (14U)
/*! CPU_CLK_ON_LPM
 *  0b0..M7 clock disabled on wait/stop mode.
 *  0b1..M7 clock enabled on wait/stop mode.
 */
#define GPC_LPCR_M7_CPU_CLK_ON_LPM(x)            (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_CPU_CLK_ON_LPM_SHIFT)) & GPC_LPCR_M7_CPU_CLK_ON_LPM_MASK)

#define GPC_LPCR_M7_MASK_M7_WFI_MASK             (0x10000U)
#define GPC_LPCR_M7_MASK_M7_WFI_SHIFT            (16U)
/*! MASK_M7_WFI
 *  0b0..WFI for M7 is not masked
 *  0b1..WFI for M7 is masked
 */
#define GPC_LPCR_M7_MASK_M7_WFI(x)               (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_MASK_M7_WFI_SHIFT)) & GPC_LPCR_M7_MASK_M7_WFI_MASK)

#define GPC_LPCR_M7_MASK_DSM_TRIGGER_MASK        (0x80000000U)
#define GPC_LPCR_M7_MASK_DSM_TRIGGER_SHIFT       (31U)
/*! MASK_DSM_TRIGGER
 *  0b0..DSM trigger of M7 platform will not be masked
 *  0b1..DSM trigger of M7 platform will be masked
 */
#define GPC_LPCR_M7_MASK_DSM_TRIGGER(x)          (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_M7_MASK_DSM_TRIGGER_SHIFT)) & GPC_LPCR_M7_MASK_DSM_TRIGGER_MASK)
/*! @} */

/*! @name SLPCR - System low power control register */
/*! @{ */

#define GPC_SLPCR_BYPASS_PMIC_READY_MASK         (0x1U)
#define GPC_SLPCR_BYPASS_PMIC_READY_SHIFT        (0U)
/*! BYPASS_PMIC_READY
 *  0b0..Don't bypass the PMIC_READY signal - GPC will wait for its assertion during exit of low power mode if standby voltage was enabled
 *  0b1..Bypass the PMIC_READY signal - GPC will not wait for its assertion during exit of low power mode if standby voltage was enabled
 */
#define GPC_SLPCR_BYPASS_PMIC_READY(x)           (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_BYPASS_PMIC_READY_SHIFT)) & GPC_SLPCR_BYPASS_PMIC_READY_MASK)

#define GPC_SLPCR_SBYOS_MASK                     (0x2U)
#define GPC_SLPCR_SBYOS_SHIFT                    (1U)
/*! SBYOS
 *  0b0..On chip oscillator will not be powered down, after next entrance to DSM.
 *  0b1..On chip oscillator will be powered down, after next entrance to DSM. When returning from DSM, external
 *       oscillator will be enabled again, on chip oscillator will return to oscillator mode , and after oscnt count
 *       GPC will continue with the exit from DSM process.
 */
#define GPC_SLPCR_SBYOS(x)                       (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_SBYOS_SHIFT)) & GPC_SLPCR_SBYOS_MASK)

#define GPC_SLPCR_VSTBY_MASK                     (0x4U)
#define GPC_SLPCR_VSTBY_SHIFT                    (2U)
/*! VSTBY
 *  0b0..Voltage will not be changed to standby voltage after next entrance to stop mode. (PMIC_STBY_REQ will remain negated - '0')
 *  0b1..Voltage will be changed to standby voltage after next entrance to stop mode.
 */
#define GPC_SLPCR_VSTBY(x)                       (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_VSTBY_SHIFT)) & GPC_SLPCR_VSTBY_MASK)

#define GPC_SLPCR_STBY_COUNT_MASK                (0x38U)
#define GPC_SLPCR_STBY_COUNT_SHIFT               (3U)
/*! STBY_COUNT
 *  0b000..GPC will wait 4 ckil clock cycles
 *  0b001..GPC will wait 8 ckil clock cycles
 *  0b010..GPC will wait 16 ckil clock cycles
 *  0b011..GPC will wait 32 ckil clock cycles
 *  0b100..GPC will wait 64 ckil clock cycles
 *  0b101..GPC will wait 128 ckil clock cycles
 *  0b110..GPC will wait 256 ckil clock cycles
 *  0b111..GPC will wait 512 ckil clock cycles
 */
#define GPC_SLPCR_STBY_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_STBY_COUNT_SHIFT)) & GPC_SLPCR_STBY_COUNT_MASK)

#define GPC_SLPCR_COSC_PWRDOWN_MASK              (0x40U)
#define GPC_SLPCR_COSC_PWRDOWN_SHIFT             (6U)
/*! COSC_PWRDOWN
 *  0b0..On-chip oscillator will not be powered down, i.e. cosc_pwrdown = 0
 *  0b1..On-chip oscillator will be powered down, i.e. cosc_pwrdown = 1
 */
#define GPC_SLPCR_COSC_PWRDOWN(x)                (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_COSC_PWRDOWN_SHIFT)) & GPC_SLPCR_COSC_PWRDOWN_MASK)

#define GPC_SLPCR_COSC_EN_MASK                   (0x80U)
#define GPC_SLPCR_COSC_EN_SHIFT                  (7U)
/*! COSC_EN
 *  0b0..Disable on-chip oscillator
 *  0b1..Enable on-chip oscillator
 */
#define GPC_SLPCR_COSC_EN(x)                     (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_COSC_EN_SHIFT)) & GPC_SLPCR_COSC_EN_MASK)

#define GPC_SLPCR_OSCCNT_MASK                    (0xFF00U)
#define GPC_SLPCR_OSCCNT_SHIFT                   (8U)
/*! OSCCNT
 *  0b00000000..count 1 ckil
 *  0b11111111..count 256 ckils
 */
#define GPC_SLPCR_OSCCNT(x)                      (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_OSCCNT_SHIFT)) & GPC_SLPCR_OSCCNT_MASK)

#define GPC_SLPCR_EN_A53_FASTWUP_WAIT_MODE_MASK  (0x10000U)
#define GPC_SLPCR_EN_A53_FASTWUP_WAIT_MODE_SHIFT (16U)
#define GPC_SLPCR_EN_A53_FASTWUP_WAIT_MODE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_EN_A53_FASTWUP_WAIT_MODE_SHIFT)) & GPC_SLPCR_EN_A53_FASTWUP_WAIT_MODE_MASK)

#define GPC_SLPCR_EN_A53_FASTWUP_STOP_MODE_MASK  (0x20000U)
#define GPC_SLPCR_EN_A53_FASTWUP_STOP_MODE_SHIFT (17U)
#define GPC_SLPCR_EN_A53_FASTWUP_STOP_MODE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_EN_A53_FASTWUP_STOP_MODE_SHIFT)) & GPC_SLPCR_EN_A53_FASTWUP_STOP_MODE_MASK)

#define GPC_SLPCR_EN_M7_FASTWUP_WAIT_MODE_MASK   (0x40000U)
#define GPC_SLPCR_EN_M7_FASTWUP_WAIT_MODE_SHIFT  (18U)
#define GPC_SLPCR_EN_M7_FASTWUP_WAIT_MODE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_EN_M7_FASTWUP_WAIT_MODE_SHIFT)) & GPC_SLPCR_EN_M7_FASTWUP_WAIT_MODE_MASK)

#define GPC_SLPCR_EN_M7_FASTWUP_STOP_MODE_MASK   (0x80000U)
#define GPC_SLPCR_EN_M7_FASTWUP_STOP_MODE_SHIFT  (19U)
#define GPC_SLPCR_EN_M7_FASTWUP_STOP_MODE(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_EN_M7_FASTWUP_STOP_MODE_SHIFT)) & GPC_SLPCR_EN_M7_FASTWUP_STOP_MODE_MASK)

#define GPC_SLPCR_DISABLE_A53_IS_DSM_MASK        (0x800000U)
#define GPC_SLPCR_DISABLE_A53_IS_DSM_SHIFT       (23U)
/*! DISABLE_A53_IS_DSM
 *  0b0..Enable A53 isolation signal in DSM
 *  0b1..Disable A53 isolation signal in DSM
 */
#define GPC_SLPCR_DISABLE_A53_IS_DSM(x)          (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_DISABLE_A53_IS_DSM_SHIFT)) & GPC_SLPCR_DISABLE_A53_IS_DSM_MASK)

#define GPC_SLPCR_REG_BYPASS_COUNT_MASK          (0x3F000000U)
#define GPC_SLPCR_REG_BYPASS_COUNT_SHIFT         (24U)
/*! REG_BYPASS_COUNT
 *  0b000000..no delay
 *  0b000001..1 CKIL clock period delay
 *  0b111111..63 CKIL clock period delay
 */
#define GPC_SLPCR_REG_BYPASS_COUNT(x)            (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_REG_BYPASS_COUNT_SHIFT)) & GPC_SLPCR_REG_BYPASS_COUNT_MASK)

#define GPC_SLPCR_RBC_EN_MASK                    (0x40000000U)
#define GPC_SLPCR_RBC_EN_SHIFT                   (30U)
/*! RBC_EN
 *  0b0..REG_BYPASS_COUNTER disabled
 *  0b1..REG_BYPASS_COUNTER enabled
 */
#define GPC_SLPCR_RBC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_RBC_EN_SHIFT)) & GPC_SLPCR_RBC_EN_MASK)

#define GPC_SLPCR_EN_DSM_MASK                    (0x80000000U)
#define GPC_SLPCR_EN_DSM_SHIFT                   (31U)
/*! EN_DSM
 *  0b0..DSM disabled
 *  0b1..DSM enabled
 */
#define GPC_SLPCR_EN_DSM(x)                      (((uint32_t)(((uint32_t)(x)) << GPC_SLPCR_EN_DSM_SHIFT)) & GPC_SLPCR_EN_DSM_MASK)
/*! @} */

/*! @name MST_CPU_MAPPING - MASTER LPM Handshake */
/*! @{ */

#define GPC_MST_CPU_MAPPING_MST0_CPU_MAPPING_MASK (0x1U)
#define GPC_MST_CPU_MAPPING_MST0_CPU_MAPPING_SHIFT (0U)
/*! MST0_CPU_MAPPING - MASTER0 CPU Mapping
 *  0b0..GPC will not send out power off requirement
 *  0b1..GPC will send out power off requirement
 */
#define GPC_MST_CPU_MAPPING_MST0_CPU_MAPPING(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MST_CPU_MAPPING_MST0_CPU_MAPPING_SHIFT)) & GPC_MST_CPU_MAPPING_MST0_CPU_MAPPING_MASK)

#define GPC_MST_CPU_MAPPING_MST1_CPU_MAPPING_MASK (0x2U)
#define GPC_MST_CPU_MAPPING_MST1_CPU_MAPPING_SHIFT (1U)
/*! MST1_CPU_MAPPING - MASTER0 CPU Mapping
 *  0b0..GPC will not send out power off requirement
 *  0b1..GPC will send out power off requirement
 */
#define GPC_MST_CPU_MAPPING_MST1_CPU_MAPPING(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MST_CPU_MAPPING_MST1_CPU_MAPPING_SHIFT)) & GPC_MST_CPU_MAPPING_MST1_CPU_MAPPING_MASK)

#define GPC_MST_CPU_MAPPING_MST2_CPU_MAPPING_MASK (0x4U)
#define GPC_MST_CPU_MAPPING_MST2_CPU_MAPPING_SHIFT (2U)
/*! MST2_CPU_MAPPING - MASTER2 CPU Mapping
 *  0b0..GPC will not send out power off requirement
 *  0b1..GPC will send out power off requirement
 */
#define GPC_MST_CPU_MAPPING_MST2_CPU_MAPPING(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MST_CPU_MAPPING_MST2_CPU_MAPPING_SHIFT)) & GPC_MST_CPU_MAPPING_MST2_CPU_MAPPING_MASK)

#define GPC_MST_CPU_MAPPING_MST3_CPU_MAPPING_MASK (0x8U)
#define GPC_MST_CPU_MAPPING_MST3_CPU_MAPPING_SHIFT (3U)
/*! MST3_CPU_MAPPING - MASTER3 CPU Mapping
 *  0b0..GPC will not send out power off requirement
 *  0b1..GPC will send out power off requirement
 */
#define GPC_MST_CPU_MAPPING_MST3_CPU_MAPPING(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MST_CPU_MAPPING_MST3_CPU_MAPPING_SHIFT)) & GPC_MST_CPU_MAPPING_MST3_CPU_MAPPING_MASK)

#define GPC_MST_CPU_MAPPING_MST4_CPU_MAPPING_MASK (0x10U)
#define GPC_MST_CPU_MAPPING_MST4_CPU_MAPPING_SHIFT (4U)
/*! MST4_CPU_MAPPING - MASTER4 CPU Mapping
 *  0b0..GPC will not send out power off requirement
 *  0b1..GPC will send out power off requirement
 */
#define GPC_MST_CPU_MAPPING_MST4_CPU_MAPPING(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MST_CPU_MAPPING_MST4_CPU_MAPPING_SHIFT)) & GPC_MST_CPU_MAPPING_MST4_CPU_MAPPING_MASK)
/*! @} */

/*! @name MLPCR - Memory low power control register */
/*! @{ */

#define GPC_MLPCR_MEMLP_CTL_DIS_MASK             (0x1U)
#define GPC_MLPCR_MEMLP_CTL_DIS_SHIFT            (0U)
/*! MEMLP_CTL_DIS
 *  0b0..Enable RAM low power control
 *  0b1..Disable RAM low power control
 */
#define GPC_MLPCR_MEMLP_CTL_DIS(x)               (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_MEMLP_CTL_DIS_SHIFT)) & GPC_MLPCR_MEMLP_CTL_DIS_MASK)

#define GPC_MLPCR_MEMLP_RET_SEL_MASK             (0x2U)
#define GPC_MLPCR_MEMLP_RET_SEL_SHIFT            (1U)
/*! MEMLP_RET_SEL
 *  0b0..retention mode 2
 *  0b1..retention mode 1
 */
#define GPC_MLPCR_MEMLP_RET_SEL(x)               (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_MEMLP_RET_SEL_SHIFT)) & GPC_MLPCR_MEMLP_RET_SEL_MASK)

#define GPC_MLPCR_ROMLP_PDN_DIS_MASK             (0x4U)
#define GPC_MLPCR_ROMLP_PDN_DIS_SHIFT            (2U)
/*! ROMLP_PDN_DIS
 *  0b0..Enable ROM shut down control(should also enable RAM low power control);
 *  0b1..Disable ROM shut down control
 */
#define GPC_MLPCR_ROMLP_PDN_DIS(x)               (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_ROMLP_PDN_DIS_SHIFT)) & GPC_MLPCR_ROMLP_PDN_DIS_MASK)

#define GPC_MLPCR_MEMLP_ENT_CNT_MASK             (0xFF00U)
#define GPC_MLPCR_MEMLP_ENT_CNT_SHIFT            (8U)
#define GPC_MLPCR_MEMLP_ENT_CNT(x)               (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_MEMLP_ENT_CNT_SHIFT)) & GPC_MLPCR_MEMLP_ENT_CNT_MASK)

#define GPC_MLPCR_MEM_EXT_CNT_MASK               (0xFF0000U)
#define GPC_MLPCR_MEM_EXT_CNT_SHIFT              (16U)
#define GPC_MLPCR_MEM_EXT_CNT(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_MEM_EXT_CNT_SHIFT)) & GPC_MLPCR_MEM_EXT_CNT_MASK)

#define GPC_MLPCR_MEMLP_RET_PGEN_MASK            (0xFF000000U)
#define GPC_MLPCR_MEMLP_RET_PGEN_SHIFT           (24U)
#define GPC_MLPCR_MEMLP_RET_PGEN(x)              (((uint32_t)(((uint32_t)(x)) << GPC_MLPCR_MEMLP_RET_PGEN_SHIFT)) & GPC_MLPCR_MEMLP_RET_PGEN_MASK)
/*! @} */

/*! @name PGC_ACK_SEL_A53 - PGC acknowledge signal selection of A53 platform */
/*! @{ */

#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PDN_ACK_MASK (0x1U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PDN_ACK_SHIFT (0U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_MASK (0x2U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_SHIFT (1U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_MASK (0x4U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_SHIFT (2U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_MASK (0x8U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_SHIFT (3U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_MASK (0x2000U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_SHIFT (13U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_MASK (0x4000U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_SHIFT (14U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_MASK (0x8000U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_SHIFT (15U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_MASK (0x10000U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_SHIFT (16U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_MASK (0x20000U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_SHIFT (17U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_MASK (0x40000U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_SHIFT (18U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_MASK (0x80000U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_SHIFT (19U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_MASK (0x20000000U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_SHIFT (29U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_MASK (0x40000000U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_SHIFT (30U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_MASK (0x80000000U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_SHIFT (31U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name PGC_ACK_SEL_M7 - PGC acknowledge signal selection of M7 platform */
/*! @{ */

#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_MASK (0x1U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_SHIFT (0U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_MASK  (0x2U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_SHIFT (1U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_MASK (0x8000U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_SHIFT (15U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_MASK (0x10000U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_SHIFT (16U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_MASK  (0x20000U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_SHIFT (17U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PUP_ACK_MASK (0x80000000U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PUP_ACK_SHIFT (31U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name MISC - GPC Miscellaneous register */
/*! @{ */

#define GPC_MISC_M7_SLEEP_HOLD_REQ_B_MASK        (0x1U)
#define GPC_MISC_M7_SLEEP_HOLD_REQ_B_SHIFT       (0U)
/*! M7_SLEEP_HOLD_REQ_B
 *  0b0..Hold M7 platform in sleep mode. This bit is a software control bit to M7 platform.
 *  0b1..Don't hold M7 platform in sleep mode.
 */
#define GPC_MISC_M7_SLEEP_HOLD_REQ_B(x)          (((uint32_t)(((uint32_t)(x)) << GPC_MISC_M7_SLEEP_HOLD_REQ_B_SHIFT)) & GPC_MISC_M7_SLEEP_HOLD_REQ_B_MASK)

#define GPC_MISC_A53_SLEEP_HOLD_REQ_B_MASK       (0x2U)
#define GPC_MISC_A53_SLEEP_HOLD_REQ_B_SHIFT      (1U)
/*! A53_SLEEP_HOLD_REQ_B
 *  0b0..Hold A53 platform in sleep mode. This bit is a software control bit to A53 platform.
 *  0b1..Don't hold A53 platform in sleep mode.
 */
#define GPC_MISC_A53_SLEEP_HOLD_REQ_B(x)         (((uint32_t)(((uint32_t)(x)) << GPC_MISC_A53_SLEEP_HOLD_REQ_B_SHIFT)) & GPC_MISC_A53_SLEEP_HOLD_REQ_B_MASK)

#define GPC_MISC_GPC_IRQ_MASK_MASK               (0x20U)
#define GPC_MISC_GPC_IRQ_MASK_SHIFT              (5U)
/*! GPC_IRQ_MASK
 *  0b0..Not masked
 *  0b1..Interrupt / event is masked
 */
#define GPC_MISC_GPC_IRQ_MASK(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_MISC_GPC_IRQ_MASK_SHIFT)) & GPC_MISC_GPC_IRQ_MASK_MASK)

#define GPC_MISC_M7_PDN_REQ_MASK_MASK            (0x100U)
#define GPC_MISC_M7_PDN_REQ_MASK_SHIFT           (8U)
/*! M7_PDN_REQ_MASK
 *  0b0..M7 power down request to virtual M7 PGC will be masked.
 *  0b1..M7 power down request to virtual M7 PGC will not be masked. Set this bit to 1'b1 when M7 virtual PGC is used.
 */
#define GPC_MISC_M7_PDN_REQ_MASK(x)              (((uint32_t)(((uint32_t)(x)) << GPC_MISC_M7_PDN_REQ_MASK_SHIFT)) & GPC_MISC_M7_PDN_REQ_MASK_MASK)

#define GPC_MISC_A53_BYPASS_PUP_MASK_MASK        (0x1000000U)
#define GPC_MISC_A53_BYPASS_PUP_MASK_SHIFT       (24U)
#define GPC_MISC_A53_BYPASS_PUP_MASK(x)          (((uint32_t)(((uint32_t)(x)) << GPC_MISC_A53_BYPASS_PUP_MASK_SHIFT)) & GPC_MISC_A53_BYPASS_PUP_MASK_MASK)

#define GPC_MISC_M7_BYPASS_PUP_MASK_MASK         (0x2000000U)
#define GPC_MISC_M7_BYPASS_PUP_MASK_SHIFT        (25U)
#define GPC_MISC_M7_BYPASS_PUP_MASK(x)           (((uint32_t)(((uint32_t)(x)) << GPC_MISC_M7_BYPASS_PUP_MASK_SHIFT)) & GPC_MISC_M7_BYPASS_PUP_MASK_MASK)
/*! @} */

/*! @name IMR_CORE0_A53 - IRQ masking register 1 of A53 core0..IRQ masking register 4 of A53 core0 */
/*! @{ */

#define GPC_IMR_CORE0_A53_IMR1_CORE0_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE0_A53_IMR1_CORE0_A53_SHIFT   (0U)
/*! IMR1_CORE0_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE0_A53_IMR1_CORE0_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE0_A53_IMR1_CORE0_A53_SHIFT)) & GPC_IMR_CORE0_A53_IMR1_CORE0_A53_MASK)

#define GPC_IMR_CORE0_A53_IMR2_CORE0_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE0_A53_IMR2_CORE0_A53_SHIFT   (0U)
/*! IMR2_CORE0_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE0_A53_IMR2_CORE0_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE0_A53_IMR2_CORE0_A53_SHIFT)) & GPC_IMR_CORE0_A53_IMR2_CORE0_A53_MASK)

#define GPC_IMR_CORE0_A53_IMR3_CORE0_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE0_A53_IMR3_CORE0_A53_SHIFT   (0U)
/*! IMR3_CORE0_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE0_A53_IMR3_CORE0_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE0_A53_IMR3_CORE0_A53_SHIFT)) & GPC_IMR_CORE0_A53_IMR3_CORE0_A53_MASK)

#define GPC_IMR_CORE0_A53_IMR4_CORE0_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE0_A53_IMR4_CORE0_A53_SHIFT   (0U)
/*! IMR4_CORE0_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE0_A53_IMR4_CORE0_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE0_A53_IMR4_CORE0_A53_SHIFT)) & GPC_IMR_CORE0_A53_IMR4_CORE0_A53_MASK)
/*! @} */

/*! @name IMR_CORE1_A53 - IRQ masking register 1 of A53 core1..IRQ masking register 4 of A53 core1 */
/*! @{ */

#define GPC_IMR_CORE1_A53_IMR1_CORE1_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE1_A53_IMR1_CORE1_A53_SHIFT   (0U)
/*! IMR1_CORE1_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE1_A53_IMR1_CORE1_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE1_A53_IMR1_CORE1_A53_SHIFT)) & GPC_IMR_CORE1_A53_IMR1_CORE1_A53_MASK)

#define GPC_IMR_CORE1_A53_IMR2_CORE1_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE1_A53_IMR2_CORE1_A53_SHIFT   (0U)
/*! IMR2_CORE1_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE1_A53_IMR2_CORE1_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE1_A53_IMR2_CORE1_A53_SHIFT)) & GPC_IMR_CORE1_A53_IMR2_CORE1_A53_MASK)

#define GPC_IMR_CORE1_A53_IMR3_CORE1_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE1_A53_IMR3_CORE1_A53_SHIFT   (0U)
/*! IMR3_CORE1_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE1_A53_IMR3_CORE1_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE1_A53_IMR3_CORE1_A53_SHIFT)) & GPC_IMR_CORE1_A53_IMR3_CORE1_A53_MASK)

#define GPC_IMR_CORE1_A53_IMR4_CORE1_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE1_A53_IMR4_CORE1_A53_SHIFT   (0U)
/*! IMR4_CORE1_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE1_A53_IMR4_CORE1_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE1_A53_IMR4_CORE1_A53_SHIFT)) & GPC_IMR_CORE1_A53_IMR4_CORE1_A53_MASK)
/*! @} */

/*! @name IMR_M7 - IRQ masking register 1 of M7..IRQ masking register 4 of M7 */
/*! @{ */

#define GPC_IMR_M7_IMR1_M7_MASK                  (0xFFFFFFFFU)
#define GPC_IMR_M7_IMR1_M7_SHIFT                 (0U)
/*! IMR1_M7
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_M7_IMR1_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_IMR_M7_IMR1_M7_SHIFT)) & GPC_IMR_M7_IMR1_M7_MASK)

#define GPC_IMR_M7_IMR2_M7_MASK                  (0xFFFFFFFFU)
#define GPC_IMR_M7_IMR2_M7_SHIFT                 (0U)
/*! IMR2_M7
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_M7_IMR2_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_IMR_M7_IMR2_M7_SHIFT)) & GPC_IMR_M7_IMR2_M7_MASK)

#define GPC_IMR_M7_IMR3_M7_MASK                  (0xFFFFFFFFU)
#define GPC_IMR_M7_IMR3_M7_SHIFT                 (0U)
/*! IMR3_M7
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_M7_IMR3_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_IMR_M7_IMR3_M7_SHIFT)) & GPC_IMR_M7_IMR3_M7_MASK)

#define GPC_IMR_M7_IMR4_M7_MASK                  (0xFFFFFFFFU)
#define GPC_IMR_M7_IMR4_M7_SHIFT                 (0U)
/*! IMR4_M7
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_M7_IMR4_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_IMR_M7_IMR4_M7_SHIFT)) & GPC_IMR_M7_IMR4_M7_MASK)
/*! @} */

/*! @name ISR_A53 - IRQ status register 1 of A53..IRQ status register 4 of A53 */
/*! @{ */

#define GPC_ISR_A53_ISR1_A53_MASK                (0xFFFFFFFFU)
#define GPC_ISR_A53_ISR1_A53_SHIFT               (0U)
#define GPC_ISR_A53_ISR1_A53(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_ISR_A53_ISR1_A53_SHIFT)) & GPC_ISR_A53_ISR1_A53_MASK)

#define GPC_ISR_A53_ISR2_A53_MASK                (0xFFFFFFFFU)
#define GPC_ISR_A53_ISR2_A53_SHIFT               (0U)
#define GPC_ISR_A53_ISR2_A53(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_ISR_A53_ISR2_A53_SHIFT)) & GPC_ISR_A53_ISR2_A53_MASK)

#define GPC_ISR_A53_ISR3_A53_MASK                (0xFFFFFFFFU)
#define GPC_ISR_A53_ISR3_A53_SHIFT               (0U)
#define GPC_ISR_A53_ISR3_A53(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_ISR_A53_ISR3_A53_SHIFT)) & GPC_ISR_A53_ISR3_A53_MASK)

#define GPC_ISR_A53_ISR4_A53_MASK                (0xFFFFFFFFU)
#define GPC_ISR_A53_ISR4_A53_SHIFT               (0U)
#define GPC_ISR_A53_ISR4_A53(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_ISR_A53_ISR4_A53_SHIFT)) & GPC_ISR_A53_ISR4_A53_MASK)
/*! @} */

/*! @name ISR_M7 - IRQ status register 1 of M7..IRQ status register 4 of M7 */
/*! @{ */

#define GPC_ISR_M7_ISR1_M7_MASK                  (0xFFFFFFFFU)
#define GPC_ISR_M7_ISR1_M7_SHIFT                 (0U)
#define GPC_ISR_M7_ISR1_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_ISR_M7_ISR1_M7_SHIFT)) & GPC_ISR_M7_ISR1_M7_MASK)

#define GPC_ISR_M7_ISR2_M7_MASK                  (0xFFFFFFFFU)
#define GPC_ISR_M7_ISR2_M7_SHIFT                 (0U)
#define GPC_ISR_M7_ISR2_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_ISR_M7_ISR2_M7_SHIFT)) & GPC_ISR_M7_ISR2_M7_MASK)

#define GPC_ISR_M7_ISR3_M7_MASK                  (0xFFFFFFFFU)
#define GPC_ISR_M7_ISR3_M7_SHIFT                 (0U)
#define GPC_ISR_M7_ISR3_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_ISR_M7_ISR3_M7_SHIFT)) & GPC_ISR_M7_ISR3_M7_MASK)

#define GPC_ISR_M7_ISR4_M7_MASK                  (0xFFFFFFFFU)
#define GPC_ISR_M7_ISR4_M7_SHIFT                 (0U)
#define GPC_ISR_M7_ISR4_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_ISR_M7_ISR4_M7_SHIFT)) & GPC_ISR_M7_ISR4_M7_MASK)
/*! @} */

/*! @name SLT0_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT0_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT0_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT0_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT0_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT0_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT0_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT0_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT0_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT0_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT0_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT0_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT0_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT0_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT0_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT0_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT0_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT0_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT0_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT0_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT0_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT0_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT0_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT0_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT0_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT0_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT0_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT0_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT0_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT1_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT1_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT1_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT1_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT1_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT1_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT1_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT1_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT1_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT1_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT1_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT1_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT1_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT1_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT1_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT1_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT1_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT1_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT1_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT1_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT1_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT1_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT1_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT1_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT1_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT1_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT1_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT1_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT1_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT2_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT2_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT2_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT2_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT2_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT2_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT2_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT2_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT2_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT2_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT2_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT2_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT2_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT2_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT2_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT2_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT2_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT2_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT2_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT2_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT2_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT2_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT2_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT2_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT2_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT2_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT2_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT2_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT2_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT3_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT3_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT3_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT3_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT3_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT3_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT3_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT3_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT3_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT3_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT3_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT3_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT3_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT3_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT3_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT3_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT3_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT3_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT3_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT3_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT3_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT3_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT3_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT3_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT3_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT3_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT3_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT3_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT3_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT4_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT4_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT4_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT4_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT4_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT4_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT4_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT4_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT4_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT4_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT4_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT4_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT4_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT4_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT4_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT4_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT4_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT4_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT4_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT4_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT4_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT4_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT4_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT4_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT4_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT4_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT4_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT4_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT4_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT5_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT5_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT5_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT5_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT5_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT5_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT5_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT5_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT5_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT5_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT5_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT5_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT5_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT5_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT5_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT5_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT5_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT5_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT5_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT5_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT5_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT5_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT5_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT5_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT5_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT5_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT5_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT5_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT5_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT6_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT6_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT6_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT6_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT6_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT6_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT6_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT6_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT6_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT6_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT6_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT6_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT6_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT6_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT6_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT6_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT6_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT6_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT6_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT6_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT6_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT6_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT6_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT6_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT6_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT6_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT6_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT6_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT6_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT7_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT7_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT7_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT7_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT7_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT7_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT7_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT7_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT7_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT7_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT7_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT7_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT7_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT7_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT7_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT7_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT7_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT7_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT7_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT7_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT7_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT7_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT7_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT7_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT7_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT7_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT7_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT7_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT7_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT8_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT8_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT8_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT8_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT8_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT8_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT8_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT8_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT8_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT8_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT8_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT8_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT8_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT8_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT8_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT8_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT8_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT8_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT8_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT8_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT8_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT8_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT8_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT8_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT8_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT8_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT8_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT8_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT8_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT9_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT9_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT9_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT9_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT9_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT9_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT9_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT9_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT9_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT9_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT9_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT9_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT9_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT9_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT9_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT9_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT9_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT9_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_SCU_PDN_SLOT_CONTROL_MASK   (0x100U)
#define GPC_SLT9_CFG_SCU_PDN_SLOT_CONTROL_SHIFT  (8U)
#define GPC_SLT9_CFG_SCU_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_SCU_PUP_SLOT_CONTROL_MASK   (0x200U)
#define GPC_SLT9_CFG_SCU_PUP_SLOT_CONTROL_SHIFT  (9U)
#define GPC_SLT9_CFG_SCU_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_NOC_PDN_SLOT_CONTROL_MASK   (0x400U)
#define GPC_SLT9_CFG_NOC_PDN_SLOT_CONTROL_SHIFT  (10U)
#define GPC_SLT9_CFG_NOC_PDN_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT9_CFG_NOC_PUP_SLOT_CONTROL_MASK   (0x800U)
#define GPC_SLT9_CFG_NOC_PUP_SLOT_CONTROL_SHIFT  (11U)
#define GPC_SLT9_CFG_NOC_PUP_SLOT_CONTROL(x)     (((uint32_t)(((uint32_t)(x)) << GPC_SLT9_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT9_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT10_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT10_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT10_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT10_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT10_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT10_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT10_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT10_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT10_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT10_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT10_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT10_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT10_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT10_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT10_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT10_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT10_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT10_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT10_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT10_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT10_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT10_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT10_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT10_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT10_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT10_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT10_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT10_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT10_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT11_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT11_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT11_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT11_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT11_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT11_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT11_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT11_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT11_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT11_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT11_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT11_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT11_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT11_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT11_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT11_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT11_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT11_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT11_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT11_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT11_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT11_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT11_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT11_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT11_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT11_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT11_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT11_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT11_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT12_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT12_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT12_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT12_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT12_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT12_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT12_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT12_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT12_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT12_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT12_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT12_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT12_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT12_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT12_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT12_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT12_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT12_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT12_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT12_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT12_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT12_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT12_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT12_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT12_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT12_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT12_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT12_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT12_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT13_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT13_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT13_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT13_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT13_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT13_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT13_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT13_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT13_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT13_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT13_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT13_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT13_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT13_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT13_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT13_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT13_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT13_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT13_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT13_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT13_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT13_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT13_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT13_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT13_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT13_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT13_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT13_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT13_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT14_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT14_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT14_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT14_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT14_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT14_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT14_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT14_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT14_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT14_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT14_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT14_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT14_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT14_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT14_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT14_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT14_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT14_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT14_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT14_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT14_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT14_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT14_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT14_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT14_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT14_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT14_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT14_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT14_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name PGC_CPU_0_1_MAPPING - PGC CPU mapping */
/*! @{ */

#define GPC_PGC_CPU_0_1_MAPPING_NOC_A53_DOMAIN_MASK (0x2U)
#define GPC_PGC_CPU_0_1_MAPPING_NOC_A53_DOMAIN_SHIFT (1U)
#define GPC_PGC_CPU_0_1_MAPPING_NOC_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_NOC_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_NOC_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_MIPI_A53_DOMAIN_MASK (0x4U)
#define GPC_PGC_CPU_0_1_MAPPING_MIPI_A53_DOMAIN_SHIFT (2U)
#define GPC_PGC_CPU_0_1_MAPPING_MIPI_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_MIPI_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_MIPI_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_OTG1_A53_DOMAIN_MASK (0x10U)
#define GPC_PGC_CPU_0_1_MAPPING_OTG1_A53_DOMAIN_SHIFT (4U)
#define GPC_PGC_CPU_0_1_MAPPING_OTG1_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_OTG1_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_OTG1_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_DDR1_A53_DOMAIN_MASK (0x80U)
#define GPC_PGC_CPU_0_1_MAPPING_DDR1_A53_DOMAIN_SHIFT (7U)
#define GPC_PGC_CPU_0_1_MAPPING_DDR1_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_DDR1_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_DDR1_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_GPU_A53_DOMAIN_MASK (0x200U)
#define GPC_PGC_CPU_0_1_MAPPING_GPU_A53_DOMAIN_SHIFT (9U)
#define GPC_PGC_CPU_0_1_MAPPING_GPU_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_GPU_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_GPU_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_A53_DOMAIN_MASK (0x1000U)
#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_A53_DOMAIN_SHIFT (12U)
#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_A53_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_DISPMIX_A53_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_DISPMIX_A53_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_NOC_M7_DOMAIN_MASK (0x20000U)
#define GPC_PGC_CPU_0_1_MAPPING_NOC_M7_DOMAIN_SHIFT (17U)
#define GPC_PGC_CPU_0_1_MAPPING_NOC_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_NOC_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_NOC_M7_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_MIPI_M7_DOMAIN_MASK (0x40000U)
#define GPC_PGC_CPU_0_1_MAPPING_MIPI_M7_DOMAIN_SHIFT (18U)
#define GPC_PGC_CPU_0_1_MAPPING_MIPI_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_MIPI_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_MIPI_M7_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_OTG1_M7_DOMAIN_MASK (0x100000U)
#define GPC_PGC_CPU_0_1_MAPPING_OTG1_M7_DOMAIN_SHIFT (20U)
#define GPC_PGC_CPU_0_1_MAPPING_OTG1_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_OTG1_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_OTG1_M7_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_DDR1_M7_DOMAIN_MASK (0x800000U)
#define GPC_PGC_CPU_0_1_MAPPING_DDR1_M7_DOMAIN_SHIFT (23U)
#define GPC_PGC_CPU_0_1_MAPPING_DDR1_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_DDR1_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_DDR1_M7_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_GPUMIX_M7_DOMAIN_MASK (0x2000000U)
#define GPC_PGC_CPU_0_1_MAPPING_GPUMIX_M7_DOMAIN_SHIFT (25U)
#define GPC_PGC_CPU_0_1_MAPPING_GPUMIX_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_GPUMIX_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_GPUMIX_M7_DOMAIN_MASK)

#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_M7_DOMAIN_MASK (0x10000000U)
#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_M7_DOMAIN_SHIFT (28U)
#define GPC_PGC_CPU_0_1_MAPPING_DISPMIX_M7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_0_1_MAPPING_DISPMIX_M7_DOMAIN_SHIFT)) & GPC_PGC_CPU_0_1_MAPPING_DISPMIX_M7_DOMAIN_MASK)
/*! @} */

/*! @name CPU_PGC_SW_PUP_REQ - CPU PGC software power up trigger */
/*! @{ */

#define GPC_CPU_PGC_SW_PUP_REQ_CORE0_A53_SW_PUP_REQ_MASK (0x1U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE0_A53_SW_PUP_REQ_SHIFT (0U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE0_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PUP_REQ_CORE0_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PUP_REQ_CORE0_A53_SW_PUP_REQ_MASK)

#define GPC_CPU_PGC_SW_PUP_REQ_CORE1_A53_SW_PUP_REQ_MASK (0x2U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE1_A53_SW_PUP_REQ_SHIFT (1U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE1_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PUP_REQ_CORE1_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PUP_REQ_CORE1_A53_SW_PUP_REQ_MASK)

#define GPC_CPU_PGC_SW_PUP_REQ_CORE2_A53_SW_PUP_REQ_MASK (0x4U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE2_A53_SW_PUP_REQ_SHIFT (2U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE2_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PUP_REQ_CORE2_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PUP_REQ_CORE2_A53_SW_PUP_REQ_MASK)

#define GPC_CPU_PGC_SW_PUP_REQ_CORE3_A53_SW_PUP_REQ_MASK (0x8U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE3_A53_SW_PUP_REQ_SHIFT (3U)
#define GPC_CPU_PGC_SW_PUP_REQ_CORE3_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PUP_REQ_CORE3_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PUP_REQ_CORE3_A53_SW_PUP_REQ_MASK)

#define GPC_CPU_PGC_SW_PUP_REQ_SCU_A53_SW_PUP_REQ_MASK (0x10U)
#define GPC_CPU_PGC_SW_PUP_REQ_SCU_A53_SW_PUP_REQ_SHIFT (4U)
#define GPC_CPU_PGC_SW_PUP_REQ_SCU_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PUP_REQ_SCU_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PUP_REQ_SCU_A53_SW_PUP_REQ_MASK)
/*! @} */

/*! @name MIX_PGC_SW_PUP_REQ - MIX PGC software power up trigger */
/*! @{ */

#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_MASK (0x2U)
#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_SHIFT (1U)
#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_SHIFT)) & GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_MASK)
/*! @} */

/*! @name PU_PGC_SW_PUP_REQ - PU PGC software up trigger */
/*! @{ */

#define GPC_PU_PGC_SW_PUP_REQ_MIPI_DSI_SW_PUP_REQ_MASK (0x1U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_DSI_SW_PUP_REQ_SHIFT (0U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_DSI_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MIPI_DSI_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MIPI_DSI_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_USB_OTG1_SW_PUP_REQ_MASK (0x4U)
#define GPC_PU_PGC_SW_PUP_REQ_USB_OTG1_SW_PUP_REQ_SHIFT (2U)
#define GPC_PU_PGC_SW_PUP_REQ_USB_OTG1_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_USB_OTG1_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_USB_OTG1_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ_MASK (0x20U)
#define GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ_SHIFT (5U)
#define GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_DDR1_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_GPUMIX_SW_PUP_REQ_MASK (0x80U)
#define GPC_PU_PGC_SW_PUP_REQ_GPUMIX_SW_PUP_REQ_SHIFT (7U)
#define GPC_PU_PGC_SW_PUP_REQ_GPUMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_GPUMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_GPUMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_DISPMIX_SW_PUP_REQ_MASK (0x400U)
#define GPC_PU_PGC_SW_PUP_REQ_DISPMIX_SW_PUP_REQ_SHIFT (10U)
#define GPC_PU_PGC_SW_PUP_REQ_DISPMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_DISPMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_DISPMIX_SW_PUP_REQ_MASK)
/*! @} */

/*! @name CPU_PGC_SW_PDN_REQ - CPU PGC software down trigger */
/*! @{ */

#define GPC_CPU_PGC_SW_PDN_REQ_CORE0_A53_SW_PDN_REQ_MASK (0x1U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE0_A53_SW_PDN_REQ_SHIFT (0U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE0_A53_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PDN_REQ_CORE0_A53_SW_PDN_REQ_SHIFT)) & GPC_CPU_PGC_SW_PDN_REQ_CORE0_A53_SW_PDN_REQ_MASK)

#define GPC_CPU_PGC_SW_PDN_REQ_CORE1_A53_SW_PDN_REQ_MASK (0x2U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE1_A53_SW_PDN_REQ_SHIFT (1U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE1_A53_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PDN_REQ_CORE1_A53_SW_PDN_REQ_SHIFT)) & GPC_CPU_PGC_SW_PDN_REQ_CORE1_A53_SW_PDN_REQ_MASK)

#define GPC_CPU_PGC_SW_PDN_REQ_CORE2_A53_SW_PDN_REQ_MASK (0x4U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE2_A53_SW_PDN_REQ_SHIFT (2U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE2_A53_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PDN_REQ_CORE2_A53_SW_PDN_REQ_SHIFT)) & GPC_CPU_PGC_SW_PDN_REQ_CORE2_A53_SW_PDN_REQ_MASK)

#define GPC_CPU_PGC_SW_PDN_REQ_CORE3_A53_SW_PUP_REQ_MASK (0x8U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE3_A53_SW_PUP_REQ_SHIFT (3U)
#define GPC_CPU_PGC_SW_PDN_REQ_CORE3_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PDN_REQ_CORE3_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PDN_REQ_CORE3_A53_SW_PUP_REQ_MASK)

#define GPC_CPU_PGC_SW_PDN_REQ_SCU_A53_SW_PUP_REQ_MASK (0x10U)
#define GPC_CPU_PGC_SW_PDN_REQ_SCU_A53_SW_PUP_REQ_SHIFT (4U)
#define GPC_CPU_PGC_SW_PDN_REQ_SCU_A53_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_SW_PDN_REQ_SCU_A53_SW_PUP_REQ_SHIFT)) & GPC_CPU_PGC_SW_PDN_REQ_SCU_A53_SW_PUP_REQ_MASK)
/*! @} */

/*! @name MIX_PGC_SW_PDN_REQ - MIX PGC software power down trigger */
/*! @{ */

#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_MASK (0x2U)
#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_SHIFT (1U)
#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_SHIFT)) & GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_MASK)
/*! @} */

/*! @name PU_PGC_SW_PDN_REQ - PU PGC software down trigger */
/*! @{ */

#define GPC_PU_PGC_SW_PDN_REQ_MIPI_DSI_SW_PDN_REQ_MASK (0x1U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_DSI_SW_PDN_REQ_SHIFT (0U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_DSI_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MIPI_DSI_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MIPI_DSI_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_USB_OTG1_SW_PDN_REQ_MASK (0x4U)
#define GPC_PU_PGC_SW_PDN_REQ_USB_OTG1_SW_PDN_REQ_SHIFT (2U)
#define GPC_PU_PGC_SW_PDN_REQ_USB_OTG1_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_USB_OTG1_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_USB_OTG1_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_DDR1_SW_PDN_REQ_MASK (0x20U)
#define GPC_PU_PGC_SW_PDN_REQ_DDR1_SW_PDN_REQ_SHIFT (5U)
#define GPC_PU_PGC_SW_PDN_REQ_DDR1_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_DDR1_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_DDR1_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_GPUMIX_SW_PDN_REQ_MASK (0x80U)
#define GPC_PU_PGC_SW_PDN_REQ_GPUMIX_SW_PDN_REQ_SHIFT (7U)
#define GPC_PU_PGC_SW_PDN_REQ_GPUMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_GPUMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_GPUMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_DISPMIX_SW_PDN_REQ_MASK (0x400U)
#define GPC_PU_PGC_SW_PDN_REQ_DISPMIX_SW_PDN_REQ_SHIFT (10U)
#define GPC_PU_PGC_SW_PDN_REQ_DISPMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_DISPMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_DISPMIX_SW_PDN_REQ_MASK)
/*! @} */

/*! @name LPCR_A53_BSC2 - Basic Low power control register of A53 platform */
/*! @{ */

#define GPC_LPCR_A53_BSC2_LPM2_MASK              (0x3U)
#define GPC_LPCR_A53_BSC2_LPM2_SHIFT             (0U)
/*! LPM2
 *  0b00..Remain in RUN mode
 *  0b01..Transfer to WAIT mode
 *  0b10..Transfer to STOP mode
 *  0b11..Reserved
 */
#define GPC_LPCR_A53_BSC2_LPM2(x)                (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC2_LPM2_SHIFT)) & GPC_LPCR_A53_BSC2_LPM2_MASK)

#define GPC_LPCR_A53_BSC2_LPM3_MASK              (0xCU)
#define GPC_LPCR_A53_BSC2_LPM3_SHIFT             (2U)
/*! LPM3
 *  0b00..Remain in RUN mode
 *  0b01..Transfer to WAIT mode
 *  0b10..Transfer to STOP mode
 *  0b11..Reserved
 */
#define GPC_LPCR_A53_BSC2_LPM3(x)                (((uint32_t)(((uint32_t)(x)) << GPC_LPCR_A53_BSC2_LPM3_SHIFT)) & GPC_LPCR_A53_BSC2_LPM3_MASK)
/*! @} */

/*! @name CPU_PGC_PUP_STATUS1 - CPU PGC software up trigger status1 */
/*! @{ */

#define GPC_CPU_PGC_PUP_STATUS1_CORE0_A53_PUP_STATUS_MASK (0x1U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE0_A53_PUP_STATUS_SHIFT (0U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE0_A53_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PUP_STATUS1_CORE0_A53_PUP_STATUS_SHIFT)) & GPC_CPU_PGC_PUP_STATUS1_CORE0_A53_PUP_STATUS_MASK)

#define GPC_CPU_PGC_PUP_STATUS1_CORE1_A53_PUP_STATUS_MASK (0x2U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE1_A53_PUP_STATUS_SHIFT (1U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE1_A53_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PUP_STATUS1_CORE1_A53_PUP_STATUS_SHIFT)) & GPC_CPU_PGC_PUP_STATUS1_CORE1_A53_PUP_STATUS_MASK)

#define GPC_CPU_PGC_PUP_STATUS1_CORE2_A53_PUP_STATUS_MASK (0x4U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE2_A53_PUP_STATUS_SHIFT (2U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE2_A53_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PUP_STATUS1_CORE2_A53_PUP_STATUS_SHIFT)) & GPC_CPU_PGC_PUP_STATUS1_CORE2_A53_PUP_STATUS_MASK)

#define GPC_CPU_PGC_PUP_STATUS1_CORE3_A53_PUP_STATUS_MASK (0x8U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE3_A53_PUP_STATUS_SHIFT (3U)
#define GPC_CPU_PGC_PUP_STATUS1_CORE3_A53_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PUP_STATUS1_CORE3_A53_PUP_STATUS_SHIFT)) & GPC_CPU_PGC_PUP_STATUS1_CORE3_A53_PUP_STATUS_MASK)

#define GPC_CPU_PGC_PUP_STATUS1_SCU_A53_PUP_REQ_MASK (0x10U)
#define GPC_CPU_PGC_PUP_STATUS1_SCU_A53_PUP_REQ_SHIFT (4U)
#define GPC_CPU_PGC_PUP_STATUS1_SCU_A53_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PUP_STATUS1_SCU_A53_PUP_REQ_SHIFT)) & GPC_CPU_PGC_PUP_STATUS1_SCU_A53_PUP_REQ_MASK)
/*! @} */

/*! @name A53_MIX_PGC_PUP_STATUS - A53 MIX software up trigger status register */
/*! @{ */

#define GPC_A53_MIX_PGC_PUP_STATUS_A53_MIX_PGC_PUP_STATUS_MASK (0x1U)
#define GPC_A53_MIX_PGC_PUP_STATUS_A53_MIX_PGC_PUP_STATUS_SHIFT (0U)
#define GPC_A53_MIX_PGC_PUP_STATUS_A53_MIX_PGC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_MIX_PGC_PUP_STATUS_A53_MIX_PGC_PUP_STATUS_SHIFT)) & GPC_A53_MIX_PGC_PUP_STATUS_A53_MIX_PGC_PUP_STATUS_MASK)
/*! @} */

/*! @name M7_MIX_PGC_PUP_STATUS - M7 MIX PGC software up trigger status register */
/*! @{ */

#define GPC_M7_MIX_PGC_PUP_STATUS_M7_MIX_PGC_PUP_STATUS_MASK (0x1U)
#define GPC_M7_MIX_PGC_PUP_STATUS_M7_MIX_PGC_PUP_STATUS_SHIFT (0U)
#define GPC_M7_MIX_PGC_PUP_STATUS_M7_MIX_PGC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_MIX_PGC_PUP_STATUS_M7_MIX_PGC_PUP_STATUS_SHIFT)) & GPC_M7_MIX_PGC_PUP_STATUS_M7_MIX_PGC_PUP_STATUS_MASK)
/*! @} */

/*! @name A53_PU_PGC_PUP_STATUS - A53 PU software up trigger status register */
/*! @{ */

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY_PUP_STATUS_MASK (0x1U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY_PUP_STATUS_SHIFT (0U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_OTG1_PUP_STATUS_MASK (0x4U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_OTG1_PUP_STATUS_SHIFT (2U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_OTG1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_OTG1_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_OTG1_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDR1_PUP_STATUS_MASK (0x20U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDR1_PUP_STATUS_SHIFT (5U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDR1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_DDR1_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_DDR1_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPUMIX_PUP_STATUS_MASK (0x80U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPUMIX_PUP_STATUS_SHIFT (7U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPUMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_GPUMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_GPUMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_DISPMIX_PUP_STATUS_MASK (0x400U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DISPMIX_PUP_STATUS_SHIFT (10U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DISPMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_DISPMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_DISPMIX_PUP_STATUS_MASK)
/*! @} */

/*! @name M7_PU_PGC_PUP_STATUS - M7 PU PGC software up trigger status register */
/*! @{ */

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY_PUP_STATUS_MASK (0x1U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY_PUP_STATUS_SHIFT (0U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_OTG1_PUP_STATUS_MASK (0x4U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_OTG1_PUP_STATUS_SHIFT (2U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_OTG1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_OTG1_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_OTG1_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDR1_PUP_STATUS_MASK (0x20U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDR1_PUP_STATUS_SHIFT (5U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDR1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_DDR1_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_DDR1_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPUMIX_PUP_STATUS_MASK (0x80U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPUMIX_PUP_STATUS_SHIFT (7U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPUMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_GPUMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_GPUMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_DISPMIX_PUP_STATUS_MASK (0x400U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DISPMIX_PUP_STATUS_SHIFT (10U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DISPMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_DISPMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_DISPMIX_PUP_STATUS_MASK)
/*! @} */

/*! @name CPU_PGC_PDN_STATUS1 - CPU PGC software dn trigger status1 */
/*! @{ */

#define GPC_CPU_PGC_PDN_STATUS1_CORE0_A53_PDN_STATUS_MASK (0x1U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE0_A53_PDN_STATUS_SHIFT (0U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE0_A53_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PDN_STATUS1_CORE0_A53_PDN_STATUS_SHIFT)) & GPC_CPU_PGC_PDN_STATUS1_CORE0_A53_PDN_STATUS_MASK)

#define GPC_CPU_PGC_PDN_STATUS1_CORE1_A53_PDN_STATUS_MASK (0x2U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE1_A53_PDN_STATUS_SHIFT (1U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE1_A53_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PDN_STATUS1_CORE1_A53_PDN_STATUS_SHIFT)) & GPC_CPU_PGC_PDN_STATUS1_CORE1_A53_PDN_STATUS_MASK)

#define GPC_CPU_PGC_PDN_STATUS1_CORE2_A53_PDN_STATUS_MASK (0x4U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE2_A53_PDN_STATUS_SHIFT (2U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE2_A53_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PDN_STATUS1_CORE2_A53_PDN_STATUS_SHIFT)) & GPC_CPU_PGC_PDN_STATUS1_CORE2_A53_PDN_STATUS_MASK)

#define GPC_CPU_PGC_PDN_STATUS1_CORE3_A53_PDN_STATUS_MASK (0x8U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE3_A53_PDN_STATUS_SHIFT (3U)
#define GPC_CPU_PGC_PDN_STATUS1_CORE3_A53_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PDN_STATUS1_CORE3_A53_PDN_STATUS_SHIFT)) & GPC_CPU_PGC_PDN_STATUS1_CORE3_A53_PDN_STATUS_MASK)

#define GPC_CPU_PGC_PDN_STATUS1_SCU_A53_PDN_REQ_MASK (0x10U)
#define GPC_CPU_PGC_PDN_STATUS1_SCU_A53_PDN_REQ_SHIFT (4U)
#define GPC_CPU_PGC_PDN_STATUS1_SCU_A53_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_CPU_PGC_PDN_STATUS1_SCU_A53_PDN_REQ_SHIFT)) & GPC_CPU_PGC_PDN_STATUS1_SCU_A53_PDN_REQ_MASK)
/*! @} */

/*! @name A53_MIX_PGC_PDN_STATUS - A53 MIX software down trigger status register */
/*! @{ */

#define GPC_A53_MIX_PGC_PDN_STATUS_A53_MIX_PGC_PDN_STATUS_MASK (0x1U)
#define GPC_A53_MIX_PGC_PDN_STATUS_A53_MIX_PGC_PDN_STATUS_SHIFT (0U)
#define GPC_A53_MIX_PGC_PDN_STATUS_A53_MIX_PGC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_MIX_PGC_PDN_STATUS_A53_MIX_PGC_PDN_STATUS_SHIFT)) & GPC_A53_MIX_PGC_PDN_STATUS_A53_MIX_PGC_PDN_STATUS_MASK)
/*! @} */

/*! @name M7_MIX_PGC_PDN_STATUS - M7 MIX PGC software power down trigger status register */
/*! @{ */

#define GPC_M7_MIX_PGC_PDN_STATUS_M7_MIX_PGC_PDN_STATUS_MASK (0x1U)
#define GPC_M7_MIX_PGC_PDN_STATUS_M7_MIX_PGC_PDN_STATUS_SHIFT (0U)
#define GPC_M7_MIX_PGC_PDN_STATUS_M7_MIX_PGC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_MIX_PGC_PDN_STATUS_M7_MIX_PGC_PDN_STATUS_SHIFT)) & GPC_M7_MIX_PGC_PDN_STATUS_M7_MIX_PGC_PDN_STATUS_MASK)
/*! @} */

/*! @name A53_PU_PGC_PDN_STATUS - A53 PU PGC software down trigger status */
/*! @{ */

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY_PDN_STATUS_MASK (0x1U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY_PDN_STATUS_SHIFT (0U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_OTG1_PDN_STATUS_MASK (0x4U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_OTG1_PDN_STATUS_SHIFT (2U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_OTG1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_OTG1_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_OTG1_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDR1_PDN_STATUS_MASK (0x20U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDR1_PDN_STATUS_SHIFT (5U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDR1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_DDR1_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_DDR1_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPUMIX_PDN_STATUS_MASK (0x80U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPUMIX_PDN_STATUS_SHIFT (7U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPUMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_GPUMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_GPUMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_DISPMIX_PDN_STATUS_MASK (0x400U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DISPMIX_PDN_STATUS_SHIFT (10U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DISPMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_DISPMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_DISPMIX_PDN_STATUS_MASK)
/*! @} */

/*! @name M7_PU_PGC_PDN_STATUS - M7 PU PGC software down trigger status */
/*! @{ */

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY_PDN_STATUS_MASK (0x1U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY_PDN_STATUS_SHIFT (0U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_OTG1_PDN_STATUS_MASK (0x4U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_OTG1_PDN_STATUS_SHIFT (2U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_OTG1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_OTG1_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_OTG1_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDR1_PDN_STATUS_MASK (0x20U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDR1_PDN_STATUS_SHIFT (5U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDR1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_DDR1_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_DDR1_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPUMIX_PDN_STATUS_MASK (0x80U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPUMIX_PDN_STATUS_SHIFT (7U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPUMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_GPUMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_GPUMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_DISPMIX_PDN_STATUS_MASK (0x400U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DISPMIX_PDN_STATUS_SHIFT (10U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DISPMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_DISPMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_DISPMIX_PDN_STATUS_MASK)
/*! @} */

/*! @name A53_MIX_PDN_FLG - A53 MIX PDN FLG */
/*! @{ */

#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_MASK (0x1U)
#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_SHIFT (0U)
#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_SHIFT)) & GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_MASK)
/*! @} */

/*! @name A53_PU_PDN_FLG - A53 PU PDN FLG */
/*! @{ */

#define GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG_MASK   (0x3FFFU)
#define GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG_SHIFT  (0U)
#define GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG(x)     (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG_SHIFT)) & GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG_MASK)
/*! @} */

/*! @name M7_MIX_PDN_FLG - M7 MIX PDN FLG */
/*! @{ */

#define GPC_M7_MIX_PDN_FLG_M7_MIX_PDN_FLAG_MASK  (0x1U)
#define GPC_M7_MIX_PDN_FLG_M7_MIX_PDN_FLAG_SHIFT (0U)
#define GPC_M7_MIX_PDN_FLG_M7_MIX_PDN_FLAG(x)    (((uint32_t)(((uint32_t)(x)) << GPC_M7_MIX_PDN_FLG_M7_MIX_PDN_FLAG_SHIFT)) & GPC_M7_MIX_PDN_FLG_M7_MIX_PDN_FLAG_MASK)
/*! @} */

/*! @name M7_PU_PDN_FLG - M7 PU PDN FLG */
/*! @{ */

#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_MASK     (0x3FFFU)
#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_SHIFT    (0U)
#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_SHIFT)) & GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_MASK)
/*! @} */

/*! @name IMR_CORE2_A53 - IRQ masking register 1 of A53 core2..IRQ masking register 4 of A53 core2 */
/*! @{ */

#define GPC_IMR_CORE2_A53_IMR1_CORE2_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE2_A53_IMR1_CORE2_A53_SHIFT   (0U)
/*! IMR1_CORE2_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE2_A53_IMR1_CORE2_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE2_A53_IMR1_CORE2_A53_SHIFT)) & GPC_IMR_CORE2_A53_IMR1_CORE2_A53_MASK)

#define GPC_IMR_CORE2_A53_IMR2_CORE2_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE2_A53_IMR2_CORE2_A53_SHIFT   (0U)
/*! IMR2_CORE2_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE2_A53_IMR2_CORE2_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE2_A53_IMR2_CORE2_A53_SHIFT)) & GPC_IMR_CORE2_A53_IMR2_CORE2_A53_MASK)

#define GPC_IMR_CORE2_A53_IMR3_CORE2_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE2_A53_IMR3_CORE2_A53_SHIFT   (0U)
/*! IMR3_CORE2_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE2_A53_IMR3_CORE2_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE2_A53_IMR3_CORE2_A53_SHIFT)) & GPC_IMR_CORE2_A53_IMR3_CORE2_A53_MASK)

#define GPC_IMR_CORE2_A53_IMR4_CORE2_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE2_A53_IMR4_CORE2_A53_SHIFT   (0U)
/*! IMR4_CORE2_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE2_A53_IMR4_CORE2_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE2_A53_IMR4_CORE2_A53_SHIFT)) & GPC_IMR_CORE2_A53_IMR4_CORE2_A53_MASK)
/*! @} */

/*! @name IMR_CORE3_A53 - IRQ masking register 1 of A53 core3..IRQ masking register 4 of A53 core3 */
/*! @{ */

#define GPC_IMR_CORE3_A53_IMR1_CORE3_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE3_A53_IMR1_CORE3_A53_SHIFT   (0U)
/*! IMR1_CORE3_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE3_A53_IMR1_CORE3_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE3_A53_IMR1_CORE3_A53_SHIFT)) & GPC_IMR_CORE3_A53_IMR1_CORE3_A53_MASK)

#define GPC_IMR_CORE3_A53_IMR2_CORE3_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE3_A53_IMR2_CORE3_A53_SHIFT   (0U)
/*! IMR2_CORE3_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE3_A53_IMR2_CORE3_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE3_A53_IMR2_CORE3_A53_SHIFT)) & GPC_IMR_CORE3_A53_IMR2_CORE3_A53_MASK)

#define GPC_IMR_CORE3_A53_IMR3_CORE3_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE3_A53_IMR3_CORE3_A53_SHIFT   (0U)
/*! IMR3_CORE3_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE3_A53_IMR3_CORE3_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE3_A53_IMR3_CORE3_A53_SHIFT)) & GPC_IMR_CORE3_A53_IMR3_CORE3_A53_MASK)

#define GPC_IMR_CORE3_A53_IMR4_CORE3_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE3_A53_IMR4_CORE3_A53_SHIFT   (0U)
/*! IMR4_CORE3_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE3_A53_IMR4_CORE3_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE3_A53_IMR4_CORE3_A53_SHIFT)) & GPC_IMR_CORE3_A53_IMR4_CORE3_A53_MASK)
/*! @} */

/*! @name ACK_SEL_A53_PU - PGC acknowledge signal selection of A53 platform for PUs */
/*! @{ */

#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PDN_ACK_MASK (0x4U)
#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MIPI_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MIPI_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PDN_ACK_MASK (0x80U)
#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PDN_ACK_SHIFT (7U)
#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_DDR1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_DDR1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PDN_ACK_MASK (0x200U)
#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PDN_ACK_SHIFT (9U)
#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PDN_ACK_MASK (0x1000U)
#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PDN_ACK_SHIFT (12U)
#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PUP_ACK_MASK (0x40000U)
#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PUP_ACK_SHIFT (18U)
#define GPC_ACK_SEL_A53_PU_MIPI_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MIPI_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MIPI_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PUP_ACK_MASK (0x100000U)
#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PUP_ACK_SHIFT (20U)
#define GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB_OTG1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PUP_ACK_MASK (0x800000U)
#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PUP_ACK_SHIFT (23U)
#define GPC_ACK_SEL_A53_PU_DDR1_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_DDR1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_DDR1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PUP_ACK_MASK (0x2000000U)
#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PUP_ACK_SHIFT (25U)
#define GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPUMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PUP_ACK_MASK (0x10000000U)
#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PUP_ACK_SHIFT (28U)
#define GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_DISPMIX_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name ACK_SEL_M7_PU - PGC acknowledge signal selection of M7 platform for PUs */
/*! @{ */

#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PDN_ACK_MASK  (0x4U)
#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PDN_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MIPI_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MIPI_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PDN_ACK_MASK  (0x80U)
#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PDN_ACK_SHIFT (7U)
#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PDN_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_DDR1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_DDR1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PDN_ACK_MASK (0x200U)
#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PDN_ACK_SHIFT (9U)
#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PDN_ACK_MASK (0x1000U)
#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PDN_ACK_SHIFT (12U)
#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PUP_ACK_MASK  (0x40000U)
#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PUP_ACK_SHIFT (18U)
#define GPC_ACK_SEL_M7_PU_MIPI_PGC_PUP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MIPI_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MIPI_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PUP_ACK_MASK (0x100000U)
#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PUP_ACK_SHIFT (20U)
#define GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB_OTG1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PUP_ACK_MASK  (0x800000U)
#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PUP_ACK_SHIFT (23U)
#define GPC_ACK_SEL_M7_PU_DDR1_PGC_PUP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_DDR1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_DDR1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PUP_ACK_MASK (0x2000000U)
#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PUP_ACK_SHIFT (25U)
#define GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPUMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PUP_ACK_MASK (0x10000000U)
#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PUP_ACK_SHIFT (28U)
#define GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_DISPMIX_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name SLT15_CFG - Slot configure register for PGC CPUs */
/*! @{ */

#define GPC_SLT15_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT15_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT15_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT15_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT15_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT15_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT15_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT15_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT15_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT15_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT15_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT15_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT15_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT15_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT15_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT15_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT15_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT15_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT15_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT15_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT15_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT15_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT15_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT15_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT15_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT15_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT15_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT15_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT16_CFG - Slot configure register for PGC CPUs */
/*! @{ */

#define GPC_SLT16_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT16_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT16_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT16_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT16_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT16_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT16_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT16_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT16_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT16_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT16_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT16_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT16_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT16_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT16_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT16_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT16_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT16_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT16_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT16_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT16_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT16_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT16_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT16_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT16_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT16_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT16_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT16_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT17_CFG - Slot configure register for PGC CPUs */
/*! @{ */

#define GPC_SLT17_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT17_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT17_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT17_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT17_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT17_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT17_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT17_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT17_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT17_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT17_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT17_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT17_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT17_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT17_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT17_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT17_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT17_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT17_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT17_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT17_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT17_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT17_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT17_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT17_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT17_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT17_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT17_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT18_CFG - Slot configure register for PGC CPUs */
/*! @{ */

#define GPC_SLT18_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT18_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT18_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT18_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT18_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT18_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT18_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT18_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT18_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT18_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT18_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT18_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT18_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT18_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT18_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT18_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT18_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT18_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT18_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT18_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT18_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT18_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT18_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT18_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT18_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT18_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT18_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT18_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT19_CFG - Slot configure register for PGC CPUs */
/*! @{ */

#define GPC_SLT19_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT19_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT19_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT19_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT19_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT19_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT19_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT19_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT19_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT19_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT19_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT19_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT19_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT19_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT19_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT19_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT19_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_SCU_PDN_SLOT_CONTROL_MASK  (0x100U)
#define GPC_SLT19_CFG_SCU_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT19_CFG_SCU_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_SCU_PUP_SLOT_CONTROL_MASK  (0x200U)
#define GPC_SLT19_CFG_SCU_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT19_CFG_SCU_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_NOC_PDN_SLOT_CONTROL_MASK  (0x400U)
#define GPC_SLT19_CFG_NOC_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT19_CFG_NOC_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT19_CFG_NOC_PUP_SLOT_CONTROL_MASK  (0x800U)
#define GPC_SLT19_CFG_NOC_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT19_CFG_NOC_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT19_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT19_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name PU_PWRHSK - Power handshake register */
/*! @{ */

#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_MASK (0x1U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_SHIFT (0U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_MASK  (0x2U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_SHIFT (1U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2DDR_PWRDNREQN_MASK (0x4U)
#define GPC_PU_PWRHSK_GPC_NOC2DDR_PWRDNREQN_SHIFT (2U)
#define GPC_PU_PWRHSK_GPC_NOC2DDR_PWRDNREQN(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2DDR_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2DDR_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_MASK (0x8U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_SHIFT (3U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_MASK (0x10U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_SHIFT (4U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNREQN_MASK (0x20U)
#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNREQN_SHIFT (5U)
#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNREQN_MASK (0x80U)
#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNREQN_SHIFT (7U)
#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_GPUPMIX2NOC_PWRDNREQN_MASK (0x200U)
#define GPC_PU_PWRHSK_GPC_GPUPMIX2NOC_PWRDNREQN_SHIFT (9U)
#define GPC_PU_PWRHSK_GPC_GPUPMIX2NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_GPUPMIX2NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_GPUPMIX2NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2GPUPMIX_PWRDNREQN_MASK (0x800U)
#define GPC_PU_PWRHSK_GPC_NOC2GPUPMIX_PWRDNREQN_SHIFT (11U)
#define GPC_PU_PWRHSK_GPC_NOC2GPUPMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2GPUPMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2GPUPMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSACK_MASK (0x10000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSACK_SHIFT (16U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSACK_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSACK_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CACTIVE_MASK (0x20000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CACTIVE_SHIFT (17U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CACTIVE(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CORE_CACTIVE_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CORE_CACTIVE_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSACK_MASK  (0x40000U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSACK_SHIFT (18U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSACK_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSACK_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CACTIVE_MASK  (0x80000U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CACTIVE_SHIFT (19U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CACTIVE(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_AXI_CACTIVE_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_AXI_CACTIVE_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2DDR1_PWRDNACKN_MASK (0x100000U)
#define GPC_PU_PWRHSK_GPC_NOC2DDR1_PWRDNACKN_SHIFT (20U)
#define GPC_PU_PWRHSK_GPC_NOC2DDR1_PWRDNACKN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2DDR1_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2DDR1_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNACKN_MASK (0x200000U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNACKN_SHIFT (21U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNACKN_MASK (0x400000U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNACKN_SHIFT (22U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNACKN_MASK (0x800000U)
#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNACKN_SHIFT (23U)
#define GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_HSIOMIX2NOC_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNACKN_MASK (0x2000000U)
#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNACKN_SHIFT (25U)
#define GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_DISPMIX2NOC_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_GPUMIX2NOC_PWRDNACKN_MASK (0x8000000U)
#define GPC_PU_PWRHSK_GPC_GPUMIX2NOC_PWRDNACKN_SHIFT (27U)
#define GPC_PU_PWRHSK_GPC_GPUMIX2NOC_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_GPUMIX2NOC_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_GPUMIX2NOC_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2GPUMIX_PWRDNACKN_MASK (0x20000000U)
#define GPC_PU_PWRHSK_GPC_NOC2GPUMIX_PWRDNACKN_SHIFT (29U)
#define GPC_PU_PWRHSK_GPC_NOC2GPUMIX_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2GPUMIX_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2GPUMIX_PWRDNACKN_MASK)
/*! @} */

/*! @name SLT_CFG_PU - Slot configure register for PGC PUs */
/*! @{ */

#define GPC_SLT_CFG_PU_MIPI_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT_CFG_PU_MIPI_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT_CFG_PU_MIPI_PDN_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MIPI_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MIPI_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MIPI_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT_CFG_PU_MIPI_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT_CFG_PU_MIPI_PUP_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MIPI_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MIPI_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_OTG1_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT_CFG_PU_OTG1_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT_CFG_PU_OTG1_PDN_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_OTG1_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_OTG1_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_OTG1_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT_CFG_PU_OTG1_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT_CFG_PU_OTG1_PUP_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_OTG1_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_OTG1_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_M7_PDN_SLOT_CONTROL_MASK  (0x1000U)
#define GPC_SLT_CFG_PU_M7_PDN_SLOT_CONTROL_SHIFT (12U)
#define GPC_SLT_CFG_PU_M7_PDN_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_M7_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_M7_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_M7_PUP_SLOT_CONTROL_MASK  (0x2000U)
#define GPC_SLT_CFG_PU_M7_PUP_SLOT_CONTROL_SHIFT (13U)
#define GPC_SLT_CFG_PU_M7_PUP_SLOT_CONTROL(x)    (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_M7_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_M7_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_DDR1_PDN_SLOT_CONTROL_MASK (0x4000U)
#define GPC_SLT_CFG_PU_DDR1_PDN_SLOT_CONTROL_SHIFT (14U)
#define GPC_SLT_CFG_PU_DDR1_PDN_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_DDR1_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_DDR1_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_DDR1_PUP_SLOT_CONTROL_MASK (0x8000U)
#define GPC_SLT_CFG_PU_DDR1_PUP_SLOT_CONTROL_SHIFT (15U)
#define GPC_SLT_CFG_PU_DDR1_PUP_SLOT_CONTROL(x)  (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_DDR1_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_DDR1_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPUMIX_PDN_SLOT_CONTROL_MASK (0x40000U)
#define GPC_SLT_CFG_PU_GPUMIX_PDN_SLOT_CONTROL_SHIFT (18U)
#define GPC_SLT_CFG_PU_GPUMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPUMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPUMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPUMIX_PUP_SLOT_CONTROL_MASK (0x80000U)
#define GPC_SLT_CFG_PU_GPUMIX_PUP_SLOT_CONTROL_SHIFT (19U)
#define GPC_SLT_CFG_PU_GPUMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPUMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPUMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_DISPMIX_PDN_SLOT_CONTROL_MASK (0x1000000U)
#define GPC_SLT_CFG_PU_DISPMIX_PDN_SLOT_CONTROL_SHIFT (24U)
#define GPC_SLT_CFG_PU_DISPMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_DISPMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_DISPMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_DISPMIX_PUP_SLOT_CONTROL_MASK (0x2000000U)
#define GPC_SLT_CFG_PU_DISPMIX_PUP_SLOT_CONTROL_SHIFT (25U)
#define GPC_SLT_CFG_PU_DISPMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_DISPMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_DISPMIX_PUP_SLOT_CONTROL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_H_ */

