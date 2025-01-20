/*
 * Copyright 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DMA_H_
#define FSL_DMA_H_

#include "fsl_common.h"

/*!
 * @defgroup dma DMA: Direct Memory Access Driver
 * @details This document consists of sections titled with <b>Driver Overview</b>, <b>Data Structures</b>,
 *          <b>Enumerations</b>, <b>Functions</b>, etc., each with an overview list and detailed documentation.
 *          It is recommended to read the <b>Driver Overview</b> first for it includes a comprehensive description
 *          of the peripheral, driver and driver changes. Other sections give detailed information for APIs, enums,
 *          macros, etc., for your further reference.
 * @{
 */

/*! @name Driver version */
/*! @{ */
/*! @brief DMA driver version. */
#define FSL_DMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * DMA peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup dma_driver_log The Driver Change Log
 * @ingroup dma
 * @{
 * The current DMA driver version is 2.0.0.
 *
 * - 2.0.0
 *   - Initial version.
 * @}
 */

/*******************************************************************************
 * DMA peripheral driver overview
 ******************************************************************************/

/*!
 * @defgroup dma_intro DMA Peripheral and Driver Overview
 * @ingroup dma
 * @brief Content including 1) peripheral features, work logic and work method; 2) driver design logic and use method;
 *        3) typical use case.
 * @{
 * Peripheral features
 * ===================
 * The DMA controller module enables fast transfers of data, providing an efficient way to
 * move blocks of data with minimal processor interaction.
 *
 *  + Four independently programmable DMA controller channels
 *  + Dual-address transfers via 32-bit master connection to the system bus
 *  + Data transfers in 8-, 16-, or 32-bit blocks
 *  + Continuous-mode or cycle-steal transfers from software or peripheral initiation
 *  + One programmable input selected from 16 possible peripheral requests per channel
 *  + Automatic hardware acknowledge/done indicator from each channel
 *  + Independent source and destination address registers
 *  + Optional modulo addressing and automatic updates of source and destination addresses
 *  + Independent transfer sizes for source and destination
 *  + Optional auto-alignment feature for source or destination accesses
 *  + Optional automatic single or double channel linking
 *  + Programming model accessed via 32-bit slave peripheral bus
 *  + Channel arbitration on transfer boundaries using fixed priority scheme

 * How this peripheral works
 * =========================
 *  As soon as a channel has been initialized, it may be started by setting DCRn[START] or
 *  a properly-selected peripheral DMA request, depending on the status of DCRn[ERQ].
 *  Each channel can be programmed to select one peripheral request from a set of 16
 *  possible request inputs.
 *  The DMA controller supports dual-address transfers using its bus master connection to
 *  the system bus. The DMA channels support transfers up to 32 data bits in size and have
 *  the same memory map addressibility as the processor.
 *  Any operation involving a DMA channel follows the same three steps:
 *  1. Channel initialization
 *  The transfer control descriptor, contained in the channel
 *  registers, is loaded with address pointers, a byte-transfer count, and control
 *  information using accesses from the slave peripheral bus.
 *  2. Data transfer
 *  The DMA accepts requests for data transfers. Upon receipt of a
 *  request, it provides address and bus control for the transfers via its master connection
 *  to the system bus and temporary storage for the read data. The channel performs one
 *  or more source read and destination write data transfers.
 *  3. Channel termination
 *  Occurs after the operation is finished successfully or due to an
 *  error. The channel indicates the operation status in the channel's DSR, described in
 *  the definitions of the DMA Status Registers (DSRn) and Byte Count Registers
 *  (BCRn).

 * How this driver is designed to make this peripheral works
 * =========================================================
 * The DMA peripheral is powerful with complex transfer features supported.
 * To satisfy different user getting different demands for the feature sets/optimization level/flexibility/abstraction
 * level, 2 parallel layers are provided in this driver (DO NOT MIX THE USAGE OF THESE 2 LAYERS!!!):
 * - Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 *   features.
 *   All hardware features are supported while requiring user get a decent understanding of the hardware detail of DMA
 *   so that user know how to organize these functional API together to meet the requirement of application.
 * - Transactional layer is provided with average optimization level, average flexibility and not all features are
 *   covered.
 *   It is for user who want to ramp up the usage of peripheral quickly without dig much into this specific peripheral
 *   with only common knowledge of DMA peripheral model. It achieve this goal by hiding the processing of interrupt
 *   handling.
 *
 * Below introduce the detail data structure/API for the two layers.
 *
 * + Functional Layer
 *
 *   - Transfer Configuration
 *     The most important data structure usage is to configure the transfer attributes.
 *     The driver provide @ref dma_channel_transfer_config_t
 *     whose members expose all the transfer attributes supported by peripheral. However, it may still complex / fussy
 *     for user who need not such many features.
 *     A helper function DMA_GetChannelDefaultTransferConfig is provided to get a ready-to-use
 *     configuration with only basic information required. User can create the @ref dma_channel_transfer_config_t
 *     himself/herself if he/she is comfortable with that way or use the helper function
 *     DMA_GetChannelDefaultTransferConfig to get initial data structure and then fine-tune needed members per
 *     requirement.
 *
 *    - Channel Identifier
 *      All channel is represented with a enumerator provided in @ref dma_channel_t that user need not bother with
 *      whether channel 0 shall be 0 or 1 for register access.
 *
 *    - Functional layer provide multiple API function groups
 *      + DMA initialization and De-initialization Interfaces
 *        - The interfaces target for whole module configuration which includes:
 *          + All channels specific transfer configuration.
 *        - The interfaces provide helper function assist user to get a ready-to-use @ref dma_config_t
 *          with easy-to-understand parameter filled to assist the usage of Init API.
 *
 *      + DMA channel functional interfaces
 *        - The interfaces provide a api that support configure the full transfer parameters of a
 *          channel.
 *        - The interfaces provide helper function assist user to get a ready-to-use @ref dma_channel_transfer_config_t
 *          with easy-to-understand parameter filled to assist the usage of Init API.
 *
 *      + DMA Channel Status Interfaces
 *        - The interfaces in the function group can be used to get/clear the channel status
 *
 *      + DMA Channel Interrupt Interfaces
 *        - The interfaces in the function group can be used to Enable/Disable channel interrupt
 *
 * + Transactional Layer
 *
 *    To distinguish from Functional layer,  all transactional API get Transfer in the naming of the API.
 *
 *    In parallel with the Functional layer, the driver provide the transactional layer remove user the effort below
 *    thus user can easily get DMA peripheral features enabled with least coding effort and much less knowledge
 *    requirement on this peripheral
 *    - User need not spent effort on prepare the interrupt handler function from vector entry to the user code.
 *
 *    Comparing to functional layer,
 *    - Transactional layer use the @ref dma_handle_t to represent a channel and
 *      user need the DMA_CreateHandle function to initialize the handle. This handler will be stored inside driver
 *      thus channel state is retained in software level which is crucial in interrupt context.
 *    - Transactional use same data structure  @ref dma_channel_transfer_config_t to configure the
 *      transfer to keep the consistent usage experience across this driver
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
 *      DMA_TransferChannelCreateHandle and when interrupt happens, callback will be invoked
 *      immediately that user codes can be executed when interrupt happens.
 *
 *    Several function groups are provided for the transactional layer
 *    - Transaction Initialization Interface
 *      + Init the channel with a user provided handle memory data structure with callback requested for inserting user
 *        code on completion of transfer
 *
 *    - Transaction Transfer Configuration Interface
 *      + Interfaces to submit transfer
 *
 *    - Transaction Start/Stop Interface
 *      + Start/Stop/Abort the transfer
 *
 *    - Transaction Interrupt Handler
 *      + Interrupt handling function which is called in the 'double weak' function. User is not necessary to understand
 *        it but can take it as reference code to understand how this driver work
 *
 *  How to use this driver
 *  ======================
 *  Functional Layer
 *  ------------------
 *    + Configuration option on compiling
 *      - if FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is defined, so please make sure that the DMA clock gate is enabled
 *        before DMA driver interface being invoked if driver does not handle it.
 *
 *      - If interrupt mode is used, setup the interrupt handler entry to execute the application codes
 *
 *    + Driver Interface invoking Sequence
 *      - Initialize the DMA peripheral
 *        Use the DMA Initialization and De-initialization Interfaces. DMA driver provides an interface
 *        DMA_Init which is target for whole module configurations.
 *        + If the application would like to submit transfer configuration by DMA_Init, please reference steps
 *          Prepare transfer configuration and then skip to step Trigger the transfer.
 *        + If the channel request is enabled in the transfer configuration, please skips steps Trigger the transfer
 *          also.
 *
 *      - Prepare transfer configuration
 *        + Use the @ref dma_channel_transfer_config_t to prepare the transfer attributes and use the
 *          DMA_GetChannelDefaultTransferConfig to assist the creation of the transfer configure. 3 typical modes are
 *          supported on getting the default configuration
 *          - Memory To Memory: Transfer data from memory to memory which means tranSfer address of source/destination
 *            address is incremental.
 *          - Memory To Peripheral: Transfer data from memory to peripheral where destination address is fixed.
 *            A typical case is sending a buffer by UART send register.
 *          - Peripheral To Memory: Transfer data from peripheral to memory buffer where source address is fixed.
 *            A typical case is receiving data into memory buffer on UART RX.
 *
 *      - Submit the transfer
 *        - Application can submit the transfer configurations by calling DMA_SetChannelTransferConfig.
 *
 *      - Trigger the transfer
 *        + User can trigger transfer manually using DMA_TriggerChannelStart/DMA_EnableChannelPeripheralRequest
 *
 *      - Track the completion of transfer
 *        + Use API DMA_GetChannelStatusFlags to know whether it is done
 *
 *      - De-initialize the DMA peripheral channel
 *        DMA driver provides an interface DMA_Deinit which will reset
 *        all the channel relate transfer control descriptor registers.
 *
 *  Transactional Layer
 *  --------------------
 *    + Configuration option on compiling
 *      - if FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL is defined, so please make sure that the DMA clock gate is enabled
 *        before DMA driver interface being invoked if driver does not handle it.
 *
 *    + Steps shall be covered in application codes rather than in driver
 *      - Same as functional layer except that interrupt entry need not be setup by user.
 *
 *    + Driver Interface invoking Sequence
 *      - Initialize the DMA peripheral
 *        Use the DMA Initialization and De-initialization Interfaces. DMA driver provides an interface
 *        DMA_Init which is target for whole module configurations, channel transfer configuration should not be
 *        submitted with DMA_Init while using transactional layer.
 *
 *      - Init the handle by calling DMA_TransferCreateHandle with optional callback provided.
 *
 *      - Configure the Transfer
 *        + Call DMA_TransferSubmitTransfer, user can submit the transfer request any
 *          time.
 *
 *      - Start/Stop/Abort channel use the DMA_TransferChannelStart/DMA_TransferChannelStop/DMA_TransferChannelAbort
 *
 *      - Handle transfer completion
 *        + User's code will be executed on completion of transfer or transfers where it is provided in callback
 *          function on DMA_TransferChannelCreateHandle.
 *
 *  Typical Use Cases
 *  =================
 *  1. single transfer (using dma transactional layer)
 *     @code
 *      DMA_Init(DEMO_DMA_BASEADDR, &dmaConfig);
 *      DMA_TransferChannelCreateHandle(DEMO_DMA_BASEADDR, &g_DMA_Handle, DEMO_DMA_CHANNEL_0, DMA_Callback, NULL);
 *      DMA_GetChannelDefaultTransferConfig(&transferConfig, g_u32SrcAddr, g_u32DestAddr,
 *                                          sizeof(g_u32SrcAddr[0]) * BUFF_LENGTH, kDMA_ChannelTransferWidth8Bits,
 *                                          kDMA_ChannelTransferMemoryToMemory);
 *      DMA_TransferChannelSubmit(&g_DMA_Handle, &transferConfig);
 *      DMA_TransferChannelStart(&g_DMA_Handle, false);
 *     @endcode
 *  2. Memory to peripheral (using kDmaCH0_IIC0_ipd_Req as peripheral)
 *     @code
 *      DMA_Init(DEMO_DMA_BASEADDR, &dmaConfig);
 *      DMA_SetChannelPeripheralRequest(DEMO_DMA_BASEADDR, DEMO_DMA_CHANNEL_0, kDmaCH0_IIC0_ipd_Req);
 *      DMA_TransferChannelCreateHandle(DEMO_DMA_BASEADDR, &g_DMA_Handle, DEMO_DMA_CHANNEL_0, DMA_Callback, NULL);
 *      DMA_GetChannelDefaultTransferConfig(&transferConfig, g_u32SrcAddr, g_u32DestAddr,
 *                                          sizeof(g_u32SrcAddr[0]) * BUFF_LENGTH, kDMA_ChannelTransferWidth8Bits,
 *                                          kDMA_ChannelTransferMemoryToPeripheral);
 *      DMA_TransferChannelSubmit(&g_DMA_Handle, &transferConfig);
 *      DMA_TransferChannelStart(&g_DMA_Handle, true);
 *     @endcode
 *  @}
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief _dma_channeltransfer_status DMA transfer status
 *  @anchor _dma_transfer_status
 *  The enumerator used for transactional interface only.
 */
