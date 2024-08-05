/** @file mlan_action.h
 *
 *  @brief Interface for the mlan_action module implemented in mlan_action.c
 *
 *  Driver interface functions and type declarations for the process action frame
 *    module implemented in mlan_action.c.
 *
 *  Copyright 2022-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/********************************************************
Change log:
    08/11/2022: initial version
********************************************************/

#ifndef _MLAN_ACTION_H_
#define _MLAN_ACTION_H_

#include "mlan_fw.h"

/** process rx action frame */
mlan_status wlan_process_mgmt_action(t_u8 *payload, t_u32 payload_len, RxPD *rxpd);

#if CONFIG_1AS
/* frame body for timing measurement action frame */
typedef PACK_START struct _wifi_wnm_timing_msmt_t
{
    t_u8 action; /* 1 */
    t_u8 dialog_token;
    t_u8 follow_up_dialog_token;
    t_u32 tod;
    t_u32 toa;
    t_u8 max_tod_err;
    t_u8 max_toa_err;
} PACK_END wifi_wnm_timing_msmt_t;

void wlan_process_timing_measurement_frame(t_u8 *payload, t_u32 payload_len, RxPD *rxpd);
void wlan_send_timing_measurement_req_frame(mlan_private *pmpriv, t_u8 *ta, t_u8 trigger);
mlan_status wlan_send_timing_measurement_frame(mlan_private *pmpriv);
#endif
#endif /* !_MLAN_ACTION_H_ */
