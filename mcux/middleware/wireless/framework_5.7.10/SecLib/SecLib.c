/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2022 NXP
* All rights reserved.
*
* \file
*
* This is the source file for the security module.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */


/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */

#include "MemManager.h"
#include "FunctionLib.h"
#include "SecLib.h"
#include "SecLib_ecp256.h"
#include "fsl_device_registers.h"
#include "fsl_os_abstraction.h"
#include "Panic.h"
#include <stddef.h>
#if defined NCCL_DEBUG
#include "dbg_logging.h"
#endif
#include "rom_aes.h"

/* Define gSecLibAESHwUsedFromIsr in app_preinclude.h if AES HW may be invoked from ISR */
#ifndef gSecLibAESHwUsedFromIsr
#define gSecLibAESHwUsedFromIsr 0
#endif
extern void dump_octet_string(const char * str, const unsigned char * data, size_t len);

#if defined FSL_FEATURE_SOC_AES_COUNT &&  (FSL_FEATURE_SOC_AES_COUNT > 0)
#define JN_AES_HW_ACC 1
#else
#define JN_AES_HW_ACC 0
#endif
#if (defined FSL_FEATURE_SOC_SHA_COUNT && (FSL_FEATURE_SOC_SHA_COUNT > 0))
#define JN_SHA_HW_ACC 1
#else
#define JN_SHA_HW_ACC 0
#endif

#if (defined FSL_FEATURE_SOC_MMCAU_COUNT &&  (FSL_FEATURE_SOC_MMCAU_COUNT > 0))
#define MMCAU_HW_ACC 1
#else
#define MMCAU_HW_ACC 0
#endif

#if (defined FSL_FEATURE_SOC_LTC_COUNT &&  (FSL_FEATURE_SOC_LTC_COUNT > 0))
#define LTC_HW_ACC 1
#else
#define LTC_HW_ACC 0
#endif

#if MMCAU_HW_ACC

#ifndef FREESCALE_MMCAU
#define FREESCALE_MMCAU 1
#endif

#ifndef FREESCALE_MMCAU_SHA
#define FREESCALE_MMCAU_SHA 1
#endif

#include "cau_api.h"
#endif /* MMCAU_HW_ACCELERATION */

#if LTC_HW_ACC
#include "fsl_ltc.h"
#endif

#if JN_AES_HW_ACC
#include "fsl_aes.h"
#endif
#if JN_SHA_HW_ACC
#include "fsl_sha.h"
#endif

#if FSL_FEATURE_SOC_AES_HW
  #ifdef CPU_QN908X
  #include "aes_reg_access.h"
  #include "fsl_aes.h"
  #include "AesManager.h"
  #endif /* CPU_QN908X */
#endif /* FSL_FEATURE_SOC_AES_HW */

#ifndef cPWR_UsePowerDownMode
#define cPWR_UsePowerDownMode 0
#endif

#if (cPWR_UsePowerDownMode)
#include "PWR_Interface.h"
#endif


/*! *********************************************************************************
*************************************************************************************
* Private macros
*************************************************************************************
********************************************************************************** */
#if (!(defined(__CORTEX_M)) || (defined(__CORTEX_M) ))
#if defined(__GNUC__)
#define HAL_REV32(x) __builtin_bswap32(x)
#elif defined(__IAR_SYSTEMS_ICC__) || defined(__CC_ARM)
#define HAL_REV32(x) __REV(x)
#endif
#else
#define HAL_REV32(x) (((x & 0x000000ffu)<<24)|((x & 0x0000ff00u)<< 8)|((x & 0x00ff0000u)>>8)|((x& 0xff000000u)>>24))
#endif

/* AES constants */
#define AES128 128
#define AES128_ROUNDS 10

#define AES192 192
#define AES192_ROUNDS 12

#define AES256 256
#define AES256_ROUNDS 14


#if (cPWR_UsePowerDownMode)
    #define SecLib_DisallowToSleep() PWR_DisallowDeviceToSleep()
    #define SecLib_AllowToSleep()    PWR_AllowDeviceToSleep()
#else
    #define SecLib_DisallowToSleep()
    #define SecLib_AllowToSleep()
#endif

/* Need to lockout access to the AES HW accelerator in multitask environments */
#if USE_RTOS && (LTC_HW_ACC || MMCAU_HW_ACC || JN_AES_HW_ACC || FSL_FEATURE_SOC_AES_HW) && gSecLibUseMutex_c
    #define SECLIB_AES_MUTEX_LOCK()   OSA_MutexLock(mSecLibAesMutexId, osaWaitForever_c)
    #define SECLIB_AES_MUTEX_UNLOCK() OSA_MutexUnlock(mSecLibAesMutexId)
#else
    #define SECLIB_AES_MUTEX_LOCK()
    #define SECLIB_AES_MUTEX_UNLOCK()
#endif /* USE_RTOS */

/* Need to lockout access to the SHA HW accelerator in multitask environments */
#if USE_RTOS && JN_SHA_HW_ACC && gSecLibUseMutex_c
    #define SECLIB_SHA_MUTEX_LOCK(timeout) OSA_MutexLock(mSecLibShaMutexId, timeout)
    #define SECLIB_SHA_MUTEX_UNLOCK()      OSA_MutexUnlock(mSecLibShaMutexId)
#else
    #define SECLIB_SHA_MUTEX_LOCK(...) osaStatus_Success
    #define SECLIB_SHA_MUTEX_UNLOCK()
#endif /* USE_RTOS */

#if (JN_AES_HW_ACC)
#define Lo8(x) ((uint8_t) ((x) & 0xFF))

#define INITIALISE_NONCE_TOP_BYTE(NONCE); \
            NONCE[14] = 0;
#define UPDATE_NONCE_COUNTER(NONCE,VALUE); \
            NONCE[15] = Lo8(VALUE);
#endif


#ifdef EC_P256_LEGACY
#define mUseBigIntMacros_d 0
#define mUseImprovedDoubleAndAdd_d 0

#define SIZE        (8 * sizeof(uint32_t))
#define LOW_MASK    ((((uint32_t)1)<<(SIZE/2))-1)
#define HIGH_HALF   (SIZE/2)

#define KEY_UINT8_ARRAY_LENGTH  ECP256_COORDINATE_LEN
#define KEY_UINT32_ARRAY_LENGTH ECP256_COORDINATE_WLEN
#endif
/*! *********************************************************************************
*************************************************************************************
* Private type definitions
*************************************************************************************
********************************************************************************** */
typedef union _uuint128_tag
{
    uint8_t  u8[16];
    uint64_t u64[2];
} uuint128_t;

#if USE_TASK_FOR_HW_AES
uint8_t AES128ECB_Enc_Id;
uint8_t AES128ECB_Dec_Id;
uint8_t AES128ECBB_Enc_Id;
uint8_t AES128ECBB_Dec_Id;
uint8_t AES128CTR_Enc_Id;
uint8_t AES128CTR_Dec_Id;
uint8_t AES128CMAC_Id;
#endif

#if MMCAU_HW_ACC
typedef struct mmcauAesContext_tag{
    uint8_t keyExpansion[44*4];
    uint8_t alignedIn[AES_BLOCK_SIZE];
    uint8_t alignedOut[AES_BLOCK_SIZE];
}mmcauAesContext_t;

/*! MMCAU AES Context Buffer for both AES Encrypt and Decrypt operations.*/
mmcauAesContext_t mmcauAesCtx;
#endif /* FSL_FEATURE_SOC_MMCAU_COUNT */

#if USE_RTOS && (JN_AES_HW_ACC || LTC_HW_ACC || MMCAU_HW_ACC || FSL_FEATURE_SOC_AES_HW)
/*! Mutex used to protect the AES Context when an RTOS is used. */
osaMutexId_t mSecLibAesMutexId = NULL;
#endif /* USE_RTOS */

#if USE_RTOS && JN_SHA_HW_ACC
/*! Mutex used to protect the SHA Context when an RTOS is used. */
osaMutexId_t mSecLibShaMutexId = NULL;
#endif /* USE_RTOS */

#if JN_SHA_HW_ACC
typedef struct sha1Context_tag{
    uint32_t sha_working_area[SHA_CTX_SIZE];
}sha1Context_t;
#else
typedef struct sha1Context_tag{
    uint32_t hash[SHA1_HASH_SIZE/sizeof(uint32_t)];
    uint8_t  buffer[SHA1_BLOCK_SIZE];
    uint32_t totalBytes;
    uint8_t  bytes;
}sha1Context_t;
#endif

typedef struct sha256Context_tag{
    uint32_t hash[SHA256_HASH_SIZE/sizeof(uint32_t)];
    uint8_t  buffer[SHA256_BLOCK_SIZE];
    uint32_t totalBytes;
    uint8_t  bytes;
}sha256Context_t;

typedef struct HMAC_SHA256_context_tag{
    sha256Context_t shaCtx;
    uint8_t pad[SHA256_BLOCK_SIZE];
} HMAC_SHA256_context_t;

typedef int (*efuse_LoadUniqueKey_t)(void);
typedef uint32_t (*aesLoadKeyFromOTP_t)(AES_KEY_SIZE_T keySize);

/* This structure can be used to define local software contexts for AES usage.
 * It will eventually be passed to AES_128_ProcessBlocks, to set the AES mode
 * and to load the correct key (Efuse OTP or software key). If pSoftwareKey
 * is NULL, secret key shall be loaded through ROM API. */
typedef struct {
    uint32_t mode;          /*!< Setup mode: ECB, etc. */
    uint32_t keySize;       /*!< Size of the AES key. */
    uint32_t* pSoftwareKey; /*!< Address to save the software key. */
    uint32_t flags;         /*!< Extra flags, normally 0. */
} aesContext_t;

/************************************************************************************
*************************************************************************************
* Private memory declarations
*************************************************************************************
************************************************************************************/


#if (JN_AES_HW_ACC)
/* Used by ZigBee stack adaptation */
enum
{
    MAX_PACKET    =   127,    // largest packet size
    A_DATA        =   0x40,   // the Adata bit in the flags
    M_SHIFT       =   3,      // how much to shift the 3-bit M field
    L_SHIFT       =   0,      // how much to shift the 3-bit L field
    L_SIZE        =   2       // size of the l(m) length field (in octets)
};
static tsReg128 sKey;
bool_t g_bLegacyHwBugEmulation;

/*
* Although an AES HW accelerator is present, it does not work correctly when simultaneous
* DMA operation happens on the same AHB port.
* A workaround consists in preventing HW AES engine operation when DM is ongoing.
*/
uint8_t force_sw_aes_execution_cnt = 0;

#endif

/* Pointer to the software context which currently uses hardware SHA256.*/
static void* sHwSha256Context = NULL;

#if defined gSecLibAESHwUsedFromIsr && (gSecLibAESHwUsedFromIsr != 0)
/* Flag to signal an ISR used hardware AES for encrypt/decrypt. */
static volatile bool_t bHasIsrInterrupted = false;
#endif
/* AES_128_ProcessBlocks can use efuseLoadUniqueKey and aesLoadKeyFromOTP to load
 * the secret key in hardware AES module. */
static const efuse_LoadUniqueKey_t efuseLoadUniqueKey = (efuse_LoadUniqueKey_t)(0x030016f4 | 1);
static const aesLoadKeyFromOTP_t aesLoadKeyFromOTP = (aesLoadKeyFromOTP_t)(0x0300146d | 1);

static uint32_t u32Reverse(uint32_t u32InWord);

#if defined gSecLibAESMethodSelectionDynHwSw_c &&  (gSecLibAESMethodSelectionDynHwSw_c != 0)
static void sw_aes_cbc_decrypt(const uint8_t* pInput,
                               uint32_t inputLen,
                               const uint8_t* pInitVector,
                               const uint8_t* pKey,
                               uint8_t* pOutput);

static void sw_aes_cbc_encrypt(const uint8_t* pInput,
                               uint32_t inputLen,
                               const uint8_t* pInitVector,
                               const uint8_t* pKey,
                               uint8_t* pOutput);
static void sw_aes_ctr( const uint8_t* pInput,
                        uint32_t inputLen,
                        uint8_t* pCounter,
                        const uint8_t* pKey,
                        uint8_t* pOutput);
static void sw_aes_cipher(bool cipher_noDecipher,
                          const uint8_t*  pInput,
                          uint32_t inputLen,
                          const uint8_t* pKey,
                          uint8_t* pOutput);
static status_t k32w0_hw_aes128_block_decrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput);
static status_t k32w0_hw_aes128_block_encrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput);
static status_t k32w0_aes_block_decrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput);
static status_t k32w0_aes_block_encrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput);
#endif
/*! *********************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
********************************************************************************** */


/* AES function - SW emulated*/
void sw_Aes128(const uint8_t *pData, const uint8_t *pKey, uint8_t enc, uint8_t *pReturnData);
uint8_t sw_AES128_CCM(uint8_t* pInput,    uint16_t inputLen,
                      uint8_t* pAuthData, uint16_t authDataLen,
                      uint8_t* pNonce,    uint8_t  nonceSize,
                      uint8_t* pKey,      uint8_t* pOutput,
                      uint8_t* pCbcMac,   uint8_t  macSize,
                      uint32_t flags);

/* SHA1 functions - SW emulated*/
void sw_sha1_initialize_output (uint32_t *sha1_state);
void sw_sha1_hash_n (const uint8_t *msg_data, int32_t num_blks, uint32_t *sha1_state);
void sw_sha1_hash   (const uint8_t *msg_data, uint32_t *sha1_state);
void sw_sha1_update (const uint8_t *msg_data, int32_t num_blks, uint32_t *sha1_state);

/* SHA256 functions - SW emulated*/
void sw_sha256_initialize_output (uint32_t *sha256_state);
void sw_sha256_hash_n (const uint8_t *msg_data, int32_t num_blks, uint32_t *sha256_state);
void sw_sha256_hash   (const uint8_t *msg_data, uint32_t *sha256_state);
void sw_sha256_update (const uint8_t *msg_data, int32_t num_blks, uint32_t *sha256_state);





/*! *********************************************************************************
*************************************************************************************
* Private prototypes
*************************************************************************************
********************************************************************************** */
#if !(JN_SHA_HW_ACC)
static void SHA1_hash_n(const uint8_t* pData, uint32_t nBlk, uint32_t* pHash);
#endif
static void SHA256_hash_n(const uint8_t* pData, uint32_t nBlk, uint32_t* pHash);

static void AES_128_CMAC_Generate_Subkey(const uint8_t *key, uint8_t *K1, uint8_t *K2);
static void SecLib_LeftShiftOneBit(uint8_t *input, uint8_t *output);
static void SecLib_Padding(const uint8_t *lastb, uint8_t *pad, uint32_t length);
static void SecLib_Xor128(const uint8_t *a, const uint8_t *b, uint8_t *out);


#if (!LTC_HW_ACC && !FSL_FEATURE_SOC_AES_HW && !(JN_AES_HW_ACC && !gSecLibAESMethodSelectionDynHwSw_c && !gSecLibAESHwUsedFromIsr))
static void AES_128_IncrementCounter(uint8_t* ctr);
#endif

static status_t k32w0_hw_aes_load_key(const uint8_t* pKey, size_t keyBitSize);



