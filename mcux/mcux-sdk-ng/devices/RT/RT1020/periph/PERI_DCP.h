/*
** ###################################################################
**     Processors:          MIMXRT1021CAF4A
**                          MIMXRT1021CAF4B
**                          MIMXRT1021CAG4A
**                          MIMXRT1021CAG4B
**                          MIMXRT1021DAF5A
**                          MIMXRT1021DAF5B
**                          MIMXRT1021DAG5A
**                          MIMXRT1021DAG5B
**                          MIMXRT1024CAG4A
**                          MIMXRT1024CAG4B
**                          MIMXRT1024DAG5A
**                          MIMXRT1024DAG5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-11-06)
**         Initial version.
**     - rev. 1.0 (2018-11-27)
**         Update header files to align with IMXRT1020RM Rev.1.
**     - rev. 1.1 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1020RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DCP.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DCP
 *
 * CMSIS Peripheral Access Layer for DCP
 */

#if !defined(PERI_DCP_H_)
#define PERI_DCP_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1021CAF4A) || defined(CPU_MIMXRT1021CAF4B) || defined(CPU_MIMXRT1021CAG4A) || defined(CPU_MIMXRT1021CAG4B) || defined(CPU_MIMXRT1021DAF5A) || defined(CPU_MIMXRT1021DAF5B) || defined(CPU_MIMXRT1021DAG5A) || defined(CPU_MIMXRT1021DAG5B))
#include "MIMXRT1021_COMMON.h"
#elif (defined(CPU_MIMXRT1024CAG4A) || defined(CPU_MIMXRT1024CAG4B) || defined(CPU_MIMXRT1024DAG5A) || defined(CPU_MIMXRT1024DAG5B))
#include "MIMXRT1024_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DCP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCP_Peripheral_Access_Layer DCP Peripheral Access Layer
 * @{
 */

/** DCP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< DCP control register 0, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< DCP control register 0, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< DCP control register 0, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< DCP control register 0, offset: 0xC */
  __IO uint32_t STAT;                              /**< DCP status register, offset: 0x10 */
  __IO uint32_t STAT_SET;                          /**< DCP status register, offset: 0x14 */
  __IO uint32_t STAT_CLR;                          /**< DCP status register, offset: 0x18 */
  __IO uint32_t STAT_TOG;                          /**< DCP status register, offset: 0x1C */
  __IO uint32_t CHANNELCTRL;                       /**< DCP channel control register, offset: 0x20 */
  __IO uint32_t CHANNELCTRL_SET;                   /**< DCP channel control register, offset: 0x24 */
  __IO uint32_t CHANNELCTRL_CLR;                   /**< DCP channel control register, offset: 0x28 */
  __IO uint32_t CHANNELCTRL_TOG;                   /**< DCP channel control register, offset: 0x2C */
  __IO uint32_t CAPABILITY0;                       /**< DCP capability 0 register, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __I  uint32_t CAPABILITY1;                       /**< DCP capability 1 register, offset: 0x40 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CONTEXT;                           /**< DCP context buffer pointer, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t KEY;                               /**< DCP key index, offset: 0x60 */
       uint8_t RESERVED_3[12];
  __IO uint32_t KEYDATA;                           /**< DCP key data, offset: 0x70 */
       uint8_t RESERVED_4[12];
  __I  uint32_t PACKET0;                           /**< DCP work packet 0 status register, offset: 0x80 */
       uint8_t RESERVED_5[12];
  __I  uint32_t PACKET1;                           /**< DCP work packet 1 status register, offset: 0x90 */
       uint8_t RESERVED_6[12];
  __I  uint32_t PACKET2;                           /**< DCP work packet 2 status register, offset: 0xA0 */
       uint8_t RESERVED_7[12];
  __I  uint32_t PACKET3;                           /**< DCP work packet 3 status register, offset: 0xB0 */
       uint8_t RESERVED_8[12];
  __I  uint32_t PACKET4;                           /**< DCP work packet 4 status register, offset: 0xC0 */
       uint8_t RESERVED_9[12];
  __I  uint32_t PACKET5;                           /**< DCP work packet 5 status register, offset: 0xD0 */
       uint8_t RESERVED_10[12];
  __I  uint32_t PACKET6;                           /**< DCP work packet 6 status register, offset: 0xE0 */
       uint8_t RESERVED_11[28];
  __IO uint32_t CH0CMDPTR;                         /**< DCP channel 0 command pointer address register, offset: 0x100 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CH0SEMA;                           /**< DCP channel 0 semaphore register, offset: 0x110 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CH0STAT;                           /**< DCP channel 0 status register, offset: 0x120 */
  __IO uint32_t CH0STAT_SET;                       /**< DCP channel 0 status register, offset: 0x124 */
  __IO uint32_t CH0STAT_CLR;                       /**< DCP channel 0 status register, offset: 0x128 */
  __IO uint32_t CH0STAT_TOG;                       /**< DCP channel 0 status register, offset: 0x12C */
  __IO uint32_t CH0OPTS;                           /**< DCP channel 0 options register, offset: 0x130 */
  __IO uint32_t CH0OPTS_SET;                       /**< DCP channel 0 options register, offset: 0x134 */
  __IO uint32_t CH0OPTS_CLR;                       /**< DCP channel 0 options register, offset: 0x138 */
  __IO uint32_t CH0OPTS_TOG;                       /**< DCP channel 0 options register, offset: 0x13C */
  __IO uint32_t CH1CMDPTR;                         /**< DCP channel 1 command pointer address register, offset: 0x140 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CH1SEMA;                           /**< DCP channel 1 semaphore register, offset: 0x150 */
       uint8_t RESERVED_15[12];
  __IO uint32_t CH1STAT;                           /**< DCP channel 1 status register, offset: 0x160 */
  __IO uint32_t CH1STAT_SET;                       /**< DCP channel 1 status register, offset: 0x164 */
  __IO uint32_t CH1STAT_CLR;                       /**< DCP channel 1 status register, offset: 0x168 */
  __IO uint32_t CH1STAT_TOG;                       /**< DCP channel 1 status register, offset: 0x16C */
  __IO uint32_t CH1OPTS;                           /**< DCP channel 1 options register, offset: 0x170 */
  __IO uint32_t CH1OPTS_SET;                       /**< DCP channel 1 options register, offset: 0x174 */
  __IO uint32_t CH1OPTS_CLR;                       /**< DCP channel 1 options register, offset: 0x178 */
  __IO uint32_t CH1OPTS_TOG;                       /**< DCP channel 1 options register, offset: 0x17C */
  __IO uint32_t CH2CMDPTR;                         /**< DCP channel 2 command pointer address register, offset: 0x180 */
       uint8_t RESERVED_16[12];
  __IO uint32_t CH2SEMA;                           /**< DCP channel 2 semaphore register, offset: 0x190 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CH2STAT;                           /**< DCP channel 2 status register, offset: 0x1A0 */
  __IO uint32_t CH2STAT_SET;                       /**< DCP channel 2 status register, offset: 0x1A4 */
  __IO uint32_t CH2STAT_CLR;                       /**< DCP channel 2 status register, offset: 0x1A8 */
  __IO uint32_t CH2STAT_TOG;                       /**< DCP channel 2 status register, offset: 0x1AC */
  __IO uint32_t CH2OPTS;                           /**< DCP channel 2 options register, offset: 0x1B0 */
  __IO uint32_t CH2OPTS_SET;                       /**< DCP channel 2 options register, offset: 0x1B4 */
  __IO uint32_t CH2OPTS_CLR;                       /**< DCP channel 2 options register, offset: 0x1B8 */
  __IO uint32_t CH2OPTS_TOG;                       /**< DCP channel 2 options register, offset: 0x1BC */
  __IO uint32_t CH3CMDPTR;                         /**< DCP channel 3 command pointer address register, offset: 0x1C0 */
       uint8_t RESERVED_18[12];
  __IO uint32_t CH3SEMA;                           /**< DCP channel 3 semaphore register, offset: 0x1D0 */
       uint8_t RESERVED_19[12];
  __IO uint32_t CH3STAT;                           /**< DCP channel 3 status register, offset: 0x1E0 */
  __IO uint32_t CH3STAT_SET;                       /**< DCP channel 3 status register, offset: 0x1E4 */
  __IO uint32_t CH3STAT_CLR;                       /**< DCP channel 3 status register, offset: 0x1E8 */
  __IO uint32_t CH3STAT_TOG;                       /**< DCP channel 3 status register, offset: 0x1EC */
  __IO uint32_t CH3OPTS;                           /**< DCP channel 3 options register, offset: 0x1F0 */
  __IO uint32_t CH3OPTS_SET;                       /**< DCP channel 3 options register, offset: 0x1F4 */
  __IO uint32_t CH3OPTS_CLR;                       /**< DCP channel 3 options register, offset: 0x1F8 */
  __IO uint32_t CH3OPTS_TOG;                       /**< DCP channel 3 options register, offset: 0x1FC */
       uint8_t RESERVED_20[512];
  __IO uint32_t DBGSELECT;                         /**< DCP debug select register, offset: 0x400 */
       uint8_t RESERVED_21[12];
  __I  uint32_t DBGDATA;                           /**< DCP debug data register, offset: 0x410 */
       uint8_t RESERVED_22[12];
  __IO uint32_t PAGETABLE;                         /**< DCP page table register, offset: 0x420 */
       uint8_t RESERVED_23[12];
  __I  uint32_t VERSION;                           /**< DCP version register, offset: 0x430 */
} DCP_Type;

/* ----------------------------------------------------------------------------
   -- DCP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCP_Register_Masks DCP Register Masks
 * @{
 */

/*! @name CTRL - DCP control register 0 */
/*! @{ */

#define DCP_CTRL_CHANNEL_INTERRUPT_ENABLE_MASK   (0xFFU)
#define DCP_CTRL_CHANNEL_INTERRUPT_ENABLE_SHIFT  (0U)
/*! CHANNEL_INTERRUPT_ENABLE
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CTRL_CHANNEL_INTERRUPT_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CHANNEL_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_CHANNEL_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE_MASK  (0x100U)
#define DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE_SHIFT (8U)
#define DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_ENABLE_CONTEXT_SWITCHING_MASK   (0x200000U)
#define DCP_CTRL_ENABLE_CONTEXT_SWITCHING_SHIFT  (21U)
#define DCP_CTRL_ENABLE_CONTEXT_SWITCHING(x)     (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_ENABLE_CONTEXT_SWITCHING_SHIFT)) & DCP_CTRL_ENABLE_CONTEXT_SWITCHING_MASK)

#define DCP_CTRL_ENABLE_CONTEXT_CACHING_MASK     (0x400000U)
#define DCP_CTRL_ENABLE_CONTEXT_CACHING_SHIFT    (22U)
#define DCP_CTRL_ENABLE_CONTEXT_CACHING(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_ENABLE_CONTEXT_CACHING_SHIFT)) & DCP_CTRL_ENABLE_CONTEXT_CACHING_MASK)

#define DCP_CTRL_GATHER_RESIDUAL_WRITES_MASK     (0x800000U)
#define DCP_CTRL_GATHER_RESIDUAL_WRITES_SHIFT    (23U)
#define DCP_CTRL_GATHER_RESIDUAL_WRITES(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_GATHER_RESIDUAL_WRITES_SHIFT)) & DCP_CTRL_GATHER_RESIDUAL_WRITES_MASK)

#define DCP_CTRL_PRESENT_SHA_MASK                (0x10000000U)
#define DCP_CTRL_PRESENT_SHA_SHIFT               (28U)
/*! PRESENT_SHA
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_PRESENT_SHA(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_PRESENT_SHA_SHIFT)) & DCP_CTRL_PRESENT_SHA_MASK)

#define DCP_CTRL_PRESENT_CRYPTO_MASK             (0x20000000U)
#define DCP_CTRL_PRESENT_CRYPTO_SHIFT            (29U)
/*! PRESENT_CRYPTO
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_PRESENT_CRYPTO(x)               (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_PRESENT_CRYPTO_SHIFT)) & DCP_CTRL_PRESENT_CRYPTO_MASK)

#define DCP_CTRL_CLKGATE_MASK                    (0x40000000U)
#define DCP_CTRL_CLKGATE_SHIFT                   (30U)
#define DCP_CTRL_CLKGATE(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLKGATE_SHIFT)) & DCP_CTRL_CLKGATE_MASK)

#define DCP_CTRL_SFTRST_MASK                     (0x80000000U)
#define DCP_CTRL_SFTRST_SHIFT                    (31U)
#define DCP_CTRL_SFTRST(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SFTRST_SHIFT)) & DCP_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - DCP control register 0 */
/*! @{ */

#define DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE_MASK (0xFFU)
#define DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE_SHIFT (0U)
/*! CHANNEL_INTERRUPT_ENABLE
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE_MASK (0x100U)
#define DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE_SHIFT (8U)
#define DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING_MASK (0x200000U)
#define DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING_SHIFT (21U)
#define DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING_SHIFT)) & DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING_MASK)

#define DCP_CTRL_SET_ENABLE_CONTEXT_CACHING_MASK (0x400000U)
#define DCP_CTRL_SET_ENABLE_CONTEXT_CACHING_SHIFT (22U)
#define DCP_CTRL_SET_ENABLE_CONTEXT_CACHING(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_ENABLE_CONTEXT_CACHING_SHIFT)) & DCP_CTRL_SET_ENABLE_CONTEXT_CACHING_MASK)

#define DCP_CTRL_SET_GATHER_RESIDUAL_WRITES_MASK (0x800000U)
#define DCP_CTRL_SET_GATHER_RESIDUAL_WRITES_SHIFT (23U)
#define DCP_CTRL_SET_GATHER_RESIDUAL_WRITES(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_GATHER_RESIDUAL_WRITES_SHIFT)) & DCP_CTRL_SET_GATHER_RESIDUAL_WRITES_MASK)

#define DCP_CTRL_SET_PRESENT_SHA_MASK            (0x10000000U)
#define DCP_CTRL_SET_PRESENT_SHA_SHIFT           (28U)
/*! PRESENT_SHA
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_SET_PRESENT_SHA(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_PRESENT_SHA_SHIFT)) & DCP_CTRL_SET_PRESENT_SHA_MASK)

#define DCP_CTRL_SET_PRESENT_CRYPTO_MASK         (0x20000000U)
#define DCP_CTRL_SET_PRESENT_CRYPTO_SHIFT        (29U)
/*! PRESENT_CRYPTO
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_SET_PRESENT_CRYPTO(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_PRESENT_CRYPTO_SHIFT)) & DCP_CTRL_SET_PRESENT_CRYPTO_MASK)

#define DCP_CTRL_SET_CLKGATE_MASK                (0x40000000U)
#define DCP_CTRL_SET_CLKGATE_SHIFT               (30U)
#define DCP_CTRL_SET_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_CLKGATE_SHIFT)) & DCP_CTRL_SET_CLKGATE_MASK)

#define DCP_CTRL_SET_SFTRST_MASK                 (0x80000000U)
#define DCP_CTRL_SET_SFTRST_SHIFT                (31U)
#define DCP_CTRL_SET_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_SET_SFTRST_SHIFT)) & DCP_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - DCP control register 0 */
/*! @{ */

