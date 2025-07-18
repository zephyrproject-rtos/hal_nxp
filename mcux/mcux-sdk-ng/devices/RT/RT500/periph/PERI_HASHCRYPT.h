/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HASHCRYPT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HASHCRYPT.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HASHCRYPT
 *
 * CMSIS Peripheral Access Layer for HASHCRYPT
 */

#if !defined(PERI_HASHCRYPT_H_)
#define PERI_HASHCRYPT_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- HASHCRYPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HASHCRYPT_Peripheral_Access_Layer HASHCRYPT Peripheral Access Layer
 * @{
 */

/** HASHCRYPT - Size of Registers Arrays */
#define HASHCRYPT_ALIAS_COUNT                     7u
#define HASHCRYPT_OUTDATA0_COUNT                  8u
#define HASHCRYPT_MASK_COUNT                      4u
#define HASHCRYPT_RELOAD_COUNT                    8u

/** HASHCRYPT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
  __IO uint32_t STATUS;                            /**< Status, offset: 0x4 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable, offset: 0x8 */
  __IO uint32_t INTENCLR;                          /**< Interrupt Clear, offset: 0xC */
  __IO uint32_t MEMCTRL;                           /**< Memory Control, offset: 0x10 */
  __IO uint32_t MEMADDR;                           /**< Memory Address, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __O  uint32_t INDATA;                            /**< Input Data, offset: 0x20 */
  __O  uint32_t ALIAS[HASHCRYPT_ALIAS_COUNT];      /**< Alias, array offset: 0x24, array step: 0x4 */
  __I  uint32_t DIGEST0[HASHCRYPT_OUTDATA0_COUNT]; /**< Digest0 n/Output Data0 n, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_1[32];
  __IO uint32_t CRYPTCFG;                          /**< Cryptographic Configuration, offset: 0x80 */
  __I  uint32_t CONFIG;                            /**< Configuration, offset: 0x84 */
       uint8_t RESERVED_2[4];
  __IO uint32_t LOCK;                              /**< Lock, offset: 0x8C */
  __O  uint32_t MASK[HASHCRYPT_MASK_COUNT];        /**< Mask, array offset: 0x90, array step: 0x4 */
  __IO uint32_t RELOAD[HASHCRYPT_RELOAD_COUNT];    /**< DIGEST/OUTDATA Reload, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_3[16];
  __O  uint32_t PRNG_SEED;                         /**< PRNG Seed, offset: 0xD0 */
       uint8_t RESERVED_4[4];
  __O  uint32_t PRNG_OUT;                          /**< PRNG Output, offset: 0xD8 */
} HASHCRYPT_Type;

/* ----------------------------------------------------------------------------
   -- HASHCRYPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HASHCRYPT_Register_Masks HASHCRYPT Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define HASHCRYPT_CTRL_MODE_MASK                 (0x7U)
#define HASHCRYPT_CTRL_MODE_SHIFT                (0U)
/*! MODE - Operational Mode
 *  0b000..Disabled
 *  0b001..SHA1 is enabled
 *  0b010..SHA2-256 is enabled
 *  0b011..
 *  0b100..AES is enabled (see also CRYPTCFG register for more controls)
 *  0b101..ICB-AES is enabled (see also CRYPTCFG register for more controls)
 *  0b110..
 *  0b111..
 */
#define HASHCRYPT_CTRL_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_MODE_SHIFT)) & HASHCRYPT_CTRL_MODE_MASK)

#define HASHCRYPT_CTRL_NEW_HASH_MASK             (0x10U)
#define HASHCRYPT_CTRL_NEW_HASH_SHIFT            (4U)
/*! NEW_HASH - New Hash Operation
 *  0b1..Starts a new Hash/Crypto and initializes the Digest/Result.
 */
#define HASHCRYPT_CTRL_NEW_HASH(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_NEW_HASH_SHIFT)) & HASHCRYPT_CTRL_NEW_HASH_MASK)

