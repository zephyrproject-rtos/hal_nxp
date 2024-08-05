/****************************************************************************
 Copyright (c) 2015 Wi-Fi Alliance
Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.
THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER
RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE
USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * wfa_cmds.h:
 *   definitions of command types.
 */
#ifndef _WFA_CMDS_H
#define _WFA_CMDS_H

typedef struct _tg_ping_start
{
    char dipaddr[WFA_IP_V6_ADDR_STR_LEN]; /* destination/remote ip address ,maybe ipv4 or ipv6*/
    int frameSize;
    int frameRate;
    int duration;
    int type;
    int iptype;
    int qos;
    int dscp;
} tgPingStart_t;

typedef struct ca_sta_set_ip_config
{
    char intf[WFA_IF_NAME_LEN];
    int isDhcp;
    int type;
    int ipv6mask;
    char ipaddr[WFA_IP_ADDR_STR_LEN];
    char ipv6addr[WFA_IP_V6_ADDR_STR_LEN];
    char mask[WFA_IP_MASK_STR_LEN];
    char defGateway[WFA_IP_ADDR_STR_LEN];
    char pri_dns[WFA_IP_ADDR_STR_LEN];
    char sec_dns[WFA_IP_ADDR_STR_LEN];
} caStaSetIpConfig_t;

typedef struct ca_sta_verify_ip_connection
{
    char dipaddr[WFA_IP_ADDR_STR_LEN];
    int timeout;
} caStaVerifyIpConnect_t;

typedef struct ca_sta_set_encryption
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    int encpType;
    char keys[4][32]; /* 26 hex */
    int activeKeyIdx;
} caStaSetEncryption_t;

typedef enum wfa_enableType
{
    eEnable = 1,
    eDisable
} wfaEnableType;

typedef enum wfa_ChanSwitchMode
{
    eChanEnable = 1,
    eChanDisable,
    eRejectReq,
    eUnSolResp,
} wfaChanSwitchMode;

typedef struct ca_sta_set_mode
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char mode;
    int encpType;
    int channel;
    char keys[4][32]; /* 26 hex */
    int activeKeyIdx;
} caStaSetMode_t;

typedef struct ca_sta_set_psk
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    BYTE passphrase[64];
    char keyMgmtType[16];
    char encrptype[16];
    int pmf;    /* PMF enable or disable */
    int micAlg; /* MIC Algorithm */
    int prefer;
} caStaSetPSK_t;

typedef struct ca_sta_set_eaptls
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char keyMgmtType[16];
    char encrptype[16];
    char trustedRootCA[128];
    char clientCertificate[128];
    char clientCertificatekey[128];
    int pmf; /* PMF enable or disable */
    int username_flag;
} caStaSetEapTLS_t;

typedef struct ca_sta_set_eapttls
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char passwd[128];
    char keyMgmtType[16];
    char encrptype[16];
    char trustedRootCA[32];
    char clientCertificate[32];
    int pmf; /* PMF enable or disable */
    int prefer;
    int akmsuitetype;
    int pmksacaching;

    char tls_cipher[50];
    int tls_cipher_flag;

    char client_cert[30];
    char server_cert[30];

    char cert_type[30];
    char pairwise_cipher[40];
    char group_cipher[40];
    char group_mgmt_cipher[40];
} caStaSetEapTTLS_t;

typedef struct ca_sta_set_eapsim
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char passwd[128];
    char keyMgmtType[16];
    char encrptype[16];
    int pmf; /* PMF enable or disable */
} caStaSetEapSIM_t;

typedef struct ca_sta_set_eappeap
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char passwd[128];
    char keyMgmtType[16];
    char encrptype[16];
    char trustedRootCA[32];
    char innerEAP[16];
    int peapVersion;
    int pmf; /* PMF enable or disable */
} caStaSetEapPEAP_t;

typedef struct ca_sta_set_eapfast
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char passwd[128];
    char keyMgmtType[16];
    char encrptype[16];
    char trustedRootCA[32];
    char innerEAP[16];
    char validateServer;
    char pacFileName[32];
    int pmf; /* PMF enable or disable */
} caStaSetEapFAST_t;

typedef struct ca_sta_set_eapaka
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    char username[128];
    char passwd[128];
    char keyMgmtType[16];
    char encrptype[16];
    int pmf; /* PMF enable or disable */
} caStaSetEapAKA_t;

enum sectype
{
    SEC_TYPE_PSK = 1,
    SEC_TYPE_SAE,
    SEC_TYPE_SAE_PSK,
    SEC_TYPE_OWE,
    SEC_TYPE_OPEN,
    SEC_TYPE_EAPTLS,
    SEC_TYPE_EAPTTLS,
    SEC_TYPE_EAPPEAP,
    SEC_TYPE_EAPSIM,
    SEC_TYPE_EAPFAST,
    SEC_TYPE_EAPAKA,
};

typedef struct ca_sta_set_security
{
    BYTE type; /* PSK, EAPx */
    char ssid[WFA_SSID_NAME_LEN];
    char keyMgmtType[16];
    char encpType[16];
    int pmf;
    BYTE pmf_flag;
    int groups_flag;
    char groups[20];
    int sae_invalid_element_flag;
    char sae_invalid_element[500];
    int SAE_FLAG;
    union _security
    {
        char passphrase[64]; /* PSK */
        caStaSetEapTLS_t tls;
        caStaSetEapTTLS_t ttls;
        caStaSetEapSIM_t sim;
        caStaSetEapPEAP_t peap;
        caStaSetEapAKA_t aka;
        caStaSetEapFAST_t fast;
    } secu;
} caStaSetSecurity_t;

typedef struct ca_sta_set_systime
{
    BYTE month;
    BYTE date;
    WORD year;
    BYTE hours;
    BYTE minutes;
    BYTE seconds;
} caStaSetSystime_t;

enum
{
    PMF_TYPE_DISASSOC = 1,
    PMF_TYPE_DEAUTH,
    PMF_TYPE_SAQUERY,
    PMF_TYPE_AUTH,
    PMF_TYPE_ASSOCREQ,
    PMF_TYPE_REASSOCREQ,
};

enum
{
    PMF_PROT_CORRECTKEY = 1,
    PMF_PROT_INCORRECTKEY,
    PMF_PROT_UNPROTECTED,
};

typedef struct pmf_frame
{
    BYTE eFrameName;
    BYTE eProtected;
    char staid[WFA_MAC_ADDR_STR_LEN]; /* sta mac addr */

    unsigned char sender_flag;
    char sender[8]; /* ap or sta */

    unsigned char bssid_flag;
    char bssid[WFA_MAC_ADDR_STR_LEN]; /* ap mac addr */

} pmfFrame_t;

enum
{
    TDLS_TYPE_DISCOVERY = 1,
    TDLS_TYPE_SETUP,
    TDLS_TYPE_TEARDOWN,
    TDLS_TYPE_CHANNELSWITCH,
    TDLS_TYPE_NULLFRAME,
};

