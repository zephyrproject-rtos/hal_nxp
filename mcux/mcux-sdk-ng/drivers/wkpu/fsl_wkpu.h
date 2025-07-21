/*
 * Copyright 2025 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_WKPU_H_
#define FSL_WKPU_H_

#include "fsl_common.h"

/*! @addtogroup wkpu */
/*! @{ */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief Defines WKPU driver version 2.0.0. */
#define FSL_WKPU_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief The wakeup source enumeration. */
typedef enum _wkpu_source
{
    kWKPU_SourceNone = (uint64_t)0ULL,         /*!< No wakeup source */
    kWKPU_Source0    = (uint64_t)(1ULL << 0),  /*!< SWT_0 timeout and RTC-API API wakeup source */
    kWKPU_Source1    = (uint64_t)(1ULL << 1),  /*!< RTC-API RTC timeout wakeup source */
    kWKPU_Source2    = (uint64_t)(1ULL << 2),  /*!< Round robin wakeup source from LPCMP_0, LPCMP_1, or LPCMP_2 */
    kWKPU_Source3    = (uint64_t)(1ULL << 3),  /*!< PIT0-RTI wakeup source */
    kWKPU_Source4    = (uint64_t)(1ULL << 4),  /*!< External pin wakeup source WKPU[0] */
    kWKPU_Source5    = (uint64_t)(1ULL << 5),  /*!< External pin wakeup source WKPU[1] */
    kWKPU_Source6    = (uint64_t)(1ULL << 6),  /*!< External pin wakeup source WKPU[2] */
    kWKPU_Source7    = (uint64_t)(1ULL << 7),  /*!< External pin wakeup source WKPU[3] */
    kWKPU_Source8    = (uint64_t)(1ULL << 8),  /*!< External pin wakeup source WKPU[4] */
    kWKPU_Source9    = (uint64_t)(1ULL << 9),  /*!< External pin wakeup source WKPU[5] */
    kWKPU_Source10   = (uint64_t)(1ULL << 10), /*!< External pin wakeup source WKPU[6] */
    kWKPU_Source11   = (uint64_t)(1ULL << 11), /*!< External pin wakeup source WKPU[7] */
    kWKPU_Source12   = (uint64_t)(1ULL << 12), /*!< External pin wakeup source WKPU[8] */
    kWKPU_Source13   = (uint64_t)(1ULL << 13), /*!< External pin wakeup source WKPU[9] */
    kWKPU_Source14   = (uint64_t)(1ULL << 14), /*!< External pin wakeup source WKPU[10] */
    kWKPU_Source15   = (uint64_t)(1ULL << 15), /*!< External pin wakeup source WKPU[11] */
    kWKPU_Source16   = (uint64_t)(1ULL << 16), /*!< External pin wakeup source WKPU[12] */
    kWKPU_Source17   = (uint64_t)(1ULL << 17), /*!< External pin wakeup source WKPU[13] */
    kWKPU_Source18   = (uint64_t)(1ULL << 18), /*!< External pin wakeup source WKPU[14] */
    kWKPU_Source19   = (uint64_t)(1ULL << 19), /*!< External pin wakeup source WKPU[15] */
    kWKPU_Source20   = (uint64_t)(1ULL << 20), /*!< External pin wakeup source WKPU[16] */
    kWKPU_Source21   = (uint64_t)(1ULL << 21), /*!< External pin wakeup source WKPU[17] */
    kWKPU_Source22   = (uint64_t)(1ULL << 22), /*!< External pin wakeup source WKPU[18] */
    kWKPU_Source23   = (uint64_t)(1ULL << 23), /*!< External pin wakeup source WKPU[19] */
    kWKPU_Source24   = (uint64_t)(1ULL << 24), /*!< External pin wakeup source WKPU[20] */
    kWKPU_Source25   = (uint64_t)(1ULL << 25), /*!< External pin wakeup source WKPU[21] */
    kWKPU_Source26   = (uint64_t)(1ULL << 26), /*!< External pin wakeup source WKPU[22] */
    kWKPU_Source27   = (uint64_t)(1ULL << 27), /*!< External pin wakeup source WKPU[23] */
    kWKPU_Source28   = (uint64_t)(1ULL << 28), /*!< External pin wakeup source WKPU[24] */
    kWKPU_Source29   = (uint64_t)(1ULL << 29), /*!< External pin wakeup source WKPU[25] */
    kWKPU_Source30   = (uint64_t)(1ULL << 30), /*!< External pin wakeup source WKPU[26] */
    kWKPU_Source31   = (uint64_t)(1ULL << 31), /*!< External pin wakeup source WKPU[27] */
    kWKPU_Source32   = (uint64_t)(1ULL << 32), /*!< External pin wakeup source WKPU[28] */
    kWKPU_Source33   = (uint64_t)(1ULL << 33), /*!< External pin wakeup source WKPU[29] */
    kWKPU_Source34   = (uint64_t)(1ULL << 34), /*!< External pin wakeup source WKPU[30] */
    kWKPU_Source35   = (uint64_t)(1ULL << 35), /*!< External pin wakeup source WKPU[31] */
    kWKPU_Source36   = (uint64_t)(1ULL << 36), /*!< External pin wakeup source WKPU[32] */
    kWKPU_Source37   = (uint64_t)(1ULL << 37), /*!< External pin wakeup source WKPU[33] */
    kWKPU_Source38   = (uint64_t)(1ULL << 38), /*!< External pin wakeup source WKPU[34] */
    kWKPU_Source39   = (uint64_t)(1ULL << 39), /*!< External pin wakeup source WKPU[35] */
    kWKPU_Source40   = (uint64_t)(1ULL << 40), /*!< External pin wakeup source WKPU[36] */
    kWKPU_Source41   = (uint64_t)(1ULL << 41), /*!< External pin wakeup source WKPU[37] */
    kWKPU_Source42   = (uint64_t)(1ULL << 42), /*!< External pin wakeup source WKPU[38] */
    kWKPU_Source43   = (uint64_t)(1ULL << 43), /*!< External pin wakeup source WKPU[39] */
    kWKPU_Source44   = (uint64_t)(1ULL << 44), /*!< External pin wakeup source WKPU[40] */
    kWKPU_Source45   = (uint64_t)(1ULL << 45), /*!< External pin wakeup source WKPU[41] */
    kWKPU_Source46   = (uint64_t)(1ULL << 46), /*!< External pin wakeup source WKPU[42] */
    kWKPU_Source47   = (uint64_t)(1ULL << 47), /*!< External pin wakeup source WKPU[43] */
    kWKPU_Source48   = (uint64_t)(1ULL << 48), /*!< External pin wakeup source WKPU[44] */
    kWKPU_Source49   = (uint64_t)(1ULL << 49), /*!< External pin wakeup source WKPU[45] */
    kWKPU_Source50   = (uint64_t)(1ULL << 50), /*!< External pin wakeup source WKPU[46] */
    kWKPU_Source51   = (uint64_t)(1ULL << 51), /*!< External pin wakeup source WKPU[47] */
    kWKPU_Source52   = (uint64_t)(1ULL << 52), /*!< External pin wakeup source WKPU[48] */
    kWKPU_Source53   = (uint64_t)(1ULL << 53), /*!< External pin wakeup source WKPU[49] */
    kWKPU_Source54   = (uint64_t)(1ULL << 54), /*!< External pin wakeup source WKPU[50] */
    kWKPU_Source55   = (uint64_t)(1ULL << 55), /*!< External pin wakeup source WKPU[51] */
    kWKPU_Source56   = (uint64_t)(1ULL << 56), /*!< External pin wakeup source WKPU[52] */
    kWKPU_Source57   = (uint64_t)(1ULL << 57), /*!< External pin wakeup source WKPU[53] */
    kWKPU_Source58   = (uint64_t)(1ULL << 58), /*!< External pin wakeup source WKPU[54] */
    kWKPU_Source59   = (uint64_t)(1ULL << 59), /*!< External pin wakeup source WKPU[55] */
    kWKPU_Source60   = (uint64_t)(1ULL << 60), /*!< External pin wakeup source WKPU[56] */
    kWKPU_Source61   = (uint64_t)(1ULL << 61), /*!< External pin wakeup source WKPU[57] */
    kWKPU_Source62   = (uint64_t)(1ULL << 62), /*!< External pin wakeup source WKPU[58] */
    kWKPU_Source63   = (uint64_t)(1ULL << 63), /*!< External pin wakeup source WKPU[59] */
    kWKPU_SourceAll  = (uint64_t)~0ULL         /*!< All wakeup sources */
} wkpu_source_t;

