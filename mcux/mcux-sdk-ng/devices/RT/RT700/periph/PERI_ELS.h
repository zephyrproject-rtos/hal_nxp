/*
** ###################################################################
**     Processors:          MIMXRT735SGAWBR_cm33_core0
**                          MIMXRT735SGAWBR_cm33_core1
**                          MIMXRT735SGAWBR_ezhv
**                          MIMXRT735SGAWBR_hifi1
**                          MIMXRT735SGFOB_cm33_core0
**                          MIMXRT735SGFOB_cm33_core1
**                          MIMXRT735SGFOB_ezhv
**                          MIMXRT735SGFOB_hifi1
**                          MIMXRT758SGAWBR_cm33_core0
**                          MIMXRT758SGAWBR_cm33_core1
**                          MIMXRT758SGAWBR_ezhv
**                          MIMXRT758SGAWBR_hifi1
**                          MIMXRT758SGFOB_cm33_core0
**                          MIMXRT758SGFOB_cm33_core1
**                          MIMXRT758SGFOB_ezhv
**                          MIMXRT758SGFOB_hifi1
**                          MIMXRT798SGAWBR_cm33_core0
**                          MIMXRT798SGAWBR_cm33_core1
**                          MIMXRT798SGAWBR_ezhv
**                          MIMXRT798SGAWBR_hifi1
**                          MIMXRT798SGAWBR_hifi4
**                          MIMXRT798SGFOB_cm33_core0
**                          MIMXRT798SGFOB_cm33_core1
**                          MIMXRT798SGFOB_ezhv
**                          MIMXRT798SGFOB_hifi1
**                          MIMXRT798SGFOB_hifi4
**
**     Version:             rev. 4.0, 2025-06-06
**     Build:               b250930
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ELS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 4.0 (2025-06-06)
**         B0 initial version
**
** ###################################################################
*/

/*!
 * @file PERI_ELS.h
 * @version 4.0
 * @date 2025-06-06
 * @brief CMSIS Peripheral Access Layer for ELS
 *
 * CMSIS Peripheral Access Layer for ELS
 */

#if !defined(PERI_ELS_H_)
#define PERI_ELS_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWBR_cm33_core0) || defined(CPU_MIMXRT735SGFOB_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_cm33_core1) || defined(CPU_MIMXRT735SGFOB_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_ezhv) || defined(CPU_MIMXRT735SGFOB_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWBR_hifi1) || defined(CPU_MIMXRT735SGFOB_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_cm33_core0) || defined(CPU_MIMXRT758SGFOB_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_cm33_core1) || defined(CPU_MIMXRT758SGFOB_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_ezhv) || defined(CPU_MIMXRT758SGFOB_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWBR_hifi1) || defined(CPU_MIMXRT758SGFOB_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_cm33_core0) || defined(CPU_MIMXRT798SGFOB_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_cm33_core1) || defined(CPU_MIMXRT798SGFOB_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_ezhv) || defined(CPU_MIMXRT798SGFOB_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi1) || defined(CPU_MIMXRT798SGFOB_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWBR_hifi4) || defined(CPU_MIMXRT798SGFOB_hifi4))
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
  __I  uint32_t ELS_KS0;                           /**< Key Status, offset: 0x150 */
  __I  uint32_t ELS_KS1;                           /**< Key Status, offset: 0x154 */
  __I  uint32_t ELS_KS2;                           /**< Key Status, offset: 0x158 */
  __I  uint32_t ELS_KS3;                           /**< Key Status, offset: 0x15C */
  __I  uint32_t ELS_KS4;                           /**< Key Status, offset: 0x160 */
  __I  uint32_t ELS_KS5;                           /**< Key Status, offset: 0x164 */
  __I  uint32_t ELS_KS6;                           /**< Key Status, offset: 0x168 */
  __I  uint32_t ELS_KS7;                           /**< Key Status, offset: 0x16C */
  __I  uint32_t ELS_KS8;                           /**< Key Status, offset: 0x170 */
  __I  uint32_t ELS_KS9;                           /**< Key Status, offset: 0x174 */
  __I  uint32_t ELS_KS10;                          /**< Key Status, offset: 0x178 */
  __I  uint32_t ELS_KS11;                          /**< Key Status, offset: 0x17C */
  __I  uint32_t ELS_KS12;                          /**< Key Status, offset: 0x180 */
  __I  uint32_t ELS_KS13;                          /**< Key Status, offset: 0x184 */
  __I  uint32_t ELS_KS14;                          /**< Key Status, offset: 0x188 */
  __I  uint32_t ELS_KS15;                          /**< Key Status, offset: 0x18C */
  __I  uint32_t ELS_KS16;                          /**< Key Status, offset: 0x190 */
  __I  uint32_t ELS_KS17;                          /**< Key Status, offset: 0x194 */
  __I  uint32_t ELS_KS18;                          /**< Key Status, offset: 0x198 */
  __I  uint32_t ELS_KS19;                          /**< Key Status, offset: 0x19C */
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

/*! @name ELS_KS0 - Key Status */
/*! @{ */

#define ELS_ELS_KS0_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS0_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS0_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_KSIZE_SHIFT)) & ELS_ELS_KS0_KSN_KSIZE_MASK)

#define ELS_ELS_KS0_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS0_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS0_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_KACT_SHIFT)) & ELS_ELS_KS0_KSN_KACT_MASK)

#define ELS_ELS_KS0_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS0_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS0_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_KBASE_SHIFT)) & ELS_ELS_KS0_KSN_KBASE_MASK)

#define ELS_ELS_KS0_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS0_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS0_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KS0_FGP_SHIFT)) & ELS_ELS_KS0_KS0_FGP_MASK)

#define ELS_ELS_KS0_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS0_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS0_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_FRTN_SHIFT)) & ELS_ELS_KS0_KSN_FRTN_MASK)

#define ELS_ELS_KS0_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS0_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS0_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_FHWO_SHIFT)) & ELS_ELS_KS0_KSN_FHWO_MASK)

#define ELS_ELS_KS0_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS0_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS0_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UKPUK_SHIFT)) & ELS_ELS_KS0_KSN_UKPUK_MASK)

#define ELS_ELS_KS0_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS0_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS0_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UTECDH_SHIFT)) & ELS_ELS_KS0_KSN_UTECDH_MASK)

#define ELS_ELS_KS0_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS0_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS0_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UCMAC_SHIFT)) & ELS_ELS_KS0_KSN_UCMAC_MASK)

#define ELS_ELS_KS0_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS0_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS0_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UKSK_SHIFT)) & ELS_ELS_KS0_KSN_UKSK_MASK)

#define ELS_ELS_KS0_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS0_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS0_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_URTF_SHIFT)) & ELS_ELS_KS0_KSN_URTF_MASK)

#define ELS_ELS_KS0_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS0_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS0_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UCKDF_SHIFT)) & ELS_ELS_KS0_KSN_UCKDF_MASK)

#define ELS_ELS_KS0_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS0_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS0_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UHKDF_SHIFT)) & ELS_ELS_KS0_KSN_UHKDF_MASK)

#define ELS_ELS_KS0_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS0_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS0_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UECSG_SHIFT)) & ELS_ELS_KS0_KSN_UECSG_MASK)

#define ELS_ELS_KS0_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS0_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS0_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UECDH_SHIFT)) & ELS_ELS_KS0_KSN_UECDH_MASK)

#define ELS_ELS_KS0_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS0_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS0_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UAES_SHIFT)) & ELS_ELS_KS0_KSN_UAES_MASK)

#define ELS_ELS_KS0_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS0_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS0_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UHMAC_SHIFT)) & ELS_ELS_KS0_KSN_UHMAC_MASK)

#define ELS_ELS_KS0_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS0_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS0_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UKWK_SHIFT)) & ELS_ELS_KS0_KSN_UKWK_MASK)

#define ELS_ELS_KS0_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS0_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS0_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UKUOK_SHIFT)) & ELS_ELS_KS0_KSN_UKUOK_MASK)

#define ELS_ELS_KS0_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS0_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS0_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS0_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS0_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS0_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS0_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS0_KSN_UTLSMS_MASK)

#define ELS_ELS_KS0_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS0_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS0_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS0_KSN_UKGSRC_MASK)

#define ELS_ELS_KS0_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS0_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS0_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UHWO_SHIFT)) & ELS_ELS_KS0_KSN_UHWO_MASK)

#define ELS_ELS_KS0_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS0_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS0_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS0_KSN_UWRPOK_MASK)

#define ELS_ELS_KS0_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS0_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS0_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UDUK_SHIFT)) & ELS_ELS_KS0_KSN_UDUK_MASK)

#define ELS_ELS_KS0_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS0_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS0_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS0_KSN_UPPROT_SHIFT)) & ELS_ELS_KS0_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS1 - Key Status */
/*! @{ */

#define ELS_ELS_KS1_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS1_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS1_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_KSIZE_SHIFT)) & ELS_ELS_KS1_KSN_KSIZE_MASK)

#define ELS_ELS_KS1_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS1_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS1_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_KACT_SHIFT)) & ELS_ELS_KS1_KSN_KACT_MASK)

#define ELS_ELS_KS1_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS1_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS1_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_KBASE_SHIFT)) & ELS_ELS_KS1_KSN_KBASE_MASK)

#define ELS_ELS_KS1_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS1_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS1_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KS0_FGP_SHIFT)) & ELS_ELS_KS1_KS0_FGP_MASK)

#define ELS_ELS_KS1_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS1_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS1_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_FRTN_SHIFT)) & ELS_ELS_KS1_KSN_FRTN_MASK)

#define ELS_ELS_KS1_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS1_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS1_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_FHWO_SHIFT)) & ELS_ELS_KS1_KSN_FHWO_MASK)

#define ELS_ELS_KS1_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS1_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS1_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UKPUK_SHIFT)) & ELS_ELS_KS1_KSN_UKPUK_MASK)

#define ELS_ELS_KS1_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS1_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS1_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UTECDH_SHIFT)) & ELS_ELS_KS1_KSN_UTECDH_MASK)

#define ELS_ELS_KS1_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS1_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS1_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UCMAC_SHIFT)) & ELS_ELS_KS1_KSN_UCMAC_MASK)

#define ELS_ELS_KS1_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS1_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS1_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UKSK_SHIFT)) & ELS_ELS_KS1_KSN_UKSK_MASK)

#define ELS_ELS_KS1_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS1_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS1_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_URTF_SHIFT)) & ELS_ELS_KS1_KSN_URTF_MASK)

#define ELS_ELS_KS1_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS1_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS1_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UCKDF_SHIFT)) & ELS_ELS_KS1_KSN_UCKDF_MASK)

#define ELS_ELS_KS1_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS1_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS1_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UHKDF_SHIFT)) & ELS_ELS_KS1_KSN_UHKDF_MASK)

#define ELS_ELS_KS1_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS1_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS1_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UECSG_SHIFT)) & ELS_ELS_KS1_KSN_UECSG_MASK)

#define ELS_ELS_KS1_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS1_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS1_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UECDH_SHIFT)) & ELS_ELS_KS1_KSN_UECDH_MASK)

#define ELS_ELS_KS1_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS1_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS1_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UAES_SHIFT)) & ELS_ELS_KS1_KSN_UAES_MASK)

#define ELS_ELS_KS1_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS1_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS1_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UHMAC_SHIFT)) & ELS_ELS_KS1_KSN_UHMAC_MASK)

#define ELS_ELS_KS1_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS1_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS1_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UKWK_SHIFT)) & ELS_ELS_KS1_KSN_UKWK_MASK)

#define ELS_ELS_KS1_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS1_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS1_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UKUOK_SHIFT)) & ELS_ELS_KS1_KSN_UKUOK_MASK)

