/*--------------------------------------------------------------------------*/
/* Copyright 2023 NXP                                                       */
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


#include <mcuxClMemory.h>
#include <mcuxClPsaDriver.h>
#include <mcuxClRsa.h>
#include <mcuxCsslFlowProtection.h>
#include <internal/mcuxClPsaDriver_Functions.h>

/**
 * \brief       Updates the pointer to immediately behind the full tag.
 *
 * \param p     *p points to the start of the DER element.
 *              On successful completion, *p points to the first byte
 *              beyond the DER element.
 *              On error, the value of *p is undefined.
 *
 * \return      PSA_SUCCESS if successful.
 * \return      An PSA_ERROR_INVALID_ARGUMENT error code if the parsed input is incorrect
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_updatePointerTag(const uint8_t **p,
                          uint8_t tag)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    uint32_t length = 0u;

    if((NULL == p) || (NULL == *p) || (**p != tag))
    {
      return PSA_ERROR_INVALID_ARGUMENT;
    }
    uint32_t ptrLen = 1u;

    //check length
    if((*(*p + 1u) & 0x80u) == 0u) //short from
    {
     length = *(*p + 1u);
     ptrLen = 2u;
    }
    else //long form
    {
      uint8_t numberBytes = *(*p + 1u) & 0x7Fu;
      ptrLen = 2u;

      /* If length is less than 128bytes it should be short form */
      if ((numberBytes == 1u) && (*(*p + ptrLen) < 128u))
      {
        return PSA_ERROR_INVALID_ARGUMENT;
      }

      for(uint8_t i = 0u; i < numberBytes; ++i)
      {
       length = length << 8u;
       length |= *(*p + ptrLen);
       ptrLen++;
      }
    }

    *p += ptrLen;
    if((tag & 0x20u) != 0x20u)
    {
      // not constructed tag, skip the content
      *p += length;
    }
    return PSA_SUCCESS;
}

/**
 * \brief       Retrieve an integer DER tag and its value.
 *              Updates the pointer to immediately behind the full tag.
 *
 * \param p     *p points to the start of the DER element.
 *              On successful completion, *p points to the first byte
 *              beyond the DER element.
 *              On error, the value of *p is undefined.
 *
 * \return      PSA_SUCCESS if successful.
 * \return      An PSA_ERROR_INVALID_ARGUMENT error code if the parsed input is incorrect
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_get_integer(const uint8_t **p,
                          mcuxClRsa_KeyEntry_t  * key)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    //check tag
    if(**p != 0x02u)
    {
      return PSA_ERROR_INVALID_ARGUMENT;
    }
    uint32_t ptrLen = 1u;

    //check length
    if((*(*p + 1u) & 0x80u) == 0u) //short from
    {
      key->keyEntryLength = *(*p + 1u);
      ptrLen = 2u;
    }
    else //long form
    {
      uint8_t numberBytes = *(*p + 1u) & 0x7Fu;
      ptrLen = 2u;

      if(numberBytes > 4u) // too big to fit into uint32
      {
        return PSA_ERROR_INVALID_ARGUMENT;
      }

      // if length is less than 128 bytes it should be short form
      if ((numberBytes == 1u) && (*(*p + ptrLen) < 128u))
      {
        return PSA_ERROR_INVALID_ARGUMENT;
      }

      key->keyEntryLength = 0u;

      for(uint32_t i = 0u; i < numberBytes; ++i)
      {
        key->keyEntryLength = key->keyEntryLength << 8;
        key->keyEntryLength |= *(*p + ptrLen);
        ptrLen++;
      }
    }

    //check first and second octet of integers
    uint8_t first_octet = *(*p + ptrLen);
    uint8_t second_octet = *(*p + ptrLen + 1u);
    if((first_octet == 0u) && ((second_octet & 0x80u) == 0u))
    {
      return PSA_ERROR_INVALID_ARGUMENT;
    }
    if((first_octet == 0xFFu) && ((second_octet & 0x80u) == 0x80u))
    {
      return PSA_ERROR_INVALID_ARGUMENT;
    }

    if(first_octet == 0u)
    {
      //take next non-zero octet, the key date is unsigned
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("ptrLen will be at most 2+numberBytes, with numberBytes being an 8-bit value. This cannot wrap.")
      ptrLen++;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
      MCUX_CSSL_ANALYSIS_START_SUPPRESS_INTEGER_WRAP("Key entry lengths are always bigger than 1, so this cannot wrap.")
      key->keyEntryLength -= 1u;
      MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_INTEGER_WRAP()
    }
    *p += ptrLen;
    MCUX_CSSL_ANALYSIS_START_SUPPRESS_DISCARD_CONST_QUALIFIER("Const must be discarded to initialize the generic structure member.")
    key->pKeyEntryData = (uint8_t *)*p;
    MCUX_CSSL_ANALYSIS_STOP_SUPPRESS_DISCARD_CONST_QUALIFIER()

    *p += key->keyEntryLength;

    return PSA_SUCCESS;
}

/**
 * \brief       Generate an integer DER tag and its value
 *              Updates the pointer to immediately behind the full tag.
 *
 * \param p     *p points to the start of the DER element.
 *              On successful completion, *p points to the first byte
 *              beyond the DER element.
 *              On error, the value of *p is undefined.
  * \param key  *key points to the origin key element.

 *
 * \return      PSA_SUCCESS if successful.
 * \return      An PSA_ERROR_INVALID_ARGUMENT error code if the parsed input is incorrect
 */

