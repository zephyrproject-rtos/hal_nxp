/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_AUDMIX_H_
#define FSL_AUDMIX_H_

#include "fsl_common.h"

/*!
 * @addtogroup audmix_driver AUDMIX Driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_AUDMIX_DRIVER_VERSION (MAKE_VERSION(1, 0, 0)) /*!< Version 1.0.0 */
/*! @} */

/*! @brief _audmix_status_t, AUDMIX return status.*/
enum
{
    kStatus_AUDMIX_Busy = MAKE_STATUS(kStatusGroup_AUDMIX, 0), /*!< AUDMIX is busy */
    kStatus_AUDMIX_Error = MAKE_STATUS(kStatusGroup_AUDMIX, 1), /*!< AUDMIX error occurred */
};

/*! @brief AUDMIX output source selection */
typedef enum _audmix_output_source
{
    kAUDMIX_OutputDisabled = 0U, /*!< Output is disabled */
    kAUDMIX_OutputFromTDM1 = 1U, /*!< Output from TDM1 */
    kAUDMIX_OutputFromTDM2 = 2U, /*!< Output from TDM2 */
    kAUDMIX_OutputMixed = 3U,    /*!< Output is mixed from TDM1 and TDM2 */
} audmix_output_source_t;

/*! @brief AUDMIX mixing clock source selection */
typedef enum _audmix_mix_clock_source
{
    kAUDMIX_MixClockFromTDM1 = 0U, /*!< Mix clock from TDM1 interface */
    kAUDMIX_MixClockFromTDM2 = 1U, /*!< Mix clock from TDM2 interface */
} audmix_mix_clock_source_t;

/*! @brief AUDMIX output audio sample width */
typedef enum _audmix_output_width
{
    kAUDMIX_OutputWidth16Bit = 0U, /*!< 16-bit output width */
    kAUDMIX_OutputWidth18Bit = 1U, /*!< 18-bit output width */
    kAUDMIX_OutputWidth20Bit = 2U, /*!< 20-bit output width */
    kAUDMIX_OutputWidth24Bit = 3U, /*!< 24-bit output width */
} audmix_output_width_t;

/*! @brief AUDMIX output bit clock polarity */
typedef enum _audmix_output_clock_polarity
{
    kAUDMIX_OutputClockPolarityPositiveEdge = 0U, /*!< Output data driven on positive edge */
    kAUDMIX_OutputClockPolarityNegativeEdge = 1U, /*!< Output data driven on negative edge */
} audmix_output_clock_polarity_t;

/*! @brief AUDMIX attenuation direction */
typedef enum _audmix_attenuation_direction
{
    kAUDMIX_AttenuationDirectionDown = 0U, /*!< Downward attenuation (increasing attenuation) */
    kAUDMIX_AttenuationDirectionUp = 1U,   /*!< Upward attenuation (decreasing attenuation) */
} audmix_attenuation_direction_t;

/*! @brief AUDMIX configuration structure */
typedef struct _audmix_config
{
    audmix_output_source_t outputSource;                   /*!< Output source selection */
    audmix_mix_clock_source_t mixClockSource;              /*!< Mix clock source selection */
    audmix_output_width_t outputWidth;                     /*!< Output audio sample width */
    audmix_output_clock_polarity_t outputClockPolarity;    /*!< Output bit clock polarity */
    bool maskFrameRateDiffError;                           /*!< Mask frame rate difference error */
    bool maskClockFrequencyDiffError;                      /*!< Mask clock frequency difference error */
    bool syncModeEnable;                                   /*!< Enable sync mode */
    audmix_mix_clock_source_t syncModeClockSource;         /*!< Sync mode clock source */
} audmix_config_t;

/*! @brief AUDMIX attenuation configuration structure */
typedef struct _audmix_attenuation_config
{
    bool attenuationEnable;                                /*!< Enable attenuation */
    audmix_attenuation_direction_t attenuationDirection;   /*!< Attenuation direction */
    uint16_t stepDivider;                                  /*!< Step divider value (0-4095) */
    uint32_t initialValue;                                 /*!< Initial attenuation value (18-bit) */
    uint32_t stepUpFactor;                                 /*!< Step up factor (18-bit) */
    uint32_t stepDownFactor;                               /*!< Step down factor (18-bit) */
    uint32_t stepTarget;                                   /*!< Step target value (18-bit) */
} audmix_attenuation_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /*_cplusplus*/

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes the AUDMIX peripheral.
 *
 * This API gates the AUDMIX clock. The AUDMIX module can't operate unless AUDMIX_Init is called to enable the clock.
 *
 * @param base AUDMIX base pointer.
 */
void AUDMIX_Init(WAKEUP_AUDMIX_Type *base);

/*!
 * @brief De-initializes the AUDMIX peripheral.
 *
 * This API gates the AUDMIX clock. The AUDMIX module can't operate unless AUDMIX_Init
 * is called to enable the clock.
 *
 * @param base AUDMIX base pointer.
 */
void AUDMIX_Deinit(WAKEUP_AUDMIX_Type *base);

/*!
 * @brief Gets the default configuration structure.
 *
 * This function initializes the AUDMIX configuration structure to default values.
 *
 * @param config Pointer to the configuration structure.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_GetDefaultConfig(audmix_config_t *config);

/*!
 * @brief Sets the AUDMIX configuration.
 *
 * @param base AUDMIX base pointer.
 * @param config Pointer to the configuration structure.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetConfig(WAKEUP_AUDMIX_Type *base, const audmix_config_t *config);

/*! @} */

