/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_biss.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.biss"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of BiSS peripheral base address. */
static BISS_Type *const s_bissBases[] = BISS_BASE_PTRS;

static biss_master_t MasterList[BISS_MASTER_COUNT];

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint8_t BISS_GetInstance(BISS_Type *base)
{
    uint8_t instance;

    for (instance = 0; instance < ARRAY_SIZE(s_bissBases); instance++)
    {
        if (s_bissBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_bissBases));

    return instance;
}

biss_master_t *BISS_GetMaster(BISS_Type *base)
{
    int idx = BISS_GetInstance(base);

    return &MasterList[idx];
}


int BISS_CalculateMADiv(biss_master_t *master,
                        uint32_t srcClk_Hz, uint32_t MAFreq_Hz)
{
    uint32_t baseFreq_Hz = srcClk_Hz / 2;

    if(MAFreq_Hz < BISS_MIN_MA_FREQ || MAFreq_Hz > BISS_MAX_SYS_CLK_FREQ) {
        return -kStatus_OutOfRange;
    }

    /* Check the max MA frequence.*/
    if (MAFreq_Hz > baseFreq_Hz)
    {
        return -kStatus_InvalidArgument;
    }

    if (MAFreq_Hz >= (baseFreq_Hz / 17))
    {
        return (baseFreq_Hz / MAFreq_Hz) - 1;
    }
    else if (MAFreq_Hz <= (baseFreq_Hz / 20))
    {
        return ((baseFreq_Hz / MAFreq_Hz) / 10) + 15;
    }
    else
    {
        return -kStatus_InvalidArgument;
    }
}

int BISS_CalculateAGSDiv(biss_master_t *master,
                         uint32_t srcClk_Hz, uint32_t AGSfre_Hz)
{
    /* Check the min MA frequence. */
    if (AGSfre_Hz >= (srcClk_Hz / 20 / (0x7b + 1)))
    {
       return (srcClk_Hz / AGSfre_Hz / 20 ) - 1;
    }
    else if (AGSfre_Hz >= (srcClk_Hz / 625 / (0xff - 127) ))
    {
        return (srcClk_Hz / AGSfre_Hz / 625 ) + 127;
    }
    else
       return BISS_AGS_MIN;
}

