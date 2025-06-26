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

#include "fsl_flash.h"
#include "rom_api.h"
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.jn_flash"
#endif

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

#define MAX_ERASE_LENGTH (FLASH_PAGE_SIZE * 100)

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/
flash_config_t gFlashConfig;

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	Enable the FLASH
 * @param	pFLASH		: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
void FLASH_Init(FLASH_Type *pFLASH)
{
    /* From Flash Adapter */
    gFlashConfig.PFlashSectorSize = FLASH_PAGE_SIZE;
    ROM_GetFlash(&gFlashConfig.PFlashBlockBase, &gFlashConfig.PFlashTotalSize);

    pFLASH->CMD = FLASH_CMD_INIT;

    FLASH_Wait(pFLASH);
}

/**
 * @brief	Power down the FLASH
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
void FLASH_Powerdown(FLASH_Type *pFLASH)
{
    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    pFLASH->CMD = FLASH_CMD_POWERDOWN;

    FLASH_Wait(pFLASH);
}

/**
 * @brief	Wait for FLASH command to complete
 * @param	pFLASH	: Pointer to selected FLASHx peripheral
 * @return	Nothing
 */
int FLASH_Wait(FLASH_Type *pFLASH)
{
    while (!(pFLASH->INT_STATUS & FLASH_DONE))
        ;
    return pFLASH->INT_STATUS;
}

int FLASH_Erase(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End)
{
    int status = 0;

    uint32_t erase_length = pu8End - pu8Start;

    while (erase_length > 0)
    {
        pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

        if (erase_length > MAX_ERASE_LENGTH)
        {
            pu8End = pu8Start + MAX_ERASE_LENGTH - 1;
            erase_length -= MAX_ERASE_LENGTH;
        }
        else
        {
            pu8End       = pu8Start + erase_length;
            erase_length = 0;
        }

        /* Set end address */
        *pu8End = 0xAA;

        /* Set start address */
        *pu8Start = 0xBB;

        pu8Start = pu8End + 1;

        pFLASH->CMD = FLASH_CMD_ERASE_RANGE;

        status = FLASH_Wait(pFLASH);
    }

    return status;
}

int FLASH_ErasePages(FLASH_Type *pFLASH, uint32_t u32StartPage, uint32_t u32PageCount)
{
    uint8_t *pu8Start = (uint8_t *)(FLASH_PAGE_SIZE * u32StartPage);
    uint8_t *pu8End   = (pu8Start + FLASH_PAGE_SIZE * u32PageCount) - 1;

    return FLASH_Erase(pFLASH, pu8Start, pu8End);
}

int FLASH_BlankCheck(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End)
{
    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    /* Set end address */
    *pu8End = 0xAA;

    /* Set start address */
    *pu8Start = 0xBB;

    pFLASH->CMD = FLASH_CMD_BLANK_CHECK;

    return FLASH_Wait(pFLASH);
}

int FLASH_MarginCheck(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End)
{
    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    /* Set end address */
    *pu8End = 0xAA;

    /* Set start address */
    *pu8Start = 0xBB;

    pFLASH->CMD = FLASH_CMD_MARGIN_CHECK;

    return FLASH_Wait(pFLASH);
}

int FLASH_Program(FLASH_Type *pFLASH, uint32_t *pu32Start, uint32_t *pu32Data, uint32_t u32Length)
{
    int status = 0;

    uint32_t start = (uint32_t)pu32Start;
    uint32_t end   = start + u32Length;

    uint32_t padding = (512 - (end & 511)) & 511;

    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    pFLASH->AUTOPROG = FLASH_AUTO_PAGE;

    memcpy((uint32_t *)start, pu32Data, u32Length);

    memset((uint32_t *)end, 0, padding);

    status = FLASH_Wait(pFLASH);

    pFLASH->AUTOPROG = FLASH_AUTO_OFF;

    return status;
}

int FLASH_Checksum(FLASH_Type *pFLASH, uint8_t *pu8Start, uint8_t *pu8End, uint32_t au32Checksum[4])
{
    int status;
    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    /* Set end address */
    *pu8End = 0xAA;

    /* Set start address */
    *pu8Start = 0xBB;

    pFLASH->CMD = FLASH_CMD_CHECKSUM;

    status = FLASH_Wait(pFLASH);

    au32Checksum[0] = pFLASH->DATAW[0];
    au32Checksum[1] = pFLASH->DATAW[1];
    au32Checksum[2] = pFLASH->DATAW[2];
    au32Checksum[3] = pFLASH->DATAW[3];

    return status;
}

int FLASH_Read(FLASH_Type *pFLASH, uint8_t *pu8Start, uint32_t u32ReadMode, uint32_t au32Data[4])
{
    int status;
    pFLASH->INT_CLR_STATUS = FLASH_STAT_ALL;

    /* Set start address */
    *pu8Start = 0xBB;

    /* Set read mode */
    pFLASH->DATAW[0] = u32ReadMode;

    pFLASH->CMD = FLASH_CMD_READ_SINGLE_WORD;

    status = FLASH_Wait(pFLASH);

    au32Data[0] = pFLASH->DATAW[0];
    au32Data[1] = pFLASH->DATAW[1];
    au32Data[2] = pFLASH->DATAW[2];
    au32Data[3] = pFLASH->DATAW[3];

    return status;
}
