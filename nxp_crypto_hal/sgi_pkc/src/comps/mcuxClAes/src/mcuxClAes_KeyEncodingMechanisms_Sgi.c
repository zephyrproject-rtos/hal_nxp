/*--------------------------------------------------------------------------*/
/* Copyright 2023-2026 NXP                                                  */
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

/** @file  mcuxClAes_KeyEncodingMechanisms.c
 *  @brief Implementations of internal functions that take care of AES key
 *         encodings using the SGI.
 */

#include <mcuxClMemory.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxClAes.h>
#include <mcuxClKey.h>
#include <mcuxCsslDataIntegrity.h>
#include <internal/mcuxClAes_Internal_Functions.h>
#include <internal/mcuxClAes_KeyEncodingMechanisms_Sgi.h>
#include <internal/mcuxClAes_Internal_Constants.h>
#include <internal/mcuxClMemory_Copy_Internal.h>
#include <internal/mcuxClMemory_Compare_Internal.h>
#include <internal/mcuxClMemory_CopyWords_Internal.h>
#include <internal/mcuxClMemory_Clear_Internal.h>
#include <internal/mcuxClKey_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <internal/mcuxClPrng_Internal.h>




MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_keyLoad_rfc3394, mcuxClKey_LoadFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyLoad_rfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  uint8_t **ppDest,
  mcuxClKey_KeyChecksum_t * pKeyChecksums,
  mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAes_keyLoad_rfc3394);

  if(MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
     MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_keyUnwrapRfc3394(session, key));
    *ppDest = mcuxClAes_getKeyDest_rfc3394UnWrap();
  }
  else
  {
    /* spec is not valid */
    MCUXCLSESSION_FAULT(session, MCUXCLKEY_STATUS_FAULT_ATTACK);
  }

  if(pKeyChecksums != NULL)
  {
    pKeyChecksums->VerifyFunc = key->encoding->handleKeyChecksumsFunc;
    pKeyChecksums->protectionToken_VerifyFunc = key->encoding->protectionToken_handleKeyChecksumsFunc;
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAes_keyLoad_rfc3394,
    MCUX_CSSL_FP_CONDITIONAL((MCUXCLKEY_ENCODING_SPEC_ACTION_SECURE == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK)),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_keyUnwrapRfc3394))
  );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_keyStore_rfc3394, mcuxClKey_StoreFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyStore_rfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t *pSrc,
  mcuxClKey_Encoding_Spec_t spec)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAes_keyStore_rfc3394);

  if(MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PLAIN == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    /* For a plain key the `pSfrSeed` is set to NULL. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_keyWrapRfc3394(
      session, key, pSrc, NULL /* pSrc is plain key material */)
    );
  }
  else if(MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PROTECTED == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
  {
    const uint8_t* pMaskedKeyMaterial = pSrc;

    /* The SFR seed is stored after the plain key, which has the length of type.size */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pSrc is always 32 bit aligned as it is an SGI SFR, key->type.size is a multiple of 4, i.e. &pSrc[key->type.size] is 32 bit aligned");
    const uint32_t* pSfrSeed = (const uint32_t*)(&pSrc[key->type.size]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING();

    /* For a protected key the `pSfrSeed` is passed to the wrapping function. */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_keyWrapRfc3394(session, key, pMaskedKeyMaterial, pSfrSeed));
  }
  else
  {
    /* spec is not valid */
    MCUXCLSESSION_FAULT(session, MCUXCLKEY_STATUS_FAULT_ATTACK);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAes_keyStore_rfc3394,
    MCUX_CSSL_FP_CONDITIONAL(
      ((MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PLAIN == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))
        || (MCUXCLKEY_ENCODING_SPEC_ACTION_STORE_FROM_PROTECTED == (spec & MCUXCLKEY_ENCODING_SPEC_ACTION_MASK))),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_keyWrapRfc3394))
  );
}

