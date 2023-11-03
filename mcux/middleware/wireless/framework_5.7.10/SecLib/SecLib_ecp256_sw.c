/*! *********************************************************************************
* Copyright 2022 NXP
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

#include "SecLib_ecp256.h"
#include "FunctionLib.h"

#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))
extern const uint32_t gSecEcP256_MultiplicationBufferSize_c;
#include "MemManager.h"
#endif

/*! Callback used to offload Security steps onto application message queue. When it is not set the
 * multiplication is done using SecLib means */
secLibCallback_t pfSecLibMultCallback = NULL;

/*! *********************************************************************************
* \brief  This function performs initialization of the callback used to offload
* elliptic curve multiplication.
*
* \param[in]  pfCallback Pointer to the function used to handle multiplication.
*
********************************************************************************** */
void SecLib_SetExternalMultiplicationCb
(
    secLibCallback_t pfCallback
)
{
    pfSecLibMultCallback = pfCallback;
}

/*! *********************************************************************************
* \brief  This function performs calls the multiplication Callback.
*
* \param[in]  pMsg Pointer to the data used in multiplication.
*
********************************************************************************** */
void SecLib_ExecMultiplicationCb
(
    computeDhKeyParam_t *pMsg
)
{
    if (pfSecLibMultCallback != NULL)
    {
        pfSecLibMultCallback(pMsg);
    }
}


#if mDbgRevertKeys_d
static ecdhPublicKey_t mReversedPublicKey;
static ecdhPrivateKey_t mReversedPrivateKey;
#endif /* mDbgRevertKeys_d */

/************************************************************************************
* \brief Handle one step of ECDH multiplication depending on the number of steps at
*        a time according to gSecLibEcStepsAtATime. After the last step is completed
*        the function returns TRUE and the upper layer is responsible for clearing
*        pData.
*
* \param[in]  pData Pointer to the structure holding information about the
*                   multiplication
*
* \return TRUE if the multiplication is completed
*         FALSE when the function needs to be called again
*
************************************************************************************/
bool_t SecLib_HandleMultiplyStep
(
    computeDhKeyParam_t *pData
)
{
    bool_t result = FALSE;

#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))
    uint8_t steps = ((255U + 1U) / gSecLibEcStepsAtATime);

    /* Intermediate step */
    if (pData->procStep < steps)
    {
        /* Compute step */
        Ecdh_ComputeJacobiChunk(255U - (pData->procStep * gSecLibEcStepsAtATime), gSecLibEcStepsAtATime, pData);
        /* Go to the next step */
        pData->procStep++;
        result = FALSE;
    }
    /* Final step was completed -> resume SecLib procedure */
    else
    {
        Ecdh_JacobiCompleteMult(pData);

#if mDbgRevertKeys_d
        {
            FLib_MemCpyReverseOrder
            (
                mReversedEcdhKey.components_8bit.x,
                pData->outX,
                sizeof(mReversedEcdhKey.components_8bit.x)
            );
            FLib_MemCpyReverseOrder
            (
                mReversedEcdhKey.components_8bit.y,
                pData->outY,
                sizeof(mReversedEcdhKey.components_8bit.y)
            );
            FLib_MemCpyReverseOrder
            (
                pData->outX,
                mReversedEcdhKey.components_8bit.x,
                sizeof(pData->outX)
            );
            FLib_MemCpyReverseOrder
            (
                pData->outY,
                mReversedEcdhKey.components_8bit.y,
                sizeof(pData->outY)
            );
        }
#endif /* mDbgRevertKeys_d */

        result = TRUE;
    }
#else
    result = TRUE;
#endif
    return result;

}
#ifdef NCCL_DEBUG
#include "fsl_debug_console.h"
#include "dbg_logging.h"

void ECP256_PointDisplay(const char * str, const uint8_t *point)
{
    const uint8_t *p = &point[0];
    PRINTF("%s\r\n", str);
    if (*p == 0x04)
    {
        PRINTF("Uncompressed Format\n\n");
        p++;
    }
    dump_octet_string("Point X", p,    32);
    dump_octet_string("Point Y", p+32, 32);
    PRINTF("\r\n");
}
#endif


