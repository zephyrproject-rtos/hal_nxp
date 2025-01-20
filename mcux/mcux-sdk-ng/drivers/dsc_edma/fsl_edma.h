/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_EDMA_H_
#define FSL_EDMA_H_

#include "fsl_common.h"

/*!
 * @defgroup edma EDMA: Enhanced Direct Memory Access Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief EDMA driver version. */
#define FSL_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 3))
/*! @} */

/*******************************************************************************
 * EDMA peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup edma_driver_log The Driver Change Log
 * @ingroup edma
 * @{
 * The current eDMA driver version is 2.0.3.
 *
 * - 2.0.3
 *  - Fixed the MISRA-2012 violations.
 *    Fixed rule10.3.
 *
 * - 2.0.2
 *  - Fixed the MISRA-2012 violations.
 *    Fixed rule 5.8, 9.2, 10.3, 10.4, 11.6.
 *
 * - 2.0.1
 *   - Code modification for SDM compliance
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */
/*******************************************************************************
 * EDMA peripheral driver overview
 ******************************************************************************/

/*!
 * @defgroup edma_intro EDMA Peripheral and Driver Overview
 * @ingroup edma
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 *
 * Peripheral features
 * ==================================================
 * The enhanced direct memory access (eDMA) controller is a second-generation module
 * Capable of performing complex data transfers with minimal intervention from a host
 * processor.
 *
 *  + Multiple channels implementation that performs complex data transfers with minimal intervention from a host
 *    processor
 *    - Each DMA channel can be routed to different peripheral slots through DMAMUX for transfer between peripheral and
 *      memory
 *    - Each DMA channel can be routed to always-on source through DMAMUX, Unlike the peripheral DMA sources, where the
 *      peripheral controls the flow of data during DMA transfers, the sources that are always
 *      enabled provide no such "throttling" of the data transfers, it is useful for transfer between memory and memory.
 *
 *  + Channel arbitration:Fixed-priority and round-robin
 *    - Fixed-Priority
 *      Channel service request from the highest priority channel is selected to execute
 *    - Round-robin
 *      Channels are serviced starting with the highest channel number and rotating through to
 *      the lowest channel number without regard to the channel priority levels.
 *
 *  + Transfer control descriptor(TCD)
 *    All data movement via dual-address transfers: read from the source, written to destination are controlled by TCD
 *    - TCD is a 32-byte array stored in eDMA peripheral local memory for each channel.
 *
 *    - TCD represent a transfer request from an application that consists of the minor loop and major loop
 *      + Minor loop
 *        A loop that control bytes count to be transferred while a dma request coming
 *      + Major loop
 *        A loop that controls the counts of the minor loop will be performed
 *      As a channel activates, the appropriate reads/writes perform until the minor loop byte transfer count has
 *      transferred, it is
 *      a indivisible operation and cannot be halted. The major loop Count decremented each time the minor loop is
 *      completed. After the
 *      major iteration count is exhausted, a transfer represented by TCD complete.
 *
 *    - TCD support enhanced addressing modes for the source and destination addresses to do with different user
 *      scenario.
 *      + address offset per reading/writing
 *      + address offset per minor loop(offset will be applied to the source or destination address after each request
 *        serviced which may include several read/write)
 *      + address offset per major loop(offset will be applied to the source or destination address after all the bytes
 *        transfer done)
 *      + address range can be specified by the MODULO feature for source/destination address, it is useful to implement
 *        a circular data queue.
 *
 *    - TCD support Channel linking feature(The capability of the EDMA channel to activate another EDMA channel) which
 *      is helpful to implement
 *      multi channel chained transfer, there are two channel linking mode support by eDMA list as below:
 *      + channel linking can perform at the major loop completion
 *      + Channel linking can perform at the minor loop completion
 *
 *    - TCD support load a software TCD into hardware TCD registers automatically on completion of current TCD by
 *      specify the memory address of
 *      the software TCD to be linked, it is called scatter/gather.
 *      + It is helpful to the data transfers from non-contiguous blocks of memory to others using a
 *        series of smaller contiguous-block transfers, such as below cases,
 *        - For the ping-pong buffer implementation, there is always TCD is working on sending/receiving data
 *          while it leave the time for software to do with received data in previous TCD transfer or prepare for data
 *          to be sent in future transfer with keep a continuous transfer
 *        - For a complex car entertainment system which get shared speaker while with multiple audio source like
 *          bluetooth-connected phone and CD player whose drivers get provide non-contiguous data buffers. Audio system
 *          is required to smoothly switch to different audio source in different scenario
 *
 *  + Channel activation via one of three methods.
 *      + Explicit software initiation by START bit in TCD register CSR(perform minor loop transfer with each software
 *        trigger).
 *      + Initiation via a channel-to-channel linking mechanism for continuous transfers
 *      + Peripheral-paced hardware requests, one per channel
 *
 *  + Channel completion reported via programmable interrupt requests.
 *      - One interrupt per channel, which can be asserted at
 *          + completion of the major loop.
 *          + half completion of the major loop which may be useful for ping-pong buffer.
 *      - Programmable error terminations per channel and logically summed together to form one error interrupt to the
 *        interrupt controller
 *
 * How this peripheral works
 * ===========================================================
 * Once the eDMA channel is activated through software/peripheral, the eDMA request input signal will be registered
 * internally and then routed through the eDMA engine: first through the control module,
 * then into the program model and channel arbitration. In the next cycle, the channel
 * arbitration performs, using the fixed-priority or round-robin algorithm. After arbitration
 * completes, the activated channel TCD will be loaded into the eDMA engine.
 *
 * The modules associated with the data transfer sequence through the required source reads and destination write to
 * perform the actual data movement continues until the minor byte count has transferred.
 *
 * After the minor bytes count has transferred, the eDMA engine performs the required updates to certain fields in
 * the appropriate TCD, for example,
 * 1. offset applied to SADDR(source address)/DADDR(destination address)
 * 2. major loop count in CITER decrement.
 * If the major loop count is exhausted, additional operations are performed. These include:
 * 1. Final address adjustments and reloading of the BITER field into the CITER.
 * 2. The assertion of an optional interrupt request also occurs at this time, as does a possible fetch of a new TCD
 * from memory using the scatter/gather address pointer included in the descriptor (if scatter/gather is enabled).
 *
 * How this driver is designed to make this peripheral works.
 * ===========================================================
 * The eDMA peripheral is powerful with complex transfer features supported.
 * To satisfy different user getting different demands for the feature sets/optimization level/flexibility/abstraction
 * level, 2 parallel layers are provided in this driver (DO NOT MIX THE USAGE OF THESE 2 LAYERS!!!):
 * - Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 *   features.
 *   All hardware features are supported while requiring user get a decent understanding of the hardware detail of eDMA
 *   so that user know how to organize these functional API together to meet the requirement of application.
 * - Transactional layer is provided with average optimization level, average flexibility and not all features are
 *   covered.
 *   It is for user who want to ramp up the usage of peripheral quickly without dig much into this specific peripheral
 *   with only common knowledge of DMA peripheral model. It achieve this goal by hiding the processing of interrupt
 *   handling,processing of scatter-gather and processing of convention among software TCD/hardware
 * TCD/human-understandable transfer attributes. To distinguish transactional layer from functional layer easily, all
 * transactional API get Transfer in the name.
 *
 * Below introduce the detail data structure/API for the two layers.
 *
 * + Functional Layer
 *
 *   - Transfer Configuration
 *     The most important data structure usage is to configure the transfer attributes.
 *     The driver provide @ref edma_channel_transfer_config_t
 *     whose members expose all the transfer attributes supported by peripheral. However, it may still complex / fussy
 *     for user who need not such many features.
 *     A helper function EDMA_GetChannelDefaultTransferConfig is provided to get a ready-to-use
 *     TCD configuration with only basic information required. User can create the @ref edma_channel_transfer_config_t
 *     himself/herself if he/she is comfortable with that way or use the helper function
 *     EDMA_GetChannelDefaultTransferConfig to get initial data structure and then fine-tune needed members per
 *     requirement.
 *
 *    - Channel Identifier
 *      All channel is represented with a enumerator provided in @ref edma_channel_t that user need not bother with
 *      whether channel 0 shall be 0 or 1 for register access.
 *
 *    - Functional layer provide multiple API function groups
 *      + eDMA initialization and De-initialization Interfaces
 *        - The interfaces target for whole module configuration which includes:
 *          + the general configurations of the module, such as the arbitration type/continuous link/minor loop mapping/
 *            halt on error.
 *          + All channels specific transfer configuration.
 *        - The interfaces provide helper function assist user to get a ready-to-use @ref edma_config_t
 *          with easy-to-understand parameter filled to assist the usage of Init API.
 *
 *      + eDMA non-channel functional interfaces
 *        - The functional interfaces used for the eDMA general configurations, the configuration apply for all channels
 *          thus need not call this group of function for each channel.
 *
 *      + eDMA channel functional interfaces
 *        - The interfaces provide a api that support configure the full transfer parameters of a
 *          channel.
 *        - The interfaces provide helper function assist user to get a ready-to-use @ref edma_channel_transfer_config_t
 *          with easy-to-understand parameter filled to assist the usage of Init API.
 *        - The interfaces provide configuration interface to configure separate transfer attribute into channel's eDMA
 *          hardware TCD register directly which is referred as hardware TCD.
 *          It is efficiency and useful when the majority of last transfer attribute still
 *          apply for next transfer and only limited fields need to updated.
 *
 *      + eDMA software TCD Functional Interfaces
 *        - The interfaces to create a software TCD with provided @ref edma_channel_transfer_config_t. This is used for
 *          scatter-gather feature.
 *        @note that memory of the @ref edma_channel_tcd_t shall not be occupied until its transfer is done rather than
 *          return of this function. And in cache enabled system, make sure the memory is strongly ordered cause DMA and
 *          CPU is different master of bus and DMA module have no knowledge of what is kept in cache.
 *
 *      + eDMA Channel Status Interfaces
 *        - The interfaces in the function group can be used to get/clear the channel status
 *
 *      + eDMA Channel Interrupt Interfaces
 *        - The interfaces in the function group can be used to Enable/Disable channel interrupt
 *
 * + Transactional Layer
 *
 *    To distinguish from Functional layer,  all transactional API get Transfer in the naming of the API.
 *
 *    In parallel with the Functional layer, the driver provide the transactional layer remove user the effort below
 *    thus user can easily get EDMA peripheral features enabled with least coding effort and much less knowledge
 *    requirement on this peripheral
 *    - User need not spent effort on prepare the interrupt handler function from vector entry to the user code.
 *    - User need not configure the scatter gather feature himself/herself but transfer are automatically linked on the
 *      sequence of submit the transfer configuration.
 *    - User need not understand the relation-ship between software TCD and hardware TCD and how they are relevant to
 *      each other.
 *
 *    Comparing to functional layer,
 *    - Transactional layer use the @ref edma_handle_t to represent a channel and
 *      user need the EDMA_TransferCreateHandle function to initialize the handle. This handler will be stored inside
 *      driver
 *      thus channel state is retained in software level which is crucial in interrupt context.
 *    - Transactional use same data structure  @ref edma_channel_transfer_config_t to configure the
 *      transfer to keep the consistent usage experience across this driver, but application shall not specify the
 *      psLinkTCD in edma_channel_transfer_config_t, since the transactional interface will link the multiple transfer
 *      request automatically.
 *
 *    One of the key feature in transactional layer comparing to functional layer is user need not setup interrupt
 *    related stuff(like enabling the system level interrupt enable/disable, prepare the vector entry function)
 *    but still get user's interrupt handling code executed once interrupt happens.
 *    - Interrupt handling codes are automatically active when user get this driver files into application project. This
 *      is provided by the 'double weak' mechanism. You can find the detail in the general section of API Reference
 *      Manual.
 *      In brief, SDK place a weak function A in the vector entry for this peripheral. The default implementation of
 *      this  function call another weak function B. By default, when a interrupt happen, the code will be executed as
 *      A (Weak) -> B (Weak). This driver provide the function B thus once user get the driver file into the application
 *      project, when interrupt happened, code will be executed as A (Weak) -> B (Non-Weak, in this driver)
 *      thus user is no longer need to do with the interrupt handling himself.
 *      If user get his/her own requirement of interrupt handling, define the A in the
 *      application and interrupt will be routed to his/her own interrupt function.
 *    - Hidden interrupt handling doesn't mean user get no chance to insert his/her processing logic in the interrupt
 *      handling. User is requested to provide the callback function on
 *      EDMA_TransferCreateHandle and when interrupt happens, callback will be invoked
 *      immediately that user codes can be executed when interrupt happens.
 *
 *    Another important feature in transactional layer is the simplified transfer management for scatter-gather
 *    Scatter-Gather feature is powerful but not easy to understand and easy to introduce mistakes, such as
 *    De-active software TCD too early.
 *    Transactional layer maintain a buffer to store/link/maintain the required transfer internally
 *    thus application need only know which kind of transfer that it want to be executed
 *    and submit these transfers to this software layer and the left work will be done by driver.
 *    Note that user is still required to provide the memory address and size for
 *    the first time cause driver are not allowed to allocate memory itself to avoid memory leakage.
 *    - Transactional layer provide flexibility that user can freely raise the transfer request anytime before or after
 *      start of the data transfer.
 *      The later submitted transfer will be automatically executed after previously transfer.
 *      is done by submit transfer with function EDMA_TransferSubmitSingleTransfer once the mentioned internal buffer
 *      still get empty slots to
 *      storing the new request.
 *      @note on doing with the race-condition, the driver use the way of disabling the global interrupt. This is not
 *      allowed
 *      for some application. For these application, user is not suggested to use the transactional layer.
 *    - Transactional layer provide another important feature that user can configure the transfer in a loop
 *      which means user want the transfer in loop as A -> B -> C -> A -> ... and continuously update the buffer
 *      represented by these
 *      transfers without update transfer attributes during runtime. This is common in audio processing. A function
 *      EDMA_SubmitLoopTransfer is provided for this case.
 *      Note that Loop Transfer shall be setup before start of transfer.
 *
 *    Several function groups are provided for the transactional layer
 *    - Transaction Initialization Interface
 *      + Init the channel with a user provided handle memory data structure with callback requested for inserting user
 *        code on completion of transfer
 *      + Interface for user to provide the memory used as internal software TCD buffer
 *
 *    - Transaction Transfer Configuration Interface
 *      + Interfaces to submit transfer in loop mode or non-loop mode
 *
 *    - Transaction Start/Stop Interface
 *      + Start/Stop/Abort the transfer
 *
 *    - Transaction Interrupt Handler
 *      + Interrupt handling function which is called in the 'double weak' function. User is not necessary to understand
 *        it but can take it as reference code to understand how this driver work
 *
 *  How to use this driver
 *  =======================
 *  Functional Layer
 *  ------------------
 *    + Configuration option on compiling
 *      - FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL:
 *        Definition of this macro means this driver will not ungate/gate EMDA peripheral inside
 *        driver. Application code need to do with the clock gate/ungate himself/herself.
 *
 *    + Steps shall be covered in application codes rather than in driver
 *      - The eDMA request source must be configured properly by the Direct Memory Access Multiplexer(DMAMUX).
 *        + For the transfer between the memory and peripheral, the peripheral request source must be routed to a
 *          particular DMA channel.
 *        + For the transfer between memory and memory, the DMAMUX support always-enabled DMA sources which are useful
 *          for the cases need software activation, that is to say, the software doesn't need to activate the channel
 *          instead of enabling the channel hardware request if always-enabled DMA sources are routed to a specified DMA
 *          channel.
 *
 *      - The eDMA peripheral driver clock gate may not be handled by the driver on some platforms if
 *        FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is defined, so please make sure that the eDMA clock gate is enabled
 *        before eDMA driver interface being invoked if driver does not handle it.
 *
 *      - If interrupt mode is used, setup the interrupt handler entry to execute the application codes
 *
 *    + Driver Interface invoking Sequence
 *      - Initialize the eDMA peripheral
 *        Use the eDMA Initialization and De-initialization Interfaces. eDMA driver provides an interface
 *        EDMA_Init which is target for whole module configurations.
 *        + If the application would like to submit transfer configuration by EDMA_Init, please reference steps
 *			Prepare transfer configuration and then skip to step Trigger the transfer.
 *        + If the channel request is enabled in the transfer configuration, please skips steps Trigger the transfer
 *          also.
 *
 *      - [Optional]Application can use eDMA non-channel functional interfaces for specific general feature enable.
 *
 *      - Prepare transfer configuration
 *        + Use the @ref edma_channel_transfer_config_t to prepare the transfer attributes and use the
 *          EDMA_GetChannelDefaultTransferConfig to assist the creation of the transfer configure. 3 typical modes are
 *          supported on getting the default configuration
 *          - Memory To Memory: Transfer data from memory to memory which means tranSfer address of source/destination
 *            address is incremental.
 *          - Memory To Peripheral: Transfer data from memory to peripheral where destination address is fixed.
 *            A typical case is sending a buffer by UART send register.
 *          - Peripheral To Memory: Transfer data from peripheral to memory buffer where source address is fixed.
 *            A typical case is receiving data into memory buffer on UART RX.
 *        + Configure the advanced transfer attributes by update the transfer configuration structure like channel link.
 *        + With prepared transfer configuration, user can configure these attributes to hardware TCD or software TCD
 *          that peripheral can recognize it and execute it.
 *          - Hardware TCD, User can use the EDMA_InitChannel to set the transfer or use the EDMA channel configuration
 *            function group to configure separate transfer attribute one by one.
 *          - Software TCD, User can use the Software TCD interface to configure the transfer but note that software TCD
 *            memory can not be released until its represented transfer is done or abort.
 *
 *      - Submit the transfer
 *        - Application can submit the transfer configurations by calling EDMA_SetChannelTransferConfig.
 *        - If the software TCD is used, application can submit the software TCD by calling function
 *          EDMA_InstallChannelSoftwareTCD , otherwise this step should be skipped.
 *
 *      - Trigger the transfer
 *        + User can trigger transfer manually using EDMA_SoftwareTriggerChannelStart
 *        + [Recommended] User can leave the trigger action be done by the DMAMUX as mentioned in the first step, but
 *          need to enable the request by calling EDMA_EnableChannelRequest.
 *
 *      - Track the completion of transfer
 *        + Use API EDMA_GetChannelStatusFlags() to know whether it is done
 *        + Use API EDMA_GetErrorStatusFlags() to know the detail of the error happen during transfer
 *
 *      - De-initialize the eDMA peripheral channel
 *        eDMA driver provides an interface EDMA_DeinitChannel which will reset
 *        all the channel relate transfer control descriptor registers.
 *
 *  Transactional Layer
 *  --------------------
 *    + Configuration option on compiling:
 *      - FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL:
 *        Definition of this macro means this driver will not ungate/gate EMDA peripheral inside
 *        driver. Application code need to do with the clock gate/ungate himself/herself.
 *      - EDMA_ENTER_CRITICAL_SECTION/EDMA_LEAVE_CRITICAL_SECTION
 *        These access protection macros is disabled by default in driver, application could overwrite it for the tcd
 *        pool access protection if multiple task would like to access the same channel.
 *
 *    + Steps shall be covered in application codes rather than in driver
 *      - Same as functional layer except that interrupt entry need not be setup by user.
 *
 *    + Driver Interface invoking Sequence
 *      - Initialize the eDMA peripheral
 *        Use the eDMA Initialization and De-initialization Interfaces. eDMA driver provides an interface
 *        EDMA_Init which is target for whole module configurations, channel transfer configuration should not be
 *        submitted with EDMA_Init while using transactional layer.

 *      - [Optional]Application can use eDMA non-channel
 *        functional interfaces for specific general feature enable.
 *
 *      - Init the handle by calling EDMA_TransferCreateHandle with optional callback provided and provide driver
 *        the software TCD memory and how many TCD slots supported.
 *        Note that user shall make sure this memory is always alive unless it is no longer used and make sure
 *        the memory in a strongly ordered memory region.

 *      - Configure the Transfer
 *        + For Loop transfer, call EDMA_TransferSubmitLoopTransfer, note that do not start the transfer before loop
 *          configuration is done
 *        + For non-loop transfer, call EDMA_TransferSubmitSingleTransfer, user can submit the transfer request any time
 *          the install software TCD buffer still get empty slots. User can submit the non-loop transfer request
 *          before/after start of the transfer.

 *      - Start/Stop/Abort channel use the EDMA_TransferStart/EDMA_TransferStop/EDMA_TransferAbort

 *      - Handle transfer completion
 *        + User's code will be executed on completion of transfer or transfers where it is provided in callback
 *          function on EDMA_TransferCreateHandle.
 *        + The callback function can be called on completion of each TCD and callback function will be assigned
 *          with parameter that how many TCDs are completed that you need to re-setup these memory buffer. When system
 *          is in heavy load by other higher priority interrupt that there maybe the case that 2 or more TCD completion
 *          trigger only one callback.
 *
 *  Typical Use Cases
 *  ================
 *  1. Single transfer(using edma channel functional layer)
 *     For a single one shot transfer,
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *		psTransfer->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *     For advance transfer case with modulo feature
 *     @code
 *      psTransfer.u32SrcAddr = xxx;
 *      psTransfer.u32DstAddr = xxx;
 *      psTransfer.eSrcWidthOfEachTransfer = kEDMA_TransferWidth32Bits;
 *      psTransfer.eDstWidthOfEachTransfer = kEDMA_TransferWidth32Bits;
 *      psTransfer.i16SrcOffsetOfEachTransfer = 4U;
 *      psTransfer.i16DstOffsetOfEachTransfer = 4U;
 *      psTransfer.u32BytesEachRequest = 4;
 *      psTransfer.u32TotalBytes = 256;
 *      psTransfer.eSrcAddrModulo = kEDMA_ChannelModulo256bytes;
 *      psTransfer.u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *  2. Scatter gather transfer(using edma channel functional layer)
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_ConfigChannelSoftwareTCD(tcd, &transferConfig);
 *      psTransfer->psLinkTCD = tcd;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *  3. Loop transfer(using edma software TCD interfaces)
 *     @code
 *      EDMA_GetDefaultConfig(&config);
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer0, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer0->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer1, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer1->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      psTransfer0->psLinkTCD = tcd[1];
 *      psTransfer1->psLinkTCD = tcd[0];
 *      EDMA_ConfigChannelSoftwareTCD(&tcd[0], &psTransfer0);
 *      EDMA_ConfigChannelSoftwareTCD(&tcd[1], &psTransfer1);
 *      EDMA_InstallChannelSoftwareTCD(base, channel, tcd0);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *  4. Channel link(using edma initialization and de-initialization interface)
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer0, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer0->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer1, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer1->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      psTransfer0->bEnableChannelMinorLoopLink = true;
 *      psTransfer0->eMinorLoopLinkChannel = 1;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0] = &psTransfer0;
 *      config.psChannelTransferConfig[1] = &psTransfer1;
 *
 *      EDMA_Init(DMA, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferMemoryToMemory);
 *      config.bEnableChannelMinorLoopLink = true;
 *      config.eMinorLoopLinkChannel = channel1;
 *      config.u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *  5. Single transfer (using edma transactional layer)
 *     @code
 *
 *      EDMA_TransferCreateHandle(handle, base, channel, tcdPool, tcdPoolCount, callback, userdata)
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,bytesEachRequest,
 *                                         totalBytes, eWidth, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_TransferSubmitSingleTransfer(handle, psTransfer0);
 *      EDMA_TransferStart(handle);
 *     @endcode
 *
 *  6. Continuous single transfer request(using transactional layer dynamic scatter gather feature)
 *     @code
 *      EDMA_TransferCreateHandle(handle, base, channel, tcdPool, tcdPoolCount, callback, userdata)
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer0, srcAddr, dstAddr,bytesEachRequest,
 *                                         totalBytes, eWidth, kEDMA_ChannelTransferMemoryToMemory);
 *      psTransfer->u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      psTransfer->srcAddrModulo = xxx;
 *      EDMA_TransferSubmitSingleTransfer(handle, psTransfer0);
 *      EDMA_TransferStart(handle);
 *
 *      EDMA_TransferSubmitSingleTransfer(handle, psTransfer1);
 *      EDMA_TransferSubmitSingleTransfer(handle, psTransfer2);
 *      .....
 *     @endcode
 *
 *  7. Loop transfer request(using transactional layer)
 *     @code
 *      EDMA_TransferCreateHandle(handle, base, channel, tcdPool, tcdPoolCount, callback, userdata);
 *
 *      EDMA_GetChannelDefaultTransferConfig(&scatterGather[0],srcAddr,dstAddr,bytesEachRequest,totalBytes,eWidth,
 *      kEDMA_ChannelTransferMemoryToMemory);
 *      scatterGather[0].u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *      EDMA_GetChannelDefaultTransferConfig(&scatterGather[1],srcAddr,dstAddr,bytesEachRequest,totalBytes,eWidth,
 *      kEDMA_ChannelTransferMemoryToMemory);
 *      scatterGather[0].u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_TransferSubmitLoopTransfer(handle, &scatterGather[0], 2U);
 *      EDMA_TransferStart(handle);
 *     @endcode
 *
 *  8. Transfer between peripheral(one fifo only) and memory (using edma channel functional layer)\n
 *     Peripheral to memory:
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferPeripheralToMemory);
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *     Memory to peripheral：
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannrlTransferMemoryToPeripheral);
 *      psTransfer.u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *      EDMA_EnableChannelRequest(base, channel, true);
 *
 *     @endcode
 *
 *  9. Transfer between peripheral(multi fifo, assume fifo number 4, fifo address offset 4) and memory. \n
 *     Peripheral to memory, reading 4 fifo data from peripheral and write to continuous memory block(using edma channel
 *     functional layer)
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannelTransferPeripheralToMemory);
 *      psTransfer.i16SrcReadOffset = 4U;
 *      psTransfer.bEnableSrcMinorLoopOffset = true;
 *      psTransfer.i32MinorLoopOffset = -16U;
 *      psTransfer.u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *     Memory to peripheral, writing data from continuous memory block to 4 fifo
 *     @code
 *      EDMA_GetChannelDefaultTransferConfig(&psTransfer, srcAddr, dstAddr,4,
 *                                         256, kEDMA_TransferWidth32Bits, kEDMA_ChannrlTransferMemoryToPeripheral);
 *      psTransfer.i16DstOffsetOfEachTransfer = 4U;
 *      psTransfer.bEnableDstMinorLoopOffset = true;
 *      psTransfer.i32MinorLoopOffset = -16U;
 *      psTransfer.u16EnabledInterruptMask = kEDMA_ChannelMajorLoopCompleteInterruptEnable;
 *
 *      EDMA_GetDefaultConfig(&config);
 *      config.psChannelTransferConfig[0]= &psTransfer;
 *      EDMA_Init(DMA, channel, &config);
 *
 *      EDMA_EnableChannelRequest(base, channel, true);
 *     @endcode
 *
 *  @}
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief edma transactional tcd pool resource protection lock definition
 * Application should overwrite below two macros if multi task trying to access the same channel.
 */
