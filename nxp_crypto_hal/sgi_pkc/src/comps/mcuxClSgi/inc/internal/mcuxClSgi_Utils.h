/*--------------------------------------------------------------------------*/
/* Copyright 2022-2026 NXP                                                  */
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

#ifndef MCUXCLSGI_UTILS_H_
#define MCUXCLSGI_UTILS_H_

#include <mcuxClCore_Platform.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClSgi_Drv.h>
#include <mcuxClSgi_Types.h>
#include <mcuxClSession.h>
#include <mcuxClKey_Types.h>
#include <internal/mcuxClKey_Types_Internal.h>
#include <internal/mcuxClKey_Functions_Internal.h>

#include <mcuxClBuffer.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClMemory_CopySecure_Internal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************
 * Type declarations
 **********************************************************/

/**
 * @brief Function type to initialize the SGI for the respective hash algorithm
 *
 * This function initializes the SGI to perform a hash operation of dedicated algorithm in dedicated mode using either a standard or specified IV
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSgi_Utils_initHash,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClSgi_Utils_initHash)(
  mcuxClSession_Handle_t session,
  const uint32_t *pIV,
  uint32_t mode
));

/**
 * @brief Function type to load one block of internal input data to the SGI
 *
 * This function loads one word-aligned block of internal input data, of size dedicated to chosen hash algorithm, to the SGI
 */
MCUX_CSSL_FP_FUNCTION_POINTER(mcuxClSgi_Utils_loadInternalHashBlock,
typedef MCUX_CSSL_FP_PROTECTED_TYPE(void) (*mcuxClSgi_Utils_loadInternalHashBlock)(
  const uint32_t *pData
));

/*****************************************************
 * utilHash Functions
 *****************************************************/

#define MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV           (0xA5A5B4B4u)
#define MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV       (0x5A5AB4B4u)

/**
 * @brief Initializes SHA-224 based on provided mode parameters
 *
 * This function initializes SHA-224 based on provided user choices,
 * namely running SGI in NORMAL or AUTO mode and loading an IV which is
 * provided by the user, or using the standard IV
 *
 * @param[in]  session Session handle
 * @param[in]  pIV    Pointer to data buffer which is loaded
 *                    (in case of using the standard IV, please set to NULL)
 * @param[in]  mode   Chooses, whether to use AUTO or NORMAL mode and whether
 *                    to use the standard IV or load an IV
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_initSha224, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha224(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode);

/**
 * @brief Initializes SHA-256 based on provided mode parameters
 *
 * This function initializes SHA-256 based on provided user choices,
 * namely running SGI in NORMAL or AUTO mode and loading an IV which is
 * provided by the user, or using the standard IV
 *
 * @param[in]  pIV    Pointer to data buffer which is loaded
 *                    (in case of using the standard IV, please set to NULL)
 * @param[in]  mode   Chooses, whether to use AUTO or NORMAL mode and whether
 *                    to use the standard IV or load an IV
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_initSha256, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha256(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode);

/**
 * @brief Initializes SHA-384 based on provided mode parameters
 *
 * This function initializes SHA-384 based on provided user choices,
 * namely running SGI in NORMAL or AUTO mode and loading an IV which is
 * provided by the user, or using the standard IV
 *
 * @param[in]  session Session handle
 * @param[in]  pIV    Pointer to data buffer which is loaded
 *                    (in case of using the standard IV, please set to NULL)
 * @param[in]  mode   Chooses, whether to use AUTO or NORMAL mode and whether
 *                    to use the standard IV or load an IV
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_initSha384, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha384(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode);

/**
 * @brief Initializes SHA-512 based on provided mode parameters
 *
 * This function initializes SHA-512 based on provided user choices,
 * namely running SGI in NORMAL or AUTO mode and loading an IV which is
 * provided by the user, or using the standard IV
 *
 * @param[in]  session Session handle
 * @param[in]  pIV    Pointer to data buffer which is loaded
 *                    (in case of using the standard IV, please set to NULL)
 * @param[in]  mode   Chooses, whether to use AUTO or NORMAL mode and whether
 *                    to use the standard IV or load an IV
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_initSha512, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha512(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode);



/**
 * @brief Returns the key type sgi configuration of the key handle.
 *
 * @return Sgi key type configuration field of the key handle.
 *         #MCUXCLSGI_DRV_CTRL_INVALID on invalid key handle
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_getKeyTypeConf)
static inline uint32_t mcuxClSgi_getKeyTypeConf(const mcuxClKey_Descriptor_t* key)
{
  uint32_t keyTypeConfig = MCUXCLSGI_DRV_CTRL_INVALID;
  if(MCUXCLKEY_ALGO_ID_AES == (key->type.algoId & MCUXCLKEY_ALGO_ID_ALGO_MASK))
  {
    switch(key->type.size)
    {
      case MCUXCLKEY_SIZE_128:
        keyTypeConfig = MCUXCLSGI_DRV_CTRL_AES128;
        break;
#ifdef MCUXCL_FEATURE_AES192
      case MCUXCLKEY_SIZE_192:
        keyTypeConfig = MCUXCLSGI_DRV_CTRL_AES192;
        break;
#endif /* MCUXCL_FEATURE_AES192 */
      case MCUXCLKEY_SIZE_256:
        keyTypeConfig = MCUXCLSGI_DRV_CTRL_AES256;
        break;
      default:
        keyTypeConfig = MCUXCLSGI_DRV_CTRL_INVALID;
        break;
    }
  }

  return keyTypeConfig;
}

