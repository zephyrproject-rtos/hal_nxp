/*
 * Copyright 2020 - 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_common.h"
#include "fwk_hal_macros.h"
#include "fwk_platform_ota.h"
#include "fwk_platform_extflash.h"
#include "fwk_config.h"
#include "FunctionLib.h"
#include "fsl_debug_console.h"

/************************************************************************************
*************************************************************************************
* Private type definitions and macros
*************************************************************************************
************************************************************************************/
/*!
 * \brief The following symbols give information on the firmware update storage section location
 *        and size must be provided by the linker.
 *        FW_UPDATE_STORAGE_OFFSET: Offset address of the firmware update storage
 *        relative to the start address of the flash
 *        FW_UPDATE_STORAGE_SIZE: Size of the whole firmware update storage section.
 *
 */
extern uint32_t FW_UPDATE_STORAGE_OFFSET[];
extern uint32_t FW_UPDATE_STORAGE_SIZE[];
extern uint32_t FW_ACTIVE_APP_OFFSET[];
extern uint32_t FW_ACTIVE_APP_SIZE[];

#define gExtFlash_StartOffset_c ((uint32_t)FW_UPDATE_STORAGE_OFFSET)
#define gExtFlash_TotalSize_c   ((uint32_t)FW_UPDATE_STORAGE_SIZE)
#define gExtFlash_SectorSize_c  KB(4)

#define _SECTOR_ADDR(x)         (((x) & ~(PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
#define _PAGE_ADDR(x)           (((x) & ~(PLATFORM_EXTFLASH_PAGE_SIZE - 1U)))
#define _ROUND_TO_UPPER_SECT(x) _SECTOR_ADDR(((x) + (PLATFORM_EXTFLASH_SECTOR_SIZE - 1U)))
#define _ROUND_TO_LOWER_SECT(x) _SECTOR_ADDR((x))

/* Stuff related to OTA */
#define FLASH_CONFIG_OFFSET 0x400U  /* The Flash Config is placed in the 1rst sector */
#define BOOTLOADER_OFFSET   0U      /* MCU boot is located at a sector frontier */
#define BOOTLOADER_SIZE     KB(128) /* MCU boot Stated size */

/* Start address of the primary application partition (Active App) */
#define ACTIVE_IMAGE_OFFSET ((uint32_t)FW_ACTIVE_APP_OFFSET)

/* Image size if rounded to a size multiple of sectors size (4kB) */
#define IMAGE_SIZE ((uint32_t)FW_ACTIVE_APP_SIZE)

/* Start address of the secondary application partition (Candidate App) */
#define CANDIDATE_IMAGE_OFFSET ((uint32_t)FW_UPDATE_STORAGE_OFFSET)

#define FLASH_AREA_IMAGE_1_OFFSET ACTIVE_IMAGE_OFFSET
#define FLASH_AREA_IMAGE_1_SIZE   IMAGE_SIZE
#define FLASH_AREA_IMAGE_2_OFFSET CANDIDATE_IMAGE_OFFSET
#define FLASH_AREA_IMAGE_2_SIZE   IMAGE_SIZE /* But slots are equally sized */

/* Image Header */
#define IMAGE_MAGIC       0x96f3b83dU
#define IMAGE_HEADER_SIZE 32

/* Image trailer */
#define BOOT_MAX_ALIGN 8
#define BOOT_FLAG_SET  1

struct image_version
{
    uint8_t  iv_major;
    uint8_t  iv_minor;
    uint16_t iv_revision;
    uint32_t iv_build_num;
};

/** Image header.  All fields are in little endian byte order. */
struct image_header
{
    uint32_t             ih_magic;
    uint32_t             ih_load_addr;
    uint16_t             ih_hdr_size;         /* Size of image header (bytes). */
    uint16_t             ih_protect_tlv_size; /* Size of protected TLV area (bytes). */
    uint32_t             ih_img_size;         /* Does not include header. */
    uint32_t             ih_flags;            /* IMAGE_F_[...]. */
    struct image_version ih_ver;
    uint32_t             _pad1;
};

#define IMAGE_TLV_INFO_MAGIC      0x6907
#define IMAGE_TLV_PROT_INFO_MAGIC 0x6908

/** Image TLV header.  All fields in little endian. */
struct image_tlv_info
{
    uint16_t it_magic;
    uint16_t it_tlv_tot; /* size of TLV area (including tlv_info header) */
};

