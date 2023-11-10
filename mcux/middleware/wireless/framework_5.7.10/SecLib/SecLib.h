/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2016-2022 NXP
* All rights reserved.
*
* \file
*
* This is the header file for the security module.
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#ifndef _SEC_LIB_H_
#define _SEC_LIB_H_


/*! *********************************************************************************
*************************************************************************************
* Include
*************************************************************************************
********************************************************************************** */
#include "EmbeddedTypes.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

//#define NCCL_DEBUG
#ifdef NCCL_DEBUG
#include "dbg_logging.h"
#endif

#ifndef gSecLibUseMutex_c
#define gSecLibUseMutex_c   TRUE
#endif

/* Must be defined as 1 if DMA are used simultaneously */
#ifndef gSecLibAESMethodSelectionDynHwSw_c
#define gSecLibAESMethodSelectionDynHwSw_c 0
#endif

/* Must be defined as 1 if switch mechanism between hardware
 * and software SHA256 has to be used. */
#ifndef gSecLibUseSha256Alt_d
#define gSecLibUseSha256Alt_d 0
#endif


/*! *********************************************************************************
*************************************************************************************
* Public macros
*************************************************************************************
********************************************************************************** */
/* AES 128 */
#define AES_128_KEY_BITS         128
#define AES_128_BLOCK_SIZE       16 /* [bytes] */

/* CCM */
#define gSecLib_CCM_Encrypt_c 0
#define gSecLib_CCM_Decrypt_c 1

/* Hashes */
#ifndef SHA1_HASH_SIZE
#define SHA1_HASH_SIZE     20 /* [bytes] */
#endif
#ifndef SHA1_BLOCK_SIZE
#define SHA1_BLOCK_SIZE    64 /* [bytes] */
#endif

#ifndef SHA256_HASH_SIZE
#define SHA256_HASH_SIZE   32 /* [bytes] */
#endif

#ifndef SHA256_BLOCK_SIZE
#define SHA256_BLOCK_SIZE  64 /* [bytes] */
#endif

#define gHmacIpad_c               0x36
#define gHmacOpad_c               0x5C

/*! Enable or disable SHA-1 functionality in the SecLib module. */
#ifndef gSecLibSha1Enable_d
#define gSecLibSha1Enable_d     1
#endif

/*! Enable or disable SHA-256 functionality in the SecLib module. */
#ifndef gSecLibSha256Enable_d
#define gSecLibSha256Enable_d   1
#endif

#ifndef AES_BLOCK_SIZE
#define AES_BLOCK_SIZE 16
#endif

#ifndef AESSW_BLK_SIZE
#define AESSW_BLK_SIZE 16
#endif


/*! *********************************************************************************
*************************************************************************************
* Public type definitions
*************************************************************************************
********************************************************************************** */
typedef enum
{
    gSecSuccess_c           = 0u,
    gSecAllocError_c        = 1u,
    gSecError_c             = 2u,
    gSecInvalidPublicKey_c  = 3u,
    gSecResultPending_c     = 4u
} secResultType_t;




/* Security block definition */
typedef union
{
    uint8_t    au8[AES_BLOCK_SIZE];
    uint32_t   au32[AES_BLOCK_SIZE / 4];
} tuAES_Block;

/* For backwards compatibility */
typedef tuAES_Block AESSW_Block_u;

typedef struct
{
    uint32_t u32register0;
    uint32_t u32register1;
    uint32_t u32register2;
    uint32_t u32register3;
} tsReg128;



/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*! *********************************************************************************
* \brief  This function performs initialization of the cryptographic HW acceleration.
*
********************************************************************************** */
void SecLib_Init (void);