#define DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE_MASK (0xFFU)
#define DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE_SHIFT (0U)
/*! CHANNEL_INTERRUPT_ENABLE
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE_MASK (0x100U)
#define DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE_SHIFT (8U)
#define DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING_MASK (0x200000U)
#define DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING_SHIFT (21U)
#define DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING_SHIFT)) & DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING_MASK)

#define DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING_MASK (0x400000U)
#define DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING_SHIFT (22U)
#define DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING_SHIFT)) & DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING_MASK)

#define DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES_MASK (0x800000U)
#define DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES_SHIFT (23U)
#define DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES_SHIFT)) & DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES_MASK)

#define DCP_CTRL_CLR_PRESENT_SHA_MASK            (0x10000000U)
#define DCP_CTRL_CLR_PRESENT_SHA_SHIFT           (28U)
/*! PRESENT_SHA
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_CLR_PRESENT_SHA(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_PRESENT_SHA_SHIFT)) & DCP_CTRL_CLR_PRESENT_SHA_MASK)

#define DCP_CTRL_CLR_PRESENT_CRYPTO_MASK         (0x20000000U)
#define DCP_CTRL_CLR_PRESENT_CRYPTO_SHIFT        (29U)
/*! PRESENT_CRYPTO
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_CLR_PRESENT_CRYPTO(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_PRESENT_CRYPTO_SHIFT)) & DCP_CTRL_CLR_PRESENT_CRYPTO_MASK)

#define DCP_CTRL_CLR_CLKGATE_MASK                (0x40000000U)
#define DCP_CTRL_CLR_CLKGATE_SHIFT               (30U)
#define DCP_CTRL_CLR_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_CLKGATE_SHIFT)) & DCP_CTRL_CLR_CLKGATE_MASK)

#define DCP_CTRL_CLR_SFTRST_MASK                 (0x80000000U)
#define DCP_CTRL_CLR_SFTRST_SHIFT                (31U)
#define DCP_CTRL_CLR_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_CLR_SFTRST_SHIFT)) & DCP_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - DCP control register 0 */
/*! @{ */

#define DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE_MASK (0xFFU)
#define DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE_SHIFT (0U)
/*! CHANNEL_INTERRUPT_ENABLE
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE_MASK (0x100U)
#define DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE_SHIFT (8U)
#define DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE_SHIFT)) & DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE_MASK)

#define DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING_MASK (0x200000U)
#define DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING_SHIFT (21U)
#define DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING(x) (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING_SHIFT)) & DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING_MASK)

#define DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING_MASK (0x400000U)
#define DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING_SHIFT (22U)
#define DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING_SHIFT)) & DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING_MASK)

#define DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES_MASK (0x800000U)
#define DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES_SHIFT (23U)
#define DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES(x)   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES_SHIFT)) & DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES_MASK)

#define DCP_CTRL_TOG_PRESENT_SHA_MASK            (0x10000000U)
#define DCP_CTRL_TOG_PRESENT_SHA_SHIFT           (28U)
/*! PRESENT_SHA
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_TOG_PRESENT_SHA(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_PRESENT_SHA_SHIFT)) & DCP_CTRL_TOG_PRESENT_SHA_MASK)

#define DCP_CTRL_TOG_PRESENT_CRYPTO_MASK         (0x20000000U)
#define DCP_CTRL_TOG_PRESENT_CRYPTO_SHIFT        (29U)
/*! PRESENT_CRYPTO
 *  0b0..Absent
 *  0b1..Present
 */
#define DCP_CTRL_TOG_PRESENT_CRYPTO(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_PRESENT_CRYPTO_SHIFT)) & DCP_CTRL_TOG_PRESENT_CRYPTO_MASK)

#define DCP_CTRL_TOG_CLKGATE_MASK                (0x40000000U)
#define DCP_CTRL_TOG_CLKGATE_SHIFT               (30U)
#define DCP_CTRL_TOG_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_CLKGATE_SHIFT)) & DCP_CTRL_TOG_CLKGATE_MASK)

#define DCP_CTRL_TOG_SFTRST_MASK                 (0x80000000U)
#define DCP_CTRL_TOG_SFTRST_SHIFT                (31U)
#define DCP_CTRL_TOG_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CTRL_TOG_SFTRST_SHIFT)) & DCP_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STAT - DCP status register */
/*! @{ */

#define DCP_STAT_IRQ_MASK                        (0xFU)
#define DCP_STAT_IRQ_SHIFT                       (0U)
#define DCP_STAT_IRQ(x)                          (((uint32_t)(((uint32_t)(x)) << DCP_STAT_IRQ_SHIFT)) & DCP_STAT_IRQ_MASK)

#define DCP_STAT_RSVD_IRQ_MASK                   (0x100U)
#define DCP_STAT_RSVD_IRQ_SHIFT                  (8U)
#define DCP_STAT_RSVD_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_STAT_RSVD_IRQ_SHIFT)) & DCP_STAT_RSVD_IRQ_MASK)

#define DCP_STAT_READY_CHANNELS_MASK             (0xFF0000U)
#define DCP_STAT_READY_CHANNELS_SHIFT            (16U)
/*! READY_CHANNELS
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_STAT_READY_CHANNELS(x)               (((uint32_t)(((uint32_t)(x)) << DCP_STAT_READY_CHANNELS_SHIFT)) & DCP_STAT_READY_CHANNELS_MASK)

#define DCP_STAT_CUR_CHANNEL_MASK                (0xF000000U)
#define DCP_STAT_CUR_CHANNEL_SHIFT               (24U)
/*! CUR_CHANNEL
 *  0b0000..None
 *  0b0001..CH0
 *  0b0010..CH1
 *  0b0011..CH2
 *  0b0100..CH3
 */
#define DCP_STAT_CUR_CHANNEL(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CUR_CHANNEL_SHIFT)) & DCP_STAT_CUR_CHANNEL_MASK)

#define DCP_STAT_OTP_KEY_READY_MASK              (0x10000000U)
#define DCP_STAT_OTP_KEY_READY_SHIFT             (28U)
#define DCP_STAT_OTP_KEY_READY(x)                (((uint32_t)(((uint32_t)(x)) << DCP_STAT_OTP_KEY_READY_SHIFT)) & DCP_STAT_OTP_KEY_READY_MASK)
/*! @} */

/*! @name STAT_SET - DCP status register */
/*! @{ */

#define DCP_STAT_SET_IRQ_MASK                    (0xFU)
#define DCP_STAT_SET_IRQ_SHIFT                   (0U)
#define DCP_STAT_SET_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_STAT_SET_IRQ_SHIFT)) & DCP_STAT_SET_IRQ_MASK)

#define DCP_STAT_SET_RSVD_IRQ_MASK               (0x100U)
#define DCP_STAT_SET_RSVD_IRQ_SHIFT              (8U)
#define DCP_STAT_SET_RSVD_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_STAT_SET_RSVD_IRQ_SHIFT)) & DCP_STAT_SET_RSVD_IRQ_MASK)

#define DCP_STAT_SET_READY_CHANNELS_MASK         (0xFF0000U)
#define DCP_STAT_SET_READY_CHANNELS_SHIFT        (16U)
/*! READY_CHANNELS
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_STAT_SET_READY_CHANNELS(x)           (((uint32_t)(((uint32_t)(x)) << DCP_STAT_SET_READY_CHANNELS_SHIFT)) & DCP_STAT_SET_READY_CHANNELS_MASK)

#define DCP_STAT_SET_CUR_CHANNEL_MASK            (0xF000000U)
#define DCP_STAT_SET_CUR_CHANNEL_SHIFT           (24U)
/*! CUR_CHANNEL
 *  0b0000..None
 *  0b0001..CH0
 *  0b0010..CH1
 *  0b0011..CH2
 *  0b0100..CH3
 */
#define DCP_STAT_SET_CUR_CHANNEL(x)              (((uint32_t)(((uint32_t)(x)) << DCP_STAT_SET_CUR_CHANNEL_SHIFT)) & DCP_STAT_SET_CUR_CHANNEL_MASK)

#define DCP_STAT_SET_OTP_KEY_READY_MASK          (0x10000000U)
#define DCP_STAT_SET_OTP_KEY_READY_SHIFT         (28U)
#define DCP_STAT_SET_OTP_KEY_READY(x)            (((uint32_t)(((uint32_t)(x)) << DCP_STAT_SET_OTP_KEY_READY_SHIFT)) & DCP_STAT_SET_OTP_KEY_READY_MASK)
/*! @} */

/*! @name STAT_CLR - DCP status register */
/*! @{ */

#define DCP_STAT_CLR_IRQ_MASK                    (0xFU)
#define DCP_STAT_CLR_IRQ_SHIFT                   (0U)
#define DCP_STAT_CLR_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CLR_IRQ_SHIFT)) & DCP_STAT_CLR_IRQ_MASK)

#define DCP_STAT_CLR_RSVD_IRQ_MASK               (0x100U)
#define DCP_STAT_CLR_RSVD_IRQ_SHIFT              (8U)
#define DCP_STAT_CLR_RSVD_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CLR_RSVD_IRQ_SHIFT)) & DCP_STAT_CLR_RSVD_IRQ_MASK)

#define DCP_STAT_CLR_READY_CHANNELS_MASK         (0xFF0000U)
#define DCP_STAT_CLR_READY_CHANNELS_SHIFT        (16U)
/*! READY_CHANNELS
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_STAT_CLR_READY_CHANNELS(x)           (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CLR_READY_CHANNELS_SHIFT)) & DCP_STAT_CLR_READY_CHANNELS_MASK)

#define DCP_STAT_CLR_CUR_CHANNEL_MASK            (0xF000000U)
#define DCP_STAT_CLR_CUR_CHANNEL_SHIFT           (24U)
/*! CUR_CHANNEL
 *  0b0000..None
 *  0b0001..CH0
 *  0b0010..CH1
 *  0b0011..CH2
 *  0b0100..CH3
 */
#define DCP_STAT_CLR_CUR_CHANNEL(x)              (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CLR_CUR_CHANNEL_SHIFT)) & DCP_STAT_CLR_CUR_CHANNEL_MASK)

#define DCP_STAT_CLR_OTP_KEY_READY_MASK          (0x10000000U)
#define DCP_STAT_CLR_OTP_KEY_READY_SHIFT         (28U)
#define DCP_STAT_CLR_OTP_KEY_READY(x)            (((uint32_t)(((uint32_t)(x)) << DCP_STAT_CLR_OTP_KEY_READY_SHIFT)) & DCP_STAT_CLR_OTP_KEY_READY_MASK)
/*! @} */

/*! @name STAT_TOG - DCP status register */
/*! @{ */

#define DCP_STAT_TOG_IRQ_MASK                    (0xFU)
#define DCP_STAT_TOG_IRQ_SHIFT                   (0U)
#define DCP_STAT_TOG_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_STAT_TOG_IRQ_SHIFT)) & DCP_STAT_TOG_IRQ_MASK)

#define DCP_STAT_TOG_RSVD_IRQ_MASK               (0x100U)
#define DCP_STAT_TOG_RSVD_IRQ_SHIFT              (8U)
#define DCP_STAT_TOG_RSVD_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_STAT_TOG_RSVD_IRQ_SHIFT)) & DCP_STAT_TOG_RSVD_IRQ_MASK)

#define DCP_STAT_TOG_READY_CHANNELS_MASK         (0xFF0000U)
#define DCP_STAT_TOG_READY_CHANNELS_SHIFT        (16U)
/*! READY_CHANNELS
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_STAT_TOG_READY_CHANNELS(x)           (((uint32_t)(((uint32_t)(x)) << DCP_STAT_TOG_READY_CHANNELS_SHIFT)) & DCP_STAT_TOG_READY_CHANNELS_MASK)

#define DCP_STAT_TOG_CUR_CHANNEL_MASK            (0xF000000U)
#define DCP_STAT_TOG_CUR_CHANNEL_SHIFT           (24U)
/*! CUR_CHANNEL
 *  0b0000..None
 *  0b0001..CH0
 *  0b0010..CH1
 *  0b0011..CH2
 *  0b0100..CH3
 */
#define DCP_STAT_TOG_CUR_CHANNEL(x)              (((uint32_t)(((uint32_t)(x)) << DCP_STAT_TOG_CUR_CHANNEL_SHIFT)) & DCP_STAT_TOG_CUR_CHANNEL_MASK)

#define DCP_STAT_TOG_OTP_KEY_READY_MASK          (0x10000000U)
#define DCP_STAT_TOG_OTP_KEY_READY_SHIFT         (28U)
#define DCP_STAT_TOG_OTP_KEY_READY(x)            (((uint32_t)(((uint32_t)(x)) << DCP_STAT_TOG_OTP_KEY_READY_SHIFT)) & DCP_STAT_TOG_OTP_KEY_READY_MASK)
/*! @} */

/*! @name CHANNELCTRL - DCP channel control register */
/*! @{ */

