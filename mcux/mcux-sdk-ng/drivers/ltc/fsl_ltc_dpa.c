/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017, 2020 NXP
 * All rights reserved.
 *
 * Freescale Confidential and Proprietary - use of this software is
 * governed by the LA_OPT_FSL_OPEN_3RD_PARTY_IP License distributed
 * with this Material.
 */
#include "confidential/fsl_ltc_dpa_confidential.h"

#if defined __CC_ARM
#elif defined __GNUC__
#elif defined __ICCARM__
#else
#error Unknown compiler
#endif
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* this allows COUNTERMEASURE_B to compile in. reqHandle->Pc becomes effective. */
#define FSL_LTC_DPA_HAVE_COUNTERMEASURE_B 0

/* this allows to compile in random LTC clock gate during AES/DES inner rounds.
 * slower version of ltc_symmetric_process() becomes effective.
 */
#define FSL_LTC_DPA_HAVE_GATE_OFF 1

/* this enables the prng ring buffer.
 * to disable, it is enough to set FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER to zero at compile time.
 */
#define FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER 1

/* when FSL_LTC_DPA_RELEASE is set to 1, the FSL_LTC_DPA_ACT_ND_AES and FSL_LTC_DPA_ACT_ND_DES become effective. */
#define FSL_LTC_DPA_RELEASE    0
#define FSL_LTC_DPA_ACT_ND_AES 23u
/* #define FSL_LTC_DPA_ACT_ND_AES 200u */
/* #define FSL_LTC_DPA_ACT_ND_AES 529u */
#define FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT 16u
#define FSL_LTC_DPA_ACT_ND_DES              95u

#define LTC_DPA_FIFO_SIZE            (0xff0u)
#define BUILD_ASSERT(condition, msg) extern int msg[1 - 2 * (!(condition))] __attribute__((unused))

#ifndef FSL_LTC_DPA_HAVE_COUNTERMEASURE_B
#define FSL_LTC_DPA_HAVE_COUNTERMEASURE_B 1
#endif

/*!* @brief Maximum number of dummies. */
#ifndef FSL_LTC_DPA_MAX_ND
#define FSL_LTC_DPA_MAX_ND 65535u
#endif

/* define FSL_LTC_DPA_TAKE_TIMESTAMPS */

typedef struct _ltc_dpa_req_handle ltc_dpa_req_handle_t;
typedef struct _ltc_dpa_operation_data ltc_dpa_operation_data_t;

/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
#pragma push
#pragma anon_unions
#elif defined(__CWCC__)
#pragma push
#pragma cpp_extensions on
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma language = extended
#else
#error Not supported compiler type
#endif

#define OPERATION_DATA_SIZE 64
/* #define OPERATION_DATA_SIZE 16 */

/*! @brief Actual operation with LTC AES. */
typedef enum _ltc_aes_encryption_decryption_mode
{
    kAES_ModeEncrypt = 0U, /*!< Encryption */
    kAES_ModeDecrypt = 1U, /*!< Decryption */
} ltc_aes_encryption_decryption_mode_t;

struct _ltc_dpa_xcm_request
{
    ltc_aes_encryption_decryption_mode_t encryptMode;
    const uint8_t *aad;
    size_t aadSize;
    const uint8_t *iv;
    size_t ivSize;
    size_t inputSize;
};

struct _ltc_dpa_key_pool
{
    uint32_t *realKey;
    uint32_t *dummyKey;
    uint32_t keyWord[16];
};

struct _ltc_dpa_operation_data
{
    uint32_t *operationOutData; /* where to store OFIFO data or NULL for CMAC */
    struct _ltc_dpa_key_pool *keyPool;
    uint32_t *hwKey;
    uint32_t *dummyKey;

    /* context related functions and data */
    status_t (*ltc_save_context)(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op);
    status_t (*ltc_load_context)(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op);
    uint32_t initCTX[16]; /* LTC Context register */
    uint32_t CTX[16];     /* LTC Context register */

    /* pointers to store derived key. real operation will store to real key in both key pools.
     * dummy operations will store to dummy key in both key pools.
     */
    uint32_t *hwDecryptKey0;
    uint32_t *hwDecryptKey1;

#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
    /* Countermeasure B specific data */
    uint32_t *cmbWriteCount;
    uint32_t *cmbReadCount;
#endif /* FSL_LTC_DPA_HAVE_COUNTERMEASURE_B */

#if defined(FSL_LTC_DPA_TAKE_TIMESTAMPS)
    bool bReal;
#endif
};

struct _ltc_dpa_req_handle
{
    uint32_t Nd; /*!< Nd parameter. */
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
#else
    uint32_t Pc; /*!< Pc parameter. */
#endif
    union
    {
        uint8_t key[32]; /*!< Storage for AES or DES key */
        uint32_t keyWord[8];
    };
    uint32_t blksz;               /*!< CMAC number of consumed bytes. */
    uint32_t state;               /*!< CMAC state. Also used by all others to distinguish Init versus Running state. */
    ltc_dpa_hash_algo_t hashAlgo; /*!< CMAC algorithm */
    uint32_t rngContext[4];       /*!< Internal Golden ration PRNG state. Use for permutations and dummy keys. */
    bool prngHasSeed;             /*!< Flag to check that PRNG has been seeded. */

    size_t keySize;   /*!< AES or DES size of key in bytes */
    uint32_t modeReg; /*!< Value used to configure LTC MD Register. */
    uint32_t dataSize;
    uint32_t realInData[OPERATION_DATA_SIZE / sizeof(uint32_t)];
    uint32_t realOutData[OPERATION_DATA_SIZE / sizeof(uint32_t)];
    uint32_t dummyOutData[OPERATION_DATA_SIZE / sizeof(uint32_t)];
    struct _ltc_dpa_key_pool keyPoolRealKeyEven;
    struct _ltc_dpa_key_pool keyPoolRealKeyOdd;
    ltc_dpa_operation_data_t rOp; /*!< All RO use this data. */
    ltc_dpa_operation_data_t
        dOp; /*!< All DOs use this data. So it is global for DOs and so each DO can update e.g.CTX[] while running. */

    struct _ltc_dpa_xcm_request xcm; /*!< Information for CCM and GCM processing. */
#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
    uint32_t cmbCntZero;
    uint32_t cmbCnt;
#endif

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    uint32_t gateOffRepeat;
    uint32_t gateOffRandom;
    uint32_t gateOffRepeatMax;
    uint32_t gateOffCycles;
    uint32_t gateOffCyclesMax;
    uint32_t oneBlockWords;
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

#if defined(FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER) && (FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER > 0)
    struct
    {
        uint32_t *currPrngSrc;
        size_t currPrngArraySize;
        uint32_t *nextPrngSrc;
        size_t nextPrngArraySize;
        uint32_t *prngBuffer;
        size_t prngBufferHalfArraySize;
        uint32_t rngContext[4]; /*!< Internal Golden ration PRNG state. Use for permutations and dummy keys. */
    } prngRingBuffer;
#endif /* FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER */
};

/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
#pragma pop
#elif defined(__CWCC__)
#pragma pop
#elif defined(__GNUC__)
/* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
#pragma language = default
#else
#error Not supported compiler type
#endif

/*! Internal states of the CMAC creation process. Now used for all others as well. */
enum _ltc_dpa_algo_state
{
    kLTC_CmacInitDPA   = 1u, /*!< Init state. */
    kLTC_CmacUpdateDPA = 2u, /*!< Update state. */
};

typedef enum _ltc_aes_configuration
{
    kLTC_CfgAesCmac = 0x00100601U, /*!< AES CMAC ENC. ENC bit is don't care as prepare_do() sets DO to ECB Encrypt */
    kLTC_CfgAesXcbcMac =
        0x00100701U,              /*!< AES XCBC-MAC ENC. ENC bit is don't care as prepare_do() sets DO to ECB Encrypt */
    kLTC_CfgAesGcm = 0x00100900U, /*!< AES GCM. ENC bit clear. Add ENC bit for GCM Encrypt. */
    kLTC_CfgAesCcm = 0x00100800U, /*!< AES CCM. ENC bit clear. Add ENC bit for CCM Encrypt. */
} ltc_aes_configuration_t;

typedef enum _ltc_md_as
{
    kLTC_CfgAsUpdate             = 0x0U,
    kLTC_CfgAsInitialize         = 0x1U,
    kLTC_CfgAsFinalize           = 0x2U,
    kLTC_CfgAsInitializeFinalize = 0x3U,
} ltc_md_as_t;

enum _ltc_context_index
{
    kLTC_ContextIndexCcmTag = 8u, /*! For CCM encryption, the encrypted final MAC is written to the context word 8-11 */
    kLTC_ContextIndexGcmTag = 0u, /*! For GCM encryption, the encrypted final MAC is written to the context word 8-11 */
};

/*! @brief Type used in GCM and CCM modes.

    Content of a block is established via individual bytes and moved to LTC
   IFIFO by moving 32-bit words.
*/
typedef union _ltc_xcm_block_t
{
    uint32_t w[4]; /*!< LTC context register is 16 bytes written as four 32-bit words */
    uint8_t b[16]; /*!< 16 octets block for CCM B0 and CTR0 and for GCM */
} ltc_xcm_block_t;

enum _ltc_probability
{
    kLTC_Probability100 = 100u,
    kLTC_Probability99  = 99u,
    kLTC_Probability0   = 0u,
};

enum _ltc_stop_before_completion_bits
{
    kLTC_StopBeforeCompletionBits = 5u,
};

