/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_device_registers.h"
#include "fsl_rom_api.h"
#include "fsl_iap.h"
#include "fsl_iap_ffr.h"
#include "fsl_iap_kbp.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.rom_api"
#endif

#define GET_PHYSICAL_ADDR(addr) ((addr) & ~(1u << 28))

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*! Get pointer to flash driver API table in ROM. */
#define FLASH_API_TREE BOOTLOADER_API_TREE_POINTER->flashDriver

/*******************************************************************************
 * Code
 ******************************************************************************/

status_t FLASH_Init(flash_config_t *config)
{
    status_t status;

    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }
    config->sysFreqInMHz = SystemCoreClock / 1000000;
    status               = FLASH_API_TREE->flash_init(config);

    if (status == kStatus_FLASH_Success)
    {
        status = FLASH_API_TREE->ffr_init(config);
    }
    return status;
}

status_t FLASH_Erase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes, uint32_t key)
{
    return FLASH_API_TREE->flash_erase(config, start, lengthInBytes, key);
}

status_t FLASH_Program(flash_config_t *config, uint32_t start, uint8_t *src, uint32_t lengthInBytes)
{
    return FLASH_API_TREE->flash_program(config, start, src, lengthInBytes);
}

status_t FLASH_VerifyErase(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    return FLASH_API_TREE->flash_verify_erase(config, start, lengthInBytes);
}

status_t FLASH_VerifyProgram(flash_config_t *config,
                             uint32_t start,
                             uint32_t lengthInBytes,
                             const uint8_t *expectedData,
                             uint32_t *failedAddress,
                             uint32_t *failedData)
{
    return FLASH_API_TREE->flash_verify_program(config, start, lengthInBytes, expectedData, failedAddress, failedData);
}

status_t FLASH_GetProperty(flash_config_t *config, flash_property_tag_t whichProperty, uint32_t *value)
{
    return FLASH_API_TREE->flash_get_property(config, whichProperty, value);
}

status_t FFR_LockAll(flash_config_t *config)
{
    return FLASH_API_TREE->ffr_lock_all(config);
}

status_t FFR_CustomerFactoryPageWrite(flash_config_t *config, uint8_t *page_data, bool seal_part)
{
    return FLASH_API_TREE->ffr_cust_factory_page_write(config, page_data, seal_part);
}

status_t FFR_GetUUID(flash_config_t *config, uint8_t *uuid)
{
    return FLASH_API_TREE->ffr_get_uuid(config, uuid);
}

status_t FFR_GetBdAddress(flash_config_t *config, uint8_t *bdAddr, uint32_t *location)
{
    status_t status = kStatus_NoData;

    /* Try to read bd_addr from CMPA*/
    if (*location & kFFR_BdAddrLocationCmpa)
    {
        status = FFR_GetBdAddressFromCmpa(config, bdAddr);
        if (status == kStatus_Success)
        {
            *location = kFFR_BdAddrLocationCmpa;
            return kStatus_Success;
        }
    }

    /* No valid address in CMPA, try to read it from NMPA */
    if (*location & kFFR_BdAddrLocationNmpa)
    {
        status = FFR_GetBdAddressFromNmpa(config, bdAddr);
        if (status == kStatus_Success)
        {
            *location = kFFR_BdAddrLocationNmpa;
            return kStatus_Success;
        }
    }

    /* No valid address in NMPA, read it from UUID NMPA */
    if (*location & kFFR_BdAddrLocationUuid)
    {
        uint8_t uid[16];
        status = FFR_GetUUID(config, uid);
        memcpy(bdAddr, uid, 6);
        *location = kFFR_BdAddrLocationUuid;
        return kStatus_Success;
    }

    return status;
}

status_t FFR_GetBdAddressFromNmpa(flash_config_t *config, uint8_t *bdAddr)
{
    status_t status;
    FLASH_NMPA_Type *nmpa     = (FLASH_NMPA_Type *)FLASH_NMPA_BASE;
    uint8_t addr0_valid_value = (nmpa->BLE_DEFAULT_ADDRESS.BLE_DEFAULT_ADDRESS0 &
                                 FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_MASK) >>
                                FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_SHIFT;
    uint8_t addr1_valid_value = (nmpa->BLE_DEFAULT_ADDRESS.BLE_DEFAULT_ADDRESS1 &
                                 FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_MASK) >>
                                FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_SHIFT;

    /* NMPA only contains valid BD address when the magic values tested below are set. */
    if (addr0_valid_value == 0xA5 && addr1_valid_value == 0xC3)
    {
        /* Copy 24 LAP bits */
        status = FLASH_Read(config, (uint32_t)&nmpa->BLE_DEFAULT_ADDRESS.BLE_DEFAULT_ADDRESS0, bdAddr, 3);

        /* Copy 24 OUI (NAP + UAP) bits */
        if (status == kStatus_Success)
        {
            status = FLASH_Read(config, (uint32_t)&nmpa->BLE_DEFAULT_ADDRESS.BLE_DEFAULT_ADDRESS1, &bdAddr[3], 3);
        }
        return status;
    }

    return kStatus_NoData;
}