#ifndef EDMA_ENTER_CRITICAL_SECTION
#define EDMA_ENTER_CRITICAL_SECTION()
#endif
#ifndef EDMA_LEAVE_CRITICAL_SECTION
#define EDMA_LEAVE_CRITICAL_SECTION()
#endif

/*! @brief _edma_transfer_status eDMA transfer status
 *  @anchor _edma_transfer_status
 *  The enumerator used for transactional interface only.
 */
enum
{
    kStatus_EDMA_ChannelQueueFull = MAKE_STATUS(kStatusGroup_EDMA, 0), /*!< TCD queue is full. */
    kStatus_EDMA_ChannelBusy      = MAKE_STATUS(kStatusGroup_EDMA, 1), /*!< Channel is busy and can't handle the
                                                                     transfer request. */
};

/*! @brief eDMA transfer type */
typedef enum _edma_channel_transfer_type
{
    kEDMA_ChannelTransferMemoryToMemory = 0x0U, /*!< Transfer type from memory to memory assume that the both source and
                                                   destination address are incremental */
    kEDMA_ChannelTransferPeripheralToMemory,    /*!< Transfer type peripher to memory assume that the source address is
                                                   fixed */
    kEDMA_ChannelTransferMemoryToPeripheral,    /*!< Transfer type from memory to peripheral assume that the destination
                                                   address is fixed */
    kEDMA_ChannelTransferPeripheralToPeripheral, /*!< Transfer type from Peripheral to peripheral assume that both
                                                    source and destination address are fixed */
} edma_channel_transfer_type_t;

