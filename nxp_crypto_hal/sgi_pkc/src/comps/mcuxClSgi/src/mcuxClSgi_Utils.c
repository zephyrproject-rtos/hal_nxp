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

#include <mcuxClAes_Constants.h>
#include <internal/mcuxClKey_Functions_Internal.h>
#include <mcuxClSgi_Constants.h>
#include <mcuxClSgi_Types.h>
#include <internal/mcuxClSgi_Drv.h>
#include <internal/mcuxClSgi_Sfr_RegBank.h>
#include <internal/mcuxClSgi_Utils.h>
#include <mcuxCsslAnalysis.h>
#include <internal/mcuxClDma_Drv.h>

#include <internal/mcuxClResource_Internal_Types.h>

#include <mcuxClBuffer.h>
#include <internal/mcuxClBuffer_Internal.h>
#include <internal/mcuxClSession_Internal.h>
#include <internal/mcuxClSession_Internal_EntryExit.h>
#include <mcuxClSession.h>
#include <internal/mcuxClSession_Internal_Functions.h>

#include <mcuxClCore_Toolchain.h>
#include <mcuxClCore_Macros.h>


/*****************************************************
 * utilHash Constants
 *****************************************************/




/*****************************************************
 * utilHash Functions
 *****************************************************/

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_initSha224, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha224(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_initSha224);

    if(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV == mode)
    {
        /* Configure SHA2-224 in auto mode using standard IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADDATA_USESTANDARDIV));
    }
    else  /* (MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV == mode) */
    {
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pIV);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, MCUXCLSGI_DRV_STATE_SIZE_SHA2_224);

        /* Configure SHA2-224, loading a special IV/state in auto mode */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADIV));

        /* Start SGI SHA2-224 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

        /* Load IV/state to FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo((const uint8_t *)pIV, MCUXCLSGI_DRV_STATE_SIZE_SHA2_224));

        /* Trigger stop (indicate that IV loading has finished) */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

        /* Wait until SGI has loaded IV and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Configure SHA2-224, loading data in auto mode, using the already loaded IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_224_AUTOMODE_LOADDATA_USELOADEDIV));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_initSha224,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2),
      MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV != mode,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2))
      );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_initSha256, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha256(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_initSha256);

    if(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV == mode)
    {
        /* Configure SHA2-256 in auto mode using standard IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADDATA_USESTANDARDIV));
    }
    else /* (MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV == mode) */
    {
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pIV);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_256);

        /* Configure SHA2-256, loading a special IV/state in auto mode */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADIV));

        /* Start SGI SHA2-256 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

        /* Load IV/state to FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo((const uint8_t *)pIV, MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_256));

        /* Trigger stop (indicate that IV loading has finished) */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

        /* Wait until SGI has loaded IV and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Configure SHA2-256, loading data in auto mode, using the already loaded IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_256_AUTOMODE_LOADDATA_USELOADEDIV));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_initSha256,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2),
      MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV != mode,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2))
      );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_initSha384, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha384(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_initSha384);

    if(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV == mode)
    {
        /* Configure SHA2-384 in auto mode using standard IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADDATA_USESTANDARDIV));
    }
    else /* (MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV == mode) */
    {
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pIV);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, MCUXCLSGI_DRV_STATE_SIZE_SHA2_384);

        /* Configure SHA2-384, loading a special IV/state in auto mode */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADIV));

        /* Start SGI SHA2-384 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

        /* Load IV/state to FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo((const uint8_t *)pIV, MCUXCLSGI_DRV_STATE_SIZE_SHA2_384));

        /* Trigger stop (indicate that IV loading has finished) */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

        /* Wait until SGI has loaded IV and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Configure SHA2-384, loading data in auto mode, using the already loaded IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_384_AUTOMODE_LOADDATA_USELOADEDIV));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_initSha384,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2),
      MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV != mode,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2))
      );
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_initSha512, mcuxClSgi_Utils_initHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_initSha512(mcuxClSession_Handle_t session, const uint32_t *pIV, uint32_t mode)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_initSha512);

    if(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV == mode)
    {
        /* Configure SHA2-512 in auto mode using standard IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADDATA_USESTANDARDIV));
    }
    else /* (MCUXCLSGI_UTILS_AUTO_MODE_LOAD_IV == mode) */
    {
        /* Record input data for mcuxClSgi_Utils_loadFifo() */
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, pIV);
        MCUX_CSSL_DI_RECORD(sgiLoadFifo, MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_512);

        /* Configure SHA2-512, loading a special IV/state in auto mode */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADIV));

        /* Start SGI SHA2-512 processing */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_START_SHA2));

        /* Load IV/state to FIFO */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_loadFifo((const uint8_t *)pIV, MCUXCLSGI_DRV_DIGEST_SIZE_SHA2_512));

        /* Trigger stop (indicate that IV loading has finished) */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopSha2());

        /* Wait until SGI has loaded IV and check for SGI SHA error */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_Sha2_wait(session));

        /* Configure SHA2-512, loading data in auto mode, using the already loaded IV */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureSha2(MCUXCLSGI_DRV_CONFIG_SHA2_512_AUTOMODE_LOADDATA_USELOADEDIV));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_initSha512,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2),
      MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_AUTO_MODE_STANDARD_IV != mode,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_loadFifo),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopSha2),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_Sha2_wait),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureSha2))
      );
}



MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_load128BitBlock)
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It defined only once.")
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_load128BitBlock(uint32_t sgisfrDatOffset, const uint8_t *pData)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_load128BitBlock);

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(sgisfrDatOffset, 0U, MCUXCLSGI_DRV_DATIN2_OFFSET)

    /* Record to balance the pointer increments in pSrc and sgisfrDatOffset*/
    MCUX_CSSL_DI_RECORD(inputParam, 32U);

    uint32_t *pDst = mcuxClSgi_Sfr_getAddr(sgisfrDatOffset);
    /* Check if source is word-aligned */
    if (((uintptr_t)pData & 0x3U) == 0U)
    {
      /* Source is aligned - direct word-wise copy */
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData is 32-bit aligned")
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pData of 16 bytes.")
      const uint32_t* pSrcWord = (const uint32_t*)pData;
      *pDst++ = *pSrcWord++;
      *pDst++ = *pSrcWord++;
      *pDst++ = *pSrcWord++;
      *pDst++ = *pSrcWord++;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

      /* pSrcWord would have updated by 16 bytes */
      MCUX_CSSL_DI_EXPUNGE(updatedInputParam, pSrcWord);
    }
    else
    {
      /* Security Note: Unaligned memory access has security implications.
       * The CL ensures less resistance to side-channel attacks in unaligned cases
       * owing to byte-wise memory access. Users must provide aligned buffers when
       * security is a concern. */

      /* Destination is unaligned - use byte-wise stores with intermediate variables */
      uint32_t word = 0U;

      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pData of 16 bytes.")
      word  = (uint32_t)(*pData++);
      word |= ((uint32_t)(*pData++)) << 8U;
      word |= ((uint32_t)(*pData++)) << 16U;
      word |= ((uint32_t)(*pData++)) << 24U;
      *pDst++ = word;

      word  = (uint32_t)(*pData++);
      word |= ((uint32_t)(*pData++)) << 8U;
      word |= ((uint32_t)(*pData++)) << 16U;
      word |= ((uint32_t)(*pData++)) << 24U;
      *pDst++ = word;

      word  = (uint32_t)(*pData++);
      word |= ((uint32_t)(*pData++)) << 8U;
      word |= ((uint32_t)(*pData++)) << 16U;
      word |= ((uint32_t)(*pData++)) << 24U;
      *pDst++ = word;

      word  = (uint32_t)(*pData++);
      word |= ((uint32_t)(*pData++)) << 8U;
      word |= ((uint32_t)(*pData++)) << 16U;
      word |= ((uint32_t)(*pData++)) << 24U;
      *pDst++ = word;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

      /* pData would have updated by 16 bytes */
      MCUX_CSSL_DI_EXPUNGE(updatedInputParam, pData);
    }
    /* pDst would have updated by 16 bytes */
    MCUX_CSSL_DI_EXPUNGE(updatedInputParam, mcuxClSgi_Sfr_getOffset(pDst));
    MCUX_CSSL_DI_EXPUNGE(inputParam, 16U);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_load128BitBlock);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_load_notFull128Block_buffer)
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It defined only once.")
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_load_notFull128Block_buffer(uint32_t sgisfrDatOffset, mcuxCl_InputBuffer_t pData, uint32_t len, uint8_t *pTempBuff)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_load_notFull128Block_buffer);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(sgisfrDatOffset, 0U, MCUXCLSGI_DRV_DATIN2_OFFSET, MCUXCLSGI_STATUS_ERROR)

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClBuffer_read(pData, 0U, pTempBuff, len));

    /* Balance multiple EXPUNGEs of the input params - SGI offset is recorded by caller */
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, pTempBuff);
    MCUX_CSSL_DI_RECORD(mcuxClBuffer_read, 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(sgisfrDatOffset, (uint8_t *)pTempBuff));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_load_notFull128Block_buffer,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClBuffer_read),
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_storeMasked128BitBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storeMasked128BitBlock(mcuxClSession_Handle_t session, uint32_t sgisfrDatOffset, uint8_t* pOut, uint32_t offset, const uint32_t* pXorMask)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_storeMasked128BitBlock);

    MCUX_CSSL_ANALYSIS_ASSERT_PARAMETER(offset, 0U, MCUXCLSGI_DRV_DATOUT_OFFSET, MCUXCLSGI_STATUS_ERROR);

    /* Enable XOR-masking */
    MCUX_CSSL_FP_FUNCTION_CALL(ctrl2backup, mcuxClSgi_Drv_enableXorWrite());

    /* mcuxClSgi_Utils_load128BitBlock will expunge sgisfrDatOffset, pXorMask, 16U */
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_load128BitBlockInputParam, 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_load128BitBlock(sgisfrDatOffset, (const uint8_t*)pXorMask));

    /* mcuxClSgi_Utils_store128BitBlock will expunge sgisfrDatOffset, pOut, offset, 16U */
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_store128BitBlockInputParam, (uint32_t)(MCUXCLSGI_DRV_DATOUT_OFFSET));
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_store128BitBlockInputParam, 16U);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(sgisfrDatOffset, (uint8_t*)(pOut + offset)));

    /* Disable XOR-masking */
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_setCtrl2(ctrl2backup));

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_storeMasked128BitBlock,
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableXorWrite),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_load128BitBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
        MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setCtrl2));
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DECLARED_BUT_NEVER_DEFINED("It is indeed defined.")
MCUX_CSSL_ANALYSIS_START_SUPPRESS_DEFINED_MORE_THAN_ONCE("It defined only once.")
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_store128BitBlock)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_store128BitBlock(uint32_t sgisfrDatOffset, uint8_t *pOut)
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DEFINED_MORE_THAN_ONCE()
MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DECLARED_BUT_NEVER_DEFINED()
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_store128BitBlock);

    MCUX_CSSL_ANALYSIS_COVERITY_ASSERT_FP_VOID(sgisfrDatOffset, 0U, MCUXCLSGI_DRV_DATIN2_OFFSET);

    /* Record to balance the pointer increments in pDst and sgisfrDatOffset*/
    MCUX_CSSL_DI_RECORD(inputParam, 32U);

    uint32_t *pSrc = mcuxClSgi_Sfr_getAddr(sgisfrDatOffset);
    /* Check if destination is word-aligned */
    if (((uintptr_t)pOut & 0x3U) == 0U)
    {
      /* Destination is aligned - can use word writes */
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pOut is 32-bit aligned")
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pOut of 16 bytes.")
      uint32_t *pDstWord = (uint32_t *)pOut;
      *pDstWord++ = *pSrc++;
      *pDstWord++ = *pSrc++;
      *pDstWord++ = *pSrc++;
      *pDstWord++ = *pSrc++;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

      /* pDstWord would have updated by 16 bytes */
      MCUX_CSSL_DI_EXPUNGE(updatedInputParam, pDstWord);
    }
    else
    {
      /* Security Note: Unaligned memory access has security implications.
       * The CL ensures less resistance to side-channel attacks in unaligned cases
       * owing to byte-wise memory access. Users must provide aligned buffers when
       * security is a concern. */

      /* Destination is unaligned - use byte-wise stores with intermediate variables */
      /* Store word 0 */
      uint32_t word = *pSrc++;

      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pOut of 16 bytes.")
      *pOut++ = (uint8_t)(word & 0xFFU);
      *pOut++ = (uint8_t)((word >> 8U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 16U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 24U) & 0xFFU);

      /* Store word 1 */
      word = *pSrc++;
      *pOut++ = (uint8_t)(word & 0xFFU);
      *pOut++ = (uint8_t)((word >> 8U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 16U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 24U) & 0xFFU);

      /* Store word 2 */
      word = *pSrc++;
      *pOut++ = (uint8_t)(word & 0xFFU);
      *pOut++ = (uint8_t)((word >> 8U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 16U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 24U) & 0xFFU);

      /* Store word 3 */
      word = *pSrc++;
      *pOut++ = (uint8_t)(word & 0xFFU);
      *pOut++ = (uint8_t)((word >> 8U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 16U) & 0xFFU);
      *pOut++ = (uint8_t)((word >> 24U) & 0xFFU);
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

      /* pOut would have updated by 16 bytes */
      MCUX_CSSL_DI_EXPUNGE(updatedInputParam, pOut);
    }
    /* pSrc would have updated by 16 bytes */
    MCUX_CSSL_DI_EXPUNGE(updatedInputParam, mcuxClSgi_Sfr_getOffset(pSrc));
    MCUX_CSSL_DI_EXPUNGE(inputParam, 16U);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_store128BitBlock);
}

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_loadFifo)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_loadFifo(const uint8_t *pData, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_loadFifo);
    /* Check if pData is word-aligned */
    if (((uintptr_t)pData & 0x3U) == 0U)
    {
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData is 32-bit aligned")
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pData of length.")
      const uint32_t* pDataWord = (const uint32_t*)pData;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()

      /* Load data to FIFO word-wise */
      for(uint32_t i = 0U; i < (length / sizeof(uint32_t)); i++)
      {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("pData is 32-bit aligned")
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pData of length.")
        mcuxClSgi_Sfr_writeFifoWord(*pDataWord++);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
      }
      /* pDataWord must have incremented by length. */
      MCUX_CSSL_DI_EXPUNGE(inputParam, pDataWord);
    }
    else
    {
      /* pData is not aligned - byte-wise assembly into words. */
      const uint8_t* pDataByte = (const uint8_t*)pData;
      size_t remainingBytes = length;
      while (remainingBytes >= 4U)
      {
        uint32_t word = 0U;
        /* Assemble word from 4 bytes */
        word  = (uint32_t)pDataByte[0];
        word |= ((uint32_t)pDataByte[1]) << 8U;
        word |= ((uint32_t)pDataByte[2]) << 16U;
        word |= ((uint32_t)pDataByte[3]) << 24U;

        mcuxClSgi_Sfr_writeFifoWord(word);
        pDataByte += 4U;
        remainingBytes -= 4U;
      }

      /* Handle remaining bytes */
      if (remainingBytes > 0U)
      {
        uint32_t lastWord = 0U;
        for (size_t i = 0U; i < remainingBytes; i++)
        {
            lastWord |= ((uint32_t)pDataByte[i]) << (i * 8U);
        }
        mcuxClSgi_Sfr_writeFifoWord(lastWord);
      }
      /* Expunge pData and length after processing */
      MCUX_CSSL_DI_EXPUNGE(inputParam, length);
      MCUX_CSSL_DI_EXPUNGE(inputParam, pData);
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_loadFifo);
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_storePartialHash)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storePartialHash(uint32_t *pOutput, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_storePartialHash);

    /* Wait until SGI has finished */
    mcuxClSgi_Drv_wait();

    for(uint32_t i = 0U; i < (length / sizeof(uint32_t)); i++)
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Increment within valid pOutput address")
        MCUX_CSSL_FP_FUNCTION_CALL(ret, mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + (4U * (i & 3U))));
        *pOutput++ = ret;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        if((0x3U == (i & 0x3U)) && ((i + 1U) < (length / sizeof(uint32_t))))
        {
            /* Trigger new output after 4 words are read, if length not yet reached */
            MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_triggerOutput());
            mcuxClSgi_Drv_wait();
        }
    }

    MCUX_CSSL_DI_EXPUNGE(inputParam, pOutput);

    /* Make sure to read the full DATOUT register, perform dummy reads */
    uint32_t processedWords = MCUXCLCORE_NUM_OF_WORDS_CEIL(4U, length);
    for(uint32_t i = (processedWords % 4U); i < 4U; i++)
    {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + 4U * i));
    }

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_storePartialHash,
      (length / sizeof(uint32_t)) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_storeWord),
      ((length / (4U * sizeof(uint32_t))) - 1U) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_triggerOutput),
      (4U - (processedWords % 4U)) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_storeWord));

}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_storeHashResult)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_storeHashResult(mcuxClSession_Handle_t session, mcuxCl_Buffer_t pOutput, uint32_t length)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_storeHashResult);

    /* Wait until SGI has finished */
    mcuxClSgi_Drv_wait();

    uint32_t remainingLength = length;

    /* Process the result in 16 bytes' multiple */
    while (16U <= remainingLength)
    {
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_store128BitBlockBalancing, MCUXCLSGI_DRV_DATOUT_OFFSET);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_store128BitBlockBalancing, pOutput);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_store128BitBlockBalancing, 16U);
      /* By casting to uint8_t* we break the buffer abstraction, however this has no effect for the buffer pointer backend. */
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_store128BitBlock(MCUXCLSGI_DRV_DATOUT_OFFSET,(uint8_t*)pOutput));

      pOutput += 16U;
      remainingLength -= 16U;
      if(remainingLength > 0U)
      {
        /* Trigger new output after 4 words are read, if length not yet reached */
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_triggerOutput());
        mcuxClSgi_Drv_wait();
        }
    }

    /* Process the hash size is not a multiple of 16 */
    if (0U < remainingLength)
    {
      /* The output length is always a multiple of 4 */
      uint32_t offset = 0U;
      while (offset < remainingLength)
      {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_UNALIGNED_ACCESS()
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("offset calculation cannot wrap")
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Pointer is not overflowed")
        uint32_t word = mcuxClSgi_Sfr_readWord(MCUXCLSGI_DRV_DATOUT_OFFSET + offset);
        /* Store word */
        pOutput[0] = (uint8_t)(word & 0xFFU);
        pOutput[1] = (uint8_t)((word >> 8U) & 0xFFU);
        pOutput[2] = (uint8_t)((word >> 16U) & 0xFFU);
        pOutput[3] = (uint8_t)((word >> 24U) & 0xFFU);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_UNALIGNED_ACCESS()

        pOutput += sizeof(uint32_t);
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("offset calculation cannot wrap")
        offset += sizeof(uint32_t);
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
      }

      remainingLength -= offset;
      /* Make sure to read the full DATOUT register, perform dummy reads */
      for(uint32_t i = (remainingLength / 4U); i < 4U; i++)
      {
        MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_storeWord(MCUXCLSGI_DRV_DATOUT_OFFSET + (4U * i)));
      }
    }
    MCUX_CSSL_DI_EXPUNGE(storeHashResultBalancing, pOutput);
    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_storeHashResult,
      (MCUXCLCORE_NUM_OF_WORDS_FLOOR(16U, length)) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_store128BitBlock),
      (MCUXCLCORE_NUM_OF_WORDS_CEIL(16U, length) - 1U) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_triggerOutput),
      MCUX_CSSL_FP_CONDITIONAL((length % 16U) != 0U,
        (4U - (remainingLength / 4U)) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_storeWord)));
}


