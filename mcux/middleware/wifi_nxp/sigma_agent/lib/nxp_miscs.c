/** @file nxp_miscs.c
 *
 * @brief This file contains WLAN  specific defines etc.
 *
 * Copyright 2008-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#include "nxp_wifi.h"

#if CONFIG_SIGMA_AGENT

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>

#include "wfa_portall.h"
#include "wfa_debug.h"
#include "wfa_ver.h"
#include "wfa_main.h"
#include "wfa_types.h"
#include "wfa_ca.h"
#include "wfa_tlv.h"
#include "wfa_sock.h"
#include "wfa_tg.h"
#include "wfa_cmds.h"
#include "wfa_rsp.h"
#include "wfa_utils.h"
#include "nxp_gvars.h"

int configure_11n_settings(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    DPRINT_INFO(WFA_OUT, "\nInside configure 11n settings, stasetwireless...\n");
    return TRUE;
}

/* Divesh: Actual HE Parameter Handling based on the flags parsed/received from UCC */
/* The flag pasring was done in cmdproc and this function handles the param setting */

int configure_he_settings(int len, BYTE *caCmdBuf, int *respLen, BYTE *respBuf)
{
    dutCmdResponse_t *heParamsResp     = &gGenericResp;
    caStaSetWireless_t *staSetWireless = (caStaSetWireless_t *)caCmdBuf;
    struct setWirelessHE *heParams     = (struct setWirelessHE *)&staSetWireless->progs.he;
    //    char tmpStr[100], txsp_stream[10] = {0}, rxsp_stream[10] = {0};
    //    int follow_vhtcfg = 0xff;
    //    int htcap_changed = 0, vhtcap_changed = 0, httxcfg_changed = 0;
    //    unsigned int htcapinfo = 0; /* Default value of htcapinfo */
    //    unsigned int httxcfg = 0;
    //    unsigned int vhtcapinfo = 0;
    //    int st = 0; // temp set to success for testing purpose.
    //    int is_testbed = 1;

    if (heParams->he_smps_flag == 1)
    {
        DPRINT_INFO(WFA_OUT, "Ashok:Enable SMPS");
    }
    if (heParams->width_flag)
    {
        DPRINT_INFO(WFA_OUT, "Ashok: Change Bandwidthidth");
    }
    if ((heParams->OMControl_flag || heParams->UPH_flag) &&
        (heParams->OMControl == WFA_ENABLED || heParams->UPH == WFA_ENABLED))
    {
        DPRINT_INFO(WFA_OUT, "Ashok: OM-Control and UPH field settings logic if required");
    }
    if (heParams->ADDBAReq_BufSize_flag)
    {
        if (!strcasecmp(heParams->ADDBAReq_BufSize, "gt64"))
            DPRINT_INFO(WFA_OUT, "Ashok: ENABLE SUPER BA-TX ");
    }

    if (heParams->ADDBAResp_BufSize_flag)
    {
        if (!strcasecmp(heParams->ADDBAResp_BufSize, "gt64"))
            DPRINT_INFO(WFA_OUT, "Divesh:ENABLE SUPER BA-RX ");
    }

    if (heParams->mcs_fixedrate_flag)
    {
        if (!strcasecmp(heParams->mcs_fixedrate, "7"))
        {
            DPRINT_INFO(WFA_OUT, "Ashok:MCS fixed rate Loop..");
            if (heParams->ldpc_flag)
            {
                DPRINT_INFO(WFA_OUT, "Ashok: ENABLE Fixed MCS RATE 7 With LDPC ");
            }
            if (heParams->bcc_flag)
            {
                DPRINT_INFO(WFA_OUT, "Ashok:ENABLE Fixed MCS RATE 7 With BCC ");
            }
        }
    }

    if (heParams->amsdu_flag)
    {
        if (heParams->amsdu == WFA_ENABLED)
        {
            DPRINT_INFO(WFA_OUT, "Ashok:ENABLE AMSDU ");
        }
    }

    if (heParams->ldpc_flag)
    {
        if (heParams->ldpc == WFA_ENABLED)
        {
            DPRINT_INFO(WFA_OUT, "Ashok:ENABLE LDPC ");
        }
    }
    if (heParams->bcc_flag)
    {
        if (heParams->bcc == WFA_ENABLED)
        {
            DPRINT_INFO(WFA_OUT, "Ashok:ENABLE BCC ");
        }
    }

    if ((heParams->txsp_stream_flag) || (heParams->rxsp_stream_flag))
    {
        if ((!strcasecmp(heParams->txsp_stream, "1SS")) || (!strcasecmp(heParams->rxsp_stream, "1SS")))
        {
            DPRINT_INFO(WFA_OUT, "Ashok:SET TX-NSS =1 and RX-NSS=1");
        }
        else if ((!strcasecmp(heParams->txsp_stream, "2SS")) || (!strcasecmp(heParams->rxsp_stream, "2SS")))
        {
            DPRINT_INFO(WFA_OUT, "Ashok:SET TX-NSS =2 and RX-NSS=2");
        }
    }

    heParamsResp->status = STATUS_COMPLETE;
    wfaEncodeTLV(WFA_STA_SET_WIRELESS_RESP_TLV, 4, (BYTE *)heParamsResp, respBuf);
    *respLen = WFA_TLV_HDR_LEN + 4;
    return WFA_SUCCESS;
}
#endif
