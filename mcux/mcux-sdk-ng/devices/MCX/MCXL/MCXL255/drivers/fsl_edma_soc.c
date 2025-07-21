/*
 * Copyright 2025 NXP
 * All rights reserved.
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
extern void DMA0_CH0_DriverIRQHandler(void);
extern void DMA0_CH1_DriverIRQHandler(void);
extern void DMA0_CH2_DriverIRQHandler(void);
extern void DMA0_CH3_DriverIRQHandler(void);
extern void DMA1_CH0_DriverIRQHandler(void);
extern void DMA1_CH1_DriverIRQHandler(void);
extern void DMA1_CH2_DriverIRQHandler(void);
extern void DMA1_CH3_DriverIRQHandler(void);
extern void EDMA_DriverIRQHandler(uint32_t instance, uint32_t channel);
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief DMA instance 0, channel 0 IRQ handler.
 *
 */
void DMA0_CH0_DriverIRQHandler(void)
{
    /* Instance 0 channel 0 */
    EDMA_DriverIRQHandler(0U, 0U);
}

/*!
 * brief DMA instance 0, channel 1 IRQ handler.
 *
 */
void DMA0_CH1_DriverIRQHandler(void)
{
    /* Instance 0 channel 1 */
    EDMA_DriverIRQHandler(0U, 1U);
}

/*!
 * brief DMA instance 0, channel 2 IRQ handler.
 *
 */
void DMA0_CH2_DriverIRQHandler(void)
{
    /* Instance 0 channel 2 */
    EDMA_DriverIRQHandler(0U, 2U);
}

/*!
 * brief DMA instance 0, channel 3 IRQ handler.
 *
 */
void DMA0_CH3_DriverIRQHandler(void)
{
    /* Instance 0 channel 3 */
    EDMA_DriverIRQHandler(0U, 3U);
}

/*!
 * brief DMA instance 1, channel 0 IRQ handler.
 *
 */
void DMA1_CH0_DriverIRQHandler(void)
{
    /* Instance 1 channel 0 */
    EDMA_DriverIRQHandler(1U, 0U);
}

/*!
 * brief DMA instance 1, channel 1 IRQ handler.
 *
 */
void DMA1_CH1_DriverIRQHandler(void)
{
    /* Instance 1 channel 1 */
    EDMA_DriverIRQHandler(1U, 1U);
}

/*!
 * brief DMA instance 1, channel 2 IRQ handler.
 *
 */
void DMA1_CH2_DriverIRQHandler(void)
{
    /* Instance 1 channel 2 */
    EDMA_DriverIRQHandler(1U, 2U);
}

/*!
 * brief DMA instance 1, channel 3 IRQ handler.
 *
 */
void DMA1_CH3_DriverIRQHandler(void)
{
    /* Instance 1 channel 3 */
    EDMA_DriverIRQHandler(1U, 3U);
}
