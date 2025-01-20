/*
 * Copyright 2023-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_TEMPSENSOR_H_
#define FSL_TEMPSENSOR_H_

#include "fsl_common.h"

/*!
 * @addtogroup tempsensor
 *
 * @note The tempsensor has non-secure registers and secure registers, the secure registers' address is offset by more
 * than 0x200 relative to the peripheral base address. Before accessing secure registers, make sure you have permission
 * before accessing secure registers. In the tempsensor driver, those with 'secure' in the name are used to access
 * secure registers, and those with 'nonsecure' are used to access non-secure registers, before using these enumerations
 * and functions, make sure you have the permission.
 *
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version
 * @{
 */
/*! @brief Tempsensor driver version 2.0.1. */
#define FSL_TEMPSENSOR_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*!
 * @}
 */

#define TMPSNS_CTRL_THR_MODE_MASK(index) \
    ((uint32_t)((uint32_t)TMPSNS_CTRL0_THR0_MODE_MASK << (((uint32_t)(index) % 4U) * 2U)))
#define TMPSNS_CTRL_THR_MODE_SHIFT(index) (TMPSNS_CTRL0_THR0_MODE_SHIFT + (((uint32_t)(index) % 4U) * 2U))
#define TMPSNS_CTRL_THR_MODE(index, mode) \
    (((uint32_t)(((uint32_t)(mode)) << TMPSNS_CTRL_THR_MODE_SHIFT(index))) & TMPSNS_CTRL_THR_MODE_MASK(index))

#define TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(index) \
    ((uint32_t)((uint32_t)TMPSNS_THR_CTRL01_TEMPERATURE_THRESHOLD0_MASK << (((uint32_t)(index) % 2U) * 16U)))
#define TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_SHIFT(index) \
    (TMPSNS_THR_CTRL01_TEMPERATURE_THRESHOLD0_SHIFT + (((uint32_t)(index) % 2U) * 16U))
#define TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD(index, value)                                    \
    (((uint32_t)(((uint32_t)(value)) << TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_SHIFT(index))) & \
     TMPSNS_THR_CTRL_TEMPERATURE_THRESHOLD_MASK(index))
/*!
 * @brief This enumeration provides the type of tempsensor interrupt enablement.
 *
 * @note The threshold 0 interrupt is connected to the SRC.
 */
enum _tmpsns_nonsecure_int_enable
{
    /*! Enable interrupt output event for the threshold0 comparator event. */
    kTMPSNS_NonSecure_Threshold0CmpIntEnable = TMPSNS_CTRL0_THR0_IE_MASK,
    /*! Enable interrupt output event for the threshold1 comparator event. */
    kTMPSNS_NonSecure_Threshold1CmpIntEnable = TMPSNS_CTRL0_THR1_IE_MASK,
    /*! Enable interrupt output event for the threshold2 comparator event. */
    kTMPSNS_NonSecure_Threshold2CmpIntEnable = TMPSNS_CTRL0_THR2_IE_MASK,
    /*! Enable interrupt output event when output data0 is ready after measurement completion. */
    kTMPSNS_NonSecure_DataReady0IntEnable = TMPSNS_CTRL0_DRDY0_IE_MASK,

    /*! Enable threshold 0, 1, 2, and data ready 0 interrupts. */
    kTMPSNS_NonSecure_AllIntEnable =
        (kTMPSNS_NonSecure_Threshold0CmpIntEnable | kTMPSNS_NonSecure_Threshold1CmpIntEnable |
         kTMPSNS_NonSecure_Threshold2CmpIntEnable | kTMPSNS_NonSecure_DataReady0IntEnable),
};

/*!
 * @brief This enumeration provides the type of tempsensor interrupt enablement.
 */
enum _tmpsns_secure_int_enable
{
    /*! Enable interrupt output event for the threshold4 comparator event. */
    kTMPSNS_Secure_Threshold4CmpIntEnable = TMPSNS_CTRL1_THR4_IE_MASK,
    /*! Enable interrupt output event for the threshold5 comparator event. */
    kTMPSNS_Secure_Threshold5CmpIntEnable = TMPSNS_CTRL1_THR5_IE_MASK,
    /*! Enable interrupt output event when output data1 is ready after measurement completion. */
    kTMPSNS_Secure_DataReady1IntEnable = TMPSNS_CTRL1_DRDY1_IE_MASK,

