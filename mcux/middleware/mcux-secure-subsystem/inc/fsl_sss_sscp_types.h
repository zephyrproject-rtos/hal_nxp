/*
 * Copyright 2018-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SSS_APIS_INC_FSL_SSS_SSCP_TYPES_H_
#define SSS_APIS_INC_FSL_SSS_SSCP_TYPES_H_

/* ************************************************************************** */
/* Includes                                                                   */
/* ************************************************************************** */

#include <fsl_sscp_commands.h>
#include <fsl_sss_api.h>
#if !defined(SSS_FTR_FILE)
#include "fsl_sss_ftr_default.h"
#else
#include SSS_FTR_FILE
#endif

#if SSS_HAVE_SSCP
#include <fsl_sscp.h>

#if SSS_HAVE_A71CH || SSS_HAVE_SE050_EAR
#include <HLSETypes.h>
#include <fsl_sss_keyid_map.h>
#endif

/**
 * @addtogroup sss_sscp
 * @{
 */

/* ************************************************************************** */
/* Defines                                                                    */
/* ************************************************************************** */

#define SSS_SSCP_CONNECTIONTYPE_SOCKET 0x01
#define SSS_SSCP_CONNECTIONTYPE_VCOM   0x02
#define SSS_SSCP_CONNECTIONTYPE_SCI2C  0x03

#define SSS_SUBSYSTEM_TYPE_IS_SSCP(subsystem) ((subsystem == kType_SSS_SE_A71CH) || (subsystem == kType_SSS_SE_SE050))

/* ************************************************************************** */
/* Structrues and Typedefs                                                    */
/* ************************************************************************** */

struct _sss_sscp_key_store;

typedef struct _sss_sscp_session
{
    /* Implementation defined */
    sss_type_t subsystem;
    sscp_context_t *sscp_context;
} sss_sscp_session_t;

typedef struct _sss_sscp_key_store
{
    sss_sscp_session_t *session;
    /*! Implementation specific part */
} sss_sscp_key_store_t;

typedef struct _sss_sscp_object
{
    /*! key store holding the data and other properties */
    sss_sscp_key_store_t *keyStore;
    /*! TODO define object types */
    uint32_t objectType;
    /*! Application specific key identifier. The keyId is kept in the key  store
     * along with the key data and other properties. */
    uint32_t keyId;

    void *transientObject;
    uint32_t transientObjectLen;

} sss_sscp_object_t;

typedef struct _sss_sscp_derive_key
{
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject;
    sss_algorithm_t algorithm; /*!  */
    sss_mode_t mode;           /*!  */

    /*! Implementation specific part */
    uint32_t sessionId; /*!  */
} sss_sscp_derive_key_t;

typedef struct _sss_sscp_asymmetric
{
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject;
    sss_algorithm_t algorithm; /*!  */
    sss_mode_t mode;           /*!  */

    uint32_t sessionId; /*!  */
} sss_sscp_asymmetric_t;

typedef struct _sss_sscp_symmetric
{
    /*! Virtual connection between application (user context) and specific
     * security subsystem and function thereof. */
    sss_sscp_session_t *session;
    sss_sscp_object_t *keyObject; /*!< Reference to key and it's properties. */
    sss_algorithm_t algorithm;    /*!  */
    sss_mode_t mode;              /*!  */
    uint32_t sessionId;           /*!  */

} sss_sscp_symmetric_t;

/* ************************************************************************** */
/* Global Variables                                                           */
/* ************************************************************************** */

/* ************************************************************************** */
/* Functions                                                                  */
/* ************************************************************************** */

#endif /* SSS_HAVE_SSCP */

#define SSS_SESSION_TYPE_IS_SSCP(session) (session && SSS_SUBSYSTEM_TYPE_IS_SSCP(session->subsystem))

#define SSS_KEY_STORE_TYPE_IS_SSCP(keyStore) (keyStore && SSS_SESSION_TYPE_IS_SSCP(keyStore->session))

#define SSS_OBJECT_TYPE_IS_SSCP(pObject) (pObject && SSS_KEY_STORE_TYPE_IS_SSCP(pObject->keyStore))

#define SSS_DERIVE_KEY_TYPE_IS_SSCP(context) (context && SSS_SESSION_TYPE_IS_SSCP(context->session))

#define SSS_ASYMMETRIC_TYPE_IS_SSCP(context) (context && SSS_SESSION_TYPE_IS_SSCP(context->session))

#define SSS_SYMMETRIC_TYPE_IS_SSCP(context) (context && SSS_SESSION_TYPE_IS_SSCP(context->session))

/** @} */

#endif /* SSS_APIS_INC_FSL_SSS_SSCP_TYPES_H_ */
