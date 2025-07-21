/*
 * Copyright 2024-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================
Functional API definitions for ARM drivers for CE
==========================================================================*/
#ifndef FSL_CE_H
#define FSL_CE_H

#include "fsl_common.h"
#include "fsl_ce_basic.h"
#include "fsl_ce_cmsis.h"
#include "fsl_ce_matrix.h"
#include "fsl_ce_transform.h"

/*!
 * @defgroup ce Computer Engine (CE) Driver
 */

/*! @name Driver version */
/*! @{ */
/*! @brief CE driver version. */
#define FSL_CE_DRIVER_VERSION (MAKE_VERSION(2, 2, 0))
/*! @} */

/*!
 * @brief Structure for CE copy image to destination address
 *
 * Defines source and destination address for copying image with given size.
 */
typedef struct _ce_copy_image
{
    uint32_t srcAddr;
    uint32_t destAddr;
    uint32_t size;
} ce_copy_image_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the CE.
 *
 * @param ceCopyImage The information about the CE image to copy.
 */
void CE_Init(ce_copy_image_t *ceCopyImage);

/*!
 * @brief Initialize the CE.
 *
 * This function is similar with CE_Init, the difference is this function
 * does not install the firmware, the firmware could be installed using
 * CE_InstallFirmware.
 */
void CE_InitWithoutFirmware(void);

/*!
 * @brief install CE firmware by given image info
 *
 * @param ceCopyImage The information about the CE image to copy.
 */
void CE_InstallFirmware(ce_copy_image_t *ceCopyImage);

#if defined(__cplusplus)
}
#endif

#endif /*FSL_CE_H*/
