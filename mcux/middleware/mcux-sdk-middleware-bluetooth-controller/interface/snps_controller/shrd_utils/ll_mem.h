/**
 ********************************************************************************
 * @file    ll_mem.h.h
 * @brief   This file contains definitions for pool type used by the LL memory manager.
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
 * </tr>
 * </table>\n
 */

#ifndef INCLUDE_LL_MEM_H
#define INCLUDE_LL_MEM_H

#include "os_wrapper.h"

#ifndef USE_OS_MALLOC
os_Pool_Def_extern(queue_handle_t);
os_Pool_Def_extern(sw_timer_t);
os_Pool_Def_extern(pkt_buff_hdr_t);
os_Pool_Def_extern(hci_buffer_t);
void ll_mem_init(void);
#endif

void ll_mem_shared_init(void);
void ll_mem_shared_check(void);
uint32_t ble_get_hci_transport_evnt_count(void);

#endif
