/*
 * Copyright 2018-2021, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_SSS_MGMT_H
#define FSL_SSS_MGMT_H

#if !defined(SSS_CONFIG_FILE)
#include "fsl_sss_config.h"
#else
#include SSS_CONFIG_FILE
#endif

#include "fsl_sss_api.h"
#include "fsl_sss_sscp.h"

typedef struct
{
    sss_sscp_session_t *session;
    uint32_t clockFrequency;
    uint32_t ctx;
} sss_mgmt_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @addtogroup sss_management
 * @{
 */

/*! @brief Mgmt context init.
 *  The function initializes mgmt context with initial values.
 *
 * @param context Pointer to mgmt crypto context.
 * @param session Associate SSS session with mgmt context.
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_context_init(sss_mgmt_t *context, sss_sscp_session_t *session);

/*! @brief Get property
 *  The function provides get property service
 *
 * @param context Pointer to mgmt crypto context.
 * @param propertyId Id of the property to read
 * @param destData Address of the destination data
 * @param dataLen Input size of the destData buffer, output actual no of bytes written to destData
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_get_property(sss_mgmt_t *context, uint32_t propertyId, uint8_t *destData, size_t *dataLen);

/*! @brief Set property
 *  The function provides set property service
 *
 * @param context Pointer to mgmt crypto context.
 * @param propertyId Id of the property to write
 * @param srcData Address of the source data
 * @param dataLen Input size of the srcData buffer
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_set_property(sss_mgmt_t *context, uint32_t propertyId, const uint8_t *srcData, size_t dataLen);

/*! @brief Read fuse
 *  The function provides read fuse service
 *
 * @param context Pointer to mgmt crypto context.
 * @param fuseId Id of the fuse to read
 * @param destData Destination address of the read value
 * @param destDataLen Input length of the destData buffer in bytes, actual number of output bytes written to destData
 * @param options Address of the implementation specific data buffer
 * @param optionsLen Input length of the options buffer in bytes, actual number of output bytes written to options
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_fuse_read(sss_mgmt_t *context,
                                uint32_t fuseId,
                                uint32_t *destData,
                                size_t *destDataLen,
                                uintptr_t options,
                                size_t *optionsLen);

/*! @brief Program fuse
 *  The function provides program fuse service
 *
 * @param context Pointer to mgmt crypto context.
 * @param fuseId Id of the fuse to write
 * @param srcData Fuse write value
 * @param srcDataLen Input length of the srcData buffer in bytes, actual number of bytes written to OTP
 * @param options Address of the implementation specific data buffer
 * @param optionsLen Input length of the options buffer in bytes, actual number of output bytes written to options
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_fuse_program(
    sss_mgmt_t *context, uint32_t fuseId, uint32_t *srcData, size_t *srcDataLen, uintptr_t options, size_t *optionsLen);

/*! @brief Get lifecycle
 *  The function provides read lifecycle service
 *
 * @param context Pointer to mgmt crypto context.
 * @param lifecycleData Destination address of the read value
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_get_lifecycle(sss_mgmt_t *context, uint32_t *lifecycleData);
/*! @brief Advance lifecycle
 *  The function provides advance lifecycle service
 *
 * @param context Pointer to mgmt crypto context.
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_advance_lifecycle(sss_mgmt_t *context,
                                        uint32_t *lifecycleData,
                                        uintptr_t options,
                                        size_t *optionsLen);

/*! @brief Move the security sub-system to field return state
 *  The function sends a request for field return
 *
 * @param context Pointer to mgmt crypto context.
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_set_return_fa(sss_mgmt_t *context,
                                    const uint8_t *request,
                                    size_t requestSize,
                                    uintptr_t options,
                                    size_t *optionsLen,
                                    uint32_t *resultState);

/*! @brief Configure host access permissions
 *
 * @param context Pointer to mgmt crypto context.
 * @param secLvl Required security level, must be either equal or lower as security level of the host sending this
 * command
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_set_host_access_permission(sss_mgmt_t *context, const sss_mgmt_security_level_t secLvl);

/*! @brief Attestation
 *  The function provides attestation service.
 *  This service provides a measurement of the security sub-system firmware, version and lifecycle.
 *
 * @param context Pointer to mgmt crypto context.
 * @param destData Address of the destination data buffer
 * @param dataLen Input length of the destination data buffer in bytes, output actual number of bytes written to
 * destData
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_ping(sss_mgmt_t *context);

/*! @brief Removes all keys in SSS
 *  The function sends a request to remove all keys within security sub-system
 *
 * @param context Pointer to mgmt crypto context.
 *
 * @returns Status of the operation
 * @retval kStatus_SSS_Success The operation has completed successfully.
 * @retval kStatus_SSS_Fail The operation has failed.
 * @retval kStatus_SSS_InvalidArgument One of the arguments is invalid for the function to execute.
 */
sss_status_t sss_mgmt_clear_all_keys(sss_mgmt_t *context);

/*! @brief Mgmt context release.
 *  The function frees Mgmt context.
 *
 * @param context Pointer to Mgmt crypto context.
 */
sss_status_t sss_mgmt_context_free(sss_mgmt_t *context);
/*!
 *@}
 */ /* end of sss_management */

#if defined(__cplusplus)
}
#endif

#endif /* FSL_SSS_MGMT_H */
