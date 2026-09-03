/* Copyright 2022-2026 NXP
 *
 * NXP Proprietary. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms.  If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

#ifndef MAINLINE_FIRMWARE_VERSION_H
#define MAINLINE_FIRMWARE_VERSION_H

#include <stdint.h>

#ifdef UWBIOT_USE_FTR_FILE
#include "uwb_iot_ftr.h"
#else
#include "uwb_iot_ftr_default.h"
#endif

#if UWBIOT_UWBD_SR250
/*Select one of the firmware depending upon the host */
/* The following marker is used by firmware integration script, do not edit or delete these
   comments unintentionally, applicable for all the markers in this file */
#if UWBIOT_FW_VARIANT_TRANSIT
/* Selection For SR250 TRANSIT FW Starts Here */
#if UWBIOT_SR1XX_FW_ROW_PROD
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x60
#define UWB_SR2XX_PATCH_NUMBER                              0x03
#elif UWBIOT_SR1XX_FW_ROW_DEV
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x60
#define UWB_SR2XX_PATCH_NUMBER                              0x03
#else
#error "Select anyone of the FW"
#endif
#else // UWBIOT_FW_VARIANT_SMARTHOME
/* Selection For SR250 SMARTHOME FW Starts Here */
#if UWBIOT_SR1XX_FW_ROW_PROD
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x51
#define UWB_SR2XX_PATCH_NUMBER                              0xEF
#elif UWBIOT_SR1XX_FW_ROW_DEV
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x51
#define UWB_SR2XX_PATCH_NUMBER                              0xEF
#else
#error "Select anyone of the FW"
#endif
#endif // UWBIOT_FW_VARIANT_TRANSIT / SMARTHOME
#endif // UWBIOT_UWBD_SR250

#if UWBIOT_UWBD_SR200T || UWBIOT_UWBD_SR200S
/*Select one of the firmware depending upon the host */
/* Selection For SR200T FW Starts Here */
/* Selection For SR200S FW Starts Here */

#if UWBIOT_SR1XX_FW_ROW_PROD
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x50
#define UWB_SR2XX_PATCH_NUMBER                              0xD0
#elif UWBIOT_SR1XX_FW_ROW_DEV
#define UWB_SR2XX_MAJOR_NUMBER                              0x01
#define UWB_SR2XX_MINOR_NUMBER                              0x50
#define UWB_SR2XX_PATCH_NUMBER                              0xD0
#else
#error "Select anyone of the FW"
#endif
#endif // UWBIOT_UWBD_SR200 || UWBIOT_UWBD_SR200S

/* FW selection End */

#endif // MAINLINE_FIRMWARE_VERSION_H
