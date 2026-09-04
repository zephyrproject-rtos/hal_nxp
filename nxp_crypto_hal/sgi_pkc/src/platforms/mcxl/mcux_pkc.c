/*
 *     Copyright 2026 NXP
 *     All rights reserved.
 *
 *     SPDX-License-Identifier: BSD-3-Clause
 */

#include "mcux_pkc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Code
 ******************************************************************************/
static status_t GlikeyWriteEnable(GLIKEY_Type *base, uint8_t idx)
{
    if (kStatus_Success != GLIKEY_StartEnable(base, idx))
    {
        return kStatus_Fail;
    }
    if (kStatus_Success != GLIKEY_ContinueEnable(base, GLIKEY_CODEWORD_STEP1))
    {
        return kStatus_Fail;
    }
    if (kStatus_Success != GLIKEY_ContinueEnable(base, GLIKEY_CODEWORD_STEP2))
    {
        return kStatus_Fail;
    }
    if (kStatus_Success != GLIKEY_ContinueEnable(base, GLIKEY_CODEWORD_STEP3))
    {
        return kStatus_Fail;
    }
    if (kStatus_Success != GLIKEY_ContinueEnable(base, GLIKEY_CODEWORD_STEP_EN))
    {
        return kStatus_Fail;
    }

    return kStatus_Success;
}
/*!
 * brief PKC Init after power down.
 *
 * This function enables RAM interleave, RAM execute permission, clocks, zeroize the PKC RAM and reset PKC peripheral.
 *
 * param base PKC peripheral address.
 *
 * return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t PKC_PowerDownWakeupInit(PKC_Type *base)
{
    status_t status = kStatus_Fail;

    status = PKC_InitNoZeroize(PKC0);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Zeroize the PKC RAM */
    for (uint32_t i = 0; i < PKC_RAM_SIZE / sizeof(uint32_t); i++)
    {
        ((uint32_t *)PKC_RAM_ADDR)[i] = 0x0;
    }

    return kStatus_Success;
}

/*!
 * brief PKC Init after power down.
 *
 * This function enables RAM interleave, RAM execute permission, clocks and reset PKC peripheral.
 *
 * param base PKC peripheral address.
 *
 * return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t PKC_InitNoZeroize(PKC_Type *base)
{
    status_t status = kStatus_Fail;
    /* Turn on PKC RAM inteleaving. This setting is need for PKC L0 memory access. */
    SYSCON->SRAM_INTERLEAVE |= SYSCON_SRAM_INTERLEAVE_INTERLEAVE_MASK;

    /* Reset PKC */
    RESET_ReleasePeripheralReset(kPKC0_RST_SHIFT_RSTn);
    /* Enable PKC clock */
    CLOCK_EnableClock(kCLOCK_GatePKC0);

    /* By default SRAM have R/W enabled, execute permission is disabled */
    /* Enable execute permission in RAM atleast where stack is located (RAM B2 0x2801C000 - 0x2801DFFF) by setting
     * SRAM_XEN register in SYSCON */
    /* This is needed so PKC can fetch FUP program */
    SYSCON->SRAM_XEN |= SYSCON_SRAM_XEN_RAMB2_XEN_MASK;

    /* SRAM_XEN is duplicated by SRAM_XEN_DP which is protected by Glikey, SRAM_XEN_DP is protected by Glikey, enable
     * write, and write same value as in SRAM_XEN register */
    status = GLIKEY_SyncReset(GLIKEY0);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Move Glikey FSM to write enable */
    status = GlikeyWriteEnable(GLIKEY0, 2u);
    if (status != kStatus_Success)
    {
        return status;
    }

    /* Write value into SRAM_XEN_DP */
    SYSCON->SRAM_XEN_DP |= SYSCON_SRAM_XEN_DP_RAMB2_XEN_DP_MASK;

    /* End of write enable */
    status = GLIKEY_EndOperation(GLIKEY0);
    if (status != kStatus_Success)
    {
        return status;
    }

    return kStatus_Success;
}