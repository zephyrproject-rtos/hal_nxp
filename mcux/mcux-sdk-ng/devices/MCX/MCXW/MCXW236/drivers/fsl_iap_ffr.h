/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef __FSL_IAP_FFR_H_
#define __FSL_IAP_FFR_H_

#include "fsl_iap.h"

/*!
 * @addtogroup flash_pfr_driver
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*!
 * @name Flash PFR version
 * @{
 */
/*! Flash PFR (Protected Flash Region) driver version for SDK*/
#define FSL_FLASH_IFR_DRIVER_VERSION (MAKE_VERSION(1, 0, 0)) /*!< Version 1.0.0. */
/*@}*/

#define FLASH_FFR_MAX_PAGE_SIZE         (512u)
#define FLASH_FFR_OEM_KEYSTORE_MAX_SIZE (sizeof(FLASH_KEY_STORE_Type))

/*!
 * Flash key store storage.
 */
typedef struct ffr_key_store_s
{
    uint8_t reserved[FLASH_FFR_OEM_KEYSTORE_MAX_SIZE];
} ffr_key_store_t;

/*!
 * Enumeration for various ffr keys.
 */
typedef enum ffr_key_type_s
{
    kFFR_KeyTypeSbkek         = 0x105014,
    kFFR_KeyTypeUser          = 0x10504c,
    kFFR_KeyTypeUds           = 0x107d94,
    kFFR_KeyTypePrinceRegion0 = 0x107cb4,
    kFFR_KeyTypePrinceRegion1 = 0x107cec,
    kFFR_KeyTypePrinceRegion2 = 0x107d24,
    kFFR_KeyTypePrinceRegion3 = 0x107d5c,
    kFFR_KeyTypeAfeAes        = 0x107dcc
} ffr_key_type_t;

/*!
 * Enumeration for locations where @ref FFR_GetBdAddress function can retrieve BD_ADDR from.
 */
typedef enum ffr_bd_addr_location_s
{
    kFFR_BdAddrLocationCmpa = 0x1,
    kFFR_BdAddrLocationNmpa = 0x2,
    kFFR_BdAddrLocationUuid = 0x4,
} ffr_bd_addr_location_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name FFR APIs
 * @{
 */

/*!
 * Enable flash firewall.
 *
 * CFPA (ping and pong), CMPA, NMPA, key store and NXP key store flash areas region will be locked, After this function
 * is executed. Unless the board is reset again. Note that CFPA scratched can still be written after enabling the
 * firewall.
 *
 * @param config A pointer to the storage for the driver runtime state.
 *
 * @retval #kStatus_FLASH_Success An invalid argument is provided.
 */
status_t FFR_LockAll(flash_config_t *config);

/*!
 * Write CFPA scratch page
 *
 * This routine will erase CFPA scratch and program the CFPA page with passed data.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param page_data A pointer to the source buffer of data that is to be programmed
 *        into the CFPA.
 * @param valid_len The length, given in bytes, to be programmed.
 *    	  This function will always recalculate the digest automatically.
 *        When writing a new CFPA page, the value of the digest can be left zero or even excluded from the valid_len
 * 		  parameter. Valid lenghts for valid_len are: ffr page size (=512) or ffr page size - digest (=480)
 *
 * @retval #kStatus_FLASH_Success The desire page-data were programmed successfully into CFPA.
 * @retval #kStatus_FLASH_OutOfDateCfpaPage It is not newest CFPA page.
 * @retval #kStatus_FLASH_SizeError valid_len parameter is not valid
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FFR_InfieldPageWrite(flash_config_t *config, uint8_t *page_data, uint32_t valid_len);

/*!
 * Read most recent CFPA page.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param pData A pointer to the dest buffer of data that is to be read from CFPA.
 * @param offset An offset from the CFPA start address.
 * @param len The length, given in bytes, to be read.
 *
 * @retval #kStatus_FLASH_Success Get data from CFPA.
 * @retval #kStatus_FLASH_InvalidArgument An invalid argument is provided.
 * @retval #kStatus_FLASH_CommandFailure access error.
 */
status_t FFR_GetCustomerInfieldData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);

/*!
 * Write CMPA page
 *
 * This routine will erase CMPA and program the page with passed data.
 * 1.During development customer code uses this API with 'seal_part' set to FALSE.
 * 2.During manufacturing this parameter should be set to TRUE to seal the part
 * from further modifications
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param page_data A pointer to the source buffer of data that is to be programmed
 *        into the "customer factory page".
 * @param seal_part When set to true, CMPA will be sealed.
 *		Different scenarios are possible:
 *		   @li When seal_part is set to true, the ROM implementation of this function will always calculate the digest and
 *seal the CMPA. In this case the content of the SHA256_DIGEST in the page_data parameter does not matter and can be
 *left zero.
 *		   @li When seal_part is set to false and the content of the SHA256_DIGEST in the page_data parameter only contains
 *zeros, the passed CMPA will be written, but the SHA256_DIGEST will remain zero and CMPA remains unsealed. This
 *means it can be written again.
 *		   @li When seal_part is set to false BUT the content of the SHA256_DIGEST in the page_data parameter is not all
 *zeros, the ROM implementation of this function will calculate the digest and seal the CMPA.
 *
 *
 * @retval #kStatus_FLASH_Success The desire page-data were programmed successfully into CMPA.
 * @retval #kStatus_FLASH_FfrBankIsLocked page is locked.
 * @retval #kStatus_FLASH_CommandFailure access error.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FFR_CustomerFactoryPageWrite(flash_config_t *config, uint8_t *page_data, bool seal_part);

/*!
 * Read CMPA page
 *
 * Read data stored in CMPA.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param pData A pointer to the dest buffer of data that is to be read
 *            from the CMPA.
 * @param offset Address offset relative to the CMPA area.
 * @param len The length, given in bytes to be read.
 *
 * @retval #kStatus_FLASH_Success Get data from 'Customer Factory CFG Page'.
 * @retval #kStatus_FLASH_InvalidArgument Parameter is not aligned with the specified baseline.
 * @retval #kStatus_FLASH_CommandFailure access error.
 */
