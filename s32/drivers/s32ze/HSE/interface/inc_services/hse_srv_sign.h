/**
*   @file    hse_srv_sign.h
*
*   @brief   HSE Digital Signature definition.
*   @details This file contains the Digital Signature service definition.
*
*   @addtogroup hse_srv_sign HSE Digital Signature Service
*   @ingroup class_crypto_services
*   @{
*/
/*==================================================================================================
*
*   Copyright 2019 - 2024 NXP.
*
*   Redistribution and use in source and binary forms, with or without modification,
*   are permitted provided that the following conditions are met:
*
*   1. Redistributions of source code must retain the above copyright notice, this list
*      of conditions and the following disclaimer.
*
*   2. Redistributions in binary form must reproduce the above copyright notice, this
*      list of conditions and the following disclaimer in the documentation and/or
*      other materials provided with the distribution.
*
*   3. Neither the name of the copyright holder nor the names of its
*      contributors may be used to endorse or promote products derived from this
*      software without specific prior written permission.
*
*   This software is owned or controlled by NXP and may only be used strictly in accordance with
*   the applicable license terms. By expressly accepting such terms or by downloading, installing,
*   activating and/or otherwise using the software, you are agreeing that you have read, and that
*   you agree to comply with and are bound by, such license terms. If you do not agree to
*   be bound by the applicable license terms, then you may not retain, install, activate or
*   otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef HSE_SRV_SIGN_H
#define HSE_SRV_SIGN_H


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "hse_common_types.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief          Digital Signature service.
* @details        Uses the input parameters to perform the signature calculation and stores the signature
*                 in the memory location pointed by the output parameter.
*
*                 This service can be accessible in one-pass or streaming (SUF) mode.
*                 In case of streaming mode, three steps (calls) will be used: START, UPDATE, FINISH.
*                 START and FINISH are mandatory; UPDATE is optional.
*                 Not all fields are used by each access mode.
*
*  The table below summarizes which fields are used by each access mode.
*  Unused fields are ignored by the HSE.
*
* |Field \ Mode      | One-pass  | Start | Update  | Finish  |
* |-----------------:|:---------:|:-----:|:-------:|:-------:|
* | accessMode       |     *     |   *   |    *    |    *    |
* | streamId         |           |   *   |    *    |    *    |
* | signScheme       |     *     |   *   |         |         |
* | authDir          |     *     |   *   |         |         |
* | keyHandle        |     *     |   *   |         |         |
* | sgtOption        |     *     |   *   |    *    |    *    |
* | inputLength      |     *     |   *   |    *    |    *    |
* | pInput           |     *     |   *   |    *    |    *    |
* | pSignatureLength |     *     |       |         |    *    |
* | pSignature       |     *     |       |         |    *    |
*/
typedef struct
{
    /** @brief   INPUT: Specifies the access mode: ONE-PASS, START, UPDATE, FINISH. <br>
     *           STREAMING USAGE: Used in all steps.*/
    hseAccessMode_t accessMode;

    /** @brief   INPUT: Specifies the stream to use for START, UPDATE, FINISH access modes. Each interface supports
     *           a limited number of streams per interface, up to #HSE_STREAM_COUNT. <br>
     *           STREAMING USAGE: Used in all steps.*/
    hseStreamId_t   streamId;

    /** @brief   INPUT: Specifies the direction: generate/verify. <br>
     *           STREAMING USAGE: Used in START.*/
    hseAuthDir_t    authDir;

    /** @brief   INPUT: Specifies that the input is already hashed with the algorithm in specified in the sign scheme.
     *                  Not valid for any signing scheme that does not perform prehashing (i.e. PureEDDSA)
     *           @note  The hashing algorithm from signScheme and the input length must be:
     *                  - for RSA scheme:   hashAlgo != HSE_HASH_ALGO_NULL, where the inputLength must be equal to the hash ouput length;
     *                  - for ECDSA scheme: hashAlgo != HSE_HASH_ALGO_NULL, where the inputLength must be equal to the hash ouput length;
     *                                      hashAlgo == HSE_HASH_ALGO_NULL, where the inputLength must be within (0, 64];
     *                  - for EDDSA scheme: hashAlgo is not used and the inputLength should be the output length of the hash associated with the curve;
     *           STREAMING USAGE: Not supported in streaming mode.*/
    bool_t          bInputIsHashed;


    /** @brief   INPUT: Scheme for selected Signature algo. <br>
     *           STREAMING USAGE: Used in START.*/
    hseSignScheme_t signScheme;

    /** @brief   INPUT: The key to be used for the operation. <br>
     *           STREAMING USAGE: Used in START.*/
    hseKeyHandle_t  keyHandle;

    /** @brief  INPUT: Specify if pInput is provided as hseScatterList_t list (the host address points to a hseScatterList_t list).
     *                 Ignored if SGT is not supported.
     *                 @note
     *                 - ONLY HSE_SGT_OPTION_INPUT can be used (the rest of the bits are ignored)
     *                 - Scatter option is supported only for RSA and ECDSA. For EDDSA, it is not supported.
     *                 - Scatter option is not supported for SHA3 hashes (unless the targeted platform has #HSE_SPT_HW_SHA3 defined).
     *                 - Scatter option is not supported for pre-hashed inputs
     *                 - If scatter option is selected (set), the length (e.g. #inputLength) shall specified the entire message length
     *                 (sum of all hseScatterList_t lengths).
     *                 - The number for SGT entries shall be less then #HSE_MAX_NUM_OF_SGT_ENTRIES. <br>
     *          STREAMING USAGE: Used in all steps.*/
    hseSGTOption_t  sgtOption;

    uint8_t         reserved[3U];

    /** @brief   INPUT: The length of the message.
     *                  For RSA schemes, this must be the length of the original (not pre-hashed) input. <br>
     *           STREAMING USAGE: Used in all steps.
     *            - START: Must be a multiple of block length of the hash, or zero.
     *            - UPDATE: Must be a multiple of block length of the hash. Cannot be zero. Refrain from issuing the service request, instead of passing zero.
     *            - FINISH: Can be any value.
     *
     *           Algorithm block lengths:
     *            - SHA1, SHA2_224, SHA2_256: 64
     *            - SHA2_512_224, SHA2_512_256, SHA2_384, SHA2_512: 128
     *            - SHA3-224: 144
     *            - SHA3-256: 136
     *            - SHA3-384: 104
     *            - SHA3-512: 72
     *            - SHA3: If the targeted platform does NOT have #HSE_SPT_HW_SHA3 defined, there is no limitation (input can be any size)
     *           @note EDDSA does not support streaming */
    uint32_t        inputLength;

    /** @brief   INPUT: The address of the message to be signed/verify.
     *                  For RSA schemes, this is the actual (not pre-hashed) input. <br>
     *           STREAMING USAGE: Used in all steps.
     *  @note    If the HOST_ADDR is on 64 bits:
     *              - For PureEDDSA: the address must fall within the 32-bit address range.
     *              - If hash algorithm is not supported in HW (#HSE_SPT_HW_SHA3 macro is not defined) and input is not hashed,
     *                the address must fall within the 32-bit address range. */
    HOST_ADDR       pInput;

    /** @brief   INPUT/OUTPUT: An array of two addresses of two uint32_t values containing signature lengths. It is input/output for "generate" and input for "verify".
     *                         On calling "generate" service, these parameter shall contain the size of the signature buffers provided by the application.
                               When the request has finished, the actual lengths of the signature components. <br>
     *           STREAMING USAGE: Used in FINISH. */
    HOST_ADDR       pSignatureLength[2];

    /** @brief   OUTPUT: Where the signature components must be stored.  It is output for "generate" and input for "verify".
     *                   - RSA has a single signature component, at index 0, and the size of buffer must be at least the byteLength(public modulus n)
     *                   - ECDSA and EDDSA signature format as (r,s), with r at index 0, and s at index 1.
     *                     The buffer size for each component must be at least the length of the used curve in bytes (e.g. 32 bytes for a 256 bit curve).<br>
     *           STREAMING USAGE: Used in FINISH. */
    HOST_ADDR       pSignature[2];
} hseSignSrv_t;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif

#endif /* HSE_SRV_SIGN_H */

/** @} */