/*! @brief eDMA interrupt source
 *
 * The eDMA peripheral support generate interrupt when half of the total request bytes transferred or
 * all of the request bytes transferred.
 *
 * @anchor _edma_channel_interrupt_enable
 *
 */
enum _edma_channel_interrupt_enable
{
    kEDMA_ChannelErrorInterruptEnable = 1U, /*!< Enable error interrupt */
    kEDMA_ChannelMajorLoopCompleteInterruptEnable =
        DMA_CSR_INTMAJOR_MASK, /*!< Enable interrupt while major count exhausted. */
    kEDMA_ChannelMajorLoopHalfCompleteInterruptEnable =
        DMA_CSR_INTHALF_MASK, /*!< Enable interrupt while major count to half value. */
    kEDMA_ChannelAllInterruptEnable = kEDMA_ChannelErrorInterruptEnable | DMA_CSR_INTMAJOR_MASK |
                                      DMA_CSR_INTHALF_MASK, /*!< Enable all the interrupt. */
};

/*!@brief _edma_channel_status_flags eDMA channel status flags.
 *  @anchor _edma_channel_status_flags
 */
enum _edma_channel_status_flags
{
    kEDMA_ChannelStatusErrorFlag = 0x1U, /*!< eDMA error flag, an error occurred in a transfer */
    kEDMA_ChannelStatusMajorLoopCompleteFlag =
        0x2U, /*!< Major loop complete flag, set while transfer finished, CITER value exhausted*/
    kEDMA_ChannelStatusMajorLoopHalfCompleteFlag = 0x4U, /*!< Major loop half complete flag */
};

