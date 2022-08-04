/*
 * Copyright 2020-2022 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _SDMMC_CONFIG_H_
#define _SDMMC_CONFIG_H_

#ifdef SD_ENABLED
#include "fsl_sd.h"
#endif
#ifdef MMC_ENABLED
#include "fsl_mmc.h"
#endif
#ifdef SDIO_ENABLED
#include "fsl_sdio.h"
#endif
#include "clock_config.h"
#include "fsl_adapter_gpio.h"
#include "fsl_sdmmc_host.h"
#include "fsl_sdmmc_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* @brief host basic configuration */
#define BOARD_SDMMC_SD_HOST_BASEADDR   USDHC0
#define BOARD_SDMMC_SD_HOST_IRQ        USDHC0_IRQn
#define BOARD_SDMMC_MMC_HOST_BASEADDR  USDHC0
#define BOARD_SDMMC_MMC_HOST_IRQ       USDHC0_IRQn
#define BOARD_SDMMC_SDIO_HOST_BASEADDR USDHC0
#define BOARD_SDMMC_SDIO_HOST_IRQ      USDHC0_IRQn
/* @brief card detect type
 *
 * Note: if you want to use DAT3 as card detect pin, please make sure the DAT3 is pulled down with 100K resistor on
 * board, it is not suggest to use the internal pull down function, from our test result, internal pull down is too
 * strong to cover all the card. And please pay attention, DAT3 card detection cannot works during the card access,
 * since the DAT3 will be used for data transfer, thus the functionality of card detect will be disabled. Using card
 * detect pin for card detection is recommended.
 */
#define BOARD_SDMMC_SD_CD_TYPE                       kSD_DetectCardByHostCD
#define BOARD_SDMMC_SD_CARD_DETECT_DEBOUNCE_DELAY_MS (100U)
/*! @brief SD power reset */
#define BOARD_SDMMC_SD_POWER_RESET_GPIO_CLOCK_NAME   kCLOCK_HsGpio4
#define BOARD_SDMMC_SD_POWER_RESET_GPIO_RESET_SOURCE kHSGPIO4_RST_SHIFT_RSTn
#define BOARD_SDMMC_SD_POWER_RESET_GPIO_BASE         GPIO
#define BOARD_SDMMC_SD_POWER_RESET_GPIO_PORT         4
#define BOARD_SDMMC_SD_POWER_RESET_GPIO_PIN          0U

/* the EVK board require mannual tuning for sd, since there is a EMI filter between 595 and card socket which will
 * affect the standard tuning*/
#define BOARD_SDMMC_SD_TUNING_TYPE             1
#define BOARD_SDMMC_SD_IO_VOLTAGE_CONTROL_TYPE kSD_IOVoltageCtrlByGpio

/* @brief mmc configuration */
#define BOARD_SDMMC_MMC_VCC_SUPPLY               kMMC_VoltageWindows270to360
#define BOARD_SDMMC_MMC_VCCQ_SUPPLY              kMMC_VoltageWindow170to195
#define BOARD_SDMMC_MMC_SUPPORT_8_BIT_DATA_WIDTH 1U
#define BOARD_SDMMC_MMC_TUNING_TYPE              0
#define BOARD_SDMMC_DATA_BUFFER_ALIGN_SIZE       (4U)

/*!@ brief host interrupt priority*/
#define BOARD_SDMMC_SD_HOST_IRQ_PRIORITY   (5U)
#define BOARD_SDMMC_MMC_HOST_IRQ_PRIORITY  (5U)
#define BOARD_SDMMC_SDIO_HOST_IRQ_PRIORITY (5U)
/*!@brief dma descriptor buffer size */
#define BOARD_SDMMC_HOST_DMA_DESCRIPTOR_BUFFER_SIZE (32U)

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief BOARD SD configurations.
 * @param card card descriptor
 * @param cd card detect callback
 * @param userData user data for callback
 */
#ifdef SD_ENABLED
void BOARD_SD_Config(void *card, sd_cd_t cd, uint32_t hostIRQPriority, void *userData);
#endif

/*!
 * @brief BOARD SDIO configurations.
 * @param card card descriptor
 * @param cd card detect callback
 * @param cardInt card interrupt
 */
#ifdef SDIO_ENABLED
void BOARD_SDIO_Config(void *card, sd_cd_t cd, uint32_t hostIRQPriority, sdio_int_t cardInt);
#endif

/*!
 * @brief BOARD MMC configurations.
 * @param card card descriptor
 * @param cd card detect callback
 * @param userData user data for callback
 */
#ifdef MMC_ENABLED
void BOARD_MMC_Config(void *card, uint32_t hostIRQPriority);

#endif

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
