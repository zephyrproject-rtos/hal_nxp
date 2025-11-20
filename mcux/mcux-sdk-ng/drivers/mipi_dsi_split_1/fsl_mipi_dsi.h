/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MIPI_DSI_H_
#define FSL_MIPI_DSI_H_

#include "fsl_common.h"
#include "fsl_soc_mipi_dsi.h"

/*!
 * @addtogroup mipi_dsi
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_MIPI_DSI_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/* The max APB transfer size. */
#define FSL_DSI_TX_MAX_PAYLOAD_BYTE (64U * 4U)
#define FSL_DSI_RX_MAX_PAYLOAD_BYTE (64U * 4U)

/*! @brief MIPI DSI structure definition. */
typedef struct
{
    DSI2_HOST_Type *host;      /*!< Pointer to HOST registers. */
    DSI2_HOST_VID_IF_Type *dpi;     /*!< Pointer to DPI registers. */
    DSI2_HOST_DBI_IF_Type *dbi;     /*!< Pointer to DBI registers. */
    DSI2_HOST_APB_PKT_IF_Type *apb; /*!< Pointer to APB registers. */
    DSI2_TX_PHY_Type *dphy;         /*!< Pointer to DPHY registers. */
} MIPI_DSI_Type;

/*! @brief Error codes for the MIPI DSI driver. */
enum
{
    kStatus_DSI_Busy        = MAKE_STATUS((int32_t)kStatusGroup_MIPI_DSI, 0), /*!< DSI is busy. */
    kStatus_DSI_RxDataError = MAKE_STATUS((int32_t)kStatusGroup_MIPI_DSI, 1), /*!< Read data error. */
    kStatus_DSI_ErrorReportReceived =
        MAKE_STATUS((int32_t)kStatusGroup_MIPI_DSI, 2),                        /*!< Error report package received. */
    kStatus_DSI_NotSupported = MAKE_STATUS((int32_t)kStatusGroup_MIPI_DSI, 3), /*!< The transfer type not supported. */
    kStatus_DSI_Invalid = MAKE_STATUS((int32_t)kStatusGroup_MIPI_DSI, 4), /*!< Invalid transmission. */
};

/*! @brief _dsi_rx_error_status Host receive error status. */
enum
{
    kDSI_RxErrorEccOneBit   = (1UL << 0U), /*!< ECC single bit error detected. */
    kDSI_RxErrorEccMultiBit = (1UL << 1U), /*!< ECC multi bit error detected. */
    kDSI_RxErrorCrc         = (1UL << 7U), /*!< CRC error detected. */
    kDSI_RxErrorHtxTo       = (1UL << 8U), /*!< High Speed forward TX timeout detected. */
    kDSI_RxErrorLrxTo       = (1UL << 9U), /*!< Reverse Low power data receive timeout detected. */
    kDSI_RxErrorBtaTo       = (1UL << 10U) /*!< BTA timeout detected. */
};

/*! @brief DSI host controller interrupt status */
enum _dsi_interrupt
{
    kDSI_HostSoTError                = (1UL << 0U), /*!< SoT error from peripheral error report. */
    kDSI_HostSoTSyncError            = (1UL << 1U), /*!< SoT Sync error from peripheral error report. */
    kDSI_HostEoTSyncError            = (1UL << 2U), /*!< EoT Sync error from peripheral error report. */
    kDSI_HostEscEntryCmdError        = (1UL << 3U), /*!< Escape Mode Entry Command Error from peripheral error report. */
    kDSI_HostLpTxSyncError           = (1UL << 4U), /*!< Low-power transmit Sync Error from peripheral error report. */
    kDSI_HostPeriphToError           = (1UL << 5U), /*!< Peripheral timeout error from peripheral error report. */
    kDSI_HostFalseControlError       = (1UL << 6U), /*!< False control error from peripheral error report. */
    kDSI_HostContentionError         = (1UL << 7U), /*!< Contention detected from peripheral error report. */
    kDSI_HostEccOneBitError          = (1UL << 8U), /*!< Single bit ECC error (corrected) from peripheral error report. */
    kDSI_HostEccMultiBitError        = (1UL << 9U), /*!< Multi bit ECC error (not corrected) from peripheral error report. */
    kDSI_HostCrcError                = (1UL << 10U), /*!< Checksum error from peripheral error report. */
    kDSI_HostInvalidDataTypeError    = (1UL << 11U), /*!< DSI data type not recognized. */
    kDSI_HostInvalidVcIdError        = (1UL << 12U), /*!< DSI VC ID invalid. */
    kDSI_HostInvalidTxLengthError    = (1UL << 13U), /*!< Invalid transmission length. */
    kDSI_HostProtocolViolationError  = (1UL << 15U), /*!< DSI protocol violation. */
    kDSI_HostResetTriggerReceived    = (1UL << 16U), /*!< Reset trigger received. */
    kDSI_HostTearTriggerReceived     = (1UL << 17U), /*!< Tear effect trigger receive. */
    kDSI_HostAckTriggerReceived      = (1UL << 18U), /*!< Acknowledge trigger message received. */
    kDSI_HostTearFailTriggerReceived = (1UL << 19U), /*!< Tear effect fail trigger receive. */
    kDSI_HostReadEccOneBit           = (1UL << 20U), /*!< ECC single bit error detected. */
    kDSI_HostReadEccMultiBit         = (1UL << 21U), /*!< ECC multi bit error detected. */
    kDSI_HostReadCrc                 = (1UL << 22U), /*!< CRC error detected. */
    kDSI_HostIrqRegParityError       = (1UL << 23U), /*!< IRQ register parity error. */
};

/*! @brief MIPI DSI PPI width. */
typedef enum _dsi_ppi_width
{
    kDSI_Ppi8Bit  = 0U,  /*!< PPI data width is 8-bit. */
    kDSI_Ppi16Bit = 1U,  /*!< PPI data width is 16-bit. Must use 16-bit for C-PHY support */
} dsi_ppi_width_t;

