/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexcan_soc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexcan_soc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void CAN0_ORed_DriverIRQHandler(void);
void CAN0_Error_DriverIRQHandler(void);
void CAN0_Wake_Up_DriverIRQHandler(void);
void CAN0_ORed_0_15_MB_DriverIRQHandler(void);
void CAN0_ORed_16_31_MB_DriverIRQHandler(void);
void CAN1_ORed_DriverIRQHandler(void);
void CAN1_Error_DriverIRQHandler(void);
void CAN1_ORed_0_15_MB_DriverIRQHandler(void);
void CAN1_ORed_16_31_MB_DriverIRQHandler(void);
void CAN2_ORed_DriverIRQHandler(void);
void CAN2_Error_DriverIRQHandler(void);
void CAN2_ORed_0_15_MB_DriverIRQHandler(void);
void CAN2_ORed_16_31_MB_DriverIRQHandler(void);
extern void FLEXCAN_DriverEventIRQHandler(uint32_t instance);
extern void FLEXCAN_DriverDataIRQHandler(uint32_t instance, uint32_t startMbIdx, uint32_t endMbIdx, uint32_t type);

/*******************************************************************************
 * Code
 ******************************************************************************/

 /*!
 * brief CAN instance 0, ORed IRQ handler.
 *
 */
void CAN0_ORed_DriverIRQHandler(void)
{
    /* Instance 0*/
    FLEXCAN_DriverEventIRQHandler(0U);
}

/*!
 * brief CAN instance 0, Error IRQ handler.
 *
 */
void CAN0_Error_DriverIRQHandler(void)
{
    /* Instance 0*/
    FLEXCAN_DriverEventIRQHandler(0U);
}

/*!
 * brief CAN instance 0, Wake-up IRQ handler.
 *
 */
void CAN0_Wake_Up_DriverIRQHandler(void)
{
    /* Instance 0*/
    FLEXCAN_DriverEventIRQHandler(0U);
}

/*!
 * brief CAN instance 0, Ored 0-15 MB IRQ handler.
 *
 */
void CAN0_ORed_0_15_MB_DriverIRQHandler(void)
{
    /* Instance 0, MB 0-15 */
    FLEXCAN_DriverDataIRQHandler(0U, 0U, 15U, 0U);
}

/*!
 * brief CAN instance 0, Ored 16-31 MB IRQ handler.
 *
 */
void CAN0_ORed_16_31_MB_DriverIRQHandler(void)
{
    /* Instance 0, MB 16-31 */
    FLEXCAN_DriverDataIRQHandler(0U, 16U, 31U, 0U);
}

/*!
 * brief CAN instance 1, ORed IRQ handler.
 *
 */
void CAN1_ORed_DriverIRQHandler(void)
{
    /* Instance 1*/
    FLEXCAN_DriverEventIRQHandler(1U);
}

/*!
 * brief CAN instance 1, Error IRQ handler.
 *
 */
void CAN1_Error_DriverIRQHandler(void)
{
    /* Instance 1*/
    FLEXCAN_DriverEventIRQHandler(1U);
}

/*!
 * brief CAN instance 1, Ored 0-15 MB IRQ handler.
 *
 */
void CAN1_ORed_0_15_MB_DriverIRQHandler(void)
{
    /* Instance 1, MB 0-15 */
    FLEXCAN_DriverDataIRQHandler(1U, 0U, 15U, 0U);
}

/*!
 * brief CAN instance 1, Ored 16-31 MB IRQ handler.
 *
 */
void CAN1_ORed_16_31_MB_DriverIRQHandler(void)
{
    /* Instance 1, MB 16-31 */
    FLEXCAN_DriverDataIRQHandler(1U, 16U, 31U, 0U);
}

/*!
 * brief CAN instance 2, ORed IRQ handler.
 *
 */
void CAN2_ORed_DriverIRQHandler(void)
{
    /* Instance 2*/
    FLEXCAN_DriverEventIRQHandler(2U);
}

/*!
 * brief CAN instance 2, Error IRQ handler.
 *
 */
void CAN2_Error_DriverIRQHandler(void)
{
    /* Instance 2*/
    FLEXCAN_DriverEventIRQHandler(2U);
}

/*!
 * brief CAN instance 2, Ored 0-15 MB IRQ handler.
 *
 */
void CAN2_ORed_0_15_MB_DriverIRQHandler(void)
{
    /* Instance 2, MB 0-15 */
    FLEXCAN_DriverDataIRQHandler(2U, 0U, 15U, 0U);
}

/*!
 * brief CAN instance 2, Ored 16-31 MB IRQ handler.
 *
 */
void CAN2_ORed_16_31_MB_DriverIRQHandler(void)
{
    /* Instance 2*, MB 16-31 */
    FLEXCAN_DriverDataIRQHandler(2U, 16U, 31U, 0U);
}
