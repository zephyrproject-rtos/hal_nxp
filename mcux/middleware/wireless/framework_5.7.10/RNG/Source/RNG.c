/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2017, 2019-2022 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#include "RNG_Interface.h"
#include "FunctionLib.h"
#include "SecLib.h"
#include "fsl_device_registers.h"
#include "fsl_os_abstraction.h"
#include "fsl_common.h"

#if (cPWR_UsePowerDownMode)
#include "PWR_Interface.h"
#endif

#if defined ELEMU_VER_FEATURE
#define USE_SENTINEL_RNG 1
#endif


#if defined USE_SENTINEL_RNG && (USE_SENTINEL_RNG != 0)
#include "sss_crypto.h"
#else
#if ((defined(FSL_FEATURE_SOC_TRNG_COUNT)) && (FSL_FEATURE_SOC_TRNG_COUNT > 0U))
#if defined CPU_JN518X
    #include "fsl_rng.h"
    #define TRNG0       RNG
#else
    #include "fsl_trng.h"
#endif
#elif ((defined(FSL_FEATURE_SOC_RNG_COUNT)) && (FSL_FEATURE_SOC_RNG_COUNT > 0U))
    #if defined CPU_QN908X
        #include "fsl_rng.h"
        #include "fsl_power.h"
    #else
        #include "fsl_rnga.h"
    #endif
#endif
#endif
#if defined(gRngSeedStorageAddr_d) || defined(gRngSeedHwParamStorage_d)
#include "HWParameter.h"
#endif

/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */
#ifndef gRNG_UsePhyRngForInitialSeed_d
#define gRNG_UsePhyRngForInitialSeed_d 0
#endif

#define mPRNG_NoOfBits_c      (256U)
#define mPRNG_NoOfBytes_c     (mPRNG_NoOfBits_c/8U)
#define mPRNG_NoOfLongWords_c (mPRNG_NoOfBits_c/32U)

#if USE_RTOS && gRngUseMutex_c
    #define RNG_MUTEX_LOCK()   OSA_MutexLock((osa_mutex_handle_t)rng_ctx.mRngMutexId, osaWaitForever_c)
    #define RNG_MUTEX_UNLOCK() OSA_MutexUnlock((osa_mutex_handle_t)rng_ctx.mRngMutexId)
#else
    #define RNG_MUTEX_LOCK()
    #define RNG_MUTEX_UNLOCK()
#endif /* USE_RTOS */


#ifndef RAISE_ERROR
#define RAISE_ERROR(_X_, _VAL_)  {_X_ = _VAL_; break;}
#endif


typedef struct rng_ctx_t {
    bool_t     Initialized;
    bool_t     mPrngSeeded;

    bool_t     mPolyRngSeeded;
    uint32_t   mPolyRngRandom;

#if USE_RTOS && gRngUseMutex_c
    /*! Mutex used to protect RNG Contexts when a RTOS is used. */
    osaMutexId_t mRngMutexId;
#endif /* USE_RTOS */

    uint32_t XKEY[mPRNG_NoOfLongWords_c];
    uint32_t mPRNG_Requests;

} RNG_context_t;


/*! *********************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
********************************************************************************** */

static RNG_context_t rng_ctx = {
    .Initialized = FALSE,
    .mPrngSeeded = FALSE,
    .mPolyRngSeeded = FALSE,
    .mPolyRngRandom = 0xDEADBEEF,
    .XKEY = { 0 },
    .mPRNG_Requests = gRngMaxRequests_d,
};


/*! *********************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
********************************************************************************** */
#if ((!defined(FSL_FEATURE_SOC_TRNG_COUNT)) || (FSL_FEATURE_SOC_TRNG_COUNT == 0U)) && \
    ((!defined(FSL_FEATURE_SOC_RNG_COUNT)) || (FSL_FEATURE_SOC_RNG_COUNT == 0U)) && \
    (gRNG_UsePhyRngForInitialSeed_d)
extern void PhyGetRandomNo(uint32_t *pRandomNo);
#endif
/*! *********************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
********************************************************************************** */

static uint8_t RNG_Specific_Init(uint32_t *pSeed);
static uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes);


/*! *********************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
********************************************************************************** */

