/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SIM_H_
#define FSL_SIM_H_

#include "fsl_common.h"

/*! @addtogroup sim */
/*! @{*/

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief PMC driver version */
#define FSL_SIM_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */
/*! @} */

/*!@brief System reset status definitions. */
typedef enum _sim_reset_source
{
    kSIM_SourceSackerr = SIM_SRSID_SACKERR_MASK, /*!< Stop mode acknowledge error reset */
    kSIM_SourceMdmap   = SIM_SRSID_MDMAP_MASK,   /*!< MDM-AP system Reset request */
    kSIM_SourceSw      = SIM_SRSID_SW_MASK,      /*!< Software reset */
    kSIM_SourceLockup  = SIM_SRSID_LOCKUP_MASK,  /*!< Core lockup reset */
    kSIM_SourcePor     = SIM_SRSID_POR_MASK,     /*!< Power on reset */
    kSIM_SourcePin     = SIM_SRSID_PIN_MASK,     /*!< External pin reset */
    kSIM_SourceWdog    = SIM_SRSID_WDOG_MASK,    /*!< Wdog reset */
    kSIM_SourceLoc     = SIM_SRSID_LOC_MASK,     /*!< Internal clock source Module reset */
    kSIM_SourceLvd     = SIM_SRSID_LVD_MASK,     /*!< Low voltage detect reset */
    kSIM_SourceAll     = 0xFFFFU,
} sim_reset_source_t;

/*!@brief Unique ID. */
typedef struct _sim_uid
{
#if (defined(FSL_FEATURE_SIM_HAS_UIDH) && FSL_FEATURE_SIM_HAS_UIDH)
    uint32_t H; /*!< UUIDH.  */
#endif          /* FSL_FEATURE_SIM_HAS_UIDH */

#if (defined(FSL_FEATURE_SIM_HAS_UIDM) && FSL_FEATURE_SIM_HAS_UIDM)
    uint32_t MH; /*!< UUIDMH. */
    uint32_t ML; /*!< UUIDML. */
#endif           /* FSL_FEATURE_SIM_HAS_UIDM */
    uint32_t L;  /*!< UUIDL.  */
} sim_uid_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*!
 * @brief Gets the unique identification register value.
 *
 * @param uid Pointer to the structure to save the UID value.
 */
void SIM_GetUniqueId(sim_uid_t *uid);

/*!
 * @brief Gets the reset source.
 * This function gets the SIM reset source.
 * Use source masks defined in the sim_reset_source_t to get the desired source status.
 *
 * This is an example.
   @code
   uint32_t resetStatus;

// To get all reset source statuses.
   resetStatus = SIM_GetSysResetStatus() & kSIM_SourceAll;

   // To test whether the MCU is reset using Watchdog.
   resetStatus = SIM_GetSysResetStatus() & kSIM_SourceWdog;

   // To test multiple reset sources.
   resetStatus = SIM_GetSysResetStatus() & (kSIM_SourceWdog | kSIM_SourcePin);
   @endcode

 * @return system reset status.
 */
static inline uint32_t SIM_GetSysResetStatus(void)
{
    return SIM->SRSID & 0xFFFFU;
}

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* FSL_SIM_H_ */
