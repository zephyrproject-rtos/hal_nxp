/** @file firmware_dnld.h
 *
 *  @brief firmware download header file to download connectivity firmwares
 *
 *  Copyright 2021-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef _FIMRWARE_DNLD_H_
#define _FIMRWARE_DNLD_H_

#include <osa.h>

#define fwdnld_io_e(...) wmlog_e("wifi_io", ##__VA_ARGS__)
#define fwdnld_io_w(...) wmlog_w("wifi_io", ##__VA_ARGS__)

#if CONFIG_FWDNLD_IO_DEBUG
#define fwdnld_io_d(...) wmlog("wifi_io", ##__VA_ARGS__)
#else
#define fwdnld_io_d(...)
#endif /* ! CONFIG_DWDNLD_IO_DEBUG */

int32_t firmware_download(const uint8_t *fw_start_addr, const size_t size, void *intf, uint8_t fw_reload);

#endif //_FIMRWARE_DNLD_H_
