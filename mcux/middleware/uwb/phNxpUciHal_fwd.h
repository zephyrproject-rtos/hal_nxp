/*
 *
 * Copyright 2021-2024 NXP.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _PHNXPUCIHAL_FW_H
#define _PHNXPUCIHAL_FW_H
#include <stdint.h>
#include <stdbool.h>

#define PHHDLL_LEN_LRC              (1U)
#define PHHDLL_MAX_MISO_DATA_LEN    (256U)
#define PHHDLL_MAX_LEN_PAYLOAD_MISO (PHHDLL_MAX_MISO_DATA_LEN + PHHDLL_LEN_LRC)

#define FILEPATH_MAXLEN 500

#define HCP_MSG_HEADER_LEN        2
#define HDLL_HEADER_LEN           2
#define HDLL_FOOTER_LEN           2
#define HDLL_CRC_LEN              2
#define HDLL_PKT_CHUNK_BITMASK    0x2000
#define HDLL_PKT_LEN_BITMASK      0x1FFF
#define HCP_GROUP_LEN             6                                   // bits
#define HCP_OPERATION_LEN         8                                   // bits
#define HCP_GROUP_OPERATION_LEN   (HCP_GROUP_LEN + HCP_OPERATION_LEN) // 14bits
#define HCP_GROUP_BIT_MASK        0x3F00
#define HDLL_MIN_RSP_LEN          8
#define HDLL_RSP_LEN_OFFSET       1 // starting from 0.
#define HDLL_RSP_TYPE_OFFSET      2
#define HDLL_RSP_GROUP_OFFSET     2
#define HDLL_RSP_GROUP_LEN        6
#define HDLL_RSP_GROUP_BIT_MASK   0x03
#define HDLL_RSP_OPERATION_OFFSET 3
#define HDLL_RSP_STATUS_OFFSET    4
#define HDLL_RSP_PAYLOAD_OFFSET   5
#define MW_MAJOR_FW_VER_OFFSET    4
#define MW_MINOR_FW_VER_OFFSET    5

#define HDLL_READ_BUFF_SIZE 64

#define UWBD_FW_MAJOR_VER 0x01
#define UWBD_FW_MINOR_VER 0x27

/* Struct to store the getinfo response */
typedef struct phHDLLGetInfo
{
    uint8_t boot_status;
    uint8_t session_control;
    uint8_t session_type;
    uint8_t rom_version;
    uint8_t AT_page_status;
    uint8_t chip_major_ver;
    uint8_t chip_minor_ver;
    uint8_t fw_minor_ver;
    uint8_t fw_major_ver;
    uint8_t chip_variant[4];
    uint8_t device_life_cycle[4];
    uint8_t chip_id[16];
    uint8_t chip_id_crc[4];
} phHDLLGetInfo_t;

/* Struct to store the getinfo response */
typedef struct phHDLLGetInfoExt
{
    uint8_t fw_info_length;
    uint8_t fw_rc_version_tag;
    uint8_t fw_rc_version_length;
    uint8_t fw_rc_version_value;
    uint8_t git_hash_tag;
    uint8_t git_hash_length;
    uint8_t git_hash_value[17];
    uint8_t variant_version_tag;
    uint8_t variant_version_length;
    uint8_t variant_version_value;
    uint8_t model_id_tag;
    uint8_t model_id_length;
    uint8_t model_id_value;
    uint8_t customer_id_tag;
    uint8_t customer_id_length;
    uint8_t customer_id_value;
} phHDLLGetInfoExt_t;

/* HCP type */
typedef enum
{
    HCP_TYPE_COMMAND = 0x00,
    HCP_TYPE_RESPONSE,
    HCP_TYPE_NOTIFICATION
} eHCP_TYPE_t;

