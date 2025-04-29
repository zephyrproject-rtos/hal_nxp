/*
 * Copyright 2024 NXP
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_edma_soc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.edma_soc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern void EDMA_DriverIRQHandler(uint32_t instance, uint32_t channel);
/*******************************************************************************
 * Code
 ******************************************************************************/
/**
 * @brief EDMA instance 1, channel 0 IRQ handler.
 *
 */
void EDMA1_CH0_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 0 */
    EDMA_DriverIRQHandler(0U, 0U);
}

/**
 * @brief EDMA instance 1, channel 1 IRQ handler.
 *
 */
void EDMA1_CH1_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 1 */
    EDMA_DriverIRQHandler(0U, 1U);
}

/**
 * @brief EDMA instance 1, channel 2 IRQ handler.
 *
 */
void EDMA1_CH2_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 2 */
    EDMA_DriverIRQHandler(0U, 2U);
}

/**
 * @brief EDMA instance 1, channel 3 IRQ handler.
 *
 */
void EDMA1_CH3_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 3 */
    EDMA_DriverIRQHandler(0U, 3U);
}

/**
 * @brief EDMA instance 1, channel 4 IRQ handler.
 *
 */
void EDMA1_CH4_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 4 */
    EDMA_DriverIRQHandler(0U, 4U);
}

/**
 * @brief EDMA instance 1, channel 5 IRQ handler.
 *
 */
void EDMA1_CH5_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 5 */
    EDMA_DriverIRQHandler(0U, 5U);
}

/**
 * @brief EDMA instance 1, channel 6 IRQ handler.
 *
 */
void EDMA1_CH6_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 6 */
    EDMA_DriverIRQHandler(0U, 6U);
}

/**
 * @brief EDMA instance 1, channel 7 IRQ handler.
 *
 */
void EDMA1_CH7_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 7 */
    EDMA_DriverIRQHandler(0U, 7U);
}

/**
 * @brief EDMA instance 1, channel 8 IRQ handler.
 *
 */
void EDMA1_CH8_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 8 */
    EDMA_DriverIRQHandler(0U, 8U);
}

/**
 * @brief EDMA instance 1, channel 9 IRQ handler.
 *
 */
void EDMA1_CH9_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 9 */
    EDMA_DriverIRQHandler(0U, 9U);
}

/**
 * @brief EDMA instance 1, channel 10 IRQ handler.
 *
 */
void EDMA1_CH10_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 10 */
    EDMA_DriverIRQHandler(0U, 10U);
}

/**
 * @brief EDMA instance 1, channel 11 IRQ handler.
 *
 */
void EDMA1_CH11_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 11 */
    EDMA_DriverIRQHandler(0U, 11U);
}

/**
 * @brief EDMA instance 1, channel 12 IRQ handler.
 *
 */
void EDMA1_CH12_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 12 */
    EDMA_DriverIRQHandler(0U, 12U);
}

/**
 * @brief EDMA instance 1, channel 13 IRQ handler.
 *
 */
void EDMA1_CH13_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 13 */
    EDMA_DriverIRQHandler(0U, 13U);
}

/**
 * @brief EDMA instance 1, channel 14 IRQ handler.
 *
 */
void EDMA1_CH14_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 14 */
    EDMA_DriverIRQHandler(0U, 14U);
}

/**
 * @brief EDMA instance 1, channel 15 IRQ handler.
 *
 */
void EDMA1_CH15_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 15 */
    EDMA_DriverIRQHandler(0U, 15U);
}

/**
 * @brief EDMA instance 1, channel 16 IRQ handler.
 *
 */
void EDMA1_CH16_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 16 */
    EDMA_DriverIRQHandler(0U, 16U);
}

/**
 * @brief EDMA instance 1, channel 17 IRQ handler.
 *
 */
void EDMA1_CH17_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 17 */
    EDMA_DriverIRQHandler(0U, 17U);
}

/**
 * @brief EDMA instance 1, channel 18 IRQ handler.
 *
 */
void EDMA1_CH18_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 18 */
    EDMA_DriverIRQHandler(0U, 18U);
}

/**
 * @brief EDMA instance 1, channel 19 IRQ handler.
 *
 */
void EDMA1_CH19_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 19 */
    EDMA_DriverIRQHandler(0U, 19U);
}

/**
 * @brief EDMA instance 1, channel 20 IRQ handler.
 *
 */
void EDMA1_CH20_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 20 */
    EDMA_DriverIRQHandler(0U, 20U);
}

/**
 * @brief EDMA instance 1, channel 21 IRQ handler.
 *
 */
void EDMA1_CH21_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 21 */
    EDMA_DriverIRQHandler(0U, 21U);
}

/**
 * @brief EDMA instance 1, channel 22 IRQ handler.
 *
 */
void EDMA1_CH22_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 22 */
    EDMA_DriverIRQHandler(0U, 22U);
}

/**
 * @brief EDMA instance 1, channel 23 IRQ handler.
 *
 */
void EDMA1_CH23_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 23 */
    EDMA_DriverIRQHandler(0U, 23U);
}

/**
 * @brief EDMA instance 1, channel 24 IRQ handler.
 *
 */
void EDMA1_CH24_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 24 */
    EDMA_DriverIRQHandler(0U, 24U);
}

/**
 * @brief EDMA instance 1, channel 25 IRQ handler.
 *
 */
void EDMA1_CH25_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 25 */
    EDMA_DriverIRQHandler(0U, 25U);
}

/**
 * @brief EDMA instance 1, channel 26 IRQ handler.
 *
 */
void EDMA1_CH26_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 26 */
    EDMA_DriverIRQHandler(0U, 26U);
}

