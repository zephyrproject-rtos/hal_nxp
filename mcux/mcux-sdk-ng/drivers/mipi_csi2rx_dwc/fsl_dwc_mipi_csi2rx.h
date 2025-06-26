/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MIPI_CSI2RX_H_
#define FSL_MIPI_CSI2RX_H_

/*!
 * @addtogroup csi2rx
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CSI2RX driver version. */
#define FSL_CSI2RX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*! @brief CSI2RX data lanes.  */
enum _csi2rx_data_lane
{
    kCSI2RX_DataLane0 = (1U << 0U), /*!< Data lane 0. */
    kCSI2RX_DataLane1 = (1U << 1U), /*!< Data lane 1. */
    kCSI2RX_DataLane2 = (1U << 2U), /*!< Data lane 2. */
    kCSI2RX_DataLane3 = (1U << 3U)  /*!< Data lane 3. */
};

/*! @brief CSI2RX payload type. */
typedef enum _csi2rx_payload
{
    kCSI2RX_DataTypeFS                   = (0x00U),   /*!< Frame Start. */
    kCSI2RX_DataTypeFE                   = (0x01U),   /*!< Frame End. */
    kCSI2RX_DataTypeLS                   = (0x02U),   /*!< Line Start. */
    kCSI2RX_DataTypeLE                   = (0x03U),   /*!< Line End. */
    kCSI2RX_DataTypeEOT                  = (0x04U),   /*!< End of transmission. */
    kCSI2RX_DataTypeGeneric1             = (0x08U),   /*!< Data type generic short 1. */
    kCSI2RX_DataTypeGeneric2             = (0x09U),   /*!< Data type generic short 2. */
    kCSI2RX_DataTypeGeneric3             = (0x0AU),   /*!< Data type generic short 3. */
    kCSI2RX_DataTypeGeneric4             = (0x0BU),   /*!< Data type generic short 4. */
    kCSI2RX_DataTypeGeneric5             = (0x0CU),   /*!< Data type generic short 5. */
    kCSI2RX_DataTypeGeneric6             = (0x0DU),   /*!< Data type generic short 6. */
    kCSI2RX_DataTypeGeneric7             = (0x0EU),   /*!< Data type generic short 7. */
    kCSI2RX_DataTypeGeneric8             = (0x0FU),   /*!< Data type generic short 8. */
    kCSI2RX_DataTypeNULL                 = (0x10U),   /*!< NULL. */
    kCSI2RX_DataTypeBlanking             = (0x11U),   /*!< Blanking. */
    kCSI2RX_DataTypeEmbedded             = (0x12U),   /*!< Embedded. */
    kCSI2RX_DataTypeYUV420_8Bit          = (0x18U),   /*!< YUV420 8 bit. */
    kCSI2RX_DataTypeYUV420_10Bit         = (0x19U),   /*!< YUV420 10 bit. */
    kCSI2RX_DataTypeYUV420_8BitLegacy    = (0x1AU),   /*!< Legacy YUV420 8 bit. */
    kCSI2RX_DataTypeYUV420_8BitCS        = (0x1CU),   /*!< YUV420 8 bit CS. */
    kCSI2RX_DataTypeYUV420_10BitCS       = (0x1DU),   /*!< YUV420 10 bit CS. */
    kCSI2RX_DataTypeYUV422_8Bit          = (0x1EU),   /*!< YUV422 8 bit. */
    kCSI2RX_DataTypeYUV422_10Bit         = (0x1FU),   /*!< YUV422 10 bit. */
    kCSI2RX_DataTypeRGB444               = (0x20U),   /*!< RGB444. */
    kCSI2RX_DataTypeRGB555               = (0x21U),   /*!< RGB555. */
    kCSI2RX_DataTypeRGB565               = (0x22U),   /*!< RGB565. */
    kCSI2RX_DataTypeRGB666               = (0x23U),   /*!< RGB666. */
    kCSI2RX_DataTypeRGB888               = (0x24U),   /*!< RGB888. */
    kCSI2RX_DataTypeRAW28                = (0x26U),   /*!< RAW28. */
    kCSI2RX_DataTypeRAW24                = (0x27U),   /*!< RAW24. */
    kCSI2RX_DataTypeRAW6                 = (0x28U),   /*!< RAW6. */
    kCSI2RX_DataTypeRAW7                 = (0x29U),   /*!< RAW7. */
    kCSI2RX_DataTypeRAW8                 = (0x2AU),   /*!< RAW8. */
    kCSI2RX_DataTypeRAW10                = (0x2BU),   /*!< RAW10. */
    kCSI2RX_DataTypeRAW12                = (0x2CU),   /*!< RAW12. */
    kCSI2RX_DataTypeRAW14                = (0x2DU),   /*!< RAW14. */
    kCSI2RX_DataTypeRAW16                = (0x2EU),   /*!< RAW16. */
    kCSI2RX_DataTypeRAW20                = (0x2FU),   /*!< RAW20. */
    kCSI2RX_DataTypeUserDefined1         = (0x30U),   /*!< User defined 8-bit data type 1. */
    kCSI2RX_DataTypeUserDefined2         = (0x31U),   /*!< User defined 8-bit data type 2. */
    kCSI2RX_DataTypeUserDefined3         = (0x32U),   /*!< User defined 8-bit data type 3. */
    kCSI2RX_DataTypeUserDefined4         = (0x33U),   /*!< User defined 8-bit data type 4. */
    kCSI2RX_DataTypeUserDefined5         = (0x34U),   /*!< User defined 8-bit data type 5. */
    kCSI2RX_DataTypeUserDefined6         = (0x35U),   /*!< User defined 8-bit data type 6. */
    kCSI2RX_DataTypeUserDefined7         = (0x36U),   /*!< User defined 8-bit data type 7. */
    kCSI2RX_DataTypeUserDefined8         = (0x37U)    /*!< User defined 8-bit data type 8. */
}csi2rx_payload_t;

