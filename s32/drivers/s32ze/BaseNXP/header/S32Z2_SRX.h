/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SRX.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SRX
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_SRX_H_)  /* Check if memory map has not been already included */
#define S32Z2_SRX_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SRX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRX_Peripheral_Access_Layer SRX Peripheral Access Layer
 * @{
 */

/** SRX - Size of Registers Arrays */
#define SRX_CNL_COUNT                             8

/** SRX - Register Layout Typedef */
typedef struct {
  __IO uint32_t GBL_CTRL;                          /**< Global Control Register, offset: 0x0 */
  __IO uint32_t CHNL_EN;                           /**< Channel Enable Register, offset: 0x4 */
  __IO uint32_t SLOW_MSG_UVF;                      /**< Slow Channel Status, offset: 0x8 */
  __IO uint32_t FMSG_RDY;                          /**< Fast Message Ready Status Register, offset: 0xC */
  __IO uint32_t SMSG_RDY;                          /**< Slow Serial Message Ready Status Register, offset: 0x10 */
  __IO uint32_t CHNL_FIFO_EN;                      /**< Channel FIFO Enable, offset: 0x14 */
  __IO uint32_t DATA_CTRL1;                        /**< Data Control Register 1, offset: 0x18 */
  uint8_t RESERVED_0[4];
  __IO uint32_t CHNL_OVF_UVF;                      /**< Fast Channel Status, offset: 0x20 */
  __IO uint32_t FDMA_CTRL;                         /**< Fast Message DMA Control Register, offset: 0x24 */
  __IO uint32_t SDMA_CTRL;                         /**< Slow Serial Message DMA Control Register, offset: 0x28 */
  __IO uint32_t CHNL_NB_REORD1;                    /**< Channel Nibble Reorder 1, offset: 0x2C */
  uint8_t RESERVED_1[4];
  __IO uint32_t FMSG_RDY_IE;                       /**< Fast Message Ready Interrupt Control Register, offset: 0x34 */
  __IO uint32_t SMSG_RDY_IE;                       /**< Slow Serial Message Ready Interrupt Enable Register, offset: 0x38 */
  uint8_t RESERVED_2[36];
  struct SRX_CNL {                                 /* offset: 0x60, array step: 0x44 */
    __IO uint32_t CH_CLK_CTRL;                       /**< Channel '0' Clock Control Register..Channel '7' Clock Control Register, array offset: 0x60, array step: 0x44 */
    __IO uint32_t CH_STATUS;                         /**< Channel '0' Status Register..Channel '7' Status Register, array offset: 0x64, array step: 0x44 */
    __IO uint32_t CH_CONFIG;                         /**< Channel '0' Configuration Register..Channel '7' Configuration Register, array offset: 0x68, array step: 0x44 */
    __I  uint32_t CH_FMSG_DATA;                      /**< Channel '0' Fast Message Data Read Register..Channel '7' Fast Message Data Read Register, array offset: 0x6C, array step: 0x44 */
    __I  uint32_t CH_FMSG_CRC;                       /**< Channel '0' Fast Message CRC Read Register..Channel '7' Fast Message CRC Read Register, array offset: 0x70, array step: 0x44 */
    __I  uint32_t CH_FMSG_TS;                        /**< Channel '0' Fast Message Time Stamp Read Register..Channel '7' Fast Message Time Stamp Read Register, array offset: 0x74, array step: 0x44 */
    __I  uint32_t CH_SMSG_BIT3;                      /**< Channel '0' Serial Message Read Register (Bit 3)..Channel '7' Serial Message Read Register (Bit 3), array offset: 0x78, array step: 0x44 */
    __I  uint32_t CH_SMSG_BIT2;                      /**< Channel '0' Serial Message Read Register (Bit 2)..Channel '7' Serial Message Read Register (Bit 2), array offset: 0x7C, array step: 0x44 */
    __I  uint32_t CH_SMSG_TS;                        /**< Channel '0' Serial Message Time Stamp Read..Channel '7' Serial Message Time Stamp Read, array offset: 0x80, array step: 0x44 */
    __I  uint32_t CH_F_DMA_RD;                       /**< Channel '0' DMA Fast Message Data Read..Channel '7' DMA Fast Message Data Read, array offset: 0x84, array step: 0x44 */
    __I  uint32_t CH_F_DMA_CRC;                      /**< Channel '0' DMA Fast Message CRC Read..Channel '7' DMA Fast Message CRC Read, array offset: 0x88, array step: 0x44 */
    __I  uint32_t CH_F_DMA_TS;                       /**< Channel '0' DMA Fast Message Time Stamp Read..Channel '7' DMA Fast Message Time Stamp Read, array offset: 0x8C, array step: 0x44 */
    __I  uint32_t CH_S_DMA_RD;                       /**< Channel '0' DMA Slow Serial Message Bit3 Read..Channel '7' DMA Slow Serial Message Bit3 Read, array offset: 0x90, array step: 0x44 */
    __I  uint32_t CH_S_DMA_CRC;                      /**< Channel '0' DMA Slow Serial Message Bit2 Read..Channel '7' DMA Slow Serial Message Bit2 Read, array offset: 0x94, array step: 0x44 */
    __I  uint32_t CH_S_DMA_TS;                       /**< Channel '0' DMA Slow Serial Message Time Stamp Read..Channel '7' DMA Slow Serial Message Time Stamp Read, array offset: 0x98, array step: 0x44 */
    __I  uint32_t CHNL_TIMESTAMP;                    /**< Channel '0' Time Stamp..Channel '7' Time Stamp, array offset: 0x9C, array step: 0x44 */
    __IO uint32_t CHNL_COUNTER;                      /**< Channel '0' Counter..Channel '7' Counter, array offset: 0xA0, array step: 0x44 */
  } CNL[SRX_CNL_COUNT];
} SRX_Type, *SRX_MemMapPtr;

/** Number of instances of the SRX module. */
#define SRX_INSTANCE_COUNT                       2

/* SRX - Peripheral instance base addresses */
/** Peripheral SRX_0 base address */
#define IP_SRX_0_BASE                            (0x40A50000u)
/** Peripheral SRX_0 base pointer */
#define IP_SRX_0                                 ((SRX_Type *)IP_SRX_0_BASE)
/** Peripheral SRX_1 base address */
#define IP_SRX_1_BASE                            (0x42050000u)
/** Peripheral SRX_1 base pointer */
#define IP_SRX_1                                 ((SRX_Type *)IP_SRX_1_BASE)
/** Array initializer of SRX peripheral base addresses */
#define IP_SRX_BASE_ADDRS                        { IP_SRX_0_BASE, IP_SRX_1_BASE }
/** Array initializer of SRX peripheral base pointers */
#define IP_SRX_BASE_PTRS                         { IP_SRX_0, IP_SRX_1 }

/* ----------------------------------------------------------------------------
   -- SRX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SRX_Register_Masks SRX Register Masks
 * @{
 */

/*! @name GBL_CTRL - Global Control Register */
/*! @{ */

#define SRX_GBL_CTRL_SENT_EN_MASK                (0x1U)
#define SRX_GBL_CTRL_SENT_EN_SHIFT               (0U)
#define SRX_GBL_CTRL_SENT_EN_WIDTH               (1U)
#define SRX_GBL_CTRL_SENT_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_SENT_EN_SHIFT)) & SRX_GBL_CTRL_SENT_EN_MASK)

#define SRX_GBL_CTRL_DBG_FRZ_MASK                (0x4U)
#define SRX_GBL_CTRL_DBG_FRZ_SHIFT               (2U)
#define SRX_GBL_CTRL_DBG_FRZ_WIDTH               (1U)
#define SRX_GBL_CTRL_DBG_FRZ(x)                  (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_DBG_FRZ_SHIFT)) & SRX_GBL_CTRL_DBG_FRZ_MASK)

#define SRX_GBL_CTRL_FAST_CLR_MASK               (0x10U)
#define SRX_GBL_CTRL_FAST_CLR_SHIFT              (4U)
#define SRX_GBL_CTRL_FAST_CLR_WIDTH              (1U)
#define SRX_GBL_CTRL_FAST_CLR(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_FAST_CLR_SHIFT)) & SRX_GBL_CTRL_FAST_CLR_MASK)

#define SRX_GBL_CTRL_SMDUIE_MASK                 (0x100U)
#define SRX_GBL_CTRL_SMDUIE_SHIFT                (8U)
#define SRX_GBL_CTRL_SMDUIE_WIDTH                (1U)
#define SRX_GBL_CTRL_SMDUIE(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_SMDUIE_SHIFT)) & SRX_GBL_CTRL_SMDUIE_MASK)

#define SRX_GBL_CTRL_FMDUIE_MASK                 (0x200U)
#define SRX_GBL_CTRL_FMDUIE_SHIFT                (9U)
#define SRX_GBL_CTRL_FMDUIE_WIDTH                (1U)
#define SRX_GBL_CTRL_FMDUIE(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_FMDUIE_SHIFT)) & SRX_GBL_CTRL_FMDUIE_MASK)

#define SRX_GBL_CTRL_FMFOIE_MASK                 (0x400U)
#define SRX_GBL_CTRL_FMFOIE_SHIFT                (10U)
#define SRX_GBL_CTRL_FMFOIE_WIDTH                (1U)
#define SRX_GBL_CTRL_FMFOIE(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_FMFOIE_SHIFT)) & SRX_GBL_CTRL_FMFOIE_MASK)

#define SRX_GBL_CTRL_FIFOWM_MASK                 (0x1F0000U)
#define SRX_GBL_CTRL_FIFOWM_SHIFT                (16U)
#define SRX_GBL_CTRL_FIFOWM_WIDTH                (5U)
#define SRX_GBL_CTRL_FIFOWM(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_FIFOWM_SHIFT)) & SRX_GBL_CTRL_FIFOWM_MASK)

#define SRX_GBL_CTRL_TSPRSC_MASK                 (0xFF000000U)
#define SRX_GBL_CTRL_TSPRSC_SHIFT                (24U)
#define SRX_GBL_CTRL_TSPRSC_WIDTH                (8U)
#define SRX_GBL_CTRL_TSPRSC(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_GBL_CTRL_TSPRSC_SHIFT)) & SRX_GBL_CTRL_TSPRSC_MASK)
/*! @} */

/*! @name CHNL_EN - Channel Enable Register */
/*! @{ */

#define SRX_CHNL_EN_EN_CH_MASK                   (0xFFU)
#define SRX_CHNL_EN_EN_CH_SHIFT                  (0U)
#define SRX_CHNL_EN_EN_CH_WIDTH                  (8U)
#define SRX_CHNL_EN_EN_CH(x)                     (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_EN_EN_CH_SHIFT)) & SRX_CHNL_EN_EN_CH_MASK)
/*! @} */

/*! @name SLOW_MSG_UVF - Slow Channel Status */
/*! @{ */

#define SRX_SLOW_MSG_UVF_CH0_SMDU_MASK           (0x1U)
#define SRX_SLOW_MSG_UVF_CH0_SMDU_SHIFT          (0U)
#define SRX_SLOW_MSG_UVF_CH0_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH0_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH0_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH0_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH1_SMDU_MASK           (0x2U)
#define SRX_SLOW_MSG_UVF_CH1_SMDU_SHIFT          (1U)
#define SRX_SLOW_MSG_UVF_CH1_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH1_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH1_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH1_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH2_SMDU_MASK           (0x4U)
#define SRX_SLOW_MSG_UVF_CH2_SMDU_SHIFT          (2U)
#define SRX_SLOW_MSG_UVF_CH2_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH2_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH2_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH2_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH3_SMDU_MASK           (0x8U)
#define SRX_SLOW_MSG_UVF_CH3_SMDU_SHIFT          (3U)
#define SRX_SLOW_MSG_UVF_CH3_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH3_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH3_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH3_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH4_SMDU_MASK           (0x10U)
#define SRX_SLOW_MSG_UVF_CH4_SMDU_SHIFT          (4U)
#define SRX_SLOW_MSG_UVF_CH4_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH4_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH4_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH4_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH5_SMDU_MASK           (0x20U)
#define SRX_SLOW_MSG_UVF_CH5_SMDU_SHIFT          (5U)
#define SRX_SLOW_MSG_UVF_CH5_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH5_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH5_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH5_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH6_SMDU_MASK           (0x40U)
#define SRX_SLOW_MSG_UVF_CH6_SMDU_SHIFT          (6U)
#define SRX_SLOW_MSG_UVF_CH6_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH6_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH6_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH6_SMDU_MASK)

#define SRX_SLOW_MSG_UVF_CH7_SMDU_MASK           (0x80U)
#define SRX_SLOW_MSG_UVF_CH7_SMDU_SHIFT          (7U)
#define SRX_SLOW_MSG_UVF_CH7_SMDU_WIDTH          (1U)
#define SRX_SLOW_MSG_UVF_CH7_SMDU(x)             (((uint32_t)(((uint32_t)(x)) << SRX_SLOW_MSG_UVF_CH7_SMDU_SHIFT)) & SRX_SLOW_MSG_UVF_CH7_SMDU_MASK)
/*! @} */

/*! @name FMSG_RDY - Fast Message Ready Status Register */
/*! @{ */

#define SRX_FMSG_RDY_F_RDY0_MASK                 (0x1U)
#define SRX_FMSG_RDY_F_RDY0_SHIFT                (0U)
#define SRX_FMSG_RDY_F_RDY0_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY0(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY0_SHIFT)) & SRX_FMSG_RDY_F_RDY0_MASK)

#define SRX_FMSG_RDY_F_RDY1_MASK                 (0x2U)
#define SRX_FMSG_RDY_F_RDY1_SHIFT                (1U)
#define SRX_FMSG_RDY_F_RDY1_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY1(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY1_SHIFT)) & SRX_FMSG_RDY_F_RDY1_MASK)

#define SRX_FMSG_RDY_F_RDY2_MASK                 (0x4U)
#define SRX_FMSG_RDY_F_RDY2_SHIFT                (2U)
#define SRX_FMSG_RDY_F_RDY2_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY2(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY2_SHIFT)) & SRX_FMSG_RDY_F_RDY2_MASK)

#define SRX_FMSG_RDY_F_RDY3_MASK                 (0x8U)
#define SRX_FMSG_RDY_F_RDY3_SHIFT                (3U)
#define SRX_FMSG_RDY_F_RDY3_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY3(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY3_SHIFT)) & SRX_FMSG_RDY_F_RDY3_MASK)

#define SRX_FMSG_RDY_F_RDY4_MASK                 (0x10U)
#define SRX_FMSG_RDY_F_RDY4_SHIFT                (4U)
#define SRX_FMSG_RDY_F_RDY4_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY4(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY4_SHIFT)) & SRX_FMSG_RDY_F_RDY4_MASK)

#define SRX_FMSG_RDY_F_RDY5_MASK                 (0x20U)
#define SRX_FMSG_RDY_F_RDY5_SHIFT                (5U)
#define SRX_FMSG_RDY_F_RDY5_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY5(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY5_SHIFT)) & SRX_FMSG_RDY_F_RDY5_MASK)

#define SRX_FMSG_RDY_F_RDY6_MASK                 (0x40U)
#define SRX_FMSG_RDY_F_RDY6_SHIFT                (6U)
#define SRX_FMSG_RDY_F_RDY6_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY6(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY6_SHIFT)) & SRX_FMSG_RDY_F_RDY6_MASK)

#define SRX_FMSG_RDY_F_RDY7_MASK                 (0x80U)
#define SRX_FMSG_RDY_F_RDY7_SHIFT                (7U)
#define SRX_FMSG_RDY_F_RDY7_WIDTH                (1U)
#define SRX_FMSG_RDY_F_RDY7(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_F_RDY7_SHIFT)) & SRX_FMSG_RDY_F_RDY7_MASK)
/*! @} */

/*! @name SMSG_RDY - Slow Serial Message Ready Status Register */
/*! @{ */

#define SRX_SMSG_RDY_S_RDY0_MASK                 (0x1U)
#define SRX_SMSG_RDY_S_RDY0_SHIFT                (0U)
#define SRX_SMSG_RDY_S_RDY0_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY0(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY0_SHIFT)) & SRX_SMSG_RDY_S_RDY0_MASK)

#define SRX_SMSG_RDY_S_RDY1_MASK                 (0x2U)
#define SRX_SMSG_RDY_S_RDY1_SHIFT                (1U)
#define SRX_SMSG_RDY_S_RDY1_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY1(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY1_SHIFT)) & SRX_SMSG_RDY_S_RDY1_MASK)

#define SRX_SMSG_RDY_S_RDY2_MASK                 (0x4U)
#define SRX_SMSG_RDY_S_RDY2_SHIFT                (2U)
#define SRX_SMSG_RDY_S_RDY2_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY2(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY2_SHIFT)) & SRX_SMSG_RDY_S_RDY2_MASK)

#define SRX_SMSG_RDY_S_RDY3_MASK                 (0x8U)
#define SRX_SMSG_RDY_S_RDY3_SHIFT                (3U)
#define SRX_SMSG_RDY_S_RDY3_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY3(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY3_SHIFT)) & SRX_SMSG_RDY_S_RDY3_MASK)

#define SRX_SMSG_RDY_S_RDY4_MASK                 (0x10U)
#define SRX_SMSG_RDY_S_RDY4_SHIFT                (4U)
#define SRX_SMSG_RDY_S_RDY4_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY4(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY4_SHIFT)) & SRX_SMSG_RDY_S_RDY4_MASK)

#define SRX_SMSG_RDY_S_RDY5_MASK                 (0x20U)
#define SRX_SMSG_RDY_S_RDY5_SHIFT                (5U)
#define SRX_SMSG_RDY_S_RDY5_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY5(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY5_SHIFT)) & SRX_SMSG_RDY_S_RDY5_MASK)

#define SRX_SMSG_RDY_S_RDY6_MASK                 (0x40U)
#define SRX_SMSG_RDY_S_RDY6_SHIFT                (6U)
#define SRX_SMSG_RDY_S_RDY6_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY6(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY6_SHIFT)) & SRX_SMSG_RDY_S_RDY6_MASK)

#define SRX_SMSG_RDY_S_RDY7_MASK                 (0x80U)
#define SRX_SMSG_RDY_S_RDY7_SHIFT                (7U)
#define SRX_SMSG_RDY_S_RDY7_WIDTH                (1U)
#define SRX_SMSG_RDY_S_RDY7(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_S_RDY7_SHIFT)) & SRX_SMSG_RDY_S_RDY7_MASK)
/*! @} */

/*! @name CHNL_FIFO_EN - Channel FIFO Enable */
/*! @{ */

#define SRX_CHNL_FIFO_EN_CH0FIFO_EN_MASK         (0x1U)
#define SRX_CHNL_FIFO_EN_CH0FIFO_EN_SHIFT        (0U)
#define SRX_CHNL_FIFO_EN_CH0FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH0FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH0FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH0FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH1FIFO_EN_MASK         (0x2U)
#define SRX_CHNL_FIFO_EN_CH1FIFO_EN_SHIFT        (1U)
#define SRX_CHNL_FIFO_EN_CH1FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH1FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH1FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH1FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH2FIFO_EN_MASK         (0x4U)
#define SRX_CHNL_FIFO_EN_CH2FIFO_EN_SHIFT        (2U)
#define SRX_CHNL_FIFO_EN_CH2FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH2FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH2FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH2FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH3FIFO_EN_MASK         (0x8U)
#define SRX_CHNL_FIFO_EN_CH3FIFO_EN_SHIFT        (3U)
#define SRX_CHNL_FIFO_EN_CH3FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH3FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH3FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH3FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH4FIFO_EN_MASK         (0x10U)
#define SRX_CHNL_FIFO_EN_CH4FIFO_EN_SHIFT        (4U)
#define SRX_CHNL_FIFO_EN_CH4FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH4FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH4FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH4FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH5FIFO_EN_MASK         (0x20U)
#define SRX_CHNL_FIFO_EN_CH5FIFO_EN_SHIFT        (5U)
#define SRX_CHNL_FIFO_EN_CH5FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH5FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH5FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH5FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH6FIFO_EN_MASK         (0x40U)
#define SRX_CHNL_FIFO_EN_CH6FIFO_EN_SHIFT        (6U)
#define SRX_CHNL_FIFO_EN_CH6FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH6FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH6FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH6FIFO_EN_MASK)

#define SRX_CHNL_FIFO_EN_CH7FIFO_EN_MASK         (0x80U)
#define SRX_CHNL_FIFO_EN_CH7FIFO_EN_SHIFT        (7U)
#define SRX_CHNL_FIFO_EN_CH7FIFO_EN_WIDTH        (1U)
#define SRX_CHNL_FIFO_EN_CH7FIFO_EN(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_FIFO_EN_CH7FIFO_EN_SHIFT)) & SRX_CHNL_FIFO_EN_CH7FIFO_EN_MASK)
/*! @} */

/*! @name DATA_CTRL1 - Data Control Register 1 */
/*! @{ */

#define SRX_DATA_CTRL1_NIBBCH7_MASK              (0x7U)
#define SRX_DATA_CTRL1_NIBBCH7_SHIFT             (0U)
#define SRX_DATA_CTRL1_NIBBCH7_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH7(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH7_SHIFT)) & SRX_DATA_CTRL1_NIBBCH7_MASK)

#define SRX_DATA_CTRL1_NIBBCH6_MASK              (0x70U)
#define SRX_DATA_CTRL1_NIBBCH6_SHIFT             (4U)
#define SRX_DATA_CTRL1_NIBBCH6_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH6(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH6_SHIFT)) & SRX_DATA_CTRL1_NIBBCH6_MASK)

#define SRX_DATA_CTRL1_NIBBCH5_MASK              (0x700U)
#define SRX_DATA_CTRL1_NIBBCH5_SHIFT             (8U)
#define SRX_DATA_CTRL1_NIBBCH5_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH5(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH5_SHIFT)) & SRX_DATA_CTRL1_NIBBCH5_MASK)

#define SRX_DATA_CTRL1_NIBBCH4_MASK              (0x7000U)
#define SRX_DATA_CTRL1_NIBBCH4_SHIFT             (12U)
#define SRX_DATA_CTRL1_NIBBCH4_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH4(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH4_SHIFT)) & SRX_DATA_CTRL1_NIBBCH4_MASK)

#define SRX_DATA_CTRL1_NIBBCH3_MASK              (0x70000U)
#define SRX_DATA_CTRL1_NIBBCH3_SHIFT             (16U)
#define SRX_DATA_CTRL1_NIBBCH3_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH3(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH3_SHIFT)) & SRX_DATA_CTRL1_NIBBCH3_MASK)

#define SRX_DATA_CTRL1_NIBBCH2_MASK              (0x700000U)
#define SRX_DATA_CTRL1_NIBBCH2_SHIFT             (20U)
#define SRX_DATA_CTRL1_NIBBCH2_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH2(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH2_SHIFT)) & SRX_DATA_CTRL1_NIBBCH2_MASK)

#define SRX_DATA_CTRL1_NIBBCH1_MASK              (0x7000000U)
#define SRX_DATA_CTRL1_NIBBCH1_SHIFT             (24U)
#define SRX_DATA_CTRL1_NIBBCH1_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH1(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH1_SHIFT)) & SRX_DATA_CTRL1_NIBBCH1_MASK)

#define SRX_DATA_CTRL1_NIBBCH0_MASK              (0x70000000U)
#define SRX_DATA_CTRL1_NIBBCH0_SHIFT             (28U)
#define SRX_DATA_CTRL1_NIBBCH0_WIDTH             (3U)
#define SRX_DATA_CTRL1_NIBBCH0(x)                (((uint32_t)(((uint32_t)(x)) << SRX_DATA_CTRL1_NIBBCH0_SHIFT)) & SRX_DATA_CTRL1_NIBBCH0_MASK)
/*! @} */

/*! @name CHNL_OVF_UVF - Fast Channel Status */
/*! @{ */

#define SRX_CHNL_OVF_UVF_FDMU_CH0_MASK           (0x1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH0_SHIFT          (0U)
#define SRX_CHNL_OVF_UVF_FDMU_CH0_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH0(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH0_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH0_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH1_MASK           (0x2U)
#define SRX_CHNL_OVF_UVF_FDMU_CH1_SHIFT          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH1_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH1(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH1_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH1_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH2_MASK           (0x4U)
#define SRX_CHNL_OVF_UVF_FDMU_CH2_SHIFT          (2U)
#define SRX_CHNL_OVF_UVF_FDMU_CH2_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH2(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH2_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH2_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH3_MASK           (0x8U)
#define SRX_CHNL_OVF_UVF_FDMU_CH3_SHIFT          (3U)
#define SRX_CHNL_OVF_UVF_FDMU_CH3_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH3(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH3_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH3_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH4_MASK           (0x10U)
#define SRX_CHNL_OVF_UVF_FDMU_CH4_SHIFT          (4U)
#define SRX_CHNL_OVF_UVF_FDMU_CH4_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH4(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH4_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH4_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH5_MASK           (0x20U)
#define SRX_CHNL_OVF_UVF_FDMU_CH5_SHIFT          (5U)
#define SRX_CHNL_OVF_UVF_FDMU_CH5_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH5(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH5_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH5_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH6_MASK           (0x40U)
#define SRX_CHNL_OVF_UVF_FDMU_CH6_SHIFT          (6U)
#define SRX_CHNL_OVF_UVF_FDMU_CH6_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH6(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH6_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH6_MASK)

#define SRX_CHNL_OVF_UVF_FDMU_CH7_MASK           (0x80U)
#define SRX_CHNL_OVF_UVF_FDMU_CH7_SHIFT          (7U)
#define SRX_CHNL_OVF_UVF_FDMU_CH7_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FDMU_CH7(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FDMU_CH7_SHIFT)) & SRX_CHNL_OVF_UVF_FDMU_CH7_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH0_MASK           (0x10000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH0_SHIFT          (16U)
#define SRX_CHNL_OVF_UVF_FMFO_CH0_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH0(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH0_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH0_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH1_MASK           (0x20000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH1_SHIFT          (17U)
#define SRX_CHNL_OVF_UVF_FMFO_CH1_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH1(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH1_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH1_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH2_MASK           (0x40000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH2_SHIFT          (18U)
#define SRX_CHNL_OVF_UVF_FMFO_CH2_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH2(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH2_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH2_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH3_MASK           (0x80000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH3_SHIFT          (19U)
#define SRX_CHNL_OVF_UVF_FMFO_CH3_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH3(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH3_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH3_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH4_MASK           (0x100000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH4_SHIFT          (20U)
#define SRX_CHNL_OVF_UVF_FMFO_CH4_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH4(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH4_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH4_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH5_MASK           (0x200000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH5_SHIFT          (21U)
#define SRX_CHNL_OVF_UVF_FMFO_CH5_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH5(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH5_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH5_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH6_MASK           (0x400000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH6_SHIFT          (22U)
#define SRX_CHNL_OVF_UVF_FMFO_CH6_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH6(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH6_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH6_MASK)

#define SRX_CHNL_OVF_UVF_FMFO_CH7_MASK           (0x800000U)
#define SRX_CHNL_OVF_UVF_FMFO_CH7_SHIFT          (23U)
#define SRX_CHNL_OVF_UVF_FMFO_CH7_WIDTH          (1U)
#define SRX_CHNL_OVF_UVF_FMFO_CH7(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_OVF_UVF_FMFO_CH7_SHIFT)) & SRX_CHNL_OVF_UVF_FMFO_CH7_MASK)
/*! @} */

/*! @name FDMA_CTRL - Fast Message DMA Control Register */
/*! @{ */

#define SRX_FDMA_CTRL_FDMA_EN_MASK               (0xFFU)
#define SRX_FDMA_CTRL_FDMA_EN_SHIFT              (0U)
#define SRX_FDMA_CTRL_FDMA_EN_WIDTH              (8U)
#define SRX_FDMA_CTRL_FDMA_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_FDMA_CTRL_FDMA_EN_SHIFT)) & SRX_FDMA_CTRL_FDMA_EN_MASK)
/*! @} */

/*! @name SDMA_CTRL - Slow Serial Message DMA Control Register */
/*! @{ */

#define SRX_SDMA_CTRL_SDMA_EN_MASK               (0xFFU)
#define SRX_SDMA_CTRL_SDMA_EN_SHIFT              (0U)
#define SRX_SDMA_CTRL_SDMA_EN_WIDTH              (8U)
#define SRX_SDMA_CTRL_SDMA_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_SDMA_CTRL_SDMA_EN_SHIFT)) & SRX_SDMA_CTRL_SDMA_EN_MASK)
/*! @} */

/*! @name CHNL_NB_REORD1 - Channel Nibble Reorder 1 */
/*! @{ */

#define SRX_CHNL_NB_REORD1_DATAORD7_MASK         (0xFU)
#define SRX_CHNL_NB_REORD1_DATAORD7_SHIFT        (0U)
#define SRX_CHNL_NB_REORD1_DATAORD7_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD7(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD7_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD7_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD6_MASK         (0xF0U)
#define SRX_CHNL_NB_REORD1_DATAORD6_SHIFT        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD6_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD6(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD6_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD6_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD5_MASK         (0xF00U)
#define SRX_CHNL_NB_REORD1_DATAORD5_SHIFT        (8U)
#define SRX_CHNL_NB_REORD1_DATAORD5_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD5(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD5_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD5_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD4_MASK         (0xF000U)
#define SRX_CHNL_NB_REORD1_DATAORD4_SHIFT        (12U)
#define SRX_CHNL_NB_REORD1_DATAORD4_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD4(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD4_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD4_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD3_MASK         (0xF0000U)
#define SRX_CHNL_NB_REORD1_DATAORD3_SHIFT        (16U)
#define SRX_CHNL_NB_REORD1_DATAORD3_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD3(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD3_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD3_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD2_MASK         (0xF00000U)
#define SRX_CHNL_NB_REORD1_DATAORD2_SHIFT        (20U)
#define SRX_CHNL_NB_REORD1_DATAORD2_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD2(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD2_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD2_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD1_MASK         (0xF000000U)
#define SRX_CHNL_NB_REORD1_DATAORD1_SHIFT        (24U)
#define SRX_CHNL_NB_REORD1_DATAORD1_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD1(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD1_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD1_MASK)

#define SRX_CHNL_NB_REORD1_DATAORD0_MASK         (0xF0000000U)
#define SRX_CHNL_NB_REORD1_DATAORD0_SHIFT        (28U)
#define SRX_CHNL_NB_REORD1_DATAORD0_WIDTH        (4U)
#define SRX_CHNL_NB_REORD1_DATAORD0(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_NB_REORD1_DATAORD0_SHIFT)) & SRX_CHNL_NB_REORD1_DATAORD0_MASK)
/*! @} */

/*! @name FMSG_RDY_IE - Fast Message Ready Interrupt Control Register */
/*! @{ */

#define SRX_FMSG_RDY_IE_FRDY_IE0_MASK            (0x1U)
#define SRX_FMSG_RDY_IE_FRDY_IE0_SHIFT           (0U)
#define SRX_FMSG_RDY_IE_FRDY_IE0_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE0(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE0_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE0_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE1_MASK            (0x2U)
#define SRX_FMSG_RDY_IE_FRDY_IE1_SHIFT           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE1_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE1(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE1_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE1_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE2_MASK            (0x4U)
#define SRX_FMSG_RDY_IE_FRDY_IE2_SHIFT           (2U)
#define SRX_FMSG_RDY_IE_FRDY_IE2_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE2(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE2_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE2_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE3_MASK            (0x8U)
#define SRX_FMSG_RDY_IE_FRDY_IE3_SHIFT           (3U)
#define SRX_FMSG_RDY_IE_FRDY_IE3_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE3(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE3_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE3_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE4_MASK            (0x10U)
#define SRX_FMSG_RDY_IE_FRDY_IE4_SHIFT           (4U)
#define SRX_FMSG_RDY_IE_FRDY_IE4_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE4(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE4_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE4_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE5_MASK            (0x20U)
#define SRX_FMSG_RDY_IE_FRDY_IE5_SHIFT           (5U)
#define SRX_FMSG_RDY_IE_FRDY_IE5_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE5(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE5_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE5_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE6_MASK            (0x40U)
#define SRX_FMSG_RDY_IE_FRDY_IE6_SHIFT           (6U)
#define SRX_FMSG_RDY_IE_FRDY_IE6_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE6(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE6_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE6_MASK)

#define SRX_FMSG_RDY_IE_FRDY_IE7_MASK            (0x80U)
#define SRX_FMSG_RDY_IE_FRDY_IE7_SHIFT           (7U)
#define SRX_FMSG_RDY_IE_FRDY_IE7_WIDTH           (1U)
#define SRX_FMSG_RDY_IE_FRDY_IE7(x)              (((uint32_t)(((uint32_t)(x)) << SRX_FMSG_RDY_IE_FRDY_IE7_SHIFT)) & SRX_FMSG_RDY_IE_FRDY_IE7_MASK)
/*! @} */

/*! @name SMSG_RDY_IE - Slow Serial Message Ready Interrupt Enable Register */
/*! @{ */

#define SRX_SMSG_RDY_IE_SRDY_IE0_MASK            (0x1U)
#define SRX_SMSG_RDY_IE_SRDY_IE0_SHIFT           (0U)
#define SRX_SMSG_RDY_IE_SRDY_IE0_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE0(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE0_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE0_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE1_MASK            (0x2U)
#define SRX_SMSG_RDY_IE_SRDY_IE1_SHIFT           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE1_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE1(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE1_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE1_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE2_MASK            (0x4U)
#define SRX_SMSG_RDY_IE_SRDY_IE2_SHIFT           (2U)
#define SRX_SMSG_RDY_IE_SRDY_IE2_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE2(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE2_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE2_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE3_MASK            (0x8U)
#define SRX_SMSG_RDY_IE_SRDY_IE3_SHIFT           (3U)
#define SRX_SMSG_RDY_IE_SRDY_IE3_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE3(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE3_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE3_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE4_MASK            (0x10U)
#define SRX_SMSG_RDY_IE_SRDY_IE4_SHIFT           (4U)
#define SRX_SMSG_RDY_IE_SRDY_IE4_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE4(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE4_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE4_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE5_MASK            (0x20U)
#define SRX_SMSG_RDY_IE_SRDY_IE5_SHIFT           (5U)
#define SRX_SMSG_RDY_IE_SRDY_IE5_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE5(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE5_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE5_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE6_MASK            (0x40U)
#define SRX_SMSG_RDY_IE_SRDY_IE6_SHIFT           (6U)
#define SRX_SMSG_RDY_IE_SRDY_IE6_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE6(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE6_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE6_MASK)

#define SRX_SMSG_RDY_IE_SRDY_IE7_MASK            (0x80U)
#define SRX_SMSG_RDY_IE_SRDY_IE7_SHIFT           (7U)
#define SRX_SMSG_RDY_IE_SRDY_IE7_WIDTH           (1U)
#define SRX_SMSG_RDY_IE_SRDY_IE7(x)              (((uint32_t)(((uint32_t)(x)) << SRX_SMSG_RDY_IE_SRDY_IE7_SHIFT)) & SRX_SMSG_RDY_IE_SRDY_IE7_MASK)
/*! @} */

/*! @name CH_CLK_CTRL - Channel '0' Clock Control Register..Channel '7' Clock Control Register */
/*! @{ */

#define SRX_CH_CLK_CTRL_PRSC_MASK                (0x3FFFU)
#define SRX_CH_CLK_CTRL_PRSC_SHIFT               (0U)
#define SRX_CH_CLK_CTRL_PRSC_WIDTH               (14U)
#define SRX_CH_CLK_CTRL_PRSC(x)                  (((uint32_t)(((uint32_t)(x)) << SRX_CH_CLK_CTRL_PRSC_SHIFT)) & SRX_CH_CLK_CTRL_PRSC_MASK)

#define SRX_CH_CLK_CTRL_COMP_EN_MASK             (0x8000U)
#define SRX_CH_CLK_CTRL_COMP_EN_SHIFT            (15U)
#define SRX_CH_CLK_CTRL_COMP_EN_WIDTH            (1U)
#define SRX_CH_CLK_CTRL_COMP_EN(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CLK_CTRL_COMP_EN_SHIFT)) & SRX_CH_CLK_CTRL_COMP_EN_MASK)

#define SRX_CH_CLK_CTRL_CM_PRSC_MASK             (0x7FFF0000U)
#define SRX_CH_CLK_CTRL_CM_PRSC_SHIFT            (16U)
#define SRX_CH_CLK_CTRL_CM_PRSC_WIDTH            (15U)
#define SRX_CH_CLK_CTRL_CM_PRSC(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CLK_CTRL_CM_PRSC_SHIFT)) & SRX_CH_CLK_CTRL_CM_PRSC_MASK)
/*! @} */

/*! @name CH_STATUS - Channel '0' Status Register..Channel '7' Status Register */
/*! @{ */

#define SRX_CH_STATUS_NUM_EDGES_ERR_MASK         (0x10000U)
#define SRX_CH_STATUS_NUM_EDGES_ERR_SHIFT        (16U)
#define SRX_CH_STATUS_NUM_EDGES_ERR_WIDTH        (1U)
#define SRX_CH_STATUS_NUM_EDGES_ERR(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_NUM_EDGES_ERR_SHIFT)) & SRX_CH_STATUS_NUM_EDGES_ERR_MASK)

#define SRX_CH_STATUS_FMSG_CRC_ERR_MASK          (0x20000U)
#define SRX_CH_STATUS_FMSG_CRC_ERR_SHIFT         (17U)
#define SRX_CH_STATUS_FMSG_CRC_ERR_WIDTH         (1U)
#define SRX_CH_STATUS_FMSG_CRC_ERR(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_FMSG_CRC_ERR_SHIFT)) & SRX_CH_STATUS_FMSG_CRC_ERR_MASK)

#define SRX_CH_STATUS_SMSG_CRC_ERR_MASK          (0x40000U)
#define SRX_CH_STATUS_SMSG_CRC_ERR_SHIFT         (18U)
#define SRX_CH_STATUS_SMSG_CRC_ERR_WIDTH         (1U)
#define SRX_CH_STATUS_SMSG_CRC_ERR(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_SMSG_CRC_ERR_SHIFT)) & SRX_CH_STATUS_SMSG_CRC_ERR_MASK)

#define SRX_CH_STATUS_NIB_VAL_ERR_HIGH_MASK      (0x80000U)
#define SRX_CH_STATUS_NIB_VAL_ERR_HIGH_SHIFT     (19U)
#define SRX_CH_STATUS_NIB_VAL_ERR_HIGH_WIDTH     (1U)
#define SRX_CH_STATUS_NIB_VAL_ERR_HIGH(x)        (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_NIB_VAL_ERR_HIGH_SHIFT)) & SRX_CH_STATUS_NIB_VAL_ERR_HIGH_MASK)

#define SRX_CH_STATUS_CAL_DIAG_ERR_MASK          (0x100000U)
#define SRX_CH_STATUS_CAL_DIAG_ERR_SHIFT         (20U)
#define SRX_CH_STATUS_CAL_DIAG_ERR_WIDTH         (1U)
#define SRX_CH_STATUS_CAL_DIAG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_CAL_DIAG_ERR_SHIFT)) & SRX_CH_STATUS_CAL_DIAG_ERR_MASK)

#define SRX_CH_STATUS_CAL_LEN_ERR_MASK           (0x200000U)
#define SRX_CH_STATUS_CAL_LEN_ERR_SHIFT          (21U)
#define SRX_CH_STATUS_CAL_LEN_ERR_WIDTH          (1U)
#define SRX_CH_STATUS_CAL_LEN_ERR(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_CAL_LEN_ERR_SHIFT)) & SRX_CH_STATUS_CAL_LEN_ERR_MASK)

#define SRX_CH_STATUS_PP_DIAG_ERR_MASK           (0x400000U)
#define SRX_CH_STATUS_PP_DIAG_ERR_SHIFT          (22U)
#define SRX_CH_STATUS_PP_DIAG_ERR_WIDTH          (1U)
#define SRX_CH_STATUS_PP_DIAG_ERR(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_PP_DIAG_ERR_SHIFT)) & SRX_CH_STATUS_PP_DIAG_ERR_MASK)

#define SRX_CH_STATUS_NIB_VAL_ERR_LOW_MASK       (0x800000U)
#define SRX_CH_STATUS_NIB_VAL_ERR_LOW_SHIFT      (23U)
#define SRX_CH_STATUS_NIB_VAL_ERR_LOW_WIDTH      (1U)
#define SRX_CH_STATUS_NIB_VAL_ERR_LOW(x)         (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_NIB_VAL_ERR_LOW_SHIFT)) & SRX_CH_STATUS_NIB_VAL_ERR_LOW_MASK)

#define SRX_CH_STATUS_FMSG_OFLW_MASK             (0x1000000U)
#define SRX_CH_STATUS_FMSG_OFLW_SHIFT            (24U)
#define SRX_CH_STATUS_FMSG_OFLW_WIDTH            (1U)
#define SRX_CH_STATUS_FMSG_OFLW(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_FMSG_OFLW_SHIFT)) & SRX_CH_STATUS_FMSG_OFLW_MASK)

#define SRX_CH_STATUS_SMSG_OFLW_MASK             (0x2000000U)
#define SRX_CH_STATUS_SMSG_OFLW_SHIFT            (25U)
#define SRX_CH_STATUS_SMSG_OFLW_WIDTH            (1U)
#define SRX_CH_STATUS_SMSG_OFLW(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_SMSG_OFLW_SHIFT)) & SRX_CH_STATUS_SMSG_OFLW_MASK)

#define SRX_CH_STATUS_CAL_20_25_MASK             (0x4000000U)
#define SRX_CH_STATUS_CAL_20_25_SHIFT            (26U)
#define SRX_CH_STATUS_CAL_20_25_WIDTH            (1U)
#define SRX_CH_STATUS_CAL_20_25(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_CAL_20_25_SHIFT)) & SRX_CH_STATUS_CAL_20_25_MASK)

#define SRX_CH_STATUS_CAL_RESYNC_MASK            (0x8000000U)
#define SRX_CH_STATUS_CAL_RESYNC_SHIFT           (27U)
#define SRX_CH_STATUS_CAL_RESYNC_WIDTH           (1U)
#define SRX_CH_STATUS_CAL_RESYNC(x)              (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_CAL_RESYNC_SHIFT)) & SRX_CH_STATUS_CAL_RESYNC_MASK)

#define SRX_CH_STATUS_BUS_IDLE_MASK              (0x80000000U)
#define SRX_CH_STATUS_BUS_IDLE_SHIFT             (31U)
#define SRX_CH_STATUS_BUS_IDLE_WIDTH             (1U)
#define SRX_CH_STATUS_BUS_IDLE(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_STATUS_BUS_IDLE_SHIFT)) & SRX_CH_STATUS_BUS_IDLE_MASK)
/*! @} */

/*! @name CH_CONFIG - Channel '0' Configuration Register..Channel '7' Configuration Register */
/*! @{ */

#define SRX_CH_CONFIG_FIL_CNT_MASK               (0xFFU)
#define SRX_CH_CONFIG_FIL_CNT_SHIFT              (0U)
#define SRX_CH_CONFIG_FIL_CNT_WIDTH              (8U)
#define SRX_CH_CONFIG_FIL_CNT(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_FIL_CNT_SHIFT)) & SRX_CH_CONFIG_FIL_CNT_MASK)

#define SRX_CH_CONFIG_SUCC_CAL_CHK_MASK          (0x100U)
#define SRX_CH_CONFIG_SUCC_CAL_CHK_SHIFT         (8U)
#define SRX_CH_CONFIG_SUCC_CAL_CHK_WIDTH         (1U)
#define SRX_CH_CONFIG_SUCC_CAL_CHK(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_SUCC_CAL_CHK_SHIFT)) & SRX_CH_CONFIG_SUCC_CAL_CHK_MASK)

#define SRX_CH_CONFIG_PAUSE_EN_MASK              (0x200U)
#define SRX_CH_CONFIG_PAUSE_EN_SHIFT             (9U)
#define SRX_CH_CONFIG_PAUSE_EN_WIDTH             (1U)
#define SRX_CH_CONFIG_PAUSE_EN(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_PAUSE_EN_SHIFT)) & SRX_CH_CONFIG_PAUSE_EN_MASK)

#define SRX_CH_CONFIG_SCRC_TYPE_MASK             (0x400U)
#define SRX_CH_CONFIG_SCRC_TYPE_SHIFT            (10U)
#define SRX_CH_CONFIG_SCRC_TYPE_WIDTH            (1U)
#define SRX_CH_CONFIG_SCRC_TYPE(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_SCRC_TYPE_SHIFT)) & SRX_CH_CONFIG_SCRC_TYPE_MASK)

#define SRX_CH_CONFIG_FCRC_SC_EN_MASK            (0x800U)
#define SRX_CH_CONFIG_FCRC_SC_EN_SHIFT           (11U)
#define SRX_CH_CONFIG_FCRC_SC_EN_WIDTH           (1U)
#define SRX_CH_CONFIG_FCRC_SC_EN(x)              (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_FCRC_SC_EN_SHIFT)) & SRX_CH_CONFIG_FCRC_SC_EN_MASK)

#define SRX_CH_CONFIG_FCRC_TYPE_MASK             (0x1000U)
#define SRX_CH_CONFIG_FCRC_TYPE_SHIFT            (12U)
#define SRX_CH_CONFIG_FCRC_TYPE_WIDTH            (1U)
#define SRX_CH_CONFIG_FCRC_TYPE(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_FCRC_TYPE_SHIFT)) & SRX_CH_CONFIG_FCRC_TYPE_MASK)

#define SRX_CH_CONFIG_PP_CHKSEL_MASK             (0x2000U)
#define SRX_CH_CONFIG_PP_CHKSEL_SHIFT            (13U)
#define SRX_CH_CONFIG_PP_CHKSEL_WIDTH            (1U)
#define SRX_CH_CONFIG_PP_CHKSEL(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_PP_CHKSEL_SHIFT)) & SRX_CH_CONFIG_PP_CHKSEL_MASK)

#define SRX_CH_CONFIG_CAL_RNG_MASK               (0x4000U)
#define SRX_CH_CONFIG_CAL_RNG_SHIFT              (14U)
#define SRX_CH_CONFIG_CAL_RNG_WIDTH              (1U)
#define SRX_CH_CONFIG_CAL_RNG(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_CAL_RNG_SHIFT)) & SRX_CH_CONFIG_CAL_RNG_MASK)

#define SRX_CH_CONFIG_DCHNG_INT_MASK             (0x8000U)
#define SRX_CH_CONFIG_DCHNG_INT_SHIFT            (15U)
#define SRX_CH_CONFIG_DCHNG_INT_WIDTH            (1U)
#define SRX_CH_CONFIG_DCHNG_INT(x)               (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_DCHNG_INT_SHIFT)) & SRX_CH_CONFIG_DCHNG_INT_MASK)

#define SRX_CH_CONFIG_IE_NUM_EDGES_ERR_MASK      (0x10000U)
#define SRX_CH_CONFIG_IE_NUM_EDGES_ERR_SHIFT     (16U)
#define SRX_CH_CONFIG_IE_NUM_EDGES_ERR_WIDTH     (1U)
#define SRX_CH_CONFIG_IE_NUM_EDGES_ERR(x)        (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_NUM_EDGES_ERR_SHIFT)) & SRX_CH_CONFIG_IE_NUM_EDGES_ERR_MASK)

#define SRX_CH_CONFIG_IE_FMSG_CRC_ERR_MASK       (0x20000U)
#define SRX_CH_CONFIG_IE_FMSG_CRC_ERR_SHIFT      (17U)
#define SRX_CH_CONFIG_IE_FMSG_CRC_ERR_WIDTH      (1U)
#define SRX_CH_CONFIG_IE_FMSG_CRC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_FMSG_CRC_ERR_SHIFT)) & SRX_CH_CONFIG_IE_FMSG_CRC_ERR_MASK)

#define SRX_CH_CONFIG_IE_SMSG_CRC_ERR_MASK       (0x40000U)
#define SRX_CH_CONFIG_IE_SMSG_CRC_ERR_SHIFT      (18U)
#define SRX_CH_CONFIG_IE_SMSG_CRC_ERR_WIDTH      (1U)
#define SRX_CH_CONFIG_IE_SMSG_CRC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_SMSG_CRC_ERR_SHIFT)) & SRX_CH_CONFIG_IE_SMSG_CRC_ERR_MASK)

#define SRX_CH_CONFIG_IE_NIB_VAL_ERR_MASK        (0x80000U)
#define SRX_CH_CONFIG_IE_NIB_VAL_ERR_SHIFT       (19U)
#define SRX_CH_CONFIG_IE_NIB_VAL_ERR_WIDTH       (1U)
#define SRX_CH_CONFIG_IE_NIB_VAL_ERR(x)          (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_NIB_VAL_ERR_SHIFT)) & SRX_CH_CONFIG_IE_NIB_VAL_ERR_MASK)

#define SRX_CH_CONFIG_IE_CAL_DIAG_ERR_MASK       (0x100000U)
#define SRX_CH_CONFIG_IE_CAL_DIAG_ERR_SHIFT      (20U)
#define SRX_CH_CONFIG_IE_CAL_DIAG_ERR_WIDTH      (1U)
#define SRX_CH_CONFIG_IE_CAL_DIAG_ERR(x)         (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_CAL_DIAG_ERR_SHIFT)) & SRX_CH_CONFIG_IE_CAL_DIAG_ERR_MASK)

#define SRX_CH_CONFIG_IE_CAL_LEN_ERR_MASK        (0x200000U)
#define SRX_CH_CONFIG_IE_CAL_LEN_ERR_SHIFT       (21U)
#define SRX_CH_CONFIG_IE_CAL_LEN_ERR_WIDTH       (1U)
#define SRX_CH_CONFIG_IE_CAL_LEN_ERR(x)          (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_CAL_LEN_ERR_SHIFT)) & SRX_CH_CONFIG_IE_CAL_LEN_ERR_MASK)

#define SRX_CH_CONFIG_IE_PP_DIAG_ERR_MASK        (0x400000U)
#define SRX_CH_CONFIG_IE_PP_DIAG_ERR_SHIFT       (22U)
#define SRX_CH_CONFIG_IE_PP_DIAG_ERR_WIDTH       (1U)
#define SRX_CH_CONFIG_IE_PP_DIAG_ERR(x)          (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_PP_DIAG_ERR_SHIFT)) & SRX_CH_CONFIG_IE_PP_DIAG_ERR_MASK)

#define SRX_CH_CONFIG_FCRC_CHK_OFF_MASK          (0x800000U)
#define SRX_CH_CONFIG_FCRC_CHK_OFF_SHIFT         (23U)
#define SRX_CH_CONFIG_FCRC_CHK_OFF_WIDTH         (1U)
#define SRX_CH_CONFIG_FCRC_CHK_OFF(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_FCRC_CHK_OFF_SHIFT)) & SRX_CH_CONFIG_FCRC_CHK_OFF_MASK)

#define SRX_CH_CONFIG_IE_FMSG_OFLW_MASK          (0x1000000U)
#define SRX_CH_CONFIG_IE_FMSG_OFLW_SHIFT         (24U)
#define SRX_CH_CONFIG_IE_FMSG_OFLW_WIDTH         (1U)
#define SRX_CH_CONFIG_IE_FMSG_OFLW(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_FMSG_OFLW_SHIFT)) & SRX_CH_CONFIG_IE_FMSG_OFLW_MASK)

#define SRX_CH_CONFIG_IE_SMSG_OFLW_MASK          (0x2000000U)
#define SRX_CH_CONFIG_IE_SMSG_OFLW_SHIFT         (25U)
#define SRX_CH_CONFIG_IE_SMSG_OFLW_WIDTH         (1U)
#define SRX_CH_CONFIG_IE_SMSG_OFLW(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_SMSG_OFLW_SHIFT)) & SRX_CH_CONFIG_IE_SMSG_OFLW_MASK)

#define SRX_CH_CONFIG_IE_CAL_20_25_MASK          (0x4000000U)
#define SRX_CH_CONFIG_IE_CAL_20_25_SHIFT         (26U)
#define SRX_CH_CONFIG_IE_CAL_20_25_WIDTH         (1U)
#define SRX_CH_CONFIG_IE_CAL_20_25(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_CAL_20_25_SHIFT)) & SRX_CH_CONFIG_IE_CAL_20_25_MASK)

#define SRX_CH_CONFIG_IE_CAL_RESYNC_MASK         (0x8000000U)
#define SRX_CH_CONFIG_IE_CAL_RESYNC_SHIFT        (27U)
#define SRX_CH_CONFIG_IE_CAL_RESYNC_WIDTH        (1U)
#define SRX_CH_CONFIG_IE_CAL_RESYNC(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_IE_CAL_RESYNC_SHIFT)) & SRX_CH_CONFIG_IE_CAL_RESYNC_MASK)

#define SRX_CH_CONFIG_BUS_IDLE_CNT_MASK          (0xF0000000U)
#define SRX_CH_CONFIG_BUS_IDLE_CNT_SHIFT         (28U)
#define SRX_CH_CONFIG_BUS_IDLE_CNT_WIDTH         (4U)
#define SRX_CH_CONFIG_BUS_IDLE_CNT(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CH_CONFIG_BUS_IDLE_CNT_SHIFT)) & SRX_CH_CONFIG_BUS_IDLE_CNT_MASK)
/*! @} */

/*! @name CH_FMSG_DATA - Channel '0' Fast Message Data Read Register..Channel '7' Fast Message Data Read Register */
/*! @{ */

#define SRX_CH_FMSG_DATA_DNIB8_MASK              (0xFU)
#define SRX_CH_FMSG_DATA_DNIB8_SHIFT             (0U)
#define SRX_CH_FMSG_DATA_DNIB8_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB8(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB8_SHIFT)) & SRX_CH_FMSG_DATA_DNIB8_MASK)

#define SRX_CH_FMSG_DATA_DNIB7_MASK              (0xF0U)
#define SRX_CH_FMSG_DATA_DNIB7_SHIFT             (4U)
#define SRX_CH_FMSG_DATA_DNIB7_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB7(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB7_SHIFT)) & SRX_CH_FMSG_DATA_DNIB7_MASK)

#define SRX_CH_FMSG_DATA_DNIB6_MASK              (0xF00U)
#define SRX_CH_FMSG_DATA_DNIB6_SHIFT             (8U)
#define SRX_CH_FMSG_DATA_DNIB6_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB6(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB6_SHIFT)) & SRX_CH_FMSG_DATA_DNIB6_MASK)

#define SRX_CH_FMSG_DATA_DNIB5_MASK              (0xF000U)
#define SRX_CH_FMSG_DATA_DNIB5_SHIFT             (12U)
#define SRX_CH_FMSG_DATA_DNIB5_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB5(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB5_SHIFT)) & SRX_CH_FMSG_DATA_DNIB5_MASK)

#define SRX_CH_FMSG_DATA_DNIB4_MASK              (0xF0000U)
#define SRX_CH_FMSG_DATA_DNIB4_SHIFT             (16U)
#define SRX_CH_FMSG_DATA_DNIB4_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB4(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB4_SHIFT)) & SRX_CH_FMSG_DATA_DNIB4_MASK)

#define SRX_CH_FMSG_DATA_DNIB3_MASK              (0xF00000U)
#define SRX_CH_FMSG_DATA_DNIB3_SHIFT             (20U)
#define SRX_CH_FMSG_DATA_DNIB3_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB3(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB3_SHIFT)) & SRX_CH_FMSG_DATA_DNIB3_MASK)

#define SRX_CH_FMSG_DATA_DNIB2_MASK              (0xF000000U)
#define SRX_CH_FMSG_DATA_DNIB2_SHIFT             (24U)
#define SRX_CH_FMSG_DATA_DNIB2_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB2(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB2_SHIFT)) & SRX_CH_FMSG_DATA_DNIB2_MASK)

#define SRX_CH_FMSG_DATA_DNIB1_MASK              (0xF0000000U)
#define SRX_CH_FMSG_DATA_DNIB1_SHIFT             (28U)
#define SRX_CH_FMSG_DATA_DNIB1_WIDTH             (4U)
#define SRX_CH_FMSG_DATA_DNIB1(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_DATA_DNIB1_SHIFT)) & SRX_CH_FMSG_DATA_DNIB1_MASK)
/*! @} */

/*! @name CH_FMSG_CRC - Channel '0' Fast Message CRC Read Register..Channel '7' Fast Message CRC Read Register */
/*! @{ */

#define SRX_CH_FMSG_CRC_SCNIB_MASK               (0xFU)
#define SRX_CH_FMSG_CRC_SCNIB_SHIFT              (0U)
#define SRX_CH_FMSG_CRC_SCNIB_WIDTH              (4U)
#define SRX_CH_FMSG_CRC_SCNIB(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_CRC_SCNIB_SHIFT)) & SRX_CH_FMSG_CRC_SCNIB_MASK)

#define SRX_CH_FMSG_CRC_CHNUM_MASK               (0xF0U)
#define SRX_CH_FMSG_CRC_CHNUM_SHIFT              (4U)
#define SRX_CH_FMSG_CRC_CHNUM_WIDTH              (4U)
#define SRX_CH_FMSG_CRC_CHNUM(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_CRC_CHNUM_SHIFT)) & SRX_CH_FMSG_CRC_CHNUM_MASK)

#define SRX_CH_FMSG_CRC_CRC4b_MASK               (0xF0000U)
#define SRX_CH_FMSG_CRC_CRC4b_SHIFT              (16U)
#define SRX_CH_FMSG_CRC_CRC4b_WIDTH              (4U)
#define SRX_CH_FMSG_CRC_CRC4b(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_CRC_CRC4b_SHIFT)) & SRX_CH_FMSG_CRC_CRC4b_MASK)
/*! @} */

/*! @name CH_FMSG_TS - Channel '0' Fast Message Time Stamp Read Register..Channel '7' Fast Message Time Stamp Read Register */
/*! @{ */

#define SRX_CH_FMSG_TS_TS_MASK                   (0xFFFFFFFFU)
#define SRX_CH_FMSG_TS_TS_SHIFT                  (0U)
#define SRX_CH_FMSG_TS_TS_WIDTH                  (32U)
#define SRX_CH_FMSG_TS_TS(x)                     (((uint32_t)(((uint32_t)(x)) << SRX_CH_FMSG_TS_TS_SHIFT)) & SRX_CH_FMSG_TS_TS_MASK)
/*! @} */

/*! @name CH_SMSG_BIT3 - Channel '0' Serial Message Read Register (Bit 3)..Channel '7' Serial Message Read Register (Bit 3) */
/*! @{ */

#define SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK    (0x1EU)
#define SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT   (1U)
#define SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_WIDTH   (4U)
#define SRX_CH_SMSG_BIT3_ID3_0_DATA15_12(x)      (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_SHIFT)) & SRX_CH_SMSG_BIT3_ID3_0_DATA15_12_MASK)

#define SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK        (0x3C0U)
#define SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT       (6U)
#define SRX_CH_SMSG_BIT3_ID7_4_ID3_0_WIDTH       (4U)
#define SRX_CH_SMSG_BIT3_ID7_4_ID3_0(x)          (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT3_ID7_4_ID3_0_SHIFT)) & SRX_CH_SMSG_BIT3_ID7_4_ID3_0_MASK)

#define SRX_CH_SMSG_BIT3_CFG_MASK                (0x400U)
#define SRX_CH_SMSG_BIT3_CFG_SHIFT               (10U)
#define SRX_CH_SMSG_BIT3_CFG_WIDTH               (1U)
#define SRX_CH_SMSG_BIT3_CFG(x)                  (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT3_CFG_SHIFT)) & SRX_CH_SMSG_BIT3_CFG_MASK)

#define SRX_CH_SMSG_BIT3_TYPE_MASK               (0x8000000U)
#define SRX_CH_SMSG_BIT3_TYPE_SHIFT              (27U)
#define SRX_CH_SMSG_BIT3_TYPE_WIDTH              (1U)
#define SRX_CH_SMSG_BIT3_TYPE(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT3_TYPE_SHIFT)) & SRX_CH_SMSG_BIT3_TYPE_MASK)

#define SRX_CH_SMSG_BIT3_CHNUM_MASK              (0xF0000000U)
#define SRX_CH_SMSG_BIT3_CHNUM_SHIFT             (28U)
#define SRX_CH_SMSG_BIT3_CHNUM_WIDTH             (4U)
#define SRX_CH_SMSG_BIT3_CHNUM(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT3_CHNUM_SHIFT)) & SRX_CH_SMSG_BIT3_CHNUM_MASK)
/*! @} */

/*! @name CH_SMSG_BIT2 - Channel '0' Serial Message Read Register (Bit 2)..Channel '7' Serial Message Read Register (Bit 2) */
/*! @{ */

#define SRX_CH_SMSG_BIT2_DATA_MASK               (0xFFFU)
#define SRX_CH_SMSG_BIT2_DATA_SHIFT              (0U)
#define SRX_CH_SMSG_BIT2_DATA_WIDTH              (12U)
#define SRX_CH_SMSG_BIT2_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT2_DATA_SHIFT)) & SRX_CH_SMSG_BIT2_DATA_MASK)

#define SRX_CH_SMSG_BIT2_SMCRC_MASK              (0x3F0000U)
#define SRX_CH_SMSG_BIT2_SMCRC_SHIFT             (16U)
#define SRX_CH_SMSG_BIT2_SMCRC_WIDTH             (6U)
#define SRX_CH_SMSG_BIT2_SMCRC(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_BIT2_SMCRC_SHIFT)) & SRX_CH_SMSG_BIT2_SMCRC_MASK)
/*! @} */

/*! @name CH_SMSG_TS - Channel '0' Serial Message Time Stamp Read..Channel '7' Serial Message Time Stamp Read */
/*! @{ */

#define SRX_CH_SMSG_TS_TS_MASK                   (0xFFFFFFFFU)
#define SRX_CH_SMSG_TS_TS_SHIFT                  (0U)
#define SRX_CH_SMSG_TS_TS_WIDTH                  (32U)
#define SRX_CH_SMSG_TS_TS(x)                     (((uint32_t)(((uint32_t)(x)) << SRX_CH_SMSG_TS_TS_SHIFT)) & SRX_CH_SMSG_TS_TS_MASK)
/*! @} */

/*! @name CH_F_DMA_RD - Channel '0' DMA Fast Message Data Read..Channel '7' DMA Fast Message Data Read */
/*! @{ */

#define SRX_CH_F_DMA_RD_DNIB8_MASK               (0xFU)
#define SRX_CH_F_DMA_RD_DNIB8_SHIFT              (0U)
#define SRX_CH_F_DMA_RD_DNIB8_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB8(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB8_SHIFT)) & SRX_CH_F_DMA_RD_DNIB8_MASK)

#define SRX_CH_F_DMA_RD_DNIB7_MASK               (0xF0U)
#define SRX_CH_F_DMA_RD_DNIB7_SHIFT              (4U)
#define SRX_CH_F_DMA_RD_DNIB7_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB7(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB7_SHIFT)) & SRX_CH_F_DMA_RD_DNIB7_MASK)

#define SRX_CH_F_DMA_RD_DNIB6_MASK               (0xF00U)
#define SRX_CH_F_DMA_RD_DNIB6_SHIFT              (8U)
#define SRX_CH_F_DMA_RD_DNIB6_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB6(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB6_SHIFT)) & SRX_CH_F_DMA_RD_DNIB6_MASK)

#define SRX_CH_F_DMA_RD_DNIB5_MASK               (0xF000U)
#define SRX_CH_F_DMA_RD_DNIB5_SHIFT              (12U)
#define SRX_CH_F_DMA_RD_DNIB5_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB5(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB5_SHIFT)) & SRX_CH_F_DMA_RD_DNIB5_MASK)

#define SRX_CH_F_DMA_RD_DNIB4_MASK               (0xF0000U)
#define SRX_CH_F_DMA_RD_DNIB4_SHIFT              (16U)
#define SRX_CH_F_DMA_RD_DNIB4_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB4(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB4_SHIFT)) & SRX_CH_F_DMA_RD_DNIB4_MASK)

#define SRX_CH_F_DMA_RD_DNIB3_MASK               (0xF00000U)
#define SRX_CH_F_DMA_RD_DNIB3_SHIFT              (20U)
#define SRX_CH_F_DMA_RD_DNIB3_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB3(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB3_SHIFT)) & SRX_CH_F_DMA_RD_DNIB3_MASK)

#define SRX_CH_F_DMA_RD_DNIB2_MASK               (0xF000000U)
#define SRX_CH_F_DMA_RD_DNIB2_SHIFT              (24U)
#define SRX_CH_F_DMA_RD_DNIB2_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB2(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB2_SHIFT)) & SRX_CH_F_DMA_RD_DNIB2_MASK)

#define SRX_CH_F_DMA_RD_DNIB1_MASK               (0xF0000000U)
#define SRX_CH_F_DMA_RD_DNIB1_SHIFT              (28U)
#define SRX_CH_F_DMA_RD_DNIB1_WIDTH              (4U)
#define SRX_CH_F_DMA_RD_DNIB1(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_RD_DNIB1_SHIFT)) & SRX_CH_F_DMA_RD_DNIB1_MASK)
/*! @} */

/*! @name CH_F_DMA_CRC - Channel '0' DMA Fast Message CRC Read..Channel '7' DMA Fast Message CRC Read */
/*! @{ */

#define SRX_CH_F_DMA_CRC_SCNIB_MASK              (0xFU)
#define SRX_CH_F_DMA_CRC_SCNIB_SHIFT             (0U)
#define SRX_CH_F_DMA_CRC_SCNIB_WIDTH             (4U)
#define SRX_CH_F_DMA_CRC_SCNIB(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_CRC_SCNIB_SHIFT)) & SRX_CH_F_DMA_CRC_SCNIB_MASK)

#define SRX_CH_F_DMA_CRC_CHNUM_MASK              (0xF0U)
#define SRX_CH_F_DMA_CRC_CHNUM_SHIFT             (4U)
#define SRX_CH_F_DMA_CRC_CHNUM_WIDTH             (4U)
#define SRX_CH_F_DMA_CRC_CHNUM(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_CRC_CHNUM_SHIFT)) & SRX_CH_F_DMA_CRC_CHNUM_MASK)

#define SRX_CH_F_DMA_CRC_CRC4b_MASK              (0xF0000U)
#define SRX_CH_F_DMA_CRC_CRC4b_SHIFT             (16U)
#define SRX_CH_F_DMA_CRC_CRC4b_WIDTH             (4U)
#define SRX_CH_F_DMA_CRC_CRC4b(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_CRC_CRC4b_SHIFT)) & SRX_CH_F_DMA_CRC_CRC4b_MASK)
/*! @} */

/*! @name CH_F_DMA_TS - Channel '0' DMA Fast Message Time Stamp Read..Channel '7' DMA Fast Message Time Stamp Read */
/*! @{ */

#define SRX_CH_F_DMA_TS_TS_MASK                  (0xFFFFFFFFU)
#define SRX_CH_F_DMA_TS_TS_SHIFT                 (0U)
#define SRX_CH_F_DMA_TS_TS_WIDTH                 (32U)
#define SRX_CH_F_DMA_TS_TS(x)                    (((uint32_t)(((uint32_t)(x)) << SRX_CH_F_DMA_TS_TS_SHIFT)) & SRX_CH_F_DMA_TS_TS_MASK)
/*! @} */

/*! @name CH_S_DMA_RD - Channel '0' DMA Slow Serial Message Bit3 Read..Channel '7' DMA Slow Serial Message Bit3 Read */
/*! @{ */

#define SRX_CH_S_DMA_RD_ID3_0_DATA15_12_MASK     (0x1EU)
#define SRX_CH_S_DMA_RD_ID3_0_DATA15_12_SHIFT    (1U)
#define SRX_CH_S_DMA_RD_ID3_0_DATA15_12_WIDTH    (4U)
#define SRX_CH_S_DMA_RD_ID3_0_DATA15_12(x)       (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_RD_ID3_0_DATA15_12_SHIFT)) & SRX_CH_S_DMA_RD_ID3_0_DATA15_12_MASK)

#define SRX_CH_S_DMA_RD_ID7_4_ID3_0_MASK         (0x3C0U)
#define SRX_CH_S_DMA_RD_ID7_4_ID3_0_SHIFT        (6U)
#define SRX_CH_S_DMA_RD_ID7_4_ID3_0_WIDTH        (4U)
#define SRX_CH_S_DMA_RD_ID7_4_ID3_0(x)           (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_RD_ID7_4_ID3_0_SHIFT)) & SRX_CH_S_DMA_RD_ID7_4_ID3_0_MASK)

#define SRX_CH_S_DMA_RD_CFG_MASK                 (0x400U)
#define SRX_CH_S_DMA_RD_CFG_SHIFT                (10U)
#define SRX_CH_S_DMA_RD_CFG_WIDTH                (1U)
#define SRX_CH_S_DMA_RD_CFG(x)                   (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_RD_CFG_SHIFT)) & SRX_CH_S_DMA_RD_CFG_MASK)

#define SRX_CH_S_DMA_RD_TYPE_MASK                (0x8000000U)
#define SRX_CH_S_DMA_RD_TYPE_SHIFT               (27U)
#define SRX_CH_S_DMA_RD_TYPE_WIDTH               (1U)
#define SRX_CH_S_DMA_RD_TYPE(x)                  (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_RD_TYPE_SHIFT)) & SRX_CH_S_DMA_RD_TYPE_MASK)

#define SRX_CH_S_DMA_RD_CHNUM_MASK               (0xF0000000U)
#define SRX_CH_S_DMA_RD_CHNUM_SHIFT              (28U)
#define SRX_CH_S_DMA_RD_CHNUM_WIDTH              (4U)
#define SRX_CH_S_DMA_RD_CHNUM(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_RD_CHNUM_SHIFT)) & SRX_CH_S_DMA_RD_CHNUM_MASK)
/*! @} */

/*! @name CH_S_DMA_CRC - Channel '0' DMA Slow Serial Message Bit2 Read..Channel '7' DMA Slow Serial Message Bit2 Read */
/*! @{ */

#define SRX_CH_S_DMA_CRC_DATA_MASK               (0xFFFU)
#define SRX_CH_S_DMA_CRC_DATA_SHIFT              (0U)
#define SRX_CH_S_DMA_CRC_DATA_WIDTH              (12U)
#define SRX_CH_S_DMA_CRC_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_CRC_DATA_SHIFT)) & SRX_CH_S_DMA_CRC_DATA_MASK)

#define SRX_CH_S_DMA_CRC_SMCRC_MASK              (0x3F0000U)
#define SRX_CH_S_DMA_CRC_SMCRC_SHIFT             (16U)
#define SRX_CH_S_DMA_CRC_SMCRC_WIDTH             (6U)
#define SRX_CH_S_DMA_CRC_SMCRC(x)                (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_CRC_SMCRC_SHIFT)) & SRX_CH_S_DMA_CRC_SMCRC_MASK)
/*! @} */

/*! @name CH_S_DMA_TS - Channel '0' DMA Slow Serial Message Time Stamp Read..Channel '7' DMA Slow Serial Message Time Stamp Read */
/*! @{ */

#define SRX_CH_S_DMA_TS_TS_MASK                  (0xFFFFFFFFU)
#define SRX_CH_S_DMA_TS_TS_SHIFT                 (0U)
#define SRX_CH_S_DMA_TS_TS_WIDTH                 (32U)
#define SRX_CH_S_DMA_TS_TS(x)                    (((uint32_t)(((uint32_t)(x)) << SRX_CH_S_DMA_TS_TS_SHIFT)) & SRX_CH_S_DMA_TS_TS_MASK)
/*! @} */

/*! @name CHNL_TIMESTAMP - Channel '0' Time Stamp..Channel '7' Time Stamp */
/*! @{ */

#define SRX_CHNL_TIMESTAMP_CHn_TS_MASK           (0xFFFFFFFFU)
#define SRX_CHNL_TIMESTAMP_CHn_TS_SHIFT          (0U)
#define SRX_CHNL_TIMESTAMP_CHn_TS_WIDTH          (32U)
#define SRX_CHNL_TIMESTAMP_CHn_TS(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_TIMESTAMP_CHn_TS_SHIFT)) & SRX_CHNL_TIMESTAMP_CHn_TS_MASK)
/*! @} */

/*! @name CHNL_COUNTER - Channel '0' Counter..Channel '7' Counter */
/*! @{ */

#define SRX_CHNL_COUNTER_EDGE_CNT_MASK           (0xFFU)
#define SRX_CHNL_COUNTER_EDGE_CNT_SHIFT          (0U)
#define SRX_CHNL_COUNTER_EDGE_CNT_WIDTH          (8U)
#define SRX_CHNL_COUNTER_EDGE_CNT(x)             (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_COUNTER_EDGE_CNT_SHIFT)) & SRX_CHNL_COUNTER_EDGE_CNT_MASK)

#define SRX_CHNL_COUNTER_CLR_EDGE_CNT_MASK       (0x8000U)
#define SRX_CHNL_COUNTER_CLR_EDGE_CNT_SHIFT      (15U)
#define SRX_CHNL_COUNTER_CLR_EDGE_CNT_WIDTH      (1U)
#define SRX_CHNL_COUNTER_CLR_EDGE_CNT(x)         (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_COUNTER_CLR_EDGE_CNT_SHIFT)) & SRX_CHNL_COUNTER_CLR_EDGE_CNT_MASK)

#define SRX_CHNL_COUNTER_FRAME_CNT_MASK          (0xFF0000U)
#define SRX_CHNL_COUNTER_FRAME_CNT_SHIFT         (16U)
#define SRX_CHNL_COUNTER_FRAME_CNT_WIDTH         (8U)
#define SRX_CHNL_COUNTER_FRAME_CNT(x)            (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_COUNTER_FRAME_CNT_SHIFT)) & SRX_CHNL_COUNTER_FRAME_CNT_MASK)

#define SRX_CHNL_COUNTER_CLR_FRAME_CNT_MASK      (0x80000000U)
#define SRX_CHNL_COUNTER_CLR_FRAME_CNT_SHIFT     (31U)
#define SRX_CHNL_COUNTER_CLR_FRAME_CNT_WIDTH     (1U)
#define SRX_CHNL_COUNTER_CLR_FRAME_CNT(x)        (((uint32_t)(((uint32_t)(x)) << SRX_CHNL_COUNTER_CLR_FRAME_CNT_SHIFT)) & SRX_CHNL_COUNTER_CLR_FRAME_CNT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SRX_Register_Masks */

/*!
 * @}
 */ /* end of group SRX_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SRX_H_) */
