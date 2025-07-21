/*
** ###################################################################
**     Processors:          LPC54005JBD100
**                          LPC54005JET100
**                          LPC54016JBD100
**                          LPC54016JBD208
**                          LPC54016JET100
**                          LPC54016JET180
**                          LPC54018JBD208
**                          LPC54018JET180
**                          LPC54S005JBD100
**                          LPC54S005JET100
**                          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**                          LPC54S018JBD208
**                          LPC54S018JET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AES
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AES.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AES
 *
 * CMSIS Peripheral Access Layer for AES
 */

#if !defined(PERI_AES_H_)
#define PERI_AES_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54005JBD100) || defined(CPU_LPC54005JET100))
#include "LPC54005_COMMON.h"
#elif (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || defined(CPU_LPC54016JET180))
#include "LPC54016_COMMON.h"
#elif (defined(CPU_LPC54018JBD208) || defined(CPU_LPC54018JET180))
#include "LPC54018_COMMON.h"
#elif (defined(CPU_LPC54S005JBD100) || defined(CPU_LPC54S005JET100))
#include "LPC54S005_COMMON.h"
#elif (defined(CPU_LPC54S016JBD100) || defined(CPU_LPC54S016JBD208) || defined(CPU_LPC54S016JET100) || defined(CPU_LPC54S016JET180))
#include "LPC54S016_COMMON.h"
#elif (defined(CPU_LPC54S018JBD208) || defined(CPU_LPC54S018JET180))
#include "LPC54S018_COMMON.h"
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
   -- AES Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_Peripheral_Access_Layer AES Peripheral Access Layer
 * @{
 */

/** AES - Size of Registers Arrays */
#define AES_KEY_COUNT                             8u
#define AES_INTEXT_COUNT                          4u
#define AES_HOLDING_COUNT                         4u
#define AES_OUTTEXT_COUNT                         4u
#define AES_GF128_Y_COUNT                         4u
#define AES_GF128_Z_COUNT                         4u
#define AES_GCM_TAG_COUNT                         4u

/** AES - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __IO uint32_t CFG;                               /**< AES Configuration register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      union {                                          /* offset: 0x0 */
        __IO uint16_t CFG0_15;                           /**< AES Configuration register 0:15, offset: 0x0 */
        struct {                                         /* offset: 0x0 */
          __IO uint8_t CFG0_7;                             /**< AES Configuration register 0:7, offset: 0x0 */
          __IO uint8_t CFG8_15;                            /**< AES Configuration register 8:15, offset: 0x1 */
        } CFGL;
      };
      __IO uint16_t CFG16_31;                          /**< AES Configuration register 16:31, offset: 0x2 */
    } CFG0_32;
  };
  __IO uint32_t CMD;                               /**< AES Command register, offset: 0x4 */
  __IO uint32_t STAT;                              /**< AES Status register, offset: 0x8 */
  __IO uint32_t CTR_INCR;                          /**< Counter Increment, offset: 0xC */
       uint8_t RESERVED_0[16];
  __O  uint32_t KEY[AES_KEY_COUNT];                /**< Bits of the AES key, array offset: 0x20, array step: 0x4 */
  __O  uint32_t INTEXT[AES_INTEXT_COUNT];          /**< Input text bits, array offset: 0x40, array step: 0x4 */
  __O  uint32_t HOLDING[AES_HOLDING_COUNT];        /**< Holding register bits, array offset: 0x50, array step: 0x4 */
  __I  uint32_t OUTTEXT[AES_OUTTEXT_COUNT];        /**< Output text bits, array offset: 0x60, array step: 0x4 */
  __O  uint32_t GF128_Y[AES_GF128_Y_COUNT];        /**< Y bits input of GF128 hash, array offset: 0x70, array step: 0x4 */
  __I  uint32_t GF128_Z[AES_GF128_Z_COUNT];        /**< Result bits of GF128 hash, array offset: 0x80, array step: 0x4 */
  __I  uint32_t GCM_TAG[AES_GCM_TAG_COUNT];        /**< GCM Tag bits, array offset: 0x90, array step: 0x4 */
} AES_Type;

