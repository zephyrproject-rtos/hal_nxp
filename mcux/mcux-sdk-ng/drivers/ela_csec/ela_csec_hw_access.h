/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CSEC_HW_ACCESS_H
#define CSEC_HW_ACCESS_H

#include <stdint.h>
#include <stdbool.h>
#include "fsl_common.h"

/**
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 10.5,
 * Impermissible cast; cannot cast from 'essentially unsigned' to 'essentially enum<i>'.
 * All possible values are covered by the enumeration, direct casting is used to optimize code.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 10.3,
 * Expression assigned to a narrower or different essential type.
 * All possible values are covered by the enumeration, direct casting is used to optimize code.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 11.4, Conversion between a pointer and
 * integer type.
 * The cast is required to initialize a pointer with an unsigned long define,
 * representing an address.
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 11.6, Cast from unsigned int to pointer.
 * The cast is required to initialize a pointer with an unsigned long define,
 * representing an address.
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#include <stddef.h>
#include "ela_csec_driver.h"

/*!
 * @brief Specifies how the data is transferred to/from the CSE.
 * There are two use cases. One is to copy all data and the command function call
 * method and the other is a pointer and function call method.
 *
 * Implements : csec_func_format_t_Class
 */
typedef enum {
    CSEC_FUNC_FORMAT_COPY,
    CSEC_FUNC_FORMAT_ADDR
} csec_func_format_t;

 /*! @brief Represents the result of the execution of a command. Provides one bit
for each error code as per SHE specification. */
#define CSEC_NO_ERROR            0x1U
#define CSEC_SEQUENCE_ERROR      0x2U
#define CSEC_KEY_NOT_AVAILABLE   0x4U
#define CSEC_KEY_INVALID         0x8U
#define CSEC_KEY_EMPTY           0x10U
#define CSEC_NO_SECURE_BOOT      0x20U
#define CSEC_KEY_WRITE_PROTECTED 0x40U
#define CSEC_KEY_UPDATE_ERROR    0x80U
#define CSEC_RNG_SEED            0x100U
#define CSEC_NO_DEBUGGING        0x200U
#define CSEC_MEMORY_FAILURE      0x400U
#define CSEC_GENERAL_ERROR       0x800U

#define CSEC_UPPER_HALF_MASK    (0xFFFF0000U)
#define CSEC_UPPER_HALF_SHIFT   (0x10U)
#define CSEC_LOWER_HALF_MASK    (0xFFFFU)
#define CSEC_LOWER_HALF_SHIFT   (0U)


/*!
 * CSE_PRAM_Register_Masks ELA_CSEC PRAM Register Masks
 *
 */

/* RAMn_DATA_32 Bit Fields */
#define CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK        0xFFu
#define CSE_PRAM_RAMn_DATA_32_BYTE_3_SHIFT       0u
#define CSE_PRAM_RAMn_DATA_32_BYTE_3_WIDTH       8u
#define CSE_PRAM_RAMn_DATA_32_BYTE_3(x)          (((uint32_t)(((uint32_t)(x))<<CSE_PRAM_RAMn_DATA_32_BYTE_3_SHIFT))&CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK)
#define CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK        0xFF00u
#define CSE_PRAM_RAMn_DATA_32_BYTE_2_SHIFT       8u
#define CSE_PRAM_RAMn_DATA_32_BYTE_2_WIDTH       8u
#define CSE_PRAM_RAMn_DATA_32_BYTE_2(x)          (((uint32_t)(((uint32_t)(x))<<CSE_PRAM_RAMn_DATA_32_BYTE_2_SHIFT))&CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK)
#define CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK        0xFF0000u
#define CSE_PRAM_RAMn_DATA_32_BYTE_1_SHIFT       16u
#define CSE_PRAM_RAMn_DATA_32_BYTE_1_WIDTH       8u
#define CSE_PRAM_RAMn_DATA_32_BYTE_1(x)          (((uint32_t)(((uint32_t)(x))<<CSE_PRAM_RAMn_DATA_32_BYTE_1_SHIFT))&CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK)
#define CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK        0xFF000000u
#define CSE_PRAM_RAMn_DATA_32_BYTE_0_SHIFT       24u
#define CSE_PRAM_RAMn_DATA_32_BYTE_0_WIDTH       8u
#define CSE_PRAM_RAMn_DATA_32_BYTE_0(x)          (((uint32_t)(((uint32_t)(x))<<CSE_PRAM_RAMn_DATA_32_BYTE_0_SHIFT))&CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK)
/* RAMn_ACCESS8BIT_DATA_8LL Bit Fields */
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL_MASK 0xFFu
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL_SHIFT 0u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL_WIDTH 8u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL(x) (((uint8_t)(((uint8_t)(x))<<CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL_SHIFT))&CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LL_RAM_LL_MASK)
/* RAMn_ACCESS8BIT_DATA_8LU Bit Fields */
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU_MASK 0xFFu
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU_SHIFT 0u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU_WIDTH 8u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU(x) (((uint8_t)(((uint8_t)(x))<<CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU_SHIFT))&CSE_PRAM_RAMn_ACCESS8BIT_DATA_8LU_RAM_LU_MASK)
/* RAMn_ACCESS8BIT_DATA_8HL Bit Fields */
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL_MASK 0xFFu
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL_SHIFT 0u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL_WIDTH 8u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL(x) (((uint8_t)(((uint8_t)(x))<<CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL_SHIFT))&CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HL_RAM_HL_MASK)
/* RAMn_ACCESS8BIT_DATA_8HU Bit Fields */
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU_MASK 0xFFu
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU_SHIFT 0u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU_WIDTH 8u
#define CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU(x) (((uint8_t)(((uint8_t)(x))<<CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU_SHIFT))&CSE_PRAM_RAMn_ACCESS8BIT_DATA_8HU_RAM_HU_MASK)

