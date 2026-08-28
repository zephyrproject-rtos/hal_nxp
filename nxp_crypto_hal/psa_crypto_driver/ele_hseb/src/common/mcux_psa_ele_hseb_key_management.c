/*
 * Copyright 2025 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "mcux_psa_ele_hseb_translate.h"
#include "mcux_psa_ele_hseb_key_management.h"
#include "hse_host_import_key.h"
#include "hse_keys_allocator.h"

psa_status_t ele_hseb_delete_key(hseKeyHandle_t *key_handle,
                                 hseEraseKeyOptions_t erase_key_options)
{
    hseSrvResponse_t hseb_status_erase = HSE_SRV_RSP_GENERAL_ERROR;
    hseSrvResponse_t hseb_status_free  = HSE_SRV_RSP_GENERAL_ERROR;

    /* Best effort, do both */
    hseb_status_erase = EraseKeyReq(*key_handle, erase_key_options);
    hseb_status_free  = HKF_FreeKeySlot(key_handle);

    /* And if either fails, return error */
    if (HSE_SRV_RSP_OK != hseb_status_erase ||
        HSE_SRV_RSP_OK != hseb_status_free) {
        return PSA_ERROR_GENERIC_ERROR;
    }
    return PSA_SUCCESS;
}
