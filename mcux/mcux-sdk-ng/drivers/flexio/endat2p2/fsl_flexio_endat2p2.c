/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexio_endat2p2.h"
#include "fsl_flexio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_endat2p2"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

static status_t FLEXIO_ENDAT2_FlexIO_EncSendPos_Cfg(FLEXIO_ENDAT2_Type *base, uint32_t srcClock_Hz, uint32_t baudRate);
/*******************************************************************************
 * Codes
 ******************************************************************************/

void FLEXIO_ENDAT2_GetDefaultConfig(flexio_endat2_config_t *config)
{
    assert(config != NULL);

    /* Initialize the configuration structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    config->enableInDoze     = false;
    config->enableInDebug    = true;
    config->enableFastAccess = false;
    config->baudRate_Bps     = 1000000U; /* 1 MHz default */
}

status_t FLEXIO_ENDAT2_Init(FLEXIO_ENDAT2_Type *base, const flexio_endat2_config_t *config, uint32_t srcClock_Hz)
{
    assert(base != NULL);
    assert(config != NULL);

    flexio_config_t flexioConfig;
    status_t result;

    /* Initialize FlexIO */
    FLEXIO_GetDefaultConfig(&flexioConfig);
    flexioConfig.enableInDoze     = config->enableInDoze;
    flexioConfig.enableInDebug    = config->enableInDebug;
    flexioConfig.enableFastAccess = config->enableFastAccess;

    FLEXIO_Init(base->flexio, &flexioConfig);

    /* Configure FlexIO for Enc Send Position command */
    result = FLEXIO_ENDAT2_FlexIO_EncSendPos_Cfg(base, srcClock_Hz, config->baudRate_Bps);
    if (result != kStatus_Success)
    {
        return result;
    }

    base->cmd_cfg[kFlexIO_ENDAT2_CmdIdxEncSendPosVal].cmd_val = FLEXIO_ENDAT2_CMD_ENCSENDPOSVAL >> (base->preambleNum + 2);
    base->cmd_cfg[kFlexIO_ENDAT2_CmdIdxEncSendPosVal].timer_val = (base->mtLen + base->stLen + FLEXIO_ENDAT2_RECV_EX_LEN) * 2 - 1;
    base->flexio->TIMCMP[TIMER_TRANS_INDEX] = base->cmd_cfg[kFlexIO_ENDAT2_CmdIdxEncSendPosVal].timer_val;
    base->flexio->TIMCMP[TIMER_RX_INDEX] |= base->cmd_cfg[kFlexIO_ENDAT2_CmdIdxEncSendPosVal].timer_val << 8;
    base->current_cmd_idx = kFlexIO_ENDAT2_CmdIdxEncSendPosVal;

    return kStatus_Success;
}

void FLEXIO_ENDAT2_Deinit(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);

    /* Disable shifters and timers */
    for (int i = 0; i < SHIFTER_RX_NUM; i++) {
        base->flexio->SHIFTCFG[SHIFTER_RX_INDEX + i] = 0;
        base->flexio->SHIFTCTL[SHIFTER_RX_INDEX + i] = 0;
   }

    for (int i = 0; i < SHIFTER_CLK_NUM; i++) {
        base->flexio->SHIFTCFG[SHIFTER_CLK_INDEX + i] = 0;
        base->flexio->SHIFTCTL[SHIFTER_CLK_INDEX + i] = 0;
     }

    for (int i = 0; i < SHIFTER_TX_NUM; i++) {
        base->flexio->SHIFTCFG[SHIFTER_TX_INDEX + i] = 0;
        base->flexio->SHIFTCTL[SHIFTER_TX_INDEX + i] = 0;
    }

    base->flexio->TIMCFG[TIMER_RX_ACTIVE_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] = 0;
    base->flexio->TIMCFG[TIMER_RX_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_RX_INDEX] = 0;
    base->flexio->TIMCFG[TIMER_TX_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_TX_INDEX] = 0;
    base->flexio->TIMCFG[TIMER_TRANS_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_TRANS_INDEX] = 0;
    base->flexio->TIMCFG[TIMER_CLK_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_CLK_INDEX] = 0;
    base->flexio->TIMCFG[TIMER_TX_INDEX] = 0;
    base->flexio->TIMCTL[TIMER_TX_INDEX] = 0;

    /* Deinitialize FlexIO */
    FLEXIO_Deinit(base->flexio);
}