#if FSL_FEATURE_SOC_AES_HW
static void AES_128_ECB_Enc_HW(AES_param_t* ECB_p);
static void AES_128_ECB_Dec_HW(AES_param_t* ECB_p);
static void AES_128_ECB_Block_Enc_HW(AES_param_t* ECBB_p);
static void AES_128_ECB_Block_Dec_HW(AES_param_t* ECBB_p);
static void AES_128_CTR_Enc_HW(AES_param_t* CTR_p);
static void AES_128_CTR_Dec_HW(AES_param_t* CTR_p);
static void AES_128_CMAC_HW(AES_param_t* CMAC_p);
#endif
/*! *********************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
********************************************************************************** */

/*! *********************************************************************************
* \brief  This function performs initialization of the cryptographic HW acceleration.
*
********************************************************************************** */
void SecLib_Init(void)
{
#if LTC_HW_ACC
    LTC_Init(LTC0);
#elif FSL_FEATURE_SOC_AES_HW
  #ifdef CPU_QN908X
   #if USE_TASK_FOR_HW_AES
    AESM_Initialize();
   #endif
  #endif
#elif JN_AES_HW_ACC
    AES_Init(AES0);
#endif

#if USE_RTOS && (LTC_HW_ACC || MMCAU_HW_ACC || JN_AES_HW_ACC || FSL_FEATURE_SOC_AES_HW)
    /*! Initialize the MMCAU AES Context Buffer Mutex here. */
    /* Do not allocate heap memory again after getting out of low power
       and reinitializing SecLib if RAM retention is on*/
    if (mSecLibAesMutexId == NULL)
    {
        mSecLibAesMutexId = OSA_MutexCreate();
        if (mSecLibAesMutexId == NULL)
        {
            panic( ID_PANIC(0,0), (uint32_t)SecLib_Init, 0, 0 );
            return;
        }
    }
#endif

#if USE_RTOS && JN_SHA_HW_ACC
    if (mSecLibShaMutexId == NULL)
    {
        mSecLibShaMutexId = OSA_MutexCreate();
        if (mSecLibShaMutexId == NULL)
        {
            panic( ID_PANIC(0,0), (uint32_t)SecLib_Init, 0, 0 );
            return;
        }
    }
#endif
}


#if (gSecLibAESMethodSelectionDynHwSw_c > 0)
void SecLib_AES_HW_Accelerator_disable(bool_t DisableNEnable)
{
    OSA_InterruptDisable();
    if (DisableNEnable)
        force_sw_aes_execution_cnt++;
    else
        if (force_sw_aes_execution_cnt > 0)
            force_sw_aes_execution_cnt--;
    OSA_InterruptEnable();
}

bool_t  SecLib_AES_Is_HW_Accelerator_disabled(void)
{
    bool_t sw_exec = false;
    OSA_InterruptDisable();
    sw_exec = (force_sw_aes_execution_cnt > 0);
    OSA_InterruptEnable();

    return sw_exec;
}
#endif

#if !defined gSecLibAESHwUsedFromIsr || (gSecLibAESHwUsedFromIsr ==  0)
/*
 * gSecLibAESHwUsedFromIsr : if set the AES HW may be requested from an ISR context.
 *
 *  CBC and CTR operations can only be done in a semi-automatic way using
 *  the AES HW to perform ECB block by block only.
 *  Likewise AES ECB mode can only be done block by block.
 *  This mode implies that AES HW is mandated so it excludes the Dynamic switching becasue
 *  the AES HW is mandated for performance reasons..
 */


static status_t k32w0_hw_aes_cbc_encrypt(const uint8_t* pInput,
                              const uint32_t inputLen,
                              const uint8_t* pInitVector,
                              const uint8_t* pKey,
                              uint8_t* pOutput)
{
    status_t st;
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
            break;
        st = AES_EncryptCbc(AES0, pInput, pOutput, inputLen, pInitVector);
    } while (false);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
    return st;
}

static status_t k32w0_hw_aes_cbc_decrypt(const uint8_t* pInput,
                        uint32_t inputLen,
                        const uint8_t* pInitVector,
                        const uint8_t* pKey,
                        uint8_t* pOutput)
{
    status_t st;
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
            break;
        st = AES_DecryptCbc(AES0, pInput, pOutput, inputLen, pInitVector);
    } while (false);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
    return st;
}


static status_t k32w0_hw_aes_ctr_crypt(const uint8_t* pInput,
                     const uint32_t inputLen,
                     uint8_t* pCounter,
                     const uint8_t* pKey,
                     uint8_t* pOutput)
{
    status_t st;
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
            break;
        st = AES_CryptCtr(AES0, pInput, pOutput, inputLen, pCounter, NULL, NULL);
    } while (false);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
    return st;
}

static status_t k32w0_hw_aes_ecb_encrypt(const uint8_t* pInput,
        const uint32_t inputLen,
        const uint8_t* pKey,
        uint8_t* pOutput)
{
    status_t st;

    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();

    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
        {
            break;
        }
        st = AES_EncryptEcb(AES0, pInput, pOutput, inputLen);

    } while(false);

    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

    return st;
}

static status_t k32w0_hw_aes_ecb_decrypt(const uint8_t* pInput,
        const uint32_t inputLen,
        const uint8_t* pKey,
        uint8_t* pOutput)
{
    status_t st;

    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
        {
            break;
        }
        st = AES_DecryptEcb(AES0, pInput, pOutput, inputLen);
    } while(false);

    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

    return st;

}


#if (gSecLibAESMethodSelectionDynHwSw_c > 0)

static status_t k32w0_aes_ecb_encrypt(const uint8_t*  pInput, uint32_t inputLen, const uint8_t* pKey, uint8_t* pOutput)
{
    status_t st;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes_ecb_encrypt(pInput, inputLen, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */
        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_aes_cipher(true, pInput, inputLen, pKey, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}
static status_t k32w0_aes_ecb_decrypt(const uint8_t*  pInput, uint32_t inputLen, const uint8_t* pKey, uint8_t* pOutput)
{
    status_t st;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes_ecb_decrypt(pInput, inputLen, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */
        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_aes_cipher(false, pInput, inputLen, pKey, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}

static status_t k32w0_aes_cbc_encrypt(const uint8_t* pInput,
                           uint32_t inputLen,
                           const uint8_t* pInitVector,
                           const uint8_t* pKey,
                           uint8_t* pOutput)
{
    status_t st;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes_cbc_encrypt(pInput, inputLen, pInitVector, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_aes_cbc_encrypt(pInput, inputLen, pInitVector, pKey, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}

static status_t k32w0_aes_cbc_decrypt(const uint8_t* pInput,
                           uint32_t inputLen,
                           const uint8_t* pInitVector,
                           const uint8_t* pKey,
                           uint8_t* pOutput)
{
    status_t st;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes_cbc_decrypt(pInput, inputLen, pInitVector, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */
        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_aes_cbc_decrypt(pInput, inputLen, pInitVector, pKey, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}

static status_t k32w0_aes_ctr_crypt(const uint8_t* pInput,
                           const uint32_t inputLen,
                           uint8_t* pCounter,
                           const uint8_t* pKey,
                           uint8_t* pOutput)
{
    status_t st;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes_ctr_crypt(pInput, inputLen, pCounter, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */
        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_aes_ctr(pInput, inputLen, pCounter, pKey, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}


#else

#define k32w0_aes_cbc_encrypt   k32w0_hw_aes_cbc_encrypt
#define k32w0_aes_cbc_decrypt   k32w0_hw_aes_cbc_decrypt
#define k32w0_aes_ctr_crypt     k32w0_hw_aes_ctr_crypt
#define k32w0_aes_ecb_encrypt   k32w0_hw_aes_ecb_encrypt
#define k32w0_aes_ecb_decrypt   k32w0_hw_aes_ecb_decrypt

#endif  /* (gSecLibAESMethodSelectionDynHwSw_c > 0) */


#endif /* !(gSecLibAESHwUsedFromIsr > 0) */

/* AES 128 block crypto */
#if defined gSecLibAESMethodSelectionDynHwSw_c &&  (gSecLibAESMethodSelectionDynHwSw_c != 0)

static status_t k32w0_aes_block_decrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput)
{
    status_t st = kStatus_Success;
    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes128_block_decrypt(pInput, pKey, pOutput);
            break;
        }
        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_Aes128((uint8_t*)pInput, (uint8_t*)pKey, 0, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;
}

static status_t k32w0_aes_block_encrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput)
{
    status_t st = kStatus_Success;

    do {
        if (!SecLib_AES_Is_HW_Accelerator_disabled())
        {
            st = k32w0_hw_aes128_block_encrypt(pInput, pKey, pOutput);
            break;
        }
        /* If we reach here HW accelerator is disabled so no NULL pKey can be accepted */        if (pKey == NULL)
        {
            st = kStatus_InvalidArgument;
            break;
        }
        sw_Aes128((uint8_t*)pInput, (uint8_t*)pKey, 1, pOutput);
        st = kStatus_Success;
    } while (false);
    return st;

}
#else /* gSecLibAESMethodSelectionDynHwSw_c */
#define k32w0_aes_block_encrypt k32w0_hw_aes128_block_encrypt
#define k32w0_aes_block_decrypt k32w0_hw_aes128_block_decrypt
#endif /* gSecLibAESMethodSelectionDynHwSw_c */



/*! *********************************************************************************
* \brief  Set AES Key in AES HW Accelerator.
*
* \param[in]  pKey May be NULL if 128 bit EFUSE Key is to be used,
*             otherwise pointer on Key byte array
* \param[in]  keyBitSize : Key size in bits must be 128 for EFUSE key.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
static status_t k32w0_hw_aes_load_key(const uint8_t* pKey, size_t keyBitSize)
{
    status_t st;
    size_t keySize = (keyBitSize >> 3); /* Byte size */
    if (pKey != NULL)
    {
        /* kStatus_InvalidArgument may be returned if keySize is not 16, 24 or 32 */
        st = AES_SetKey(AES0, pKey, keySize);
    }
    else
    {
        if (keySize == 16u) /* AES 128 we use the EFUSEd Key */
        {
            efuseLoadUniqueKey();
            aesLoadKeyFromOTP(AES_KEY_128BITS);
            st = kStatus_Success;
        }
        else
        {
            st = kStatus_InvalidArgument;
        }
    }
    return st;
}

/*! *********************************************************************************
* \brief  Launch HW AES 128  ECB encryption operation over a single block :
*         length is implicitly 16 bytes
*
* \param[in]  pInput Pointer on input plaintext 
* \param[in]  pKey pointer on key - Length of key is implicitly 128 bit
*             may be NULL if meaning to use EFUSE secret key
* \param[out] pointer on output ciphertext buffer.
*
* Note: An operation may be interrupted by an ISR requesting the AES HW too.
* If so a global volatile variable is set so that the caller from the non ISR context
* can resume the operation that got cancelled as the ISR stole the resource.
*
********************************************************************************** */
static status_t k32w0_hw_aes128_block_encrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput)
{
    status_t st;
#if defined gSecLibAESHwUsedFromIsr && (gSecLibAESHwUsedFromIsr != 0)
    do {

        if (OSA_InIsrContext())
        {
            st = k32w0_hw_aes_load_key(pKey, 128u);
            if (st != kStatus_Success)
            {
                break;
            }
            st = AES_EncryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);
            bHasIsrInterrupted = true;
        }
        else
        {
            SECLIB_AES_MUTEX_LOCK();
            do
            {
                bHasIsrInterrupted = false;
                st = k32w0_hw_aes_load_key(pKey, 128u);
                if (st != kStatus_Success)
                {
                    break;
                }
                st = AES_EncryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);
            } while (bHasIsrInterrupted);
            SECLIB_AES_MUTEX_UNLOCK();
        }
    } while(false);

#else
    SECLIB_AES_MUTEX_LOCK();
    do {

        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
        {
            break;
        }
        st = AES_EncryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);

    } while(false);
    SECLIB_AES_MUTEX_UNLOCK();

#endif

    return st;
}


static status_t k32w0_hw_aes128_block_decrypt(const uint8_t *pInput, const uint8_t *pKey, uint8_t * pOutput)
{
    status_t st;

#if defined gSecLibAESHwUsedFromIsr && (gSecLibAESHwUsedFromIsr != 0)
    do {
        if (OSA_InIsrContext())
        {
            st = k32w0_hw_aes_load_key(pKey, 128u);
            if (st != kStatus_Success)
            {
                break;
            }
            st = AES_DecryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);
            bHasIsrInterrupted = true;
        }
        else

        {
            SECLIB_AES_MUTEX_LOCK();
            do
            {
                bHasIsrInterrupted = false;
                st = k32w0_hw_aes_load_key(pKey, 128u);
                if (st != kStatus_Success)
                {
                    break;
                }
                st = AES_DecryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);
            } while (bHasIsrInterrupted);
            SECLIB_AES_MUTEX_UNLOCK();
        }
    } while(false);

#else
    SECLIB_AES_MUTEX_LOCK();
    do {
        st = k32w0_hw_aes_load_key(pKey, 128u);
        if (st != kStatus_Success)
        {
            break;
        }
        st = AES_DecryptEcb(AES0, pInput, pOutput, AES_BLOCK_SIZE);
    } while(false);
    SECLIB_AES_MUTEX_UNLOCK();
#endif
    return st;
}




/*! *********************************************************************************
* \brief  Process current AES operation described by the context.
*         It wraps ROM API and offers mutex protection and protection
*         against ISR interruption.
*
* \param[in]  pBlockIn Pointer to the location of the input (plaintext/ciphertext).
*
* \param[in]  pBlockOut Pointer to the location of the output (plaintext/ciphertext).
*
* \param[in]  numBlocks Number of 16 bytes blocks to be processed.
*
********************************************************************************** */
uint32_t AES_128_ProcessBlocks(const void* pContext,
                               uint32_t* pBlockIn,
                               uint32_t* pBlockOut,
                               uint32_t  numBlocks)
{
    ErrorCode_t status = 0;

    const aesContext_t* context = (const aesContext_t*)pContext;
    while (numBlocks > 0)
    {
        status_t st;
        if (context->mode == AES_MODE_ECB_DECRYPT)
        {
            st = k32w0_hw_aes128_block_decrypt((const uint8_t *)pBlockIn, (const uint8_t*)context->pSoftwareKey, (uint8_t *)pBlockOut);
        }
        else
        {
            st = k32w0_hw_aes128_block_encrypt((const uint8_t *)pBlockIn, (const uint8_t*)context->pSoftwareKey, (uint8_t *)pBlockOut);
        }
        if (st != kStatus_Success)
            break;
        numBlocks--;
        pBlockIn += (AES_BLOCK_SIZE/sizeof(uint32_t));
        pBlockOut += (AES_BLOCK_SIZE/sizeof(uint32_t));
    }
    return (uint32_t)status;
}

/*! *********************************************************************************
* \brief  This function performs AES-128 encryption on one 16-byte AES block.
*
* \param[in]  pInput Pointer to the location of the 16-byte plain text block.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*             If NULL the key is already programmed.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address aligned to 4 bytes!
*
********************************************************************************** */
void AES_128_Encrypt(const uint8_t* pInput,
                     const uint8_t* pKey,
                     uint8_t* pOutput)
{

#if !JN_AES_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
#endif

#if MMCAU_HW_ACC
    mmcauAesContext_t *pCtx = &mmcauAesCtx;
    uint8_t* pIn;
    uint8_t* pOut;
    /* Check if pKey is 4 bytes aligned */
    if ((uint32_t)pKey & 0x00000003)
    {
        FLib_MemCpy(pCtx->alignedIn, (uint8_t*)pKey, AES_BLOCK_SIZE);
        pIn = pCtx->alignedIn;
    }
    else
    {
        pIn = (uint8_t*)pKey;
    }

    /* Expand Key */
    mmcau_aes_set_key(pIn, AES128, pCtx->keyExpansion);

    /* Check if pData is 4 bytes aligned */
    if ((uint32_t)pInput & 0x00000003)
    {
        FLib_MemCpy(pCtx->alignedIn, (uint8_t*)pInput, AES_BLOCK_SIZE);
        pIn = pCtx->alignedIn;
    }
    else
    {
        pIn = (uint8_t*)pInput;
    }

    /* Check if pReturnData is 4 bytes aligned */
    if ((uint32_t)pOutput & 0x00000003)
    {
        pOut = pCtx->alignedOut;
    }
    else
    {
        pOut = pOutput;
    }

    /* Encrypt data */
    mmcau_aes_encrypt(pIn, pCtx->keyExpansion, AES128_ROUNDS, pOut);

    if (pOut == pCtx->alignedOut)
    {
        FLib_MemCpy(pOutput, pCtx->alignedOut, AES_BLOCK_SIZE);
    }

#elif LTC_HW_ACC
    LTC_AES_EncryptEcb(LTC0, pInput, pOutput, AES_BLOCK_SIZE, pKey, AES_BLOCK_SIZE);
#elif FSL_FEATURE_SOC_AES_HW
    aes_enc_status_t hw_ase_status_flag;
    do
    {
        while( *(uint8_t *)(0x04000168 + 76) == true)
        {
            OSA_TaskYield();
        }
        __disable_irq();
        hw_ase_status_flag = AES_128_Encrypt_HW(pInput, pKey, pOutput);
        __enable_irq();
    } while(hw_ase_status_flag == HW_AES_Previous_Enc_on_going);
#elif (JN_AES_HW_ACC)
    k32w0_aes_block_encrypt(pInput, pKey, pOutput);
#else
    sw_Aes128(pInput, pKey, 1, pOutput);
#endif

 #if !JN_AES_HW_ACC
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
#endif
}




/*! *********************************************************************************
* \brief  This function performs AES-128 decryption on a 16-byte block.
*
* \param[in]  pInput Pointer to the location of the 16-byte plain text block.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_Decrypt(const uint8_t* pInput,
                     const uint8_t* pKey,
                     uint8_t* pOutput)
{
#if !JN_AES_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
#endif

#if MMCAU_HW_ACC
    mmcauAesContext_t *pCtx = &mmcauAesCtx;
    uint8_t* pIn;
    uint8_t* pOut;
    /* Check if pKey is 4 bytes aligned */
    if ((uint32_t)pKey & 0x00000003)
    {
        FLib_MemCpy( pCtx->alignedIn, (uint8_t*)pKey, AES_BLOCK_SIZE);
        pIn = pCtx->alignedIn;
    }
    else
    {
        pIn = (uint8_t*)pKey;
    }

    /* Expand Key */
    mmcau_aes_set_key(pIn, AES128, pCtx->keyExpansion);

    /* Check if pData is 4 bytes aligned */
    if ((uint32_t)pInput & 0x00000003)
    {
        FLib_MemCpy( pCtx->alignedIn, (uint8_t*)pInput, AES_BLOCK_SIZE);
        pIn = pCtx->alignedIn;
    }
    else
    {
        pIn = (uint8_t*)pInput;
    }

    /* Check if pReturnData is 4 bytes aligned */
    if ((uint32_t)pOutput & 0x00000003)
    {
        pOut = pCtx->alignedOut;
    }
    else
    {
        pOut = pOutput;
    }

    /* Decrypt data */
    mmcau_aes_decrypt(pIn, pCtx->keyExpansion, AES128_ROUNDS, pOut);

    if (pOut == pCtx->alignedOut)
    {
        FLib_MemCpy( pOutput, pCtx->alignedOut, AES_BLOCK_SIZE);
    }

#elif LTC_HW_ACC
    LTC_AES_DecryptEcb(LTC0, pInput, pOutput, AES_BLOCK_SIZE, pKey, AES_BLOCK_SIZE, kLTC_EncryptKey);
#elif FSL_FEATURE_SOC_AES_HW
    aes_enc_status_t hw_ase_status_flag;
    do
    {
        while( *(uint8_t *)(0x04000168 + 76) == true)
        {
            OSA_TaskYield();
        }
        __disable_irq();
        hw_ase_status_flag = AES_128_Decrypt_HW(pInput, pKey, pOutput);
        __enable_irq();
    } while(hw_ase_status_flag == HW_AES_Previous_Enc_on_going);
#elif JN_AES_HW_ACC
    k32w0_aes_block_decrypt(pInput, pKey, pOutput);
#else
    sw_Aes128(pInput, pKey, 0, pOutput);
#endif
#if !JN_AES_HW_ACC
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
#endif
}



