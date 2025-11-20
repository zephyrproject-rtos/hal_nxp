/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DCIF_H_
#define FSL_DCIF_H_

#include "fsl_common.h"

/*!
 * @addtogroup dcif
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_DCIF_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Max loops to wait for DBI command complete
 */
#ifndef DCIF_DBI_CMD_TIMEOUT
    #ifdef CONFIG_DCIF_DBI_CMD_TIMEOUT
        #define DCIF_DBI_CMD_TIMEOUT CONFIG_DCIF_DBI_CMD_TIMEOUT
    #else
        #define DCIF_DBI_CMD_TIMEOUT 0U
    #endif
#endif

/*! @brief The frame buffer and stide must be 16 byte aligned. */
#define DCIF_FB_ALIGN 16U

/*! @brief DCIF color space conversion mode. */
typedef enum _dcif_csc_mode
{
    kDCIF_CscDisable   = 0U, /*!< Disable the CSC. */
    kDCIF_CscYUV2RGB   = 1U, /*!< YUV to RGB. */
    kDCIF_CscYCbCr2RGB = 3U, /*!< YCbCr to RGB. */
} dcif_csc_mode_t;

/*! @brief DCIF interrupts and status flags. */
enum _dcif_interrupt
{
    kDCIF_InterruptVsync = DCIF_IS0_D0_VSYNC_MASK, /*!< Indicate that the vertical synchronization phase. */
    kDCIF_InterruptOutputUnderflow = DCIF_IS0_D0_UNDERRUN_MASK, /*!< Output buffer underflow. */
    kDCIF_InterruptVbp = DCIF_IS0_D0_VS_BLANK_MASK, /*!< Indicate vertical blanking period. */
    kDCIF_InterruptPdiOverflow = DCIF_IS0_D0_PDI_OVERRUN_MASK, /*!< PDI buffer overflow condition. */
    kDCIF_InterruptPdiVsyncTimeout = DCIF_IS0_D0_PDI_TIMEOUT_MASK, /*!< PDI VSYNC detection timeout. */
    kDCIF_InterruptDbiCommandDone = DCIF_IS0_D0_DBI_DONE_MASK, /*!< DBI command finish. */
    kDCIF_InterruptTxPacketDone = DCIF_IS0_D0_TXPKTIF_DONE_MASK, /*!< TX packet interface command finish. */
    kDCIF_InterruptTxPacketTimeout = DCIF_IS0_D0_TXPKTIF_TIMEOUT_MASK, /*!< TX packet interface command execution timeout. */
};

/*! @brief DCIF interrupts and status flags for each layer. */
enum _dcif_layer_interrupt
{
    kDCIF_InterruptLayerFifoPanic = DCIF_IS1_D0_FIFO_PANIC0_MASK, /*!< Layer FIFO is panic when the pixel blending. */
    kDCIF_InterruptLayerFetchError = DCIF_IE1_D0_DMA_ERR_EN0_MASK, /*!< Layer has read error on AXI interface. */
    kDCIF_InterruptLayerFetchDone = DCIF_IE1_D0_DMA_DONE_EN0_MASK, /*!< Layer has fetched the last pixel from memory. */
    kDCIF_InterruptLayerFifoUnderflow = DCIF_IE1_D0_FIFO_EMPTY_EN0_MASK, /*!< Layer FIFO in the pixel blending underflowed. */
};

/*! @brief DCIF gamma correction table access mask. */
enum _dcif_gamma_access
{
    kDCIF_GammaAccessBluetable = DCIF_GC_CTRL_GC_B_MASK_MASK, /*!< Enable write/read access to gamma correction blue table. */
    kDCIF_GammaAccessGreentable = DCIF_GC_CTRL_GC_G_MASK_MASK, /*!< Enable write/read access to gamma correction green table. */
    kDCIF_GammaAccessRedtable = DCIF_GC_CTRL_GC_R_MASK_MASK, /*!< Enable write/read access to gamma correction red table. */
};

/*! @brief DCIF CLUTs. */
typedef enum _dcif_clut
{
    kDCIF_Clut0 = 0U, /*!< CLUT 0. */
    kDCIF_Clut1 = 1U, /*!< CLUT 1. */
} dcif_clut_t;

/*! @brief DCIF CLUT configuration. */
typedef struct _dcif_clut_config
{
    dcif_clut_t clutAccess; /*!< Choose which CLUT is accessed by APB write. */
    uint8_t clut0Layer; /*!< Choose layer CLUT0 is used for. */
    uint8_t clut1Layer; /*!< Choose layer CLUT1 is used for. */
} dcif_clut_config_t;

/*! @brief DCIF PDI input pixel format. */
typedef enum _dcif_pdi_format
{
    kDCIF_PdiRGB888 = 0U, /*!< 24bps RGB888. */
    kDCIF_PdiRGB666 = 1U, /*!< 18bps RGB666. XXXXXXRR_RRRRGGGG_GGBBBBBB. */
    kDCIF_PdiRGB565 = 2U, /*!< 16bps RGB565. RRRRRGGG_GGGBBBBB. */
    kDCIF_PdiRGB444 = 3U, /*!< 12bps RGB444. XXXXRRRR_GGGGBBBB. */
    kDCIF_PdiRGB555 = 4U, /*!< 15bps RGB555. XRRRRRGG_GGGBBBBB. */
    kDCIF_PdiYCbCr422 = 5U, /*!< 24bps YCbCr422. */
} dcif_pdi_format_t;

/*! @brief DCIF PDI input layer select. */
typedef enum _dcif_pdi_layer_select
{
    kDCIF_PdiLayer0 = 0U, /*!< Select layer 0 for PDI input. */
    kDCIF_PdiLayer1 = 1U, /*!< Select layer 1 for PDI input. */
} dcif_pdi_layer_select_t;

/*!
 * @brief DCIF PDI signal polarity flags
 */
enum _dcif_pdi_polarity_flags
{
    kDCIF_PdiVsyncActiveLow            = DCIF_PDI_CTRL_PDI_VSYNC_POL_MASK, /*!< VSYNC active low. */
    kDCIF_PdiDataEnableActiveLow       = DCIF_PDI_CTRL_PDI_DE_POL_MASK,    /*!< Data enable line active low. */
    kDCIF_PdiDriveDataOnFallingClkEdge = DCIF_PDI_CTRL_PDI_PCLK_EDGE_MASK, /*!< Pixel data is launched on the PCLK falling edge. */
};

