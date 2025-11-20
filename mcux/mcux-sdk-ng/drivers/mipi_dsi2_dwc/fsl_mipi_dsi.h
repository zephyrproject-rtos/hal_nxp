/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MIPI_DSI_H_
#define FSL_MIPI_DSI_H_

#include "fsl_common.h"

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

/*! @brief Error codes for the MIPI DSI driver. */
enum
{
    kStatus_DSI_Busy = MAKE_STATUS(kStatusGroup_MIPI_DSI, 0), /*!< DSI is busy. */
    kStatus_DSI_EccMultiBitError =
        MAKE_STATUS(kStatusGroup_MIPI_DSI, 1),                /*!< Multibit ECC error detected in rx packet. */
    kStatus_DSI_CrcError            = MAKE_STATUS(kStatusGroup_MIPI_DSI, 2), /*!< CRC error detected in rx packet. */
    kStatus_DSI_PacketSizeError     = MAKE_STATUS(kStatusGroup_MIPI_DSI, 3), /*!< Rx packet size error. */
    kStatus_DSI_ErrorReportReceived = MAKE_STATUS(kStatusGroup_MIPI_DSI, 4), /*!< Error report package received. */
    kStatus_DSI_NotSupported        = MAKE_STATUS(kStatusGroup_MIPI_DSI, 5), /*!< The transfer type not supported. */
    kStatus_DSI_PhyError            = MAKE_STATUS(kStatusGroup_MIPI_DSI, 6), /*!< Physical layer error. */
};

/* Interrupt related definitions */
/*! @brief Status and interrupt mask of acknowledge error sent by device caused by host, belongs to ack interrupt group.
 * INT_INT_ST_ACK bit0-bit15 */
enum
{
    kDSI_ErrorAckReportSot     = (1UL << 0U), /*!< ERR_ACK_RPT_0: SoT error. Clears to 0 after read. */
    kDSI_ErrorAckReportSotSync = (1UL << 1U), /*!< ERR_ACK_RPT_1: SoT Sync error. Clears to 0 after read. */
    kDSI_ErrorAckReportEotSync = (1UL << 2U), /*!< ERR_ACK_RPT_2: EoT Sync error. Clears to 0 after read. */
    kDSI_ErrorAckReportEscapeEntryCmd =
        (1UL << 3U), /*!< ERR_ACK_RPT_3: Escape Mode Entry Command error. Clears to 0 after read. */
    kDSI_ErrorAckReportLpTxSync =
        (1UL << 4U), /*!< ERR_ACK_RPT_4: Low-Power Transmit Sync error. Clears to 0 after read. */
    kDSI_ErrorAckReportPeripheralTimeout =
        (1UL << 5U), /*!< ERR_ACK_RPT_5: Peripheral Timeout error. Clears to 0 after read. */
    kDSI_ErrorAckReportFalseControl = (1UL << 6U), /*!< ERR_ACK_RPT_6: False Control error. Clears to 0 after read. */
    kDSI_ErrorAckReportContention =
        (1UL << 7U),  /*!< ERR_ACK_RPT_7: Contention Detected error. Clears to 0 after read. */
    kDSI_ErrorReportEccOneBit =
        (1UL << 8U),  /*!< ERR_ACK_RPT_8: ECC/SSDC/Checksum single-bit error (corrected). Clears to 0 after read. */
    kDSI_ErrorReportEccMultiBit =
        (1UL << 9U),  /*!< ERR_ACK_RPT_9: ECC/SSDC/Checksum multi-bit error (uncorrected). Clears to 0 after read. */
    kDSI_ErrorAckReportChecksum =
        (1UL << 10U), /*!< ERR_ACK_RPT_10: Payload Checksum error (long packet only). Clears to 0 after read. */
    kDSI_ErrorAckReportDataTypeInvalid =
        (1UL << 11U), /*!< ERR_ACK_RPT_11: Data Type not recognized. Clears to 0 after read. */
    kDSI_ErrorAckReportVcIdInvalid =
        (1UL << 12U), /*!< ERR_ACK_RPT_12: Virtual Channel ID invalid. Clears to 0 after read. */
    kDSI_ErrorAckReportTxLengthInvalid =
        (1UL << 13U), /*!< ERR_ACK_RPT_13: Invalid Transmission Length. Clears to 0 after read. */
    kDSI_ErrorAckReportDeviceSpecific =
        (1UL << 14U), /*!< ERR_ACK_RPT_14: Reserved device-specific error. Clears to 0 after read. */
    kDSI_ErrorAckReportProtocolViolation =
        (1UL << 15U), /*!< ERR_ACK_RPT_15: Protocol Violation error. Clears to 0 after read. */

    kDSI_ErrorAckReportAll = kDSI_ErrorAckReportSot | kDSI_ErrorAckReportSotSync | kDSI_ErrorAckReportEotSync |
                             kDSI_ErrorAckReportEscapeEntryCmd | kDSI_ErrorAckReportLpTxSync |
                             kDSI_ErrorAckReportPeripheralTimeout | kDSI_ErrorAckReportFalseControl |
                             kDSI_ErrorAckReportContention | kDSI_ErrorReportEccOneBit | kDSI_ErrorReportEccMultiBit |
                             kDSI_ErrorAckReportChecksum | kDSI_ErrorAckReportDataTypeInvalid |
                             kDSI_ErrorAckReportVcIdInvalid | kDSI_ErrorAckReportTxLengthInvalid |
                             kDSI_ErrorAckReportDeviceSpecific | kDSI_ErrorAckReportProtocolViolation,
};