#define DCP_CHANNELCTRL_ENABLE_CHANNEL_MASK      (0xFFU)
#define DCP_CHANNELCTRL_ENABLE_CHANNEL_SHIFT     (0U)
/*! ENABLE_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_ENABLE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_ENABLE_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_ENABLE_CHANNEL_MASK)

#define DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL_MASK (0xFF00U)
#define DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL_SHIFT (8U)
/*! HIGH_PRIORITY_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL_MASK)

#define DCP_CHANNELCTRL_CH0_IRQ_MERGED_MASK      (0x10000U)
#define DCP_CHANNELCTRL_CH0_IRQ_MERGED_SHIFT     (16U)
#define DCP_CHANNELCTRL_CH0_IRQ_MERGED(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_CH0_IRQ_MERGED_SHIFT)) & DCP_CHANNELCTRL_CH0_IRQ_MERGED_MASK)

#define DCP_CHANNELCTRL_RSVD_MASK                (0xFFFE0000U)
#define DCP_CHANNELCTRL_RSVD_SHIFT               (17U)
#define DCP_CHANNELCTRL_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_RSVD_SHIFT)) & DCP_CHANNELCTRL_RSVD_MASK)
/*! @} */

/*! @name CHANNELCTRL_SET - DCP channel control register */
/*! @{ */

#define DCP_CHANNELCTRL_SET_ENABLE_CHANNEL_MASK  (0xFFU)
#define DCP_CHANNELCTRL_SET_ENABLE_CHANNEL_SHIFT (0U)
/*! ENABLE_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_SET_ENABLE_CHANNEL(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_SET_ENABLE_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_SET_ENABLE_CHANNEL_MASK)

#define DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL_MASK (0xFF00U)
#define DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL_SHIFT (8U)
/*! HIGH_PRIORITY_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL_MASK)

#define DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED_MASK  (0x10000U)
#define DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED_SHIFT (16U)
#define DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED_SHIFT)) & DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED_MASK)

#define DCP_CHANNELCTRL_SET_RSVD_MASK            (0xFFFE0000U)
#define DCP_CHANNELCTRL_SET_RSVD_SHIFT           (17U)
#define DCP_CHANNELCTRL_SET_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_SET_RSVD_SHIFT)) & DCP_CHANNELCTRL_SET_RSVD_MASK)
/*! @} */

/*! @name CHANNELCTRL_CLR - DCP channel control register */
/*! @{ */

#define DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL_MASK  (0xFFU)
#define DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL_SHIFT (0U)
/*! ENABLE_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL_MASK)

#define DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL_MASK (0xFF00U)
#define DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL_SHIFT (8U)
/*! HIGH_PRIORITY_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL_MASK)

#define DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED_MASK  (0x10000U)
#define DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED_SHIFT (16U)
#define DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED_SHIFT)) & DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED_MASK)

#define DCP_CHANNELCTRL_CLR_RSVD_MASK            (0xFFFE0000U)
#define DCP_CHANNELCTRL_CLR_RSVD_SHIFT           (17U)
#define DCP_CHANNELCTRL_CLR_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_CLR_RSVD_SHIFT)) & DCP_CHANNELCTRL_CLR_RSVD_MASK)
/*! @} */

/*! @name CHANNELCTRL_TOG - DCP channel control register */
/*! @{ */

#define DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL_MASK  (0xFFU)
#define DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL_SHIFT (0U)
/*! ENABLE_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL_MASK)

#define DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL_MASK (0xFF00U)
#define DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL_SHIFT (8U)
/*! HIGH_PRIORITY_CHANNEL
 *  0b00000001..CH0
 *  0b00000010..CH1
 *  0b00000100..CH2
 *  0b00001000..CH3
 */
#define DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL_SHIFT)) & DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL_MASK)

#define DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED_MASK  (0x10000U)
#define DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED_SHIFT (16U)
#define DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED_SHIFT)) & DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED_MASK)

#define DCP_CHANNELCTRL_TOG_RSVD_MASK            (0xFFFE0000U)
#define DCP_CHANNELCTRL_TOG_RSVD_SHIFT           (17U)
#define DCP_CHANNELCTRL_TOG_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CHANNELCTRL_TOG_RSVD_SHIFT)) & DCP_CHANNELCTRL_TOG_RSVD_MASK)
/*! @} */

/*! @name CAPABILITY0 - DCP capability 0 register */
/*! @{ */

#define DCP_CAPABILITY0_NUM_KEYS_MASK            (0xFFU)
#define DCP_CAPABILITY0_NUM_KEYS_SHIFT           (0U)
#define DCP_CAPABILITY0_NUM_KEYS(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY0_NUM_KEYS_SHIFT)) & DCP_CAPABILITY0_NUM_KEYS_MASK)

#define DCP_CAPABILITY0_NUM_CHANNELS_MASK        (0xF00U)
#define DCP_CAPABILITY0_NUM_CHANNELS_SHIFT       (8U)
#define DCP_CAPABILITY0_NUM_CHANNELS(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY0_NUM_CHANNELS_SHIFT)) & DCP_CAPABILITY0_NUM_CHANNELS_MASK)

#define DCP_CAPABILITY0_RSVD_MASK                (0x1FFFF000U)
#define DCP_CAPABILITY0_RSVD_SHIFT               (12U)
#define DCP_CAPABILITY0_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY0_RSVD_SHIFT)) & DCP_CAPABILITY0_RSVD_MASK)

#define DCP_CAPABILITY0_DISABLE_UNIQUE_KEY_MASK  (0x20000000U)
#define DCP_CAPABILITY0_DISABLE_UNIQUE_KEY_SHIFT (29U)
#define DCP_CAPABILITY0_DISABLE_UNIQUE_KEY(x)    (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY0_DISABLE_UNIQUE_KEY_SHIFT)) & DCP_CAPABILITY0_DISABLE_UNIQUE_KEY_MASK)

#define DCP_CAPABILITY0_DISABLE_DECRYPT_MASK     (0x80000000U)
#define DCP_CAPABILITY0_DISABLE_DECRYPT_SHIFT    (31U)
#define DCP_CAPABILITY0_DISABLE_DECRYPT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY0_DISABLE_DECRYPT_SHIFT)) & DCP_CAPABILITY0_DISABLE_DECRYPT_MASK)
/*! @} */

/*! @name CAPABILITY1 - DCP capability 1 register */
/*! @{ */

#define DCP_CAPABILITY1_CIPHER_ALGORITHMS_MASK   (0xFFFFU)
#define DCP_CAPABILITY1_CIPHER_ALGORITHMS_SHIFT  (0U)
/*! CIPHER_ALGORITHMS
 *  0b0000000000000001..AES128
 */
#define DCP_CAPABILITY1_CIPHER_ALGORITHMS(x)     (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY1_CIPHER_ALGORITHMS_SHIFT)) & DCP_CAPABILITY1_CIPHER_ALGORITHMS_MASK)

#define DCP_CAPABILITY1_HASH_ALGORITHMS_MASK     (0xFFFF0000U)
#define DCP_CAPABILITY1_HASH_ALGORITHMS_SHIFT    (16U)
/*! HASH_ALGORITHMS
 *  0b0000000000000001..SHA1
 *  0b0000000000000010..CRC32
 *  0b0000000000000100..SHA256
 */
#define DCP_CAPABILITY1_HASH_ALGORITHMS(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CAPABILITY1_HASH_ALGORITHMS_SHIFT)) & DCP_CAPABILITY1_HASH_ALGORITHMS_MASK)
/*! @} */

/*! @name CONTEXT - DCP context buffer pointer */
/*! @{ */

#define DCP_CONTEXT_ADDR_MASK                    (0xFFFFFFFFU)
#define DCP_CONTEXT_ADDR_SHIFT                   (0U)
#define DCP_CONTEXT_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CONTEXT_ADDR_SHIFT)) & DCP_CONTEXT_ADDR_MASK)
/*! @} */

/*! @name KEY - DCP key index */
/*! @{ */

#define DCP_KEY_SUBWORD_MASK                     (0x3U)
#define DCP_KEY_SUBWORD_SHIFT                    (0U)
#define DCP_KEY_SUBWORD(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_KEY_SUBWORD_SHIFT)) & DCP_KEY_SUBWORD_MASK)

#define DCP_KEY_RSVD_SUBWORD_MASK                (0xCU)
#define DCP_KEY_RSVD_SUBWORD_SHIFT               (2U)
#define DCP_KEY_RSVD_SUBWORD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_KEY_RSVD_SUBWORD_SHIFT)) & DCP_KEY_RSVD_SUBWORD_MASK)

#define DCP_KEY_INDEX_MASK                       (0x30U)
#define DCP_KEY_INDEX_SHIFT                      (4U)
#define DCP_KEY_INDEX(x)                         (((uint32_t)(((uint32_t)(x)) << DCP_KEY_INDEX_SHIFT)) & DCP_KEY_INDEX_MASK)

#define DCP_KEY_RSVD_INDEX_MASK                  (0xC0U)
#define DCP_KEY_RSVD_INDEX_SHIFT                 (6U)
#define DCP_KEY_RSVD_INDEX(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_KEY_RSVD_INDEX_SHIFT)) & DCP_KEY_RSVD_INDEX_MASK)

#define DCP_KEY_RSVD_MASK                        (0xFFFFFF00U)
#define DCP_KEY_RSVD_SHIFT                       (8U)
#define DCP_KEY_RSVD(x)                          (((uint32_t)(((uint32_t)(x)) << DCP_KEY_RSVD_SHIFT)) & DCP_KEY_RSVD_MASK)
/*! @} */

/*! @name KEYDATA - DCP key data */
/*! @{ */

#define DCP_KEYDATA_DATA_MASK                    (0xFFFFFFFFU)
#define DCP_KEYDATA_DATA_SHIFT                   (0U)
#define DCP_KEYDATA_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_KEYDATA_DATA_SHIFT)) & DCP_KEYDATA_DATA_MASK)
/*! @} */

/*! @name PACKET0 - DCP work packet 0 status register */
/*! @{ */

#define DCP_PACKET0_ADDR_MASK                    (0xFFFFFFFFU)
#define DCP_PACKET0_ADDR_SHIFT                   (0U)
#define DCP_PACKET0_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_PACKET0_ADDR_SHIFT)) & DCP_PACKET0_ADDR_MASK)
/*! @} */

/*! @name PACKET1 - DCP work packet 1 status register */
/*! @{ */

#define DCP_PACKET1_INTERRUPT_MASK               (0x1U)
#define DCP_PACKET1_INTERRUPT_SHIFT              (0U)
#define DCP_PACKET1_INTERRUPT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_INTERRUPT_SHIFT)) & DCP_PACKET1_INTERRUPT_MASK)

#define DCP_PACKET1_DECR_SEMAPHORE_MASK          (0x2U)
#define DCP_PACKET1_DECR_SEMAPHORE_SHIFT         (1U)
#define DCP_PACKET1_DECR_SEMAPHORE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_DECR_SEMAPHORE_SHIFT)) & DCP_PACKET1_DECR_SEMAPHORE_MASK)

#define DCP_PACKET1_CHAIN_MASK                   (0x4U)
#define DCP_PACKET1_CHAIN_SHIFT                  (2U)
#define DCP_PACKET1_CHAIN(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CHAIN_SHIFT)) & DCP_PACKET1_CHAIN_MASK)

#define DCP_PACKET1_CHAIN_CONTIGUOUS_MASK        (0x8U)
#define DCP_PACKET1_CHAIN_CONTIGUOUS_SHIFT       (3U)
#define DCP_PACKET1_CHAIN_CONTIGUOUS(x)          (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CHAIN_CONTIGUOUS_SHIFT)) & DCP_PACKET1_CHAIN_CONTIGUOUS_MASK)

#define DCP_PACKET1_ENABLE_MEMCOPY_MASK          (0x10U)
#define DCP_PACKET1_ENABLE_MEMCOPY_SHIFT         (4U)
#define DCP_PACKET1_ENABLE_MEMCOPY(x)            (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_ENABLE_MEMCOPY_SHIFT)) & DCP_PACKET1_ENABLE_MEMCOPY_MASK)

#define DCP_PACKET1_ENABLE_CIPHER_MASK           (0x20U)
#define DCP_PACKET1_ENABLE_CIPHER_SHIFT          (5U)
#define DCP_PACKET1_ENABLE_CIPHER(x)             (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_ENABLE_CIPHER_SHIFT)) & DCP_PACKET1_ENABLE_CIPHER_MASK)

#define DCP_PACKET1_ENABLE_HASH_MASK             (0x40U)
#define DCP_PACKET1_ENABLE_HASH_SHIFT            (6U)
#define DCP_PACKET1_ENABLE_HASH(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_ENABLE_HASH_SHIFT)) & DCP_PACKET1_ENABLE_HASH_MASK)

#define DCP_PACKET1_ENABLE_BLIT_MASK             (0x80U)
#define DCP_PACKET1_ENABLE_BLIT_SHIFT            (7U)
#define DCP_PACKET1_ENABLE_BLIT(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_ENABLE_BLIT_SHIFT)) & DCP_PACKET1_ENABLE_BLIT_MASK)

#define DCP_PACKET1_CIPHER_ENCRYPT_MASK          (0x100U)
#define DCP_PACKET1_CIPHER_ENCRYPT_SHIFT         (8U)
/*! CIPHER_ENCRYPT
 *  0b0..DECRYPT
 *  0b1..ENCRYPT
 */
#define DCP_PACKET1_CIPHER_ENCRYPT(x)            (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CIPHER_ENCRYPT_SHIFT)) & DCP_PACKET1_CIPHER_ENCRYPT_MASK)

#define DCP_PACKET1_CIPHER_INIT_MASK             (0x200U)
#define DCP_PACKET1_CIPHER_INIT_SHIFT            (9U)
#define DCP_PACKET1_CIPHER_INIT(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CIPHER_INIT_SHIFT)) & DCP_PACKET1_CIPHER_INIT_MASK)

#define DCP_PACKET1_OTP_KEY_MASK                 (0x400U)
#define DCP_PACKET1_OTP_KEY_SHIFT                (10U)
#define DCP_PACKET1_OTP_KEY(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_OTP_KEY_SHIFT)) & DCP_PACKET1_OTP_KEY_MASK)

