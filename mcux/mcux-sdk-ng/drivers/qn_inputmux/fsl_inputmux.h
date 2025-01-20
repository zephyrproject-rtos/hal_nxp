/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_INPUTMUX_H_
#define FSL_INPUTMUX_H_

#include "fsl_inputmux_connections.h"
#include "fsl_common.h"

/*!
 * @addtogroup qn_inputmux
 * @{
 */

/*! @file */
/*! @file fsl_inputmux_connections.h */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Group interrupt driver version for SDK */
#define FSL_INPUTMUX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */
                                                            /*! @} */

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @brief	Initialize INPUTMUX peripheral.

 * This function enables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 *
 * @retval None.
 */
void INPUTMUX_Init(INPUTMUX_Type *base);

/*!
 * @brief Attaches a signal
 *
 * This function gates the INPUTPMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 * @param index Destination peripheral to attach the signal to.
 * @param connection Selects connection.
 *
 * @retval None.
 */
void INPUTMUX_AttachSignal(INPUTMUX_Type *base, uint32_t index, inputmux_connection_t connection);

/*!
 * @brief	Deinitialize INPUTMUX peripheral.

 * This function disables the INPUTMUX clock.
 *
 * @param base Base address of the INPUTMUX peripheral.
 *
 * @retval None.
 */
void INPUTMUX_Deinit(INPUTMUX_Type *base);

#ifdef __cplusplus
}
#endif

/*! @} */

#endif /* FSL_INPUTMUX_H_ */