/*! @brief Status and interrupt error in phy layer, belongs to phy interrupt group. INT_ST_PHY bit0-bit4 */
enum
{
    kDSI_PhyErrorEscEntry      = (1UL << 0U), /*!< Escape entry error from Lane 0. */
    kDSI_PhyErrorLpSync        = (1UL << 1U), /*!< Low-power data transmission synchronization error from Lane 0. */
    kDSI_PhyErrorControl       = (1UL << 2U), /*!< Control error from Lane 0. */
    kDSI_PhyErrorLp0Connection = (1UL << 3U), /*!< LP0 connection error from Lane 0. */
    kDSI_PhyErrorLp1Connection = (1UL << 4U), /*!< LP1 connection error from Lane 0. */

    kDSI_PhyErrorAll = kDSI_PhyErrorEscEntry | kDSI_PhyErrorLpSync | kDSI_PhyErrorControl | kDSI_PhyErrorLp0Connection |
                       kDSI_PhyErrorLp1Connection,
};

/*! @brief Timeout error interrupt and status, belongs to to(timeout) interrupt group. INT_ST_TO bit0-bit6 */
enum
{
    kDSI_TimeoutErrorHstx     = (1UL << 0U), /*!< High-speed TX timeout detected. */
    kDSI_TimeoutErrorHstxRdy  = (1UL << 1U), /*!< High-speed TX RDY timeout detected. */
    kDSI_TimeoutErrorLprx     = (1UL << 2U), /*!< Low-power RX timeout detected. */
    kDSI_TimeoutErrorLptxRdy  = (1UL << 3U), /*!< Low-power TX DATA timeout detected. */
    kDSI_TimeoutErrorLptxTrig = (1UL << 4U), /*!< Low-power TX TRIGGER timeout detected. */
    kDSI_TimeoutErrorLptxUlps = (1UL << 5U), /*!< Low-power TX ULPS timeout detected. */
    kDSI_TimeoutErrorBta      = (1UL << 6U), /*!< Bus turnaround direction timeout detected. */

    kDSI_TimeoutErrorAll = kDSI_TimeoutErrorHstx | kDSI_TimeoutErrorHstxRdy | kDSI_TimeoutErrorLprx |
                           kDSI_TimeoutErrorLptxRdy | kDSI_TimeoutErrorLptxTrig | kDSI_TimeoutErrorBta,
};

/*! @brief IPI error status, belongs to ipi interrupt group. INT_ST_IPI bit0-bit19 */
enum
{
    kDSI_IpiErrorDisplayCmdTime =
        (1UL << 0U), /*!< ERR_DISPLAY_CMD_TIME: Display command ignored due to timing. Clears to 0 after read. */
    kDSI_IpiErrorIpiDataType =
        (1UL
         << 1U), /*!< ERR_IPI_DTYPE: No matching DSI-2 data type for ipi_format/ipi_depth. Clears to 0 after read. */
    kDSI_IpiErrorVideoBandwidth =
        (1UL << 2U), /*!< ERR_VID_BANDWIDTH: Video packet exceeds HLINETIME bandwidth. Clears to 0 after read. */
    kDSI_IpiErrorIpiCmdDiscarded = (1UL << 3U), /*!< ERR_IPI_CMD: Display command discarded. Clears to 0 after read. */
    kDSI_IpiErrorDisplayCmdOverflow =
        (1UL
         << 8U), /*!< ERR_DISPLAY_CMD_OVFL: Display command ignored due to buffer overflow. Clears to 0 after read. */
    kDSI_IpiErrorEventFifoOverflow =
        (1UL << 16U), /*!< IPI_EVENT_FIFO_OVER: Write attempted when event FIFO is full. Clears to 0 after read. */
    kDSI_IpiErrorEventFifoUnderflow =
        (1UL << 17U), /*!< IPI_EVENT_FIFO_UNDER: Read attempted when event FIFO is empty. Clears to 0 after read. */
    kDSI_IpiErrorPixelFifoOverflow =
        (1UL << 18U), /*!< IPI_PIXEL_FIFO_OVER: Write attempted when pixel FIFO is full. Clears to 0 after read. */
    kDSI_IpiErrorPixelFifoUnderflow =
        (1UL << 19U), /*!< IPI_PIXEL_FIFO_UNDER: Read attempted when pixel FIFO is empty. Clears to 0 after read. */

    kDSI_IpiErrorAll = kDSI_IpiErrorDisplayCmdTime | kDSI_IpiErrorIpiDataType | kDSI_IpiErrorVideoBandwidth |
                       kDSI_IpiErrorIpiCmdDiscarded | kDSI_IpiErrorDisplayCmdOverflow | kDSI_IpiErrorEventFifoOverflow |
                       kDSI_IpiErrorEventFifoUnderflow | kDSI_IpiErrorPixelFifoOverflow |
                       kDSI_IpiErrorPixelFifoUnderflow,
};

