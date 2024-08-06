/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32Z270_GLUE_MCUX_H_
#define _S32Z270_GLUE_MCUX_H_

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

#endif /* _S32Z270_GLUE_MCUX_H_ */