#define DCP_PACKET1_PAYLOAD_KEY_MASK             (0x800U)
#define DCP_PACKET1_PAYLOAD_KEY_SHIFT            (11U)
#define DCP_PACKET1_PAYLOAD_KEY(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_PAYLOAD_KEY_SHIFT)) & DCP_PACKET1_PAYLOAD_KEY_MASK)

#define DCP_PACKET1_HASH_INIT_MASK               (0x1000U)
#define DCP_PACKET1_HASH_INIT_SHIFT              (12U)
#define DCP_PACKET1_HASH_INIT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_HASH_INIT_SHIFT)) & DCP_PACKET1_HASH_INIT_MASK)

#define DCP_PACKET1_HASH_TERM_MASK               (0x2000U)
#define DCP_PACKET1_HASH_TERM_SHIFT              (13U)
#define DCP_PACKET1_HASH_TERM(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_HASH_TERM_SHIFT)) & DCP_PACKET1_HASH_TERM_MASK)

#define DCP_PACKET1_CHECK_HASH_MASK              (0x4000U)
#define DCP_PACKET1_CHECK_HASH_SHIFT             (14U)
#define DCP_PACKET1_CHECK_HASH(x)                (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CHECK_HASH_SHIFT)) & DCP_PACKET1_CHECK_HASH_MASK)

#define DCP_PACKET1_HASH_OUTPUT_MASK             (0x8000U)
#define DCP_PACKET1_HASH_OUTPUT_SHIFT            (15U)
/*! HASH_OUTPUT
 *  0b0..INPUT
 *  0b1..OUTPUT
 */
#define DCP_PACKET1_HASH_OUTPUT(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_HASH_OUTPUT_SHIFT)) & DCP_PACKET1_HASH_OUTPUT_MASK)

#define DCP_PACKET1_CONSTANT_FILL_MASK           (0x10000U)
#define DCP_PACKET1_CONSTANT_FILL_SHIFT          (16U)
#define DCP_PACKET1_CONSTANT_FILL(x)             (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_CONSTANT_FILL_SHIFT)) & DCP_PACKET1_CONSTANT_FILL_MASK)

#define DCP_PACKET1_TEST_SEMA_IRQ_MASK           (0x20000U)
#define DCP_PACKET1_TEST_SEMA_IRQ_SHIFT          (17U)
#define DCP_PACKET1_TEST_SEMA_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_TEST_SEMA_IRQ_SHIFT)) & DCP_PACKET1_TEST_SEMA_IRQ_MASK)

#define DCP_PACKET1_KEY_BYTESWAP_MASK            (0x40000U)
#define DCP_PACKET1_KEY_BYTESWAP_SHIFT           (18U)
#define DCP_PACKET1_KEY_BYTESWAP(x)              (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_KEY_BYTESWAP_SHIFT)) & DCP_PACKET1_KEY_BYTESWAP_MASK)

#define DCP_PACKET1_KEY_WORDSWAP_MASK            (0x80000U)
#define DCP_PACKET1_KEY_WORDSWAP_SHIFT           (19U)
#define DCP_PACKET1_KEY_WORDSWAP(x)              (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_KEY_WORDSWAP_SHIFT)) & DCP_PACKET1_KEY_WORDSWAP_MASK)

#define DCP_PACKET1_INPUT_BYTESWAP_MASK          (0x100000U)
#define DCP_PACKET1_INPUT_BYTESWAP_SHIFT         (20U)
#define DCP_PACKET1_INPUT_BYTESWAP(x)            (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_INPUT_BYTESWAP_SHIFT)) & DCP_PACKET1_INPUT_BYTESWAP_MASK)

#define DCP_PACKET1_INPUT_WORDSWAP_MASK          (0x200000U)
#define DCP_PACKET1_INPUT_WORDSWAP_SHIFT         (21U)
#define DCP_PACKET1_INPUT_WORDSWAP(x)            (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_INPUT_WORDSWAP_SHIFT)) & DCP_PACKET1_INPUT_WORDSWAP_MASK)

#define DCP_PACKET1_OUTPUT_BYTESWAP_MASK         (0x400000U)
#define DCP_PACKET1_OUTPUT_BYTESWAP_SHIFT        (22U)
#define DCP_PACKET1_OUTPUT_BYTESWAP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_OUTPUT_BYTESWAP_SHIFT)) & DCP_PACKET1_OUTPUT_BYTESWAP_MASK)

#define DCP_PACKET1_OUTPUT_WORDSWAP_MASK         (0x800000U)
#define DCP_PACKET1_OUTPUT_WORDSWAP_SHIFT        (23U)
#define DCP_PACKET1_OUTPUT_WORDSWAP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_OUTPUT_WORDSWAP_SHIFT)) & DCP_PACKET1_OUTPUT_WORDSWAP_MASK)

#define DCP_PACKET1_TAG_MASK                     (0xFF000000U)
#define DCP_PACKET1_TAG_SHIFT                    (24U)
#define DCP_PACKET1_TAG(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_PACKET1_TAG_SHIFT)) & DCP_PACKET1_TAG_MASK)
/*! @} */

/*! @name PACKET2 - DCP work packet 2 status register */
/*! @{ */

#define DCP_PACKET2_CIPHER_SELECT_MASK           (0xFU)
#define DCP_PACKET2_CIPHER_SELECT_SHIFT          (0U)
/*! CIPHER_SELECT
 *  0b0000..AES128
 */
#define DCP_PACKET2_CIPHER_SELECT(x)             (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_CIPHER_SELECT_SHIFT)) & DCP_PACKET2_CIPHER_SELECT_MASK)

#define DCP_PACKET2_CIPHER_MODE_MASK             (0xF0U)
#define DCP_PACKET2_CIPHER_MODE_SHIFT            (4U)
/*! CIPHER_MODE
 *  0b0000..ECB
 *  0b0001..CBC
 */
#define DCP_PACKET2_CIPHER_MODE(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_CIPHER_MODE_SHIFT)) & DCP_PACKET2_CIPHER_MODE_MASK)

#define DCP_PACKET2_KEY_SELECT_MASK              (0xFF00U)
#define DCP_PACKET2_KEY_SELECT_SHIFT             (8U)
/*! KEY_SELECT
 *  0b00000000..KEY0
 *  0b00000001..KEY1
 *  0b00000010..KEY2
 *  0b00000011..KEY3
 *  0b11111110..UNIQUE_KEY
 *  0b11111111..OTP_KEY
 */
#define DCP_PACKET2_KEY_SELECT(x)                (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_KEY_SELECT_SHIFT)) & DCP_PACKET2_KEY_SELECT_MASK)

#define DCP_PACKET2_HASH_SELECT_MASK             (0xF0000U)
#define DCP_PACKET2_HASH_SELECT_SHIFT            (16U)
/*! HASH_SELECT
 *  0b0000..SHA1
 *  0b0001..CRC32
 *  0b0010..SHA256
 */
#define DCP_PACKET2_HASH_SELECT(x)               (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_HASH_SELECT_SHIFT)) & DCP_PACKET2_HASH_SELECT_MASK)

#define DCP_PACKET2_RSVD_MASK                    (0xF00000U)
#define DCP_PACKET2_RSVD_SHIFT                   (20U)
#define DCP_PACKET2_RSVD(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_RSVD_SHIFT)) & DCP_PACKET2_RSVD_MASK)

#define DCP_PACKET2_CIPHER_CFG_MASK              (0xFF000000U)
#define DCP_PACKET2_CIPHER_CFG_SHIFT             (24U)
#define DCP_PACKET2_CIPHER_CFG(x)                (((uint32_t)(((uint32_t)(x)) << DCP_PACKET2_CIPHER_CFG_SHIFT)) & DCP_PACKET2_CIPHER_CFG_MASK)
/*! @} */

/*! @name PACKET3 - DCP work packet 3 status register */
/*! @{ */

#define DCP_PACKET3_ADDR_MASK                    (0xFFFFFFFFU)
#define DCP_PACKET3_ADDR_SHIFT                   (0U)
#define DCP_PACKET3_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_PACKET3_ADDR_SHIFT)) & DCP_PACKET3_ADDR_MASK)
/*! @} */

/*! @name PACKET4 - DCP work packet 4 status register */
/*! @{ */

#define DCP_PACKET4_ADDR_MASK                    (0xFFFFFFFFU)
#define DCP_PACKET4_ADDR_SHIFT                   (0U)
#define DCP_PACKET4_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_PACKET4_ADDR_SHIFT)) & DCP_PACKET4_ADDR_MASK)
/*! @} */

/*! @name PACKET5 - DCP work packet 5 status register */
/*! @{ */

#define DCP_PACKET5_COUNT_MASK                   (0xFFFFFFFFU)
#define DCP_PACKET5_COUNT_SHIFT                  (0U)
#define DCP_PACKET5_COUNT(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_PACKET5_COUNT_SHIFT)) & DCP_PACKET5_COUNT_MASK)
/*! @} */

/*! @name PACKET6 - DCP work packet 6 status register */
/*! @{ */

#define DCP_PACKET6_ADDR_MASK                    (0xFFFFFFFFU)
#define DCP_PACKET6_ADDR_SHIFT                   (0U)
#define DCP_PACKET6_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_PACKET6_ADDR_SHIFT)) & DCP_PACKET6_ADDR_MASK)
/*! @} */

/*! @name CH0CMDPTR - DCP channel 0 command pointer address register */
/*! @{ */

#define DCP_CH0CMDPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define DCP_CH0CMDPTR_ADDR_SHIFT                 (0U)
#define DCP_CH0CMDPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_CH0CMDPTR_ADDR_SHIFT)) & DCP_CH0CMDPTR_ADDR_MASK)
/*! @} */

/*! @name CH0SEMA - DCP channel 0 semaphore register */
/*! @{ */

#define DCP_CH0SEMA_INCREMENT_MASK               (0xFFU)
#define DCP_CH0SEMA_INCREMENT_SHIFT              (0U)
#define DCP_CH0SEMA_INCREMENT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH0SEMA_INCREMENT_SHIFT)) & DCP_CH0SEMA_INCREMENT_MASK)

#define DCP_CH0SEMA_VALUE_MASK                   (0xFF0000U)
#define DCP_CH0SEMA_VALUE_SHIFT                  (16U)
#define DCP_CH0SEMA_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_CH0SEMA_VALUE_SHIFT)) & DCP_CH0SEMA_VALUE_MASK)
/*! @} */

/*! @name CH0STAT - DCP channel 0 status register */
/*! @{ */

#define DCP_CH0STAT_RSVD_COMPLETE_MASK           (0x1U)
#define DCP_CH0STAT_RSVD_COMPLETE_SHIFT          (0U)
#define DCP_CH0STAT_RSVD_COMPLETE(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_RSVD_COMPLETE_SHIFT)) & DCP_CH0STAT_RSVD_COMPLETE_MASK)

#define DCP_CH0STAT_HASH_MISMATCH_MASK           (0x2U)
#define DCP_CH0STAT_HASH_MISMATCH_SHIFT          (1U)
#define DCP_CH0STAT_HASH_MISMATCH(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_HASH_MISMATCH_SHIFT)) & DCP_CH0STAT_HASH_MISMATCH_MASK)

#define DCP_CH0STAT_ERROR_SETUP_MASK             (0x4U)
#define DCP_CH0STAT_ERROR_SETUP_SHIFT            (2U)
#define DCP_CH0STAT_ERROR_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_SETUP_SHIFT)) & DCP_CH0STAT_ERROR_SETUP_MASK)

#define DCP_CH0STAT_ERROR_PACKET_MASK            (0x8U)
#define DCP_CH0STAT_ERROR_PACKET_SHIFT           (3U)
#define DCP_CH0STAT_ERROR_PACKET(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_PACKET_SHIFT)) & DCP_CH0STAT_ERROR_PACKET_MASK)

#define DCP_CH0STAT_ERROR_SRC_MASK               (0x10U)
#define DCP_CH0STAT_ERROR_SRC_SHIFT              (4U)
#define DCP_CH0STAT_ERROR_SRC(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_SRC_SHIFT)) & DCP_CH0STAT_ERROR_SRC_MASK)

#define DCP_CH0STAT_ERROR_DST_MASK               (0x20U)
#define DCP_CH0STAT_ERROR_DST_SHIFT              (5U)
#define DCP_CH0STAT_ERROR_DST(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_DST_SHIFT)) & DCP_CH0STAT_ERROR_DST_MASK)

#define DCP_CH0STAT_ERROR_PAGEFAULT_MASK         (0x40U)
#define DCP_CH0STAT_ERROR_PAGEFAULT_SHIFT        (6U)
#define DCP_CH0STAT_ERROR_PAGEFAULT(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_PAGEFAULT_SHIFT)) & DCP_CH0STAT_ERROR_PAGEFAULT_MASK)

#define DCP_CH0STAT_ERROR_CODE_MASK              (0xFF0000U)
#define DCP_CH0STAT_ERROR_CODE_SHIFT             (16U)
/*! ERROR_CODE
 *  0b00000001..Error signalled because the next pointer is 0x00000000
 *  0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
 *  0b00000011..Error signalled because an error is reported reading/writing the context buffer
 *  0b00000100..Error signalled because an error is reported reading/writing the payload
 *  0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
 */
#define DCP_CH0STAT_ERROR_CODE(x)                (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_ERROR_CODE_SHIFT)) & DCP_CH0STAT_ERROR_CODE_MASK)

#define DCP_CH0STAT_TAG_MASK                     (0xFF000000U)
#define DCP_CH0STAT_TAG_SHIFT                    (24U)
#define DCP_CH0STAT_TAG(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TAG_SHIFT)) & DCP_CH0STAT_TAG_MASK)
/*! @} */

/*! @name CH0STAT_SET - DCP channel 0 status register */
/*! @{ */

#define DCP_CH0STAT_SET_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH0STAT_SET_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH0STAT_SET_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_RSVD_COMPLETE_SHIFT)) & DCP_CH0STAT_SET_RSVD_COMPLETE_MASK)

#define DCP_CH0STAT_SET_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH0STAT_SET_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH0STAT_SET_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_HASH_MISMATCH_SHIFT)) & DCP_CH0STAT_SET_HASH_MISMATCH_MASK)