status_t FLEXIO_ENDAT2_FlexIO_BuadrateVerify(uint32_t srcClock_Hz, uint32_t baudRate)
{

    double ns_rem_clk = (double)srcClock_Hz / baudRate / 4 - srcClock_Hz / baudRate / 4;
    double ns_rem_rxtx = (double)srcClock_Hz / baudRate / 2 - srcClock_Hz / baudRate / 2;
    double ns_rem;
    ns_rem_clk *= 2;

    if (ns_rem_rxtx > ns_rem_clk) {
        ns_rem = ns_rem_rxtx - ns_rem_clk;
    } else {
        ns_rem = ns_rem_clk - ns_rem_rxtx;
    }

    ns_rem *= 100; // The max lengh don't exceed 100 bits.
    if (ns_rem < (double)1000000000 / baudRate / 2) {
        return kStatus_Success;
    } else {
        return kStatus_Fail;
    }
}
static status_t FLEXIO_ENDAT2_FlexIO_EncSendPos_Cfg(FLEXIO_ENDAT2_Type *base, uint32_t srcClock_Hz, uint32_t baudRate)
{
    flexio_shifter_config_t shifterConfig;
    flexio_timer_config_t timerConfig;
    uint32_t timerDiv, period;

    period = 1000000000 / baudRate;
    if (base->recoveryTimeIII > period / 2) {
        base->preambleNum = (base->recoveryTimeIII - period /2) / period + 1;
    } else {
        base->preambleNum = 0;
    }
    /* Configure RX shifter and Timer*/
    memset(&shifterConfig, 0, sizeof(shifterConfig));
    memset(&timerConfig, 0, sizeof(timerConfig));
    shifterConfig.timerSelect   = TIMER_RX_INDEX;
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnNegitive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutputDisabled;
    shifterConfig.pinSelect     = base->RxdPinIndex;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeReceive;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromNextShifterOutput;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitDisable;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitHigh;

    for (int i = 0; i < SHIFTER_RX_NUM - 1; i++) {
        FLEXIO_SetShifterConfig(base->flexio, SHIFTER_RX_INDEX + i, &shifterConfig);
    }
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    FLEXIO_SetShifterConfig(base->flexio, SHIFTER_RX_INDEX + SHIFTER_RX_NUM - 1, &shifterConfig);

    /* Calculate timer divider for RX */
    timerDiv = (srcClock_Hz / (baudRate)) / 2U - 1U;
    if (timerDiv > 0xFFU)
    {
        return kStatus_InvalidArgument;
    }

    /* Configure RX timer */
    if (base->txTrigger == kFlexioEndat2_txTriggerHw)
    {
        timerConfig.triggerSelect = base->triggerInput;
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        timerConfig.triggerSource = kFLEXIO_TimerTriggerSourceExternal;
    } else {
        timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX);
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    }

    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeSingle16Bit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
    timerConfig.timerCompare    = (uint32_t)((base->preambleNum + FLEXIO_ENDAT2_CMD_CLK_LEN + 3) *(srcClock_Hz / baudRate));
    FLEXIO_SetTimerConfig(base->flexio, TIMER_RX_ACTIVE_INDEX, &timerConfig);

    memset(&timerConfig, 0, sizeof(timerConfig));
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(TIMER_RX_ACTIVE_INDEX);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinSelect = base->RxdPinIndex;
    timerConfig.pinPolarity = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput = kFLEXIO_TimerOutputZeroAffectedByReset;
    timerConfig.timerDecrement = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset = kFLEXIO_TimerResetOnTimerPinRisingEdge;
    timerConfig.timerDisable = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable = kFLEXIO_TimerEnableOnPinRisingEdgeTriggerHigh;
    timerConfig.timerStop = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart = kFLEXIO_TimerStartBitEnabled;
    timerConfig.timerCompare = timerDiv;
    FLEXIO_SetTimerConfig(base->flexio, TIMER_RX_INDEX, &timerConfig);

    /* Configure TX shifter */
    memset(&shifterConfig, 0, sizeof(shifterConfig));
    memset(&timerConfig, 0, sizeof(timerConfig));
    shifterConfig.timerSelect   = TIMER_TX_INDEX;
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutput;
    shifterConfig.pinSelect     = base->TxdPinIndex;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeTransmit;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitHigh;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnEnable;
    FLEXIO_SetShifterConfig(base->flexio, SHIFTER_TX_INDEX, &shifterConfig);

    /* Configure TX timer */
    timerDiv = (srcClock_Hz / (baudRate)) / 2U - 1U;
    if (timerDiv > 0xFFU)
    {
        return kStatus_InvalidArgument;
    }

    if (base->txTrigger == kFlexioEndat2_txTriggerHw)
    {
        timerConfig.triggerSelect = base->triggerInput;
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        timerConfig.triggerSource = kFLEXIO_TimerTriggerSourceExternal;
    } else {
        timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX);
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    }

    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerDisable;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
    timerConfig.timerCompare    = (uint32_t)(((((base->preambleNum  + FLEXIO_ENDAT2_CMD_CLK_LEN) * 2) - 1) << 8U) | (timerDiv));
    FLEXIO_SetTimerConfig(base->flexio, TIMER_TX_INDEX, &timerConfig);

    /* Configure DIR timer */
    memset(&timerConfig, 0, sizeof(timerConfig));
    if (base->txTrigger == kFlexioEndat2_txTriggerHw)
    {
        timerConfig.triggerSelect = base->triggerInput;
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        timerConfig.triggerSource = kFLEXIO_TimerTriggerSourceExternal;
    } else {
        timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX);
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    }
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
    timerConfig.pinSelect       = base->DirPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeSingle16Bit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
    timerConfig.timerCompare    = (uint32_t)((base->preambleNum + FLEXIO_ENDAT2_CMD_CLK_LEN + 1) *(srcClock_Hz / baudRate));
    FLEXIO_SetTimerConfig(base->flexio, TIMER_DIR_INDEX, &timerConfig);

    /* Configure Trans Timer. Trans Time is used to detect whether the transaction is completed. */
    memset(&timerConfig, 0, sizeof(timerConfig));
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(TIMER_RX_INDEX);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveLow;
    timerConfig.timerMode       = kFLEXIO_TimerModeSingle16Bit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnTriggerInputShiftTriggerInput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnPrevTimerEnable;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
    FLEXIO_SetTimerConfig(base->flexio, TIMER_TRANS_INDEX, &timerConfig);

    /* Configure Clock shifter */
    memset(&shifterConfig, 0, sizeof(shifterConfig));
    memset(&timerConfig, 0, sizeof(timerConfig));
    shifterConfig.timerSelect   = TIMER_CLK_INDEX;
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutput;
    shifterConfig.pinSelect     = base->ClkPinIndex;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeTransmit;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromNextShifterOutput;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitHigh;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnEnable;
    FLEXIO_SetShifterConfig(base->flexio, SHIFTER_CLK_INDEX, &shifterConfig);

    if (base->preambleNum > 16) {
        base->flexio->SHIFTBUF[SHIFTER_CLK_INDEX + 1] = (0xAAAAAAAA << ((base->preambleNum - 16) * 2));
        base->flexio->SHIFTBUF[SHIFTER_CLK_INDEX] = (0);
    } else {
        base->flexio->SHIFTBUF[SHIFTER_CLK_INDEX] = (0xAAAAAAAA << (base->preambleNum * 2));
        base->flexio->SHIFTBUF[SHIFTER_CLK_INDEX + 1] = 0xAAAAAAAA;
    }
    for (int i = 2; i < SHIFTER_CLK_NUM; i++) {
        base->flexio->SHIFTBUF[SHIFTER_CLK_INDEX + i] = 0xAAAAAAAA;
    }

    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutputDisabled;
    for (int i = 1; i < SHIFTER_CLK_NUM; i++) {
        FLEXIO_SetShifterConfig(base->flexio, SHIFTER_CLK_INDEX + i, &shifterConfig);
    }

    /* Calculate timer divider for Clock */
    timerDiv = (srcClock_Hz / (baudRate * 2)) / 2U - 1U; //The baudrate of clock is the double of data.
    if (timerDiv > 0xFFU)
    {
        return kStatus_InvalidArgument;
    }

    /* Configure clock timer */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(TIMER_TRANS_INDEX);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTriggerFallingEdge; //kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerRisingEdge; //kFLEXIO_TimerEnableOnPrevTimerEnable;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerDisable;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;
    timerConfig.timerCompare    = (uint32_t)((0xFF << 8U) | (timerDiv));
    FLEXIO_SetTimerConfig(base->flexio, TIMER_CLK_INDEX, &timerConfig);

    return kStatus_Success;
}

