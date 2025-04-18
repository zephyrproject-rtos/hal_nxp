/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_EDMA_H_
#define FSL_EDMA_H_

#include "fsl_common.h"

/*!
 * @addtogroup dma3
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief eDMA driver version */
#define FSL_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 3, 1)) /*!< Version 2.3.1. */
/*! @} */

/*! @brief eDMA transfer configuration */
typedef enum _edma_transfer_size
{
    kEDMA_TransferSize1Bytes  = 0x0U, /*!< Source/Destination data transfer size is 1 byte every time */
    kEDMA_TransferSize2Bytes  = 0x1U, /*!< Source/Destination data transfer size is 2 bytes every time */
    kEDMA_TransferSize4Bytes  = 0x2U, /*!< Source/Destination data transfer size is 4 bytes every time */
    kEDMA_TransferSize8Bytes  = 0x3U, /*!< Source/Destination data transfer size is 8 bytes every time */
    kEDMA_TransferSize16Bytes = 0x4U, /*!< Source/Destination data transfer size is 16 bytes every time */
    kEDMA_TransferSize32Bytes = 0x5U, /*!< Source/Destination data transfer size is 32 bytes every time */
    kEDMA_TransferSize64Bytes = 0x6U, /*!< Source/Destination data transfer size is 64 bytes every time */
} edma_transfer_size_t;

/*! @brief eDMA modulo configuration */
typedef enum _edma_modulo
{
    kEDMA_ModuloDisable = 0x0U, /*!< Disable modulo */
    kEDMA_Modulo2bytes,         /*!< Circular buffer size is 2 bytes. */
    kEDMA_Modulo4bytes,         /*!< Circular buffer size is 4 bytes. */
    kEDMA_Modulo8bytes,         /*!< Circular buffer size is 8 bytes. */
    kEDMA_Modulo16bytes,        /*!< Circular buffer size is 16 bytes. */
    kEDMA_Modulo32bytes,        /*!< Circular buffer size is 32 bytes. */
    kEDMA_Modulo64bytes,        /*!< Circular buffer size is 64 bytes. */
    kEDMA_Modulo128bytes,       /*!< Circular buffer size is 128 bytes. */
    kEDMA_Modulo256bytes,       /*!< Circular buffer size is 256 bytes. */
    kEDMA_Modulo512bytes,       /*!< Circular buffer size is 512 bytes. */
    kEDMA_Modulo1Kbytes,        /*!< Circular buffer size is 1 K bytes. */
    kEDMA_Modulo2Kbytes,        /*!< Circular buffer size is 2 K bytes. */
    kEDMA_Modulo4Kbytes,        /*!< Circular buffer size is 4 K bytes. */
    kEDMA_Modulo8Kbytes,        /*!< Circular buffer size is 8 K bytes. */
    kEDMA_Modulo16Kbytes,       /*!< Circular buffer size is 16 K bytes. */
    kEDMA_Modulo32Kbytes,       /*!< Circular buffer size is 32 K bytes. */
    kEDMA_Modulo64Kbytes,       /*!< Circular buffer size is 64 K bytes. */
    kEDMA_Modulo128Kbytes,      /*!< Circular buffer size is 128 K bytes. */
    kEDMA_Modulo256Kbytes,      /*!< Circular buffer size is 256 K bytes. */
    kEDMA_Modulo512Kbytes,      /*!< Circular buffer size is 512 K bytes. */
    kEDMA_Modulo1Mbytes,        /*!< Circular buffer size is 1 M bytes. */
    kEDMA_Modulo2Mbytes,        /*!< Circular buffer size is 2 M bytes. */
    kEDMA_Modulo4Mbytes,        /*!< Circular buffer size is 4 M bytes. */
    kEDMA_Modulo8Mbytes,        /*!< Circular buffer size is 8 M bytes. */
    kEDMA_Modulo16Mbytes,       /*!< Circular buffer size is 16 M bytes. */
    kEDMA_Modulo32Mbytes,       /*!< Circular buffer size is 32 M bytes. */
    kEDMA_Modulo64Mbytes,       /*!< Circular buffer size is 64 M bytes. */
    kEDMA_Modulo128Mbytes,      /*!< Circular buffer size is 128 M bytes. */
    kEDMA_Modulo256Mbytes,      /*!< Circular buffer size is 256 M bytes. */
    kEDMA_Modulo512Mbytes,      /*!< Circular buffer size is 512 M bytes. */
    kEDMA_Modulo1Gbytes,        /*!< Circular buffer size is 1 G bytes. */
    kEDMA_Modulo2Gbytes,        /*!< Circular buffer size is 2 G bytes. */
} edma_modulo_t;

/*! @brief Bandwidth control */
typedef enum _edma_bandwidth
{
    kEDMA_BandwidthStallNone   = 0x0U, /*!< No eDMA engine stalls. */
    kEDMA_BandwidthStall4Cycle = 0x2U, /*!< eDMA engine stalls for 4 cycles after each read/write. */
    kEDMA_BandwidthStall8Cycle = 0x3U, /*!< eDMA engine stalls for 8 cycles after each read/write. */
} edma_bandwidth_t;

