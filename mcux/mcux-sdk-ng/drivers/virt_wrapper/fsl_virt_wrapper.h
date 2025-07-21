/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_VIRT_WRAPPER_H_
#define FSL_VIRT_WRAPPER_H_

#include "fsl_common.h"

/*!
 * @addtogroup virt_wrapper
 * @{
 */

/******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! Version. */
#define FSL_VIRT_WRAPPER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @brief Maps the pins to a specific slot.
 *
 * This function maps the pins of a port to specific slot. This function
 * can map multiple pins at one time, by using a bit mask.
 *
 * @param base VIRT_WRAPPER peripheral base address.
 * @param port Pin port number, starting from 0, for exapmle, PTA is 0, PTB is 1.
 * @param pins Bit-mask of the pins, ((1 << 0) | (1 << 1)) means pin 0 and pin 1 in the port.
 * @param slot The slot to map to.
 *
 * @return kStatus_Success on success, otherwise returns error code.
 */
status_t VIRT_WRAPPER_MapPins(VIRT_WRAPPER_Type *base, uint16_t port, uint32_t pins, virt_wrapper_slot_t slot);

/*!
 * @brief Maps the input multiplexer to a specific slot.
 *
 * This function maps the input multiplexer to a specified slot.
 *
 * @param base VIRT_WRAPPER peripheral base address.
 * @param inputMuxIndex Index of the input multiplexer.
 * @param slot The slot to map to.
 *
 * @return kStatus_Success on success, otherwise returns error code.
 */
status_t VIRT_WRAPPER_MapInputMux(VIRT_WRAPPER_Type *base, uint32_t inputMuxIndex, virt_wrapper_slot_t slot);

/*!
 * @brief Maps interrupt control to a specific slot.
 *
 * This function maps the interrupt control register to a specified slot.
 *
 * @param base VIRT_WRAPPER peripheral base address.
 * @param slot The slot to map to.
 */
static inline void VIRT_WRAPPER_MapInterrupt(VIRT_WRAPPER_Type *base, virt_wrapper_slot_t slot)
{
    base->REG_C[0] = (base->REG_C[0] & ~VIRT_WRAPPER_REG_C_INTC_CTRL_MASK) | VIRT_WRAPPER_REG_C_INTC_CTRL(slot);
}

/*!
 * @brief Maps the GPC register to a specific slot.
 *
 * This function maps the GPC register to a specified slot.
 *
 * @param base VIRT_WRAPPER peripheral base address.
 * @param slot The slot to map to.
 */
static inline void VIRT_WRAPPER_MapGCR(VIRT_WRAPPER_Type *base, virt_wrapper_slot_t slot)
{
    base->REG_D[0] = (base->REG_D[0] & ~VIRT_WRAPPER_REG_D_REG_GCR_MASK) | VIRT_WRAPPER_REG_D_REG_GCR(slot);
}

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @}*/

#endif /* FSL_VIRT_WRAPPER_H_ */