/*
 * Copyright 2018, 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_NFC_H_
#define FSL_NFC_H_

#include "fsl_common.h"

/*!
 * @addtogroup nfc_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_NFC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */

#define NFC_PAGE_SIZE_BYTE 4U /*!< Every page is 4 byte */
#define NFC_SHARED_MEM_PAGE_COUNT \
    ((sizeof(((RFIDNFC_Type *)0)->SHARED_MEM)) / NFC_PAGE_SIZE_BYTE) /*!< NFC shared RAM page count. */
#define NFC_SHARED_MEM_PAGE_OFFSET 4                                 /*!< Page offset for shared memory */

/*!
 * @brief NFC interrupts
 */
enum _nfc_interrupts
{
    kNFC_RFPowerInterrupt     = RFIDNFC_MIS_RFPOWER_MASK,     /*!< RFID power is detected. */
    kNFC_RFSelectInterrupt    = RFIDNFC_MIS_RFSELECT_MASK,    /*!< Tag is selected by reader. */
    kNFC_MemReadInterrupt     = RFIDNFC_MIS_MEMREAD_MASK,     /*!< Reader reads from shared memory. */
    kNFC_MemWriteInterrupt    = RFIDNFC_MIS_MEMWRITE_MASK,    /*!< Reader writes to shared memory. */
    kNFC_CmdWriteInterrupt    = RFIDNFC_MIS_CMDWRITE_MASK,    /*!< Reader writes to CMDIN register. */
    kNFC_CmdReadInterrupt     = RFIDNFC_MIS_CMDREAD_MASK,     /*!< Reader reads the DATAOUT register. */
    kNFC_TargetWriteInterrupt = RFIDNFC_MIS_TARGETWRITE_MASK, /*!< Reader writes to address specified by @ref
                                                                 NFC_SetTargetAddress> */
    kNFC_TargetReadInterrupt =
        RFIDNFC_MIS_TARGETREAD_MASK, /*!< Reader reads from address specified by @ref NFC_SetTargetAddress. */
    kNFC_NFCOffInterrupt = RFIDNFC_MIS_NFCOFF_MASK, /*!< NFC front-end is powered down by external reader. */
    kNFC_AllInterrupt    = RFIDNFC_MIS_RFPOWER_MASK | RFIDNFC_MIS_RFSELECT_MASK | RFIDNFC_MIS_MEMREAD_MASK |
                        RFIDNFC_MIS_MEMWRITE_MASK | RFIDNFC_MIS_CMDWRITE_MASK | RFIDNFC_MIS_CMDREAD_MASK |
                        RFIDNFC_MIS_TARGETWRITE_MASK | RFIDNFC_MIS_TARGETREAD_MASK | RFIDNFC_MIS_NFCOFF_MASK,
    /*!< All NFC interrupts. */
};

/*!
 * @brief NFC status flags
 */
enum _nfc_flags
{
    kNFC_PORFlag = RFIDNFC_SR_POR_MASK,   /*!< Indicates that the NFC analog core has been powered ON. */
    kNFC_1V2Flag = RFIDNFC_SR_R1V2_MASK,  /*!< Indicates a warning that VDD_RFID is < 1.2 V. */
    kNFC_1V5Flag = RFIDNFC_SR_R1V5_MASK,  /*!< Indicates a warning that VDD_RFID is < 1.5 V. */
    kNFC_PllFlag = RFIDNFC_SR_PLL_MASK,   /*!< Indicates that NFC PLL has been locked. */
    kNFC_SelFlag = RFIDNFC_SR_SEL_MASK,   /*!< Indicates that the NFC block has been activated via ISO/IEC 14443 Type A
                                      commands.   Or in other words the MIFARE Ultralight EV1 block has reached the ACTIVE
                                      state in   it's state machine. All memory operations falling under MIFARE Ultralight
                                      EV1   command set can now be carried out over the RF. */
    kNFC_AuthFlag = RFIDNFC_SR_AUTH_MASK, /*!< Indicates that password authentication is successful. All memory
                                     operations to password protected regions can now be carried out over the RF. */
    kNFC_BypassFlag = RFIDNFC_SR_BYPASS_MASK, /*!< Indicates that the NFC interface is in bypass mode. */
    kNFC_AllFlag    = RFIDNFC_SR_POR_MASK | RFIDNFC_SR_R1V2_MASK | RFIDNFC_SR_R1V5_MASK | RFIDNFC_SR_PLL_MASK |
                   RFIDNFC_SR_SEL_MASK | RFIDNFC_SR_AUTH_MASK | RFIDNFC_SR_BYPASS_MASK /*!< All flags. */
};

/*!
 * @brief NFC shared memory access type by the reader
 */