/**
 * @brief RFC3394 encoded key load function. This function will place the encoded key
 *        in SGI registers in preparation for unwrapping operations.
 *
 * @param[in]     wrappedKey  Initialized key handle containing wrapped key.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_rfc3394Utils_loadWrappedKeyData)
static MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_rfc3394Utils_loadWrappedKeyData(
  mcuxClKey_Handle_t wrappedKey)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAes_rfc3394Utils_loadWrappedKeyData);

  /*************************************************************************************
  *  SGI Register layout at the end of LoadWrappedKeyData execution.
  *
  *    DATIN_0                         | ... | DATIN_n-1                         |
  *  -----------------------------------------------------------------------------
  *  | 0000000000000000 WrappedKey[n]  | ... | 0000000000000000 WrappedKey[1]    |
  *
  *  Order of wrapped RFC3394 key blocks in DATIN registers is reversed such that main
  *  processing loop starts at index 0.
  *
  *    DATOUT                            |
  *  -------------------------------------
  *  | WrappedKey[0]  xxxxxxxxxxxxxxxx   |
  *
  *  n - index [0:n] of RFC3394 wrapped data block
  *  x - uninitialized
  *  0 - cleared
  **************************************************************************************/

  /* Fill DATOUT lower part */
  uint8_t *pData = mcuxClKey_getKeyData(wrappedKey);
  uint8_t *pTargetReg = (uint8_t*)mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
  MCUX_CSSL_DI_RECORD(memory_copy_words_params, pTargetReg);
  MCUX_CSSL_DI_RECORD(memory_copy_words_params, pData);
  MCUX_CSSL_DI_RECORD(memory_copy_words_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pTargetReg, pData, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE));

  /* Fill corresponding DATIN parts based on the key size. */
  /* Loop iterations start with storing lowest wrapped key data chunk into the highest DATIN register*/
  const uint32_t keySizeInRfc3394Blocks = mcuxClKey_getSize(wrappedKey) / MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;

  for(int i = (int)keySizeInRfc3394Blocks - 1; i >= 0; --i)
  {
    pData += MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;
    pTargetReg = (uint8_t*)mcuxClSgi_Drv_getAddr(mcuxClSgi_Drv_datinIndexToOffset((uint32_t)i));
    MCUX_CSSL_DI_RECORD(memory_clear_loop_params, pTargetReg);
    MCUX_CSSL_DI_RECORD(memory_clear_loop_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
    MCUXCLMEMORY_CLEAR_INT(pTargetReg, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);

    pTargetReg += MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int_params, pTargetReg);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int_params, pData);
    MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_int_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClMemory_copy_int(pTargetReg, pData, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE));
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAes_rfc3394Utils_loadWrappedKeyData,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int),
    (keySizeInRfc3394Blocks * (
      MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
      + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy_int)
    ))
  );
}