#if (gSecLibAESMethodSelectionDynHwSw_c > 0) || (gSecLibAESHwUsedFromIsr > 0)

static void sw_aes_cipher(bool cipher_noDecipher,
                          const uint8_t* pInput,
                          uint32_t inputLen,
                          const uint8_t* pKey,
                          uint8_t* pOutput)
{
    /* If remaining data bigger than one AES block size */
    while( inputLen > AES_BLOCK_SIZE )
    {
        if (cipher_noDecipher)
            AES_128_Encrypt(pInput, pKey, pOutput);
        else
            AES_128_Decrypt(pInput, pKey, pOutput);
        pInput += AES_BLOCK_SIZE;
        pOutput += AES_BLOCK_SIZE;
        inputLen -= AES_BLOCK_SIZE;
    }
    /* Only do if there is remaining data: since we have consumed the whole AES blocks already
     * the remainder is smaller then one AES block size */
    if (inputLen > 0)
    {
        uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
        uint8_t tempBuffOut[AES_BLOCK_SIZE] = {0};
        FLib_MemCpy(tempBuffIn, pInput, inputLen);
           if (cipher_noDecipher)
               AES_128_Encrypt(tempBuffIn, pKey, tempBuffOut);
           else
               AES_128_Decrypt(tempBuffIn, pKey, tempBuffOut);
        FLib_MemCpy(pOutput, tempBuffOut, inputLen);
    }
}
#endif




/*! *********************************************************************************
* \brief  This function performs AES-128-ECB encryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Encrypt(const uint8_t* pInput,
                         uint32_t inputLen,
                         const uint8_t* pKey,
                         uint8_t* pOutput)
{
#if JN_AES_HW_ACC && !(gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_ecb_encrypt(pInput, inputLen, pKey, pOutput);
#elif FSL_FEATURE_SOC_AES_HW  /* HW AES */
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = pKey;
    pAES.Len = inputLen;
    pAES.pCipher = pOutput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pInput;
    pAES.Blocks = 0;
  #if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECB_Enc_Id, gAESMGR_ECB_Enc_c );
    AESM_SetParam( AES128ECB_Enc_Id, pAES, AES_128_ECB_Enc_HW);
    AESM_Start(AES128ECB_Enc_Id);
  #else
    AES_128_ECB_Enc_HW(&pAES);
  #endif /* USE_TASK_FOR_HW_AES */
#else /* SW AES */
    sw_aes_cipher(true, pInput, inputLen, pKey, pOutput);
#endif
}

/*! *********************************************************************************
 * \brief  This function performs AES-128-ECB decryption on a message block.
 *
 * \param[in]  pInput Pointer to the location of the input message.
 *
 * \param[in]  inputLen Input message length in bytes.
 *
 * \param[in]  pKey Pointer to the location of the 128-bit key.
 *
 * \param[out]  pOutput Pointer to the location to store the ciphered output.
 *
 * \pre All Input/Output pointers must refer to a memory address aligned to 4 bytes!
 *
 ********************************************************************************** */
void AES_128_ECB_Decrypt(const uint8_t *pInput, uint32_t inputLen, const uint8_t *pKey, uint8_t *pOutput)
{
#if JN_AES_HW_ACC && !(gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_ecb_decrypt(pInput, inputLen, pKey, pOutput);
#elif FSL_FEATURE_SOC_AES_HW  /* HW AES */
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key         = pKey;
    pAES.Len         = inputLen;
    pAES.pCipher     = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain      = pOutput;
    pAES.Blocks      = 0;
    #if (defined(USE_TASK_FOR_HW_AES) && (USE_TASK_FOR_HW_AES > 0))
    AESM_InitType(&AES128ECB_Dec_Id, gAESMGR_ECB_Dec_c);
    AESM_SetParam(AES128ECB_Dec_Id, pAES, AES_128_ECB_Dec_HW);
    AESM_Start(AES128ECB_Dec_Id);
    #else
    AES_128_ECB_Dec_HW(&pAES);
    #endif /* USE_TASK_FOR_HW_AES */
#else /* SW AES */
    sw_aes_cipher(false, pInput, inputLen, pKey, pOutput);
#endif
}

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB encryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  numBlocks Input message number of 16-byte blocks.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address aligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Block_Encrypt(uint8_t* pInput,
                               uint32_t numBlocks,
                               uint8_t* pKey,
                               uint8_t* pOutput)
{
#if FSL_FEATURE_SOC_AES_HW  /* HW AES */
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = (uint8_t*)pKey;
    pAES.Len = numBlocks * 16;
    pAES.pCipher = pOutput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pInput;
    pAES.Blocks = numBlocks;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECBB_Enc_Id, gAESMGR_ECB_Block_Enc_c );
    AESM_SetParam( AES128ECBB_Enc_Id, pAES, AES_128_ECB_Block_Enc_HW);
    AESM_Start(AES128ECBB_Enc_Id);
  #else
    AES_128_ECB_Block_Enc_HW(&pAES);
  #endif /* USE_TASK_FOR_HW_AES */
#else /* SW AES */
    while( numBlocks )
    {
        AES_128_Encrypt(pInput, pKey, pOutput);
        numBlocks--;
        pInput += AES_BLOCK_SIZE;
        pOutput += AES_BLOCK_SIZE;
    }
#endif /* FSL_FEATURE_SOC_AES_HW */
}

#if (gSecLibAESMethodSelectionDynHwSw_c > 0) || (gSecLibAESHwUsedFromIsr > 0)
static void sw_aes_cbc_encrypt(const uint8_t* pInput,
                               uint32_t inputLen,
                               const uint8_t* pInitVector,
                               const uint8_t* pKey,
                               uint8_t* pOutput)
{

    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t tempBuffOut[AES_BLOCK_SIZE] = {0};

    if( pInitVector != NULL )
    {
        FLib_MemCpy(tempBuffIn, pInitVector, AES_BLOCK_SIZE);
    }

    /* If remaining data is bigger than one AES block size */
    while( inputLen > AES_BLOCK_SIZE )
    {
        SecLib_XorN(tempBuffIn, pInput, AES_BLOCK_SIZE);
        AES_128_Encrypt(tempBuffIn, pKey, pOutput);
        FLib_MemCpy(tempBuffIn, pOutput, AES_BLOCK_SIZE);
        pInput += AES_BLOCK_SIZE;
        pOutput += AES_BLOCK_SIZE;
        inputLen -= AES_BLOCK_SIZE;
    }
    /*  Remaining data is necessarily <= than AES block size  */
    SecLib_XorN(tempBuffIn, pInput, inputLen);
    AES_128_Encrypt(tempBuffIn, pKey, tempBuffOut);
    FLib_MemCpy(pOutput, tempBuffOut, inputLen);

}
#endif



/*! *********************************************************************************
* \brief  This function performs AES-128-CBC encryption on a message block.
*         This function accepts arbitrary (non-multiple of AES block size) length data
*         in which case it can be used for data signing but the output in this case will
*         not be AES 128 CBC decryptable.
*         To be able to decrypt the output please use an input length which is a multiple of
*         the AES block size.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pInitVector Pointer to the location of the 128-bit initialization vector.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_CBC_Encrypt(const uint8_t* pInput,
                         const uint32_t inputLen,
                         const uint8_t* pInitVector,
                         const uint8_t* pKey,
                         uint8_t* pOutput)
{
#if LTC_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    LTC_AES_EncryptCbc(LTC0, pInput, pOutput, inputLen, pInitVector, pKey, AES_BLOCK_SIZE);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

#elif JN_AES_HW_ACC && ! (gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_cbc_encrypt(pInput,
                          inputLen,
                          pInitVector,
                          pKey,
                          pOutput);
#else
    sw_aes_cbc_encrypt(pInput, inputLen,
                        pInitVector, pKey, pOutput);
#endif
}


/*! *********************************************************************************
* \brief  This function performs AES-128-CBC encryption on a message block after
* padding it with 1 bit of 1 and 0 bits trail.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
*             IMPORTANT: User must make sure that input and output
*             buffers have at least inputLen + 16 bytes size
*
* \param[in]  pInitVector Pointer to the location of the 128-bit initialization vector.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* Return value: size of output buffer (after padding)
*
********************************************************************************** */
uint32_t AES_128_CBC_Encrypt_And_Pad(uint8_t* pInput,
                                     uint32_t inputLen,
                                     const uint8_t* pInitVector,
                                     const uint8_t* pKey,
                                     uint8_t* pOutput)
{
    uint32_t newLen = 0;
    uint32_t idx;
    /*compute new length*/
    newLen = inputLen + (AES_BLOCK_SIZE - (inputLen & (AES_BLOCK_SIZE-1)));
    /*pad the input buffer with 1 bit of 1 and trail of 0's from inputLen to newLen*/
    for(idx=0; idx < (newLen - inputLen)-1; idx++)
    {
        pInput[newLen-1 - idx] = 0x00;
    }
    pInput[inputLen] = 0x80;

    /* At this stage the padding has been appended: the length is a multiple of 16 bytes */

    /* CBC-Encrypt */
#if LTC_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    LTC_AES_EncryptCbc(LTC0, pInput, pOutput, newLen, pInitVector, pKey, AES_BLOCK_SIZE);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();
#elif JN_AES_HW_ACC && !(gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_cbc_encrypt(pInput, newLen, pInitVector, pKey, pOutput);
#else
    sw_aes_cbc_encrypt(pInput, newLen, pInitVector, pKey, pOutput);
#endif
    return newLen;
}

#if (gSecLibAESMethodSelectionDynHwSw_c > 0) || (gSecLibAESHwUsedFromIsr > 0)

static void sw_aes_cbc_decrypt(const uint8_t* pInput,
                               uint32_t inputLen,
                               const uint8_t* pInitVector,
                               const uint8_t* pKey,
                               uint8_t* pOutput)
{
    uint8_t temp[2*AES_BLOCK_SIZE] = {0};

    if(pInitVector != NULL)
    {
        FLib_MemCpy(temp, pInitVector, AES_BLOCK_SIZE);
    }

    FLib_MemCpy(temp + AES_BLOCK_SIZE, pInput, AES_BLOCK_SIZE);

    while( inputLen > 0 )
    {
        AES_128_Decrypt(pInput, pKey, pOutput);

        SecLib_XorN(pOutput, temp, AES_BLOCK_SIZE);

        pInput += AES_BLOCK_SIZE;
        pOutput += AES_BLOCK_SIZE;
        inputLen -= AES_BLOCK_SIZE;

        FLib_MemCpy(temp, temp + AES_BLOCK_SIZE, AES_BLOCK_SIZE);
        if(inputLen > 0)
        {
            FLib_MemCpy(temp + AES_BLOCK_SIZE, pInput, AES_BLOCK_SIZE);
        }
    }
}
#endif