#define HASHCRYPT_CTRL_RELOAD_MASK               (0x20U)
#define HASHCRYPT_CTRL_RELOAD_SHIFT              (5U)
/*! RELOAD - Reload
 *  0b0..Disabled
 *  0b1..Allows the SHA RELOAD registers to be used.
 */
#define HASHCRYPT_CTRL_RELOAD(x)                 (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_RELOAD_SHIFT)) & HASHCRYPT_CTRL_RELOAD_MASK)

#define HASHCRYPT_CTRL_DMA_I_MASK                (0x100U)
#define HASHCRYPT_CTRL_DMA_I_SHIFT               (8U)
/*! DMA_I - DMA to Fill INDATA.
 *  0b0..DMA is not used. Processor writes the necessary words when WAITING is set (interrupts), unless AHB Master is used.
 *  0b1..DMA will push in the data.
 */
#define HASHCRYPT_CTRL_DMA_I(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_DMA_I_SHIFT)) & HASHCRYPT_CTRL_DMA_I_MASK)

#define HASHCRYPT_CTRL_DMA_O_MASK                (0x200U)
#define HASHCRYPT_CTRL_DMA_O_SHIFT               (9U)
/*! DMA_O - DMA to Drain the Digest/Output
 *  0b0..DMA is not used. Processor reads the digest/output in response to DIGEST interrupt.
 *  0b1..DMA will drain the data.
 */
#define HASHCRYPT_CTRL_DMA_O(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_DMA_O_SHIFT)) & HASHCRYPT_CTRL_DMA_O_MASK)

#define HASHCRYPT_CTRL_HASHSWPB_MASK             (0x1000U)
#define HASHCRYPT_CTRL_HASHSWPB_SHIFT            (12U)
/*! HASHSWPB - Hash Swap Bytes */
#define HASHCRYPT_CTRL_HASHSWPB(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CTRL_HASHSWPB_SHIFT)) & HASHCRYPT_CTRL_HASHSWPB_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define HASHCRYPT_STATUS_WAITING_MASK            (0x1U)
#define HASHCRYPT_STATUS_WAITING_SHIFT           (0U)
/*! WAITING - Waiting for Data
 *  0b0..Not waiting for data - may be disabled or may be busy. For cryptographic uses, this is not set if IsLast
 *       is set nor will it set until at least 1 word is read of the output.
 *  0b1..Waiting for data to be written (16 words)
 */
#define HASHCRYPT_STATUS_WAITING(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_WAITING_SHIFT)) & HASHCRYPT_STATUS_WAITING_MASK)

#define HASHCRYPT_STATUS_DIGEST_MASK             (0x2U)
#define HASHCRYPT_STATUS_DIGEST_SHIFT            (1U)
/*! DIGEST - Digest/Outdata
 *  0b0..Digest is not ready
 *  0b1..Digest is ready. Application may read it or may write more data.
 */
#define HASHCRYPT_STATUS_DIGEST(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_DIGEST_SHIFT)) & HASHCRYPT_STATUS_DIGEST_MASK)

#define HASHCRYPT_STATUS_ERROR_MASK              (0x4U)
#define HASHCRYPT_STATUS_ERROR_SHIFT             (2U)
/*! ERROR - Error
 *  0b0..No error.
 *  0b1..An error occurred since last cleared (written 1 to clear).
 */
#define HASHCRYPT_STATUS_ERROR(x)                (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_ERROR_SHIFT)) & HASHCRYPT_STATUS_ERROR_MASK)

#define HASHCRYPT_STATUS_NEEDKEY_MASK            (0x10U)
#define HASHCRYPT_STATUS_NEEDKEY_SHIFT           (4U)
/*! NEEDKEY - Need Key to be Written
 *  0b0..No Key is needed and writes will not be treated as Key
 *  0b1..Key is needed and INDATA/ALIAS will be accepted as Key. Will also set WAITING.
 */
#define HASHCRYPT_STATUS_NEEDKEY(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_NEEDKEY_SHIFT)) & HASHCRYPT_STATUS_NEEDKEY_MASK)

