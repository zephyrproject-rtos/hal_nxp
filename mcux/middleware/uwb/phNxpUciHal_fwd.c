/*
 *
 * Copyright 2021-2026 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "phUwbTypes.h"
#include "phNxpUciHal_fwd.h"
#include "uwb_tml_proprietary.h"
#include <uwb_tml_transport.h>
#include <mainline_firmware_version.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(nxp_fwd, LOG_LEVEL_INF);

#define FWDL_STREAM_TO_UINT32(u32, p)                                                                        \
    {                                                                                                        \
        u32 = (((uint32_t)(*(p))) | ((((uint32_t)(*((p) + 1)))) << 8) | ((((uint32_t)(*((p) + 2)))) << 16) | \
               ((((uint32_t)(*((p) + 3)))) << 24));                                                          \
        (p) += 4;                                                                                            \
    }

#define MAX_FRAME_LEN 4200

/**Local Function Prototypes */
static void printStatusErrorType(uint8_t status_error_msg);
static void print_device_life_cycle_str(uint32_t device_life_cycleu32);
static void print_session_control_str(uint32_t session_controlu8);
static void print_rom_version_str(uint8_t rom_version);
static void print_at_page_status(uint8_t at_status);
static void check_fw_update_required(phUwbFWImageCtx_t *pfwImageCtx);
static phFWD_Status_t phLoadFwBinary(phUwbFWImageCtx_t *pfwImageCtx);
static phFWD_Status_t phGetUwbDeviceInfo(void);
static uint16_t phHal_Host_CalcCrc16(uint8_t *p, uint32_t dwLength);

static phUwbFWImageCtx_t fwImageCtx;

phFWD_Status_t phGenericSendAndRecv(uint8_t *payload, uint16_t len, uint8_t *read_buff, uint16_t *rsp_buf_len)
{
    phFWD_Status_t ret = FW_DNLD_FAILURE;

    size_t sz_rspBufLen     = *rsp_buf_len;
    uint16_t calculated_crc = 0;
    uint16_t received_crc   = 0;

    /**
     * * UCI Payload:
     *   - Macro: `#define ACTUAL_PACKET_START (UCI_CMD_INDEX + N)`
     *   - Description: Refers to the section of the buffer where the actual UCI (UWB Command Interface)
     *                : data will be stored, starting after the platform-specific and bidirectional
     * bytes.
     *   - For any Uwbs all Bidirectional and Platform specific handling done on the Transport layer.
     *   - And actual Payload for the Read start from the "ACTUAL_PACKET_START"
     *
     */

    uint8_t *pActualDataRead = &read_buff[ACTUAL_PACKET_START];
    if ((phTmlUwb_hdll_transceive(payload, len, &read_buff[0], &sz_rspBufLen)) == kUWBSTATUS_SUCCESS) {
        if (sz_rspBufLen < 2) {
            LOG_ERR("%s: invalid length", __FUNCTION__);
        }
        else {
            // increment the platform buffer 2 bytes
            received_crc   = (uint16_t)((pActualDataRead[sz_rspBufLen - 2] << 8) + pActualDataRead[sz_rspBufLen - 1]);
            calculated_crc = phHal_Host_CalcCrc16(pActualDataRead, (uint32_t)(sz_rspBufLen - 2));
            if (received_crc != calculated_crc) {
                LOG_ERR("%s: crc check failed received:0x%02X calculated:0x%02X",
                    __FUNCTION__,
                    received_crc,
                    calculated_crc);
            }
            else {
                *rsp_buf_len = (uint16_t)sz_rspBufLen;
                ret          = FW_DNLD_SUCCESS;
            }
        }
    }

    return ret;
}

#define MY_CASE_ERROR(value, the_string) \
    case (value):                        \
        LOG_ERR(the_string); \
        break

