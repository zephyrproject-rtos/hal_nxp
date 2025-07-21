/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ENDAT2P2_H_
#define FSL_ENDAT2P2_H_

#include "fsl_common.h"

/*!
 * @addtogroup endat2p2
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_ENDAT2P2_DRIVER_VERSION (MAKE_VERSION(1, 0, 1)) /*!< Version 1.0.1 */
/*! @} */

#define SSI_MODE            0x1
#define ENDAT_MODE          0x2

/*! @name EnDat2.2 clock */
/*! @{ */
#define ENDAT2P2_CLK_100M   (100 * 1000 * 1000)
#define ENDAT2P2_CLK_64M    (64 * 1000 * 1000)
#define ENDAT2P2_CLK_50M    (50 * 1000 * 1000)
#define ENDAT2P2_CLK_48M    (48 * 1000 * 1000)
#define ENDAT2P2_CLK_32M    (32 * 1000 * 1000)
#define ENDAT2P2_CLK_16M    (16 * 1000 * 1000)
#define ENDAT2P2_CLK_8M     (8 * 1000 * 1000)
#define ENDAT2P2_CLK_4M     (4 * 1000 * 1000)
#define ENDAT2P2_CLK_2M     (2 * 1000 * 1000)
#define ENDAT2P2_CLK_1M     (1 * 1000 * 1000)
#define ENDAT2P2_CLK_200K   (200 * 1000)
#define ENDAT2P2_CLK_100K   (100 * 1000)
/*! @} */

/*! @brief EnDat2.2 addation information */
#define ENDAT2P2_ADDINFO_MASK           0xFFFFFF
#define ENDAT2P2_ADDINFO_POS_MASK       0xFFFF
#define ENDAT2P2_ADDINFO_TEMP_MASK      0x0FFF
#define ENDAT2P2_ADDINFO_MEM_DATA_MASK  0x00FF
#define ENDAT2P2_ADDINFO_MEM_ADDR_SHIFT 8
#define ENDAT2P2_ADDINFO_MEM_ADDR_MASK  0xFF00
#define ENDAT2P2_ADDINFO_INS_SHIFT      16
#define ENDAT2P2_ADDINFO_INS_MASK       (0x1f << 16)
#define ENDAT2P2_ADDINFO_BUSY_MASK      (0x1 << 21)
#define ENDAT2P2_ADDINFO_RM_MASK        (0x1 << 22)
#define ENDAT2P2_ADDINFO_WRN_MASK       (0x1 << 23)

/*! @brief EnDat2.2 addation information 1 */
#define ENDAT2P2_ADDINFO1_STATUS_POS2_MASK      (0x1 << 0)
#define ENDAT2P2_ADDINFO1_STATUS_TEST_MASK      (0x1 << 1)
#define ENDAT2P2_ADDINFO1_STATUS_TEMP1_MASK     (0x1 << 2)
#define ENDAT2P2_ADDINFO1_STATUS_TEMP2_MASK     (0x1 << 3)
#define ENDAT2P2_ADDINFO1_STATUS_SENSORS_MASK   (0x1 << 4)

/*! @brief EnDat2.2 addation information 2 */
#define ENDAT2P2_ADDINFO2_STATUS_COMMUTATION_MASK  (0x1 << 0)
#define ENDAT2P2_ADDINFO2_STATUS_ACCELERATION_MASK (0x1 << 1)
#define ENDAT2P2_ADDINFO2_STATUS_LIMITPOS_MASK     (0x1 << 2)
#define ENDAT2P2_ADDINFO2_STATUS_ASYNCPOS_MASK     (0x1 << 3)
#define ENDAT2P2_ADDINFO2_STATUS_OPTERRSRC_MASK    (0x1 << 4)
#define ENDAT2P2_ADDINFO2_STATUS_POS2_MASK         (0x1 << 6)
#define ENDAT2P2_ADDINFO2_STATUS_TIMESTAMP_MASK    (0x1 << 7)

