/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef EMIOS_PWM_IP_H
#define EMIOS_PWM_IP_H

/**
*   @file       Emios_Pwm_Ip.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Emios_Pwm_Ip_Cfg.h"
#include "Emios_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_VENDOR_ID                       43
#define EMIOS_PWM_IP_MODULE_ID                       121
#define EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_PWM_IP_SW_MAJOR_VERSION                3
#define EMIOS_PWM_IP_SW_MINOR_VERSION                0
#define EMIOS_PWM_IP_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Emios_Pwm_Ip.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same vendor */
#if (EMIOS_PWM_IP_VENDOR_ID != EMIOS_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Cfg header file are of the same software version */
#if ((EMIOS_PWM_IP_SW_MAJOR_VERSION != EMIOS_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_SW_MINOR_VERSION != EMIOS_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_SW_PATCH_VERSION != EMIOS_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same vendor */
#if (EMIOS_PWM_IP_VENDOR_ID != EMIOS_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same software version */
#if ((EMIOS_PWM_IP_SW_MAJOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_SW_MINOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_SW_PATCH_VERSION != EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip.h and Emios_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/**
* @brief Initialize PWM Mode
*
* @param[in] Instance    The eMIOS group id
* @param[in] UserChCfg   A pointer to the PWM configuration structure
* @return void
*/
void Emios_Pwm_Ip_InitChannel(uint8 Instance,
                              Emios_Pwm_Ip_ChannelConfigType const *UserChCfg);

/**
 * @brief Reset eMIOS Channel to GPIO mode (reset default)
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @return void
 */
void Emios_Pwm_Ip_DeInitChannel(uint8 Instance,
                                uint8 Channel);

/**
 * @brief Allow the software to force the output flip-flop to the level corresponding
 * to a match on leading edge. The FLAG bit is not set.
 *
 * @param[in] Instance The eMIOS group id
 * @param[in] Channel  The Channel in this eMIOS group
 * @param[in] Enable   The Channel in Force Match Leading Edge or not
 * @return void
 */
void Emios_Pwm_Ip_ForceMatchLeadingEdge(uint8 Instance,
                                        uint8 Channel,
                                        boolean Enable);

/**
 * @brief Allow the software to force the output flip-flop to the level corresponding
 * to a match on trailing edge. The FLAG bit is not set.
 *
 * @param[in] Instance The eMIOS group id
 * @param[in] Channel  The Channel in this eMIOS group
 * @param[in] Enable   The Channel in Force Match Leading Edge or not
 * @return void
 */
void Emios_Pwm_Ip_ForceMatchTrailingEdge(uint8 Instance,
                                         uint8 Channel,
                                         boolean Enable);

/**
 * @brief Get Period value in PWM mode
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @param[out] RetPeriod A pointer to return period value
 * @return Emios_Pwm_Ip_PeriodType Value of period
 */
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetPeriod(uint8 Instance,
                              uint8 Channel);

/**
 * @brief Set new Period value in PWM mode
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @param[in] NewPeriod   New Period value
 * @return void
 */
void Emios_Pwm_Ip_SetPeriod(uint8 Instance,
                            uint8 Channel,
                            Emios_Pwm_Ip_PeriodType NewPeriod);

/**
 * @brief Get Duty Cycle value in PWM mode
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @return Emios_Pwm_Ip_DutyType Value of duty cycle
 */
Emios_Pwm_Ip_DutyType Emios_Pwm_Ip_GetDutyCycle(uint8 Instance,
                                 uint8 Channel);

/**
 * @brief Set new Duty Cycle value in PWM mode
 *
 * @param[in] Instance       The eMIOS group id
 * @param[in] Channel        The Channel in this eMIOS group
 * @param[in] NewDutyCycle   New duty cycle value
 * @return operation status
 *        - EMIOS_PWM_IP_STATUS_SUCCESS      :  Operation was successful.
 *        - EMIOS_PWM_IP_STATUS_ERROR        :  Operation failed, invalid input value.
 */
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetDutyCycle(uint8 Instance,
                                                  uint8 Channel,
                                                  Emios_Pwm_Ip_DutyType NewDutyCycle);

/**
 * @brief Get Leading Edge Placement value in PWM mode
 *
 * @param[in] Instance   The eMIOS group id
 * @param[in] Channel    The Channel in this eMIOS group
 * @return Emios_Pwm_Ip_PeriodType Value of leading edge placement in counter bus time base
 */
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetPhaseShift(uint8 Instance,
                                  uint8 Channel);