/*! @brief LTC status return codes. */
enum _ltc_status
{
    kStatus_LTC_GcmGHASH           = MAKE_STATUS(kStatusGroup_LTC, 0), /*!< GCM has only public data. */
    kStatus_LTC_CcmNoMDATA         = MAKE_STATUS(kStatusGroup_LTC, 1), /*!< CCM has no MDATA. */
    kStatus_LTC_PrngRingBufferFull = MAKE_STATUS(kStatusGroup_LTC, 2), /*!< Ring Buffer PRNG is full. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
extern void ltc_gate_off(volatile uint32_t *scgc2,
                         uint32_t gateOffRandom,
                         uint32_t gateOffRepeat,
                         uint32_t gateOffCycles);
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

static void ltc_generate_dummy_key(ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *actOp);

static status_t ltc_aes_gcm_do_aad(LTC_Type *base,
                                   ltc_dpa_req_handle_t *reqHandle,
                                   ltc_aes_encryption_decryption_mode_t encryptMode,
                                   const uint8_t *aad,
                                   size_t aadSize,
                                   bool aadOnly);
static status_t ltc_aes_gcm_do_iv(LTC_Type *base,
                                  ltc_dpa_req_handle_t *reqHandle,
                                  ltc_aes_encryption_decryption_mode_t encryptMode,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  bool ivOnly);

extern void ltc_decrementer(uint32_t count);
extern uint32_t getRandomWord(void *aRngContext);
extern void secureCopy(void *dstPtr, const void *srcPtr, int nBytes, uint32_t random32bits);
extern uint32_t getRandomIndex(uint32_t n, uint32_t random32bits);
extern void *securePointerSelect(
    uint32_t index, uint32_t referenceIndex, void *ptrEqual, void *ptrDifferent, uint32_t random32bits);
extern void secureCopy_wordsInterleaved(void *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits);
extern void secureCopy_wordsCombine(volatile uint32_t *dstPtr, void *srcPtr, int nBytes, uint32_t random32bits);

/*******************************************************************************
 * Code
 ******************************************************************************/
#if defined(FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER) && (FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER > 0)

static uint32_t ltc_dpa_prng_get_random_word(ltc_dpa_req_handle_t *reqHandle)
{
    uint32_t r32;
    size_t head;

    /* consuming backwards, from (HalfArraySize-1) to 0 */
    head = reqHandle->prngRingBuffer.currPrngArraySize;
    if (head)
    {
        head--;
        r32                                         = reqHandle->prngRingBuffer.currPrngSrc[head];
        reqHandle->prngRingBuffer.currPrngArraySize = head;
    }
    else
    {
        /* no pre-generated random words available, fall back to on-the-fly PRNG. */
        r32 = getRandomWord(reqHandle->rngContext);
    }

    return r32;
}

/*!
 * brief Runs PRNG algorithm and puts the 32-bit random word to associated memory buffer.
 *
 * This function is intended and designed to be used during system idle time
 * to generate random numbers, to be consumed by LTC_DPA encrypt/decrypt APIs.
 *
 * Example usage FreeRTOS Idle Time Hook:
 * code
 * static uint32_t s_prngBuffer[2048];
 * LTC_IdleTimePrngBufferEnableDPA(g_ltcDpaHandle, s_prngBuffer, 2048);
 * ...
 * void vApplicationIdleHook(void)
 * {
 *     if (kStatus_Success != LTC_IdleTimePrngBufferPutNextDPA(g_ltcDpaHandle)
 *     {
 *         __WFI();
 *     }
 * }
 * endcode
 *
 * Example usage in Super Loop (bare metal):
 * code
 * static uint32_t s_prngBuffer[2048];
 * LTC_IdleTimePrngBufferEnableDPA(g_ltcDpaHandle, s_prngBuffer, 2048);
 * ...
 * while (1)
 * {
 *     ...
 *     ...
 *     ...
 *     if (kStatus_Success != LTC_IdleTimePrngBufferPutNextDPA(g_ltcDpaHandle)
 *     {
 *         __WFI();
 *     }
 * }
 * endcode
 *
 * param[in,out] handle    Pointer to ltc_dpa_handle_t structure
 * return kStatus_Success Sucesfully generated next random number. prngBuffer[] is not full yet.
 * return kStatus_LTC_PrngRingBufferFull prngBuffer[] is full.
 * return kStatus_InvalidArgument prngBuffer[] is not configured. Use LTC_IdleTimePrngBufferEnableDPA().
 */
status_t LTC_IdleTimePrngBufferPutNextDPA(ltc_dpa_handle_t *handle)
{
    status_t status;

    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    if (NULL == reqHandle->prngRingBuffer.prngBuffer)
    {
        return kStatus_InvalidArgument;
    }

    status = kStatus_Success;

    /* generate the Next half from 0 to (HalfArraySize-1). */
    if ((reqHandle->prngRingBuffer.prngBufferHalfArraySize) == reqHandle->prngRingBuffer.nextPrngArraySize)
    {
        /* non-zero currPrngArraySize means that LTC_DPA APIs consume the Current half */
        if (reqHandle->prngRingBuffer.currPrngArraySize)
        {
            status = kStatus_LTC_PrngRingBufferFull;
        }
        else
        {
            /* switch: Next if full, so move it to become Current (to be consumed by LTC_DPA APIs).
             * Current is empty (currPngArraySize is zero), so it means it has been all consumed by LTC_DPA APIs.
             * Thus, move Current to become Next and the idle time function can generate random words into Next.
             */
            uint32_t *current                           = reqHandle->prngRingBuffer.currPrngSrc;
            reqHandle->prngRingBuffer.currPrngSrc       = reqHandle->prngRingBuffer.nextPrngSrc;
            reqHandle->prngRingBuffer.nextPrngSrc       = current;
            reqHandle->prngRingBuffer.nextPrngArraySize = 0;
            reqHandle->prngRingBuffer.currPrngArraySize = reqHandle->prngRingBuffer.prngBufferHalfArraySize;
        }
    }
    else
    {
        reqHandle->prngRingBuffer.nextPrngSrc[reqHandle->prngRingBuffer.nextPrngArraySize] =
            getRandomWord(reqHandle->prngRingBuffer.rngContext);

        reqHandle->prngRingBuffer.nextPrngArraySize++;
    }

    return status;
}

/*!
 * brief Enables the Idle time PRNG buffer.
 * This feature is intended to enable pseudo-random numbers generation
 * during system idle time. These idle time pre-generated numbers are simply consumed
 * by LTC_DPA encrypt/decrypt functions.
 *
 * param[in,out] handle    Pointer to ltc_dpa_handle_t structure
 * param prngBuffer        Memory buffer to be used as storage for random 32-bit words.
 * param prngBufferArraySize  Number of items (array size) in the prngBuffer[] array.
 */
status_t LTC_IdleTimePrngBufferEnableDPA(ltc_dpa_handle_t *handle, uint32_t *prngBuffer, size_t prngBufferArraySize)
{
    status_t status;

    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (prngBuffer && prngBufferArraySize)
    {
        status                                            = kStatus_Success;
        reqHandle->prngRingBuffer.prngBuffer              = prngBuffer;
        reqHandle->prngRingBuffer.prngBufferHalfArraySize = prngBufferArraySize / 2;
        reqHandle->prngRingBuffer.currPrngSrc             = &prngBuffer[0];
        reqHandle->prngRingBuffer.nextPrngSrc       = &prngBuffer[reqHandle->prngRingBuffer.prngBufferHalfArraySize];
        reqHandle->prngRingBuffer.currPrngArraySize = 0;
        reqHandle->prngRingBuffer.nextPrngArraySize = 0;
    }
    else
    {
        status = kStatus_InvalidArgument;
    }

    return status;
}

#else  /* FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER */
__STATIC_INLINE uint32_t ltc_dpa_prng_get_random_word(ltc_dpa_req_handle_t *reqHandle)
{
    return getRandomWord(reqHandle->rngContext);
}
#endif /* FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER */

__STATIC_INLINE uint32_t ltc_prng_get_random_key32(ltc_dpa_req_handle_t *reqHandle)
{
    uint32_t retVal;
    retVal = ltc_dpa_prng_get_random_word(reqHandle);
    return retVal;
}

static void ltc_memcpy(void *dst, const void *src, size_t size)
{
    register uint8_t *to         = (uint8_t *)(uintptr_t)dst;
    register const uint8_t *from = (const uint8_t *)(uintptr_t)src;

    /* if it is possible to move data with 32-bit aligned access, do it so */
    if ((size >= sizeof(uint32_t)) && (0u == ((uintptr_t)dst & 0x3u)) && (0u == ((uintptr_t)src & 0x3u)))
    {
        register uint32_t *to32         = (uint32_t *)(uintptr_t)dst;
        register const uint32_t *from32 = (const uint32_t *)(uintptr_t)src;
        while (size >= sizeof(uint32_t))
        {
            *to32 = *from32;
            size -= sizeof(uint32_t);
            to32++;
            from32++;
        }

        to   = (uint8_t *)(uintptr_t)to32;
        from = (const uint8_t *)(uintptr_t)from32;
    }

    while (size)
    {
        *to = *from;
        size--;
        to++;
        from++;
    }
}

/* secure memcpy. size not power of two. */
static void ltc_secure_memcpy(ltc_dpa_req_handle_t *reqHandle, uint8_t *dst, const uint8_t *src, size_t size)
{
    uint32_t r32;

    /* 1. find n such that 2^n <= size && 2^(n+1) > size */
    uint32_t n;
    uint32_t res0;
    uint32_t res1;

    do
    {
        n = 0;
        do
        {
            res0 = 1u << n;
            n++;
            res1 = 1u << n;
        } while (res1 <= size);

        if (res0 > 4u)
        {
            /* 2.  */
            r32 = ltc_dpa_prng_get_random_word(reqHandle);
            secureCopy(dst, src, res0, r32);
            size -= res0;
            src += res0;
            dst += res0;
        }
    } while (res0 > 4u);

    if (size)
    {
        ltc_memcpy(dst, src, size);
    }
}

/*! @brief LTC driver wait mechanism. */
static status_t ltc_wait(LTC_Type *base)
{
    status_t status;

    bool error = false;
    bool done  = false;

    /* Wait for 'done' or 'error' flag. */
    while ((!error) && (!done))
    {
        uint32_t temp32 = base->STA;
        error           = temp32 & LTC_STA_EI_MASK;
        done            = temp32 & LTC_STA_DI_MASK;
    }

    if (error)
    {
        base->COM = LTC_COM_ALL_MASK; /* Reset all engine to clear the error flag */
        while (base->COM)
        {
        }
        base->CTL = LTC_CTL_COS_MASK | LTC_CTL_CIS_MASK | LTC_CTL_KOS_MASK | LTC_CTL_KIS_MASK | LTC_CTL_OFS_MASK |
                    LTC_CTL_IFS_MASK;
        status = kStatus_Fail;
    }
    else /* 'done' */
    {
        status = kStatus_Success;

        base->CW = LTC_CW_CDS_MASK;
        /* Clear 'done' interrupt status.  This also clears the mode register. */
        base->STA = LTC_STA_DI_MASK;
    }

    return status;
}

/*! @brief LTC driver wait mechanism. */
static status_t ltc_wait_or_reset(LTC_Type *base, uint32_t count)
{
    status_t status;

    if (count)
    {
        ltc_decrementer(count);
#if defined(FSL_FEATURE_LTC_HAS_DES) && (FSL_FEATURE_LTC_HAS_DES > 0)
        base->COM = 0x00000006u; /* Reset AES and DES */
#else
        base->COM = 0x00000002u; /* Reset AES */
#endif
        status = kStatus_Fail; /* return we have failed, which is intended. */

        base->CW  = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CKR_MASK | LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
        base->STA = LTC_STA_DI_MASK;
    }
    else
    {
        status = ltc_wait(base);
    }

    return status;
}

/*!
 * @brief Swap bytes withing 32-bit word.
 *
 * This function changes endianess of a 32-bit word.
 *
 * @param in 32-bit unsigned integer
 * @return 32-bit unsigned integer with different endianess (big endian to little endian and vice versa).
 */
static uint32_t swap_bytes(uint32_t in)
{
    return (((in & 0x000000ffu) << 24) | ((in & 0x0000ff00u) << 8) | ((in & 0x00ff0000u) >> 8) |
            ((in & 0xff000000u) >> 24));
}

static status_t ltc_dpa_check_handle(ltc_dpa_req_handle_t *reqHandle)
{
    if (
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
#else
        (reqHandle->Nd > FSL_LTC_DPA_MAX_ND) || (reqHandle->Pc > 100u) ||
#endif
        (!reqHandle->prngHasSeed))
    {
        return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
static void ltc_prepare_gate_off(ltc_dpa_req_handle_t *reqHandle)
{
    uint32_t r32             = ltc_dpa_prng_get_random_word(reqHandle);
    reqHandle->gateOffRandom = r32;
    reqHandle->gateOffRepeat = ((r32 & 0xC0000000u) >> 30); /* = 0 to 3 */
    reqHandle->gateOffCycles = ((r32 & 0x00000030u) >> 4);  /* = 0 to 3 */

    if (reqHandle->gateOffRepeat > reqHandle->gateOffRepeatMax)
    {
        reqHandle->gateOffRepeat = reqHandle->gateOffRepeatMax;
    }

    /* prevent divide by zero in ltc_gate_off() */
    if (0 == reqHandle->gateOffRandom)
    {
        reqHandle->gateOffRandom = 0xbaba5a12U;
    }
}

static void ltc_symmetric_process(
    LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, uint32_t inSize, const uint32_t *in, uint32_t *out)
{
    uint32_t outSize;
    uint32_t fifoData;
    uint32_t fifoStatus;

    if (out)
    {
        outSize = inSize;
    }
    else
    {
        outSize = 0; /* for CMAC */
    }

    while ((inSize) || (outSize))
    {
        uint32_t inSizeWords  = (inSize + 3) >> 2;
        uint32_t outSizeWords = 0;
        if (inSizeWords > reqHandle->oneBlockWords)
        {
            inSizeWords = reqHandle->oneBlockWords;
        }

        if (inSizeWords && outSize)
        {
            outSizeWords = inSizeWords;
        }

        while (inSizeWords)
        {
            fifoStatus = base->FIFOSTA;
            if (!(fifoStatus & LTC_FIFOSTA_IFF_MASK))
            {
                /* Copy data to the input FIFO.
                 * Data can only be copied one word at a time, so pad the data
                 * appropriately if it is less than this size. */
                if (inSize > 0)
                {
                    if (inSize >= sizeof(uint32_t))
                    {
                        base->IFIFO = in[0];
                        inSize -= sizeof(uint32_t);
                        in++;
                        inSizeWords--;
                    }
                    else /* (inSize > 0) && (inSize < 4) */
                    {
                        fifoData = 0;
                        ltc_memcpy(&fifoData, in, inSize);
                        base->IFIFO = fifoData;
                        inSize      = 0;
                        inSizeWords = 0;
                    }
                }
            }
        }

        ltc_gate_off(&SIM->SCGC2, reqHandle->gateOffRandom, reqHandle->gateOffRepeat, reqHandle->gateOffCycles);
        ltc_prepare_gate_off(reqHandle);

        while (outSizeWords)
        {
            fifoStatus = base->FIFOSTA;

            if (fifoStatus & LTC_FIFOSTA_OFL_MASK)
            {
                fifoStatus = base->FIFOSTA;

                /* Read data from the output FIFO. */
                if (outSize > 0)
                {
                    if (outSize >= sizeof(uint32_t))
                    {
                        out[0] = base->OFIFO;
                        out++;
                        outSize -= sizeof(uint32_t);
                        outSizeWords--;
                    }
                    else /* (outSize > 0) && (outSize < 4) */
                    {
                        fifoData = base->OFIFO;
                        ltc_memcpy(out, &fifoData, outSize);
                        outSize      = 0;
                        outSizeWords = 0;
                    }
                }
            }
        }
    }
}
#else  /* FSL_LTC_DPA_HAVE_GATE_OFF */
static void ltc_symmetric_process(
    LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, uint32_t inSize, const uint32_t *in, uint32_t *out)
{
    uint32_t outSize;
    uint32_t fifoData;
    uint32_t fifoStatus;

    if (out)
    {
        outSize = inSize;
    }
    else
    {
        outSize = 0; /* for CMAC */
    }
    while ((outSize > 0) || (inSize > 0))
    {
        fifoStatus = base->FIFOSTA;

        /* Check output FIFO level to make sure there is at least an entry
         * ready to be read. */
        if (fifoStatus & LTC_FIFOSTA_OFL_MASK)
        {
            /* Read data from the output FIFO. */
            if (outSize > 0)
            {
                if (outSize >= sizeof(uint32_t))
                {
                    out[0] = base->OFIFO;
                    out++;
                    outSize -= sizeof(uint32_t);
                }
                else /* (outSize > 0) && (outSize < 4) */
                {
                    fifoData = base->OFIFO;
                    ltc_memcpy(out, &fifoData, outSize);
                    outSize = 0;
                }
            }
        }

        if (!(fifoStatus & LTC_FIFOSTA_IFF_MASK))
        {
            /* Copy data to the input FIFO.
             * Data can only be copied one word at a time, so pad the data
             * appropriately if it is less than this size. */
            if (inSize > 0)
            {
                if (inSize >= sizeof(uint32_t))
                {
                    base->IFIFO = in[0];
                    inSize -= sizeof(uint32_t);
                    in++;
                }
                else /* (inSize > 0) && (inSize < 4) */
                {
                    fifoData = 0;
                    ltc_memcpy(&fifoData, in, inSize);
                    base->IFIFO = fifoData;
                    inSize = 0;
                }
            }
        }
    }
}
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

#if defined(FSL_LTC_DPA_TAKE_TIMESTAMPS)
static volatile uint16_t s_log[10000];
static uint32_t s_logCnt = 0;
#endif

/*!
 * @brief Operation flow.
 *
 * @param base LTC peripheral base address
 * @param reqHandle
 * @param op Operation data.
 */
static status_t ltc_run_one_op(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    status_t status;
    uint32_t dataSize;
    uint32_t r32;

    dataSize = reqHandle->dataSize;

    ltc_generate_dummy_key(reqHandle, op);

    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy_wordsCombine(base->KEY, op->hwKey, 32, r32);
    base->KS = reqHandle->keySize;
    base->CW = LTC_CW_CIF_MASK | LTC_CW_COF_MASK;

    status = kStatus_Success;
    if (op->ltc_load_context)
    {
        /* GCM can report GHASH only so in that case I skip data but save context to read out the MAC */
        status = op->ltc_load_context(base, reqHandle, op);
    }

    if (status == kStatus_Success)
    {
        base->MD = reqHandle->modeReg;

        /* for last un-complete block, this is real byte size in the last block.
         */
        base->DS = dataSize;
#if defined(FSL_LTC_DPA_TAKE_TIMESTAMPS)
        if (op->bReal)
        {
            if (s_log[s_logCnt] < 10000)
            {
                s_log[s_logCnt++] = SysTick->VAL;
            }
            else
            {
                __BKPT(0);
            }
        }
#endif

#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
        /* Pc parameter is global for all operations, so when Countermeasure B is active,
         * the if is always taken - common execution path
         */
        if (0 == *(op->cmbReadCount))
        {
            /* run to completion. same code as in Countermeasure A only case. */
            /* *cmbReadCount must be zero for RO and all DOs that run to completion. */
            ltc_symmetric_process(base, reqHandle, dataSize, reqHandle->realInData, op->operationOutData);
            status = ltc_wait(base);
        }
        else
        {
            /* this branch is taken only for Countermeasure B DO that runs to completion.
             * The algorithm is anyway different from RO (operation is reset within *cmbReadCount cycles)
             * by definition, so no effort is taken here to equalize RO with DOs.
             */
            base->IFIFO = reqHandle->realInData[0];
            base->IFIFO = reqHandle->realInData[1];
            base->IFIFO = reqHandle->realInData[2];
            base->IFIFO = reqHandle->realInData[3];
            status      = ltc_wait_or_reset(base, *(op->cmbReadCount));
        }
#else
        ltc_symmetric_process(base, reqHandle, dataSize, reqHandle->realInData, op->operationOutData);
        status = ltc_wait(base);
#endif
    }

    if (op->ltc_save_context)
    {
        op->ltc_save_context(base, reqHandle, op);
    }

    base->CW  = /* LTC_CW_COF_MASK | */ LTC_CW_CKR_MASK | LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
    base->STA = LTC_STA_DI_MASK;

    return status;
}

static void ltc_generate_dummy_key(ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *actOp)
{
    uint32_t dummyKey[8];

    for (int i = 0; i < 8; i++)
    {
        dummyKey[i] = ltc_prng_get_random_key32(reqHandle);
    }

    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy_wordsInterleaved(actOp->dummyKey, dummyKey, 32, r32);
}

#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
static void ltc_set_cmb_count(ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *actOp)
{
    uint32_t r32;
    r32                     = ltc_dpa_prng_get_random_word(reqHandle);
    uint32_t r22            = r32 & 0x003FFFFFu;
    *(actOp->cmbWriteCount) = (r22 * 100u) >> 22;                            /* generate random number 0-99 */
    *(actOp->cmbWriteCount) = ((*(actOp->cmbWriteCount)) > (reqHandle->Pc)); /* compare to Pc */
    /* MUL by zero (run to completion) or by <1;31> */
    *(actOp->cmbWriteCount) = ((*(actOp->cmbWriteCount)) * (1u + (r32 & 0x0000001Fu)));
}
#endif

static status_t ltc_one_block(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, uint8_t *output, const uint8_t *input)
{
    uint32_t r32;
    uint32_t poolIndexReal;
    uint32_t poolIndexDummy;
    uint32_t opTypeIndex;
    uint32_t opIndex;

    ltc_dpa_operation_data_t *actOp;
    struct _ltc_dpa_key_pool *keyPoolReal;
    struct _ltc_dpa_key_pool *keyPoolDummy;

    if (input)
    {
        ltc_secure_memcpy(reqHandle, (uint8_t *)(uintptr_t)reqHandle->realInData, input, reqHandle->dataSize);
    }

    /* configure rOp vs dOp */
    r32            = ltc_dpa_prng_get_random_word(reqHandle);
    poolIndexReal  = getRandomIndex(2, r32);
    r32            = ltc_dpa_prng_get_random_word(reqHandle);
    poolIndexDummy = getRandomIndex(2, r32);
    r32            = ltc_dpa_prng_get_random_word(reqHandle);
    opTypeIndex    = getRandomIndex(2, r32);

    for (int i = 0; i < 2; i++)
    {
        /* get random pool */
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        keyPoolReal =
            securePointerSelect(i, poolIndexReal, &reqHandle->keyPoolRealKeyEven, &reqHandle->keyPoolRealKeyOdd, r32);
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        keyPoolDummy =
            securePointerSelect(i, poolIndexDummy, &reqHandle->keyPoolRealKeyEven, &reqHandle->keyPoolRealKeyOdd, r32);

        /* get random operation */
        r32             = ltc_dpa_prng_get_random_word(reqHandle);
        actOp           = securePointerSelect(i, opTypeIndex, &reqHandle->rOp, &reqHandle->dOp, r32);
        actOp->dummyKey = keyPoolDummy->dummyKey;
        actOp->hwKey    = securePointerSelect(i, opTypeIndex, keyPoolReal->realKey, keyPoolDummy->dummyKey, r32);
    }

    /* basic LTC configuration */
    /* base->COM = LTC_COM_ALL_MASK; */
    base->CW  = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CKR_MASK | LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
    base->STA = LTC_STA_DI_MASK;
    base->CTL =
        LTC_CTL_COS_MASK | LTC_CTL_CIS_MASK | LTC_CTL_KOS_MASK | LTC_CTL_KIS_MASK | LTC_CTL_OFS_MASK | LTC_CTL_IFS_MASK;

    uint32_t noOp;
#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
    if (reqHandle->Pc != kLTC_Probability100)
    {
        /* Pc parameter is global for all operations, so when Countermeasure B is active,
         * the if is always taken - common execution path
         */
        r32     = ltc_dpa_prng_get_random_word(reqHandle);
        noOp    = reqHandle->Nd - 1u;
        opIndex = getRandomIndex(noOp, r32);

        r32   = ltc_dpa_prng_get_random_word(reqHandle);
        actOp = securePointerSelect(0, opIndex, &reqHandle->dOp, &reqHandle->dOp, r32);
        ltc_set_cmb_count(reqHandle, actOp);
        ltc_run_one_op(base, reqHandle, actOp);

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
        ltc_prepare_gate_off(reqHandle);
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

        for (uint32_t i = 0; i < noOp; i++)
        {
            r32   = ltc_dpa_prng_get_random_word(reqHandle);
            actOp = securePointerSelect(i, opIndex, &reqHandle->rOp, &reqHandle->dOp, r32);
            ltc_set_cmb_count(reqHandle, actOp);
            /* now run actOp */
            ltc_run_one_op(base, reqHandle, actOp);
        }

        r32   = ltc_dpa_prng_get_random_word(reqHandle);
        actOp = securePointerSelect(noOp + 1u, opIndex, &reqHandle->dOp, &reqHandle->dOp, r32);
        ltc_set_cmb_count(reqHandle, actOp);
        ltc_run_one_op(base, reqHandle, actOp);
    }
    else
    {
        r32     = ltc_dpa_prng_get_random_word(reqHandle);
        noOp    = reqHandle->Nd + 1u;
        opIndex = getRandomIndex(noOp, r32);

        for (uint32_t i = 0; i < noOp; i++)
        {
            r32   = ltc_dpa_prng_get_random_word(reqHandle);
            actOp = securePointerSelect(i, opIndex, &reqHandle->rOp, &reqHandle->dOp, r32);

            /* now run actOp */
            ltc_run_one_op(base, reqHandle, actOp);
        }
    }
#else

    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    noOp = reqHandle->Nd + 1u;
    opIndex = getRandomIndex(noOp, r32);

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    ltc_prepare_gate_off(reqHandle);
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
#else
    if (0 == reqHandle->Nd)
    {
        ltc_run_one_op(base, reqHandle, &reqHandle->rOp);
    }
    else
    {
#endif

    for (uint32_t i = 0; i < noOp; i++)
    {
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        actOp = securePointerSelect(i, opIndex, &reqHandle->rOp, &reqHandle->dOp, r32);

        /* now run actOp */
        ltc_run_one_op(base, reqHandle, actOp);
    }

#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
#else
    }
#endif

#endif

    /* get real outData */
    if (output)
    {
        ltc_secure_memcpy(reqHandle, output, (const uint8_t *)(uintptr_t)reqHandle->realOutData, reqHandle->dataSize);
    }

    reqHandle->state = kLTC_CmacUpdateDPA; /* used by e.g.GCM to determine that IV and AAD is done. */

    return kStatus_Success;
}

/*!
 * brief Enable clock to LTC module.
 * This function enables clock to the LTC module.
 * param base LTC peripheral base address
 */
void LTC_InitDPA(LTC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* ungate clock */
    CLOCK_EnableClock(kCLOCK_Ltc0);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
void LTC_SetDummyNumberDPA(ltc_dpa_handle_t *handle, uint32_t num)
{
}
#else
void LTC_SetDummyNumberDPA(ltc_dpa_handle_t *handle, uint32_t num)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    if (num > FSL_LTC_DPA_MAX_ND)
    {
        num = FSL_LTC_DPA_MAX_ND;
    }
    reqHandle->Nd = num;
}
#endif

#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
void LTC_SetDummyProbabilityDPA(ltc_dpa_handle_t *handle, uint32_t probability)
{
}
#else
void LTC_SetDummyProbabilityDPA(ltc_dpa_handle_t *handle, uint32_t probability)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    if (probability > kLTC_Probability100)
    {
        probability = kLTC_Probability100;
    }
    reqHandle->Pc = probability;

#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
    /* make sure *cmbReadCount of all operations is zero
     * so that ltc_run_one_op() takes the path to run to completion for all of them.
     */
    if (kLTC_Probability100 == probability)
    {
        reqHandle->cmbCntZero = 0;
        reqHandle->cmbCnt = 0;
    }
#endif
}
#endif

/*!
 * brief Init the LTC DPA handle which is used in transactional functions
 *
 * This function creates internal context for the LTC DPA functions.
 * This function also initializes LTC DPA Mask Seed DPAMS register with a 32-bit word,
 * where the word is derived from the seed[].
 *
 * param base      LTC module base address
 * param[in,out] handle    Pointer to ltc_dpa_handle_t structure
 * param seed Pointer to 128-bit entropy input.
 * return kStatus_Success is successfull or kStatus_InvalidArgument if error.
 */
status_t LTC_CreateHandleDPA(LTC_Type *base, ltc_dpa_handle_t *handle, uint8_t seed[16])
{
    BUILD_ASSERT((sizeof(ltc_dpa_request_t) >= sizeof(ltc_dpa_req_handle_t)), ltc_dpa_request_t_size_too_low);
    bool zeroSeed;
    uint32_t temp32;

    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* this memset() is important as it clears some structure members.
     * specifically "count" in operations and "cmbCntZero"
     */
    memset(handle, 0, sizeof(ltc_dpa_handle_t));

    ltc_memcpy(reqHandle->rngContext, seed, 16);

    /* make sure the seed[16] is not everywhere zero */
    zeroSeed = true;
    for (int i = 0; i < 16; i++)
    {
        if (0 != seed[i])
        {
            zeroSeed = false;
            break;
        }
    }
    if (zeroSeed)
    {
        return kStatus_InvalidArgument;
    }

    reqHandle->prngHasSeed = true;

#if defined(FSL_FEATURE_LTC_HAS_DPAMS) && FSL_FEATURE_LTC_HAS_DPAMS
    temp32 = ltc_prng_get_random_key32(reqHandle);
    LTC_SetDpaMaskSeedDPA(base, temp32);
#endif

    reqHandle->keyPoolRealKeyEven.realKey  = &reqHandle->keyPoolRealKeyEven.keyWord[0];
    reqHandle->keyPoolRealKeyEven.dummyKey = &reqHandle->keyPoolRealKeyEven.keyWord[1];
    reqHandle->keyPoolRealKeyOdd.realKey   = &reqHandle->keyPoolRealKeyOdd.keyWord[1];
    reqHandle->keyPoolRealKeyOdd.dummyKey  = &reqHandle->keyPoolRealKeyOdd.keyWord[0];
    /* these pointers are used by XCBC-MAC to store derived key K1 from LTC KEY register to real key in key pools */
    reqHandle->rOp.hwDecryptKey0 = reqHandle->keyPoolRealKeyEven.realKey;
    reqHandle->rOp.hwDecryptKey1 = reqHandle->keyPoolRealKeyOdd.realKey;
    reqHandle->dOp.hwDecryptKey0 = reqHandle->keyPoolRealKeyEven.dummyKey;
    reqHandle->dOp.hwDecryptKey1 = reqHandle->keyPoolRealKeyOdd.dummyKey;

#if defined(FSL_LTC_DPA_HAVE_COUNTERMEASURE_B) && (FSL_LTC_DPA_HAVE_COUNTERMEASURE_B > 0)
    reqHandle->rOp.cmbWriteCount = &reqHandle->cmbCnt;
    reqHandle->rOp.cmbReadCount  = &reqHandle->cmbCntZero;
    reqHandle->dOp.cmbWriteCount = &reqHandle->cmbCnt;
    reqHandle->dOp.cmbReadCount  = &reqHandle->cmbCnt;
#endif

#if defined(FSL_LTC_DPA_TAKE_TIMESTAMPS)
    reqHandle->rOp.bReal = true;
    reqHandle->dOp.bReal = false;
#endif

#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
#else
    LTC_SetDummyNumberDPA(handle, 15);
    LTC_SetDummyProbabilityDPA(handle, kLTC_Probability100);
#endif

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    LTC_SetGateOffRepeatDPA(handle, FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT);
    LTC_SetGateOffCyclesDPA(handle, 24u);
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

#if defined(FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER) && (FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER > 0)

    reqHandle->prngRingBuffer.currPrngSrc             = NULL;
    reqHandle->prngRingBuffer.currPrngArraySize       = 0;
    reqHandle->prngRingBuffer.nextPrngSrc             = NULL;
    reqHandle->prngRingBuffer.nextPrngArraySize       = 0;
    reqHandle->prngRingBuffer.prngBuffer              = NULL;
    reqHandle->prngRingBuffer.prngBufferHalfArraySize = 0;
    reqHandle->prngRingBuffer.rngContext[0]           = reqHandle->rngContext[3];
    reqHandle->prngRingBuffer.rngContext[1]           = reqHandle->rngContext[2];
    reqHandle->prngRingBuffer.rngContext[2]           = reqHandle->rngContext[1];
    reqHandle->prngRingBuffer.rngContext[3]           = reqHandle->rngContext[0];
#endif /* FSL_LTC_DPA_HAVE_PRNG_RING_BUFFER */

    return kStatus_Success;
}

#if defined(FSL_FEATURE_LTC_HAS_DPAMS) && FSL_FEATURE_LTC_HAS_DPAMS
/*!
 * brief Sets the DPA Mask Seed register.
 *
 * The DPA Mask Seed register reseeds the mask that provides resistance against DPA (differential power analysis)
 * attacks on AES or DES keys.
 *
 * Differential Power Analysis Mask (DPA) resistance uses a randomly changing mask that introduces
 * "noise" into the power consumed by the AES or DES. This reduces the signal-to-noise ratio that differential
 * power analysis attacks use to "guess" bits of the key. This randomly changing mask should be
 * seeded at POR, and continues to provide DPA resistance from that point on. However, to provide even more
 * DPA protection it is recommended that the DPA mask be reseeded after every 50,000 blocks have
 * been processed. At that time, software can opt to write a new seed (preferably obtained from an RNG)
 * into the DPA Mask Seed register (DPAMS), or software can opt to provide the new seed earlier or
 * later, or not at all. DPA resistance continues even if the DPA mask is never reseeded.
 *
 * param base LTC peripheral base address
 * param mask The DPA mask seed.
 */
void LTC_SetDpaMaskSeedDPA(LTC_Type *base, uint32_t mask)
{
    base->DPAMS = mask;
    base->DPAMS = mask;
}
#endif /* FSL_FEATURE_LTC_HAS_DPAMS */

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
void LTC_SetGateOffRepeatDPA(ltc_dpa_handle_t *handle, uint32_t numRepeat)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (numRepeat > 16u)
    {
        numRepeat = 16u;
    }

    reqHandle->gateOffRepeatMax = numRepeat;
}

void LTC_SetGateOffCyclesDPA(ltc_dpa_handle_t *handle, uint32_t numCycles)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (numCycles > 24u)
    {
        numCycles = 24u;
    }