/* ----------------------------------------------------------------------------
   -- AES Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AES_Register_Masks AES Register Masks
 * @{
 */

/*! @name CFG - AES Configuration register */
/*! @{ */

#define AES_CFG_PROC_EN_MASK                     (0x3U)
#define AES_CFG_PROC_EN_SHIFT                    (0U)
/*! PROC_EN - Process type enable. */
#define AES_CFG_PROC_EN(x)                       (((uint32_t)(((uint32_t)(x)) << AES_CFG_PROC_EN_SHIFT)) & AES_CFG_PROC_EN_MASK)

#define AES_CFG_GF128_SEL_MASK                   (0x4U)
#define AES_CFG_GF128_SEL_SHIFT                  (2U)
/*! GF128_SEL - GF128 hash selection. */
#define AES_CFG_GF128_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << AES_CFG_GF128_SEL_SHIFT)) & AES_CFG_GF128_SEL_MASK)

#define AES_CFG_INTEXT_BSWAP_MASK                (0x10U)
#define AES_CFG_INTEXT_BSWAP_SHIFT               (4U)
/*! INTEXT_BSWAP - Byte swap input text. */
#define AES_CFG_INTEXT_BSWAP(x)                  (((uint32_t)(((uint32_t)(x)) << AES_CFG_INTEXT_BSWAP_SHIFT)) & AES_CFG_INTEXT_BSWAP_MASK)

#define AES_CFG_INTEXT_WSWAP_MASK                (0x20U)
#define AES_CFG_INTEXT_WSWAP_SHIFT               (5U)
/*! INTEXT_WSWAP - Word swap input text. */
#define AES_CFG_INTEXT_WSWAP(x)                  (((uint32_t)(((uint32_t)(x)) << AES_CFG_INTEXT_WSWAP_SHIFT)) & AES_CFG_INTEXT_WSWAP_MASK)

#define AES_CFG_OUTTEXT_BSWAP_MASK               (0x40U)
#define AES_CFG_OUTTEXT_BSWAP_SHIFT              (6U)
/*! OUTTEXT_BSWAP - Byte swap output text. */
#define AES_CFG_OUTTEXT_BSWAP(x)                 (((uint32_t)(((uint32_t)(x)) << AES_CFG_OUTTEXT_BSWAP_SHIFT)) & AES_CFG_OUTTEXT_BSWAP_MASK)

#define AES_CFG_OUTTEXT_WSWAP_MASK               (0x80U)
#define AES_CFG_OUTTEXT_WSWAP_SHIFT              (7U)
/*! OUTTEXT_WSWAP - Word swap output text. */
#define AES_CFG_OUTTEXT_WSWAP(x)                 (((uint32_t)(((uint32_t)(x)) << AES_CFG_OUTTEXT_WSWAP_SHIFT)) & AES_CFG_OUTTEXT_WSWAP_MASK)

#define AES_CFG_KEY_CFG_MASK                     (0x300U)
#define AES_CFG_KEY_CFG_SHIFT                    (8U)
/*! KEY_CFG - Key Configuration. */
#define AES_CFG_KEY_CFG(x)                       (((uint32_t)(((uint32_t)(x)) << AES_CFG_KEY_CFG_SHIFT)) & AES_CFG_KEY_CFG_MASK)

#define AES_CFG_INBLK_SEL_MASK                   (0x30000U)
#define AES_CFG_INBLK_SEL_SHIFT                  (16U)
/*! INBLK_SEL - Input block select. */
#define AES_CFG_INBLK_SEL(x)                     (((uint32_t)(((uint32_t)(x)) << AES_CFG_INBLK_SEL_SHIFT)) & AES_CFG_INBLK_SEL_MASK)

#define AES_CFG_HOLD_SEL_MASK                    (0x300000U)
#define AES_CFG_HOLD_SEL_SHIFT                   (20U)
/*! HOLD_SEL - Holding register source select. */
#define AES_CFG_HOLD_SEL(x)                      (((uint32_t)(((uint32_t)(x)) << AES_CFG_HOLD_SEL_SHIFT)) & AES_CFG_HOLD_SEL_MASK)

