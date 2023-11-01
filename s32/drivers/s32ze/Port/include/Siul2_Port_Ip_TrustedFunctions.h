/*
 * Copyright 2021-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Siul2_Port_Ip_TrustedFunctions.h
*
*   @addtogroup Port_IPL Port IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                1
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Port_Ip_TrustedFunctions.h and Std_Types.h file are of the same Autosar version */
    #if ((SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Port_Ip_TrustedFunctions.h and Std_Types.h are different"
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

extern void Port_Init_ClearIMCR(const Port_ConfigType * pConfigPtr);

extern void Port_Init_UnusedPins(const Port_ConfigType * pConfigPtr);

extern void Siul2_Port_Ip_PinInit(const Siul2_Port_Ip_PinSettingsConfig * config);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
extern Std_ReturnType Port_SetPinDirectionRunTime(Port_PinType PinIndex,
                                                  Port_PinDirectionType eDirection,
                                                  const Port_ConfigType * pConfigPtr
                                                 );
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#ifdef PORT_CODE_SIZE_OPTIMIZATION
#if (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)
extern Std_ReturnType Port_SetPinModeRunTime(Port_PinType PinIndex,
                                             Port_PinModeType PinMode,
                                             const Port_ConfigType * pConfigPtr
                                            );
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

extern void Port_RefreshPortDirectionRuntime(const Port_ConfigType * pConfigPtr);

#ifdef PORT_SET_AS_UNUSED_PIN_API
#if (STD_ON == PORT_SET_AS_UNUSED_PIN_API)
extern void Port_SetAsUnusedPinRunTime(Port_PinType PinIndex,
                                       const Port_ConfigType *pConfigPtr
                                      );

extern void Port_SetAsUsedPinRunTime(Port_PinType PinIndex,
                                     Port_ConfigType *pConfigPtr
                                    );
#endif /* (STD_ON == PORT_SET_AS_UNUSED_PIN_API) */
#endif /* PORT_SET_AS_UNUSED_PIN_API */

#ifdef PORT_CODE_SIZE_OPTIMIZATION
#ifdef PORT_RESET_PIN_MODE_API
#if (STD_ON == PORT_RESET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION)
extern void Port_ResetPinModeRunTime(Port_PinType PinIndex,
                                     const Port_ConfigType * pConfigPtr
                                    );
#endif /* (STD_ON == PORT_RESET_PIN_MODE_API) && (STD_OFF == PORT_CODE_SIZE_OPTIMIZATION) */
#endif /* PORT_RESET_PIN_MODE_API */
#endif /* PORT_CODE_SIZE_OPTIMIZATION */

extern void Siul2_Port_Ip_ConfigInternalResistor(Siul2_Port_Ip_PortType * const base,
                                                 uint16 pin,
                                                 Siul2_Port_Ip_PortPullConfig pullConfig
                                                );

extern void Siul2_Port_Ip_ConfigOutputBuffer(Siul2_Port_Ip_PortType * const base,
                                             uint16 pin,
                                             boolean enable,
                                             Siul2_Port_Ip_PortMux mux
                                            );

extern void Siul2_Port_Ip_ConfigInputBuffer(Siul2_Port_Ip_PortType * const base,
                                            uint16 pin,
                                            boolean enable,
                                            uint32 inputMuxReg,
                                            Siul2_Port_Ip_PortInputMux inputMux
                                           );

extern void Siul2_Port_Ip_SetPinDirection(Siul2_Port_Ip_PortType * const base,
                                          uint16 pin,
                                          Siul2_Port_Ip_PortDirectionType direction
                                         );

extern uint32 Siul2_Port_Ip_GetValueConfigRevertPin(const Siul2_Port_Ip_PortType * const base,
                                                    uint16 pin
                                                   );

extern void Siul2_Port_Ip_GetValuePinConfiguration(const Siul2_Port_Ip_PortType * const base,
                                                   Siul2_Port_Ip_PinSettingsConfig * config,
                                                   uint16 pin
                                                  );

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H */