/*! @brief PRI error status, belongs to pri interrupt group. INT_ST_PRI bit0-bit1 */
enum
{
    kDSI_PriErrortxtime = (1UL << 0U), /*!< ERR_PRI_TX_TIME: PRI request ignored due to timing error. */
    kDSI_PriErrortxcmd  = (1UL << 1U), /*!< ERR_PRI_TX_CMD: PRI request can not be attended and will be discarded. */

    kDSI_CtrlErrorAll = kDSI_PriErrortxtime | kDSI_PriErrortxcmd,
};

/*! @brief CRI error status, belongs to cri interrupt group. INT_ST_CRI bit0-bit12. */
enum
{
    kDSI_CriErrorCmdTime = (1UL << 0U), /*!< ERR_CRI_CMD_TIME: CRI request ignored due to timing error (Video Mode
                                           only). Clears to 0 after read. */
    kDSI_CriErrorInvalidDataType =
        (1UL << 1U), /*!< ERR_CRI_DTYPE: Invalid data type in CRI packet header. Clears to 0 after read. */
    kDSI_CriErrorInvalidVChannel =
        (1UL << 2U), /*!< ERR_CRI_VCHANNEL: Invalid virtual channel in CRI packet header. Clears to 0 after read. */
    kDSI_CriErrorRxLength =
        (1UL << 3U), /*!< ERR_CRI_RX_LENGTH: Invalid packet length received by CRI. Clears to 0 after read. */
    kDSI_CriErrorEccOneBit =
        (1UL << 4U), /*!< ERR_CRI_ECC: Single-bit ECC error in CRI packet header. Clears to 0 after read. */
    kDSI_CriErrorEccMultiBit =
        (1UL << 5U), /*!< ERR_CRI_ECC_FATAL: Multi-bit ECC error in CRI packet header. Clears to 0 after read. */
    kDSI_CriErrorCrc = (1UL << 6U), /*!< ERR_CRI_CRC: CRC error in CRI long packet payload. Clears to 0 after read. */

    kDSI_CriErrorCmdRdPayloadOver = (1UL << 16U),  /*!< CMD_RD_PLD_FIFO_OVER: Write attempted when Command Read Payload
                                                      FIFO is full. Clears to 0 after read. */
    kDSI_CriErrorCmdRdPayloadUnder = (1UL << 17U), /*!< CMD_RD_PLD_FIFO_UNDER: Read attempted when Command Read Payload
                                                      FIFO is empty. Clears to 0 after read. */
    kDSI_CriErrorCmdWrPayloadOver = (1UL << 18U),  /*!< CMD_WR_PLD_FIFO_OVER: Write attempted when Command Write Payload
                                                      FIFO is full. Clears to 0 after read. */
    kDSI_CriErrorCmdWrPayloadUnder = (1UL << 19U), /*!< CMD_WR_PLD_FIFO_UNDER: Read attempted when Command Write Payload
                                                      FIFO is empty. Clears to 0 after read. */
    kDSI_CriErrorCmdWrHeaderOver = (1UL << 20U),   /*!< CMD_WR_HDR_FIFO_OVER: Write attempted when Command Write Header
                                                      FIFO is full. Clears to 0 after read. */
    kDSI_CriErrorCmdWrHeaderUnder = (1UL << 21U),  /*!< CMD_WR_HDR_FIFO_UNDER: Read attempted when Command Write Header
                                                      FIFO is empty. Clears to 0 after read. */

    kDSI_CriErrorAll = kDSI_CriErrorCmdTime | kDSI_CriErrorInvalidDataType | kDSI_CriErrorInvalidVChannel |
                       kDSI_CriErrorRxLength | kDSI_CriErrorEccOneBit | kDSI_CriErrorEccMultiBit | kDSI_CriErrorCrc |
                       kDSI_CriErrorCmdRdPayloadOver | kDSI_CriErrorCmdRdPayloadUnder | kDSI_CriErrorCmdWrPayloadOver |
                       kDSI_CriErrorCmdWrPayloadUnder | kDSI_CriErrorCmdWrHeaderOver | kDSI_CriErrorCmdWrHeaderUnder,
};

/* General configuration. */
/*! @brief MIPI DSI dsi general config. */
enum
{
    kDSI_EnableEotpTxHs = (1U << 0U), /*!< Enables the EoTp transmission in high-speed. */
    kDSI_EnableBta      = (1U << 1U), /*!< Enables the Bus Turn-Around (BTA) request. */
    kDSI_EnableSSS      = (1U << 2U), /*!< Enables the C-PHY SendSync Symbols behavior. */
    kDSI_EnableAll      = kDSI_EnableEotpTxHs | kDSI_EnableBta | kDSI_EnableSSS,
    kDSI_DisableAll     = 0,
};

/*! @brief MIPI DSI operation mode. */
typedef enum _dsi_operation_mode
{
    kDSI_IdleMode       = 0U, /*!< Video mode. */
    kDSI_AutoMode       = 1U, /*!< AutoCalculaton mode. */
    kDSI_CommandMode    = 2U, /*!< Command mode. */
    kDSI_VideoMode      = 3U, /*!< Video mode. */
    kDSI_DataStreamMode = 4U, /*!< Data Stream mode. */
} dsi_operation_mode_t;

