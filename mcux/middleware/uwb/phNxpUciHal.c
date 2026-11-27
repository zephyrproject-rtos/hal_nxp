/*
 * Copyright (C) 2019-2024,2026 NXP Semiconductors
 * SPDX-License-Identifier: Apache-2.0
 */

#include "phNxpUciHal.h"
#include "zephyr/uwb/uwb_types.h"
#include "zephyr/uwb/tml.h"
#include "uwb_tml_transport.h"
#include "phUwbTypes.h"
#include "zephyr/uwb/uci.h"
#include "uci_ext_defs.h"
#include "zephyr/uwb/uwb_types.h"
#include "zephyr/kernel.h"
#include "phNxpUwbConfig.h"
#include "zephyr/uwb/uwb_core.h"
#include "uci_ext_defs.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_uci_hal, LOG_LEVEL_INF);

#if !(UWBIOT_UWBD_SR04X)

#include <UwbApi_Types_Proprietary.h>
#endif //!(UWBIOT_UWBD_SR04X)

#include "phUwbStatus.h"

/**  Device State - IDLE */
#define UWB_UCI_DEVICE_INIT 0x00
/**  Device State - READY */
#define UWB_UCI_DEVICE_READY 0x01
/** Device State - ERROR */
#define UWB_UCI_DEVICE_ERROR 0xFF

struct k_sem g_uwb_nxp_semaphore;

/* Static function declarations */

extern int phNxpUciHal_fw_download(void);
static uint8_t phNxpUciHal_uwb_reset(void);
/**
 * Function         phNxpUciHal_uwbDeviceInit
 *
 * Description      This function is called to initialize UWB device. It performs
 *                  firmware download and set device configuration
 * Returns          return status
 *
 */
int phNxpUciHal_uwbDeviceInit(BOOLEAN recovery);

uint8_t UwbDeviceInit(bool recovery)
{
    uint8_t status = 0;
    int temp_status;
    temp_status             = phNxpUciHal_uwbDeviceInit(recovery);
    if(temp_status != UWBSTATUS_SUCCESS) {
        status = UWBSTATUS_FAILED;
    }
    else{
        status = UWBSTATUS_SUCCESS;
    }
    return status;
}

