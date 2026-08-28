/*
 * Copyright 2023-2026 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef MCUX_PSA_DEFINES_H
#define MCUX_PSA_DEFINES_H

#if defined(PSA_CRYPTO_DRIVER_ELE_S4XX)
#define PSA_CRYPTO_ELE_S4XX_LOCATION 			0xC00002
#endif /* PSA_CRYPTO_DRIVER_ELE_S4XX */

#if defined(PSA_CRYPTO_DRIVER_ELS_PKC)
#include "mcuxClPsaDriver_Oracle_Interface_key_locations.h"
#endif /* PSA_CRYPTO_DRIVER_ELS_PKC */

#if defined(PSA_CRYPTO_DRIVER_ELE_S2XX)
#include "mcux_psa_s2xx_key_locations.h"
#endif /* PSA_CRYPTO_DRIVER_ELE_S2XX */

#if defined(PSA_CRYPTO_DRIVER_CAAM)
#define PSA_CRYPTO_CAAM_LOCATION 			0x000001
#endif /* PSA_CRYPTO_DRIVER_CAAM */

#if defined(PSA_CRYPTO_DRIVER_ELE_HSEB)
#include "mcux_psa_ele_hseb_key_locations.h"
#endif /* PSA_CRYPTO_DRIVER_ELE_HSEB */

#endif /* MCUX_PSA_DEFINES_H */
