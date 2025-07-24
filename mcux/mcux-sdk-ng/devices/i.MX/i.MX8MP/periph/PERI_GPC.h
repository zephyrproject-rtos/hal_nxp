/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
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
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC
 *
 * CMSIS Peripheral Access Layer for GPC
 */

#if !defined(PERI_GPC_H_)
#define PERI_GPC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
#define GPC_IMR_CORE0_A53_COUNT                   5u
#define GPC_IMR_CORE1_A53_COUNT                   5u
#define GPC_IMR_M7_COUNT                          5u
#define GPC_ISR_A53_COUNT                         5u
#define GPC_ISR_M7_COUNT                          5u
#define GPC_A53_MIX_PGC_PUP_STATUS_COUNT          3u
#define GPC_M7_MIX_PGC_PUP_STATUS_COUNT           3u
#define GPC_A53_PU_PGC_PUP_STATUS_COUNT           3u
#define GPC_M7_PU_PGC_PUP_STATUS_COUNT            3u
#define GPC_A53_MIX_PGC_PDN_STATUS_COUNT          3u
#define GPC_M7_MIX_PGC_PDN_STATUS_COUNT           3u
#define GPC_A53_PU_PGC_PDN_STATUS_COUNT           3u
#define GPC_M7_PU_PGC_PDN_STATUS_COUNT            3u
#define GPC_IMR_CORE2_A53_COUNT                   5u
#define GPC_IMR_CORE3_A53_COUNT                   5u
#define GPC_SLT_CFG_COUNT                         27u
#define GPC_SLTn_CFG_PU_COUNT                     27u

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
  __IO uint32_t IMR_CORE0_A53[GPC_IMR_CORE0_A53_COUNT]; /**< IRQ masking register 1 of A53 core0..IRQ masking register 5 of A53 core0, array offset: 0x30, array step: 0x4 */
  __IO uint32_t IMR_CORE1_A53[GPC_IMR_CORE1_A53_COUNT]; /**< IRQ masking register 1 of A53 core1..IRQ masking register 5 of A53 core1, array offset: 0x44, array step: 0x4 */
  __IO uint32_t IMR_M7[GPC_IMR_M7_COUNT];          /**< IRQ masking register 1 of M7..IRQ masking register 5 of M7, array offset: 0x58, array step: 0x4 */
       uint8_t RESERVED_2[20];
  __I  uint32_t ISR_A53[GPC_ISR_A53_COUNT];        /**< IRQ status register 1 of A53..IRQ status register 5 of A53, array offset: 0x80, array step: 0x4 */
  __I  uint32_t ISR_M7[GPC_ISR_M7_COUNT];          /**< IRQ status register 1 of M7..IRQ status register 5 of M7, array offset: 0x94, array step: 0x4 */
       uint8_t RESERVED_3[40];
  __IO uint32_t CPU_PGC_SW_PUP_REQ;                /**< CPU PGC software power up trigger, offset: 0xD0 */
  __IO uint32_t MIX_PGC_SW_PUP_REQ;                /**< MIX PGC software power up trigger, offset: 0xD4 */
  __IO uint32_t PU_PGC_SW_PUP_REQ;                 /**< PU PGC software up trigger, offset: 0xD8 */
  __IO uint32_t CPU_PGC_SW_PDN_REQ;                /**< CPU PGC software down trigger, offset: 0xDC */
  __IO uint32_t MIX_PGC_SW_PDN_REQ;                /**< MIX PGC software power down trigger, offset: 0xE0 */
  __IO uint32_t PU_PGC_SW_PDN_REQ;                 /**< PU PGC software down trigger, offset: 0xE4 */
       uint8_t RESERVED_4[32];
  __I  uint32_t CPU_PGC_PUP_STATUS1;               /**< CPU PGC software up trigger status1, offset: 0x108 */
  __I  uint32_t A53_MIX_PGC_PUP_STATUS[GPC_A53_MIX_PGC_PUP_STATUS_COUNT]; /**< A53 MIX software up trigger status register, array offset: 0x10C, array step: 0x4 */
  __I  uint32_t M7_MIX_PGC_PUP_STATUS[GPC_M7_MIX_PGC_PUP_STATUS_COUNT]; /**< M7 MIX PGC software up trigger status register, array offset: 0x118, array step: 0x4 */
  __I  uint32_t A53_PU_PGC_PUP_STATUS[GPC_A53_PU_PGC_PUP_STATUS_COUNT]; /**< A53 PU software up trigger status register, array offset: 0x124, array step: 0x4 */
  __I  uint32_t M7_PU_PGC_PUP_STATUS[GPC_M7_PU_PGC_PUP_STATUS_COUNT]; /**< M7 PU PGC software up trigger status register, array offset: 0x130, array step: 0x4 */
  __I  uint32_t CPU_PGC_PDN_STATUS1;               /**< CPU PGC software dn trigger status1, offset: 0x13C */
  __I  uint32_t A53_MIX_PGC_PDN_STATUS[GPC_A53_MIX_PGC_PDN_STATUS_COUNT]; /**< A53 MIX software down trigger status register, array offset: 0x140, array step: 0x4 */
  __I  uint32_t M7_MIX_PGC_PDN_STATUS[GPC_M7_MIX_PGC_PDN_STATUS_COUNT]; /**< M7 MIX PGC software power down trigger status register, array offset: 0x14C, array step: 0x4 */
  __I  uint32_t A53_PU_PGC_PDN_STATUS[GPC_A53_PU_PGC_PDN_STATUS_COUNT]; /**< A53 PU PGC software down trigger status, array offset: 0x158, array step: 0x4 */
  __I  uint32_t M7_PU_PGC_PDN_STATUS[GPC_M7_PU_PGC_PDN_STATUS_COUNT]; /**< M7 PU PGC software down trigger status, array offset: 0x164, array step: 0x4 */
  __IO uint32_t A53_MIX_PDN_FLG;                   /**< A53 MIX PDN FLG, offset: 0x170 */
  __IO uint32_t A53_PU_PDN_FLG;                    /**< A53 PU PDN FLG, offset: 0x174 */
  __IO uint32_t M7_MIX_PDN_FLG;                    /**< M7 MIX PDN FLG, offset: 0x178 */
  __IO uint32_t M7_PU_PDN_FLG;                     /**< M7 PU PDN FLG, offset: 0x17C */
  __IO uint32_t LPCR_A53_BSC2;                     /**< Basic Low power control register of A53 platform, offset: 0x180 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PU_PWRHSK;                         /**< Power handshake register, offset: 0x190 */
  __IO uint32_t IMR_CORE2_A53[GPC_IMR_CORE2_A53_COUNT]; /**< IRQ masking register 1 of A53 core2..IRQ masking register 5 of A53 core2, array offset: 0x194, array step: 0x4 */
  __IO uint32_t IMR_CORE3_A53[GPC_IMR_CORE3_A53_COUNT]; /**< IRQ masking register 1 of A53 core3..IRQ masking register 5 of A53 core3, array offset: 0x1A8, array step: 0x4 */
  __IO uint32_t ACK_SEL_A53_PU;                    /**< PGC acknowledge signal selection of A53 platform for PUs, offset: 0x1BC */
  __IO uint32_t ACK_SEL_A53_PU1;                   /**< PGC acknowledge signal selection of A53 platform for PUs, offset: 0x1C0 */
  __IO uint32_t ACK_SEL_M7_PU;                     /**< PGC acknowledge signal selection of M7 platform for PUs, offset: 0x1C4 */
  __IO uint32_t ACK_SEL_M7_PU1;                    /**< PGC acknowledge signal selection of M7 platform for PUs, offset: 0x1C8 */
  __IO uint32_t PGC_CPU_A53_MAPPING;               /**< PGC CPU A53 mapping, offset: 0x1CC */
  __IO uint32_t PGC_CPU_M7_MAPPING;                /**< PGC CPU M7 mapping, offset: 0x1D0 */
       uint8_t RESERVED_6[44];
  __IO uint32_t SLT_CFG[GPC_SLT_CFG_COUNT];        /**< Slot configure register for CPUs, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_7[20];
  struct {                                         /* offset: 0x280, array step: 0x8 */
    __IO uint32_t SLT_CFG_PU;                        /**< Slot configure register for PGC PUs, array offset: 0x280, array step: 0x8 */
    __IO uint32_t SLT_CFG_PU1;                       /**< Extended slot configure register for PGC PUs, array offset: 0x284, array step: 0x8 */
  } SLTn_CFG_PU[GPC_SLTn_CFG_PU_COUNT];
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
/*! MST1_CPU_MAPPING - MASTER1 CPU Mapping
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

#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_MASK (0x2U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_SHIFT (1U)
#define GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C0_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_MASK (0x4U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_SHIFT (2U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_MASK (0x8U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_SHIFT (3U)
#define GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C1_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_MASK (0x10U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_SHIFT (4U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_MASK (0x20U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_SHIFT (5U)
#define GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C2_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_MASK (0x40U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_SHIFT (6U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_MASK (0x80U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_SHIFT (7U)
#define GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_C3_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_MASK (0x100U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_SHIFT (8U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_MASK (0x200U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_SHIFT (9U)
#define GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PLAT_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_MASK (0x1000U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_SHIFT (12U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_NOC_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_MASK (0x2000U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_SHIFT (13U)
#define GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_NOC_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_MASK (0x40000000U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_SHIFT (30U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_MASK (0x80000000U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_SHIFT (31U)
#define GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_A53_A53_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name PGC_ACK_SEL_M7 - PGC acknowledge signal selection of M7 platform */
/*! @{ */

#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_MASK (0x1U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_SHIFT (0U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_MASK (0x2U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_SHIFT (1U)
#define GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_VIRTUAL_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_MASK  (0x1000U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_SHIFT (12U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_NOC_PGC_PDN_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_MASK  (0x2000U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_SHIFT (13U)
#define GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_NOC_PGC_PUP_ACK_MASK)

#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_MASK (0x40000000U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_SHIFT (30U)
#define GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_SHIFT)) & GPC_PGC_ACK_SEL_M7_M7_DUMMY_PGC_PDN_ACK_MASK)

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

#define GPC_MISC_MIPI_LDO_EN_CTRL_MASK           (0x80000000U)
#define GPC_MISC_MIPI_LDO_EN_CTRL_SHIFT          (31U)
#define GPC_MISC_MIPI_LDO_EN_CTRL(x)             (((uint32_t)(((uint32_t)(x)) << GPC_MISC_MIPI_LDO_EN_CTRL_SHIFT)) & GPC_MISC_MIPI_LDO_EN_CTRL_MASK)
/*! @} */

/*! @name IMR_CORE0_A53 - IRQ masking register 1 of A53 core0..IRQ masking register 5 of A53 core0 */
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

#define GPC_IMR_CORE0_A53_IMR5_CORE0_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE0_A53_IMR5_CORE0_A53_SHIFT   (0U)
/*! IMR5_CORE0_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE0_A53_IMR5_CORE0_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE0_A53_IMR5_CORE0_A53_SHIFT)) & GPC_IMR_CORE0_A53_IMR5_CORE0_A53_MASK)
/*! @} */

/*! @name IMR_CORE1_A53 - IRQ masking register 1 of A53 core1..IRQ masking register 5 of A53 core1 */
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

#define GPC_IMR_CORE1_A53_IMR5_CORE1_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE1_A53_IMR5_CORE1_A53_SHIFT   (0U)
/*! IMR5_CORE1_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE1_A53_IMR5_CORE1_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE1_A53_IMR5_CORE1_A53_SHIFT)) & GPC_IMR_CORE1_A53_IMR5_CORE1_A53_MASK)
/*! @} */

