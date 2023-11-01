/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_DIO_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Siul2_Dio_Ip_TrustedFunctions.h
*
*   @addtogroup Dio_IPL Dio IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                1
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define SIUL2_DIO_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Dio_Ip_TrustedFunctions.h and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_DIO_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_DIO_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Dio_Ip_TrustedFunctions.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

extern void Siul2_Dio_Ip_WritePinRunTime(Siul2_Dio_Ip_GpioType * const base,
                                         Siul2_Dio_Ip_PinsChannelType pin,
                                         Siul2_Dio_Ip_PinsLevelType value
                                        );

extern void Siul2_Dio_Ip_WritePinsRunTime(Siul2_Dio_Ip_GpioType * const base,
                                          Siul2_Dio_Ip_PinsChannelType pins
                                         );

extern Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_GetPinsOutputRunTime(const Siul2_Dio_Ip_GpioType * const base);

extern void Siul2_Dio_Ip_SetPinsRunTime(Siul2_Dio_Ip_GpioType * const base,
                                        Siul2_Dio_Ip_PinsChannelType pins
                                       );

extern void Siul2_Dio_Ip_ClearPinsRunTime(Siul2_Dio_Ip_GpioType * const base,
                                          Siul2_Dio_Ip_PinsChannelType pins
                                         );

extern void Siul2_Dio_Ip_TogglePinsRunTime(Siul2_Dio_Ip_GpioType * const base,
                                           Siul2_Dio_Ip_PinsChannelType pins
                                          );

extern Siul2_Dio_Ip_PinsChannelType Siul2_Dio_Ip_ReadPinsRunTime(const Siul2_Dio_Ip_GpioType * const base);

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
extern void Siul2_Dio_Ip_MaskedWritePinsRunTime(uint8 u8Siul2Instance,
                                                uint8 u8PortId,
                                                Siul2_Dio_Ip_PinsChannelType pins,
                                                Siul2_Dio_Ip_PinsChannelType mask
                                               );
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

extern Siul2_Dio_Ip_PinsLevelType Siul2_Dio_Ip_ReadPinRunTime(const Siul2_Dio_Ip_GpioType * const base,
                                                              Siul2_Dio_Ip_PinsChannelType pin
                                                             );

extern Dio_LevelType Dio_ReadChannelRunTime(Dio_ChannelType ChannelId);

extern void Dio_WriteChannelRunTime(Dio_ChannelType ChannelId,
                                    Dio_LevelType Level
                                   );

#if (STD_ON == DIO_FLIP_CHANNEL_API)
extern Dio_LevelType Dio_FlipChannelRunTime(Dio_ChannelType ChannelId);
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
extern Dio_PortLevelType Dio_ReadPortRunTime(Dio_PortType PortId);
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
extern void Dio_WritePortRunTime(Dio_PortType PortId,
                                 Dio_PortLevelType Level
                                );
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
extern Dio_PortLevelType Dio_ReadChannelGroupRunTime(const Dio_ChannelGroupType * pChannelGroupIdPtr);
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
extern void Dio_WriteChannelGroupRunTime(const Dio_ChannelGroupType * pChannelGroupIdPtr,
                                         Dio_PortLevelType Level
                                        );
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

#if (STD_OFF == DIO_VIRTWRAPPER_SUPPORT)
#if ((STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__))
extern void Dio_MaskedWritePortRunTime(Dio_PortType PortId,
                                       Dio_PortLevelType Level,
                                       Dio_PortLevelType Mask
                                      );
#endif /* ((STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__)) */
#endif /* (STD_OFF == DIO_VIRTWRAPPER_SUPPORT) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_DIO_IP_TRUSTEDFUNCTIONS_H */