#define DCP_CH0STAT_SET_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH0STAT_SET_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH0STAT_SET_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_SETUP_SHIFT)) & DCP_CH0STAT_SET_ERROR_SETUP_MASK)

#define DCP_CH0STAT_SET_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH0STAT_SET_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH0STAT_SET_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_PACKET_SHIFT)) & DCP_CH0STAT_SET_ERROR_PACKET_MASK)

#define DCP_CH0STAT_SET_ERROR_SRC_MASK           (0x10U)
#define DCP_CH0STAT_SET_ERROR_SRC_SHIFT          (4U)
#define DCP_CH0STAT_SET_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_SRC_SHIFT)) & DCP_CH0STAT_SET_ERROR_SRC_MASK)

#define DCP_CH0STAT_SET_ERROR_DST_MASK           (0x20U)
#define DCP_CH0STAT_SET_ERROR_DST_SHIFT          (5U)
#define DCP_CH0STAT_SET_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_DST_SHIFT)) & DCP_CH0STAT_SET_ERROR_DST_MASK)

#define DCP_CH0STAT_SET_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH0STAT_SET_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH0STAT_SET_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_PAGEFAULT_SHIFT)) & DCP_CH0STAT_SET_ERROR_PAGEFAULT_MASK)

#define DCP_CH0STAT_SET_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH0STAT_SET_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error signalled because the next pointer is 0x00000000
 *  0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
 *  0b00000011..Error signalled because an error is reported reading/writing the context buffer
 *  0b00000100..Error signalled because an error is reported reading/writing the payload
 *  0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
 */
#define DCP_CH0STAT_SET_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_ERROR_CODE_SHIFT)) & DCP_CH0STAT_SET_ERROR_CODE_MASK)

#define DCP_CH0STAT_SET_TAG_MASK                 (0xFF000000U)
#define DCP_CH0STAT_SET_TAG_SHIFT                (24U)
#define DCP_CH0STAT_SET_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_SET_TAG_SHIFT)) & DCP_CH0STAT_SET_TAG_MASK)
/*! @} */

/*! @name CH0STAT_CLR - DCP channel 0 status register */
/*! @{ */

#define DCP_CH0STAT_CLR_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH0STAT_CLR_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH0STAT_CLR_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_RSVD_COMPLETE_SHIFT)) & DCP_CH0STAT_CLR_RSVD_COMPLETE_MASK)

#define DCP_CH0STAT_CLR_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH0STAT_CLR_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH0STAT_CLR_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_HASH_MISMATCH_SHIFT)) & DCP_CH0STAT_CLR_HASH_MISMATCH_MASK)

#define DCP_CH0STAT_CLR_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH0STAT_CLR_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH0STAT_CLR_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_SETUP_SHIFT)) & DCP_CH0STAT_CLR_ERROR_SETUP_MASK)

#define DCP_CH0STAT_CLR_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH0STAT_CLR_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH0STAT_CLR_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_PACKET_SHIFT)) & DCP_CH0STAT_CLR_ERROR_PACKET_MASK)

#define DCP_CH0STAT_CLR_ERROR_SRC_MASK           (0x10U)
#define DCP_CH0STAT_CLR_ERROR_SRC_SHIFT          (4U)
#define DCP_CH0STAT_CLR_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_SRC_SHIFT)) & DCP_CH0STAT_CLR_ERROR_SRC_MASK)

#define DCP_CH0STAT_CLR_ERROR_DST_MASK           (0x20U)
#define DCP_CH0STAT_CLR_ERROR_DST_SHIFT          (5U)
#define DCP_CH0STAT_CLR_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_DST_SHIFT)) & DCP_CH0STAT_CLR_ERROR_DST_MASK)

#define DCP_CH0STAT_CLR_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH0STAT_CLR_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH0STAT_CLR_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_PAGEFAULT_SHIFT)) & DCP_CH0STAT_CLR_ERROR_PAGEFAULT_MASK)

#define DCP_CH0STAT_CLR_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH0STAT_CLR_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error signalled because the next pointer is 0x00000000
 *  0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
 *  0b00000011..Error signalled because an error is reported reading/writing the context buffer
 *  0b00000100..Error signalled because an error is reported reading/writing the payload
 *  0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
 */
#define DCP_CH0STAT_CLR_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_ERROR_CODE_SHIFT)) & DCP_CH0STAT_CLR_ERROR_CODE_MASK)

#define DCP_CH0STAT_CLR_TAG_MASK                 (0xFF000000U)
#define DCP_CH0STAT_CLR_TAG_SHIFT                (24U)
#define DCP_CH0STAT_CLR_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_CLR_TAG_SHIFT)) & DCP_CH0STAT_CLR_TAG_MASK)
/*! @} */

/*! @name CH0STAT_TOG - DCP channel 0 status register */
/*! @{ */

#define DCP_CH0STAT_TOG_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH0STAT_TOG_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH0STAT_TOG_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_RSVD_COMPLETE_SHIFT)) & DCP_CH0STAT_TOG_RSVD_COMPLETE_MASK)

#define DCP_CH0STAT_TOG_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH0STAT_TOG_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH0STAT_TOG_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_HASH_MISMATCH_SHIFT)) & DCP_CH0STAT_TOG_HASH_MISMATCH_MASK)

#define DCP_CH0STAT_TOG_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH0STAT_TOG_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH0STAT_TOG_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_SETUP_SHIFT)) & DCP_CH0STAT_TOG_ERROR_SETUP_MASK)

#define DCP_CH0STAT_TOG_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH0STAT_TOG_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH0STAT_TOG_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_PACKET_SHIFT)) & DCP_CH0STAT_TOG_ERROR_PACKET_MASK)

#define DCP_CH0STAT_TOG_ERROR_SRC_MASK           (0x10U)
#define DCP_CH0STAT_TOG_ERROR_SRC_SHIFT          (4U)
#define DCP_CH0STAT_TOG_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_SRC_SHIFT)) & DCP_CH0STAT_TOG_ERROR_SRC_MASK)

#define DCP_CH0STAT_TOG_ERROR_DST_MASK           (0x20U)
#define DCP_CH0STAT_TOG_ERROR_DST_SHIFT          (5U)
#define DCP_CH0STAT_TOG_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_DST_SHIFT)) & DCP_CH0STAT_TOG_ERROR_DST_MASK)

#define DCP_CH0STAT_TOG_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH0STAT_TOG_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH0STAT_TOG_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_PAGEFAULT_SHIFT)) & DCP_CH0STAT_TOG_ERROR_PAGEFAULT_MASK)

#define DCP_CH0STAT_TOG_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH0STAT_TOG_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error signalled because the next pointer is 0x00000000
 *  0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
 *  0b00000011..Error signalled because an error is reported reading/writing the context buffer
 *  0b00000100..Error signalled because an error is reported reading/writing the payload
 *  0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
 */
#define DCP_CH0STAT_TOG_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_ERROR_CODE_SHIFT)) & DCP_CH0STAT_TOG_ERROR_CODE_MASK)

#define DCP_CH0STAT_TOG_TAG_MASK                 (0xFF000000U)
#define DCP_CH0STAT_TOG_TAG_SHIFT                (24U)
#define DCP_CH0STAT_TOG_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH0STAT_TOG_TAG_SHIFT)) & DCP_CH0STAT_TOG_TAG_MASK)
/*! @} */

/*! @name CH0OPTS - DCP channel 0 options register */
/*! @{ */

#define DCP_CH0OPTS_RECOVERY_TIMER_MASK          (0xFFFFU)
#define DCP_CH0OPTS_RECOVERY_TIMER_SHIFT         (0U)
#define DCP_CH0OPTS_RECOVERY_TIMER(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_RECOVERY_TIMER_SHIFT)) & DCP_CH0OPTS_RECOVERY_TIMER_MASK)

#define DCP_CH0OPTS_RSVD_MASK                    (0xFFFF0000U)
#define DCP_CH0OPTS_RSVD_SHIFT                   (16U)
#define DCP_CH0OPTS_RSVD(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_RSVD_SHIFT)) & DCP_CH0OPTS_RSVD_MASK)
/*! @} */

/*! @name CH0OPTS_SET - DCP channel 0 options register */
/*! @{ */

#define DCP_CH0OPTS_SET_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH0OPTS_SET_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH0OPTS_SET_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_SET_RECOVERY_TIMER_SHIFT)) & DCP_CH0OPTS_SET_RECOVERY_TIMER_MASK)

#define DCP_CH0OPTS_SET_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH0OPTS_SET_RSVD_SHIFT               (16U)
#define DCP_CH0OPTS_SET_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_SET_RSVD_SHIFT)) & DCP_CH0OPTS_SET_RSVD_MASK)
/*! @} */

/*! @name CH0OPTS_CLR - DCP channel 0 options register */
/*! @{ */

#define DCP_CH0OPTS_CLR_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH0OPTS_CLR_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH0OPTS_CLR_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_CLR_RECOVERY_TIMER_SHIFT)) & DCP_CH0OPTS_CLR_RECOVERY_TIMER_MASK)

#define DCP_CH0OPTS_CLR_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH0OPTS_CLR_RSVD_SHIFT               (16U)
#define DCP_CH0OPTS_CLR_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_CLR_RSVD_SHIFT)) & DCP_CH0OPTS_CLR_RSVD_MASK)
/*! @} */

/*! @name CH0OPTS_TOG - DCP channel 0 options register */
/*! @{ */

#define DCP_CH0OPTS_TOG_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH0OPTS_TOG_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH0OPTS_TOG_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_TOG_RECOVERY_TIMER_SHIFT)) & DCP_CH0OPTS_TOG_RECOVERY_TIMER_MASK)

#define DCP_CH0OPTS_TOG_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH0OPTS_TOG_RSVD_SHIFT               (16U)
#define DCP_CH0OPTS_TOG_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH0OPTS_TOG_RSVD_SHIFT)) & DCP_CH0OPTS_TOG_RSVD_MASK)
/*! @} */

/*! @name CH1CMDPTR - DCP channel 1 command pointer address register */
/*! @{ */

#define DCP_CH1CMDPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define DCP_CH1CMDPTR_ADDR_SHIFT                 (0U)
#define DCP_CH1CMDPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_CH1CMDPTR_ADDR_SHIFT)) & DCP_CH1CMDPTR_ADDR_MASK)
/*! @} */

/*! @name CH1SEMA - DCP channel 1 semaphore register */
/*! @{ */

#define DCP_CH1SEMA_INCREMENT_MASK               (0xFFU)
#define DCP_CH1SEMA_INCREMENT_SHIFT              (0U)
#define DCP_CH1SEMA_INCREMENT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH1SEMA_INCREMENT_SHIFT)) & DCP_CH1SEMA_INCREMENT_MASK)

#define DCP_CH1SEMA_VALUE_MASK                   (0xFF0000U)
#define DCP_CH1SEMA_VALUE_SHIFT                  (16U)
#define DCP_CH1SEMA_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_CH1SEMA_VALUE_SHIFT)) & DCP_CH1SEMA_VALUE_MASK)
/*! @} */

/*! @name CH1STAT - DCP channel 1 status register */
/*! @{ */

#define DCP_CH1STAT_RSVD_COMPLETE_MASK           (0x1U)
#define DCP_CH1STAT_RSVD_COMPLETE_SHIFT          (0U)
#define DCP_CH1STAT_RSVD_COMPLETE(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_RSVD_COMPLETE_SHIFT)) & DCP_CH1STAT_RSVD_COMPLETE_MASK)

#define DCP_CH1STAT_HASH_MISMATCH_MASK           (0x2U)
#define DCP_CH1STAT_HASH_MISMATCH_SHIFT          (1U)
#define DCP_CH1STAT_HASH_MISMATCH(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_HASH_MISMATCH_SHIFT)) & DCP_CH1STAT_HASH_MISMATCH_MASK)

#define DCP_CH1STAT_ERROR_SETUP_MASK             (0x4U)
#define DCP_CH1STAT_ERROR_SETUP_SHIFT            (2U)
#define DCP_CH1STAT_ERROR_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_SETUP_SHIFT)) & DCP_CH1STAT_ERROR_SETUP_MASK)

#define DCP_CH1STAT_ERROR_PACKET_MASK            (0x8U)
#define DCP_CH1STAT_ERROR_PACKET_SHIFT           (3U)
#define DCP_CH1STAT_ERROR_PACKET(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_PACKET_SHIFT)) & DCP_CH1STAT_ERROR_PACKET_MASK)

#define DCP_CH1STAT_ERROR_SRC_MASK               (0x10U)
#define DCP_CH1STAT_ERROR_SRC_SHIFT              (4U)
#define DCP_CH1STAT_ERROR_SRC(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_SRC_SHIFT)) & DCP_CH1STAT_ERROR_SRC_MASK)

#define DCP_CH1STAT_ERROR_DST_MASK               (0x20U)
#define DCP_CH1STAT_ERROR_DST_SHIFT              (5U)
#define DCP_CH1STAT_ERROR_DST(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_DST_SHIFT)) & DCP_CH1STAT_ERROR_DST_MASK)

#define DCP_CH1STAT_ERROR_PAGEFAULT_MASK         (0x40U)
#define DCP_CH1STAT_ERROR_PAGEFAULT_SHIFT        (6U)
#define DCP_CH1STAT_ERROR_PAGEFAULT(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_PAGEFAULT_SHIFT)) & DCP_CH1STAT_ERROR_PAGEFAULT_MASK)

#define DCP_CH1STAT_ERROR_CODE_MASK              (0xFF0000U)
#define DCP_CH1STAT_ERROR_CODE_SHIFT             (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported when reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH1STAT_ERROR_CODE(x)                (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_ERROR_CODE_SHIFT)) & DCP_CH1STAT_ERROR_CODE_MASK)

#define DCP_CH1STAT_TAG_MASK                     (0xFF000000U)
#define DCP_CH1STAT_TAG_SHIFT                    (24U)
#define DCP_CH1STAT_TAG(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TAG_SHIFT)) & DCP_CH1STAT_TAG_MASK)
/*! @} */

/*! @name CH1STAT_SET - DCP channel 1 status register */
/*! @{ */