struct image_trailer
{
    uint8_t swap_type;
    uint8_t pad1[BOOT_MAX_ALIGN - 1];
    uint8_t copy_done;
    uint8_t pad2[BOOT_MAX_ALIGN - 1];
    uint8_t image_ok;
    uint8_t pad3[BOOT_MAX_ALIGN - 1];
    uint8_t magic[16];
};

#define TRAILER1_OFFSET (FLASH_AREA_IMAGE_1_OFFSET + FLASH_AREA_IMAGE_1_SIZE - sizeof(struct image_trailer))
#define TRAILER2_OFFSET (FLASH_AREA_IMAGE_2_OFFSET + FLASH_AREA_IMAGE_2_SIZE - sizeof(struct image_trailer))

/************************************************************************************
 * Private memory declarations
 ************************************************************************************/

const uint32_t trailer_img_magic[] = {
    0xf395c277,
    0x7fefd260,
    0x0f505235,
    0x8079b62c,
};

static const OtaPartition_t ota_partition_cfg = {.start_offset   = gExtFlash_StartOffset_c,
                                                 .size           = gExtFlash_TotalSize_c,
                                                 .sector_size    = gExtFlash_SectorSize_c,
                                                 .page_size      = 256u,
                                                 .internal_flash = false};

/************************************************************************************
*************************************************************************************
* Private functions
*************************************************************************************
************************************************************************************/

static int trailer_img_magic_check(uint8_t *p)
{
    return FLib_MemCmp(p, (uint8_t *)trailer_img_magic, sizeof(trailer_img_magic));
}

static int check_unset(uint8_t *p, uint32_t length)
{
    return FLib_MemCmpToVal(p, 0xFFU, length);
}

static status_t boot_wipe_candidate_trailer(void)
{
    return PLATFORM_EraseExternalFlash(TRAILER2_OFFSET, PLATFORM_EXTFLASH_SECTOR_SIZE);
}

static status_t boot_swap_test(void)
{
    uint32_t off;
    status_t status;

    uint32_t              buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    struct image_trailer *image_trailer_p =
        (struct image_trailer *)((uint8_t *)buf + PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer));
    do
    {
        off = TRAILER2_OFFSET;

        memset(buf, 0xff, PLATFORM_EXTFLASH_PAGE_SIZE);
        memcpy(image_trailer_p->magic, trailer_img_magic, sizeof(trailer_img_magic));

        PRINTF("write magic number offset = 0x%x\r\n", off);

        status = PLATFORM_EraseExternalFlash(off, sizeof(trailer_img_magic));
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to erase trailer2\r\n", __FUNCTION__);
            break;
        }

        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, _PAGE_ADDR(off));
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to write trailer2\r\n", __FUNCTION__);
            break;
        }
        else
        {
            PRINTF("%s: Wrote trailer at offset %08x %08x", __FUNCTION__, off, _PAGE_ADDR(off));
        }
    } while (false);
    return status;
}

status_t boot_swap_perm(void)
{
    uint32_t off;
    status_t status;

    uint32_t              buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    struct image_trailer *image_trailer_p =
        (struct image_trailer *)((uint8_t *)buf + PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer));

    off = TRAILER2_OFFSET;

    memset(buf, 0xff, PLATFORM_EXTFLASH_PAGE_SIZE);
    memcpy(image_trailer_p->magic, trailer_img_magic, sizeof(trailer_img_magic));
    image_trailer_p->image_ok = BOOT_FLAG_SET;

    do
    {
        status = PLATFORM_EraseExternalFlash(off, sizeof(trailer_img_magic));
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to erase trailer2\r\n", __FUNCTION__);
            break;
        }

        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, _PAGE_ADDR(off));
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to write trailer2\r\n", __FUNCTION__);
            break;
        }
    } while (false);

    return status;
}

