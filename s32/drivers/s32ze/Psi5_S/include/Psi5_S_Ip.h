/*
 * Copyright 2021-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_S_IP_H
#define PSI5_S_IP_H

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Psi5_S_Ip_Types.h"
#include "Psi5_S_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFOPSI5ATION
==================================================================================================*/
#define PSI5_S_IP_VENDOR_ID                      43
#define PSI5_S_IP_AR_RELEASE_MAJOR_VERSION       4
#define PSI5_S_IP_AR_RELEASE_MINOR_VERSION       7
#define PSI5_S_IP_AR_RELEASE_REVISION_VERSION    0
#define PSI5_S_IP_SW_MAJOR_VERSION               2
#define PSI5_S_IP_SW_MINOR_VERSION               0
#define PSI5_S_IP_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Psi5_S_Ip_Types.h */
#if (PSI5_S_IP_VENDOR_ID != PSI5_S_IP_TYPES_VENDOR_ID)
    #error "Psi5_S_Ip.h and Psi5_S_Ip_Types.h have different vendor ids"
#endif
#if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip.h and Psi5_S_Ip_Types.h are different"
#endif
#if ((PSI5_S_IP_SW_MAJOR_VERSION != PSI5_S_IP_TYPES_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_SW_MINOR_VERSION != PSI5_S_IP_TYPES_SW_MINOR_VERSION) || \
     (PSI5_S_IP_SW_PATCH_VERSION != PSI5_S_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip.h and Psi5_S_Ip_Types.h are different"
#endif

/* Checks against Psi5_S_Ip_Cfg.h */
#if (PSI5_S_IP_VENDOR_ID != PSI5_S_IP_CFG_VENDOR_ID)
    #error "Psi5_S_Ip.h and Psi5_S_Ip_Cfg.h have different vendor ids"
#endif
#if ((PSI5_S_IP_AR_RELEASE_MAJOR_VERSION    != PSI5_S_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_MINOR_VERSION    != PSI5_S_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_S_IP_AR_RELEASE_REVISION_VERSION != PSI5_S_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_S_Ip.h and Psi5_S_Ip_Cfg.h are different"
#endif
#if ((PSI5_S_IP_SW_MAJOR_VERSION != PSI5_S_IP_CFG_SW_MAJOR_VERSION) || \
     (PSI5_S_IP_SW_MINOR_VERSION != PSI5_S_IP_CFG_SW_MINOR_VERSION) || \
     (PSI5_S_IP_SW_PATCH_VERSION != PSI5_S_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_S_Ip.h and Psi5_S_Ip_Cfg.h are different"
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

#define PSI5_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"
/**
* @brief   Export PSI5 configurations.
*/
PSI5_S_IP_CONFIG_EXT

#define PSI5_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"

/*!
 * @brief Main initializer for the driver
 *
 * Initializes the driver for a given peripheral
 * according to the given configuration structure.
 *
 * @param[in] configPtr Pointer to the configuration structure
 */
void Psi5_S_Ip_Init(const Psi5_S_Ip_ConfigType * configPtr);

/*!
 * @brief Reset the peripheral.
 *
 * De-Initializes the peripheral and brings it's registers into a reset state.
 *
 */
void Psi5_S_Ip_DeInit(void);

/*!
 * @brief Transmit a data frame
 *
 * Transmits a data frame according to configuration.
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SChannelId Channel number
 * @param[in] Psi5SData Data to send
 * @return E_OK If transmit succeeded
 * @return E_NOT_OK If not configured or not enabled or not ready
 */
Std_ReturnType Psi5_S_Ip_Transmit(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId,  const uint64 Psi5SData);

/*!
 * @brief Transmission status
 *
 * Returns the status of the transmission.
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SChannelId Channel number
 * @return true If transmission ready
 * @return false If transmission pending
 */
boolean Psi5_S_Ip_GetTransmissionStatus(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId);

/*!
 * @brief Send direct command a data frame
 *
 * Send direct command a data frame according to configuration.
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SDirCmd Direct command to send
 * @param[in] Psi5SDirCmdLen Direct command lenght to send
 * @return E_OK If transmit succeeded
 * @return E_NOT_OK If not configured or not enabled or not ready
 */
Std_ReturnType Psi5_S_Ip_SendDirectCommand(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const uint32 Psi5SDirCmd, const uint8 Psi5SDirCmdLen);

/*!
 * @brief Gets a PSI5 frame
 *
 * Returns the last received PSI5 frame.
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SChannelId Channel number
 * @param[out] Psi5SFramePtr Target variable
 * @return E_OK If channel is active
 * @return E_NOT_OK If channel is not active
 */
Std_ReturnType Psi5_S_Ip_GetPsi5SFrame(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId, Psi5_S_Ip_Psi5SFrameType * Psi5SFramePtr);

/*!
 * @brief Global sync all the DDSR's
 *
 * Changes the global sync all the DDSR's
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SState Sellect state
 * @return E_OK If config succeeded
 * @return E_NOT_OK If Channel Target Counter is controlled by Channel Target Counter Enable/Disable.
 */
Std_ReturnType Psi5_S_Ip_SetGlobalSync(const uint8 Psi5SInstanceId, const boolean Psi5SState);

/*!
 * @brief Channel sync the DDSR's
 *
 * Changes the channel sync the DDSR's
 *
 * @param[in] Psi5SInstanceId Instance number
 * @param[in] Psi5SChannelId Instance channel number
 * @param[in] Psi5SState Sellect state
 * @return E_OK If config succeeded
 * @return E_NOT_OK If Channel Target Counter is controlled by Channel Target Counter Enable/Disable.
 */
Std_ReturnType Psi5_S_Ip_SetChannelSync(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId, const boolean Psi5SState);

/**
* @brief   Interrupt handler signature for Rx
*
* @param[in] Psi5SInstanceId Instance number
* @param[in] Psi5SChannelId Instance channel number
* @return  void
*
*/
void Psi5_S_Ip_IRQ_Handler_Rx(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId);

/**
* @brief   Interrupt handler signature for Tx
*
* @param[in] Psi5SInstanceId Instance number
* @param[in] Psi5SChannelId Instance channel number
* @return  void
*
*/
void Psi5_S_Ip_IRQ_Handler_Tx(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId, const Psi5_S_Ip_HwChannelIdType Psi5SChannelId);

/**
* @brief   Interrupt global handler signature
*
* @param[in] Psi5SInstanceId Instance number
* @return  void
*
*/
void Psi5_S_Ip_IRQ_Global_Handler(const Psi5_S_Ip_InstanceIdType Psi5SInstanceId);

/**
 * @brief   : Prepare for timeout checking
 * @internal
 * @return  : None
 */
static inline void Psi5_S_Ip_StartTimeout(uint32 *StartTimeOut, uint32 *TimeoutTicksOut, uint32 TimeoutUs, OsIf_CounterType OsifCounter)
{
    *StartTimeOut    = OsIf_GetCounter(OsifCounter);
    *TimeoutTicksOut = OsIf_MicrosToTicks(TimeoutUs, OsifCounter);
}

/**
 * @brief   : Checks for timeout condition
 * @internal
 * @return  TRUE     Timeout occurs
 *          FALSE    Timeout does not occur
 */
static inline boolean Psi5_S_Ip_CheckTimeout(uint32 * StartTime, uint32 * ElapsedTicks, uint32 TimeoutTicks, OsIf_CounterType OsifCounter)
{
    boolean RetVal = FALSE;
    uint32 CurrentElapsedTicks = OsIf_GetElapsed(StartTime, OsifCounter);

    *ElapsedTicks += CurrentElapsedTicks;
    if (*ElapsedTicks >= TimeoutTicks)
    {
        RetVal = TRUE;
    }

    return RetVal;
}

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @}*/ /* End of addtogroup psi5s */

#endif /* PSI5_S_IP_H */