#define DCP_CH1STAT_SET_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH1STAT_SET_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH1STAT_SET_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_RSVD_COMPLETE_SHIFT)) & DCP_CH1STAT_SET_RSVD_COMPLETE_MASK)

#define DCP_CH1STAT_SET_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH1STAT_SET_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH1STAT_SET_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_HASH_MISMATCH_SHIFT)) & DCP_CH1STAT_SET_HASH_MISMATCH_MASK)

#define DCP_CH1STAT_SET_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH1STAT_SET_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH1STAT_SET_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_SETUP_SHIFT)) & DCP_CH1STAT_SET_ERROR_SETUP_MASK)

#define DCP_CH1STAT_SET_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH1STAT_SET_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH1STAT_SET_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_PACKET_SHIFT)) & DCP_CH1STAT_SET_ERROR_PACKET_MASK)

#define DCP_CH1STAT_SET_ERROR_SRC_MASK           (0x10U)
#define DCP_CH1STAT_SET_ERROR_SRC_SHIFT          (4U)
#define DCP_CH1STAT_SET_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_SRC_SHIFT)) & DCP_CH1STAT_SET_ERROR_SRC_MASK)

#define DCP_CH1STAT_SET_ERROR_DST_MASK           (0x20U)
#define DCP_CH1STAT_SET_ERROR_DST_SHIFT          (5U)
#define DCP_CH1STAT_SET_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_DST_SHIFT)) & DCP_CH1STAT_SET_ERROR_DST_MASK)

#define DCP_CH1STAT_SET_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH1STAT_SET_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH1STAT_SET_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_PAGEFAULT_SHIFT)) & DCP_CH1STAT_SET_ERROR_PAGEFAULT_MASK)

#define DCP_CH1STAT_SET_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH1STAT_SET_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported when reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH1STAT_SET_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_ERROR_CODE_SHIFT)) & DCP_CH1STAT_SET_ERROR_CODE_MASK)

#define DCP_CH1STAT_SET_TAG_MASK                 (0xFF000000U)
#define DCP_CH1STAT_SET_TAG_SHIFT                (24U)
#define DCP_CH1STAT_SET_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_SET_TAG_SHIFT)) & DCP_CH1STAT_SET_TAG_MASK)
/*! @} */

/*! @name CH1STAT_CLR - DCP channel 1 status register */
/*! @{ */

#define DCP_CH1STAT_CLR_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH1STAT_CLR_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH1STAT_CLR_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_RSVD_COMPLETE_SHIFT)) & DCP_CH1STAT_CLR_RSVD_COMPLETE_MASK)

#define DCP_CH1STAT_CLR_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH1STAT_CLR_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH1STAT_CLR_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_HASH_MISMATCH_SHIFT)) & DCP_CH1STAT_CLR_HASH_MISMATCH_MASK)

#define DCP_CH1STAT_CLR_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH1STAT_CLR_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH1STAT_CLR_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_SETUP_SHIFT)) & DCP_CH1STAT_CLR_ERROR_SETUP_MASK)

#define DCP_CH1STAT_CLR_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH1STAT_CLR_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH1STAT_CLR_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_PACKET_SHIFT)) & DCP_CH1STAT_CLR_ERROR_PACKET_MASK)

#define DCP_CH1STAT_CLR_ERROR_SRC_MASK           (0x10U)
#define DCP_CH1STAT_CLR_ERROR_SRC_SHIFT          (4U)
#define DCP_CH1STAT_CLR_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_SRC_SHIFT)) & DCP_CH1STAT_CLR_ERROR_SRC_MASK)

#define DCP_CH1STAT_CLR_ERROR_DST_MASK           (0x20U)
#define DCP_CH1STAT_CLR_ERROR_DST_SHIFT          (5U)
#define DCP_CH1STAT_CLR_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_DST_SHIFT)) & DCP_CH1STAT_CLR_ERROR_DST_MASK)

#define DCP_CH1STAT_CLR_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH1STAT_CLR_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH1STAT_CLR_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_PAGEFAULT_SHIFT)) & DCP_CH1STAT_CLR_ERROR_PAGEFAULT_MASK)

#define DCP_CH1STAT_CLR_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH1STAT_CLR_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported when reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH1STAT_CLR_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_ERROR_CODE_SHIFT)) & DCP_CH1STAT_CLR_ERROR_CODE_MASK)

#define DCP_CH1STAT_CLR_TAG_MASK                 (0xFF000000U)
#define DCP_CH1STAT_CLR_TAG_SHIFT                (24U)
#define DCP_CH1STAT_CLR_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_CLR_TAG_SHIFT)) & DCP_CH1STAT_CLR_TAG_MASK)
/*! @} */

/*! @name CH1STAT_TOG - DCP channel 1 status register */
/*! @{ */

#define DCP_CH1STAT_TOG_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH1STAT_TOG_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH1STAT_TOG_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_RSVD_COMPLETE_SHIFT)) & DCP_CH1STAT_TOG_RSVD_COMPLETE_MASK)

#define DCP_CH1STAT_TOG_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH1STAT_TOG_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH1STAT_TOG_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_HASH_MISMATCH_SHIFT)) & DCP_CH1STAT_TOG_HASH_MISMATCH_MASK)

#define DCP_CH1STAT_TOG_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH1STAT_TOG_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH1STAT_TOG_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_SETUP_SHIFT)) & DCP_CH1STAT_TOG_ERROR_SETUP_MASK)

#define DCP_CH1STAT_TOG_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH1STAT_TOG_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH1STAT_TOG_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_PACKET_SHIFT)) & DCP_CH1STAT_TOG_ERROR_PACKET_MASK)

#define DCP_CH1STAT_TOG_ERROR_SRC_MASK           (0x10U)
#define DCP_CH1STAT_TOG_ERROR_SRC_SHIFT          (4U)
#define DCP_CH1STAT_TOG_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_SRC_SHIFT)) & DCP_CH1STAT_TOG_ERROR_SRC_MASK)

#define DCP_CH1STAT_TOG_ERROR_DST_MASK           (0x20U)
#define DCP_CH1STAT_TOG_ERROR_DST_SHIFT          (5U)
#define DCP_CH1STAT_TOG_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_DST_SHIFT)) & DCP_CH1STAT_TOG_ERROR_DST_MASK)

#define DCP_CH1STAT_TOG_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH1STAT_TOG_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH1STAT_TOG_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_PAGEFAULT_SHIFT)) & DCP_CH1STAT_TOG_ERROR_PAGEFAULT_MASK)

#define DCP_CH1STAT_TOG_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH1STAT_TOG_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported when reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH1STAT_TOG_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_ERROR_CODE_SHIFT)) & DCP_CH1STAT_TOG_ERROR_CODE_MASK)

#define DCP_CH1STAT_TOG_TAG_MASK                 (0xFF000000U)
#define DCP_CH1STAT_TOG_TAG_SHIFT                (24U)
#define DCP_CH1STAT_TOG_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH1STAT_TOG_TAG_SHIFT)) & DCP_CH1STAT_TOG_TAG_MASK)
/*! @} */

/*! @name CH1OPTS - DCP channel 1 options register */
/*! @{ */

#define DCP_CH1OPTS_RECOVERY_TIMER_MASK          (0xFFFFU)
#define DCP_CH1OPTS_RECOVERY_TIMER_SHIFT         (0U)
#define DCP_CH1OPTS_RECOVERY_TIMER(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_RECOVERY_TIMER_SHIFT)) & DCP_CH1OPTS_RECOVERY_TIMER_MASK)

#define DCP_CH1OPTS_RSVD_MASK                    (0xFFFF0000U)
#define DCP_CH1OPTS_RSVD_SHIFT                   (16U)
#define DCP_CH1OPTS_RSVD(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_RSVD_SHIFT)) & DCP_CH1OPTS_RSVD_MASK)
/*! @} */

/*! @name CH1OPTS_SET - DCP channel 1 options register */
/*! @{ */

#define DCP_CH1OPTS_SET_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH1OPTS_SET_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH1OPTS_SET_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_SET_RECOVERY_TIMER_SHIFT)) & DCP_CH1OPTS_SET_RECOVERY_TIMER_MASK)

#define DCP_CH1OPTS_SET_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH1OPTS_SET_RSVD_SHIFT               (16U)
#define DCP_CH1OPTS_SET_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_SET_RSVD_SHIFT)) & DCP_CH1OPTS_SET_RSVD_MASK)
/*! @} */

/*! @name CH1OPTS_CLR - DCP channel 1 options register */
/*! @{ */

#define DCP_CH1OPTS_CLR_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH1OPTS_CLR_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH1OPTS_CLR_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_CLR_RECOVERY_TIMER_SHIFT)) & DCP_CH1OPTS_CLR_RECOVERY_TIMER_MASK)

#define DCP_CH1OPTS_CLR_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH1OPTS_CLR_RSVD_SHIFT               (16U)
#define DCP_CH1OPTS_CLR_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_CLR_RSVD_SHIFT)) & DCP_CH1OPTS_CLR_RSVD_MASK)
/*! @} */

/*! @name CH1OPTS_TOG - DCP channel 1 options register */
/*! @{ */

#define DCP_CH1OPTS_TOG_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH1OPTS_TOG_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH1OPTS_TOG_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_TOG_RECOVERY_TIMER_SHIFT)) & DCP_CH1OPTS_TOG_RECOVERY_TIMER_MASK)

#define DCP_CH1OPTS_TOG_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH1OPTS_TOG_RSVD_SHIFT               (16U)
#define DCP_CH1OPTS_TOG_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH1OPTS_TOG_RSVD_SHIFT)) & DCP_CH1OPTS_TOG_RSVD_MASK)
/*! @} */

/*! @name CH2CMDPTR - DCP channel 2 command pointer address register */
/*! @{ */

#define DCP_CH2CMDPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define DCP_CH2CMDPTR_ADDR_SHIFT                 (0U)
#define DCP_CH2CMDPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_CH2CMDPTR_ADDR_SHIFT)) & DCP_CH2CMDPTR_ADDR_MASK)
/*! @} */

/*! @name CH2SEMA - DCP channel 2 semaphore register */
/*! @{ */

#define DCP_CH2SEMA_INCREMENT_MASK               (0xFFU)
#define DCP_CH2SEMA_INCREMENT_SHIFT              (0U)
#define DCP_CH2SEMA_INCREMENT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH2SEMA_INCREMENT_SHIFT)) & DCP_CH2SEMA_INCREMENT_MASK)

#define DCP_CH2SEMA_VALUE_MASK                   (0xFF0000U)
#define DCP_CH2SEMA_VALUE_SHIFT                  (16U)
#define DCP_CH2SEMA_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_CH2SEMA_VALUE_SHIFT)) & DCP_CH2SEMA_VALUE_MASK)
/*! @} */

/*! @name CH2STAT - DCP channel 2 status register */
/*! @{ */

#define DCP_CH2STAT_RSVD_COMPLETE_MASK           (0x1U)
#define DCP_CH2STAT_RSVD_COMPLETE_SHIFT          (0U)
#define DCP_CH2STAT_RSVD_COMPLETE(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_RSVD_COMPLETE_SHIFT)) & DCP_CH2STAT_RSVD_COMPLETE_MASK)

#define DCP_CH2STAT_HASH_MISMATCH_MASK           (0x2U)
#define DCP_CH2STAT_HASH_MISMATCH_SHIFT          (1U)
#define DCP_CH2STAT_HASH_MISMATCH(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_HASH_MISMATCH_SHIFT)) & DCP_CH2STAT_HASH_MISMATCH_MASK)

#define DCP_CH2STAT_ERROR_SETUP_MASK             (0x4U)
#define DCP_CH2STAT_ERROR_SETUP_SHIFT            (2U)
#define DCP_CH2STAT_ERROR_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_SETUP_SHIFT)) & DCP_CH2STAT_ERROR_SETUP_MASK)

#define DCP_CH2STAT_ERROR_PACKET_MASK            (0x8U)
#define DCP_CH2STAT_ERROR_PACKET_SHIFT           (3U)
#define DCP_CH2STAT_ERROR_PACKET(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_PACKET_SHIFT)) & DCP_CH2STAT_ERROR_PACKET_MASK)

#define DCP_CH2STAT_ERROR_SRC_MASK               (0x10U)
#define DCP_CH2STAT_ERROR_SRC_SHIFT              (4U)
#define DCP_CH2STAT_ERROR_SRC(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_SRC_SHIFT)) & DCP_CH2STAT_ERROR_SRC_MASK)

#define DCP_CH2STAT_ERROR_DST_MASK               (0x20U)
#define DCP_CH2STAT_ERROR_DST_SHIFT              (5U)
#define DCP_CH2STAT_ERROR_DST(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_DST_SHIFT)) & DCP_CH2STAT_ERROR_DST_MASK)

#define DCP_CH2STAT_ERROR_PAGEFAULT_MASK         (0x40U)
#define DCP_CH2STAT_ERROR_PAGEFAULT_SHIFT        (6U)
#define DCP_CH2STAT_ERROR_PAGEFAULT(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_PAGEFAULT_SHIFT)) & DCP_CH2STAT_ERROR_PAGEFAULT_MASK)

#define DCP_CH2STAT_ERROR_CODE_MASK              (0xFF0000U)
#define DCP_CH2STAT_ERROR_CODE_SHIFT             (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
 */
#define DCP_CH2STAT_ERROR_CODE(x)                (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_ERROR_CODE_SHIFT)) & DCP_CH2STAT_ERROR_CODE_MASK)

#define DCP_CH2STAT_TAG_MASK                     (0xFF000000U)
#define DCP_CH2STAT_TAG_SHIFT                    (24U)
#define DCP_CH2STAT_TAG(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TAG_SHIFT)) & DCP_CH2STAT_TAG_MASK)
/*! @} */

/*! @name CH2STAT_SET - DCP channel 2 status register */
/*! @{ */

#define DCP_CH2STAT_SET_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH2STAT_SET_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH2STAT_SET_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_RSVD_COMPLETE_SHIFT)) & DCP_CH2STAT_SET_RSVD_COMPLETE_MASK)

#define DCP_CH2STAT_SET_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH2STAT_SET_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH2STAT_SET_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_HASH_MISMATCH_SHIFT)) & DCP_CH2STAT_SET_HASH_MISMATCH_MASK)