/**
 * @brief Set new Leading edge placement value in PWM mode
 *
 * @param[in] Instance     The eMIOS group id
 * @param[in] Channel      The Channel in this eMIOS group
 * @param[in] PhaseShift   New Phase Shift value
 * @return void
 */
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_SetPhaseShift(uint8 Instance,
                                                   uint8 Channel,
                                                   Emios_Pwm_Ip_DutyType PhaseShift);

/**
 * @brief Get dead time value in PWM mode
 *
 * @param[in] Instance   The eMIOS group id
 * @param[in] Channel    The Channel in this eMIOS group
 * @return Emios_Pwm_Ip_PeriodType Value of Dead Time
 */
Emios_Pwm_Ip_PeriodType Emios_Pwm_Ip_GetDeadTime(uint8 Instance,
                                uint8 Channel);

/**
 * @brief Set new dead time value in PWM mode
 *
 * @param[in] Instance       The eMIOS group id
 * @param[in] Channel        The Channel in this eMIOS group
 * @param[in] NewDeadTime    New Dead Time value
 * @return void
 */
void Emios_Pwm_Ip_SetDeadTime(uint8 Instance,
                              uint8 Channel,
                              Emios_Pwm_Ip_PeriodType NewDeadTime);

/**
 * @brief Get Trigger Placement value in PWM mode
 *
 * @param[in] Instance The eMIOS group id
 * @param[in] Channel  The Channel in this eMIOS group
 * @return uint32 Value of Trigger Placement
 */
uint32 Emios_Pwm_Ip_GetTriggerPlacement(uint8 Instance,
                                        uint8 Channel);

/**
 * @brief Set new Trigger Placement value in PWM mode
 *
 * @param[in] Instance             The eMIOS group id
 * @param[in] Channel              The Channel in this eMIOS group
 * @param[in] NewTriggerPlacement  New Trigger Placement value
 * @return void
 */
void Emios_Pwm_Ip_SetTriggerPlacement(uint8  Instance,
                                      uint8  Channel,
                                      Emios_Pwm_Ip_PeriodType NewTriggerPlacement);

/**
 * @brief Set a Channel enters freeze state, should be setting
 * EMIOS_AllowEnterDebugMode first.
 *
 * @param[in] Instance   The eMIOS group id
 * @param[in] Channel    The Channel in this eMIOS group
 * @return operation status
 *        - EMIOS_PWM_IP_STATUS_SUCCESS                 :  Operation was successful.
 *        - EMIOS_PWM_IP_STATUS_ERROR                   :  Operation failed, invalid input value.
 *        - EMIOS_PWM_IP_STATUS_ENABLE_GLOBAL_FRZ       :  Need call EMIOS_AllowEnterDebugMode first.
 */
Emios_Pwm_Ip_StatusType Emios_Pwm_Ip_ChannelEnterDebugMode(uint8 Instance,
                                                           uint8 Channel);

/**
 * @brief Release a Channel from freeze state
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @return void
 */
void Emios_Pwm_Ip_ChannelStopDebugMode(uint8 Instance,
                                       uint8 Channel);

/**
 * @brief Get the Unified Channel FLAG event generated. Interrupt or DMA request.
 *
 * @param[in] Instance   The eMIOS group id
 * @param[in] Channel    The Channel in this eMIOS group
 * @return The FLAG event response type
 */
Emios_Pwm_Ip_InterruptType Emios_Pwm_Ip_GetFlagRequest(uint8 Instance,
                                                       uint8 Channel);

/**
 * @brief Allow the Unified Channel FLAG bit to generate an interrupt signal or
 * a DMA request signal
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @param[in] Event     The FLAG event response type
 * @return void
 */
void Emios_Pwm_Ip_SetFlagRequest(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_InterruptType Event);

/**
 * @brief Get the Unified Channel output pin logic level
 *
 * @param[in] Instance  The eMIOS group id
 * @param[in] Channel   The Channel in this eMIOS group
 * @return The Emios Channel output pin state HIGH/LOW
 */
Emios_Pwm_Ip_OutputStateType Emios_Pwm_Ip_GetOutputState(uint8 Instance,
                                                         uint8 Channel);