/**
 * @brief Key unwrap function as specified in RFC$lUsing software algorithm
 *        in combination with SGI AES block decrypt operations.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_keyUnwrapRfc3394_swDriven)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyUnwrapRfc3394_swDriven(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t wrappedKey,
  uint32_t *pKeyDst)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAes_keyUnwrapRfc3394_swDriven);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClAes_rfc3394Utils_loadWrappedKeyData(wrappedKey));

  /* Get parameters of already loaded key-wrapping key (KWK) */
  const mcuxClKey_Descriptor_t *keyWrappingKey = mcuxClKey_getKeyDescriptorFromAuxData(wrappedKey);

  const uint32_t jCount = 6U; /* Number of external loop iterations according to RFC$lUnwrap algorithm */
  const uint32_t iCount = mcuxClKey_getSize(wrappedKey) / MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;
  /* t factor to be used within the loop
  *  For first loop iteration according to RFC3394 we can calculate:
  *  t = n*j+i = n*j + n = n*(j+1) = n*6 ==> iCount*jCount */
  uint32_t t = jCount * iCount;

  uint32_t sgiCtrlKey = mcuxClSgi_getKeyConf(keyWrappingKey);
  uint32_t *pResult = mcuxClSgi_Drv_getAddr(MCUXCLSGI_DRV_DATOUT_OFFSET);
  uint32_t *pLowerResultWord = pResult + (MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE >> 2U);
  uint8_t *pLowerResult = (uint8_t*)pLowerResultWord;

  /*******************************************************************************
  * Loops below implement key unwrap RFC3394 algorithm using index based approach
  * One loop iteration (j,i):
  *
  *                          DATIN_i
  *           --------------------------------------
  *           |               t |      R[i]        |
  *           --------------------------------------
  *                             |
  *                             V
  *                            XOR        <-------------
  *           --------------------------------------   |
  *           |     A xor t     |      R[i]        |   |
  *           --------------------------------------   |
  *                             |                      |
  *                             V                      |
  *                          DECRYPT                   |
  *                             |                      |
  *                             V                      |
  *                          DATOUT                    |
  *           --------------------------------------   |
  *           |       A         |        0         |----
  *           --------------------------------------
  ********************************************************************************/

  /* Point to the end of data buffer (wrt. size of unwrapped key),
     unwrapped key will be stored blockwise starting from the right-side */
  uint32_t *pCopyOut = pKeyDst + ((iCount * MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE)>>2U);

  /* Generate seed for SFR masking */
  MCUX_CSSL_FP_FUNCTION_CALL(sfrSeed, mcuxClPrng_generate_word());

  for(uint32_t j = 0U; j < jCount; ++j)
  {
    for(uint32_t i = 0U; i < iCount; ++i)
    {
      /* Set t in the first half of DATIN (starting from the right side of first half as per RFC3349) */
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_loadWord(
        mcuxClSgi_Drv_datinIndexToOffset(i) + sizeof(uint32_t), MCUXCLMEMORY_SWITCH_4BYTE_ENDIANNESS(t)));

      MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, pLowerResult);
      MCUX_CSSL_DI_RECORD(mcuxClMemory_clear_int_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
      MCUXCLMEMORY_CLEAR_INT(pLowerResult, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);

      /* Execute decrypt with DATIN_i xor DATOUT as input */
      /* Each internal (iCount) loop iteration shall use seaprate DATIN slot to minimize number of copy operations
         needed for storing intermediate data in between the loop iterations */
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(
        MCUXCLSGI_DRV_CTRL_END_UP                             |
        MCUXCLSGI_DRV_CTRL_DEC                                |
        MCUXCLSGI_DRV_CTRL_INSEL_XOR_DATOUT_NUMBER_TO_CTRL(i) |
        MCUXCLSGI_DRV_CTRL_OUTSEL_RES                         |
        sgiCtrlKey
      ));

      /* Wait for result before copy out */
      mcuxClSgi_Drv_wait();

      if((jCount - 1U) != j)
      {
        /* Store second half of result (R[i]) in corresponding DATIN register for next external loop iteration */
        uint8_t *pLowerResultStore = (uint8_t *)mcuxClSgi_Drv_getAddr(mcuxClSgi_Drv_datinIndexToOffset(i)) + MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int_params, pLowerResultStore);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int_params, pLowerResult);
        MCUX_CSSL_DI_RECORD(mcuxClMemory_copy_secure_int_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
        MCUXCLMEMORY_COPY_SECURE_INT(pLowerResultStore, pLowerResult, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
      }
      else /* last j-loop iteration */
      {
        /* Store second half of result (R[i]) in the result buffer */
        /* Note: The `sfrSeed` is re-initialized for each block, and the SFR protected unwrapped key is copied to the `pKeyDst`.*/
        pCopyOut -= (MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE >> 2U);
        MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
        MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pLowerResultWord);
        MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pCopyOut);
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copySfrMasked(pCopyOut, pLowerResultWord, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE, sfrSeed));
      }

      /* RFC3394 t = n * j + i calculation equivalent */
      /* The inner loop is executed jCount * iCount times, which is equal to the initialization value of t, i.e. t = 1 before the last decrement */
      MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER_VOID(t, 1U, jCount * iCount)
      --t;
    }
  }

  MCUX_CSSL_DI_RECORD(loop_iteration, t); /* Expected to be 0 */

  /* Check if unwrapped IV matches the reference IV consisting of
     0xA6 bytes of MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE length */
  const uint32_t referenceIvWord = 0xA6A6A6A6U;
  MCUX_CSSL_FP_FUNCTION_CALL(dataoutA, mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 0U));
  MCUX_CSSL_FP_FUNCTION_CALL(dataoutB, mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 4U));
  if(   (referenceIvWord != dataoutA)
     || (referenceIvWord != dataoutB))
  {
    /* Clear the result in case validation fails - No need to balance DI or FP in error cases */
    MCUXCLMEMORY_CLEAR_INT((uint8_t*)pCopyOut, iCount * MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
    MCUXCLSESSION_ERROR(session, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  /* Store the sfrSeed after the SFR-masked plain key */
  uint32_t *pSfrMaskSeed = (&pKeyDst[(wrappedKey->type.size)>>2U]);
  *pSfrMaskSeed = sfrSeed;

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAes_keyUnwrapRfc3394_swDriven,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_rfc3394Utils_loadWrappedKeyData),
    2U * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_storeWord),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClPrng_generate_word),
    /* balance calls in the nested for-loops: */
    ((jCount * iCount) * (
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_loadWord)
      + MCUXCLMEMORY_CLEAR_INT_FP_EXPECT
      + MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start)
    )),
    /* if((jCount - 1U) != j): */
    ((iCount * (jCount - 1U))  * MCUXCLMEMORY_COPY_SECURE_INT_FP_EXPECT),
    /* else: */
    (iCount * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copySfrMasked))
  );
}

