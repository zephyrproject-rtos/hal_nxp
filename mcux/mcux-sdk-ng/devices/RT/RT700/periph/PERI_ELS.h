/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 2.0, 2024-05-28
**     Build:               b241121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ELS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**
** ###################################################################
*/

/*!
 * @file ELS.h
 * @version 2.0
 * @date 2024-05-28
 * @brief CMSIS Peripheral Access Layer for ELS
 *
 * CMSIS Peripheral Access Layer for ELS
 */

#if !defined(ELS_H_)
#define ELS_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- ELS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELS_Peripheral_Access_Layer ELS Peripheral Access Layer
 * @{
 */

/** ELS - Register Layout Typedef */
typedef struct {
  __I  uint32_t ELS_STATUS;                        /**< Status Register, offset: 0x0 */
  __IO uint32_t ELS_CTRL;                          /**< Control Register, offset: 0x4 */
  __IO uint32_t ELS_CMDCFG0;                       /**< Command Configuration, offset: 0x8 */
  __IO uint32_t ELS_CFG;                           /**< Configuration Register, offset: 0xC */
  __IO uint32_t ELS_KIDX0;                         /**< Keystore Index 0 Register, offset: 0x10 */
  __IO uint32_t ELS_KIDX1;                         /**< Keystore Index 1 Register, offset: 0x14 */
  __IO uint32_t ELS_KPROPIN;                       /**< Key Properties Request Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t ELS_DMA_SRC0;                      /**< DMA Source 0 Register, offset: 0x20 */
  __IO uint32_t ELS_DMA_SRC0_LEN;                  /**< DMA Source 0 Length Register, offset: 0x24 */
  __IO uint32_t ELS_DMA_SRC1;                      /**< DMA Source 1 Register, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ELS_DMA_SRC2;                      /**< DMA Source 2 Register, offset: 0x30 */
  __IO uint32_t ELS_DMA_SRC2_LEN;                  /**< DMA Source 2 Length Register, offset: 0x34 */
  __IO uint32_t ELS_DMA_RES0;                      /**< DMA Result 0 Register, offset: 0x38 */
  __IO uint32_t ELS_DMA_RES0_LEN;                  /**< DMA Result 0 Size Register, offset: 0x3C */
  __IO uint32_t ELS_INT_ENABLE;                    /**< Interrupt Enable Register, offset: 0x40 */
  __O  uint32_t ELS_INT_STATUS_CLR;                /**< Interrupt Status Clear Register, offset: 0x44 */
  __O  uint32_t ELS_INT_STATUS_SET;                /**< Interrupt Status Set Register, offset: 0x48 */
  __I  uint32_t ELS_ERR_STATUS;                    /**< Error Status Register, offset: 0x4C */
  __O  uint32_t ELS_ERR_STATUS_CLR;                /**< Error Status Clear Register, offset: 0x50 */
  __I  uint32_t ELS_VERSION;                       /**< Version Register, offset: 0x54 */
  __I  uint32_t ELS_CONFIG;                        /**< ELS CONFIG, offset: 0x58 */
  __I  uint32_t ELS_PRNG_DATOUT;                   /**< PRNG SW Read Out Register, offset: 0x5C */
  __IO uint32_t ELS_CMDCRC_CTRL;                   /**< CRC Configuration Register, offset: 0x60 */
  __I  uint32_t ELS_CMDCRC;                        /**< Command CRC Value Register, offset: 0x64 */
  __IO uint32_t ELS_SESSION_ID;                    /**< Session ID Register, offset: 0x68 */
       uint8_t RESERVED_2[4];
  __I  uint32_t ELS_DMA_FIN_ADDR;                  /**< Final DMA Address Register, offset: 0x70 */
  __IO uint32_t ELS_MASTER_ID;                     /**< Master ID Register, offset: 0x74 */
  __IO uint32_t ELS_KIDX2;                         /**< Keystore Index 2 Register, offset: 0x78 */
       uint8_t RESERVED_3[132];
  __I  uint32_t ELS_SHA2_STATUS;                   /**< SHA2 Status Register, offset: 0x100 */
  __IO uint32_t ELS_SHA2_CTRL;                     /**< SHA2 Control Register, offset: 0x104 */
  __IO uint32_t ELS_SHA2_DIN;                      /**< SHA_DATA IN 0 Register, offset: 0x108 */
  __I  uint32_t ELS_SHA2_DOUT0;                    /**< SHA_DATA Out 0 Register, offset: 0x10C */
  __I  uint32_t ELS_SHA2_DOUT1;                    /**< SHA_DATA Out 1 Register, offset: 0x110 */
  __I  uint32_t ELS_SHA2_DOUT2;                    /**< SHA_DATA Out 2 Register, offset: 0x114 */
  __I  uint32_t ELS_SHA2_DOUT3;                    /**< SHA_DATA Out 3 Register, offset: 0x118 */
  __I  uint32_t ELS_SHA2_DOUT4;                    /**< SHA_DATA Out 4 Register, offset: 0x11C */
  __I  uint32_t ELS_SHA2_DOUT5;                    /**< SHA_DATA Out 5 Register, offset: 0x120 */
  __I  uint32_t ELS_SHA2_DOUT6;                    /**< SHA_DATA Out 6 Register, offset: 0x124 */
  __I  uint32_t ELS_SHA2_DOUT7;                    /**< SHA_DATA Out 7 Register, offset: 0x128 */
  __I  uint32_t ELS_SHA2_DOUT8;                    /**< SHA_DATA Out 8 Register, offset: 0x12C */
  __I  uint32_t ELS_SHA2_DOUT9;                    /**< SHA_DATA Out 9 Register, offset: 0x130 */
  __I  uint32_t ELS_SHA2_DOUT10;                   /**< SHA_DATA Out 10 Register, offset: 0x134 */
  __I  uint32_t ELS_SHA2_DOUT11;                   /**< SHA_DATA Out 11 Register, offset: 0x138 */
  __I  uint32_t ELS_SHA2_DOUT12;                   /**< SHA_DATA Out 12 Register, offset: 0x13C */
  __I  uint32_t ELS_SHA2_DOUT13;                   /**< SHA_DATA Out 13 Register, offset: 0x140 */
  __I  uint32_t ELS_SHA2_DOUT14;                   /**< SHA_DATA Out 14 Register, offset: 0x144 */
  __I  uint32_t ELS_SHA2_DOUT15;                   /**< SHA_DATA Out 15 Register, offset: 0x148 */
       uint8_t RESERVED_4[4];
  __I  uint32_t ELS_KS0;                           /**< Status Register, offset: 0x150 */
  __I  uint32_t ELS_KS1;                           /**< Status Register, offset: 0x154 */
  __I  uint32_t ELS_KS2;                           /**< Status Register, offset: 0x158 */
  __I  uint32_t ELS_KS3;                           /**< Status Register, offset: 0x15C */
  __I  uint32_t ELS_KS4;                           /**< Status Register, offset: 0x160 */
  __I  uint32_t ELS_KS5;                           /**< Status Register, offset: 0x164 */
  __I  uint32_t ELS_KS6;                           /**< Status Register, offset: 0x168 */
  __I  uint32_t ELS_KS7;                           /**< Status Register, offset: 0x16C */
  __I  uint32_t ELS_KS8;                           /**< Status Register, offset: 0x170 */
  __I  uint32_t ELS_KS9;                           /**< Status Register, offset: 0x174 */
  __I  uint32_t ELS_KS10;                          /**< Status Register, offset: 0x178 */
  __I  uint32_t ELS_KS11;                          /**< Status Register, offset: 0x17C */
  __I  uint32_t ELS_KS12;                          /**< Status Register, offset: 0x180 */
  __I  uint32_t ELS_KS13;                          /**< Status Register, offset: 0x184 */
  __I  uint32_t ELS_KS14;                          /**< Status Register, offset: 0x188 */
  __I  uint32_t ELS_KS15;                          /**< Status Register, offset: 0x18C */
  __I  uint32_t ELS_KS16;                          /**< Status Register, offset: 0x190 */
  __I  uint32_t ELS_KS17;                          /**< Status Register, offset: 0x194 */
  __I  uint32_t ELS_KS18;                          /**< Status Register, offset: 0x198 */
  __I  uint32_t ELS_KS19;                          /**< Status Register, offset: 0x19C */
       uint8_t RESERVED_5[4];
  __IO uint32_t RESERVED_LA4;                      /**< Reserved LA4, offset: 0x1A4 */
  __IO uint32_t RESERVED_LA8;                      /**< Reserved LA8, offset: 0x1A8 */
} ELS_Type;

/* ----------------------------------------------------------------------------
   -- ELS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ELS_Register_Masks ELS Register Masks
 * @{
 */

/*! @name ELS_STATUS - Status Register */
/*! @{ */

#define ELS_ELS_STATUS_ELS_BUSY_MASK             (0x1U)
#define ELS_ELS_STATUS_ELS_BUSY_SHIFT            (0U)
/*! ELS_BUSY
 *  0b0..Crypto sequence not executing
 *  0b1..Crypto sequence executing
 */
#define ELS_ELS_STATUS_ELS_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_ELS_BUSY_SHIFT)) & ELS_ELS_STATUS_ELS_BUSY_MASK)

#define ELS_ELS_STATUS_ELS_IRQ_MASK              (0x2U)
#define ELS_ELS_STATUS_ELS_IRQ_SHIFT             (1U)
/*! ELS_IRQ
 *  0b0..No active interrupt
 *  0b1..Active interrupt
 */
#define ELS_ELS_STATUS_ELS_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_ELS_IRQ_SHIFT)) & ELS_ELS_STATUS_ELS_IRQ_MASK)

#define ELS_ELS_STATUS_ELS_ERR_MASK              (0x4U)
#define ELS_ELS_STATUS_ELS_ERR_SHIFT             (2U)
/*! ELS_ERR
 *  0b0..Internal error not detected
 *  0b1..Internal error detected
 */
#define ELS_ELS_STATUS_ELS_ERR(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_ELS_ERR_SHIFT)) & ELS_ELS_STATUS_ELS_ERR_MASK)

#define ELS_ELS_STATUS_PRNG_RDY_MASK             (0x8U)
#define ELS_ELS_STATUS_PRNG_RDY_SHIFT            (3U)
/*! PRNG_RDY
 *  0b0..Internal PRNG not ready
 *  0b1..Internal PRNG ready
 */
#define ELS_ELS_STATUS_PRNG_RDY(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_PRNG_RDY_SHIFT)) & ELS_ELS_STATUS_PRNG_RDY_MASK)

#define ELS_ELS_STATUS_ECDSA_VFY_STATUS_MASK     (0x30U)
#define ELS_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT    (4U)
/*! ECDSA_VFY_STATUS
 *  0b00..No verify run
 *  0b01..Signature verify failed
 *  0b10..Signature verify passed
 *  0b11..Invalid, Error
 */
#define ELS_ELS_STATUS_ECDSA_VFY_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_ECDSA_VFY_STATUS_SHIFT)) & ELS_ELS_STATUS_ECDSA_VFY_STATUS_MASK)

#define ELS_ELS_STATUS_PPROT_MASK                (0xC0U)
#define ELS_ELS_STATUS_PPROT_SHIFT               (6U)
/*! PPROT
 *  0b00..Secure, non-privileged
 *  0b01..Secure, privileged
 *  0b10..Non-secure, non-privileged
 *  0b11..Non-secure, privileged
 */
#define ELS_ELS_STATUS_PPROT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_PPROT_SHIFT)) & ELS_ELS_STATUS_PPROT_MASK)

#define ELS_ELS_STATUS_DRBG_ENT_LVL_MASK         (0x300U)
#define ELS_ELS_STATUS_DRBG_ENT_LVL_SHIFT        (8U)
/*! DRBG_ENT_LVL
 *  0b00..NONE
 *  0b01..LOW, DRBG generates random numbers of low quality entropy
 *  0b10..HIGH, DRBG generates random numbers of high quality entropy
 *  0b11..RFU, Reserved for Future Use
 */
#define ELS_ELS_STATUS_DRBG_ENT_LVL(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_DRBG_ENT_LVL_SHIFT)) & ELS_ELS_STATUS_DRBG_ENT_LVL_MASK)

#define ELS_ELS_STATUS_DTRNG_BUSY_MASK           (0x400U)
#define ELS_ELS_STATUS_DTRNG_BUSY_SHIFT          (10U)
/*! DTRNG_BUSY
 *  0b0..Not gathering entropy
 *  0b1..Gathering entropy
 */
#define ELS_ELS_STATUS_DTRNG_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_DTRNG_BUSY_SHIFT)) & ELS_ELS_STATUS_DTRNG_BUSY_MASK)

#define ELS_ELS_STATUS_ELS_LOCKED_MASK           (0x10000U)
#define ELS_ELS_STATUS_ELS_LOCKED_SHIFT          (16U)
/*! ELS_LOCKED
 *  0b0..Not locked by master
 *  0b1..Locked by master
 */
#define ELS_ELS_STATUS_ELS_LOCKED(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_ELS_LOCKED_SHIFT)) & ELS_ELS_STATUS_ELS_LOCKED_MASK)

#define ELS_ELS_STATUS_RESERVED17_MASK           (0x20000U)
#define ELS_ELS_STATUS_RESERVED17_SHIFT          (17U)
/*! reserved17 - reserved */
#define ELS_ELS_STATUS_RESERVED17(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_RESERVED17_SHIFT)) & ELS_ELS_STATUS_RESERVED17_MASK)

#define ELS_ELS_STATUS_RESERVED31_MASK           (0xFFFC0000U)
#define ELS_ELS_STATUS_RESERVED31_SHIFT          (18U)
/*! reserved31 - reserved */
#define ELS_ELS_STATUS_RESERVED31(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_STATUS_RESERVED31_SHIFT)) & ELS_ELS_STATUS_RESERVED31_MASK)
/*! @} */

/*! @name ELS_CTRL - Control Register */
/*! @{ */

#define ELS_ELS_CTRL_ELS_EN_MASK                 (0x1U)
#define ELS_ELS_CTRL_ELS_EN_SHIFT                (0U)
/*! ELS_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define ELS_ELS_CTRL_ELS_EN(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CTRL_ELS_EN_SHIFT)) & ELS_ELS_CTRL_ELS_EN_MASK)

#define ELS_ELS_CTRL_ELS_START_MASK              (0x2U)
#define ELS_ELS_CTRL_ELS_START_SHIFT             (1U)
#define ELS_ELS_CTRL_ELS_START(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CTRL_ELS_START_SHIFT)) & ELS_ELS_CTRL_ELS_START_MASK)

#define ELS_ELS_CTRL_ELS_RESET_MASK              (0x4U)
#define ELS_ELS_CTRL_ELS_RESET_SHIFT             (2U)
#define ELS_ELS_CTRL_ELS_RESET(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CTRL_ELS_RESET_SHIFT)) & ELS_ELS_CTRL_ELS_RESET_MASK)

#define ELS_ELS_CTRL_ELS_CMD_MASK                (0xF8U)
#define ELS_ELS_CTRL_ELS_CMD_SHIFT               (3U)
/*! ELS_CMD - ELS Command ID */
#define ELS_ELS_CTRL_ELS_CMD(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CTRL_ELS_CMD_SHIFT)) & ELS_ELS_CTRL_ELS_CMD_MASK)

#define ELS_ELS_CTRL_BYTE_ORDER_MASK             (0x100U)
#define ELS_ELS_CTRL_BYTE_ORDER_SHIFT            (8U)
/*! BYTE_ORDER
 *  0b0..Little endian
 *  0b1..Big endian
 */
#define ELS_ELS_CTRL_BYTE_ORDER(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CTRL_BYTE_ORDER_SHIFT)) & ELS_ELS_CTRL_BYTE_ORDER_MASK)
/*! @} */

/*! @name ELS_CMDCFG0 - Command Configuration */
/*! @{ */

#define ELS_ELS_CMDCFG0_CMDCFG0_MASK             (0xFFFFFFFFU)
#define ELS_ELS_CMDCFG0_CMDCFG0_SHIFT            (0U)
#define ELS_ELS_CMDCFG0_CMDCFG0(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CMDCFG0_CMDCFG0_SHIFT)) & ELS_ELS_CMDCFG0_CMDCFG0_MASK)
/*! @} */

/*! @name ELS_CFG - Configuration Register */
/*! @{ */

#define ELS_ELS_CFG_ADCTRL_MASK                  (0x3FF0000U)
#define ELS_ELS_CFG_ADCTRL_SHIFT                 (16U)
#define ELS_ELS_CFG_ADCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CFG_ADCTRL_SHIFT)) & ELS_ELS_CFG_ADCTRL_MASK)

#define ELS_ELS_CFG_SHA2_DIRECT_MASK             (0x80000000U)
#define ELS_ELS_CFG_SHA2_DIRECT_SHIFT            (31U)
/*! SHA2_DIRECT
 *  0b0..Disabled
 *  0b1..Enabled: direct access from external
 */
#define ELS_ELS_CFG_SHA2_DIRECT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CFG_SHA2_DIRECT_SHIFT)) & ELS_ELS_CFG_SHA2_DIRECT_MASK)
/*! @} */

/*! @name ELS_KIDX0 - Keystore Index 0 Register */
/*! @{ */

#define ELS_ELS_KIDX0_KIDX0_MASK                 (0x1FU)
#define ELS_ELS_KIDX0_KIDX0_SHIFT                (0U)
#define ELS_ELS_KIDX0_KIDX0(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KIDX0_KIDX0_SHIFT)) & ELS_ELS_KIDX0_KIDX0_MASK)
/*! @} */

/*! @name ELS_KIDX1 - Keystore Index 1 Register */
/*! @{ */

#define ELS_ELS_KIDX1_KIDX1_MASK                 (0x1FU)
#define ELS_ELS_KIDX1_KIDX1_SHIFT                (0U)
#define ELS_ELS_KIDX1_KIDX1(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KIDX1_KIDX1_SHIFT)) & ELS_ELS_KIDX1_KIDX1_MASK)
/*! @} */

/*! @name ELS_KPROPIN - Key Properties Request Register */
/*! @{ */

#define ELS_ELS_KPROPIN_KPROPIN_MASK             (0xFFFFFFFFU)
#define ELS_ELS_KPROPIN_KPROPIN_SHIFT            (0U)
#define ELS_ELS_KPROPIN_KPROPIN(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KPROPIN_KPROPIN_SHIFT)) & ELS_ELS_KPROPIN_KPROPIN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0 - DMA Source 0 Register */
/*! @{ */

#define ELS_ELS_DMA_SRC0_ADDR_SRC0_MASK          (0xFFFFFFFFU)
#define ELS_ELS_DMA_SRC0_ADDR_SRC0_SHIFT         (0U)
#define ELS_ELS_DMA_SRC0_ADDR_SRC0(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_SRC0_ADDR_SRC0_SHIFT)) & ELS_ELS_DMA_SRC0_ADDR_SRC0_MASK)
/*! @} */

/*! @name ELS_DMA_SRC0_LEN - DMA Source 0 Length Register */
/*! @{ */

#define ELS_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK  (0xFFFFFFFFU)
#define ELS_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT (0U)
#define ELS_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_SHIFT)) & ELS_ELS_DMA_SRC0_LEN_SIZE_SRC0_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_SRC1 - DMA Source 1 Register */
/*! @{ */

#define ELS_ELS_DMA_SRC1_ADDR_SRC1_MASK          (0xFFFFFFFFU)
#define ELS_ELS_DMA_SRC1_ADDR_SRC1_SHIFT         (0U)
#define ELS_ELS_DMA_SRC1_ADDR_SRC1(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_SRC1_ADDR_SRC1_SHIFT)) & ELS_ELS_DMA_SRC1_ADDR_SRC1_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2 - DMA Source 2 Register */
/*! @{ */

#define ELS_ELS_DMA_SRC2_ADDR_SRC2_MASK          (0xFFFFFFFFU)
#define ELS_ELS_DMA_SRC2_ADDR_SRC2_SHIFT         (0U)
#define ELS_ELS_DMA_SRC2_ADDR_SRC2(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_SRC2_ADDR_SRC2_SHIFT)) & ELS_ELS_DMA_SRC2_ADDR_SRC2_MASK)
/*! @} */

/*! @name ELS_DMA_SRC2_LEN - DMA Source 2 Length Register */
/*! @{ */

#define ELS_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK  (0xFFFFFFFFU)
#define ELS_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT (0U)
#define ELS_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN(x)    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_SHIFT)) & ELS_ELS_DMA_SRC2_LEN_SIZE_SRC2_LEN_MASK)
/*! @} */

/*! @name ELS_DMA_RES0 - DMA Result 0 Register */
/*! @{ */

#define ELS_ELS_DMA_RES0_ADDR_RES0_MASK          (0xFFFFFFFFU)
#define ELS_ELS_DMA_RES0_ADDR_RES0_SHIFT         (0U)
#define ELS_ELS_DMA_RES0_ADDR_RES0(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_RES0_ADDR_RES0_SHIFT)) & ELS_ELS_DMA_RES0_ADDR_RES0_MASK)
/*! @} */

/*! @name ELS_DMA_RES0_LEN - DMA Result 0 Size Register */
/*! @{ */

#define ELS_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK  (0xFFFFFFFFU)
#define ELS_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT (0U)
#define ELS_ELS_DMA_RES0_LEN_SIZE_RES0_LEN(x)    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_SHIFT)) & ELS_ELS_DMA_RES0_LEN_SIZE_RES0_LEN_MASK)
/*! @} */

/*! @name ELS_INT_ENABLE - Interrupt Enable Register */
/*! @{ */

#define ELS_ELS_INT_ENABLE_INT_EN_MASK           (0x1U)
#define ELS_ELS_INT_ENABLE_INT_EN_SHIFT          (0U)
#define ELS_ELS_INT_ENABLE_INT_EN(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_INT_ENABLE_INT_EN_SHIFT)) & ELS_ELS_INT_ENABLE_INT_EN_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_CLR - Interrupt Status Clear Register */
/*! @{ */

#define ELS_ELS_INT_STATUS_CLR_INT_CLR_MASK      (0x1U)
#define ELS_ELS_INT_STATUS_CLR_INT_CLR_SHIFT     (0U)
#define ELS_ELS_INT_STATUS_CLR_INT_CLR(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_INT_STATUS_CLR_INT_CLR_SHIFT)) & ELS_ELS_INT_STATUS_CLR_INT_CLR_MASK)
/*! @} */

/*! @name ELS_INT_STATUS_SET - Interrupt Status Set Register */
/*! @{ */

#define ELS_ELS_INT_STATUS_SET_INT_SET_MASK      (0x1U)
#define ELS_ELS_INT_STATUS_SET_INT_SET_SHIFT     (0U)
#define ELS_ELS_INT_STATUS_SET_INT_SET(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_INT_STATUS_SET_INT_SET_SHIFT)) & ELS_ELS_INT_STATUS_SET_INT_SET_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS - Error Status Register */
/*! @{ */

#define ELS_ELS_ERR_STATUS_BUS_ERR_MASK          (0x1U)
#define ELS_ELS_ERR_STATUS_BUS_ERR_SHIFT         (0U)
#define ELS_ELS_ERR_STATUS_BUS_ERR(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_BUS_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_BUS_ERR_MASK)

#define ELS_ELS_ERR_STATUS_OPN_ERR_MASK          (0x2U)
#define ELS_ELS_ERR_STATUS_OPN_ERR_SHIFT         (1U)
#define ELS_ELS_ERR_STATUS_OPN_ERR(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_OPN_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_OPN_ERR_MASK)

#define ELS_ELS_ERR_STATUS_ALG_ERR_MASK          (0x4U)
#define ELS_ELS_ERR_STATUS_ALG_ERR_SHIFT         (2U)
#define ELS_ELS_ERR_STATUS_ALG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_ALG_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_ALG_ERR_MASK)

#define ELS_ELS_ERR_STATUS_ITG_ERR_MASK          (0x8U)
#define ELS_ELS_ERR_STATUS_ITG_ERR_SHIFT         (3U)
#define ELS_ELS_ERR_STATUS_ITG_ERR(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_ITG_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_ITG_ERR_MASK)

#define ELS_ELS_ERR_STATUS_FLT_ERR_MASK          (0x10U)
#define ELS_ELS_ERR_STATUS_FLT_ERR_SHIFT         (4U)
#define ELS_ELS_ERR_STATUS_FLT_ERR(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_FLT_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_FLT_ERR_MASK)

#define ELS_ELS_ERR_STATUS_PRNG_ERR_MASK         (0x20U)
#define ELS_ELS_ERR_STATUS_PRNG_ERR_SHIFT        (5U)
#define ELS_ELS_ERR_STATUS_PRNG_ERR(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_PRNG_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_PRNG_ERR_MASK)

#define ELS_ELS_ERR_STATUS_ERR_LVL_MASK          (0xC0U)
#define ELS_ELS_ERR_STATUS_ERR_LVL_SHIFT         (6U)
#define ELS_ELS_ERR_STATUS_ERR_LVL(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_ERR_LVL_SHIFT)) & ELS_ELS_ERR_STATUS_ERR_LVL_MASK)

#define ELS_ELS_ERR_STATUS_DTRNG_ERR_MASK        (0x100U)
#define ELS_ELS_ERR_STATUS_DTRNG_ERR_SHIFT       (8U)
#define ELS_ELS_ERR_STATUS_DTRNG_ERR(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_DTRNG_ERR_SHIFT)) & ELS_ELS_ERR_STATUS_DTRNG_ERR_MASK)
/*! @} */

/*! @name ELS_ERR_STATUS_CLR - Error Status Clear Register */
/*! @{ */

#define ELS_ELS_ERR_STATUS_CLR_ERR_CLR_MASK      (0x1U)
#define ELS_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT     (0U)
/*! ERR_CLR
 *  0b0..Exits ELS error state
 *  0b1..Clears ELS error status bits
 */
#define ELS_ELS_ERR_STATUS_CLR_ERR_CLR(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_ERR_STATUS_CLR_ERR_CLR_SHIFT)) & ELS_ELS_ERR_STATUS_CLR_ERR_CLR_MASK)
/*! @} */

/*! @name ELS_VERSION - Version Register */
/*! @{ */

#define ELS_ELS_VERSION_Z_MASK                   (0xFU)
#define ELS_ELS_VERSION_Z_SHIFT                  (0U)
#define ELS_ELS_VERSION_Z(x)                     (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_Z_SHIFT)) & ELS_ELS_VERSION_Z_MASK)

#define ELS_ELS_VERSION_Y2_MASK                  (0xF0U)
#define ELS_ELS_VERSION_Y2_SHIFT                 (4U)
#define ELS_ELS_VERSION_Y2(x)                    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_Y2_SHIFT)) & ELS_ELS_VERSION_Y2_MASK)

#define ELS_ELS_VERSION_Y1_MASK                  (0xF00U)
#define ELS_ELS_VERSION_Y1_SHIFT                 (8U)
#define ELS_ELS_VERSION_Y1(x)                    (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_Y1_SHIFT)) & ELS_ELS_VERSION_Y1_MASK)

#define ELS_ELS_VERSION_X_MASK                   (0xF000U)
#define ELS_ELS_VERSION_X_SHIFT                  (12U)
#define ELS_ELS_VERSION_X(x)                     (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_X_SHIFT)) & ELS_ELS_VERSION_X_MASK)

#define ELS_ELS_VERSION_SW_Z_MASK                (0xF0000U)
#define ELS_ELS_VERSION_SW_Z_SHIFT               (16U)
#define ELS_ELS_VERSION_SW_Z(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_SW_Z_SHIFT)) & ELS_ELS_VERSION_SW_Z_MASK)

#define ELS_ELS_VERSION_SW_Y2_MASK               (0xF00000U)
#define ELS_ELS_VERSION_SW_Y2_SHIFT              (20U)
#define ELS_ELS_VERSION_SW_Y2(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_SW_Y2_SHIFT)) & ELS_ELS_VERSION_SW_Y2_MASK)

#define ELS_ELS_VERSION_SW_Y1_MASK               (0xF000000U)
#define ELS_ELS_VERSION_SW_Y1_SHIFT              (24U)
#define ELS_ELS_VERSION_SW_Y1(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_SW_Y1_SHIFT)) & ELS_ELS_VERSION_SW_Y1_MASK)

#define ELS_ELS_VERSION_SW_X_MASK                (0xF0000000U)
#define ELS_ELS_VERSION_SW_X_SHIFT               (28U)
#define ELS_ELS_VERSION_SW_X(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_VERSION_SW_X_SHIFT)) & ELS_ELS_VERSION_SW_X_MASK)
/*! @} */

/*! @name ELS_CONFIG - ELS CONFIG */
/*! @{ */

#define ELS_ELS_CONFIG_CIPHER_SUP_MASK           (0x1U)
#define ELS_ELS_CONFIG_CIPHER_SUP_SHIFT          (0U)
/*! cipher_sup - cipher command is supported */
#define ELS_ELS_CONFIG_CIPHER_SUP(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_CIPHER_SUP_SHIFT)) & ELS_ELS_CONFIG_CIPHER_SUP_MASK)

#define ELS_ELS_CONFIG_AUTH_CIPHER_SUP_MASK      (0x2U)
#define ELS_ELS_CONFIG_AUTH_CIPHER_SUP_SHIFT     (1U)
/*! auth_cipher_sup - auth_cipher command is supported */
#define ELS_ELS_CONFIG_AUTH_CIPHER_SUP(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_AUTH_CIPHER_SUP_SHIFT)) & ELS_ELS_CONFIG_AUTH_CIPHER_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED2_MASK            (0x4U)
#define ELS_ELS_CONFIG_RESERVED2_SHIFT           (2U)
/*! reserved2 - reserved */
#define ELS_ELS_CONFIG_RESERVED2(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED2_SHIFT)) & ELS_ELS_CONFIG_RESERVED2_MASK)

#define ELS_ELS_CONFIG_RESERVED3_MASK            (0x8U)
#define ELS_ELS_CONFIG_RESERVED3_SHIFT           (3U)
/*! reserved3 - reserved */
#define ELS_ELS_CONFIG_RESERVED3(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED3_SHIFT)) & ELS_ELS_CONFIG_RESERVED3_MASK)

#define ELS_ELS_CONFIG_ECSIGN_SUP_MASK           (0x10U)
#define ELS_ELS_CONFIG_ECSIGN_SUP_SHIFT          (4U)
/*! ecsign_sup - ecsign command is supported */
#define ELS_ELS_CONFIG_ECSIGN_SUP(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_ECSIGN_SUP_SHIFT)) & ELS_ELS_CONFIG_ECSIGN_SUP_MASK)

#define ELS_ELS_CONFIG_ECVFY_SUP_MASK            (0x20U)
#define ELS_ELS_CONFIG_ECVFY_SUP_SHIFT           (5U)
/*! ecvfy_sup - ecvfy command is supported */
#define ELS_ELS_CONFIG_ECVFY_SUP(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_ECVFY_SUP_SHIFT)) & ELS_ELS_CONFIG_ECVFY_SUP_MASK)

#define ELS_ELS_CONFIG_ECKXCH_SUP_MASK           (0x40U)
#define ELS_ELS_CONFIG_ECKXCH_SUP_SHIFT          (6U)
/*! eckxch_sup - dhkey_xch command is supported */
#define ELS_ELS_CONFIG_ECKXCH_SUP(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_ECKXCH_SUP_SHIFT)) & ELS_ELS_CONFIG_ECKXCH_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED7_MASK            (0x80U)
#define ELS_ELS_CONFIG_RESERVED7_SHIFT           (7U)
/*! reserved7 - reserved */
#define ELS_ELS_CONFIG_RESERVED7(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED7_SHIFT)) & ELS_ELS_CONFIG_RESERVED7_MASK)

#define ELS_ELS_CONFIG_KEYGEN_SUP_MASK           (0x100U)
#define ELS_ELS_CONFIG_KEYGEN_SUP_SHIFT          (8U)
/*! keygen_sup - keygen command is supported */
#define ELS_ELS_CONFIG_KEYGEN_SUP(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_KEYGEN_SUP_SHIFT)) & ELS_ELS_CONFIG_KEYGEN_SUP_MASK)

#define ELS_ELS_CONFIG_KEYIN_SUP_MASK            (0x200U)
#define ELS_ELS_CONFIG_KEYIN_SUP_SHIFT           (9U)
/*! keyin_sup - keyin command is supported */
#define ELS_ELS_CONFIG_KEYIN_SUP(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_KEYIN_SUP_SHIFT)) & ELS_ELS_CONFIG_KEYIN_SUP_MASK)

#define ELS_ELS_CONFIG_KEYOUT_SUP_MASK           (0x400U)
#define ELS_ELS_CONFIG_KEYOUT_SUP_SHIFT          (10U)
/*! keyout_sup - keyout command is supported */
#define ELS_ELS_CONFIG_KEYOUT_SUP(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_KEYOUT_SUP_SHIFT)) & ELS_ELS_CONFIG_KEYOUT_SUP_MASK)

#define ELS_ELS_CONFIG_KDELETE_SUP_MASK          (0x800U)
#define ELS_ELS_CONFIG_KDELETE_SUP_SHIFT         (11U)
/*! kdelete_sup - kdelete command is supported */
#define ELS_ELS_CONFIG_KDELETE_SUP(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_KDELETE_SUP_SHIFT)) & ELS_ELS_CONFIG_KDELETE_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED13_MASK           (0x2000U)
#define ELS_ELS_CONFIG_RESERVED13_SHIFT          (13U)
/*! reserved13 - reserved */
#define ELS_ELS_CONFIG_RESERVED13(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED13_SHIFT)) & ELS_ELS_CONFIG_RESERVED13_MASK)

#define ELS_ELS_CONFIG_RESERVED14_MASK           (0x4000U)
#define ELS_ELS_CONFIG_RESERVED14_SHIFT          (14U)
/*! reserved14 - reserved */
#define ELS_ELS_CONFIG_RESERVED14(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED14_SHIFT)) & ELS_ELS_CONFIG_RESERVED14_MASK)

#define ELS_ELS_CONFIG_RESERVED15_MASK           (0x8000U)
#define ELS_ELS_CONFIG_RESERVED15_SHIFT          (15U)
/*! reserved15 - reserved */
#define ELS_ELS_CONFIG_RESERVED15(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED15_SHIFT)) & ELS_ELS_CONFIG_RESERVED15_MASK)

#define ELS_ELS_CONFIG_CKDF_SUP_MASK             (0x10000U)
#define ELS_ELS_CONFIG_CKDF_SUP_SHIFT            (16U)
/*! ckdf_sup - ckdf command is supported */
#define ELS_ELS_CONFIG_CKDF_SUP(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_CKDF_SUP_SHIFT)) & ELS_ELS_CONFIG_CKDF_SUP_MASK)

#define ELS_ELS_CONFIG_HKDF_SUP_MASK             (0x20000U)
#define ELS_ELS_CONFIG_HKDF_SUP_SHIFT            (17U)
/*! hkdf_sup - hkdf command is supported */
#define ELS_ELS_CONFIG_HKDF_SUP(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_HKDF_SUP_SHIFT)) & ELS_ELS_CONFIG_HKDF_SUP_MASK)

#define ELS_ELS_CONFIG_TLS_INIT_SUP_MASK         (0x40000U)
#define ELS_ELS_CONFIG_TLS_INIT_SUP_SHIFT        (18U)
/*! tls_init_sup - tls_init command is supported */
#define ELS_ELS_CONFIG_TLS_INIT_SUP(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_TLS_INIT_SUP_SHIFT)) & ELS_ELS_CONFIG_TLS_INIT_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED19_MASK           (0x80000U)
#define ELS_ELS_CONFIG_RESERVED19_SHIFT          (19U)
/*! reserved19 - reserved */
#define ELS_ELS_CONFIG_RESERVED19(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED19_SHIFT)) & ELS_ELS_CONFIG_RESERVED19_MASK)

#define ELS_ELS_CONFIG_HASH_SUP_MASK             (0x100000U)
#define ELS_ELS_CONFIG_HASH_SUP_SHIFT            (20U)
/*! hash_sup - hash command is supported */
#define ELS_ELS_CONFIG_HASH_SUP(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_HASH_SUP_SHIFT)) & ELS_ELS_CONFIG_HASH_SUP_MASK)

#define ELS_ELS_CONFIG_HMAC_SUP_MASK             (0x200000U)
#define ELS_ELS_CONFIG_HMAC_SUP_SHIFT            (21U)
/*! hmac_sup - hmac command is supported */
#define ELS_ELS_CONFIG_HMAC_SUP(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_HMAC_SUP_SHIFT)) & ELS_ELS_CONFIG_HMAC_SUP_MASK)

#define ELS_ELS_CONFIG_CMAC_SUP_MASK             (0x400000U)
#define ELS_ELS_CONFIG_CMAC_SUP_SHIFT            (22U)
/*! cmac_sup - cmac command is supported */
#define ELS_ELS_CONFIG_CMAC_SUP(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_CMAC_SUP_SHIFT)) & ELS_ELS_CONFIG_CMAC_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED23_MASK           (0x800000U)
#define ELS_ELS_CONFIG_RESERVED23_SHIFT          (23U)
/*! reserved23 - reserved */
#define ELS_ELS_CONFIG_RESERVED23(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED23_SHIFT)) & ELS_ELS_CONFIG_RESERVED23_MASK)

#define ELS_ELS_CONFIG_RND_REQ_SUP_MASK          (0x1000000U)
#define ELS_ELS_CONFIG_RND_REQ_SUP_SHIFT         (24U)
/*! rnd_req_sup - rnd_req command is supported */
#define ELS_ELS_CONFIG_RND_REQ_SUP(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RND_REQ_SUP_SHIFT)) & ELS_ELS_CONFIG_RND_REQ_SUP_MASK)

#define ELS_ELS_CONFIG_DRBG_TEST_SUP_MASK        (0x2000000U)
#define ELS_ELS_CONFIG_DRBG_TEST_SUP_SHIFT       (25U)
/*! drbg_test_sup - drbg_test command is supported */
#define ELS_ELS_CONFIG_DRBG_TEST_SUP(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_DRBG_TEST_SUP_SHIFT)) & ELS_ELS_CONFIG_DRBG_TEST_SUP_MASK)

#define ELS_ELS_CONFIG_DTRNG_PRVL_CFG_LOAD_SUP_MASK (0x4000000U)
#define ELS_ELS_CONFIG_DTRNG_PRVL_CFG_LOAD_SUP_SHIFT (26U)
/*! dtrng_prvl_cfg_load_sup - dtrng_prvl_cfg_load command is supported */
#define ELS_ELS_CONFIG_DTRNG_PRVL_CFG_LOAD_SUP(x) (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_DTRNG_PRVL_CFG_LOAD_SUP_SHIFT)) & ELS_ELS_CONFIG_DTRNG_PRVL_CFG_LOAD_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED27_MASK           (0x8000000U)
#define ELS_ELS_CONFIG_RESERVED27_SHIFT          (27U)
/*! reserved27 - reserved */
#define ELS_ELS_CONFIG_RESERVED27(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED27_SHIFT)) & ELS_ELS_CONFIG_RESERVED27_MASK)

#define ELS_ELS_CONFIG_DTRNG_CFG_LOAD_SUP_MASK   (0x10000000U)
#define ELS_ELS_CONFIG_DTRNG_CFG_LOAD_SUP_SHIFT  (28U)
/*! dtrng_cfg_load_sup - dtrng_cfg_load command is supported */
#define ELS_ELS_CONFIG_DTRNG_CFG_LOAD_SUP(x)     (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_DTRNG_CFG_LOAD_SUP_SHIFT)) & ELS_ELS_CONFIG_DTRNG_CFG_LOAD_SUP_MASK)

#define ELS_ELS_CONFIG_DTRNG_EVAL_SUP_MASK       (0x20000000U)
#define ELS_ELS_CONFIG_DTRNG_EVAL_SUP_SHIFT      (29U)
/*! dtrng_eval_sup - dtrng_eval command is supported */
#define ELS_ELS_CONFIG_DTRNG_EVAL_SUP(x)         (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_DTRNG_EVAL_SUP_SHIFT)) & ELS_ELS_CONFIG_DTRNG_EVAL_SUP_MASK)

#define ELS_ELS_CONFIG_RESERVED30_MASK           (0x40000000U)
#define ELS_ELS_CONFIG_RESERVED30_SHIFT          (30U)
/*! reserved30 - reserved */
#define ELS_ELS_CONFIG_RESERVED30(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED30_SHIFT)) & ELS_ELS_CONFIG_RESERVED30_MASK)

#define ELS_ELS_CONFIG_RESERVED31_MASK           (0x80000000U)
#define ELS_ELS_CONFIG_RESERVED31_SHIFT          (31U)
/*! reserved31 - reserved */
#define ELS_ELS_CONFIG_RESERVED31(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CONFIG_RESERVED31_SHIFT)) & ELS_ELS_CONFIG_RESERVED31_MASK)
/*! @} */

/*! @name ELS_PRNG_DATOUT - PRNG SW Read Out Register */
/*! @{ */

#define ELS_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK     (0xFFFFFFFFU)
#define ELS_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT    (0U)
#define ELS_ELS_PRNG_DATOUT_PRNG_DATOUT(x)       (((uint32_t)(((uint32_t)(x)) << ELS_ELS_PRNG_DATOUT_PRNG_DATOUT_SHIFT)) & ELS_ELS_PRNG_DATOUT_PRNG_DATOUT_MASK)
/*! @} */

/*! @name ELS_CMDCRC_CTRL - CRC Configuration Register */
/*! @{ */

#define ELS_ELS_CMDCRC_CTRL_CMDCRC_RST_MASK      (0x1U)
#define ELS_ELS_CMDCRC_CTRL_CMDCRC_RST_SHIFT     (0U)
#define ELS_ELS_CMDCRC_CTRL_CMDCRC_RST(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CMDCRC_CTRL_CMDCRC_RST_SHIFT)) & ELS_ELS_CMDCRC_CTRL_CMDCRC_RST_MASK)

#define ELS_ELS_CMDCRC_CTRL_CMDCRC_EN_MASK       (0x2U)
#define ELS_ELS_CMDCRC_CTRL_CMDCRC_EN_SHIFT      (1U)
#define ELS_ELS_CMDCRC_CTRL_CMDCRC_EN(x)         (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CMDCRC_CTRL_CMDCRC_EN_SHIFT)) & ELS_ELS_CMDCRC_CTRL_CMDCRC_EN_MASK)
/*! @} */

/*! @name ELS_CMDCRC - Command CRC Value Register */
/*! @{ */

#define ELS_ELS_CMDCRC_CMDCRC_MASK               (0xFFFFFFFFU)
#define ELS_ELS_CMDCRC_CMDCRC_SHIFT              (0U)
#define ELS_ELS_CMDCRC_CMDCRC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_CMDCRC_CMDCRC_SHIFT)) & ELS_ELS_CMDCRC_CMDCRC_MASK)
/*! @} */

/*! @name ELS_SESSION_ID - Session ID Register */
/*! @{ */

#define ELS_ELS_SESSION_ID_SESSION_ID_MASK       (0xFFFFFFFFU)
#define ELS_ELS_SESSION_ID_SESSION_ID_SHIFT      (0U)
#define ELS_ELS_SESSION_ID_SESSION_ID(x)         (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SESSION_ID_SESSION_ID_SHIFT)) & ELS_ELS_SESSION_ID_SESSION_ID_MASK)
/*! @} */

/*! @name ELS_DMA_FIN_ADDR - Final DMA Address Register */
/*! @{ */

#define ELS_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_MASK   (0xFFFFFFFFU)
#define ELS_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_SHIFT  (0U)
#define ELS_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ELS_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_SHIFT)) & ELS_ELS_DMA_FIN_ADDR_DMA_FIN_ADDR_MASK)
/*! @} */

/*! @name ELS_MASTER_ID - Master ID Register */
/*! @{ */

#define ELS_ELS_MASTER_ID_MASTER_ID_MASK         (0x1FU)
#define ELS_ELS_MASTER_ID_MASTER_ID_SHIFT        (0U)
#define ELS_ELS_MASTER_ID_MASTER_ID(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_MASTER_ID_MASTER_ID_SHIFT)) & ELS_ELS_MASTER_ID_MASTER_ID_MASK)
/*! @} */

/*! @name ELS_KIDX2 - Keystore Index 2 Register */
/*! @{ */

#define ELS_ELS_KIDX2_KIDX2_MASK                 (0x1FU)
#define ELS_ELS_KIDX2_KIDX2_SHIFT                (0U)
#define ELS_ELS_KIDX2_KIDX2(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KIDX2_KIDX2_SHIFT)) & ELS_ELS_KIDX2_KIDX2_MASK)
/*! @} */

/*! @name ELS_SHA2_STATUS - SHA2 Status Register */
/*! @{ */

#define ELS_ELS_SHA2_STATUS_SHA2_BUSY_MASK       (0x1U)
#define ELS_ELS_SHA2_STATUS_SHA2_BUSY_SHIFT      (0U)
#define ELS_ELS_SHA2_STATUS_SHA2_BUSY(x)         (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_STATUS_SHA2_BUSY_SHIFT)) & ELS_ELS_SHA2_STATUS_SHA2_BUSY_MASK)
/*! @} */

/*! @name ELS_SHA2_CTRL - SHA2 Control Register */
/*! @{ */

#define ELS_ELS_SHA2_CTRL_SHA2_START_MASK        (0x1U)
#define ELS_ELS_SHA2_CTRL_SHA2_START_SHIFT       (0U)
/*! sha2_start - Write to 1 to Init the SHA2 Module */
#define ELS_ELS_SHA2_CTRL_SHA2_START(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_START_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_START_MASK)

#define ELS_ELS_SHA2_CTRL_SHA2_RST_MASK          (0x2U)
#define ELS_ELS_SHA2_CTRL_SHA2_RST_SHIFT         (1U)
/*! sha2_rst - Write to 1 to Reset a SHA2 operation */
#define ELS_ELS_SHA2_CTRL_SHA2_RST(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_RST_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_RST_MASK)

#define ELS_ELS_SHA2_CTRL_SHA2_INIT_MASK         (0x4U)
#define ELS_ELS_SHA2_CTRL_SHA2_INIT_SHIFT        (2U)
/*! sha2_init - Write to 1 to Init the SHA2 Kernel */
#define ELS_ELS_SHA2_CTRL_SHA2_INIT(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_INIT_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_INIT_MASK)

#define ELS_ELS_SHA2_CTRL_SHA2_LOAD_MASK         (0x8U)
#define ELS_ELS_SHA2_CTRL_SHA2_LOAD_SHIFT        (3U)
/*! sha2_load - Write to 1 to Load the SHA2 Kernel */
#define ELS_ELS_SHA2_CTRL_SHA2_LOAD(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_LOAD_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_LOAD_MASK)

#define ELS_ELS_SHA2_CTRL_SHA2_MODE_MASK         (0x30U)
#define ELS_ELS_SHA2_CTRL_SHA2_MODE_SHIFT        (4U)
/*! sha2_mode - SHA2 MODE: */
#define ELS_ELS_SHA2_CTRL_SHA2_MODE(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_MODE_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_MODE_MASK)

#define ELS_ELS_SHA2_CTRL_CTRL_RSVD1_MASK        (0x1C0U)
#define ELS_ELS_SHA2_CTRL_CTRL_RSVD1_SHIFT       (6U)
/*! ctrl_rsvd1 - r-eserved */
#define ELS_ELS_SHA2_CTRL_CTRL_RSVD1(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_CTRL_RSVD1_SHIFT)) & ELS_ELS_SHA2_CTRL_CTRL_RSVD1_MASK)

#define ELS_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_MASK   (0x200U)
#define ELS_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_SHIFT  (9U)
/*! sha2_byte_order - Write to 1 to Reverse byte endianess */
#define ELS_ELS_SHA2_CTRL_SHA2_BYTE_ORDER(x)     (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_SHIFT)) & ELS_ELS_SHA2_CTRL_SHA2_BYTE_ORDER_MASK)

#define ELS_ELS_SHA2_CTRL_CTRL_RSVD_MASK         (0xFFFFFC00U)
#define ELS_ELS_SHA2_CTRL_CTRL_RSVD_SHIFT        (10U)
/*! ctrl_rsvd - r-eserved */
#define ELS_ELS_SHA2_CTRL_CTRL_RSVD(x)           (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_CTRL_CTRL_RSVD_SHIFT)) & ELS_ELS_SHA2_CTRL_CTRL_RSVD_MASK)
/*! @} */

/*! @name ELS_SHA2_DIN - SHA_DATA IN 0 Register */
/*! @{ */

#define ELS_ELS_SHA2_DIN_SHA_DATIN_MASK          (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DIN_SHA_DATIN_SHIFT         (0U)
#define ELS_ELS_SHA2_DIN_SHA_DATIN(x)            (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DIN_SHA_DATIN_SHIFT)) & ELS_ELS_SHA2_DIN_SHA_DATIN_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT0 - SHA_DATA Out 0 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT0_SHA_DATA0_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT0_SHA_DATA0_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT0_SHA_DATA0(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT0_SHA_DATA0_SHIFT)) & ELS_ELS_SHA2_DOUT0_SHA_DATA0_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT1 - SHA_DATA Out 1 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT1_SHA_DATA1_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT1_SHA_DATA1_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT1_SHA_DATA1(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT1_SHA_DATA1_SHIFT)) & ELS_ELS_SHA2_DOUT1_SHA_DATA1_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT2 - SHA_DATA Out 2 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT2_SHA_DATA2_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT2_SHA_DATA2_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT2_SHA_DATA2(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT2_SHA_DATA2_SHIFT)) & ELS_ELS_SHA2_DOUT2_SHA_DATA2_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT3 - SHA_DATA Out 3 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT3_SHA_DATA3_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT3_SHA_DATA3_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT3_SHA_DATA3(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT3_SHA_DATA3_SHIFT)) & ELS_ELS_SHA2_DOUT3_SHA_DATA3_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT4 - SHA_DATA Out 4 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT4_SHA_DATA4_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT4_SHA_DATA4_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT4_SHA_DATA4(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT4_SHA_DATA4_SHIFT)) & ELS_ELS_SHA2_DOUT4_SHA_DATA4_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT5 - SHA_DATA Out 5 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT5_SHA_DATA5_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT5_SHA_DATA5_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT5_SHA_DATA5(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT5_SHA_DATA5_SHIFT)) & ELS_ELS_SHA2_DOUT5_SHA_DATA5_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT6 - SHA_DATA Out 6 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT6_SHA_DATA6_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT6_SHA_DATA6_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT6_SHA_DATA6(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT6_SHA_DATA6_SHIFT)) & ELS_ELS_SHA2_DOUT6_SHA_DATA6_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT7 - SHA_DATA Out 7 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT7_SHA_DATA7_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT7_SHA_DATA7_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT7_SHA_DATA7(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT7_SHA_DATA7_SHIFT)) & ELS_ELS_SHA2_DOUT7_SHA_DATA7_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT8 - SHA_DATA Out 8 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT8_SHA_DATA8_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT8_SHA_DATA8_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT8_SHA_DATA8(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT8_SHA_DATA8_SHIFT)) & ELS_ELS_SHA2_DOUT8_SHA_DATA8_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT9 - SHA_DATA Out 9 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT9_SHA_DATA9_MASK        (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT9_SHA_DATA9_SHIFT       (0U)
#define ELS_ELS_SHA2_DOUT9_SHA_DATA9(x)          (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT9_SHA_DATA9_SHIFT)) & ELS_ELS_SHA2_DOUT9_SHA_DATA9_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT10 - SHA_DATA Out 10 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT10_SHA_DATA10_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT10_SHA_DATA10_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT10_SHA_DATA10(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT10_SHA_DATA10_SHIFT)) & ELS_ELS_SHA2_DOUT10_SHA_DATA10_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT11 - SHA_DATA Out 11 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT11_SHA_DATA11_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT11_SHA_DATA11_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT11_SHA_DATA11(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT11_SHA_DATA11_SHIFT)) & ELS_ELS_SHA2_DOUT11_SHA_DATA11_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT12 - SHA_DATA Out 12 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT12_SHA_DATA12_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT12_SHA_DATA12_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT12_SHA_DATA12(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT12_SHA_DATA12_SHIFT)) & ELS_ELS_SHA2_DOUT12_SHA_DATA12_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT13 - SHA_DATA Out 13 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT13_SHA_DATA13_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT13_SHA_DATA13_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT13_SHA_DATA13(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT13_SHA_DATA13_SHIFT)) & ELS_ELS_SHA2_DOUT13_SHA_DATA13_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT14 - SHA_DATA Out 14 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT14_SHA_DATA14_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT14_SHA_DATA14_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT14_SHA_DATA14(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT14_SHA_DATA14_SHIFT)) & ELS_ELS_SHA2_DOUT14_SHA_DATA14_MASK)
/*! @} */

/*! @name ELS_SHA2_DOUT15 - SHA_DATA Out 15 Register */
/*! @{ */

#define ELS_ELS_SHA2_DOUT15_SHA_DATA15_MASK      (0xFFFFFFFFU)
#define ELS_ELS_SHA2_DOUT15_SHA_DATA15_SHIFT     (0U)
#define ELS_ELS_SHA2_DOUT15_SHA_DATA15(x)        (((uint32_t)(((uint32_t)(x)) << ELS_ELS_SHA2_DOUT15_SHA_DATA15_SHIFT)) & ELS_ELS_SHA2_DOUT15_SHA_DATA15_MASK)
/*! @} */

/*! @name ELS_KS0 - Status Register */
/*! @{ */

#define ELS_ELS_KS0_KS0_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS0_KS0_KSIZE_SHIFT              (0U)
/*! KS0_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS0_KS0_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_KSIZE_SHIFT)) & ELS_ELS_KS0_KS0_KSIZE_MASK)

#define ELS_ELS_KS0_KS0_KACT_MASK                (0x20U)
#define ELS_ELS_KS0_KS0_KACT_SHIFT               (5U)
#define ELS_ELS_KS0_KS0_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_KACT_SHIFT)) & ELS_ELS_KS0_KS0_KACT_MASK)

#define ELS_ELS_KS0_KS0_KBASE_MASK               (0x40U)
#define ELS_ELS_KS0_KS0_KBASE_SHIFT              (6U)
#define ELS_ELS_KS0_KS0_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_KBASE_SHIFT)) & ELS_ELS_KS0_KS0_KBASE_MASK)

#define ELS_ELS_KS0_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS0_KS0_FGP_SHIFT                (7U)
#define ELS_ELS_KS0_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_FGP_SHIFT)) & ELS_ELS_KS0_KS0_FGP_MASK)

#define ELS_ELS_KS0_KS0_FRTN_MASK                (0x100U)
#define ELS_ELS_KS0_KS0_FRTN_SHIFT               (8U)
#define ELS_ELS_KS0_KS0_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_FRTN_SHIFT)) & ELS_ELS_KS0_KS0_FRTN_MASK)

#define ELS_ELS_KS0_KS0_FHWO_MASK                (0x200U)
#define ELS_ELS_KS0_KS0_FHWO_SHIFT               (9U)
#define ELS_ELS_KS0_KS0_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_FHWO_SHIFT)) & ELS_ELS_KS0_KS0_FHWO_MASK)

#define ELS_ELS_KS0_KS0_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS0_KS0_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS0_KS0_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UKPUK_SHIFT)) & ELS_ELS_KS0_KS0_UKPUK_MASK)

#define ELS_ELS_KS0_KS0_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS0_KS0_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS0_KS0_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UTECDH_SHIFT)) & ELS_ELS_KS0_KS0_UTECDH_MASK)

#define ELS_ELS_KS0_KS0_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS0_KS0_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS0_KS0_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UCMAC_SHIFT)) & ELS_ELS_KS0_KS0_UCMAC_MASK)

#define ELS_ELS_KS0_KS0_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS0_KS0_UKSK_SHIFT               (14U)
#define ELS_ELS_KS0_KS0_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UKSK_SHIFT)) & ELS_ELS_KS0_KS0_UKSK_MASK)

#define ELS_ELS_KS0_KS0_URTF_MASK                (0x8000U)
#define ELS_ELS_KS0_KS0_URTF_SHIFT               (15U)
#define ELS_ELS_KS0_KS0_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_URTF_SHIFT)) & ELS_ELS_KS0_KS0_URTF_MASK)

#define ELS_ELS_KS0_KS0_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS0_KS0_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS0_KS0_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UCKDF_SHIFT)) & ELS_ELS_KS0_KS0_UCKDF_MASK)

#define ELS_ELS_KS0_KS0_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS0_KS0_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS0_KS0_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UHKDF_SHIFT)) & ELS_ELS_KS0_KS0_UHKDF_MASK)

#define ELS_ELS_KS0_KS0_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS0_KS0_UECSG_SHIFT              (18U)
#define ELS_ELS_KS0_KS0_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UECSG_SHIFT)) & ELS_ELS_KS0_KS0_UECSG_MASK)

#define ELS_ELS_KS0_KS0_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS0_KS0_UECDH_SHIFT              (19U)
#define ELS_ELS_KS0_KS0_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UECDH_SHIFT)) & ELS_ELS_KS0_KS0_UECDH_MASK)

#define ELS_ELS_KS0_KS0_UAES_MASK                (0x100000U)
#define ELS_ELS_KS0_KS0_UAES_SHIFT               (20U)
#define ELS_ELS_KS0_KS0_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UAES_SHIFT)) & ELS_ELS_KS0_KS0_UAES_MASK)

#define ELS_ELS_KS0_KS0_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS0_KS0_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS0_KS0_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UHMAC_SHIFT)) & ELS_ELS_KS0_KS0_UHMAC_MASK)

#define ELS_ELS_KS0_KS0_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS0_KS0_UKWK_SHIFT               (22U)
#define ELS_ELS_KS0_KS0_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UKWK_SHIFT)) & ELS_ELS_KS0_KS0_UKWK_MASK)

#define ELS_ELS_KS0_KS0_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS0_KS0_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS0_KS0_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UKUOK_SHIFT)) & ELS_ELS_KS0_KS0_UKUOK_MASK)

#define ELS_ELS_KS0_KS0_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS0_KS0_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS0_KS0_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UTLSPMS_SHIFT)) & ELS_ELS_KS0_KS0_UTLSPMS_MASK)

#define ELS_ELS_KS0_KS0_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS0_KS0_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS0_KS0_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UTLSMS_SHIFT)) & ELS_ELS_KS0_KS0_UTLSMS_MASK)

#define ELS_ELS_KS0_KS0_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS0_KS0_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS0_KS0_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UKGSRC_SHIFT)) & ELS_ELS_KS0_KS0_UKGSRC_MASK)

#define ELS_ELS_KS0_KS0_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS0_KS0_UHWO_SHIFT               (27U)
#define ELS_ELS_KS0_KS0_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UHWO_SHIFT)) & ELS_ELS_KS0_KS0_UHWO_MASK)

#define ELS_ELS_KS0_KS0_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS0_KS0_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS0_KS0_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UWRPOK_SHIFT)) & ELS_ELS_KS0_KS0_UWRPOK_MASK)

#define ELS_ELS_KS0_KS0_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS0_KS0_UDUK_SHIFT               (29U)
#define ELS_ELS_KS0_KS0_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UDUK_SHIFT)) & ELS_ELS_KS0_KS0_UDUK_MASK)

#define ELS_ELS_KS0_KS0_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS0_KS0_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS0_KS0_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_UPPROT_SHIFT)) & ELS_ELS_KS0_KS0_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS1 - Status Register */
/*! @{ */

#define ELS_ELS_KS1_KS1_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS1_KS1_KSIZE_SHIFT              (0U)
/*! KS1_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS1_KS1_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_KSIZE_SHIFT)) & ELS_ELS_KS1_KS1_KSIZE_MASK)

#define ELS_ELS_KS1_KS1_KACT_MASK                (0x20U)
#define ELS_ELS_KS1_KS1_KACT_SHIFT               (5U)
#define ELS_ELS_KS1_KS1_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_KACT_SHIFT)) & ELS_ELS_KS1_KS1_KACT_MASK)

#define ELS_ELS_KS1_KS1_KBASE_MASK               (0x40U)
#define ELS_ELS_KS1_KS1_KBASE_SHIFT              (6U)
#define ELS_ELS_KS1_KS1_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_KBASE_SHIFT)) & ELS_ELS_KS1_KS1_KBASE_MASK)

#define ELS_ELS_KS1_KS1_FGP_MASK                 (0x80U)
#define ELS_ELS_KS1_KS1_FGP_SHIFT                (7U)
#define ELS_ELS_KS1_KS1_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_FGP_SHIFT)) & ELS_ELS_KS1_KS1_FGP_MASK)

#define ELS_ELS_KS1_KS1_FRTN_MASK                (0x100U)
#define ELS_ELS_KS1_KS1_FRTN_SHIFT               (8U)
#define ELS_ELS_KS1_KS1_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_FRTN_SHIFT)) & ELS_ELS_KS1_KS1_FRTN_MASK)

#define ELS_ELS_KS1_KS1_FHWO_MASK                (0x200U)
#define ELS_ELS_KS1_KS1_FHWO_SHIFT               (9U)
#define ELS_ELS_KS1_KS1_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_FHWO_SHIFT)) & ELS_ELS_KS1_KS1_FHWO_MASK)

#define ELS_ELS_KS1_KS1_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS1_KS1_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS1_KS1_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UKPUK_SHIFT)) & ELS_ELS_KS1_KS1_UKPUK_MASK)

#define ELS_ELS_KS1_KS1_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS1_KS1_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS1_KS1_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UTECDH_SHIFT)) & ELS_ELS_KS1_KS1_UTECDH_MASK)

#define ELS_ELS_KS1_KS1_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS1_KS1_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS1_KS1_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UCMAC_SHIFT)) & ELS_ELS_KS1_KS1_UCMAC_MASK)

#define ELS_ELS_KS1_KS1_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS1_KS1_UKSK_SHIFT               (14U)
#define ELS_ELS_KS1_KS1_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UKSK_SHIFT)) & ELS_ELS_KS1_KS1_UKSK_MASK)

#define ELS_ELS_KS1_KS1_URTF_MASK                (0x8000U)
#define ELS_ELS_KS1_KS1_URTF_SHIFT               (15U)
#define ELS_ELS_KS1_KS1_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_URTF_SHIFT)) & ELS_ELS_KS1_KS1_URTF_MASK)

#define ELS_ELS_KS1_KS1_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS1_KS1_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS1_KS1_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UCKDF_SHIFT)) & ELS_ELS_KS1_KS1_UCKDF_MASK)

#define ELS_ELS_KS1_KS1_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS1_KS1_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS1_KS1_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UHKDF_SHIFT)) & ELS_ELS_KS1_KS1_UHKDF_MASK)

#define ELS_ELS_KS1_KS1_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS1_KS1_UECSG_SHIFT              (18U)
#define ELS_ELS_KS1_KS1_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UECSG_SHIFT)) & ELS_ELS_KS1_KS1_UECSG_MASK)

#define ELS_ELS_KS1_KS1_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS1_KS1_UECDH_SHIFT              (19U)
#define ELS_ELS_KS1_KS1_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UECDH_SHIFT)) & ELS_ELS_KS1_KS1_UECDH_MASK)

#define ELS_ELS_KS1_KS1_UAES_MASK                (0x100000U)
#define ELS_ELS_KS1_KS1_UAES_SHIFT               (20U)
#define ELS_ELS_KS1_KS1_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UAES_SHIFT)) & ELS_ELS_KS1_KS1_UAES_MASK)

#define ELS_ELS_KS1_KS1_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS1_KS1_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS1_KS1_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UHMAC_SHIFT)) & ELS_ELS_KS1_KS1_UHMAC_MASK)

#define ELS_ELS_KS1_KS1_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS1_KS1_UKWK_SHIFT               (22U)
#define ELS_ELS_KS1_KS1_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UKWK_SHIFT)) & ELS_ELS_KS1_KS1_UKWK_MASK)

#define ELS_ELS_KS1_KS1_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS1_KS1_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS1_KS1_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UKUOK_SHIFT)) & ELS_ELS_KS1_KS1_UKUOK_MASK)

#define ELS_ELS_KS1_KS1_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS1_KS1_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS1_KS1_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UTLSPMS_SHIFT)) & ELS_ELS_KS1_KS1_UTLSPMS_MASK)

#define ELS_ELS_KS1_KS1_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS1_KS1_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS1_KS1_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UTLSMS_SHIFT)) & ELS_ELS_KS1_KS1_UTLSMS_MASK)

#define ELS_ELS_KS1_KS1_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS1_KS1_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS1_KS1_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UKGSRC_SHIFT)) & ELS_ELS_KS1_KS1_UKGSRC_MASK)

#define ELS_ELS_KS1_KS1_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS1_KS1_UHWO_SHIFT               (27U)
#define ELS_ELS_KS1_KS1_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UHWO_SHIFT)) & ELS_ELS_KS1_KS1_UHWO_MASK)

#define ELS_ELS_KS1_KS1_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS1_KS1_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS1_KS1_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UWRPOK_SHIFT)) & ELS_ELS_KS1_KS1_UWRPOK_MASK)

#define ELS_ELS_KS1_KS1_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS1_KS1_UDUK_SHIFT               (29U)
#define ELS_ELS_KS1_KS1_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UDUK_SHIFT)) & ELS_ELS_KS1_KS1_UDUK_MASK)

#define ELS_ELS_KS1_KS1_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS1_KS1_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS1_KS1_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS1_UPPROT_SHIFT)) & ELS_ELS_KS1_KS1_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS2 - Status Register */
/*! @{ */

#define ELS_ELS_KS2_KS2_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS2_KS2_KSIZE_SHIFT              (0U)
/*! KS2_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS2_KS2_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_KSIZE_SHIFT)) & ELS_ELS_KS2_KS2_KSIZE_MASK)

#define ELS_ELS_KS2_KS2_KACT_MASK                (0x20U)
#define ELS_ELS_KS2_KS2_KACT_SHIFT               (5U)
#define ELS_ELS_KS2_KS2_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_KACT_SHIFT)) & ELS_ELS_KS2_KS2_KACT_MASK)

#define ELS_ELS_KS2_KS2_KBASE_MASK               (0x40U)
#define ELS_ELS_KS2_KS2_KBASE_SHIFT              (6U)
#define ELS_ELS_KS2_KS2_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_KBASE_SHIFT)) & ELS_ELS_KS2_KS2_KBASE_MASK)

#define ELS_ELS_KS2_KS2_FGP_MASK                 (0x80U)
#define ELS_ELS_KS2_KS2_FGP_SHIFT                (7U)
#define ELS_ELS_KS2_KS2_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_FGP_SHIFT)) & ELS_ELS_KS2_KS2_FGP_MASK)

#define ELS_ELS_KS2_KS2_FRTN_MASK                (0x100U)
#define ELS_ELS_KS2_KS2_FRTN_SHIFT               (8U)
#define ELS_ELS_KS2_KS2_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_FRTN_SHIFT)) & ELS_ELS_KS2_KS2_FRTN_MASK)

#define ELS_ELS_KS2_KS2_FHWO_MASK                (0x200U)
#define ELS_ELS_KS2_KS2_FHWO_SHIFT               (9U)
#define ELS_ELS_KS2_KS2_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_FHWO_SHIFT)) & ELS_ELS_KS2_KS2_FHWO_MASK)

#define ELS_ELS_KS2_KS2_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS2_KS2_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS2_KS2_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UKPUK_SHIFT)) & ELS_ELS_KS2_KS2_UKPUK_MASK)

#define ELS_ELS_KS2_KS2_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS2_KS2_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS2_KS2_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UTECDH_SHIFT)) & ELS_ELS_KS2_KS2_UTECDH_MASK)

#define ELS_ELS_KS2_KS2_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS2_KS2_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS2_KS2_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UCMAC_SHIFT)) & ELS_ELS_KS2_KS2_UCMAC_MASK)

#define ELS_ELS_KS2_KS2_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS2_KS2_UKSK_SHIFT               (14U)
#define ELS_ELS_KS2_KS2_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UKSK_SHIFT)) & ELS_ELS_KS2_KS2_UKSK_MASK)

#define ELS_ELS_KS2_KS2_URTF_MASK                (0x8000U)
#define ELS_ELS_KS2_KS2_URTF_SHIFT               (15U)
#define ELS_ELS_KS2_KS2_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_URTF_SHIFT)) & ELS_ELS_KS2_KS2_URTF_MASK)

#define ELS_ELS_KS2_KS2_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS2_KS2_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS2_KS2_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UCKDF_SHIFT)) & ELS_ELS_KS2_KS2_UCKDF_MASK)

#define ELS_ELS_KS2_KS2_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS2_KS2_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS2_KS2_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UHKDF_SHIFT)) & ELS_ELS_KS2_KS2_UHKDF_MASK)

#define ELS_ELS_KS2_KS2_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS2_KS2_UECSG_SHIFT              (18U)
#define ELS_ELS_KS2_KS2_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UECSG_SHIFT)) & ELS_ELS_KS2_KS2_UECSG_MASK)

#define ELS_ELS_KS2_KS2_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS2_KS2_UECDH_SHIFT              (19U)
#define ELS_ELS_KS2_KS2_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UECDH_SHIFT)) & ELS_ELS_KS2_KS2_UECDH_MASK)

#define ELS_ELS_KS2_KS2_UAES_MASK                (0x100000U)
#define ELS_ELS_KS2_KS2_UAES_SHIFT               (20U)
#define ELS_ELS_KS2_KS2_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UAES_SHIFT)) & ELS_ELS_KS2_KS2_UAES_MASK)

#define ELS_ELS_KS2_KS2_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS2_KS2_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS2_KS2_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UHMAC_SHIFT)) & ELS_ELS_KS2_KS2_UHMAC_MASK)

#define ELS_ELS_KS2_KS2_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS2_KS2_UKWK_SHIFT               (22U)
#define ELS_ELS_KS2_KS2_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UKWK_SHIFT)) & ELS_ELS_KS2_KS2_UKWK_MASK)

#define ELS_ELS_KS2_KS2_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS2_KS2_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS2_KS2_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UKUOK_SHIFT)) & ELS_ELS_KS2_KS2_UKUOK_MASK)

#define ELS_ELS_KS2_KS2_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS2_KS2_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS2_KS2_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UTLSPMS_SHIFT)) & ELS_ELS_KS2_KS2_UTLSPMS_MASK)

#define ELS_ELS_KS2_KS2_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS2_KS2_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS2_KS2_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UTLSMS_SHIFT)) & ELS_ELS_KS2_KS2_UTLSMS_MASK)

#define ELS_ELS_KS2_KS2_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS2_KS2_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS2_KS2_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UKGSRC_SHIFT)) & ELS_ELS_KS2_KS2_UKGSRC_MASK)

#define ELS_ELS_KS2_KS2_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS2_KS2_UHWO_SHIFT               (27U)
#define ELS_ELS_KS2_KS2_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UHWO_SHIFT)) & ELS_ELS_KS2_KS2_UHWO_MASK)

#define ELS_ELS_KS2_KS2_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS2_KS2_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS2_KS2_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UWRPOK_SHIFT)) & ELS_ELS_KS2_KS2_UWRPOK_MASK)

#define ELS_ELS_KS2_KS2_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS2_KS2_UDUK_SHIFT               (29U)
#define ELS_ELS_KS2_KS2_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UDUK_SHIFT)) & ELS_ELS_KS2_KS2_UDUK_MASK)

#define ELS_ELS_KS2_KS2_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS2_KS2_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS2_KS2_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS2_UPPROT_SHIFT)) & ELS_ELS_KS2_KS2_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS3 - Status Register */
/*! @{ */

#define ELS_ELS_KS3_KS3_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS3_KS3_KSIZE_SHIFT              (0U)
/*! KS3_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS3_KS3_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_KSIZE_SHIFT)) & ELS_ELS_KS3_KS3_KSIZE_MASK)

#define ELS_ELS_KS3_KS3_KACT_MASK                (0x20U)
#define ELS_ELS_KS3_KS3_KACT_SHIFT               (5U)
#define ELS_ELS_KS3_KS3_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_KACT_SHIFT)) & ELS_ELS_KS3_KS3_KACT_MASK)

#define ELS_ELS_KS3_KS3_KBASE_MASK               (0x40U)
#define ELS_ELS_KS3_KS3_KBASE_SHIFT              (6U)
#define ELS_ELS_KS3_KS3_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_KBASE_SHIFT)) & ELS_ELS_KS3_KS3_KBASE_MASK)

#define ELS_ELS_KS3_KS3_FGP_MASK                 (0x80U)
#define ELS_ELS_KS3_KS3_FGP_SHIFT                (7U)
#define ELS_ELS_KS3_KS3_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_FGP_SHIFT)) & ELS_ELS_KS3_KS3_FGP_MASK)

#define ELS_ELS_KS3_KS3_FRTN_MASK                (0x100U)
#define ELS_ELS_KS3_KS3_FRTN_SHIFT               (8U)
#define ELS_ELS_KS3_KS3_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_FRTN_SHIFT)) & ELS_ELS_KS3_KS3_FRTN_MASK)

#define ELS_ELS_KS3_KS3_FHWO_MASK                (0x200U)
#define ELS_ELS_KS3_KS3_FHWO_SHIFT               (9U)
#define ELS_ELS_KS3_KS3_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_FHWO_SHIFT)) & ELS_ELS_KS3_KS3_FHWO_MASK)

#define ELS_ELS_KS3_KS3_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS3_KS3_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS3_KS3_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UKPUK_SHIFT)) & ELS_ELS_KS3_KS3_UKPUK_MASK)

#define ELS_ELS_KS3_KS3_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS3_KS3_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS3_KS3_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UTECDH_SHIFT)) & ELS_ELS_KS3_KS3_UTECDH_MASK)

#define ELS_ELS_KS3_KS3_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS3_KS3_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS3_KS3_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UCMAC_SHIFT)) & ELS_ELS_KS3_KS3_UCMAC_MASK)

#define ELS_ELS_KS3_KS3_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS3_KS3_UKSK_SHIFT               (14U)
#define ELS_ELS_KS3_KS3_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UKSK_SHIFT)) & ELS_ELS_KS3_KS3_UKSK_MASK)

#define ELS_ELS_KS3_KS3_URTF_MASK                (0x8000U)
#define ELS_ELS_KS3_KS3_URTF_SHIFT               (15U)
#define ELS_ELS_KS3_KS3_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_URTF_SHIFT)) & ELS_ELS_KS3_KS3_URTF_MASK)

#define ELS_ELS_KS3_KS3_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS3_KS3_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS3_KS3_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UCKDF_SHIFT)) & ELS_ELS_KS3_KS3_UCKDF_MASK)

#define ELS_ELS_KS3_KS3_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS3_KS3_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS3_KS3_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UHKDF_SHIFT)) & ELS_ELS_KS3_KS3_UHKDF_MASK)

#define ELS_ELS_KS3_KS3_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS3_KS3_UECSG_SHIFT              (18U)
#define ELS_ELS_KS3_KS3_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UECSG_SHIFT)) & ELS_ELS_KS3_KS3_UECSG_MASK)

#define ELS_ELS_KS3_KS3_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS3_KS3_UECDH_SHIFT              (19U)
#define ELS_ELS_KS3_KS3_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UECDH_SHIFT)) & ELS_ELS_KS3_KS3_UECDH_MASK)

#define ELS_ELS_KS3_KS3_UAES_MASK                (0x100000U)
#define ELS_ELS_KS3_KS3_UAES_SHIFT               (20U)
#define ELS_ELS_KS3_KS3_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UAES_SHIFT)) & ELS_ELS_KS3_KS3_UAES_MASK)

#define ELS_ELS_KS3_KS3_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS3_KS3_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS3_KS3_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UHMAC_SHIFT)) & ELS_ELS_KS3_KS3_UHMAC_MASK)

#define ELS_ELS_KS3_KS3_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS3_KS3_UKWK_SHIFT               (22U)
#define ELS_ELS_KS3_KS3_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UKWK_SHIFT)) & ELS_ELS_KS3_KS3_UKWK_MASK)

#define ELS_ELS_KS3_KS3_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS3_KS3_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS3_KS3_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UKUOK_SHIFT)) & ELS_ELS_KS3_KS3_UKUOK_MASK)

#define ELS_ELS_KS3_KS3_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS3_KS3_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS3_KS3_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UTLSPMS_SHIFT)) & ELS_ELS_KS3_KS3_UTLSPMS_MASK)

#define ELS_ELS_KS3_KS3_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS3_KS3_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS3_KS3_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UTLSMS_SHIFT)) & ELS_ELS_KS3_KS3_UTLSMS_MASK)

#define ELS_ELS_KS3_KS3_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS3_KS3_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS3_KS3_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UKGSRC_SHIFT)) & ELS_ELS_KS3_KS3_UKGSRC_MASK)

#define ELS_ELS_KS3_KS3_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS3_KS3_UHWO_SHIFT               (27U)
#define ELS_ELS_KS3_KS3_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UHWO_SHIFT)) & ELS_ELS_KS3_KS3_UHWO_MASK)

#define ELS_ELS_KS3_KS3_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS3_KS3_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS3_KS3_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UWRPOK_SHIFT)) & ELS_ELS_KS3_KS3_UWRPOK_MASK)

#define ELS_ELS_KS3_KS3_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS3_KS3_UDUK_SHIFT               (29U)
#define ELS_ELS_KS3_KS3_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UDUK_SHIFT)) & ELS_ELS_KS3_KS3_UDUK_MASK)

#define ELS_ELS_KS3_KS3_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS3_KS3_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS3_KS3_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS3_UPPROT_SHIFT)) & ELS_ELS_KS3_KS3_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS4 - Status Register */
/*! @{ */

#define ELS_ELS_KS4_KS4_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS4_KS4_KSIZE_SHIFT              (0U)
/*! KS4_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS4_KS4_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_KSIZE_SHIFT)) & ELS_ELS_KS4_KS4_KSIZE_MASK)

#define ELS_ELS_KS4_KS4_KACT_MASK                (0x20U)
#define ELS_ELS_KS4_KS4_KACT_SHIFT               (5U)
#define ELS_ELS_KS4_KS4_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_KACT_SHIFT)) & ELS_ELS_KS4_KS4_KACT_MASK)

#define ELS_ELS_KS4_KS4_KBASE_MASK               (0x40U)
#define ELS_ELS_KS4_KS4_KBASE_SHIFT              (6U)
#define ELS_ELS_KS4_KS4_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_KBASE_SHIFT)) & ELS_ELS_KS4_KS4_KBASE_MASK)

#define ELS_ELS_KS4_KS4_FGP_MASK                 (0x80U)
#define ELS_ELS_KS4_KS4_FGP_SHIFT                (7U)
#define ELS_ELS_KS4_KS4_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_FGP_SHIFT)) & ELS_ELS_KS4_KS4_FGP_MASK)

#define ELS_ELS_KS4_KS4_FRTN_MASK                (0x100U)
#define ELS_ELS_KS4_KS4_FRTN_SHIFT               (8U)
#define ELS_ELS_KS4_KS4_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_FRTN_SHIFT)) & ELS_ELS_KS4_KS4_FRTN_MASK)

#define ELS_ELS_KS4_KS4_FHWO_MASK                (0x200U)
#define ELS_ELS_KS4_KS4_FHWO_SHIFT               (9U)
#define ELS_ELS_KS4_KS4_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_FHWO_SHIFT)) & ELS_ELS_KS4_KS4_FHWO_MASK)

#define ELS_ELS_KS4_KS4_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS4_KS4_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS4_KS4_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UKPUK_SHIFT)) & ELS_ELS_KS4_KS4_UKPUK_MASK)

#define ELS_ELS_KS4_KS4_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS4_KS4_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS4_KS4_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UTECDH_SHIFT)) & ELS_ELS_KS4_KS4_UTECDH_MASK)

#define ELS_ELS_KS4_KS4_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS4_KS4_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS4_KS4_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UCMAC_SHIFT)) & ELS_ELS_KS4_KS4_UCMAC_MASK)

#define ELS_ELS_KS4_KS4_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS4_KS4_UKSK_SHIFT               (14U)
#define ELS_ELS_KS4_KS4_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UKSK_SHIFT)) & ELS_ELS_KS4_KS4_UKSK_MASK)

#define ELS_ELS_KS4_KS4_URTF_MASK                (0x8000U)
#define ELS_ELS_KS4_KS4_URTF_SHIFT               (15U)
#define ELS_ELS_KS4_KS4_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_URTF_SHIFT)) & ELS_ELS_KS4_KS4_URTF_MASK)

#define ELS_ELS_KS4_KS4_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS4_KS4_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS4_KS4_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UCKDF_SHIFT)) & ELS_ELS_KS4_KS4_UCKDF_MASK)

#define ELS_ELS_KS4_KS4_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS4_KS4_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS4_KS4_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UHKDF_SHIFT)) & ELS_ELS_KS4_KS4_UHKDF_MASK)

#define ELS_ELS_KS4_KS4_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS4_KS4_UECSG_SHIFT              (18U)
#define ELS_ELS_KS4_KS4_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UECSG_SHIFT)) & ELS_ELS_KS4_KS4_UECSG_MASK)

#define ELS_ELS_KS4_KS4_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS4_KS4_UECDH_SHIFT              (19U)
#define ELS_ELS_KS4_KS4_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UECDH_SHIFT)) & ELS_ELS_KS4_KS4_UECDH_MASK)

#define ELS_ELS_KS4_KS4_UAES_MASK                (0x100000U)
#define ELS_ELS_KS4_KS4_UAES_SHIFT               (20U)
#define ELS_ELS_KS4_KS4_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UAES_SHIFT)) & ELS_ELS_KS4_KS4_UAES_MASK)

#define ELS_ELS_KS4_KS4_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS4_KS4_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS4_KS4_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UHMAC_SHIFT)) & ELS_ELS_KS4_KS4_UHMAC_MASK)

#define ELS_ELS_KS4_KS4_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS4_KS4_UKWK_SHIFT               (22U)
#define ELS_ELS_KS4_KS4_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UKWK_SHIFT)) & ELS_ELS_KS4_KS4_UKWK_MASK)

#define ELS_ELS_KS4_KS4_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS4_KS4_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS4_KS4_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UKUOK_SHIFT)) & ELS_ELS_KS4_KS4_UKUOK_MASK)

#define ELS_ELS_KS4_KS4_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS4_KS4_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS4_KS4_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UTLSPMS_SHIFT)) & ELS_ELS_KS4_KS4_UTLSPMS_MASK)

#define ELS_ELS_KS4_KS4_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS4_KS4_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS4_KS4_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UTLSMS_SHIFT)) & ELS_ELS_KS4_KS4_UTLSMS_MASK)

#define ELS_ELS_KS4_KS4_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS4_KS4_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS4_KS4_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UKGSRC_SHIFT)) & ELS_ELS_KS4_KS4_UKGSRC_MASK)

#define ELS_ELS_KS4_KS4_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS4_KS4_UHWO_SHIFT               (27U)
#define ELS_ELS_KS4_KS4_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UHWO_SHIFT)) & ELS_ELS_KS4_KS4_UHWO_MASK)

#define ELS_ELS_KS4_KS4_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS4_KS4_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS4_KS4_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UWRPOK_SHIFT)) & ELS_ELS_KS4_KS4_UWRPOK_MASK)

#define ELS_ELS_KS4_KS4_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS4_KS4_UDUK_SHIFT               (29U)
#define ELS_ELS_KS4_KS4_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UDUK_SHIFT)) & ELS_ELS_KS4_KS4_UDUK_MASK)

#define ELS_ELS_KS4_KS4_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS4_KS4_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS4_KS4_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS4_UPPROT_SHIFT)) & ELS_ELS_KS4_KS4_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS5 - Status Register */
/*! @{ */

#define ELS_ELS_KS5_KS5_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS5_KS5_KSIZE_SHIFT              (0U)
/*! KS5_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS5_KS5_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_KSIZE_SHIFT)) & ELS_ELS_KS5_KS5_KSIZE_MASK)

#define ELS_ELS_KS5_KS5_KACT_MASK                (0x20U)
#define ELS_ELS_KS5_KS5_KACT_SHIFT               (5U)
#define ELS_ELS_KS5_KS5_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_KACT_SHIFT)) & ELS_ELS_KS5_KS5_KACT_MASK)

#define ELS_ELS_KS5_KS5_KBASE_MASK               (0x40U)
#define ELS_ELS_KS5_KS5_KBASE_SHIFT              (6U)
#define ELS_ELS_KS5_KS5_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_KBASE_SHIFT)) & ELS_ELS_KS5_KS5_KBASE_MASK)

#define ELS_ELS_KS5_KS5_FGP_MASK                 (0x80U)
#define ELS_ELS_KS5_KS5_FGP_SHIFT                (7U)
#define ELS_ELS_KS5_KS5_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_FGP_SHIFT)) & ELS_ELS_KS5_KS5_FGP_MASK)

#define ELS_ELS_KS5_KS5_FRTN_MASK                (0x100U)
#define ELS_ELS_KS5_KS5_FRTN_SHIFT               (8U)
#define ELS_ELS_KS5_KS5_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_FRTN_SHIFT)) & ELS_ELS_KS5_KS5_FRTN_MASK)

#define ELS_ELS_KS5_KS5_FHWO_MASK                (0x200U)
#define ELS_ELS_KS5_KS5_FHWO_SHIFT               (9U)
#define ELS_ELS_KS5_KS5_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_FHWO_SHIFT)) & ELS_ELS_KS5_KS5_FHWO_MASK)

#define ELS_ELS_KS5_KS5_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS5_KS5_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS5_KS5_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UKPUK_SHIFT)) & ELS_ELS_KS5_KS5_UKPUK_MASK)

#define ELS_ELS_KS5_KS5_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS5_KS5_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS5_KS5_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UTECDH_SHIFT)) & ELS_ELS_KS5_KS5_UTECDH_MASK)

#define ELS_ELS_KS5_KS5_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS5_KS5_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS5_KS5_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UCMAC_SHIFT)) & ELS_ELS_KS5_KS5_UCMAC_MASK)

#define ELS_ELS_KS5_KS5_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS5_KS5_UKSK_SHIFT               (14U)
#define ELS_ELS_KS5_KS5_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UKSK_SHIFT)) & ELS_ELS_KS5_KS5_UKSK_MASK)

#define ELS_ELS_KS5_KS5_URTF_MASK                (0x8000U)
#define ELS_ELS_KS5_KS5_URTF_SHIFT               (15U)
#define ELS_ELS_KS5_KS5_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_URTF_SHIFT)) & ELS_ELS_KS5_KS5_URTF_MASK)

#define ELS_ELS_KS5_KS5_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS5_KS5_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS5_KS5_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UCKDF_SHIFT)) & ELS_ELS_KS5_KS5_UCKDF_MASK)

#define ELS_ELS_KS5_KS5_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS5_KS5_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS5_KS5_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UHKDF_SHIFT)) & ELS_ELS_KS5_KS5_UHKDF_MASK)

#define ELS_ELS_KS5_KS5_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS5_KS5_UECSG_SHIFT              (18U)
#define ELS_ELS_KS5_KS5_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UECSG_SHIFT)) & ELS_ELS_KS5_KS5_UECSG_MASK)

#define ELS_ELS_KS5_KS5_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS5_KS5_UECDH_SHIFT              (19U)
#define ELS_ELS_KS5_KS5_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UECDH_SHIFT)) & ELS_ELS_KS5_KS5_UECDH_MASK)

#define ELS_ELS_KS5_KS5_UAES_MASK                (0x100000U)
#define ELS_ELS_KS5_KS5_UAES_SHIFT               (20U)
#define ELS_ELS_KS5_KS5_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UAES_SHIFT)) & ELS_ELS_KS5_KS5_UAES_MASK)

#define ELS_ELS_KS5_KS5_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS5_KS5_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS5_KS5_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UHMAC_SHIFT)) & ELS_ELS_KS5_KS5_UHMAC_MASK)

#define ELS_ELS_KS5_KS5_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS5_KS5_UKWK_SHIFT               (22U)
#define ELS_ELS_KS5_KS5_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UKWK_SHIFT)) & ELS_ELS_KS5_KS5_UKWK_MASK)

#define ELS_ELS_KS5_KS5_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS5_KS5_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS5_KS5_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UKUOK_SHIFT)) & ELS_ELS_KS5_KS5_UKUOK_MASK)

#define ELS_ELS_KS5_KS5_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS5_KS5_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS5_KS5_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UTLSPMS_SHIFT)) & ELS_ELS_KS5_KS5_UTLSPMS_MASK)

#define ELS_ELS_KS5_KS5_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS5_KS5_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS5_KS5_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UTLSMS_SHIFT)) & ELS_ELS_KS5_KS5_UTLSMS_MASK)

#define ELS_ELS_KS5_KS5_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS5_KS5_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS5_KS5_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UKGSRC_SHIFT)) & ELS_ELS_KS5_KS5_UKGSRC_MASK)

#define ELS_ELS_KS5_KS5_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS5_KS5_UHWO_SHIFT               (27U)
#define ELS_ELS_KS5_KS5_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UHWO_SHIFT)) & ELS_ELS_KS5_KS5_UHWO_MASK)

#define ELS_ELS_KS5_KS5_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS5_KS5_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS5_KS5_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UWRPOK_SHIFT)) & ELS_ELS_KS5_KS5_UWRPOK_MASK)

#define ELS_ELS_KS5_KS5_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS5_KS5_UDUK_SHIFT               (29U)
#define ELS_ELS_KS5_KS5_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UDUK_SHIFT)) & ELS_ELS_KS5_KS5_UDUK_MASK)

#define ELS_ELS_KS5_KS5_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS5_KS5_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS5_KS5_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS5_UPPROT_SHIFT)) & ELS_ELS_KS5_KS5_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS6 - Status Register */
/*! @{ */

#define ELS_ELS_KS6_KS6_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS6_KS6_KSIZE_SHIFT              (0U)
/*! KS6_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS6_KS6_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_KSIZE_SHIFT)) & ELS_ELS_KS6_KS6_KSIZE_MASK)

#define ELS_ELS_KS6_KS6_KACT_MASK                (0x20U)
#define ELS_ELS_KS6_KS6_KACT_SHIFT               (5U)
#define ELS_ELS_KS6_KS6_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_KACT_SHIFT)) & ELS_ELS_KS6_KS6_KACT_MASK)

#define ELS_ELS_KS6_KS6_KBASE_MASK               (0x40U)
#define ELS_ELS_KS6_KS6_KBASE_SHIFT              (6U)
#define ELS_ELS_KS6_KS6_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_KBASE_SHIFT)) & ELS_ELS_KS6_KS6_KBASE_MASK)

#define ELS_ELS_KS6_KS6_FGP_MASK                 (0x80U)
#define ELS_ELS_KS6_KS6_FGP_SHIFT                (7U)
#define ELS_ELS_KS6_KS6_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_FGP_SHIFT)) & ELS_ELS_KS6_KS6_FGP_MASK)

#define ELS_ELS_KS6_KS6_FRTN_MASK                (0x100U)
#define ELS_ELS_KS6_KS6_FRTN_SHIFT               (8U)
#define ELS_ELS_KS6_KS6_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_FRTN_SHIFT)) & ELS_ELS_KS6_KS6_FRTN_MASK)

#define ELS_ELS_KS6_KS6_FHWO_MASK                (0x200U)
#define ELS_ELS_KS6_KS6_FHWO_SHIFT               (9U)
#define ELS_ELS_KS6_KS6_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_FHWO_SHIFT)) & ELS_ELS_KS6_KS6_FHWO_MASK)

#define ELS_ELS_KS6_KS6_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS6_KS6_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS6_KS6_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UKPUK_SHIFT)) & ELS_ELS_KS6_KS6_UKPUK_MASK)

#define ELS_ELS_KS6_KS6_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS6_KS6_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS6_KS6_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UTECDH_SHIFT)) & ELS_ELS_KS6_KS6_UTECDH_MASK)

#define ELS_ELS_KS6_KS6_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS6_KS6_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS6_KS6_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UCMAC_SHIFT)) & ELS_ELS_KS6_KS6_UCMAC_MASK)

#define ELS_ELS_KS6_KS6_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS6_KS6_UKSK_SHIFT               (14U)
#define ELS_ELS_KS6_KS6_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UKSK_SHIFT)) & ELS_ELS_KS6_KS6_UKSK_MASK)

#define ELS_ELS_KS6_KS6_URTF_MASK                (0x8000U)
#define ELS_ELS_KS6_KS6_URTF_SHIFT               (15U)
#define ELS_ELS_KS6_KS6_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_URTF_SHIFT)) & ELS_ELS_KS6_KS6_URTF_MASK)

#define ELS_ELS_KS6_KS6_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS6_KS6_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS6_KS6_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UCKDF_SHIFT)) & ELS_ELS_KS6_KS6_UCKDF_MASK)

#define ELS_ELS_KS6_KS6_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS6_KS6_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS6_KS6_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UHKDF_SHIFT)) & ELS_ELS_KS6_KS6_UHKDF_MASK)

#define ELS_ELS_KS6_KS6_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS6_KS6_UECSG_SHIFT              (18U)
#define ELS_ELS_KS6_KS6_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UECSG_SHIFT)) & ELS_ELS_KS6_KS6_UECSG_MASK)

#define ELS_ELS_KS6_KS6_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS6_KS6_UECDH_SHIFT              (19U)
#define ELS_ELS_KS6_KS6_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UECDH_SHIFT)) & ELS_ELS_KS6_KS6_UECDH_MASK)

#define ELS_ELS_KS6_KS6_UAES_MASK                (0x100000U)
#define ELS_ELS_KS6_KS6_UAES_SHIFT               (20U)
#define ELS_ELS_KS6_KS6_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UAES_SHIFT)) & ELS_ELS_KS6_KS6_UAES_MASK)

#define ELS_ELS_KS6_KS6_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS6_KS6_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS6_KS6_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UHMAC_SHIFT)) & ELS_ELS_KS6_KS6_UHMAC_MASK)

#define ELS_ELS_KS6_KS6_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS6_KS6_UKWK_SHIFT               (22U)
#define ELS_ELS_KS6_KS6_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UKWK_SHIFT)) & ELS_ELS_KS6_KS6_UKWK_MASK)

#define ELS_ELS_KS6_KS6_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS6_KS6_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS6_KS6_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UKUOK_SHIFT)) & ELS_ELS_KS6_KS6_UKUOK_MASK)

#define ELS_ELS_KS6_KS6_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS6_KS6_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS6_KS6_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UTLSPMS_SHIFT)) & ELS_ELS_KS6_KS6_UTLSPMS_MASK)

#define ELS_ELS_KS6_KS6_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS6_KS6_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS6_KS6_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UTLSMS_SHIFT)) & ELS_ELS_KS6_KS6_UTLSMS_MASK)

#define ELS_ELS_KS6_KS6_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS6_KS6_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS6_KS6_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UKGSRC_SHIFT)) & ELS_ELS_KS6_KS6_UKGSRC_MASK)

#define ELS_ELS_KS6_KS6_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS6_KS6_UHWO_SHIFT               (27U)
#define ELS_ELS_KS6_KS6_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UHWO_SHIFT)) & ELS_ELS_KS6_KS6_UHWO_MASK)

#define ELS_ELS_KS6_KS6_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS6_KS6_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS6_KS6_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UWRPOK_SHIFT)) & ELS_ELS_KS6_KS6_UWRPOK_MASK)

#define ELS_ELS_KS6_KS6_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS6_KS6_UDUK_SHIFT               (29U)
#define ELS_ELS_KS6_KS6_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UDUK_SHIFT)) & ELS_ELS_KS6_KS6_UDUK_MASK)

#define ELS_ELS_KS6_KS6_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS6_KS6_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS6_KS6_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS6_UPPROT_SHIFT)) & ELS_ELS_KS6_KS6_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS7 - Status Register */
/*! @{ */

#define ELS_ELS_KS7_KS7_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS7_KS7_KSIZE_SHIFT              (0U)
/*! KS7_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS7_KS7_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_KSIZE_SHIFT)) & ELS_ELS_KS7_KS7_KSIZE_MASK)

#define ELS_ELS_KS7_KS7_KACT_MASK                (0x20U)
#define ELS_ELS_KS7_KS7_KACT_SHIFT               (5U)
#define ELS_ELS_KS7_KS7_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_KACT_SHIFT)) & ELS_ELS_KS7_KS7_KACT_MASK)

#define ELS_ELS_KS7_KS7_KBASE_MASK               (0x40U)
#define ELS_ELS_KS7_KS7_KBASE_SHIFT              (6U)
#define ELS_ELS_KS7_KS7_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_KBASE_SHIFT)) & ELS_ELS_KS7_KS7_KBASE_MASK)

#define ELS_ELS_KS7_KS7_FGP_MASK                 (0x80U)
#define ELS_ELS_KS7_KS7_FGP_SHIFT                (7U)
#define ELS_ELS_KS7_KS7_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_FGP_SHIFT)) & ELS_ELS_KS7_KS7_FGP_MASK)

#define ELS_ELS_KS7_KS7_FRTN_MASK                (0x100U)
#define ELS_ELS_KS7_KS7_FRTN_SHIFT               (8U)
#define ELS_ELS_KS7_KS7_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_FRTN_SHIFT)) & ELS_ELS_KS7_KS7_FRTN_MASK)

#define ELS_ELS_KS7_KS7_FHWO_MASK                (0x200U)
#define ELS_ELS_KS7_KS7_FHWO_SHIFT               (9U)
#define ELS_ELS_KS7_KS7_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_FHWO_SHIFT)) & ELS_ELS_KS7_KS7_FHWO_MASK)

#define ELS_ELS_KS7_KS7_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS7_KS7_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS7_KS7_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UKPUK_SHIFT)) & ELS_ELS_KS7_KS7_UKPUK_MASK)

#define ELS_ELS_KS7_KS7_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS7_KS7_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS7_KS7_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UTECDH_SHIFT)) & ELS_ELS_KS7_KS7_UTECDH_MASK)

#define ELS_ELS_KS7_KS7_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS7_KS7_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS7_KS7_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UCMAC_SHIFT)) & ELS_ELS_KS7_KS7_UCMAC_MASK)

#define ELS_ELS_KS7_KS7_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS7_KS7_UKSK_SHIFT               (14U)
#define ELS_ELS_KS7_KS7_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UKSK_SHIFT)) & ELS_ELS_KS7_KS7_UKSK_MASK)

#define ELS_ELS_KS7_KS7_URTF_MASK                (0x8000U)
#define ELS_ELS_KS7_KS7_URTF_SHIFT               (15U)
#define ELS_ELS_KS7_KS7_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_URTF_SHIFT)) & ELS_ELS_KS7_KS7_URTF_MASK)

#define ELS_ELS_KS7_KS7_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS7_KS7_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS7_KS7_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UCKDF_SHIFT)) & ELS_ELS_KS7_KS7_UCKDF_MASK)

#define ELS_ELS_KS7_KS7_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS7_KS7_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS7_KS7_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UHKDF_SHIFT)) & ELS_ELS_KS7_KS7_UHKDF_MASK)

#define ELS_ELS_KS7_KS7_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS7_KS7_UECSG_SHIFT              (18U)
#define ELS_ELS_KS7_KS7_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UECSG_SHIFT)) & ELS_ELS_KS7_KS7_UECSG_MASK)

#define ELS_ELS_KS7_KS7_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS7_KS7_UECDH_SHIFT              (19U)
#define ELS_ELS_KS7_KS7_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UECDH_SHIFT)) & ELS_ELS_KS7_KS7_UECDH_MASK)

#define ELS_ELS_KS7_KS7_UAES_MASK                (0x100000U)
#define ELS_ELS_KS7_KS7_UAES_SHIFT               (20U)
#define ELS_ELS_KS7_KS7_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UAES_SHIFT)) & ELS_ELS_KS7_KS7_UAES_MASK)

#define ELS_ELS_KS7_KS7_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS7_KS7_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS7_KS7_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UHMAC_SHIFT)) & ELS_ELS_KS7_KS7_UHMAC_MASK)

#define ELS_ELS_KS7_KS7_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS7_KS7_UKWK_SHIFT               (22U)
#define ELS_ELS_KS7_KS7_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UKWK_SHIFT)) & ELS_ELS_KS7_KS7_UKWK_MASK)

#define ELS_ELS_KS7_KS7_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS7_KS7_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS7_KS7_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UKUOK_SHIFT)) & ELS_ELS_KS7_KS7_UKUOK_MASK)

#define ELS_ELS_KS7_KS7_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS7_KS7_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS7_KS7_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UTLSPMS_SHIFT)) & ELS_ELS_KS7_KS7_UTLSPMS_MASK)

#define ELS_ELS_KS7_KS7_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS7_KS7_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS7_KS7_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UTLSMS_SHIFT)) & ELS_ELS_KS7_KS7_UTLSMS_MASK)

#define ELS_ELS_KS7_KS7_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS7_KS7_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS7_KS7_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UKGSRC_SHIFT)) & ELS_ELS_KS7_KS7_UKGSRC_MASK)

#define ELS_ELS_KS7_KS7_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS7_KS7_UHWO_SHIFT               (27U)
#define ELS_ELS_KS7_KS7_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UHWO_SHIFT)) & ELS_ELS_KS7_KS7_UHWO_MASK)

#define ELS_ELS_KS7_KS7_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS7_KS7_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS7_KS7_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UWRPOK_SHIFT)) & ELS_ELS_KS7_KS7_UWRPOK_MASK)

#define ELS_ELS_KS7_KS7_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS7_KS7_UDUK_SHIFT               (29U)
#define ELS_ELS_KS7_KS7_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UDUK_SHIFT)) & ELS_ELS_KS7_KS7_UDUK_MASK)

#define ELS_ELS_KS7_KS7_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS7_KS7_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS7_KS7_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS7_UPPROT_SHIFT)) & ELS_ELS_KS7_KS7_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS8 - Status Register */
/*! @{ */

#define ELS_ELS_KS8_KS8_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS8_KS8_KSIZE_SHIFT              (0U)
/*! KS8_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS8_KS8_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_KSIZE_SHIFT)) & ELS_ELS_KS8_KS8_KSIZE_MASK)

#define ELS_ELS_KS8_KS8_KACT_MASK                (0x20U)
#define ELS_ELS_KS8_KS8_KACT_SHIFT               (5U)
#define ELS_ELS_KS8_KS8_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_KACT_SHIFT)) & ELS_ELS_KS8_KS8_KACT_MASK)

#define ELS_ELS_KS8_KS8_KBASE_MASK               (0x40U)
#define ELS_ELS_KS8_KS8_KBASE_SHIFT              (6U)
#define ELS_ELS_KS8_KS8_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_KBASE_SHIFT)) & ELS_ELS_KS8_KS8_KBASE_MASK)

#define ELS_ELS_KS8_KS8_FGP_MASK                 (0x80U)
#define ELS_ELS_KS8_KS8_FGP_SHIFT                (7U)
#define ELS_ELS_KS8_KS8_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_FGP_SHIFT)) & ELS_ELS_KS8_KS8_FGP_MASK)

#define ELS_ELS_KS8_KS8_FRTN_MASK                (0x100U)
#define ELS_ELS_KS8_KS8_FRTN_SHIFT               (8U)
#define ELS_ELS_KS8_KS8_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_FRTN_SHIFT)) & ELS_ELS_KS8_KS8_FRTN_MASK)

#define ELS_ELS_KS8_KS8_FHWO_MASK                (0x200U)
#define ELS_ELS_KS8_KS8_FHWO_SHIFT               (9U)
#define ELS_ELS_KS8_KS8_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_FHWO_SHIFT)) & ELS_ELS_KS8_KS8_FHWO_MASK)

#define ELS_ELS_KS8_KS8_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS8_KS8_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS8_KS8_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UKPUK_SHIFT)) & ELS_ELS_KS8_KS8_UKPUK_MASK)

#define ELS_ELS_KS8_KS8_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS8_KS8_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS8_KS8_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UTECDH_SHIFT)) & ELS_ELS_KS8_KS8_UTECDH_MASK)

#define ELS_ELS_KS8_KS8_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS8_KS8_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS8_KS8_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UCMAC_SHIFT)) & ELS_ELS_KS8_KS8_UCMAC_MASK)

#define ELS_ELS_KS8_KS8_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS8_KS8_UKSK_SHIFT               (14U)
#define ELS_ELS_KS8_KS8_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UKSK_SHIFT)) & ELS_ELS_KS8_KS8_UKSK_MASK)

#define ELS_ELS_KS8_KS8_URTF_MASK                (0x8000U)
#define ELS_ELS_KS8_KS8_URTF_SHIFT               (15U)
#define ELS_ELS_KS8_KS8_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_URTF_SHIFT)) & ELS_ELS_KS8_KS8_URTF_MASK)

#define ELS_ELS_KS8_KS8_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS8_KS8_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS8_KS8_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UCKDF_SHIFT)) & ELS_ELS_KS8_KS8_UCKDF_MASK)

#define ELS_ELS_KS8_KS8_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS8_KS8_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS8_KS8_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UHKDF_SHIFT)) & ELS_ELS_KS8_KS8_UHKDF_MASK)

#define ELS_ELS_KS8_KS8_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS8_KS8_UECSG_SHIFT              (18U)
#define ELS_ELS_KS8_KS8_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UECSG_SHIFT)) & ELS_ELS_KS8_KS8_UECSG_MASK)

#define ELS_ELS_KS8_KS8_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS8_KS8_UECDH_SHIFT              (19U)
#define ELS_ELS_KS8_KS8_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UECDH_SHIFT)) & ELS_ELS_KS8_KS8_UECDH_MASK)

#define ELS_ELS_KS8_KS8_UAES_MASK                (0x100000U)
#define ELS_ELS_KS8_KS8_UAES_SHIFT               (20U)
#define ELS_ELS_KS8_KS8_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UAES_SHIFT)) & ELS_ELS_KS8_KS8_UAES_MASK)

#define ELS_ELS_KS8_KS8_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS8_KS8_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS8_KS8_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UHMAC_SHIFT)) & ELS_ELS_KS8_KS8_UHMAC_MASK)

#define ELS_ELS_KS8_KS8_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS8_KS8_UKWK_SHIFT               (22U)
#define ELS_ELS_KS8_KS8_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UKWK_SHIFT)) & ELS_ELS_KS8_KS8_UKWK_MASK)

#define ELS_ELS_KS8_KS8_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS8_KS8_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS8_KS8_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UKUOK_SHIFT)) & ELS_ELS_KS8_KS8_UKUOK_MASK)

#define ELS_ELS_KS8_KS8_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS8_KS8_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS8_KS8_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UTLSPMS_SHIFT)) & ELS_ELS_KS8_KS8_UTLSPMS_MASK)

#define ELS_ELS_KS8_KS8_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS8_KS8_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS8_KS8_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UTLSMS_SHIFT)) & ELS_ELS_KS8_KS8_UTLSMS_MASK)

#define ELS_ELS_KS8_KS8_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS8_KS8_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS8_KS8_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UKGSRC_SHIFT)) & ELS_ELS_KS8_KS8_UKGSRC_MASK)

#define ELS_ELS_KS8_KS8_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS8_KS8_UHWO_SHIFT               (27U)
#define ELS_ELS_KS8_KS8_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UHWO_SHIFT)) & ELS_ELS_KS8_KS8_UHWO_MASK)

#define ELS_ELS_KS8_KS8_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS8_KS8_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS8_KS8_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UWRPOK_SHIFT)) & ELS_ELS_KS8_KS8_UWRPOK_MASK)

#define ELS_ELS_KS8_KS8_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS8_KS8_UDUK_SHIFT               (29U)
#define ELS_ELS_KS8_KS8_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UDUK_SHIFT)) & ELS_ELS_KS8_KS8_UDUK_MASK)

#define ELS_ELS_KS8_KS8_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS8_KS8_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS8_KS8_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS8_UPPROT_SHIFT)) & ELS_ELS_KS8_KS8_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS9 - Status Register */
/*! @{ */

#define ELS_ELS_KS9_KS9_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS9_KS9_KSIZE_SHIFT              (0U)
/*! KS9_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS9_KS9_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_KSIZE_SHIFT)) & ELS_ELS_KS9_KS9_KSIZE_MASK)

#define ELS_ELS_KS9_KS9_KACT_MASK                (0x20U)
#define ELS_ELS_KS9_KS9_KACT_SHIFT               (5U)
#define ELS_ELS_KS9_KS9_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_KACT_SHIFT)) & ELS_ELS_KS9_KS9_KACT_MASK)

#define ELS_ELS_KS9_KS9_KBASE_MASK               (0x40U)
#define ELS_ELS_KS9_KS9_KBASE_SHIFT              (6U)
#define ELS_ELS_KS9_KS9_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_KBASE_SHIFT)) & ELS_ELS_KS9_KS9_KBASE_MASK)

#define ELS_ELS_KS9_KS9_FGP_MASK                 (0x80U)
#define ELS_ELS_KS9_KS9_FGP_SHIFT                (7U)
#define ELS_ELS_KS9_KS9_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_FGP_SHIFT)) & ELS_ELS_KS9_KS9_FGP_MASK)

#define ELS_ELS_KS9_KS9_FRTN_MASK                (0x100U)
#define ELS_ELS_KS9_KS9_FRTN_SHIFT               (8U)
#define ELS_ELS_KS9_KS9_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_FRTN_SHIFT)) & ELS_ELS_KS9_KS9_FRTN_MASK)

#define ELS_ELS_KS9_KS9_FHWO_MASK                (0x200U)
#define ELS_ELS_KS9_KS9_FHWO_SHIFT               (9U)
#define ELS_ELS_KS9_KS9_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_FHWO_SHIFT)) & ELS_ELS_KS9_KS9_FHWO_MASK)

#define ELS_ELS_KS9_KS9_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS9_KS9_UKPUK_SHIFT              (11U)
#define ELS_ELS_KS9_KS9_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UKPUK_SHIFT)) & ELS_ELS_KS9_KS9_UKPUK_MASK)

#define ELS_ELS_KS9_KS9_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS9_KS9_UTECDH_SHIFT             (12U)
#define ELS_ELS_KS9_KS9_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UTECDH_SHIFT)) & ELS_ELS_KS9_KS9_UTECDH_MASK)

#define ELS_ELS_KS9_KS9_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS9_KS9_UCMAC_SHIFT              (13U)
#define ELS_ELS_KS9_KS9_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UCMAC_SHIFT)) & ELS_ELS_KS9_KS9_UCMAC_MASK)

#define ELS_ELS_KS9_KS9_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS9_KS9_UKSK_SHIFT               (14U)
#define ELS_ELS_KS9_KS9_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UKSK_SHIFT)) & ELS_ELS_KS9_KS9_UKSK_MASK)

#define ELS_ELS_KS9_KS9_URTF_MASK                (0x8000U)
#define ELS_ELS_KS9_KS9_URTF_SHIFT               (15U)
#define ELS_ELS_KS9_KS9_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_URTF_SHIFT)) & ELS_ELS_KS9_KS9_URTF_MASK)

#define ELS_ELS_KS9_KS9_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS9_KS9_UCKDF_SHIFT              (16U)
#define ELS_ELS_KS9_KS9_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UCKDF_SHIFT)) & ELS_ELS_KS9_KS9_UCKDF_MASK)

#define ELS_ELS_KS9_KS9_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS9_KS9_UHKDF_SHIFT              (17U)
#define ELS_ELS_KS9_KS9_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UHKDF_SHIFT)) & ELS_ELS_KS9_KS9_UHKDF_MASK)

#define ELS_ELS_KS9_KS9_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS9_KS9_UECSG_SHIFT              (18U)
#define ELS_ELS_KS9_KS9_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UECSG_SHIFT)) & ELS_ELS_KS9_KS9_UECSG_MASK)

#define ELS_ELS_KS9_KS9_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS9_KS9_UECDH_SHIFT              (19U)
#define ELS_ELS_KS9_KS9_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UECDH_SHIFT)) & ELS_ELS_KS9_KS9_UECDH_MASK)

#define ELS_ELS_KS9_KS9_UAES_MASK                (0x100000U)
#define ELS_ELS_KS9_KS9_UAES_SHIFT               (20U)
#define ELS_ELS_KS9_KS9_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UAES_SHIFT)) & ELS_ELS_KS9_KS9_UAES_MASK)

#define ELS_ELS_KS9_KS9_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS9_KS9_UHMAC_SHIFT              (21U)
#define ELS_ELS_KS9_KS9_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UHMAC_SHIFT)) & ELS_ELS_KS9_KS9_UHMAC_MASK)

#define ELS_ELS_KS9_KS9_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS9_KS9_UKWK_SHIFT               (22U)
#define ELS_ELS_KS9_KS9_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UKWK_SHIFT)) & ELS_ELS_KS9_KS9_UKWK_MASK)

#define ELS_ELS_KS9_KS9_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS9_KS9_UKUOK_SHIFT              (23U)
#define ELS_ELS_KS9_KS9_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UKUOK_SHIFT)) & ELS_ELS_KS9_KS9_UKUOK_MASK)

#define ELS_ELS_KS9_KS9_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS9_KS9_UTLSPMS_SHIFT            (24U)
#define ELS_ELS_KS9_KS9_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UTLSPMS_SHIFT)) & ELS_ELS_KS9_KS9_UTLSPMS_MASK)

#define ELS_ELS_KS9_KS9_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS9_KS9_UTLSMS_SHIFT             (25U)
#define ELS_ELS_KS9_KS9_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UTLSMS_SHIFT)) & ELS_ELS_KS9_KS9_UTLSMS_MASK)

#define ELS_ELS_KS9_KS9_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS9_KS9_UKGSRC_SHIFT             (26U)
#define ELS_ELS_KS9_KS9_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UKGSRC_SHIFT)) & ELS_ELS_KS9_KS9_UKGSRC_MASK)

#define ELS_ELS_KS9_KS9_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS9_KS9_UHWO_SHIFT               (27U)
#define ELS_ELS_KS9_KS9_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UHWO_SHIFT)) & ELS_ELS_KS9_KS9_UHWO_MASK)

#define ELS_ELS_KS9_KS9_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS9_KS9_UWRPOK_SHIFT             (28U)
#define ELS_ELS_KS9_KS9_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UWRPOK_SHIFT)) & ELS_ELS_KS9_KS9_UWRPOK_MASK)

#define ELS_ELS_KS9_KS9_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS9_KS9_UDUK_SHIFT               (29U)
#define ELS_ELS_KS9_KS9_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UDUK_SHIFT)) & ELS_ELS_KS9_KS9_UDUK_MASK)

#define ELS_ELS_KS9_KS9_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS9_KS9_UPPROT_SHIFT             (30U)
#define ELS_ELS_KS9_KS9_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS9_UPPROT_SHIFT)) & ELS_ELS_KS9_KS9_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS10 - Status Register */
/*! @{ */

#define ELS_ELS_KS10_KS10_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS10_KS10_KSIZE_SHIFT            (0U)
/*! KS10_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS10_KS10_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_KSIZE_SHIFT)) & ELS_ELS_KS10_KS10_KSIZE_MASK)

#define ELS_ELS_KS10_KS10_KACT_MASK              (0x20U)
#define ELS_ELS_KS10_KS10_KACT_SHIFT             (5U)
#define ELS_ELS_KS10_KS10_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_KACT_SHIFT)) & ELS_ELS_KS10_KS10_KACT_MASK)

#define ELS_ELS_KS10_KS10_KBASE_MASK             (0x40U)
#define ELS_ELS_KS10_KS10_KBASE_SHIFT            (6U)
#define ELS_ELS_KS10_KS10_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_KBASE_SHIFT)) & ELS_ELS_KS10_KS10_KBASE_MASK)

#define ELS_ELS_KS10_KS10_FGP_MASK               (0x80U)
#define ELS_ELS_KS10_KS10_FGP_SHIFT              (7U)
#define ELS_ELS_KS10_KS10_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_FGP_SHIFT)) & ELS_ELS_KS10_KS10_FGP_MASK)

#define ELS_ELS_KS10_KS10_FRTN_MASK              (0x100U)
#define ELS_ELS_KS10_KS10_FRTN_SHIFT             (8U)
#define ELS_ELS_KS10_KS10_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_FRTN_SHIFT)) & ELS_ELS_KS10_KS10_FRTN_MASK)

#define ELS_ELS_KS10_KS10_FHWO_MASK              (0x200U)
#define ELS_ELS_KS10_KS10_FHWO_SHIFT             (9U)
#define ELS_ELS_KS10_KS10_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_FHWO_SHIFT)) & ELS_ELS_KS10_KS10_FHWO_MASK)

#define ELS_ELS_KS10_KS10_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS10_KS10_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS10_KS10_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UKPUK_SHIFT)) & ELS_ELS_KS10_KS10_UKPUK_MASK)

#define ELS_ELS_KS10_KS10_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS10_KS10_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS10_KS10_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UTECDH_SHIFT)) & ELS_ELS_KS10_KS10_UTECDH_MASK)

#define ELS_ELS_KS10_KS10_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS10_KS10_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS10_KS10_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UCMAC_SHIFT)) & ELS_ELS_KS10_KS10_UCMAC_MASK)

#define ELS_ELS_KS10_KS10_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS10_KS10_UKSK_SHIFT             (14U)
#define ELS_ELS_KS10_KS10_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UKSK_SHIFT)) & ELS_ELS_KS10_KS10_UKSK_MASK)

#define ELS_ELS_KS10_KS10_URTF_MASK              (0x8000U)
#define ELS_ELS_KS10_KS10_URTF_SHIFT             (15U)
#define ELS_ELS_KS10_KS10_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_URTF_SHIFT)) & ELS_ELS_KS10_KS10_URTF_MASK)

#define ELS_ELS_KS10_KS10_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS10_KS10_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS10_KS10_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UCKDF_SHIFT)) & ELS_ELS_KS10_KS10_UCKDF_MASK)

#define ELS_ELS_KS10_KS10_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS10_KS10_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS10_KS10_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UHKDF_SHIFT)) & ELS_ELS_KS10_KS10_UHKDF_MASK)

#define ELS_ELS_KS10_KS10_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS10_KS10_UECSG_SHIFT            (18U)
#define ELS_ELS_KS10_KS10_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UECSG_SHIFT)) & ELS_ELS_KS10_KS10_UECSG_MASK)

#define ELS_ELS_KS10_KS10_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS10_KS10_UECDH_SHIFT            (19U)
#define ELS_ELS_KS10_KS10_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UECDH_SHIFT)) & ELS_ELS_KS10_KS10_UECDH_MASK)

#define ELS_ELS_KS10_KS10_UAES_MASK              (0x100000U)
#define ELS_ELS_KS10_KS10_UAES_SHIFT             (20U)
#define ELS_ELS_KS10_KS10_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UAES_SHIFT)) & ELS_ELS_KS10_KS10_UAES_MASK)

#define ELS_ELS_KS10_KS10_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS10_KS10_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS10_KS10_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UHMAC_SHIFT)) & ELS_ELS_KS10_KS10_UHMAC_MASK)

#define ELS_ELS_KS10_KS10_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS10_KS10_UKWK_SHIFT             (22U)
#define ELS_ELS_KS10_KS10_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UKWK_SHIFT)) & ELS_ELS_KS10_KS10_UKWK_MASK)

#define ELS_ELS_KS10_KS10_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS10_KS10_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS10_KS10_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UKUOK_SHIFT)) & ELS_ELS_KS10_KS10_UKUOK_MASK)

#define ELS_ELS_KS10_KS10_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS10_KS10_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS10_KS10_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UTLSPMS_SHIFT)) & ELS_ELS_KS10_KS10_UTLSPMS_MASK)

#define ELS_ELS_KS10_KS10_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS10_KS10_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS10_KS10_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UTLSMS_SHIFT)) & ELS_ELS_KS10_KS10_UTLSMS_MASK)

#define ELS_ELS_KS10_KS10_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS10_KS10_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS10_KS10_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UKGSRC_SHIFT)) & ELS_ELS_KS10_KS10_UKGSRC_MASK)

#define ELS_ELS_KS10_KS10_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS10_KS10_UHWO_SHIFT             (27U)
#define ELS_ELS_KS10_KS10_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UHWO_SHIFT)) & ELS_ELS_KS10_KS10_UHWO_MASK)

#define ELS_ELS_KS10_KS10_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS10_KS10_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS10_KS10_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UWRPOK_SHIFT)) & ELS_ELS_KS10_KS10_UWRPOK_MASK)

#define ELS_ELS_KS10_KS10_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS10_KS10_UDUK_SHIFT             (29U)
#define ELS_ELS_KS10_KS10_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UDUK_SHIFT)) & ELS_ELS_KS10_KS10_UDUK_MASK)

#define ELS_ELS_KS10_KS10_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS10_KS10_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS10_KS10_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS10_UPPROT_SHIFT)) & ELS_ELS_KS10_KS10_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS11 - Status Register */
/*! @{ */

#define ELS_ELS_KS11_KS11_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS11_KS11_KSIZE_SHIFT            (0U)
/*! KS11_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS11_KS11_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_KSIZE_SHIFT)) & ELS_ELS_KS11_KS11_KSIZE_MASK)

#define ELS_ELS_KS11_KS11_KACT_MASK              (0x20U)
#define ELS_ELS_KS11_KS11_KACT_SHIFT             (5U)
#define ELS_ELS_KS11_KS11_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_KACT_SHIFT)) & ELS_ELS_KS11_KS11_KACT_MASK)

#define ELS_ELS_KS11_KS11_KBASE_MASK             (0x40U)
#define ELS_ELS_KS11_KS11_KBASE_SHIFT            (6U)
#define ELS_ELS_KS11_KS11_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_KBASE_SHIFT)) & ELS_ELS_KS11_KS11_KBASE_MASK)

#define ELS_ELS_KS11_KS11_FGP_MASK               (0x80U)
#define ELS_ELS_KS11_KS11_FGP_SHIFT              (7U)
#define ELS_ELS_KS11_KS11_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_FGP_SHIFT)) & ELS_ELS_KS11_KS11_FGP_MASK)

#define ELS_ELS_KS11_KS11_FRTN_MASK              (0x100U)
#define ELS_ELS_KS11_KS11_FRTN_SHIFT             (8U)
#define ELS_ELS_KS11_KS11_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_FRTN_SHIFT)) & ELS_ELS_KS11_KS11_FRTN_MASK)

#define ELS_ELS_KS11_KS11_FHWO_MASK              (0x200U)
#define ELS_ELS_KS11_KS11_FHWO_SHIFT             (9U)
#define ELS_ELS_KS11_KS11_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_FHWO_SHIFT)) & ELS_ELS_KS11_KS11_FHWO_MASK)

#define ELS_ELS_KS11_KS11_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS11_KS11_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS11_KS11_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UKPUK_SHIFT)) & ELS_ELS_KS11_KS11_UKPUK_MASK)

#define ELS_ELS_KS11_KS11_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS11_KS11_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS11_KS11_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UTECDH_SHIFT)) & ELS_ELS_KS11_KS11_UTECDH_MASK)

#define ELS_ELS_KS11_KS11_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS11_KS11_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS11_KS11_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UCMAC_SHIFT)) & ELS_ELS_KS11_KS11_UCMAC_MASK)

#define ELS_ELS_KS11_KS11_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS11_KS11_UKSK_SHIFT             (14U)
#define ELS_ELS_KS11_KS11_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UKSK_SHIFT)) & ELS_ELS_KS11_KS11_UKSK_MASK)

#define ELS_ELS_KS11_KS11_URTF_MASK              (0x8000U)
#define ELS_ELS_KS11_KS11_URTF_SHIFT             (15U)
#define ELS_ELS_KS11_KS11_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_URTF_SHIFT)) & ELS_ELS_KS11_KS11_URTF_MASK)

#define ELS_ELS_KS11_KS11_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS11_KS11_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS11_KS11_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UCKDF_SHIFT)) & ELS_ELS_KS11_KS11_UCKDF_MASK)

#define ELS_ELS_KS11_KS11_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS11_KS11_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS11_KS11_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UHKDF_SHIFT)) & ELS_ELS_KS11_KS11_UHKDF_MASK)

#define ELS_ELS_KS11_KS11_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS11_KS11_UECSG_SHIFT            (18U)
#define ELS_ELS_KS11_KS11_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UECSG_SHIFT)) & ELS_ELS_KS11_KS11_UECSG_MASK)

#define ELS_ELS_KS11_KS11_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS11_KS11_UECDH_SHIFT            (19U)
#define ELS_ELS_KS11_KS11_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UECDH_SHIFT)) & ELS_ELS_KS11_KS11_UECDH_MASK)

#define ELS_ELS_KS11_KS11_UAES_MASK              (0x100000U)
#define ELS_ELS_KS11_KS11_UAES_SHIFT             (20U)
#define ELS_ELS_KS11_KS11_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UAES_SHIFT)) & ELS_ELS_KS11_KS11_UAES_MASK)

#define ELS_ELS_KS11_KS11_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS11_KS11_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS11_KS11_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UHMAC_SHIFT)) & ELS_ELS_KS11_KS11_UHMAC_MASK)

#define ELS_ELS_KS11_KS11_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS11_KS11_UKWK_SHIFT             (22U)
#define ELS_ELS_KS11_KS11_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UKWK_SHIFT)) & ELS_ELS_KS11_KS11_UKWK_MASK)

#define ELS_ELS_KS11_KS11_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS11_KS11_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS11_KS11_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UKUOK_SHIFT)) & ELS_ELS_KS11_KS11_UKUOK_MASK)

#define ELS_ELS_KS11_KS11_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS11_KS11_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS11_KS11_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UTLSPMS_SHIFT)) & ELS_ELS_KS11_KS11_UTLSPMS_MASK)

#define ELS_ELS_KS11_KS11_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS11_KS11_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS11_KS11_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UTLSMS_SHIFT)) & ELS_ELS_KS11_KS11_UTLSMS_MASK)

#define ELS_ELS_KS11_KS11_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS11_KS11_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS11_KS11_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UKGSRC_SHIFT)) & ELS_ELS_KS11_KS11_UKGSRC_MASK)

#define ELS_ELS_KS11_KS11_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS11_KS11_UHWO_SHIFT             (27U)
#define ELS_ELS_KS11_KS11_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UHWO_SHIFT)) & ELS_ELS_KS11_KS11_UHWO_MASK)

#define ELS_ELS_KS11_KS11_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS11_KS11_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS11_KS11_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UWRPOK_SHIFT)) & ELS_ELS_KS11_KS11_UWRPOK_MASK)

#define ELS_ELS_KS11_KS11_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS11_KS11_UDUK_SHIFT             (29U)
#define ELS_ELS_KS11_KS11_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UDUK_SHIFT)) & ELS_ELS_KS11_KS11_UDUK_MASK)

#define ELS_ELS_KS11_KS11_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS11_KS11_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS11_KS11_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS11_UPPROT_SHIFT)) & ELS_ELS_KS11_KS11_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS12 - Status Register */
/*! @{ */

#define ELS_ELS_KS12_KS12_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS12_KS12_KSIZE_SHIFT            (0U)
/*! KS12_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS12_KS12_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_KSIZE_SHIFT)) & ELS_ELS_KS12_KS12_KSIZE_MASK)

#define ELS_ELS_KS12_KS12_KACT_MASK              (0x20U)
#define ELS_ELS_KS12_KS12_KACT_SHIFT             (5U)
#define ELS_ELS_KS12_KS12_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_KACT_SHIFT)) & ELS_ELS_KS12_KS12_KACT_MASK)

#define ELS_ELS_KS12_KS12_KBASE_MASK             (0x40U)
#define ELS_ELS_KS12_KS12_KBASE_SHIFT            (6U)
#define ELS_ELS_KS12_KS12_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_KBASE_SHIFT)) & ELS_ELS_KS12_KS12_KBASE_MASK)

#define ELS_ELS_KS12_KS12_FGP_MASK               (0x80U)
#define ELS_ELS_KS12_KS12_FGP_SHIFT              (7U)
#define ELS_ELS_KS12_KS12_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_FGP_SHIFT)) & ELS_ELS_KS12_KS12_FGP_MASK)

#define ELS_ELS_KS12_KS12_FRTN_MASK              (0x100U)
#define ELS_ELS_KS12_KS12_FRTN_SHIFT             (8U)
#define ELS_ELS_KS12_KS12_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_FRTN_SHIFT)) & ELS_ELS_KS12_KS12_FRTN_MASK)

#define ELS_ELS_KS12_KS12_FHWO_MASK              (0x200U)
#define ELS_ELS_KS12_KS12_FHWO_SHIFT             (9U)
#define ELS_ELS_KS12_KS12_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_FHWO_SHIFT)) & ELS_ELS_KS12_KS12_FHWO_MASK)

#define ELS_ELS_KS12_KS12_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS12_KS12_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS12_KS12_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UKPUK_SHIFT)) & ELS_ELS_KS12_KS12_UKPUK_MASK)

#define ELS_ELS_KS12_KS12_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS12_KS12_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS12_KS12_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UTECDH_SHIFT)) & ELS_ELS_KS12_KS12_UTECDH_MASK)

#define ELS_ELS_KS12_KS12_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS12_KS12_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS12_KS12_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UCMAC_SHIFT)) & ELS_ELS_KS12_KS12_UCMAC_MASK)

#define ELS_ELS_KS12_KS12_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS12_KS12_UKSK_SHIFT             (14U)
#define ELS_ELS_KS12_KS12_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UKSK_SHIFT)) & ELS_ELS_KS12_KS12_UKSK_MASK)

#define ELS_ELS_KS12_KS12_URTF_MASK              (0x8000U)
#define ELS_ELS_KS12_KS12_URTF_SHIFT             (15U)
#define ELS_ELS_KS12_KS12_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_URTF_SHIFT)) & ELS_ELS_KS12_KS12_URTF_MASK)

#define ELS_ELS_KS12_KS12_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS12_KS12_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS12_KS12_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UCKDF_SHIFT)) & ELS_ELS_KS12_KS12_UCKDF_MASK)

#define ELS_ELS_KS12_KS12_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS12_KS12_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS12_KS12_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UHKDF_SHIFT)) & ELS_ELS_KS12_KS12_UHKDF_MASK)

#define ELS_ELS_KS12_KS12_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS12_KS12_UECSG_SHIFT            (18U)
#define ELS_ELS_KS12_KS12_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UECSG_SHIFT)) & ELS_ELS_KS12_KS12_UECSG_MASK)

#define ELS_ELS_KS12_KS12_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS12_KS12_UECDH_SHIFT            (19U)
#define ELS_ELS_KS12_KS12_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UECDH_SHIFT)) & ELS_ELS_KS12_KS12_UECDH_MASK)

#define ELS_ELS_KS12_KS12_UAES_MASK              (0x100000U)
#define ELS_ELS_KS12_KS12_UAES_SHIFT             (20U)
#define ELS_ELS_KS12_KS12_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UAES_SHIFT)) & ELS_ELS_KS12_KS12_UAES_MASK)

#define ELS_ELS_KS12_KS12_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS12_KS12_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS12_KS12_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UHMAC_SHIFT)) & ELS_ELS_KS12_KS12_UHMAC_MASK)

#define ELS_ELS_KS12_KS12_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS12_KS12_UKWK_SHIFT             (22U)
#define ELS_ELS_KS12_KS12_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UKWK_SHIFT)) & ELS_ELS_KS12_KS12_UKWK_MASK)

#define ELS_ELS_KS12_KS12_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS12_KS12_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS12_KS12_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UKUOK_SHIFT)) & ELS_ELS_KS12_KS12_UKUOK_MASK)

#define ELS_ELS_KS12_KS12_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS12_KS12_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS12_KS12_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UTLSPMS_SHIFT)) & ELS_ELS_KS12_KS12_UTLSPMS_MASK)

#define ELS_ELS_KS12_KS12_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS12_KS12_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS12_KS12_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UTLSMS_SHIFT)) & ELS_ELS_KS12_KS12_UTLSMS_MASK)

#define ELS_ELS_KS12_KS12_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS12_KS12_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS12_KS12_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UKGSRC_SHIFT)) & ELS_ELS_KS12_KS12_UKGSRC_MASK)

#define ELS_ELS_KS12_KS12_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS12_KS12_UHWO_SHIFT             (27U)
#define ELS_ELS_KS12_KS12_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UHWO_SHIFT)) & ELS_ELS_KS12_KS12_UHWO_MASK)

#define ELS_ELS_KS12_KS12_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS12_KS12_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS12_KS12_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UWRPOK_SHIFT)) & ELS_ELS_KS12_KS12_UWRPOK_MASK)

#define ELS_ELS_KS12_KS12_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS12_KS12_UDUK_SHIFT             (29U)
#define ELS_ELS_KS12_KS12_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UDUK_SHIFT)) & ELS_ELS_KS12_KS12_UDUK_MASK)

#define ELS_ELS_KS12_KS12_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS12_KS12_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS12_KS12_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS12_UPPROT_SHIFT)) & ELS_ELS_KS12_KS12_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS13 - Status Register */
/*! @{ */

#define ELS_ELS_KS13_KS13_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS13_KS13_KSIZE_SHIFT            (0U)
/*! KS13_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS13_KS13_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_KSIZE_SHIFT)) & ELS_ELS_KS13_KS13_KSIZE_MASK)

#define ELS_ELS_KS13_KS13_KACT_MASK              (0x20U)
#define ELS_ELS_KS13_KS13_KACT_SHIFT             (5U)
#define ELS_ELS_KS13_KS13_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_KACT_SHIFT)) & ELS_ELS_KS13_KS13_KACT_MASK)

#define ELS_ELS_KS13_KS13_KBASE_MASK             (0x40U)
#define ELS_ELS_KS13_KS13_KBASE_SHIFT            (6U)
#define ELS_ELS_KS13_KS13_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_KBASE_SHIFT)) & ELS_ELS_KS13_KS13_KBASE_MASK)

#define ELS_ELS_KS13_KS13_FGP_MASK               (0x80U)
#define ELS_ELS_KS13_KS13_FGP_SHIFT              (7U)
#define ELS_ELS_KS13_KS13_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_FGP_SHIFT)) & ELS_ELS_KS13_KS13_FGP_MASK)

#define ELS_ELS_KS13_KS13_FRTN_MASK              (0x100U)
#define ELS_ELS_KS13_KS13_FRTN_SHIFT             (8U)
#define ELS_ELS_KS13_KS13_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_FRTN_SHIFT)) & ELS_ELS_KS13_KS13_FRTN_MASK)

#define ELS_ELS_KS13_KS13_FHWO_MASK              (0x200U)
#define ELS_ELS_KS13_KS13_FHWO_SHIFT             (9U)
#define ELS_ELS_KS13_KS13_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_FHWO_SHIFT)) & ELS_ELS_KS13_KS13_FHWO_MASK)

#define ELS_ELS_KS13_KS13_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS13_KS13_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS13_KS13_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UKPUK_SHIFT)) & ELS_ELS_KS13_KS13_UKPUK_MASK)

#define ELS_ELS_KS13_KS13_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS13_KS13_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS13_KS13_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UTECDH_SHIFT)) & ELS_ELS_KS13_KS13_UTECDH_MASK)

#define ELS_ELS_KS13_KS13_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS13_KS13_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS13_KS13_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UCMAC_SHIFT)) & ELS_ELS_KS13_KS13_UCMAC_MASK)

#define ELS_ELS_KS13_KS13_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS13_KS13_UKSK_SHIFT             (14U)
#define ELS_ELS_KS13_KS13_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UKSK_SHIFT)) & ELS_ELS_KS13_KS13_UKSK_MASK)

#define ELS_ELS_KS13_KS13_URTF_MASK              (0x8000U)
#define ELS_ELS_KS13_KS13_URTF_SHIFT             (15U)
#define ELS_ELS_KS13_KS13_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_URTF_SHIFT)) & ELS_ELS_KS13_KS13_URTF_MASK)

#define ELS_ELS_KS13_KS13_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS13_KS13_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS13_KS13_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UCKDF_SHIFT)) & ELS_ELS_KS13_KS13_UCKDF_MASK)

#define ELS_ELS_KS13_KS13_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS13_KS13_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS13_KS13_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UHKDF_SHIFT)) & ELS_ELS_KS13_KS13_UHKDF_MASK)

#define ELS_ELS_KS13_KS13_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS13_KS13_UECSG_SHIFT            (18U)
#define ELS_ELS_KS13_KS13_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UECSG_SHIFT)) & ELS_ELS_KS13_KS13_UECSG_MASK)

#define ELS_ELS_KS13_KS13_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS13_KS13_UECDH_SHIFT            (19U)
#define ELS_ELS_KS13_KS13_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UECDH_SHIFT)) & ELS_ELS_KS13_KS13_UECDH_MASK)

#define ELS_ELS_KS13_KS13_UAES_MASK              (0x100000U)
#define ELS_ELS_KS13_KS13_UAES_SHIFT             (20U)
#define ELS_ELS_KS13_KS13_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UAES_SHIFT)) & ELS_ELS_KS13_KS13_UAES_MASK)

#define ELS_ELS_KS13_KS13_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS13_KS13_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS13_KS13_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UHMAC_SHIFT)) & ELS_ELS_KS13_KS13_UHMAC_MASK)

#define ELS_ELS_KS13_KS13_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS13_KS13_UKWK_SHIFT             (22U)
#define ELS_ELS_KS13_KS13_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UKWK_SHIFT)) & ELS_ELS_KS13_KS13_UKWK_MASK)

#define ELS_ELS_KS13_KS13_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS13_KS13_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS13_KS13_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UKUOK_SHIFT)) & ELS_ELS_KS13_KS13_UKUOK_MASK)

#define ELS_ELS_KS13_KS13_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS13_KS13_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS13_KS13_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UTLSPMS_SHIFT)) & ELS_ELS_KS13_KS13_UTLSPMS_MASK)

#define ELS_ELS_KS13_KS13_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS13_KS13_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS13_KS13_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UTLSMS_SHIFT)) & ELS_ELS_KS13_KS13_UTLSMS_MASK)

#define ELS_ELS_KS13_KS13_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS13_KS13_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS13_KS13_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UKGSRC_SHIFT)) & ELS_ELS_KS13_KS13_UKGSRC_MASK)

#define ELS_ELS_KS13_KS13_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS13_KS13_UHWO_SHIFT             (27U)
#define ELS_ELS_KS13_KS13_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UHWO_SHIFT)) & ELS_ELS_KS13_KS13_UHWO_MASK)

#define ELS_ELS_KS13_KS13_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS13_KS13_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS13_KS13_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UWRPOK_SHIFT)) & ELS_ELS_KS13_KS13_UWRPOK_MASK)

#define ELS_ELS_KS13_KS13_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS13_KS13_UDUK_SHIFT             (29U)
#define ELS_ELS_KS13_KS13_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UDUK_SHIFT)) & ELS_ELS_KS13_KS13_UDUK_MASK)

#define ELS_ELS_KS13_KS13_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS13_KS13_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS13_KS13_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS13_UPPROT_SHIFT)) & ELS_ELS_KS13_KS13_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS14 - Status Register */
/*! @{ */

#define ELS_ELS_KS14_KS14_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS14_KS14_KSIZE_SHIFT            (0U)
/*! KS14_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS14_KS14_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_KSIZE_SHIFT)) & ELS_ELS_KS14_KS14_KSIZE_MASK)

#define ELS_ELS_KS14_KS14_KACT_MASK              (0x20U)
#define ELS_ELS_KS14_KS14_KACT_SHIFT             (5U)
#define ELS_ELS_KS14_KS14_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_KACT_SHIFT)) & ELS_ELS_KS14_KS14_KACT_MASK)

#define ELS_ELS_KS14_KS14_KBASE_MASK             (0x40U)
#define ELS_ELS_KS14_KS14_KBASE_SHIFT            (6U)
#define ELS_ELS_KS14_KS14_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_KBASE_SHIFT)) & ELS_ELS_KS14_KS14_KBASE_MASK)

#define ELS_ELS_KS14_KS14_FGP_MASK               (0x80U)
#define ELS_ELS_KS14_KS14_FGP_SHIFT              (7U)
#define ELS_ELS_KS14_KS14_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_FGP_SHIFT)) & ELS_ELS_KS14_KS14_FGP_MASK)

#define ELS_ELS_KS14_KS14_FRTN_MASK              (0x100U)
#define ELS_ELS_KS14_KS14_FRTN_SHIFT             (8U)
#define ELS_ELS_KS14_KS14_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_FRTN_SHIFT)) & ELS_ELS_KS14_KS14_FRTN_MASK)

#define ELS_ELS_KS14_KS14_FHWO_MASK              (0x200U)
#define ELS_ELS_KS14_KS14_FHWO_SHIFT             (9U)
#define ELS_ELS_KS14_KS14_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_FHWO_SHIFT)) & ELS_ELS_KS14_KS14_FHWO_MASK)

#define ELS_ELS_KS14_KS14_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS14_KS14_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS14_KS14_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UKPUK_SHIFT)) & ELS_ELS_KS14_KS14_UKPUK_MASK)

#define ELS_ELS_KS14_KS14_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS14_KS14_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS14_KS14_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UTECDH_SHIFT)) & ELS_ELS_KS14_KS14_UTECDH_MASK)

#define ELS_ELS_KS14_KS14_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS14_KS14_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS14_KS14_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UCMAC_SHIFT)) & ELS_ELS_KS14_KS14_UCMAC_MASK)

#define ELS_ELS_KS14_KS14_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS14_KS14_UKSK_SHIFT             (14U)
#define ELS_ELS_KS14_KS14_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UKSK_SHIFT)) & ELS_ELS_KS14_KS14_UKSK_MASK)

#define ELS_ELS_KS14_KS14_URTF_MASK              (0x8000U)
#define ELS_ELS_KS14_KS14_URTF_SHIFT             (15U)
#define ELS_ELS_KS14_KS14_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_URTF_SHIFT)) & ELS_ELS_KS14_KS14_URTF_MASK)

#define ELS_ELS_KS14_KS14_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS14_KS14_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS14_KS14_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UCKDF_SHIFT)) & ELS_ELS_KS14_KS14_UCKDF_MASK)

#define ELS_ELS_KS14_KS14_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS14_KS14_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS14_KS14_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UHKDF_SHIFT)) & ELS_ELS_KS14_KS14_UHKDF_MASK)

#define ELS_ELS_KS14_KS14_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS14_KS14_UECSG_SHIFT            (18U)
#define ELS_ELS_KS14_KS14_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UECSG_SHIFT)) & ELS_ELS_KS14_KS14_UECSG_MASK)

#define ELS_ELS_KS14_KS14_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS14_KS14_UECDH_SHIFT            (19U)
#define ELS_ELS_KS14_KS14_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UECDH_SHIFT)) & ELS_ELS_KS14_KS14_UECDH_MASK)

#define ELS_ELS_KS14_KS14_UAES_MASK              (0x100000U)
#define ELS_ELS_KS14_KS14_UAES_SHIFT             (20U)
#define ELS_ELS_KS14_KS14_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UAES_SHIFT)) & ELS_ELS_KS14_KS14_UAES_MASK)

#define ELS_ELS_KS14_KS14_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS14_KS14_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS14_KS14_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UHMAC_SHIFT)) & ELS_ELS_KS14_KS14_UHMAC_MASK)

#define ELS_ELS_KS14_KS14_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS14_KS14_UKWK_SHIFT             (22U)
#define ELS_ELS_KS14_KS14_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UKWK_SHIFT)) & ELS_ELS_KS14_KS14_UKWK_MASK)

#define ELS_ELS_KS14_KS14_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS14_KS14_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS14_KS14_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UKUOK_SHIFT)) & ELS_ELS_KS14_KS14_UKUOK_MASK)

#define ELS_ELS_KS14_KS14_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS14_KS14_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS14_KS14_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UTLSPMS_SHIFT)) & ELS_ELS_KS14_KS14_UTLSPMS_MASK)

#define ELS_ELS_KS14_KS14_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS14_KS14_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS14_KS14_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UTLSMS_SHIFT)) & ELS_ELS_KS14_KS14_UTLSMS_MASK)

#define ELS_ELS_KS14_KS14_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS14_KS14_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS14_KS14_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UKGSRC_SHIFT)) & ELS_ELS_KS14_KS14_UKGSRC_MASK)

#define ELS_ELS_KS14_KS14_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS14_KS14_UHWO_SHIFT             (27U)
#define ELS_ELS_KS14_KS14_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UHWO_SHIFT)) & ELS_ELS_KS14_KS14_UHWO_MASK)

#define ELS_ELS_KS14_KS14_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS14_KS14_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS14_KS14_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UWRPOK_SHIFT)) & ELS_ELS_KS14_KS14_UWRPOK_MASK)

#define ELS_ELS_KS14_KS14_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS14_KS14_UDUK_SHIFT             (29U)
#define ELS_ELS_KS14_KS14_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UDUK_SHIFT)) & ELS_ELS_KS14_KS14_UDUK_MASK)

#define ELS_ELS_KS14_KS14_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS14_KS14_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS14_KS14_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS14_UPPROT_SHIFT)) & ELS_ELS_KS14_KS14_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS15 - Status Register */
/*! @{ */

#define ELS_ELS_KS15_KS15_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS15_KS15_KSIZE_SHIFT            (0U)
/*! KS15_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS15_KS15_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_KSIZE_SHIFT)) & ELS_ELS_KS15_KS15_KSIZE_MASK)

#define ELS_ELS_KS15_KS15_KACT_MASK              (0x20U)
#define ELS_ELS_KS15_KS15_KACT_SHIFT             (5U)
#define ELS_ELS_KS15_KS15_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_KACT_SHIFT)) & ELS_ELS_KS15_KS15_KACT_MASK)

#define ELS_ELS_KS15_KS15_KBASE_MASK             (0x40U)
#define ELS_ELS_KS15_KS15_KBASE_SHIFT            (6U)
#define ELS_ELS_KS15_KS15_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_KBASE_SHIFT)) & ELS_ELS_KS15_KS15_KBASE_MASK)

#define ELS_ELS_KS15_KS15_FGP_MASK               (0x80U)
#define ELS_ELS_KS15_KS15_FGP_SHIFT              (7U)
#define ELS_ELS_KS15_KS15_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_FGP_SHIFT)) & ELS_ELS_KS15_KS15_FGP_MASK)

#define ELS_ELS_KS15_KS15_FRTN_MASK              (0x100U)
#define ELS_ELS_KS15_KS15_FRTN_SHIFT             (8U)
#define ELS_ELS_KS15_KS15_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_FRTN_SHIFT)) & ELS_ELS_KS15_KS15_FRTN_MASK)

#define ELS_ELS_KS15_KS15_FHWO_MASK              (0x200U)
#define ELS_ELS_KS15_KS15_FHWO_SHIFT             (9U)
#define ELS_ELS_KS15_KS15_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_FHWO_SHIFT)) & ELS_ELS_KS15_KS15_FHWO_MASK)

#define ELS_ELS_KS15_KS15_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS15_KS15_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS15_KS15_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UKPUK_SHIFT)) & ELS_ELS_KS15_KS15_UKPUK_MASK)

#define ELS_ELS_KS15_KS15_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS15_KS15_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS15_KS15_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UTECDH_SHIFT)) & ELS_ELS_KS15_KS15_UTECDH_MASK)

#define ELS_ELS_KS15_KS15_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS15_KS15_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS15_KS15_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UCMAC_SHIFT)) & ELS_ELS_KS15_KS15_UCMAC_MASK)

#define ELS_ELS_KS15_KS15_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS15_KS15_UKSK_SHIFT             (14U)
#define ELS_ELS_KS15_KS15_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UKSK_SHIFT)) & ELS_ELS_KS15_KS15_UKSK_MASK)

#define ELS_ELS_KS15_KS15_URTF_MASK              (0x8000U)
#define ELS_ELS_KS15_KS15_URTF_SHIFT             (15U)
#define ELS_ELS_KS15_KS15_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_URTF_SHIFT)) & ELS_ELS_KS15_KS15_URTF_MASK)

#define ELS_ELS_KS15_KS15_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS15_KS15_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS15_KS15_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UCKDF_SHIFT)) & ELS_ELS_KS15_KS15_UCKDF_MASK)

#define ELS_ELS_KS15_KS15_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS15_KS15_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS15_KS15_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UHKDF_SHIFT)) & ELS_ELS_KS15_KS15_UHKDF_MASK)

#define ELS_ELS_KS15_KS15_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS15_KS15_UECSG_SHIFT            (18U)
#define ELS_ELS_KS15_KS15_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UECSG_SHIFT)) & ELS_ELS_KS15_KS15_UECSG_MASK)

#define ELS_ELS_KS15_KS15_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS15_KS15_UECDH_SHIFT            (19U)
#define ELS_ELS_KS15_KS15_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UECDH_SHIFT)) & ELS_ELS_KS15_KS15_UECDH_MASK)

#define ELS_ELS_KS15_KS15_UAES_MASK              (0x100000U)
#define ELS_ELS_KS15_KS15_UAES_SHIFT             (20U)
#define ELS_ELS_KS15_KS15_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UAES_SHIFT)) & ELS_ELS_KS15_KS15_UAES_MASK)

#define ELS_ELS_KS15_KS15_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS15_KS15_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS15_KS15_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UHMAC_SHIFT)) & ELS_ELS_KS15_KS15_UHMAC_MASK)

#define ELS_ELS_KS15_KS15_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS15_KS15_UKWK_SHIFT             (22U)
#define ELS_ELS_KS15_KS15_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UKWK_SHIFT)) & ELS_ELS_KS15_KS15_UKWK_MASK)

#define ELS_ELS_KS15_KS15_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS15_KS15_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS15_KS15_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UKUOK_SHIFT)) & ELS_ELS_KS15_KS15_UKUOK_MASK)

#define ELS_ELS_KS15_KS15_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS15_KS15_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS15_KS15_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UTLSPMS_SHIFT)) & ELS_ELS_KS15_KS15_UTLSPMS_MASK)

#define ELS_ELS_KS15_KS15_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS15_KS15_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS15_KS15_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UTLSMS_SHIFT)) & ELS_ELS_KS15_KS15_UTLSMS_MASK)

#define ELS_ELS_KS15_KS15_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS15_KS15_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS15_KS15_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UKGSRC_SHIFT)) & ELS_ELS_KS15_KS15_UKGSRC_MASK)

#define ELS_ELS_KS15_KS15_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS15_KS15_UHWO_SHIFT             (27U)
#define ELS_ELS_KS15_KS15_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UHWO_SHIFT)) & ELS_ELS_KS15_KS15_UHWO_MASK)

#define ELS_ELS_KS15_KS15_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS15_KS15_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS15_KS15_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UWRPOK_SHIFT)) & ELS_ELS_KS15_KS15_UWRPOK_MASK)

#define ELS_ELS_KS15_KS15_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS15_KS15_UDUK_SHIFT             (29U)
#define ELS_ELS_KS15_KS15_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UDUK_SHIFT)) & ELS_ELS_KS15_KS15_UDUK_MASK)

#define ELS_ELS_KS15_KS15_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS15_KS15_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS15_KS15_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS15_UPPROT_SHIFT)) & ELS_ELS_KS15_KS15_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS16 - Status Register */
/*! @{ */

#define ELS_ELS_KS16_KS16_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS16_KS16_KSIZE_SHIFT            (0U)
/*! KS16_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS16_KS16_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_KSIZE_SHIFT)) & ELS_ELS_KS16_KS16_KSIZE_MASK)

#define ELS_ELS_KS16_KS16_KACT_MASK              (0x20U)
#define ELS_ELS_KS16_KS16_KACT_SHIFT             (5U)
#define ELS_ELS_KS16_KS16_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_KACT_SHIFT)) & ELS_ELS_KS16_KS16_KACT_MASK)

#define ELS_ELS_KS16_KS16_KBASE_MASK             (0x40U)
#define ELS_ELS_KS16_KS16_KBASE_SHIFT            (6U)
#define ELS_ELS_KS16_KS16_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_KBASE_SHIFT)) & ELS_ELS_KS16_KS16_KBASE_MASK)

#define ELS_ELS_KS16_KS16_FGP_MASK               (0x80U)
#define ELS_ELS_KS16_KS16_FGP_SHIFT              (7U)
#define ELS_ELS_KS16_KS16_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_FGP_SHIFT)) & ELS_ELS_KS16_KS16_FGP_MASK)

#define ELS_ELS_KS16_KS16_FRTN_MASK              (0x100U)
#define ELS_ELS_KS16_KS16_FRTN_SHIFT             (8U)
#define ELS_ELS_KS16_KS16_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_FRTN_SHIFT)) & ELS_ELS_KS16_KS16_FRTN_MASK)

#define ELS_ELS_KS16_KS16_FHWO_MASK              (0x200U)
#define ELS_ELS_KS16_KS16_FHWO_SHIFT             (9U)
#define ELS_ELS_KS16_KS16_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_FHWO_SHIFT)) & ELS_ELS_KS16_KS16_FHWO_MASK)

#define ELS_ELS_KS16_KS16_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS16_KS16_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS16_KS16_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UKPUK_SHIFT)) & ELS_ELS_KS16_KS16_UKPUK_MASK)

#define ELS_ELS_KS16_KS16_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS16_KS16_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS16_KS16_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UTECDH_SHIFT)) & ELS_ELS_KS16_KS16_UTECDH_MASK)

#define ELS_ELS_KS16_KS16_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS16_KS16_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS16_KS16_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UCMAC_SHIFT)) & ELS_ELS_KS16_KS16_UCMAC_MASK)

#define ELS_ELS_KS16_KS16_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS16_KS16_UKSK_SHIFT             (14U)
#define ELS_ELS_KS16_KS16_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UKSK_SHIFT)) & ELS_ELS_KS16_KS16_UKSK_MASK)

#define ELS_ELS_KS16_KS16_URTF_MASK              (0x8000U)
#define ELS_ELS_KS16_KS16_URTF_SHIFT             (15U)
#define ELS_ELS_KS16_KS16_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_URTF_SHIFT)) & ELS_ELS_KS16_KS16_URTF_MASK)

#define ELS_ELS_KS16_KS16_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS16_KS16_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS16_KS16_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UCKDF_SHIFT)) & ELS_ELS_KS16_KS16_UCKDF_MASK)

#define ELS_ELS_KS16_KS16_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS16_KS16_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS16_KS16_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UHKDF_SHIFT)) & ELS_ELS_KS16_KS16_UHKDF_MASK)

#define ELS_ELS_KS16_KS16_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS16_KS16_UECSG_SHIFT            (18U)
#define ELS_ELS_KS16_KS16_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UECSG_SHIFT)) & ELS_ELS_KS16_KS16_UECSG_MASK)

#define ELS_ELS_KS16_KS16_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS16_KS16_UECDH_SHIFT            (19U)
#define ELS_ELS_KS16_KS16_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UECDH_SHIFT)) & ELS_ELS_KS16_KS16_UECDH_MASK)

#define ELS_ELS_KS16_KS16_UAES_MASK              (0x100000U)
#define ELS_ELS_KS16_KS16_UAES_SHIFT             (20U)
#define ELS_ELS_KS16_KS16_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UAES_SHIFT)) & ELS_ELS_KS16_KS16_UAES_MASK)

#define ELS_ELS_KS16_KS16_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS16_KS16_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS16_KS16_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UHMAC_SHIFT)) & ELS_ELS_KS16_KS16_UHMAC_MASK)

#define ELS_ELS_KS16_KS16_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS16_KS16_UKWK_SHIFT             (22U)
#define ELS_ELS_KS16_KS16_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UKWK_SHIFT)) & ELS_ELS_KS16_KS16_UKWK_MASK)

#define ELS_ELS_KS16_KS16_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS16_KS16_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS16_KS16_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UKUOK_SHIFT)) & ELS_ELS_KS16_KS16_UKUOK_MASK)

#define ELS_ELS_KS16_KS16_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS16_KS16_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS16_KS16_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UTLSPMS_SHIFT)) & ELS_ELS_KS16_KS16_UTLSPMS_MASK)

#define ELS_ELS_KS16_KS16_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS16_KS16_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS16_KS16_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UTLSMS_SHIFT)) & ELS_ELS_KS16_KS16_UTLSMS_MASK)

#define ELS_ELS_KS16_KS16_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS16_KS16_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS16_KS16_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UKGSRC_SHIFT)) & ELS_ELS_KS16_KS16_UKGSRC_MASK)

#define ELS_ELS_KS16_KS16_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS16_KS16_UHWO_SHIFT             (27U)
#define ELS_ELS_KS16_KS16_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UHWO_SHIFT)) & ELS_ELS_KS16_KS16_UHWO_MASK)

#define ELS_ELS_KS16_KS16_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS16_KS16_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS16_KS16_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UWRPOK_SHIFT)) & ELS_ELS_KS16_KS16_UWRPOK_MASK)

#define ELS_ELS_KS16_KS16_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS16_KS16_UDUK_SHIFT             (29U)
#define ELS_ELS_KS16_KS16_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UDUK_SHIFT)) & ELS_ELS_KS16_KS16_UDUK_MASK)

#define ELS_ELS_KS16_KS16_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS16_KS16_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS16_KS16_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS16_UPPROT_SHIFT)) & ELS_ELS_KS16_KS16_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS17 - Status Register */
/*! @{ */

#define ELS_ELS_KS17_KS17_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS17_KS17_KSIZE_SHIFT            (0U)
/*! KS17_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS17_KS17_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_KSIZE_SHIFT)) & ELS_ELS_KS17_KS17_KSIZE_MASK)

#define ELS_ELS_KS17_KS17_KACT_MASK              (0x20U)
#define ELS_ELS_KS17_KS17_KACT_SHIFT             (5U)
#define ELS_ELS_KS17_KS17_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_KACT_SHIFT)) & ELS_ELS_KS17_KS17_KACT_MASK)

#define ELS_ELS_KS17_KS17_KBASE_MASK             (0x40U)
#define ELS_ELS_KS17_KS17_KBASE_SHIFT            (6U)
#define ELS_ELS_KS17_KS17_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_KBASE_SHIFT)) & ELS_ELS_KS17_KS17_KBASE_MASK)

#define ELS_ELS_KS17_KS17_FGP_MASK               (0x80U)
#define ELS_ELS_KS17_KS17_FGP_SHIFT              (7U)
#define ELS_ELS_KS17_KS17_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_FGP_SHIFT)) & ELS_ELS_KS17_KS17_FGP_MASK)

#define ELS_ELS_KS17_KS17_FRTN_MASK              (0x100U)
#define ELS_ELS_KS17_KS17_FRTN_SHIFT             (8U)
#define ELS_ELS_KS17_KS17_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_FRTN_SHIFT)) & ELS_ELS_KS17_KS17_FRTN_MASK)

#define ELS_ELS_KS17_KS17_FHWO_MASK              (0x200U)
#define ELS_ELS_KS17_KS17_FHWO_SHIFT             (9U)
#define ELS_ELS_KS17_KS17_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_FHWO_SHIFT)) & ELS_ELS_KS17_KS17_FHWO_MASK)

#define ELS_ELS_KS17_KS17_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS17_KS17_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS17_KS17_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UKPUK_SHIFT)) & ELS_ELS_KS17_KS17_UKPUK_MASK)

#define ELS_ELS_KS17_KS17_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS17_KS17_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS17_KS17_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UTECDH_SHIFT)) & ELS_ELS_KS17_KS17_UTECDH_MASK)

#define ELS_ELS_KS17_KS17_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS17_KS17_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS17_KS17_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UCMAC_SHIFT)) & ELS_ELS_KS17_KS17_UCMAC_MASK)

#define ELS_ELS_KS17_KS17_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS17_KS17_UKSK_SHIFT             (14U)
#define ELS_ELS_KS17_KS17_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UKSK_SHIFT)) & ELS_ELS_KS17_KS17_UKSK_MASK)

#define ELS_ELS_KS17_KS17_URTF_MASK              (0x8000U)
#define ELS_ELS_KS17_KS17_URTF_SHIFT             (15U)
#define ELS_ELS_KS17_KS17_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_URTF_SHIFT)) & ELS_ELS_KS17_KS17_URTF_MASK)

#define ELS_ELS_KS17_KS17_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS17_KS17_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS17_KS17_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UCKDF_SHIFT)) & ELS_ELS_KS17_KS17_UCKDF_MASK)

#define ELS_ELS_KS17_KS17_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS17_KS17_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS17_KS17_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UHKDF_SHIFT)) & ELS_ELS_KS17_KS17_UHKDF_MASK)

#define ELS_ELS_KS17_KS17_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS17_KS17_UECSG_SHIFT            (18U)
#define ELS_ELS_KS17_KS17_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UECSG_SHIFT)) & ELS_ELS_KS17_KS17_UECSG_MASK)

#define ELS_ELS_KS17_KS17_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS17_KS17_UECDH_SHIFT            (19U)
#define ELS_ELS_KS17_KS17_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UECDH_SHIFT)) & ELS_ELS_KS17_KS17_UECDH_MASK)

#define ELS_ELS_KS17_KS17_UAES_MASK              (0x100000U)
#define ELS_ELS_KS17_KS17_UAES_SHIFT             (20U)
#define ELS_ELS_KS17_KS17_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UAES_SHIFT)) & ELS_ELS_KS17_KS17_UAES_MASK)

#define ELS_ELS_KS17_KS17_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS17_KS17_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS17_KS17_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UHMAC_SHIFT)) & ELS_ELS_KS17_KS17_UHMAC_MASK)

#define ELS_ELS_KS17_KS17_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS17_KS17_UKWK_SHIFT             (22U)
#define ELS_ELS_KS17_KS17_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UKWK_SHIFT)) & ELS_ELS_KS17_KS17_UKWK_MASK)

#define ELS_ELS_KS17_KS17_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS17_KS17_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS17_KS17_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UKUOK_SHIFT)) & ELS_ELS_KS17_KS17_UKUOK_MASK)

#define ELS_ELS_KS17_KS17_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS17_KS17_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS17_KS17_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UTLSPMS_SHIFT)) & ELS_ELS_KS17_KS17_UTLSPMS_MASK)

#define ELS_ELS_KS17_KS17_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS17_KS17_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS17_KS17_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UTLSMS_SHIFT)) & ELS_ELS_KS17_KS17_UTLSMS_MASK)

#define ELS_ELS_KS17_KS17_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS17_KS17_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS17_KS17_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UKGSRC_SHIFT)) & ELS_ELS_KS17_KS17_UKGSRC_MASK)

#define ELS_ELS_KS17_KS17_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS17_KS17_UHWO_SHIFT             (27U)
#define ELS_ELS_KS17_KS17_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UHWO_SHIFT)) & ELS_ELS_KS17_KS17_UHWO_MASK)

#define ELS_ELS_KS17_KS17_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS17_KS17_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS17_KS17_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UWRPOK_SHIFT)) & ELS_ELS_KS17_KS17_UWRPOK_MASK)

#define ELS_ELS_KS17_KS17_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS17_KS17_UDUK_SHIFT             (29U)
#define ELS_ELS_KS17_KS17_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UDUK_SHIFT)) & ELS_ELS_KS17_KS17_UDUK_MASK)

#define ELS_ELS_KS17_KS17_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS17_KS17_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS17_KS17_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS17_UPPROT_SHIFT)) & ELS_ELS_KS17_KS17_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS18 - Status Register */
/*! @{ */

#define ELS_ELS_KS18_KS18_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS18_KS18_KSIZE_SHIFT            (0U)
/*! KS18_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS18_KS18_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_KSIZE_SHIFT)) & ELS_ELS_KS18_KS18_KSIZE_MASK)

#define ELS_ELS_KS18_KS18_KACT_MASK              (0x20U)
#define ELS_ELS_KS18_KS18_KACT_SHIFT             (5U)
#define ELS_ELS_KS18_KS18_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_KACT_SHIFT)) & ELS_ELS_KS18_KS18_KACT_MASK)

#define ELS_ELS_KS18_KS18_KBASE_MASK             (0x40U)
#define ELS_ELS_KS18_KS18_KBASE_SHIFT            (6U)
#define ELS_ELS_KS18_KS18_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_KBASE_SHIFT)) & ELS_ELS_KS18_KS18_KBASE_MASK)

#define ELS_ELS_KS18_KS18_FGP_MASK               (0x80U)
#define ELS_ELS_KS18_KS18_FGP_SHIFT              (7U)
#define ELS_ELS_KS18_KS18_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_FGP_SHIFT)) & ELS_ELS_KS18_KS18_FGP_MASK)

#define ELS_ELS_KS18_KS18_FRTN_MASK              (0x100U)
#define ELS_ELS_KS18_KS18_FRTN_SHIFT             (8U)
#define ELS_ELS_KS18_KS18_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_FRTN_SHIFT)) & ELS_ELS_KS18_KS18_FRTN_MASK)

#define ELS_ELS_KS18_KS18_FHWO_MASK              (0x200U)
#define ELS_ELS_KS18_KS18_FHWO_SHIFT             (9U)
#define ELS_ELS_KS18_KS18_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_FHWO_SHIFT)) & ELS_ELS_KS18_KS18_FHWO_MASK)

#define ELS_ELS_KS18_KS18_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS18_KS18_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS18_KS18_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UKPUK_SHIFT)) & ELS_ELS_KS18_KS18_UKPUK_MASK)

#define ELS_ELS_KS18_KS18_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS18_KS18_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS18_KS18_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UTECDH_SHIFT)) & ELS_ELS_KS18_KS18_UTECDH_MASK)

#define ELS_ELS_KS18_KS18_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS18_KS18_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS18_KS18_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UCMAC_SHIFT)) & ELS_ELS_KS18_KS18_UCMAC_MASK)

#define ELS_ELS_KS18_KS18_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS18_KS18_UKSK_SHIFT             (14U)
#define ELS_ELS_KS18_KS18_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UKSK_SHIFT)) & ELS_ELS_KS18_KS18_UKSK_MASK)

#define ELS_ELS_KS18_KS18_URTF_MASK              (0x8000U)
#define ELS_ELS_KS18_KS18_URTF_SHIFT             (15U)
#define ELS_ELS_KS18_KS18_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_URTF_SHIFT)) & ELS_ELS_KS18_KS18_URTF_MASK)

#define ELS_ELS_KS18_KS18_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS18_KS18_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS18_KS18_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UCKDF_SHIFT)) & ELS_ELS_KS18_KS18_UCKDF_MASK)

#define ELS_ELS_KS18_KS18_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS18_KS18_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS18_KS18_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UHKDF_SHIFT)) & ELS_ELS_KS18_KS18_UHKDF_MASK)

#define ELS_ELS_KS18_KS18_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS18_KS18_UECSG_SHIFT            (18U)
#define ELS_ELS_KS18_KS18_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UECSG_SHIFT)) & ELS_ELS_KS18_KS18_UECSG_MASK)

#define ELS_ELS_KS18_KS18_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS18_KS18_UECDH_SHIFT            (19U)
#define ELS_ELS_KS18_KS18_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UECDH_SHIFT)) & ELS_ELS_KS18_KS18_UECDH_MASK)

#define ELS_ELS_KS18_KS18_UAES_MASK              (0x100000U)
#define ELS_ELS_KS18_KS18_UAES_SHIFT             (20U)
#define ELS_ELS_KS18_KS18_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UAES_SHIFT)) & ELS_ELS_KS18_KS18_UAES_MASK)

#define ELS_ELS_KS18_KS18_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS18_KS18_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS18_KS18_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UHMAC_SHIFT)) & ELS_ELS_KS18_KS18_UHMAC_MASK)

#define ELS_ELS_KS18_KS18_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS18_KS18_UKWK_SHIFT             (22U)
#define ELS_ELS_KS18_KS18_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UKWK_SHIFT)) & ELS_ELS_KS18_KS18_UKWK_MASK)

#define ELS_ELS_KS18_KS18_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS18_KS18_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS18_KS18_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UKUOK_SHIFT)) & ELS_ELS_KS18_KS18_UKUOK_MASK)

#define ELS_ELS_KS18_KS18_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS18_KS18_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS18_KS18_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UTLSPMS_SHIFT)) & ELS_ELS_KS18_KS18_UTLSPMS_MASK)

#define ELS_ELS_KS18_KS18_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS18_KS18_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS18_KS18_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UTLSMS_SHIFT)) & ELS_ELS_KS18_KS18_UTLSMS_MASK)

#define ELS_ELS_KS18_KS18_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS18_KS18_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS18_KS18_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UKGSRC_SHIFT)) & ELS_ELS_KS18_KS18_UKGSRC_MASK)

#define ELS_ELS_KS18_KS18_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS18_KS18_UHWO_SHIFT             (27U)
#define ELS_ELS_KS18_KS18_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UHWO_SHIFT)) & ELS_ELS_KS18_KS18_UHWO_MASK)

#define ELS_ELS_KS18_KS18_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS18_KS18_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS18_KS18_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UWRPOK_SHIFT)) & ELS_ELS_KS18_KS18_UWRPOK_MASK)

#define ELS_ELS_KS18_KS18_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS18_KS18_UDUK_SHIFT             (29U)
#define ELS_ELS_KS18_KS18_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UDUK_SHIFT)) & ELS_ELS_KS18_KS18_UDUK_MASK)

#define ELS_ELS_KS18_KS18_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS18_KS18_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS18_KS18_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS18_UPPROT_SHIFT)) & ELS_ELS_KS18_KS18_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS19 - Status Register */
/*! @{ */

#define ELS_ELS_KS19_KS19_KSIZE_MASK             (0x3U)
#define ELS_ELS_KS19_KS19_KSIZE_SHIFT            (0U)
/*! KS19_KSIZE
 *  0b00..128
 *  0b01..256
 */
#define ELS_ELS_KS19_KS19_KSIZE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_KSIZE_SHIFT)) & ELS_ELS_KS19_KS19_KSIZE_MASK)

#define ELS_ELS_KS19_KS19_KACT_MASK              (0x20U)
#define ELS_ELS_KS19_KS19_KACT_SHIFT             (5U)
#define ELS_ELS_KS19_KS19_KACT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_KACT_SHIFT)) & ELS_ELS_KS19_KS19_KACT_MASK)

#define ELS_ELS_KS19_KS19_KBASE_MASK             (0x40U)
#define ELS_ELS_KS19_KS19_KBASE_SHIFT            (6U)
#define ELS_ELS_KS19_KS19_KBASE(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_KBASE_SHIFT)) & ELS_ELS_KS19_KS19_KBASE_MASK)

#define ELS_ELS_KS19_KS19_FGP_MASK               (0x80U)
#define ELS_ELS_KS19_KS19_FGP_SHIFT              (7U)
#define ELS_ELS_KS19_KS19_FGP(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_FGP_SHIFT)) & ELS_ELS_KS19_KS19_FGP_MASK)

#define ELS_ELS_KS19_KS19_FRTN_MASK              (0x100U)
#define ELS_ELS_KS19_KS19_FRTN_SHIFT             (8U)
#define ELS_ELS_KS19_KS19_FRTN(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_FRTN_SHIFT)) & ELS_ELS_KS19_KS19_FRTN_MASK)

#define ELS_ELS_KS19_KS19_FHWO_MASK              (0x200U)
#define ELS_ELS_KS19_KS19_FHWO_SHIFT             (9U)
#define ELS_ELS_KS19_KS19_FHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_FHWO_SHIFT)) & ELS_ELS_KS19_KS19_FHWO_MASK)

#define ELS_ELS_KS19_KS19_UKPUK_MASK             (0x800U)
#define ELS_ELS_KS19_KS19_UKPUK_SHIFT            (11U)
#define ELS_ELS_KS19_KS19_UKPUK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UKPUK_SHIFT)) & ELS_ELS_KS19_KS19_UKPUK_MASK)

#define ELS_ELS_KS19_KS19_UTECDH_MASK            (0x1000U)
#define ELS_ELS_KS19_KS19_UTECDH_SHIFT           (12U)
#define ELS_ELS_KS19_KS19_UTECDH(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UTECDH_SHIFT)) & ELS_ELS_KS19_KS19_UTECDH_MASK)

#define ELS_ELS_KS19_KS19_UCMAC_MASK             (0x2000U)
#define ELS_ELS_KS19_KS19_UCMAC_SHIFT            (13U)
#define ELS_ELS_KS19_KS19_UCMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UCMAC_SHIFT)) & ELS_ELS_KS19_KS19_UCMAC_MASK)

#define ELS_ELS_KS19_KS19_UKSK_MASK              (0x4000U)
#define ELS_ELS_KS19_KS19_UKSK_SHIFT             (14U)
#define ELS_ELS_KS19_KS19_UKSK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UKSK_SHIFT)) & ELS_ELS_KS19_KS19_UKSK_MASK)

#define ELS_ELS_KS19_KS19_URTF_MASK              (0x8000U)
#define ELS_ELS_KS19_KS19_URTF_SHIFT             (15U)
#define ELS_ELS_KS19_KS19_URTF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_URTF_SHIFT)) & ELS_ELS_KS19_KS19_URTF_MASK)

#define ELS_ELS_KS19_KS19_UCKDF_MASK             (0x10000U)
#define ELS_ELS_KS19_KS19_UCKDF_SHIFT            (16U)
#define ELS_ELS_KS19_KS19_UCKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UCKDF_SHIFT)) & ELS_ELS_KS19_KS19_UCKDF_MASK)

#define ELS_ELS_KS19_KS19_UHKDF_MASK             (0x20000U)
#define ELS_ELS_KS19_KS19_UHKDF_SHIFT            (17U)
#define ELS_ELS_KS19_KS19_UHKDF(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UHKDF_SHIFT)) & ELS_ELS_KS19_KS19_UHKDF_MASK)

#define ELS_ELS_KS19_KS19_UECSG_MASK             (0x40000U)
#define ELS_ELS_KS19_KS19_UECSG_SHIFT            (18U)
#define ELS_ELS_KS19_KS19_UECSG(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UECSG_SHIFT)) & ELS_ELS_KS19_KS19_UECSG_MASK)

#define ELS_ELS_KS19_KS19_UECDH_MASK             (0x80000U)
#define ELS_ELS_KS19_KS19_UECDH_SHIFT            (19U)
#define ELS_ELS_KS19_KS19_UECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UECDH_SHIFT)) & ELS_ELS_KS19_KS19_UECDH_MASK)

#define ELS_ELS_KS19_KS19_UAES_MASK              (0x100000U)
#define ELS_ELS_KS19_KS19_UAES_SHIFT             (20U)
#define ELS_ELS_KS19_KS19_UAES(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UAES_SHIFT)) & ELS_ELS_KS19_KS19_UAES_MASK)

#define ELS_ELS_KS19_KS19_UHMAC_MASK             (0x200000U)
#define ELS_ELS_KS19_KS19_UHMAC_SHIFT            (21U)
#define ELS_ELS_KS19_KS19_UHMAC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UHMAC_SHIFT)) & ELS_ELS_KS19_KS19_UHMAC_MASK)

#define ELS_ELS_KS19_KS19_UKWK_MASK              (0x400000U)
#define ELS_ELS_KS19_KS19_UKWK_SHIFT             (22U)
#define ELS_ELS_KS19_KS19_UKWK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UKWK_SHIFT)) & ELS_ELS_KS19_KS19_UKWK_MASK)

#define ELS_ELS_KS19_KS19_UKUOK_MASK             (0x800000U)
#define ELS_ELS_KS19_KS19_UKUOK_SHIFT            (23U)
#define ELS_ELS_KS19_KS19_UKUOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UKUOK_SHIFT)) & ELS_ELS_KS19_KS19_UKUOK_MASK)

#define ELS_ELS_KS19_KS19_UTLSPMS_MASK           (0x1000000U)
#define ELS_ELS_KS19_KS19_UTLSPMS_SHIFT          (24U)
#define ELS_ELS_KS19_KS19_UTLSPMS(x)             (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UTLSPMS_SHIFT)) & ELS_ELS_KS19_KS19_UTLSPMS_MASK)

#define ELS_ELS_KS19_KS19_UTLSMS_MASK            (0x2000000U)
#define ELS_ELS_KS19_KS19_UTLSMS_SHIFT           (25U)
#define ELS_ELS_KS19_KS19_UTLSMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UTLSMS_SHIFT)) & ELS_ELS_KS19_KS19_UTLSMS_MASK)

#define ELS_ELS_KS19_KS19_UKGSRC_MASK            (0x4000000U)
#define ELS_ELS_KS19_KS19_UKGSRC_SHIFT           (26U)
#define ELS_ELS_KS19_KS19_UKGSRC(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UKGSRC_SHIFT)) & ELS_ELS_KS19_KS19_UKGSRC_MASK)

#define ELS_ELS_KS19_KS19_UHWO_MASK              (0x8000000U)
#define ELS_ELS_KS19_KS19_UHWO_SHIFT             (27U)
#define ELS_ELS_KS19_KS19_UHWO(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UHWO_SHIFT)) & ELS_ELS_KS19_KS19_UHWO_MASK)

#define ELS_ELS_KS19_KS19_UWRPOK_MASK            (0x10000000U)
#define ELS_ELS_KS19_KS19_UWRPOK_SHIFT           (28U)
#define ELS_ELS_KS19_KS19_UWRPOK(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UWRPOK_SHIFT)) & ELS_ELS_KS19_KS19_UWRPOK_MASK)

#define ELS_ELS_KS19_KS19_UDUK_MASK              (0x20000000U)
#define ELS_ELS_KS19_KS19_UDUK_SHIFT             (29U)
#define ELS_ELS_KS19_KS19_UDUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UDUK_SHIFT)) & ELS_ELS_KS19_KS19_UDUK_MASK)

#define ELS_ELS_KS19_KS19_UPPROT_MASK            (0xC0000000U)
#define ELS_ELS_KS19_KS19_UPPROT_SHIFT           (30U)
#define ELS_ELS_KS19_KS19_UPPROT(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS19_UPPROT_SHIFT)) & ELS_ELS_KS19_KS19_UPPROT_MASK)
/*! @} */

/*! @name RESERVED_LA4 - Reserved LA4 */
/*! @{ */

#define ELS_RESERVED_LA4_RESERVED31_MASK         (0xFFFFFFFFU)
#define ELS_RESERVED_LA4_RESERVED31_SHIFT        (0U)
/*! reserved31 - should be 0 */
#define ELS_RESERVED_LA4_RESERVED31(x)           (((uint32_t)(((uint32_t)(x)) << ELS_RESERVED_LA4_RESERVED31_SHIFT)) & ELS_RESERVED_LA4_RESERVED31_MASK)
/*! @} */

/*! @name RESERVED_LA8 - Reserved LA8 */
/*! @{ */

#define ELS_RESERVED_LA8_RESERVED31_MASK         (0xFFFFFFFFU)
#define ELS_RESERVED_LA8_RESERVED31_SHIFT        (0U)
/*! reserved31 - should be 0x2d */
#define ELS_RESERVED_LA8_RESERVED31(x)           (((uint32_t)(((uint32_t)(x)) << ELS_RESERVED_LA8_RESERVED31_SHIFT)) & ELS_RESERVED_LA8_RESERVED31_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ELS_Register_Masks */


/*!
 * @}
 */ /* end of group ELS_Peripheral_Access_Layer */


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


#endif  /* ELS_H_ */

