/*--------------------------------------------------------------------------*/
/* Copyright 2014-2019, 2021-2024 NXP                                       */
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

/**
 *
 * @file: mcuxClOsccaSm4_Core.c
 * @brief: Implementation of OSCCA SM4 Core.
 *
 */

#include <mcuxClMemory.h>
#include <mcuxClOscca_Memory.h>
#include <internal/mcuxClOsccaSm4_Internal.h>
#include <mcuxCsslFlowProtection.h>
#include <mcuxClOscca_FunctionIdentifiers.h>

#ifdef MCUXCL_FEATURE_HW_SAFO_SM4
#include <mcuxClOsccaSafo.h>
#endif

#ifdef MCUXCL_FEATURE_HW_SAFO_SM4
#else
/**
 * \brief The Linear substitution function
 *
 * \returns 32-bit output word
 *
 * \param [IN] B 32-bit input word to be transformed
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm4_L) /* No semicolon */
static inline MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClOsccaSm4_L(uint32_t B)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm4_L);
    uint32_t L = (B ^ MCUXCLOSCCASM4_ROTATE_LEFT_UINT32(B, 2U)
      ^ MCUXCLOSCCASM4_ROTATE_LEFT_UINT32(B, 10U)
      ^ MCUXCLOSCCASM4_ROTATE_LEFT_UINT32(B, 18U)
      ^ MCUXCLOSCCASM4_ROTATE_LEFT_UINT32(B, 24U));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm4_L, L);
}

/**
 * \brief The Mixer-substitution function
 *
 * \returns 32-bit output word
 *
 * \param [IN] X 32-bit input word to be transformed
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm4_T) /* No semicolon */
static inline MCUX_CSSL_FP_PROTECTED_TYPE(uint32_t) mcuxClOsccaSm4_T(uint32_t X)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm4_T,MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_Tau),
                                                MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_L));
    MCUX_CSSL_FP_FUNCTION_CALL(output_Tau, mcuxClOsccaSm4_Tau(X));
    MCUX_CSSL_FP_FUNCTION_CALL(output_L, mcuxClOsccaSm4_L(output_Tau));
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm4_T, output_L);
}
#endif

#ifdef MCUXCL_FEATURE_HW_SAFO_SM4
/**
 * \brief This function encrypts/decrypts one block of data using SAFO SGI SM4
 *
 * \param pRoKeys not used in SGI
 * \param pIn Pointer to the input (plaintext)
 * \param pOut Pointer to the result (ciphertext)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm4_Engine)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm4_Status_t) mcuxClOsccaSm4_Engine(
  uint32_t * const pRoKeys,
  const uint8_t * const pIn,
  uint8_t * const pOut,
  uint32_t direction
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm4_Engine);

    /* First load key to Safo SGI. note: the pRoKeys is indeed master key for SGI implementation */

    (void)mcuxClOsccaSafo_Drv_setByteOrder(MCUXCLOSCCASAFO_DRV_BYTE_ORDER_LE);

    /* Load key data */
    mcuxClOsccaSafo_Drv_loadKey(0u, pRoKeys[3]);
    mcuxClOsccaSafo_Drv_loadKey(1u, pRoKeys[2]);
    mcuxClOsccaSafo_Drv_loadKey(2u, pRoKeys[1]);
    mcuxClOsccaSafo_Drv_loadKey(3u, pRoKeys[0]);

    /* Second process the plain data */
    uint32_t inOutData[MCUXCLOSCCASM4_BLOCK_SIZE/sizeof(uint32_t)];
    MCUXCLMEMORY_FP_MEMORY_COPY((uint8_t *)inOutData, pIn, MCUXCLOSCCASM4_BLOCK_SIZE);

    /* Load plain data */
    mcuxClOsccaSafo_Drv_load(0u, inOutData[3]);
    mcuxClOsccaSafo_Drv_load(1u, inOutData[2]);
    mcuxClOsccaSafo_Drv_load(2u, inOutData[1]);
    mcuxClOsccaSafo_Drv_load(3u, inOutData[0]);

    /* Configure encryption or decryption */
    uint32_t sgi_ctrl = (direction == MCUXCLOSCCASM4_ENCRYPT) ? MCUXCLOSCCASAFO_DRV_CTRL_ENC : MCUXCLOSCCASAFO_DRV_CTRL_DEC;
    /* start SAFO operation */
    mcuxClOsccaSafo_Drv_start(sgi_ctrl                       |
                     MCUXCLOSCCASAFO_DRV_CTRL_SM4_EN         |         // enable SM4 kernel
                     MCUXCLOSCCASAFO_DRV_CTRL_SM4            |         // SM4 operation
                     MCUXCLOSCCASAFO_DRV_CTRL_INSEL_DATIN0   |         // data in selection
                     MCUXCLOSCCASAFO_DRV_CTRL_OUTSEL_RES     |         // data out selection
                     MCUXCLOSCCASAFO_DRV_CTRL_INKEYSEL(0u)   |         // key selection
                     MCUXCLOSCCASAFO_DRV_CTRL_END_UP                   // kernel data out option
                     );

    /* Wait for finished */
    mcuxClOsccaSafo_Drv_wait();

    /* Read back the output */
    inOutData[3] = mcuxClOsccaSafo_Drv_store(0u);
    inOutData[2] = mcuxClOsccaSafo_Drv_store(1u);
    inOutData[1] = mcuxClOsccaSafo_Drv_store(2u);
    inOutData[0] = mcuxClOsccaSafo_Drv_store(3u);

    MCUXCLMEMORY_FP_MEMORY_COPY(pOut, (uint8_t *)inOutData, MCUXCLOSCCASM4_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm4_Engine, MCUXCLOSCCASM4_STATUS_CRYPT_OK,
                    (2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)));
}