/*! *********************************************************************************
* \brief  This function performs AES-128-CBC decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pInitVector Pointer to the location of the 128-bit initialization vector.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* Return value: size of output buffer (after depadding)
*
********************************************************************************** */
uint32_t AES_128_CBC_Decrypt_And_Depad(const uint8_t* pInput,
                                       uint32_t inputLen,
                                       const uint8_t* pInitVector,
                                       const uint8_t* pKey,
                                       uint8_t* pOutput)
{
    uint32_t newLen = inputLen;
    /* a CBC ciphered message must have a size multiple of 16 */
    if((inputLen & (AES_BLOCK_SIZE - 1)) != 0)
    {
        return 0;
    }
#if LTC_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    LTC_AES_DecryptCbc(LTC0, pInput, pOutput, inputLen, pInitVector, pKey, AES_BLOCK_SIZE, kLTC_DecryptKey);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

#elif JN_AES_HW_ACC && ! (gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_cbc_decrypt(pInput, inputLen, pInitVector, pKey, pOutput);
#else
    sw_aes_cbc_decrypt(pInput, inputLen, pInitVector, pKey, pOutput);
#endif

    while( (pOutput[--newLen] != 0x80) && (newLen !=0) ) {}
    return newLen;
}

#if (gSecLibAESMethodSelectionDynHwSw_c > 0) || (gSecLibAESHwUsedFromIsr > 0)
static void sw_aes_ctr( const uint8_t* pInput,
                        uint32_t inputLen,
                        uint8_t* pCounter,
                        const uint8_t* pKey,
                        uint8_t* pOutput)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t encrCtr[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( inputLen > AES_BLOCK_SIZE )
    {
        FLib_MemCpy(tempBuffIn, pInput, AES_BLOCK_SIZE);
        AES_128_Encrypt(pCounter, pKey, encrCtr);
        SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
        FLib_MemCpy(pOutput, tempBuffIn, AES_BLOCK_SIZE);
        pInput += AES_BLOCK_SIZE;
        pOutput += AES_BLOCK_SIZE;
        inputLen -= AES_BLOCK_SIZE;
        AES_128_IncrementCounter(pCounter);
    }

    /* Remaining data is <= than one AES block size  */
    FLib_MemCpy(tempBuffIn, pInput, inputLen);
    AES_128_Encrypt(pCounter, pKey, encrCtr);
    SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
    FLib_MemCpy(pOutput, tempBuffIn, inputLen);
    AES_128_IncrementCounter(pCounter);
}
#endif




/*! *********************************************************************************
* \brief  This function performs AES-128-CTR encryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pCounter Pointer to the location of the 128-bit counter.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_CTR(const uint8_t* pInput,
                 uint32_t inputLen,
                 uint8_t* pCounter,
                 const uint8_t* pKey,
                 uint8_t* pOutput)
{
#if FSL_FEATURE_SOC_AES_HW  /* HW AES */
    AES_param_t pAES;
    pAES.CTR_counter = pCounter;
    pAES.Key = pKey;
    pAES.Len = inputLen;
    pAES.pCipher = pOutput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pInput;
    pAES.Blocks = 0;
  #if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128CTR_Enc_Id, gAESMGR_CTR_Enc_c );
    AESM_SetParam( AES128CTR_Enc_Id, pAES, AES_128_CTR_Enc_HW);
    AESM_Start( AES128CTR_Enc_Id );
  #else
    AES_128_CTR_Enc_HW( &pAES );
  #endif /* USE_TASK_FOR_HW_AES */

#elif LTC_HW_ACC
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    LTC_AES_EncryptCtr(LTC0, pInput, pOutput, inputLen, pCounter, pKey, AES_BLOCK_SIZE, NULL, NULL);
    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

#elif JN_AES_HW_ACC && !(gSecLibAESHwUsedFromIsr > 0)
    k32w0_aes_ctr_crypt(pInput, inputLen, pCounter, pKey, pOutput);
#else
    sw_aes_ctr( pInput, inputLen, pCounter, pKey, pOutput);
#endif
}




/*! *********************************************************************************
* \brief  This function performs AES-128-CMAC on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Length of the input message in bytes. The input data must be provided MSB first.
*
* \param[in]  pKey Pointer to the location of the 128-bit key. The key must be provided MSB first.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte authentication code. The code will be generated MSB first.
*
* \remarks This is public open source code! Terms of use must be checked before use!
*
********************************************************************************** */
void AES_128_CMAC(const  uint8_t* pInput,
                  uint32_t inputLen,
                  const  uint8_t* pKey,
                  uint8_t* pOutput)
{
#if FSL_FEATURE_SOC_AES_HW /* HW AES */
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = pKey;
    pAES.Len = inputLen;
    pAES.pCipher = pOutput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pInput;
    pAES.Blocks = 0;
  #if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128CMAC_Id, gAESMGR_CMAC_Enc_c );
    AESM_SetParam( AES128CMAC_Id, pAES, AES_128_CMAC_HW);
    AESM_Start(AES128CMAC_Id);
  #else
    AES_128_CMAC_HW(&pAES);
  #endif /* USE_TASK_FOR_HW_AES */

#else /* SW AES */

    uint8_t X[16];
    uint8_t Y[16];
    uint8_t M_last[16] = {0};
    uint8_t padded[16] = {0};

    uint8_t K1[16] = {0};
    uint8_t K2[16] = {0};

    uint8_t n;
    uint32_t i;
    uint8_t flag;

    AES_128_CMAC_Generate_Subkey(pKey, K1, K2);

    n = (uint8_t) ((inputLen + AES_BLOCK_SIZE -1) / AES_BLOCK_SIZE); /* n is number of rounds */

    if (n == 0)
    {
        n = 1;
        flag = 0;
    }
    else
    {
        if ((inputLen % AES_BLOCK_SIZE) == 0)
        { /* last block is a complete block */
            flag = 1;
        }
        else
        { /* last block is not complete block */
            flag = 0;
        }
    }

    /* Process the last block  - the last part the MSB first input data */
    if (flag)
    { /* last block is complete block */
        SecLib_Xor128(&pInput[16 * (n - 1)], K1, M_last);
    }
    else
    {
        SecLib_Padding(&pInput[AES_BLOCK_SIZE * (n - 1)], padded, inputLen % 16);
        SecLib_Xor128(padded, K2, M_last);
    }

    for (i = 0; i < AES_BLOCK_SIZE; i++)
    {
        X[i] = 0;
    }

    for (i = 0; i < n - 1; i++)
    {
        SecLib_Xor128(X, &pInput[AES_BLOCK_SIZE * i], Y); /* Y := Mi (+) X  */
        AES_128_Encrypt(Y, pKey, X); /* X := AES-128(KEY, Y) */
    }

    SecLib_Xor128(X, M_last, Y);
    AES_128_Encrypt(Y, pKey, X);

    for (i = 0; i < AES_BLOCK_SIZE; i++)
    {
        pOutput[i] = X[i];
    }
#endif /* FSL_FEATURE_SOC_AES_HW */
}


/*! *********************************************************************************
* \brief  This function performs AES-128-CMAC on a message block accepting input data
*         which is in LSB first format and computing the authentication code starting fromt he end of the data.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Length of the input message in bytes. The input data must be provided LSB first.
*
* \param[in]  pKey Pointer to the location of the 128-bit key. The key must be provided MSB first.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte authentication code. The code will be generated MSB first.
*
********************************************************************************** */
void AES_128_CMAC_LsbFirstInput (const uint8_t* pInput,
                                 const uint32_t inputLen,
                                 const uint8_t* pKey,
                                 uint8_t* pOutput)
{
    uint8_t X[AES_BLOCK_SIZE];
    uint8_t Y[AES_BLOCK_SIZE];
    uint8_t M_last[AES_BLOCK_SIZE] = {0};
    uint8_t padded[AES_BLOCK_SIZE] = {0};
    uint8_t reversedBlock[AES_BLOCK_SIZE] = {0};

    uint8_t K1[AES_BLOCK_SIZE] = {0};
    uint8_t K2[AES_BLOCK_SIZE] = {0};

    uint8_t n;
    uint32_t i;
    uint8_t flag;

    AES_128_CMAC_Generate_Subkey((uint8_t*)pKey, K1, K2);

    n = (uint8_t) ((inputLen + (AES_BLOCK_SIZE-1)) / AES_BLOCK_SIZE); /* n is number of rounds */

    if (n == 0)
    {
        n = 1;
        flag = 0;
    }
    else
    {
        if ((inputLen % AES_BLOCK_SIZE) == 0) /* last block is a complete block */
        {
            flag = 1;
        }
        else /* last block is not complete block */
        {
            flag = 0;
        }
    }

    /* Process the last block  - the first part the LSB first input data */
    if (flag)  /* last block is complete block */
    {
        FLib_MemCpyReverseOrder (reversedBlock, &pInput[0], AES_BLOCK_SIZE);
        SecLib_Xor128 (reversedBlock, K1, M_last);
    }
    else
    {
        FLib_MemCpyReverseOrder (reversedBlock, &pInput[0], inputLen % AES_BLOCK_SIZE);
        SecLib_Padding(reversedBlock, padded, inputLen % AES_BLOCK_SIZE);
        SecLib_Xor128(padded, K2, M_last);
    }

    for (i = 0; i < AES_BLOCK_SIZE; i++)
    {
        X[i] = 0;
    }

    for (i = 0; i < n - 1; i++)
    {
        FLib_MemCpyReverseOrder (reversedBlock, &pInput[inputLen - AES_BLOCK_SIZE * (i + 1)], AES_BLOCK_SIZE);
        SecLib_Xor128(X, reversedBlock, Y); /* Y := Mi (+) X  */
        AES_128_Encrypt(Y, pKey, X); /* X := AES-128(KEY, Y) */
    }

    SecLib_Xor128(X, M_last, Y);
    AES_128_Encrypt(Y, pKey, X);

    for (i = 0; i < AES_BLOCK_SIZE; i++) {
        pOutput[i] = X[i];
    }
}


/*! *********************************************************************************
* \brief  This function performs AES 128 CMAC Pseudo-Random Function (AES-CMAC-PRF-128),
*         according to rfc4615, on a message block.
*
* \details The AES-CMAC-PRF-128 algorithm behaves similar to teh AES CMAC 128 algorithm
*          but removes 128 bit key size restriction.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Length of the input message in bytes.
*
* \param[in]  pVarKey Pointer to the location of the variable length key.
*
* \param[in]  varKeyLen Length of the input key in bytes
*
* \param[out]  pOutput Pointer to the location to store the 16-byte pseudo random variable.
*
********************************************************************************** */
void AES_CMAC_PRF_128(const uint8_t* pInput,
                      const uint32_t inputLen,
                      const uint8_t* pVarKey,
                      const uint32_t varKeyLen,
                      uint8_t* pOutput)
{
    uint8_t  K[16];  /*!< Temporary key location to be used if the key length is not 16 bytes. */
    const uint8_t* pCmacKey = pVarKey; /*!<  Pointer to the key used by the CMAC operation which generates the output. */
    if (varKeyLen)
    {
        if (varKeyLen != AES_BLOCK_SIZE)
        {
            uint8_t K0[AES_BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            /*! Perform AES 128 CMAC on the variable key if it has a length which
            *  is different from 16 bytes using a 128 bit key with all zeroes and
            *  set the CMAC key to point to the result. */
            AES_128_CMAC(pVarKey, varKeyLen, K0, K);
            pCmacKey = K;
        }

        /*! Perform the CMAC operation which generates the output using the local
        *  key pointer which will be set to the initial key or the generated one. */
        AES_128_CMAC(pInput, inputLen, pCmacKey, pOutput);
    }
}

/*! *********************************************************************************
* \brief  This function performs AES-128-EAX encryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Length of the input message in bytes.
*
* \param[in]  pNonce Pointer to the location of the nonce.
*
* \param[in]  nonceLen Nonce length in bytes.
*
* \param[in]  pHeader Pointer to the location of header.
*
* \param[in]  headerLen Header length in bytes.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte authentication code.
*
* \param[out]  pTag Pointer to the location to store the 128-bit tag.
*
********************************************************************************** */
secResultType_t AES_128_EAX_Encrypt(uint8_t* pInput,
                                    uint32_t inputLen,
                                    uint8_t* pNonce,
                                    uint32_t nonceLen,
                                    uint8_t* pHeader,
                                    uint8_t headerLen,
                                    uint8_t* pKey,
                                    uint8_t* pOutput,
                                    uint8_t* pTag)
{
    uint8_t *buf;
    uint32_t buf_len;
    uint8_t nonce_mac[AES_BLOCK_SIZE] = {0};
    uint8_t hdr_mac[AES_BLOCK_SIZE] = {0};
    uint8_t data_mac[AES_BLOCK_SIZE] = {0};
    uint8_t tempBuff[AES_BLOCK_SIZE] = {0};
    secResultType_t status = gSecSuccess_c;
    uint32_t i;

    if( nonceLen > inputLen )
    {
        buf_len = nonceLen;
    }
    else
    {
        buf_len = inputLen;
    }

    if( headerLen > buf_len )
    {
        buf_len = headerLen;
    }

    buf_len += AES_BLOCK_SIZE;

    buf = MEM_BufferAlloc(buf_len);

    if( buf == NULL )
    {
        status = gSecAllocError_c;
    }
    else
    {
        FLib_MemSet(buf, 0, 15);

        buf[15] = 0;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pNonce, nonceLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + nonceLen, pKey, nonce_mac);

        buf[15] = 1;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pHeader, headerLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + headerLen, pKey, hdr_mac);

        /* keep the original value of nonce_mac, because AES_128_CTR will increment it */
        FLib_MemCpy(tempBuff, nonce_mac, nonceLen);

        AES_128_CTR(pInput, inputLen, tempBuff, pKey, pOutput);

        buf[15] = 2;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pOutput, inputLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + inputLen, pKey, data_mac);

        for (i = 0; i < AES_BLOCK_SIZE; i++)
        {
            pTag[i] = nonce_mac[i] ^ data_mac[i] ^ hdr_mac[i];
        }

        MEM_BufferFree(buf);
    }

    return status;
}