    reqHandle->gateOffCyclesMax = numCycles;
}
#else
void LTC_SetGateOffRepeatDPA(ltc_dpa_handle_t *handle, uint32_t numRepeat)
{
}
void LTC_SetGateOffCyclesDPA(ltc_dpa_handle_t *handle, uint32_t numCycles)
{
}
#endif /* FSL_LTC_DPA_HAVE_GATE_OFF */

static status_t ltc_aes_check_key_valid(ltc_dpa_req_handle_t *reqHandle)
{
    if ((reqHandle->keySize == 16u)
#if defined(FSL_FEATURE_LTC_HAS_AES192) && FSL_FEATURE_LTC_HAS_AES192
        || ((reqHandle->keySize == 24u))
#endif /* FSL_FEATURE_LTC_HAS_AES192 */
#if defined(FSL_FEATURE_LTC_HAS_AES256) && FSL_FEATURE_LTC_HAS_AES256
        || ((reqHandle->keySize == 32u))
#endif /* FSL_FEATURE_LTC_HAS_AES256 */
    )
    {
        return kStatus_Success;
    }
    return kStatus_InvalidArgument;
}

/*!
 * brief Set key for LTC DPA AES encryption.
 *
 * This function sets key for usage with LTC DPA AES functions.
 *
 * param base      LTC module base address
 * param[in,out] handle    Pointer to ltc_dpa_handle_t structure
 * param probability  Probability that a dummy operation runs to completion.
 * return Status.
 */
