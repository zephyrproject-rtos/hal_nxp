/*
 * Copyright 2021-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SWT_IP_H
#define SWT_IP_H

/**
*   @file
*
*   @addtogroup Swt
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Swt_Ip_Types.h"
#include "Swt_Ip_DeviceRegisters.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SWT_IP_VENDOR_ID                    43
#define SWT_IP_MODULE_ID                    102
#define SWT_IP_AR_RELEASE_MAJOR_VERSION     4
#define SWT_IP_AR_RELEASE_MINOR_VERSION     7
#define SWT_IP_AR_RELEASE_REVISION_VERSION  0
#define SWT_IP_SW_MAJOR_VERSION             0
#define SWT_IP_SW_MINOR_VERSION             9
#define SWT_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Swt_Ip_Types header file are of the same vendor */
#if (SWT_IP_VENDOR_ID != SWT_IP_TYPES_VENDOR_ID)
#error "Swt_Ip.h and Swt_Ip_Types.h have different vendor ids"
#endif

#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION    != SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION    != SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION != SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip.h and Swt_Ip_Types.h are different"
#endif

#if ((SWT_IP_SW_MAJOR_VERSION != SWT_IP_TYPES_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION != SWT_IP_TYPES_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION != SWT_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip.h and Swt_Ip_Types.h are different"
#endif

/* Check if current file and Swt_Ip_DeviceRegisters header file are of the same vendor */
#if (SWT_IP_VENDOR_ID != SWT_IP_DEVICE_REGISTERS_VENDOR_ID)
#error "Swt_Ip.h and Swt_Ip_DeviceRegisters.h have different vendor ids"
#endif

#if ((SWT_IP_AR_RELEASE_MAJOR_VERSION    != SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (SWT_IP_AR_RELEASE_MINOR_VERSION    != SWT_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (SWT_IP_AR_RELEASE_REVISION_VERSION != SWT_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Swt_Ip.h and Swt_Ip_DeviceRegisters.h are different"
#endif

#if ((SWT_IP_SW_MAJOR_VERSION != SWT_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (SWT_IP_SW_MINOR_VERSION != SWT_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (SWT_IP_SW_PATCH_VERSION != SWT_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Swt_Ip.h and Swt_Ip_DeviceRegisters.h are different"
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

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

/*!
 * @brief       Initialize SWT instance.
 * @details     This Initializes SWT instance with the configuration passed via
 *              ConfigPtr pointer.
 *
 * @param[in]   Instance     SWT Instance number.
 * @param[in]   ConfigPtr  Pointer to the configuration structure 
 *                              which will be used to configure the SWT driver
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
Swt_Ip_StatusType Swt_Ip_Init(const uint32 Instance,
                        const Swt_Ip_ConfigType * const ConfigPtr);

#if (SWT_IP_DEINIT == STD_ON)
/*!
 * @brief       De-Initializes SWT instance.
 * @details     This function De-Initializes SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
    Swt_Ip_StatusType Swt_Ip_Deinit(const uint32 Instance);
#endif


/*!
 * @brief       Services the SWT instance.
 * @details     This function services SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 *
 * @return      void
 */
 void Swt_Ip_Service(const uint32 Instance);


/*!
 * @brief       Configure SWT instance.
 * @details     This function configure SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 * @param[in]   ConfigPtr  Pointer to the configuration structure
 *                              which will be used to configure the SWT driver
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
Swt_Ip_StatusType Swt_Ip_Config(const uint32 Instance,
                            const Swt_Ip_ConfigType * const ConfigPtr);

/*!
 * @brief       Sets the timeout value for SWT instance.
 * @details     This function sets the timeout value for SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 * @param[in]   TimeoutValue SWT timeout value
 * @param[in]   WindowValue  SWT window value
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
Swt_Ip_StatusType Swt_Ip_SetTimeout(const uint32 Instance,
                                const uint32 TimeoutValue, const uint32 WindowValue);

/*!
 * @brief       Starts the timer of SWT instance.
 * @details     This function starts the timer of the SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
Swt_Ip_StatusType Swt_Ip_StartTimer(const uint32 Instance);

/*!
 * @brief       Stops the timer of SWT instance.
 * @details     This function stops the timer of the SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 *
 * @return      An error code or SWT_IP_STATUS_SUCCESS
 */
Swt_Ip_StatusType Swt_Ip_StopTimer(const uint32 Instance);

#if (SWT_IP_DEINIT == STD_ON)
#if (SWT_IP_CLEAR_RESET_REQUEST == STD_ON)
/*!
 * @brief       Clear reset request.
 * @details     This function clear the reset request for SWT instance.
 *
 * @param[in]   Instance     SWT Instance number
 *
 * @return                             Swt_Ip_StatusType.
 * @retval  SWT_IP_STATUS_SUCCESS      Clear reset request successfully.
 * @retval  SWT_IP_STATUS_ERROR        Clear reset request encountered error 
 *                                     caused by unlock sequence failed.
 */
    Swt_Ip_StatusType Swt_Ip_ClearResetRequest(const uint32 Instance);
#endif
#endif


#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*SWT_IP_H */