status_t FFR_GetCustomerData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len);

/*!
 * Read UUID.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param uuid pointer to buffer which can hold 128-bit (16 bytes) value.
 *
 * @retval #kStatus_FLASH_Success The UUID was read successfully.
 */
status_t FFR_GetUUID(flash_config_t *config, uint8_t *uuid);

/*!
 * Read Bluetooth address (BD_ADDR) from CMPA, NMPA or UUID.
 * If a valid address exists in CMPA, the address is read from CMPA (BLE_UNIQUE_ADDRESS CMPA field).
 * Else, if a valid address exists in NMPA, the address is read from NMPA (BLE_DEFAULT_ADDRESS NMPA field).
 * Else, the 6 least significant bytes from UUID are read from NMPA (UUID NMPA field).
 *
 * Bluetooth Address consists of three parts: NAP, UAP  and LAP.
 *  @li NAP: Non-significant Address Part (2 bytes). Contains first 16 bits of the OUI. The NAP value is used in
 * Frequency Hopping Synchronization frames.
 *  @li UAP: Upper Address Part (1 byte). Contains remaining 8 bits of the OUI. The UAP value is used for seeding in
 * various Bluetooth specification algorithms.
 *  @li LAP: Lower Address Part (3 bytes). This portion of Bluetooth Address is allocated by the vendor of device.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param bdAddr pointer to buffer which holds 48-bit BD_ADDR value (little-endian).
 * @param location contains bit mask of locations (@ref ffr_bd_addr_location_t) where function must search BD_ADDR.
 *                       If the function returns #kStatus_FLASH_Success, the variable will be overwritten,
 *                       with location that was used to copy the BD_ADDR from.
 *
 * @retval #kStatus_FLASH_Success The BD_ADDR was read successfully.
 */
status_t FFR_GetBdAddress(flash_config_t *config, uint8_t *bdAddr, uint32_t *location);

/*!
 * Read Bluetooth address from NMPA (BD_ADDR).
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param bdAddr pointer to buffer which holds 48-bit BD_ADDR value (little-endian).
 *
 * @retval #kStatus_FLASH_Success The BD_ADDR was read successfully.
 * @retval #kStatus_NoData In case no valid address exists in NMPA
 */
status_t FFR_GetBdAddressFromNmpa(flash_config_t *config, uint8_t *bdAddr);

/*!
 * Read Bluetooth address from CMPA (BD_ADDR).
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param bdAddr pointer to buffer which holds 48-bit BD_ADDR value (little-endian).
 *
 * @retval #kStatus_FLASH_Success The BD_ADDR was read successfully.
 * @retval #kStatus_NoData In case no valid address exists in CMPA
 */
status_t FFR_GetBdAddressFromCmpa(flash_config_t *config, uint8_t *bdAddr);

/*!
 * Write key store.
 *
 * 1.Used during manufacturing. Should write pages when CMPA is not in sealed state.
 * 2.Optional routines to set individual data members (activation code, key codes etc) to construct
 * the key store structure in RAM before committing it to IFR/FFR.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param pKeyStore A Pointer to the data allocated for key store data.
 *        that will be written to 'customer factory page'.
 *
 * @retval #kStatus_FLASH_Success The key store was programmed successfully into FFR.
 * @retval #kStatus_FLASH_SealedFfrRegion CMPA is sealed, key store cannot be written anymore.
 * @retval #kStatus_FLASH_FfrBankIsLocked page is locked.
 * @retval #kStatus_FLASH_CommandFailure access error.
 *
 * @attention No interrupts should be executed from flash while executing this function.
 */
status_t FFR_KeystoreWrite(flash_config_t *config, ffr_key_store_t *pKeyStore);

/*!
 * Read the activation code from the key store.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param pActivationCode A Pointer to buffer than can store activation code (1192 bytes).
 * @retval #kStatus_FLASH_Success The key was successfully retrieved
 * @retval kStatus_FLASH_BlankIfrPageData activation code cannot be read because page is blank.
 */
status_t FFR_KeystoreGetAC(flash_config_t *config, uint8_t *pActivationCode);

/*!
 * Reads the given key from the key store.
 *
 * @param config A pointer to the storage for the driver runtime state.
 * @param pKeyCode A Pointer to buffer than can store key code (52 bytes).
 * @param keyAddress Address of the key to retrieve
 * @retval #kStatus_FLASH_Success The key was successfully retrieved
 * @retval kStatus_FLASH_BlankIfrPageData key cannot be read because page is blank.
 */
status_t FFR_KeystoreGetKC(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyAddress);

/*@}*/

#ifdef __cplusplus
}
#endif

/*@}*/

#endif /*! __FSL_FLASH_FFR_H_ */