enum
{
    kStatus_DMA_ChannelBusy = MAKE_STATUS(kStatusGroup_DMA, 0), /*!< Channel is busy and can't handle the
                                                                transfer request. */
};

/*! @brief DMA channel transfer type */
typedef enum _dma_channel_transfer_type
{
    kDMA_ChannelTransferMemoryToMemory = 0x0U, /*!< Transfer type from memory to memory assume that the both source and
                                                   destination address are incremental */
    kDMA_ChannelTransferPeripheralToMemory,    /*!< Transfer type peripher to memory assume that the source address is
                                                   fixed */
    kDMA_ChannelTransferMemoryToPeripheral,    /*!< Transfer type from memory to peripheral assume that the destination
                                                   address is fixed */
} dma_channel_transfer_type_t;

/*! @brief DMA interrupt source
 *  @anchor _dma_channel_interrupt_enable
 */
enum _dma_channel_interrupt_enable
{
    kDMA_ChannelInterruptEnable, /*!< Enable interrupt while transfer complete. */
};

/*! @brief _dma_channel_status_flags DMA channel status flags.
 *  @anchor _dma_channel_status_flags
 */
enum _dma_channel_status_flags
{
    kDMA_ChannelTransactionsBCRFlag = DMA_DSR_BCR_BCR_MASK,      /*!< Contains the number of bytes yet to be
                                                               transferred for a given block */
    kDMA_ChannelTransactionsDoneFlag    = DMA_DSR_BCR_DONE_MASK, /*!< Transactions Done */
    kDMA_ChannelTransactionsBusyFlag    = DMA_DSR_BCR_BSY_MASK,  /*!< Transactions Busy */
    kDMA_ChannelTransactionsRequestFlag = DMA_DSR_BCR_REQ_MASK,  /*!< Transactions Request */
};

