/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_CONTROLLER_H
#define XSPI_IP_CONTROLLER_H

/**
*   @file Xspi_Ip_Controller.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip_Controller.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Xspi_Ip_Types.h"
#include "Xspi_Ip_Cfg.h"
#include "Xspi_Ip_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_CONTROLLER_VENDOR_ID_H                       43
#define XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H        4
#define XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H        9
#define XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H     0
#define XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H                0
#define XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H                8
#define XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Types.h header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_H != XSPI_IP_TYPES_VENDOR_ID)
    #error "Xspi_Ip_Controller.h and Xspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Types.h are different"
#endif
/* Check if current file and Xspi_Ip_Types.h header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != XSPI_IP_TYPES_SW_MAJOR_VERSION) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != XSPI_IP_TYPES_SW_MINOR_VERSION) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != XSPI_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Types.h are different"
#endif

/* Check if current file and Xspi_Ip_Cfg.h header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_H != XSPI_IP_VENDOR_ID_CFG)
    #error "Xspi_Ip_Controller.h and Xspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Cfg.h header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Xspi_Ip_Cfg.h header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != XSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != XSPI_IP_SW_MINOR_VERSION_CFG) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != XSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Cfg.h are different"
#endif

/* Check if current file and Xspi_Ip_Common.h header file are of the same vendor */
#if (XSPI_IP_CONTROLLER_VENDOR_ID_H != XSPI_IP_COMMON_VENDOR_ID_H)
    #error "Xspi_Ip_Controller.h and Xspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Common.h header file are of the same Autosar version */
#if ((XSPI_IP_CONTROLLER_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Common.h are different"
#endif
/* Check if current file and Xspi_Ip_Common.h header file are of the same Software version */
#if ((XSPI_IP_CONTROLLER_SW_MAJOR_VERSION_H != XSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_MINOR_VERSION_H != XSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (XSPI_IP_CONTROLLER_SW_PATCH_VERSION_H != XSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip_Controller.h and Xspi_Ip_Common.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

#if (XSPI_IP_MEM_INSTANCE_COUNT > 0)

#if (XSPI_IP_ENABLE_USER_MODE_SUPPORT == STD_ON)

#define Xspi_Ip_SetLutSeq(instance, lutSeqNo, opList)               OsIf_Trusted_Call3params(Xspi_Ip_SetLutSeq_Privileged, instance, lutSeqNo, opList)
#define Xspi_Ip_SetAhbSeqId(instance, seqID)                        OsIf_Trusted_Call2params(Xspi_Ip_SetAhbSeqId_Privileged, instance, seqID)
#define Xspi_Ip_SetAhbWriteSeqId(instance, seqID)                   OsIf_Trusted_Call2params(Xspi_Ip_SetAhbWriteSeqId_Privileged, instance, seqID)
#define Xspi_Ip_SetLutAccess(instance, accessRights)                OsIf_Trusted_Call2params(Xspi_Ip_SetLutAccess_Privileged, instance, accessRights)
#define Xspi_Ip_ControllerTimeoutsConfig(instance, userConfigPtr)   OsIf_Trusted_Call2params(Xspi_Ip_ControllerTimeoutsConfig_Privileged, instance, userConfigPtr)

#else /* XSPI_IP_ENABLE_USER_MODE_SUPPORT */

#define Xspi_Ip_SetLutSeq(instance, lutSeqNo, opList)               Xspi_Ip_SetLutSeq_Privileged(instance, lutSeqNo, opList)
#define Xspi_Ip_SetAhbSeqId(instance, seqID)                        Xspi_Ip_SetAhbSeqId_Privileged(instance, seqID)
#define Xspi_Ip_SetAhbWriteSeqId(instance, seqID)                   Xspi_Ip_SetAhbWriteSeqId_Privileged(instance, seqID)
#define Xspi_Ip_SetLutAccess(instance, accessRights)                Xspi_Ip_SetLutAccess_Privileged(instance, accessRights)
#define Xspi_Ip_ControllerTimeoutsConfig(instance, userConfigPtr)   Xspi_Ip_ControllerTimeoutsConfig_Privileged(instance, userConfigPtr)