#define AES_CFG_OUTTEXT_SEL_MASK                 (0x3000000U)
#define AES_CFG_OUTTEXT_SEL_SHIFT                (24U)
/*! OUTTEXT_SEL - Output text source select. */
#define AES_CFG_OUTTEXT_SEL(x)                   (((uint32_t)(((uint32_t)(x)) << AES_CFG_OUTTEXT_SEL_SHIFT)) & AES_CFG_OUTTEXT_SEL_MASK)
/*! @} */

/*! @name CFG0_15 - AES Configuration register 0:15 */
/*! @{ */

#define AES_CFG0_15_PROC_EN_MASK                 (0x3U)
#define AES_CFG0_15_PROC_EN_SHIFT                (0U)
/*! PROC_EN - Process type enable. */
#define AES_CFG0_15_PROC_EN(x)                   (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_PROC_EN_SHIFT)) & AES_CFG0_15_PROC_EN_MASK)

#define AES_CFG0_15_GF128_SEL_MASK               (0x4U)
#define AES_CFG0_15_GF128_SEL_SHIFT              (2U)
/*! GF128_SEL - GF128 hash selection. */
#define AES_CFG0_15_GF128_SEL(x)                 (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_GF128_SEL_SHIFT)) & AES_CFG0_15_GF128_SEL_MASK)

#define AES_CFG0_15_INTEXT_BSWAP_MASK            (0x10U)
#define AES_CFG0_15_INTEXT_BSWAP_SHIFT           (4U)
/*! INTEXT_BSWAP - Byte swap input text. */
#define AES_CFG0_15_INTEXT_BSWAP(x)              (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_INTEXT_BSWAP_SHIFT)) & AES_CFG0_15_INTEXT_BSWAP_MASK)

#define AES_CFG0_15_INTEXT_WSWAP_MASK            (0x20U)
#define AES_CFG0_15_INTEXT_WSWAP_SHIFT           (5U)
/*! INTEXT_WSWAP - Word swap input text. */
#define AES_CFG0_15_INTEXT_WSWAP(x)              (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_INTEXT_WSWAP_SHIFT)) & AES_CFG0_15_INTEXT_WSWAP_MASK)

#define AES_CFG0_15_OUTTEXT_BSWAP_MASK           (0x40U)
#define AES_CFG0_15_OUTTEXT_BSWAP_SHIFT          (6U)
/*! OUTTEXT_BSWAP - Byte swap output text. */
#define AES_CFG0_15_OUTTEXT_BSWAP(x)             (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_OUTTEXT_BSWAP_SHIFT)) & AES_CFG0_15_OUTTEXT_BSWAP_MASK)

#define AES_CFG0_15_OUTTEXT_WSWAP_MASK           (0x80U)
#define AES_CFG0_15_OUTTEXT_WSWAP_SHIFT          (7U)
/*! OUTTEXT_WSWAP - Word swap output text. */
#define AES_CFG0_15_OUTTEXT_WSWAP(x)             (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_OUTTEXT_WSWAP_SHIFT)) & AES_CFG0_15_OUTTEXT_WSWAP_MASK)

#define AES_CFG0_15_KEY_CFG_MASK                 (0x300U)
#define AES_CFG0_15_KEY_CFG_SHIFT                (8U)
/*! KEY_CFG - Key Configuration. */
#define AES_CFG0_15_KEY_CFG(x)                   (((uint16_t)(((uint16_t)(x)) << AES_CFG0_15_KEY_CFG_SHIFT)) & AES_CFG0_15_KEY_CFG_MASK)
/*! @} */

/*! @name CFG0_7 - AES Configuration register 0:7 */
/*! @{ */

#define AES_CFG0_7_PROC_EN_MASK                  (0x3U)
#define AES_CFG0_7_PROC_EN_SHIFT                 (0U)
/*! PROC_EN - Process type enable. */
#define AES_CFG0_7_PROC_EN(x)                    (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_PROC_EN_SHIFT)) & AES_CFG0_7_PROC_EN_MASK)

#define AES_CFG0_7_GF128_SEL_MASK                (0x4U)
#define AES_CFG0_7_GF128_SEL_SHIFT               (2U)
/*! GF128_SEL - GF128 hash selection. */
#define AES_CFG0_7_GF128_SEL(x)                  (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_GF128_SEL_SHIFT)) & AES_CFG0_7_GF128_SEL_MASK)