/**
 * @brief Returns the sgi configuration of the key handle.
 *
 * @return Sgi configuration field of the key handle.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_getKeyConf)
static inline uint32_t mcuxClSgi_getKeyConf(const mcuxClKey_Descriptor_t* key)
{
  uint32_t keyTypeConfig = mcuxClSgi_getKeyTypeConf(key);
  uint32_t keyIndex = mcuxClSgi_Drv_keySlotToIndex(mcuxClKey_getLoadedKeySlot(key));
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("key have valid value and keyIndex is valid")
  return keyTypeConfig | MCUXCLSGI_DRV_CTRL_INKEYSEL(keyIndex);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
}

/**
 * @brief Loads a 128-bit block of data to the SGI
 *
 * This function loads a 128-bit data block to the specified SGI
 * register bank. Unaligned access is handled properly, as
 * well as differences in compilers and architectures.
 *
 * Data Integrity: Expunge(sgisfrDatOffset + pData + 16u)
 *
 * @param[in]  sgisfrDatOffset   Offset of the target SGI SFR,
 *                               can be either of these values:
 *                                 #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN3_OFFSET
 *                                 #MCUXCLSGI_DRV_DATOUT_OFFSET
 * @param[in]  pData             Pointer to data buffer which is loaded
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_load128BitBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_load128BitBlock(uint32_t sgisfrDatOffset, const uint8_t *pData);

/** Helper macro for DI balanced call to mcuxClSgi_Utils_load128BitBlock. */
#define MCUXCLSGI_UTILS_LOAD128BITBLOCK_DI_BALANCED(sfrDatOffset, pData) \
  do {  \
    MCUX_CSSL_DI_RECORD(sgiLoad, ((uint32_t)(sfrDatOffset)) + ((uint32_t)pData) + 16u); \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(sfrDatOffset, pData)); \
  } while(false)

