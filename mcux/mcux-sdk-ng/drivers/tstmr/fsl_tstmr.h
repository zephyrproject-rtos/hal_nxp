/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2023, 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_TSTMR_H_
#define FSL_TSTMR_H_

#include "fsl_common.h"

/*!
 * @addtogroup tstmr_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_TSTMR_DRIVER_VERSION (MAKE_VERSION(2, 1, 0)) /*!< Version 2.1.0 */
                                                         /*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Init TSTMR.
 *
 * This function initializes the TSTMR module.
 *
 * @param base TSTMR peripheral base address.
 */
void TSTMR_Init(TSTMR_Type *base);

/*!
 * @brief Deinit TSTMR.
 *
 * This function deinitializes the TSTMR module.
 *
 * @param base TSTMR peripheral base address.
 */
void TSTMR_Deinit(TSTMR_Type *base);

/*! @}*/

/*!
 * @brief Reads the time stamp.
 *
 * This function reads the low and high registers and returns the 56-bit free running
 * counter value. This can be read by software at any time to determine the software ticks.
 * TSTMR registers can be read with 32-bit accesses only. The TSTMR LOW read should occur first,
 * followed by the TSTMR HIGH read.
 *
 * @param base TSTMR peripheral base address.
 *
 * @return The 56-bit time stamp value.
 */
static inline uint64_t TSTMR_ReadTimeStamp(TSTMR_Type *base)
{
    uint32_t primask = DisableGlobalIRQ();
    uint64_t timeStamp;

    uint32_t l1 = base->L;
    __DMB();
    uint32_t h1 = base->H & TSTMR_H_VALUE_MASK;

    __DMB();
    uint32_t l2 = base->L;
    __DMB();
    uint32_t h2 = base->H & TSTMR_H_VALUE_MASK;

    EnableGlobalIRQ(primask);

    if (l2 < l1)
    {
        /* Wrap (or early-carry window): use the pair that follows L2 */
        timeStamp = (((uint64_t)h2) << 32) | l2;
    }
    else
    {
        /* No wrap between L1 and L2: use the earlier consistent pair */
        timeStamp = (((uint64_t)h1) << 32) | l1;
    }

    return timeStamp;
}

/*!
 * @brief Delays for a specified number of microseconds.
 *
 * This function repeatedly reads the timestamp register and waits for the user-specified
 * delay value.
 *
 * @param base      TSTMR peripheral base address.
 * @param delayInUs Delay value in microseconds.
 */
void TSTMR_DelayUs(TSTMR_Type *base, uint64_t delayInUs);

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_TSTMR_H_ */