/*! \public
 * @brief Generic status return codes.
 */
enum
{
    /* Security specific error codes */
    kStatus_SEC_SEQUENCE_ERROR              = MAKE_STATUS(kStatusGroup_Generic, 0x402U),  /*!< The sequence of commands or subcommands is out of sequence */
    kStatus_SEC_KEY_NOT_AVAILABLE           = MAKE_STATUS(kStatusGroup_Generic, 0x403U),  /*!< A key is locked due to failed boot measurement or an active debugger */
    kStatus_SEC_KEY_INVALID                 = MAKE_STATUS(kStatusGroup_Generic, 0x404U),  /*!< A function is called to perform an operation with a key that is not allowed for the given operation */
    kStatus_SEC_KEY_EMPTY                   = MAKE_STATUS(kStatusGroup_Generic, 0x405U),  /*!< Attempt to use a key that has not been initialized yet */
    kStatus_SEC_NO_SECURE_BOOT              = MAKE_STATUS(kStatusGroup_Generic, 0x406U),  /*!< The conditions for a secure boot process are not met */
    kStatus_SEC_KEY_WRITE_PROTECTED         = MAKE_STATUS(kStatusGroup_Generic, 0x407U),  /*!< Request for updating a write protected key slot, or activating debugger with write protected key(s) */
    kStatus_SEC_KEY_UPDATE_ERROR            = MAKE_STATUS(kStatusGroup_Generic, 0x408U),  /*!< Key update did not succeed due to errors in verification of the messages */
    kStatus_SEC_RNG_SEED                    = MAKE_STATUS(kStatusGroup_Generic, 0x409U),  /*!< Returned by CMD_RND and CMD_DEBUG if the seed has not been initialized before */
    kStatus_SEC_NO_DEBUGGING                = MAKE_STATUS(kStatusGroup_Generic, 0x40AU),  /*!< DEBUG command authentication failed */
    kStatus_SEC_MEMORY_FAILURE              = MAKE_STATUS(kStatusGroup_Generic, 0x40CU),  /*!< General memory technology failure (multibit ECC error, common fault detected) */
    kStatus_SEC_HSM_INTERNAL_MEMORY_ERROR   = MAKE_STATUS(kStatusGroup_Generic, 0x410U),  /*!< An internal memory error encountered while executing the command */
    kStatus_SEC_INVALID_COMMAND             = MAKE_STATUS(kStatusGroup_Generic, 0x411U),  /*!< Command value out of range */
    kStatus_SEC_TRNG_ERROR                  = MAKE_STATUS(kStatusGroup_Generic, 0x412U),  /*!< One or more statistical tests run on the TRNG output failed */
    kStatus_SEC_HSM_FLASH_BLOCK_ERROR       = MAKE_STATUS(kStatusGroup_Generic, 0x413U),  /*!< Error reading, programming or erasing one of the HSM flash blocks */
    kStatus_SEC_INTERNAL_CMD_ERROR          = MAKE_STATUS(kStatusGroup_Generic, 0x414U),  /*!< An internal command processor error while executing a command */
    kStatus_SEC_MAC_LENGTH_ERROR            = MAKE_STATUS(kStatusGroup_Generic, 0x415U),  /*!< MAC/Message length out of range */
    kStatus_SEC_INVALID_ARG                 = MAKE_STATUS(kStatusGroup_Generic, 0x421U),  /*!< Invalid command argument */
    kStatus_SEC_TRNG_CLOCK_ERROR            = MAKE_STATUS(kStatusGroup_Generic, 0x423U),  /*!< TRNG not provided with a stable clock */
};

