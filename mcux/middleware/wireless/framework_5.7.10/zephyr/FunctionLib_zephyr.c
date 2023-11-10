/**
 * 2023-11-03 - Created by Sendrato.com
 * SPDX-License-Identifier: Apache-2.0
 */

#include "FunctionLib.h"
#include <string.h>

/**
 * @brief  Copy the content of one memory block to another. The amount of data
 *         to copy must be specified in number of bytes.
 *
 * The source and destination buffers must not overlap.
 *
 * @param[out] pDst   Pointer to destination memory block
 * @param[in] pSrc    Pointer to source memory block
 * @param[in] cBytes  Number of bytes to copy
 */
void FLib_MemCpy(void *pDst, const void *pSrc, uint32_t cBytes)
{
    memcpy(pDst, pSrc, cBytes);
}


/**
 * @brief  Copy bytes. The byte at index i from the source buffer is copied to
 *         index ((n-1) - i) in the destination buffer (and vice versa).
 *
 * @param[out] pDst   Pointer to destination memory block
 * @param[in] pSrc    Pointer to source memory block
 * @param[in] cBytes  Number of bytes to copy
 */
void FLib_MemCpyReverseOrder(void *pDst, const void *pSrc, uint32_t cBytes)
{
    if(cBytes)
    {
        pDst = (uint8_t*)pDst + (uint32_t)(cBytes-1);
        while (cBytes)
        {
            *((uint8_t*)pDst) = *((uint8_t*)pSrc);
            pDst = (uint8_t*)pDst-1;
            pSrc = (uint8_t*)pSrc+1;
            cBytes--;
        }
    }
}

/**
 * @brief  Reset bytes in a memory block to a certain value. The value, and the
 *         number of bytes to be set, are supplied as arguments.
 *
 * @param[in] pData   Pointer to memory block to reset
 * @param[in] value   Value that memory block will be set to
 * @param[in] cBytes  Number of bytes to set
 */
void FLib_MemSet(void *pData, uint8_t value, uint32_t cBytes)
{
    memset(pData, value, cBytes);
}

/**
 * @brief  This function compares two buffers.
 *
 * @param[in]  pData1  First buffer to compare.
 * @param[in]  pData2  Second buffer to compare.
 * @param[in]  cBytes Number of bytes to compare.
 * @return            TRUE if the buffers are equal and FALSE otherwise.
 */
bool_t FLib_MemCmp(const void* pData1, const void *pData2, uint32_t cBytes)
{
    return memcmp(pData1, pData2, cBytes) == 0;
}

/*! *********************************************************************************
* \brief  This function compares each octet of a given location to a value.
*
* \param [in]     pAddr      location to be compared
*
* \param [in]     val        reference value
*
* \param [in]     len        length of location to be compared
*
* \return  This function return TRUE if all octests match and FALSE otherwise.
*
* \post
*
* \remarks
*
********************************************************************************** */
bool_t FLib_MemCmpToVal
        (
                const void* pAddr,
                uint8_t val,
                uint32_t len
        )
{
    while(len)
    {
        len--;

        if(((uint8_t *)pAddr)[len] != val)
        {
            return FALSE;
        }
    }

    return TRUE;
}