typedef struct tdls_frame
{
    BYTE eFrameName;
    char peer[WFA_MAC_ADDR_STR_LEN];

    unsigned char timeout_flag;
    int timeout;
    unsigned char switchtime_flag;
    int switchtime;
    unsigned char channel_flag;
    int channel;
    unsigned char offset_flag;
    char offset[4]; /* 20 or 40 Mhz */
    unsigned char status_flag;
    int status; /* status code */
    unsigned char reason_flag;
    int reason; /* reason code */
    unsigned char bssid_flag;
    char bssid[WFA_MAC_ADDR_STR_LEN];
} tdlsFrame_t;

enum
{
    VENT_TYPE_NEIGREQ = 1,
    VENT_TYPE_TRANSMGMT,
};

typedef struct vent_frame
{
    BYTE type;
    char ssid[WFA_SSID_NAME_LEN];
} ventFrame_t;

enum
{
    WFD_FRAME_PRBREQ = 1,
    WFD_FRAME_RTSP,
    WFD_FRAME_SERVDISC_REQ,
    WFD_FRAME_PRBREQ_TDLS_REQ,
    WFD_FRAME_11V_TIMING_MSR_REQ,
};

enum
{
    WFD_DEV_TYPE_SOURCE = 1,
    WFD_DEV_TYPE_PSINK,
    WFD_DEV_TYPE_SSINK,

};

enum
{
    WFD_RTSP_PAUSE = 1,
    WFD_RTSP_PLAY,
    WFD_RTSP_TEARDOWN,
    WFD_RTSP_TRIG_PAUSE,
    WFD_RTSP_TRIG_PLAY,
    WFD_RTSP_TRIG_TEARDOWN,
    WFD_RTSP_SET_PARAMETER,

};

enum setParamsTypes
{
    WFD_CAP_UIBC_KEYBOARD = 1,
    WFD_CAP_UIBC_MOUSE    = 1,
    WFD_CAP_RE_NEGO,
    WFD_STANDBY,
    WFD_UIBC_SETTINGS_ENABLE,
    WFD_UIBC_SETTINGS_DISABLE,
    WFD_ROUTE_AUDIO,
    WFD_3D_VIDEOPARAM,
    WFD_2D_VIDEOPARAM,
};

typedef struct wfd_frame
{
    BYTE eframe;
    char sa[WFA_MAC_ADDR_STR_LEN];
    char da[WFA_MAC_ADDR_STR_LEN];
    unsigned char devtype_flag;
    BYTE eDevType;
    unsigned char rtspmsg_flag;
    BYTE eRtspMsgType;
    unsigned char wfdsessionid_flag;
    char wfdSessionID[WFA_WFD_SESSION_ID_LEN];
    unsigned char setparm_flag;
    int eSetParams;
    unsigned char audioDest_flag;
    int eAudioDest;
    unsigned char bssid_flag;
    char bssid[WFA_MAC_ADDR_STR_LEN];
    unsigned char msrReqAction_flag;
    int eMsrAction;
    unsigned char capReNego_flag;
    int ecapReNego;

} wfdFrame_t;

typedef struct _opt_md_notif
{
    int channel_width;
    int nss;
} opt_md_notif;

typedef struct vht5g_frame
{
    char frameName[32];
    char destMAC[WFA_MAC_ADDR_STR_LEN];
    union _para
    {
        opt_md_notif opt_md;
    } para;
} vht5gFrame_t;

typedef struct HS2Frame_t
{
    // char intf[WFA_IF_NAME_LEN];
    char dest[WFA_MAC_ADDR_STR_LEN];
    char srcmac[WFA_MAC_ADDR_STR_LEN];
    char framename[WFA_FRAME_NAME_LEN];
    BYTE DLSrequest;
    BYTE anqpCapList;
    BYTE g3ppinfo;
    BYTE nairealmlist;
    BYTE domainlist;
    BYTE hscaplist;
    BYTE opername;
    BYTE wanmat;
    BYTE venuename;
    BYTE naihomerealmlist;
    BYTE opclass;
    BYTE arpProbe;
    BYTE arpAnnounce;
    BYTE neighSolicitReq;
    BYTE netAuthType;
    BYTE osuProviderlist;
    BYTE iconRequestList;
    char iconRequest[50];

    BYTE clearARP;
    BYTE ARPREPLY;
    char sendermac[WFA_MAC_ADDR_STR_LEN];
    char destip[50];
    char srcip[50];
} HS2_Frame_t;

typedef struct MBOFrame_t
{
    // char intf[WFA_IF_NAME_LEN];
    char dest[WFA_MAC_ADDR_STR_LEN];
    char srcmac[WFA_MAC_ADDR_STR_LEN];
    char framename[WFA_FRAME_NAME_LEN];
    BYTE BTMQuery;
    BYTE BTMReq;
    BYTE WNM_Notify;
    BYTE ANQPQuery;
    BYTE BcnRptReq;
    BYTE NeighborReportReq;
    BYTE QueryListWithCellPref;
    BYTE CellularCapabilities;
    BYTE NonPrefChanReport;

    /** PF2 */
    BYTE APChanRpt_flag;
    int APChanRpt;

    BYTE BTMQuery_Reason_Code_flag;
    int BTMQuery_Reason_Code;
    BYTE Disassoc_Timer_flag;
    int Disassoc_Timer;

    BYTE Cand_List_flag;
    int cand_list;

    BYTE Channel_flag;
    int Channel;

    BYTE MeaDur_flag;
    int MeaDur;

    BYTE MeaDurMand_flag;
    int MeaDurMand;

    BYTE MeaMode_flag;
    char MeaMode[32];

    BYTE Name_flag;
    char Name[64];

    BYTE RandInt_flag;
    char RandInt[16];

    BYTE RegClass_flag;
    int RegClass;

    BYTE ReqInfo_flag;
    char ReqInfo[128];

    BYTE RptCond_flag;
    int RptCond;

    BYTE RptDet_flag;
    int RptDet;

    BYTE SSID_flag;
    char SSID[32];

    BYTE ANQPQuery_ID_flag;
    char ANQPQuery_ID[32];
    BYTE WNM_Notify_Element_flag;
    char WNM_Notify_Element[32];

    BYTE Request_Mode_flag;
    int Request_Mode;

    char Anqp_Query_id;
} MBO_Frame_t;

enum _program_type_
{
    PROG_TYPE_GEN = 1,
    PROG_TYPE_PMF,
    PROG_TYPE_TDLS,
    PROG_TYPE_VENT,
    PROG_TYPE_WFD,
    PROG_TYPE_11N,
    PROG_TYPE_VHT5G,
    PROG_TYPE_HE,
    PROG_TYPE_HS2,
    PROG_TYPE_MBO,
    PROG_TYPE_WPA3,
};

typedef struct ca_sta_dev_sendframe
{
    BYTE program;
    union _frametype
    {
        pmfFrame_t pmf;
        tdlsFrame_t tdls;
        ventFrame_t vent;
        wfdFrame_t wfd;
        vht5gFrame_t vht5g;
        HS2_Frame_t hs2;
        MBO_Frame_t mbo;
    } frameType;
} caStaDevSendFrame_t;