#endif /* XSPI_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

#define MEM_43_EXFLS_START_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

extern XSPI_Type * const Xspi_Ip_BaseAddress[];

#define MEM_43_EXFLS_STOP_SEC_CONST_UNSPECIFIED
#include "Mem_43_EXFLS_MemMap.h"

#define MEM_43_EXFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

/* The padding bytes information to handle unaligned read/write operation for XSPI instances */
extern uint8 Xspi_Ip_MemoryPadding;

#define MEM_43_EXFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_EXFLS_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/*!
 * @name XSPI Driver
 * @{
 */

#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

/*!
 * @brief Configures LUT commands
 *
 * This function configures a pair of LUT commands in the specified LUT register.
 * LUT sequences start at index multiple of 4 and can have up to 8 commands
 *
 * @param instance     XSPI peripheral instance number
 * @param LutRegister  Sequence index in physical LUT array
 * @param opList       List of operations; operation XSPI_IP_LUT_SEQ_END marks the end of the sequence
 * Implements      Xspi_Ip_SetLutSeq_Activity
 */
void Xspi_Ip_SetLutSeq_Privileged(uint32 instance,
                                  uint8 lutSeqNo,
                                  const Xspi_Ip_InstrOpType *opList
                                 );

/*!
 * @brief Sets sequence ID for AHB operations
 *
 * @param instance     XSPI peripheral instance number
 * @param seqID        Sequence ID in LUT for read operation
 * Implements   Xspi_Ip_SetAhbSeqId_Activity
 */
void Xspi_Ip_SetAhbSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   );

/*!
 * @brief Sets sequence ID for AHB wrte operations
 *
 * @param instance     XSPI peripheral instance number
 * @param seqID        Sequence ID in LUT for read operation
 *
 */
void Xspi_Ip_SetAhbWriteSeqId_Privileged(uint32 instance,
                                    uint8 seqID
                                   );

/*!
 * @brief Configures access rights of HIFs to LUTs
 *
 * @param instance      XSPI peripheral instance number
 * @param accessRights  List of access rights, of length XSPI_MDAD_COUNT; each element specifies the access rights for a HIF.
 * Implements   Xspi_Ip_SetLutAccess_Activity
 */
void Xspi_Ip_SetLutAccess_Privileged(uint32 instance,
                                     const uint16 *accessRights
                                    );

/*!
 * @brief Returns the physical base address of a host interface, either master or user.
 *
 * @param instance      XSPI peripheral instance number
 * @param hifNo         HIF number. 0 = Master HIF
 * Implements   Xspi_Ip_ControllerGetHifAdress_Activity
 */
XSPI_Type * Xspi_Ip_ControllerGetHifAdress(uint32 instance,
                                               uint8 hifNo
                                              );

/*!
 * @brief Returns the physical base address of a flash device
 *
 * This function returns the physical base address of a flash device, depending on the XSPI connection.
 * The controller must be initialized prior to calling this function.
 *
 * @param instance        XSPI peripheral instance number
 * @param connectionType  Connection of the flash device to XSPI
 */
uint32 Xspi_Ip_ControllerGetBaseAdress(uint32 instance,
                                       Xspi_Ip_ConnectionType connectionType
                                      );


