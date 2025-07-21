/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_endat2p2.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.endat2p2"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define ENDAT_NUM_BITS_VALID_PAGE0_WORD13 6
#define ENDAT_NUM_BITS_VALID_PAGE1_WORD1 16
#define FSL_ENDAT2P2_COUNT 2

/*! @brief Array to map EDMA instance number to base pointer. */
static ENDAT2P2_Type *const s_EnDatBases[] = ENDAT2P2_BASE_PTRS;

static endat2p2_dev_t s_EnDat2p2Dev[FSL_ENDAT2P2_COUNT];

static int NumTo2N(uint32_t x)
{
    int i = 0;

    while(x >>= 1)
    {
        i++;
    }

    return i;
}

static void ENDAT2P2_DelayUs(uint32_t delay_us)
{
    SDK_DelayAtLeastUs(delay_us, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

char *ENDAT2P2_GetTypeStr(encode_type_t encode_t)
{
    switch (encode_t)
    {
    case ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITHOUT_DCRM:
        return "Incremental linear encoder without distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_DCRM:
        return "Incremental linear encoder with distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_BAT_WITH_DCRM:
        return "Incremental linear encoder with battery buffer and distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_LINEAR_WITH_BAT_WITHOUT_DCRM:
        return "Incremental linear encoder with battery buffer and without distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_ABSO_LINEAR:
        return "Absolute linear encoder";
        break;
    case ENDAT2P2_ENCODER_TYPE_ABSO_LINEAR_WITH_CYCLIC:
        return "Absolute linear encoder with cyclic coding";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITHOUT_DCRM:
        return "Incremental rotary encoder with distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_DCRM:
        return "Incremental rotary encoder without distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_BAT_WITHOUT_DCRM:
        return "Incremental rotary encoder with battery buffer and distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_INCR_ROTARY_WITH_BAT_WITH_DCRM:
        return "Incremental rotary encoder with battery buffer and without distance-coded reference marks";
        break;
    case ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_SINGLETURN:
        return "Singleturn rotary encoder";
        break;
    case ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_MULTITURN_WITH_BAT:
        return "Multiturn rotary encoder with battery buffer";
        break;
    case ENDAT2P2_ENCODER_TYPE_ABSO_ROTARY_MULTITURN_WITH_GEARS:
        return "Multiturn rotary encoder with gears";
        break;
    default:
        return "Not support";
    }
}

bool ENDAT2P2_EncoderIsRotary(endat2p2_dev_t *dev)
{
    return dev->type & (1 << ENDAT2P2_TYPE_ROTARY_SHIFT);
}

endat2p2_dev_t *ENDAT2P2_GetDev(ENDAT2P2_Type *base)
{
    int i;

    for(i = 0; i < ARRAY_SIZE(s_EnDatBases); i++)
    {
        if (s_EnDatBases[i] == base)
        {
            break;
        }
    }

    assert(i < ARRAY_SIZE(s_EnDatBases));

    return &s_EnDat2p2Dev[i];
}

bool ENDAT2P2_CheckRecv(endat2p2_dev_t *dev)
{
    uint32_t status;

    status = dev->base->STATUSREGISTER;

    if (!(status & ENDAT2P2_STATUSREGISTER_RECEIVE_REGISTER1_MASK))
    {
        return false;
    }

    return true;
}

uint32_t ENDAT2P2_GetConfR1(endat2p2_dev_t *dev)
{
    return dev->base->CONFIGREGISTER1;
}

uint32_t ENDAT2P2_GetStatus(endat2p2_dev_t *dev)
{
    return dev->base->STATUSREGISTER;
}

void ENDAT2P2_CleanStatus(endat2p2_dev_t *dev)
{
    dev->base->STATUSREGISTER = 0xFFFFFFFF;
}

void ENDAT2P2_SetInterruptMask(endat2p2_dev_t *dev, uint32_t mask)
{
    dev->base->INTERRUPTMASKREGISTER = mask;
}

uint64_t ENDAT2P2_GetRecvReg1(endat2p2_dev_t *dev)
{
    return (uint64_t) (dev->base->RECEIVEREGISTER1_2) << 32 |
          (dev->base->RECEIVEREGISTER1_1);
}

uint32_t ENDAT2P2_GetRecvReg2(endat2p2_dev_t *dev)
{
    return dev->base->RECEIVEREGISTER2;
}

uint32_t ENDAT2P2_GetRecvReg3(endat2p2_dev_t *dev)
{
    return dev->base->RECEIVEREGISTER3;
}

uint32_t ENDAT2P2_GetAddInfo1(endat2p2_dev_t *dev)
{
    return  dev->base->RECEIVEREGISTER3 & ENDAT2P2_ADDINFO_MASK;
}

uint32_t ENDAT2P2_GetAddInfo2(endat2p2_dev_t *dev)
{
    return  dev->base->RECEIVEREGISTER2 & ENDAT2P2_ADDINFO_MASK;
}

endat2p2_position_t ENDAT2P2_RecvPosition(endat2p2_dev_t *dev)
{
    uint64_t pos;
    endat2p2_position_t data;

    pos = ENDAT2P2_GetRecvReg1(dev);
    pos = pos & (((uint64_t) 1 << dev->pos_res) - 1);
    data.revolution = (pos & (((uint64_t) 1 << dev->pos_res) - 1)) >>
                        dev->single_turn_res;
    data.position = pos & (((uint64_t) 1 << dev->single_turn_res) - 1);

    return data;
}

endat2p2_position_addinfo_t ENDAT2P2_RecvPositionAddInfo(endat2p2_dev_t *dev)
{
    uint64_t pos;
    endat2p2_position_addinfo_t data;

    pos = ENDAT2P2_GetRecvReg1(dev);
    pos = pos & (((uint64_t) 1 << dev->pos_res) - 1);
    data.revolution = (pos & (((uint64_t) 1 << dev->pos_res) - 1)) >>
            dev->single_turn_res;
    data.position = pos & (((uint64_t) 1 << dev->single_turn_res) - 1);

    data.addinfo2 = ENDAT2P2_GetAddInfo2(dev);
    data.addinfo1 = ENDAT2P2_GetAddInfo1(dev);

    return data;
}

endat2p2_addr_param_t ENDAT2P2_RecvAddrParam(endat2p2_dev_t *dev)
{
    uint64_t recvd1;
    endat2p2_addr_param_t data;

    recvd1 = ENDAT2P2_GetRecvReg1(dev);
    data.param = recvd1 & ((1 << ENDAT_NUM_BITS_PARAMETER) - 1);
    data.address = (recvd1 >> ENDAT_NUM_BITS_PARAMETER) &
                    ((1 << ENDAT_NUM_BITS_ADDRESS) - 1);

    return data;
}

int ENDAT2P2_RecvData(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                      endat2p2_recv_data_t *data)
{
    data->status = ENDAT2P2_GetStatus(dev);
    ENDAT2P2_CleanStatus(dev);

    switch(cmd)
    {
        case ENDAT2P2_CMD_SELECT_MEM_AREA:
        case ENDAT2P2_CMD_RECEIVE_PARAMETERS:
        case ENDAT2P2_CMD_SEND_PARAMETERS:
        case ENDAT2P2_CMD_RECEIVE_RESET:
        case ENDAT2P2_CMD_RECEIVE_TEST_COMMAND:
        case ENDAT2P2_CMD_RECEIVE_COMMUNICATION_CMD:
            data->addr_param = ENDAT2P2_RecvAddrParam(dev);
            break;

        case ENDAT2P2_CMD_SEND_POSITION_VALUE:
            data->position = ENDAT2P2_RecvPosition(dev);
            break;

        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO:
        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM:
        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_PARAM:
        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEND_PARAM:
        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_ERR_RST:
        case ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_TESTCMD:
            data->position_addinfo = ENDAT2P2_RecvPositionAddInfo(dev);
            break;

        default:
            return -1;
    }

    return 0;
}

/*
 * XXX: check 2.2 command case with 2.2 capability in encoder, can live w/o as endat_get_command
 * will dev and it is assumed that this function will be called either after endat_get_command
 * or by diagnostic initialization code where it is only 2.1 commands used
 */
void ENDAT2P2_CMDBuild(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                       uint8_t mrs_or_addr, uint16_t param)
{
    uint32_t data = ENDAT2P2_SENDREGISTER_MODE_COMMAND(cmd) |
                    ENDAT2P2_SENDREGISTER_DATA_2_SENT(mrs_or_addr) |
                    ENDAT2P2_SENDREGISTER_DATA_1_SENT(param);

    dev->base->SENDREGISTER = data;
}

void ENDAT2P2_CMDSend(endat2p2_dev_t *dev)
{
    dev->base->SOFTWARESTROBE = 0x1;
}

void ENDAT2P2_CMDWait(endat2p2_dev_t *dev)
{
    while (! (dev->base->STATUSREGISTER &
              ENDAT2P2_STATUSREGISTER_READY_FOR_STROBE_MASK))
        ;
}

void ENDAT2P2_CMDProcess(endat2p2_dev_t *dev, endat2p2_mode_cmd_t cmd,
                         uint8_t msr_or_addr, uint16_t param)
{
    ENDAT2P2_CMDBuild(dev, cmd, msr_or_addr, param);
    ENDAT2P2_CMDWait(dev);
    ENDAT2P2_CleanStatus(dev);
    ENDAT2P2_CMDSend(dev);
    ENDAT2P2_CMDWait(dev);
}

void ENDAT2P2_EncoderRest(endat2p2_dev_t *dev)
{
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_RECEIVE_RESET, 0, 0);
}

void ENDAT2P2_SetParam(endat2p2_dev_t *dev, uint8_t page,
                       uint8_t addr, uint16_t data)
{
    /* select memory area */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SELECT_MEM_AREA, page, 0);

    /* receive data of address */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_RECEIVE_PARAMETERS, addr, data);
}

