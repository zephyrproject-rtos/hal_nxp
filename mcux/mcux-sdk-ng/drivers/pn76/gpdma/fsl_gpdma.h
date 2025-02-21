/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_GPDMA_H_
#define FSL_GPDMA_H_

#include "fsl_common.h"
/*!
 * @addtogroup gpdma
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief GPDMA driver version */
#define FSL_GPDMA_DRIVER_VERSION (MAKE_VERSION(2, 0, 1)) /*!< Version 2.0.1. */
/*! @} */

/**
 * @brief GPDMA Interrupt Clear Status
 */
typedef enum _gpdma_status_clear
{
    kGPDMA_StatusClearInterruptTerminalCountRequest = 0x0, /*!< GPDMA Interrupt Terminal Count Request Clear */
    kGPDMA_StatusClearInterruptError,                      /*!< GPDMA Interrupt Error Clear */
} gpdma_status_clear_t;

/**
 * @brief GPDMA Type of Status
 */
typedef enum _gpdma_status
{
    kGPDMA_StatusInterrupt = 0x0,               /*!< GPDMA Interrupt Status */
    kGPDMA_StatusInterruptTerminalCountRequest, /*!< GPDMA Interrupt Terminal Count Request Status */
    kGPDMA_StatusInterruptError,                /*!< GPDMA Interrupt Error Status */
    kGPDMA_StatusRawInterruptTerminalCount,     /*!< GPDMA Raw Interrupt Terminal Count Status */
    kGPDMA_StatusRawErrorInterrupt,             /*!< GPDMA Raw Error Interrupt Status */
    kGPDMA_StatusEnabledChannel,                /*!< GPDMA Enabled Channel Status */
} gpdma_status_t;

/*! @brief GPDMA transfer type */
typedef enum _gpdma_transfer_type
{
    kGPDMA_TransferM2MControllerDma            = 0UL, /*!< Memory to memory, GPDMA control */
    kGPDMA_TransferM2PControllerDma            = 1UL, /*!< Memory to peripheral, GPDMA control */
    kGPDMA_TransferP2MControllerDma            = 2UL, /*!< Peripheral to memory, GPDMA control */
    kGPDMA_TransferP2PControllerDma            = 3UL, /*!< Source peripheral to destination peripheral, GPDMA control */
    kGPDMA_TransferP2PControllerDestPeripheral = 4UL, /*!< Source peripheral to destination peripheral,
                                                        destination peripheral control */
    kGPDMA_TransferM2PControllerPeripheral    = 5UL,  /*!< Memory to peripheral, peripheral control */
    kGPDMA_TransferP2MControllerPeripheral    = 6UL,  /*!< Peripheral to memory, peripheral control */
    kGPDMA_TransferP2PControllerSrcPeripheral = 7UL,  /*!< Source peripheral to destination peripheral,
                                                        source peripheral control */
} gpdma_transfer_type_t;

/*! @brief GPDMA transfer width configuration */
typedef enum _gpdma_transfer_width
{
    kGPDMA_TransferWidth1Bytes = 0U, /*!< Source/Destination data transfer width is 1 byte every time */
    kGPDMA_TransferWidth2Bytes = 1U, /*!< Source/Destination data transfer width is 2 bytes every time */
    kGPDMA_TransferWidth4Bytes = 2U, /*!< Source/Destination data transfer width is 4 bytes every time */
} gpdma_transfer_width_t;

/*! @brief GPDMA transfer configuration */
typedef enum _gpdma_burst_size
{
    kGPDMA_BurstSize1   = 0U, /*!< Source/Destination data burst size is 1 every time */
    kGPDMA_BurstSize4   = 1U, /*!< Source/Destination data burst size is 4 every time */
    kGPDMA_BurstSize8   = 2U, /*!< Source/Destination data burst size is 8 every time */
    kGPDMA_BurstSize16  = 3U, /*!< Source/Destination data burst size is 16 every time */
    kGPDMA_BurstSize32  = 4U, /*!< Source/Destination data burst size is 32 every time */
    kGPDMA_BurstSize64  = 5U, /*!< Source/Destination data burst size is 64 every time */
    kGPDMA_BurstSize128 = 6U, /*!< Source/Destination data burst size is 128 every time */
    kGPDMA_BurstSize256 = 7U, /*!< Source/Destination data burst size is 256 every time */
} gpdma_burst_size_t;