/*! @brief Channel link type */
typedef enum _edma_channel_link_type
{
    kEDMA_LinkNone = 0x0U, /*!< No channel link  */
    kEDMA_MinorLink,       /*!< Channel link after each minor loop */
    kEDMA_MajorLink,       /*!< Channel link while major loop count exhausted */
} edma_channel_link_type_t;

/*!@brief eDMA channel status flags, _edma_channel_status_flags */
enum
{
    kEDMA_DoneFlag      = 0x1U, /*!< DONE flag, set while transfer finished, CITER value exhausted*/
    kEDMA_ErrorFlag     = 0x2U, /*!< eDMA error flag, an error occurred in a transfer */
    kEDMA_InterruptFlag = 0x4U, /*!< eDMA interrupt flag, set while an interrupt occurred of this channel */
};

/*! @brief eDMA channel error status flags, _edma_error_status_flags */
enum
{
    kEDMA_DestinationBusErrorFlag = DMA_MP_ES_DBE_MASK, /*!< Bus error on destination address */
    kEDMA_SourceBusErrorFlag      = DMA_MP_ES_SBE_MASK, /*!< Bus error on the source address */
    kEDMA_ScatterGatherErrorFlag  = DMA_MP_ES_SGE_MASK, /*!< Error on the Scatter/Gather address, not 32byte aligned. */
    kEDMA_NbytesErrorFlag         = DMA_MP_ES_NCE_MASK, /*!< NBYTES/CITER configuration error */
    kEDMA_DestinationOffsetErrorFlag = DMA_MP_ES_DOE_MASK, /*!< Destination offset not aligned with destination size */
    kEDMA_DestinationAddressErrorFlag =
        DMA_MP_ES_DAE_MASK,                               /*!< Destination address not aligned with destination size */
    kEDMA_SourceOffsetErrorFlag  = DMA_MP_ES_SOE_MASK,    /*!< Source offset not aligned with source size */
    kEDMA_SourceAddressErrorFlag = DMA_MP_ES_SAE_MASK,    /*!< Source address not aligned with source size*/
    kEDMA_TransferCanceledFlag   = DMA_MP_ES_ECX_MASK,    /*!< Transfer cancelled */
    kEDMA_ErrorChannelFlag       = DMA_MP_ES_ERRCHN_MASK, /*!< Error channel number of the cancelled channel number */
    kEDMA_ValidFlag              = DMA_MP_ES_VLD_MASK,    /*!< No error occurred, this bit is 0. Otherwise, it is 1. */
};

/*! @brief eDMA channel system bus information, _edma_channel_sys_bus_info*/
enum
{
#if !(defined(FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR) && FSL_FEATURE_EDMA_HAS_NO_CH_SBR_ATTR)
    kEDMA_AttributeOutput = DMA_CH_SBR_ATTR_MASK, /*!< DMA's AHB system bus attribute output value. */
#endif

    kEDMA_PrivilegedAccessLevel = DMA_CH_SBR_PAL_MASK, /*!< Privileged Access Level for DMA transfers. 0b - User
                                                          protection level; 1b - Privileged protection level. */
    kEDMA_MasterId =
        DMA_CH_SBR_MID_MASK, /*!< DMA's master ID when channel is active and master ID replication is enabled. */
};

/*! @brief eDMA interrupt source */
typedef enum _edma_interrupt_enable
{
    kEDMA_ErrorInterruptEnable = 0x1U,                      /*!< Enable interrupt while channel error occurs. */
    kEDMA_MajorInterruptEnable = DMA_TCD_CSR_INTMAJOR_MASK, /*!< Enable interrupt while major count exhausted. */
    kEDMA_HalfInterruptEnable  = DMA_TCD_CSR_INTHALF_MASK,  /*!< Enable interrupt while major count to half value. */
} edma_interrupt_enable_t;

/*! @brief eDMA transfer type */
typedef enum _edma_transfer_type
{
    kEDMA_MemoryToMemory = 0x0U, /*!< Transfer from memory to memory */
    kEDMA_PeripheralToMemory,    /*!< Transfer from peripheral to memory */
    kEDMA_MemoryToPeripheral,    /*!< Transfer from memory to peripheral */
} edma_transfer_type_t;

/*! @brief eDMA transfer status, _edma_transfer_status*/
enum
{
    kStatus_EDMA_QueueFull = MAKE_STATUS(kStatusGroup_EDMA, 0), /*!< TCD queue is full. */
    kStatus_EDMA_Busy      = MAKE_STATUS(kStatusGroup_EDMA, 1), /*!< Channel is busy and can't handle the
                                                                     transfer request. */
};