/*! @brief _edma_error_status_flags eDMA channel detail error status flags.
 *   @anchor _edma_error_status_flags
 */
enum _edma_error_status_flags
{
    kEDMA_ChannelDestinationBusErrorFlag = DMA_ES_DBE_MASK, /*!< Bus error on destination address */
    kEDMA_ChannelSourceBusErrorFlag      = DMA_ES_SBE_MASK, /*!< Bus error on the source address */
    kEDMA_ChannelScatterGatherErrorFlag =
        DMA_ES_SGE_MASK,                            /*!< Error on the Scatter/Gather address, not 32byte aligned. */
    kEDMA_ChannelNbytesErrorFlag = DMA_ES_NCE_MASK, /*!< NBYTES/CITER configuration error */
    kEDMA_ChannelDestinationOffsetErrorFlag =
        DMA_ES_DOE_MASK, /*!< Destination offset not aligned with destination size */
    kEDMA_ChannelDestinationAddressErrorFlag =
        DMA_ES_DAE_MASK,                                   /*!< Destination address not aligned with destination size */
    kEDMA_ChannelSourceOffsetErrorFlag  = DMA_ES_SOE_MASK, /*!< Source offset not aligned with source size */
    kEDMA_ChannelSourceAddressErrorFlag = DMA_ES_SAE_MASK, /*!< Source address not aligned with source size*/
    kEDMA_ChannelErrorChannelFlag     = DMA_ES_ERRCHN_MASK, /*!< Error channel number of the canceled channel number */
    kEDMA_ChannelPriorityErrorFlag    = DMA_ES_CPE_MASK,    /*!< Channel priority is not unique. */
    kEDMA_ChannelTransferCanceledFlag = DMA_ES_ECX_MASK,    /*!< Transfer canceled */
#if defined(FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT) && (FSL_FEATURE_EDMA_CHANNEL_GROUP_COUNT > 1)
    kEDMA_ChannelGroupPriorityErrorFlag = DMA_ES_GPE_MASK, /*!< Group priority is not unique. */
#endif
    kEDMA_ChannelValidFlag = DMA_ES_VLD_MASK, /*!< No error occurred, this bit is 0. Otherwise, it is 1. */
};

/*! @brief eDMA arbitration type */
typedef enum _edma_arbitration_type
{
    kEDMA_ArbitrationFixedPriority = 0x0U, /*!< channel arbitration by fixed priority  */
    kEDMA_ArbitrationRoundRobin,           /*!< Channel arbitration by round robin */
} edma_arbitration_type_t;

/*!@brief edma channel index */
typedef enum _edma_channel
{
    kEDMA_Channel0 = 0U, /*!< EDMA channel 0 */
    kEDMA_Channel1 = 1U, /*!< EDMA channel 1 */
    kEDMA_Channel2 = 2U, /*!< EDMA channel 2 */
    kEDMA_Channel3 = 3U, /*!< EDMA channel 3 */
} edma_channel_t;

/*! @brief eDMA transfer width configuration */
typedef enum _edma_channel_transfer_width
{
    kEDMA_ChannelTransferWidth8Bits   = 0U,   /*!< Source/Destination data transfer width is 1 byte every time */
    kEDMA_ChannelTransferWidth16Bits  = 1U,   /*!< Source/Destination data transfer width is 2 bytes every time */
    kEDMA_ChannelTransferWidth32Bits  = 2U,   /*!< Source/Destination data transfer width is 4 bytes every time */
    kEDMA_ChannelTransferWidth128Bits = 0x4U, /*!< Source/Destination data transfer size is 16 bytes every time */
} edma_channel_transfer_width_t;

/*! @brief eDMA channel modulo configuration
 *
 * The eDMA modulo feature can be used to specify the address range of the source/destination address, it is
 * useful to implement a circular data queue.
 */
typedef enum _edma_channel_modulo
{
    kEDMA_ChannelModuloDisable = 0x0U, /*!< Disable modulo */
    kEDMA_ChannelModulo2bytes,         /*!< Circular buffer size is 2 bytes. */
    kEDMA_ChannelModulo4bytes,         /*!< Circular buffer size is 4 bytes. */
    kEDMA_ChannelModulo8bytes,         /*!< Circular buffer size is 8 bytes. */
    kEDMA_ChannelModulo16bytes,        /*!< Circular buffer size is 16 bytes. */
    kEDMA_ChannelModulo32bytes,        /*!< Circular buffer size is 32 bytes. */
    kEDMA_ChannelModulo64bytes,        /*!< Circular buffer size is 64 bytes. */
    kEDMA_ChannelModulo128bytes,       /*!< Circular buffer size is 128 bytes. */
    kEDMA_ChannelModulo256bytes,       /*!< Circular buffer size is 256 bytes. */
    kEDMA_ChannelModulo512bytes,       /*!< Circular buffer size is 512 bytes. */
    kEDMA_ChannelModulo1Kbytes,        /*!< Circular buffer size is 1 K bytes. */
    kEDMA_ChannelModulo2Kbytes,        /*!< Circular buffer size is 2 K bytes. */
    kEDMA_ChannelModulo4Kbytes,        /*!< Circular buffer size is 4 K bytes. */
    kEDMA_ChannelModulo8Kbytes,        /*!< Circular buffer size is 8 K bytes. */
    kEDMA_ChannelModulo16Kbytes,       /*!< Circular buffer size is 16 K bytes. */
    kEDMA_ChannelModulo32Kbytes,       /*!< Circular buffer size is 32 K bytes. */
    kEDMA_ChannelModulo64Kbytes,       /*!< Circular buffer size is 64 K bytes. */
    kEDMA_ChannelModulo128Kbytes,      /*!< Circular buffer size is 128 K bytes. */
    kEDMA_ChannelModulo256Kbytes,      /*!< Circular buffer size is 256 K bytes. */
    kEDMA_ChannelModulo512Kbytes,      /*!< Circular buffer size is 512 K bytes. */
    kEDMA_ChannelModulo1Mbytes,        /*!< Circular buffer size is 1 M bytes. */
    kEDMA_ChannelModulo2Mbytes,        /*!< Circular buffer size is 2 M bytes. */
    kEDMA_ChannelModulo4Mbytes,        /*!< Circular buffer size is 4 M bytes. */
    kEDMA_ChannelModulo8Mbytes,        /*!< Circular buffer size is 8 M bytes. */
    kEDMA_ChannelModulo16Mbytes,       /*!< Circular buffer size is 16 M bytes. */
    kEDMA_ChannelModulo32Mbytes,       /*!< Circular buffer size is 32 M bytes. */
    kEDMA_ChannelModulo64Mbytes,       /*!< Circular buffer size is 64 M bytes. */
    kEDMA_ChannelModulo128Mbytes,      /*!< Circular buffer size is 128 M bytes. */
    kEDMA_ChannelModulo256Mbytes,      /*!< Circular buffer size is 256 M bytes. */
    kEDMA_ChannelModulo512Mbytes,      /*!< Circular buffer size is 512 M bytes. */
    kEDMA_ChannelModulo1Gbytes,        /*!< Circular buffer size is 1 G bytes. */
    kEDMA_ChannelModulo2Gbytes,        /*!< Circular buffer size is 2 G bytes. */
} edma_channel_modulo_t;