/*! @brief MIPI DSI controller configuration. */
typedef struct _dsi_config
{
    uint32_t numLanes : 4U;        /*!< Number of lanes. *///TODO 4? 2?
    uint32_t : 1U;                 /*!< Reserved. */
    uint32_t ppiWidth : 2U;        /*!< PPI width, see @ref dsi_ppi_width_t. */
    uint32_t : 1U;                 /*!< Reserved. */
    uint32_t enableContinuousHsClk : 1U; /*!< Set to true, the high speed clock will not enter
                                       low power mode between transmissions. */
    uint32_t autoInsertEoTp : 1U;  /*!< Insert an EoTp short package when switching from HS to LP. */
    uint32_t : 1U;                 /*!< Reserved. */
    uint32_t disableBurst : 1U;    /*!< Set to true, each packet is sent separately with a return
                                    to LP between each packet, otherwise packets are combined in a burst. */
    uint32_t disableCrcCheck : 1U; /*!< Set to true, controller will not check payload CRC from longs
                                    packets sent from peripheral. */
    uint32_t enableScramble : 1U;  /*!< Set to true to scramble long packet data and data CRC. */
    uint32_t : 17U;                /*!< Reserved. */
    uint32_t enable: 1U;           /*!< Enable DSI controller. */
    // uint32_t watchdogCount: 31U;           /*!< Watchdog count. *///TODO
    // uint32_t enableWatchdog: 1U;           /*!< Enable watchdog timer. */
    uint32_t htxTo_ByteClk : 24U;        /*!< HS TX timeout count (HTX_TO) in byte clock. */
    uint32_t : 8U;                /*!< Reserved. */
    uint32_t lrxHostTo_ByteClk : 24U;    /*!< LP RX host timeout count (LRX-H_TO) in byte clock. */
    uint32_t : 8U;                /*!< Reserved. */
    uint32_t btaTo_ByteClk : 24U;        /*!< Bus turn around timeout count (TA_TO) in byte clock. */
    uint32_t : 8U;                /*!< Reserved. */
} dsi_config_t;

/*! @brief DPI interrupt status. */
enum _dsi_dpi_interrupt
{
    kDSI_DpiFifoUnderflow  = (1UL << 9U),  /*!< DPI Host FIFO underflow error */
    kDSI_DpiFifoOverflow   = (1UL << 10U), /*!< DPI Host FIFO overflow error */
    kDSI_DpiSyncWhenActive = (1UL << 11U), /*!< Sync When Video Active Error. */
    kDSI_DpiSyncPulseError = (1UL << 12U), /*!< Sync Pulse Error. */
};

/*! @brief MIPI DSI pixel packet type send through DPI interface. */
typedef enum _dsi_dpi_pixel_packet
{
    kDSI_DpiPixelPacketCompressed   = 0x0BU, /*!< Compressed. */
    kDSI_DpiPixelPacket20BitYCbCr   = 0x0CU, /*!< 20 bit YCbCr, 6 bytes per 2 pixels. */
    kDSI_DpiPixelPacket24BitYCbCr   = 0x1CU, /*!< 24 bit YCbCr, 6 bytes per 2 pixels. */
    kDSI_DpiPixelPacket16BitYCbCr   = 0x2CU, /*!< 16 bit YCbCr, 4 bytes per 2 pixels. */
    kDSI_DpiPixelPacket30Bit        = 0x0DU, /*!< 30 bit RGB10_10_10. */
    kDSI_DpiPixelPacket36Bit        = 0x1DU, /*!< 36 bit RGB12_12_12. */
    kDSI_DpiPixelPacket12BitYCbCr   = 0x3DU, /*!< 12 bit YCbCr, 3 bytes per 2 pixels. */
    kDSI_DpiPixelPacket16Bit        = 0x0EU, /*!< 16 bit RGB565, 2 bytes per pixel. */
    kDSI_DpiPixelPacket18Bit        = 0x1EU, /*!< 18 bit RGB666 packed. */
    kDSI_DpiPixelPacket18BitLoosely = 0x2EU, /*!< 18 bit RGB666, one pixel loosely packed into three bytes. */
    kDSI_DpiPixelPacket24Bit        = 0x3EU, /*!< 24 bit RGB888, three bytes per pixel. */
} dsi_dpi_pixel_packet_t;

/*! @brief Mask to allow DPI external packet in which part of the frame. */
enum _dsi_dpi_extrenal_packet
{
    kDSI_DpiExternalVsw     = (1U << 0U), /*!< External packets are allowed during vertical sync. */
    kDSI_DpiExternalVbp     = (1U << 1U), /*!< External packets are allowed during vertical back porch. */
    kDSI_DpiExternalVactive = (1U << 2U), /*!< External packets are allowed during active video lines. */
    kDSI_DpiExternalVfp     = (1U << 3U), /*!< External packets are allowed during vertical front porch. */
};

/*! @brief Enable Multiple packets per video line in DPI mode. */
typedef enum _dsi_dpi_packet_per_line
{
    kDSI_Dpi1PacketPerLine = 1U, /*!< 1 packet sent per line. */
    kDSI_Dpi2PacketPerLine = 2U, /*!< 2 packets sent per line. */
    kDSI_Dpi3PacketPerLine = 3U, /*!< 3 packets sent per line. */
    kDSI_Dpi4PacketPerLine = 4U, /*!< 4 packets sent per line. */
    kDSI_Dpi5PacketPerLine = 5U, /*!< 5 packets sent per line. */
    kDSI_Dpi6PacketPerLine = 6U, /*!< 6 packets sent per line. */
    kDSI_Dpi7PacketPerLine = 7U, /*!< 7 packets sent per line. */
    kDSI_Dpi8PacketPerLine = 8U, /*!< 8 packets sent per line. */
} dsi_dpi_packet_per_line_t;

/*! @brief DPI video mode. */
typedef enum _dsi_dpi_video_mode
{
    kDSI_DpiNonBurstWithSyncPulse = 0U, /*!< Non-Burst mode with Sync Pulses. */
    kDSI_DpiNonBurstWithSyncEvent = 1U, /*!< Non-Burst mode with Sync Events. */
    kDSI_DpiBurst                 = 2U, /*!< Burst mode. */
} dsi_dpi_video_mode_t;

/*! @brief DPI signal polarity. */
enum _dsi_dpi_polarity_flag
{
    kDSI_DpiHsyncActiveLow  = 0U,         /*!< HSYNC active low. */
    kDSI_DpiVsyncActiveLow  = 0U,         /*!< VSYNC active low. */
    kDSI_DpiHsyncActiveHigh = (1U << 0U), /*!< HSYNC active high. */
    kDSI_DpiVsyncActiveHigh = (1U << 1U), /*!< VSYNC active high. */
};