int ENDAT2P2_GetParam(endat2p2_dev_t *dev, uint8_t page, uint8_t addr)
{
    endat2p2_addr_param_t data;

    /* select memory area encoder manufacturer page */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SELECT_MEM_AREA, page, 0);

    /* send parameter for address */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_PARAMETERS, addr, 0);

    data = ENDAT2P2_RecvAddrParam(dev);

    return data.param;
}

int ENDAT2P2_GetParamWithPos(endat2p2_dev_t *dev, uint8_t page, uint8_t addr)
{
    int data;

    /* Select Memory Area */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        page, 0);

    /* ACK MRS Code */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        MRS_CODE_ADDITIONAL_INFO1_ACK_MRS_CODE, 0);

    /* Select Reg */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEND_PARAM,
                        addr, 0);

    /* ACK MEM LSB */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        MRS_CODE_ADDITIONAL_INFO1_ACK_MEM_LSB, 0);

    /* Read LSB */
    while (ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_BUSY_MASK)
    {
        ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    }
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_MEM_DATA_MASK;

    /* ACK MEM MSB */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        MRS_CODE_ADDITIONAL_INFO1_ACK_MEM_MSB, 0);

    /* Read MSB */
    while (ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_BUSY_MASK)
    {
        ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    }
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data |= ((ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_MEM_DATA_MASK) << 8);

    return data;
}

