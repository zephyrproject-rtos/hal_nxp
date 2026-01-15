/*
 * Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _BLE_CONTROLLER_LOWLEVEL_H_
#define _BLE_CONTROLLER_LOWLEVEL_H_

#include <stdint.h>
#include "ble_controller.h"

/************************************************************************************
*************************************************************************************
* Definitions
*************************************************************************************
************************************************************************************/
#define BLE_CONTROLLER_LL_ALIGN(x,alignment) ((((uint32_t)x + alignment - 1) & ~(uint32_t)(alignment - 1)))
#define BLE_CONTROLLER_LL_BLOCK_OFFSET 4
#define HCI_CMD_BUF_BLOCK_SIZE BLE_CONTROLLER_LL_ALIGN(MAX_HCI_CMD_PACKET_SIZE + BLE_CONTROLLER_LL_BLOCK_OFFSET, 4)

/* The maximum number of HCI commands that can be cached */
#define MAX_HCI_CMD_PACKET_SIZE 260
/* Define raw memory for the command buffers */
#define DEF_HCI_CMD_BUFFER_MEM(name, MAX_HCI_COMMANDS) \
static uint8_t name[HCI_CMD_BUF_BLOCK_SIZE * MAX_HCI_COMMANDS] __attribute__ ((aligned (4)));

/************************************************************************************
*************************************************************************************
* Structures/Data Types
*************************************************************************************
************************************************************************************/

/************************************************************************************
*************************************************************************************
* Public prototypes
*************************************************************************************
************************************************************************************/

/*! *********************************************************************************
 * \brief  Get power table index with the lowest maximum tx power supporting the
 *         tx_power_dbm given as a parameter
 * \param tx_power_dbm      : [in] Maximum power that the power table needs to support
 * \return power table index
 ********************************************************************************** */
uint8_t BLEController_getTableIdx(int8_t max_tx_power_dbm);

/*! *********************************************************************************
 * \brief  Get power range of the current tx power table
 * \param selected_power_range      : [out]  Power range of the selected table
 ********************************************************************************** */
void BLEController_getPowerRange(power_range_dbm_t *selected_power_range);

/*! *********************************************************************************
 * \brief  Allocate an HCI command buffer
 * \return Allocated buffer
 ********************************************************************************** */
void* BLEController_AllocCmdBuffer(void);

/*! *********************************************************************************
 * \brief  Low level initialization of the BLE Controller
 * \param hci_cmd_buffer_mem : [in]  Pointer to the managed raw memory containing the
 *                                   command buffers
 * \param hci_cmd_packet_size: [in]  Size of each of the command buffers
 * \param hci_cmd_buffer_mem : [in]  Number of command buffers
 * \return blec_result_t
 ********************************************************************************** */
blec_result_t BLEController_InitLowLevel(uint8_t *hci_cmd_buffer_mem, uint32_t hci_cmd_packet_size,
    uint32_t max_hci_cmds);

#endif /* _BLE_CONTROLLER_LOWLEVEL_H_ */
