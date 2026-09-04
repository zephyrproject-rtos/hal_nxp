/*--------------------------------------------------------------------------*/
/* Copyright 2021-2026 NXP                                                  */
/*                                                                          */
/* SPDX-License-Identifier: BSD-3-Clause                                    */
/*                                                                          */
/* Redistribution and use in source and binary forms, with or without       */
/* modification, are permitted provided that the following conditions are   */
/* met:                                                                     */
/*                                                                          */
/* 1. Redistributions of source code must retain the above copyright        */
/*    notice, this list of conditions and the following disclaimer.         */
/*                                                                          */
/* 2. Redistributions in binary form must reproduce the above copyright     */
/*    notice, this list of conditions and the following disclaimer in the   */
/*    documentation and/or other materials provided with the distribution.  */
/*                                                                          */
/* 3. Neither the name of the copyright holder nor the names of its         */
/*    contributors may be used to endorse or promote products derived from  */
/*    this software without specific prior written permission.              */
/*                                                                          */
/* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  */
/* IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED    */
/* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A          */
/* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT       */
/* HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,   */
/* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED */
/* TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR   */
/* PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF   */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING     */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS       */
/* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.             */
/*--------------------------------------------------------------------------*/

#ifndef MCUXCLSGI_DRV_H_
#define MCUXCLSGI_DRV_H_

#include <mcuxCsslFlowProtection.h>
#include <stdbool.h>
#include <mcuxClKey_Constants.h>
#include <mcuxClSgi_Constants.h>
#include <mcuxClSgi_Types.h>
#include <internal/mcuxClSgi_Sfr_RegBank.h>
#include <internal/mcuxClSgi_Sfr_Ctrl.h>
#include <internal/mcuxClSgi_Sfr_Sec.h>
#include <internal/mcuxClSgi_Sfr_Status.h>
#include <internal/mcuxClSession_Internal.h>


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************
 * Defines to abstract Sfr definitions
*****************************************************/

/* Number of key register banks */
#define MCUXCLSGI_DRV_KEY_BANK_COUNT     (MCUXCLSGI_SFR_KEY_CNT / 4U)

/** Datout update handling */
#define MCUXCLSGI_DRV_CTRL_DATOUT_RES_END_UP     (MCUXCLSGI_SFR_CTRL_DATOUT_RES_END_UP)

#define MCUXCLSGI_DRV_CTRL_END_UP         (MCUXCLSGI_SFR_CTRL_END_UP)
#define MCUXCLSGI_DRV_CTRL_START_UP       (MCUXCLSGI_SFR_CTRL_START_UP)
#define MCUXCLSGI_DRV_CTRL_NO_UP          (MCUXCLSGI_SFR_CTRL_NO_UP)
#define MCUXCLSGI_DRV_CTRL_TRIGGER_UP     (MCUXCLSGI_SFR_CTRL_TRIGGER_UP)

#define MCUXCLSGI_DRV_CTRL_INVALID  (MCUXCLSGI_SFR_CTRL_INVALID)
#define MCUXCLSGI_DRV_CTRL_GFMUL    (MCUXCLSGI_SFR_CTRL_GFMUL)
#define MCUXCLSGI_DRV_CTRL_AES128   (MCUXCLSGI_SFR_CTRL_AES128)
#define MCUXCLSGI_DRV_CTRL_AES192   (MCUXCLSGI_SFR_CTRL_AES192)
#define MCUXCLSGI_DRV_CTRL_AES256   (MCUXCLSGI_SFR_CTRL_AES256)
#define MCUXCLSGI_DRV_CTRL_CMAC     (MCUXCLSGI_SFR_CTRL_CMAC)

/** data input offset*/
#define MCUXCLSGI_DRV_DATIN0_OFFSET    (MCUXCLSGI_SFR_DATIN0_OFFSET)
#define MCUXCLSGI_DRV_DATIN1_OFFSET    (MCUXCLSGI_SFR_DATIN1_OFFSET)
#define MCUXCLSGI_DRV_DATIN2_OFFSET    (MCUXCLSGI_SFR_DATIN2_OFFSET)
#define MCUXCLSGI_DRV_DATIN3_OFFSET    (MCUXCLSGI_SFR_DATIN3_OFFSET)

/** SHA FIFO offset */
#define MCUXCLSGI_DRV_SHAFIFO_OFFSET   (MCUXCLSGI_SFR_SHAFIFO_OFFSET)

/** data output offset */
#define MCUXCLSGI_DRV_DATOUT_OFFSET    (MCUXCLSGI_SFR_DATOUT_OFFSET)

