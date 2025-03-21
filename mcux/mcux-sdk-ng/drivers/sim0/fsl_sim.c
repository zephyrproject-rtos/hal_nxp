/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_sim.h"

/*******************************************************************************
 * Codes
 ******************************************************************************/

/*!
 * brief Gets the unique identification register value.
 *
 * param uid Pointer to the structure to save the UID value.
 */
void SIM_GetUniqueId(sim_uid_t *uid)
{
#if (defined(FSL_FEATURE_SIM_HAS_UIDH) && FSL_FEATURE_SIM_HAS_UIDH)
    uid->H = SIM->UUIDH;
#endif /* FSL_FEATURE_SIM_HAS_UIDH */

#if (defined(FSL_FEATURE_SIM_HAS_UIDM) && FSL_FEATURE_SIM_HAS_UIDM)
    uid->MH = SIM->UUIDMH;
    uid->ML = SIM->UUIDML;
#endif /* FSL_FEATURE_SIM_HAS_UIDM */
    uid->L = SIM->UUIDL;
}