/**
 * @brief EDMA instance 1, channel 27 IRQ handler.
 *
 */
void EDMA1_CH27_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 27 */
    EDMA_DriverIRQHandler(0U, 27U);
}

/**
 * @brief EDMA instance 1, channel 28 IRQ handler.
 *
 */
void EDMA1_CH28_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 28 */
    EDMA_DriverIRQHandler(0U, 28U);
}

/**
 * @brief EDMA instance 1, channel 29 IRQ handler.
 *
 */
void EDMA1_CH29_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 29 */
    EDMA_DriverIRQHandler(0U, 29U);
}

/**
 * @brief EDMA instance 1, channel 30 IRQ handler.
 *
 */
void EDMA1_CH30_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 30 */
    EDMA_DriverIRQHandler(0U, 30U);
}

/**
 * @brief EDMA instance 1, channel 31 IRQ handler.
 *
 */
void EDMA1_CH31_DriverIRQHandler(void)
{
    /* EDMA instance 1 channel 31 */
    EDMA_DriverIRQHandler(0U, 31U);
}

/**
 * @brief EDMA instance 2, channel 0 IRQ handler.
 *
 */
void EDMA2_CH0_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 0 */
    EDMA_DriverIRQHandler(1U, 0U);
}

/**
 * @brief EDMA instance 2, channel 1 IRQ handler.
 *
 */
void EDMA2_CH1_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 1 */
    EDMA_DriverIRQHandler(1U, 1U);
}

/**
 * @brief EDMA instance 2, channel 2 IRQ handler.
 *
 */
void EDMA2_CH2_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 2 */
    EDMA_DriverIRQHandler(1U, 2U);
}

/**
 * @brief EDMA instance 2, channel 3 IRQ handler.
 *
 */
void EDMA2_CH3_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 3 */
    EDMA_DriverIRQHandler(1U, 3U);
}

/**
 * @brief EDMA instance 2, channel 4 IRQ handler.
 *
 */
void EDMA2_CH4_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 4 */
    EDMA_DriverIRQHandler(1U, 4U);
}

/**
 * @brief EDMA instance 2, channel 5 IRQ handler.
 *
 */
void EDMA2_CH5_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 5 */
    EDMA_DriverIRQHandler(1U, 5U);
}

/**
 * @brief EDMA instance 2, channel 6 IRQ handler.
 *
 */
void EDMA2_CH6_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 6 */
    EDMA_DriverIRQHandler(1U, 6U);
}

/**
 * @brief EDMA instance 2, channel 7 IRQ handler.
 *
 */
void EDMA2_CH7_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 7 */
    EDMA_DriverIRQHandler(1U, 7U);
}

/**
 * @brief EDMA instance 2, channel 8 IRQ handler.
 *
 */
void EDMA2_CH8_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 8 */
    EDMA_DriverIRQHandler(1U, 8U);
}

/**
 * @brief EDMA instance 2, channel 9 IRQ handler.
 *
 */
void EDMA2_CH9_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 9 */
    EDMA_DriverIRQHandler(1U, 9U);
}

/**
 * @brief EDMA instance 2, channel 10 IRQ handler.
 *
 */
void EDMA2_CH10_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 10 */
    EDMA_DriverIRQHandler(1U, 10U);
}

/**
 * @brief EDMA instance 2, channel 11 IRQ handler.
 *
 */
void EDMA2_CH11_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 11 */
    EDMA_DriverIRQHandler(1U, 11U);
}

/**
 * @brief EDMA instance 2, channel 12 IRQ handler.
 *
 */
void EDMA2_CH12_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 12 */
    EDMA_DriverIRQHandler(1U, 12U);
}

/**
 * @brief EDMA instance 2, channel 13 IRQ handler.
 *
 */
void EDMA2_CH13_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 13 */
    EDMA_DriverIRQHandler(1U, 13U);
}

/**
 * @brief EDMA instance 2, channel 14 IRQ handler.
 *
 */
void EDMA2_CH14_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 14 */
    EDMA_DriverIRQHandler(1U, 14U);
}

/**
 * @brief EDMA instance 2, channel 15 IRQ handler.
 *
 */
void EDMA2_CH15_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 15 */
    EDMA_DriverIRQHandler(1U, 15U);
}

/**
 * @brief EDMA instance 2, channel 16 IRQ handler.
 *
 */
void EDMA2_CH16_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 16 */
    EDMA_DriverIRQHandler(1U, 16U);
}

/**
 * @brief EDMA instance 2, channel 17 IRQ handler.
 *
 */
void EDMA2_CH17_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 17 */
    EDMA_DriverIRQHandler(1U, 17U);
}

/**
 * @brief EDMA instance 2, channel 18 IRQ handler.
 *
 */
void EDMA2_CH18_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 18 */
    EDMA_DriverIRQHandler(1U, 18U);
}

/**
 * @brief EDMA instance 2, channel 19 IRQ handler.
 *
 */
void EDMA2_CH19_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 19 */
    EDMA_DriverIRQHandler(1U, 19U);
}

/**
 * @brief EDMA instance 2, channel 20 IRQ handler.
 *
 */
void EDMA2_CH20_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 20 */
    EDMA_DriverIRQHandler(1U, 20U);
}

/**
 * @brief EDMA instance 2, channel 21 IRQ handler.
 *
 */
void EDMA2_CH21_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 21 */
    EDMA_DriverIRQHandler(1U, 21U);
}

/**
 * @brief EDMA instance 2, channel 22 IRQ handler.
 *
 */
void EDMA2_CH22_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 22 */
    EDMA_DriverIRQHandler(1U, 22U);
}

