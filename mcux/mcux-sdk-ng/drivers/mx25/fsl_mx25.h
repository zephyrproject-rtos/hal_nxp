/*
 * Copyright 2021 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_MX25_H_
#define FSL_MX25_H_

#include "fsl_common.h"
#include "fsl_spifi.h"
#include "fsl_spifi_dma.h"

/*!
 * @addtogroup mx25_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! MX25 flash driver version. */
#define FSL_MX25_DRIVER_VERSION (MAKE_VERSION(0, 1, 0))
/*! @} */

/*! Defines the page size of the Macronix flash. */
#define MX25_PAGE_SIZE (256)
/*! Defines the sector size. */
#define MX25_SECTOR_SIZE (4096)

/*! List of commands that can be sent to mx25 flash. */
typedef enum
{
    kMX25_CMD_READ_SR,            /*!< Read Status register. */
    kMX25_CMD_READ_CR,            /*!< Read Configuration register. */
    kMX25_CMD_READ_SCUR,          /*!< Read Security register. */
    kMX25_CMD_WRITE_SR,           /*!< Write Status register. */
    kMX25_CMD_WRITE_SC_REGISTERS, /*!< Write Status and Configuration registers. */
    kMX25_CMD_WRITE_SCUR,         /*!< Write Security register. */
    kMX25_CMD_WRITE_ENABLE,       /*!< Set Write Enable Bit. */
    kMX25_CMD_WRITE_DISABLE,      /*!< Unset Write Enable Bit (Write Disable). */
    kMX25_CMD_ENSO,               /*!< Enter Secure OTP. */
    kMX25_CMD_EXSO,               /*!< Exit Secure OTP. */
    kMX25_CMD_SPG,                /*!< Suspend page program. */
    kMX25_CMD_SER,                /*!< Suspend erase. */
    kMX25_CMD_RPG,                /*!< Resume page program. */
    kMX25_CMD_RER,                /*!< Resume erase. */
    kMX25_CMD_RSTEN,              /*!< Reset Enbale. */
    kMX25_CMD_RST,                /*!< Reset command. */
    kMX25_CMD_READ,               /*!< Read in serial mode over 1 line. */
    kMX25_CMD_FAST_READ,          /*!< Fast read in serial mode over 1 line. */
    kMX25_CMD_DUAL_READ,          /*!< Read in serial over two lines. */
    kMX25_CMD_TWO_READ,           /*!< Read in serial over two lines and send address over two lines. */
    kMX25_CMD_QUAD_READ,          /*!< Read in Quad mode over 4 lines. */
    kMX25_CMD_FOUR_READ,          /*!< Read in Quad mode over 4 lines ad send address over 4 lines. */
    kMX25_CMD_BURST_READ,         /*!< Burst Read Enable. */
    kMX25_CMD_PROGRAM_PAGE,       /*!< Write over 1 line. */
    kMX25_CMD_FOUR_PROGRAM_PAGE,  /*!< Write to flash in Quad mode over 4 lines. */
    kMX25_CMD_SECTOR_ERASE,       /*!< Erase sector of 4KBytes. */
    kMX25_CMD_BLOCK_ERASE32K,     /*!< Erase block of 32KBytes. */
    kMX25_CMD_BLOCK_ERASE64K,     /*!< Erase block of 64KBytes. */
    kMX25_CMD_CHIP_ERASE,         /*!< Erase entire flash. */
    kMX25_CMD_READ_ID,            /*!< Read device Identification - 3 Bytes*/
    kMX25_CMD_READ_ES,            /*!< Read device Electronic Signature - 1 Byte*/
    kMX25_CMD_READ_EMS,           /*!< Read device Electronic Manufacturer ID and Device ID - 2 Bytes*/
    kMX25_CMD_DEEP_PD,            /*!< Set the device in Deep Power Down Mode */
    kMX25_CMD_NUM,
} mx25_cmd_t;