/** key offset */
#define MCUXCLSGI_DRV_KEY0_OFFSET    (MCUXCLSGI_SFR_KEY0_OFFSET)
#define MCUXCLSGI_DRV_KEY1_OFFSET    (MCUXCLSGI_SFR_KEY1_OFFSET)
#define MCUXCLSGI_DRV_KEY2_OFFSET    (MCUXCLSGI_SFR_KEY2_OFFSET)
#define MCUXCLSGI_DRV_KEY3_OFFSET    (MCUXCLSGI_SFR_KEY3_OFFSET)
#define MCUXCLSGI_DRV_KEY4_OFFSET    (MCUXCLSGI_SFR_KEY4_OFFSET)
#define MCUXCLSGI_DRV_KEY5_OFFSET    (MCUXCLSGI_SFR_KEY5_OFFSET)
#define MCUXCLSGI_DRV_KEY6_OFFSET    (MCUXCLSGI_SFR_KEY6_OFFSET)
#define MCUXCLSGI_DRV_KEY7_OFFSET    (MCUXCLSGI_SFR_KEY7_OFFSET)
#ifdef SGI_HAS_KEY_WRAP_UNWRAP
#define MCUXCLSGI_DRV_KEY_OFFSET_UNWRAP_DEST (MCUXCLSGI_SFR_KEY_OFFSET_UNWRAP_DEST)
#endif /* SGI_HAS_KEY_WRAP_UNWRAP */

/** key index */
#define MCUXCLSGI_DRV_KEY0_INDEX    (MCUXCLSGI_SFR_KEY0_INDEX)
#define MCUXCLSGI_DRV_KEY1_INDEX    (MCUXCLSGI_SFR_KEY1_INDEX)
#define MCUXCLSGI_DRV_KEY2_INDEX    (MCUXCLSGI_SFR_KEY2_INDEX)
#define MCUXCLSGI_DRV_KEY3_INDEX    (MCUXCLSGI_SFR_KEY3_INDEX)
#define MCUXCLSGI_DRV_KEY4_INDEX    (MCUXCLSGI_SFR_KEY0_INDEX)
#define MCUXCLSGI_DRV_KEY5_INDEX    (MCUXCLSGI_SFR_KEY1_INDEX)
#define MCUXCLSGI_DRV_KEY6_INDEX    (MCUXCLSGI_SFR_KEY2_INDEX)
#define MCUXCLSGI_DRV_KEY7_INDEX    (MCUXCLSGI_SFR_KEY3_INDEX)
#ifdef SGI_HAS_KEY_WRAP_UNWRAP
#define MCUXCLSGI_DRV_KEY_INDEX_UNWRAP_DEST (MCUXCLSGI_SFR_KEY_INDEX_UNWRAP_DEST)
#endif /* SGI_HAS_KEY_WRAP_UNWRAP */

/** Input selection and pre-processing handling */
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN0            (MCUXCLSGI_SFR_CTRL_INSEL_DATIN0)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN1            (MCUXCLSGI_SFR_CTRL_INSEL_DATIN1)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN2            (MCUXCLSGI_SFR_CTRL_INSEL_DATIN2)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN3            (MCUXCLSGI_SFR_CTRL_INSEL_DATIN3)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN0_XOR_DATOUT (MCUXCLSGI_SFR_CTRL_INSEL_DATIN0_XOR_DATOUT)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN1_XOR_DATOUT (MCUXCLSGI_SFR_CTRL_INSEL_DATIN1_XOR_DATOUT)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN2_XOR_DATOUT (MCUXCLSGI_SFR_CTRL_INSEL_DATIN2_XOR_DATOUT)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATIN3_XOR_DATOUT (MCUXCLSGI_SFR_CTRL_INSEL_DATIN3_XOR_DATOUT)
#define MCUXCLSGI_DRV_CTRL_INSEL_DATOUT            (MCUXCLSGI_SFR_CTRL_INSEL_DATOUT)
#define MCUXCLSGI_DRV_CTRL_INSEL_INDEX(index)      (MCUXCLSGI_SFR_CTRL_INSEL_INDEX(index))

#define MCUXCLSGI_DRV_CTRL_INSEL_XOR_DATOUT_NUMBER_TO_CTRL(datinNumber)    (MCUXCLSGI_SFR_CTRL_INSEL_XOR_DATOUT_NUMBER_TO_CTRL(datinNumber))  ///< Get the correct DATIN INSEL XOR_DATOUT CTRL from the given datinNumber (0:MCUXCLSGI_SFR_CTRL_INSEL_DATIN0_XOR_DATOUT, 1:MCUXCLSGI_SFR_CTRL_INSEL_DATIN1_XOR_DATOUT,..)

/** Output selection and post-processing handling */
#define MCUXCLSGI_DRV_CTRL_OUTSEL_RES               (MCUXCLSGI_SFR_CTRL_OUTSEL_RES)
#define MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN0    (MCUXCLSGI_SFR_CTRL_OUTSEL_RES_XOR_DATIN0)
#define MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN1    (MCUXCLSGI_SFR_CTRL_OUTSEL_RES_XOR_DATIN1)
#define MCUXCLSGI_DRV_CTRL_OUTSEL_RES_XOR_DATIN2    (MCUXCLSGI_SFR_CTRL_OUTSEL_RES_XOR_DATIN2)
#define MCUXCLSGI_DRV_CTRL_OUTSEL_RES_INDEX(index)  (MCUXCLSGI_SFR_CTRL_OUTSEL_RES_INDEX(index))

