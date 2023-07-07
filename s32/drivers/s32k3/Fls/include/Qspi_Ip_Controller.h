/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_CONTROLLER_H
#define QSPI_IP_CONTROLLER_H

/**
*   @file Qspi_Ip_Controller.h
*
*   @addtogroup IPV_QSPI QSPI IPV Driver
*   @{
*/

/* implements Qspi_Ip_Controller.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Qspi_Ip_Types.h"
#include "Qspi_Ip_Cfg.h"
#include "Qspi_Ip_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_CONTROLLER_VENDOR_ID_H                       43
#define QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H                3
#define QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H                0
#define QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types.h header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_H != FLS_QSPI_TYPES_VENDOR_ID)
    #error "Qspi_Ip_Controller.h and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types.h header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != FLS_QSPI_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != FLS_QSPI_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != FLS_QSPI_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types.h header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != FLS_QSPI_TYPES_SW_MAJOR_VERSION) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != FLS_QSPI_TYPES_SW_MINOR_VERSION) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != FLS_QSPI_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Types.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg.h header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_H != QSPI_IP_VENDOR_ID_CFG)
    #error "Qspi_Ip_Controller.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg.h header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Cfg.h are different"
#endif

/* Check if current file and Qspi_Ip_Common.h header file are of the same vendor */
#if (QSPI_IP_CONTROLLER_VENDOR_ID_H != QSPI_IP_COMMON_VENDOR_ID_H)
    #error "Qspi_Ip_Controller.h and Qspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Common.h header file are of the same Autosar version */
#if ((QSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != QSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != QSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != QSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Common.h are different"
#endif
/* Check if current file and Qspi_Ip_Common.h header file are of the same Software version */
#if ((QSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != QSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != QSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (QSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != QSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip_Controller.h and Qspi_Ip_Common.h are different"
#endif

#if (QSPI_IP_MEM_INSTANCE_COUNT > 0)

/*******************************************************************************
 * Macros
 ******************************************************************************/
#if (QSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)
     #define Qspi_Ip_WriteLuts(Instance, StartLutRegister, Data, Size) \
             OsIf_Trusted_Call4params(Qspi_Ip_WriteLuts_Privileged, Instance, StartLutRegister, Data, Size)

     #define Qspi_Ip_SetAhbSeqId(instance, seqID) \
             OsIf_Trusted_Call2params(Qspi_Ip_SetAhbSeqId_Privileged, instance, seqID)

#else
     #define Qspi_Ip_WriteLuts(Instance, StartLutRegister, Data, Size) \
             Qspi_Ip_WriteLuts_Privileged(Instance, StartLutRegister, Data, Size)

     #define Qspi_Ip_SetAhbSeqId(instance, seqID) \
             Qspi_Ip_SetAhbSeqId_Privileged(instance, seqID)

#endif

/*******************************************************************************
 * Enumerations.
 ******************************************************************************/

/*******************************************************************************
* Definitions
******************************************************************************/

#define FLS_START_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"

extern QuadSPI_Type * const Qspi_Ip_BaseAddress[];

#define FLS_STOP_SEC_CONST_UNSPECIFIED
#include "Fls_MemMap.h"


#define FLS_START_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"

/* The padding bytes information to handle unaligned read/write operation for QuadSPI instances */
extern uint8 Qspi_Ip_MemoryPadding[QuadSPI_INSTANCE_COUNT];

#define FLS_STOP_SEC_VAR_CLEARED_8
#include "Fls_MemMap.h"


/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @name QuadSPI Driver
 * @{
 */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"



/*!
 * @brief Configures LUT commands
 *
 * This function configures a pair of LUT commands in the specified LUT register.
 * LUT sequences start at index multiple of 4 and can have up to 8 commands
 *
 * @param instance     QuadSPI peripheral instance number
 * @param LutRegister  Index in physical LUT array
 * @param operation0   First operation
 * @param operation1   Second operation
 * Implements      Qspi_Ip_SetLut_Activity
 */
void Qspi_Ip_SetLut(uint32 instance,
                    uint8 LutRegister,
                    Qspi_Ip_InstrOpType operation0,
                    Qspi_Ip_InstrOpType operation1
                   );

/*!
 * @brief Configures LUT commands
 *
 * This function configures pairs of LUT commands from the specified LUT register.
 *
 * @param Instance          QuadSPI peripheral instance number
 * @param StartLutRegister  Start index in physical LUT array
 * @param Data              Data to be written in LUT register
 * @param Size              Size of data buffer
 */
void Qspi_Ip_WriteLuts_Privileged(uint32 Instance,
                                  uint8 StartLutRegister,
                                  const uint32 *Data,
                                  uint8 Size
                                 );

/*!
 * @brief Sets sequence ID for AHB operations
 *
 * @param instance     QuadSPI peripheral instance number
 * @param seqID        Sequence ID in LUT for read operation
 * Implements   Qspi_Ip_SetAhbSeqId_Activity
 */
void Qspi_Ip_SetAhbSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   );

/*!
 * @brief Returns the physical base address of a flash device
 *
 * This function returns the physical base address of a flash device, depending on the QSPI connection.
 * The controller must be initialized prior to calling this function.
 *
 * @param instance        QuadSPI peripheral instance number
 * @param connectionType  Connection of the flash device to QSPI
 */
uint32 Qspi_Ip_GetBaseAdress(uint32 instance,
                             Qspi_Ip_ConnectionType connectionType
                            );

/*!
 * @brief Launches a simple IP command
 *
 * @param instance     QuadSPI peripheral instance number
 * @param SeqId        Sequence ID where the command is to be found
 * @param addr         Address of the target serial flash
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_IpCommand(uint32 instance,
                                     uint8 SeqId,
                                     uint32 addr
                                    );


/*!
 * @brief Launches an IP read command
 *
 * This function can launch a read command in 3 modes:
 * - normal read (dataRead != NULL_PTR): Data is read from serial flash and placed in the buffer
 * - verify (dataRead == NULL_PTR, dataCmp != NULL_PTR): Data is read from serial flash and compared to the reference buffer
 * - blank check (dataRead == NULL_PTR, dataCmp == NULL_PTR): Data is read from serial flash and compared to 0xFF
 * Only normal read mode can use DMA.
 *
 * @param instance       QuadSPI peripheral instance number
 * @param SeqId          Sequence ID where the command is to be found
 * @param addr           Start address for read operation in serial flash
 * @param dataRead       Buffer where to store read data
 * @param dataCmp        Buffer to be compared to read data
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_IpRead(uint32 instance,
                                  uint8 SeqId,
                                  uint32 addr,
                                  uint8 * dataRead,
                                  const uint8 * dataCmp,
                                  uint32 size
                                 );


/*!
 * @brief Launches an IP write command
 *
 * @param instance       QuadSPI peripheral instance number
 * @param SeqId          Sequence ID where the command is to be found
 * @param addr           Start address for write operation in serial flash
 * @param data           Data to be programmed in flash
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_IpWrite(uint32 instance,
                                   uint8 SeqId,
                                   uint32 addr,
                                   const uint8 * data,
                                   uint32 size
                                  );


#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#endif /* (QSPI_IP_MEM_INSTANCE_COUNT > 0) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* QSPI_IP_CONTROLLER_H */
