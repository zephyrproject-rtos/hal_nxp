/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DCM_GPR_H_
#define FSL_DCM_GPR_H_

#include "fsl_common.h"

/*!
 * @addtogroup dcm_gpr
 * @{
 */

 /*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */

/*! @brief DCM_GPR driver version 2.0.0. */
#define FSL_DCM_GPR_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*!
 * @brief Disable debug mode for module.
 */
enum _disable_debug_mode_for_module
{
    kDCM_GPR_disableEdmaDebug     = DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_MASK, /*!< EDMA remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableFccuDebug     = DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_MASK, /*!< FCCU remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLcu0Debug     = DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_MASK, /*!< LCU0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLcu1Debug     = DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_MASK, /*!< LCU1 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableEmios0Debug   = DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_MASK, /*!< eMIOS0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableEmios1Debug   = DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_MASK, /*!< eMIOS1 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_EMIOS2_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_EMIOS2_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableEmios2Debug   = DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0_MASK, /*!< eMIOS2 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_EMIOS2_DBG_DIS_CM7_0 */
    kDCM_GPR_disableRtcDebug      = DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_MASK, /*!< RTC remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableSwt0Debug     = DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_MASK, /*!< SWT0 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SWT1_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SWT1_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableSwt1Debug     = DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0_MASK, /*!< SWT1 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SWT1_DBG_DIS_CM7_0 */
    kDCM_GPR_disableStm0Debug     = DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_MASK, /*!< STM0 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_STM1_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_STM1_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableStm1Debug     = DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0_MASK, /*!< STM1 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_STM1_DBG_DIS_CM7_0 */
    kDCM_GPR_disablePit0Debug     = DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_MASK, /*!< PIT0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disablePit1Debug     = DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_MASK, /*!< PIT1 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_PIT2_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_PIT2_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disablePit2Debug     = DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0_MASK, /*!< PIT2 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_PIT2_DBG_DIS_CM7_0 */
    kDCM_GPR_disableLpspi0Debug   = DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_MASK, /*!< LPSPI0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLpspi1Debug   = DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_MASK, /*!< LPSPI1 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLpspi2Debug   = DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_MASK, /*!< LPSPI2 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLpspi3Debug   = DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_MASK, /*!< LPSPI3 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI4_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI4_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableLpspi4Debug   = DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0_MASK, /*!< LPSPI4 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI4_DBG_DIS_CM7_0 */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI5_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI5_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableLpspi5Debug   = DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0_MASK, /*!< LPSPI5 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_LPSPI5_DBG_DIS_CM7_0 */
    kDCM_GPR_disableLpi2c0Debug   = DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_MASK, /*!< LPI2C0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableLpi2c1Debug   = DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_MASK, /*!< LPI2C1 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableFlexioDebug   = DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_MASK, /*!< FLEXIO remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableFlexcan0Debug = DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN0 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableFlexcan1Debug = DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN1 remains functional and is not impacted when CM7_0 enters debug mode. */
    kDCM_GPR_disableFlexcan2Debug = DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN2 remains functional and is not impacted when CM7_0 enters debug mode. */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableFlexcan3Debug = DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN3 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0 */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableFlexcan4Debug = DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN4 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0 */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableFlexcan5Debug = DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0_MASK, /*!< FLEXCAN5 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0 */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI0_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI0_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableSai0Debug     = DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0_MASK, /*!< SAI0 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI0_DBG_DIS_CM7_0 */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI1_DBG_DIS_CM7_0) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI1_DBG_DIS_CM7_0 != 0U)
    kDCM_GPR_disableSai1Debug     = DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0_MASK  /*!< SAI1 remains functional and is not impacted when CM7_0 enters debug mode. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWD6_SAI1_DBG_DIS_CM7_0 */
};

/*!
 * @brief The source of voltage used by ADC for supply monitoring.
 */
typedef enum _internal_supply_monitor_source
{
    kDCM_GPR_VDD_HV_A_DIV = (uint8_t)(0U), /*!< VDD_HV_A divider supply monitoring. */
    kDCM_GPR_VDD_HV_B_DIV = (uint8_t)(1U), /*!< VDD_HV_B divider supply monitoring. */
    kDCM_GPR_VDD_V15_DIV  = (uint8_t)(2U), /*!< VDD 1.5V divider supply monitoring. */
    kDCM_GPR_VDD_V25_OSC  = (uint8_t)(3U), /*!< VDD 2.5V supply monitoring. */
    kDCM_GPR_VDD_V11_PD1H = (uint8_t)(4U), /*!< VDD 1.1V PD1 Hot point supply monitoring. */
    kDCM_GPR_VDD_V11_PD1C = (uint8_t)(5U), /*!< VDD 1.1V PD1 Cold point supply monitoring. */
    kDCM_GPR_VDD_V11_PLL  = (uint8_t)(6U), /*!< VDD 1.1V PLL supply monitoring. */
    kDCM_GPR_VDD_V11_PD0  = (uint8_t)(7U)  /*!< VDD 1.1V PD0 supply monitoring. */
} internal_supply_monitor_source_t;