/**
 * @brief Set the state of output pin
 *
 * @param[in] Instance     The eMIOS group id
 * @param[in] Channel      The Channel in this eMIOS group
 * @param[in] OutputState  The state of output pin
 * @return    void
 */
void Emios_Pwm_Ip_SetOutputState(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_OutputStateType OutputState);

/**
 * @brief Set the polarity and mode for current Channel as normal
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @param[in] DutyPercent The range of duty cycle value :0x00(0%) ->0x8000(100%)
 * @param[in] Polarity    The polarity of Channel
 * @param[in] Mode        Mode of Channel
 * @return    void
 */
void Emios_Pwm_Ip_SetOutputToNormal(uint8 Instance,
                                    uint8 Channel,
                                    uint16 DutyPercent,
                                    Emios_Pwm_Ip_PolarityType Polarity,
                                    Emios_Pwm_Ip_PwmModeType  Mode);

/**
 * @brief  Get mode of operation of the Unified Channel
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @return    Emios_Pwm_Ip_PwmModeType
 */
Emios_Pwm_Ip_PwmModeType Emios_Pwm_Ip_GetChannelMode(uint8 Instance,
                                                     uint8 Channel);

/**
 * @brief  Get master bus Channel
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @return    Emios_Pwm_Ip_PwmModeType
 */
uint8 Emios_Pwm_Ip_GetMasterBusChannel(uint8 Instance,
                                       uint8 Channel);

/**
 * @brief    Set Prescaler Enable bit.
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @param[in] Value       The value to set
 *                        - 0     Prescaler disabled (no clock)
 *                        - 1     Prescaler enabled
 * @return  void
 */
void Emios_Pwm_Ip_SetPreEnableClock(uint8 Instance,
                                    uint8 Channel,
                                    boolean Value);

/**
 * @brief    Set Bus Select bits.
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @param[in] Value       The value to set
 * @return  void
 */
void Emios_Pwm_Ip_SetBusSelected(uint8 Instance,
                                 uint8 Channel,
                                 Emios_Pwm_Ip_CounterBusSourceType Value);

/**
 * @brief     This function set the value of the prescaler on eMios channels
 *
 * @param[in] Instance    The eMIOS group id
 * @param[in] Channel     The Channel in this eMIOS group
 * @param[in] Value       The value to set
 * @return    void
 */
void Emios_Pwm_Ip_SetClockPs(uint8 Instance,
                             uint8 Channel,
                             Emios_Pwm_Ip_InternalClkPsType Value);

/**
 * @brief The function shall Enable the output update for the corresponding Channel.
 *
 * @param[in] Instance        Instance of EMIOS used.
 * @param[in] ChannelMask     EMIOS hardware mask Channel used.
 */
void Emios_Pwm_Ip_ComparatorTransferEnable(uint8 Instance, uint32 ChannelMask);

/**
 * @brief The function shall disable the output update for the corresponding Channel.
 *
 * @param[in] Instance        Instance of EMIOS used.
 * @param[in] ChannelMask     EMIOS hardware mask Channel used.
 */
void Emios_Pwm_Ip_ComparatorTransferDisable(uint8 Instance, uint32 ChannelMask);

/**
* @brief        This function updates the duty cycle and-or period for the specified PWM Channel.
*               The value written does not take effect until calling SyncUpdate API.
*
* @param        Instance          eMIOS hardware module index
*
* @return       void
*
*/
void Emios_Pwm_Ip_SyncUpdate(uint8 Instance);

/**
* @brief        This function updates the value of UCRegA. It may be used to change duty cycle or phase shift 
*               with minimum overhead.
*
* @param        Instance          eMIOS hardware module index
* @param        Channel           The Channel in this eMIOS group
* @param        Value             The value to set
*
* @return       void
*
*/
void Emios_Pwm_Ip_UpdateUCRegA(uint8 Instance, uint8 Channel, Emios_Pwm_Ip_PeriodType Value);

/**
* @brief        This function updates the value of UCRegB. It may be used to change duty cycle, phase shift or
*               inserted dead time buffer with minimum overhead.
*
* @param        Instance          eMIOS hardware module index
* @param        Channel           The Channel in this eMIOS group
* @param        Value             The value to set
*
* @return       void
*
*/
void Emios_Pwm_Ip_UpdateUCRegB(uint8 Instance, uint8 Channel, Emios_Pwm_Ip_PeriodType Value);


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_H */
