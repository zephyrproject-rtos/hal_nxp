/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DMAMUX_H_
#define FSL_DMAMUX_H_

#include "fsl_common.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_dmamux"
#endif

/*!
 * @defgroup dmamux DMAMUX: DMA Channel Multiplexer Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief DMAMUX driver version. */
#define FSL_DMAMUX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * DMAMUX peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup dmamux_driver_log The Driver Change Log
 * @ingroup dmamux
 * @{
 *   The current dmamux driver version is 2.0.0.
 *
 *   - 2.0.0
 *     - Initial version.
 * @}
 */

/*******************************************************************************
 * DMAMUX peripheral driver overview
 ******************************************************************************/

/*!
 * @defgroup dmamux_intro DMAMUX Peripheral and Driver Overview
 * @ingroup dmamux
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ==================================================
 * The Direct Memory Access Multiplexer (DMAMUX) routes DMA sources, called slots,
 * to any of the DMA channels on SOCS.
 *
 *  + Support multiple independently selectable DMA channel routers.
 *
 *  + Support multiple peripheral slots can be routed to all the DMA channels.
 *    The peripheral used as the DMA sources.
 *
 *  + Support always-on slots can be routed to all the DMA channels.
 *    In addition to the peripherals that can be used as DMA sources, there are several additional
 *    DMA sources that are always enabled.
 *    Unlike the peripheral DMA sources, where the
 *    peripheral controls the flow of data during DMA transfers, the sources that are always
 *    enabled provide no such "throttling" of the data transfers
 *    It is useful to below cases:
 *    1. Performing DMA transfer to/from GPIO, moving data from/to one or more GPIO
 *    2. Performing DMA transfer from memory to memory, typically as fast as possible without software activation
 *    3. Any DMA transfer that requires software activation, since when activating a DMA channel via software,
 *       subsequent executions of the minor loop(reference EDMA driver for concept of minor loop)
 *       require that a new start event be sent,  to reduce software intervention, the always-on source can be used to
 * do the channel reactivation.
 *
 * How this peripheral works
 * ===========================================================
 * A DMA source will be routed directly to the specified DMA channel.
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 * + The DMAMUX driver provide one function group,
 *   - DMAMUX Channel functional group
 *     - The interfaces support connect one sources(peripheral or always on) to a specified DMA channel, then
 *       enable the channel.
 *     - The interfaces support put a DMAMUX channel into the disconnect status.
 *
 * How to use this driver
 * =======================
 *
 * + Connect a source to a DMA channel
 *   Using DMAMUX_ConnectChannelToTriggerSource Interface to connect a source to a specified DMA channel and enable the
 * channel.
 *
 * + Disconnect the DMAMUX channel
 *   Using DMAMUX_DisconnectChannelFromTriggerSource Interface to disconnect a specified channel from the source.
 *
 * Typical Use Cases
 * ================
 * 1. Connect a perpheral source to DMA channel 0
 * @code
 * DMAMUX_ConnectChannelToTriggerSource(DMAMUX, kDMAMUX_DMAChannel0, kDmaRequestMuxI2C0)
 * @endcode
 *
 * 2. Connect a always on source to DMA channel 0
 * @code
 * DMAMUX_ConnectChannelToTriggerSource(DMAMUX, kDMAMUX_DMAChannel0, kDmaRequestMuxAlwaysOn60)
 * @endcode
 *
 * 3. Swicth source for DMA channel 0
 * step1:
 * Disable the DMA channel 0 in DMA peripheral firstly
 * step2:
 * Switch to a new source for the channel
 * @code
 * DMAMUX_ConnectChannelToTriggerSource(DMAMUX, kDMAMUX_DMAChannel0, kDmaRequestMuxI2C1)
 * @endcode
 *
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief List of Dmamux dma channels */
typedef enum _dmamux_dma_channel
{
    kDMAMUX_DMAChannel0 = 0U, /*!< Dmamux dma channel  0 */
    kDMAMUX_DMAChannel1,      /*!< Dmamux dma channel  1 */
    kDMAMUX_DMAChannel2,      /*!< Dmamux dma channel  2 */
    kDMAMUX_DMAChannel3,      /*!< Dmamux dma channel  3 */
} dmamux_dma_channel_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name DMAMUX Channel functional group
 * @{
 */

/*!
 * @brief Connect the DMAMUX channel to trigger source.
 *
 * This function will connnect a source to the specify dma channel and enable that channel
 *
 * @param base      DMAMUX peripheral base address.
 * @param eChannel  DMAMUX channel index, @ref dmamux_dma_channel_t.
 * @param eSource   DMA request source.
 */
static inline void DMAMUX_ConnectChannelToTriggerSource(DMAMUX_Type *base,
                                                        dmamux_dma_channel_t eChannel,
                                                        dma_request_source_t eSource)
{
    /* disable the dmamux channel */
    base->CHCFG[(uint8_t)eChannel] &= ~(uint8_t)DMAMUX_CHCFG_ENBL_MASK;
    /* connect dmamux channel to source */
    base->CHCFG[(uint8_t)eChannel] =
        (uint8_t)((base->CHCFG[(uint8_t)eChannel] & ~DMAMUX_CHCFG_SOURCE_MASK) | DMAMUX_CHCFG_SOURCE(eSource));
    /* enable dmamux channel */
    base->CHCFG[(uint8_t)eChannel] |= DMAMUX_CHCFG_ENBL_MASK;
}

/*!
 * @brief Disconnect the DMAMUX channel.
 *
 * This function will disable the specified channel and reset the channel source.
 *
 * @param base DMAMUX peripheral base address.
 * @param eChannel DMAMUX channel index, @ref dmamux_dma_channel_t.
 */
static inline void DMAMUX_DisconnectChannelFromTriggerSource(DMAMUX_Type *base, dmamux_dma_channel_t eChannel)
{
    base->CHCFG[(uint8_t)eChannel] &= ~(uint8_t)(DMAMUX_CHCFG_ENBL_MASK | DMAMUX_CHCFG_SOURCE_MASK);
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_DMAMUX_H_ */
