/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_IRQSTEER_SOC_H_
#define FSL_IRQSTEER_SOC_H_

#include "fsl_common.h"

/*
 * +----------------------------------------+
 * |  soc   | max number of output channel  |
 * +----------------------------------------+
 * | iMX95  |           8 = 512 / 64        |
 * +----------------------------------------+
 * | iMX943 |          15 = 960 / 64        |
 * +----------------------------------------+
 */

/* Max number of irqsteer instance */
#define IRQSTEER_MAX_INST	1

/* define instance index of irqsteer */
#define IRQSTEERM7_INST 0

/* IRQ channel index(not output channel index) */
#define IRQSTEER_IRQ_CHAN_IDX 0

/*
 * reg: IRQSTEERM33_BASE
 * intNum: 960
 * irqChanNum: 2
 * irqChanIdx: 0 - irq channel 0 for cm7 core0, irq channel 1 for cm7 core1
 */
#define MULTI_IRQSTEER_INFO \
    { \
        { (void *)IRQSTEERM7_BASE, FSL_FEATURE_IRQSTEER_EXT_INT_MAX_NUM, FSL_FEATURE_IRQSTEER_IRQ_CHAN_MAX_NUM, IRQSTEER_IRQ_CHAN_IDX \
       	} \
    } 

#define MULTI_IRQSTEER_CLOCKS \
    {kCLOCK_IpInvalid}

#define MULTI_IRQSTEER_IRQS \
    { \
        { \
            IRQSTEERM7_CH0_IRQn, IRQSTEERM7_CH1_IRQn, IRQSTEERM7_CH2_IRQn, IRQSTEERM7_CH3_IRQn, IRQSTEERM7_CH4_IRQn, IRQSTEERM7_CH5_IRQn, IRQSTEERM7_CH6_IRQn, IRQSTEERM7_CH7_IRQn, IRQSTEERM7_CH8_IRQn, IRQSTEERM7_CH9_IRQn, IRQSTEERM7_CH10_IRQn, IRQSTEERM7_CH11_IRQn, IRQSTEERM7_CH12_IRQn \
        } \
    }

#endif /* FSL_IRQSTEER_SOC_H_ */
