/*
 * Copyright 2022-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __FWK_PLATFORM_OTA_H__
#define __FWK_PLATFORM_OTA_H__

#include "fsl_common.h"

typedef struct
{
    uint32_t image_addr;           /*!< Image physical address */
    uint32_t image_sz;             /*!< Image size in bytes */
    bool     sb_arch_in_ext_flash; /*!< Image stored in external flash */
    uint32_t spi_baudrate; /*!< SPI baudrate - only necessary if loader has to access image in external SPI flash */
    uint8_t *pBitMap;      /*!< Downloaded image bitmap in flash potentiall NULL if no bit map used */
} OtaLoaderInfo_t;

/*! *********************************************************************************
 * \brief  Boot with the Update data on commit
 *
 * \param[in] ota_loader_info pointer on   start of the archive start address
 *
 * \return    < 0 if error, 0 otherwise
 ********************************************************************************** */
int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info);

/*! *********************************************************************************
 * \brief  Set necessary information to indicate a new image is ready after an OTA
 *
 * \param[in] ota_loader_info pointer on   start of the archive start address
 *
 * \return    < 0 if error, 0 otherwise
 ********************************************************************************** */
int PLATFORM_OtaUpdateBootFlags(const OtaLoaderInfo_t *ota_loader_info);

/*! *********************************************************************************
* \brief  Post FW update clear boot flags
*
* \return    -1: Flash erase procedure failed
*             0 : Erase successful and FW update succeeded
*             1 : no erase was required
*             2: erase succeeded but FW update has failed
              3: Flash was erased but update status was reporting an unexpected value
********************************************************************************** */
int PLATFORM_OtaClearBootFlags(void);

/*! *********************************************************************************
 * \brief  Returns Image offset : leave space for BooData section when needed.
 *
 * \param[in] internal_storage true if OTA in internal flash, false otherwise not used
 * \param[in] partition_offset offset to be added to base address to place OTA
 *              partition, usually 0.
 * \return    offset where OTA partition should start
 ********************************************************************************** */
uint32_t PLATFORM_OtaGetImageOffset(bool internal_storage, uint32_t partition_offset);

/*! *********************************************************************************
* \brief  Returns maximum possible size of the OTAed image depends on whether the OTA
*         storage is internal flash or external
*
* \param[in] internal_storage true if OTA in internal flash, false otherwise not used

* \return    Internal flash capacity minus the NVM reserved size if external OTA, half
*            of that if internal flash OTA
*********************************************************************************** */
uint32_t PLATFORM_OtaGetMaxImageSize(bool internal_storage);

/*! *********************************************************************************
* \brief Set pin muxing and clock to make SPI Flash module ready.

* \return    None
*********************************************************************************** */
void PLATFORM_InitSPIFlash(void);

/*!
 * @}  end of FWK_Platform_OTA
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* __FWK_PLATFORM_OTA_H__ */