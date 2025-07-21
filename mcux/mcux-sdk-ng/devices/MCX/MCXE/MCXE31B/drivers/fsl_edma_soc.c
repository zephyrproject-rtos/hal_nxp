/*
 * Copyright 2025 NXP
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
extern void DMATCD0_DriverIRQHandler(void);
extern void DMATCD1_DriverIRQHandler(void);
extern void DMATCD2_DriverIRQHandler(void);
extern void DMATCD3_DriverIRQHandler(void);
extern void DMATCD4_DriverIRQHandler(void);
extern void DMATCD5_DriverIRQHandler(void);
extern void DMATCD6_DriverIRQHandler(void);
extern void DMATCD7_DriverIRQHandler(void);
extern void DMATCD8_DriverIRQHandler(void);
extern void DMATCD9_DriverIRQHandler(void);
extern void DMATCD10_DriverIRQHandler(void);
extern void DMATCD11_DriverIRQHandler(void);
#if (FSL_FEATURE_EDMA_MODULE_CHANNEL > 12U)
extern void DMATCD12_DriverIRQHandler(void);
extern void DMATCD13_DriverIRQHandler(void);
extern void DMATCD14_DriverIRQHandler(void);
extern void DMATCD15_DriverIRQHandler(void);
extern void DMATCD16_DriverIRQHandler(void);
extern void DMATCD17_DriverIRQHandler(void);
extern void DMATCD18_DriverIRQHandler(void);
extern void DMATCD19_DriverIRQHandler(void);
extern void DMATCD20_DriverIRQHandler(void);
extern void DMATCD21_DriverIRQHandler(void);
extern void DMATCD22_DriverIRQHandler(void);
extern void DMATCD23_DriverIRQHandler(void);
extern void DMATCD24_DriverIRQHandler(void);
extern void DMATCD25_DriverIRQHandler(void);
extern void DMATCD26_DriverIRQHandler(void);
extern void DMATCD27_DriverIRQHandler(void);
extern void DMATCD28_DriverIRQHandler(void);
extern void DMATCD29_DriverIRQHandler(void);
extern void DMATCD30_DriverIRQHandler(void);
extern void DMATCD31_DriverIRQHandler(void);
#endif

/*!
 * brief DMA instance 0, channel 0 IRQ handler.
 *
 */
void DMATCD0_DriverIRQHandler(void)
{
    /* Instance 0 channel 0 */
    EDMA_DriverIRQHandler(0U, 0U);
}

void DMATCD1_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 1U);
}

void DMATCD2_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 2U);
}

void DMATCD3_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 3U);
}

void DMATCD4_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 4U);
}

void DMATCD5_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 5U);
}

void DMATCD6_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 6U);
}

void DMATCD7_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 7U);
}
void DMATCD8_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 8U);
}

void DMATCD9_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 9U);
}

void DMATCD10_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 10U);
}

void DMATCD11_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 11U);
}

#if (FSL_FEATURE_EDMA_MODULE_CHANNEL > 12U)
void DMATCD12_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 12U);
}

void DMATCD13_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 13U);
}

void DMATCD14_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 14U);
}

void DMATCD15_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 15U);
}

void DMATCD16_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 16U);
}

void DMATCD17_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 17U);
}
void DMATCD18_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 18U);
}

void DMATCD19_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 19U);
}

void DMATCD20_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 20U);
}

void DMATCD21_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 21U);
}

void DMATCD22_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 22U);
}

void DMATCD23_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 23U);
}

void DMATCD24_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 24U);
}

void DMATCD25_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 25U);
}

void DMATCD26_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 26U);
}

void DMATCD27_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 27U);
}
void DMATCD28_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 28U);
}

void DMATCD29_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 29U);
}

void DMATCD30_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 30U);
}
void DMATCD31_DriverIRQHandler(void)
{
    EDMA_DriverIRQHandler(0U, 31U);
}
#endif