secResultType_t ECDH_P256_GenerateKeys
(
    ecdhPublicKey_t*   pOutPublicKey,
    ecdhPrivateKey_t*   pOutPrivateKey
)
{
    secResultType_t result;

#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))
    void* pMultiplicationBuffer = MEM_BufferAlloc(gSecEcP256_MultiplicationBufferSize_c);
    if (NULL == pMultiplicationBuffer)
    {
        result = gSecAllocError_c;
    }
    else
    {
#if mDbgRevertKeys_d
        if (gSecEcp256Success_c != ECP256_GenerateNewKeys(&mReversedPublicKey, &mReversedPrivateKey, pMultiplicationBuffer))
#else /* !mDbgRevertKeys_d */
        if (gSecEcp256Success_c != ECP256_GenerateNewKeys(pOutPublicKey, pOutPrivateKey, pMultiplicationBuffer))
#endif /* mDbgRevertKeys_d */
        {
            result = gSecError_c;
        }
        else
        {
            result = gSecSuccess_c;
#if mDbgRevertKeys_d
            FLib_MemCpyReverseOrder
            (
                pOutPublicKey->components_8bit.x,
                mReversedPublicKey.components_8bit.x,
                32
            );
            FLib_MemCpyReverseOrder
            (
                pOutPublicKey->components_8bit.y,
                mReversedPublicKey.components_8bit.y,
                32
            );
            FLib_MemCpyReverseOrder
            (
                pOutPrivateKey->raw_8bit,
                mReversedPrivateKey.raw_8bit,
                32
            );
#endif /* mDbgRevertKeys_d */
        }

        MEM_BufferFree(pMultiplicationBuffer);
    }
#else
    ecp256KeyPair_t       KeyPair;
    if (gSecEcp256Success_c != ECP256_GenerateKeyPair(&KeyPair.public_key, &KeyPair.private_key, NULL))
    {
        result = gSecError_c;
    }
    else
    {
        result = gSecSuccess_c;
        /* The NCCL output is BE and BLE expected LE */
        ecp_p256_copy_and_change_endianess((uint8_t*)pOutPublicKey, (const uint8_t*)&KeyPair.public_key);
        ecp_coordinate_copy_and_change_endianess((uint8_t*)pOutPrivateKey, (const uint8_t*)&KeyPair.private_key);
    }
#endif

    return result;
}

#if mDbgRevertKeys_d
static ecdhDhKey_t mReversedEcdhKey;
#endif /* mDbgRevertKeys_d */

secResultType_t ECDH_P256_ComputeDhKey
(
    const ecdhPrivateKey_t*   pPrivateKey,
    const ecdhPublicKey_t*    pPeerPublicKey,
    ecdhDhKey_t*        pOutDhKey
)
{
    secResultType_t result;
    secEcdhStatus_t ecdhStatus;

#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))

    void* pMultiplicationBuffer = MEM_BufferAlloc(gSecEcP256_MultiplicationBufferSize_c);
    if (NULL == pMultiplicationBuffer)
    {
        result = gSecAllocError_c;
    }
    else
    {
#if mDbgRevertKeys_d
        FLib_MemCpyReverseOrder
        (
            mReversedPublicKey.components_8bit.x,
            pPeerPublicKey->components_8bit.x,
            32
        );
        FLib_MemCpyReverseOrder
        (
            mReversedPublicKey.components_8bit.y,
            pPeerPublicKey->components_8bit.y,
            32
        );
        FLib_MemCpyReverseOrder
        (
            mReversedPrivateKey.raw_8bit,
            pPrivateKey->raw_8bit,
            32
        );
#endif /* mDbgRevertKeys_d */

#if mDbgRevertKeys_d
        ecdhStatus = Ecdh_ComputeDhKey(&mReversedPrivateKey, &mReversedPublicKey, &mReversedEcdhKey, pMultiplicationBuffer);
#else /* !mDbgRevertKeys_d */
        ecdhStatus = Ecdh_ComputeDhKey(pPrivateKey, pPeerPublicKey, pOutDhKey, pMultiplicationBuffer);
#endif /* mDbgRevertKeys_d */
        if (gSecEcdhInvalidPublicKey_c == ecdhStatus)
        {
            result = gSecInvalidPublicKey_c;
        }
        else if (gSecEcdhSuccess_c != ecdhStatus)
        {
            result = gSecError_c;
        }
        else
        {
            result = gSecSuccess_c;
#if mDbgRevertKeys_d
            FLib_MemCpyReverseOrder
            (
                pOutDhKey->components_8bit.x,
                mReversedEcdhKey.components_8bit.x,
                32
            );
            FLib_MemCpyReverseOrder
            (
                pOutDhKey->components_8bit.y,
                mReversedEcdhKey.components_8bit.y,
                32
            );
#endif /* mDbgRevertKeys_d */
        }

        MEM_BufferFree(pMultiplicationBuffer);
    }
#else
    ecp256Point_t peer_public_key;
    ecp256Coordinate_t self_private_key;
    ecp256Point_t dh_secret;
    ecp_p256_copy_and_change_endianess(&peer_public_key.raw[0], (const uint8_t*)pPeerPublicKey);
    ecp_coordinate_copy_and_change_endianess(&self_private_key.raw_8bit[0], (const uint8_t*)pPrivateKey);
    ecdhStatus = Ecdh_ComputeDhKey(&self_private_key, &peer_public_key, &dh_secret, NULL);
    if (ecdhStatus == gSecEcdhSuccess_c)
    {
        ecp_p256_copy_and_change_endianess(&pOutDhKey->raw[0], (const uint8_t*)&dh_secret);
        result = gSecSuccess_c;
    }
    else
    {
        result = gSecError_c;
    }
    #endif
    return result;
}