/*! @brief eDMA global configuration structure.*/
typedef struct _edma_config
{
    bool enableMasterIdReplication; /*!< Enable (true) master ID replication. If Master ID replication is disabled, the
                                        privileged protection level (supervisor mode) for DMA transfers is used. */

    bool enableHaltOnError;           /*!< Enable (true) transfer halt on error. Any error causes the HALT bit to set.
                                           Subsequently, all service requests are ignored until the HALT bit is cleared.*/
    bool enableRoundRobinArbitration; /*!< Enable (true) round robin channel arbitration method or fixed priority
                                           arbitration is used for channel selection */
    bool enableDebugMode; /*!< Enable(true) eDMA debug mode. When in debug mode, the eDMA stalls the start of
                               a new channel. Executing channels are allowed to complete. */
#if !(defined FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW && FSL_FEATURE_EDMA_HAS_NO_MP_CSR_EBW)
    bool
        enableBufferedWrites; /*!< Enable(true) buffered writes. When buffered writes are enabled, all writes except for
                                   the last write sequence of the minor loop are signaled by the eDMA as bufferable. */
#endif

} edma_config_t;

/*!
 * @brief eDMA transfer configuration
 *
 * This structure configures the source/destination transfer attribute.
 */
typedef struct _edma_transfer_config
{
    uint32_t srcAddr;                      /*!< Source data address. */
    uint32_t destAddr;                     /*!< Destination data address. */
    edma_transfer_size_t srcTransferSize;  /*!< Source data transfer size. */
    edma_transfer_size_t destTransferSize; /*!< Destination data transfer size. */
    int16_t srcOffset;                     /*!< Sign-extended offset applied to the current source address to
                                                form the next-state value as each source read is completed. */
    int16_t destOffset;                    /*!< Sign-extended offset applied to the current destination address to
                                                form the next-state value as each destination write is completed. */
    uint32_t minorLoopBytes;               /*!< Bytes to transfer in a minor loop*/
    uint32_t majorLoopCounts;              /*!< Major loop iteration count. */
} edma_transfer_config_t;

/*! @brief eDMA channel priority configuration */
typedef struct _edma_channel_Preemption_config
{
    bool enableChannelPreemption; /*!< If true: a channel can be suspended by other channel with higher priority */
    bool enablePreemptAbility;    /*!< If true: a channel can suspend other channel with low priority */
    uint8_t channelPriority;      /*!< Channel priority */
} edma_channel_Preemption_config_t;

/*! @brief eDMA minor offset configuration */
typedef struct _edma_minor_offset_config
{
    bool enableSrcMinorOffset;  /*!< Enable(true) or Disable(false) source minor loop offset. */
    bool enableDestMinorOffset; /*!< Enable(true) or Disable(false) destination minor loop offset. */
    uint32_t minorOffset;       /*!< Offset for a minor loop mapping. */
} edma_minor_offset_config_t;

/*!
 * @brief eDMA TCD.
 *
 * This structure is same as TCD register which is described in reference manual,
 * and is used to configure the scatter/gather feature as a next hardware TCD.
 */
typedef struct _edma_tcd
{
    __IO uint32_t SADDR;     /*!< SADDR register, used to save source address */
    __IO uint16_t SOFF;      /*!< SOFF register, save offset bytes every transfer */
    __IO uint16_t ATTR;      /*!< ATTR register, source/destination transfer size and modulo */
    __IO uint32_t NBYTES;    /*!< Nbytes register, minor loop length in bytes */
    __IO uint32_t SLAST;     /*!< SLAST register */
    __IO uint32_t DADDR;     /*!< DADDR register, used for destination address */
    __IO uint16_t DOFF;      /*!< DOFF register, used for destination offset */
    __IO uint16_t CITER;     /*!< CITER register, current minor loop numbers, for unfinished minor loop.*/
    __IO uint32_t DLAST_SGA; /*!< DLASTSGA register, next stcd address used in scatter-gather mode */
    __IO uint16_t CSR;       /*!< CSR register, for TCD control status */
    __IO uint16_t BITER;     /*!< BITER register, begin minor loop count. */
} edma_tcd_t;

/*! @brief Callback for eDMA */
struct _edma_handle;

/*! @brief Define callback function for eDMA. */
typedef void (*edma_callback)(struct _edma_handle *handle, void *userData, bool transferDone, uint32_t tcds);

/*! @brief Memroy map function callback for DMA */
typedef uint32_t (*edma_memorymap_callback)(uint32_t addr);

/*! @brief eDMA transfer handle structure */
typedef struct _edma_handle
{
    edma_callback callback;  /*!< Callback function for major count exhausted. */
    void *userData;          /*!< Callback function parameter. */
    DMA_Type *base;          /*!< eDMA peripheral base address. */
    edma_tcd_t *tcdPool;     /*!< Pointer to memory stored TCDs. */
    uint8_t channel;         /*!< eDMA channel number. */
    volatile int8_t header;  /*!< The first TCD index. */
    volatile int8_t tail;    /*!< The last TCD index. */
    volatile int8_t tcdUsed; /*!< The number of used TCD slots. */
    volatile int8_t tcdSize; /*!< The total number of TCD slots in the queue. */
    uint8_t flags;           /*!< The status of the current channel. */
#if defined FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET && FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET
    edma_memorymap_callback memoryCallback; /*!< Callback function for memory map convert in complex system */
#endif                                      /* FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET */
} edma_handle_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name eDMA initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the eDMA peripheral.
 *
 * This function ungates the eDMA clock and configures the eDMA peripheral according
 * to the configuration structure.
 *
 * @param base eDMA peripheral base address.
 * @param config A pointer to the configuration structure, see "edma_config_t".
 * @note This function enables the minor loop map feature.
 */
