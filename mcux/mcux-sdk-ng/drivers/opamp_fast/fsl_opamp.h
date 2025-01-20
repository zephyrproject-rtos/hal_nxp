/*
 * Copyright 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_OPAMP_H_
#define FSL_OPAMP_H_

#include "fsl_common.h"

/*!
 * @addtogroup opamp
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief OPAMP driver version. */
#define FSL_OPAMP_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief The enumeration provides the selection of the OPAMP compensation capcitor,
 * choose different option to fit different gains.
 */
typedef enum _opamp_comp_cap
{
    kOPAMP_FitGain2x = 0U, /*!< Fit 2x gains. */
    kOPAMP_FitGain4x,      /*!< Fit 4x gains. */
    kOPAMP_FitGain8x,      /*!< Fit 2x gains. */
    kOPAMP_FitGain16x,     /*!< Fit 16x gains. */
} opamp_comp_cap_t;

/*!
 * @brief The enumeration provides the selection of the OPAMP bias current,
 * choose different option to change power comsumption.
 */
typedef enum _opamp_bias_current
{
    kOPAMP_NoChange = 0U,   /*!< Keep power consumption constant. */
    kOPAMP_ChangeToQuarter, /*!< Reduce power consumption to 1/4. */
    kOPAMP_ChangeToHalf,    /*!< Reduce power consumption to 1/2. */
    kOPAMP_ChangeToDouble,  /*!< Double the power consumption. */
} opamp_bias_current_t;

/*!
 * @brief OPAMP configuraion.
 */
typedef struct _opamp_config
{
    bool enable;         /*!< Decides whether to enable or disable OPAMP. */
    uint8_t compCap;     /*!< Compensation capacitor selection. */
    uint8_t biasCurrent; /*!< Bias current selection. */
} opamp_config_t;

/*******************************************************************************
 * API
 *******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initialize OPAMP instance.
 *
 * @param base OPAMP peripheral base address.
 * @param config The pointer to @ref opamp_config_t.
 */
void OPAMP_Init(OPAMP_Type *base, const opamp_config_t *config);

/*!
 * @brief De-initialize OPAMP instance.
 *
 * @param base OPAMP peripheral base address.
 */
void OPAMP_Deinit(OPAMP_Type *base);

/*! @} */

/*!
 * @name Configuration.
 * @{
 */

/*!
 * @brief Get default configuration of OPAMP.
 *
 * @code
 *     config->enable      = false;
 *     config->compCap     = kOPAMP_FitGain2x;
 *     config->biasCurrent = kOPAMP_NoChange;
 * @endcode
 *
 * @param config The pointer to @ref opamp_config_t.
 */
void OPAMP_GetDefaultConfig(opamp_config_t *config);

/*!
 * @brief This function is used to set OPAMP compensation capcitor.
 *
 * @param base OPAMP peripheral base address.
 * @param compCap The value of compensation capcitor.
 */
static inline void OPAMP_SetCompensationCapcitor(OPAMP_Type *base, uint8_t compCap)
{
    base->OPAMP_CTRL = (base->OPAMP_CTRL & ~OPAMP_OPAMP_CTRL_OPA_CC_SEL_MASK) | OPAMP_OPAMP_CTRL_OPA_CC_SEL(compCap);
}

/*!
 * @brief This function is used to set the OPAMP bias current.
 *
 * @param base OPAMP peripheral base address.
 * @param biasCurrent The value of bias current.
 */
static inline void OPAMP_SetBiasCurrent(OPAMP_Type *base, uint8_t biasCurrent)
{
    base->OPAMP_CTRL =
        (base->OPAMP_CTRL & ~OPAMP_OPAMP_CTRL_OPA_BC_SEL_MASK) | OPAMP_OPAMP_CTRL_OPA_BC_SEL(biasCurrent);
}

/*!
 * @brief This function is used to enable or disable the OPAMP.
 *
 * @param base OPAMP peripheral base address.
 * @param enable Decides whether to enable or disable the OPAMP.
 * - \b true Enable the OPAMP.
 * - \b false DIsable the OPAMP.
 */
static inline void OPAMP_Enable(OPAMP_Type *base, bool enable)
{
    if (enable)
    {
        base->OPAMP_CTRL |= OPAMP_OPAMP_CTRL_OPA_EN_MASK;
    }
    else
    {
        base->OPAMP_CTRL &= ~OPAMP_OPAMP_CTRL_OPA_EN_MASK;
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_OPAMP_H_ */