#define ELS_ELS_KS1_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS1_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS1_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS1_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS1_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS1_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS1_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS1_KSN_UTLSMS_MASK)

#define ELS_ELS_KS1_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS1_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS1_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS1_KSN_UKGSRC_MASK)

#define ELS_ELS_KS1_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS1_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS1_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UHWO_SHIFT)) & ELS_ELS_KS1_KSN_UHWO_MASK)

#define ELS_ELS_KS1_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS1_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS1_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS1_KSN_UWRPOK_MASK)

#define ELS_ELS_KS1_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS1_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS1_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UDUK_SHIFT)) & ELS_ELS_KS1_KSN_UDUK_MASK)

#define ELS_ELS_KS1_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS1_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS1_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS1_KSN_UPPROT_SHIFT)) & ELS_ELS_KS1_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS2 - Key Status */
/*! @{ */

#define ELS_ELS_KS2_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS2_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS2_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_KSIZE_SHIFT)) & ELS_ELS_KS2_KSN_KSIZE_MASK)

#define ELS_ELS_KS2_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS2_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS2_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_KACT_SHIFT)) & ELS_ELS_KS2_KSN_KACT_MASK)

#define ELS_ELS_KS2_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS2_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS2_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_KBASE_SHIFT)) & ELS_ELS_KS2_KSN_KBASE_MASK)

#define ELS_ELS_KS2_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS2_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS2_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KS0_FGP_SHIFT)) & ELS_ELS_KS2_KS0_FGP_MASK)

#define ELS_ELS_KS2_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS2_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS2_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_FRTN_SHIFT)) & ELS_ELS_KS2_KSN_FRTN_MASK)

#define ELS_ELS_KS2_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS2_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS2_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_FHWO_SHIFT)) & ELS_ELS_KS2_KSN_FHWO_MASK)

#define ELS_ELS_KS2_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS2_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS2_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UKPUK_SHIFT)) & ELS_ELS_KS2_KSN_UKPUK_MASK)

#define ELS_ELS_KS2_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS2_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS2_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UTECDH_SHIFT)) & ELS_ELS_KS2_KSN_UTECDH_MASK)

#define ELS_ELS_KS2_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS2_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS2_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UCMAC_SHIFT)) & ELS_ELS_KS2_KSN_UCMAC_MASK)

#define ELS_ELS_KS2_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS2_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS2_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UKSK_SHIFT)) & ELS_ELS_KS2_KSN_UKSK_MASK)

#define ELS_ELS_KS2_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS2_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS2_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_URTF_SHIFT)) & ELS_ELS_KS2_KSN_URTF_MASK)

#define ELS_ELS_KS2_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS2_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS2_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UCKDF_SHIFT)) & ELS_ELS_KS2_KSN_UCKDF_MASK)

#define ELS_ELS_KS2_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS2_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS2_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UHKDF_SHIFT)) & ELS_ELS_KS2_KSN_UHKDF_MASK)

#define ELS_ELS_KS2_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS2_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS2_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UECSG_SHIFT)) & ELS_ELS_KS2_KSN_UECSG_MASK)

#define ELS_ELS_KS2_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS2_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS2_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UECDH_SHIFT)) & ELS_ELS_KS2_KSN_UECDH_MASK)

#define ELS_ELS_KS2_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS2_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS2_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UAES_SHIFT)) & ELS_ELS_KS2_KSN_UAES_MASK)

#define ELS_ELS_KS2_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS2_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS2_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UHMAC_SHIFT)) & ELS_ELS_KS2_KSN_UHMAC_MASK)

#define ELS_ELS_KS2_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS2_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS2_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UKWK_SHIFT)) & ELS_ELS_KS2_KSN_UKWK_MASK)

#define ELS_ELS_KS2_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS2_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS2_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UKUOK_SHIFT)) & ELS_ELS_KS2_KSN_UKUOK_MASK)

#define ELS_ELS_KS2_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS2_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS2_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS2_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS2_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS2_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS2_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS2_KSN_UTLSMS_MASK)

#define ELS_ELS_KS2_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS2_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS2_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS2_KSN_UKGSRC_MASK)

#define ELS_ELS_KS2_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS2_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS2_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UHWO_SHIFT)) & ELS_ELS_KS2_KSN_UHWO_MASK)

#define ELS_ELS_KS2_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS2_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS2_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS2_KSN_UWRPOK_MASK)

#define ELS_ELS_KS2_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS2_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS2_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UDUK_SHIFT)) & ELS_ELS_KS2_KSN_UDUK_MASK)

#define ELS_ELS_KS2_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS2_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS2_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS2_KSN_UPPROT_SHIFT)) & ELS_ELS_KS2_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS3 - Key Status */
/*! @{ */

#define ELS_ELS_KS3_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS3_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS3_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_KSIZE_SHIFT)) & ELS_ELS_KS3_KSN_KSIZE_MASK)

#define ELS_ELS_KS3_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS3_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS3_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_KACT_SHIFT)) & ELS_ELS_KS3_KSN_KACT_MASK)

#define ELS_ELS_KS3_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS3_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS3_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_KBASE_SHIFT)) & ELS_ELS_KS3_KSN_KBASE_MASK)

#define ELS_ELS_KS3_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS3_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS3_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KS0_FGP_SHIFT)) & ELS_ELS_KS3_KS0_FGP_MASK)

#define ELS_ELS_KS3_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS3_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS3_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_FRTN_SHIFT)) & ELS_ELS_KS3_KSN_FRTN_MASK)

#define ELS_ELS_KS3_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS3_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS3_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_FHWO_SHIFT)) & ELS_ELS_KS3_KSN_FHWO_MASK)

#define ELS_ELS_KS3_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS3_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS3_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UKPUK_SHIFT)) & ELS_ELS_KS3_KSN_UKPUK_MASK)

#define ELS_ELS_KS3_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS3_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS3_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UTECDH_SHIFT)) & ELS_ELS_KS3_KSN_UTECDH_MASK)

#define ELS_ELS_KS3_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS3_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS3_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UCMAC_SHIFT)) & ELS_ELS_KS3_KSN_UCMAC_MASK)

#define ELS_ELS_KS3_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS3_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS3_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UKSK_SHIFT)) & ELS_ELS_KS3_KSN_UKSK_MASK)

#define ELS_ELS_KS3_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS3_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS3_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_URTF_SHIFT)) & ELS_ELS_KS3_KSN_URTF_MASK)

#define ELS_ELS_KS3_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS3_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS3_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UCKDF_SHIFT)) & ELS_ELS_KS3_KSN_UCKDF_MASK)

#define ELS_ELS_KS3_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS3_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS3_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UHKDF_SHIFT)) & ELS_ELS_KS3_KSN_UHKDF_MASK)

#define ELS_ELS_KS3_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS3_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS3_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UECSG_SHIFT)) & ELS_ELS_KS3_KSN_UECSG_MASK)

#define ELS_ELS_KS3_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS3_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS3_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UECDH_SHIFT)) & ELS_ELS_KS3_KSN_UECDH_MASK)

#define ELS_ELS_KS3_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS3_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS3_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UAES_SHIFT)) & ELS_ELS_KS3_KSN_UAES_MASK)

#define ELS_ELS_KS3_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS3_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS3_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UHMAC_SHIFT)) & ELS_ELS_KS3_KSN_UHMAC_MASK)

#define ELS_ELS_KS3_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS3_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS3_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UKWK_SHIFT)) & ELS_ELS_KS3_KSN_UKWK_MASK)

#define ELS_ELS_KS3_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS3_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS3_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UKUOK_SHIFT)) & ELS_ELS_KS3_KSN_UKUOK_MASK)

#define ELS_ELS_KS3_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS3_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS3_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS3_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS3_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS3_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS3_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS3_KSN_UTLSMS_MASK)

#define ELS_ELS_KS3_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS3_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS3_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS3_KSN_UKGSRC_MASK)

#define ELS_ELS_KS3_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS3_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS3_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UHWO_SHIFT)) & ELS_ELS_KS3_KSN_UHWO_MASK)

#define ELS_ELS_KS3_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS3_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS3_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS3_KSN_UWRPOK_MASK)

#define ELS_ELS_KS3_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS3_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS3_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UDUK_SHIFT)) & ELS_ELS_KS3_KSN_UDUK_MASK)

#define ELS_ELS_KS3_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS3_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS3_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS3_KSN_UPPROT_SHIFT)) & ELS_ELS_KS3_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS4 - Key Status */
/*! @{ */

#define ELS_ELS_KS4_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS4_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS4_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_KSIZE_SHIFT)) & ELS_ELS_KS4_KSN_KSIZE_MASK)

#define ELS_ELS_KS4_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS4_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS4_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_KACT_SHIFT)) & ELS_ELS_KS4_KSN_KACT_MASK)

#define ELS_ELS_KS4_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS4_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS4_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_KBASE_SHIFT)) & ELS_ELS_KS4_KSN_KBASE_MASK)

#define ELS_ELS_KS4_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS4_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS4_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KS0_FGP_SHIFT)) & ELS_ELS_KS4_KS0_FGP_MASK)

#define ELS_ELS_KS4_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS4_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS4_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_FRTN_SHIFT)) & ELS_ELS_KS4_KSN_FRTN_MASK)

#define ELS_ELS_KS4_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS4_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS4_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_FHWO_SHIFT)) & ELS_ELS_KS4_KSN_FHWO_MASK)

#define ELS_ELS_KS4_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS4_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS4_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UKPUK_SHIFT)) & ELS_ELS_KS4_KSN_UKPUK_MASK)

#define ELS_ELS_KS4_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS4_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS4_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UTECDH_SHIFT)) & ELS_ELS_KS4_KSN_UTECDH_MASK)

#define ELS_ELS_KS4_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS4_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS4_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UCMAC_SHIFT)) & ELS_ELS_KS4_KSN_UCMAC_MASK)

#define ELS_ELS_KS4_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS4_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS4_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UKSK_SHIFT)) & ELS_ELS_KS4_KSN_UKSK_MASK)

#define ELS_ELS_KS4_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS4_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS4_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_URTF_SHIFT)) & ELS_ELS_KS4_KSN_URTF_MASK)

#define ELS_ELS_KS4_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS4_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS4_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UCKDF_SHIFT)) & ELS_ELS_KS4_KSN_UCKDF_MASK)

#define ELS_ELS_KS4_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS4_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS4_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UHKDF_SHIFT)) & ELS_ELS_KS4_KSN_UHKDF_MASK)

#define ELS_ELS_KS4_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS4_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS4_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UECSG_SHIFT)) & ELS_ELS_KS4_KSN_UECSG_MASK)

#define ELS_ELS_KS4_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS4_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS4_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UECDH_SHIFT)) & ELS_ELS_KS4_KSN_UECDH_MASK)

#define ELS_ELS_KS4_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS4_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS4_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UAES_SHIFT)) & ELS_ELS_KS4_KSN_UAES_MASK)

#define ELS_ELS_KS4_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS4_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS4_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UHMAC_SHIFT)) & ELS_ELS_KS4_KSN_UHMAC_MASK)

#define ELS_ELS_KS4_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS4_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS4_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UKWK_SHIFT)) & ELS_ELS_KS4_KSN_UKWK_MASK)

#define ELS_ELS_KS4_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS4_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS4_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UKUOK_SHIFT)) & ELS_ELS_KS4_KSN_UKUOK_MASK)

#define ELS_ELS_KS4_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS4_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS4_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS4_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS4_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS4_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS4_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS4_KSN_UTLSMS_MASK)

#define ELS_ELS_KS4_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS4_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS4_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS4_KSN_UKGSRC_MASK)