/*! @brief MIPI DSI fifo status. */
typedef enum _dsi_fifo_status
{
    kDSI_FifoEmpty       = 0U, /*!< Indicates that the selected FIFO is empty. */
    kDSI_FifoAlmostEmpty = 1U, /*!< Indicates that the selected FIFO is empty. */
    kDSI_FifoHalfFull    = 2U, /*!< Indicates that the selected FIFO is empty. */
    kDSI_FifoAlmostfFull = 3U, /*!< Indicates that the selected FIFO is empty. */
    kDSI_FifoFull        = 4U, /*!< Indicates that the selected FIFO is empty. */
} dsi_fifo_status_t;

/*! @brief MIPI DSI fifo select. */
typedef enum _dsi_fifo_select
{
    kDSI_FifoRxAllPayload = 0, /* Stores all the packets that are received from the DSI-2 device side. */
    kDSI_FifoWrHdrCommand = 1, /* Stores the packet headers for short and long packets, to be delivered in the
                                 Command mode. */
    kDSI_FifoWrPayload = 2,    /* Stores the payload to be delivered in the long packets, in the Command mode. */
    kDSI_FifoIpiPixel  = 3,    /* Stores all the IPI pixel data and all the ipi_data_en_X signals. */
    kDSI_FifoIpiEvent  = 4,    /* Stores all the rising and falling edge events of the IPI frame. */
    kDSI_FifoTxHs      = 5,    /* Stores the SendSync, valid bytes and payload bytes. */
    kDSI_FifoSysIpiCmd = 6,    /* Stores the IPI display commands through the ipi_shutdn, ipi_colorm,
                                 ipi_tear_req, and ipi_hibernate_req interface pins. */
    kDSI_FifoHsHdrBuffer = 7,  /* Stores the high-speed packet headers. */
    kDSI_FifoLpHeader    = 8,  /* Stores the low-power packet headers. */
    kDSI_FifoLpdtByte    = 9,  /* Stores the bytes to be transmitted in the low-power mode. */
    kDSI_FifoPriReq      = 10, /* Stores the valid PRI TX commands requested using the PRI_TX_CMD register. */

} dsi_fifo_select_t;

/*! @brief MIPI DSI manual mode. */
typedef enum _dsi_manual_mode
{
    kDSI_AutomaticallyMode,
    kDSI_ManualMode = 1,
} dsi_manual_mode_t;

/*! @brief DSI video mode. */
typedef enum _dsi_video_mode
{
    kDSI_IpiNonBurstWithSyncPulse = 0U, /*!< Non-Burst mode with Sync Pulses. */
    kDSI_IpiNonBurstWithSyncEvent = 1U, /*!< Non-Burst mode with Sync Events. */
    kDSI_IpiBurst                 = 2U, /*!< Burst mode. */
} dsi_video_mode_t;

/*! @brief DSI pixel format. */
typedef enum _dsi_pixel_format
{
    kDSI_Format_RGB888,
    kDSI_Format_RGB666,
    kDSI_Format_RGB666_PACKED,
    kDSI_Format_RGB565,
} dsi_pixel_format_t;

/*! @brief MIPI DSI controller configuration. */
typedef struct _dsi_config
{
    uint8_t dsivirtualchannel;
    dsi_operation_mode_t operatemode;
    dsi_video_mode_t videoMode;

    uint8_t packageFlags;
    uint16_t HsTxTimeout;
    uint16_t HsTxReadyTimeout;
    uint16_t lpRxTimeout;
    uint16_t lpTxDataReadyTimeout;
    uint16_t lpTxTriggerTimeout;
    uint16_t lpTxUlpsEntryTimeout;
    uint16_t BtaTimeout;

    dsi_fifo_select_t fifo;
    dsi_manual_mode_t manualmode;
} dsi_config_t;

/* IPI related definitions */
/*! @brief MIPI IPI interface color depth. */
typedef enum _dsi_ipi_color_depth
{
    kDSI_IPIDepth565bits = 2U,
    kDSI_IPIDepth6bits   = 3U,
    kDSI_IPIdepth8bits   = 5U,
    kDSI_IPIDepth10bits  = 6U,
    kDSI_IPIDepth12bits  = 7U,
    KDSI_IPIDepth16bits  = 9U,
} dsi_ipi_color_depth_t;

/*! @brief MIPI IPI interface color format. */
typedef enum _dsi_ipi_color_format
{
    kDSI_IPIRGB             = 0U,
    kDSI_IPIYCbCr422        = 1U,
    kDSI_IPIYCbCr420        = 3U,
    kDSI_IPIYCbCr422Loosely = 4U,
    kDSI_IPIRGBLoosely      = 5U,
    kDSI_IPIComporessedData = 8U,
} dsi_ipi_color_format_t;

/*! @brief MIPI IPI interface color setting. */
typedef struct _dsi_ipi_color_setting
{
    dsi_ipi_color_depth_t depth;
    dsi_ipi_color_format_t format;
} dsi_ipi_color_setting_t;

/*! @brief MIPI IPI video pattern. */
typedef enum _dsi_video_pattern
{
    kDSI_PatternDisable    = 0U, /*!< Color bar pattern mode disabled. */
    kDSI_PatternVertical   = 1U, /*!< Color bar pattern mode displayed vertically. */
    kDSI_PatternHorizontal = 2U, /*!< Color bar pattern mode displayed horizontally. */
} dsi_video_pattern_t;

