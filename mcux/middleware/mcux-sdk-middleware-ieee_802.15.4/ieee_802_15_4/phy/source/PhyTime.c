/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2018-2022 NXP
* All rights reserved.
*
* \file
*
* SPDX-License-Identifier: BSD-3-Clause
********************************************************************************** */

#include "Phy.h"
#include "PhyTime.h"
#include "EmbeddedTypes.h"

#include "fsl_os_abstraction.h"
#include "fsl_device_registers.h"

#define gPhyTimeMinSetupTime_c (4) /* symbols */

static phyTimeEvent_t  maPhyTimers[gMaxPhyTimers_c];
static phyTimeEvent_t *pNextEvent;
volatile uint64_t      gPhyTimerOverflow;
static uint8_t         mPhyActiveTimers;
static bool            bTimerInitDone = false;
static void (*gpfPhyTimeNotify)(void) = NULL;

static void PhyTime_OverflowCB(uint32_t param);
static phyTimeEvent_t *PhyTime_GetNextEvent(void);


phyTime_t PhyTimeGetEventTimeout(void)
{
    return ZLL->T3CMP;
}

phyTime_t PhyTime_ReadClock()
{
    return (phyTime_t)(ZLL->EVENT_TMR >> ZLL_EVENT_TMR_EVENT_TMR_SHIFT);
}

void PhyTime_ISR(void)
{
    if (pNextEvent->callback == PhyTime_OverflowCB)
    {
        gPhyTimerOverflow += (uint64_t)(1 << gPhyTimeShift_c);
    }

    if (gpfPhyTimeNotify)
    {
        gpfPhyTimeNotify();
    }
    else
    {
        PhyTime_RunCallback();
        PhyTime_Maintenance();
    }
}

phyTimeStatus_t PhyTime_TimerInit(void (*cb)(void))
{
    // Check whether timer has already been initialised
    if (bTimerInitDone == true)
    {
		return gPhyTimeError_c;
    }

    gpfPhyTimeNotify = cb;
    gPhyTimerOverflow = 0;
    memset(maPhyTimers, 0, sizeof(maPhyTimers));

    /* Schedule Overflow Calback */
    pNextEvent = &maPhyTimers[0];
    pNextEvent->callback = PhyTime_OverflowCB;
    pNextEvent->timestamp = (uint64_t)(1 << gPhyTimeShift_c);
    PhyTimeSetWaitTimeout(pNextEvent->timestamp);
    mPhyActiveTimers = 1;

    // indicate that phytimer layer is initialized
    bTimerInitDone = true;

    return gPhyTimeOk_c;
}

void PhyTime_TimerDeinit ( void )
{
    bTimerInitDone = false;
    gpfPhyTimeNotify = NULL;
}

phyTime_t PhyTime_GetTimestamp(void)
{
    phyTime_t t;

    OSA_InterruptDisable();
    t = PhyTime_ReadClock();
    t |= gPhyTimerOverflow;
    /* Check for overflow */
    if(pNextEvent != NULL)
    {
        if (pNextEvent->callback == PhyTime_OverflowCB)
        {
            if (ZLL->IRQSTS & ZLL_IRQSTS_TMR1IRQ_MASK)
            {
                t = PhyTime_ReadClock();
                t |= gPhyTimerOverflow;
                t += (1 << gPhyTimeShift_c);
            }
        }
    }
    OSA_InterruptEnable();

    return t;
}

phyTimeTimerId_t PhyTime_ScheduleEvent(phyTimeEvent_t *pEvent)
{
    phyTimeTimerId_t tmr;

    if (NULL == pEvent->callback)
    {
        return gInvalidTimerId_c;
    }

    /* Search for a free slot (slot 0 is reserved for the Overflow calback) */
    OSA_InterruptDisable();
    for (tmr = 1; tmr < gMaxPhyTimers_c; tmr++)
    {
        if (maPhyTimers[tmr].callback == NULL)
        {
            if (mPhyActiveTimers == 1)
            {
                /* PHY_disallow_sleep(); */
            }

            mPhyActiveTimers++;
            maPhyTimers[tmr] = *pEvent;
            break;
        }
    }
    OSA_InterruptEnable();

    if (tmr >= gMaxPhyTimers_c)
    {
        return gInvalidTimerId_c;
    }

    /* Program the next event */
    if ((NULL == pNextEvent) || ((NULL != pNextEvent) && (maPhyTimers[tmr].timestamp < pNextEvent->timestamp)))
    {
        PhyTime_Maintenance();
    }

    return tmr;
}