#define ELS_ELS_KS4_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS4_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS4_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UHWO_SHIFT)) & ELS_ELS_KS4_KSN_UHWO_MASK)

#define ELS_ELS_KS4_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS4_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS4_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS4_KSN_UWRPOK_MASK)

#define ELS_ELS_KS4_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS4_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS4_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UDUK_SHIFT)) & ELS_ELS_KS4_KSN_UDUK_MASK)

#define ELS_ELS_KS4_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS4_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS4_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS4_KSN_UPPROT_SHIFT)) & ELS_ELS_KS4_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS5 - Key Status */
/*! @{ */

#define ELS_ELS_KS5_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS5_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS5_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_KSIZE_SHIFT)) & ELS_ELS_KS5_KSN_KSIZE_MASK)

#define ELS_ELS_KS5_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS5_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS5_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_KACT_SHIFT)) & ELS_ELS_KS5_KSN_KACT_MASK)

#define ELS_ELS_KS5_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS5_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS5_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_KBASE_SHIFT)) & ELS_ELS_KS5_KSN_KBASE_MASK)

#define ELS_ELS_KS5_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS5_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS5_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KS0_FGP_SHIFT)) & ELS_ELS_KS5_KS0_FGP_MASK)

#define ELS_ELS_KS5_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS5_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS5_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_FRTN_SHIFT)) & ELS_ELS_KS5_KSN_FRTN_MASK)

#define ELS_ELS_KS5_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS5_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS5_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_FHWO_SHIFT)) & ELS_ELS_KS5_KSN_FHWO_MASK)

#define ELS_ELS_KS5_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS5_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS5_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UKPUK_SHIFT)) & ELS_ELS_KS5_KSN_UKPUK_MASK)

#define ELS_ELS_KS5_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS5_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS5_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UTECDH_SHIFT)) & ELS_ELS_KS5_KSN_UTECDH_MASK)

#define ELS_ELS_KS5_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS5_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS5_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UCMAC_SHIFT)) & ELS_ELS_KS5_KSN_UCMAC_MASK)

#define ELS_ELS_KS5_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS5_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS5_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UKSK_SHIFT)) & ELS_ELS_KS5_KSN_UKSK_MASK)

#define ELS_ELS_KS5_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS5_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS5_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_URTF_SHIFT)) & ELS_ELS_KS5_KSN_URTF_MASK)

#define ELS_ELS_KS5_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS5_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS5_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UCKDF_SHIFT)) & ELS_ELS_KS5_KSN_UCKDF_MASK)

#define ELS_ELS_KS5_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS5_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS5_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UHKDF_SHIFT)) & ELS_ELS_KS5_KSN_UHKDF_MASK)

#define ELS_ELS_KS5_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS5_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS5_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UECSG_SHIFT)) & ELS_ELS_KS5_KSN_UECSG_MASK)

#define ELS_ELS_KS5_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS5_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS5_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UECDH_SHIFT)) & ELS_ELS_KS5_KSN_UECDH_MASK)

#define ELS_ELS_KS5_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS5_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS5_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UAES_SHIFT)) & ELS_ELS_KS5_KSN_UAES_MASK)

#define ELS_ELS_KS5_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS5_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS5_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UHMAC_SHIFT)) & ELS_ELS_KS5_KSN_UHMAC_MASK)

#define ELS_ELS_KS5_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS5_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS5_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UKWK_SHIFT)) & ELS_ELS_KS5_KSN_UKWK_MASK)

#define ELS_ELS_KS5_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS5_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS5_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UKUOK_SHIFT)) & ELS_ELS_KS5_KSN_UKUOK_MASK)

#define ELS_ELS_KS5_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS5_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS5_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS5_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS5_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS5_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS5_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS5_KSN_UTLSMS_MASK)

#define ELS_ELS_KS5_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS5_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS5_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS5_KSN_UKGSRC_MASK)

#define ELS_ELS_KS5_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS5_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS5_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UHWO_SHIFT)) & ELS_ELS_KS5_KSN_UHWO_MASK)

#define ELS_ELS_KS5_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS5_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS5_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS5_KSN_UWRPOK_MASK)

#define ELS_ELS_KS5_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS5_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS5_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UDUK_SHIFT)) & ELS_ELS_KS5_KSN_UDUK_MASK)

#define ELS_ELS_KS5_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS5_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS5_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS5_KSN_UPPROT_SHIFT)) & ELS_ELS_KS5_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS6 - Key Status */
/*! @{ */

#define ELS_ELS_KS6_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS6_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS6_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_KSIZE_SHIFT)) & ELS_ELS_KS6_KSN_KSIZE_MASK)

#define ELS_ELS_KS6_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS6_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS6_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_KACT_SHIFT)) & ELS_ELS_KS6_KSN_KACT_MASK)

#define ELS_ELS_KS6_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS6_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS6_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_KBASE_SHIFT)) & ELS_ELS_KS6_KSN_KBASE_MASK)

#define ELS_ELS_KS6_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS6_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS6_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KS0_FGP_SHIFT)) & ELS_ELS_KS6_KS0_FGP_MASK)

#define ELS_ELS_KS6_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS6_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS6_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_FRTN_SHIFT)) & ELS_ELS_KS6_KSN_FRTN_MASK)

#define ELS_ELS_KS6_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS6_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS6_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_FHWO_SHIFT)) & ELS_ELS_KS6_KSN_FHWO_MASK)

#define ELS_ELS_KS6_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS6_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS6_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UKPUK_SHIFT)) & ELS_ELS_KS6_KSN_UKPUK_MASK)

#define ELS_ELS_KS6_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS6_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS6_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UTECDH_SHIFT)) & ELS_ELS_KS6_KSN_UTECDH_MASK)

#define ELS_ELS_KS6_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS6_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS6_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UCMAC_SHIFT)) & ELS_ELS_KS6_KSN_UCMAC_MASK)

#define ELS_ELS_KS6_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS6_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS6_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UKSK_SHIFT)) & ELS_ELS_KS6_KSN_UKSK_MASK)

#define ELS_ELS_KS6_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS6_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS6_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_URTF_SHIFT)) & ELS_ELS_KS6_KSN_URTF_MASK)

#define ELS_ELS_KS6_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS6_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS6_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UCKDF_SHIFT)) & ELS_ELS_KS6_KSN_UCKDF_MASK)

#define ELS_ELS_KS6_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS6_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS6_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UHKDF_SHIFT)) & ELS_ELS_KS6_KSN_UHKDF_MASK)

#define ELS_ELS_KS6_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS6_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS6_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UECSG_SHIFT)) & ELS_ELS_KS6_KSN_UECSG_MASK)

#define ELS_ELS_KS6_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS6_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS6_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UECDH_SHIFT)) & ELS_ELS_KS6_KSN_UECDH_MASK)

#define ELS_ELS_KS6_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS6_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS6_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UAES_SHIFT)) & ELS_ELS_KS6_KSN_UAES_MASK)

#define ELS_ELS_KS6_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS6_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS6_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UHMAC_SHIFT)) & ELS_ELS_KS6_KSN_UHMAC_MASK)

#define ELS_ELS_KS6_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS6_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS6_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UKWK_SHIFT)) & ELS_ELS_KS6_KSN_UKWK_MASK)

#define ELS_ELS_KS6_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS6_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS6_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UKUOK_SHIFT)) & ELS_ELS_KS6_KSN_UKUOK_MASK)

#define ELS_ELS_KS6_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS6_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS6_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS6_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS6_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS6_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS6_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS6_KSN_UTLSMS_MASK)

#define ELS_ELS_KS6_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS6_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS6_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS6_KSN_UKGSRC_MASK)

#define ELS_ELS_KS6_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS6_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS6_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UHWO_SHIFT)) & ELS_ELS_KS6_KSN_UHWO_MASK)

#define ELS_ELS_KS6_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS6_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS6_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS6_KSN_UWRPOK_MASK)

#define ELS_ELS_KS6_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS6_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS6_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UDUK_SHIFT)) & ELS_ELS_KS6_KSN_UDUK_MASK)

#define ELS_ELS_KS6_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS6_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS6_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS6_KSN_UPPROT_SHIFT)) & ELS_ELS_KS6_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS7 - Key Status */
/*! @{ */

#define ELS_ELS_KS7_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS7_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS7_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_KSIZE_SHIFT)) & ELS_ELS_KS7_KSN_KSIZE_MASK)

#define ELS_ELS_KS7_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS7_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS7_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_KACT_SHIFT)) & ELS_ELS_KS7_KSN_KACT_MASK)

#define ELS_ELS_KS7_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS7_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS7_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_KBASE_SHIFT)) & ELS_ELS_KS7_KSN_KBASE_MASK)

#define ELS_ELS_KS7_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS7_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS7_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KS0_FGP_SHIFT)) & ELS_ELS_KS7_KS0_FGP_MASK)

#define ELS_ELS_KS7_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS7_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS7_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_FRTN_SHIFT)) & ELS_ELS_KS7_KSN_FRTN_MASK)

#define ELS_ELS_KS7_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS7_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS7_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_FHWO_SHIFT)) & ELS_ELS_KS7_KSN_FHWO_MASK)

#define ELS_ELS_KS7_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS7_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS7_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UKPUK_SHIFT)) & ELS_ELS_KS7_KSN_UKPUK_MASK)

#define ELS_ELS_KS7_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS7_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS7_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UTECDH_SHIFT)) & ELS_ELS_KS7_KSN_UTECDH_MASK)

#define ELS_ELS_KS7_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS7_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS7_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UCMAC_SHIFT)) & ELS_ELS_KS7_KSN_UCMAC_MASK)

#define ELS_ELS_KS7_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS7_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS7_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UKSK_SHIFT)) & ELS_ELS_KS7_KSN_UKSK_MASK)

#define ELS_ELS_KS7_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS7_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS7_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_URTF_SHIFT)) & ELS_ELS_KS7_KSN_URTF_MASK)

#define ELS_ELS_KS7_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS7_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS7_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UCKDF_SHIFT)) & ELS_ELS_KS7_KSN_UCKDF_MASK)

#define ELS_ELS_KS7_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS7_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS7_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UHKDF_SHIFT)) & ELS_ELS_KS7_KSN_UHKDF_MASK)

#define ELS_ELS_KS7_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS7_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS7_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UECSG_SHIFT)) & ELS_ELS_KS7_KSN_UECSG_MASK)

#define ELS_ELS_KS7_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS7_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS7_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UECDH_SHIFT)) & ELS_ELS_KS7_KSN_UECDH_MASK)

#define ELS_ELS_KS7_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS7_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS7_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UAES_SHIFT)) & ELS_ELS_KS7_KSN_UAES_MASK)

#define ELS_ELS_KS7_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS7_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS7_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UHMAC_SHIFT)) & ELS_ELS_KS7_KSN_UHMAC_MASK)

#define ELS_ELS_KS7_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS7_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS7_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UKWK_SHIFT)) & ELS_ELS_KS7_KSN_UKWK_MASK)

#define ELS_ELS_KS7_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS7_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS7_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UKUOK_SHIFT)) & ELS_ELS_KS7_KSN_UKUOK_MASK)

#define ELS_ELS_KS7_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS7_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS7_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS7_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS7_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS7_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS7_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS7_KSN_UTLSMS_MASK)

#define ELS_ELS_KS7_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS7_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS7_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS7_KSN_UKGSRC_MASK)

#define ELS_ELS_KS7_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS7_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS7_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UHWO_SHIFT)) & ELS_ELS_KS7_KSN_UHWO_MASK)

#define ELS_ELS_KS7_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS7_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS7_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS7_KSN_UWRPOK_MASK)