static status_t boot_swap_ok(void)
{
    uint32_t page_off;
    status_t status;

    uint32_t              buf[PLATFORM_EXTFLASH_PAGE_SIZE / 4]; /* ensure the buffer is word aligned */
    struct image_trailer *image_trailer_p =
        (struct image_trailer *)((uint8_t *)buf + PLATFORM_EXTFLASH_PAGE_SIZE - sizeof(struct image_trailer));

    do
    {
        page_off = _PAGE_ADDR(TRAILER1_OFFSET);
        status   = PLATFORM_ReadExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, page_off, false);
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to read trailer\r\n", __FUNCTION__);
            break;
        }

        if ((trailer_img_magic_check(image_trailer_p->magic) == 0) || (image_trailer_p->copy_done != 0x01))
        {
            /* the image in the slot is likely incomplete (or none) */
            PRINTF("%s: no image awaiting confirmation\r\n", __FUNCTION__);
            status = kStatus_Fail; /* No data */
            break;
        }

        if (image_trailer_p->image_ok == BOOT_FLAG_SET)
        {
            /* nothing to be done, report it and return */
            PRINTF("%s: image already confirmed\r\n", __FUNCTION__);
            status = kStatus_Success; /* set it explicitly */
            break;
        }

        /* mark image ok */
        image_trailer_p->image_ok = BOOT_FLAG_SET;

        /* erase trailer */
        status = PLATFORM_EraseExternalFlash(_SECTOR_ADDR(page_off), PLATFORM_EXTFLASH_SECTOR_SIZE);
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to erase trailer\r\n", __FUNCTION__);
            break;
        }

        /* write trailer */
        status = PLATFORM_WriteExternalFlash((uint8_t *)buf, PLATFORM_EXTFLASH_PAGE_SIZE, page_off);
        if (status != kStatus_Success)
        {
            PRINTF("%s: failed to write trailer\r\n", __FUNCTION__);
            break;
        }
    } while (false);
    return status;
}

/*! *********************************************************************************
 * \brief  Patch candidate image's trailer to mark it 'ready for test' or 'permanent'
 *
 * \param[in] img_state: kPlatOtaImg_CandidateRdy or kPlatOtaImg_Permanent are expected
 *
 * \return    kStatus_InvalidArgument is cur_state out of expected set.
 *            k_Status_Success if flash operations succeed.
 *********************************************************************************** */
int PLATFORM_OtaUpdateImageState(uint8_t img_state)
{
    status_t ret;

    switch (img_state)
    {
        case kPlatOtaImg_CandidateRdy:
            ret = boot_swap_test();
            break;

        case kPlatOtaImg_Permanent:
            ret = boot_swap_ok();
            break;

        default:
            ret = kStatus_InvalidArgument;
            break;
    }

    return (int)ret;
}

/*! *********************************************************************************
 * \brief  Read the active and candidate image trailer and determine image state
 *         checking the contents.
 *
 * \param[in] p_state: pointer on state enum to pass value deduved from current and
 *           candidate application trailer contents.
 *           The value returned in p_state can be one of:
 *           - kPlatOtaImg_CandidateRdy: if candidate trailer is correct but the remainder unset.
 *           - kPlatOtaImg_Permanent: if candidate trailer's magic is correct and image marked OK.
 *           - kPlatOtaImg_RunCandidate: if candidate trailer's magic is unset and active trailer
 *             is valid, and active trailer's copy done is marked. (revert back)
 *           - kPlatOtaImg_None in other cases if no error.
 *           - kPlatOtaImg_Fail if an error occurs while reading the external flash
 *.
 *
 * \return    kStatus_Success if flash operations suceed otherwise status of failing operation.
 *            Disregard *p_state if not kStatus_Success.
 *********************************************************************************** */
int PLATFORM_OtaGetImageState(uint8_t *p_state)
{
    int ret = -1;

    struct image_trailer image_trailer1;
    struct image_trailer image_trailer2;

    do
    {
        PlatOtaImgState_t state;
        if (p_state == NULL)
        {
            ret = kStatus_InvalidArgument;
            break;
        }
        state = (PlatOtaImgState_t)*p_state;
        if (state == kPlatOtaImg_None)
        {
            *p_state = kPlatOtaImg_Fail;
            ret = PLATFORM_ReadExternalFlash((uint8_t *)&image_trailer1, sizeof(struct image_trailer), TRAILER1_OFFSET,
                                             false);
            if (ret != kStatus_Success)
            {
                PRINTF("%s: failed to read trailer%d\r\n", __FUNCTION__, 1);
                break;
            }

            ret = PLATFORM_ReadExternalFlash((uint8_t *)&image_trailer2, sizeof(struct image_trailer), TRAILER2_OFFSET,
                                             false);
            if (ret != kStatus_Success)
            {
                PRINTF("%s: failed to read trailer$d\r\n", __FUNCTION__, 2);
                break;
            }

            if (trailer_img_magic_check(image_trailer2.magic))
            {
                if (check_unset(&image_trailer2.image_ok, sizeof(image_trailer2.image_ok)))
                {
                    /* State I (request for swapping upon next reboot) */
                    *p_state = kPlatOtaImg_CandidateRdy;
                    ret      = kStatus_Success;
                    break;
                }
                else if (image_trailer2.image_ok == 0x01)
                {
                    /* State II (image marked for permanent change) */
                    *p_state = kPlatOtaImg_Permanent;
                    ret      = kStatus_Success;
                    break;
                }
            }
            else if (check_unset(image_trailer2.magic, sizeof(image_trailer2.magic)))
            {
                if (trailer_img_magic_check(image_trailer1.magic) && (image_trailer1.image_ok == 0xff) &&
                    (image_trailer1.copy_done == 0x01))
                {
                    /* State III (revert scheduled for next reboot => image is under test) */
                    *p_state = kPlatOtaImg_RunCandidate;
                    ret      = kStatus_Success;
                    break;
                }
            }
            *p_state = kPlatOtaImg_None; /* State IV default */
        }
        ret = kStatus_Success;
    } while (false);

    return ret;
}