#else

#define SM4_REDUNDANT_4ROUNDS_AND_COMPARE() \
    do \
    { \
        MCUX_CSSL_FP_FUNCTION_CALL(output_a0, mcuxClOsccaSm4_T(z[1] ^ z[2] ^ z[3] ^ *pRoundKeys)); \
        MCUX_CSSL_FP_FUNCTION_CALL(output_b0, mcuxClOsccaSm4_T(z1[1] ^ z1[2] ^ z1[3] ^ *pRoundKeys)); \
        z[0] = z[0] ^ output_a0; \
        z1[0] = z1[0] ^ output_b0; \
        pRoundKeys += 1u; \
        MCUX_CSSL_FP_FUNCTION_CALL(output_a1, mcuxClOsccaSm4_T(z[2] ^ z[3] ^ z[0] ^ *pRoundKeys)); \
        MCUX_CSSL_FP_FUNCTION_CALL(output_b1, mcuxClOsccaSm4_T(z1[2] ^ z1[3] ^ z1[0] ^ *pRoundKeys)); \
        z[1] = z[1] ^ output_a1; \
        z1[1] = z1[1] ^ output_b1; \
        pRoundKeys += 1u; \
        MCUX_CSSL_FP_FUNCTION_CALL(output_a2, mcuxClOsccaSm4_T(z[3] ^ z[0] ^ z[1] ^ *pRoundKeys)); \
        MCUX_CSSL_FP_FUNCTION_CALL(output_b2, mcuxClOsccaSm4_T(z1[3] ^ z1[0] ^ z1[1] ^ *pRoundKeys)); \
        z[2] = z[2] ^ output_a2; \
        z1[2] = z1[2] ^ output_b2; \
        pRoundKeys += 1u; \
        MCUX_CSSL_FP_FUNCTION_CALL(output_a3, mcuxClOsccaSm4_T(z[0] ^ z[1] ^ z[2] ^ *pRoundKeys)); \
        MCUX_CSSL_FP_FUNCTION_CALL(output_b3, mcuxClOsccaSm4_T(z1[0] ^ z1[1] ^ z1[2] ^ *pRoundKeys)); \
        z[3] = z[3] ^ output_a3; \
        z1[3] = z1[3] ^ output_b3; \
        pRoundKeys += 1u; \
        MCUX_CSSL_FP_FUNCTION_CALL(compare_result, mcuxCsslMemory_Compare( \
          mcuxCsslParamIntegrity_Protect(3u, tempBuffer, tempBuffer1, MCUXCLOSCCASM4_BLOCK_SIZE), \
          (uint8_t*)tempBuffer, (uint8_t*)tempBuffer1, MCUXCLOSCCASM4_BLOCK_SIZE)); \
        if (MCUXCSSLMEMORY_STATUS_EQUAL != compare_result) \
        { \
            MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm4_Engine, MCUXCLOSCCASM4_STATUS_FAULT_ATTACK); \
        } \
    } while(false)