/*! @name IMR_M7 - IRQ masking register 1 of M7..IRQ masking register 5 of M7 */
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

#define GPC_IMR_M7_IMR5_M7_MASK                  (0xFFFFFFFFU)
#define GPC_IMR_M7_IMR5_M7_SHIFT                 (0U)
/*! IMR5_M7
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_M7_IMR5_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_IMR_M7_IMR5_M7_SHIFT)) & GPC_IMR_M7_IMR5_M7_MASK)
/*! @} */

/*! @name ISR_A53 - IRQ status register 1 of A53..IRQ status register 5 of A53 */
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

#define GPC_ISR_A53_ISR5_A53_MASK                (0xFFFFFFFFU)
#define GPC_ISR_A53_ISR5_A53_SHIFT               (0U)
#define GPC_ISR_A53_ISR5_A53(x)                  (((uint32_t)(((uint32_t)(x)) << GPC_ISR_A53_ISR5_A53_SHIFT)) & GPC_ISR_A53_ISR5_A53_MASK)
/*! @} */

/*! @name ISR_M7 - IRQ status register 1 of M7..IRQ status register 5 of M7 */
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

#define GPC_ISR_M7_ISR5_M7_MASK                  (0xFFFFFFFFU)
#define GPC_ISR_M7_ISR5_M7_SHIFT                 (0U)
#define GPC_ISR_M7_ISR5_M7(x)                    (((uint32_t)(((uint32_t)(x)) << GPC_ISR_M7_ISR5_M7_SHIFT)) & GPC_ISR_M7_ISR5_M7_MASK)
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

#define GPC_MIX_PGC_SW_PUP_REQ_MF_SW_PUP_REQ_MASK (0x1U)
#define GPC_MIX_PGC_SW_PUP_REQ_MF_SW_PUP_REQ_SHIFT (0U)
#define GPC_MIX_PGC_SW_PUP_REQ_MF_SW_PUP_REQ(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PUP_REQ_MF_SW_PUP_REQ_SHIFT)) & GPC_MIX_PGC_SW_PUP_REQ_MF_SW_PUP_REQ_MASK)

#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_MASK (0x2U)
#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_SHIFT (1U)
#define GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_SHIFT)) & GPC_MIX_PGC_SW_PUP_REQ_NOC_SW_PUP_REQ_MASK)
/*! @} */

/*! @name PU_PGC_SW_PUP_REQ - PU PGC software up trigger */
/*! @{ */

#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY1_SW_PUP_REQ_MASK (0x1U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY1_SW_PUP_REQ_SHIFT (0U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY1_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY1_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY1_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_PCIE_PHY_SW_PUP_REQ_MASK (0x2U)
#define GPC_PU_PGC_SW_PUP_REQ_PCIE_PHY_SW_PUP_REQ_SHIFT (1U)
#define GPC_PU_PGC_SW_PUP_REQ_PCIE_PHY_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_PCIE_PHY_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_PCIE_PHY_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_USB1_PHY_SW_PUP_REQ_MASK (0x4U)
#define GPC_PU_PGC_SW_PUP_REQ_USB1_PHY_SW_PUP_REQ_SHIFT (2U)
#define GPC_PU_PGC_SW_PUP_REQ_USB1_PHY_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_USB1_PHY_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_USB1_PHY_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_USB2_PHY_SW_PUP_REQ_MASK (0x8U)
#define GPC_PU_PGC_SW_PUP_REQ_USB2_PHY_SW_PUP_REQ_SHIFT (3U)
#define GPC_PU_PGC_SW_PUP_REQ_USB2_PHY_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_USB2_PHY_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_USB2_PHY_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_MLMIX_PHY_SW_PUP_REQ_MASK (0x10U)
#define GPC_PU_PGC_SW_PUP_REQ_MLMIX_PHY_SW_PUP_REQ_SHIFT (4U)
#define GPC_PU_PGC_SW_PUP_REQ_MLMIX_PHY_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MLMIX_PHY_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MLMIX_PHY_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_AUDIOMIX_SW_PUP_REQ_MASK (0x20U)
#define GPC_PU_PGC_SW_PUP_REQ_AUDIOMIX_SW_PUP_REQ_SHIFT (5U)
#define GPC_PU_PGC_SW_PUP_REQ_AUDIOMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_AUDIOMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_AUDIOMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_GPU_2D_SW_PUP_REQ_MASK (0x40U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_2D_SW_PUP_REQ_SHIFT (6U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_2D_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_GPU_2D_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_GPU_2D_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_GPU_SHARE_LOGIC_SW_PUP_REQ_MASK (0x80U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_SHARE_LOGIC_SW_PUP_REQ_SHIFT (7U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_SHARE_LOGIC_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_GPU_SHARE_LOGIC_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_GPU_SHARE_LOGIC_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_VPUMIX_SW_PUP_REQ_MASK (0x100U)
#define GPC_PU_PGC_SW_PUP_REQ_VPUMIX_SW_PUP_REQ_SHIFT (8U)
#define GPC_PU_PGC_SW_PUP_REQ_VPUMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_VPUMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_VPUMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_GPU_3D_SW_PUP_REQ_MASK (0x200U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_3D_SW_PUP_REQ_SHIFT (9U)
#define GPC_PU_PGC_SW_PUP_REQ_GPU_3D_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_GPU_3D_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_GPU_3D_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_MEDIMIX_SW_PUP_REQ_MASK (0x400U)
#define GPC_PU_PGC_SW_PUP_REQ_MEDIMIX_SW_PUP_REQ_SHIFT (10U)
#define GPC_PU_PGC_SW_PUP_REQ_MEDIMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MEDIMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MEDIMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_VPU_G1_SW_PUP_REQ_MASK (0x800U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_G1_SW_PUP_REQ_SHIFT (11U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_G1_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_VPU_G1_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_VPU_G1_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_VPU_G2_SW_PUP_REQ_MASK (0x1000U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_G2_SW_PUP_REQ_SHIFT (12U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_G2_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_VPU_G2_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_VPU_G2_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_VPU_VC8K_SW_PUP_REQ_MASK (0x2000U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_VC8K_SW_PUP_REQ_SHIFT (13U)
#define GPC_PU_PGC_SW_PUP_REQ_VPU_VC8K_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_VPU_VC8K_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_VPU_VC8K_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_HDMIMIX_SW_PUP_REQ_MASK (0x4000U)
#define GPC_PU_PGC_SW_PUP_REQ_HDMIMIX_SW_PUP_REQ_SHIFT (14U)
#define GPC_PU_PGC_SW_PUP_REQ_HDMIMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_HDMIMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_HDMIMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_HDMI_PHY_SW_PUP_REQ_MASK (0x8000U)
#define GPC_PU_PGC_SW_PUP_REQ_HDMI_PHY_SW_PUP_REQ_SHIFT (15U)
#define GPC_PU_PGC_SW_PUP_REQ_HDMI_PHY_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_HDMI_PHY_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_HDMI_PHY_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY2_SW_PUP_REQ_MASK (0x10000U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY2_SW_PUP_REQ_SHIFT (16U)
#define GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY2_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY2_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MIPI_PHY2_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_HSIOMIX_SW_PUP_REQ_MASK (0x20000U)
#define GPC_PU_PGC_SW_PUP_REQ_HSIOMIX_SW_PUP_REQ_SHIFT (17U)
#define GPC_PU_PGC_SW_PUP_REQ_HSIOMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_HSIOMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_HSIOMIX_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_MEDIA_ISP_DWP_SW_PUP_REQ_MASK (0x40000U)
#define GPC_PU_PGC_SW_PUP_REQ_MEDIA_ISP_DWP_SW_PUP_REQ_SHIFT (18U)
#define GPC_PU_PGC_SW_PUP_REQ_MEDIA_ISP_DWP_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_MEDIA_ISP_DWP_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_MEDIA_ISP_DWP_SW_PUP_REQ_MASK)

#define GPC_PU_PGC_SW_PUP_REQ_DDRMIX_SW_PUP_REQ_MASK (0x80000U)
#define GPC_PU_PGC_SW_PUP_REQ_DDRMIX_SW_PUP_REQ_SHIFT (19U)
#define GPC_PU_PGC_SW_PUP_REQ_DDRMIX_SW_PUP_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PUP_REQ_DDRMIX_SW_PUP_REQ_SHIFT)) & GPC_PU_PGC_SW_PUP_REQ_DDRMIX_SW_PUP_REQ_MASK)
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

#define GPC_MIX_PGC_SW_PDN_REQ_MF_SW_PDN_REQ_MASK (0x1U)
#define GPC_MIX_PGC_SW_PDN_REQ_MF_SW_PDN_REQ_SHIFT (0U)
#define GPC_MIX_PGC_SW_PDN_REQ_MF_SW_PDN_REQ(x)  (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PDN_REQ_MF_SW_PDN_REQ_SHIFT)) & GPC_MIX_PGC_SW_PDN_REQ_MF_SW_PDN_REQ_MASK)

#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_MASK (0x2U)
#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_SHIFT (1U)
#define GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_SHIFT)) & GPC_MIX_PGC_SW_PDN_REQ_NOC_SW_PDN_REQ_MASK)
/*! @} */

/*! @name PU_PGC_SW_PDN_REQ - PU PGC software down trigger */
/*! @{ */