void BISS_SetFREQS(biss_master_t *master, uint8_t MADiv)
{
    /* The frequence of MA must bigger than the min of MA frequence */
    master->ctrlcomm2 = (master->ctrlcomm2 & (~BISS_CTRLCOMM2_FREQS_MASK)) |
                        BISS_CTRLCOMM2_FREQS(MADiv);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetFREQAGS(biss_master_t *master, uint8_t AGSDiv)
{
    master->base->MACONFIG = (master->base->MACONFIG &
                              (~BISS_MACONFIG_FREQAGS_MASK)) |
                             BISS_MACONFIG_FREQAGS(AGSDiv);
}

void BISS_SetFREQR(biss_master_t *master, uint8_t FREQRDiv)
{
    if(master->protType == PROTOCOL_BISS_C)
        FREQRDiv = 0x05;

    /* The frequence of MA must bigger than the min of MA frequence */
    master->ctrlcomm2 = (master->ctrlcomm2 & (~BISS_CTRLCOMM2_FREQR_MASK)) |
                        BISS_CTRLCOMM2_FREQR(FREQRDiv);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetNOCRC(biss_master_t *master, bool NoCRC)
{
    uint32_t value;

    if (NoCRC)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    master->ctrlcomm2 = (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_NOCRC_MASK)) |
                        BISS_CTRLCOMM2_NOCRC(value);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetSingleRAMBank(biss_master_t *master, bool SingleBank)
{
    uint32_t value;

    if (SingleBank)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    master->ctrlcomm2 =
                (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_SINGLEBANK_MASK)) |
                BISS_CTRLCOMM2_SINGLEBANK(value);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetProtocol(biss_master_t *master, biss_prot_type_t protType)
{
    master->protType = protType;
    master->ctrlcomm2 =
                (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_REGVERS_MASK)) |
                BISS_CTRLCOMM2_REGVERS(protType);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetHoldCDM(biss_master_t *master, bool holdcdm)
{
    uint32_t value;

    if (holdcdm)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    master->ctrlcomm2 =
                (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_HOLDCDM_MASK)) |
                BISS_CTRLCOMM2_HOLDCDM(value);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetChannel(biss_master_t *master, int channel)
{
    master->ctrlcomm2 = (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_CHSEL_MASK)) |
                        BISS_CTRLCOMM2_CHSEL(channel);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetMOBusy(biss_master_t *master, uint8_t busy)
{
    master->base->MACONFIG = (master->base->MACONFIG &
                              (~BISS_MACONFIG_MO_BUSY_MASK)) |
                             BISS_MACONFIG_MO_BUSY(busy);
}

void BISS_SetENMO(biss_master_t *master, bool enmo)
{
    uint32_t value;

    if (enmo)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    master->ctrlcomm2 = (master->ctrlcomm2 & ~(BISS_CTRLCOMM2_EN_MO_MASK)) |
                        BISS_CTRLCOMM2_EN_MO(value);

    master->base->CTRLCOMM2 = master->ctrlcomm2;
}

void BISS_SetHoldBank(biss_master_t *master, bool holdbank)
{
    uint32_t value;

    if (holdbank)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    master->dacq = (master->dacq & (~BISS_DACQ_HOLDBANK_MASK)) |
                    BISS_DACQ_HOLDBANK(value);
}

void BISS_InitBissStatus(biss_master_t *master)
{
    master->base->DACQ = BISS_DACQ_INIT(BISS_INIT_PROC);
}

void BISS_AbortTrans(biss_master_t *master)
{
    master->base->DACQ = BISS_DACQ_BREAK(1);
}

uint32_t BISS_GetStatus(biss_master_t *master)
{
    return master->base->STATUS1;
}

void BISS_DisableAGS(biss_master_t *master)
{
    master->base->DACQ = master->base->DACQ & ~BISS_DACQ_AGS_MASK;
}

void BISS_EnableAGS(biss_master_t *master)
{
    master->base->DACQ = master->dacq | BISS_DACQ_AGS(BISS_AGS_ENABLE);
}

uint32_t BISS_GetStepVal(biss_master_t *master, uint8_t slvID)
{
    return master->slvList[slvID].step;
}

uint8_t BISS_GetLineDelay(biss_master_t *master)
{
    return master->lineDelay;
}

biss_trigger_mode_t BISS_GetTriggerMode(biss_master_t *master)
{
    return master->triggerMode;
}

/*!
 * Change trigger mode of SCData getting.
 * When the target trigger mode is BISS_AutoRepet and the existing FREQAGS is
 * BISS_AGS_INFINITE, this function will change FREQAGS(auto repeat frequence)
 * to the minimum(BISS_AGS_MIN).
 *
 * param base - BISS peripheral base address.
 * param triggerMode - target trigger mode.
 */
void BISS_ChangeTriggerMode(biss_master_t *master,
                            biss_trigger_mode_t triggerMode)
{
    if (BISS_INSTR_TRIGGER == triggerMode)
    {
        BISS_DisableAGS(master);
        return;
    }
    if (BISS_PIN_TRIGGER == triggerMode)
    {
        BISS_SetFREQAGS(master, BISS_AGS_INFINITE);
    }
    else if (BISS_TIMEOUT_TRIGGER == triggerMode)
    {
        BISS_SetFREQAGS(master, BISS_AGS_MIN);
    }
    else
    {
        BISS_SetFREQAGS(master, master->freqAGSDiv);
    }

    BISS_EnableAGS(master);
}

static void BISS_MasterInfoReset(biss_master_t *master)
{
    uint8_t index;

    /* The default value of MA output frequence is 1/2 of the input frequence of BISS */
    master->freqMADiv = BISS_FREQS_DEFAULT;
    /* The default value of auto get sensor data is BISS_AGS_INFINITE */
    master->freqAGSDiv = BISS_AGS_INFINITE;
    /* The default trigger mode is triggered by instruction */
    master->triggerMode = BISS_INSTR_TRIGGER;
    /* The default protocol is BISS-C */
    master->protType = PROTOCOL_BISS_C;

    master->ctrlcomm2 = 0;
    master->dacq = 0;
    master->slvCnt = 0;
    master->lineDelay = 0;
    master->maxProcTime = 0xFF;
    master->processTime = 0;

    for (index = 0; index < BISS_MAX_SLAVE_COUNT; index++)
    {
        master->slvList[index].stopBit = false;
        master->slvList[index].profile = 0;
        master->slvList[index].commEDS = 0;
        master->slvList[index].profileEDS = 0;
        master->slvList[index].crcPoly = 0;
        master->slvList[index].crcStart = 0;
        master->slvList[index].dataLen = 0;
        master->slvList[index].errWarLen = 2;
        master->slvList[index].mtLen = 0;
        master->slvList[index].stLen = 0;
        master->slvList[index].dataAlign = BISS_LeftAlign;
        master->slvList[index].mtAlign = BISS_RightAlign;
        master->slvList[index].stAlign = BISS_LeftAlign;
        master->slvList[index].step = 0;
    }
}

static status_t BISS_ChannelInit(biss_master_t *master)
{
    BISS_Type *base = master->base;
    /*
     * SLAVELOC1 is const averiable and the value of it must should be 1.
     * So it doesn't need to be reset.
     */

    /*
     * Clear CFGCH register.
     * 0x03 means the target channel is not used.
     */
    base->BISSINTDATACHCONFIG2 |= BISS_BISSINTDATACHCONFIG2_CFGCH1_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH2_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH3_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH4_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH5_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH6_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH7_MASK |
                                  BISS_BISSINTDATACHCONFIG2_CFGCH8_MASK;

    /* Set the 1st channel to the config protocol type. */
    base->BISSINTDATACHCONFIG2 =
                        (base->BISSINTDATACHCONFIG2 &
                        ~BISS_BISSINTDATACHCONFIG2_CFGCH1_MASK) |
                        BISS_BISSINTDATACHCONFIG2_CFGCH1(master->protType);

    return kStatus_Success;
}

/*!
 * Initialize the BISS module and internal state.
 * This function configures the BISS module with the input parameters.
 * User should call this function before any BISS operations.
 *
 * param base - BISS peripheral base address.
 * param config - BISS configure structure.
 * param srcClock_Hz - Source clock frequence.
 */
biss_master_t *BISS_MasterInit(BISS_Type *base, uint32_t srcClock_Hz,
                               uint32_t ma_Hz, uint32_t ags_Hz)
{
    biss_master_t *master = BISS_GetMaster(base);
    int ret;

    master->base = base;

    BISS_MasterInfoReset(master);

    /* Configurate the clock div for BISS device */
    ret = BISS_CalculateMADiv(master, srcClock_Hz, ma_Hz);
    if (ret < 0)
    {
        return NULL;
    }

    master->freqMADiv = (uint8_t) ret;
    BISS_SetFREQS(master, master->freqMADiv);
    BISS_SetFREQR(master, 0x05);

    /* Configurate the clock div for BISS device */
    ret = BISS_CalculateAGSDiv(master, srcClock_Hz, ags_Hz);
    if (ret < 0)
    {
        return NULL;
    }

    master->freqAGSDiv = (uint8_t) ret;
    BISS_SetFREQAGS(master, master->freqAGSDiv);

    /* Setup CRC check and BANK config */
    BISS_SetNOCRC(master, false);

    BISS_SetSingleRAMBank(master, false);

    BISS_SetProtocol(master, PROTOCOL_BISS_C);

    BISS_SetHoldCDM(master, true);

    BISS_SetChannel(master, 1);

    BISS_SetENMO(master, true);

    BISS_ChangeTriggerMode(master, BISS_INSTR_TRIGGER);

    BISS_ChannelInit(master);

    BISS_SetHoldBank(master, false);

    return master;
}

void BISS_InitBissSequence(biss_master_t *master)
{
    master->base->DACQ = BISS_DACQ_INIT(BISS_INIT_PROC);

    /* Check the INIT finished by checking EOT register */
    while (!(master->base->DACQ))
    {
        ;
    }

    /* Update the line delay */
    master->lineDelay = master->base->SCDATA1_LOW & BISS_LINEDELAY_MASK;
}

void BISS_InstrSend(biss_master_t *master, int instr, int ags)
{
    master->base->DACQ = master->dacq |
                         BISS_DACQ_INSTR(instr) |
                         BISS_DACQ_AGS(ags);
}

void BISS_InstrWait(biss_master_t *master)
{
    /* Wait until INSTR is reset */
    while(master->base->DACQ & BISS_DACQ_INSTR_MASK)
    {
        ;
    }
}

void BISS_InstrSendandWait(biss_master_t *master, int instr, int ags)
{
    BISS_InstrSend(master, instr, ags);

     /* Wait until INSTR is reset */
    BISS_InstrWait(master);
}

status_t BISS_CMDProcess(biss_master_t *master, uint8_t IDS, uint8_t cmd)
{
    BISS_Type *base = master->base;

    /* Set ctrl command configuration register for this command */
    base->CTRLCOMM2 = master->ctrlcomm2 |
                      BISS_CTRLCOMM2_CMD(cmd) |
                      BISS_CTRLCOMM2_CTS(BISS_CTRL_CMD);

    base->RDATA1 = IDS;

    BISS_InstrSend(master, BISS_INSTR_CTRL_FRAME, BISS_AGS_ENABLE);

    /* Wait until INSTR is reset */
    BISS_InstrWait(master);

    return kStatus_Success;
}

status_t BISS_ActivateAllSLV(biss_master_t *master)
{
    status_t status;

    status = BISS_CMDProcess(master, BISS_CMD_IDS_BOARDCAST,
                             BISS_CMD_BOARDCAST_ALL_DEACTIVATED);
    if (kStatus_Success != status)
    {
        return status;
    }

    status = BISS_CMDProcess(master, BISS_CMD_IDS_BOARDCAST,
                             BISS_CMD_BOARDCAST_CTRL_ACTIVATED);
    if (kStatus_Success != status)
    {
        return status;
    }

    return status;
}

/* Slave related functions */
static status_t BISS_Wait14CDM0(biss_master_t *master)
{
    BISS_Type *base = master->base;

    /* Send CDM = 1 to clear CDM counter */
    base->DACQ = master->dacq | BISS_DACQ_INSTR(1);

    BISS_InstrSendandWait(master, BISS_INSTR_CDM_1, BISS_AGS_DISABLE);

    /* Send CDM = 0 */
    BISS_InstrSend(master, BISS_INSTR_CDM_0, BISS_AGS_ENABLE);

    /* Waiting for CDM timeout */
    while (!(base->STATUS1 & BISS_STATUS1_CDMTIMEOUT_MASK))
    {
        ;
    }

    return kStatus_Success;
}

static void BISS_RDATAWrite(biss_master_t *master, uint8_t regNum, uint8_t *buf)
{
    volatile uint32_t *rdata = (volatile uint32_t *) &master->base->RDATA1;
    uint32_t data;
    int idx, num_blks = regNum / 4;
    int remaining_bytes = regNum % 4;

    for (idx = 0; idx < num_blks; idx++)
    {
        rdata[idx] = (uint32_t)buf[idx * 4 + 0] |
                     (buf[idx * 4 + 1] << 8U) |
                     (buf[idx * 4 + 2] << 16U) |
                     (buf[idx * 4 + 3] << 24U);
    }

    data = 0;
    for(idx = 0; idx < remaining_bytes; idx++)
    {
        data |= buf[num_blks * 4 + idx] << (idx * 8U);
    }

    rdata[num_blks] = data;
}

static void BISS_RDATARead(biss_master_t *master, uint8_t regNum, uint8_t *buf)
{
    volatile uint32_t *rdata = (volatile uint32_t *) &master->base->RDATA1;
    int idx;

    for (idx = 0; idx < regNum; idx++)
    {
        buf[idx] = (rdata[idx / 4] >> ((idx % 4) * 8)) & 0xFF;
    }
}

biss_slave_info_t *BISS_SLVGet(biss_master_t *master, uint8_t slvID)
{
    return &(master->slvList[slvID]);
}

/*
 * This function used for register writting.
 * Before this function call, you should check BISS master status.
 *
 * param base - BISS peripheral base address.
 * param slvID - The target slave's index in BISS chain.
 * param regAddr - The register address which want to write.
 * param regNum - The register access bytes count, and the max bytes count is 4.
 * param buffer - The value which want to write to the register.
 */
status_t BISS_SLVWriteRegister(biss_master_t *master, uint8_t slvID,
                               uint8_t regAddr, uint8_t regNum, uint8_t *buf)
{
    BISS_Type *base = master->base;

    BISS_RDATAWrite(master, regNum, buf);

    base->CTRLCOMM1 = BISS_CTRLCOMM1_REGADR(regAddr) |
                      BISS_CTRLCOMM1_WNR(BISS_REG_ACCESS_WRITE) |
                      BISS_CTRLCOMM1_REGNUM(regNum - 1);

    base->CTRLCOMM2 = master->ctrlcomm2 |
                       BISS_CTRLCOMM2_SLAVEID(slvID) |
                       BISS_CTRLCOMM2_CTS(BISS_REG_ACCESS);

    /* Set instr register to trigger this command */
    BISS_InstrSend(master, BISS_INSTR_CTRL_FRAME, BISS_AGS_ENABLE);

    /* Wait until INSTR is reset */
    BISS_InstrWait(master);

    /* Waiting for the command finished */
    if (!(base->STATUS1 & BISS_STATUS1_REGEND_MASK))
    {
        return kStatus_Fail;
    }

    return kStatus_Success;
}

status_t BISS_SLVReadRegister(biss_master_t *master, uint8_t slvID,
                              uint8_t regAddr, uint8_t regNum, uint8_t *buf)
{
    BISS_Type *base = master->base;

    if (!(base->STATUS1 & BISS_STATUS1_CDMTIMEOUT_MASK)) {
        BISS_Wait14CDM0(master);
    }

    base->CTRLCOMM1 = BISS_CTRLCOMM1_REGADR(regAddr) |
                      BISS_CTRLCOMM1_WNR(BISS_REG_ACCESS_READ) |
                      BISS_CTRLCOMM1_REGNUM(regNum - 1);

    base->CTRLCOMM2 = master->ctrlcomm2 |
                      BISS_CTRLCOMM2_SLAVEID(slvID) |
                      BISS_CTRLCOMM2_CTS(BISS_REG_ACCESS);

    /* Set instr register to trigger this command */
    BISS_InstrSend(master, BISS_INSTR_CTRL_FRAME, BISS_AGS_ENABLE);

    /* Wait until INSTR is reset */
    BISS_InstrWait(master);

    if (!(base->STATUS1 & BISS_STATUS1_REGEND_MASK))
    {
        return kStatus_Fail;
    }

    BISS_RDATARead(master, regNum, buf);

    return kStatus_Success;
}

static volatile uint32_t *BISS_SLVGetSCDReg(biss_master_t *master, int slvID)
{
    return  ((volatile uint32_t *)(&master->base->CONFIGSL1)) + (slvID);
}

void BISS_SLVSetSCDEN(biss_master_t *master, uint8_t slvID, bool enable)
{
    volatile uint32_t *dataChlCfg;
    uint32_t value;

    if (enable)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL1_ENSCD1_MASK)) |
                  BISS_CONFIGSL1_ENSCD1(value);
}

