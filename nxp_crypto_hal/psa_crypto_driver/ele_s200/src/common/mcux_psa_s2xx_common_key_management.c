/*
 * Copyright 2025-2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/** \file mcux_psa_s2xx_common_key_management.c
 *
 * This file contains the definitions of the entry points associated to
 * common S2XX key management procedures.
 *
 */

#include "mcux_psa_s2xx_common_compute.h"
#include "mcux_psa_s2xx_common_key_management.h"
#include "mcux_psa_s2xx_key_locations.h"
#include "mcux_psa_util_wrapcheck_static_inline.h"


#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
extern const uint8_t fw[];
#endif /* ELEMU_HAS_LOADABLE_FW */

// PSA command context
typedef struct psa_cmd_s
{
    psa_key_attributes_t attributes;
    const uint8_t *magic;
    size_t magic_size;
    uint32_t wrapping_key_id;
    uint32_t wrapping_algorithm;
    const uint8_t *iv;
    size_t iv_size;
    uint32_t signature_key_id;
    uint32_t signature_algorithm;
    const uint8_t *keyincmd;
    size_t keyincmd_size;
    const uint8_t *signature;
    size_t signature_size;
} psa_cmd_t;

#define EL2GO_AES_KEY_PROPERTIES          (0x8001c001u)

// Tags used in PSA commands
#define PSA_CMD_TAG_MAGIC               0x40U
#define PSA_CMD_TAG_KEY_ID              0x41U
#define PSA_CMD_TAG_PERMITTED_ALGORITHM 0x42U
#define PSA_CMD_TAG_KEY_USAGE_FLAGS     0x43U
#define PSA_CMD_TAG_KEY_TYPE            0x44U
#define PSA_CMD_TAG_KEY_BITS            0x45U
#define PSA_CMD_TAG_KEY_LIFETIME        0x46U
#define PSA_CMD_TAG_KEY_LIFECYCLE       0x47U
#define PSA_CMD_TAG_WRAPPING_KEY_ID     0x50U
#define PSA_CMD_TAG_WRAPPING_ALGORITHM  0x51U
#define PSA_CMD_TAG_IV                  0x52U
#define PSA_CMD_TAG_SIGNATURE_KEY_ID    0x53U
#define PSA_CMD_TAG_SIGNATURE_ALGORITHM 0x54U
#define PSA_CMD_TAG_KEYIN_CMD           0x55U
#define PSA_CMD_TAG_SIGNATURE           0x5EU

// Algorithms used in EL2GO blobs
#define BLOB_SIGN_ALGORITHM_CMAC    0x01U
#define BLOB_WRAP_ALGORITHM_RFC3394 0x01U
#define BLOB_WRAP_ALGORITHM_AES_CBC 0x02U

#define NXP_DIE_EL2GOIMPORT_AUTH_SK_ID   0x7FFF8170U

#define CMAC_BLOCK_SIZE 16U

#ifndef PSA_DRIVER_ERROR
#define PSA_DRIVER_ERROR(...)                                \
    for (;;)                                                 \
    {                                                        \
        break;                                               \
    }
#endif /* PSA_DRIVER_ERROR */

#define PSA_DRIVER_EXIT_STATUS_MSG(STATUS, ...) \
    psa_status = STATUS;                        \
    PSA_DRIVER_ERROR(__VA_ARGS__);              \
    goto exit;

#define PSA_DRIVER_SUCCESS_OR_EXIT_MSG(...) \
    if (PSA_SUCCESS != psa_status)          \
    {                                       \
        PSA_DRIVER_ERROR(__VA_ARGS__);      \
        goto exit;                          \
    }

#define PSA_DRIVER_SUCCESS_OR_EXIT() PSA_DRIVER_SUCCESS_OR_EXIT_MSG("psa_status is not success but [0x%x]", psa_status)


#define PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(CONDITION, STATUS, ...) \
    if (!(CONDITION))                                                \
    {                                                                \
        PSA_DRIVER_EXIT_STATUS_MSG(STATUS, __VA_ARGS__);             \
    }

/** @brief Gets the 32-bit value from the value buffer.
 *
 */