/*! @brief EnDat2.2 operating status */
#define ENDAT2P2_OPT_ERR_LIGHTING_MASk          (1 << 0x0)
#define ENDAT2P2_OPT_ERR_SIGNAL_AMPLITUDE_MASk  (1 << 0x1)
#define ENDAT2P2_OPT_ERR_POSITION_MASk          (1 << 0x2)
#define ENDAT2P2_OPT_ERR_OVERVOLTAGE_MASk       (1 << 0x3)
#define ENDAT2P2_OPT_ERR_UNDERVLOTAGE_MASk      (1 << 0x4)
#define ENDAT2P2_OPT_ERR_OVERCURRENT_MASk       (1 << 0x5)
#define ENDAT2P2_OPT_ERR_BATTERY_MASk           (1 << 0x6)

#define ENDAT2P2_OPT_WARN_FREQ_COLLISION_MASk   (1 << 0x0)
#define ENDAT2P2_OPT_WARN_TEMP_EXCEEDED_MASk    (1 << 0x1)
#define ENDAT2P2_OPT_WARN_LIGHT_RESERVE_MASk    (1 << 0x2)
#define ENDAT2P2_OPT_WARN_BATTERY_CHARGE_MASk   (1 << 0x3)
#define ENDAT2P2_OPT_WARN_REGERNVE_POINT_MASk   (1 << 0x4)
#define ENDAT2P2_OPT_WARN_CYCLIC_MODE_MASk      (1 << 0x5)
#define ENDAT2P2_OPT_WARN_LIMIT_POSITION_MASk   (1 << 0x6)
#define ENDAT2P2_OPT_WARN_STANDBY_MASk          (1 << 0x7)
#define ENDAT2P2_OPT_WARN_DIAGNOSTICS_MASk      (1 << 0x8)

#define ENDAT_NUM_BITS_POSITION_CRC 5
#define ENDAT_NUM_BITS_F1           1
#define ENDAT_NUM_BITS_F2           1
#define ENDAT_NUM_BITS_PARAMETER    16
#define ENDAT_NUM_BITS_ADDRESS      8

/*! @brief EnDat2.2 mode command */
typedef enum _ENDAT2P2P2_mode_cmd
{
    ENDAT2P2_CMD_SEND_POSITION_VALUE                    = 0x07,
    ENDAT2P2_CMD_SELECT_MEM_AREA                        = 0x0E,
    ENDAT2P2_CMD_RECEIVE_PARAMETERS                     = 0x1C,
    ENDAT2P2_CMD_SEND_PARAMETERS                        = 0x23,
    ENDAT2P2_CMD_RECEIVE_RESET                          = 0x2A,
    ENDAT2P2_CMD_SEND_TEST_VALUES                       = 0x15,
    ENDAT2P2_CMD_RECEIVE_TEST_COMMAND                   = 0x31,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO               = 0x38,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM       = 0x09,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_PARAM    = 0x1B,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEND_PARAM    = 0x24,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_ERR_RST  = 0x2D,
    ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_TESTCMD  = 0x36,
    ENDAT2P2_CMD_RECEIVE_COMMUNICATION_CMD              = 0x12,
} endat2p2_mode_cmd_t;

