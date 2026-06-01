/* -------------------------------------------------------------------------- */
/*                           Copyright 2024-2026 NXP                          */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_CRYPTO_H_
#define _FWK_PLATFORM_CRYPTO_H_

/*!
 * @addtogroup FWK_Platform_module
 * The FWK_Platform module
 *
 * FWK_Platform module provides APIs to set platform parameters.
 * @{
 */
/*!
 * @addtogroup FWK_Platform
 * The FWK_Platform main module
 *
 * FWK_Platform main module provides APIs to set main platform parameters.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "EmbeddedTypes.h"
#include <stdbool.h>

/* -------------------------------------------------------------------------- */
/*                                 Definitions                                */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                        Public functions declaration                        */
/* -------------------------------------------------------------------------- */
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * \brief  Initialize Security subsystem
 *
 */
int PLATFORM_InitCrypto(void);

/*!
 * \brief Close Security subsystem (if applicable)
 *
 */
int PLATFORM_TerminateCrypto(void);

/*!
 * \brief Reset Security subsystem (if applicable)
 *
 */
int PLATFORM_ResetCrypto(void);

/*!
 * \brief Reinit Security subsystem (if applicable)
 *
 */
int PLATFORM_ReinitCrypto(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!
 * @}  end of FWK_Platform addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* _FWK_PLATFORM_CRYPTO_H_ */