static uint32_t get_uint32_val(const uint8_t *input)
{
    uint32_t output = 0U;
    output          = *(input);
    output <<= 8;
    output |= *(input + 1u);
    output <<= 8;
    output |= *(input + 2u);
    output <<= 8;
    output |= *(input + 3u);
    return output;
}

/** @brief Gets the 16-bit value from the value buffer.
 *
 */
static uint16_t get_uint16_val(const uint8_t *input)
{
    uint16_t output = 0U;
    output          = *input;
    output <<= 8;
    output |= *(input + 1u);
    return output;
}

/* coverity[misra_c_2012_rule_5_8_violation]: local "p_end" name chosen to avoid conflict with external "end" symbol */
/* Function taken from MbedTLS */
static int get_len(const unsigned char **p, const unsigned char *p_end, size_t *len)
{
    if ((p_end - *p) < 1)
    {
        return (PSA_ERROR_INVALID_ARGUMENT);
    }

    if ((**p & 0x80u) == 0u)
    {
        *len = *(*p)++;
    }
    else
    {
        /* coverity[misra_c_2012_rule_16_1_violation]: switch controlling expression type matches case values */
        switch (**p & 0x7Fu)
        {
            case 1U:
                if ((p_end - *p) < 2)
                {
                    return (PSA_ERROR_INVALID_ARGUMENT);
                }

                *len = (*p)[1];
                (*p) += 2;
                break;

            case 2U:
                if ((p_end - *p) < 3)
                {
                    return (PSA_ERROR_INVALID_ARGUMENT);
                }

                *len = ((size_t)(*p)[1] << 8U) | (*p)[2];
                (*p) += 3;
                break;

            case 3U:
                if ((p_end - *p) < 4)
                {
                    return (PSA_ERROR_INVALID_ARGUMENT);
                }

                *len = ((size_t)(*p)[1] << 16U) | ((size_t)(*p)[2] << 8U) | (*p)[3];
                (*p) += 4;
                break;

            case 4U:
                if ((p_end - *p) < 5)
                {
                    return (PSA_ERROR_INVALID_ARGUMENT);
                }

                *len = ((size_t)(*p)[1] << 24U) | ((size_t)(*p)[2] << 16U) | ((size_t)(*p)[3] << 8U) | (*p)[4];
                (*p) += 5;
                break;

            default:
                /* coverity[misra_c_2012_rule_16_3_violation]: return exits the function; break is unreachable */
                return (PSA_ERROR_INVALID_ARGUMENT);
        }
    }
    /* coverity[misra_c_2012_rule_10_8_violation]: ptrdiff_t to size_t cast; p_end >= *p guaranteed by checks above */
    if (*len > (size_t)(p_end - *p))
    {
        return (PSA_ERROR_INVALID_ARGUMENT);
    }
    return (0);
}

/* coverity[misra_c_2012_rule_5_8_violation]: local "p_end" name chosen to avoid conflict with external "end" symbol */
/* Function taken from MbedTLS */
static int get_tag(const unsigned char **p, const unsigned char *p_end, size_t *len, uint8_t tag)
{
    if ((p_end - *p) < 1)
    {
        return (PSA_ERROR_INVALID_ARGUMENT);
    }

    if (**p != tag)
    {
        return (PSA_ERROR_INVALID_ARGUMENT);
    }

    (*p)++;

    return (get_len(p, p_end, len));
}

