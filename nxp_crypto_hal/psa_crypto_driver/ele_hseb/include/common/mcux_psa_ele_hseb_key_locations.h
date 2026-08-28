/*
 * Copyright 2026 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/** \file  mcux_psa_ele_hseb_key_locations.h
 *  \brief Key locations supported by the HSE-B driver
 */

#ifndef MCUX_PSA_ELE_HSEB_KEY_LOCATIONS_H
#define MCUX_PSA_ELE_HSEB_KEY_LOCATIONS_H

/** \brief Vendor-defined non-EL2GO key location
 *
 * Cached opaque  keys that never leave the HSE-B subsystem. Lowest Byte chosen
 * as 0x82 (HB) until key location architecture is finalized.
 */
#define PSA_KEY_LOCATION_ELE_HSEB (0xC00082u)

#endif /*MCUX_PSA_ELE_HSEB_KEY_LOCATIONS_H */
