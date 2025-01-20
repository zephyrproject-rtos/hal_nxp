/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_PMC_H_
#define FSL_PMC_H_

#include "fsl_common.h"

/*! @addtogroup pmc */
/*! @{ */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief PMC driver version */
#define FSL_PMC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */
                                                       /*! @} */

/*!
 * @brief Low-voltage Detect Voltage Select
 */
typedef enum _pmc_low_volt_detect_volt_select
{
    kPMC_LowVoltDetectLowTrip  = 0U, /*!< Low-trip point selected (VLVD = VLVDL )*/
    kPMC_LowVoltDetectHighTrip = 1U  /*!< High-trip point selected (VLVD = VLVDH )*/
} pmc_low_volt_detect_volt_select_t;

/*!
 * @brief Low-voltage Warning Voltage Select
 */
typedef enum _pmc_low_volt_warning_volt_select
{
    kPMC_LowVoltWarningLowTrip  = 0U, /*!< Low-trip point selected (VLVW = VLVW1)*/
    kPMC_LowVoltWarningMid1Trip = 1U, /*!< Mid 1 trip point selected (VLVW = VLVW2)*/
    kPMC_LowVoltWarningMid2Trip = 2U, /*!< Mid 2 trip point selected (VLVW = VLVW3)*/
    kPMC_LowVoltWarningHighTrip = 3U  /*!< High-trip point selected (VLVW = VLVW4)*/
} pmc_low_volt_warning_volt_select_t;

/*!
 * @brief Low-voltage Detect Configuration Structure
 */
typedef struct _pmc_low_volt_detect_config
{
    bool enableStop;                              /*!< enable Low-voltage detect when MCU in stop */
    bool enableReset;                             /*!< Enable system reset when Low-voltage detect*/
    pmc_low_volt_detect_volt_select_t voltSelect; /*!< Low-voltage detect trip point voltage selection*/
} pmc_low_volt_detect_config_t;

/*!
 * @brief Low-voltage Warning Configuration Structure
 */
typedef struct _pmc_low_volt_warning_config
{
    bool enableInt;                                /*!< Enable interrupt when low-voltage warning*/
    pmc_low_volt_warning_volt_select_t voltSelect; /*!< Low-voltage warning trip point voltage selection*/
} pmc_low_volt_warning_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*! @name Power Management Controller Control APIs*/
/*! @{ */

/*!
 * @brief Configures the low-voltage detect setting.
 *
 * This function configures the low-voltage detect setting, including the trip
 * point voltage setting, enables or disables the interrupt, enables or disables the system reset.
 *
 * @param base PMC peripheral base address.
 * @param config  Low-voltage detect configuration structure.
 */
void PMC_ConfigureLowVoltDetect(PMC_Type *base, const pmc_low_volt_detect_config_t *config);

/*!
 * @brief Configures the low-voltage warning setting.
 *
 * This function configures the low-voltage warning setting, including the trip
 * point voltage setting and enabling or disabling the interrupt.
 *
 * @param base PMC peripheral base address.
 * @param config  Low-voltage warning configuration structure.
 */
void PMC_ConfigureLowVoltWarning(PMC_Type *base, const pmc_low_volt_warning_config_t *config);

/*!
 * @brief Gets the Low-voltage Warning Flag status.
 *
 * This function polls the current LVWF status. When 1 is returned, it
 * indicates a low-voltage warning event. LVWF is set when V Supply transitions
 * below the trip point or after reset and V Supply is already below the V LVW.
 *
 * @param base PMC peripheral base address.
 * @return Current LVWF status
 *                  - true: Low-voltage Warning Flag is set.
 *                  - false: the  Low-voltage Warning does not happen.
 */
static inline bool PMC_GetLowVoltWarningFlag(PMC_Type *base)
{
    return (bool)(base->SPMSC1 & PMC_SPMSC1_LVWF_MASK);
}

/*!
 * @brief Acknowledges the Low-voltage Warning flag.
 *
 * This function acknowledges the low voltage warning errors (write 1 to
 * clear LVWF).
 *
 * @param base PMC peripheral base address.
 */
static inline void PMC_ClearLowVoltWarningFlag(PMC_Type *base)
{
    base->SPMSC1 |= PMC_SPMSC1_LVWACK_MASK;
}

/*!
 * @brief enable/disable LVD system.
 *
 * This function shoule be called with PMC_ConfigureLowVoltDetect or PMC_ConfigureLowVoltWarning
 *
 * @param base PMC peripheral base address.
 * @param enable enable LVD system
 */
static inline void PMC_EnableLVD(PMC_Type *base, bool enable)
{
    if (enable)
    {
        base->SPMSC1 |= PMC_SPMSC1_LVDE_MASK;
    }
    else
    {
        base->SPMSC1 &= ~PMC_SPMSC1_LVDE_MASK;
    }
}

/*!
 * @brief Configures the PMC bandgap.
 *
 * This function enable bandgap buffer.
 *
 * @param base PMC peripheral base address.
 * @param enable enable bandgap buffer
 */
static inline void PMC_EnableBandgapBuffer(PMC_Type *base, bool enable)
{
    if (enable)
    {
        base->SPMSC1 |= PMC_SPMSC1_BGBE_MASK;
    }
    else
    {
        base->SPMSC1 &= (~PMC_SPMSC1_BGBE_MASK);
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* FSL_PMC_H_*/