#define MY_CASE_INFO(value, the_string)        \
    case (value):                              \
        LOG_INF("\t" #the_string); \
        break

static void printStatusErrorType(uint8_t status_error_msg)
{
    switch (status_error_msg) {
        MY_CASE_INFO(0x00, "Success");
        MY_CASE_ERROR(0x01, "Acknowledgement");
        MY_CASE_ERROR(0x02, "Ready");
        MY_CASE_ERROR(0x80, "Generic Error");
        MY_CASE_ERROR(0x81, "Memory Error");
        MY_CASE_ERROR(0x82, "Timeout Error");
        MY_CASE_ERROR(0x83, "CRC Error");
        MY_CASE_ERROR(0x84, "Invalid Error");
        MY_CASE_ERROR(0x90, "Invalid Length Error");
        MY_CASE_ERROR(0x91, "Invalid Address Error");
        MY_CASE_ERROR(0x92, "ECC Signature error. Firmware not compatible with device.");
        MY_CASE_ERROR(0x93, "SHA384 Error");
        MY_CASE_ERROR(0x94, "Lifecycle validity Error. Ensure device lifecycle matches firmware lifecycle.");
        MY_CASE_ERROR(0x95, "Chip ID Error");
        MY_CASE_ERROR(0x96, "Chip Version Error");
        MY_CASE_ERROR(0x97, "Certificate Version Error");
        MY_CASE_ERROR(0x98, "FW Version Error");
        MY_CASE_ERROR(0x99, "SRAM Download Allow Error");
        MY_CASE_ERROR(0xA0, "Key derivation Error");
        MY_CASE_ERROR(0xA1, "AES Decryption error");
        MY_CASE_ERROR(0xA2, "Invalid Encrypted Payload Error");
        MY_CASE_ERROR(0xB0, "N-1/N-2 page read Error");
        MY_CASE_ERROR(0xB1, "N-1/N-2 page write Error");
        MY_CASE_ERROR(0xB2, "Lifecycle update Error");
        MY_CASE_ERROR(0xC0, "Flash Blank Page Error");

    default:
        LOG_ERR("Error... 0x%02X!!!", status_error_msg);
    }
}

static void print_device_life_cycle_str(uint32_t device_life_cycleu32)
{
    switch (device_life_cycleu32) {
        MY_CASE_INFO(0xCCCCCCCC, "Lifecycle Virgin/Unknown");
        MY_CASE_INFO(0x5C5C5C5C, "Lifecycle Degraded");
        MY_CASE_INFO(0xAAAAAAAA, "Lifecycle Flash Test");
        MY_CASE_INFO(0xC5C5C5C5, "Lifecycle Development");
        MY_CASE_INFO(0xA5A5A5A5, "Lifecycle Customer");
        MY_CASE_INFO(0x55555555, "Lifecycle Protected");
        MY_CASE_INFO(0x5A5A5A5A, "Lifecycle NXP RMA");
    default:
        LOG_WRN("\tUnknown LC 0x%08X", device_life_cycleu32);
        break;
    }
}

static void print_session_control_str(uint32_t session_controlu8)
{
    switch (session_controlu8) {
        MY_CASE_INFO(0x55, "Session Control Close");
        MY_CASE_INFO(0xAA, "Session Control Open");
    default:
        LOG_WRN("\tUnknown Session Control 0x%02X", session_controlu8);
        break;
    }
}

static void print_rom_version_str(uint8_t rom_version)
{
    switch (rom_version) {
        MY_CASE_INFO(0x2, "ROM Version A1V1");
        MY_CASE_INFO(0x3, "ROM Version A1V2");
    default:
        LOG_WRN("\tUnknown ROM Version 0x%02X", rom_version);
        break;
    }
}

static void print_at_page_status(uint8_t at_status)
{
    switch (at_status) {
        MY_CASE_INFO(0x55, "N-1/N-2 Page is OK");
        MY_CASE_INFO(0x5A, "RECOVERED N-1");
        MY_CASE_INFO(0xA5, "RECOVERED N-2");
        MY_CASE_INFO(0xAA, "ERROR");
    default:
        LOG_WRN("\tUnknown AT Page Status 0x%02X", at_status);
        break;
    }
}
void print_getInfoExtRsp(phHDLLGetInfoExt_t *getInfoExtRsp)
{
    uint8_t i = 0, offset = 0;
    int charsWritten               = 0;
    char buff[HDLL_READ_BUFF_SIZE] = {0};
    if (NULL == getInfoExtRsp) {
        LOG_ERR("%s getInfoExtRsp is null", __FUNCTION__);
        return;
    }
    LOG_INF("=====================GET_INFO_EXT =======================\n");
    LOG_DBG("Fw Info length: 0x%02X\n", getInfoExtRsp->fw_info_length);
    LOG_DBG("Fw Rc version Tag: 0x%02X\n", getInfoExtRsp->fw_rc_version_tag);
    LOG_DBG("Fw Rc version length: 0x%02X\n", getInfoExtRsp->fw_rc_version_length);
    LOG_INF("Fw Rc version value: 0x%02X\n", getInfoExtRsp->fw_rc_version_value);
    LOG_DBG("git hash Tag: 0x%02X\n", getInfoExtRsp->git_hash_tag);
    LOG_DBG("git hash length: 0x%02X\n", getInfoExtRsp->git_hash_length);
    for (i = 0, offset = 0; i != 34; i += 2) { // 17 bytes
        charsWritten = sprintf(&buff[i], "%02X", getInfoExtRsp->git_hash_value[offset++]);
        if (charsWritten < 0) {
            LOG_ERR("sprintf failed while writing git hash value at offset=%u", offset - 1);
            return;
        }
    }
    buff[i] = '\0';
    LOG_DBG("git hash value: 0x%s\n", buff);
    LOG_DBG("variant version tag: 0x%02X\n", getInfoExtRsp->variant_version_tag);
    LOG_DBG("variant version length : 0x%02X\n", getInfoExtRsp->variant_version_length);
    LOG_DBG("variant version value : 0x%02X\n", getInfoExtRsp->variant_version_value);
    LOG_DBG("Model id tag: 0x%02X\n", getInfoExtRsp->model_id_tag);
    LOG_DBG("Model id length: 0x%02X\n", getInfoExtRsp->model_id_length);
    LOG_DBG("Model id value: 0x%02X\n", getInfoExtRsp->model_id_value);
    LOG_DBG("customer id tag: 0x%02X\n", getInfoExtRsp->customer_id_tag);
    LOG_DBG("customer id length: 0x%02X\n", getInfoExtRsp->customer_id_length);
    LOG_DBG("customer id value: 0x%02X\n", getInfoExtRsp->customer_id_value);
    LOG_DBG("=====================================================\n");
}

void print_getInfoRsp(phHDLLGetInfo_t *getInfoRsp)
{
    uint8_t i = 0, offset = 0;
    int charsWritten               = 0;
    char buff[HDLL_READ_BUFF_SIZE] = {0};
    if (NULL == getInfoRsp) {
        LOG_ERR("%s getInfoRsp is null", __FUNCTION__);
        return;
    }
    LOG_INF("=====================GET_INFO =======================");
    LOG_DBG("Boot Status: 0x%02X", getInfoRsp->boot_status);
    LOG_DBG("Session Control: 0x%02X", getInfoRsp->session_control);
    print_session_control_str(getInfoRsp->session_control);
    LOG_DBG("Session Type: 0x%02X", getInfoRsp->session_type);
    LOG_DBG("ROM Version: 0x%02X", getInfoRsp->rom_version);
    print_rom_version_str(getInfoRsp->rom_version);
    LOG_DBG("AT Page Status: 0x%02X", getInfoRsp->AT_page_status);
    print_at_page_status(getInfoRsp->AT_page_status);
    LOG_DBG("Chip Version: Major.Minor: %02X.%02X", getInfoRsp->chip_major_ver, getInfoRsp->chip_minor_ver);
    LOG_INF("FW Version: Major.Minor: %02X.%02X", getInfoRsp->fw_major_ver, getInfoRsp->fw_minor_ver);

    for (i = 0; i != 8; i += 2) { // 4bytes
        charsWritten = sprintf(&buff[i], "%02X", getInfoRsp->chip_variant[offset++]);
        if (charsWritten < 0) {
            LOG_ERR("sprintf failed while writing git hash value at offset=%u", offset - 1);
            return;
        }
    }
    buff[i] = '\0';
    LOG_DBG("Chip Variant: 0x%s", buff);

    uint32_t device_life_cycleu32 = 0;
    {
        uint8_t *p = getInfoRsp->device_life_cycle;
        FWDL_STREAM_TO_UINT32(device_life_cycleu32, p);
    }
    LOG_DBG("Device Lifecycle: 0x%08X", device_life_cycleu32);
    print_device_life_cycle_str(device_life_cycleu32);

    for (i = 0, offset = 0; i != 32; i += 2) { // 16bytes
        charsWritten = sprintf(&buff[i], "%02X", getInfoRsp->chip_id[offset++]);
        if (charsWritten < 0) {
            LOG_ERR("sprintf failed while writing git hash value at offset=%u", offset - 1);
            return;
        }
    }
    buff[i] = '\0';
    LOG_DBG("Chip ID: 0x%s", buff);

    for (i = 0, offset = 0; i != 8; i += 2) { // 4bytes
        charsWritten = sprintf(&buff[i], "%02X", getInfoRsp->chip_id_crc[offset++]);
        if (charsWritten < 0) {
            LOG_ERR("sprintf failed while writing git hash value at offset=%u", offset - 1);
            return;
        }
    }
    buff[i] = '\0';
    LOG_DBG("Chip ID CRC:0x%s", buff);
    LOG_DBG("=====================================================");
}

void process_getInfoExt_rsp(uint8_t *payload, phHDLLGetInfoExt_t *getExtInfoRsp)
{
    uint8_t offset = 0;

    memset(getExtInfoRsp, 0, sizeof(phHDLLGetInfoExt_t));
    getExtInfoRsp->fw_info_length = payload[offset++];
    offset++; // padding
    getExtInfoRsp->fw_rc_version_tag    = payload[offset++];
    getExtInfoRsp->fw_rc_version_length = payload[offset++];
    getExtInfoRsp->fw_rc_version_value  = payload[offset++];
    getExtInfoRsp->git_hash_tag         = payload[offset++];
    getExtInfoRsp->git_hash_length      = payload[offset++];
    memcpy(getExtInfoRsp->git_hash_value, payload + offset, sizeof(uint8_t) * 17);
    offset += 17;
    getExtInfoRsp->variant_version_tag    = payload[offset++];
    getExtInfoRsp->variant_version_length = payload[offset++];
    getExtInfoRsp->variant_version_value  = payload[offset++];
    getExtInfoRsp->model_id_tag           = payload[offset++];
    getExtInfoRsp->model_id_length        = payload[offset++];
    getExtInfoRsp->model_id_value         = payload[offset++];
    getExtInfoRsp->customer_id_tag        = payload[offset++];
    getExtInfoRsp->customer_id_length     = payload[offset++];
    getExtInfoRsp->customer_id_value      = payload[offset++];
}

void process_getInfo_rsp(uint8_t *payload, phHDLLGetInfo_t *getInfoRsp)
{
    uint8_t offset = 0;

    memset(getInfoRsp, 0, sizeof(phHDLLGetInfo_t));
    getInfoRsp->boot_status     = payload[offset++];
    getInfoRsp->session_control = payload[offset++];
    getInfoRsp->session_type    = payload[offset++];
    getInfoRsp->rom_version     = payload[offset++];
    getInfoRsp->AT_page_status  = payload[offset++];
    offset += 2; // padding bytes
    getInfoRsp->chip_major_ver = payload[offset++];
    getInfoRsp->chip_minor_ver = payload[offset++];
    getInfoRsp->fw_major_ver   = payload[offset++];
    getInfoRsp->fw_minor_ver   = payload[offset++];
    memcpy(getInfoRsp->chip_variant, payload + offset, sizeof(uint8_t) * 4);
    offset += 4;
    memcpy(getInfoRsp->device_life_cycle, payload + offset, sizeof(uint8_t) * 4);
    offset += 4;
    memcpy(getInfoRsp->chip_id, payload + offset, sizeof(uint8_t) * 16);
    offset += 16;
    memcpy(getInfoRsp->chip_id_crc, payload + offset, sizeof(uint8_t) * 4);
    if ((getInfoRsp->fw_major_ver < UWBD_FW_MAJOR_VER) ||
        (getInfoRsp->fw_major_ver == UWBD_FW_MAJOR_VER && getInfoRsp->fw_minor_ver < UWBD_FW_MINOR_VER)) {
        fwImageCtx.isLegacyFw = TRUE;
    }
}

/*******************************************************************************
**
** Function    :   uwb_fwdl_setFwImage
**
** Description :   This function sets the Firmware Download context with firmware image and the fimrware size.
**
** Parameters  :   pfwImageCtx     - Firmware Image Context
**
** Returns     :   phFWD_Status_t :  0 - success
                                     1 - failure
**
**
*******************************************************************************/
UWBStatus_t uwb_fwdl_setFwImage(const phUwbFWImageContext_t *const pAppfwImageCtx)
{
    uint32_t frame_payload_length = 0;
    uint32_t index                = 0;
    if (pAppfwImageCtx == NULL) {
        return kUWBSTATUS_FAILED;
    }
    if (pAppfwImageCtx->fwImgSize == 0 && fwImageCtx.fwImage == NULL) {
        if (TRUE == pAppfwImageCtx->forceFwUpdate) {
            LOG_ERR(
                "%s Cannot enable force firmware download without passing the firmware context", __FUNCTION__);
            return kUWBSTATUS_FAILED;
        }
        else {
            fwImageCtx.fwImageMajorVer = UWB_SR2XX_MAJOR_NUMBER;
            fwImageCtx.fwImageMinorVer = UWB_SR2XX_MINOR_NUMBER;
            fwImageCtx.fwImagePatchVer = UWB_SR2XX_PATCH_NUMBER;
            fwImageCtx.fwImgSize       = 0;
            fwImageCtx.fwImage         = NULL;
            fwImageCtx.forceFwDownload = pAppfwImageCtx->forceFwUpdate;
        }
    }
    else {
        /* Get Fw Context from file */
        fwImageCtx.fwImgSize       = pAppfwImageCtx->fwImgSize;
        fwImageCtx.fwImage         = (uint8_t *)pAppfwImageCtx->fwImage;
        fwImageCtx.fwImagePatchVer = pAppfwImageCtx->patchVerion;
        fwImageCtx.forceFwDownload = pAppfwImageCtx->forceFwUpdate;
        /* Get Fw Context from file */
        frame_payload_length = ((uint32_t)pAppfwImageCtx->fwImage[0] << 8) + (uint32_t)pAppfwImageCtx->fwImage[1];
        // get the index of first_write_cmd_payload
        index                      = frame_payload_length + HDLL_HEADER_LEN + HDLL_FOOTER_LEN;
        fwImageCtx.fwImageMajorVer = pAppfwImageCtx->fwImage[index + MW_MAJOR_FW_VER_OFFSET];
        fwImageCtx.fwImageMinorVer = pAppfwImageCtx->fwImage[index + MW_MINOR_FW_VER_OFFSET];
    }
    return kUWBSTATUS_SUCCESS;
}
/**
**
** Function    :   check_fw_update_required
**
** Description :   This function checks whether FW update is required or not
                   based on FW version from MW binary and FW version present in
                   the HeliosX chip.
**
** Parameters  :   getInfoRsp  - Struct which has the GetInfo response details.
**
** Returns     :   FW_DNLD_FAILURE - If any un expected failure
                   FW_DNLD_NOT_REQUIRED - FW update not required
                   FW_DNLD_REQUIRED - FW update required
                   FW_DNLD_FILE_NOT_FOUND - if the FW bin file is unable to
                                                open or not present
**
**
*/
static void check_fw_update_required(phUwbFWImageCtx_t *pfwImageCtx)
{
    pfwImageCtx->isSkipFwDnld = FALSE;

    print_getInfoRsp(pfwImageCtx->deviceInfo);
    print_getInfoExtRsp(pfwImageCtx->deviceExtInfo);
    LOG_INF("mw_fw_ver: %02X.%02X chip_fw_ver: %02X.%02X",
        pfwImageCtx->fwImageMajorVer,
        pfwImageCtx->fwImageMinorVer,
        pfwImageCtx->deviceInfo->fw_major_ver,
        pfwImageCtx->deviceInfo->fw_minor_ver);

    if (!fwImageCtx.isLegacyFw) {
        LOG_INF("mw_fw_patch_ver: %02X chip_fw_patch_ver: %02X",
            pfwImageCtx->fwImagePatchVer,
            pfwImageCtx->deviceExtInfo->fw_rc_version_value);
    }

    /* Update the FW if  Integrated FW MajorVer is greateer than chip FW Major version*/
    if (pfwImageCtx->fwImageMajorVer > pfwImageCtx->deviceInfo->fw_major_ver) {
        LOG_INF("FW Update required as MajorVersion is Mismatch");
        pfwImageCtx->isSkipFwDnld = FALSE;
    }
    /* Update the FW if Integrated FW major version is same but minor or patch version is defferent  */
    else if (pfwImageCtx->fwImageMajorVer == pfwImageCtx->deviceInfo->fw_major_ver) {
        if (pfwImageCtx->fwImageMinorVer != pfwImageCtx->deviceInfo->fw_minor_ver) {
            LOG_INF("FW Update required as Minor is Mismatch");
            pfwImageCtx->isSkipFwDnld = FALSE;
        }
        else {
            if ((pfwImageCtx->fwImagePatchVer != pfwImageCtx->deviceExtInfo->fw_rc_version_value) &&
                !pfwImageCtx->isLegacyFw) {
                LOG_INF("Patch version Mismatch FW Update required");
                pfwImageCtx->isSkipFwDnld = FALSE;
            }
            else {
                LOG_INF("FW Update not required");
                pfwImageCtx->isSkipFwDnld = TRUE;
            }
        }
    }
    /* Skip FW update if Major Minor and patch version is same */
    else {
        LOG_INF("FW Update not required");
        pfwImageCtx->isSkipFwDnld = TRUE;
    }
}

phFWD_Status_t handleGetInfoExtRsp(uint8_t *hdll_payload)
{
    if (fwImageCtx.deviceExtInfo == NULL) {
        fwImageCtx.deviceExtInfo = (phHDLLGetInfoExt_t *)k_malloc(sizeof(phHDLLGetInfoExt_t));
        if (NULL == fwImageCtx.deviceExtInfo) {
            return FW_DNLD_FAILURE;
        }
    }
    process_getInfoExt_rsp(hdll_payload, fwImageCtx.deviceExtInfo);
    if (NULL == fwImageCtx.deviceExtInfo) {
        return FW_DNLD_FAILURE;
    }
    return FW_DNLD_SUCCESS;
}

phFWD_Status_t handleGetInfoRsp(uint8_t *hdll_payload)
{
    if (fwImageCtx.deviceInfo == NULL) {
        fwImageCtx.deviceInfo = (phHDLLGetInfo_t *)k_malloc(sizeof(phHDLLGetInfo_t));
        if (NULL == fwImageCtx.deviceInfo) {
            return FW_DNLD_FAILURE;
        }
    }

    process_getInfo_rsp(hdll_payload, fwImageCtx.deviceInfo);
    if (NULL == fwImageCtx.deviceInfo) {
        return FW_DNLD_FAILURE;
    }
    return FW_DNLD_SUCCESS;
}

phFWD_Status_t process_hdll_response(uint8_t *hdll_rsp,
    uint16_t rsp_buf_len,
    eOperation_t operation,
    eAPPLICATION_STATUS_CODES_t status,
    eHCP_TYPE_t type)
{
    uint8_t hdll_msg_type         = 0;
    uint8_t hdll_rsp_status       = 0;
    uint16_t hdll_packet_len      = 0;
    uint16_t hdll_group_operation = 0;
    uint8_t *hdll_payload         = NULL;
    phFWD_Status_t ret            = FW_DNLD_FAILURE;
    uint8_t *actual_hdll_response = NULL;

    if (hdll_rsp == NULL) {
        LOG_ERR("%s HDLL response buffer is NULL", __FUNCTION__);
        return ret;
    }
    if (rsp_buf_len < HDLL_MIN_RSP_LEN) {
        LOG_ERR("%s Error! HDLL response buffer length is %d, expected min %d bytes",
            __FUNCTION__,
            rsp_buf_len,
            HDLL_MIN_RSP_LEN);
        return ret;
    }
    /**
     * * UCI Payload:
     *   - Macro: `#define ACTUAL_PACKET_START (UCI_CMD_INDEX + N)`
     *   - Description: Refers to the section of the buffer where the actual UCI (UWB Command Interface)
     *                : data will be stored, starting after the platform-specific and bidirectional
     * bytes.
     *   - For any Uwbs all Bidirectional and Platform specific handling done on the Transport layer.
     *   - And actual Payload for the Read start from the "ACTUAL_PACKET_START"
     *
     */
    actual_hdll_response = &hdll_rsp[ACTUAL_PACKET_START];
    // parse hdll frame
    hdll_packet_len =
        ((uint16_t)((uint16_t)actual_hdll_response[0] << 8)) | ((uint16_t)actual_hdll_response[HDLL_RSP_LEN_OFFSET]);
    hdll_packet_len &= HDLL_PKT_LEN_BITMASK;
    LOG_DBG("Received RSP packet len      :0x%04X", hdll_packet_len);
    if (hdll_packet_len == 0) {
        LOG_ERR("Error in hdll response.. hdll_packet_len = 0");
        return ret;
    }

    hdll_msg_type        = actual_hdll_response[HDLL_RSP_TYPE_OFFSET] >> HDLL_RSP_GROUP_LEN;
    hdll_group_operation = (((uint16_t)(actual_hdll_response[HDLL_RSP_GROUP_OFFSET] & HDLL_RSP_GROUP_BIT_MASK) << 8) |
                            (uint16_t)(actual_hdll_response[HDLL_RSP_OPERATION_OFFSET]));
    hdll_rsp_status      = actual_hdll_response[HDLL_RSP_STATUS_OFFSET];

    LOG_DBG("Received RSP msg type        :0x%02X", hdll_msg_type);
    LOG_DBG("Received RSP group operation :0x%04X", hdll_group_operation);
    LOG_DBG("Received RSP status          :0x%02X", hdll_rsp_status);

    if (rsp_buf_len > HDLL_RSP_PAYLOAD_OFFSET) {
        if (hdll_packet_len >= HDLL_CRC_LEN) {
            uint32_t payload_len = hdll_packet_len - HDLL_CRC_LEN;
            hdll_payload         = (uint8_t *)k_malloc(sizeof(uint8_t) * payload_len);
            if (NULL == hdll_payload) {
                LOG_ERR(
                    "%s: Failed to allocate memory for hdll_payload (size=%u)", __FUNCTION__, payload_len);
                return ret;
            }
            memcpy(hdll_payload, &actual_hdll_response[HDLL_RSP_PAYLOAD_OFFSET], payload_len);
        }
        else {
            LOG_ERR("Invalid HDLL packet length. hdll_packet_len=%u", hdll_packet_len);
            return ret;
        }
    }

    // validate the response
    if (status != hdll_rsp_status) {
        LOG_ERR(
            "Error! expected response status code is 0x%02X  but "
            "received 0x%02X",
            status,
            hdll_rsp_status);
        printStatusErrorType(hdll_rsp_status);
        ret = FW_DNLD_FAILURE;
    }
    else if (type != hdll_msg_type) {
        LOG_ERR("Error! expected HDLL type code is 0x%02X but received 0x%02X", type, hdll_msg_type);
        ret = FW_DNLD_FAILURE;
    }
    else if (operation != hdll_group_operation) {
        if (operation == OP_PROTOCOL_HDLL && hdll_group_operation == OP_PROTOCOL_EDL)
        {
            /* FW update was interrupted, hence device boots up in EDL mode */
            /* If Device boots up in EDL mode, then Skip EDL check and do FW download */
            fwImageCtx.skipEdlCheck    = TRUE;
            fwImageCtx.forceFwDownload = TRUE;
            ret                        = FW_DNLD_SUCCESS;
        }
        else {
            LOG_ERR(
                "Error! expected response operation code is 0x%04X but "
                "received 0x%04X ",
                operation,
                hdll_group_operation);
            ret = FW_DNLD_FAILURE;
        }
    }
    else {
        ret = FW_DNLD_SUCCESS;
    }

    if (ret == FW_DNLD_FAILURE) {
        goto exit;
    }

    // Handle the response according to the operation
    switch (hdll_group_operation) {
    case OP_EDL_DOWNLOAD_CERTIFICATE: {
        LOG_DBG("Received OP_EDL_DOWNLOAD_CERTIFICATE");
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST: {
        LOG_DBG("Received OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST");
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE: {
        LOG_DBG("Received OP_EDL_DOWNLOAD_FLASH_WRITE");
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE_LAST: {
        LOG_DBG("Received OP_EDL_DOWNLOAD_FLASH_WRITE_LAST");
    } break;
    case OP_GENERIC_GET_INFO: {
        LOG_DBG("Received OP_GENERIC_GET_INFO");
        if (hdll_payload != NULL) {
            ret = handleGetInfoRsp(hdll_payload);
        }
    } break;
    case OP_GENERIC_GET_INFO_EXT: {
        LOG_DBG("Received OP_GENERIC_GET_INFO");
        if (hdll_payload != NULL) {
            ret = handleGetInfoExtRsp(hdll_payload);
        }
    } break;
    default:
        break;
    }

exit:
    if (hdll_payload != NULL) {
        k_free(hdll_payload);
    }
    return ret;
}

phFWD_Status_t sendEdlDownloadCertificateCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf)
{
    uint16_t rsp_buf_len = 0x0;
    phFWD_Status_t ret   = FW_DNLD_SUCCESS;
    ret                  = phGenericSendAndRecv(payload, len, rsp_buf, &rsp_buf_len);
    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_ERR(
            "Error in sending/receiving OP_EDL_DOWNLOAD_CERTIFICATE "
            "cmd/response");
        return ret;
    }
    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_EDL_DOWNLOAD_CERTIFICATE, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);
    return ret;
}

phFWD_Status_t sendEdlFlashWriteFirstCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf)
{
    uint16_t rsp_buf_len = 0x0;
    phFWD_Status_t ret   = FW_DNLD_SUCCESS;
    ret                  = phGenericSendAndRecv(payload, len, rsp_buf, &rsp_buf_len);
    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_ERR(
            "Error in sending/receiving "
            "OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST cmd/response");
        return ret;
    }
    ret = process_hdll_response(
        rsp_buf, rsp_buf_len, OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);
    return ret;
}