/* Security specific error codes */
#define  STATUS_SUCCESS                          kStatus_Success
#define  STATUS_ERROR                            kStatus_Fail
#define  STATUS_SEC_SEQUENCE_ERROR               kStatus_SEC_SEQUENCE_ERROR  /*!< The sequence of commands or subcommands is out of sequence */
#define  STATUS_SEC_KEY_NOT_AVAILABLE            kStatus_SEC_KEY_NOT_AVAILABLE  /*!< A key is locked due to failed boot measurement or an active debugger */
#define  STATUS_SEC_KEY_INVALID                  kStatus_SEC_KEY_INVALID  /*!< A function is called to perform an operation with a key that is not allowed for the given operation */
#define  STATUS_SEC_KEY_EMPTY                    kStatus_SEC_KEY_EMPTY  /*!< Attempt to use a key that has not been initialized yet */
#define  STATUS_SEC_NO_SECURE_BOOT               kStatus_SEC_NO_SECURE_BOOT  /*!< The conditions for a secure boot process are not met */
#define  STATUS_SEC_KEY_WRITE_PROTECTED          kStatus_SEC_KEY_WRITE_PROTECTED  /*!< Request for updating a write protected key slot, or activating debugger with write protected key(s) */
#define  STATUS_SEC_KEY_UPDATE_ERROR             kStatus_SEC_KEY_UPDATE_ERROR  /*!< Key update did not succeed due to errors in verification of the messages */
#define  STATUS_SEC_RNG_SEED                     kStatus_SEC_RNG_SEED  /*!< Returned by CMD_RND and CMD_DEBUG if the seed has not been initialized before */
#define  STATUS_SEC_NO_DEBUGGING                 kStatus_SEC_NO_DEBUGGING  /*!< DEBUG command authentication failed */
#define  STATUS_SEC_MEMORY_FAILURE               kStatus_SEC_MEMORY_FAILURE  /*!< General memory technology failure (multibit ECC error, common fault detected) */
#define  STATUS_SEC_HSM_INTERNAL_MEMORY_ERROR    kStatus_SEC_HSM_INTERNAL_MEMORY_ERROR  /*!< An internal memory error encountered while executing the command */
#define  STATUS_SEC_INVALID_COMMAND              kStatus_SEC_INVALID_COMMAND  /*!< Command value out of range */
#define  STATUS_SEC_TRNG_ERROR                   kStatus_SEC_TRNG_ERROR  /*!< One or more statistical tests run on the TRNG output failed */
#define  STATUS_SEC_HSM_FLASH_BLOCK_ERROR        kStatus_SEC_HSM_FLASH_BLOCK_ERROR  /*!< Error reading, programming or erasing one of the HSM flash blocks */
#define  STATUS_SEC_INTERNAL_CMD_ERROR           kStatus_SEC_INTERNAL_CMD_ERROR  /*!< An internal command processor error while executing a command */
#define  STATUS_SEC_MAC_LENGTH_ERROR             kStatus_SEC_MAC_LENGTH_ERROR  /*!< MAC/Message length out of range */
#define  STATUS_SEC_INVALID_ARG                  kStatus_SEC_INVALID_ARG  /*!< Invalid command argument */
#define  STATUS_SEC_TRNG_CLOCK_ERROR             kStatus_SEC_TRNG_CLOCK_ERROR  /*!< TRNG not provided with a stable clock */

