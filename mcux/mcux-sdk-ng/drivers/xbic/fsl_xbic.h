/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_XBIC_H_
#define FSL_XBIC_H_

#include "fsl_common.h"

/*!
 * @addtogroup xbic
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief XBIC driver version 2.0.1. */
#define FSL_XBIC_DRIVER_VERSION (MAKE_VERSION(2, 0, 1))
/*! @} */
 
/*! @brief _xbic_error_syndromes XBIC error syndromes. */
typedef enum _xbic_error_syndromes
{
    kXBIC_SynHwrite = 0x7U,      /*!< hwrite signal. */
    kXBIC_SynHtrans0 = 0x0BU,    /*!< htrans[0] signal */
    kXBIC_SynHsize2 = 0x0DU,     /*!< hsize[2] signal */
    kXBIC_SynHsize1 = 0x0EU,     /*!< hsize[1] signal */
    kXBIC_SynHsize0 = 0x13U,     /*!< hsize[0] signal */
    kXBIC_SynHprot5 = 0x15U,     /*!< hprot[5] signal */
    kXBIC_SynHprot4 = 0x16U,     /*!< hprot[4] signal */
    kXBIC_SynHprot3 = 0x19U,     /*!< hprot[3] signal */
    kXBIC_SynHprot2 = 0x1AU,     /*!< hprot[2] signal */
    kXBIC_SynHprot1 = 0x1CU,     /*!< hprot[1] signal */
    kXBIC_SynHprot0 = 0x91U,     /*!< hprot[0] signal */
    kXBIC_SynHburst2 = 0xA1U,    /*!< hburst[2] signal */
    kXBIC_SynHburst1 = 0x64U,    /*!< hburst[1] signal */
    kXBIC_SynHburst0 = 0x29U,    /*!< hburst[0] signal */
    kXBIC_SynHmastlock = 0x2AU,  /*!< hmastlock signal */
    kXBIC_SynHunalign = 0x2CU,   /*!< hunalign signal */
    kXBIC_SynEdc7 = 0x80U,       /*!< edc[7] signal */
    kXBIC_SynEdc6 = 0x40U,       /*!< edc[6] signal */
    kXBIC_SynEdc5 = 0x20U,       /*!< edc[5] signal */
    kXBIC_SynEdc4 = 0x10U,       /*!< edc[4] signal */
    kXBIC_SynEdc3 = 0x08U,       /*!< edc[3] signal */
    kXBIC_SynEdc2 = 0x04U,       /*!< edc[2] signal */
    kXBIC_SynEdc1 = 0x02U,       /*!< edc[1] signal */
    kXBIC_SynEdc0 = 0x01U,       /*!< edc[0] signal */
    kXBIC_SynHbstrb7 = 0x70U,    /*!< hbstrb[7] signal */
    kXBIC_SynHbstrb6 = 0x32U,    /*!< hbstrb[6] signal */
    kXBIC_SynHbstrb5 = 0x52U,    /*!< hbstrb[5] signal */
    kXBIC_SynHbstrb4 = 0xA8U,    /*!< hbstrb[4] signal */
    kXBIC_SynHbstrb3 = 0x43U,    /*!< hbstrb[3] signal */
    kXBIC_SynHbstrb2 = 0x45U,    /*!< hbstrb[2] signal */
    kXBIC_SynHbstrb1 = 0x4CU,    /*!< hbstrb[1] signal */
    kXBIC_SynHbstrb0 = 0xA4U,     /*!< hbstrb[0] signal */
    kXBIC_SynHmaster3 = 0xA2U,   /*!< hmaster[3] signal */
    kXBIC_SynHmaster2 = 0xB0U,   /*!< hmaster[2] signal */
    kXBIC_SynHmaster1 = 0xC1U,   /*!< hmaster[1] signal */
    kXBIC_SynHmaster0 = 0xC2U,   /*!< hmaster[0] signal */
    kXBIC_SynHslave2 = 0xC4U,    /*!< hslave[2] signal */
    kXBIC_SynHslave1 = 0xCBU,    /*!< hslave[1] signal */
    kXBIC_SynHslave0 = 0xD0U,    /*!< hslave[0] signal */
    kXBIC_SynHdecorated = 0xE0U, /*!< hdecorated signal */
    kXBIC_SynHdecor31 = 0x25U,   /*!< hdecor[31] signal */
    kXBIC_SynHdecor30 = 0x68U,   /*!< hdecor[30] signal */
    kXBIC_SynHdecor29 = 0xC7U,   /*!< hdecor[29] signal */
    kXBIC_SynHdecor28 = 0x83U,   /*!< hdecor[28] signal */
    kXBIC_SynHdecor27 = 0x85U,   /*!< hdecor[27] signal */
    kXBIC_SynHdecor26 = 0x86U,   /*!< hdecor[26] signal */
    kXBIC_SynHdecor25 = 0x89U,   /*!< hdecor[25] signal */
    kXBIC_SynHdecor24 = 0x8AU,   /*!< hdecor[24] signal */
    kXBIC_SynHdecor23 = 0x8CU,   /*!< hdecor[23] signal */
    kXBIC_SynHdecor22 = 0x49U,   /*!< hdecor[22] signal */
    kXBIC_SynHdecor21 = 0x92U,   /*!< hdecor[21] signal */
    kXBIC_SynHdecor20 = 0x94U,   /*!< hdecor[20] signal */
    kXBIC_SynHdecor19 = 0x98U,   /*!< hdecor[19] signal */
    kXBIC_SynHdecor18 = 0x46U,   /*!< hdecor[18] signal */
    kXBIC_SynHdecor17 = 0x34U,   /*!< hdecor[17] signal */
    kXBIC_SynHdecor16 = 0x48U,   /*!< hdecor[16] signal */
    kXBIC_SynHdecor15 = 0x23U,   /*!< hdecor[15] signal */
    kXBIC_SynHdecor14 = 0x51U,   /*!< hdecor[14] signal */
    kXBIC_SynHdecor13 = 0x54U,   /*!< hdecor[13] signal */
    kXBIC_SynHdecor12 = 0x61U,   /*!< hdecor[12] signal */
    kXBIC_SynHdecor11 = 0xE3U,   /*!< hdecor[11] signal */
    kXBIC_SynHdecor10 = 0xE6U,   /*!< hdecor[10] signal */
    kXBIC_SynHdecor9 = 0xF8U,    /*!< hdecor[9] signal */
    kXBIC_SynHdecor8 = 0x38U,    /*!< hdecor[8] signal */
    kXBIC_SynHdecor7 = 0x58U,    /*!< hdecor[7] signal */
    kXBIC_SynHdecor6 = 0x37U,    /*!< hdecor[6] signal */
    kXBIC_SynHdecor5 = 0xF1U,    /*!< hdecor[5] signal */
    kXBIC_SynHdecor4 = 0x3BU,    /*!< hdecor[4] signal */
    kXBIC_SynHdecor3 = 0x3DU,    /*!< hdecor[3] signal */
    kXBIC_SynHdecor2 = 0x3EU,    /*!< hdecor[2] signal */
    kXBIC_SynHdecor1 = 0x4FU,    /*!< hdecor[1] signal */
    kXBIC_SynHdecor0 = 0x6EU,    /*!< hdecor[0] signal */
} xbic_error_syndromes_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name XBIC Initialization and de-initialization
 * @{
 */

/*!
 * @brief Enables individual XBIC master port error detection.
 *
 * This function enables individual XBIC master port error detection.
 *
 * @param base XBIC peripheral base address.
 * @param masterPort ID of XBIC master port.
 */
void XBIC_EnableMasterPortEDC(XBIC_Type *base, xbic_master_port_t masterPort);

/*!
 * @brief Enables individual XBIC slave port error detection.
 *
 * This function enables individual XBIC slave port error detection.
 *
 * @param base XBIC peripheral base address.
 * @param slavePort ID of XBIC slave port.
 */
void XBIC_EnableSlavePortEDC(XBIC_Type *base, xbic_slave_port_t slavePort);

/*!
 * @brief Disables individual XBIC master port error detection.
 *
 * This function disables individual XBIC master port error detection.
 *
 * @param base XBIC peripheral base address.
 * @param masterPort ID of XBIC master port.
 */
void XBIC_DisableMasterPortEDC(XBIC_Type *base, xbic_master_port_t masterPort);

/*!
 * @brief Disables individual XBIC slave port error detection.
 *
 * This function disables individual XBIC slave port error detection.
 *
 * @param base XBIC peripheral base address.
 * @param slavePort ID of XBIC slave port.
 */
void XBIC_DisableSlavePortEDC(XBIC_Type *base, xbic_slave_port_t slavePort);

/*!
 * @brief Sets error injection parameters config for selected XBIC master and slave port.
 *
 * This function sets error injection parameters for selected XBIC master and slave port.
 * 
 * @param base XBIC peripheral base address.
 * @param masterPort ID of XBIC master port.
 * @param slavePort ID of XBIC slave port.
 * @param syndromes value of XBIC error syndromes.
 */ 
void XBIC_ErrorInjectionConfig(XBIC_Type *base,
                               xbic_master_port_t masterPort,
                               xbic_slave_port_t slavePort,
                               xbic_error_syndromes_t syndromes);

/*!
 * @brief Enable XBIC error injection
 *
 * This function enables or disable XBIC error injection. 
 * This API should be called after calling XBIC_ErrorInjectionConfig.
 * 
 * @param base XBIC peripheral base address.
 * @param enable Switcher of XBIC error injection feature. "true" means to enable, "false" means not.
 */ 
static inline void XBIC_EnableErrorInjection(XBIC_Type *base, bool enable)
{
    if(enable)
    {
        base->EIR |= XBIC_EIR_EIE_MASK;
    }
    else
    {
        base->EIR &= ~XBIC_EIR_EIE_MASK;
    }
    __DSB();
}

/*!
 * @brief Get XBIC error status valid flag.
 * This function gets XBIC error status valid flag.
 *
 * @param base XBIC peripheral base address.
 * @return error valid status. (0-no error detected, 1-error detected)
 */
static inline uint32_t XBIC_GetErrorValidFlag(XBIC_Type *base)
{
    return ((base->ESR & XBIC_ESR_VLD_MASK) == 0U ? 0U : 1U);
}

/*!
 * @brief Get selected master port feedback integrity error status.
 *
 * @param base XBIC peripheral base address.
 * @param slavePort ID of XBIC slave port.
 * @return Slave port error status (0-no error detected, 1-error detected)
 */
static inline uint32_t  XBIC_GetDpseFlag(XBIC_Type *base, xbic_slave_port_t slavePort)
{
    return ((base->ESR & (XBIC_ESR_DPSE0_MASK >> slavePort)) == 0U ? 0U : 1U);
}

/*!
 * @brief Returns selected slave port feedback integrity error status.
 *
 * @param base XBIC peripheral base address.
 * @param masterPort ID of XBIC master port.
 * @return Master port error status (0-no error detected, 1-error detected)
 */
static inline uint32_t  XBIC_GetDpmeFlag(XBIC_Type *base, xbic_master_port_t masterPort)
{
    return ((base->ESR & (XBIC_ESR_DPME0_MASK >> masterPort)) == 0U ? 0U : 1U);
}

/*!
 * @brief Get ID of a slave port targeted by the most recent transfer.
 *
 * @param base XBIC peripheral base address.
 * @return Slave port error status mask @ref xbic_slave_port_t.
 */
static inline uint32_t  XBIC_GetErrorSlavePorts(XBIC_Type *base)
{
    return ((base->ESR & XBIC_ESR_SLV_MASK) >> XBIC_ESR_SLV_SHIFT);
}

/*!
 * @brief Get ID of a master port that requested the most recent transfer
 *
 * @param base XBIC peripheral base address.
 * @return Master port error status mask @ref xbic_master_port_t.
 */
static inline uint32_t  XBIC_GetErrorMasterPorts(XBIC_Type *base)
{
    return ((base->ESR & XBIC_ESR_MST_MASK) >> XBIC_ESR_MST_SHIFT);
}

/*!
 * @brief Get the syndrome calculated for the most recent transfer.
 *
 * @param base XBIC peripheral base address.
 * @return Syndrome value.
 */
static inline uint32_t  XBIC_GetErrorSyndrome(XBIC_Type *base)
{
    return ((base->ESR & XBIC_ESR_SYN_MASK) >> XBIC_ESR_SYN_SHIFT);
}

/*!
 * @brief Get the address of the most recent transfer with 
          an attribute integrity check error detected.
 *
 * @param base XBIC peripheral base address.
 * @return Error address value.
 */
static inline uint32_t  XBIC_GetErrorAddress(XBIC_Type *base)
{
    return base->EAR;
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* FSL_XBIC_H_ */