/*! @brief Behavior in BLLP (Blanking or Low-Power Interval). */
enum _dsi_dpi_bllp_mode
{
    kDSI_DpiBllpBlanking           = 0U,         /*!< Blanking packet used in BLLP periods. */
    kDSI_DpiBllpNull               = (1U << 0U), /*!< Null packet used in BLLP periods. */
    kDSI_DpiBllpVerticalLowPower   = (1U << 1U), /*!< LP mode is used in vertical BLLP periods. */
    kDSI_DpiBllpHorizontalLowPower = (1U << 2U), /*!< LP mode is used in horizontal BLLP periods. */
};

/*! @brief DPI video mode pixel alignment when pixel number is smaller than the maximum pixel size. */
typedef enum _dsi_dpi_alignment_mode
{
    kDSI_DpiLsb = 0U, /*!< Lower pixels are valid: 00000PPP. */
    kDSI_DpiMsb = 1U, /*!< Higher pixel are valid: PPP00000. */
} dsi_dpi_alignment_mode_t;

/*! @brief MIPI DSI controller DPI interface configuration. */
typedef struct _dsi_dpi_config
{
    uint32_t pixelPacket : 6U;     /*!< Pixel packet format. See @ref dsi_dpi_pixel_packet_t. */
    uint32_t virtualChannel : 2U;  /*!< Virtual channel. */
    uint32_t externalPacket : 4U;  /*!< OR'ed value of @ref _dsi_dpi_extrenal_packet to configure when external packets are allowed. */
    uint32_t packetPerLine : 4U;   /*!< Enable multiple packets per video line. See @ref dsi_dpi_packet_per_line_t. */
    uint32_t videoMode : 2U;       /*!< Video mode. See @ref dsi_dpi_video_mode_t. */
    uint32_t polarityFlags : 2U;   /*!< OR'ed value of @ref _dsi_dpi_polarity_flag controls signal polarity. */
    uint32_t bllpMode : 3U;        /*!< OR'ed value of @ref _dsi_dpi_bllp_mode to control behavior in BLLP. */
    uint32_t overrideTiming : 1;   /*!< Set to true to use hfp/hbp/hsw/vfp/vbp/panelHeight configurations directly,
                                        otherwise the host uses the first video frame to calibrate automatically. */
    uint32_t alignment : 1U;       /*!< The alignment for pixel when the number is smaller than the maximum pixel
                                        size. See @ref dsi_dpi_alignment_mode_t. */
    uint32_t : 6U;                 /*!< Reserved. */
    uint32_t enable: 1U;           /*!< Enable DPI mode. */
    uint32_t pixelPerPacket : 16U; /*!< Number of pixels to be sent per packet. pixelPerPacket x packetPerLine shall be the pixel number each line. */
    // uint32_t pixelPayloadSize : 16U; /*!< Maximum number of pixels that should be sent
    //                                  as one DSI packet. Recommended that the pixelPerPacket is
    //                                  evenly divisible by this parameter. todo */
    uint32_t payloadPerPacket : 16U; /*!< Number of bytes in each packet, alongside with pixelPerPacket
                                          indicate which video ports contain valid data on the last cycle
                                          of the slice/chunk. */
    uint32_t startDelay : 16U;       /*!< The delay cycle before start of line. Used to buffer enough pixel in FIFO to prevent underflow. */
    uint32_t vssPayload : 16U;       /*!< The payload value for Vertical Sync Start.
                                          Normally the 16 bit payload is 16’h0000 for all sync events,
                                          but the MIPI spec allows the VSS to send a non-zero payload. */
    uint32_t hfp : 16U;         /*!< Horizontal front porch, in dpi pixel clock. */
    uint32_t hbp : 16U;         /*!< Horizontal back porch, in dpi pixel clock. */
    uint32_t hsw : 16U;         /*!< Horizontal sync width, in dpi pixel clock. */
    uint32_t vbp : 16U;         /*!< Number of lines in vertical back porch. */
    uint32_t vfp : 16U;         /*!< Number of lines in vertical front porch. */
    uint32_t panelHeight : 16U; /*!< Line number in vertical active area. */
} dsi_dpi_config_t;

/*! @brief DBI status. */
enum _dsi_dbi_status
{
    kDSI_DbiFifoUnderflow = (1UL << 0U), /*!< DBI Host FIFO underflow error */
    kDSI_DbiFifoOverflow  = (1UL << 1U), /*!< DBI Host FIFO overflow error */
};

/*! @brief DBI pixel format. */
typedef enum _dsi_dbi_pixel_format
{
    kDSI_DbiNoMapping = 0U, /*!< No pixel to bit mapping. */
    kDSI_DbiRGB888    = 1U, /*!< Send data to interface as RGB888 format. */
    kDSI_DbiRGB666    = 2U, /*!< Send data to interface as RGB666 format. */
    kDSI_DbiRGB565    = 3U, /*!< Send data to interface as RGB565 format. */
    kDSI_DbiRGB444    = 4U, /*!< Send data to interface as RGB444 format. */
    kDSI_DbiRGB332    = 5U, /*!< Send data to interface as RGB332 format. */
} dsi_dbi_pixel_format_t;

/*! @brief MIPI DSI controller DBI interface configuration. */
typedef struct _dsi_dbi_config
{
    bool enable;                   /*!< Enable DBI mode. */
    dsi_dbi_pixel_format_t format; /*!< DBI pixel format. */
    uint8_t virtualChannel;        /*!< Virtual channel. */
} dsi_dbi_config_t;