void BISS_SLVSetSCDLen(biss_master_t *master, uint8_t slvID, int SCDLen)
{
    volatile uint32_t *dataChlCfg;

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL_SCDLEN1_MASK)) |
                  BISS_CONFIGSL_SCDLEN1(SCDLen - 1);
}

void BISS_SLVSetCRCLen(biss_master_t *master, uint8_t slvID, int crcLen)
{
    volatile uint32_t *dataChlCfg;

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL1_SCRCPOLY1_MASK) &
                  (~BISS_CONFIGSL_SELCRCS1_MASK)) |
                  BISS_CONFIGSL_SELCRCS1(BISS_SEL_SCRCLEN) |
                  BISS_CONFIGSL1_SCRCPOLY1(crcLen);
}

void BISS_SLVSetCRCPoly(biss_master_t *master, uint8_t slvID, int crcPoly)
{
    volatile uint32_t *dataChlCfg;

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL1_SCRCPOLY1_MASK) &
                  (~BISS_CONFIGSL_SELCRCS1_MASK)) |
                  BISS_CONFIGSL_SELCRCS1(BISS_SEL_SCRCPOLY) |
                  BISS_CONFIGSL1_SCRCPOLY1(crcPoly);
}

void BISS_SLVSetCRCStart(biss_master_t *master, uint8_t slvID, uint32_t crcStart)
{
    volatile uint32_t *dataChlCfg;

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL1_SCRCSTART1_MASK)) |
                  BISS_CONFIGSL1_SCRCSTART1(crcStart);
}