/*! @brief MIPI IPI hibernate type. */
typedef enum _dsi_ipi_hib
{
    kDSI_IPIHibLP11 = 0U,
    kDSI_IPIHibULPS = 1U,
} dsi_ipi_hib_t;

/*! @brief MIPI IPI lane number. */
typedef enum _dsi_ipi_lanes
{
    kDSI_IPI4Lanes = 0U,
    kDSI_IPI1Lane  = 1U,
    kDSI_IPI2Lanes = 2U,
} dsi_ipi_lanes_t;

/*! @brief MIPI IPI mapping. */
typedef enum _dsi_ipi_mapping
{
    kDSI_IPIDefaltConfig = 0U,
    kDSI_IPIDpiConfig1   = 1U,
    kDSI_IPIDpiConfig2   = 2U,
    kDSI_IPIDpiConfig3   = 3U,
} dsi_ipi_mapping_t;

/*! @brief MIPI DSI controller IPI interface configuration. */
typedef struct _dsi_ipi_config
{
    dsi_ipi_color_setting_t ipiColor;

    uint16_t hsa;                  /*!< Horizontal sync width. */
    uint16_t hfp;                  /*!< Horizontal front porch width. */
    uint16_t hbp;                  /*!< Horizontal back porch. */
    uint16_t hactive;              /*!< Horizontal active area. */
    uint16_t hline;                /*!< Horizontal total line timing(HSA+HBP+HACT+HFP). */
    uint16_t vsa;                  /*!< vertical sync width. */
    uint16_t vbp;                  /*!< vertical back porch. */
    uint16_t vactive;              /*!< vertical active area. */
    uint16_t vfp;                  /*!< vertical front porch area. */

    uint16_t pixelPayloadSize;     /*!< Configures the number of pixels in a single video packet,
                                       used in Video mode (for non-burst modes) and Data Stream mode. For RGB-6bit color
                                      coding, this value must be a multiple of
                                       4. For RGB-10bit color coding, this value must be a multiple of 4. For RGB-12bit
                                      color coding, this value must be a multiple     of 2. For YCbCr color codings, this
                                      value     must be a multiple of 2. */
    uint16_t ipi_fifo_depth_value; /*!< IPI Pixel FIFO depth value */
    dsi_ipi_hib_t hibernateType;
    uint16_t dsi_ipi_hibtime;
    dsi_ipi_lanes_t dsi_ipi_lane;
    uint16_t dsi_ipi_fifodepth;
    dsi_ipi_mapping_t dsi_ipi_mapping;
    dsi_pixel_format_t dsi_fmt;
} dsi_ipi_config_t;

/*! @brief MIPI DSI phy mode. */
typedef enum _dsi_phy_mode
{
    kDSI_DPHY = 0U,
    kDSI_CPHY = 1U,
} dsi_phy_mode_t;

/*! @brief MIPI DSI phy ppi width. */
typedef enum _dsi_phy_ppiwidth
{
    kDSI_PPI8BITS  = 0U,
    kDSI_PPI816ITS = 1U,
    kDSI_PPI832ITS = 2U,
} dsi_phy_ppiwidth_t;

/*! @brief MIPI DSI phy lane mapping. */
typedef enum _dsi_phy_lane_mapping
{
    kDSI_LANE1_MAPPING = 1U,
    kDSI_LANE2_MAPPING = 2U,
    kDSI_LANE3_MAPPING = 3U,
} dsi_phy_lane_mapping_t;

/* PHY configuration */
/*! @brief MIPI DSI C/D-PHY configuration. */
typedef struct _dsi_phy_config
{
    dsi_phy_mode_t phymode;
    dsi_phy_ppiwidth_t ppiwidth;
    dsi_phy_lane_mapping_t lanemapping[3];

    bool enableNoncontinuousClk;
    uint8_t numLanes; /*!< Number of lanes. The value range is from 0-3, lane 1-4. PHY_IF_CFG[n_lanes] */

    uint32_t lp2hs_time;
    uint32_t hs2lp_time;
    uint32_t esccmd_time;
    uint32_t escbyte_time;
    uint16_t tolerance_time;
    uint16_t ulps_wakeuptime;
    uint16_t cal_time;
    uint8_t lptx_clkdiv;
} dsi_phy_config_t;

/* Transfer related structure */
/*! @brief DSI TX data type. */
typedef enum _dsi_tx_data_type
{
    kDSI_TxDataVsyncStart                   = 0x01U, /*!< V Sync start. */
    kDSI_TxDataVsyncEnd                     = 0x11U, /*!< V Sync end. */
    kDSI_TxDataHsyncStart                   = 0x21U, /*!< H Sync start. */
    kDSI_TxDataHsyncEnd                     = 0x31U, /*!< H Sync end. */
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
    kDSI_TxDataSetMaxReturnPktSize          = 0x37U, /*!< Set the Maximum Return Packet Size. */
    kDSI_TxDataNull                         = 0x09U, /*!< Null Packet, no data. */
    kDSI_TxDataBlanking                     = 0x19U, /*!< Blanking Packet, no data. */
    kDSI_TxDataGenLongWr                    = 0x29U, /*!< Generic long write. */
    kDSI_TxDataDcsLongWr                    = 0x39U, /*!< DCS Long Write/write_LUT Command Packet. */
    kDSI_TxDataLooselyPackedPixel20BitYCbCr = 0x0CU, /*!< Loosely Packed Pixel Stream, 20-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel24BitYCbCr        = 0x1CU, /*!< Packed Pixel Stream, 24-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel16BitYCbCr        = 0x2CU, /*!< Packed Pixel Stream, 16-bit YCbCr, 4:2:2 Format. */
    kDSI_TxDataPackedPixel30BitRGB          = 0x0DU, /*!< Packed Pixel Stream, 30-bit RGB, 10-10-10 Format. */
    kDSI_TxDataPackedPixel36BitRGB          = 0x1DU, /*!< Packed Pixel Stream, 36-bit RGB, 12-12-12 Format. */
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
} dsi_rx_data_type_t;