status_t FFR_GetBdAddressFromCmpa(flash_config_t *config, uint8_t *bdAddr)
{
    status_t status;
    FLASH_CMPA_Type *cmpa = (FLASH_CMPA_Type *)FLASH_CMPA_BASE;
    uint16_t addr_valid_value =
        (cmpa->BLE_UNIQUE_ADDRESS.BLE_UNIQUE_ADDRESS1 & FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_MASK) >>
        FLASH_CMPA_BLE_UNIQUE_ADDRESS1_BLE_UNIQUE_ADDRESS_VALID_SHIFT;

    /* CMPA only contains valid BD address when the magic value tested below is set. */
    if (addr_valid_value == 0xC3A5)
    {
        /* Get 32 LSB bits */
        status = FLASH_Read(config, (uint32_t)&cmpa->BLE_UNIQUE_ADDRESS.BLE_UNIQUE_ADDRESS0, bdAddr, 4);

        /* Get 16 MSB bits */
        if (status == kStatus_Success)
        {
            status = FLASH_Read(config, (uint32_t)&cmpa->BLE_UNIQUE_ADDRESS.BLE_UNIQUE_ADDRESS1, &bdAddr[4], 2);
        }
        return status;
    }

    return kStatus_NoData;
}

status_t FFR_GetCustomerData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len)
{
    return FLASH_API_TREE->ffr_get_customer_data(config, pData, offset, len);
}

status_t FFR_KeystoreWrite(flash_config_t *config, ffr_key_store_t *pKeyStore)
{
    return FLASH_API_TREE->ffr_keystore_write(config, pKeyStore);
}

status_t FFR_KeystoreGetAC(flash_config_t *config, uint8_t *pActivationCode)
{
    return FLASH_API_TREE->ffr_keystore_get_ac(config, pActivationCode);
}

status_t FFR_KeystoreGetKC(flash_config_t *config, uint8_t *pKeyCode, ffr_key_type_t keyIndex)
{
    return FLASH_API_TREE->ffr_keystore_get_kc(config, pKeyCode, keyIndex);
}

status_t FFR_InfieldPageWrite(flash_config_t *config, uint8_t *page_data, uint32_t valid_len)
{
    return FLASH_API_TREE->ffr_infield_page_write(config, page_data, valid_len);
}

status_t FFR_GetCustomerInfieldData(flash_config_t *config, uint8_t *pData, uint32_t offset, uint32_t len)
{
    return FLASH_API_TREE->ffr_get_customer_infield_data(config, pData, offset, len);
}

static status_t flash_check_region(flash_config_t *config,
                                   uint32_t start,
                                   uint32_t lengthInBytes,
                                   uint32_t alignmentBaseline)
{
    if (config == NULL)
    {
        return kStatus_FLASH_InvalidArgument;
    }

    start = GET_PHYSICAL_ADDR(start);

    /* Validates the alignment of the given address and length */
    if ((alignmentBaseline > 0U) && (((start & (alignmentBaseline - 1U)) != 0u) || ((lengthInBytes & (alignmentBaseline - 1U)) != 0u)))
    {
        return kStatus_FLASH_AlignmentError;
    }

    /* Validates the range of the given address for reading or writing. Note that writing will
       still fail if a sector is protected by the firewall or if it is in IFR1. */
    if (((start >= config->flashDesc.blockBase) &&
         ((start <= UINT32_MAX - lengthInBytes) &&
          ((start + lengthInBytes) <= (config->flashDesc.blockBase + config->flashDesc.totalSize))) &&
         (lengthInBytes <=
          config->flashDesc.totalSize)) // Protect against integer wrap-around caused by huge lengthInBytes
        || ((start >= config->ffrConfig.ffrBlockBase) &&
            ((start <= UINT32_MAX - lengthInBytes) &&
             ((start + lengthInBytes) <= (config->ffrConfig.ffrBlockBase + config->ffrConfig.ffrTotalSize))) &&
            (lengthInBytes <=
             config->ffrConfig.ffrTotalSize)) // Protect against integer wrap-around caused by huge lengthInBytes
    )
    {
        return (status_t)kStatus_FLASH_Success;
    }

    return kStatus_FLASH_AddressError;
}