phFWD_Status_t sendEdlFlashWriteCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf)
{
    uint16_t rsp_buf_len = 0x0;
    phFWD_Status_t ret   = FW_DNLD_SUCCESS;
    ret                  = phGenericSendAndRecv(payload, len, rsp_buf, &rsp_buf_len);
    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_ERR(
            "Error in sending/receiving OP_EDL_DOWNLOAD_FLASH_WRITE "
            "cmd/response");
        return ret;
    }
    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_EDL_DOWNLOAD_FLASH_WRITE, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);
    return ret;
}

phFWD_Status_t sendEdlPatchFlashWriteCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf)
{
    uint16_t rsp_buf_len = 0x0;
    phFWD_Status_t ret   = FW_DNLD_SUCCESS;
    ret                  = phGenericSendAndRecv(payload, len, rsp_buf, &rsp_buf_len);
    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_ERR(
            "Error in sending/receiving OP_EDL_PATCH_FLASH_WRITE "
            "cmd/response");
        return ret;
    }
    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_EDL_PATCH_FLASH_WRITE, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);
    return ret;
}

phFWD_Status_t sendEdlFlashWriteLastCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf)
{
    uint16_t rsp_buf_len = 0x0;
    phFWD_Status_t ret   = FW_DNLD_SUCCESS;
    ret                  = phGenericSendAndRecv(payload, len, rsp_buf, &rsp_buf_len);
    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_ERR(
            "Error in sending/receiving "
            "OP_EDL_DOWNLOAD_FLASH_WRITE_LAST cmd/response");
        return ret;
    }
    ret = process_hdll_response(
        rsp_buf, rsp_buf_len, OP_EDL_DOWNLOAD_FLASH_WRITE_LAST, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);
    return ret;
}