/* Flush function for AES keys */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClAes_keyFlush, mcuxClKey_FlushFuncPtr_t)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClAes_keyFlush(
  mcuxClSession_Handle_t session UNUSED_PARAM,
  mcuxClKey_Handle_t key,
  mcuxClKey_Encoding_Spec_t spec UNUSED_PARAM)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClAes_keyFlush);

  /* AES keys are assumed to be in SGI */

  uint32_t keySlot = mcuxClKey_getLoadedKeySlot(key);

  /* Record input data for mcuxClSgi_Drv_flushRegisterBanks() */
  MCUX_CSSL_DI_RECORD(sgiFlush,mcuxClSgi_Drv_keySlotToOffset(keySlot));
  MCUX_CSSL_DI_RECORD(sgiFlush,mcuxClKey_getSize(key));

  if(keySlot >= MCUXCLSGI_DRV_KEY_BANK_COUNT)
  {
    /* Key slot number does not exist in SGI - invalid key object */
    MCUXCLSESSION_ERROR(session, MCUXCLKEY_STATUS_INVALID_INPUT);
  }

  uint32_t numKeyWords = mcuxClKey_getSize(key) / sizeof(uint32_t);
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_flushRegisterBanks(mcuxClSgi_Drv_keySlotToOffset(keySlot), numKeyWords));

  /* Restore the initial state of the key object */
  mcuxClKey_setLoadStatus(key, MCUXCLKEY_LOADSTATUS_NOTLOADED);
  mcuxClKey_setLoadedKeySlot(key, MCUXCLKEY_LOADOPTION_SLOT_INVALID);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClAes_keyFlush,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_flushRegisterBanks)
  );
}




MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()


/**
 * @brief Key encoding descriptor for RFC3394 key wrap/unwrap.
 */
const mcuxClKey_EncodingDescriptor_t mcuxClAes_EncodingDescriptor_Rfc3394 = {
  .loadFunc = mcuxClAes_keyLoad_rfc3394,
  .storeFunc = mcuxClAes_keyStore_rfc3394,
  .flushFunc = mcuxClAes_keyFlush,
  .handleKeyChecksumsFunc = mcuxClKey_handleKeyChecksums_none,
  .protectionToken_loadFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_keyLoad_rfc3394),
  .protectionToken_storeFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_keyStore_rfc3394),
  .protectionToken_flushFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClAes_keyFlush),
  .protectionToken_handleKeyChecksumsFunc = MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClKey_handleKeyChecksums_none)
};




MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
