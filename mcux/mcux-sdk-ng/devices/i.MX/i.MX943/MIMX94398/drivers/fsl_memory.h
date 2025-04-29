/*
 * Copyright 2024 NXP
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

/*
 * The CM33 subsystem local TCM start address, refer to Reference Manual for detailed information
 * +------------------------------------------------------------------------------------------------------------------+
 * |                         |   from cm33 (0, 1) view    |   from cm7 (0, 1) view     |   from ca55(edma) view       |
 * +------------------------------------------------------------------------------------------------------------------+
 * |                         |   start      |   end       |   start      |   end       |   start       | end          |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm33 core0 code tcm     | 0x0ffc0000   |  0x0fffffff | 0x201c0000   |  0x201fffff | 0x201c0000    | 0x201fffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm33 core0 system tcm   | 0x20000000   |  0x2003ffff | 0x20200000   |  0x2023ffff | 0x20200000    | 0x2023ffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm33 core1 code tcm     | 0x0ffc0000   |  0x0fffffff | 0x209c0000   |  0x209fffff | 0x209c0000    | 0x209fffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm33 core1 system tcm   | 0x20000000   |  0x2003ffff | 0x20a00000   |  0x20a3ffff | 0x20a00000    | 0x20a3ffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm7 core0 itcm          | 0x203c0000   |  0x203fffff | 0x00000000   |  0x0003ffff | 0x203c0000    | 0x203fffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm7 core0 dtcm          | 0x20400000   |  0x2043ffff | 0x20000000   |  0x2003ffff | 0x20400000    | 0x2043ffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm7 core1 itcm          | 0x202c0000   |  0x202fffff | 0x202c0000   |  0x202fffff | 0x202c0000    | 0x202fffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 * | cm7 core1 dtcm          | 0x20300000   |  0x2033ffff | 0x20300000   |  0x2033ffff | 0x20300000    | 0x2033ffff   |
 * +------------------------------------------------------------------------------------------------------------------+
 */
#if defined(CPU_MIMX94398AVKM_cm33_core0)
/* For cm33 core0 system tcm from edma view */
#define FSL_MEM_M33_SYS_TCM_BEGIN_FROM_EDMA_VIEW (0x20200000U)
#define FSL_MEM_M33_SYS_TCM_END_FROM_EDMA_VIEW   (0x2023FFFFU)

/* For cm33 core0 system tcm from cortex-m33 core0 view */
#define FSL_MEM_M33_SYS_TCM_BEGIN (0x20000000U)
#define FSL_MEM_M33_SYS_TCM_END   (0x2003FFFFU)

#define FSL_MEM_M33_SYS_TCM_OFFSET (FSL_MEM_M33_SYS_TCM_BEGIN_FROM_EDMA_VIEW - FSL_MEM_M33_SYS_TCM_BEGIN)

#elif defined(CPU_MIMX94398AVKM_cm33_core1)
/* For cm33 core1 system tcm from edma view */
#define FSL_MEM_M33_SYS_TCM_BEGIN_FROM_EDMA_VIEW (0x20A00000U)
#define FSL_MEM_M33_SYS_TCM_END_FROM_EDMA_VIEW   (0x20A3FFFFU)

/* For cm33 core1 system tcm from cortex-m33 core1 view */
#define FSL_MEM_M33_SYS_TCM_BEGIN (0x20000000U)
#define FSL_MEM_M33_SYS_TCM_END   (0x2003FFFFU)

#define FSL_MEM_M33_SYS_TCM_OFFSET (FSL_MEM_M33_SYS_TCM_BEGIN_FROM_EDMA_VIEW - FSL_MEM_M33_SYS_TCM_BEGIN)

#elif defined(CPU_MIMX94398AVKM_cm7_core0)

/* For cm7 core0 dtcm from edma view */
#define FSL_MEM_M7_DTCM_BEGIN_FROM_EDMA_VIEW (0x20400000U)
#define FSL_MEM_M7_DTCM_END_FROM_EDMA_VIEW   (0x2043FFFFU)

/* For cm7 core0 dtcm from cortex-m7 core0 view */
#define FSL_MEM_M7_DTCM_BEGIN (0x20000000U)
#define FSL_MEM_M7_DTCM_END   (0x2003FFFFU)

#define FSL_MEM_M7_DTCM_OFFSET (FSL_MEM_M7_DTCM_BEGIN_FROM_EDMA_VIEW - FSL_MEM_M7_DTCM_BEGIN)

#elif defined(CPU_MIMX94398AVKM_cm7_core1)
/* For cm7 core1 dtcm from edma view */
#define FSL_MEM_M7_DTCM_BEGIN_FROM_EDMA_VIEW (0x20300000U)
#define FSL_MEM_M7_DTCM_END_FROM_EDMA_VIEW (0x2033FFFFU)

/* For cm7 core1 dtcm from cortex-m7 core1 view */
#define FSL_MEM_M7_DTCM_BEGIN (0x20000000U)
#define FSL_MEM_M7_DTCM_END (0x2003FFFFU)

#define FSL_MEM_M7_DTCM_OFFSET (FSL_MEM_M7_DTCM_BEGIN_FROM_EDMA_VIEW - FSL_MEM_M7_DTCM_BEGIN)

#else
#error "Pls define CPU macro!"
#endif

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
#if (__CORTEX_M == 33U)
            if ((addr >= FSL_MEM_M33_SYS_TCM_BEGIN) && (addr <= FSL_MEM_M33_SYS_TCM_END))
            {
                dest = addr + FSL_MEM_M33_SYS_TCM_OFFSET;
            }
#elif (__CORTEX_M == 7U)
            if ((addr > FSL_MEM_M7_DTCM_BEGIN) && (addr <= FSL_MEM_M7_DTCM_END))
            {
                dest = addr + FSL_MEM_M7_DTCM_OFFSET;
            }
#endif
            else
            {
                dest = addr;
            }
            break;
        }
        case kMEMORY_DMA2Local:
        {
#if (__CORTEX_M == 33U)
            if ((addr >= (FSL_MEM_M33_SYS_TCM_BEGIN + FSL_MEM_M33_SYS_TCM_OFFSET)) &&
                (addr <= (FSL_MEM_M33_SYS_TCM_END + FSL_MEM_M33_SYS_TCM_OFFSET)))
            {
                dest = addr - FSL_MEM_M33_SYS_TCM_OFFSET;
            }
#elif (__CORTEX_M == 7U)
            if ((addr >= (FSL_MEM_M7_DTCM_BEGIN + FSL_MEM_M7_DTCM_OFFSET)) &&
                (addr <= (FSL_MEM_M7_DTCM_END + FSL_MEM_M7_DTCM_OFFSET)))
            {
                dest = addr - FSL_MEM_M7_DTCM_OFFSET;
            }
#endif
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