/*! @brief CSI2RX pattern injection configuration.  */
typedef struct _pg_pattern_config
{
    uint32_t pattern_vertical;    /*!< Number of pattern vertical size. */
    uint32_t pattern_horizontal;  /*!< Number of pattern horizontal size. */
    uint8_t  pattern_data_type;   /*!< Number of sent pattern data type. */
    uint32_t pattern_format;      /*!< Number of pattern format. */
}pg_pattern_config_t;

/*! @brief CSI2RX configuration.  */
typedef struct _csi2rx_config
{
    uint32_t laneNum;                /*!< Number of active lanes used for receiving data. */
    uint32_t vcnum;                  /*!< Number of used CSI host interface vittual channel. */
    csi2rx_payload_t datatype;       /*!< Number of csi host channel received data type from sonsor. */
    bool pg_enable;                  /*!< Whether enable CSI host pattern generator, CSI will halt camera received data 
                                          if enable it. Default disabled */
    pg_pattern_config_t pg_pattern;  /*!< Number of active lanes used for receiving data. */
    
    uint32_t cfgclkfreqrange;        /*!< Number of DPHY clock frequency. */
    uint32_t hsfreqrange;            /*!< Number of DPHY frequency range, a lane operation range from 8Mbps to ?. */
} csi2rx_config_t;

/*! @brief MIPI CSI2RX bit errors. */
enum _csi2rx_bit_error
{
    kCSI2RX_BitErrorEccTwoBit = (1U << 0U), /*!< ECC two bit error has occurred. */
    kCSI2RX_BitErrorEccOneBit = (1U << 1U)  /*!< ECC one bit error has occurred. */
};

/*! @brief MIPI CSI2RX PPI error types. */
typedef enum _csi2rx_ppi_error
{
    kCSI2RX_PpiErrorSotHs,     /*!< CSI2RX DPHY PPI error ErrSotHS. */
    kCSI2RX_PpiErrorSotSyncHs, /*!< CSI2RX DPHY PPI error ErrSotSync_HS. */
    kCSI2RX_PpiErrorEsc,       /*!< CSI2RX DPHY PPI error ErrEsc. */
    kCSI2RX_PpiErrorSyncEsc,   /*!< CSI2RX DPHY PPI error ErrSyncEsc. */
    kCSI2RX_PpiErrorControl,   /*!< CSI2RX DPHY PPI error ErrControl. */
} csi2rx_ppi_error_t;

/*! @brief MIPI CSI2RX interrupt. */
enum _csi2rx_interrupt
{
    kCSI2RX_InterruptphyFatal           = (1U << 0U), /* PHY fatal source. */
    kCSI2RX_InterruptPktFatal           = (1U << 1U), /* PJY fatal source. */
    kCSI2RX_InterruptBndryFrameFatal    = (1U << 2U), /* Bndry frame fatal source. */
    kCSI2RX_InterruptSeqFrameFatal      = (1U << 3U), /* Seq frame source. */
    kCSI2RX_InterruptCrcFrameFatal      = (1U << 4U), /* Crc frame fatal source. */
    kCSI2RX_InterruptDataId             = (1U << 5U), /* Data id source. */
    kCSI2RX_InterruptEccCorrected       = (1U << 6U), /* Ecc corrected source. */
    kCSI2RX_InterruptStPhy              = (1U << 15U), /* St phy source. */
    kCSI2RX_InterruptStline             = (1U << 16U), /* St line source. */
};

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Get the CSI instance from peripheral base address.
 *
 * @param base CSI peripheral base address.
 * @return CSI instance.
 */
uint32_t CSI2RX_GetInstance(CAMERA_MIPI_CSI2_Type *base);

/*!
 * @brief introduce function MIPI_CSI2RX_Startup.
 * This function start up the CSI host controller.
 *
 * @param base CSI2RX peripheral address.
 */
void MIPI_CSI2RX_Startup(CAMERA_MIPI_CSI2_Type *base);

/*!
 * @brief introduce function MIPI_CSI2RX_InitInterface.
 * This function deal with CSI and PHY initialization.
 *
 * @param base CSI2RX peripheral address.
 * @param phybase PHY module periperal address.
 * @param config CSI2RX module configuration structure.
 */
status_t MIPI_CSI2RX_InitInterface(CAMERA_MIPI_CSI2_Type *base, CAMERA_DSI_OR_CSI_PHY_CSR_Type *phybase, csi2rx_config_t *config);

/*!
 * @brief introduce function MIPI_CSI2RX_Init.
 * The CSI host interface is basically configured and ready to receive sensor data after this function.
 *
 * @param base CSI2RX peripheral address.
 * @param phybase PHY module periperal address.
 * @param config CSI2RX module configuration structure.
 */
status_t MIPI_CSI2RX_Init(CAMERA_MIPI_CSI2_Type *base, CAMERA_DSI_OR_CSI_PHY_CSR_Type *phybase, csi2rx_config_t *config);

/*!
 * @brief introduce function CSI2RX_Deinit.
 * This function disables the CSI2 host and PHY module.
 *
 * @param base CSI2RX peripheral address.
 */
void CSI2RX_Deinit(CAMERA_MIPI_CSI2_Type *base);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _FSL_MIPI_CSI2RX_H_ */