uint32_t FLEXIO_ENDAT2_GetRxStatusFlags(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    return FLEXIO_GetShifterStatusFlags(base->flexio) & (0x01 << SHIFTER_RX_INDEX);
}

uint32_t FLEXIO_ENDAT2_GetRxErrFlags(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    return FLEXIO_GetShifterErrorFlags(base->flexio) & (0x01 << SHIFTER_RX_INDEX);
}

void FLEXIO_ENDAT2_ClearRxStatusFlags(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    FLEXIO_ClearShifterStatusFlags(base->flexio, 0x03 << SHIFTER_RX_INDEX);
}

void FLEXIO_ENDAT2_ClearRxErrorFlags(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    FLEXIO_ClearShifterErrorFlags(base->flexio, 0x03 << SHIFTER_RX_INDEX);
}

void FLEXIO_ENDAT2_EnableInterrupts(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    FLEXIO_EnableShifterStatusInterrupts(base->flexio, 0x01 << SHIFTER_RX_INDEX);
}

void FLEXIO_ENDAT2_DisableInterrupts(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);
    FLEXIO_DisableShifterStatusInterrupts(base->flexio, 0x01 << SHIFTER_RX_INDEX);
}

void FLEXIO_ENDAT2_WriteCmd(FLEXIO_ENDAT2_Type *base, flexio_endat2_cmd_index_t cmd_idx)
{
    if (cmd_idx != base->current_cmd_idx) {
        base->flexio->TIMCMP[TIMER_TRANS_INDEX] = base->cmd_cfg[cmd_idx].timer_val;
        base->flexio->TIMCMP[TIMER_RX_INDEX] |= base->cmd_cfg[cmd_idx].timer_val << 8;
    }
    base->flexio->SHIFTBUFBIS[SHIFTER_TX_INDEX] = base->cmd_cfg[cmd_idx].cmd_val;
}