/*! @brief edma channel Bandwidth control
 *
 * Generally, as the eDMA processes the minor loop, it continuously generates read/write sequences
 * until the minor count is exhausted. This bandwidth field forces the eDMA to stall after the completion of
 * each read/write access to control the bus request bandwidth.
 *
 * The default configuration is kEDMA_BandwidthStallNone.
 */
typedef enum _edma_channel_bandwidth
{
    kEDMA_ChannelBandwidthStallNone   = 0x0U, /*!< No eDMA engine stalls. */
    kEDMA_ChannelBandwidthStall4Cycle = 0x2U, /*!< eDMA engine stalls for 4 cycles after each read/write. */
    kEDMA_ChannelBandwidthStall8Cycle = 0x3U, /*!< eDMA engine stalls for 8 cycles after each read/write. */
} edma_channel_bandwidth_t;

/*! @brief eDMA channel priority configuration, useful to the fixed priority arbitration type */
typedef struct _edma_channel_Preemption_config
{
    bool bSuspendedByHighPriorityChannel : 1; /*!< a channel can be suspended by other channel with higher priority */
    bool bSuspendLowPriorityChannel : 1;      /*!< a channel can suspend other channel with low priority */
    uint8_t u8ChannelPriority : 5;            /*!< Channel priority */
} edma_channel_Preemption_config_t;

/*!
 * @brief edma channel software tcd definition
 * @anchor edma_channel_tcd_t
 */
typedef struct _edma_channel_tcd edma_channel_tcd_t;

/*! @brief edma channel transfer configuration
 *
 * The transfer configuration structure support full feature configuration of the transfer control descriptor.
 *
 * @note User should pay attention to the transfer size alignment limitation
 *       1. the u32BytesEachRequest should align with the  eSrcWidthOfEachTransfer and the eDstWidthOfEachTransfer
 *          that is to say u32BytesEachRequest % eSrcWidthOfEachTransfer should be 0
 *       2. the i16SrcOffsetOfEachTransfer and i16DstOffsetOfEachTransfer must be aligne with transfer width
 *       3. the u32TotalBytes should align with the u32BytesEachRequest
 *       4. the u32SrcAddr should align with the eSrcWidthOfEachTransfer
 *       5. the u32DstAddr should align with the eDstWidthOfEachTransfer
 *       6. the u32SrcAddr should align with eSrcAddrModulo if modulo feature is enabled
 *       7. the u32DstAddr should align with eDstAddrModulo if modulo feature is enabled
 *       If anyone of above condition can not be satisfied, the edma interfaces will generate assert error.
 *
 * 1.To perform a simple transfer, below members should be initialized at least
 * .u32SrcAddr - source address
 * .u32DstAddr - destination address
 * .eSrcWidthOfEachTransfer - data width of source address
 * .eDstWidthOfEachTransfer - data width of destination address, normally it should be as same as
 * eSrcWidthOfEachTransfer .u32BytesEachRequest - bytes to be transferred in each DMA request .u32TotalBytes - total
 * bytes to be transferred .i16SrcOffsetOfEachTransfer - offset value in bytes unit to be applied to source address as
 * each source read is completed .i16DstOffsetOfEachTransfer - offset value in bytes unit to be applied to destination
 * address as each destination write is completed bEnableChannelRequest - channel request can be enabled together with
 * transfer configure submission
 *
 * 2.The transfer configuration structure also support advance feature:
 * Programmable source/destination address range(MODULO)
 * Programmable minor loop offset
 * Programmable major loop offset
 * Programmable channel chain feature
 * Programmable channel transfer control descriptor link feature
 *
 */
typedef struct _edma_channel_transfer_config
{
    uint32_t u32SrcAddr; /*!< source address */
    uint32_t u32DstAddr; /*!< destination address */

    edma_channel_transfer_width_t eSrcWidthOfEachTransfer; /*!< source width of each transfer */
    edma_channel_transfer_width_t eDstWidthOfEachTransfer; /*!< destination width of each transfer */

    uint32_t u32BytesEachMinorLoop;           /*!< bytes in each minor loop or each request
                                               * range: 1 - (2^30 -1) when minor loop mapping is enabled
                                               * range: 1 - (2^10 - 1) when minor loop mapping is enabled and source or dest minor
                                               * loop offset is enabled
                                               * range: 1 - (2^32 - 1) when minor loop mapping is disabled
                                               */
    uint16_t u16MinorLoopCountsEachMajorLoop; /*!< minor loop counts in each major loop, should be 1 at least for each
                                               * transfer range: (0 - (2^15 - 1)) when minor loop channel link is
                                               * disabled range: (0 - (2^9 - 1)) when minor loop channel link is enabled
                                               * total bytes in a transfer = u16MinorLoopCountsEachMajorLoop *
                                               * u32BytesEachMinorLoop
                                               */
    uint16_t u16EnabledInterruptMask;         /*!< channel interrupt to enable, can be OR'ed value of @ref
                                                 _edma_channel_interrupt_enable */

    int16_t i16SrcOffsetOfEachTransfer;   /*!< Sign-extended offset value in byte unit applied to the current source
                                address to form the next-state   value as each source read is completed */
    edma_channel_modulo_t eSrcAddrModulo; /*!< source circular data queue range */
    int32_t i32SrcMajorLoopOffset;        /*!< source major loop offset */

    int16_t i16DstOffsetOfEachTransfer; /*!< Sign-extended offset value in byte unit applied to the current destination
                               address to form the next-state value as each destination write is completed. */
    edma_channel_modulo_t eDstAddrModulo; /*!< destination circular data queue range */
    int32_t i32DstMajorLoopOffset;        /*!< destination major loop offset */

    bool bEnableSrcMinorLoopOffset; /*!< enable source minor loop offset */
    bool bEnableDstMinorLoopOffset; /*!< enable dest minor loop offset */
    int32_t i32MinorLoopOffset;     /*!< burst offset, the offset will be applied after minor loop update */

    bool bEnableChannelMajorLoopLink;     /*!< channel link when major loop complete */
    edma_channel_t eMajorLoopLinkChannel; /*!< major loop link channel number */

    bool bEnableChannelMinorLoopLink;     /*!< channel link when minor loop complete */
    edma_channel_t eMinorLoopLinkChannel; /*!< minor loop link channel number */

    edma_channel_bandwidth_t eChannelBandWidth; /*!< channel bandwidth */

    bool bDisableRequestAfterMajorLoopComplete; /*!< the channel's ERQ bit can be cleared after the major loop complete
                                                  automatically */

    bool bEnableChannelRequest; /*!< enable the channel request signal */

    edma_channel_tcd_t *psLinkTCD; /*!< pointer to the link transfer control descriptor */
} edma_channel_transfer_config_t;

/*!
 * @brief eDMA software Transfer control descriptor structure.
 *
 * This structure is same as eDMA hardware channel TCD registers, user doesn't need to understand the
 * structures, since eDMA driver will responsible for configure it.
 *
 * The software TCD is useful to configure a software TCD which is linked by the channel hardware TCD to have
 * scatter/gather feature without using transactional interface.
 */
struct _edma_channel_tcd
{
    __IO uint32_t u32SADDR;  /*!< SADDR register, used to save source address */
    __IO uint16_t u16SOFF;   /*!< SOFF register, offset bytes added to source address every transfer */
    __IO uint16_t u16ATTR;   /*!< ATTR register, source/destination transfer size and modulo */
    __IO uint32_t u32NBYTES; /*!< Nbytes register, minor loop length in bytes */
    __IO uint32_t u32SLAST;  /*!< SLAST register, adjustment value added to the source address at the completion of the
                                major loop */
    __IO uint32_t u32DADDR;  /*!< DADDR register, used for destination address */
    __IO uint16_t u16DOFF;   /*!< DOFF register, offset bytes added to destination address every transfer */
    __IO uint16_t u16CITER;  /*!< CITER register, current minor loop numbers, for unfinished minor loop.*/
    __IO uint32_t u32DLAST_SGA; /*!< DLASTSGA register, next tcd address used in scatter-gather mode */
    __IO uint16_t u16CSR;       /*!< CSR register, for TCD control status */
    __IO uint16_t u16BITER;     /*!< BITER register, begin minor loop count. */
};

