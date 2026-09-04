/*
 * Copyright 2022-2025 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** @file  mcuxClPsaDriver_Oracle_KeyRecipes.h
 *  @brief Key Recipes used in the Oracle code*/

#ifndef _MCUXCLPSADRIVER_ORACLE_KEYRECIPES_
#define _MCUXCLPSADRIVER_ORACLE_KEYRECIPES_

#include <psa/crypto.h>

#include <stdint.h>
#include <stddef.h>
#include "mcuxClPsaDriver_Oracle_Utils.h"

/*****************************************************************************************************************/
/* WARNING: These recipes are here only for compilation success, EL2Go support is not yet done for MIMXRT family */
/*****************************************************************************************************************/


#define NXP_DIE_MK_SK_SLOT          (0x00U)
#define NXP_DIE_EL2GOOEM_MK_SK_SLOT (0x04U)

#define RECIPE_STEP_CREATE_NXP_DIE_KEK_SK                                                                                      \
    {                                                                                                                          \
        .operation = OP_CKDF, .storage = STORAGE_FINAL_KEY,                                                                    \
        .ckdf = {                                                                                                              \
            .source_key_slot           = NXP_DIE_MK_SK_SLOT,                                                                   \
            .target_key_id             = MBEDTLS_NXP_DIE_KEK_SK_ID,                                                            \
            .key_properties.word.value = 0x404000E1u,                                                                          \
            .derivation_data           = {0x89u, 0xb3u, 0xa0u, 0x29u, 0x27u, 0x62u, 0xcbu, 0x04u, 0x96u, 0xcdu, 0xbfu, 0xa9u}, \
        },                                                                                                                     \
    }

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORT_KEK_SK                                                              \
    {                                                                                                              \
        .operation = OP_CKDF, .storage = STORAGE_FINAL_KEY,                                                        \
        .ckdf = {                                                                                                  \
            .source_key_slot           = NXP_DIE_EL2GOOEM_MK_SK_SLOT,                                              \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOIMPORT_KEK_SK_ID,                                    \
            .key_properties.word.value = 0x0u,                                                                     \
            .derivation_data           = {0u}                                                                      \
        },                                                                                                         \
    }

const key_recipe_t recipe_el2goimport_kek_sk = {
    .number_of_steps = 1,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORT_KEK_SK,
        },
};

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORTTFM_KEK_SK                                                           \
    {                                                                                                              \
        .operation = OP_CKDF, .storage = STORAGE_FINAL_KEY,                                                        \
        .ckdf = {                                                                                                  \
            .source_key_slot           = NXP_DIE_EL2GOOEM_MK_SK_SLOT,                                              \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOIMPORTTFM_KEK_SK_ID,                                 \
            .key_properties.word.value = 0x0u,                                                                     \
            .derivation_data           = {0u},                                                                     \
        },                                                                                                         \
    }

const key_recipe_t recipe_el2goimporttfm_kek_sk = {
    .number_of_steps = 1,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORTTFM_KEK_SK,
        },
};

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORT_AUTH_SK                                                             \
    {                                                                                                              \
        .operation = OP_CKDF, .storage = STORAGE_FINAL_KEY,                                                        \
        .ckdf = {                                                                                                  \
            .source_key_slot           = NXP_DIE_EL2GOOEM_MK_SK_SLOT,                                              \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOIMPORT_AUTH_SK_ID,                                   \
            .key_properties.word.value = 0x0u,                                                                     \
            .derivation_data           = {0u},                                                                     \
        },                                                                                                         \
    }

const key_recipe_t recipe_el2goimport_auth_sk = {
    .number_of_steps = 1,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOIMPORT_AUTH_SK,
        },
};

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOCONN_AUTH_PRK_SEED                                                         \
    {                                                                                                              \
        .operation = OP_CKDF, .storage = STORAGE_TEMP_KEY,                                                         \
        .ckdf = {                                                                                                  \
            .source_key_slot           = NXP_DIE_EL2GOPUBLIC_MK_SK_SLOT,                                           \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOCONN_AUTH_PRK_ID,                                    \
            .key_properties.word.value = 0x0u,                                                                     \
            .derivation_data           = {0u},                                                                     \
        },                                                                                                         \
    }

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOCONN_AUTH_PRK                           \
    {                                                                           \
        .operation = OP_KEYGEN, .storage = STORAGE_FINAL_KEY,                   \
        .keygen = {                                                             \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOCONN_AUTH_PRK_ID, \
            .key_properties.word.value = 0x80040001U,                           \
        },                                                                      \
    }

const key_recipe_t recipe_el2goconn_auth_prk = {
    .number_of_steps = 2,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOCONN_AUTH_PRK_SEED,
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOCONN_AUTH_PRK,
        },
};

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOATTEST_AUTH_PRK_SEED                                                       \
    {                                                                                                              \
        .operation = OP_CKDF, .storage = STORAGE_TEMP_KEY,                                                         \
        .ckdf = {                                                                                                  \
            .source_key_slot           = NXP_DIE_EL2GOPUBLIC_MK_SK_SLOT,                                           \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOATTEST_AUTH_PRK_ID,                                  \
            .key_properties.word.value = 0x0u,                                                                     \
            .derivation_data           = {0u},                                                                     \
        },                                                                                                         \
    }

#define RECIPE_STEP_CREATE_NXP_DIE_EL2GOATTEST_AUTH_PRK                           \
    {                                                                             \
        .operation = OP_KEYGEN, .storage = STORAGE_FINAL_KEY,                     \
        .keygen = {                                                               \
            .target_key_id             = MBEDTLS_NXP_DIE_EL2GOATTEST_AUTH_PRK_ID, \
            .key_properties.word.value = 0x80040001U,                             \
        },                                                                        \
    }

const key_recipe_t recipe_el2goattest_auth_prk = {
    .number_of_steps = 2,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOATTEST_AUTH_PRK_SEED,
            RECIPE_STEP_CREATE_NXP_DIE_EL2GOATTEST_AUTH_PRK,
        },
};

const key_recipe_t recipe_die_kek_sk = {
    .number_of_steps = 1,
    .steps =
        {
            RECIPE_STEP_CREATE_NXP_DIE_KEK_SK,
        },
};

const key_recipe_t *key_recipes_directory[] = {&recipe_el2goimport_kek_sk, &recipe_el2goimporttfm_kek_sk, &recipe_el2goimport_auth_sk,
                                               &recipe_el2goconn_auth_prk, &recipe_el2goattest_auth_prk, &recipe_die_kek_sk};

// This value should be changed to the number of elements of key_recipes_directory[] when EL2GO suuport will be added 
size_t key_recipes_directory_size = 0u;

#endif //_MCUXCLPSADRIVER_ORACLE_KEYRECIPES_
