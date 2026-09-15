/*
 * Copyright 2026 NXP
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
#define FSL_EDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*******************************************************************************
 * EDMA peripheral driver Change log
 ******************************************************************************/
/*!
 * @defgroup edma_driver_log The Driver Change Log
 * @ingroup edma
 * @{
 * The current eDMA driver version is 2.0.0.
 *
 * - 2.0.0
 *   - Initial version for eDMA3 (spp_dma3) IP on Nevis4 DSC devices.
 *     Maintains the same API as the dsc_edma driver but targets the new
 *     per-channel register architecture.
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
 * The enhanced direct memory access (eDMA3) controller is a third-generation DMA module
 * capable of performing complex data transfers with minimal intervention from a host processor.
 *
 *  + 8 independent DMA channels with per-channel control registers
 *    - Each channel has its own Control/Status (CH_CSR), Error Status (CH_ES),
 *      Interrupt Status (CH_INT), Priority (CH_PRI),
 *      Multiplexor (CH_MUX), and Transfer Control Descriptor (TCD) registers.
 *    - Integrated DMAMUX via per-channel CH_MUX register (7-bit SRC field).
 *
 *  + Channel arbitration: Fixed-priority and round-robin
 *    - Two-tier priority: Group priority (CH_GRPRI, 5-bit) + Channel priority (CH_PRI APL, 3-bit)
 *
 *  + Transfer control descriptor (TCD)
 *    - TCD registers are embedded within each channel's register block.
 *    - Minor loop offset is always available (no EMLM bit needed).
 *    - Global channel linking control via MP_CSR.GCLC.
 *
 *  + Per-channel enable/disable control
 *    - Channel request enable (CH_CSR.ERQ) replaces global ERQ register.
 *    - Error interrupt enable (CH_CSR.EEI) replaces global EEI register.
 *    - Async request enable (CH_CSR.EARQ) replaces global EARS register.
 *
 *  + Management Page registers for global status
 *    - MP_CSR: Global control (ERCA, HAE, EDBG, GCLC)
 *    - MP_ES: Global error status
 *    - MP_INT: Interrupt request status summary
 *    - MP_HRS: Hardware request status summary
 *
 *  How this driver is designed to make this peripheral works.
 *  ===========================================================
 *  The eDMA peripheral is powerful with complex transfer features supported.
 *  To satisfy different user getting different demands for the feature sets/optimization level/flexibility/abstraction
 *  level, 2 parallel layers are provided in this driver (DO NOT MIX THE USAGE OF THESE 2 LAYERS!!!):
 *  - Functional Layer is provided with highly optimized implementation and highly flexible usage of the peripheral
 *    features.
 *  - Transactional layer is provided with average optimization level, average flexibility and not all features are
 *    covered.
 *
 *  @}
 */
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief eDMA channel count */
#ifndef FSL_FEATURE_EDMA_MODULE_CHANNEL
#define FSL_FEATURE_EDMA_MODULE_CHANNEL DMA_CH_COUNT
#endif

/*! @brief eDMA instance count */
#ifndef FSL_FEATURE_SOC_EDMA_COUNT
#define FSL_FEATURE_SOC_EDMA_COUNT 1U
#endif

