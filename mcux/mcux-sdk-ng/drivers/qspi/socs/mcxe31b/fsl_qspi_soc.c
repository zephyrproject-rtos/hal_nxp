/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qspi_soc.h"

/*! brief Defines the QuadSPI SOCCR mask field. */
#define QuadSPI_SOCCR_OBE_PULL_TIMING_RELAX_MASK             (1U << 0)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_INPUT_MASK         (1U << 1)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_OUTPUT_MASK        (1U << 2)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_DRIVE_MASK         (1U << 3)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_PULL_ENABLE_MASK   (1U << 4)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_PULLUP_ENABLE_MASK (1U << 5)
#define QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_SLEW_RATE_MASK     (1U << 6)

/*!
 * brief Set QuadSPI Soc specific configuration.
 * note Should call it when QuadSPI is disabled.
 *
 * param base  Pointer to QuadSPI Type.
 * param config  QuadSPI Soc configuration structure.
 * return status_t
 */
status_t QSPI_SocConfigure(QuadSPI_Type *base, qspi_soc_config_t *config)
{
    base->SOCCR = (config->obePullTimingRelax ? QuadSPI_SOCCR_OBE_PULL_TIMING_RELAX_MASK : 0U) |
                  (config->sckDummyPadInputEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_INPUT_MASK : 0U) |
                  (config->sckDummyPadOutputEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_OUTPUT_MASK : 0U) |
                  (config->sckDummyPadDriveEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_DRIVE_MASK : 0U) |
                  (config->sckDummyPadPullEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_PULL_ENABLE_MASK : 0U) |
                  (config->sckDummyPadPullupEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_PULLUP_ENABLE_MASK : 0U) |
                  (config->sckDummyPadSlewRateEnable ? QuadSPI_SOCCR_QSPIA_SCK_DUMMY_PAD_SLEW_RATE_MASK : 0U);

    base->MCR &= ~QuadSPI_MCR_DQS_FA_SEL_MASK;
    base->MCR |= QuadSPI_MCR_DQS_FA_SEL((config->dqsClkPadLoopEnable ? 0x1U : 0U));

    return kStatus_Success;
}
