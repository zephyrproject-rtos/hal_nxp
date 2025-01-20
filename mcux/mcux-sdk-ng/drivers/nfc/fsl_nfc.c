/*
 * Copyright 2018, 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_nfc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.nfc"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

#define NFC_TERMINATOR_TLV 0x000000FE /*!< Terminator TLV. */

/*****************************************************************************
 * Public functions
 ****************************************************************************/
/*!
 * brief Initialize the NFC.
 *
 * This function initializes the peripheral, and resets the NFC registers status.
 * Any previously written NDEF message will be lost due to initialization of
 * shared memory.
 *
 * param base NFC peripheral base address.
 */
void NFC_Init(RFIDNFC_Type *base)
{
    base->SHARED_MEM[0] = NFC_TERMINATOR_TLV; /*Terminate shared RAM with a terminator TLV*/

    /* Disable NFC interrupt. */
    NFC_DisableInterrupts(base, kNFC_AllInterrupt);

    /* Clear any pending stray NFC interrupts. */
    NFC_ClearInterruptStatus(base, kNFC_AllInterrupt);

    /* Disabling bypass mode. */
    base->CFG = 0x0;
}

/*!
 * brief Deinitialize the NFC.
 *
 * param base NFC peripheral base address.
 */
void NFC_DeInit(RFIDNFC_Type *base)
{
    /* Disable NFC interrupt. */
    NFC_DisableInterrupts(base, kNFC_AllInterrupt);

    /* Clear any pending stray NFC interrupts. */
    NFC_ClearInterruptStatus(base, kNFC_AllInterrupt);
}

/*!
 * brief Get the status of last RF access
 *
 * param base NFC peripheral base address.
 * param [out] pStartPageIndex : Start page index for last RF access
 * param [out] pEndPageIndex : Last accessed page index for last RF access
 * return Access type.
 */
nfc_access_t NFC_GetLastAccessInfo(RFIDNFC_Type *base, int32_t *pStartPageIndex, int32_t *pEndPageIndex)
{
    uint32_t last_access = base->LAST_ACCESS;

    *pStartPageIndex =
        ((last_access & RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_MASK) >> RFIDNFC_LAST_ACCESS_LAST_ACCESS_START_SHIFT) -
        NFC_SHARED_MEM_PAGE_OFFSET;
    *pEndPageIndex =
        ((last_access & RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_MASK) >> RFIDNFC_LAST_ACCESS_LAST_ACCESS_END_SHIFT) -
        NFC_SHARED_MEM_PAGE_OFFSET;

    if ((last_access & RFIDNFC_LAST_ACCESS_DIR_MASK) == RFIDNFC_LAST_ACCESS_DIR_MASK)
    {
        return kNFC_Write;
    }
    else
    {
        return kNFC_Read;
    }
}

/*!
 * brief Writes to the shared memory
 *
 * param base NFC peripheral base address.
 * param pageIndex : Start page to write.
 * param data : Address of the data to write.
 * param numPage : Number of pages to write.
 *
 * warning Because the shared memory could be access by the RF too, upper layer
 * sould make sure no write conflict.
 */
void NFC_WritePage(RFIDNFC_Type *base, uint32_t pageIndex, const uint32_t *data, uint32_t numPage)
{
    assert(pageIndex + numPage <= NFC_SHARED_MEM_PAGE_COUNT);
    uint32_t i;

    for (i = 0; i < numPage; i++)
    {
        base->SHARED_MEM[pageIndex++] = data[i];
    }
}

/*!
 * brief Read from the shared memory
 *
 * param base NFC peripheral base address.
 * param pageIndex : Start page to read.
 * param data : Address of the data to read.
 * param numPage : Number of pages to read.
 *
 * warning Because the shared memory could be access by the RF too, upper layer
 * sould make sure RF is not writing the same pages during core reading.
 *  .
 */
void NFC_ReadPage(RFIDNFC_Type *base, uint32_t pageIndex, uint32_t *data, uint32_t numPage)
{
    assert(pageIndex + numPage <= NFC_SHARED_MEM_PAGE_COUNT);
    uint32_t i;

    for (i = 0; i < numPage; i++)
    {
        data[i] = base->SHARED_MEM[pageIndex++];
    }
}