/*! @brief Wake up pin edge detection enumeration, applied for both NMI and external wake up and interrupt pin. */
typedef enum _wkpu_pin_edge_detection
{
    kWKPU_PinDisable     = 0x0U, /*!< Pin disabled. */
    kWKPU_PinRisingEdge  = 0x1U, /*!< Pin enabled with the rising edge detection. */
    kWKPU_PinFallingEdge = 0x2U, /*!< Pin enabled with the falling edge detection. */
    kWKPU_PinAnyEdge     = 0x3U, /*!< Pin enabled with any update detection. */
} wkpu_pin_edge_detection_t;

/*! @brief wake up event enumeration. */
typedef enum _wkpu_event
{
    kWKPU_Interrupt          = 0x0U, /*!< Interrupt. */
    kWKPU_WakeUp             = 0x1U, /*!< Wake up */
    kWKPU_InterruptAndWakeUp = 0x2U, /*!< Interrupt and wake up */
} wakeup_event_t;

/*! @brief NMI status flag enumeration */
typedef enum _wkpu_nmi_status_flag
{
    kWKPU_NMIOverrunStatusFlag = WKPU_NSR_NOVF0_MASK, /*!< NMI Overrun Status Flag. */
    kWKPU_NMIStatusFlag =
        WKPU_NSR_NIF0_MASK, /*!< NMI status flag. Assert when NMI rising-edge or falling-edge event occurred. */
    kWKPU_NMIAllStatusFlag = WKPU_NSR_NOVF0_MASK | WKPU_NSR_NIF0_MASK, /*!< All NMI status flag. */
} wkpu_nmi_status_flag_t;

