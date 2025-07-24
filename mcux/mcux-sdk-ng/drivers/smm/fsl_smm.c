/*
 * Copyright 2025 NXP
 *
 * All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "fsl_smm.h"


/*******************************************************************************
* Definitions
******************************************************************************/


/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.smm
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

/*!
 * brief Set external interrupt configuration.
 * 
 * param base SMM base address.
 * param ptrConfig Pointer to configuration in type of smm_ext_int_config_t.
 */
void SMM_SetExtInterruptConfig(SMM_Type *base, const smm_ext_int_config_t *ptrConfig)
{
    uint32_t tmp32 = 0UL;

    tmp32 = (base->CNFG) & ~(SMM_CNFG_EXT_INTP_POL_MASK | SMM_CNFG_EXT_INTP_MASK_MASK);
    tmp32 |= SMM_CNFG_EXT_INTP_MASK(ptrConfig->maskExtIntPin) | SMM_CNFG_EXT_INTP_POL(ptrConfig->extIntPolarity);

    base->CNFG = tmp32;
}

/*!
 * brief Write data to backup registers.
 * 
 * param base SMM base address.
 * param[in] ptrBackupRegContent Pointer of the content will write to backup registers.
 */
void SMM_WriteToBackupReg(SMM_Type *base, const smm_backup_reg_content_t *ptrBackupRegContent)
{
    base->LSB_BCKP1 = SMM_LSB_BCKP1_LSB1(ptrBackupRegContent->word1);
    base->MSB_BCKP1 = SMM_MSB_BCKP1_MSB1(ptrBackupRegContent->word1 >> 16UL);
    base->LSB_BCKP2 = SMM_LSB_BCKP2_LSB2(ptrBackupRegContent->word2);
    base->MSB_BCKP2 = SMM_MSB_BCKP2_MSB2(ptrBackupRegContent->word2 >> 16UL);
}

/*!
 * brief Read data from backup registers.
 * 
 * param base SMM base address.
 * param[out] ptrBackupRegContent Pointer of the content will read from backup registers.
 */
void SMM_ReadFromBackupReg(SMM_Type *base, smm_backup_reg_content_t *ptrBackupRegContent)
{
    ptrBackupRegContent->word1 = (uint32_t)(base->LSB_BCKP1 | (base->MSB_BCKP1 << 16UL));
    ptrBackupRegContent->word2 = (uint32_t)(base->LSB_BCKP2 | (base->MSB_BCKP2 << 16UL));
}

/*!
 * brief Enable memory retention at low power modes for main CPU.
 * 
 * param base SMM base address.
 * param sramCuts Mask of sram cuts to retained.
 */
void SMM_EnableMainDomainSramRetention(SMM_Type *base, uint16_t sramCuts)
{
    uint32_t tmp32 = (base->MEMORY_RTN & ~(SMM_MEMORY_RTN_RETAIN_EN_MASK | SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET_MASK));

    if (sramCuts != 0U)
    {
        tmp32 |= SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET(sramCuts) | SMM_MEMORY_RTN_RETAIN_EN_MASK;
    }

    base->MEMORY_RTN = tmp32;
}