#define AES_CFG0_7_INTEXT_BSWAP_MASK             (0x10U)
#define AES_CFG0_7_INTEXT_BSWAP_SHIFT            (4U)
/*! INTEXT_BSWAP - Byte swap input text. */
#define AES_CFG0_7_INTEXT_BSWAP(x)               (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_INTEXT_BSWAP_SHIFT)) & AES_CFG0_7_INTEXT_BSWAP_MASK)

#define AES_CFG0_7_INTEXT_WSWAP_MASK             (0x20U)
#define AES_CFG0_7_INTEXT_WSWAP_SHIFT            (5U)
/*! INTEXT_WSWAP - Word swap input text. */
#define AES_CFG0_7_INTEXT_WSWAP(x)               (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_INTEXT_WSWAP_SHIFT)) & AES_CFG0_7_INTEXT_WSWAP_MASK)

#define AES_CFG0_7_OUTTEXT_BSWAP_MASK            (0x40U)
#define AES_CFG0_7_OUTTEXT_BSWAP_SHIFT           (6U)
/*! OUTTEXT_BSWAP - Byte swap output text. */
#define AES_CFG0_7_OUTTEXT_BSWAP(x)              (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_OUTTEXT_BSWAP_SHIFT)) & AES_CFG0_7_OUTTEXT_BSWAP_MASK)

#define AES_CFG0_7_OUTTEXT_WSWAP_MASK            (0x80U)
#define AES_CFG0_7_OUTTEXT_WSWAP_SHIFT           (7U)
/*! OUTTEXT_WSWAP - Word swap output text. */
#define AES_CFG0_7_OUTTEXT_WSWAP(x)              (((uint8_t)(((uint8_t)(x)) << AES_CFG0_7_OUTTEXT_WSWAP_SHIFT)) & AES_CFG0_7_OUTTEXT_WSWAP_MASK)
/*! @} */

/*! @name CFG8_15 - AES Configuration register 8:15 */
/*! @{ */

#define AES_CFG8_15_KEY_CFG_MASK                 (0x3U)
#define AES_CFG8_15_KEY_CFG_SHIFT                (0U)
/*! KEY_CFG - Key Configuration. */
#define AES_CFG8_15_KEY_CFG(x)                   (((uint8_t)(((uint8_t)(x)) << AES_CFG8_15_KEY_CFG_SHIFT)) & AES_CFG8_15_KEY_CFG_MASK)
/*! @} */

/*! @name CFG16_31 - AES Configuration register 16:31 */
/*! @{ */

#define AES_CFG16_31_INBLK_SEL_MASK              (0x3U)
#define AES_CFG16_31_INBLK_SEL_SHIFT             (0U)
/*! INBLK_SEL - Input block select. */
#define AES_CFG16_31_INBLK_SEL(x)                (((uint16_t)(((uint16_t)(x)) << AES_CFG16_31_INBLK_SEL_SHIFT)) & AES_CFG16_31_INBLK_SEL_MASK)

#define AES_CFG16_31_HOLD_SEL_MASK               (0x30U)
#define AES_CFG16_31_HOLD_SEL_SHIFT              (4U)
/*! HOLD_SEL - Holding register source select. */
#define AES_CFG16_31_HOLD_SEL(x)                 (((uint16_t)(((uint16_t)(x)) << AES_CFG16_31_HOLD_SEL_SHIFT)) & AES_CFG16_31_HOLD_SEL_MASK)

#define AES_CFG16_31_OUTTEXT_SEL_MASK            (0x300U)
#define AES_CFG16_31_OUTTEXT_SEL_SHIFT           (8U)
/*! OUTTEXT_SEL - Output text source select. */
#define AES_CFG16_31_OUTTEXT_SEL(x)              (((uint16_t)(((uint16_t)(x)) << AES_CFG16_31_OUTTEXT_SEL_SHIFT)) & AES_CFG16_31_OUTTEXT_SEL_MASK)
/*! @} */

/*! @name CMD - AES Command register */
/*! @{ */