void ENDAT2P2_SetParamWithPos(endat2p2_dev_t *dev,
                              uint8_t page, uint8_t addr, uint16_t data)
{
    /* Select Memory Area */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        page, 0);

    /* ACK MRS Code */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        MRS_CODE_ADDITIONAL_INFO1_ACK_MRS_CODE, 0);

    /* Select Reg */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_PARAM,
                        addr, data);

    /* Send out */
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
}

void ENDAT2P2_EncoderRestWithPos(endat2p2_dev_t *dev)
{
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_RECV_ERR_RST, 0, 0);
}

int ENDAT2P2_GetPosRes(endat2p2_dev_t *dev)
{
    int param;

    param = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE0,
                              ENDAT2P2_MEM_WORD_13);

    return param &= (1 << ENDAT_NUM_BITS_VALID_PAGE0_WORD13) - 1;
}

int ENDAT2P2_GetType(endat2p2_dev_t *dev)
{
    int param;

    param = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE0,
                              ENDAT2P2_MEM_WORD_14);

    return param >> 12;
}

int ENDAT2P2_GetMultiTurnRes(endat2p2_dev_t *dev)
{
    int param;

    param = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_1);

    return param &= (1 << ENDAT_NUM_BITS_VALID_PAGE1_WORD1) - 1;
}

