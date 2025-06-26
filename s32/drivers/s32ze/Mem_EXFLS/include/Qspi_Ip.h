/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef QSPI_IP_H
#define QSPI_IP_H

/**
*   @file Qspi_Ip.h
*
*   @defgroup IPV_QSPI QSPI IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Qspi_Ip_Types.h"
#include "Qspi_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define QSPI_IP_VENDOR_ID_H                       43
#define QSPI_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define QSPI_IP_AR_RELEASE_MINOR_VERSION_H        7
#define QSPI_IP_AR_RELEASE_REVISION_VERSION_H     0
#define QSPI_IP_SW_MAJOR_VERSION_H                2
#define QSPI_IP_SW_MINOR_VERSION_H                0
#define QSPI_IP_SW_PATCH_VERSION_H                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Qspi_Ip_Types header file are of the same vendor */
#if (QSPI_IP_TYPES_VENDOR_ID_CFG != QSPI_IP_VENDOR_ID_H)
    #error "Qspi_Ip.h and Qspi_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Autosar version */
#if ((QSPI_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG    != QSPI_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG != QSPI_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.h and Qspi_Ip_Types.h are different"
#endif
/* Check if current file and Qspi_Ip_Types header file are of the same Software version */
#if ((QSPI_IP_TYPES_SW_MAJOR_VERSION_CFG != QSPI_IP_SW_MAJOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_MINOR_VERSION_CFG != QSPI_IP_SW_MINOR_VERSION_H) || \
     (QSPI_IP_TYPES_SW_PATCH_VERSION_CFG != QSPI_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Qspi_Ip.h and Qspi_Ip_Types.h are different"
#endif

/* Check if current file and Qspi_Ip_Cfg header file are of the same vendor */
#if (QSPI_IP_VENDOR_ID_H != QSPI_IP_VENDOR_ID_CFG)
    #error "Qspi_Ip.h and Qspi_Ip_Cfg.h have different vendor ids"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Autosar version */
#if ((QSPI_IP_AR_RELEASE_MAJOR_VERSION_H    != QSPI_IP_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (QSPI_IP_AR_RELEASE_MINOR_VERSION_H    != QSPI_IP_AR_RELEASE_MINOR_VERSION_CFG) || \
     (QSPI_IP_AR_RELEASE_REVISION_VERSION_H != QSPI_IP_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Qspi_Ip.h and Qspi_Ip_Cfg.h are different"
#endif
/* Check if current file and Qspi_Ip_Cfg header file are of the same Software version */
#if ((QSPI_IP_SW_MAJOR_VERSION_H != QSPI_IP_SW_MAJOR_VERSION_CFG) || \
     (QSPI_IP_SW_MINOR_VERSION_H != QSPI_IP_SW_MINOR_VERSION_CFG) || \
     (QSPI_IP_SW_PATCH_VERSION_H != QSPI_IP_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Qspi_Ip.h and Qspi_Ip_Cfg.h are different"
#endif

/*******************************************************************************
 * Definitions.
 ******************************************************************************/

/*! Maximum number of bytes then can be read in one operation */
#define     QSPI_IP_MAX_READ_SIZE       (FEATURE_QSPI_RX_BUF_SIZE)
/*! Maximum number of bytes then can be written in one operation */
#define     QSPI_IP_MAX_WRITE_SIZE      (FEATURE_QSPI_TX_BUF_SIZE)

/*******************************************************************************
 * API
 ******************************************************************************/
#define MEM_43_EXFLS_START_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"

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
Qspi_Ip_StatusType Qspi_Ip_Init(uint32 instance,
                                const Qspi_Ip_MemoryConfigType * pConfig,
                                const Qspi_Ip_MemoryConnectionType * pConnect
                               );


/*!
 * @brief De-initializes the serial flash memory driver
 *
 * This function de-initializes the qspi driver. The driver can't be used
 * again until reinitialized. The state structure is no longer needed by the driver and
 * may be freed after calling this function.
 *
 * @param instance     External flash instance number
 * @return    void
 */
Qspi_Ip_StatusType Qspi_Ip_Deinit(uint32 instance);


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
Qspi_Ip_StatusType Qspi_Ip_EraseBlock(uint32 instance,
                                      uint32 address,
                                      uint32 size
                                     );

/*!
 * @brief Erase the entire serial flash
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_EraseChip(uint32 instance);

/*!
 * @brief Check the status of the flash device
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_GetMemoryStatus(uint32 instance);


/*!
 * @brief Sets the protection bits to the requested value.
 *
 * @param instance     External flash instance number
 * @param value        New value for the protection bits
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_SetProtection(uint32 instance,
                                         uint8 value
                                        );


/*!
 * @brief Returns the current value of the protection bits
 *
 * @param instance     External flash instance number
 * @param value        Current value of the protection bits
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_GetProtection(uint32 instance,
                                         uint8 *value
                                        );


/*!
 * @brief Resets the flash device
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Reset(uint32 instance);


/*!
 * @brief Enters 0-X-X (no command) mode. This mode assumes only reads are performed.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Enter0XX(uint32 instance);


/*!
 * @brief Exits 0-X-X (no command) mode. This allows operations other than reads to be performed.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Exit0XX(uint32 instance);


/*!
 * @brief Suspends a program operation.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ProgramSuspend(uint32 instance);


/*!
 * @brief Resumes a program operation.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ProgramResume(uint32 instance);


/*!
 * @brief Suspends an erase operation.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_EraseSuspend(uint32 instance);


/*!
 * @brief Resumes an erase operation.
 *
 * @param instance     External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_EraseResume(uint32 instance);


/*!
 * @brief Read data from serial flash
 *
 * @param instance     External flash instance number
 * @param address      Start address for read operation
 * @param data         Buffer where to store read data
 * @param size         Size of data buffer
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Read(uint32 instance,
                                uint32 address,
                                uint8 * data,
                                uint32 size
                               );


/*!
 * @brief Read manufacturer ID/device ID from serial flash
 *
 * @param instance     External flash instance number
 * @param data         Buffer where to store read data. Buffer size must match ReadId initialization settings.
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ReadId(uint32 instance,
                                  uint8 * data
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
Qspi_Ip_StatusType Qspi_Ip_ProgramVerify(uint32 instance,
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
Qspi_Ip_StatusType Qspi_Ip_EraseVerify(uint32 instance,
                                       uint32 address,
                                       uint32 size
                                      );

/*!
 * @brief Writes data in serial flash
 *
 * @details            Writes data in serial flash memory then exits (Async mode)
 *                     The status of the flash memory must be verified by calling asynchronously the Qspi_Ip_GetMemoryStatus function
 *                     until it is not busy, meaning that the write operation is complete.
 *                     The maximum supported size is equal to the Qspi hardware TxBuffer size.
 *
 * @param instance     External flash instance number
 * @param address      Start address of area to be programmed
 * @param data         Data to be programmed in flash
 * @param size         Size of data buffer
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Program(uint32 instance,
                                   uint32 address,
                                   const uint8 * data,
                                   uint32 size
                                  );


/*!
 * @brief Launches a simple command for the serial flash.
 *
 * @param instance     External flash instance number
 * @param lut          Index of command in virtual LUT
 * @param addr         Address used in the command, or base address of the target serial flash
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_RunCommand(uint32 instance,
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
Qspi_Ip_StatusType Qspi_Ip_RunReadCommand(uint32 instance,
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
Qspi_Ip_StatusType Qspi_Ip_RunWriteCommand(uint32 instance,
                                           uint16 lut,
                                           uint32 addr,
                                           const uint8 * data,
                                           uint32 size
                                          );

/*!
 * @brief Sets up AHB reads to the serial flash
 *
 * @param instance   External flash instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_AhbReadEnable(uint32 instance);

/*!
 * @brief Check the status of the QSPI controller
 *
 * @param instance     QSPI peripheral instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ControllerGetStatus(uint32 instance);


/*!
 * @brief Initializes the qspi driver
 *
 * This function initializes the qspi driver and prepares it for operation.
 *
 * @param instance         QSPI peripheral instance number
 * @param userConfigPtr    Pointer to the qspi configuration structure.
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ControllerInit(uint32 instance,
                                          const Qspi_Ip_ControllerConfigType * userConfigPtr
                                         );

/*!
 * @brief De-initialize the qspi driver
 *
 * This function de-initializes the qspi driver. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param instance     QSPI peripheral instance number
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ControllerDeinit(uint32 instance);

/*!
 * @brief Aborts any on-going transactions
 *
 * Force the Qspi controller to cancel the on-going IP transaction by performing the software reset sequence.
 *
 * @param instance     QSPI peripheral instance number
 * @return             Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_Abort(uint32 instance);

/*!
 * @brief Initializes the serial flash memory configuration from SFDP table
 *
 * This function uses the information in the SFDP table to auto-fill the memory configuration structure.
 *
 * @param pConfig      Pointer to the driver configuration structure.
 * @param pConnect     Pointer to the flash device connection structure.
 * @return    Error or success status returned by API
 */
Qspi_Ip_StatusType Qspi_Ip_ReadSfdp(Qspi_Ip_MemoryConfigType * pConfig,
                                    const Qspi_Ip_MemoryConnectionType * pConnect
                                   );


#define MEM_43_EXFLS_STOP_SEC_CODE
#include "Mem_43_EXFLS_MemMap.h"


#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* QSPI_IP_H */

