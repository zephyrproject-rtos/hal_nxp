/*
 * Copyright 2021-2022, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FWK_DEBUG_H__
#define __FWK_DEBUG_H__

/* Enable NXP debug */
//#define gDbg_Enabled_d 1

#if (defined(gDbg_Enabled_d) && (gDbg_Enabled_d > 0))
#include "board_dbg.h"
#endif

#if defined(SERIAL_BTSNOOP)
#include "sbtsnoop.h"
#endif

/************************************************************************************
 * DEBUG - STUB MACROS
 ************************************************************************************/
/* Debug MACRO stubbed if not defined */
#ifndef BOARD_DBGLPIOSET
#define BOARD_DBGLPIOSET(__x, __y)
#endif

#ifndef BOARD_DBGINITSET
#define BOARD_DBGINITSET(__x, __y)
#endif

#ifndef BOARD_DBGINITDBGIO
#define BOARD_DBGINITDBGIO()
#endif

#ifndef BOARD_DBGAPPIOSET
#define BOARD_DBGAPPIOSET(__x, __y)
#endif

#ifndef BOARD_DBGTOGGLEDBGIO
#define BOARD_DBGTOGGLEDBGIO()
#endif

#ifndef BOARD_DBGINITDTEST
#define BOARD_DBGINITDTEST()
#endif

#ifndef BOARD_DBGSETDBGIOFORLOWPOWER
#define BOARD_DBGSETDBGIOFORLOWPOWER()
#endif

#ifndef BOARD_DBGCONFIGINIT
#define BOARD_DBGCONFIGINIT(__x)
#endif

#ifndef BOARD_DBGCONFIGINITNBU
#define BOARD_DBGCONFIGINITNBU(__x)
#endif

#ifndef APP_DBG_LOG
#define APP_DBG_LOG(...)
#endif

#ifndef PWR_DBG_LOG
#define PWR_DBG_LOG(...)
#endif

#ifndef SFC_DBG_LOG
#define SFC_DBG_LOG(...)
#endif

#ifndef MEM_DBG_LOG
#define MEM_DBG_LOG(...)
#endif

#ifndef DBG_DBG_LOG
#define DBG_DBG_LOG(...)
#endif

#ifndef INIT_DBG_LOG
#define INIT_DBG_LOG(...)
#endif

#ifndef HCI_DBG_LOG
#define HCI_DBG_LOG(...)
#endif

#ifndef PLAT_DBG_LOG
#define PLAT_DBG_LOG(...)
#endif

#ifndef DBG_LOG_DUMP
#define DBG_LOG_DUMP()
#endif

#ifndef DBG_LOG_DUMP_CHECK
#define DBG_LOG_DUMP_CHECK()
#endif

#ifndef DBG_LOG_WAKEUP_CHECK
#define DBG_LOG_WAKEUP_CHECK()
#endif

#ifndef BOARD_DBGLOGCOUNTERRUNNING
#define BOARD_DBGLOGCOUNTERRUNNING()
#endif

#ifndef BOARD_DBGINITRFACTIVE
#define BOARD_DBGINITRFACTIVE()
#endif

#ifndef DBG_NBU_GPIOD_ACCESS
#define DBG_NBU_GPIOD_ACCESS()
#endif

//#define DBG_PERF_MEAS
#if defined DBG_PERF_MEAS
#define FWK_DBG_PERF_DWT_CYCLE_CNT_DECL() uint32_t perf_primask;

#define FWK_DBG_PERF_DWT_CYCLE_CNT_START()              \
    {                                                   \
        perf_primask = DisableGlobalIRQ();              \
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; \
        DWT->CYCCNT = 0; /* Reset cycle counter */      \
        DWT->CTRL |= 1;  /* enable cycle counter */     \
    }

#define FWK_DBG_PERF_DWT_CYCLE_CNT_GET(x) \
    {                                     \
        x = DWT->CYCCNT;                  \
        EnableGlobalIRQ(perf_primask);    \
    }

#define FWK_DBG_PERF_DWT_CYCLE_CNT_STOP() DWT->CTRL &= ~0x1; /* disable cycle counter */
#else
#define FWK_DBG_PERF_DWT_CYCLE_CNT_DECL
#define FWK_DBG_PERF_DWT_CYCLE_CNT_START(...)
#define FWK_DBG_PERF_DWT_CYCLE_CNT_GET(...)
#define FWK_DBG_PERF_DWT_CYCLE_CNT_STOP
#endif

#endif /*  __FWK_DEBUG_H__ */