/*! @brief _dma_error_status_flags DMA channel detail error status flags.
 *  @anchor _dma_error_status_flags
 */
enum _dma_error_status_flags
{
    kDMA_ChannelConfigurationErrorFlag =
        DMA_DSR_BCR_CE_MASK, /*!< Any of the following conditions causes a configuration error:
                                    BCR, SAR, or DAR does not match the requested transfer size.
                                    SSIZE or DSIZE is set to an unsupported value.
                                    BCR equals 0 when the DMA receives a start condition.
                                  CE is cleared at hardware reset or by writing a 1 to DONE. */
    kDMA_ChannelBusErrorOnSourceFlag =
        DMA_DSR_BCR_BES_MASK, /*!< BES is cleared at hardware reset or by writing a 1 to DONE. */
    kDMA_ChannelBusErrorOnDestinatiFlag =
        DMA_DSR_BCR_BED_MASK, /*!< BED is cleared at hardware reset or by writing a 1 to DONE. */
};

/*!@brief DMA channel index */
typedef enum _dma_channel
{
    kDMA_Channel0 = 0U, /*!< DMA channel 0 */
    kDMA_Channel1 = 1U, /*!< DMA channel 1 */
    kDMA_Channel2 = 2U, /*!< DMA channel 2 */
    kDMA_Channel3 = 3U, /*!< DMA channel 3 */
} dma_channel_t;