#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY1_SW_PDN_REQ_MASK (0x1U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY1_SW_PDN_REQ_SHIFT (0U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY1_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY1_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY1_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_PCIE_PHY_SW_PDN_REQ_MASK (0x2U)
#define GPC_PU_PGC_SW_PDN_REQ_PCIE_PHY_SW_PDN_REQ_SHIFT (1U)
#define GPC_PU_PGC_SW_PDN_REQ_PCIE_PHY_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_PCIE_PHY_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_PCIE_PHY_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_USB1_PHY_SW_PDN_REQ_MASK (0x4U)
#define GPC_PU_PGC_SW_PDN_REQ_USB1_PHY_SW_PDN_REQ_SHIFT (2U)
#define GPC_PU_PGC_SW_PDN_REQ_USB1_PHY_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_USB1_PHY_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_USB1_PHY_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_USB2_PHY_SW_PDN_REQ_MASK (0x8U)
#define GPC_PU_PGC_SW_PDN_REQ_USB2_PHY_SW_PDN_REQ_SHIFT (3U)
#define GPC_PU_PGC_SW_PDN_REQ_USB2_PHY_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_USB2_PHY_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_USB2_PHY_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_MLMIX_SW_PDN_REQ_MASK (0x10U)
#define GPC_PU_PGC_SW_PDN_REQ_MLMIX_SW_PDN_REQ_SHIFT (4U)
#define GPC_PU_PGC_SW_PDN_REQ_MLMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MLMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MLMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_AUDIOMIX_SW_PDN_REQ_MASK (0x20U)
#define GPC_PU_PGC_SW_PDN_REQ_AUDIOMIX_SW_PDN_REQ_SHIFT (5U)
#define GPC_PU_PGC_SW_PDN_REQ_AUDIOMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_AUDIOMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_AUDIOMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_GPU_2D_SW_PDN_REQ_MASK (0x40U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_2D_SW_PDN_REQ_SHIFT (6U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_2D_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_GPU_2D_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_GPU_2D_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_GPU_SHARE_LOGIC_SW_PDN_REQ_MASK (0x80U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_SHARE_LOGIC_SW_PDN_REQ_SHIFT (7U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_SHARE_LOGIC_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_GPU_SHARE_LOGIC_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_GPU_SHARE_LOGIC_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_VPUMIX_SHARE_LOGIC_SW_PDN_REQ_MASK (0x100U)
#define GPC_PU_PGC_SW_PDN_REQ_VPUMIX_SHARE_LOGIC_SW_PDN_REQ_SHIFT (8U)
#define GPC_PU_PGC_SW_PDN_REQ_VPUMIX_SHARE_LOGIC_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_VPUMIX_SHARE_LOGIC_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_VPUMIX_SHARE_LOGIC_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_GPU_3D_SW_PDN_REQ_MASK (0x200U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_3D_SW_PDN_REQ_SHIFT (9U)
#define GPC_PU_PGC_SW_PDN_REQ_GPU_3D_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_GPU_3D_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_GPU_3D_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_MEDIMIX_SW_PDN_REQ_MASK (0x400U)
#define GPC_PU_PGC_SW_PDN_REQ_MEDIMIX_SW_PDN_REQ_SHIFT (10U)
#define GPC_PU_PGC_SW_PDN_REQ_MEDIMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MEDIMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MEDIMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_VPU_G1_SW_PDN_REQ_MASK (0x800U)
#define GPC_PU_PGC_SW_PDN_REQ_VPU_G1_SW_PDN_REQ_SHIFT (11U)
#define GPC_PU_PGC_SW_PDN_REQ_VPU_G1_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_VPU_G1_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_VPU_G1_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ__SW_PDN_REQ_MASK   (0x1000U)
#define GPC_PU_PGC_SW_PDN_REQ__SW_PDN_REQ_SHIFT  (12U)
#define GPC_PU_PGC_SW_PDN_REQ__SW_PDN_REQ(x)     (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ__SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ__SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_VPU_VC8K_SW_PDN_REQ_MASK (0x2000U)
#define GPC_PU_PGC_SW_PDN_REQ_VPU_VC8K_SW_PDN_REQ_SHIFT (13U)
#define GPC_PU_PGC_SW_PDN_REQ_VPU_VC8K_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_VPU_VC8K_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_VPU_VC8K_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_HDMIMIX_SW_PDN_REQ_MASK (0x4000U)
#define GPC_PU_PGC_SW_PDN_REQ_HDMIMIX_SW_PDN_REQ_SHIFT (14U)
#define GPC_PU_PGC_SW_PDN_REQ_HDMIMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_HDMIMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_HDMIMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_HDMI_PHY_SW_PDN_REQ_MASK (0x8000U)
#define GPC_PU_PGC_SW_PDN_REQ_HDMI_PHY_SW_PDN_REQ_SHIFT (15U)
#define GPC_PU_PGC_SW_PDN_REQ_HDMI_PHY_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_HDMI_PHY_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_HDMI_PHY_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY2_SW_PDN_REQ_MASK (0x10000U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY2_SW_PDN_REQ_SHIFT (16U)
#define GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY2_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY2_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MIPI_PHY2_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_HSIOMIX_SW_PDN_REQ_MASK (0x20000U)
#define GPC_PU_PGC_SW_PDN_REQ_HSIOMIX_SW_PDN_REQ_SHIFT (17U)
#define GPC_PU_PGC_SW_PDN_REQ_HSIOMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_HSIOMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_HSIOMIX_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_MEDIA_ISP_DWP_SW_PDN_REQ_MASK (0x40000U)
#define GPC_PU_PGC_SW_PDN_REQ_MEDIA_ISP_DWP_SW_PDN_REQ_SHIFT (18U)
#define GPC_PU_PGC_SW_PDN_REQ_MEDIA_ISP_DWP_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_MEDIA_ISP_DWP_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_MEDIA_ISP_DWP_SW_PDN_REQ_MASK)

