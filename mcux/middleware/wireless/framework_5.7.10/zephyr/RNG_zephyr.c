/**
 * 2023-11-03 - Created by Sendrato.com
 * SPDX-License-Identifier: Apache-2.0
 */

#include "RNG_Interface.h"
#include "SecLib.h"

#include <zephyr/kernel.h>
#include <zephyr/random/random.h>

/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */
#define mPRNG_NoOfBits_c      (256)
#define mPRNG_NoOfBytes_c     (mPRNG_NoOfBits_c/8)
#define mPRNG_NoOfLongWords_c (mPRNG_NoOfBits_c/32)


/*! *********************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
********************************************************************************** */
static uint32_t XKEY[mPRNG_NoOfLongWords_c];
static uint32_t mPRNG_Requests = gRngMaxRequests_d;

/*! *********************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
********************************************************************************** */

/* Crypto Library function prototypes. */
extern uint32_t SecLib_set_rng_seed (uint32_t seed);
extern uint32_t SecLib_get_random(void);

/**
 * @brief  Returns a random 32 bit word
 *
 * A number is read from the HW RNG module. If the HW fails, the SW PRNG is
 * used as backup.
 *
 * @param[out] pRandomNo    Pointer to location where the value will be stored
 * @return                  Status of the RNG initialization procedure.
 */
uint8_t RNG_HwGetRandomNo(uint32_t *pRandomNo)
{
    uint8_t status = gRngSuccess_d;
    *pRandomNo = sys_rand32_get();
    return status;
}

/*! *********************************************************************************
* \brief  Generates a 32-bit statistically random number
*         No random number will be generated if the RNG was not initialized
*         or an error occurs.
*
* \param[out]  pRandomNo  Pointer to location where the value will be stored
*
********************************************************************************** */
void RNG_GetRandomNo(uint32_t* pRandomNo)
{
    /* Check for NULL pointers */
    if (NULL != pRandomNo)
    {
        uint32_t n = SecLib_get_random();
        *pRandomNo = n;
    }
}

/**
 * @brief  Returns a random number between 0 an 256.
 *
 * @return            random number
 */
uint32_t RND_u32GetRand256(void)
{
    uint32_t n = sys_rand32_get();
    return n % 256;
}


/*! *********************************************************************************
* \brief  Returns a random number between the specified minimum and maximum values
*
* \param[in] u32Min  minimum value
* \param[in] u32Max  maximum value
*
* \return random number
*
********************************************************************************** */
uint32_t RND_u32GetRand(uint32_t u32Min, uint32_t u32Max)
{
    uint32_t n = sys_rand32_get();

    return n % (u32Max - u32Min) + u32Min;
}


/*! *********************************************************************************
* \brief  Pseudo Random Number Generator (PRNG) implementation
*         according to NIST FIPS Publication 186-2, APPENDIX 3
*
*         Let x be the signer's private key.
*         The following may be used to generate m values of x:
*           Step 1. Choose a new, secret value for the seed-key, XKEY.
*           Step 2. In hexadecimal notation let
*             t = 67452301 EFCDAB89 98BADCFE 10325476 C3D2E1F0.
*             This is the initial value for H0 || H1 || H2 || H3 || H4 in the SHS.
*           Step 3. For j = 0 to m - 1 do
*             a. XSEEDj = optional user input.
*             b. XVAL = (XKEY + XSEEDj) mod 2^b
*             c. xj = G(t,XVAL) mod q
*             d. XKEY = (1 + XKEY + xj) mod 2^b
*
* \param[out]    pOut - pointer to the output buffer
* \param[in]     outBytes - the number of bytes to be copied (1-20)
* \param[in]     pXSEED - optional user SEED. Should be NULL if not used.
*
* \return  The number of bytes copied or -1 if reseed is needed
*
********************************************************************************** */
int16_t RNG_GetPseudoRandomNo(uint8_t* pOut, uint8_t outBytes, uint8_t* pXSEED)
{
    uint32_t i;
    int16_t outputBytes = outBytes;
    /* PRNG buffer used for both input and output */
    uint32_t prngBuffer[mPRNG_NoOfLongWords_c] = {0};

    if(pXSEED)
    {
        mPRNG_Requests = 1;
    }

    if (mPRNG_Requests == gRngMaxRequests_d)
    {
        outputBytes = -1;
    }
    else
    {
        mPRNG_Requests++;

        /* a. XSEEDj = optional user input. */
        if (pXSEED)
        {
            /* b. XVAL = (XKEY + XSEEDj) mod 2^b */
            for (i=0; i<mPRNG_NoOfBytes_c; i++)
            {
                ((uint8_t*)prngBuffer)[i] = ((uint8_t*)XKEY)[i] + pXSEED[i];
            }
        }
        else
        {
            for (i=0; i<mPRNG_NoOfBytes_c; i++)
            {
                ((uint8_t*)prngBuffer)[i] = ((uint8_t*)XKEY)[i];
            }
        }

        /* c. xj = G(t,XVAL) mod q
        ***************************/
        SHA256_Hash((uint8_t*)prngBuffer, mPRNG_NoOfBytes_c, (uint8_t*)prngBuffer);
        /* d. XKEY = (1 + XKEY + xj) mod 2^b */
        XKEY[0] += 1;
        for (i=0; i<mPRNG_NoOfLongWords_c; i++)
        {
            XKEY[i] += prngBuffer[i];
        }

        /* Check if the length provided exceeds the output data size */
        if (outputBytes > mPRNG_NoOfBytes_c)
        {
            outputBytes = mPRNG_NoOfBytes_c;
        }

        /* Copy the generated number */
        for (i=0; i < outputBytes; i++)
        {
            pOut[i] = ((uint8_t*)prngBuffer)[i];
        }
    }

    return outputBytes;
}