/*! *********************************************************************************
* \brief  Initialize the RNG HW module
*
* \return  Status of the RNG initialization sequence
*
********************************************************************************** */
uint8_t RNG_Init(void)
{
    uint32_t seed = 0U;

    uint8_t status = gRngSuccess_d;
    do {
        /* Check if RNG is already initialized */
        if( rng_ctx.Initialized )
          break;
#if USE_RTOS && gRngUseMutex_c
        /*! Initialize the Rng Mutex here. */
        if ((rng_ctx.mRngMutexId = OSA_MutexCreate()) == NULL)
        {
        	assert(0);
        	status = gRngInternalError_d;
            break;
        }
#endif
    #if defined(gRngSeedHwParamStorage_d) || defined(gRngSeedStorageAddr_d)
        seed = Rng_read_seed_from_flash();
        /* A valid seed has been stored to NVM */
        if ( (seed != 0U) && (seed != 0xFFFFFFFFU) )
          break;
    #endif

        status = RNG_Specific_Init(&seed);
        if (status != gRngSuccess_d)
            break;

        /* Make sure that the seed is not zero */
      rng_ctx.mPolyRngRandom = seed | 1u;
      rng_ctx.mPolyRngSeeded = TRUE;
    #if defined(gRngSeedHwParamStorage_d) || defined(gRngSeedStorageAddr_d)
      Rng_save_seed_to_flash(seed);
    #endif
      rng_ctx.Initialized = TRUE;

    } while (0);
    /* Init Successful */
    return status;
}


/*! *********************************************************************************
* \brief  Read a random number from the HW RNG module.
*         If the HW fails, the SW PRNG is used as backup.
*
* \param[out] pRandomNo - pointer to location where the value will be stored
*
* \return  status of the RNG module
*
********************************************************************************** */
uint8_t RNG_HwGetRandomNo(uint32_t* pRandomNo)
{
    uint8_t status = gRngSuccess_d;
    if(pRandomNo == NULL)
    {
        status =  gRngNullPointer_d;
    }
    else
    {
       int16_t obtained_sz = 0;
       status = RNG_Specific_GetRandomU32(pRandomNo, &obtained_sz);
       if (status != gRngSuccess_d || obtained_sz != sizeof(uint32_t))
         status =  gRngInternalError_d;
    }
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
    if ((rng_ctx.mPolyRngSeeded == TRUE) && (pRandomNo != NULL))
    {
        uint64_t rndval = (uint64_t)rng_ctx.mPolyRngRandom;
        rndval = (rndval * 279470273UL) % 4294967291UL;
        rng_ctx.mPolyRngRandom = (uint32_t)rndval;
        if ( (uint32_t)pRandomNo & 0x3)
          *pRandomNo = rng_ctx.mPolyRngRandom;
        else
           FLib_MemCpy(pRandomNo, &rng_ctx.mPolyRngRandom, sizeof(uint32_t));
    }

}

/*! *********************************************************************************
* \brief  Initialize seed for the PRNG algorithm.
*         If this function is called again, even with a NULL argument,
*         the PRNG will be reseeded.
*
* \param[in]  pSeed  Ignored - please set to NULL
*             This parameter is ignored because it is no longer needed.
*             The PRNG is automatically seeded from the true random source.
*
********************************************************************************** */
void RNG_SetPseudoRandomNoSeed(uint8_t* pSeed)
{
    NOT_USED(pSeed);
    uint8_t pseudoRNGSeed[mPRNG_NoOfBytes_c] = {0};
    uint32_t i;

    rng_ctx.mPRNG_Requests = 1U;

    for (i = 0; i < mPRNG_NoOfBytes_c; i+=4U)
    {
        RNG_GetRandomNo((uint32_t*)(void *)(&(pseudoRNGSeed[i])));
    }
    FLib_MemCpy( rng_ctx.XKEY, pseudoRNGSeed, mPRNG_NoOfBytes_c );
}