/*! @brief EnDat2.2 MRS code */
typedef enum _mrs_mode {
    /* MRS code for selecting the memory area */
    MRS_CODE_OPERATING_STATUS                            = 0xB9, /* 4 words */
    MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE0            = 0xA1, /* 12 words */
    MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1            = 0xA3, /* 16 words */
    MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE2            = 0xA5, /* 16 words */
    MRS_CODE_PARAM_OPERATING_PARAMS                      = 0xA7, /* 16 words */
    MRS_CODE_PARAM_OEM_PAGE0                             = 0xA9, /* 64 words */
    MRS_CODE_PARAM_OEM_PAGE1                             = 0xAB, /* 128 words */
    MRS_CODE_PARAM_OEM_PAGE2                             = 0xAD, /* 128 words */
    MRS_CODE_PARAM_OEM_PAGE3                             = 0xAF, /* 128 words */
    MRS_CODE_COMPENSATION_ENCODER_MANUFACTURER_1         = 0xB1,
    MRS_CODE_COMPENSATION_ENCODER_MANUFACTURER_2         = 0xB3,
    MRS_CODE_COMPENSATION_ENCODER_MANUFACTURER_3         = 0xB5,
    MRS_CODE_COMPENSATION_ENCODER_MANUFACTURER_4         = 0xB7,
    MRS_CODE_PARAM_ENCODER_MFG_ENDAT2P2_2                = 0xBD, /*  64 words */
    MRS_CODE_PARAM_SECTION2_MEMORY_AREA                  = 0xBF,
    MRS_CODE_OPERATING_PARAMETERS                        = 0xBB,

    /* MRS code for selecting the additional data */
    MRS_CODE_ADDITIONAL_INFO1_WITHOUT_DATA              = 0x40,
    MRS_CODE_ADDITIONAL_INFO1_DIAGNOSTIC                = 0x41,
    MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD1_LSB         = 0x42,
    MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD2             = 0x43,
    MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD3_MSB         = 0x44,
    MRS_CODE_ADDITIONAL_INFO1_ACK_MEM_LSB               = 0x45,
    MRS_CODE_ADDITIONAL_INFO1_ACK_MEM_MSB               = 0x46,
    MRS_CODE_ADDITIONAL_INFO1_ACK_MRS_CODE              = 0x47,
    MRS_CODE_ADDITIONAL_INFO1_ACK_TEST_CMD              = 0x48,
    MRS_CODE_ADDITIONAL_INFO1_TESTVAL_WORD1_LSB         = 0x49,
    MRS_CODE_ADDITIONAL_INFO1_TESTVAL_WORD2             = 0x4A,
    MRS_CODE_ADDITIONAL_INFO1_TESTVAL_WORD3_MSB         = 0x4B,
    MRS_CODE_ADDITIONAL_INFO1_TEMPERATURE1              = 0x4C,
    MRS_CODE_ADDITIONAL_INFO1_TEMPERATURE2              = 0x4D,
    MRS_CODE_ADDITIONAL_INFO1_ADTL_SENSORS              = 0x4E,
    MRS_CODE_ADDITIONAL_INFO1_STOP_DATA                 = 0x4F,

    MRS_CODE_ADDITIONAL_INFO2_WITHOUT_DATA              = 0x50,
    MRS_CODE_ADDITIONAL_INFO2_COMMUNICATION             = 0x51,
    MRS_CODE_ADDITIONAL_INFO2_ACCELERATION              = 0x52,
    MRS_CODE_ADDITIONAL_INFO2_COMM_AND_ACCLN            = 0x53,
    MRS_CODE_ADDITIONAL_INFO2_LIMIT_POS_SIGNAL          = 0x54,
    MRS_CODE_ADDITIONAL_INFO2_LPS_AND_ACCLN             = 0x55,
    MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD1_LSB    = 0x56,
    MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD2        = 0x57,
    MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD3_MSB    = 0x58,
    MRS_CODE_ADDITIONAL_INFO2_OPSTATUS_ERRSOURCE        = 0x59,
    MRS_CODE_ADDITIONAL_INFO2_TIMESTAMP                 = 0x5B,
    MRS_CODE_ADDITIONAL_INFO2_STOP_DATA                 = 0x5F,
} mrs_mode_t;

