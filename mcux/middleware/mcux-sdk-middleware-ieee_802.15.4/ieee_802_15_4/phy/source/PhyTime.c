/*! *********************************************************************************
* Copyright (c) 2015, Freescale Semiconductor, Inc.
* Copyright 2018-2024 NXP
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


/* for timeouts <= gPhyTimeMinSetupTime_c, PhyTime_ScheduleEvent() runs the event callback without delay */
#define gPhyTimeMinSetupTime_c (4) /* symbols */


static bool_t phy_lp_tmr_allow_sleep = TRUE;


#ifndef PHY_LP_TMR
#undef PHY_TMR_EXTRA
#define PHY_TMR_EXTRA 0

#else
/* PHY low power timer API based on the LL timer API */

#include "ll_types.h"
#include "controller_api_ll.h"


#define PHY_LP_TMR_MIN_DT ((gPhyTimeMinSetupTime_c) * 2)     /* symbols */

#undef PHY_TMR_EXTRA
#define PHY_TMR_EXTRA 1

#ifndef PHY_LP_TMR_CNT
#define PHY_LP_TMR_CNT 5
#endif

#define QUS_US(x) ((uint64_t)(x) / 4)       /* 1 us = 4 qus */
#define HF_QUS(x) ((uint64_t)(x) * 1250)    /* qus. 1 half slot = 312.5 us */

static const uint64_t TSTP_MAX_SYM = QUS_US(HF_QUS(((uint64_t)1 << 32))) / PHY_SYMBOLS_US;  /* BLE_REG_TMR_NATIVE_CLOCK is 32bit */

static uint64_t tstp_ovf_sym;
static uint64_t prev_ll_tstp;

static const uint64_t MIN_LP_TO = QUS_US(HF_QUS(4));                      /* 4 half slots in us. Minimum timeout that uses low power LL timer */
static const uint64_t MAX_LP_TO = QUS_US(HF_QUS(((uint64_t)1 << 28)));    /* BLE_REG_TMR_SWT_VALUE_x is 28bit */

struct phy_lp_tmr
{
    uint32_t next;
    phyTimeEvent_t ev;
};

static bool_t phy_lp_tmr_init = FALSE;

static uint32_t free_head;
static uint32_t active_head;    /* sorted list */
static uint32_t expired_head;

static struct phy_lp_tmr phy_lp_tmr[PHY_LP_TMR_CNT];

static bool_t phy_lp_tmr_process_pending = FALSE;


static void ll_tmr_start(uint64_t to);

static uint64_t get_ll_tstp()
{
    uint32_t clk;
    uint16_t qus;
    uint64_t tstp;

    LL_API_GetBleTiming(&clk, &qus);

    tstp = QUS_US(HF_QUS(clk) + qus);
    return tstp;
}

static void phy_lp_tmr_process(uint32 tmp)
{
    uint64_t tstp, to;
    int64_t dt;
    uint32_t id, p;
    phyTimeCallback_t cb;

    (void)tmp;

    OSA_InterruptDisable();

    phy_lp_tmr_process_pending = FALSE;

    /* move the expired timers from active into expired list */
    tstp = phy_lp_time_get_timestamp();

    while (active_head != INV_IDX)
    {
        id = active_head;
        dt = (int64_t)(phy_lp_tmr[id].ev.timestamp - tstp);

        if (dt <= PHY_LP_TMR_MIN_DT)
        {
            /* event is in the past or close to current time */
            active_head = phy_lp_tmr[id].next;

            phy_lp_tmr[id].next = expired_head;
            expired_head = id;
        }
        else
        {
            /* sorted list */
            break;
        }
    }

    /* there is a future event */
    if (active_head != INV_IDX)
    {
        to = (phy_lp_tmr[active_head].ev.timestamp - tstp) * PHY_SYMBOLS_US;

        ll_tmr_start(to);
    }

    /* move the expired timers into free list and run their callbacks */
    while (expired_head != INV_IDX)
    {
        id = expired_head;
        cb = phy_lp_tmr[id].ev.callback;
        p = phy_lp_tmr[id].ev.parameter;

        expired_head = phy_lp_tmr[id].next;

        phy_lp_tmr[id].next = free_head;
        free_head = id;

        /* callback could schedule other events so we processed the lists first */
        if (cb)
        {
            cb(p);
        }
    }

    OSA_InterruptEnable();
}

static void phy_lp_tmr_callback(uint32 tmp)
{
    (void)tmp;

    OSA_InterruptDisable();

    if (phy_lp_tmr_process_pending)
    {
        OSA_InterruptEnable();
        return;
    }

    phyTimeEvent_t ev;

    /* phy_lp_tmr_process() must run in PHY ISR context since you can't rearm
       the BLE timer from LL ISR context */
    ev.callback = phy_lp_tmr_process;
    ev.timestamp = PHY_LP_TMR_MIN_DT + PhyTime_GetTimestamp();
    ev.parameter = 0;

    /* set state in case the phy_lp_tmr_process() is run in
       this context (LL ISR) by PhyTime_ScheduleEvent() */
    phy_lp_tmr_process_pending = TRUE;
    phy_lp_tmr_allow_sleep = TRUE;

    if (PhyTime_ScheduleEvent(&ev) == gInvalidTimerId_c)
    {
        /* active PHY timers prevent low power mode */
        phy_lp_tmr_process_pending = FALSE;
        phy_lp_tmr_allow_sleep = FALSE;
    }

    OSA_InterruptEnable();
}

static void ll_tmr_start(uint64_t to)
{
    if (to >= MAX_LP_TO)
    {
        to = MAX_LP_TO - 1;
    }

    /* rearm the BLE timer. It can't be done from LL ISR context */
    LL_API_AppTimerClear();
    LL_API_AppTimerSet(to, phy_lp_tmr_callback, 0);

    phy_lp_tmr_allow_sleep = (to >= MIN_LP_TO);
}