/*! @brief PDI(parallel data input) configuration. */
typedef struct _dcif_pdi_config
{
    bool enable; /*!< Enable PDI. */
    bool skipFirstFrame; /*!< Enable to skip the first frame when the VBP of CSI input is less thancv the DPI output. */
    bool vsyncControl; /*!< Use the vsyncDelay_pclk to control DPI vsync signal directly. */
    uint32_t vsyncDelay_pclk; /*!< The delay count of pixel clock cycles from PDI vsync signal to DPI vsync signal. */
    uint32_t vsyncTimeout_hsync; /*!< The timeout count of hsync cycles to detect PDI vsync signal. Set to 0 to disable. */
    uint8_t polarityFlags;       /*!< OR'ed value of @ref _dcif_pdi_polarity_flags, used to contol the signal polarity. */
    dcif_pdi_format_t format; /*!< PDI input pixel format. */
    dcif_pdi_layer_select_t layer;  /*!< Which layer to use the PDI input. */
} dcif_pdi_config_t;

/*! @brief DCIF FBD input pixel format. */
typedef enum _dcif_fbd_format
{
    kDCIF_FbdRGBA16 = 0xAU, /*!< 16bps RGBA. */
    kDCIF_FbdRGB12 = 0xBU, /*!< 12bps RGB. */
    kDCIF_FbdRGBA13 = 0xCU, /*!< 13bps RGBA. */
    kDCIF_FbdRGB10 = 0xDU, /*!< 10bps RGB. */
    kDCIF_FbdRGBA11 = 0xEU, /*!< 11bps RGBA. */
    kDCIF_FbdRGB8 = 0xFU, /*!< 8bps RGB. */
} dcif_fbd_format_t;

/*! @brief DCIF FBD input layer select. */
typedef enum _dcif_fbd_layer_select
{
    kDCIF_FbdLayer0 = 0U, /*!< Select layer 0 for FBD input. */
    kDCIF_FbdLayer1 = 1U, /*!< Select layer 1 for FBD input. */
} dcif_fbd_layer_select_t;

/*! @brief FBD(frame buffer decompression) configuration. */
typedef struct _dcif_fbd_config
{
    bool enable; /*!< Enable FBD. */
    dcif_fbd_format_t format; /*!< FBD input pixel format. */
    dcif_fbd_layer_select_t layer;  /*!< Which layer to use the FBD input. */
} dcif_fbd_config_t;

/*!
 * @brief DCIF DPI signal polarity flags
 */
enum _dcif_dpi_polarity_flags
{
    kDCIF_DpiHsyncActiveHigh           = 0U, /*!< HSYNC active high. */
    kDCIF_DpiHsyncActiveLow            = DCIF_DPI_CTRL_HSYNC_POL_MASK, /*!< HSYNC active low. */
    kDCIF_DpiVsyncActiveHigh           = 0U, /*!< VSYNC active high. */
    kDCIF_DpiVsyncActiveLow            = DCIF_DPI_CTRL_VSYNC_POL_MASK, /*!< VSYNC active low. */
    kDCIF_DpiDataEnableActiveHigh      = 0U, /*!< Data enable line active high. */
    kDCIF_DpiDataEnableActiveLow       = DCIF_DPI_CTRL_DE_POL_MASK,    /*!< Data enable line active low. */
    kDCIF_DpiDriveDataOnRisingClkEdge  = 0U, /*!< Pixel data is launched on the PCLK rising edge. */
    kDCIF_DpiDriveDataOnFallingClkEdge = DCIF_DPI_CTRL_PCLK_EDGE_MASK, /*!< Pixel data is launched on the PCLK falling edge. */
    kDCIF_DpiPixelDataInvert           = DCIF_DPI_CTRL_DATA_INV_MASK,  /*!< Invert each bit of output pixel data. */
};

/*! @brief DCIF DPI display mode. */
typedef enum _dcif_dpi_display_mode
{
    kDCIF_DpiNormal = 0U,        /*!< Normal display mode. */
    kDCIF_DpiTestBackground,     /*!< Display background color only. */
    kDCIF_DpiTestColorBarColumn, /*!< Display color bar column test pattern. */
    kDCIF_DpiTestColorBarRow,    /*!< Display color bar row test pattern. */
} dcif_dpi_display_mode_t;

/*! @brief When to fetch/fill the async tx FIFO. */
typedef enum _dcif_dpi_fifo_option
{
    kDCIF_DpiVfpBegin = 0U, /*!< Fetch/fill starts as soon as vfp begins. */
    kDCIF_DpiVswBegin,      /*!< Fetch/fill starts as soon as vsw begins. */
    kDCIF_DpiVbpBegin,      /*!< Fetch/fill starts as soon as vbp begins. */
    kDCIF_DpiVbpEnd,        /*!< Fetch/fill starts as soon as vbp ends. */
} dcif_dpi_fifo_option_t;

/*! @brief DCIF DPI output format. */
typedef enum _dcif_dpi_output_format
{
    kDCIF_DpiRGB888 = 0U, /*!< 24-bit. */
    kDCIF_DpiRBG888 = 1U, /*!< 24-bit. */
    kDCIF_DpiGBR888 = 2U, /*!< 24-bit. */
    kDCIF_DpiGRB888 = 3U, /*!< 24-bit. */
    kDCIF_DpiBRG888 = 4U, /*!< 24-bit. */
    kDCIF_DpiBGR888 = 5U, /*!< 24-bit. */
    kDCIF_DpiRGB555 = 6U, /*!< 15-bit. XRRRRRGG_GGGBBBBB. */
    kDCIF_DpiRGB565 = 7U, /*!< 16-bit configuration 1. RRRRRGGG_GGGBBBBB. */
    kDCIF_DpiRGB666 = 8U, /*!< 18-bit. XXXXXXRR_RRRRGGGG_GGBBBBBB. */
} dcif_dpi_output_format_t;