/*! *********************************************************************************
* \brief  This function performs AES-128-EAX decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Length of the input message in bytes.
*
* \param[in]  pNonce Pointer to the location of the nonce.
*
* \param[in]  nonceLen Nonce length in bytes.
*
* \param[in]  pHeader Pointer to the location of header.
*
* \param[in]  headerLen Header length in bytes.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte authentication code.
*
* \param[out]  pTag Pointer to the location to store the 128-bit tag.
*
********************************************************************************** */
secResultType_t AES_128_EAX_Decrypt(uint8_t* pInput,
                                    uint32_t inputLen,
                                    uint8_t* pNonce,
                                    uint32_t nonceLen,
                                    uint8_t* pHeader,
                                    uint8_t headerLen,
                                    uint8_t* pKey,
                                    uint8_t* pOutput,
                                    uint8_t* pTag)
{
    uint8_t *buf;
    uint32_t buf_len;
    uint8_t nonce_mac[AES_BLOCK_SIZE] = {0};
    uint8_t hdr_mac[AES_BLOCK_SIZE] = {0};
    uint8_t data_mac[AES_BLOCK_SIZE] = {0};
    secResultType_t status = gSecSuccess_c;
    uint32_t i;

    if( nonceLen > inputLen )
    {
        buf_len = nonceLen;
    }
    else
    {
        buf_len = inputLen;
    }

    if( headerLen > buf_len )
    {
        buf_len = headerLen;
    }

    buf_len += AES_BLOCK_SIZE;

    buf = MEM_BufferAlloc(buf_len);

    if( buf == NULL )
    {
        status = gSecAllocError_c;
    }
    else
    {
        FLib_MemSet(buf, 0, AES_BLOCK_SIZE-1);

        buf[15] = 0;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pNonce, nonceLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + nonceLen, pKey, nonce_mac);

        buf[15] = 1;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pHeader, headerLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + headerLen, pKey, hdr_mac);

        buf[15] = 2;
        FLib_MemCpy((buf + AES_BLOCK_SIZE), pInput, inputLen);
        AES_128_CMAC(buf, AES_BLOCK_SIZE + inputLen, pKey, data_mac);

        MEM_BufferFree(buf);

        for (i = 0; i < AES_BLOCK_SIZE; i++)
        {
            if (pTag[i] != (nonce_mac[i] ^ data_mac[i] ^ hdr_mac[i]))
            {
                status = gSecError_c;
                break;
            }
        }

        if( gSecSuccess_c == status )
        {
            AES_128_CTR(pInput, inputLen, nonce_mac, pKey, pOutput);
        }
    }

    return status;
}

/*! *********************************************************************************
* \brief  This function performs AES-128-CCM on a message block.
*
* \param[in]  pInput       Pointer to the location of the input message (plaintext or cyphertext).
*
* \param[in]  inputLen     Length of the input plaintext in bytes when encrypting.
*                          Length of the input cypertext without the MAC length when decrypting.
*
* \param[in]  pAuthData    Pointer to the additional authentication data.
*
* \param[in]  authDataLen  Length of additional authentication data.
*
* \param[in]  pNonce       Pointer to the Nonce.
*
* \param[in]  nonceSize    The size of the nonce (7-13).
*
* \param[in]  pKey         Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput     Pointer to the location to store the plaintext data when decrypting.
*                          Pointer to the location to store the ciphertext data when encrypting.
*
* \param[out]  pCbcMac     Pointer to the location to store the Message Authentication Code (MAC) when encrypting.
*                          Pointer to the location where the received MAC can be found when decrypting.
*
* \param[out]  macSize     The size of the MAC.
*
* \param[out]  flags       Select encrypt/decrypt operations (gSecLib_CCM_Encrypt_c, gSecLib_CCM_Decrypt_c)
*
* \return 0 if encryption/decryption was successful; otherwise, error code for failed encryption/decryption
*
* \remarks At decryption, MIC fail is also signaled by returning a non-zero value.
*
********************************************************************************** */
uint8_t AES_128_CCM(const uint8_t* pInput,
                    const uint16_t inputLen,
                    const uint8_t* pAuthData,
                    const uint16_t authDataLen,
                    const uint8_t* pNonce,
                    const uint8_t  nonceSize,
                    const uint8_t* pKey,
                    uint8_t* pOutput,
                    uint8_t* pCbcMac,
                    uint8_t  macSize,
                    uint32_t flags)
{
    uint8_t status;

    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();

#if LTC_HW_ACC
    if( flags & gSecLib_CCM_Decrypt_c )
    {
        status = LTC_AES_DecryptTagCcm(LTC0, pInput, pOutput, inputLen, pNonce, nonceSize, pAuthData, authDataLen, pKey, AES_BLOCK_SIZE, pCbcMac, macSize);
    }
    else
    {
        status = LTC_AES_EncryptTagCcm(LTC0, pInput, pOutput, inputLen, pNonce, nonceSize, pAuthData, authDataLen, pKey, AES_BLOCK_SIZE, pCbcMac, macSize);
    }

#else
        status = sw_AES128_CCM((uint8_t*)pInput, (uint16_t)inputLen,
                               (uint8_t*)pAuthData, (uint16_t)authDataLen,
                               (uint8_t*)pNonce, (uint16_t)nonceSize,
                               (uint8_t*)pKey, pOutput, pCbcMac, macSize, flags);
#endif

    SECLIB_AES_MUTEX_UNLOCK();
    SecLib_AllowToSleep();

    return status;
}

/*! *********************************************************************************
* \brief  This function calculates XOR of individual byte pairs in two uint8_t arrays.
*         pDst[i] := pDst[i] ^ pSrc[i] for i=0 to n-1
*
* \param[in, out]  pDst First byte array operand for XOR and destination byte array
*
* \param[in]  pSrc Second byte array operand for XOR
*
* \param[in]  n  Length of the byte arrays which will be XORed
*
********************************************************************************** */
void SecLib_XorN(uint8_t* pDst,
                 const uint8_t* pSrc,
                 uint8_t n)
{
    while( n )
    {
        *pDst = *pDst ^ *pSrc;
        pDst = pDst + 1;
        pSrc = pSrc + 1;
        n--;
    }
}

/*! *********************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
********************************************************************************** */

#if (!LTC_HW_ACC && !FSL_FEATURE_SOC_AES_HW && !(JN_AES_HW_ACC && !gSecLibAESMethodSelectionDynHwSw_c && !gSecLibAESHwUsedFromIsr))
/*! *********************************************************************************
* \brief  Increments the value of a given counter vector.
*
* \param [in,out]     ctr         Counter.
*
* \remarks
*
********************************************************************************** */
static void AES_128_IncrementCounter(uint8_t* ctr)
{
    uint32_t i;
    for (i = 0; i < 4; i++)
    {
        uint32_t * pWrd = (uint32_t*)&ctr[12-4*i];
        uint32_t wrd = HAL_REV32(*pWrd);
        wrd ++;
        *pWrd = HAL_REV32(wrd);
        if (wrd != 0)
            break;
    }
}
#endif /* !(FSL_FEATURE_SOC_LTC_COUNT || FSL_FEATURE_SOC_AES_COUNT) */

/*! *********************************************************************************
* \brief  Generates the two subkeys that correspond two an AES key
*
* \param [in]    key        AES Key.
*
* \param [out]   K1         First subkey.
*
* \param [out]   K2         Second subkey.
*
* \remarks   This is public open source code! Terms of use must be checked before use!
*
********************************************************************************** */
static void AES_128_CMAC_Generate_Subkey(const uint8_t *key,
                                         uint8_t *K1,
                                         uint8_t *K2)
{
    const uint8_t const_Rb[AES_BLOCK_SIZE] = {
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x00,
                            0x00, 0x00, 0x00, 0x87};
    uint8_t L[AES_BLOCK_SIZE];
    uint8_t Z[AES_BLOCK_SIZE];
    uint8_t tmp[AES_BLOCK_SIZE] = {0};
    uint32_t i;

    for ( i=0; i<AES_BLOCK_SIZE; i++ )
    {
        Z[i] = 0;
    }

    AES_128_Encrypt(Z,key,L);

    if ( (L[0] & 0x80) == 0 )
    {
        /* If MSB(L) = 0, then K1 = L << 1 */
        SecLib_LeftShiftOneBit(L,K1);
    }
    else
    {
        /* Else K1 = ( L << 1 ) (+) Rb */
        SecLib_LeftShiftOneBit(L,tmp);
        SecLib_Xor128(tmp, const_Rb, K1);
    }

    if ( (K1[0] & 0x80) == 0 )
    {
        SecLib_LeftShiftOneBit(K1, K2);
    }
    else
    {
        SecLib_LeftShiftOneBit(K1, tmp);
        SecLib_Xor128(tmp, const_Rb, K2);
    }
}

/*! *********************************************************************************
* \brief    Shifts a given vector to the left with one bit.
*
* \param [in]      input         Input vector.
*
* \param [out]     output        Output vector.
*
* \remarks   This is public open source code! Terms of use must be checked before use!
*
********************************************************************************** */
static void SecLib_LeftShiftOneBit(uint8_t *input,
                                   uint8_t *output)
{
    int32_t i;
    uint8_t overflow = 0;

    for ( i=AES_BLOCK_SIZE-1; i>=0; i-- )
    {
        output[i] = input[i] << 1;
        output[i] |= overflow;
        overflow = (input[i] & 0x80) ? 1 : 0;
    }
}

/*! *********************************************************************************
* \brief  This function pads an incomplete 16 byte block of data, where padding is
*         the concatenation of x and a single '1',
*         followed by the minimum number of '0's, so that the total length is equal to 128 bits.
*
* \param[in, out] lastb Pointer to the last block to be padded
*
* \param[in]  pad       Padded block destination
*
* \param[in]  length    Number of bytes in the block to be padded
*
* \remarks   This is public open source code! Terms of use must be checked before use!
*
********************************************************************************** */
static void SecLib_Padding(const uint8_t *lastb,
                           uint8_t *pad,
                           uint32_t length)
{
    uint32_t j;

    /* original last block */
    for ( j=0; j<AES_BLOCK_SIZE; j++ ) {
        if ( j < length ) {
            pad[j] = lastb[j];
        } else if ( j == length ) {
            pad[j] = 0x80;
        } else {
            pad[j] = 0x00;
        }
    }
}

/*! *********************************************************************************
* \brief  This function Xors 2 blocks of 128 bits and copies the result to a set destination
*
* \param [in]    a        Pointer to the first block to XOR
*
* \param [in]    b        Pointer to the second block to XOR.
*
* \param [out]   out      Destination pointer
*
* \remarks   This is public open source code! Terms of use must be checked before use!
*
********************************************************************************** */
static void SecLib_Xor128(const uint8_t *a,
                          const uint8_t *b,
                          uint8_t *out)
{
    uint32_t i;

    for (i=0;i<AES_BLOCK_SIZE; i++)
    {
      out[i] = a[i] ^ b[i];
    }
}


/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a SHA1 context structure
*
* \return    Address of the SHA1 context buffer
*            Deallocate using SHA1_FreeCtx()
*
********************************************************************************** */
void* SHA1_AllocCtx (void)
{
    void* sha1Ctx = MEM_BufferAlloc(sizeof(sha1Context_t));

    return sha1Ctx;
}


/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the SHA1 context structure
*
* \param [in]    pContext    Address of the SHA1 context buffer
*
********************************************************************************** */
void SHA1_FreeCtx (void* pContext)
{
    MEM_BufferFree(pContext);
}


/*! *********************************************************************************
* \brief  This function clones a SHA1 context.
*         Make sure the size of the allocated destination context buffer is appropriate.
*
* \param [in]    pDestCtx    Address of the destination SHA1 context
* \param [in]    pSourceCtx  Address of the source SHA1 context
*
********************************************************************************** */
void SHA1_CloneCtx (void* pDestCtx, void* pSourceCtx)
{
    FLib_MemCpy(pDestCtx, pSourceCtx, sizeof(sha1Context_t));
}


/*! *********************************************************************************
* \brief  This function initializes the SHA1 context data
*
* \param [in]    pContext    Pointer to the SHA1 context data
*                            Allocated using SHA1_AllocCtx()
*
********************************************************************************** */
void SHA1_Init (void* pContext)
{
#if JN_SHA_HW_ACC
    /* lock SHA HW resource and */
    /* prevent device to go to low power until SHA processing finished */
    SecLib_DisallowToSleep();
    SECLIB_AES_MUTEX_LOCK();
    SHA_ClkInit(SHA0);
    SHA_Init(SHA0, pContext, kSHA_Sha1);
#else
    sha1Context_t* context = (sha1Context_t*)pContext;

    context->bytes = 0;
    context->totalBytes = 0;
#if MMCAU_HW_ACC
    (void)mmcau_sha1_initialize_output((const unsigned int*)context->hash);
#else
    sw_sha1_initialize_output(context->hash);
#endif
#endif
}


/*! *********************************************************************************
* \brief  This function performs SHA1 on multiple bytes and updates the context data
*
* \param [in]    pContext    Pointer to the SHA1 context data
*                            Allocated using SHA1_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA1_HashUpdate (void* pContext, const uint8_t* pData, uint32_t numBytes)
{

#if JN_SHA_HW_ACC
    SHA_Update(SHA0, pContext, pData, numBytes);
#else
    uint16_t blocks;
    sha1Context_t* context = (sha1Context_t*)pContext;

    /* update total byte count */
    context->totalBytes += numBytes;
    /* Check if we have at least 1 SHA1 block */
    if( context->bytes + numBytes < SHA1_BLOCK_SIZE )
    {
        /* store bytes for later processing */
        FLib_MemCpy(&context->buffer[context->bytes], pData, numBytes);
        context->bytes += numBytes;
    }
    else
    {
        /* Check for bytes leftover from previous update */
        if( context->bytes )
        {
            uint8_t copyBytes = SHA1_BLOCK_SIZE - context->bytes;

            FLib_MemCpy(&context->buffer[context->bytes], pData, copyBytes);
            SHA1_hash_n(context->buffer, 1, context->hash);
            pData += copyBytes;
            numBytes -= copyBytes;
            context->bytes = 0;
        }
        /* Hash 64 bytes blocks */
        blocks = numBytes/SHA1_BLOCK_SIZE;
        SHA1_hash_n(pData, blocks, context->hash);
        numBytes -= blocks*SHA1_BLOCK_SIZE;
        pData += blocks*SHA1_BLOCK_SIZE;
        /* Check for remaining bytes */
        if( numBytes )
        {
            context->bytes = numBytes;
            FLib_MemCpy(context->buffer, pData, numBytes);
        }
    }
#endif
}


/*! *********************************************************************************
* \brief  This function finalizes the SHA1 hash computaion and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA1 context data
*                               Allocated using SHA1_AllocCtx()
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA1_HashFinish (void* pContext, uint8_t*  pOutput)
{
#if JN_SHA_HW_ACC
    SHA_Finish(SHA0, pContext, pOutput, NULL);
    SHA_ClkDeinit(SHA0);
    /* Unlock SHA HW resource and allow device to go to low power */
    SecLib_AllowToSleep();
    SECLIB_AES_MUTEX_UNLOCK();
#else
    uint32_t i;
    uint32_t temp;
    sha1Context_t* context = (sha1Context_t*)pContext;
    uint32_t numBytes;

    /* update remaining bytes */
    numBytes = context->bytes;
    /* Add 1 bit (a 0x80 byte) after the message to begin padding */
    context->buffer[numBytes++] = 0x80;
    /* Chack for space to fit an 8 byte length field plus the 0x80 */
    if( context->bytes >= 56 )
    {
        /* Fill the rest of the chunk with zeros */
        FLib_MemSet(&context->buffer[numBytes], 0, SHA1_BLOCK_SIZE - numBytes);
        SHA1_hash_n(context->buffer, 1, context->hash);
        numBytes = 0;
    }
    /* Fill the rest of the chunk with zeros */
    FLib_MemSet(&context->buffer[numBytes], 0, SHA1_BLOCK_SIZE - numBytes);
    /* Append the total length of the message, in bits (bytes << 3) */
    context->totalBytes <<= 3;
    FLib_MemCpyReverseOrder(&context->buffer[60], &context->totalBytes, sizeof(uint32_t));
    SHA1_hash_n(context->buffer, 1, context->hash);
    /* Convert to Big Endian */
    for(i=0; i<SHA1_HASH_SIZE/sizeof(uint32_t); i++)
    {
        temp = context->hash[i];
        FLib_MemCpyReverseOrder(&context->hash[i], &temp, sizeof(uint32_t));
    }

    /* Copy the generated hash to the indicated output location */
    FLib_MemCpy(pOutput, (uint8_t*)(context->hash), SHA1_HASH_SIZE);