static psa_status_t parse_psa_import_command(const uint8_t *data, size_t data_size, psa_cmd_t *psa_cmd)
{
    psa_status_t psa_status = PSA_ERROR_INVALID_ARGUMENT;

    uint8_t tag    = 0U; // the tag of the current TLV
    size_t cmd_len = 0U; // the length of the current TLV

    /* coverity[misra_c_2012_rule_5_8_violation]: local "p_end" name chosen to avoid conflict with external "end" symbol */
    const uint8_t *cmd_ptr = NULL;
    const uint8_t *p_end   = NULL;

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(data != NULL, PSA_ERROR_INVALID_ARGUMENT, "The command is null");
    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_cmd != NULL, PSA_ERROR_INVALID_ARGUMENT,
                                         "The key attributes context is null");

    (void)memset(psa_cmd, 0, sizeof(psa_cmd_t));
    psa_cmd->attributes = psa_key_attributes_init();

    cmd_ptr = data;
    p_end   = cmd_ptr + data_size;

    while ((cmd_ptr + 1U) < p_end)
    {
        tag        = *cmd_ptr;
        psa_status = get_tag(&cmd_ptr, p_end, &cmd_len, tag);
        PSA_DRIVER_SUCCESS_OR_EXIT_MSG("get_tag failed: 0x%x", psa_status);

        switch (tag)
        {
            case PSA_CMD_TAG_MAGIC:
                psa_cmd->magic      = cmd_ptr;
                psa_cmd->magic_size = cmd_len;
                break;
            case PSA_CMD_TAG_KEY_ID:
                psa_set_key_id(&psa_cmd->attributes, mbedtls_svc_key_id_make(0, (psa_key_id_t)get_uint32_val(cmd_ptr)));
                break;
            case PSA_CMD_TAG_PERMITTED_ALGORITHM:
                psa_set_key_algorithm(&psa_cmd->attributes, (psa_algorithm_t)get_uint32_val(cmd_ptr));
                break;
            case PSA_CMD_TAG_KEY_USAGE_FLAGS:
                psa_set_key_usage_flags(&psa_cmd->attributes, (psa_key_usage_t)get_uint32_val(cmd_ptr));
                break;
            case PSA_CMD_TAG_KEY_TYPE:
                psa_set_key_type(&psa_cmd->attributes, (psa_key_type_t)get_uint16_val(cmd_ptr));
                break;
            case PSA_CMD_TAG_KEY_BITS:
                psa_set_key_bits(&psa_cmd->attributes, (size_t)get_uint32_val(cmd_ptr));
                break;
            case PSA_CMD_TAG_KEY_LIFETIME:
                psa_set_key_lifetime(&psa_cmd->attributes, (psa_key_lifetime_t)get_uint32_val(cmd_ptr));
                break;
            case PSA_CMD_TAG_KEY_LIFECYCLE:
                /* Nothing to do */
                break;
            case PSA_CMD_TAG_WRAPPING_KEY_ID:
                psa_cmd->wrapping_key_id = get_uint32_val(cmd_ptr);
                break;
            case PSA_CMD_TAG_WRAPPING_ALGORITHM:
                psa_cmd->wrapping_algorithm = get_uint32_val(cmd_ptr);
                break;
            case PSA_CMD_TAG_IV:
                psa_cmd->iv      = cmd_ptr;
                psa_cmd->iv_size = cmd_len;
                break;
            case PSA_CMD_TAG_SIGNATURE_KEY_ID:
                psa_cmd->signature_key_id = get_uint32_val(cmd_ptr);
                break;
            case PSA_CMD_TAG_SIGNATURE_ALGORITHM:
                psa_cmd->signature_algorithm = get_uint32_val(cmd_ptr);
                break;
            case PSA_CMD_TAG_KEYIN_CMD:
                psa_cmd->keyincmd      = cmd_ptr;
                psa_cmd->keyincmd_size = cmd_len;
                break;
            case PSA_CMD_TAG_SIGNATURE:
                psa_cmd->signature      = cmd_ptr;
                psa_cmd->signature_size = cmd_len;
                break;
            default:
                PSA_DRIVER_ERROR("Unknown tag: 0x%x", tag);
                break;
        }
        cmd_ptr += cmd_len;
    }

exit:

    return psa_status;
}

