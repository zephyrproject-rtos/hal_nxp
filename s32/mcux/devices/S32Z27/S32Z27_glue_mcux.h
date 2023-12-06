/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32Z27_GLUE_MCUX_H_
#define _S32Z27_GLUE_MCUX_H_

#include "S32Z27_device.h"

/* PIT - Peripheral instance base addresses */
/** Peripheral PIT0 base address */
#define PIT0_BASE                                IP_PIT_0_BASE
/** Peripheral PIT0 base pointer */
#define PIT0                                     IP_PIT_0
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           IP_PIT_BASE_ADDRS
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            IP_PIT_BASE_PTRS
/** Interrupt vectors for the PIT peripheral type */
#define PIT_IRQS                                 { RTU_RTUn_PIT0_IRQn }

/* I3C - Peripheral instance base addresses */
/** Peripheral I3C0 base address */
#define I3C0_BASE                                IP_I3C_0_BASE
/** Peripheral I3C0 base pointer */
#define I3C0                                     IP_I3C_0
/** Peripheral I3C1 base address */
#define I3C1_BASE                                IP_I3C_1_BASE
/** Peripheral I3C1 base pointer */
#define I3C1                                     IP_I3C_1
/** Peripheral I3C2 base address */
#define I3C2_BASE                                IP_I3C_2_BASE
/** Peripheral I3C1 base pointer */
#define I3C2                                     IP_I3C_2
/** Array initializer of I3C peripheral base addresses */
#define I3C_BASE_ADDRS                           IP_I3C_BASE_ADDRS
/** Array initializer of I3C peripheral base pointers */
#define I3C_BASE_PTRS                            IP_I3C_BASE_PTRS
/** Interrupt vectors for the I3C peripheral type */
#define I3C_IRQS                                 { RTU_I3C0_IRQn, RTU_I3C1_IRQn, RTU_I3C2_IRQn }

#endif /* _S32Z27_GLUE_MCUX_H_ */