status_t LTC_AES_SetKeyDPA(LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *key, size_t keySize)
{
    ltc_dpa_req_handle_t *reqHandle;
    status_t status;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    /* assure the key is aligned at 0-modulo-4 address so that it can be moved with 32-bit accesses */
    if ((uintptr_t)key & 0x3u)
    {
        reqHandle->keySize = 0;
        status             = kStatus_InvalidArgument;
    }
    else
    {
        /* bring key into workspace by secure copy */
        uint32_t r32 = ltc_dpa_prng_get_random_word(reqHandle);

        status                = kStatus_Success;
        uint32_t nextKeyIndex = 8u;
        switch (keySize)
        {
            case 16u:
                secureCopy(reqHandle->key, key, 16, r32);
                nextKeyIndex = 4u;
                break;

            case 24u:
                secureCopy(reqHandle->key, key, 16, r32);
                r32 = ltc_dpa_prng_get_random_word(reqHandle);
                secureCopy(reqHandle->key + 16, key + 16, 8, r32);
                nextKeyIndex = 6u;
                break;

            case 32u:
                secureCopy(reqHandle->key, key, 32, r32);
                nextKeyIndex = 8u;
                break;

            default:
                status = kStatus_InvalidArgument;
                break;
        }

        if (kStatus_Success != status)
        {
            reqHandle->keySize = 0;
            return status;
        }
        else
        {
            reqHandle->keySize = keySize;
        }

        /* fill random key bits up to 32 bytes */
        for (uint32_t i = nextKeyIndex; i < 8u; i++)
        {
            reqHandle->keyWord[i] = ltc_prng_get_random_key32(reqHandle);
        }

        /* copy to interleaved locations in key pools */
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy_wordsInterleaved(reqHandle->keyPoolRealKeyEven.realKey, reqHandle->key, 32, r32);
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy_wordsInterleaved(reqHandle->keyPoolRealKeyOdd.realKey, reqHandle->key, 32, r32);

        status = kStatus_Success;
    }
    return status;
}

/*!
 * brief Encrypts AES using the ECB block mode.
 *
 * Encrypts AES using the ECB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plain text to encrypt
 * param[out] ciphertext Output cipher text
 * param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * return Status from encrypt operation
 */
status_t LTC_AES_EncryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *plaintext, uint8_t *ciphertext, size_t size)
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* ECB mode, size must be 16-byte multiple */
    if (size % 16u)
    {
        return kStatus_InvalidArgument;
    }
    reqHandle->modeReg = 0x00100201u; /* AES ECB Encrypt Update */
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->rOp.ltc_save_context = NULL;
    reqHandle->rOp.ltc_load_context = NULL;
    reqHandle->dOp.ltc_save_context = NULL;
    reqHandle->dOp.ltc_load_context = NULL;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    uint32_t dataSize;
    while (size >= 16u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, ciphertext, plaintext);
        ciphertext += dataSize;
        plaintext += dataSize;
        size -= dataSize;
    }

    return status;
}

/*!
 * brief Decrypts AES using ECB block mode.
 *
 * Decrypts AES using ECB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input cipher text to decrypt
 * param[out] plaintext Output plain text
 * param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * return Status from decrypt operation
 */
status_t LTC_AES_DecryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *ciphertext, uint8_t *plaintext, size_t size)
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* ECB mode, size must be 16-byte multiple */
    if (size % 16u)
    {
        return kStatus_InvalidArgument;
    }
    reqHandle->modeReg = 0x00100200u; /* AES ECB Decrypt Update */
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->rOp.ltc_save_context = NULL;
    reqHandle->rOp.ltc_load_context = NULL;
    reqHandle->dOp.ltc_save_context = NULL;
    reqHandle->dOp.ltc_load_context = NULL;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    uint32_t dataSize;
    while (size >= 16u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, plaintext, ciphertext);
        ciphertext += dataSize;
        plaintext += dataSize;
        size -= dataSize;
    }

    /* restore key pools - due to decrypt key */
    /* TODO? */

    return status;
}

static status_t ltc_save_context_cbc(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);

    secureCopy(&op->CTX[0], (const void *)(uintptr_t)&base->CTX[0], 16, r32);
    return kStatus_Success;
}

static status_t ltc_load_context_cbc(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    if (reqHandle->state == kLTC_CmacInitDPA)
    {
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->initCTX[0], 16, r32);
    }
    else
    {
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->CTX[0], 16, r32);
    }
    return kStatus_Success;
}

/*!
 * brief Encrypts AES using CBC block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plain text to encrypt
 * param[out] ciphertext Output cipher text
 * param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * param iv Input initial vector to combine with the first input block.
 * return Status from encrypt operation
 */
status_t LTC_AES_EncryptCbcDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_AES_IV_SIZE])
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* CBC mode, size must be 16-byte multiple */
    if (size % 16u)
    {
        return kStatus_InvalidArgument;
    }
    reqHandle->modeReg = 0x00100101u; /* AES CBC Encrypt Update */
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.ltc_save_context = &ltc_save_context_cbc;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_cbc;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_cbc;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_cbc;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    /* Write IV data to the context register. */
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->rOp.initCTX[0], &iv[0], 16, r32);
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->dOp.initCTX[0], &reqHandle->rOp.initCTX[0], 16, r32);

    uint32_t dataSize;
    while (size >= 16u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, ciphertext, plaintext);
        ciphertext += dataSize;
        plaintext += dataSize;
        size -= dataSize;
    }

    return status;
}

/*!
 * brief Decrypts AES using CBC block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input cipher text to decrypt
 * param[out] plaintext Output plain text
 * param size Size of input and output data in bytes. Must be multiple of 16 bytes.
 * param iv Input initial vector to combine with the first input block.
 * param key Input key to use for decryption
 * return Status from decrypt operation
 */
status_t LTC_AES_DecryptCbcDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_AES_IV_SIZE])
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* CBC mode, size must be 16-byte multiple */
    if (size % 16u)
    {
        return kStatus_InvalidArgument;
    }
    reqHandle->modeReg = 0x00100100u; /* AES CBC Decrypt Update */
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.ltc_save_context = &ltc_save_context_cbc;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_cbc;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_cbc;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_cbc;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    /* Write IV data to the context register. */
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->rOp.initCTX[0], &iv[0], 16, r32);
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->dOp.initCTX[0], &reqHandle->rOp.initCTX[0], 16, r32);

    uint32_t dataSize;
    while (size >= 16u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, plaintext, ciphertext);
        ciphertext += dataSize;
        plaintext += dataSize;
        size -= dataSize;
    }

    return status;
}

static status_t ltc_save_context_ctr(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&op->CTX[4], (const void *)(uintptr_t)&base->CTX[4], 16, r32);
    return kStatus_Success;
}

static status_t ltc_load_context_ctr(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    if (reqHandle->state == kLTC_CmacInitDPA)
    {
        secureCopy((void *)(uintptr_t)&base->CTX[4], &op->initCTX[4], 16, r32);
    }
    else
    {
        secureCopy((void *)(uintptr_t)&base->CTX[4], &op->CTX[4], 16, r32);
    }
    return kStatus_Success;
}

/*!
 * brief Encrypts or decrypts AES using CTR block mode.
 *
 * Encrypts or decrypts AES using CTR block mode.
 * AES CTR mode uses only forward AES cipher and same algorithm for encryption and decryption.
 * The only difference between encryption and decryption is that, for encryption, the input argument
 * is plain text and the output argument is cipher text. For decryption, the input argument is cipher text
 * and the output argument is plain text.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param input Input data for CTR block mode
 * param[out] output Output data for CTR block mode
 * param size Size of input and output data in bytes
 * param[in,out] counter Input counter (updates on return)
 * param[out] counterlast Output cipher of last counter, for chained CTR calls. NULL can be passed if chained calls are
 * not used.
 * param[out] szLeft Output number of bytes in left unused in counterlast block. NULL can be passed if chained calls
 * are not used.
 * return Status from encrypt operation
 */
status_t LTC_AES_CryptCtrDPA(LTC_Type *base,
                             ltc_dpa_handle_t *handle,
                             const uint8_t *input,
                             uint8_t *output,
                             size_t size,
                             uint8_t counter[LTC_DPA_AES_BLOCK_SIZE],
                             uint8_t counterlast[LTC_DPA_AES_BLOCK_SIZE],
                             size_t *szLeft)
{
    status_t status;
    uint32_t lastSize;
    uint8_t lastBlock[LTC_DPA_AES_BLOCK_SIZE] = {0};
    uint8_t *lastEncryptedCounter;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    reqHandle->modeReg = 0x00100000u; /* AES CTR Update */
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.ltc_save_context = &ltc_save_context_ctr;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_ctr;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_ctr;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_ctr;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    /* Write IV data to the context register. */
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->rOp.initCTX[4], &counter[0], 16, r32);
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->dOp.initCTX[4], &reqHandle->rOp.initCTX[4], 16, r32);

    /* Split the size into full 16-byte chunks and last incomplete block */
    lastSize = 0U;
    if (size <= 16U)
    {
        lastSize = size;
        size     = 0U;
    }
    else
    {
        /* Process all 16-byte data chunks. */
        lastSize = size % 16U;
        if (lastSize == 0U)
        {
            lastSize = 16U;
            size -= 16U;
        }
        else
        {
            size -= lastSize; /* size will be rounded down to 16 byte boundary. remaining bytes in lastSize */
        }
    }

    uint32_t dataSize;
    while (size >= 16u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, output, input);
        output += dataSize;
        input += dataSize;
        size -= dataSize;
    }

    /* last block */
    if (counterlast)
    {
        lastEncryptedCounter = counterlast;
    }
    else
    {
        lastEncryptedCounter = lastBlock;
    }

    reqHandle->dataSize = 16u;
    ltc_one_block(base, reqHandle, lastEncryptedCounter,
                  lastBlock); /* lastBlock is all zeroes, so I get directly ECB of the last counter, as the XOR with
                                 zeroes doesn't change */

    /* remain output = input XOR counterlast */
    /* TODO secure XOR here ? */
    for (uint32_t i = 0; i < lastSize; i++)
    {
        output[i] = input[i] ^ lastEncryptedCounter[i];
    }

    /* read counter value after last encryption */
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&counter[0], (const void *)(uintptr_t)&base->CTX[4], 16, r32);

    if (szLeft)
    {
        *szLeft = 16U - lastSize;
    }

    return status;
}

#if defined(FSL_FEATURE_LTC_HAS_GCM) && FSL_FEATURE_LTC_HAS_GCM

static status_t ltc_save_context_gcm(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&op->CTX[0], (const void *)(uintptr_t)&base->CTX[0], 64, r32);
    return kStatus_Success;
}

static status_t ltc_load_context_gcm(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    status_t status;

    /* in init state, move IV and AAD */
    if (kLTC_CmacInitDPA == reqHandle->state)
    {
        base->COM = LTC_COM_AES_MASK;
        /* basic LTC configuration */
        base->CW = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CCR_MASK | LTC_CW_CICV_MASK /*| LTC_CW_CKR_MASK */ |
                   LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
        base->STA = LTC_STA_DI_MASK;
        base->CTL = LTC_CTL_COS_MASK | LTC_CTL_CIS_MASK | LTC_CTL_KOS_MASK | LTC_CTL_KIS_MASK | LTC_CTL_OFS_MASK |
                    LTC_CTL_IFS_MASK;
        bool ivOnly  = (reqHandle->xcm.aadSize == 0) && (reqHandle->xcm.inputSize == 0);
        bool aadOnly = (reqHandle->xcm.inputSize == 0);
        status       = ltc_aes_gcm_do_iv(base, reqHandle, reqHandle->xcm.encryptMode, reqHandle->xcm.iv,
                                   reqHandle->xcm.ivSize, ivOnly);
        if (status != kStatus_Success)
        {
            return status;
        }

        status = ltc_aes_gcm_do_aad(base, reqHandle, reqHandle->xcm.encryptMode, reqHandle->xcm.aad,
                                    reqHandle->xcm.aadSize, aadOnly);
        if (status != kStatus_Success)
        {
            return status;
        }

        if (reqHandle->xcm.inputSize == 0)
        {
            return kStatus_LTC_GcmGHASH;
        }
    }
    else
    {
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->CTX[0], 64, r32);
    }
    return kStatus_Success;
}

/*!
 * @brief AES GCM check validity of input arguments.
 *
 * This function checks the validity of input arguments.
 *
 * @param base LTC peripheral base address.
 * @param src Source address (plaintext or ciphertext).
 * @param iv Initialization vector address.
 * @param aad Additional authenticated data address.
 * @param dst Destination address (plaintext or ciphertext).
 * @param inputSize Size of input (same size as output) data in bytes.
 * @param ivSize Size of Initialization vector in bytes.
 * @param aadSize Size of additional data in bytes.
 * @param tagSize Size of the GCM tag in bytes.
 */