static psa_status_t ele_s2xx_import_key_blob(const psa_key_attributes_t *attributes,
                                             const uint8_t *blob,
                                             size_t blob_size,
                                             sss_sscp_object_t *sssKey)
{
    psa_status_t psa_status          = PSA_ERROR_CORRUPTION_DETECTED;
    sss_sscp_key_property_t keyprops = {0u};
    sss_key_part_t key_part          = {0u};
    sss_cipher_type_t cipher_type    = {0u};
    size_t allocation_size           = 0u;
    psa_key_location_t location      = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    sss_sscp_blob_type_t blob_type   = kSSS_blobType_ELKE_blob;

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* Check if EL2go FW is loaded into S200; if not, load it */
        if (is_fw_loaded() != PSA_SUCCESS)
        {
#if (defined(ELEMU_HAS_LOADABLE_FW) && ELEMU_HAS_LOADABLE_FW)
            if (ELEMU_loadFw(ELEMUA, (uint32_t *)fw) != kStatus_Success)
            {
                psa_status = PSA_ERROR_HARDWARE_FAILURE;
            }
#else /* ELEMU_HAS_LOADABLE_FW */
            psa_status = PSA_ERROR_NOT_SUPPORTED;
#endif /* ELEMU_HAS_LOADABLE_FW */
            PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, loadFW() failed");
        }
        blob_type = kSSS_blobType_EL2GO_TLV_blob;
    }
    else if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
    {
        blob_type = kSSS_blobType_ELKE_blob;
    }
    else
    {
        psa_status = PSA_ERROR_INVALID_ARGUMENT;
        PSA_DRIVER_SUCCESS_OR_EXIT();
    }

    /* Import blob into S200, if operation ends with success, blob is valid */

    if (sss_sscp_key_object_init_internal(sssKey, &g_ele_ctx.keyStore) != kStatus_SSS_Success)
    {
        psa_status = PSA_ERROR_HARDWARE_FAILURE;
        PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, Keyobject init failed");
    }

    psa_status = ele_s2xx_get_algo_keyprop(attributes, &keyprops, &key_part, &cipher_type, &allocation_size);
    if (PSA_SUCCESS != psa_status)
    {
        PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, Valid keyproperty not found");
    }

    /* Check if this key has already been imported */
    if (sss_sscp_key_object_get_handle(sssKey, MBEDTLS_SVC_KEY_ID_GET_KEY_ID(psa_get_key_id(attributes))) != kStatus_SSS_Success)
    {
        /* Handle not found, but we got passed a key; try to import it */

        if (sss_sscp_key_object_init(sssKey, &g_ele_ctx.keyStore) != kStatus_SSS_Success)
        {
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, Keyobject init 2 failed");
        }

        /* Use the PSA key ID as the S200 key ID - easier to keep track of it */
        if (sss_sscp_key_object_allocate_handle(sssKey, MBEDTLS_SVC_KEY_ID_GET_KEY_ID(psa_get_key_id(attributes)),
                                                key_part, cipher_type,
                                                allocation_size,
                                                keyprops) != kStatus_SSS_Success)
        {
            (void)sss_sscp_key_object_free(sssKey, kSSS_keyObjFree_KeysStoreDefragment);
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, Allocating handle failed");
        }

        /* Load key from blob */
        if (sss_sscp_key_store_import_key(&g_ele_ctx.keyStore, sssKey, blob,
                                          blob_size, 0u,
                                          blob_type) != kStatus_SSS_Success)
        {
            (void)sss_sscp_key_object_free(sssKey, kSSS_keyObjFree_KeysStoreDefragment);
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error, Blob import failed");
        }

        /* In case the original blob did not prohibit plain reads and writes,
         * we add plain read/write prohibition flags. This does not override
         * existing flags from the blob import, as writeable flags are sticky.
         */
        keyprops = kSSS_KeyProp_NoPlainWrite | kSSS_KeyProp_NoPlainRead;

        if (sss_sscp_key_object_set_properties(sssKey, (uint32_t)keyprops) != kStatus_SSS_Success)
        {
            (void)sss_sscp_key_object_free(sssKey, kSSS_keyObjFree_KeysStoreDefragment);
            psa_status = PSA_ERROR_HARDWARE_FAILURE;
            goto exit;
        }
    }

    psa_status = PSA_SUCCESS;
exit:
    return psa_status;
}