    /*! Enable thresholds 4, 5, and data ready 1 interrupt. */
    kTMPSNS_Secure_AllIntEnable = (kTMPSNS_Secure_Threshold4CmpIntEnable | kTMPSNS_Secure_Threshold5CmpIntEnable |
                                   kTMPSNS_Secure_DataReady1IntEnable),
};

/*!
 * @brief This enumeration provides tempsensor status flags.
 */
enum _tmpsns_nonsecure_status
{
    /*! Indicate whether the tempsensor is in an idle state or undergoing conversion. */
    kTMPSNS_NonSecure_Idle0 = TMPSNS_STAT0_IDLE_MASK,

    /*! Indicate whether new data is available on DATA0[DATA_VAL]. */
    kTMPSNS_NonSecure_DataReady0 = TMPSNS_STAT0_DRDY0_IF_MASK,

    /*! Indicate the state of the threshold0 comparator. */
    kTMPSNS_NonSecure_Threshold0CmpStatus = TMPSNS_STAT0_THR0_IF_MASK,
    /*! Indicate the state of the threshold1 comparator. */
    kTMPSNS_NonSecure_Threshold1CmpStatus = TMPSNS_STAT0_THR1_IF_MASK,
    /*! Indicate the state of the threshold2 comparator. */
    kTMPSNS_NonSecure_Threshold2CmpStatus = TMPSNS_STAT0_THR2_IF_MASK,

    /*! Indicate whether a threshold0 comparator event (interrupt) occurred. */
    kTMPSNS_NonSecure_Threshold0IntStatus = TMPSNS_STAT0_THR0_STAT_MASK,
    /*! Indicate whether a threshold1 comparator event (interrupt) occurred. */
    kTMPSNS_NonSecure_Threshold1IntStatus = TMPSNS_STAT0_THR1_STAT_MASK,
    /*! Indicate whether a threshold2 comparator event (interrupt) occurred. */
    kTMPSNS_NonSecure_Threshold2IntStatus = TMPSNS_STAT0_THR2_STAT_MASK,
};

/*!
 * @brief This enumeration provides tempsensor status flags.
 */
enum _tmpsns_secure_status
{
    /*! Indicate whether the tempsensor is in an idle state or undergoing conversion. */
    kTMPSNS_Secure_Idle1 = TMPSNS_STAT1_IDLE_MASK,

    /*! Indicate whether new data is available on DATA1[DATA_VAL]. */
    kTMPSNS_Secure_DataReady1 = TMPSNS_STAT1_DRDY1_IF_MASK,

    /*! Indicate the state of the threshold4 comparator. */
    kTMPSNS_Secure_Threshold4CmpStatus = TMPSNS_STAT1_THR4_IF_MASK,
    /*! Indicate the state of the threshold5 comparator. */
    kTMPSNS_Secure_Threshold5CmpStatus = TMPSNS_STAT1_THR5_IF_MASK,

    /*! Indicate whether a threshold4 comparator event (interrupt) occurred. */
    kTMPSNS_Secure_Threshold4IntStatus = TMPSNS_STAT1_THR4_STAT_MASK,
    /*! Indicate whether a threshold5 comparator event (interrupt) occurred. */
    kTMPSNS_Secure_Threshold5IntStatus = TMPSNS_STAT1_THR5_STAT_MASK,
};

/*!
 * @brief This enumeration provides the type of tempsensor filter counter clear.
 */
enum _tmpsns_nonsecure_filter_count_clear
{
    /*! Clear the internal counter that counts the number of threshold violations corresponding to
       THR_CTRL01[TEMPERATURE_THRESHOLD0]. */
    kTMPSNS_NonSecure_Filter0CountClear = TMPSNS_CTRL0_FILT0_CNT_CLR_MASK,
    /*! Clear the internal counter that counts the number of threshold violations corresponding to
       THR_CTRL01[TEMPERATURE_THRESHOLD1]. */
    kTMPSNS_NonSecure_Filter1CountClear = TMPSNS_CTRL0_FILT1_CNT_CLR_MASK,
    /*! Clear the internal counter that counts the number of threshold violations corresponding to
       THR_CTRL23[TEMPERATURE_THRESHOLD2]. */
    kTMPSNS_NonSecure_Filter2CountClear = TMPSNS_CTRL0_FILT2_CNT_CLR_MASK,

