/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MIPI_CSI2RX_H_
#define FSL_MIPI_CSI2RX_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief CSI2RX driver version. */
#define FSL_CSI2RX_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief MIPI CSI-2 data types.
 *
 * Encoding values per MIPI CSI-2 specification.
 */
typedef enum _csi2rx_data_type
{
    kCSI2RX_DataTypeNULL         = 0x10U, /*!< NULL packet */
    kCSI2RX_DataTypeBlanking     = 0x11U, /*!< Blanking data */
    kCSI2RX_DataTypeEmbedded     = 0x12U, /*!< Embedded 8-bit non-image data */
    kCSI2RX_DataTypeYUV420_8bit  = 0x18U, /*!< YUV420 8-bit */
    kCSI2RX_DataTypeYUV420_10bit = 0x19U, /*!< YUV420 10-bit */
    kCSI2RX_DataTypeLegYUV420_8  = 0x1AU, /*!< Legacy YUV420 8-bit */
    kCSI2RX_DataTypeYUV422_8bit  = 0x1EU, /*!< YUV422 8-bit */
    kCSI2RX_DataTypeYUV422_10bit = 0x1FU, /*!< YUV422 10-bit */
    kCSI2RX_DataTypeRGB444       = 0x20U, /*!< RGB444 */
    kCSI2RX_DataTypeRGB555       = 0x21U, /*!< RGB555 */
    kCSI2RX_DataTypeRGB565       = 0x22U, /*!< RGB565 */
    kCSI2RX_DataTypeRGB666       = 0x23U, /*!< RGB666 */
    kCSI2RX_DataTypeRGB888       = 0x24U, /*!< RGB888 */
    kCSI2RX_DataTypeRAW6         = 0x28U, /*!< RAW6 */
    kCSI2RX_DataTypeRAW7         = 0x29U, /*!< RAW7 */
    kCSI2RX_DataTypeRAW8         = 0x2AU, /*!< RAW8 */
    kCSI2RX_DataTypeRAW10        = 0x2BU, /*!< RAW10 */
    kCSI2RX_DataTypeRAW12        = 0x2CU, /*!< RAW12 */
    kCSI2RX_DataTypeRAW14        = 0x2DU, /*!< RAW14 */
    kCSI2RX_DataTypeRAW16        = 0x2EU, /*!< RAW16 */
    kCSI2RX_DataTypeRAW20        = 0x2FU, /*!< RAW20 */
    kCSI2RX_DataTypeUserDef0     = 0x30U, /*!< User defined type 0 */
    kCSI2RX_DataTypeUserDef1     = 0x31U, /*!< User defined type 1 */
    kCSI2RX_DataTypeUserDef2     = 0x32U, /*!< User defined type 2 */
    kCSI2RX_DataTypeUserDef3     = 0x33U, /*!< User defined type 3 */
    kCSI2RX_DataTypeUserDef4     = 0x34U, /*!< User defined type 4 */
    kCSI2RX_DataTypeUserDef5     = 0x35U, /*!< User defined type 5 */
    kCSI2RX_DataTypeUserDef6     = 0x36U, /*!< User defined type 6 */
    kCSI2RX_DataTypeUserDef7     = 0x37U, /*!< User defined type 7 */
} csi2rx_data_type_t;

/*!
 * @brief MIPI CSI-2 interrupt flags.
 *
 * Maps to IRQ_STATUS / IRQ_ENABLE register bits.
 */
typedef enum _csi2rx_interrupt
{
    kCSI2RX_InterruptCrcError      = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_0_MASK,  /*!< CRC mismatch */
    kCSI2RX_InterruptEcc1BitError  = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_1_MASK,  /*!< 1-bit ECC (corrected) */
    kCSI2RX_InterruptEcc2BitError  = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_2_MASK,  /*!< 2-bit ECC (uncorrectable) */
    kCSI2RX_InterruptUlpsActive    = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_3_MASK,  /*!< ULPS active state change */
    kCSI2RX_InterruptUlpsMark      = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_4_MASK,  /*!< ULPS Mark-1 state change */
    kCSI2RX_InterruptLaneError     = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_5_MASK,  /*!< PPI FIFO flushed before EOP */
    kCSI2RX_InterruptWatchdog      = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_6_MASK,  /*!< Watchdog timeout */
    kCSI2RX_InterruptInternalError = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_7_MASK,  /*!< Internal error */
    kCSI2RX_InterruptParityError   = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_8_MASK,  /*!< Pixel parity error */
    kCSI2RX_InterruptCalibration   = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_10_MASK, /*!< Lane calibration active */
    kCSI2RX_InterruptPhyStatus     = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_11_MASK, /*!< PHY status update */
    kCSI2RX_InterruptCsrParity     = MIPI_CSI2RX_IRQ_STATUS_IRQ_STATUS_12_MASK, /*!< CSR parity error */
} csi2rx_interrupt_t;