/*! @brief Configuration for DCIF module to work in DPI mode. */
typedef struct _dcif_dpi_config
{
    uint8_t hsw;                  /*!< HSYNC pulse width. */
    uint8_t hfp;                  /*!< Horizontal front porch. */
    uint8_t hbp;                  /*!< Horizontal back porch. */
    uint8_t vsw;                  /*!< VSYNC pulse width. */
    uint8_t vfp;                  /*!< Vrtical front porch. */
    uint8_t vbp;                  /*!< Vertical back porch. */
    uint8_t polarityFlags;        /*!< OR'ed value of @ref _dcif_dpi_polarity_flags, used to contol the signal polarity. */
    dcif_dpi_output_format_t format; /*!< DPI output format. */
    dcif_dpi_display_mode_t displayMode; /*!< DPI display mode. */
    dcif_dpi_fifo_option_t frameFetch; /*!< When to start fetching for new frame. Also decide the shadow registers load and async tx fifo clear time. */
    dcif_dpi_fifo_option_t txFifoFill;  /*!< When to start fill async tx FIFO. */
    bool enableBackground; /*!< Enable background to display when all layers are disabled in normal display mode. */
} dcif_dpi_config_t;

/*! @brief DCIF DBI output format. */
typedef enum _dcif_dbi_out_format
{
    /*! 8-bit data bus width, pixel RGB332. For type A or B. 1 pixel sent in 1 cycle. */
    kDCIF_DbiOutD8RGB332 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(0),
    /*! 16-bit data bus width, pixel RGB332. For type A or B. 2 pixels sent in 1 cycle. */
    kDCIF_DbiOutD16RGB332 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(1),
    /*! 8-bit data bus width, pixel RGB444. For type A or B. 2 pixels sent in 3 cycles. */
    kDCIF_DbiOutD8RGB444 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(2),
    /*! 16-bit data bus width, pixel RGB444. For type A or B. 1 pixel sent in 1 cycle, data bus 4 MSB not used. */
    kDCIF_DbiOutD16RGB444 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(3),
    /*! 8-bit data bus width, pixel RGB565. For type A or B. 1 pixel sent in 2 cycles. */
    kDCIF_DbiOutD8RGB565 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(4),
    /*! 16-bit data bus width, pixel RGB565. For type A or B. 1 pixel sent in 1 cycle. */
    kDCIF_DbiOutD16RGB565 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(5),
    /*! 8-bit data bus width, pixel RGB666. For type A or B. 1 pixel sent in 3 cycles, data bus 2 LSB not used. */
    kDCIF_DbiOutD8RGB666 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(6),
    /*! 9-bit data bus width, pixel RGB666. For type A or B. 1 pixel sent in 2 cycles. */
    kDCIF_DbiOutD9RGB666 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(7),
    /*! 16-bit data bus width, pixel RGB666. For type A or B. 2 pixels sent in 3 cycles. */
    kDCIF_DbiOutD16RGB666Option1 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(8),
    /*! 16-bit data bus width, pixel RGB666. For type A or B. 1 pixel sent in 2 cycles. */
    kDCIF_DbiOutD16RGB666Option2 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(9),
    /*! 8-bit data bus width, pixel RGB888. For type A or B. 1 pixel sent in 3 cycles. */
    kDCIF_DbiOutD8RGB888 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(10),
    /*! 16-bit data bus width, pixel RGB888. For type A or B. 2 pixels sent in 3 cycles. */
    kDCIF_DbiOutD16RGB888Option1 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(11),
    /*! 16-bit data bus width, pixel RGB888. For type A or B. 1 pixel sent in 2 cycles. */
    kDCIF_DbiOutD16RGB888Option2 = DCIF_DBI_CTRL_DBI_DATA_PATTERN(12),
} dcif_dbi_out_format_t;

/*! @brief DCIF DBI type. */
typedef enum _dcif_dbi_type
{
    kDCIF_DbiTypeA_ClockedE = 0U, /*!< Selects DBI Type A Clocked E mode, 68000, Motorola mode. */
    kDCIF_DbiTypeA_FixedE   = 1U, /*!< Selects DBI type A fixed E mode, 68000, Motorola mode. */
    kDCIF_DbiTypeB          = 2U, /*!< Selects DBI type B, 8080, Intel mode. */
} dcif_dbi_type_t;

/*! @brief DCIF DBI command type. */
typedef enum _dcif_dbi_cmd_type
{
    kDCIF_DbiCmdReadParam = 0U, /*!< Start read parameter. */
    kDCIF_DbiCmdWriteCommand,   /*!< Send address (or command). */
    kDCIF_DbiCmdWriteParam,     /*!< Send data(parameter). */
    kDCIF_DbiCmdWritePixel,     /*!< Start write memory(pixel data) */
} dcif_dbi_cmd_type_t;

/*!
 * @brief DCIF DBI signal flags
 */
enum _dcif_dbi_signal_flags
{
    kDCIF_DbiTeEnable = DCIF_DBI_CTRL_DBI_TE_SYNC_MASK,   /*!< Enable TE signal. */
    kDCIF_DbiCsxLow   = DCIF_DBI_CTRL_DBI_CSX_FORCE_MASK, /*!< Force CSX signal to be low. */
};

/*! @brief Configuration for DCIF module to work in DBI mode. */
typedef struct _dcif_dbi_config
{
    dcif_dbi_out_format_t format; /*!< Output format. */
    dcif_dbi_type_t type;         /*!< DBI type. */
    uint8_t signalFlags;          /*!< Signal flags. See @ref _dcif_dbi_signal_flags. */
    uint8_t rdHigh;               /*!< RDX signal high time in clock cycles. */
    uint8_t rdLow;                /*!< RDX signal low time in clock cycles. */
    uint8_t wrHigh;               /*!< WRX signal high time in clock cycles. */
    uint8_t wrLow;                /*!< WRX signal low time in clock cycles. */
    uint8_t csSetup;              /*!< CSX setup time in clock cycles. */
    uint8_t csHold;               /*!< CSX hold time in clock cycles. */
} dcif_dbi_config_t;

/*! @brief DCIF DCS packet output format. */
typedef enum _dcif_dcs_pkt_out_format
{
    kDCIF_DcsPktOutRGB565Ls = DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN(0), /*! RGB565, LS byte first. */
    kDCIF_DcsPktOutRGB565Ms = DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN(1), /*! RGB565, MS byte first. */
    kDCIF_DcsPktOutBGR565Ls = DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN(2), /*! BGR565, LS byte first. */
    kDCIF_DcsPktOutBGR565Ms = DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN(3), /*! BGR565, MS byte first. */
} dcif_dcs_pkt_out_format_t;