static status_t ltc_aes_gcm_check_input_args(LTC_Type *base,
                                             const uint8_t *src,
                                             const uint8_t *iv,
                                             const uint8_t *aad,
                                             uint8_t *dst,
                                             size_t inputSize,
                                             size_t ivSize,
                                             size_t aadSize,
                                             size_t tagSize)
{
    if (!base)
    {
        return kStatus_InvalidArgument;
    }

    /* tag can be NULL to skip tag processing */
    if ((ivSize && (!iv)) || (aadSize && (!aad)) || (inputSize && ((!src) || (!dst))))
    {
        return kStatus_InvalidArgument;
    }

    /* octet length of tag (tagSize) must be element of 4,8,12,13,14,15,16 */
    if (((tagSize > 16u) || (tagSize < 12u)) && (tagSize != 4u) && (tagSize != 8u))
    {
        return kStatus_InvalidArgument;
    }

    /* no IV AAD DATA makes no sense */
    if (0 == (inputSize + ivSize + aadSize))
    {
        return kStatus_InvalidArgument;
    }

    /* check length of input strings. This is more strict than the GCM specificaiton due to 32-bit architecture.
     * The API interface would work on 64-bit architecture as well, but as it has not been tested, let it limit to
     * 32-bits.
     */
    if (!((ivSize >= 1u) && (sizeof(size_t) <= 4u)))
    {
        return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

static void ltc_move_block_to_ififo(LTC_Type *base, const ltc_xcm_block_t *blk, uint32_t dataSize)
{
    uint32_t dataWords = (dataSize + 3u) >> 2;

    uint32_t i = dataWords;
    while (i)
    {
        uint32_t fifosta;
        do
        {
            fifosta = base->FIFOSTA;
        } while ((fifosta & LTC_FIFOSTA_IFF_MASK) /*|| (0 == (fifosta & LTC_FIFOSTA_OFL_MASK))*/);
        base->IFIFO = blk->w[dataWords - i];
        i--;
    }
}

static void ltc_move_to_ififo(LTC_Type *base, const uint8_t *data, size_t dataSize)
{
    ltc_xcm_block_t blk;

    while (dataSize)
    {
        if (dataSize >= 16u)
        {
            ltc_memcpy(&blk, data, 16u);
            dataSize -= 16u;
            data += 16u;
            ltc_move_block_to_ififo(base, &blk, 16u);
        }
        else
        {
            ltc_xcm_block_t blkZero = {{0x0u, 0x0u, 0x0u, 0x0u}};
            ltc_memcpy(&blkZero, data, dataSize);
            dataSize = 0;
            ltc_move_block_to_ififo(base, &blkZero, 16u);
        }
    }
}

static status_t ltc_aes_gcm_do_iv(LTC_Type *base,
                                  ltc_dpa_req_handle_t *reqHandle,
                                  ltc_aes_encryption_decryption_mode_t encryptMode,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  bool ivOnly)
{
    status_t status = kStatus_Success;
    size_t fifoSize = LTC_DPA_FIFO_SIZE;
    bool wait       = false;

    uint32_t md;
    uint32_t size;
    uint32_t ivsz;

    while (ivSize)
    {
        if (ivSize > 16u)
        {
            md = kLTC_CfgAesGcm | LTC_MD_AS(kLTC_CfgAsUpdate);
            if (encryptMode == kAES_ModeEncrypt)
            {
                md |= LTC_MD_ENC_MASK;
            }

            if (ivSize >= fifoSize)
            {
                size = fifoSize;
            }
            else
            {
                size = ((ivSize >> 4) << 4);
            }
            ivsz = size | LTC_IVSZ_IL(1);
            wait = true;
        }
        else
        {
            md = kLTC_CfgAesGcm;
            if (ivOnly)
            {
                md |= LTC_MD_AS(kLTC_CfgAsInitializeFinalize);
            }
            else
            {
                md |= LTC_MD_AS(kLTC_CfgAsInitialize);
            }
            if (encryptMode == kAES_ModeEncrypt)
            {
                md |= LTC_MD_ENC_MASK;
            }
            size = ivSize;
            ivsz = size | LTC_IVSZ_IL(1);
            wait = true;
        }

        base->MD   = md;
        base->IVSZ = ivsz;
        ltc_move_to_ififo(base, iv, size);
        if (wait)
        {
            status = ltc_wait(base);
            if (status != kStatus_Success)
            {
                break;
            }
            base->CW = LTC_CW_CIF_MASK;
        }
        iv += size;
        ivSize -= size;
    }

    return status;
}

static status_t ltc_aes_gcm_do_aad(LTC_Type *base,
                                   ltc_dpa_req_handle_t *reqHandle,
                                   ltc_aes_encryption_decryption_mode_t encryptMode,
                                   const uint8_t *aad,
                                   size_t aadSize,
                                   bool aadOnly)
{
    status_t status = kStatus_Success;
    size_t fifoSize = LTC_DPA_FIFO_SIZE;
    bool wait       = false;

    uint32_t md;
    uint32_t size;
    uint32_t aadsz;

    while (aadSize)
    {
        if (aadSize > 16u)
        {
            md = kLTC_CfgAesGcm | LTC_MD_AS(kLTC_CfgAsUpdate);
            if (encryptMode == kAES_ModeEncrypt)
            {
                md |= LTC_MD_ENC_MASK;
            }

            if (aadSize >= fifoSize)
            {
                size = fifoSize;
            }
            else
            {
                size = ((aadSize >> 4) << 4); /* div by 16 */
            }
            aadsz = size | LTC_AADSZ_AL(1);
            wait  = true;
        }
        else
        {
            md = kLTC_CfgAesGcm;
            if (aadOnly)
            {
                md |= LTC_MD_AS(kLTC_CfgAsInitializeFinalize);
            }
            else
            {
                md |= LTC_MD_AS(kLTC_CfgAsUpdate);
            }
            if (encryptMode == kAES_ModeEncrypt)
            {
                md |= LTC_MD_ENC_MASK;
            }
            size  = aadSize;
            aadsz = size | LTC_AADSZ_AL(1);
            wait  = true;
        }

        base->MD    = md;
        base->AADSZ = aadsz;
        ltc_move_to_ififo(base, aad, size);
        if (wait)
        {
            status = ltc_wait(base);
            if (status != kStatus_Success)
            {
                break;
            }
            base->CW = LTC_CW_CIF_MASK;
        }
        aad += size;
        aadSize -= size;
    }

    return status;
}

static status_t ltc_aes_gcm_do_data(LTC_Type *base,
                                    ltc_dpa_handle_t *handle,
                                    ltc_aes_encryption_decryption_mode_t encryptMode,
                                    const uint8_t *input,
                                    uint8_t *output,
                                    size_t size)
{
    uint32_t md;
    ltc_dpa_req_handle_t *reqHandle;

    md = kLTC_CfgAesGcm;
    if (encryptMode == kAES_ModeEncrypt)
    {
        md |= LTC_MD_ENC_MASK;
    }

    reqHandle          = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    reqHandle->modeReg = md | LTC_MD_AS(kLTC_CfgAsUpdate);

    if (!size)
    {
        ltc_one_block(base, reqHandle, output, input);
    }
    else
    {
        /* Split the size into full 16-byte chunks and last incomplete block */
        uint32_t lastSize = 0U;
        if (size <= 16U)
        {
            lastSize = size;
            size     = 0U;
        }
        else
        {
            /* Process all 16-byte data chunks. */
            lastSize = size % 16u;
            if (lastSize == 0U)
            {
                lastSize = 16U;
                size -= 16U;
            }
            else
            {
                size -= lastSize; /* size will be rounded down to 16 byte boundary. remaining bytes in lastSize */
            }
        }

        uint32_t dataSize;
        while (size >= 16u)
        {
            if (size >= OPERATION_DATA_SIZE)
            {
                dataSize = OPERATION_DATA_SIZE;
            }
            else
            {
                dataSize = size;
            }

            reqHandle->dataSize = dataSize;
            ltc_one_block(base, reqHandle, output, input);
            output += dataSize;
            input += dataSize;
            size -= dataSize;
        }

        if (lastSize)
        {
            reqHandle->modeReg  = md | LTC_MD_AS(kLTC_CfgAsInitializeFinalize);
            reqHandle->dataSize = lastSize;
            ltc_one_block(base, reqHandle, output, input);
        }
    }

    return kStatus_Success;
}

/*!
 * @brief Receives MAC compare.
 *
 * This function is a sub-process of CCM and GCM decryption.
 * It compares received MAC with the MAC computed during decryption.
 *
 * @param base LTC peripheral base address
 * @param tag Received MAC.
 * @param tagSize Number of bytes in the received MAC.
 * @param modeReg LTC Mode Register current value. It is modified and written to LTC Mode Register.
 */
static status_t ltc_aes_received_mac_compare(LTC_Type *base, const uint8_t *tag, uint32_t tagSize, uint32_t modeReg)
{
    ltc_xcm_block_t blk = {{0x0u, 0x0u, 0x0u, 0x0u}};

    base->CW  = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
    base->STA = LTC_STA_DI_MASK;

    modeReg &= ~LTC_MD_AS_MASK;
    modeReg |= LTC_MD_AS(kLTC_CfgAsUpdate) | LTC_MD_ICV_TEST_MASK;
    base->MD = modeReg;

    base->DS   = 0;
    base->ICVS = tagSize;
    ltc_memcpy(&blk.b[0], &tag[0], tagSize);

    ltc_move_block_to_ififo(base, &blk, tagSize);
    return ltc_wait(base);
}

/*!
 * @brief GCM process.
 *
 * This function is the main function for AES GCM encryption/decryption and tag generation/comparison.
 *
 * @param base LTC peripheral base address.
 * @param encryptMode Whether the actual operation is an encryption or a decryption.
 * @param src Input plaintext for encryption or ciphertext for decryption.
 * @param inputSize Size of input and output in bytes.
 * @param iv Input initial vector.
 * @param ivSize Size of initial vector in bytes.
 * @param aad Additional authenticated data.
 * @param aadSize Size of additional authenticated data in bytes.
 * @param dst Output ciphertext for encryption or plaintext for decryption.
 * @param tag For encryption, GCM tag output. For decryption, GCM tag input for comparison.
 * @param tagSize Size of the GCM tag in bytes.
 */
static status_t ltc_aes_gcm_process(LTC_Type *base,
                                    ltc_dpa_handle_t *handle,
                                    ltc_aes_encryption_decryption_mode_t encryptMode,
                                    const uint8_t *src,
                                    size_t inputSize,
                                    const uint8_t *iv,
                                    size_t ivSize,
                                    const uint8_t *aad,
                                    size_t aadSize,
                                    uint8_t *dst,
                                    uint8_t *tag,
                                    size_t tagSize)
{
    status_t status;
    uint8_t blkTag[16] = {0};
    ltc_dpa_req_handle_t *reqHandle;

    status = ltc_aes_gcm_check_input_args(base, src, iv, aad, dst, inputSize, ivSize, aadSize, tagSize);
    if (status != kStatus_Success)
    {
        return status;
    }

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif
    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.ltc_save_context = &ltc_save_context_gcm;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_gcm;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_gcm;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_gcm;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;
    reqHandle->xcm.iv               = iv;
    reqHandle->xcm.aad              = aad;
    reqHandle->xcm.ivSize           = ivSize;
    reqHandle->xcm.aadSize          = aadSize;
    reqHandle->xcm.inputSize        = inputSize;
    reqHandle->xcm.encryptMode      = encryptMode;

    status = ltc_aes_gcm_do_data(base, handle, encryptMode, src, dst, inputSize);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (tag && tagSize)
    {
        if (encryptMode == kAES_ModeEncrypt)
        {
            ltc_memcpy(blkTag, (const void *)(uintptr_t)&reqHandle->rOp.CTX[kLTC_ContextIndexGcmTag], sizeof(blkTag));
            ltc_memcpy(tag, blkTag, tagSize);
        }
        else
        {
            ltc_load_context_gcm(base, reqHandle, &reqHandle->rOp);
            status = ltc_aes_received_mac_compare(base, tag, tagSize, kLTC_CfgAesGcm);
        }
    }
    return status;
}

/*!
 * brief Encrypts AES and tags using GCM block mode.
 *
 * Encrypts AES and optionally tags using GCM block mode. If plaintext is NULL, only the GHASH is calculated and output
 * in the 'tag' field.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plain text to encrypt
 * param[out] ciphertext Output cipher text.
 * param size Size of input and output data in bytes
 * param iv Input initial vector
 * param ivSize Size of the IV
 * param aad Input additional authentication data
 * param aadSize Input size in bytes of AAD
 * param[out] tag Output hash tag. Set to NULL to skip tag processing.
 * param tagSize Input size of the tag to generate, in bytes. Must be 4,8,12,13,14,15 or 16.
 * return Status from encrypt operation
 */
status_t LTC_AES_EncryptTagGcmDPA(LTC_Type *base,
                                  ltc_dpa_handle_t *handle,
                                  const uint8_t *plaintext,
                                  uint8_t *ciphertext,
                                  size_t size,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  const uint8_t *aad,
                                  size_t aadSize,
                                  uint8_t *tag,
                                  size_t tagSize)
{
    status_t status;
    status = ltc_aes_gcm_process(base, handle, kAES_ModeEncrypt, plaintext, size, iv, ivSize, aad, aadSize, ciphertext,
                                 tag, tagSize);
    return status;
}

/*!
 * brief Decrypts AES and authenticates using GCM block mode.
 *
 * Decrypts AES and optionally authenticates using GCM block mode. If ciphertext is NULL, only the GHASH is calculated
 * and compared with the received GHASH in 'tag' field.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input cipher text to decrypt
 * param[out] plaintext Output plain text.
 * param size Size of input and output data in bytes
 * param iv Input initial vector
 * param ivSize Size of the IV
 * param aad Input additional authentication data
 * param aadSize Input size in bytes of AAD
 * param tag Input hash tag to compare. Set to NULL to skip tag processing.
 * param tagSize Input size of the tag, in bytes. Must be 4, 8, 12, 13, 14, 15, or 16.
 * return Status from decrypt operation
 */
status_t LTC_AES_DecryptTagGcmDPA(LTC_Type *base,
                                  ltc_dpa_handle_t *handle,
                                  const uint8_t *ciphertext,
                                  uint8_t *plaintext,
                                  size_t size,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  const uint8_t *aad,
                                  size_t aadSize,
                                  const uint8_t *tag,
                                  size_t tagSize)
{
    uint8_t temp_tag[16] = {0}; /* max. octet length of MAC (tag) is 16 */
    uint8_t *tag_ptr;
    status_t status;

    tag_ptr = NULL;
    if (tag)
    {
        ltc_memcpy(temp_tag, tag, tagSize);
        tag_ptr = &temp_tag[0];
    }

    status = ltc_aes_gcm_process(base, handle, kAES_ModeDecrypt, ciphertext, size, iv, ivSize, aad, aadSize, plaintext,
                                 tag_ptr, tagSize);
    return status;
}
#endif /* FSL_FEATURE_LTC_HAS_GCM */

#if defined(FSL_FEATURE_LTC_HAS_DES) && (FSL_FEATURE_LTC_HAS_DES > 0)

typedef enum _ltc_des_configuration
{
    kLTC_CfgDesEncryptEcb = 0x00200201U,
    kLTC_CfgDesDecryptEcb = 0x00200200U,
    kLTC_CfgDesEncryptCfb = 0x00200301U,
    kLTC_CfgDesDecryptCfb = 0x00200300U,
    kLTC_CfgDesEncryptCbc = 0x00200101U,
    kLTC_CfgDesDecryptCbc = 0x00200100U,
    kLTC_CfgDesCryptOfb   = 0x00200401U,
} ltc_des_configuration_t;

static status_t ltc_des_check_key_valid(ltc_dpa_req_handle_t *reqHandle)
{
    if ((reqHandle->keySize == 8u) || ((reqHandle->keySize == 16u)) || ((reqHandle->keySize == 24u)))
    {
        return kStatus_Success;
    }
    return kStatus_InvalidArgument;
}

static status_t ltc_save_context_des(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);

    secureCopy(&op->CTX[0], (const void *)(uintptr_t)&base->CTX[0], 8, r32);
    return kStatus_Success;
}

static status_t ltc_load_context_des(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    if (reqHandle->state == kLTC_CmacInitDPA)
    {
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->initCTX[0], 8, r32);
    }
    else
    {
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->CTX[0], 8, r32);
    }
    return kStatus_Success;
}

