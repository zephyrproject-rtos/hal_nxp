/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_advc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.advc"
#endif

#define ADVC_OPTIMAL_CFG_CLOCK_MASK (0xFFF9UL)

typedef enum _advc_state
{
    kADVC_NotInitalized = 0U,
    kADVC_Initalized    = 1U,
} advc_state_t;

typedef enum
{
    ADVC_STATUS_OK,                         /*< ADVC returns OK */
    ADVC_STATUS_INIT,                       /*< ADVC init status  */
    ADVC_STATUS_SAFE_DONE_FAILED,           /*< ADVC safe was not done  */
    ADVC_STATUS_TIMEOUT,                    /*< ADVC status done condition was not set before timeout  */
    ADVC_STATUS_RINGO_MEASURE_FAILED,       /*< RINGO measurement failed */
    ADVC_STATUS_FF_MEASURE_FAILED,          /*< First fail measurement failed */
    ADVC_STATUS_OPTIMAL_FAILED,             /*< ADVC set optimal ended with error */
    ADVC_STATUS_BAD_SIGNATURE,              /*< ADVC table value  */
    ADVC_STATUS_IS_NOT_ENABLED,             /*< when trying to manipulate advc frequencies before it's enabled  */
    ADVC_STATUS_PRE_VOLTAGE_REQUEST_FAILED, /*< when pre-voltage request change is reaching timeout  */
    ADVC_STATUS_ILLEGAL_OPERATION,          /*< When using illegal operation mode in ADVC_ENABLE */
} ADVC_STATUS_t;

typedef enum ADVC_MODE
{
    ADVC_MODE_SAFE            = 0,
    ADVC_MODE_PRODUCTION_TEST = 1,
    ADVC_MODE_OPTIMAL         = 2,
    ADVC_MODE_SW              = 3,
} ADVC_MODE_t;

typedef enum ADVC_FREQUENCY_CODE
{
    ADVC_FREQUENCY_CODE_10MHZ  = 0, /**< 10 MHz, from FRO 10MHZ */
    ADVC_FREQUENCY_CODE_5MHZ   = 1, /*< 5 MHz, from FRO 10MHZ */
    ADVC_FREQUENCY_CODE_3P3MHZ = 2, /*< 3.3P3MHZ MHz, from FRO 10MHZ */
    ADVC_FREQUENCY_CODE_2P5MHZ = 3, /*< 2.5P3MHZ MHz, from FRO 10MHZ */
    ADVC_FREQUENCY_CODE_2MHZ   = 4, /*< 2MHZ MHz, from FRO 2MHZ */
    ADVC_FREQUENCY_CODE_1MHZ   = 5, /*< 1MHZ MHz, from FRO 2MHZ */
} ADVC_FREQUENCY_CODE_t;

/**
 * @brief defines safe_mode_parameters
 */
typedef struct ADVC_SAFE_CONFIG_s
{
    bool should_write_to_dc2dc;           /*< should write to dc2dc or not */
    ADVC_FREQUENCY_CODE_t frequency_code; /*< frequency code , @see ADVC_FREQUENCY_CODE_t for details */
} ADVC_SAFE_CONFIG_t;

/**
 * @brief defines optimal_mode_parameters
 */
typedef struct ADVC_OPTIMAL_CONFIG
{
    bool is_sw_mode;
    bool should_write_to_dc2dc;
    bool should_use_spare_function;
    bool is_external_temperature;
    uint32_t clocks_mask;
} ADVC_OPTIMAL_CONFIG_t;

/**
 * @brief defines advc enable mode paratemers to safe/optimal
 */
typedef union
{
    ADVC_SAFE_CONFIG_t advc_safe_config;       /*< advc_safe_config @see ADVC_SAFE_CONFIG_t for details */
    ADVC_OPTIMAL_CONFIG_t advc_optimal_config; /*< advc_optimal_config @see ADVC_OPTIMAL_CONFIG_t for details */
} ADVC_ENABLE_CONFIG_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
extern void ADVC_DRIVER_init(uint32_t table_address);
extern ADVC_STATUS_t ADVC_DRIVER_Enable(ADVC_MODE_t advc_mode, ADVC_ENABLE_CONFIG_t *advc_enable_config, uint8_t *code);
extern void ADVC_DRIVER_Disable();
extern ADVC_STATUS_t ADVC_DRIVER_convert_frequency_to_code(uint32_t frequency_in_Hz,
                                                           ADVC_FREQUENCY_CODE_t *frequency_code);
extern ADVC_STATUS_t ADVC_DRIVER_pre_voltage_change_request(ADVC_FREQUENCY_CODE_t frequency);
extern ADVC_STATUS_t ADVC_DRIVER_post_voltage_change_request();
extern bool ADVC_DRIVER_is_ADVC_enabled();
/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile advc_state_t g_advcState = kADVC_NotInitalized;

/*******************************************************************************
 * Code
 ******************************************************************************/
