/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_tspc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.tspc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get instance number for TSPC.
 *
 * @param base TSPC peripheral base address.
 */
static uint32_t TSPC_GetInstance(TSPC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/        
 
/*! @brief Array to map TSPC instance number to base pointer. */
static TSPC_Type *const s_tspcBases[] = TSPC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Array to map TSPC instance number to clock name. */
static const clock_ip_name_t s_tspcClock[] = TSPC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t TSPC_GetInstance(TSPC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_tspcBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_tspcBases[instance]) == MSDK_REG_SECURE_ADDR(base))   
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_tspcBases));

    return instance;
}
/*!
 * brief Initializes the TSPC peripheral.
 *
 * This function ungates the TSPC clock.
 * 
 * param base TSPC peripheral base address.
 */
void TSPC_Init(TSPC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the TSPC clock */
    (void)CLOCK_EnableClock(s_tspcClock[TSPC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Deinitializes the TSPC peripheral.
 *
 * This function gates the TSPC clock.
 *
 * param base TSPC peripheral base address.
 */
void TSPC_Deinit(TSPC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the TSPC clock */
    CLOCK_DisableClock(s_tspcClock[TSPC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Enables individual TSPC master port error detection.
 *
 * This function enables individual TSPC master port error detection.
 *
 * param base TSPC peripheral base address.
 * param group number of TSPC group.
 * param padsMask Mask value of TSPC pads, @ref tspc_group1_pads_t or tspc_group2_pads_t.
 */
void TSPC_InitGroup(TSPC_Type *base, tspc_group_t group, uint64_t padsMask)
{
    assert(group < TSPC_GROUP_COUNT);

    TSPC_DisableGroup(base, group);
    base->GROUP[group].GRP_OBE1 = (uint32_t)padsMask;
    base->GROUP[group].GRP_OBE2 = (uint32_t)(padsMask >> 32U);
    TSPC_EnableGroup(base, group);
}