/**
 * @brief GPDMA structure using for GPDMA configuration
 */
typedef struct _gpdma_transfer_config
{
    uint32_t srcAddr;  /*!< Source data address. */
    uint32_t destAddr; /*!< Destination data address. */

    gpdma_burst_size_t srcBurstSize;  /*!< Source data transfer size. */
    gpdma_burst_size_t destBurstSize; /*!< Destination data transfer size. */

    gpdma_transfer_width_t srcTransferWidth;  /*!< Source data transfer width */
    gpdma_transfer_width_t destTransferWidth; /*!< Destination transfer width */

    gpdma_transfer_type_t transferType; /*!< Transfer Type */

    uint32_t totalBytes; /*!< Length/Size of transfer */

    uint32_t linkListItem; /*!< Next descriptor address, use 0 means disable. */
} gpdma_transfer_config_t;

/**
 * @brief Transfer Descriptor structure typedef
 */
typedef struct _gpdma_descriptor
{
    uint32_t srcAddr;  /*!< Source address */
    uint32_t destAddr; /*!< Destination address */
    uint32_t lli;      /*!< Link to next descriptor. */
    uint32_t control;  /*!< Control word that has transfer size, trasnfer type etc. */
} gpdma_descriptor_t;

/*! @brief Callback for GPDMA */
struct _gpdma_handle;

/*! @brief Define callback function for GPDMA.
 *
 * This callback function is called in the GPDMA interrupt handle.
 * Run into callback function means the transfer users need is done.
 *
 * @param handle GPDMA handle pointer, users shall not touch the values inside.
 * @param userData The callback user parameter pointer. Users can use this parameter to involve things users need to
 *                 change in GPDMA callback function.
 * @param status GPDMA trasnfer status
 */
typedef void (*gpdma_callback)(struct _gpdma_handle *handle, void *userData, uint32_t status);

/*! @brief GPDMA transfer handle structure */
typedef struct _gpdma_handle
{
    gpdma_callback callback; /*!< Callback function */
    void *userData;          /*!< Callback function parameter. */
    uint8_t channel;         /*!< GPDMA channel number. */
    GPDMA_Type *base;        /*!< GPDMA peripheral base address. */
} gpdma_handle_t;
/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name GPDMA initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the GPDMA peripheral.
 *
 * @param base GPDMA peripheral base address.
 * @retval kStatus_Success Initialiation succeed.
 * @retval kStatus_Timeout Timeout during initialization.
 */
status_t GPDMA_Init(GPDMA_Type *base);

/*!
 * @brief Deinitializes the GPDMA peripheral.
 *
 * @param base GPDMA peripheral base address.
 */
void GPDMA_Deinit(GPDMA_Type *base);

/*! @} */

/*!
 * @name GPDMA Channel Transfer Operation
 * @{
 */

/*!
 * @brief Enables the interrupt source for the GPDMA transfer.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 */
static inline void GPDMA_EnableChannelInterrupts(GPDMA_Type *base, uint8_t channel)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    base->DMACC[channel].CONFIGURATION |= GPDMA_CONFIGURATION_IE_MASK;
}

/*!
 * @brief Disables the interrupt source for the GPDMA transfer.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 */
static inline void GPDMA_DisableChannelInterrupts(GPDMA_Type *base, uint8_t channel)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    base->DMACC[channel].CONFIGURATION &= ~GPDMA_CONFIGURATION_IE_MASK;
}

/*!
 * @brief Set the GPDMA request source peripheral.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @param srcPeripheral GPDMA hardware service request source for the channel.
 */