#define ELS_ELS_KS7_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS7_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS7_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UDUK_SHIFT)) & ELS_ELS_KS7_KSN_UDUK_MASK)

#define ELS_ELS_KS7_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS7_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS7_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS7_KSN_UPPROT_SHIFT)) & ELS_ELS_KS7_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS8 - Key Status */
/*! @{ */

#define ELS_ELS_KS8_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS8_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS8_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_KSIZE_SHIFT)) & ELS_ELS_KS8_KSN_KSIZE_MASK)

#define ELS_ELS_KS8_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS8_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS8_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_KACT_SHIFT)) & ELS_ELS_KS8_KSN_KACT_MASK)

#define ELS_ELS_KS8_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS8_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS8_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_KBASE_SHIFT)) & ELS_ELS_KS8_KSN_KBASE_MASK)

#define ELS_ELS_KS8_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS8_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS8_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KS0_FGP_SHIFT)) & ELS_ELS_KS8_KS0_FGP_MASK)

#define ELS_ELS_KS8_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS8_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS8_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_FRTN_SHIFT)) & ELS_ELS_KS8_KSN_FRTN_MASK)

#define ELS_ELS_KS8_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS8_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS8_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_FHWO_SHIFT)) & ELS_ELS_KS8_KSN_FHWO_MASK)

#define ELS_ELS_KS8_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS8_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS8_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UKPUK_SHIFT)) & ELS_ELS_KS8_KSN_UKPUK_MASK)

#define ELS_ELS_KS8_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS8_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS8_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UTECDH_SHIFT)) & ELS_ELS_KS8_KSN_UTECDH_MASK)

#define ELS_ELS_KS8_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS8_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS8_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UCMAC_SHIFT)) & ELS_ELS_KS8_KSN_UCMAC_MASK)

#define ELS_ELS_KS8_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS8_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS8_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UKSK_SHIFT)) & ELS_ELS_KS8_KSN_UKSK_MASK)

#define ELS_ELS_KS8_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS8_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS8_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_URTF_SHIFT)) & ELS_ELS_KS8_KSN_URTF_MASK)

#define ELS_ELS_KS8_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS8_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS8_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UCKDF_SHIFT)) & ELS_ELS_KS8_KSN_UCKDF_MASK)

#define ELS_ELS_KS8_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS8_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS8_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UHKDF_SHIFT)) & ELS_ELS_KS8_KSN_UHKDF_MASK)

#define ELS_ELS_KS8_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS8_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS8_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UECSG_SHIFT)) & ELS_ELS_KS8_KSN_UECSG_MASK)

#define ELS_ELS_KS8_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS8_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS8_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UECDH_SHIFT)) & ELS_ELS_KS8_KSN_UECDH_MASK)

#define ELS_ELS_KS8_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS8_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS8_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UAES_SHIFT)) & ELS_ELS_KS8_KSN_UAES_MASK)

#define ELS_ELS_KS8_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS8_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS8_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UHMAC_SHIFT)) & ELS_ELS_KS8_KSN_UHMAC_MASK)

#define ELS_ELS_KS8_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS8_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS8_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UKWK_SHIFT)) & ELS_ELS_KS8_KSN_UKWK_MASK)

#define ELS_ELS_KS8_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS8_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS8_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UKUOK_SHIFT)) & ELS_ELS_KS8_KSN_UKUOK_MASK)

#define ELS_ELS_KS8_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS8_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS8_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS8_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS8_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS8_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS8_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS8_KSN_UTLSMS_MASK)

#define ELS_ELS_KS8_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS8_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS8_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS8_KSN_UKGSRC_MASK)

#define ELS_ELS_KS8_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS8_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS8_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UHWO_SHIFT)) & ELS_ELS_KS8_KSN_UHWO_MASK)

#define ELS_ELS_KS8_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS8_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS8_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS8_KSN_UWRPOK_MASK)

#define ELS_ELS_KS8_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS8_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS8_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UDUK_SHIFT)) & ELS_ELS_KS8_KSN_UDUK_MASK)

#define ELS_ELS_KS8_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS8_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS8_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS8_KSN_UPPROT_SHIFT)) & ELS_ELS_KS8_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS9 - Key Status */
/*! @{ */

#define ELS_ELS_KS9_KSN_KSIZE_MASK               (0x3U)
#define ELS_ELS_KS9_KSN_KSIZE_SHIFT              (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS9_KSN_KSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_KSIZE_SHIFT)) & ELS_ELS_KS9_KSN_KSIZE_MASK)

#define ELS_ELS_KS9_KSN_KACT_MASK                (0x20U)
#define ELS_ELS_KS9_KSN_KACT_SHIFT               (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS9_KSN_KACT(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_KACT_SHIFT)) & ELS_ELS_KS9_KSN_KACT_MASK)

#define ELS_ELS_KS9_KSN_KBASE_MASK               (0x40U)
#define ELS_ELS_KS9_KSN_KBASE_SHIFT              (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS9_KSN_KBASE(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_KBASE_SHIFT)) & ELS_ELS_KS9_KSN_KBASE_MASK)

#define ELS_ELS_KS9_KS0_FGP_MASK                 (0x80U)
#define ELS_ELS_KS9_KS0_FGP_SHIFT                (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS9_KS0_FGP(x)                   (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KS0_FGP_SHIFT)) & ELS_ELS_KS9_KS0_FGP_MASK)

#define ELS_ELS_KS9_KSN_FRTN_MASK                (0x100U)
#define ELS_ELS_KS9_KSN_FRTN_SHIFT               (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS9_KSN_FRTN(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_FRTN_SHIFT)) & ELS_ELS_KS9_KSN_FRTN_MASK)

#define ELS_ELS_KS9_KSN_FHWO_MASK                (0x200U)
#define ELS_ELS_KS9_KSN_FHWO_SHIFT               (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS9_KSN_FHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_FHWO_SHIFT)) & ELS_ELS_KS9_KSN_FHWO_MASK)

#define ELS_ELS_KS9_KSN_UKPUK_MASK               (0x800U)
#define ELS_ELS_KS9_KSN_UKPUK_SHIFT              (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS9_KSN_UKPUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UKPUK_SHIFT)) & ELS_ELS_KS9_KSN_UKPUK_MASK)

#define ELS_ELS_KS9_KSN_UTECDH_MASK              (0x1000U)
#define ELS_ELS_KS9_KSN_UTECDH_SHIFT             (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS9_KSN_UTECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UTECDH_SHIFT)) & ELS_ELS_KS9_KSN_UTECDH_MASK)

#define ELS_ELS_KS9_KSN_UCMAC_MASK               (0x2000U)
#define ELS_ELS_KS9_KSN_UCMAC_SHIFT              (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS9_KSN_UCMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UCMAC_SHIFT)) & ELS_ELS_KS9_KSN_UCMAC_MASK)

#define ELS_ELS_KS9_KSN_UKSK_MASK                (0x4000U)
#define ELS_ELS_KS9_KSN_UKSK_SHIFT               (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS9_KSN_UKSK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UKSK_SHIFT)) & ELS_ELS_KS9_KSN_UKSK_MASK)

#define ELS_ELS_KS9_KSN_URTF_MASK                (0x8000U)
#define ELS_ELS_KS9_KSN_URTF_SHIFT               (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS9_KSN_URTF(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_URTF_SHIFT)) & ELS_ELS_KS9_KSN_URTF_MASK)

#define ELS_ELS_KS9_KSN_UCKDF_MASK               (0x10000U)
#define ELS_ELS_KS9_KSN_UCKDF_SHIFT              (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS9_KSN_UCKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UCKDF_SHIFT)) & ELS_ELS_KS9_KSN_UCKDF_MASK)

#define ELS_ELS_KS9_KSN_UHKDF_MASK               (0x20000U)
#define ELS_ELS_KS9_KSN_UHKDF_SHIFT              (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS9_KSN_UHKDF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UHKDF_SHIFT)) & ELS_ELS_KS9_KSN_UHKDF_MASK)

#define ELS_ELS_KS9_KSN_UECSG_MASK               (0x40000U)
#define ELS_ELS_KS9_KSN_UECSG_SHIFT              (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS9_KSN_UECSG(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UECSG_SHIFT)) & ELS_ELS_KS9_KSN_UECSG_MASK)

#define ELS_ELS_KS9_KSN_UECDH_MASK               (0x80000U)
#define ELS_ELS_KS9_KSN_UECDH_SHIFT              (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS9_KSN_UECDH(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UECDH_SHIFT)) & ELS_ELS_KS9_KSN_UECDH_MASK)

#define ELS_ELS_KS9_KSN_UAES_MASK                (0x100000U)
#define ELS_ELS_KS9_KSN_UAES_SHIFT               (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS9_KSN_UAES(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UAES_SHIFT)) & ELS_ELS_KS9_KSN_UAES_MASK)

#define ELS_ELS_KS9_KSN_UHMAC_MASK               (0x200000U)
#define ELS_ELS_KS9_KSN_UHMAC_SHIFT              (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS9_KSN_UHMAC(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UHMAC_SHIFT)) & ELS_ELS_KS9_KSN_UHMAC_MASK)

#define ELS_ELS_KS9_KSN_UKWK_MASK                (0x400000U)
#define ELS_ELS_KS9_KSN_UKWK_SHIFT               (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS9_KSN_UKWK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UKWK_SHIFT)) & ELS_ELS_KS9_KSN_UKWK_MASK)

#define ELS_ELS_KS9_KSN_UKUOK_MASK               (0x800000U)
#define ELS_ELS_KS9_KSN_UKUOK_SHIFT              (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS9_KSN_UKUOK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UKUOK_SHIFT)) & ELS_ELS_KS9_KSN_UKUOK_MASK)

#define ELS_ELS_KS9_KSN_UTLSPMS_MASK             (0x1000000U)
#define ELS_ELS_KS9_KSN_UTLSPMS_SHIFT            (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS9_KSN_UTLSPMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS9_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS9_KSN_UTLSMS_MASK              (0x2000000U)
#define ELS_ELS_KS9_KSN_UTLSMS_SHIFT             (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS9_KSN_UTLSMS(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS9_KSN_UTLSMS_MASK)

#define ELS_ELS_KS9_KSN_UKGSRC_MASK              (0x4000000U)
#define ELS_ELS_KS9_KSN_UKGSRC_SHIFT             (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS9_KSN_UKGSRC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS9_KSN_UKGSRC_MASK)

#define ELS_ELS_KS9_KSN_UHWO_MASK                (0x8000000U)
#define ELS_ELS_KS9_KSN_UHWO_SHIFT               (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS9_KSN_UHWO(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UHWO_SHIFT)) & ELS_ELS_KS9_KSN_UHWO_MASK)

#define ELS_ELS_KS9_KSN_UWRPOK_MASK              (0x10000000U)
#define ELS_ELS_KS9_KSN_UWRPOK_SHIFT             (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS9_KSN_UWRPOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS9_KSN_UWRPOK_MASK)

#define ELS_ELS_KS9_KSN_UDUK_MASK                (0x20000000U)
#define ELS_ELS_KS9_KSN_UDUK_SHIFT               (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS9_KSN_UDUK(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UDUK_SHIFT)) & ELS_ELS_KS9_KSN_UDUK_MASK)

#define ELS_ELS_KS9_KSN_UPPROT_MASK              (0xC0000000U)
#define ELS_ELS_KS9_KSN_UPPROT_SHIFT             (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS9_KSN_UPPROT(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS9_KSN_UPPROT_SHIFT)) & ELS_ELS_KS9_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS10 - Key Status */
/*! @{ */

#define ELS_ELS_KS10_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS10_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS10_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_KSIZE_SHIFT)) & ELS_ELS_KS10_KSN_KSIZE_MASK)

