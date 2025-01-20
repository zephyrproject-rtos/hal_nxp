/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_LDB_H_
#define _FSL_LDB_H_

#include "fsl_common.h"

/*!
 * @addtogroup ldb
 * @{
 */

/*! @file */

/******************************************************************************
 * Definitions
 *****************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief LDB driver version. */
#define FSL_LDB_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*@}*/

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#define LVDS_DI_COUNT 2U /* LDB DI count*/
#define LVDS_SPWG     0U /* LDB data map use SPWG standard */
#define LVDS_JEIDA    1U /* LDB data map use JEIDA standard */

/*!
 * brief Initializes the LDB module for LVDS port panel.
 *
 * param base LDB peripheral base address.
 * param diIndex Display Input index.
 * param dualpanelIndex dual panel index.
 * param datamap 0 for SPWG 1 for JEIDA.
 */
void LDB_Init(LDB_Type *base, uint8_t diIndex, uint8_t dualpanelIndex, uint8_t datamap);


#if defined(__cplusplus)
}
#endif /*_cplusplus*/
/*@}*/

#endif /* _FSL_LDB_H_ */
