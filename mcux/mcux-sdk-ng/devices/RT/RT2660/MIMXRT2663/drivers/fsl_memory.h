/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MEMORY_H_
#define _FSL_MEMORY_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief MEMORY driver version 1.0.0. */
#define FSL_MEMORY_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*@}*/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.memory"
#endif

/*
 * ITCM
 */
#define MEM_ITCM_START          0x00000000U
#define MEM_ITCM_END            0x0003FFFFU
#define MEM_ITCM_ALIAS_OFFSET   0x210C0000U
#define MEM_ITCM_ALIAS_START    (MEM_ITCM_START + MEM_ITCM_ALIAS_OFFSET)
#define MEM_ITCM_ALIAS_END      (MEM_ITCM_END + MEM_ITCM_ALIAS_OFFSET)

/*
 * DTCM
 */
#define MEM_DTCM_START          0x20000000U
#define MEM_DTCM_END            0x2003FFFFU
#define MEM_DTCM_ALIAS_OFFSET   0x01100000U
#define MEM_DTCM_ALIAS_START    (MEM_DTCM_START + MEM_DTCM_ALIAS_OFFSET)
#define MEM_DTCM_ALIAS_END      (MEM_DTCM_END + MEM_DTCM_ALIAS_OFFSET)

/*
 * Cache
 */
#define MEM_XSPI0_LLC_START     0x68000000U
#define MEM_XSPI0_LLC_END       0x6FFFFFFFU
#define MEM_XSPI1_LLC_START     0x88000000U
#define MEM_XSPI1_LLC_END       0x8FFFFFFFU
#define MEM_XSPI_LLC_OFFSET     0x08000000U
#define MEM_XSPI0_START         (MEM_XSPI0_LLC_START - MEM_XSPI_LLC_OFFSET)
#define MEM_XSPI0_END           (MEM_XSPI0_LLC_END - MEM_XSPI_LLC_OFFSET)
#define MEM_XSPI1_START         (MEM_XSPI1_LLC_START - MEM_XSPI_LLC_OFFSET)
#define MEM_XSPI1_END           (MEM_XSPI1_LLC_END - MEM_XSPI_LLC_OFFSET)

#define SECURE_ADDR(addr)       (addr + 0x10000000U)



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
            /*ITCM*/
            if ((addr <= MEM_ITCM_END) || ((addr >= SECURE_ADDR(MEM_ITCM_START)) && (addr <= SECURE_ADDR(MEM_ITCM_END))))
            {
                dest = addr + MEM_ITCM_ALIAS_OFFSET;
            }
            /*DTCM*/
            else if (((addr >= MEM_DTCM_START) && (addr <= MEM_DTCM_END)) || ((addr >= SECURE_ADDR(MEM_DTCM_START)) && (addr <= SECURE_ADDR(MEM_DTCM_END))))
            {
                dest = addr + MEM_DTCM_ALIAS_OFFSET;
            }
            /*XSPI*/
            else if (((addr >= MEM_XSPI0_LLC_START) && (addr <= MEM_XSPI0_LLC_END)) || ((addr >= SECURE_ADDR(MEM_XSPI0_LLC_START)) && (addr <= SECURE_ADDR(MEM_XSPI0_LLC_END)))
                     || ((addr >= MEM_XSPI1_LLC_START) && (addr <= MEM_XSPI1_LLC_END)) || ((addr >= SECURE_ADDR(MEM_XSPI1_LLC_START)) && (addr <= SECURE_ADDR(MEM_XSPI1_LLC_END))))
            {
                dest = addr - MEM_XSPI_LLC_OFFSET;
            }
            else
            {
                dest = addr;
            }
            break;
        }
        case kMEMORY_DMA2Local:
        {
            /*ITCM*/
            if (((addr >= MEM_ITCM_ALIAS_START) && (addr <= MEM_ITCM_ALIAS_END)) || ((addr >= SECURE_ADDR(MEM_ITCM_ALIAS_START)) && (addr <= SECURE_ADDR(MEM_ITCM_ALIAS_END))))
            {
                dest = addr - MEM_ITCM_ALIAS_OFFSET;
            }
            /*DTCM*/
            else if (((addr >= MEM_DTCM_ALIAS_START) && (addr <= MEM_DTCM_ALIAS_END)) || ((addr >= SECURE_ADDR(MEM_DTCM_ALIAS_START)) && (addr <= SECURE_ADDR(MEM_DTCM_ALIAS_END))))
            {
                dest = addr - MEM_DTCM_ALIAS_OFFSET;
            }
            /*XSPI*/
            else if (((addr >= MEM_XSPI0_START) && (addr <= MEM_XSPI0_END)) || ((addr >= SECURE_ADDR(MEM_XSPI0_START)) && (addr <= SECURE_ADDR(MEM_XSPI0_END)))
                     || ((addr >= MEM_XSPI1_START) && (addr <= MEM_XSPI1_END)) || ((addr >= SECURE_ADDR(MEM_XSPI1_START)) && (addr <= SECURE_ADDR(MEM_XSPI1_END))))
            {
                dest = addr + MEM_XSPI_LLC_OFFSET;
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