#define DCP_CH2STAT_SET_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH2STAT_SET_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH2STAT_SET_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_SETUP_SHIFT)) & DCP_CH2STAT_SET_ERROR_SETUP_MASK)

#define DCP_CH2STAT_SET_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH2STAT_SET_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH2STAT_SET_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_PACKET_SHIFT)) & DCP_CH2STAT_SET_ERROR_PACKET_MASK)

#define DCP_CH2STAT_SET_ERROR_SRC_MASK           (0x10U)
#define DCP_CH2STAT_SET_ERROR_SRC_SHIFT          (4U)
#define DCP_CH2STAT_SET_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_SRC_SHIFT)) & DCP_CH2STAT_SET_ERROR_SRC_MASK)

#define DCP_CH2STAT_SET_ERROR_DST_MASK           (0x20U)
#define DCP_CH2STAT_SET_ERROR_DST_SHIFT          (5U)
#define DCP_CH2STAT_SET_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_DST_SHIFT)) & DCP_CH2STAT_SET_ERROR_DST_MASK)

#define DCP_CH2STAT_SET_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH2STAT_SET_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH2STAT_SET_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_PAGEFAULT_SHIFT)) & DCP_CH2STAT_SET_ERROR_PAGEFAULT_MASK)

#define DCP_CH2STAT_SET_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH2STAT_SET_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
 */
#define DCP_CH2STAT_SET_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_ERROR_CODE_SHIFT)) & DCP_CH2STAT_SET_ERROR_CODE_MASK)

#define DCP_CH2STAT_SET_TAG_MASK                 (0xFF000000U)
#define DCP_CH2STAT_SET_TAG_SHIFT                (24U)
#define DCP_CH2STAT_SET_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_SET_TAG_SHIFT)) & DCP_CH2STAT_SET_TAG_MASK)
/*! @} */

/*! @name CH2STAT_CLR - DCP channel 2 status register */
/*! @{ */

#define DCP_CH2STAT_CLR_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH2STAT_CLR_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH2STAT_CLR_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_RSVD_COMPLETE_SHIFT)) & DCP_CH2STAT_CLR_RSVD_COMPLETE_MASK)

#define DCP_CH2STAT_CLR_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH2STAT_CLR_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH2STAT_CLR_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_HASH_MISMATCH_SHIFT)) & DCP_CH2STAT_CLR_HASH_MISMATCH_MASK)

#define DCP_CH2STAT_CLR_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH2STAT_CLR_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH2STAT_CLR_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_SETUP_SHIFT)) & DCP_CH2STAT_CLR_ERROR_SETUP_MASK)

#define DCP_CH2STAT_CLR_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH2STAT_CLR_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH2STAT_CLR_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_PACKET_SHIFT)) & DCP_CH2STAT_CLR_ERROR_PACKET_MASK)

#define DCP_CH2STAT_CLR_ERROR_SRC_MASK           (0x10U)
#define DCP_CH2STAT_CLR_ERROR_SRC_SHIFT          (4U)
#define DCP_CH2STAT_CLR_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_SRC_SHIFT)) & DCP_CH2STAT_CLR_ERROR_SRC_MASK)

#define DCP_CH2STAT_CLR_ERROR_DST_MASK           (0x20U)
#define DCP_CH2STAT_CLR_ERROR_DST_SHIFT          (5U)
#define DCP_CH2STAT_CLR_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_DST_SHIFT)) & DCP_CH2STAT_CLR_ERROR_DST_MASK)

#define DCP_CH2STAT_CLR_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH2STAT_CLR_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH2STAT_CLR_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_PAGEFAULT_SHIFT)) & DCP_CH2STAT_CLR_ERROR_PAGEFAULT_MASK)

#define DCP_CH2STAT_CLR_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH2STAT_CLR_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
 */
#define DCP_CH2STAT_CLR_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_ERROR_CODE_SHIFT)) & DCP_CH2STAT_CLR_ERROR_CODE_MASK)

#define DCP_CH2STAT_CLR_TAG_MASK                 (0xFF000000U)
#define DCP_CH2STAT_CLR_TAG_SHIFT                (24U)
#define DCP_CH2STAT_CLR_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_CLR_TAG_SHIFT)) & DCP_CH2STAT_CLR_TAG_MASK)
/*! @} */

/*! @name CH2STAT_TOG - DCP channel 2 status register */
/*! @{ */

#define DCP_CH2STAT_TOG_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH2STAT_TOG_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH2STAT_TOG_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_RSVD_COMPLETE_SHIFT)) & DCP_CH2STAT_TOG_RSVD_COMPLETE_MASK)

#define DCP_CH2STAT_TOG_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH2STAT_TOG_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH2STAT_TOG_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_HASH_MISMATCH_SHIFT)) & DCP_CH2STAT_TOG_HASH_MISMATCH_MASK)

#define DCP_CH2STAT_TOG_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH2STAT_TOG_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH2STAT_TOG_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_SETUP_SHIFT)) & DCP_CH2STAT_TOG_ERROR_SETUP_MASK)

#define DCP_CH2STAT_TOG_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH2STAT_TOG_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH2STAT_TOG_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_PACKET_SHIFT)) & DCP_CH2STAT_TOG_ERROR_PACKET_MASK)

#define DCP_CH2STAT_TOG_ERROR_SRC_MASK           (0x10U)
#define DCP_CH2STAT_TOG_ERROR_SRC_SHIFT          (4U)
#define DCP_CH2STAT_TOG_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_SRC_SHIFT)) & DCP_CH2STAT_TOG_ERROR_SRC_MASK)

#define DCP_CH2STAT_TOG_ERROR_DST_MASK           (0x20U)
#define DCP_CH2STAT_TOG_ERROR_DST_SHIFT          (5U)
#define DCP_CH2STAT_TOG_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_DST_SHIFT)) & DCP_CH2STAT_TOG_ERROR_DST_MASK)

#define DCP_CH2STAT_TOG_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH2STAT_TOG_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH2STAT_TOG_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_PAGEFAULT_SHIFT)) & DCP_CH2STAT_TOG_ERROR_PAGEFAULT_MASK)

#define DCP_CH2STAT_TOG_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH2STAT_TOG_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
 */
#define DCP_CH2STAT_TOG_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_ERROR_CODE_SHIFT)) & DCP_CH2STAT_TOG_ERROR_CODE_MASK)

#define DCP_CH2STAT_TOG_TAG_MASK                 (0xFF000000U)
#define DCP_CH2STAT_TOG_TAG_SHIFT                (24U)
#define DCP_CH2STAT_TOG_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH2STAT_TOG_TAG_SHIFT)) & DCP_CH2STAT_TOG_TAG_MASK)
/*! @} */

/*! @name CH2OPTS - DCP channel 2 options register */
/*! @{ */

#define DCP_CH2OPTS_RECOVERY_TIMER_MASK          (0xFFFFU)
#define DCP_CH2OPTS_RECOVERY_TIMER_SHIFT         (0U)
#define DCP_CH2OPTS_RECOVERY_TIMER(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_RECOVERY_TIMER_SHIFT)) & DCP_CH2OPTS_RECOVERY_TIMER_MASK)

#define DCP_CH2OPTS_RSVD_MASK                    (0xFFFF0000U)
#define DCP_CH2OPTS_RSVD_SHIFT                   (16U)
#define DCP_CH2OPTS_RSVD(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_RSVD_SHIFT)) & DCP_CH2OPTS_RSVD_MASK)
/*! @} */

/*! @name CH2OPTS_SET - DCP channel 2 options register */
/*! @{ */

#define DCP_CH2OPTS_SET_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH2OPTS_SET_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH2OPTS_SET_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_SET_RECOVERY_TIMER_SHIFT)) & DCP_CH2OPTS_SET_RECOVERY_TIMER_MASK)

#define DCP_CH2OPTS_SET_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH2OPTS_SET_RSVD_SHIFT               (16U)
#define DCP_CH2OPTS_SET_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_SET_RSVD_SHIFT)) & DCP_CH2OPTS_SET_RSVD_MASK)
/*! @} */

/*! @name CH2OPTS_CLR - DCP channel 2 options register */
/*! @{ */

#define DCP_CH2OPTS_CLR_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH2OPTS_CLR_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH2OPTS_CLR_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_CLR_RECOVERY_TIMER_SHIFT)) & DCP_CH2OPTS_CLR_RECOVERY_TIMER_MASK)

#define DCP_CH2OPTS_CLR_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH2OPTS_CLR_RSVD_SHIFT               (16U)
#define DCP_CH2OPTS_CLR_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_CLR_RSVD_SHIFT)) & DCP_CH2OPTS_CLR_RSVD_MASK)
/*! @} */

/*! @name CH2OPTS_TOG - DCP channel 2 options register */
/*! @{ */

#define DCP_CH2OPTS_TOG_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH2OPTS_TOG_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH2OPTS_TOG_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_TOG_RECOVERY_TIMER_SHIFT)) & DCP_CH2OPTS_TOG_RECOVERY_TIMER_MASK)

#define DCP_CH2OPTS_TOG_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH2OPTS_TOG_RSVD_SHIFT               (16U)
#define DCP_CH2OPTS_TOG_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH2OPTS_TOG_RSVD_SHIFT)) & DCP_CH2OPTS_TOG_RSVD_MASK)
/*! @} */

/*! @name CH3CMDPTR - DCP channel 3 command pointer address register */
/*! @{ */

#define DCP_CH3CMDPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define DCP_CH3CMDPTR_ADDR_SHIFT                 (0U)
#define DCP_CH3CMDPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_CH3CMDPTR_ADDR_SHIFT)) & DCP_CH3CMDPTR_ADDR_MASK)
/*! @} */

/*! @name CH3SEMA - DCP channel 3 semaphore register */
/*! @{ */

#define DCP_CH3SEMA_INCREMENT_MASK               (0xFFU)
#define DCP_CH3SEMA_INCREMENT_SHIFT              (0U)
#define DCP_CH3SEMA_INCREMENT(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH3SEMA_INCREMENT_SHIFT)) & DCP_CH3SEMA_INCREMENT_MASK)

#define DCP_CH3SEMA_VALUE_MASK                   (0xFF0000U)
#define DCP_CH3SEMA_VALUE_SHIFT                  (16U)
#define DCP_CH3SEMA_VALUE(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_CH3SEMA_VALUE_SHIFT)) & DCP_CH3SEMA_VALUE_MASK)
/*! @} */

/*! @name CH3STAT - DCP channel 3 status register */
/*! @{ */

#define DCP_CH3STAT_RSVD_COMPLETE_MASK           (0x1U)
#define DCP_CH3STAT_RSVD_COMPLETE_SHIFT          (0U)
#define DCP_CH3STAT_RSVD_COMPLETE(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_RSVD_COMPLETE_SHIFT)) & DCP_CH3STAT_RSVD_COMPLETE_MASK)

#define DCP_CH3STAT_HASH_MISMATCH_MASK           (0x2U)
#define DCP_CH3STAT_HASH_MISMATCH_SHIFT          (1U)
#define DCP_CH3STAT_HASH_MISMATCH(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_HASH_MISMATCH_SHIFT)) & DCP_CH3STAT_HASH_MISMATCH_MASK)

#define DCP_CH3STAT_ERROR_SETUP_MASK             (0x4U)
#define DCP_CH3STAT_ERROR_SETUP_SHIFT            (2U)
#define DCP_CH3STAT_ERROR_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_SETUP_SHIFT)) & DCP_CH3STAT_ERROR_SETUP_MASK)

#define DCP_CH3STAT_ERROR_PACKET_MASK            (0x8U)
#define DCP_CH3STAT_ERROR_PACKET_SHIFT           (3U)
#define DCP_CH3STAT_ERROR_PACKET(x)              (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_PACKET_SHIFT)) & DCP_CH3STAT_ERROR_PACKET_MASK)

#define DCP_CH3STAT_ERROR_SRC_MASK               (0x10U)
#define DCP_CH3STAT_ERROR_SRC_SHIFT              (4U)
#define DCP_CH3STAT_ERROR_SRC(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_SRC_SHIFT)) & DCP_CH3STAT_ERROR_SRC_MASK)

#define DCP_CH3STAT_ERROR_DST_MASK               (0x20U)
#define DCP_CH3STAT_ERROR_DST_SHIFT              (5U)
#define DCP_CH3STAT_ERROR_DST(x)                 (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_DST_SHIFT)) & DCP_CH3STAT_ERROR_DST_MASK)

#define DCP_CH3STAT_ERROR_PAGEFAULT_MASK         (0x40U)
#define DCP_CH3STAT_ERROR_PAGEFAULT_SHIFT        (6U)
#define DCP_CH3STAT_ERROR_PAGEFAULT(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_PAGEFAULT_SHIFT)) & DCP_CH3STAT_ERROR_PAGEFAULT_MASK)

#define DCP_CH3STAT_ERROR_CODE_MASK              (0xFF0000U)
#define DCP_CH3STAT_ERROR_CODE_SHIFT             (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH3STAT_ERROR_CODE(x)                (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_ERROR_CODE_SHIFT)) & DCP_CH3STAT_ERROR_CODE_MASK)

#define DCP_CH3STAT_TAG_MASK                     (0xFF000000U)
#define DCP_CH3STAT_TAG_SHIFT                    (24U)
#define DCP_CH3STAT_TAG(x)                       (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TAG_SHIFT)) & DCP_CH3STAT_TAG_MASK)
/*! @} */

/*! @name CH3STAT_SET - DCP channel 3 status register */
/*! @{ */

#define DCP_CH3STAT_SET_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH3STAT_SET_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH3STAT_SET_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_RSVD_COMPLETE_SHIFT)) & DCP_CH3STAT_SET_RSVD_COMPLETE_MASK)

#define DCP_CH3STAT_SET_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH3STAT_SET_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH3STAT_SET_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_HASH_MISMATCH_SHIFT)) & DCP_CH3STAT_SET_HASH_MISMATCH_MASK)

#define DCP_CH3STAT_SET_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH3STAT_SET_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH3STAT_SET_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_SETUP_SHIFT)) & DCP_CH3STAT_SET_ERROR_SETUP_MASK)

