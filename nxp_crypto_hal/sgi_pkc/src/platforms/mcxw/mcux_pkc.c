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

/*!
 * brief PKC Init after power down.
 *
 * This function enables clocks, zeroize the PKC RAM and reset PKC peripheral.
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
 * This function enables clocks and reset PKC peripheral.
 *
 * param base PKC peripheral address.
 *
 * return kStatus_Success upon success, kStatus_Fail otherwise
 */
status_t PKC_InitNoZeroize(PKC_Type *base)
{

    /* Enable PKC clock and disable reset */
    MRCC_0->MRCC_PKC_WRAPPER_CLKSEL = MRCC_MRCC_PKC_WRAPPER_CLKSEL_CC(1u) | MRCC_MRCC_PKC_WRAPPER_CLKSEL_RSTB_MASK;

    return kStatus_Success;
}
