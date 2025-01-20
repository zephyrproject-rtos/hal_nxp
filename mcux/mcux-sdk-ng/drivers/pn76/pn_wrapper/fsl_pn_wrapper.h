/*
 * Copyright 2022 NXP.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_COMMON_PN_H_
#define FSL_COMMON_PN_H_

#include "PN76_Status.h"

/*!
 * @addtogroup pn_wrapper
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.pn_wrapper"
#endif

/*! @brief PN_WRAPPER driver version. */
#define FSL_PN_WRAPPER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))

/*! @brief Common Error Codes. */
typedef enum
{
    kStatus_PN_Success        = PN76_STATUS_SUCCESS,         /**< Returned in case of no error. */
    kStatus_PN_Timeout        = PN76_STATUS_TIMEOUT,         /**< No reply received. */
    kStatus_PN_BufferOverflow = PN76_STATUS_BUFFER_OVERFLOW, /**< Buffer Overflow error. */
    kStatus_PN_AuthError      = PN76_STATUS_AUTH_ERROR,      /**< Authentication error. */
    kStatus_PN_MemError       = PN76_STATUS_MEMORY_ERROR,    /**< Wrong EEPROM Read/Write . */
    kStatus_PN_CrcError       = PN76_STATUS_CRC_ERROR,       /**< CRC check failed. */
    kStatus_PN_ResourceError  = PN76_STATUS_RESOURCE_ERROR,  /**< An resource error. */
    kStatus_PN_ExternalField  = PN76_STATUS_EXTERNAL_FIELD,  /**< External RF present/ERROR */
    kStatus_PN_UserCancelled  = PN76_STATUS_USER_CANCELLED,  /**< User cancelled. */
    kStatus_PN_ParameterError = PN76_STATUS_PARAMETER_ERROR, /**< Value to be returned in case of wrong parameter. */
    kStatus_PN_GpadcError     = PN76_STATUS_GPADC_ERROR,     /**< GPADC Error during GPADC Initialization procedure */
    kStatus_PN_InternalError  = PN76_STATUS_INTERNAL_ERROR,  /**< Internal error. */
    kStatus_PN_Busy           = PN76_STATUS_BUSY,            /**< Device or resource busy. */
} pn_status_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_COMMON_PN_H_ */