#define AES_CMD_COPY_TO_Y_MASK                   (0x2U)
#define AES_CMD_COPY_TO_Y_SHIFT                  (1U)
/*! COPY_TO_Y - Copy output text to GF128Y. */
#define AES_CMD_COPY_TO_Y(x)                     (((uint32_t)(((uint32_t)(x)) << AES_CMD_COPY_TO_Y_SHIFT)) & AES_CMD_COPY_TO_Y_MASK)

#define AES_CMD_SWITCH_MODE_MASK                 (0x10U)
#define AES_CMD_SWITCH_MODE_SHIFT                (4U)
/*! SWITCH_MODE - When this bit is set the mode switches from forward mode (encryption) to reverse
 *    mode (decryption) or reverse mode to forward mode.
 */
#define AES_CMD_SWITCH_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << AES_CMD_SWITCH_MODE_SHIFT)) & AES_CMD_SWITCH_MODE_MASK)

#define AES_CMD_ABORT_MASK                       (0x100U)
#define AES_CMD_ABORT_SHIFT                      (8U)
/*! ABORT - Aborts Encrypt/Decrypt and GF128 Hash operation. */
#define AES_CMD_ABORT(x)                         (((uint32_t)(((uint32_t)(x)) << AES_CMD_ABORT_SHIFT)) & AES_CMD_ABORT_MASK)

#define AES_CMD_WIPE_MASK                        (0x200U)
#define AES_CMD_WIPE_SHIFT                       (9U)
/*! WIPE - When set this bit performs abort, clears KEY and GF128_Y registers and disables cipher. */
#define AES_CMD_WIPE(x)                          (((uint32_t)(((uint32_t)(x)) << AES_CMD_WIPE_SHIFT)) & AES_CMD_WIPE_MASK)
/*! @} */

/*! @name STAT - AES Status register */
/*! @{ */

#define AES_STAT_IDLE_MASK                       (0x1U)
#define AES_STAT_IDLE_SHIFT                      (0U)
/*! IDLE - AES engine Idle. */
#define AES_STAT_IDLE(x)                         (((uint32_t)(((uint32_t)(x)) << AES_STAT_IDLE_SHIFT)) & AES_STAT_IDLE_MASK)

#define AES_STAT_IN_READY_MASK                   (0x2U)
#define AES_STAT_IN_READY_SHIFT                  (1U)
/*! IN_READY - Input text ready. */
#define AES_STAT_IN_READY(x)                     (((uint32_t)(((uint32_t)(x)) << AES_STAT_IN_READY_SHIFT)) & AES_STAT_IN_READY_MASK)

#define AES_STAT_OUT_READY_MASK                  (0x4U)
#define AES_STAT_OUT_READY_SHIFT                 (2U)
/*! OUT_READY - Output text ready. */
#define AES_STAT_OUT_READY(x)                    (((uint32_t)(((uint32_t)(x)) << AES_STAT_OUT_READY_SHIFT)) & AES_STAT_OUT_READY_MASK)

#define AES_STAT_REVERSE_MASK                    (0x10U)
#define AES_STAT_REVERSE_SHIFT                   (4U)
/*! REVERSE - Reverse mode. */
#define AES_STAT_REVERSE(x)                      (((uint32_t)(((uint32_t)(x)) << AES_STAT_REVERSE_SHIFT)) & AES_STAT_REVERSE_MASK)

#define AES_STAT_KEY_VALID_MASK                  (0x20U)
#define AES_STAT_KEY_VALID_SHIFT                 (5U)
/*! KEY_VALID - Key valid. */
#define AES_STAT_KEY_VALID(x)                    (((uint32_t)(((uint32_t)(x)) << AES_STAT_KEY_VALID_SHIFT)) & AES_STAT_KEY_VALID_MASK)
/*! @} */

/*! @name CTR_INCR - Counter Increment */
/*! @{ */

#define AES_CTR_INCR_CTR_INCR_MASK               (0xFFFFFFFFU)
#define AES_CTR_INCR_CTR_INCR_SHIFT              (0U)
/*! CTR_INCR - Increment value for HOLDING register when in counter modes. */
#define AES_CTR_INCR_CTR_INCR(x)                 (((uint32_t)(((uint32_t)(x)) << AES_CTR_INCR_CTR_INCR_SHIFT)) & AES_CTR_INCR_CTR_INCR_MASK)
/*! @} */