/* <1 byte>     <1 byte>  */
/* <Group ID>  <Operation> */
typedef enum Operation
{
    OP_PROTOCOL_HDLL                  = 0x0101,
    OP_PROTOCOL_HCP                   = 0x0102,
    OP_PROTOCOL_EDL                   = 0x0103,
    OP_GENERIC_GET_INFO_EXT           = 0x0201,
    OP_GENERIC_GET_INFO               = 0x0202,
    OP_EDL_DOWNLOAD_CERTIFICATE       = 0x0301,
    OP_EDL_DOWNLOAD_FLASH_WRITE_FIRST = 0x0302,
    OP_EDL_DOWNLOAD_FLASH_WRITE       = 0x0303,
    OP_EDL_DOWNLOAD_FLASH_WRITE_LAST  = 0x0304,
    OP_EDL_PATCH_FLASH_WRITE          = 0x0323,
} eOperation_t;

/* Application status codes */
typedef enum
{
    /* Success */
    GENERIC_SUCCESS = 0x00,
    ACKNOWLEDGE     = 0x01,
    READY           = 0x02,

    /* Generic errors */
    GENERIC_ERROR = 0x80,
    MEMORY_ERROR  = 0x81,
    TIMEOUT_ERROR = 0x82,
    CRC_ERROR     = 0x83,
    INVALID_ERROR = 0x84,

    /* Verification errors */
    INVALID_LENGTH_ERROR      = 0x90,
    INVALID_ADDRESS_ERROR     = 0x91,
    ECC_SIGNATURE_ERROR       = 0x92,
    SHA384_HASH_ERROR         = 0x93,
    LIFECYCLE_VALIDITY_ERROR  = 0x94,
    CHIP_ID_ERROR             = 0x95,
    CHIP_VERSION_ERROR        = 0x96,
    CERTIFICATE_VERSION_ERROR = 0x97,
    FIRMWARE_VERSION_ERROR    = 0x98,
    SRAM_DOWNLOAD_ALLOW_ERROR = 0x99,

    /* Encryption errors */
    KEY_DERIVATION_ERROR               = 0xA0,
    ENCRYPTED_PAYLOAD_DECRYPTION_ERROR = 0xA1,
    INVALID_ENCRYPTED_PAYLOAD_ERROR    = 0xA2,

    /* N-1 & N-2 errors */
    PROTECTED_CACHE_LOAD_ERROR   = 0xB0,
    PROTECTED_CACHE_DEPLOY_ERROR = 0xB1,
    LIFECYCLE_UPDATE_ERROR       = 0xB2,

    /* Flash errors */
    FLASH_BLANK_PAGE_ERROR   = 0xC0,
    FLASH_CHECK_MARGIN_ERROR = 0xC1
} eAPPLICATION_STATUS_CODES_t;

typedef enum phFWD_Status
{
    FW_DNLD_SUCCESS        = 0x00,
    FW_DNLD_FAILURE        = 0x01,
    FW_DNLD_REQUIRED       = 0x02,
    FW_DNLD_NOT_REQUIRED   = 0x03,
    FW_DNLD_FILE_NOT_FOUND = 0x14,
    FW_DNLD_EDL_MODE       = 0x05,
} phFWD_Status_t;

typedef struct phUwbFWImageCtx
{
    /* pointer to the FW image to be used */
    uint8_t *fwImage;
    /* size of fw image */
    uint32_t fwImgSize;
    /* Neccesity of downloading FW */
    bool isSkipFwDnld;
    /* Legacy FW */
    bool isLegacyFw;
    /* FW Image  Major version */
    uint8_t fwImageMajorVer;
    /* FW Image  Minor version */
    uint8_t fwImageMinorVer;
    /* FW Image  Patch version */
    uint8_t fwImagePatchVer;
    /* FW recovery */
    bool fwRecovery;
    /* FW recovery */
    bool forceFwDownload;
    /* Skiping EDL check */
    bool skipEdlCheck;
    /* Device Info */
    phHDLLGetInfo_t *deviceInfo;
    /* Extended Device Info */
    phHDLLGetInfoExt_t *deviceExtInfo;
} phUwbFWImageCtx_t;