#define HASHCRYPT_STATUS_NEEDIV_MASK             (0x20U)
#define HASHCRYPT_STATUS_NEEDIV_SHIFT            (5U)
/*! NEEDIV - Need IV/Nonce
 *  0b0..No IV/Nonce is needed, either because written already or because not needed.
 *  0b1..IV/Nonce is needed and INDATA/ALIAS will be accepted as IV/Nonce. Will also set WAITING.
 */
#define HASHCRYPT_STATUS_NEEDIV(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_NEEDIV_SHIFT)) & HASHCRYPT_STATUS_NEEDIV_MASK)

#define HASHCRYPT_STATUS_ICBIDX_MASK             (0x3F0000U)
#define HASHCRYPT_STATUS_ICBIDX_SHIFT            (16U)
/*! ICBIDX - ICB Index Count */
#define HASHCRYPT_STATUS_ICBIDX(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_STATUS_ICBIDX_SHIFT)) & HASHCRYPT_STATUS_ICBIDX_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable */
/*! @{ */

#define HASHCRYPT_INTENSET_WAITING_MASK          (0x1U)
#define HASHCRYPT_INTENSET_WAITING_SHIFT         (0U)
/*! WAITING - Interrupt When Waiting for Data Input
 *  0b0..Interrupt not enabled when waiting
 *  0b1..Interrupt is enabled when waiting
 */
#define HASHCRYPT_INTENSET_WAITING(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENSET_WAITING_SHIFT)) & HASHCRYPT_INTENSET_WAITING_MASK)

#define HASHCRYPT_INTENSET_DIGEST_MASK           (0x2U)
#define HASHCRYPT_INTENSET_DIGEST_SHIFT          (1U)
/*! DIGEST - Digest/Outdata
 *  0b0..Interrupt not enabled when Digest is ready
 *  0b1..Interrupt is enabled when Digest is ready. Interrupt cleared by writing more data, starting a new Hash, or disabling (done).
 */
#define HASHCRYPT_INTENSET_DIGEST(x)             (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENSET_DIGEST_SHIFT)) & HASHCRYPT_INTENSET_DIGEST_MASK)

#define HASHCRYPT_INTENSET_ERROR_MASK            (0x4U)
#define HASHCRYPT_INTENSET_ERROR_SHIFT           (2U)
/*! ERROR - Interrupt on Error
 *  0b0..Interrupt not enabled on Error.
 *  0b1..Interrupt is enabled on Error (until cleared).
 */
#define HASHCRYPT_INTENSET_ERROR(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENSET_ERROR_SHIFT)) & HASHCRYPT_INTENSET_ERROR_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Clear */
/*! @{ */

#define HASHCRYPT_INTENCLR_WAITING_MASK          (0x1U)
#define HASHCRYPT_INTENCLR_WAITING_SHIFT         (0U)
/*! WAITING - Waiting */
#define HASHCRYPT_INTENCLR_WAITING(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENCLR_WAITING_SHIFT)) & HASHCRYPT_INTENCLR_WAITING_MASK)

#define HASHCRYPT_INTENCLR_DIGEST_MASK           (0x2U)
#define HASHCRYPT_INTENCLR_DIGEST_SHIFT          (1U)
/*! DIGEST - Digest */
#define HASHCRYPT_INTENCLR_DIGEST(x)             (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENCLR_DIGEST_SHIFT)) & HASHCRYPT_INTENCLR_DIGEST_MASK)

#define HASHCRYPT_INTENCLR_ERROR_MASK            (0x4U)
#define HASHCRYPT_INTENCLR_ERROR_SHIFT           (2U)
/*! ERROR - Error */
#define HASHCRYPT_INTENCLR_ERROR(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INTENCLR_ERROR_SHIFT)) & HASHCRYPT_INTENCLR_ERROR_MASK)
/*! @} */

/*! @name MEMCTRL - Memory Control */
/*! @{ */

