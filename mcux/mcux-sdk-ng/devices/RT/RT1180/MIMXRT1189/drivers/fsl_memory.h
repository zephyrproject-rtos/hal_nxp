/*
 * Copyright 2021-2023, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MEMORY_H_
#define _FSL_MEMORY_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.memory"
#endif

#define FSL_MEM_M33_SECURE_ADDRESS_OFFSET 0x10000000U
#define ADDRESS_NOT_AVAILABLE 0xFFFFFFFFU

typedef enum _mem_direction
{
    kMEMORY_Local2DMA = 0,
    kMEMORY_DMA2Local,
} mem_direction_t;

typedef enum _addr_type
{
    kCore_CM7_ITCM_START = 0,
    kCore_CM7_ITCM_START_ALIAS,
    kCore_CM7_ITCM_END,
    kCore_CM7_ITCM_END_ALIAS,
    kCore_CM7_DTCM_START,
    kCore_CM7_DTCM_START_ALIAS,
    kCore_CM7_DTCM_END,
    kCore_CM7_DTCM_END_ALIAS,
    kCore_CM33_CTCM_START,
    kCore_CM33_CTCM_START_ALIAS,
    kCore_CM33_CTCM_END,
    kCore_CM33_CTCM_END_ALIAS,
    kCore_CM33_STCM_START,
    kCore_CM33_STCM_START_ALIAS,
    kCore_CM33_STCM_END,
    kCore_CM33_STCM_END_ALIAS
} addr_type_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif
/*!
 * @brief Get Memory Boundary Address
 *
 * This function translate CM33/CM7 TCM address between Core View and ALIAS System View
 * CM33 and CM7 TCM Address are determined by M33_CFG[TCM_SIZE] and M7_CFG[TCM_SIZE]
 * @param type address boundary to be retrieved.
 */
uint32_t get_memory_address(addr_type_t type);

/*!
 * @brief Convert the memory map address.
 *
 * This function convert the address between system mapped address and native mapped address.
 * There maybe offset between subsystem native address and system address for some memory,
 * this funciton convert the address to different memory map.
 * @param addr address need to be converted.
 * @param direction convert direction.
 * @return the converted address
 */
uint32_t MEMORY_ConvertMemoryMapAddress(uint32_t addr, mem_direction_t direction);

#if defined(__cplusplus)
}
#endif /* __cplusplus */
#endif /* _FSL_MEMORY_H_ */