/**
 * @brief EDMA instance 2, channel 23 IRQ handler.
 *
 */
void EDMA2_CH23_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 23 */
    EDMA_DriverIRQHandler(1U, 23U);
}

/**
 * @brief EDMA instance 2, channel 24 IRQ handler.
 *
 */
void EDMA2_CH24_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 24 */
    EDMA_DriverIRQHandler(1U, 24U);
}

/**
 * @brief EDMA instance 2, channel 25 IRQ handler.
 *
 */
void EDMA2_CH25_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 25 */
    EDMA_DriverIRQHandler(1U, 25U);
}

/**
 * @brief EDMA instance 2, channel 26 IRQ handler.
 *
 */
void EDMA2_CH26_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 26 */
    EDMA_DriverIRQHandler(1U, 26U);
}

/**
 * @brief EDMA instance 2, channel 27 IRQ handler.
 *
 */
void EDMA2_CH27_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 27 */
    EDMA_DriverIRQHandler(1U, 27U);
}

/**
 * @brief EDMA instance 2, channel 28 IRQ handler.
 *
 */
void EDMA2_CH28_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 28 */
    EDMA_DriverIRQHandler(1U, 28U);
}

/**
 * @brief EDMA instance 2, channel 29 IRQ handler.
 *
 */
void EDMA2_CH29_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 29 */
    EDMA_DriverIRQHandler(1U, 29U);
}

/**
 * @brief EDMA instance 2, channel 30 IRQ handler.
 *
 */
void EDMA2_CH30_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 30 */
    EDMA_DriverIRQHandler(1U, 30U);
}

/**
 * @brief EDMA instance 2, channel 31 IRQ handler.
 *
 */
void EDMA2_CH31_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 31 */
    EDMA_DriverIRQHandler(1U, 31U);
}

/**
 * @brief EDMA instance 2, channel 32 IRQ handler.
 *
 */
void EDMA2_CH32_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 32 */
    EDMA_DriverIRQHandler(1U, 32U);
}

/**
 * @brief EDMA instance 2, channel 33 IRQ handler.
 *
 */
void EDMA2_CH33_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 33 */
    EDMA_DriverIRQHandler(1U, 33U);
}

/**
 * @brief EDMA instance 2, channel 34 IRQ handler.
 *
 */
void EDMA2_CH34_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 34 */
    EDMA_DriverIRQHandler(1U, 34U);
}

/**
 * @brief EDMA instance 2, channel 35 IRQ handler.
 *
 */
void EDMA2_CH35_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 35 */
    EDMA_DriverIRQHandler(1U, 35U);
}

/**
 * @brief EDMA instance 2, channel 36 IRQ handler.
 *
 */
void EDMA2_CH36_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 36 */
    EDMA_DriverIRQHandler(1U, 36U);
}

/**
 * @brief EDMA instance 2, channel 37 IRQ handler.
 *
 */
void EDMA2_CH37_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 37 */
    EDMA_DriverIRQHandler(1U, 37U);
}

/**
 * @brief EDMA instance 2, channel 38 IRQ handler.
 *
 */
void EDMA2_CH38_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 38 */
    EDMA_DriverIRQHandler(1U, 38U);
}

/**
 * @brief EDMA instance 2, channel 39 IRQ handler.
 *
 */
void EDMA2_CH39_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 39 */
    EDMA_DriverIRQHandler(1U, 39U);
}

/**
 * @brief EDMA instance 2, channel 40 IRQ handler.
 *
 */
void EDMA2_CH40_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 40 */
    EDMA_DriverIRQHandler(1U, 40U);
}

/**
 * @brief EDMA instance 2, channel 41 IRQ handler.
 *
 */
void EDMA2_CH41_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 41 */
    EDMA_DriverIRQHandler(1U, 41U);
}

/**
 * @brief EDMA instance 2, channel 42 IRQ handler.
 *
 */
void EDMA2_CH42_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 42 */
    EDMA_DriverIRQHandler(1U, 42U);
}

/**
 * @brief EDMA instance 2, channel 43 IRQ handler.
 *
 */
void EDMA2_CH43_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 43 */
    EDMA_DriverIRQHandler(1U, 43U);
}

/**
 * @brief EDMA instance 2, channel 44 IRQ handler.
 *
 */
void EDMA2_CH44_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 44 */
    EDMA_DriverIRQHandler(1U, 44U);
}

/**
 * @brief EDMA instance 2, channel 45 IRQ handler.
 *
 */
void EDMA2_CH45_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 45 */
    EDMA_DriverIRQHandler(1U, 45U);
}

/**
 * @brief EDMA instance 2, channel 46 IRQ handler.
 *
 */
void EDMA2_CH46_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 46 */
    EDMA_DriverIRQHandler(1U, 46U);
}

/**
 * @brief EDMA instance 2, channel 47 IRQ handler.
 *
 */
void EDMA2_CH47_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 47 */
    EDMA_DriverIRQHandler(1U, 47U);
}

/**
 * @brief EDMA instance 2, channel 48 IRQ handler.
 *
 */
void EDMA2_CH48_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 48 */
    EDMA_DriverIRQHandler(1U, 48U);
}

/**
 * @brief EDMA instance 2, channel 49 IRQ handler.
 *
 */
void EDMA2_CH49_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 49 */
    EDMA_DriverIRQHandler(1U, 49U);
}

/**
 * @brief EDMA instance 2, channel 50 IRQ handler.
 *
 */
void EDMA2_CH50_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 50 */
    EDMA_DriverIRQHandler(1U, 50U);
}