    /*! Clear threshold 0, 1, and 2 filter count. */
    kTMPSNS_NonSecure_AllFilterCountClear = (kTMPSNS_NonSecure_Filter0CountClear | kTMPSNS_NonSecure_Filter1CountClear |
                                             kTMPSNS_NonSecure_Filter2CountClear),
};

/*!
 * @brief This enumeration provides the type of tempsensor filter counter clear.
 */
enum _tmpsns_secure_filter_count_clear
{
    /*! Clears the internal counter that counts the number of threshold violations corresponding to
       THR_CTRL45[TEMPERATURE_THRESHOLD4]. */
    kTMPSNS_Secure_Filter4CountClear = TMPSNS_CTRL1_FILT4_CNT_CLR_MASK,
    /*! Clear the internal counter that counts the number of threshold violations corresponding to
       THR_CTRL45[TEMPERATURE_THRESHOLD5]. */
    kTMPSNS_Secure_Filter5CountClear = TMPSNS_CTRL1_FILT5_CNT_CLR_MASK,

    /*! Clear thresholds 4, and 5 filter count. */
    kTMPSNS_Secure_AllFilterCountClear = (kTMPSNS_Secure_Filter4CountClear | kTMPSNS_Secure_Filter5CountClear),
};

/*!
 * @brief This enumeration provides the selection of the tempsensor resolution modes, including mode 0 (0.59325ms),
 * mode 1 (1.10525ms), mode 2 (2.12925ms), mode 3 (4.17725ms).
 */
typedef enum _tmpsns_resolution_mode
{
    kTMPSNS_ResolutionMode0 = 0x00U, /*!< 0.59325ms. */
    kTMPSNS_ResolutionMode1 = 0x01U, /*!< 1.10525ms. */
    kTMPSNS_ResolutionMode2 = 0x02U, /*!< 2.12925ms. */
    kTMPSNS_ResolutionMode3 = 0x03U, /*!< 4.17725ms. */
} tmpsns_resolution_mode_t;

/*!
 * @brief This enumeration provides the selection of the tempsensor measurement modes, including single one-shot mode,
 * continuous mode and periodic one-shot mode.
 */
typedef enum _tmpsns_measurement_mode
{
    kTMPSNS_SingleOneShotMode = 0x00U,   /*!< Measures single temperature data after you start a measurement. */
    kTMPSNS_ContinuousMode    = 0x01U,   /*!< Continues to measure temperature data repeatedly
                                              at the conversion time rate. */
    kTMPSNS_PeriodicOneShotMode = 0x02U, /*!< Measures temperature data repeatedly at a periodic interval of time. */
} tmpsns_measurement_mode_t;

/*!
 * @brief This enumeration provides the selection of the tempsensor thresholds, including thresholds 0, 1, 2, 4, and 5.
 *
 * @note Thresholds 4 and 5 are used only when secure registers can be accessed.
 */
typedef enum _tmpsns_thresholds
{
    kTMPSNS_ThresholdCmp0 = 0x00U, /*!< Threshold comparator 0. */
    kTMPSNS_ThresholdCmp1 = 0x01U, /*!< Threshold comparator 1. */
    kTMPSNS_ThresholdCmp2 = 0x02U, /*!< Threshold comparator 2. */
    kTMPSNS_ThresholdCmp4 = 0x04U, /*!< Threshold comparator 4. */
    kTMPSNS_ThresholdCmp5 = 0x05U, /*!< Threshold comparator 5. */
} tmpsns_thresholds_t;

/*!
 * @brief This enumeration provides the selection of the tempsensor threshold comparator modes, including mode 0
 * (Less than or equal to the threshold), mode 1 (Greater than the threshold), mode 2 (High to low-temperature data
 * transition at threshold) and mode 3 (Low to high-temperature data transition at threshold).
 */