/*! @brief edma configuration structure
 *
 * This structure target for whole edma module configurations.
 */
typedef struct _edma_config
{
    bool bEnableContinuousLinkMode; /*!< Enable (true) continuous link mode. Upon minor loop completion, the channel
                                         activates again if that channel has a minor loop channel link enabled and
                                         the link channel is itself. */
    bool bEnableHaltOnError;        /*!< Enable (true) transfer halt on error. Any error causes the HALT bit to set.
                                         Subsequently, all service requests are ignored until the HALT bit is cleared.*/
    bool bEnableDmaInDebugMode;     /*!< Enable(true) eDMA debug mode. When in debug mode, the eDMA stalls the start of
                                         a new channel. Executing channels are allowed to complete. */
    bool bEnableMinorLoopMapping; /*!< TCDn.word2 is redefined to include individual enable fields, an offset field, and
                                     the NBYTES field. The individual enable fields allow the minor loop offset to be
                                     applied to the source address, the destination address, or both. The NBYTES field
                                     is reduced when either offset is enabled */
    edma_arbitration_type_t eArbitrationType; /*!< Enable (true) round robin channel arbitration method or fixed
                                                 priority arbitration is used for channel selection */
    edma_channel_Preemption_config_t
        sChannelPreemptionConfig[FSL_FEATURE_EDMA_MODULE_CHANNEL]; /*!< channel preemption configuration */

    edma_channel_transfer_config_t
        *psChannelTransferConfig[FSL_FEATURE_EDMA_MODULE_CHANNEL]; /*!< channel transfer configuration pointer */
} edma_config_t;

/*!
 * @brief handler for eDMA
 * @anchor edma_handle_t
 */
typedef struct _edma_handle edma_handle_t;

/*! @brief Define callback function for eDMA.
 *
 * This callback function is called in the EDMA interrupt handler function.
 * In normal mode, running into callback function means the transfer users need is done.
 * In scatter gather mode, run into callback function means a transfer control block (tcd) is finished. Not
 * all transfer finished, users can get the finished tcd numbers using interface EDMA_GetUnusedTCDNumber.
 *
 * @param handle EDMA handle pointer, users shall not touch the values inside.
 * @param userData The callback user parameter pointer. Users can use this parameter to involve things users need to
 *                 change in EDMA callback function.
 * @param transferDone If the current loaded transfer done. In normal mode it means if all transfer done. In scatter
 *                     gather mode, this parameter shows is the current transfer block in EDMA register is done. As the
 *                     load of core is different, it will be different if the new tcd loaded into EDMA registers while
 *                     this callback called. If true, it always means new tcd still not loaded into registers, while
 *                     false means new tcd already loaded into registers.
 * @param tcds How many tcds are done from the last callback. This parameter only used in scatter gather mode. It
 *             tells user how many tcds are finished between the last callback and this.
 */
typedef void (*edma_transfer_callback_t)(edma_handle_t *psHandle,
                                         void *pUserData,
                                         bool bTransferDone,
                                         uint32_t u32Tcds);

/*! @brief eDMA transfer handle structure */
struct _edma_handle
{
    edma_transfer_callback_t pfCallback; /*!< Callback function for major count exhausted. */
    void *pUserData;                     /*!< Callback function parameter. */
    DMA_Type *psBase;                    /*!< eDMA peripheral base address. */
    edma_channel_tcd_t *psTcdPool;       /*!< Pointer to memory stored TCDs. */
    edma_channel_t eChannel;             /*!< eDMA channel number. */
    volatile uint8_t
        u8Header; /*!< The first TCD index. Should point to the next TCD to be loaded into the eDMA engine. */
    volatile uint8_t u8Tail; /*!< The last TCD index. Should point to the next TCD to be stored into the memory pool. */
    volatile uint8_t u8TcdUsed; /*!< The number of used TCD slots. Should reflect the number of TCDs can be used/loaded
                               in the memory. */
    volatile uint8_t u8TcdSize; /*!< The total number of TCD slots in the queue. */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name eDMA Initialization and De-initialization interfaces
 * @{
 */
/*!
 * @brief Get default edma peripheral configuration.
 *
 * @note This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *
 * @param psConfig pointer to user's eDMA config structure, see edma_config_t for detail.
 */
void EDMA_GetDefaultConfig(edma_config_t *psConfig);

/*!
 * @brief EDMA initialization
 *
 * @param base eDMA peripheral base address.
 * @param psConfig pointer to user's eDMA config structure, see edma_transfer_config_t for detail.
 */
void EDMA_Init(DMA_Type *base, edma_config_t *psConfig);

/*!
 * @brief EDMA De-initialization
 *
 * @param base eDMA peripheral base address.
 */
void EDMA_Deinit(DMA_Type *base);

/*! @} */

/*!
 * @name eDMA non-channel functional interfaces
 * @{
 */

/*!
 * @brief Enable/Disable arbitration before the channel been activate by minor loop link trigger from itself.
 *
 * A minor loop channel link made to itself does not go through channel arbitration before being
 * activated again. Upon minor loop completion, the channel activates again if that channel has a
 * minor loop channel link enabled and the link channel is itself. This effectively applies the minor loop
 * offsets and restarts the next minor loop.
 *
 * @note Do not use continuous link mode with a channel linking to itself if there is only one minor loop
 * iteration per service request, for example, if the channel's NBYTES value is the same as either
 * the source or destination size. The same data transfer profile can be achieved by simply
 * increasing the NBYTES value, which provides more efficient, faster processing.
 *
 * @param base EDMA peripheral base address.
 * @param bEnable true is channel link to itself without arbitration
                  false is channel link to itself with arbitration
 */
static inline void EDMA_EnableContinuousChannelLinkMode(DMA_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR |= DMA_CR_CLM_MASK;
    }
    else
    {
        base->CR &= ~DMA_CR_CLM_MASK;
    }
}

/*!
 * @brief Enable/Disable redefine the minor loop bytes register.
 *
 * The TCDn.word2 is redefined to include individual enable fields, an offset field and the
 * NBYTES field, the offset will be applied to source/destination address after minor loop complete
 *
 * @param base EDMA peripheral base address.
 * @param bEnable true is minor loop bytes register redefined to individual enable/offset/minor loop bytes fields.
 *                false is minor loop bytes register defined as minor loop bytes fields only.
 */
static inline void EDMA_EnableMinorLoopMapping(DMA_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR |= DMA_CR_EMLM_MASK;
    }
    else
    {
        base->CR &= ~DMA_CR_EMLM_MASK;
    }
}

/*!
 * @brief Enable/Disable the eDMA halt when error occur feature.
 *
 * Any error causes the HALT bit to set will cause the EDMA halt. Subsequently, all service requests are ignored until
 * the HALT bit is cleared
 *
 * @param base EDMA peripheral base address.
 * @param bEnable true is Stall the start of any new channels when error occur.
 *                false is eDMA service request operation normal when error occur.
 */
static inline void EDMA_EnableHaltOnError(DMA_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->CR |= DMA_CR_HOE_MASK;
    }
    else
    {
        base->CR &= ~DMA_CR_HOE_MASK;
    }
}

/*!
 * @brief set EDMA arbitration type to fixed priority or round robin.
 *
 * @param base EDMA peripheral base address.
 * @param eArbitration Arbitration by priority or round robin, @ref edma_arbitration_type_t.
 */
static inline void EDMA_SetArbitration(DMA_Type *base, edma_arbitration_type_t eArbitration)
{
    base->CR = (base->CR & (~DMA_CR_ERCA_MASK)) | DMA_CR_ERCA(eArbitration);
}

/*! @} */

/*!
 * @name eDMA channel functional interfaces
 * @{
 */

/*!
 * @brief Get channel default transfer configuration.
 *
 * @note 1. This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *       2. No interrupt enabled by this function by default, if application would like to use DMA interrupt
 *          please enable it manually by psTransfer->u16EnabledInterruptMask = _edma_channel_interrupt
 *
 * @param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 * @param u32SrcAddr source address, must be byte address.
 * @param u32DstAddr destination address,  must be byte address.
 * @param u32BytesEachRequest bytes to be transferred in each request(namely, in each minor loop).
 * @param u32TotalBytes total bytes to be transferred.
 * @param eTransferWidth it represents how many bits are transferred in each read/write.
 * @param eTransferType eDMA channel transfer type.
 */
void EDMA_GetChannelDefaultTransferConfig(edma_channel_transfer_config_t *psTransfer,
                                          uint32_t u32SrcAddr,
                                          uint32_t u32DstAddr,
                                          uint32_t u32BytesEachRequest,
                                          uint32_t u32TotalBytes,
                                          edma_channel_transfer_width_t eTransferWidth,
                                          edma_channel_transfer_type_t eTransferType);