/*! @brief EnDat2.2 memory address */
typedef enum _endat2p2_mem_word_addr {
    ENDAT2P2_MEM_WORD_0  = 0,
    ENDAT2P2_MEM_WORD_1  = 1,
    ENDAT2P2_MEM_WORD_2  = 2,
    ENDAT2P2_MEM_WORD_3  = 3,
    ENDAT2P2_MEM_WORD_4  = 4,
    ENDAT2P2_MEM_WORD_5  = 5,
    ENDAT2P2_MEM_WORD_6  = 6,
    ENDAT2P2_MEM_WORD_7  = 7,
    ENDAT2P2_MEM_WORD_8  = 8,
    ENDAT2P2_MEM_WORD_9  = 9,
    ENDAT2P2_MEM_WORD_10 = 10,
    ENDAT2P2_MEM_WORD_11 = 11,
    ENDAT2P2_MEM_WORD_12 = 12,
    ENDAT2P2_MEM_WORD_13 = 13,
    ENDAT2P2_MEM_WORD_14 = 14,
    ENDAT2P2_MEM_WORD_15 = 15,
    ENDAT2P2_MEM_WORD_16 = 16,
    ENDAT2P2_MEM_WORD_17 = 17,
    ENDAT2P2_MEM_WORD_18 = 18,
    ENDAT2P2_MEM_WORD_19 = 19,
} endatp2p_mem_word_addr_t;

#define ENDAT2P2_TYPE_WITH_BATTERY_SHIFT 1
#define ENDAT2P2_TYPE_ABSOLUTE_SHIFT     2
#define ENDAT2P2_TYPE_ROTARY_SHIFT       3

/*! @brief EnDat2.2 encoder type */
typedef enum  _encoder_type {
    ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITHOUT_DCRM            = 0b0000,
    ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_DCRM               = 0b0001,
    ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_BAT_WITHOUT_DCRM   = 0b0010,
    ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_BAT_WITH_DCRM      = 0b0011,
    ENDAT2P2_ENCODER_TYPE_ABSO_LINEAR                         = 0b0100,
    ENDAT2P2_ENCODER_TYPE_ABSO_LINEAR_WITH_CYCLIC             = 0x0110,
    ENDAT2P2_ENCODER_TYPE_NOTE_TOUCH_D                        = 0x0101,
    ENDAT2P2_ENCODER_TYPE_NOTE_D                              = 0x0111,
    ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITHOUT_DCRM            = 0b1000,
    ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_DCRM               = 0b1001,
    ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_BAT_WITHOUT_DCRM   = 0b1010,
    ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_BAT_WITH_DCRM      = 0b1011,
    ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_SINGLETURN              = 0b1100,
    ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_MULTITURN_WITH_BAT      = 0b1101,
    ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_MULTITURN_WITH_GEARS    = 0b1110,
    ENDAT2P2_ENCODER_TYPE_EIB                                 = 0b1111,
} encode_type_t;

/*! @brief EnDat2.2 device */
typedef struct _endat2p2_dev {
    ENDAT2P2_Type *base;
    uint32_t fsys;
    uint32_t ftclk;
    uint32_t master_id;
    uint32_t pos_res;
    uint32_t id_ascii;
    uint32_t id_binary;
    uint32_t sn_binary;
    uint32_t sn_ascii_msb;
    uint32_t sn_ascii_lsb;
    uint32_t cmd_set_2_2;
    uint32_t has_safety;
    uint32_t single_turn_res;
    uint32_t multi_turn_res;
    int step;
    int type;
    int rx_en_cnt;
    int status_addinfo2;
    int status_addinfo1;
} endat2p2_dev_t;

/*! @brief EnDat2.2 received data - position, additional information 1 & 2 */
typedef struct _endat2p2_data
{
    /* position */
    uint64_t  recvd1;
    /* addinfo 2 */
    uint32_t  recvd2;
    /* addinfo 1 */
    uint32_t  recvd3;
} endat2p2_data_t;

/*! @brief EnDat2.2 position value */
typedef struct _endat2p2_position
{
    uint64_t position;
    uint64_t revolution;
} endat2p2_position_t;

/*! @brief EnDat2.2 position and additional information */
typedef struct endat2p2_position_addinfo
{
    uint64_t position;
    uint64_t revolution;
    uint32_t addinfo1;
    uint32_t addinfo2;
} endat2p2_position_addinfo_t;

/*! @brief EnDat2.2 memory addr and parameter */
typedef struct _endat2p2_addr_param
{
    uint8_t     address;
    uint16_t    param;
} endat2p2_addr_param_t;