/**
 * @brief EDMA instance 2, channel 51 IRQ handler.
 *
 */
void EDMA2_CH51_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 51 */
    EDMA_DriverIRQHandler(1U, 51U);
}

/**
 * @brief EDMA instance 2, channel 52 IRQ handler.
 *
 */
void EDMA2_CH52_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 52 */
    EDMA_DriverIRQHandler(1U, 52U);
}

/**
 * @brief EDMA instance 2, channel 53 IRQ handler.
 *
 */
void EDMA2_CH53_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 53 */
    EDMA_DriverIRQHandler(1U, 53U);
}

/**
 * @brief EDMA instance 2, channel 54 IRQ handler.
 *
 */
void EDMA2_CH54_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 54 */
    EDMA_DriverIRQHandler(1U, 54U);
}

/**
 * @brief EDMA instance 2, channel 55 IRQ handler.
 *
 */
void EDMA2_CH55_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 55 */
    EDMA_DriverIRQHandler(1U, 55U);
}

/**
 * @brief EDMA instance 2, channel 56 IRQ handler.
 *
 */
void EDMA2_CH56_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 56 */
    EDMA_DriverIRQHandler(1U, 56U);
}

/**
 * @brief EDMA instance 2, channel 57 IRQ handler.
 *
 */
void EDMA2_CH57_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 57 */
    EDMA_DriverIRQHandler(1U, 57U);
}

/**
 * @brief EDMA instance 2, channel 58 IRQ handler.
 *
 */
void EDMA2_CH58_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 58 */
    EDMA_DriverIRQHandler(1U, 58U);
}

/**
 * @brief EDMA instance 2, channel 59 IRQ handler.
 *
 */
void EDMA2_CH59_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 59 */
    EDMA_DriverIRQHandler(1U, 59U);
}

/**
 * @brief EDMA instance 2, channel 60 IRQ handler.
 *
 */
void EDMA2_CH60_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 60 */
    EDMA_DriverIRQHandler(1U, 60U);
}

/**
 * @brief EDMA instance 2, channel 61 IRQ handler.
 *
 */
void EDMA2_CH61_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 61 */
    EDMA_DriverIRQHandler(1U, 61U);
}

/**
 * @brief EDMA instance 2, channel 62 IRQ handler.
 *
 */
void EDMA2_CH62_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 62 */
    EDMA_DriverIRQHandler(1U, 62U);
}

/**
 * @brief EDMA instance 2, channel 63 IRQ handler.
 *
 */
void EDMA2_CH63_DriverIRQHandler(void)
{
    /* EDMA instance 2 channel 63 */
    EDMA_DriverIRQHandler(1U, 63U);
}

/**
 * @brief EDMA instance 3, channel 0 IRQ handler.
 *
 */
void EDMA3_CH0_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 0 */
    EDMA_DriverIRQHandler(2U, 0U);
}

/**
 * @brief EDMA instance 3, channel 1 IRQ handler.
 *
 */
void EDMA3_CH1_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 1 */
    EDMA_DriverIRQHandler(2U, 1U);
}

/**
 * @brief EDMA instance 3, channel 2 IRQ handler.
 *
 */
void EDMA3_CH2_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 2 */
    EDMA_DriverIRQHandler(2U, 2U);
}

/**
 * @brief EDMA instance 3, channel 3 IRQ handler.
 *
 */
void EDMA3_CH3_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 3 */
    EDMA_DriverIRQHandler(2U, 3U);
}

/**
 * @brief EDMA instance 3, channel 4 IRQ handler.
 *
 */
void EDMA3_CH4_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 4 */
    EDMA_DriverIRQHandler(2U, 4U);
}

/**
 * @brief EDMA instance 3, channel 5 IRQ handler.
 *
 */
void EDMA3_CH5_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 5 */
    EDMA_DriverIRQHandler(2U, 5U);
}

/**
 * @brief EDMA instance 3, channel 6 IRQ handler.
 *
 */
void EDMA3_CH6_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 6 */
    EDMA_DriverIRQHandler(2U, 6U);
}

/**
 * @brief EDMA instance 3, channel 7 IRQ handler.
 *
 */
void EDMA3_CH7_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 7 */
    EDMA_DriverIRQHandler(2U, 7U);
}

/**
 * @brief EDMA instance 3, channel 8 IRQ handler.
 *
 */
void EDMA3_CH8_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 8 */
    EDMA_DriverIRQHandler(2U, 8U);
}

/**
 * @brief EDMA instance 3, channel 9 IRQ handler.
 *
 */
void EDMA3_CH9_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 9 */
    EDMA_DriverIRQHandler(2U, 9U);
}

/**
 * @brief EDMA instance 3, channel 10 IRQ handler.
 *
 */
void EDMA3_CH10_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 10 */
    EDMA_DriverIRQHandler(2U, 10U);
}

/**
 * @brief EDMA instance 3, channel 11 IRQ handler.
 *
 */
void EDMA3_CH11_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 11 */
    EDMA_DriverIRQHandler(2U, 11U);
}

/**
 * @brief EDMA instance 3, channel 12 IRQ handler.
 *
 */
void EDMA3_CH12_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 12 */
    EDMA_DriverIRQHandler(2U, 12U);
}

/**
 * @brief EDMA instance 3, channel 13 IRQ handler.
 *
 */
void EDMA3_CH13_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 13 */
    EDMA_DriverIRQHandler(2U, 13U);
}

/**
 * @brief EDMA instance 3, channel 14 IRQ handler.
 *
 */
void EDMA3_CH14_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 14 */
    EDMA_DriverIRQHandler(2U, 14U);
}