#endif
}


/*! *********************************************************************************
* \brief  This function performs all SHA1 steps on multiple bytes: initialize,
*         update and finish.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pData       Pointer to the input data
* \param [in]       numBytes    Number of bytes to hash
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA1_Hash (const uint8_t* pData, const uint32_t numBytes, uint8_t* pOutput)
{
    sha1Context_t context;

    SHA1_Init(&context);
    SHA1_HashUpdate(&context, pData, numBytes);
    SHA1_HashFinish(&context, pOutput);
}

/*! *********************************************************************************
* \brief  Initialize the SHA256 context data in SW.
*         SHA256_SW_* API was introduced to take into account lengthy SHA256
*         operations, which would block access to the hardware module. Instead,
*         software SHA256 can be used. Such an example is in Matter, where a
*         SHA256 process is started at initialization phase and it's finished
*         after the commissioning was successful.
*
* \param [in]    pContext    Pointer to the SHA256 context data
*
********************************************************************************** */
void SHA256_SW_Init(void* pContext)
{
    sha256Context_t* context = (sha256Context_t*)pContext;

    context->bytes = 0;
    context->totalBytes = 0;
#if FSL_FEATURE_SOC_MMCAU_COUNT
    (void)mmcau_sha256_initialize_output((const unsigned int*)context->hash);
#else
    sw_sha256_initialize_output(context->hash);
#endif
}


/*! *********************************************************************************
* \brief  Perform SW SHA256 on multiple bytes and updates the context data.
*
* \param [in]    pContext    Pointer to the SHA256 context data
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA256_SW_Update(void* pContext, const uint8_t* pData, uint32_t numBytes)
{
    uint16_t blocks;
    sha256Context_t* context = (sha256Context_t*)pContext;

    /* update total byte count */
    context->totalBytes += numBytes;
    /* Check if we have at least 1 SHA256 block */
    if( context->bytes + numBytes < SHA256_BLOCK_SIZE )
    {
        /* store bytes for later processing */
        FLib_MemCpy(&context->buffer[context->bytes], pData, numBytes);
        context->bytes += numBytes;
    }
    else
    {
        /* Check for bytes leftover from previous update */
        if( context->bytes )
        {
            uint8_t copyBytes = SHA256_BLOCK_SIZE - context->bytes;

            FLib_MemCpy(&context->buffer[context->bytes], pData, copyBytes);
            SHA256_hash_n(context->buffer, 1, context->hash);
            pData += copyBytes;
            numBytes -= copyBytes;
            context->bytes = 0;
        }
        /* Hash 64 bytes blocks */
        blocks = numBytes/SHA256_BLOCK_SIZE;
        SHA256_hash_n(pData, blocks, context->hash);
        numBytes -= blocks*SHA256_BLOCK_SIZE;
        pData += blocks*SHA256_BLOCK_SIZE;
        /* Check for remaining bytes */
        if( numBytes )
        {
            context->bytes = numBytes;
            FLib_MemCpy(context->buffer, pData, numBytes);
        }
    }
}


/*! *********************************************************************************
* \brief  Finalize the SW SHA256 hash computation and clear the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA256 context data
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA256_SW_Finish(void* pContext, uint8_t* pOutput)
{
    uint32_t i;
    uint32_t temp;
    uint32_t numBytes;
    sha256Context_t* context = (sha256Context_t*)pContext;

    /* update remaining bytes */
    numBytes = context->bytes;
    /* Add 1 bit (a 0x80 byte) after the message to begin padding */
    context->buffer[numBytes++] = 0x80;
    /* Chack for space to fit an 8 byte length field plus the 0x80 */
    if( context->bytes >= 56 )
    {
        /* Fill the rest of the chunk with zeros */
        FLib_MemSet(&context->buffer[numBytes], 0, SHA256_BLOCK_SIZE - numBytes);
        SHA256_hash_n(context->buffer, 1, context->hash);
        numBytes = 0;
    }
    /* Fill the rest of the chunk with zeros */
    FLib_MemSet(&context->buffer[numBytes], 0, SHA256_BLOCK_SIZE - numBytes);
    /* Append the total length of the message(Big Endian), in bits (bytes << 3) */
    context->totalBytes <<= 3;
    FLib_MemCpyReverseOrder(&context->buffer[60], &context->totalBytes, sizeof(uint32_t));
    SHA256_hash_n(context->buffer, 1, context->hash);
    /* Convert to Big Endian */
    for(i=0; i<SHA256_HASH_SIZE/sizeof(uint32_t); i++)
    {
        temp = context->hash[i];
        FLib_MemCpyReverseOrder(&context->hash[i], &temp, sizeof(uint32_t));
    }

    /* Copy the generated hash to the indicated output location */
    FLib_MemCpy(pOutput, (uint8_t*)(context->hash), SHA256_HASH_SIZE);
}

/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a SHA256 context structure
*
* \return    Address of the SHA256 context buffer
*            Deallocate using SHA256_FreeCtx()
*
********************************************************************************** */
void* SHA256_AllocCtx (void)
{
    void* sha256Ctx = MEM_BufferAlloc(sizeof(sha256Context_t));

    return sha256Ctx;
}


/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the SHA256 context structure
*
* \param [in]    pContext    Address of the SHA256 context buffer
*
********************************************************************************** */
void SHA256_FreeCtx (void* pContext)
{
    MEM_BufferFree(pContext);
}


/*! *********************************************************************************
* \brief  This function clones SHA256 context.
*         Make sure the size of the allocated destination context buffer is appropriate.
*
* \param [in]    pDestCtx    Address of the destination SHA256 context
* \param [in]    pSourceCtx  Address of the source SHA256 context
*
********************************************************************************** */
void SHA256_CloneCtx (void* pDestCtx, void* pSourceCtx)
{
   FLib_MemCpy(pDestCtx, pSourceCtx, sizeof(sha256Context_t));
}


/*! *********************************************************************************
* \brief  This function initializes the SHA256 context data.
*
* \param [in]    pContext    Pointer to the SHA256 context data
*                            Allocated using SHA256_AllocCtx()
*
********************************************************************************** */
void SHA256_Init (void* pContext)
{
#if JN_SHA_HW_ACC
    /* Timeout is set to 0 to force a task to switch to software SHA256
     * if mutex is already locked (hardware SHA256 operation in progress).*/
    if (SECLIB_SHA_MUTEX_LOCK(0) == osaStatus_Success && sHwSha256Context == NULL)
    {
        SecLib_DisallowToSleep();
        sHwSha256Context = pContext;
        SHA_ClkInit(SHA0);
        SHA_Init(SHA0, pContext, kSHA_Sha256);
    }
    else
    {
#if gSecLibUseSha256Alt_d
        SHA256_SW_Init(pContext);
#else
        /* User should explicitly use the switch mechanism between software and
         * hardware SHA256.
         * You are reaching this assert if a hardware SHA256 is in process and
         * another hardware SHA256 process is started. For example, this can
         * happen in mbedtls_entropy_func, where a SHA256 is started before the
         * previous one is finished:
         *   SHA256_Init(context1) -> SHA256_HashUpdate(context1)
         *   -> SHA256_Init(context2)
         * Please set gSecLibUseSha256Alt_d to 1 if you want to avoid this assert.
         * This will enable switching to software SHA256, if the mutex cannot be
         * locked. Please note that if mbedtls_sha256 ALT module is also used,
         * mbedlts_sha256_context will be defined inside sha256_alt.h.
         * mbedtls_sha256_context should be defined as sha256Context_t for this
         * mechanism to work correctly. Otherwise, there is a possibility of data
         * corruption due to memory differences between the structures (i.e. sha_ctx_t
         * and sha256Context_t).
         *
         * Please note:
         * - port/matter/ksdk_mbedtls.c redirects SHA256 calls through SecLib.
         * - port/ksdk/ksdk_mbedtls.c calls SHA256 driver API directly. */
        assert(0);
#endif
    }
#else
    SHA256_SW_Init(pContext);
#endif
}


/*! *********************************************************************************
* \brief  This function performs SHA256 on multiple bytes and updates the context data
*
* \param [in]    pContext    Pointer to the SHA256 context data
*                            Allocated using SHA256_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA256_HashUpdate(void* pContext, const uint8_t* pData, uint32_t numBytes)
{
#if JN_SHA_HW_ACC
    if (sHwSha256Context == pContext)
    {
        SHA_Update(SHA0, pContext, pData, numBytes);
    }
    else
    {
#if gSecLibUseSha256Alt_d
        SHA256_SW_Update(pContext, pData, numBytes);
#else
        /* See explanation in SHA256_Init. */
        assert(0);
#endif
    }
#else
    SHA256_SW_Update(pContext, pData, numBytes);
#endif
}


/*! *********************************************************************************
* \brief  This function finalizes the SHA256 hash computaion and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA256 context data
*                               Allocated using SHA256_AllocCtx()
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA256_HashFinish (void* pContext, uint8_t* pOutput)
{
#if JN_SHA_HW_ACC
    if (sHwSha256Context == pContext)
    {
        sHwSha256Context = NULL;
        SHA_Finish(SHA0, pContext, pOutput, NULL);
        SHA_ClkDeinit(SHA0);
        /* Unlock SHA HW resource and allow device to go to low power */
        SecLib_AllowToSleep();
        SECLIB_SHA_MUTEX_UNLOCK();
    }
    else
    {
#if gSecLibUseSha256Alt_d
        SHA256_SW_Finish(pContext, pOutput);
#else
        /* See explanation in SHA256_Init. */
        assert(0);
#endif
    }
#else
    SHA256_SW_Finish(pContext, pOutput);
#endif
}

/*! *********************************************************************************
* \brief  This function performs all SHA256 steps on multiple bytes: initialize,
*         update and finish.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pData       Pointer to the input data
* \param [in]       numBytes    Number of bytes to hash
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA256_Hash(const uint8_t* pData, uint32_t numBytes, uint8_t* pOutput)
{
    sha256Context_t context;

    SHA256_Init(&context);
    SHA256_HashUpdate(&context, pData, numBytes);
    SHA256_HashFinish(&context, pOutput);
}


/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a HMAC SHA256 context structure
*
* \return    Address of the HMAC SHA256 context buffer
*            Deallocate using HMAC_SHA256_FreeCtx()
*
********************************************************************************** */
void* HMAC_SHA256_AllocCtx(void)
{
    void* hmacSha256Ctx = MEM_BufferAlloc(sizeof(HMAC_SHA256_context_t));

    return hmacSha256Ctx;
}


/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the HMAC SHA256 context structure
*
* \param [in]    pContext    Address of the HMAC SHA256 context buffer
*
********************************************************************************** */
void HMAC_SHA256_FreeCtx(void* pContext)
{
    MEM_BufferFree (pContext);
}


/*! *********************************************************************************
* \brief  This function performs the initialization of the HMAC SHA256 context data
*
* \param [in]    pContext    Pointer to the HMAC SHA256 context data
*                            Allocated using HMAC_SHA256_AllocCtx()
* \param [in]    InKey       Pointer to the HMAC key - Input Key material
* \param [in]    InKeyLen    Length of the HMAC key in bytes
*
********************************************************************************** */
void HMAC_SHA256_Init(void* pContext, const uint8_t* InKey, const size_t InKeyLen)
{
    uint8_t i;
    HMAC_SHA256_context_t* context = (HMAC_SHA256_context_t*)pContext;
    uint8_t sha256HashKeyBuffer[SHA256_HASH_SIZE] = {0};
    uint8_t * pKey;
    size_t keyLen;

    if( InKeyLen > SHA256_BLOCK_SIZE )
    {
        SHA256_Hash(InKey, InKeyLen, sha256HashKeyBuffer);
        pKey = sha256HashKeyBuffer;
        keyLen = SHA256_HASH_SIZE;
    }
    else
    {
        pKey = (uint8_t*)InKey;
        keyLen = InKeyLen;
    }
    SHA256_Init(&context->shaCtx);
    FLib_MemSet(context->pad, gHmacIpad_c, SHA256_BLOCK_SIZE);
    for( i = 0; i < keyLen; i++ )
    {
        context->pad[i] ^= pKey[i];
    }
    /* start hashing of the i_pad */
    SHA256_HashUpdate(&context->shaCtx, context->pad, SHA256_BLOCK_SIZE);

    /* create o_pad by xor-ing pad[i] with 0x36 ^ 0x5C: */
    for(i=0; i<SHA256_BLOCK_SIZE; i++)
    {
        context->pad[i] ^= (gHmacIpad_c^gHmacOpad_c);
    }
}

/*! *********************************************************************************
* \brief  This function performs HMAC update with the input data.
*
* \param [in]    pContext    Pointer to the HMAC SHA256 context data
*                            Allocated using HMAC_SHA256_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void HMAC_SHA256_Update(void* pContext, const uint8_t* pData, uint32_t numBytes)
{
    HMAC_SHA256_context_t* context = (HMAC_SHA256_context_t*)pContext;

    SHA256_HashUpdate(&context->shaCtx, pData, numBytes);
}


/*! *********************************************************************************
* \brief  This function finalizes the HMAC SHA256 computaion and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the HMAC SHA256 context data
*                               Allocated using HMAC_SHA256_AllocCtx()
* \param [in,out]   pOutput     Pointer to the output location
*
********************************************************************************** */
void HMAC_SHA256_Finish(void* pContext, uint8_t* pOutput)
{
    uint8_t hash1[SHA256_HASH_SIZE];
    HMAC_SHA256_context_t* context = (HMAC_SHA256_context_t*)pContext;

    /* finalize the hash of the i_key_pad and message */
    SHA256_HashFinish(&context->shaCtx, hash1);
    /* perform hash of the o_key_pad and hash1 */
    SHA256_Init(&context->shaCtx);
    SHA256_HashUpdate(&context->shaCtx, context->pad, SHA256_BLOCK_SIZE);
    SHA256_HashUpdate(&context->shaCtx, (const uint8_t*)hash1, SHA256_HASH_SIZE);
    SHA256_HashFinish(&context->shaCtx, pOutput);
}


/*! *********************************************************************************
* \brief  This function performs all HMAC SHA256 steps on multiple bytes: initialize,
*         update, finish, and update context data.
*         The final HMAC value is stored at the provided output location.
*
* \param [in]       pKey        Pointer to the HMAC key
* \param [in]       keyLen      Length of the HMAC key in bytes
* \param [in]       pData       Pointer to the input data
* \param [in]       numBytes    Number of bytes to perform HMAC on
* \param [in,out]   pOutput     Pointer to the output location
*
********************************************************************************** */
void HMAC_SHA256 (const uint8_t *pKey,
                  const size_t  keyLen,
                  const uint8_t *pData,
                  const size_t  numBytes,
                  uint8_t       *pOutput)
{
    HMAC_SHA256_context_t context;

    HMAC_SHA256_Init(&context, pKey, keyLen);
    HMAC_SHA256_Update(&context, pData, numBytes);
    HMAC_SHA256_Finish(&context, pOutput);
}




/****************************************************************************
 *
 * NAME:       bACI_WriteKey
 */
/**
 * This function setups the key in the AES.
 *
 * @ingroup
 *
 * @param psKeyData               tsReg128 key split over 4 words (16 bytes)
 *
 * @note
 *
 ****************************************************************************/