/*! @brief EnDat2.2 encoder received data */
typedef struct _endat2p2_recv_data
{
    union
    {
        endat2p2_position_t         position;
        endat2p2_position_addinfo_t position_addinfo;
        endat2p2_addr_param_t       addr_param;
    };
    uint32_t status;

} endat2p2_recv_data_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Convert sensor type to descriptor string.
 * @param encode_t Encoder type.
 * @return The encoder descriptor.
 */
char *ENDAT2P2_GetTypeStr(encode_type_t encode_t);

/*!
 * @brief Get EnDat2.2 device handle pointer.
 *
 * @param base EnDat2.2 peripheral address.
 * @return EnDat2.2 device handle pointer.
 */
endat2p2_dev_t *ENDAT2P2_GetDev(ENDAT2P2_Type *base);

/*!
 * @brief Initialize the EnDat2.2 device.
 * This function configures the EnDat2.2 module with the input parameters.
 * User should call this function before any EnDat2.2 operations.
 * @param base EnDat2.2 peripheral base address.
 * @param fsys EnDat2.2 sys clock frequency.
 * @return The EnDat2.2 device handle pointer.
 */
endat2p2_dev_t *ENDAT2P2_InitMaster(ENDAT2P2_Type *base, uint32_t fsys);

/*!
 * @brief Check if encoder is rotary
 * @param dev EnDat2.2 device handle pointer.
 * @return true - is rotary.
 */
bool ENDAT2P2_EncoderIsRotary(endat2p2_dev_t *dev);

/*!
 * @brief Check if the receive register is updated by new data.
 * @param dev EnDat2.2 device handle pointer.
 * @return true - receive new data.
 * @return false - not receive new data.
 */
bool ENDAT2P2_CheckRecv(endat2p2_dev_t *dev);

/*!
 * @brief Get configuration register 1.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of configration register 1.
 */
uint32_t ENDAT2P2_GetConfR1(endat2p2_dev_t *dev);

/*!
 * @brief Get the status register
 * @param dev EnDat2.2 device handle pointer.
 * @return the vaule of status register.
 */
uint32_t ENDAT2P2_GetStatus(endat2p2_dev_t *dev);

/*!
 * @brief Clear the status register.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_CleanStatus(endat2p2_dev_t *dev);

/*!
 * @brief Set the interupt mask register.
 * @param dev EnDat2.2 device handle pointer.
 * @param mask The mask value of interrupt mask.
 */
void ENDAT2P2_SetInterruptMask(endat2p2_dev_t *dev, uint32_t mask);

/*!
 * @brief Get the receive register 1.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of receive register 1.
 */
uint64_t ENDAT2P2_GetRecvReg1(endat2p2_dev_t *dev);

/*!
 * @brief Get the receive register 2.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of receive register 2.
 */
uint32_t ENDAT2P2_GetRecvReg2(endat2p2_dev_t *dev);

/*!
 * @brief Get the receive register 3.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of receive register 3.
 */
uint32_t ENDAT2P2_GetRecvReg3(endat2p2_dev_t *dev);

/*!
 * @brief Get the additional information 1.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of additional information 1.
 */
uint32_t ENDAT2P2_GetAddInfo1(endat2p2_dev_t *dev);

/*!
 * @brief Get the additional information 2.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of additional information 2.
 */
uint32_t ENDAT2P2_GetAddInfo2(endat2p2_dev_t *dev);

/*!
 * @brief Get the position value.
 * @param dev EnDat2.2 device handle pointer.
 * @return position data including MT and ST.
 */
endat2p2_position_t ENDAT2P2_RecvPosition(endat2p2_dev_t *dev);

/*!
 * @brief Get the position value and additional information.
 * @param dev EnDat2.2 device handle pointer.
 * @return position value and additional information.
 */
endat2p2_position_addinfo_t ENDAT2P2_RecvPositionAddInfo(endat2p2_dev_t *dev);

/*!
 * @brief Get the address and parameter.
 * @param dev EnDat2.2 device handle pointer.
 * @return address and parameter.
 */