/*! @brief MIPI DSI D-PHY configuration. */
typedef struct _dsi_dphy_config
{
    uint32_t txHsBitClk_Hz;         /*!< The generated HS TX bit clock in Hz. */
    uint8_t tClkPre_ByteClk;        /*!< TLPX + TCLK-PREPARE + TCLK-ZERO + TCLK-PRE in byte clock.
                                         Set how long the controller
                                         will wait after enabling clock lane for HS before
                                         enabling data lanes for HS. */
    uint8_t tClkPost_ByteClk;       /*!< TCLK-POST + T_CLK-TRAIL in byte clock. Set how long the controller
                                         will wait before putting clock lane into LP mode after
                                         data lanes detected in stop state. */
    uint8_t tHsExit_ByteClk;        /*!< THS-EXIT in byte clock. Set how long the controller
                                         will wait after the clock lane has been put into LP
                                         mode before enabling clock lane for HS again. */
    uint8_t tClkGap_ByteClk;        /*!< The count that the controller waits when changing from continous to
                                         non-continuous clock in unit of byte clock. */
    uint32_t tWakeup_EscClk;        /*!< Number of clk_esc clock periods to keep a clock
                                         or data lane in Mark-1 state after exiting ULPS. */
    uint8_t tHsPrepare_HalfTxEscClk;  /*!< THS-PREPARE in tx_clk_esc/2. Set how long
                                           to drive the LP-00 state before HS transmissions,
                                           available values are 2, 3, 4, 5. */
    uint8_t tClkPrepare_HalfTxEscClk; /*!< TCLK-PREPARE in tx_clk_esc/2. Set how long
                                           to drive the LP-00 state before HS transmissions,
                                           available values are 2, 3, 4, 5. */
    uint8_t tHsZero_ByteClk;        /*!< THS-ZERO in clk_byte. Set how long that controller
                                         drives data lane HS-0 state before transmit
                                         the Sync sequence. */
    uint8_t tClkZero_ByteClk;       /*!< TCLK-ZERO in clk_byte. Set how long that controller
                                         drives clock lane HS-0 state before transmit
                                         the Sync sequence. */
    uint8_t tHsTrail_ByteClk;       /*!< THS-TRAIL + 4*UI in clk_byte. Set the time
                                         of the flipped differential state after last payload
                                         data bit of HS transmission burst. Available values
                                         are 0, 1, ..., 15. */
    uint8_t tClkTrail_ByteClk;      /*!< TCLK-TRAIL + 4*UI in clk_byte. Set the time
                                         of the flipped differential state after last payload
                                         data bit of HS transmission burst. Available values
                                         are 0, 1, ..., 15. */
    uint8_t tClkSettle_RxEscClk; /*!< T-CLK-SETTLE in tx_clk_esc. Time interval during which
                                      the HS receiver should ignore any Clock Lane HS transitions, starting
                                      from the beginning of TCLK-PREPARE. */
    uint8_t tHsSettle_RxEscClk;  /*!< T-HS-SETTLE + 4*UI in tx_clk_esc. Time interval during which the
                                      HS receiver shall ignore any Data Lane HS transitions, starting
                                      from the beginning of THS-PREPARE. */
} dsi_dphy_config_t;

/*! @brief DSI APB interrupt status. */
enum _dsi_apb_interrupt
{
    kDSI_ApbNotIdle          = (1UL << 0U), /*!< State machine not idle */
    kDSI_ApbTxDone           = (1UL << 1U), /*!< Tx packet done */
    kDSI_ApbRxControl        = (1UL << 2U), /*!< DPHY direction 0 - tx had control, 1 - rx has control */
    kDSI_ApbTxOverflow       = (1UL << 3U), /*!< TX fifo overflow */
    kDSI_ApbTxUnderflow      = (1UL << 4U), /*!< TX fifo underflow */
    kDSI_ApbRxOverflow       = (1UL << 5U), /*!< RX fifo overflow */
    kDSI_ApbRxUnderflow      = (1UL << 6U), /*!< RX fifo underflow */
    kDSI_ApbRxHeaderReceived = (1UL << 7U), /*!< RX packet header has been received */
    kDSI_ApbRxPacketReceived = (1UL << 8U), /*!< All RX packet payload data has been received */
    kDSI_ApbBtaTo            = (1UL << 9U), /*!< BTA timeout */
    kDSI_ApbLrxTo            = (1UL << 10U), /*!< Low power receive timeout */
    kDSI_ApbHtxTo            = (1UL << 11U), /*!< High speed transmit timeout */
    kDSI_ApbParityError      = (1UL << 12U), /*!< Parity error */
};

/*! @brief DSI TX data type. */
typedef enum _dsi_tx_data_type
{
    kDSI_TxDataVsyncStart                   = 0x01U, /*!< V Sync start. */
    kDSI_TxDataVsyncEnd                     = 0x11U, /*!< V Sync end. */
    kDSI_TxDataHsyncStart                   = 0x21U, /*!< H Sync start. */
    kDSI_TxDataHsyncEnd                     = 0x31U, /*!< H Sync end. */
    kDSI_TxDataCompressionMode              = 0x07U, /*!< Compression Mode Command. */
    kDSI_TxDataEoTp                         = 0x08U, /*!< End of transmission packet. */
    kDSI_TxDataCmOff                        = 0x02U, /*!< Color mode off. */
    kDSI_TxDataCmOn                         = 0x12U, /*!< Color mode on. */
    kDSI_TxDataShutDownPeriph               = 0x22U, /*!< Shut down peripheral. */
    kDSI_TxDataTurnOnPeriph                 = 0x32U, /*!< Turn on peripheral. */
    kDSI_TxDataGenShortWrNoParam            = 0x03U, /*!< Generic Short WRITE, no parameters. */
    kDSI_TxDataGenShortWrOneParam           = 0x13U, /*!< Generic Short WRITE, one parameter. */
    kDSI_TxDataGenShortWrTwoParam           = 0x23U, /*!< Generic Short WRITE, two parameter. */
    kDSI_TxDataGenShortRdNoParam            = 0x04U, /*!< Generic Short READ, no parameters. */
    kDSI_TxDataGenShortRdOneParam           = 0x14U, /*!< Generic Short READ, one parameter. */
    kDSI_TxDataGenShortRdTwoParam           = 0x24U, /*!< Generic Short READ, two parameter. */
    kDSI_TxDataDcsShortWrNoParam            = 0x05U, /*!< DCS Short WRITE, no parameters. */
    kDSI_TxDataDcsShortWrOneParam           = 0x15U, /*!< DCS Short WRITE, one parameter. */
    kDSI_TxDataDcsShortRdNoParam            = 0x06U, /*!< DCS Short READ, no parameters. */
    kDSI_TxDataExecuteQueue                 = 0x16U, /*!< Execute Queue. */
    kDSI_TxDataSetMaxReturnPktSize          = 0x37U, /*!< Set the Maximum Return Packet Size. */
    kDSI_TxDataScramblingMode               = 0x27U, /*!< Scrambling Mode Command. */
    kDSI_TxDataNull                         = 0x09U, /*!< Null Packet, no data. */
    kDSI_TxDataBlanking                     = 0x19U, /*!< Blanking Packet, no data. */
    kDSI_TxDataGenLongWr                    = 0x29U, /*!< Generic long write. */
    kDSI_TxDataDcsLongWr                    = 0x39U, /*!< DCS Long Write/write_LUT Command Packet. */
    kDSI_TxDataPictureParameterSet          = 0x0AU, /*!< Picture Parameter Set. */
    kDSI_TxDataServiceExtensions            = 0x25U, /*!< Service Extensions Packet (SEP). */
    kDSI_TxDataPhysicalEventNotification    = 0x26U, /*!< Physical Event Notification Packet (PENP). */
    kDSI_TxDataCompressedPixel              = 0x0BU, /*!< Compressed Pixel Stream. */
    kDSI_TxDataLooselyPackedPixel20BitYCbCr = 0x0CU, /*!< Loosely Packed Pixel Stream, 20-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel24BitYCbCr        = 0x1CU, /*!< Packed Pixel Stream, 24-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel16BitYCbCr        = 0x2CU, /*!< Packed Pixel Stream, 16-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel20BitYCbCr        = 0x3CU, /*!< Packed Pixel Stream, 20-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel30BitRGB          = 0x0DU, /*!< Packed Pixel Stream, 30-bit RGB, 10-10-10 Format. */
    kDSI_TxDataPackedPixel36BitRGB          = 0x1DU, /*!< Packed Pixel Stream, 36-bit RGB, 12-12-12 Format. */
    kDSI_TxDataPackedPixel48BitRGB          = 0x2DU, /*!< Packed Pixel Stream, 48-bit RGB, 16-16-16 Format. */
    kDSI_TxDataPackedPixel12BitYCrCb        = 0x3DU, /*!< Packed Pixel Stream, 12-bit YCbCr, 4:2:0 Format. */
    kDSI_TxDataPackedPixel16BitRGB          = 0x0EU, /*!< Packed Pixel Stream, 16-bit RGB, 5-6-5 Format. */
    kDSI_TxDataPackedPixel18BitRGB          = 0x1EU, /*!< Packed Pixel Stream, 18-bit RGB, 6-6-6 Format. */
    kDSI_TxDataLooselyPackedPixel18BitRGB   = 0x2EU, /*!< Loosely Packed Pixel Stream, 18-bit RGB, 6-6-6 Format. */
    kDSI_TxDataPackedPixel24BitRGB          = 0x3EU, /*!< Packed Pixel Stream, 24-bit RGB, 8-8-8 Format. */
} dsi_tx_data_type_t;