int ENDAT2P2_GetStep(endat2p2_dev_t *dev)
{
    int param;

    param = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_4);

    param |= ENDAT2P2_GetParam(dev,
                               MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                               ENDAT2P2_MEM_WORD_5) << 16;

    return param;
}

void ENDAT2P2_GetID(endat2p2_dev_t *dev)
{
    uint32_t word0, word1, word2;

    word0 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_8);

    word1 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_9);

    word2 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_10);

    dev->id_binary = word1 | word2 << 16;

    /* swap the two ascii's so that printing as string will give what is required */
    dev->id_ascii = ((word0 & 0xFF) << 8) | ((word0 & 0xFF00) >> 8);
}

void ENDAT2P2_GetSN(endat2p2_dev_t *dev)
{
    uint32_t word0, word1, word2;

    word0 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_11);

    word1 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_12);

    word2 = ENDAT2P2_GetParam(dev,
                              MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE1,
                              ENDAT2P2_MEM_WORD_13);

    dev->sn_ascii_lsb = word0 & 0xFF;
    dev->sn_binary = ((word0 & 0xFF00) >> 8) | (word1 << 8) | ((
                          word2 & 0xFF) << 24);
    dev->sn_ascii_msb = (word2 & 0xFF00) >> 8;
}

void ENDAT2P2_GetCommandSet(endat2p2_dev_t *dev)
{
    int word;

    word = ENDAT2P2_GetParam(dev,
                             MRS_CODE_PARAM_ENCODER_MANUFACTURER_PAGE2,
                             ENDAT2P2_MEM_WORD_5);

    dev->cmd_set_2_2 = (word & 0x1) && !(word & 0x2);
    dev->has_safety = (word & 0x4) && !(word & 0x8);
}

void ENDAT2P2_GetStatusAddInfo(endat2p2_dev_t *dev)
{
    int word;

    word = ENDAT2P2_GetParamWithPos(dev,
                             MRS_CODE_PARAM_ENCODER_MFG_ENDAT2P2_2,
                             ENDAT2P2_MEM_WORD_0);

    dev->status_addinfo1 = word;

    word = ENDAT2P2_GetParamWithPos(dev,
                             MRS_CODE_PARAM_ENCODER_MFG_ENDAT2P2_2,
                             ENDAT2P2_MEM_WORD_1);

    dev->status_addinfo2 = word;
}

int ENDAT2P2_GetEncoderInfo(endat2p2_dev_t *dev)
{
    dev->pos_res = ENDAT2P2_GetPosRes(dev);
    dev->multi_turn_res = ENDAT2P2_GetMultiTurnRes(dev);
    if (dev->multi_turn_res == 0)
    {
        dev->single_turn_res = dev->pos_res;
    }
    else
    {
        dev->multi_turn_res = NumTo2N(dev->multi_turn_res);
        dev->single_turn_res = dev->pos_res - dev->multi_turn_res;
    }

    dev->step = ENDAT2P2_GetStep(dev);

    dev->type = ENDAT2P2_GetType(dev);

    ENDAT2P2_GetID(dev);

    ENDAT2P2_GetSN(dev);

    ENDAT2P2_GetCommandSet(dev);

    return 0;
}

