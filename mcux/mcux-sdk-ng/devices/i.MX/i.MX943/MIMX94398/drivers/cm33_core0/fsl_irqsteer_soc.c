/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_irqsteer.h"

void IRQSTEERM33_CH0_DriverIRQHandler(void);
void IRQSTEERM33_CH0_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 0);
}

void IRQSTEERM33_CH1_DriverIRQHandler(void);
void IRQSTEERM33_CH1_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 1);
}

void IRQSTEERM33_CH2_DriverIRQHandler(void);
void IRQSTEERM33_CH2_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 2);
}

void IRQSTEERM33_CH3_DriverIRQHandler(void);
void IRQSTEERM33_CH3_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 3);
}

void IRQSTEERM33_CH4_DriverIRQHandler(void);
void IRQSTEERM33_CH4_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 4);
}

void IRQSTEERM33_CH5_DriverIRQHandler(void);
void IRQSTEERM33_CH5_DriverIRQHandler(void)
{
    IRQSTEER_CommonIRQHandler(IRQSTEERM33_INST, 5);
}