/**
**
** Function    :   phHal_Host_CalcCrc16
**
** Description :   This function calculates the HDLL command's CRC
**
** Parameters  :   p  - HDLL command buffer
                   dwLength - command buffer length
**
** Returns     :   the calculated CRC value
**
**
*/
static uint16_t phHal_Host_CalcCrc16(uint8_t *p, uint32_t dwLength)
{
    uint32_t i;
    uint16_t crc_new;
    uint16_t crc = 0xffffU;

    for (i = 0; i < dwLength; i++) {
        crc_new = (uint8_t)(crc >> 8) | ((crc & 0xFF) << 8);
        crc_new ^= p[i];
        crc_new ^= (uint8_t)(crc_new & 0xff) >> 4;
        crc_new ^= crc_new << 12;
        crc_new ^= (crc_new & 0xff) << 5;
        crc = crc_new;
    }
    return crc;
}

uint8_t *phbuild_hdll_payload(
    eHCP_TYPE_t msg_type, eOperation_t operation, uint8_t *payload, uint16_t payload_len, uint16_t *hcp_data_len)
{
    uint8_t *hdll_payload = NULL;
    uint16_t hcp_header   = 0x0;
    int hdll_payload_len  = HCP_MSG_HEADER_LEN + payload_len;
    uint16_t type         = (uint16_t)msg_type;

    // Validate range before any memory allocation
    if ((hdll_payload_len < 0) || (hdll_payload_len > UINT16_MAX)) {
        LOG_ERR("%s: Invalid payload length: %d", __FUNCTION__, hdll_payload_len);
        return NULL;
    }

    // build hcp frame
    hdll_payload = (uint8_t *)k_malloc(sizeof(uint8_t) * hdll_payload_len);
    if (NULL == hdll_payload) {
        return hdll_payload;
    }
    type <<= HCP_GROUP_OPERATION_LEN;
    hcp_header = type | operation;

    // hcp_header uint16 to uint8
    hdll_payload[0] = (hcp_header >> 8);
    hdll_payload[1] = (hcp_header & 0xFF);

    if (payload_len > 0) {
        // copy payload to hdll payload
        memcpy(&hdll_payload[2], payload, payload_len);
    }
    *hcp_data_len = (uint16_t)hdll_payload_len;
    return hdll_payload;
}

