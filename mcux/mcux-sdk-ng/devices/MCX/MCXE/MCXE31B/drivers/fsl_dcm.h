/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DCM_H_
#define FSL_DCM_H_

#include "fsl_common.h"

/*!
 * @addtogroup dcm
 * @{
 */

 /*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */

/*! @brief DCM driver version. */
#define FSL_DCM_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

/*! @brief DCM life cycle slot count */
#define DCM_LC_SLOT_COUNT 6u

/*!
 * @brief DCF scan report
 */
typedef struct _dcm_dcf_scan_report
{
    uint32_t address : 21;       /*!< Address */
    uint32_t : 3;
    uint32_t location : 3;       /*!< Load location */
    uint32_t flashError : 1;     /*!< Flash memory error, 1 if there is error */
    uint32_t chipSideError : 1;  /*!< Chip side error, 1 if there is error */
    uint32_t scanTimeout : 1;    /*!< 1 if scan timeout. */
    uint32_t : 2;
} dcm_dcf_scan_report_t;

/*!
 * @brief Life cycle
 */
typedef enum _dcm_life_cycle
{
    kDCM_LifeCycleFailureAnalysis    = 0U, /*!< Failure analysis (FA) */
    kDCM_LifeCyclePreFailureAnalysis = 1U, /*!< Pre-Failure analysis (Pre-FA) */
    kDCM_LifeCycleOemProduction      = 2U, /*!< OEM production */
    kDCM_LifeCycleCustomerDelivery   = 3U, /*!< Customer delivery */
    kDCM_LifeCycleMcuProduction      = 6U, /*!< MCU production */
    kDCM_LifeCycleInField            = 7U, /*!< In field */
} dcm_life_cycle_t;

/*!
 * @brief Life cycle scan marking
 */
enum _dcm_life_cycle_scan_marking
{
    kDCM_LifeCycleScanNotScanned   = 0U, /*!< Not scanned yet */
    kDCM_LifeCycleScanActive       = 1U, /*!< Marked as active */
    kDCM_LifeCycleScanInactive     = 2U, /*!< Marked as inactive */
    kDCM_LifeCycleScanRegionErased = 3U, /*!< Region is erased/virgin */
    kDCM_LifeCycleScanUnknown      = 4U, /*!< Marked as inactive by an unknown pattern */
    kDCM_LifeCycleScanTimeout      = 5U, /*!< Scanning timed out */
};

/*!
 * @brief Life cycle slot scan status structure
 */
typedef struct _dcm_life_cycle_slost_scan_status
{
    uint8_t hasError      : 1; /*!< 1 means error, 0 means no error. */
    uint8_t marking       : 3; /*!< See _dcm_life_cycle_scan_marking */
    uint8_t hasEccError   : 1; /*!< 1 means error, 0 means no error. */
    uint8_t hasFlashError : 1; /*!< 1 means error, 0 means no error. */
} dcm_life_cycle_slot_scan_status_t;

/*!
 * @brief Life cycle scan status structure
 */
typedef struct _dcm_life_cycle_scan_status
{
    dcm_life_cycle_slot_scan_status_t status[DCM_LC_SLOT_COUNT];
} dcm_life_cycle_scan_status_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DCF scan result
 * @{
 */

/*!
 * @brief Get DCF scan report.
 *
 * @param slot Slot number, should be less than DCM_DCMSRR_COUNT.
 * @param report The DCF scan report.
 */
void DCM_GetDcfScanReport(uint32_t slot, dcm_dcf_scan_report_t *report);

/*!
 * @brief Clear DCF scan report.
 *
 * @param slot Slot number, should be less than DCM_DCMSRR_COUNT.
 */
static inline void DCM_ClearDcfScanReport(uint32_t slot)
{
    assert(slot  < DCM_DCMSRR_COUNT);

    DCM->DCMSRR[slot] = (DCM_DCMSRR_DCMDCFE1_MASK | DCM_DCMSRR_DCMDCFF1_MASK | DCM_DCMSRR_DCMESF1_MASK | DCM_DCMSRR_DCMESD1_MASK | DCM_DCMSRR_DCMDCFT1_MASK);
}
/*! @}*/

/*!
 * @name Life cycle
 * @{
 */

/*!
 * @brief Get real life cycle.
 *
 * @return The real life cycle.
 */
static inline dcm_life_cycle_t DCM_GetRealLifeCycle(void)
{
    return (dcm_life_cycle_t)((DCM->DCMLCC & DCM_DCMLCC_DCMRLC_MASK) >> DCM_DCMLCC_DCMRLC_SHIFT);
}

/*!
 * @brief Get current life cycle.
 *
 * @return The current life cycle.
 */
static inline dcm_life_cycle_t DCM_GetCurrentLifeCycle(void)
{
    return (dcm_life_cycle_t)((DCM->DCMLCC & DCM_DCMLCC_DCMCLC_MASK) >> DCM_DCMLCC_DCMCLC_SHIFT);
}

/*!
 * @brief Get life cycle scan status.
 *
 * @param status The life cycle scan status.
 */
void DCM_GetLifeCycleScanStatus(dcm_life_cycle_scan_status_t *status);

/*!
 * @brief Clear life cycle scan status.
 */
void DCM_ClearLifeCycleScanStatus(void);

/*! @}*/

/*!
 * @}
 */
#if defined(__cplusplus)
}
#endif
#endif /* FSL_DCM_H_ */
