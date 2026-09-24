/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * The RT2660 Neutron driver expects a few MCUX SDK helpers that have no
 * counterpart in a Zephyr build: the debug console (DbgConsole_Printf /
 * DbgConsole_Vprintf) used for its diagnostic messages and cleanCache_by_Addr()
 * used for cache maintenance. Provide thin shims that route these to the
 * equivalent Zephyr APIs (printk() and the cache subsystem).
 */

#include <stdarg.h>
#include <zephyr/sys/printk.h>
#include <zephyr/cache.h>

int DbgConsole_Printf(const char *fmt_s, ...)
{
	va_list ap;

	va_start(ap, fmt_s);
	vprintk(fmt_s, ap);
	va_end(ap);

	return 0;
}

int DbgConsole_Vprintf(const char *fmt_s, va_list formatStringArg)
{
	vprintk(fmt_s, formatStringArg);

	return 0;
}

void cleanCache_by_Addr(uint32_t addr, uint32_t size)
{
	sys_cache_data_flush_range((uint32_t *)addr, (int32_t)size);
}