/**
 * @brief Loads a data to the SGI which are not full block
 *
 * This function loads a data to the specified SGI
 * register bank. Unaligned access is handled properly, as
 * well as differences in compilers and architectures.
 *
 * Data Integrity: Expunge(sgisfrDatOffset + pData + len + pTempBuff)
 *
 * @param[in]  sgisfrDatOffset   Offset of the target SGI SFR,
 *                               can be either of these values:
 *                                 #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN3_OFFSET
 *                                 #MCUXCLSGI_DRV_DATOUT_OFFSET
 * @param[in]  pData             Pointer to data buffer which is loaded
 * @param[in]  len               Length of input data
 * @param[in]  pTempBuff         Pointer to temporary buffer
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_load_notFull128Block_buffer)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_load_notFull128Block_buffer(uint32_t sgisfrDatOffset, mcuxCl_InputBuffer_t pData, uint32_t len, uint8_t *pTempBuff);

/**
 * @brief Stores a 128-bit block of data from the SGI
 *
 * This function stores a 128-bit data block from the specified SGI
 * data register bank. Unaligned access is handled properly, as
 * well as differences in compilers and architectures.
 *
 * Data Integrity: Expunge(sgisfrDatOffset + pOut + 16u)
 *
 * @param[in]  sgisfrDatOffset   Offset of the target data SGI SFR,
 *                               can be either of these values:
 *                                 #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN3_OFFSET
 *                                 #MCUXCLSGI_DRV_DATOUT_OFFSET
 * @param[in]  pOut            Pointer to data buffer which data is stored to
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_store128BitBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_store128BitBlock(uint32_t sgisfrDatOffset, uint8_t *pOut);

/** Helper macro for DI balanced call to mcuxClSgi_Utils_store128BitBlock. */
#define MCUXCLSGI_UTILS_STORE128BITBLOCK_DI_BALANCED(sfrDatOffset, pOut) \
  do {  \
    MCUX_CSSL_DI_RECORD(sgiStore, ((uint32_t)(sfrDatOffset)) + ((uint32_t)pOut) + 16u); \
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(sfrDatOffset, pOut)); \
  } while(false)


/**
 * @brief Stores a 128-bit block of data using masking from the SGI
 *
 * This function stores a 128-bit data block using masking from the specified SGI
 * data register bank to a buffer.
 *
 * Data Integrity:
 *   EXPUNGEs sgisfrDatOffset, pOut, offset and pXorMask.
 *
 * @param[in]  session           Session handle
 * @param[in]  sgisfrDatOffset   Offset of the target data SGI SFR,
 *                               can be either of these values:
 *                                 #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                                 #MCUXCLSGI_DRV_DATIN3_OFFSET
 *                                 #MCUXCLSGI_DRV_DATOUT_OFFSET
 * @param[in]  pOut            Pointer to the data buffer which data is stored to
 * @param[in]  offset          Offset of the data buffer to store to
 * @param[in]  pXorMask        Pointer to 128 bit mask
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_storeMasked128BitBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storeMasked128BitBlock(
                                                               mcuxClSession_Handle_t session,
                                                               uint32_t sgisfrDatOffset,
                                                               uint8_t* pOut,
                                                               uint32_t offset,
                                                               const uint32_t *pXorMask);

/**
 * @brief Load data to FIFO
 *
 * When using SGI in auto mode for hashing, data has to be
 * loaded to FIFO. This function takes care of that.
 *
 * Data Integrity:
 *   EXPUNGEs pData and length.
 *
 * @param[in]  pData    Pointer to data buffer which is loaded
 * @param[in]  length   Byte-length of data
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_loadFifo)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_loadFifo(const uint8_t *pData, uint32_t length);

/**
 * @brief Load data from an input buffer to FIFO
 *
 * When using SGI in auto mode for hashing, data has to be
 * loaded to FIFO. This function takes care of that.
 *
 * @param[in]  data     Data buffer which is loaded to the FIFO
 * @param[in]  length   Byte-length of data
 *
 * Data Integrity:
 *   EXPUNGEs data and length.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_loadFifo_buffer)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_loadFifo_buffer(mcuxCl_InputBuffer_t data, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_loadFifo_buffer);
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("SGI driver expects unaligned memory access (guarded by MCUXCL_FEATURE_HW_UNALIGNED_MEMORY_ACCESS)")
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo(MCUXCLBUFFER_GET(data), length));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_loadFifo_buffer,MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo));
}

/**
 * @brief Store partial hash in output buffer
 *
 * Store the result of a hash operation in an output buffer during process phase.
 *
 * Data Integrity:
 *   EXPUNGEs pOutput and length.
 *
 * @param[in]  pOutput    Pointer to output buffer, where partial digest is stored word-wise.
 *                        The pointer needs to be word aligned.
 * @param[in]  length     Byte-length of result. The input length needs to be a multiple of wordsize.
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_storePartialHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storePartialHash(uint32_t *pOutput, uint32_t length);

/**
 * @brief Store result in output buffer
 *
 * Store the result of a hash operation in an output buffer.
 *
 * Data Integrity:
 *   Expunges pOutput and length.
 *
 * @param[in]  session    Session handle
 * @param[in]  pOutput    Pointer to output buffer, where result is stored word-wise
 * @param[in]  length     Byte-length of result
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_storeHashResult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storeHashResult(mcuxClSession_Handle_t session, mcuxCl_Buffer_t pOutput, uint32_t length);

/**
 * @brief Configure the SGI in AUTO mode with DMA handshake(s) and start the operation.
 *
 * This function configures the SGI in AUTO mode. Two DMA channels are used to tranfer
 * data to/from SGI. SGI/DMA handshake signals are enabled to coordinate the communication.
 * This function also starts the operation.
 *
 * @pre Function @ref mcuxClSgi_Drv_configureAutoMode has been called.
 *
 * @param[in]  operation              Configuration of the SGI operation to be executed
 * @param[in]  enableOutputHandshake  Enable or disable the output DMA-SGI handshake
 *
 */
