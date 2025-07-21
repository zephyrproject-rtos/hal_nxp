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

/*! @brief Defines the QuadSPI Soc specific configuration. */
typedef struct _qspi_soc_config
{
    bool obePullTimingRelax : 1; /*!< Enables the timing relaxation by pulling obe for pad 1 for half cycle, if 0 then
                                    enabled else disabled. */
    bool sckDummyPadInputEnable : 1;  /*!< ibe of QSPIA_SCK_DUMMY pad. 0: Disable input reciever 1: Enable input
                                         reciever. */
    bool sckDummyPadOutputEnable : 1; /*!< obe of QSPIA_SCK_DUMMY pad. 0: Disable output driver 1: Enable output driver.
                                       */
    bool sckDummyPadDriveEnable : 1;  /*!< dse of QSPIA_SCK_DUMMY pad. 0: Disable drive strength 1: Enable drive
                                         strength. */
    bool sckDummyPadPullEnable : 1; /*!< pue of QSPIA_SCK_DUMMY pad. 0: Disable internal pullup or pulldown resistor 1:
                                       Enable internal pullup or pulldown resistor. */
    bool sckDummyPadPullupEnable : 1;   /*!< pus of QSPIA_SCK_DUMMY pad. 0: Enable internal pulldown resistor if pue is
                                           set 1: Enable internal pullup resistor if pue is set. */
    bool sckDummyPadSlewRateEnable : 1; /*!< sre of QSPIA_SCK_DUMMY pad. 0: Disable slew rate control 1: Enable slew
                                           rate control. */
    bool dqsClkPadLoopEnable : 1; /*!< Enables the internal clock which is loop-backed from the dummy internal pad to
                                     compensate data pad delays. */
} qspi_soc_config_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Set QuadSPI Soc specific configuration.
 * @note Should call it when QuadSPI is disabled.
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
