/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_gpc.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.gpc"
#endif

/*!
 * brief Enable the modules as wakeup sources of PSLEEP (Partial Sleep) mode.
 *
 * In PSLEEP mode, HP domain is powered down, while LP domain remains powered on so peripherals in
 * LP domain can wakeup the system from PSLEEP mode via interrupts. In PSLEEP mode, system clocks
 * are stopped and peripheral clocks of LP domain can be optionally on. LP domain peripherals can
 * generate interrupt either asynchronously or need its peripheral clock on, depending on what kind
 * of wakeup event is expected. Refer to the corresponding module description about what kind of
 * interrupts are supported by the module.
 *
 * param base GPC peripheral base address.
 * param source Wakeup source for responding module, see to #gpc_wakeup_source_t.
 * param enable Enable the wakeup source or not.
 */
void GPC_EnablePartialSleepWakeupSource(GPC_Type *base, gpc_wakeup_source_t source, bool enable)
{
    /* Get the register and the shifter code. */
    uint32_t group  = source >> GPC_MAKE_WAKEUP_SOURCE_GROUP_SHIFT;
    uint32_t offset = source & GPC_MAKE_WAKEUP_SOURCE_OFFSET_MASK;

    switch (group)
    {
        case 0: /* Listed in PSLEEP Wakeup Module Enable (PWME) register. */
            if (enable)
            {
                base->PWME &= ~(1U << offset);
            }
            else
            {
                base->PWME |= (1U << offset);
            }
            break;
        /*
         * Todo: if the new register (other than PWME) is used to switch the wakeup source, just create
         * the new group and make the new case here.
         */
        default:
            break;
    }
}

/*!
 * brief Get if indicated wakeup module just caused the wakeup event to exit PSLEEP mode.
 *
 * This function returns if the responding wakeup module just caused the MCU to exit PSLEEP mode.
 * In hardware level, the flags of wakeup source are read only and will be cleared by cleaning the
 * interrupt status of the corresponding wakeup module.
 *
 * param base GPC peripheral base address.
 * param source Wakeup source for responding module, see to #gpc_wakeup_source_t.
 * retval true  - Indicated wakeup flag is asserted.
 * retval false - Indicated wakeup flag is not asserted.
 */
bool GPC_GetPartialSleepWakeupFlag(GPC_Type *base, gpc_wakeup_source_t source)
{
    /* Get the register and the shifter code. */
    uint32_t group  = source >> GPC_MAKE_WAKEUP_SOURCE_GROUP_SHIFT;
    uint32_t offset = source & GPC_MAKE_WAKEUP_SOURCE_OFFSET_MASK;
    bool ret        = false;

    switch (group)
    {
        case 0: /* Listed in PSLEEP Wakeup Module Flag (PWMF) register. */
            ret = (0U != ((1U << offset) & base->PWMF));
            break;
        /*
         * Todo: if the new register (other than PWMF) is used to switch the wakeup source, just create
         * the new group and make the new case here.
         */
        default:
            break;
    }
    return ret;
}
