/*
 * Copyright 2023-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_EZHV_H_
#define FSL_EZHV_H_

#include "fsl_common.h"

/*!
 * @addtogroup ezhv
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief EZHV inside machine-mode external isr offset */
#define EZHV_M_EXT_INT           (11U)

/*! @brief shared data space between ARM and EZHV, space size is 256 Bytes */
#define EZHV_SHARED_DATA_ADDR    (0x2410FF00U)

/*! @brief definition for active ezhv2arm int channel number
 * 
 * please redefine this macro's value if less channels are enabled
*/
#define EZHV_INT_CHAN_NUM       (16U)

/*! @name Driver version */
/*@{*/
/*! @brief cache driver version. */
#define FSL_EZHV_DRIVER_VERSION (MAKE_VERSION(2, 1, 1))
/*@}*/

/*! @brief define callback function for EZH-V 
 *
 * This callback function is called in EZH-V interrupt handle.
*/
typedef void (*ezhv_callback_t)(void *userData);

/*!
 * @brief Structure for EZH-V copy image to destination address
 *
 * Defines source and destination address for copying image with given size.
 */
typedef struct _ezhv_copy_image
{
    uint32_t srcAddr;
    uint32_t destAddr;
    uint32_t size;
} ezhv_copy_image_t;

/*!
 * @Brief List of EZH-V APIs
 */
typedef uint32_t ezhv_api_t;

#define EZHV_API_MAX_ARG 8U

/*!
 * @brief parameters used by EZH-V
 */
typedef struct _ezhv_param {
    ezhv_api_t ezhvApi;
    uint32_t argc;
    uint32_t *argv[EZHV_API_MAX_ARG];
} ezhv_param_t;

/*! @brief Definition of 4 interrupt requests from ARM to EZH-V */
typedef enum _arm2ezhv_intctl {
    kEZHV_ARM2EZHV_MEI = SYSCON4_ARM2EZHV_INT_CTRL_MEIP_MASK,
    kEZHV_ARM2EZHV_SEI = SYSCON4_ARM2EZHV_INT_CTRL_SEIP_MASK,
    kEZHV_ARM2EZHV_MSI = SYSCON4_ARM2EZHV_INT_CTRL_MSIP_MASK,
    kEZHV_ARM2EZHV_MTI = SYSCON4_ARM2EZHV_INT_CTRL_MTIP_MASK,
} arm2ezhv_intctl_t;

/*! @brief EZH-V to ARM interrupt channel. */
typedef enum _ezhv2arm_int_chan {
    kEZHV_EzhvToArmIntChan0  = (0x1U << 0U),
    kEZHV_EzhvToArmIntChan1  = (0x1U << 1U),
    kEZHV_EzhvToArmIntChan2  = (0x1U << 2U),
    kEZHV_EzhvToArmIntChan3  = (0x1U << 3U),
    kEZHV_EzhvToArmIntChan4  = (0x1U << 4U),
    kEZHV_EzhvToArmIntChan5  = (0x1U << 5U),
    kEZHV_EzhvToArmIntChan6  = (0x1U << 6U),
    kEZHV_EzhvToArmIntChan7  = (0x1U << 7U),
    kEZHV_EzhvToArmIntChan8  = (0x1U << 8U),
    kEZHV_EzhvToArmIntChan9  = (0x1U << 9U),
    kEZHV_EzhvToArmIntChan10 = (0x1U << 10U),
    kEZHV_EzhvToArmIntChan11 = (0x1U << 11U),
    kEZHV_EzhvToArmIntChan12 = (0x1U << 12U),
    kEZHV_EzhvToArmIntChan13 = (0x1U << 13U),
    kEZHV_EzhvToArmIntChan14 = (0x1U << 14U),
    kEZHV_EzhvToArmIntChan15 = (0x1U << 15U),
} ezhv2arm_int_chan_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Initialize the EZH-V.
 *
 * @param ezhvCopyImage The information about the EZH-V image to copy.
 */
void EZHV_Init(ezhv_copy_image_t *ezhvCopyImage);

 /*!
 * @brief Initialize the EZH-V.
 *
 * This function is similar with EZHV_Init, the difference is this function
 * does not install the firmware, the firmware could be installed using
 * EZHV_InstallFirmware.
 */
void EZHV_InitWithoutFirmware(void);

/*!
 * @brief install EZH-V firmware by given image info
 *
 * @param ezhvCopyImage The information about the EZH-V image to copy.
 */
void EZHV_InstallFirmware(ezhv_copy_image_t *ezhvCopyImage);

/*!
 * @brief Boot EZH-V from given address bootAddr
 *
 * @param bootAddr The boot address.
 */
void EZHV_Boot(uint32_t bootAddr);