endat2p2_addr_param_t ENDAT2P2_RecvAddrParam(endat2p2_dev_t *dev);

/*!
 * @brief Get the received data.
 * @param dev EnDat2.2 device handle pointer.
 * @param cmd Mode command.
 * @param pointer of received data
 * @return 0 - successfully get the data
 * @return -EINVAL - invalid mode command
 */
int ENDAT2P2_RecvData(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                      endat2p2_recv_data_t *data);

/*!
 * @brief Create the command and write to the send register.
 * @param dev EnDat2.2 device handle pointer.
 * @param cmd Mode command.
 * @param mrs_or_addr MRS code or memory address.
 * @param param Parameter of memory.
 */
void ENDAT2P2_CMDBuild(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                       uint8_t mrs_or_addr, uint16_t param);

/*!
 * @brief trigger master to send out the command.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_CMDSend(endat2p2_dev_t *dev);

/*!
 * @brief Wait for the command to be processed.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_CMDWait(endat2p2_dev_t *dev);

/*!
 * @brief Process the command
 * @param dev EnDat2.2 device handle pointer.
 * @param cmd Mode command.
 * @param mrs_or_addr MRS code or memory address.
 * @param param Parameter of memory.
 */
void ENDAT2P2_CMDProcess(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                         uint8_t msr_or_addr, uint16_t param);

/*!
 * @brief Reset encoder
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_EncoderRest(endat2p2_dev_t *dev);

/*!
 * @brief Get the parameter of memory.
 * @param dev EnDat2.2 device handle pointer.
 * @param page Memory page.
 * @param addr Memory address.
 * @return the value of the parameter.
 */
int ENDAT2P2_GetParam(endat2p2_dev_t *dev, uint8_t page, uint8_t addr);

/*!
 * @brief Set the parameter of memory.
 * @param dev EnDat2.2 device handle pointer.
 * @param page Memory page.
 * @param addr Memory address.
 * @param data Parameter of memory.
 */
void ENDAT2P2_SetParam(endat2p2_dev_t *dev, uint8_t page,
                       uint8_t addr, uint16_t data);

/*!
 * @brief Reset encoder and get the position resolution.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_EncoderRestWithPos(endat2p2_dev_t *dev);

/*!
 * @brief Get the parameter and get the position resolution.
 * @param dev EnDat2.2 device handle pointer.
 * @param page Memory page.
 * @param addr Memory address.
 * @return the value of the memory.
 */
int ENDAT2P2_GetParamWithPos(endat2p2_dev_t *dev, uint8_t page, uint8_t addr);

/*!
 * @brief Set the parameter and get the position resolution.
 * @param dev EnDat2.2 device handle pointer.
 * @param page Memory page.
 * @param addr Memory address.
 * @param data Parameter of memory.
 */
void ENDAT2P2_SetParamWithPos(endat2p2_dev_t *dev, uint8_t page,
                              uint8_t addr, uint16_t data);

/*!
 * @brief Get the position resolution.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the position resolution.
 */
int ENDAT2P2_GetPosRes(endat2p2_dev_t *dev);

/*!
 * @brief Get the type of encoder.
 * @param dev EnDat2.2 device handle pointer.
 * @return the type value.
 */
int ENDAT2P2_GetType(endat2p2_dev_t *dev);

/*!
 * @brief Get the multiple turn resolution.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the multiple turn resolution.
 */
int ENDAT2P2_GetMultiTurnRes(endat2p2_dev_t *dev);

/*!
 * @brief Get the step resolution.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the step resolution.
 */
int ENDAT2P2_GetStep(endat2p2_dev_t *dev);

/*!
 * @brief Get the ID of encoder and store
 * to dev->id_ascii and dev->id_binary.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_GetID(endat2p2_dev_t *dev);

/*!
 * @brief Get the serial number of encoder
 * and store to dev->sn_ascii_msb and dev->sn_ascii_lsb.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_GetSN(endat2p2_dev_t *dev);

/*!
 * @brief Get the command set of encoder
 * and store to dev->cmd_set_2_2 and dev->has_safety.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_GetCommandSet(endat2p2_dev_t *dev);

/*!
 * @brief Get the additional information.
 * Store to dev->status_addinfo1 and dev->status_addinfo2.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_GetStatusAddInfo(endat2p2_dev_t *dev);

/*!
 * @brief Get the encoder error.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the encoder error.
 */
int  ENDAT2P2_GetEncoderError(endat2p2_dev_t *dev);

/*!
 * @brief Clear the encoder error.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_ClearEncoderError(endat2p2_dev_t *dev);

/*!
 * @brief Get the encoder warning.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the encoder warning.
 */
int  ENDAT2P2_GetEncoderWarning(endat2p2_dev_t *dev);

/*!
 * @brief Clear the encoder warning.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_ClearEncoderWarning(endat2p2_dev_t *dev);

/*!
 * @brief Get the encoder information.
 * @param dev EnDat2.2 device handle pointer.
 * @return 0 - sucessfully get the encoder information.
 */
int ENDAT2P2_GetEncoderInfo(endat2p2_dev_t *dev);

/*!
 * @brief Initialize encoder.
 * @param dev EnDat2.2 device handle pointer.
 */
int ENDAT2P2_InitEncoder(endat2p2_dev_t *dev);

/*!
 * @brief Get encoder error with the position value.
 * @param dev EnDat2.2 device handle pointer.
 * @return the error value.
 */
int  ENDAT2P2_GetEncoderErrorWithPos(endat2p2_dev_t *dev);

/*!
 * @brief Clear encoder error with the position value.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_ClearEncoderErrorWithPos(endat2p2_dev_t *dev);

/*!
 * @brief Get encoder warning with the position value.
 * @param dev EnDat2.2 device handle pointer.
 * @return the warning value.
 */
int  ENDAT2P2_GetEncoderWarningWithPos(endat2p2_dev_t *dev);

/*!
 * @brief Clear encoder warning with the position value.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_ClearEncoderWarningWithPos(endat2p2_dev_t *dev);

/*!
 * @brief Select the encoder additional information.
 * @param dev EnDat2.2 device handle pointer.
 * @param mrs MRS code.
 */
void ENDAT2P2_AddInfoSelect(endat2p2_dev_t *dev, mrs_mode_t mrs);

/*!
 * @brief Stop getting additional information 1.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_AddInfo1Stop(endat2p2_dev_t *dev);

/*!
 * @brief Stop getting additional information 2.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_AddInfo2Stop(endat2p2_dev_t *dev);

/*!
 * @brief Get the position value 2.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of the position value 2.
 */
uint64_t ENDAT2P2_GetPosVal2(endat2p2_dev_t *dev);

/*!
 * @brief Get the temperature.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of temperature.
 */
double ENDAT2P2_GetTemperature1(endat2p2_dev_t *dev);

/*!
 * @brief Get the temperature 2.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of temperature.
 */
double ENDAT2P2_GetTemperature2(endat2p2_dev_t *dev);

/*!
 * @brief Get the async position value 2.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of async position value 2.
 */
uint64_t ENDAT2P2_GetAsyncPosVal2(endat2p2_dev_t *dev);

/*!
 * @brief Get the operating status error source.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of error source.
 */
int ENDAT2P2_GetOPSERRSRC(endat2p2_dev_t *dev);

/*!
 * @brief Get the timestamp.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of timestamp.
 */
int ENDAT2P2_GetTimeStamp(endat2p2_dev_t *dev);

/* EnDat Master setting */

/*!
 * @brief Enable hardware strobe mode.
 * @param dev EnDat2.2 device handle pointer.
 * @param enable enable/disable hardware strobe mode .
 */
void ENDAT2P2_SetHWStrobe(endat2p2_dev_t *dev, bool enable);

/*!
 * @brief Set DU bit of configuration register.
 * @param dev EnDat2.2 device handle pointer.
 * @param on set or clear DU bit.
 */
