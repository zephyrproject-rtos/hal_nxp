/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_CFG_DEFINES_H
#define QSPI_IP_CFG_DEFINES_H

/**
*   @file Qspi_Ip_CfgDefines.h
*
*   @addtogroup IPV_QSPI
*   Qspi_Ip_CfgDefines.h_Artifact
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
#include <zephyr/devicetree.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_CFG_DEFINES                    43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES     4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG_DEFINES     7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG_DEFINES  0
#define QSPI_IP_SW_MAJOR_VERSION_CFG_DEFINES             2
#define QSPI_IP_SW_MINOR_VERSION_CFG_DEFINES             0
#define QSPI_IP_SW_PATCH_VERSION_CFG_DEFINES             1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


#define QSPI_IP_SFP_ENABLE_MDAD                      DT_HAS_COMPAT_STATUS_OKAY(nxp_s32_qspi_sfp_mdad)
#define QSPI_IP_SFP_ENABLE_FRAD                      DT_HAS_COMPAT_STATUS_OKAY(nxp_s32_qspi_sfp_frad)
#define QSPI_IP_SFP_ENABLE_GLOBAL                    UTIL_OR(QSPI_IP_SFP_ENABLE_MDAD, QSPI_IP_SFP_ENABLE_FRAD)


/* Enable calculates CRC for items */
#define QSPI_IP_CHECK_CFG_CRC                        (STD_OFF)
/* Enable using SFDP config */
#define QSPI_IP_USE_SFDP_CFG                         (STD_OFF)

/* Enable Multicore support when using MemAcc*/
#define QSPI_IP_MULTICORE_ENABLED                        (STD_OFF)

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CFG_DEFINES_H */