#define ELS_ELS_KS10_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS10_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS10_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_KACT_SHIFT)) & ELS_ELS_KS10_KSN_KACT_MASK)

#define ELS_ELS_KS10_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS10_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS10_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_KBASE_SHIFT)) & ELS_ELS_KS10_KSN_KBASE_MASK)

#define ELS_ELS_KS10_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS10_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS10_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KS0_FGP_SHIFT)) & ELS_ELS_KS10_KS0_FGP_MASK)

#define ELS_ELS_KS10_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS10_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS10_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_FRTN_SHIFT)) & ELS_ELS_KS10_KSN_FRTN_MASK)

#define ELS_ELS_KS10_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS10_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS10_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_FHWO_SHIFT)) & ELS_ELS_KS10_KSN_FHWO_MASK)

#define ELS_ELS_KS10_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS10_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS10_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UKPUK_SHIFT)) & ELS_ELS_KS10_KSN_UKPUK_MASK)

#define ELS_ELS_KS10_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS10_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS10_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UTECDH_SHIFT)) & ELS_ELS_KS10_KSN_UTECDH_MASK)

#define ELS_ELS_KS10_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS10_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS10_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UCMAC_SHIFT)) & ELS_ELS_KS10_KSN_UCMAC_MASK)

#define ELS_ELS_KS10_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS10_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS10_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UKSK_SHIFT)) & ELS_ELS_KS10_KSN_UKSK_MASK)

#define ELS_ELS_KS10_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS10_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS10_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_URTF_SHIFT)) & ELS_ELS_KS10_KSN_URTF_MASK)

#define ELS_ELS_KS10_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS10_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS10_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UCKDF_SHIFT)) & ELS_ELS_KS10_KSN_UCKDF_MASK)

#define ELS_ELS_KS10_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS10_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS10_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UHKDF_SHIFT)) & ELS_ELS_KS10_KSN_UHKDF_MASK)

#define ELS_ELS_KS10_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS10_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS10_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UECSG_SHIFT)) & ELS_ELS_KS10_KSN_UECSG_MASK)

#define ELS_ELS_KS10_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS10_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS10_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UECDH_SHIFT)) & ELS_ELS_KS10_KSN_UECDH_MASK)

#define ELS_ELS_KS10_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS10_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS10_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UAES_SHIFT)) & ELS_ELS_KS10_KSN_UAES_MASK)

#define ELS_ELS_KS10_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS10_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS10_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UHMAC_SHIFT)) & ELS_ELS_KS10_KSN_UHMAC_MASK)

#define ELS_ELS_KS10_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS10_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS10_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UKWK_SHIFT)) & ELS_ELS_KS10_KSN_UKWK_MASK)

#define ELS_ELS_KS10_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS10_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS10_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UKUOK_SHIFT)) & ELS_ELS_KS10_KSN_UKUOK_MASK)

#define ELS_ELS_KS10_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS10_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS10_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS10_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS10_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS10_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS10_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS10_KSN_UTLSMS_MASK)

#define ELS_ELS_KS10_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS10_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS10_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS10_KSN_UKGSRC_MASK)

#define ELS_ELS_KS10_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS10_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS10_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UHWO_SHIFT)) & ELS_ELS_KS10_KSN_UHWO_MASK)

#define ELS_ELS_KS10_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS10_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS10_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS10_KSN_UWRPOK_MASK)

#define ELS_ELS_KS10_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS10_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS10_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UDUK_SHIFT)) & ELS_ELS_KS10_KSN_UDUK_MASK)

#define ELS_ELS_KS10_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS10_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS10_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS10_KSN_UPPROT_SHIFT)) & ELS_ELS_KS10_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS11 - Key Status */
/*! @{ */

#define ELS_ELS_KS11_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS11_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS11_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_KSIZE_SHIFT)) & ELS_ELS_KS11_KSN_KSIZE_MASK)

#define ELS_ELS_KS11_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS11_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS11_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_KACT_SHIFT)) & ELS_ELS_KS11_KSN_KACT_MASK)

#define ELS_ELS_KS11_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS11_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS11_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_KBASE_SHIFT)) & ELS_ELS_KS11_KSN_KBASE_MASK)

#define ELS_ELS_KS11_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS11_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS11_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KS0_FGP_SHIFT)) & ELS_ELS_KS11_KS0_FGP_MASK)

#define ELS_ELS_KS11_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS11_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS11_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_FRTN_SHIFT)) & ELS_ELS_KS11_KSN_FRTN_MASK)

#define ELS_ELS_KS11_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS11_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS11_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_FHWO_SHIFT)) & ELS_ELS_KS11_KSN_FHWO_MASK)

#define ELS_ELS_KS11_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS11_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS11_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UKPUK_SHIFT)) & ELS_ELS_KS11_KSN_UKPUK_MASK)

#define ELS_ELS_KS11_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS11_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS11_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UTECDH_SHIFT)) & ELS_ELS_KS11_KSN_UTECDH_MASK)

#define ELS_ELS_KS11_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS11_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS11_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UCMAC_SHIFT)) & ELS_ELS_KS11_KSN_UCMAC_MASK)

#define ELS_ELS_KS11_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS11_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS11_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UKSK_SHIFT)) & ELS_ELS_KS11_KSN_UKSK_MASK)

#define ELS_ELS_KS11_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS11_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS11_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_URTF_SHIFT)) & ELS_ELS_KS11_KSN_URTF_MASK)

#define ELS_ELS_KS11_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS11_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS11_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UCKDF_SHIFT)) & ELS_ELS_KS11_KSN_UCKDF_MASK)

#define ELS_ELS_KS11_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS11_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS11_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UHKDF_SHIFT)) & ELS_ELS_KS11_KSN_UHKDF_MASK)

#define ELS_ELS_KS11_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS11_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS11_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UECSG_SHIFT)) & ELS_ELS_KS11_KSN_UECSG_MASK)

#define ELS_ELS_KS11_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS11_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS11_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UECDH_SHIFT)) & ELS_ELS_KS11_KSN_UECDH_MASK)

#define ELS_ELS_KS11_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS11_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS11_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UAES_SHIFT)) & ELS_ELS_KS11_KSN_UAES_MASK)

#define ELS_ELS_KS11_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS11_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS11_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UHMAC_SHIFT)) & ELS_ELS_KS11_KSN_UHMAC_MASK)

#define ELS_ELS_KS11_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS11_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS11_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UKWK_SHIFT)) & ELS_ELS_KS11_KSN_UKWK_MASK)

#define ELS_ELS_KS11_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS11_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS11_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UKUOK_SHIFT)) & ELS_ELS_KS11_KSN_UKUOK_MASK)

#define ELS_ELS_KS11_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS11_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS11_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS11_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS11_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS11_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS11_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS11_KSN_UTLSMS_MASK)

#define ELS_ELS_KS11_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS11_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS11_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS11_KSN_UKGSRC_MASK)

#define ELS_ELS_KS11_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS11_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS11_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UHWO_SHIFT)) & ELS_ELS_KS11_KSN_UHWO_MASK)

#define ELS_ELS_KS11_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS11_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS11_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS11_KSN_UWRPOK_MASK)

#define ELS_ELS_KS11_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS11_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS11_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UDUK_SHIFT)) & ELS_ELS_KS11_KSN_UDUK_MASK)

#define ELS_ELS_KS11_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS11_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS11_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS11_KSN_UPPROT_SHIFT)) & ELS_ELS_KS11_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS12 - Key Status */
/*! @{ */

#define ELS_ELS_KS12_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS12_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS12_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_KSIZE_SHIFT)) & ELS_ELS_KS12_KSN_KSIZE_MASK)

#define ELS_ELS_KS12_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS12_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS12_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_KACT_SHIFT)) & ELS_ELS_KS12_KSN_KACT_MASK)

#define ELS_ELS_KS12_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS12_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS12_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_KBASE_SHIFT)) & ELS_ELS_KS12_KSN_KBASE_MASK)

#define ELS_ELS_KS12_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS12_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS12_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KS0_FGP_SHIFT)) & ELS_ELS_KS12_KS0_FGP_MASK)

#define ELS_ELS_KS12_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS12_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS12_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_FRTN_SHIFT)) & ELS_ELS_KS12_KSN_FRTN_MASK)

#define ELS_ELS_KS12_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS12_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS12_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_FHWO_SHIFT)) & ELS_ELS_KS12_KSN_FHWO_MASK)

#define ELS_ELS_KS12_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS12_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS12_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UKPUK_SHIFT)) & ELS_ELS_KS12_KSN_UKPUK_MASK)

#define ELS_ELS_KS12_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS12_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS12_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UTECDH_SHIFT)) & ELS_ELS_KS12_KSN_UTECDH_MASK)

#define ELS_ELS_KS12_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS12_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS12_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UCMAC_SHIFT)) & ELS_ELS_KS12_KSN_UCMAC_MASK)

#define ELS_ELS_KS12_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS12_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS12_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UKSK_SHIFT)) & ELS_ELS_KS12_KSN_UKSK_MASK)

#define ELS_ELS_KS12_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS12_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS12_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_URTF_SHIFT)) & ELS_ELS_KS12_KSN_URTF_MASK)

#define ELS_ELS_KS12_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS12_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS12_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UCKDF_SHIFT)) & ELS_ELS_KS12_KSN_UCKDF_MASK)

#define ELS_ELS_KS12_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS12_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS12_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UHKDF_SHIFT)) & ELS_ELS_KS12_KSN_UHKDF_MASK)

#define ELS_ELS_KS12_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS12_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS12_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UECSG_SHIFT)) & ELS_ELS_KS12_KSN_UECSG_MASK)

#define ELS_ELS_KS12_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS12_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS12_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UECDH_SHIFT)) & ELS_ELS_KS12_KSN_UECDH_MASK)

#define ELS_ELS_KS12_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS12_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS12_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UAES_SHIFT)) & ELS_ELS_KS12_KSN_UAES_MASK)

#define ELS_ELS_KS12_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS12_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS12_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UHMAC_SHIFT)) & ELS_ELS_KS12_KSN_UHMAC_MASK)

#define ELS_ELS_KS12_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS12_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS12_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UKWK_SHIFT)) & ELS_ELS_KS12_KSN_UKWK_MASK)

#define ELS_ELS_KS12_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS12_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS12_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UKUOK_SHIFT)) & ELS_ELS_KS12_KSN_UKUOK_MASK)

#define ELS_ELS_KS12_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS12_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS12_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS12_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS12_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS12_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS12_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS12_KSN_UTLSMS_MASK)

#define ELS_ELS_KS12_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS12_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS12_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS12_KSN_UKGSRC_MASK)

#define ELS_ELS_KS12_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS12_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS12_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UHWO_SHIFT)) & ELS_ELS_KS12_KSN_UHWO_MASK)

#define ELS_ELS_KS12_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS12_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS12_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS12_KSN_UWRPOK_MASK)

#define ELS_ELS_KS12_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS12_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS12_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UDUK_SHIFT)) & ELS_ELS_KS12_KSN_UDUK_MASK)

#define ELS_ELS_KS12_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS12_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS12_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS12_KSN_UPPROT_SHIFT)) & ELS_ELS_KS12_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS13 - Key Status */
/*! @{ */

#define ELS_ELS_KS13_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS13_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS13_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_KSIZE_SHIFT)) & ELS_ELS_KS13_KSN_KSIZE_MASK)

#define ELS_ELS_KS13_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS13_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS13_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_KACT_SHIFT)) & ELS_ELS_KS13_KSN_KACT_MASK)

#define ELS_ELS_KS13_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS13_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS13_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_KBASE_SHIFT)) & ELS_ELS_KS13_KSN_KBASE_MASK)