/*!
 * @brief Deinitialize the EZH-V.
 */
void EZHV_Deinit(void);

/*!
 * @brief Install the EZH-V callback function.
 *
 * @param callback EZH-V callback function pointer.
 * @param channel interrupt channel index.
 * @param userData A parameter for the callback function.
 */
void EZHV_SetCallback(ezhv_callback_t callback,
                    uint16_t channel,
                    void *userData);

/*!
 * @brief Set the parameter used by EZH-V.
 *
 * @param para Parameter written into shared mem between ARM and EZH-V.
 */
void EZHV_SetPara(ezhv_param_t *para);

/*!
 * @brief Get shared space address
 *
 * @return The start address of shared space
 */
uint32_t *EZHV_GetParaAddr(void);

/*!
 * @brief Check the wait status and wake up EZH-V.
 *
 * @param arm2ezhvInt The interrupt request which will send to the EZH-V.
 */
void EZHV_WakeUpEzhv(arm2ezhv_intctl_t arm2ezhvInt);

/*!
 * @brief Enable interrupt request from ARM core to EZH-V core.
 * 
 * @note This interrupt can be used to send interrupt request to EZH-V
 *
 * @param arm2ezhvInt The interrupt request which will send to the EZH-V.
 */
static inline void EZHV_EnableArm2EzhvInt(arm2ezhv_intctl_t arm2ezhvInt)
{
    SYSCON4->ARM2EZHV_INT_CTRL |= (uint32_t)arm2ezhvInt;
}

/*!
 * @brief Disable interrupt request from ARM core to EZH-V core.
 * 
 * @param arm2ezhvInt The interrupt request type.
 */
static inline void EZHV_DisableArm2EzhvInt(arm2ezhv_intctl_t arm2ezhvInt)
{
    SYSCON4->ARM2EZHV_INT_CTRL &= ~(uint32_t)arm2ezhvInt;
}

/*!
 * @brief EZH-V IRQ handler
 */
void EZHV_DriverIRQHandler(void);

/*! 
 * @brief Enable the EZH-V interrupt channel to ARM core.
 *
 * @param chan Ezhv to arm interrupt channel index.
 */
static inline void EZHV_EnableEzhv2ArmIntChan(ezhv2arm_int_chan_t chan)
{
    SYSCON4->EZHV2ARM_INT_EN |= (uint32_t)chan;
}

/*! 
 * @brief Disable the EZH-V interrupt channel to ARM core.
 *
 * @param chan Ezhv to arm interrupt channel index.
 */
static inline void EZHV_DisableEzhv2ArmIntChan(ezhv2arm_int_chan_t chan)
{
    SYSCON4->EZHV2ARM_INT_EN &= ~((uint32_t)chan);
}

/*! 
 * @brief Get EZH-V interrupt outputs. 
 */
static inline uint32_t EZHV_GetEzhv2ArmIntChan(void)
{
    return (uint32_t)(SYSCON4->EZHV2ARM_INT_CHAN & SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_MASK >> SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_SHIFT);
}

/*! 
 * @brief Clear EZH-V interrupt outputs.
 *
 * @param chan EZH-V to ARM interrupt channel index.
 */
static inline void EZHV_ClearEzhv2ArmIntChan(ezhv2arm_int_chan_t chan)
{
    SYSCON4->EZHV2ARM_INT_CHAN = (uint32_t)chan;
}

/*!
 * @brief Get EZH-V stop status flag
 */
static inline bool EZHV_GetEzhvStopStatusFlag()
{
    return (bool)((SLEEPCON0->SHA_MED_CSTAT0 & SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_MASK) >> SLEEPCON0_SHA_MED_CSTAT0_EZHV_STOPPED_SHIFT);
}

/*!
 * @brief Get EZH-V halt status flag
 */
static inline bool EZHV_GetEzhvHaltStatusFlag()
{
    return (bool)((SLEEPCON0->SHA_MED_CSTAT0 & SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_MASK) >> SLEEPCON0_SHA_MED_CSTAT0_EZHV_HALTED_SHIFT);
}

/*!
 * @brief Get EZH-V wait status flag
 */
static inline bool EZHV_GetEzhvWaitStatusFlag()
{
    return (bool)((SLEEPCON0->SHA_MED_CSTAT0 & SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_MASK) >> SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAITING_SHIFT);
}

/*!
 * @brief Get EZH-V wakeup status flag
 */
static inline bool EZHV_GetEzhvWakeupStatusFlag()
{
    return (bool)((SLEEPCON0->SHA_MED_CSTAT0 & SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_MASK) >> SLEEPCON0_SHA_MED_CSTAT0_EZHV_WAKEUP_SHIFT);
}

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif
