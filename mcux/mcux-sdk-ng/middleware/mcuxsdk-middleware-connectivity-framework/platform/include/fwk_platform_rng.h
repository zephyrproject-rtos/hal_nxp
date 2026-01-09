/* -------------------------------------------------------------------------- */
/*                             Copyright 2024 NXP                             */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef _FWK_PLATFORM_RNG_H_
#define _FWK_PLATFORM_RNG_H_

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_Rng
 * The FWK_Platform_Rng module
 *
 * FWK_Platform_Rng module provides APIs for random number generation.
 *
 * \details FWK_Platform_Rng API are used by RNG module.
 * @{
 */
#include "EmbeddedTypes.h"
/* -------------------------------------------------------------------------- */
/*                        Public functions declaration                        */
/* -------------------------------------------------------------------------- */

/*! *********************************************************************************
 * \brief  Request a seed to another core if there is no possibility to have one on
 *         the current core.
 *
 * \return  Error status :
 *          < 0 : Error
 *          = 0 : Success
 *          = 1 : Not implemented
 *          = 2 : Other core not started
 *
 ********************************************************************************** */
int PLATFORM_RequestRngSeed(void);

/*! *********************************************************************************
 * \brief  Send to the other core a seed for the PRNG.
 *
 * \param[in]  seed  Pointer to the seed
 * \param[in]  seed_size  Size of the seed.
 *
 * \return  Error status
 *          < 0 : Error
 *          = 0 : Success
 *          = 1 : Not implemented
 *
 ********************************************************************************** */
int PLATFORM_SendRngSeed(uint8_t *seed, uint16_t seed_size);

/*!
 * @}  end of FWK_Platform_Rng addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* _FWK_PLATFORM_RNG_H_ */
