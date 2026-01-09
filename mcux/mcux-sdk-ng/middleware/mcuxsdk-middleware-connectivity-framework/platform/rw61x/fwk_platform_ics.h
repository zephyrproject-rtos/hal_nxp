/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FWK_PLATFORM_ICS_H__
#define __FWK_PLATFORM_ICS_H__

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_ICS
 * The FWK_Platform_ICS module
 *
 * Framework platform inter core service module provides services to manage communication between the 2 device cores.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>

/* -------------------------------------------------------------------------- */
/*                           Public type definitions                          */
/* -------------------------------------------------------------------------- */

typedef void (*nbu_temp_req_event_callback_t)(uint32_t periodic_interval_ms);

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Register function callback called when nbu request a temperature measurement
 * \note  This is not implemented/supported on RW platform
 *
 * \param[in] cb callback that will be used when nbu request a temperature measurement
 *
 */
static inline void PLATFORM_RegisterNbuTemperatureRequestEventCb(nbu_temp_req_event_callback_t cb)
{
    (void)cb;
}

/*!
 * @}  end of FWK_Platform_ICS addtogroup
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* __FWK_PLATFORM_ICS_H__ */