void BISS_SLVSetSCD(biss_master_t *master, uint8_t slvID, int dataLen, int crcLen)
{
    BISS_SLVSetSCDLen(master, slvID, dataLen);
    BISS_SLVSetCRCLen(master, slvID, crcLen);
    BISS_SLVSetSCDEN(master, slvID, true);
}

void BISS_SLVSetLStop(biss_master_t *master, uint8_t slvID, bool enable)
{
    volatile uint32_t *dataChlCfg;
    uint32_t value;

    if (enable)
    {
        value = 1;
    }
    else
    {
        value = 0;
    }

    dataChlCfg = BISS_SLVGetSCDReg(master, slvID);

    *dataChlCfg = ((*dataChlCfg) &
                  (~BISS_CONFIGSL1_LSTOP1_MASK)) |
                  BISS_CONFIGSL1_LSTOP1(value);
}

void BISS_SLVSetDataType(biss_master_t *master, uint8_t slvID,
                         biss_data_type_t dataType)
{
    uint32_t data = master->base->BISSINTDATACHCONFIG2;
    uint32_t shift = slvID + BISS_BISSINTDATACHCONFIG2_ACTnSENS_SHIFT;

    data = (data & (~ (1U << shift))) | (dataType << shift);

    master->base->BISSINTDATACHCONFIG2 = data;
}