/*! @brief DSI RX data type. */
typedef enum _dsi_rx_data_type
{
    kDSI_RxDataAckAndErrorReport         = 0x02U, /*!< Acknowledge and Error Report */
    kDSI_RxDataEoTp                      = 0x08U, /*!< End of Transmission packet. */
    kDSI_RxDataGenShortRdResponseOneByte = 0x11U, /*!< Generic Short READ Response, 1 byte returned. */
    kDSI_RxDataGenShortRdResponseTwoByte = 0x12U, /*!< Generic Short READ Response, 2 byte returned. */
    kDSI_RxDataGenLongRdResponse         = 0x1AU, /*!< Generic Long READ Response. */
    kDSI_RxDataDcsLongRdResponse         = 0x1CU, /*!< DCS Long READ Response. */
    kDSI_RxDataDcsShortRdResponseOneByte = 0x21U, /*!< DCS Short READ Response, 1 byte returned. */
    kDSI_RxDataDcsShortRdResponseTwoByte = 0x22U, /*!< DCS Short READ Response, 2 byte returned. */
    kDSI_RxDataServiceExtensions         = 0x25U, /*!< Service Extensions Packet (SEP). */
    kDSI_RxDataPhysicalEventNotification = 0x26U, /*!< Physical Event Notification Packet (PENP). */
} dsi_rx_data_type_t;

/*! @brief DSI transfer control flags. */
enum _dsi_transfer_flags
{
    kDSI_TransferUseHighSpeed = (1U << 0U), /*!< Use high speed mode or not. */
    kDSI_TransferPerformBTA   = (1U << 1U), /*!< Perform BTA or not. */
};

/*! @brief Structure for the data transfer. */
typedef struct _dsi_transfer
{
    uint8_t virtualChannel;        /*!< Virtual channel. */
    dsi_tx_data_type_t txDataType; /*!< TX data type. */
    uint8_t flags;                 /*!< Flags to control the transfer, see _dsi_transfer_flags. */
    const uint8_t *txData;         /*!< The TX data buffer. */
    uint8_t *rxData;               /*!< The TX data buffer. */
    uint16_t txDataSize;           /*!< Size of the TX data. */
    uint16_t rxDataSize;           /*!< Size of the RX data. */
    bool sendDcsCmd;               /*!< If set to true, the DCS command is specified by @ref dcsCmd, otherwise
                                        the DCS command is included in the @ref txData. */
    uint8_t dcsCmd;                /*!< The DCS command to send, only valid when @ref sendDcsCmd is true. */
} dsi_transfer_t;

/*! @brief MIPI DSI transfer handle. */
typedef struct _dsi_handle dsi_handle_t;

/*!
 * @brief MIPI DSI callback for finished transfer.
 *
 * When transfer finished, one of these status values will be passed to the user:
 * - @ref kStatus_Success Data transfer finished with no error.
 * - @ref kStatus_Timeout Transfer failed because of timeout.
 * - @ref kStatus_DSI_RxDataError RX data error, user could use @ref DSI_GetRxErrorStatus
 *        to check the error details.
 * - @ref kStatus_DSI_ErrorReportReceived Error Report packet received, user could use
 *        @ref DSI_GetAndClearHostStatus to check the error report status.
 * - @ref kStatus_Fail Transfer failed for other reasons.
 */
typedef void (*dsi_callback_t)(const MIPI_DSI_Type *base, dsi_handle_t *handle, status_t status, void *userData);

/*! @brief MIPI DSI transfer handle structure */
struct _dsi_handle
{
    volatile bool isBusy;     /*!< MIPI DSI is busy with APB data transfer. */
    dsi_transfer_t xfer;      /*!< Transfer information. */
    dsi_callback_t callback;  /*!< DSI callback */
    void *userData;           /*!< Callback parameter */
    const MIPI_DSI_Type *dsi; /*!< Pointer to MIPI DSI peripheral. */
};

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enable the DSI host interrupts.
 *
 * The interrupts to enable are passed in as OR'ed value of _dsi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to enable.
 */