/*!
 * @brief Main function for DES/3DES in ECB, CBC, CFB and OFB modes.
 *
 * @param base LTC peripheral base address
 * @param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * @param input Input plaintext for encryption, input ciphertext for decryption.
 * @param[out] output Output ciphertext for encryption, output plaintext for decryption.
 * @param size Size of input and output data in bytes. For ECB, CBC and CFB it must be multiple of 8-bytes.
 * @param iv Input initial vector to combine with the first input block.
 * @return Status from the operation.
 */
static status_t ltc_des_block_mode(LTC_Type *base,
                                   ltc_dpa_handle_t *handle,
                                   const uint8_t *input,
                                   uint8_t *output,
                                   size_t size,
                                   const uint8_t iv[LTC_DPA_DES_IV_SIZE],
                                   ltc_des_configuration_t configuration)
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    /* ECB, CBC and CFB mode, size must be 8-byte multiple */
    switch (configuration)
    {
        case kLTC_CfgDesEncryptEcb:
        case kLTC_CfgDesDecryptEcb:
        case kLTC_CfgDesEncryptCfb:
        case kLTC_CfgDesDecryptCfb:
        case kLTC_CfgDesEncryptCbc:
        case kLTC_CfgDesDecryptCbc:
            if (size % 8u)
            {
                status = kStatus_InvalidArgument;
            }
            else
            {
                status = kStatus_Success;
            }
            break;

        case kLTC_CfgDesCryptOfb:
            status = kStatus_Success;
            break;

        default:
            status = kStatus_InvalidArgument;
            break;
    }
    if (status != kStatus_Success)
    {
        return status;
    }

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_des_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (reqHandle->keySize == 8u)
    {
        reqHandle->modeReg = (uint32_t)configuration;
    }
    else
    {
        reqHandle->modeReg = (uint32_t)configuration | (1u << 16); /* add 3DES to AAI */
    }

    /* For CBC, CFB and OFB modes write the Initialization Vector (IV) in context registers. */
    /* Write IV data to the context register. */
    uint32_t r32;
    if (iv != NULL)
    {
        reqHandle->rOp.ltc_save_context = &ltc_save_context_des;
        reqHandle->rOp.ltc_load_context = &ltc_load_context_des;
        reqHandle->dOp.ltc_save_context = &ltc_save_context_des;
        reqHandle->dOp.ltc_load_context = &ltc_load_context_des;
        /* Write IV data to the context register. */
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy(&reqHandle->rOp.initCTX[0], &iv[0], LTC_DPA_DES_IV_SIZE, r32);
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy(&reqHandle->dOp.initCTX[0], &reqHandle->rOp.initCTX[0], LTC_DPA_DES_IV_SIZE, r32);
    }
    else
    {
        reqHandle->rOp.ltc_save_context = NULL;
        reqHandle->rOp.ltc_load_context = NULL;
        reqHandle->dOp.ltc_save_context = NULL;
        reqHandle->dOp.ltc_load_context = NULL;
    }

#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 2u;
    reqHandle->gateOffRepeatMax = 0;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_DES;
#endif
    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;

    uint32_t dataSize;
    while (size >= 8u)
    {
        if (size >= OPERATION_DATA_SIZE)
        {
            dataSize = OPERATION_DATA_SIZE;
        }
        else
        {
            dataSize = size;
        }

        reqHandle->dataSize = dataSize;
        ltc_one_block(base, reqHandle, output, input);
        output += dataSize;
        input += dataSize;
        size -= dataSize;
    }

    /* OFB can have non-block multiple size. ECB, CBC and CFB have size zero at this moment. */
    if (size)
    {
        uint8_t blkTemp[LTC_DPA_DES_BLOCK_SIZE] = {0};

        ltc_memcpy(blkTemp, input, size);
        ltc_one_block(base, reqHandle, blkTemp, blkTemp);
        ltc_memcpy(output, blkTemp, size);
    }

    return status;
}

/*!
 * brief Set key for LTC DPA DES operations.
 *
 * This function sets key for usage with LTC DPA DES functions.
 *
 * param base      LTC module base address
 * param[in,out] handle    Pointer to ltc_dpa_handle_t structure
 * param key1 The 1st 8-byte key.
 * param key2 The 2nd 8-byte key. Can be NULL if running simple DES.
 * param key3 The 3rd 8-byte key. Can be NULL if running 3DES with 2 keys (16-byte key).
 * return Status.
 */
status_t LTC_DES_SetKeyDPA(LTC_Type *base,
                           ltc_dpa_handle_t *handle,
                           const uint8_t key1[LTC_DPA_DES_KEY_SIZE],
                           const uint8_t key2[LTC_DPA_DES_KEY_SIZE],
                           const uint8_t key3[LTC_DPA_DES_KEY_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;
    status_t status;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    status = kStatus_Success;

    /* assure the key is aligned at 0-modulo-4 address so that it can be moved with 32-bit accesses */
    const uint8_t *desKey[3] = {key1, key2, key3};
    for (int i = 0; i < 3; i++)
    {
        if ((desKey[i]) && (((uintptr_t)desKey[i]) & 3u))
        {
            reqHandle->keySize = 0;
            status             = kStatus_InvalidArgument;
            break;
        }
    }
    if (kStatus_Success != status)
    {
        return status;
    }

    size_t keySize = 0;
    uint32_t r32;
    uint32_t nextKeyIndex;
    if (key1)
    {
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy((void *)(uintptr_t)&reqHandle->keyWord[0], (const void *)(uintptr_t)&key1[0], 8, r32);
        keySize      = 8u;
        nextKeyIndex = 2u;
        if (key2)
        {
            r32 = ltc_dpa_prng_get_random_word(reqHandle);
            secureCopy((void *)(uintptr_t)&reqHandle->keyWord[2], (const void *)(uintptr_t)&key2[0], 8, r32);
            keySize      = 16u;
            nextKeyIndex = 4u;
            if (key3)
            {
                r32 = ltc_dpa_prng_get_random_word(reqHandle);
                secureCopy((void *)(uintptr_t)&reqHandle->keyWord[4], (const void *)(uintptr_t)&key3[0], 8, r32);
                keySize      = 24u;
                nextKeyIndex = 6u;
            }
        }
    }

    if (0 == keySize)
    {
        return kStatus_InvalidArgument;
    }

    reqHandle->keySize = keySize;

    /* fill random key bits up to 32 bytes */
    for (uint32_t i = nextKeyIndex; i < 8u; i++)
    {
        reqHandle->keyWord[i] = ltc_prng_get_random_key32(reqHandle);
    }

    /* copy to interleaved locations in key pools */
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy_wordsInterleaved(reqHandle->keyPoolRealKeyEven.realKey, reqHandle->key, 32, r32);
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy_wordsInterleaved(reqHandle->keyPoolRealKeyOdd.realKey, reqHandle->key, 32, r32);

    return kStatus_Success;
}

/*!
 * brief Encrypts DES using ECB block mode.
 *
 * Encrypts DES using ECB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *plaintext, uint8_t *ciphertext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, NULL, kLTC_CfgDesEncryptEcb);
}

/*!
 * brief Decrypts DES using ECB block mode.
 *
 * Decrypts DES using ECB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *ciphertext, uint8_t *plaintext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, NULL, kLTC_CfgDesDecryptEcb);
}

/*!
 * brief Encrypts DES using CBC block mode.
 *
 * Encrypts DES using CBC block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Ouput ciphertext
 * param size Size of input and output data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptCbcDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCbc);
}

/*!
 * brief Decrypts DES using CBC block mode.
 *
 * Decrypts DES using CBC block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptCbcDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCbc);
}

/*!
 * brief Encrypts DES using CFB block mode.
 *
 * Encrypts DES using CFB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param size Size of input data in bytes
 * param iv Input initial block.
 * param[out] ciphertext Output ciphertext
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptCfbDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCfb);
}

/*!
 * brief Decrypts DES using CFB block mode.
 *
 * Decrypts DES using CFB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input initial block.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptCfbDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCfb);
}

/*!
 * brief Encrypts DES using OFB block mode.
 *
 * Encrypts DES using OFB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_EncryptOfbDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *plaintext,
                               uint8_t *ciphertext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesCryptOfb);
}

/*!
 * brief Decrypts DES using OFB block mode.
 *
 * Decrypts DES using OFB block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES_DecryptOfbDPA(LTC_Type *base,
                               ltc_dpa_handle_t *handle,
                               const uint8_t *ciphertext,
                               uint8_t *plaintext,
                               size_t size,
                               const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 8u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesCryptOfb);
}

/*!
 * brief Encrypts triple DES using ECB block mode with two keys.
 *
 * Encrypts triple DES using ECB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *plaintext, uint8_t *ciphertext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, NULL, kLTC_CfgDesEncryptEcb);
}

/*!
 * brief Decrypts triple DES using ECB block mode with two keys.
 *
 * Decrypts triple DES using ECB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *ciphertext, uint8_t *plaintext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, NULL, kLTC_CfgDesDecryptEcb);
}

/*!
 * brief Encrypts triple DES using CBC block mode with two keys.
 *
 * Encrypts triple DES using CBC block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptCbcDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCbc);
}

/*!
 * brief Decrypts triple DES using CBC block mode with two keys.
 *
 * Decrypts triple DES using CBC block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptCbcDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCbc);
}

/*!
 * brief Encrypts triple DES using CFB block mode with two keys.
 *
 * Encrypts triple DES using CFB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes
 * param iv Input initial block.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptCfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCfb);
}

/*!
 * brief Decrypts triple DES using CFB block mode with two keys.
 *
 * Decrypts triple DES using CFB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input initial block.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptCfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCfb);
}

/*!
 * brief Encrypts triple DES using OFB block mode with two keys.
 *
 * Encrypts triple DES using OFB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_EncryptOfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesCryptOfb);
}

/*!
 * brief Decrypts triple DES using OFB block mode with two keys.
 *
 * Decrypts triple DES using OFB block mode with two keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES2_DecryptOfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 16u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesCryptOfb);
}

/*!
 * brief Encrypts triple DES using ECB block mode with three keys.
 *
 * Encrypts triple DES using ECB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *plaintext, uint8_t *ciphertext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, NULL, kLTC_CfgDesEncryptEcb);
}

/*!
 * brief Decrypts triple DES using ECB block mode with three keys.
 *
 * Decrypts triple DES using ECB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes. Must be multiple of 8 bytes.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptEcbDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *ciphertext, uint8_t *plaintext, size_t size)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, NULL, kLTC_CfgDesDecryptEcb);
}

/*!
 * brief Encrypts triple DES using CBC block mode with three keys.
 *
 * Encrypts triple DES using CBC block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptCbcDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCbc);
}

/*!
 * brief Decrypts triple DES using CBC block mode with three keys.
 *
 * Decrypts triple DES using CBC block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input initial vector to combine with the first plaintext block.
 *           The iv does not need to be secret, but it must be unpredictable.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptCbcDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCbc);
}

/*!
 * brief Encrypts triple DES using CFB block mode with three keys.
 *
 * Encrypts triple DES using CFB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and ouput data in bytes
 * param iv Input initial block.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptCfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesEncryptCfb);
}

/*!
 * brief Decrypts triple DES using CFB block mode with three keys.
 *
 * Decrypts triple DES using CFB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input data in bytes
 * param iv Input initial block.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptCfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesDecryptCfb);
}

/*!
 * brief Encrypts triple DES using OFB block mode with three keys.
 *
 * Encrypts triple DES using OFB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plaintext to encrypt
 * param[out] ciphertext Output ciphertext
 * param size Size of input and output data in bytes
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_EncryptOfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *plaintext,
                                uint8_t *ciphertext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, plaintext, ciphertext, size, iv, kLTC_CfgDesCryptOfb);
}

/*!
 * brief Decrypts triple DES using OFB block mode with three keys.
 *
 * Decrypts triple DES using OFB block mode with three keys.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input ciphertext to decrypt
 * param[out] plaintext Output plaintext
 * param size Size of input and output data in bytes
 * param iv Input unique input vector. The OFB mode requires that the IV be unique
 *           for each execution of the mode under the given key.
 * return Status from encrypt/decrypt operation
 */
status_t LTC_DES3_DecryptOfbDPA(LTC_Type *base,
                                ltc_dpa_handle_t *handle,
                                const uint8_t *ciphertext,
                                uint8_t *plaintext,
                                size_t size,
                                const uint8_t iv[LTC_DPA_DES_IV_SIZE])
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if (reqHandle->keySize != 24u)
    {
        return kStatus_InvalidArgument;
    }
    return ltc_des_block_mode(base, handle, ciphertext, plaintext, size, iv, kLTC_CfgDesCryptOfb);
}

#endif /* FSL_FEATURE_LTC_HAS_DES */

/*!
 * @brief Check validity of algoritm.
 *
 * This function checks the validity of input argument.
 *
 * @param algo Tested algorithm value.
 * @return kStatus_Success if valid, kStatus_InvalidArgument otherwise.
 */