/*! @brief DCIF DCS packet command type. */
typedef enum _dcif_dcs_pkt_cmd_type
{
    kDCIF_DcsPktCmdWritePixel = 0U,      /*!< DCS command write pixel start/continue. */
    kDCIF_DcsPktCmdSetColWritePixel,     /*!< DCS command set column address, then write pixel start/continue. */
    kDCIF_DcsPktCmdSetPageWritePixel,    /*!< DCS command set page address, then write pixel start/continue. */
    kDCIF_DcsPktCmdSetColPageWritePixel, /*!< DCS command set column and page address, then write pixel start/continue */
} dcif_dcs_pkt_cmd_type_t;

/*! @brief DCIF module DCS packet mode configuration. */
typedef struct _dcif_dcs_pkt_config
{
    uint32_t : 4U; /*!< Reserved. */
    uint32_t virtualChannel : 2U; /*!< Virtual channel number. */
    uint32_t useHighSpeed : 1U; /*!< Interface transfer mode. Enable to use high speed, disable to use low power. */
    uint32_t enableTe : 1U; /*!< Enable TE signal. */
    uint32_t format : 3U; /*!< Output data format. See @ref dcif_dcs_pkt_out_format_t. */
    uint32_t : 4U; /*!< Reserved. */
    /*!< Set pkt_tx_cmd_req to deasserts after receiving command request and re-asserts after request completes.
         otherwise the pkt_tx_cmd_req asserts until all command requests are sent. */
    uint32_t cmdReqWait : 1U;
    /*!< The DCS command and pixel byte count for each packet. If the toltal count exceeds the payloadByteCnt,
         then the payload will be split into n packets, payloadByteCnt bytes each packet except for the last one. */
    uint32_t payloadByteCnt : 16U;
    uint32_t fifoSendLevel : 7U; /*!< The DCS command and data are sent until this amount of data is filled into the async Tx FIFO. */
    uint32_t timeout : 13U; /*!< Timeout wait count for command execution. The counter adds 1 each 65536 AXI clock cycle. Set to 0 to disable timeout. */
} dcif_dcs_pkt_config_t;

/*! @brief Lyer alpha blend factor mode. */
typedef enum _dcif_layer_alpha_factor_mode
{
    kDCIF_AlphaFactorOne      = 0, /*!< Use 1 as the blending factor. */
    kDCIF_AlphaFactorZero     = 1, /*!< Use 0 as the blending factor. */
    kDCIF_AlphaFactorStraight = 2, /*!< Use the modified alpha component(As'' for source layer or Ad'' for destination
                                       layer) as the blending factor. */
    kDCIF_AlphaFactorInversed = 3, /*!< Use the inversed alpha component(1-As'' for source layer or 1-Ad'' for
                                       destination layer) as the blending factor. */
} dcif_layer_alpha_factor_mode_t;

/*! @brief Layer global alpha mode for alpha blend. */
typedef enum _dcif_layer_global_alpha_mode
{
    kDCIF_AlphaGlobal = 0U, /*!< Use the global alpha instead. */
    kDCIF_AlphaLocal,       /*!< Use the alpha(or inversed alpha) component directly. */
    kDCIF_AlphaScaled,      /*!< Multiply the alpha(or inversed alpha) component by the global alpha. */
} dcif_layer_global_alpha_mode_t;

/*! @brief Layer alpha blend alpha component mode. */
typedef enum _dcif_layer_alpha_mode
{
    kDCIF_AlphaStraight = 0U, /*!< Use straight alpha, s0_alpha' = s0_alpha. */
    kDCIF_AlphaInversed       /*!< Use inversed alpha, s0_alpha' = 0xFF - s0_alpha. */
} dcif_layer_alpha_mode_t;

/*! @brief Layer alpha blend color mode. */
typedef enum _dcif_layer_alpha_color_mode
{
    kDCIF_AlphaColorNoAlpha   = 0, /*!< s0_pixel' = s0_pixel. */
    kDCIF_AlphaColorWithAlpha = 1, /*!< s0_pixel' = s0_pixel * s0_alpha". */
} dcif_layer_alpha_color_mode_t;

/*! @brief Layer alpha blend color mode. */
typedef enum _dcif_layer_alpha_background_mode
{
    kDCIF_AlphaBackgroundPorterDuff = 0, /*!< Layer covered by background is blended in porter-duff blend mode. */
    kDCIF_AlphaBackgroundNormal     = 1, /*!< Layer covered by background is blended in normal blend mode. */
} dcif_layer_alpha_background_mode_t;

/*! @brief DCIF ;ayer input alpha blend configuration. */
typedef struct
{
    uint32_t srcFactorMode : 2;      /*!< Source layer factor mode, see @ref dcif_layer_alpha_factor_mode_t. */
    uint32_t dstGlobalAlphaMode : 2; /*!< Destination layer global alpha mode, see @ref dcif_layer_global_alpha_mode_t. */
    uint32_t dstAlphaMode : 1; /*!< Destination layer alpha mode, see @ref dcif_layer_alpha_mode_t. */
    uint32_t dstColorMode : 1; /*!< Destination layer (or PS, s0) color mode, see @ref dcif_layer_alpha_color_mode_t. */
    uint32_t : 2U; /*!< Reserved. */
    uint32_t dstFactorMode : 2; /*!< Destination layer factor mode, see @ref dcif_layer_alpha_factor_mode_t. */
    uint32_t srcGlobalAlphaMode : 2; /*!< Source layer global alpha mode, see @ref dcif_layer_global_alpha_mode_t. */
    uint32_t srcAlphaMode : 1;       /*!< Source layer alpha mode, see @ref dcif_layer_alpha_mode_t. */
    uint32_t srcColorMode : 1;       /*!< Source layer color mode, see @ref dcif_layer_alpha_color_mode_t. */
    uint32_t : 1U; /*!< Reserved. */
    uint32_t backgroundBlendMode: 1U; /*!< Which blend mode that the part of the layer covered by background uses,
                                           see @ref dcif_layer_alpha_background_mode_t. */
    uint32_t dstGlobalAlpha : 8; /*!< Destination layer global alpha value, 0~255. */
    uint32_t : 8U; /*!< Reserved. */
} dcif_layer_alpha_blend_config_t;