status_t BISS_SLVSelectBank(biss_master_t *master, uint8_t slvID, uint8_t bank)
{
    return BISS_SLVWriteRegister(master, slvID,
                                 BISS_DEV_BANK_SEL_ADDR,
                                 BISS_DEV_REG_LEN_1,
                                 &bank);
}

status_t BISS_SLVGetEDSBank(biss_master_t *master, uint8_t slvID, uint8_t* bank)
{
    /* Get the EDS bank ID, 0x00 means could not access the EDS by this slave */
    return BISS_SLVReadRegister(master, slvID,
                                BISS_DEV_EDS_BANK_NUM_ADDR,
                                BISS_DEV_REG_LEN_1,
                                bank);
}

status_t BISS_SLVGetProfile(biss_master_t *master,
                            uint8_t slvID, uint16_t *profile)
{
    *profile = 0;
    return BISS_SLVReadRegister(master, slvID,
                                  BISS_DEV_PROFILE_ADDR,
                                  BISS_DEV_PROFILE_LEN,
                                  (uint8_t *)profile);
}

status_t BISS_SLVGetSerialNum(biss_master_t *master,
                              uint8_t slvID, uint32_t *serialNum)
{
    return BISS_SLVReadRegister(master, slvID, BISS_DEV_SN_ADDR,
                                BISS_DEV_REG_LEN_1,
                                (uint8_t *)serialNum);
}

status_t BISS_SLVGetManufacturerID(biss_master_t *master,
                                   uint8_t slvID, uint16_t *mfrID)
{
    return BISS_SLVReadRegister(master, slvID,
                                BISS_DEV_MFR_ID_ADDR,
                                BISS_DEV_MFR_ID_LEN,
                                (uint8_t *)mfrID);
}

status_t BISS_SLVGetDeviceID(biss_master_t *master,
                             uint8_t slvID, uint8_t *devID)
{
    return BISS_SLVReadRegister(master, slvID,
                                BISS_DEV_ID_ADDR,
                                BISS_DEV_ID_LEN,
                                devID);
}

status_t BISS_SLVUpdateWithProfile(biss_master_t *master, uint8_t slvID)
{
    biss_slave_info_t *slv;

    slv = BISS_SLVGet(master, slvID);

    slv->stopBit = true;
    slv->dataAlign = BISS_RightAlign;
    slv->crcStart = 0;

    if (BISS_BP0_PROFILE_ID == BISS_BP0_PROFILE_ID_GET(slv->profile))
    {
        if (BISS_BP0_SENSOR == BISS_BP0_APL_TYPE_GET(slv->profile))
        {
           slv->dataType = BISS_DATA_SENSOR;
        }
        else
        {
            slv->dataType = BISS_DATA_ACTUATOR;
        }
       slv->dataLen = BISS_BP0_DATA_LEN_GET(slv->profile);
       slv->crcPoly = BISS_BP0_CRCPOLY;
    }
    else if (BISS_BP3_PROFILE_ID == BISS_BP3_PROFILE_ID_GET(slv->profile))
    {
       slv->dataLen = BISS_BP3_DATA_LEN_GET(slv->profile);
       slv->crcPoly = BISS_BP3_CRCPOLY;
    }
    else if (BISS_BP3S_PROFILE_ID == BISS_BP3S_PROFILE_ID_GET(slv->profile))
    {
       slv->dataLen = BISS_BP3S_DATA_LEN_GET(slv->profile);
       slv->crcPoly = BISS_BP3S_CRCPOLY;
    }

    return kStatus_Success;
}

