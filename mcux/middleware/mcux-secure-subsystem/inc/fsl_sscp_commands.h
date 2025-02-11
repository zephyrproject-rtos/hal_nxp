/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSCP_COMMANDS_H
#define FSL_SSCP_COMMANDS_H

#if !defined(SSCP_CONFIG_FILE)
#include "fsl_sscp_config_elemu.h"
#else
#include SSCP_CONFIG_FILE
#endif

/*!
@defgroup sscp_cmd SSCP commands
@details This section describes the SSCP commands and parameters.
@ingroup sscp
*/
/*!
 * @addtogroup sscp_cmd
 * @{
 */

#if !defined(SSCP_COMMAND_ENUM_ALT)
/*! @brief SSCP common commands */
typedef enum
{
    kSSCP_CMD_SSS_OpenSession,
    kSSCP_CMD_SSS_CloseSession,
    kSSCP_CMD_SSS_Ping,
    kSSCP_CMD_SSS_ContextFree,
    kSSCP_CMD_SSS_SymmetricContextInit,
    kSSCP_CMD_SSS_SymmetricCipherOneGo,
    kSSCP_CMD_SSS_SymmetricCipherInit,
    kSSCP_CMD_SSS_SymmetricCipherUpdate,
    kSSCP_CMD_SSS_SymmetricCipherFinish,
    kSSCP_CMD_SSS_SymmetricCryptCtr,
    kSSCP_CMD_SSS_AeadContextInit,
    kSSCP_CMD_SSS_AeadOneGo,
    kSSCP_CMD_SSS_AeadInit,
    kSSCP_CMD_SSS_AeadUpdateAead,
    kSSCP_CMD_SSS_AeadUpdate,
    kSSCP_CMD_SSS_AeadFinish,
    kSSCP_CMD_SSS_DigestContextInit,
    kSSCP_CMD_SSS_DigestOneGo,
    kSSCP_CMD_SSS_DigestInit,
    kSSCP_CMD_SSS_DigestUpdate,
    kSSCP_CMD_SSS_DigestFinish,
    kSSCP_CMD_SSS_MacContextInit,
    kSSCP_CMD_SSS_MacOneGo,
    kSSCP_CMD_SSS_MacInit,
    kSSCP_CMD_SSS_MacUpdate,
    kSSCP_CMD_SSS_MacFinish,
    kSSCP_CMD_SSS_AsymetricContextInit,
    kSSCP_CMD_SSS_AsymmetricEncrypt,
    kSSCP_CMD_SSS_AsymmetricDecrypt,
    kSSCP_CMD_SSS_AsymmetricSignDigest,
    kSSCP_CMD_SSS_AsymmetricVerifyDigest,
    kSSCP_CMD_SSS_TunnelContextInit,
    kSSCP_CMD_SSS_Tunnel,
    kSSCP_CMD_SSS_DeriveKeyContextInit,
    kSSCP_CMD_SSS_DeriveKey,
    kSSCP_CMD_SSS_AsymmetricDeriveKey,
    kSSCP_CMD_SSS_KeyObjectContextInit,
    kSSCP_CMD_SSS_KeyObjectAllocateHandle,
    kSSCP_CMD_SSS_KeyObjectGetHandle,
    kSSCP_CMD_SSS_KeyObjectContextFree,
    kSSCP_CMD_SSS_KeyStoreContextInit,
    kSSCP_CMD_SSS_KeyStoreAllocate,
    kSSCP_CMD_SSS_KeyStoreSave,
    kSSCP_CMD_SSS_KeyStoreLoad,
    kSSCP_CMD_SSS_KeyStoreSetKey,
    kSSCP_CMD_SSS_KeyStoreGenerateKey,
    kSSCP_CMD_SSS_KeyStoreGetKey,
    kSSCP_CMD_SSS_KeyStoreOpenKey,
    kSSCP_CMD_SSS_KeyStoreFreezeKey,
    kSSCP_CMD_SSS_KeyStoreEraseKey,
    kSSCP_CMD_SSS_KeyStoreEraseAll,
    KSSCP_CMD_SSS_RngGet,
    kSSCP_CMD_SSS_MGMT_ContextInit,
    kSSCP_CMD_SSS_MGMT_FuseRead,
    kSSCP_CMD_SSS_MGMT_FuseShadowRegisterRead,
    kSSCP_CMD_SSS_MGMT_FuseProgram,
    kSSCP_CMD_SSS_MGMT_PropertyGet,
    kSSCP_CMD_SSS_MGMT_LifeCycleGet,
    kSSCP_CMD_SSS_MGMT_PropertySet,
    kSSCP_CMD_SSS_MGMT_AdvanceLifecycle,
    kSSCP_CMD_SSS_MGMT_SecretImport,
    kSSCP_CMD_SSS_MGMT_SecretExport,
    kSSCP_CMD_SSS_MGMT_Attest,
    kSSCP_CMD_SSS_MGMT_SecretBlobLoad,
    kSSCP_CMD_SSS_MGMT_SecretBlobExport,
    kSSCP_CMD_SSS_MGMT_SecretBlobImport,
    kSSCP_CMD_SSS_MGMT_SoftwareVersionGet,
    kSSCP_CMD_SSS_MGMT_ReturnFaSet,
    kSSCP_CMD_SSS_MGMT_HostAccessPermissionSet,
    kSSCP_CMD_SSS_MGMT_IntegrityCheckEnable,

    /* TODO: Remove TEE */
    TEE_CMD_NONE,
    TEE_CMD_GENERATE_KEY,
    TEE_CMD_ERASE_KEY,
    TEE_CMD_GET_KEY,
    TEE_CMD_FREEZE_KEY,
    // TEE_CMD_ALLOCATE_KEY,
    TEE_CMD_ALLOCATE_KEYSTORE,
    TEE_CMD_SAVE_KEYSTORE,
    TEE_CMD_LOAD_KEYSTORE,
    TEE_CMD_SET_KEY,
    TEE_KEYOBJ_CMD_ALLOCATE_HANDLE,
    TEE_KEYOBJ_CMD_GET_HANDLE,
    TEE_KEYOBJ_CMD_SET_USER,
    TEE_KEYOBJ_CMD_SET_PURPOSE,
    TEE_KEYOBJ_CMD_SET_ACCESS,
    TEE_KEYOBJ_CMD_GET_USER,
    TEE_KEYOBJ_CMD_GET_PURPOSE,
    TEE_KEYOBJ_CMD_GET_ACCESS,
    TEE_ASYMMETRIC_CTX_INIT,
    TEE_ASYMMETRIC_CMD_ENCRYPT,
    TEE_ASYMMETRIC_CMD_DECRYPT,
    TEE_ASYMMETRIC_CMD_SIGN_DIGEST,
    TEE_ASYMMETRIC_CMD_VERIFY_DIGEST,
    TEE_SYMM_CIPHER_CTX_INIT,
    TEE_SYMM_CIPHER_ONE_GO,
    TEE_SYMM_CIPHER_INIT,
    TEE_SYMM_CIPHER_UPDATE,
    TEE_SYMM_CIPHER_FINISH,
    TEE_SYMM_CIPHER_CRYPT_CTR,
    TEE_DERIVE_CTX_INIT,
    TEE_DERIVE_KEY,
    TEE_ASYMM_DH_DERIVE_KEY,
    TEE_CMD_LAST
} sscp_command_t;
#endif /* SSCP_COMMAND_ENUM_ALT */

#if !defined(SSCP_PARAMCONTEXTTYPE_ENUM_ALT)
/*! @brief SSCP ParamContextType list */
enum
{
    kSSCP_ParamContextType_SSS_Session = 0x1u,
    kSSCP_ParamContextType_SSS_Symmetric,
    kSSCP_ParamContextType_SSS_Aead,
    kSSCP_ParamContextType_SSS_Digest,
    kSSCP_ParamContextType_SSS_Mac,
    kSSCP_ParamContextType_SSS_Asymmetric,
    kSSCP_ParamContextType_SSS_Tunnel,
    kSSCP_ParamContextType_SSS_DeriveKey,
    kSSCP_ParamContextType_SSS_Object,
    kSSCP_ParamContextType_SSS_KeyStore,
    kSSCP_ParamContextType_SSS_KeyStoreCtx,
    kSSCP_ParamContextType_SSS_Mgmt,
    kSSCP_ParamContextType_SSS_Rng,
};
#endif /* SSCP_PARAMCONTEXTTYPE_ENUM_ALT */

/*!
 *@}
 */ /* end of sscp */

#endif /* FSL_SSCP_COMMANDS_H */