/*! *********************************************************************************
* \brief  Process current AES operation described by the context.
*         It wraps ROM API and offers mutex protection and protection
*         against ISR interruption.
*
* \param[in]  pContext Software context that holds AES data (key, mode).
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
                               uint32_t  numBlocks);

/*! *********************************************************************************
* \brief  This function performs AES-128 encryption on a 16-byte block.
*
* \param[in]  pInput Pointer to the location of the 16-byte plain text block.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address aligned to 4 bytes!
*
********************************************************************************** */
void AES_128_Encrypt (const uint8_t*  pInput,
                      const uint8_t*  pKey,
                      uint8_t*  pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128 decryption on a 16-byte block.
*
* \param[in]  pInput Pointer to the location of the 16-byte plain text block.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the 16-byte ciphered output.
*
* \pre All Input/Output pointers must refer to a memory address aligned to 4 bytes!
*
********************************************************************************** */
void AES_128_Decrypt (const uint8_t*  pInput,
                      const uint8_t*  pKey,
                      uint8_t*  pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128-ECB encryption on a message block.
*         This function only accepts input lengths which are multiple
*         of 16 bytes (AES 128 block size).
*
* \param[in]  pInput Pointer to the location of the input message.
*
* \param[in]  inputLen Input message length in bytes.
*
* \param[in]  pKey Pointer to the location of the 128-bit key.
*
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_ECB_Encrypt (const uint8_t*  pInput,
                          uint32_t  inputLen,
                          const uint8_t*  pKey,
                          uint8_t*  pOutput);

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
void AES_128_ECB_Decrypt(const uint8_t *pInput,
                         uint32_t inputLen,
                         const uint8_t *pKey,
                         uint8_t *pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128-CBC encryption on a message block.
*         This function only accepts input lengths which are multiple
*         of 16 bytes (AES 128 block size).
*
* \param[in]  pInput Pointer to the location of the input message.
* \param[in]  inputLen Input message length in bytes.
* \param[in]  pInitVector Pointer to the location of the 128-bit initialization vector.
* \param[in]  pKey Pointer to the location of the 128-bit key.
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_CBC_Encrypt (const uint8_t*  pInput,
                          uint32_t  inputLen,
                          const uint8_t*  pInitVector,
                          const uint8_t*  pKey,
                          uint8_t*  pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128-CBC encryption on a message block after
*         padding it with 1 bit of 1 and 0 bits trail.
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
uint32_t AES_128_CBC_Encrypt_And_Pad (uint8_t*  pInput,
                                      uint32_t  inputLen,
                                      const uint8_t*  pInitVector,
                                      const uint8_t*  pKey,
                                      uint8_t*  pOutput);

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
* Return value: size of output buffer (after depadding the 0x80 0x00 ... padding sequence)
*
********************************************************************************** */
uint32_t AES_128_CBC_Decrypt_And_Depad (const uint8_t* pInput,
                                        uint32_t inputLen,
                                        const uint8_t* pInitVector,
                                        const uint8_t* pKey,
                                        uint8_t* pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128-CTR encryption on a message block.
*         This function only accepts input lengths which are multiple
*         of 16 bytes (AES 128 block size).
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
void AES_128_CTR (const uint8_t*  pInput,
                  uint32_t  inputLen,
                  uint8_t*  pCounter,
                  const uint8_t*  pKey,
                  uint8_t*  pOutput);


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
void AES_128_CMAC (const  uint8_t* pInput,
                   uint32_t inputLen,
                   const  uint8_t* pKey,
                   uint8_t* pOutput);

/*! *********************************************************************************
* \brief  This function performs AES-128-CMAC on a message block accepting input data
*         which is in LSB first format and computing the authentication code starting from the end of the data.
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
void AES_128_CMAC_LsbFirstInput (const uint8_t*   pInput,
                                 const uint32_t   inputLen,
                                 const uint8_t*   pKey,
                                 uint8_t*   pOutput);

/*! *********************************************************************************
* \brief  This function performs AES 128 CMAC Pseudo-Random Function (AES-CMAC-PRF-128),
*         according to rfc4615, on a message block.
*
* \details The AES-CMAC-PRF-128 algorithm behaves similar to the AES CMAC 128 algorithm
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
void AES_CMAC_PRF_128 (const uint8_t* pInput,
                       const uint32_t inputLen,
                       const uint8_t* pVarKey,
                       const uint32_t varKeyLen,
                       uint8_t* pOutput);

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
secResultType_t AES_128_EAX_Encrypt (uint8_t*   pInput,
                                     uint32_t   inputLen,
                                     uint8_t*   pNonce,
                                     uint32_t   nonceLen,
                                     uint8_t*   pHeader,
                                     uint8_t    headerLen,
                                     uint8_t*   pKey,
                                     uint8_t*   pOutput,
                                     uint8_t*   pTag);

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
secResultType_t AES_128_EAX_Decrypt (uint8_t*   pInput,
                                     uint32_t   inputLen,
                                     uint8_t*   pNonce,
                                     uint32_t   nonceLen,
                                     uint8_t*   pHeader,
                                     uint8_t    headerLen,
                                     uint8_t*   pKey,
                                     uint8_t*   pOutput,
                                     uint8_t*   pTag);

/*! *********************************************************************************
* \brief  This function performs AES-128-CCM on a message block.
*
* \param[in]  pInput       Pointer to the location of the input message (plaintext or cyphertext).
*
* \param[in]  inputLen     Length of the input plaintext in bytes when encrypting.
*                          Length of the input cyphertext without the MAC length when decrypting.
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
* \param[out]  pOutput     Pointer to the location to store the plaintext data when encrypting.
*                          Pointer to the location to store the cyphertext data when encrypting.
*
* \param[out]  pCbcMac     Pointer to the location to store the Message Authentication Code (MAC) when encrypting.
*                          Pointer to the location where the received MAC can be found when decrypting.
*
* \param[out]  macSize     The size of the MAC.
*
* \param[out]  flags       Select encrypt/decrypt operations (gSecLib_CCM_Encrypt_c, gSecLib_CCM_Decrypt_c)
*
********************************************************************************** */
uint8_t AES_128_CCM (const uint8_t*   pInput,
                     const uint16_t   inputLen,
                     const uint8_t*   pAuthData,
                     const uint16_t   authDataLen,
                     const uint8_t*   pNonce,
                     const uint8_t    nonceSize,
                     const uint8_t*   pKey,
                     uint8_t*   pOutput,
                     uint8_t*   pCbcMac,
                     uint8_t    macSize,
                     uint32_t   flags);

/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a SHA1 context structure
*
* \return    Address of the SHA1 context buffer
*            Deallocate using SHA1_FreeCtx()
*
********************************************************************************** */
void* SHA1_AllocCtx (void);

/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the SHA1 context structure
*
* \param [in]    pContext    Address of the SHA1 context buffer
*
********************************************************************************** */
void SHA1_FreeCtx (void* pContext);

/*! *********************************************************************************
* \brief  This function clones a SHA1 context.
*         Make sure the size of the allocated destination context buffer is appropriate.
*
* \param [in]    pDestCtx    Address of the destination SHA1 context
* \param [in]    pSourceCtx  Address of the source SHA1 context
*
********************************************************************************** */
void SHA1_CloneCtx (void* pDestCtx, void* pSourceCtx);

/*! *********************************************************************************
* \brief  This function initializes the SHA1 context data
*
* \param [in]    pContext    Pointer to the SHA1 context data
*                            Allocated using SHA1_AllocCtx()
*
********************************************************************************** */
void SHA1_Init (void* pContext);

/*! *********************************************************************************
* \brief  This function performs SHA1 on multiple bytes and updates the context data
*
* \param [in]    pContext    Pointer to the SHA1 context data
*                            Allocated using SHA1_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA1_HashUpdate (void*     pContext,
                      const uint8_t*  pData,
                      uint32_t  numBytes);

/*! *********************************************************************************
* \brief  This function finalizes the SHA1 hash computation and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA1 context data
*                               Allocated using SHA1_AllocCtx()
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA1_HashFinish (void*     pContext,
                      uint8_t*  pOutput);

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
void SHA1_Hash (const uint8_t*    pData,
                const uint32_t    numBytes,
                uint8_t*    pOutput);

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
void SHA256_SW_Init(void* pContext);

/*! *********************************************************************************
* \brief  Perform SW SHA256 on multiple bytes and updates the context data.
*
* \param [in]    pContext    Pointer to the SHA256 context data
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA256_SW_Update(void* pContext, const uint8_t* pData, uint32_t numBytes);

/*! *********************************************************************************
* \brief  Finalize the SW SHA256 hash computation and clear the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA256 context data
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA256_SW_Finish(void* pContext, uint8_t* pOutput);

/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a SHA256 context structure
*
* \return    Address of the SHA256 context buffer
*            Deallocate using SHA256_FreeCtx()
*
********************************************************************************** */
void* SHA256_AllocCtx (void);

/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the SHA256 context structure
*
* \param [in]    pContext    Address of the SHA256 context buffer
*
********************************************************************************** */
void SHA256_FreeCtx (void* pContext);

/*! *********************************************************************************
* \brief  This function clones a SHA256 context.
*         Make sure the size of the allocated destination context buffer is appropriate.
*
* \param [in]    pDestCtx    Address of the destination SHA256 context
* \param [in]    pSourceCtx  Address of the source SHA256 context
*
********************************************************************************** */
void SHA256_CloneCtx (void* pDestCtx, void* pSourceCtx);

/*! *********************************************************************************
* \brief  This function initializes the SHA256 context data.
*
* \param [in]    pContext    Pointer to the SHA256 context data
*                            Allocated using SHA256_AllocCtx()
*
********************************************************************************** */
void SHA256_Init (void* pContext);

/*! *********************************************************************************
* \brief  This function performs SHA256 on multiple bytes and updates the context data
*
* \param [in]    pContext    Pointer to the SHA256 context data
*                            Allocated using SHA256_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void SHA256_HashUpdate (void*       pContext,
                        const uint8_t*    pData,
                        uint32_t    numBytes);

/*! *********************************************************************************
* \brief  This function finalizes the SHA256 hash computation and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the SHA256 context data
*                               Allocated using SHA256_AllocCtx()
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void SHA256_HashFinish
(
    void*       pContext,
    uint8_t*    pOutput
);

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
void SHA256_Hash
(
    const uint8_t*  pData,
    const uint32_t  numBytes,
    uint8_t*  pOutput
);

/*! *********************************************************************************
* \brief  This function allocates a memory buffer for a HMAC SHA256 context structure
*
* \return    Address of the HMAC SHA256 context buffer
*            Deallocate using HMAC_SHA256_FreeCtx()
*
********************************************************************************** */
void* HMAC_SHA256_AllocCtx
(
    void
);

/*! *********************************************************************************
* \brief  This function deallocates the memory buffer for the HMAC SHA256 context structure
*
* \param [in]    pContext    Address of the HMAC SHA256 context buffer
*
********************************************************************************** */
void HMAC_SHA256_FreeCtx
(
    void* pContext
);

/*! *********************************************************************************
* \brief  This function performs the initialization of the HMAC SHA256 context data
*
* \param [in]    pContext    Pointer to the HMAC SHA256 context data
*                            Allocated using HMAC_SHA256_AllocCtx()
* \param [in]    pKey        Pointer to the HMAC key
* \param [in]    keyLen      Length of the HMAC key in bytes
*
********************************************************************************** */
void HMAC_SHA256_Init
(
    void         *pContext,
    const uint8_t *InKey,
    const size_t  keyLen
);

/*! *********************************************************************************
* \brief  This function performs HMAC update with the input data.
*
* \param [in]    pContext    Pointer to the HMAC SHA256 context data
*                            Allocated using HMAC_SHA256_AllocCtx()
* \param [in]    pData       Pointer to the input data
* \param [in]    numBytes    Number of bytes to hash
*
********************************************************************************** */
void HMAC_SHA256_Update
(
    void          *pContext,
    const uint8_t *pData,
    uint32_t      numBytes
);

/*! *********************************************************************************
* \brief  This function finalizes the HMAC SHA256 computation and clears the context data.
*         The final hash value is stored at the provided output location.
*
* \param [in]       pContext    Pointer to the HMAC SHA256 context data
*                               Allocated using HMAC_SHA256_AllocCtx()
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void HMAC_SHA256_Finish
(
    void     *pContext,
    uint8_t  *pOutput
);

/*! *********************************************************************************
* \brief  This function performs all HMAC SHA256 steps on multiple bytes: initialize,
*         update, finish, and update context data.
*         The final HMAC value is stored at the provided output location.
*
* \param [in]       pKey        Pointer to the HMAC key
* \param [in]       keyLen      Length of the HMAC key in bytes
* \param [in]       pData       Pointer to the input data
* \param [in]       numBytes    Number of bytes to perform HMAC on
* \param [out]      pOutput     Pointer to the output location
*
********************************************************************************** */
void HMAC_SHA256
(
    const uint8_t *pKey,
    const size_t  keyLen,
    const uint8_t *pData,
    const size_t  numBytes,
    uint8_t       *pOutput
);

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
void SecLib_XorN (uint8_t*  pDst,   /* First operand and result of XOR operation */
                  const uint8_t*  pSrc,   /* Second operand. Not modified. */
                  uint8_t   n);     /* Number of bytes in input arrays. */








/****************************************************************************
 * \brief Perform an MMO Block Update on the hash
 *        H[j] = E(H[j-1], M[j]) ^ M[j]
 *        where E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * \param [in] psMMO   MMO object
 * \param [in] puBlock Block to hash
 *
 ****************************************************************************/
void AESSW_vMMOBlockUpdate(AESSW_Block_u *puHash,
                           AESSW_Block_u *puBlock);

/****************************************************************************
 * \brief  Perform the final update on the MMO, running text through it
 *         H[0] = 0; H[j] = E(H[j-1], M[j]) ^ M[j] for j=1..t
 *         E(K,x) = AES-128 block cipher, K=key, x=text
 *
 * \param [in] psMMO     MMO object
 * \param [in] pu8Data   Text to run through
 * \param [in] iDataLen  Length of text to run through
 * \param [in] iFinalLen Final length of buffer
 *
 ****************************************************************************/
void AESSW_vMMOFinalUpdate(AESSW_Block_u *puHash,
                           uint8_t *pu8Data,
                           int iDataLen,
                           int iFinalLen);

/****************************************************************************
 * \brief  Perform the HMAC-MMO Keyed Hash Function for Message Authentication
 *         Specified in B.1.4 in ZigBee specification (053474r17)
 *
 * \param [in]  pu8Data  Pointer to data stream
 * \param [in]  iDataLen Length of data stream
 * \param [in]  puKey    Key
 * \param [out] puHash   Output hash
 *
 ****************************************************************************/
void AESSW_vHMAC_MMO(uint8_t *pu8Data,
                     int iDataLen,
                     AESSW_Block_u *puKeyData,
                     AESSW_Block_u *puHash);

/*! *********************************************************************************
* \brief  This function performs AES-128-CTR decryption on a message block.
*
* \param[in]  pInput Pointer to the location of the input message.
* \param[in]  inputLen Input message length in bytes.
* \param[in]  pCounter Pointer to the location of the 128-bit counter.
* \param[in]  pKey Pointer to the location of the 128-bit key.
* \param[out]  pOutput Pointer to the location to store the ciphered output.
*
********************************************************************************** */
void AES_128_CTR_Decrypt(uint8_t* pInput,
                         uint32_t inputLen,
                         uint8_t* pCounter,
                         uint8_t* pKey,
                         uint8_t* pOutput);

/****************************************************************************
 * \brief This function setups the key in the AES.
 *
 * \param [in] psKeyData               tsReg128 key split over 4 words (16 bytes)
 *
 ****************************************************************************/
bool_t bACI_WriteKey(tsReg128 *psKeyData);

/****************************************************************************
 * \brief  This function performs CCM* AES encryption/decryption with checksum
 *         generation/verification. Assumes input buffers are aligned and nonce has a
 *         free byte at the start for the flags field
 *
 * \param [in] bEncrypt               TRUE to encrypt, FALSE to decrypt
 * \param [in] u8M                    Required number of checksum bytes
 * \param [in] u8alength              Length of authentication data, in bytes
 * \param [in] u8mlength              Length of input data, in bytes
 * \param [in] puNonce                Pre-allocated pointer to a structure
 *                                    containing 128-bit Nonce data
 * \param [in] pau8authenticationData Pre-allocated pointer to byte array of
 *                                    authentication data
 * \param [in] pau8Data               Pre-allocated pointer to byte array of input
 *                                    and output data
 * \param [in] pau8checksumData       Pre-allocated pointer to byte array of
 *                                    checksum data
 * \param [in] pbChecksumVerify       Pre-allocated pointer to boolean which in CCM
 *                                    decode mode stores the result of the checksum
 *                                    verification operation
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
                           bool_t        *pbChecksumVerify);


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
 * @param bBlockToReg  direction of conversion
 *                      1 = AESSW_Block_u to tsReg128
 *                      0 = tsReg128 to AESSW_Block_u
 *
 * @return
 *
 * @note
 *
 ****************************************************************************/
void vSwipeEndian( AESSW_Block_u *puBlock,
                   tsReg128 *psReg,
                   bool_t bBlockToReg );



#if (gSecLibAESMethodSelectionDynHwSw_c > 0)
/****************************************************************************
 * NAME:       SecLib_AES_HW_Accelerator_disable
 *
 * @ingroup grp_aes_sw
 *
 * @param DisableNEnable  if set to true disables use of AES HW accelerator and switches to SW implementation
 *
 * @note Required to protect from some error due to simultaneous DMA master performing operations on bus
 *
 ****************************************************************************/
void SecLib_AES_HW_Accelerator_disable(bool_t DisableNEnable);

/****************************************************************************
 * NAME:       SecLib_AES_Is_HW_Accelerator_disabled
 *
 * @ingroup grp_aes_sw
 *
 * @return  true if HW accelerator is disallowed, false otherwise
 *
 *
 ****************************************************************************/
bool_t  SecLib_AES_Is_HW_Accelerator_disabled(void);
#endif


#if defined gLoggingActive_d && (gLoggingActive_d > 0)
#include "dbg_logging.h"
#ifndef DBG_SEC
#define DBG_SEC 0
#endif
#define SEC_DBG_LOG(fmt, ...)   if (DBG_SEC) do { DbgLogAdd(__FUNCTION__ , fmt, VA_NUM_ARGS(__VA_ARGS__), ##__VA_ARGS__); } while (0);
#else
#define SEC_DBG_LOG(...)
#endif
#ifdef __cplusplus
}
#endif

#endif /* _SEC_LIB_H_ */