int ENDAT2P2_GetEncoderError(endat2p2_dev_t *dev)
{
    int error;

    error = ENDAT2P2_GetParam(dev, MRS_CODE_OPERATING_STATUS,
                              ENDAT2P2_MEM_WORD_0);

    return error;
}

/* It can only be called When F1/F2 bit = 1 */
void ENDAT2P2_ClearEncoderError(endat2p2_dev_t *dev)
{
    ENDAT2P2_SetParam(dev, MRS_CODE_OPERATING_STATUS,
                      ENDAT2P2_MEM_WORD_1, 0);
    ENDAT2P2_EncoderRest(dev);
}

int ENDAT2P2_GetEncoderWarning(endat2p2_dev_t *dev)
{
    int warn;

    warn = ENDAT2P2_GetParam(dev, MRS_CODE_OPERATING_STATUS,
                             ENDAT2P2_MEM_WORD_1);

    return warn;
}

/* It can only be called When RM bit = 1 */
void ENDAT2P2_ClearEncoderWarning(endat2p2_dev_t *dev)
{
    ENDAT2P2_SetParam(dev, MRS_CODE_OPERATING_STATUS,
                      ENDAT2P2_MEM_WORD_1, 0);
    ENDAT2P2_EncoderRest(dev);
}

int ENDAT2P2_GetEncoderErrorWithPos(endat2p2_dev_t *dev)
{
    int error;

    error = ENDAT2P2_GetParamWithPos(dev, MRS_CODE_OPERATING_STATUS,
                                     ENDAT2P2_MEM_WORD_0);

    return error;
}

/* It can only be called When F1/F2 bit = 1 */
void ENDAT2P2_ClearEncoderErrorWithPos(endat2p2_dev_t *dev)
{
    ENDAT2P2_SetParamWithPos(dev, MRS_CODE_OPERATING_STATUS,
                             ENDAT2P2_MEM_WORD_1, 0);
    ENDAT2P2_EncoderRestWithPos(dev);
}

int ENDAT2P2_GetEncoderWarningWithPos(endat2p2_dev_t *dev)
{
    int warn;

    warn = ENDAT2P2_GetParamWithPos(dev, MRS_CODE_OPERATING_STATUS,
                                    ENDAT2P2_MEM_WORD_1);

    return warn;
}

/* It can only be called When RM bit = 1 */
void ENDAT2P2_ClearEncoderWarningWithPos(endat2p2_dev_t *dev)
{
    ENDAT2P2_SetParamWithPos(dev, MRS_CODE_OPERATING_STATUS,
                             ENDAT2P2_MEM_WORD_1, 0);
    ENDAT2P2_EncoderRestWithPos(dev);
}

int ENDAT2P2_InitEncoder(endat2p2_dev_t *dev)
{
    ENDAT2P2_EncoderRest(dev);
    ENDAT2P2_DelayUs(50 * 1000);

    ENDAT2P2_ClearEncoderError(dev);
    ENDAT2P2_DelayUs(50 * 1000);

    ENDAT2P2_ClearEncoderWarning(dev);
    ENDAT2P2_DelayUs(50 * 1000);

    ENDAT2P2_GetEncoderInfo(dev);

    ENDAT2P2_SetDataWordLength(dev, dev->pos_res);

    if(dev->cmd_set_2_2)
    {
         ENDAT2P2_GetStatusAddInfo(dev);
    }

    return 0;
}

void ENDAT2P2_AddInfoSelect(endat2p2_dev_t *dev, mrs_mode_t mrs)
{
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO_SEL_MEM,
                        mrs, 0);
}

void ENDAT2P2_AddInfo1Stop(endat2p2_dev_t *dev)
{
    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_STOP_DATA);
}

void ENDAT2P2_AddInfo2Stop(endat2p2_dev_t *dev)
{
    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_STOP_DATA);
}