uint8_t *phbuild_hdll_frame(
    uint8_t *hdll_payload, uint16_t hdll_payload_len, uint32_t hdll_frame_size, uint8_t chunk_size)
{
    uint8_t *hdll_frame     = NULL;
    uint8_t *pHdllFrameData = NULL;
    uint32_t hdll_header    = 0x0;
    uint16_t hdll_crc       = 0x0;

    // build hdll frame
    hdll_header |= hdll_payload_len;
    hdll_header &= HDLL_PKT_LEN_BITMASK;
    hdll_header = chunk_size ? (HDLL_PKT_CHUNK_BITMASK | hdll_header) : hdll_header;

    hdll_frame = (uint8_t *)k_malloc(sizeof(uint8_t) * hdll_frame_size + UCI_CMD_INDEX);
    if (NULL == hdll_frame) {
        LOG_ERR(" %s Error in Creating hdll_frame Memory", __FUNCTION__);
        return hdll_frame;
    }
    pHdllFrameData = &hdll_frame[UCI_CMD_INDEX];
    // hdll_header uint16 to uint8
    pHdllFrameData[0] = (hdll_header >> 8);
    pHdllFrameData[1] = (hdll_header & 0xFF);

    if (hdll_payload_len > 0) {
        // copy hdll payload into hdll frame
        memcpy(&pHdllFrameData[2], hdll_payload, hdll_payload_len);
    }
    hdll_crc                            = phHal_Host_CalcCrc16(pHdllFrameData, hdll_frame_size - 2);
    pHdllFrameData[hdll_frame_size - 2] = (hdll_crc >> 8);
    pHdllFrameData[hdll_frame_size - 1] = (hdll_crc & 0xFF);
    return hdll_frame;
}