/*! @brief DMA transfer width configuration */
typedef enum _dma_channel_transfer_width
{
    kDMA_ChannelTransferWidth32Bits = 0x0U, /*!< Source/Destination data transfer width is 4 byte every time */
    kDMA_ChannelTransferWidth8Bits,         /*!< Source/Destination data transfer width is 1 bytes every time */
    kDMA_ChannelTransferWidth16Bits,        /*!< Source/Destination data transfer width is 2 bytes every time */

} dma_channel_transfer_width_t;

/*! @brief DMA channel modulo configuration
 *
 * The DMA modulo feature can be used to specify the address range of the source/destination address, it is
 * useful to implement a circular data queue.
 */
typedef enum _dma_channel_modulo
{
    kDMA_ChannelModuloDisable = 0x0U, /*!< Disable modulo */
    kDMA_ChannelModulo16bytes,        /*!< Circular buffer size is 16 bytes. */
    kDMA_ChannelModulo32bytes,        /*!< Circular buffer size is 32 bytes. */
    kDMA_ChannelModulo64bytes,        /*!< Circular buffer size is 64 bytes. */
    kDMA_ChannelModulo128bytes,       /*!< Circular buffer size is 128 bytes. */
    kDMA_ChannelModulo256bytes,       /*!< Circular buffer size is 256 bytes. */
    kDMA_ChannelModulo512bytes,       /*!< Circular buffer size is 512 bytes. */
    kDMA_ChannelModulo1Kbytes,        /*!< Circular buffer size is 1 K bytes. */
    kDMA_ChannelModulo2Kbytes,        /*!< Circular buffer size is 2 K bytes. */
    kDMA_ChannelModulo4Kbytes,        /*!< Circular buffer size is 4 K bytes. */
    kDMA_ChannelModulo8Kbytes,        /*!< Circular buffer size is 8 K bytes. */
    kDMA_ChannelModulo16Kbytes,       /*!< Circular buffer size is 16 K bytes. */
    kDMA_ChannelModulo32Kbytes,       /*!< Circular buffer size is 32 K bytes. */
    kDMA_ChannelModulo64Kbytes,       /*!< Circular buffer size is 64 K bytes. */
    kDMA_ChannelModulo128Kbytes,      /*!< Circular buffer size is 128 K bytes. */
    kDMA_ChannelModulo256Kbytes,      /*!< Circular buffer size is 256 K bytes. */
} dma_channel_modulo_t;

