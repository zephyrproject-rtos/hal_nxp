/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_common.h"
#include "fsl_reset.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.reset"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
#define GET_REG_INDEX(x) ((uint32_t)(((uint32_t)(x) & 0xFF00U) >> 8))
#define GET_BIT_INDEX(x) ((uint32_t)((uint32_t)(x) & 0x00FFU))

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Assert reset to peripheral.
 *
 * Asserts reset signal to specified peripheral module.
 *
 * param peripheral Assert reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_SetPeripheralReset(reset_ip_name_t peripheral)
{
    uint32_t regIndex             = GET_REG_INDEX(peripheral);
    uint32_t bitPos               = GET_BIT_INDEX(peripheral);
    uint32_t bitMask              = 1UL << bitPos;
    volatile uint32_t *pResetCtrl = &(MRCC->MRCC_GLB_RST0);

    /* NotAvail_RSTn (0xFFFF) encodes bitPos=0xFF; guard to avoid undefined left-shift. */
    if (peripheral == NotAvail_RSTn)
    {
        return;
    }

    assert(bitPos < 32u);
    assert(regIndex < 3u);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_LOCK_MASK;

    /* Use SET register to set RST bit to 1: bit=1 means peripheral is released from reset */
    if (regIndex == 0U)
    {
        MRCC->MRCC_GLB_RST0_SET = bitMask;
        pResetCtrl = &(MRCC->MRCC_GLB_RST0);
    }
    else if (regIndex == 1U)
    {
        MRCC->MRCC_GLB_RST1_SET = bitMask;
        pResetCtrl = &(MRCC->MRCC_GLB_RST1);
    }
    else if (regIndex == 2U)
    {
        MRCC->MRCC_GLB_RST2_SET = bitMask;
        pResetCtrl = &(MRCC->MRCC_GLB_RST2);
    }
    else
    {
        /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
    }
    /* wait until it reads 0b1 (peripheral is released from reset) */
    while (0u == ((*pResetCtrl) & bitMask))
    {
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_LOCK_MASK;
}

/*!
 * brief Clear reset to peripheral.
 *
 * Clears reset signal to specified peripheral module, allows it to operate.
 *
 * param peripheral Clear reset to this peripheral. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_ClearPeripheralReset(reset_ip_name_t peripheral)
{
    uint32_t regIndex             = GET_REG_INDEX(peripheral);
    uint32_t bitPos               = GET_BIT_INDEX(peripheral);
    uint32_t bitMask              = 1UL << bitPos;
    volatile uint32_t *pResetCtrl = &(MRCC->MRCC_GLB_RST0);

    /* NotAvail_RSTn (0xFFFF) encodes bitPos=0xFF; guard to avoid undefined left-shift. */
    if (peripheral == NotAvail_RSTn)
    {
        return;
    }

    assert(bitPos < 32u);
    assert(regIndex < 3u);

    /* Unlock clock configuration */
    SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_LOCK_MASK;

    /* Use CLR register to clear RST bit to 0: bit=0 means peripheral is held in reset */
    if (regIndex == 0U)
    {
        MRCC->MRCC_GLB_RST0_CLR = bitMask;
        pResetCtrl               = &(MRCC->MRCC_GLB_RST0);
    }
    else if (regIndex == 1U)
    {
        MRCC->MRCC_GLB_RST1_CLR = bitMask;
        pResetCtrl               = &(MRCC->MRCC_GLB_RST1);
    }
    else if (regIndex == 2U)
    {
        MRCC->MRCC_GLB_RST2_CLR = bitMask;
        pResetCtrl               = &(MRCC->MRCC_GLB_RST2);
    }
    else
    {
        /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
    }
    /* wait until it reads 0b0 (peripheral is held in reset) */
    while (0u != ((*pResetCtrl) & bitMask))
    {
    }

    /* Freeze clock configuration */
    SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_LOCK_MASK;
}

/*!
 * brief Reset peripheral module.
 *
 * Reset peripheral module.
 *
 * param peripheral Peripheral to reset. The enum argument contains encoding of reset register
 *                   and reset bit position in the reset register.
 */
void RESET_PeripheralReset(reset_ip_name_t peripheral)
{
    RESET_ClearPeripheralReset(peripheral);
    RESET_SetPeripheralReset(peripheral);
}
