/*
 *  Functions to delegate cryptographic operations to an available
 *  and appropriate accelerator.
 *  Warning: This file is now auto-generated.
 */
/*  Copyright The Mbed TLS Contributors
 *  SPDX-License-Identifier: Apache-2.0 OR GPL-2.0-or-later
 */


/* BEGIN-common headers */
#include "tf_psa_crypto_common.h"
#include "psa_crypto_aead.h"
#include "psa_crypto_cipher.h"
#include "psa_crypto_core.h"
#include "psa_crypto_driver_wrappers_no_static.h"
#include "psa_crypto_hash.h"
#include "psa_crypto_xof.h"
#include "psa_crypto_mac.h"
#include "psa_crypto_pake.h"
#include "psa_crypto_rsa.h"

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
#include "psa_crypto_mldsa.h"
#endif

#include "mbedtls/platform.h"
#include "mbedtls/constant_time.h"
/* END-common headers */

#if defined(MBEDTLS_PSA_CRYPTO_C)

/* BEGIN-driver headers */
/* Headers for p256 transparent driver */
#if defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED)
#include "../drivers/p256-m/p256-m_driver_entrypoints.h"

#endif
/* Headers for hashcrypt transparent driver */
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
#include "hashcrypt.h"

#endif
/* Headers for casper transparent driver */
#if defined(PSA_CRYPTO_DRIVER_CASPER)
#include "casper.h"

#endif
/* Headers for dcp transparent driver */
#if defined(PSA_CRYPTO_DRIVER_DCP)
#include "dcp.h"

#endif
/* Headers for sgi transparent driver */
#if defined(PSA_CRYPTO_DRIVER_SGI)
#include "sgi.h"

#endif
/* Headers for pkc transparent driver */
#if defined(PSA_CRYPTO_DRIVER_PKC)
#include "pkc.h"

#endif
/* Headers for ele_hseb opaque driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
#include "ele_hseb.h"

#endif
/* Headers for ele_hseb transparent driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
#include "ele_hseb.h"

#endif
/* Headers for caam opaque driver */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
#include "caam.h"

#endif
/* Headers for caam transparent driver */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
#include "caam.h"

#endif
/* Headers for ela_csec transparent driver */
#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
#include "ela_csec.h"

#endif
/* Headers for ele_s2xx transparent driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
#include "ele_s2xx.h"

#endif
/* Headers for ele_s2xx opaque driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
#include "ele_s2xx.h"

#endif
/* Headers for ele_s4xx opaque driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
#include "ele_s4xx.h"

#endif
/* Headers for ele_s4xx transparent driver */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
#include "ele_s4xx.h"

#endif
/* Headers for els_pkc transparent driver */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
#include "els_pkc_driver.h"

#endif

/* END-driver headers */

/* Auto-generated values depending on which drivers are registered.
 * ID 0 is reserved for unallocated operations.
 * ID 1 is reserved for the Mbed TLS software driver. */
/* BEGIN-driver id definition */
#define PSA_CRYPTO_MBED_TLS_DRIVER_ID (1)
#define P256_TRANSPARENT_DRIVER_ID (2)
#define HASHCRYPT_TRANSPARENT_DRIVER_ID (3)
#define CASPER_TRANSPARENT_DRIVER_ID (4)
#define DCP_TRANSPARENT_DRIVER_ID (5)
#define SGI_TRANSPARENT_DRIVER_ID (6)
#define PKC_TRANSPARENT_DRIVER_ID (7)
#define ELE_HSEB_OPAQUE_DRIVER_ID (8)
#define ELE_HSEB_TRANSPARENT_DRIVER_ID (9)
#define CAAM_OPAQUE_DRIVER_ID (10)
#define CAAM_TRANSPARENT_DRIVER_ID (11)
#define ELA_CSEC_TRANSPARENT_DRIVER_ID (12)
#define ELE_S2XX_TRANSPARENT_DRIVER_ID (13)
#define ELE_S2XX_OPAQUE_DRIVER_ID (14)
#define ELE_S4XX_OPAQUE_DRIVER_ID (15)
#define ELE_S4XX_TRANSPARENT_DRIVER_ID (16)
#define ELS_PKC_TRANSPARENT_DRIVER_ID (17)

/* END-driver id */

/* BEGIN-Common Macro definitions */

/* END-Common Macro definitions */

static inline psa_status_t psa_driver_wrapper_init( void )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

#if defined(PSA_CRYPTO_DRIVER_TEST)
    status = mbedtls_test_transparent_init( );
    if( status != PSA_SUCCESS )
        return( status );

    status = mbedtls_test_opaque_init( );
    if( status != PSA_SUCCESS )
        return( status );
#endif

#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
    status = hashcrypt_common_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */

#if defined(PSA_CRYPTO_DRIVER_CASPER)
    status = casper_common_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_CASPER */

#if defined(PSA_CRYPTO_DRIVER_DCP)
    status = dcp_common_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_DCP */
#if defined(PSA_CRYPTO_DRIVER_SGI)
    status = psa_sgi_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */

#if defined(PSA_CRYPTO_DRIVER_PKC)
    status = psa_pkc_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_PKC */

#if defined(PSA_CRYPTO_DRIVER_CAAM)
    status = caam_common_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif

#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
    status = ele_s2xx_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
    status = ele_s4xx_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );

    status = ele_s4xx_opaque_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
    status = els_pkc_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */

#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
    status = ela_csec_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */

#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
    status = ele_hseb_transparent_init();
    if (status != PSA_SUCCESS)
        return ( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

    (void) status;
    return( PSA_SUCCESS );
}

static inline void psa_driver_wrapper_free( void )
{
#if defined(PSA_CRYPTO_DRIVER_TEST)
    mbedtls_test_transparent_free( );
    mbedtls_test_opaque_free( );
#endif
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
    (void)ele_s4xx_transparent_free();
    (void)ele_s4xx_opaque_free();
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
    (void)hashcrypt_common_free();
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */

#if defined(PSA_CRYPTO_DRIVER_CASPER)
    (void)casper_common_free();
#endif /* PSA_CRYPTO_DRIVER_CASPER */

#if defined(PSA_CRYPTO_DRIVER_DCP)
    (void)dcp_common_free();
#endif /* PSA_CRYPTO_DRIVER_DCP */

#if defined(PSA_CRYPTO_DRIVER_SGI)
    (void)psa_sgi_transparent_free();
#endif /* PSA_CRYPTO_DRIVER_SGI */

#if defined(PSA_CRYPTO_DRIVER_PKC)
    (void)psa_pkc_deinit();
#endif /* PSA_CRYPTO_DRIVER_PKC */

#if defined(PSA_CRYPTO_DRIVER_CAAM)
    (void)caam_common_free();
#endif /* PSA_CRYPTO_DRIVER_CAAM */

#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
    (void)ele_s2xx_transparent_free();
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */

#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
    (void)els_pkc_transparent_free();
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */

#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
    (void)ela_csec_transparent_free();
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */

#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
    (void)ele_hseb_transparent_free();
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
}

