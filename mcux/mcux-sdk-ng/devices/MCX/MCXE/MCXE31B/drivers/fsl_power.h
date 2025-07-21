/*
 * Copyright 2025 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_POWER_H_
#define _FSL_POWER_H_

#include "fsl_common.h"

/*! @addtogroup power */
/*! @{ */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief POWER driver version */
#define FSL_POWER_DRIVER_VERSION                \
    (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. \
                             */
/*! @} */

/*! @name POWER Configuration */
/*! @{ */

/*! @brief Power PMC voltage event flag enumeration. */
typedef enum _pmc_event_flag
{
    kPMC_FPMVDD_HV_ALowPowerVoltageResetEventFlag = PMC_LVSC_LVRAF_MASK, /*!< Low-voltage reset event on VDD_HV_A domain
                                                                            in FPM(full performance mode). */
    kPMC_LPMFPMVDD_HV_ALowPowerVoltageResetEventFlag =
        PMC_LVSC_LVRALPF_MASK, /*!< Low-power reset event on VDD_HV_A domain in
                                * both LPM(low performance mode) and FPM.
                                */
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
    kPMC_FPMVDD_HV_BLowPowerVoltageResetEventFlag = PMC_LVSC_LVRBF_MASK, /*!< Low-voltage reset event on VDD_HV_B domain
                                                                            in FPM. */
    kPMC_LPMFPMVDD_HV_BLowPowerVoltageResetEventFlag = PMC_LVSC_LVRBLPF_MASK, /*!< Low-power reset event on VDD_HV_B
                                                                                 domain in both LPM and FPM. */
#endif
    kPMC_FPMV25LowPowerVoltageResetEventFlag = PMC_LVSC_LVR25F_MASK, /*!< Low-voltage reset event on V25 domain in FPM.
                                                                      */
    kPMC_LPMFPMV25LowPowerVoltageResetEventFlag = PMC_LVSC_LVR25LPF_MASK, /*!< Low-power reset event on V25 domain in
                                                                             both LPM and FPM. */
    kPMC_FPMV11LowPowerVoltageResetEventFlag = PMC_LVSC_LVR11F_MASK, /*!< Low-voltage reset event on V11 1.1V domain in
                                                                        FPM. */
    kPMC_LPMFPMV11LowPowerVoltageResetEventFlag = PMC_LVSC_LVR11LPF_MASK, /*!< Low-power reset event on V11 1.1V domain
                                                                             in both LPM and FPM. */
    kPMC_FPMOSCV25GoNoGoEventFlag = PMC_LVSC_GNG25OSCF_MASK, /*!<  Go/NoGo sensor has detected a low voltage
                                                                on the V25 domain in FPM. */
    kPMC_FPMOSCV11GoNoGoEventFlag = PMC_LVSC_GNG11OSCF_MASK, /*!<  Go/NoGo sensor has detected a low voltage
                                                                on the V11 domain in FPM. */
    kPMC_POREventFlag  = PMC_LVSC_PORF_MASK,                 /*!< POR event flag. */
    kPMC_AllEventFlags = PMC_LVSC_LVRAF_MASK | PMC_LVSC_LVRALPF_MASK |
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
                         PMC_LVSC_LVRBF_MASK | PMC_LVSC_LVRBLPF_MASK |
#endif
                         PMC_LVSC_LVR25F_MASK | PMC_LVSC_LVR25LPF_MASK | PMC_LVSC_LVR11F_MASK | PMC_LVSC_LVR11LPF_MASK |
                         PMC_LVSC_GNG25OSCF_MASK | PMC_LVSC_GNG11OSCF_MASK | PMC_LVSC_PORF_MASK /*!< All event flags. */
} pmc_event_flag_t;

/*! @brief List of Power PMC high and low voltage detect flags enumeration */
typedef enum _pmc_voltage_detect_flag
{
    kPMC_FPMVDD_HV_AHighVoltageDetectFlag = PMC_LVSC_HVDAF_MASK, /*!< Voltage on VDD_HV_A is above high-voltage detect
                                                                    threshold and FPM is active. */
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
    kPMC_FPMVDD_HV_BHighVoltageDetectFlag = PMC_LVSC_HVDBF_MASK, /*!< Voltage on VDD_HV_B is above high-voltage detect
                                                                    threshold and FPM is active. */
#endif
    kPMC_FPMV25HighVoltageDetectFlag = PMC_LVSC_HVD25F_MASK,     /*!< Voltage on V25 is above high-voltage detect
                                                                    threshold and full performance mode is active. */
    kPMC_FPMV11HighVoltageDetectFlag = PMC_LVSC_HVD11F_MASK,     /*!< Voltage on V11 is above high-voltage detect
                                                                    threshold and full performance mode is active. */
    kPMC_FPMAllHighVoltageDetectFlags = PMC_LVSC_HVDAF_MASK |
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
                                        PMC_LVSC_HVDBF_MASK |
#endif
                                        PMC_LVSC_HVD25F_MASK |
                                        PMC_LVSC_HVD11F_MASK,   /*!< All high voltage detect flags. */
    kPMC_VDD_HV_AV5LowVoltageDetectFlag = PMC_LVSC_LVD5AF_MASK, /*!< Voltage on VDD_HV_A is below 5V low-voltage
                                                                   threshold. */
#if defined(FSL_FEATURE_PMC_HAS_15V_SUPPLY) && (FSL_FEATURE_PMC_HAS_15V_SUPPLY)
    kPMC_V15LowVoltageDetectFlag = PMC_LVSC_LVD15F_MASK,        /*!< Voltage on V15 is below low-voltage detect
                                                                   threshold and full performance mode is active. */
#endif
    kPMC_AllLowVoltageDetectFlags =
#if defined(FSL_FEATURE_PMC_HAS_15V_SUPPLY) && (FSL_FEATURE_PMC_HAS_15V_SUPPLY)
        PMC_LVSC_LVD15F_MASK |
#endif
        PMC_LVSC_LVD5AF_MASK, /*!< All low voltage detect flags. */
    kPMC_AllVoltageDetectFlags = PMC_LVSC_HVDAF_MASK |
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
                                 PMC_LVSC_HVDBF_MASK |
#endif
                                 PMC_LVSC_HVD25F_MASK | PMC_LVSC_HVD11F_MASK | PMC_LVSC_LVD5AF_MASK
#if defined(FSL_FEATURE_PMC_HAS_15V_SUPPLY) && (FSL_FEATURE_PMC_HAS_15V_SUPPLY)
                                 | PMC_LVSC_LVD15F_MASK /*!< All voltage detect flags. */
#endif
} pmc_voltage_detect_flag_t;

/*! @brief List of POWER PMC high and low voltage detect status enumeration */
typedef enum _pmc_voltage_detect_status
{
    kPMC_FPMVDD_HV_AHighVoltageStatus = PMC_LVSC_HVDAS_MASK, /*!< Voltage on VDD_HV_A is above high-voltage detect
                                                                threshold and FPM is active. */
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
    kPMC_FPMVDD_HV_BHighVoltageStatus = PMC_LVSC_HVDBS_MASK, /*!< Voltage on VDD_HV_B is above high-voltage detect
                                                                threshold and FPM is active. */
#endif
    kPMC_FPMV25HighVoltageStatus = PMC_LVSC_HVD25S_MASK,     /*!< Voltage on V25 is above high-voltage detect
                                                                threshold and FPM is active. */
    kPMC_FPMV11HighVoltageStatus = PMC_LVSC_HVD11S_MASK,     /*!< Voltage on V11 is above high-voltage detect
                                                                threshold and FPM is active. */
    kPMC_VDD_HV_AV5LowVoltageStatus = PMC_LVSC_LVD5AS_MASK,  /*!< Voltage on VDD_HV_A is below low-voltage detect
                                                                threshold. */
#if defined(FSL_FEATURE_PMC_HAS_15V_SUPPLY) && (FSL_FEATURE_PMC_HAS_15V_SUPPLY)
    kPMC_V15LowVoltageStatus = PMC_LVSC_LVD15S_MASK,         /*!< Voltage on V15 is below low-voltage detect
                                                                threshold and FPM is active. */
#endif
    kPMC_AllVoltageDetectStatus = PMC_LVSC_HVDAS_MASK |
#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
                                  PMC_LVSC_HVDBS_MASK |
#endif
                                  PMC_LVSC_HVD25S_MASK | PMC_LVSC_HVD11S_MASK | PMC_LVSC_LVD5AS_MASK
#if defined(FSL_FEATURE_PMC_HAS_15V_SUPPLY) && (FSL_FEATURE_PMC_HAS_15V_SUPPLY)
                                  | PMC_LVSC_LVD15S_MASK /*!< All voltage detect status. */
#endif
} pmc_voltage_detect_status_t;

/*! @brief List of PMC interrupts */
typedef enum _pmc_interrupt_enable
{
    kPMC_HighVoltageDetectInterruptEnable = PMC_CONFIG_HVDIE_MASK, /*!< High voltage detect interrupt enable. */
    kPMC_LowVoltageDetectInterruptEnable  = PMC_CONFIG_LVDIE_MASK, /*!< Low voltage detect interrupt enable. */
    kPMC_AnyVoltageDetectInterruptEnable =
        PMC_CONFIG_HVDIE_MASK | PMC_CONFIG_LVDIE_MASK,             /*!< Hign and low voltage detect interrupt enable.
                                                                    */
} pmc_interrupt_enable_t;

/*!
 * @brief POWER PMC IP version ID definition.
 */
typedef struct _pmc_version_id
{
    bool supportLastMileRegulator; /*!< Support last mile regulator feature. */
    uint8_t minor;                 /*!< Minor version number.         */
    uint8_t major;                 /*!< Major version number.         */
} pmc_version_id_t;

/*! @} */

/*! @name POWER MC_ME Configuration related to power mode switch */
/*! @{ */

/*! @brief POWER MC_ME previous mode enumeration. */
enum _mc_me_previous_mode
{
    kMC_ME_PreviousResetMode   = 0U,  /*!< Previous mode is reset mode(any reset). */
    kMC_ME_PreviousStandbyMode = 0x1U /*!< Previous mode is standby mode. */
};

/*!
 * @brief POWER MC_ME reset type.
 */
typedef enum _mc_me_reset_type
{
    kMC_ME_DestructiveReset = MC_ME_MODE_CONF_DEST_RST_MASK, /*!< Destructive reset request */
    kMC_ME_FunctionalReset  = MC_ME_MODE_CONF_FUNC_RST_MASK  /*!< Functional reset request */
} mc_me_reset_type_t;

/*! @} */

/*! @brief POWER PMC callback function. */
typedef void (*power_pmc_callback_t)(uint32_t mask);

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus*/

/*! @name Power Management Controller Control APIs*/
/*! @{ */

#if defined(FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR) && (FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR)
/*!
 * @brief Enable POWER PMC last mile regulator.
 *
 * @param externalBJTUsed Set to true if external BJT between VDD_HV_A and V15
 * is used, otherwise set to false
 */
static inline void POWER_EnableLastMileRegulator(bool externalBJTUsed)
{
    /*
     * This field must be set to 1 if external BJT between VDD_HV_A and V15 is
     * used on the PCB. The base of this BJT must be connected to the VRC_CTRL pin
     * and is controlled by the PMC to regulate a voltage of 1.5V on V15 pin.
     */
    if (externalBJTUsed)
    {
        PMC->CONFIG |= (uint32_t)PMC_CONFIG_LMBCTLEN_MASK;
    }
    /* After setting LMBCTLEN=1 the software has to wait for LVD15S=0 and then
     * setting LMEN=1 */
    while (PMC->LVSC & (uint32_t)PMC_LVSC_LVD15S_MASK)
    {
    }
    PMC->CONFIG |= (uint32_t)PMC_CONFIG_LMEN_MASK;
    while ((PMC->CONFIG & (uint32_t)PMC_CONFIG_LMSTAT_MASK) == 0u)
    {
    }
}

/*!
 * @brief Disables POWER PMC last mile regulator.
 */
static inline void POWER_DisableLastMileRegulator(void)
{
    PMC->CONFIG &= ~((uint32_t)(PMC_CONFIG_LMBCTLEN_MASK | PMC_CONFIG_LMEN_MASK));
}

#endif /* FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR */

/*!
 * @brief Enable fast recovery from LPM.
 */
static inline void POWER_EnableFastRecoveryFromLPM(void)
{
    PMC->CONFIG |= (uint32_t)PMC_CONFIG_FASTREC_MASK;
}

/*!
 * @brief Disable fast recovery from LPM.
 */
static inline void POWER_DisableFastRecoveryFromLPM(void)
{
    PMC->CONFIG &= ~((uint32_t)PMC_CONFIG_FASTREC_MASK);
}

/*!
 * @brief Enable V25 domain regulator.
 */
static inline void POWER_EnableLPMV25Regulator(void)
{
    PMC->CONFIG |= (uint32_t)PMC_CONFIG_LPM25EN_MASK;
}

/*!
 * @brief Disable V25 domain regulator.
 */
static inline void POWER_DisableLPMV25Regulator(void)
{
    PMC->CONFIG &= ~((uint32_t)PMC_CONFIG_LPM25EN_MASK);
}

#if defined(FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY) && (FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY)
/*!
 * @brief Enable low voltage reset in VDD_HV_B domain of LPM.
 */
static inline void POWER_EnableLPMVDD_HV_BLowVoltageReset(void)
{
    PMC->CONFIG |= (uint32_t)PMC_CONFIG_LVRBLPEN_MASK;
}

/*!
 * @brief Disable low voltage reset in VDD_HV_B domain of LPM.
 */
static inline void POWER_DisableLPMVDD_HV_BLowVoltageReset(void)
{
    PMC->CONFIG &= ~((uint32_t)PMC_CONFIG_LVRBLPEN_MASK);
}
#endif /* FSL_FEATURE_PMC_HAS_VDD_HV_B_SUPPLY */

#if defined(FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR) && (FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR)
/*!
 * @brief Enable auto turn over last mile regulator.
 *
 */
static inline void POWER_EnableAutoTurnOverLastMileRegulator(void)
{
    PMC->CONFIG |= (uint32_t)PMC_CONFIG_LMAUTOEN_MASK;
}

/*!
 * @brief Disable auto turn over last mile regulator.
 */
static inline void POWER_DisableAutoTurnOverLastMileRegulator(void)
{
    PMC->CONFIG &= ~((uint32_t)PMC_CONFIG_LMAUTOEN_MASK);
}
#endif /* FSL_FEATURE_PMC_HAS_LAST_MILE_REGULATOR */

/*! @} */

/*!
 * @name POWER PMC event detect interface
 * @{
 */

/*!
 * @brief Get the PMC event flag.
 *
 * @return The event flags. This is the logical OR of members of the
 *         enumeration ::pmc_event_flag_t
 */
static inline uint32_t POWER_GetPMCEventFlags(void)
{
    return (PMC->LVSC & (uint32_t)kPMC_AllEventFlags);
}

/*!
 * @brief Clear the event flag.
 *
 * @param mask    The event flags to clear. This is a logical OR of members of
 * the enumeration ::pmc_event_flag_t
 */
static inline void POWER_ClearPMCEventFlags(uint32_t mask)
{
    mask &= (uint32_t)kPMC_AllEventFlags;
    PMC->LVSC = mask;
}

/*!
 * @brief Get the voltage detect status.
 *
 * @return The voltage detect status. This is the logical OR of members of the
 *         enumeration ::pmc_voltage_detect_status_t
 */
static inline uint32_t POWER_GetVoltageDetectStatus(void)
{
    return (PMC->LVSC & (uint32_t)kPMC_AllVoltageDetectStatus);
}

/*! @} */

/*!
 * @name POWER PMC interrupt Interface
 * @{
 */

/*!
 * @brief Enable POWER PMC voltage detect interrupt.
 *
 * @param mask    The interrupts to enable. This is a logical OR of members of
 * the enumeration ::pmc_interrupt_enable_t
 */
static inline void POWER_EnablePMCInterrupts(uint32_t mask)
{
    mask &= (uint32_t)kPMC_AnyVoltageDetectInterruptEnable;
    PMC->CONFIG |= mask;
}

/*!
 * @brief Disable POWER PMC voltage detect interrupt.
 *
 * @param mask    The interrupts to disable. This is a logical OR of members of
 * the enumeration ::pmc_interrupt_enable_t
 */
static inline void POWER_DisablePMCInterrupts(uint32_t mask)
{
    mask &= (uint32_t)kPMC_AnyVoltageDetectInterruptEnable;
    PMC->CONFIG &= ~mask;
}

/*!
 * @brief Get PMC interrupt flags.
 *
 * @return The voltage interrupt flags. This is the logical OR of members of the
 *         enumeration ::pmc_voltage_detect_flag_t
 *
 */
static inline uint32_t POWER_GetPMCInterruptFlags(void)
{
    return (PMC->LVSC & (uint32_t)kPMC_AllVoltageDetectFlags);
}

/*!
 * @brief Clear PMC interrupt flags.
 *
 * @param mask    The interrupts to clear. This is a logical OR of members of
 * the enumeration ::pmc_voltage_detect_flag_t
 *
 */
static inline void POWER_ClearPMCInterruptFlags(uint32_t mask)
{
    mask &= (uint32_t)kPMC_AllVoltageDetectFlags;
    PMC->LVSC = mask;
}

/*! @} */

/*!
 * @name POWER PMC misc
 * @{
 */

/*!
 * @brief Gets the POWER PMC version id.
 *
 * This function gets the PMC version id including whether the PMC supports last
 * mile regulator.
 *
 * @param versionId         Pointer to pmc_version_id_t structure.
 */
void POWER_GetPMCVersionID(pmc_version_id_t *versionId);

/*! @} */

/*!
 * @name POWER power mode switch APIs
 * @{
 */

/*!
 * @brief Check previous mode is standby mode or not.
 *
 * @return true if previous mode is standby mode, false if previous mode is
 * reset mode.
 */
static inline bool POWER_ExitFromStandbyMode(void)
{
    if (kMC_ME_PreviousStandbyMode == (MC_ME->MODE_STAT & MC_ME_MODE_STAT_PREV_MODE_MASK))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * @brief Request to enter standby mode.
 */
void POWER_EnterStandbyMode(void);

/*!
 * @brief Request destructive or functional reset mode transition.
 *
 * @param resetType Reset type, see ref mc_me_reset_type_t.
 */
void POWER_RequestResetMode(mc_me_reset_type_t resetType);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* _FSL_POWER_H_*/