/*! @brief DMA channel link type */
typedef enum _dma_channel_link_type
{
    kDMA_ChannelLinkDisable = 0x0U,      /*!< No channel link. */
    kDMA_ChannelLinkChannel1AndChannel2, /*!< Perform a link to channel LCH1 after each cycle-steal transfer.
                                              followed by a link to LCH2 after the BCR decrements to 0. */
    kDMA_ChannelLinkChannel1,            /*!< Perform a link to LCH1 after each cycle-steal transfer. */
    kDMA_ChannelLinkChannel1AfterBCR0,   /*!< Perform a link to LCH1 after the BCR decrements. */
} dma_channel_link_type_t;

/*! @brief DMA channel link configuration structure */
typedef struct _dma_channel_link_config
{
    dma_channel_link_type_t linkType; /*!< Channel link type. */
    dma_channel_t eChannel1;          /*!< The index of channel 1. */
    dma_channel_t eChannel2;          /*!< The index of channel 2. */
} dma_channel_link_config_t;

/*! @brief DMA transfer address increment definition */
typedef enum _dma_channel_address_increment_type
{
    kDMA_ChannelAddressFix       = 0x0U, /*!< Address Fix */
    kDMA_ChannelAddressIncrement = 0x1U, /*!< Address increment */
} dma_channel_address_increment_type_t;

/*! @brief DMA channel transfer configuration structure
 *
 * The transfer configuration structure support full feature configuration of the transfer control descriptor.
 *
 */
typedef struct _dma_channel_transfer_config
{
    uint32_t u32SrcAddr;                                  /*!< source byte address */
    uint32_t u32DstAddr;                                  /*!< destination byte address */
    dma_channel_transfer_width_t eSrcWidthOfEachTransfer; /*!< source width of each transfer */
    dma_channel_transfer_width_t eDstWidthOfEachTransfer; /*!< destination width of each transfer */
    dma_channel_modulo_t
        eSrcAddrModulo; /*!< Defines the size of the source data circular buffer used by the DMA Controller */
    dma_channel_modulo_t
        eDstAddrModulo; /*!< defines the size of the destination data circular buffer used by the DMA Controller */
    dma_channel_address_increment_type_t eEnableSrcIncrement;  /*!< Source address increase after each transfer */
    dma_channel_address_increment_type_t eEnableDestIncrement; /*!< destination address increase after each transfer */
    dma_channel_link_config_t *pChannelLinkControl; /*!< allows DMA channels to have their transfers linked */

    uint32_t u32TransferSize;             /*!< the number of bytes to be transferred */
    bool bEnableInterrupt;                /*!< enable interrupt on completion of transfer */
    bool bEnableAutoAlign;                /*!< enable the channel auto align */
    bool bEnablAutoStopPeripheralRequest; /*!< DMA hardware automatically clears the corresponding DCRn[ERQ] bit
                         when the byte count register reaches 0. */
    bool bEnableCycleSteal;               /*!< enable cycle steal, forces a single read/write transfer per request */
} dma_channel_transfer_config_t;

/*! @brief DMA configuration structure
 *
 * This structure target for whole dma module configurations.
 */