/* P(x) = x5 + x3 + x1 + 1; LSB fist in data. */
static uint8_t FLEXIO_ENDAT2_CRC5(uint32_t *data, uint32_t len)
{
    register uint8_t crc = 0x1F; /* All filled with 1 in advance. */
    register uint32_t tmp32;
    uint32_t len_tmp, data_index = 0;
    uint8_t b0, b1, b3;

    while (len)
    {
        len_tmp = len >= 32u ? 32u : len;
        len -= len_tmp;
        tmp32 = data[data_index++];

        while (len_tmp--)
        {
            b0 = (tmp32 ^ (crc >> 4u)) & 1u;
            b1 = (crc ^ b0) & 1u;
            b3 = ((crc >> 2u) ^ b0) & 1u;
            crc <<= 1u;
            crc &= 0x14u; /* Clear bit0, bit1, and bit3. */
            crc |= (b3 << 3u) | (b1 << 1u) | b0;
            tmp32 >>= 1u;
        }
    }

    return (~crc) & 0x1Fu; /* Reverse the result. */
}

status_t FLEXIO_ENDAT2_DataProcess(FLEXIO_ENDAT2_Type *base)
{
    uint8_t crc_recv, crc_cal;
    uint64_t data64;

    data64 = ((uint64_t)base->flexio->SHIFTBUF[SHIFTER_RX_INDEX] << 32) |
             base->flexio->SHIFTBUF[SHIFTER_RX_INDEX + 1];
    crc_cal = FLEXIO_ENDAT2_CRC5((uint32_t *)&data64,
                                 1u + base->mtLen + base->stLen); /* calculate CRC. */
    base->error1Bit = data64 & 1u;                                /* error1 bit */
    data64 >>= 1u;
    base->st = data64 & ((1u << base->stLen) - 1u); /* st */
    data64 >>= base->stLen;
    base->mt = data64 & ((1u << base->mtLen) - 1u); /* mt */
    data64 >>= base->mtLen;
    /* received CRC from encoder. MSB first, result in reversed bit order. */
    crc_recv = data64 & ((1u << FLEXIO_ENDAT2_CRC_LEN) - 1u);
    uint32_t tmp32 = crc_recv;
    tmp32 = __RBIT(tmp32);
    crc_recv = tmp32 >> (32u - FLEXIO_ENDAT2_CRC_LEN);
    base->crcMatch = (crc_cal == crc_recv);
    return base->crcMatch ? kStatus_Success : kStatus_Fail;
}