typedef struct phPalSr200_Config
{
    void *pDevHandle;
} phPalSr200_Config_t;

extern phPalSr200_Config_t tPalConfig;

/**
 * Function         phNxpUciHal_fw_download
 *
 * Description
 *
 * Returns          FW_DNLD_SUCCESS - on success
                    FW_DNLD_FAILURE - on failure
                    FW_DNLD_FILE_NOT_FOUND - if the FW binary is not found or
                                             unable to open
 *
 */
int phNxpUciHal_fw_download(void);

/**
**
** Function    :   phbuild_hdll_payload
**
** Description :   This function frames the HDLL payload buffer based on the
                   HCP message type, operation and payload.
**
** Parameters  :   msg_type  - HCP message type
                   operation - Which has operation group and code information
                   payload - payload buffer
                   payload_len - payload len
                   hcp_data_len - hcp_data_len to be filled and sent to the
                                  callee function.
**
** Returns     :   NULL - on failure
                   HDLL payload buffer - On success
**
**
*/
uint8_t *phbuild_hdll_payload(
    eHCP_TYPE_t msg_type, eOperation_t operation, uint8_t *payload, uint16_t payload_len, uint16_t *hcp_data_len);

/**
**
** Function    :   phbuild_hdll_frame
**
** Description :   This function frames the HDLL command (HDLL header + HDLL
                   payload + CRC)
**
** Parameters  :   hdll_payload - HDLL payload buffer
                   hdll_payload_len - HDLL payload len
                   hdll_frame_size - HDLL frame size
                   chunk_size - chunk size
**
** Returns     :   NULL - on failure
                   HDLL command buffer - On success
**
**
*/
uint8_t *phbuild_hdll_frame(
    uint8_t *hdll_payload, uint16_t hdll_payload_len, uint32_t hdll_frame_size, uint8_t chunk_size);

/**
**
** Function    :   phBuildHdllCmd
**
** Description :   This function frames the final HDLL command (HDLL header +
                   HDLL payload + CRC) by framing HDLL payload and HDLL frame
                   using 2 different APIs.
**
** Parameters  :   operation - Which has operation group and code information
                   payload - payload buffer
                   payload_len - payload len
                   chunk_size - chunk size
                   frame_size - HDLL frame size to filled and sent to the callee
**
** Returns     :   NULL - on failure
                   HDLL command buffer - On success
**
**
*/
/*
 * HDLL Command:
 * <--------HDLL Header---->|<------------------HDLL payload------------------->
 * <--------HDLL (2bytes)-->|<-----HCP (2bytes)------->|<-Application-><--CRC-->
 * <31 30> <29>    <28 -16> |<15 -14><13 - 8><7 - 0>   |<---Payload---><2 bytes>
 * <--R--> <Chunk> <length> |< Type ><Group><Operation>|
 *
 */

uint8_t *phBuildHdllCmd(
    eOperation_t operation, uint8_t *payload, uint16_t payload_len, uint8_t chunk_size, uint32_t *frame_size);

/**
**
** Function    :   phHdll_GetApdu
**
** Description :   This function reads the HDLL command's response from HeliosX
                   chip over SPI.
**
** Parameters  :   pApdu     - HDLL response buffer
                   sz        - Max buffer size to be read
                   rsp_buf_len - HDLL response buffer length
**
** Returns     :   phFWD_Status_t : 0 - success
                                     1 - failure
**
**
*/
phFWD_Status_t phHdll_GetApdu(uint8_t *pApdu, uint16_t sz, uint16_t *rsp_buf_len);

/**
**
** Function    :   phHdll_GetHdllReadyNtf
**
** Description :   This function frames the GetHdllReadyNtf command and sends to
                   the HeliosX chip
**
** Parameters  :   None
**
** Returns     :   FW_DNLD_FAILURE - If any failure occurs while framing or
                                    sending the command or while receiving the
                                    response
                   FW_DNLD_SUCCESS - On success
**
**
*/
phFWD_Status_t phHdll_GetHdllReadyNtf(void);