/** Encryption/Decryption mode selection */
#define MCUXCLSGI_DRV_CTRL_ENC                   (MCUXCLSGI_SFR_CTRL_ENC)
#define MCUXCLSGI_DRV_CTRL_DEC                   (MCUXCLSGI_SFR_CTRL_DEC)

#ifdef SGI_HAS_KEY_WRAP_UNWRAP
/** Key Wrap/Unwrap mode selection */
#define MCUXCLSGI_DRV_CTRL_KEY_WRAP              (MCUXCLSGI_SFR_CTRL_ENC)
#define MCUXCLSGI_DRV_CTRL_KEY_UNWRAP            (MCUXCLSGI_SFR_CTRL_DEC)
#endif /* SGI_HAS_KEY_WRAP_UNWRAP */

#define MCUXCLSGI_DRV_CTRL_AES_EN                (MCUXCLSGI_SFR_CTRL_AES_EN)

/** Selection of input key register for SGI CTRL */
#define MCUXCLSGI_DRV_CTRL_INKEYSEL(keyIndex)    (MCUXCLSGI_SFR_CTRL_INKEYSEL(keyIndex))

/** Selection of input key KEY0 for SGI CTRL */
#define MCUXCLSGI_DRV_CTRL_INKEYSEL_KEY0         (MCUXCLSGI_SFR_CTRL_INKEYSEL_KEY0)

/** AES no decryption key schedule */
#define MCUXCLSGI_DRV_CTRL_AES_NO_KL             (MCUXCLSGI_SFR_CTRL_AES_NO_KL)



/****************************************************************
 * Static inline functions
 ****************************************************************/

/**
 * @brief Translate an SGI DATIN index to a DATIN OFFSET.
 *
 * @param  datinIndex   DATIN index between 0..3 (DATIN0: 0, DATIN1: 1, DATIN2: 2, DATIN3: 3)
 *
 * @return The DATIN offset, an OFFET between MCUXCLSGI_DRV_DATIN0_OFFSET..MCUXCLSGI_DRV_DATIN3_OFFSET
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_datinIndexToOffset)
static inline uint32_t mcuxClSgi_Drv_datinIndexToOffset(uint32_t datinIndex)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(datinIndex, 0U, 3U, 0U);
  return MCUXCLSGI_SFR_DATIN_INDEX_TO_OFFSET(datinIndex);
}

/**
 * @brief Translate an SGI keyslot number to a key index.
 *
 * @param  slot   Key slot (0,1,..,7) from a key handle.
 *
 * @return The key index, an INDEX between MCUXCLSGI_DRV_KEY0_INDEX..MCUXCLSGI_DRV_KEY7_INDEX
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_keySlotToIndex)
static inline uint32_t mcuxClSgi_Drv_keySlotToIndex(uint32_t keySlot)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keySlot, 0U, 7U, 0U);
  return MCUXCLSGI_SFR_KEY_SLOT_TO_INDEX(keySlot);
}

/**
 * @brief Translate an SGI keyslot number to a key offset with respect to the SGI base.
 *
 * @param  slot   Key slot (0,1,..,7) from a key handle.
 *
 * @return The key offset, an OFFSET between MCUXCLSGI_DRV_KEY0_OFFSET..MCUXCLSGI_DRV_KEY7_OFFSET
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_keySlotToOffset)
static inline uint32_t mcuxClSgi_Drv_keySlotToOffset(uint32_t keySlot)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keySlot, 0U, 7U, 0U);
  return MCUXCLSGI_SFR_KEY_SLOT_TO_OFFSET(keySlot);
}

/**
 * @brief Translate an SGI key offset to a key slot number.
 *
 * @param  keyOffset   Key offset. Can be any offset between MCUXCLSGI_DRV_KEY0_OFFSET..MCUXCLSGI_DRV_KEY7_OFFSET.
 *
 * @return The key slot, a slot number between 0..7
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_keyOffsetToSlot)
static inline uint32_t mcuxClSgi_Drv_keyOffsetToSlot(uint32_t keyOffset)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyOffset, MCUXCLSGI_DRV_KEY0_OFFSET, MCUXCLSGI_DRV_KEY7_OFFSET, 0U);
  return MCUXCLSGI_SFR_KEY_OFFSET_TO_SLOT(keyOffset);
}

/**
 * @brief Translate an SGI key offset to a key index.
 *
 * @param  keyOffset   Key offset. Can be any offset between MCUXCLSGI_DRV_KEY0_OFFSET..MCUXCLSGI_DRV_KEY7_OFFSET.
 *
 * @return The key index, an INDEX between MCUXCLSGI_DRV_KEY0_INDEX..MCUXCLSGI_DRV_KEY7_INDEX
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_keyOffsetToIndex)
static inline uint32_t mcuxClSgi_Drv_keyOffsetToIndex(uint32_t keyOffset)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(keyOffset, MCUXCLSGI_DRV_KEY0_OFFSET, MCUXCLSGI_DRV_KEY7_OFFSET, 0U);
  return MCUXCLSGI_SFR_KEY_OFFSET_TO_INDEX(keyOffset);
}

/**
 * @brief Translate an SGI SFR address to an offset (with respect to the SGI base).
 *
 * @param  sfrAddress   Address of the SGI SFR.
 *
 * @return The offset of the SFR
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_addressToOffset)
static inline uint32_t mcuxClSgi_Drv_addressToOffset(uint32_t* sfrAddress)
{
  return mcuxClSgi_Sfr_getOffset(sfrAddress);
}

#ifdef SGI_HAS_WRITEONLY_KEYS
/**
 * @brief Check if a key offset is write-only.
 *
 * @param  offset   Offset with respect to the SGI base. Can be any of MCUXCLSGI_DRV_KEY*_OFFSET_*.
 *
 * @return bool
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_isWriteOnlyKeyOffset)
static inline bool mcuxClSgi_Drv_isWriteOnlyKeyOffset(uint32_t offset)
{
  MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, MCUXCLSGI_SFR_KEY0_OFFSET, MCUXCLSGI_SFR_KEY7_OFFSET, true);
  return mcuxClSgi_Sfr_isWriteOnlyKey(MCUXCLSGI_SFR_KEY_OFFSET_TO_INDEX(offset));
}

/**
 * @brief Check if a key slot is write-only.
 *
 * @param  slot   Key slot from a key handle.
 *
 * @return bool
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_isWriteOnlyKeySlot)
static inline bool mcuxClSgi_Drv_isWriteOnlyKeySlot(uint32_t slot)
{
  return mcuxClSgi_Sfr_isWriteOnlyKey(mcuxClSgi_Drv_keySlotToIndex(slot));
}
#else
/**
 * @brief Check if a key offset is write-only.
 *
 * @param  offset   Offset with respect to the SGI base. Can be any of MCUXCLSGI_DRV_KEY*_OFFSET_*.
 *
 * @return bool
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_isWriteOnlyKeyOffset)
static inline bool mcuxClSgi_Drv_isWriteOnlyKeyOffset(uint32_t offset)
{
  return false;
}

/**
 * @brief Check if a key slot is write-only.
 *
 * @param  slot   Key slot from a key handle.
 *
 * @return bool
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_isWriteOnlyKeySlot)
static inline bool mcuxClSgi_Drv_isWriteOnlyKeySlot(uint32_t slot)
{
  return false;
}

#endif /* SGI_HAS_WRITEONLY_KEYS */