/*!
 * @brief EDMA set channel transfer configurations
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 *
 * @note
 * 1.This function must not be called while the channel transfer is ongoing
 * or it causes unpredictable results.
 * 2.The psLinkTCD must be configured before invoke this API if scatter/gather function is needed
 * 3.The edma channel request may be enabled after the channel transfer configure done according to the transfer
 *   configurations.
 *
 */
void EDMA_SetChannelTransferConfig(DMA_Type *base, edma_channel_t eChannel, edma_channel_transfer_config_t *psTransfer);

/*!
 * @brief Configures the eDMA channel minor loop offset value.
 *
 * The minor offset means that the signed-extended value is added to the source address or destination
 * address after each minor loop.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param bEnableSrcMinorLoopOffset True is enable source address minor offset, otherwise is disable
 * @param bEnableDestMinorLoopOffset True is enable source address minor offset, otherwise is disable
 * @param i32MinorLoopOffset Minor loop offset value.
 */
void EDMA_SetChannelMinorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    bool bEnableSrcMinorLoopOffset,
                                    bool bEnableDestMinorLoopOffset,
                                    int32_t i32MinorLoopOffset);

/*!
 * @brief Configures the eDMA channel preemption configurations.
 *
 * This function configures the channel preemption attribute and the priority of the channel.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number
 * @param bSuspendedByHighPriorityChannel True is the channel can be suspended by high priority channel, otherwise
 * cannot.
 * @param bSuspendLowPriorityChannel True is the channel can suspend low priority channel, otherwise cannot.
 * @param u8Priority Channel priority.
 *
 * @note, this function is used only in fixed-priority channel arbitration mode.
 */
void EDMA_SetChannelPreemption(DMA_Type *base,
                               edma_channel_t eChannel,
                               bool bSuspendedByHighPriorityChannel,
                               bool bSuspendLowPriorityChannel,
                               uint8_t u8Priority);

/*!
 * @brief Enable the minor loop channel link and configure the linked channel number.
 *
 * This function configures the minor link mode. The minor link means that the channel link is
 * triggered every time that the minor loop bytes transferred complete.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param eLinkChannel The linked channel number.
 * @note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 */
void EDMA_EnableMinorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel);

/*!
 * @brief Disable the minor loop channel link for the eDMA transfer.
 *
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 */
static inline void EDMA_DisableMinorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel)
{
    base->TCD[(uint8_t)eChannel].CITER_ELINKYES &= ~(uint16_t)DMA_CITER_ELINKYES_LINKCH_MASK;
    base->TCD[(uint8_t)eChannel].BITER_ELINKYES &= ~(uint16_t)DMA_CITER_ELINKYES_LINKCH_MASK;
}

/*!
 * @brief Enable the major loop channel link and configure the linked channel number.
 *
 * This function configures the major link mode. The major link means that the channel link is triggered when the CITER
 * is exhausted.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param eLinkChannel The linked channel number.
 * @note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 */
void EDMA_EnableMajorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel, edma_channel_t eLinkChannel);

/*!
 * @brief Disable the major loop channel link for the eDMA transfer.
 *
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 */
static inline void EDMA_DisableMajorLoopChannelLink(DMA_Type *base, edma_channel_t eChannel)
{
    base->TCD[(uint8_t)eChannel].CSR &= ~(uint16_t)DMA_CSR_MAJORLINKCH_MASK;
}

/*!
 * @brief Sets the edma channel stall cycles after each R/W.
 *
 * Because the eDMA processes the minor loop, it continuously generates read/write sequences
 * until the minor count is exhausted. The bandwidth forces the eDMA to stall after the completion of
 * each read/write access to control the bus request bandwidth seen by the crossbar switch.
 *
 * @note:
 * 1.If the source and destination sizes are equal, this field is ignored between the first and second
 * transfers and after the last write of each minor loop. This behavior is a side effect of reducing
 * start-up latency.
 * 2.When executing a large, zero wait-stated memory-to-memory transfer, insert bandwidth control
 * using the TCD_CSR[BWC] bits to avoid:
•*   Starvation of another master accessing the memory.
•*   Any delay in writing a TCD duloop the transfer.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param eBandWidth A bandwidth setting, which can be one of the @ref edma_channel_bandwidth_t
 */
void EDMA_SetChannelBandWidth(DMA_Type *base, edma_channel_t eChannel, edma_channel_bandwidth_t eBandWidth);

/*!
 * @brief Sets the source address range and the destination address range for the eDMA transfer.
 *
 * This function defines a specific address range of source/destination address, after the source/destination address
 * hits the range boundary, source/destination address will wrap to origin value.
 *
 * Setting this field provides the ability
 * to implement a circular data queue easily. For data queues require loop power-of-2 size bytes, the
 * queue should start at a 0-modulo-size address and the SMOD field should be set to the appropriate
 * value for the queue, freezing the desired number of upper address bits. The value programmed into
 * this field specifies the number of lower address bits allowed to change
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param eSrcModulo A source modulo value.
 * @param eDestModulo A destination modulo value.
 */
void EDMA_SetChannelModulo(DMA_Type *base,
                           edma_channel_t eChannel,
                           edma_channel_modulo_t eSrcModulo,
                           edma_channel_modulo_t eDestModulo);

/*!
 * @brief Enables the edma channel async request in stop mode.
 *
 * The EARS register is used to enable or disable the DMA requests in Enable Request
 * Register (ERQ) by AND'ing the bits of these two registers in stop mode only.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param bEnable The command to enable (true) or disable (false).
 */
static inline void EDMA_EnableChannelAsyncRequestInStopMode(DMA_Type *base, edma_channel_t eChannel, bool bEnable)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    if (bEnable)
    {
        base->EARS |= (1UL << ((uint8_t)eChannel));
    }
    else
    {
        base->EARS &= ~(1UL << ((uint8_t)eChannel));
    }
}

/*!
 * @brief Enables the edma channel auto disable request after major loop complete.
 *
 * The eDMA hardware automatically clears the corresponding ERQ bit when the current
 * major iteration count reaches zero.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param bEnable The command to enable (true) or disable (false).
 */
static inline void EDMA_EnableChannelAutoStopRequest(DMA_Type *base, edma_channel_t eChannel, bool bEnable)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->TCD[(uint8_t)eChannel].CSR = (uint16_t)((base->TCD[(uint8_t)eChannel].CSR & (~DMA_CSR_DREQ_MASK)) |
                                                  DMA_CSR_DREQ((true == bEnable ? 1U : 0U)));
}

/*!
 * @brief Configures the eDMA channel major loop offset feature.
 *
 * Adjustment value added to the source/destination address at the completion of the major iteration count
 *
 * @param base eDMA peripheral base address.
 * @param eChannel edma channel number.
 * @param i32SourceOffset source address offset.
 * @param i32DestOffset destination address offset.
 */
void EDMA_SetChannelMajorLoopOffset(DMA_Type *base,
                                    edma_channel_t eChannel,
                                    int32_t i32SourceOffset,
                                    int32_t i32DestOffset);

/*!
 * @brief Enable/disable the eDMA hardware channel request.
 *
 * This function enables the hardware channel request.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param bEnable true is start, false is stop.
 */
static inline void EDMA_EnableChannelRequest(DMA_Type *base, edma_channel_t eChannel, bool bEnable)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    if (bEnable)
    {
        base->SERQ = DMA_SERQ_SERQ(eChannel);
    }
    else
    {
        base->CERQ = DMA_CERQ_CERQ(eChannel);
    }
}

/*!
 * @brief Starts the eDMA transfer by using the software trigger.
 *
 * This function starts a minor loop transfer only, the channel will halt when minor loop complete, so application
 * should re-call the function to start the transfer again.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 */
static inline void EDMA_SoftwareTriggerChannelStart(DMA_Type *base, edma_channel_t eChannel)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->SSRT = DMA_SSRT_SSRT(eChannel);
}

/*!
 * @brief Gets the remaining major loop count from the eDMA current channel TCD.
 *
 * This function checks the TCD (Transfer Control Descriptor) status for a specified
 * eDMA channel and returns the number of major loop count that has not finished.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @retval Major loop count which has not been transferred yet for the current TCD.
 * @note 1. This function can only be used to get unfinished major loop count of transfer without
 *          the next TCD, or it might be inaccuracy.
 *       2. The unfinished/remaining transfer bytes cannot be obtained directly from registers while
 *          the channel is running.
 *          Because to calculate the remaining bytes, the initial NBYTES configured in DMA_TCDn_NBYTES_MLNO
 *          register is needed while the eDMA IP does not support getting it while a channel is active.
 *          In another word, the NBYTES value reading is always the actual (decrementing) NBYTES value the dma_engine
 *          is working with while a channel is running.
 *          Consequently, to get the remaining transfer bytes, a software-saved initial value of NBYTES (for example
 *          copied before enabling the channel) is needed. The formula to calculate it is shown below:
 *          RemainingBytes = RemainingMajorLoopCount * NBYTES(initially configured)
 */
uint32_t EDMA_GetChannelRemainingMajorLoopCount(DMA_Type *base, edma_channel_t eChannel);

/*! @} */

/*!
 * @name eDMA Channel interrupt Interfaces
 * @{
 */