/*! @brief DCIF Porter Duff blend mode. Note: don't change the enum item value */
typedef enum _dcif_layer_porter_duff_blend_mode
{
    kDCIF_PorterDuffSrc = 0, /*!< Source Only */
    kDCIF_PorterDuffAtop,    /*!< Source Atop */
    kDCIF_PorterDuffOver,    /*!< Source Over */
    kDCIF_PorterDuffIn,      /*!< Source In. */
    kDCIF_PorterDuffOut,     /*!< Source Out. */
    kDCIF_PorterDuffDst,     /*!< Destination Only. */
    kDCIF_PorterDuffDstAtop, /*!< Destination Atop. */
    kDCIF_PorterDuffDstOver, /*!< Destination Over. */
    kDCIF_PorterDuffDstIn,   /*!< Destination In. */
    kDCIF_PorterDuffDstOut,  /*!< Destination Out. */
    kDCIF_PorterDuffPlus,    /*!< Clear. */
    kDCIF_PorterDuffXor,     /*!< XOR. */
    kDCIF_PorterDuffClear,   /*!< Clear. */
    kDCIF_PorterDuffMax,
} dcif_layer_porter_duff_blend_mode_t;

/*! @brief Layer alpha blend mode. */
typedef enum _dcif_layer_alpha_blend_mode
{
    kDCIF_AlphaBlendEmbedded   = 0U, /*!< Blend with pixel defined alpha value. */
    kDCIF_AlphaBlendOverride   = 1U, /*!< Blend with gobal alpha value, pixel defined alpha value is overridden. */
    kDCIF_AlphaBlendPorterDuff = 3U, /*!< Blend with Porter-Duff enable. */
} dcif_layer_alpha_blend_mode_t;