static inline void GPDMA_SetChannelSourcePeripheral(GPDMA_Type *base,
                                                    uint8_t channel,
                                                    gpdma_request_source_t srcPeripheral)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    if (srcPeripheral != kGpdmaRequestDisabled)
    {
        base->DMACC[channel].CONFIGURATION =
            (base->DMACC[channel].CONFIGURATION & (~GPDMA_CONFIGURATION_SRCPERIPHERAL_MASK)) |
            GPDMA_CONFIGURATION_SRCPERIPHERAL((uint32_t)srcPeripheral - 1U);
    }
    else
    {
        base->DMACC[channel].CONFIGURATION =
            (base->DMACC[channel].CONFIGURATION & (~GPDMA_CONFIGURATION_SRCPERIPHERAL_MASK)) |
            GPDMA_CONFIGURATION_SRCPERIPHERAL(0);
    }
}

/*!
 * @brief Set the GPDMA request destination peripheral.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @param destPeripheral GPDMA hardware service request source for the channel.
 */
static inline void GPDMA_SetChannelDestinationPeripheral(GPDMA_Type *base,
                                                         uint8_t channel,
                                                         gpdma_request_source_t destPeripheral)
{
    assert(channel < (uint8_t)FSL_FEATURE_GPDMA_MODULE_MAX_CHANNEL);

    if (destPeripheral != kGpdmaRequestDisabled)
    {
        base->DMACC[channel].CONFIGURATION =
            (base->DMACC[channel].CONFIGURATION & (~GPDMA_CONFIGURATION_DESTPERIPHERAL_MASK)) |
            GPDMA_CONFIGURATION_DESTPERIPHERAL((uint32_t)destPeripheral - 1U);
    }
    else
    {
        base->DMACC[channel].CONFIGURATION =
            (base->DMACC[channel].CONFIGURATION & (~GPDMA_CONFIGURATION_DESTPERIPHERAL_MASK)) |
            GPDMA_CONFIGURATION_DESTPERIPHERAL(0);
    }
}

/**
 * @brief Enable or Disable the GPDMA Channel.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @param enable true to enable GPDMA or false to disable GPDMA channel.
 */
void GPDMA_EnableChannel(GPDMA_Type *base, uint8_t channel, bool enable);

/**
 * @brief Stop a stream GPDMA transfer.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 */
void GPDMA_StopChannel(GPDMA_Type *base, uint8_t channel);

/**
 * @brief The GPDMA stream interrupt status checking.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @return status: kStatus_Success It means succeed.
 *                 kStatus_Fail It means failed.
 */
status_t GPDMA_CheckChannelInterrupts(GPDMA_Type *base, uint8_t channel);

/**
 * @brief Read the status from different registers according to the flag.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @param flag The GPDMA interrupt flag.
 * @return status: true It means flag is set.
 *                 false It means flag is not set.
 */
bool GPDMA_GetChannelStatus(GPDMA_Type *base, uint8_t channel, gpdma_status_t flag);

/**
 * @brief Clear the Interrupt status from different registers according to the flag.
 *
 * @param base Base address of GPDMA module.
 * @param channel The GPDMA channel (0 to 7).
 * @param flag The GPDMA interrupt flag.
 */
void GPDMA_ClearChannelStatus(GPDMA_Type *base, uint8_t channel, gpdma_status_clear_t flag);

/*!
 * @brief Prepares the GPDMA transfer descriptor.
 *
 * @param descriptor The transfer descriptor.
 * @param srcAddr GPDMA transfer source address.
 * @param srcBurstSize source address offset.
 * @param srcTransferWidth Source data trasnfer size every time.
 * @param destAddr GPDMA transfer destination address.
 * @param destBurstSize destination address offset.
 * @param destTransferWidth Destination data trasnfer size every time.
 * @param totalBytes GPDMA transfer bytes to be transferred.
 * @param transferType GPDMA transfer type.
 * @param linkListItem Pointer to next transfer descriptor.
 * @retval kStatus_Success \ref status_t Prepared successfully.
 * @retval kStatus_InvalidArgument \ref status_t Failed because invalid argument.
 */
status_t GPDMA_PrepareDescriptor(gpdma_descriptor_t *descriptor,
                                 void *srcAddr,
                                 gpdma_burst_size_t srcBurstSize,
                                 gpdma_transfer_width_t srcTransferWidth,
                                 void *destAddr,
                                 gpdma_burst_size_t destBurstSize,
                                 gpdma_transfer_width_t destTransferWidth,
                                 uint32_t totalBytes,
                                 gpdma_transfer_type_t transferType,
                                 uint32_t linkListItem);