int phNxpUciHal_uwbDeviceInit(BOOLEAN recovery)
{
    int status;
    LOG_DBG(" Start FW download");
    static bool uwb_device_initialized        = FALSE;
    static struct k_sem semaphore;
    /* Initiate semaphore */
    if (!uwb_device_initialized) {
        if (k_sem_init(&semaphore, 0, 1) != UWB_STATUS_CODE_SUCCESS) {
            LOG_ERR("Semaphore creation failed");
            return UWBSTATUS_FAILED;
        }
        if (0 != k_sem_init(&g_uwb_nxp_semaphore, 0, 1)) {
            LOG_ERR("Could not create g_uwb_nxp_semaphore");
            return UWB_STATUS_CODE_FAILED;
        }
    }
    uwb_device_initialized = TRUE;
    if (recovery == TRUE) {
        (void)phTmlUwb_reset(0);
        phTmlUwb_suspendReader();
#if (UWBIOT_TML_PNP || UWBIOT_TML_SOCKET)
        phTmlUwb_set_mode_fwdld();
        phTmlUwb_reset_uwbs();
#endif // (UWBIOT_TML_PNP || UWBIOT_TML_SOCKET)
    }

#if (UWBIOT_UWBD_SR04X)
    status = UWBSTATUS_SUCCESS;
#if UWBIOT_TML_SPI
    uwb_transport_io_set(kUWBS_IO_O_RSTN, 0);
    k_msleep(10);
    uwb_transport_io_set(kUWBS_IO_O_RSTN, 1);
#endif /* (UWBIOT_TML_SPI) */
#endif /* (UWBIOT_UWBD_SR04X) */

#if UWBIOT_UWBD_SR2XXT
    uwb_tml_read_abort();
#if UWBIOT_OS_NATIVE
    /* Issue a read abort in the kernel space*/
    uwb_tml_reset(ABORT_READ_PENDING);
#endif
    status = phNxpUciHal_fw_download();
#endif // UWBIOT_UWBD_SR2XXT

#if UWBIOT_UWBD_SR1XXT
    LOG_INF("Starting FW download");
    status = phNxpUciHal_fw_download();
#if UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
    if (status != UWBSTATUS_SUCCESS) {
        /* Retry, just once more...
         * This failure is seen in PNP PC Windows mode, where if there was no clean
         * shut down, above call seems to fail, so sending again.
         */
        status = phNxpUciHal_fw_download();
    }
#endif // UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
#endif // UWBIOT_UWBD_SR1XXT
    if (status == UWBSTATUS_SUCCESS) {
#if UWBIOT_UWBD_SR1XXT
        LOG_INF("FW Download done.");
#endif // UWBIOT_UWBD_SR1XXT
        /** Restart TML if it was de-initialized */
        uwb_tml_init();
        if (recovery == TRUE) {
            phTmlUwb_resumeReader();
        }

        status = (int) uwb_tml_read();
    }
#if UWBIOT_UWBD_SR1XXT
    else {
        LOG_ERR("FW download is failed: status= %x", status);
        status = UWBSTATUS_FAILED;
        goto clean_and_return;
    }
#endif // UWBIOT_UWBD_SR1XXT

    if (status == UWBSTATUS_SUCCESS) {
        // Wait for device init ntf
        uint8_t buffer[20] = {0};
        uint32_t bufferLen = 20;
        const k_timeout_t timeout = Z_TIMEOUT_MS(5000);

        void *pScheduledPacket = uwb_uci_schedule_packet_read(UCI_MT_NTF, UCI_GID_CORE, UCI_MSG_CORE_DEVICE_STATUS_NTF, buffer, &bufferLen, &semaphore);
        // status = uwb_uci_wait_for_packet(UCI_MT_NTF, UCI_GID_CORE, UCI_MSG_CORE_DEVICE_STATUS_NTF, buffer, &bufferLen, 5000);
        // if (0 != status) {
        if (NULL == pScheduledPacket) {
            /** Timed out */
            LOG_ERR("%s: Sem Timed out", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
        if (k_sem_take(&semaphore, timeout) != 0) {
            LOG_ERR("%s: Sem Timed out", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
#if UWBIOT_UWBD_SR1XXT
        if (buffer[4] != UWB_UCI_DEVICE_INIT) {
            LOG_ERR("%s: device status is failed", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
#else
        if (buffer[4] != UWB_UCI_DEVICE_READY) {
            LOG_ERR("%s: device status is failed", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
#endif /* UWBIOT_UWBD_SR1XXT */

#if !(UWBIOT_UWBD_SR04X)
        /* set board variant */
        status = phNxpUciHal_set_board_config();
        if (status != 0) {
            LOG_ERR("%s: set board config is failed with status %d", __FUNCTION__, status);
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }

        // wait for dev ready ntf
        bufferLen = sizeof(buffer);
        if (k_sem_take(&semaphore, timeout) != 0) {
            LOG_ERR("%s: Sem Timed out", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
        if (buffer[4] != UWB_UCI_DEVICE_READY) {
            LOG_ERR("%s: device not ready", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
#endif /*!(UWBIOT_UWBD_SR04X)*/
        // reset device FIXME: Need to revert this once the RESET issue is fixed.
        status = phNxpUciHal_uwb_reset();
        if (status != UWBSTATUS_OK) {
            LOG_ERR("%s: Device reset Failed", __FUNCTION__);
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }

        // wait for dev ready ntf
        bufferLen = sizeof(buffer);
        if (k_sem_take(
                &semaphore, timeout) != UWB_STATUS_CODE_SUCCESS) {
            LOG_ERR("%s: Sem Timed out", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            uwb_uci_remove_scheduled_packet(pScheduledPacket);
            goto clean_and_return;
        }
        uwb_uci_remove_scheduled_packet(pScheduledPacket);
        if (buffer[4] != UWB_UCI_DEVICE_READY) {
            LOG_ERR("%s: device status is failed", __FUNCTION__);
            status = UWBSTATUS_FAILED;
            goto clean_and_return;
        }
    }

clean_and_return:
    k_sem_reset(&semaphore);

    return status;
}
/**
 * Function         phNxpUciHal_uwb_reset
 *
 * Description      This function is called to reset uwb device
 * Returns          return 0 on success and -1 on fail, On success
 *                  update the actual state of operation in arg pointer
 *
 */
static uint8_t phNxpUciHal_uwb_reset()
{
    // uint8_t status;
    // uint8_t buffer[] = {0x20, 0x00, 0x00, 0x01, 0x00};
    // status           = (uint8_t)phNxpUciHal_send_ext_cmd(sizeof(buffer), buffer);

    uint8_t payload[] = {0, };
    uint8_t response[10] = {0};
    uint16_t payload_len = sizeof(payload);
    uint32_t response_len = sizeof(response);

    int ret = uwb_uci_transceive_control_packet(UCI_GID_CORE, UCI_MSG_CORE_DEVICE_RESET,
                        payload, payload_len,
                        response, &response_len);

    if (0 != ret) {
        /** Could not transceive UCI packet */
        return UWBSTATUS_FAILED;
    }
    return UWBSTATUS_SUCCESS;
}

int phNxpUciHal_SerializeCoreDevConfig(const phUwbCoreDevConfig_t *pCoreDevConfig, uint8_t numConfigs, uint8_t *pCmdBuff, uint16_t *pCmdLen)
{
    LOG_DBG("Entering %s", __func__);
    uint16_t offset = 0;
    bool status = TRUE;

    if (pCoreDevConfig == NULL || pCmdBuff == NULL || pCmdLen == NULL) {
        LOG_ERR("Invalid parameters");
        if (pCmdLen != NULL) {
            *pCmdLen = 0;
        }
        status = FALSE;
        goto exit;
    }

    if (numConfigs == 0) {
        *pCmdLen = 0;
        LOG_DBG("No Configs to be set");
        /* Return true, as no configs to be serialized */
        status = TRUE;
        goto exit;
    }

    const uint16_t total_buffer_size = *pCmdLen;

    /* Check minimum buffer size for header */
    if (total_buffer_size < UCI_HEADER_SIZE + 1) {
        LOG_ERR("Buffer too small for header");
        *pCmdLen = 0;
        status = FALSE;
        goto exit;
    }

    /* command formation */
    pCmdBuff[offset++] = UCI_MTS_CMD | UCI_GID_CORE;
    pCmdBuff[offset++] = UCI_MSG_CORE_SET_CONFIG;
    pCmdBuff[offset++] = 0x00;
    pCmdBuff[offset++] = 0x00; /* Payload length placeholder */
    pCmdBuff[offset++] = numConfigs;


    /* Serialize the configuration parameters */
    for (uint8_t itr = 0; itr < numConfigs; itr++) {

        if (pCoreDevConfig[itr].pParam_value == NULL) {
            LOG_ERR("Null pParam_value at index %d", itr);
            *pCmdLen = 0;
            status = FALSE;
            goto exit;
        }

        /* Calculate required space for this config entry */
        uint16_t param_id_size = 1;
#if (UWBIOT_UWBD_SR1XXT_SR2XXT)
        /* check if param_id is of 2 bytes or 1 byte by checking if the 1st byte holds extended*/
        if ((((pCoreDevConfig[itr].param_id >> 8) & 0xFF) == EXTENDED_DEVICE_CONFIG_ID) ||
            (((pCoreDevConfig[itr].param_id >> 8) & 0xFF) == EXTENDED_DBG_DEVICE_CONFIG_ID)) {
            param_id_size = 2;
        }
#endif /* (UWBIOT_UWBD_SR1XXT_SR2XXT) */

        /* current position + p_param_id size + param_len + param value len */
        uint16_t required_size = offset + param_id_size + 1 + pCoreDevConfig[itr].param_len;

        /* Check buffer bounds before writing */
        if (required_size > total_buffer_size) {
            LOG_ERR("Buffer overflow at index %d: required %d, available %d",
                    itr, required_size, total_buffer_size);
            *pCmdLen = 0;
            status = FALSE;
            goto exit;
        }

#if (UWBIOT_UWBD_SR1XXT_SR2XXT)
        if (param_id_size == 2) {
            UWB_UINT16_TO_BE_STREAM(pCmdBuff, pCoreDevConfig[itr].param_id, offset);
        }
        else
#endif /* (UWBIOT_UWBD_SR1XXT_SR2XXT) */
        {
            UWB_UINT8_TO_BE_STREAM(pCmdBuff, pCoreDevConfig[itr].param_id, offset);
        }
        UWB_UINT8_TO_BE_STREAM(pCmdBuff, pCoreDevConfig[itr].param_len, offset);
        UWB_ARRAY_TO_STREAM(pCmdBuff, pCoreDevConfig[itr].pParam_value, pCoreDevConfig[itr].param_len, offset);
    }

    /* Update payload length */
    pCmdBuff[UCI_LENGTH_OFFSET] = offset - UCI_HEADER_SIZE;

    /* Set total command length */
    *pCmdLen = offset;

    /* Check if command size is within limits of UCI_MAX_CTRL_PACKET_PAYLOAD_SIZE*/
    if ((*pCmdLen) >= UCI_HEADER_SIZE + UCI_MAX_CTRL_PACKET_PAYLOAD_SIZE) {
        LOG_ERR("Command size exceeded, %d", *pCmdLen);
        *pCmdLen = 0;
        status = FALSE;
        goto exit;
    }

exit:

    LOG_DBG("Exiting %s with length %d", __func__, *pCmdLen);
    return status;
}

#if UWBIOT_UWBD_SR1XXT_SR2XXT
int phNxpUciHal_SerializeCalibConfig(const phUwbCalibConfig_t *pCalibConfig, uint8_t *pCmdBuff, uint16_t *pCmdLen){

    LOG_DBG("Entering %s", __func__);
    bool status = TRUE;
    uint16_t offset = 0;

    if (pCalibConfig == NULL || pCmdBuff == NULL || pCmdLen == NULL || pCalibConfig->pCalib_value == NULL) {
        LOG_ERR("Invalid parameters");
        if (pCmdLen != NULL) {
            *pCmdLen = 0;
        }
        status = FALSE;
        goto exit;
    }

    const uint16_t total_buffer_size = *pCmdLen;

    /* Calculate required size based on calib_id type */
    uint16_t calib_id_size = (((pCalibConfig->calib_id >> 8) & 0xFF) == EXTENTED_CALIB_PARAM_ID) ? 2 : 1;
    /* Header + Channel_id + 1 or 2 bytes for calid_id + 1 or 2 bytes for calib_len(calib_id_size) + calib_value */
    uint16_t required_size = UCI_HEADER_SIZE + 1 + calib_id_size + calib_id_size + pCalibConfig->calib_len;

    /* Check buffer bounds */
    if (required_size > total_buffer_size) {
        LOG_ERR("Buffer overflow: required %d, available %d", required_size, total_buffer_size);
        *pCmdLen = 0;
        status = FALSE;
        goto exit;
    }

    /* command formation */
    pCmdBuff[offset++] = UCI_MTS_CMD | UCI_GID_PROPRIETARY_CUSTOM_2;
    pCmdBuff[offset++] = VENDOR_UCI_MSG_SET_DEVICE_CALIBRATION;
    pCmdBuff[offset++] = 0x00;
    pCmdBuff[offset++] = 0x00; /* Payload length placeholder */


    /* command formation */
    UWB_UINT8_TO_STREAM(pCmdBuff, pCalibConfig->channel_id, offset);

    if (((pCalibConfig->calib_id >> 8) & 0xFF) == EXTENTED_CALIB_PARAM_ID) {
        UWB_UINT16_TO_BE_STREAM(pCmdBuff, pCalibConfig->calib_id, offset);
        UWB_UINT16_TO_STREAM(pCmdBuff, pCalibConfig->calib_len, offset);
    }
    else
    {
        UWB_UINT8_TO_STREAM(pCmdBuff, pCalibConfig->calib_id, offset);
        UWB_UINT8_TO_STREAM(pCmdBuff, pCalibConfig->calib_len, offset);
    }

    UWB_ARRAY_TO_STREAM(pCmdBuff, pCalibConfig->pCalib_value, pCalibConfig->calib_len, offset);

    /* Update payload length */
    pCmdBuff[UCI_LENGTH_OFFSET] = offset - UCI_HEADER_SIZE;

    /* Set total command length */
    *pCmdLen = offset;

exit:

      LOG_DBG("Exiting %s with length %d", __func__, *pCmdLen);
      return status;
}
#endif /* UWBIOT_UWBD_SR1XXT_SR2XXT */

