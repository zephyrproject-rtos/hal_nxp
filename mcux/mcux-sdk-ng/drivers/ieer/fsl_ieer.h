/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2017, NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_IEER_H_
#define FSL_IEER_H_

#include "fsl_common.h"

/*!
 * @addtogroup ieer
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief IEER driver version. Version 2.0.0.
 *
 * Current version: 2.0.0
 *
 * Change log:
 * - Version 2.0.0
 *   - Initial version
 */
#define FSL_IEER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

typedef enum _ieer_region
{
    kIEER_Region0 = 0U, /*!< IEER region 0 */
    kIEER_Region1 = 1U, /*!< IEER region 1 */
    kIEER_Region2 = 2U, /*!< IEER region 2 */
    kIEER_Region3 = 3U  /*!< IEER region 3 */
} ieer_region_t;

/*! @brief IEER configuration structure. */
typedef struct _ieer_config
{
    uint32_t startaddr; /*!< IEER Memory Region W0 Descriptor */
    uint32_t endaddr;   /*!< IEER Memory Region W2 Descriptor */
    uint32_t rmsg;      /*!< IEER Memory Region W4 Descriptor RMSG field */
    bool valid;         /*!< IEER Memory Region W4 Descriptor VLD bit */
} ieer_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Clears the IEER Memory Region Descriptors.
 *
 * This function clears IEER Memory Region Descriptors to reset values.
 *
 * @param base IEER peripheral address.
 */
void IEER_Init(IEER_Type *base);

/*!
 * @brief Sets the IEER Memory Region Descriptors.
 *
 * This function configures IEER Memory Region Descriptor according to region configuration structure.
 *
 * @param base IEER peripheral address.
 * @param region Selection of the IEER region to be configured.
 * @param config Configuration for the selected IEER region.
 */
void IEER_SetRegionConfig(IEER_Type *base, ieer_region_t region, ieer_config_t *config);

/*!
 * @brief Loads default values to the IEER memory region configuration structure.
 *
 * Loads default values to the IEER memory region configuration structure. The default values are as follows.
 * @code
 *   config->startaddr = 0;
 *   config->endaddr = 0x00000FFFU;
 *   config->rmsg = 0;
 *   config->valid = false;
 * @endcode
 *
 * @param config Configuration for the selected IEER region.
 */
void IEER_GetDefaultConfig(ieer_config_t *config);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_IEER_H_ */