/**
 * @brief EDMA instance 3, channel 15 IRQ handler.
 *
 */
void EDMA3_CH15_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 15 */
    EDMA_DriverIRQHandler(2U, 15U);
}

/**
 * @brief EDMA instance 3, channel 16 IRQ handler.
 *
 */
void EDMA3_CH16_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 16 */
    EDMA_DriverIRQHandler(2U, 16U);
}

/**
 * @brief EDMA instance 3, channel 17 IRQ handler.
 *
 */
void EDMA3_CH17_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 17 */
    EDMA_DriverIRQHandler(2U, 17U);
}

/**
 * @brief EDMA instance 3, channel 18 IRQ handler.
 *
 */
void EDMA3_CH18_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 18 */
    EDMA_DriverIRQHandler(2U, 18U);
}

/**
 * @brief EDMA instance 3, channel 19 IRQ handler.
 *
 */
void EDMA3_CH19_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 19 */
    EDMA_DriverIRQHandler(2U, 19U);
}

/**
 * @brief EDMA instance 3, channel 20 IRQ handler.
 *
 */
void EDMA3_CH20_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 20 */
    EDMA_DriverIRQHandler(2U, 20U);
}

/**
 * @brief EDMA instance 3, channel 21 IRQ handler.
 *
 */
void EDMA3_CH21_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 21 */
    EDMA_DriverIRQHandler(2U, 21U);
}

/**
 * @brief EDMA instance 3, channel 22 IRQ handler.
 *
 */
void EDMA3_CH22_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 22 */
    EDMA_DriverIRQHandler(2U, 22U);
}

/**
 * @brief EDMA instance 3, channel 23 IRQ handler.
 *
 */
void EDMA3_CH23_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 23 */
    EDMA_DriverIRQHandler(2U, 23U);
}

/**
 * @brief EDMA instance 3, channel 24 IRQ handler.
 *
 */
void EDMA3_CH24_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 24 */
    EDMA_DriverIRQHandler(2U, 24U);
}

/**
 * @brief EDMA instance 3, channel 25 IRQ handler.
 *
 */
void EDMA3_CH25_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 25 */
    EDMA_DriverIRQHandler(2U, 25U);
}

/**
 * @brief EDMA instance 3, channel 26 IRQ handler.
 *
 */
void EDMA3_CH26_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 26 */
    EDMA_DriverIRQHandler(2U, 26U);
}

/**
 * @brief EDMA instance 3, channel 27 IRQ handler.
 *
 */
void EDMA3_CH27_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 27 */
    EDMA_DriverIRQHandler(2U, 27U);
}

/**
 * @brief EDMA instance 3, channel 28 IRQ handler.
 *
 */
void EDMA3_CH28_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 28 */
    EDMA_DriverIRQHandler(2U, 28U);
}

/**
 * @brief EDMA instance 3, channel 29 IRQ handler.
 *
 */
void EDMA3_CH29_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 29 */
    EDMA_DriverIRQHandler(2U, 29U);
}

/**
 * @brief EDMA instance 3, channel 30 IRQ handler.
 *
 */
void EDMA3_CH30_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 30 */
    EDMA_DriverIRQHandler(2U, 30U);
}

/**
 * @brief EDMA instance 3, channel 31 IRQ handler.
 *
 */
void EDMA3_CH31_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 31 */
    EDMA_DriverIRQHandler(2U, 31U);
}

/**
 * @brief EDMA instance 3, channel 32 IRQ handler.
 *
 */
void EDMA3_CH32_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 32 */
    EDMA_DriverIRQHandler(2U, 32U);
}

/**
 * @brief EDMA instance 3, channel 33 IRQ handler.
 *
 */
void EDMA3_CH33_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 33 */
    EDMA_DriverIRQHandler(2U, 33U);
}

/**
 * @brief EDMA instance 3, channel 34 IRQ handler.
 *
 */
void EDMA3_CH34_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 34 */
    EDMA_DriverIRQHandler(2U, 34U);
}

/**
 * @brief EDMA instance 3, channel 35 IRQ handler.
 *
 */
void EDMA3_CH35_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 35 */
    EDMA_DriverIRQHandler(2U, 35U);
}

/**
 * @brief EDMA instance 3, channel 36 IRQ handler.
 *
 */
void EDMA3_CH36_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 36 */
    EDMA_DriverIRQHandler(2U, 36U);
}

/**
 * @brief EDMA instance 3, channel 37 IRQ handler.
 *
 */
void EDMA3_CH37_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 37 */
    EDMA_DriverIRQHandler(2U, 37U);
}

/**
 * @brief EDMA instance 3, channel 38 IRQ handler.
 *
 */
void EDMA3_CH38_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 38 */
    EDMA_DriverIRQHandler(2U, 38U);
}

/**
 * @brief EDMA instance 3, channel 39 IRQ handler.
 *
 */
void EDMA3_CH39_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 39 */
    EDMA_DriverIRQHandler(2U, 39U);
}

/**
 * @brief EDMA instance 3, channel 40 IRQ handler.
 *
 */
void EDMA3_CH40_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 40 */
    EDMA_DriverIRQHandler(2U, 40U);
}

/**
 * @brief EDMA instance 3, channel 41 IRQ handler.
 *
 */
void EDMA3_CH41_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 41 */
    EDMA_DriverIRQHandler(2U, 41U);
}

/**
 * @brief EDMA instance 3, channel 42 IRQ handler.
 *
 */
void EDMA3_CH42_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 42 */
    EDMA_DriverIRQHandler(2U, 42U);
}

/**
 * @brief EDMA instance 3, channel 43 IRQ handler.
 *
 */