typedef enum _tmpsns_threshold_cmp_mode
{
    kTMPSNS_ThresholdCmpMode0 = 0x00U, /*!< Less than or equal to the threshold. */
    kTMPSNS_ThresholdCmpMode1 = 0x01U, /*!< Greater than threshold. */
    kTMPSNS_ThresholdCmpMode2 = 0x02U, /*!< High to low temperature data transition at the threshold. */
    kTMPSNS_ThresholdCmpMode3 = 0x03U, /*!< Low to high temperature data transition at the threshold. */
} tmpsns_threshold_cmp_mode_t;

/*!
 * @brief This structure is used to configure the tempsensor module.
 *
 * @note All configurations of the tempsensor need to access secure registers (register address is offset by more
 * than 0x200 relative to the peripheral base address). Before configuring the tempsensor, make sure you have permission
 * to access these registers.
 */
typedef struct _tmpsns_config
{
    bool enableClockDivider; /*!< Decides whether to enable the clock divider. */
    uint8_t refClockDivider; /*!< Specifies the divider value for generating CONV_CLK from MODULE_CLK, the output clock
                                frequency = input clock frequency / (DIV + 1). */
    uint8_t powerUpDealy;    /*!< Sets the power-up delay on CONV_CLK for the analog block, see the chip data sheet
                                for the tempsensor power-up time. */
    tmpsns_resolution_mode_t resolutionMode;   /*!< Specifies the conversion time for different resolution modes, this
                                                  parameter helps the user configure the length of the conversion time,
                                                  longer conversion time translates into higher resolution. */
    tmpsns_measurement_mode_t measurementMode; /*!< Selects the measurement mode for the tempsensor, the mode could be
                                changed only when the tempsensor does not measure, that is, when STAT[IDLE] = 1. */
    uint32_t measurementPeriod; /*!< Sets the target count (measurement period) on CONV_CLK for periodic trigger
                                in periodic One-Shot conversion mode. */
} tmpsns_config_t;

/*!
 * @brief This structure is used to configure the tempsensor threshold.
 *
 * @note Thresholds 4 and 5 are used only when secure registers can be accessed.
 */