/*! @name KEY - Bits of the AES key */
/*! @{ */

#define AES_KEY_KEY_MASK                         (0xFFFFFFFFU)
#define AES_KEY_KEY_SHIFT                        (0U)
/*! KEY - Contains the bits of the AES key. */
#define AES_KEY_KEY(x)                           (((uint32_t)(((uint32_t)(x)) << AES_KEY_KEY_SHIFT)) & AES_KEY_KEY_MASK)
/*! @} */

/*! @name INTEXT - Input text bits */
/*! @{ */

#define AES_INTEXT_INTEXT_MASK                   (0xFFFFFFFFU)
#define AES_INTEXT_INTEXT_SHIFT                  (0U)
/*! INTEXT - Contains bits of the AES key. */
#define AES_INTEXT_INTEXT(x)                     (((uint32_t)(((uint32_t)(x)) << AES_INTEXT_INTEXT_SHIFT)) & AES_INTEXT_INTEXT_MASK)
/*! @} */

/*! @name HOLDING - Holding register bits */
/*! @{ */

#define AES_HOLDING_HOLDING_MASK                 (0xFFFFFFFFU)
#define AES_HOLDING_HOLDING_SHIFT                (0U)
/*! HOLDING - Contains the first word (bits 31:0) of the 128 bit Holding value. */
#define AES_HOLDING_HOLDING(x)                   (((uint32_t)(((uint32_t)(x)) << AES_HOLDING_HOLDING_SHIFT)) & AES_HOLDING_HOLDING_MASK)
/*! @} */

/*! @name OUTTEXT - Output text bits */
/*! @{ */

#define AES_OUTTEXT_OUTTEXT_MASK                 (0xFFFFFFFFU)
#define AES_OUTTEXT_OUTTEXT_SHIFT                (0U)
/*! OUTTEXT - Contains the bits of the 128 bit Output text data. */
#define AES_OUTTEXT_OUTTEXT(x)                   (((uint32_t)(((uint32_t)(x)) << AES_OUTTEXT_OUTTEXT_SHIFT)) & AES_OUTTEXT_OUTTEXT_MASK)
/*! @} */

/*! @name GF128_Y - Y bits input of GF128 hash */
/*! @{ */

#define AES_GF128_Y_GF128_Y_MASK                 (0xFFFFFFFFU)
#define AES_GF128_Y_GF128_Y_SHIFT                (0U)
/*! GF128_Y - Contains the bits of the Y input of GF128 hash. */
#define AES_GF128_Y_GF128_Y(x)                   (((uint32_t)(((uint32_t)(x)) << AES_GF128_Y_GF128_Y_SHIFT)) & AES_GF128_Y_GF128_Y_MASK)
/*! @} */

/*! @name GF128_Z - Result bits of GF128 hash */
/*! @{ */

#define AES_GF128_Z_GF128_Z_MASK                 (0xFFFFFFFFU)
#define AES_GF128_Z_GF128_Z_SHIFT                (0U)
/*! GF128_Z - Contains bits of the result of GF128 hash. */
#define AES_GF128_Z_GF128_Z(x)                   (((uint32_t)(((uint32_t)(x)) << AES_GF128_Z_GF128_Z_SHIFT)) & AES_GF128_Z_GF128_Z_MASK)
/*! @} */

/*! @name GCM_TAG - GCM Tag bits */
/*! @{ */

#define AES_GCM_TAG_GCM_TAG_MASK                 (0xFFFFFFFFU)
#define AES_GCM_TAG_GCM_TAG_SHIFT                (0U)
/*! GCM_TAG - Contains bits of the 128 bit GCM tag. */
#define AES_GCM_TAG_GCM_TAG(x)                   (((uint32_t)(((uint32_t)(x)) << AES_GCM_TAG_GCM_TAG_SHIFT)) & AES_GCM_TAG_GCM_TAG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AES_Register_Masks */


/*!
 * @}
 */ /* end of group AES_Peripheral_Access_Layer */


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


#endif  /* PERI_AES_H_ */