static status_t ltc_cmac_check_input_alg(ltc_dpa_hash_algo_t algo)
{
    if ((algo != kLTC_XcbcMacDPA) && (algo != kLTC_CmacDPA))
    {
        return kStatus_InvalidArgument;
    }
    return kStatus_Success;
}

/*!
 * @brief Check validity of input arguments.
 *
 * This function checks the validity of input arguments.
 *
 * @param base LTC peripheral base address.
 * @param handle
 * @param algo Tested algorithm value.
 * @return kStatus_Success if valid, kStatus_InvalidArgument otherwise.
 */
static status_t ltc_cmac_check_input_args(LTC_Type *base, ltc_dpa_handle_t *handle, ltc_dpa_hash_algo_t algo)
{
    /* Check validity of input algorithm */
    if (kStatus_Success != ltc_cmac_check_input_alg(algo))
    {
        return kStatus_InvalidArgument;
    }

    if ((NULL == handle) || (NULL == base))
    {
        return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

/*!
 * @brief Check validity of internal software context.
 *
 * This function checks if the internal context structure looks correct.
 *
 * @param handle Internal context.
 * @param message Input message address.
 * @return kStatus_Success if valid, kStatus_InvalidArgument otherwise.
 */
static status_t ltc_cmac_check_context(ltc_dpa_handle_t *handle, const uint8_t *message)
{
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;
    if ((NULL == message) || (NULL == handle) || (kStatus_Success != ltc_cmac_check_input_alg(reqHandle->hashAlgo)))
    {
        return kStatus_InvalidArgument;
    }
    /* Check handle has been initialized */

    if (kStatus_Success != ltc_dpa_check_handle(reqHandle))
    {
        return kStatus_InvalidArgument;
    }

    return kStatus_Success;
}

static status_t ltc_cmac_process_message_data(
    LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *message, size_t messageSize, ltc_md_as_t mdAs)
{
    uint32_t algAai;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* first fill the internal buffer to full block */
    size_t toCopy = OPERATION_DATA_SIZE - reqHandle->blksz;
    ltc_memcpy((uint8_t *)(&reqHandle->realOutData) + reqHandle->blksz, message, toCopy);
    message += toCopy;
    messageSize -= toCopy;

    /* process full internal block */
    if (reqHandle->hashAlgo == kLTC_XcbcMacDPA)
    {
        algAai = kLTC_CfgAesXcbcMac;
    }
    else
    {
        algAai = kLTC_CfgAesCmac;
    }
    /* AS bits for the MD register for internal buffer are set by mdAs.
     * This is mainly to process the first request in INITIALIZE or INITIALIZE/FINALIZE
     */
    reqHandle->modeReg = algAai | LTC_MD_AS(mdAs);

    ltc_one_block(base, reqHandle, NULL, (uint8_t *)(&reqHandle->realOutData));

    /* process all full blocks in message[] */
    reqHandle->modeReg = algAai | LTC_MD_AS(kLTC_CfgAsUpdate);
    while (messageSize > OPERATION_DATA_SIZE)
    {
        ltc_one_block(base, reqHandle, NULL, message);
        message += OPERATION_DATA_SIZE;
        messageSize -= OPERATION_DATA_SIZE;
    }

    /* copy last message bytes into internal block */
    ltc_memcpy((uint8_t *)(&reqHandle->realOutData), message, messageSize);

    reqHandle->blksz = messageSize; /* runs also if messageSize is zero. */
    return kStatus_Success;
}

static status_t ltc_cmac_finalize(LTC_Type *base, ltc_dpa_handle_t *handle, ltc_md_as_t mdAs)
{
    uint32_t algAai;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    /* process internal block */
    if (reqHandle->hashAlgo == kLTC_XcbcMacDPA)
    {
        algAai = kLTC_CfgAesXcbcMac;
    }
    else
    {
        algAai = kLTC_CfgAesCmac;
    }
    /* AS bits for the MD register for internal buffer are set by mdAs.
     * This is mainly to process the request in FINALIZE or INITIALIZE/FINALIZE
     */
    reqHandle->modeReg  = algAai | LTC_MD_AS(mdAs);
    reqHandle->dataSize = reqHandle->blksz; /* zero also possible. */
    ltc_one_block(base, reqHandle, NULL, (uint8_t *)(&reqHandle->realOutData));
    return kStatus_Success;
}

static status_t ltc_save_context_cmac(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&op->CTX[0], (const void *)(uintptr_t)&base->CTX[0], 64, r32);

    /* for XCBC-MAC get derived key from key registers */
    if (reqHandle->hashAlgo == kLTC_XcbcMacDPA)
    {
        /* copy to interleaved locations in key pools */
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy_wordsInterleaved(op->hwDecryptKey0, (void *)(uintptr_t)base->KEY, 32, r32);
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy_wordsInterleaved(op->hwDecryptKey1, (void *)(uintptr_t)base->KEY, 32, r32);
    }

    return kStatus_Success;
}

static status_t ltc_load_context_cmac(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;

    /* in init state, clear context */
    if (kLTC_CmacInitDPA == reqHandle->state)
    {
        base->COM = LTC_COM_AES_MASK;
        /* basic LTC configuration */
        base->CW = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CCR_MASK | LTC_CW_CICV_MASK /*| LTC_CW_CKR_MASK */ |
                   LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
        base->STA = LTC_STA_DI_MASK;
        base->CTL = LTC_CTL_COS_MASK | LTC_CTL_CIS_MASK | LTC_CTL_KOS_MASK | LTC_CTL_KIS_MASK | LTC_CTL_OFS_MASK |
                    LTC_CTL_IFS_MASK;
    }
    else
    {
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->CTX[0], 64, r32);
    }
    return kStatus_Success;
}

/*!
 * brief Initialize CMAC context
 *
 * This function initialize the CMAC.
 * Key shall be supplied because the underlaying algoritm is AES XCBC-MAC or AES CMAC.
 *
 * For XCBC-MAC, the key length must be 16. For CMAC, the key length can be
 * the AES key lengths supported by AES engine.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param algo Underlaying algorithm to use for hash computation.
 * param key Input key (NULL if underlaying algorithm is SHA)
 * param keySize Size of input key in bytes
 * return Status of initialization
 */
status_t LTC_CMAC_InitDPA(
    LTC_Type *base, ltc_dpa_handle_t *handle, ltc_dpa_hash_algo_t algo, const uint8_t *key, size_t keySize)
{
    status_t status;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    status = ltc_cmac_check_input_args(base, handle, algo);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = LTC_AES_SetKeyDPA(base, handle, key, keySize);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* set algorithm in context struct for later use */
    reqHandle->hashAlgo = algo;
    reqHandle->blksz    = 0u;
    reqHandle->state    = kLTC_CmacInitDPA;

    reqHandle->rOp.ltc_save_context = &ltc_save_context_cmac;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_cmac;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_cmac;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_cmac;
    reqHandle->rOp.operationOutData = NULL;
    reqHandle->dOp.operationOutData = NULL;
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif

    return status;
}

/*!
 * brief Add data to current CMAC
 *
 * Add data to current CMAC. This can be called repeatedly with an arbitrary amount of data to be
 * hashed.
 *
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param message Input data
 * param messageSize Size of input data in bytes
 * return Status of the hash update operation
 */
status_t LTC_CMAC_UpdateDPA(LTC_Type *base, ltc_dpa_handle_t *handle, const uint8_t *message, size_t messageSize)
{
    bool isUpdateState;
    status_t status;
    ltc_md_as_t mdAs; /* AS bits for the internal buffer. Set to INITIALIZE for the first processing, UPDATE then. */
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    if (0 == messageSize)
    {
        return kStatus_Success;
    }

    status = ltc_cmac_check_context(handle, message);
    if (kStatus_Success != status)
    {
        return status;
    }

    /* ctxInternal->fullMessageSize += messageSize; */
    reqHandle->dataSize = OPERATION_DATA_SIZE;

    /* if we are still less than 16 bytes, keep only in context */
    if ((reqHandle->blksz + messageSize) <= reqHandle->dataSize)
    {
        ltc_memcpy((uint8_t *)(&reqHandle->realOutData) + reqHandle->blksz, message, messageSize);
        reqHandle->blksz += messageSize;
        return status;
    }
    else
    {
        isUpdateState = reqHandle->state == kLTC_CmacUpdateDPA;
        if (!isUpdateState)
        {
            /* start NEW hash */
            /* ltc_cmac_engine_init(base, handle); */
            mdAs = kLTC_CfgAsInitialize;
            /*reqHandle->state = kLTC_CmacUpdateDPA;*/
        }
        else
        {
            mdAs = kLTC_CfgAsUpdate;
        }
    }

    /* process message data. Internal block is processed with mdAs set for MD register AS bits */
    status = ltc_cmac_process_message_data(base, handle, message, messageSize, mdAs);
    return status;
}

/*!
 * brief Finalize hashing
 *
 * Outputs the final hash and erases the context.
 *
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param[out] output Output hash data
 * param[out] outputSize Output parameter storing the size of the output hash in bytes
 * return Status of the hash finish operation
 */
status_t LTC_CMAC_FinishDPA(LTC_Type *base, ltc_dpa_handle_t *handle, uint8_t *output, size_t *outputSize)
{
    size_t algOutSize;
    status_t status;
    ltc_md_as_t mdAs; /* AS bits for the internal buffer. Set to INITIALIZE/FINALIZE for the first processing,
                             FINALIZE otherwise. */
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    status = ltc_cmac_check_context(handle, output);
    if (kStatus_Success != status)
    {
        return status;
    }

    if (reqHandle->state == kLTC_CmacInitDPA)
    {
        /* ltc_cmac_engine_init(base, handle); */
        mdAs = kLTC_CfgAsInitializeFinalize;
    }
    else
    {
        mdAs = kLTC_CfgAsFinalize;
    }
    algOutSize = 16u;

    /* flush message last incomplete block, if there is any, and add padding bits */
    status = ltc_cmac_finalize(base, handle, mdAs);

    if (outputSize)
    {
        if (algOutSize < *outputSize)
        {
            *outputSize = algOutSize;
        }
        else
        {
            algOutSize = *outputSize;
        }
    }

    ltc_memcpy(&output[0], &reqHandle->rOp.CTX[0], algOutSize);
    return status;
}

/*!
 * brief Create CMAC on given data
 *
 * Perform the full keyed CMAC in one function call.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param algo Block cipher algorithm to use for CMAC creation
 * param input Input data
 * param inputSize Size of input data in bytes
 * param key Input key
 * param keySize Size of input key in bytes
 * param[out] output Output hash data
 * param[out] outputSize Output parameter storing the size of the output hash in bytes
 * return Status of the one call hash operation.
 */
status_t LTC_CMAC_DPA(LTC_Type *base,
                      ltc_dpa_handle_t *handle,
                      ltc_dpa_hash_algo_t algo,
                      const uint8_t *input,
                      size_t inputSize,
                      const uint8_t *key,
                      size_t keySize,
                      uint8_t *output,
                      size_t *outputSize)
{
    status_t status;

    status = LTC_CMAC_InitDPA(base, handle, algo, key, keySize);
    if (status != kStatus_Success)
    {
        return status;
    }
    status = LTC_CMAC_UpdateDPA(base, handle, input, inputSize);
    if (status != kStatus_Success)
    {
        return status;
    }
    status = LTC_CMAC_FinishDPA(base, handle, output, outputSize);
    return status;
}