uint8_t *phBuildHdllCmd(
    eOperation_t operation, uint8_t *payload, uint16_t payload_len, uint8_t chunk_size, uint32_t *frame_size)
{
    uint8_t *hdll_payload     = NULL;
    uint8_t *hdll_frame       = NULL;
    uint16_t hdll_payload_len = 0x0;
    uint32_t hdll_frame_size  = 0x0;

    LOG_DBG("phBuildHdllCmd:");
    hdll_payload = phbuild_hdll_payload(HCP_TYPE_COMMAND, operation, payload, payload_len, &hdll_payload_len);
    if (NULL == hdll_payload) {
        return hdll_payload;
    }

    // header len =2 bytes + hdll_payload_len + crc =2 bytes
    hdll_frame_size = HDLL_HEADER_LEN + hdll_payload_len + HDLL_CRC_LEN;

    hdll_frame  = phbuild_hdll_frame(hdll_payload, hdll_payload_len, hdll_frame_size, chunk_size);
    *frame_size = hdll_frame_size;
    if (hdll_payload != NULL) {
        k_free(hdll_payload);
    }
    return hdll_frame;
}

phFWD_Status_t phGetEdlReadyNtf(void)
{
    uint8_t rsp_buf[HDLL_READ_BUFF_SIZE] = {0};
    phFWD_Status_t ret                   = FW_DNLD_FAILURE;
    uint16_t rsp_buf_len                 = 0x0;

    LOG_DBG("Wait for EDL_READY notification");
    ret = phHdll_GetApdu((uint8_t *)&rsp_buf[0], HDLL_READ_BUFF_SIZE, &rsp_buf_len);

    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_DBG("Error in sending/receiving GET_EDL_READY cmd/response");
        return ret;
    }

    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_PROTOCOL_EDL, READY, HCP_TYPE_NOTIFICATION);
    ret = FW_DNLD_SUCCESS;
    return ret;
}

phFWD_Status_t phGenericGetInfoExt(void)
{
    uint8_t rsp_buf[HDLL_READ_BUFF_SIZE] = {0};
    uint8_t *hdll_frame                  = NULL;
    phFWD_Status_t ret                   = FW_DNLD_FAILURE;
    uint32_t hdll_frame_size             = 0x0;
    uint16_t rsp_buf_len                 = 0x0;
    hdll_frame                           = phBuildHdllCmd(OP_GENERIC_GET_INFO_EXT, NULL, 0, 0, &hdll_frame_size);
    if (NULL == hdll_frame) {
        return ret;
    }
    LOG_DBG("Sending operation: OP_GENERIC_GET_INFO_EXT");
    ret = phGenericSendAndRecv(hdll_frame, hdll_frame_size, rsp_buf, &rsp_buf_len);
    if (0 == rsp_buf_len) {
        ret = FW_DNLD_FAILURE;
    }
    if (ret == FW_DNLD_FAILURE) {
        LOG_ERR("Error in sending/receiving hdll cmd/response");
        if (NULL != hdll_frame) {
            k_free(hdll_frame);
        }
        return ret;
    }
    LOG_HEXDUMP_DBG(rsp_buf, rsp_buf_len, "RECV");
    if (NULL != hdll_frame) {
        k_free(hdll_frame);
    }
    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_GENERIC_GET_INFO_EXT, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);

    return ret;
}