void EDMA3_CH43_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 43 */
    EDMA_DriverIRQHandler(2U, 43U);
}

/**
 * @brief EDMA instance 3, channel 44 IRQ handler.
 *
 */
void EDMA3_CH44_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 44 */
    EDMA_DriverIRQHandler(2U, 44U);
}

/**
 * @brief EDMA instance 3, channel 45 IRQ handler.
 *
 */
void EDMA3_CH45_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 45 */
    EDMA_DriverIRQHandler(2U, 45U);
}

/**
 * @brief EDMA instance 3, channel 46 IRQ handler.
 *
 */
void EDMA3_CH46_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 46 */
    EDMA_DriverIRQHandler(2U, 46U);
}

/**
 * @brief EDMA instance 3, channel 47 IRQ handler.
 *
 */
void EDMA3_CH47_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 47 */
    EDMA_DriverIRQHandler(2U, 47U);
}

/**
 * @brief EDMA instance 3, channel 48 IRQ handler.
 *
 */
void EDMA3_CH48_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 48 */
    EDMA_DriverIRQHandler(2U, 48U);
}

/**
 * @brief EDMA instance 3, channel 49 IRQ handler.
 *
 */
void EDMA3_CH49_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 49 */
    EDMA_DriverIRQHandler(2U, 49U);
}

/**
 * @brief EDMA instance 3, channel 50 IRQ handler.
 *
 */
void EDMA3_CH50_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 50 */
    EDMA_DriverIRQHandler(2U, 50U);
}

/**
 * @brief EDMA instance 3, channel 51 IRQ handler.
 *
 */
void EDMA3_CH51_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 51 */
    EDMA_DriverIRQHandler(2U, 51U);
}

/**
 * @brief EDMA instance 3, channel 52 IRQ handler.
 *
 */
void EDMA3_CH52_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 52 */
    EDMA_DriverIRQHandler(2U, 52U);
}

/**
 * @brief EDMA instance 3, channel 53 IRQ handler.
 *
 */
void EDMA3_CH53_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 53 */
    EDMA_DriverIRQHandler(2U, 53U);
}

/**
 * @brief EDMA instance 3, channel 54 IRQ handler.
 *
 */
void EDMA3_CH54_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 54 */
    EDMA_DriverIRQHandler(2U, 54U);
}

/**
 * @brief EDMA instance 3, channel 55 IRQ handler.
 *
 */
void EDMA3_CH55_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 55 */
    EDMA_DriverIRQHandler(2U, 55U);
}

/**
 * @brief EDMA instance 3, channel 56 IRQ handler.
 *
 */
void EDMA3_CH56_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 56 */
    EDMA_DriverIRQHandler(2U, 56U);
}

/**
 * @brief EDMA instance 3, channel 57 IRQ handler.
 *
 */
void EDMA3_CH57_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 57 */
    EDMA_DriverIRQHandler(2U, 57U);
}

/**
 * @brief EDMA instance 3, channel 58 IRQ handler.
 *
 */
void EDMA3_CH58_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 58 */
    EDMA_DriverIRQHandler(2U, 58U);
}

/**
 * @brief EDMA instance 3, channel 59 IRQ handler.
 *
 */
void EDMA3_CH59_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 59 */
    EDMA_DriverIRQHandler(2U, 59U);
}

/**
 * @brief EDMA instance 3, channel 60 IRQ handler.
 *
 */
void EDMA3_CH60_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 60 */
    EDMA_DriverIRQHandler(2U, 60U);
}

/**
 * @brief EDMA instance 3, channel 61 IRQ handler.
 *
 */
void EDMA3_CH61_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 61 */
    EDMA_DriverIRQHandler(2U, 61U);
}

/**
 * @brief EDMA instance 3, channel 62 IRQ handler.
 *
 */
void EDMA3_CH62_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 62 */
    EDMA_DriverIRQHandler(2U, 62U);
}

/**
 * @brief EDMA instance 3, channel 63 IRQ handler.
 *
 */
void EDMA3_CH63_DriverIRQHandler(void)
{
    /* EDMA instance 3 channel 63 */
    EDMA_DriverIRQHandler(2U, 63U);
}

/**
 * @brief EDMA instance 4, channel 0 IRQ handler.
 *
 */
void EDMA4_CH0_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 0 */
    EDMA_DriverIRQHandler(3U, 0U);
}

/**
 * @brief EDMA instance 4, channel 1 IRQ handler.
 *
 */
void EDMA4_CH1_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 1 */
    EDMA_DriverIRQHandler(3U, 1U);
}

/**
 * @brief EDMA instance 4, channel 2 IRQ handler.
 *
 */
void EDMA4_CH2_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 2 */
    EDMA_DriverIRQHandler(3U, 2U);
}

/**
 * @brief EDMA instance 4, channel 3 IRQ handler.
 *
 */
void EDMA4_CH3_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 3 */
    EDMA_DriverIRQHandler(3U, 3U);
}

/**
 * @brief EDMA instance 4, channel 4 IRQ handler.
 *
 */
void EDMA4_CH4_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 4 */
    EDMA_DriverIRQHandler(3U, 4U);
}

/**
 * @brief EDMA instance 4, channel 5 IRQ handler.
 *
 */
void EDMA4_CH5_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 5 */
    EDMA_DriverIRQHandler(3U, 5U);
}

/**
 * @brief EDMA instance 4, channel 6 IRQ handler.
 *
 */
void EDMA4_CH6_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 6 */
    EDMA_DriverIRQHandler(3U, 6U);
}

/**
 * @brief EDMA instance 4, channel 7 IRQ handler.
 *
 */