#define GPC_PU_PGC_SW_PDN_REQ_DDRMIX_SW_PDN_REQ_MASK (0x80000U)
#define GPC_PU_PGC_SW_PDN_REQ_DDRMIX_SW_PDN_REQ_SHIFT (19U)
#define GPC_PU_PGC_SW_PDN_REQ_DDRMIX_SW_PDN_REQ(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PGC_SW_PDN_REQ_DDRMIX_SW_PDN_REQ_SHIFT)) & GPC_PU_PGC_SW_PDN_REQ_DDRMIX_SW_PDN_REQ_MASK)
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

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY1_PUP_STATUS_MASK (0x1U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY1_PUP_STATUS_SHIFT (0U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY1_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY1_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_PCIE_PHY_PUP_STATUS_MASK (0x2U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_PCIE_PHY_PUP_STATUS_SHIFT (1U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_PCIE_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_PCIE_PHY_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_PCIE_PHY_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB1_PHY_PUP_STATUS_MASK (0x4U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB1_PHY_PUP_STATUS_SHIFT (2U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB1_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_USB1_PHY_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_USB1_PHY_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB2_PHY_PUP_STATUS_MASK (0x8U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB2_PHY_PUP_STATUS_SHIFT (3U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_USB2_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_USB2_PHY_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_USB2_PHY_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MLMIX_PUP_STATUS_MASK (0x10U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MLMIX_PUP_STATUS_SHIFT (4U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MLMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MLMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MLMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_AUDIOMIX_PUP_STATUS_MASK (0x20U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_AUDIOMIX_PUP_STATUS_SHIFT (5U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_AUDIOMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_AUDIOMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_AUDIOMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_2D_PUP_STATUS_MASK (0x40U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_2D_PUP_STATUS_SHIFT (6U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_2D_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_2D_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_2D_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_SHARE_LOGIC_PUP_STATUS_MASK (0x80U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_SHARE_LOGIC_PUP_STATUS_SHIFT (7U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_SHARE_LOGIC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_SHARE_LOGIC_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_SHARE_LOGIC_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPUMIX_SHARE_LOGIC_PUP_STATUS_MASK (0x100U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPUMIX_SHARE_LOGIC_PUP_STATUS_SHIFT (8U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPUMIX_SHARE_LOGIC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_VPUMIX_SHARE_LOGIC_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_VPUMIX_SHARE_LOGIC_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_3D_PUP_STATUS_MASK (0x200U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_3D_PUP_STATUS_SHIFT (9U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_3D_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_3D_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_GPU_3D_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIMIX_PUP_STATUS_MASK (0x400U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIMIX_PUP_STATUS_SHIFT (10U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G1_PUP_STATUS_MASK (0x800U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G1_PUP_STATUS_SHIFT (11U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G1_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G1_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G2_PUP_STATUS_MASK (0x1000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G2_PUP_STATUS_SHIFT (12U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G2_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G2_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_G2_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_VC8K_PUP_STATUS_MASK (0x2000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_VC8K_PUP_STATUS_SHIFT (13U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_VC8K_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_VC8K_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_VPU_VC8K_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMIMIX_PUP_STATUS_MASK (0x4000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMIMIX_PUP_STATUS_SHIFT (14U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMIMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_HDMIMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_HDMIMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMI_PHY_PUP_STATUS_MASK (0x8000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMI_PHY_PUP_STATUS_SHIFT (15U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HDMI_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_HDMI_PHY_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_HDMI_PHY_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY2_PUP_STATUS_MASK (0x10000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY2_PUP_STATUS_SHIFT (16U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY2_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY2_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MIPI_PHY2_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_HSIOMIX_PUP_STATUS_MASK (0x20000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HSIOMIX_PUP_STATUS_SHIFT (17U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_HSIOMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_HSIOMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_HSIOMIX_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIA_ISP_DWP_PUP_STATUS_MASK (0x40000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIA_ISP_DWP_PUP_STATUS_SHIFT (18U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIA_ISP_DWP_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIA_ISP_DWP_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_MEDIA_ISP_DWP_PUP_STATUS_MASK)

#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDRMIX_PUP_STATUS_MASK (0x80000U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDRMIX_PUP_STATUS_SHIFT (19U)
#define GPC_A53_PU_PGC_PUP_STATUS_A53_DDRMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PUP_STATUS_A53_DDRMIX_PUP_STATUS_SHIFT)) & GPC_A53_PU_PGC_PUP_STATUS_A53_DDRMIX_PUP_STATUS_MASK)
/*! @} */

/*! @name M7_PU_PGC_PUP_STATUS - M7 PU PGC software up trigger status register */
/*! @{ */

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY1_PUP_STATUS_MASK (0x1U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY1_PUP_STATUS_SHIFT (0U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY1_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY1_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_PCIE_PHY_PUP_STATUS_MASK (0x2U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_PCIE_PHY_PUP_STATUS_SHIFT (1U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_PCIE_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_PCIE_PHY_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_PCIE_PHY_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB1_PHY_PUP_STATUS_MASK (0x4U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB1_PHY_PUP_STATUS_SHIFT (2U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB1_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_USB1_PHY_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_USB1_PHY_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB2_PHY_PUP_STATUS_MASK (0x8U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB2_PHY_PUP_STATUS_SHIFT (3U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_USB2_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_USB2_PHY_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_USB2_PHY_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MLMIX_PUP_STATUS_MASK (0x10U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MLMIX_PUP_STATUS_SHIFT (4U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MLMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MLMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MLMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_AUDIOMIX_PUP_STATUS_MASK (0x20U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_AUDIOMIX_PUP_STATUS_SHIFT (5U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_AUDIOMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_AUDIOMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_AUDIOMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU2D_PUP_STATUS_MASK (0x40U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU2D_PUP_STATUS_SHIFT (6U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU2D_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_GPU2D_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_GPU2D_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU_SHARE_LOGIC_PUP_STATUS_MASK (0x80U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU_SHARE_LOGIC_PUP_STATUS_SHIFT (7U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU_SHARE_LOGIC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_GPU_SHARE_LOGIC_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_GPU_SHARE_LOGIC_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPUMIX_SHARE_LOGIC_PUP_STATUS_MASK (0x100U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPUMIX_SHARE_LOGIC_PUP_STATUS_SHIFT (8U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPUMIX_SHARE_LOGIC_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_VPUMIX_SHARE_LOGIC_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_VPUMIX_SHARE_LOGIC_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU3D_PUP_STATUS_MASK (0x200U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU3D_PUP_STATUS_SHIFT (9U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_GPU3D_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_GPU3D_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_GPU3D_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIMIX_PUP_STATUS_MASK (0x400U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIMIX_PUP_STATUS_SHIFT (10U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G1_PUP_STATUS_MASK (0x800U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G1_PUP_STATUS_SHIFT (11U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G1_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G1_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G1_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G2_PUP_STATUS_MASK (0x1000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G2_PUP_STATUS_SHIFT (12U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G2_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G2_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_G2_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_VC8K_PUP_STATUS_MASK (0x2000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_VC8K_PUP_STATUS_SHIFT (13U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_VC8K_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_VC8K_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_VPU_VC8K_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMIMIX_PUP_STATUS_MASK (0x4000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMIMIX_PUP_STATUS_SHIFT (14U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMIMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_HDMIMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_HDMIMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMI_PHY_PUP_STATUS_MASK (0x8000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMI_PHY_PUP_STATUS_SHIFT (15U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HDMI_PHY_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_HDMI_PHY_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_HDMI_PHY_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY2_PUP_STATUS_MASK (0x10000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY2_PUP_STATUS_SHIFT (16U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY2_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY2_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MIPI_PHY2_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_HSIOMIX_PUP_STATUS_MASK (0x20000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HSIOMIX_PUP_STATUS_SHIFT (17U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_HSIOMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_HSIOMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_HSIOMIX_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIA_ISP_DWP_PUP_STATUS_MASK (0x40000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIA_ISP_DWP_PUP_STATUS_SHIFT (18U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIA_ISP_DWP_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIA_ISP_DWP_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_MEDIA_ISP_DWP_PUP_STATUS_MASK)

#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDRMIX_PUP_STATUS_MASK (0x80000U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDRMIX_PUP_STATUS_SHIFT (19U)
#define GPC_M7_PU_PGC_PUP_STATUS_M7_DDRMIX_PUP_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PUP_STATUS_M7_DDRMIX_PUP_STATUS_SHIFT)) & GPC_M7_PU_PGC_PUP_STATUS_M7_DDRMIX_PUP_STATUS_MASK)
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

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY1_PDN_STATUS_MASK (0x1U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY1_PDN_STATUS_SHIFT (0U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY1_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY1_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_PCIEPHY_PDN_STATUS_MASK (0x2U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_PCIEPHY_PDN_STATUS_SHIFT (1U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_PCIEPHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_PCIEPHY_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_PCIEPHY_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB1_PHY_PDN_STATUS_MASK (0x4U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB1_PHY_PDN_STATUS_SHIFT (2U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB1_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_USB1_PHY_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_USB1_PHY_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB2_PHY_PDN_STATUS_MASK (0x8U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB2_PHY_PDN_STATUS_SHIFT (3U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_USB2_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_USB2_PHY_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_USB2_PHY_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MLMIX_PDN_STATUS_MASK (0x10U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MLMIX_PDN_STATUS_SHIFT (4U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MLMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MLMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MLMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_AUDIOMIX_PDN_STATUS_MASK (0x20U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_AUDIOMIX_PDN_STATUS_SHIFT (5U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_AUDIOMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_AUDIOMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_AUDIOMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_2D_PDN_STATUS_MASK (0x40U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_2D_PDN_STATUS_SHIFT (6U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_2D_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_2D_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_2D_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_SHARE_LOGIC_PDN_STATUS_MASK (0x80U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_SHARE_LOGIC_PDN_STATUS_SHIFT (7U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_SHARE_LOGIC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_SHARE_LOGIC_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_SHARE_LOGIC_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPUMIX_SHARE_LOGIC_PDN_STATUS_MASK (0x100U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPUMIX_SHARE_LOGIC_PDN_STATUS_SHIFT (8U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPUMIX_SHARE_LOGIC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_VPUMIX_SHARE_LOGIC_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_VPUMIX_SHARE_LOGIC_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_3D_PDN_STATUS_MASK (0x200U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_3D_PDN_STATUS_SHIFT (9U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_3D_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_3D_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_GPU_3D_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIMIX_PDN_STATUS_MASK (0x400U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIMIX_PDN_STATUS_SHIFT (10U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G1_PDN_STATUS_MASK (0x800U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G1_PDN_STATUS_SHIFT (11U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G1_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G1_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G2_PDN_STATUS_MASK (0x1000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G2_PDN_STATUS_SHIFT (12U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G2_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G2_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_G2_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_VC8K_PDN_STATUS_MASK (0x2000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_VC8K_PDN_STATUS_SHIFT (13U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_VC8K_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_VC8K_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_VPU_VC8K_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMIMIX_PDN_STATUS_MASK (0x4000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMIMIX_PDN_STATUS_SHIFT (14U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMIMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_HDMIMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_HDMIMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMI_PHY_PDN_STATUS_MASK (0x8000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMI_PHY_PDN_STATUS_SHIFT (15U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HDMI_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_HDMI_PHY_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_HDMI_PHY_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY2_PDN_STATUS_MASK (0x10000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY2_PDN_STATUS_SHIFT (16U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY2_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY2_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MIPI_PHY2_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_HSIOMIX_PDN_STATUS_MASK (0x20000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HSIOMIX_PDN_STATUS_SHIFT (17U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_HSIOMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_HSIOMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_HSIOMIX_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIA_ISP_DWP_PDN_STATUS_MASK (0x40000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIA_ISP_DWP_PDN_STATUS_SHIFT (18U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIA_ISP_DWP_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIA_ISP_DWP_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_MEDIA_ISP_DWP_PDN_STATUS_MASK)

#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDRMIX_PDN_STATUS_MASK (0x80000U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDRMIX_PDN_STATUS_SHIFT (19U)
#define GPC_A53_PU_PGC_PDN_STATUS_A53_DDRMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_A53_PU_PGC_PDN_STATUS_A53_DDRMIX_PDN_STATUS_SHIFT)) & GPC_A53_PU_PGC_PDN_STATUS_A53_DDRMIX_PDN_STATUS_MASK)
/*! @} */

/*! @name M7_PU_PGC_PDN_STATUS - M7 PU PGC software down trigger status */
/*! @{ */

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY1_PDN_STATUS_MASK (0x1U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY1_PDN_STATUS_SHIFT (0U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY1_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY1_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_PCIE_PHY_PDN_STATUS_MASK (0x2U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_PCIE_PHY_PDN_STATUS_SHIFT (1U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_PCIE_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_PCIE_PHY_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_PCIE_PHY_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB1_PHY_PDN_STATUS_MASK (0x4U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB1_PHY_PDN_STATUS_SHIFT (2U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB1_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_USB1_PHY_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_USB1_PHY_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB2_PHY_PDN_STATUS_MASK (0x8U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB2_PHY_PDN_STATUS_SHIFT (3U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_USB2_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_USB2_PHY_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_USB2_PHY_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MLMIX_PDN_STATUS_MASK (0x10U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MLMIX_PDN_STATUS_SHIFT (4U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MLMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MLMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MLMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_AUDIOMIX_PDN_STATUS_MASK (0x20U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_AUDIOMIX_PDN_STATUS_SHIFT (5U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_AUDIOMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_AUDIOMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_AUDIOMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_2D_PDN_STATUS_MASK (0x40U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_2D_PDN_STATUS_SHIFT (6U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_2D_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_2D_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_2D_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_SHARE_LOGIC_PDN_STATUS_MASK (0x80U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_SHARE_LOGIC_PDN_STATUS_SHIFT (7U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_SHARE_LOGIC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_SHARE_LOGIC_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_GPU_SHARE_LOGIC_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPUMIX_SHARE_LOGIC_PDN_STATUS_MASK (0x100U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPUMIX_SHARE_LOGIC_PDN_STATUS_SHIFT (8U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPUMIX_SHARE_LOGIC_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_VPUMIX_SHARE_LOGIC_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_VPUMIX_SHARE_LOGIC_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU3D_PDN_STATUS_MASK (0x200U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU3D_PDN_STATUS_SHIFT (9U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_GPU3D_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_GPU3D_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_GPU3D_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIMIX_PDN_STATUS_MASK (0x400U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIMIX_PDN_STATUS_SHIFT (10U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G1_PDN_STATUS_MASK (0x800U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G1_PDN_STATUS_SHIFT (11U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G1_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G1_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G1_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G2_PDN_STATUS_MASK (0x1000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G2_PDN_STATUS_SHIFT (12U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G2_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G2_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_G2_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_VC8K_PDN_STATUS_MASK (0x2000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_VC8K_PDN_STATUS_SHIFT (13U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_VC8K_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_VC8K_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_VPU_VC8K_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMIMIX_PDN_STATUS_MASK (0x4000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMIMIX_PDN_STATUS_SHIFT (14U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMIMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_HDMIMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_HDMIMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMI_PHY_PDN_STATUS_MASK (0x8000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMI_PHY_PDN_STATUS_SHIFT (15U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HDMI_PHY_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_HDMI_PHY_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_HDMI_PHY_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY2_PDN_STATUS_MASK (0x10000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY2_PDN_STATUS_SHIFT (16U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY2_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY2_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MIPI_PHY2_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_HSIOMIX_PDN_STATUS_MASK (0x20000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HSIOMIX_PDN_STATUS_SHIFT (17U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_HSIOMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_HSIOMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_HSIOMIX_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIA_ISP_DWP_PDN_STATUS_MASK (0x40000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIA_ISP_DWP_PDN_STATUS_SHIFT (18U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIA_ISP_DWP_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIA_ISP_DWP_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_MEDIA_ISP_DWP_PDN_STATUS_MASK)

#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDRMIX_PDN_STATUS_MASK (0x80000U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDRMIX_PDN_STATUS_SHIFT (19U)
#define GPC_M7_PU_PGC_PDN_STATUS_M7_DDRMIX_PDN_STATUS(x) (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PGC_PDN_STATUS_M7_DDRMIX_PDN_STATUS_SHIFT)) & GPC_M7_PU_PGC_PDN_STATUS_M7_DDRMIX_PDN_STATUS_MASK)
/*! @} */

/*! @name A53_MIX_PDN_FLG - A53 MIX PDN FLG */
/*! @{ */

#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_MASK (0x1U)
#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_SHIFT (0U)
#define GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG(x)  (((uint32_t)(((uint32_t)(x)) << GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_SHIFT)) & GPC_A53_MIX_PDN_FLG_A53_MIX_PDN_FLAG_MASK)
/*! @} */

/*! @name A53_PU_PDN_FLG - A53 PU PDN FLG */
/*! @{ */

#define GPC_A53_PU_PDN_FLG_A53_PU_PDN_FLG_MASK   (0xFFFFFU)
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

#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_MASK     (0xFFFFFU)
#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_SHIFT    (0U)
#define GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_SHIFT)) & GPC_M7_PU_PDN_FLG_M7_PU_PDN_FLG_MASK)
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

/*! @name PU_PWRHSK - Power handshake register */
/*! @{ */

#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_MASK (0x1U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_SHIFT (0U)
#define GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CORE_CSYSREQ_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_MASK  (0x2U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_SHIFT (1U)
#define GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_AXI_CSYSREQ_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWRDNREQN_MASK (0x10U)
#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWRDNREQN_SHIFT (4U)
#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_MASK (0x20U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_SHIFT (5U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_MASK (0x40U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_SHIFT (6U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNREQN_MASK (0x80U)
#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNREQN_SHIFT (7U)
#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWRDNREQN_MASK (0x100U)
#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWRDNREQN_SHIFT (8U)
#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNREQN_MASK (0x200U)
#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNREQN_SHIFT (9U)
#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_VPUMIX_NOC_PWRDNREQN_MASK (0x400U)
#define GPC_PU_PWRHSK_GPC_VPUMIX_NOC_PWRDNREQN_SHIFT (10U)
#define GPC_PU_PWRHSK_GPC_VPUMIX_NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_VPUMIX_NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_VPUMIX_NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNREQN_MASK (0x800U)
#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNREQN_SHIFT (11U)
#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWRDNREQN_MASK (0x1000U)
#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWRDNREQN_SHIFT (12U)
#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNREQN_MASK (0x2000U)
#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNREQN_SHIFT (13U)
#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNREQN_MASK (0x4000U)
#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNREQN_SHIFT (14U)
#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_AUDIOMIX_NOC_PWRDNREQN_MASK (0x8000U)
#define GPC_PU_PWRHSK_GPC_AUDIOMIX_NOC_PWRDNREQN_SHIFT (15U)
#define GPC_PU_PWRHSK_GPC_AUDIOMIX_NOC_PWRDNREQN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_AUDIOMIX_NOC_PWRDNREQN_SHIFT)) & GPC_PU_PWRHSK_GPC_AUDIOMIX_NOC_PWRDNREQN_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_LWPWACKN_MASK (0x10000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_LWPWACKN_SHIFT (16U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_LWPWACKN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CTRL_LWPWACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CTRL_LWPWACKN_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_CLKACTIVE_MASK (0x20000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_CLKACTIVE_SHIFT (17U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_CLKACTIVE(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CTRL_CLKACTIVE_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CTRL_CLKACTIVE_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_REQACK_MASK  (0x40000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_REQACK_SHIFT (18U)
#define GPC_PU_PWRHSK_GPC_DDR1_CTRL_REQACK(x)    (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CTRL_REQACK_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CTRL_REQACK_MASK)

#define GPC_PU_PWRHSK_GPC_DDR1_CACTIVE_MASK      (0x80000U)
#define GPC_PU_PWRHSK_GPC_DDR1_CACTIVE_SHIFT     (19U)
#define GPC_PU_PWRHSK_GPC_DDR1_CACTIVE(x)        (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_DDR1_CACTIVE_SHIFT)) & GPC_PU_PWRHSK_GPC_DDR1_CACTIVE_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWDWNACKN_MASK (0x100000U)
#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWDWNACKN_SHIFT (20U)
#define GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2AUDIOMIX_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_ADBS_PWDWNACKN_MASK (0x200000U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_ADBS_PWDWNACKN_SHIFT (21U)
#define GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_ADBS_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_ADBS_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2SUPERMIX_ADBS_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_ADBS_PWDWNACKN_MASK (0x400000U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_ADBS_PWDWNACKN_SHIFT (22U)
#define GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_ADBS_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_ADBS_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_SUPERMIX2NOC_ADBS_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNACKN_MASK (0x800000U)
#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNACKN_SHIFT (23U)
#define GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_MLMIX_ADBS_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWDWNACKN_MASK (0x1000000U)
#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWDWNACKN_SHIFT (24U)
#define GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2MLMIX_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNACKN_MASK (0x2000000U)
#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNACKN_SHIFT (25U)
#define GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_GPUMIX_NOC_ADBS_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_VPUMIX_NOX_PWDWNACKN_MASK (0x4000000U)
#define GPC_PU_PWRHSK_GPC_VPUMIX_NOX_PWDWNACKN_SHIFT (26U)
#define GPC_PU_PWRHSK_GPC_VPUMIX_NOX_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_VPUMIX_NOX_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_VPUMIX_NOX_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNACKN_MASK (0x8000000U)
#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNACKN_SHIFT (27U)
#define GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2DDRMIX_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWDWNACKN_MASK (0x10000000U)
#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWDWNACKN_SHIFT (28U)
#define GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWDWNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWDWNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_NOC2HSIO_ADBS_PWDWNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNACKN_MASK (0x20000000U)
#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNACKN_SHIFT (29U)
#define GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_HDMIMIX_NOC_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNACKN_MASK (0x40000000U)
#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNACKN_SHIFT (30U)
#define GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNACKN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_MEDIAMIX_NOC_ADBS_PWRDNACKN_MASK)

#define GPC_PU_PWRHSK_GPC_AUDIOMIX_PWRDNACKN_MASK (0x80000000U)
#define GPC_PU_PWRHSK_GPC_AUDIOMIX_PWRDNACKN_SHIFT (31U)
#define GPC_PU_PWRHSK_GPC_AUDIOMIX_PWRDNACKN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PU_PWRHSK_GPC_AUDIOMIX_PWRDNACKN_SHIFT)) & GPC_PU_PWRHSK_GPC_AUDIOMIX_PWRDNACKN_MASK)
/*! @} */

/*! @name IMR_CORE2_A53 - IRQ masking register 1 of A53 core2..IRQ masking register 5 of A53 core2 */
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

#define GPC_IMR_CORE2_A53_IMR5_CORE2_A53_MASK    (0xFFFFFFFFU)
#define GPC_IMR_CORE2_A53_IMR5_CORE2_A53_SHIFT   (0U)
/*! IMR5_CORE2_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE2_A53_IMR5_CORE2_A53(x)      (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE2_A53_IMR5_CORE2_A53_SHIFT)) & GPC_IMR_CORE2_A53_IMR5_CORE2_A53_MASK)
/*! @} */

/*! @name IMR_CORE3_A53 - IRQ masking register 1 of A53 core3..IRQ masking register 5 of A53 core3 */
/*! @{ */

#define GPC_IMR_CORE3_A53_IM5_CORE3_A53_MASK     (0xFFFFFFFFU)
#define GPC_IMR_CORE3_A53_IM5_CORE3_A53_SHIFT    (0U)
/*! IM5_CORE3_A53
 *  0b00000000000000000000000000000000..IRQ not masked
 *  0b00000000000000000000000000000001..IRQ masked
 */
#define GPC_IMR_CORE3_A53_IM5_CORE3_A53(x)       (((uint32_t)(((uint32_t)(x)) << GPC_IMR_CORE3_A53_IM5_CORE3_A53_SHIFT)) & GPC_IMR_CORE3_A53_IM5_CORE3_A53_MASK)

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

#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PDN_ACK_MASK (0x1U)
#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PDN_ACK_SHIFT (0U)
#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PUP_ACK_MASK (0x2U)
#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PUP_ACK_SHIFT (1U)
#define GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MIPI_PHY1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PDN_ACK_MASK (0x4U)
#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PUP_ACK_MASK (0x8U)
#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PUP_ACK_SHIFT (3U)
#define GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_PCIE_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PUP_ACK_MASK (0x20U)
#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PUP_ACK_SHIFT (5U)
#define GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB1_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PDN_ACK_MASK (0x40U)
#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PDN_ACK_SHIFT (6U)
#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PUP_ACK_MASK (0x80U)
#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PUP_ACK_SHIFT (7U)
#define GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_USB2_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PDN_ACK_MASK (0x100U)
#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PDN_ACK_SHIFT (8U)
#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MLMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MLMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PUP_ACK_MASK (0x200U)
#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PUP_ACK_SHIFT (9U)
#define GPC_ACK_SEL_A53_PU_MLMIX_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MLMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MLMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PDN_ACK_MASK (0x400U)
#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PDN_ACK_SHIFT (10U)
#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PUP_ACK_MASK (0x800U)
#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PUP_ACK_SHIFT (11U)
#define GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_AUDIOMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PDN_ACK_MASK (0x1000U)
#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PDN_ACK_SHIFT (12U)
#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PUP_ACK_MASK (0x2000U)
#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PUP_ACK_SHIFT (13U)
#define GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU_2D_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_MASK (0x4000U)
#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_SHIFT (14U)
#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_MASK (0x8000U)
#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_SHIFT (15U)
#define GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_MASK (0x10000U)
#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_SHIFT (16U)
#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_MASK (0x20000U)
#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_SHIFT (17U)
#define GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PDN_ACK_MASK (0x40000U)
#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PDN_ACK_SHIFT (18U)
#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU3D_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU3D_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PUP_ACK_MASK (0x80000U)
#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PUP_ACK_SHIFT (19U)
#define GPC_ACK_SEL_A53_PU_GPU3D_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_GPU3D_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_GPU3D_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PDN_ACK_MASK (0x100000U)
#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PDN_ACK_SHIFT (20U)
#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PUP_ACK_MASK (0x200000U)
#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PUP_ACK_SHIFT (21U)
#define GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_MEDIMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PDN_ACK_MASK (0x400000U)
#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PDN_ACK_SHIFT (22U)
#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PUP_ACK_MASK (0x800000U)
#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PUP_ACK_SHIFT (23U)
#define GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_G1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PDN_ACK_MASK (0x1000000U)
#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PDN_ACK_SHIFT (24U)
#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PUP_ACK_MASK (0x2000000U)
#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PUP_ACK_SHIFT (25U)
#define GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_G2_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PDN_ACK_MASK (0x4000000U)
#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PDN_ACK_SHIFT (26U)
#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PUP_ACK_MASK (0x8000000U)
#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PUP_ACK_SHIFT (27U)
#define GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_VPU_VC8K_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PDN_ACK_MASK (0x10000000U)
#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PDN_ACK_SHIFT (28U)
#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PUP_ACK_MASK (0x20000000U)
#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PUP_ACK_SHIFT (29U)
#define GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_HDMIMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PDN_ACK_MASK (0x40000000U)
#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PDN_ACK_SHIFT (30U)
#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PUP_ACK_MASK (0x80000000U)
#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PUP_ACK_SHIFT (31U)
#define GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU_HDMI_PHY_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name ACK_SEL_A53_PU1 - PGC acknowledge signal selection of A53 platform for PUs */
/*! @{ */

#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PDN_ACK_MASK (0x1U)
#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PDN_ACK_SHIFT (0U)
#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PUP_ACK_MASK (0x2U)
#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PUP_ACK_SHIFT (1U)
#define GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_MIPI_PHY2_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PDN_ACK_MASK (0x4U)
#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PUP_ACK_MASK (0x8U)
#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PUP_ACK_SHIFT (3U)
#define GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_HSIOMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_MASK (0x20U)
#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_SHIFT (5U)
#define GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PDN_ACK_MASK (0x40U)
#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PDN_ACK_SHIFT (6U)
#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PUP_ACK_MASK (0x80U)
#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PUP_ACK_SHIFT (7U)
#define GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_A53_PU1_DDRMIX_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name ACK_SEL_M7_PU - PGC acknowledge signal selection of M7 platform for PUs */
/*! @{ */

#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PDN_ACK_MASK (0x1U)
#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PDN_ACK_SHIFT (0U)
#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PUP_ACK_MASK (0x2U)
#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PUP_ACK_SHIFT (1U)
#define GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MIPI_PHY1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PDN_ACK_MASK (0x4U)
#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PUP_ACK_MASK (0x8U)
#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PUP_ACK_SHIFT (3U)
#define GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_PCIE_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PUP_ACK_MASK (0x20U)
#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PUP_ACK_SHIFT (5U)
#define GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB1_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PDN_ACK_MASK (0x40U)
#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PDN_ACK_SHIFT (6U)
#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PUP_ACK_MASK (0x80U)
#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PUP_ACK_SHIFT (7U)
#define GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_USB2_PHY_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PDN_ACK_MASK (0x100U)
#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PDN_ACK_SHIFT (8U)
#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MLMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MLMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PUP_ACK_MASK (0x200U)
#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PUP_ACK_SHIFT (9U)
#define GPC_ACK_SEL_M7_PU_MLMIX_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MLMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MLMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PDN_ACK_MASK (0x400U)
#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PDN_ACK_SHIFT (10U)
#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PUP_ACK_MASK (0x800U)
#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PUP_ACK_SHIFT (11U)
#define GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_AUDIOMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PDN_ACK_MASK (0x1000U)
#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PDN_ACK_SHIFT (12U)
#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PUP_ACK_MASK (0x2000U)
#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PUP_ACK_SHIFT (13U)
#define GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU_2D_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_MASK (0x4000U)
#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_SHIFT (14U)
#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_MASK (0x8000U)
#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_SHIFT (15U)
#define GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU_SHARE_LOGIC_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_MASK (0x10000U)
#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_SHIFT (16U)
#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_MASK (0x20000U)
#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_SHIFT (17U)
#define GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPUMIX_SHARE_LOGIC_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PDN_ACK_MASK (0x40000U)
#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PDN_ACK_SHIFT (18U)
#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PDN_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU3D_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU3D_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PUP_ACK_MASK (0x80000U)
#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PUP_ACK_SHIFT (19U)
#define GPC_ACK_SEL_M7_PU_GPU3D_PGC_PUP_ACK(x)   (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_GPU3D_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_GPU3D_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PDN_ACK_MASK (0x100000U)
#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PDN_ACK_SHIFT (20U)
#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PUP_ACK_MASK (0x200000U)
#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PUP_ACK_SHIFT (21U)
#define GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_MEDIMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PDN_ACK_MASK (0x400000U)
#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PDN_ACK_SHIFT (22U)
#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PUP_ACK_MASK (0x800000U)
#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PUP_ACK_SHIFT (23U)
#define GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_G1_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PDN_ACK_MASK (0x1000000U)
#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PDN_ACK_SHIFT (24U)
#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PDN_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PUP_ACK_MASK (0x2000000U)
#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PUP_ACK_SHIFT (25U)
#define GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PUP_ACK(x)  (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_G2_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PDN_ACK_MASK (0x4000000U)
#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PDN_ACK_SHIFT (26U)
#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PUP_ACK_MASK (0x8000000U)
#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PUP_ACK_SHIFT (27U)
#define GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_VPU_VC8K_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PDN_ACK_MASK (0x10000000U)
#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PDN_ACK_SHIFT (28U)
#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PUP_ACK_MASK (0x20000000U)
#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PUP_ACK_SHIFT (29U)
#define GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_HDMIMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PDN_ACK_MASK (0x40000000U)
#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PDN_ACK_SHIFT (30U)
#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PUP_ACK_MASK (0x80000000U)
#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PUP_ACK_SHIFT (31U)
#define GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU_HDMI_PHY_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name ACK_SEL_M7_PU1 - PGC acknowledge signal selection of M7 platform for PUs */
/*! @{ */

#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PDN_ACK_MASK (0x1U)
#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PDN_ACK_SHIFT (0U)
#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PUP_ACK_MASK (0x2U)
#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PUP_ACK_SHIFT (1U)
#define GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_MIPI_PHY2_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PDN_ACK_MASK (0x4U)
#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PDN_ACK_SHIFT (2U)
#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PUP_ACK_MASK (0x8U)
#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PUP_ACK_SHIFT (3U)
#define GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_HSIOMIX_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_MASK (0x10U)
#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_SHIFT (4U)
#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_MASK (0x20U)
#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_SHIFT (5U)
#define GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_MEDIA_ISP_DWP_PGC_PUP_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PDN_ACK_MASK (0x40U)
#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PDN_ACK_SHIFT (6U)
#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PDN_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PDN_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PDN_ACK_MASK)

#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PUP_ACK_MASK (0x80U)
#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PUP_ACK_SHIFT (7U)
#define GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PUP_ACK(x) (((uint32_t)(((uint32_t)(x)) << GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PUP_ACK_SHIFT)) & GPC_ACK_SEL_M7_PU1_DDRMIX_PGC_PUP_ACK_MASK)
/*! @} */

/*! @name PGC_CPU_A53_MAPPING - PGC CPU A53 mapping */
/*! @{ */

#define GPC_PGC_CPU_A53_MAPPING_MIX0_SUPERMIXM7_DOMAIN_MASK (0x1U)
#define GPC_PGC_CPU_A53_MAPPING_MIX0_SUPERMIXM7_DOMAIN_SHIFT (0U)
/*! MIX0_SUPERMIXM7_DOMAIN
 *  0b0..Don't map M7 to A53 domain
 *  0b1..Map M7 to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MIX0_SUPERMIXM7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MIX0_SUPERMIXM7_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MIX0_SUPERMIXM7_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MIX1_NOC_DOMAIN_MASK (0x2U)
#define GPC_PGC_CPU_A53_MAPPING_MIX1_NOC_DOMAIN_SHIFT (1U)
/*! MIX1_NOC_DOMAIN
 *  0b0..Don't map NOC to A53 domain
 *  0b1..Map NOC to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MIX1_NOC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MIX1_NOC_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MIX1_NOC_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY1_DOMAIN_MASK (0x4U)
#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY1_DOMAIN_SHIFT (2U)
/*! MIPI_PHY1_DOMAIN
 *  0b0..Don't map MIPI_PHY1 to A53 domain
 *  0b1..Map MIPI_PHY1 to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY1_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MIPI_PHY1_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MIPI_PHY1_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_PCIE_PHY_DOMAIN_MASK (0x8U)
#define GPC_PGC_CPU_A53_MAPPING_PCIE_PHY_DOMAIN_SHIFT (3U)
/*! PCIE_PHY_DOMAIN
 *  0b0..Don't map PCIE_PHY to A53 domain
 *  0b1..Map PCIE_PHY to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_PCIE_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_PCIE_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_PCIE_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_USB1_PHY_DOMAIN_MASK (0x10U)
#define GPC_PGC_CPU_A53_MAPPING_USB1_PHY_DOMAIN_SHIFT (4U)
/*! USB1_PHY_DOMAIN
 *  0b0..Don't map USB1_PHY to A53 domain
 *  0b1..Map USB1_PHY to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_USB1_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_USB1_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_USB1_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_USB2_PHY_DOMAIN_MASK (0x20U)
#define GPC_PGC_CPU_A53_MAPPING_USB2_PHY_DOMAIN_SHIFT (5U)
/*! USB2_PHY_DOMAIN
 *  0b0..Don't map USB2_PHY to A53 domain
 *  0b1..Map USB2_PHY to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_USB2_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_USB2_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_USB2_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MLMIX_DOMAIN_MASK (0x40U)
#define GPC_PGC_CPU_A53_MAPPING_MLMIX_DOMAIN_SHIFT (6U)
/*! MLMIX_DOMAIN
 *  0b0..Don't map MLMIX to A53 domain
 *  0b1..Map MLMIX to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MLMIX_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MLMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MLMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_AUDIOMIX_DOMAIN_MASK (0x80U)
#define GPC_PGC_CPU_A53_MAPPING_AUDIOMIX_DOMAIN_SHIFT (7U)
/*! AUDIOMIX_DOMAIN
 *  0b0..Don't map AUDIOMIX to A53 domain
 *  0b1..Map AUDIOMIX to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_AUDIOMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_AUDIOMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_AUDIOMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_GPU_2D_DOMAIN_MASK (0x100U)
#define GPC_PGC_CPU_A53_MAPPING_GPU_2D_DOMAIN_SHIFT (8U)
/*! GPU_2D_DOMAIN
 *  0b0..Don't map GPU2D to A53 domain
 *  0b1..Map GPU2D to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_GPU_2D_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_GPU_2D_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_GPU_2D_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_GPU_SHARE_LOGIC_DOMAIN_MASK (0x200U)
#define GPC_PGC_CPU_A53_MAPPING_GPU_SHARE_LOGIC_DOMAIN_SHIFT (9U)
/*! GPU_SHARE_LOGIC_DOMAIN
 *  0b0..Don't map GPU Share Logic to A53 domain
 *  0b1..Map GPU Share Logic to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_GPU_SHARE_LOGIC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_GPU_SHARE_LOGIC_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_GPU_SHARE_LOGIC_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_MASK (0x400U)
#define GPC_PGC_CPU_A53_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_SHIFT (10U)
/*! VPUMIX_SHARE_LOGIC_DOMAIN
 *  0b0..Don't map VPUMIX Share Logic to A53 domain
 *  0b1..Map VPUMIX Share Logic to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_GPU3D_DOMAIN_MASK (0x800U)
#define GPC_PGC_CPU_A53_MAPPING_GPU3D_DOMAIN_SHIFT (11U)
/*! GPU3D_DOMAIN
 *  0b0..Don't map GPU2D to A53 domain
 *  0b1..Map GPU2D to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_GPU3D_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_GPU3D_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_GPU3D_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MEDIMIX_DOMAIN_MASK (0x1000U)
#define GPC_PGC_CPU_A53_MAPPING_MEDIMIX_DOMAIN_SHIFT (12U)
/*! MEDIMIX_DOMAIN
 *  0b0..Don't map MEDIMIX to A53 domain
 *  0b1..Map MEDIMIX to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MEDIMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MEDIMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MEDIMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_VPU_G1_DOMAIN_MASK (0x2000U)
#define GPC_PGC_CPU_A53_MAPPING_VPU_G1_DOMAIN_SHIFT (13U)
/*! VPU_G1_DOMAIN
 *  0b0..Don't map VPU_G1 to A53 domain
 *  0b1..Map VPU_G1 to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_VPU_G1_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_VPU_G1_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_VPU_G1_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_VPU_G2_DOMAIN_MASK (0x4000U)
#define GPC_PGC_CPU_A53_MAPPING_VPU_G2_DOMAIN_SHIFT (14U)
/*! VPU_G2_DOMAIN
 *  0b0..Don't map VPU_G1 to A53 domain
 *  0b1..Map VPU_G1 to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_VPU_G2_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_VPU_G2_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_VPU_G2_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_VPU_VC8K_DOMAIN_MASK (0x8000U)
#define GPC_PGC_CPU_A53_MAPPING_VPU_VC8K_DOMAIN_SHIFT (15U)
/*! VPU_VC8K_DOMAIN
 *  0b0..Don't map VPU_VC8K to A53 domain
 *  0b1..Map VPU_VC8K to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_VPU_VC8K_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_VPU_VC8K_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_VPU_VC8K_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_HDMIMIX_DOMAIN_MASK (0x10000U)
#define GPC_PGC_CPU_A53_MAPPING_HDMIMIX_DOMAIN_SHIFT (16U)
/*! HDMIMIX_DOMAIN
 *  0b0..Don't map HDMI to A53 domain
 *  0b1..Map HDMI to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_HDMIMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_HDMIMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_HDMIMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_HDMI_PHY_DOMAIN_MASK (0x20000U)
#define GPC_PGC_CPU_A53_MAPPING_HDMI_PHY_DOMAIN_SHIFT (17U)
/*! HDMI_PHY_DOMAIN
 *  0b0..Don't map HDMI PHY to A53 domain
 *  0b1..Map HDMI PHY to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_HDMI_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_HDMI_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_HDMI_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY2_DOMAIN_MASK (0x40000U)
#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY2_DOMAIN_SHIFT (18U)
/*! MIPI_PHY2_DOMAIN
 *  0b0..Don't map MIPI PHY2 to A53 domain
 *  0b1..Map MIPI PHY2 to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MIPI_PHY2_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MIPI_PHY2_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MIPI_PHY2_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_HSIOMIX_DOMAIN_MASK (0x80000U)
#define GPC_PGC_CPU_A53_MAPPING_HSIOMIX_DOMAIN_SHIFT (19U)
/*! HSIOMIX_DOMAIN
 *  0b0..Don't map HSIOMIX to A53 domain
 *  0b1..Map HSIOMIX to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_HSIOMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_HSIOMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_HSIOMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_MEDIA_ISP_DWP_DOMAIN_MASK (0x100000U)
#define GPC_PGC_CPU_A53_MAPPING_MEDIA_ISP_DWP_DOMAIN_SHIFT (20U)
/*! MEDIA_ISP_DWP_DOMAIN
 *  0b0..Don't map MEDIA_ISP_DWP_DOMAIN to A53 domain
 *  0b1..Map DDR to MEDIA_ISP_DWP_DOMAIN domain
 */
#define GPC_PGC_CPU_A53_MAPPING_MEDIA_ISP_DWP_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_MEDIA_ISP_DWP_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_MEDIA_ISP_DWP_DOMAIN_MASK)

#define GPC_PGC_CPU_A53_MAPPING_DDRMIX_DOMAIN_MASK (0x200000U)
#define GPC_PGC_CPU_A53_MAPPING_DDRMIX_DOMAIN_SHIFT (21U)
/*! DDRMIX_DOMAIN
 *  0b0..Don't map DDR to A53 domain
 *  0b1..Map DDR to A53 domain
 */
#define GPC_PGC_CPU_A53_MAPPING_DDRMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_A53_MAPPING_DDRMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_A53_MAPPING_DDRMIX_DOMAIN_MASK)
/*! @} */

/*! @name PGC_CPU_M7_MAPPING - PGC CPU M7 mapping */
/*! @{ */

#define GPC_PGC_CPU_M7_MAPPING_MIX0_SUPERMIXM7_DOMAIN_MASK (0x1U)
#define GPC_PGC_CPU_M7_MAPPING_MIX0_SUPERMIXM7_DOMAIN_SHIFT (0U)
/*! MIX0_SUPERMIXM7_DOMAIN
 *  0b0..Don't map MIX0_SUPERMIXM7 to M7 domain
 *  0b1..Map MIX0_SUPERMIXM7 to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MIX0_SUPERMIXM7_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MIX0_SUPERMIXM7_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MIX0_SUPERMIXM7_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MIX1_NOC_DOMAIN_MASK (0x2U)
#define GPC_PGC_CPU_M7_MAPPING_MIX1_NOC_DOMAIN_SHIFT (1U)
/*! MIX1_NOC_DOMAIN
 *  0b0..Don't map MIX1_NOC to M7 domain
 *  0b1..Map MIX1_NOC to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MIX1_NOC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MIX1_NOC_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MIX1_NOC_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY1_DOMAIN_MASK (0x4U)
#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY1_DOMAIN_SHIFT (2U)
/*! MIPI_PHY1_DOMAIN
 *  0b0..Don't map MIPI_PHY1 to M7 domain
 *  0b1..Map MIPI_PHY1 to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY1_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MIPI_PHY1_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MIPI_PHY1_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_PCIE_PHY_DOMAIN_MASK (0x8U)
#define GPC_PGC_CPU_M7_MAPPING_PCIE_PHY_DOMAIN_SHIFT (3U)
/*! PCIE_PHY_DOMAIN
 *  0b0..Don't map PCIE_PHY to M7 domain
 *  0b1..Map PCIE_PHY to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_PCIE_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_PCIE_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_PCIE_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_USB1_PHY_DOMAIN_MASK (0x10U)
#define GPC_PGC_CPU_M7_MAPPING_USB1_PHY_DOMAIN_SHIFT (4U)
/*! USB1_PHY_DOMAIN
 *  0b0..Don't map USB1_PHY to M7 domain
 *  0b1..Map USB1_PHY to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_USB1_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_USB1_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_USB1_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_USB2_PHY_DOMAIN_MASK (0x20U)
#define GPC_PGC_CPU_M7_MAPPING_USB2_PHY_DOMAIN_SHIFT (5U)
/*! USB2_PHY_DOMAIN
 *  0b0..Don't map USB2_PHY to M7 domain
 *  0b1..Map USB2_PHY to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_USB2_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_USB2_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_USB2_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MLMIX_DOMAIN_MASK (0x40U)
#define GPC_PGC_CPU_M7_MAPPING_MLMIX_DOMAIN_SHIFT (6U)
/*! MLMIX_DOMAIN
 *  0b0..Don't map MLMIX to M7 domain
 *  0b1..Map MLMIX to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MLMIX_DOMAIN(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MLMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MLMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_AUDIOMIX_DOMAIN_MASK (0x80U)
#define GPC_PGC_CPU_M7_MAPPING_AUDIOMIX_DOMAIN_SHIFT (7U)
/*! AUDIOMIX_DOMAIN
 *  0b0..Don't map AUDIOMIX to M7 domain
 *  0b1..Map AUDIOMIX to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_AUDIOMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_AUDIOMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_AUDIOMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_GPU_2D_DOMAIN_MASK (0x100U)
#define GPC_PGC_CPU_M7_MAPPING_GPU_2D_DOMAIN_SHIFT (8U)
/*! GPU_2D_DOMAIN
 *  0b0..Don't map GPU2D to M7 domain
 *  0b1..Map GPU2D to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_GPU_2D_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_GPU_2D_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_GPU_2D_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_GPU_SHARE_LOGIC_DOMAIN_MASK (0x200U)
#define GPC_PGC_CPU_M7_MAPPING_GPU_SHARE_LOGIC_DOMAIN_SHIFT (9U)
/*! GPU_SHARE_LOGIC_DOMAIN
 *  0b0..Don't map GPU Share Logic to M7 domain
 *  0b1..Map GPU Share Logic to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_GPU_SHARE_LOGIC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_GPU_SHARE_LOGIC_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_GPU_SHARE_LOGIC_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_MASK (0x400U)
#define GPC_PGC_CPU_M7_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_SHIFT (10U)
/*! VPUMIX_SHARE_LOGIC_DOMAIN
 *  0b0..Don't map VPUMIX Share Logic to M7 domain
 *  0b1..Map VPUMIX Share Logic to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_VPUMIX_SHARE_LOGIC_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_GPU3D_DOMAIN_MASK (0x800U)
#define GPC_PGC_CPU_M7_MAPPING_GPU3D_DOMAIN_SHIFT (11U)
/*! GPU3D_DOMAIN
 *  0b0..Don't map GPU2D to M7 domain
 *  0b1..Map GPU2D to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_GPU3D_DOMAIN(x)   (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_GPU3D_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_GPU3D_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MEDIMIX_DOMAIN_MASK (0x1000U)
#define GPC_PGC_CPU_M7_MAPPING_MEDIMIX_DOMAIN_SHIFT (12U)
/*! MEDIMIX_DOMAIN
 *  0b0..Don't map MEDIMIX to M7 domain
 *  0b1..Map MEDIMIX to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MEDIMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MEDIMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MEDIMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_VPU_G1_DOMAIN_MASK (0x2000U)
#define GPC_PGC_CPU_M7_MAPPING_VPU_G1_DOMAIN_SHIFT (13U)
/*! VPU_G1_DOMAIN
 *  0b0..Don't map VPU_G1 to M7 domain
 *  0b1..Map VPU_G1 to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_VPU_G1_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_VPU_G1_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_VPU_G1_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_VPU_G2_DOMAIN_MASK (0x4000U)
#define GPC_PGC_CPU_M7_MAPPING_VPU_G2_DOMAIN_SHIFT (14U)
/*! VPU_G2_DOMAIN
 *  0b0..Don't map VPU_G1 to M7 domain
 *  0b1..Map VPU_G1 to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_VPU_G2_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_VPU_G2_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_VPU_G2_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_VPU_VC8K_DOMAIN_MASK (0x8000U)
#define GPC_PGC_CPU_M7_MAPPING_VPU_VC8K_DOMAIN_SHIFT (15U)
/*! VPU_VC8K_DOMAIN
 *  0b0..Don't map VPU_VC8K to M7 domain
 *  0b1..Map VPU_VC8K to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_VPU_VC8K_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_VPU_VC8K_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_VPU_VC8K_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_HDMIMIX_DOMAIN_MASK (0x10000U)
#define GPC_PGC_CPU_M7_MAPPING_HDMIMIX_DOMAIN_SHIFT (16U)
/*! HDMIMIX_DOMAIN
 *  0b0..Don't map HDMI to M7 domain
 *  0b1..Map HDMI to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_HDMIMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_HDMIMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_HDMIMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_HDMI_PHY_DOMAIN_MASK (0x20000U)
#define GPC_PGC_CPU_M7_MAPPING_HDMI_PHY_DOMAIN_SHIFT (17U)
/*! HDMI_PHY_DOMAIN
 *  0b0..Don't map HDMI PHY to M7 domain
 *  0b1..Map HDMI PHY to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_HDMI_PHY_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_HDMI_PHY_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_HDMI_PHY_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY2_DOMAIN_MASK (0x40000U)
#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY2_DOMAIN_SHIFT (18U)
/*! MIPI_PHY2_DOMAIN
 *  0b0..Don't map MIPI PHY2 to M7 domain
 *  0b1..Map MIPI PHY2 to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MIPI_PHY2_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MIPI_PHY2_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MIPI_PHY2_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_HSIOMIX_DOMAIN_MASK (0x80000U)
#define GPC_PGC_CPU_M7_MAPPING_HSIOMIX_DOMAIN_SHIFT (19U)
/*! HSIOMIX_DOMAIN
 *  0b0..Don't map HSIOMIX to M7 domain
 *  0b1..Map HSIOMIX to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_HSIOMIX_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_HSIOMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_HSIOMIX_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_MEDIA_ISP_DWP_DOMAIN_MASK (0x100000U)
#define GPC_PGC_CPU_M7_MAPPING_MEDIA_ISP_DWP_DOMAIN_SHIFT (20U)
/*! MEDIA_ISP_DWP_DOMAIN
 *  0b0..Don't map MEDIA_ISP_DWP_DOMAIN to M7 domain
 *  0b1..Map MEDIA_ISP_DWP_DOMAIN to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_MEDIA_ISP_DWP_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_MEDIA_ISP_DWP_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_MEDIA_ISP_DWP_DOMAIN_MASK)

#define GPC_PGC_CPU_M7_MAPPING_DDRMIX_DOMAIN_MASK (0x200000U)
#define GPC_PGC_CPU_M7_MAPPING_DDRMIX_DOMAIN_SHIFT (21U)
/*! DDRMIX_DOMAIN
 *  0b0..Don't map DDR to M7 domain
 *  0b1..Map DDR to M7 domain
 */
#define GPC_PGC_CPU_M7_MAPPING_DDRMIX_DOMAIN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_PGC_CPU_M7_MAPPING_DDRMIX_DOMAIN_SHIFT)) & GPC_PGC_CPU_M7_MAPPING_DDRMIX_DOMAIN_MASK)
/*! @} */

/*! @name SLT_CFG - Slot configure register for CPUs */
/*! @{ */

#define GPC_SLT_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT_CFG_CORE0_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE0_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE0_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT_CFG_CORE0_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE0_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE0_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT_CFG_CORE1_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE1_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE1_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT_CFG_CORE1_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE1_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE1_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT_CFG_CORE2_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE2_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE2_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT_CFG_CORE2_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE2_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE2_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT_CFG_CORE3_A53_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE3_A53_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE3_A53_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT_CFG_CORE3_A53_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_CORE3_A53_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_CORE3_A53_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_SCU_PDN_SLOT_CONTROL_MASK    (0x100U)
#define GPC_SLT_CFG_SCU_PDN_SLOT_CONTROL_SHIFT   (8U)
#define GPC_SLT_CFG_SCU_PDN_SLOT_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_SCU_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_SCU_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_SCU_PUP_SLOT_CONTROL_MASK    (0x200U)
#define GPC_SLT_CFG_SCU_PUP_SLOT_CONTROL_SHIFT   (9U)
#define GPC_SLT_CFG_SCU_PUP_SLOT_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_SCU_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_SCU_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_NOC_PDN_SLOT_CONTROL_MASK    (0x1000U)
#define GPC_SLT_CFG_NOC_PDN_SLOT_CONTROL_SHIFT   (12U)
#define GPC_SLT_CFG_NOC_PDN_SLOT_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_NOC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_NOC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_NOC_PUP_SLOT_CONTROL_MASK    (0x2000U)
#define GPC_SLT_CFG_NOC_PUP_SLOT_CONTROL_SHIFT   (13U)
#define GPC_SLT_CFG_NOC_PUP_SLOT_CONTROL(x)      (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_NOC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_NOC_PUP_SLOT_CONTROL_MASK)
/*! @} */

/*! @name SLT_CFG_PU - Slot configure register for PGC PUs */
/*! @{ */

#define GPC_SLT_CFG_PU_MIPI_PHY1_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT_CFG_PU_MIPI_PHY1_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT_CFG_PU_MIPI_PHY1_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MIPI_PHY1_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MIPI_PHY1_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MIPI_PHY1_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT_CFG_PU_MIPI_PHY1_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT_CFG_PU_MIPI_PHY1_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MIPI_PHY1_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MIPI_PHY1_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_PCIE_PHY_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT_CFG_PU_PCIE_PHY_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT_CFG_PU_PCIE_PHY_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_PCIE_PHY_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_PCIE_PHY_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_PCIE_PHY_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT_CFG_PU_PCIE_PHY_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT_CFG_PU_PCIE_PHY_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_PCIE_PHY_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_PCIE_PHY_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_USB1_PHY_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT_CFG_PU_USB1_PHY_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT_CFG_PU_USB1_PHY_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_USB1_PHY_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_USB1_PHY_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_USB1_PHY_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT_CFG_PU_USB1_PHY_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT_CFG_PU_USB1_PHY_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_USB1_PHY_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_USB1_PHY_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_USB2_PHY_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT_CFG_PU_USB2_PHY_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT_CFG_PU_USB2_PHY_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_USB2_PHY_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_USB2_PHY_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_USB2_PHY_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT_CFG_PU_USB2_PHY_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT_CFG_PU_USB2_PHY_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_USB2_PHY_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_USB2_PHY_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MLMIX_PDN_SLOT_CONTROL_MASK (0x100U)
#define GPC_SLT_CFG_PU_MLMIX_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT_CFG_PU_MLMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MLMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MLMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MLMIX_PUP_SLOT_CONTROL_MASK (0x200U)
#define GPC_SLT_CFG_PU_MLMIX_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT_CFG_PU_MLMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MLMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MLMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_AUDIOMIX_PDN_SLOT_CONTROL_MASK (0x400U)
#define GPC_SLT_CFG_PU_AUDIOMIX_PDN_SLOT_CONTROL_SHIFT (10U)
#define GPC_SLT_CFG_PU_AUDIOMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_AUDIOMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_AUDIOMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_AUDIOMIX_PUP_SLOT_CONTROL_MASK (0x800U)
#define GPC_SLT_CFG_PU_AUDIOMIX_PUP_SLOT_CONTROL_SHIFT (11U)
#define GPC_SLT_CFG_PU_AUDIOMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_AUDIOMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_AUDIOMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU_2D_PDN_SLOT_CONTROL_MASK (0x1000U)
#define GPC_SLT_CFG_PU_GPU_2D_PDN_SLOT_CONTROL_SHIFT (12U)
#define GPC_SLT_CFG_PU_GPU_2D_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU_2D_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU_2D_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU_2D_PUP_SLOT_CONTROL_MASK (0x2000U)
#define GPC_SLT_CFG_PU_GPU_2D_PUP_SLOT_CONTROL_SHIFT (13U)
#define GPC_SLT_CFG_PU_GPU_2D_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU_2D_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU_2D_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PDN_SLOT_CONTROL_MASK (0x4000U)
#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PDN_SLOT_CONTROL_SHIFT (14U)
#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PUP_SLOT_CONTROL_MASK (0x8000U)
#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PUP_SLOT_CONTROL_SHIFT (15U)
#define GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU_SHARE_LOGIC_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PDN_SLOT_CONTROL_MASK (0x10000U)
#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PDN_SLOT_CONTROL_SHIFT (16U)
#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PUP_SLOT_CONTROL_MASK (0x20000U)
#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PUP_SLOT_CONTROL_SHIFT (17U)
#define GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPUMIX_SHARE_LOGIC_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU3D_PDN_SLOT_CONTROL_MASK (0x40000U)
#define GPC_SLT_CFG_PU_GPU3D_PDN_SLOT_CONTROL_SHIFT (18U)
#define GPC_SLT_CFG_PU_GPU3D_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU3D_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU3D_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_GPU3D_PUP_SLOT_CONTROL_MASK (0x80000U)
#define GPC_SLT_CFG_PU_GPU3D_PUP_SLOT_CONTROL_SHIFT (19U)
#define GPC_SLT_CFG_PU_GPU3D_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_GPU3D_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_GPU3D_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MEDIMIX_PDN_SLOT_CONTROL_MASK (0x100000U)
#define GPC_SLT_CFG_PU_MEDIMIX_PDN_SLOT_CONTROL_SHIFT (20U)
#define GPC_SLT_CFG_PU_MEDIMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MEDIMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MEDIMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_MEDIMIX_PUP_SLOT_CONTROL_MASK (0x200000U)
#define GPC_SLT_CFG_PU_MEDIMIX_PUP_SLOT_CONTROL_SHIFT (21U)
#define GPC_SLT_CFG_PU_MEDIMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_MEDIMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_MEDIMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_G1_PDN_SLOT_CONTROL_MASK (0x400000U)
#define GPC_SLT_CFG_PU_VPU_G1_PDN_SLOT_CONTROL_SHIFT (22U)
#define GPC_SLT_CFG_PU_VPU_G1_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_G1_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_G1_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_G1_PUP_SLOT_CONTROL_MASK (0x800000U)
#define GPC_SLT_CFG_PU_VPU_G1_PUP_SLOT_CONTROL_SHIFT (23U)
#define GPC_SLT_CFG_PU_VPU_G1_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_G1_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_G1_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_G2_PDN_SLOT_CONTROL_MASK (0x1000000U)
#define GPC_SLT_CFG_PU_VPU_G2_PDN_SLOT_CONTROL_SHIFT (24U)
#define GPC_SLT_CFG_PU_VPU_G2_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_G2_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_G2_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_G2_PUP_SLOT_CONTROL_MASK (0x2000000U)
#define GPC_SLT_CFG_PU_VPU_G2_PUP_SLOT_CONTROL_SHIFT (25U)
#define GPC_SLT_CFG_PU_VPU_G2_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_G2_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_G2_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_VC8K_PDN_SLOT_CONTROL_MASK (0x4000000U)
#define GPC_SLT_CFG_PU_VPU_VC8K_PDN_SLOT_CONTROL_SHIFT (26U)
#define GPC_SLT_CFG_PU_VPU_VC8K_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_VC8K_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_VC8K_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_VPU_VC8K_PUP_SLOT_CONTROL_MASK (0x8000000U)
#define GPC_SLT_CFG_PU_VPU_VC8K_PUP_SLOT_CONTROL_SHIFT (27U)
#define GPC_SLT_CFG_PU_VPU_VC8K_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_VPU_VC8K_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_VPU_VC8K_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_HDMIMIX_PDN_SLOT_CONTROL_MASK (0x10000000U)
#define GPC_SLT_CFG_PU_HDMIMIX_PDN_SLOT_CONTROL_SHIFT (28U)
#define GPC_SLT_CFG_PU_HDMIMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_HDMIMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_HDMIMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_HDMIMIX_PUP_SLOT_CONTROL_MASK (0x20000000U)
#define GPC_SLT_CFG_PU_HDMIMIX_PUP_SLOT_CONTROL_SHIFT (29U)
#define GPC_SLT_CFG_PU_HDMIMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_HDMIMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_HDMIMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_HDMI_PHY_PDN_SLOT_CONTROL_MASK (0x40000000U)
#define GPC_SLT_CFG_PU_HDMI_PHY_PDN_SLOT_CONTROL_SHIFT (30U)
#define GPC_SLT_CFG_PU_HDMI_PHY_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_HDMI_PHY_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_HDMI_PHY_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU_HDMI_PHY_PUP_SLOT_CONTROL_MASK (0x80000000U)
#define GPC_SLT_CFG_PU_HDMI_PHY_PUP_SLOT_CONTROL_SHIFT (31U)
#define GPC_SLT_CFG_PU_HDMI_PHY_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU_HDMI_PHY_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU_HDMI_PHY_PUP_SLOT_CONTROL_MASK)
/*! @} */

/* The count of GPC_SLT_CFG_PU */
#define GPC_SLT_CFG_PU_COUNT                     (27U)

/*! @name SLT_CFG_PU1 - Extended slot configure register for PGC PUs */
/*! @{ */

#define GPC_SLT_CFG_PU1_MIPI_PHY2_PDN_SLOT_CONTROL_MASK (0x1U)
#define GPC_SLT_CFG_PU1_MIPI_PHY2_PDN_SLOT_CONTROL_SHIFT (0U)
#define GPC_SLT_CFG_PU1_MIPI_PHY2_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_MIPI_PHY2_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_MIPI_PHY2_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_MIPI_PHY2_PUP_SLOT_CONTROL_MASK (0x2U)
#define GPC_SLT_CFG_PU1_MIPI_PHY2_PUP_SLOT_CONTROL_SHIFT (1U)
#define GPC_SLT_CFG_PU1_MIPI_PHY2_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_MIPI_PHY2_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_MIPI_PHY2_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_HSIOMIX_PDN_SLOT_CONTROL_MASK (0x4U)
#define GPC_SLT_CFG_PU1_HSIOMIX_PDN_SLOT_CONTROL_SHIFT (2U)
#define GPC_SLT_CFG_PU1_HSIOMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_HSIOMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_HSIOMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_HSIOMIX_PUP_SLOT_CONTROL_MASK (0x8U)
#define GPC_SLT_CFG_PU1_HSIOMIX_PUP_SLOT_CONTROL_SHIFT (3U)
#define GPC_SLT_CFG_PU1_HSIOMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_HSIOMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_HSIOMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PDN_SLOT_CONTROL_MASK (0x10U)
#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PDN_SLOT_CONTROL_SHIFT (4U)
#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PUP_SLOT_CONTROL_MASK (0x20U)
#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PUP_SLOT_CONTROL_SHIFT (5U)
#define GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_MEDIA_ISP_DWP_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_DDRMIX_PDN_SLOT_CONTROL_MASK (0x40U)
#define GPC_SLT_CFG_PU1_DDRMIX_PDN_SLOT_CONTROL_SHIFT (6U)
#define GPC_SLT_CFG_PU1_DDRMIX_PDN_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_DDRMIX_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_DDRMIX_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_DDRMIX_PUP_SLOT_CONTROL_MASK (0x80U)
#define GPC_SLT_CFG_PU1_DDRMIX_PUP_SLOT_CONTROL_SHIFT (7U)
#define GPC_SLT_CFG_PU1_DDRMIX_PUP_SLOT_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_DDRMIX_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_DDRMIX_PUP_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_M7_PDN_SLOT_CONTROL_MASK (0x100U)
#define GPC_SLT_CFG_PU1_M7_PDN_SLOT_CONTROL_SHIFT (8U)
#define GPC_SLT_CFG_PU1_M7_PDN_SLOT_CONTROL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_M7_PDN_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_M7_PDN_SLOT_CONTROL_MASK)

#define GPC_SLT_CFG_PU1_M7_PUP_SLOT_CONTROL_MASK (0x200U)
#define GPC_SLT_CFG_PU1_M7_PUP_SLOT_CONTROL_SHIFT (9U)
#define GPC_SLT_CFG_PU1_M7_PUP_SLOT_CONTROL(x)   (((uint32_t)(((uint32_t)(x)) << GPC_SLT_CFG_PU1_M7_PUP_SLOT_CONTROL_SHIFT)) & GPC_SLT_CFG_PU1_M7_PUP_SLOT_CONTROL_MASK)
/*! @} */

/* The count of GPC_SLT_CFG_PU1 */
#define GPC_SLT_CFG_PU1_COUNT                    (27U)


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_GPC_H_ */