/*! @brief Number of physical IRQ lines per eDMA instance (shared between channel pairs) */
#define EDMA_IRQ_COUNT_PER_INSTANCE 4U

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
        DMA_TCD_CSR_INTMAJOR_MASK, /*!< Enable interrupt while major count exhausted. */
    kEDMA_ChannelMajorLoopHalfCompleteInterruptEnable =
        DMA_TCD_CSR_INTHALF_MASK, /*!< Enable interrupt while major count to half value. */
    kEDMA_ChannelAllInterruptEnable = kEDMA_ChannelErrorInterruptEnable | DMA_TCD_CSR_INTMAJOR_MASK |
                                      DMA_TCD_CSR_INTHALF_MASK, /*!< Enable all the interrupt. */
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
    kEDMA_ChannelDestinationBusErrorFlag = DMA_MP_ES_DBE_MASK, /*!< Bus error on destination address */
    kEDMA_ChannelSourceBusErrorFlag      = DMA_MP_ES_SBE_MASK, /*!< Bus error on the source address */
    kEDMA_ChannelScatterGatherErrorFlag =
        DMA_MP_ES_SGE_MASK,                            /*!< Error on the Scatter/Gather address, not 32byte aligned. */
    kEDMA_ChannelNbytesErrorFlag = DMA_MP_ES_NCE_MASK, /*!< NBYTES/CITER configuration error */
    kEDMA_ChannelDestinationOffsetErrorFlag =
        DMA_MP_ES_DOE_MASK, /*!< Destination offset not aligned with destination size */
    kEDMA_ChannelDestinationAddressErrorFlag =
        DMA_MP_ES_DAE_MASK,                                   /*!< Destination address not aligned with destination size */
    kEDMA_ChannelSourceOffsetErrorFlag  = DMA_MP_ES_SOE_MASK, /*!< Source offset not aligned with source size */
    kEDMA_ChannelSourceAddressErrorFlag = DMA_MP_ES_SAE_MASK, /*!< Source address not aligned with source size*/
    kEDMA_ChannelErrorChannelFlag       = DMA_MP_ES_ERRCHN_MASK, /*!< Error channel number of the canceled channel number */
    kEDMA_ChannelTransferCanceledFlag   = DMA_MP_ES_ECX_MASK,    /*!< Transfer canceled */
    kEDMA_ChannelValidFlag = DMA_MP_ES_VLD_MASK, /*!< No error occurred, this bit is 0. Otherwise, it is 1. */
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
    kEDMA_Channel4 = 4U, /*!< EDMA channel 4 */
    kEDMA_Channel5 = 5U, /*!< EDMA channel 5 */
    kEDMA_Channel6 = 6U, /*!< EDMA channel 6 */
    kEDMA_Channel7 = 7U, /*!< EDMA channel 7 */
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
    uint8_t u8ChannelPriority : 3;            /*!< Channel arbitration priority level (CH_PRI.APL, 0-7) */
    uint8_t u8GroupPriority;                  /*!< Channel group arbitration priority (CH_GRPRI, 0-31) */
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
 *       2. the i16SrcOffsetOfEachTransfer and i16DstOffsetOfEachTransfer must be aligned with transfer width
 *       3. the u32TotalBytes should align with the u32BytesEachRequest
 *       4. the u32SrcAddr should align with the eSrcWidthOfEachTransfer
 *       5. the u32DstAddr should align with the eDstWidthOfEachTransfer
 *       6. the u32SrcAddr should align with eSrcAddrModulo if modulo feature is enabled
 *       7. the u32DstAddr should align with eDstAddrModulo if modulo feature is enabled
 */
typedef struct _edma_channel_transfer_config
{
    uint32_t u32SrcAddr; /*!< source address */
    uint32_t u32DstAddr; /*!< destination address */

    edma_channel_transfer_width_t eSrcWidthOfEachTransfer; /*!< source width of each transfer */
    edma_channel_transfer_width_t eDstWidthOfEachTransfer; /*!< destination width of each transfer */

    uint32_t u32BytesEachMinorLoop;           /*!< bytes in each minor loop or each request
                                               * range: 1 - (2^30 -1) when source or dest minor loop offset is disabled
                                               * range: 1 - (2^10 - 1) when source or dest minor loop offset is enabled
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
    __IO uint32_t u32SLAST;  /*!< SLAST_SDA register, adjustment value added to the source address at the completion of
                                the major loop */
    __IO uint32_t u32DADDR;  /*!< DADDR register, used for destination address */
    __IO uint16_t u16DOFF;   /*!< DOFF register, offset bytes added to destination address every transfer */
    __IO uint16_t u16CITER;  /*!< CITER register, current minor loop numbers, for unfinished minor loop.*/
    __IO uint32_t u32DLAST_SGA; /*!< DLAST_SGA register, next tcd address used in scatter-gather mode */
    __IO uint16_t u16CSR;       /*!< CSR register, for TCD control status */
    __IO uint16_t u16BITER;     /*!< BITER register, begin minor loop count. */
};

/*! @brief edma configuration structure
 *
 * This structure target for whole edma module configurations.
 */
