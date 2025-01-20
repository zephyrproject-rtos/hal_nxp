/*
 * Copyright 2020 - 2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_mcm.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_mcm"
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
 * brief Gets the processor's attributes of the last faulted core access to the system bus.
 *
 * param base MCM peripheral base address.
 * param psAttribute The pointer of structure ref mcm_core_fault_attribute_t.
 */
void MCM_GetCoreFaultAttribute(MCM_Type *base, mcm_core_fault_attribute_t *psAttribute)
{
    assert(psAttribute != NULL);

    psAttribute->eType       = (mcm_last_fault_access_type_t)(base->CFATR & MCM_CFATR_TYPE_MASK);
    psAttribute->bBufferable = (bool)(base->CFATR & MCM_CFATR_BUFFER_MASK);
    psAttribute->eSize       = (mcm_last_fault_access_size_t)(base->CFATR & MCM_CFATR_SIZE_MASK);
    psAttribute->eDirection  = (mcm_last_fault_access_dir_t)(base->CFATR & MCM_CFATR_DIR_MASK);
}

/*!
 * brief Sets the configuration of resource protection, including flash base address, ram base address, etc.
 *
 * param base MCM peripheral base address.
 * param psConfig The pointer of structure ref mcm_resource_protection_config_t.
 * retval kStatus_Success Succeed in setting resource protection related options.
 * retval kStatus_Fail    Fail to set resource protection related options.
 */
status_t MCM_SetResourceProtectionConfig(MCM_Type *base, const mcm_resource_protection_config_t *psConfig)
{
    assert(psConfig != NULL);

    status_t eStatus;

    if ((base->RPCR & MCM_RPCR_RPE_MASK) == 0UL)
    {
        base->UFLASHBAR = MCM_UFLASHBAR_FBA(psConfig->u8FlashBaseAddress);
        base->UPRAMBAR  = MCM_UPRAMBAR_RBA(psConfig->u8RamBaseAddress);
#if (defined(FSL_FEATURE_MCM_HAS_UBROMBAR_REGISTER) && FSL_FEATURE_MCM_HAS_UBROMBAR_REGISTER)
        base->UBROMBAR = MCM_UBROMBAR_RBA(psConfig->u32BootRomBaseAddress);
#endif /* FSL_FEATURE_MCM_HAS_UBROMBAR_REGISTER */
        base->SRPOSP = MCM_SRPOSP_SRPOSP(psConfig->u32ResourceProtectionOtherSP);
        MCM_EnableResourceProtection(base, psConfig->bEnableResourceProtection);
        eStatus = kStatus_Success;
    }
    else
    {
        eStatus = kStatus_Fail;
    }

    return eStatus;
}