/*!
 * @brief Launches a simple IP command
 *
 * @param baseAddr     Base address of the host interface
 * @param SeqId        Sequence ID where the command is to be found
 * @param addr         Address of the target serial flash
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_IpCommand(XSPI_Type *baseAddr,
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
 *
 * @param baseAddr       Base address of the host interface
 * @param SeqId          Sequence ID where the command is to be found
 * @param addr           Start address for read operation in serial flash
 * @param dataRead       Buffer where to store read data
 * @param dataCmp        Buffer to be compared to read data
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_IpRead(XSPI_Type *baseAddr,
                                  uint8 SeqId,
                                  uint32 addr,
                                  uint8 * dataRead,
                                  const uint8 * dataCmp,
                                  uint32 size
                                 );

/*!
 * @brief Launches an async read command with arbitration lock request
 *
 * @param baseAddr     Base address of the host interface
 * @param SeqId        Sequence ID where the command is to be found
 * @param addr         Address of the target serial flash
 * @param size         Size of read data
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerArbLock(XSPI_Type *baseAddr,
                                             uint8 SeqId,
                                             uint32 addr,
                                             uint32 size
                                            );

/*!
 * @brief Checks the completion status of an async IP command
 *
 * @param baseAddr     Base address of the host interface
 * @return             Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerGetStatus(XSPI_Type *baseAddr);

/*!
 * @brief Check for master errors.
 *
 * @param baseAddr  Base address of the host interface
 *
 * @return          Error status
 * @retval          TRUE, if there were master error flags found
 * @retval          FALSE, if there were no master error flags found
 */
boolean Xspi_Ip_GotMasterErrors(XSPI_Type *baseAddr);

/*!
 * @brief Clear the master errors.
 *
 * @param baseAddr  Base address of the host interface
 */
void Xspi_Ip_ClearMasterErrors(XSPI_Type *baseAddr);

/*!
 * @brief Completes an async read command
 *
 * This function completes an async read command by reading the data from the Rx FIFO.
 *
 * @param baseAddr       Base address of the host interface
 * @param dataRead       Buffer where to store read data
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_IpCompleteAsyncRead(XSPI_Type *baseAddr,
                                               uint8 * dataRead,
                                               uint32 size
                                              );

/*!
 * @brief Unlocks arbitration.
 *
 * This function Launches a sync read command with arbitration unlock request.
 *
 * @param baseAddr       Base address of the host interface
 * @param SeqId          Sequence ID where the command is to be found
 * @param addr           Start address for read operation in serial flash
 * @param dataRead       Buffer where to store read data
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerArbUnlock(XSPI_Type *baseAddr,
                                               uint8 SeqId,
                                               uint32 addr,
                                               uint8 * dataRead,
                                               uint32 size
                                              );

/*!
 * @brief Launches a sync write command
 *
 * @param baseAddr       Base address of the host interface
 * @param SeqId          Sequence ID where the command is to be found
 * @param addr           Start address for write operation in serial flash
 * @param data           Data to be programmed in flash
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_IpWrite(XSPI_Type *baseAddr,
                                   uint8 SeqId,
                                   uint32 addr,
                                   const uint8 * data,
                                   uint32 size
                                  );
/*!
 * @brief Aborts any on-going transactions
 *
 * Force the Xspi controller to cancel the on-going IP transaction by performing the software reset sequence.
 *
 * @param instance     XSPI peripheral instance number
 * @return             Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_Abort(uint32 instance);

#if (XSPI_IP_CHECK_CFG_CRC == STD_ON)
/*!
 * @brief Calculate and check the CRC of memory device configurations set
 *
 * @return             Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ValidateMemConfigCRC(const Xspi_Ip_MemoryConfigType * pxConfig,
                                                const Xspi_Ip_MemoryConnectionType * pxConnect
                                               );
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Xspi_Ip_IpHyperRamErase
 * Description   : Launches a sync write command
*/
Xspi_Ip_StatusType Xspi_Ip_IpHyperRamErase( XSPI_Type *baseAddr,
                                            uint8 SeqId,
                                            uint32 addr,
                                            uint32 size
                                          );

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

#endif /* (XSPI_IP_MEM_INSTANCE_COUNT > 0) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* XSPI_IP_CONTROLLER_H */