phyTimeStatus_t phy_lp_time_init(void (*cb)())
{
    uint32_t cnt;

    (void)cb;

    OSA_InterruptDisable();

    if (phy_lp_tmr_init)
    {
        OSA_InterruptEnable();
        return gPhyTimeOk_c;
    }

    phy_lp_tmr_init = TRUE;

    OSA_InterruptEnable();

    active_head = INV_IDX;
    expired_head = INV_IDX;
    free_head = 0;

    /* init free list */
    for (cnt = 0; cnt < PHY_LP_TMR_CNT; cnt++)
    {
        phy_lp_tmr[cnt].next = cnt + 1;
    }
    phy_lp_tmr[PHY_LP_TMR_CNT - 1].next = INV_IDX;

    return gPhyTimeOk_c;
}

void phy_lp_time_deinit()
{
    OSA_InterruptDisable();

    if (!phy_lp_tmr_init)
    {
        OSA_InterruptEnable();
        return;
    }

    phy_lp_tmr_init = FALSE;
    OSA_InterruptEnable();
}

phyTimeTimerId_t phy_lp_time_sched_ev(phyTimeEvent_t *ev)
{
    uint32_t id, tmp, next;
    uint64_t tstp, to;
    int64_t dt = 0, dte = 0;

    if (!ev->callback)
    {
        return gInvalidTimerId_c;
    }

    OSA_InterruptDisable();

    if (free_head == INV_IDX)
    {
        OSA_InterruptEnable();
        return gInvalidTimerId_c;
    }

    /* remove from free list */
    id = free_head;
    free_head = phy_lp_tmr[id].next;

    phy_lp_tmr[id].ev = *ev;

    /* check expiration time */
    tstp = phy_lp_time_get_timestamp();

    to = (ev->timestamp - tstp) * PHY_SYMBOLS_US;
    dt = (int64_t)(ev->timestamp - tstp);

    if (dt <= PHY_LP_TMR_MIN_DT)
    {
        /* event is in the past or close to current time.
           add it to expired list */
        phy_lp_tmr[id].next = expired_head;
        expired_head = id;

        /* don't wait for the active timer (if any) to expire to handle events */
        ll_tmr_start(PHY_LP_TMR_MIN_DT * PHY_SYMBOLS_US);

        OSA_InterruptEnable();
        return id;
    }

    /* add it as active head? */
    if (active_head != INV_IDX)
    {
        dt = (int64_t)(phy_lp_tmr[active_head].ev.timestamp - tstp);
        dte = (int64_t)(phy_lp_tmr[active_head].ev.timestamp - ev->timestamp);
    }

    if ((active_head == INV_IDX) || ((dt > 0) && (dte > 0)))
    {
        /* event is in the future and the first to expire */
        phy_lp_tmr[id].next = active_head;
        active_head = id;

        ll_tmr_start(to);

        OSA_InterruptEnable();
        return id;
    }

    /* insert into the active list */
    for (tmp = active_head; tmp != INV_IDX; tmp = phy_lp_tmr[tmp].next)
    {
        next = phy_lp_tmr[tmp].next;

        if (next != INV_IDX)
        {
            dt = (int64_t)(phy_lp_tmr[next].ev.timestamp - tstp);
            dte = (int64_t)(phy_lp_tmr[next].ev.timestamp - ev->timestamp);
        }

        if ((next == INV_IDX) || ((dt > 0) && (dte > 0)))
        {
            /* event expires before next */
            phy_lp_tmr[id].next = next;
            phy_lp_tmr[tmp].next = id;

            break;
        }
    }

    OSA_InterruptEnable();
    return id;
}

phyTimeStatus_t phy_lp_time_cancel_ev(phyTimeTimerId_t id)
{
    uint32_t tmp, next;

    if (id >= PHY_LP_TMR_CNT)
    {
        return gPhyTimeNotFound_c;
    }

    OSA_InterruptDisable();

    if (active_head == INV_IDX)
    {
        OSA_InterruptEnable();
        return gPhyTimeNotFound_c;
    }

    /* remove timer from active list and add it to free list.
       no need to rearm */
    if (active_head == id)
    {
        active_head = phy_lp_tmr[id].next;

        phy_lp_tmr[id].next = free_head;
        free_head = id;

        OSA_InterruptEnable();
        return gPhyTimeOk_c;
    }

    for (tmp = active_head; tmp != INV_IDX; tmp = phy_lp_tmr[tmp].next)
    {
        next = phy_lp_tmr[tmp].next;

        if (next == id)
        {
            phy_lp_tmr[tmp].next = phy_lp_tmr[id].next;

            phy_lp_tmr[id].next = free_head;
            free_head = id;

            OSA_InterruptEnable();
            return gPhyTimeOk_c;
        }
    }

    OSA_InterruptEnable();
    return gPhyTimeNotFound_c;
}

uint64_t phy_lp_time_get_timestamp()
{
    uint64_t tmp;

    OSA_InterruptDisable();

    uint64_t ll_tstp = get_ll_tstp();

    if (prev_ll_tstp > ll_tstp)
    {
        tstp_ovf_sym += TSTP_MAX_SYM;
    }

    prev_ll_tstp = ll_tstp;

    tmp = tstp_ovf_sym + (ll_tstp / PHY_SYMBOLS_US);

    OSA_InterruptEnable();

    return tmp;
}

#endif  /* PHY_LP_TMR */


static phyTimeEvent_t  maPhyTimers[gMaxPhyTimers_c + PHY_TMR_EXTRA];
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
    return (mPhyActiveTimers == 1) && phy_lp_tmr_allow_sleep;
}