/*!
 * @brief Prepares the GPDMA transfer structure configurations.
 *
 * @param config The user configuration structure of type.
 * @param srcAddr GPDMA transfer source address.
 * @param srcBurstSize source address offset.
 * @param srcTransferWidth Source data trasnfer size every time.
 * @param destAddr GPDMA transfer destination address.
 * @param destBurstSize destination address offset.
 * @param destTransferWidth Destination data trasnfer size every time.
 * @param totalBytes GPDMA transfer bytes to be transferred.
 * @param transferType GPDMA transfer type.
 * @param linkListItem Pointer to next transfer descriptor.
 */
void GPDMA_PrepareTransferConfig(gpdma_transfer_config_t *config,
                                 void *srcAddr,
                                 gpdma_burst_size_t srcBurstSize,
                                 gpdma_transfer_width_t srcTransferWidth,
                                 void *destAddr,
                                 gpdma_burst_size_t destBurstSize,
                                 gpdma_transfer_width_t destTransferWidth,
                                 uint32_t totalBytes,
                                 gpdma_transfer_type_t transferType,
                                 uint32_t linkListItem);

/*!
 * @brief Configures the GPDMA transfer attribute.
 *
 * @param base GPDMA peripheral base address.
 * @param channel The GPDMA channel (0 to 7).
 * @param config Pointer to GPDMA transfer configuration structure.
 *
 * @retval kStatus_Busy The channel is busy.
 * @retval kStatus_Success Set succeed.
 */
status_t GPDMA_SetTransferConfig(GPDMA_Type *base, uint8_t channel, const gpdma_transfer_config_t *config);

/**
 * @brief Get a free GPDMA channel.
 *
 * @param base Base address of GPDMA module.
 * @return The channel number which is selected in case of success (0 to 7).
 * @return Maximum channel number (8) in case channel is not available.
 */
uint8_t GPDMA_GetFreeChannel(GPDMA_Type *base);

/*! @} */

/*!
 * @name GPDMA Transactional Operation
 * @{
 */

/*!
 * @brief Creates the GPDMA handle.
 *
 * @param handle GPDMA handle pointer. The GPDMA handle stores callback function and
 *               parameters.
 * @param base GPDMA peripheral base address.
 * @param channel The GPDMA channel (0 to 7).
 */
void GPDMA_CreateHandle(gpdma_handle_t *handle, GPDMA_Type *base, uint8_t channel);

/*!
 * @brief Installs a callback function for the GPDMA transfer.
 *
 * @param handle GPDMA handle pointer.
 * @param callback GPDMA callback function pointer.
 * @param userData A parameter for the callback function.
 */
void GPDMA_SetCallback(gpdma_handle_t *handle, gpdma_callback callback, void *userData);

/*!
 * @brief Submits the GPDMA transfer request.
 *
 * @param handle GPDMA handle pointer.
 * @param config Pointer to GPDMA transfer configuration structure.
 *
 * @retval kStatus_Busy The channel is busy.
 * @retval kStatus_Success Set succeed.
 */
status_t GPDMA_SubmitTransfer(gpdma_handle_t *handle, const gpdma_transfer_config_t *config);

/*!
 * @brief Abort running transfer by handle.
 *
 * This function aborts GPDMA transfer specified by handle.
 *
 * @brief handle GPDMA handle pointer.
 */
void GPDMA_AbortTransfer(gpdma_handle_t *handle);

/*!
 * @brief GPDMA start transfer.
 *
 * User can call this function after GPDMA_SubmitTransfer.
 *
 * @param handle GPDMA handle pointer.
 */
void GPDMA_StartTransfer(gpdma_handle_t *handle);

/*!
 * @brief GPDMA IRQ Handler.
 *
 * @param base Base address of GPDMA module.
 */
void GPDMA_HandleIRQ(GPDMA_Type *base);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* __GPDMA_H_ */