/*!
 * @brief Standby exit configuration.
 */
typedef struct _standby_exit_config
{
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT != 0U)
    bool bypassSircTriming;                 /*!< Bypass SIRC trimming. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT */
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT != 0U)
    bool bypassPmcTrimingAndRgmDcfLoading;  /*!< Bypass PMC trimming and RGM DCF loading. */
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT */
    bool bypassFircTriming;                 /*!< Bypass FIRC trimming. */
    bool enableFastStandbyExit;             /*!< Enable fast standby exit. */
    uint32_t fastStandbyExitBootAddress;    /*!< Cortex-M7_0 base address of vector table to be used after exiting Standby mode. */
} standby_exit_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name DCM_GPR module control
 * @{
 */

/*!
 * @brief Disable debug mode for module when CM7_0 enters debug mode.
 *
 * @param mask The mask of modules to be disabled debug mode. Use the OR'ed value of @ref _disable_debug_mode_for_module.
 */
static inline void DCM_GPR_DisableDebugModeForModule(uint32_t mask)
{
    DCM_GPR->DCMRWD6 |= mask;
}
/*! @}*/

/*!
 * @name DCM_GPR standby configuration
 * @{
 */

/*!
 * @brief Controls the IO state before entering standby mode.
 */
static inline void DCM_GPR_StandbyEntryIoConfig(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK;
}

/*!
 * @brief Controls the IO state after exiting standby mode.
 */
static inline void DCM_GPR_StandbyExitIoConfig(void)
{
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK;
}

/*!
 * @brief Configure the standby exit.
 *
 * @param config The configuration of standby exit. @ref standby_exit_config_t.
 */
void DCM_GPR_StandbyExitConfig(const standby_exit_config_t *config);
/*! @}*/

/*!
 * @name DCM_GPR internal supply voltage monitor
 * @{
 */

/*!
 * @brief Enable the supply voltage monitoring by ADC.
 *
 * @note For divider sources, remeber to enable them before monitoring.
 *
 * @param source The source of voltage used by ADC for supply monitoring. @ref internal_supply_monitor_source_t.
 */
static inline void DCM_GPR_EnableSupplyVoltageMonitor(internal_supply_monitor_source_t source)
{
    DCM_GPR->DCMRWF1 &= ~(DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_MASK);
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_SUPPLY_MON_SEL(source);
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK;
}

/*!
 * @brief Disable the supply voltage monitoring by ADC.
 */
static inline void DCM_GPR_DisableSupplyVoltageMonitor(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK;
}

/*!
 * @brief Enable the VSS_LV divider.
 */
static inline void DCM_GPR_EnableVssLvMonitor(void)
{
    DCM_GPR_DisableSupplyVoltageMonitor();
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_MASK;
}

/*!
 * @brief Disable the VSS_LV divider.
 */
static inline void DCM_GPR_DisableVssLvMonitor(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_MASK;
}

/*!
 * @brief Enable the VSS_HV_A divider.
 */
static inline void DCM_GPR_EnableHvADivider(void)
{
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK;
}

/*!
 * @brief Disable the VSS_HV_A divider.
 */
static inline void DCM_GPR_DisableHvADivider(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK;
}

#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_HV_B_VLT_DVDR_EN) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_HV_B_VLT_DVDR_EN != 0U)
/*!
 * @brief Enable the VSS_HV_B divider.
 */
static inline void DCM_GPR_EnableHvBDivider(void)
{
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_MASK;
}

/*!
 * @brief Disable the VSS_HV_B divider.
 */
static inline void DCM_GPR_DisableHvBDivider(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_MASK;
}
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_HV_B_VLT_DVDR_EN */

#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_1_5_VLT_DVDR_EN) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_1_5_VLT_DVDR_EN != 0U)
/*!
 * @brief Enable the VDD_1.5_DIV divider.
 */
static inline void DCM_GPR_EnableV15Divider(void)
{
    DCM_GPR->DCMRWF1 |= DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_MASK;
}

/*1
 * @brief Disable the VDD_1.5_DIV divider.
 */
static inline void DCM_GPR_DisableV15Divider(void)
{
    DCM_GPR->DCMRWF1 &= ~DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_MASK;
}
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF1_VDD_1_5_VLT_DVDR_EN */
/*! @}*/

/*!
 * @}
 */
#if defined(__cplusplus)
}
#endif
#endif /* FSL_DCM_GPR_H_ */