#define HASHCRYPT_MEMCTRL_MASTER_MASK            (0x1U)
#define HASHCRYPT_MEMCTRL_MASTER_SHIFT           (0U)
/*! MASTER - Master
 *  0b0..Mastering is not used and the normal DMA or Interrupt based model is used with INDATA.
 *  0b1..Mastering is enabled and DMA and INDATA should not be used.
 */
#define HASHCRYPT_MEMCTRL_MASTER(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_MEMCTRL_MASTER_SHIFT)) & HASHCRYPT_MEMCTRL_MASTER_MASK)

#define HASHCRYPT_MEMCTRL_COUNT_MASK             (0x7FF0000U)
#define HASHCRYPT_MEMCTRL_COUNT_SHIFT            (16U)
/*! COUNT - Count
 *  0b00000000000..Done. Nothing to process
 *  0b00000000001..One 512-bit block to hash
 *  0b00000000010..Two 512-bit block to hash
 *  0b00000000011..Three 512-bit block to hash
 */
#define HASHCRYPT_MEMCTRL_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_MEMCTRL_COUNT_SHIFT)) & HASHCRYPT_MEMCTRL_COUNT_MASK)
/*! @} */

/*! @name MEMADDR - Memory Address */
/*! @{ */

#define HASHCRYPT_MEMADDR_BASE_MASK              (0xFFFFFFFFU)
#define HASHCRYPT_MEMADDR_BASE_SHIFT             (0U)
/*! BASE - Base */
#define HASHCRYPT_MEMADDR_BASE(x)                (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_MEMADDR_BASE_SHIFT)) & HASHCRYPT_MEMADDR_BASE_MASK)
/*! @} */

/*! @name INDATA - Input Data */
/*! @{ */

#define HASHCRYPT_INDATA_DATA_MASK               (0xFFFFFFFFU)
#define HASHCRYPT_INDATA_DATA_SHIFT              (0U)
/*! DATA - Data */
#define HASHCRYPT_INDATA_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_INDATA_DATA_SHIFT)) & HASHCRYPT_INDATA_DATA_MASK)
/*! @} */

/*! @name ALIAS - Alias */
/*! @{ */

#define HASHCRYPT_ALIAS_DATA_MASK                (0xFFFFFFFFU)
#define HASHCRYPT_ALIAS_DATA_SHIFT               (0U)
/*! DATA - Data */
#define HASHCRYPT_ALIAS_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_ALIAS_DATA_SHIFT)) & HASHCRYPT_ALIAS_DATA_MASK)
/*! @} */

/*! @name DIGEST0 - Digest0 n/Output Data0 n */
/*! @{ */

#define HASHCRYPT_DIGEST0_DIGEST_MASK            (0xFFFFFFFFU)
#define HASHCRYPT_DIGEST0_DIGEST_SHIFT           (0U)
/*! DIGEST - Digest */
#define HASHCRYPT_DIGEST0_DIGEST(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_DIGEST0_DIGEST_SHIFT)) & HASHCRYPT_DIGEST0_DIGEST_MASK)
/*! @} */

/* The count of HASHCRYPT_DIGEST0 */
#define HASHCRYPT_DIGEST0_COUNT                  (8U)

/*! @name CRYPTCFG - Cryptographic Configuration */
/*! @{ */

#define HASHCRYPT_CRYPTCFG_MSW1ST_OUT_MASK       (0x1U)
#define HASHCRYPT_CRYPTCFG_MSW1ST_OUT_SHIFT      (0U)
/*! MSW1ST_OUT - Most Significant Word 1st Out */
#define HASHCRYPT_CRYPTCFG_MSW1ST_OUT(x)         (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_MSW1ST_OUT_SHIFT)) & HASHCRYPT_CRYPTCFG_MSW1ST_OUT_MASK)

#define HASHCRYPT_CRYPTCFG_SWAPKEY_MASK          (0x2U)
#define HASHCRYPT_CRYPTCFG_SWAPKEY_SHIFT         (1U)
/*! SWAPKEY - Swap Key */
#define HASHCRYPT_CRYPTCFG_SWAPKEY(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_SWAPKEY_SHIFT)) & HASHCRYPT_CRYPTCFG_SWAPKEY_MASK)