/* Start delegation functions */
static inline psa_status_t psa_driver_wrapper_sign_message(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *signature,
    size_t signature_size,
    size_t *signature_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_signature_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_sign_message(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
            if (PSA_ALG_IS_ML_DSA(alg)) {
                status = tf_psa_crypto_mldsa_sign_message(
                            attributes,
                            key_buffer, key_buffer_size,
                            alg,
                            input, input_length,
                            signature, signature_size, signature_length);
                return status;
            }
#endif

            break;

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_signature_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_asymmetric_sign_message((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            status = ele_hseb_opaque_sign_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            break;
    }

    return( psa_sign_message_builtin( attributes,
                                      key_buffer,
                                      key_buffer_size,
                                      alg,
                                      input,
                                      input_length,
                                      signature,
                                      signature_size,
                                      signature_length ) );
}

static inline psa_status_t psa_driver_wrapper_sign_setup(
    psa_sign_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
            status = mbedtls_test_transparent_sign_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
            if( PSA_KEY_TYPE_IS_ML_DSA( psa_get_key_type( attributes ) ) )
            {
                status = tf_psa_crypto_mldsa_sign_setup( &operation->ctx.pqcp,
                                                         attributes,
                                                         key_buffer, key_buffer_size,
                                                         alg );
                if( status == PSA_SUCCESS )
                    operation->id = PQCP_TRANSPARENT_DRIVER_ID;
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    return( status );
            }
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_sign_setup( &operation->ctx.mbedtls_ctx,
                                             attributes,
                                             key_buffer, key_buffer_size,
                                             alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_signature_sign_setup(
                &operation->ctx.opaque_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void) status;
            (void) operation;
            (void) key_buffer;
            (void) key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_sign_set_context(
    psa_sign_operation_t *operation,
    const uint8_t *context, size_t context_length )
{
    switch( operation->id )
    {
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_sign_set_context(
                        &operation->ctx.test_driver_ctx,
                        context, context_length ) );
#endif
        default:
            (void) context;
            (void) context_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_sign_update(
    psa_sign_operation_t *operation,
    const uint8_t *input, size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_sign_update( &operation->ctx.mbedtls_ctx,
                                             input, input_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_update( &operation->ctx.pqcp,
                                                input, input_length ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_signature_sign_update(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_sign_update(
                        &operation->ctx.opaque_test_driver_ctx,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) input;
            (void) input_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_sign_finish(
    psa_sign_operation_t *operation,
    const uint8_t *key_buffer, size_t key_buffer_size,
    uint8_t *signature,  size_t signature_size,
    size_t *signature_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_sign_finish( &operation->ctx.mbedtls_ctx,
                                             key_buffer, key_buffer_size,
                                             signature, signature_size,
                                             signature_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_sign_finish( &operation->ctx.pqcp,
                                                     key_buffer, key_buffer_size,
                                                     signature, signature_size,
                                                     signature_length ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_sign_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        key_buffer, key_buffer_size,
                        signature, signature_size, signature_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_sign_finish(
                        &operation->ctx.opaque_test_driver_ctx,
                        key_buffer, key_buffer_size,
                        signature, signature_size, signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) key_buffer;
            (void) key_buffer_size;
            (void) signature;
            (void) signature_size;
            (void) signature_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_sign_abort(
    psa_sign_operation_t *operation )
{
    switch( operation->id )
    {
        case 0:
            return( PSA_SUCCESS );
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_sign_abort( &operation->ctx.mbedtls_ctx ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_abort( &operation->ctx.pqcp ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_sign_abort(
                        &operation->ctx.transparent_test_driver_ctx ) );
        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_sign_abort(
                        &operation->ctx.opaque_test_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_message(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    const uint8_t *signature,
    size_t signature_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_signature_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_verify_message(
                        MCUX_PSA_CAAM_KEY_TYPE_NONE,
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
            if (PSA_ALG_IS_ML_DSA(alg)) {
                status = tf_psa_crypto_mldsa_verify_message(
                            attributes,
                            key_buffer, key_buffer_size,
                            alg,
                            input, input_length,
                            signature, signature_length);
                return status;
            }
#endif

            break;

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_signature_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length ) );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return (caam_common_asymmetric_verify_message(
                        (mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length ) );
            /* Below code is unreachable */
//            if( status != PSA_ERROR_NOT_SUPPORTED )
//                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            return( ele_s4xx_opaque_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length ) );
            /* Below code is unreachable - fix by example of psa_driver_wrapper_sign_message()
               and test functionality. */
//            if( status != PSA_ERROR_NOT_SUPPORTED )
//                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return( ele_s2xx_opaque_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length ) );
            /* Below code is unreachable */
//            if( status != PSA_ERROR_NOT_SUPPORTED )
//                return( status );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            return (ele_hseb_opaque_verify_message(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        input,
                        input_length,
                        signature,
                        signature_length ) );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            break;
    }

    return( psa_verify_message_builtin( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        input,
                                        input_length,
                                        signature,
                                        signature_length ) );
}

static inline psa_status_t psa_driver_wrapper_verify_setup(
    psa_verify_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
            status = mbedtls_test_transparent_verify_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
            if( PSA_KEY_TYPE_IS_ML_DSA( psa_get_key_type( attributes ) ) )
            {
                status = tf_psa_crypto_mldsa_verify_setup( &operation->ctx.pqcp,
                                                           attributes,
                                                           key_buffer, key_buffer_size,
                                                           alg );
                if( status == PSA_SUCCESS )
                    operation->id = PQCP_TRANSPARENT_DRIVER_ID;
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    return( status );
            }
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_verify_setup( &operation->ctx.mbedtls_ctx,
                                               attributes,
                                               key_buffer, key_buffer_size,
                                               alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_signature_verify_setup(
                &operation->ctx.opaque_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void) status;
            (void) operation;
            (void) key_buffer;
            (void) key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_set_context(
    psa_verify_operation_t *operation,
    const uint8_t *context, size_t context_length )
{
    switch( operation->id )
    {
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_verify_set_context(
                        &operation->ctx.test_driver_ctx,
                        context, context_length ) );
#endif
        default:
            (void) context;
            (void) context_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_update(
    psa_verify_operation_t *operation,
    const uint8_t *input, size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_verify_update( &operation->ctx.mbedtls_ctx,
                                               input, input_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_update( &operation->ctx.pqcp,
                                                input, input_length ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_signature_verify_update(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_verify_update(
                        &operation->ctx.opaque_test_driver_ctx,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) input;
            (void) input_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_finish(
    psa_verify_operation_t *operation,
    const uint8_t *key_buffer, size_t key_buffer_size,
    const uint8_t *signature, size_t signature_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_verify_finish( &operation->ctx.mbedtls_ctx,
                                               key_buffer, key_buffer_size,
                                               signature, signature_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_verify_finish( &operation->ctx.pqcp,
                                                       key_buffer, key_buffer_size,
                                                       signature, signature_length ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_verify_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        key_buffer, key_buffer_size,
                        signature, signature_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_verify_finish(
                        &operation->ctx.opaque_test_driver_ctx,
                        key_buffer, key_buffer_size,
                        signature, signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) key_buffer;
            (void) key_buffer_size;
            (void) signature;
            (void) signature_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_abort(
    psa_verify_operation_t *operation )
{
    switch( operation->id )
    {
        case 0:
            return( PSA_SUCCESS );
#if defined(MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_verify_abort( &operation->ctx.mbedtls_ctx ) );
#endif /* MBEDTLS_PSA_BUILTIN_SIGNATURE_MULTIPART */

#if defined(TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED)
        case PQCP_TRANSPARENT_DRIVER_ID:
            return( tf_psa_crypto_mldsa_abort( &operation->ctx.pqcp ) );
#endif /* TF_PSA_CRYPTO_PQCP_MLDSA_ENABLED */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST) && 0 /*not implemented yet*/
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_signature_verify_abort(
                        &operation->ctx.transparent_test_driver_ctx ) );
        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_signature_verify_abort(
                        &operation->ctx.opaque_test_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_sign_hash(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg, const uint8_t *hash, size_t hash_length,
    uint8_t *signature, size_t signature_size, size_t *signature_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_signature_sign_hash( attributes,
                                                           key_buffer,
                                                           key_buffer_size,
                                                           alg,
                                                           hash,
                                                           hash_length,
                                                           signature,
                                                           signature_size,
                                                           signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined (MBEDTLS_PSA_P256M_DRIVER_ENABLED)
            if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                PSA_ALG_IS_RANDOMIZED_ECDSA(alg) &&
                PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                psa_get_key_bits(attributes) == 256 )
            {
                status = p256_transparent_sign_hash( attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     hash,
                                                     hash_length,
                                                     signature,
                                                     signature_size,
                                                     signature_length );
                if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            }
#endif /* MBEDTLS_PSA_P256M_DRIVER_ENABLED */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_sign_hash(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        hash,
                        hash_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_CASPER)
            if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                PSA_ALG_IS_ECDSA(alg) &&
                PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                (
                    psa_get_key_bits(attributes) == 256 ||
                    psa_get_key_bits(attributes) == 384 ||
                    psa_get_key_bits(attributes) == 521
                )
                )
            {
                status = casper_common_asymmetric_sign_hash(
                            attributes,
                            key_buffer,
                            key_buffer_size,
                            alg,
                            hash,
                            hash_length,
                            signature,
                            signature_size,
                            signature_length );
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    return( status );
            }
#endif /* PSA_CRYPTO_DRIVER_CASPER */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_sign_hash( attributes,
                                    key_buffer,
                                    key_buffer_size,
                                    alg,
                                    hash,
                                    hash_length,
                                    signature,
                                    signature_size,
                                    signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_PKC)
            status = pkc_sign_hash( attributes,
                                    key_buffer,
                                    key_buffer_size,
                                    alg,
                                    hash,
                                    hash_length,
                                    signature,
                                    signature_size,
                                    signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_PKC */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_sign_hash(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        hash,
                        hash_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_sign_hash(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        hash,
                        hash_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_sign_hash(
                        attributes,
                        key_buffer,
                        key_buffer_size,
                        alg,
                        hash,
                        hash_length,
                        signature,
                        signature_size,
                        signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
            /* Fell through, meaning no accelerator supports this operation */
            return( psa_sign_hash_builtin( attributes,
                                           key_buffer,
                                           key_buffer_size,
                                           alg,
                                           hash,
                                           hash_length,
                                           signature,
                                           signature_size,
                                           signature_length ) );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_signature_sign_hash( attributes,
                                                             key_buffer,
                                                             key_buffer_size,
                                                             alg,
                                                             hash,
                                                             hash_length,
                                                             signature,
                                                             signature_size,
                                                             signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return (caam_common_asymmetric_sign_hash((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE, attributes,
                                            key_buffer,
                                            key_buffer_size,
                                            alg,
                                            hash,
                                            hash_length,
                                            signature,
                                            signature_size,
                                            signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            return( ele_s4xx_opaque_sign_hash( attributes,
                                               key_buffer,
                                               key_buffer_size,
                                               alg,
                                               hash,
                                               hash_length,
                                               signature,
                                               signature_size,
                                               signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return( ele_s2xx_opaque_sign_hash( attributes,
                                               key_buffer,
                                               key_buffer_size,
                                               alg,
                                               hash,
                                               hash_length,
                                               signature,
                                               signature_size,
                                               signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            return( ele_hseb_opaque_sign_hash( attributes,
                                   key_buffer,
                                   key_buffer_size,
                                   alg,
                                   hash,
                                   hash_length,
                                   signature,
                                   signature_size,
                                   signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_verify_hash(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg, const uint8_t *hash, size_t hash_length,
    const uint8_t *signature, size_t signature_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_signature_verify_hash(
                         attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         hash,
                         hash_length,
                         signature,
                         signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined (MBEDTLS_PSA_P256M_DRIVER_ENABLED)
            if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                PSA_ALG_IS_ECDSA(alg) &&
                PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                psa_get_key_bits(attributes) == 256 )
            {
                status = p256_transparent_verify_hash( attributes,
                                                       key_buffer,
                                                       key_buffer_size,
                                                       alg,
                                                       hash,
                                                       hash_length,
                                                       signature,
                                                       signature_length );
                if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
            }
#endif /* MBEDTLS_PSA_P256M_DRIVER_ENABLED */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_verify_hash(
                         attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         hash,
                         hash_length,
                         signature,
                         signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_CASPER)
            if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                PSA_ALG_IS_ECDSA(alg) &&
                PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                (
                    psa_get_key_bits(attributes) == 256 ||
                    psa_get_key_bits(attributes) == 384 ||
                    psa_get_key_bits(attributes) == 521
                )
                )
            {
                status = casper_common_asymmetric_verify_hash(
                            attributes,
                            key_buffer,
                            key_buffer_size,
                            alg,
                            hash,
                            hash_length,
                            signature,
                            signature_length );
                /* Declared with fallback == true */
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    return( status );
            }
#endif /* PSA_CRYPTO_DRIVER_CASPER */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_verify_hash( attributes,
                                      key_buffer,
                                      key_buffer_size,
                                      alg,
                                      hash,
                                      hash_length,
                                      signature,
                                      signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_PKC)
            status = pkc_verify_hash( attributes,
                                      key_buffer,
                                      key_buffer_size,
                                      alg,
                                      hash,
                                      hash_length,
                                      signature,
                                      signature_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_PKC */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_verify_hash(
                        MCUX_PSA_CAAM_KEY_TYPE_NONE,
                         attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         hash,
                         hash_length,
                         signature,
                         signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_verify_hash(
                         attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         hash,
                         hash_length,
                         signature,
                         signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_verify_hash(
                         attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         hash,
                         hash_length,
                         signature,
                         signature_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            return( psa_verify_hash_builtin( attributes,
                                             key_buffer,
                                             key_buffer_size,
                                             alg,
                                             hash,
                                             hash_length,
                                             signature,
                                             signature_length ) );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_signature_verify_hash( attributes,
                                                               key_buffer,
                                                               key_buffer_size,
                                                               alg,
                                                               hash,
                                                               hash_length,
                                                               signature,
                                                               signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return (caam_common_asymmetric_verify_hash( (mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                                                 attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 alg,
                                                 hash,
                                                 hash_length,
                                                 signature,
                                                 signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            return( ele_s4xx_opaque_verify_hash( attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 alg,
                                                 hash,
                                                 hash_length,
                                                 signature,
                                                 signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return( ele_s2xx_opaque_verify_hash( attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 alg,
                                                 hash,
                                                 hash_length,
                                                 signature,
                                                 signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            return( ele_hseb_opaque_verify_hash( attributes,
                                     key_buffer,
                                     key_buffer_size,
                                     alg,
                                     hash,
                                     hash_length,
                                     signature,
                                     signature_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline uint32_t psa_driver_wrapper_sign_hash_get_num_ops(
    psa_sign_hash_interruptible_operation_t *operation )
{
    switch( operation->id )
    {
        /* If uninitialised, return 0, as no work can have been done. */
        case 0:
            return 0;

        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return(mbedtls_psa_sign_hash_get_num_ops(&operation->ctx.mbedtls_ctx));

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    /* Can't happen (see discussion in #8271) */
    return 0;
}

static inline uint32_t psa_driver_wrapper_verify_hash_get_num_ops(
    psa_verify_hash_interruptible_operation_t *operation )
{
    switch( operation->id )
    {
        /* If uninitialised, return 0, as no work can have been done. */
        case 0:
            return 0;

        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return (mbedtls_psa_verify_hash_get_num_ops(&operation->ctx.mbedtls_ctx));

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

    }

    /* Can't happen (see discussion in #8271) */
    return 0;
}

static inline psa_status_t psa_driver_wrapper_sign_hash_start(
    psa_sign_hash_interruptible_operation_t *operation,
    const psa_key_attributes_t *attributes, const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *hash, size_t hash_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(
                                                    psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)

            /* Add test driver tests here */

            /* Declared with fallback == true */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
            operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            status = mbedtls_psa_sign_hash_start( &operation->ctx.mbedtls_ctx,
                                                  attributes,
                                                  key_buffer, key_buffer_size,
                                                  alg, hash, hash_length );
            break;

            /* Add cases for opaque driver here */

        default:
            /* Key is declared with a lifetime not known to us */
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
    }

    return( status );
}

static inline psa_status_t psa_driver_wrapper_sign_hash_complete(
    psa_sign_hash_interruptible_operation_t *operation,
    uint8_t *signature, size_t signature_size,
    size_t *signature_length )
{
    switch( operation->id )
    {
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_sign_hash_complete( &operation->ctx.mbedtls_ctx,
                                                    signature, signature_size,
                                                    signature_length ) );

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    ( void ) signature;
    ( void ) signature_size;
    ( void ) signature_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_sign_hash_abort(
    psa_sign_hash_interruptible_operation_t *operation )
{
    switch( operation->id )
    {
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_sign_hash_abort( &operation->ctx.mbedtls_ctx ) );

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_verify_hash_start(
    psa_verify_hash_interruptible_operation_t *operation,
    const psa_key_attributes_t *attributes, const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg,
    const uint8_t *hash, size_t hash_length,
    const uint8_t *signature, size_t signature_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(
                                                    psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)

            /* Add test driver tests here */

            /* Declared with fallback == true */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
            operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            status = mbedtls_psa_verify_hash_start( &operation->ctx.mbedtls_ctx,
                                                    attributes,
                                                    key_buffer, key_buffer_size,
                                                    alg, hash, hash_length,
                                                    signature, signature_length );
            break;

            /* Add cases for opaque driver here */

        default:
            /* Key is declared with a lifetime not known to us */
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
    }

    return( status );
}

static inline psa_status_t psa_driver_wrapper_verify_hash_complete(
    psa_verify_hash_interruptible_operation_t *operation )
{
    switch( operation->id )
    {
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_verify_hash_complete(
                                                     &operation->ctx.mbedtls_ctx
                                                     ) );

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_verify_hash_abort(
    psa_verify_hash_interruptible_operation_t *operation )
{
    switch( operation->id )
    {
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_verify_hash_abort( &operation->ctx.mbedtls_ctx
                                                 ) );

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            /* Add test driver tests here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    return( PSA_ERROR_INVALID_ARGUMENT );
}

/** Calculate the key buffer size required to store the key material of a key
 *  associated with an opaque driver from input key data.
 *
 * \param[in] attributes        The key attributes
 * \param[in] data              The input key data.
 * \param[in] data_length       The input data length.
 * \param[out] key_buffer_size  Minimum buffer size to contain the key material.
 *
 * \retval #PSA_SUCCESS \emptydescription
 * \retval #PSA_ERROR_INVALID_ARGUMENT \emptydescription
 * \retval #PSA_ERROR_NOT_SUPPORTED \emptydescription
 */
static inline psa_status_t psa_driver_wrapper_get_key_buffer_size_from_key_data(
    const psa_key_attributes_t *attributes,
    const uint8_t *data,
    size_t data_length,
    size_t *key_buffer_size )
{
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );
    psa_key_type_t key_type = psa_get_key_type(attributes);

    *key_buffer_size = 0;
    switch( location )
    {
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            *key_buffer_size = mbedtls_test_opaque_size_function( key_type,
                                     PSA_BYTES_TO_BITS( data_length ) );
            return( ( *key_buffer_size != 0 ) ?
                    PSA_SUCCESS : PSA_ERROR_NOT_SUPPORTED );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
        case PSA_CRYPTO_LOCATION_S200_DATA_STORAGE:
            *key_buffer_size = ele_s2xx_opaque_size_function( attributes,
                                                 data,
                                                 data_length);
            return( ( *key_buffer_size != 0 ) ?
                    PSA_SUCCESS : PSA_ERROR_NOT_SUPPORTED );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            *key_buffer_size = ele_hseb_opaque_size_function( attributes,
                                                 data,
                                                 data_length);
            return( ( *key_buffer_size != 0 ) ?
                    PSA_SUCCESS : PSA_ERROR_NOT_SUPPORTED );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

        default:
            (void)key_type;
            (void)data;
            (void)data_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_generate_key(
    const psa_key_attributes_t *attributes,
    const psa_custom_key_parameters_t *custom,
    const uint8_t *custom_data, size_t custom_data_length,
    uint8_t *key_buffer, size_t key_buffer_size, size_t *key_buffer_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

#if defined(PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_GENERATE)
    int is_default_production =
        psa_custom_key_parameters_are_default(custom, custom_data_length);
    if( location != PSA_KEY_LOCATION_LOCAL_STORAGE && !is_default_production )
    {
        /* We don't support passing custom production parameters
         * to drivers yet. */
        return PSA_ERROR_NOT_SUPPORTED;
    }
#else
    int is_default_production = 1;
    (void) is_default_production;
#endif

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
            /* Transparent drivers are limited to generating asymmetric keys. */
            /* We don't support passing custom production parameters
             * to drivers yet. */
            if( PSA_KEY_TYPE_IS_ASYMMETRIC( psa_get_key_type(attributes) ) &&
                is_default_production )
            {
            /* Cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_DRIVER_TEST)
                status = mbedtls_test_transparent_generate_key(
                    attributes, key_buffer, key_buffer_size,
                    key_buffer_length );
                /* Declared with fallback == true */
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    break;
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED)
                if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                    psa_get_key_type(attributes) == PSA_KEY_TYPE_ECC_KEY_PAIR(PSA_ECC_FAMILY_SECP_R1) &&
                    psa_get_key_bits(attributes) == 256 )
                {
                    status = p256_transparent_generate_key( attributes,
                                                            key_buffer,
                                                            key_buffer_size,
                                                            key_buffer_length );
                    if( status != PSA_ERROR_NOT_SUPPORTED )
                        break;
                }

#endif /* MBEDTLS_PSA_P256M_DRIVER_ENABLED */
#if defined(PSA_CRYPTO_DRIVER_CASPER)
                if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                    PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                    (
                        psa_get_key_bits(attributes) == 256 ||
                        psa_get_key_bits(attributes) == 384 ||
                        psa_get_key_bits(attributes) == 521
                    )
                    )
                {
                    status = casper_mbedtls_psa_ecp_generate_key(
                        attributes, key_buffer, key_buffer_size,
                        key_buffer_length );
                    /* Declared with fallback == true */
                    if( status != PSA_ERROR_NOT_SUPPORTED )
                        break;
                }
#endif /* PSA_CRYPTO_DRIVER_CASPER */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
                status = els_pkc_transparent_generate_key( attributes, key_buffer, key_buffer_size,
                                           key_buffer_length );
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    break;
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_PKC)
                status = pkc_generate_key( attributes, key_buffer, key_buffer_size,
                                           key_buffer_length );
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    break;
#endif /* PSA_CRYPTO_DRIVER_PKC */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
                status = caam_common_generate_key(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                    attributes, key_buffer, key_buffer_size,
                    key_buffer_length );
                /* Declared with fallback == true */
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
                status = ele_s2xx_transparent_generate_key(
                    attributes, key_buffer, key_buffer_size,
                    key_buffer_length );
                /* Declared with fallback == true */
                if( status != PSA_ERROR_NOT_SUPPORTED )
                    break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
            }
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Software fallback */
            status = psa_generate_key_internal(
                attributes, custom, custom_data, custom_data_length,
                key_buffer, key_buffer_size, key_buffer_length );
            break;

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_generate_key(
                attributes, key_buffer, key_buffer_size, key_buffer_length );
            break;
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_generate_key((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                attributes, key_buffer, key_buffer_size, key_buffer_length );
            break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
    case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_generate_key(
                attributes, key_buffer, key_buffer_size, key_buffer_length );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_generate_key(
                attributes, key_buffer, key_buffer_size, key_buffer_length );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            status = ele_hseb_opaque_generate_key(
                attributes, key_buffer, key_buffer_size, key_buffer_length );
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            status = PSA_ERROR_INVALID_ARGUMENT;
            break;
    }

    return( status );
}

/* This is a temporary placeholder for destroy till full stateful destroy is added in upstream */
static inline psa_status_t psa_driver_wrapper_destroy_key(
    const psa_key_attributes_t *attributes,
    uint8_t *key_buffer, size_t key_buffer_size)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION(psa_get_key_lifetime(attributes));

    switch( location )
    {
        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_destroy_key(
                attributes, key_buffer, key_buffer_size);
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case PSA_CRYPTO_ELS_PKC_LOCATION_S50_ENC_STORAGE_KEY:
        case PSA_CRYPTO_ELS_PKC_LOCATION_S50_ENC_STORAGE_DATA:
        case PSA_CRYPTO_ELS_PKC_LOCATION_S50_BLOB_STORAGE:
        case PSA_CRYPTO_ELS_PKC_LOCATION_S50_KEY_GEN_STORAGE:
        case PSA_CRYPTO_ELS_PKC_LOCATION_S50_RFC3394_STORAGE:
            status = els_pkc_opaque_destroy_key(
                attributes, key_buffer, key_buffer_size);
            break;
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_destroy_key(
                attributes, key_buffer, key_buffer_size);
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_destroy_key(
                attributes, key_buffer, key_buffer_size);
            break;
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            status = ele_hseb_opaque_destroy_key(
                attributes, key_buffer, key_buffer_size);
            break;
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        /* Drivers which may not have any state to change for destruction of key */
        default:
            (void)key_buffer;
            (void)key_buffer_size;
            status = PSA_SUCCESS;
            break;
    }

    return( status );
}

static inline psa_status_t psa_driver_wrapper_import_key(
    const psa_key_attributes_t *attributes,
    const uint8_t *data,
    size_t data_length,
    uint8_t *key_buffer,
    size_t key_buffer_size,
    size_t *key_buffer_length,
    size_t *bits )
{

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(
                                      psa_get_key_lifetime( attributes ) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)

#if (defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED) )
            status = p256_transparent_import_key
                (attributes,
                                data,
                                data_length,
                                key_buffer,
                                key_buffer_size,
                                key_buffer_length,
                                bits
            );

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif













#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
            return( psa_import_key_into_slot( attributes,
                                              data, data_length,
                                              key_buffer, key_buffer_size,
                                              key_buffer_length, bits ) );
        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)






#if (defined(PSA_CRYPTO_DRIVER_ELE_S2XX) )
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
        case PSA_CRYPTO_LOCATION_S200_DATA_STORAGE:
            return( ele_s2xx_opaque_import_key
            (attributes,
                            data,
                            data_length,
                            key_buffer,
                            key_buffer_size,
                            key_buffer_length,
                            bits
        ));
#endif  /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case PSA_KEY_LOCATION_ELE_HSEB:
            return( ele_hseb_opaque_import_key(
                            attributes,
                            data,
                            data_length,
                            key_buffer,
                            key_buffer_size,
                            key_buffer_length,
                            bits
        ));
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void)status;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }

}

static inline psa_status_t psa_driver_wrapper_export_key(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    uint8_t *data, size_t data_size, size_t *data_length )

{

    psa_status_t status = PSA_ERROR_INVALID_ARGUMENT;
    psa_key_location_t location = PSA_KEY_LIFETIME_GET_LOCATION(
                                      psa_get_key_lifetime( attributes ) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            return( psa_export_key_internal( attributes,
                                             key_buffer,
                                             key_buffer_size,
                                             data,
                                             data_size,
                                             data_length ) );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)






#if (defined(PSA_CRYPTO_DRIVER_ELE_S2XX) )
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
        case PSA_CRYPTO_LOCATION_S200_DATA_STORAGE:
            return( ele_s2xx_opaque_export_key
            (attributes,
                            key_buffer,
                            key_buffer_size,
                            data,
                            data_size,
                            data_length
        ));
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            return( status );
    }

}

static inline psa_status_t psa_driver_wrapper_copy_key(
    psa_key_attributes_t *attributes,
    const uint8_t *source_key, size_t source_key_length,
    uint8_t *target_key_buffer, size_t target_key_buffer_size,
    size_t *target_key_buffer_length )
{

    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)






#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return( ele_s2xx_opaque_copy_key
            (attributes,
                            source_key,
                            source_key_length,
                            target_key_buffer,
                            target_key_buffer_size,
                            target_key_buffer_length
        ));
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void)source_key;
            (void)source_key_length;
            (void)target_key_buffer;
            (void)target_key_buffer_size;
            (void)target_key_buffer_length;
            status = PSA_ERROR_INVALID_ARGUMENT;
    }
    return( status );

}

/*
 * Cipher functions
 */
static inline psa_status_t psa_driver_wrapper_cipher_encrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *iv,
    size_t iv_length,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_cipher_encrypt( attributes,
                                                              key_buffer,
                                                              key_buffer_size,
                                                              alg,
                                                              iv,
                                                              iv_length,
                                                              input,
                                                              input_length,
                                                              output,
                                                              output_size,
                                                              output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)                           //NXP ELE --- BEGIN ---
            status = ele_s4xx_transparent_cipher_encrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
            status = hashcrypt_cipher_encrypt( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        iv,
                                        iv_length,
                                        input,
                                        input_length,
                                        output,
                                        output_size,
                                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP)
            status = dcp_cipher_encrypt( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        iv,
                                        iv_length,
                                        input,
                                        input_length,
                                        output,
                                        output_size,
                                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_DCP */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_transparent_cipher_encrypt( attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     iv,
                                                     iv_length,
                                                     input,
                                                     input_length,
                                                     output,
                                                     output_size,
                                                     output_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_cipher_encrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                                         attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_cipher_encrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_cipher_encrypt( attributes,
                                                         key_buffer,
                                                         key_buffer_size,
                                                         alg,
                                                         iv,
                                                         iv_length,
                                                         input,
                                                         input_length,
                                                         output,
                                                         output_size,
                                                         output_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
            status = ela_csec_transparent_cipher_encrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_cipher_encrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
            return( mbedtls_psa_cipher_encrypt( attributes,
                                                key_buffer,
                                                key_buffer_size,
                                                alg,
                                                iv,
                                                iv_length,
                                                input,
                                                input_length,
                                                output,
                                                output_size,
                                                output_length ) );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_cipher_encrypt( attributes,
                                                        key_buffer,
                                                        key_buffer_size,
                                                        alg,
                                                        iv,
                                                        iv_length,
                                                        input,
                                                        input_length,
                                                        output,
                                                        output_size,
                                                        output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return (caam_common_cipher_encrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE, attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            return (ele_s4xx_opaque_cipher_encrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         iv,
                                         iv_length,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length ) );

#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return ( ele_s2xx_opaque_cipher_encrypt( attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     iv,
                                                     iv_length,
                                                     input,
                                                     input_length,
                                                     output,
                                                     output_size,
                                                     output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            (void)iv;
            (void)iv_length;
            (void)input;
            (void)input_length;
            (void)output;
            (void)output_size;
            (void)output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_cipher_decrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_cipher_decrypt( attributes,
                                                              key_buffer,
                                                              key_buffer_size,
                                                              alg,
                                                              input,
                                                              input_length,
                                                              output,
                                                              output_size,
                                                              output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_cipher_decrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
            status = hashcrypt_cipher_decrypt( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        input,
                                        input_length,
                                        output,
                                        output_size,
                                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP)
            status = dcp_cipher_decrypt( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        input,
                                        input_length,
                                        output,
                                        output_size,
                                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_DCP */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_transparent_cipher_decrypt( attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     input,
                                                     input_length,
                                                     output,
                                                     output_size,
                                                     output_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_cipher_decrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                                         attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_cipher_decrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_cipher_decrypt( attributes,
                                                         key_buffer,
                                                         key_buffer_size,
                                                         alg,
                                                         input,
                                                         input_length,
                                                         output,
                                                         output_size,
                                                         output_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
            status = ela_csec_transparent_cipher_decrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_cipher_decrypt( attributes,
                                         key_buffer,
                                         key_buffer_size,
                                         alg,
                                         input,
                                         input_length,
                                         output,
                                         output_size,
                                         output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
            return( mbedtls_psa_cipher_decrypt( attributes,
                                                key_buffer,
                                                key_buffer_size,
                                                alg,
                                                input,
                                                input_length,
                                                output,
                                                output_size,
                                                output_length ) );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_cipher_decrypt( attributes,
                                                        key_buffer,
                                                        key_buffer_size,
                                                        alg,
                                                        input,
                                                        input_length,
                                                        output,
                                                        output_size,
                                                        output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return (caam_common_cipher_decrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE, attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     input,
                                                     input_length,
                                                     output,
                                                     output_size,
                                                     output_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
         case PSA_CRYPTO_ELE_S4XX_LOCATION:
           return ( ele_s4xx_opaque_cipher_decrypt( attributes,
                                                     key_buffer,
                                                     key_buffer_size,
                                                     alg,
                                                     input,
                                                     input_length,
                                                     output,
                                                     output_size,
                                                     output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
           return ( ele_s2xx_opaque_cipher_decrypt( attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    alg,
                                                    input,
                                                    input_length,
                                                    output,
                                                    output_size,
                                                    output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            (void)input;
            (void)input_length;
            (void)output;
            (void)output_size;
            (void)output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_cipher_encrypt_setup(
    psa_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_cipher_encrypt_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_transparent_cipher_encrypt_setup(
                &operation->ctx.sgi_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            if( status == PSA_SUCCESS )
                operation->id = SGI_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_cipher_encrypt_setup(
                &operation->ctx.els_pkc_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            if( status == PSA_SUCCESS )
                operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_cipher_encrypt_setup(
                &operation->ctx.transparent_ele_hseb_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_cipher_encrypt_setup( &operation->ctx.mbedtls_ctx,
                                                       attributes,
                                                       key_buffer,
                                                       key_buffer_size,
                                                       alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_cipher_encrypt_setup(
                &operation->ctx.opaque_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)operation;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_cipher_decrypt_setup(
    psa_cipher_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_INVALID_ARGUMENT;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_cipher_decrypt_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_transparent_cipher_decrypt_setup(
                &operation->ctx.sgi_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            if( status == PSA_SUCCESS )
                operation->id = SGI_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_cipher_decrypt_setup(
                &operation->ctx.els_pkc_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            if( status == PSA_SUCCESS )
                operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_cipher_decrypt_setup(
                &operation->ctx.transparent_ele_hseb_driver_ctx,
                attributes,
                key_buffer,
                key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_cipher_decrypt_setup( &operation->ctx.mbedtls_ctx,
                                                       attributes,
                                                       key_buffer,
                                                       key_buffer_size,
                                                       alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

            return( status );
#else /* MBEDTLS_PSA_BUILTIN_CIPHER */
            return( PSA_ERROR_NOT_SUPPORTED );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_cipher_decrypt_setup(
                         &operation->ctx.opaque_test_driver_ctx,
                         attributes,
                         key_buffer, key_buffer_size,
                         alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)operation;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_cipher_set_iv(
    psa_cipher_operation_t *operation,
    const uint8_t *iv,
    size_t iv_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_cipher_set_iv( &operation->ctx.mbedtls_ctx,
                                               iv,
                                               iv_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_cipher_set_iv(
                        &operation->ctx.transparent_test_driver_ctx,
                        iv, iv_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_cipher_set_iv(
                        &operation->ctx.opaque_test_driver_ctx,
                        iv, iv_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_transparent_cipher_set_iv(
                        &operation->ctx.sgi_driver_ctx,
                        iv, iv_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_cipher_set_iv(
                        &operation->ctx.els_pkc_driver_ctx,
                        iv, iv_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_cipher_set_iv(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        iv, iv_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)iv;
    (void)iv_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_cipher_update(
    psa_cipher_operation_t *operation,
    const uint8_t *input,
    size_t input_length,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_cipher_update( &operation->ctx.mbedtls_ctx,
                                               input,
                                               input_length,
                                               output,
                                               output_size,
                                               output_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_cipher_update(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length,
                        output, output_size, output_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_cipher_update(
                        &operation->ctx.opaque_test_driver_ctx,
                        input, input_length,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_transparent_cipher_update(
                        &operation->ctx.sgi_driver_ctx,
                        input, input_length,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_cipher_update(
                        &operation->ctx.els_pkc_driver_ctx,
                        input, input_length,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_cipher_update(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        input, input_length,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)input;
    (void)input_length;
    (void)output;
    (void)output_size;
    (void)output_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_cipher_finish(
    psa_cipher_operation_t *operation,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_cipher_finish( &operation->ctx.mbedtls_ctx,
                                               output,
                                               output_size,
                                               output_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_cipher_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        output, output_size, output_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_cipher_finish(
                        &operation->ctx.opaque_test_driver_ctx,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_transparent_cipher_finish(
                        &operation->ctx.sgi_driver_ctx,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_cipher_finish(
                        &operation->ctx.els_pkc_driver_ctx,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_cipher_finish(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)output;
    (void)output_size;
    (void)output_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_cipher_abort(
    psa_cipher_operation_t *operation )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_CIPHER)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_cipher_abort( &operation->ctx.mbedtls_ctx ) );
#endif /* MBEDTLS_PSA_BUILTIN_CIPHER */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            status = mbedtls_test_transparent_cipher_abort(
                         &operation->ctx.transparent_test_driver_ctx );
            mbedtls_platform_zeroize(
                &operation->ctx.transparent_test_driver_ctx,
                sizeof( operation->ctx.transparent_test_driver_ctx ) );
            return( status );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            status = mbedtls_test_opaque_cipher_abort(
                         &operation->ctx.opaque_test_driver_ctx );
            mbedtls_platform_zeroize(
                &operation->ctx.opaque_test_driver_ctx,
                sizeof( operation->ctx.opaque_test_driver_ctx ) );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            status = sgi_transparent_cipher_abort( &operation->ctx.sgi_driver_ctx );
            mbedtls_platform_zeroize(
                &operation->ctx.sgi_driver_ctx,
                sizeof( operation->ctx.sgi_driver_ctx ) );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            status = els_pkc_transparent_cipher_abort( &operation->ctx.els_pkc_driver_ctx );
            mbedtls_platform_zeroize(
                &operation->ctx.els_pkc_driver_ctx,
                sizeof( operation->ctx.els_pkc_driver_ctx ) );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return ele_hseb_transparent_cipher_abort(
                         &operation->ctx.transparent_ele_hseb_driver_ctx );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)status;
    return( PSA_ERROR_INVALID_ARGUMENT );
}

/*
 * Hashing functions
 */
static inline psa_status_t psa_driver_wrapper_hash_compute(
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *hash,
    size_t hash_size,
    size_t *hash_length)
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Try accelerators first */
#if defined(PSA_CRYPTO_DRIVER_TEST)
    status = mbedtls_test_transparent_hash_compute(
                alg, input, input_length, hash, hash_size, hash_length );
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
    status = hashcrypt_hash_compute( alg, input, input_length,
                                     hash, hash_size, hash_length );
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)                      //NXP ELE --- BEGIN ---
    status = ele_s4xx_transparent_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
    status = dcp_hash_compute(alg, input, input_length, hash, hash_size,
                        hash_length);
    if ( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_SGI)
    status = sgi_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
    status = caam_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
    status = ele_s2xx_transparent_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
    status = els_pkc_transparent_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
    status = ele_hseb_transparent_hash_compute(alg, input, input_length, hash, hash_size,
                              hash_length);
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

    /* If software fallback is compiled in, try fallback */
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
    status = mbedtls_psa_hash_compute( alg, input, input_length,
                                       hash, hash_size, hash_length );
    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
    (void) status;
    (void) alg;
    (void) input;
    (void) input_length;
    (void) hash;
    (void) hash_size;
    (void) hash_length;

    return( PSA_ERROR_NOT_SUPPORTED );
}

static inline psa_status_t psa_driver_wrapper_hash_setup(
    psa_hash_operation_t *operation,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Try setup on accelerators first */
#if defined(PSA_CRYPTO_DRIVER_TEST)
    status = mbedtls_test_transparent_hash_setup(
                &operation->ctx.test_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
    status = hashcrypt_hash_setup( &operation->ctx.hashcrypt_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = HASHCRYPT_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
    status = dcp_hash_setup( &operation->ctx.dcp_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = DCP_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)                      //NXP ELE --- BEGIN ---
    status = ele_s4xx_transparent_hash_setup( &operation->ctx.ele_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = ELE_S4XX_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
#if defined(PSA_CRYPTO_DRIVER_SGI)
    status = sgi_hash_setup( &operation->ctx.sgi_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = SGI_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
    status = caam_hash_setup( &operation->ctx.caam_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = CAAM_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
    status = ele_s2xx_transparent_hash_setup( &operation->ctx.ele_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = ELE_S2XX_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
    status = els_pkc_transparent_hash_setup( &operation->ctx.els_pkc_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
    status = ele_hseb_transparent_hash_setup( &operation->ctx.ele_hseb_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

    /* If software fallback is compiled in, try fallback */
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
    status = mbedtls_psa_hash_setup( &operation->ctx.mbedtls_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
    /* Nothing left to try if we fall through here */
    (void) status;
    (void) operation;
    (void) alg;
    return( PSA_ERROR_NOT_SUPPORTED );
}

static inline psa_status_t psa_driver_wrapper_hash_clone(
    const psa_hash_operation_t *source_operation,
    psa_hash_operation_t *target_operation )
{
    switch( source_operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            target_operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            return( mbedtls_psa_hash_clone( &source_operation->ctx.mbedtls_ctx,
                                            &target_operation->ctx.mbedtls_ctx ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            target_operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;
            return( mbedtls_test_transparent_hash_clone(
                        &source_operation->ctx.test_driver_ctx,
                        &target_operation->ctx.test_driver_ctx ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
        case HASHCRYPT_TRANSPARENT_DRIVER_ID:
            target_operation->id = HASHCRYPT_TRANSPARENT_DRIVER_ID;
            return( hashcrypt_hash_clone( &source_operation->ctx.hashcrypt_driver_ctx,
                                    &target_operation->ctx.hashcrypt_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
        case DCP_TRANSPARENT_DRIVER_ID:
            target_operation->id = DCP_TRANSPARENT_DRIVER_ID;
            return( dcp_hash_clone( &source_operation->ctx.dcp_driver_ctx,
                                &target_operation->ctx.dcp_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            target_operation->id = SGI_TRANSPARENT_DRIVER_ID;
            return( sgi_hash_clone( &source_operation->ctx.sgi_driver_ctx,
                                    &target_operation->ctx.sgi_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case CAAM_TRANSPARENT_DRIVER_ID:
            target_operation->id = CAAM_TRANSPARENT_DRIVER_ID;
            return( caam_hash_clone( &source_operation->ctx.caam_driver_ctx,
                                    &target_operation->ctx.caam_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            target_operation->id = ELE_S2XX_TRANSPARENT_DRIVER_ID;
            return( ele_s2xx_transparent_hash_clone( &source_operation->ctx.ele_driver_ctx,
                                    &target_operation->ctx.ele_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case ELE_S4XX_TRANSPARENT_DRIVER_ID:
            target_operation->id = ELE_S4XX_TRANSPARENT_DRIVER_ID;
            return( ele_s4xx_transparent_hash_clone( &source_operation->ctx.ele_driver_ctx,
                                    &target_operation->ctx.ele_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            target_operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;
            return( els_pkc_transparent_hash_clone( &source_operation->ctx.els_pkc_driver_ctx,
                                    &target_operation->ctx.els_pkc_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            target_operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;
            return( ele_hseb_transparent_hash_clone( &source_operation->ctx.ele_hseb_driver_ctx,
                                    &target_operation->ctx.ele_hseb_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

        default:
            (void) target_operation;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_hash_update(
    psa_hash_operation_t *operation,
    const uint8_t *input,
    size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_hash_update( &operation->ctx.mbedtls_ctx,
                                             input, input_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_hash_update(
                        &operation->ctx.test_driver_ctx,
                        input, input_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
        case HASHCRYPT_TRANSPARENT_DRIVER_ID:
            return( hashcrypt_hash_update( &operation->ctx.hashcrypt_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
        case DCP_TRANSPARENT_DRIVER_ID:
            return( dcp_hash_update( &operation->ctx.dcp_driver_ctx,
                                input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_hash_update( &operation->ctx.sgi_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case CAAM_TRANSPARENT_DRIVER_ID:
            return( caam_hash_update( &operation->ctx.caam_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_hash_update( &operation->ctx.ele_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case ELE_S4XX_TRANSPARENT_DRIVER_ID:
            return( ele_s4xx_transparent_hash_update( &operation->ctx.ele_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_hash_update( &operation->ctx.els_pkc_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_hash_update( &operation->ctx.ele_hseb_driver_ctx,
                                     input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

        default:
            (void) input;
            (void) input_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_hash_finish(
    psa_hash_operation_t *operation,
    uint8_t *hash,
    size_t hash_size,
    size_t *hash_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_hash_finish( &operation->ctx.mbedtls_ctx,
                                             hash, hash_size, hash_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_hash_finish(
                        &operation->ctx.test_driver_ctx,
                        hash, hash_size, hash_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
        case HASHCRYPT_TRANSPARENT_DRIVER_ID:
            return( hashcrypt_hash_finish( &operation->ctx.hashcrypt_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
        case DCP_TRANSPARENT_DRIVER_ID:
            return( dcp_hash_finish( &operation->ctx.dcp_driver_ctx,
                                hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_hash_finish( &operation->ctx.sgi_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case CAAM_TRANSPARENT_DRIVER_ID:
            return( caam_hash_finish( &operation->ctx.caam_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_hash_finish( &operation->ctx.ele_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case ELE_S4XX_TRANSPARENT_DRIVER_ID:
            return( ele_s4xx_transparent_hash_finish( &operation->ctx.ele_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_hash_finish( &operation->ctx.els_pkc_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_hash_finish( &operation->ctx.ele_hseb_driver_ctx,
                                     hash, hash_size, hash_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

        default:
            (void) hash;
            (void) hash_size;
            (void) hash_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_hash_abort(
    psa_hash_operation_t *operation )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_HASH)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_hash_abort( &operation->ctx.mbedtls_ctx ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_hash_abort(
                        &operation->ctx.test_driver_ctx ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_HASHCRYPT)
        case HASHCRYPT_TRANSPARENT_DRIVER_ID:
            return( hashcrypt_hash_abort( &operation->ctx.hashcrypt_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_HASHCRYPT */
#if defined(PSA_CRYPTO_DRIVER_DCP) && defined(PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH)
        case DCP_TRANSPARENT_DRIVER_ID:
            return( dcp_hash_abort( &operation->ctx.dcp_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_DCP && PSA_CRYPTO_DRIVER_DCP_ENFORCE_HASH */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_hash_abort( &operation->ctx.sgi_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case CAAM_TRANSPARENT_DRIVER_ID:
            return( caam_hash_abort( &operation->ctx.caam_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_hash_abort( &operation->ctx.ele_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case ELE_S4XX_TRANSPARENT_DRIVER_ID:
            return( ele_s4xx_transparent_hash_abort( &operation->ctx.ele_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_hash_abort( &operation->ctx.els_pkc_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_hash_abort( &operation->ctx.ele_hseb_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

        default:
            return( PSA_ERROR_BAD_STATE );
    }
}

/*
 * XOF functions
 */
static inline psa_status_t psa_driver_wrapper_xof_setup(
    psa_xof_operation_t *operation,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    /* Try setup on accelerators first */
#if defined(PSA_CRYPTO_DRIVER_TEST)
    status = mbedtls_test_transparent_xof_setup(
                &operation->ctx.test_driver_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif

    /* If software fallback is compiled in, try fallback */
#if defined(MBEDTLS_PSA_BUILTIN_XOF)
    status = mbedtls_psa_xof_setup( &operation->ctx.mbedtls_ctx, alg );
    if( status == PSA_SUCCESS )
        operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

    if( status != PSA_ERROR_NOT_SUPPORTED )
        return( status );
#endif
    /* Nothing left to try if we fall through here */
    (void) status;
    (void) operation;
    (void) alg;
    return( PSA_ERROR_NOT_SUPPORTED );
}

static inline psa_status_t psa_driver_wrapper_xof_set_context(
    psa_xof_operation_t *operation,
    const uint8_t *context,
    size_t context_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_XOF)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_xof_set_context( &operation->ctx.mbedtls_ctx,
                                                 context, context_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_xof_set_context(
                        &operation->ctx.test_driver_ctx,
                        context, context_length ) );
#endif
        default:
            (void) context;
            (void) context_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_xof_update(
    psa_xof_operation_t *operation,
    const uint8_t *input,
    size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_XOF)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_xof_update( &operation->ctx.mbedtls_ctx,
                                            input, input_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_xof_update(
                        &operation->ctx.test_driver_ctx,
                        input, input_length ) );
#endif
        default:
            (void) input;
            (void) input_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_xof_output(
    psa_xof_operation_t *operation,
    uint8_t *output,
    size_t output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_XOF)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_xof_output( &operation->ctx.mbedtls_ctx,
                                            output, output_length ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_xof_output(
                        &operation->ctx.test_driver_ctx,
                        output, output_length ) );
#endif
        default:
            (void) output;
            (void) output_length;
            return( PSA_ERROR_BAD_STATE );
    }
}

static inline psa_status_t psa_driver_wrapper_xof_abort(
    psa_xof_operation_t *operation )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_XOF)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_xof_abort( &operation->ctx.mbedtls_ctx ) );
#endif
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_xof_abort(
                        &operation->ctx.test_driver_ctx ) );
#endif
        default:
            return( PSA_ERROR_BAD_STATE );
    }
}

/*
 * AEAD functions
 */
static inline psa_status_t psa_driver_wrapper_aead_encrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *nonce, size_t nonce_length,
    const uint8_t *additional_data, size_t additional_data_length,
    const uint8_t *plaintext, size_t plaintext_length,
    uint8_t *ciphertext, size_t ciphertext_size, size_t *ciphertext_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_aead_encrypt( attributes, key_buffer, key_buffer_size,
                                       alg,
                                       nonce, nonce_length,
                                       additional_data, additional_data_length,
                                       plaintext, plaintext_length,
                                       ciphertext, ciphertext_size, ciphertext_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_aead_encrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_aead_encrypt( attributes, key_buffer, key_buffer_size,
                                       alg,
                                       nonce, nonce_length,
                                       additional_data, additional_data_length,
                                       plaintext, plaintext_length,
                                       ciphertext, ciphertext_size, ciphertext_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
            return( mbedtls_psa_aead_encrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        plaintext, plaintext_length,
                        ciphertext, ciphertext_size, ciphertext_length ) );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_aead_encrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_aead_encrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         plaintext, plaintext_length,
                         ciphertext, ciphertext_size, ciphertext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void) key_buffer; (void) key_buffer_size;
            (void) alg;
            (void) nonce; (void) nonce_length;
            (void) additional_data; (void) additional_data_length;
            (void) plaintext; (void) plaintext_length;
            (void) ciphertext; (void) ciphertext_size; (void) ciphertext_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_aead_decrypt(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer, size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *nonce, size_t nonce_length,
    const uint8_t *additional_data, size_t additional_data_length,
    const uint8_t *ciphertext, size_t ciphertext_length,
    uint8_t *plaintext, size_t plaintext_size, size_t *plaintext_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_aead_decrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_aead_decrypt( attributes, key_buffer, key_buffer_size,
                                       alg,
                                       nonce, nonce_length,
                                       additional_data, additional_data_length,
                                       ciphertext, ciphertext_length,
                                       plaintext, plaintext_size, plaintext_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_aead_decrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE,
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_aead_decrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_aead_decrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_aead_decrypt( attributes, key_buffer, key_buffer_size,
                                       alg,
                                       nonce, nonce_length,
                                       additional_data, additional_data_length,
                                       ciphertext, ciphertext_length,
                                       plaintext, plaintext_size, plaintext_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_aead_decrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
            return( mbedtls_psa_aead_decrypt(
                        attributes, key_buffer, key_buffer_size,
                        alg,
                        nonce, nonce_length,
                        additional_data, additional_data_length,
                        ciphertext, ciphertext_length,
                        plaintext, plaintext_size, plaintext_length ) );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_aead_decrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE,
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         ciphertext, ciphertext_length,
                         plaintext, plaintext_size, plaintext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_aead_decrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         ciphertext, ciphertext_length,
                         plaintext, plaintext_size, plaintext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_aead_decrypt(
                         attributes, key_buffer, key_buffer_size,
                         alg,
                         nonce, nonce_length,
                         additional_data, additional_data_length,
                         ciphertext, ciphertext_length,
                         plaintext, plaintext_size, plaintext_length );

            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void) key_buffer; (void) key_buffer_size;
            (void) alg;
            (void) nonce; (void) nonce_length;
            (void) additional_data; (void) additional_data_length;
            (void) ciphertext; (void) ciphertext_length;
            (void) plaintext; (void) plaintext_size; (void) plaintext_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_aead_encrypt_setup(
   psa_aead_operation_t *operation,
   const psa_key_attributes_t *attributes,
   const uint8_t *key_buffer, size_t key_buffer_size,
   psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;
            status = mbedtls_test_transparent_aead_encrypt_setup(
                        &operation->ctx.transparent_test_driver_ctx,
                        attributes, key_buffer, key_buffer_size,
                        alg );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            operation->id = SGI_TRANSPARENT_DRIVER_ID;
            status = sgi_aead_encrypt_setup( &operation->ctx.sgi_driver_ctx,
                                             attributes, key_buffer, key_buffer_size,
                                             alg );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;
            status = els_pkc_transparent_aead_encrypt_setup( &operation->ctx.els_pkc_driver_ctx,
                                             attributes, key_buffer, key_buffer_size,
                                             alg );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
            operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            status = mbedtls_psa_aead_encrypt_setup(
                        &operation->ctx.mbedtls_ctx, attributes,
                        key_buffer, key_buffer_size,
                        alg );
            return( status );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif

        /* Add cases for opaque driver here */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void) operation;
            (void) key_buffer; (void) key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_aead_decrypt_setup(
   psa_aead_operation_t *operation,
   const psa_key_attributes_t *attributes,
   const uint8_t *key_buffer, size_t key_buffer_size,
   psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;
            status = mbedtls_test_transparent_aead_decrypt_setup(
                        &operation->ctx.transparent_test_driver_ctx,
                        attributes,
                        key_buffer, key_buffer_size,
                        alg );

            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            operation->id = SGI_TRANSPARENT_DRIVER_ID;
            status = sgi_aead_decrypt_setup( &operation->ctx.sgi_driver_ctx,
                                             attributes, key_buffer, key_buffer_size,
                                             alg );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;
            status = els_pkc_transparent_aead_decrypt_setup( &operation->ctx.els_pkc_driver_ctx,
                                             attributes, key_buffer, key_buffer_size,
                                             alg );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Fell through, meaning no accelerator supports this operation */
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
            operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
            status = mbedtls_psa_aead_decrypt_setup(
                        &operation->ctx.mbedtls_ctx,
                        attributes,
                        key_buffer, key_buffer_size,
                        alg );
            return( status );
#else
            return( PSA_ERROR_NOT_SUPPORTED );
#endif
        /* Add cases for opaque driver here */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void) operation;
            (void) key_buffer; (void)key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_aead_set_nonce(
   psa_aead_operation_t *operation,
   const uint8_t *nonce,
   size_t nonce_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_set_nonce( &operation->ctx.mbedtls_ctx,
                                                nonce,
                                                nonce_length ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_set_nonce(
                         &operation->ctx.transparent_test_driver_ctx,
                         nonce, nonce_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_set_nonce( &operation->ctx.sgi_driver_ctx,
                                        nonce, nonce_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_set_nonce( &operation->ctx.els_pkc_driver_ctx,
                                        nonce, nonce_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)nonce;
    (void)nonce_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_set_lengths(
   psa_aead_operation_t *operation,
   size_t ad_length,
   size_t plaintext_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_set_lengths( &operation->ctx.mbedtls_ctx,
                                                  ad_length,
                                                  plaintext_length ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_set_lengths(
                        &operation->ctx.transparent_test_driver_ctx,
                        ad_length, plaintext_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_set_lengths( &operation->ctx.sgi_driver_ctx,
                                          ad_length, plaintext_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_set_lengths( &operation->ctx.els_pkc_driver_ctx,
                                          ad_length, plaintext_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)ad_length;
    (void)plaintext_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_update_ad(
   psa_aead_operation_t *operation,
   const uint8_t *input,
   size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_update_ad( &operation->ctx.mbedtls_ctx,
                                                input,
                                                input_length ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_update_ad(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_update_ad( &operation->ctx.sgi_driver_ctx,
                                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_update_ad( &operation->ctx.els_pkc_driver_ctx,
                                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)input;
    (void)input_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_update(
   psa_aead_operation_t *operation,
   const uint8_t *input,
   size_t input_length,
   uint8_t *output,
   size_t output_size,
   size_t *output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_update( &operation->ctx.mbedtls_ctx,
                                             input, input_length,
                                             output, output_size,
                                             output_length ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_update(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length, output, output_size,
                        output_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_update( &operation->ctx.sgi_driver_ctx,
                                     input, input_length,
                                     output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_update( &operation->ctx.els_pkc_driver_ctx,
                                     input, input_length,
                                     output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)input;
    (void)input_length;
    (void)output;
    (void)output_size;
    (void)output_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_finish(
   psa_aead_operation_t *operation,
   uint8_t *ciphertext,
   size_t ciphertext_size,
   size_t *ciphertext_length,
   uint8_t *tag,
   size_t tag_size,
   size_t *tag_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_finish( &operation->ctx.mbedtls_ctx,
                                             ciphertext,
                                             ciphertext_size,
                                             ciphertext_length, tag,
                                             tag_size, tag_length ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        ciphertext, ciphertext_size,
                        ciphertext_length, tag, tag_size, tag_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_finish( &operation->ctx.sgi_driver_ctx,
                                     ciphertext, ciphertext_size,
                                     ciphertext_length, tag, tag_size, tag_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_finish( &operation->ctx.els_pkc_driver_ctx,
                                     ciphertext, ciphertext_size,
                                     ciphertext_length, tag, tag_size, tag_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)ciphertext;
    (void)ciphertext_size;
    (void)ciphertext_length;
    (void)tag;
    (void)tag_size;
    (void)tag_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_verify(
   psa_aead_operation_t *operation,
   uint8_t *plaintext,
   size_t plaintext_size,
   size_t *plaintext_length,
   const uint8_t *tag,
   size_t tag_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            {
                psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
                uint8_t check_tag[PSA_AEAD_TAG_MAX_SIZE];
                size_t check_tag_length;

                status = mbedtls_psa_aead_finish( &operation->ctx.mbedtls_ctx,
                                                  plaintext,
                                                  plaintext_size,
                                                  plaintext_length,
                                                  check_tag,
                                                  sizeof( check_tag ),
                                                  &check_tag_length );

                if( status == PSA_SUCCESS )
                {
                    if( tag_length != check_tag_length ||
                        mbedtls_ct_memcmp( tag, check_tag, tag_length )
                        != 0 )
                        status = PSA_ERROR_INVALID_SIGNATURE;
                }

                mbedtls_platform_zeroize( check_tag, sizeof( check_tag ) );

                return( status );
            }

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_verify(
                        &operation->ctx.transparent_test_driver_ctx,
                        plaintext, plaintext_size,
                        plaintext_length, tag, tag_length ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_verify( &operation->ctx.sgi_driver_ctx,
                                     plaintext, plaintext_size,
                                     plaintext_length, tag, tag_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_verify( &operation->ctx.els_pkc_driver_ctx,
                                     plaintext, plaintext_size,
                                     plaintext_length, tag, tag_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    (void)plaintext;
    (void)plaintext_size;
    (void)plaintext_length;
    (void)tag;
    (void)tag_length;

    return( PSA_ERROR_INVALID_ARGUMENT );
}

static inline psa_status_t psa_driver_wrapper_aead_abort(
   psa_aead_operation_t *operation )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_AEAD)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_aead_abort( &operation->ctx.mbedtls_ctx ) );

#endif /* MBEDTLS_PSA_BUILTIN_AEAD */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_aead_abort(
               &operation->ctx.transparent_test_driver_ctx ) );

        /* Add cases for opaque driver here */

#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_aead_abort( &operation->ctx.sgi_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_aead_abort( &operation->ctx.els_pkc_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
    }

    return( PSA_ERROR_INVALID_ARGUMENT );
}

/*
 * MAC functions
 */
static inline psa_status_t psa_driver_wrapper_mac_compute(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *input,
    size_t input_length,
    uint8_t *mac,
    size_t mac_size,
    size_t *mac_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_mac_compute( attributes, key_buffer, key_buffer_size, alg,
                                      input, input_length,
                                      mac, mac_size, mac_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_mac_compute( attributes, key_buffer, key_buffer_size, alg,
                                      input, input_length,
                                      mac, mac_size, mac_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELA_CSEC)
            status = ela_csec_transparent_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELA_CSEC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            status = caam_common_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
        case PSA_CRYPTO_ELE_S4XX_LOCATION:
            status = ele_s4xx_opaque_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            status = ele_s2xx_opaque_mac_compute(
                attributes, key_buffer, key_buffer_size, alg,
                input, input_length,
                mac, mac_size, mac_length );
            return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void) key_buffer;
            (void) key_buffer_size;
            (void) alg;
            (void) input;
            (void) input_length;
            (void) mac;
            (void) mac_size;
            (void) mac_length;
            (void) status;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_sign_setup(
    psa_mac_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_mac_sign_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_mac_sign_setup( &operation->ctx.sgi_driver_ctx,
                                         attributes,
                                         key_buffer, key_buffer_size,
                                         alg );
            if( status == PSA_SUCCESS )
                operation->id = SGI_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_mac_sign_setup(
                &operation->ctx.transparent_ele_s2xx_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_S2XX_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_mac_sign_setup( &operation->ctx.els_pkc_driver_ctx,
                                         attributes,
                                         key_buffer, key_buffer_size,
                                         alg );
            if( status == PSA_SUCCESS )
                operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_mac_sign_setup(
                &operation->ctx.transparent_ele_hseb_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_mac_sign_setup( &operation->ctx.mbedtls_ctx,
                                                 attributes,
                                                 key_buffer, key_buffer_size,
                                                 alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_mac_sign_setup(
                &operation->ctx.opaque_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void) status;
            (void) operation;
            (void) key_buffer;
            (void) key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_verify_setup(
    psa_mac_operation_t *operation,
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_mac_verify_setup(
                &operation->ctx.transparent_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
            status = sgi_mac_verify_setup( &operation->ctx.sgi_driver_ctx,
                                           attributes,
                                           key_buffer, key_buffer_size,
                                           alg );
            if( status == PSA_SUCCESS )
                operation->id = SGI_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_mac_verify_setup(
                &operation->ctx.transparent_ele_s2xx_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_S2XX_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_mac_verify_setup( &operation->ctx.els_pkc_driver_ctx,
                                           attributes,
                                           key_buffer, key_buffer_size,
                                           alg );
            if( status == PSA_SUCCESS )
                operation->id = ELS_PKC_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
            status = ele_hseb_transparent_mac_verify_setup(
                &operation->ctx.transparent_ele_hseb_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );
            /* Declared with fallback == true */
            if( status == PSA_SUCCESS )
                operation->id = ELE_HSEB_TRANSPARENT_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
            /* Fell through, meaning no accelerator supports this operation */
            status = mbedtls_psa_mac_verify_setup( &operation->ctx.mbedtls_ctx,
                                                   attributes,
                                                   key_buffer, key_buffer_size,
                                                   alg );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */
            return( PSA_ERROR_NOT_SUPPORTED );

        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            status = mbedtls_test_opaque_mac_verify_setup(
                &operation->ctx.opaque_test_driver_ctx,
                attributes,
                key_buffer, key_buffer_size,
                alg );

            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_OPAQUE_DRIVER_ID;

            return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            /* Key is declared with a lifetime not known to us */
            (void) status;
            (void) operation;
            (void) key_buffer;
            (void) key_buffer_size;
            (void) alg;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_update(
    psa_mac_operation_t *operation,
    const uint8_t *input,
    size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_mac_update( &operation->ctx.mbedtls_ctx,
                                            input, input_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_mac_update(
                        &operation->ctx.transparent_test_driver_ctx,
                        input, input_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_mac_update(
                        &operation->ctx.opaque_test_driver_ctx,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_mac_update( &operation->ctx.sgi_driver_ctx,
                                    input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_mac_update(
                        &operation->ctx.transparent_ele_s2xx_driver_ctx,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_mac_update( &operation->ctx.els_pkc_driver_ctx,
                                    input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_mac_update(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) input;
            (void) input_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_sign_finish(
    psa_mac_operation_t *operation,
    uint8_t *mac,
    size_t mac_size,
    size_t *mac_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_mac_sign_finish( &operation->ctx.mbedtls_ctx,
                                                 mac, mac_size, mac_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_mac_sign_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        mac, mac_size, mac_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_mac_sign_finish(
                        &operation->ctx.opaque_test_driver_ctx,
                        mac, mac_size, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_mac_sign_finish( &operation->ctx.sgi_driver_ctx,
                                         mac, mac_size, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_mac_sign_finish(
                        &operation->ctx.transparent_ele_s2xx_driver_ctx,
                        mac, mac_size, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_mac_sign_finish( &operation->ctx.els_pkc_driver_ctx,
                                         mac, mac_size, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_mac_sign_finish(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        mac, mac_size, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) mac;
            (void) mac_size;
            (void) mac_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_verify_finish(
    psa_mac_operation_t *operation,
    const uint8_t *mac,
    size_t mac_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_mac_verify_finish( &operation->ctx.mbedtls_ctx,
                                                   mac, mac_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_mac_verify_finish(
                        &operation->ctx.transparent_test_driver_ctx,
                        mac, mac_length ) );

        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_mac_verify_finish(
                        &operation->ctx.opaque_test_driver_ctx,
                        mac, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_mac_verify_finish( &operation->ctx.sgi_driver_ctx,
                                           mac, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_mac_verify_finish(
                        &operation->ctx.transparent_ele_s2xx_driver_ctx,
                        mac, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_mac_verify_finish( &operation->ctx.els_pkc_driver_ctx,
                                           mac, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_mac_verify_finish(
                        &operation->ctx.transparent_ele_hseb_driver_ctx,
                        mac, mac_length ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) mac;
            (void) mac_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_mac_abort(
    psa_mac_operation_t *operation )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_MAC)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_mac_abort( &operation->ctx.mbedtls_ctx ) );
#endif /* MBEDTLS_PSA_BUILTIN_MAC */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_mac_abort(
                        &operation->ctx.transparent_test_driver_ctx ) );
        case MBEDTLS_TEST_OPAQUE_DRIVER_ID:
            return( mbedtls_test_opaque_mac_abort(
                        &operation->ctx.opaque_test_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_SGI)
        case SGI_TRANSPARENT_DRIVER_ID:
            return( sgi_mac_abort( &operation->ctx.sgi_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_SGI */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case ELE_S2XX_TRANSPARENT_DRIVER_ID:
            return( ele_s2xx_transparent_mac_abort(
                        &operation->ctx.transparent_ele_s2xx_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
        case ELS_PKC_TRANSPARENT_DRIVER_ID:
            return( els_pkc_transparent_mac_abort( &operation->ctx.els_pkc_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
        case ELE_HSEB_TRANSPARENT_DRIVER_ID:
            return( ele_hseb_transparent_mac_abort(
                        &operation->ctx.transparent_ele_hseb_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

/*
 * Asymmetric cryptography
 */
static inline psa_status_t psa_driver_wrapper_asymmetric_encrypt(
    const psa_key_attributes_t *attributes, const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg, const uint8_t *input,
    size_t input_length, const uint8_t *salt, size_t salt_length,
    uint8_t *output, size_t output_size, size_t *output_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_asymmetric_encrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_encrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE, attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_asymmetric_encrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
            return( mbedtls_psa_asymmetric_encrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size, output_length )
                  );
        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_asymmetric_encrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size, output_length )
                  );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return caam_common_asymmetric_encrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE, attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            (void)input;
            (void)input_length;
            (void)salt;
            (void)salt_length;
            (void)output;
            (void)output_size;
            (void)output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_asymmetric_decrypt(
    const psa_key_attributes_t *attributes, const uint8_t *key_buffer,
    size_t key_buffer_size, psa_algorithm_t alg, const uint8_t *input,
    size_t input_length, const uint8_t *salt, size_t salt_length,
    uint8_t *output, size_t output_size, size_t *output_length )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_asymmetric_decrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
            status = caam_common_asymmetric_decrypt(MCUX_PSA_CAAM_KEY_TYPE_NONE, attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
            status = ele_s4xx_transparent_asymmetric_decrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
            return( mbedtls_psa_asymmetric_decrypt( attributes,
                        key_buffer, key_buffer_size, alg,input, input_length,
                        salt, salt_length, output, output_size,
                        output_length ) );
        /* Add cases for opaque driver here */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_asymmetric_decrypt( attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_CAAM)
        case PSA_CRYPTO_CAAM_LOCATION:
            return caam_common_asymmetric_decrypt((mcux_psa_caam_key_type_t)PSA_CRYPTO_DRIVER_CAAM_OPAQUE, attributes,
                        key_buffer, key_buffer_size, alg, input, input_length,
                        salt, salt_length, output, output_size,
                        output_length );
#endif /* PSA_CRYPTO_DRIVER_CAAM */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            /* Key is declared with a lifetime not known to us */
            (void)status;
            (void)key_buffer;
            (void)key_buffer_size;
            (void)alg;
            (void)input;
            (void)input_length;
            (void)salt;
            (void)salt_length;
            (void)output;
            (void)output_size;
            (void)output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_key_agreement(
    const psa_key_attributes_t *attributes,
    const uint8_t *key_buffer,
    size_t key_buffer_size,
    psa_algorithm_t alg,
    const uint8_t *peer_key,
    size_t peer_key_length,
    uint8_t *shared_secret,
    size_t shared_secret_size,
    size_t *shared_secret_length
 )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;
    psa_key_location_t location =
        PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime(attributes) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status =
                mbedtls_test_transparent_key_agreement( attributes,
                        key_buffer, key_buffer_size, alg, peer_key,
                        peer_key_length, shared_secret, shared_secret_size,
                        shared_secret_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(MBEDTLS_PSA_P256M_DRIVER_ENABLED)
            if( PSA_KEY_TYPE_IS_ECC( psa_get_key_type(attributes) ) &&
                PSA_ALG_IS_ECDH(alg) &&
                PSA_KEY_TYPE_ECC_GET_FAMILY(psa_get_key_type(attributes)) == PSA_ECC_FAMILY_SECP_R1 &&
                psa_get_key_bits(attributes) == 256 )
            {
                status = p256_transparent_key_agreement( attributes,
                                                         key_buffer,
                                                         key_buffer_size,
                                                         alg,
                                                         peer_key,
                                                         peer_key_length,
                                                         shared_secret,
                                                         shared_secret_size,
                                                         shared_secret_length );
                if( status != PSA_ERROR_NOT_SUPPORTED)
                    return( status );
            }
#endif /* MBEDTLS_PSA_P256M_DRIVER_ENABLED */
#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
            status = els_pkc_transparent_key_agreement( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        peer_key,
                                        peer_key_length,
                                        shared_secret,
                                        shared_secret_size,
                                        shared_secret_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */
#if defined(PSA_CRYPTO_DRIVER_PKC)
            status = pkc_key_agreement( attributes,
                                        key_buffer,
                                        key_buffer_size,
                                        alg,
                                        peer_key,
                                        peer_key_length,
                                        shared_secret,
                                        shared_secret_size,
                                        shared_secret_length );
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_PKC */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
            status = ele_s2xx_transparent_key_agreement( attributes,
                                          key_buffer,
                                          key_buffer_size,
                                          alg,
                                          peer_key,
                                          peer_key_length,
                                          shared_secret,
                                          shared_secret_size,
                                          shared_secret_length);

            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
    status = ele_s4xx_transparent_key_agreement( attributes,
                                                 key_buffer,
                                                 key_buffer_size,
                                                 alg,
                                                 peer_key,
                                                 peer_key_length,
                                                 shared_secret,
                                                 shared_secret_size,
                                                 shared_secret_length );

        // Declared with fallback == true
        if( status != PSA_ERROR_NOT_SUPPORTED )
            return( status );


#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */
#if defined(PSA_CRYPTO_DRIVER_CASPER)
#if defined(MBEDTLS_BIGNUM_C) && defined(MBEDTLS_ECP_C)
            status = casper_psa_key_agreement_ecdh( attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    alg,
                                                    peer_key,
                                                    peer_key_length,
                                                    shared_secret,
                                                    shared_secret_size,
                                                    shared_secret_length);
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* MBEDTLS_ECP_C && MBEDTLS_BIGNUM_C */
#endif /* PSA_CRYPTO_DRIVER_CASPER */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

            /* Software Fallback */
            status = psa_key_agreement_raw_builtin( attributes,
                                                    key_buffer,
                                                    key_buffer_size,
                                                    alg,
                                                    peer_key,
                                                    peer_key_length,
                                                    shared_secret,
                                                    shared_secret_size,
                                                    shared_secret_length );
            return( status );
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case PSA_CRYPTO_TEST_DRIVER_LOCATION:
            return( mbedtls_test_opaque_key_agreement( attributes,
                        key_buffer, key_buffer_size, alg, peer_key,
                        peer_key_length, shared_secret, shared_secret_size,
                        shared_secret_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE:
        case PSA_CRYPTO_LOCATION_S200_KEY_STORAGE_NON_EL2GO:
            return( ele_s2xx_opaque_key_agreement( attributes,
                         key_buffer,
                         key_buffer_size,
                         alg,
                         peer_key,
                         peer_key_length,
                         shared_secret,
                         shared_secret_size,
                         shared_secret_length) );
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */

        default:
            (void) attributes;
            (void) key_buffer;
            (void) key_buffer_size;
            (void) peer_key;
            (void) peer_key_length;
            (void) shared_secret;
            (void) shared_secret_size;
            (void) shared_secret_length;
            return( PSA_ERROR_NOT_SUPPORTED );

    }
}

static inline psa_status_t psa_driver_wrapper_pake_setup(
    psa_pake_operation_t *operation,
    const psa_crypto_driver_pake_inputs_t *inputs )
{
    psa_status_t status = PSA_ERROR_CORRUPTION_DETECTED;

    psa_key_location_t location =
            PSA_KEY_LIFETIME_GET_LOCATION( psa_get_key_lifetime( &inputs->attributes ) );

    switch( location )
    {
        case PSA_KEY_LOCATION_LOCAL_STORAGE:
            /* Key is stored in the slot in export representation, so
             * cycle through all known transparent accelerators */
            status = PSA_ERROR_NOT_SUPPORTED;
#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
            status = mbedtls_test_transparent_pake_setup(
                        &operation->data.ctx.transparent_test_driver_ctx,
                        inputs );
            if( status == PSA_SUCCESS )
                operation->id = MBEDTLS_TEST_TRANSPARENT_DRIVER_ID;
            /* Declared with fallback == true */
            if( status != PSA_ERROR_NOT_SUPPORTED )
                return( status );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
#if defined(MBEDTLS_PSA_BUILTIN_PAKE)
            status = mbedtls_psa_pake_setup( &operation->data.ctx.mbedtls_ctx,
                        inputs );
            if( status == PSA_SUCCESS )
                operation->id = PSA_CRYPTO_MBED_TLS_DRIVER_ID;
#endif
            return status;
        /* Add cases for opaque driver here */
        default:
            /* Key is declared with a lifetime not known to us */
            (void)operation;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_pake_output(
    psa_pake_operation_t *operation,
    psa_crypto_driver_pake_step_t step,
    uint8_t *output,
    size_t output_size,
    size_t *output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_PAKE)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_pake_output( &operation->data.ctx.mbedtls_ctx, step,
                                             output, output_size, output_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_PAKE */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_pake_output(
                        &operation->data.ctx.transparent_test_driver_ctx,
                        step, output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) step;
            (void) output;
            (void) output_size;
            (void) output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_pake_input(
    psa_pake_operation_t *operation,
    psa_crypto_driver_pake_step_t step,
    const uint8_t *input,
    size_t input_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_PAKE)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_pake_input( &operation->data.ctx.mbedtls_ctx,
                                            step, input,
                                            input_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_PAKE */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_pake_input(
                        &operation->data.ctx.transparent_test_driver_ctx,
                        step,
                        input, input_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) step;
            (void) input;
            (void) input_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_pake_get_shared_key(
    psa_pake_operation_t *operation,
    uint8_t *output, size_t output_size,
    size_t *output_length )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_PAKE)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_pake_get_implicit_key( &operation->data.ctx.mbedtls_ctx,
                                                       output, output_size, output_length ) );
#endif /* MBEDTLS_PSA_BUILTIN_PAKE */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_pake_get_implicit_key(
                        &operation->data.ctx.transparent_test_driver_ctx,
                        output, output_size, output_length ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            (void) output;
            (void) output_size;
            (void) output_length;
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

static inline psa_status_t psa_driver_wrapper_pake_abort(
    psa_pake_operation_t * operation )
{
    switch( operation->id )
    {
#if defined(MBEDTLS_PSA_BUILTIN_PAKE)
        case PSA_CRYPTO_MBED_TLS_DRIVER_ID:
            return( mbedtls_psa_pake_abort( &operation->data.ctx.mbedtls_ctx ) );
#endif /* MBEDTLS_PSA_BUILTIN_PAKE */

#if defined(PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT)
#if defined(PSA_CRYPTO_DRIVER_TEST)
        case MBEDTLS_TEST_TRANSPARENT_DRIVER_ID:
            return( mbedtls_test_transparent_pake_abort(
                        &operation->data.ctx.transparent_test_driver_ctx ) );
#endif /* PSA_CRYPTO_DRIVER_TEST */
#endif /* PSA_CRYPTO_ACCELERATOR_DRIVER_PRESENT */
        default:
            return( PSA_ERROR_INVALID_ARGUMENT );
    }
}

#endif /* MBEDTLS_PSA_CRYPTO_C */
