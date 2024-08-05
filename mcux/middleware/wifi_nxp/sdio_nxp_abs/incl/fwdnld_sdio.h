/** @file fwdnld_sdio.h
 *
 *  @brief  This file provides declarations for sdio interface abstraction
 *
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _FWDNLD_SDIO_H_
#define _FWDNLD_SDIO_H_
#include <stdint.h>
#include "fwdnld_intf_abs.h"

typedef struct
{
    uint32_t ioport;
} fwdnld_sdio_intf_specific;

#define GET_INTF_SDIO_IOPORT(x)                                                                  \
    ({                                                                                           \
        fwdnld_sdio_intf_specific *y = (fwdnld_sdio_intf_specific *)((x)->intf_s.intf_specific); \
        y->ioport;                                                                               \
    })

/** Firmware ready */
#define FIRMWARE_READY 0xfedcU

extern fwdnld_intf_t *sdio_init_interface(void *settings);

#endif /*_FWDNLD_SDIO_H_*/