/** Configure the SGI in AUTO mode. Use two DMA channels to tranfer data to/from SGI.
    Use SGI/DMA Handshake signals to coordinate the communication. */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_startAutoModeWithHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_startAutoModeWithHandshakes(
  uint32_t operation,
  uint32_t enableOutputHandshake)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_startAutoModeWithHandshakes);

  /* Configure and start the SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(operation));

  /* Enable the handshake signal(s) - will start the DMA input channel to start writing data to the SGI DATIN */
  if(MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_ENABLE == enableOutputHandshake)
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableDmaHandshakes());
  }
  else
  {
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_enableInputDmaHandshake());
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_startAutoModeWithHandshakes,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_ENABLE == enableOutputHandshake,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableDmaHandshakes)),
    MCUX_CSSL_FP_CONDITIONAL(MCUXCLSGI_UTILS_OUTPUT_HANDSHAKE_ENABLE != enableOutputHandshake,
      MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableInputDmaHandshake)));
}

/** Stop and disable the SGI AUTO mode, disable handshakes for DMA channel in the SGI/DMA/SCM */
MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes(
  mcuxClSession_Channel_t inputChannel)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes);

  /* AUTO mode needs to be stopped by software */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopAndDisableAutoMode());

  /* Disable DMA handshakes in the SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableDmaHandshakes());

  /* Disable DMA handshaking */
  mcuxClDma_Sfr_setSrcSelect(inputChannel, MCUXCLDMA_DRV_HWREQ_SRC_DISABLED);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaInputHandshakes,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableDmaHandshakes));
}

