/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_CFG_DEFINES_H
#define XSPI_IP_CFG_DEFINES_H

/**
*   @file Xspi_Ip_CfgDefines.h
*
*   @addtogroup IPV_XSPI
*   @{
*/

/* implements Xspi_Ip_CfgDefines.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_VENDOR_ID_CFG_DEFINES                    43
#define XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     9
#define XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define XSPI_IP_SW_MAJOR_VERSION_CFG_DEFINES             0
#define XSPI_IP_SW_MINOR_VERSION_CFG_DEFINES             8
#define XSPI_IP_SW_PATCH_VERSION_CFG_DEFINES             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Enable using SFDP config */
#define XSPI_IP_USE_SFDP_CFG                         (STD_OFF)

/* Enable calculates CRC for items */
#define XSPI_IP_CHECK_CFG_CRC                        (STD_OFF)

#define XSPI_IP_HYPERRAM_ENABLED                     (STD_ON)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_CFG_DEFINES_H */


