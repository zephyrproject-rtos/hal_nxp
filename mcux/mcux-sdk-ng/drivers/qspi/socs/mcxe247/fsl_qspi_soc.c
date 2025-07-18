/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qspi_soc.h"

/*! brief Defines the QuadSPI SOCCR mask field. */
#define QuadSPI_SOCCR_PENDING_READ_ENABLE_MASK (1U << 16)
#define QuadSPI_SOCCR_BURST_READ_ENABLE_MASK   (1U << 17)
#define QuadSPI_SOCCR_BURST_WRITE_ENABLE_MASK  (1U << 18)

/*! brief Defines the QuadSPI MCR[SCLKCFG] mask field. */
#define QuadSPI_SCLKCFG_INPUT_BUFF_MASK (1U << 7)

status_t QSPI_SocConfigure(QuadSPI_Type *base, qspi_soc_config_t *config)
{
    assert(config->clkDiv <= 8U);

    uint8_t div = (config->clkDiv != 0U) ? (config->clkDiv - 1U) : 0U;
    uint32_t sclkCfg;

    base->SOCCR = (uint32_t)config->delayChainFlashA | ((uint32_t)config->delayChainFlashB << 8U) |
                  (config->pendingReadEnable ? QuadSPI_SOCCR_PENDING_READ_ENABLE_MASK : 0U) |
                  (config->burstReadEnable ? QuadSPI_SOCCR_BURST_READ_ENABLE_MASK : 0U) |
                  (config->burstWriteEnable ? QuadSPI_SOCCR_BURST_WRITE_ENABLE_MASK : 0U) |
                  ((uint32_t)(!config->divEnable) << 28U) | (((uint32_t)div & 0x7U) << 29U);

    sclkCfg = (uint32_t)config->clkDqsFlashA | ((uint32_t)config->invertClkDqsFlashA << 1U) |
              ((uint32_t)config->clkDqsFlashB << 2U) | ((uint32_t)config->invertClkDqsFlashB << 3U) |
              ((uint32_t)config->internalClk << 4U) | ((uint32_t)config->hyperramDqsClkFlashB << 5U) |
              ((uint32_t)config->clkMode << 6U) | (config->inputBufEnable ? QuadSPI_SCLKCFG_INPUT_BUFF_MASK : 0U);
    base->MCR |= QuadSPI_MCR_SCLKCFG(sclkCfg);

    /* Ungate the QSPI SFCK. */
    SIM->MISCTRL0 |= SIM_MISCTRL0_QSPI_CLK_SEL_MASK;

    return kStatus_Success;
}