static inline void DSI_EnableHostInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->host->PERIPH_IRQ_STATUS |= interrupt;
}

/*!
 * @brief Disable the DSI host interrupts.
 *
 * The interrupts to disable are passed in as OR'ed value of _dsi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to disable.
 */
static inline void DSI_DisableHostInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->host->PERIPH_IRQ_STATUS &= ~interrupt;
}

/*!
 * @brief Get the DSI host interrupt.
 *
 * The host status are returned as OR'ed value of @ref _dsi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The DSI host interrupt status.
 */
static inline uint32_t DSI_GetHostInterruptStatus(const MIPI_DSI_Type *base)
{
    return base->host->PERIPH_IRQ_STATUS;
}

/*!
 * @brief Clear the DSI host interrupt.
 *
 * Clear the status of the host interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param status The status to clear as OR'ed value of @ref _dsi_interrupt.
 */
static inline void DSI_ClearHostInterruptStatus(const MIPI_DSI_Type *base, uint32_t status)
{
    base->host->PERIPH_IRQ_STATUS = status;
}

/*!
 * @brief Enable the DSI DPI interrupts.
 *
 * The interrupts to enable are passed in as OR'ed value of _dsi_dpi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to enable.
 */
static inline void DSI_EnableDpiInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->dpi->VID_IRQ_MASK |= interrupt;
}

/*!
 * @brief Disable the DSI DPI interrupts.
 *
 * The interrupts to disable are passed in as OR'ed value of _dsi_dpi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to disable.
 */
static inline void DSI_DisableDpiInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->dpi->VID_IRQ_MASK &= ~interrupt;
}

/*!
 * @brief Get the DSI DPI interrupt.
 *
 * The host status are returned as OR'ed value of @ref _dsi_dpi_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The DSI host interrupt status.
 */
static inline uint32_t DSI_GetDpiInterruptStatus(const MIPI_DSI_Type *base)
{
    return base->dpi->VID_IRQ_STATUS;
}

/*!
 * @brief Clear the DSI DPI interrupt.
 *
 * Clear the status of the host interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param status The status to clear as OR'ed value of @ref _dsi_dpi_interrupt.
 */
static inline void DSI_ClearDpiInterruptStatus(const MIPI_DSI_Type *base, uint32_t status)
{
    base->dpi->VID_IRQ_STATUS = status;
}

/*!
 * @brief Enable the DSI APB interrupts.
 *
 * The interrupts to enable are passed in as OR'ed value of _dsi_apb_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to enable.
 */
static inline void DSI_EnableApbInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->apb->CFG_APB_IRQ_MASK |= interrupt;
}

/*!
 * @brief Disable the DSI APB interrupts.
 *
 * The interrupts to disable are passed in as OR'ed value of _dsi_apb_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param interrupt Interrupts to disable.
 */
static inline void DSI_DisableApbInterrupts(const MIPI_DSI_Type *base, uint32_t interrupt)
{
    base->apb->CFG_APB_IRQ_MASK &= ~interrupt;
}

/*!
 * @brief Get the DSI APB interrupt.
 *
 * The host status are returned as OR'ed value of @ref _dsi_apb_interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The DSI APB interrupt status.
 */
static inline uint32_t DSI_GetApbInterruptStatus(const MIPI_DSI_Type *base)
{
    return base->apb->CFG_APB_IRQ_STATUS;
}

/*!
 * @brief Clear the DSI APB interrupt.
 *
 * Clear the status of the host interrupt.
 *
 * @param base MIPI DSI peripheral base address.
 * @param status The status to clear as OR'ed value of @ref _dsi_apb_interrupt.
 */
static inline void DSI_ClearApbInterruptStatus(const MIPI_DSI_Type *base, uint32_t status)
{
    base->apb->CFG_APB_IRQ_STATUS = status;
}
/*! @} */

/*!
 * @name DSI host.
 * @{
 */

/*!
 * @brief Initializes an MIPI DSI with the user configuration.
 *
 * This function initializes the MIPI DSI with the configuration, it should
 * be called first before other MIPI DSI driver functions.
 *
 * @param base MIPI DSI peripheral base address.
 * @param config Pointer to a user-defined configuration structure.
 */
void DSI_Init(const MIPI_DSI_Type *base, const dsi_config_t *config);

/*!
 * @brief Deinitializes an MIPI DSI.
 *
 * This function should be called after all bother MIPI DSI driver functions.
 *
 * @param base MIPI DSI peripheral base address.
 */
void DSI_Deinit(const MIPI_DSI_Type *base);

/*!
 * @brief Get the default configuration to initialize the MIPI DSI.
 *
 * The default value is:
 * @code
    config->enable                = true;
    config->numLanes              = 2;
    config->ppiWidth              = kDSI_Ppi8Bit;
    config->enableContinuousHsClk = true;
    config->autoInsertEoTp        = true;
    config->disableBurst          = false;
    config->disableCrcCheck       = false;
    config->enableScramble        = false;
    config->enableWatchdog        = false;
    config->htxTo_ByteClk         = 0;
    config->lrxHostTo_ByteClk     = 0;
    config->btaTo_ByteClk         = 0;
   @endcode
 *
 * @param config Pointer to a user-defined configuration structure.
 */
void DSI_GetDefaultConfig(dsi_config_t *config);

/*! @} */

/*!
 * @name DPI interface
 * @{
 */

/*!
 * @brief Configure the DPI interface core.
 *
 * This function sets the DPI interface configuration, it should be used in
 * video mode.
 *
 * @param base MIPI DSI peripheral base address.
 * @param config Pointer to the DPI interface configuration.
 * @param numLanes Lane number, should be same with the setting in @ref dsi_dpi_config_t.
 * @param dpiPixelClkFreq_Hz The DPI pixel clock frequency in Hz.
 * @param dsiHsBitClkFreq_Hz The DSI high speed bit clock frequency in Hz. It is
 * the same with DPHY PLL output.
 */
void DSI_SetDpiConfig(const MIPI_DSI_Type *base,
    const dsi_dpi_config_t *config,
    uint8_t numLanes,
    uint32_t dpiPixelClkFreq_Hz,
    uint32_t dsiHsBitClkFreq_Hz);

/*! @} */

/*!
 * @name DBI interface
 * @{
 */

/*!
 * @brief Configure the DBI pixel FIFO send level.
 *
 * This controls the level at which the DBI Host bridge begins sending pixels
 *
 * @param base MIPI DSI peripheral base address.
 * @param sendLevel Send level value set to register.
 */
static inline void DSI_SetDbiPixelFifoSendLevel(MIPI_DSI_Type *base, uint16_t sendLevel)
{
    base->dbi->CFG_DBI_PIXEL_FIFO_SEND_LEVEL = (uint32_t)sendLevel;
}

/*!
 * @brief Configure the DBI pixel payload size.
 *
 * Configures maximum number of pixels that should be sent as one DSI packet.
 * Recommended to be evenly divisible by the line size (in pixels).
 *
 * @param base MIPI DSI peripheral base address.
 * @param payloadSize Payload size value set to register.
 */
static inline void DSI_SetDbiPixelPayloadSize(MIPI_DSI_Type *base, uint16_t payloadSize)
{
    base->dbi->CFG_DBI_PIXEL_PAYLOAD_SIZE = (uint32_t)payloadSize;
}

/*!
 * @brief Get the DBI host status.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The DBI host status, OR'ed value of @ref _dsi_dbi_status.
 */
static inline uint32_t DSI_GetDbiHostStatus(MIPI_DSI_Type *base)
{
    return base->dbi->DBI_HOST_STATUS;
}

/*!
 * @brief Configure the DBI interface core.
 *
 * This function sets the DBI interface configuration.
 *
 * @param base MIPI DSI peripheral base address.
 * @param config Pointer to the DBI interface configuration.
 */
void DSI_SetDbiConfig(const MIPI_DSI_Type *base, const dsi_dbi_config_t *config);
/*! @} */

/*!
 * @name D-PHY configuration.
 * @{
 */

/*!
 * @brief Initializes the D-PHY
 *
 * This function configures the D-PHY timing and setups the D-PHY PLL based on
 * user configuration. The configuration structure could be got by the function
 * @ref DSI_GetDphyDefaultConfig.
 *
 * For some platforms there is not dedicated D-PHY PLL, indicated by the macro
 * FSL_FEATURE_MIPI_DSI_NO_DPHY_PLL. For these platforms, the @p refClkFreq_Hz
 * is useless.
 *
 * @param base MIPI DSI peripheral base address.
 * @param config Pointer to the D-PHY configuration.
 * @param refClkFreq_Hz The REFCLK frequency in Hz.
 * @return The actual D-PHY PLL output frequency. If could not configure the
 * PLL to the target frequency, the return value is 0.
 */
uint32_t DSI_InitDphy(const MIPI_DSI_Type *base, const dsi_dphy_config_t *config, uint32_t refClkFreq_Hz);

/*!
 * @brief Deinitializes the D-PHY
 *
 * Power down the D-PHY PLL and shut down D-PHY.
 *
 * @param base MIPI DSI peripheral base address.
 */
void DSI_DeinitDphy(const MIPI_DSI_Type *base);

/*!
 * @brief Get the default D-PHY configuration.
 *
 * Gets the default D-PHY configuration, the timing parameters are set according
 * to D-PHY specification. User could use the configuration directly, or change
 * some parameters according to the special device.
 *
 * @param config Pointer to the D-PHY configuration.
 * @param txHsBitClk_Hz High speed bit clock in Hz.
 * @param txEscClk_Hz tx Esc clock in Hz.
 * @param rxEscClk_Hz rx Esc clock in Hz.
 */
void DSI_GetDphyDefaultConfig(dsi_dphy_config_t *config, uint32_t txHsBitClk_Hz, uint32_t txEscClk_Hz, uint32_t rxEscClk_Hz);

/*! @} */

/*!
 * @name MIPI DSI APB
 * @{
 */
/*!
 * @brief Get the receive error status during data transfer.
 *
 * The return value is OR'ed value of _dsi_rx_error_status.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The error status.
 */
static inline uint32_t DSI_GetRxErrorStatus(const MIPI_DSI_Type *base)
{
    return base->host->CFG_RX_ERROR_STATUS;
}

/*!
 * @brief Configure the APB packet to send.
 *
 * This function configures the next APB packet transfer. After configuration,
 * the packet transfer could be started with function @ref DSI_SendApbPacket.
 * If the packet is long packet, Use @ref DSI_WriteApbTxPayload to fill the payload
 * before start transfer.
 *
 * @param base MIPI DSI peripheral base address.
 * @param wordCount For long packet, this is the byte count of the payload.
 * For short packet, this is (data1 << 8) | data0.
 * @param virtualChannel Virtual channel.
 * @param dataType The packet data type, (DI).
 * @param flags The transfer control flags, see @ref _dsi_transfer_flags.
 */
void DSI_SetApbPacketControl(
    const MIPI_DSI_Type *base, uint16_t wordCount, uint8_t virtualChannel, dsi_tx_data_type_t dataType, uint8_t flags);

/*!
 * @brief Fill the long APB packet payload.
 *
 * Write the long packet payload to TX FIFO.
 *
 * @param base MIPI DSI peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 */
void DSI_WriteApbTxPayload(const MIPI_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize);

/*!
 * @brief Extended function to fill the payload to TX FIFO.
 *
 * Write the long packet payload to TX FIFO. This function could be used in two ways
 *
 * 1. Include the DCS command in parameter @p payload. In this case, the DCS command
 *    is the first byte of @p payload. The parameter @p sendDcsCmd is set to false,
 *    the @p dcsCmd is not used. This function is the same as @ref DSI_WriteApbTxPayload
 *    when used in this way.
 *
 * 2. The DCS command in not in parameter @p payload, but specified by parameter @p dcsCmd.
 *    In this case, the parameter @p sendDcsCmd is set to true, the @p dcsCmd is the DCS
 *    command to send. The @p payload is sent after @p dcsCmd.
 *
 * @param base MIPI DSI peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 * @param sendDcsCmd If set to true, the DCS command is specified by @p dcsCmd,
 *        otherwise the DCS command is included in the @p payload.
 * @param dcsCmd The DCS command to send, only used when @p sendDcsCmd is true.
 */
void DSI_WriteApbTxPayloadExt(
    const MIPI_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize, bool sendDcsCmd, uint8_t dcsCmd);

/*!
 * @brief Read the long APB packet payload.
 *
 * Read the long packet payload from RX FIFO. This function reads directly but
 * does not check the RX FIFO status. Upper layer should make sure there are
 * available data.
 *
 * @param base MIPI DSI peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 */