uint64_t ENDAT2P2_GetPosVal2(endat2p2_dev_t *dev)
{
    uint64_t data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD1_LSB);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_POS_MASK;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD2);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data |= ((uint64_t) ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_POS_MASK) << 16;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_POSVAL2_WORD3_MSB);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data |= ((uint64_t) ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_POS_MASK) << 32;

    return data;
}

double ENDAT2P2_GetTemperature1(endat2p2_dev_t *dev)
{
    uint32_t data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_TEMPERATURE1);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_TEMP_MASK;

    return data / 10.0 + 115.0;
}

double ENDAT2P2_GetTemperature2(endat2p2_dev_t *dev)
{
    uint32_t data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO1_TEMPERATURE2);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo1(dev) & ENDAT2P2_ADDINFO_TEMP_MASK;

    return data / 10.0 + 115.0;
}

uint64_t ENDAT2P2_GetAsyncPosVal2(endat2p2_dev_t *dev)
{
    uint64_t data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD1_LSB);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo2(dev) & ENDAT2P2_ADDINFO_POS_MASK;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD2);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data |= ((uint64_t) ENDAT2P2_GetAddInfo2(dev) & ENDAT2P2_ADDINFO_POS_MASK) << 16;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_ASYNCPOSVAL2_WORD3_MSB);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data |= ((uint64_t) ENDAT2P2_GetAddInfo2(dev) & ENDAT2P2_ADDINFO_POS_MASK) << 32;

    return data;
}

int ENDAT2P2_GetOPSERRSRC(endat2p2_dev_t *dev)
{
    int data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_OPSTATUS_ERRSOURCE);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo2(dev) & 0xFFFF;

    return data;
}

int ENDAT2P2_GetTimeStamp(endat2p2_dev_t *dev)
{
    int data;

    ENDAT2P2_AddInfoSelect(dev, MRS_CODE_ADDITIONAL_INFO2_TIMESTAMP);
    ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSVAL_WITH_ADDINFO, 0, 0);
    data = ENDAT2P2_GetAddInfo2(dev) & 0xFFFF;

    return data;
}