typedef struct ca_sta_exec_action
{
    char intf[WFA_IF_NAME_LEN];
    char destmac[WFA_MAC_ADDR_STR_LEN];
    char trigger[16];
    int BurstsExponent;
    int asap;
    int FormatBwFTM;
    int askForLocCivic;
    int askForLCI;

} caStaExecAction_t;

typedef struct caDevExecAction
{
    char name[16];
    char intf[WFA_IF_NAME_LEN];
    char prog[8];
    int keyrotation;
    char ServerCertTrust[10];
} caDevExecAction_t;

typedef struct ca_sta_start_wfd_conn
{
    char intf[WFA_IF_NAME_LEN];
    BYTE peer_count;
    char peer[2][WFA_P2P_DEVID_LEN];
    unsigned char init_wfd_flag;
    BYTE init_wfd;
    unsigned char intent_val_flag;
    BYTE intent_val;
    unsigned char oper_chn_flag;
    WORD oper_chn;
    unsigned char coupledSession_flag;
    WORD coupledSession;
} caStaStartWfdConn_t;

typedef struct ca_sta_connect_go_start_wfd
{
    char intf[WFA_IF_NAME_LEN];
    char grpid[WFA_P2P_GRP_ID_LEN];
    char devId[WFA_P2P_DEVID_LEN];
} caStaConnectGoStartWfd_t;

enum
{
    eInvitationSend = 1,
    eInvitationAccept,
};

typedef struct ca_sta_reinvoke_wfd_session
{
    char intf[WFA_IF_NAME_LEN];
    unsigned char grpid_flag;
    char grpid[WFA_P2P_GRP_ID_LEN];
    char peer[WFA_MAC_ADDR_STR_LEN];
    BYTE wfdInvitationAction;

} caStaReinvokeWfdSession_t;

enum
{
    eDiscoveredDevList = 1,
};
enum
{
    eRSSI = 2,
};
enum
{
    ePMK = 3,
};

enum
{
    eMBSS_SCANS = 1,
};

typedef struct ca_sta_get_parameter
{
    char intf[WFA_IF_NAME_LEN];
    BYTE program;
    BYTE getParamValue;
    int getParamValFlag;
    char rssi[5];
    int rssi_flag;
    int pmk_flag;
    char pmk[70];
} caStaGetParameter_t;

enum
{
    eUibcGen = 1,
    eUibcHid,
    eFrameSkip,
    eInputContent,
    eI2cRead,
    eI2cWrite,
    eIdrReq,
};

enum
{
    eSingleTouchEvent = 1,
    eMultiTouchEvent,
    eKeyBoardEvent,
    eMouseEvent,
    eBtEvent,
};

enum
{
    eProtected = 1,
    eUnprotected,
    // eProtectedAudio,
    eProtectedVideoOnly,
    // eUnProtectedAudio,
    // eFirstVideo60fps,
    // eSecondVideo60fps,
    // eSecondVideo30fps,
};

typedef struct wfd_generate_event
{
    BYTE type;
    BYTE wfdSessionIdflag;
    char wfdSessionID[WFA_WFD_SESSION_ID_LEN];
    BYTE wfdUibcEventTypeflag;
    BYTE wfdUibcEventType;
    BYTE wfdUibcEventPrepareflag;
    BYTE wfdUibcEventPrepare;
    BYTE wfdFrameSkipRateflag;
    BYTE wfdInputContentTypeflag;
    BYTE wfdInputContentType;
    BYTE wfdI2cDataflag;
    char wfdI2cData[32];

} caWfdStaGenEvent_t;

typedef struct ca_sta_generate_event
{
    char intf[WFA_IF_NAME_LEN];
    BYTE program;
    caWfdStaGenEvent_t wfdEvent;
} caStaGenEvent_t;

#ifndef WFA_STA_TB
typedef enum wfa_supplicant_names
{
    eWindowsZeroConfig = 1,
    eNXP,
    eIntelProset,
    eWpaSupplicant,
    eCiscoSecureClient,
    eOpen1x,
    eDefault
} wfaSupplicantName;
/* P2P */
/*
typedef struct ca_sta_get_p2p_dev_address
{
   char intf[WFA_IF_NAME_LEN];
} caStaGetP2pDevAddress_t;
*/
typedef struct ca_sta_set_p2p
{
    char intf[WFA_IF_NAME_LEN];

    unsigned char listen_chn_flag;
    WORD listen_chn;

    unsigned char p2p_mode_flag;
    char p2p_mode[16];

    unsigned char presistent_flag;
    int presistent;

    unsigned char intra_bss_flag;
    int intra_bss;

    unsigned char noa_duration_flag;
    int noa_duration;

    unsigned char noa_interval_flag;
    int noa_interval;

    unsigned char noa_count_flag;
    int noa_count;

    unsigned char concurrency_flag;
    int concurrency;

    unsigned char p2p_invitation_flag;
    int p2p_invitation;

    unsigned char bcn_int_flag;
    int bcn_int;

    unsigned char ext_listen_time_int_flag;
    int ext_listen_time_int;

    unsigned char ext_listen_time_period_flag;
    int ext_listen_time_period;

    unsigned char discoverability_flag;
    int discoverability;

    unsigned char service_discovry_flag;
    int service_discovery;

    unsigned char crossconnection_flag;
    int crossconnection;

    unsigned char p2pmanaged_flag;
    int p2pmanaged;

    unsigned char go_apsd_flag;
    int go_apsd;

    unsigned char discover_type_flag;
    int discoverType;

} caStaSetP2p_t;

typedef struct ca_sta_p2p_connect
{
    char intf[WFA_IF_NAME_LEN];
    char grpid[WFA_P2P_GRP_ID_LEN];
    char devId[WFA_P2P_DEVID_LEN];
} caStaP2pConnect_t;

typedef struct ca_sta_start_auto_go
{
    char intf[WFA_IF_NAME_LEN];
    WORD oper_chn;
    unsigned char ssid_flag;
    char ssid[WFA_SSID_NAME_LEN];
    unsigned char rtsp_flag;
    WORD rtsp;

} caStaStartAutoGo_t;

typedef struct ca_sta_p2p_start_grp_formation
{
    char intf[WFA_IF_NAME_LEN];
    char devId[WFA_P2P_DEVID_LEN];
    WORD intent_val;
    WORD init_go_neg;
    unsigned char oper_chn_flag;
    WORD oper_chn;
    unsigned char ssid_flag;
    char ssid[WFA_SSID_NAME_LEN];
} caStaP2pStartGrpForm_t;