#ifndef CPU_JN518X
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
* \param[in]     pSeed - optional user SEED. Should be NULL if not used.
*
* \return  The number of bytes copied or -1 if reseed is needed
*
********************************************************************************** */
int16_t RNG_GetPseudoRandomNo(uint8_t* pOut, uint8_t outBytes, uint8_t* pSeed)
{
     uint16_t outputBytes = outBytes;

    /* PRNG buffer used for both input and output */
    uint32_t prngBuffer[mPRNG_NoOfLongWords_c] = {0};

    if(pSeed != NULL)
    {
        rng_ctx.mPRNG_Requests = 1U;
    }

    if (rng_ctx.mPRNG_Requests == gRngMaxRequests_d)
    {
        outputBytes = 0xFFFF;
    }
    else
    {
        uint32_t i;
        rng_ctx.mPRNG_Requests++;

        /* a. XSEEDj = optional user input. */
        if(pSeed != NULL)
        {
            /* b. XVAL = (XKEY + XSEEDj) mod 2^b */
            for (i=0; i<mPRNG_NoOfBytes_c; i++)
            {
                ((uint8_t*)prngBuffer)[i] = ((uint8_t*)rng_ctx.XKEY)[i] + pSeed[i];
            }
        }
        else
        {
            for (i=0; i<mPRNG_NoOfBytes_c; i++)
            {
                ((uint8_t*)prngBuffer)[i] = ((uint8_t*)rng_ctx.XKEY)[i];
            }
        }
        /* c. xj = G(t,XVAL) mod q
        ***************************/
        SHA256_Hash((uint8_t*)prngBuffer, mPRNG_NoOfBytes_c, (uint8_t*)prngBuffer);

        /* d. XKEY = (1 + XKEY + xj) mod 2^b */
        rng_ctx.XKEY[0] += 1U;
        for (i=0; i<mPRNG_NoOfLongWords_c; i++)
        {
            rng_ctx.XKEY[i] += prngBuffer[i];
        }

        /* Check if the length provided exceeds the output data size */
        if (outputBytes > mPRNG_NoOfBytes_c)
        {
            outputBytes = mPRNG_NoOfBytes_c;
        }
        /* Copy the generated number */

        for (i=0; i < (uint32_t)outputBytes; i++)
        {
            pOut[i] = ((uint8_t*)prngBuffer)[i];
        }
    }

    return (int16_t)outputBytes;
}
#else
int16_t RNG_GetPseudoRandomNo(uint8_t* pOut, uint8_t outBytes, uint8_t* pSeed)
{
    uint16_t outputBytes = outBytes;
    uint16_t i = 0;
    int16_t rng_nb_bytes;
    uint32_t random_val;
    /* Bypass PRNG intentionally */
    while ( i < outputBytes )
    {
        if (RNG_Specific_GetRandomU32(&random_val, &rng_nb_bytes) != gRngSuccess_d)
           break;
        if (rng_nb_bytes == sizeof(uint32_t))
        {
            if (i <= outputBytes - sizeof(uint32_t))
            {
                *(uint32_t*)&pOut[i] = random_val;
                i += sizeof(uint32_t);
            }
            else
            {
                /* finish off partial word */
                for (; i < outputBytes; i++)
                {
                    pOut[i] = random_val & 0xff;
                    random_val >>= 8;
                }
            }
        }
    }

    return (int16_t)outputBytes;
}
#endif
int PRNG_GetRandomData(void * ctx_data, unsigned char *output, size_t len)
{
    NOT_USED(ctx_data);
    int ret = -1;
    uint8_t sz = (uint8_t)len;
    if (RNG_GetPseudoRandomNo(output, sz, NULL) == len)
    {
       ret = 0;
    }
    return ret;
}

/*! *********************************************************************************
* \brief  Returns a pointer to the general PRNG function
*         Call RNG_SetPseudoRandomNoSeed() before calling this function.
*
* \return  Function pointer to the general PRNG function or NULL if it
*          was not seeded.
*
********************************************************************************** */
fpRngPrng_t RNG_GetPrngFunc (void)
{
    return PRNG_GetRandomData;
}

/*! *********************************************************************************
* \brief  Returns a pointer to the general PRNG context
*         Call RNG_SetPseudoRandomNoSeed() before calling this function.
*
* \return  Function pointer to the general PRNG context or NULL if it
*          was not initialized correctly.
*
********************************************************************************** */
void* RNG_GetPrngContext (void)
{
    return (void*)&rng_ctx;
}

/*! *********************************************************************************
* \brief  Returns a random number between 0 and 256
*
* \return random number
*
********************************************************************************** */
uint32_t RND_u32GetRand256(void)
{
    uint32_t n;
    
    RNG_GetRandomNo(&n);
    
    return n & 0xFF;
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
    uint32_t n;
    
    RNG_GetRandomNo(&n);
    
    return n % (u32Max - u32Min) + u32Min;
}

/*! *********************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
********************************************************************************** */
#if defined(gRngSeedHwParamStorage_d) || defined(gRngSeedStorageAddr_d)
static uint32_t Rng_read_seed_from_flash(void)
{
    uint32_t seed = 0U;
#if defined(gRngSeedHwParamStorage_d)
    hardwareParameters_t *pHWParams = NULL;
    (void)NV_ReadHWParameters(&pHWParams);
    seed = pHWParams->rngSeed;
#elif defined(gRngSeedStorageAddr_d)
    seed = *((uint32_t*)gRngSeedStorageAddr_d);
#endif
    return seed;
}