/**
 * @brief Get the address of an SGI SFR based on its offset
 *
 * @param  offset   The offset of the SGI SFR with respect to the SGI base.
 *
 * @return The address of the SFR
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_getAddr)
static inline uint32_t * mcuxClSgi_Drv_getAddr(uint32_t offset)
{
  return mcuxClSgi_Sfr_getAddr(offset);
}


/*****************************************************
 * Functions related to controlling an SGI operation
 *****************************************************/

/**
 * @brief Waits until SGI operation finished
 *
 * This function does not need FP, the SGI will either throw an error
 * or block read/write accesses until it is not busy anymore.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Drv_wait)
static inline void mcuxClSgi_Drv_wait(void)
{
  while(MCUXCLSGI_SFR_STATUS_BUSY(mcuxClSgi_Sfr_readStatus())) { /*nothing*/ }
}

/**
 * @brief Initializes SGI
 *
 * Initializes SGI by setting
 * - CTRL to 0
 * - CTRL2 to the given mode
 *
 * @param[in]  mode   Ctrl2 Configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_init)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_init(uint32_t mode);

/**
 * @brief Closes SGI
 *
 * Closes SGI after usage:
 * Returns MCUXCLSGI_STATUS_ERROR in case an error has occured,
 * otherwise returns MCUXCLSGI_STATUS_OK.
 *
 * @param[in]    session          Handle for the current CL session
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_close)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_close(mcuxClSession_Handle_t session);

#ifdef SGI_HAS_AES_AUTO_MODE
/**
 * @brief Writes SGI AUTO mode settings.
 *
 * Configures the SGI AUTO mode feature by writing to the AUTO_MODE register:
 *    enable, command (Ecb, Cbc, Ctr 32/64/96/128, Cmac), counter_incr.
 *
 * @param[in]  autoModeConfig  Configuration of the AUTO mode control
 */
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_ECB      (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_ECB) ///< Configures AUTO mode in ECB
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CTR_32   (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CTR | MCUXCLSGI_SFR_AUTO_MODE_INCR_32_BIT) ///< Configures AUTO mode in CTR for a 32-bit counter
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CTR_64   (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CTR | MCUXCLSGI_SFR_AUTO_MODE_INCR_64_BIT) ///< Configures AUTO mode in CTR for a 64-bit counter
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CTR_96   (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CTR | MCUXCLSGI_SFR_AUTO_MODE_INCR_96_BIT) ///< Configures AUTO mode in CTR for a 96-bit counter
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CTR_128  (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CTR | MCUXCLSGI_SFR_AUTO_MODE_INCR_128_BIT) ///< Configures AUTO mode in CTR for a 128-bit counter
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CBC      (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CBC) ///< Configures AUTO mode in CBC
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_CMAC     (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_CMAC) ///< Configures AUTO mode in CMAC. Note that this mode only handles the CBC-MAC part of the CMAC.
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_128  (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_KEYWRAP_128) ///< Configures AUTO mode in key wrap (128-bit key data) mode
#define MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_256  (MCUXCLSGI_SFR_AUTO_MODE_EN | MCUXCLSGI_SFR_AUTO_MODE_KEYWRAP_256) ///< Configures AUTO mode in key wrap (256-bit key data) mode
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_configureAutoMode)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_configureAutoMode(uint32_t autoModeConfig);