typedef struct _dma_config
{
    dma_channel_transfer_config_t
        *psChannelTransferConfig[FSL_FEATURE_DMA_MODULE_CHANNEL]; /*!< channel transfer configuration pointer */
} dma_config_t;

/*!
 * @brief handler for DMA
 * @anchor dma_handle_t
 */
typedef struct _dma_handle dma_handle_t;

/*! @brief Define callback function for DMA.
 *
 * This callback function is called in the DMA interrupt handler function.
 * In normal mode, running into callback function means the transfer users need is done.
 *
 * @param psHandle DMA handle pointer, users shall not touch the values inside.
 * @param pUserData The callback user parameter pointer. Users can use this parameter to involve things users need to
 *                 change in DMA callback function.
 */
typedef void (*dma_transfer_callback_t)(dma_handle_t *psHandle, void *pUserData);

/*! @brief DMA transfer handle structure */
struct _dma_handle
{
    dma_transfer_callback_t pfCallback; /*!< DMA callback function.*/
    void *pUserData;                    /*!< Callback function parameter. */
    DMA_Type *psBase;                   /*!< DMA peripheral base address. */
    dma_channel_t eChannel;             /*!< DMA channel used. */
};

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name DMA Initialization and De-initialization interfaces
 * @{
 */

/*!
 * @brief DMA initialization
 *
 * @param base DMA peripheral base address.
 * @param psConfig pointer to user's DMA configure structure, see dma_config_t for detail.
 */
void DMA_Init(DMA_Type *base, dma_config_t *psConfig);

/*!
 * @brief DMA De-initialization
 *
 * @param base DMA peripheral base address.
 */
void DMA_Deinit(DMA_Type *base);

/*! @} */

/*!
 * @name DMA channel functional interfaces
 * @{
 */

/*!
 * @brief Resets the DMA channel.
 *
 * Sets all register values to reset values and enables
 * the cycle steal and auto stop channel request features.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 */
void DMA_ResetChannel(DMA_Type *base, dma_channel_t eChannel);

/*!
 * @brief Get channel default transfer configuration.
 *
 * @note 1. This function will reset all of the configuration structure members to zero firstly,
 *       then apply default configurations to the structure.
 *       2. No interrupt enabled by this function by default, if application would like to use DMA interrupt
 *          please enable it manually by psTransfer->u16EnabledInterruptMask = _dma_channel_interrupt
 *
 * @param psTransfer pointer to user's DMA channel configure structure, see dma_channel_transfer_config_t for detail.
 * @param u32SrcAddr source address, must be byte address.
 * @param u32DstAddr destination address,  must be byte address.
 * @param u32TotalBytes total bytes to be transferred.
 * @param eTransferWidth it represents how many bits are transferred in each read/write.
 * @param eTransferType DMA channel transfer type.
 */
void DMA_GetChannelDefaultTransferConfig(dma_channel_transfer_config_t *psTransfer,
                                         uint32_t u32SrcAddr,
                                         uint32_t u32DstAddr,
                                         uint32_t u32TotalBytes,
                                         dma_channel_transfer_width_t eTransferWidth,
                                         dma_channel_transfer_type_t eTransferType);

/*!
 * @brief DMA set channel transfer configurations
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param psTransfer pointer to user's DMA channel configure structure, see dma_channel_transfer_config_t for detail.
 */
void DMA_SetChannelTransferConfig(DMA_Type *base, dma_channel_t eChannel, dma_channel_transfer_config_t *psTransfer);

/*!
 * @brief Configures the DMA channel link feature.
 *
 * This function allows DMA channels to have their transfers linked. The current DMA channel
 * triggers a DMA request to the linked channels (LCH1 or LCH2) depending on the channel link
 * type.
 * Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2
 * after the BCR decrements to 0 if the type is kDMA_ChannelLinkChannel1AndChannel2.
 * Perform a link to LCH1 after each cycle-steal transfer if the type is kDMA_ChannelLinkChannel1.
 * Perform a link to LCH1 after the BCR decrements to 0 if the type is kDMA_ChannelLinkChannel1AfterBCR0.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param pLinkConfig Pointer to the channel link configuration structure.
 */
void DMA_SetChannelLinkConfig(DMA_Type *base, dma_channel_t eChannel, dma_channel_link_config_t *pLinkConfig);

/*!
 * @brief Sets the DMA source address for the DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param u32SrcAddr DMA source address.
 */
static inline void DMA_SetChannelSourceAddress(DMA_Type *base, dma_channel_t eChannel, uint32_t u32SrcAddr)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].SAR = u32SrcAddr;
}

