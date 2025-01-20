/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cop.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_cop"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Initializes the COP configuration structure.
 *
 * This function initializes the COP configuration structure to default values. The default
 * values are:
 * code
 *   psConfig->bEnableWriteProtect = false;
 *   psConfig->bEnableWait = false;
 *   psConfig->bEnableStop = false;
 *   psConfig->bEnableLossOfReference = false;
 *   psConfig->bEnableInterrupt = false;
 *   psConfig->bEnableCOP = false;
 *   psConfig->ePrescaler = kCOP_ClockPrescalerDivide1;
 *   psConfig->u16TimeoutCount = 0xFFFFU;
 *   psConfig->u16WindowCount = 0xFFFFU;
 *   psConfig->u16InterruptCount = 0xFFU;
 *   psConfig->eClockSource = kCOP_RoscClockSource;
 * endcode
 *
 * param config Pointer to the COP configuration structure.
 * see cop_config_t
 */
void COP_GetDefaultConfig(cop_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->bEnableWriteProtect    = false;
    psConfig->bEnableStop            = false;
    psConfig->bEnableWait            = false;
    psConfig->bEnableLossOfReference = false;
    psConfig->bEnableInterrupt       = false;
    psConfig->bEnableCOP             = false;

    psConfig->ePrescaler      = kCOP_ClockPrescalerDivide1;
    psConfig->u16TimeoutCount = 0xFFFFU;
#if (defined(FSL_FEATURE_COP_HAS_WINDOW_REGISTER) && FSL_FEATURE_COP_HAS_WINDOW_REGISTER)
    psConfig->u16WindowCount = 0xFFFFU;
#endif
    psConfig->u16InterruptCount = 0xFFU;
    psConfig->eClockSource      = kCOP_RoscClockSource;
}

/*!
 * brief Initializes the COP module.
 *
 * Call this function to do initilization configuration for COP module.
 * The configurations are:
 * - COP configuration write protect enablement
 * - Clock source selection for COP module
 * - Prescaler configuration to the input clock source
 * - Counter timeout value
 * - Window value
 * - WAIT/STOP workmode enablement
 * - Interrupt enable/disable and interrupt timing value
 * - Loss of reference counter enablement
 * - COP enable/disable
 *
 * note: Once set bEnableWriteProtect=true, the CTRL, INTVAL, WINDOW and TOUT registers are read-only.
 *
 * param base   COP peripheral base address.
 * param psConfig The configuration of COP.
 */
void COP_Init(COP_Type *base, const cop_config_t *psConfig)
{
    assert(NULL != psConfig);

    uint16_t u16Value = 0U;

    u16Value = COP_CTRL_CWEN(psConfig->bEnableWait) | COP_CTRL_CSEN(psConfig->bEnableStop) |
               COP_CTRL_CLOREN(psConfig->bEnableLossOfReference) | COP_CTRL_CLKSEL(psConfig->eClockSource) |
               COP_CTRL_INTEN(psConfig->bEnableInterrupt) | COP_CTRL_PSS(psConfig->ePrescaler) |
               COP_CTRL_CEN(psConfig->bEnableCOP);

    base->CTRL &= ~((uint16_t)COP_CTRL_CEN_MASK | COP_CTRL_CWP_MASK);

    base->TOUT   = psConfig->u16TimeoutCount;
    base->INTVAL = psConfig->u16InterruptCount;

#if (defined(FSL_FEATURE_COP_HAS_WINDOW_REGISTER) && FSL_FEATURE_COP_HAS_WINDOW_REGISTER)
    base->WINDOW = psConfig->u16WindowCount;
#endif

    base->CTRL = u16Value;

    if (psConfig->bEnableWriteProtect)
    {
        base->CTRL |= COP_CTRL_CWP_MASK;
    }
}

/*!
 * brief Refreshes the COP timer
 *
 * This function feeds the COP.
 *
 * param base  SIM peripheral base address.
 */
void COP_Refresh(COP_Type *base)
{
    base->CNTR = COP_FIRST_WORD_OF_REFRESH;
    base->CNTR = COP_SECOND_WORD_OF_REFRESH;
}
