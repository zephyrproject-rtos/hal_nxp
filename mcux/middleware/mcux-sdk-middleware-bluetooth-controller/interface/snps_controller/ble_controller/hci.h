// reuse-pragma startSub nMAC_ONLY    [IncludeIf @BLE_MAC_ROLE!=3 %subText]
/**
 ********************************************************************************
 * @file    hci.h
 * @brief   This file contains all the functions prototypes for the hci.h.
 ******************************************************************************
 * @copy
 *
 * Synopsys MIT License:
 * Copyright (c) 2020-Present Synopsys, Inc
 * Permission is hereby granted, free of charge, to any person obtaining a copy of the Software,
 * to deal in the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,INCLUDING,
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE ARISING FROM,
 * OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
 *
 * \n\n<b>References</b>\n
 * -Documents folder .
 *
 * <b>Edit History For File</b>\n
 *  This section contains comments describing changes made to this file.\n
 *  Notice that changes are listed in reverse chronological order.\n
 * <table border>
 * <tr>
 * </tr>
 * </table>\n
 */

/** @defgroup  hci_intf HCI Layer
 *  @ingroup BLE_STACK_API
 *  @brief Provide APIs to interface with HCI layer, like HCI layer initialization, allocation and free of HCI buffer header, process the received HCI command packet ...etc, HCI APIS are defined in hci.h header file.
 *  @{
 */
/* Define to prevnt recursive inclusion */
#ifndef INCLUDE_HCI_H
#define INCLUDE_HCI_H

/* Includes ---------------------------------------------------------------------*/

#include <stdint.h>
#include "bsp.h"
#include "ll_intf.h"

/* Exported  Enumerations -----------------------------------------------------*/

/**
 * @brief Enumeration holding the types of the returned commands in response
 * 		  to a received HCI command.
 */
typedef enum {
	HCI_RETURN_COMMAND_TYPE_COMPLETE,
	HCI_RETURN_COMMAND_TYPE_STATUS,
} hci_return_command_type;

/* Exported  Defines -----------------------------------------------------------*/

typedef void (*hci_trnsprt_cbk)(
	ble_buff_hdr_t *ptr_evnt_hdr);

typedef void (*ble_ext_cmd_processed_cb_t) (ble_buff_hdr_t *evnt_pckt_p);

/** @ingroup  ext_hci_cmds External HCI Commands
 * @{
 */
typedef ble_stat_t (*ble_ext_custm_cb_t) (uint16_t ocf, uint8_t *pckt_p, uint8_t *evnt_pckt_p, uint8_t* params_length, hci_return_command_type* return_command_type);
/**@}
 */

/* Exported functions ---------------------------------------------------------*/

/**
 * @brief Initialize the HCI layer and Registers a callback function to the upper layer
 *
 * @param p_trnsprt_cbk : [in] callback function
 *
 * @retval always returns SUCCESS
 */
ble_stat_t ll_hci_init(
	hci_trnsprt_cbk p_trnsprt_cbk);

/**
 * @brief  get a pointer to the HCI dispatch table.
 *
 * @param  p_p_dispatch_tbl : [out] pointer to be filled by the address of the HCI dispatch table.
 */
void hci_get_dis_tbl(
	const struct hci_dispatch_tbl** p_p_dispatch_tbl);

#if (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)
/**
 * @brief  Process the received ACL data packet from the host.
 *
 * @param  ptr_buff_hdr  : [in] Pointer to the HCI command packet.
 *
 * @retval ble_stat_t  : Command status to be sent to the Host.
 */
ble_stat_t hci_rcvd_acl_data_pckt_hndlr(
		ble_buff_hdr_t *ptr_buff_hdr);
#endif /* (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION) */

#if ((SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)) || (SUPPORT_BRD_ISOCHRONOUS))
/**
 * @brief  Process the received ISO data packet from the host.
 *
 * @param  ptr_buff_hdr  : [in] Pointer to the HCI command packet.
 *
 * @retval ble_stat_t  : Command status to be sent to the Host.
 */
ble_stat_t hci_rcvd_iso_data_pckt_hndlr(
		ble_buff_hdr_t *ptr_buff_hdr);
#endif /* ((SUPPORT_CONNECTED_ISOCHRONOUS && (SUPPORT_MASTER_CONNECTION || SUPPORT_SLAVE_CONNECTION)) || SUPPORT_BRD_ISOCHRONOUS) */


/**
 * @brief  Process the received HCI command packet from the host.
 *
 * @param  ptr_rcvd_pckt_strt   : [in] Pointer to the HCI command packet.
 * @param  rcvd_pckt_len   		: [in] Length of the HCI command packet.
 * @retval ble_stat_t : Command status to be sent to the Host.
 */
ble_stat_t hci_rcvd_cmd_pckt_hndlr(
	uint8_t *ptr_rcvd_pckt_strt,
	uint16_t rcvd_pckt_len);

/**
 * @brief  allocate a message structure to be sent to the HCI layer through event manager.
 *
 * @retval ble_buff_hdr_t* : pointer to the buffer header allocated.
 */
ble_buff_hdr_t* hci_alloc_msg(void);

/**
 * @brief  free an allocated message structure
 *
 * @param  ptr_hci_msg  : [in] Pointer to the message to be freed.
 */
void hci_free_msg(
		ble_buff_hdr_t *ptr_hci_msg);
/**
 * @}
 */

/** @ingroup  ext_hci_cmds External HCI Commands
 * @{
 */

/**
 * @brief Registers a callback function to be called whenever a command has been
 *        processed. It can be used to free resources that were allocated for the
 *        command
 *
 * @param cmd_processed_cbk :[IN] Pointer to the callback function. NULL to
 *                                unregister callback
 */
void hci_rgstr_cmd_processed_cbk(ble_ext_cmd_processed_cb_t cmd_processed_cbk);

/**
 * @brief Registers a custom callback function to be called when the
 * 		  hci_cstm_pckt_hndlr() cannot resolve the OCF.
 *
 * @param ext_custm_cbk :[IN] Pointer to the callback function.
 *
 * @retval False if the cbk is null, True otherwise.
 */
uint8_t hci_rgstr_ble_external_custom_cbk(ble_ext_custm_cb_t ext_custm_cbk);
/**@}
 */


#endif /* INCLUDE_HCI_H */

/******************* (C) COPYRIGHT 2025 SYNOPSYS, INC. *****END OF FILE****/

// reuse-pragma endSub nMAC_ONLY