#define MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_ENABLE   ((uint32_t) 1u)
#define MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_DISABLE  ((uint32_t) 0u)
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_startAutoModeWithHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_startAutoModeWithHandshakes(uint32_t operation, uint32_t enableOutputHandshake);

/**
 * @brief Stop and disable AUTO mode, disable DMA handshakes.
 *
 * This function stop and disables SGI AUTO mode, and disables all handshake related
 * settings in the SGI and the SCM for the involved DMA channel.
 *
 * @param[in]  inputChannel      DMA channel that is used to write to the SGI
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes(mcuxClSession_Channel_t inputChannel);

/**
 * @brief Stop and disable AUTO mode, disable DMA handshakes for both channels.
 *
 * This function stop and disables SGI AUTO mode, and disables all handshake related
 * settings in the SGI and the SCM for two involved DMA channels.
 *
 * @param[in]  inputChannel      DMA channel that is used to write to the SGI
 * @param[in]  outputChannel     DMA channel that is used to read from the SGI
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes(
  mcuxClSession_Channel_t inputChannel,
  mcuxClSession_Channel_t outputChannel
);


/**
 * Internal function to release the SGI.
 * Will also release the HW if MCUXCL_FEATURE_SESSION_JOBS is enabled.
 *
 * @param[in]  session            Session handle
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_Uninit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_Uninit(mcuxClSession_Handle_t session);

/**
 * @brief Copy 16 bytes from source to destination with SFR masking enabled.
 *
 * This function will enable SGI SFR-masking with the given @p sfrSeed, and disable it again after the copy.
 *
 * Data Integrity: Expunge(pSrc + pDst + MCUXCLAES_BLOCK_SIZE)
 *
 * @param[out] pDst     Pointer to destination buffer.
 * @param[in]  pSrc     Pointer to source buffer.
 * @param[in]  sfrSeed  Seed value for SFR masking
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_copyBlockSfrMasked)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_copyBlockSfrMasked(uint32_t *pDst, const uint32_t *pSrc, uint32_t sfrSeed);

/**
 * @brief Copy SFR-masked data to/from SGI.
 *
 * This function will enable SGI SFR-masking with the given @p sfrSeed, and disable it again after the copy.
 *
 * Data Integrity: Expunge(pSrc + pDst + length)
 *
 * @param[in] pDst     destination address
 * @param[in] pSrc     source address
 * @param[in] length   byte length of the data to be copied
 * @param[in] sfrSeed  SFR mask seed
 *
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_copySfrMasked)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_copySfrMasked(uint32_t *pDst, const uint32_t *pSrc, uint32_t length, uint32_t sfrSeed);

/**
 * @brief Load key into SGI using secure word-wise copy operation.
 *
 * @param[in]  offset      offset to key register.
 * @param[out] pKey        pointer to the key buffer.
 * @param[in]  keySize     key size.
 *
 * Data Integrity: Expunge(offset  + pKey + keySize)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_loadKey_secure)
static inline MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_loadKey_secure(
  uint32_t offset,
  const uint8_t *pKey,
  uint32_t keySize)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_loadKey_secure);
  uint32_t *sgiKey = mcuxClSgi_Sfr_getAddr(offset);
  /* The caller should have recorded the offset, hence expunge it and record sgiKey */
  MCUX_CSSL_DI_EXPUNGE(mcuxClMemory_copy_secure_int, offset);
  MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int, sgiKey);
  MCUXCLMEMORY_COPY_SECURE_INT((uint8_t *) sgiKey, pKey, keySize);
  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_loadKey_secure, MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT);
}