void EDMA_Init(DMA_Type *base, const edma_config_t *config);

/*!
 * @brief Deinitializes the eDMA peripheral.
 *
 * This function gates the eDMA clock.
 *
 * @param base eDMA peripheral base address.
 */
void EDMA_Deinit(DMA_Type *base);

/*!
 * @brief Push content of TCD structure into hardware TCD register.
 *
 * @param base EDMA peripheral base address.
 * @param channel EDMA channel number.
 * @param tcd Point to TCD structure.
 */
void EDMA_InstallTCD(DMA_Type *base, uint32_t channel, edma_tcd_t *tcd);

/*!
 * @brief Gets the eDMA default configuration structure.
 *
 * This function sets the configuration structure to default values.
 * The default configuration is set to the following values:
 * @code
 *   config.enableMasterIdReplication = true;
 *   config.enableHaltOnError = true;
 *   config.enableRoundRobinArbitration = false;
 *   config.enableDebugMode = false;
 *   config.enableBufferedWrites = false;
 * @endcode
 *
 * @param config A pointer to the eDMA configuration structure.
 */
void EDMA_GetDefaultConfig(edma_config_t *config);

/*!
 * @brief Enables/disables all channel linking.
 *
 * This function enables/disables all channel linking in the management page.
 * For specific channel linking enablement & configuration, please refer to EDMA_SetChannelLink and
 * EDMA_TcdSetChannelLink APIs.
 *
 * For example, to disable all channel linking in the DMA0 management page:
 * @code
 *     EDMA_EnableAllChannelLink(DMA0, false);
 * @endcode
 *
 * @param base eDMA peripheral base address.
 * @param enable Switcher of the channel linking feature for all channels. "true" means to enable. "false" means not.
 */
static inline void EDMA_EnableAllChannelLink(DMA_Type *base, bool enable)
{
    if (enable)
    {
        base->MP_CSR |= DMA_MP_CSR_GCLC_MASK;
    }
    else
    {
        base->MP_CSR &= ~DMA_MP_CSR_GCLC_MASK;
    }
}

/*! @} */
/*!
 * @name eDMA Channel Operation
 * @{
 */

/*!
 * @brief Sets all TCD registers to default values.
 *
 * This function sets TCD registers for this channel to default values.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @note This function must not be called while the channel transfer is ongoing
 *       or it causes unpredictable results.
 * @note This function enables the auto stop request feature.
 */
void EDMA_ResetChannel(DMA_Type *base, uint32_t channel);

/*!
 * @brief Configures the eDMA transfer attribute.
 *
 * This function configures the transfer attribute, including source address, destination address,
 * transfer size, address offset, and so on. It also configures the scatter gather feature if the
 * user supplies the TCD address.
 * Example:
 * @code
 *  edma_transfer_config_t config;
 *  edma_tcd_t tcd;
 *  config.srcAddr = ..;
 *  config.destAddr = ..;
 *  ...
 *  EDMA_SetTransferConfig(DMA0, channel, &config, &stcd);
 * @endcode
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param config Pointer to eDMA transfer configuration structure.
 * @param nextTcd Point to TCD structure. It can be NULL if users
 *                do not want to enable scatter/gather feature.
 * @note If nextTcd is not NULL, it means scatter gather feature is enabled
 *       and DREQ bit is cleared in the previous transfer configuration, which
 *       is set in the eDMA_ResetChannel.
 */
void EDMA_SetTransferConfig(DMA_Type *base,
                            uint32_t channel,
                            const edma_transfer_config_t *config,
                            edma_tcd_t *nextTcd);

/*!
 * @brief Configures the eDMA minor offset feature.
 *
 * The minor offset means that the signed-extended value is added to the source address or destination
 * address after each minor loop.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param config A pointer to the minor offset configuration structure.
 */
void EDMA_SetMinorOffsetConfig(DMA_Type *base, uint32_t channel, const edma_minor_offset_config_t *config);

/*!
 * @brief Configures the eDMA channel arbitration group.
 *
 * This function configures the channel arbitration group.
 * The arbitration group priorities are evaluated by numeric value from highest group number to lowest.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number
 * @param group Fixed-priority arbitration group number for the channel.
 */
static inline void EDMA_SetChannelArbitrationGroup(DMA_Type *base, uint32_t channel, uint32_t group)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(group < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH_GRPRI[channel] = DMA_CH_GRPRI_GRPRI(group);
}

/*!
 * @brief Configures the eDMA channel preemption feature.
 *
 * This function configures the channel preemption attribute and the priority of the channel.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number
 * @param config A pointer to the channel preemption configuration structure.
 */