static bool ADVC_CheckAONApbClockEnabled(void)
{
    if ((AON__CGU->PER_CLK_EN & CGU_PER_CLK_EN_APB_CLK_MASK) != 0UL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*!
 * Check whether systick is enabled, if not enable it.
 */
static bool ADVC_CheckSystickEnabled(void)
{
  bool enabled = ((SysTick->CTRL & SysTick_CTRL_ENABLE_Msk) != 0UL) ? true : false;
  
  if (enabled == false)
  {
      SysTick->LOAD = 0xFFFFFFL;
      SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
  }
  
  return enabled;
}

/*!
 * @brief Restore configuration of systick.
 * 
 * @param enabled Indicated if systick is pre-enabled.
 */
static void ADVC_RestoreSystickConfig(bool enabled)
{
   if (enabled == false)
   {
      SysTick->LOAD = 0U;
      SysTick->CTRL &= ~(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk);
   }
}

/*!
 * brief Load advc configuration table and initialize ADVC.
 */
#if __CORTEX_M == 33U
void ADVC_Init(void)
{
    bool isSystickEnabled = ADVC_CheckSystickEnabled();
    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();

    ADVC_DRIVER_init(FSL_FEATURE_ADVC_CFG_TABLE_ADDR);

    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }
    ADVC_RestoreSystickConfig(isSystickEnabled);
    g_advcState = kADVC_Initalized;
}
#endif /* __CORTEX_M == 33U */

/*!
 * brief Check if ADVC is initialized.
 *
 * retval false ADVC is not initialized.
 * retval true ADVC is initialized.
 */
bool ADVC_IsInitalized(void)
{
    return (bool)(g_advcState == kADVC_Initalized);
}

/*!
 * brief Enable ADVC
 *
 * param[in] mode Specify the mode of advc, please refer to advc_mode_t.
 * param[out] vddCode The value of VDD.
 *
 * return The result outcome with enabling ADVC.
 */
advc_result_t ADVC_Enable(advc_mode_t mode, uint8_t *vddCode)
{
    ADVC_ENABLE_CONFIG_t advcEnableConfig;
    ADVC_STATUS_t status;

    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();

    if (mode == kADVC_ModeSafe)
    {
        advcEnableConfig.advc_safe_config.frequency_code        = ADVC_FREQUENCY_CODE_10MHZ;
        advcEnableConfig.advc_safe_config.should_write_to_dc2dc = true;
    }
    else if (mode == kADVC_ModeOptimal)
    {
        advcEnableConfig.advc_optimal_config.clocks_mask               = ADVC_OPTIMAL_CFG_CLOCK_MASK;
        advcEnableConfig.advc_optimal_config.is_external_temperature   = false;
        advcEnableConfig.advc_optimal_config.is_sw_mode                = false;
        advcEnableConfig.advc_optimal_config.should_use_spare_function = true;
        advcEnableConfig.advc_optimal_config.should_write_to_dc2dc     = true;
    }
    else
    {
        /* To avoid violation of MISRA rule. */
    }

    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    if (vddCode == NULL)
    {
        uint8_t tmp8 = 0U;
        status       = ADVC_DRIVER_Enable((ADVC_MODE_t)mode, &advcEnableConfig, &tmp8);
        (void)tmp8;
    }
    else
    {
        status = ADVC_DRIVER_Enable((ADVC_MODE_t)mode, &advcEnableConfig, vddCode);
    }
    ADVC_RestoreSystickConfig(isSystickEnabled);

    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }

    return (advc_result_t)status;
}

/*!
 * brief Check if ADVC is enabled.
 *
 * retval false ADVC is not enabled.
 * retval true ADVC is enabled.
 */
bool ADVC_IsEnabled(void)
{
    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();
    bool ret               = false;
    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    ret = ADVC_DRIVER_is_ADVC_enabled();

    ADVC_RestoreSystickConfig(isSystickEnabled);
    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }
    return ret;
}

/*!
 * brief Disable ADVC.
 */
void ADVC_Disable(void)
{
    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();
    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    ADVC_DRIVER_Disable();

    ADVC_RestoreSystickConfig(isSystickEnabled);
    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }
}

/*!
 * brief Check if ADVC is disabled.
 *
 * retval true ADVC is not disabled.
 * retval false ADVC is enabled.
 */
bool ADVC_IsDisabled(void)
{
    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();
    bool ret               = false;
    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    ret = !(ADVC_DRIVER_is_ADVC_enabled());

    ADVC_RestoreSystickConfig(isSystickEnabled);
    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }
    return ret;
}

/*!
 * brief Request to change frequency.
 *
 * note This should be done every time we want to change frequency of any ADVC related clock.
 *
 * param aonCpuFreq The frequency of AON CPU, only 10MHz, 5MHz, 3.3MHz, 2.5MHz, 2MHz, 1MHz are allowed.
 *
 * return The result outcome with requesting to change frequency.
 */
advc_result_t ADVC_PreVoltageChangeRequest(uint32_t aonCpuFreq)
{
    ADVC_FREQUENCY_CODE_t advcFreqCode;
    ADVC_STATUS_t status;

    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();
    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    status                 = ADVC_DRIVER_convert_frequency_to_code(aonCpuFreq, &advcFreqCode);

    if (status == ADVC_STATUS_OK)
    {
        status = ADVC_DRIVER_pre_voltage_change_request(advcFreqCode);
    }

    ADVC_RestoreSystickConfig(isSystickEnabled);

    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }
    return (advc_result_t)status;
}

/*!
 * brief Move back to optimal after changing any ADVC related clock frequency.
 *
 * return The observed result following the post-frequency change.
 */
advc_result_t ADVC_PostVoltageChangeRequest(void)
{
    ADVC_STATUS_t status;
    bool isAhbClockEnabled = ADVC_CheckAONApbClockEnabled();
    bool isSystickEnabled = ADVC_CheckSystickEnabled();

    status = ADVC_DRIVER_post_voltage_change_request();

    ADVC_RestoreSystickConfig(isSystickEnabled);
    if (isAhbClockEnabled)
    {
        AON__CGU->PER_CLK_EN |= CGU_PER_CLK_EN_APB_CLK_MASK;
    }

    return (advc_result_t)status;
}