phyTimeStatus_t PhyTime_CancelEvent(phyTimeTimerId_t timerId)
{
    if ((timerId == 0) || (timerId >= gMaxPhyTimers_c) || (NULL == maPhyTimers[timerId].callback))
    {
        return gPhyTimeNotFound_c;
    }

    OSA_InterruptDisable();
    if (pNextEvent == &maPhyTimers[timerId])
    {
        pNextEvent = NULL;
    }

    maPhyTimers[timerId].callback = NULL;
    mPhyActiveTimers--;

    if (mPhyActiveTimers == 1)
    {
        /* PHY_allow_sleep(); */
    }

    OSA_InterruptEnable();

    return gPhyTimeOk_c;
}

phyTimeStatus_t PhyTime_CancelEventsWithParam(uint32_t param)
{
    uint32_t i;
    phyTimeStatus_t status = gPhyTimeNotFound_c;

    OSA_InterruptDisable();
    for (i = 1; i < gMaxPhyTimers_c; i++)
    {
        if ((NULL != maPhyTimers[i].callback) && (param == maPhyTimers[i].parameter))
        {
            status = gPhyTimeOk_c;
            maPhyTimers[i].callback = NULL;
            mPhyActiveTimers--;

            if (pNextEvent == &maPhyTimers[i])
            {
                pNextEvent = NULL;
            }
        }
    }

    if (mPhyActiveTimers == 1)
    {
        /* PHY_allow_sleep(); */
    }
    OSA_InterruptEnable();

    return status;
}

void PhyTime_RunCallback(void)
{
/* for V18 compiler, variable need be given initial value */
    uint32_t param =0;
    phyTimeCallback_t cb = NULL;

    OSA_InterruptDisable();

    if (pNextEvent)
    {
        param = pNextEvent->parameter;
        cb = pNextEvent->callback;
        pNextEvent->callback = NULL;
        pNextEvent = NULL;
        mPhyActiveTimers--;

        if (mPhyActiveTimers == 1)
        {
            /* PHY_allow_sleep(); */
        }
    }

    OSA_InterruptEnable();
    
    if (cb)
    {
        cb(param);
    }
} 

void PhyTime_Maintenance(void)
{
    phyTime_t currentTime;
    phyTimeEvent_t *pEv;

    PhyTimeDisableWaitTimeout();

    while (1)
    {
        OSA_InterruptDisable();

        pEv = PhyTime_GetNextEvent();
        currentTime = PhyTime_GetTimestamp();

        /* Program next event if exists */
        if (pEv)
        {
            pNextEvent = pEv;

            if (pEv->timestamp > (currentTime + gPhyTimeMinSetupTime_c))
            {
                PhyTimeSetWaitTimeout(pEv->timestamp);
                pEv = NULL;
            }
        }

        OSA_InterruptEnable();

        if (!pEv)
        {
            break;
        }

        PhyTime_RunCallback();
    }
}

static void PhyTime_OverflowCB(uint32_t param)
{
    param = param;

    /* Reprogram the next overflow callback */
    OSA_InterruptDisable();
    mPhyActiveTimers++;
    maPhyTimers[0].callback = PhyTime_OverflowCB;
    maPhyTimers[0].timestamp = gPhyTimerOverflow + (1 << gPhyTimeShift_c);
    OSA_InterruptEnable();
}

static phyTimeEvent_t *PhyTime_GetNextEvent(void)
{
    phyTimeEvent_t *pEv = NULL;
    uint32_t i;

    /* Search for the next event to be serviced */
    for (i = 0; i < gMaxPhyTimers_c; i++)
    {
        if (NULL != maPhyTimers[i].callback)
        {
            if (NULL == pEv)
            {
                pEv = &maPhyTimers[i];
            }
            /* Check which event expires first */
            else
            {
                if (maPhyTimers[i].timestamp < pEv->timestamp)
                {
                    pEv = &maPhyTimers[i];
                }
            }
        }
    }

    return pEv;
}

bool_t PhyTime_can_sleep()
{
    return (mPhyActiveTimers == 1);
}