static inline void EDMA_SetChannelPreemptionConfig(DMA_Type *base,
                                                   uint32_t channel,
                                                   const edma_channel_Preemption_config_t *config)
{
    assert(channel < (uint16_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);
    assert(config != NULL);

    base->CH[channel].CH_PRI = DMA_CH_PRI_ECP(config->enableChannelPreemption) |
                               DMA_CH_PRI_DPA(!config->enablePreemptAbility) | DMA_CH_PRI_APL(config->channelPriority);
}

/*!
 * @brief Gets the eDMA channel identification and attribute information on the system bus interface.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @return The mask of the channel system bus information. Users need to use the
 *         _edma_channel_sys_bus_info type to decode the return variables.
 */
static inline uint32_t EDMA_GetChannelSystemBusInformation(DMA_Type *base, uint32_t channel)
{
    return base->CH[channel].CH_SBR;
}

/*!
 * @brief Sets the channel link for the eDMA transfer.
 *
 * This function configures either the minor link or the major link mode. The minor link means that the channel link is
 * triggered every time CITER decreases by 1. The major link means that the channel link is triggered when the CITER is
 * exhausted.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param type A channel link type, which can be one of the following:
 *   @arg kEDMA_LinkNone
 *   @arg kEDMA_MinorLink
 *   @arg kEDMA_MajorLink
 * @param linkedChannel The linked channel number.
 * @note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 */
void EDMA_SetChannelLink(DMA_Type *base, uint32_t channel, edma_channel_link_type_t type, uint32_t linkedChannel);

/*!
 * @brief Sets the bandwidth for the eDMA transfer.
 *
 * Because the eDMA processes the minor loop, it continuously generates read/write sequences
 * until the minor count is exhausted. The bandwidth forces the eDMA to stall after the completion of
 * each read/write access to control the bus request bandwidth seen by the crossbar switch.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param bandWidth A bandwidth setting, which can be one of the following:
 *     @arg kEDMABandwidthStallNone
 *     @arg kEDMABandwidthStall4Cycle
 *     @arg kEDMABandwidthStall8Cycle
 */
void EDMA_SetBandWidth(DMA_Type *base, uint32_t channel, edma_bandwidth_t bandWidth);

/*!
 * @brief Sets the source modulo and the destination modulo for the eDMA transfer.
 *
 * This function defines a specific address range specified to be the value after (SADDR + SOFF)/(DADDR + DOFF)
 * calculation is performed or the original register value. It provides the ability to implement a circular data
 * queue easily.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param srcModulo A source modulo value.
 * @param destModulo A destination modulo value.
 */
void EDMA_SetModulo(DMA_Type *base, uint32_t channel, edma_modulo_t srcModulo, edma_modulo_t destModulo);

/*!
 * @brief Enables an async request for the eDMA transfer.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param enable The command to enable (true) or disable (false).
 */
static inline void EDMA_EnableAsyncRequest(DMA_Type *base, uint32_t channel, bool enable)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[channel].CH_CSR =
        (base->CH[channel].CH_CSR & (~(DMA_CH_CSR_EARQ_MASK | DMA_CH_CSR_DONE_MASK))) | DMA_CH_CSR_EARQ(enable);
}

/*!
 * @brief Enables an auto stop request for the eDMA transfer.
 *
 * If enabling the auto stop request, the eDMA hardware automatically disables the hardware channel request.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param enable The command to enable (true) or disable (false).
 */
static inline void EDMA_EnableAutoStopRequest(DMA_Type *base, uint32_t channel, bool enable)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[channel].TCD_CSR =
        (base->CH[channel].TCD_CSR & (~(uint16_t)DMA_TCD_CSR_DREQ_MASK)) | DMA_TCD_CSR_DREQ(enable);
}

/*!
 * @brief Enables the interrupt source for the eDMA transfer.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param mask The mask of interrupt source to be set. Users need to use
 *             the defined edma_interrupt_enable_t type.
 */
void EDMA_EnableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask);

/*!
 * @brief Disables the interrupt source for the eDMA transfer.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param mask The mask of the interrupt source to be set. Use
 *             the defined edma_interrupt_enable_t type.
 */
void EDMA_DisableChannelInterrupts(DMA_Type *base, uint32_t channel, uint32_t mask);

#if defined(FSL_FEATURE_EDMA_HAS_CHANNEL_MUX) && FSL_FEATURE_EDMA_HAS_CHANNEL_MUX
/*!
 * @brief Set channel mux source.
 *
 * Note:When the peripheral is no longer needed, the mux configuration for that channel should be written to 0, thus
 * releasing the resource.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param mux the mux source value is SOC specific, please reference the SOC for detail.
 */
static inline void EDMA_SetChannelMux(DMA_Type *base, uint32_t channel, uint32_t mux)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    if ((base->CH[channel].CH_MUX & DMA_CH_MUX_SRC_MASK) != DMA_CH_MUX_SRC(mux))
    {
        base->CH[channel].CH_MUX = DMA_CH_MUX_SRC(mux);
    }
}
#endif

