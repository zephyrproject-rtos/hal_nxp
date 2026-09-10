/*--------------------------------------------------------------------------*/
/* Copyright 2022-2023 NXP                                                  */
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

#include <mcuxClHash.h>
#include <internal/mcuxClHash_Internal.h>
#include <internal/mcuxClHashModes_Internal.h>
#include <internal/mcuxClHashModes_Core_c_sha1.h>

/**********************************************************
 * Defines and Macros
 **********************************************************/

#define MCUXCLHASHMODES_SHA1_CH(x_,y_,z_)   (((x_) & (y_)) ^ ((~(x_)) & (z_)))  ///< Macro for Sha-1 function Ch(x,y,z)

#define MCUXCLHASHMODES_SHA1_PARITY(x_,y_,z_)   ((x_) ^ (y_) ^ ((z_)))  ///< Macro for Sha-1 function Parity(x,y,z)

#define MCUXCLHASHMODES_SHA1_MAJORITY(x_,y_,z_)   (((x_) & (y_)) ^ ((x_) & (z_)) ^ ((y_) & (z_)))  ///< Macro for Sha-1 function Majority(x,y,z)

/**********************************************************
 * Constants
 **********************************************************/

/**
 * @brief Sha-1 constants vector
 */
const static uint32_t mcuxClHashModes_sha1_K[] = {0x5A827999u,
                                                 0x6ED9EBA1u,
                                                 0x8F1BBCDCu,
                                                 0xCA62C1D6u};

/**********************************************************
 * *CORE* layer functions
 **********************************************************/

/**
 * @brief Sha-1 message schedule
 *
 * This function processes the message schedule of the SHA-1 algorithm
 *
 * @param[in/out] pAccBuf  Pointer to the accumulation buffer
 *
 * @return A code-flow protected error code (see @ref mcuxCsslFlowProtection)
 * @retval MCUXCLHASH_STATUS_OK               Hash operation successful
 */
MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_core_c_sha1_messageSchedule)
static inline void mcuxClHashModes_core_c_sha1_messageSchedule(uint32_t *pAccBuf)
{
    for(uint32_t i = 0u; i < (MCUXCLHASH_BLOCK_SIZE_SHA_1/sizeof(uint32_t)); i ++)
    {
        uint32_t tmp = pAccBuf[i]
                     ^ pAccBuf[(i + 2u) & 0xFu]
                     ^ pAccBuf[(i + 8u) & 0xFu]
                     ^ pAccBuf[(i + 13u) & 0xFu];

        pAccBuf[i] = (tmp << 1) | (tmp >> 31);
    }
}


MCUX_CSSL_FP_FUNCTION_DEF(mcuxClHashModes_core_c_sha1)
MCUX_CSSL_FP_PROTECTED_TYPE(mcuxClHash_Status_t) mcuxClHashModes_core_c_sha1(
                                  uint32_t *pState,
                                  uint32_t *pAccBuf)
{
    MCUX_CSSL_FP_FUNCTION_ENTRY(mcuxClHashModes_core_c_sha1);

    /**************************************************************************************
     * Step 1: Load state to working variables
     **************************************************************************************/
    uint32_t a = pState[0];
    uint32_t b = pState[1];
    uint32_t c = pState[2];
    uint32_t d = pState[3];
    uint32_t e = pState[4];

    /**************************************************************************************
     * Step 2: Process iterations
     **************************************************************************************/

    for(uint32_t i = 0u; i < MCUXCLHASHMODES_SHA_1_NO_OF_ROUNDS; i++)
    {
        /* Perform message schedule, before executing round 16 */
        if((0u == (i % 16u)) && (0u != i))
        {
            mcuxClHashModes_core_c_sha1_messageSchedule(pAccBuf);
        }

        uint32_t t = 0u;

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Per SHA1 standard, the result does not wrap.")
        if(20u > i)
        {
            t = mcuxClHashModes_sha1_K[0] + MCUXCLHASHMODES_SHA1_CH(b,c,d);
        }
        else if(40u > i)
        {
            t = mcuxClHashModes_sha1_K[1] + MCUXCLHASHMODES_SHA1_PARITY(b, c, d);
        }
        else if(60u > i)
        {
            t = mcuxClHashModes_sha1_K[2] + MCUXCLHASHMODES_SHA1_MAJORITY(b, c, d);
        }
        else
        {
            t = mcuxClHashModes_sha1_K[3] + MCUXCLHASHMODES_SHA1_PARITY(b, c, d);
        }
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Per SHA1 standard, the result does not wrap.")
        t += ((a << 5u) | (a >> 27u))
          + pAccBuf[i & 0xFu]
          + e;
        MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()

        e = d;
        d = c;
        c = (b << 30u) | (b >> 2u);
        b = a;
        a = t;
    }

    /**************************************************************************************
     * Step 3: Update state variables
     **************************************************************************************/

    MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_OVERFLOW("Per SHA1 standard, the result does not wrap.")
    pState[0] += a;
    pState[1] += b;
    pState[2] += c;
    pState[3] += d;
    pState[4] += e;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_OVERFLOW()

    MCUX_CSSL_FP_FUNCTION_EXIT(mcuxClHashModes_core_c_sha1, MCUXCLHASH_STATUS_OK);
}