/*!
 * Scan the common EDS information under this slave.
 *
 * para base - BISS peripheral base address.
 * para slvID - The slave ID which could access all slave EDS information in one device.
 */
status_t BISS_SLVUpdatewithCommonEDS(biss_master_t *master, uint8_t slvID)
{
    status_t status;
    uint8_t index;
    uint8_t slvCnt;
    uint8_t slvOffset;
    uint8_t startSlvID;
    uint8_t bcOffset;
    uint8_t bcSlvID;
    uint8_t maxProcTime;
    uint8_t processTime;
    uint8_t format;
    biss_slave_info_t *slv;

    slv = BISS_SLVGet(master, slvID);

    /* Switch the bank to common EDS bank. */
    status = BISS_SLVSelectBank(master, slvID, slv->commEDS);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = BISS_SLVReadRegister(master, slvID,
                                  BISS_EDS_TBUSY_MAX_ADDR,
                                  BISS_DEV_REG_LEN_1,
                                  &maxProcTime);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (master->maxProcTime <= maxProcTime)
    {
        master->maxProcTime = maxProcTime;
    }

    /* Get additional processing time SCD in clock */
    status = BISS_SLVReadRegister(master, slvID,
                                  BISS_EDS_BUSY_S_ADDR,
                                  BISS_DEV_REG_LEN_1,
                                  &processTime);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (master->processTime < processTime)
    {
        master->processTime = processTime;
    }

    /* Get the slave count in this device */
    status = BISS_SLVReadRegister(master, slvID,
                                  BISS_EDS_SL_NUM_ADDR,
                                  BISS_DEV_REG_LEN_1,
                                  &slvCnt);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Get this slave's offset in this device */
    status = BISS_SLVReadRegister(master, slvID,
                                  BISS_EDS_SL_OFF_ADDR,
                                  BISS_DEV_REG_LEN_1,
                                  &slvOffset);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (slvID < slvOffset)
    {
        return kStatus_Fail;
    }

    /* Calculate the first slave's ID in this device */
    startSlvID = slvID - slvOffset;

    status = BISS_SLVReadRegister(master, slvID,
                                  BISS_EDS_BC_OFFSET_ADDR,
                                  BISS_EDS_BC_OFFSET_LEN,
                                  &bcOffset);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Calculate the bus coupler's ID in this device */
    bcSlvID = (uint8_t)((bcOffset & BISS_BC_ENABLE_MASK) ? \
              (startSlvID + (bcOffset & BISS_BC_OFFSET_MASK)) : 0xFF);

    /* Loop for getting profile EDS Bank, data length, data format and CRC poly. */
    for (index = startSlvID; index < (startSlvID + slvCnt); index++)
    {
        slv = BISS_SLVGet(master, index);

        if(bcSlvID == index)
        {
            /* The bus coupler does not have data channel. */
            slv->role = BISS_BusCoupler;
            continue;
        }

        status = BISS_SLVReadRegister(master, slvID,
                                BISS_EDS_DLEN_CHAN_ADDR(index - startSlvID),
                                BISS_DEV_REG_LEN_1,
                                &(slv->dataLen));
        if (status != kStatus_Success)
        {
            return status;
        }

        status = BISS_SLVReadRegister(master, slvID,
                                BISS_EDS_FORMAT_CHAN_ADDR(index - startSlvID),
                                BISS_DEV_REG_LEN_1,
                                &format);
        if (status != kStatus_Success)
        {
            return status;
        }

        slv->dataType = (biss_data_type_t)BISS_EDS_FORMAT_GET_TYPE(format);
        slv->stopBit = (bool)BISS_EDS_FORMAT_GET_STOPBIT(format);
        slv->dataAlign = (biss_align_type_t)BISS_EDS_FORMAT_GET_ALIGN(format);

        status = BISS_SLVReadRegister(master, slvID,
                                BISS_EDS_CPOLY_CHAN_ADDR(index - startSlvID),
                                BISS_DEV_REG_LEN_1,
                                (uint8_t *)(&(slv->crcPoly)));
        if (status != kStatus_Success)
        {
            return status;
        }

        status = BISS_SLVReadRegister(master, slvID,
                                BISS_EDS_BANK_CHAN_ADDR(index - startSlvID),
                                BISS_DEV_REG_LEN_1,
                                &(slv->profileEDS));
        if (status != kStatus_Success)
        {
            return status;
        }
    }

    return status;
}