/*! @brief External WakeUp pin configuration. */
typedef struct _wkpu_external_wakeup_source_config
{
    wakeup_event_t event;           /*!< External Input wakeup Pin event */
    wkpu_pin_edge_detection_t edge; /*!< External Input pin edge detection. */
    bool enableFilter;              /*!< Enable filter for the external input pin. */
} wkpu_external_wakeup_source_config_t;

/*! @brief NMI wake up configuration. */
typedef struct _wkpu_nmi_wakeup_config
{
    wkpu_pin_edge_detection_t edge; /*!< External Input pin edge detection. */
    bool enableFilter;              /*!< Enable filter for the NMI input pin. */
    bool enableWakeup;              /*!< Enable wakeup for the NMI input pin. */
    bool lockRegister;              /*!< Enable NMI for the NMI input pin. */
} wkpu_nmi_wakeup_config_t;

/*! @brief WakeUp callback function. */
typedef void (*wkpu_callback_t)(uint64_t mask);

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name External Wake up Sources Control APIs.
 * @{
 */

/*!
 * @brief Fills in the WKPU external wake up source config struct with the default settings.
 *
 * The default values are as follows.
 * @code
 *     config->event               = kWKPU_WakeUp;
 *     config->edge                       = kWKPU_PinRisingEdge;
 *     config->enableFilter               = false;
 * @endcode
 *
 * @param config Pointer to the user defined WKPU configuration structure.
 */
void WKPU_GetDefaultExternalWakeUpSourceConfig(wkpu_external_wakeup_source_config_t *config);

/*!
 * @brief Enable and config the external wakeup source.
 *
 * This function enables/disables the external wake up source as the wake up input. The wake up sources are mostly wake
 * up pins with several internal wakeup modules.
 *
 * @param base         WKPU peripheral base address.
 * @param mask         The wake up source to used. This is a logical OR of members of the enumeration ::wkpu_source_t
 * @param config       Pointer to wkpu_external_wakeup_source_config_t structure.
 */
void WKPU_SetExternalWakeUpSourceConfig(WKPU_Type *base,
                                        uint64_t mask,
                                        const wkpu_external_wakeup_source_config_t *config);

/*!
 * @brief Disable and clear external wakeup source settings.
 *
 * @param base         WKPU peripheral base address.
 * @param mask         The wake up source to used. This is a logical OR of members of the enumeration ::wkpu_source_t
 */
void WKPU_ClearExternalWakeupSourceConfig(WKPU_Type *base, uint64_t mask);

/*!
 * @brief Get the external wakeup source flag.
 *
 * This function return the external wakeup source flag of the source index.
 *
 * @param base WKPU peripheral base address.
 * @return Wakeup flag of the source index.
 */
static inline uint64_t WKPU_GetExternalWakeUpSourceFlag(WKPU_Type *base)
{
    return ((uint64_t)base->WISR) | (((uint64_t)base->WISR_64) << 32);
}

/*!
 * @brief Clear the external wake up source flag.
 *
 * This function clears external wakeup source flag of the source index .
 *
 * @param base WKPU peripheral base address.
 * @param mask The wake up source to used. This is a logical OR of members of the enumeration ::wkpu_source_t
 */
static inline void WKPU_ClearExternalWakeUpSourceFlag(WKPU_Type *base, uint64_t mask)
{
    uint64_t lowBitMask = 0;
    lowBitMask          = (uint64_t)mask & 0xFFFFFFFF;
    base->WISR          = (uint32_t)lowBitMask;
    base->WISR_64       = (uint32_t)(mask >> 32);
}

/*! @} */

/*!
 * @name NMI Wakeup source control APIs.
 * @{
 */

/*!
 * @brief Fills in the NMI wake up source config struct with the default settings.
 *
 * The default values are as follows.
 * @code
 *    config->edge                       = kWKPU_PinRisingEdge;
 *    config->enableFilter               = true;
 *    config->enableWakeup               = true;
 *    config->lockRegister               = false;
 * @endcode
 *
 * @param config Pointer to the user defined WKPU configuration structure.
 */
void WKPU_GetDefaultNMIWakeUpConfig(wkpu_nmi_wakeup_config_t *config);

/*!
 * @brief Config NMI event as the wake up soures.
 *
 * This function configs the NMI as wake up source.
 *
 * @param base      WKPU peripheral base address.
 * @param config    Pointer to wkpu_external_wakeup_source_config_t structure.
 */
void WKPU_SetNMIWakeupConfig(WKPU_Type *base, const wkpu_nmi_wakeup_config_t *config);

/*!
 * @brief Disable and clear NMI settings.
 *
 * @param base WKPU peripheral base address.
 */
void WKPU_ClearNMIWakeupConfig(WKPU_Type *base);

/*
 * @brief Get the NMI status flag.
 *
 * This function return the NMI status flag
 *
 * @param base WKPU peripheral base address.
 */
static inline uint32_t WKPU_GetNMIStatusFlag(WKPU_Type *base)
{
    return base->NSR & (uint32_t)kWKPU_NMIAllStatusFlag;
}

/*!
 * @brief Clear the NMI status flag.
 *
 * @param base WKPU peripheral base address.
 * @param mask The NMI status flag to be cleared. This is a logical OR of members of the enumeration
 * ::wkpu_nmi_status_flag_t
 *
 */
static inline void WKPU_ClearNMIStatusFlag(WKPU_Type *base, uint32_t mask)
{
    base->NSR = (mask & (uint32_t)kWKPU_NMIAllStatusFlag);
}

/*! @} */

/*!
 * @brief Register callback.
 *
 * @param cb_func   callback function
 */
void WKPU_RegisterCallBack(wkpu_callback_t cb_func);

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /*FSL_WKPU_H_*/