/*! @brief Converts the FTFM flash module registers access */
#if FEATURE_CSEC_HAS_FTFM_MODULE
#define FTFC					(FTFM)
#define FTFC_FSTAT_CCIF_MASK	FTFM_FSTAT_CCIF_MASK
#define FTFC_FCNFG_CCIE_MASK	FTFM_FCNFG_CCIE_MASK
#define FTFC_FCNFG_CCIE			FTFM_FCNFG_CCIE
#endif
/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Writes the command header to ELA_CSEC PRAM.
 *
 * This function writes the command header to ELA_CSEC PRAM, triggering the CSEc
 * operation.
 *
 * @param[in] funcId The ID of the operation to be started.
 * @param[in] funcFormat Specifies how the data is transferred to/from the CSE.
 * @param[in] callSeq Specifies if the information is the first or a following
 * function call.
 * @param[in] keyId Specify the KeyID to be used to implement the requested
 * cryptographic operation.
 */
static inline void CSEC_WriteCommandHeader(csec_cmd_t funcId,
                                       csec_func_format_t funcFormat,
                                       csec_call_sequence_t callSeq,
                                       csec_key_id_t keyId)
{
    ELA_CSEC->DATA_32[0u] =
        CSE_PRAM_RAMn_DATA_32_BYTE_0(funcId) |
        CSE_PRAM_RAMn_DATA_32_BYTE_1(funcFormat) |
        CSE_PRAM_RAMn_DATA_32_BYTE_2(callSeq) |
        CSE_PRAM_RAMn_DATA_32_BYTE_3(keyId);
}

/*!
 * @brief Writes command bytes to ELA_CSEC PRAM.
 *
 * This function writes command bytes to ELA_CSEC PRAM, at a 32-bit aligned offset.
 *
 * @param[in] offset The offset (in bytes) at which the bytes shall be written.
 * @param[in] bytes The buffer containing the bytes to be written.
 * @param[in] numBytes The number of bytes to be written.
 */
void CSEC_WriteCommandBytes(uint8_t offset, const uint8_t *bytes, uint8_t numBytes);

/*!
 * @brief Writes a command half word to ELA_CSEC PRAM.
 *
 * This function writes a command half word to ELA_CSEC PRAM, at a 16-bit aligned
 * offset.
 *
 * @param[in] offset The offset (in bytes) at which the half word shall be
 * written.
 * @param[in] halfWord The half word to be written.
 */
void CSEC_WriteCommandHalfWord(uint8_t offset, uint16_t halfWord);

/*!
 * @brief Writes a command byte to ELA_CSEC PRAM.
 *
 * This function writes a command byte to ELA_CSEC PRAM.
 *
 * @param[in] offset The offset (in bytes) at which the byte shall be written.
 * @param[in] byte The byte to be written.
 */
void CSEC_WriteCommandByte(uint8_t offset, uint8_t byte);

/*!
 * @brief Writes command words to ELA_CSEC PRAM.
 *
 * This function writes command words to ELA_CSEC PRAM, at a 32-bit aligned offset.
 *
 * @param[in] offset The offset (in bytes) at which the words shall be written.
 * @param[in] words The buffer containing the words to be written.
 * @param[in] numWords The number of words to be written.
 */
void CSEC_WriteCommandWords(uint8_t offset, const uint32_t *words, uint8_t numWords);

/*!
 * @brief Reads command bytes from ELA_CSEC PRAM.
 *
 * This function reads command bytes from ELA_CSEC PRAM, from a 32-bit aligned offset.
 *
 * @param[in] offset The offset (in bytes) from which the bytes shall be read.
 * @param[out] bytes The buffer containing the bytes read.
 * @param[in] numBytes The number of bytes to be read.
 */
void CSEC_ReadCommandBytes(uint8_t offset, uint8_t *bytes, uint8_t numBytes);

/*!
 * @brief Reads a command byte from ELA_CSEC PRAM.
 *
 * This function reads a command byte from ELA_CSEC PRAM.
 *
 * @param[in] offset The offset (in bytes) from which the byte shall be read.
 * @return The byte read.
 */
uint8_t CSEC_ReadCommandByte(uint8_t offset);

/*!
 * @brief Reads a command word from ELA_CSEC PRAM.
 *
 * This function reads a command word from ELA_CSEC PRAM, from a 32-bit aligned offset.
 *
 * @param[in] offset The offset (in bytes) from which the word shall be read.
 * @return The word read.
 */