/* Master setting */
void ENDAT2P2_SetHWStrobe(endat2p2_dev_t *dev, bool enable)
{
    uint32_t data;
    uint32_t value;

    if (enable)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_HW_STROBE_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_HW_STROBE(value);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetDU(endat2p2_dev_t *dev, bool on)
{
    uint32_t data;
    uint32_t value;

    if (on)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_DU_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_DU(value);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetDT(endat2p2_dev_t *dev, bool on)
{
    uint32_t data;
    uint32_t value;

    if (on)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_DT_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_DT(value);
    dev->base->CONFIGREGISTER1 = data;
}

int ENDAT2P2_SetFTCLOCK(endat2p2_dev_t *dev, uint32_t clock)
{
    uint32_t data, value;

    switch (clock)
    {
        case ENDAT2P2_CLK_16M:
            if(dev->fsys == ENDAT2P2_CLK_100M)
            {
                value = 1;
            }
            else
            {
                return -1;
            }
            break;
        case ENDAT2P2_CLK_8M:
            if(dev->fsys == ENDAT2P2_CLK_48M)
            {
                value = 1;
            }
            else if(dev->fsys == ENDAT2P2_CLK_50M)
            {
                value = 1;
            }
            else if(dev->fsys == ENDAT2P2_CLK_64M)
            {
                value = 4;
            }
            else {
                return -1;
            }
            break;
        case ENDAT2P2_CLK_4M:
            if(dev->fsys == ENDAT2P2_CLK_32M)
            {
                value = 4;
            }
            else if(dev->fsys == ENDAT2P2_CLK_48M)
            {
                value = 6;
            }
            else if(dev->fsys == ENDAT2P2_CLK_64M)
            {
                value = 8;
            }
            else
            {
                return -1;
            }
            break;
        case ENDAT2P2_CLK_2M:
            value = 0xc;
            break;
        case ENDAT2P2_CLK_1M:
            value = 0xD;
            break;
        case ENDAT2P2_CLK_200K:
            value = 0xE;
            break;
        case ENDAT2P2_CLK_100K:
            value = 0xF;
            break;
        default:
            return -1;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_fTCLK_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_fTCLK(value);
    dev->base->CONFIGREGISTER1 = data;

    dev->ftclk = clock;

    return 0;
}

void ENDAT2P2_SetDataWordLength(endat2p2_dev_t *dev, int length)
{
    uint32_t data;

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_DATA_WORD_LENGTH_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_DATA_WORD_LENGTH(length);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetResetWindow(endat2p2_dev_t *dev, bool reset)
{
    uint32_t data;
    uint32_t value;

    if (reset)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_RESET_WINDOW_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_RESET_WINDOW(value);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetAutoReset(endat2p2_dev_t *dev, bool enable)
{
    uint32_t data;
    uint32_t value;

    if (enable)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_AUTOM_RESET_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_AUTOM_RESET(value);
    dev->base->CONFIGREGISTER1 = data;
}

uint32_t ENDAT2P2_GetCablePropagationTime(endat2p2_dev_t *dev)
{
    uint32_t data;

    data = dev->base->CONFIGREGISTER1;
    data = (data & ENDAT2P2_CONFIGREGISTER1_CABLE_PROPAGATION_TIME_MASK) >>
            ENDAT2P2_CONFIGREGISTER1_CABLE_PROPAGATION_TIME_SHIFT;
   return data;
}

void ENDAT2P2_SetCablePropagationTime(endat2p2_dev_t *dev, uint32_t time)
{
    uint32_t data;

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_CABLE_PROPAGATION_TIME_MASK)) |
            ENDAT2P2_CONFIGREGISTER1_CABLE_PROPAGATION_TIME(time);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetDelayCompensation(endat2p2_dev_t *dev, bool enable)
{
    uint32_t data;
    uint32_t value;

    if (enable)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data & (~ ENDAT2P2_CONFIGREGISTER1_DELAY_COMPENSATION_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_DELAY_COMPENSATION(value);
    dev->base->CONFIGREGISTER1 = data;
}

uint32_t ENDAT2P2_CalculatePropagationTime(endat2p2_dev_t *dev, int count)
{
    uint32_t status, sum = 0;
    int cnt;

    if (count < 1)
        count = 5;
    cnt = count;

    while (cnt)
    {
        ENDAT2P2_CleanStatus(dev);
        ENDAT2P2_SetDelayCompensation(dev, false);
        ENDAT2P2_SetCablePropagationTime(dev, 0);
        ENDAT2P2_SetDelayCompensation(dev, true);

        ENDAT2P2_CMDProcess(dev, ENDAT2P2_CMD_SEND_POSITION_VALUE, 0, 0);
        status = ENDAT2P2_GetStatus(dev);
        if (status & ENDAT2P2_STATUSREGISTER_PROPAGATION_TIME_MEASUREMENT_MASK)
        {
            sum += ENDAT2P2_GetCablePropagationTime(dev);
            cnt--;
        }
    }

    return sum / count;
}

void ENDAT2P2_ConfigSYSClock(endat2p2_dev_t *dev, uint32_t sysclock)
{
    uint32_t value, data;

    switch(sysclock)
    {
        case ENDAT2P2_CLK_64M:
            value = 0;
            break;
        case ENDAT2P2_CLK_48M:
            value = 0x2;
            break;
        case ENDAT2P2_CLK_32M:
            value = 0x4;
            break;
        case ENDAT2P2_CLK_50M:
            value = 0x5;
            break;
        case ENDAT2P2_CLK_100M:
            value = 0x6;
            break;
        default:
            value = 0;
    }

    data = dev->base->CONFIGREGISTER1;
    data = (data  & (~ ENDAT2P2_CONFIGREGISTER1_fSYS_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_fSYS(value);

    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_ICReset(endat2p2_dev_t *dev)
{
    dev->base->CONFIGREGISTER1 =
                ENDAT2P2_CONFIGREGISTER1_IC_RESET(1);
}

void ENDAT2P2_SetEnDatMode(endat2p2_dev_t *dev)
{
    uint32_t data;

    /* EnDat mode */
    data = dev->base->CONFIGREGISTER1;
    data = (data  & (~ ENDAT2P2_CONFIGREGISTER1_EnDAT_SSI_SET_MASK)) |
           ENDAT2P2_CONFIGREGISTER1_EnDAT_SSI_SET(ENDAT_MODE);
    dev->base->CONFIGREGISTER1 = data;
}

void ENDAT2P2_SetSamplingRate(endat2p2_dev_t *dev, int us)
{
    int value, ms_flag;
    uint32_t data;

    if(us < 256)
    {
        value = us / 2;
        ms_flag = 0;
    }
    else
    {
        us = us / 100;
        value = us / 2;
        ms_flag = (1 << 7);
    }

    if (value > 0x7f)
        value = 0x7f;

    value |= ms_flag;

    data = dev->base->CONFIGREGISTER2;
    data = (data  & (~ ENDAT2P2_CONFIGREGISTER2_SAMPLING_RATE_TIMER_MASK)) |
            ENDAT2P2_CONFIGREGISTER2_SAMPLING_RATE_TIMER(value);
    dev->base->CONFIGREGISTER2 = data;
}

void ENDAT2P2_SetWatchdogTimer(endat2p2_dev_t *dev, int us)
{
    int value, ms_flag;
    uint32_t data;

    if(us < 256)
    {
        value = us / 2;
        ms_flag = 0;
    }
    else
    {
        us = us / 100;
        value = us / 2;
        ms_flag = 0x80;
    }

    if (value > 0x7f)
        value = 0x7f;

    value |= ms_flag;

    data = dev->base->CONFIGREGISTER2;
    data = (data  & (~ ENDAT2P2_CONFIGREGISTER2_WATCHDOG_MASK)) |
            ENDAT2P2_CONFIGREGISTER2_WATCHDOG(value);
    dev->base->CONFIGREGISTER2 = data;
}

void ENDAT2P2_SetRecoveryTimer(endat2p2_dev_t *dev, int us)
{
    uint32_t data;

    data = dev->base->CONFIGREGISTER2;
    data = (data  & (~ ENDAT2P2_CONFIGREGISTER2_RECOVERY_TIME_III_TST_MASK)) |
            ENDAT2P2_CONFIGREGISTER2_RECOVERY_TIME_III_TST(us);
    dev->base->CONFIGREGISTER2 = data;
}

void ENDAT2P2_EnableDelayCompensation(endat2p2_dev_t *dev)
{
    uint32_t propagation;

    propagation = ENDAT2P2_CalculatePropagationTime(dev, 5);

    ENDAT2P2_SetCablePropagationTime(dev, propagation);
    ENDAT2P2_SetDelayCompensation(dev, true);
}

endat2p2_dev_t *ENDAT2P2_InitMaster(ENDAT2P2_Type *base, uint32_t fsys)
{
    endat2p2_dev_t *dev;

    dev = ENDAT2P2_GetDev(base);
    if(!dev)
        return NULL;

    dev->base = base;
    dev->fsys = fsys;
    dev->ftclk = ENDAT2P2_CLK_200K;

    ENDAT2P2_ICReset(dev);
    ENDAT2P2_DelayUs(800 * 1000);
    ENDAT2P2_SetEnDatMode(dev);
    ENDAT2P2_SetAutoReset(dev, 1);
    ENDAT2P2_CleanStatus(dev);

    ENDAT2P2_ConfigSYSClock(dev, fsys);
    ENDAT2P2_SetFTCLOCK(dev, ENDAT2P2_CLK_200K);

    return dev;
}