/** Stop and disable the SGI AUTO mode, disable handshakes for both DMA channels in the SGI/DMA/SCM */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes(
  mcuxClSession_Channel_t inputChannel,
  mcuxClSession_Channel_t outputChannel)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes);

  /* AUTO mode needs to be stopped by software */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_stopAndDisableAutoMode());

  /* Disable DMA handshakes in the SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_disableDmaHandshakes());

  /* Disable DMA handshaking */
  mcuxClDma_Sfr_setSrcSelect(inputChannel, MCUXCLDMA_DRV_HWREQ_SRC_DISABLED);
  mcuxClDma_Sfr_setSrcSelect(outputChannel, MCUXCLDMA_DRV_HWREQ_SRC_DISABLED);

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_stopAutoModeWithDmaHandshakes,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_stopAndDisableAutoMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_disableDmaHandshakes));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_Uninit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_Uninit(mcuxClSession_Handle_t session)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_Uninit);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClResource_release(session->pResourceCtx, MCUXCLRESOURCE_HWID_SGI));

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_RETURN_CODE_NOT_CHECKED("Return code is checked in every call to this function")
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_RETURN_CODE_NOT_CHECKED()

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_Uninit,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClResource_release),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_copySfrMasked)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_copySfrMasked(uint32_t *pDst, const uint32_t *pSrc, uint32_t length, uint32_t sfrSeed)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_copySfrMasked);

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  uint32_t sfrSeedBackup = mcuxClSgi_Sfr_readSfrSeed();
#endif

  MCUX_CSSL_FP_FUNCTION_CALL(ctrl2Backup, mcuxClSgi_Drv_enableMasking(MCUXCLSGI_DRV_MASKING_SFR, sfrSeed));

  MCUX_CSSL_DI_RECORD(loopIncrement,length);
  for (uint32_t i = 0U; i < length / sizeof(uint32_t); i++)
  {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pDst and pSrc of length.")
    *pDst++ = *pSrc++;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
  }

  MCUX_CSSL_DI_EXPUNGE(inputParam, pDst);
  MCUX_CSSL_DI_EXPUNGE(inputParam, pSrc);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_setCtrl2(ctrl2Backup));

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  mcuxClSgi_Sfr_writeSfrSeed(sfrSeedBackup);
#endif

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_copySfrMasked,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableMasking),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setCtrl2));
}

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_copyBlockSfrMasked)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_copyBlockSfrMasked(uint32_t *pDst, const uint32_t *pSrc, uint32_t sfrSeed)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_copyBlockSfrMasked);

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  uint32_t sfrSeedBackup = mcuxClSgi_Sfr_readSfrSeed();
#endif

  MCUX_CSSL_FP_FUNCTION_CALL(ctrl2Backup, mcuxClSgi_Drv_enableMasking(MCUXCLSGI_DRV_MASKING_SFR, sfrSeed));

  MCUX_CSSL_DI_RECORD(loopIncrement, MCUXCLAES_BLOCK_SIZE);

  /* Fixed length copy of 16 bytes (4 words) - no loop needed */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Caller shall provide valid buffer pDst and pSrc of 16 bytes.")
  *pDst++ = *pSrc++;
  *pDst++ = *pSrc++;
  *pDst++ = *pSrc++;
  *pDst++ = *pSrc++;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_DI_EXPUNGE(inputParam, pDst);
  MCUX_CSSL_DI_EXPUNGE(inputParam, pSrc);

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_setCtrl2(ctrl2Backup));