/*!
 * @brief Enables the edma channel interrupts according to a provided mask,
 *        the mask is a logical OR of enumerator members @ref _edma_channel_interrupt_enable.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param u16InterruptsMask the mask is a logical OR of enumerator members @ref _edma_channel_interrupt_enable.
 * @param bEnable true is enable, false is disable.
 *
 */
void EDMA_EnableChannelInterrupts(DMA_Type *base, edma_channel_t eChannel, uint16_t u16InterruptsMask, bool bEnable);

/*! @} */

/*!
 * @name eDMA Channel Status Interfaces
 * @{
 */

/*!
 * @brief Gets the eDMA channel status flags.
 *
 * @note if the function return error status, application can call @ref EDMA_GetErrorStatusFlags for
 *       the detail error status.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @retval The mask of channel status flags. Users need to use the
 *         _edma_channel_status_flags type to decode the return variables.
 */
uint16_t EDMA_GetChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel);

/*!
 * @brief Clears the eDMA channel status flags.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param u16StatusFlags The mask of channel status to be cleared. Users need to use
 *             the defined _edma_channel_status_flags type.
 */
void EDMA_ClearChannelStatusFlags(DMA_Type *base, edma_channel_t eChannel, uint16_t u16StatusFlags);

/*!
 * @brief Gets the eDMA channel error status flags.
 *
 * @param base eDMA peripheral base address.
 * @return The mask of error status flags. Users need to use the
 *         @ref _edma_error_status_flags type to decode the return variables.
 */
static inline uint32_t EDMA_GetErrorStatusFlags(DMA_Type *base)
{
    return base->ES;
}

/*! @} */

/*!
 * @name eDMA software TCD Interfaces
 * @{
 */
/*!
 * @brief Sets TCD fields according to the user's channel transfer configuration structure, @ref
 * edma_channel_transfer_config_t.
 *
 * Application should be careful about the TCD pool buffer storage class,
 * - For the platform has cache, the software TCD should be put in non cache section
 * - The TCD pool buffer should have a consistent storage class.
 *
 * @note Application should be careful when using the minor loop offset feature with this function, please make sure the
 * EMLM bit is asserted, although EDMA_InitChannel will set this bit by default, if the bit is cleared, application can
 *       use @ref EDMA_EnableMinorLoopMapping to enable the feature.
 *
 * @param psTcd Pointer to the TCD structure.
 * @param psTransfer channel transfer configuration pointer.
 *
 * @note This function enables the auto stop request feature.
 */
void EDMA_ConfigChannelSoftwareTCD(edma_channel_tcd_t *psTcd, edma_channel_transfer_config_t *psTransfer);

/*!
 * @brief Push content of software TCD structure into hardware TCD register.
 *
 * @param base EDMA peripheral base address.
 * @param eChannel EDMA channel number.
 * @param psTcd Point to TCD structure.
 */
void EDMA_InstallChannelSoftwareTCD(DMA_Type *base, edma_channel_t eChannel, edma_channel_tcd_t *psTcd);

/*! @} */

/*!
 * @name eDMA Transactional Interfaces
 * @{
 */

/*!
 * @brief Creates the eDMA channel handle.
 *
 * This function is called if using the transactional API for eDMA. This function
 * initializes the internal state of the eDMA handle.
 *
 * @param base eDMA peripheral base address.
 * @param psHandle eDMA handle pointer. The eDMA handle stores callback function and
 *               parameters.
 * @param eChannel eDMA channel number.
 * @param psTcdPool A memory pool to store TCDs. It must be 32 bytes aligned.
 * @param u32TcdCount The number of TCD slots.
 * @param pfCallback eDMA callback function pointer.
 * @param pUserData A parameter for the callback function.
 *
 */
void EDMA_TransferCreateHandle(DMA_Type *base,
                               edma_handle_t *psHandle,
                               edma_channel_t eChannel,
                               edma_channel_tcd_t *psTcdPool,
                               uint32_t u32TcdCount,
                               edma_transfer_callback_t pfCallback,
                               void *pUserData);

/*!
 * @brief Submits the eDMA single transfer configuration.
 *
 * Application can submit single transfer when
 * 1. channel is idle, the transfer request will be submitted to eDMA channel TCD register directly
 * 2. channel is idle, a previous transfer request is pending, the new transfer request will be submitted to the
 * installed TCD pool and linked to the pending one.
 * 3. channel is active, the transfer request will be submitted to the installed TCD pool and linked to previous one.
 *
 * @note,
 * 1.Please be aware of that tcd pool maintain is unprotect by default, that is to say, the behavior of multiple task
 * trying to access the same channel is undefine, application can protect the channel by itself or overwrite
 * EDMA_ENTER_CRITICAL_SECTION/EDMA_LEAVE_CRITICAL_SECTION to have edma driver protect the TCD pool maintain.
 * 2.Since the destination major loop offset feature register is reused as scatter gather tcd address, so the two
 * features cannot be used together, if the destination major loop offset feature is used, then the transfer request
 * will be submit hardware TCD directly.
 *
 * It is suggest that application should check the return value of this function to make sure that the transfer request
 * is submitted successfully.
 *
 * @param psHandle eDMA handle pointer.
 * @param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail.
 *
 * @retval #kStatus_Success It means submit transfer request succeed.
 * @retval #kStatus_EDMA_ChannelQueueFull It means TCD queue is full. Submit transfer request is not allowed.
 */
status_t EDMA_TransferSubmitSingleTransfer(edma_handle_t *psHandle, edma_channel_transfer_config_t *psTransfer);

/*!
 * @brief Submits the eDMA scatter gather transfer configurations.
 *
 * The function is target for submit loop transfer request,
 * the ring transfer request means that the transfer request TAIL is link to HEAD, such as,
 * A->B->C->D->A, or A->A
 *
 * To use the ring transfer feature, the application should allocate several transfer object, such as
 * @code
 * edma_channel_transfer_config_t transfer[2];
 * EDMA_TransferSubmitLoopTransfer(psHandle, &transfer, 2U);
 * @endcode
 * Then eDMA driver will link transfer[0] and transfer[1] to each other
 *
 * @note Application should check the return value of this function to avoid transfer request
 * submit failed
 *
 * @param psHandle eDMA handle pointer
 * @param psTransfer pointer to user's eDMA channel configure structure, see edma_channel_transfer_config_t for detail
 * @param transferLoopCount the count of the transfer ring, if loop count is 1, that means that the one will link to
 * itself.
 *
 * @retval #kStatus_Success It means submit transfer request succeed
 * @retval #kStatus_EDMA_ChannelBusy channel is in busy status
 * @retval #kStatus_EDMA_ChannelQueueFull It means TCD pool is not len enough for the ring transfer request
 */
status_t EDMA_TransferSubmitLoopTransfer(edma_handle_t *psHandle,
                                         edma_channel_transfer_config_t *psTransfer,
                                         uint32_t transferLoopCount);

/*!
 * @brief eDMA starts transfer.
 *
 * This function enables the channel request. Users can call this function after submitting the transfer request
 * or before submitting the transfer request.
 *
 * @param psHandle eDMA handle pointer.
 */
void EDMA_TransferStart(edma_handle_t *psHandle);

/*!
 * @brief eDMA stops transfer.
 *
 * This function disables the channel request to pause the transfer. Users can call EDMA_StartTransfer()
 * again to resume the transfer.
 *
 * @param psHandle eDMA handle pointer.
 */
void EDMA_TransferStop(edma_handle_t *psHandle);

/*!
 * @brief eDMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * @param psHandle DMA handle pointer.
 */
void EDMA_TransferAbort(edma_handle_t *psHandle);

/*!
 * @brief eDMA IRQ handler for the current major loop transfer completion.
 *
 * This function clears the channel major interrupt flag and calls
 * the callback function if it is not NULL.
 *
 * Note:
 * For the case using TCD queue, when the major iteration count is exhausted, additional Interfaces are performed.
 * These include the final address adjustments and reloading of the BITER field into the CITER.
 * Assertion of an optional interrupt request also occurs at this time, as does a possible fetch of a new TCD from
 * memory using the scatter/gather address pointer included in the descriptor (if scatter/gather is enabled).
 *
 * For instance, when the time interrupt of TCD[0] happens, the TCD[1] has already been loaded into the eDMA engine.
 * As sga and sga_index are calculated based on the DLAST_SGA bit field lies in the TCD_CSR register, the sga_index
 * in this case should be 2 (DLAST_SGA of TCD[1] stores the address of TCD[2]). Thus, the "tcdUsed" updated should be
 * (tcdUsed - 2U) which indicates the number of TCDs can be loaded in the memory pool (because TCD[0] and TCD[1] have
 * been loaded into the eDMA engine at this point already.).
 *
 * For the last two continuous ISRs in a scatter/gather process, they  both load the last TCD (The last ISR does not
 * load a new TCD) from the memory pool to the eDMA engine when major loop completes.
 * Therefore, ensure that the header and tcdUsed updated are identical for them.
 * tcdUsed are both 0 in this case as no TCD to be loaded.
 *
 * See the "eDMA basic data flow" in the eDMA Functional description section of the Reference Manual for
 * further details.
 *
 * @param psHandle eDMA handle pointer.
 */
void EDMA_TransferHandleIRQ(edma_handle_t *psHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_EDMA_H_*/