/************************************************************************************
*************************************************************************************
* Public functions
*************************************************************************************
************************************************************************************/

int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info)
{
    uint32_t size = ota_loader_info->image_sz;
    return PLATFORM_OtaCheckImageValidity((const uint8_t *)ota_loader_info->image_addr, size);
}

int PLATFORM_OtaNotifyNewImageReady(const OtaLoaderInfo_t *ota_loader_info)
{
    int st = -1;
    NOT_USED(ota_loader_info);
    status_t status;
    status = PLATFORM_OtaUpdateImageState(kPlatOtaImg_CandidateRdy);
    if (status == kStatus_Success)
    {
        st = 0;
    }
    return st;
}

int PLATFORM_OtaClearBootFlags(void)
{
    int st = -1;
    if (boot_wipe_candidate_trailer() == kStatus_Success)
    {
        st = 0;
    }
    return st;
}

uint32_t PLATFORM_OtaGetImageOffset(void)
{
    return 0u;
}

const OtaPartition_t *PLATFORM_OtaGetOtaInternalPartitionConfig(void)
{
    return NULL;
}

const OtaPartition_t *PLATFORM_OtaGetOtaExternalPartitionConfig(void)
{
    return &ota_partition_cfg;
}

/*! *********************************************************************************
 * \brief  Perform validity checks on candidate image header
 *
 * \param[in] data: byte pointer on candidate image
 * \param[in] size: image size including header.
 *
 * \return    0 if image is valid , -1 otherwise
 *
 *********************************************************************************** */
int PLATFORM_OtaCheckImageValidity(const uint8_t *img_addr, uint32_t size)
{
    struct image_header *  ih;
    struct image_tlv_info *it;
    uint32_t               decl_size;
    uint32_t               tlv_size;
    int                    ret  = -1;
    uint8_t *              data = FLASH_SOC_ADDR(img_addr);
    ih                          = (struct image_header *)data;
    do
    {
        /* do we have at least the header */
        if (size < sizeof(struct image_header))
        {
            break;
        }
        /* check magic number in image header */
        if (ih->ih_magic != IMAGE_MAGIC)
        {
            break;
        }

        /* check that we have at least the amount of data declared by the header */
        decl_size = ih->ih_img_size + ih->ih_hdr_size + ih->ih_protect_tlv_size;
        if (size < decl_size)
        {
            break;
        }
        /* check protected TLVs if any */
        if (ih->ih_protect_tlv_size > 0)
        {
            if (ih->ih_protect_tlv_size < sizeof(struct image_tlv_info))
            {
                break;
            }
            it = (struct image_tlv_info *)(data + ih->ih_img_size + ih->ih_hdr_size);
            if ((it->it_magic != IMAGE_TLV_PROT_INFO_MAGIC) || (it->it_tlv_tot != ih->ih_protect_tlv_size))
            {
                break;
            }
        }

        /* check for optional TLVs following the image as declared by the header */
        tlv_size = size - decl_size;
        if (tlv_size > 0)
        {
            if (tlv_size < sizeof(struct image_tlv_info))
            {
                break;
            }
            it = (struct image_tlv_info *)(data + decl_size);
            if ((it->it_magic != IMAGE_TLV_INFO_MAGIC) || (it->it_tlv_tot != tlv_size))
            {
                break;
            }
        }

        ret = 0;

    } while (false);
    return ret;
}
