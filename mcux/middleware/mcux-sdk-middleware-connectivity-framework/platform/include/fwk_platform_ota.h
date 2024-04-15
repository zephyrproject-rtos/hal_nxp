/* -------------------------------------------------------------------------- */
/*                           Copyright 2020-2023 NXP                          */
/*                            All rights reserved.                            */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

#ifndef __FWK_PLATFORM_OTA_H__
#define __FWK_PLATFORM_OTA_H__

/*!
 * @addtogroup FWK_Platform_module
 * @{
 */
/*!
 * @addtogroup FWK_Platform_OTA
 * The FWK_Platform_OTA module
 *
 * FWK_Platform_OTA module supplies to over-the-air (OTA) applications.
 * @{
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include "fsl_common.h"

/* -------------------------------------------------------------------------- */
/*                                Public macros                               */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                Public types                                */
/* -------------------------------------------------------------------------- */

typedef enum
{
    kPlatOtaImg_None,   /*!< Default value when there is no upgradable image and current image was made permanent */
    kPlatImg_Acquiring, /*!< Acquisition of new firmware image is ongoing */
    kPlatOtaImg_CandidateRdy, /*!< Acquisition complete. It denotes that a candidate image is fully loaded.
                               * The application has to switch to this state when finishing the update operation.
                               * This state is transient and the bootloader is expected to change it to
                               * kPlatOtaImg_RunCandidate if the image verification criteria pass.
                               */
    kPlatOtaImg_RunCandidate, /*!< The bootloader needs to switch to this state before allowing the the test image
                               * to run. From this state, the application may decide to revert from the candidate image
                               * to the original one, or make it permanent.
                               */
    kPlatOtaImg_Permanent,    /*!< The application needs to switch to this state when the self-test is okay.
                               * This state can only exist if the OTA system provides a revert/confirmation mechanism
                               * such as that of MCUBOOT. When conplete, the image state become kPlatOtaImg_None again
                               * (allowing a    new OTA).
                               */
    kPlatOtaImg_Fail,
    kPlatOtaImg_Fatal,
    kPlatOtaImg_Max,
} PlatOtaImgState_t;

/*! \brief OTA partition characteristics structure
 */
typedef struct
{
    uint32_t start_offset; /*!< Offset of firmware update partition in flash device. The physical address is translated
                              by flash driver */
    uint32_t size;         /*! Size of firmware update storage expressed in bytes */
    uint32_t sector_size;  /*! Sector size of flash used for OTA, usually 4kB for external flash but varies for internal
                              flash */
    uint32_t page_size;    /*! Page size of flash device : minimal program size*/

    bool     internal_flash; /*! true if internal flash, false for SPI NOR Flash */
    uint32_t spi_baudrate;   /*! SPI baudrate concerns only external flash if flash config is not used KW45 case */

} OtaPartition_t;

/*! \brief  OTA Loader informations structure
 *
 * Data structure containing OTA Image to be loaded
 */
typedef struct
{
    uint32_t              image_addr; /*!< Image physical address */
    uint32_t              image_sz;   /*!< Image size in bytes */
    uint8_t *             pBitMap;    /*!< Downloaded image bitmap in flash potentially NULL if no bit map used */
    const OtaPartition_t *partition_desc;

} OtaLoaderInfo_t;

/* -------------------------------------------------------------------------- */
/*                              Public prototypes                             */
/* -------------------------------------------------------------------------- */

int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info);

/*! *********************************************************************************
 * \brief  Set necessary information to indicate a new image is ready after an OTA
 *
 * \param[in] ota_loader_info pointer on loader info structure used to pass candidate
 *            image start address and its size.
 * \param[in] img_state normally
 *
 * \return    < 0 if error, 0 otherwise
 ********************************************************************************** */
int PLATFORM_OtaNotifyNewImageReady(const OtaLoaderInfo_t *ota_loader_info);

/*! *********************************************************************************
* \brief  Post FW update clear boot flags
*
* \return    -1: Flash erase procedure failed
*             0: Erase successful and FW update succeeded
*             1: no erase was required
*             2: erase succeeded but FW update has failed
              3: Flash was erased but update status was reporting an unexpected value
********************************************************************************** */
int PLATFORM_OtaClearBootFlags(void);

/*! *********************************************************************************
 * \brief  Returns Image offset : leave space for BootData section when needed.
 *
 * \return    0 always on KW45
 ********************************************************************************** */
uint32_t PLATFORM_OtaGetImageOffset(void);

/**
 * \brief Returns internal partition configuration structure.
 * *
 * \return pointer on constant OtaPartition_t configuration structure if implemented NULL otherwise.
 */
const OtaPartition_t *PLATFORM_OtaGetOtaInternalPartitionConfig(void);

/**
 * \brief Returns external partition configuration structure.
 * *
 * \return pointer on constant OtaPartition_t configuration structure if implemented NULL otherwise.
 */
const OtaPartition_t *PLATFORM_OtaGetOtaExternalPartitionConfig(void);

/**
 * \brief Check the image validity.
 *
 * \param[in] data pointer on image start
 * \param[in] size image size
 *
 * \return 0 if no erro was detected, error code otherwise.
 */
int PLATFORM_OtaCheckImageValidity(const uint8_t *data, uint32_t size);

/**
 * \brief Retrieve the image state based on MCU boot information if used.
 *
 * \param[in/out] p_state pointer to byte where to return current state.
 *
 * \return -1 if unimplemented (platforms not supporting MCUBOOT)
 *         -2 if p_state not supplied
 *         0 otherwise
 */
int PLATFORM_OtaGetImageState(uint8_t *p_state);

/**
 * \brief Set the information to notify boot loader of intentions regarding
 *  the firmware image slots.
 *
 * \param[in] img_state image state to go to.
 *
 * \return 0 if no error was detected, error code otherwise.
 */
int PLATFORM_OtaUpdateImageState(uint8_t img_state);

/*!
 * @}  end of FWK_Platform_OTA
 */
/*!
 * @}  end of FWK_Platform_module addtogroup
 */
#endif /* __FWK_PLATFORM_OTA_H__ */
