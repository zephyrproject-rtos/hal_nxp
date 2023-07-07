/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_HYPERFLASH_H
#define QSPI_IP_HYPERFLASH_H

/**
*   @file Qspi_Ip_Hyperflash.h
*
*   @addtogroup FLS
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
 *                                        INCLUDE FILES
==================================================================================================*/
#include "Qspi_Ip_Types.h"


/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_HYPERFLASH_VENDOR_ID_H                    43
#define QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_H     4
#define QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_H     7
#define QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_H  0
#define QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_H             3
#define QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_H             0
#define QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_H             0

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types header file are of the same vendor */
#if (QSPI_IP_HYPERFLASH_VENDOR_ID_H != FLS_QSPI_TYPES_VENDOR_ID)
    #error "Qspi_Ip_Hyperflash.h and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Autosar version */
#if ((QSPI_IP_HYPERFLASH_AR_RELEASE_MAJOR_VERSION_H    != FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_MINOR_VERSION_H    != FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_HYPERFLASH_AR_RELEASE_REVISION_VERSION_H != FLS_QSPI_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Hyperflash.h and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Software version */
#if ((QSPI_IP_HYPERFLASH_SW_MAJOR_VERSION_H != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (QSPI_IP_HYPERFLASH_SW_MINOR_VERSION_H != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (QSPI_IP_HYPERFLASH_SW_PATCH_VERSION_H != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_Hyperflash.h and Qspi_Ip_Types.h are different"
#endif


/*******************************************************************************
 * API
 ******************************************************************************/

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"


/*!
 * @brief Initializes the hyper flash memory device
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashInit(uint32 instance);


/*!
 * @brief Erases a specific sector.
 *
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashSectorErase(uint32 instance,
                                                 uint32 sectorAddress
                                                );


/*!
 * @brief Chip erase
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashChipErase(uint32 instance);


/*!
 * @brief Writes between 1 and 512 bytes to write buffer. Addresses should be on the same line of data buffer.
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashProgram(uint32 instance,
                                             uint32 address,
                                             const uint8 * data,
                                             uint32 size
                                            );


/*!
 * @brief Read manufacturer ID from hyper flash.
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashReadId(uint32 instance,
                                            uint32 wordAddress,
                                            uint8 * data,
                                            uint32 size
                                           );


/*!
 * @brief Checks if the chip or a specific sector is erased
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashSectorBlankCheck(uint32 instance,
                                                      uint32 sectorAddress
                                                     );


/*!
 * @brief Returns the status of the last command
 */
Qspi_Ip_StatusType Qspi_Ip_HyperflashGetMemoryStatus(uint32 instance);


/*!
 * @brief Patch a read command with the configured dummy cycles count
 */
void Qspi_Ip_HyperflashPatchReadCommand(uint32 instance,
                                        uint16 lut
                                       );


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#endif /* QSPI_IP_MEM_INSTANCE_COUNT */

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* QSPI_IP_HYPERFLASH_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
