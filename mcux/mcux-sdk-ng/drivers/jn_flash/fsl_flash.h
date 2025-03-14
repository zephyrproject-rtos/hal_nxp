/*
 * The Clear BSD License
 * Copyright 2014, NXP
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 *  that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FSL_FLASH_H_
#define FSL_FLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fsl_common.h"

/*!
 * @addtogroup jn_flash
 * @{
 */

/*! @file */

/*******************
 * EXPORTED MACROS  *
 ********************/

/* FLASH Commands */
#define FLASH_CMD_INIT             0
#define FLASH_CMD_POWERDOWN        1
#define FLASH_CMD_SET_READ_MODE    2
#define FLASH_CMD_READ_SINGLE_WORD 3
#define FLASH_CMD_ERASE_RANGE      4
#define FLASH_CMD_BLANK_CHECK      5
#define FLASH_CMD_MARGIN_CHECK     6
#define FLASH_CMD_CHECKSUM         7
#define FLASH_CMD_WRITE            8
#define FLASH_CMD_WRITE_PROG       10
#define FLASH_CMD_PROGRAM          12
#define FLASH_CMD_REPORT_ECC       13

/* FLASH Autoprogram modes */
#define FLASH_AUTO_OFF  0
#define FLASH_AUTO_WORD 1
#define FLASH_AUTO_PAGE 2

#define FLASH_BASE_ADDRESS 0
#define FLASH_PAGE_SIZE    512

/**
 * @brief FLASH INT_STATUS register definitions
 */
#define FLASH_FAIL    (1 << 0) /*!< Command failed */
#define FLASH_ERR     (1 << 1) /*!< Illegal command */
#define FLASH_DONE    (1 << 2) /*!< Command complete */
#define FLASH_ECC_ERR (1 << 3) /*!< ECC error detected */

/**
 * @brief FLASH INT_ENABLE register definitions
 */
#define FLASH_FAIL    (1 << 0) /*!< Command failed */
#define FLASH_ERR     (1 << 1) /*!< Illegal command */
#define FLASH_DONE    (1 << 2) /*!< Command complete */
#define FLASH_ECC_ERR (1 << 3) /*!< ECC error detected */

#define FLASH_STAT_ALL (0xF)

/* FLASH Events */
#define FLASH_EVENT_RESET (1 << 0)
//#define FLASH_EVENT_WAKEUP         (1 << 1)
//#define FLASH_EVENT_ABORT          (1 << 2)

/******************************
 * EXPORTED TYPE DEFINITIONS  *
 ******************************/

/*! @brief Flash configuration information.
 *
 * An instance of this structure is allocated by the user of the flash driver and
 * at initialization.
 */

typedef struct _flash_config
{
    uint32_t PFlashBlockBase;  /*!< A base address of the first PFlash block */
    uint32_t PFlashTotalSize;  /*!< The size of the combined PFlash block. */
    uint32_t PFlashSectorSize; /*!< The size in bytes of a sector of PFlash. */
} flash_config_t;

extern flash_config_t gFlashConfig;

/**
 * @brief	Enable the FLASH
 * @param	pFLASH		: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
void FLASH_Init(FLASH_Type *pFLASH);

/**
 * @brief	Power down the FLASH
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
void FLASH_Powerdown(FLASH_Type *pFLASH);

/**
 * @brief	Wait for FLASH command to complete
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	status
 */
int FLASH_Wait(FLASH_Type *pFLASH);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_Erase(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_ErasePages(FLASH_Type *pFLASH, uint32_t u32StartPage, uint32_t u32PageCount);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_BlankCheck(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_MarginCheck(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_Program(FLASH_Type *pFLASH, uint32_t *pu32Start, uint32_t *pu32Data, uint32_t u32Length);

/**
 * @brief	Erase page
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_Checksum(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End, uint32_t au32Checksum[4]);

/**
 * @brief	Read word
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_Read(FLASH_Type *pFLASH, uint8_t *pu8Start, uint32_t u32ReadMode, uint32_t au32Data[4]);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_JN518X_H_ */