void DSI_ReadApbRxPayload(const MIPI_DSI_Type *base, uint8_t *payload, uint16_t payloadSize);

/*!
 * @brief Trigger the controller to send out APB packet.
 *
 * Send the packet set by @ref DSI_SetApbPacketControl.
 *
 * @param base MIPI DSI peripheral base address.
 */
static inline void DSI_SendApbPacket(const MIPI_DSI_Type *base)
{
    base->apb->CFG_SEND_PACKET = 0x1U;
}

/*!
 * @brief Get the one-bit RX ECC error position.
 *
 * When one-bit ECC RX error detected using @ref DSI_GetRxErrorStatus, this
 * function could be used to get the error bit position.
 *
 * @code
   uint8_t eccErrorPos;
   uint32_t rxErrorStatus = DSI_GetRxErrorStatus(MIPI_DSI);
   if (kDSI_RxErrorEccOneBit & rxErrorStatus)
   {
       eccErrorPos = DSI_GetEccRxErrorPosition(rxErrorStatus);
   }
   @endcode
 *
 * @param rxErrorStatus The error status returned by @ref DSI_GetRxErrorStatus.
 * @return The 1-bit ECC error position.
 */
static inline uint8_t DSI_GetEccRxErrorPosition(uint32_t rxErrorStatus)
{
    return (uint8_t)((rxErrorStatus >> 2U) & 0x1FU);
}

/*!
 * @brief Get the RX packet header.
 *
 * @param base MIPI DSI peripheral base address.
 * @return The RX packet header.
 */
static inline uint32_t DSI_GetRxPacketHeader(const MIPI_DSI_Type *base)
{
    return base->apb->CFG_PKT_RX_PKT_HEADER;
}

/*!
 * @brief Extract the RX packet type from the packet header.
 *
 * Extract the RX packet type from the packet header get by @ref DSI_GetRxPacketHeader.
 *
 * @param rxPktHeader The RX packet header get by @ref DSI_GetRxPacketHeader.
 * @return The RX packet type.
 */
static inline dsi_rx_data_type_t DSI_GetRxPacketType(uint32_t rxPktHeader)
{
    return (dsi_rx_data_type_t)(uint8_t)((rxPktHeader >> 16U) & 0x3FU);
}

/*!
 * @brief Extract the RX packet word count from the packet header.
 *
 * Extract the RX packet word count from the packet header get by @ref DSI_GetRxPacketHeader.
 *
 * @param rxPktHeader The RX packet header get by @ref DSI_GetRxPacketHeader.
 * @return For long packet, return the payload word count (byte). For short packet,
 * return the (data0 << 8) | data1.
 */
static inline uint16_t DSI_GetRxPacketWordCount(uint32_t rxPktHeader)
{
    return (uint16_t)(rxPktHeader & 0xFFFFU);
}

/*!
 * @brief Extract the RX packet virtual channel from the packet header.
 *
 * Extract the RX packet virtual channel from the packet header get by @ref DSI_GetRxPacketHeader.
 *
 * @param rxPktHeader The RX packet header get by @ref DSI_GetRxPacketHeader.
 * @return The virtual channel.
 */
static inline uint8_t DSI_GetRxPacketVirtualChannel(uint32_t rxPktHeader)
{
    return (uint8_t)((rxPktHeader >> 22U) & 0x3U);
}

/*!
 * @brief APB data transfer using blocking method.
 *
 * Perform APB data transfer using blocking method. This function waits until all
 * data send or received, or timeout happens.
 *
 * When using this API to read data, the actually read data count could be got
 * from xfer->rxDataSize.
 *
 * @param base MIPI DSI peripheral base address.
 * @param xfer Pointer to the transfer structure.
 * @retval kStatus_Success Data transfer finished with no error.
 * @retval kStatus_Timeout Transfer failed because of timeout.
 * @retval kStatus_DSI_RxDataError RX data error, user could use @ref DSI_GetRxErrorStatus
 * to check the error details.
 * @retval kStatus_DSI_ErrorReportReceived Error Report packet received, user could use
 *        @ref DSI_GetAndClearHostStatus to check the error report status.
 * @retval kStatus_DSI_NotSupported Transfer format not supported.
 * @retval kStatus_DSI_Invalid The transmission is invalid.
 * @retval kStatus_Fail Transfer failed for other reasons.
 */
status_t DSI_TransferBlocking(const MIPI_DSI_Type *base, dsi_transfer_t *xfer);

/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*!
 * @brief Create the MIPI DSI handle.
 *
 * This function initializes the MIPI DSI handle which can be used for other transactional APIs.
 *
 * @param base MIPI DSI peripheral base address.
 * @param handle Handle pointer.
 * @param callback Callback function.
 * @param userData User data.
 */
status_t DSI_TransferCreateHandle(const MIPI_DSI_Type *base,
                                  dsi_handle_t *handle,
                                  dsi_callback_t callback,
                                  void *userData);

/*!
 * @brief APB data transfer using interrupt method.
 *
 * Perform APB data transfer using interrupt method, when transfer finished,
 * upper layer could be informed through callback function.
 *
 * When using this API to read data, the actually read data count could be got
 * from handle->xfer->rxDataSize after read finished.
 *
 * @param base MIPI DSI peripheral base address.
 * @param handle pointer to dsi_handle_t structure which stores the transfer state.
 * @param xfer Pointer to the transfer structure.
 *
 * @retval kStatus_Success Data transfer started successfully.
 * @retval kStatus_DSI_Busy Failed to start transfer because DSI is busy with pervious transfer.
 * @retval kStatus_DSI_NotSupported Transfer format not supported.
 */
status_t DSI_TransferNonBlocking(const MIPI_DSI_Type *base, dsi_handle_t *handle, dsi_transfer_t *xfer);

/*!
 * @brief Abort current APB data transfer.
 *
 * @param base MIPI DSI peripheral base address.
 * @param handle pointer to dsi_handle_t structure which stores the transfer state.
 */
void DSI_TransferAbort(const MIPI_DSI_Type *base, dsi_handle_t *handle);

/*!
 * @brief Interrupt handler for the DSI.
 *
 * @param base MIPI DSI peripheral base address.
 * @param handle pointer to dsi_handle_t structure which stores the transfer state.
 */
void DSI_TransferHandleIRQ(const MIPI_DSI_Type *base, dsi_handle_t *handle);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_MIPI_DSI_H_ */