bool_t bACI_WriteKey(tsReg128 *psKeyData)
{
    /* For kw41, LTC_AES_EncryptEcb api directly needs key data instead
    * of JN where key is set first. */
    FLib_MemCpy(&sKey, psKeyData, sizeof(tsReg128));
    return TRUE;
}

/****************************************************************************
 *
 * NAME:       vACI_OptimisedCcmStar
 */
/**
 * This function performs CCM* AES encryption/decryption with checksum
 * generation/verification. Assumes input buffers are aligned and nonce has a
 * free byte at the start for the flags field
 *
 * @ingroup
 *
 * @param bEncrypt               TRUE to encrypt, FALSE to decrypt
 * @param u8M                    Required number of checksum bytes
 * @param u8alength              Length of authentication data, in bytes
 * @param u8mlength              Length of input data, in bytes
 * @param puNonce                Pre-allocated pointer to a structure
 *                               containing 128-bit Nonce data
 * @param pau8authenticationData Pre-allocated pointer to byte array of
 *                               authentication data
 * @param pau8Data               Pre-allocated pointer to byte array of input
 *                               and output data
 * @param pau8checksumData       Pre-allocated pointer to byte array of
 *                               checksum data
 * @param pbChecksumVerify       Pre-allocated pointer to boolean which in CCM
 *                               decode mode stores the result of the checksum
 *                               verification operation
 *
 * @note
 *
 ****************************************************************************/
void vACI_OptimisedCcmStar(bool_t         bEncrypt,
                           uint8_t        u8M,
                           uint8_t        u8alength,
                           uint8_t        u8mlength,
                           tuAES_Block   *puNonce,
                           uint8_t       *pau8authenticationData,
                           uint8_t       *pau8Data,
                           uint8_t       *pau8checksumData,
                           bool_t        *pbChecksumVerify)
{
    uint32_t u32BlockCnt;
    int i,j;
    tuAES_Block uOut;
    tuAES_Block uCalculatedMic;
    tuAES_Block uRxedMic;
    uint8_t *pu8Out;
    uint8_t *pu8In;

    /* Bounds checking on u8M:
     * 1. To ensure that it will never overflow the MIC storage arrays, for
     *    MISRA C compliance
     * 2. To limit u8M to even values. According to the generic CCM*
     *    definition in IEEE802.15.4-2006, valid values are 0, 4, 6, 8, 10,
     *    12, 14 or 16 but we let 2 through as well. This does mean that the M
     *    field of the Flags field in the Nonce has the same value for a u8M
     *    of 0 or 2, but in practice this form of the Flags field is only used
     *    when u8M is non-0 anyway */
    if (u8M > 16U)
    {
        u8M = 16U;
    }
    else
    {
        /* Round down to even value by zeroing bit 0 */
        u8M &= 0xfeU;
    }

    /**************************************************/
    /* If we are Decrypting - then do this first      */
    /**************************************************/
    if (bEncrypt == FALSE)
    {
        /* Decrypt the data */
        pu8Out = pau8Data;

        /* Add in CTR Flags */
        puNonce->au8[0] =(uint8_t)((L_SIZE - 1) << L_SHIFT);
        INITIALISE_NONCE_TOP_BYTE(puNonce->au8);

        u32BlockCnt = 0;
        for (i = 0; i < u8mlength; i++)
        {
            j = i & 0xf;
            if (j == 0)
            {
                /* generate new keystream block */
                /* Start block counter at 1 for PDU; A[0] is for Mic */
                u32BlockCnt++;
                UPDATE_NONCE_COUNTER(puNonce->au8, u32BlockCnt);

                /* Encrypt the Counter */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            }

            /* XOR in the keystream and copy into both output buffer and temp buffer */
            *pu8Out ^= uOut.au8[j];
            pu8Out++;
        }

        /* Decrypt the Received MIC */
        if (u8M > 0)
        {
            /* MIC encryption uses block counter = 0 */
            puNonce->au8[14] = 0;
            puNonce->au8[15] = 0;
            (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            /* Store the MIC for Comparison later */
            pu8Out = uRxedMic.au8;
            pu8In = pau8checksumData;
            for (i = 0; i < u8M; i++)
            {
                *pu8Out = *pu8In ^ uOut.au8[i];
                pu8Out++;
                pu8In++;
            }
        }
    }
    /********************************************/
    /* If we are calculating the MIC, do it now */
    /********************************************/
    if (u8M > 0) /* Only even values are possible, enforced at the start of
                  * the function, so > 0 also implies >= 2, hence there is no
                  * possibility of underflow of the (u8M - 2) calculation
                  * below */
    {
        /* Add in CBC-MAC Flags */
        puNonce->au8[0] =(uint8_t)(  ((u8alength > 0) ? A_DATA : 0)
                                 + (((u8M - 2) / 2) << M_SHIFT)
                                 + ((L_SIZE - 1) << L_SHIFT)
                                );

        /* Add in l(m). The octet order is clearly specified in CCM* as */
        /* 'most-significant-octet first order' */
        puNonce->au8[14] = 0; /* Was: Lo8(u8mlength >> 8); */
        puNonce->au8[15] = Lo8(u8mlength);

        /* Generate the first AES block for CBC-MAC */
        (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
        /* Initialise input counter */
        j = 0;

        /* Encode L(a) at the header if necessary */
        if (u8alength > 0)
        {
            /* Removed XOR with top byte of u8alength, as will always be 0.
             * Was: uOut.au8[j++] ^= Lo8(u8alength >> 8);
             * Now: j++; */
            j++;
            uOut.au8[j++] ^= Lo8(u8alength);
        }

        /* Generate further codes for the MIC in place */
        for (i = 0; i < u8alength; i++)
        {
            /* Perform the CBC XOR */
            uOut.au8[j] ^= pau8authenticationData[i];
            j++;

            /* Full Block, or hit pad boundary */
            if ((j == AES_BLOCK_SIZE) || (i == (u8alength - 1)))
            {
                /* Following is to emulate the hardware bug in the JN5148. The
                   hardware prepended the pair of length bytes in hardware,
                   and although it took in 16 bytes at a time (appended with
                   zeroes as necessary for the last stripe) it only used 14 of
                   them at that time (to complete a 16 byte stripe) and held
                   back 2 bytes for the next stripe. But if the final stripe
                   only consisted of one or both of the held back bytes, there
                   wasn't another stripe coming in from the higher layer and
                   the hardware appended 14 bytes from the previous stripe
                   rather than add zeroes itself. So we emulate this by XORing
                   in those bytes again */
                if (g_bLegacyHwBugEmulation && (j < 3))
                {
                    uint8_t *pu8Data;

                    /* Bug only happens for u8alength of (15 + 16.x) or
                       (16 + 16.x); we aren't bothering with the case where
                       u8alength is 0. In both cases we need to XOR back in
                       the 14 bytes from just before the one or two in this
                       stripe. So if u8alength is 15, there is 1 byte in this
                       stripe and we want bytes 0-13. For u8alength of 16,
                       there are 2 bytes in this stripe and we still want
                       bytes 0-13. Similarly for u8alength of 31 or 32, 47 or
                       48, etc. */
                    pu8Data = &pau8authenticationData[(u8alength - 15) & 0xfe];

                    /* XOR data from previous stripe */
                    for (j = 2; j < AES_BLOCK_SIZE; j++)
                    {
                        uOut.au8[j] ^= *pu8Data;
                        pu8Data++;
                    }
                }
                /* Encrypt the CBC-MAC block, in place */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)&uOut,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
                /* the block is now empty */
                j = 0;
            }
        }

        for (i = 0; i < u8mlength; i++)
        {
            /* Perform the CBC XOR */
            uOut.au8[j] ^= pau8Data[i];
            j++;

            /* Full Block, or hit pad boundary */
            if ((j == AES_BLOCK_SIZE) || (i == (u8mlength - 1)))
            {
                /* Encrypt the CBC-MAC block, in place */
               (void)AES_128_ECB_Encrypt(
                         (uint8_t*)&uOut,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
                /* the block is now empty */
                j = 0;
            }
        }

        /* Save the MIC */
        FLib_MemCpy(uCalculatedMic.au8, uOut.au8, u8M);
    }

    /**************************************************/
    /* If we are Encrypting */
    /**************************************************/
    if (bEncrypt)
    {
        /* Encrypt the data */
        pu8Out = pau8Data;

        /* Add in CTR Flags */
        puNonce->au8[0] =(uint8_t)((L_SIZE - 1) << L_SHIFT);
        INITIALISE_NONCE_TOP_BYTE(puNonce->au8);

        u32BlockCnt = 0;
        for (i = 0; i < u8mlength; i++)
        {
            j = i & 0xf;
            if (j == 0)
            {
                /* generate new keystream block */
                /* Start block counter at 1 for PDU; A[0] is for Mic */
                u32BlockCnt++;
                UPDATE_NONCE_COUNTER(puNonce->au8, u32BlockCnt);

                /* Encrypt the Counter */
                (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            }
            /* XOR in the keystream and copy to output buffer */
            *pu8Out ^= uOut.au8[j];
            pu8Out++;
        }

        /* MIC encryption uses block counter = 0 */
        puNonce->au8[14] = 0;
        puNonce->au8[15] = 0;

        /*---- truncate, encrypt, and append MIC to packet */
        if (u8M > 0)
        {
            /* Encrypt the Counter */
           (void)AES_128_ECB_Encrypt(
                         (uint8_t*)puNonce,
                         AES_BLOCK_SIZE,
                         (uint8_t*)&sKey,
                         (uint8_t*)&uOut);
            /* Append the encrypted MIC */
            pu8Out = pau8checksumData;
            pu8In = uCalculatedMic.au8;
            for (i = 0; i < u8M; i++)
            {
                *pu8Out = *pu8In ^ uOut.au8[i];
                pu8Out++;
                pu8In++;
            }
        }
    }
    else
    {
        /* Compare the Received MIC with Calculated MIC */
        if (FLib_MemCmp(uCalculatedMic.au8, uRxedMic.au8, u8M))
        {
            *pbChecksumVerify = TRUE;
        }
        else
        {
            *pbChecksumVerify = FALSE;
        }
    }
}







/*! *********************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
********************************************************************************** */
#if !(JN_SHA_HW_ACC)

/*! *********************************************************************************
* \brief  This function performs SHA1 on multiple blocks
*
* \param [in]    pData      Pointer to the input data
* \param [in]    nBlk       Number of SHA1 blocks to hash
* \param [in]    context        Pointer to the SHA1 context data
*
********************************************************************************** */
static void SHA1_hash_n(const uint8_t* pData, uint32_t nBlk, uint32_t* pHash)
{
    if( nBlk )
    {
        SecLib_DisallowToSleep();
#if FSL_FEATURE_SOC_MMCAU_COUNT
        mmcau_sha1_hash_n(pData, nBlk, (unsigned int *)pHash);
#else
        sw_sha1_hash_n(pData, nBlk, pHash);
#endif
        SecLib_AllowToSleep();
    }
}
#endif

/*! *********************************************************************************
* \brief  This function performs SHA256 on multiple blocks
*
* \param [in]    pData      Pointer to the input data
* \param [in]    nBlk       Number of SHA256 blocks to hash
* \param [in]    context        Pointer to the SHA256 context data
*
********************************************************************************** */
static void SHA256_hash_n(const uint8_t* pData, uint32_t nBlk, uint32_t* pHash)
{
    if( nBlk )
    {
        SecLib_DisallowToSleep();
#if FSL_FEATURE_SOC_MMCAU_COUNT
        mmcau_sha256_hash_n(pData, nBlk, (unsigned int *)pHash);
#else
        sw_sha256_hash_n(pData, nBlk, pHash);
#endif
        SecLib_AllowToSleep();
    }
}

/****************************************************************************
 *
 * NAME:       u32Reverse
 */
/**
 * Reverses 32bit data
 *
 * @ingroup grp_aes_sw
 *
 * @param u32InWord  Input 32-bit data
 *
 * @return u32OutWord Output reversed 32- bit data
 *
 * @note
 *
 ****************************************************************************/
static uint32_t u32Reverse(uint32_t u32InWord)
{
    uint32_t u32OutWord;

    __asm volatile ("REV %[reverse], %[input];"
                  : [reverse] "=r" (u32OutWord)
                  : [input]  "r"  (u32InWord)   );

    return u32OutWord;
}

/****************************************************************************
 *
 * NAME:       vSwipeEndian
 */
/**
 * Reverses 1282bit data between AESSW_Block_u and tsReg128
 *
 * @ingroup grp_aes_sw
 *
 * @param puBlock  128 bit data of type AESSW_Block_u
 *
 * @param psReg  128 bit data of type  tsReg128
 *
 * @param bBlockToReg  direction of converesion
 *                      1 = AESSW_Block_u to tsReg128
 *                      0 = tsReg128 to AESSW_Block_u
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
void vSwipeEndian(AESSW_Block_u *puBlock, tsReg128 *psReg, bool_t bBlockToReg)
{
    int i=0;
    for (i =0;i< (AES_BLOCK_SIZE/4);i++)
    {
        if(bBlockToReg)
            ((uint32_t*)psReg)[i] = u32Reverse((uint32_t)(puBlock->au32[i]));
        else
            puBlock->au32[i]  = u32Reverse(((uint32_t*)psReg)[i]);
    }
}


#if FSL_FEATURE_SOC_AES_HW

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 ECB encryption
*
* \param [in]    ECB_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_ECB_Dec_HW(AES_param_t* ECB_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t tempBuffOut[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( ECB_p->Len > AES_BLOCK_SIZE )
    {
        AES_128_Decrypt(ECB_p->pCipher, ECB_p->Key, ECB_p->pPlain);
        ECB_p->pPlain += AES_BLOCK_SIZE;
        ECB_p->pCipher += AES_BLOCK_SIZE;
        ECB_p->Len -= AES_BLOCK_SIZE;
    }

    /* If remaining data is smaller then one AES block size */
    FLib_MemCpy(tempBuffIn, ECB_p->pCipher, ECB_p->Len);
    AES_128_Decrypt(tempBuffIn, ECB_p->Key, tempBuffOut);
    FLib_MemCpy(ECB_p->pPlain, tempBuffOut, ECB_p->Len);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECB_Dec_Id );
#endif /* USE_TASK_FOR_HW_AES */
}
/*! *********************************************************************************
* \brief  This function performs hardware AES-128 ECB encryption
*
* \param [in]    ECB_p      Pointer to AES parameter structure
*
********************************************************************************** */

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Decrypt(uint8_t* pInput,
                         uint32_t inputLen,
                         uint8_t* pKey,
                         uint8_t* pOutput)
{
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = pKey;
    pAES.Len = inputLen;
    pAES.pCipher = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pOutput;
    pAES.Blocks = 0;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECB_Dec_Id, gAESMGR_ECB_Dec_c );
    AESM_SetParam( AES128ECB_Dec_Id, pAES, AES_128_ECB_Dec_HW);
    AESM_Start(AES128ECB_Dec_Id);
#else
    AES_128_ECB_Dec_HW(&pAES);
#endif /* USE_TASK_FOR_HW_AES */
}

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  numBlocks Input message number of 16-byte blocks.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Block_Decrypt(uint8_t* pInput,
                               uint32_t numBlocks,
                               uint8_t* pKey,
                               uint8_t* pOutput)
{
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = (uint8_t*)pKey;
    pAES.Len = numBlocks * 16;
    pAES.pCipher = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pOutput;
    pAES.Blocks = numBlocks;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECBB_Dec_Id, gAESMGR_ECB_Block_Dec_c );
    AESM_SetParam( AES128ECBB_Dec_Id, pAES, AES_128_ECB_Block_Dec_HW);
    AESM_Start(AES128ECBB_Dec_Id);
