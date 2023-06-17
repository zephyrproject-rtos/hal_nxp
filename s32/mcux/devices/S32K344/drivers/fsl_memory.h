/*
 * Copyright 2023 NXP
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
/* The CM7 DTCM 0 start address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_DTCM_0_BEGIN 0x20000000U
/* The CM7 DTCM 0 end address, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_DTCM_0_END 0x2001FFFFU
/* The CM7 DTCM 0 Backdoor offset from DTCM 0, refer to Reference Manual for detailed information */
#define FSL_MEM_M7_DTCM_0_OFFSET 0x1000000U

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
            if ((addr >= FSL_MEM_M7_DTCM_0_BEGIN) && (addr <= FSL_MEM_M7_DTCM_0_END))
            {
                dest = addr + FSL_MEM_M7_DTCM_0_OFFSET;
            }
            else
            {
                dest = addr;
            }
            break;
        }
        case kMEMORY_DMA2Local:
        {
            if ((addr >= (FSL_MEM_M7_DTCM_0_BEGIN + FSL_MEM_M7_DTCM_0_OFFSET)) &&
                (addr <= (FSL_MEM_M7_DTCM_0_END + FSL_MEM_M7_DTCM_0_OFFSET)))
            {
                dest = addr - FSL_MEM_M7_DTCM_0_OFFSET;
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