status_t BISS_SLVUpdatewithProfileEDS(biss_master_t *master, uint8_t slvID)
{
    status_t status;
    biss_slave_info_t *slv;
    uint8_t EDSSlvID;
    uint8_t encoderType;

    slv = BISS_SLVGet(master, slvID);
    EDSSlvID = slv->EDSSlvID;

    /* Switch the bank to profifle EDS bank */
    status = BISS_SLVSelectBank(master, EDSSlvID, slv->profileEDS);
    if (status != kStatus_Success)
    {
        return status;
    }

    status = BISS_SLVReadRegister(master, EDSSlvID,
                                  BISS_EDS_ENTYP_ADDR,
                                  BISS_DEV_REG_LEN_1,
                                  &encoderType);
    if (status != kStatus_Success)
    {
        return status;
    }

    if (BISS_SENSOR_ROTARY == encoderType)
    {
        slv->role = BISS_RotaryEncoder;
    }
    else
    {
        slv->role = BISS_LinearEncoder;
    }

    status = BISS_SLVReadRegister(master, EDSSlvID,
            BISS_EDS_MTLEN_ADDR, BISS_EDS_MTLEN_LEN,
            &(slv->mtLen));
    if (status != kStatus_Success)
    {
        return status;
    }

    slv->stLen = slv->dataLen - slv->mtLen - slv->errWarLen;

    slv->stMask = ((uint64_t)1 << slv->stLen) - 1;
    slv->mtMask = ((uint64_t)1 << slv->mtLen) - 1;

    status = BISS_SLVReadRegister(master, EDSSlvID,
                                  BISS_EDS_MTFMT_ADDR,
                                  BISS_EDS_MTFMT_LEN,
                                  &(slv->mtAlign));
    if (status != kStatus_Success)
    {
        return status;
    }

    status = BISS_SLVReadRegister(master, EDSSlvID,
                                  BISS_SPEC_CPOLY_ADDR,
                                  BISS_SPEC_CPOLY_LEN,
                                  (uint8_t *)(&(slv->crcPoly)));
    if (status != kStatus_Success)
    {
        return status;
    }

    status = BISS_SLVReadRegister(master, EDSSlvID,
                                  BISS_SPEC_CSTART_ADDR,
                                  BISS_SPEC_CSTART_LEN,
                                  (uint8_t *)(&(slv->crcStart)));
    if (status != kStatus_Success)
    {
        return status;
    }

    status = BISS_SLVReadRegister(master, EDSSlvID,
                                  BISS_EDS_SIPCNT_ADDR,
                                  BISS_EDS_SIPCNT_LEN,
                                  (uint8_t *)(&(slv->step)));

    return status;
}

status_t BISS_SLVDeactivate(biss_master_t *master, uint8_t slvID)
{
    return BISS_CMDProcess(master, (uint8_t)BISS_CMD_IDS_FRM_SLV(slvID),
                           BISS_CMD_ADDRESSED_DEACTIVATED);
}

status_t BISS_SLVActivate(biss_master_t *master, uint8_t slvID)
{
    return BISS_CMDProcess(master, (uint8_t)BISS_CMD_IDS_FRM_SLV(slvID),
                           BISS_CMD_ADDRESSED_ACTIVATED);
}

uint8_t BISS_SLVGetCnt(biss_master_t *master)
{
    BISS_Type *base = master->base;
    status_t status;
    uint8_t slvCnt;

    /* Send cmd to update IDL register */
    status = BISS_CMDProcess(master, BISS_CMD_IDS_BOARDCAST,
                             BISS_CMD_BOARDCAST_CTRL_ACTIVATED);
    if (kStatus_Success != status)
    {
        return 0;
    }

    /* Update the slave count in the biss chain */
    slvCnt = (base->STATUS2 & BISS_STATUS2_IDL_MASK) >>
              BISS_STATUS2_IDL_SHIFT;

    if (slvCnt > BISS_MAX_SLAVE_COUNT)
    {
        slvCnt = BISS_MAX_SLAVE_COUNT;
    }

    return slvCnt;
}

status_t BISS_SLVScan(biss_master_t *master)
{
    uint8_t slvID;
    status_t status;
    biss_slave_info_t *slv;

    master->slvCnt = BISS_SLVGetCnt(master);

    for (slvID = 0; slvID < master->slvCnt; slvID++)
    {
        slv = BISS_SLVGet(master, slvID);

        BISS_SLVGetEDSBank(master, slvID, &slv->commEDS);
        BISS_SLVGetProfile(master, slvID, &slv->profile);
        BISS_SLVGetDeviceID(master, slvID, slv->did);
        BISS_SLVGetManufacturerID(master, slvID, &slv->mid);
        BISS_SLVGetSerialNum(master, slvID, &slv->sn);

        /* If the EDS bank could not be access by this slave, continue to the next slave. */
        if (slv->profile)
        {
            status = BISS_SLVUpdateWithProfile(master, slvID);
            if (status != kStatus_Success)
            {
                return status;
            }
        }

        if(slv->commEDS)
        {
            status = BISS_SLVUpdatewithCommonEDS(master, slvID);
            if (status != kStatus_Success)
            {
                return status;
            }
        }

        if (slv->profileEDS)
        {
            status = BISS_SLVUpdatewithProfileEDS(master, slvID);
            if (status != kStatus_Success)
            {
                return status;
            }
        }
    }

    return kStatus_Success;
}

