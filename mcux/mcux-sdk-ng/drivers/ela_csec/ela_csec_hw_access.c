/*
 * Copyright 2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ela_csec_hw_access.h"

/**
 * @page misra_violations MISRA-C:2012 violations
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
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * The function is defined for use by application code.
 */

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_WriteCommandBytes
 * Description   : This function writes command bytes to ELA_CSEC PRAM at
 * 32-bit aligned addresses.
 *
 *END**************************************************************************/
void CSEC_WriteCommandBytes(uint8_t offset, const uint8_t *bytes, uint8_t numBytes)
{
    uint8_t i = 0U;

    assert(bytes != NULL);

    while ((i + 3U) < numBytes)
    {
        ELA_CSEC->DATA_32[(offset + i) >> 2U] =
            CSE_PRAM_RAMn_DATA_32_BYTE_0(bytes[i]) |
            CSE_PRAM_RAMn_DATA_32_BYTE_1(bytes[i + 1U]) |
            CSE_PRAM_RAMn_DATA_32_BYTE_2(bytes[i + 2U]) |
            CSE_PRAM_RAMn_DATA_32_BYTE_3(bytes[i + 3U]);
        i = (uint8_t)(i + 4U);
    }
    while (i < numBytes)
    {
        CSEC_WriteCommandByte(offset + i, bytes[i]);
        i++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_WriteCommandHalfWord
 * Description   : This function writes a command half word to ELA_CSEC PRAM at
 * a 16-bit aligned offset.
 *
 *END**************************************************************************/
void CSEC_WriteCommandHalfWord(uint8_t offset, uint16_t halfWord)
{
    uint32_t tmp;

    tmp = ELA_CSEC->DATA_32[(offset >> 2U)];

    if ((offset & 2U) != 0U)
    {
        tmp = tmp & ~CSEC_LOWER_HALF_MASK;
        tmp = tmp | ((((uint32_t) halfWord) << CSEC_LOWER_HALF_SHIFT) & CSEC_LOWER_HALF_MASK);
    }
    else
    {
        tmp = tmp & ~CSEC_UPPER_HALF_MASK;
        tmp = tmp | ((((uint32_t) halfWord) << CSEC_UPPER_HALF_SHIFT) & CSEC_UPPER_HALF_MASK);
    }

    ELA_CSEC->DATA_32[(offset >> 2U)] = tmp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_WriteCommandByte
 * Description   : This function writes a single byte to ELA_CSEC PRAM.
 *
 *END**************************************************************************/
void CSEC_WriteCommandByte(uint8_t offset, uint8_t byte)
{
    uint32_t temp = 0U;

    temp = ELA_CSEC->DATA_32[offset >> 2U];

    switch (offset & 0x3U)
    {
    case 0x0U:
    	temp = temp & ~CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK;
    	temp = temp | ((((uint32_t)(byte) << CSE_PRAM_RAMn_DATA_32_BYTE_0_SHIFT)) & CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK);
    	break;
    case 0x1U:
    	temp = temp & ~CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK;
		temp = temp | ((((uint32_t)(byte) << CSE_PRAM_RAMn_DATA_32_BYTE_1_SHIFT)) & CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK);
        break;
    case 0x2U:
    	temp = temp & ~CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK;
		temp = temp | ((((uint32_t)(byte) << CSE_PRAM_RAMn_DATA_32_BYTE_2_SHIFT)) & CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK);
        break;
    case 0x3U:
    	temp = temp & ~CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK;
		temp = temp | ((((uint32_t)(byte) << CSE_PRAM_RAMn_DATA_32_BYTE_3_SHIFT)) & CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK);
        break;
    default:
        /* Impossible to get here */
        break;
    }
    ELA_CSEC->DATA_32[offset >> 2U] = temp;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_WriteCommandWords
 * Description   : This function writes command words to ELA_CSEC PRAM at a
 * 32-bit aligned offset.
 *
 *END**************************************************************************/
void CSEC_WriteCommandWords(uint8_t offset, const uint32_t *words, uint8_t numWords)
{
    uint8_t i = 0U;
    uint8_t alignedOffset = (uint8_t)(offset >> 2U);

    assert(words != NULL);

    while (i < numWords)
    {
        ELA_CSEC->DATA_32[alignedOffset + i] = words[i];
        i++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_ReadCommandBytes
 * Description   : This function reads command bytes from ELA_CSEC PRAM from a
 * 32-bit aligned offset.
 *
 *END**************************************************************************/
void CSEC_ReadCommandBytes(uint8_t offset, uint8_t *bytes, uint8_t numBytes)
{
    uint8_t i = 0U;

    assert(bytes != NULL);

    while ((i + 3U) < numBytes)
    {
        uint32_t tmp = ELA_CSEC->DATA_32[(offset + i) >> 2U];

        bytes[i]      = (uint8_t)((tmp & CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_0_SHIFT);
        bytes[i + 1U] = (uint8_t)((tmp & CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_1_SHIFT);
        bytes[i + 2U] = (uint8_t)((tmp & CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_2_SHIFT);
        bytes[i + 3U] = (uint8_t)((tmp & CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_3_SHIFT);
        i = (uint8_t)(i + 4U);
    }
    while (i < numBytes)
    {
        bytes[i] = CSEC_ReadCommandByte(offset + i);
        i++;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_ReadCommandByte
 * Description   : This function reads a single byte from ELA_CSEC PRAM.
 *
 *END**************************************************************************/
uint8_t CSEC_ReadCommandByte(uint8_t offset)
{
    uint8_t byte = 0;
    uint32_t temp = 0U;

    temp = ELA_CSEC->DATA_32[offset >> 2U];

    switch (offset & 0x3U)
    {
    case 0x0U:
        byte = (uint8_t)((temp & CSE_PRAM_RAMn_DATA_32_BYTE_0_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_0_SHIFT);
        break;
    case 0x1U:
        byte = (uint8_t)((temp & CSE_PRAM_RAMn_DATA_32_BYTE_1_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_1_SHIFT);
        break;
    case 0x2U:
        byte = (uint8_t)((temp & CSE_PRAM_RAMn_DATA_32_BYTE_2_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_2_SHIFT);
        break;
    case 0x3U:
        byte = (uint8_t)((temp & CSE_PRAM_RAMn_DATA_32_BYTE_3_MASK) >> CSE_PRAM_RAMn_DATA_32_BYTE_3_SHIFT);
        break;
    default:
        /* Impossible to get here */
        break;
    }

    return byte;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CSEC_WriteCmdAndWait
 * Description   : This function writes the header of a command and waits for
 * completion.
 *
 *END**************************************************************************/
//START_FUNCTION_DEFINITION_RAMSECTION
RAMFUNCTION_SECTION_CODE(void CSEC_WriteCmdAndWait(csec_cmd_t funcId,
        csec_func_format_t funcFormat,
        csec_call_sequence_t callSeq,
        csec_key_id_t keyId))
{
    ELA_CSEC->DATA_32[0] =
        CSE_PRAM_RAMn_DATA_32_BYTE_0(funcId) |
        CSE_PRAM_RAMn_DATA_32_BYTE_1(funcFormat) |
        CSE_PRAM_RAMn_DATA_32_BYTE_2(callSeq) |
        CSE_PRAM_RAMn_DATA_32_BYTE_3(keyId);

    while ((FTFC->FSTAT & FTFC_FSTAT_CCIF_MASK) == 0U)
    {
        /* Wait until the CCIF flag is set */
    }
}
//END_FUNCTION_DEFINITION_RAMSECTION

/*******************************************************************************
 * EOF
 ******************************************************************************/