/*!
 * @name Status
 * @{
 */

/*!
 * @brief Gets the AUDMIX status flags.
 *
 * @param base AUDMIX base pointer.
 * @return Status flags. Use the defined AUDMIX_STR_* masks to get the status value.
 *         Returns 0 if base is NULL.
 */
uint32_t AUDMIX_GetStatusFlags(WAKEUP_AUDMIX_Type *base);

/*!
 * @brief Checks if frame rates between TDM1 and TDM2 are matched.
 *
 * @param base AUDMIX base pointer.
 * @return true if frame rates match, false if mismatch or if base is NULL.
 */
bool AUDMIX_IsFrameRateMatched(WAKEUP_AUDMIX_Type *base);

/*!
 * @brief Checks if bit clock frequencies between TDM1 and TDM2 are matched.
 *
 * @param base AUDMIX base pointer.
 * @return true if bit clock frequencies match, false if mismatch or if base is NULL.
 */
bool AUDMIX_IsClockFrequencyMatched(WAKEUP_AUDMIX_Type *base);

/*!
 * @brief Gets the current mixer state.
 *
 * @param base AUDMIX base pointer.
 * @return Current mixer state (disabled, TDM1, TDM2, or mixed).
 *         Returns kAUDMIX_OutputDisabled if base is NULL.
 */
audmix_output_source_t AUDMIX_GetMixerState(WAKEUP_AUDMIX_Type *base);

/*! @} */

/*!
 * @name Attenuation Control
 * @{
 */

/*!
 * @brief Gets the default attenuation configuration structure.
 *
 * This function initializes the AUDMIX attenuation configuration structure to default values.
 *
 * @param config Pointer to the attenuation configuration structure.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_GetDefaultAttenuationConfig(audmix_attenuation_config_t *config);

/*!
 * @brief Sets the attenuation configuration for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param config Pointer to the attenuation configuration structure.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 *         Failure occurs if base or config is NULL, or if tdmChannel is not 0 or 1.
 */
status_t AUDMIX_SetAttenuationConfig(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, const audmix_attenuation_config_t *config);

/*!
 * @brief Enables or disables attenuation for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param enable true to enable, false to disable.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_EnableAttenuation(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, bool enable);

/*!
 * @brief Sets the attenuation direction for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param direction Attenuation direction (up or down).
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetAttenuationDirection(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, audmix_attenuation_direction_t direction);

/*!
 * @brief Gets the current attenuation value for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param value Pointer to store the attenuation value.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_GetAttenuationValue(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *value);

/*!
 * @brief Gets the current attenuation step counter for a specific TDM channel.
 *
 * @param base AUDMIX base pointer.
 * @param tdmChannel TDM channel (0 for TDM1, 1 for TDM2).
 * @param counter Pointer to store the step counter value.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_GetAttenuationStepCounter(WAKEUP_AUDMIX_Type *base, uint8_t tdmChannel, uint32_t *counter);

/*! @} */

/*!
 * @name Output Control
 * @{
 */

/*!
 * @brief Sets the output source.
 *
 * @param base AUDMIX base pointer.
 * @param source Output source selection.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetOutputSource(WAKEUP_AUDMIX_Type *base, audmix_output_source_t source);

/*!
 * @brief Sets the mixing clock source.
 *
 * @param base AUDMIX base pointer.
 * @param source Mix clock source selection.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetMixClockSource(WAKEUP_AUDMIX_Type *base, audmix_mix_clock_source_t source);

/*!
 * @brief Sets the output audio sample width.
 *
 * @param base AUDMIX base pointer.
 * @param width Output audio sample width.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetOutputWidth(WAKEUP_AUDMIX_Type *base, audmix_output_width_t width);

/*!
 * @brief Sets the output bit clock polarity.
 *
 * @param base AUDMIX base pointer.
 * @param polarity Output bit clock polarity.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetOutputClockPolarity(WAKEUP_AUDMIX_Type *base, audmix_output_clock_polarity_t polarity);

/*!
 * @brief Enables or disables the frame rate difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_EnableFrameRateDiffErrorMasking(WAKEUP_AUDMIX_Type *base, bool enable);

/*!
 * @brief Enables or disables the clock frequency difference error masking.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable masking, false to disable masking.
 *
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_EnableClockFrequencyDiffErrorMasking(WAKEUP_AUDMIX_Type *base, bool enable);

/*!
 * @brief Enables or disables the sync mode.
 *
 * @param base AUDMIX base pointer.
 * @param enable true to enable sync mode, false to disable sync mode.
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_EnableSyncMode(WAKEUP_AUDMIX_Type *base, bool enable);

/*!
 * @brief Sets the sync mode clock source.
 *
 * @param base AUDMIX base pointer.
 * @param source Sync mode clock source (TDM1 or TDM2).
 * @return Returns status code. kStatus_Success on success, kStatus_AUDMIX_Error on failure.
 */
status_t AUDMIX_SetSyncModeClockSource(WAKEUP_AUDMIX_Type *base, audmix_mix_clock_source_t source);

/*! @} */

#if defined(__cplusplus)
}
#endif /*_cplusplus*/

/*! @} */

#endif /* FSL_AUDMIX_H_ */