#define HASHCRYPT_CRYPTCFG_SWAPDAT_MASK          (0x4U)
#define HASHCRYPT_CRYPTCFG_SWAPDAT_SHIFT         (2U)
/*! SWAPDAT - Swap Data/IV Inputs */
#define HASHCRYPT_CRYPTCFG_SWAPDAT(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_SWAPDAT_SHIFT)) & HASHCRYPT_CRYPTCFG_SWAPDAT_MASK)

#define HASHCRYPT_CRYPTCFG_MSW1ST_MASK           (0x8U)
#define HASHCRYPT_CRYPTCFG_MSW1ST_SHIFT          (3U)
/*! MSW1ST - Most Significant Word 1st Load */
#define HASHCRYPT_CRYPTCFG_MSW1ST(x)             (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_MSW1ST_SHIFT)) & HASHCRYPT_CRYPTCFG_MSW1ST_MASK)

#define HASHCRYPT_CRYPTCFG_AESMODE_MASK          (0x30U)
#define HASHCRYPT_CRYPTCFG_AESMODE_SHIFT         (4U)
/*! AESMODE - AES Cipher Mode
 *  0b00..ECB - used as is
 *  0b01..CBC mode (see details on IV/nonce)
 *  0b10..CTR mode (see details on IV/nonce). See also AESCTRPOS.
 *  0b11..Reserved
 */
#define HASHCRYPT_CRYPTCFG_AESMODE(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_AESMODE_SHIFT)) & HASHCRYPT_CRYPTCFG_AESMODE_MASK)

#define HASHCRYPT_CRYPTCFG_AESDECRYPT_MASK       (0x40U)
#define HASHCRYPT_CRYPTCFG_AESDECRYPT_SHIFT      (6U)
/*! AESDECRYPT - AES Decrypt
 *  0b0..Encrypt
 *  0b1..Decrypt
 */
#define HASHCRYPT_CRYPTCFG_AESDECRYPT(x)         (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_AESDECRYPT_SHIFT)) & HASHCRYPT_CRYPTCFG_AESDECRYPT_MASK)

#define HASHCRYPT_CRYPTCFG_AESSECRET_MASK        (0x80U)
#define HASHCRYPT_CRYPTCFG_AESSECRET_SHIFT       (7U)
/*! AESSECRET - AES Secret
 *  0b0..User key provided in normal way
 *  0b1..Secret key provided in hidden way by HW
 */
#define HASHCRYPT_CRYPTCFG_AESSECRET(x)          (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_AESSECRET_SHIFT)) & HASHCRYPT_CRYPTCFG_AESSECRET_MASK)

#define HASHCRYPT_CRYPTCFG_AESKEYSZ_MASK         (0x300U)
#define HASHCRYPT_CRYPTCFG_AESKEYSZ_SHIFT        (8U)
/*! AESKEYSZ - AES Key Size
 *  0b00..128 bit key
 *  0b01..192 bit key
 *  0b10..256 bit key
 *  0b11..Reserved
 */
#define HASHCRYPT_CRYPTCFG_AESKEYSZ(x)           (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_AESKEYSZ_SHIFT)) & HASHCRYPT_CRYPTCFG_AESKEYSZ_MASK)

#define HASHCRYPT_CRYPTCFG_AESCTRPOS_MASK        (0x1C00U)
#define HASHCRYPT_CRYPTCFG_AESCTRPOS_SHIFT       (10U)
/*! AESCTRPOS - AES CTR Position */
#define HASHCRYPT_CRYPTCFG_AESCTRPOS(x)          (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_AESCTRPOS_SHIFT)) & HASHCRYPT_CRYPTCFG_AESCTRPOS_MASK)