#define DCP_CH3STAT_SET_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH3STAT_SET_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH3STAT_SET_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_PACKET_SHIFT)) & DCP_CH3STAT_SET_ERROR_PACKET_MASK)

#define DCP_CH3STAT_SET_ERROR_SRC_MASK           (0x10U)
#define DCP_CH3STAT_SET_ERROR_SRC_SHIFT          (4U)
#define DCP_CH3STAT_SET_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_SRC_SHIFT)) & DCP_CH3STAT_SET_ERROR_SRC_MASK)

#define DCP_CH3STAT_SET_ERROR_DST_MASK           (0x20U)
#define DCP_CH3STAT_SET_ERROR_DST_SHIFT          (5U)
#define DCP_CH3STAT_SET_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_DST_SHIFT)) & DCP_CH3STAT_SET_ERROR_DST_MASK)

#define DCP_CH3STAT_SET_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH3STAT_SET_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH3STAT_SET_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_PAGEFAULT_SHIFT)) & DCP_CH3STAT_SET_ERROR_PAGEFAULT_MASK)

#define DCP_CH3STAT_SET_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH3STAT_SET_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH3STAT_SET_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_ERROR_CODE_SHIFT)) & DCP_CH3STAT_SET_ERROR_CODE_MASK)

#define DCP_CH3STAT_SET_TAG_MASK                 (0xFF000000U)
#define DCP_CH3STAT_SET_TAG_SHIFT                (24U)
#define DCP_CH3STAT_SET_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_SET_TAG_SHIFT)) & DCP_CH3STAT_SET_TAG_MASK)
/*! @} */

/*! @name CH3STAT_CLR - DCP channel 3 status register */
/*! @{ */

#define DCP_CH3STAT_CLR_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH3STAT_CLR_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH3STAT_CLR_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_RSVD_COMPLETE_SHIFT)) & DCP_CH3STAT_CLR_RSVD_COMPLETE_MASK)

#define DCP_CH3STAT_CLR_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH3STAT_CLR_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH3STAT_CLR_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_HASH_MISMATCH_SHIFT)) & DCP_CH3STAT_CLR_HASH_MISMATCH_MASK)

#define DCP_CH3STAT_CLR_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH3STAT_CLR_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH3STAT_CLR_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_SETUP_SHIFT)) & DCP_CH3STAT_CLR_ERROR_SETUP_MASK)

#define DCP_CH3STAT_CLR_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH3STAT_CLR_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH3STAT_CLR_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_PACKET_SHIFT)) & DCP_CH3STAT_CLR_ERROR_PACKET_MASK)

#define DCP_CH3STAT_CLR_ERROR_SRC_MASK           (0x10U)
#define DCP_CH3STAT_CLR_ERROR_SRC_SHIFT          (4U)
#define DCP_CH3STAT_CLR_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_SRC_SHIFT)) & DCP_CH3STAT_CLR_ERROR_SRC_MASK)

#define DCP_CH3STAT_CLR_ERROR_DST_MASK           (0x20U)
#define DCP_CH3STAT_CLR_ERROR_DST_SHIFT          (5U)
#define DCP_CH3STAT_CLR_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_DST_SHIFT)) & DCP_CH3STAT_CLR_ERROR_DST_MASK)

#define DCP_CH3STAT_CLR_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH3STAT_CLR_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH3STAT_CLR_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_PAGEFAULT_SHIFT)) & DCP_CH3STAT_CLR_ERROR_PAGEFAULT_MASK)

#define DCP_CH3STAT_CLR_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH3STAT_CLR_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH3STAT_CLR_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_ERROR_CODE_SHIFT)) & DCP_CH3STAT_CLR_ERROR_CODE_MASK)

#define DCP_CH3STAT_CLR_TAG_MASK                 (0xFF000000U)
#define DCP_CH3STAT_CLR_TAG_SHIFT                (24U)
#define DCP_CH3STAT_CLR_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_CLR_TAG_SHIFT)) & DCP_CH3STAT_CLR_TAG_MASK)
/*! @} */

/*! @name CH3STAT_TOG - DCP channel 3 status register */
/*! @{ */

#define DCP_CH3STAT_TOG_RSVD_COMPLETE_MASK       (0x1U)
#define DCP_CH3STAT_TOG_RSVD_COMPLETE_SHIFT      (0U)
#define DCP_CH3STAT_TOG_RSVD_COMPLETE(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_RSVD_COMPLETE_SHIFT)) & DCP_CH3STAT_TOG_RSVD_COMPLETE_MASK)

#define DCP_CH3STAT_TOG_HASH_MISMATCH_MASK       (0x2U)
#define DCP_CH3STAT_TOG_HASH_MISMATCH_SHIFT      (1U)
#define DCP_CH3STAT_TOG_HASH_MISMATCH(x)         (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_HASH_MISMATCH_SHIFT)) & DCP_CH3STAT_TOG_HASH_MISMATCH_MASK)

#define DCP_CH3STAT_TOG_ERROR_SETUP_MASK         (0x4U)
#define DCP_CH3STAT_TOG_ERROR_SETUP_SHIFT        (2U)
#define DCP_CH3STAT_TOG_ERROR_SETUP(x)           (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_SETUP_SHIFT)) & DCP_CH3STAT_TOG_ERROR_SETUP_MASK)

#define DCP_CH3STAT_TOG_ERROR_PACKET_MASK        (0x8U)
#define DCP_CH3STAT_TOG_ERROR_PACKET_SHIFT       (3U)
#define DCP_CH3STAT_TOG_ERROR_PACKET(x)          (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_PACKET_SHIFT)) & DCP_CH3STAT_TOG_ERROR_PACKET_MASK)

#define DCP_CH3STAT_TOG_ERROR_SRC_MASK           (0x10U)
#define DCP_CH3STAT_TOG_ERROR_SRC_SHIFT          (4U)
#define DCP_CH3STAT_TOG_ERROR_SRC(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_SRC_SHIFT)) & DCP_CH3STAT_TOG_ERROR_SRC_MASK)

#define DCP_CH3STAT_TOG_ERROR_DST_MASK           (0x20U)
#define DCP_CH3STAT_TOG_ERROR_DST_SHIFT          (5U)
#define DCP_CH3STAT_TOG_ERROR_DST(x)             (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_DST_SHIFT)) & DCP_CH3STAT_TOG_ERROR_DST_MASK)

#define DCP_CH3STAT_TOG_ERROR_PAGEFAULT_MASK     (0x40U)
#define DCP_CH3STAT_TOG_ERROR_PAGEFAULT_SHIFT    (6U)
#define DCP_CH3STAT_TOG_ERROR_PAGEFAULT(x)       (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_PAGEFAULT_SHIFT)) & DCP_CH3STAT_TOG_ERROR_PAGEFAULT_MASK)

#define DCP_CH3STAT_TOG_ERROR_CODE_MASK          (0xFF0000U)
#define DCP_CH3STAT_TOG_ERROR_CODE_SHIFT         (16U)
/*! ERROR_CODE
 *  0b00000001..Error is signalled because the next pointer is 0x00000000.
 *  0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
 *  0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
 *  0b00000100..Error is signalled because an error was reported while reading/writing the payload.
 *  0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
 */
#define DCP_CH3STAT_TOG_ERROR_CODE(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_ERROR_CODE_SHIFT)) & DCP_CH3STAT_TOG_ERROR_CODE_MASK)

#define DCP_CH3STAT_TOG_TAG_MASK                 (0xFF000000U)
#define DCP_CH3STAT_TOG_TAG_SHIFT                (24U)
#define DCP_CH3STAT_TOG_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_CH3STAT_TOG_TAG_SHIFT)) & DCP_CH3STAT_TOG_TAG_MASK)
/*! @} */

/*! @name CH3OPTS - DCP channel 3 options register */
/*! @{ */

#define DCP_CH3OPTS_RECOVERY_TIMER_MASK          (0xFFFFU)
#define DCP_CH3OPTS_RECOVERY_TIMER_SHIFT         (0U)
#define DCP_CH3OPTS_RECOVERY_TIMER(x)            (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_RECOVERY_TIMER_SHIFT)) & DCP_CH3OPTS_RECOVERY_TIMER_MASK)

#define DCP_CH3OPTS_RSVD_MASK                    (0xFFFF0000U)
#define DCP_CH3OPTS_RSVD_SHIFT                   (16U)
#define DCP_CH3OPTS_RSVD(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_RSVD_SHIFT)) & DCP_CH3OPTS_RSVD_MASK)
/*! @} */

/*! @name CH3OPTS_SET - DCP channel 3 options register */
/*! @{ */

#define DCP_CH3OPTS_SET_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH3OPTS_SET_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH3OPTS_SET_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_SET_RECOVERY_TIMER_SHIFT)) & DCP_CH3OPTS_SET_RECOVERY_TIMER_MASK)

#define DCP_CH3OPTS_SET_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH3OPTS_SET_RSVD_SHIFT               (16U)
#define DCP_CH3OPTS_SET_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_SET_RSVD_SHIFT)) & DCP_CH3OPTS_SET_RSVD_MASK)
/*! @} */

/*! @name CH3OPTS_CLR - DCP channel 3 options register */
/*! @{ */

#define DCP_CH3OPTS_CLR_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH3OPTS_CLR_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH3OPTS_CLR_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_CLR_RECOVERY_TIMER_SHIFT)) & DCP_CH3OPTS_CLR_RECOVERY_TIMER_MASK)

#define DCP_CH3OPTS_CLR_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH3OPTS_CLR_RSVD_SHIFT               (16U)
#define DCP_CH3OPTS_CLR_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_CLR_RSVD_SHIFT)) & DCP_CH3OPTS_CLR_RSVD_MASK)
/*! @} */

/*! @name CH3OPTS_TOG - DCP channel 3 options register */
/*! @{ */

#define DCP_CH3OPTS_TOG_RECOVERY_TIMER_MASK      (0xFFFFU)
#define DCP_CH3OPTS_TOG_RECOVERY_TIMER_SHIFT     (0U)
#define DCP_CH3OPTS_TOG_RECOVERY_TIMER(x)        (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_TOG_RECOVERY_TIMER_SHIFT)) & DCP_CH3OPTS_TOG_RECOVERY_TIMER_MASK)

#define DCP_CH3OPTS_TOG_RSVD_MASK                (0xFFFF0000U)
#define DCP_CH3OPTS_TOG_RSVD_SHIFT               (16U)
#define DCP_CH3OPTS_TOG_RSVD(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_CH3OPTS_TOG_RSVD_SHIFT)) & DCP_CH3OPTS_TOG_RSVD_MASK)
/*! @} */

/*! @name DBGSELECT - DCP debug select register */
/*! @{ */

#define DCP_DBGSELECT_INDEX_MASK                 (0xFFU)
#define DCP_DBGSELECT_INDEX_SHIFT                (0U)
/*! INDEX
 *  0b00000001..CONTROL
 *  0b00010000..OTPKEY0
 *  0b00010001..OTPKEY1
 *  0b00010010..OTPKEY2
 *  0b00010011..OTPKEY3
 */
#define DCP_DBGSELECT_INDEX(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_DBGSELECT_INDEX_SHIFT)) & DCP_DBGSELECT_INDEX_MASK)

#define DCP_DBGSELECT_RSVD_MASK                  (0xFFFFFF00U)
#define DCP_DBGSELECT_RSVD_SHIFT                 (8U)
#define DCP_DBGSELECT_RSVD(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_DBGSELECT_RSVD_SHIFT)) & DCP_DBGSELECT_RSVD_MASK)
/*! @} */

/*! @name DBGDATA - DCP debug data register */
/*! @{ */

#define DCP_DBGDATA_DATA_MASK                    (0xFFFFFFFFU)
#define DCP_DBGDATA_DATA_SHIFT                   (0U)
#define DCP_DBGDATA_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_DBGDATA_DATA_SHIFT)) & DCP_DBGDATA_DATA_MASK)
/*! @} */

/*! @name PAGETABLE - DCP page table register */
/*! @{ */

#define DCP_PAGETABLE_ENABLE_MASK                (0x1U)
#define DCP_PAGETABLE_ENABLE_SHIFT               (0U)
#define DCP_PAGETABLE_ENABLE(x)                  (((uint32_t)(((uint32_t)(x)) << DCP_PAGETABLE_ENABLE_SHIFT)) & DCP_PAGETABLE_ENABLE_MASK)

#define DCP_PAGETABLE_FLUSH_MASK                 (0x2U)
#define DCP_PAGETABLE_FLUSH_SHIFT                (1U)
#define DCP_PAGETABLE_FLUSH(x)                   (((uint32_t)(((uint32_t)(x)) << DCP_PAGETABLE_FLUSH_SHIFT)) & DCP_PAGETABLE_FLUSH_MASK)

#define DCP_PAGETABLE_BASE_MASK                  (0xFFFFFFFCU)
#define DCP_PAGETABLE_BASE_SHIFT                 (2U)
#define DCP_PAGETABLE_BASE(x)                    (((uint32_t)(((uint32_t)(x)) << DCP_PAGETABLE_BASE_SHIFT)) & DCP_PAGETABLE_BASE_MASK)
/*! @} */

/*! @name VERSION - DCP version register */
/*! @{ */

#define DCP_VERSION_STEP_MASK                    (0xFFFFU)
#define DCP_VERSION_STEP_SHIFT                   (0U)
#define DCP_VERSION_STEP(x)                      (((uint32_t)(((uint32_t)(x)) << DCP_VERSION_STEP_SHIFT)) & DCP_VERSION_STEP_MASK)

#define DCP_VERSION_MINOR_MASK                   (0xFF0000U)
#define DCP_VERSION_MINOR_SHIFT                  (16U)
#define DCP_VERSION_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_VERSION_MINOR_SHIFT)) & DCP_VERSION_MINOR_MASK)

#define DCP_VERSION_MAJOR_MASK                   (0xFF000000U)
#define DCP_VERSION_MAJOR_SHIFT                  (24U)
#define DCP_VERSION_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << DCP_VERSION_MAJOR_SHIFT)) & DCP_VERSION_MAJOR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DCP_Register_Masks */


/*!
 * @}
 */ /* end of group DCP_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_DCP_H_ */