/*! @brief CSI2RX configuration. */
typedef struct _csi2rx_config
{
    uint8_t  laneNum;           /*!< Number of active data lanes: 1 or 2 */
    bool     enableVCX;         /*!< Enable Virtual Channel Extension */
    bool     enableScramble;    /*!< Enable per-lane data descrambling */
    bool     enablePacketIface; /*!< Enable packet interface mode */
    uint8_t  flushCount;        /*!< FIFO flush wait cycles */
    bool     enableWatchdog;    /*!< Enable watchdog timer */
    uint16_t watchdogCount;     /*!< Watchdog count in core clock cycles */
    uint8_t  tHsSettle_EscClk;  /*!< Data lane HS settle: u_PRG_RXHS_SETTLE[5:0] */
    uint8_t  tClkSettle_EscClk; /*!< Clock lane HS settle: uc_PRG_RXHS_SETTLE[6:0] */
    bool     enableHighSpeed;   /*!< cfg_rx_hsel: false=below 1.5Gbit/s, true=above */
    bool     enableDeskew;      /*!< cfg_dphy_deskew_en: enable for >1.5Gbit/s */
} csi2rx_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Gets the default configuration for MIPI CSI-2 RX controller.
 *
 * @param config Pointer to the configuration structure.
 */
void CSI2RX_GetDefaultConfig(csi2rx_config_t *config);

/*!
 * @brief Initializes the MIPI CSI-2 RX controller and D-PHY.
 *
 * @param base   MIPI_CSI2RX peripheral base address.
 * @param config Pointer to configuration.
 *
 * @retval #kStatus_Success   Initialization succeeded.
 * @retval #kStatus_Timeout   D-PHY PHY_INIT_DONE not asserted within timeout.
 */
status_t CSI2RX_Init(MIPI_CSI2RX_Type *base, const csi2rx_config_t *config);

/*!
 * @brief Deinitializes the MIPI CSI-2 RX controller.
 *
 * @param base MIPI_CSI2RX peripheral base address.
 */
void CSI2RX_Deinit(MIPI_CSI2RX_Type *base);

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables MIPI CSI-2 interrupts.
 *
 * @param base MIPI_CSI2RX peripheral base address.
 * @param mask Interrupt mask. A logical OR of @ref csi2rx_interrupt_t.
 */
static inline void CSI2RX_EnableInterrupts(MIPI_CSI2RX_Type *base, uint32_t mask)
{
    base->IRQ_ENABLE |= mask;
}

/*!
 * @brief Disables MIPI CSI-2 interrupts.
 *
 * @param base MIPI_CSI2RX peripheral base address.
 * @param mask Interrupt mask. A logical OR of @ref csi2rx_interrupt_t.
 */
static inline void CSI2RX_DisableInterrupts(MIPI_CSI2RX_Type *base, uint32_t mask)
{
    base->IRQ_ENABLE &= ~mask;
}

/*!
 * @brief Gets MIPI CSI-2 interrupt status flags.
 *
 * @param base MIPI_CSI2RX peripheral base address.
 * @return Interrupt status flags. A logical OR of @ref csi2rx_interrupt_t.
 */
static inline uint32_t CSI2RX_GetInterruptStatus(MIPI_CSI2RX_Type *base)
{
    return base->IRQ_STATUS;
}

/*!
 * @brief Clears MIPI CSI-2 interrupt status flags (W1C).
 *
 * @param base MIPI_CSI2RX peripheral base address.
 * @param mask Interrupt flags to clear. A logical OR of @ref csi2rx_interrupt_t.
 */
static inline void CSI2RX_ClearInterruptStatus(MIPI_CSI2RX_Type *base, uint32_t mask)
{
    base->IRQ_STATUS = mask;
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*!
 * @}
 */

#endif /* FSL_MIPI_CSI2RX_H_ */