MCUX_CSSL_ANALYSIS_START_PATTERN_DESCRIPTIVE_IDENTIFIER()
psa_status_t mcuxClPsaDriver_psa_driver_wrapper_der_integer(uint8_t **p,
                          mcuxClRsa_KeyEntry_t  * key)
MCUX_CSSL_ANALYSIS_STOP_PATTERN_DESCRIPTIVE_IDENTIFIER()
{
    uint8_t *ptr = *p;
    uint32_t ptrLen = 1u;

    //check tag
    *ptr = 0x02u;
    if(key->keyEntryLength > 0x7Fu) //long form
    {
        uint8_t h3_byte = (uint8_t)(((key->keyEntryLength) & 0xFF000000u) >> 24u);
        uint8_t h2_byte = (uint8_t)(((key->keyEntryLength) & 0xFF0000u) >> 16u);
        uint8_t h1_byte = (uint8_t)(((key->keyEntryLength) & 0xFF00u) >> 8u);
        uint8_t h0_byte = (uint8_t)((key->keyEntryLength) & 0xFFu);
        if(h3_byte != 0u)
        {
            ptr[1u] = 0x84u;
            ptr[2u] = h3_byte;
            ptr[3u] = h2_byte;
            ptr[4u] = h1_byte;
            ptr[5u] = h0_byte;
            ptrLen = 6u;
        }
        else if(h2_byte != 0u)
        {
            ptr[1u] = 0x83u;
            ptr[2u] = h2_byte;
            ptr[3u] = h1_byte;
            ptr[4u] = h0_byte;
            ptrLen = 5u;
        }
        else if(h1_byte != 0u)
        {
            ptr[1u] = 0x82u;
            ptr[2u] = h1_byte;
            ptr[3u] = h0_byte;
            ptrLen = 4u;
        }
        else
        {
            ptr[1u] = 0x81u;
            ptr[2u] = h0_byte;
            ptrLen = 3u;
        }
    }
    else                           //short from
    {
        ptr[1] = (uint8_t)key->keyEntryLength;
        ptrLen = 2u;
    }

    *p = ptr + ptrLen;
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_BEGIN(token, mcuxClMemory_copy(
                                                  *p,
                                                  key->pKeyEntryData,
                                                  key->keyEntryLength,
                                                  key->keyEntryLength));
    if (MCUX_CSSL_FP_FUNCTION_CALLED(mcuxClMemory_copy) != token)
    {
        return PSA_ERROR_GENERIC_ERROR;
    }
    MCUX_CSSL_FP_FUNCTION_CALL_VOID_END();
    *p += key->keyEntryLength;

    return PSA_SUCCESS;
}