/*! @brief dsi_transfer_flags DSI transfer control flags. */
enum
{
    kDSI_TransferUseLowPower = (1U << 0U), /*!< Use low power or not. */
    kDSI_TransferPerformBTA  = (1U << 1U), /*!< Perform BTA or not at the end of a frame. */
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

/*! @brief Structure for the dsi csr pixel link format. */
typedef enum _dsi_csr_pixel_format
{
    kDSI_PixelFormatRGB24Bit   = 0U,
    kDSI_PixelFormatRGB30Bit   = 1U,
    kDSI_PixelFormatRGB18Bit   = 2U,
    kDSI_PixelFormatRGB16Bit   = 3U,
    kDSI_PixelFormatYcbcr20Bit = 4U,
    kDSI_PixelFormatYcbcr16Bit = 5U,
} dsi_csr_pixel_format_t;

/*! @brief Structure for the dphy pll config. */
typedef struct
{
    uint32_t m; /*!< PLL multiplier. */
    uint32_t n; /*!< PLL divider. */
    uint32_t p; /*!< Post divider. */
    uint8_t cpbias;
    uint16_t vcoctrl;
} dsi_dphypll_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif
/*!
 * @brief Convert IEEE 754 float value to the value could be written to registers.
 *
 * This function converts the float value to integer value to set the scaler parameters.
 *
 * @param floatValue The float value to convert.
 * @param intBits Bits number of integer part in result.
 * @param fracBits Bits number of fractional part in result.
 * @return The value to set to register.
 */
uint32_t MIPI_ConvertFloat(float floatValue, uint8_t intBits, uint8_t fracBits);

/*!
 * @brief Gets the MIPI DSI host controller instance from peripheral base address.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @return MIPI DSI instance.
 */
uint32_t DSI_GetInstance(DSI_V2_HOST_DSI_Type *base);

/*!
 * @name Controller initialization and de-initialization
 * @{
 */
/*!
 * @brief Initializes the MIPI DSI host with the user configuration.
 *
 * This function initializes the MIPI DSI host with the configuration, it should
 * be called before other MIPI DSI driver functions.
 *
 * @param main MIPI DSI main peripheral base address.
 * @param dsi  MIPI DSI dsi peripheral base address.
 * @param inter MIPI DSI int peripheral base address.
 * @param config Pointer to the dsi configuration structure.
 */
void DSI_Init(DSI_V2_HOST_MAIN_Type *main,
              DSI_V2_HOST_DSI_Type *dsi,
              DSI_V2_HOST_INT_Type *inter,
              const dsi_config_t *config);

/*!
 * @brief Deinitializes an MIPI DSI host.
 *
 * This function should be called after all bother MIPI DSI driver functions.
 *
 * @param base MIPI DSI main peripheral base address.
 */
void DSI_Deinit(DSI_V2_HOST_MAIN_Type *base);

/*!
 * @brief Gets the default configuration to initialize the MIPI DSI host.
 *
 * The default value is:
 * code
 * config->operatemode            = kDSI_CommandMode;
 * config->packageFlags           = kDSI_DisableAll;
 * config->HsTxTimeout            = 0U;
 * config->HsTxReadyTimeout       = 0U;
 * config->lpRxTimeout            = 0U;
 * config->lpTxDataReadyTimeout   = 0U;
 * config->lpTxTriggerTimeout     = 0U;
 * config->lpTxUlpsEntryTimeout   = 0U;
 * config->BtaTimeout             = 0U;
 * config->manualmode             = kDSI_ManualMode;
 * config->videoMode              = kDSI_IpiNonBurstWithSyncPulse;
 * endcode
 *
 * @param config Pointer to a user-defined configuration structure.
 */
void DSI_GetDefaultConfig(dsi_config_t *config);

/*!
 * @brief Configure the MIDPI DSI IPI interface.
 *
 * This function sets the IPI interface configuration, it should be used in
 * video mode.
 *
 * @param ipi MIPI DSI ipi peripheral base address.
 * @param config Pointer to the IPI configuration.
 *
 */
void DSI_SetIpiConfig(DSI_V2_HOST_IPI_Type *ipi, const dsi_ipi_config_t *config);

/*!
 * @brief Set the operation mode configuration.
 *
 * This function configures the operation mode for DSI.
 *
 * @param base MIPI DSI main peripheral base address.
 * @param dsi MIPI DSI dsi peripheral base address.
 * @param config Pointer to the DSI configuration structure.
 */
void DSI_SetOperateMode(DSI_V2_HOST_MAIN_Type *base, DSI_V2_HOST_DSI_Type *dsi, const dsi_config_t *config);

/*!
 * @brief Updates the Horizontal timing parameter cycles.
 *
 * @param ipi MIPI DSI ipi host peripheral base address.
 * @param config Pointer to the IPI interface configuration.
 * @param ratio Ratio of frequencies of IPI / SYS clock.
 */
void DSI_ConfigHorizontalParams(DSI_V2_HOST_IPI_Type *ipi, const dsi_ipi_config_t *config, float ratio);

/*!
 * @brief Set the MIPI DSI phy configuration.
 *
 * This function configures the phy register for DSI setting.
 *
 * @param dsi_phy MIPI DSI phy peripheral base address.
 * @param phyConfig Pointer to the DSI phy configuration structure.
 */
void DSI_SetPhyConfig(DSI_V2_HOST_PHY_Type *dsi_phy, const dsi_phy_config_t *phyConfig);

/*!
 * @brief Calculates the D-PHY PLL dividers to generate the desired output frequency.
 *
 * The phy byte clock frequency(byte count per second) is generated by multiplying the refClkFreq_Hz,
 * the formula is as follows, m & n is configured by mediamix control block.
 *
 * desiredOutFreq_Hz = refClkFreq_Hz * M / N / P.
 * Feedback Multiplication Ratio M: phy_m[11:0] /4 , phy_m[11:0] range from 256 to 900
 * Input Frequency Division Ratio N:phy_n[3:0] + 1, phy_n[3:0] range  0 ~ 15
 * Output Division Factor P:[1, 2, 4, 8, 16, 32]
 *
 * @param config Pointer to the DSI D-phy PLL config structure containing m, n, p.
 * @param refClkFreq_Hz The D-PHY input reference clock frequency (REF_CLK).
 * @param desiredOutFreq_Hz Desired PLL output frequency.
 * @return The actually output frequency using the returned dividers. If can not
 * find suitable dividers, return 0.
 */
uint32_t DSI_DphyGetPllDivider(dsi_dphypll_config_t *config, uint32_t refClkFreq_Hz, uint32_t desiredOutFreq_Hz);
/*!
 * @brief Power up the DSI
 *
 * @param base MIPI DSI main peripheral base address.
 * @param phy MIPI DSI phy peripheral base address.
 * @retval kStatus_Success Data transfer finished with no error.
 * @retval kStatus_Timeout Transfer failed because of timeout.
 */
status_t DSI_PowerUp(DSI_V2_HOST_MAIN_Type *base, DSI_V2_HOST_PHY_Type *phy);

/*!
 * @brief Power down the DSI
 *
 * @param base MIPI DSI main peripheral base address.
 */
static inline void DSI_PowerDown(DSI_V2_HOST_MAIN_Type *base)
{
    base->PWR_UP = 0UL;
}

/*! @} */

/*!
 * @name Interrupts and status
 * @{
 */
/*!
 * @brief Enable the interrupts.
 *
 * The interrupts to enable are passed in as OR'ed mask value of _dsi_interrupt.
 *
 * @param base MIPI DSI int peripheral base address.
 * @param intGroupphy Interrupts to disable in group phy.
 * @param intGroupto Interrupts to disable in group timeout.
 * @param intGroupack Interrupts to disable in group ack.
 * @param intGroupcri Interrupts to disable in group cri.
 */
static inline void DSI_EnableInterrupts(
    DSI_V2_HOST_INT_Type *base, uint32_t intGroupphy, uint32_t intGroupto, uint32_t intGroupack, uint32_t intGroupcri)
{
    base->INT_UNMASK_PHY |= intGroupphy;
    base->INT_UNMASK_TO |= intGroupto;
    base->INT_UNMASK_ACK |= intGroupack;
    base->INT_UNMASK_CRI |= intGroupcri;
}

/*!
 * @brief Disable the interrupts.
 *
 * The interrupts to disable are passed in as OR'ed mask value of _dsi_interrupt.
 *
 * @param base MIPI DSI int peripheral base address.
 * @param intGroupphy Interrupts to disable in group phy.
 * @param intGroupto Interrupts to disable in group timeout.
 * @param intGroupack Interrupts to disable in group ack.
 * @param intGroupcri Interrupts to disable in group cri.
 */
static inline void DSI_DisableInterrupts(
    DSI_V2_HOST_INT_Type *base, uint32_t intGroupphy, uint32_t intGroupto, uint32_t intGroupack, uint32_t intGroupcri)
{
    base->INT_UNMASK_PHY &= ~intGroupphy;
    base->INT_UNMASK_TO &= ~intGroupto;
    base->INT_UNMASK_ACK &= ~intGroupack;
    base->INT_UNMASK_CRI &= ~intGroupcri;
}

/*!
 * @brief Get and clear the interrupt status.
 *
 * @param base MIPI DSI int peripheral base address.
 * @param intGroupphy Interrupts to disable in group phy.
 * @param intGroupto Interrupts to disable in group timeout.
 * @param intGroupack Interrupts to disable in group ack.
 * @param intGroupcri Interrupts to disable in group cri.
 */
static inline void DSI_GetAndClearInterruptStatus(DSI_V2_HOST_INT_Type *base,
                                                  uint32_t *intGroupphy,
                                                  uint32_t *intGroupto,
                                                  uint32_t *intGroupack,
                                                  uint32_t *intGroupcri)
{
    *intGroupphy = base->INT_ST_PHY;
    *intGroupto  = base->INT_ST_TO;
    *intGroupack = base->INT_ST_ACK;
    *intGroupcri = base->INT_ST_CRI;
}
/*! @} */

/*! @} */

/*!
 * @name PHY
 * @{
 */

/*! @} */

/*!
 * @name Bus Operation
 * @{
 */

/*!
 * @brief Writes tx header to command FIFO. This will trigger the packet transfer.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param wordCount For long packet, this is the byte count of the payload.
 *                 For short packet, this is (data1 << 8) | data0.
 * @param virtualChannel Virtual channel.
 * @param dataType The packet data type, (DI).
 */
void DSI_WriteTxHeader(DSI_V2_HOST_DSI_Type *base,
                       uint16_t wordCount,
                       uint8_t virtualChannel,
                       dsi_tx_data_type_t dataType);

/*!
 * @brief Fills the long APB packet payload.
 *
 * Write the long packet payload to TX FIFO.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 */
void DSI_WriteTxPayload(DSI_V2_HOST_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize);

/*!
 * @brief Writes payload data to generic payload FIFO.
 *
 * Write the long packet payload to TX FIFO. This function could be used in two ways
 *
 * 1. Include the DCS command in the 1st byte of @p payload. In this case, the DCS command
 *    is the first byte of @p payload. The parameter @p sendDcsCmd is set to false,
 *    the @p dcsCmd is not used. This function is the same as @ref DSI_WriteTxPayload
 *    when used in this way.
 *
 * 2. The DCS command in not in @p payload, but specified by parameter @p dcsCmd.
 *    In this case, the parameter @p sendDcsCmd is set to true, the @p dcsCmd is the DCS
 *    command to send. The @p payload is sent after @p dcsCmd.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload.
 * @param payloadSize Payload size in byte.
 * @param sendDcsCmd If set to true, the DCS command is specified by @p dcsCmd,
 *       otherwise the DCS command is included in the @p payload.
 * @param dcsCmd The DCS command to send, only used when @p sendDCSCmd is true.
 */
void DSI_WriteTxPayloadExt(
    DSI_V2_HOST_DSI_Type *base, const uint8_t *payload, uint16_t payloadSize, bool sendDcsCmd, uint8_t dcsCmd);

/*!
 * @brief Reads the long APB packet payload.
 *
 * Read the long packet payload from RX FIFO. This function reads directly from
 * RX FIFO status. Upper layer should make sure the whole rx packet has been received.
 *
 * @param base MIPI DSI dsi peripheral base address.
 * @param payload Pointer to the payload buffer.
 * @param payloadSize Payload size in byte.
 */
void DSI_ReadRxData(DSI_V2_HOST_DSI_Type *base, uint8_t *payload, uint16_t payloadSize);
/*! @} */

/*!
 * @name Transactional
 * @{
 */

/*
 * @brief APB data transfer using blocking method.
 *
 * Perform APB data transfer using blocking method. This function waits until all
 * data send or received, or timeout happens.
 *
 * @param base MIPI DSI main peripheral base address.
 * @param dsi MIPI DSI dsi peripheral base address.
 * @param inter MIPI DSI int peripheral base address.
 * @param xfer Pointer to the transfer structure.
 * @retval kStatus_Success Data transfer finished with no error.
 * @retval kStatus_Timeout Transfer failed because of timeout.
 * @retval kStatus_DSI_RxDataError RX data error, user could use ref DSI_GetRxErrorStatus
 *        to check the error details.
 * @retval kStatus_DSI_PhyError PHY error detected during transfer.
 * @retval kStatus_DSI_ErrorReportReceived Error Report packet received, user could use
 *        ref DSI_GetAndClearHostStatus to check the error report status.
 * @retval kStatus_DSI_NotSupported Transfer format not supported.
 * @retval kStatus_Fail Transfer failed for other reasons.
 */
status_t DSI_TransferBlocking(DSI_V2_HOST_MAIN_Type *base,
                              DSI_V2_HOST_DSI_Type *dsi,
                              DSI_V2_HOST_INT_Type *inter,
                              dsi_transfer_t *xfer);
/*!
 * @brief Lookup table method to obtain HS frequency range of operation selection override.
 *
 * @param bnd_width band width frequncy in Hz
 * @return the hsfreqrange_ovr[6:0] value based on band width frequncy in hz.
 */
uint16_t Pll_Set_Hs_Freqrange(uint32_t bnd_width);

/*!
 * @brief Lookup table method to obtain VCO parameter.
 *
 * @param pll_freq_sel PLL frequency in Mhz.
 * @return the pll_vco_cntrl[5:0] value based on video Pll frequency in Mhz.
 */
void Pll_Set_Pll_Vco_Param(uint32_t pll_freq_sel, dsi_dphypll_config_t *config);

/*!
 * @brief config to set Dphy.
 *
 * @param phyRefClkFreq_Hz Dphy reference clock frequency in Hz.
 * @param dataRateFreq_Hz line rate clock frequency.
 * @param config Pointer to dsi ipi configuration structure.
 */
void DSI_ConfigDphy(DISPLAY_DSI_CSR_Type *base,
                    uint32_t phyRefClkFreq_Hz,
                    uint32_t dataRateFreq_Hz,
                    const dsi_ipi_config_t *config);
/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_MIPI_DSI_H_ */
