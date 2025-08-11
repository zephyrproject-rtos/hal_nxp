/*
 * Copyright 2025 NXP
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

/* The CM7 local ITCM start address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_ITCM_BEGIN 0x00000000U
/* The CM7 local ITCM end address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_ITCM_END 0x00007FFFU
/* The CM7 local DTCM start address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_DTCM_BEGIN 0x20000000U
/* The CM7 local DTCM end address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_DTCM_END 0x2000FFFFU

/* The CM7 local ITCM backdoor address offset */
#define FSL_MEM_M7_ITCM_BACKDOOR_OFFSET 0x11000000U
/* The CM7 local DTCM backdoor address offset */
#define FSL_MEM_M7_DTCM_BACKDOOR_OFFSET 0x01000000U

typedef enum _mem_direction
{
    kMEMORY_Local2DMA = 0,
    kMEMORY_DMA2Local,
} mem_direction_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif
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
static inline uint32_t MEMORY_ConvertMemoryMapAddress(uint32_t addr, mem_direction_t direction)
{
    uint32_t dest;

    switch (direction)
    {
        case kMEMORY_Local2DMA:
        {
            if (addr <= FSL_MEM_M7_ITCM_END) /* FSL_MEM_M7_ITCM_BEGIN = 0 */
            {
                dest = addr + FSL_MEM_M7_ITCM_BACKDOOR_OFFSET;
            }
            else if ((addr >= FSL_MEM_M7_DTCM_BEGIN) && (addr <= FSL_MEM_M7_DTCM_END))
            {
                dest = addr + FSL_MEM_M7_DTCM_BACKDOOR_OFFSET;
            }
            else
            {
                dest = addr;
            }
            break;
        }
        case kMEMORY_DMA2Local:
        {
            if ((addr >= (FSL_MEM_M7_ITCM_BEGIN + FSL_MEM_M7_ITCM_BACKDOOR_OFFSET)) &&
                (addr <= (FSL_MEM_M7_ITCM_END + FSL_MEM_M7_ITCM_BACKDOOR_OFFSET)))
            {
                dest = addr + FSL_MEM_M7_ITCM_BACKDOOR_OFFSET;
            }
            else if ((addr >= (FSL_MEM_M7_DTCM_BEGIN + FSL_MEM_M7_DTCM_BACKDOOR_OFFSET)) &&
                     (addr <= (FSL_MEM_M7_DTCM_END + FSL_MEM_M7_DTCM_BACKDOOR_OFFSET)))
            {
                dest = addr + FSL_MEM_M7_DTCM_BACKDOOR_OFFSET;
            }
            else
            {
                dest = addr;
            }
            break;
        }
        default:
            dest = addr;
            break;
    }

    return dest;
}
#if defined(__cplusplus)
}
#endif /* __cplusplus */
#endif /* _FSL_MEMORY_H_ */