status_t FLASH_Read(flash_config_t *config, uint32_t start, uint8_t *dest, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;

    /* Check the supplied address and length. */
    status = flash_check_region(config, start, lengthInBytes, 1);
    if (kStatus_FLASH_Success != status)
    {
        return status;
    }

    memcpy(dest, (uint8_t *)start, lengthInBytes);

    return status;
}

status_t kb_init(kb_session_ref_t **session, const kb_options_t *options)
{
    return BOOTLOADER_API_TREE_POINTER->kbApi->kb_init(session, options);
}

status_t kb_deinit(kb_session_ref_t *session)
{
    return BOOTLOADER_API_TREE_POINTER->kbApi->kb_deinit(session);
}

status_t kb_execute(kb_session_ref_t *session, const uint8_t *data, uint32_t dataLength)
{
    return BOOTLOADER_API_TREE_POINTER->kbApi->kb_execute(session, data, dataLength);
}

status_t kb_authenticate(const uint8_t *imageStartAddr, secure_bool_t *isSignVerified)
{
    return BOOTLOADER_API_TREE_POINTER->kbAuthenticate->kb_authenticate(imageStartAddr, isSignVerified);
}

void kb_HASHCRYPT_IRQHandler(void)
{
    BOOTLOADER_API_TREE_POINTER->kbAuthenticate->hashcrypt_irq_handler();
}

void RunBootloader(boot_argument_t *arg)
{
    BOOTLOADER_API_TREE_POINTER->runBootloader((void *)arg);
}

void FLASH_CacheClear(void)
{
    SYSCTL->AUX_FLASH_CTRL |= SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_MASK;
    __ISB(); /*The ISB instruction flushes the processor pipeline fetch buffers, so that subsequent instructions are
                fetched from cache or memory.*/
    __DSB(); /*The DSB instruction ensures the completion of memory accesses.*/
    SYSCTL->AUX_FLASH_CTRL &= ~(SYSCTL_AUX_FLASH_CTRL_CLR_FLASH_CACHE_MASK);
}

void FLASH_CacheSpeculationControl(bool enable)
{
    if (enable == false)
    {
        SYSCTL->AUX_FLASH_CTRL |= SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_MASK | SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_MASK;
    }
    else
    {
        SYSCTL->AUX_FLASH_CTRL &=
            ~(SYSCTL_AUX_FLASH_CTRL_DIS_FLASH_SPEC_MASK | SYSCTL_AUX_FLASH_CTRL_DIS_DATA_SPEC_MASK);
    }
    __ISB();
    __DSB();
}

status_t FLASH_CheckECC(flash_config_t *config, uint32_t start, uint32_t lengthInBytes)
{
    status_t status = kStatus_FLASH_Success;
    volatile uint32_t dummyWord;

    /* Check the supplied address and length. */
    status = flash_check_region(config, start, lengthInBytes, 1);
    if (kStatus_FLASH_Success != status)
    {
        return status;
    }

    if (start > UINT32_MAX - lengthInBytes)
    {
        return kStatus_FLASH_AddressError;
    }

    /* Disable bus error on unrecoverable ECC error for data fetch. */
    SYSCTL->AUX_FLASH_CTRL |= SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_MASK;

    /* Clear the DFDIF error bit. */
    FMU0->FSTAT = FMU_FSTAT_DFDIF_MASK;

    /* Access all addresses in the required flash area. */
    start &= ~(0x3UL);

    for (; lengthInBytes > 4;)
    {
        dummyWord = *((volatile uint32_t *)start);
        (void)dummyWord; /* Avoid compiler warning */
        start += 4;
        lengthInBytes -= 4;
    }

    if (lengthInBytes > 0)
    {
        dummyWord = *((volatile uint32_t *)start);
        (void)dummyWord; /* Avoid compiler warning */
    }

    /* Check the DFDIF error bit. */
    if (FMU0->FSTAT & FMU_FSTAT_DFDIF_MASK)
    {
        /* Clear the DFDIF error bit. */
        FMU0->FSTAT = FMU_FSTAT_DFDIF_MASK;

        status = kStatus_FLASH_AccessError;
    }

    /* Re-enable bus error on unrecoverable ECC error for data fetch. */
    SYSCTL->AUX_FLASH_CTRL &= ~(SYSCTL_AUX_FLASH_CTRL_DIS_MBECC_BERR_DATA_MASK);

    return status;
}