void BISS_SLVSetCRC(biss_master_t *master, uint8_t slvID,
                    uint32_t crcPoly, uint32_t crcStart)
{
    uint8_t crcLen;

    if (0x00 == crcPoly)
    {
        crcLen = 0x00;
    }
    else if (0xB == crcPoly)
    {
        crcLen = 0x03;
    }
    else if(0x13 == crcPoly)
    {
        crcLen = 0x04;
    }
    else if(0x25 == crcPoly)
    {
        crcLen = 0x05;
    }
    else if(0x43 == crcPoly)
    {
        crcLen = 0x06;
    }
    else if(0x89 == crcPoly)
    {
        crcLen = 0x07;
    }
    else if(0x12F == crcPoly)
    {
        crcLen = 0x08;
    }
    else if(0x190D9 == crcPoly)
    {
        crcLen = 0x10;
    }
    else
    {
        crcLen = 0xFF;
    }

    if (0xFF != crcLen)
    {
       BISS_SLVSetCRCLen(master, slvID, crcLen);
    }
    else
    {
       BISS_SLVSetCRCPoly(master, slvID, crcPoly);
    }

    BISS_SLVSetCRCStart(master, slvID, crcStart);
}

/*!
 * Setup slave SCD transfer channel by setting the registers in Master.
 *
 * param base - BISS peripheral base address.
 * IDS - The ID master to get which slave should be set up this time.
 */
void BISS_SLVSetup(biss_master_t *master, uint8_t slvID)
{
    biss_slave_info_t *slv;

    slv = BISS_SLVGet(master, slvID);

    BISS_SLVActivate(master, slvID);

    BISS_SLVSetDataType(master, slvID, slv->dataType);

    BISS_SLVSetSCD(master, slvID, slv->dataLen, slv->crcLen);

    if(slv->crcPoly)
        BISS_SLVSetCRC(master, slvID, slv->crcPoly, slv->crcStart);

    BISS_SLVSetLStop(master, slvID, slv->stopBit);
}

uint64_t BISS_SLVGetSCDRawData(biss_master_t *master, uint8_t slvID)
{
    volatile uint32_t *scdl = (&master->base->SCDATA1_LOW) + (slvID) * 2;
    volatile uint32_t *scdh = (&master->base->SCDATA1_HIGH) + (slvID) * 2;

    return (*scdl) | ((uint64_t)(*scdh) << 32);
}

status_t BISS_SLVCheckSVALID(biss_master_t *master, uint8_t slvID)
{
    return !(master->base->STATUS1 & BISS_STATUS1_SVALID_MASK(slvID));
}

void BISS_SLVResetSVALID(biss_master_t *master, uint8_t slvID)
{
    master->base->STATUS1 &= (~BISS_STATUS1_SVALID_MASK(slvID));
}

status_t BISS_StatusProcess(biss_master_t *master)
{
    BISS_Type *base = master->base;

    if ((base->STATUS1 & 0x70) == 0x70)
    {
        return kStatus_Success;
    }

    BISS_InitBissStatus(master);

    /* Reset AGS, intsr trigger mode do not need to reset AGS register */
    if (BISS_INSTR_TRIGGER != master->triggerMode)
    {
        BISS_EnableAGS(master);
    }

    return kStatus_Fail;
}

status_t BISS_SLVGetSCD(biss_master_t *master,
                        uint8_t slvID, uint64_t *SCData)
{
    status_t status;

    status = BISS_SLVCheckSVALID(master, slvID);
    if (status != kStatus_Success)
    {
        return status;
    }

    *SCData = BISS_SLVGetSCDRawData(master, slvID);

    BISS_SLVResetSVALID(master, slvID);

    return kStatus_Success;
}

uint64_t BISS_SCDLeftToRight(uint64_t SCData)
{
    uint64_t SCDdataNew = 0;
    uint8_t index;

    for (index = 0; index < 64; index++)
    {
        SCDdataNew |= (SCData >> index) & 0x01;
        SCDdataNew = SCDdataNew << 1;
    }

    return SCDdataNew;
}

int BISS_SCDGetnWarning(biss_master_t *master, uint8_t slvID, uint64_t SCData)
{
    biss_slave_info_t *slv = BISS_SLVGet(master, slvID);

    return (SCData >> (slv->dataLen - 1)) & 0x01;
}

int BISS_SCDGetnERR(biss_master_t *master, uint8_t slvID, uint64_t SCData)
{
    biss_slave_info_t *slv = BISS_SLVGet(master, slvID);

    return (SCData >> (slv->dataLen - 2)) & 0x01;
}

uint64_t BISS_SCDGetLinear(biss_master_t *master, uint8_t slvID, uint64_t SCData)
{
    biss_slave_info_t *slv = BISS_SLVGet(master, slvID);

    return SCData & ((1ULL << (slv->dataLen - 2)) - 1);
}

uint64_t BISS_SCDGetMtVal(biss_master_t *master,
                          uint8_t slvID, uint64_t SCData)
{
    biss_slave_info_t *slv = BISS_SLVGet(master, slvID);

    return (SCData >> (slv->stLen + slv->errWarLen)) & slv->mtMask;
}

uint64_t BISS_SLVGetStVal(biss_master_t *master,
                          uint8_t slvID, uint64_t SCData)
{
    biss_slave_info_t *slv = BISS_SLVGet(master, slvID);

    return (SCData >> slv->errWarLen) & slv->stMask;
}