typedef struct _tmpsns_threshold_config
{
    tmpsns_thresholds_t thresholdIndex;           /*!< Indicates which threshold is selected. */
    tmpsns_threshold_cmp_mode_t thresholdCmpMode; /*!< Indicates which threshold comparator mode is selected. */
    float thresholdVal;                           /*!< Sets selected threshold's value. */
} tmpsns_threshold_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Tempsensor Initialization, de-initialization and configuration.
 *
 * @note The tempsensor initialization and de-initialization need to access secure registers (register address is
 * offset by more than 0x200 relative to the peripheral base address), before configuring the tempsensor, make sure
 * you have permission to access these registers.
 *
 * @{
 */
/*!
 * @brief This function is used to get predefined configurations for the tempsensor initialization.
 *
 * @param config Pointer to the tempsensor configuration structure, please refer to @ref tmpsns_config_t for details.
 */
void TMPSNS_GetDefaultConfig(tmpsns_config_t *config);

/*!
 * @brief This function is used to initialize the tempsensor.
 *
 * @param base Tempsensor peripheral base address.
 * @param config Pointer to the tempsensor configuration structure, please refer to @ref tmpsns_config_t for details.
 */
void TMPSNS_Init(TMPSNS_Type *base, const tmpsns_config_t *config);

/*!
 * @brief This function is used to de-initialize the tempsensor.
 *
 * @param base Tempsensor peripheral base address.
 */
void TMPSNS_Deinit(TMPSNS_Type *base);
/*!
 * @}
 */

/*!
 * @name Tempsensor threshold configuration.
 * @{
 */
/*!
 * @brief This function is used to configure the thresholds.
 *
 * @param base Tempsensor peripheral base address.
 * @param config Pointer to the threshold configuration structure, please refer @ref tmpsns_threshold_config_t for
 * details.
 */
void TMPSNS_NonSecure_DoThresholdConfig(TMPSNS_Type *base, const tmpsns_threshold_config_t *config);

/*!
 * @brief This function is used to configure the thresholds.
 *
 * @param base Tempsensor peripheral base address.
 * @param config Pointer to the threshold configuration structure, please refer @ref tmpsns_threshold_config_t for
 * details.
 */
void TMPSNS_Secure_DoThresholdConfig(TMPSNS_Type *base, const tmpsns_threshold_config_t *config);
/*!
 * @}
 */

/*!
 * @name Temperature acquisition, the unit is Celsius.
 * @{
 */
/*!
 * @brief This function is used to get the current temperature.
 *
 * @param base TMPSNS base pointer
 * @return Current temperature with degrees Celsius.
 */
float TMPSNS_NonSecure_GetCurrentTemperature(TMPSNS_Type *base);

/*!
 * @brief This function is used to get the current temperature.
 *
 * @param base TMPSNS base pointer
 * @return Current temperature with degrees Celsius.
 */
float TMPSNS_Secure_GetCurrentTemperature(TMPSNS_Type *base);
/*!
 * @}
 */

/*!
 * @name Tempsensor enable and disable, temperature measurement start and stop.
 * @{
 */
/*!
 * @brief This function is used to enable the tempsensor.
 *
 * @param base Tempsensor peripheral base address.
 */
static inline void TMPSNS_EnableTmpsns(TMPSNS_Type *base)
{
    base->CTRL1_SET = TMPSNS_CTRL1_ENABLE_MASK;
}

/*!
 * @brief This function is used to disable the tempsensor.
 *
 * @param base Tempsensor peripheral base address.
 */
static inline void TMPSNS_DisableTmpsns(TMPSNS_Type *base)
{
    base->CTRL1_CLR = TMPSNS_CTRL1_ENABLE_MASK;
}

/*!
 * @brief This function is used to start the temperature measurement process.
 *
 * @param base Tempsensor peripheral base address.
 */
static inline void TMPSNS_StartMeasurement(TMPSNS_Type *base)
{
    base->CTRL1_SET = TMPSNS_CTRL1_START_MASK;
}

/*!
 * @brief This function is used to stop the temperature measurement process.
 *
 * @param base Tempsensor peripheral base address.
 */
static inline void TMPSNS_StopMeasurement(TMPSNS_Type *base)
{
    base->CTRL1_SET = TMPSNS_CTRL1_STOP_MASK;
}
/*!
 * @}
 */

/*!
 * @name Tempsensor interrupts and status.
 * @{
 */
/*!
 * @brief This function is used to enable the tempsensor interrupts.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for interrupts, please refer @ref _tmpsns_nonsecure_int_enable for details.
 */
static inline void TMPSNS_NonSecure_EnableTmpsnsInt(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL0_SET = mask;
}

/*!
 * @brief This function is used to enable the tempsensor interrupts.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for interrupts, please refer @ref _tmpsns_secure_int_enable for details.
 */
static inline void TMPSNS_Secure_EnableTmpsnsInt(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL1_SET = mask;
}

/*!
 * @brief This function is used to disable the tempsensor interrupts.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for interrupts, please refer @ref _tmpsns_nonsecure_int_enable for details.
 */
static inline void TMPSNS_NonSecure_DisableTmpsnsInt(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL0_CLR = mask;
}

/*!
 * @brief This function is used to disable the tempsensor interrupts.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for interrupts, please refer @ref _tmpsns_secure_int_enable for details.
 */
static inline void TMPSNS_Secure_DisableTmpsnsInt(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL1_CLR = mask;
}

/*!
 * @brief This function clears the tempsensor threshold interrupt status flags.
 *
 * @note The @p mask can using member @c kTMPSNS_NonSecure_Threshold0IntStatus to clean threshold 0
 * interrupt flag, using member @c kTMPSNS_NonSecure_Threshold1IntStatus to clean threshold 1 interrupt
 * flag, and use member @c kTMPSNS_NonSecure_Threshold2IntStatus to clear threshold 2 interrupt. The
 * data ready 0 interrupt flag cannot be cleaned using this function.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer to @ref _tmpsns_nonsecure_status for details.
 */
static inline void TMPSNS_NonSecure_ClearTmpsnsIntStatus(TMPSNS_Type *base, uint32_t mask)
{
    base->STAT0_CLR = mask;
}

/*!
 * @brief This function clears the tempsensor threshold interrupt status flags.
 *
 * @note The @p mask can using member @c kTMPSNS_Secure_Threshold4IntStatus to clean threshold 4
 * interrupt flag and using member @c kTMPSNS_Secure_Threshold5IntStatus to clear threshold 5 interrupt.
 * The data ready 1 interrupt flag cannot be cleaned using this function.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer to @ref _tmpsns_secure_status for details.
 */
static inline void TMPSNS_Secure_ClearTmpsnsIntStatus(TMPSNS_Type *base, uint32_t mask)
{
    base->STAT1_CLR = mask;
}

/*!
 * @brief This function is used to get the tempsensor status.
 *
 * @param base Tempsensor peripheral base address.
 *
 * @return tempsensor status mask.
 */
static inline uint32_t TMPSNS_NonSecure_GetTmpsnsStatus(TMPSNS_Type *base)
{
    return base->STAT0;
}

/*!
 * @brief This function is used to get the tempsensor status.
 *
 * @param base Tempsensor peripheral base address.
 *
 * @return tempsensor status mask.
 */
static inline uint32_t TMPSNS_Secure_GetTmpsnsStatus(TMPSNS_Type *base)
{
    return base->STAT1;
}
/*!
 * @}
 */

/*!
 * @name Tempsensor misc.
 * @{
 */
/*!
 * @brief This function is used to set the tempsensor filter length.
 *
 * @param base Tempsensor peripheral base address.
 * @param length Filter length to be set.
 */
static inline void TMPSNS_NonSecure_SetFilterLength(TMPSNS_Type *base, uint8_t length)
{
    base->CTRL0_CLR = TMPSNS_CTRL0_N_FILT_0_MASK;
    base->CTRL0_SET = TMPSNS_CTRL0_N_FILT_0(length);
}

/*!
 * @brief This function is used to set the tempsensor filter length.
 *
 * @param base Tempsensor peripheral base address.
 * @param length Filter length to be set.
 */
static inline void TMPSNS_Secure_SetFilterLength(TMPSNS_Type *base, uint8_t length)
{
    base->CTRL1_CLR = TMPSNS_CTRL1_N_FILT_1_MASK;
    base->CTRL1_SET = TMPSNS_CTRL1_N_FILT_1(length);
}

/*!
 * @brief This function is used to clear the tempsensor filter count.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer @ref _tmpsns_nonsecure_filter_count_clear for details.
 */
static inline void TMPSNS_NonSecure_ClearFilterCount(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL0_SET = mask;
    __ISB();
    __DSB();
    base->CTRL0_CLR = mask;
}

/*!
 * @brief This function is used to clear the tempsensor filter count.
 *
 * @param base Tempsensor peripheral base address.
 * @param mask Mask value for flags to be cleared, please refer @ref _tmpsns_secure_filter_count_clear for details.
 */
static inline void TMPSNS_Secure_ClearFilterCount(TMPSNS_Type *base, uint32_t mask)
{
    base->CTRL1_SET = mask;
    __ISB();
    __DSB();
    base->CTRL1_CLR = mask;
}

/*!
 * @brief This function is used to set the trim values.
 *
 * @param base Tempsensor peripheral base address.
 * @param valA Controls trimming code, VAL_A, for the analog block.
 * @param valB Controls trimming code, VAL_B, for the analog block.
 * @param valAlpha Controls trimming code, VAL_ALPHA, for the analog block.
 * @param valOffset Controls trimming code, VAL_OFFSET, for the analog block.
 */
static inline void TMPSNS_Secure_SetTrimVal(
    TMPSNS_Type *base, uint16_t valA, int16_t valB, uint16_t valAlpha, int16_t valOffset)
{
    base->TRIM1_CLR = (TMPSNS_TRIM1_VAL_A_MASK | TMPSNS_TRIM1_VAL_B_MASK);
    base->TRIM1_SET = (TMPSNS_TRIM1_VAL_A(valA) | TMPSNS_TRIM1_VAL_B(valB));

    base->TRIM2_CLR = (TMPSNS_TRIM2_VAL_ALPHA_MASK | TMPSNS_TRIM2_VAL_OFFSET_MASK);
    base->TRIM2_SET = (TMPSNS_TRIM2_VAL_ALPHA(valAlpha) | TMPSNS_TRIM2_VAL_OFFSET(valOffset));
}
/*!
 * @}
 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_TEMPSENSOR_H_ */
