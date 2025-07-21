/*
 * Copyright 2023, NXP
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
#define GET_REG_INDEX(x) ((uint32_t)(((uint32_t)(x)&0xFF00U) >> 8))
#define GET_BIT_INDEX(x) ((uint32_t)((uint32_t)(x)&0x00FFU))
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

    if (peripheral == NotAvail_RSTn)
    {
        return;
    }

    assert(bitPos < 32u);
    assert(regIndex <= 2u);

    


    /* reset register is in MRCC */
    /* clear bit */
    if (regIndex == 2U)
    {
        AON__CGU->RST_SUB_BLK |= bitMask;
    }
    else
    {
#if __CORTEX_M == (33U) /* Building on the main core */

        /* Unlock clock configuration */  
        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        if (regIndex == 0U)
        {
            MRCC->GLB_RSTCLR0 = bitMask;
        }
        else if (regIndex == 1U)
        {
            MRCC->GLB_RSTCLR1 = bitMask;
        }
        else
        {
            /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
        }

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

#endif /* Building on the main core */
    }
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

    if (peripheral == NotAvail_RSTn)
    {
        return;
    }

    assert(bitPos < 32u);
    assert(regIndex <= 2u);

    /* Unlock clock configuration */


    /* reset register is in MRCC */
    /* clear bit */
    if (regIndex == 2U)
    {
        AON__CGU->RST_SUB_BLK |= bitMask;
    }
    else
    {
#if __CORTEX_M == (33U) /* Building on the main core */

        SYSCON->CLKUNLOCK &= ~SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

        if (regIndex == 0U)
        {
            MRCC->GLB_RSTSET0 = bitMask;
        }
        else if (regIndex == 1U)
        {
            MRCC->GLB_RSTSET1 = bitMask;
        }
        else
        {
            /* Added comments to prevent the violation of MISRA C-2012 rule 15.7 */
        }

        /* Freeze clock configuration */
        SYSCON->CLKUNLOCK |= SYSCON_CLKUNLOCK_CLKGEN_LOCKOUT_MASK;

#endif /* Building on the main core */
    }
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
    RESET_SetPeripheralReset(peripheral);
    RESET_ClearPeripheralReset(peripheral);
}