/*! @} */
/*!
 * @name eDMA TCD Operation
 * @{
 */

/*!
 * @brief Sets all fields to default values for the TCD structure.
 *
 * This function sets all fields for this TCD structure to default value.
 *
 * @param tcd Pointer to the TCD structure.
 * @note This function enables the auto stop request feature.
 */
void EDMA_TcdReset(edma_tcd_t *tcd);

/*!
 * @brief Configures the eDMA TCD transfer attribute.
 *
 * The TCD is a transfer control descriptor. The content of the TCD is the same as the hardware TCD registers.
 * The STCD is used in the scatter-gather mode.
 * This function configures the TCD transfer attribute, including source address, destination address,
 * transfer size, address offset, and so on. It also configures the scatter gather feature if the
 * user supplies the next TCD address.
 * Example:
 * @code
 *   edma_transfer_config_t config = {
 *   ...
 *   }
 *   edma_tcd_t tcd __aligned(32);
 *   edma_tcd_t nextTcd __aligned(32);
 *   EDMA_TcdSetTransferConfig(&tcd, &config, &nextTcd);
 * @endcode
 *
 * @param tcd Pointer to the TCD structure.
 * @param config Pointer to eDMA transfer configuration structure.
 * @param nextTcd Pointer to the next TCD structure. It can be NULL if users
 *                do not want to enable scatter/gather feature.
 * @note TCD address should be 32 bytes aligned or it causes an eDMA error.
 * @note If the nextTcd is not NULL, the scatter gather feature is enabled
 *       and DREQ bit is cleared in the previous transfer configuration, which
 *       is set in the EDMA_TcdReset.
 */
void EDMA_TcdSetTransferConfig(edma_tcd_t *tcd, const edma_transfer_config_t *config, edma_tcd_t *nextTcd);

/*!
 * @brief Configures the eDMA TCD minor offset feature.
 *
 * A minor offset is a signed-extended value added to the source address or a destination
 * address after each minor loop.
 *
 * @param tcd A point to the TCD structure.
 * @param config A pointer to the minor offset configuration structure.
 */
void EDMA_TcdSetMinorOffsetConfig(edma_tcd_t *tcd, const edma_minor_offset_config_t *config);

/*!
 * @brief Sets the channel link for the eDMA TCD.
 *
 * This function configures either a minor link or a major link. The minor link means the channel link is
 * triggered every time CITER decreases by 1. The major link means that the channel link  is triggered when the CITER is
 * exhausted.
 *
 * @note Users should ensure that DONE flag is cleared before calling this interface, or the configuration is invalid.
 * @param tcd Point to the TCD structure.
 * @param type Channel link type, it can be one of:
 *   @arg kEDMA_LinkNone
 *   @arg kEDMA_MinorLink
 *   @arg kEDMA_MajorLink
 * @param linkedChannel The linked channel number.
 */
void EDMA_TcdSetChannelLink(edma_tcd_t *tcd, edma_channel_link_type_t type, uint32_t linkedChannel);

/*!
 * @brief Sets the bandwidth for the eDMA TCD.
 *
 * Because the eDMA processes the minor loop, it continuously generates read/write sequences
 * until the minor count is exhausted. The bandwidth forces the eDMA to stall after the completion of
 * each read/write access to control the bus request bandwidth seen by the crossbar switch.
 * @param tcd A pointer to the TCD structure.
 * @param bandWidth A bandwidth setting, which can be one of the following:
 *     @arg kEDMABandwidthStallNone
 *     @arg kEDMABandwidthStall4Cycle
 *     @arg kEDMABandwidthStall8Cycle
 */
static inline void EDMA_TcdSetBandWidth(edma_tcd_t *tcd, edma_bandwidth_t bandWidth)
{
    assert(tcd != NULL);
    assert(((uint32_t)tcd & 0x1FU) == 0U);

    tcd->CSR = (tcd->CSR & (~(uint16_t)DMA_TCD_CSR_BWC_MASK)) | DMA_TCD_CSR_BWC(bandWidth);
}

/*!
 * @brief Sets the source modulo and the destination modulo for the eDMA TCD.
 *
 * This function defines a specific address range specified to be the value after (SADDR + SOFF)/(DADDR + DOFF)
 * calculation is performed or the original register value. It provides the ability to implement a circular data
 * queue easily.
 *
 * @param tcd A pointer to the TCD structure.
 * @param srcModulo A source modulo value.
 * @param destModulo A destination modulo value.
 */
void EDMA_TcdSetModulo(edma_tcd_t *tcd, edma_modulo_t srcModulo, edma_modulo_t destModulo);

/*!
 * @brief Sets the auto stop request for the eDMA TCD.
 *
 * If enabling the auto stop request, the eDMA hardware automatically disables the hardware channel request.
 *
 * @param tcd A pointer to the TCD structure.
 * @param enable The command to enable (true) or disable (false).
 */