#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
/**
 * @brief Decrements an 16-byte value from the SGI DATIN at an offset srcSfrDatOffset and stores it at an offset dstSfrDatOffset.
 *
 * This function retrieves a 16-byte value from the SGI DATIN at an offset srcSfrDatOffset, decrements it by 1,
 * and stores the result at an dstSfrDatOffset.
 * The decremention will start at the least significant word (located at srcSfrDatOffset + 12)
 * and will end at the most significant word (located at srcSfrDatOffset).
 *
 * EXPUNGEs srcSfrDatOffset + dstSfrDatOffset
 *
 * @param srcSfrDatOffset     Offset of the source data SGI SFR,
 *                            can be either of these values:
 *                              #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                              #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                              #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                              #MCUXCLSGI_DRV_DATOUT_OFFSET
 * @param dstSfrDatOffset     Offset of the destination data SGI SFR,
 *                            can be either of these values:
 *                              #MCUXCLSGI_DRV_DATIN0_OFFSET
 *                              #MCUXCLSGI_DRV_DATIN1_OFFSET
 *                              #MCUXCLSGI_DRV_DATIN2_OFFSET
 *                              #MCUXCLSGI_DRV_DATOUT_OFFSET
*/
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_decrement128Bit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_decrement128Bit(uint32_t srcSfrDatOffset, uint32_t dstSfrDatOffset);
#endif /* defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING) && defined(MCUXCL_FEATURE_CIPHERMODES_CTR) */

/**
 * @brief This function performs RFC3394 key unwrapping with the SGI.
 *
 * Only 128-bit and 256-bit AES key material sizes are supported.
 *
 * @post The unwrapped key material will be stored in SGI key registers that are
 * fixed by hardware, see @ref MCUXCLKEY_LOADOPTION_SLOT_SGI_KEY_UNWRAP.
 *
 * @param      session       The session handle.
 * @param      key           The key handle containing the wrapped key material (word-aligned)
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_keyUnwrapRfc3394)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_keyUnwrapRfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key
);

/**
 * @brief This function performs RFC3394 key wrapping with the SGI.
 *
 * - Only 128-bit and 256-bit AES key material sizes are supported.
 * - The `keyMaterial` can contain either a plain key or a protected key to be wrapped.
 * - The `pSfrSeed` determines the type of key in the `keyMaterial`. For a plain key the
 *   `pSfrSeed` is NULL, and for a protected key the `pSfrSeed` holds the seed for SFR masking.
 * - The protected key is loaded to SGI in blocks of `RFC3394_BLOCK_SIZE` using a special type
 *   of SFR masking, that is tightly coupled to how the keys were produced in the
 *   `mcuxClAes_keyUnwrapRfc3394_swDriven` function. And the `pSfrSeed` is re-initialized
 *   for each block before it is loaded to SGI, for them to be unmasked correctly.
 *
 * @post The wrapped key material will be stored in the container of the @p key.
 *
 * @param      session       The session handle.
 * @param      key           The key handle (word-aligned).
 * @param[in]  keyMaterial   A pointer to the key material to be wrapped.
 * @param[in]  pSfrSeed      Seed for the SFR-masked key.
 */
MCUX_CSSL_FP_FUNCTION_DECL(mcuxClSgi_Utils_keyWrapRfc3394)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_keyWrapRfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t* pKeyMaterial,
  const uint32_t* pSfrSeed
);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MCUXCLSGI_UTILS_H_ */