#define ELS_ELS_KS13_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS13_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS13_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KS0_FGP_SHIFT)) & ELS_ELS_KS13_KS0_FGP_MASK)

#define ELS_ELS_KS13_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS13_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS13_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_FRTN_SHIFT)) & ELS_ELS_KS13_KSN_FRTN_MASK)

#define ELS_ELS_KS13_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS13_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS13_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_FHWO_SHIFT)) & ELS_ELS_KS13_KSN_FHWO_MASK)

#define ELS_ELS_KS13_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS13_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS13_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UKPUK_SHIFT)) & ELS_ELS_KS13_KSN_UKPUK_MASK)

#define ELS_ELS_KS13_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS13_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS13_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UTECDH_SHIFT)) & ELS_ELS_KS13_KSN_UTECDH_MASK)

#define ELS_ELS_KS13_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS13_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS13_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UCMAC_SHIFT)) & ELS_ELS_KS13_KSN_UCMAC_MASK)

#define ELS_ELS_KS13_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS13_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS13_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UKSK_SHIFT)) & ELS_ELS_KS13_KSN_UKSK_MASK)

#define ELS_ELS_KS13_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS13_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS13_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_URTF_SHIFT)) & ELS_ELS_KS13_KSN_URTF_MASK)

#define ELS_ELS_KS13_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS13_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS13_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UCKDF_SHIFT)) & ELS_ELS_KS13_KSN_UCKDF_MASK)

#define ELS_ELS_KS13_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS13_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS13_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UHKDF_SHIFT)) & ELS_ELS_KS13_KSN_UHKDF_MASK)

#define ELS_ELS_KS13_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS13_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS13_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UECSG_SHIFT)) & ELS_ELS_KS13_KSN_UECSG_MASK)

#define ELS_ELS_KS13_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS13_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS13_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UECDH_SHIFT)) & ELS_ELS_KS13_KSN_UECDH_MASK)

#define ELS_ELS_KS13_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS13_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS13_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UAES_SHIFT)) & ELS_ELS_KS13_KSN_UAES_MASK)

#define ELS_ELS_KS13_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS13_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS13_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UHMAC_SHIFT)) & ELS_ELS_KS13_KSN_UHMAC_MASK)

#define ELS_ELS_KS13_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS13_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS13_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UKWK_SHIFT)) & ELS_ELS_KS13_KSN_UKWK_MASK)

#define ELS_ELS_KS13_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS13_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS13_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UKUOK_SHIFT)) & ELS_ELS_KS13_KSN_UKUOK_MASK)

#define ELS_ELS_KS13_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS13_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS13_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS13_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS13_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS13_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS13_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS13_KSN_UTLSMS_MASK)

#define ELS_ELS_KS13_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS13_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS13_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS13_KSN_UKGSRC_MASK)

#define ELS_ELS_KS13_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS13_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS13_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UHWO_SHIFT)) & ELS_ELS_KS13_KSN_UHWO_MASK)

#define ELS_ELS_KS13_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS13_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS13_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS13_KSN_UWRPOK_MASK)

#define ELS_ELS_KS13_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS13_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS13_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UDUK_SHIFT)) & ELS_ELS_KS13_KSN_UDUK_MASK)

#define ELS_ELS_KS13_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS13_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS13_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS13_KSN_UPPROT_SHIFT)) & ELS_ELS_KS13_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS14 - Key Status */
/*! @{ */

#define ELS_ELS_KS14_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS14_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS14_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_KSIZE_SHIFT)) & ELS_ELS_KS14_KSN_KSIZE_MASK)

#define ELS_ELS_KS14_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS14_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS14_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_KACT_SHIFT)) & ELS_ELS_KS14_KSN_KACT_MASK)

#define ELS_ELS_KS14_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS14_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS14_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_KBASE_SHIFT)) & ELS_ELS_KS14_KSN_KBASE_MASK)

#define ELS_ELS_KS14_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS14_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS14_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KS0_FGP_SHIFT)) & ELS_ELS_KS14_KS0_FGP_MASK)

#define ELS_ELS_KS14_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS14_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS14_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_FRTN_SHIFT)) & ELS_ELS_KS14_KSN_FRTN_MASK)

#define ELS_ELS_KS14_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS14_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS14_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_FHWO_SHIFT)) & ELS_ELS_KS14_KSN_FHWO_MASK)

#define ELS_ELS_KS14_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS14_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS14_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UKPUK_SHIFT)) & ELS_ELS_KS14_KSN_UKPUK_MASK)

#define ELS_ELS_KS14_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS14_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS14_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UTECDH_SHIFT)) & ELS_ELS_KS14_KSN_UTECDH_MASK)

#define ELS_ELS_KS14_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS14_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS14_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UCMAC_SHIFT)) & ELS_ELS_KS14_KSN_UCMAC_MASK)

#define ELS_ELS_KS14_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS14_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS14_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UKSK_SHIFT)) & ELS_ELS_KS14_KSN_UKSK_MASK)

#define ELS_ELS_KS14_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS14_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS14_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_URTF_SHIFT)) & ELS_ELS_KS14_KSN_URTF_MASK)

#define ELS_ELS_KS14_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS14_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS14_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UCKDF_SHIFT)) & ELS_ELS_KS14_KSN_UCKDF_MASK)

#define ELS_ELS_KS14_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS14_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS14_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UHKDF_SHIFT)) & ELS_ELS_KS14_KSN_UHKDF_MASK)

#define ELS_ELS_KS14_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS14_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS14_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UECSG_SHIFT)) & ELS_ELS_KS14_KSN_UECSG_MASK)

#define ELS_ELS_KS14_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS14_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS14_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UECDH_SHIFT)) & ELS_ELS_KS14_KSN_UECDH_MASK)

#define ELS_ELS_KS14_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS14_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS14_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UAES_SHIFT)) & ELS_ELS_KS14_KSN_UAES_MASK)

#define ELS_ELS_KS14_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS14_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS14_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UHMAC_SHIFT)) & ELS_ELS_KS14_KSN_UHMAC_MASK)

#define ELS_ELS_KS14_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS14_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS14_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UKWK_SHIFT)) & ELS_ELS_KS14_KSN_UKWK_MASK)

#define ELS_ELS_KS14_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS14_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS14_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UKUOK_SHIFT)) & ELS_ELS_KS14_KSN_UKUOK_MASK)

#define ELS_ELS_KS14_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS14_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS14_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS14_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS14_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS14_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS14_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS14_KSN_UTLSMS_MASK)

#define ELS_ELS_KS14_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS14_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS14_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS14_KSN_UKGSRC_MASK)

#define ELS_ELS_KS14_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS14_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS14_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UHWO_SHIFT)) & ELS_ELS_KS14_KSN_UHWO_MASK)

#define ELS_ELS_KS14_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS14_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS14_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS14_KSN_UWRPOK_MASK)

#define ELS_ELS_KS14_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS14_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS14_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UDUK_SHIFT)) & ELS_ELS_KS14_KSN_UDUK_MASK)

#define ELS_ELS_KS14_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS14_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS14_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS14_KSN_UPPROT_SHIFT)) & ELS_ELS_KS14_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS15 - Key Status */
/*! @{ */

#define ELS_ELS_KS15_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS15_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS15_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_KSIZE_SHIFT)) & ELS_ELS_KS15_KSN_KSIZE_MASK)

#define ELS_ELS_KS15_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS15_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS15_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_KACT_SHIFT)) & ELS_ELS_KS15_KSN_KACT_MASK)

#define ELS_ELS_KS15_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS15_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS15_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_KBASE_SHIFT)) & ELS_ELS_KS15_KSN_KBASE_MASK)

#define ELS_ELS_KS15_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS15_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS15_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KS0_FGP_SHIFT)) & ELS_ELS_KS15_KS0_FGP_MASK)

#define ELS_ELS_KS15_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS15_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS15_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_FRTN_SHIFT)) & ELS_ELS_KS15_KSN_FRTN_MASK)

#define ELS_ELS_KS15_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS15_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS15_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_FHWO_SHIFT)) & ELS_ELS_KS15_KSN_FHWO_MASK)

#define ELS_ELS_KS15_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS15_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS15_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UKPUK_SHIFT)) & ELS_ELS_KS15_KSN_UKPUK_MASK)

#define ELS_ELS_KS15_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS15_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS15_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UTECDH_SHIFT)) & ELS_ELS_KS15_KSN_UTECDH_MASK)

#define ELS_ELS_KS15_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS15_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS15_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UCMAC_SHIFT)) & ELS_ELS_KS15_KSN_UCMAC_MASK)

#define ELS_ELS_KS15_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS15_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS15_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UKSK_SHIFT)) & ELS_ELS_KS15_KSN_UKSK_MASK)

#define ELS_ELS_KS15_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS15_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS15_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_URTF_SHIFT)) & ELS_ELS_KS15_KSN_URTF_MASK)

#define ELS_ELS_KS15_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS15_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS15_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UCKDF_SHIFT)) & ELS_ELS_KS15_KSN_UCKDF_MASK)

#define ELS_ELS_KS15_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS15_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS15_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UHKDF_SHIFT)) & ELS_ELS_KS15_KSN_UHKDF_MASK)

#define ELS_ELS_KS15_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS15_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS15_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UECSG_SHIFT)) & ELS_ELS_KS15_KSN_UECSG_MASK)

#define ELS_ELS_KS15_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS15_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS15_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UECDH_SHIFT)) & ELS_ELS_KS15_KSN_UECDH_MASK)

#define ELS_ELS_KS15_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS15_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS15_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UAES_SHIFT)) & ELS_ELS_KS15_KSN_UAES_MASK)

#define ELS_ELS_KS15_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS15_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS15_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UHMAC_SHIFT)) & ELS_ELS_KS15_KSN_UHMAC_MASK)

#define ELS_ELS_KS15_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS15_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS15_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UKWK_SHIFT)) & ELS_ELS_KS15_KSN_UKWK_MASK)

#define ELS_ELS_KS15_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS15_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS15_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UKUOK_SHIFT)) & ELS_ELS_KS15_KSN_UKUOK_MASK)

#define ELS_ELS_KS15_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS15_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS15_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS15_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS15_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS15_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS15_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS15_KSN_UTLSMS_MASK)

#define ELS_ELS_KS15_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS15_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS15_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS15_KSN_UKGSRC_MASK)

#define ELS_ELS_KS15_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS15_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS15_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UHWO_SHIFT)) & ELS_ELS_KS15_KSN_UHWO_MASK)

#define ELS_ELS_KS15_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS15_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS15_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS15_KSN_UWRPOK_MASK)

#define ELS_ELS_KS15_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS15_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS15_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UDUK_SHIFT)) & ELS_ELS_KS15_KSN_UDUK_MASK)

#define ELS_ELS_KS15_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS15_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS15_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS15_KSN_UPPROT_SHIFT)) & ELS_ELS_KS15_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS16 - Key Status */
/*! @{ */

#define ELS_ELS_KS16_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS16_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS16_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_KSIZE_SHIFT)) & ELS_ELS_KS16_KSN_KSIZE_MASK)

#define ELS_ELS_KS16_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS16_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS16_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_KACT_SHIFT)) & ELS_ELS_KS16_KSN_KACT_MASK)

#define ELS_ELS_KS16_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS16_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS16_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_KBASE_SHIFT)) & ELS_ELS_KS16_KSN_KBASE_MASK)

#define ELS_ELS_KS16_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS16_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS16_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KS0_FGP_SHIFT)) & ELS_ELS_KS16_KS0_FGP_MASK)

#define ELS_ELS_KS16_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS16_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS16_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_FRTN_SHIFT)) & ELS_ELS_KS16_KSN_FRTN_MASK)