static void Rng_save_seed_to_flash(uint32_t seed)
{
    NV_Init();

  #if defined(gRngSeedHwParamStorage_d)
    pHWParams->rngSeed = seed ;
    (void)NV_WriteHWParameters();

  #elif defined(gRngSeedStorageAddr_d)
    (void)NV_FlashProgramUnaligned(gRngSeedStorageAddr_d,
                                   sizeof(seed),
                                   (uint8_t*)&seed);
  #endif
}
#endif


#if ((defined(FSL_FEATURE_SOC_TRNG_COUNT)) && (FSL_FEATURE_SOC_TRNG_COUNT > 0U))
/* The Allow/Disallow to sleep order is related to the use of a HW TRNG only */
#if (cPWR_UsePowerDownMode)
  #define RNG_DisallowDeviceToSleep() PWR_DisallowDeviceToSleep()
  #define RNG_AllowDeviceToSleep()    PWR_AllowDeviceToSleep()
#else
  #define RNG_DisallowDeviceToSleep()
  #define RNG_AllowDeviceToSleep()
#endif
#ifndef CPU_JN518X

static bool_t mRngDisallowMcuSleep = FALSE;

static void TRNG_GoToSleep(void)
{
    if ((TRNG0->MCTL & TRNG_MCTL_ENT_VAL_MASK) != 0U)
    {
        if (mRngDisallowMcuSleep)
        {
            mRngDisallowMcuSleep = FALSE;
            RNG_AllowDeviceToSleep();
        }
    }
    else
    {
        if (!mRngDisallowMcuSleep)
        {
            mRngDisallowMcuSleep = TRUE;
            RNG_DisallowDeviceToSleep();
        }
    }
}

static void TRNG_ISR(void)
{
    /* Clear Interrupt flags */
    TRNG0->INT_CTRL &= ~(TRNG_INT_CTRL_ENT_VAL_MASK |
                         TRNG_INT_CTRL_HW_ERR_MASK  |
                         TRNG_INT_CTRL_FRQ_CT_FAIL_MASK);

    TRNG_GoToSleep();
}
#endif

#endif /* FSL_FEATURE_SOC_TRNG_COUNT  */

#if ((defined(FSL_FEATURE_SOC_RNG_COUNT)) && (FSL_FEATURE_SOC_RNG_COUNT > 0U))
uint8_t RNG_Specific_Init(uint32_t *pSeed)
{
    uint8_t status = gRngSuccess_d;
#ifndef CPU_QN908X
    RNGA_Init(RNG);

    /* Get seed for pseudo RNG */
    status = RNGA_GetRandomData(RNG, pSeed, (int32_t)sizeof(uint32_t));
    assert(gRngSuccess_d == status);
#else
    POWER_EnableADC(true);
    RNG_Drv_Init(RNG);
    RNG_Enable(RNG, true);
    /* Get seed for pseudo RNG */
    if( RNG_GetRandomData(RNG, (uint8_t*)pSeed, (int32_t)sizeof(uint32_t)) )
    {
        status = gRngInternalError_d;
    }
    RNG_Enable(RNG, false);
    POWER_EnableADC(false);
#endif /* CPU_QN908X */
    return status;
}

uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes)
{
    uint8_t status;
    *returned_bytes = 0;
#ifndef CPU_QN908X
    status = RNGA_GetRandomData(RNG, pRandomNo, (size_t)sizeof(uint32_t));
    assert(gRngSuccess_d == status);
    *returned_bytes = sizeof(uint32_t);
#else
    POWER_EnableADC(true);
    RNG_Enable(RNG, true);
    if( RNG_GetRandomData(RNG, (uint8_t*)pRandomNo, (size_t)sizeof(uint32_t)) )
    {
        status = gRngInternalError_d;
    }
    else
    {
        *returned_bytes = sizeof(uint32_t);
        status = gRngSuccess_d;
    }
    RNG_Enable(RNG, false);
    POWER_EnableADC(false);
#endif
    return status;
}