#ifdef MCUXCL_FEATURE_PRNG_SGI_SFRSEED
  mcuxClSgi_Sfr_writeSfrSeed(sfrSeedBackup);
#endif

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_copyBlockSfrMasked,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_enableMasking),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_setCtrl2));
}


#if defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING)
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_decrement128Bit)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_decrement128Bit(uint32_t srcSfrDatOffset, uint32_t dstSfrDatOffset)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_decrement128Bit);
    /* Balance the offset increments*/
    MCUX_CSSL_DI_RECORD(offsetIncrements, 24U);

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset calculations cannot wrap")
    mcuxClSgi_Sfr_writeWord(dstSfrDatOffset, mcuxClSgi_Sfr_readWord(srcSfrDatOffset));
    dstSfrDatOffset += 4U;
    srcSfrDatOffset += 4U;
    mcuxClSgi_Sfr_writeWord(dstSfrDatOffset, mcuxClSgi_Sfr_readWord(srcSfrDatOffset));
    dstSfrDatOffset += 4U;
    srcSfrDatOffset += 4U;
    mcuxClSgi_Sfr_writeWord(dstSfrDatOffset, mcuxClSgi_Sfr_readWord(srcSfrDatOffset));
    dstSfrDatOffset += 4U;
    srcSfrDatOffset += 4U;
    mcuxClSgi_Sfr_writeWord(dstSfrDatOffset, mcuxClSgi_Sfr_readWord(srcSfrDatOffset));
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    const uint32_t wordSize = 4U;
    const uint32_t leastWordOffset = 12U;
    uint32_t wordOffset = 0U;
    uint32_t dataWord = 0U;

    while ((wordOffset <= leastWordOffset) && (dataWord == 0U))
    {
        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Calculated offset doesn't wrap.")
        uint32_t dataOffset = dstSfrDatOffset - wordOffset; // dstSfrDatOffset has incremented by leastWordOffset
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        dataWord = mcuxClSgi_Sfr_readWord(dataOffset);

        if (dataWord == 0U)
        {
            mcuxClSgi_Sfr_writeWord(dataOffset, 0xffffffffU);
        }
        else
        {
            const uint32_t decreasedWord = mcuxCl_Core_Swap32(mcuxCl_Core_Swap32(dataWord) - 1U);
            mcuxClSgi_Sfr_writeWord(dataOffset, decreasedWord);
        }

      wordOffset += wordSize;
    }

    MCUX_CSSL_DI_EXPUNGE(inputParam, srcSfrDatOffset);
    MCUX_CSSL_DI_EXPUNGE(inputParam, dstSfrDatOffset);

    MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_decrement128Bit);
}
#endif /* defined(MCUXCL_FEATURE_CIPHERMODES_DMA_NONBLOCKING) && defined(MCUXCL_FEATURE_CIPHERMODES_CTR) */

MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_keyUnwrapRfc3394)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_keyUnwrapRfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_keyUnwrapRfc3394);

  /* Determine the auto mode for key wrap depending on the size of the key material */
  mcuxClKey_Size_t plainKeyMaterialSize = mcuxClKey_getSize(key);
  uint32_t keyWrapConfig = 0U;
  if(MCUXCLAES_AES128_KEY_SIZE == plainKeyMaterialSize)
  {
    keyWrapConfig = MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_128;
  }
  else if(MCUXCLAES_AES256_KEY_SIZE == plainKeyMaterialSize)
  {
    keyWrapConfig = MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_256;
  }
  else
  {
    /* Aes-192 is not supported */
    MCUXCLSESSION_ERROR(session, MCUXCLSGI_STATUS_KEYSIZE_NOT_SUPPORTED);
  }

  /* The key-wrapping key (kwk) is stored as a pointer to a full key descriptor in the key handle's auxData buffer. */
  const mcuxClKey_Descriptor_t *kwk = mcuxClKey_getKeyDescriptorFromAuxData(key);

  /* Configure the SGI: Perform a key unwrap with the associated kwk */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(keyWrapConfig));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_KEY_UNWRAP | mcuxClSgi_getKeyConf(kwk)));

  /* Load the wrapped key material to DATIN0/DATIN1(/DATIN2) after the operation was started */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_UNALIGNED_ACCESS()
  uint32_t *pWrappedKeyData = (uint32_t *) mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_UNALIGNED_ACCESS()

  if (((uintptr_t)pWrappedKeyData & 0x3U) != 0U)
  {
    /* Unaligned access is not supported */
    MCUXCLSESSION_ERROR(session, MCUXCLSGI_STATUS_UNALIGNED_ACCESS_NOT_SUPPORTED);
  }

  uint32_t wrappedKeySize = plainKeyMaterialSize + MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE;
  MCUX_CSSL_FP_LOOP_DECL(wrappedKeyLoop);
  for(uint32_t i = 0U; i < wrappedKeySize / sizeof(uint32_t); i++)
  {
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset calculations cannot wrap")
    mcuxClSgi_Sfr_writeWord(MCUXCLSGI_SFR_DATIN0_OFFSET + (i * sizeof(uint32_t)), pWrappedKeyData[i]);
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
    MCUX_CSSL_FP_LOOP_ITERATION(wrappedKeyLoop);
  }

  /* Wait for the SGI to finish the key wrap */
  mcuxClSgi_Drv_wait();

  /* Disable the AUTO mode */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_resetAutoMode());

  /* The unwrapped key material is now in the key register bank that is fixed in hardware
   * for each platform. See MCUXCLKEY_LOADOPTION_SLOT_SGI_KEY_UNWRAP.
   * Even if the unwrapping was invalid, the invalid unwrapped material will be placed in this
   * key register. */

  /* Check for unwrapping errors - the SGI checks internally whether the RFC3394 IV is correct.
   * When MCUXCLSGI_SFR_STATUS_HAS_KEY_UNWRAP_ERROR is raised, an SGI reset or FULL_FLUSH has to be performed
   * because this error is sticky. As we never perform any FULL_FLUSH in the SGI due to pre-loaded keys,
   * it is user responsibility to perform a reset or FULL_FLUSH on MCUXCLSGI_STATUS_UNWRAP_ERROR.
   */
  uint32_t sgiStatus = mcuxClSgi_Sfr_readStatus();
  if(MCUXCLSGI_SFR_STATUS_HAS_KEY_UNWRAP_ERROR(sgiStatus))
  {
    MCUXCLSESSION_ERROR(session, MCUXCLSGI_STATUS_UNWRAP_ERROR);
  }

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_keyUnwrapRfc3394,
    MCUX_CSSL_FP_LOOP_ITERATIONS(wrappedKeyLoop, wrappedKeySize / sizeof(uint32_t)),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_resetAutoMode));
}