psa_status_t ele_s2xx_set_key(sss_sscp_object_t *sssKey,
                              uint32_t key_id,
                              const uint8_t *key_buffer,
                              size_t key_buffer_size,
                              sss_key_part_t key_part,
                              sss_cipher_type_t cipher_type,
                              sss_sscp_key_property_t key_properties,
                              size_t allocation_size,
                              size_t key_bitlen)
{
    if (sss_sscp_key_object_init(sssKey, &g_ele_ctx.keyStore) != kStatus_SSS_Success)
    {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    if (sss_sscp_key_object_allocate_handle(sssKey, key_id,
                                            key_part, cipher_type,
                                            allocation_size,
                                            key_properties) != kStatus_SSS_Success)
    {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    if (sss_sscp_key_store_set_key(&g_ele_ctx.keyStore, sssKey, key_buffer,
                                   key_buffer_size, key_bitlen,
                                   key_part) != kStatus_SSS_Success)
    {
        return PSA_ERROR_HARDWARE_FAILURE;
    }

    return PSA_SUCCESS;
}

psa_status_t ele_s2xx_get_key(sss_sscp_object_t *sssKey,
                              uint8_t *key_buffer,
                              size_t key_buffer_size,
                              size_t *key_buffer_length,
                              sss_key_part_t key_part,
                              size_t *key_bitlen)
{
    psa_status_t status        = PSA_SUCCESS;
    size_t key_bitlen_internal = 0u;

    *key_buffer_length = key_buffer_size;
    if ((sss_sscp_key_store_get_key(&g_ele_ctx.keyStore, sssKey, key_buffer,
                                    key_buffer_length, &key_bitlen_internal,
                                    key_part)) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }

    if (NULL != key_bitlen)
    {
        *key_bitlen = key_bitlen_internal;
    }

    return status;
}

psa_status_t ele_s2xx_get_ecc_public_key_from_private(sss_sscp_object_t *sssKey,
                                                      uint8_t *data,
                                                      size_t data_size,
                                                      size_t *data_length,
                                                      size_t *key_bitlen)
{
    psa_status_t status        = PSA_SUCCESS;
    size_t key_bitlen_internal = 0u;

    *data_length = data_size;
    if (sss_sscp_key_store_get_key(&g_ele_ctx.keyStore, sssKey, data,
                                   data_length, &key_bitlen_internal,
                                   kSSS_KeyPart_Public) != kStatus_SSS_Success)
    {
        status = PSA_ERROR_HARDWARE_FAILURE;
    }

    if (NULL != key_bitlen)
    {
        *key_bitlen = key_bitlen_internal;
    }

    return status;
}

psa_status_t ele_s2xx_delete_key(sss_sscp_object_t *sssKey)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    do
    {
        if (NULL == sssKey)
        {
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
        }

        /* Check if the key object has been initialized; return early if not */
        if (NULL == sssKey->keyStore)
        {
            status = PSA_ERROR_DOES_NOT_EXIST;
            break;
        }

        /* At first, try to erase the key */
        (void)sss_sscp_key_store_erase_key(&g_ele_ctx.keyStore, sssKey);

        /* Regardless of the erase operation success, free the key object */
        if (sss_sscp_key_object_free(sssKey, kSSS_keyObjFree_KeysStoreDefragment) != kStatus_SSS_Success)
        {
            status = PSA_ERROR_HARDWARE_FAILURE;
            break;
        }

        status = PSA_SUCCESS;
    } while (false);

    return status;
}

/* Modified from mcuxClPsaDriver_Oracle_Utils_ValidateBlobAttributes() */
/* Take the blob attribs + the given PSA key attribs and check if they match. */
psa_status_t ele_s2xx_validate_blob_attributes(const psa_key_attributes_t *attributes,
                                               const uint8_t *psa_import_blob,
                                               size_t psa_import_blob_size)
{
    psa_status_t psa_status = PSA_SUCCESS;

    psa_cmd_t psa_cmd;
    psa_status = parse_psa_import_command(psa_import_blob, psa_import_blob_size, &psa_cmd);
    PSA_DRIVER_SUCCESS_OR_EXIT_MSG("Error while parsing import blob");

    // Validate input PSA attributes
    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(0 == mbedtls_svc_key_id_is_null(psa_get_key_id(attributes)),
                                         PSA_ERROR_INVALID_ARGUMENT, "Invalid input key_id");

    // Attention: Permitted algorithm can be 0 (PSA_ALG_NONE for X.509/Binary)
    // Attention: Permitted usage can be 0 (PSA_KEY_USAGE_NONE for static public keys)

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_type(attributes) != (psa_key_type_t)0, PSA_ERROR_INVALID_ARGUMENT,
                                         "Invalid input key_type");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_bits(attributes) != (size_t)0, PSA_ERROR_INVALID_ARGUMENT,
                                         "Invalid input key_length");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_lifetime(attributes) != (psa_key_lifetime_t)0,
                                         PSA_ERROR_INVALID_ARGUMENT, "Invalid input key_lifetime");

    // Validate blob PSA attributes
    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(MBEDTLS_SVC_KEY_ID_GET_KEY_ID(psa_get_key_id(attributes)) ==
                                             MBEDTLS_SVC_KEY_ID_GET_KEY_ID(psa_get_key_id(&psa_cmd.attributes)),
                                         PSA_ERROR_INVALID_ARGUMENT, "provided key_id does not match with blob key_id");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(
        psa_get_key_algorithm(attributes) == psa_get_key_algorithm(&psa_cmd.attributes), PSA_ERROR_INVALID_ARGUMENT,
        "provided permitted_alg does not match with blob permitted_alg");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(
        psa_get_key_usage_flags(attributes) == psa_get_key_usage_flags(&psa_cmd.attributes), PSA_ERROR_INVALID_ARGUMENT,
        "provided key_usage does not match with blob key_usage");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_type(attributes) == psa_get_key_type(&psa_cmd.attributes),
                                         PSA_ERROR_INVALID_ARGUMENT,
                                         "provided key_type does not match with blob key_type");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_bits(attributes) == psa_get_key_bits(&psa_cmd.attributes),
                                         PSA_ERROR_INVALID_ARGUMENT,
                                         "provided key_length does not match with blob key_length");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(psa_get_key_lifetime(attributes) == psa_get_key_lifetime(&psa_cmd.attributes),
                                         PSA_ERROR_INVALID_ARGUMENT,
                                         "provided key_lifetime does not match with blob key_lifetime");


    // Validate signature parameters
    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(NXP_DIE_EL2GOIMPORT_AUTH_SK_ID == psa_cmd.signature_key_id,
                                         PSA_ERROR_INVALID_ARGUMENT, "Unknown blob signature_key_id");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(BLOB_SIGN_ALGORITHM_CMAC == psa_cmd.signature_algorithm,
                                         PSA_ERROR_INVALID_ARGUMENT, "Unknown blob signature_algorithm");

    PSA_DRIVER_ASSERT_OR_EXIT_STATUS_MSG(CMAC_BLOCK_SIZE == psa_cmd.signature_size, PSA_ERROR_INVALID_ARGUMENT,
                                         "Invalid blob CMAC size");

    psa_status = PSA_SUCCESS;
