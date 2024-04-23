/*
 *  Copyright 2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef __TELNET_SERVER_H__
#define __TELNET_SERVER_H__

extern void SocketTelnetServer(void *pvParameters);
extern void TelnetServer(void *pvParameters);
extern void telnet_write(const void *dataptr, int size);

#define MAX_OUTPUT_LENGTH 128
#define MAX_INPUT_LENGTH  512

#endif /* __TELNET_SERVER_H__ */