void FLEXIO_ENDAT2_SetTrigMode(FLEXIO_ENDAT2_Type *base, flexio_endat2_tx_trigger_t txTrigger)
{
    if (txTrigger != base->txTrigger) {
        if (txTrigger == kFlexioEndat2_txTriggerHw) {
            base->flexio->TIMCTL[TIMER_TX_INDEX] &= ~FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] &= ~FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] |= FLEXIO_TIMCTL_TRGSEL(base->triggerInput);
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] &= ~FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] &= ~FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] |= FLEXIO_TIMCTL_TRGSEL(base->triggerInput);
            base->flexio->TIMCTL[TIMER_DIR_INDEX] &= ~FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] &= ~FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] |= FLEXIO_TIMCTL_TRGSEL(base->triggerInput);
        } else {
            base->flexio->TIMCTL[TIMER_TX_INDEX] |= FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] |= FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_TX_INDEX] |= FLEXIO_TIMCTL_TRGSEL(FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX));
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] |= FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] |= FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_RX_ACTIVE_INDEX] |= FLEXIO_TIMCTL_TRGSEL(FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX));
            base->flexio->TIMCTL[TIMER_DIR_INDEX] |= FLEXIO_TIMCTL_TRGSRC_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] |= FLEXIO_TIMCTL_TRGPOL_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] &= ~FLEXIO_TIMCTL_TRGSEL_MASK;
            base->flexio->TIMCTL[TIMER_DIR_INDEX] |= FLEXIO_TIMCTL_TRGSEL(FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(SHIFTER_TX_INDEX));
        }
        base->txTrigger = txTrigger;
    }
}

status_t FLEXIO_ENDAT2_ReadBlocking(FLEXIO_ENDAT2_Type *base)
{
    assert(base != NULL);

    /* Send command */
    FLEXIO_ENDAT2_WriteCmd(base, kFlexIO_ENDAT2_CmdIdxEncSendPosVal);

    /* Wait for transmission complete */
    while (!(FLEXIO_ENDAT2_GetRxStatusFlags(base)));

   return FLEXIO_ENDAT2_DataProcess(base);;
}