typedef struct _edma_config
{
    bool bEnableHaltOnError;        /*!< Enable (true) transfer halt on error. Any error causes the HALT bit to set.
                                         Subsequently, all service requests are ignored until the HALT bit is cleared.*/
    bool bEnableDmaInDebugMode;     /*!< Enable(true) eDMA debug mode. When in debug mode, the eDMA stalls the start of
                                         a new channel. Executing channels are allowed to complete. */
    bool bEnableGlobalChannelLink;  /*!< Enable (true) global channel linking control (GCLC). When enabled, channel
                                         linking is available and controlled by each channel's link settings.
                                         When disabled, channel linking is disabled for all channels. */
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
 * @brief Enable/Disable the global channel linking control.
 *
 * When enabled, channel linking is available and controlled by each channel's link settings.
 * When disabled, channel linking is disabled for all channels.
 *
 * @param base EDMA peripheral base address.
 * @param bEnable true to enable global channel linking, false to disable.
 */
static inline void EDMA_EnableGlobalChannelLink(DMA_Type *base, bool bEnable)
{
    if (bEnable)
    {
        base->MP_CSR |= DMA_MP_CSR_GCLC_MASK;
    }
    else
    {
        base->MP_CSR &= ~DMA_MP_CSR_GCLC_MASK;
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
        base->MP_CSR |= DMA_MP_CSR_HAE_MASK;
    }
    else
    {
        base->MP_CSR &= ~DMA_MP_CSR_HAE_MASK;
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
    base->MP_CSR = (base->MP_CSR & (~DMA_MP_CSR_ERCA_MASK)) | DMA_MP_CSR_ERCA(eArbitration);
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
 * @param u8Priority Channel priority (CH_PRI.APL, 0-7).
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
    base->CH[(uint8_t)eChannel].TCD_CITER_ELINKYES &= ~(uint16_t)DMA_TCD_CITER_ELINKYES_LINKCH_MASK;
    base->CH[(uint8_t)eChannel].TCD_BITER_ELINKYES &= ~(uint16_t)DMA_TCD_CITER_ELINKYES_LINKCH_MASK;
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
    base->CH[(uint8_t)eChannel].TCD_CSR &= ~(uint16_t)DMA_TCD_CSR_MAJORLINKCH_MASK;
}

/*!
 * @brief Sets the edma channel stall cycles after each R/W.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param eBandWidth A bandwidth setting, which can be one of the @ref edma_channel_bandwidth_t
 */
void EDMA_SetChannelBandWidth(DMA_Type *base, edma_channel_t eChannel, edma_channel_bandwidth_t eBandWidth);

/*!
 * @brief Sets the source address range and the destination address range for the eDMA transfer.
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
 * In eDMA3, async request is controlled per-channel via CH_CSR.EARQ bit.
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
        base->CH[(uint8_t)eChannel].CH_CSR |= DMA_CH_CSR_EARQ_MASK;
    }
    else
    {
        base->CH[(uint8_t)eChannel].CH_CSR &= ~DMA_CH_CSR_EARQ_MASK;
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

    base->CH[(uint8_t)eChannel].TCD_CSR =
        (uint16_t)((base->CH[(uint8_t)eChannel].TCD_CSR & (~DMA_TCD_CSR_DREQ_MASK)) |
                   DMA_TCD_CSR_DREQ((true == bEnable ? 1U : 0U)));
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
 * This function enables the hardware channel request via per-channel CH_CSR.ERQ bit.
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
        base->CH[(uint8_t)eChannel].CH_CSR |= DMA_CH_CSR_ERQ_MASK;
    }
    else
    {
        base->CH[(uint8_t)eChannel].CH_CSR &= ~DMA_CH_CSR_ERQ_MASK;
    }
}

/*!
 * @brief Sets the channel mux request source.
 *
 * eDMA3 integrates DMAMUX through the per-channel CH_MUX register (7-bit SRC field).
 * When the peripheral is no longer needed, the mux source for that channel should be
 * written to 0 to release the resource.
 *
 * @param base eDMA peripheral base address.
 * @param eChannel eDMA channel number.
 * @param u32RequestSource Mux source value. The value is SOC specific, please reference
 *                         the SOC header for the request source mapping.
 */
static inline void EDMA_SetChannelMux(DMA_Type *base, edma_channel_t eChannel, uint32_t u32RequestSource)
{
    assert(eChannel < (edma_channel_t)FSL_FEATURE_EDMA_MODULE_CHANNEL);

    if ((base->CH[(uint8_t)eChannel].CH_MUX & DMA_CH_MUX_SRC_MASK) != DMA_CH_MUX_SRC(u32RequestSource))
    {
        base->CH[(uint8_t)eChannel].CH_MUX = DMA_CH_MUX_SRC(u32RequestSource);
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

    base->CH[(uint8_t)eChannel].TCD_CSR |= DMA_TCD_CSR_START_MASK;
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
    return base->MP_ES;
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
 * @param psHandle eDMA handle pointer.
 */
void EDMA_TransferHandleIRQ(edma_handle_t *psHandle);

/*!
 * @brief eDMA IRQ handler for a given instance and channel.
 *
 * @param instance eDMA instance number.
 * @param channel eDMA channel number.
 */
void EDMA_DriverIRQHandler(uint32_t instance, uint32_t channel);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_EDMA_H_*/