void EDMA4_CH7_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 7 */
    EDMA_DriverIRQHandler(3U, 7U);
}

/**
 * @brief EDMA instance 4, channel 8 IRQ handler.
 *
 */
void EDMA4_CH8_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 8 */
    EDMA_DriverIRQHandler(3U, 8U);
}

/**
 * @brief EDMA instance 4, channel 9 IRQ handler.
 *
 */
void EDMA4_CH9_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 9 */
    EDMA_DriverIRQHandler(3U, 9U);
}

/**
 * @brief EDMA instance 4, channel 10 IRQ handler.
 *
 */
void EDMA4_CH10_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 10 */
    EDMA_DriverIRQHandler(3U, 10U);
}

/**
 * @brief EDMA instance 4, channel 11 IRQ handler.
 *
 */
void EDMA4_CH11_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 11 */
    EDMA_DriverIRQHandler(3U, 11U);
}

/**
 * @brief EDMA instance 4, channel 12 IRQ handler.
 *
 */
void EDMA4_CH12_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 12 */
    EDMA_DriverIRQHandler(3U, 12U);
}

/**
 * @brief EDMA instance 4, channel 13 IRQ handler.
 *
 */
void EDMA4_CH13_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 13 */
    EDMA_DriverIRQHandler(3U, 13U);
}

/**
 * @brief EDMA instance 4, channel 14 IRQ handler.
 *
 */
void EDMA4_CH14_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 14 */
    EDMA_DriverIRQHandler(3U, 14U);
}

/**
 * @brief EDMA instance 4, channel 15 IRQ handler.
 *
 */
void EDMA4_CH15_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 15 */
    EDMA_DriverIRQHandler(3U, 15U);
}

/**
 * @brief EDMA instance 4, channel 16 IRQ handler.
 *
 */
void EDMA4_CH16_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 16 */
    EDMA_DriverIRQHandler(3U, 16U);
}

/**
 * @brief EDMA instance 4, channel 17 IRQ handler.
 *
 */
void EDMA4_CH17_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 17 */
    EDMA_DriverIRQHandler(3U, 17U);
}

/**
 * @brief EDMA instance 4, channel 18 IRQ handler.
 *
 */
void EDMA4_CH18_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 18 */
    EDMA_DriverIRQHandler(3U, 18U);
}

/**
 * @brief EDMA instance 4, channel 19 IRQ handler.
 *
 */
void EDMA4_CH19_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 19 */
    EDMA_DriverIRQHandler(3U, 19U);
}

/**
 * @brief EDMA instance 4, channel 20 IRQ handler.
 *
 */
void EDMA4_CH20_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 20 */
    EDMA_DriverIRQHandler(3U, 20U);
}

/**
 * @brief EDMA instance 4, channel 21 IRQ handler.
 *
 */
void EDMA4_CH21_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 21 */
    EDMA_DriverIRQHandler(3U, 21U);
}

/**
 * @brief EDMA instance 4, channel 22 IRQ handler.
 *
 */
void EDMA4_CH22_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 22 */
    EDMA_DriverIRQHandler(3U, 22U);
}

/**
 * @brief EDMA instance 4, channel 23 IRQ handler.
 *
 */
void EDMA4_CH23_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 23 */
    EDMA_DriverIRQHandler(3U, 23U);
}

/**
 * @brief EDMA instance 4, channel 24 IRQ handler.
 *
 */
void EDMA4_CH24_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 24 */
    EDMA_DriverIRQHandler(3U, 24U);
}

/**
 * @brief EDMA instance 4, channel 25 IRQ handler.
 *
 */
void EDMA4_CH25_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 25 */
    EDMA_DriverIRQHandler(3U, 25U);
}

/**
 * @brief EDMA instance 4, channel 26 IRQ handler.
 *
 */
void EDMA4_CH26_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 26 */
    EDMA_DriverIRQHandler(3U, 26U);
}

/**
 * @brief EDMA instance 4, channel 27 IRQ handler.
 *
 */
void EDMA4_CH27_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 27 */
    EDMA_DriverIRQHandler(3U, 27U);
}

/**
 * @brief EDMA instance 4, channel 28 IRQ handler.
 *
 */
void EDMA4_CH28_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 28 */
    EDMA_DriverIRQHandler(3U, 28U);
}

/**
 * @brief EDMA instance 4, channel 29 IRQ handler.
 *
 */
void EDMA4_CH29_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 29 */
    EDMA_DriverIRQHandler(3U, 29U);
}

/**
 * @brief EDMA instance 4, channel 30 IRQ handler.
 *
 */
void EDMA4_CH30_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 30 */
    EDMA_DriverIRQHandler(3U, 30U);
}

/**
 * @brief EDMA instance 4, channel 31 IRQ handler.
 *
 */
void EDMA4_CH31_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 31 */
    EDMA_DriverIRQHandler(3U, 31U);
}

/**
 * @brief EDMA instance 4, channel 32 IRQ handler.
 *
 */
void EDMA4_CH32_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 32 */
    EDMA_DriverIRQHandler(3U, 32U);
}

/**
 * @brief EDMA instance 4, channel 33 IRQ handler.
 *
 */
void EDMA4_CH33_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 33 */
    EDMA_DriverIRQHandler(3U, 33U);
}

/**
 * @brief EDMA instance 4, channel 34 IRQ handler.
 *
 */
void EDMA4_CH34_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 34 */
    EDMA_DriverIRQHandler(3U, 34U);
}

/**
 * @brief EDMA instance 4, channel 35 IRQ handler.
 *
 */
void EDMA4_CH35_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 35 */
    EDMA_DriverIRQHandler(3U, 35U);
}