static status_t ltc_aes_ccm_check_input_args(LTC_Type *base,
                                             ltc_dpa_req_handle_t *reqHandle,
                                             const uint8_t *src,
                                             const uint8_t *iv,
                                             uint8_t *dst,
                                             size_t ivSize,
                                             size_t aadSize,
                                             size_t tagSize)
{
    status_t status;

    if (!base)
    {
        return kStatus_InvalidArgument;
    }

    /* Check handle has been initialized */
    status = ltc_dpa_check_handle(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Check the key is valid */
    status = ltc_aes_check_key_valid(reqHandle);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* tag can be NULL to skip tag processing */
    if ((!src) || (!iv) || (!dst))
    {
        return kStatus_InvalidArgument;
    }

    /* size of Nonce (ivSize) must be element of 7,8,9,10,11,12,13 */
    if ((ivSize < 7u) || (ivSize > 13u))
    {
        return kStatus_InvalidArgument;
    }
    /* octet length of MAC (tagSize) must be element of 4,6,8,10,12,14,16 for tag processing or zero to skip tag
     * processing */
    if (((tagSize > 0) && (tagSize < 4u)) || (tagSize > 16u) || (tagSize & 1u))
    {
        return kStatus_InvalidArgument;
    }

    /* LTC does not support more AAD than this */
    if (aadSize >= 65280u)
    {
        return kStatus_InvalidArgument;
    }
    return kStatus_Success;
}

static void ltc_aes_ccm_context_init(
    uint32_t inputSize, const uint8_t *iv, uint32_t ivSize, uint32_t aadSize, uint32_t tagSize, void *b0, void *ctr0)
{
    ltc_xcm_block_t blk;
    ltc_xcm_block_t blkZero = {{0x0u, 0x0u, 0x0u, 0x0u}};

    int q; /* octet length of binary representation of the octet length of the payload. computed as (15 - n), where n is
              length of nonce(=ivSize) */
    uint8_t flags; /* flags field in B0 and CTR0 */

    /* compute B0 */
    ltc_memcpy(&blk, &blkZero, sizeof(blk));
    /* tagSize - size of output MAC */
    q     = 15 - ivSize;
    flags = (uint8_t)(8 * ((tagSize - 2) / 2) + q - 1); /* 8*M' + L' */
    if (aadSize)
    {
        flags |= 0x40; /* Adata */
    }
    blk.b[0] = flags;                  /* flags field */
    blk.w[3] = swap_bytes(inputSize);  /* message size, most significant byte first */
    ltc_memcpy(&blk.b[1], iv, ivSize); /* nonce field */

    /* Write B0 data to the context register.
     */
    ltc_memcpy(b0, &blk.b[0], 16);

    /* Write CTR0 to the context register.
     */
    ltc_memcpy(&blk, &blkZero, sizeof(blk)); /* ctr(0) field = zero */
    blk.b[0] = q - 1;                        /* flags field */
    ltc_memcpy(&blk.b[1], iv, ivSize);       /* nonce field */
    ltc_memcpy(ctr0, &blk.b[0], 16);
}

static status_t ltc_aes_ccm_do_aad(LTC_Type *base,
                                   ltc_dpa_req_handle_t *reqHandle,
                                   ltc_dpa_operation_data_t *actOperation,
                                   ltc_aes_encryption_decryption_mode_t encryptMode,
                                   uint32_t inputSize,
                                   const uint8_t *aad,
                                   uint32_t aadSize,
                                   uint32_t runToCompletionCount)
{
    ltc_xcm_block_t blk = {{0x0u, 0x0u, 0x0u, 0x0u}};
    uint32_t swapped; /* holds byte swap of uint32_t */
    status_t retval;
    uint32_t md;

    md = kLTC_CfgAesCcm;
    if (encryptMode == kAES_ModeEncrypt)
    {
        md |= LTC_MD_ENC_MASK;
    }
    base->MD = md | LTC_MD_AS(kLTC_CfgAsInitialize);

    if (aadSize)
    {
        bool aadSingleSession;

        uint32_t sz      = 0;
        aadSingleSession = (((aadSize + 2u) + 15u) & 0xfffffff0u) <= LTC_DPA_FIFO_SIZE;

        /* limit by CCM spec: 2^16 - 2^8 = 65280 */

        /* encoding is two octets, msbyte first */
        swapped = swap_bytes(aadSize);
        ltc_memcpy(&blk.b[0], ((uint8_t *)&swapped) + sizeof(uint16_t), sizeof(uint16_t));

        sz = aadSize > 14u ? 14u : aadSize; /* limit aad to the end of 16 bytes blk */
        ltc_memcpy(&blk.b[2], aad, sz);     /* fill B1 with aad */

        if (aadSingleSession)
        {
            base->AADSZ = LTC_AADSZ_AL(1) | ((aadSize + 2U) & LTC_DS_DS_MASK);
            /* move first AAD block (16 bytes block B1) to FIFO */
            ltc_move_block_to_ififo(base, &blk, 16u);
        }
        else
        {
            base->AADSZ = LTC_AADSZ_AL(1) | (16U);
            /* move first AAD block (16 bytes block B1) to FIFO */
            ltc_move_block_to_ififo(base, &blk, 16u);
        }

        /* track consumed AAD. sz bytes have been moved to fifo. */
        aadSize -= sz;
        aad += sz;

        if (aadSingleSession)
        {
            /* move remaining AAD to FIFO, then return, to continue with MDATA */
            ltc_move_to_ififo(base, aad, aadSize);
            retval = ltc_wait_or_reset(base, runToCompletionCount);
            if (kStatus_Success != retval)
            {
                return retval;
            }
            base->CW = LTC_CW_CIF_MASK;
        }
        else if (aadSize == 0u)
        {
            retval = ltc_wait_or_reset(base, runToCompletionCount);
            if (kStatus_Success != retval)
            {
                return retval;
            }
            base->CW = LTC_CW_CIF_MASK;
        }
        else
        {
            while (aadSize)
            {
                retval = ltc_wait_or_reset(base, runToCompletionCount);
                if (kStatus_Success != retval)
                {
                    return retval;
                }
                base->CW = LTC_CW_CIF_MASK;

                /* change to AS Update */
                base->MD = md | LTC_MD_AS(kLTC_CfgAsUpdate);

                sz = LTC_DPA_FIFO_SIZE;
                if (aadSize < sz)
                {
                    base->AADSZ = LTC_AADSZ_AL(1) | (aadSize & LTC_DS_DS_MASK);
                    ltc_move_to_ififo(base, aad, aadSize);
                    aadSize = 0;
                    retval  = ltc_wait_or_reset(base, runToCompletionCount);
                    if (kStatus_Success != retval)
                    {
                        return retval;
                    }
                    base->CW = LTC_CW_CIF_MASK;
                }
                else
                {
                    base->AADSZ = LTC_AADSZ_AL(1) | (sz & LTC_DS_DS_MASK);
                    ltc_move_to_ififo(base, aad, sz);
                    aadSize -= sz;
                    aad += sz;
                }
            } /* end while */
        }     /* end else */
    }         /* end if */
    else
    {
        base->AADSZ = LTC_AADSZ_AL(1);
        retval      = ltc_wait_or_reset(base, runToCompletionCount);
        if (kStatus_Success != retval)
        {
            return retval;
        }
        base->CW = LTC_CW_CIF_MASK;
    }
    return kStatus_Success;
}

static status_t ltc_save_context_ccm(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&op->CTX[0], (const void *)(uintptr_t)&base->CTX[0], 64, r32);
    return kStatus_Success;
}

static status_t ltc_load_context_ccm(LTC_Type *base, ltc_dpa_req_handle_t *reqHandle, ltc_dpa_operation_data_t *op)
{
    uint32_t r32;
    status_t status;

    /* in init state, compute CTR0 and B0 for context */
    if (kLTC_CmacInitDPA == reqHandle->state)
    {
        base->COM = LTC_COM_AES_MASK;
        /* basic LTC configuration */
        base->CW = LTC_CW_CIF_MASK | LTC_CW_COF_MASK | LTC_CW_CCR_MASK | LTC_CW_CICV_MASK /*| LTC_CW_CKR_MASK */ |
                   LTC_CW_CDS_MASK | LTC_CW_CM_MASK;
        base->STA = LTC_STA_DI_MASK;
        base->CTL = LTC_CTL_COS_MASK | LTC_CTL_CIS_MASK | LTC_CTL_KOS_MASK | LTC_CTL_KIS_MASK | LTC_CTL_OFS_MASK |
                    LTC_CTL_IFS_MASK;

        /* B0 and CTR0 */
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->initCTX[0], 32, r32);
        status = ltc_aes_ccm_do_aad(base, reqHandle, op, reqHandle->xcm.encryptMode, reqHandle->xcm.inputSize,
                                    reqHandle->xcm.aad, reqHandle->xcm.aadSize, 0);
        if (kStatus_Success != status)
        {
            return status;
        }

        if (reqHandle->xcm.inputSize == 0)
        {
            return kStatus_LTC_CcmNoMDATA;
        }
    }
    else
    {
        r32 = ltc_dpa_prng_get_random_word(reqHandle);
        secureCopy((void *)(uintptr_t)&base->CTX[0], &op->CTX[0], 64, r32);
    }
    return kStatus_Success;
}

static status_t ltc_aes_ccm_do_data(LTC_Type *base,
                                    ltc_dpa_handle_t *handle,
                                    ltc_aes_encryption_decryption_mode_t encryptMode,
                                    const uint8_t *input,
                                    uint8_t *output,
                                    size_t size,
                                    size_t aadSize)
{
    uint32_t md;
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    md = kLTC_CfgAesCcm;
    if (encryptMode == kAES_ModeEncrypt)
    {
        md |= LTC_MD_ENC_MASK;
    }

    reqHandle->modeReg = md | LTC_MD_AS(kLTC_CfgAsUpdate);

    if (!size)
    {
        ltc_one_block(base, reqHandle, output, input);
    }
    else
    {
        /* Split the size into full 16-byte chunks and last incomplete block */
        uint32_t lastSize = 0U;
        if (size <= 16U)
        {
            lastSize = size;
            size     = 0U;
        }
        else
        {
            /* Process all 16-byte data chunks. */
            lastSize = size % 16u;
            if (lastSize == 0U)
            {
                lastSize = 16U;
                size -= 16U;
            }
            else
            {
                size -= lastSize; /* size will be rounded down to 16 byte boundary. remaining bytes in lastSize */
            }
        }

        uint32_t dataSize;
        while (size >= 16u)
        {
            if (size >= OPERATION_DATA_SIZE)
            {
                dataSize = OPERATION_DATA_SIZE;
            }
            else
            {
                dataSize = size;
            }

            reqHandle->dataSize = dataSize;
            ltc_one_block(base, reqHandle, output, input);
            output += dataSize;
            input += dataSize;
            size -= dataSize;
        }

        if (lastSize)
        {
            reqHandle->modeReg  = md | LTC_MD_AS(kLTC_CfgAsFinalize);
            reqHandle->dataSize = lastSize;
            ltc_one_block(base, reqHandle, output, input);
        }
    }

    return kStatus_Success;
}

static status_t ltc_aes_ccm_process(LTC_Type *base,
                                    ltc_dpa_handle_t *handle,
                                    ltc_aes_encryption_decryption_mode_t encryptMode,
                                    const uint8_t *src,
                                    size_t inputSize,
                                    const uint8_t *iv,
                                    size_t ivSize,
                                    const uint8_t *aad,
                                    size_t aadSize,
                                    uint8_t *dst,
                                    uint8_t *tag,
                                    size_t tagSize)
{
    status_t status; /* return value */
    uint8_t blkTag[16] = {0};
    ltc_dpa_req_handle_t *reqHandle;

    reqHandle = (ltc_dpa_req_handle_t *)(uintptr_t)&handle->req;

    status = ltc_aes_ccm_check_input_args(base, reqHandle, src, iv, dst, ivSize, aadSize, tagSize);
    /* API input validation */
    /* Check the key is valid */
    if (kStatus_Success != status)
    {
        return status;
    }

    reqHandle->state                = kLTC_CmacInitDPA;
    reqHandle->rOp.ltc_save_context = &ltc_save_context_ccm;
    reqHandle->rOp.ltc_load_context = &ltc_load_context_ccm;
    reqHandle->dOp.ltc_save_context = &ltc_save_context_ccm;
    reqHandle->dOp.ltc_load_context = &ltc_load_context_ccm;
    reqHandle->rOp.operationOutData = reqHandle->realOutData;
    reqHandle->dOp.operationOutData = reqHandle->dummyOutData;
    reqHandle->xcm.iv               = iv;
    reqHandle->xcm.aad              = aad;
    reqHandle->xcm.ivSize           = ivSize;
    reqHandle->xcm.aadSize          = aadSize;
    reqHandle->xcm.inputSize        = inputSize;
    reqHandle->xcm.encryptMode      = encryptMode;
#if defined(FSL_LTC_DPA_HAVE_GATE_OFF) && (FSL_LTC_DPA_HAVE_GATE_OFF > 0)
    reqHandle->oneBlockWords    = 4u;
    reqHandle->gateOffRepeatMax = FSL_LTC_DPA_AES_MAX_GATE_OFF_REPEAT;
#endif
#if defined(FSL_LTC_DPA_RELEASE) && (FSL_LTC_DPA_RELEASE > 0)
    reqHandle->Nd = FSL_LTC_DPA_ACT_ND_AES;
#endif

    /* prepare common CTR0 and B0 */
    ltc_aes_ccm_context_init(inputSize, iv, ivSize, aadSize, tagSize, &reqHandle->dOp.initCTX[0],
                             &reqHandle->dOp.initCTX[4]);
    uint32_t r32;
    r32 = ltc_dpa_prng_get_random_word(reqHandle);
    secureCopy(&reqHandle->rOp.initCTX[0], &reqHandle->dOp.initCTX[0], 32, r32);

    status = ltc_aes_ccm_do_data(base, handle, encryptMode, src, dst, inputSize, aadSize);
    if (kStatus_Success != status)
    {
        return status;
    }

    if (tag && tagSize)
    {
        if (encryptMode == kAES_ModeEncrypt)
        {
            ltc_memcpy(blkTag, (const void *)(uintptr_t)&reqHandle->rOp.CTX[kLTC_ContextIndexCcmTag], sizeof(blkTag));
            ltc_memcpy(tag, blkTag, tagSize);
        }
        else
        {
            ltc_load_context_ccm(base, reqHandle, &reqHandle->rOp);
            status = ltc_aes_received_mac_compare(base, tag, tagSize, kLTC_CfgAesCcm);
        }
    }

    return status;
}

/*!
 * brief Encrypts AES and tags using CCM block mode.
 *
 * Encrypts AES and optionally tags using CCM block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param plaintext Input plain text to encrypt
 * param[out] ciphertext Output cipher text.
 * param size Size of input and output data in bytes. Zero means authentication only.
 * param iv Nonce
 * param ivSize Length of the Nonce in bytes. Must be 7, 8, 9, 10, 11, 12, or 13.
 * param aad Input additional authentication data. Can be NULL if aadSize is zero.
 * param aadSize Input size in bytes of AAD. Zero means data mode only (authentication skipped).
 * param[out] tag Generated output tag. Set to NULL to skip tag processing.
 * param tagSize Input size of the tag to generate, in bytes. Must be 4, 6, 8, 10, 12, 14, or 16.
 * return Status from encrypt operation
 */
status_t LTC_AES_EncryptTagCcmDPA(LTC_Type *base,
                                  ltc_dpa_handle_t *handle,
                                  const uint8_t *plaintext,
                                  uint8_t *ciphertext,
                                  size_t size,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  const uint8_t *aad,
                                  size_t aadSize,
                                  uint8_t *tag,
                                  size_t tagSize)
{
    status_t status;
    status = ltc_aes_ccm_process(base, handle, kAES_ModeEncrypt, plaintext, size, iv, ivSize, aad, aadSize, ciphertext,
                                 tag, tagSize);
    return status;
}

/*!
 * brief Decrypts AES and authenticates using CCM block mode.
 *
 * Decrypts AES and optionally authenticates using CCM block mode.
 *
 * param base LTC peripheral base address
 * param handle pointer to ltc_dpa_handle_t structure which stores the transaction state.
 * param ciphertext Input cipher text to decrypt
 * param[out] plaintext Output plain text.
 * param size Size of input and output data in bytes. Zero means authentication only.
 * param iv Nonce
 * param ivSize Length of the Nonce in bytes. Must be 7, 8, 9, 10, 11, 12, or 13.
 * param aad Input additional authentication data. Can be NULL if aadSize is zero.
 * param aadSize Input size in bytes of AAD. Zero means data mode only (authentication skipped).
 * param tag Received tag. Set to NULL to skip tag processing.
 * param tagSize Input size of the received tag to compare with the computed tag, in bytes. Must be 4, 6, 8, 10, 12,
 * 14, or 16.
 * return Status from decrypt operation
 */
status_t LTC_AES_DecryptTagCcmDPA(LTC_Type *base,
                                  ltc_dpa_handle_t *handle,
                                  const uint8_t *ciphertext,
                                  uint8_t *plaintext,
                                  size_t size,
                                  const uint8_t *iv,
                                  size_t ivSize,
                                  const uint8_t *aad,
                                  size_t aadSize,
                                  const uint8_t *tag,
                                  size_t tagSize)
{
    uint8_t temp_tag[16] = {0}; /* max. octet length of MAC (tag) is 16 */
    uint8_t *tag_ptr;
    status_t status;

    tag_ptr = NULL;
    if (tag)
    {
        ltc_memcpy(temp_tag, tag, tagSize);
        tag_ptr = &temp_tag[0];
    }

    status = ltc_aes_ccm_process(base, handle, kAES_ModeDecrypt, ciphertext, size, iv, ivSize, aad, aadSize, plaintext,
                                 tag_ptr, tagSize);
    return status;
}