/**
 * @brief Resets the SGI AUTO mode settings to 0.
 *
 * This can be used to finish a key wrap/unwrap operation.
 *
 * @pre The SGI busy must be de-asserted before resetting this register.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_resetAutoMode)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_resetAutoMode(void);

/**
 * @brief Stops a Cipher/CMAC operation in AUTO mode, and disables AUTO mode.
 *
 * Stops a Cipher (ECB/CBC/CTR) or CMAC operation, when SGI is configured to AUTO mode,
 * and disables AUTO mode.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_stopAndDisableAutoMode)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_stopAndDisableAutoMode(void);

/**
 * @brief Enable Input and Output DMA Handshakes for AUTO mode
 *
 * Updates the AUTO mode DMA CTRL register to enable Input and Output FIFO.
 * This will enable the DMA handshakes for SGI input and output signals, notifying
 * the DMA channels once the SGI is ready to accept new input data and ready to
 * provide new output data.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableDmaHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_enableDmaHandshakes(void);

/**
 * @brief Disable Input and OUtput DMA Handshake for AUTO mode
 *
 * Updates the AUTO mode DMA CTRL register to disable all handshakes.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableDmaHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_disableDmaHandshakes(void);

/**
 * @brief Enable Input DMA Handshake for AUTO mode
 *
 * Updates the AUTO mode DMA CTRL register to enable Input FIFO.
 * This will enable the DMA handshake for SGI input signals, notifying
 * the DMA input channel once the SGI is ready to accept new input data.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableInputDmaHandshake)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_enableInputDmaHandshake(void);

#endif /* SGI_HAS_AES_AUTO_MODE */

/**
 * @brief Starts an SGI operation
 *
 * Starts an SGI operation:
 * mode(Aes,Des...), Enc/Dec, KeySize, inXor,outXor, KeySel, DatinSel
 * by configuring the CTRL register
 *
 * @param[in]  operation   Configuration of operation to be executed
 */
#define MCUXCLSGI_DRV_START_SHA2   (MCUXCLSGI_SFR_CTRL_SHA2 | MCUXCLSGI_SFR_CTRL_DATOUT_RES_END_UP)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_start)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_start(uint32_t operation);

/**
 * @brief Stops a SHA-2 operation in AUTO mode
 *
 * Stops a SHA-2 operation, when SGI is configured to AUTO mode
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_stopSha2)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_stopSha2(void);

/**
 * @brief Gets control value (CTRL)
 *
 * @return Return CTRL register configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getCtrl)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_getCtrl(void);

/**
 * @brief Gets control value (CTRL2)
 *
 * @return Return CTRL2 register configuration
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getCtrl2)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_getCtrl2(void);

/**
 * @brief Sets control value (CTRL)
 *
 * @param[in]  control   Configuration, which CTRL shall be set to
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_setCtrl)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_setCtrl(uint32_t control);

/**
 * @brief Sets control value (CTRL2)
 *
 * @param[in]  control   Configuration, which CTRL2 shall be set to
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_setCtrl2)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_setCtrl2(uint32_t control);

/**
 * @brief Configures SHA-2 operation
 *
 * Configures SHA-2 operation, setting SHA2_CTRL value to control.
 *
 * @param[in]  control   Configuration, which SHA2_CTRL shall be set to
 */
#define MCUXCLSGI_DRV_STATE_SIZE_SHA2_224 (32u)
#define MCUXCLSGI_DRV_STATE_SIZE_SHA2_256 (32u)
#define MCUXCLSGI_DRV_STATE_SIZE_SHA2_384 (64u)
#define MCUXCLSGI_DRV_STATE_SIZE_SHA2_512 (64u)

#define MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_224 (28u)
#define MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_256 (32u)
#define MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_384 (48u)
#define MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_512 (64u)

