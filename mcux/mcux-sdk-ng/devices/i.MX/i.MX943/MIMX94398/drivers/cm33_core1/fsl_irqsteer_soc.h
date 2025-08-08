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
#define IRQSTEERM33_INST 0

/* IRQ channel index(not output channel index) */
#define IRQSTEER_IRQ_CHAN_IDX 1

/*
 * reg: IRQSTEERM33_BASE
 * intNum: 960
 * irqChanNum: 2
 * irqChanIdx: 1 - irq channel 0 for cm33 core0, irq channel 1 for cm33 core1
 */
#define MULTI_IRQSTEER_INFO \
    { \
        { (void *)IRQSTEERM33_BASE, FSL_FEATURE_IRQSTEER_EXT_INT_MAX_NUM, FSL_FEATURE_IRQSTEER_IRQ_CHAN_MAX_NUM, IRQSTEER_IRQ_CHAN_IDX \
       	} \
    } 

#define MULTI_IRQSTEER_CLOCKS \
    {kCLOCK_IpInvalid}

#define MULTI_IRQSTEER_IRQS \
    { \
        { \
            IRQSTEERM33_CH0_IRQn, IRQSTEERM33_CH1_IRQn, IRQSTEERM33_CH2_IRQn, IRQSTEERM33_CH3_IRQn, IRQSTEERM33_CH4_IRQn, IRQSTEERM33_CH5_IRQn \
        } \
    }

#endif /* FSL_IRQSTEER_SOC_H_ */
