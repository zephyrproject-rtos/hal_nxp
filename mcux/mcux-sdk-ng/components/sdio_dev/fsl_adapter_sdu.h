/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ADAPTER_SDU_H
#define FSL_ADAPTER_SDU_H

#include <stdint.h>
#include "fsl_sdioslv_sdu.h"

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FSL_FEATURE_SOC_SDIO_COUNT (3)

#define SDU_CMD_DNLD_OVR  (1U << 0U)
#define SDU_DATA_DNLD_OVR (1U << 1U)
#define SDU_CMD_UPLD_OVR  (1U << 2U)
#define SDU_DATA_UPLD_OVR (1U << 3U)

typedef enum _sdu_for_read_type
{
    SDU_TYPE_FOR_READ_CMD = 0,
    SDU_TYPE_FOR_READ_DATA = 1,
    SDU_TYPE_FOR_READ_EVENT= 2,
    SDU_TYPE_FOR_READ_MAX,
} sdu_for_read_type_t;

typedef enum _sdu_for_write_type
{
    SDU_TYPE_FOR_WRITE_CMD = 0,
    SDU_TYPE_FOR_WRITE_DATA = 1,
    SDU_TYPE_FOR_WRITE_MAX,
} sdu_for_write_type_t;

typedef struct _sdio_header
{
    uint16_t len;
    uint16_t type;
} sdio_header_t;

#define SDIO_SLEEP_HS_DONE 1U
#define SDIO_HOST_RESET_DONE 2U
#define SDIO_HOST_INIT_DONE 3U

/*******************************************************************************
 * APIs
 ******************************************************************************/


#if defined(__cplusplus)
extern "C" {
#endif

/*! @} */

bool SDU_IsPhase3En(void);
status_t SDU_ReadReg(uint32_t fn, uint32_t offset, uint8_t *val);
status_t SDU_WriteReg(uint32_t fn, uint32_t offset, uint8_t val);

status_t SDU_Init(void);
status_t SDU_InitPhase1(void);
status_t SDU_InitPhase2(void);
status_t SDU_InitPhase3(void);
void SDU_Deinit(void);
void SDU_EnterSuspend(void);
void SDU_ExitSuspend(void);
status_t SDU_EnterPowerDown(void);
status_t SDU_ExitPowerDownLite(void);
status_t SDU_ExitPowerDown(void);
status_t SDU_ExitPowerDownPhase2(void);
status_t SDU_ExitPowerDownPhase3(void);
status_t SDU_WritePowerMode(int32_t pm_state);
status_t SDU_CheckHostStatus(uint8_t *status);
uint32_t SDU_CheckUpldOvrDone(void);
status_t SDU_GetFwReady(uint16_t *val);
void SDU_GetDefaultCISTable(const uint32_t SDU_BASE);
status_t SDU_SetFwReady(void);

typedef void (*sdu_callback_t)(void *tlv, size_t tlv_sz);
status_t SDU_InstallCallback(sdu_for_write_type_t type, sdu_callback_t callback);

/*!
 * @brief SDU send cmd/event/data.
 *
 * @param sdu_for_read_type_t type for cmd/event/data.
 * @param data_addr Data Address.
 * @param data_len Data Length.
 * @retval #kStatus_Success buffer is added to data slot with problem.
 * @retval #kStatus_InvalidArgument Invalid argument.
 * @retval #kStatus_NoData No free buffer to use.
 * @retval #kStatus_Fail Fail to send data.
 */
status_t SDU_Send(sdu_for_read_type_t type, uint8_t *data_addr, uint16_t data_len);

status_t SDU_RecvCmd(void);
status_t SDU_RecvData(void);

void SDU_DriverIRQHandler(void);

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif
