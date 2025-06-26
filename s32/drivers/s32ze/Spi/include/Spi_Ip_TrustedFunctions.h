/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SPI_IP_TRUSTEDFUNCTIONS_H
#define SPI_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Spi_Ip_TrustedFunctions.h
*
*
*   @brief   SPI IP driver header file.
*   @details SPI IP driver header file.

*   @addtogroup SPI_DRIVER Spi Driver
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
#include "Spi_Ip_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define SPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define SPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define SPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                1
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Spi_Ip_TrustedFunctions.h header file and Spi_Ip_Cfg.h configuration header file are of the same vendor */
#if (SPI_IP_TRUSTEDFUNCTIONS_VENDOR_ID != SPI_IP_VENDOR_ID_CFG)
    #error "Spi_Ip_TrustedFunctions.h and Spi_Ip_Cfg.h have different vendor IDs"
#endif
    /* Check if Spi_Ip_TrustedFunctions.h header file and Spi_Ip_Cfg.h  configuration header file are of the same Autosar version */
#if ((SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != SPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != SPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (SPI_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != SPI_IP_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Spi_Ip_TrustedFunctions.h and Spi_Ip_Cfg.h are different"
#endif
/* Check if Spi_Ip_TrustedFunctions.h header file and Spi_Ip_Cfg.h configuration header file are of the same software version */
#if ((SPI_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != SPI_IP_SW_MAJOR_VERSION_CFG) || \
     (SPI_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != SPI_IP_SW_MINOR_VERSION_CFG) || \
     (SPI_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != SPI_IP_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Spi_Ip_TrustedFunctions.h and Spi_Ip_Cfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
#include "Spi_MemMap.h"

#if (STD_ON == SPI_IP_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
* @details          This function will enable writing all SPI registers under protection in User mode by configuring REG_PROT
*
* @param[in]        Instance - SPI peripheral instance number.
*
* @return           void.
*/
extern void Spi_Ip_SetUserAccess(uint8 Instance);
#endif

#define SPI_STOP_SEC_CODE
#include "Spi_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SPI_IP_TRUSTEDFUNCTIONS_H */
