/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _UWB_FWDL_PROVIDER_H_
#define _UWB_FWDL_PROVIDER_H_

#include "phUwbStatus.h"
#include "phNxpUciHal_fwd.h"
#if UWBIOT_UWBD_SR1XXT

/** @defgroup uwb_fwdl_provider_t UWB FwDl Context Management
 *
 * @{
 */

/** Mode of operation of the Firmware download
 *
 */
typedef enum uwb_fwdl_mode
{
    UWB_FWDL_FACTORY,
    UWB_FWDL_MAINLINE,
} uwb_fwdl_mode_t;

/**
 * @brief Context for the Firmware Download
 *
 *
 */
typedef struct uwb_fwdl
{
    phHbci_MosiApdu_t uwb_fwdl_MosiApdu;
    phHbci_MisoApdu_t uwb_fwdl_MisoApdu;
    Options_t uwb_fwdl_gOpts;

    const uint8_t *fwImgPtr;
    uint32_t fwSize;
    uwb_fwdl_mode_t uwb_fwdl_mode;

} uwb_fwdl_provider_t;

/** @} */

/** @brief  This function is used to download the firmware on the Helios.
 *
 *
 * @param      pCtx     The context
 */
UWBStatus_t uwb_fwdl_downloadFw(uwb_fwdl_provider_t *pCtx);
#endif // UWBIOT_UWBD_SR1XXT
#if UWBIOT_UWBD_SR1XXT_SR2XXT
/** @brief  This function sets the Firmware Download context with firmware image and the firmware size.
 *
 *
 * @param      pAppfwImageCtx     - Firmware Image Context
 * @return     UWBStatus_t        - 0: success, 1: failure
 */
UWBStatus_t uwb_fwdl_setFwImage(const phUwbFWImageContext_t *const pAppfwImageCtx);
#endif // UWBIOT_UWBD_SR1XXT_SR2XXT
#endif //_UWB_FWDL_PROVIDER_H_