#define HASHCRYPT_CRYPTCFG_STREAMLAST_MASK       (0x10000U)
#define HASHCRYPT_CRYPTCFG_STREAMLAST_SHIFT      (16U)
/*! STREAMLAST - Stream Last */
#define HASHCRYPT_CRYPTCFG_STREAMLAST(x)         (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_STREAMLAST_SHIFT)) & HASHCRYPT_CRYPTCFG_STREAMLAST_MASK)

#define HASHCRYPT_CRYPTCFG_ICBSZ_MASK            (0x300000U)
#define HASHCRYPT_CRYPTCFG_ICBSZ_SHIFT           (20U)
/*! ICBSZ - ICB Size
 *  0b00..32 bits of the IV/ctr are used (from 127:96)
 *  0b01..64 bits of the IV/ctr are used (from 127:64)
 *  0b10..96 bits of the IV/ctr are used (from 127:32)
 *  0b11..All 128 bits of the IV/ctr are used
 */
#define HASHCRYPT_CRYPTCFG_ICBSZ(x)              (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_ICBSZ_SHIFT)) & HASHCRYPT_CRYPTCFG_ICBSZ_MASK)

#define HASHCRYPT_CRYPTCFG_ICBSTRM_MASK          (0xC00000U)
#define HASHCRYPT_CRYPTCFG_ICBSTRM_SHIFT         (22U)
/*! ICBSTRM - ICB Stream Size
 *  0b00..8 blocks
 *  0b01..16 blocks
 *  0b10..32 blocks
 *  0b11..64 blocks
 */
#define HASHCRYPT_CRYPTCFG_ICBSTRM(x)            (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CRYPTCFG_ICBSTRM_SHIFT)) & HASHCRYPT_CRYPTCFG_ICBSTRM_MASK)
/*! @} */

/*! @name CONFIG - Configuration */
/*! @{ */

#define HASHCRYPT_CONFIG_DUAL_MASK               (0x1U)
#define HASHCRYPT_CONFIG_DUAL_SHIFT              (0U)
/*! DUAL - Reads 1 if 2 x 512 bit buffers, 0 if only 1 x 512 bit */
#define HASHCRYPT_CONFIG_DUAL(x)                 (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_DUAL_SHIFT)) & HASHCRYPT_CONFIG_DUAL_MASK)

#define HASHCRYPT_CONFIG_DMA_MASK                (0x2U)
#define HASHCRYPT_CONFIG_DMA_SHIFT               (1U)
/*! DMA - Reads 1 if DMA is connected */
#define HASHCRYPT_CONFIG_DMA(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_DMA_SHIFT)) & HASHCRYPT_CONFIG_DMA_MASK)

#define HASHCRYPT_CONFIG_AHB_MASK                (0x8U)
#define HASHCRYPT_CONFIG_AHB_SHIFT               (3U)
/*! AHB - Reads 1 if AHB Master is enabled */
#define HASHCRYPT_CONFIG_AHB(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_AHB_SHIFT)) & HASHCRYPT_CONFIG_AHB_MASK)

#define HASHCRYPT_CONFIG_AES_MASK                (0x40U)
#define HASHCRYPT_CONFIG_AES_SHIFT               (6U)
/*! AES - Reads 1 if AES 128 is included */
#define HASHCRYPT_CONFIG_AES(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_AES_SHIFT)) & HASHCRYPT_CONFIG_AES_MASK)

#define HASHCRYPT_CONFIG_AESKEY_MASK             (0x80U)
#define HASHCRYPT_CONFIG_AESKEY_SHIFT            (7U)
/*! AESKEY - Reads 1 if AES 192 and 256 also included */
#define HASHCRYPT_CONFIG_AESKEY(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_AESKEY_SHIFT)) & HASHCRYPT_CONFIG_AESKEY_MASK)

#define HASHCRYPT_CONFIG_SECRET_MASK             (0x100U)
#define HASHCRYPT_CONFIG_SECRET_SHIFT            (8U)
/*! SECRET - Reads 1 if AES Secret key is available */
#define HASHCRYPT_CONFIG_SECRET(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_SECRET_SHIFT)) & HASHCRYPT_CONFIG_SECRET_MASK)