phFWD_Status_t phGenericGetInfo()
{
    uint8_t rsp_buf[HDLL_READ_BUFF_SIZE] = {0};
    uint8_t *hdll_frame                  = NULL;
    phFWD_Status_t ret                   = FW_DNLD_FAILURE;
    uint32_t hdll_frame_size             = 0x0;
    uint16_t rsp_buf_len                 = 0x0;

    hdll_frame = phBuildHdllCmd(OP_GENERIC_GET_INFO, NULL, 0, 0, &hdll_frame_size);
    if (NULL == hdll_frame) {
        return ret;
    }
    LOG_DBG("Sending operation: OP_GENERIC_GET_INFO");
    ret = phGenericSendAndRecv(hdll_frame, hdll_frame_size, rsp_buf, &rsp_buf_len);
    if (0 == rsp_buf_len) {
        ret = FW_DNLD_FAILURE;
    }
    if (ret == FW_DNLD_FAILURE) {
        LOG_ERR("Error in sending/receiving hdll cmd/response");
        if (NULL != hdll_frame) {
            k_free(hdll_frame);
        }
        return ret;
    }
    LOG_HEXDUMP_DBG(rsp_buf, rsp_buf_len, "RECV");
    if (NULL != hdll_frame) {
        k_free(hdll_frame);
    }

    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_GENERIC_GET_INFO, GENERIC_SUCCESS, HCP_TYPE_RESPONSE);

    return ret;
}

phFWD_Status_t phHdll_GetHdllReadyNtf()
{
    uint8_t rsp_buf[HDLL_READ_BUFF_SIZE] = {0};
    phFWD_Status_t ret                   = FW_DNLD_FAILURE;
    uint16_t rsp_buf_len                 = 0x0;

    LOG_DBG("Wait for HDL_READY notification");
    ret = phHdll_GetApdu((uint8_t *)&rsp_buf[0], HDLL_READ_BUFF_SIZE, &rsp_buf_len);

    if (!rsp_buf_len || ret == FW_DNLD_FAILURE) {
        LOG_DBG("Error in reading GET_HDL_READY notification");
        return ret;
    }

    ret = process_hdll_response(rsp_buf, rsp_buf_len, OP_PROTOCOL_HDLL, READY, HCP_TYPE_NOTIFICATION);
    return ret;
}