typedef enum _nfc_access
{
    kNFC_Read,  /*!< Share memory read by reader. */
    kNFC_Write, /*!< Share memory written by reader. */
} nfc_access_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initialize the NFC.
 *
 * This function initializes the peripheral, and resets the NFC registers status.
 * Any previously written NDEF message will be lost due to initialization of
 * shared memory.
 *
 * @param base NFC peripheral base address.
 */
void NFC_Init(RFIDNFC_Type *base);

/*!
 * @brief Deinitialize the NFC.
 *
 * @param base NFC peripheral base address.
 */
void NFC_DeInit(RFIDNFC_Type *base);

/*! @} */

/*!
 * @name Interrupt
 * @{
 */

/*!
 * @brief Enable the interrupts
 *
 * @param base NFC peripheral base address.
 * @param mask Interrupts to enable. OR'ed value of the @ref _nfc_interrupts.
 */
static inline void NFC_EnableInterrupts(RFIDNFC_Type *base, uint32_t mask)
{
    mask &= kNFC_AllInterrupt;
    base->IMIS |= mask;
}

/*!
 * @brief Disables the interrupts
 *
 * @param base NFC peripheral base address.
 * @param mask Interrupts to disable. OR'ed value of the @ref _nfc_interrupts.
 */
static inline void NFC_DisableInterrupts(RFIDNFC_Type *base, uint32_t mask)
{
    mask &= kNFC_AllInterrupt;
    base->IMIS &= ~mask;
}

/*!
 * @brief Get the enabled interrupts
 *
 * @param base NFC peripheral base address.
 * @return Interrupts enabled. OR'ed value of the @ref _nfc_interrupts.
 */
static inline uint32_t NFC_GetEnabledInterrupts(RFIDNFC_Type *base)
{
    return base->IMIS & kNFC_AllInterrupt;
}

/*!
 * @brief Get the interrupts pending status
 *
 * @param base NFC peripheral base address.
 * @return Interrupts pending status. OR'ed value of the @ref _nfc_interrupts.
 */
static inline uint32_t NFC_GetInterruptStatus(RFIDNFC_Type *base)
{
    return base->RIS & kNFC_AllInterrupt;
}

/*!
 * @brief Clear the interrupts pending status
 *
 * @param base NFC peripheral base address.
 * @param mask Interrupts status to clear. OR'ed value of the @ref _nfc_interrupts.
 */
static inline void NFC_ClearInterruptStatus(RFIDNFC_Type *base, uint32_t mask)
{
    base->ICR = mask & kNFC_AllInterrupt;
}

/*! @} */

/*!
 * @name Shared memory
 * @{
 */

/*!
 * @brief Writes to the shared memory
 *
 * @param base NFC peripheral base address.
 * @param pageIndex : Start page to write.
 * @param data : Address of the data to write.
 * @param numPage : Number of pages to write.
 *
 * @warning Because the shared memory could be access by the RF too, upper layer
 * sould make sure no write conflict.
 */
void NFC_WritePage(RFIDNFC_Type *base, uint32_t pageIndex, const uint32_t *data, uint32_t numPage);

/*!
 * @brief Read from the shared memory
 *
 * @param base NFC peripheral base address.
 * @param pageIndex : Start page to read.
 * @param data : Address of the data to read.
 * @param numPage : Number of pages to read.
 *
 * @warning Because the shared memory could be access by the RF too, upper layer
 * sould make sure RF is not writing the same pages during core reading.
 *
 */
void NFC_ReadPage(RFIDNFC_Type *base, uint32_t pageIndex, uint32_t *data, uint32_t numPage);

/*! @} */

/*!
 * @name Misc
 * @{
 */

/**
 * Returns the status information from the NFC block
 * @param base : The base address of the NFC peripheral on the chip
 * @return Status of the NFC HW block.
 */
static inline uint32_t NFC_GetStatusFlag(RFIDNFC_Type *base)
{
    return base->SR & kNFC_AllFlag;
}

/*!
 * @brief Set the target address
 *
 * When read or write access happens to the address set by this function, the
 * interrupt @ref kNFC_TargetReadInterrupt or @ref kNFC_TargetWriteInterrupt
 * asserts.
 *
 * @param base NFC peripheral base address.
 * @param pageIndex The page index to set.
 */
static inline void NFC_SetTargetAddress(RFIDNFC_Type *base, uint32_t pageIndex)
{
    base->TARGET = pageIndex + NFC_SHARED_MEM_PAGE_OFFSET;
}

/*!
 * @brief Get the status of last RF access
 *
 * @param base NFC peripheral base address.
 * @param [out] pStartPageIndex : Start page index for last RF access
 * @param [out] pEndPageIndex : Last accessed page index for last RF access
 * @return Access type.
 */
nfc_access_t NFC_GetLastAccessInfo(RFIDNFC_Type *base, int32_t *pStartPageIndex, int32_t *pEndPageIndex);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* FSL_NFC_H_ */
