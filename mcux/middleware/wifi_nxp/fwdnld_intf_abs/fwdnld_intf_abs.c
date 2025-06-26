/** @file fwdnld_intf_abs.c
 *
 *  @brief  This file provides interface abstraction APIs
 *
 *  Copyright 2023-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "fwdnld_intf_abs.h"
#include "fwdnld_sdio.h"

/** API to init the interface
 *
 * This function calls internally the interface specific init
 *
 * \param[in] intf_type Its of type fwdnld_intf_type_t
 * \param[in] intf_specific Initialisation sequence related any setting that
 * the specific interface needs.
 * \note intf_specific is to be interpretted and defined by each interface
 *
 * \return fwdnld_intf* Success, a pointer to interface is returned. To be used in
 * further API calls to this inited interface.
 * \return In case init fails, NULL is returned.
 */

fwdnld_intf_t *fwdnld_intf_init(fwdnld_intf_type_t intf_type, void *intf_specific)
{
    if (intf_type == FWDNLD_INTF_SDIO)
    {
        return sdio_init_interface(intf_specific);
    }
    return NULL;
}