#define HASHCRYPT_CONFIG_ICB_MASK                (0x800U)
#define HASHCRYPT_CONFIG_ICB_SHIFT               (11U)
/*! ICB - ICB */
#define HASHCRYPT_CONFIG_ICB(x)                  (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_CONFIG_ICB_SHIFT)) & HASHCRYPT_CONFIG_ICB_MASK)
/*! @} */

/*! @name LOCK - Lock */
/*! @{ */

#define HASHCRYPT_LOCK_SECLOCK_MASK              (0x3U)
#define HASHCRYPT_LOCK_SECLOCK_SHIFT             (0U)
/*! SECLOCK - Secure Lock
 *  0b00..Unlocks, so block is open to all. But, AHB Master will only issue non-secure requests.
 *  0b01..Locks to the current security level. AHB Master will issue requests at this level.
 */
#define HASHCRYPT_LOCK_SECLOCK(x)                (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_LOCK_SECLOCK_SHIFT)) & HASHCRYPT_LOCK_SECLOCK_MASK)

#define HASHCRYPT_LOCK_PATTERN_MASK              (0xFFF0U)
#define HASHCRYPT_LOCK_PATTERN_SHIFT             (4U)
/*! PATTERN - Must write 0xA75 to change lock state. A75:Pattern needed to change bits 1:0 */
#define HASHCRYPT_LOCK_PATTERN(x)                (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_LOCK_PATTERN_SHIFT)) & HASHCRYPT_LOCK_PATTERN_MASK)
/*! @} */

/*! @name MASK - Mask */
/*! @{ */

#define HASHCRYPT_MASK_MASK_MASK                 (0xFFFFFFFFU)
#define HASHCRYPT_MASK_MASK_SHIFT                (0U)
/*! MASK - A random word. */
#define HASHCRYPT_MASK_MASK(x)                   (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_MASK_MASK_SHIFT)) & HASHCRYPT_MASK_MASK_MASK)
/*! @} */

/*! @name RELOAD - DIGEST/OUTDATA Reload */
/*! @{ */

#define HASHCRYPT_RELOAD_DIGEST_MASK             (0xFFFFFFFFU)
#define HASHCRYPT_RELOAD_DIGEST_SHIFT            (0U)
/*! DIGEST - SHA Digest word to reload. */
#define HASHCRYPT_RELOAD_DIGEST(x)               (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_RELOAD_DIGEST_SHIFT)) & HASHCRYPT_RELOAD_DIGEST_MASK)
/*! @} */

/*! @name PRNG_SEED - PRNG Seed */
/*! @{ */

#define HASHCRYPT_PRNG_SEED_PRNG_SEED_MASK       (0xFFFFFFFFU)
#define HASHCRYPT_PRNG_SEED_PRNG_SEED_SHIFT      (0U)
/*! PRNG_SEED - SHA Digest word to reload. */
#define HASHCRYPT_PRNG_SEED_PRNG_SEED(x)         (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_PRNG_SEED_PRNG_SEED_SHIFT)) & HASHCRYPT_PRNG_SEED_PRNG_SEED_MASK)
/*! @} */

/*! @name PRNG_OUT - PRNG Output */
/*! @{ */

#define HASHCRYPT_PRNG_OUT_PRNG_OUT_R_MASK       (0xFFFFFFFFU)
#define HASHCRYPT_PRNG_OUT_PRNG_OUT_R_SHIFT      (0U)
/*! PRNG_OUT_R - SHA Digest word to reload. */
#define HASHCRYPT_PRNG_OUT_PRNG_OUT_R(x)         (((uint32_t)(((uint32_t)(x)) << HASHCRYPT_PRNG_OUT_PRNG_OUT_R_SHIFT)) & HASHCRYPT_PRNG_OUT_PRNG_OUT_R_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HASHCRYPT_Register_Masks */


/*!
 * @}
 */ /* end of group HASHCRYPT_Peripheral_Access_Layer */


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


#endif  /* PERI_HASHCRYPT_H_ */