/**
**
** Function    :   process_hdll_response
**
** Description :   This function processes the HDLL response

** Parameters  :   hdll_rsp  - HDLL response buffer
                   rsp_buf_len - response buffer length
                   operation - Operation code that is expected in the response
                   status - Application status code that is expected in the
                            response
                   type - HCP message type that is expected in the response
**
** Returns     :   FW_DNLD_FAILURE - If any undesired response received
                   FW_DNLD_SUCCESS - On proper response
**
**
*/
/*
 * HDLL Response:
 * <-------HDLL Header--->|<------------------HDLL payload--------------------->
 * <-------HDLL (2bytes)->|<-----HCP (2bytes)------->|<-Application--> <--CRC-->
 * <31 30> <29>  <28 -16> |<15 -14><13 - 8> <7 - 0>  |<status><Payload><2 bytes>
 * <--R--><Chunk><length> |< Type ><Group><Operation>|<1 byte>
 *
 */
phFWD_Status_t process_hdll_response(uint8_t *hdll_rsp,
    uint16_t rsp_buf_len,
    eOperation_t operation,
    eAPPLICATION_STATUS_CODES_t status,
    eHCP_TYPE_t type);

/**
**
** Function    :   phGenericSendAndRecv
**
** Description :   This function sends the HDLL commands to HeliosX chip over
                   SPI and gets the response using phTmlUwb_hdll_transceive().
**
** Parameters  :   payload     - HDLL command to be sent
                   len         - HDLL command length
                   readbuff    - HDLL command response buffer
                   rsp_buf_len - HDLL command response buffer length
**
** Returns     :   phFWD_Status_t : 0 - success
                                    1 - failure
**
**
*/
phFWD_Status_t phGenericSendAndRecv(uint8_t *payload, uint16_t len, uint8_t *read_buff, uint16_t *rsp_buf_len);

/**
**
** Function    :   handleGetInfoRsp
**
** Description :   This function handles the GetInfo response that is received
                   from the HeliosX chip.
**
** Parameters  :   hdll_payload  - HDLL response buffer
**
** Returns     :   FW_DNLD_FAILURE - If any un expected failure
                   FW_DNLD_NOT_REQUIRED - FW update not required
                   FW_DNLD_REQUIRED - FW update required
                   FW_DNLD_FILE_NOT_FOUND - if the FW bin file is unable to
                                                open or not present
**
**
*/
phFWD_Status_t handleGetInfoRsp(uint8_t *hdll_payload);

/**
**
** Function    :   sendEdlDownloadCertificateCmd
**
** Description :   This function frames the EdlDownloadCertificateCmd which
                   needs to be sent as part of FW download sequence.
**
** Parameters  :   payload  - HDLL command buffer
                   len - command buffer length
                   rsp_buf - response buffer that will be received from the
                   HeliosX chip.
**
** Returns     :   FW_DNLD_FAILURE - If any undesired response received
                   FW_DNLD_SUCCESS - On proper response
**
**
*/
phFWD_Status_t sendEdlDownloadCertificateCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf);

/**
**
** Function    :   sendEdlFlashWriteFirstCmd
**
** Description :   This function frames the EdlFlashWriteFirstCmd which
                   needs to be sent as part of FW download sequence.
**
** Parameters  :   payload  - HDLL command buffer
                   len - command buffer length
                   rsp_buf - response buffer that will be received from the
                   HeliosX chip.
**
** Returns     :   FW_DNLD_FAILURE - If any undesired response received
                   FW_DNLD_SUCCESS - On proper response
**
**
*/
phFWD_Status_t sendEdlFlashWriteFirstCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf);