/*!
 * @brief Sets the DMA destination address for the DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param u32DestAddr DMA destination address.
 */
static inline void DMA_SetChannelDestinationAddress(DMA_Type *base, dma_channel_t eChannel, uint32_t u32DestAddr)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DAR = u32DestAddr;
}

/*!
 * @brief Sets the DMA transfer size for the DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param u32TransferSize The number of bytes to be transferred.
 */
static inline void DMA_SetChannelTransferSize(DMA_Type *base, dma_channel_t eChannel, uint32_t u32TransferSize)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DSR_BCR =
        (base->DMA[(uint8_t)eChannel].DSR_BCR & (~DMA_DSR_BCR_BCR_MASK)) | DMA_DSR_BCR_BCR(u32TransferSize);
}

/*!
 * @brief Sets the DMA transfer peripheral number for the DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param eChannelRequestSource The number of request source.
 */
void DMA_SetChannelPeripheralRequest(DMA_Type *base,
                                     dma_channel_t eChannel,
                                     dma_channel_request_source_t eChannelRequestSource);

/*!
 * @brief Sets the source address range and the destination address range for the DMA transfer.
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
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param eSrcModulo A source modulo value.
 * @param eDestModulo A destination modulo value.
 */
void DMA_SetChannelModulo(DMA_Type *base,
                          dma_channel_t eChannel,
                          dma_channel_modulo_t eSrcModulo,
                          dma_channel_modulo_t eDestModulo);

/*!
 * @brief Enables the DMA cycle steal for the DMA transfer.
 *
 * If the cycle steal feature is enabled (true), the DMA controller forces a single read/write transfer per request,
 *  or it continuously makes read/write transfers until the BCR decrements to 0.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param bEnable The command for enable (true) or disable (false).
 */
static inline void DMA_EnableChannelCycleSteal(DMA_Type *base, dma_channel_t eChannel, bool bEnable)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DCR = (base->DMA[(uint8_t)eChannel].DCR & (~DMA_DCR_CS_MASK)) | DMA_DCR_CS(bEnable);
}

/*!
 * @brief Enables the DMA auto align for the DMA transfer.
 *
 * If the auto align feature is enabled (true), the appropriate address register increments
 * regardless of DINC or SINC.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param bEnable The command for enable (true) or disable (false).
 */
static inline void DMA_EnableChannelAutoAlign(DMA_Type *base, dma_channel_t eChannel, bool bEnable)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DCR = (base->DMA[(uint8_t)eChannel].DCR & (~DMA_DCR_AA_MASK)) | DMA_DCR_AA(bEnable);
}

/*! @} */

/*!
 * @name DMA Channel interrupt Interfaces
 * @{
 */

/*!
 * @brief Enables an interrupt for the DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @param bEnable The command for enable (true) or disable (false).
 */
static inline void DMA_EnableChannelInterrupt(DMA_Type *base, dma_channel_t eChannel, bool bEnable)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DCR =
        (base->DMA[(uint8_t)eChannel].DCR & (~DMA_DCR_EINT_MASK)) | DMA_DCR_EINT(bEnable);
}

/*! @} */

/*!
 * @name DMA Channel Transfer Operation
 * @{
 */

/*!
 * @brief Enables the DMA hardware channel request.
 *
 * @param base DMA peripheral base address.
 * @param eChannel The DMA channel number.
 * @param bEnable The command for enable (true) or disable (false).
 */
static inline void DMA_EnableChannelPeripheralRequest(DMA_Type *base, dma_channel_t eChannel, bool bEnable)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DCR =
        ((base->DMA[(uint8_t)eChannel].DCR) & (~DMA_DCR_ERQ_MASK)) | DMA_DCR_ERQ(bEnable);
}

/*!
 * @brief Starts the DMA transfer with a software trigger.
 *
 * This function starts only one read/write iteration.
 *
 * @param base DMA peripheral base address.
 * @param eChannel The DMA channel number.
 */
static inline void DMA_TriggerChannelStart(DMA_Type *base, dma_channel_t eChannel)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DCR |= DMA_DCR_START_MASK;
}

/*!
 * @brief Starts the DMA enable/disable auto disable request.
 *
 * @param base DMA peripheral base address.
 * @param eChannel The DMA channel number.
 * @param bEnable true is enable, false is disable.
 */