/*! @brief Layer input pixel format. */
typedef enum _dcif_layer_format
{
    kDCIF_LayerPixelFormatIndex1BPP = DCIF_CTRLDESC_L_FORMAT(0U), /*!< LUT index 1 bit. */
    kDCIF_LayerPixelFormatIndex2BPP = DCIF_CTRLDESC_L_FORMAT(1U), /*!< LUT index 2 bit. */
    kDCIF_LayerPixelFormatIndex4BPP = DCIF_CTRLDESC_L_FORMAT(2U), /*!< LUT index 4 bit. */
    kDCIF_LayerPixelFormatIndex8BPP = DCIF_CTRLDESC_L_FORMAT(3U), /*!< LUT index 8 bit. */
    kDCIF_LayerPixelFormatRGB565    = DCIF_CTRLDESC_L_FORMAT(4U), /*!< RGB565, two pixels use 32 bits. */
    kDCIF_LayerPixelFormatARGB1555  = DCIF_CTRLDESC_L_FORMAT(5U), /*!< ARGB1555, two pixels use 32 bits. */
    kDCIF_LayerPixelFormatARGB4444  = DCIF_CTRLDESC_L_FORMAT(6U), /*!< ARGB4444, two pixels use 32 bits. */
    /*!< If CSC is YUV->RGB the input order from high to low is Y1V0Y0U0, if CSC is YCbCr->RGB the order is Y1Cr0Y0Cb0,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatYVYU      = DCIF_CTRLDESC_L_FORMAT(7U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(0U),
    /*!< If CSC is YUV->RGB the input order from high to low is Y1U0Y0V0, if CSC is YCbCr->RGB the order is Y1CB0Y0CR0,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatYUYV      = DCIF_CTRLDESC_L_FORMAT(7U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(1U),
    /*!< If CSC is YUV->RGB the input order from high to low is V0Y1U0Y0, if CSC is YCbCr->RGB the order is Cr0Y1Cb0Y0,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatVYUY      = DCIF_CTRLDESC_L_FORMAT(7U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(2U),
    /*!< If CSC is YUV->RGB the input order from high to low is U0Y1V0Y0, if CSC is YCbCr->RGB the order is Cb0Y1Cr0Y0,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatUYVY      = DCIF_CTRLDESC_L_FORMAT(7U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(3U),
    kDCIF_LayerPixelFormatRGB888    = DCIF_CTRLDESC_L_FORMAT(8U),  /*!< RGB888 packed, one pixel uses 24 bits. */
    kDCIF_LayerPixelFormatARGB8888  = DCIF_CTRLDESC_L_FORMAT(9U),  /*!< ARGB8888 unpacked, one pixel uses 32 bits. */
    kDCIF_LayerPixelFormatABGR8888  = DCIF_CTRLDESC_L_FORMAT(10U), /*!< ABGR8888 unpacked, one pixel uses 32 bits. */
    kDCIF_LayerPixelFormatBGR888    = DCIF_CTRLDESC_L_FORMAT(11U), /*!< BGR888 unpacked, one pixel uses 24 bits. */
    /*!< YUV420 2 planner format. Planner 1 is for Y component, 8-bit each. Planner 2 is for VU component, 8-bit each from high to low. */
    kDCIF_LayerPixelFormatNV12      = DCIF_CTRLDESC_L_FORMAT(12U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(0U),
    /*!< YUV420 2 planner format. Planner 1 is for Y component, 8-bit each. Planner 2 is for UV component, 8-bit each from high to low. */
    kDCIF_LayerPixelFormatNV21      = DCIF_CTRLDESC_L_FORMAT(12U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(1U),
    /*!< If CSC is YUV->RGB the input order from high to low is YUV, if CSC is YCbCr->RGB the order is YCbCr,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatYUV       = DCIF_CTRLDESC_L_FORMAT(13U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(0U),
    /*!< If CSC is YUV->RGB the input order from high to low is YVU, if CSC is YCbCr->RGB the order is YCrCb,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatYVU       = DCIF_CTRLDESC_L_FORMAT(13U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(1U),
    /*!< If CSC is YUV->RGB the input order from high to low is UVY, if CSC is YCbCr->RGB the order is CbCrY,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatUVY       = DCIF_CTRLDESC_L_FORMAT(13U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(2U),
    /*!< If CSC is YUV->RGB the input order from high to low is VUY, if CSC is YCbCr->RGB the order is CrCbY,
     only layer 0 and layer 1 support this. */
    kDCIF_LayerPixelFormatVUY       = DCIF_CTRLDESC_L_FORMAT(13U) |
                                      DCIF_CTRLDESC_L_YUV_FORMAT(3U),
} dcif_layer_format_t;

/*! @brief DCIF module layer panic configuration. */
typedef struct _dcif_layer_panic_config_t
{
    bool enable; /*!< Enable panic request. Enable to prevent layer underflow. */
    uint16_t lowLevel; /*!< When word count in layer FIFO is less than lowLevel, panic interrupt will be asserted. */
    uint16_t highLevel; /*!< When word count in layer FIFO is greater than highLevel, panic interrupt will be cleared. */
} dcif_layer_panic_config_t;

/*! @brief DCIF module layer configuration for all 4 user configurable layers. */
typedef struct _dcif_layer_config_t
{
    bool enable; /*!< Enable layer. */
    dcif_layer_format_t format; /*!< Layer input format. */
    int32_t topLeftX; /*!< Top left Y coordinate, can not be negative value if PDI input is used. */
    int32_t topLeftY; /*!< Top left Y coordinate, can not be negative value if PDI input is used. */
    uint16_t width;    /*!< The width of the layer. */
    uint16_t height;   /*!< The height of the layer. */
    uint32_t background; /*!< The background color in ARGB8888 format of the layer.
                            It is used to fill the not overlaped area of the layer compared with the output frame. */
    dcif_layer_panic_config_t panic; /*!< Panic configuration. */
    uint8_t globalAlpha; /*!< Global alpha value. alphaBlendConfig has a alpha value too. TODO */
    dcif_layer_alpha_blend_mode_t alphaBlendMode; /*!< Alpha blending mode. */
    dcif_layer_alpha_blend_config_t alphaBlendConfig; /*!< Alpha blend configuration. */
} dcif_layer_config_t;

/*! @brief DCIF output interface. */
typedef enum _dcif_output_interface
{
    kDCIF_OutputDpi    = 0U, /*!< DPI interface. */
    kDCIF_OutputDbi    = 1U, /*!< DBI interface. */
    kDCIF_OutputDcsPkt = 2U, /*!< DCS packet interface. */
} dcif_output_interface_t;

/*! @brief DCIF module output configuration. */
typedef struct _dcif_output_config_t
{
    dcif_output_interface_t interface; /*!< Output interface selection. */
    uint16_t width; /*!< The width of the output frame in pixel. When in DPI mode, this should be the panel width. */
    uint16_t height; /*!< The height of the output frame in pixel. When in DPI mode, this should be the panel height. */
} dcif_output_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

 #if defined(__cplusplus)
 extern "C" {
 #endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initialize the DCIF.
 *
 * This function initializes the DCIF to prepare it to work.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Init(DCIF_Type *base);

/*!
 * @brief De-initialize the DCIF.
 *
 * This function disables the DCIF peripheral clock.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Deinit(DCIF_Type *base);
/*! @} */

/*!
 * @name General control
 * @{
 */

/*!
 * @brief Set the DCIF output configuration.
 *
 * Set the output configuration of frame size, output interface.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_SetOutputConfig(DCIF_Type *base, const dcif_output_config_t *config);

/*
 * @brief Enable or disable output.
 *
 * @param base DCIF peripheral base address.
 * @param enable Use true to enable, false to disable.
 */
static inline void DCIF_EnableOutput(DCIF_Type *base, bool enable)
{
    base->DISP_CTRL = (base->DISP_CTRL & ~DCIF_DISP_CTRL_DISP_ON_MASK) | DCIF_DISP_CTRL_DISP_ON(enable ? 1U : 0U);
}

/*!
 * @brief Reset the DCIF module.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Reset(DCIF_Type *base);

/*! @} */

/*!
 * @name Layer configuration
 * @{
 */

/*!
 * @brief Configure the layer position.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param topLeftX The x value of thr top-left coordinate.
 * @param topLeftY The y value of thr top-left coordinate.
 * @param width The width of the layer.
 * @param height The height of the layer.
 */
void DCIF_SetLayerPosition(DCIF_Type *base, uint8_t layer, uint16_t topLeftX, uint16_t topLeftY, uint16_t width, uint16_t height);

/*!
 * @brief Set the DCIF layer configuration.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param config Pointer to the configuration structure.
 * @retval kStatus_Success Successfully get the configuration.
 * @retval kStatus_InvalidArgument The blend mode not supported.
 */
status_t DCIF_SetLayerConfig(DCIF_Type *base, uint8_t layer, const dcif_layer_config_t *config);

/*
 * @brief Enable or disable layer.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param enable Use true to enable, false to disable.
 */
static inline void DCIF_EnableLayer(DCIF_Type *base, uint8_t layer, bool enable)
{
    base->L[layer].CTRLDESC_L[0] = (base->L[layer].CTRLDESC_L[0] & ~DCIF_CTRLDESC_L_EN_MASK) |
                     DCIF_CTRLDESC_L_EN(enable ? 1U : 0U);
}

/*
 * @brief Disable layer.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 */
static inline void DCIF_DisableLayer(DCIF_Type *base, uint8_t layer)
{
    base->L[layer].CTRLDESC_L[0] &= ~DCIF_CTRLDESC_L_EN_MASK;
}

/*!
 * @brief Get the alpha blend configuration by porter duff blend mode.
 *
 * @param mode The blend mode.
 * @param config Pointer to the configuration.
 * @retval kStatus_Success Successfully get the configuration.
 * @retval kStatus_InvalidArgument The blend mode not supported.
 */
status_t DCIF_GetPorterDuffConfig(dcif_layer_porter_duff_blend_mode_t mode, dcif_layer_alpha_blend_config_t *config);

/*!
 * @brief Set the DCIF layer alpha blend configuration.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param config Pointer to the configuration structure.
 */
void DCIF_SetLayerAlphaBlendConfig(DCIF_Type *base, uint8_t layer, const dcif_layer_alpha_blend_config_t *config);

/*
 * @brief Set the layer buffer stride.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param strideBytes The stride in byte.
 */
static inline void DCIF_SetLayerStride(DCIF_Type *base, uint8_t layer, uint32_t strideBytes)
{
    /* The frame buffer address and stride must be aligned. */
    assert(0U == (strideBytes & (DCIF_FB_ALIGN - 1U)));

    base->L[layer].CTRLDESC_L[3] = strideBytes;
}

/*
 * @brief Set the layer buffer address.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param address The stride in byte.
 */
static inline void DCIF_SetLayerAddr(DCIF_Type *base, uint8_t layer, uint32_t address)
{
    /* The frame buffer address and stride must be aligned. */
    assert(0U == (address & (DCIF_FB_ALIGN - 1U)));

    base->L[layer].CTRLDESC_L[4] = address;
}

/*
 * @brief Set the layer buffer address for UV planner when input format is YUV420_2p(NV12 or NV21).
 *
 * Only layer 0 and layer 1 supports this feature.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer index.
 * @param address The stride in byte.
 */
static inline void DCIF_SetLayerUVAddr(DCIF_Type *base, uint8_t layer, uint32_t address)
{
    /* The frame buffer address and stride must be aligned. */
    assert(0U == (address & (DCIF_FB_ALIGN - 1U)));

    assert(layer < 2U);

    base->L[layer].FRAME_BUF2_ADDR_LOW_L = address;
}

/*!
 * @brief Set the color for back ground layer.
 *
 * @param base DCIF peripheral base address.
 * @param backGroundColor Pixel value of the background color.
 */
static inline void DCIF_SetBackGroundLayerColor(DCIF_Type *base, uint32_t backGroundColor)
{
    base->DISP_PAR = backGroundColor;
}

/*!
 * @brief Trigger the layer configuration shadow load.
 *
 * The new layer configurations are written to the shadow registers first,
 * When all configurations written finished, call this function, then shadowed
 * control registers are updated to the active control registers on VSYNC of
 * next frame.
 *
 * @param base DCIF peripheral base address.
 * @param layer Layer layerIndex.
 */
static inline void DCIF_TriggerLayerShadowLoad(DCIF_Type *base, uint8_t layer)
{
    base->L[layer].CTRLDESC_L[0] |= DCIF_CTRLDESC_L_SHADOW_LOAD_EN_MASK;
}

/*!
 * @brief Set the gamma correction value to the gamma table.
 *
 * @param base DCIF peripheral base address.
 * @param mask The mask of red/green/blue table access, OR'd value of _dcif_gamma_access.
 * @param startIndex Start index in the gamma table that the value will be set to.
 * @param gamma The gamma values to set to the gamma table.
 * @param gammaLen The length of the gamma table data.
 */
void DCIF_SetGammaData(DCIF_Type *base, uint32_t mask, uint8_t startIndex, const uint32_t *gamma, uint16_t gammaLen);

/*!
 * @brief Enables the gamma correction.
 *
 * @param base DCIF peripheral base address.
 * @param enable True to enable, false to disable.
 */
static inline void DCIF_EnableGamma(DCIF_Type *base, bool enable)
{
    if (enable)
    {
        base->GC_CTRL |= DCIF_GC_CTRL_GC_EN_MASK;
    }
    else
    {
        base->GC_CTRL &= ~DCIF_GC_CTRL_GC_EN_MASK;
    }
}

/*!
 * @brief Get the default configuration for CLUT.
 *
 * The default configuration value is:
 *
 * @code
   config->clutSelect[0] = kDCIF_Clut0;
   config->clutSelect[1] = kDCIF_Clut1;
 * @endcode
 *
 * @param config Pointer to the DCIF CLUT configuration.
 */
void DCIF_ClutGetDefaultConfig(dcif_clut_config_t *config);

/*!
 * @brief Set the color look up table configuration.
 *
 * This function must be called before DCIF_SetLayerConfig if the input pixel
 * format isIndex.
 *
 * @param base DCIF peripheral base address.
 * @param config The CLUT configuration.
 */
void DCIF_ClutSetConfig(DCIF_Type *base, const dcif_clut_config_t *config);

/*!
 * @brief Set the CLUT value.
 *
 * @param base DCIF peripheral base address.
 * @param startIndex Start index in the CLUT that the value will be set to.
 * @param clut The LUT values to set to the CLUT table.
 * @param clutLen The length of the CLUT table data.
 */
void DCIF_ClutSetData(DCIF_Type *base, uint8_t startIndex, const uint32_t *clut, uint8_t clutLen);

/*!
 * @brief Set the color space conversion mode.
 *
 * Supports YUV2RGB and YCbCr2RGB. This must be called before DCIF_SetLayerConfig
 * if the layer pixel format is YUV.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Index of the layer.
 * @param mode The conversion mode.
 */
void DCIF_SetCscMode(DCIF_Type *base, uint8_t layerIndex, dcif_csc_mode_t mode);
/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables DCIF interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
void DCIF_EnableInterrupts(DCIF_Type *base, uint8_t domain, uint32_t mask);

/*!
 * @brief Disables DCIF interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
void DCIF_DisableInterrupts(DCIF_Type *base, uint8_t domain, uint32_t mask);

/*!
 * @brief Get DCIF interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @return Interrupt pending status, OR'ed value of _dcif_interrupt.
 */
uint32_t DCIF_GetInterruptStatus(DCIF_Type *base, uint8_t domain);

/*!
 * @brief Clear DCIF interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask of the flags to clear, OR'ed value of _dcif_interrupt.
 */
void DCIF_ClearInterruptStatus(DCIF_Type *base, uint8_t domain, uint32_t mask);

/*!
 * @brief Enables DCIF layer interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask interrupt source, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_EnableLayerInterrupts(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask);

/*!
 * @brief Disables DCIF layer interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask interrupt source, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_DisableLayerInterrupts(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask);

/*!
 * @brief Get DCIF layer interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @return Interrupt pending status, OR'ed value of _dcif_layer_interrupt.
 */
uint32_t DCIF_GetLayerInterruptStatus(DCIF_Type *base, uint8_t domain,  uint8_t layer);

/*!
 * @brief Clear DCIF layer interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask of the flags to clear, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_ClearLayerInterruptStatus(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask);

/*! @} */

/*!
 * @name PDI(parallel data interface) configuration
 * @{
 */

/*!
 * @brief Get the default configuration for DCIF PDI input.
 *
 * The default configuration value is:
 *
 * @code
   config->enable = false;
   config->skipFirstFrame = false;
   config->vsyncControl = false;
   config->vsyncDelay_pclk = 0;
   config->vsyncTimeout_hsync = 0;
   config->polarityFlags = kDCIF_PdiVsyncActiveLow | kDCIF_PdiDriveDataOnFallingClkEdge;
   config->format = kDCIF_PdiRGB888;
   config->layer = kDCIF_PdiLayer0;
 * @endcode
 *
 * @param config Pointer to the DCIF PDI configuration.
 */
void DCIF_PdiGetDefaultConfig(dcif_pdi_config_t *config);

/*!
 * @brief Configure the DCIF PDI input.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_PdiSetConfig(DCIF_Type *base, const dcif_pdi_config_t *config);

/*! @} */

/*!
 * @name FBD(frame buffer decompression) configuration
 * @{
 */

/*!
 * @brief Get the default configuration for DCIF FBD input.
 *
 * The default configuration value is:
 *
 * @code
   config->enable = false;
   config->format = kDCIF_FbdRGBA16;
   config->layer = kDCIF_FbdLayer0;
 * @endcode
 *
 * param config Pointer to the DCIF PDI configuration.
 */
void DCIF_FbdGetDefaultConfig(dcif_fbd_config_t *config);

/*!
 * @brief Configure the DCIF FBD input.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_FbdSetConfig(DCIF_Type *base, const dcif_fbd_config_t *config);

/*! @} */

/*!
 * @name DPI configuration
 * @{
 */

/*!
 * @brief Get the default configuration for DPI interface.
 *
 * The default configuration value is:
 *
 * @code
   config->hsw = 0;
   config->hfp = 0;
   config->hbp = 0;
   config->vsw = 0;
   config->vfp = 0;
   config->vbp = 0;
   config->polarityFlags = kDCIF_HsyncActiveLow | kDCIF_VsyncActiveLow | kDCIF_DriveDataOnFallingClkEdge;
   config->format = kDCIF_DpiRGB565;;
   config->dcif_dpi_display_mode_t = kDCIF_DpiNormal;
   config->frameFetch = kDCIF_DpiVfpBegin;
   config->tcFifoFill = kDCIF_DpiVbpEnd;
   config->enableBackground = true;
 * @endcode
 *
 * @param config Pointer to the DCIF configuration.
 */
void DCIF_DpiGetDefaultConfig(dcif_dpi_config_t *config);

/*!
 * @brief Set the configuration for DCIF DPI interface.
 *
 * This function configures the DCIF DPI interface.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_DpiSetConfig(DCIF_Type *base, const dcif_dpi_config_t *config);

/*! @} */

/*!
 * @name DBI configuration
 * @{
 */

/*!
 * @brief Get the default configuration to initialize the DCIF DBI interface.
 *
 * The default configuration value is:
 *
 * @code
   config->format      = kDCIF_DbiOutD16RGB565;
   config->type        = kDCIF_DbiTypeB;
   config->signalFlags = kDCIF_DbiTeEnable;
   config->rdHigh      = 0U;
   config->rdLow       = 0U;
   config->wrHigh      = 0U;
   config->wrLow       = 0U;
   config->csSetup     = 0U;
   config->csHold      = 0U;
   @endcode
 *
 * @param config Pointer to the DCIF DBI configuration.
 */
void DCIF_DbiGetDefaultConfig(dcif_dbi_config_t *config);

/*!
 * @brief Set the configuration for DCIF DBI mode.
 *
 * This function configures the DCIF DBI interface.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_DbiSetConfig(DCIF_Type *base, const dcif_dbi_config_t *config);

/*!
 * @brief Send command to DBI port.
 *
 * @param base DCIF peripheral base address.
 * @param cmd the DBI command to send.
 */
void DCIF_DbiWriteCommand(DCIF_Type *base, uint8_t cmd);

/*!
 * @brief Write parameter to DBI port.
 *
 * @param base DCIF peripheral base address.
 * @param data pointer to data buffer.
 * @param dataLen_Byte data buffer length in byte.
 */
void DCIF_DbiWriteParam(DCIF_Type *base, const uint8_t *data, uint32_t dataLen_Byte);

/*!
 * @brief Trigger the send of pixel data in frame buffer to panel controller memory.
 *
 * This function starts sending the pixel data in frame buffer to panel controller,
 * user can monitor interrupt @ref kDCIF_InterruptDbiCommandDone to know when
 * then data sending finished.
 *
 * @param base DCIF peripheral base address.
 */
static inline void DCIF_DbiWritePixel(DCIF_Type *base)
{
    base->DBI_CTRL = (base->DBI_CTRL & ~DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK) |
        DCIF_DBI_CTRL_DBI_CMD_TYPE(kDCIF_DbiCmdWritePixel) |
        DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK;
}

/*!
 * @brief Read command followed by data to DBI port.
 *
 * @param base DCIF peripheral base address.
 * @param data pointer to data buffer.
 * @param dataLen_Byte data buffer length in byte.
 * @retval kStatus_Success Successfully received parameters.
 * @retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t DCIF_DbiReadParam(DCIF_Type *base, const uint8_t *data, uint32_t dataLen_Byte);

/*! @} */

/*!
 * @name DSI packet interface configuration
 * @{
 */

/*!
 * @brief Set the configuration for DCIF DCS packet interface.
 *
 * This function configures the DCIF DCS packet interface.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the configuration structure.
 */
void DCIF_DcsPktSetConfig(DCIF_Type *base, const dcif_dcs_pkt_config_t *config);

/*!
 * @brief brief Select the update area and send the pixels using DCS packet interface.
 *
 * @param base DCIF peripheral base address.
 * @param startX X coordinate for start pixel.
 * @param startY Y coordinate for start pixel.
 * @param endX X coordinate for end pixel.
 * @param endY Y coordinate for end pixel.
 */
void DCIF_DcsPktUpdateArea(DCIF_Type *base, uint16_t startX, uint16_t startY, uint16_t endX, uint16_t endY);

/*!
 * @brief Start the DCS packet transfer pixel data.
 *
 * @param base DCIF peripheral base address.
 */
static inline void DCIF_DcsPktTransferStart(DCIF_Type *base)
{
    base->TXPKTIF_CTRL = (base->TXPKTIF_CTRL & ~DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_MASK) |
                         DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE(kDCIF_DcsPktCmdWritePixel);

    base->TXPKTIF_CTRL |= DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_MASK;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_DCIF_H_ */
