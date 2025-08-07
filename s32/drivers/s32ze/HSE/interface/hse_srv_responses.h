/**
    @file    hse_srv_responses.h
*
*   @brief   The HSE service responses.
*   @details The service response is provided by MUB_RRx register after the service execution.
*
*   @addtogroup hse_srv_responses HSE Service Responses
*   @ingroup class_interface
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

#ifndef HSE_SRV_RESPONSES_H
#define HSE_SRV_RESPONSES_H

#ifdef __cplusplus
extern "C"{
#endif

#include "hse_platform.h"

#define HSE_START_PRAGMA_PACK
#include "hse_compiler_abs.h"


/** @brief   HSE Service response.
*  @details  The Service response is provided by MUB_RRx register after the service execution. */
typedef uint32_t  hseSrvResponse_t;
#define HSE_SRV_RSP_OK                          ((hseSrvResponse_t)0x55A5AA33UL)  /**< @brief HSE service successfully executed with no error. */
#define HSE_SRV_RSP_VERIFY_FAILED               ((hseSrvResponse_t)0x55A5A164UL)  /**< @brief HSE signals that a verification request fails (e.g. MAC and Signature verification). */
#define HSE_SRV_RSP_INVALID_ADDR                ((hseSrvResponse_t)0x55A5A26AUL)  /**< @brief The address parameters are invalid. */
#define HSE_SRV_RSP_INVALID_PARAM               ((hseSrvResponse_t)0x55A5A399UL)  /**< @brief The HSE request parameters are invalid. */
#define HSE_SRV_RSP_NOT_SUPPORTED               ((hseSrvResponse_t)0xAA55A11EUL)  /**< @brief The operation or feature not supported. */
#define HSE_SRV_RSP_NOT_ALLOWED                 ((hseSrvResponse_t)0xAA55A21CUL)  /**< @brief The operation is not allowed because of some restrictions (in attributes, life-cycle dependent operations, key-management, etc.). */
#define HSE_SRV_RSP_NOT_ENOUGH_SPACE            ((hseSrvResponse_t)0xAA55A371UL)  /**< @brief There is no enough space to perform service (e.g. format key store) */
#define HSE_SRV_RSP_READ_FAILURE                ((hseSrvResponse_t)0xAA55A427UL)  /**< @brief The service request failed because read access was denied. For HSE_B, it can be returned if Host Flash Programming/Erase operaton was in progress at the time of giving the command. */
#define HSE_SRV_RSP_WRITE_FAILURE               ((hseSrvResponse_t)0xAA55A517UL)  /**< @brief The service request failed because write access was denied */
#define HSE_SRV_RSP_STREAMING_MODE_FAILURE      ((hseSrvResponse_t)0xAA55A6B1UL)  /**< @brief The service request that uses streaming mode failed (e.g. UPDATES and FINISH steps do not use the same HSE interface ID and channel ID as START step). */
#define HSE_SRV_RSP_KEY_NOT_AVAILABLE           ((hseSrvResponse_t)0xA5AA51B2UL)  /**< @brief This error code is returned if a key is locked due to failed boot measurement or an active debugger. */
#define HSE_SRV_RSP_KEY_INVALID                 ((hseSrvResponse_t)0xA5AA52B4UL)  /**< @brief The key usage flags (provided using the key handle) don't allow to perform the requested crypto operation (the key flags don't match the crypto operation;
                                                                                              e.g. the key is configured to be used for decryption, and the host requested an encryption). In SHE, the key ID provided is either invalid or non-usable
                                                                                              due to some flag restrictions. */