#else
    AES_128_ECB_Block_Dec_HW(&pAES);
#endif /* USE_TASK_FOR_HW_AES */
}

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  numBlocks Input message number of 16-byte blocks.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Block_Decrypt(uint8_t* pInput,
                               uint32_t numBlocks,
                               uint8_t* pKey,
                               uint8_t* pOutput)
{
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = (uint8_t*)pKey;
    pAES.Len = numBlocks * 16;
    pAES.pCipher = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pOutput;
    pAES.Blocks = numBlocks;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECBB_Dec_Id, gAESMGR_ECB_Block_Dec_c );
    AESM_SetParam( AES128ECBB_Dec_Id, pAES, AES_128_ECB_Block_Dec_HW);
    AESM_Start(AES128ECBB_Dec_Id);
#else
    AES_128_ECB_Block_Dec_HW(&pAES);
#endif /* USE_TASK_FOR_HW_AES */
}

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  numBlocks Input message number of 16-byte blocks.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address alligned to 4 bytes!
*
********************************************************************************** */
void AES_128_ECB_Block_Decrypt(uint8_t* pInput,
                               uint32_t numBlocks,
                               const uint8_t* pKey,
                               uint8_t* pOutput)
{
    AES_param_t pAES;

    pAES.CTR_counter = NULL;
    pAES.Key = (uint8_t*)pKey;
    pAES.Len = numBlocks * 16;
    pAES.pCipher = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pOutput;
    pAES.Blocks = numBlocks;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128ECBB_Dec_Id, gAESMGR_ECB_Block_Dec_c );
    AESM_SetParam( AES128ECBB_Dec_Id, pAES, AES_128_ECB_Block_Dec_HW);
    AESM_Start(AES128ECBB_Dec_Id);
#else
    AES_128_ECB_Block_Dec_HW(&pAES);
#endif /* USE_TASK_FOR_HW_AES */
}


/*! *********************************************************************************
* \brief  This function performs AES-128-CTR decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pCounter Pointer to the location of the 128-bit counter.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_CTR_Decrypt(uint8_t* pInput,
                         uint32_t inputLen,
                         uint8_t* pCounter,
                         uint8_t* pKey,
                         uint8_t* pOutput)
{
    AES_param_t pAES;

    pAES.CTR_counter = pCounter;
    pAES.Key = pKey;
    pAES.Len = inputLen;
    pAES.pCipher = pInput;
    pAES.pInitVector = NULL;
    pAES.pPlain = pOutput;
    pAES.Blocks = 0;
#if USE_TASK_FOR_HW_AES
    AESM_InitType( &AES128CTR_Dec_Id, gAESMGR_CTR_Dec_c );
    AESM_SetParam( AES128CTR_Dec_Id, pAES, AES_128_CTR_Dec_HW);
    AESM_Start( AES128CTR_Dec_Id );
#else
    AES_128_CTR_Dec_HW( &pAES );
#endif /* USE_TASK_FOR_HW_AES */
}



static void AES_128_ECB_Enc_HW(AES_param_t* ECB_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t tempBuffOut[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( ECB_p->Len > AES_BLOCK_SIZE )
    {
        AES_128_Encrypt(ECB_p->pPlain, ECB_p->Key, ECB_p->pCipher);
        ECB_p->pPlain += AES_BLOCK_SIZE;
        ECB_p->pCipher += AES_BLOCK_SIZE;
        ECB_p->Len -= AES_BLOCK_SIZE;
    }

    /* If remaining data is smaller then one AES block size */
    FLib_MemCpy(tempBuffIn, ECB_p->pPlain, ECB_p->Len);
    AES_128_Encrypt(tempBuffIn, ECB_p->Key, tempBuffOut);
    FLib_MemCpy(ECB_p->pCipher, tempBuffOut, AES_BLOCK_SIZE);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECB_Enc_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 ECB decryption
*
* \param [in]    ECB_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_ECB_Dec_HW(AES_param_t* ECB_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t tempBuffOut[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( ECB_p->Len > AES_BLOCK_SIZE )
    {
        AES_128_Decrypt(ECB_p->pCipher, ECB_p->Key, ECB_p->pPlain);
        ECB_p->pPlain += AES_BLOCK_SIZE;
        ECB_p->pCipher += AES_BLOCK_SIZE;
        ECB_p->Len -= AES_BLOCK_SIZE;
    }

    /* If remaining data is smaller then one AES block size */
    FLib_MemCpy(tempBuffIn, ECB_p->pCipher, ECB_p->Len);
    AES_128_Decrypt(tempBuffIn, ECB_p->Key, tempBuffOut);
    FLib_MemCpy(ECB_p->pPlain, tempBuffOut, ECB_p->Len);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECB_Dec_Id );
#endif /* USE_TASK_FOR_HW_AES */
}


/*! *********************************************************************************
* \brief  This function performs hardware AES-128 ECB block decryption
*
* \param [in]    ECB_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_ECB_Block_Dec_HW(AES_param_t* ECBB_p)
{
    while( ECBB_p->Blocks )
    {
        AES_128_Decrypt(ECBB_p->pCipher, ECBB_p->Key, ECBB_p->pPlain);
        ECBB_p->Blocks--;
        ECBB_p->pPlain += AES_BLOCK_SIZE;
        ECBB_p->pCipher += AES_BLOCK_SIZE;
    }
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECBB_Dec_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CTR encryption
*
* \param [in]    CTR_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CTR_Enc_HW(AES_param_t* CTR_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t encrCtr[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( CTR_p->Len > AES_BLOCK_SIZE )
    {
        FLib_MemCpy(tempBuffIn, CTR_p->pPlain, AES_BLOCK_SIZE);
        AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
        SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
        FLib_MemCpy(CTR_p->pCipher, tempBuffIn, AES_BLOCK_SIZE);
        CTR_p->pPlain += AES_BLOCK_SIZE;
        CTR_p->pCipher += AES_BLOCK_SIZE;
        CTR_p->Len -= AES_BLOCK_SIZE;
        AES_128_IncrementCounter(CTR_p->CTR_counter);
    }

    /* If remaining data is smaller then one AES block size  */
    FLib_MemCpy(tempBuffIn, CTR_p->pPlain, CTR_p->Len);
    AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
    SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
    FLib_MemCpy(CTR_p->pCipher, tempBuffIn, CTR_p->Len);
    AES_128_IncrementCounter(CTR_p->CTR_counter);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CTR_Enc_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CTR decryption
*
* \param [in]    CTR_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CTR_Dec_HW(AES_param_t* CTR_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t encrCtr[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( CTR_p->Len > AES_BLOCK_SIZE )
    {
        FLib_MemCpy(tempBuffIn, CTR_p->pCipher, AES_BLOCK_SIZE);
        AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
        SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
        FLib_MemCpy(CTR_p->pPlain, tempBuffIn, AES_BLOCK_SIZE);
        CTR_p->pPlain += AES_BLOCK_SIZE;
        CTR_p->pCipher += AES_BLOCK_SIZE;
        CTR_p->Len -= AES_BLOCK_SIZE;
        AES_128_IncrementCounter(CTR_p->CTR_counter);
    }

    /* If remaining data is smaller then one AES block size  */
    FLib_MemCpy(tempBuffIn, CTR_p->pCipher, CTR_p->Len);
    AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
    SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
    FLib_MemCpy(CTR_p->pPlain, tempBuffIn, CTR_p->Len);
    AES_128_IncrementCounter(CTR_p->CTR_counter);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CTR_Dec_Id );
#endif
}
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CMAC encryption
*
* \param [in]    CMAC_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CMAC_HW(AES_param_t* CMAC_p)
{
    uint8_t X[16];
    uint8_t Y[16];
    uint8_t M_last[16] = {0};
    uint8_t padded[16] = {0};

    uint8_t K1[16] = {0};
    uint8_t K2[16] = {0};

    uint8_t n;
    uint32_t i;
    uint8_t flag;

    AES_128_CMAC_Generate_Subkey(CMAC_p->Key, K1, K2);

    n = (uint8_t) ((CMAC_p->Len + 15) / 16); /* n is number of rounds */

    if (n == 0)
    {
        n = 1;
        flag = 0;
    }
    else
    {
        if ((CMAC_p->Len % 16) == 0)
        { /* last block is a complete block */
            flag = 1;
        }
        else
        if(bBlockToReg)
            ((uint32_t*)psReg)[i] = u32Reverse((uint32_t)(puBlock->au32[i]));
        else
        AES_128_Encrypt(ECBB_p->pPlain, ECBB_p->Key, ECBB_p->pCipher);
        ECBB_p->Blocks--;
        ECBB_p->pPlain += AES_BLOCK_SIZE;
        ECBB_p->pCipher += AES_BLOCK_SIZE;
    }
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECBB_Enc_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 ECB block decryption
*
* \param [in]    ECB_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_ECB_Block_Dec_HW(AES_param_t* ECBB_p)
{
    while( ECBB_p->Blocks )
    {
        AES_128_Decrypt(ECBB_p->pCipher, ECBB_p->Key, ECBB_p->pPlain);
        ECBB_p->Blocks--;
        ECBB_p->pPlain += AES_BLOCK_SIZE;
        ECBB_p->pCipher += AES_BLOCK_SIZE;
    }
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128ECBB_Dec_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CTR encryption
*
* \param [in]    CTR_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CTR_Enc_HW(AES_param_t* CTR_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t encrCtr[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( CTR_p->Len > AES_BLOCK_SIZE )
    {
        FLib_MemCpy(tempBuffIn, CTR_p->pPlain, AES_BLOCK_SIZE);
        AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
        SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
        FLib_MemCpy(CTR_p->pCipher, tempBuffIn, AES_BLOCK_SIZE);
        CTR_p->pPlain += AES_BLOCK_SIZE;
        CTR_p->pCipher += AES_BLOCK_SIZE;
        CTR_p->Len -= AES_BLOCK_SIZE;
        AES_128_IncrementCounter(CTR_p->CTR_counter);
    }

    /* If remaining data is smaller then one AES block size  */
    FLib_MemCpy(tempBuffIn, CTR_p->pPlain, CTR_p->Len);
    AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
    SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
    FLib_MemCpy(CTR_p->pCipher, tempBuffIn, CTR_p->Len);
    AES_128_IncrementCounter(CTR_p->CTR_counter);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CTR_Enc_Id );
#endif
}

/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CTR decryption
*
* \param [in]    CTR_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CTR_Dec_HW(AES_param_t* CTR_p)
{
    uint8_t tempBuffIn[AES_BLOCK_SIZE] = {0};
    uint8_t encrCtr[AES_BLOCK_SIZE] = {0};

    /* If remaining data bigger than one AES block size */
    while( CTR_p->Len > AES_BLOCK_SIZE )
    {
        FLib_MemCpy(tempBuffIn, CTR_p->pCipher, AES_BLOCK_SIZE);
        AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
        SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
        FLib_MemCpy(CTR_p->pPlain, tempBuffIn, AES_BLOCK_SIZE);
        CTR_p->pPlain += AES_BLOCK_SIZE;
        CTR_p->pCipher += AES_BLOCK_SIZE;
        CTR_p->Len -= AES_BLOCK_SIZE;
        AES_128_IncrementCounter(CTR_p->CTR_counter);
    }

    /* If remaining data is smaller then one AES block size  */
    FLib_MemCpy(tempBuffIn, CTR_p->pCipher, CTR_p->Len);
    AES_128_Encrypt(CTR_p->CTR_counter, CTR_p->Key, encrCtr);
    SecLib_XorN(tempBuffIn, encrCtr, AES_BLOCK_SIZE);
    FLib_MemCpy(CTR_p->pPlain, tempBuffIn, CTR_p->Len);
    AES_128_IncrementCounter(CTR_p->CTR_counter);
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CTR_Dec_Id );
#endif
}


/*! *********************************************************************************
* \brief  This function performs hardware AES-128 CMAC encryption
*
* \param [in]    CMAC_p      Pointer to AES parameter structure
*
********************************************************************************** */
static void AES_128_CMAC_HW(AES_param_t* CMAC_p)
{
    uint8_t X[16];
    uint8_t Y[16];
    uint8_t M_last[16] = {0};
    uint8_t padded[16] = {0};

    uint8_t K1[16] = {0};
    uint8_t K2[16] = {0};

    uint8_t n;
    uint32_t i;
    uint8_t flag;

    AES_128_CMAC_Generate_Subkey(CMAC_p->Key, K1, K2);

    n = (uint8_t) ((CMAC_p->Len + 15) / 16); /* n is number of rounds */

    if (n == 0)
    {
        n = 1;
        flag = 0;
    }
    else
    {
        if ((CMAC_p->Len % 16) == 0)
        { /* last block is a complete block */
            flag = 1;
        }
        else
        { /* last block is not complete block */
            flag = 0;
        }
    }

    /* Process the last block  - the last part the MSB first input data */
    if (flag)
    { /* last block is complete block */
        SecLib_Xor128(&CMAC_p->pPlain[16 * (n - 1)], K1, M_last);
            puBlock->au32[i]  = u32Reverse(((uint32_t*)psReg)[i]);
        { /* last block is not complete block */
            flag = 0;
        }
    }

    /* Process the last block  - the last part the MSB first input data */
    if (flag)
    { /* last block is complete block */
        SecLib_Xor128(&CMAC_p->pPlain[16 * (n - 1)], K1, M_last);
    }
    else
    {
        SecLib_Padding(&CMAC_p->pPlain[16 * (n - 1)], padded, CMAC_p->Len % 16);
        SecLib_Xor128(padded, K2, M_last);
    }

    for (i = 0; i < 16; i++)
    {
        X[i] = 0;
    }

    for (i = 0; i < n - 1; i++)
    {
        SecLib_Xor128(X, &CMAC_p->pPlain[16 * i], Y); /* Y := Mi (+) X  */
        AES_128_Encrypt(Y, CMAC_p->Key, X); /* X := AES-128(KEY, Y) */
    }

    SecLib_Xor128(X, M_last, Y);
    AES_128_Encrypt(Y, CMAC_p->Key, X);

    for (i = 0; i < 16; i++)
    {
        CMAC_p->pCipher[i] = X[i];
    }
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CMAC_Id );
#endif
    {
        SecLib_Padding(&CMAC_p->pPlain[16 * (n - 1)], padded, CMAC_p->Len % 16);
        SecLib_Xor128(padded, K2, M_last);
    }

    for (i = 0; i < 16; i++)
    {
        X[i] = 0;
    }

    for (i = 0; i < n - 1; i++)
    {
        SecLib_Xor128(X, &CMAC_p->pPlain[16 * i], Y); /* Y := Mi (+) X  */
        AES_128_Encrypt(Y, CMAC_p->Key, X); /* X := AES-128(KEY, Y) */
    }

    SecLib_Xor128(X, M_last, Y);
    AES_128_Encrypt(Y, CMAC_p->Key, X);

    for (i = 0; i < 16; i++)
    {
        CMAC_p->pCipher[i] = X[i];
    }
#if USE_TASK_FOR_HW_AES
    AESM_Complete( AES128CMAC_Id );
#endif
}
#endif