/**
 * @brief This function performs RFC3394 key wrapping with the SGI.
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClSgi_Utils_keyWrapRfc3394)
MCUX_CSSL_FP_PROTECTED_TYPE(void) mcuxClSgi_Utils_keyWrapRfc3394(
  mcuxClSession_Handle_t session,
  mcuxClKey_Handle_t key,
  const uint8_t* pKeyMaterial,
  const uint32_t* pSfrSeed
)
{
  MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClSgi_Utils_keyWrapRfc3394);

  if (((uintptr_t)pKeyMaterial & 0x3U) != 0U)
  {
    /* Unaligned access is not supported */
    MCUXCLSESSION_ERROR(session, MCUXCLSGI_STATUS_UNALIGNED_ACCESS_NOT_SUPPORTED);
  }

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_UNALIGNED_ACCESS()
  const uint32_t *pKeyMaterial32 = (const uint32_t *)pKeyMaterial;
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_UNALIGNED_ACCESS()

  /* Expunged below after increasing the pointer and writing the wrapped KeyData */
  MCUX_CSSL_DI_RECORD(pKeyDest_length, mcuxClKey_getKeyData(key));
  MCUX_CSSL_DI_RECORD(pKeyDest_length, mcuxClKey_getSize(key) + MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);

  /* Determine the auto mode for key wrap depending on the size of the key material */
  mcuxClKey_Size_t plainKeyMaterialSize = mcuxClKey_getSize(key);
  uint32_t keyWrapConfig = 0U;
  if(MCUXCLAES_AES128_KEY_SIZE == plainKeyMaterialSize)
  {
    keyWrapConfig = MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_128;
  }
  else if(MCUXCLAES_AES256_KEY_SIZE == plainKeyMaterialSize)
  {
    keyWrapConfig = MCUXCLSGI_DRV_CONFIG_AUTO_MODE_ENABLE_KEYWRAP_256;
  }
  else
  {
    /* Aes-192 is not supported */
    MCUXCLSESSION_ERROR(session, MCUXCLSGI_STATUS_KEYSIZE_NOT_SUPPORTED);
  }

  /* Initialize the SGI */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_init(MCUXCLSGI_DRV_BYTE_ORDER_LE));

  /* The key-wrapping key (kwk) is stored as a pointer to a full key descriptor in the key handle's auxData buffer. */
  const mcuxClKey_Descriptor_t *kwk = mcuxClKey_getKeyDescriptorFromAuxData(key);

  /* Configure the SGI: Perform a key unwrap with the associated kwk */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_configureAutoMode(keyWrapConfig));
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_start(MCUXCLSGI_DRV_CTRL_KEY_WRAP | mcuxClSgi_getKeyConf(kwk)));

  /* Get the pointer to DATIN0 (and DATIN1) to load the key material */
  uint32_t *pDATIN0A = mcuxClSgi_Sfr_getAddr(MCUXCLSGI_SFR_DATIN0_OFFSET);
  uint32_t *pDATIN0C = (pDATIN0A + 2U);
  uint32_t *pDATIN1A = mcuxClSgi_Sfr_getAddr(MCUXCLSGI_SFR_DATIN1_OFFSET);
  uint32_t *pDATIN1C = (pDATIN1A + 2U);

  /* Load the key material depending on the on the pSfrSeed value. For a plain key the pSfrSeed is
     NULL, and for a protected key the pSfrSeed is not NULL and contains the seed for SFR masking. */
  MCUX_CSSL_FP_LOOP_DECL(plainKeyLoop);
  if (NULL == pSfrSeed)
  {
    /* Plain key - load as is */
    for(uint32_t i = 0U; i < plainKeyMaterialSize / sizeof(uint32_t); i++)
    {
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("offset calculations cannot wrap")
      mcuxClSgi_Sfr_writeWord(MCUXCLSGI_SFR_DATIN0_OFFSET + (i * sizeof(uint32_t)),pKeyMaterial32[i]);
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()
      MCUX_CSSL_FP_LOOP_ITERATION(plainKeyLoop);
    }
  }
  else
  {
    /* Protected key - load using the special SFR Masking as produced by `mcuxClAes_keyUnwrapRfc3394_swDriven`. */

    /* Copy the SFRMask */
    uint32_t sfrMaskingSeed = *pSfrSeed;

    /* Load the (first) 128-bits of the key */
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("parameters are 32 bit aligned")
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pDATIN0A);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pKeyMaterial32);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copySfrMasked(pDATIN0A, pKeyMaterial32, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE, sfrMaskingSeed));

    pKeyMaterial32 += MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE / sizeof(uint32_t);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pDATIN0C);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pKeyMaterial32);
    MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copySfrMasked(pDATIN0C, pKeyMaterial32, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE, sfrMaskingSeed));

    if (MCUXCLAES_AES256_KEY_SIZE == plainKeyMaterialSize)
    {
      /* If the key material size is 256bits, load the remaining 128-bits */
      pKeyMaterial32 += MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE / sizeof(uint32_t);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pDATIN1A);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pKeyMaterial32);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copySfrMasked(pDATIN1A, pKeyMaterial32, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE, sfrMaskingSeed));

      pKeyMaterial32 += MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE / sizeof(uint32_t);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pDATIN1C);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, pKeyMaterial32);
      MCUX_CSSL_DI_RECORD(mcuxClSgi_Utils_copySfrMasked_params, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE);
      MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Utils_copySfrMasked(pDATIN1C, pKeyMaterial32, MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE, sfrMaskingSeed));
    }
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  }

  /* Wait for the SGI to finish the key wrap */
  mcuxClSgi_Drv_wait();

  /* Read the result of the key wrap from the KEY_WRAP SFR.
   * The result size is the key material size + 8 bytes (MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE).
   * The SGI updates the SFR after each access until the full wrapped key is read. */

  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_CASTING("Key data has to be aligned per CL use guidance.")
  uint32_t* pKeyDest = (uint32_t*) mcuxClKey_getKeyData(key);
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_CASTING()
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("pKeyDest++ cannot overflow, because CL user guidance ensures that the Key data is within a valid memory region far below address UINT32_MAX.")

  /* TODO CLNS-16308: use new copy function here */
  MCUX_CSSL_ANALYSIS_START_SUPPRESS_POINTER_INCOMPATIBLE("The pointer pKeyDest is aligned and the access using pKeyDest is valid")
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();

  if(MCUXCLAES_AES256_KEY_SIZE == plainKeyMaterialSize)
  {
    *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
    *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
    *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
    *(pKeyDest++) = mcuxClSgi_Sfr_readWrappedKeyWord();
  }
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_POINTER_INCOMPATIBLE()
  MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

  MCUX_CSSL_DI_EXPUNGE(pKeyDest_length, pKeyDest);

  /* Disable the AUTO mode */
  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_resetAutoMode());

  MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClSgi_Drv_close(session));

  MCUX_CSSL_FP_FUNCTION_EXIT_VOID(mcuxClSgi_Utils_keyWrapRfc3394,
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_init),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_configureAutoMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_start),
    MCUX_CSSL_FP_CONDITIONAL((NULL != pSfrSeed),
      ((mcuxClKey_getSize(key) / MCUXCLAES_ENCODING_RFC3394_BLOCK_SIZE) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Utils_copySfrMasked))
    ),
    MCUX_CSSL_FP_CONDITIONAL((NULL == pSfrSeed),
      MCUX_CSSL_FP_LOOP_ITERATIONS(plainKeyLoop, plainKeyMaterialSize / sizeof(uint32_t))
    ),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_resetAutoMode),
    MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClSgi_Drv_close)
  );
}
