/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DBG_IO_H
#define _DBG_IO_H


#ifdef DBG_IO_ENABLE

void Dbg_IO_Init(void);
void Dbg_IO_Set(unsigned long io, unsigned short level);

#else

#define Dbg_IO_Init()
#define Dbg_IO_Set(io, level)

#endif


#endif /* _DBG_IO_H */