#elif ((defined(FSL_FEATURE_SOC_TRNG_COUNT)) && (FSL_FEATURE_SOC_TRNG_COUNT > 0U))
#if !defined (CPU_JN518X)
uint8_t RNG_Specific_Init(uint32_t *pSeed)
{
    uint8_t status = gRngSuccess_d;
    trng_config_t config;

    (void)TRNG_GetDefaultConfig(&config);
    config.frequencyCountLimit.minimum = 0x00000100U;
    config.frequencyCountLimit.maximum = 0x000F0000U;
    config.ringOscDiv = kTRNG_RingOscDiv0;
    config.entropyDelay = 1200U;

    OSA_InstallIntHandler((uint32_t)TRNG0_IRQn, TRNG_ISR);

    status = (uint8_t)TRNG_Init(TRNG0, (const trng_config_t *)&config);
    assert(0U == status);

    /* Get seed for pseudo RNG */

    status = (uint8_t)TRNG_GetRandomData(TRNG0, pSeed, (size_t)sizeof(uint32_t));
    assert(0U == status);

#if defined(gRngSeedStorageAddr_d) || defined(gRngSeedHwParamStorage_d)
    TRNG_Deinit(TRNG0);
#else
    /* Check if the entropy generation ongoing */
    TRNG_GoToSleep();

    /* Clear Interrupt status.*/
    TRNG0->INT_CTRL &= ~(TRNG_INT_CTRL_ENT_VAL_MASK |
                         TRNG_INT_CTRL_HW_ERR_MASK  |
                             TRNG_INT_CTRL_FRQ_CT_FAIL_MASK);

    /* Enable interrupt.*/
    NVIC_SetPriority(TRNG0_IRQn, (uint32_t)gRngIsrPrio_c >> (8U - (uint8_t)__NVIC_PRIO_BITS));
    (void)EnableIRQ(TRNG0_IRQn);
    TRNG0->INT_MASK |= TRNG_INT_MASK_ENT_VAL_MASK |
                       TRNG_INT_MASK_HW_ERR_MASK  |
                       TRNG_INT_MASK_FRQ_CT_FAIL_MASK;
#endif
}
uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes)
{
    uint8_t status;
    *returned_bytes = 0;

    if( (TRNG0->MCTL & TRNG_MCTL_ENT_VAL_MASK) == 0U )
    {
        status = gRngInternalError_d;
    }
    else
    {
        status = (uint8_t)TRNG_GetRandomData(TRNG0, pRandomNo, (size_t)sizeof(uint32_t));
        assert(0U == status);
        *returned_bytes = sizeof(uint32_t);
    }

    TRNG_GoToSleep();

    return status;
}
#else /* CPU_JN518X */
uint8_t RNG_Specific_Init(uint32_t *pSeed)
{
    uint8_t status = gRngSuccess_d;
    trng_config_t config;

    TRNG_GetDefaultConfig(&config);
    if( kStatus_Success != TRNG_Init(TRNG0, &config) )
    {
        status = gRngInternalError_d;
    }
    else
    {
        /* Get seed for pseudo RNG */
        if( kStatus_Success != TRNG_GetRandomData(TRNG0, pSeed, sizeof(uint32_t)) )
        {
            status = gRngInternalError_d;
        }
    }
    return status;
}
uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes)
{
    uint8_t status;
    *returned_bytes = 0;

     status = (uint8_t)TRNG_GetRandomData(TRNG0, pRandomNo, (size_t)sizeof(uint32_t));
     assert(0U == status);
     *returned_bytes = sizeof(uint32_t);

    return status;
}

#endif
#elif gRNG_UsePhyRngForInitialSeed_d
uint8_t RNG_Specific_Init(uint32_t *pSeed)
{
    PhyGetRandomNo(pSeed);
    return gRngSuccess_d;
}
uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes)
{
   PhyGetRandomNo(pRandomNo);
   *returned_bytes = sizeof(uint32_t);
   return gRngSuccess_d;
}
#elif defined(FSL_FEATURE_SOC_SIM_COUNT) && (FSL_FEATURE_SOC_SIM_COUNT > 1)
uint8_t RNG_Specific_Init(uint32_t *pSeed)
{
    /* Lousy RNG seed based on MCU unique Id */
    uint8_t status = gRngSuccess_d;
    *pSeed = SIM->UIDL;
    *returned_bytes = sizeof(uint32_t);

    return status;
}
uint8_t RNG_Specific_GetRandomU32( uint32_t * pRandomNo, int16_t *returned_bytes)
{
   return gRngInternalError_d;
}

#endif
/********************************** EOF ***************************************/