static inline void EDMA_TcdEnableAutoStopRequest(edma_tcd_t *tcd, bool enable)
{
    assert(tcd != NULL);
    assert(((uint32_t)tcd & 0x1FU) == 0U);

    tcd->CSR = (tcd->CSR & (~(uint16_t)DMA_TCD_CSR_DREQ_MASK)) | DMA_TCD_CSR_DREQ(enable);
}

/*!
 * @brief Enables the interrupt source for the eDMA TCD.
 *
 * @param tcd Point to the TCD structure.
 * @param mask The mask of interrupt source to be set. Users need to use
 *             the defined edma_interrupt_enable_t type.
 */
void EDMA_TcdEnableInterrupts(edma_tcd_t *tcd, uint32_t mask);

/*!
 * @brief Disables the interrupt source for the eDMA TCD.
 *
 * @param tcd Point to the TCD structure.
 * @param mask The mask of interrupt source to be set. Users need to use
 *             the defined edma_interrupt_enable_t type.
 */
void EDMA_TcdDisableInterrupts(edma_tcd_t *tcd, uint32_t mask);

/*! @} */
/*!
 * @name eDMA Channel Transfer Operation
 * @{
 */

/*!
 * @brief Enables the eDMA hardware channel request.
 *
 * This function enables the hardware channel request.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 */
static inline void EDMA_EnableChannelRequest(DMA_Type *base, uint32_t channel)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[channel].CH_CSR |= DMA_CH_CSR_ERQ_MASK;
}

/*!
 * @brief Disables the eDMA hardware channel request.
 *
 * This function disables the hardware channel request.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 */
static inline void EDMA_DisableChannelRequest(DMA_Type *base, uint32_t channel)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[channel].CH_CSR &= ~DMA_CH_CSR_ERQ_MASK;
}

/*!
 * @brief Starts the eDMA transfer by using the software trigger.
 *
 * This function starts a minor loop transfer.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 */
