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
 * | iMX952 |           12 = 768 / 64       |
 * +----------------------------------------+
 */

/* Max number of irqsteer instance */
#define IRQSTEER_MAX_INST	1

/* define instance index of irqsteer */
#define IRQSTEERM7_INST 0

/* IRQ channel index(not output channel index) */
#define IRQSTEER_IRQ_CHAN_IDX 0

#define FSL_FEATURE_IRQSTEER_IRQ_CHAN_MAX_NUM (1)
/*
 * reg: IRQSTEERM7_BASE
 * intNum: 768
 * irqChanNum: 1
 * irqChanIdx: 0 - irq channel 0 for cm7
 */
#define MULTI_IRQSTEER_INFO \
    { \
        { (void *)IRQSTEER_BASE, FSL_FEATURE_IRQSTEER_EXT_INT_MAX_NUM, FSL_FEATURE_IRQSTEER_IRQ_CHAN_MAX_NUM, IRQSTEER_IRQ_CHAN_IDX \
       	} \
    } 

#define MULTI_IRQSTEER_CLOCKS \
    {-1}

#define MULTI_IRQSTEER_IRQS \
    { \
        { \
            IRQSTEER_0_IRQn, IRQSTEER_1_IRQn, IRQSTEER_2_IRQn, IRQSTEER_3_IRQn, IRQSTEER_4_IRQn, IRQSTEER_5_IRQn, IRQSTEER_6_IRQn, IRQSTEER_7_IRQn, IRQSTEER_8_IRQn, IRQSTEER_9_IRQn, IRQSTEER_10_IRQn, IRQSTEER_11_IRQn\
        } \
    }

#endif /* FSL_IRQSTEER_SOC_H_ */
