/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef XSPI_IP_H
#define XSPI_IP_H

/**
*   @file Xspi_Ip.h
*
*   @addtogroup IPV_XSPI XSPI IPV Driver
*   @{
*/

/* implements Xspi_Ip.h_Artifact */

#ifdef __cplusplus
extern "C"{
#endif

#include "Mcal.h"
#include "Xspi_Ip_Cfg.h"
#include "Xspi_Ip_Common.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define XSPI_IP_VENDOR_ID_H                       43
#define XSPI_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define XSPI_IP_AR_RELEASE_MINOR_VERSION_H        9
#define XSPI_IP_AR_RELEASE_REVISION_VERSION_H     0
#define XSPI_IP_SW_MAJOR_VERSION_H                0
#define XSPI_IP_SW_MINOR_VERSION_H                8
#define XSPI_IP_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Xspi_Ip_Cfg header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_H != XSPI_IP_VENDOR_ID_CFG)
    #error "Xspi_Ip.h and Xspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Cfg header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.h and Xspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Xspi_Ip_Cfg header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_H != XSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (XSPI_IP_SW_MINOR_VERSION_H != XSPI_IP_SW_MINOR_VERSION_CFG) || \
     (XSPI_IP_SW_PATCH_VERSION_H != XSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Xspi_Ip.h and Xspi_Ip_Cfg.h are different"
#endif

/* Check if current file and Xspi_Ip_Common.h header file are of the same vendor */
#if (XSPI_IP_VENDOR_ID_H != XSPI_IP_COMMON_VENDOR_ID_H)
    #error "Xspi_Ip.h and Xspi_Ip_Common.h have different vendor ids"
#endif
/* Check if current file and Xspi_Ip_Common.h header file are of the same Autosar version */
#if ((XSPI_IP_AR_RELEASE_MAJOR_VERSION_H    != XSPI_IP_COMMON_AR_RELEASE_MAJOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_MINOR_VERSION_H    != XSPI_IP_COMMON_AR_RELEASE_MINOR_VERSION_H) || \
     (XSPI_IP_AR_RELEASE_REVISION_VERSION_H != XSPI_IP_COMMON_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Xspi_Ip.h and Xspi_Ip_Common.h are different"
#endif
/* Check if current file and Xspi_Ip_Common.h header file are of the same Software version */
#if ((XSPI_IP_SW_MAJOR_VERSION_H != XSPI_IP_COMMON_SW_MAJOR_VERSION_H) || \
     (XSPI_IP_SW_MINOR_VERSION_H != XSPI_IP_COMMON_SW_MINOR_VERSION_H) || \
     (XSPI_IP_SW_PATCH_VERSION_H != XSPI_IP_COMMON_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Xspi_Ip.h and Xspi_Ip_Common.h are different"
#endif
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*! Maximum number of bytes then can be read in one operation */
#define     XSPI_IP_MAX_READ_SIZE       (FEATURE_XSPI_RX_BUF_SIZE)

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

/*!
 * @brief Launches a simple command for the serial flash.
 *
 * @param instance     External flash instance number
 * @param lut          Index of command in virtual LUT
 * @param addr         Address used in the command, or base address of the target serial flash
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_RunCommand(uint32 instance,
                                      uint16 lut,
                                      uint32 addr
                                     );

/*!
 * @brief Launches a read command for the serial flash
 *
 * This function can launch a read command in 3 modes:
 * - normal read (dataRead != NULL_PTR): Data is read from serial flash and placed in the buffer
 * - verify (dataRead == NULL_PTR, dataCmp != NULL_PTR): Data is read from serial flash and compared to the reference buffer
 * - blank check (dataRead == NULL_PTR, dataCmp == NULL_PTR): Data is read from serial flash and compared to 0xFF
 *
 * @param instance       External flash instance number
 * @param lut            Index of command in virtual LUT
 * @param addr           Start address for read operation in serial flash
 * @param dataRead       Buffer where to store read data
 * @param dataCmp        Buffer to be compared to read data
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_RunReadCommand(uint32 instance,
                                          uint16 lut,
                                          uint32 addr,
                                          uint8 * dataRead,
                                          const uint8 * dataCmp,
                                          uint32 size
                                         );

/*!
 * @brief Launches a write command for the serial flash
 *
 * @param instance       External flash instance number
 * @param lut            Index of command in virtual LUT
 * @param addr           Start address for write operation in serial flash
 * @param data           Data to be programmed in flash
 * @param size           Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_RunWriteCommand(uint32 instance,
                                           uint16 lut,
                                           uint32 addr,
                                           const uint8 * data,
                                           uint32 size
                                          );

/*!
 * @brief Get the status of the last operation
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_GetJobStatus(uint32 instance);


/*!
 * @brief Read manufacturer ID from serial flash
 *
 * @param instance     External flash instance number
 * @param data         Buffer where to store read data.
 *                     Buffer size must match ReadId initialization settings
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ReadId(uint32 instance,
                                  uint8 * data
                                 );


/*!
 * @brief Suspends a program operation
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ProgramSuspend(uint32 instance);

/*!
 * @brief Resumes a program operation
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ProgramResume(uint32 instance);

/*!
 * @brief Suspends an erase operation
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_EraseSuspend(uint32 instance);

/*!
 * @brief Resumes an erase operation
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_EraseResume(uint32 instance);

/*!
 * @brief Read data from serial flash
 *
 * @param instance     External flash instance number
 * @param address      Start address for read operation
 * @param data         Buffer where to store read data
 * @param size         Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_Read(uint32 instance,
                                uint32 address,
                                uint8 * data,
                                uint32 size
                               );

/*!
 * @brief Verifies the correctness of the programmed data
 *
 * @param instance     External flash instance number
 * @param address      Start address of area to be verified
 * @param data         Data to be verified
 * @param size         Size of area to be verified
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ProgramVerify(uint32 instance,
                                         uint32 address,
                                         const uint8 * data,
                                         uint32 size
                                        );


/*!
 * @brief Checks whether or not an area in the serial flash is erased
 *
 * @param instance     External flash instance number
 * @param address      Start address of area to be verified
 * @param size         Size of area to be verified
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_EraseVerify(uint32 instance,
                                       uint32 address,
                                       uint32 size
                                      );

/*!
 * @brief Writes data in serial flash
 *
 * @details            Writes data in serial flash memory then exits (Async mode)
 *                     The status of the flash memory must be verified by calling asynchronously the Xspi_Ip_GetMemoryStatus function
 *                     until it is not busy, meaning that the write operation is complete.
 *                     The maximum supported size is equal to the XSPI hardware TxBuffer size.
 *
 * @param instance     External flash instance number
 * @param address      Start address of area to be programmed
 * @param data         Data to be programmed in flash
 * @param size         Size of data buffer
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_Program(uint32 instance,
                                   uint32 address,
                                   const uint8 * data,
                                   uint32 size
                                  );


/*!
 * @brief Erase a sector in the serial flash.
 *
 * This function performs one erase sector (block) operation on the external flash. The erase size must match one of
 * the device's erase types.
 *
 * @param instance     External flash instance number
 * @param address      Address of sector to be erased
 * @param size         Size of the sector to be erase. The sector size must match one of the supported erase sizes of the device.
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_EraseBlock(uint32 instance,
                                      uint32 address,
                                      uint32 size
                                     );


/*!
 * @brief Initializes the serial flash memory driver
 *
 * This function initializes the external flash driver and prepares it for operation.
 *
 * @param instance     External flash instance number
 * @param pConfig      Pointer to the driver configuration structure.
 * @param pConnect     Pointer to the flash device connection structure.
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_Init(uint32 instance,
                                const Xspi_Ip_MemoryConfigType * pConfig,
                                const Xspi_Ip_MemoryConnectionType * pConnect
                               );

/*!
 * @brief De-initializes the serial flash memory driver
 *
 * This function de-initializes the XSPI driver. The driver can't be used
 * again until reinitialized. The state structure is no longer needed by the driver and
 * may be freed after calling this function.
 *
 * @param instance     External flash instance number
 * @return    Xspi_Ip_StatusType
 */
Xspi_Ip_StatusType Xspi_Ip_Deinit(uint32 instance);


/*!
 * @brief Initializes the XSPI driver
 *
 * This function initializes the XSPI driver and prepares it for operation.
 *
 * @param instance         XSPI peripheral instance number
 * @param userConfigPtr    Pointer to the XSPI configuration structure.
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerInit(uint32 instance,
                                          const Xspi_Ip_ControllerConfigType * userConfigPtr
                                         );


/*!
 * @brief Applies security settings
 *
 * Applies security settings for the controller: FRAD/MDAD/LUT lock.
 *
 * @param instance         XSPI peripheral instance number
 * @param userConfigPtr    Pointer to the XSPI configuration structure.
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerInitSecurity(uint32 instance,
                                                  const Xspi_Ip_ControllerConfigType * userConfigPtr
                                                 );


/*!
 * @brief De-initialize the XSPI driver
 *
 * This function de-initializes the XSPI driver. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param instance     XSPI peripheral instance number
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ControllerDeinit(uint32 instance);

#if (XSPI_IP_USE_SFDP_CFG == STD_ON)
/*!
 * @brief Initializes the serial flash memory configuration from SFDP table
 *
 * This function uses the information in the SFDP table to auto-fill the memory configuration structure.
 *
 * @param pConfig      Pointer to the driver configuration structure.
 * @param pConnect     Pointer to the flash device connection structure.
 * @return    Error or success status returned by API
 */
Xspi_Ip_StatusType Xspi_Ip_ReadSfdp(Xspi_Ip_MemoryConfigType * pConfig,
                                    const Xspi_Ip_MemoryConnectionType * pConnect
                                   );
#endif /* (XSPI_IP_USE_SFDP_CFG == STD_ON) */

Xspi_Ip_StatusType Xspi_Ip_ArbUnlock(uint32 instance, uint32 address);

/** * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* @brief        Process errors that need to be handled by the master ENV.
* @details      Clear them and notify the user application.
*
* @param[in]    instance of the MEM driver
*
* @pre          The driver is initialized.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void Xspi_Ip_ProcessErrors(uint32 instance);

void Xspi_Ip_InitLuts(const Xspi_Ip_StateType *state);

#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* XSPI_IP_H */
