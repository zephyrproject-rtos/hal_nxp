/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_xbic.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.xbic"
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
 * brief Enables individual XBIC master port error detection.
 *
 * This function enables individual XBIC master port error detection.
 *
 * param base XBIC peripheral base address.
 * param masterPort ID of XBIC master port.
 */
void XBIC_EnableMasterPortEDC(XBIC_Type *base, xbic_master_port_t masterPort)
{
    base->MCR |= (XBIC_MCR_ME0_MASK >> masterPort);
}

/*!
 * brief Enables individual XBIC slave port error detection.
 *
 * This function enables individual XBIC slave port error detection.
 *
 * param base XBIC peripheral base address.
 * param slavePort ID of XBIC slave port.
 */
void XBIC_EnableSlavePortEDC(XBIC_Type *base, xbic_slave_port_t slavePort)
{
    base->MCR |= (XBIC_MCR_SE0_MASK >> slavePort);
}

/*!
 * brief Disables individual XBIC master port error detection.
 *
 * This function disables individual XBIC master port error detection.
 *
 * param base XBIC peripheral base address.
 * param masterPort ID of XBIC master port.
 */
void XBIC_DisableMasterPortEDC(XBIC_Type *base, xbic_master_port_t masterPort)
{
    base->MCR &= ~(XBIC_MCR_ME0_MASK >> masterPort);
}

/*!
 * brief Disables individual XBIC slave port error detection.
 *
 * This function disables individual XBIC slave port error detection.
 *
 * param base XBIC peripheral base address.
 * param slavePort ID of XBIC slave port.
 */
void XBIC_DisableSlavePortEDC(XBIC_Type *base, xbic_slave_port_t slavePort)
{
    base->MCR &= ~(XBIC_MCR_SE0_MASK >> slavePort);
}

/*!
 * brief Sets error injection parameters config for selected XBIC master and slave port.
 *
 * This function sets error injection parameters for selected XBIC master and slave port.
 * 
 * param base XBIC peripheral base address.
 * param masterPort ID of XBIC master port.
 * param slavePort ID of XBIC slave port.
 * param syndromes value of XBIC error syndromes.
 */ 
void XBIC_ErrorInjectionConfig(XBIC_Type *base,
                               xbic_master_port_t masterPort,
                               xbic_slave_port_t slavePort,
                               xbic_error_syndromes_t syndromes)
{

    uint32_t tmpreg;

    tmpreg = base->EIR;
    tmpreg &= ~(XBIC_EIR_SLV_MASK| XBIC_EIR_MST_MASK | XBIC_EIR_SYN_MASK);
    tmpreg |= (XBIC_EIR_MST(masterPort) | XBIC_EIR_SLV(slavePort) | XBIC_EIR_SYN(syndromes));
    base->EIR = tmpreg;
}