static inline void DMA_EnableChannelAutoStopRequest(DMA_Type *base, dma_channel_t eChannel, bool bEnable)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    if (bEnable)
    {
        base->DMA[(uint8_t)eChannel].DCR |= DMA_DCR_D_REQ(1);
    }
    else
    {
        base->DMA[(uint8_t)eChannel].DCR &= ~DMA_DCR_D_REQ_MASK;
    }
}

/*! @} */

/*!
 * @name DMA Channel Status Interfaces
 * @{
 */

/*!
 * @brief Gets the remaining bytes of the current DMA transfer.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @return The number of bytes which have not been transferred yet.
 */
static inline uint32_t DMA_GetChannelRemainingBytes(DMA_Type *base, dma_channel_t eChannel)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    return (base->DMA[(uint8_t)eChannel].DSR_BCR & DMA_DSR_BCR_BCR_MASK) >> DMA_DSR_BCR_BCR_SHIFT;
}

/*!
 * @brief Gets the DMA channel status flags.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 * @return The mask of the channel status. Use the _dma_channel_status_flags
 *         type to decode the return 32 bit variables.
 */
static inline uint32_t DMA_GetChannelStatusFlags(DMA_Type *base, dma_channel_t eChannel)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    return base->DMA[(uint8_t)eChannel].DSR_BCR;
}

/*!
 * @brief Clears the DMA channel status flags.
 *
 * @param base DMA peripheral base address.
 * @param eChannel DMA channel number.
 */
static inline void DMA_ClearChannelDoneStatus(DMA_Type *base, dma_channel_t eChannel)
{
    assert((uint32_t)eChannel < (uint32_t)FSL_FEATURE_DMA_MODULE_CHANNEL);

    base->DMA[(uint8_t)eChannel].DSR_BCR |= DMA_DSR_BCR_DONE(true);
}

/*! @} */

/*!
 * @name DMA Transactional Interfaces
 * @{
 */

/*!
 * @brief Creates the DMA handle.
 *
 * This function is called first if using the transactional API for the DMA. This function
 * initializes the internal state of the DMA handle.
 *
 * @param base DMA peripheral base address.
 * @param psHandle DMA handle pointer. The DMA handle stores callback function and
 *               parameters.
 * @param eChannel DMA channel number.
 * @param pfCallback DMA callback function pointer.
 * @param pUserData A parameter for the callback function.
 */
void DMA_TransferChannelCreateHandle(DMA_Type *base,
                                     dma_handle_t *psHandle,
                                     dma_channel_t eChannel,
                                     dma_transfer_callback_t pfCallback,
                                     void *pUserData);

/*!
 * @brief Submits the DMA transfer request.
 *
 * This function submits the DMA transfer request according to the transfer configuration structure.
 *
 * @param psHandle DMA handle pointer.
 * @param psTransfer Pointer to DMA transfer configuration structure.
 *
 * @retval kStatus_DMA_Success It indicates that the DMA submit transfer request succeeded.
 * @retval kStatus_DMA_ChannelBusy It indicates that the DMA is busy. Submit transfer request is not allowed.
 * @note This function can't process multi transfer request.
 */
status_t DMA_TransferChannelSubmit(dma_handle_t *psHandle, dma_channel_transfer_config_t *psTransfer);

/*!
 * @brief DMA starts transfer.
 *
 * This function enables the channel request. Call this function
 * after submitting a transfer request.
 *
 * @param psHandle DMA handle pointer.
 * @param bIsPeripheral  For true: enable DMA hardware request peripheral.
 * 				        For false: disable DMA hardware request peripheral.
 */
void DMA_TransferChannelStart(dma_handle_t *psHandle, bool bIsPeripheral);

/*!
 * @brief DMA stops a transfer.
 *
 * This function disables the channel request to stop a DMA transfer.
 * The transfer can be resumed by calling the DMA_StartTransfer.
 *
 * @param psHandle DMA handle pointer.
 */
void DMA_TransferChannelStop(dma_handle_t *psHandle);

/*!
 * @brief DMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * @param psHandle DMA handle pointer.
 */
void DMA_TransferChannelAbort(dma_handle_t *psHandle);

/*!
 * @brief DMA IRQ handler for current transfer complete.
 *
 * This function clears the channel interrupt flag and calls
 * the callback function if it is not NULL.
 *
 * @param psHandle DMA handle pointer.
 */
void DMA_TransferChannelHandleIRQ(dma_handle_t *psHandle);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_DMA_H_*/
