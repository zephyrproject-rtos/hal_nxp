/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_ldb.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.ldb_1"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Initializes the LDB module for LVDS port panel.
 *
 * param base LDB peripheral base address.
 * param diIndex Display Input index.
 * param dualpanelIndex dual panel index.
 * param datamap 0 for SPWG 1 for JEIDA.
 */
void LDB_Init(LDB_Type *base, uint8_t diIndex, uint8_t dualpanelIndex, uint8_t datamap)
{
    assert(diIndex < LVDS_DI_COUNT);
    assert(dualpanelIndex < LVDS_DI_COUNT);

    if (1U == dualpanelIndex)
    {
        /* Set PHY clock frequency is equal to PLL clock freq/2 for LVDS dual panel */
        base->LVDS_PHY_CLOCK_CONTROL |= LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_MASK;
        base->PIXEL_MAPPER_CONTROL |= LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE(0x1);
    }
    else
    {
        base->PIXEL_MAPPER_CONTROL |= LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE(0x0);
    }

    if (LVDS_JEIDA == datamap)
    {
        base->PIXEL_MAPPER_CONTROL |= LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING(0x1) /* Set LVDS0 bitmap as JEIDA standard */
                            | LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING(0x1);        /* Set LVDS1 bitmap as JEIDA standard */
    }
    else
    {
        base->PIXEL_MAPPER_CONTROL |= LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING(0x0) /* Set LVDS0 bitmap as SPWG standard */
                            | LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING(0x0);  /* Set LVDS1 bitmap as SPWG standard */
    }

    base->PIXEL_MAPPER_CONTROL |=
        LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH(0x1)      /* 24 bit data width for lvds0 */
        | LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH(0x1);      /* 24 bit data width for lvds1 */

    /* Choose LVDS port route to display Input 0 */
    if (0U == diIndex)
    {
        base->PIXEL_MAPPER_CONTROL |= (LDB_PIXEL_MAPPER_CONTROL_CH0_MODE(0x1) | LDB_PIXEL_MAPPER_CONTROL_CH1_MODE(0x1) \
                                   | LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY(0x1));
    }
    /* Choose LVDS port route to display Input 1*/
    else
    {
        base->PIXEL_MAPPER_CONTROL |= (LDB_PIXEL_MAPPER_CONTROL_CH0_MODE(0x3) | LDB_PIXEL_MAPPER_CONTROL_CH1_MODE(0x3) \
                                   | LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY(0x1));
    }

    /* Disable LVDS ports */
    base->LVDS0_CONTROL = LDB_LVDS0_CONTROL_CH0_EN(0x1) |
                          LDB_LVDS0_CONTROL_LVDS_EN(0x1) |
                          LDB_LVDS0_CONTROL_BG_EN(0x1);
    base->LVDS1_CONTROL = LDB_LVDS1_CONTROL_CH0_EN(0x1) |
                          LDB_LVDS1_CONTROL_LVDS_EN(0x1) |
                          LDB_LVDS1_CONTROL_BG_EN(0x1);

    /* Delay before restart LVDS ports */
    SDK_DelayAtLeastUs(100000, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    /* Enable LVDS ports and port configration */
    base->LVDS0_CONTROL =
        LDB_LVDS0_CONTROL_CH0_EN(0x1) | LDB_LVDS0_CONTROL_BG_EN(0x1) |
        LDB_LVDS0_CONTROL_PRE_EMPH_EN(0x1) | LDB_LVDS0_CONTROL_PRE_EMPH_ADJ(0x3) |
        LDB_LVDS0_CONTROL_CC_ADJ(0x2);
    base->LVDS1_CONTROL =
        LDB_LVDS1_CONTROL_CH0_EN(0x1) | LDB_LVDS1_CONTROL_BG_EN(0x1) |
        LDB_LVDS1_CONTROL_PRE_EMPH_EN(0x1) | LDB_LVDS1_CONTROL_PRE_EMPH_ADJ(0x3) |
        LDB_LVDS1_CONTROL_CC_ADJ(0x2);
}
