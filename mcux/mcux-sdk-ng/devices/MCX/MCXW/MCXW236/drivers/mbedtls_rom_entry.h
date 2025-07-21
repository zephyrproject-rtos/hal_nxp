/*
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _MBEDTLS_ROM_ENTRY_H_
#define _MBEDTLS_ROM_ENTRY_H_

/*!
 * Function that must be called before mbedTLS libraries from ROM can be used.
 */
void mbedtls_rom_init(uint32_t *rom_load_addr, uint32_t *ram_load_addr, uint32_t *load_size);

#endif /*_MBEDTLS_ROM_ENTRY_H_*/