#define MCUXCLSGI_DRV_CONFIG_SHA2_224 (MCUXCLSGI_SFR_CTRL_SHA2_EN \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_LOW_LIM \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_SIZE_224) ///< Configures SHA-224
#define MCUXCLSGI_DRV_CONFIG_SHA2_256 (MCUXCLSGI_SFR_CTRL_SHA2_EN \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_LOW_LIM \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_SIZE_256) ///< Configures SHA-256
#define MCUXCLSGI_DRV_CONFIG_SHA2_384 (MCUXCLSGI_SFR_CTRL_SHA2_EN \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_LOW_LIM \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_SIZE_384) ///< Configures SHA-384
#define MCUXCLSGI_DRV_CONFIG_SHA2_512 (MCUXCLSGI_SFR_CTRL_SHA2_EN \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_LOW_LIM \
                                      | MCUXCLSGI_SFR_CTRL_SHA2_SIZE_512) ///< Configures SHA-512
#define MCUXCLSGI_DRV_CONFIG_SHA2_MASK (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                       | MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                       | MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                       | MCUXCLSGI_DRV_CONFIG_SHA2_512)   ///< Mask to extract SHA-2 configuration from SHA2_CTRL register


#define MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV (MCUXCLSGI_SFR_CTRL_SHA2_HASH_RELOAD \
                                          | MCUXCLSGI_SFR_CTRL_SHA2_NO_AUTO_INIT) ///< Enables loading a custom IV

#define MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV (MCUXCLSGI_SFR_CTRL_SHA2_NO_AUTO_INIT) ///< Use state that has been loaded

#define MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE (MCUXCLSGI_SFR_CTRL_SHA2_MODE \
                                            | MCUXCLSGI_SFR_CTRL_SHA2_HIGH_LIM_AUTO) ///< Enable AUTO mode (if not enabled, NORMAL mode is executed, but FIFO limits have to be set explicitly)

#define MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_256 (MCUXCLSGI_SFR_CTRL_SHA2_HIGH_LIM_256) ///< Configures FIFO limit for 256-bit data blocks
#define MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512 (MCUXCLSGI_SFR_CTRL_SHA2_HIGH_LIM_512) ///< Configures FIFO limit for 512-bit data blocks
#define MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_1024 (MCUXCLSGI_SFR_CTRL_SHA2_HIGH_LIM_1024) ///< Configures FIFO limit for 1024-bit data blocks

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE) ///< Configures loading data for SHA-224 in auto mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE) ///< Configures loading data for SHA-256 in auto mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE) ///< Configures loading data for SHA-384 in auto mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE) ///< Configures loading data for SHA-512 in auto mode using the standard IV

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading an IV/state for SHA-224 in auto mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading an IV/state for SHA-256 in auto mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading an IV/state for SHA-384 in auto mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading an IV/state for SHA-512 in auto mode

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-224 in auto mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-256 in auto mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-384 in auto mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_AUTO_MODE \
                                                                    | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-512 in auto mode using an already loaded IV

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_NORMALMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512) ///< Configures loading data for SHA-224 in normal mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_NORMALMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512) ///< Configures loading data for SHA-256 in normal mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_NORMALMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_1024) ///< Configures loading data for SHA-384 in normal mode using the standard IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_NORMALMODE_LOADDATA_USESTANDARDIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_1024) ///< Configures loading data for SHA-512 in normal mode using the standard IV

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_NORMALMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_256 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading loading an IV/state for SHA-224 in normal mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_NORMALMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_256 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading loading an IV/state for SHA-256 in normal mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_NORMALMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading loading an IV/state for SHA-384 in normal mode
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_NORMALMODE_LOADIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512 \
                                                        | MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV) ///< Configures loading loading an IV/state for SHA-512 in normal mode

#define MCUXCLSGI_DRV_CONFIG_SHA2_224_NORMALMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_224 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-224 in normal mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_256_NORMALMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_256 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_512 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-256 in normal mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_384_NORMALMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_384 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_1024 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-384 in normal mode using an already loaded IV
#define MCUXCLSGI_DRV_CONFIG_SHA2_512_NORMALMODE_LOADDATA_USELOADEDIV (MCUXCLSGI_DRV_CONFIG_SHA2_512 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_FIFO_HILIM_1024 \
                                                                      | MCUXCLSGI_DRV_CONFIG_SHA2_USE_LOADED_IV) ///< Configures loading data for SHA-512 in normal mode using an already loaded IV

MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_configureSha2)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_configureSha2(uint32_t control);

/*****************************************************
 * Functions related to security features
 *****************************************************/

 #if 0
/**
 * @brief Flush SGI
 *
 * Flushes SGI SFRs and register banks based on configuration (all, key, datain)
 *
 * @param[in]  option   Configuration, which registers shall be flushed
 */
#define MCUXCLSGI_DRV_FLUSH_ALL  (MCUXCLSGI_SFR_CTRL2_FLUSH)
#define MCUXCLSGI_DRV_FLUSH_KEY  (MCUXCLSGI_SFR_CTRL2_FLUSHKEY)
#define MCUXCLSGI_DRV_FLUSH_DATA (MCUXCLSGI_SFR_CTRL2_FLUSHDATA)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableFlush)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_enableFlush(uint32_t option);
#endif /* 0 */

