/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_TSPC_H_
#define FSL_XTSPC_H_

#include "fsl_common.h"

/*!
 * @addtogroup tspc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief TSPC driver version 2.0.0. */
#define FSL_TSPC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief _tspc_group TSPC group. */
typedef enum _tspc_group
{
    kTSPC_Group1 = 0x0U, /*!< TSPC group 0. */
    kTSPC_Group2,        /*!< TSPC group 1. */
} tspc_group_t;
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name TSPC Initialization and de-initialization
 * @{
 */
/*!
 * @brief Initializes the TSPC peripheral.
 *
 * This function ungates the TSPC clock.
 *
 * @param base TSPC peripheral base address.
 *
 */
void TSPC_Init(TSPC_Type *base);

/*!
 * @brief Deinitializes the TSPC peripheral.
 *
 * This function gates the TSPC clock.
 *
 * @param base TSPC peripheral base address.
 */
void TSPC_Deinit(TSPC_Type *base);

/*!
 * @brief Initializes the TSPC group.
 *
 * This function configures which pads will participate in the grouping 
 * and enables grouping.
 *
 * @param base XBIC peripheral base address.
 * @param group number of TSPC group.
 * @param padsMask Mask value of TSPC pads, @ref tspc_group1_pads_t or tspc_group2_pads_t.
 */
void TSPC_InitGroup(TSPC_Type *base, tspc_group_t port, uint64_t padsMask);

/*!
 * @brief Enable TSPC group.
 *
 * @param base TSPC peripheral base address.
 * @param group number of TSPC group.
 */ 
static inline void TSPC_EnableGroup(TSPC_Type *base, tspc_group_t group)
{
    if(group == kTSPC_Group1)
    {
        TSPC->GRP_EN |= TSPC_GRP_EN_GRP1_EN(1);
    }
    else if(group == kTSPC_Group2)
    {
        TSPC->GRP_EN |= TSPC_GRP_EN_GRP2_EN(1);
    }
    else
    {
        /* No action taken. */
    }
}

/*!
 * @brief Disable TSPC group.
 *
 * @param base TSPC peripheral base address.
 * @param group The group number of TSPC.
 */ 
static inline void TSPC_DisableGroup(TSPC_Type *base, tspc_group_t group)
{
    if(group == kTSPC_Group1)
    {
        TSPC->GRP_EN &= ~TSPC_GRP_EN_GRP1_EN(1);
    }
    else if(group == kTSPC_Group2)
    {
        TSPC->GRP_EN &= ~TSPC_GRP_EN_GRP2_EN(1);
    }
    else
    {
        /* No action taken. */
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_TSPC_H_ */
