/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_QSPI_SOC_H_
#define FSL_QSPI_SOC_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief QSPI driver version. */
#define FSL_QSPI_SOC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Reference clock selection for DQS for flash. */
typedef enum _qspi_dqs_clk_src
{
    kQSPI_DQSInternalClock = 0x0U, /*!< Internal Reference Clock selected as DQS. */
    kQSPI_DQSLoopbackClock,        /*!< Loopback clock from PAD SCKB selected as DQS. */
} qspi_dqs_clk_src_t;

/*! @brief Reference clock selection for DQS for Flash-B. */
typedef enum _qspi_dqs_clk_type
{
    kQSPI_InvertClock = 0x0U, /*!< Inverted clock from qspi_dqs_clk_src_t selected as DQS. */
    kQSPI_NormalClock,        /*!< Clock from qspi_dqs_clk_src_t selected as DQS. */
} qspi_dqs_clk_type_t;

/*! @brief Internal reference clock (async clock domain) source selection for Quadspi. */
typedef enum _qspi_internal_clk_src
{
    kQSPI_PllDiv1Clock = 0x0U, /*!< PLL_DIV1. */
    kQSPI_FircDiv1Clock,       /*!< FIRC_DIV1. */
} qspi_internal_clk_src_t;

/*! @brief Reference clock selection for DQS for Flash-B. */
typedef enum _qspi_hyperram_dqs_clk_src
{
    kQSPI_InternalDqsClock = 0x0U, /*!< Clock from SCLKCFG[3] selected as DQS (HyperRAM Disabled). */
    kQSPI_ExternalDqsClock,        /*!< External RWDS from Flash B selected as DQS (HyperRAM Enabled). */
} qspi_hyperram_dqs_clk_src_t;

/*! @brief Quadspi Clocking mode selection. */
typedef enum _qspi_clk_mode
{
    kQSPI_SysClock = 0x0U, /*!< Selecting SYS_CLK as AHB read interface Clock and module clock. Mandatory for
                              HSRUN80/RUN 64/RUN 80 configurations. */
    kQSPI_BusClock,        /*!< Selecting BUS_CLK as AHB read interface clock and module clock. Mandatory for HSRUN 112
                              configuration. */
} qspi_clk_mode_t;

/*! @brief Defines the QuadSPI Soc specific configuration. */
typedef struct _qspi_soc_config
{
    uint8_t delayChainFlashA;            /*!< Flash A fine delay chain. 0: Delay of 0 buffer and 1 mux. */
    uint8_t delayChainFlashB;            /*!< Flash B fine delay chain. 0: Delay of 0 buffer and 1 mux. */
    bool pendingReadEnable : 1;          /*!< Enable to control bus gasket’s handling of pending read transactions. */
    bool burstReadEnable : 1;            /*!< Enable to control the bus gasket’s handling of burst read transactions. */
    bool burstWriteEnable : 1;           /*!< Enable to control the bus gasket’s handling of burst read transactions. */
    bool divEnable : 1;                  /*!< Enable the divider. */
    uint8_t clkDiv : 4;                  /*!< Divider for SCK. */
    qspi_dqs_clk_src_t clkDqsFlashA : 1; /*!< Reference clock selection for DQS for Flash-A. */
    qspi_dqs_clk_type_t invertClkDqsFlashA : 1; /*!< DQS clock type. */
    qspi_dqs_clk_src_t clkDqsFlashB : 1;        /*!< Reference clock selection for DQS for Flash-B. */
    qspi_dqs_clk_type_t invertClkDqsFlashB : 1; /*!< DQS clock type. */
    qspi_internal_clk_src_t
        internalClk : 1; /*!< Internal reference clock (async clock domain) source selection for QuadSPI. */
    qspi_hyperram_dqs_clk_src_t hyperramDqsClkFlashB : 1; /*!< HyperRAM selection for Flash B - Reference clock
                                                             selection for DQS for Flash-B. */
    qspi_clk_mode_t clkMode : 1;                          /*!< Quadspi Clocking mode selection. */
    bool inputBufEnable : 1; /*!< Enables input buffer of QSPI pads for SDR and HyperRAM modes. */
} qspi_soc_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Set QuadSPI Soc specific configuration.
 * @note Should call it when IP is disabled.
 *
 * @param base  Pointer to QuadSPI Type.
 * @param config  QuadSPI Soc configuration structure.
 * @return status_t
 */
status_t QSPI_SocConfigure(QuadSPI_Type *base, qspi_soc_config_t *config);

#if defined(__cplusplus)
}
#endif

#endif /* FSL_QSPI_SOC_H_ */
