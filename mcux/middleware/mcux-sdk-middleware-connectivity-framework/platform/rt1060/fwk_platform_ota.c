/*
 * Copyright 2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fwk_platform_ota.h"
#include "FunctionLib.h"

extern uint32_t OTA_STORAGE_SIZE[];
#define PARTITION_SIZE ((uint32_t)OTA_STORAGE_SIZE)

/* TODO : Define Platform Ota bootloader functions */

int PLATFORM_OtaUpdateBootFlags(const OtaLoaderInfo_t *ota_load_info)
{
    return 0;
}

int PLATFORM_OtaBootDataUpdateOnCommit(const OtaLoaderInfo_t *ota_loader_info)
{
    return 0;
}

int PLATFORM_OtaClearBootFlags(void)
{
    return 0;
}

uint32_t PLATFORM_OtaGetImageOffset(bool internal_storage)
{
    NOT_USED(internal_storage);
    return 0U;
}

uint32_t PLATFORM_OtaGetMaxImageSize(bool internal_storage)
{
    NOT_USED(internal_storage);
    return PARTITION_SIZE;
}
status_t PLATFORM_OtaGetOtaPartitionConfig(OtaPartition_t *partition, bool internal_storage)
{
    status_t st = kStatus_InvalidArgument;
    NOT_USED(internal_storage);
    if (partition)
    {
        memset(partition, 0x0, sizeof(OtaPartition_t));
#if 0 /* TODO populate with right values */
        partition->start_offset = (uint32_t)FW_UPDATE_STORAGE_OFFSET;
#endif

        partition->size        = PARTITION_SIZE;
        partition->sector_size = KB(4);
        st                     = kStatus_Success;
    }
    return st;
}

void PLATFORM_InitSPIFlash(void)
{
}

//#endif /*(!gEnableOTAServer_d || (gEnableOTAServer_d && gUpgradeImageOnCurrentDevice_d)) */