/**
**
** Function    :   sendEdlFlashWriteCmd
**
** Description :   This function frames the sendEdlFlashWriteCmd which
                   will have the actual FW chunk.
**
** Parameters  :   payload  - HDLL command buffer
                   len - command buffer length
                   rsp_buf - response buffer that will be received from the
                   HeliosX chip.
**
** Returns     :   FW_DNLD_FAILURE - If any undesired response received
                   FW_DNLD_SUCCESS - On proper response
**
**
*/
phFWD_Status_t sendEdlFlashWriteCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf);

/**
**
** Function    :   sendEdlFlashWriteLastCmd
**
** Description :   This function frames the EdlFlashWriteLastCmd which
                   needs to be sent as part of FW download sequence.
**
** Parameters  :   payload  - HDLL command buffer
                   len - command buffer length
                   rsp_buf - response buffer that will be received from the
                   HeliosX chip.
**
** Returns     :   FW_DNLD_FAILURE - If any undesired response received
                   FW_DNLD_SUCCESS - On proper response
**
**
*/
phFWD_Status_t sendEdlFlashWriteLastCmd(uint8_t *payload, uint16_t len, uint8_t *rsp_buf);

/**
**
** Function    :   phGetEdlReadyNtf
**
** Description :   This function frames the GetEdlReadyNtf command and sends to
                   the HeliosX chip
**
** Parameters  :   None
**
** Returns     :   FW_DNLD_FAILURE - If any failure occurs while framing or
                                    sending the command or while receiving the
                                    response
                   FW_DNLD_SUCCESS - On success
**
**
*/
phFWD_Status_t phGetEdlReadyNtf(void);

/**
**
** Function    :   phGenericGetInfo
**
** Description :   This function frames the GenericGetInfo command and sends to
                   the HeliosX chip
**
** Parameters  :   None
**
** Returns     :   FW_DNLD_FAILURE - If any failure occurs while framing or
                                    sending the command or while receiving the
                                    response
                   FW_DNLD_SUCCESS - On success
**
**
*/
phFWD_Status_t phGenericGetInfo(void);

/**
**
** Function    :   phHdll_send_and_recv
**
** Description :   This function sends and receives the HDLL commands and
                   responses based on the given operation code.
**
** Parameters  :   hdll_data - HDLL command buffer
                   hdll_data_len - HDLL command buffer len
                   operation - which will have the group and operation
                               code info.
**
** Returns     :   FW_DNLD_FAILURE - If any failure occurs while framing or
                                    sending the command or while receiving the
                                    response
                   FW_DNLD_SUCCESS - On success
**
**
*/
phFWD_Status_t phHdll_send_and_recv(uint8_t *hdll_data, uint32_t hdll_data_len, eOperation_t operation);
/**
**
** Function    :   process_getInfo_rsp
**
** Description :   This function processes the HDLL GetInfo command's response
**
** Parameters  :   payload  - Struct in which the processed info will be kept
**                 pointer to phHDLLGetInfo_t stucture
**
** Returns     :   void
**
**
*/
void process_getInfo_rsp(uint8_t *payload, phHDLLGetInfo_t *getInfoRsp);
/**
**
** Function    :   process_getInfoExt_rsp
**
** Description :   This function processes the HDLL GetExtInfo command's response
**
** Parameters  :   payload  - Struct in which the processed info will be kept
**                 pointer to phHDLLGetInfoExt_t stucture
**
** Returns     :   void
**
**
*/
void process_getInfoExt_rsp(uint8_t *payload, phHDLLGetInfoExt_t *getExtInfoRsp);

/**
**
** Function    :   print_getInfoRsp
**
** Description :   This function prints the HDLL GetInfo command's response
**
** Parameters  :   getInfoRsp  - Struct which has the GetInfo response details.
**
** Returns     :   None
**
**
*/
void print_getInfoRsp(phHDLLGetInfo_t *getInfoRsp);
#endif /* _PHNXPUCIHAL_FW_H */
