/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for S50
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_S50.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for S50
 *
 * CMSIS Peripheral Access Layer for S50
 */

#if !defined(PERI_S50_H_)
#define PERI_S50_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- S50 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S50_Peripheral_Access_Layer S50 Peripheral Access Layer
 * @{
 */

/** S50 - Register Layout Typedef */
typedef struct {
  __I  uint32_t ELS_STATUS;                        /**< Status register, offset: 0x0 */
  __IO uint32_t ELS_CTRL;                          /**< ELS Control register, offset: 0x4 */
  __IO uint32_t ELS_CMDCFG0;                       /**< ELS command configuration register, offset: 0x8 */
  __IO uint32_t ELS_CFG;                           /**< ELS configuration register, offset: 0xC */
  __IO uint32_t ELS_KIDX0;                         /**< Keystore index 0 - for commands that access a single key, offset: 0x10 */
  __IO uint32_t ELS_KIDX1;                         /**< Keystore index 1 - for commands that access 2 keys, offset: 0x14 */
  __IO uint32_t ELS_KPROPIN;                       /**< key properties request, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ELS_DMA_SRC0;                      /**< ELS DMA Source 0, offset: 0x20 */
  __IO uint32_t ELS_DMA_SRC0_LEN;                  /**< ELS DMA Source 0 length, offset: 0x24 */
  __IO uint32_t ELS_DMA_SRC1;                      /**< ELS DMA Source 1, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ELS_DMA_SRC2;                      /**< ELS DMA Source 2, offset: 0x30 */
  __IO uint32_t ELS_DMA_SRC2_LEN;                  /**< ELS DMA Source 2 length, offset: 0x34 */
  __IO uint32_t ELS_DMA_RES0;                      /**< ELS DMA Result 0, offset: 0x38 */
  __IO uint32_t ELS_DMA_RES0_LEN;                  /**< ELS DMA Result 0 Size, offset: 0x3C */
  __IO uint32_t ELS_INT_ENABLE;                    /**< Interrupt enable, offset: 0x40 */
  __O  uint32_t ELS_INT_STATUS_CLR;                /**< Interrupt status clear, offset: 0x44 */
  __O  uint32_t ELS_INT_STATUS_SET;                /**< Interrupt status set, offset: 0x48 */
  __I  uint32_t ELS_ERR_STATUS;                    /**< Status register, offset: 0x4C */
  __O  uint32_t ELS_ERR_STATUS_CLR;                /**< Interrupt status clear, offset: 0x50 */
  __I  uint32_t ELS_VERSION;                       /**< ELS Version, offset: 0x54 */
       uint8_t RESERVED_2[4];
  __I  uint32_t ELS_PRNG_DATOUT;                   /**< PRNG SW read out register, offset: 0x5C */
  __I  uint32_t ELS_GDET_EVTCNT;                   /**< ELS GDET Event Counter, offset: 0x60 */
  __O  uint32_t ELS_GDET_EVTCNT_CLR;               /**< ELS GDET Event Counter Clear, offset: 0x64 */
       uint8_t RESERVED_3[152];
  __I  uint32_t ELS_SHA2_STATUS;                   /**< ELS SHA2 Status Register, offset: 0x100 */
  __IO uint32_t ELS_SHA2_CTRL;                     /**< SHA2 Control register, offset: 0x104 */
  __IO uint32_t ELS_SHA2_DIN;                      /**< ELS SHA_DATA IN Register 0, offset: 0x108 */
  __I  uint32_t ELS_SHA2_DOUT0;                    /**< ELS ELS_SHA_DATA Out Register 0, offset: 0x10C */
  __I  uint32_t ELS_SHA2_DOUT1;                    /**< ELS SHA_DATA Out Register 1, offset: 0x110 */
  __I  uint32_t ELS_SHA2_DOUT2;                    /**< ELS SHA_DATA Out Register 2, offset: 0x114 */
  __I  uint32_t ELS_SHA2_DOUT3;                    /**< ELS SHA_DATA Out Register 3, offset: 0x118 */
  __I  uint32_t ELS_SHA2_DOUT4;                    /**< ELS SHA_DATA Out Register 4, offset: 0x11C */
  __I  uint32_t ELS_SHA2_DOUT5;                    /**< ELS SHA_DATA Out Register 5, offset: 0x120 */
  __I  uint32_t ELS_SHA2_DOUT6;                    /**< ELS SHA_DATA Out Register 6, offset: 0x124 */
  __I  uint32_t ELS_SHA2_DOUT7;                    /**< ELS SHA_DATA Out Register 7, offset: 0x128 */
  __I  uint32_t ELS_SHA2_DOUT8;                    /**< ELS ELS_SHA_DATA Out Register 8, offset: 0x12C */
  __I  uint32_t ELS_SHA2_DOUT9;                    /**< ELS SHA_DATA Out Register 9, offset: 0x130 */
  __I  uint32_t ELS_SHA2_DOUT10;                   /**< ELS SHA_DATA Out Register 10, offset: 0x134 */
  __I  uint32_t ELS_SHA2_DOUT11;                   /**< ELS SHA_DATA Out Register 11, offset: 0x138 */
  __I  uint32_t ELS_SHA2_DOUT12;                   /**< ELS SHA_DATA Out Register 12, offset: 0x13C */
  __I  uint32_t ELS_SHA2_DOUT13;                   /**< ELS SHA_DATA Out Register 13, offset: 0x140 */
  __I  uint32_t ELS_SHA2_DOUT14;                   /**< ELS SHA_DATA Out Register 14, offset: 0x144 */
  __I  uint32_t ELS_SHA2_DOUT15;                   /**< ELS SHA_DATA Out Register 15, offset: 0x148 */
       uint8_t RESERVED_4[4];
  __I  uint32_t ELS_KS0;                           /**< Status register, offset: 0x150 */
  __I  uint32_t ELS_KS1;                           /**< Status register, offset: 0x154 */
  __I  uint32_t ELS_KS2;                           /**< Status register, offset: 0x158 */
  __I  uint32_t ELS_KS3;                           /**< Status register, offset: 0x15C */
  __I  uint32_t ELS_KS4;                           /**< Status register, offset: 0x160 */
  __I  uint32_t ELS_KS5;                           /**< Status register, offset: 0x164 */
  __I  uint32_t ELS_KS6;                           /**< Status register, offset: 0x168 */
  __I  uint32_t ELS_KS7;                           /**< Status register, offset: 0x16C */
  __I  uint32_t ELS_KS8;                           /**< Status register, offset: 0x170 */
  __I  uint32_t ELS_KS9;                           /**< Status register, offset: 0x174 */
  __I  uint32_t ELS_KS10;                          /**< Status register, offset: 0x178 */
  __I  uint32_t ELS_KS11;                          /**< Status register, offset: 0x17C */
  __I  uint32_t ELS_KS12;                          /**< Status register, offset: 0x180 */
  __I  uint32_t ELS_KS13;                          /**< Status register, offset: 0x184 */
  __I  uint32_t ELS_KS14;                          /**< Status register, offset: 0x188 */
  __I  uint32_t ELS_KS15;                          /**< Status register, offset: 0x18C */
  __I  uint32_t ELS_KS16;                          /**< Status register, offset: 0x190 */
  __I  uint32_t ELS_KS17;                          /**< Status register, offset: 0x194 */
  __I  uint32_t ELS_KS18;                          /**< Status register, offset: 0x198 */
  __I  uint32_t ELS_KS19;                          /**< Status register, offset: 0x19C */
} S50_Type;

/* ----------------------------------------------------------------------------
   -- S50 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S50_Register_Masks S50 Register Masks
 * @{
 */

/*! @name ELS_STATUS - Status register */
/*! @{ */

#define S50_ELS_STATUS_ELS_BUSY_MASK             (0x1U)
#define S50_ELS_STATUS_ELS_BUSY_SHIFT            (0U)
/*! els_busy - High to indicate the ELS is executing a Crypto Sequence */
#define S50_ELS_STATUS_ELS_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_BUSY_SHIFT)) & S50_ELS_STATUS_ELS_BUSY_MASK)

#define S50_ELS_STATUS_ELS_IRQ_MASK              (0x2U)
#define S50_ELS_STATUS_ELS_IRQ_SHIFT             (1U)
/*! els_irq - High to indicate the ELS has an active interrupt */
#define S50_ELS_STATUS_ELS_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_IRQ_SHIFT)) & S50_ELS_STATUS_ELS_IRQ_MASK)

#define S50_ELS_STATUS_ELS_ERR_MASK              (0x4U)
#define S50_ELS_STATUS_ELS_ERR_SHIFT             (2U)
/*! els_err - High to indicate the ELS has detected an internal error */
#define S50_ELS_STATUS_ELS_ERR(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ELS_ERR_SHIFT)) & S50_ELS_STATUS_ELS_ERR_MASK)

#define S50_ELS_STATUS_PRNG_RDY_MASK             (0x8U)
#define S50_ELS_STATUS_PRNG_RDY_SHIFT            (3U)
/*! prng_rdy - High to indicate the internal PRNG is ready. SFR */
#define S50_ELS_STATUS_PRNG_RDY(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_PRNG_RDY_SHIFT)) & S50_ELS_STATUS_PRNG_RDY_MASK)

#define S50_ELS_STATUS_ECDSA_VFY_STATUS_MASK     (0x30U)
#define S50_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT    (4U)
/*! ecdsa_vfy_status - Signature Verify Result Status */
#define S50_ELS_STATUS_ECDSA_VFY_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT)) & S50_ELS_STATUS_ECDSA_VFY_STATUS_MASK)

#define S50_ELS_STATUS_PPROT_MASK                (0xC0U)
#define S50_ELS_STATUS_PPROT_SHIFT               (6U)
/*! pprot - Current command privilege level */
#define S50_ELS_STATUS_PPROT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_PPROT_SHIFT)) & S50_ELS_STATUS_PPROT_MASK)

#define S50_ELS_STATUS_DRBG_ENT_LVL_MASK         (0x300U)
#define S50_ELS_STATUS_DRBG_ENT_LVL_SHIFT        (8U)
/*! drbg_ent_lvl - Entropy quality of the current DRBG instance. This value */
#define S50_ELS_STATUS_DRBG_ENT_LVL(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_DRBG_ENT_LVL_SHIFT)) & S50_ELS_STATUS_DRBG_ENT_LVL_MASK)

#define S50_ELS_STATUS_DTRNG_BUSY_MASK           (0x400U)
#define S50_ELS_STATUS_DTRNG_BUSY_SHIFT          (10U)
/*! dtrng_busy - When set, it indicates the DTRNG is gathering entropy */
#define S50_ELS_STATUS_DTRNG_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_DTRNG_BUSY_SHIFT)) & S50_ELS_STATUS_DTRNG_BUSY_MASK)

#define S50_ELS_STATUS_GDET_IRQ_POS_MASK         (0x800U)
#define S50_ELS_STATUS_GDET_IRQ_POS_SHIFT        (11U)
/*! gdet_irq_pos - IRQ for GDET has detected a negative glitch: active high irq */
#define S50_ELS_STATUS_GDET_IRQ_POS(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_GDET_IRQ_POS_SHIFT)) & S50_ELS_STATUS_GDET_IRQ_POS_MASK)

#define S50_ELS_STATUS_GDET_IRQ_NEG_MASK         (0x1000U)
#define S50_ELS_STATUS_GDET_IRQ_NEG_SHIFT        (12U)
/*! gdet_irq_neg - IRQ for GDET has detected a positive glitch: active high irq */
#define S50_ELS_STATUS_GDET_IRQ_NEG(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_GDET_IRQ_NEG_SHIFT)) & S50_ELS_STATUS_GDET_IRQ_NEG_MASK)

#define S50_ELS_STATUS_STATUS_RSVD_MASK          (0xFFFFE000U)
#define S50_ELS_STATUS_STATUS_RSVD_SHIFT         (13U)
/*! status_rsvd - reserved */
#define S50_ELS_STATUS_STATUS_RSVD(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_STATUS_STATUS_RSVD_SHIFT)) & S50_ELS_STATUS_STATUS_RSVD_MASK)
/*! @} */

/*! @name ELS_CTRL - ELS Control register */
/*! @{ */

#define S50_ELS_CTRL_ELS_EN_MASK                 (0x1U)
#define S50_ELS_CTRL_ELS_EN_SHIFT                (0U)
/*! els_en - ELS enable 0=ELS disabled, 1= ELS is enabled */
#define S50_ELS_CTRL_ELS_EN(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_EN_SHIFT)) & S50_ELS_CTRL_ELS_EN_MASK)

#define S50_ELS_CTRL_ELS_START_MASK              (0x2U)
#define S50_ELS_CTRL_ELS_START_SHIFT             (1U)
/*! els_start - Write to 1 to start a ELS Operation */
#define S50_ELS_CTRL_ELS_START(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_START_SHIFT)) & S50_ELS_CTRL_ELS_START_MASK)

#define S50_ELS_CTRL_ELS_RESET_MASK              (0x4U)
#define S50_ELS_CTRL_ELS_RESET_SHIFT             (2U)
/*! els_reset - Write to 1 to perform a ELS synchronous Reset */
#define S50_ELS_CTRL_ELS_RESET(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_RESET_SHIFT)) & S50_ELS_CTRL_ELS_RESET_MASK)

#define S50_ELS_CTRL_ELS_CMD_MASK                (0xF8U)
#define S50_ELS_CTRL_ELS_CMD_SHIFT               (3U)
/*! els_cmd - ELS Command Field: List of Valid commands: */
#define S50_ELS_CTRL_ELS_CMD(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_ELS_CMD_SHIFT)) & S50_ELS_CTRL_ELS_CMD_MASK)

#define S50_ELS_CTRL_BYTE_ORDER_MASK             (0x100U)
#define S50_ELS_CTRL_BYTE_ORDER_SHIFT            (8U)
/*! byte_order - Defines Endianness - 1: BigEndian, 0: Little Endian */
#define S50_ELS_CTRL_BYTE_ORDER(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_BYTE_ORDER_SHIFT)) & S50_ELS_CTRL_BYTE_ORDER_MASK)

#define S50_ELS_CTRL_CTRL_RFU_MASK               (0xFFFFFE00U)
#define S50_ELS_CTRL_CTRL_RFU_SHIFT              (9U)
/*! ctrl_rfu - reserved */
#define S50_ELS_CTRL_CTRL_RFU(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_CTRL_CTRL_RFU_SHIFT)) & S50_ELS_CTRL_CTRL_RFU_MASK)
/*! @} */

/*! @name ELS_CMDCFG0 - ELS command configuration register */
/*! @{ */

#define S50_ELS_CMDCFG0_CMDCFG0_MASK             (0xFFFFFFFFU)
#define S50_ELS_CMDCFG0_CMDCFG0_SHIFT            (0U)
/*! cmdcfg0 - refer to reference manual for assignment of this field */
#define S50_ELS_CMDCFG0_CMDCFG0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_CMDCFG0_CMDCFG0_SHIFT)) & S50_ELS_CMDCFG0_CMDCFG0_MASK)
/*! @} */

/*! @name ELS_CFG - ELS configuration register */
/*! @{ */

#define S50_ELS_CFG_CFG_RSVD0_MASK               (0xFFFFU)
#define S50_ELS_CFG_CFG_RSVD0_SHIFT              (0U)
/*! cfg_rsvd0 - reserved */
#define S50_ELS_CFG_CFG_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_CFG_CFG_RSVD0_SHIFT)) & S50_ELS_CFG_CFG_RSVD0_MASK)

#define S50_ELS_CFG_ADCTRL_MASK                  (0x3FF0000U)
#define S50_ELS_CFG_ADCTRL_SHIFT                 (16U)
/*! adctrl - maximum aes start delay */
#define S50_ELS_CFG_ADCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_CFG_ADCTRL_SHIFT)) & S50_ELS_CFG_ADCTRL_MASK)

#define S50_ELS_CFG_CFG_RSVD1_MASK               (0x7C000000U)
#define S50_ELS_CFG_CFG_RSVD1_SHIFT              (26U)
/*! cfg_rsvd1 - reserved */
#define S50_ELS_CFG_CFG_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_CFG_CFG_RSVD1_SHIFT)) & S50_ELS_CFG_CFG_RSVD1_MASK)

#define S50_ELS_CFG_SHA2_DIRECT_MASK             (0x80000000U)
#define S50_ELS_CFG_SHA2_DIRECT_SHIFT            (31U)
/*! sha2_direct - 1=enable sha2 direct mode: direct access from external */
#define S50_ELS_CFG_SHA2_DIRECT(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_CFG_SHA2_DIRECT_SHIFT)) & S50_ELS_CFG_SHA2_DIRECT_MASK)
/*! @} */

/*! @name ELS_KIDX0 - Keystore index 0 - for commands that access a single key */
/*! @{ */

#define S50_ELS_KIDX0_KIDX0_MASK                 (0x7FU)
#define S50_ELS_KIDX0_KIDX0_SHIFT                (0U)
/*! kidx0 - keystore is indexed as an array of 128 bit key slots */
#define S50_ELS_KIDX0_KIDX0(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX0_KIDX0_SHIFT)) & S50_ELS_KIDX0_KIDX0_MASK)

#define S50_ELS_KIDX0_KIDX0_RSVD_MASK            (0xFFFFFF80U)
#define S50_ELS_KIDX0_KIDX0_RSVD_SHIFT           (7U)
/*! kidx0_rsvd - reserved */
#define S50_ELS_KIDX0_KIDX0_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX0_KIDX0_RSVD_SHIFT)) & S50_ELS_KIDX0_KIDX0_RSVD_MASK)
/*! @} */

/*! @name ELS_KIDX1 - Keystore index 1 - for commands that access 2 keys */
/*! @{ */

#define S50_ELS_KIDX1_KIDX1_MASK                 (0x7FU)
#define S50_ELS_KIDX1_KIDX1_SHIFT                (0U)
/*! kidx1 - keystore is indexed as an array of 128 bit key slots */
#define S50_ELS_KIDX1_KIDX1(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX1_KIDX1_SHIFT)) & S50_ELS_KIDX1_KIDX1_MASK)

#define S50_ELS_KIDX1_KIDX1_RSVD_MASK            (0xFFFFFF80U)
#define S50_ELS_KIDX1_KIDX1_RSVD_SHIFT           (7U)
/*! kidx1_rsvd - reserved */
#define S50_ELS_KIDX1_KIDX1_RSVD(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KIDX1_KIDX1_RSVD_SHIFT)) & S50_ELS_KIDX1_KIDX1_RSVD_MASK)
/*! @} */

/*! @name ELS_KPROPIN - key properties request */
/*! @{ */

#define S50_ELS_KPROPIN_KPROPIN_MASK             (0xFFFFFFFFU)
#define S50_ELS_KPROPIN_KPROPIN_SHIFT            (0U)
/*! kpropin - for commands that create a key - requested properties */
#define S50_ELS_KPROPIN_KPROPIN(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KPROPIN_KPROPIN_SHIFT)) & S50_ELS_KPROPIN_KPROPIN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0 - ELS DMA Source 0 */
/*! @{ */

#define S50_ELS_DMA_SRC0_ADDR_SRC0_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC0_ADDR_SRC0_SHIFT         (0U)
/*! addr_src0 - defines the System address of the start of the */
#define S50_ELS_DMA_SRC0_ADDR_SRC0(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC0_ADDR_SRC0_SHIFT)) & S50_ELS_DMA_SRC0_ADDR_SRC0_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0_LEN - ELS DMA Source 0 length */
/*! @{ */

#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT (0U)
/*! size_src0_len - Size in bytes of the data to be transferred from */
#define S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT)) & S50_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC1 - ELS DMA Source 1 */
/*! @{ */

#define S50_ELS_DMA_SRC1_ADDR_SRC1_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC1_ADDR_SRC1_SHIFT         (0U)
/*! addr_src1 - defines the System address of the start of the */
#define S50_ELS_DMA_SRC1_ADDR_SRC1(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC1_ADDR_SRC1_SHIFT)) & S50_ELS_DMA_SRC1_ADDR_SRC1_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2 - ELS DMA Source 2 */
/*! @{ */

#define S50_ELS_DMA_SRC2_ADDR_SRC2_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC2_ADDR_SRC2_SHIFT         (0U)
/*! addr_src2 - defines the System address of the start of the */
#define S50_ELS_DMA_SRC2_ADDR_SRC2(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC2_ADDR_SRC2_SHIFT)) & S50_ELS_DMA_SRC2_ADDR_SRC2_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2_LEN - ELS DMA Source 2 length */
/*! @{ */

#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT (0U)
/*! size_src2_len - Size in bytes of the data to be transferred from */
#define S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT)) & S50_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_RES0 - ELS DMA Result 0 */
/*! @{ */

#define S50_ELS_DMA_RES0_ADDR_RES0_MASK          (0xFFFFFFFFU)
#define S50_ELS_DMA_RES0_ADDR_RES0_SHIFT         (0U)
/*! addr_res0 - defines the System Start address of where the result */
#define S50_ELS_DMA_RES0_ADDR_RES0(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_RES0_ADDR_RES0_SHIFT)) & S50_ELS_DMA_RES0_ADDR_RES0_MASK)
/*! @} */

/*! @name ELS_DMA_RES0_LEN - ELS DMA Result 0 Size */
/*! @{ */

#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK  (0xFFFFFFFFU)
#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT (0U)
/*! size_res0_len - Size in bytes of the data to be transferred to */
#define S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT)) & S50_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK)
/*! @} */

/*! @name ELS_INT_ENABLE - Interrupt enable */
/*! @{ */

#define S50_ELS_INT_ENABLE_INT_EN_MASK           (0x1U)
#define S50_ELS_INT_ENABLE_INT_EN_SHIFT          (0U)
/*! int_en - Interrupt enable bit */
#define S50_ELS_INT_ENABLE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_ENABLE_INT_EN_SHIFT)) & S50_ELS_INT_ENABLE_INT_EN_MASK)

#define S50_ELS_INT_ENABLE_GDET_INT_EN_MASK      (0x2U)
#define S50_ELS_INT_ENABLE_GDET_INT_EN_SHIFT     (1U)
/*! gdet_int_en - GDET Interrupt enable bit */
#define S50_ELS_INT_ENABLE_GDET_INT_EN(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_ENABLE_GDET_INT_EN_SHIFT)) & S50_ELS_INT_ENABLE_GDET_INT_EN_MASK)

#define S50_ELS_INT_ENABLE_INT_ENA_RSVD_MASK     (0xFFFFFFFCU)
#define S50_ELS_INT_ENABLE_INT_ENA_RSVD_SHIFT    (2U)
/*! int_ena_rsvd - reserved */
#define S50_ELS_INT_ENABLE_INT_ENA_RSVD(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_ENABLE_INT_ENA_RSVD_SHIFT)) & S50_ELS_INT_ENABLE_INT_ENA_RSVD_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_CLR - Interrupt status clear */
/*! @{ */

#define S50_ELS_INT_STATUS_CLR_INT_CLR_MASK      (0x1U)
#define S50_ELS_INT_STATUS_CLR_INT_CLR_SHIFT     (0U)
/*! int_clr - Interrupt status clear */
#define S50_ELS_INT_STATUS_CLR_INT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_CLR_INT_CLR_SHIFT)) & S50_ELS_INT_STATUS_CLR_INT_CLR_MASK)

#define S50_ELS_INT_STATUS_CLR_GDET_INT_CLR_MASK (0x2U)
#define S50_ELS_INT_STATUS_CLR_GDET_INT_CLR_SHIFT (1U)
/*! gdet_int_clr - GDET Interrupt status clear */
#define S50_ELS_INT_STATUS_CLR_GDET_INT_CLR(x)   (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_CLR_GDET_INT_CLR_SHIFT)) & S50_ELS_INT_STATUS_CLR_GDET_INT_CLR_MASK)

#define S50_ELS_INT_STATUS_CLR_INT_STSC_RSVD_MASK (0xFFFFFFFCU)
#define S50_ELS_INT_STATUS_CLR_INT_STSC_RSVD_SHIFT (2U)
/*! int_stsc_rsvd - reserved */
#define S50_ELS_INT_STATUS_CLR_INT_STSC_RSVD(x)  (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_CLR_INT_STSC_RSVD_SHIFT)) & S50_ELS_INT_STATUS_CLR_INT_STSC_RSVD_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_SET - Interrupt status set */
/*! @{ */

#define S50_ELS_INT_STATUS_SET_INT_SET_MASK      (0x1U)
#define S50_ELS_INT_STATUS_SET_INT_SET_SHIFT     (0U)
/*! int_set - Set interrupt by software */
#define S50_ELS_INT_STATUS_SET_INT_SET(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_SET_INT_SET_SHIFT)) & S50_ELS_INT_STATUS_SET_INT_SET_MASK)

#define S50_ELS_INT_STATUS_SET_GDET_INT_NEG_SET_MASK (0x2U)
#define S50_ELS_INT_STATUS_SET_GDET_INT_NEG_SET_SHIFT (1U)
/*! gdet_int_neg_set - Set GDET interrupt by software */
#define S50_ELS_INT_STATUS_SET_GDET_INT_NEG_SET(x) (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_SET_GDET_INT_NEG_SET_SHIFT)) & S50_ELS_INT_STATUS_SET_GDET_INT_NEG_SET_MASK)

#define S50_ELS_INT_STATUS_SET_GDET_INT_POS_SET_MASK (0x4U)
#define S50_ELS_INT_STATUS_SET_GDET_INT_POS_SET_SHIFT (2U)
/*! gdet_int_pos_set - Set GDET interrupt by software */
#define S50_ELS_INT_STATUS_SET_GDET_INT_POS_SET(x) (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_SET_GDET_INT_POS_SET_SHIFT)) & S50_ELS_INT_STATUS_SET_GDET_INT_POS_SET_MASK)

#define S50_ELS_INT_STATUS_SET_INT_STSS_RSVD_MASK (0xFFFFFFF8U)
#define S50_ELS_INT_STATUS_SET_INT_STSS_RSVD_SHIFT (3U)
/*! int_stss_rsvd - reserved */
#define S50_ELS_INT_STATUS_SET_INT_STSS_RSVD(x)  (((uint32_t)(((uint32_t)(x)) << S50_ELS_INT_STATUS_SET_INT_STSS_RSVD_SHIFT)) & S50_ELS_INT_STATUS_SET_INT_STSS_RSVD_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS - Status register */
/*! @{ */

#define S50_ELS_ERR_STATUS_BUS_ERR_MASK          (0x1U)
#define S50_ELS_ERR_STATUS_BUS_ERR_SHIFT         (0U)
/*! bus_err - Bus access error: public or private bus */
#define S50_ELS_ERR_STATUS_BUS_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_BUS_ERR_SHIFT)) & S50_ELS_ERR_STATUS_BUS_ERR_MASK)

#define S50_ELS_ERR_STATUS_OPN_ERR_MASK          (0x2U)
#define S50_ELS_ERR_STATUS_OPN_ERR_SHIFT         (1U)
/*! opn_err - Operational error: */
#define S50_ELS_ERR_STATUS_OPN_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_OPN_ERR_SHIFT)) & S50_ELS_ERR_STATUS_OPN_ERR_MASK)

#define S50_ELS_ERR_STATUS_ALG_ERR_MASK          (0x4U)
#define S50_ELS_ERR_STATUS_ALG_ERR_SHIFT         (2U)
/*! alg_err - Algorithm error: An internal algorithm has */
#define S50_ELS_ERR_STATUS_ALG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ALG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_ALG_ERR_MASK)

#define S50_ELS_ERR_STATUS_ITG_ERR_MASK          (0x8U)
#define S50_ELS_ERR_STATUS_ITG_ERR_SHIFT         (3U)
/*! itg_err - Data integrity error: */
#define S50_ELS_ERR_STATUS_ITG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ITG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_ITG_ERR_MASK)

#define S50_ELS_ERR_STATUS_FLT_ERR_MASK          (0x10U)
#define S50_ELS_ERR_STATUS_FLT_ERR_SHIFT         (4U)
/*! flt_err - Hardware fault error: Attempt to change the value */
#define S50_ELS_ERR_STATUS_FLT_ERR(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_FLT_ERR_SHIFT)) & S50_ELS_ERR_STATUS_FLT_ERR_MASK)

#define S50_ELS_ERR_STATUS_PRNG_ERR_MASK         (0x20U)
#define S50_ELS_ERR_STATUS_PRNG_ERR_SHIFT        (5U)
/*! prng_err - User Read of ELS_PRNG_DATOUT when ELS_STATUS.PRNG_RDY */
#define S50_ELS_ERR_STATUS_PRNG_ERR(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_PRNG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_PRNG_ERR_MASK)

#define S50_ELS_ERR_STATUS_ERR_LVL_MASK          (0xC0U)
#define S50_ELS_ERR_STATUS_ERR_LVL_SHIFT         (6U)
/*! err_lvl - Indicates Error Level which has been triggerer. 0, 1 ,2 */
#define S50_ELS_ERR_STATUS_ERR_LVL(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ERR_LVL_SHIFT)) & S50_ELS_ERR_STATUS_ERR_LVL_MASK)

#define S50_ELS_ERR_STATUS_DTRNG_ERR_MASK        (0x100U)
#define S50_ELS_ERR_STATUS_DTRNG_ERR_SHIFT       (8U)
/*! dtrng_err - DTRNG unable to gather entropy with the current */
#define S50_ELS_ERR_STATUS_DTRNG_ERR(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_DTRNG_ERR_SHIFT)) & S50_ELS_ERR_STATUS_DTRNG_ERR_MASK)

#define S50_ELS_ERR_STATUS_ERR_STAT_RSVD_MASK    (0xFFFFFE00U)
#define S50_ELS_ERR_STATUS_ERR_STAT_RSVD_SHIFT   (9U)
/*! err_stat_rsvd - reserved */
#define S50_ELS_ERR_STATUS_ERR_STAT_RSVD(x)      (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_ERR_STAT_RSVD_SHIFT)) & S50_ELS_ERR_STATUS_ERR_STAT_RSVD_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS_CLR - Interrupt status clear */
/*! @{ */

#define S50_ELS_ERR_STATUS_CLR_ERR_CLR_MASK      (0x1U)
#define S50_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT     (0U)
/*! err_clr - 1=clear ELS error status bits and exit ELS error state */
#define S50_ELS_ERR_STATUS_CLR_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT)) & S50_ELS_ERR_STATUS_CLR_ERR_CLR_MASK)

#define S50_ELS_ERR_STATUS_CLR_ERR_STSC_RSVD_MASK (0xFFFFFFFEU)
#define S50_ELS_ERR_STATUS_CLR_ERR_STSC_RSVD_SHIFT (1U)
/*! err_stsc_rsvd - reserved */
#define S50_ELS_ERR_STATUS_CLR_ERR_STSC_RSVD(x)  (((uint32_t)(((uint32_t)(x)) << S50_ELS_ERR_STATUS_CLR_ERR_STSC_RSVD_SHIFT)) & S50_ELS_ERR_STATUS_CLR_ERR_STSC_RSVD_MASK)
/*! @} */

/*! @name ELS_VERSION - ELS Version */
/*! @{ */

#define S50_ELS_VERSION_Z_MASK                   (0xFU)
#define S50_ELS_VERSION_Z_SHIFT                  (0U)
/*! z - extended revision version: possible values 0-9 */
#define S50_ELS_VERSION_Z(x)                     (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Z_SHIFT)) & S50_ELS_VERSION_Z_MASK)

#define S50_ELS_VERSION_Y2_MASK                  (0xF0U)
#define S50_ELS_VERSION_Y2_SHIFT                 (4U)
/*! y2 - minor release versino digit0: possible values 0-9 */
#define S50_ELS_VERSION_Y2(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Y2_SHIFT)) & S50_ELS_VERSION_Y2_MASK)

#define S50_ELS_VERSION_Y1_MASK                  (0xF00U)
#define S50_ELS_VERSION_Y1_SHIFT                 (8U)
/*! y1 - minor release version digit1: possible values 0-9 */
#define S50_ELS_VERSION_Y1(x)                    (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_Y1_SHIFT)) & S50_ELS_VERSION_Y1_MASK)

#define S50_ELS_VERSION_X_MASK                   (0xF000U)
#define S50_ELS_VERSION_X_SHIFT                  (12U)
/*! x - major release version: possible values 1-9 */
#define S50_ELS_VERSION_X(x)                     (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_X_SHIFT)) & S50_ELS_VERSION_X_MASK)

#define S50_ELS_VERSION_VERSION_RSVD_MASK        (0xFFFF0000U)
#define S50_ELS_VERSION_VERSION_RSVD_SHIFT       (16U)
/*! version_rsvd - reserved */
#define S50_ELS_VERSION_VERSION_RSVD(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_VERSION_VERSION_RSVD_SHIFT)) & S50_ELS_VERSION_VERSION_RSVD_MASK)
/*! @} */

/*! @name ELS_PRNG_DATOUT - PRNG SW read out register */
/*! @{ */

#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK     (0xFFFFFFFFU)
#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT    (0U)
/*! prng_datout - 32-bit wide pseudo-random number */
#define S50_ELS_PRNG_DATOUT_PRNG_DATOUT(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT)) & S50_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK)
/*! @} */

/*! @name ELS_GDET_EVTCNT - ELS GDET Event Counter */
/*! @{ */

#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_MASK     (0xFFU)
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_SHIFT    (0U)
/*! gdet_evtcnt - Number of glitch event recorded */
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT(x)       (((uint32_t)(((uint32_t)(x)) << S50_ELS_GDET_EVTCNT_GDET_EVTCNT_SHIFT)) & S50_ELS_GDET_EVTCNT_GDET_EVTCNT_MASK)

#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE_MASK (0x100U)
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE_SHIFT (8U)
/*! gdet_evtcnt_clr_done - The GDET event counter has been cleared */
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE(x) (((uint32_t)(((uint32_t)(x)) << S50_ELS_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE_SHIFT)) & S50_ELS_GDET_EVTCNT_GDET_EVTCNT_CLR_DONE_MASK)

#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_RSVD_MASK (0xFFFFFE00U)
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_RSVD_SHIFT (9U)
/*! gdet_evtcnt_rsvd - reserved */
#define S50_ELS_GDET_EVTCNT_GDET_EVTCNT_RSVD(x)  (((uint32_t)(((uint32_t)(x)) << S50_ELS_GDET_EVTCNT_GDET_EVTCNT_RSVD_SHIFT)) & S50_ELS_GDET_EVTCNT_GDET_EVTCNT_RSVD_MASK)
/*! @} */

/*! @name ELS_GDET_EVTCNT_CLR - ELS GDET Event Counter Clear */
/*! @{ */

#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_MASK (0x1U)
#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_SHIFT (0U)
/*! gdet_evtcnt_clr - 1=clear GDET event counter clear */
#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR(x) (((uint32_t)(((uint32_t)(x)) << S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_SHIFT)) & S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_MASK)

#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_RSVD_MASK (0xFFFFFFFEU)
#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_RSVD_SHIFT (1U)
/*! gdet_evtcnt_clr_rsvd - reserved */
#define S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_RSVD(x) (((uint32_t)(((uint32_t)(x)) << S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_RSVD_SHIFT)) & S50_ELS_GDET_EVTCNT_CLR_GDET_EVTCNT_CLR_RSVD_MASK)
/*! @} */

/*! @name ELS_SHA2_STATUS - ELS SHA2 Status Register */
/*! @{ */

#define S50_ELS_SHA2_STATUS_SHA2_BUSY_MASK       (0x1U)
#define S50_ELS_SHA2_STATUS_SHA2_BUSY_SHIFT      (0U)
/*! sha2_busy - SHA2 busy/idle status for sha direct */
#define S50_ELS_SHA2_STATUS_SHA2_BUSY(x)         (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_STATUS_SHA2_BUSY_SHIFT)) & S50_ELS_SHA2_STATUS_SHA2_BUSY_MASK)

#define S50_ELS_SHA2_STATUS_STATUS_RSVD1_MASK    (0xFFFFFFFEU)
#define S50_ELS_SHA2_STATUS_STATUS_RSVD1_SHIFT   (1U)
/*! status_rsvd1 - reserved */
#define S50_ELS_SHA2_STATUS_STATUS_RSVD1(x)      (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_STATUS_STATUS_RSVD1_SHIFT)) & S50_ELS_SHA2_STATUS_STATUS_RSVD1_MASK)
/*! @} */

/*! @name ELS_SHA2_CTRL - SHA2 Control register */
/*! @{ */

#define S50_ELS_SHA2_CTRL_SHA2_START_MASK        (0x1U)
#define S50_ELS_SHA2_CTRL_SHA2_START_SHIFT       (0U)
/*! sha2_start - Write to 1 to Init the SHA2 Module */
#define S50_ELS_SHA2_CTRL_SHA2_START(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_START_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_START_MASK)

#define S50_ELS_SHA2_CTRL_SHA2_RST_MASK          (0x2U)
#define S50_ELS_SHA2_CTRL_SHA2_RST_SHIFT         (1U)
/*! sha2_rst - Write to 1 to Reset a SHA2 operation */
#define S50_ELS_SHA2_CTRL_SHA2_RST(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_RST_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_RST_MASK)

#define S50_ELS_SHA2_CTRL_SHA2_INIT_MASK         (0x4U)
#define S50_ELS_SHA2_CTRL_SHA2_INIT_SHIFT        (2U)
/*! sha2_init - Write to 1 to Init the SHA2 Kernel */
#define S50_ELS_SHA2_CTRL_SHA2_INIT(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_INIT_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_INIT_MASK)

#define S50_ELS_SHA2_CTRL_SHA2_LOAD_MASK         (0x8U)
#define S50_ELS_SHA2_CTRL_SHA2_LOAD_SHIFT        (3U)
/*! sha2_load - Write to 1 to Load the SHA2 Kernel */
#define S50_ELS_SHA2_CTRL_SHA2_LOAD(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_LOAD_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_LOAD_MASK)

#define S50_ELS_SHA2_CTRL_SHA2_MODE_MASK         (0x30U)
#define S50_ELS_SHA2_CTRL_SHA2_MODE_SHIFT        (4U)
/*! sha2_mode - SHA2 MODE: */
#define S50_ELS_SHA2_CTRL_SHA2_MODE(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_MODE_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_MODE_MASK)

#define S50_ELS_SHA2_CTRL_CTRL_RSVD1_MASK        (0x1C0U)
#define S50_ELS_SHA2_CTRL_CTRL_RSVD1_SHIFT       (6U)
/*! ctrl_rsvd1 - r-eserved */
#define S50_ELS_SHA2_CTRL_CTRL_RSVD1(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_CTRL_RSVD1_SHIFT)) & S50_ELS_SHA2_CTRL_CTRL_RSVD1_MASK)

#define S50_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_MASK   (0x200U)
#define S50_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_SHIFT  (9U)
/*! sha2_byte_order - Write to 1 to Reverse byte endianess */
#define S50_ELS_SHA2_CTRL_SHA2_BYTE_ORDER(x)     (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_SHIFT)) & S50_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_MASK)

#define S50_ELS_SHA2_CTRL_CTRL_RSVD_MASK         (0xFFFFFC00U)
#define S50_ELS_SHA2_CTRL_CTRL_RSVD_SHIFT        (10U)
/*! ctrl_rsvd - r-eserved */
#define S50_ELS_SHA2_CTRL_CTRL_RSVD(x)           (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_CTRL_CTRL_RSVD_SHIFT)) & S50_ELS_SHA2_CTRL_CTRL_RSVD_MASK)
/*! @} */

/*! @name ELS_SHA2_DIN - ELS SHA_DATA IN Register 0 */
/*! @{ */

#define S50_ELS_SHA2_DIN_SHA_DATIN_MASK          (0xFFFFFFFFU)
#define S50_ELS_SHA2_DIN_SHA_DATIN_SHIFT         (0U)
/*! sha_datin - Output ELS_SHA_DATIN from ELS Application being executed */
#define S50_ELS_SHA2_DIN_SHA_DATIN(x)            (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DIN_SHA_DATIN_SHIFT)) & S50_ELS_SHA2_DIN_SHA_DATIN_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT0 - ELS ELS_SHA_DATA Out Register 0 */
/*! @{ */

#define S50_ELS_SHA2_DOUT0_SHA_DATA0_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT0_SHA_DATA0_SHIFT       (0U)
/*! sha_data0 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT0_SHA_DATA0(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT0_SHA_DATA0_SHIFT)) & S50_ELS_SHA2_DOUT0_SHA_DATA0_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT1 - ELS SHA_DATA Out Register 1 */
/*! @{ */

#define S50_ELS_SHA2_DOUT1_SHA_DATA1_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT1_SHA_DATA1_SHIFT       (0U)
/*! sha_data1 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT1_SHA_DATA1(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT1_SHA_DATA1_SHIFT)) & S50_ELS_SHA2_DOUT1_SHA_DATA1_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT2 - ELS SHA_DATA Out Register 2 */
/*! @{ */

#define S50_ELS_SHA2_DOUT2_SHA_DATA2_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT2_SHA_DATA2_SHIFT       (0U)
/*! sha_data2 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT2_SHA_DATA2(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT2_SHA_DATA2_SHIFT)) & S50_ELS_SHA2_DOUT2_SHA_DATA2_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT3 - ELS SHA_DATA Out Register 3 */
/*! @{ */

#define S50_ELS_SHA2_DOUT3_SHA_DATA3_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT3_SHA_DATA3_SHIFT       (0U)
/*! sha_data3 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT3_SHA_DATA3(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT3_SHA_DATA3_SHIFT)) & S50_ELS_SHA2_DOUT3_SHA_DATA3_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT4 - ELS SHA_DATA Out Register 4 */
/*! @{ */

#define S50_ELS_SHA2_DOUT4_SHA_DATA4_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT4_SHA_DATA4_SHIFT       (0U)
/*! sha_data4 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT4_SHA_DATA4(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT4_SHA_DATA4_SHIFT)) & S50_ELS_SHA2_DOUT4_SHA_DATA4_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT5 - ELS SHA_DATA Out Register 5 */
/*! @{ */

#define S50_ELS_SHA2_DOUT5_SHA_DATA5_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT5_SHA_DATA5_SHIFT       (0U)
/*! sha_data5 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT5_SHA_DATA5(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT5_SHA_DATA5_SHIFT)) & S50_ELS_SHA2_DOUT5_SHA_DATA5_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT6 - ELS SHA_DATA Out Register 6 */
/*! @{ */

#define S50_ELS_SHA2_DOUT6_SHA_DATA6_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT6_SHA_DATA6_SHIFT       (0U)
/*! sha_data6 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT6_SHA_DATA6(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT6_SHA_DATA6_SHIFT)) & S50_ELS_SHA2_DOUT6_SHA_DATA6_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT7 - ELS SHA_DATA Out Register 7 */
/*! @{ */

#define S50_ELS_SHA2_DOUT7_SHA_DATA7_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT7_SHA_DATA7_SHIFT       (0U)
/*! sha_data7 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT7_SHA_DATA7(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT7_SHA_DATA7_SHIFT)) & S50_ELS_SHA2_DOUT7_SHA_DATA7_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT8 - ELS ELS_SHA_DATA Out Register 8 */
/*! @{ */

#define S50_ELS_SHA2_DOUT8_SHA_DATA8_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT8_SHA_DATA8_SHIFT       (0U)
/*! sha_data8 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT8_SHA_DATA8(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT8_SHA_DATA8_SHIFT)) & S50_ELS_SHA2_DOUT8_SHA_DATA8_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT9 - ELS SHA_DATA Out Register 9 */
/*! @{ */

#define S50_ELS_SHA2_DOUT9_SHA_DATA9_MASK        (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT9_SHA_DATA9_SHIFT       (0U)
/*! sha_data9 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT9_SHA_DATA9(x)          (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT9_SHA_DATA9_SHIFT)) & S50_ELS_SHA2_DOUT9_SHA_DATA9_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT10 - ELS SHA_DATA Out Register 10 */
/*! @{ */

#define S50_ELS_SHA2_DOUT10_SHA_DATA10_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT10_SHA_DATA10_SHIFT     (0U)
/*! sha_data10 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT10_SHA_DATA10(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT10_SHA_DATA10_SHIFT)) & S50_ELS_SHA2_DOUT10_SHA_DATA10_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT11 - ELS SHA_DATA Out Register 11 */
/*! @{ */

#define S50_ELS_SHA2_DOUT11_SHA_DATA11_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT11_SHA_DATA11_SHIFT     (0U)
/*! sha_data11 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT11_SHA_DATA11(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT11_SHA_DATA11_SHIFT)) & S50_ELS_SHA2_DOUT11_SHA_DATA11_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT12 - ELS SHA_DATA Out Register 12 */
/*! @{ */

#define S50_ELS_SHA2_DOUT12_SHA_DATA12_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT12_SHA_DATA12_SHIFT     (0U)
/*! sha_data12 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT12_SHA_DATA12(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT12_SHA_DATA12_SHIFT)) & S50_ELS_SHA2_DOUT12_SHA_DATA12_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT13 - ELS SHA_DATA Out Register 13 */
/*! @{ */

#define S50_ELS_SHA2_DOUT13_SHA_DATA13_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT13_SHA_DATA13_SHIFT     (0U)
/*! sha_data13 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT13_SHA_DATA13(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT13_SHA_DATA13_SHIFT)) & S50_ELS_SHA2_DOUT13_SHA_DATA13_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT14 - ELS SHA_DATA Out Register 14 */
/*! @{ */

#define S50_ELS_SHA2_DOUT14_SHA_DATA14_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT14_SHA_DATA14_SHIFT     (0U)
/*! sha_data14 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT14_SHA_DATA14(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT14_SHA_DATA14_SHIFT)) & S50_ELS_SHA2_DOUT14_SHA_DATA14_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT15 - ELS SHA_DATA Out Register 15 */
/*! @{ */

#define S50_ELS_SHA2_DOUT15_SHA_DATA15_MASK      (0xFFFFFFFFU)
#define S50_ELS_SHA2_DOUT15_SHA_DATA15_SHIFT     (0U)
/*! sha_data15 - Output SHA_DATA from ELS Application being executed */
#define S50_ELS_SHA2_DOUT15_SHA_DATA15(x)        (((uint32_t)(((uint32_t)(x)) << S50_ELS_SHA2_DOUT15_SHA_DATA15_SHIFT)) & S50_ELS_SHA2_DOUT15_SHA_DATA15_MASK)
/*! @} */

/*! @name ELS_KS0 - Status register */
/*! @{ */

#define S50_ELS_KS0_KS0_KSIZE_MASK               (0x1U)
#define S50_ELS_KS0_KS0_KSIZE_SHIFT              (0U)
/*! ks0_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS0_KS0_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KSIZE_SHIFT)) & S50_ELS_KS0_KS0_KSIZE_MASK)

#define S50_ELS_KS0_KS0_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS0_KS0_RSVD0_SHIFT              (1U)
/*! ks0_rsvd0 - Reserved 0 */
#define S50_ELS_KS0_KS0_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_RSVD0_SHIFT)) & S50_ELS_KS0_KS0_RSVD0_MASK)

#define S50_ELS_KS0_KS0_KACT_MASK                (0x20U)
#define S50_ELS_KS0_KS0_KACT_SHIFT               (5U)
/*! ks0_kact - Key is active */
#define S50_ELS_KS0_KS0_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KACT_SHIFT)) & S50_ELS_KS0_KS0_KACT_MASK)

#define S50_ELS_KS0_KS0_KBASE_MASK               (0x40U)
#define S50_ELS_KS0_KS0_KBASE_SHIFT              (6U)
/*! ks0_kbase - First slot in a multislot key */
#define S50_ELS_KS0_KS0_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_KBASE_SHIFT)) & S50_ELS_KS0_KS0_KBASE_MASK)

#define S50_ELS_KS0_KS0_FGP_MASK                 (0x80U)
#define S50_ELS_KS0_KS0_FGP_SHIFT                (7U)
/*! ks0_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS0_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FGP_SHIFT)) & S50_ELS_KS0_KS0_FGP_MASK)

#define S50_ELS_KS0_KS0_FRTN_MASK                (0x100U)
#define S50_ELS_KS0_KS0_FRTN_SHIFT               (8U)
/*! ks0_frtn - Hardware Feature Retention */
#define S50_ELS_KS0_KS0_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FRTN_SHIFT)) & S50_ELS_KS0_KS0_FRTN_MASK)

#define S50_ELS_KS0_KS0_FHWO_MASK                (0x200U)
#define S50_ELS_KS0_KS0_FHWO_SHIFT               (9U)
/*! ks0_fhwo - Hardware Feature Output */
#define S50_ELS_KS0_KS0_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_FHWO_SHIFT)) & S50_ELS_KS0_KS0_FHWO_MASK)

#define S50_ELS_KS0_KS0_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS0_KS0_RSVD1_SHIFT              (10U)
/*! ks0_rsvd1 - Reserved 1 */
#define S50_ELS_KS0_KS0_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_RSVD1_SHIFT)) & S50_ELS_KS0_KS0_RSVD1_MASK)

#define S50_ELS_KS0_KS0_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS0_KS0_UCMAC_SHIFT              (13U)
/*! ks0_ucmac - CMAC key */
#define S50_ELS_KS0_KS0_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UCMAC_SHIFT)) & S50_ELS_KS0_KS0_UCMAC_MASK)

#define S50_ELS_KS0_KS0_UKSK_MASK                (0x4000U)
#define S50_ELS_KS0_KS0_UKSK_SHIFT               (14U)
/*! ks0_uksk - KSK key */
#define S50_ELS_KS0_KS0_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKSK_SHIFT)) & S50_ELS_KS0_KS0_UKSK_MASK)

#define S50_ELS_KS0_KS0_URTF_MASK                (0x8000U)
#define S50_ELS_KS0_KS0_URTF_SHIFT               (15U)
/*! ks0_urtf - Real Time Fingerprint key */
#define S50_ELS_KS0_KS0_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_URTF_SHIFT)) & S50_ELS_KS0_KS0_URTF_MASK)

#define S50_ELS_KS0_KS0_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS0_KS0_UCKDF_SHIFT              (16U)
/*! ks0_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS0_KS0_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UCKDF_SHIFT)) & S50_ELS_KS0_KS0_UCKDF_MASK)

#define S50_ELS_KS0_KS0_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS0_KS0_UHKDF_SHIFT              (17U)
/*! ks0_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS0_KS0_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHKDF_SHIFT)) & S50_ELS_KS0_KS0_UHKDF_MASK)

#define S50_ELS_KS0_KS0_UECSG_MASK               (0x40000U)
#define S50_ELS_KS0_KS0_UECSG_SHIFT              (18U)
/*! ks0_uecsg - Ecc signing key */
#define S50_ELS_KS0_KS0_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UECSG_SHIFT)) & S50_ELS_KS0_KS0_UECSG_MASK)

#define S50_ELS_KS0_KS0_UECDH_MASK               (0x80000U)
#define S50_ELS_KS0_KS0_UECDH_SHIFT              (19U)
/*! ks0_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS0_KS0_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UECDH_SHIFT)) & S50_ELS_KS0_KS0_UECDH_MASK)

#define S50_ELS_KS0_KS0_UAES_MASK                (0x100000U)
#define S50_ELS_KS0_KS0_UAES_SHIFT               (20U)
/*! ks0_uaes - Aes key */
#define S50_ELS_KS0_KS0_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UAES_SHIFT)) & S50_ELS_KS0_KS0_UAES_MASK)

#define S50_ELS_KS0_KS0_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS0_KS0_UHMAC_SHIFT              (21U)
/*! ks0_uhmac - Hmac key */
#define S50_ELS_KS0_KS0_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHMAC_SHIFT)) & S50_ELS_KS0_KS0_UHMAC_MASK)

#define S50_ELS_KS0_KS0_UKWK_MASK                (0x400000U)
#define S50_ELS_KS0_KS0_UKWK_SHIFT               (22U)
/*! ks0_ukwk - Key wrapping key */
#define S50_ELS_KS0_KS0_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKWK_SHIFT)) & S50_ELS_KS0_KS0_UKWK_MASK)

#define S50_ELS_KS0_KS0_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS0_KS0_UKUOK_SHIFT              (23U)
/*! ks0_ukuok - Key unwrapping key */
#define S50_ELS_KS0_KS0_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKUOK_SHIFT)) & S50_ELS_KS0_KS0_UKUOK_MASK)

#define S50_ELS_KS0_KS0_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS0_KS0_UTLSPMS_SHIFT            (24U)
/*! ks0_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS0_KS0_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UTLSPMS_SHIFT)) & S50_ELS_KS0_KS0_UTLSPMS_MASK)

#define S50_ELS_KS0_KS0_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS0_KS0_UTLSMS_SHIFT             (25U)
/*! ks0_utlsms - TLS Master Secret */
#define S50_ELS_KS0_KS0_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UTLSMS_SHIFT)) & S50_ELS_KS0_KS0_UTLSMS_MASK)

#define S50_ELS_KS0_KS0_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS0_KS0_UKGSRC_SHIFT             (26U)
/*! ks0_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS0_KS0_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UKGSRC_SHIFT)) & S50_ELS_KS0_KS0_UKGSRC_MASK)

#define S50_ELS_KS0_KS0_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS0_KS0_UHWO_SHIFT               (27U)
/*! ks0_uhwo - Hardware out key */
#define S50_ELS_KS0_KS0_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UHWO_SHIFT)) & S50_ELS_KS0_KS0_UHWO_MASK)

#define S50_ELS_KS0_KS0_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS0_KS0_UWRPOK_SHIFT             (28U)
/*! ks0_uwrpok - Ok to wrap key */
#define S50_ELS_KS0_KS0_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UWRPOK_SHIFT)) & S50_ELS_KS0_KS0_UWRPOK_MASK)

#define S50_ELS_KS0_KS0_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS0_KS0_UDUK_SHIFT               (29U)
/*! ks0_uduk - Device Unique Key */
#define S50_ELS_KS0_KS0_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UDUK_SHIFT)) & S50_ELS_KS0_KS0_UDUK_MASK)

#define S50_ELS_KS0_KS0_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS0_KS0_UPPROT_SHIFT             (30U)
/*! ks0_upprot - Priviledge level */
#define S50_ELS_KS0_KS0_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS0_KS0_UPPROT_SHIFT)) & S50_ELS_KS0_KS0_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS1 - Status register */
/*! @{ */

#define S50_ELS_KS1_KS1_KSIZE_MASK               (0x1U)
#define S50_ELS_KS1_KS1_KSIZE_SHIFT              (0U)
/*! ks1_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS1_KS1_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KSIZE_SHIFT)) & S50_ELS_KS1_KS1_KSIZE_MASK)

#define S50_ELS_KS1_KS1_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS1_KS1_RSVD0_SHIFT              (1U)
/*! ks1_rsvd0 - Reserved 0 */
#define S50_ELS_KS1_KS1_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_RSVD0_SHIFT)) & S50_ELS_KS1_KS1_RSVD0_MASK)

#define S50_ELS_KS1_KS1_KACT_MASK                (0x20U)
#define S50_ELS_KS1_KS1_KACT_SHIFT               (5U)
/*! ks1_kact - Key is active */
#define S50_ELS_KS1_KS1_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KACT_SHIFT)) & S50_ELS_KS1_KS1_KACT_MASK)

#define S50_ELS_KS1_KS1_KBASE_MASK               (0x40U)
#define S50_ELS_KS1_KS1_KBASE_SHIFT              (6U)
/*! ks1_kbase - First slot in a multislot key */
#define S50_ELS_KS1_KS1_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_KBASE_SHIFT)) & S50_ELS_KS1_KS1_KBASE_MASK)

#define S50_ELS_KS1_KS1_FGP_MASK                 (0x80U)
#define S50_ELS_KS1_KS1_FGP_SHIFT                (7U)
/*! ks1_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS1_KS1_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FGP_SHIFT)) & S50_ELS_KS1_KS1_FGP_MASK)

#define S50_ELS_KS1_KS1_FRTN_MASK                (0x100U)
#define S50_ELS_KS1_KS1_FRTN_SHIFT               (8U)
/*! ks1_frtn - Hardware Feature Retention */
#define S50_ELS_KS1_KS1_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FRTN_SHIFT)) & S50_ELS_KS1_KS1_FRTN_MASK)

#define S50_ELS_KS1_KS1_FHWO_MASK                (0x200U)
#define S50_ELS_KS1_KS1_FHWO_SHIFT               (9U)
/*! ks1_fhwo - Hardware Feature Output */
#define S50_ELS_KS1_KS1_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_FHWO_SHIFT)) & S50_ELS_KS1_KS1_FHWO_MASK)

#define S50_ELS_KS1_KS1_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS1_KS1_RSVD1_SHIFT              (10U)
/*! ks1_rsvd1 - Reserved 1 */
#define S50_ELS_KS1_KS1_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_RSVD1_SHIFT)) & S50_ELS_KS1_KS1_RSVD1_MASK)

#define S50_ELS_KS1_KS1_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS1_KS1_UCMAC_SHIFT              (13U)
/*! ks1_ucmac - CMAC key */
#define S50_ELS_KS1_KS1_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UCMAC_SHIFT)) & S50_ELS_KS1_KS1_UCMAC_MASK)

#define S50_ELS_KS1_KS1_UKSK_MASK                (0x4000U)
#define S50_ELS_KS1_KS1_UKSK_SHIFT               (14U)
/*! ks1_uksk - KSK key */
#define S50_ELS_KS1_KS1_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKSK_SHIFT)) & S50_ELS_KS1_KS1_UKSK_MASK)

#define S50_ELS_KS1_KS1_URTF_MASK                (0x8000U)
#define S50_ELS_KS1_KS1_URTF_SHIFT               (15U)
/*! ks1_urtf - Real Time Fingerprint key */
#define S50_ELS_KS1_KS1_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_URTF_SHIFT)) & S50_ELS_KS1_KS1_URTF_MASK)

#define S50_ELS_KS1_KS1_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS1_KS1_UCKDF_SHIFT              (16U)
/*! ks1_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS1_KS1_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UCKDF_SHIFT)) & S50_ELS_KS1_KS1_UCKDF_MASK)

#define S50_ELS_KS1_KS1_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS1_KS1_UHKDF_SHIFT              (17U)
/*! ks1_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS1_KS1_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHKDF_SHIFT)) & S50_ELS_KS1_KS1_UHKDF_MASK)

#define S50_ELS_KS1_KS1_UECSG_MASK               (0x40000U)
#define S50_ELS_KS1_KS1_UECSG_SHIFT              (18U)
/*! ks1_uecsg - Ecc signing key */
#define S50_ELS_KS1_KS1_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UECSG_SHIFT)) & S50_ELS_KS1_KS1_UECSG_MASK)

#define S50_ELS_KS1_KS1_UECDH_MASK               (0x80000U)
#define S50_ELS_KS1_KS1_UECDH_SHIFT              (19U)
/*! ks1_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS1_KS1_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UECDH_SHIFT)) & S50_ELS_KS1_KS1_UECDH_MASK)

#define S50_ELS_KS1_KS1_UAES_MASK                (0x100000U)
#define S50_ELS_KS1_KS1_UAES_SHIFT               (20U)
/*! ks1_uaes - Aes key */
#define S50_ELS_KS1_KS1_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UAES_SHIFT)) & S50_ELS_KS1_KS1_UAES_MASK)

#define S50_ELS_KS1_KS1_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS1_KS1_UHMAC_SHIFT              (21U)
/*! ks1_uhmac - Hmac key */
#define S50_ELS_KS1_KS1_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHMAC_SHIFT)) & S50_ELS_KS1_KS1_UHMAC_MASK)

#define S50_ELS_KS1_KS1_UKWK_MASK                (0x400000U)
#define S50_ELS_KS1_KS1_UKWK_SHIFT               (22U)
/*! ks1_ukwk - Key wrapping key */
#define S50_ELS_KS1_KS1_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKWK_SHIFT)) & S50_ELS_KS1_KS1_UKWK_MASK)

#define S50_ELS_KS1_KS1_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS1_KS1_UKUOK_SHIFT              (23U)
/*! ks1_ukuok - Key unwrapping key */
#define S50_ELS_KS1_KS1_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKUOK_SHIFT)) & S50_ELS_KS1_KS1_UKUOK_MASK)

#define S50_ELS_KS1_KS1_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS1_KS1_UTLSPMS_SHIFT            (24U)
/*! ks1_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS1_KS1_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UTLSPMS_SHIFT)) & S50_ELS_KS1_KS1_UTLSPMS_MASK)

#define S50_ELS_KS1_KS1_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS1_KS1_UTLSMS_SHIFT             (25U)
/*! ks1_utlsms - TLS Master Secret */
#define S50_ELS_KS1_KS1_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UTLSMS_SHIFT)) & S50_ELS_KS1_KS1_UTLSMS_MASK)

#define S50_ELS_KS1_KS1_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS1_KS1_UKGSRC_SHIFT             (26U)
/*! ks1_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS1_KS1_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UKGSRC_SHIFT)) & S50_ELS_KS1_KS1_UKGSRC_MASK)

#define S50_ELS_KS1_KS1_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS1_KS1_UHWO_SHIFT               (27U)
/*! ks1_uhwo - Hardware out key */
#define S50_ELS_KS1_KS1_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UHWO_SHIFT)) & S50_ELS_KS1_KS1_UHWO_MASK)

#define S50_ELS_KS1_KS1_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS1_KS1_UWRPOK_SHIFT             (28U)
/*! ks1_uwrpok - Ok to wrap key */
#define S50_ELS_KS1_KS1_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UWRPOK_SHIFT)) & S50_ELS_KS1_KS1_UWRPOK_MASK)

#define S50_ELS_KS1_KS1_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS1_KS1_UDUK_SHIFT               (29U)
/*! ks1_uduk - Device Unique Key */
#define S50_ELS_KS1_KS1_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UDUK_SHIFT)) & S50_ELS_KS1_KS1_UDUK_MASK)

#define S50_ELS_KS1_KS1_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS1_KS1_UPPROT_SHIFT             (30U)
/*! ks1_upprot - Priviledge level */
#define S50_ELS_KS1_KS1_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS1_KS1_UPPROT_SHIFT)) & S50_ELS_KS1_KS1_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS2 - Status register */
/*! @{ */

#define S50_ELS_KS2_KS2_KSIZE_MASK               (0x1U)
#define S50_ELS_KS2_KS2_KSIZE_SHIFT              (0U)
/*! ks2_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS2_KS2_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KSIZE_SHIFT)) & S50_ELS_KS2_KS2_KSIZE_MASK)

#define S50_ELS_KS2_KS2_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS2_KS2_RSVD0_SHIFT              (1U)
/*! ks2_rsvd0 - Reserved 0 */
#define S50_ELS_KS2_KS2_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_RSVD0_SHIFT)) & S50_ELS_KS2_KS2_RSVD0_MASK)

#define S50_ELS_KS2_KS2_KACT_MASK                (0x20U)
#define S50_ELS_KS2_KS2_KACT_SHIFT               (5U)
/*! ks2_kact - Key is active */
#define S50_ELS_KS2_KS2_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KACT_SHIFT)) & S50_ELS_KS2_KS2_KACT_MASK)

#define S50_ELS_KS2_KS2_KBASE_MASK               (0x40U)
#define S50_ELS_KS2_KS2_KBASE_SHIFT              (6U)
/*! ks2_kbase - First slot in a multislot key */
#define S50_ELS_KS2_KS2_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_KBASE_SHIFT)) & S50_ELS_KS2_KS2_KBASE_MASK)

#define S50_ELS_KS2_KS2_FGP_MASK                 (0x80U)
#define S50_ELS_KS2_KS2_FGP_SHIFT                (7U)
/*! ks2_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS2_KS2_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FGP_SHIFT)) & S50_ELS_KS2_KS2_FGP_MASK)

#define S50_ELS_KS2_KS2_FRTN_MASK                (0x100U)
#define S50_ELS_KS2_KS2_FRTN_SHIFT               (8U)
/*! ks2_frtn - Hardware Feature Retention */
#define S50_ELS_KS2_KS2_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FRTN_SHIFT)) & S50_ELS_KS2_KS2_FRTN_MASK)

#define S50_ELS_KS2_KS2_FHWO_MASK                (0x200U)
#define S50_ELS_KS2_KS2_FHWO_SHIFT               (9U)
/*! ks2_fhwo - Hardware Feature Output */
#define S50_ELS_KS2_KS2_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_FHWO_SHIFT)) & S50_ELS_KS2_KS2_FHWO_MASK)

#define S50_ELS_KS2_KS2_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS2_KS2_RSVD1_SHIFT              (10U)
/*! ks2_rsvd1 - Reserved 1 */
#define S50_ELS_KS2_KS2_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_RSVD1_SHIFT)) & S50_ELS_KS2_KS2_RSVD1_MASK)

#define S50_ELS_KS2_KS2_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS2_KS2_UCMAC_SHIFT              (13U)
/*! ks2_ucmac - CMAC key */
#define S50_ELS_KS2_KS2_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UCMAC_SHIFT)) & S50_ELS_KS2_KS2_UCMAC_MASK)

#define S50_ELS_KS2_KS2_UKSK_MASK                (0x4000U)
#define S50_ELS_KS2_KS2_UKSK_SHIFT               (14U)
/*! ks2_uksk - KSK key */
#define S50_ELS_KS2_KS2_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKSK_SHIFT)) & S50_ELS_KS2_KS2_UKSK_MASK)

#define S50_ELS_KS2_KS2_URTF_MASK                (0x8000U)
#define S50_ELS_KS2_KS2_URTF_SHIFT               (15U)
/*! ks2_urtf - Real Time Fingerprint key */
#define S50_ELS_KS2_KS2_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_URTF_SHIFT)) & S50_ELS_KS2_KS2_URTF_MASK)

#define S50_ELS_KS2_KS2_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS2_KS2_UCKDF_SHIFT              (16U)
/*! ks2_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS2_KS2_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UCKDF_SHIFT)) & S50_ELS_KS2_KS2_UCKDF_MASK)

#define S50_ELS_KS2_KS2_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS2_KS2_UHKDF_SHIFT              (17U)
/*! ks2_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS2_KS2_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHKDF_SHIFT)) & S50_ELS_KS2_KS2_UHKDF_MASK)

#define S50_ELS_KS2_KS2_UECSG_MASK               (0x40000U)
#define S50_ELS_KS2_KS2_UECSG_SHIFT              (18U)
/*! ks2_uecsg - Ecc signing key */
#define S50_ELS_KS2_KS2_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UECSG_SHIFT)) & S50_ELS_KS2_KS2_UECSG_MASK)

#define S50_ELS_KS2_KS2_UECDH_MASK               (0x80000U)
#define S50_ELS_KS2_KS2_UECDH_SHIFT              (19U)
/*! ks2_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS2_KS2_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UECDH_SHIFT)) & S50_ELS_KS2_KS2_UECDH_MASK)

#define S50_ELS_KS2_KS2_UAES_MASK                (0x100000U)
#define S50_ELS_KS2_KS2_UAES_SHIFT               (20U)
/*! ks2_uaes - Aes key */
#define S50_ELS_KS2_KS2_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UAES_SHIFT)) & S50_ELS_KS2_KS2_UAES_MASK)

#define S50_ELS_KS2_KS2_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS2_KS2_UHMAC_SHIFT              (21U)
/*! ks2_uhmac - Hmac key */
#define S50_ELS_KS2_KS2_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHMAC_SHIFT)) & S50_ELS_KS2_KS2_UHMAC_MASK)

#define S50_ELS_KS2_KS2_UKWK_MASK                (0x400000U)
#define S50_ELS_KS2_KS2_UKWK_SHIFT               (22U)
/*! ks2_ukwk - Key wrapping key */
#define S50_ELS_KS2_KS2_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKWK_SHIFT)) & S50_ELS_KS2_KS2_UKWK_MASK)

#define S50_ELS_KS2_KS2_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS2_KS2_UKUOK_SHIFT              (23U)
/*! ks2_ukuok - Key unwrapping key */
#define S50_ELS_KS2_KS2_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKUOK_SHIFT)) & S50_ELS_KS2_KS2_UKUOK_MASK)

#define S50_ELS_KS2_KS2_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS2_KS2_UTLSPMS_SHIFT            (24U)
/*! ks2_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS2_KS2_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UTLSPMS_SHIFT)) & S50_ELS_KS2_KS2_UTLSPMS_MASK)

#define S50_ELS_KS2_KS2_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS2_KS2_UTLSMS_SHIFT             (25U)
/*! ks2_utlsms - TLS Master Secret */
#define S50_ELS_KS2_KS2_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UTLSMS_SHIFT)) & S50_ELS_KS2_KS2_UTLSMS_MASK)

#define S50_ELS_KS2_KS2_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS2_KS2_UKGSRC_SHIFT             (26U)
/*! ks2_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS2_KS2_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UKGSRC_SHIFT)) & S50_ELS_KS2_KS2_UKGSRC_MASK)

#define S50_ELS_KS2_KS2_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS2_KS2_UHWO_SHIFT               (27U)
/*! ks2_uhwo - Hardware out key */
#define S50_ELS_KS2_KS2_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UHWO_SHIFT)) & S50_ELS_KS2_KS2_UHWO_MASK)

#define S50_ELS_KS2_KS2_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS2_KS2_UWRPOK_SHIFT             (28U)
/*! ks2_uwrpok - Ok to wrap key */
#define S50_ELS_KS2_KS2_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UWRPOK_SHIFT)) & S50_ELS_KS2_KS2_UWRPOK_MASK)

#define S50_ELS_KS2_KS2_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS2_KS2_UDUK_SHIFT               (29U)
/*! ks2_uduk - Device Unique Key */
#define S50_ELS_KS2_KS2_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UDUK_SHIFT)) & S50_ELS_KS2_KS2_UDUK_MASK)

#define S50_ELS_KS2_KS2_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS2_KS2_UPPROT_SHIFT             (30U)
/*! ks2_upprot - Priviledge level */
#define S50_ELS_KS2_KS2_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS2_KS2_UPPROT_SHIFT)) & S50_ELS_KS2_KS2_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS3 - Status register */
/*! @{ */

#define S50_ELS_KS3_KS3_KSIZE_MASK               (0x1U)
#define S50_ELS_KS3_KS3_KSIZE_SHIFT              (0U)
/*! ks3_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS3_KS3_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KSIZE_SHIFT)) & S50_ELS_KS3_KS3_KSIZE_MASK)

#define S50_ELS_KS3_KS3_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS3_KS3_RSVD0_SHIFT              (1U)
/*! ks3_rsvd0 - Reserved 0 */
#define S50_ELS_KS3_KS3_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_RSVD0_SHIFT)) & S50_ELS_KS3_KS3_RSVD0_MASK)

#define S50_ELS_KS3_KS3_KACT_MASK                (0x20U)
#define S50_ELS_KS3_KS3_KACT_SHIFT               (5U)
/*! ks3_kact - Key is active */
#define S50_ELS_KS3_KS3_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KACT_SHIFT)) & S50_ELS_KS3_KS3_KACT_MASK)

#define S50_ELS_KS3_KS3_KBASE_MASK               (0x40U)
#define S50_ELS_KS3_KS3_KBASE_SHIFT              (6U)
/*! ks3_kbase - First slot in a multislot key */
#define S50_ELS_KS3_KS3_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_KBASE_SHIFT)) & S50_ELS_KS3_KS3_KBASE_MASK)

#define S50_ELS_KS3_KS3_FGP_MASK                 (0x80U)
#define S50_ELS_KS3_KS3_FGP_SHIFT                (7U)
/*! ks3_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS3_KS3_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FGP_SHIFT)) & S50_ELS_KS3_KS3_FGP_MASK)

#define S50_ELS_KS3_KS3_FRTN_MASK                (0x100U)
#define S50_ELS_KS3_KS3_FRTN_SHIFT               (8U)
/*! ks3_frtn - Hardware Feature Retention */
#define S50_ELS_KS3_KS3_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FRTN_SHIFT)) & S50_ELS_KS3_KS3_FRTN_MASK)

#define S50_ELS_KS3_KS3_FHWO_MASK                (0x200U)
#define S50_ELS_KS3_KS3_FHWO_SHIFT               (9U)
/*! ks3_fhwo - Hardware Feature Output */
#define S50_ELS_KS3_KS3_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_FHWO_SHIFT)) & S50_ELS_KS3_KS3_FHWO_MASK)

#define S50_ELS_KS3_KS3_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS3_KS3_RSVD1_SHIFT              (10U)
/*! ks3_rsvd1 - Reserved 1 */
#define S50_ELS_KS3_KS3_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_RSVD1_SHIFT)) & S50_ELS_KS3_KS3_RSVD1_MASK)

#define S50_ELS_KS3_KS3_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS3_KS3_UCMAC_SHIFT              (13U)
/*! ks3_ucmac - CMAC key */
#define S50_ELS_KS3_KS3_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UCMAC_SHIFT)) & S50_ELS_KS3_KS3_UCMAC_MASK)

#define S50_ELS_KS3_KS3_UKSK_MASK                (0x4000U)
#define S50_ELS_KS3_KS3_UKSK_SHIFT               (14U)
/*! ks3_uksk - KSK key */
#define S50_ELS_KS3_KS3_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKSK_SHIFT)) & S50_ELS_KS3_KS3_UKSK_MASK)

#define S50_ELS_KS3_KS3_URTF_MASK                (0x8000U)
#define S50_ELS_KS3_KS3_URTF_SHIFT               (15U)
/*! ks3_urtf - Real Time Fingerprint key */
#define S50_ELS_KS3_KS3_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_URTF_SHIFT)) & S50_ELS_KS3_KS3_URTF_MASK)

#define S50_ELS_KS3_KS3_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS3_KS3_UCKDF_SHIFT              (16U)
/*! ks3_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS3_KS3_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UCKDF_SHIFT)) & S50_ELS_KS3_KS3_UCKDF_MASK)

#define S50_ELS_KS3_KS3_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS3_KS3_UHKDF_SHIFT              (17U)
/*! ks3_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS3_KS3_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHKDF_SHIFT)) & S50_ELS_KS3_KS3_UHKDF_MASK)

#define S50_ELS_KS3_KS3_UECSG_MASK               (0x40000U)
#define S50_ELS_KS3_KS3_UECSG_SHIFT              (18U)
/*! ks3_uecsg - Ecc signing key */
#define S50_ELS_KS3_KS3_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UECSG_SHIFT)) & S50_ELS_KS3_KS3_UECSG_MASK)

#define S50_ELS_KS3_KS3_UECDH_MASK               (0x80000U)
#define S50_ELS_KS3_KS3_UECDH_SHIFT              (19U)
/*! ks3_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS3_KS3_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UECDH_SHIFT)) & S50_ELS_KS3_KS3_UECDH_MASK)

#define S50_ELS_KS3_KS3_UAES_MASK                (0x100000U)
#define S50_ELS_KS3_KS3_UAES_SHIFT               (20U)
/*! ks3_uaes - Aes key */
#define S50_ELS_KS3_KS3_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UAES_SHIFT)) & S50_ELS_KS3_KS3_UAES_MASK)

#define S50_ELS_KS3_KS3_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS3_KS3_UHMAC_SHIFT              (21U)
/*! ks3_uhmac - Hmac key */
#define S50_ELS_KS3_KS3_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHMAC_SHIFT)) & S50_ELS_KS3_KS3_UHMAC_MASK)

#define S50_ELS_KS3_KS3_UKWK_MASK                (0x400000U)
#define S50_ELS_KS3_KS3_UKWK_SHIFT               (22U)
/*! ks3_ukwk - Key wrapping key */
#define S50_ELS_KS3_KS3_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKWK_SHIFT)) & S50_ELS_KS3_KS3_UKWK_MASK)

#define S50_ELS_KS3_KS3_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS3_KS3_UKUOK_SHIFT              (23U)
/*! ks3_ukuok - Key unwrapping key */
#define S50_ELS_KS3_KS3_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKUOK_SHIFT)) & S50_ELS_KS3_KS3_UKUOK_MASK)

#define S50_ELS_KS3_KS3_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS3_KS3_UTLSPMS_SHIFT            (24U)
/*! ks3_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS3_KS3_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UTLSPMS_SHIFT)) & S50_ELS_KS3_KS3_UTLSPMS_MASK)

#define S50_ELS_KS3_KS3_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS3_KS3_UTLSMS_SHIFT             (25U)
/*! ks3_utlsms - TLS Master Secret */
#define S50_ELS_KS3_KS3_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UTLSMS_SHIFT)) & S50_ELS_KS3_KS3_UTLSMS_MASK)

#define S50_ELS_KS3_KS3_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS3_KS3_UKGSRC_SHIFT             (26U)
/*! ks3_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS3_KS3_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UKGSRC_SHIFT)) & S50_ELS_KS3_KS3_UKGSRC_MASK)

#define S50_ELS_KS3_KS3_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS3_KS3_UHWO_SHIFT               (27U)
/*! ks3_uhwo - Hardware out key */
#define S50_ELS_KS3_KS3_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UHWO_SHIFT)) & S50_ELS_KS3_KS3_UHWO_MASK)

#define S50_ELS_KS3_KS3_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS3_KS3_UWRPOK_SHIFT             (28U)
/*! ks3_uwrpok - Ok to wrap key */
#define S50_ELS_KS3_KS3_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UWRPOK_SHIFT)) & S50_ELS_KS3_KS3_UWRPOK_MASK)

#define S50_ELS_KS3_KS3_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS3_KS3_UDUK_SHIFT               (29U)
/*! ks3_uduk - Device Unique Key */
#define S50_ELS_KS3_KS3_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UDUK_SHIFT)) & S50_ELS_KS3_KS3_UDUK_MASK)

#define S50_ELS_KS3_KS3_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS3_KS3_UPPROT_SHIFT             (30U)
/*! ks3_upprot - Priviledge level */
#define S50_ELS_KS3_KS3_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS3_KS3_UPPROT_SHIFT)) & S50_ELS_KS3_KS3_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS4 - Status register */
/*! @{ */

#define S50_ELS_KS4_KS4_KSIZE_MASK               (0x1U)
#define S50_ELS_KS4_KS4_KSIZE_SHIFT              (0U)
/*! ks4_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS4_KS4_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KSIZE_SHIFT)) & S50_ELS_KS4_KS4_KSIZE_MASK)

#define S50_ELS_KS4_KS4_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS4_KS4_RSVD0_SHIFT              (1U)
/*! ks4_rsvd0 - Reserved 0 */
#define S50_ELS_KS4_KS4_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_RSVD0_SHIFT)) & S50_ELS_KS4_KS4_RSVD0_MASK)

#define S50_ELS_KS4_KS4_KACT_MASK                (0x20U)
#define S50_ELS_KS4_KS4_KACT_SHIFT               (5U)
/*! ks4_kact - Key is active */
#define S50_ELS_KS4_KS4_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KACT_SHIFT)) & S50_ELS_KS4_KS4_KACT_MASK)

#define S50_ELS_KS4_KS4_KBASE_MASK               (0x40U)
#define S50_ELS_KS4_KS4_KBASE_SHIFT              (6U)
/*! ks4_kbase - First slot in a multislot key */
#define S50_ELS_KS4_KS4_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_KBASE_SHIFT)) & S50_ELS_KS4_KS4_KBASE_MASK)

#define S50_ELS_KS4_KS4_FGP_MASK                 (0x80U)
#define S50_ELS_KS4_KS4_FGP_SHIFT                (7U)
/*! ks4_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS4_KS4_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FGP_SHIFT)) & S50_ELS_KS4_KS4_FGP_MASK)

#define S50_ELS_KS4_KS4_FRTN_MASK                (0x100U)
#define S50_ELS_KS4_KS4_FRTN_SHIFT               (8U)
/*! ks4_frtn - Hardware Feature Retention */
#define S50_ELS_KS4_KS4_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FRTN_SHIFT)) & S50_ELS_KS4_KS4_FRTN_MASK)

#define S50_ELS_KS4_KS4_FHWO_MASK                (0x200U)
#define S50_ELS_KS4_KS4_FHWO_SHIFT               (9U)
/*! ks4_fhwo - Hardware Feature Output */
#define S50_ELS_KS4_KS4_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_FHWO_SHIFT)) & S50_ELS_KS4_KS4_FHWO_MASK)

#define S50_ELS_KS4_KS4_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS4_KS4_RSVD1_SHIFT              (10U)
/*! ks4_rsvd1 - Reserved 1 */
#define S50_ELS_KS4_KS4_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_RSVD1_SHIFT)) & S50_ELS_KS4_KS4_RSVD1_MASK)

#define S50_ELS_KS4_KS4_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS4_KS4_UCMAC_SHIFT              (13U)
/*! ks4_ucmac - CMAC key */
#define S50_ELS_KS4_KS4_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UCMAC_SHIFT)) & S50_ELS_KS4_KS4_UCMAC_MASK)

#define S50_ELS_KS4_KS4_UKSK_MASK                (0x4000U)
#define S50_ELS_KS4_KS4_UKSK_SHIFT               (14U)
/*! ks4_uksk - KSK key */
#define S50_ELS_KS4_KS4_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKSK_SHIFT)) & S50_ELS_KS4_KS4_UKSK_MASK)

#define S50_ELS_KS4_KS4_URTF_MASK                (0x8000U)
#define S50_ELS_KS4_KS4_URTF_SHIFT               (15U)
/*! ks4_urtf - Real Time Fingerprint key */
#define S50_ELS_KS4_KS4_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_URTF_SHIFT)) & S50_ELS_KS4_KS4_URTF_MASK)

#define S50_ELS_KS4_KS4_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS4_KS4_UCKDF_SHIFT              (16U)
/*! ks4_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS4_KS4_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UCKDF_SHIFT)) & S50_ELS_KS4_KS4_UCKDF_MASK)

#define S50_ELS_KS4_KS4_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS4_KS4_UHKDF_SHIFT              (17U)
/*! ks4_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS4_KS4_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHKDF_SHIFT)) & S50_ELS_KS4_KS4_UHKDF_MASK)

#define S50_ELS_KS4_KS4_UECSG_MASK               (0x40000U)
#define S50_ELS_KS4_KS4_UECSG_SHIFT              (18U)
/*! ks4_uecsg - Ecc signing key */
#define S50_ELS_KS4_KS4_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UECSG_SHIFT)) & S50_ELS_KS4_KS4_UECSG_MASK)

#define S50_ELS_KS4_KS4_UECDH_MASK               (0x80000U)
#define S50_ELS_KS4_KS4_UECDH_SHIFT              (19U)
/*! ks4_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS4_KS4_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UECDH_SHIFT)) & S50_ELS_KS4_KS4_UECDH_MASK)

#define S50_ELS_KS4_KS4_UAES_MASK                (0x100000U)
#define S50_ELS_KS4_KS4_UAES_SHIFT               (20U)
/*! ks4_uaes - Aes key */
#define S50_ELS_KS4_KS4_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UAES_SHIFT)) & S50_ELS_KS4_KS4_UAES_MASK)

#define S50_ELS_KS4_KS4_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS4_KS4_UHMAC_SHIFT              (21U)
/*! ks4_uhmac - Hmac key */
#define S50_ELS_KS4_KS4_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHMAC_SHIFT)) & S50_ELS_KS4_KS4_UHMAC_MASK)

#define S50_ELS_KS4_KS4_UKWK_MASK                (0x400000U)
#define S50_ELS_KS4_KS4_UKWK_SHIFT               (22U)
/*! ks4_ukwk - Key wrapping key */
#define S50_ELS_KS4_KS4_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKWK_SHIFT)) & S50_ELS_KS4_KS4_UKWK_MASK)

#define S50_ELS_KS4_KS4_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS4_KS4_UKUOK_SHIFT              (23U)
/*! ks4_ukuok - Key unwrapping key */
#define S50_ELS_KS4_KS4_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKUOK_SHIFT)) & S50_ELS_KS4_KS4_UKUOK_MASK)

#define S50_ELS_KS4_KS4_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS4_KS4_UTLSPMS_SHIFT            (24U)
/*! ks4_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS4_KS4_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UTLSPMS_SHIFT)) & S50_ELS_KS4_KS4_UTLSPMS_MASK)

#define S50_ELS_KS4_KS4_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS4_KS4_UTLSMS_SHIFT             (25U)
/*! ks4_utlsms - TLS Master Secret */
#define S50_ELS_KS4_KS4_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UTLSMS_SHIFT)) & S50_ELS_KS4_KS4_UTLSMS_MASK)

#define S50_ELS_KS4_KS4_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS4_KS4_UKGSRC_SHIFT             (26U)
/*! ks4_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS4_KS4_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UKGSRC_SHIFT)) & S50_ELS_KS4_KS4_UKGSRC_MASK)

#define S50_ELS_KS4_KS4_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS4_KS4_UHWO_SHIFT               (27U)
/*! ks4_uhwo - Hardware out key */
#define S50_ELS_KS4_KS4_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UHWO_SHIFT)) & S50_ELS_KS4_KS4_UHWO_MASK)

#define S50_ELS_KS4_KS4_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS4_KS4_UWRPOK_SHIFT             (28U)
/*! ks4_uwrpok - Ok to wrap key */
#define S50_ELS_KS4_KS4_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UWRPOK_SHIFT)) & S50_ELS_KS4_KS4_UWRPOK_MASK)

#define S50_ELS_KS4_KS4_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS4_KS4_UDUK_SHIFT               (29U)
/*! ks4_uduk - Device Unique Key */
#define S50_ELS_KS4_KS4_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UDUK_SHIFT)) & S50_ELS_KS4_KS4_UDUK_MASK)

#define S50_ELS_KS4_KS4_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS4_KS4_UPPROT_SHIFT             (30U)
/*! ks4_upprot - Priviledge level */
#define S50_ELS_KS4_KS4_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS4_KS4_UPPROT_SHIFT)) & S50_ELS_KS4_KS4_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS5 - Status register */
/*! @{ */

#define S50_ELS_KS5_KS5_KSIZE_MASK               (0x1U)
#define S50_ELS_KS5_KS5_KSIZE_SHIFT              (0U)
/*! ks5_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS5_KS5_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KSIZE_SHIFT)) & S50_ELS_KS5_KS5_KSIZE_MASK)

#define S50_ELS_KS5_KS5_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS5_KS5_RSVD0_SHIFT              (1U)
/*! ks5_rsvd0 - Reserved 0 */
#define S50_ELS_KS5_KS5_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_RSVD0_SHIFT)) & S50_ELS_KS5_KS5_RSVD0_MASK)

#define S50_ELS_KS5_KS5_KACT_MASK                (0x20U)
#define S50_ELS_KS5_KS5_KACT_SHIFT               (5U)
/*! ks5_kact - Key is active */
#define S50_ELS_KS5_KS5_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KACT_SHIFT)) & S50_ELS_KS5_KS5_KACT_MASK)

#define S50_ELS_KS5_KS5_KBASE_MASK               (0x40U)
#define S50_ELS_KS5_KS5_KBASE_SHIFT              (6U)
/*! ks5_kbase - First slot in a multislot key */
#define S50_ELS_KS5_KS5_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_KBASE_SHIFT)) & S50_ELS_KS5_KS5_KBASE_MASK)

#define S50_ELS_KS5_KS5_FGP_MASK                 (0x80U)
#define S50_ELS_KS5_KS5_FGP_SHIFT                (7U)
/*! ks5_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS5_KS5_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FGP_SHIFT)) & S50_ELS_KS5_KS5_FGP_MASK)

#define S50_ELS_KS5_KS5_FRTN_MASK                (0x100U)
#define S50_ELS_KS5_KS5_FRTN_SHIFT               (8U)
/*! ks5_frtn - Hardware Feature Retention */
#define S50_ELS_KS5_KS5_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FRTN_SHIFT)) & S50_ELS_KS5_KS5_FRTN_MASK)

#define S50_ELS_KS5_KS5_FHWO_MASK                (0x200U)
#define S50_ELS_KS5_KS5_FHWO_SHIFT               (9U)
/*! ks5_fhwo - Hardware Feature Output */
#define S50_ELS_KS5_KS5_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_FHWO_SHIFT)) & S50_ELS_KS5_KS5_FHWO_MASK)

#define S50_ELS_KS5_KS5_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS5_KS5_RSVD1_SHIFT              (10U)
/*! ks5_rsvd1 - Reserved 1 */
#define S50_ELS_KS5_KS5_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_RSVD1_SHIFT)) & S50_ELS_KS5_KS5_RSVD1_MASK)

#define S50_ELS_KS5_KS5_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS5_KS5_UCMAC_SHIFT              (13U)
/*! ks5_ucmac - CMAC key */
#define S50_ELS_KS5_KS5_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UCMAC_SHIFT)) & S50_ELS_KS5_KS5_UCMAC_MASK)

#define S50_ELS_KS5_KS5_UKSK_MASK                (0x4000U)
#define S50_ELS_KS5_KS5_UKSK_SHIFT               (14U)
/*! ks5_uksk - KSK key */
#define S50_ELS_KS5_KS5_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKSK_SHIFT)) & S50_ELS_KS5_KS5_UKSK_MASK)

#define S50_ELS_KS5_KS5_URTF_MASK                (0x8000U)
#define S50_ELS_KS5_KS5_URTF_SHIFT               (15U)
/*! ks5_urtf - Real Time Fingerprint key */
#define S50_ELS_KS5_KS5_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_URTF_SHIFT)) & S50_ELS_KS5_KS5_URTF_MASK)

#define S50_ELS_KS5_KS5_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS5_KS5_UCKDF_SHIFT              (16U)
/*! ks5_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS5_KS5_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UCKDF_SHIFT)) & S50_ELS_KS5_KS5_UCKDF_MASK)

#define S50_ELS_KS5_KS5_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS5_KS5_UHKDF_SHIFT              (17U)
/*! ks5_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS5_KS5_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHKDF_SHIFT)) & S50_ELS_KS5_KS5_UHKDF_MASK)

#define S50_ELS_KS5_KS5_UECSG_MASK               (0x40000U)
#define S50_ELS_KS5_KS5_UECSG_SHIFT              (18U)
/*! ks5_uecsg - Ecc signing key */
#define S50_ELS_KS5_KS5_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UECSG_SHIFT)) & S50_ELS_KS5_KS5_UECSG_MASK)

#define S50_ELS_KS5_KS5_UECDH_MASK               (0x80000U)
#define S50_ELS_KS5_KS5_UECDH_SHIFT              (19U)
/*! ks5_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS5_KS5_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UECDH_SHIFT)) & S50_ELS_KS5_KS5_UECDH_MASK)

#define S50_ELS_KS5_KS5_UAES_MASK                (0x100000U)
#define S50_ELS_KS5_KS5_UAES_SHIFT               (20U)
/*! ks5_uaes - Aes key */
#define S50_ELS_KS5_KS5_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UAES_SHIFT)) & S50_ELS_KS5_KS5_UAES_MASK)

#define S50_ELS_KS5_KS5_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS5_KS5_UHMAC_SHIFT              (21U)
/*! ks5_uhmac - Hmac key */
#define S50_ELS_KS5_KS5_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHMAC_SHIFT)) & S50_ELS_KS5_KS5_UHMAC_MASK)

#define S50_ELS_KS5_KS5_UKWK_MASK                (0x400000U)
#define S50_ELS_KS5_KS5_UKWK_SHIFT               (22U)
/*! ks5_ukwk - Key wrapping key */
#define S50_ELS_KS5_KS5_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKWK_SHIFT)) & S50_ELS_KS5_KS5_UKWK_MASK)

#define S50_ELS_KS5_KS5_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS5_KS5_UKUOK_SHIFT              (23U)
/*! ks5_ukuok - Key unwrapping key */
#define S50_ELS_KS5_KS5_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKUOK_SHIFT)) & S50_ELS_KS5_KS5_UKUOK_MASK)

#define S50_ELS_KS5_KS5_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS5_KS5_UTLSPMS_SHIFT            (24U)
/*! ks5_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS5_KS5_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UTLSPMS_SHIFT)) & S50_ELS_KS5_KS5_UTLSPMS_MASK)

#define S50_ELS_KS5_KS5_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS5_KS5_UTLSMS_SHIFT             (25U)
/*! ks5_utlsms - TLS Master Secret */
#define S50_ELS_KS5_KS5_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UTLSMS_SHIFT)) & S50_ELS_KS5_KS5_UTLSMS_MASK)

#define S50_ELS_KS5_KS5_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS5_KS5_UKGSRC_SHIFT             (26U)
/*! ks5_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS5_KS5_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UKGSRC_SHIFT)) & S50_ELS_KS5_KS5_UKGSRC_MASK)

#define S50_ELS_KS5_KS5_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS5_KS5_UHWO_SHIFT               (27U)
/*! ks5_uhwo - Hardware out key */
#define S50_ELS_KS5_KS5_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UHWO_SHIFT)) & S50_ELS_KS5_KS5_UHWO_MASK)

#define S50_ELS_KS5_KS5_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS5_KS5_UWRPOK_SHIFT             (28U)
/*! ks5_uwrpok - Ok to wrap key */
#define S50_ELS_KS5_KS5_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UWRPOK_SHIFT)) & S50_ELS_KS5_KS5_UWRPOK_MASK)

#define S50_ELS_KS5_KS5_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS5_KS5_UDUK_SHIFT               (29U)
/*! ks5_uduk - Device Unique Key */
#define S50_ELS_KS5_KS5_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UDUK_SHIFT)) & S50_ELS_KS5_KS5_UDUK_MASK)

#define S50_ELS_KS5_KS5_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS5_KS5_UPPROT_SHIFT             (30U)
/*! ks5_upprot - Priviledge level */
#define S50_ELS_KS5_KS5_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS5_KS5_UPPROT_SHIFT)) & S50_ELS_KS5_KS5_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS6 - Status register */
/*! @{ */

#define S50_ELS_KS6_KS6_KSIZE_MASK               (0x1U)
#define S50_ELS_KS6_KS6_KSIZE_SHIFT              (0U)
/*! ks6_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS6_KS6_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KSIZE_SHIFT)) & S50_ELS_KS6_KS6_KSIZE_MASK)

#define S50_ELS_KS6_KS6_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS6_KS6_RSVD0_SHIFT              (1U)
/*! ks6_rsvd0 - Reserved 0 */
#define S50_ELS_KS6_KS6_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_RSVD0_SHIFT)) & S50_ELS_KS6_KS6_RSVD0_MASK)

#define S50_ELS_KS6_KS6_KACT_MASK                (0x20U)
#define S50_ELS_KS6_KS6_KACT_SHIFT               (5U)
/*! ks6_kact - Key is active */
#define S50_ELS_KS6_KS6_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KACT_SHIFT)) & S50_ELS_KS6_KS6_KACT_MASK)

#define S50_ELS_KS6_KS6_KBASE_MASK               (0x40U)
#define S50_ELS_KS6_KS6_KBASE_SHIFT              (6U)
/*! ks6_kbase - First slot in a multislot key */
#define S50_ELS_KS6_KS6_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_KBASE_SHIFT)) & S50_ELS_KS6_KS6_KBASE_MASK)

#define S50_ELS_KS6_KS6_FGP_MASK                 (0x80U)
#define S50_ELS_KS6_KS6_FGP_SHIFT                (7U)
/*! ks6_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS6_KS6_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FGP_SHIFT)) & S50_ELS_KS6_KS6_FGP_MASK)

#define S50_ELS_KS6_KS6_FRTN_MASK                (0x100U)
#define S50_ELS_KS6_KS6_FRTN_SHIFT               (8U)
/*! ks6_frtn - Hardware Feature Retention */
#define S50_ELS_KS6_KS6_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FRTN_SHIFT)) & S50_ELS_KS6_KS6_FRTN_MASK)

#define S50_ELS_KS6_KS6_FHWO_MASK                (0x200U)
#define S50_ELS_KS6_KS6_FHWO_SHIFT               (9U)
/*! ks6_fhwo - Hardware Feature Output */
#define S50_ELS_KS6_KS6_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_FHWO_SHIFT)) & S50_ELS_KS6_KS6_FHWO_MASK)

#define S50_ELS_KS6_KS6_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS6_KS6_RSVD1_SHIFT              (10U)
/*! ks6_rsvd1 - Reserved 1 */
#define S50_ELS_KS6_KS6_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_RSVD1_SHIFT)) & S50_ELS_KS6_KS6_RSVD1_MASK)

#define S50_ELS_KS6_KS6_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS6_KS6_UCMAC_SHIFT              (13U)
/*! ks6_ucmac - CMAC key */
#define S50_ELS_KS6_KS6_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UCMAC_SHIFT)) & S50_ELS_KS6_KS6_UCMAC_MASK)

#define S50_ELS_KS6_KS6_UKSK_MASK                (0x4000U)
#define S50_ELS_KS6_KS6_UKSK_SHIFT               (14U)
/*! ks6_uksk - KSK key */
#define S50_ELS_KS6_KS6_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKSK_SHIFT)) & S50_ELS_KS6_KS6_UKSK_MASK)

#define S50_ELS_KS6_KS6_URTF_MASK                (0x8000U)
#define S50_ELS_KS6_KS6_URTF_SHIFT               (15U)
/*! ks6_urtf - Real Time Fingerprint key */
#define S50_ELS_KS6_KS6_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_URTF_SHIFT)) & S50_ELS_KS6_KS6_URTF_MASK)

#define S50_ELS_KS6_KS6_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS6_KS6_UCKDF_SHIFT              (16U)
/*! ks6_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS6_KS6_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UCKDF_SHIFT)) & S50_ELS_KS6_KS6_UCKDF_MASK)

#define S50_ELS_KS6_KS6_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS6_KS6_UHKDF_SHIFT              (17U)
/*! ks6_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS6_KS6_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHKDF_SHIFT)) & S50_ELS_KS6_KS6_UHKDF_MASK)

#define S50_ELS_KS6_KS6_UECSG_MASK               (0x40000U)
#define S50_ELS_KS6_KS6_UECSG_SHIFT              (18U)
/*! ks6_uecsg - Ecc signing key */
#define S50_ELS_KS6_KS6_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UECSG_SHIFT)) & S50_ELS_KS6_KS6_UECSG_MASK)

#define S50_ELS_KS6_KS6_UECDH_MASK               (0x80000U)
#define S50_ELS_KS6_KS6_UECDH_SHIFT              (19U)
/*! ks6_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS6_KS6_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UECDH_SHIFT)) & S50_ELS_KS6_KS6_UECDH_MASK)

#define S50_ELS_KS6_KS6_UAES_MASK                (0x100000U)
#define S50_ELS_KS6_KS6_UAES_SHIFT               (20U)
/*! ks6_uaes - Aes key */
#define S50_ELS_KS6_KS6_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UAES_SHIFT)) & S50_ELS_KS6_KS6_UAES_MASK)

#define S50_ELS_KS6_KS6_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS6_KS6_UHMAC_SHIFT              (21U)
/*! ks6_uhmac - Hmac key */
#define S50_ELS_KS6_KS6_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHMAC_SHIFT)) & S50_ELS_KS6_KS6_UHMAC_MASK)

#define S50_ELS_KS6_KS6_UKWK_MASK                (0x400000U)
#define S50_ELS_KS6_KS6_UKWK_SHIFT               (22U)
/*! ks6_ukwk - Key wrapping key */
#define S50_ELS_KS6_KS6_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKWK_SHIFT)) & S50_ELS_KS6_KS6_UKWK_MASK)

#define S50_ELS_KS6_KS6_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS6_KS6_UKUOK_SHIFT              (23U)
/*! ks6_ukuok - Key unwrapping key */
#define S50_ELS_KS6_KS6_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKUOK_SHIFT)) & S50_ELS_KS6_KS6_UKUOK_MASK)

#define S50_ELS_KS6_KS6_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS6_KS6_UTLSPMS_SHIFT            (24U)
/*! ks6_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS6_KS6_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UTLSPMS_SHIFT)) & S50_ELS_KS6_KS6_UTLSPMS_MASK)

#define S50_ELS_KS6_KS6_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS6_KS6_UTLSMS_SHIFT             (25U)
/*! ks6_utlsms - TLS Master Secret */
#define S50_ELS_KS6_KS6_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UTLSMS_SHIFT)) & S50_ELS_KS6_KS6_UTLSMS_MASK)

#define S50_ELS_KS6_KS6_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS6_KS6_UKGSRC_SHIFT             (26U)
/*! ks6_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS6_KS6_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UKGSRC_SHIFT)) & S50_ELS_KS6_KS6_UKGSRC_MASK)

#define S50_ELS_KS6_KS6_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS6_KS6_UHWO_SHIFT               (27U)
/*! ks6_uhwo - Hardware out key */
#define S50_ELS_KS6_KS6_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UHWO_SHIFT)) & S50_ELS_KS6_KS6_UHWO_MASK)

#define S50_ELS_KS6_KS6_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS6_KS6_UWRPOK_SHIFT             (28U)
/*! ks6_uwrpok - Ok to wrap key */
#define S50_ELS_KS6_KS6_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UWRPOK_SHIFT)) & S50_ELS_KS6_KS6_UWRPOK_MASK)

#define S50_ELS_KS6_KS6_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS6_KS6_UDUK_SHIFT               (29U)
/*! ks6_uduk - Device Unique Key */
#define S50_ELS_KS6_KS6_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UDUK_SHIFT)) & S50_ELS_KS6_KS6_UDUK_MASK)

#define S50_ELS_KS6_KS6_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS6_KS6_UPPROT_SHIFT             (30U)
/*! ks6_upprot - Priviledge level */
#define S50_ELS_KS6_KS6_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS6_KS6_UPPROT_SHIFT)) & S50_ELS_KS6_KS6_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS7 - Status register */
/*! @{ */

#define S50_ELS_KS7_KS7_KSIZE_MASK               (0x1U)
#define S50_ELS_KS7_KS7_KSIZE_SHIFT              (0U)
/*! ks7_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS7_KS7_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KSIZE_SHIFT)) & S50_ELS_KS7_KS7_KSIZE_MASK)

#define S50_ELS_KS7_KS7_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS7_KS7_RSVD0_SHIFT              (1U)
/*! ks7_rsvd0 - Reserved 0 */
#define S50_ELS_KS7_KS7_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_RSVD0_SHIFT)) & S50_ELS_KS7_KS7_RSVD0_MASK)

#define S50_ELS_KS7_KS7_KACT_MASK                (0x20U)
#define S50_ELS_KS7_KS7_KACT_SHIFT               (5U)
/*! ks7_kact - Key is active */
#define S50_ELS_KS7_KS7_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KACT_SHIFT)) & S50_ELS_KS7_KS7_KACT_MASK)

#define S50_ELS_KS7_KS7_KBASE_MASK               (0x40U)
#define S50_ELS_KS7_KS7_KBASE_SHIFT              (6U)
/*! ks7_kbase - First slot in a multislot key */
#define S50_ELS_KS7_KS7_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_KBASE_SHIFT)) & S50_ELS_KS7_KS7_KBASE_MASK)

#define S50_ELS_KS7_KS7_FGP_MASK                 (0x80U)
#define S50_ELS_KS7_KS7_FGP_SHIFT                (7U)
/*! ks7_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS7_KS7_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FGP_SHIFT)) & S50_ELS_KS7_KS7_FGP_MASK)

#define S50_ELS_KS7_KS7_FRTN_MASK                (0x100U)
#define S50_ELS_KS7_KS7_FRTN_SHIFT               (8U)
/*! ks7_frtn - Hardware Feature Retention */
#define S50_ELS_KS7_KS7_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FRTN_SHIFT)) & S50_ELS_KS7_KS7_FRTN_MASK)

#define S50_ELS_KS7_KS7_FHWO_MASK                (0x200U)
#define S50_ELS_KS7_KS7_FHWO_SHIFT               (9U)
/*! ks7_fhwo - Hardware Feature Output */
#define S50_ELS_KS7_KS7_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_FHWO_SHIFT)) & S50_ELS_KS7_KS7_FHWO_MASK)

#define S50_ELS_KS7_KS7_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS7_KS7_RSVD1_SHIFT              (10U)
/*! ks7_rsvd1 - Reserved 1 */
#define S50_ELS_KS7_KS7_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_RSVD1_SHIFT)) & S50_ELS_KS7_KS7_RSVD1_MASK)

#define S50_ELS_KS7_KS7_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS7_KS7_UCMAC_SHIFT              (13U)
/*! ks7_ucmac - CMAC key */
#define S50_ELS_KS7_KS7_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UCMAC_SHIFT)) & S50_ELS_KS7_KS7_UCMAC_MASK)

#define S50_ELS_KS7_KS7_UKSK_MASK                (0x4000U)
#define S50_ELS_KS7_KS7_UKSK_SHIFT               (14U)
/*! ks7_uksk - KSK key */
#define S50_ELS_KS7_KS7_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKSK_SHIFT)) & S50_ELS_KS7_KS7_UKSK_MASK)

#define S50_ELS_KS7_KS7_URTF_MASK                (0x8000U)
#define S50_ELS_KS7_KS7_URTF_SHIFT               (15U)
/*! ks7_urtf - Real Time Fingerprint key */
#define S50_ELS_KS7_KS7_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_URTF_SHIFT)) & S50_ELS_KS7_KS7_URTF_MASK)

#define S50_ELS_KS7_KS7_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS7_KS7_UCKDF_SHIFT              (16U)
/*! ks7_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS7_KS7_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UCKDF_SHIFT)) & S50_ELS_KS7_KS7_UCKDF_MASK)

#define S50_ELS_KS7_KS7_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS7_KS7_UHKDF_SHIFT              (17U)
/*! ks7_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS7_KS7_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHKDF_SHIFT)) & S50_ELS_KS7_KS7_UHKDF_MASK)

#define S50_ELS_KS7_KS7_UECSG_MASK               (0x40000U)
#define S50_ELS_KS7_KS7_UECSG_SHIFT              (18U)
/*! ks7_uecsg - Ecc signing key */
#define S50_ELS_KS7_KS7_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UECSG_SHIFT)) & S50_ELS_KS7_KS7_UECSG_MASK)

#define S50_ELS_KS7_KS7_UECDH_MASK               (0x80000U)
#define S50_ELS_KS7_KS7_UECDH_SHIFT              (19U)
/*! ks7_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS7_KS7_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UECDH_SHIFT)) & S50_ELS_KS7_KS7_UECDH_MASK)

#define S50_ELS_KS7_KS7_UAES_MASK                (0x100000U)
#define S50_ELS_KS7_KS7_UAES_SHIFT               (20U)
/*! ks7_uaes - Aes key */
#define S50_ELS_KS7_KS7_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UAES_SHIFT)) & S50_ELS_KS7_KS7_UAES_MASK)

#define S50_ELS_KS7_KS7_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS7_KS7_UHMAC_SHIFT              (21U)
/*! ks7_uhmac - Hmac key */
#define S50_ELS_KS7_KS7_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHMAC_SHIFT)) & S50_ELS_KS7_KS7_UHMAC_MASK)

#define S50_ELS_KS7_KS7_UKWK_MASK                (0x400000U)
#define S50_ELS_KS7_KS7_UKWK_SHIFT               (22U)
/*! ks7_ukwk - Key wrapping key */
#define S50_ELS_KS7_KS7_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKWK_SHIFT)) & S50_ELS_KS7_KS7_UKWK_MASK)

#define S50_ELS_KS7_KS7_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS7_KS7_UKUOK_SHIFT              (23U)
/*! ks7_ukuok - Key unwrapping key */
#define S50_ELS_KS7_KS7_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKUOK_SHIFT)) & S50_ELS_KS7_KS7_UKUOK_MASK)

#define S50_ELS_KS7_KS7_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS7_KS7_UTLSPMS_SHIFT            (24U)
/*! ks7_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS7_KS7_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UTLSPMS_SHIFT)) & S50_ELS_KS7_KS7_UTLSPMS_MASK)

#define S50_ELS_KS7_KS7_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS7_KS7_UTLSMS_SHIFT             (25U)
/*! ks7_utlsms - TLS Master Secret */
#define S50_ELS_KS7_KS7_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UTLSMS_SHIFT)) & S50_ELS_KS7_KS7_UTLSMS_MASK)

#define S50_ELS_KS7_KS7_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS7_KS7_UKGSRC_SHIFT             (26U)
/*! ks7_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS7_KS7_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UKGSRC_SHIFT)) & S50_ELS_KS7_KS7_UKGSRC_MASK)

#define S50_ELS_KS7_KS7_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS7_KS7_UHWO_SHIFT               (27U)
/*! ks7_uhwo - Hardware out key */
#define S50_ELS_KS7_KS7_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UHWO_SHIFT)) & S50_ELS_KS7_KS7_UHWO_MASK)

#define S50_ELS_KS7_KS7_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS7_KS7_UWRPOK_SHIFT             (28U)
/*! ks7_uwrpok - Ok to wrap key */
#define S50_ELS_KS7_KS7_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UWRPOK_SHIFT)) & S50_ELS_KS7_KS7_UWRPOK_MASK)

#define S50_ELS_KS7_KS7_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS7_KS7_UDUK_SHIFT               (29U)
/*! ks7_uduk - Device Unique Key */
#define S50_ELS_KS7_KS7_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UDUK_SHIFT)) & S50_ELS_KS7_KS7_UDUK_MASK)

#define S50_ELS_KS7_KS7_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS7_KS7_UPPROT_SHIFT             (30U)
/*! ks7_upprot - Priviledge level */
#define S50_ELS_KS7_KS7_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS7_KS7_UPPROT_SHIFT)) & S50_ELS_KS7_KS7_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS8 - Status register */
/*! @{ */

#define S50_ELS_KS8_KS8_KSIZE_MASK               (0x1U)
#define S50_ELS_KS8_KS8_KSIZE_SHIFT              (0U)
/*! ks8_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS8_KS8_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KSIZE_SHIFT)) & S50_ELS_KS8_KS8_KSIZE_MASK)

#define S50_ELS_KS8_KS8_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS8_KS8_RSVD0_SHIFT              (1U)
/*! ks8_rsvd0 - Reserved 0 */
#define S50_ELS_KS8_KS8_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_RSVD0_SHIFT)) & S50_ELS_KS8_KS8_RSVD0_MASK)

#define S50_ELS_KS8_KS8_KACT_MASK                (0x20U)
#define S50_ELS_KS8_KS8_KACT_SHIFT               (5U)
/*! ks8_kact - Key is active */
#define S50_ELS_KS8_KS8_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KACT_SHIFT)) & S50_ELS_KS8_KS8_KACT_MASK)

#define S50_ELS_KS8_KS8_KBASE_MASK               (0x40U)
#define S50_ELS_KS8_KS8_KBASE_SHIFT              (6U)
/*! ks8_kbase - First slot in a multislot key */
#define S50_ELS_KS8_KS8_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_KBASE_SHIFT)) & S50_ELS_KS8_KS8_KBASE_MASK)

#define S50_ELS_KS8_KS8_FGP_MASK                 (0x80U)
#define S50_ELS_KS8_KS8_FGP_SHIFT                (7U)
/*! ks8_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS8_KS8_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FGP_SHIFT)) & S50_ELS_KS8_KS8_FGP_MASK)

#define S50_ELS_KS8_KS8_FRTN_MASK                (0x100U)
#define S50_ELS_KS8_KS8_FRTN_SHIFT               (8U)
/*! ks8_frtn - Hardware Feature Retention */
#define S50_ELS_KS8_KS8_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FRTN_SHIFT)) & S50_ELS_KS8_KS8_FRTN_MASK)

#define S50_ELS_KS8_KS8_FHWO_MASK                (0x200U)
#define S50_ELS_KS8_KS8_FHWO_SHIFT               (9U)
/*! ks8_fhwo - Hardware Feature Output */
#define S50_ELS_KS8_KS8_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_FHWO_SHIFT)) & S50_ELS_KS8_KS8_FHWO_MASK)

#define S50_ELS_KS8_KS8_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS8_KS8_RSVD1_SHIFT              (10U)
/*! ks8_rsvd1 - Reserved 1 */
#define S50_ELS_KS8_KS8_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_RSVD1_SHIFT)) & S50_ELS_KS8_KS8_RSVD1_MASK)

#define S50_ELS_KS8_KS8_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS8_KS8_UCMAC_SHIFT              (13U)
/*! ks8_ucmac - CMAC key */
#define S50_ELS_KS8_KS8_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UCMAC_SHIFT)) & S50_ELS_KS8_KS8_UCMAC_MASK)

#define S50_ELS_KS8_KS8_UKSK_MASK                (0x4000U)
#define S50_ELS_KS8_KS8_UKSK_SHIFT               (14U)
/*! ks8_uksk - KSK key */
#define S50_ELS_KS8_KS8_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKSK_SHIFT)) & S50_ELS_KS8_KS8_UKSK_MASK)

#define S50_ELS_KS8_KS8_URTF_MASK                (0x8000U)
#define S50_ELS_KS8_KS8_URTF_SHIFT               (15U)
/*! ks8_urtf - Real Time Fingerprint key */
#define S50_ELS_KS8_KS8_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_URTF_SHIFT)) & S50_ELS_KS8_KS8_URTF_MASK)

#define S50_ELS_KS8_KS8_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS8_KS8_UCKDF_SHIFT              (16U)
/*! ks8_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS8_KS8_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UCKDF_SHIFT)) & S50_ELS_KS8_KS8_UCKDF_MASK)

#define S50_ELS_KS8_KS8_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS8_KS8_UHKDF_SHIFT              (17U)
/*! ks8_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS8_KS8_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHKDF_SHIFT)) & S50_ELS_KS8_KS8_UHKDF_MASK)

#define S50_ELS_KS8_KS8_UECSG_MASK               (0x40000U)
#define S50_ELS_KS8_KS8_UECSG_SHIFT              (18U)
/*! ks8_uecsg - Ecc signing key */
#define S50_ELS_KS8_KS8_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UECSG_SHIFT)) & S50_ELS_KS8_KS8_UECSG_MASK)

#define S50_ELS_KS8_KS8_UECDH_MASK               (0x80000U)
#define S50_ELS_KS8_KS8_UECDH_SHIFT              (19U)
/*! ks8_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS8_KS8_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UECDH_SHIFT)) & S50_ELS_KS8_KS8_UECDH_MASK)

#define S50_ELS_KS8_KS8_UAES_MASK                (0x100000U)
#define S50_ELS_KS8_KS8_UAES_SHIFT               (20U)
/*! ks8_uaes - Aes key */
#define S50_ELS_KS8_KS8_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UAES_SHIFT)) & S50_ELS_KS8_KS8_UAES_MASK)

#define S50_ELS_KS8_KS8_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS8_KS8_UHMAC_SHIFT              (21U)
/*! ks8_uhmac - Hmac key */
#define S50_ELS_KS8_KS8_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHMAC_SHIFT)) & S50_ELS_KS8_KS8_UHMAC_MASK)

#define S50_ELS_KS8_KS8_UKWK_MASK                (0x400000U)
#define S50_ELS_KS8_KS8_UKWK_SHIFT               (22U)
/*! ks8_ukwk - Key wrapping key */
#define S50_ELS_KS8_KS8_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKWK_SHIFT)) & S50_ELS_KS8_KS8_UKWK_MASK)

#define S50_ELS_KS8_KS8_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS8_KS8_UKUOK_SHIFT              (23U)
/*! ks8_ukuok - Key unwrapping key */
#define S50_ELS_KS8_KS8_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKUOK_SHIFT)) & S50_ELS_KS8_KS8_UKUOK_MASK)

#define S50_ELS_KS8_KS8_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS8_KS8_UTLSPMS_SHIFT            (24U)
/*! ks8_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS8_KS8_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UTLSPMS_SHIFT)) & S50_ELS_KS8_KS8_UTLSPMS_MASK)

#define S50_ELS_KS8_KS8_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS8_KS8_UTLSMS_SHIFT             (25U)
/*! ks8_utlsms - TLS Master Secret */
#define S50_ELS_KS8_KS8_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UTLSMS_SHIFT)) & S50_ELS_KS8_KS8_UTLSMS_MASK)

#define S50_ELS_KS8_KS8_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS8_KS8_UKGSRC_SHIFT             (26U)
/*! ks8_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS8_KS8_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UKGSRC_SHIFT)) & S50_ELS_KS8_KS8_UKGSRC_MASK)

#define S50_ELS_KS8_KS8_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS8_KS8_UHWO_SHIFT               (27U)
/*! ks8_uhwo - Hardware out key */
#define S50_ELS_KS8_KS8_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UHWO_SHIFT)) & S50_ELS_KS8_KS8_UHWO_MASK)

#define S50_ELS_KS8_KS8_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS8_KS8_UWRPOK_SHIFT             (28U)
/*! ks8_uwrpok - Ok to wrap key */
#define S50_ELS_KS8_KS8_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UWRPOK_SHIFT)) & S50_ELS_KS8_KS8_UWRPOK_MASK)

#define S50_ELS_KS8_KS8_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS8_KS8_UDUK_SHIFT               (29U)
/*! ks8_uduk - Device Unique Key */
#define S50_ELS_KS8_KS8_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UDUK_SHIFT)) & S50_ELS_KS8_KS8_UDUK_MASK)

#define S50_ELS_KS8_KS8_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS8_KS8_UPPROT_SHIFT             (30U)
/*! ks8_upprot - Priviledge level */
#define S50_ELS_KS8_KS8_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS8_KS8_UPPROT_SHIFT)) & S50_ELS_KS8_KS8_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS9 - Status register */
/*! @{ */

#define S50_ELS_KS9_KS9_KSIZE_MASK               (0x1U)
#define S50_ELS_KS9_KS9_KSIZE_SHIFT              (0U)
/*! ks9_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS9_KS9_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KSIZE_SHIFT)) & S50_ELS_KS9_KS9_KSIZE_MASK)

#define S50_ELS_KS9_KS9_RSVD0_MASK               (0x1EU)
#define S50_ELS_KS9_KS9_RSVD0_SHIFT              (1U)
/*! ks9_rsvd0 - Reserved 0 */
#define S50_ELS_KS9_KS9_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_RSVD0_SHIFT)) & S50_ELS_KS9_KS9_RSVD0_MASK)

#define S50_ELS_KS9_KS9_KACT_MASK                (0x20U)
#define S50_ELS_KS9_KS9_KACT_SHIFT               (5U)
/*! ks9_kact - Key is active */
#define S50_ELS_KS9_KS9_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KACT_SHIFT)) & S50_ELS_KS9_KS9_KACT_MASK)

#define S50_ELS_KS9_KS9_KBASE_MASK               (0x40U)
#define S50_ELS_KS9_KS9_KBASE_SHIFT              (6U)
/*! ks9_kbase - First slot in a multislot key */
#define S50_ELS_KS9_KS9_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_KBASE_SHIFT)) & S50_ELS_KS9_KS9_KBASE_MASK)

#define S50_ELS_KS9_KS9_FGP_MASK                 (0x80U)
#define S50_ELS_KS9_KS9_FGP_SHIFT                (7U)
/*! ks9_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS9_KS9_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FGP_SHIFT)) & S50_ELS_KS9_KS9_FGP_MASK)

#define S50_ELS_KS9_KS9_FRTN_MASK                (0x100U)
#define S50_ELS_KS9_KS9_FRTN_SHIFT               (8U)
/*! ks9_frtn - Hardware Feature Retention */
#define S50_ELS_KS9_KS9_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FRTN_SHIFT)) & S50_ELS_KS9_KS9_FRTN_MASK)

#define S50_ELS_KS9_KS9_FHWO_MASK                (0x200U)
#define S50_ELS_KS9_KS9_FHWO_SHIFT               (9U)
/*! ks9_fhwo - Hardware Feature Output */
#define S50_ELS_KS9_KS9_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_FHWO_SHIFT)) & S50_ELS_KS9_KS9_FHWO_MASK)

#define S50_ELS_KS9_KS9_RSVD1_MASK               (0x1C00U)
#define S50_ELS_KS9_KS9_RSVD1_SHIFT              (10U)
/*! ks9_rsvd1 - Reserved 1 */
#define S50_ELS_KS9_KS9_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_RSVD1_SHIFT)) & S50_ELS_KS9_KS9_RSVD1_MASK)

#define S50_ELS_KS9_KS9_UCMAC_MASK               (0x2000U)
#define S50_ELS_KS9_KS9_UCMAC_SHIFT              (13U)
/*! ks9_ucmac - CMAC key */
#define S50_ELS_KS9_KS9_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UCMAC_SHIFT)) & S50_ELS_KS9_KS9_UCMAC_MASK)

#define S50_ELS_KS9_KS9_UKSK_MASK                (0x4000U)
#define S50_ELS_KS9_KS9_UKSK_SHIFT               (14U)
/*! ks9_uksk - KSK key */
#define S50_ELS_KS9_KS9_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKSK_SHIFT)) & S50_ELS_KS9_KS9_UKSK_MASK)

#define S50_ELS_KS9_KS9_URTF_MASK                (0x8000U)
#define S50_ELS_KS9_KS9_URTF_SHIFT               (15U)
/*! ks9_urtf - Real Time Fingerprint key */
#define S50_ELS_KS9_KS9_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_URTF_SHIFT)) & S50_ELS_KS9_KS9_URTF_MASK)

#define S50_ELS_KS9_KS9_UCKDF_MASK               (0x10000U)
#define S50_ELS_KS9_KS9_UCKDF_SHIFT              (16U)
/*! ks9_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS9_KS9_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UCKDF_SHIFT)) & S50_ELS_KS9_KS9_UCKDF_MASK)

#define S50_ELS_KS9_KS9_UHKDF_MASK               (0x20000U)
#define S50_ELS_KS9_KS9_UHKDF_SHIFT              (17U)
/*! ks9_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS9_KS9_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHKDF_SHIFT)) & S50_ELS_KS9_KS9_UHKDF_MASK)

#define S50_ELS_KS9_KS9_UECSG_MASK               (0x40000U)
#define S50_ELS_KS9_KS9_UECSG_SHIFT              (18U)
/*! ks9_uecsg - Ecc signing key */
#define S50_ELS_KS9_KS9_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UECSG_SHIFT)) & S50_ELS_KS9_KS9_UECSG_MASK)

#define S50_ELS_KS9_KS9_UECDH_MASK               (0x80000U)
#define S50_ELS_KS9_KS9_UECDH_SHIFT              (19U)
/*! ks9_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS9_KS9_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UECDH_SHIFT)) & S50_ELS_KS9_KS9_UECDH_MASK)

#define S50_ELS_KS9_KS9_UAES_MASK                (0x100000U)
#define S50_ELS_KS9_KS9_UAES_SHIFT               (20U)
/*! ks9_uaes - Aes key */
#define S50_ELS_KS9_KS9_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UAES_SHIFT)) & S50_ELS_KS9_KS9_UAES_MASK)

#define S50_ELS_KS9_KS9_UHMAC_MASK               (0x200000U)
#define S50_ELS_KS9_KS9_UHMAC_SHIFT              (21U)
/*! ks9_uhmac - Hmac key */
#define S50_ELS_KS9_KS9_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHMAC_SHIFT)) & S50_ELS_KS9_KS9_UHMAC_MASK)

#define S50_ELS_KS9_KS9_UKWK_MASK                (0x400000U)
#define S50_ELS_KS9_KS9_UKWK_SHIFT               (22U)
/*! ks9_ukwk - Key wrapping key */
#define S50_ELS_KS9_KS9_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKWK_SHIFT)) & S50_ELS_KS9_KS9_UKWK_MASK)

#define S50_ELS_KS9_KS9_UKUOK_MASK               (0x800000U)
#define S50_ELS_KS9_KS9_UKUOK_SHIFT              (23U)
/*! ks9_ukuok - Key unwrapping key */
#define S50_ELS_KS9_KS9_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKUOK_SHIFT)) & S50_ELS_KS9_KS9_UKUOK_MASK)

#define S50_ELS_KS9_KS9_UTLSPMS_MASK             (0x1000000U)
#define S50_ELS_KS9_KS9_UTLSPMS_SHIFT            (24U)
/*! ks9_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS9_KS9_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UTLSPMS_SHIFT)) & S50_ELS_KS9_KS9_UTLSPMS_MASK)

#define S50_ELS_KS9_KS9_UTLSMS_MASK              (0x2000000U)
#define S50_ELS_KS9_KS9_UTLSMS_SHIFT             (25U)
/*! ks9_utlsms - TLS Master Secret */
#define S50_ELS_KS9_KS9_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UTLSMS_SHIFT)) & S50_ELS_KS9_KS9_UTLSMS_MASK)

#define S50_ELS_KS9_KS9_UKGSRC_MASK              (0x4000000U)
#define S50_ELS_KS9_KS9_UKGSRC_SHIFT             (26U)
/*! ks9_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS9_KS9_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UKGSRC_SHIFT)) & S50_ELS_KS9_KS9_UKGSRC_MASK)

#define S50_ELS_KS9_KS9_UHWO_MASK                (0x8000000U)
#define S50_ELS_KS9_KS9_UHWO_SHIFT               (27U)
/*! ks9_uhwo - Hardware out key */
#define S50_ELS_KS9_KS9_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UHWO_SHIFT)) & S50_ELS_KS9_KS9_UHWO_MASK)

#define S50_ELS_KS9_KS9_UWRPOK_MASK              (0x10000000U)
#define S50_ELS_KS9_KS9_UWRPOK_SHIFT             (28U)
/*! ks9_uwrpok - Ok to wrap key */
#define S50_ELS_KS9_KS9_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UWRPOK_SHIFT)) & S50_ELS_KS9_KS9_UWRPOK_MASK)

#define S50_ELS_KS9_KS9_UDUK_MASK                (0x20000000U)
#define S50_ELS_KS9_KS9_UDUK_SHIFT               (29U)
/*! ks9_uduk - Device Unique Key */
#define S50_ELS_KS9_KS9_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UDUK_SHIFT)) & S50_ELS_KS9_KS9_UDUK_MASK)

#define S50_ELS_KS9_KS9_UPPROT_MASK              (0xC0000000U)
#define S50_ELS_KS9_KS9_UPPROT_SHIFT             (30U)
/*! ks9_upprot - Priviledge level */
#define S50_ELS_KS9_KS9_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS9_KS9_UPPROT_SHIFT)) & S50_ELS_KS9_KS9_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS10 - Status register */
/*! @{ */

#define S50_ELS_KS10_KS10_KSIZE_MASK             (0x1U)
#define S50_ELS_KS10_KS10_KSIZE_SHIFT            (0U)
/*! ks10_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS10_KS10_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KSIZE_SHIFT)) & S50_ELS_KS10_KS10_KSIZE_MASK)

#define S50_ELS_KS10_KS10_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS10_KS10_RSVD0_SHIFT            (1U)
/*! ks10_rsvd0 - Reserved 0 */
#define S50_ELS_KS10_KS10_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_RSVD0_SHIFT)) & S50_ELS_KS10_KS10_RSVD0_MASK)

#define S50_ELS_KS10_KS10_KACT_MASK              (0x20U)
#define S50_ELS_KS10_KS10_KACT_SHIFT             (5U)
/*! ks10_kact - Key is active */
#define S50_ELS_KS10_KS10_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KACT_SHIFT)) & S50_ELS_KS10_KS10_KACT_MASK)

#define S50_ELS_KS10_KS10_KBASE_MASK             (0x40U)
#define S50_ELS_KS10_KS10_KBASE_SHIFT            (6U)
/*! ks10_kbase - First slot in a multislot key */
#define S50_ELS_KS10_KS10_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_KBASE_SHIFT)) & S50_ELS_KS10_KS10_KBASE_MASK)

#define S50_ELS_KS10_KS10_FGP_MASK               (0x80U)
#define S50_ELS_KS10_KS10_FGP_SHIFT              (7U)
/*! ks10_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS10_KS10_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FGP_SHIFT)) & S50_ELS_KS10_KS10_FGP_MASK)

#define S50_ELS_KS10_KS10_FRTN_MASK              (0x100U)
#define S50_ELS_KS10_KS10_FRTN_SHIFT             (8U)
/*! ks10_frtn - Hardware Feature Retention */
#define S50_ELS_KS10_KS10_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FRTN_SHIFT)) & S50_ELS_KS10_KS10_FRTN_MASK)

#define S50_ELS_KS10_KS10_FHWO_MASK              (0x200U)
#define S50_ELS_KS10_KS10_FHWO_SHIFT             (9U)
/*! ks10_fhwo - Hardware Feature Output */
#define S50_ELS_KS10_KS10_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_FHWO_SHIFT)) & S50_ELS_KS10_KS10_FHWO_MASK)

#define S50_ELS_KS10_KS10_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS10_KS10_RSVD1_SHIFT            (10U)
/*! ks10_rsvd1 - Reserved 1 */
#define S50_ELS_KS10_KS10_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_RSVD1_SHIFT)) & S50_ELS_KS10_KS10_RSVD1_MASK)

#define S50_ELS_KS10_KS10_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS10_KS10_UCMAC_SHIFT            (13U)
/*! ks10_ucmac - CMAC key */
#define S50_ELS_KS10_KS10_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UCMAC_SHIFT)) & S50_ELS_KS10_KS10_UCMAC_MASK)

#define S50_ELS_KS10_KS10_UKSK_MASK              (0x4000U)
#define S50_ELS_KS10_KS10_UKSK_SHIFT             (14U)
/*! ks10_uksk - KSK key */
#define S50_ELS_KS10_KS10_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKSK_SHIFT)) & S50_ELS_KS10_KS10_UKSK_MASK)

#define S50_ELS_KS10_KS10_URTF_MASK              (0x8000U)
#define S50_ELS_KS10_KS10_URTF_SHIFT             (15U)
/*! ks10_urtf - Real Time Fingerprint key */
#define S50_ELS_KS10_KS10_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_URTF_SHIFT)) & S50_ELS_KS10_KS10_URTF_MASK)

#define S50_ELS_KS10_KS10_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS10_KS10_UCKDF_SHIFT            (16U)
/*! ks10_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS10_KS10_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UCKDF_SHIFT)) & S50_ELS_KS10_KS10_UCKDF_MASK)

#define S50_ELS_KS10_KS10_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS10_KS10_UHKDF_SHIFT            (17U)
/*! ks10_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS10_KS10_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHKDF_SHIFT)) & S50_ELS_KS10_KS10_UHKDF_MASK)

#define S50_ELS_KS10_KS10_UECSG_MASK             (0x40000U)
#define S50_ELS_KS10_KS10_UECSG_SHIFT            (18U)
/*! ks10_uecsg - Ecc signing key */
#define S50_ELS_KS10_KS10_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UECSG_SHIFT)) & S50_ELS_KS10_KS10_UECSG_MASK)

#define S50_ELS_KS10_KS10_UECDH_MASK             (0x80000U)
#define S50_ELS_KS10_KS10_UECDH_SHIFT            (19U)
/*! ks10_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS10_KS10_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UECDH_SHIFT)) & S50_ELS_KS10_KS10_UECDH_MASK)

#define S50_ELS_KS10_KS10_UAES_MASK              (0x100000U)
#define S50_ELS_KS10_KS10_UAES_SHIFT             (20U)
/*! ks10_uaes - Aes key */
#define S50_ELS_KS10_KS10_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UAES_SHIFT)) & S50_ELS_KS10_KS10_UAES_MASK)

#define S50_ELS_KS10_KS10_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS10_KS10_UHMAC_SHIFT            (21U)
/*! ks10_uhmac - Hmac key */
#define S50_ELS_KS10_KS10_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHMAC_SHIFT)) & S50_ELS_KS10_KS10_UHMAC_MASK)

#define S50_ELS_KS10_KS10_UKWK_MASK              (0x400000U)
#define S50_ELS_KS10_KS10_UKWK_SHIFT             (22U)
/*! ks10_ukwk - Key wrapping key */
#define S50_ELS_KS10_KS10_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKWK_SHIFT)) & S50_ELS_KS10_KS10_UKWK_MASK)

#define S50_ELS_KS10_KS10_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS10_KS10_UKUOK_SHIFT            (23U)
/*! ks10_ukuok - Key unwrapping key */
#define S50_ELS_KS10_KS10_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKUOK_SHIFT)) & S50_ELS_KS10_KS10_UKUOK_MASK)

#define S50_ELS_KS10_KS10_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS10_KS10_UTLSPMS_SHIFT          (24U)
/*! ks10_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS10_KS10_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UTLSPMS_SHIFT)) & S50_ELS_KS10_KS10_UTLSPMS_MASK)

#define S50_ELS_KS10_KS10_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS10_KS10_UTLSMS_SHIFT           (25U)
/*! ks10_utlsms - TLS Master Secret */
#define S50_ELS_KS10_KS10_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UTLSMS_SHIFT)) & S50_ELS_KS10_KS10_UTLSMS_MASK)

#define S50_ELS_KS10_KS10_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS10_KS10_UKGSRC_SHIFT           (26U)
/*! ks10_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS10_KS10_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UKGSRC_SHIFT)) & S50_ELS_KS10_KS10_UKGSRC_MASK)

#define S50_ELS_KS10_KS10_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS10_KS10_UHWO_SHIFT             (27U)
/*! ks10_uhwo - Hardware out key */
#define S50_ELS_KS10_KS10_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UHWO_SHIFT)) & S50_ELS_KS10_KS10_UHWO_MASK)

#define S50_ELS_KS10_KS10_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS10_KS10_UWRPOK_SHIFT           (28U)
/*! ks10_uwrpok - Ok to wrap key */
#define S50_ELS_KS10_KS10_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UWRPOK_SHIFT)) & S50_ELS_KS10_KS10_UWRPOK_MASK)

#define S50_ELS_KS10_KS10_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS10_KS10_UDUK_SHIFT             (29U)
/*! ks10_uduk - Device Unique Key */
#define S50_ELS_KS10_KS10_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UDUK_SHIFT)) & S50_ELS_KS10_KS10_UDUK_MASK)

#define S50_ELS_KS10_KS10_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS10_KS10_UPPROT_SHIFT           (30U)
/*! ks10_upprot - Priviledge level */
#define S50_ELS_KS10_KS10_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS10_KS10_UPPROT_SHIFT)) & S50_ELS_KS10_KS10_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS11 - Status register */
/*! @{ */

#define S50_ELS_KS11_KS11_KSIZE_MASK             (0x1U)
#define S50_ELS_KS11_KS11_KSIZE_SHIFT            (0U)
/*! ks11_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS11_KS11_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KSIZE_SHIFT)) & S50_ELS_KS11_KS11_KSIZE_MASK)

#define S50_ELS_KS11_KS11_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS11_KS11_RSVD0_SHIFT            (1U)
/*! ks11_rsvd0 - Reserved 0 */
#define S50_ELS_KS11_KS11_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_RSVD0_SHIFT)) & S50_ELS_KS11_KS11_RSVD0_MASK)

#define S50_ELS_KS11_KS11_KACT_MASK              (0x20U)
#define S50_ELS_KS11_KS11_KACT_SHIFT             (5U)
/*! ks11_kact - Key is active */
#define S50_ELS_KS11_KS11_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KACT_SHIFT)) & S50_ELS_KS11_KS11_KACT_MASK)

#define S50_ELS_KS11_KS11_KBASE_MASK             (0x40U)
#define S50_ELS_KS11_KS11_KBASE_SHIFT            (6U)
/*! ks11_kbase - First slot in a multislot key */
#define S50_ELS_KS11_KS11_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_KBASE_SHIFT)) & S50_ELS_KS11_KS11_KBASE_MASK)

#define S50_ELS_KS11_KS11_FGP_MASK               (0x80U)
#define S50_ELS_KS11_KS11_FGP_SHIFT              (7U)
/*! ks11_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS11_KS11_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FGP_SHIFT)) & S50_ELS_KS11_KS11_FGP_MASK)

#define S50_ELS_KS11_KS11_FRTN_MASK              (0x100U)
#define S50_ELS_KS11_KS11_FRTN_SHIFT             (8U)
/*! ks11_frtn - Hardware Feature Retention */
#define S50_ELS_KS11_KS11_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FRTN_SHIFT)) & S50_ELS_KS11_KS11_FRTN_MASK)

#define S50_ELS_KS11_KS11_FHWO_MASK              (0x200U)
#define S50_ELS_KS11_KS11_FHWO_SHIFT             (9U)
/*! ks11_fhwo - Hardware Feature Output */
#define S50_ELS_KS11_KS11_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_FHWO_SHIFT)) & S50_ELS_KS11_KS11_FHWO_MASK)

#define S50_ELS_KS11_KS11_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS11_KS11_RSVD1_SHIFT            (10U)
/*! ks11_rsvd1 - Reserved 1 */
#define S50_ELS_KS11_KS11_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_RSVD1_SHIFT)) & S50_ELS_KS11_KS11_RSVD1_MASK)

#define S50_ELS_KS11_KS11_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS11_KS11_UCMAC_SHIFT            (13U)
/*! ks11_ucmac - CMAC key */
#define S50_ELS_KS11_KS11_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UCMAC_SHIFT)) & S50_ELS_KS11_KS11_UCMAC_MASK)

#define S50_ELS_KS11_KS11_UKSK_MASK              (0x4000U)
#define S50_ELS_KS11_KS11_UKSK_SHIFT             (14U)
/*! ks11_uksk - KSK key */
#define S50_ELS_KS11_KS11_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKSK_SHIFT)) & S50_ELS_KS11_KS11_UKSK_MASK)

#define S50_ELS_KS11_KS11_URTF_MASK              (0x8000U)
#define S50_ELS_KS11_KS11_URTF_SHIFT             (15U)
/*! ks11_urtf - Real Time Fingerprint key */
#define S50_ELS_KS11_KS11_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_URTF_SHIFT)) & S50_ELS_KS11_KS11_URTF_MASK)

#define S50_ELS_KS11_KS11_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS11_KS11_UCKDF_SHIFT            (16U)
/*! ks11_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS11_KS11_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UCKDF_SHIFT)) & S50_ELS_KS11_KS11_UCKDF_MASK)

#define S50_ELS_KS11_KS11_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS11_KS11_UHKDF_SHIFT            (17U)
/*! ks11_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS11_KS11_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHKDF_SHIFT)) & S50_ELS_KS11_KS11_UHKDF_MASK)

#define S50_ELS_KS11_KS11_UECSG_MASK             (0x40000U)
#define S50_ELS_KS11_KS11_UECSG_SHIFT            (18U)
/*! ks11_uecsg - Ecc signing key */
#define S50_ELS_KS11_KS11_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UECSG_SHIFT)) & S50_ELS_KS11_KS11_UECSG_MASK)

#define S50_ELS_KS11_KS11_UECDH_MASK             (0x80000U)
#define S50_ELS_KS11_KS11_UECDH_SHIFT            (19U)
/*! ks11_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS11_KS11_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UECDH_SHIFT)) & S50_ELS_KS11_KS11_UECDH_MASK)

#define S50_ELS_KS11_KS11_UAES_MASK              (0x100000U)
#define S50_ELS_KS11_KS11_UAES_SHIFT             (20U)
/*! ks11_uaes - Aes key */
#define S50_ELS_KS11_KS11_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UAES_SHIFT)) & S50_ELS_KS11_KS11_UAES_MASK)

#define S50_ELS_KS11_KS11_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS11_KS11_UHMAC_SHIFT            (21U)
/*! ks11_uhmac - Hmac key */
#define S50_ELS_KS11_KS11_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHMAC_SHIFT)) & S50_ELS_KS11_KS11_UHMAC_MASK)

#define S50_ELS_KS11_KS11_UKWK_MASK              (0x400000U)
#define S50_ELS_KS11_KS11_UKWK_SHIFT             (22U)
/*! ks11_ukwk - Key wrapping key */
#define S50_ELS_KS11_KS11_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKWK_SHIFT)) & S50_ELS_KS11_KS11_UKWK_MASK)

#define S50_ELS_KS11_KS11_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS11_KS11_UKUOK_SHIFT            (23U)
/*! ks11_ukuok - Key unwrapping key */
#define S50_ELS_KS11_KS11_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKUOK_SHIFT)) & S50_ELS_KS11_KS11_UKUOK_MASK)

#define S50_ELS_KS11_KS11_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS11_KS11_UTLSPMS_SHIFT          (24U)
/*! ks11_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS11_KS11_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UTLSPMS_SHIFT)) & S50_ELS_KS11_KS11_UTLSPMS_MASK)

#define S50_ELS_KS11_KS11_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS11_KS11_UTLSMS_SHIFT           (25U)
/*! ks11_utlsms - TLS Master Secret */
#define S50_ELS_KS11_KS11_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UTLSMS_SHIFT)) & S50_ELS_KS11_KS11_UTLSMS_MASK)

#define S50_ELS_KS11_KS11_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS11_KS11_UKGSRC_SHIFT           (26U)
/*! ks11_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS11_KS11_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UKGSRC_SHIFT)) & S50_ELS_KS11_KS11_UKGSRC_MASK)

#define S50_ELS_KS11_KS11_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS11_KS11_UHWO_SHIFT             (27U)
/*! ks11_uhwo - Hardware out key */
#define S50_ELS_KS11_KS11_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UHWO_SHIFT)) & S50_ELS_KS11_KS11_UHWO_MASK)

#define S50_ELS_KS11_KS11_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS11_KS11_UWRPOK_SHIFT           (28U)
/*! ks11_uwrpok - Ok to wrap key */
#define S50_ELS_KS11_KS11_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UWRPOK_SHIFT)) & S50_ELS_KS11_KS11_UWRPOK_MASK)

#define S50_ELS_KS11_KS11_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS11_KS11_UDUK_SHIFT             (29U)
/*! ks11_uduk - Device Unique Key */
#define S50_ELS_KS11_KS11_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UDUK_SHIFT)) & S50_ELS_KS11_KS11_UDUK_MASK)

#define S50_ELS_KS11_KS11_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS11_KS11_UPPROT_SHIFT           (30U)
/*! ks11_upprot - Priviledge level */
#define S50_ELS_KS11_KS11_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS11_KS11_UPPROT_SHIFT)) & S50_ELS_KS11_KS11_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS12 - Status register */
/*! @{ */

#define S50_ELS_KS12_KS12_KSIZE_MASK             (0x1U)
#define S50_ELS_KS12_KS12_KSIZE_SHIFT            (0U)
/*! ks12_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS12_KS12_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KSIZE_SHIFT)) & S50_ELS_KS12_KS12_KSIZE_MASK)

#define S50_ELS_KS12_KS12_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS12_KS12_RSVD0_SHIFT            (1U)
/*! ks12_rsvd0 - Reserved 0 */
#define S50_ELS_KS12_KS12_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_RSVD0_SHIFT)) & S50_ELS_KS12_KS12_RSVD0_MASK)

#define S50_ELS_KS12_KS12_KACT_MASK              (0x20U)
#define S50_ELS_KS12_KS12_KACT_SHIFT             (5U)
/*! ks12_kact - Key is active */
#define S50_ELS_KS12_KS12_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KACT_SHIFT)) & S50_ELS_KS12_KS12_KACT_MASK)

#define S50_ELS_KS12_KS12_KBASE_MASK             (0x40U)
#define S50_ELS_KS12_KS12_KBASE_SHIFT            (6U)
/*! ks12_kbase - First slot in a multislot key */
#define S50_ELS_KS12_KS12_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_KBASE_SHIFT)) & S50_ELS_KS12_KS12_KBASE_MASK)

#define S50_ELS_KS12_KS12_FGP_MASK               (0x80U)
#define S50_ELS_KS12_KS12_FGP_SHIFT              (7U)
/*! ks12_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS12_KS12_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FGP_SHIFT)) & S50_ELS_KS12_KS12_FGP_MASK)

#define S50_ELS_KS12_KS12_FRTN_MASK              (0x100U)
#define S50_ELS_KS12_KS12_FRTN_SHIFT             (8U)
/*! ks12_frtn - Hardware Feature Retention */
#define S50_ELS_KS12_KS12_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FRTN_SHIFT)) & S50_ELS_KS12_KS12_FRTN_MASK)

#define S50_ELS_KS12_KS12_FHWO_MASK              (0x200U)
#define S50_ELS_KS12_KS12_FHWO_SHIFT             (9U)
/*! ks12_fhwo - Hardware Feature Output */
#define S50_ELS_KS12_KS12_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_FHWO_SHIFT)) & S50_ELS_KS12_KS12_FHWO_MASK)

#define S50_ELS_KS12_KS12_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS12_KS12_RSVD1_SHIFT            (10U)
/*! ks12_rsvd1 - Reserved 1 */
#define S50_ELS_KS12_KS12_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_RSVD1_SHIFT)) & S50_ELS_KS12_KS12_RSVD1_MASK)

#define S50_ELS_KS12_KS12_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS12_KS12_UCMAC_SHIFT            (13U)
/*! ks12_ucmac - CMAC key */
#define S50_ELS_KS12_KS12_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UCMAC_SHIFT)) & S50_ELS_KS12_KS12_UCMAC_MASK)

#define S50_ELS_KS12_KS12_UKSK_MASK              (0x4000U)
#define S50_ELS_KS12_KS12_UKSK_SHIFT             (14U)
/*! ks12_uksk - KSK key */
#define S50_ELS_KS12_KS12_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKSK_SHIFT)) & S50_ELS_KS12_KS12_UKSK_MASK)

#define S50_ELS_KS12_KS12_URTF_MASK              (0x8000U)
#define S50_ELS_KS12_KS12_URTF_SHIFT             (15U)
/*! ks12_urtf - Real Time Fingerprint key */
#define S50_ELS_KS12_KS12_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_URTF_SHIFT)) & S50_ELS_KS12_KS12_URTF_MASK)

#define S50_ELS_KS12_KS12_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS12_KS12_UCKDF_SHIFT            (16U)
/*! ks12_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS12_KS12_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UCKDF_SHIFT)) & S50_ELS_KS12_KS12_UCKDF_MASK)

#define S50_ELS_KS12_KS12_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS12_KS12_UHKDF_SHIFT            (17U)
/*! ks12_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS12_KS12_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHKDF_SHIFT)) & S50_ELS_KS12_KS12_UHKDF_MASK)

#define S50_ELS_KS12_KS12_UECSG_MASK             (0x40000U)
#define S50_ELS_KS12_KS12_UECSG_SHIFT            (18U)
/*! ks12_uecsg - Ecc signing key */
#define S50_ELS_KS12_KS12_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UECSG_SHIFT)) & S50_ELS_KS12_KS12_UECSG_MASK)

#define S50_ELS_KS12_KS12_UECDH_MASK             (0x80000U)
#define S50_ELS_KS12_KS12_UECDH_SHIFT            (19U)
/*! ks12_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS12_KS12_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UECDH_SHIFT)) & S50_ELS_KS12_KS12_UECDH_MASK)

#define S50_ELS_KS12_KS12_UAES_MASK              (0x100000U)
#define S50_ELS_KS12_KS12_UAES_SHIFT             (20U)
/*! ks12_uaes - Aes key */
#define S50_ELS_KS12_KS12_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UAES_SHIFT)) & S50_ELS_KS12_KS12_UAES_MASK)

#define S50_ELS_KS12_KS12_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS12_KS12_UHMAC_SHIFT            (21U)
/*! ks12_uhmac - Hmac key */
#define S50_ELS_KS12_KS12_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHMAC_SHIFT)) & S50_ELS_KS12_KS12_UHMAC_MASK)

#define S50_ELS_KS12_KS12_UKWK_MASK              (0x400000U)
#define S50_ELS_KS12_KS12_UKWK_SHIFT             (22U)
/*! ks12_ukwk - Key wrapping key */
#define S50_ELS_KS12_KS12_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKWK_SHIFT)) & S50_ELS_KS12_KS12_UKWK_MASK)

#define S50_ELS_KS12_KS12_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS12_KS12_UKUOK_SHIFT            (23U)
/*! ks12_ukuok - Key unwrapping key */
#define S50_ELS_KS12_KS12_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKUOK_SHIFT)) & S50_ELS_KS12_KS12_UKUOK_MASK)

#define S50_ELS_KS12_KS12_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS12_KS12_UTLSPMS_SHIFT          (24U)
/*! ks12_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS12_KS12_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UTLSPMS_SHIFT)) & S50_ELS_KS12_KS12_UTLSPMS_MASK)

#define S50_ELS_KS12_KS12_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS12_KS12_UTLSMS_SHIFT           (25U)
/*! ks12_utlsms - TLS Master Secret */
#define S50_ELS_KS12_KS12_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UTLSMS_SHIFT)) & S50_ELS_KS12_KS12_UTLSMS_MASK)

#define S50_ELS_KS12_KS12_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS12_KS12_UKGSRC_SHIFT           (26U)
/*! ks12_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS12_KS12_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UKGSRC_SHIFT)) & S50_ELS_KS12_KS12_UKGSRC_MASK)

#define S50_ELS_KS12_KS12_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS12_KS12_UHWO_SHIFT             (27U)
/*! ks12_uhwo - Hardware out key */
#define S50_ELS_KS12_KS12_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UHWO_SHIFT)) & S50_ELS_KS12_KS12_UHWO_MASK)

#define S50_ELS_KS12_KS12_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS12_KS12_UWRPOK_SHIFT           (28U)
/*! ks12_uwrpok - Ok to wrap key */
#define S50_ELS_KS12_KS12_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UWRPOK_SHIFT)) & S50_ELS_KS12_KS12_UWRPOK_MASK)

#define S50_ELS_KS12_KS12_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS12_KS12_UDUK_SHIFT             (29U)
/*! ks12_uduk - Device Unique Key */
#define S50_ELS_KS12_KS12_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UDUK_SHIFT)) & S50_ELS_KS12_KS12_UDUK_MASK)

#define S50_ELS_KS12_KS12_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS12_KS12_UPPROT_SHIFT           (30U)
/*! ks12_upprot - Priviledge level */
#define S50_ELS_KS12_KS12_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS12_KS12_UPPROT_SHIFT)) & S50_ELS_KS12_KS12_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS13 - Status register */
/*! @{ */

#define S50_ELS_KS13_KS13_KSIZE_MASK             (0x1U)
#define S50_ELS_KS13_KS13_KSIZE_SHIFT            (0U)
/*! ks13_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS13_KS13_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KSIZE_SHIFT)) & S50_ELS_KS13_KS13_KSIZE_MASK)

#define S50_ELS_KS13_KS13_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS13_KS13_RSVD0_SHIFT            (1U)
/*! ks13_rsvd0 - Reserved 0 */
#define S50_ELS_KS13_KS13_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_RSVD0_SHIFT)) & S50_ELS_KS13_KS13_RSVD0_MASK)

#define S50_ELS_KS13_KS13_KACT_MASK              (0x20U)
#define S50_ELS_KS13_KS13_KACT_SHIFT             (5U)
/*! ks13_kact - Key is active */
#define S50_ELS_KS13_KS13_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KACT_SHIFT)) & S50_ELS_KS13_KS13_KACT_MASK)

#define S50_ELS_KS13_KS13_KBASE_MASK             (0x40U)
#define S50_ELS_KS13_KS13_KBASE_SHIFT            (6U)
/*! ks13_kbase - First slot in a multislot key */
#define S50_ELS_KS13_KS13_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_KBASE_SHIFT)) & S50_ELS_KS13_KS13_KBASE_MASK)

#define S50_ELS_KS13_KS13_FGP_MASK               (0x80U)
#define S50_ELS_KS13_KS13_FGP_SHIFT              (7U)
/*! ks13_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS13_KS13_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FGP_SHIFT)) & S50_ELS_KS13_KS13_FGP_MASK)

#define S50_ELS_KS13_KS13_FRTN_MASK              (0x100U)
#define S50_ELS_KS13_KS13_FRTN_SHIFT             (8U)
/*! ks13_frtn - Hardware Feature Retention */
#define S50_ELS_KS13_KS13_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FRTN_SHIFT)) & S50_ELS_KS13_KS13_FRTN_MASK)

#define S50_ELS_KS13_KS13_FHWO_MASK              (0x200U)
#define S50_ELS_KS13_KS13_FHWO_SHIFT             (9U)
/*! ks13_fhwo - Hardware Feature Output */
#define S50_ELS_KS13_KS13_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_FHWO_SHIFT)) & S50_ELS_KS13_KS13_FHWO_MASK)

#define S50_ELS_KS13_KS13_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS13_KS13_RSVD1_SHIFT            (10U)
/*! ks13_rsvd1 - Reserved 1 */
#define S50_ELS_KS13_KS13_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_RSVD1_SHIFT)) & S50_ELS_KS13_KS13_RSVD1_MASK)

#define S50_ELS_KS13_KS13_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS13_KS13_UCMAC_SHIFT            (13U)
/*! ks13_ucmac - CMAC key */
#define S50_ELS_KS13_KS13_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UCMAC_SHIFT)) & S50_ELS_KS13_KS13_UCMAC_MASK)

#define S50_ELS_KS13_KS13_UKSK_MASK              (0x4000U)
#define S50_ELS_KS13_KS13_UKSK_SHIFT             (14U)
/*! ks13_uksk - KSK key */
#define S50_ELS_KS13_KS13_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKSK_SHIFT)) & S50_ELS_KS13_KS13_UKSK_MASK)

#define S50_ELS_KS13_KS13_URTF_MASK              (0x8000U)
#define S50_ELS_KS13_KS13_URTF_SHIFT             (15U)
/*! ks13_urtf - Real Time Fingerprint key */
#define S50_ELS_KS13_KS13_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_URTF_SHIFT)) & S50_ELS_KS13_KS13_URTF_MASK)

#define S50_ELS_KS13_KS13_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS13_KS13_UCKDF_SHIFT            (16U)
/*! ks13_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS13_KS13_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UCKDF_SHIFT)) & S50_ELS_KS13_KS13_UCKDF_MASK)

#define S50_ELS_KS13_KS13_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS13_KS13_UHKDF_SHIFT            (17U)
/*! ks13_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS13_KS13_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHKDF_SHIFT)) & S50_ELS_KS13_KS13_UHKDF_MASK)

#define S50_ELS_KS13_KS13_UECSG_MASK             (0x40000U)
#define S50_ELS_KS13_KS13_UECSG_SHIFT            (18U)
/*! ks13_uecsg - Ecc signing key */
#define S50_ELS_KS13_KS13_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UECSG_SHIFT)) & S50_ELS_KS13_KS13_UECSG_MASK)

#define S50_ELS_KS13_KS13_UECDH_MASK             (0x80000U)
#define S50_ELS_KS13_KS13_UECDH_SHIFT            (19U)
/*! ks13_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS13_KS13_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UECDH_SHIFT)) & S50_ELS_KS13_KS13_UECDH_MASK)

#define S50_ELS_KS13_KS13_UAES_MASK              (0x100000U)
#define S50_ELS_KS13_KS13_UAES_SHIFT             (20U)
/*! ks13_uaes - Aes key */
#define S50_ELS_KS13_KS13_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UAES_SHIFT)) & S50_ELS_KS13_KS13_UAES_MASK)

#define S50_ELS_KS13_KS13_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS13_KS13_UHMAC_SHIFT            (21U)
/*! ks13_uhmac - Hmac key */
#define S50_ELS_KS13_KS13_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHMAC_SHIFT)) & S50_ELS_KS13_KS13_UHMAC_MASK)

#define S50_ELS_KS13_KS13_UKWK_MASK              (0x400000U)
#define S50_ELS_KS13_KS13_UKWK_SHIFT             (22U)
/*! ks13_ukwk - Key wrapping key */
#define S50_ELS_KS13_KS13_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKWK_SHIFT)) & S50_ELS_KS13_KS13_UKWK_MASK)

#define S50_ELS_KS13_KS13_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS13_KS13_UKUOK_SHIFT            (23U)
/*! ks13_ukuok - Key unwrapping key */
#define S50_ELS_KS13_KS13_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKUOK_SHIFT)) & S50_ELS_KS13_KS13_UKUOK_MASK)

#define S50_ELS_KS13_KS13_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS13_KS13_UTLSPMS_SHIFT          (24U)
/*! ks13_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS13_KS13_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UTLSPMS_SHIFT)) & S50_ELS_KS13_KS13_UTLSPMS_MASK)

#define S50_ELS_KS13_KS13_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS13_KS13_UTLSMS_SHIFT           (25U)
/*! ks13_utlsms - TLS Master Secret */
#define S50_ELS_KS13_KS13_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UTLSMS_SHIFT)) & S50_ELS_KS13_KS13_UTLSMS_MASK)

#define S50_ELS_KS13_KS13_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS13_KS13_UKGSRC_SHIFT           (26U)
/*! ks13_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS13_KS13_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UKGSRC_SHIFT)) & S50_ELS_KS13_KS13_UKGSRC_MASK)

#define S50_ELS_KS13_KS13_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS13_KS13_UHWO_SHIFT             (27U)
/*! ks13_uhwo - Hardware out key */
#define S50_ELS_KS13_KS13_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UHWO_SHIFT)) & S50_ELS_KS13_KS13_UHWO_MASK)

#define S50_ELS_KS13_KS13_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS13_KS13_UWRPOK_SHIFT           (28U)
/*! ks13_uwrpok - Ok to wrap key */
#define S50_ELS_KS13_KS13_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UWRPOK_SHIFT)) & S50_ELS_KS13_KS13_UWRPOK_MASK)

#define S50_ELS_KS13_KS13_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS13_KS13_UDUK_SHIFT             (29U)
/*! ks13_uduk - Device Unique Key */
#define S50_ELS_KS13_KS13_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UDUK_SHIFT)) & S50_ELS_KS13_KS13_UDUK_MASK)

#define S50_ELS_KS13_KS13_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS13_KS13_UPPROT_SHIFT           (30U)
/*! ks13_upprot - Priviledge level */
#define S50_ELS_KS13_KS13_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS13_KS13_UPPROT_SHIFT)) & S50_ELS_KS13_KS13_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS14 - Status register */
/*! @{ */

#define S50_ELS_KS14_KS14_KSIZE_MASK             (0x1U)
#define S50_ELS_KS14_KS14_KSIZE_SHIFT            (0U)
/*! ks14_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS14_KS14_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KSIZE_SHIFT)) & S50_ELS_KS14_KS14_KSIZE_MASK)

#define S50_ELS_KS14_KS14_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS14_KS14_RSVD0_SHIFT            (1U)
/*! ks14_rsvd0 - Reserved 0 */
#define S50_ELS_KS14_KS14_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_RSVD0_SHIFT)) & S50_ELS_KS14_KS14_RSVD0_MASK)

#define S50_ELS_KS14_KS14_KACT_MASK              (0x20U)
#define S50_ELS_KS14_KS14_KACT_SHIFT             (5U)
/*! ks14_kact - Key is active */
#define S50_ELS_KS14_KS14_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KACT_SHIFT)) & S50_ELS_KS14_KS14_KACT_MASK)

#define S50_ELS_KS14_KS14_KBASE_MASK             (0x40U)
#define S50_ELS_KS14_KS14_KBASE_SHIFT            (6U)
/*! ks14_kbase - First slot in a multislot key */
#define S50_ELS_KS14_KS14_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_KBASE_SHIFT)) & S50_ELS_KS14_KS14_KBASE_MASK)

#define S50_ELS_KS14_KS14_FGP_MASK               (0x80U)
#define S50_ELS_KS14_KS14_FGP_SHIFT              (7U)
/*! ks14_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS14_KS14_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FGP_SHIFT)) & S50_ELS_KS14_KS14_FGP_MASK)

#define S50_ELS_KS14_KS14_FRTN_MASK              (0x100U)
#define S50_ELS_KS14_KS14_FRTN_SHIFT             (8U)
/*! ks14_frtn - Hardware Feature Retention */
#define S50_ELS_KS14_KS14_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FRTN_SHIFT)) & S50_ELS_KS14_KS14_FRTN_MASK)

#define S50_ELS_KS14_KS14_FHWO_MASK              (0x200U)
#define S50_ELS_KS14_KS14_FHWO_SHIFT             (9U)
/*! ks14_fhwo - Hardware Feature Output */
#define S50_ELS_KS14_KS14_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_FHWO_SHIFT)) & S50_ELS_KS14_KS14_FHWO_MASK)

#define S50_ELS_KS14_KS14_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS14_KS14_RSVD1_SHIFT            (10U)
/*! ks14_rsvd1 - Reserved 1 */
#define S50_ELS_KS14_KS14_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_RSVD1_SHIFT)) & S50_ELS_KS14_KS14_RSVD1_MASK)

#define S50_ELS_KS14_KS14_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS14_KS14_UCMAC_SHIFT            (13U)
/*! ks14_ucmac - CMAC key */
#define S50_ELS_KS14_KS14_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UCMAC_SHIFT)) & S50_ELS_KS14_KS14_UCMAC_MASK)

#define S50_ELS_KS14_KS14_UKSK_MASK              (0x4000U)
#define S50_ELS_KS14_KS14_UKSK_SHIFT             (14U)
/*! ks14_uksk - KSK key */
#define S50_ELS_KS14_KS14_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKSK_SHIFT)) & S50_ELS_KS14_KS14_UKSK_MASK)

#define S50_ELS_KS14_KS14_URTF_MASK              (0x8000U)
#define S50_ELS_KS14_KS14_URTF_SHIFT             (15U)
/*! ks14_urtf - Real Time Fingerprint key */
#define S50_ELS_KS14_KS14_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_URTF_SHIFT)) & S50_ELS_KS14_KS14_URTF_MASK)

#define S50_ELS_KS14_KS14_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS14_KS14_UCKDF_SHIFT            (16U)
/*! ks14_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS14_KS14_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UCKDF_SHIFT)) & S50_ELS_KS14_KS14_UCKDF_MASK)

#define S50_ELS_KS14_KS14_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS14_KS14_UHKDF_SHIFT            (17U)
/*! ks14_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS14_KS14_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHKDF_SHIFT)) & S50_ELS_KS14_KS14_UHKDF_MASK)

#define S50_ELS_KS14_KS14_UECSG_MASK             (0x40000U)
#define S50_ELS_KS14_KS14_UECSG_SHIFT            (18U)
/*! ks14_uecsg - Ecc signing key */
#define S50_ELS_KS14_KS14_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UECSG_SHIFT)) & S50_ELS_KS14_KS14_UECSG_MASK)

#define S50_ELS_KS14_KS14_UECDH_MASK             (0x80000U)
#define S50_ELS_KS14_KS14_UECDH_SHIFT            (19U)
/*! ks14_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS14_KS14_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UECDH_SHIFT)) & S50_ELS_KS14_KS14_UECDH_MASK)

#define S50_ELS_KS14_KS14_UAES_MASK              (0x100000U)
#define S50_ELS_KS14_KS14_UAES_SHIFT             (20U)
/*! ks14_uaes - Aes key */
#define S50_ELS_KS14_KS14_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UAES_SHIFT)) & S50_ELS_KS14_KS14_UAES_MASK)

#define S50_ELS_KS14_KS14_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS14_KS14_UHMAC_SHIFT            (21U)
/*! ks14_uhmac - Hmac key */
#define S50_ELS_KS14_KS14_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHMAC_SHIFT)) & S50_ELS_KS14_KS14_UHMAC_MASK)

#define S50_ELS_KS14_KS14_UKWK_MASK              (0x400000U)
#define S50_ELS_KS14_KS14_UKWK_SHIFT             (22U)
/*! ks14_ukwk - Key wrapping key */
#define S50_ELS_KS14_KS14_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKWK_SHIFT)) & S50_ELS_KS14_KS14_UKWK_MASK)

#define S50_ELS_KS14_KS14_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS14_KS14_UKUOK_SHIFT            (23U)
/*! ks14_ukuok - Key unwrapping key */
#define S50_ELS_KS14_KS14_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKUOK_SHIFT)) & S50_ELS_KS14_KS14_UKUOK_MASK)

#define S50_ELS_KS14_KS14_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS14_KS14_UTLSPMS_SHIFT          (24U)
/*! ks14_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS14_KS14_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UTLSPMS_SHIFT)) & S50_ELS_KS14_KS14_UTLSPMS_MASK)

#define S50_ELS_KS14_KS14_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS14_KS14_UTLSMS_SHIFT           (25U)
/*! ks14_utlsms - TLS Master Secret */
#define S50_ELS_KS14_KS14_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UTLSMS_SHIFT)) & S50_ELS_KS14_KS14_UTLSMS_MASK)

#define S50_ELS_KS14_KS14_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS14_KS14_UKGSRC_SHIFT           (26U)
/*! ks14_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS14_KS14_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UKGSRC_SHIFT)) & S50_ELS_KS14_KS14_UKGSRC_MASK)

#define S50_ELS_KS14_KS14_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS14_KS14_UHWO_SHIFT             (27U)
/*! ks14_uhwo - Hardware out key */
#define S50_ELS_KS14_KS14_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UHWO_SHIFT)) & S50_ELS_KS14_KS14_UHWO_MASK)

#define S50_ELS_KS14_KS14_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS14_KS14_UWRPOK_SHIFT           (28U)
/*! ks14_uwrpok - Ok to wrap key */
#define S50_ELS_KS14_KS14_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UWRPOK_SHIFT)) & S50_ELS_KS14_KS14_UWRPOK_MASK)

#define S50_ELS_KS14_KS14_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS14_KS14_UDUK_SHIFT             (29U)
/*! ks14_uduk - Device Unique Key */
#define S50_ELS_KS14_KS14_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UDUK_SHIFT)) & S50_ELS_KS14_KS14_UDUK_MASK)

#define S50_ELS_KS14_KS14_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS14_KS14_UPPROT_SHIFT           (30U)
/*! ks14_upprot - Priviledge level */
#define S50_ELS_KS14_KS14_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS14_KS14_UPPROT_SHIFT)) & S50_ELS_KS14_KS14_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS15 - Status register */
/*! @{ */

#define S50_ELS_KS15_KS15_KSIZE_MASK             (0x1U)
#define S50_ELS_KS15_KS15_KSIZE_SHIFT            (0U)
/*! ks15_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS15_KS15_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KSIZE_SHIFT)) & S50_ELS_KS15_KS15_KSIZE_MASK)

#define S50_ELS_KS15_KS15_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS15_KS15_RSVD0_SHIFT            (1U)
/*! ks15_rsvd0 - Reserved 0 */
#define S50_ELS_KS15_KS15_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_RSVD0_SHIFT)) & S50_ELS_KS15_KS15_RSVD0_MASK)

#define S50_ELS_KS15_KS15_KACT_MASK              (0x20U)
#define S50_ELS_KS15_KS15_KACT_SHIFT             (5U)
/*! ks15_kact - Key is active */
#define S50_ELS_KS15_KS15_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KACT_SHIFT)) & S50_ELS_KS15_KS15_KACT_MASK)

#define S50_ELS_KS15_KS15_KBASE_MASK             (0x40U)
#define S50_ELS_KS15_KS15_KBASE_SHIFT            (6U)
/*! ks15_kbase - First slot in a multislot key */
#define S50_ELS_KS15_KS15_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_KBASE_SHIFT)) & S50_ELS_KS15_KS15_KBASE_MASK)

#define S50_ELS_KS15_KS15_FGP_MASK               (0x80U)
#define S50_ELS_KS15_KS15_FGP_SHIFT              (7U)
/*! ks15_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS15_KS15_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FGP_SHIFT)) & S50_ELS_KS15_KS15_FGP_MASK)

#define S50_ELS_KS15_KS15_FRTN_MASK              (0x100U)
#define S50_ELS_KS15_KS15_FRTN_SHIFT             (8U)
/*! ks15_frtn - Hardware Feature Retention */
#define S50_ELS_KS15_KS15_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FRTN_SHIFT)) & S50_ELS_KS15_KS15_FRTN_MASK)

#define S50_ELS_KS15_KS15_FHWO_MASK              (0x200U)
#define S50_ELS_KS15_KS15_FHWO_SHIFT             (9U)
/*! ks15_fhwo - Hardware Feature Output */
#define S50_ELS_KS15_KS15_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_FHWO_SHIFT)) & S50_ELS_KS15_KS15_FHWO_MASK)

#define S50_ELS_KS15_KS15_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS15_KS15_RSVD1_SHIFT            (10U)
/*! ks15_rsvd1 - Reserved 1 */
#define S50_ELS_KS15_KS15_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_RSVD1_SHIFT)) & S50_ELS_KS15_KS15_RSVD1_MASK)

#define S50_ELS_KS15_KS15_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS15_KS15_UCMAC_SHIFT            (13U)
/*! ks15_ucmac - CMAC key */
#define S50_ELS_KS15_KS15_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UCMAC_SHIFT)) & S50_ELS_KS15_KS15_UCMAC_MASK)

#define S50_ELS_KS15_KS15_UKSK_MASK              (0x4000U)
#define S50_ELS_KS15_KS15_UKSK_SHIFT             (14U)
/*! ks15_uksk - KSK key */
#define S50_ELS_KS15_KS15_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKSK_SHIFT)) & S50_ELS_KS15_KS15_UKSK_MASK)

#define S50_ELS_KS15_KS15_URTF_MASK              (0x8000U)
#define S50_ELS_KS15_KS15_URTF_SHIFT             (15U)
/*! ks15_urtf - Real Time Fingerprint key */
#define S50_ELS_KS15_KS15_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_URTF_SHIFT)) & S50_ELS_KS15_KS15_URTF_MASK)

#define S50_ELS_KS15_KS15_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS15_KS15_UCKDF_SHIFT            (16U)
/*! ks15_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS15_KS15_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UCKDF_SHIFT)) & S50_ELS_KS15_KS15_UCKDF_MASK)

#define S50_ELS_KS15_KS15_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS15_KS15_UHKDF_SHIFT            (17U)
/*! ks15_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS15_KS15_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHKDF_SHIFT)) & S50_ELS_KS15_KS15_UHKDF_MASK)

#define S50_ELS_KS15_KS15_UECSG_MASK             (0x40000U)
#define S50_ELS_KS15_KS15_UECSG_SHIFT            (18U)
/*! ks15_uecsg - Ecc signing key */
#define S50_ELS_KS15_KS15_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UECSG_SHIFT)) & S50_ELS_KS15_KS15_UECSG_MASK)

#define S50_ELS_KS15_KS15_UECDH_MASK             (0x80000U)
#define S50_ELS_KS15_KS15_UECDH_SHIFT            (19U)
/*! ks15_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS15_KS15_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UECDH_SHIFT)) & S50_ELS_KS15_KS15_UECDH_MASK)

#define S50_ELS_KS15_KS15_UAES_MASK              (0x100000U)
#define S50_ELS_KS15_KS15_UAES_SHIFT             (20U)
/*! ks15_uaes - Aes key */
#define S50_ELS_KS15_KS15_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UAES_SHIFT)) & S50_ELS_KS15_KS15_UAES_MASK)

#define S50_ELS_KS15_KS15_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS15_KS15_UHMAC_SHIFT            (21U)
/*! ks15_uhmac - Hmac key */
#define S50_ELS_KS15_KS15_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHMAC_SHIFT)) & S50_ELS_KS15_KS15_UHMAC_MASK)

#define S50_ELS_KS15_KS15_UKWK_MASK              (0x400000U)
#define S50_ELS_KS15_KS15_UKWK_SHIFT             (22U)
/*! ks15_ukwk - Key wrapping key */
#define S50_ELS_KS15_KS15_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKWK_SHIFT)) & S50_ELS_KS15_KS15_UKWK_MASK)

#define S50_ELS_KS15_KS15_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS15_KS15_UKUOK_SHIFT            (23U)
/*! ks15_ukuok - Key unwrapping key */
#define S50_ELS_KS15_KS15_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKUOK_SHIFT)) & S50_ELS_KS15_KS15_UKUOK_MASK)

#define S50_ELS_KS15_KS15_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS15_KS15_UTLSPMS_SHIFT          (24U)
/*! ks15_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS15_KS15_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UTLSPMS_SHIFT)) & S50_ELS_KS15_KS15_UTLSPMS_MASK)

#define S50_ELS_KS15_KS15_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS15_KS15_UTLSMS_SHIFT           (25U)
/*! ks15_utlsms - TLS Master Secret */
#define S50_ELS_KS15_KS15_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UTLSMS_SHIFT)) & S50_ELS_KS15_KS15_UTLSMS_MASK)

#define S50_ELS_KS15_KS15_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS15_KS15_UKGSRC_SHIFT           (26U)
/*! ks15_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS15_KS15_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UKGSRC_SHIFT)) & S50_ELS_KS15_KS15_UKGSRC_MASK)

#define S50_ELS_KS15_KS15_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS15_KS15_UHWO_SHIFT             (27U)
/*! ks15_uhwo - Hardware out key */
#define S50_ELS_KS15_KS15_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UHWO_SHIFT)) & S50_ELS_KS15_KS15_UHWO_MASK)

#define S50_ELS_KS15_KS15_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS15_KS15_UWRPOK_SHIFT           (28U)
/*! ks15_uwrpok - Ok to wrap key */
#define S50_ELS_KS15_KS15_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UWRPOK_SHIFT)) & S50_ELS_KS15_KS15_UWRPOK_MASK)

#define S50_ELS_KS15_KS15_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS15_KS15_UDUK_SHIFT             (29U)
/*! ks15_uduk - Device Unique Key */
#define S50_ELS_KS15_KS15_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UDUK_SHIFT)) & S50_ELS_KS15_KS15_UDUK_MASK)

#define S50_ELS_KS15_KS15_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS15_KS15_UPPROT_SHIFT           (30U)
/*! ks15_upprot - Priviledge level */
#define S50_ELS_KS15_KS15_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS15_KS15_UPPROT_SHIFT)) & S50_ELS_KS15_KS15_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS16 - Status register */
/*! @{ */

#define S50_ELS_KS16_KS16_KSIZE_MASK             (0x1U)
#define S50_ELS_KS16_KS16_KSIZE_SHIFT            (0U)
/*! ks16_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS16_KS16_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KSIZE_SHIFT)) & S50_ELS_KS16_KS16_KSIZE_MASK)

#define S50_ELS_KS16_KS16_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS16_KS16_RSVD0_SHIFT            (1U)
/*! ks16_rsvd0 - Reserved 0 */
#define S50_ELS_KS16_KS16_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_RSVD0_SHIFT)) & S50_ELS_KS16_KS16_RSVD0_MASK)

#define S50_ELS_KS16_KS16_KACT_MASK              (0x20U)
#define S50_ELS_KS16_KS16_KACT_SHIFT             (5U)
/*! ks16_kact - Key is active */
#define S50_ELS_KS16_KS16_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KACT_SHIFT)) & S50_ELS_KS16_KS16_KACT_MASK)

#define S50_ELS_KS16_KS16_KBASE_MASK             (0x40U)
#define S50_ELS_KS16_KS16_KBASE_SHIFT            (6U)
/*! ks16_kbase - First slot in a multislot key */
#define S50_ELS_KS16_KS16_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_KBASE_SHIFT)) & S50_ELS_KS16_KS16_KBASE_MASK)

#define S50_ELS_KS16_KS16_FGP_MASK               (0x80U)
#define S50_ELS_KS16_KS16_FGP_SHIFT              (7U)
/*! ks16_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS16_KS16_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FGP_SHIFT)) & S50_ELS_KS16_KS16_FGP_MASK)

#define S50_ELS_KS16_KS16_FRTN_MASK              (0x100U)
#define S50_ELS_KS16_KS16_FRTN_SHIFT             (8U)
/*! ks16_frtn - Hardware Feature Retention */
#define S50_ELS_KS16_KS16_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FRTN_SHIFT)) & S50_ELS_KS16_KS16_FRTN_MASK)

#define S50_ELS_KS16_KS16_FHWO_MASK              (0x200U)
#define S50_ELS_KS16_KS16_FHWO_SHIFT             (9U)
/*! ks16_fhwo - Hardware Feature Output */
#define S50_ELS_KS16_KS16_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_FHWO_SHIFT)) & S50_ELS_KS16_KS16_FHWO_MASK)

#define S50_ELS_KS16_KS16_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS16_KS16_RSVD1_SHIFT            (10U)
/*! ks16_rsvd1 - Reserved 1 */
#define S50_ELS_KS16_KS16_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_RSVD1_SHIFT)) & S50_ELS_KS16_KS16_RSVD1_MASK)

#define S50_ELS_KS16_KS16_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS16_KS16_UCMAC_SHIFT            (13U)
/*! ks16_ucmac - CMAC key */
#define S50_ELS_KS16_KS16_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UCMAC_SHIFT)) & S50_ELS_KS16_KS16_UCMAC_MASK)

#define S50_ELS_KS16_KS16_UKSK_MASK              (0x4000U)
#define S50_ELS_KS16_KS16_UKSK_SHIFT             (14U)
/*! ks16_uksk - KSK key */
#define S50_ELS_KS16_KS16_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKSK_SHIFT)) & S50_ELS_KS16_KS16_UKSK_MASK)

#define S50_ELS_KS16_KS16_URTF_MASK              (0x8000U)
#define S50_ELS_KS16_KS16_URTF_SHIFT             (15U)
/*! ks16_urtf - Real Time Fingerprint key */
#define S50_ELS_KS16_KS16_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_URTF_SHIFT)) & S50_ELS_KS16_KS16_URTF_MASK)

#define S50_ELS_KS16_KS16_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS16_KS16_UCKDF_SHIFT            (16U)
/*! ks16_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS16_KS16_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UCKDF_SHIFT)) & S50_ELS_KS16_KS16_UCKDF_MASK)

#define S50_ELS_KS16_KS16_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS16_KS16_UHKDF_SHIFT            (17U)
/*! ks16_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS16_KS16_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHKDF_SHIFT)) & S50_ELS_KS16_KS16_UHKDF_MASK)

#define S50_ELS_KS16_KS16_UECSG_MASK             (0x40000U)
#define S50_ELS_KS16_KS16_UECSG_SHIFT            (18U)
/*! ks16_uecsg - Ecc signing key */
#define S50_ELS_KS16_KS16_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UECSG_SHIFT)) & S50_ELS_KS16_KS16_UECSG_MASK)

#define S50_ELS_KS16_KS16_UECDH_MASK             (0x80000U)
#define S50_ELS_KS16_KS16_UECDH_SHIFT            (19U)
/*! ks16_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS16_KS16_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UECDH_SHIFT)) & S50_ELS_KS16_KS16_UECDH_MASK)

#define S50_ELS_KS16_KS16_UAES_MASK              (0x100000U)
#define S50_ELS_KS16_KS16_UAES_SHIFT             (20U)
/*! ks16_uaes - Aes key */
#define S50_ELS_KS16_KS16_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UAES_SHIFT)) & S50_ELS_KS16_KS16_UAES_MASK)

#define S50_ELS_KS16_KS16_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS16_KS16_UHMAC_SHIFT            (21U)
/*! ks16_uhmac - Hmac key */
#define S50_ELS_KS16_KS16_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHMAC_SHIFT)) & S50_ELS_KS16_KS16_UHMAC_MASK)

#define S50_ELS_KS16_KS16_UKWK_MASK              (0x400000U)
#define S50_ELS_KS16_KS16_UKWK_SHIFT             (22U)
/*! ks16_ukwk - Key wrapping key */
#define S50_ELS_KS16_KS16_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKWK_SHIFT)) & S50_ELS_KS16_KS16_UKWK_MASK)

#define S50_ELS_KS16_KS16_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS16_KS16_UKUOK_SHIFT            (23U)
/*! ks16_ukuok - Key unwrapping key */
#define S50_ELS_KS16_KS16_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKUOK_SHIFT)) & S50_ELS_KS16_KS16_UKUOK_MASK)

#define S50_ELS_KS16_KS16_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS16_KS16_UTLSPMS_SHIFT          (24U)
/*! ks16_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS16_KS16_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UTLSPMS_SHIFT)) & S50_ELS_KS16_KS16_UTLSPMS_MASK)

#define S50_ELS_KS16_KS16_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS16_KS16_UTLSMS_SHIFT           (25U)
/*! ks16_utlsms - TLS Master Secret */
#define S50_ELS_KS16_KS16_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UTLSMS_SHIFT)) & S50_ELS_KS16_KS16_UTLSMS_MASK)

#define S50_ELS_KS16_KS16_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS16_KS16_UKGSRC_SHIFT           (26U)
/*! ks16_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS16_KS16_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UKGSRC_SHIFT)) & S50_ELS_KS16_KS16_UKGSRC_MASK)

#define S50_ELS_KS16_KS16_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS16_KS16_UHWO_SHIFT             (27U)
/*! ks16_uhwo - Hardware out key */
#define S50_ELS_KS16_KS16_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UHWO_SHIFT)) & S50_ELS_KS16_KS16_UHWO_MASK)

#define S50_ELS_KS16_KS16_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS16_KS16_UWRPOK_SHIFT           (28U)
/*! ks16_uwrpok - Ok to wrap key */
#define S50_ELS_KS16_KS16_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UWRPOK_SHIFT)) & S50_ELS_KS16_KS16_UWRPOK_MASK)

#define S50_ELS_KS16_KS16_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS16_KS16_UDUK_SHIFT             (29U)
/*! ks16_uduk - Device Unique Key */
#define S50_ELS_KS16_KS16_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UDUK_SHIFT)) & S50_ELS_KS16_KS16_UDUK_MASK)

#define S50_ELS_KS16_KS16_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS16_KS16_UPPROT_SHIFT           (30U)
/*! ks16_upprot - Priviledge level */
#define S50_ELS_KS16_KS16_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS16_KS16_UPPROT_SHIFT)) & S50_ELS_KS16_KS16_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS17 - Status register */
/*! @{ */

#define S50_ELS_KS17_KS17_KSIZE_MASK             (0x1U)
#define S50_ELS_KS17_KS17_KSIZE_SHIFT            (0U)
/*! ks17_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS17_KS17_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KSIZE_SHIFT)) & S50_ELS_KS17_KS17_KSIZE_MASK)

#define S50_ELS_KS17_KS17_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS17_KS17_RSVD0_SHIFT            (1U)
/*! ks17_rsvd0 - Reserved 0 */
#define S50_ELS_KS17_KS17_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_RSVD0_SHIFT)) & S50_ELS_KS17_KS17_RSVD0_MASK)

#define S50_ELS_KS17_KS17_KACT_MASK              (0x20U)
#define S50_ELS_KS17_KS17_KACT_SHIFT             (5U)
/*! ks17_kact - Key is active */
#define S50_ELS_KS17_KS17_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KACT_SHIFT)) & S50_ELS_KS17_KS17_KACT_MASK)

#define S50_ELS_KS17_KS17_KBASE_MASK             (0x40U)
#define S50_ELS_KS17_KS17_KBASE_SHIFT            (6U)
/*! ks17_kbase - First slot in a multislot key */
#define S50_ELS_KS17_KS17_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_KBASE_SHIFT)) & S50_ELS_KS17_KS17_KBASE_MASK)

#define S50_ELS_KS17_KS17_FGP_MASK               (0x80U)
#define S50_ELS_KS17_KS17_FGP_SHIFT              (7U)
/*! ks17_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS17_KS17_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FGP_SHIFT)) & S50_ELS_KS17_KS17_FGP_MASK)

#define S50_ELS_KS17_KS17_FRTN_MASK              (0x100U)
#define S50_ELS_KS17_KS17_FRTN_SHIFT             (8U)
/*! ks17_frtn - Hardware Feature Retention */
#define S50_ELS_KS17_KS17_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FRTN_SHIFT)) & S50_ELS_KS17_KS17_FRTN_MASK)

#define S50_ELS_KS17_KS17_FHWO_MASK              (0x200U)
#define S50_ELS_KS17_KS17_FHWO_SHIFT             (9U)
/*! ks17_fhwo - Hardware Feature Output */
#define S50_ELS_KS17_KS17_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_FHWO_SHIFT)) & S50_ELS_KS17_KS17_FHWO_MASK)

#define S50_ELS_KS17_KS17_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS17_KS17_RSVD1_SHIFT            (10U)
/*! ks17_rsvd1 - Reserved 1 */
#define S50_ELS_KS17_KS17_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_RSVD1_SHIFT)) & S50_ELS_KS17_KS17_RSVD1_MASK)

#define S50_ELS_KS17_KS17_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS17_KS17_UCMAC_SHIFT            (13U)
/*! ks17_ucmac - CMAC key */
#define S50_ELS_KS17_KS17_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UCMAC_SHIFT)) & S50_ELS_KS17_KS17_UCMAC_MASK)

#define S50_ELS_KS17_KS17_UKSK_MASK              (0x4000U)
#define S50_ELS_KS17_KS17_UKSK_SHIFT             (14U)
/*! ks17_uksk - KSK key */
#define S50_ELS_KS17_KS17_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKSK_SHIFT)) & S50_ELS_KS17_KS17_UKSK_MASK)

#define S50_ELS_KS17_KS17_URTF_MASK              (0x8000U)
#define S50_ELS_KS17_KS17_URTF_SHIFT             (15U)
/*! ks17_urtf - Real Time Fingerprint key */
#define S50_ELS_KS17_KS17_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_URTF_SHIFT)) & S50_ELS_KS17_KS17_URTF_MASK)

#define S50_ELS_KS17_KS17_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS17_KS17_UCKDF_SHIFT            (16U)
/*! ks17_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS17_KS17_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UCKDF_SHIFT)) & S50_ELS_KS17_KS17_UCKDF_MASK)

#define S50_ELS_KS17_KS17_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS17_KS17_UHKDF_SHIFT            (17U)
/*! ks17_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS17_KS17_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHKDF_SHIFT)) & S50_ELS_KS17_KS17_UHKDF_MASK)

#define S50_ELS_KS17_KS17_UECSG_MASK             (0x40000U)
#define S50_ELS_KS17_KS17_UECSG_SHIFT            (18U)
/*! ks17_uecsg - Ecc signing key */
#define S50_ELS_KS17_KS17_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UECSG_SHIFT)) & S50_ELS_KS17_KS17_UECSG_MASK)

#define S50_ELS_KS17_KS17_UECDH_MASK             (0x80000U)
#define S50_ELS_KS17_KS17_UECDH_SHIFT            (19U)
/*! ks17_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS17_KS17_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UECDH_SHIFT)) & S50_ELS_KS17_KS17_UECDH_MASK)

#define S50_ELS_KS17_KS17_UAES_MASK              (0x100000U)
#define S50_ELS_KS17_KS17_UAES_SHIFT             (20U)
/*! ks17_uaes - Aes key */
#define S50_ELS_KS17_KS17_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UAES_SHIFT)) & S50_ELS_KS17_KS17_UAES_MASK)

#define S50_ELS_KS17_KS17_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS17_KS17_UHMAC_SHIFT            (21U)
/*! ks17_uhmac - Hmac key */
#define S50_ELS_KS17_KS17_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHMAC_SHIFT)) & S50_ELS_KS17_KS17_UHMAC_MASK)

#define S50_ELS_KS17_KS17_UKWK_MASK              (0x400000U)
#define S50_ELS_KS17_KS17_UKWK_SHIFT             (22U)
/*! ks17_ukwk - Key wrapping key */
#define S50_ELS_KS17_KS17_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKWK_SHIFT)) & S50_ELS_KS17_KS17_UKWK_MASK)

#define S50_ELS_KS17_KS17_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS17_KS17_UKUOK_SHIFT            (23U)
/*! ks17_ukuok - Key unwrapping key */
#define S50_ELS_KS17_KS17_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKUOK_SHIFT)) & S50_ELS_KS17_KS17_UKUOK_MASK)

#define S50_ELS_KS17_KS17_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS17_KS17_UTLSPMS_SHIFT          (24U)
/*! ks17_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS17_KS17_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UTLSPMS_SHIFT)) & S50_ELS_KS17_KS17_UTLSPMS_MASK)

#define S50_ELS_KS17_KS17_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS17_KS17_UTLSMS_SHIFT           (25U)
/*! ks17_utlsms - TLS Master Secret */
#define S50_ELS_KS17_KS17_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UTLSMS_SHIFT)) & S50_ELS_KS17_KS17_UTLSMS_MASK)

#define S50_ELS_KS17_KS17_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS17_KS17_UKGSRC_SHIFT           (26U)
/*! ks17_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS17_KS17_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UKGSRC_SHIFT)) & S50_ELS_KS17_KS17_UKGSRC_MASK)

#define S50_ELS_KS17_KS17_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS17_KS17_UHWO_SHIFT             (27U)
/*! ks17_uhwo - Hardware out key */
#define S50_ELS_KS17_KS17_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UHWO_SHIFT)) & S50_ELS_KS17_KS17_UHWO_MASK)

#define S50_ELS_KS17_KS17_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS17_KS17_UWRPOK_SHIFT           (28U)
/*! ks17_uwrpok - Ok to wrap key */
#define S50_ELS_KS17_KS17_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UWRPOK_SHIFT)) & S50_ELS_KS17_KS17_UWRPOK_MASK)

#define S50_ELS_KS17_KS17_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS17_KS17_UDUK_SHIFT             (29U)
/*! ks17_uduk - Device Unique Key */
#define S50_ELS_KS17_KS17_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UDUK_SHIFT)) & S50_ELS_KS17_KS17_UDUK_MASK)

#define S50_ELS_KS17_KS17_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS17_KS17_UPPROT_SHIFT           (30U)
/*! ks17_upprot - Priviledge level */
#define S50_ELS_KS17_KS17_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS17_KS17_UPPROT_SHIFT)) & S50_ELS_KS17_KS17_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS18 - Status register */
/*! @{ */

#define S50_ELS_KS18_KS18_KSIZE_MASK             (0x1U)
#define S50_ELS_KS18_KS18_KSIZE_SHIFT            (0U)
/*! ks18_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS18_KS18_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KSIZE_SHIFT)) & S50_ELS_KS18_KS18_KSIZE_MASK)

#define S50_ELS_KS18_KS18_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS18_KS18_RSVD0_SHIFT            (1U)
/*! ks18_rsvd0 - Reserved 0 */
#define S50_ELS_KS18_KS18_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_RSVD0_SHIFT)) & S50_ELS_KS18_KS18_RSVD0_MASK)

#define S50_ELS_KS18_KS18_KACT_MASK              (0x20U)
#define S50_ELS_KS18_KS18_KACT_SHIFT             (5U)
/*! ks18_kact - Key is active */
#define S50_ELS_KS18_KS18_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KACT_SHIFT)) & S50_ELS_KS18_KS18_KACT_MASK)

#define S50_ELS_KS18_KS18_KBASE_MASK             (0x40U)
#define S50_ELS_KS18_KS18_KBASE_SHIFT            (6U)
/*! ks18_kbase - First slot in a multislot key */
#define S50_ELS_KS18_KS18_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_KBASE_SHIFT)) & S50_ELS_KS18_KS18_KBASE_MASK)

#define S50_ELS_KS18_KS18_FGP_MASK               (0x80U)
#define S50_ELS_KS18_KS18_FGP_SHIFT              (7U)
/*! ks18_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS18_KS18_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FGP_SHIFT)) & S50_ELS_KS18_KS18_FGP_MASK)

#define S50_ELS_KS18_KS18_FRTN_MASK              (0x100U)
#define S50_ELS_KS18_KS18_FRTN_SHIFT             (8U)
/*! ks18_frtn - Hardware Feature Retention */
#define S50_ELS_KS18_KS18_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FRTN_SHIFT)) & S50_ELS_KS18_KS18_FRTN_MASK)

#define S50_ELS_KS18_KS18_FHWO_MASK              (0x200U)
#define S50_ELS_KS18_KS18_FHWO_SHIFT             (9U)
/*! ks18_fhwo - Hardware Feature Output */
#define S50_ELS_KS18_KS18_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_FHWO_SHIFT)) & S50_ELS_KS18_KS18_FHWO_MASK)

#define S50_ELS_KS18_KS18_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS18_KS18_RSVD1_SHIFT            (10U)
/*! ks18_rsvd1 - Reserved 1 */
#define S50_ELS_KS18_KS18_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_RSVD1_SHIFT)) & S50_ELS_KS18_KS18_RSVD1_MASK)

#define S50_ELS_KS18_KS18_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS18_KS18_UCMAC_SHIFT            (13U)
/*! ks18_ucmac - CMAC key */
#define S50_ELS_KS18_KS18_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UCMAC_SHIFT)) & S50_ELS_KS18_KS18_UCMAC_MASK)

#define S50_ELS_KS18_KS18_UKSK_MASK              (0x4000U)
#define S50_ELS_KS18_KS18_UKSK_SHIFT             (14U)
/*! ks18_uksk - KSK key */
#define S50_ELS_KS18_KS18_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKSK_SHIFT)) & S50_ELS_KS18_KS18_UKSK_MASK)

#define S50_ELS_KS18_KS18_URTF_MASK              (0x8000U)
#define S50_ELS_KS18_KS18_URTF_SHIFT             (15U)
/*! ks18_urtf - Real Time Fingerprint key */
#define S50_ELS_KS18_KS18_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_URTF_SHIFT)) & S50_ELS_KS18_KS18_URTF_MASK)

#define S50_ELS_KS18_KS18_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS18_KS18_UCKDF_SHIFT            (16U)
/*! ks18_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS18_KS18_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UCKDF_SHIFT)) & S50_ELS_KS18_KS18_UCKDF_MASK)

#define S50_ELS_KS18_KS18_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS18_KS18_UHKDF_SHIFT            (17U)
/*! ks18_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS18_KS18_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHKDF_SHIFT)) & S50_ELS_KS18_KS18_UHKDF_MASK)

#define S50_ELS_KS18_KS18_UECSG_MASK             (0x40000U)
#define S50_ELS_KS18_KS18_UECSG_SHIFT            (18U)
/*! ks18_uecsg - Ecc signing key */
#define S50_ELS_KS18_KS18_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UECSG_SHIFT)) & S50_ELS_KS18_KS18_UECSG_MASK)

#define S50_ELS_KS18_KS18_UECDH_MASK             (0x80000U)
#define S50_ELS_KS18_KS18_UECDH_SHIFT            (19U)
/*! ks18_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS18_KS18_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UECDH_SHIFT)) & S50_ELS_KS18_KS18_UECDH_MASK)

#define S50_ELS_KS18_KS18_UAES_MASK              (0x100000U)
#define S50_ELS_KS18_KS18_UAES_SHIFT             (20U)
/*! ks18_uaes - Aes key */
#define S50_ELS_KS18_KS18_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UAES_SHIFT)) & S50_ELS_KS18_KS18_UAES_MASK)

#define S50_ELS_KS18_KS18_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS18_KS18_UHMAC_SHIFT            (21U)
/*! ks18_uhmac - Hmac key */
#define S50_ELS_KS18_KS18_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHMAC_SHIFT)) & S50_ELS_KS18_KS18_UHMAC_MASK)

#define S50_ELS_KS18_KS18_UKWK_MASK              (0x400000U)
#define S50_ELS_KS18_KS18_UKWK_SHIFT             (22U)
/*! ks18_ukwk - Key wrapping key */
#define S50_ELS_KS18_KS18_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKWK_SHIFT)) & S50_ELS_KS18_KS18_UKWK_MASK)

#define S50_ELS_KS18_KS18_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS18_KS18_UKUOK_SHIFT            (23U)
/*! ks18_ukuok - Key unwrapping key */
#define S50_ELS_KS18_KS18_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKUOK_SHIFT)) & S50_ELS_KS18_KS18_UKUOK_MASK)

#define S50_ELS_KS18_KS18_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS18_KS18_UTLSPMS_SHIFT          (24U)
/*! ks18_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS18_KS18_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UTLSPMS_SHIFT)) & S50_ELS_KS18_KS18_UTLSPMS_MASK)

#define S50_ELS_KS18_KS18_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS18_KS18_UTLSMS_SHIFT           (25U)
/*! ks18_utlsms - TLS Master Secret */
#define S50_ELS_KS18_KS18_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UTLSMS_SHIFT)) & S50_ELS_KS18_KS18_UTLSMS_MASK)

#define S50_ELS_KS18_KS18_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS18_KS18_UKGSRC_SHIFT           (26U)
/*! ks18_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS18_KS18_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UKGSRC_SHIFT)) & S50_ELS_KS18_KS18_UKGSRC_MASK)

#define S50_ELS_KS18_KS18_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS18_KS18_UHWO_SHIFT             (27U)
/*! ks18_uhwo - Hardware out key */
#define S50_ELS_KS18_KS18_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UHWO_SHIFT)) & S50_ELS_KS18_KS18_UHWO_MASK)

#define S50_ELS_KS18_KS18_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS18_KS18_UWRPOK_SHIFT           (28U)
/*! ks18_uwrpok - Ok to wrap key */
#define S50_ELS_KS18_KS18_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UWRPOK_SHIFT)) & S50_ELS_KS18_KS18_UWRPOK_MASK)

#define S50_ELS_KS18_KS18_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS18_KS18_UDUK_SHIFT             (29U)
/*! ks18_uduk - Device Unique Key */
#define S50_ELS_KS18_KS18_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UDUK_SHIFT)) & S50_ELS_KS18_KS18_UDUK_MASK)

#define S50_ELS_KS18_KS18_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS18_KS18_UPPROT_SHIFT           (30U)
/*! ks18_upprot - Priviledge level */
#define S50_ELS_KS18_KS18_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS18_KS18_UPPROT_SHIFT)) & S50_ELS_KS18_KS18_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS19 - Status register */
/*! @{ */

#define S50_ELS_KS19_KS19_KSIZE_MASK             (0x1U)
#define S50_ELS_KS19_KS19_KSIZE_SHIFT            (0U)
/*! ks19_ksize - Key size: 0-128, 1-256 */
#define S50_ELS_KS19_KS19_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KSIZE_SHIFT)) & S50_ELS_KS19_KS19_KSIZE_MASK)

#define S50_ELS_KS19_KS19_RSVD0_MASK             (0x1EU)
#define S50_ELS_KS19_KS19_RSVD0_SHIFT            (1U)
/*! ks19_rsvd0 - Reserved 0 */
#define S50_ELS_KS19_KS19_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_RSVD0_SHIFT)) & S50_ELS_KS19_KS19_RSVD0_MASK)

#define S50_ELS_KS19_KS19_KACT_MASK              (0x20U)
#define S50_ELS_KS19_KS19_KACT_SHIFT             (5U)
/*! ks19_kact - Key is active */
#define S50_ELS_KS19_KS19_KACT(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KACT_SHIFT)) & S50_ELS_KS19_KS19_KACT_MASK)

#define S50_ELS_KS19_KS19_KBASE_MASK             (0x40U)
#define S50_ELS_KS19_KS19_KBASE_SHIFT            (6U)
/*! ks19_kbase - First slot in a multislot key */
#define S50_ELS_KS19_KS19_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_KBASE_SHIFT)) & S50_ELS_KS19_KS19_KBASE_MASK)

#define S50_ELS_KS19_KS19_FGP_MASK               (0x80U)
#define S50_ELS_KS19_KS19_FGP_SHIFT              (7U)
/*! ks19_fgp - Hardware Feature General Purpose */
#define S50_ELS_KS19_KS19_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FGP_SHIFT)) & S50_ELS_KS19_KS19_FGP_MASK)

#define S50_ELS_KS19_KS19_FRTN_MASK              (0x100U)
#define S50_ELS_KS19_KS19_FRTN_SHIFT             (8U)
/*! ks19_frtn - Hardware Feature Retention */
#define S50_ELS_KS19_KS19_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FRTN_SHIFT)) & S50_ELS_KS19_KS19_FRTN_MASK)

#define S50_ELS_KS19_KS19_FHWO_MASK              (0x200U)
#define S50_ELS_KS19_KS19_FHWO_SHIFT             (9U)
/*! ks19_fhwo - Hardware Feature Output */
#define S50_ELS_KS19_KS19_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_FHWO_SHIFT)) & S50_ELS_KS19_KS19_FHWO_MASK)

#define S50_ELS_KS19_KS19_RSVD1_MASK             (0x1C00U)
#define S50_ELS_KS19_KS19_RSVD1_SHIFT            (10U)
/*! ks19_rsvd1 - Reserved 1 */
#define S50_ELS_KS19_KS19_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_RSVD1_SHIFT)) & S50_ELS_KS19_KS19_RSVD1_MASK)

#define S50_ELS_KS19_KS19_UCMAC_MASK             (0x2000U)
#define S50_ELS_KS19_KS19_UCMAC_SHIFT            (13U)
/*! ks19_ucmac - CMAC key */
#define S50_ELS_KS19_KS19_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UCMAC_SHIFT)) & S50_ELS_KS19_KS19_UCMAC_MASK)

#define S50_ELS_KS19_KS19_UKSK_MASK              (0x4000U)
#define S50_ELS_KS19_KS19_UKSK_SHIFT             (14U)
/*! ks19_uksk - KSK key */
#define S50_ELS_KS19_KS19_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKSK_SHIFT)) & S50_ELS_KS19_KS19_UKSK_MASK)

#define S50_ELS_KS19_KS19_URTF_MASK              (0x8000U)
#define S50_ELS_KS19_KS19_URTF_SHIFT             (15U)
/*! ks19_urtf - Real Time Fingerprint key */
#define S50_ELS_KS19_KS19_URTF(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_URTF_SHIFT)) & S50_ELS_KS19_KS19_URTF_MASK)

#define S50_ELS_KS19_KS19_UCKDF_MASK             (0x10000U)
#define S50_ELS_KS19_KS19_UCKDF_SHIFT            (16U)
/*! ks19_uckdf - Derivation key for CKDF command */
#define S50_ELS_KS19_KS19_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UCKDF_SHIFT)) & S50_ELS_KS19_KS19_UCKDF_MASK)

#define S50_ELS_KS19_KS19_UHKDF_MASK             (0x20000U)
#define S50_ELS_KS19_KS19_UHKDF_SHIFT            (17U)
/*! ks19_uhkdf - Derivation key for HKDF command */
#define S50_ELS_KS19_KS19_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHKDF_SHIFT)) & S50_ELS_KS19_KS19_UHKDF_MASK)

#define S50_ELS_KS19_KS19_UECSG_MASK             (0x40000U)
#define S50_ELS_KS19_KS19_UECSG_SHIFT            (18U)
/*! ks19_uecsg - Ecc signing key */
#define S50_ELS_KS19_KS19_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UECSG_SHIFT)) & S50_ELS_KS19_KS19_UECSG_MASK)

#define S50_ELS_KS19_KS19_UECDH_MASK             (0x80000U)
#define S50_ELS_KS19_KS19_UECDH_SHIFT            (19U)
/*! ks19_uecdh - Ecc diffie hellman key */
#define S50_ELS_KS19_KS19_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UECDH_SHIFT)) & S50_ELS_KS19_KS19_UECDH_MASK)

#define S50_ELS_KS19_KS19_UAES_MASK              (0x100000U)
#define S50_ELS_KS19_KS19_UAES_SHIFT             (20U)
/*! ks19_uaes - Aes key */
#define S50_ELS_KS19_KS19_UAES(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UAES_SHIFT)) & S50_ELS_KS19_KS19_UAES_MASK)

#define S50_ELS_KS19_KS19_UHMAC_MASK             (0x200000U)
#define S50_ELS_KS19_KS19_UHMAC_SHIFT            (21U)
/*! ks19_uhmac - Hmac key */
#define S50_ELS_KS19_KS19_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHMAC_SHIFT)) & S50_ELS_KS19_KS19_UHMAC_MASK)

#define S50_ELS_KS19_KS19_UKWK_MASK              (0x400000U)
#define S50_ELS_KS19_KS19_UKWK_SHIFT             (22U)
/*! ks19_ukwk - Key wrapping key */
#define S50_ELS_KS19_KS19_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKWK_SHIFT)) & S50_ELS_KS19_KS19_UKWK_MASK)

#define S50_ELS_KS19_KS19_UKUOK_MASK             (0x800000U)
#define S50_ELS_KS19_KS19_UKUOK_SHIFT            (23U)
/*! ks19_ukuok - Key unwrapping key */
#define S50_ELS_KS19_KS19_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKUOK_SHIFT)) & S50_ELS_KS19_KS19_UKUOK_MASK)

#define S50_ELS_KS19_KS19_UTLSPMS_MASK           (0x1000000U)
#define S50_ELS_KS19_KS19_UTLSPMS_SHIFT          (24U)
/*! ks19_utlspms - TLS Pre Master Secret */
#define S50_ELS_KS19_KS19_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UTLSPMS_SHIFT)) & S50_ELS_KS19_KS19_UTLSPMS_MASK)

#define S50_ELS_KS19_KS19_UTLSMS_MASK            (0x2000000U)
#define S50_ELS_KS19_KS19_UTLSMS_SHIFT           (25U)
/*! ks19_utlsms - TLS Master Secret */
#define S50_ELS_KS19_KS19_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UTLSMS_SHIFT)) & S50_ELS_KS19_KS19_UTLSMS_MASK)

#define S50_ELS_KS19_KS19_UKGSRC_MASK            (0x4000000U)
#define S50_ELS_KS19_KS19_UKGSRC_SHIFT           (26U)
/*! ks19_ukgsrc - Supply KEYGEN source */
#define S50_ELS_KS19_KS19_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UKGSRC_SHIFT)) & S50_ELS_KS19_KS19_UKGSRC_MASK)

#define S50_ELS_KS19_KS19_UHWO_MASK              (0x8000000U)
#define S50_ELS_KS19_KS19_UHWO_SHIFT             (27U)
/*! ks19_uhwo - Hardware out key */
#define S50_ELS_KS19_KS19_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UHWO_SHIFT)) & S50_ELS_KS19_KS19_UHWO_MASK)

#define S50_ELS_KS19_KS19_UWRPOK_MASK            (0x10000000U)
#define S50_ELS_KS19_KS19_UWRPOK_SHIFT           (28U)
/*! ks19_uwrpok - Ok to wrap key */
#define S50_ELS_KS19_KS19_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UWRPOK_SHIFT)) & S50_ELS_KS19_KS19_UWRPOK_MASK)

#define S50_ELS_KS19_KS19_UDUK_MASK              (0x20000000U)
#define S50_ELS_KS19_KS19_UDUK_SHIFT             (29U)
/*! ks19_uduk - Device Unique Key */
#define S50_ELS_KS19_KS19_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UDUK_SHIFT)) & S50_ELS_KS19_KS19_UDUK_MASK)

#define S50_ELS_KS19_KS19_UPPROT_MASK            (0xC0000000U)
#define S50_ELS_KS19_KS19_UPPROT_SHIFT           (30U)
/*! ks19_upprot - Priviledge level */
#define S50_ELS_KS19_KS19_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << S50_ELS_KS19_KS19_UPPROT_SHIFT)) & S50_ELS_KS19_KS19_UPPROT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group S50_Register_Masks */


/*!
 * @}
 */ /* end of group S50_Peripheral_Access_Layer */


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


#endif  /* PERI_S50_H_ */