/**
 * @brief EDMA instance 4, channel 36 IRQ handler.
 *
 */
void EDMA4_CH36_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 36 */
    EDMA_DriverIRQHandler(3U, 36U);
}

/**
 * @brief EDMA instance 4, channel 37 IRQ handler.
 *
 */
void EDMA4_CH37_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 37 */
    EDMA_DriverIRQHandler(3U, 37U);
}

/**
 * @brief EDMA instance 4, channel 38 IRQ handler.
 *
 */
void EDMA4_CH38_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 38 */
    EDMA_DriverIRQHandler(3U, 38U);
}

/**
 * @brief EDMA instance 4, channel 39 IRQ handler.
 *
 */
void EDMA4_CH39_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 39 */
    EDMA_DriverIRQHandler(3U, 39U);
}

/**
 * @brief EDMA instance 4, channel 40 IRQ handler.
 *
 */
void EDMA4_CH40_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 40 */
    EDMA_DriverIRQHandler(3U, 40U);
}

/**
 * @brief EDMA instance 4, channel 41 IRQ handler.
 *
 */
void EDMA4_CH41_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 41 */
    EDMA_DriverIRQHandler(3U, 41U);
}

/**
 * @brief EDMA instance 4, channel 42 IRQ handler.
 *
 */
void EDMA4_CH42_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 42 */
    EDMA_DriverIRQHandler(3U, 42U);
}

/**
 * @brief EDMA instance 4, channel 43 IRQ handler.
 *
 */
void EDMA4_CH43_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 43 */
    EDMA_DriverIRQHandler(3U, 43U);
}

/**
 * @brief EDMA instance 4, channel 44 IRQ handler.
 *
 */
void EDMA4_CH44_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 44 */
    EDMA_DriverIRQHandler(3U, 44U);
}

/**
 * @brief EDMA instance 4, channel 45 IRQ handler.
 *
 */
void EDMA4_CH45_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 45 */
    EDMA_DriverIRQHandler(3U, 45U);
}

/**
 * @brief EDMA instance 4, channel 46 IRQ handler.
 *
 */
void EDMA4_CH46_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 46 */
    EDMA_DriverIRQHandler(3U, 46U);
}

/**
 * @brief EDMA instance 4, channel 47 IRQ handler.
 *
 */
void EDMA4_CH47_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 47 */
    EDMA_DriverIRQHandler(3U, 47U);
}

/**
 * @brief EDMA instance 4, channel 48 IRQ handler.
 *
 */
void EDMA4_CH48_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 48 */
    EDMA_DriverIRQHandler(3U, 48U);
}

/**
 * @brief EDMA instance 4, channel 49 IRQ handler.
 *
 */
void EDMA4_CH49_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 49 */
    EDMA_DriverIRQHandler(3U, 49U);
}

/**
 * @brief EDMA instance 4, channel 50 IRQ handler.
 *
 */
void EDMA4_CH50_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 50 */
    EDMA_DriverIRQHandler(3U, 50U);
}

/**
 * @brief EDMA instance 4, channel 51 IRQ handler.
 *
 */
void EDMA4_CH51_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 51 */
    EDMA_DriverIRQHandler(3U, 51U);
}

/**
 * @brief EDMA instance 4, channel 52 IRQ handler.
 *
 */
void EDMA4_CH52_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 52 */
    EDMA_DriverIRQHandler(3U, 52U);
}

/**
 * @brief EDMA instance 4, channel 53 IRQ handler.
 *
 */
void EDMA4_CH53_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 53 */
    EDMA_DriverIRQHandler(3U, 53U);
}

/**
 * @brief EDMA instance 4, channel 54 IRQ handler.
 *
 */
void EDMA4_CH54_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 54 */
    EDMA_DriverIRQHandler(3U, 54U);
}

/**
 * @brief EDMA instance 4, channel 55 IRQ handler.
 *
 */
void EDMA4_CH55_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 55 */
    EDMA_DriverIRQHandler(3U, 55U);
}

/**
 * @brief EDMA instance 4, channel 56 IRQ handler.
 *
 */
void EDMA4_CH56_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 56 */
    EDMA_DriverIRQHandler(3U, 56U);
}

/**
 * @brief EDMA instance 4, channel 57 IRQ handler.
 *
 */
void EDMA4_CH57_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 57 */
    EDMA_DriverIRQHandler(3U, 57U);
}

/**
 * @brief EDMA instance 4, channel 58 IRQ handler.
 *
 */
void EDMA4_CH58_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 58 */
    EDMA_DriverIRQHandler(3U, 58U);
}

/**
 * @brief EDMA instance 4, channel 59 IRQ handler.
 *
 */
void EDMA4_CH59_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 59 */
    EDMA_DriverIRQHandler(3U, 59U);
}

/**
 * @brief EDMA instance 4, channel 60 IRQ handler.
 *
 */
void EDMA4_CH60_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 60 */
    EDMA_DriverIRQHandler(3U, 60U);
}

/**
 * @brief EDMA instance 4, channel 61 IRQ handler.
 *
 */
void EDMA4_CH61_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 61 */
    EDMA_DriverIRQHandler(3U, 61U);
}

/**
 * @brief EDMA instance 4, channel 62 IRQ handler.
 *
 */
void EDMA4_CH62_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 62 */
    EDMA_DriverIRQHandler(3U, 62U);
}

/**
 * @brief EDMA instance 4, channel 63 IRQ handler.
 *
 */
void EDMA4_CH63_DriverIRQHandler(void)
{
    /* EDMA instance 4 channel 63 */
    EDMA_DriverIRQHandler(3U, 63U);
}