/** Enables masking - next load/store of data/key will use masking
 * Returns previous control value */
#define MCUXCLSGI_DRV_MASKING_SFR (MCUXCLSGI_SFR_CTRL2_SMASKEN)
#define MCUXCLSGI_DRV_MASKING_XOR (MCUXCLSGI_SFR_CTRL2_SMASKSW | MCUXCLSGI_SFR_CTRL2_SMASKEN)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClmcuxClSgi_Drv_enableMaskingSgi_Drv_wait)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_enableMasking(uint32_t type, uint32_t mask);


/**
 * @brief Enable and init counter for SHA-2
 *
 * Enables counter for SHA-2 and initializes counter value
 *
 * @param[in]  cntVal   Counter init value
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableHashCounter)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_enableHashCounter(uint32_t cntVal);

/**
 * @brief Compare counter value
 *
 * Compare counter value to expected value
 *
 * @param[in]    session          Handle for the current CL session
 * @param[in]    expCntVal        Expected counter value
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_checkHashCounter)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_checkHashCounter(mcuxClSession_Handle_t session, uint32_t expectedCounterValue);

/**
 * @brief Get the SGI Calculation counter value.
 *
 * @return SGI Calculation counter value.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getCount)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_getCount(void);


/**
 * @brief Waits for the SGI and does a SHA error check.
 *
 *  Waits until the SGI operation is finished and checks if SGI SHA ERROR flag is set.
 *  Returns via early exit in fault attack case.
 *  Note: SHA_ERROR is reset after every successful SHA operation,
 *        therefore SHA_ERROR needs to be checked after every SHA operation.
 *
 * @param[in]    session          Handle for the current CL session
 */
 MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_Sha2_wait)
 MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_Sha2_wait(mcuxClSession_Handle_t session);

/*****************************************************
 * Functions related to input output handling
 *****************************************************/

/**
 * @brief Increments by 1 (with carry) value in datin
 *
 * Increments data in DATIN register bank by one.
 * The incrementation will start at the least significant word (located at offset + length)
 * and will end at the most significant word (located at offset).
 * This function will also propagate carry if a non-zero length is specified.
 *
 * Data Integrity: Expunge(offset + length)
 *
 * @param[in]  offset   Offset with respect to the SGI base address.
 * @param[in]  length   Size of data on which increment shall be applied
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_incrementData)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_incrementData(uint32_t offset, uint32_t length);

/**
 * @brief Set byte order
 *
 * Sets the byte order of reading from and writing to register banks.
 *
 * @param[in]  mode   Specifies byte order mode to be used
 *
 * @return Return original CTRL2 register contents for back up.
 */
#define MCUXCLSGI_DRV_BYTE_ORDER_LE (MCUXCLSGI_SFR_CTRL2_BYTES_ORDER)
#define MCUXCLSGI_DRV_BYTE_ORDER_BE (0u)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_setByteOrder)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_setByteOrder(uint32_t mode);

/**
 * @brief Enables XOR on write
 *
 * Enables XORWR feature of register banks, such that
 * value is XORed with data currently contained in register bank.
 *
 * @return Return original CTRL2 register contents for back up.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableXorWrite)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_enableXorWrite(void);

/**
 * @brief Disables XOR on write
 *
 * Disables XORWR feature of register banks.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableXorWrite)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_disableXorWrite(void);

/**
 * @brief Fetch data word into an SGI register
 *
 * Fetch one word of data to the SGI register. Offset specifies
 * the word location in the register bank with respect to
 * SGI base address, where the word is written to.
 *
 * @param[in]  offset   Offset with respect to SGI base address.
 *                      Must be the offset of a valid SGI register.
 * @param[in]  data     Data to be written to DATIN
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_loadWord)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_loadWord(uint32_t offset, uint32_t data);

/**
 * @brief Enables storing output in key register
 *
 * Enables to store the output of a crypto operation in a key
 * register bank, indicated by keyIndex.
 *
 * @param[in]  keyIndex   Indicates key register bank, which the output shall be written to
 *
 * @return Return original CTRL2 register contents for back up.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableOutputToKey)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_enableOutputToKey(uint32_t keyIndex);

/**
 * @brief Disable output to key
 *
 * Disables to store the output of a crypto operation in a key
 * register bank. Output will be stored in DATOUT.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableOutputToKey)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_disableOutputToKey(void);

/**
 * @brief Trigger writing result to DATOUT
 *
 * Only 128 bits of output are stored in the output register
 * in one step. This function triggers writing the next 128 bits
 * of the output to DATOUT.
 *
 * @note: It must be checked, with mcuxClSgi_Drv_wait that the
 *        writing of output data completed, before fetching it from DATOUT.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_triggerOutput)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_triggerOutput(void);

/**
 * @brief Get data word from a DATA/KEY register.
 *
 * Read one word from a SGI register bank. Offset
 * specifies the word to be read with respect to SGI base address.
 *
 * @param[in]  offset   Offset of a valid SGI register.
 *
 * @return 32-bit result word
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_storeWord)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_storeWord(uint32_t offset);

#ifdef SGI_HAS_PRNG_SW_READ
/**
 * @brief Get PRNG value from SGI_PRNG_SW_READ
 *
 * Get PRNG_SW_READ register value
 *
  * @return 32-bit PRNG value
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getPrngWord)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_getPrngWord(void);

/**
 * @brief Reseed the PRNG value in SGI_PRNG_SW_SEED
 *
 * Seed value to SGI_PRNG_SW_SEED
 *
 * @param[in]  seed   The value which will be seeded
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_reseedPrng)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_reseedPrng(uint32_t seed);

#endif /* SGI_HAS_PRNG_SW_READ */