static inline void EDMA_TriggerChannelStart(DMA_Type *base, uint32_t channel)
{
    assert(channel < (uint32_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    base->CH[channel].TCD_CSR |= DMA_TCD_CSR_START_MASK;
}

/*! @} */
/*!
 * @name eDMA Channel Status Operation
 * @{
 */

/*!
 * @brief Gets the Remaining major loop count from the eDMA current channel TCD.
 *
 * This function checks the TCD (Task Control Descriptor) status for a specified
 * eDMA channel and returns the number of major loop count that has not finished.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @return Major loop count which has not been transferred yet for the current TCD.
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
uint32_t EDMA_GetRemainingMajorLoopCount(DMA_Type *base, uint32_t channel);

/*!
 * @brief Gets the eDMA channel error status flags.
 *
 * @param base eDMA peripheral base address.
 * @return The mask of error status flags. Users need to use the
 *         _edma_error_status_flags type to decode the return variables.
 */
static inline uint32_t EDMA_GetErrorStatusFlags(DMA_Type *base)
{
    return base->MP_ES;
}

/*!
 * @brief Gets the eDMA channel status flags.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @return The mask of channel status flags. Users need to use the
 *         _edma_channel_status_flags type to decode the return variables.
 */
uint32_t EDMA_GetChannelStatusFlags(DMA_Type *base, uint32_t channel);

/*!
 * @brief Clears the eDMA channel status flags.
 *
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 * @param mask The mask of channel status to be cleared. Users need to use
 *             the defined _edma_channel_status_flags type.
 */
void EDMA_ClearChannelStatusFlags(DMA_Type *base, uint32_t channel, uint32_t mask);

/*! @} */
/*!
 * @name eDMA Transactional Operation
 */

/*!
 * @brief Creates the eDMA handle.
 *
 * This function is called if using the transactional API for eDMA. This function
 * initializes the internal state of the eDMA handle.
 *
 * @param handle eDMA handle pointer. The eDMA handle stores callback function and
 *               parameters.
 * @param base eDMA peripheral base address.
 * @param channel eDMA channel number.
 */
void EDMA_CreateHandle(edma_handle_t *handle, DMA_Type *base, uint32_t channel);

/*!
 * @brief Installs the TCDs memory pool into the eDMA handle.
 *
 * This function is called after the EDMA_CreateHandle to use scatter/gather feature.
 *
 * @param handle eDMA handle pointer.
 * @param tcdPool A memory pool to store TCDs. It must be 32 bytes aligned.
 * @param tcdSize The number of TCD slots.
 */
void EDMA_InstallTCDMemory(edma_handle_t *handle, edma_tcd_t *tcdPool, uint32_t tcdSize);

/*!
 * @brief Installs a callback function for the eDMA transfer.
 *
 * This callback is called in the eDMA IRQ handler. Use the callback to do something after
 * the current major loop transfer completes.
 *
 * @param handle eDMA handle pointer.
 * @param callback eDMA callback function pointer.
 * @param userData A parameter for the callback function.
 */
void EDMA_SetCallback(edma_handle_t *handle, edma_callback callback, void *userData);

/*!
 * @brief Prepares the eDMA transfer structure configurations.
 *
 * This function prepares the transfer configuration structure according to the
 * user input.
 *
 * @param config The user configuration structure of type edma_transfer_config_t.
 * @param srcAddr eDMA transfer source address.
 * @param srcWidth eDMA transfer source address width(bytes).
 * @param srcOffset eDMA transfer source address offset
 * @param destAddr eDMA transfer destination address.
 * @param destWidth eDMA transfer destination address width(bytes).
 * @param destOffset eDMA transfer destination address offset
 * @param bytesEachRequest eDMA transfer bytes per channel request.
 * @param transferBytes eDMA transfer bytes to be transferred.
 *
 * @note The data address and the data width must be consistent. For example, if
 * the SRC is 4 bytes, the source address must be 4 bytes aligned, or it results
 * in source address error (SAE).
 */
void EDMA_PrepareTransferConfig(edma_transfer_config_t *config,
                                void *srcAddr,
                                uint32_t srcWidth,
                                int16_t srcOffset,
                                void *destAddr,
                                uint32_t destWidth,
                                int16_t destOffset,
                                uint32_t bytesEachRequest,
                                uint32_t transferBytes);

/*!
 * @brief Prepares the eDMA transfer structure.
 *
 * This function prepares the transfer configuration structure according to the user input.
 *
 * @param config The user configuration structure of type edma_transfer_config_t.
 * @param srcAddr eDMA transfer source address.
 * @param srcWidth eDMA transfer source address width(bytes).
 * @param destAddr eDMA transfer destination address.
 * @param destWidth eDMA transfer destination address width(bytes).
 * @param bytesEachRequest eDMA transfer bytes per channel request.
 * @param transferBytes eDMA transfer bytes to be transferred.
 * @param transferType eDMA transfer type.
 * @note The data address and the data width must be consistent. For example, if the SRC
 *       is 4 bytes, the source address must be 4 bytes aligned, or it results in
 *       source address error (SAE).
 */
void EDMA_PrepareTransfer(edma_transfer_config_t *config,
                          void *srcAddr,
                          uint32_t srcWidth,
                          void *destAddr,
                          uint32_t destWidth,
                          uint32_t bytesEachRequest,
                          uint32_t transferBytes,
                          edma_transfer_type_t transferType);

/*!
 * @brief Submits the eDMA transfer request.
 *
 * This function submits the eDMA transfer request according to the transfer configuration structure.
 * If submitting the transfer request repeatedly, this function packs an unprocessed request as
 * a TCD and enables scatter/gather feature to process it in the next time.
 *
 * @param handle eDMA handle pointer.
 * @param config Pointer to eDMA transfer configuration structure.
 * @retval kStatus_EDMA_Success It means submit transfer request succeed.
 * @retval kStatus_EDMA_QueueFull It means TCD queue is full. Submit transfer request is not allowed.
 * @retval kStatus_EDMA_Busy It means the given channel is busy, need to submit request later.
 */
status_t EDMA_SubmitTransfer(edma_handle_t *handle, const edma_transfer_config_t *config);

/*!
 * @brief eDMA starts transfer.
 *
 * This function enables the channel request. Users can call this function after submitting the transfer request
 * or before submitting the transfer request.
 *
 * @param handle eDMA handle pointer.
 */
void EDMA_StartTransfer(edma_handle_t *handle);

/*!
 * @brief eDMA stops transfer.
 *
 * This function disables the channel request to pause the transfer. Users can call EDMA_StartTransfer()
 * again to resume the transfer.
 *
 * @param handle eDMA handle pointer.
 */
void EDMA_StopTransfer(edma_handle_t *handle);

/*!
 * @brief eDMA aborts transfer.
 *
 * This function disables the channel request and clear transfer status bits.
 * Users can submit another transfer after calling this API.
 *
 * @param handle DMA handle pointer.
 */
void EDMA_AbortTransfer(edma_handle_t *handle);

/*!
 * @brief Get unused TCD slot number.
 *
 * This function gets current tcd index which is run. If the TCD pool pointer is NULL, it will return 0.
 *
 * @param handle DMA handle pointer.
 * @return The unused tcd slot number.
 */
static inline uint32_t EDMA_GetUnusedTCDNumber(edma_handle_t *handle)
{
    int8_t tmpTcdSize = handle->tcdSize;
    int8_t tmpTcdUsed = handle->tcdUsed;
    return ((uint32_t)tmpTcdSize - (uint32_t)tmpTcdUsed);
}

/*!
 * @brief Get the next tcd address.
 *
 * This function gets the next tcd address. If this is last TCD, return 0.
 *
 * @param handle DMA handle pointer.
 * @return The next TCD address.
 */
static inline uint32_t EDMA_GetNextTCDAddress(edma_handle_t *handle)
{
    return (handle->base->CH[handle->channel].TCD_DLAST_SGA);
}

/*!
 * @brief eDMA IRQ handler for the current major loop transfer completion.
 *
 * This function clears the channel major interrupt flag and calls
 * the callback function if it is not NULL.
 *
 * @param handle eDMA handle pointer.
 */
void EDMA_HandleIRQ(edma_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_EDMA_H_*/
