/**
 ********************************************************************************
 * @file    hci_transport.h
 * @brief   This component for interfacing the hci with bus interface .
 ******************************************************************************
 * @copy
 *
 * Synopsys MIT License:
 * 
 * Copyright (c) 2020-Present Synopsys, Inc
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * the Software, to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 * 
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 *  
 * 
 * THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING, BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE ARISING FROM,
 * OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 * \n\n<b>References</b>\n
 * -Documents folder .
 *
 * <b>Edit History For File</b>\n
 *  This section contains comments describing changes made to this file.\n
 *  Notice that changes are listed in reverse chronological order.\n
 * <table border>
 * <tr>
 *   <td><b> when </b></td>
 *   <td><b> who </b></td>
 *   <td><b> what, where, why </b></td>
 * </tr>
 * <tr>
 *   <td>  Create the file</td>
 * </tr>
 * </table>\n
 */

#ifndef SRC_HCI_TRANSPORT_H_
#define SRC_HCI_TRANSPORT_H_

#include <stdint.h>
#include "common_types.h"

void hci_transport_init(void);
int hci_transport_initialized();
void hci_transport_deinit();
void hci_transport_reset(void);
void hci_transport_send_pckt(ble_buff_hdr_t *ptr_evnt_hdr);
void hci_transport_controller_ready(void);

#endif /* SRC_HCI_TRANSPORT_H_ */
/**
 * @}
 */
/******************* (C) COPYRIGHT 2025 SYNOPSYS, INC. *****END OF FILE****/