#define HSE_SRV_RSP_KEY_EMPTY                   ((hseSrvResponse_t)0xA5AA5317UL)  /**< @brief Specified key slot is empty. */
#define HSE_SRV_RSP_KEY_WRITE_PROTECTED         ((hseSrvResponse_t)0xA5AA5436UL)  /**< @brief Key slot to be loaded is protected with WRITE PROTECTION restriction flag. */
#define HSE_SRV_RSP_KEY_UPDATE_ERROR            ((hseSrvResponse_t)0xA5AA5563UL)  /**< @brief Used only in the context of SHE specification: specified key slot cannot be updated due to errors in verification of the parameters. */
#define HSE_SRV_RSP_MEMORY_FAILURE              ((hseSrvResponse_t)0x33D6D136UL)  /**< @brief Detect physical errors, flipped bits etc., during memory read or write operations. */
#define HSE_SRV_RSP_CANCEL_FAILURE              ((hseSrvResponse_t)0x33D6D261UL)  /**< @brief The service can not be canceled. */
#define HSE_SRV_RSP_CANCELED                    ((hseSrvResponse_t)0x33D6D396UL)  /**< @brief The service has been canceled. */
#define HSE_SRV_RSP_GENERAL_ERROR               ((hseSrvResponse_t)0x33D6D4F1UL)  /**< @brief This error code is returned if an error not covered by the error codes above is detected inside HSE. */
#define HSE_SRV_RSP_COUNTER_OVERFLOW            ((hseSrvResponse_t)0x33D6D533UL)  /**< @brief The monotonic counter overflows. */
#define HSE_SRV_RSP_SHE_NO_SECURE_BOOT          ((hseSrvResponse_t)0x33D6D623UL)  /**< @brief HSE did not perform SHE based secure Boot. */
#define HSE_SRV_RSP_SHE_BOOT_SEQUENCE_ERROR     ((hseSrvResponse_t)0x33D7D83AUL)  /**< @brief Received SHE_BOOT_OK or SHE_BOOT_FAILURE more then one time. */
#define HSE_SRV_RSP_RNG_INIT_IN_PROGRESS        ((hseSrvResponse_t)0x33D7D92AUL)  /**< @brief This error code is returned if RNG Intialization is in Progress. */

#ifdef HSE_SPT_IPSEC
#define HSE_SRV_RSP_IPSEC_INVALID_DATA          ((hseSrvResponse_t)0xDD333133UL)  /**< @brief Invalid (malformed) IP packet */
#define HSE_SRV_RSP_IPSEC_REPLAY_DETECTED       ((hseSrvResponse_t)0xDD3332DDUL)  /**< @brief Valid packet but replay detected */
#define HSE_SRV_RSP_IPSEC_REPLAY_LATE           ((hseSrvResponse_t)0xDD3333A5UL)  /**< @brief Valid packet but frame late in sequence */
#define HSE_SRV_RSP_IPSEC_SEQNUM_OVERFLOW       ((hseSrvResponse_t)0xDD33343DUL)  /**< @brief Sequence number overflow */
#define HSE_SRV_RSP_IPSEC_CE_DROP               ((hseSrvResponse_t)0xDD33A15AUL)  /**< @brief Decap CE DROP (ECN issue) error */
#define HSE_SRV_RSP_IPSEC_TTL_EXCEEDED          ((hseSrvResponse_t)0xDD33A2D3UL)  /**< @brief Packet decrypted but TTL exceeded */
#define HSE_SRV_RSP_IPSEC_VALID_DUMMY_PAYLOAD   ((hseSrvResponse_t)0xDD33A3D5UL)  /**< @brief Valid Dummy Payload (type 59) */
#define HSE_SRV_RSP_IPSEC_HEADER_LEN_OVERFLOW   ((hseSrvResponse_t)0xDD33A4D9UL)  /**< @brief Operation successful, but IPsec additions cause overflow of IP header length field */
#define HSE_SRV_RSP_IPSEC_PADDING_CHECK_FAIL    ((hseSrvResponse_t)0xDD33A53AUL)  /**< @brief IPsec padding check error found */
#endif

#define HSE_SRV_RSP_FUSE_WRITE_FAILURE          ((hseSrvResponse_t)0xBB4456E7UL)  /**< @brief This error code is returned, if fuse write operation fail. */
#define HSE_SRV_RSP_FUSE_VDD_GND                ((hseSrvResponse_t)0xBB4457F3UL)  /**< @brief This error code is returned, if EFUSE_VDD connected to ground during fuse write operation. */

#define HSE_SRV_RSP_SBAF_UPDATE_REQUIRED        ((hseSrvResponse_t)0xCC66FEADUL)  /**< @brief This error code is returned, if operation is dependent on Secure BAF version, which on the device happens to be old. */

#define HSE_STOP_PRAGMA_PACK
#include "hse_compiler_abs.h"

#ifdef __cplusplus
}
#endif
#endif /*  HSE_SRV_RESPONSES_H */

/** @} */