#define ELS_ELS_KS16_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS16_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS16_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_FHWO_SHIFT)) & ELS_ELS_KS16_KSN_FHWO_MASK)

#define ELS_ELS_KS16_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS16_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS16_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UKPUK_SHIFT)) & ELS_ELS_KS16_KSN_UKPUK_MASK)

#define ELS_ELS_KS16_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS16_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS16_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UTECDH_SHIFT)) & ELS_ELS_KS16_KSN_UTECDH_MASK)

#define ELS_ELS_KS16_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS16_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS16_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UCMAC_SHIFT)) & ELS_ELS_KS16_KSN_UCMAC_MASK)

#define ELS_ELS_KS16_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS16_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS16_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UKSK_SHIFT)) & ELS_ELS_KS16_KSN_UKSK_MASK)

#define ELS_ELS_KS16_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS16_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS16_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_URTF_SHIFT)) & ELS_ELS_KS16_KSN_URTF_MASK)

#define ELS_ELS_KS16_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS16_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS16_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UCKDF_SHIFT)) & ELS_ELS_KS16_KSN_UCKDF_MASK)

#define ELS_ELS_KS16_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS16_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS16_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UHKDF_SHIFT)) & ELS_ELS_KS16_KSN_UHKDF_MASK)

#define ELS_ELS_KS16_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS16_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS16_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UECSG_SHIFT)) & ELS_ELS_KS16_KSN_UECSG_MASK)

#define ELS_ELS_KS16_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS16_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS16_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UECDH_SHIFT)) & ELS_ELS_KS16_KSN_UECDH_MASK)

#define ELS_ELS_KS16_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS16_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS16_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UAES_SHIFT)) & ELS_ELS_KS16_KSN_UAES_MASK)

#define ELS_ELS_KS16_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS16_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS16_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UHMAC_SHIFT)) & ELS_ELS_KS16_KSN_UHMAC_MASK)

#define ELS_ELS_KS16_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS16_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS16_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UKWK_SHIFT)) & ELS_ELS_KS16_KSN_UKWK_MASK)

#define ELS_ELS_KS16_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS16_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS16_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UKUOK_SHIFT)) & ELS_ELS_KS16_KSN_UKUOK_MASK)

#define ELS_ELS_KS16_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS16_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS16_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS16_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS16_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS16_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS16_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS16_KSN_UTLSMS_MASK)

#define ELS_ELS_KS16_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS16_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS16_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS16_KSN_UKGSRC_MASK)

#define ELS_ELS_KS16_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS16_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS16_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UHWO_SHIFT)) & ELS_ELS_KS16_KSN_UHWO_MASK)

#define ELS_ELS_KS16_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS16_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS16_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS16_KSN_UWRPOK_MASK)

#define ELS_ELS_KS16_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS16_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS16_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UDUK_SHIFT)) & ELS_ELS_KS16_KSN_UDUK_MASK)

#define ELS_ELS_KS16_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS16_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS16_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS16_KSN_UPPROT_SHIFT)) & ELS_ELS_KS16_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS17 - Key Status */
/*! @{ */

#define ELS_ELS_KS17_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS17_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS17_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_KSIZE_SHIFT)) & ELS_ELS_KS17_KSN_KSIZE_MASK)

#define ELS_ELS_KS17_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS17_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS17_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_KACT_SHIFT)) & ELS_ELS_KS17_KSN_KACT_MASK)

#define ELS_ELS_KS17_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS17_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS17_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_KBASE_SHIFT)) & ELS_ELS_KS17_KSN_KBASE_MASK)

#define ELS_ELS_KS17_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS17_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS17_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KS0_FGP_SHIFT)) & ELS_ELS_KS17_KS0_FGP_MASK)

#define ELS_ELS_KS17_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS17_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS17_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_FRTN_SHIFT)) & ELS_ELS_KS17_KSN_FRTN_MASK)

#define ELS_ELS_KS17_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS17_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS17_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_FHWO_SHIFT)) & ELS_ELS_KS17_KSN_FHWO_MASK)

#define ELS_ELS_KS17_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS17_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS17_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UKPUK_SHIFT)) & ELS_ELS_KS17_KSN_UKPUK_MASK)

#define ELS_ELS_KS17_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS17_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS17_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UTECDH_SHIFT)) & ELS_ELS_KS17_KSN_UTECDH_MASK)

#define ELS_ELS_KS17_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS17_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS17_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UCMAC_SHIFT)) & ELS_ELS_KS17_KSN_UCMAC_MASK)

#define ELS_ELS_KS17_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS17_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS17_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UKSK_SHIFT)) & ELS_ELS_KS17_KSN_UKSK_MASK)

#define ELS_ELS_KS17_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS17_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS17_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_URTF_SHIFT)) & ELS_ELS_KS17_KSN_URTF_MASK)

#define ELS_ELS_KS17_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS17_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS17_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UCKDF_SHIFT)) & ELS_ELS_KS17_KSN_UCKDF_MASK)

#define ELS_ELS_KS17_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS17_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS17_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UHKDF_SHIFT)) & ELS_ELS_KS17_KSN_UHKDF_MASK)

#define ELS_ELS_KS17_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS17_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS17_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UECSG_SHIFT)) & ELS_ELS_KS17_KSN_UECSG_MASK)

#define ELS_ELS_KS17_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS17_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS17_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UECDH_SHIFT)) & ELS_ELS_KS17_KSN_UECDH_MASK)

#define ELS_ELS_KS17_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS17_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS17_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UAES_SHIFT)) & ELS_ELS_KS17_KSN_UAES_MASK)

#define ELS_ELS_KS17_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS17_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS17_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UHMAC_SHIFT)) & ELS_ELS_KS17_KSN_UHMAC_MASK)

#define ELS_ELS_KS17_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS17_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS17_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UKWK_SHIFT)) & ELS_ELS_KS17_KSN_UKWK_MASK)

#define ELS_ELS_KS17_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS17_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS17_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UKUOK_SHIFT)) & ELS_ELS_KS17_KSN_UKUOK_MASK)

#define ELS_ELS_KS17_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS17_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS17_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS17_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS17_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS17_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS17_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS17_KSN_UTLSMS_MASK)

#define ELS_ELS_KS17_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS17_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS17_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS17_KSN_UKGSRC_MASK)

#define ELS_ELS_KS17_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS17_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS17_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UHWO_SHIFT)) & ELS_ELS_KS17_KSN_UHWO_MASK)

#define ELS_ELS_KS17_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS17_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS17_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS17_KSN_UWRPOK_MASK)

#define ELS_ELS_KS17_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS17_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS17_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UDUK_SHIFT)) & ELS_ELS_KS17_KSN_UDUK_MASK)

#define ELS_ELS_KS17_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS17_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS17_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS17_KSN_UPPROT_SHIFT)) & ELS_ELS_KS17_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS18 - Key Status */
/*! @{ */

#define ELS_ELS_KS18_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS18_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS18_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_KSIZE_SHIFT)) & ELS_ELS_KS18_KSN_KSIZE_MASK)

#define ELS_ELS_KS18_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS18_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS18_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_KACT_SHIFT)) & ELS_ELS_KS18_KSN_KACT_MASK)

#define ELS_ELS_KS18_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS18_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS18_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_KBASE_SHIFT)) & ELS_ELS_KS18_KSN_KBASE_MASK)

#define ELS_ELS_KS18_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS18_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS18_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KS0_FGP_SHIFT)) & ELS_ELS_KS18_KS0_FGP_MASK)

#define ELS_ELS_KS18_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS18_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS18_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_FRTN_SHIFT)) & ELS_ELS_KS18_KSN_FRTN_MASK)

#define ELS_ELS_KS18_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS18_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS18_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_FHWO_SHIFT)) & ELS_ELS_KS18_KSN_FHWO_MASK)

#define ELS_ELS_KS18_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS18_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS18_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UKPUK_SHIFT)) & ELS_ELS_KS18_KSN_UKPUK_MASK)

#define ELS_ELS_KS18_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS18_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS18_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UTECDH_SHIFT)) & ELS_ELS_KS18_KSN_UTECDH_MASK)

#define ELS_ELS_KS18_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS18_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS18_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UCMAC_SHIFT)) & ELS_ELS_KS18_KSN_UCMAC_MASK)

#define ELS_ELS_KS18_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS18_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS18_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UKSK_SHIFT)) & ELS_ELS_KS18_KSN_UKSK_MASK)

#define ELS_ELS_KS18_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS18_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS18_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_URTF_SHIFT)) & ELS_ELS_KS18_KSN_URTF_MASK)

#define ELS_ELS_KS18_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS18_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS18_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UCKDF_SHIFT)) & ELS_ELS_KS18_KSN_UCKDF_MASK)

#define ELS_ELS_KS18_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS18_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS18_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UHKDF_SHIFT)) & ELS_ELS_KS18_KSN_UHKDF_MASK)

#define ELS_ELS_KS18_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS18_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS18_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UECSG_SHIFT)) & ELS_ELS_KS18_KSN_UECSG_MASK)

#define ELS_ELS_KS18_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS18_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS18_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UECDH_SHIFT)) & ELS_ELS_KS18_KSN_UECDH_MASK)

#define ELS_ELS_KS18_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS18_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS18_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UAES_SHIFT)) & ELS_ELS_KS18_KSN_UAES_MASK)

#define ELS_ELS_KS18_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS18_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS18_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UHMAC_SHIFT)) & ELS_ELS_KS18_KSN_UHMAC_MASK)

#define ELS_ELS_KS18_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS18_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS18_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UKWK_SHIFT)) & ELS_ELS_KS18_KSN_UKWK_MASK)

#define ELS_ELS_KS18_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS18_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS18_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UKUOK_SHIFT)) & ELS_ELS_KS18_KSN_UKUOK_MASK)

#define ELS_ELS_KS18_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS18_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS18_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS18_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS18_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS18_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS18_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS18_KSN_UTLSMS_MASK)

#define ELS_ELS_KS18_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS18_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS18_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS18_KSN_UKGSRC_MASK)

#define ELS_ELS_KS18_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS18_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS18_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UHWO_SHIFT)) & ELS_ELS_KS18_KSN_UHWO_MASK)

#define ELS_ELS_KS18_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS18_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS18_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS18_KSN_UWRPOK_MASK)

#define ELS_ELS_KS18_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS18_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS18_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UDUK_SHIFT)) & ELS_ELS_KS18_KSN_UDUK_MASK)

#define ELS_ELS_KS18_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS18_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS18_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS18_KSN_UPPROT_SHIFT)) & ELS_ELS_KS18_KSN_UPPROT_MASK)
/*! @} */

/*! @name ELS_KS19 - Key Status */
/*! @{ */

#define ELS_ELS_KS19_KSN_KSIZE_MASK              (0x3U)
#define ELS_ELS_KS19_KSN_KSIZE_SHIFT             (0U)
/*! KSn_KSIZE
 *  0b00..Key size is 128 bits (1 slot)
 *  0b01..Key size is 256 bits (2 slots)
 *  0b10..Reserved
 *  0b11..Key size is 512 bits (4 slots)
 */
#define ELS_ELS_KS19_KSN_KSIZE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_KSIZE_SHIFT)) & ELS_ELS_KS19_KSN_KSIZE_MASK)

#define ELS_ELS_KS19_KSN_KACT_MASK               (0x20U)
#define ELS_ELS_KS19_KSN_KACT_SHIFT              (5U)
/*! KSn_KACT
 *  0b0..Key slot is not in use by a key
 *  0b1..Key is in use by a key
 */
#define ELS_ELS_KS19_KSN_KACT(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_KACT_SHIFT)) & ELS_ELS_KS19_KSN_KACT_MASK)