phFWD_Status_t phHdll_send_and_recv(uint8_t *hdll_data, uint32_t hdll_data_len, eOperation_t operation)
{
    phFWD_Status_t ret                    = FW_DNLD_SUCCESS;
    uint8_t rsp_buff[HDLL_READ_BUFF_SIZE] = {0};

    /* Validate HDLL data length fits in uint16_t for all operations */
    if (hdll_data_len > UINT16_MAX) {
        LOG_ERR("%s: HDLL data length %u exceeds maximum %u", __FUNCTION__, hdll_data_len, UINT16_MAX);
        return FW_DNLD_FAILURE;
    }

    switch (operation) {
    case OP_EDL_DOWNLOAD_CERTIFICATE: {
        ret = sendEdlDownloadCertificateCmd(hdll_data, (uint16_t)hdll_data_len, rsp_buff);
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST: {
        ret = sendEdlFlashWriteFirstCmd(hdll_data, (uint16_t)hdll_data_len, rsp_buff);
    } break;
    case OP_EDL_PATCH_FLASH_WRITE: {
        ret = sendEdlPatchFlashWriteCmd(hdll_data, (uint16_t)hdll_data_len, rsp_buff);
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE: {
        ret = sendEdlFlashWriteCmd(hdll_data, (uint16_t)hdll_data_len, rsp_buff);
    } break;
    case OP_EDL_DOWNLOAD_FLASH_WRITE_LAST: {
        ret = sendEdlFlashWriteLastCmd(hdll_data, (uint16_t)hdll_data_len, rsp_buff);
    } break;
    case OP_GENERIC_GET_INFO:
        break;
    default:
        break;
    }
    return ret;
}

#if UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
/**
**
** Function    :   sendHDLLResetCmd
**
** Description :   This function sends the reset command to Helios
**                 After reset, the Helios goes in UCI Mode.
**                 Command is used when firmware download not required.
**
** Parameters  :   None
**
** Returns     :   None
**
*/
static void sendHDLLResetCmd(bool isFWDownloadDone)
{
    phTmlUwb_hdll_reset(isFWDownloadDone);
}

#endif

/**
**
** Function    :   phLoadFwBinary
**
** Description :   This function reads the MW FW binary file and writes to
                   HeliosX chip.
**
** Parameters  :   None
**
** Returns     :   FW_DNLD_FAILURE - on failure
                   FW_DNLD_SUCCESS - On success
                   FW_DNLD_FILE_NOT_FOUND - if the FW bin file is unable to
                             open or not present

**
**
*/
static phFWD_Status_t phLoadFwBinary(phUwbFWImageCtx_t *pfwImageCtx)
{
    if (pfwImageCtx == NULL || pfwImageCtx->fwImage == NULL || pfwImageCtx->fwImgSize == 0) {
        LOG_ERR(" %s pfwImageCtx is NULL", __FUNCTION__);
        return FW_DNLD_FILE_NOT_FOUND;
    }
    size_t next_frame_first_byte_index = 0;
    eOperation_t current_op;
    uint32_t frame_payload_length = 0;
    uint32_t frame_length         = 0;
    phFWD_Status_t status         = FW_DNLD_FAILURE;
    uint8_t *actual_buffer        = (uint8_t *)k_malloc(MAX_FRAME_LEN + UCI_CMD_INDEX);
    if (actual_buffer == NULL) {
        LOG_ERR(" %s Dynamic Memory allocation is failed in the phLoadFwBinary", __FUNCTION__);
        goto exit;
    }
    while (1) {
        // compute next frame payload length
        // TODO: warning this is not HDLL fragmentation compatible (valid header can
        // have chunk flag (biy 10 (13)) set) Assuming header length is 2 bytes
        frame_payload_length = ((uint32_t)pfwImageCtx->fwImage[next_frame_first_byte_index] << 8) +
                               ((uint32_t)pfwImageCtx->fwImage[next_frame_first_byte_index + 1]);

        // if max_payload_length is not None and (frame_payload_length >=
        // max_payload_length): raise Exception('Invalid SFWU content (not an HDLL
        // header).')

        // copy the header, the payload and the footer (crc) from the file bytes
        // into a byte array
        frame_length = frame_payload_length + HDLL_HEADER_LEN + HDLL_FOOTER_LEN;
        if (frame_length > MAX_FRAME_LEN) {
            LOG_ERR(
                "%s: Error while performing FW download frame_length > "
                "MAX_FRAME_LEN",
                __FUNCTION__);
            status = FW_DNLD_FAILURE;
            break;
        }
        current_op = (eOperation_t)((pfwImageCtx->fwImage[next_frame_first_byte_index + 2] << 8) |
                                    (pfwImageCtx->fwImage[next_frame_first_byte_index + 3]));
        memcpy(
            &actual_buffer[UCI_CMD_INDEX], &pfwImageCtx->fwImage[next_frame_first_byte_index], frame_length);
        status = phHdll_send_and_recv(actual_buffer, frame_length, current_op);
        if (status != FW_DNLD_SUCCESS) {
            LOG_ERR("%s: Error while performing FW download", __FUNCTION__);
            break;
        }

        // update byte index
        next_frame_first_byte_index = next_frame_first_byte_index + frame_length;

        // check end of file
        if (next_frame_first_byte_index >= pfwImageCtx->fwImgSize) {
            break;
        }
    }
exit:
    // Null check handling inside the osal api.
    k_free(actual_buffer);
    pfwImageCtx->fwImage = NULL;

    return status;
}

static phFWD_Status_t phGetUwbDeviceInfo(void)
{
    phFWD_Status_t ret = FW_DNLD_FAILURE;

    ret = phGenericGetInfoExt();
    if (ret != FW_DNLD_SUCCESS) {
        LOG_WRN("%s: error in getting phGenericGetInfoExt()...", __FUNCTION__);
        return ret;
    }

    // do chip reset
#if UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
    sendHDLLResetCmd(false);
    k_msleep(20);
#endif
    phTmlUwb_Chip_Reset();
    ret = phHdll_GetHdllReadyNtf();
    if (ret != FW_DNLD_SUCCESS) {
        LOG_WRN("%s: error in getting phHdll_GetHdllReadyNtf()...", __FUNCTION__);
        return ret;
    }
    ret = phGenericGetInfo();
    if (ret != FW_DNLD_SUCCESS) {
        LOG_WRN("%s: error in getting phGenericGetInfo()...", __FUNCTION__);
        return ret;
    }
    ret = phGetEdlReadyNtf();
    if (ret != FW_DNLD_SUCCESS) {
        LOG_WRN("%s: error in getting the phGetEdlReadyNtf()...", __FUNCTION__);
        return ret;
    }
    return ret;
}

/*   GLOBAL FUNCTIONS   */

phFWD_Status_t phHdll_GetApdu(uint8_t *pApdu, uint16_t sz, uint16_t *rsp_buf_len)
{
    if (sz == 0 || sz > PHHDLL_MAX_LEN_PAYLOAD_MISO) {
        LOG_ERR(
            "ERROR: phHdll_GetApdu data len is 0 or greater than max "
            "palyload length supported");
        return FW_DNLD_FAILURE;
    }
    if (phTmlUwb_hdll_read(pApdu, rsp_buf_len) == kUWBSTATUS_SUCCESS) {
        LOG_HEXDUMP_INF(&pApdu[ACTUAL_PACKET_START], *rsp_buf_len, "RECV");
        return FW_DNLD_SUCCESS;
    }

    LOG_ERR("ERROR: Get APDU %u bytes failed!", sz);
    return FW_DNLD_FAILURE;
}

int phNxpUciHal_fw_download(void)
{
    phFWD_Status_t ret       = FW_DNLD_FAILURE;
    fwImageCtx.isLegacyFw    = FALSE;
    fwImageCtx.deviceInfo    = NULL;
    fwImageCtx.deviceExtInfo = NULL;
    fwImageCtx.fwRecovery    = FALSE;
    fwImageCtx.skipEdlCheck  = FALSE;

    LOG_INF("phNxpUciHal_fw_download enter.....");
    phTmlUwb_Chip_Reset();
    if (uwb_uwbs_tml_setmode(&gUwbsTmlCtx, kUWB_UWBS_TML_MODE_HDLL) != kUWBSTATUS_SUCCESS) {
        LOG_ERR("phTmlUwb_set_mode_uci : uwb_uwbs_tml_setmode failed");
    }

    ret = phHdll_GetHdllReadyNtf();
    if (ret != FW_DNLD_SUCCESS) {
        LOG_WRN("%s: error in getting the hdll ready notification...", __FUNCTION__);
        goto cleanup;
    }

    if (!fwImageCtx.skipEdlCheck) {
        ret = phGenericGetInfo();
        if (ret == FW_DNLD_FAILURE) {
            LOG_ERR("%s: error in getting the getInfo response...\n", __FUNCTION__);
            goto cleanup;
        }

        ret = phGetEdlReadyNtf();
        if (ret != FW_DNLD_SUCCESS) {
            LOG_ERR("%s: error in getting the EDL ready notification...", __FUNCTION__);
            goto cleanup;
        }

        if (!fwImageCtx.isLegacyFw) {
            /* Get the device ext information */
            ret = phGetUwbDeviceInfo();
            if (ret != FW_DNLD_SUCCESS) {
                LOG_ERR("%s: error in phGetUwbDeviceInfo()", __FUNCTION__);
                goto cleanup;
            }
        }
    }

    if (!fwImageCtx.forceFwDownload) {
        if (!fwImageCtx.skipEdlCheck) {
            check_fw_update_required(&fwImageCtx);
            if (fwImageCtx.isSkipFwDnld) {
                LOG_INF("Same FW version found skipping FW download");
            }
            else {
                if (fwImageCtx.fwImage != NULL && fwImageCtx.fwImgSize != 0) {
                    ret = phLoadFwBinary(&fwImageCtx);
                    LOG_INF("phLoadFwBinary() status - %0x", ret);
                    if (ret != FW_DNLD_SUCCESS) {
                        LOG_ERR("%s: error in phLoadFwBinary...", __FUNCTION__);
                        goto cleanup;
                    }
                }
                else {
                    LOG_ERR("%s: fwImageCtx.fwImage or fwImageCtx.fwImgSize is NULL ...", __FUNCTION__);
                    return FW_DNLD_FAILURE;
                }
            }
        }
    }
    else {
        if (fwImageCtx.fwImage != NULL && fwImageCtx.fwImgSize != 0) {
            LOG_WRN("Force FW update");
            ret = phLoadFwBinary(&fwImageCtx);
            LOG_INF("phLoadFwBinary() status - %0x", ret);
            if (ret != FW_DNLD_SUCCESS) {
                LOG_ERR("%s: error in phLoadFwBinary...", __FUNCTION__);
                goto cleanup;
            }
        }
        else {
            LOG_ERR("%s: fwImageCtx.fwImage or fwImageCtx.fwImgSize is NULL ...", __FUNCTION__);
            return FW_DNLD_FAILURE;
        }
    }

    // do chip reset
#if UWBIOT_TML_PNP || UWBIOT_TML_SOCKET
    sendHDLLResetCmd(true);
    k_msleep(20);
#endif
    phTmlUwb_Chip_Reset();
    ret = phHdll_GetHdllReadyNtf();

    if (ret == FW_DNLD_SUCCESS) {
        // goto UCI Mode.
        phTmlUwb_set_mode_uci();
    }
    k_msleep(100);
cleanup:
    if (NULL != fwImageCtx.deviceExtInfo) {
        k_free(fwImageCtx.deviceExtInfo);
    }
    if (NULL != fwImageCtx.deviceInfo) {
        k_free(fwImageCtx.deviceInfo);
    }

    return ret;
}