/************************************************************************************
* \brief Generates a new ECDH P256 Private/Public key pair. This function starts the
*        ECDH generate procedure. The pDhKeyData must be allocated and kept
*        allocated for the time of the computation procedure.
*        When the result is gSecResultPending_c the memory should be kept until the
*        last step.
*        In any other result messages the data shall be cleared after this call.
*
* \param[in]  pDhKeyData Pointer to the structure holding information about the
*                        multiplication
*
* \return gSecSuccess_c, gSecResultPending_c or error
*
************************************************************************************/
secResultType_t ECDH_P256_GenerateKeysSeg
(
    computeDhKeyParam_t *pDhKeyData
)
{
    secResultType_t result = gSecError_c;
    do {
        if (NULL == pDhKeyData)
        {
            break;
        }
    /* The callback is NULL when there is no async ECDH */
#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))
        if (pfSecLibMultCallback == NULL)
        {
            result = ECDH_P256_GenerateKeys((ecp256Point_t*)&pDhKeyData->outPoint, &pDhKeyData->privateKey);
        }
        else
        {
            secEcp256Status_t st;

            /* Allocate a Multiplication context */
            pDhKeyData->pWorkBuffer = MEM_BufferAlloc(gSecEcP256_MultiplicationBufferSize_c);
            if (NULL == pDhKeyData->pWorkBuffer)
            {
                result = gSecAllocError_c;
                break;
            }
            st = Ecp256_GenerateKeysSeg(pDhKeyData);
            if (gSecEcp256Success_c != st)
            {
                SEC_DBG_LOG("Ecp256_GenerateKeysSeg error = %d", st);
                result = gSecError_c;
                break;
            }
            result = gSecResultPending_c;
        }
#else
        result = ECDH_P256_GenerateKeys((ecp256Point_t*)&pDhKeyData->outPoint, &pDhKeyData->privateKey);
#endif
    } while (false);

    return result;
}

/************************************************************************************
* \brief Computes the Diffie-Hellman Key for an ECDH P256 key pair. This function
*        starts the ECDH key pair generate procedure. The pDhKeyData must be
*        allocated and kept allocated for the time of the computation procedure.
*        When the result is gSecResultPending_c the memory should be kept until the
*        last step, when it can be safely freed.
*        In any other result messages the data shall be cleared after this call.
*
* \param[in]  pDhKeyData Pointer to the structure holding information about the
*                        multiplication
*
* \return gSecSuccess_c or error
*
************************************************************************************/
secResultType_t ECDH_P256_ComputeDhKeySeg
(
    computeDhKeyParam_t*        pDhKeyData
)
{
    secResultType_t result;

#if !(defined EC_P256_DSPEXT && (EC_P256_DSPEXT == 1))
    if (pfSecLibMultCallback == NULL)
    {
        result = ECDH_P256_ComputeDhKey(&pDhKeyData->privateKey,
                                        &pDhKeyData->peerPublicKey,
                                        &pDhKeyData->outPoint);
    }
    else
    {
        /* Segmented EC point multiply not working when the callback is not set */
        secEcdhStatus_t ecdhStatus;
        void* pMultiplicationBuffer = MEM_BufferAlloc(gSecEcP256_MultiplicationBufferSize_c);
        if (NULL == pMultiplicationBuffer)
        {
            result = gSecAllocError_c;
        }
        else
        {
#if mDbgRevertKeys_d
            FLib_MemCpyReverseOrder
            (
                mReversedPublicKey.components_8bit.x,
                pDhKeyData->peerPublicX,
                sizeof(mReversedPublicKey.components_8bit.x)
            );
            FLib_MemCpyReverseOrder
            (
                mReversedPublicKey.components_8bit.y,
                pDhKeyData->peerPublicY,
                sizeof(mReversedPublicKey.components_8bit.y)
            );
            FLib_MemCpyReverseOrder
            (
                mReversedPrivateKey.raw_8bit,
                pDhKeyData->privateKey,
                sizeof(mReversedPrivateKey.raw_8bit)
            );
#endif /* mDbgRevertKeys_d */

            pDhKeyData->pWorkBuffer = pMultiplicationBuffer;
#if mDbgRevertKeys_d
            FLib_MemCpy(pDhKeyData->peerPublicX, mReversedPublicKey.components_32bit.x, sizeof(pDhKeyData->peerPublicX));
            FLib_MemCpy(pDhKeyData->peerPublicY, mReversedPublicKey.components_32bit.y, sizeof(pDhKeyData->peerPublicY));
            FLib_MemCpy(pDhKeyData->privateKey, mReversedPrivateKey.raw_32bit, sizeof(pDhKeyData->privateKey));
#endif /* mDbgRevertKeys_d */
            ecdhStatus = Ecdh_ComputeDhKeySeg(pDhKeyData);
            SEC_DBG_LOG("Ecdh_ComputeDhKeySeg error = %d", ecdhStatus);

            if (gSecEcdhInvalidPublicKey_c == ecdhStatus)
            {
                result = gSecInvalidPublicKey_c;
            }
            else if (gSecEcdhSuccess_c != ecdhStatus)
            {
                result = gSecError_c;
            }
            else
            {
                result = gSecResultPending_c;
            }
        }
    }
#else
    result = ECDH_P256_ComputeDhKey(&pDhKeyData->privateKey,
                                            &pDhKeyData->peerPublicKey,
                                            &pDhKeyData->outPoint);
#endif
    return result;
}


