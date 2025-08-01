/*
 * Copyright 2022-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_ECAT_H_
#define FSL_ECAT_H_

#include "fsl_common.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief eCAT driver version */
#define FSL_ECAT_DRIVER_VERSION (MAKE_VERSION(2, 0, 0)) /*!< Version 2.0.0. */
/*! @} */

/*! @brief Returns the first 16Bit of the AL Event register (0x220).*/
#define ECAT_GetALEventRegister(ecat)   (uint16_t)((ecat)->AL_EVENT_REQUEST)

/*! @brief Generic ESC (register and DPRAM) read access.*/
#define ECAT_EscRead(ecat, pData, Address, Len) \
    memcpy((uint8_t *)(pData), &((uint32_t *)(ecat))[(Address) >> 2], (Len))

/*! @brief 32Bit specific ESC (register and DPRAM) read access.*/
#define ECAT_EscReadDWord(ecat, DWordValue, Address) \
    ((DWordValue) = (uint32_t)(((uint32_t *)(ecat))[(Address >> 2)]))

/*! @brief Generic ESC (register and DPRAM) write access.*/
#define ECAT_EscWrite(ecat, pData, Address, Len) \
    memcpy(&((uint32_t *)(ecat))[(Address) >> 2], (uint8_t *)(pData), (Len))

/*! @brief 32Bit specific ESC (register and DPRAM) write access.*/
#define ECAT_EscWriteDWord(ecat, DWordValue, Address) \
    ((((uint32_t *)(ecat))[(Address >> 2)]) = (DWordValue))

/*!
 * @brief Read PHY register via ESC MII Management Interface.
 *
 * @param ecat base ECAT peripheral address.
 * @param phy_addr PHY address.
 * @param reg_addr Register address.
 * @param data PHY data returned.
 */

status_t ECAT_EscMdioRead(ECAT_Type *ecat, uint8_t phy_addr, uint8_t reg_addr, uint16_t *data);

/*!
 * @brief Write PHY register via ESC MII Management Interface.
 *
 * @param ecat base ECAT peripheral address.
 * @param phy_addr PHY address.
 * @param reg_addr Register address.
 * @param data Write to PHY register.
 */
status_t ECAT_EscMdioWrite(ECAT_Type *ecat, uint8_t phy_addr, uint8_t reg_addr, uint16_t data);

#endif /* FSL_ECAT_H_ */