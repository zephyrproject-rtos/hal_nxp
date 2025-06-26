/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSCP_MU_H
#define FSL_SSCP_MU_H

#include "fsl_sscp.h"
#include "fsl_elemu.h"

/*!
@defgroup sscp_mu SSCP over MU
@details This section describes definition of the messages for the MU to invoke services
and MU implementation specific functions to initialize SSCP MU link, deinitialize SSCP MU link
and MU invoke command.
@ingroup sscp

# MU commands

## Symmetric cipher

### Symmetric cipher in one go

@copydetails sss_cipher_one_go

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Symmetric Cipher One Go <th class="markdownTableHeadNone" width="10%"> TX
<th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_SymmetricCipherOneGo
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefInput, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_symmetric
<tr><td> word        <td> 3  <td> Pointer to iv
<tr><td> word        <td> 4  <td> ivLen
<tr><td> word        <td> 5  <td> Pointer to srcData
<tr><td> word        <td> 6  <td> dataLen
<tr><td> word        <td> 7  <td> Pointer to destData
<tr><td> word        <td> 8  <td> Pointer to dataLen
</table>

### Symmetric AES in counter mode

@copydetails sss_cipher_crypt_ctr

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> AES in Counter Mode <th class="markdownTableHeadNone" width="10%"> TX <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_SymmetricCryptCtr
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefOutput, MemrefInOut, MemrefInOut, MemrefInOut
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_symmetric
<tr><td> word        <td> 3  <td> Pointer to input data buffer
<tr><td> word        <td> 4  <td> Length of the input data buffer in bytes
<tr><td> word        <td> 5  <td> Pointer to output data buffer
<tr><td> word        <td> 6  <td> Pointer to uint32_t with length of the output data buffer in bytes
<tr><td> word        <td> 7  <td> Pointer to Initial Counter Block
<tr><td> word        <td> 8  <td> Length of the Initial Counter Block in bytes
<tr><td> word        <td> 9  <td> Pointer to Last Encrypted Counter Block
<tr><td> word        <td> 10 <td> Length of the Last Encrypted Counter Block in bytes
<tr><td> word        <td> 11 <td> Pointer to uint32_t specifying number of bytes left unused in the Last Encrypted
Counter Block
<tr><td> word        <td> 12 <td> sizeof(uint32_t)
</table>

### Authenticated encryption with additional data

@copydetails sss_aead_one_go

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Authenticated Encryption with Additional Data <th
class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_AeadOneGo
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefOutput, MemrefOutput, MemrefInput, MemrefInput,
MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_aead
<tr><td> word        <td> 3  <td> Pointer to input data buffer
<tr><td> word        <td> 4  <td> Length of the input data buffer in bytes
<tr><td> word        <td> 5  <td> Pointer to output data buffer
<tr><td> word        <td> 6  <td> Pointer to uint32_t with length of the output data buffer in bytes
<tr><td> word        <td> 7  <td> Pointer to nonce buffer
<tr><td> word        <td> 8  <td> Length of the nonce buffer in bytes
<tr><td> word        <td> 9  <td> Pointer to aad buffer
<tr><td> word        <td> 10 <td> Length of the aad buffer in bytes
<tr><td> word        <td> 11 <td> Pointer to tag buffer
<tr><td> word        <td> 12 <td> Pointer to uint32_t with length of the tag buffer in bytes
</table>

## Digest

### Message digest in one go

@copydetails sss_digest_one_go

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Digest One Go <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_DigestOneGo
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_digest
<tr><td> word        <td> 3  <td> Pointer to message
<tr><td> word        <td> 4  <td> messageLen
<tr><td> word        <td> 5  <td> Pointer to digest
<tr><td> word        <td> 6  <td> Pointer to digestLen
</table>

### Message digest init

@copydetails sss_digest_init

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Digest Init <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_DigestInit
<tr><td> paramTypes  <td> 1  <td> Context
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_digest
</table>

### Message digest update

@copydetails sss_digest_update

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Digest Update <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_DigestUpdate
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_digest
<tr><td> word        <td> 3  <td> Pointer to message
<tr><td> word        <td> 4  <td> messageLen
</table>

### Message digest finish

@copydetails sss_digest_finish

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Digest Finish <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_DigestFinish
<tr><td> paramTypes  <td> 1  <td> Context, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_digest
<tr><td> word        <td> 3  <td> Pointer to digest
<tr><td> word        <td> 4  <td> Pointer to digestLen
</table>

## Mac

### Message authentication code (MAC) in one go

@copydetails sss_mac_one_go

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Mac One Go <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_MacOneGo
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_mac
<tr><td> word        <td> 3  <td> Pointer to message
<tr><td> word        <td> 4  <td> messageLen
<tr><td> word        <td> 5  <td> Pointer to mac
<tr><td> word        <td> 6  <td> Pointer to macLen
</table>

### Message mac init

@copydetails sss_mac_init

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Mac Init <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_MacInit
<tr><td> paramTypes  <td> 1  <td> Context
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_mac
</table>

### Message mac update

@copydetails sss_mac_update

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Mac Update <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_MacUpdate
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_mac
<tr><td> word        <td> 3  <td> Pointer to message
<tr><td> word        <td> 4  <td> messageLen
</table>

### Message mac finish

@copydetails sss_mac_finish

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> MAc Finish <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_MacFinish
<tr><td> paramTypes  <td> 1  <td> Context, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_mac
<tr><td> word        <td> 3  <td> Pointer to mac
<tr><td> word        <td> 4  <td> Pointer to macLen
</table>

## Asymmetric

### Asymmetric sign digest

@copydetails sss_asymmetric_sign_digest

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Asymmetric Sign Digest <th class="markdownTableHeadNone" width="10%"> TX
<th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_AsymmetricSignDigest
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefOutput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_asymmetric
<tr><td> word        <td> 3  <td> Pointer to digest
<tr><td> word        <td> 4  <td> digestLen
<tr><td> word        <td> 5  <td> Pointer to signature
<tr><td> word        <td> 6  <td> Pointer to signatureLen
</table>

### Asymmetric verify digest

@copydetails sss_asymmetric_verify_digest

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Asymmetric Verify Digest <th class="markdownTableHeadNone" width="10%">
TX  <th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_AsymmetricVerifyDigest
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, MemrefInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_asymmetric
<tr><td> word        <td> 3  <td> Pointer to digest
<tr><td> word        <td> 4  <td> digestLen
<tr><td> word        <td> 5  <td> Pointer to signature
<tr><td> word        <td> 6  <td> signatureLen
</table>

## Tunnel

@copydetails sss_tunnel

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Tunnel <th class="markdownTableHeadNone" width="10%"> TX
<th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_Tunnel
<tr><td> paramTypes  <td> 1  <td> Context, MemrefInput, Context, ValueInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_tunnel
<tr><td> word        <td> 3  <td> Pointer to input data buffer
<tr><td> word        <td> 4  <td> Length of the input data buffer in bytes
<tr><td> word        <td> 5  <td> Pointer to an array of ::_sss_sscp_object
<tr><td> word        <td> 6  <td> Number of the elements in the array of ::_sss_sscp_object
<tr><td> word        <td> 7  <td> Tunnel type id
</table>

## Derive key

### Asymmetric shared secret - Diffie-Helmann

@copydetails sss_asymmetric_dh_derive_key

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Asymmetric Derive Key <th class="markdownTableHeadNone" width="10%"> TX
<th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_AsymmetricDeriveKey
<tr><td> paramTypes  <td> 1  <td> Context, Context, Context
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_derive_key
<tr><td> word        <td> 3  <td> Pointer to ::_sss_sscp_object
<tr><td> word        <td> 4  <td> Pointer to ::_sss_sscp_object
</table>

## Key Object

### Key Object Allocate Handle

@copydetails sss_key_object_allocate_handle

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Key Object Allocate Handle <th class="markdownTableHeadNone" width="10%">
TX  <th class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_KeyObjectAllocateHandle
<tr><td> paramTypes  <td> 1  <td> Context, ValueInput, ValueInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_object
<tr><td> word        <td> 3  <td> keyId
<tr><td> word        <td> 4  <td> keyType
<tr><td> word        <td> 5  <td> keyByteLenMax
<tr><td> word        <td> 6  <td> options
</table>

## Key Store

### Key Store Allocate

@copydetails sss_key_store_allocate

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Key Store Allocate <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_KeyStoreAllocate
<tr><td> paramTypes  <td> 1  <td> Context, ValueInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_key_store
<tr><td> word        <td> 3  <td> keyStoreId
<tr><td> word        <td> 4  <td> Zero
</table>

### Set key into key store

@copydetails sss_key_store_set_key

<table width="60%" class="markdownTable">
<tr class="markdownTableHead">
<th class="markdownTableHeadNone" width="30%"> Key Store Set Key <th class="markdownTableHeadNone" width="10%"> TX  <th
class="markdownTableHeadNone" width="60%"> MU TXn register value
<tr><td> Command     <td> 0  <td> kSSCP_CMD_SSS_KeyStoreSetKey
<tr><td> paramTypes  <td> 1  <td> Context, Context, MemrefInput, ValueInput, MemrefInput
<tr><td> word        <td> 2  <td> Pointer to ::_sss_sscp_key_store
<tr><td> word        <td> 3  <td> Pointer to ::_sss_sscp_object
<tr><td> word        <td> 4  <td> Pointer to key buffer
<tr><td> word        <td> 5  <td> Length of key buffer in bytes
<tr><td> word        <td> 6  <td> Key Length in bits
<tr><td> word        <td> 7  <td> Zero
<tr><td> word        <td> 8  <td> Pointer to options buffer
<tr><td> word        <td> 9  <td> Length of the options buffer in bytes
</table>

*/

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @addtogroup sscp_mu
 * @{
 */

/**
 * struct sscp_mu_context_t - SSCP context struct for MU implementation
 *
 * This data type is used to keep context of the SSCP link.
 * It is completely implementation specific.
 *
 * @param context Container for the implementation specific data.
 */
typedef struct
{
    fn_sscp_invoke_command_t invoke;

    /*! Implementation specific part */
    ELEMU_Type *base;
} sscp_mu_context_t;

/*! @brief Initializes the SSCP link
 *
 * This function initializes the SSCP for operation - e.g.underlaying hardware is initialized
 * and prepared for data exchange.
 *
 * @param context Context structure for the SSCP.
 * @param base The MU peripheral base address to be used for communication
 *
 * @returns Status of the operation
 * @retval kStatus_SSCP_Success SSCP init success
 * @retval kStatus_SSCP_Fail SSCP init failure
 */
sscp_status_t sscp_mu_init(sscp_context_t *context, ELEMU_Type *base);

/*! @brief Close the SSCP link
 *
 * This function closes the SSCP link - e.g.underlying hardware is disabled.
 *
 * @param context Context structure for the SSCP.
 */
void sscp_mu_deinit(sscp_context_t *context);

/*! @brief Sends a command and associated parameters to security sub-system
 *
 *  The commandID and operation content is serialized and sent over to the selected security sub-system.
 *  This is implementation specific function.
 *  The function can invoke both blocking and non-blocking secure functions in the selected security sub-system.
 *
 * @param context Initialized SSCP context
 * @param commandID Command - an id of a remote secure function to be invoked
 * @param op Description of function arguments as a sequence of buffers and values
 * @param ret Return code of the remote secure function (application layer return value)
 *
 * @returns Status of the operation
 * @retval kStatus_SSCP_Success A blocking command has completed or a non-blocking command has been accepted.
 * @retval kStatus_SSCP_Fail Operation failure, for example hardware fail.
 * @retval kStatus_SSCP_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sscp_status_t sscp_mu_invoke_command(sscp_context_t *context,
                                     sscp_command_t commandId,
                                     sscp_operation_t *op,
                                     uint32_t *ret);

void MU_Init(void);

sscp_status_t MU_ReceiveMsg(ELEMU_Type *base, uint32_t msg[ELEMU_RR_COUNT], size_t wordNum);

sscp_status_t MU_SendMsg(ELEMU_Type *base, uint32_t msg[ELEMU_TR_COUNT], size_t wordNum);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */ /* end of sscp_mu */

#endif /* FSL_SSCP_MU_H */
