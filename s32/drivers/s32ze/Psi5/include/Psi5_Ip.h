/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PSI5_IP_H
#define PSI5_IP_H

#if defined(__cplusplus)
extern "C" {
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Psi5_Ip_Types.h"
#include "Psi5_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFOPSI5ATION
==================================================================================================*/
#define PSI5_IP_VENDOR_ID                      43
#define PSI5_IP_AR_RELEASE_MAJOR_VERSION       4
#define PSI5_IP_AR_RELEASE_MINOR_VERSION       7
#define PSI5_IP_AR_RELEASE_REVISION_VERSION    0
#define PSI5_IP_SW_MAJOR_VERSION               2
#define PSI5_IP_SW_MINOR_VERSION               0
#define PSI5_IP_SW_PATCH_VERSION               1


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Psi5_Ip_Types.h */
#if (PSI5_IP_VENDOR_ID != PSI5_IP_TYPES_VENDOR_ID)
    #error "Psi5_Ip.h and Psi5_Ip_Types.h have different vendor ids"
#endif
#if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_MINOR_VERSION    != PSI5_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_REVISION_VERSION != PSI5_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip.h and Psi5_Ip_Types.h are different"
#endif
#if ((PSI5_IP_SW_MAJOR_VERSION != PSI5_IP_TYPES_SW_MAJOR_VERSION) || \
     (PSI5_IP_SW_MINOR_VERSION != PSI5_IP_TYPES_SW_MINOR_VERSION) || \
     (PSI5_IP_SW_PATCH_VERSION != PSI5_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip.h and Psi5_Ip_Types.h are different"
#endif

/* Checks against Psi5_Ip_Cfg.h */
#if (PSI5_IP_VENDOR_ID != PSI5_IP_CFG_VENDOR_ID)
    #error "Psi5_Ip.h and Psi5_Ip_Cfg.h have different vendor ids"
#endif
#if ((PSI5_IP_AR_RELEASE_MAJOR_VERSION    != PSI5_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_MINOR_VERSION    != PSI5_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PSI5_IP_AR_RELEASE_REVISION_VERSION != PSI5_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Psi5_Ip.h and Psi5_Ip_Cfg.h are different"
#endif
#if ((PSI5_IP_SW_MAJOR_VERSION != PSI5_IP_CFG_SW_MAJOR_VERSION) || \
     (PSI5_IP_SW_MINOR_VERSION != PSI5_IP_CFG_SW_MINOR_VERSION) || \
     (PSI5_IP_SW_PATCH_VERSION != PSI5_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Psi5_Ip.h and Psi5_Ip_Cfg.h are different"
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
PSI5_IP_CONFIG_EXT

#define PSI5_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Psi5_MemMap.h"

#define PSI5_START_SEC_CODE
#include "Psi5_MemMap.h"


/**
* @brief   Interrupt handler signature for PSI5 module.
*
* @param[in] Psi5InstanceId Instance number
* @param[in] Psi5ChannelId Instance channel number
* @return            void
*
*/
void Psi5_Ip_IRQ_Handler(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                         const Psi5_Ip_HwChannelIdType Psi5ChannelId
                        );
/*!
 * @brief Main initializer for the driver
 *
 * Initializes the driver for a given peripheral
 * according to the given configuration structure.
 *
 * @param[in] configPtr Pointer to the configuration structure
 */
void Psi5_Ip_Init(const Psi5_Ip_ConfigType *configPtr);

/*!
 * @brief Reset the peripheral.
 *
 * De-Initializes the peripheral and brings it's registers into a reset state.
 *
 */
void Psi5_Ip_DeInit(void);

#if (STD_ON == PSI5_IP_TRANSMIT_API)
/*!
 * @brief Transmit a data frame
 *
 * Transmits a data frame according to configuration.
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5ChannelId Channel number
 * @param[in] Psi5Data Data to send
 * @return STATUS_SUCCESS If transmit succeeded
 * @return STATUS_ERROR If not configured or not enabled or not ready
 */
Std_ReturnType Psi5_Ip_Transmit(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                const uint64 Psi5Data
                               );
#endif

#if (STD_ON == PSI5_IP_GET_TRANSMISSION_STATUS_API)
/*!
 * @brief Transmission status
 *
 * Returns the status of the transmission.
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5ChannelId Channel number
 * @return true If transmission ready
 * @return false If transmission pending
 */
boolean Psi5_Ip_GetTransmissionStatus(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                      const Psi5_Ip_HwChannelIdType Psi5ChannelId
                                     );
#endif

#if (STD_ON == PSI5_IP_GET_PSI5_FRAME_API)
/*!
 * @brief Gets a PSI5 frame
 *
 * Returns the last received PSI5 frame.
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5ChannelId Channel number
 * @param[out] Psi5FramePtr Target variable
 */
Std_ReturnType Psi5_Ip_GetPsi5Frame(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                    const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                    Psi5_Ip_Psi5FrameType *PsiFramePtr
                                   );
#endif

#if (STD_ON == PSI5_IP_GET_SMC_FRAME_API)
/*!
 * @brief Gets a SMC frame
 *
 * Returns the last received SMC frame.
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5ChannelId Channel number
 * @param[out] Psi5FramePtr Target variable
 */
Std_ReturnType Psi5_Ip_GetSmcFrame(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                   const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                   Psi5_Ip_SmcFrameType *Psi5SmcFramePtr
                                  );
#endif

#if (STD_ON == PSI5_IP_SET_GLOBAL_SYNC_API)
/*!
 * @brief Global sync state
 *
 * Changes the global sync pulse generator state
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5State Desired state
 */
Std_ReturnType Psi5_Ip_SetGlobalSync(const uint8 Psi5InstanceId,
                                     const boolean PsiState
                                    );
#endif

#if (STD_ON == PSI5_IP_SET_CHANNEL_SYNC_API)
/*!
 * @brief Channel sync state
 *
 * Changes the channel sync pulse generator state
 *
 * @param[in] Psi5InstanceId Instance number
 * @param[in] Psi5ChannelId Instance channel number
 * @param[in] Psi5State Desired state
 */
Std_ReturnType Psi5_Ip_SetChannelSync(const Psi5_Ip_InstanceIdType Psi5InstanceId,
                                      const Psi5_Ip_HwChannelIdType Psi5ChannelId,
                                      const boolean PsiState
                                     );
#endif

#define PSI5_STOP_SEC_CODE
#include "Psi5_MemMap.h"

#if defined(__cplusplus)
}
#endif

/*! @}*/

/*! @}*/ /* End of addtogroup psi5 */

#endif /* PSI5_IP_H */