void ENDAT2P2_SetDU(endat2p2_dev_t *dev, bool on);

/*!
 * @brief Set DT bit to select continuous clock mode.
 * @param dev EnDat2.2 device handle pointer.
 * @param on set or clear DT bit.
 */
void ENDAT2P2_SetDT(endat2p2_dev_t *dev, bool on);

/*!
 * @brief Set the data word length.
 * @param dev EnDat2.2 device handle pointer.
 * @param length the length of data word.
 */
void ENDAT2P2_SetDataWordLength(endat2p2_dev_t *dev, int length);

/*!
 * @brief Set bit Reset window.
 * @param dev EnDat2.2 device handle pointer.
 * @param reset set to 0 or 1 to this bit.
 */
void ENDAT2P2_SetResetWindow(endat2p2_dev_t *dev, bool reset);

/*!
 * @brief Set the auto reset.
 * @param dev EnDat2.2 device handle pointer.
 * @param enable enable/disable auto reset.
 */
void ENDAT2P2_SetAutoReset(endat2p2_dev_t *dev, bool enable);

/*!
 * @brief Set cable propagation time.
 * @param dev EnDat2.2 device handle pointer.
 * @param time the time of cable propagation.
 */
void ENDAT2P2_SetCablePropagationTime(endat2p2_dev_t *dev, uint32_t time);

/*!
 * @brief Get the cable propagation time.
 * @param dev EnDat2.2 device handle pointer.
 * @return the value of cable propagation time.
 */
uint32_t ENDAT2P2_GetCablePropagationTime(endat2p2_dev_t *dev);

/*!
 * @brief Calculate the propagation time.
 * @param dev EnDat2.2 device handle pointer.
 * @param count the count of the propagation time.
 * @return the value of the propagation time.
 */
uint32_t ENDAT2P2_CalculatePropagationTime(endat2p2_dev_t *dev, int count);

/*!
 * @brief Set the delay compensation.
 * @param dev EnDat2.2 device handle pointer.
 * @param enable enable/disable delay compensation.
 */
void ENDAT2P2_SetDelayCompensation(endat2p2_dev_t *dev, bool enable);

/*!
 * @brief Enable the delay compensation.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_EnableDelayCompensation(endat2p2_dev_t *dev);

/*!
 * @brief Set sysclock of the master.
 * @param dev EnDat2.2 device handle pointer.
 * @param sysclock system clock.
 */
void ENDAT2P2_ConfigSYSClock(endat2p2_dev_t *dev, uint32_t sysclock);

/*!
 * @brief Set the transmission rate for EnDat.
 * @param dev EnDat2.2 device handle pointer.
 * @param clock transmission rate.
 * @return 0 - successfully set ftclk.
 * @return -EINVAL - invalid clock parameter.
 */
int ENDAT2P2_SetFTCLOCK(endat2p2_dev_t *dev, uint32_t clock);

/*!
 * @brief Reset entire interface component.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_ICReset(endat2p2_dev_t *dev);

/*!
 * @brief Set the EnDat mode.
 * @param dev EnDat2.2 device handle pointer.
 */
void ENDAT2P2_SetEnDatMode(endat2p2_dev_t *dev);

/*!
 * @brief Set sampling rate.
 * @param dev EnDat2.2 device handle pointer.
 * @param us the clock of sampling.
 */
void ENDAT2P2_SetSamplingRate(endat2p2_dev_t *dev, int us);

/*!
 * @brief Set the watchdog timer.
 * @param dev EnDat2.2 device handle pointer.
 * @param us the time of watchdog timer.
 */
void ENDAT2P2_SetWatchdogTimer(endat2p2_dev_t *dev, int us);

/*!
 * @brief Set the recovery timer.
 * @param dev EnDat2.2 device handle pointer.
 * @param us the time ofrecovery timer.
 */
void ENDAT2P2_SetRecoveryTimer(endat2p2_dev_t *dev, int us);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/* @} */

#endif /* FSL_ENDAT2P2_H_ */