/*! MX25 configuration.*/
typedef struct mx25_config_s
{
    SPIFI_Type *base;             /**< SPIFI Base Register */
    spifi_config_t config;        /**< SPIFI config, information */
    uint32_t spifiStatIRQMask;    /**< SPIFI Interrupt Request value */
    uint32_t extMemAddr;          /**< SPIFI Start Address */
    spifi_dual_mode_t dualMode;   /**< Spifi Communication Mode */
    uint8_t mx25PerfEnhanceValue; /**< Enhance Performance Mode value of MX25 flash.*/
    IRQn_Type irqSource;          /**< Interrupt vector value*/
} mx25_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @name MX25 Main APIs
 * @{
 */

/*!
 * Get the default configuration for the MX25 driver.
 *
 * The purpose of this API is to get the configuration structure initialized for use in MX25_Init().
 * User may use this default configuration in MX25_Init(), or modify some fields of the structure
 * before calling MX25_Init().
 *
 * @param[in] config pointer to mx25config structure
 *
 */
void MX25_GetDefaultConfig(mx25_config_t *config);

/*!
 *
 * After calling this API, the mx25 is ready to be used. The default mode has Quad Mode enabled.
 *
 * The configuration structure can be filled by user from scratch, or be set with default
 * values by MX25_GetDefaultConfig().
 *
 * @param[in] config pointer to mx25config structure
 *
 */
void MX25_Init(mx25_config_t *config);

/*!
 * De-initializes the access to the MX25.
 * The MX25 can't work unless calling the MX25_Init (again) to initialize module.
 *
 * @param[in] config pointer to mx25config structure
 */
void MX25_Deinit(mx25_config_t *config);

/*!
 * Enable function mode of the mx25 driver. The input mode has to be either dual or quad.
 * An error is thrown if input value is neither dual or quad mode. The default value is quad mode.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] mode Functional mode of the mx25.
 *
 *
 * @retval kStatus_Success One of the two mode was enabled properly.
 * @retval kStatus_Fail The entered value do not correspond to a valid mode.
 */
status_t MX25_EnableMode(mx25_config_t *config, const spifi_dual_mode_t mode);

/*!
 * Write a buffer to the mx25.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] address The address to start writing in the mx25.
 * @param[in] *buf The pointer of the buffer to be written in the mx25.
 * @param[in] dataLen Length of data to be written. This value needs to be a multiplier of MX25_PAGE_SIZE (256 bytes).
 * @param[in] pageProgCmd The page program mode. Two modes are accepted to program pages to be written
 * 												in the mx25: kMX25_CMD_FOUR_PROGRAM_PAGE or kMX25_CMD_PROGRAM_PAGE.
 *
 * @retval kStatus_Success The specified buffer was written properly.
 * @retval kStatus_Fail Either dataLen is not a multiplier of MX25_PAGE_SIZE or page program mode is wrong.
 */
status_t MX25_WriteBuffer(
    mx25_config_t *config, const uint32_t address, const unsigned char *buf, uint32_t dataLen, mx25_cmd_t pageProgCmd);

/*!
 * This function is used to erase a 4 KB sector, a 32 KB block, a 64 KB block of the flash or all of it.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] address The address to start erasing. Remark: if specified in the middle of a sector or a block, the
 * entire sector/block will be erased starting at (address)mod(sizeof(sector/block)).
 * @param[in] eraseCmd One of the four erase mode.
 *
 */
void MX25_Erase(mx25_config_t *config, uint32_t address, mx25_cmd_t eraseCmd);

/*!
 * Read back from the mx25 flash and store the values in a buffer. Possible read modes are:
 *
 * kMX25_CMD_READ
 * kMX25_CMD_FAST_READ
 * kMX25_CMD_DUAL_READ
 * kMX25_CMD_TWO_READ
 * kMX25_CMD_QUAD_READ
 * kMX25_CMD_FOUR_READ
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] address Address from which to start reading back from mx25.
 * @param[out] *buf The pointer of the buffer that will contain read content.
 * @param[in] dataLen Number of bytes to be read from the mx25 flash. Can be any value between 1 and mx25 flash size.
 * @param[in] readModeCmd Read mode to be used - cfr. mx25_cmd_t list for possible values.
 *
 */
void MX25_ReadBuffer(
    mx25_config_t *config, uint32_t address, unsigned char *buf, uint32_t dataLen, mx25_cmd_t readModeCmd);

/*!
 * Read back from the mx25 through the basic commands without an input buffer or an address.
 * An example of its usage is to read a large amount of data without the need to create a large buffer variable.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] readModeCmd Read mode to be used - cfr. to the list in MX_ReadBuffer doc.
 *
 */
void MX25_Read(mx25_config_t *config, mx25_cmd_t readModeCmd);

/*!
 * Read diverse information from the mx25. Possible commands are:
 *
 * kMX25_CMD_READ_ID
 * kMX25_CMD_READ_ES
 * kMX25_CMD_READ_EMS
 * kMX25_CMD_READ_SR
 * kMX25_CMD_READ_CR
 * kMX25_CMD_READ_SCUR
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] readInfoCmd The device info. required, - cfr. to the above list.
 * @retval 		A variable containing the information required in readInfoCmd
 *
 */
uint32_t MX25_ReadDeviceInfo(mx25_config_t *config, mx25_cmd_t readInfoCmd);

/*!
 * Set the configuration register.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] crVal Configuration register value to be set in the mx25.
 *
 */
void MX25_SetConfigRegister(mx25_config_t *config, uint8_t crVal);

/*!
 * Set the configuration register.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] srVal Configuration register value to be set in the mx25.
 *
 */
void MX25_SetStatusRegister(mx25_config_t *config, uint8_t srVal);

/*!
 * Set a specific protection mode to protect desired part of the flash from program or erase functions
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] protectionModeMask Mask corresponding to the protection mode bits to be set.
 *
 */
void MX25_SetProtectionMode(mx25_config_t *config, uint8_t protectionModeMask);

/*!
 * Set specific parameters of the mx25. Possible commands are:
 *
 * kMX25_CMD_WRITE_ENABLE
 * kMX25_CMD_WRITE_DISABLE
 * kMX25_CMD_ENSO
 * kMX25_CMD_EXSO
 * kMX25_CMD_SPG
 * kMX25_CMD_SER
 * kMX25_CMD_RPG
 * kMX25_CMD_RER
 * kMX25_CMD_RSTEN
 * kMX25_CMD_RST
 * kMX25_CMD_DEEP_PD
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] opParamCmd Single Opcode command - cfr. to the above list.
 *
 */
void MX25_SetOperationalParameters(mx25_config_t *config, mx25_cmd_t opParamCmd);

/*!
 * Initializes the MX25-SPIFI handle for receive which is used in transactional functions and set the callback.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] handle Pointer to spifi_dma_handle_t structure
 * @param[in] dmaHandle User requested DMA handle for DMA transfer
 *
 */
void MX25_TransferRxCreateHandleDMA(mx25_config_t *config, spifi_dma_handle_t *handle, dma_handle_t *dmaHandle);

/*!
 * Write a buffer to the mx25 using DMA Mode.
 *
 * @param[in] config pointer to mx25config structure
 * @param[in] address The address to start writing in the mx25.
 * @param[in] *buf The pointer of the buffer to be written in the mx25.
 * @param[in] pageProgCmd The page program mode. Two modes are accepted to program pages to be written
 * 												in the mx25: kMX25_CMD_FOUR_PROGRAM_PAGE or kMX25_CMD_PROGRAM_PAGE.
 * @param[in] handle * param handle Pointer to spifi_dma_handle_t structure
 *
 */
void MX25_WritePageDma(mx25_config_t *config,
                       const uint32_t address,
                       unsigned char *buf,
                       mx25_cmd_t pageProgCmd,
                       spifi_dma_handle_t handle);

/*! @} */

/*! @} */

#endif /* FSL_MX25_H_ */