/**
 * @brief Get current value of SFR seed
 *
 * Get SFR seed register value
 *
  * @return 32-bit seed value
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getSfrSeed)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_getSfrSeed(void);

/**
 * @brief Get value from status register
 *
 * Get status register and check if SGI raised an error
 *
 * @param[in]    session          Handle for the current CL session
 *
 * @return bool status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_readStatusError)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSgi_Status_t) mcuxClSgi_Drv_readStatusError(mcuxClSession_Handle_t session);

/**
 * @brief Get value from access error register
 *
 * Get access error register and check if SGI raised an related error
 *
 * @param[in]    session          Handle for the current CL session
 *
 * @return bool status
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_readAccessError)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClSgi_Status_t) mcuxClSgi_Drv_readAccessError(mcuxClSession_Handle_t session);

#ifdef SGI_HAS_FLUSHWR /* SGI has the flush on write functionality available */
/**
 * @brief Enables the flush-on-write feature
 *
 * @post With flush-on-write enabled, when writing data to a register, random data
 * will be loaded to it instead
 *
 * @return Original CTRL2 register contents (for backup).
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableFlushWr)
MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClSgi_Drv_enableFlushWr(void);

/**
 * @brief Disables the flush-on-write feature
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableFlushWr)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_disableFlushWr(void);
#endif /* SGI_HAS_FLUSHWR */

/**
 * @brief Flushes consecutive register banks with random data
 *
 * Uses the SGI flush-on-write feature to flush a specific register bank with random data.
 *
 * Data Integrity: Expunge(offset + number of bytes to be cleared)
 *
 * @param offset         Offset of the register bank that should be flushed.
 *                       Can be any of MCUXCLSGI_DRV_KEY*_OFFSET or MCUXCLSGI_DRV_DAT*_OFFSET.
 * @param numberOfWords  Number of 32-bit SFR words to clear.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_flushRegisterBanks)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Drv_flushRegisterBanks(
  uint32_t offset,
  uint32_t numberOfWords);

#if 0  /* Disable below unused functions, but keep those disabled functions for possible future use*/
/**
 * @brief Enable loading a custom hash IV (intermediate state) to the SGI.
 *
 * Updates control value (SHA2_CTRL) to enable loading partial digest to the SGI.
 * After calling this function, data loaded to DATIN will be interpreted as IV.
 *
 * @note: Alternatively option MCUXCLSGI_DRV_CONFIG_SHA2_LOAD_IV can be chosen, when configuring SHA-2.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_enableHashReload)
void mcuxClSgi_Drv_enableHashReload(void);

/**
 * @brief Disable loading a custom hash IV (intermediate state) to the SGI.
 *
 * Updates control value (SHA2_CTRL) to disable reloading the partial digest to the SGI.
 * After loading an IV, this function can be called to indicate that input data will be loaded in the sequel.
 * Data loaded to DATIN after calling this function is interpreted as input data to hashing.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableHashReload)
void mcuxClSgi_Drv_disableHashReload(void);

/** Returns current value of mask - needs to be passed to next enableMasking() call*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_getMaskValue)
uint32_t mcuxClSgi_Drv_getMaskValue(void);

/**
 * @brief Disable masking data/key
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_disableMasking)
void mcuxClSgi_Drv_disableMasking(void);

/**
 * @brief Enable noise
 *
 * @return Return original CTRL register contents for back up.
 */
#define MCUXCLSGI_DRV_AES_NOISE_EN           (MCUXCLSGI_SFR_CTRL_AES_EN)
#define MCUXCLSGI_DRV_DES_NOISE_EN           (MCUXCLSGI_SFR_CTRL_DES_EN)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_setNoise)
uint32_t mcuxClSgi_Drv_setNoise(uint32_t noise);

/**
 * @brief Select output mode
 *
 * Selects whether to store the SGI result to the output
 * register banks in plain, or whether to XOR it with data from DATIN
 * register banks, prior to storing it in DATOUT.
 *
 * @param[in]  mode   Specifies output mode to be used
 *
 * @return Return original CTRL register contents for back up.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Drv_dataOut_res)
uint32_t mcuxClSgi_Drv_dataOut_res(uint32_t mode);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_DRV_H_ */