exit:
    return psa_status;
}

psa_status_t ele_s2xx_import_key(const psa_key_attributes_t *attributes,
                                 const uint8_t *key_buffer,
                                 size_t key_buffer_size,
                                 sss_sscp_object_t *sssKey)
{
    psa_status_t psa_status     = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    if (true == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE(location))
    {
        /* Validate if the key is an EL2GO blob */
        psa_status = ele_s2xx_validate_blob_attributes(attributes, key_buffer, key_buffer_size);
        if (PSA_SUCCESS != psa_status)
        {
            return psa_status;
        }
    }

    /* Import the key blob */
    psa_status = ele_s2xx_import_key_blob(attributes, key_buffer,
                                          key_buffer_size, sssKey);
    return psa_status;
}


psa_status_t ele_s2xx_export_key(const psa_key_attributes_t *attributes,
                                 uint8_t *data,
                                 size_t data_size,
                                 size_t *data_length,
                                 sss_sscp_object_t *sssKey)
{
    psa_status_t status            = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location    = PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));
    sss_sscp_blob_type_t blob_type = {0};

    do
    {
        /* Check for a valid key object */
        if (NULL == sssKey->keyStore)
        {
            status = PSA_ERROR_DOES_NOT_EXIST;
            break;
        }

        /* We may add other locations (blob types) later. For now, only ELKE. */
        if (false == MCUXCLPSADRIVER_IS_S200_KEY_STORAGE_NON_EL2GO(location))
        {
            status = PSA_ERROR_NOT_SUPPORTED;
            break;
        }

        blob_type    = kSSS_blobType_ELKE_blob;
        *data_length = data_size;
        if (sss_sscp_key_store_export_key(&g_ele_ctx.keyStore, sssKey, data, data_length, blob_type) != kStatus_SSS_Success)
        {
            *data_length = 0u;
            status       = PSA_ERROR_HARDWARE_FAILURE;
            break;
        }

        status = PSA_SUCCESS;
    } while (false);

    return status;
}