static inline uint32_t CSEC_ReadCommandWord(uint8_t offset)
{
    return ELA_CSEC->DATA_32[offset >> 2U];
}

/*!
 * @brief Waits for the completion of a CSEc command.
 *
 * This function waits for the completion of a CSEc command.
 */
static inline void CSEC_WaitCommandCompletion(void)
{
    while ((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0U)
    {
        /* Wait until the CCIF flag is set */
    }
}

/*!
 * @brief Reads the error bits from PRAM.
 *
 * This function reads the error bits reported after running a CSEc command.
 *
 * @return Error Code after command execution.
 */
static inline status_t CSEC_ReadErrorBits(void)
{
	uint32_t errWord;
    uint16_t errBits;
    status_t stat;

    errWord = CSEC_ReadCommandWord(FSL_FEATURE_ELA_CSEC_ERROR_BITS_OFFSET);
    errBits = (uint16_t)((errWord & CSEC_UPPER_HALF_MASK) >> CSEC_UPPER_HALF_SHIFT);

    switch (errBits)
    {
    case CSEC_NO_ERROR:
        stat = STATUS_SUCCESS;
        break;
    case CSEC_SEQUENCE_ERROR:
        stat = STATUS_SEC_SEQUENCE_ERROR;
        break;
    case CSEC_KEY_NOT_AVAILABLE:
        stat = STATUS_SEC_KEY_NOT_AVAILABLE;
        break;
    case CSEC_KEY_INVALID:
        stat = STATUS_SEC_KEY_INVALID;
        break;
    case CSEC_KEY_EMPTY:
        stat = STATUS_SEC_KEY_EMPTY;
        break;
    case CSEC_NO_SECURE_BOOT:
        stat = STATUS_SEC_NO_SECURE_BOOT;
        break;
    case CSEC_KEY_WRITE_PROTECTED:
        stat = STATUS_SEC_KEY_WRITE_PROTECTED;
        break;
    case CSEC_KEY_UPDATE_ERROR:
        stat = STATUS_SEC_KEY_UPDATE_ERROR;
        break;
    case CSEC_RNG_SEED:
        stat = STATUS_SEC_RNG_SEED;
        break;
    case CSEC_NO_DEBUGGING:
        stat = STATUS_SEC_NO_DEBUGGING;
        break;
    case CSEC_MEMORY_FAILURE:
        stat = STATUS_SEC_MEMORY_FAILURE;
        break;
    case CSEC_GENERAL_ERROR:
    default:
        stat = STATUS_ERROR;
        break;
    }

    return stat;
}

/*!
 * @brief Writes the command header to ELA_CSEC PRAM and waits for completion.
 *
 * This function writes the header of a command and waits for completion.
 * The function is always located in RAM, and is used for CSEc commands using
 * pointer methods, in order to allow the MGATE to read from FLASH without
 * causing a read collision.
 *
 * @param[in] funcId The ID of the operation to be started.
 * @param[in] funcFormat Specifies how the data is transferred to/from the CSE.
 * @param[in] callSeq Specifies if the information is the first or a following
 * function call.
 * @param[in] keyId Specify the KeyID to be used to implement the requested
 * cryptographic operation.
 */
//START_FUNCTION_DECLARATION_RAMSECTION
RAMFUNCTION_SECTION_CODE(void CSEC_WriteCmdAndWait(csec_cmd_t funcId,
        csec_func_format_t funcFormat,
        csec_call_sequence_t callSeq,
        csec_key_id_t keyId));
//END_FUNCTION_DECLARATION_RAMSECTION

/*!
 * @brief Enables/Disables the command completion interrupt.
 *
 * This function enables/disables the command completion interrupt.
 *
 * @param[in] enable Enable/Disable the command completion interrupt.
 */
static inline void CSEC_SetInterrupt(bool enable)
{
    uint8_t tmp = FTFC->FCNFG;

    FTFC->FCNFG = (uint8_t)((tmp & ~FTFC_FCNFG_CCIE_MASK) | FTFC_FCNFG_CCIE(enable ? 1U : 0U));
}

#if defined(__cplusplus)
}
#endif

#endif /* CSEC_HW_ACCESS_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