typedef struct ca_sta_p2p_dissolve
{
    char intf[WFA_IF_NAME_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaP2pDissolve_t;

typedef struct ca_sta_send_p2p_inv_req
{
    char intf[WFA_IF_NAME_LEN];
    char devId[WFA_P2P_DEVID_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
    int reinvoke;
} caStaSendP2pInvReq_t;

typedef struct ca_sta_accept_p2p_inv_req
{
    char intf[WFA_IF_NAME_LEN];
    char devId[WFA_P2P_DEVID_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
    int reinvoke;
} caStaAcceptP2pInvReq_t;

typedef struct ca_sta_send_p2p_prov_dis_req
{
    char intf[WFA_IF_NAME_LEN];
    char confMethod[16];
    char devId[WFA_P2P_DEVID_LEN];
} caStaSendP2pProvDisReq_t;

typedef struct ca_sta_set_wps_pbc
{
    char intf[WFA_IF_NAME_LEN];
    unsigned char grpid_flag;
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaSetWpsPbc_t;

typedef struct ca_sta_wps_read_pin
{
    char intf[WFA_IF_NAME_LEN];
    unsigned char grpid_flag;
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaWpsReadPin_t;

typedef struct ca_sta_wps_read_label
{
    char intf[WFA_IF_NAME_LEN];
    unsigned char grpid_flag;
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaWpsReadLabel_t;

typedef struct ca_sta_wps_enter_pin
{
    char intf[WFA_IF_NAME_LEN];
    char wpsPin[WFA_WPS_PIN_LEN];
    unsigned char grpid_flag;
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaWpsEnterPin_t;

typedef struct ca_sta_get_psk
{
    char intf[WFA_IF_NAME_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaGetPsk_t;

typedef struct ca_sta_get_p2p_ip_config
{
    char intf[WFA_IF_NAME_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaGetP2pIpConfig_t;

typedef struct ca_sta_send_service_discovery_req
{
    char intf[WFA_IF_NAME_LEN];
    char devId[WFA_P2P_DEVID_LEN];
} caStaSendServiceDiscoveryReq_t;

typedef struct ca_sta_send_p2p_presence_req
{
    char intf[WFA_IF_NAME_LEN];
    long long int duration;
    long long int interval;
} caStaSendP2pPresenceReq_t;

typedef struct ca_sta_add_arp_table_entry
{
    char intf[WFA_IF_NAME_LEN];
    char macaddress[WFA_MAC_ADDR_STR_LEN];
    char ipaddress[WFA_MAC_ADDR_STR_LEN];
} caStaAddARPTableEntry_t;

typedef struct ca_sta_block_icmp_reponse
{
    char intf[WFA_IF_NAME_LEN];
    char ipaddress[WFA_MAC_ADDR_STR_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaBlockICMPResponse_t;

typedef struct ca_sta_set_sleep
{
    char intf[WFA_IF_NAME_LEN];
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaSetSleep_t;

typedef struct ca_sta_set_opportunistic_ps
{
    char intf[WFA_IF_NAME_LEN];
    int ctwindow;
    char grpId[WFA_P2P_GRP_ID_LEN];
} caStaSetOpprPs_t;

/* P2P */

typedef enum wfa_preambleType
{
    eLong = 1,
    eShort
} wfaPreambleType;

typedef enum wfa_WirelessMode
{
    eModeB = 1,
    eModeBG,
    eModeA,
    eModeABG,
    eModeAN,
    eModeGN,
    eModeNL,
    eModeAC,
    eModeHE,
} wfaWirelessMode;

typedef enum wfa_reset_prog
{
    eResetProg11n = 1,
} wfaResetProg;

typedef enum wfa_tdlsMode
{
    eDef     = 0,
    eHiLoMac = 1,
    eExistLink,
    eAPProhibit,
    eWeakSec,
    eIgnChnlSWProh, /* if it is present, ignore channel switch prohibit */
} wfaTDLSMode;

typedef enum wfa_wfdDevType
{
    eSource = 1,
    ePSink,
    eSSink,
    eDual,
} wfaWfdDevType;

typedef enum wfa_UiInput
{
    eKeyBoard = 1,
    eMouse,
    eBt,
    eJoyStick,
    eSingleTouch,
    eMultiTouch,
} wfaUiInput;

typedef enum wfa_AudioModes
{
    eMandatoryAudioMode = 1,
    eDefaultAudioMode,
} wfaAudioModes;

typedef enum wfa_VideoFormats
{
    eCEA = 1,
    e640x480p60,
    e720x480p60,
    e20x480i60,
    e720x576p50,
    e720x576i50,
    e1280x720p30,
    e1280x720p60,
    e1920x1080p30,
    e1920x1080p60,
    e1920x1080i60,
    e1280x720p25,
    e1280x720p50,
    e1920x1080p25,
    e1920x1080p50,
    e1920x1080i50,
    e1280x720p24,
    e1920x1080p24,

    eVesa,
    e800x600p30,
    e800x600p60,
    e1024x768p30,
    e1024x768p60,
    e1152x864p30,
    e1152x864p60,
    e1280x768p30,
    e1280x768p60,
    e1280x800p30,
    e1280x800p60,
    e1360x768p30,
    e1360x768p60,
    e1366x768p30,
    e1366x768p60,
    e1280x1024p30,
    e1280x1024p60,
    e1400x1050p30,
    e1400x1050p60,
    e1440x900p30,
    e1440x900p60,
    e1600x900p30,
    e1600x900p60,
    e1600x1200p30,
    e1600x1200p60,
    e1680x1024p30,
    e1680x1024p60,
    e1680x1050p30,
    e1680x1050p60,
    e1920x1200p30,
    e1920x1200p60,

    eHH,
    e800x480p30,
    e800x480p60,
    e854x480p30,
    e854x480p60,
    e864x480p30,
    e864x480p60,
    e640x360p30,
    e640x360p60,
    e960x540p30,
    e960x540p60,
    e848x480p30,
    e848x480p60,
} wfavideoFormats;

typedef struct ca_sta_preset_parameters
{
    char intf[WFA_IF_NAME_LEN];
    wfaSupplicantName supplicant;
    BYTE programFlag;
    WORD program;
    BYTE rtsFlag;
    WORD rtsThreshold;
    BYTE fragFlag;
    WORD fragThreshold;
    BYTE preambleFlag;
    wfaPreambleType preamble;
    BYTE modeFlag;
    wfaWirelessMode wirelessMode;
    BYTE psFlag;
    BYTE legacyPowerSave;
    BYTE wmmFlag;
    BYTE wmmState;
    BYTE reset;
    BYTE ht; // temperary for high throughput
    BYTE ftoa;
    BYTE ftoa_flag;
    BYTE ftds;
    BYTE activescan;
    BYTE tdls;
    BYTE tdlsMode;
    BYTE tdlsFlag;
    BYTE wfdDevTypeFlag;
    BYTE wfdDevType;
    BYTE wfdUibcGenFlag;
    BYTE wfdUibcGen;
    BYTE wfdUibcHidFlag;
    BYTE wfdUibcHid;
    BYTE wfdUiInputFlag;
    BYTE wfdUiInputs;
    BYTE wfdUiInput[3];
    BYTE wfdHdcpFlag;
    BYTE wfdHdcp;
    BYTE wfdFrameSkipFlag;
    BYTE wfdFrameSkip;
    BYTE wfdAvChangeFlag;
    BYTE wfdAvChange;
    BYTE wfdStandByFlag;
    BYTE wfdStandBy;
    BYTE wfdInVideoFlag;
    BYTE wfdInVideo;
    BYTE wfdVideoFmatFlag;
    BYTE wfdInputVideoFmats;
    BYTE wfdVideoFmt[64];
    BYTE wfdAudioFmatFlag;
    BYTE wfdAudioFmt;
    BYTE wfdI2cFlag;
    BYTE wfdI2c;
    BYTE wfdVideoRecoveryFlag;
    BYTE wfdVideoRecovery;
    BYTE wfdPrefDisplayFlag;
    BYTE wfdPrefDisplay;
    BYTE wfdServiceDiscoveryFlag;
    BYTE wfdServiceDiscovery;
    BYTE wfd3dVideoFlag;
    BYTE wfd3dVideo;
    BYTE wfdMultiTxStreamFlag;
    BYTE wfdMultiTxStream;
    BYTE wfdTimeSyncFlag;
    BYTE wfdTimeSync;
    BYTE wfdEDIDFlag;
    BYTE wfdEDID;
    BYTE wfdUIBCPrepareFlag;
    BYTE wfdUIBCPrepare;
    BYTE wfdCoupledCapFlag;
    BYTE wfdCoupledCap;
    BYTE wfdOptionalFeatureFlag;
    BYTE wfdSessionAvail;
    BYTE wfdSessionAvailFlag;
    BYTE wfdDeviceDiscoverability;
    BYTE wfdDeviceDiscoverabilityFlag;
    BYTE Cellular_Data_Cap;
    BYTE Cellular_Data_Cap_Flag;
    BYTE Roaming_Flag;
    int Roaming;
    BYTE Ch_Op_Class_Flag;
    int Ch_Op_Class;
    BYTE Ch_Reason_Code_Flag;
    int Ch_Reason_Code;
    int Assoc_Disallow;
    BYTE Assoc_Disallow_Flag;
    int BSS_Transition;
    BYTE BSS_Transition_Flag;
    int Ch_Pref_Num;
    BYTE Ch_Pref_Num_Flag;
    int Ch_Pref;
    BYTE Ch_Pref_Flag;
    int wfdPpsMoId;
    char fileType[10];
    char fileName[30];
    char filePath[100];
    char provisioningProto[10];
} caStaPresetParameters_t;

typedef struct ca_sta_set_11n
{
    char intf[WFA_IF_NAME_LEN];
    BOOL _40_intolerant;
    BOOL addba_reject;
    BOOL ampdu;
    BOOL amsdu;
    BOOL greenfield;
    BOOL sgi20;
    unsigned short stbc_rx;
    unsigned short smps;
    char width[8];
    char mcs_fixedrate[4];
    BOOL mcs32;
    BOOL rifs_test;
    unsigned char txsp_stream;
    unsigned char rxsp_stream;
} caSta11n_t;

#define WFA_ENABLED      1
#define WFA_OPTIONAL     1
#define WFA_DISABLED     0
#define WFA_REQUIRED     2
#define WFA_F_REQUIRED   3 /* forced required */
#define WFA_F_DISABLED   4 /* forced disabled */
#define WFA_INVALID_BOOL 0xFF

struct setWireless11n
{
    BOOL _40_intolerant;
    BOOL addba_reject;
    BOOL ampdu;
    BOOL amsdu;
    BOOL greenfield;
    BOOL sgi20;
    unsigned short stbc_rx;
    unsigned short smps;
    char width[8];
    char mcs_fixedrate[4];
    BOOL mcs32;
    BOOL rifs_test;
    unsigned char txsp_stream;
    unsigned char rxsp_stream;
};

struct setWirelessVHT5G
{
    BOOL _40_intolerant;
    int _40_intolerant_flag;
    BOOL addba_reject;
    int addba_reject_flag;
    BOOL ampdu;
    int ampdu_flag;
    BOOL amsdu;
    int amsdu_flag;
    BOOL greenfield;
    int greenfield_flag;
    BOOL sgi20;
    int sgi20_flag;
    unsigned short stbc_rx;
    int stbc_rx_flag;
    unsigned short smps;
    int smps_flag;
    char width[8];
    int width_flag;
    BOOL mcs32;
    int mcs32_flag;
    BOOL rifs_test;
    int rifs_test_flag;
    unsigned char txsp_stream;
    int txsp_stream_flag;
    unsigned char rxsp_stream;
    int rxsp_stream_flag;
    BOOL dynBWSig80;
    int dynBWSig80_flag;
    BOOL dynBWSig40;
    int dynBWSig40_flag;
    BOOL sgi80;
    int sgi80_flag;
    BOOL txBF;
    int txBF_flag;
    BOOL ldpc;
    int ldpc_flag;
    char optMNotifIE[8];
    int optMNotifIE_flag;
    char nssMCSCap[8];
    int nssMCSCap_flag;
    char nssMCSOpt[8];
    int nssMCSOpt_flag;
    int zero_crc;
    int zero_crc_flag;
    int bw_signal;
    int bw_signal_flag;
    int dyn_bw_signal;
    int dyn_bw_signal_flag;
    int vht_tkip;
    int vht_tkip_flag;
};

/*Divesh Adding the sta_set_wireless Struct for HE */
struct setWirelessHE
{
    BOOL _40_intolerant;
    int _40_intolerant_flag;
    BOOL addba_reject;
    int addba_reject_flag;
    BOOL ampdu;
    int ampdu_flag;
    BOOL amsdu;
    int amsdu_flag;
    BOOL greenfield;
    int greenfield_flag;
    BOOL sgi20;
    int sgi20_flag;
    unsigned short stbc_rx;
    int stbc_rx_flag;
    unsigned short smps;
    int smps_flag;
    char width[8];
    int width_flag;
    char ADDBAReq_BufSize[20];
    int ADDBAReq_BufSize_flag;
    BOOL OMControl;
    char ADDBAResp_BufSize[20];
    int ADDBAResp_BufSize_flag;
    char BA_Recv_Status[20];
    int BA_Recv_Status_flag;
    int OMControl_flag;
    BOOL UPH;
    int UPH_flag;
    char mcs_fixedrate[8];
    int mcs_fixedrate_flag;
    BOOL mcs32;
    int mcs32_flag;
    BOOL rifs_test;
    int rifs_test_flag;
    char txsp_stream[12];
    int txsp_stream_flag;
    char rxsp_stream[12];
    int rxsp_stream_flag;
    BOOL dynBWSig80;
    int dynBWSig80_flag;
    BOOL dynBWSig40;
    int dynBWSig40_flag;
    BOOL sgi80;
    int sgi80_flag;
    BOOL txBF;
    int txBF_flag;
    BOOL ldpc;
    int ldpc_flag;
    BOOL bcc;
    int bcc_flag;
    char optMNotifIE[8];
    int optMNotifIE_flag;
    char nssMCSCap[8];
    int nssMCSCap_flag;
    char nssMCSOpt[8];
    int nssMCSOpt_flag;
    int zero_crc;
    int zero_crc_flag;
    int bw_signal;
    int bw_signal_flag;
    int dyn_bw_signal;
    int dyn_bw_signal_flag;
    int vht_tkip;
    int vht_tkip_flag;
    int he_smps_flag;
    int HE_SMPS;
};

typedef struct ca_sta_set_wireless
{
    char intf[WFA_IF_NAME_LEN];
    char band[8];
#define NOACK_BE 0
#define NOACK_BK 1
#define NOACK_VI 2
#define NOACK_VO 3
    unsigned char noAck[4];
    // move all "set_11n" to this command

    //   char prog[16];
    // set enum definition _program_type_
    unsigned short prog;

    union _progs
    {
        struct setWireless11n cert11n;
        struct setWirelessVHT5G vht5g;
        struct setWirelessHE he;
    } progs;
} caStaSetWireless_t;

typedef struct ca_sta_send_addba
{
    char intf[WFA_IF_NAME_LEN];
    unsigned short tid;
    char dest[WFA_MAC_ADDR_STR_LEN]; /* dest mac addr */
} caStaSetSendADDBA_t;

typedef struct ca_sta_set_rifs
{
    char intf[WFA_IF_NAME_LEN];
    unsigned int action;

} caStaSetRIFS_t;

typedef struct ca_sta_send_coexist_mgmt
{
    char intf[WFA_IF_NAME_LEN];
    char type[16];
    char value[16];
} caStaSendCoExistMGMT_t;
#endif

typedef struct ca_sta_set_uapsd
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    int maxSPLength;
    BYTE acBE;
    BYTE acBK;
    BYTE acVI;
    BYTE acVO;
    int type;
    char peer[18];
} caStaSetUAPSD_t;

typedef struct ca_sta_set_ibss
{
    char intf[WFA_IF_NAME_LEN];
    char ssid[WFA_SSID_NAME_LEN];
    int channel;
    int encpType;
    char keys[4][32];
    int activeKeyIdx;
} caStaSetIBSS_t;

typedef struct sta_upload
{
    int type;
    int next; /* sequence number, 0 is the last one */
} caStaUpload_t;

typedef struct sta_debug_set
{
    unsigned short level;
    unsigned short state;
} staDebugSet_t;
typedef struct config
{
    BYTE wmm;
    int rts_thr;
    int frag_thr;
} wmmconf_t;

typedef struct wmm_tsinfo
{
    unsigned int Reserved1 : 1;
    unsigned int TID : 4;
    unsigned int direction : 2;
    unsigned int dummy1 : 1;
    unsigned int dummy2 : 1;
    unsigned int Reserved2 : 1;
    unsigned int PSB : 1;
    unsigned int UP : 3;
    unsigned int infoAck : 2;
    unsigned int Reserved4 : 1;
    unsigned int Reserved5 : 6;
    unsigned int bstSzDef : 1;
} wmmtsinfo_t;

typedef struct wmm_tspec
{
    wmmtsinfo_t tsinfo;
    BOOL Fixed;                 // The MSDU Fixed Bit
    unsigned short size;        // The MSDU Size
    unsigned short maxsize;     // Maximum MSDU Size
    unsigned int min_srvc;      // The minimum Service Interval
    unsigned int max_srvc;      // The maximum Service Interval
    unsigned int inactivity;    // Inactivity Interval
    unsigned int suspension;    // The Suspension Interval
    unsigned int srvc_strt_tim; // The Service Start Time
    unsigned int mindatarate;   // The Minimum Data Rate
    unsigned int meandatarate;  // The Minimum Data Rate
    unsigned int peakdatarate;  // The Minimum Data Rate
    unsigned int burstsize;     // The Maximum Burst Size
    unsigned int delaybound;    // The Delay Bound
    unsigned int PHYrate;       // The minimum PHY Rate
    float sba;                  // The Surplus Bandwidth Allownce
    unsigned short medium_time; // The medium time
} wmmtspec_t;

typedef struct wmmac_addts
{
    BYTE dialog_token;
    BYTE accesscat;
    wmmtspec_t tspec;
} wmmacadd_t;

typedef struct ca_sta_set_wmm
{
    char intf[WFA_IF_NAME_LEN];
    BYTE group;
    BYTE action;
#ifdef WFA_WMM_AC
    BYTE send_trig;
    char dipaddr[WFA_IP_ADDR_STR_LEN];
    BYTE trig_ac;
#endif

    union _action
    {
        wmmconf_t config;
        wmmacadd_t addts;
        BYTE delts;
    } actions;
} caStaSetWMM_t;

typedef struct ca_sta_set_pwrsave
{
    char intf[WFA_IF_NAME_LEN];
    char mode[8];
} caStaSetPwrSave_t;

typedef struct ca_sta_set_powersave
{
    char intf[WFA_IF_NAME_LEN];
    char mode[8];
    int ps_flag;
} caStaSetPowerSave_t;

typedef struct ca_sta_reset_default
{
    char intf[WFA_IF_NAME_LEN];
    char prog[8];
    char type[16];
    int testbed;
} caStaResetDefault_t;

typedef struct ca_dev_info
{
    BYTE fw;
} caDevInfo_t;

typedef struct ca_sta_associate
{
    char ssid[WFA_SSID_NAME_LEN];
    char bssid[18];
    unsigned char wps;
    int channel;
    int HE_24G;
    int HE_5G;

} caStaAssociate_t;

typedef struct ca_sta_set_radio
{
    wfaOnOffType mode;
} caStaSetRadio_t;

typedef struct rfeat_tdls
{
    BYTE chsw;
    short int offchnum;
    BYTE secChOffset;
} rfeatTDLS_t;

typedef struct ca_sta_rfeature
{
    char intf[WFA_IF_NAME_LEN];
    char prog[8];
    wfaEnableType uapsd;
    char peer[18];
    wfaEnableType tpktimer;
    char nss_mcs_opt[8];
    int nss_mcs_opt_flag;
    unsigned short prog_enum_name;

    int Nebor_Pref;
    BYTE Nebor_Pref_Flag;
    int Ch_Pref_Num;
    BYTE Ch_Pref_Num_Flag;
    int Ch_Pref;
    BYTE Ch_Pref_Flag;
    int Cellular_Data_Cap;
    BYTE Cellular_Data_Cap_Flag;
    int Ch_Op_Class;
    BYTE Ch_Op_Class_Flag;
    int Ch_Reason_Code;
    BYTE Ch_Reason_Code_Flag;
    BYTE Nebor_BSSID_flag;
    char Nebor_BSSID[32];
    BYTE Nebor_Op_Class_flag;
    int Nebor_Op_Class;
    BYTE Nebor_Op_Ch_flag;
    int Nebor_Op_Ch;
    // add tx_lgi_rate
    /* HE STA_SET_RFEATURE*/
    int NDPPagingInd;
    int NDPPagingInd_Flag;
    int RespPMMode;
    int RespPMMode_Flag;
    int NegotiationType;
    int NegotiationType_Flag;
    int TWT_Setup_Flag;
    char TWT_Setup[10];
    int SetupCommand_Flag;
    int SetupCommand;
    int TWT_Trigger;
    int TWT_Trigger_Flag;
    int implicit;
    int FlowType;
    int WakeIntervalExp;
    int Protection;
    int NominalMinWakeDur;
    int WakeIntervalMantissa;
    int TWT_Channel;
    int transmitOMI;
    int transmitOMI_Flag;
    int OMCtrl_TxNSTS;
    int OMCtrl_RxNSS;
    int OMCtrl_ChnlWidth;
    int OMCtrl_ULMUDataDisable;
    int OMCtrl_ULMUDisable;
    int LTF_Flag;
    char LTF[5];
    int GI_Flag;
    char GI[5];
    int HE_BAND_24G;
    int HE_BAND_5G;
    char PPDUTxType[8];
    int PPDUTxType_Flag;
    int TxSUPPDU_flag;
    char TxSUPPDUType[8];
    int MU_EDCA_flag;
    char MU_EDCAType[8];
    int BTWT_ID;
    int BTWT_FLAG;

    /* HE STA_SET_RFEATURE-Completed*/
    union _rfeatype
    {
        rfeatTDLS_t tdls;
    } rfeaType;
} caStaRFeat_t;

typedef struct ca_bssid_pool
{
    int enable;
    char bssid[WFA_BSSID_POOL_STR_LEN];
} caBssidPool_t;

typedef enum credential_type
{
    UNAME_PWD = 1,
    SIM,
    CERT,
} Credential_t;

typedef struct ca_set_HS2
{
    char mcc[WFA_MCC_MNC_STR_LEN];
    char mnc[WFA_MCC_MNC_STR_LEN];
    char realm[WFA_HOME_REALM_STR_LEN];
    char username[WFA_HOME_REALM_STR_LEN];
    char password[WFA_HOME_REALM_STR_LEN];
    char imsi[17]; /* 16B */
    char ca[32];
    char client[32];
    Credential_t cred;
    BYTE prefer;
    BYTE home_fdqn;
    char fqdn[128];
} caSetHS2_t;

typedef struct ca_OSU_HS2
{
    int enable;
    int prodESSAssoc;
    int ignore_blacklist;
    int not_provide_friendly_name;
    char ssid[128];
    char friendly_name[128];
} caOSU_t;

typedef struct ca_Sta_scan
{
    BYTE accNetType;
    char hessid[WFA_BSSID_POOL_STR_LEN];
    int mbss_scan;
    char mbss_scan_res[920];
    BYTE sta_mbss_scan;
} caStaScan_t;
typedef struct ca_dev_set_parm
{
    BYTE program;
    char devType[10];
    HS2_Frame_t hs2;
} cadevSetParm_t;

typedef struct ca_reset_parm
{
    BYTE HS2_cache;
    BYTE arp;
    char ip[16];
} caResetParm_t;

typedef struct sta_policy_update
{
    BYTE policy_update;
    int timeout;
} staPolicyUpdate_t;

typedef struct dev_configure_ie
{
    char ie_name[20];
    char ie_contents[524];
} devConfigureIe_t;
typedef struct dut_commands
{
    char intf[WFA_IF_NAME_LEN];
    union _cmds
    {
        int streamId;
        int iftype;
        tgProfile_t profile;
        tgPingStart_t startPing;
        char resetProg[16];
        char macaddr[18];
        caStaAssociate_t assoc;
        char ssid[WFA_SSID_NAME_LEN];
        caStaSetIpConfig_t ipconfig;
        caStaVerifyIpConnect_t verifyIp;
        caStaSetEncryption_t wep;
        caStaSetPSK_t psk;
        caStaSetEapTLS_t tls;
        caStaSetEapTTLS_t ttls;
        caStaSetEapSIM_t sim;
        caStaSetEapPEAP_t peap;
        caStaSetEapAKA_t aka;
        caStaSetEapFAST_t fast;
        caStaSetSecurity_t setsec;
        caStaSetUAPSD_t uapsd;
        caStaSetIBSS_t ibss;
        caStaUpload_t upload;
        caStaSetWMM_t setwmm;
        staDebugSet_t dbg;
        caDevInfo_t dev;
        caStaDevSendFrame_t sf;
        caStaSetRadio_t sr;
        caStaRFeat_t rfeat;
        caBssidPool_t bssid_pool;
        caSetHS2_t hs2_param;
        caOSU_t osu;
        caStaScan_t Stascan_param;
        cadevSetParm_t devSetParm;
        caResetParm_t reset_parm;
        staPolicyUpdate_t staPolicyUpdate;
        devConfigureIe_t devConfigIe;
        caStaGetParameter_t getrssi;
    } cmdsu;
} dutCommand_t;

#ifndef EXPERIMENTAL_AP_SUPPORT

typedef struct caAPReboot
{
    char intf[WFA_IF_NAME_LEN];
} caAPReboot_t;

typedef struct caAPConfigCommit
{
    char intf[WFA_IF_NAME_LEN];
} caAPConfigCommit_t;

typedef struct caAPResetDefault
{
    char intf[WFA_IF_NAME_LEN];
    char prog[8];
    char type[16];
    int testbed;
} caAPResetDefault_t;

typedef struct caAPSet11n
{
    char intf[WFA_IF_NAME_LEN];
} caAPSet11n_t;

typedef struct caAPSet11d
{
    char intf[WFA_IF_NAME_LEN];
    char regulatory_mode[4];
    char CountryCode[4];
    int CountryCode_flag;
} caAPSet11d_t;

typedef struct caAPSet11h
{
    char intf[WFA_IF_NAME_LEN];
    char regulatory_mode[4];
    char CountryCode[4];
    int CountryCode_flag;
    int dfs_chan;
    int dfs_flag;
    int sim_dfs_flag;
    char dfs_mode[12];
} caAPSet11h_t;

typedef struct wmm_ac_s
{
    int cwmin;
    int cwmin_flag;
    int cwmax;
    int cwmax_flag;
    int aifs;
    int aifs_flag;
    int txop;
    int txop_flag;
} wmm_ac_t;

typedef struct caAPSetStaQos
{
    char intf[WFA_IF_NAME_LEN];
    wmm_ac_t vi, vo, be, bk;
    int vi_flag, vo_flag, be_flag, bk_flag;
} caAPSetStaQos_t;

typedef struct caAPSetAPQos
{
    char intf[WFA_IF_NAME_LEN];
} caAPSetAPQos_t;

typedef struct caAPSetWireless
{
    char intf[WFA_IF_NAME_LEN];
    char name[WFA_AP_NAME_LEN];

    char ssid[WFA_AP_SSID_LEN];
    int ssid_flag;

    int channel;
    int channel_flag;

    int chnlfreq;
    int chnlfreq_flag;

    char mode[10];
    int mode_flag;

    char wme[10];
    int wme_flag;

    char wmmps[10];
    int wmmps_flag;

    int rts;
    int rts_flag;

    int frgmnt;
    int frgmnt_flag;

    char powersave[10];
    int ps_flag;

    char bcnint[10];
    int bcnint_flag;

    int radio;
    int radio_flag;

    int p2p_mgmt_bit;
    int p2p_mgmt_bit_flag;

    char channel_usage[10];
    int channel_usage_flag;

    int tdls_prohibit;
    int tdls_prohibit_flag;

    int tdls_ch_switch_prohibit;
    int tdls_ch_switch_prohibit_flag;

    int addba_reject;
    int addba_reject_flag;

    int mcs_fixedrate;
    int mcs_fixedrate_flag;

    int spatial_tx_stream;
    int spatial_tx_stream_flag;

    int spatial_rx_stream;
    int spatial_rx_stream_flag;

    int gf;
    int gf_flag;

    int ampdu;
    int ampdu_flag;

    int amsdu;
    int amsdu_flag;

    int vht_tkip_flag;
    int vht_tkip;

    int vht_wep_flag;
    int vht_wep;

    int stbc_tx;
    int stbc_tx_flag;

    int tx_bf;
    int tx_bf_flag;

    int htc_vht;
    int htc_vht_flag;

    char nssMCSCap[8];
    int nssMCSCap_flag;

    int width;
    int width_flag;

    int bw_signal;
    int bw_signal_flag;

    int dyn_bw_signal;
    int dyn_bw_signal_flag;

    int ldpc;
    int ldpc_flag;

    int spectrum_mgt;
    int spectrum_mgt_flag;

    char country_code[4];
    int country_code_flag;

    int protect_mode;
    int protect_mode_flag;
    int sgi80;
    int sgi80_flag;

    int sgi20;
    int sgi20_flag;

    int mcs32;
    int mcs32_flag;

    int band6gonly;
    int band6gonly_flag;

    int testbed;

    int DFS_CHAN_FLAG;
    int HT_40_PLUS_FLAG;
    int HT_40_MINUS_FLAG;
    int HT_20_ONLY_FLAG;
    BYTE Cellular_Cap_Pref_flag;
    int Cellular_Cap_Pref;
    BYTE Reg_Domain_flag;
    char Reg_Domain[16];
    BYTE GAS_CB_Delay_flag;
    int GAS_CB_Delay;
    // HE-AP
    char PPDUTxType[2];
    int PPDUTxType_flag;
    char OFDMA[2];
    int OFDMA_flag;
    char MIMO[2];
    int MIMO_flag;
    char BA_Recv_Status[4];
    int BA_Recv_Status_flag;

    int BCC;
    int BCC_flag;
    int ADDBAResp_BufSize;
    int ADDBAResp_BufSize_flag;
    int ADDBAReq_BufSize;
    int ADDBAReq_BufSize_flag;
    int HE_TXOPDurRTSThr;
    int HE_TXOPDurRTSThr_flag;
} caAPSetWireless_t;

typedef struct caAPSetSecurity
{
    char intf[WFA_IF_NAME_LEN];
    char name[WFA_AP_NAME_LEN];
    char keymgnt[WFA_AP_KEYMGMT_LEN];
    char encrypt[WFA_AP_ENCRY_LEN];
    short encry_flag;
    char psk[WFA_AP_PASSPHRASE_LEN];
    short psk_flag;
    char wepkey[WFA_AP_WEPKEY_LEN];
    short wep_flag;
    char ssid[WFA_AP_SSID_LEN];
    short ssid_flag;
    char pmf[WFA_AP_SSID_LEN];
    short pmf_flag;
    char sha256ad[WFA_AP_SSID_LEN];
    short sha_flag;
    int sae_pwe_flag;
    char sae_pwe[8];
    int ECGroupID_flag;
    char ECGroup_ID[10];
    int AKMSuiteType_flag;
    char AKMSuiteType[8];
    char SAEPasswords[WFA_AP_PASSPHRASE_LEN];
    int SAEPasswords_flag;
    int Transition_Disable_flag;
    int Transition_Disable;
    int Transition_Disable_Index;
} caAPSetSecurity_t;

typedef struct caAPSendADDBAReq
{
    char intf[WFA_IF_NAME_LEN];
    char name[WFA_AP_NAME_LEN];
} caAPSendADDBAReq_t;

typedef struct caAPSetRfeature
{
    char intf[WFA_IF_NAME_LEN];
    char name[WFA_AP_NAME_LEN];
    char nss_mcs_opt[8];
    int nss_mcs_opt_flag;
    char optMNotifIE[8];
    int optMNotifIE_flag;

    int csa_chnum;
    int csa_width;
    int csa_chnum_band_flag;
    BYTE BTMReq_DisAssoc_Imnt_flag;
    int BTMReq_DisAssoc_Imnt;
    BYTE BTMReq_Term_Bit_flag;
    int BTMReq_Term_Bit;
    BYTE Assoc_Disallow_flag;
    char Assoc_Disallow[16];
    BYTE Nebor_BSSID_flag;
    int Nebor_BSSID;
    BYTE Nebor_Op_Class_flag;
    int Nebor_Op_Class;
    BYTE Nebor_Op_Ch_flag;
    int Nebor_Op_Ch;
    BYTE Disassoc_Timer_flag;
    int Disassoc_Timer;
    BYTE Assoc_Delay_flag;
    int Assoc_Delay;
    BYTE Nebor_Pref_flag;
    int Nebor_Pref;
    BYTE BSS_Term_Duration_flag;
    int BSS_Term_Duration;
    // DD-HE
    int LTF_Flag;
    char LTF[5];
    int GI_Flag;
    char GI[5];
    int txBandwidth_flag;
    char txBandwidth[5];
    int HE_BAND_24G;
    int HE_BAND_5G;
    char HE_TXOPDurRTSThr[5];
    int HE_TXOPDurRTSThr_flag;
    int TriggerType;
    int TriggerType_flag;

} caAPSetRfeature_t;

typedef struct caAPSetRadius
{
    char intf[WFA_IF_NAME_LEN];
    char name[WFA_AP_NAME_LEN];
    char as_ip[32];
    int as_ip_flag;
    char as_port[8];
    int as_port_flag;
    char as_passwd[128];
    int as_passwd_flag;
} caAPSetRadius_t;

typedef struct ca_ap_set_11n_wireless
{
    char intf[WFA_IF_NAME_LEN];
    char name[16];
    char width[4];
    char sgi20[8];
    char spatial_tx[4];
    char spatial_rx[4];
} caApSet11nWireless_t;

typedef struct ca_ap_set_pmf
{
    char name[16];
    char intf[WFA_IF_NAME_LEN];
    char pmf[16];
} caApSetPmf_t;

typedef struct ca_ap_get_mac_address
{
    char name[16];
    char intf[WFA_IF_NAME_LEN];
} caApGetMacAddress_t;

typedef struct ca_ap_deauth_sta
{
    char intf[WFA_IF_NAME_LEN];
    char name[16];
    char sta_mac_address[17];
    int MinorCode;
} caApDeauthSta_t;

#endif

extern int buildCommandProcessTable(void);

#endif