#define ELS_ELS_KS19_KSN_KBASE_MASK              (0x40U)
#define ELS_ELS_KS19_KSN_KBASE_SHIFT             (6U)
/*! KSn_KBASE
 *  0b0..Key is not a base slot of a multi slot key
 *  0b1..Key is a base slot of a multi slot key
 */
#define ELS_ELS_KS19_KSN_KBASE(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_KBASE_SHIFT)) & ELS_ELS_KS19_KSN_KBASE_MASK)

#define ELS_ELS_KS19_KS0_FGP_MASK                (0x80U)
#define ELS_ELS_KS19_KS0_FGP_SHIFT               (7U)
/*! KS0_FGP
 *  0b0..Slot is not a general purpose type key slot
 *  0b1..Slot is a general purpose type key slot
 */
#define ELS_ELS_KS19_KS0_FGP(x)                  (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KS0_FGP_SHIFT)) & ELS_ELS_KS19_KS0_FGP_MASK)

#define ELS_ELS_KS19_KSN_FRTN_MASK               (0x100U)
#define ELS_ELS_KS19_KSN_FRTN_SHIFT              (8U)
/*! KSn_FRTN
 *  0b0..Slot is not a retention type key slot
 *  0b1..Slot is a retention type key slot
 */
#define ELS_ELS_KS19_KSN_FRTN(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_FRTN_SHIFT)) & ELS_ELS_KS19_KSN_FRTN_MASK)

#define ELS_ELS_KS19_KSN_FHWO_MASK               (0x200U)
#define ELS_ELS_KS19_KSN_FHWO_SHIFT              (9U)
/*! KSn_FHWO
 *  0b0..Slot is not a hardware out type key slot
 *  0b1..Slot is a hardware out type key slot
 */
#define ELS_ELS_KS19_KSN_FHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_FHWO_SHIFT)) & ELS_ELS_KS19_KSN_FHWO_MASK)

#define ELS_ELS_KS19_KSN_UKPUK_MASK              (0x800U)
#define ELS_ELS_KS19_KSN_UKPUK_SHIFT             (11U)
/*! KSn_UKPUK
 *  0b0..Key is not a trusted public key
 *  0b1..Key is a trusted public key
 */
#define ELS_ELS_KS19_KSN_UKPUK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UKPUK_SHIFT)) & ELS_ELS_KS19_KSN_UKPUK_MASK)

#define ELS_ELS_KS19_KSN_UTECDH_MASK             (0x1000U)
#define ELS_ELS_KS19_KSN_UTECDH_SHIFT            (12U)
/*! KSn_UTECDH
 *  0b0..Key is not a UTECDH key
 *  0b1..Key is a UTECDH key
 */
#define ELS_ELS_KS19_KSN_UTECDH(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UTECDH_SHIFT)) & ELS_ELS_KS19_KSN_UTECDH_MASK)

#define ELS_ELS_KS19_KSN_UCMAC_MASK              (0x2000U)
#define ELS_ELS_KS19_KSN_UCMAC_SHIFT             (13U)
/*! KSn_UCMAC
 *  0b0..Key is not a CMAC key
 *  0b1..Key is a CMAC key
 */
#define ELS_ELS_KS19_KSN_UCMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UCMAC_SHIFT)) & ELS_ELS_KS19_KSN_UCMAC_MASK)

#define ELS_ELS_KS19_KSN_UKSK_MASK               (0x4000U)
#define ELS_ELS_KS19_KSN_UKSK_SHIFT              (14U)
/*! KSn_UKSK
 *  0b0..Key is not a public key signing Key
 *  0b1..Key is a public key signing key
 */
#define ELS_ELS_KS19_KSN_UKSK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UKSK_SHIFT)) & ELS_ELS_KS19_KSN_UKSK_MASK)

#define ELS_ELS_KS19_KSN_URTF_MASK               (0x8000U)
#define ELS_ELS_KS19_KSN_URTF_SHIFT              (15U)
/*! KSn_URTF
 *  0b0..Key is not a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 *  0b1..Key is a ECC signing key that can be used as the input private key to ECSIGN command when SIGNRTF command parameter is set
 */
#define ELS_ELS_KS19_KSN_URTF(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_URTF_SHIFT)) & ELS_ELS_KS19_KSN_URTF_MASK)

#define ELS_ELS_KS19_KSN_UCKDF_MASK              (0x10000U)
#define ELS_ELS_KS19_KSN_UCKDF_SHIFT             (16U)
/*! KSn_UCKDF
 *  0b0..Key is not a CMAC based derivation key
 *  0b1..Key is a CMAC based derivation key
 */
#define ELS_ELS_KS19_KSN_UCKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UCKDF_SHIFT)) & ELS_ELS_KS19_KSN_UCKDF_MASK)

#define ELS_ELS_KS19_KSN_UHKDF_MASK              (0x20000U)
#define ELS_ELS_KS19_KSN_UHKDF_SHIFT             (17U)
/*! KSn_UHKDF
 *  0b0..Key is not a HKDF key
 *  0b1..Key is a HKDF key
 */
#define ELS_ELS_KS19_KSN_UHKDF(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UHKDF_SHIFT)) & ELS_ELS_KS19_KSN_UHKDF_MASK)

#define ELS_ELS_KS19_KSN_UECSG_MASK              (0x40000U)
#define ELS_ELS_KS19_KSN_UECSG_SHIFT             (18U)
/*! KSn_UECSG
 *  0b0..Key is not a ECC signing key
 *  0b1..Key is a ECC signing key
 */
#define ELS_ELS_KS19_KSN_UECSG(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UECSG_SHIFT)) & ELS_ELS_KS19_KSN_UECSG_MASK)

#define ELS_ELS_KS19_KSN_UECDH_MASK              (0x80000U)
#define ELS_ELS_KS19_KSN_UECDH_SHIFT             (19U)
/*! KSn_UECDH
 *  0b0..Key is not a Diffie hellman key exchange private key
 *  0b1..Key is a Diffie hellman key exchange private key
 */
#define ELS_ELS_KS19_KSN_UECDH(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UECDH_SHIFT)) & ELS_ELS_KS19_KSN_UECDH_MASK)

#define ELS_ELS_KS19_KSN_UAES_MASK               (0x100000U)
#define ELS_ELS_KS19_KSN_UAES_SHIFT              (20U)
/*! KSn_UAES
 *  0b0..Key is not a AES key
 *  0b1..Key is a AES key
 */
#define ELS_ELS_KS19_KSN_UAES(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UAES_SHIFT)) & ELS_ELS_KS19_KSN_UAES_MASK)

#define ELS_ELS_KS19_KSN_UHMAC_MASK              (0x200000U)
#define ELS_ELS_KS19_KSN_UHMAC_SHIFT             (21U)
/*! KSn_UHMAC
 *  0b0..Key is not a HMAC key
 *  0b1..Key is a HMAC key
 */
#define ELS_ELS_KS19_KSN_UHMAC(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UHMAC_SHIFT)) & ELS_ELS_KS19_KSN_UHMAC_MASK)

#define ELS_ELS_KS19_KSN_UKWK_MASK               (0x400000U)
#define ELS_ELS_KS19_KSN_UKWK_SHIFT              (22U)
/*! KSn_UKWK
 *  0b0..Key is not a RFC3394 key wrap plus unwrap only key
 *  0b1..Key is a RFC3394 key wrap plus unwrap only key
 */
#define ELS_ELS_KS19_KSN_UKWK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UKWK_SHIFT)) & ELS_ELS_KS19_KSN_UKWK_MASK)

#define ELS_ELS_KS19_KSN_UKUOK_MASK              (0x800000U)
#define ELS_ELS_KS19_KSN_UKUOK_SHIFT             (23U)
/*! KSn_UKUOK
 *  0b0..Key is not a RFC3394 key unwrap only key
 *  0b1..Key is a RFC3394 key unwrap only key
 */
#define ELS_ELS_KS19_KSN_UKUOK(x)                (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UKUOK_SHIFT)) & ELS_ELS_KS19_KSN_UKUOK_MASK)

#define ELS_ELS_KS19_KSN_UTLSPMS_MASK            (0x1000000U)
#define ELS_ELS_KS19_KSN_UTLSPMS_SHIFT           (24U)
/*! KSn_UTLSPMS
 *  0b0..Key is not a TLS pre master secret key
 *  0b1..Key is a TLS pre master secret key
 */
#define ELS_ELS_KS19_KSN_UTLSPMS(x)              (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UTLSPMS_SHIFT)) & ELS_ELS_KS19_KSN_UTLSPMS_MASK)

#define ELS_ELS_KS19_KSN_UTLSMS_MASK             (0x2000000U)
#define ELS_ELS_KS19_KSN_UTLSMS_SHIFT            (25U)
/*! KSn_UTLSMS
 *  0b0..Key is not a TLS master secret key
 *  0b1..Key is a TLS master secret key
 */
#define ELS_ELS_KS19_KSN_UTLSMS(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UTLSMS_SHIFT)) & ELS_ELS_KS19_KSN_UTLSMS_MASK)

#define ELS_ELS_KS19_KSN_UKGSRC_MASK             (0x4000000U)
#define ELS_ELS_KS19_KSN_UKGSRC_SHIFT            (26U)
/*! KSn_UKGSRC
 *  0b0..Key cannot be used as a key material source for deterministic ECC keygen
 *  0b1..Key can be used as a key material source for deterministic ECC keygen
 */
#define ELS_ELS_KS19_KSN_UKGSRC(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UKGSRC_SHIFT)) & ELS_ELS_KS19_KSN_UKGSRC_MASK)

#define ELS_ELS_KS19_KSN_UHWO_MASK               (0x8000000U)
#define ELS_ELS_KS19_KSN_UHWO_SHIFT              (27U)
/*! KSn_UHWO
 *  0b0..Key can exist in any slot
 *  0b1..Key can only exist in a hardware out slot
 */
#define ELS_ELS_KS19_KSN_UHWO(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UHWO_SHIFT)) & ELS_ELS_KS19_KSN_UHWO_MASK)

#define ELS_ELS_KS19_KSN_UWRPOK_MASK             (0x10000000U)
#define ELS_ELS_KS19_KSN_UWRPOK_SHIFT            (28U)
/*! KSn_UWRPOK
 *  0b0..Key cannot be RFC3394 wrapped
 *  0b1..Key can be RFC3394 wrapped
 */
#define ELS_ELS_KS19_KSN_UWRPOK(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UWRPOK_SHIFT)) & ELS_ELS_KS19_KSN_UWRPOK_MASK)

#define ELS_ELS_KS19_KSN_UDUK_MASK               (0x20000000U)
#define ELS_ELS_KS19_KSN_UDUK_SHIFT              (29U)
/*! KSn_UDUK
 *  0b0..Key is not a device unique key
 *  0b1..Key is a device unique key
 */
#define ELS_ELS_KS19_KSN_UDUK(x)                 (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UDUK_SHIFT)) & ELS_ELS_KS19_KSN_UDUK_MASK)

#define ELS_ELS_KS19_KSN_UPPROT_MASK             (0xC0000000U)
#define ELS_ELS_KS19_KSN_UPPROT_SHIFT            (30U)
/*! KSn_UPPROT
 *  0b00..Non-privileged, secure
 *  0b01..Privileged, secure
 *  0b10..Non-privileged, non-secure
 *  0b11..Privileged, non-secure
 */
#define ELS_ELS_KS19_KSN_UPPROT(x)               (((uint32_t)(((uint32_t)(x)) << ELS_ELS_KS19_KSN_UPPROT_SHIFT)) & ELS_ELS_KS19_KSN_UPPROT_MASK)
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


#endif  /* PERI_ELS_H_ */