/**
 * \brief This function encrypts/decrypts one block of data using algorithm OSCCA SM4
 *
 * \param pRoKeys Pointer to round keys
 * \param pIn Pointer to the input (plaintext)
 * \param pOut Pointer to the result (ciphertext)
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClOsccaSm4_Engine)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClOsccaSm4_Status_t) mcuxClOsccaSm4_Engine(
  uint32_t * const pRoKeys,
  const uint8_t * const pIn,
  uint8_t * const pOut,
  uint32_t direction
)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClOsccaSm4_Engine);

    /* Avoid building error of unused parameter */
    (void)direction;

    uint32_t *pRoundKeys = (uint32_t *)pRoKeys;
    /* Create temporary buffer for the Crypt operation (alignment limitation) */
    uint32_t tempBuffer[MCUXCLOSCCASM4_BLOCK_SIZE/sizeof(uint32_t)];
    uint32_t tempBuffer1[MCUXCLOSCCASM4_BLOCK_SIZE/sizeof(uint32_t)];

    /* Initialize the temporary buffer */
    MCUXCLMEMORY_FP_MEMORY_COPY((uint8_t*)tempBuffer, pIn, MCUXCLOSCCASM4_BLOCK_SIZE);
    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_switch_endianness(tempBuffer, MCUXCLOSCCASM4_BLOCK_SIZE));
    MCUXCLMEMORY_FP_MEMORY_COPY(tempBuffer1, tempBuffer, MCUXCLOSCCASM4_BLOCK_SIZE);

    uint32_t *z = tempBuffer;
    uint32_t temp = z[0];
    z[0]  = z[3];
    z[3]  = temp;
    temp = z[1];
    z[1]  = z[2];
    z[2]  = temp;

    uint32_t *z1 = tempBuffer1;
    temp = z1[0];
    z1[0]  = z1[3];
    z1[3]  = temp;
    temp = z1[1];
    z1[1]  = z1[2];
    z1[2]  = temp;

    SM4_REDUNDANT_4ROUNDS_AND_COMPARE();

    for(uint8_t i = 4u; i < MCUXCLOSCCASM4_RK_WORDS - 4u; i += 4u)
    {
        MCUX_CSSL_FP_FUNCTION_CALL(output_0, mcuxClOsccaSm4_T(z[1] ^ z[2] ^ z[3] ^ *pRoundKeys));
        z[0] = z[0] ^ output_0;
        pRoundKeys += 1u;
        MCUX_CSSL_FP_FUNCTION_CALL(output_1, mcuxClOsccaSm4_T(z[2] ^ z[3] ^ z[0] ^ *pRoundKeys));
        z[1] = z[1] ^ output_1;
        pRoundKeys += 1u;
        MCUX_CSSL_FP_FUNCTION_CALL(output_2, mcuxClOsccaSm4_T(z[3] ^ z[0] ^ z[1] ^ *pRoundKeys));
        z[2] = z[2] ^ output_2;
        pRoundKeys += 1u;
        MCUX_CSSL_FP_FUNCTION_CALL(output_3, mcuxClOsccaSm4_T(z[0] ^ z[1] ^ z[2] ^ *pRoundKeys));
        z[3] = z[3] ^ output_3;
        pRoundKeys += 1u;
    }

    MCUXCLMEMORY_FP_MEMORY_COPY(tempBuffer1, tempBuffer, MCUXCLOSCCASM4_BLOCK_SIZE);
    SM4_REDUNDANT_4ROUNDS_AND_COMPARE();

    MCUX_CSSL_FP_FUNCTION_CALL_VOID(mcuxClOscca_switch_endianness(tempBuffer, MCUXCLOSCCASM4_BLOCK_SIZE));

    /* Copy data from the temporary buffer to the output buffer
     * and reverse order
     * */
    MCUXCLMEMORY_FP_MEMORY_COPY(pOut, (uint8_t*)tempBuffer, MCUXCLOSCCASM4_BLOCK_SIZE);

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClOsccaSm4_Engine, MCUXCLOSCCASM4_STATUS_CRYPT_OK,
                    (4u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy)),
                    (2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOscca_switch_endianness)),
                    (2u * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxCsslMemory_Compare)),
                    /* RK_WORDS normal rounds + first 4 redundant rounds + last 4 redundant rounds */
                    (MCUXCLOSCCASM4_RK_WORDS + 8u) * MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClOsccaSm4_T));
}
#endif
