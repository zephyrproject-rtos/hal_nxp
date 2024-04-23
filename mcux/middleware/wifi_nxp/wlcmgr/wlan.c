/** @file wlan.c
 *
 *  @brief  This file provides Core WLAN definition
 *
 *  Copyright 2008-2023 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <string.h>
#include <wm_utils.h>
#include <wlan.h>
#include <wifi.h>
#include <wm_os.h>
#include <wm_net.h>
#include <wifi-debug.h>
#include <wlan_11d.h>
#include <stdint.h>
#ifndef RW610
#include <mlan_sdio_api.h>
#endif
#if defined(CONFIG_HOST_PMK) || defined(CONFIG_WPS2)
#include <wm_mbedtls_helper_api.h>
#include <mbedtls/x509_crt.h>
#endif /* defined(CONFIG_HOST_PMK) || defined(CONFIG_WPS2) */
#ifdef RW610
#include <wifi_cal_data_ext.h>
#endif
#ifdef OVERRIDE_CALIBRATION_DATA
#include OVERRIDE_CALIBRATION_DATA
#else
#include <wifi_cal_data_ext.h>
#endif
#include <fsl_common.h>
#include <dhcp-server.h>
#ifdef RW610
#include "fsl_loader.h"
#endif

#ifdef CONFIG_SIGMA_AGENT
#include "wifi_ping.h"
#include <sigma_agent.h>
#endif

#ifdef CONFIG_HOST_SLEEP
#ifdef RW610
#include  "fsl_power.h"
#ifndef __ZEPHYR__
#if !defined(CONFIG_WIFI_BLE_COEX_APP)
#include  "lpm.h"
#include  "host_sleep.h"
#endif
#ifdef CONFIG_POWER_MANAGER
#include  "fsl_pm_core.h"
#include  "fsl_pm_device.h"
#endif
#endif
#endif
#endif
#ifdef CONFIG_WPS2
#include  <wifi_nxp_wps.h>
#include  <wps_def.h>
#endif
#ifdef CONFIG_WPA_SUPP
#include <supp_main.h>
#include <supp_api.h>
#include <wifi_nxp.h>
#include "utils/common.h"
#ifdef CONFIG_WIFI_SHELL
#include "wpa_cli.h"
#endif
#endif

#if defined(CONFIG_WPA2_ENTP) || (defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE) && !defined(CONFIG_WIFI_USB_FILE_ACCESS))
#include "ca-cert.h"
#include "client-cert.h"
#include "client-key.h"
#include "dh-param.h"
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
#include "server-cert.h"
#include "server-key.h"
#endif
#endif
#endif
#include "mlan_decl.h"

#ifdef CONFIG_NCP_BRIDGE
#include "app_notify.h"
#endif

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
#include "board.h"

#if (defined(CPU_MIMXRT1062DVMAA_cm7) || defined(CPU_MIMXRT1062DVL6A_cm7) || defined (CPU_MIMXRT1062DVL6B_cm7))
#if defined(SD8978) || defined(SD8987)
/* IR-OOB TRIGGER Connect Fly-Wire between J16.1 and J108.4 for 1XK-M2, 1ZM-M2*/
#define IR_OUTBAND_TRIGGER_GPIO			GPIO1
#define IR_OUTBAND_TRIGGER_GPIO_PIN		(23U)
#define IR_OUTBAND_TRIGGER_GPIO_NAME   "GPIO1"
//#define IOMUXC_GPIO_IR_OUTBAND_TRIGGER IOMUXC_GPIO_AD_B1_07_GPIO1_IO23
#elif defined(SD9177)
/* IR-OOB TRIGGER for 2EL-M2, Internal Routing to M2 Slot*/
#define IR_OUTBAND_TRIGGER_GPIO			GPIO1
#define IR_OUTBAND_TRIGGER_GPIO_PIN		(24U)
#define IR_OUTBAND_TRIGGER_GPIO_NAME   "GPIO1"
//#define IOMUXC_GPIO_IR_OUTBAND_TRIGGER IOMUXC_GPIO_AD_B1_08_GPIO1_IO24
#endif

#elif defined(CPU_MIMXRT1176DVMAA_cm7) // For RT1170
/* IR OUT-BAND TRIGGER GPIO*/
/*Output GPIO J9 PIN2 (IOMUXC_GPIO_DISP_B2_11) for RT1170-EVKA/B*/
#define IR_OUTBAND_TRIGGER_GPIO   		GPIO5
#define IR_OUTBAND_TRIGGER_GPIO_PIN   	(12U)
#define IR_OUTBAND_TRIGGER_GPIO_NAME  	"GPIO5"

#endif /* (defined(CPU_MIMXRT1062DVMAA_cm7) || (CPU_MIMXRT1062DVL6A_cm7)) */
#endif

#define DELAYED_SLP_CFM_DUR 10U
#define BAD_MIC_TIMEOUT     (60 * 1000)

#ifdef CONFIG_WPA_SUPP
#define SUPP_STATUS_TIMEOUT (2 * 1000)
#define ROAM_SCAN_TIMEOUT   (60 * 1000)
#endif

#define WL_ID_CONNECT      "wifi_connect"
#define WL_ID_DEEPSLEEP_SM "wlcm_deepsleep_sm"
#define WL_ID_WIFI_RSSI    "wifi_rssi"

/** Find maximum */
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifdef CONFIG_ECSA
#define DEF_SWITCH_COUNT 10
#endif

#define BG_SCAN_LIMIT 3

static bool wlan_uap_scan_chan_list_set;

wlan_flt_cfg_t g_flt_cfg;
#ifdef RW610
#if defined(CONFIG_MONOLITHIC_WIFI) && defined(__ZEPHYR__)
extern const unsigned char *wlan_fw_bin;
extern const unsigned int wlan_fw_bin_len;
#else
const unsigned char *wlan_fw_bin   = (const unsigned char *)(void *)0;
const unsigned int wlan_fw_bin_len = 0;
#endif /* CONFIG_MONOLITHIC_WIFI */
#ifdef __ZEPHYR__
extern int nxp_wifi_wlan_event_callback(enum wlan_event_reason reason, void *data);
#define wlan_event_callback nxp_wifi_wlan_event_callback
#else
extern int wlan_event_callback(enum wlan_event_reason reason, void *data);
#endif
#endif

static int wifi_wakeup_card_cb(os_rw_lock_t *plock, unsigned int wait_time);

#ifdef CONFIG_WPA2_ENTP
extern int wpa2_ent_connect(struct wlan_network *wpa2_network);
extern void wpa2_shutdown();
#endif

#ifdef CONFIG_NCP_BRIDGE
/* uap provision callbacks */
int (*uap_prov_deinit_cb)(void) = NULL;
void (*uap_prov_cleanup_cb)(void) = NULL;
#endif

os_rw_lock_t sleep_rwlock;

#ifdef CONFIG_WMM_UAPSD
os_semaphore_t uapsd_sem;
#endif

#ifdef CONFIG_CPU_LOADING
#define CPU_LOADING_ACTION_STOP        0
#define CPU_LOADING_ACTION_START       1
#define CPU_LOADING_STATUS_ONGOING     2
#define CPU_LOADING_STATUS_ENDING      3
#define CPU_LOADING_STATUS_DEAD        4
#define CPU_LOADING_PERIOD             2000
#define CPU_LOADING_TASK_NUM           20
#define CPU_LOADING_KEEPING            -1
static os_thread_stack_define(cpu_loading_stack, 2048);

static struct
{
    /*The number of tasks.*/
    uint8_t task_nums;
    /*The total length of cpu info struct*/
    uint32_t task_status_len;
    /*Pointer to buffer of storing cpu Loading info.*/
    char *cpu_loading_info;
    /*CPU loading status: CPU_LOADING_STATUS_ENDING / CPU_LOADING_STATUS_ONGOING / CPU_LOADING_STATUS_DEAD*/
    uint8_t status;
    /*Index of collecting CPU loading info.*/
    uint32_t index;
    /*Remaining time of collecting CPU loading info.*/
    int sampling_loops;
    /*The value of timer time out*/
    uint32_t sampling_period;
    /*CPU loading timer.*/
    os_timer_t cpu_loading_timer;
    /*CPU loading thread.*/
    os_thread_t cpu_loading_thread;

    /*Array of recording names of tasks.*/
    char task_name[CPU_LOADING_TASK_NUM][configMAX_TASK_NAME_LEN];
    /*Array of recording runing time of tasks.*/
    uint64_t data_cur[CPU_LOADING_TASK_NUM];
    uint64_t data_pre[CPU_LOADING_TASK_NUM];
    /*Array of recording the first runing time of tasks.*/
    uint64_t first_data[CPU_LOADING_TASK_NUM];
}cpu_loading;

char task_string_name[CPU_LOADING_TASK_NUM][configMAX_TASK_NAME_LEN];

#endif


#ifdef CONFIG_WPS2
int prov_session_attempt = PROV_NON_SESSION_ATTEMPT;
extern WPS_DATA wps_global;
#endif

#define MAX_EVENTS 20
#define CONNECTION_EVENT(r, data) \
    if (wlan.cb != NULL)          \
    {                             \
        (void)wlan.cb(r, data);   \
    }

#ifdef RW610
static os_mutex_t reset_lock;
/* Mon thread */
static os_thread_t mon_thread;
static os_thread_stack_t mon_stack;
static bool mon_thread_init = 0;
#endif

#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
#ifndef __ZEPHYR__
status_t powerManager_WlanNotify(pm_event_type_t eventType, uint8_t powerState, void *data);
AT_ALWAYS_ON_DATA_INIT(pm_notify_element_t wlan_notify) =
{
    .notifyCallback = powerManager_WlanNotify,
    .data           = NULL,
};
bool is_wakeup_cond_set = false;
#endif
#if !defined(CONFIG_WIFI_BLE_COEX_APP)
int wlan_host_sleep_state = HOST_SLEEP_DISABLE;
#else
int wlan_host_sleep_state = HOST_SLEEP_PERIODIC;
#endif
#ifdef CONFIG_UART_INTERRUPT
/* This flag is used for Power Manager only.
 * When using Power Manager, the uart task holds the rxSemaphore and waits
 * on uart event group to receive input from uart. With this flag, uart task
 * will have chance to release the lock so that IDLE task can do uart deinit
 * before entering PM3.
 * When using suspend mode, no such observations.
 */
bool usart_suspend_flag = false;
#endif
os_timer_t wake_timer;
#endif
int is_hs_handshake_done = 0;
extern os_semaphore_t wakelock;
extern int wakeup_by;
bool wlan_is_manual = false;
#endif

/* The monitor thread event queue receives events from the power manager
 * wlan notifier when idle hook is invoked and host is ready to enter
 * specific low power mode
 */
os_queue_t mon_thread_events;
os_queue_pool_t mon_thread_events_queue_data;

static t_u16 scan_channel_gap = (t_u16)SCAN_CHANNEL_GAP_VALUE;

#ifndef __ZEPHYR__
#ifdef SD9177
#define POLL_TIMEOUT (20 * 1000)
static struct udp_pcb *udp_raw_pcb;
#endif
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V)
#define NEIGHBOR_REQ_TIMEOUT (60 * 1000)
#endif

#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
#define FT_ROAM_TIMEOUT (20 * 1000)
#endif
#endif

enum user_request_type
{
    /* we append our user-generated events to the wifi interface events and
     * handle them accordingly */
    CM_STA_USER_REQUEST_CONNECT = WIFI_EVENT_LAST + 1,
    CM_STA_USER_REQUEST_DISCONNECT,
    CM_STA_USER_REQUEST_SCAN,
#if defined(CONFIG_11K) || defined(CONFIG_11V)
    CM_STA_USER_REQUEST_SET_RSSI_THRESHOLD,
#endif
#ifdef CONFIG_HOST_SLEEP
    CM_STA_USER_REQUEST_HS,
#endif
    CM_STA_USER_REQUEST_PS_ENTER,
    CM_STA_USER_REQUEST_PS_EXIT,
#ifdef CONFIG_CPU_LOADING
    CM_STA_USER_REQUEST_CPU_LOADING,
#endif
    CM_STA_USER_REQUEST_LAST,
    /* All the STA related request are above and uAP related requests are
       below */
    CM_UAP_USER_REQUEST_START,
    CM_UAP_USER_REQUEST_STOP,
    CM_UAP_USER_REQUEST_PS_ENTER,
    CM_UAP_USER_REQUEST_PS_EXIT,
    CM_UAP_USER_REQUEST_LAST,
    CM_WLAN_USER_REQUEST_DEINIT,
    CM_WLAN_USER_REQUEST_SHUTDOWN
};

static int send_user_request(enum user_request_type request, unsigned int data);

enum cm_sta_state
{
    CM_STA_INITIALIZING = 0,
    CM_STA_IDLE,
    CM_STA_SCANNING,
    CM_STA_SCANNING_USER,
    CM_STA_ASSOCIATING,
    CM_STA_ASSOCIATED,
    CM_STA_AUTHENTICATED,
    CM_STA_REQUESTING_ADDRESS,
    CM_STA_OBTAINING_ADDRESS,
    CM_STA_CONNECTED,
};

enum cm_uap_state
{
    CM_UAP_INITIALIZING = 0,
    CM_UAP_CONFIGURED,
    CM_UAP_STARTED,
    CM_UAP_IP_UP,
};

static struct wifi_scan_params_t g_wifi_scan_params = {NULL,
                                                       NULL,
                                                       {
                                                           0,
                                                       },
                                                       BSS_ANY,
                                                       60,
                                                       153};

static os_queue_pool_define(g_wlan_event_queue_data, (int)(sizeof(struct wifi_message) * MAX_EVENTS));

#ifndef CONFIG_WLCMGR_STACK_SIZE
#define CONFIG_WLCMGR_STACK_SIZE 5120
#endif
static os_thread_stack_define(g_cm_stack, CONFIG_WLCMGR_STACK_SIZE);
#ifdef CONFIG_WPS2
#ifndef CONFIG_WPS_STACK_SIZE
#define CONFIG_WPS_STACK_SIZE 5120
#endif
static os_thread_stack_define(g_wps_stack, CONFIG_WPS_STACK_SIZE);
static int wlcm_wps_callback(enum wps_event event, void *data, uint16_t len);

typedef enum
{
    PROV_WPS_NONE,
    PROV_WPS_STARTED,     /* WPS provisioning started */
    PROV_WPS_PBC_ENABLED, /* WPS pushbutton attempt enabled */
    PROV_WPS_PIN_ENABLED, /* WPS PIN attempt enabled */
    PROV_WPS_SUCCESSFUL,  /* WPS based provisioning successful */
} wps_state_t;

static struct
{
    wps_state_t wps_state;
    enum wps_session_command wps_cmd;
    uint32_t wps_pin;

    /* WPS thread */
    os_thread_t wps_main_thread;
    os_thread_stack_t wps_stack;

    os_semaphore_t wps_scan_done;
    struct wlan_scan_result wps_res;
} wlan_wps;

static struct wps_config wps_conf = {
    .role                    = 1, //WPS_ENROLLEE
    .pin_generator           = 1,
    .version                 = 0x20,
    .version2                = 0x20,
    .device_name             = "Redfinch",
    .manufacture             = "NXP",
    .model_name              = "rw610",
    .model_number            = "0001",
    .serial_number           = "0001",
    .config_methods          = 0x2388,
    .primary_dev_category    = 01,
    .primary_dev_subcategory = 01,
    .rf_bands                = 2,
    .os_version              = 0xFFFFFFFF,
    .wps_msg_max_retry       = 5,
    .wps_msg_timeout         = 5000,
    .pin_len                 = 8,
    .wps_callback            = wlcm_wps_callback,
    .prov_session            = PROV_NON_SESSION_ATTEMPT,
};
#endif /* CONFIG_WPS2 */
#ifdef RW610
#ifndef CONFIG_MON_THREAD_STACK_SIZE
#define CONFIG_MON_THREAD_STACK_SIZE 1152
#endif
static void wlan_mon_thread(os_thread_arg_t data);
static os_thread_stack_define(g_mon_stack, CONFIG_MON_THREAD_STACK_SIZE);
static os_queue_pool_define(g_mon_event_queue_data, sizeof(struct wlan_message) * MAX_EVENTS);
#endif
typedef enum
{
    WLCMGR_INACTIVE,
    WLCMGR_INIT_DONE,
    WLCMGR_ACTIVATED,
    WLCMGR_THREAD_STOPPED,
    WLCMGR_THREAD_DELETED,
} wlcmgr_status_t;

static struct
{
    /* This lock enables the scan response data to be accessed by multiple
     * threads with the expectation that any thread accessing the scan lock may
     * have to sleep until it is available.  The lock is taken by calling
     * wlan_scan() and it is released by the WLAN Connection Manager main
     * thread when the scan response data has been handled and
     * is therefore free for another user.  This lock must never be taken
     * in the WLAN Connection Manager main thread and it must only be
     * released by that thread. The lock count must be 0 or 1. */
    os_semaphore_t scan_lock;
    bool is_scan_lock;

    /* The WLAN Connection Manager event queue receives events (command
     * responses, WiFi events, TCP stack events) from the wifi interface as
     * well as user requests (connect, disconnect, scan).  This is the main
     * blocking point for the main thread and acts as the state machine tick.*/
    os_queue_t events;
    os_queue_pool_t events_queue_data;

    /* internal state */
    enum cm_sta_state sta_state, sta_ipv4_state;
#ifdef CONFIG_IPV6
    enum cm_sta_state sta_ipv6_state;
#endif
    enum cm_sta_state sta_return_to;
    enum cm_uap_state uap_state;
    enum cm_uap_state uap_return_to;
    /* store sta mac addr */
    uint8_t sta_mac[MLAN_MAC_ADDR_LENGTH];
    /* store uap mac addr */
    uint8_t uap_mac[MLAN_MAC_ADDR_LENGTH];
    /* callbacks */
    int (*cb)(enum wlan_event_reason reason, void *data);
    int (*scan_cb)(unsigned int count);
    void (*event_cb)(int type);

    /* known networks list */
    struct wlan_network networks[WLAN_MAX_KNOWN_NETWORKS];
    int cur_network_idx;
    int cur_uap_network_idx;

    unsigned int num_networks;
    unsigned int scan_count;

    unsigned int uap_supported_max_sta_num;

    /* CM thread */
    os_thread_t cm_main_thread;
    os_thread_stack_t cm_stack;
    unsigned running : 1;
    unsigned stop_request : 1;
    wlcmgr_status_t status;

    /*
     * Power save state configuration
     * These are states corresponding to the network that we are currently
     * connected to. Not relevant, when we are not connected.
     */
    bool cm_ieeeps_configured : 1;
    bool cm_deepsleepps_configured : 1;
    bool connect_wakelock_taken : 1;
    unsigned int wakeup_conditions;
#ifdef CONFIG_HOST_SLEEP
    bool is_hs_configured : 1;
#endif
    bool is_mef_enabled : 1;
    bool cm_wnmps_configured;
    t_u16 wnm_sleep_time;
    wifi_fw_version_ext_t fw_ver_ext;

    int uap_rsn_ie_index;
    bool smart_mode_active : 1;
#ifdef CONFIG_WPA_SUPP
    os_timer_t supp_status_timer;
    bool pending_disconnect_request : 1;
    int status_timeout;
    bool connect : 1;
#ifdef CONFIG_WPA_SUPP_WPS
    int wps_session_attempt;
#endif
#endif
#if defined(CONFIG_WPA2_ENTP) || (defined(CONFIG_WPA_SUPP) && defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE))
    t_u8 *ca_cert_data;
    t_u32 ca_cert_len;
    t_u8 *client_cert_data;
    t_u32 client_cert_len;
    t_u8 *client_key_data;
    t_u32 client_key_len;
    t_u8 *ca_cert2_data;
    t_u32 ca_cert2_len;
    t_u8 *client_cert2_data;
    t_u32 client_cert2_len;
    t_u8 *client_key2_data;
    t_u32 client_key2_len;
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    t_u8 *dh_data;
    t_u32 dh_len;
    t_u8 *server_cert_data;
    t_u32 server_cert_len;
    t_u8 *server_key_data;
    t_u32 server_key_len;
#endif
#endif
#endif
    os_timer_t assoc_timer;
    bool assoc_paused : 1;
    bool pending_assoc_request : 1;
    bool reassoc_control : 1;
    bool reassoc_request : 1;
    unsigned int reassoc_count;
    bool hs_enabled;
    bool hs_configured;
    unsigned int hs_wakeup_condition;
    wifi_scan_chan_list_t scan_chan_list;
#ifdef CONFIG_WPA2_ENTP
    bool allow_wpa2_enterprise_ap_only : 1;
#endif
    bool hidden_scan_on : 1;
#ifdef CONFIG_ROAMING
    bool roaming_enabled : 1;
#endif
#ifdef CONFIG_11R
    bool ft_bss : 1;
#endif
    bool same_ess : 1;
    unsigned int bgscan_attempt;
    bool roam_reassoc : 1;
#ifdef CONFIG_WIFI_FW_DEBUG
    void (*wlan_usb_init_cb)(void);
#endif
#ifndef __ZEPHYR__
#ifdef SD9177
    os_timer_t poll_timer;
#endif
#endif
#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
    os_timer_t ft_roam_timer;
#endif
#endif
#ifdef CONFIG_11K
    bool enable_11k : 1;
    wlan_rrm_scan_cb_param rrm_scan_cb_param;
#endif
#if defined(CONFIG_11K) || defined(CONFIG_11V)
    os_timer_t neighbor_req_timer;
    bool neighbor_req : 1;
#endif
#if defined(CONFIG_11K) || defined(CONFIG_11V)
    wlan_nlist_report_param nlist_rep_param;
    wlan_rrm_neighbor_report_t nbr_rpt;
#endif
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
    uint8_t rssi_low_threshold;
#endif
    uint8_t ind_reset;
#ifdef CONFIG_HOST_SLEEP
    uint8_t hs_dummy_send;
#endif
#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
    uint8_t ir_mode;
#endif
} wlan;

#ifdef CONFIG_CLOUD_KEEP_ALIVE
#define MIN_KEEP_ALIVE_ID 0
#define MAX_KEEP_ALIVE_ID 4
wlan_cloud_keep_alive_t cloud_keep_alive_param[MAX_KEEP_ALIVE_ID];
#endif

void wlan_wake_up_card(void);

#ifdef CONFIG_WLCMGR_DEBUG
static char *dbg_sta_state_name(enum cm_sta_state state)
{
    switch (state)
    {
        case CM_STA_INITIALIZING:
            return "initializing";
        case CM_STA_IDLE:
            return "idle";
        case CM_STA_SCANNING:
            return "scanning";
        case CM_STA_SCANNING_USER:
            return "user scanning";
        case CM_STA_ASSOCIATING:
            return "associating";
        case CM_STA_ASSOCIATED:
            return "associated";
        case CM_STA_AUTHENTICATED:
            return "authenticated";
        case CM_STA_REQUESTING_ADDRESS:
            return "requesting address";
        case CM_STA_OBTAINING_ADDRESS:
            return "obtaining address";
        case CM_STA_CONNECTED:
            return "connected";
        default:
            return "unknown";
    }
}

static char *dbg_uap_state_name(enum cm_uap_state state)
{
    switch (state)
    {
        case CM_UAP_INITIALIZING:
            return "initializing";
        case CM_UAP_CONFIGURED:
            return "configured";
        case CM_UAP_STARTED:
            return "started";
        case CM_UAP_IP_UP:
            return "IP configured";
        default:
            return "unknown";
    }
}

static void dbg_lock_info(void)
{
#if 0
	int ret;
	char *name;
	unsigned long cur_val, suspended_count;
	TX_THREAD *first_suspended;
	TX_SEMAPHORE *next;

	ret = tx_semaphore_info_get(&wlan.scan_lock, &name, &cur_val,
				    &first_suspended, &suspended_count, &next);
	if (ret) {
		wlcm_e("unable to fetch scan lock info");
		return;
	}

	wlcm_d("scan lock info: count=%ld, suspended=%ld", cur_val,
	       suspended_count);
#endif
}
#else
#define dbg_lock_info(...)
#define dbg_sta_state_name(...)
#define dbg_uap_state_name(...)
#endif /* CONFIG_WLCMGR_DEBUG */

/*
 * Utility Functions
 */

int verify_scan_duration_value(int scan_duration)
{
    if (scan_duration >= 50 && scan_duration <= 500)
    {
        return WM_SUCCESS;
    }
    return -WM_FAIL;
}

int verify_scan_channel_value(int channel)
{
    if (channel >= 0 && channel <= 11)
    {
        return WM_SUCCESS;
    }
    return -WM_FAIL;
}

int verify_split_scan_delay(int delay)
{
    if (delay >= 30 && delay <= 300)
    {
        return WM_SUCCESS;
    }
    return -WM_FAIL;
}

int set_scan_params(struct wifi_scan_params_t *wifi_scan_params)
{
    if (!verify_scan_duration_value(wifi_scan_params->scan_duration))
    {
        g_wifi_scan_params.scan_duration = wifi_scan_params->scan_duration;
    }
    if (!verify_scan_channel_value(wifi_scan_params->channel[0]))
    {
        g_wifi_scan_params.channel[0] = wifi_scan_params->channel[0];
    }
    if (!verify_split_scan_delay(wifi_scan_params->split_scan_delay))
    {
        g_wifi_scan_params.split_scan_delay = wifi_scan_params->split_scan_delay;
    }
    return WM_SUCCESS;
}

#ifdef CONFIG_RX_ABORT_CFG
int wlan_set_get_rx_abort_cfg(struct wlan_rx_abort_cfg *cfg, t_u16 action)
{
    return wifi_set_get_rx_abort_cfg((void *)cfg, action);
}
#endif

#ifdef CONFIG_RX_ABORT_CFG_EXT
int wlan_set_rx_abort_cfg_ext(const struct wlan_rx_abort_cfg_ext *cfg)
{
    return wifi_set_get_rx_abort_cfg_ext((void *)cfg, ACTION_SET);
}

int wlan_get_rx_abort_cfg_ext(struct wlan_rx_abort_cfg_ext *cfg)
{
    return wifi_set_get_rx_abort_cfg_ext((void *)cfg, ACTION_GET);
}
#endif

#ifdef CONFIG_CCK_DESENSE_CFG
int wlan_set_get_cck_desense_cfg(struct wlan_cck_desense_cfg *cfg, t_u16 action)
{
    return wifi_set_get_cck_desense_cfg((void *)cfg, action);
}
#endif

int get_scan_params(struct wifi_scan_params_t *wifi_scan_params)
{
    wifi_scan_params->scan_duration    = g_wifi_scan_params.scan_duration;
    wifi_scan_params->channel[0]       = g_wifi_scan_params.channel[0];
    wifi_scan_params->split_scan_delay = g_wifi_scan_params.split_scan_delay;
    return WM_SUCCESS;
}

void wlan_dhcp_cleanup()
{
    net_stop_dhcp_timer();
    net_interface_dhcp_stop(net_get_mlan_handle());
#ifndef __ZEPHYR__
    net_interface_dhcp_cleanup(net_get_mlan_handle());
#endif
}

#ifdef CONFIG_HOST_SLEEP
static uint32_t wlan_map_to_wifi_wakeup_condtions(const uint32_t wlan_wakeup_condtions)
{
    uint32_t conditions = 0;
    if ((wlan_wakeup_condtions & WAKE_ON_UNICAST) != 0U)
    {
        conditions |= WIFI_WAKE_ON_UNICAST;
    }

    if ((wlan_wakeup_condtions & WAKE_ON_ALL_BROADCAST) != 0U)
    {
        conditions |= WIFI_WAKE_ON_ALL_BROADCAST;
    }

    if ((wlan_wakeup_condtions & WAKE_ON_MULTICAST) != 0U)
    {
        conditions |= WIFI_WAKE_ON_MULTICAST;
    }

    if ((wlan_wakeup_condtions & WAKE_ON_ARP_BROADCAST) != 0U)
    {
        conditions |= WIFI_WAKE_ON_ARP_BROADCAST;
    }

    if ((wlan_wakeup_condtions & WAKE_ON_MAC_EVENT) != 0U)
    {
        conditions |= WIFI_WAKE_ON_MAC_EVENT;
    }

    if ((wlan_wakeup_condtions & WAKE_ON_MGMT_FRAME) != 0U)
    {
        conditions |= WIFI_WAKE_ON_MGMT_FRAME;
    }

    return conditions;
}
#endif

int wlan_is_started()
{
    return ((wlan.running == 1) && (wlan.status == WLCMGR_ACTIVATED));
}

static bool is_user_scanning(void)
{
    return (wlan.sta_state == CM_STA_SCANNING_USER);
}

static bool is_state(enum cm_sta_state state)
{
    if (is_user_scanning() == true)
    {
        return (wlan.sta_return_to == state);
    }

    return (wlan.sta_state == state);
}

static bool is_uap_state(enum cm_uap_state state)
{
    return (wlan.uap_state == state);
}

static int wlan_get_ipv4_addr(unsigned int *ipv4_addr)
{
    struct wlan_network* network = NULL;

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        network = &wlan.networks[wlan.cur_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get network info");
        *ipv4_addr = 0;
        return -WM_FAIL;
    }

    *ipv4_addr = network->ip.ipv4.address;

    return WM_SUCCESS;
}

static int wlan_get_uap_ipv4_addr(unsigned int *ipv4_addr)
{
    struct wlan_network* network = NULL;

    if (wlan.running && (is_uap_state(CM_UAP_IP_UP) || is_uap_state(CM_UAP_STARTED)))
    {
        network = &wlan.networks[wlan.cur_uap_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get uap network info");
        *ipv4_addr = 0;
        return -WM_FAIL;
    }

    *ipv4_addr = network->ip.ipv4.address;

    return WM_SUCCESS;
}

static int wlan_set_pmfcfg(uint8_t mfpc, uint8_t mfpr);

#ifdef CONFIG_HOST_SLEEP
static int wlan_send_host_sleep_int(uint32_t wake_up_conds, bool is_config)
{
    int ret = WM_SUCCESS;
    unsigned int ipv4_addr = 0;
    enum wlan_bss_type type = WLAN_BSS_TYPE_STA;

    if (!wlan_is_started())
    {
        (void)PRINTF("Wakeup condition configure is not allowed when WIFI is disabled\r\n");
        return -WM_FAIL;
    }

    /* Check if wake_up_conds is valid or not */
    if (wake_up_conds && (wake_up_conds != HOST_SLEEP_CFG_CANCEL) && (wake_up_conds & 0x20))
    {
        (void)PRINTF("Invalid wake_up_conds. Bit 5 is reserved.\r\n");
        return -WM_FAIL;
    }

    if (!is_sta_connected() && !mlan_adap->priv[1]->media_connected)
    {
        if ((wake_up_conds & (WAKE_ON_ALL_BROADCAST | WAKE_ON_UNICAST | WAKE_ON_MULTICAST
                                   | WAKE_ON_ARP_BROADCAST | WAKE_ON_MGMT_FRAME)) != 0)
        {
            wlcm_e("Connection on STA or uAP is required for configured bitmap!\r\n");
            ret = -WM_FAIL;
            return ret;
        }
    }

    if (wake_up_conds == HOST_SLEEP_CFG_CANCEL)
    {
        wlan.hs_enabled = MFALSE;
        wlan.hs_configured       = MFALSE;
        wlan.hs_wakeup_condition = wake_up_conds;
        wlan.is_mef_enabled = MFALSE;
        (void)memset(&g_flt_cfg, 0, sizeof(wlan_flt_cfg_t));
        wifi_set_packet_filters(&g_flt_cfg);
    }
#ifdef CONFIG_CLOUD_KEEP_ALIVE
    else if(is_config == MFALSE)
    {
        wlan_start_cloud_keep_alive();
    }
#endif

#ifndef RW610
    if (wake_up_conds == HOST_SLEEP_NO_COND)
    {
        wlan.hs_enabled = MTRUE;
        wlan.hs_wakeup_condition = wake_up_conds;
        if (g_flt_cfg.nentries == 0 && (is_config == MFALSE))
        {
            (void)PRINTF("No user configured MEF entries, use default ARP filters.\r\n");
            /* User doesn't configure MEF, use default MEF entry */
            wlan_mef_set_auto_arp(MEF_ACTION_ALLOW_AND_WAKEUP_HOST);
        }
        if (wlan.is_mef_enabled == MFALSE)
        {
            wlan.is_mef_enabled = MTRUE;
            wifi_set_packet_filters(&g_flt_cfg);
        }
    }
    else
#endif
    {
        wlan.hs_enabled = MTRUE;
        wlan.hs_wakeup_condition = wlan_map_to_wifi_wakeup_condtions(wake_up_conds);
    }

    if (is_sta_ipv4_connected() != 0)
    {
        ret = wlan_get_ipv4_addr(&ipv4_addr);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("HS: cannot get STA IP, check if STA disconnected");
            return -WM_FAIL;
        }
    }
    else if (is_uap_started())
    {
        ret = wlan_get_uap_ipv4_addr(&ipv4_addr);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("HS: cannot get UAP IP, check if uAP stopped");
            return -WM_FAIL;
        }
        type = WLAN_BSS_TYPE_UAP;
    }
    else
    {
        ipv4_addr = 0;
    }

    if (wlan.hs_dummy_send == MFALSE || is_config == MFALSE)
    {
        ret = wifi_send_hs_cfg_cmd((mlan_bss_type)type, ipv4_addr, HS_CONFIGURE, wlan.hs_wakeup_condition);
        if (ret == WM_SUCCESS)
        {
            if (wake_up_conds != HOST_SLEEP_CFG_CANCEL)
            {
                wlan.hs_configured = MTRUE;
            }
        }
        wlan.hs_dummy_send = MTRUE;
    }
    return ret;
}

void wlan_hs_pre_cfg(void)
{
    if (wlan.hs_enabled == MTRUE)
    {
        (void)wlan_send_host_sleep_int(wlan.hs_wakeup_condition, MFALSE);
        /** Wait for HS Activate to complete */
        os_thread_sleep(os_msec_to_ticks(1000));
    }
}

void wlan_hs_post_cfg(void)
{
    uint16_t hs_wakeup_reason;

    if (wlan.hs_enabled == MTRUE)
    {
        (void)wifi_get_wakeup_reason(&hs_wakeup_reason);

        (void)wifi_print_wakeup_reason(hs_wakeup_reason);
    }
}

int wlan_send_host_sleep(uint32_t wake_up_conds)
{
    if (!wlan.running)
    {
        return WLAN_ERROR_STATE;
    }

    wakelock_get();

    (void)send_user_request(CM_STA_USER_REQUEST_HS, wake_up_conds);

    return WM_SUCCESS;
}

int wlan_get_wakeup_reason(uint16_t *hs_wakeup_reason)
{
    return wifi_get_wakeup_reason(hs_wakeup_reason);
}

#endif

#ifdef CONFIG_HOST_SLEEP
status_t wlan_hs_send_event(int id, void *data)
{
    struct wlan_message msg;
    int ret;

    (void)memset(&msg, 0U, sizeof(struct wlan_message));
    msg.data = data;
    msg.id  = id;
    ret = os_queue_send(&mon_thread_events, &msg, OS_NO_WAIT);
    if (ret != 0)
    {
        (void)PRINTF("PM: Failed to send msg to queue\r\n");
#ifdef __ZEPHYR__
        return -WM_FAIL;
#else
        return kStatus_Fail;
#endif
    }
#ifdef __ZEPHYR__
    return WM_SUCCESS;
#else
    return kStatus_Success;
#endif
}

#ifdef CONFIG_POWER_MANAGER
static void wake_timer_cb(os_timer_arg_t arg)
{
    if(wakelock_isheld())
        wakelock_put();
}

#ifndef __ZEPHYR__
status_t powerManager_WlanNotify(pm_event_type_t eventType, uint8_t powerState, void *data)
{
    int ret;

    if (eventType == kPM_EventEnteringSleep
#ifdef RW610
            && powerState > PM_LP_STATE_PM0
#endif
            )
    {
        /* Entering low power mode is not allowed in any of below conditions:
         * 1. Host sleep is disabled
         * 2. wlan initialization is still on going
         * 3. wakelock is held by any task
         * 4. Host sleep handshake is on going or fail
         * 5. UAPSD/PPS is activated
         */
        if (!wlan_host_sleep_state || wlan.status != WLCMGR_ACTIVATED ||
            wakelock_isheld()
#ifdef CONFIG_WMM_UAPSD
            || mlan_adap->pps_uapsd_mode
#endif
            )
            return kStatus_PMPowerStateNotAllowed;
#ifdef RW610
        /* Skip host sleep handshake for PM1 */
        if (powerState == PM_LP_STATE_PM1)
            goto done;
#endif
        if (!is_hs_handshake_done)
        {
            is_hs_handshake_done = WLAN_HOSTSLEEP_IN_PROCESS;
            ret = wlan_hs_send_event(HOST_SLEEP_HANDSHAKE, NULL);
            if (ret != 0)
                return kStatus_PMNotifyEventError;
            return kStatus_PMPowerStateNotAllowed;
        }
        /* If hanshake is still in process, entring low power mode is not allowed */
        if (is_hs_handshake_done == WLAN_HOSTSLEEP_IN_PROCESS)
            return kStatus_PMPowerStateNotAllowed;
        if (is_hs_handshake_done == WLAN_HOSTSLEEP_FAIL)
        {
            is_hs_handshake_done = 0;
            return kStatus_PMNotifyEventError;
        }
#ifdef RW610
#if !defined(CONFIG_WIFI_BLE_COEX_APP)
        ret = host_sleep_pre_cfg((int)powerState);
        if(ret != 0)
            return kStatus_PMPowerStateNotAllowed;
#endif
#endif
    }
    else if (eventType == kPM_EventExitingSleep)
    {
#ifdef RW610
        /* Skip host sleep handshake for PM1 */
        if (powerState == PM_LP_STATE_PM1)
            goto done;
#endif
        if (is_hs_handshake_done == WLAN_HOSTSLEEP_SUCCESS)
        {
            ret = wlan_hs_send_event(HOST_SLEEP_EXIT, NULL);
            if (ret != 0)
                return kStatus_PMNotifyEventError;
            /* reset hs hanshake flag after waking up */
            is_hs_handshake_done = 0;
#if !defined(CONFIG_WIFI_BLE_COEX_APP)
#ifdef RW610
            host_sleep_post_cfg((int)powerState);
#endif
            /* If periodic host sleep is not enabled, reset the flag to disable host sleep */
            if (wlan_host_sleep_state == HOST_SLEEP_ONESHOT)
                wlan_host_sleep_state = HOST_SLEEP_DISABLE;
#endif
        }
    }
#ifdef RW610
done:
#endif
    return kStatus_PMSuccess;
}
#endif
#endif

int wlan_wowlan_config(uint8_t is_mef, t_u32 wake_up_conds)
{
    int ret = WM_SUCCESS;

    if (!wlan_is_started())
    {
        (void)PRINTF("Wakeup condition configure is not allowed when WIFI is disabled\r\n");
        return -WM_FAIL;
    }

    /* Check if wake_up_conds is valid or not */
    if (wake_up_conds && (wake_up_conds & 0x20))
    {
        (void)PRINTF("Invalid wake_up_conds. Bit 5 is reserved.\r\n");
        return -WM_FAIL;
    }

    if (!is_sta_connected() && !mlan_adap->priv[1]->media_connected)
    {
        if (is_mef)
        {
            wlcm_e("Connection on STA or uAP is required for MEF configuration\r\n");
            ret = -WM_FAIL;
            return ret;
        }
        else
             if ((wake_up_conds & (WAKE_ON_ALL_BROADCAST | WAKE_ON_UNICAST | WAKE_ON_MULTICAST
                                   | WAKE_ON_ARP_BROADCAST | WAKE_ON_MGMT_FRAME)) != 0)
        {
            wlcm_e("Connection on STA or uAP is required for configured bitmap!\r\n");
            ret = -WM_FAIL;
            return ret;
        }
    }

    if (is_mef)
    {
        wlan.wakeup_conditions = 0;
        if (g_flt_cfg.nentries == 0)
        {
            (void)PRINTF("No user configured MEF entries, use default ARP filters.\r\n");
            /* User doesn't configure MEF, use default MEF entry */
            wlan_mef_set_auto_arp(MEF_ACTION_ALLOW_AND_WAKEUP_HOST);
        }
        wifi_set_packet_filters(&g_flt_cfg);
    }
    else
    {
        wlan.wakeup_conditions = wake_up_conds;
        /* Clear previous MEF entries */
        if (g_flt_cfg.nentries != 0)
        {
            (void)memset(&g_flt_cfg, 0, sizeof(wlan_flt_cfg_t));
            wifi_set_packet_filters(&g_flt_cfg);
        }
    }

    return ret;
}

void wlan_config_host_sleep(bool is_manual, t_u8 is_periodic)
{
    int ret = 0;

#ifdef CONFIG_WMM_UAPSD
    if (mlan_adap && mlan_adap->pps_uapsd_mode)
    {
        wlcm_e("Host sleep is not allowed if UAPSD/PPS is activated");
        return;
    }
#endif
    wlan_is_manual = is_manual;
    if (!wlan_is_manual)
    {
#ifdef CONFIG_POWER_MANAGER
	if (!wlan_is_started())
        {
            wlcm_e("Host sleep is not allowed when WIFI is disabled\r\n");
            return;
        }
        if (is_periodic)
            wlan_host_sleep_state = HOST_SLEEP_PERIODIC;
        else
            wlan_host_sleep_state = HOST_SLEEP_ONESHOT;
#endif
    }
    else
    {
#ifdef CONFIG_POWER_MANAGER
        /* Reset flag and stop timer if manual mode is selected without cancel periodic sleep */
        wlan_host_sleep_state = HOST_SLEEP_DISABLE;
        if (os_timer_is_running(&wake_timer))
        {
            os_timer_deactivate(&wake_timer);
            wakelock_put();
        }
#endif
        if (wlan.status == WLCMGR_ACTIVATED)
        {
#ifdef CONFIG_HOST_SLEEP
            /* Start host sleep handshake here if manual mode is selected */
            ret = wlan_send_host_sleep_int(wlan.wakeup_conditions, MFALSE);
            if (ret != WM_SUCCESS)
            {
#ifdef CONFIG_NCP_BRIDGE
                app_notify_event(APP_EVT_HS_CONFIG, APP_EVT_REASON_FAILURE, NULL, 0);
#endif
                wlcm_e("Error: Failed to config host sleep");
                return;
            }
#endif
        }
    }
}

void wlan_cancel_host_sleep()
{
    int ret = 0;
    enum wlan_bss_type type = WLAN_BSS_TYPE_STA;

    if (!wlan_is_started())
    {
        PRINTF("Wlan not started, can't cancel host sleep\r\n");
        return;
    }

    if (is_uap_started() != 0)
        type = WLAN_BSS_TYPE_UAP;
    ret = wifi_cancel_host_sleep((mlan_bss_type)type);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Error: Failed to send host sleep cancel command");
        return;
    }
}

void wlan_clear_host_sleep_config()
{
    wlan_is_manual = MFALSE;
#ifdef CONFIG_POWER_MANAGER
    wlan_host_sleep_state = HOST_SLEEP_DISABLE;
#ifdef CONFIG_UART_INTERRUPT
    usart_suspend_flag = MFALSE;
#endif
    if (os_timer_is_running(&wake_timer))
    {
        os_timer_deactivate(&wake_timer);
        wakelock_put();
    }
    is_hs_handshake_done = 0;
#endif
    memset(&g_flt_cfg, 0x0, sizeof(wlan_flt_cfg_t));

    if (wlan_is_started())
    {
	wifi_set_packet_filters(&g_flt_cfg);
    }
    wakeup_by = 0;
    wifi_clear_wakeup_reason();
    wlan.wakeup_conditions = 0;
    wlan.is_hs_configured = MFALSE;
}
#endif

static void wlan_send_sleep_confirm(void)
{
    enum wlan_bss_type type = WLAN_BSS_TYPE_STA;

    if (is_uap_started() != 0)
    {
        type = WLAN_BSS_TYPE_UAP;
    }

    send_sleep_confirm_command((mlan_bss_type)type);
}

static int is_bssid_any(char *b)
{
    return (int)(!b[0] && !b[1] && !b[2] && !b[3] && !b[4] && !b[5]);
}

/* Check to see if the security features of our network, 'config', match with
 * those of a scan result, 'res' and return 1 if they do, 0 if they do not. */
static int security_profile_matches(const struct wlan_network *network, const struct wifi_scan_result2 *res)
{
    const struct wlan_network_security *config = &network->security;

    /* No security: just check that the scan result doesn't specify security */
    if (config->type == WLAN_SECURITY_NONE)
    {
#ifdef CONFIG_WPS2
        if (res->wps_session != WPS_SESSION_INACTIVE)
            return 1;
#endif
#ifdef CONFIG_OWE
        if (res->trans_mode == OWE_TRANS_MODE_OPEN)
        {
            return res->trans_ssid_len;
        }
        else if (res->trans_mode == OWE_TRANS_MODE_OWE)
        {
            return res->WPA_WPA2_WEP.wpa2;
        }
        else
        { /* Do Nothing */
        }
#endif

        if (res->WPA_WPA2_WEP.wepStatic || res->WPA_WPA2_WEP.wpa2 || res->WPA_WPA2_WEP.wpa)
        {
            return WM_SUCCESS;
        }

        return 1;
    }

    /* WEP mode: if we are using WEP, the AP must use static WEP */
    if (config->type == WLAN_SECURITY_WEP_OPEN || config->type == WLAN_SECURITY_WEP_SHARED)
    {
        if (res->phtcap_ie_present)
        {
            wlcm_e(
                "As per Wi-Fi Certification WEP "
                "is not used with HT associations "
                "in 11n devices");
            return 0;
        }
        return (int)res->WPA_WPA2_WEP.wepStatic;
    }

    /* WPA/WPA2 mode: if we are using WPA/WPA2, the AP must use WPA/WPA2 */
    if (config->type == WLAN_SECURITY_WPA_WPA2_MIXED)
    {
        return (int)(res->WPA_WPA2_WEP.wpa | res->WPA_WPA2_WEP.wpa2);
    }

    /* WPA2 mode: if we are using WPA2, the AP must use WPA2 */
    if (config->type == WLAN_SECURITY_WPA2)
    {
        return (int)(res->WPA_WPA2_WEP.wpa2 | res->WPA_WPA2_WEP.wpa2_sha256);

    }

#ifdef CONFIG_11R
    /* WPA2_FT mode: if we are using WPA2, the AP must use WPA2_FT */
    if (config->type == WLAN_SECURITY_WPA2_FT)
    {
        return (int)(res->WPA_WPA2_WEP.ft_psk);

    }
#endif

    /* OWE mode: if we are using OWE, the AP must use OWE */
#ifdef CONFIG_OWE
    if (config->type == WLAN_SECURITY_OWE_ONLY)
    {
        return (int)res->WPA_WPA2_WEP.owe;
    }
#endif

    /* WPA mode: if we are using WPA, the AP must use WPA */
    if (config->type == WLAN_SECURITY_WPA)
    {
        if (res->wpa_ucstCipher.tkip != 0U)
        {
            wlcm_e(
                "As per Wi-Fi Certification security "
                "combinations \"WPA\" alone is not allowed "
                "security type.");
            wlcm_e(
                "Please use WLAN_SECURITY_WPA_WPA2_MIXED "
                "security type to connect to "
                "WPA(TKIP) Only AP.");
            return (int)!res->wpa_ucstCipher.tkip;
        }
        return (int)res->WPA_WPA2_WEP.wpa;
    }

#ifdef CONFIG_WPA2_ENTP
    /* WPA2 Enterprise mode: if we are using WPA2 Enterprise,
     * the AP must use WPA2 Enterpise */
    if (config->type == WLAN_SECURITY_EAP_TLS || config->type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
        return res->wpa2_entp_IE_exist;
#endif

    if ((config->type == WLAN_SECURITY_WPA3_SAE) || (config->type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED))
    {
        uint8_t mfpc, mfpr;

        (void)wlan_get_pmfcfg(&mfpc, &mfpr);

        if (!mfpc && !mfpr)
        {
            wlcm_e("As per WPA3 SAE Certification, PMF is mandatory.\r\n");
            return WM_SUCCESS;
        }
        if (config->type == WLAN_SECURITY_WPA3_SAE)
            return (int)(res->WPA_WPA2_WEP.wpa3_sae);
        if (config->type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED)
            return (int)(res->WPA_WPA2_WEP.wpa3_sae | res->WPA_WPA2_WEP.wpa2 | res->WPA_WPA2_WEP.wpa2_sha256);
    }
    return WM_SUCCESS;
}

/* Check if 'network' matches the scan result 'res' based on network properties
 * and the security profile.  If we found a match, update 'network' with any
 * new information discovered when parsing 'res'. 192 We may update the channel,
 * BSSID, or SSID but not the security profile. */
static int network_matches_scan_result(const struct wlan_network *network,
                                       const struct wifi_scan_result2 *res,
                                       uint8_t *num_channels,
                                       wlan_scan_channel_list_t *chan_list)
{
    uint8_t null_ssid[IEEEtypes_SSID_SIZE] = {0};
    uint16_t idx = 0;

#ifdef CONFIG_11V
    if ((wlan.roam_reassoc == true) && (wlan.nlist_rep_param.nlist_mode == WLAN_NLIST_11V) &&
        ((wlan.nlist_rep_param.btm_mode & 0x1C) != 0U))
    {
        if (memcmp((const void *)network->bssid, (const void *)res->bssid, (size_t)IEEEtypes_ADDRESS_SIZE) == 0)
        {
            return -WM_FAIL;
        }
    }
#endif
    /* Check basic network information that we know */
    if (network->channel_specific && network->channel != res->Channel)
    {
        wlcm_d("%s: Channel mismatch. Got: %d Expected: %d", network->ssid, res->Channel, network->channel);
        return -WM_FAIL;
    }
    if (network->bssid_specific && memcmp(network->bssid, res->bssid, 6))
    {
        wlcm_d("%s: bssid mismatch.", network->ssid);
        return -WM_FAIL;
    }

    if (network->ssid_specific != 0U)
    {
        if (!wlan.hidden_scan_on && (!memcmp(null_ssid, (const char *)res->ssid, (size_t)res->ssid_len)))
        {
            chan_list[*num_channels].chan_number = res->Channel;
            chan_list[*num_channels].scan_type   = MLAN_SCAN_TYPE_ACTIVE;
            chan_list[*num_channels].scan_time   = 150;
            (*num_channels)++;
        }
        if ((res->ssid_len == 0) ||
            (strncmp((const char *)network->ssid, (const char *)res->ssid,
                     (size_t)MAX(strlen(network->ssid), (unsigned int)res->ssid_len)) != 0)
#ifdef CONFIG_OWE
            || ((res->trans_mode == OWE_TRANS_MODE_OWE) &&
                (strncmp((const char *)network->trans_ssid, (const char *)res->ssid,
                         (size_t)MAX(strlen(network->trans_ssid), (unsigned int)res->ssid_len))) != 0)
#endif
        )
        {
            wlcm_d("ssid mismatch: Got: %s Expected: %s", (char *)res->ssid, network->ssid);
            return -WM_FAIL;
        }
    }

    /* In case of CONFIG_WD_EXTERAL we don't parse and
       store the security profile.
       Instead the respective IE are stored in network struct as is */
    /* Check security information */
    if (network->security_specific != 0U)
    {
        if (!security_profile_matches(network, res))
        {
            wlcm_d("%s: security profile mismatch", network->ssid);
            return -WM_FAIL;
        }
    }

    if (!(res->WPA_WPA2_WEP.wepStatic || res->WPA_WPA2_WEP.wpa3_sae || res->WPA_WPA2_WEP.wpa2 || res->WPA_WPA2_WEP.wpa || res->WPA_WPA2_WEP.wpa2_sha256) && (network->security.psk_len || network->security.password_len))
    {
        wlcm_d("%s: security profile mismatch", network->ssid);
        return -WM_FAIL;
    }

    if (!wifi_11d_is_channel_allowed((int)res->Channel))
    {
        wlcm_d("%d: Channel not allowed.", res->Channel);
        return -WM_FAIL;
    }

#ifdef CONFIG_DRIVER_MBO
    if (res->mbo_assoc_disallowed)
    {
        wlcm_d("%s: MBO Association disallowed.", network->ssid);
        return -WM_FAIL;
    }
#endif

#ifdef CONFIG_OWE
    wlcm_d("%s: Match successful", res->trans_mode == OWE_TRANS_MODE_OWE ? network->trans_ssid : network->ssid);
#endif
    /* If the bss blacklist is not empty, check whether the network is in the blacklist or not. */
    /* If yes, skip this network. */
    if(mlan_adap->blacklist_bss.num_bssid)
    {
        for(idx = 0; idx < mlan_adap->blacklist_bss.num_bssid; idx++)
        {
            if(!memcmp(res->bssid, mlan_adap->blacklist_bss.bssids[idx], MLAN_MAC_ADDR_LENGTH))
            {
                wlcm_d("%02X:%02X:%02X:%02X:%02X:%02X : BSSID is not allowed.", res->bssid[0], res->bssid[1], res->bssid[2],
                       res->bssid[3], res->bssid[4], res->bssid[5]);
                return WM_SUCCESS;
            }
        }
    }
    return WM_SUCCESS;
}

#ifdef CONFIG_WPA2_ENTP
static int wpa2_tls_init(struct wlan_network *network)
{
    network->security.wlan_ctx =
        wm_mbedtls_ssl_config_new(&network->security.tls_cert, MBEDTLS_SSL_IS_CLIENT, MBEDTLS_SSL_VERIFY_NONE);

    if (!network->security.wlan_ctx)
    {
        wlcm_e("TLS session init failed (ctx failed)");
        return -WM_FAIL;
    }

    network->security.wlan_ssl = wm_mbedtls_ssl_new(network->security.wlan_ctx, 0, NULL);

    if (!network->security.wlan_ssl)
    {
        wlcm_e("TLS session init failed (ssl failed)");
        wm_mbedtls_ssl_config_free(network->security.wlan_ctx);
        network->security.wlan_ctx = NULL;
        return -WM_FAIL;
    }

    /* Disable SSL application data splitting as FreeRADIUS fails to
     * process splitted data
     */
    mbedtls_ssl_conf_cbc_record_splitting(network->security.wlan_ctx, MBEDTLS_SSL_CBC_RECORD_SPLITTING_DISABLED);

    return WM_SUCCESS;
}

static void wpa2_tls_cleanup(struct wlan_network *network, bool force)
{
    if (force)
    {
        if (network->security.wlan_ssl)
        {
            wm_mbedtls_ssl_free(network->security.wlan_ssl);
            network->security.wlan_ssl = NULL;
            if (network->security.wlan_ctx)
            {
                wm_mbedtls_ssl_config_free(network->security.wlan_ctx);
                network->security.wlan_ctx = NULL;
            }
        }
    }

    wpa2_shutdown();
    wlan_set_prov_session(PROV_NON_SESSION_ATTEMPT);
}
#endif

static void wlcm_request_reconnect(enum cm_sta_state *next, struct wlan_network *network);
int load_wep_key(const uint8_t *input, uint8_t *output, uint8_t *output_len, const unsigned max_output_len);

/* Configure the firmware and PSK Supplicant for the security settings
 * specified in 'network'.  For WPA and WPA2 networks, we must chose between
 * the older TKIP cipher or the newer CCMP cipher.  We prefer CCMP, however we
 * will chose TKIP if the AP doesn't report CCMP support.  CCMP is optional for
 * WPA and required for WPA2, however a WPA2 AP may still have it disabled. */
static int configure_security(struct wlan_network *network, struct wifi_scan_result2 *res)
{
    int ret = WM_SUCCESS;
    switch (network->security.type)
    {
#ifdef CONFIG_WPA2_ENTP
        case WLAN_SECURITY_EAP_TLS:
        case WLAN_SECURITY_EAP_PEAP_MSCHAPV2:
            if (network->security.pmk_valid == false)
            {
                wlan_set_prov_session(PROV_ENTP_SESSION_ATTEMPT);
                ret = wpa2_tls_init(network);
                if (ret != WM_SUCCESS)
                    return -WM_FAIL;
            }

            ret                 = wifi_send_enable_supplicant(network->role, network->ssid);
            if (ret != WM_SUCCESS)
                return -WM_FAIL;

            break;
#endif
        case WLAN_SECURITY_WPA:
        case WLAN_SECURITY_WPA2:
        case WLAN_SECURITY_WPA_WPA2_MIXED:
#ifdef CONFIG_WPS2
            wlan_set_prov_session(PROV_NON_SESSION_ATTEMPT);
#endif
            if (network->security.type == WLAN_SECURITY_WPA)
            {
                wlcm_d("configuring WPA security");
            }
            else if (network->security.type == WLAN_SECURITY_WPA2)
            {
                wlcm_d("configuring WPA2 security");
            }
            else
            {
                wlcm_d("configuring WPA/WPA2 Mixed security");
            }

            /* the handler for the "add PSK" command calls supplicantEnable() so we
             * don't do it here
             *
             * TODO: at this time, the firmware will not generate a specific
             * response to the command sent by wifi_add_wpa_psk().  The
             * command+response sequence should be worked into the WLAN Connection
             * Manager once this is fixed.
             *
             * TODO: at this time, the PSK Supplicant caches passphrases on the
             * SSID however this won't work for networks with a hidden SSID.  The
             * WLAN Connection manager will need to be updated once that's
             * resolved. */
            if (network->security.pmk_valid)
            {
                wlcm_d("adding SSID and PMK to supplicant cache");

                /* Do not pass BSSID here as embedded supplicant fails
                 * to derive session keys
                 */
                ret = wifi_send_add_wpa_pmk((int)network->role, network->ssid, NULL, network->security.pmk,
                                            WLAN_PMK_LENGTH);
            }
            else
            {
#ifdef CONFIG_11R
                if (!wlan.ft_bss)
#endif
                {
                    wlcm_d("adding SSID and PSK to supplicant cache");
                    ret = wifi_send_add_wpa_psk((int)network->role, network->ssid, network->security.psk,
                                                (unsigned int)network->security.psk_len);
                }
            }

            if (ret != WM_SUCCESS)
            {
                return -WM_FAIL;
            }
            break;
#ifdef CONFIG_OWE
        case WLAN_SECURITY_OWE_ONLY:
            if (res->WPA_WPA2_WEP.owe != 0U)
            {
                /** This is dummy command to enable the embedded supplicant in Wi-Fi fimrware, OWE never uses any password */
                wlcm_d("configuring OWE security");
                ret = wifi_send_add_wpa3_password((int)network->role, network->ssid, "12345678",
                                                  8U);
            }
            else
            { /* Do Nothing */
            }
            if (ret != WM_SUCCESS)
            {
                return -WM_FAIL;
            }
            break;
#endif
        case WLAN_SECURITY_WPA3_SAE:
        case WLAN_SECURITY_WPA2_WPA3_SAE_MIXED:
            if (res->WPA_WPA2_WEP.wpa3_sae != 0U)
            {
                wlcm_d("configuring WPA3 SAE security");
                wlcm_d("adding SSID and WPA3 SAE PASSWORD to supplicant cache");
                ret = wifi_send_add_wpa3_password((int)network->role, network->ssid, network->security.password,
                                                  network->security.password_len);
            }
            else if (res->WPA_WPA2_WEP.wpa2 != 0U || res->WPA_WPA2_WEP.wpa2_sha256 != 0U)
            {
                wlcm_d("configuring WPA2 security");
                wlcm_d("adding SSID and PSK to supplicant cache");
                ret = wifi_send_add_wpa_psk((int)network->role, network->ssid, network->security.password,
                                            network->security.password_len);
            }
            else
            { /* Do Nothing */
            }
            if (ret != WM_SUCCESS)
            {
                return -WM_FAIL;
            }
            break;
        case WLAN_SECURITY_WEP_OPEN:
        case WLAN_SECURITY_WEP_SHARED:
            ret = load_wep_key((const uint8_t *)network->security.psk, (uint8_t *)network->security.psk,
                               (uint8_t *)&network->security.psk_len, sizeof(network->security.psk));
            if (ret != WM_SUCCESS)
            {
                return -WM_E_INVAL;
            }

            ret = wifi_set_key(BSS_TYPE_STA, true, 0U, (const uint8_t *)network->security.psk,
                               (unsigned)network->security.psk_len, NULL, 0, (const uint8_t *)network->bssid, 0);

            if (ret != WM_SUCCESS)
            {
                return -WM_FAIL;
            }
            break;

        case WLAN_SECURITY_NONE:
#ifdef CONFIG_WPS2
            if (network->wps_specific && res->wps_session != WPS_SESSION_INACTIVE)
                wlan_set_prov_session(PROV_WPS_SESSION_ATTEMPT);
#endif
            break;
        default:
            wlcm_d("Unexpected wlan security");
            break;
    }

    return WM_SUCCESS;
}

static bool is_running(void)
{
    return (wlan.running && wlan.sta_state >= CM_STA_IDLE);
}

static bool is_sta_connecting(void)
{
    return ((wlan.sta_state > CM_STA_ASSOCIATING) && (wlan.sta_state <= CM_STA_CONNECTED));
}

/* Check whether we are allowed to start a user-requested scan right now. */
static bool is_scanning_allowed(void)
{
    return (is_state(CM_STA_IDLE) || is_state(CM_STA_CONNECTED) || is_state(CM_STA_AUTHENTICATED));
}

/*
 * Connection Manager actions
 */
static void do_scan(struct wlan_network *network)
{
    int ret;
    uint8_t *bssid = NULL;
    char *ssid     = NULL;
    unsigned int channel = 0;
    IEEEtypes_Bss_t type;
    wlan_scan_channel_list_t chan_list[1];
    (void)memset((uint8_t *)chan_list, 0x00, sizeof(wlan_scan_channel_list_t) * 1);
    wlcm_d("initiating scan for network \"%s\"", network->name);

    if (network->bssid_specific != 0U)
    {
        bssid = (uint8_t *)network->bssid;
    }
    if (network->ssid_specific != 0U)
    {
        ssid = network->ssid;
    }
#ifdef CONFIG_OWE
    if (network->owe_trans_mode == OWE_TRANS_MODE_OPEN)
    {
        ssid    = network->trans_ssid;
        channel = network->channel;
    }
#endif
    if (network->channel_specific != 0U)
    {
        channel = network->channel;
    }

    switch (network->role)
    {
        case WLAN_BSS_ROLE_STA:
            type = BSS_INFRASTRUCTURE;
            break;
        default:
            type = BSS_INFRASTRUCTURE;
            break;
    }

    wlan.sta_state = CM_STA_SCANNING;

    /* comment out this, need to check if 11d needs 3 times full channel scan */
    /*
    if (wrapper_wlan_11d_support_is_enabled() && wlan.scan_count < WLAN_11D_SCAN_LIMIT)
    {
        ret = wifi_send_scan_cmd((t_u8)g_wifi_scan_params.bss_type, g_wifi_scan_params.bssid, g_wifi_scan_params.ssid,
                                 NULL, 0, NULL, 0,
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
                                 0,
#endif
#ifdef CONFIG_SCAN_CHANNEL_GAP
                                 scan_channel_gap,
#endif
                                 false, false);
    }
    else
    */
    {
        if (channel != 0)
        {
            chan_list[0].chan_number = (t_u8)channel;
            chan_list[0].scan_type   = MLAN_SCAN_TYPE_ACTIVE;
            chan_list[0].scan_time   = 120;
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
            ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, 1, chan_list, 0, 0,
                                     scan_channel_gap,
                                     false, false);
#else
            ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, 1, chan_list, 0,
                                     scan_channel_gap,
                                     false, false);
#endif
        }
        else
        {
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
            ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, 0, NULL, 0, 0,
                                     scan_channel_gap,
                                     false, false);
#else
            ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, 0, NULL, 0,
                                     scan_channel_gap,
                                     false, false);
#endif
        }
    }
    if (ret != 0)
    {
        (void)wlan_wlcmgr_send_msg(WIFI_EVENT_SCAN_RESULT, WIFI_EVENT_REASON_FAILURE, NULL);
        wlcm_e("error: scan failed");
    }
    else
    {
        wlan.scan_count++;
    }
}

static void do_hidden_scan(struct wlan_network *network, uint8_t num_channels, wlan_scan_channel_list_t *chan_list)
{
    int ret;
    uint8_t *bssid = NULL;
    char *ssid     = NULL;
    IEEEtypes_Bss_t type;

    wlcm_d("initiating scan for hidden network \"%s\"", network->name);

    if (network->bssid_specific != 0U)
    {
        bssid = (uint8_t *)network->bssid;
    }
    if (network->ssid_specific != 0U)
    {
        ssid = network->ssid;
    }

    switch (network->role)
    {
        case WLAN_BSS_ROLE_STA:
            type = BSS_INFRASTRUCTURE;
            break;
        default:
            type = BSS_INFRASTRUCTURE;
            break;
    }

    wlan.sta_state = CM_STA_SCANNING;

#ifdef CONFIG_SCAN_WITH_RSSIFILTER
    ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, num_channels, chan_list, 0, 0,
                             scan_channel_gap,
                             false, true);
#else
    ret = wifi_send_scan_cmd((t_u8)type, bssid, ssid, NULL, num_channels, chan_list, 0,
                             scan_channel_gap,
                             false, true);
#endif
    if (ret != 0)
    {
        (void)wlan_wlcmgr_send_msg(WIFI_EVENT_SCAN_RESULT, WIFI_EVENT_REASON_FAILURE, NULL);
        wlcm_e("error: scan failed");
    }
}

static void do_connect_failed(enum wlan_event_reason reason);

#ifndef CONFIG_WPA_SUPP
/* Start a connection attempt.  To do this we choose a specific network to scan
 * for or the first of our list of known networks. If that network uses WEP
 * security, we first issue the WEP configuration command and enter the
 * CM_STA_CONFIGURING state, we'll get a response to this command which will
 * transition us to the CM_STA_SCANNING state.  Otherwise we issue a scan and
 * enter the CM_STA_SCANNING state now. */
static int do_connect(int netindex)
{


    /* try the specified network */
    if (wlan.networks[netindex].role != WLAN_BSS_ROLE_STA)
    {
        return -WM_E_INVAL;
    }

#ifdef CONFIG_OWE
    wlan.networks[netindex].owe_trans_mode = 0;
#endif
    wlan.cur_network_idx = netindex;
    wlan.scan_count      = 0;

    do_scan(&wlan.networks[netindex]);

    return WM_SUCCESS;
}
#endif

static int do_start(struct wlan_network *network)
{
    int ret;
    uint8_t active_chan_list[40];
    uint8_t active_num_chans = 0;
    wifi_scan_chan_list_t scan_chan_list;
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_uap_interface();
#else
    uint8_t i;
#endif

    if (network->role == WLAN_BSS_ROLE_UAP)
    {
        if (network->channel_specific == 0U)
        {
            network->channel = UAP_DEFAULT_CHANNEL;

            if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
            {
                network->channel = wlan.networks[wlan.cur_network_idx].channel;
#ifdef CONFIG_WPA_SUPP
            network->sec_channel_offset = wifi_get_sec_channel_offset(network->channel);
            if (network->channel == 14)
            {
                wpa_supp_set_ap_bw(netif, 1);
            }
#endif
            }
            else
            {
                if (!wlan_uap_scan_chan_list_set)
                {
                    wifi_get_active_channel_list(active_chan_list, &active_num_chans,
                                                 wlan.networks[wlan.cur_uap_network_idx].acs_band);

                    if (active_num_chans != 0U)
                    {
                        scan_chan_list.num_of_chan = active_num_chans;
                        (void)memcpy((void *)scan_chan_list.chan_number, (const void *)active_chan_list,
                                     active_num_chans);
                        wlan_uap_set_scan_chan_list(scan_chan_list);
                    }
                }
            }
        }
        else
        {
#ifdef CONFIG_11AC
            t_u8 bandwidth = wifi_uap_get_bandwidth();
            if (bandwidth == BANDWIDTH_80MHZ)
            {
                if ((wlan.networks[wlan.cur_uap_network_idx].acs_band == 0)
                        || ((wlan.networks[wlan.cur_uap_network_idx].acs_band == 1) && (!(network->wlan_capa & (WIFI_SUPPORT_11AX | WIFI_SUPPORT_11AC))))
                   )
                {
                    wlcm_e("uAP configured bandwidth not allowed");
                    CONNECTION_EVENT(WLAN_REASON_UAP_START_FAILED, NULL);
                    wlan.cur_uap_network_idx = -1;
                    return -WM_FAIL;
                }
            }
#endif
#ifdef CONFIG_WPA_SUPP
            network->sec_channel_offset = wifi_get_sec_channel_offset(network->channel);
            if (network->channel == 14)
            {
                wpa_supp_set_ap_bw(netif, 1);
            }
#else
            wifi_get_active_channel_list(active_chan_list, &active_num_chans,
                                                 wlan.networks[wlan.cur_uap_network_idx].acs_band);

            for (i = 0; i < active_num_chans; i++)
            {
                if (network->channel == active_chan_list[i])
                {
                    break;
                }
            }
            if (i == active_num_chans)
            {
                wlcm_e("uAP configured channel not allowed");
                CONNECTION_EVENT(WLAN_REASON_UAP_START_FAILED, NULL);
                wlan.cur_uap_network_idx = -1;
                return -WM_FAIL;
            }
#endif
        }

        wlcm_d("starting our own network");

        if (network->channel == 14)
        {
            wifi_uap_config_wifi_capa(WIFI_SUPPORT_LEGACY);
        }
        else
        {
            wifi_uap_config_wifi_capa(network->wlan_capa);
        }

#ifdef CONFIG_WPA_SUPP
        if (network->bssid_specific == 0U)
        {
            (void)memcpy(&network->bssid[0], &wlan.uap_mac[0], MLAN_MAC_ADDR_LENGTH);
        }

        t_u8 bandwidth = wifi_uap_get_bandwidth();

#if defined(SD8801) || defined(RW610)
        wpa_supp_set_ap_bw(netif, 1);
#else
        wpa_supp_set_ap_bw(netif, bandwidth);
#endif
        ret = wpa_supp_start_ap(netif, network, 0);
#else
        if (network->channel == 14)
        {
            wifi_uap_set_bandwidth(BANDWIDTH_20MHZ);
        }

        ret = wifi_uap_start((mlan_bss_type)network->type, network->ssid,
                             wlan.uap_mac,
                             (int)network->security.type, network->security.key_mgmt, &network->security.psk[0], &network->security.password[0],
                             (int)network->channel, wlan.scan_chan_list,
                             network->security.pwe_derivation,
                             network->security.transition_disable,
                             network->security.mfpc,
#ifdef CONFIG_WIFI_DTIM_PERIOD
                             network->security.mfpr, network->dtim_period
#else
                             network->security.mfpr
#endif
        );
#endif
        if (ret != WM_SUCCESS)
        {
            wlcm_e("uAP start failed, giving up");
            CONNECTION_EVENT(WLAN_REASON_UAP_START_FAILED, NULL);
            wlan.cur_uap_network_idx = -1;
            return -WM_FAIL;
        }

#ifdef CONFIG_WPA_SUPP
        if (ret == WM_SUCCESS)
        {
            wlan.connect        = false;
            wlan.status_timeout = 0;
            (void)os_timer_activate(&wlan.supp_status_timer);
        }
#endif

        wlan.uap_state = CM_UAP_CONFIGURED;
    }
    return WM_SUCCESS;
}

static int do_stop(struct wlan_network *network)
{
    int ret = WM_SUCCESS;
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_uap_interface();
#endif

    wlcm_d("stopping our own network");

    if (network->role == WLAN_BSS_ROLE_UAP)
    {
#ifdef CONFIG_WPA_SUPP
        ret = wpa_supp_stop_ap(netif, network);
#else
        ret = wifi_uap_stop();
#endif
        if (ret != 0)
        {
            wlcm_e("uAP stop failed, giving up");
            CONNECTION_EVENT(WLAN_REASON_UAP_STOP_FAILED, NULL);
            return -WM_FAIL;
        }
        wlan.uap_state = CM_UAP_INITIALIZING;
        wlan.cur_uap_network_idx = -1;
    }

    return WM_SUCCESS;
}

/* A connection attempt has failed for 'reason', decide whether to try to
 * connect to another network (in that case, tell the state machine to
 * transition to CM_STA_CONFIGURING to try that network) or finish attempting to
 * connect by releasing the scan lock and informing the user. */
static void do_connect_failed(enum wlan_event_reason reason)
{
#if defined(CONFIG_OWE) || defined(CONFIG_WPA2_ENTP)
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];
#endif

#ifdef CONFIG_WPA2_ENTP
    if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
    {
        wpa2_tls_cleanup(network, false);
    }
#endif
    if (wlan.connect_wakelock_taken)
    {
#ifdef CONFIG_HOST_SLEEP
        wakelock_put();
#endif
        wlan.connect_wakelock_taken = false;
    }

#ifdef CONFIG_OWE
    if (network->trans_ssid_specific && network->trans_ssid_len)
    {
        (void)memset(&network->trans_ssid, 0x00, sizeof(network->trans_ssid));
        network->trans_ssid_len = 0;
    }
#endif

    wlcm_d("connecting to \"%s\" failed", wlan.networks[wlan.cur_network_idx].name);

    if (wlan.sta_state == CM_STA_SCANNING_USER)
    {
        wlan.sta_return_to = CM_STA_IDLE;
    }

    wlan.sta_state = CM_STA_IDLE;
    CONNECTION_EVENT(reason, NULL);
}

static void report_scan_results(void)
{
    unsigned int count;
    if (wlan.scan_cb != NULL)
    {
        if (wifi_get_scan_result_count(&count) != WM_SUCCESS)
        {
            count = 0;
        }
        (void)wlan.scan_cb(count);
        wlan.scan_cb = NULL;
    }
}

static void update_network_params(struct wlan_network *network, const struct wifi_scan_result2 *res)
{
    if (!network->security_specific)
    {
        /* Wildcard: If wildcard security is specified, copy the highest
         * security available in the scan result to the configuration
         * structure
         */
        enum wlan_security_type t = WLAN_SECURITY_NONE;
        int key_mgmt = WLAN_KEY_MGMT_NONE;

        if ((res->WPA_WPA2_WEP.wpa3_sae != 0U) && (res->WPA_WPA2_WEP.wpa2 != 0U))
        {
            t = WLAN_SECURITY_WPA2_WPA3_SAE_MIXED;
            key_mgmt = WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_SAE;
        }
        else if (res->WPA_WPA2_WEP.wpa3_sae != 0U)
        {
            t = WLAN_SECURITY_WPA3_SAE;
            key_mgmt = WLAN_KEY_MGMT_SAE;
        }
        else if (res->WPA_WPA2_WEP.wpa2 != 0U)
        {
            t = WLAN_SECURITY_WPA2;
            key_mgmt = WLAN_KEY_MGMT_PSK;
        }
        else if (res->WPA_WPA2_WEP.wpa != 0U)
        {
            t = WLAN_SECURITY_WPA_WPA2_MIXED;
            key_mgmt = WLAN_KEY_MGMT_PSK;
        }
        else if (res->WPA_WPA2_WEP.wepStatic != 0U)
        {
            t = WLAN_SECURITY_WEP_OPEN;
        }
#ifdef CONFIG_OWE
        else if (res->WPA_WPA2_WEP.wpa2 && res->WPA_WPA2_WEP.owe)
        {
            t = WLAN_SECURITY_OWE_ONLY;
            key_mgmt = WLAN_KEY_MGMT_OWE;
        }
#endif
        else
        {
            t = WLAN_SECURITY_NONE;
            key_mgmt = WLAN_KEY_MGMT_NONE;
        }

        network->security.type = t;
        network->security.key_mgmt = key_mgmt;

        if ((network->security.type == WLAN_SECURITY_WPA2) || (network->security.type == WLAN_SECURITY_WPA3_SAE) || (network->security.type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED))
        {
            network->security.mfpr = 0;
            (void)wlan_set_pmfcfg((t_u8)network->security.mfpc, (t_u8)network->security.mfpr);
        }
    }

    network->dot11n = res->phtcap_ie_present;

#ifdef CONFIG_11AC
    network->dot11ac = res->pvhtcap_ie_present;
#endif
#ifdef CONFIG_11AX
    network->dot11ax = res->phecap_ie_present;
#endif

#ifdef CONFIG_11R

    network->mdid = res->mdid;

    if (res->WPA_WPA2_WEP.ft_1x != 0U)
    {
        network->ft_1x = 1;
    }
    else if (res->WPA_WPA2_WEP.ft_psk != 0U)
    {
        network->ft_psk = 1;
    }
    else if (res->WPA_WPA2_WEP.ft_sae != 0U)
    {
        network->ft_sae = 1;
    }
    else
    {
        /* Do nothing */
    }
#endif

    /* We have a match based on the criteria we checked, update the known
     * network with any additional information that we got from the scan but
     * did not know before */
    if (!network->channel_specific)
    {
        network->channel = res->Channel;
    }
    if (!network->bssid_specific)
    {
        (void)memcpy((void *)network->bssid, (const void *)res->bssid, MLAN_MAC_ADDR_LENGTH);
    }
    if (!network->ssid_specific)
    {
        (void)memcpy((void *)network->ssid, (const void *)res->ssid, (size_t)res->ssid_len);
    }

    network->beacon_period = res->beacon_period;
    network->dtim_period   = res->dtim_period;
#ifdef CONFIG_OWE
    network->owe_trans_mode = res->trans_mode;

    if (res->trans_mode == OWE_TRANS_MODE_OPEN)
    {
        (void)memset(&network->trans_ssid, 0x00, sizeof(network->trans_ssid));
        (void)memcpy((void *)network->trans_ssid, (const void *)res->trans_ssid, res->trans_ssid_len);
        network->trans_ssid_len = res->trans_ssid_len;
    }
#endif

#ifdef CONFIG_11K
    if (res->neighbor_report_supported == true)
    {
        network->neighbor_report_supported = true;
    }
    else
    {
        network->neighbor_report_supported = false;
    }
#endif

#ifdef CONFIG_11V
    if (res->bss_transition_supported == true)
    {
        network->bss_transition_supported = true;
    }
    else
    {
        network->bss_transition_supported = false;
    }
#endif

    network->security.is_pmf_required = res->is_pmf_required;

    switch (network->security.type)
    {
        case WLAN_SECURITY_WPA:
            network->security.mcstCipher.tkip = res->wpa_mcstCipher.tkip;
            network->security.ucstCipher.tkip = res->wpa_ucstCipher.tkip;
            network->security.mcstCipher.ccmp = res->wpa_mcstCipher.ccmp;
            network->security.ucstCipher.ccmp = res->wpa_ucstCipher.ccmp;
            break;
        case WLAN_SECURITY_WPA2:
        case WLAN_SECURITY_WPA_WPA2_MIXED:
#ifdef CONFIG_WPA2_ENTP
        case WLAN_SECURITY_EAP_TLS:
        case WLAN_SECURITY_EAP_PEAP_MSCHAPV2:
#endif
            network->security.mcstCipher.ccmp = res->rsn_mcstCipher.ccmp;
            network->security.ucstCipher.ccmp = res->rsn_ucstCipher.ccmp;
            if (!res->rsn_mcstCipher.ccmp)
            {
                network->security.mcstCipher.tkip = res->rsn_mcstCipher.tkip;
            }
            if (!res->rsn_ucstCipher.ccmp)
            {
                network->security.ucstCipher.tkip = res->rsn_ucstCipher.tkip;
            }
            if (!res->rsn_mcstCipher.tkip && !res->rsn_ucstCipher.tkip && !res->rsn_mcstCipher.ccmp &&
                !res->rsn_ucstCipher.ccmp)
            {
                network->security.mcstCipher.ccmp = res->wpa_mcstCipher.ccmp;
                network->security.ucstCipher.ccmp = res->wpa_ucstCipher.ccmp;
                if (!res->wpa_mcstCipher.ccmp)
                {
                    network->security.mcstCipher.tkip = res->wpa_mcstCipher.tkip;
                }
                if (!res->wpa_ucstCipher.ccmp)
                {
                    network->security.ucstCipher.tkip = res->wpa_ucstCipher.tkip;
                }
            }
            break;
        case WLAN_SECURITY_NONE:
            break;
        default:
            wlcm_d("Unexpected security nw param");
            break;
    }
}

static int start_association(struct wlan_network *network, struct wifi_scan_result2 *res)
{
    int ret                     = WM_SUCCESS;
    unsigned int owe_trans_mode = 0;
    bool is_ft                  = false;

    wlcm_d("starting association to \"%s\"", network->name);
    wlan.roam_reassoc = false;
    ret               = configure_security(network, res);
    if (ret != 0)
    {
        wlcm_d("setting security params failed");
        do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);
        return -WM_FAIL;
    }
#ifdef CONFIG_OWE
    owe_trans_mode = res->trans_mode;
#endif
#ifdef CONFIG_11R
    is_ft       = wlan.ft_bss;
    wlan.ft_bss = false;
#endif

    ret = wrapper_wifi_assoc(res->bssid, (int)network->security.type, (bool)network->security.ucstCipher.tkip,
                             owe_trans_mode, is_ft);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("association failed");
        do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);
        return -WM_FAIL;
    }

    return ret;
}

#ifdef CONFIG_11V
static void wlan_send_btm_response(t_u8 *bssid, enum wnm_btm_status_code status)
{
    wlan_send_mgmt_wnm_btm_resp(wlan.nlist_rep_param.dialog_token, status, wlan.nlist_rep_param.dst_addr, wlan.sta_mac,
                                bssid, NULL, 0, wlan.nlist_rep_param.protect);

    memset(&wlan.nlist_rep_param, 0x00, sizeof(wlan_nlist_report_param));
}
#endif

static void handle_scan_results(void)
{
    unsigned int count;
    int ret;
    unsigned int i;
    struct wifi_scan_result2 *res;
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];
    bool matching_ap_found       = false;
    uint8_t num_channels         = 0;
    wlan_scan_channel_list_t chan_list[40];

    /* comment out this, need to check if 11d needs 3 times full channel scan */
    /*
    if (wrapper_wlan_11d_support_is_enabled() && wlan.scan_count < WLAN_11D_SCAN_LIMIT)
    {
        wlcm_d("11D enabled, re-scanning");
        do_scan(network);
        return;
    }
    */

    /*
     * We need an allocation here because the lower layer puts all the
     * results into the same global buffer. Hence, we need a private
     * copy. fixme: Can be removed after this issue is fixed in the
     * lower layer.
     */
    struct wifi_scan_result2 *best_ap = os_mem_alloc(sizeof(struct wifi_scan_result2));
    if (best_ap == NULL)
    {
        wlcm_d("%s: Failed to alloc scan result object", __func__);
        return;
    }

    /* We're associating unless an error occurs, in which case we make a
     * decision to rescan (transition to CM_STA_SCANNING) or fail
     * (transition to CM_STA_IDLE or a new connection attempt) */
    wlan.sta_state = CM_STA_ASSOCIATING;

    ret = wifi_get_scan_result_count(&count);
    if (ret != 0)
    {
        count = 0;
    }

    /* 'count' scan results available, is our network there? */
    for (i = 0; i < count; i++)
    {
        ret = wifi_get_scan_result(i, &res);
        if (ret == WM_SUCCESS)
        {
            ret = network_matches_scan_result(network, res, &num_channels, chan_list);
            if (ret == WM_SUCCESS)
            {
                if (!matching_ap_found)
                {
                    /* First matching AP found */
                    (void)memcpy((void *)best_ap, (const void *)res, sizeof(struct wifi_scan_result2));
                    matching_ap_found = true;
                    /*
                     * Continue the search. There may be an AP
                     * with same name but better RSSI.
                     */
                    continue;
                }

                wlcm_d("RSSI: Best AP=%d Result AP=%d", best_ap->RSSI, res->RSSI);
                if (best_ap->RSSI > res->RSSI)
                {
                    /*
                     * We found a network better that current
                     * best_ap
                     */
                    wlcm_d("Found better AP %s on channel %d", res->ssid, res->Channel);
                    /* Assign the new found as curr_best */
                    (void)memcpy((void *)best_ap, (const void *)res, sizeof(struct wifi_scan_result2));
                }

                /* Continue the search */
            }
        }
    }

    if (matching_ap_found)
    {
        if (wlan.roam_reassoc == true)
        {
            if (memcmp((const void *)network->bssid, (const void *)best_ap->bssid, (size_t)IEEEtypes_ADDRESS_SIZE) == 0)
            {
#ifdef CONFIG_11V
                if (wlan.nlist_rep_param.nlist_mode == WLAN_NLIST_11V)
                {
                    wlan_send_btm_response(NULL, WNM_BTM_REJECT_NO_SUITABLE_CANDIDATES);
                }
#endif
                wlan.sta_state    = CM_STA_CONNECTED;
                wlan.roam_reassoc = false;
#ifdef CONFIG_11R
                wlan.ft_bss = false;
#endif
                os_mem_free((void *)best_ap);
                return;
            }
#ifdef CONFIG_11V
            if (wlan.nlist_rep_param.nlist_mode == WLAN_NLIST_11V)
            {
                wlan_send_btm_response(best_ap->bssid, WNM_BTM_ACCEPT);
            }
#endif
        }

        wlan.same_ess = false;

#ifdef CONFIG_11R
        if ((wlan.ft_bss == true) && (network->mdid == best_ap->mdid))
        {
            wlan.same_ess = true;
        }
#endif
        wlan.same_ess |= wlan.roam_reassoc;

        update_network_params(network, best_ap);
#ifdef CONFIG_OWE
        if (network->owe_trans_mode == OWE_TRANS_MODE_OPEN)
        {
            wlcm_d("do scan for OWE Transition SSID: %s", network->trans_ssid);
            os_mem_free((void *)best_ap);
            do_scan(network);
            return;
        }
        else
        {
#endif
            ret = start_association(network, best_ap);
            if (ret == WM_SUCCESS)
            {
                os_mem_free((void *)best_ap);
                return;
            }
#ifdef CONFIG_OWE
        }
#endif
    }
    else if (num_channels != 0U)
    {
        os_mem_free((void *)best_ap);
        wlan.hidden_scan_on = true;
        do_hidden_scan(network, num_channels, chan_list);
        return;
    }
    else
    {
        /* Do Nothing */
    }

    os_mem_free((void *)best_ap);

    if (wlan.roam_reassoc == true)
    {
        wlan.sta_state    = CM_STA_CONNECTED;
        wlan.roam_reassoc = false;
#ifdef CONFIG_11R
        wlan.ft_bss = false;
#endif
        return;
    }

#ifdef RW610
    /* If reset is in process, skip re-scan */
    if (os_mutex_get(&reset_lock, 0) != WM_SUCCESS)
    {
        (void)PRINTF("skip re-scan when reset is in process\r\n");
        return;
    }
    os_mutex_put(&reset_lock);
#endif

    /* We didn't find our network in the scan results set: rescan if we
     * have rescan attempts remaining, otherwise give up.
     */
    if (wlan.scan_count < WLAN_RESCAN_LIMIT)
    {
        wlcm_d("network not found, re-scanning");
        wlan.hidden_scan_on = false;
        do_scan(network);
    }
    else
    {
        wlcm_d("rescan limit exceeded, giving up");
        do_connect_failed(WLAN_REASON_NETWORK_NOT_FOUND);

        if (wlan.reassoc_control)
        {
            wlcm_request_reconnect(&wlan.sta_state, network);
        }
    }
}

static void wlan_disable_power_save(int action)
{
    switch (action)
    {
        case WLAN_DEEP_SLEEP:
            wlcm_d("stopping deep sleep ps mode");
            (void)wifi_exit_deepsleep_power_save();
            break;
        case WLAN_IEEE:
            wlcm_d("stopping IEEE ps mode");
            (void)wifi_exit_ieee_power_save();
            break;
        case WLAN_WNM:
            wlcm_d("stopping WNM ps mode");
            (void)wifi_exit_wnm_power_save();
            break;
        default:
            wlcm_d("Unexpected disable ps action");
            break;
    }
}

static void wlan_enable_power_save(int action)
{
    switch (action)
    {
        case WLAN_DEEP_SLEEP:
            wlcm_d("starting deep sleep ps mode");
            (void)wifi_enter_deepsleep_power_save();
            break;
        case WLAN_IEEE:
            wlcm_d("starting IEEE ps mode");
            (void)wifi_enter_ieee_power_save();
            break;
        case WLAN_WNM:
            wlcm_d("starting WNM ps mode");
            (void)wifi_enter_wnm_power_save(wlan.wnm_sleep_time);
            break;
        default:
            wlcm_d("Unexpected ps mode");
            break;
    }
}

static void wlcm_process_sleep_event(void)
{
    wlan_send_sleep_confirm();
}

static void wlcm_process_ieeeps_event(struct wifi_message *msg)
{
    ENH_PS_MODES action = (ENH_PS_MODES)(*((uint32_t *)msg->data));
    wlcm_d("got msg data :: %x", action);
    os_mem_free(msg->data);

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        if (action == EN_AUTO_PS)
        {
            if (!wlan.cm_ieeeps_configured)
            {
                CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_IEEE);
                wlan.cm_ieeeps_configured = true;
            }
        }
        else if (action == DIS_AUTO_PS)
        {
            wlan.cm_ieeeps_configured = false;
            CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_IEEE);
        }
        else if (action == SLEEP_CONFIRM)
        {
        }
        else
        { /* Do Nothing */
        }
    }
}

static void wlcm_process_deepsleep_event(struct wifi_message *msg, enum cm_sta_state *next)
{
    ENH_PS_MODES action = (ENH_PS_MODES)(*((uint32_t *)msg->data));
#ifdef CONFIG_WIFI_PS_DEBUG
    wlcm_d("got msg data :: %x", action);
#endif
    os_mem_free(msg->data);

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        if (action == EN_AUTO_PS)
        {
            if(!wlan.cm_deepsleepps_configured)
            {
                CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_DEEP_SLEEP);
                wlan.cm_deepsleepps_configured = true;
            }
        }
        else if (action == DIS_AUTO_PS)
        {
            wlan.cm_deepsleepps_configured = false;
            // CONNECTION_EVENT(WLAN_REASON_INITIALIZED, NULL);
            /* Skip ps-exit event for the first time
               after waking from PM4+DS. This will ensure
               that we do not send ps-exit event until
               wlan-init event has been sent */
            CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_DEEP_SLEEP);
        }
        else if (action == SLEEP_CONFIRM)
        {
        }
        else
        { /* Do Nothing */
        }
    }
}

static void wlcm_process_wnmps_event(struct wifi_message *msg)
{
    uint16_t action                      = (uint16_t)(uint32_t)msg->data;
    wnm_sleep_result_t *wnm_sleep_result = (wnm_sleep_result_t *)&action;

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        if ((wnm_sleep_result->action == 0) && (wnm_sleep_result->result == 0))
        {
            wlcm_d("WNM enable success event: action %x result %x", wnm_sleep_result->action, wnm_sleep_result->result);
            if (!wlan.cm_wnmps_configured)
            {
                CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_WNM);
                wlan.cm_wnmps_configured = true;
            }
        }
        else if ((wnm_sleep_result->action == 0) && (wnm_sleep_result->result == 1))
        {
            wlcm_d("WNM enable fail event: action %x result %x", wnm_sleep_result->action, wnm_sleep_result->result);
            wlan.cm_wnmps_configured = false;
        }
        else if (action == DIS_WNM_PS)
        {
            wlcm_d("WNM disable success event");
            wlan.cm_wnmps_configured = false;
            CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_WNM);
        }
        else
        {
            /* Do nothing */
        }
    }
}

#define WL_ID_STA_DISCONN "sta_disconnected"

/* fixme: duplicated from legacy. Needs to be removed later. */
#define IEEEtypes_REASON_MIC_FAILURE          14U
#define IEEEtypes_REASON_4WAY_HANDSHK_TIMEOUT 15
#define WPA2_ENTERPRISE_FAILED                0xFF

static void wlcm_process_scan_result_event(struct wifi_message *msg, enum cm_sta_state *next)
{
    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        wifi_scan_process_results();
    }

    if (wlan.sta_state == CM_STA_SCANNING)
    {
        if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
        {
            handle_scan_results();
        }
        *next = wlan.sta_state;
        wlcm_d("SM: returned to %s", dbg_sta_state_name(*next));
        wlcm_d("releasing scan lock (connect scan)");
    }
    else if (wlan.sta_state == CM_STA_SCANNING_USER)
    {
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11K
        if (wlan.enable_11k == 1U)
        {
            wifi_scan_done(msg);
        }
#endif
#endif
        if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
        {
            report_scan_results();
        }
        *next = wlan.sta_return_to;
        wlcm_d("SM: returned to %s", dbg_sta_state_name(*next));
        wlcm_d("releasing scan lock (user scan)");
    }
    else
    {
#ifdef CONFIG_WPA_SUPP
        if (wlan.is_scan_lock)
        {
            wlcm_d("releasing scan lock (connect scan)");
            (void)os_semaphore_put(&wlan.scan_lock);
            wlan.is_scan_lock = 0;
        }

        wifi_scan_done(msg);
        return;
#else
        if (wlan.roam_reassoc == true)
        {
            if (wlan.sta_state == CM_STA_CONNECTED)
            {
                wlcm_d("SM: returned to %s", dbg_sta_state_name(*next));
                handle_scan_results();
                *next = wlan.sta_state;
                return;
            }
        }
#endif
    }

    (void)os_semaphore_put(&wlan.scan_lock);
    wlan.is_scan_lock = 0;
}

static void wlcm_process_sta_addr_config_event(struct wifi_message *msg,
                                               enum cm_sta_state *next,
                                               struct wlan_network *network)
{
    /* We have a response to our configuration request from the TCP stack.
     * If we configured the stack with a static IP address and this was
     * successful, we are effectively connected so we can report success
     * and proceed to CM_STA_CONNECTED.  If we configured the stack with
     * DHCP and the response is successful then the TCP stack is trying to
     * obtain an address for us and we should proceed to the
     * CM_STA_OBTAINING_ADDRESS state and wait for the
     * WIFI_EVENT_DHCP_CONFIG event,
     * which will tell us whether or not the DHCP address was
     * obtained.  Otherwise, if we got an unsuccessful response then we
     * must report a connection error.
     *
     * This event is only relevant if we are connecting and have requested
     * a TCP stack configuration (that is, we are in the
     * CM_STA_REQUESTING_ADDRESS state).  Otherwise, we ignore it. */

    if (!is_state(CM_STA_REQUESTING_ADDRESS))
    {
        if (wlan.connect_wakelock_taken)
        {
#ifdef CONFIG_HOST_SLEEP
            wakelock_put();
#endif
            wlan.connect_wakelock_taken = false;
        }
        wlcm_d("ignoring TCP configure response");
        return;
    }
    if (msg->reason != WIFI_EVENT_REASON_SUCCESS)
    {
        do_connect_failed(WLAN_REASON_ADDRESS_FAILED);
        *next = wlan.sta_state;
        return;
    }
    void *if_handle = NULL;
    switch (network->ip.ipv4.addr_type)
    {
        case ADDR_TYPE_STATIC:
            net_configure_dns((struct net_ip_config *)&network->ip, network->role);
            if (network->type == WLAN_BSS_TYPE_STA)
            {
                if_handle = net_get_mlan_handle();
            }
            (void)net_get_if_addr((struct net_ip_config *)&network->ip, if_handle);
            wlan.sta_state = CM_STA_CONNECTED;
            if (wlan.connect_wakelock_taken)
            {
#ifdef CONFIG_HOST_SLEEP
                wakelock_put();
#endif
                wlan.connect_wakelock_taken = false;
            }
            *next                       = CM_STA_CONNECTED;
            wlan.sta_ipv4_state         = CM_STA_CONNECTED;
                if (wlan.reassoc_control && wlan.reassoc_request)
                {
                    wlan.reassoc_count   = 0;
                    wlan.reassoc_request = false;
                }
            mlan_adap->skip_dfs = false;
            CONNECTION_EVENT(WLAN_REASON_SUCCESS, NULL);
            break;
        case ADDR_TYPE_DHCP:
        case ADDR_TYPE_LLA:
            *next               = CM_STA_OBTAINING_ADDRESS;
            wlan.sta_ipv4_state = CM_STA_OBTAINING_ADDRESS;
            break;
        default:
            wlcm_d("Unexpected addr type");
            break;
    } /* end of switch */
#ifdef CONFIG_IPV6
    /* Set the ipv6 state to obtaining address */
    wlan.sta_ipv6_state = CM_STA_OBTAINING_ADDRESS;
#endif
}

static void wlcm_process_channel_switch_ann(enum cm_sta_state *next, struct wlan_network *network)
{
    if (!wifi_is_ecsa_enabled())
    {
        if (is_state(CM_STA_CONNECTED))
        {
            wlcm_d("Sending deauth because of channel switch");
            set_event_chanswann();
            (void)wifi_deauthenticate((uint8_t *)network->bssid);
            /*
              This function call is already present in
              wlan_11h_handle_event_chanswann(). Remove it from here when
              that function is used directly.
            */
            wrapper_wlan_11d_clear_parsedtable();
            wrapper_clear_media_connected_event();
            clear_event_chanswann();
            wlan.sta_state = CM_STA_IDLE;
            *next          = CM_STA_IDLE;
            CONNECTION_EVENT(WLAN_REASON_CHAN_SWITCH, NULL);
        }
    }
}

#ifdef CONFIG_WPA_SUPP
enum mlan_channel_type wlan_get_chan_type(nxp_wifi_ch_switch_info chandef)
{
    switch (chandef.ch_width) {
    case CHAN_BAND_WIDTH_20_NOHT:
        return CHAN_NO_HT;
    case CHAN_BAND_WIDTH_20:
        return CHAN_HT20;
    case CHAN_BAND_WIDTH_40:
        if (chandef.center_freq1 > chandef.center_freq)
            return CHAN_HT40PLUS;
        return CHAN_HT40MINUS;
    default:

        return CHAN_NO_HT;
    }
}

int wlan_get_chan_offset(int width, int freq, int cf1, int cf2)
{
    int freq1 = 0;

    switch (width)
    {
        case CHAN_BAND_WIDTH_20_NOHT:
        case CHAN_BAND_WIDTH_20:
            return 0;
        case CHAN_BAND_WIDTH_40:
            freq1 = cf1 - 10;
            break;
        case CHAN_BAND_WIDTH_80:
            freq1 = cf1 - 30;
            break;
        case CHAN_BAND_WIDTH_160:
            freq1 = cf1 - 70;
            break;
        case CHAN_BAND_WIDTH_80P80:
            freq1 = cf1 - 30;
            break;
        default:
            /* FIXME: implement this */
            return 0;
    }

    return (abs(freq - freq1) / 20) % 2 == 0 ? 1 : -1;
}

static void wlcm_process_channel_switch_supp(struct wifi_message *msg)
{
    chan_band_info  pchan_band_info ;
    nxp_wifi_ch_switch_info chandef = {0,};
    t_u8 band = BAND_2GHZ;
    enum mlan_channel_type ch_type = CHAN_NO_HT;
    uint8_t bss_type = 0;
    pmlan_private pmpriv = NULL;
    wifi_ecsa_info *pchan_info = NULL;
    t_u8 channel= 0 ;
    const chan_freq_power_t *cfp = MNULL;
    mlan_adapter *pmadapter = NULL;

    if (wifi_is_ecsa_enabled())
    {
        if (msg->data != NULL)
        {
            memset(&pchan_band_info , 0, sizeof(chan_band_info));
            pchan_info = (wifi_ecsa_info *)msg->data;
            bss_type = pchan_info->bss_type;
            pmpriv = mlan_adap->priv[bss_type];
            pmadapter = pmpriv->adapter;
            channel= pchan_info->channel;

            if(is_uap_started())
            {
                wlan.networks[wlan.cur_uap_network_idx].channel = channel;
                pmpriv->uap_channel = channel;
        		pmpriv->uap_state_chan_cb.channel = channel;
        		pmpriv->uap_state_chan_cb.band_config = pchan_info->band_config;

                pchan_band_info.is_11n_enabled = pmpriv->is_11n_enabled;
            }

            if (is_sta_connected())
            {
                wlan.networks[wlan.cur_network_idx].channel = channel;
                wifi_set_curr_bss_channel(wlan.networks[wlan.cur_network_idx].channel);

#define MAX_CHANNEL_BAND_B 14
			if (channel <= MAX_CHANNEL_BAND_B)
				cfp = wlan_find_cfp_by_band_and_channel(pmadapter, BAND_B, channel);
#ifdef CONFIG_5GHz_SUPPORT
			else
				cfp = wlan_find_cfp_by_band_and_channel(pmadapter, BAND_A, channel);
#endif
			if (cfp)
				pmpriv->curr_bss_params.bss_descriptor.freq = cfp->freq;
			else
				pmpriv->curr_bss_params.bss_descriptor.freq = 0;
            }

            /* Handle Host-based DFS and non-DFS(normal uap) case */
            memcpy((t_u8 *)&pchan_band_info.bandcfg,(t_u8 *)&pchan_info->band_config, sizeof(pchan_info->band_config));
		    pchan_band_info.channel = channel;
#if defined(CONFIG_11AC)
		    if (pchan_band_info.bandcfg.chanWidth == CHAN_BW_80MHZ)
			pchan_band_info.center_chan = wlan_get_center_freq_idx(pmpriv, BAND_AAC,channel,CHANNEL_BW_80MHZ);
#endif

            /*Get freq and width info*/
            memset(&chandef,0, sizeof(nxp_wifi_ch_switch_info));
            chandef.center_freq2 = 0;

            if (pchan_band_info.bandcfg.chanBand == BAND_2GHZ)
                band = BAND_2GHZ;
            else if (pchan_band_info.bandcfg.chanBand == BAND_5GHZ)
                band = BAND_5GHZ;

            chandef.center_freq = channel_to_frequency(pchan_band_info.channel, band);

            switch (pchan_band_info.bandcfg.chanWidth)
            {
                case CHAN_BW_20MHZ:
                    if (pchan_band_info.is_11n_enabled)
                        chandef.ch_width = CHAN_BAND_WIDTH_20;
                    else
                        chandef.ch_width = CHAN_BAND_WIDTH_20_NOHT;
                    chandef.center_freq1 = chandef.center_freq;
                    break;

                case CHAN_BW_40MHZ:
                    chandef.ch_width = CHAN_BAND_WIDTH_40;
                    if (pchan_band_info.bandcfg.chan2Offset == SEC_CHAN_ABOVE)
                        chandef.center_freq1 = chandef.center_freq + 10;
                    else if (pchan_band_info.bandcfg.chan2Offset == SEC_CHAN_BELOW)
                        chandef.center_freq1 = chandef.center_freq - 10;
                    break;

#if defined(CONFIG_11AC)
                case CHAN_BW_80MHZ:
                    chandef.ch_width = CHAN_BAND_WIDTH_80;
                    chandef.center_freq1 = channel_to_frequency(pchan_band_info.center_chan, band);
                    break;
#endif

                default:
                    break;
            }

            /*Get type*/
            switch (chandef.ch_width)
            {
                case CHAN_BAND_WIDTH_20_NOHT:
                case CHAN_BAND_WIDTH_20:
                case CHAN_BAND_WIDTH_40:
                    ch_type = wlan_get_chan_type(chandef);
                    break;
                default:
                    break;
            }

            chandef.ht_enabled = 1;
            /*Get ht and ch_offset info*/
            switch (ch_type)
            {
                case CHAN_NO_HT:
                    chandef.ht_enabled = 0;
                    break;
                case CHAN_HT20:
                    break;
                case CHAN_HT40PLUS:
                    chandef.ch_offset = 1;
                    break;
                case CHAN_HT40MINUS:
                    chandef.ch_offset = -1;
                    break;
                default:
                    if (chandef.ch_width && chandef.center_freq1)
                    {
                        /* This can happen for example with VHT80 ch switch */
                        chandef.ch_offset = wlan_get_chan_offset(chandef.ch_width, chandef.center_freq, chandef.center_freq1, chandef.center_freq2 ? chandef.center_freq2 : 0);
                    }
                    else
                    {
                        PRINTF("Unknown secondary channel information - following channel definition calculations may fail\r\n");
                    }
                    break;
           }

            if(is_uap_started())
            {
                wm_wifi.supp_if_callbk_fns->ecsa_complete_callbk_fn(wm_wifi.hapd_if_priv, &chandef);
                (void)PRINTF("uap switch to channel %d success!\r\n", channel);
            }

            if (is_sta_connected())
            {
                wm_wifi.supp_if_callbk_fns->ecsa_complete_callbk_fn(wm_wifi.if_priv, &chandef);
                (void)PRINTF("sta switch to channel %d success!\r\n", channel);
            }

            os_mem_free((void *)msg->data);
        }

#ifdef CONFIG_ECSA
        wifi_put_ecsa_sem();
        set_ecsa_block_tx_flag(false);
#endif
    }
    else
    {
        wlcm_d("ECSA not support");
        if (msg->data != NULL)
            os_mem_free((void *)msg->data);
    }
}
#else
static void wlcm_process_channel_switch(struct wifi_message *msg)
{
    t_u8 channel= 0 ;
    wifi_ecsa_info *pchan_info = NULL;

    if (wifi_is_ecsa_enabled())
    {
        if (msg->data != NULL)
        {
            pchan_info = (wifi_ecsa_info *)msg->data;
            channel= pchan_info->channel;

            if(is_uap_started())
            {
                (void)PRINTF("uap switch to channel %d success!\r\n", channel);
                wlan.networks[wlan.cur_uap_network_idx].channel = channel;
            }

            if (is_sta_connected())
            {
                (void)PRINTF("sta switch to channel %d success!\r\n", channel);
                wlan.networks[wlan.cur_network_idx].channel = channel;
                wifi_set_curr_bss_channel(wlan.networks[wlan.cur_network_idx].channel);
            }
            os_mem_free((void *)msg->data);
        }

#ifdef CONFIG_ECSA
        wifi_put_ecsa_sem();
        set_ecsa_block_tx_flag(false);
#endif
    }
    else
    {
        wlcm_d("ECSA not support");
        if (msg->data != NULL)
            os_mem_free((void *)msg->data);
    }
}
#endif /*End of CONFIG_WPA_SUPP*/

#ifdef CONFIG_HOST_SLEEP
static void wlcm_process_hs_config_event(void)
{
    /* host sleep config done event received */
    int ret = WM_SUCCESS;
    unsigned int ipv4_addr = 0;
    enum wlan_bss_type type = WLAN_BSS_TYPE_STA;

    if(is_sta_ipv4_connected() != 0)
    {
        ret = wlan_get_ipv4_addr(&ipv4_addr);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("HS : Cannot get STA IP, check if STA disconnected");
            return;
        }
    }
    /* If uap interface is up
     * configure host sleep for uap interface
     * else confiugre host sleep for station
     * interface.
     */
    else if (is_uap_started() != 0)
    {
        ret = wlan_get_uap_ipv4_addr(&ipv4_addr);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("HS: Cannot get UAP IP, check if uAP stopped");
            return;
        }
        type = WLAN_BSS_TYPE_UAP;
    }
    else
        ipv4_addr = 0;

    (void)wifi_send_hs_cfg_cmd((mlan_bss_type)type, ipv4_addr, (uint16_t)HS_ACTIVATE, 0);
}
#endif

static void wlcm_process_addba_request(struct wifi_message *msg)
{
    if (is_state(CM_STA_ASSOCIATED) || is_state(CM_STA_REQUESTING_ADDRESS) || is_state(CM_STA_OBTAINING_ADDRESS) ||
        is_state(CM_STA_CONNECTED) || is_uap_started())
    {
        (void)wrapper_wlan_cmd_11n_addba_rspgen(msg->data);
    }
    else
    {
        wlcm_d("Ignore ADDBA Request event in disconnected state");
        os_mem_free((void *)msg->data);
    }
}

static void wlcm_process_delba_request(struct wifi_message *msg)
{
    if (is_state(CM_STA_ASSOCIATED) || is_state(CM_STA_REQUESTING_ADDRESS) || is_state(CM_STA_OBTAINING_ADDRESS) ||
        is_state(CM_STA_CONNECTED) || is_uap_started())
    {
        (void)wrapper_wlan_cmd_11n_delba_rspgen(msg->data);
    }
    else
    {
        wlcm_d("Ignore DELBA Request event in disconnected state");
        os_mem_free((void *)msg->data);
    }
}

static void wlcm_process_ba_stream_timeout_request(struct wifi_message *msg)
{
    if (is_state(CM_STA_ASSOCIATED) || is_state(CM_STA_REQUESTING_ADDRESS) || is_state(CM_STA_OBTAINING_ADDRESS) ||
        is_state(CM_STA_CONNECTED) || is_uap_started())
    {
        (void)wrapper_wlan_cmd_11n_ba_stream_timeout(msg->data);
    }
    else
    {
        wlcm_d(
            "Ignore BA STREAM TIMEOUT Request"
            " event in disconnected state");
        os_mem_free((void *)msg->data);
    }
}

static void wlcm_process_association_event(struct wifi_message *msg, enum cm_sta_state *next)
{
#ifdef CONFIG_WPA2_ENTP
    int ret;
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];
#endif

#ifdef CONFIG_WPA_SUPP
    if (wlan.is_scan_lock)
    {
      	wlcm_d("releasing scan lock (connect scan)");
       	(void)os_semaphore_put(&wlan.scan_lock);
       	wlan.is_scan_lock = 0;
    }
#endif

    /* We have received a response to the association command.  We may now
     * proceed to authenticating if it was successful, otherwise this
     * connection attempt has failed.
     *
     * This event is only relevant if we have sent an association command
     * while connecting (that is, we are in the CM_STA_ASSOCIATING state).
     * Otherwise, it is ignored. */

#ifndef CONFIG_WPA_SUPP
    if (!is_state(CM_STA_ASSOCIATING))
    {
        wlcm_d("ignoring association result event");
        return;
    }
#endif

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
        wlan.sta_state = CM_STA_ASSOCIATED;
        *next          = CM_STA_ASSOCIATED;

#ifdef CONFIG_WPA2_ENTP
        if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
        {
            ret = wpa2_ent_connect(network);
            if (ret != WM_SUCCESS)
            {
                wlcm_e("wpa2_ent_connect failed");
            }
        }
#endif
        wlan.scan_count = 0;
    }
#ifndef CONFIG_WPA_SUPP
    else if (wlan.scan_count < WLAN_RESCAN_LIMIT)
    {
        wlcm_d("association failed, re-scanning");
#ifdef CONFIG_WPA2_ENTP
        if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
        {
            wpa2_tls_cleanup(network, true);
        }
#endif
        /*
         *  this scan does not hold scan lock as it was already put by wlcmgr task
         *  need to check if need to hold scan lock again
         */
        do_scan(&wlan.networks[wlan.cur_network_idx]);
        *next = CM_STA_SCANNING;
    }
#endif
    else
    {
#ifdef CONFIG_WPA2_ENTP
        if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
        {
            wpa2_tls_cleanup(network, true);
        }
#endif
#ifdef CONFIG_WPA_SUPP
        os_timer_deactivate(&wlan.supp_status_timer);
        wlan.status_timeout = 0;
#endif

#ifndef CONFIG_WPA_SUPP
        do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);

        if (wlan.reassoc_control)
        {
            wlcm_request_reconnect(next, &wlan.networks[wlan.cur_network_idx]);
        }
#endif
        *next = wlan.sta_state;
    }
}

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_AUTO_RECONNECT

static void wlcm_process_association_notify_event(struct wifi_message *msg, enum cm_sta_state *next)
{
    struct netif *netif = net_get_sta_interface();

    (void)msg;
    (void)next;

    if (wlan.roam_reassoc == false)
    {
        (void)wpa_supp_notify_assoc(netif);
    }
}

#endif
#endif

static void wlcm_process_pmk_event(struct wifi_message *msg, enum cm_sta_state *next, struct wlan_network *network)
{
    char *bssid = network->bssid;

    if (msg->data != NULL)
    {
        network->security.pmk_valid = true;
        (void)memcpy((void *)network->security.pmk, (const void *)msg->data, WLAN_PMK_LENGTH);
        if (network->role == WLAN_BSS_ROLE_STA)
        {
#ifdef CONFIG_WPA2_ENTP
            if (network->security.type == WLAN_SECURITY_EAP_TLS)
            {
                /* OKC-802.1X case, roaming without specifying bssid */
                bssid = NULL;
            }
#endif
            (void)wifi_send_add_wpa_pmk((int)network->role, network->ssid, bssid, network->security.pmk,
                                        WLAN_PMK_LENGTH);
        }
    }
}

static void wlcm_process_authentication_event(struct wifi_message *msg,
                                              enum cm_sta_state *next,
                                              struct wlan_network *network)
{
#ifdef CONFIG_STA_AUTO_DHCPV4
    int ret         = 0;
#endif
    void *if_handle = NULL;
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

#ifdef CONFIG_WPS2
    if (wlan_get_prov_session() == PROV_WPS_SESSION_ATTEMPT)
    {
        if(wlan.connect_wakelock_taken)
        {
#ifdef CONFIG_HOST_SLEEP
            wakelock_put();
#endif
            wlan.connect_wakelock_taken = false;
        }
        return;
    }
#endif

    if (!is_state(CM_STA_ASSOCIATING) && !is_state(CM_STA_ASSOCIATED) && !is_state(CM_STA_REQUESTING_ADDRESS) &&
        !is_state(CM_STA_OBTAINING_ADDRESS) && !is_state(CM_STA_CONNECTED))
    {
        if (wlan.connect_wakelock_taken)
        {
#ifdef CONFIG_HOST_SLEEP
            wakelock_put();
#endif
            wlan.connect_wakelock_taken = false;
        }
        wlcm_d("ignoring authentication event");
        return;
    }

    if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
    {
            if (network->type == WLAN_BSS_TYPE_STA)
            {
                if_handle = net_get_mlan_handle();
            }
            CONNECTION_EVENT(WLAN_REASON_AUTH_SUCCESS, NULL);

#ifndef __ZEPHYR__
#ifdef SD9177
            os_timer_activate(&wlan.poll_timer);
#endif
#endif

            wlan.bgscan_attempt = 0;

#ifdef CONFIG_WPA_SUPP
            os_timer_deactivate(&wlan.supp_status_timer);
            wlan.status_timeout = 0;

            wpa_supp_network_status(netif, network);
#endif

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
            wlan.same_ess = wifi_same_ess_ft();
#endif
            wlan.roam_reassoc = false;
#endif
            if (wlan.same_ess == true)
            {
#ifdef CONFIG_11R
                wlan.ft_bss = false;
#endif
                (void)net_get_if_addr((struct net_ip_config *)&network->ip, if_handle);
                wlan.sta_state      = CM_STA_CONNECTED;
                *next               = CM_STA_CONNECTED;
                wlan.sta_ipv4_state = CM_STA_CONNECTED;

                if (wlan.reassoc_control && wlan.reassoc_request)
                {
                    wlan.reassoc_count   = 0;
                    wlan.reassoc_request = false;
                }
                mlan_adap->skip_dfs = false;
                CONNECTION_EVENT(WLAN_REASON_SUCCESS, NULL);
                return;
            }

#ifdef CONFIG_STA_AUTO_DHCPV4
            ret = net_configure_address((struct net_ip_config *)&network->ip, if_handle);
            if (ret != 0)
            {
                wlcm_e("Configure Address failed");
                do_connect_failed(WLAN_REASON_ADDRESS_FAILED);
                *next = wlan.sta_state;
            }
            else
            {
                *next               = CM_STA_REQUESTING_ADDRESS;
                wlan.sta_ipv4_state = CM_STA_REQUESTING_ADDRESS;
#ifdef CONFIG_IPV6
                wlan.sta_ipv6_state = CM_STA_REQUESTING_ADDRESS;
#endif
            }
#else
            *next               = CM_STA_AUTHENTICATED;
            wlan.sta_ipv4_state = CM_STA_AUTHENTICATED;
#ifdef CONFIG_IPV6
            wlan.sta_ipv6_state = CM_STA_AUTHENTICATED;
#endif
#endif

#ifdef CONFIG_WPA2_ENTP
        if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT &&
            (network->security.type != WLAN_SECURITY_EAP_PEAP_MSCHAPV2))
        {
            wpa2_tls_cleanup(network, false);
        }
#endif
    }
    else
    {
#ifdef CONFIG_WPA2_ENTP
        if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
        {
            wpa2_tls_cleanup(network, false);
        }
        else if (wlan_get_prov_session() == PROV_NON_SESSION_ATTEMPT &&
                 network->security.pmk_valid == true &&
                 (network->security.type == WLAN_SECURITY_EAP_TLS || network->security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
                )
        {
            /* If EAP_TLS re-connected but get auth failed, clear pmk_valid/pmk and enter "PROV_ENTP_SESSION_ATTEMPT" again */
            network->security.pmk_valid = false;
            memset(network->security.pmk, 0, WLAN_PMK_LENGTH);
        }
#endif
        if (*((uint16_t *)msg->data) == IEEEtypes_REASON_MIC_FAILURE)
        {
            wlan.assoc_paused = true;
            (void)os_timer_activate(&wlan.assoc_timer);
        }

        if (is_state(CM_STA_REQUESTING_ADDRESS) || is_state(CM_STA_OBTAINING_ADDRESS))
        {
            void *if_handle = NULL;
            /* On Link loss, we need to take down the interface. */
            if (network->type == WLAN_BSS_TYPE_STA)
            {
                if_handle = net_get_mlan_handle();
            }

            if (if_handle != NULL)
            {
                /* Forcefully stop dhcp on given interface.
                 * net_interface_dhcp_stop internally does nothing
                 * if dhcp client is not started.
                 */
                net_interface_dhcp_stop(if_handle);
                net_interface_down(if_handle);
            }
        }

#ifndef CONFIG_WPA_SUPP
        if (is_state(CM_STA_ASSOCIATED))
        {
            (void)wifi_deauthenticate((uint8_t *)network->bssid);
        }
#endif
        wlan.sta_return_to  = CM_STA_IDLE;
        wlan.sta_state      = CM_STA_IDLE;
        *next               = CM_STA_IDLE;
        wlan.sta_ipv4_state = CM_STA_IDLE;
#ifdef CONFIG_IPV6
        wlan.sta_ipv6_state = CM_STA_IDLE;
#endif

#ifndef CONFIG_WPA_SUPP
        do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);
#endif

        if (wlan.reassoc_control)
        {
            wlcm_request_reconnect(next, network);
        }

    }
}

#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
static void wlcm_process_rssi_low_event(struct wifi_message *msg, enum cm_sta_state *next, struct wlan_network *network)
{
    bool set_rssi_threshold = false;

#ifdef CONFIG_ROAMING
    if (wlan.roaming_enabled == true)
    {
        if (wlan.roam_reassoc == false)
        {
            wlan.roam_reassoc = true;
#ifdef CONFIG_11R
            wlan.ft_bss = false;
            if ((network->ft_psk | network->ft_1x | network->ft_sae) == 1U)
            {
                wlan.ft_bss = true;
            }
#endif
            int ret = wifi_config_bgscan_and_rssi(network->ssid);
            if (ret == WM_SUCCESS)
            {
                wlcm_d("bgscan config successful");
                return;
            }
            wlan.roam_reassoc = false;
            set_rssi_threshold = true;
        }
        else
        {
            wlcm_d("Roaming already in progress");
            (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
            return;
        }
    }
#endif /* CONFIG_ROAMING */

#ifdef CONFIG_11K
    if (network->neighbor_report_supported == true)
    {
        int ret;
        ret = wlan_host_11k_neighbor_req((const char *)network->ssid);
        if (ret == WM_SUCCESS)
        {
            wlcm_d("Sent 11K neighbor request");
            return;
        }
        set_rssi_threshold = true;
    }
#endif /* CONFIG_11K */

#ifdef CONFIG_11V
    if (network->bss_transition_supported == true)
    {
        int ret;
        ret = wlan_host_11v_bss_trans_query(0x10);
        if (ret == WM_SUCCESS)
        {
            wlcm_d("Sent 11V bss transition query");
            return;
        }
        set_rssi_threshold = true;
    }
#endif /* CONFIG_11V */

    if (set_rssi_threshold == true)
    {
        (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
    }
}
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V)
static void wlan_sort_nlist_channels(wlan_nlist_report_param *pnlist_rep_param)
{
    t_u8 i, j;

    /* Bubble sort */
    for (i = 0; i < pnlist_rep_param->num_channels; i++)
    {
        for (j = 1; j < pnlist_rep_param->num_channels - i; j++)
        {
            if ((t_u8)pnlist_rep_param->channels[j - 1] > (t_u8)pnlist_rep_param->channels[j])
            {
                SWAP_U8(pnlist_rep_param->channels[j - 1], pnlist_rep_param->channels[j]);
            }
        }
    }
}

#ifdef CONFIG_WPA_SUPP
int wlan_11k_roam()
{
    int ret;
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];
    wlan_nlist_report_param *pnlist_rep_param = (wlan_nlist_report_param *)&wlan.nlist_rep_param;
    t_u8 i;
    wlan_scan_params_v2_t params;
    struct netif *netif = net_get_sta_interface();

    if (is_state(CM_STA_IDLE))
    {
        (void)PRINTF("Station is not connected\r\n");
        return -WM_FAIL;
    }

    memset(&params, 0x00, sizeof(wlan_scan_params_v2_t));

    memcpy(params.ssid, network->ssid, strlen(network->ssid));
    params.is_ssid = 1;

    params.num_channels = pnlist_rep_param->num_channels;

    for (i = 0; i < pnlist_rep_param->num_channels; i++)
    {
        params.chan_list[i].chan_number = (t_u8)pnlist_rep_param->channels[i];
        params.chan_list[i].scan_type   = MLAN_SCAN_TYPE_ACTIVE;
        params.chan_list[i].scan_time   = 60;

    }

    ret = wpa_supp_roam(netif, NULL);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("wlan ft roam failed");
        return -WM_FAIL;
    }

    ret = wpa_supp_scan(netif, &params);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("wlan ft roam scan failed");
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}

static void wlcm_process_neighbor_list_report_event(struct wifi_message *msg,
                                                    enum cm_sta_state *next,
                                                    struct wlan_network *network)
{
    // unsigned int i;
    int ret;
    wlan_nlist_report_param *pnlist_rep_param = (wlan_nlist_report_param *)&wlan.nlist_rep_param;

    if (is_state(CM_STA_IDLE) || (pnlist_rep_param == NULL))
    {
        wlcm_d("ignoring neighbor list report event in idle state");
        return;
    }

#ifdef CONFIG_11K
    if (pnlist_rep_param->nlist_mode == WLAN_NLIST_11K)
    {
        wlan.neighbor_req = false;
        (void)os_timer_deactivate(&wlan.neighbor_req_timer);
    }
#endif

    wlan_sort_nlist_channels(pnlist_rep_param);

    ret = wlan_11k_roam();
    if (ret != WM_SUCCESS)
    {
        wlcm_e("11k roam failed");
    }

    memset(&wlan.nlist_rep_param, 0x00, sizeof(wlan_nlist_report_param));
}
#else
static void wlcm_process_neighbor_list_report_event(struct wifi_message *msg,
                                                    enum cm_sta_state *next,
                                                    struct wlan_network *network)
{
    unsigned int i;
    int ret;
    wlan_scan_channel_list_t chan_list[MAX_NUM_CHANS_IN_NBOR_RPT];
    t_u8 *bssid                               = NULL;
    wlan_nlist_report_param *pnlist_rep_param = (wlan_nlist_report_param *)msg->data;

    wlan.roam_reassoc = false;

    if (is_state(CM_STA_IDLE) || (pnlist_rep_param == NULL))
    {
        wlcm_d("ignoring neighbor list report event in idle state");
        return;
    }

#ifdef CONFIG_11K
    if (pnlist_rep_param->nlist_mode == WLAN_NLIST_11K)
    {
        wlan.neighbor_req = false;
        (void)os_timer_deactivate(&wlan.neighbor_req_timer);
    }
#endif

#ifdef CONFIG_11V
    if ((pnlist_rep_param->nlist_mode == WLAN_NLIST_11V) || (pnlist_rep_param->nlist_mode == WLAN_NLIST_11V_PREFERRED))
    {
        wlan.neighbor_req = false;
        (void)os_timer_deactivate(&wlan.neighbor_req_timer);
    }
#endif

    wlan_sort_nlist_channels(pnlist_rep_param);
    memcpy(&wlan.nlist_rep_param, pnlist_rep_param, sizeof(wlan_nlist_report_param));

#ifdef CONFIG_11V
    if (pnlist_rep_param->nlist_mode == WLAN_NLIST_11V_PREFERRED)
    {
        bssid = pnlist_rep_param->bssid;
    }
#endif

    for (i = 0; i < pnlist_rep_param->num_channels; i++)
    {
        chan_list[i].chan_number = (t_u8)pnlist_rep_param->channels[i];
        chan_list[i].scan_type   = MLAN_SCAN_TYPE_ACTIVE;
        chan_list[i].scan_time   = 60;
    }

#ifdef CONFIG_11R
    wlan.ft_bss = false;
    if ((network->ft_psk | network->ft_1x | network->ft_sae) == 1U)
    {
        wlan.ft_bss = true;
    }
#endif
    wlan.roam_reassoc = true;
    ret = wifi_send_scan_cmd((t_u8)BSS_INFRASTRUCTURE, bssid, network->ssid, NULL, pnlist_rep_param->num_channels,
                             chan_list, 0,
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
                             0,
#endif
                             scan_channel_gap,
                             false, false);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("neighbor list scan failed");
#ifdef CONFIG_11R
        wlan.ft_bss = false;
#endif
        wlan.roam_reassoc = false;
    }

    if (pnlist_rep_param != NULL)
    {
        os_mem_free((void *)pnlist_rep_param);
    }
}
#endif
#endif

#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
int wlan_ft_roam(const t_u8 *bssid, const t_u8 channel)
{
    int ret;
    wlan_scan_params_v2_t params;
    t_u8 curr_bss[MLAN_MAC_ADDR_LENGTH] = {0};

    struct netif *netif = net_get_sta_interface();

    if (is_state(CM_STA_IDLE))
    {
        (void)PRINTF("Station is not connected\r\n");
        return -WM_FAIL;
    }
    if (wlan.roam_reassoc == true)
    {
        (void)PRINTF("Roaming already in progress\r\n");
        return WM_SUCCESS;
    }

    wlan.roam_reassoc = false;

    memset(&params, 0x00, sizeof(wlan_scan_params_v2_t));

    if (bssid)
    {
        if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
        {
            memcpy(curr_bss, wlan.networks[wlan.cur_network_idx].bssid, MLAN_MAC_ADDR_LENGTH);
            if(memcmp(curr_bss, bssid, MLAN_MAC_ADDR_LENGTH) == 0)
            {
                (void)PRINTF("Already connected to this BSS. Skip roaming.\r\n");
                return WM_SUCCESS;
            }
        }
        memcpy(params.bssid, bssid, MLAN_MAC_ADDR_LENGTH);
        params.is_bssid = 1;
    }

    if (channel)
    {
        params.num_channels = 1;
        params.chan_list[0].chan_number = channel;
    }

    ret = wpa_supp_roam(netif, (t_u8 *)bssid);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("wlan ft roam failed");
        return -WM_FAIL;
    }

    ret = wpa_supp_scan(netif, &params);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("wlan ft roam scan failed");
        return -WM_FAIL;
    }

    wlan.roam_reassoc = true;

    (void)os_timer_activate(&wlan.ft_roam_timer);

    (void)PRINTF("Started FT Roaming...\r\n");

    return WM_SUCCESS;
}
#else
int wlan_ft_roam(const t_u8 *bssid, const t_u8 channel)
{
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];

    if (is_state(CM_STA_IDLE))
    {
        (void)PRINTF("Station is not connected\r\n");
        return -WM_FAIL;
    }

    if ((network->ft_psk | network->ft_1x | network->ft_sae) == 1U)
    {
        int ret;
        wlan_scan_channel_list_t chan_list;

        chan_list.chan_number = channel;
        chan_list.scan_type   = MLAN_SCAN_TYPE_ACTIVE;
        chan_list.scan_time   = 120;

        wlan.ft_bss       = true;
        wlan.roam_reassoc = true;
        ret               = wifi_send_scan_cmd((t_u8)BSS_INFRASTRUCTURE, bssid, network->ssid, NULL, 1, &chan_list, 0,
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
                                 0,
#endif
                                 scan_channel_gap,
                                 false, false);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("wlan ft roam scan failed");
            wlan.ft_bss       = false;
            wlan.roam_reassoc = false;
            return -WM_FAIL;
        }

        return WM_SUCCESS;
    }
    else
    {
        (void)PRINTF("Current associated AP do not support FT BSS transition\r\n");
    }

    return -WM_FAIL;
}
#endif
#endif

#ifdef CONFIG_ECSA
static int wlan_check_valid_channel_operclass(t_u8 channel, t_u8 oper_class)
{
    int ret = 0;
    mlan_ioctl_req req;
    mlan_ds_misc_cfg *misc = NULL;
    mlan_status status     = MLAN_STATUS_SUCCESS;

    (void)memset(&req, 0x00, sizeof(mlan_ioctl_req));

    misc = os_mem_alloc(sizeof(mlan_ds_misc_cfg));
    if (misc == NULL)
    {
        return -WM_FAIL;
    }

    req.bss_index                       = MLAN_BSS_ROLE_UAP;
    req.pbuf                            = (t_u8 *)misc;
    misc->sub_command                   = MLAN_OID_MISC_OPER_CLASS_CHECK;
    req.req_id                          = MLAN_IOCTL_MISC_CFG;
    req.action                          = MLAN_ACT_GET;
    misc->param.bw_chan_oper.oper_class = oper_class;
    misc->param.bw_chan_oper.channel    = channel;

    status = wlan_ops_uap_ioctl(mlan_adap, &req);
    if (status != MLAN_STATUS_SUCCESS)
    {
        PRINTM(MERROR, "Failed to get operclass\n");
        os_mem_free(misc);
        return -WM_FAIL;
    }

    os_mem_free(misc);

    return ret;
}

static int wlan_set_uap_ecsa_cfg(
    t_u8 block_tx, t_u8 oper_class, t_u8 channel, t_u8 switch_count, t_u8 band_width, t_u8 ecsa)
{
    mlan_private *pmpriv = (mlan_private *)mlan_adap->priv[1];
    bool block_tx_flag   = (1 == block_tx) ? true : false;

    if (wlan_11h_radar_detect_required(pmpriv, channel))
    {
        wlcm_e("Please set non-dfs channel");
        return -WM_FAIL;
    }

    if ((channel > MAX_CHANNELS_BG) && ISSUPP_NO5G(mlan_adap->fw_cap_ext))
    {
        wlcm_e("Not support 5G, please set 2G channel");
        return -WM_FAIL;
    }

    if (wlan_check_channel_by_region_table(pmpriv, channel) == MFALSE)
    {
        (void)PRINTF("uAP target channel not allowed\n\r");
        return -WM_FAIL;
    }

    if (is_uap_started() && (!is_sta_connected()))
    {
        if (oper_class)
        {
            if (wlan_check_valid_channel_operclass(channel, oper_class))
            {
                wlcm_e("Wrong channel switch parameters!");
                return -EINVAL;
            }
        }

        set_ecsa_block_tx_flag(block_tx_flag);

        if (0 != switch_count)
        {
            set_ecsa_block_tx_time(switch_count);
            return wifi_set_ecsa_cfg(block_tx, oper_class, channel, switch_count, band_width, ecsa);
        }
        else
        {
            return wifi_set_action_ecsa_cfg(block_tx, oper_class, channel, switch_count);
        }
    }
    else
    {
        wlcm_e("uap isn't up");
        return -WM_FAIL;
    }
}

static void wlan_switch_to_nondfs_channel(void)
{
    mlan_private *pmpriv = (mlan_private *)mlan_adap->priv[1];
    t_u8 uap_channel     = 0;
    t_u8 block_tx        = 1;
    t_u8 oper_class      = 0;
    t_u8 switch_count    = DEF_SWITCH_COUNT;
    t_u8 band_width      = 0;
    t_u8 ecsa            = MTRUE;

    if (is_uap_started())
    {
        uap_channel = (t_u8)wlan.networks[wlan.cur_uap_network_idx].channel;

        if (MTRUE == wlan_11h_radar_detect_required(pmpriv, uap_channel))
        {
            if (MLAN_STATUS_SUCCESS == wlan_get_non_dfs_chan(pmpriv, &uap_channel))
            {
                wlan_set_uap_ecsa_cfg(block_tx, oper_class, uap_channel, switch_count, band_width, ecsa);
            }
            else
            {
                return;
            }
        }
    }
}
#endif

static void wlcm_process_link_loss_event(struct wifi_message *msg,
                                         enum cm_sta_state *next,
                                         struct wlan_network *network)
{
    /* We're being informed about an asynchronous link loss (ex: beacon loss
     * counter detected that the AP is gone, security failure, etc). If we
     * were connected, we need to report this event and proceed to idle.
     * If we were in the middle of a connection attempt, we need to treat
     * this as a connection attempt failure via do_connect_fail() and
     * proceed accordingly.
     */
    if (is_state(CM_STA_IDLE))
    {
        wlcm_d("ignoring link loss event in idle state");
        return;
    }

    void *if_handle = NULL;
    /* On Link loss, we need to take down the interface. */
    if (network->type == WLAN_BSS_TYPE_STA)
    {
        if_handle = net_get_mlan_handle();
    }

    if (if_handle != NULL)
    {
        /* Forcefully stop dhcp on given interface.
         * net_interface_dhcp_stop internally does nothing
         * if dhcp client is not started.
         */
        net_interface_dhcp_stop(if_handle);
        net_interface_down(if_handle);
    }

    /* If we were connected and lost the link, we must report that now and
     * return to CM_STA_IDLE
     */
    if (is_state(CM_STA_CONNECTED))
    {
        if (is_user_scanning() != 0)
        {
            wlan.sta_return_to = CM_STA_IDLE;
        }
        else
        {
            *next = CM_STA_IDLE;
        }
        wlan.sta_state      = CM_STA_IDLE;
        wlan.sta_ipv4_state = CM_STA_IDLE;
#ifdef CONFIG_IPV6
        wlan.sta_ipv6_state = CM_STA_IDLE;
#endif
        if ((int)msg->data == IEEEtypes_REASON_MIC_FAILURE)
        {
            /* In case of a LINK loss because of bad MIC
             * failure, directly send a deauth.
             */
            wlcm_d(
                "Sending deauth because of"
                " successive bad MIC failures");
            (void)wlan_disconnect();
            *next = CM_STA_IDLE;
        }

        CONNECTION_EVENT(WLAN_REASON_LINK_LOST, NULL);
#ifdef CONFIG_ECSA
        wrapper_clear_media_connected_event();
        wlan_switch_to_nondfs_channel();
#endif
    }
    else
    {
        /* Stop the dhcp timer first after link lost occurs, as the dhcp timer
         * callback may lead to that the connection state is out-of-sync with FW */
        net_stop_dhcp_timer();

        /* we were attempting a connection and lost the link,
         * so treat this as a connection attempt failure
         */
        switch ((int)msg->data)
        {
            case IEEEtypes_REASON_4WAY_HANDSHK_TIMEOUT:
                do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);
                break;
            default:
                do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);
                break;
        }
        *next = wlan.sta_state;
    }
#ifdef CONFIG_WPA2_ENTP
    if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
    {
        wpa2_tls_cleanup(network, false);
    }
#endif

#ifndef CONFIG_WPA_SUPP
    if (wlan.reassoc_control)
    {
        wlcm_request_reconnect(next, network);
    }
#endif
}


static void wlcm_process_disassoc_event(struct wifi_message *msg, enum cm_sta_state *next, struct wlan_network *network)
{
    /* We're being informed about an asynchronous disassociation from AP
     * As were in the middle of a connection attempt, we need to treat
     * this as a connection attempt failure via do_connect_fail() and
     * proceed accordingly.
     */
#ifdef CONFIG_WPA2_ENTP
    if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
    {
        wpa2_tls_cleanup(network, false);
    }
    else if (wlan_get_prov_session() == PROV_NON_SESSION_ATTEMPT && is_state(CM_STA_CONNECTED) &&
             network->security.pmk_valid == true &&
             (network->security.type == WLAN_SECURITY_EAP_TLS || network->security.type == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
            )
    {
        /* Connects with security EAP_TLS, if AP reset PMK and send disassoc, STA clear pmk_valid/pmk and enter "PROV_ENTP_SESSION_ATTEMPT" again */
        network->security.pmk_valid = false;
        memset(network->security.pmk, 0, WLAN_PMK_LENGTH);
    }
#endif
    if (is_user_scanning() != 0)
    {
        wlan.sta_return_to = CM_STA_IDLE;
    }
    *next          = CM_STA_IDLE;
    wlan.sta_state = CM_STA_IDLE;

    do_connect_failed(WLAN_REASON_NETWORK_AUTH_FAILED);

    if (wlan.reassoc_control)
    {
        wlcm_request_reconnect(next, network);
    }
}

static void wlcm_process_deauthentication_event(struct wifi_message *msg,
                                                enum cm_sta_state *next,
                                                struct wlan_network *network)
{
#ifdef CONFIG_WPA2_ENTP
    if (wlan_get_prov_session() == PROV_ENTP_SESSION_ATTEMPT)
    {
        wpa2_tls_cleanup(network, false);
    }
#endif
#ifdef CONFIG_WPA_SUPP
    if (network->security.type == WLAN_SECURITY_WPA3_SAE &&
        (msg->reason == WLAN_REASON_PREV_AUTH_NOT_VALID ||
        msg->reason == WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY ||
        msg->reason == WLAN_REASON_INVALID_IE))
    {
        /*
         *  Clear pmksa cache in case AP wants to redo sae auth.
         *  But send successful assoc resp and send deauth right after.
         *  Then we will always using pmksa cache if it exists.
         */
        wlan_pmksa_flush();
    }
#endif
}

static void wlcm_process_net_dhcp_config(struct wifi_message *msg,
                                         enum cm_sta_state *next,
                                         struct wlan_network *network)
{
    /* We have received a response from the embedded DHCP client.  If
     * successful, we now have a DHCP lease and can update our IP address
     * information and procceed to the CM_STA_CONNECTED state, otherwise we
     * failed to obtain a DHCP lease and report that we failed to connect.
     *
     * This event is only relevant if we are attempting a connection and
     * are in the CM_STA_OBTAINING_ADDRESS state (due to configuring the TCP
     * stack with DHCP), otherwise we ignore it. */

    void *if_handle = NULL;
    // wakelock_put(WL_ID_CONNECT);
    // wlan.connect_wakelock_taken = false;
    if (wlan.sta_ipv4_state == CM_STA_OBTAINING_ADDRESS)
    {
        if (wlan.connect_wakelock_taken)
        {
#ifdef CONFIG_HOST_SLEEP
            wakelock_put();
#endif
            wlan.connect_wakelock_taken = false;
        }
        if (msg->reason != WIFI_EVENT_REASON_SUCCESS)
        {
            wlcm_d("got event: DHCP failure");
#ifdef CONFIG_IPV6
            if (wlan.sta_ipv6_state != CM_STA_CONNECTED)
            {
#endif

                do_connect_failed(WLAN_REASON_ADDRESS_FAILED);

                if (wlan.reassoc_control)
                {
                    wlcm_request_reconnect(next, network);
                }

                *next = wlan.sta_state;
#ifdef CONFIG_IPV6
            }
            else if (wlan.sta_ipv6_state == CM_STA_CONNECTED)
            {
                wlan.sta_state = CM_STA_CONNECTED;
                *next          = CM_STA_CONNECTED;
                if (network->type == WLAN_BSS_TYPE_STA)
                {
                    if_handle = net_get_mlan_handle();
                }

                net_interface_up(if_handle);
                mlan_adap->skip_dfs = false;
                CONNECTION_EVENT(WLAN_REASON_SUCCESS, NULL);
            }
            else
            {
                /* Do Nothing */
            }
#endif
            return;
        }
        char ip[16];
        wlcm_d("got event: DHCP success");
        net_stop_dhcp_timer();
        net_configure_dns((struct net_ip_config *)&network->ip, network->role);
        if (network->type == WLAN_BSS_TYPE_STA)
        {
            if_handle = net_get_mlan_handle();
        }
        (void)net_get_if_addr((struct net_ip_config *)&network->ip, if_handle);
        // net_inet_ntoa(network->ip.ipv4.address, ip);
        wlan.sta_state      = CM_STA_CONNECTED;
        *next               = CM_STA_CONNECTED;
        wlan.sta_ipv4_state = CM_STA_CONNECTED;

#ifdef CONFIG_WPS2
        wlan_set_prov_session(PROV_NON_SESSION_ATTEMPT);
#endif
        if (wlan.reassoc_control && wlan.reassoc_request)
        {
            wlan.reassoc_count   = 0;
            wlan.reassoc_request = false;
        }
        mlan_adap->skip_dfs = false;
        CONNECTION_EVENT(WLAN_REASON_SUCCESS, &ip);

    }
    else
    {
        wlcm_d("got event from dhcp client %d", msg->reason);
        if (msg->reason != WIFI_EVENT_REASON_SUCCESS)
        {
            /* There was some problem with dhcp lease
             * renewal, so just disconnect from wlan.
             */

#ifdef CONFIG_IPV6
            /* Do not disconnect-connect if the STA interface has
             * obtained IPv6 address */
            if (wlan.sta_ipv6_state != CM_STA_CONNECTED)
            {
#endif
                if (wlan.sta_ipv4_state == CM_STA_CONNECTED)
                {
                    wlcm_d("Lease renewal failed, disconnecting");


                    do_connect_failed(WLAN_REASON_ADDRESS_FAILED);

                    if (wlan.reassoc_control)
                    {
                        wlcm_request_reconnect(next, network);
                    }

                    *next = wlan.sta_state;
                }
#ifdef CONFIG_IPV6
            }
#endif
            return;
        }
        /* Successful in getting ip address, so update
         * local wlan-info params */
        wlcm_d("update wlan-info params");
        if (network->type == WLAN_BSS_TYPE_STA)
        {
            if_handle = net_get_mlan_handle();
        }
        (void)net_get_if_addr((struct net_ip_config *)&network->ip, if_handle);
        CONNECTION_EVENT(WLAN_REASON_ADDRESS_SUCCESS, NULL);
    }
}

#ifdef CONFIG_IPV6
static void wlcm_process_net_ipv6_config(struct wifi_message *msg,
                                         enum cm_sta_state *next,
                                         struct wlan_network *network)
{
    void *if_handle = net_get_mlan_handle();
    int i, found = 0;
    if (network->type != WLAN_BSS_TYPE_STA || (if_handle == NULL))
    {
        return;
    }

    net_get_if_ipv6_addr((struct net_ip_config *)&network->ip, if_handle);
#ifndef __ZEPHYR__
    for (i = 0; i < CONFIG_MAX_IPV6_ADDRESSES; i++)
    {
        if (ip6_addr_isvalid((network->ip.ipv6[i].addr_state)) != 0U)
#else
    for (i = 0; i < CONFIG_MAX_IPV6_ADDRESSES && i < network->ip.ipv6_count; i++)
    {
        if ((network->ip.ipv6[i].addr_state == NET_ADDR_TENTATIVE) ||
                (network->ip.ipv6[i].addr_state == NET_ADDR_PREFERRED))
#endif
        {
            found++;
            /* Not considering link-local address as of now */
            if (wlan.sta_ipv6_state != CM_STA_CONNECTED)
            {
                wlan.sta_ipv6_state = CM_STA_CONNECTED;

                if (wlan.reassoc_control && wlan.reassoc_request)
                {
                    wlan.reassoc_count   = 0;
                    wlan.reassoc_request = false;
                }
            }
        }
    }

    if (wlan.sta_ipv6_state >= CM_STA_OBTAINING_ADDRESS && !found)
    {
        /* If the state is either obtaining address or connected and
         * if none of the IP addresses is preferred, then
         * change/maintain the state to obtaining address */
        wlan.sta_ipv6_state = CM_STA_OBTAINING_ADDRESS;
    }
}
#endif /* CONFIG_IPV6 */

int wlan_rx_mgmt_indication(const enum wlan_bss_type bss_type,
                            const uint32_t mgmt_subtype_mask,
                            int (*rx_mgmt_callback)(const enum wlan_bss_type bss_type,
                                                    const wlan_mgmt_frame_t *frame,
                                                    const size_t len))
{
#ifdef MGMT_RX
    if (mgmt_subtype_mask)
        rx_mgmt_register_callback(rx_mgmt_callback);
    else
        rx_mgmt_deregister_callback();
#endif

    return wifi_set_rx_mgmt_indication(bss_type, mgmt_subtype_mask);
}

#ifdef CONFIG_WPA_SUPP

static void wlcm_process_scan_failed()
{
    if (wlan.pending_disconnect_request == true)
    {
        wlan_disconnect();
    }
}

#define IEEEtypes_REASON_DEAUTH_LEAVING     3

static void wlcm_process_disconnected()
{
    (void)wifi_event_completion(WIFI_EVENT_LINK_LOSS, WIFI_EVENT_REASON_FAILURE, (void *)IEEEtypes_REASON_DEAUTH_LEAVING);
}

#ifdef CONFIG_11K
static void wlan_parse_neighbor_report_response(const char *nbr_response, wlan_rrm_neighbor_report_t *nbr_rpt)
{
    char event[32] = {0};
    char bssid[32] = {0};
    char info[32]  = {0};
    int op_class,channel,phy_type;

    if (!nbr_response || nbr_response[0] == '\0')
    {
        wlcm_e("11K: Neighbor response is NULL");
        return;
    }
    else if (!nbr_rpt)
    {
        wlcm_e("11K: Input Neighbor report is NULL");
        return;
    }

// Sample Response Pattern
//<3>RRM-NEIGHBOR-REP-RECEIVED bssid=ec:aa:a0:81:7f:20 info=0x1801 op_class=0 chan=153 phy_type=1 lci=0100080010000000000000000000000000000000000406000000000000060101 civic=02000b0000ed000000

    if (sscanf(nbr_response,"%s bssid=%s info=%s op_class=%d chan=%d phy_type=%d", event, bssid, info, &op_class, &channel, &phy_type) == 6)
    {
        int i;
        int match  = 0;
        size_t len = 0;

        // Check if the bssid is already present in list

        for (i = 0; i < nbr_rpt->neighbor_cnt; i++)
        {
            if (strncmp((const char *)nbr_rpt->neighbor_ap[i].bssid, bssid, 32) == 0)
            {
                match = 1;
                break;
            }

            if (nbr_rpt->neighbor_ap[i].channel == channel)
            {
                match = 1;
                break;
            }
        }

        if (!match && (nbr_rpt->neighbor_cnt < MAX_NEIGHBOR_AP_LIMIT))
        {
            strncpy((char *)nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssid, bssid, sizeof(nbr_rpt->neighbor_ap->bssid));
            len = strlen(bssid);
            nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssid[len] = (t_u8)'\0';

            strncpy((char *)nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssidInfo, info, sizeof(nbr_rpt->neighbor_ap->bssidInfo));
            len = strlen(info);
            nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssidInfo[len] = (t_u8)'\0';

            nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].channel = channel;
            wlan.nlist_rep_param.channels[wlan.nlist_rep_param.num_channels] = channel;
            nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].op_class = op_class;
            nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].phy_type = phy_type;
            //nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].freq = wifi_getRadioFrequencyFromChannel(channel);

            wlcm_d("RRM Neighbor[%d] - Bssid = %s , Info = %s, op_class=%d, Channel = %d, Phy_Type = %d, Freq=%d ", nbr_rpt->neighbor_cnt, nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssid, nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].bssidInfo, nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].op_class, nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].channel,nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].phy_type,nbr_rpt->neighbor_ap[nbr_rpt->neighbor_cnt].freq);

            nbr_rpt->neighbor_cnt += 1;
            wlan.nlist_rep_param.num_channels += 1;

            wlan.nlist_rep_param.nlist_mode = WLAN_NLIST_11K;
        }
        else if (match)
        {
            wlcm_d("BSSID already present in neighbor list, Skipping %s ",bssid);
        }
        else
        {
            wlcm_d("Maximum neighbors added to list, Skipping.");
        }
    }
    else
    {
        wlcm_d("Failed to Parse Neighbor Report - Skipping entry\n");
    }
}
#endif

#ifdef CONFIG_WPA_SUPP
static int wlcm_process_add_unspecified_network(const char *name)
{
    int ret, i;
    struct wlan_network *network;
    size_t len       = 0;
    const char *ssid = "w";

    network = os_mem_alloc(sizeof(struct wlan_network));

    if (network == NULL)
    {
        wlcm_d("%s: Failed to alloc wlan_network network", __func__);
        return -WM_FAIL;
    }

    (void)memset(network, 0, sizeof(struct wlan_network));
    (void)memcpy(network->name, name, strlen(name));
    len = strlen(name);
    network->name[len] = '\0';
    (void)memcpy(network->ssid, ssid, strlen(ssid));

    network->ip.ipv4.addr_type = ADDR_TYPE_DHCP;

    ret = wlan_add_network(network);

    os_mem_free(network);

    if (ret != WM_SUCCESS)
    {
        wlcm_e("Failed to add wps network");
        return ret;
    }
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && strlen(wlan.networks[i].name) == len &&
                !strncmp(wlan.networks[i].name, name, len))
        {
            wlan.cur_network_idx = i;
            break;
        }
    }
    return WM_SUCCESS;
}
#endif

static void wpa_supplicant_msg_cb(const char *buf, size_t len)
{
    const char *s;
    unsigned char is_11n_enabled;
    int ret;
    struct netif *netif = net_get_uap_interface();
    struct netif *sta_netif = net_get_sta_interface();
    struct wlan_network *network = &wlan.networks[wlan.cur_network_idx];

    wlcm_d("%s: %s", __func__, buf);

    if (strstr(buf, WPA_EVENT_SCAN_FAILED))
    {
        wlcm_process_scan_failed();
    }
    else if (strstr(buf, WPA_EVENT_DISCONNECTED))
    {
        wlcm_process_disconnected();
        wlan_handle_disconnect_event(mlan_adap->priv[0]);
    }
    else if (strstr(buf, WPA_EVENT_NETWORK_NOT_FOUND))
    {
        wlcm_d("No suitable network was found");

        if (wlan.roam_reassoc == true)
        {
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
            (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
            wlan.roam_reassoc = false;
#endif
        }
        else
        {
            wlan.scan_count++;

            do_connect_failed(WLAN_REASON_NETWORK_NOT_FOUND);

            if (wlan.scan_count > WLAN_RESCAN_LIMIT)
            {
                wlan.cur_network_idx = -1;
                (void)wpa_supp_disable(sta_netif, network);
            }
        }
    }
    else if (strstr(buf, WPA_EVENT_AUTH_REJECT))
    {
        wlcm_d("Authentication rejected during connection attempt");
        if ((wlan.roam_reassoc != true) && (!(strlen(buf) > strlen(WPA_EVENT_AUTH_REJECT))))
        {
            (void)send_user_request(CM_STA_USER_REQUEST_CONNECT, wlan.cur_network_idx);
        }
        wlan.roam_reassoc = false;
    }
    else if (strstr(buf, AP_STA_CONNECTED))
    {
        wlcm_d("AP: Station connected");
        t_u8 addr[MLAN_MAC_ADDR_LENGTH];

        s = strchr(buf, ' ');
        if (s == NULL)
            return;

        if (hwaddr_aton(s + 1, addr))
            return;

        ret = wpa_supp_get_sta_info(netif, addr, &is_11n_enabled);
        if (ret != 0)
            return;

        wifi_uap_client_assoc(addr, is_11n_enabled);

        CONNECTION_EVENT(WLAN_REASON_UAP_CLIENT_CONN, addr);
    }
    if (strstr(buf, AP_STA_DISCONNECTED))
    {
        wlcm_d("AP: Station dis-connected");

        wifi_uap_client_disassoc_t disassoc_resp;

        disassoc_resp.reason_code = 0;

        s = strchr(buf, ' ');
        if (s == NULL)
            return;

        if (hwaddr_aton(s + 1, disassoc_resp.sta_addr))
            return;

        wifi_uap_client_deauth(disassoc_resp.sta_addr);

        CONNECTION_EVENT(WLAN_REASON_UAP_CLIENT_DISSOC, (void *)&disassoc_resp);
    }
#ifdef CONFIG_WPA_SUPP_WPS
    else if (strstr(buf, WPS_EVENT_OVERLAP))
    {
        wlcm_d("WPS overlap detected in PBC mode");
    }
    else if (strstr(buf, WPS_EVENT_AP_AVAILABLE_PBC))
    {
        wlcm_d("Available WPS AP with active PBC found in scan results");
    }
    else if (strstr(buf, WPS_EVENT_AP_AVAILABLE_PIN))
    {
        wlcm_d("Available WPS AP with recently selected PIN registrar found in scan results");
    }
    else if (strstr(buf, WPS_EVENT_AP_AVAILABLE))
    {
        wlcm_d("Available WPS AP found in scan results");
    }
    else if (strstr(buf, WPS_EVENT_CRED_RECEIVED))
    {
        wlcm_d("A new credential received");
    }
    else if (strstr(buf, WPS_EVENT_DISABLE))
    {
        wlcm_d("PBC mode was disabled");
        wlan.wps_session_attempt = 0;
    }
    else if (strstr(buf, WPS_EVENT_ACTIVE))
    {
        wlcm_d("PBC mode was activated");
        wlan.wps_session_attempt = 1;
    }
    else if (strstr(buf, WPS_EVENT_PIN_ACTIVE))
    {
        wlcm_d("PIN mode was activated");
        wlan.wps_session_attempt = 1;
    }
    else if (strstr(buf, WPS_EVENT_TIMEOUT))
    {
        wlcm_d("WPS enrollment attempt timed out and was terminated");
        wlan.wps_session_attempt = 0;
    }
    else if (strstr(buf, WPS_EVENT_FAIL))
    {
        wlcm_d("WPS registration failed after M2/M2D");
        wlan.wps_session_attempt = 0;
    }
    else if (strstr(buf, WPS_EVENT_SUCCESS))
    {
        wlcm_d("WPS registration completed successfully");
        if (wlan.wps_session_attempt)
        {
            if (wlcm_process_add_unspecified_network("wps_network") == WM_SUCCESS)
            {
                wlan.wps_session_attempt = 0;
            }
        }
    }
    else
#endif
#ifdef CONFIG_11K
        if (strstr(buf, RRM_EVENT_NEIGHBOR_REP_RXED))
    {
        wlcm_d("11K RRM event neighbor response received");
        wlan_parse_neighbor_report_response(buf, &wlan.nbr_rpt);
    }
    else if (strstr(buf, RRM_EVENT_NEIGHBOR_REP_COMPLETED))
    {
        if (wlan.nbr_rpt.neighbor_cnt != 0U)
        {
            memset(&wlan.nbr_rpt, 0x00, sizeof(wlan_rrm_neighbor_report_t));
            (void)wifi_event_completion(WIFI_EVENT_NLIST_REPORT, WIFI_EVENT_REASON_SUCCESS, NULL);
        }
    }
    else if (strstr(buf, RRM_EVENT_NEIGHBOR_REP_FAILED))
    {
        wlcm_d("11K RRM event neighbor report request failed");
    }
    else
#endif
#ifdef CONFIG_WPA_SUPP_DPP
        if (strstr(buf, DPP_EVENT_CONF_RECEIVED))
    {
        if (!is_uap_started())
        {
            wlcm_d("DPP starts to new a network profile");
            (void)wlcm_process_add_unspecified_network("dpp_network");
        }
    }
    else if (strstr(buf, DPP_EVENT_CONFOBJ_AKM))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        /* Only for STA associate */
        mlan_adap->priv[0]->is_dpp_connect = MTRUE;
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_CONFOBJ_AKM) - 1;
            security->pmk_valid = false;
            security->type = WLAN_SECURITY_NONE;
            if (memcmp("psk", pos, strlen("psk")) == 0)
            {
                security->type     = WLAN_SECURITY_WPA2;
                security->key_mgmt = WLAN_KEY_MGMT_PSK;
            }
            else if (memcmp("sae", pos, strlen("sae")) == 0)
            {
                security->type     = WLAN_SECURITY_WPA3_SAE;
                security->key_mgmt = WLAN_KEY_MGMT_SAE;
            }
            else if ((memcmp("psk-sae", pos, strlen("psk-sae")) == 0) ||
                     (memcmp("psk+sae", pos, strlen("psk+sae")) == 0))
            {
                security->type = WLAN_SECURITY_WPA2_WPA3_SAE_MIXED;
                security->key_mgmt = WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_SAE;
            }
            else if ((memcmp("sae-dpp", pos, strlen("sae-dpp")) == 0) ||
                     (memcmp("dpp+sae", pos, strlen("dpp+sae")) == 0))
            {
                security->type        = WLAN_SECURITY_WPA3_SAE;
                security->key_mgmt = WLAN_KEY_MGMT_DPP | WLAN_KEY_MGMT_SAE;
            }
            else if ((memcmp("psk-sae-dpp", pos, strlen("psk-sae-dpp")) == 0) ||
                     (memcmp("dpp+psk+sae", pos, strlen("dpp+psk+sae")) == 0))
            {
                security->type = WLAN_SECURITY_WPA2_WPA3_SAE_MIXED;
                security->key_mgmt = WLAN_KEY_MGMT_DPP | WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_SAE;
            }
            else if (memcmp("dpp", pos, strlen("dpp")) == 0)
            {
                security->type = WLAN_SECURITY_DPP;
                security->key_mgmt = WLAN_KEY_MGMT_DPP;
            }
            else if (memcmp("dot1x", pos, strlen("dot1x")) == 0)
            {
#ifdef CONFIG_EAP_TLS
                security->type = WLAN_SECURITY_EAP_TLS_SHA256;
#endif
                security->key_mgmt = WLAN_KEY_MGMT_IEEE8021X;
            }
            else
            {
                wlcm_e("DPP AKM type(%s) unknown!", pos);
                return ;
            }
            security->pairwise_cipher = 0x10; /* CCMP */
            security->mfpc = 1;
            security->mfpr = 1;
            wlan_set_pmfcfg(security->mfpc, security->mfpr);
        }
    }
    else if (strstr(buf, DPP_EVENT_CONFOBJ_SSID))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            const char *pos = buf + sizeof(DPP_EVENT_CONFOBJ_SSID) - 1;
            if (strlen(pos) < IEEEtypes_SSID_SIZE)
            {
                (void)memcpy(wlan.networks[network_idx].ssid, pos, strlen(pos));
            }
        }
    }
    else if (strstr(buf, DPP_EVENT_CONFOBJ_PASS))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            char psk[WLAN_PSK_MAX_LENGTH];
            unsigned int hex_len = 0;
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_CONFOBJ_PASS) - 1;

            hex_len = strlen(pos);
            if (hex_len <= (WLAN_PSK_MAX_LENGTH * 2))
            {
                memset(psk, 0, sizeof(psk));
                hexstr2bin(pos, (unsigned char *)psk, hex_len/2);
                security->psk_len = strlen(psk);
                (void)strcpy(security->psk, psk);
                security->password_len = strlen(psk);
                (void)strcpy(security->password, psk);
            }
        }
    }
    else if (strstr(buf, DPP_EVENT_CONFOBJ_PSK))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            char pmk[WLAN_PMK_LENGTH];
            unsigned int hex_len = 0;
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_CONFOBJ_PSK) - 1;

            hex_len = strlen(pos);
            if (hex_len <= (WLAN_PMK_LENGTH * 2))
            {
                memset(pmk, 0, sizeof(pmk));
                hexstr2bin(pos, (unsigned char *)pmk, hex_len/2);
                security->pmk_valid = true;
                (void)memcpy(security->pmk, pmk, WLAN_PMK_LENGTH);
            }
        }
    }
    else if (strstr(buf, DPP_EVENT_CONNECTOR))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_CONNECTOR) - 1;

            if (security->dpp_connector)
            {
                os_mem_free(security->dpp_connector);
            }
            security->dpp_connector = os_mem_calloc(strlen(pos) + 1);
            if (security->dpp_connector == NULL)
            {
                wlcm_e("Allocate %s memory failed!", DPP_EVENT_CONNECTOR);
                return ;
            }
            (void)memcpy(security->dpp_connector, pos, strlen(pos));
        }
    }
    else if (strstr(buf, DPP_EVENT_C_SIGN_KEY))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_C_SIGN_KEY) - 1;

            if (security->dpp_c_sign_key)
            {
                os_mem_free(security->dpp_c_sign_key);
            }
            security->dpp_c_sign_key = os_mem_calloc(strlen(pos) + 1);
            if (security->dpp_c_sign_key == NULL)
            {
                wlcm_e("Allocate %s memory failed!", DPP_EVENT_C_SIGN_KEY);
                return ;
            }
            (void)memcpy(security->dpp_c_sign_key, pos, strlen(pos));
        }
    }
    else if (strstr(buf, DPP_EVENT_NET_ACCESS_KEY))
    {
        unsigned int network_idx = -1;

        if (is_uap_started())
        {
            network_idx = wlan.cur_uap_network_idx;
        }
        else
        {
            network_idx = wlan.cur_network_idx;
        }
        if (network_idx < WLAN_MAX_KNOWN_NETWORKS)
        {
            struct wlan_network_security *security = &(wlan.networks[network_idx].security);
            const char *pos = buf + sizeof(DPP_EVENT_NET_ACCESS_KEY) - 1;

            if (security->dpp_net_access_key)
            {
                os_mem_free(security->dpp_net_access_key);
            }
            security->dpp_net_access_key = os_mem_calloc(strlen(pos) + 1);
            if (security->dpp_net_access_key == NULL)
            {
                wlcm_e("Allocate %s memory failed!", DPP_EVENT_NET_ACCESS_KEY);
                return ;
            }
            (void)memcpy(security->dpp_net_access_key, pos, strlen(pos));
            if (is_uap_started())
            {
                wlcm_d("DPP reload uap");
                wlan_enable_uap_11d(MTRUE);
                wpa_supp_start_ap(netif, &wlan.networks[network_idx], 1);
            }
        }
    }
    else if (strstr(buf, DPP_EVENT_INTRO))
    {
        wlan_deepsleepps_on();
        wlan_ieeeps_on(wlan.wakeup_conditions);
    }
    else
#endif
    {
    }
}
#endif

#define MAX_RETRY_TICKS 50

static void wlcm_process_init_params()
{
    wlan.cm_ieeeps_configured = false;

    wlan.cm_deepsleepps_configured = false;

    wlan.cm_wnmps_configured = false;
    wlan.wnm_sleep_time      = 0;
#if defined(CONFIG_11K) || defined(CONFIG_11V)
    memset(&wlan.nlist_rep_param, 0x00, sizeof(wlan_nlist_report_param));
#endif

    wlan.bgscan_attempt = 0;

    wlan.cur_network_idx     = -1;
    wlan.cur_uap_network_idx = -1;
}

static void wlcm_process_init(enum cm_sta_state *next)
{
    int ret;
    (void)ret;

    wlan.sta_state = CM_STA_IDLE;
    *next          = CM_STA_IDLE;

    wlcm_process_init_params();


#ifdef OTP_CHANINFO
    (void)wifi_get_fw_region_and_cfp_tables();
#endif

    (void)wifi_get_uap_max_clients(&wlan.uap_supported_max_sta_num);

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *uap_netif = net_get_uap_interface();

    wpa_supp_set_ap_max_num_sta(uap_netif, wlan.uap_supported_max_sta_num);
#endif
#endif

    (void)wrapper_wlan_cmd_get_hw_spec();

#ifndef RW610
#ifndef __ZEPHYR__
    wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl = WLAN_ED_MAC_CTRL;
#else
    wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl = {
        0x01,
        CONFIG_NXP_WIFI_ED_OFFSET_2G
#ifdef CONFIG_5GHz_SUPPORT
        ,
        0x01,
        CONFIG_NXP_WIFI_ED_OFFSET_5G
#endif
    };
#endif
    (void)wlan_set_ed_mac_mode(wlan_ed_mac_ctrl);
    (void)wlan_set_uap_ed_mac_mode(wlan_ed_mac_ctrl);
#endif

    (void)wifi_enable_ecsa_support();

    //		uint16_t ant = 1; //board_antenna_select();
    //                if (board_antenna_switch_ctrl())
    //			rfctrl_set_config(ant);

#if defined(SD8801) || defined(SD8978) || defined(SD8987)
    uint32_t ant           = 1;
    uint16_t evaluate_time = 0x1770;

    ret = wifi_set_antenna(ant, evaluate_time);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("Failed to set antenna configuration");
    }
    else
    {
        wlcm_d("Antenna selected: %d", ant);
    }
#endif /* defined(SD8801, 8978, 8987) */

    wifi_set_packet_retry_count(MAX_RETRY_TICKS);

#if defined(SD8978) || defined(SD8987) || defined(SD8997) || defined(SD9097) || defined(SD9098) || defined(SD9177)

    wifi_set_txbfcap(0x19e74608);

    /*Enabling 20/40MHz enable(bit 1)
     * enabling Short GI in 40 Mhz(bit 6)
     * and 20MHz(bit 5),
     * Reserved bits to be set to 1 (Bits 2,3)*/
    uint16_t httxcfg = 0x6E; // TODO need to add defines for this setting

    ret = wlan_set_httxcfg(httxcfg);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Failed to set HT TX configuration");
        return;
    }

    wlan_uap_set_httxcfg(httxcfg);
#endif

#ifdef CONFIG_11K
    (void)wifi_host_11k_cfg(1);
#endif
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_1AS)
#ifndef CONFIG_WPA_SUPP
    (void)wlan_rx_mgmt_indication(WLAN_BSS_TYPE_STA, WLAN_MGMT_ACTION, NULL);
#endif
#endif

#ifndef CONFIG_WPA_SUPP
#ifdef CONFIG_DRIVER_MBO
    wifi_host_mbo_cfg(1);
#endif
#endif

#ifdef CONFIG_WIFI_AUTO_POWER_SAVE
    wlan_deepsleepps_on();
    wifi_set_power_save_mode();
    wlan_ieeeps_on(wlan.wakeup_conditions);
#endif

    wlan_set_11d_state(WLAN_BSS_TYPE_UAP, 1);
    wlan_set_11d_state(WLAN_BSS_TYPE_STA, 1);
}

static void wlcm_process_net_if_config_event(struct wifi_message *msg, enum cm_sta_state *next)
{
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
    int ret;
#endif

    if (wlan.sta_state != CM_STA_INITIALIZING)
    {
        wlcm_d("ignoring TCP configure response");
        return;
    }

    if (msg->reason != WIFI_EVENT_REASON_SUCCESS)
    {
        wlcm_e("Interfaces init failed");
        CONNECTION_EVENT(WLAN_REASON_INITIALIZATION_FAILED, NULL);
        /* stay here until user re-inits */
        *next = CM_STA_INITIALIZING;
        return;
    }
#ifdef CONFIG_WPA_SUPP
    ret = wpa_supp_init(wpa_supplicant_msg_cb);
    if (ret != 0)
    {
        wlcm_e("wpa_supp_init failed. status code %d", ret);
        return;
    }

    ret = wifi_supp_init();
    if (ret != 0)
    {
        wlcm_e("wifi_supp_init failed. status code %d", ret);
        return;
    }

    ret = wpa_supp_status(netif);
    if (ret != 0)
    {
        wlcm_e("wpa_supp_status failed. status code %d", ret);
        return;
    }

    /* ret = monitor_start();
    if (ret != 0)
    {
        wlcm_e("monitor_start failed. status code %d", ret);
        return;
    } */

#endif

    wlcm_process_init(next);
}

static void wlcm_request_disconnect(enum cm_sta_state *next, struct wlan_network *curr_nw);

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
static void wlcm_process_fw_hang_event(struct wifi_message *msg, enum cm_sta_state *next)
{
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

    (void)msg;

    CONNECTION_EVENT(WLAN_REASON_FW_HANG, NULL);

    if (wlan.sta_state > CM_STA_IDLE)
    {
#ifdef CONFIG_WPA_SUPP
        wpa_supp_disconnect(netif);
#endif
        wlcm_request_disconnect(next, &wlan.networks[wlan.cur_network_idx]);
        wlan_dhcp_cleanup();
    }

    if (wlan.uap_state > CM_UAP_INITIALIZING)
    {
        (void)do_stop(&wlan.networks[wlan.cur_uap_network_idx]);
    }
}

static void wlcm_process_fw_reset_event(struct wifi_message *msg, enum cm_sta_state *next)
{
    (void)msg;
    (void)next;

    wlan.ind_reset = 1;

    wlcm_process_init(next);

    CONNECTION_EVENT(WLAN_REASON_FW_RESET, NULL);
}
#endif

static enum cm_uap_state uap_state_machine(struct wifi_message *msg)
{
    struct wlan_network *network = NULL;
    enum cm_uap_state next       = wlan.uap_state;
    int ret                      = 0;
    void *if_handle              = NULL;
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_uap_interface();
#endif

    network = &wlan.networks[wlan.cur_uap_network_idx];

    switch (msg->event)
    {
        case CM_UAP_USER_REQUEST_START:
            wlan.cur_uap_network_idx = (int)msg->data;
            wlan.scan_count          = 0;

            (void)do_start(&wlan.networks[wlan.cur_uap_network_idx]);
            next = wlan.uap_state;
            break;
        case CM_UAP_USER_REQUEST_STOP:
            if (wlan.uap_state < CM_UAP_CONFIGURED)
            {
                break;
            }
            (void)do_stop(&wlan.networks[wlan.cur_uap_network_idx]);
            next = wlan.uap_state;
#ifdef CONFIG_WPA_SUPP
            if (wlan.status_timeout)
            {
                os_timer_deactivate(&wlan.supp_status_timer);
                wlan.status_timeout = 0;
                CONNECTION_EVENT(WLAN_REASON_UAP_START_FAILED, NULL);
            }
#endif
            break;
        case WIFI_EVENT_UAP_STARTED:
            if (!is_uap_state(CM_UAP_CONFIGURED))
            {
                wlcm_w(
                    "Ignoring address config event as uap not "
                    "in configured state");
                break;
            }

            if (msg->reason == WIFI_EVENT_REASON_SUCCESS)
            {
                if (network->type == WLAN_BSS_TYPE_UAP)
                {
                    (void)memcpy((void *)&network->bssid[0], (const void *)&wlan.uap_mac[0], 6);
                    if_handle = net_get_uap_handle();
                }
#ifdef CONFIG_WPA_SUPP
                os_timer_deactivate(&wlan.supp_status_timer);
                wlan.status_timeout = 0;

                wpa_supp_network_status(netif, network);
#endif

#ifdef __ZEPHYR__
                net_interface_up(if_handle);
#endif

                ret = net_configure_address((struct net_ip_config *)&network->ip, if_handle);
                if (ret != 0)
                {
                    wlcm_e("TCP/IP stack setup failed");
                    CONNECTION_EVENT(WLAN_REASON_ADDRESS_FAILED, NULL);
                }
                else
                {
                    next = CM_UAP_STARTED;
                }
            }
            else
            {
                CONNECTION_EVENT(WLAN_REASON_UAP_START_FAILED, NULL);
            }
            break;
        case WIFI_EVENT_UAP_CLIENT_ASSOC:
#ifdef CONFIG_WIFI_UAP_WORKAROUND_STICKY_TIM
            if (network->type == WLAN_BSS_TYPE_UAP)
            {
                wifi_uap_enable_sticky_bit(msg->data);
            }
#endif /* CONFIG_WIFI_UAP_WORKAROUND_STICKY_TIM */
            CONNECTION_EVENT(WLAN_REASON_UAP_CLIENT_ASSOC, msg->data);
            /* This was allocated by the sender */
            os_mem_free(msg->data);
            break;
        case WIFI_EVENT_UAP_CLIENT_CONN:
            CONNECTION_EVENT(WLAN_REASON_UAP_CLIENT_CONN, msg->data);
            /* This was allocated by the sender */
            os_mem_free(msg->data);
            break;
        case WIFI_EVENT_UAP_CLIENT_DEAUTH:
#ifdef CONFIG_WPA_SUPP_AP
            {
                wlan_uap_client_disassoc_t *disassoc_resp = msg->data;
                /* BIT 14 indicate deauth is initiated by FW */
                if(!(disassoc_resp->reason_code & MBIT(14)))
                {
                    wifi_nxp_sta_remove(disassoc_resp->sta_addr);
                }
            }
#else
            CONNECTION_EVENT(WLAN_REASON_UAP_CLIENT_DISSOC, msg->data);
#endif
            /* This was allocated by the sender */
            os_mem_free(msg->data);
            break;
        case WIFI_EVENT_UAP_STOPPED:
            CONNECTION_EVENT(WLAN_REASON_UAP_STOPPED, NULL);
            break;
        case WIFI_EVENT_UAP_NET_ADDR_CONFIG:
            if (!is_uap_state(CM_UAP_STARTED))
            {
                wlcm_w(
                    "Ignoring address config event as uap not "
                    "in started state");
                break;
            }

            if (msg->reason == WIFI_EVENT_REASON_SUCCESS && network->ip.ipv4.addr_type == ADDR_TYPE_STATIC)
            {
                if (network->type == WLAN_BSS_TYPE_UAP)
                {
                    if_handle = net_get_uap_handle();
                }

                (void)net_get_if_addr((struct net_ip_config *)&network->ip, if_handle);
                /* UAP case set dns same as gateway */
                network->ip.ipv4.dns1 = network->ip.ipv4.gw;
                network->ip.ipv4.dns2 = 0;
#ifdef CONFIG_IPV6
                (void)net_get_if_ipv6_addr((struct net_ip_config *)&network->ip, if_handle);
#endif
                next = CM_UAP_IP_UP;
                CONNECTION_EVENT(WLAN_REASON_UAP_SUCCESS, NULL);
            }
            else
            {
                CONNECTION_EVENT(WLAN_REASON_ADDRESS_FAILED, NULL);
                next = CM_UAP_INITIALIZING;
            }
            break;
        default:
            wlcm_w("got unknown message  UAP  : %d", msg->event);
            break;
    }
    return next;
}

static void wlcm_request_scan(struct wifi_message *msg, enum cm_sta_state *next)
{
    char *ssid = NULL;
    char *ssid2 = NULL;

    if (msg->data == NULL)
    {
        wlcm_w("ignoring scan request with NULL scan params");
        wlcm_d("releasing scan lock");
        (void)os_semaphore_put(&wlan.scan_lock);
        wlan.is_scan_lock = 0;
        return;
    }

    wlan_scan_params_v2_t *wlan_scan_param = (wlan_scan_params_v2_t *)msg->data;

    if ((!is_scanning_allowed())
#ifdef CONFIG_WPS2
        || (wlan_get_prov_session() != PROV_NON_SESSION_ATTEMPT)
#endif
    )
    {
        wlcm_w("ignoring scan result in invalid state");
        wlcm_d("releasing scan lock");
        /* Free allocated wifi scan parameters */
        os_mem_free(wlan_scan_param);
        (void)os_semaphore_put(&wlan.scan_lock);
        wlan.is_scan_lock = 0;
        return;
    }

    ssid = wlan_scan_param->ssid[0];
    ssid2 = wlan_scan_param->ssid[1];
    if (is_uap_started() || is_sta_connected())
        wlan_scan_param->scan_chan_gap = scan_channel_gap;
    else
        wlan_scan_param->scan_chan_gap = 0;

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11K
    if (wlan.enable_11k == 1U)
    {
        wm_wifi.wpa_supp_scan = true;
        wm_wifi.external_scan = true;
    }
#endif
#endif

    wlcm_d("initiating wlan-scan (return to %s)", dbg_sta_state_name(wlan.sta_state));


    int ret = wifi_send_scan_cmd((t_u8)g_wifi_scan_params.bss_type, wlan_scan_param->bssid,
                                 ssid, ssid2,
                                 wlan_scan_param->num_channels, wlan_scan_param->chan_list, wlan_scan_param->num_probes,
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
                                 wlan_scan_param->rssi_threshold,
#endif
                                 wlan_scan_param->scan_chan_gap,
                                 false, false);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("wifi send scan cmd failed");
        *next = wlan.sta_state;
#ifdef CONFIG_WPA_SUPP
        wm_wifi.wpa_supp_scan = false;
        wm_wifi.external_scan = false;
#endif
        wlcm_d("releasing scan lock");
        (void)os_semaphore_put(&wlan.scan_lock);
        wlan.is_scan_lock = 0;
    }
    else
    {
        wlan.scan_cb       = (int (*)(unsigned int count))(wlan_scan_param->cb);
        wlan.sta_return_to = wlan.sta_state;
        *next              = CM_STA_SCANNING_USER;
    }
    /* Free allocated wifi scan parameters */
    os_mem_free(wlan_scan_param);
}

static void wlcm_deinit(int action)
{
    if ((wlan.status != WLCMGR_ACTIVATED) && (wlan.status != WLCMGR_INIT_DONE))
    {
        wlcm_e("cannot deinit wlcmgr. unexpected status: %d\n\r", wlan.status);
        return;
    }

    wifi_scan_stop();
    wifi_deinit();
#ifndef __ZEPHYR__
    wlan_dhcp_cleanup();
#endif

    wlan.status = WLCMGR_INACTIVE;
}

static void wlcm_request_disconnect(enum cm_sta_state *next, struct wlan_network *curr_nw)
{
    void *if_handle = NULL;
    /* On disconnect request, we need to take down the interface.
       This is required to fix bug # 52964 */
    if (curr_nw->type == WLAN_BSS_TYPE_STA)
    {
        if_handle = net_get_mlan_handle();
    }
    if (if_handle == NULL)
    {
#ifdef CONFIG_NCP_BRIDGE
        CONNECTION_EVENT(WLAN_REASON_USER_DISCONNECT, (void *)(-WM_FAIL));
#endif
#ifdef CONFIG_HOST_SLEEP
        wakelock_put();
#endif
        wlcm_w("No interface is up\r\n");
        return;
    }
    net_stop_dhcp_timer();
    /* Forcefully stop dhcp on given interface.
     * net_interface_dhcp_stop internally does nothing
     * if dhcp client is not started.
     */
    net_interface_dhcp_stop(if_handle);
    net_interface_down(if_handle);

    if (
#ifdef CONFIG_WPS2
        (wlan_get_prov_session() == PROV_NON_SESSION_ATTEMPT) &&
#endif
        (wlan.sta_state < CM_STA_IDLE || is_state(CM_STA_IDLE)))
    {

#ifdef CONFIG_WPA_SUPP
        if (wlan.status_timeout)
        {
            os_timer_deactivate(&wlan.supp_status_timer);
            wlan.status_timeout = 0;
            CONNECTION_EVENT(WLAN_REASON_USER_DISCONNECT, NULL);
        }
        else
#endif
        {
#ifdef CONFIG_NCP_BRIDGE
            CONNECTION_EVENT(WLAN_REASON_USER_DISCONNECT, (void *)(-WM_FAIL));
#endif
        }
        if (wlan.connect_wakelock_taken)
        {
#ifdef CONFIG_HOST_SLEEP
            wakelock_put();
#endif
            wlan.connect_wakelock_taken = false;
        }

        wlan.cur_network_idx = -1;
        return;
    }

    if (is_user_scanning() && wlan.sta_return_to != CM_STA_IDLE)
    {
        /* we're in a user scan: we'll need to disconnect and
         * return to the idle state once this scan completes */
        if (wlan.sta_return_to >= CM_STA_ASSOCIATING)
        {
#ifndef CONFIG_WPA_SUPP
            (void)wifi_deauthenticate((uint8_t *)curr_nw->bssid);
#endif
            wlan.sta_return_to  = CM_STA_IDLE;
            *next               = CM_STA_IDLE;
            wlan.sta_ipv4_state = CM_STA_IDLE;
#ifdef CONFIG_IPV6
            wlan.sta_ipv6_state = CM_STA_IDLE;
#endif
        }
    }
    else if (wlan.sta_state >= CM_STA_ASSOCIATING)
    {
        /* if we aren't idle or user scanning,
         * we'll need to actually
         * disconnect */
#ifndef CONFIG_WPA_SUPP
        (void)wifi_deauthenticate((uint8_t *)curr_nw->bssid);
#endif
        if (wlan.is_scan_lock)
        {
            wlcm_d("releasing scan lock");
            (void)os_semaphore_put(&wlan.scan_lock);
            wlan.is_scan_lock = 0;
        }
        wlan.sta_return_to  = CM_STA_IDLE;
        wlan.sta_state      = CM_STA_IDLE;
        *next               = CM_STA_IDLE;
        wlan.sta_ipv4_state = CM_STA_IDLE;
#ifdef CONFIG_IPV6
        wlan.sta_ipv6_state = CM_STA_IDLE;
#endif
    }
    else if (wlan.sta_state == CM_STA_SCANNING)
    {
        wlan.sta_state      = CM_STA_IDLE;
        *next               = CM_STA_IDLE;
        wlan.sta_ipv4_state = CM_STA_IDLE;
#ifdef CONFIG_IPV6
        wlan.sta_ipv6_state = CM_STA_IDLE;
#endif
    }
    else
    { /* Do Nothing */
    }
    wlan.cur_network_idx =-1;

#ifdef CONFIG_WPS2
    if (wlan_get_prov_session() == PROV_WPS_SESSION_ATTEMPT)
    {
        CONNECTION_EVENT(WLAN_REASON_WPS_DISCONNECT, NULL);
        wlan_set_prov_session(PROV_NON_SESSION_ATTEMPT);
    }
    else
#endif
#ifdef CONFIG_WPA_SUPP
        if (wlan.status_timeout)
    {
#ifdef CONFIG_WPA_SUPP_WPS
        wlan.wps_session_attempt = 0;
#endif
        os_timer_deactivate(&wlan.supp_status_timer);
        wlan.status_timeout = 0;
    }
#endif
    CONNECTION_EVENT(WLAN_REASON_USER_DISCONNECT, NULL);

    if (wlan.reassoc_control && wlan.reassoc_request)
    {
        wlan.scan_count      = WLAN_RESCAN_LIMIT;
        wlan.reassoc_count   = WLAN_RECONNECT_LIMIT;
        wlan.reassoc_request = false;
    }

    if (wlan.connect_wakelock_taken)
    {
#ifdef CONFIG_HOST_SLEEP
        wakelock_put();
#endif
        wlan.connect_wakelock_taken = false;
    }
#ifdef CONFIG_HOST_SLEEP
     /* The wakelock will be taken when user issue disconnect command and this time flag wlan.connect_wakelock_taken is false.
      * Release wakelock when disconnect process is done without check.
      */
    wakelock_put();
#endif
}

static void wlcm_request_connect(struct wifi_message *msg, enum cm_sta_state *next, struct wlan_network *network)
{
    int ret;
    struct wlan_network *new_network = &wlan.networks[(unsigned int)msg->data];
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

#ifdef CONFIG_HOST_SLEEP
    if (!wlan.connect_wakelock_taken)
    {
        wakelock_get();
        wlan.connect_wakelock_taken = true;
    }
#endif

    (void)wlan_set_pmfcfg((t_u8)new_network->security.mfpc, (t_u8)new_network->security.mfpr);

    if ((wlan.roam_reassoc == false) && (wlan.sta_state >= CM_STA_ASSOCIATING))
    {
        if (new_network->role == WLAN_BSS_ROLE_STA)
        {
            wlcm_d(
                "deauthenticating before"
                " attempting new connection");
            (void)wifi_deauthenticate((uint8_t *)network->bssid);
        }
    }

    wlcm_d("starting %s to network: %d", wlan.roam_reassoc == false ? "connection" : "reassociation", (int)msg->data);

#ifndef CONFIG_WPA_SUPP
    ret = do_connect((int)msg->data);
#else
    wlan.scan_count      = 0;
    wlan.cur_network_idx = (int)msg->data;
    if (wlan.roam_reassoc == true)
    {
        ret                  = wpa_supp_reassociate(netif);
    }
    else
    {
        ret                  = wpa_supp_connect(netif, new_network);
    }
#endif

    /* Release the connect scan lock if do_connect fails,
     * in successful case it gets freed in scan result event.
     */
    if (ret != WM_SUCCESS)
    {
        if (wlan.is_scan_lock)
        {
            wlcm_d("releasing scan lock (connect scan)");
            (void)os_semaphore_put(&wlan.scan_lock);
            wlan.is_scan_lock = 0;
        }
        wlan.cur_network_idx = -1;
        CONNECTION_EVENT(WLAN_REASON_CONNECT_FAILED, NULL);
    }

#ifdef CONFIG_WPA_SUPP
    if (ret == WM_SUCCESS)
    {
        wlan.sta_state      = CM_STA_ASSOCIATING;
        wlan.connect        = true;
        wlan.status_timeout = 0;
        (void)os_timer_activate(&wlan.supp_status_timer);
    }
#endif

    *next = wlan.sta_state;
}

static void wlcm_request_reconnect(enum cm_sta_state *next, struct wlan_network *network)
{
    struct wifi_message msg;
    msg.event  = 0;
    msg.reason = WIFI_EVENT_REASON_SUCCESS;
    msg.data   = (void *)(wlan.cur_network_idx);

    wlcm_d("Reconnect in progress ...");

    wlan.reassoc_request = true;

    if (wlan.reassoc_count < WLAN_RECONNECT_LIMIT)
    {
        wlcm_d("Reconnect attempt # %d", wlan.reassoc_count + 1);
        wlan.reassoc_count++;
        wlcm_request_connect(&msg, next, network);
    }
    else
    {
        wlcm_d("Reconnection failed. Giving up.");
        wlan.reassoc_request = false;
        wlan.reassoc_count   = 0;

        wlan.cur_network_idx = -1;
        CONNECTION_EVENT(WLAN_REASON_CONNECT_FAILED, NULL);

        wlcm_d("Disconnecting ... ");
        (void)wlan_disconnect();
    }
}

static void wifi_process_bg_scan_stopped(struct wifi_message *msg)
{
    (void)msg;

    if (wlan.roam_reassoc && wlan.bgscan_attempt < BG_SCAN_LIMIT)
    {
        wlan.bgscan_attempt++;
        wlan.roam_reassoc = false;
        (void)wifi_event_completion(WIFI_EVENT_RSSI_LOW, WIFI_EVENT_REASON_SUCCESS, NULL);
    }
    else
    {
        wlan.bgscan_attempt = 0;
        wlan.roam_reassoc = false;
        PRINTF("Soft Roam: AP with better RSSI not found");
        CONNECTION_EVENT(WLAN_REASON_BGSCAN_NETWORK_NOT_FOUND, NULL);
    }
}

static void wlcm_process_bg_scan_report(void)
{
    wifi_send_scan_query();
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
    /* Set rssi low threshold and subscribe rssi low event again */
    (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
#endif
}

static void wlcm_process_get_hw_spec_event(void)
{
#ifdef CONFIG_WMM
    (void)wifi_wmm_init();
#endif

#ifdef CONFIG_WIFI_SMOKE_TESTS
    extern int initNetwork(void);
    /* network enet init */
    int ret = initNetwork();
    if (ret != WM_SUCCESS)
    {
        PRINTF("FAILED to init network (ret=%d). Reboot the board and try again.\r\n", ret);
    }
#endif

#ifdef CONFIG_SIGMA_AGENT
    (void)sigma_agent_init();
#endif

    /* Set Tx Power Limits in Wi-Fi firmware */
    (void)wlan_set_wwsm_txpwrlimit();

    if (wlan.ind_reset == 0)
    {
        CONNECTION_EVENT(WLAN_REASON_INITIALIZED, NULL);
    }
}

static void wlcm_process_mgmt_frame(void *data)
{
    RxPD *rxpd                   = (RxPD *)(net_stack_buffer_get_payload(data));
    wlan_mgmt_pkt *pmgmt_pkt_hdr = NULL;

    pmgmt_pkt_hdr          = (wlan_mgmt_pkt *)(void *)((uint8_t *)rxpd + rxpd->rx_pkt_offset);
    pmgmt_pkt_hdr->frm_len = wlan_le16_to_cpu(pmgmt_pkt_hdr->frm_len);
    if ((pmgmt_pkt_hdr->wlan_header.frm_ctl & (t_u16)IEEE80211_FC_MGMT_FRAME_TYPE_MASK) == (t_u16)0U)
    {
        // coverity[overrun-buffer-val:SUPPRESS]
		(void)wlan_process_802dot11_mgmt_pkt(
            mlan_adap->priv[0], (t_u8 *)&pmgmt_pkt_hdr->wlan_header,
            pmgmt_pkt_hdr->frm_len + sizeof(wlan_mgmt_pkt) - sizeof(pmgmt_pkt_hdr->frm_len), rxpd);
    }
}


static void wlcm_process_sync_region_code(t_u8 *code)
{
    int ret;
    t_u8 country_code[COUNTRY_CODE_LEN + 1] = {0};
    unsigned char country3                  = 0x20;
    t_u8 region_code;

    country_code[0] = code[0];
    country_code[1] = code[1];
    country_code[2] = country3;

    ret = wlan_11d_region_2_code(mlan_adap, country_code, &region_code);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("%s, Can't find '%s' in region code mapping table. Keep region code unchanged.", __func__, country_code);
        return;
    }

    wlan_set_country_code((const char *)country_code);
}

static void wlcm_process_region_power_cfg(struct wifi_message *msg)
{
    t_u8 *country_code = (t_u8 *)msg->data;

#ifdef CONFIG_COMPRESS_TX_PWTBL
    t_u8 region_code;

    region_code = region_string_2_region_code(country_code);
    wlan_set_rg_power_cfg(region_code);
#endif

    os_mem_free(country_code);
}

#if defined(CONFIG_11K) || defined(CONFIG_11V)
static void wlcm_set_rssi_low_threshold(enum cm_sta_state *next, struct wlan_network *curr_nw)
{
    (void)next;
    (void)curr_nw;

    (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
}
#endif

#ifdef CONFIG_HOST_SLEEP
static void wlcm_send_host_sleep(struct wifi_message *msg, enum cm_sta_state *next, struct wlan_network *network)
{
    uint32_t wake_up_conds = (uint32_t)msg->data;

    (void)next;
    (void)network;

    (void)wlan_send_host_sleep_int(wake_up_conds, MTRUE);
}
#endif

#ifdef CONFIG_CPU_LOADING
static void wlan_cpu_loading_info_display(void)
{
    uint64_t total_runtime = 0;
    uint64_t task_runtime[CPU_LOADING_TASK_NUM] = {0};
    float task_runtime_percentage[CPU_LOADING_TASK_NUM] = {0};
    uint8_t task_index = 0, i = 0;
    uint32_t collect_time = 0;
    char cpu_loading_task_name[] = "cpu_loading_task";

    for(i = 0; i < cpu_loading.task_nums; i++) //Don't calculate cpu info of cpu_loading_thread task.
    {
        if(!memcmp(cpu_loading_task_name, cpu_loading.task_name[i], strlen(cpu_loading_task_name)))
            continue;

        if(cpu_loading.status == CPU_LOADING_STATUS_ONGOING)
            task_runtime[i] = cpu_loading.data_cur[i] - cpu_loading.data_pre[i];
        else
            task_runtime[i] = cpu_loading.data_cur[i] - cpu_loading.first_data[i];

        total_runtime += task_runtime[i];
    }

    collect_time = ((cpu_loading.index - 1) * cpu_loading.sampling_period) /1000;
    (void)PRINTF("\r\n");
    if(cpu_loading.status != CPU_LOADING_STATUS_ENDING)
        (void)PRINTF("CPU loading: %ds ~ %ds \r\n", (collect_time - cpu_loading.sampling_period /1000) + 1, collect_time);
    else
        (void)PRINTF("Total CPU loading info in previous %d seconds\r\n", cpu_loading.index * cpu_loading.sampling_period / 1000);

    (void)PRINTF("taskName             \t\tPercentage\r\n");
    for(int i = 0; i < cpu_loading.task_nums; i++)
    {
        if(!memcmp(cpu_loading_task_name, cpu_loading.task_name[i], strlen(cpu_loading_task_name)))
            continue;
        task_runtime_percentage[i] = (float)(((float)(task_runtime[i]) / total_runtime) * 100);
        (void)PRINTF("%s \t\t%6.2f%%\r\n", task_string_name[i], task_runtime_percentage[i]);
    }
}

static int wlan_cpu_loading_stop()
{
    cpu_loading.status = CPU_LOADING_STATUS_ENDING;
    wlan_cpu_loading_info_display();

    cpu_loading.index = 0;

    (void)send_user_request(CM_STA_USER_REQUEST_CPU_LOADING, 0); // Notify wlcmgr task to destory cpu_loading_thread task.

    return WM_SUCCESS;
}

static void wlan_cpu_loading_request()
{
    int ret;

    ret = os_timer_delete(&cpu_loading.cpu_loading_timer);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Failed to delete cpu loading timer: %d.\r\n", ret);
    }

    os_mem_free(cpu_loading.cpu_loading_info);

    ret = os_thread_delete(&cpu_loading.cpu_loading_thread);
    if (ret != WM_SUCCESS)
    {
        (void)PRINTF("Failed to delete cpu_loading_task: %d.\r\n", ret);
    }

    cpu_loading.status = CPU_LOADING_STATUS_DEAD;

    (void)PRINTF("Success to stop CPU loading test.\r\n");
}
#endif

/*
 * Event Handlers
 */

static enum cm_sta_state handle_message(struct wifi_message *msg)
{
    enum cm_sta_state next       = wlan.sta_state;
    struct wlan_network *network = NULL;
#ifdef CONFIG_WPA_SUPP
    int ret;
    struct netif *netif = net_get_sta_interface();
#endif

    network = &wlan.networks[wlan.cur_network_idx];

    switch (msg->event)
    {
        case CM_STA_USER_REQUEST_CONNECT:
            wlan.pending_assoc_request = false;
            if (!wlan.assoc_paused)
            {
                wlcm_request_connect(msg, &next, network);
            }
            else
            {
                wlan.pending_assoc_request = true;
            }
            break;

        case CM_STA_USER_REQUEST_DISCONNECT:
#ifdef CONFIG_WPA_SUPP
            wlan.pending_disconnect_request = false;
            ret = wpa_supp_abort_scan(netif);
            if (ret == WM_SUCCESS)
            {
                wlan.pending_disconnect_request = true;
                break;
            }
            wpa_supp_disconnect(netif);
#endif
            wlcm_request_disconnect(&next, network);
            break;

        case CM_STA_USER_REQUEST_SCAN:
            wlcm_request_scan(msg, &next);
            break;
#if defined(CONFIG_11K) || defined(CONFIG_11V)
        case CM_STA_USER_REQUEST_SET_RSSI_THRESHOLD:
            wlcm_set_rssi_low_threshold(&next, network);
            break;
#endif
#ifdef CONFIG_HOST_SLEEP
        case CM_STA_USER_REQUEST_HS:
            wlcm_send_host_sleep(msg, &next, network);
            break;
#endif
        case CM_STA_USER_REQUEST_PS_ENTER:
            if (wlan.sta_state >= CM_STA_SCANNING && wlan.sta_state <= CM_STA_OBTAINING_ADDRESS)
            {
                wlcm_w("ignoring ps enter in invalid state");
                wlcm_e("Error entering power save mode");
                break;
            }
            if (msg->data == NULL)
            {
                wlcm_w("ignoring ps enter request with NULL ps mode");
                wlcm_e("entering power save mode");
                break;
            }
            wlan_enable_power_save((int)msg->data);
            break;
        case CM_STA_USER_REQUEST_PS_EXIT:
            if (msg->data == NULL)
            {
                wlcm_w("ignoring ps exit request with NULL ps mode");
                break;
            }
            wlan_disable_power_save((int)msg->data);
            break;
#ifdef CONFIG_CPU_LOADING
        case CM_STA_USER_REQUEST_CPU_LOADING:
            wlan_cpu_loading_request();
            break;
#endif
        case WIFI_EVENT_SCAN_START:
#ifdef CONFIG_WPA_SUPP
            wifi_scan_start(msg);
#endif
            break;
        case WIFI_EVENT_SCAN_RESULT:
            wlcm_d("got event: scan result");
            wlcm_process_scan_result_event(msg, &next);
            break;

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
        case WIFI_EVENT_FW_HANG:
            wlcm_d("got event: fw hang");
            wlcm_process_fw_hang_event(msg, &next);
            break;
        case WIFI_EVENT_FW_RESET:
            wlcm_d("got event: fw reset");
            wlcm_process_fw_reset_event(msg, &next);
            break;
#endif

#ifdef CONFIG_WPA_SUPP
        case WIFI_EVENT_SURVEY_RESULT_GET:
            wifi_survey_result_get(msg);
            break;
#endif

        case WIFI_EVENT_ASSOCIATION:
            wlcm_d("got event: association result: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");

            wlcm_process_association_event(msg, &next);
            break;

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_AUTO_RECONNECT
        case WIFI_EVENT_ASSOCIATION_NOTIFY:
            wlcm_d("got event: association notify: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");

            wlcm_process_association_notify_event(msg, &next);
            break;
#endif
#endif

        case WIFI_EVENT_PMK:
            wlcm_d("got event: PMK result: %s", msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
            wlcm_process_pmk_event(msg, &next, network);
            break;
            /* We have received a event from firmware whether
             * authentication with given wireless credentials was successful
             * or not. If successful, we are authenticated and can proceed
             * to IP-level setup by configuring the TCP stack for our
             * desired address and transitioning to the
             * CM_STA_REQUESTING_ADDRESS state where we wait for the TCP
             * stack configuration response.  Otherwise we have failed to
             * connect to the network.
             */
        case WIFI_EVENT_AUTHENTICATION:
            wlcm_d("got event: authentication result: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
            if(msg->reason == WIFI_EVENT_REASON_FAILURE)
            {
#ifdef CONFIG_ECSA
                wrapper_clear_media_connected_event();
                wlan_switch_to_nondfs_channel();
#endif
            }
            wlcm_process_authentication_event(msg, &next, network);
            break;
        case WIFI_EVENT_LINK_LOSS:
            wlcm_d("got event: link loss, code=%d", (int)msg->data);
            wlcm_process_link_loss_event(msg, &next, network);
            break;
        case WIFI_EVENT_RSSI_LOW:
            wlcm_d("got event: rssi low");
#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
            wlcm_process_rssi_low_event(msg, &next, network);
#else
            CONNECTION_EVENT(WLAN_REASON_RSSI_LOW, NULL);
#endif
            break;
#ifdef CONFIG_SUBSCRIBE_EVENT_SUPPORT
        case WIFI_EVENT_RSSI_HIGH:
            wlcm_d("got event: RSSI high");
            CONNECTION_EVENT(WLAN_REASON_RSSI_HIGH, NULL);
            break;
        case WIFI_EVENT_SNR_LOW:
            wlcm_d("got event: SNR low");
            CONNECTION_EVENT(WLAN_REASON_SNR_LOW, NULL);
            break;
        case WIFI_EVENT_SNR_HIGH:
            wlcm_d("got event: SNR high");
            CONNECTION_EVENT(WLAN_REASON_SNR_HIGH, NULL);
            break;
        case WIFI_EVENT_MAX_FAIL:
            wlcm_d("got event: MAX fail");
            CONNECTION_EVENT(WLAN_REASON_MAX_FAIL, NULL);
            break;
        case WIFI_EVENT_BEACON_MISSED:
            wlcm_d("got event: Beacon missed");
            CONNECTION_EVENT(WLAN_REASON_BEACON_MISSED, NULL);
            break;
        case WIFI_EVENT_DATA_RSSI_LOW:
            wlcm_d("got event: DATA_RSSI low");
            CONNECTION_EVENT(WLAN_REASON_DATA_RSSI_LOW, NULL);
            break;
        case WIFI_EVENT_DATA_RSSI_HIGH:
            wlcm_d("got event: DATA_RSSI high");
            CONNECTION_EVENT(WLAN_REASON_DATA_RSSI_HIGH, NULL);
            break;
        case WIFI_EVENT_DATA_SNR_LOW:
            wlcm_d("got event: DATA_SNR low");
            CONNECTION_EVENT(WLAN_REASON_DATA_SNR_LOW, NULL);
            break;
        case WIFI_EVENT_DATA_SNR_HIGH:
            wlcm_d("got event: DATA_SNR high");
            CONNECTION_EVENT(WLAN_REASON_DATA_SNR_HIGH, NULL);
            break;
        case WIFI_EVENT_FW_LINK_QUALITY:
            wlcm_d("got event: LINK_QUALITY");
            CONNECTION_EVENT(WLAN_REASON_LINK_QUALITY, NULL);
            break;
        case WIFI_EVENT_FW_PRE_BCN_LOST:
            wlcm_d("got event: PRE_BEACON_LOST");
            CONNECTION_EVENT(WLAN_REASON_PRE_BEACON_LOST, NULL);
            break;
#endif
#ifdef CONFIG_HOST_SLEEP
        case WIFI_EVENT_HS_ACTIVATED:
        case WIFI_EVENT_SLEEP_CONFIRM_DONE:
            if (wlan.hs_configured == MTRUE)
            {
                wlan.hs_configured = MFALSE;
#ifdef CONFIG_POWER_MANAGER
                if (!wlan_is_manual)
                {
                    is_hs_handshake_done = WLAN_HOSTSLEEP_SUCCESS;
#ifdef RW610
#ifndef __ZEPHYR__
#if !defined(CONFIG_WIFI_BLE_COEX_APP)
                    host_sleep_cli_notify();
#endif
#endif
#endif
                }
#endif
            }
            break;
#endif
#if defined(CONFIG_11K) || defined(CONFIG_11V)
        case WIFI_EVENT_NLIST_REPORT:
            wlcm_d("got event: neighbor list report");
            wlcm_process_neighbor_list_report_event(msg, &next, network);
            break;
#endif
        case WIFI_EVENT_DISASSOCIATION:
            wlcm_d("got event: disassociation, code=%d", (int)(msg->data));
#ifdef CONFIG_ECSA
            wrapper_clear_media_connected_event();
            wlan_switch_to_nondfs_channel();
#endif
            wlcm_process_disassoc_event(msg, &next, network);
            break;

        case WIFI_EVENT_DEAUTHENTICATION:
            wlcm_d("got event: deauthentication");
            wlcm_process_deauthentication_event(msg, &next, network);
            break;

        case WIFI_EVENT_NET_STA_ADDR_CONFIG:
            wlcm_d("got event: TCP configured");
            wlcm_process_sta_addr_config_event(msg, &next, network);
            break;

        case WIFI_EVENT_GET_HW_SPEC:
            wlcm_process_get_hw_spec_event();
            break;

        case WIFI_EVENT_NET_INTERFACE_CONFIG:
            wlcm_d("got event: Interfaces configured");
            wlcm_process_net_if_config_event(msg, &next);
            break;

        case WIFI_EVENT_NET_DHCP_CONFIG:
            wlcm_process_net_dhcp_config(msg, &next, network);
            break;
#ifdef CONFIG_IPV6
        case WIFI_EVENT_NET_IPV6_CONFIG:
            wlcm_d("got event: net ipv6 config");
            if (wlan.cur_network_idx >= WLAN_MAX_KNOWN_NETWORKS)
                break;

            wlcm_process_net_ipv6_config(msg, &next, network);
            break;
#endif /* CONFIG_IPV6 */

        case WIFI_EVENT_CHAN_SWITCH_ANN:
            wlcm_d("got event: channel switch announcement");
            wlcm_process_channel_switch_ann(&next, network);
            break;
        case WIFI_EVENT_CHAN_SWITCH:
            wlcm_d("got event: channel switch");
#ifdef CONFIG_WPA_SUPP
            wlcm_process_channel_switch_supp(msg);
#else
            wlcm_process_channel_switch(msg);
#endif
            break;

        case WIFI_EVENT_SLEEP:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: sleep");
#endif
            wlcm_process_sleep_event();
            break;

        case WIFI_EVENT_IEEE_PS:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: IEEE ps result: %s", msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
#endif
            wlcm_process_ieeeps_event(msg);
            break;

        case WIFI_EVENT_DEEP_SLEEP:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: deep sleep result: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
#endif
            wlcm_process_deepsleep_event(msg, &next);

            break;
        case WIFI_EVENT_WNM_PS:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: WNM ps result: %s", msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
#endif
            wlcm_process_wnmps_event(msg);
            break;
        case WIFI_EVENT_IEEE_DEEP_SLEEP:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: IEEE deep sleep result: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
#endif
            os_mem_free(msg->data);
            break;
        case WIFI_EVENT_WNM_DEEP_SLEEP:
#ifdef CONFIG_WIFI_PS_DEBUG
            wlcm_d("got event: WNM deep sleep result: %s",
                    msg->reason == WIFI_EVENT_REASON_SUCCESS ? "success" : "failure");
#endif
            os_mem_free(msg->data);
            break;
#ifdef CONFIG_HOST_SLEEP
        case WIFI_EVENT_HS_CONFIG:
            if (wlan.hs_configured == MTRUE)
            {
                wlcm_process_hs_config_event();
            }
            break;
#endif
        case WIFI_EVENT_11N_ADDBA:
            wlcm_process_addba_request(msg);
            break;
        case WIFI_EVENT_11N_DELBA:
            wlcm_process_delba_request(msg);
            break;
        case WIFI_EVENT_11N_BA_STREAM_TIMEOUT:
            wlcm_process_ba_stream_timeout_request(msg);
            break;
        case WIFI_EVENT_11N_AGGR_CTRL:
            wlcm_d("AGGR_CTRL ignored for now");
            break;
        case WIFI_EVENT_STA_MAC_ADDR_CONFIG:
            if (msg->data != NULL)
            {
                (void)memcpy((void *)&wlan.sta_mac[0], (const void *)msg->data, MLAN_MAC_ADDR_LENGTH);
                os_mem_free(msg->data);
            }
            break;
        case WIFI_EVENT_UAP_MAC_ADDR_CONFIG:
            if (msg->data != NULL)
            {
                (void)memcpy((void *)&wlan.uap_mac[0], (const void *)msg->data, MLAN_MAC_ADDR_LENGTH);
                os_mem_free(msg->data);
            }
            break;
        case WIFI_EVENT_BG_SCAN_STOPPED:
            wlcm_d("got event: BG scan stopped");
            wifi_process_bg_scan_stopped(msg);
            break;
        case WIFI_EVENT_BG_SCAN_REPORT:
            wlcm_d("got event: BG scan report");
            wlcm_process_bg_scan_report();
            break;
        case WIFI_EVENT_MGMT_FRAME:
            wlcm_d("got event: management frame");
            wlcm_process_mgmt_frame(msg->data);
            next = wlan.sta_state;
            net_stack_buffer_free(msg->data);
            break;
#ifdef CONFIG_WPA_SUPP
        case WIFI_EVENT_REMAIN_ON_CHANNEL:
            wifi_process_remain_on_channel(msg);
            break;
        case WIFI_EVENT_MGMT_TX_STATUS:
            wifi_process_mgmt_tx_status(msg);
            break;
#endif
        case WIFI_EVENT_SYNC_REGION_CODE:
            wlcm_process_sync_region_code((t_u8 *)msg->data);
            break;
        case WIFI_EVENT_REGION_POWER_CFG:
            wlcm_process_region_power_cfg(msg);
            break;
        default:
            wlcm_w("got unknown message: %d", msg->event);
            break;
    }

    return next;
}

static bool is_uap_msg(struct wifi_message *msg)
{
    return (((msg->event >= CM_UAP_USER_REQUEST_START) && (msg->event < CM_WLAN_USER_REQUEST_DEINIT)) ||
            (msg->event <= WIFI_EVENT_UAP_LAST));
}

/*
 * Main Thread: the WLAN Connection Manager event queue handler and state
 * machine.
 */

static void cm_main(os_thread_arg_t data)
{
    int ret;
    struct wifi_message msg;
    enum cm_sta_state next_sta_state;
    enum cm_uap_state next_uap_state;

    (void)memset((void *)&msg, 0, sizeof(struct wifi_message));

    /* Wait for all the data structures to be created */
    while (!wlan.running)
    {
        os_thread_sleep(os_msec_to_ticks(500));
    }

    (void)net_wlan_init();

    while (true)
    {
        ret = os_queue_recv(&wlan.events, &msg, OS_WAIT_FOREVER);

        if ((wlan.stop_request != 0U) && (msg.event == (uint16_t)CM_WLAN_USER_REQUEST_SHUTDOWN))
        {
            wlcm_d("Received shutdown request");
            wlan.status = WLCMGR_THREAD_STOPPED;
            os_thread_self_complete(NULL);
        }

        if (ret == WM_SUCCESS)
        {
#ifndef CONFIG_WIFI_PS_DEBUG
            if (msg.event != WIFI_EVENT_SLEEP && msg.event != WIFI_EVENT_IEEE_PS &&
                    msg.event != WIFI_EVENT_DEEP_SLEEP && msg.event != WIFI_EVENT_IEEE_DEEP_SLEEP)
            {
                wlcm_d("got wifi message: %d %d %p", msg.event, msg.reason, msg.data);
            }
#else
            wlcm_d("got wifi message: %d %d %p", msg.event, msg.reason, msg.data);
#endif

            if (is_uap_msg(&msg) != 0)
            {
                /* uAP related msg */
                next_uap_state = uap_state_machine(&msg);
                if (wlan.uap_state == next_uap_state)
                {
                    continue;
                }

                wlcm_d("SM uAP %s -> %s", dbg_uap_state_name(wlan.uap_state), dbg_uap_state_name(next_uap_state));
                wlan.uap_state = next_uap_state;
            }
            else if (msg.event == (uint16_t)CM_WLAN_USER_REQUEST_DEINIT)
            {
                wlcm_deinit((int)msg.data);
            }
            else
            {
                /* STA related msg */
                next_sta_state = handle_message(&msg);
                if (wlan.sta_state == next_sta_state)
                {
                    continue;
                }

                wlcm_d("SM STA %s -> %s", dbg_sta_state_name(wlan.sta_state), dbg_sta_state_name(next_sta_state));
                wlan.sta_state = next_sta_state;
            }
        }
        else
        {
            wlcm_d("SM queue recv Timed out ");
        }
    }
}

#ifdef CONFIG_WPS2
/* WLAN Connection Manager scan results callback */
static int prov_wps_scan_results(unsigned int count)
{
    int i;
    int err;

    if (count == 0)
    {
        os_semaphore_put(&wlan_wps.wps_scan_done);
        return 0;
    }

    for (i = 0; i < count; i++)
    {
        err = wlan_get_scan_result(i, &wlan_wps.wps_res);
        if (err != 0)
        {
            wlcm_e("Error: can't get scan res %d", i);
            continue;
        }

        if ((wlan_wps.wps_res.wps_session == WPS_SESSION_PBC) || (wlan_wps.wps_res.wps_session == WPS_SESSION_PIN))
            break;
    }

    os_semaphore_put(&wlan_wps.wps_scan_done);

    return 0;
}

static void wps_main(os_thread_arg_t data)
{
    int rv = os_semaphore_create(&wlan_wps.wps_scan_done, "wlanwpssem");
    if (rv != WM_SUCCESS)
    {
        wlcm_e("Failed to create WPS scan semaphore");
    }

    os_semaphore_get(&wlan_wps.wps_scan_done, OS_WAIT_FOREVER);
    while (1)
    {
        os_thread_sleep(os_msec_to_ticks(500));
        if ((wlan_wps.wps_state == PROV_WPS_PBC_ENABLED) || (wlan_wps.wps_state == PROV_WPS_PIN_ENABLED))
        {
            int i = 5;

            wlcm_d("WPS is enabled");
            if (is_uap_started())
            {
                wlan_wps.wps_state = PROV_WPS_STARTED;
                wps_conf.role = 2; //WPS_REGISTRAR
                wlan_set_prov_session(PROV_WPS_SESSION_ATTEMPT);
                wps_connect(wlan_wps.wps_cmd, wlan_wps.wps_pin, &wlan_wps.wps_res);
            }
            else
            {
                while (i)
                {
                    if (wlan_scan(prov_wps_scan_results) != 0)
                    {
                        (void)PRINTF("Error: scan request failed, sta_state");
#ifdef CONFIG_WLCMGR_DEBUG
                        (void)PRINTF("(%s)", dbg_sta_state_name(wlan.sta_state));
#else
                        (void)PRINTF("(%d)", wlan.sta_state);
#endif
                        (void)PRINTF(" is not idle/connected\r\n");
                        (void)PRINTF("Wait or disconnect network\r\n");
                        break;
                    }
                    os_semaphore_get(&wlan_wps.wps_scan_done, OS_WAIT_FOREVER);
                    if ((wlan_wps.wps_res.wps_session == WPS_SESSION_PIN) ||
                        (wlan_wps.wps_res.wps_session == WPS_SESSION_PBC))
                    {
                        wlcm_d("WPS Session from AP started");
                        wlan_wps.wps_state = PROV_WPS_STARTED;
                        wlan_set_prov_session(PROV_WPS_SESSION_ATTEMPT);
                        wps_connect(wlan_wps.wps_cmd, wlan_wps.wps_pin, &wlan_wps.wps_res);
                        break;
                    }
                    i--;
                }
            }

            wlan_wps.wps_state = PROV_WPS_NONE;
            memset(&wlan_wps.wps_res, 0, sizeof(wlan_wps.wps_res));
        }
    }
}
#endif
/*
 * WLAN API
 */

static int send_user_request(enum user_request_type request, unsigned int data)
{
    struct wifi_message msg;

    msg.event  = (uint16_t)request;
    msg.reason = WIFI_EVENT_REASON_SUCCESS;
    msg.data   = (void *)data;

    if (os_queue_send(&wlan.events, &msg, OS_NO_WAIT) == WM_SUCCESS)
    {
        return WM_SUCCESS;
    }

    return -WM_FAIL;
}

static void copy_network(struct wlan_network *dst, struct wlan_network *src)
{
    (void)memcpy((void *)dst, (const void *)src, sizeof(struct wlan_network));
    /* Omit any information that was dynamically
     * learned from the network so that users can
     * see which parameters were actually
     * configured by the user.
     */
    if (!src->bssid_specific)
    {
        (void)memset(dst->bssid, 0, IEEEtypes_ADDRESS_SIZE);
    }
    if (!src->ssid_specific)
    {
        (void)memset(dst->ssid, 0, IEEEtypes_SSID_SIZE);
    }
    if (!src->channel_specific)
    {
        dst->channel = 0;
    }
    if (src->ip.ipv4.addr_type != 0U)
    {
        dst->ip.ipv4.address = 0;
        dst->ip.ipv4.gw      = 0;
        dst->ip.ipv4.netmask = 0;
        dst->ip.ipv4.dns1    = 0;
        dst->ip.ipv4.dns2    = 0;
    }
}

static int wifi_wakeup_card_cb(os_rw_lock_t *plock, unsigned int wait_time)
{
    int ret = os_semaphore_get(&(plock->rw_lock), 0);
    if (ret == -WM_FAIL)
    {
        wlan_wake_up_card();
        ret = os_semaphore_get(&(plock->rw_lock), wait_time);
    }
    return ret;
}

int wlan_init(const uint8_t *fw_start_addr, const size_t size)
{
    int ret;

    if (wlan.status != WLCMGR_INACTIVE)
    {
        return WM_SUCCESS;
    }

#ifdef OVERRIDE_CALIBRATION_DATA
    wlan_set_cal_data(ext_cal_data, sizeof(ext_cal_data));
#else
#ifndef RW610
    wlan_set_cal_data(int_cal_data, sizeof(int_cal_data));
#else
    wlan_set_cal_data(cal_data_rw610, sizeof(cal_data_rw610));
#endif
#endif

#if defined(CONFIG_HOST_PMK) || defined(CONFIG_WPS2)
    wm_mbedtls_lib_init();
#endif /* defined(CONFIG_HOST_PMK) || defined(CONFIG_WPS2) */

    ret = os_rwlock_create_with_cb(&sleep_rwlock, "sleep_mutex", "sleep_rwlock", wifi_wakeup_card_cb);
    if (ret != WM_SUCCESS)
    {
        wifi_e("Create sleep cmd lock failed");
        return ret;
    }

#ifdef CONFIG_WMM_UAPSD
    ret = os_semaphore_create(&uapsd_sem, "uapsd sem");
    if (ret != WM_SUCCESS)
    {
        wifi_e("Create uapsd sem failed");
        return ret;
    }
#endif
#ifdef CONFIG_HOST_SLEEP
    ret = os_semaphore_create_counting(&wakelock, "wake-lock", 10, 0);
    if (ret == -WM_FAIL)
    {
        wifi_e("Failed to create wake-lock semaphore");
        return ret;
    }
#endif

    ret = wifi_init(fw_start_addr, size);
    if (ret != 0)
    {
        wlcm_e("wifi_init failed. status code %d", ret);
        return ret;
    }

    wlan.status = WLCMGR_INIT_DONE;
    wifi_mac_addr_t mac_addr;
    wifi_mac_addr_t mac_addr_uap;
    ret = wifi_get_device_mac_addr(&mac_addr);

    if (ret != WM_SUCCESS)
    {
        wlcm_e("Failed to get sta mac address");
        return ret;
    }

    ret = wifi_get_device_uap_mac_addr(&mac_addr_uap);

    if (ret != WM_SUCCESS)
    {
        wlcm_e("Failed to get uap mac address");
        return ret;
    }

    (void)memcpy((void *)&wlan.uap_mac[0], (const void *)mac_addr_uap.mac, MLAN_MAC_ADDR_LENGTH);
    (void)memcpy((void *)&wlan.sta_mac[0], (const void *)mac_addr.mac, MLAN_MAC_ADDR_LENGTH);
    (void)PRINTF("MAC Address: ");
    print_mac((const char *)&wlan.uap_mac);
    (void)PRINTF("\r\n");

    ret = wifi_get_device_firmware_version_ext(&wlan.fw_ver_ext);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Failed to get verext");
        return ret;
    }
    wlcm_d("WLAN FW ext_version: %s", wlan.fw_ver_ext.version_str);

#ifdef CONFIG_WIFI_FW_DEBUG
    if (wlan.wlan_usb_init_cb != NULL)
        wlan.wlan_usb_init_cb();
    else
        wifi_d("USB init callback is not registered");
#endif
    return ret;
}

void wlan_deinit(int action)
{
    if (wlan.running != 0U)
    {
        (void)send_user_request(CM_WLAN_USER_REQUEST_DEINIT, (unsigned int)action);
    }
    else
    {
        wlcm_deinit(action);
    }
#ifndef RW610
    os_rwlock_delete(&sleep_rwlock);
#endif
}

#ifdef CONFIG_WPS2
static int wlcm_wps_callback(enum wps_event event, void *data, uint16_t len)
{
    int ret                  = WM_SUCCESS;
    struct wlan_network *net = (struct wlan_network *)data;

    wlcm_d("WPS EVENT = %d data = %p len=%d", event, data, len);

    if (event == WPS_STARTED) {
        wifi_send_wps_cfg_cmd(1); /* Notify wifidriver that wps session has started */
    }
    else if (event == WPS_SESSION_SUCCESSFUL)
    {
        if (data == NULL)
        {
            wifi_send_wps_cfg_cmd(0); /* Notify wifidriver that wps session end */
            if (wps_conf.role != 2) /* if not WPS_REGISTRAR */
            {
                wlcm_e("Invalid data for WPS SESSION SUCCESSFUL");
                return -WM_FAIL;
            }
        }
        if (len == sizeof(struct wlan_network))
        {
            /* It's WPS SESSION */
            wifi_send_wps_cfg_cmd(0); /* Notify wifidriver that wps session end */
            ret = wlan_add_network(net);

            if (ret != WM_SUCCESS)
            {
                wlcm_d("Adding network failed");
                return ret;
            }
#ifdef CONFIG_NCP_BRIDGE
            CONNECTION_EVENT(WLAN_REASON_WPS_SESSION_DONE, net);
#endif
            ret = wlan_connect(net->name);
            if (ret != WM_SUCCESS)
            {
                wlcm_d("Connecting to network failed");
                return ret;
            }
        }
        else
        {
            /* It's ENTP SESSION */
            ret = wlan_wlcmgr_send_msg(WIFI_EVENT_PMK, WIFI_EVENT_REASON_SUCCESS, data);
        }

    }
    else if (event == WPS_SESSION_TIMEOUT || event == WPS_SESSION_FAILED)
    {
        wifi_send_wps_cfg_cmd(0); /* Notify wifidriver that wps session end */
        ret =
            wlan_wlcmgr_send_msg(WIFI_EVENT_AUTHENTICATION, WIFI_EVENT_REASON_FAILURE, (void *)WPA2_ENTERPRISE_FAILED);
    }

    return ret;
}
#endif

static void assoc_timer_cb(os_timer_arg_t arg)
{
    wlan.assoc_paused = false;
    if (wlan.pending_assoc_request)
    {
        (void)send_user_request(CM_STA_USER_REQUEST_CONNECT, 0);
    }
}

#ifdef CONFIG_WPA_SUPP
static void supp_status_timer_cb(os_timer_arg_t arg)
{
    int ret;

#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    if (wlan.status_timeout == 60)
#else
    if (wlan.status_timeout == 40)
#endif
    {
        ret = wpa_supp_req_status(wlan.connect ? CONNECT : START);

        if (ret != WM_SUCCESS)
        {
            (void)send_user_request(wlan.connect ? CM_STA_USER_REQUEST_DISCONNECT : CM_UAP_USER_REQUEST_STOP, 0);
        }
    }

    wlan.status_timeout++;
}
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V)
static void neighbor_req_timer_cb(os_timer_arg_t arg)
{
    if (wlan.neighbor_req == true)
    {
        wlan.neighbor_req = false;
        (void)send_user_request(CM_STA_USER_REQUEST_SET_RSSI_THRESHOLD, 0);
    }
}
#endif

#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
static void ft_roam_timer_cb(os_timer_arg_t arg)
{
    wlan.roam_reassoc = false;
}
#endif
#endif

#ifndef __ZEPHYR__
#ifdef SD9177

#include "lwip/udp.h"

static ip_addr_t udp_addr;
static int udp_addr_set;
static struct net_ip_config net_udp_addr;
/*!
 * @brief Invokes UDP polling, to be run on tcpip_thread.
 */
static void poll_udp_client(void *arg)
{
    LWIP_UNUSED_ARG(arg);
    struct pbuf *p;
    uint8_t udp_data[4] = {1, 2, 3, 4};
    err_t i;

    if (udp_raw_pcb == NULL)
        udp_raw_pcb = udp_new_ip_type(IPADDR_TYPE_ANY);

    if (udp_raw_pcb != NULL)
    {
        p = pbuf_alloc(PBUF_TRANSPORT, sizeof(udp_data), PBUF_RAM);
        if (p)
        {
            memcpy(p->payload, udp_data, sizeof(udp_data));
            i = udp_sendto(udp_raw_pcb, p, &udp_addr, 1234);
            if (i != ERR_OK)
            {
                wlcm_d("Got error %d when sending UDP packet!\r\n", i);
            }
            pbuf_free(p);
        }
        else
        {
            wlcm_d("Couldn't allocate a pbuf!!\r\n");
        }
    }
}

static void udp_remove_cb(void *arg)
{
    udp_remove((struct udp_pcb *)arg);
}

static void poll_timer_cb(os_timer_arg_t arg)
{
    void *if_handle = NULL;

    if ((is_sta_ipv4_connected() != 0) && (wlan.cm_ieeeps_configured == true))
    {
        if (udp_addr_set == 0)
        {
            if_handle = net_get_mlan_handle();

            if (net_get_if_addr(&net_udp_addr, if_handle) != 0)
            {
                return;
            }

#ifdef CONFIG_IPV6
            memcpy((void *)&udp_addr.u_addr.ip4.addr, (void *)&net_udp_addr.ipv4.gw, sizeof(unsigned int));
            udp_addr.type = IPADDR_TYPE_V4;
#else
            memcpy((void *)&udp_addr.addr, (void *)&net_udp_addr.ipv4.gw, sizeof(unsigned int));
#endif
            udp_addr_set = 1;
        }

        (void)tcpip_try_callback(poll_udp_client, NULL);
    }
    else
    {
        udp_addr_set = 0;
        if(udp_raw_pcb != NULL)
        {
            (void)tcpip_try_callback(udp_remove_cb, udp_raw_pcb);
            udp_raw_pcb = NULL;
        }
    }
}
#endif
#endif

static void wlan_wait_wlmgr_ready()
{
    while (wlan.sta_state == CM_STA_INITIALIZING)
    {
        /* wait for wlmgr ready */
        os_thread_sleep(os_msec_to_ticks(50));
    }
}

int wlan_start(int (*cb)(enum wlan_event_reason reason, void *data))
{
    int ret;

    if (!((wlan.status == WLCMGR_INIT_DONE) || (wlan.status == WLCMGR_INACTIVE)))
    {
        wlcm_e("cannot start wlcmgr. unexpected status: %d", wlan.status);
        return WLAN_ERROR_STATE;
    }

    if (cb == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running != 0U)
    {
        return WLAN_ERROR_STATE;
    }

    wlan.sta_state = CM_STA_INITIALIZING;

    wlan.sta_return_to = CM_STA_IDLE;
    wlan.uap_state     = CM_UAP_INITIALIZING;
    wlan.uap_return_to = CM_UAP_INITIALIZING;

#ifdef CONFIG_WIFI_STA_RECONNECT
    wlan.reassoc_control = true;
#endif
    wlan.hidden_scan_on  = false;

    wlcm_process_init_params();

#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
    wlan.rssi_low_threshold = 70;
#endif

#ifdef RW610
#if defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)
    wlan.wakeup_conditions = (unsigned int)WAKE_ON_UNICAST | (unsigned int)WAKE_ON_MAC_EVENT |
                             (unsigned int)WAKE_ON_MULTICAST | (unsigned int)WAKE_ON_ARP_BROADCAST;
#else
    wlan.wakeup_conditions = 0;
#endif
#else
    wlan.wakeup_conditions = (unsigned int)WAKE_ON_UNICAST | (unsigned int)WAKE_ON_MAC_EVENT |
                             (unsigned int)WAKE_ON_MULTICAST | (unsigned int)WAKE_ON_ARP_BROADCAST;
#endif

    wlan.num_networks = 0;
    (void)memset(&wlan.networks[0], 0, sizeof(wlan.networks));
    (void)memset(&wlan.scan_chan_list, 0, sizeof(wifi_scan_chan_list_t));
    wlan.scan_count = 0;
    wlan.cb         = cb;
    wlan.scan_cb    = NULL;

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    wlan.ca_cert_data     = NULL;
    wlan.ca_cert_len      = 0;
    wlan.client_cert_data = NULL;
    wlan.client_cert_len  = 0;
    wlan.client_key_data  = NULL;
    wlan.client_key_len   = 0;
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    wlan.dh_data          = NULL;
    wlan.dh_len           = 0;
    wlan.server_cert_data = NULL;
    wlan.server_cert_len  = 0;
    wlan.server_key_data  = NULL;
    wlan.server_key_len   = 0;
#endif
#endif
#endif
#endif

    wlan.events_queue_data = g_wlan_event_queue_data;
    ret = os_queue_create(&wlan.events, "wlan-events", (int)sizeof(struct wifi_message), &wlan.events_queue_data);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("unable to create event queue: %d", ret);
        return -WM_FAIL;
    }

    ret = wifi_register_event_queue(&wlan.events);

    if (ret != 0)
    {
        wlcm_e("unable to register event queue");
        (void)os_queue_delete(&wlan.events);
        return -WM_FAIL;
    }

    wlan.cm_stack = g_cm_stack;
    ret           = os_thread_create(&wlan.cm_main_thread, "wlcmgr", cm_main, NULL, &wlan.cm_stack, OS_PRIO_1);

    if (ret != 0)
    {
        wlan.cb = NULL;
        (void)wifi_unregister_event_queue(&wlan.events);
        (void)os_queue_delete(&wlan.events);
        return -WM_FAIL;
    }


    if (os_semaphore_create(&wlan.scan_lock, "wlan-scan") != 0)
    {
        (void)wifi_unregister_event_queue(&wlan.events);
        (void)os_queue_delete(&wlan.events);
        (void)os_thread_delete(&wlan.cm_main_thread);
        return -WM_FAIL;
    }

#ifdef RW610
    if (reset_lock == NULL)
    {
        ret = os_mutex_create(&reset_lock, "reset_lock", OS_MUTEX_INHERIT);
        if (ret != 0)
        {
            wlan.cb = NULL;
            wifi_unregister_event_queue(&wlan.events);
            os_queue_delete(&wlan.events);
            os_thread_delete(&wlan.cm_main_thread);
            os_semaphore_delete(&wlan.scan_lock);
            return -WM_FAIL;
        }
    }

    if (!mon_thread_init)
    {
#ifdef RW610
        wifi_cau_temperature_enable();
#endif
        mon_thread_events_queue_data = g_mon_event_queue_data;
        ret = os_queue_create(&mon_thread_events, "mon-thread-events", sizeof(struct wlan_message),
                              &mon_thread_events_queue_data);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("unable to create event queue: %d", ret);
            return -WM_FAIL;
        }
#if ((defined(APP_LOWPOWER_ENABLED) && (APP_LOWPOWER_ENABLED == 1)) && \
     (defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)))
        /* For coex app, only register wlan notify callback when APP_LOWPOWER_ENABLED == 1 */
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
        PM_RegisterNotify(kPM_NotifyGroup0, &wlan_notify);
#endif
#endif
#endif
        mon_stack = g_mon_stack;
        /* Host sleep hanshake will be done in IDLE task and infinite
         * while loop is added to wait for hankshake complete to
         * prevent IDLE task from entering suspend state.
         * If mon_thread using same priority of IDLE task, then the
         * mon_thread task could not be scheduled as we did not
         * enabled time slice.
         */
        ret = os_thread_create(&mon_thread, "mon_thread", wlan_mon_thread, 0, &mon_stack, OS_PRIO_3);
        if (ret != 0)
        {
            wlan.cb = NULL;
            wifi_unregister_event_queue(&wlan.events);
            os_queue_delete(&wlan.events);
            os_thread_delete(&wlan.cm_main_thread);
            os_semaphore_delete(&wlan.scan_lock);
            os_mutex_delete(&reset_lock);
            return -WM_FAIL;
        }
        mon_thread_init = 1;
    }
#endif

    wlan.running = 1;

    wlan.status = WLCMGR_ACTIVATED;

#ifdef CONFIG_WPS2
    wlcm_d("WPS started");
    wps_start(&wps_conf);

    wlan_wps.wps_stack = g_wps_stack;
    ret = os_thread_create(&wlan_wps.wps_main_thread, "wps", wps_main, 0, &wlan_wps.wps_stack, OS_PRIO_3);
    if (ret != WM_SUCCESS)
    {
        wlan.cb = NULL;
        wifi_unregister_event_queue(&wlan.events);
        os_queue_delete(&wlan.events);
        os_thread_delete(&wlan.cm_main_thread);
        os_semaphore_delete(&wlan.scan_lock);
        os_mutex_delete(&reset_lock);
        return -WM_FAIL;
    }
#endif

#ifdef CONFIG_CPU_LOADING
    cpu_loading.status = CPU_LOADING_STATUS_DEAD;
    cpu_loading.sampling_period = CPU_LOADING_PERIOD;
#endif

    ret = os_timer_create(&wlan.assoc_timer, "assoc-timer", os_msec_to_ticks(BAD_MIC_TIMEOUT), &assoc_timer_cb, NULL,
                          OS_TIMER_ONE_SHOT, OS_TIMER_NO_ACTIVATE);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Unable to create unicast bad mic timer");
        return ret;
    }

#ifdef CONFIG_WPA_SUPP
    ret = os_timer_create(&wlan.supp_status_timer, "supp-status-timer", os_msec_to_ticks(SUPP_STATUS_TIMEOUT),
                          &supp_status_timer_cb, NULL, OS_TIMER_PERIODIC, OS_TIMER_NO_ACTIVATE);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Unable to create supp status timer");
        return ret;
    }
#endif

#ifdef CONFIG_11K

    memset(&wlan.nbr_rpt, 0x00, sizeof(wlan_rrm_neighbor_report_t));
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V)
    ret = os_timer_create(&wlan.neighbor_req_timer, "neighbor-req-timer", os_msec_to_ticks(NEIGHBOR_REQ_TIMEOUT),
                          &neighbor_req_timer_cb, NULL, OS_TIMER_ONE_SHOT, OS_TIMER_NO_ACTIVATE);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Unable to create neighbor request timer");
        return ret;
    }
#endif

#ifndef __ZEPHYR__
#ifdef SD9177
    ret = os_timer_create(&wlan.poll_timer, "poll-timer", os_msec_to_ticks(POLL_TIMEOUT),
                          &poll_timer_cb, NULL, OS_TIMER_PERIODIC, OS_TIMER_NO_ACTIVATE);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Unable to start poll timer");
        return ret;
    }
#endif
#endif

#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
    ret = os_timer_create(&wlan.ft_roam_timer, "ft-roam-timer", os_msec_to_ticks(FT_ROAM_TIMEOUT),
                          &ft_roam_timer_cb, NULL, OS_TIMER_ONE_SHOT, OS_TIMER_NO_ACTIVATE);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Unable to create ft roam timer");
        return ret;
    }
#endif
#endif

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
#ifdef IR_OUTBAND_TRIGGER_GPIO
    gpio_pin_config_t out_config = {kGPIO_DigitalOutput, 1, kGPIO_NoIntmode};

#if defined(IOMUXC_GPIO_IR_OUTBAND_TRIGGER)
    IOMUXC_SetPinMux(IOMUXC_GPIO_IR_OUTBAND_TRIGGER, /* GPIO_AD_B0_10 is configured as GPIO1_IO10 */
                     0U);
#endif
    GPIO_PinInit(IR_OUTBAND_TRIGGER_GPIO, IR_OUTBAND_TRIGGER_GPIO_PIN, &out_config);
#endif

#endif

    wlan_wait_wlmgr_ready();

#ifdef CONFIG_WIFI_SHELL
#ifdef CONFIG_WIFI_RF_TEST_MODE
    ret = wlan_test_mode_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize WLAN RF test mode CLIs\r\n");
        return 0;
    }
#endif
#if !defined(CONFIG_WIFI_RF_TEST_MODE) || defined(CONFIG_RW610)
    ret = wlan_basic_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize BASIC WLAN CLIs\r\n");
        return 0;
    }
    ret = wlan_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize WLAN CLIs\r\n");
        return 0;
    }
#ifdef CONFIG_SIGMA_AGENT
    ret = ping_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize PING CLI\r\n");
        return 0;
    }
#endif
    ret = wlan_enhanced_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize WLAN Enhanced CLIs\r\n");
        return 0;
    }
#ifdef CONFIG_WPA_SUPP
    ret = wpa_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize WPA SUPP CLIs\r\n");
        return 0;
    }
#endif
#if defined(CONFIG_HOST_SLEEP) && !defined(__ZEPHYR__)
    ret = host_sleep_cli_init();
    if (ret != WM_SUCCESS)
    {
        PRINTF("Failed to initialize WLAN CLIs\r\n");
        return 0;
    }
#endif
#endif
#endif

    return WM_SUCCESS;
}

int wlan_stop(void)
{
    int ret = WM_SUCCESS;
#ifndef RW610
    int total_wait_time = 1000; /* millisecs */
    int check_interval  = 200;  /* millisecs */
    int num_iterations  = total_wait_time / check_interval;
#endif
    if (wlan.status != WLCMGR_ACTIVATED)
    {
        wlcm_e("cannot stop wlcmgr. unexpected status: %d", wlan.status);
        return WLAN_ERROR_STATE;
    }

    if (!wlan.running)
    {
        wlcm_e("cannot stop wlcmgr. unexpected wlan.running: %d", wlan.running);
        return WLAN_ERROR_STATE;
    }
#ifdef OTP_CHANINFO
    wifi_free_fw_region_and_cfp_tables();
#endif

#ifndef RW610
    wlan.running = 0;
    wlan.scan_cb = NULL;

#ifdef CONFIG_WPA_SUPP

    wifi_supp_deinit();

    ret = wpa_supp_deinit();
    if (ret != 0)
    {
        wlcm_e("wpa_supp_deinit failed. status code %d", ret);
        return WLAN_ERROR_STATE;
    }
#endif

    /* We need to wait for scan_lock as wifi scan might have been
     * scheduled, so it must be completed before deleting cm_main_thread
     * here. Otherwise deadlock situation might arrive as both of them
     * share command_lock semaphore.
     */
    ret = os_semaphore_get(&wlan.scan_lock, OS_WAIT_FOREVER);
    if (ret != WM_SUCCESS)
    {
        wlcm_w("failed to get scan lock: %d.", ret);
        return WLAN_ERROR_STATE;
    }
#else
    /* If CONFIG_WIFI_RECOVERY is defined, 0xb2 CMD will be skipped, but dhcp_server_stop()
     * is called in 0xb2 CMD response. So it needs to be called here to stop DHCP server
     */
        dhcp_server_stop();
#endif
    if (wlan.scan_lock)
    {
        ret = os_semaphore_delete(&wlan.scan_lock);
        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to delete scan lock: %d.", ret);
            return WLAN_ERROR_STATE;
        }
        wlan.is_scan_lock = 0;
    }
    wlan.scan_cb = NULL;

    if (wlan.assoc_timer)
    {
        ret = os_timer_delete(&wlan.assoc_timer);
        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to delete assoc timer: %d.", ret);
            return WLAN_ERROR_STATE;
        }
    }

#ifdef CONFIG_WPA_SUPP
    ret = os_timer_delete(&wlan.supp_status_timer);
    if (ret != WM_SUCCESS)
    {
        wlcm_w("failed to delete supp status timer: %d.", ret);
        return WLAN_ERROR_STATE;
    }
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V)
    if (wlan.neighbor_req_timer)
    {
        ret = os_timer_delete(&wlan.neighbor_req_timer);
        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to delete neighbor req timer: %d.", ret);
            return WLAN_ERROR_STATE;
        }
    }
#endif

#ifdef CONFIG_11R
#ifdef CONFIG_WPA_SUPP
    if (wlan.ft_roam_timer)
    {
        ret = os_timer_delete(&wlan.ft_roam_timer);
        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to delete ft roam timer: %d.", ret);
            return WLAN_ERROR_STATE;
        }
    }
#endif
#endif

#ifndef RW610
    /* We need to tell the AP that we're going away, however we've already
     * stopped the main thread so we can't do this by means of the state
     * machine.  Unregister from the wifi interface and explicitly send a
     * deauth request and then proceed to tearing the main thread down. */

    /* Set stop_request and wait for wlcmgr thread to acknowledge it */
    wlan.stop_request = (uint8_t) true;

    wlcm_d("Sent wlcmgr shutdown request. Current State: %d", wlan.status);

    (void)send_user_request(CM_WLAN_USER_REQUEST_SHUTDOWN, 0);

    --num_iterations;
    while (wlan.status != WLCMGR_THREAD_STOPPED && num_iterations)
    {
        --num_iterations;
        os_thread_sleep(os_msec_to_ticks((uint32_t)check_interval));
    }

    if (wlan.status != WLCMGR_THREAD_STOPPED && !num_iterations)
    {
        wlcm_d("Timed out waiting for wlcmgr to stop\r\n");
        wlcm_d("Forcing halt for wlcmgr thread\r\n");
        /* Reinitiailize variable states */
        wlan.status = WLCMGR_THREAD_STOPPED;
    }

    wlan.stop_request = (uint8_t) false;
#endif
    if (wm_wifi.wlc_mgr_event_queue)
    {
        ret = wifi_unregister_event_queue(&wlan.events);

        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to unregister wifi event queue: %d", ret);
            return WLAN_ERROR_STATE;
        }
    }

    if (wlan.events)
    {
        ret = os_queue_delete(&wlan.events);

        if (ret != WM_SUCCESS)
        {
            wlcm_w("failed to delete event queue: %d", ret);
            return WLAN_ERROR_STATE;
        }
    }

#ifdef CONFIG_HOST_SLEEP
    if (wakelock != NULL)
    {
        os_semaphore_delete(&wakelock);
        wakelock = NULL;
    }
#endif

#ifndef RW610
    if (wlan.sta_state > CM_STA_ASSOCIATING)
    {
        (void)wifi_deauthenticate((uint8_t *)wlan.networks[wlan.cur_network_idx].bssid);
        wlan.sta_return_to = CM_STA_IDLE;
    }
    if (wlan.uap_state > CM_UAP_CONFIGURED)
    {
        (void)wifi_uap_stop();
        (void)dhcp_server_stop();
    }

    ret = os_thread_delete(&wlan.cm_main_thread);

    if (ret != WM_SUCCESS)
    {
        wlcm_w("failed to terminate thread: %d", ret);
        return WLAN_ERROR_STATE;
    }

    (void)net_wlan_deinit();

    wlan.status = WLCMGR_INIT_DONE;
    wlcm_d("WLCMGR thread deleted\n\r");
#else
    wlan.running = 0;
    wlan.status  = WLCMGR_INACTIVE;
    memset(&wlan, 0x00, sizeof(wlan));

    wifi_deinit();

    os_rwlock_delete(&sleep_rwlock);
#endif
#ifdef CONFIG_WMM_UAPSD
    if (uapsd_sem != NULL)
    {
        os_semaphore_delete(&uapsd_sem);
        uapsd_sem = NULL;
    }
#endif
    return ret;
}

#define DEF_UAP_IP 0xc0a80a01UL /* 192.168.10.1 */
static unsigned int uap_ip = DEF_UAP_IP;

void wlan_initialize_uap_network(struct wlan_network *net)
{
    (void)memset(net, 0, sizeof(struct wlan_network));
    /* Set profile name */
    (void)strcpy(net->name, "uap-network");
    /* Set channel selection to auto (0) */
    net->channel = 0;
    /* Set network type to uAP */
    net->type = WLAN_BSS_TYPE_UAP;
    /* Set network role to uAP */
    net->role = WLAN_BSS_ROLE_UAP;
    /* Set IP address to 192.168.10.1 */
    net->ip.ipv4.address = htonl(uap_ip);
    /* Set default gateway to 192.168.10.1 */
    net->ip.ipv4.gw = htonl(uap_ip);
    /* Set netmask to 255.255.255.0 */
    net->ip.ipv4.netmask = htonl(0xffffff00UL);
    /* Specify address type as static assignment */
    net->ip.ipv4.addr_type = ADDR_TYPE_STATIC;
}

void wlan_initialize_sta_network(struct wlan_network *net)
{
    (void)memset(net, 0, sizeof(struct wlan_network));
    /* Set profile name */
    (void)strcpy(net->name, "sta-network");
    /* Set channel selection to auto (0) */
    net->channel = 0;
    /* Set network type to sta */
    net->type = WLAN_BSS_TYPE_STA;
    /* Set network role to sta */
    net->role = WLAN_BSS_ROLE_STA;
    /* Specify address type as dynamic assignment */
    net->ip.ipv4.addr_type = ADDR_TYPE_DHCP;
}

static bool isHexNumber(const char *str, const uint8_t len)
{
    for (int i = 0; i < len; ++i)
    {
        if (('0' > str[i] || '9' < str[i]) && ('A' > str[i] || 'F' < str[i]) && ('a' > str[i] || 'f' < str[i]))
        {
            return false;
        }
    }

    return true;
}

static bool wlan_is_key_valid(struct wlan_network *network)
{
    enum wlan_security_type type = network->security.type;
    bool valid                   = true;

    switch (type)
    {
        case WLAN_SECURITY_WPA:
        case WLAN_SECURITY_WPA2:
        case WLAN_SECURITY_WPA_WPA2_MIXED:
#ifdef CONFIG_11R
        case WLAN_SECURITY_WPA2_FT:
#endif
            /* check the length of PSK phrase */
            if (network->security.psk_len < WLAN_PSK_MIN_LENGTH || network->security.psk_len >= WLAN_PSK_MAX_LENGTH)
            {
                wlcm_e(
                    "Invalid passphrase length %d "
                    "(expected ASCII characters: 8..63)",
                    network->security.psk_len);
                return false;
            }
            if ((network->security.psk_len == WLAN_PSK_MAX_LENGTH - 1) &&
                (isHexNumber(network->security.psk, network->security.psk_len) == false))
            {
                wlcm_e(
                    "Invalid hexadecimal digits psk"
                    "(expected Hexadecimal digits: 64)");
                return false;
            }
            break;
        case WLAN_SECURITY_WPA2_WPA3_SAE_MIXED:
            /* check the length of PSK phrase */
            if (network->security.psk_len < WLAN_PSK_MIN_LENGTH || network->security.psk_len >= WLAN_PSK_MAX_LENGTH)
            {
                wlcm_e(
                    "Invalid passphrase length %d "
                    "(expected ASCII characters: 8..63)",
                    network->security.psk_len);
                return false;
            }
            if ((network->security.psk_len == WLAN_PSK_MAX_LENGTH - 1) &&
                (isHexNumber(network->security.psk, network->security.psk_len) == false))
            {
                wlcm_e(
                    "Invalid hexadecimal digits psk"
                    "(expected Hexadecimal digits: 64)");
                return false;
            }
        case WLAN_SECURITY_WPA3_SAE:
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
        case WLAN_SECURITY_WPA3_FT_SAE:
#endif
#endif
            if (network->security.password_len < WLAN_PASSWORD_MIN_LENGTH ||
                network->security.password_len > WLAN_PASSWORD_MAX_LENGTH)
            {
                wlcm_e("Invalid password length %d (expected 8..255)", network->security.password_len);
                return false;
            }
            break;
        case WLAN_SECURITY_NONE:
        case WLAN_SECURITY_WILDCARD:
#ifdef CONFIG_OWE
        case WLAN_SECURITY_OWE_ONLY:
#endif
#ifdef CONFIG_WPA2_ENTP
        case WLAN_SECURITY_EAP_TLS:
#elif CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_TLS
        case WLAN_SECURITY_EAP_TLS:
        case WLAN_SECURITY_EAP_TLS_SHA256:
#ifdef CONFIG_11R
        case WLAN_SECURITY_EAP_TLS_FT:
        case WLAN_SECURITY_EAP_TLS_FT_SHA384:
#endif
#endif
#ifdef CONFIG_EAP_TTLS
        case WLAN_SECURITY_EAP_TTLS:
#ifdef CONFIG_EAP_MSCHAPV2
        case WLAN_SECURITY_EAP_TTLS_MSCHAPV2:
#endif
#endif
#ifdef CONFIG_EAP_PEAP
#ifdef CONFIG_EAP_MSCHAPV2
        case WLAN_SECURITY_EAP_PEAP_MSCHAPV2:
#endif
#ifdef CONFIG_EAP_TLS
        case WLAN_SECURITY_EAP_PEAP_TLS:
#endif
#ifdef CONFIG_EAP_GTC
        case WLAN_SECURITY_EAP_PEAP_GTC:
#endif
#endif
#ifdef CONFIG_EAP_SIM
        case WLAN_SECURITY_EAP_SIM:
#endif
#ifdef CONFIG_EAP_AKA
        case WLAN_SECURITY_EAP_AKA:
#endif
#ifdef CONFIG_EAP_AKA_PRIME
        case WLAN_SECURITY_EAP_AKA_PRIME:
#endif
#ifdef CONFIG_EAP_FAST
#ifdef CONFIG_EAP_MSCHAPV2
        case WLAN_SECURITY_EAP_FAST_MSCHAPV2:
#endif
#ifdef CONFIG_EAP_GTC
        case WLAN_SECURITY_EAP_FAST_GTC:
#endif
#endif
#endif
#endif
#ifdef CONFIG_PEAP_MSCHAPV2
        case WLAN_SECURITY_EAP_PEAP_MSCHAPV2:
#endif
            valid = true;
            break;
        case WLAN_SECURITY_WEP_OPEN:
        case WLAN_SECURITY_WEP_SHARED:
            valid = false;
            break;
        default:

            valid = false;
            break;
    }

    if (valid == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_TLS
static bool wlan_is_eap_tls_security(enum wlan_security_type security)
{
    if ((security == WLAN_SECURITY_EAP_TLS) || (security == WLAN_SECURITY_EAP_TLS_SHA256)
#ifdef CONFIG_11R
        || (security == WLAN_SECURITY_EAP_TLS_FT) || (security == WLAN_SECURITY_EAP_TLS_FT_SHA384)
#endif
       )
        return true;
    return false;
}
#endif

#ifdef CONFIG_EAP_TTLS
static bool wlan_is_eap_ttls_security(enum wlan_security_type security)
{
    if (security == WLAN_SECURITY_EAP_TTLS)
        return true;
#ifdef CONFIG_EAP_MSCHAPV2
    if (security == WLAN_SECURITY_EAP_TTLS_MSCHAPV2)
        return true;
#endif

    return false;
}
#endif

#ifdef CONFIG_EAP_PEAP
static bool wlan_is_eap_peap_security(enum wlan_security_type security)
{
#ifdef CONFIG_EAP_MSCHAPV2
    if (security == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
        return true;
#endif
#ifdef CONFIG_EAP_GTC
    if (security == WLAN_SECURITY_EAP_PEAP_GTC)
        return true;
#endif
#ifdef CONFIG_EAP_TLS
    if (security == WLAN_SECURITY_EAP_PEAP_TLS)
        return true;
#endif
    return false;
}
#endif

#ifdef CONFIG_EAP_FAST
static bool wlan_is_eap_fast_security(enum wlan_security_type security)
{
#ifdef CONFIG_EAP_MSCHAPV2
    if (security == WLAN_SECURITY_EAP_FAST_MSCHAPV2)
        return true;
#endif
#ifdef CONFIG_EAP_GTC
    if (security == WLAN_SECURITY_EAP_FAST_GTC)
        return true;
#endif
    return false;
}

static bool wlan_is_skip_cert_cfg(enum wlan_security_type security)
{
#ifdef CONFIG_EAP_MSCHAPV2
    if (security == WLAN_SECURITY_EAP_TTLS_MSCHAPV2)
        return true;

    if (security == WLAN_SECURITY_EAP_PEAP_MSCHAPV2)
        return true;
#endif

    return false;
}
#endif
#endif
#endif

static int wlan_key_mgmt_wpa_psk(int akm)
{
    int rakm = (WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_FT_PSK | WLAN_KEY_MGMT_PSK_SHA256);

    if (akm == 0)
    {
        return 0;
    }

    akm &= ~(WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_FT_PSK | WLAN_KEY_MGMT_PSK_SHA256);

    return (!akm && rakm);
}

#ifdef CONFIG_11R
static int wlan_key_mgmt_ft_psk(int akm)
{
    int rakm = WLAN_KEY_MGMT_FT_PSK;

    if (akm == 0)
    {
        return 0;
    }

    akm &= ~WLAN_KEY_MGMT_FT_PSK;

    return (!akm && rakm);
}
#endif

static int wlan_key_mgmt_sae(int akm)
{
    int rakm;

    if (akm == 0)
    {
        return 0;
    }

    rakm = (
#ifdef CONFIG_WPA_SUPP_DPP
            WLAN_KEY_MGMT_DPP |
#endif
            WLAN_KEY_MGMT_SAE);

    akm &= ~(
#ifdef CONFIG_WPA_SUPP_DPP
            WLAN_KEY_MGMT_DPP |
#endif
            WLAN_KEY_MGMT_SAE);

    return (!akm && rakm);
}

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
static int wlan_key_mgmt_ft_sae(int akm)
{
    int rakm =~WLAN_KEY_MGMT_FT_SAE;

    if (akm == 0)
    {
        return 0;
    }

    akm &= ~WLAN_KEY_MGMT_FT_SAE;

    return (!akm && rakm);
}
#endif
#endif

static int wlan_key_mgmt_wpa_psk_sae(int akm)
{
    int rakm;

    if (akm == 0)
    {
        return 0;
    }

    rakm = (
#ifdef CONFIG_WPA_SUPP_DPP
                WLAN_KEY_MGMT_DPP |
#endif
                WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_PSK_SHA256 | WLAN_KEY_MGMT_SAE);

    akm &= ~(
#ifdef CONFIG_WPA_SUPP_DPP
            WLAN_KEY_MGMT_DPP |
#endif
            WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_PSK_SHA256 | WLAN_KEY_MGMT_SAE);

    return (!akm && rakm);
}

#ifdef CONFIG_OWE
static int wlan_key_mgmt_owe(int akm)
{
    int rakm = WLAN_KEY_MGMT_OWE;

    if (akm == 0)
    {
        return 0;
    }

    akm &= ~WLAN_KEY_MGMT_OWE;

    return (!akm && rakm);
}
#endif

#ifdef CONFIG_WPA_SUPP_DPP
static int wlan_key_mgmt_dpp(int akm)
{
    int rakm = WLAN_KEY_MGMT_DPP;

    if (akm == 0)
    {
        return 0;
    }

    akm &= ~WLAN_KEY_MGMT_DPP;

    return (!akm && rakm);
}
#endif

int wlan_add_network(struct wlan_network *network)
{
    int pos = -1;
    int i;
    unsigned int len;
    int ret;

    if (!wlan.running)
    {
        return WLAN_ERROR_STATE;
    }

#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

    if (network == NULL)
    {
        return -WM_E_INVAL;
    }

    if ((network->channel > MAX_CHANNELS_BG) && ISSUPP_NO5G(mlan_adap->fw_cap_ext))
    {
        wlcm_e("Not support 5G, please set 2G channel");
        return -WM_E_INVAL;
    }
    if ((network->acs_band == 1) && ISSUPP_NO5G(mlan_adap->fw_cap_ext))
    {
        wlcm_e("Not support 5G, please not set acs_band 1");
        return -WM_E_INVAL;
    }

    if (network->role == WLAN_BSS_ROLE_STA)
    {
        if (is_running() && !is_state(CM_STA_IDLE) && !is_state(CM_STA_ASSOCIATED) && !is_state(CM_STA_CONNECTED))
        {
            return WLAN_ERROR_STATE;
        }
    }

    /* make sure that the network name length is acceptable */
    len = strlen(network->name);
    if (len < WLAN_NETWORK_NAME_MIN_LENGTH || len >= WLAN_NETWORK_NAME_MAX_LENGTH)
    {
        wlcm_e("name length is out of bounds");
        return -WM_E_INVAL;
    }

    /* make sure that either the SSID or BSSID field is present */
    if (network->ssid[0] == '\0' && is_bssid_any(network->bssid))
    {
        wlcm_e("SSID or BSSID is required");
        return -WM_E_INVAL;
    }

    if ((network->role == WLAN_BSS_ROLE_UAP) && (network->ip.ipv4.gw != network->ip.ipv4.address))
    {
        wlcm_e("IP address and Default gateway must be same for uAP");
        return -WM_E_INVAL;
    }

    /* Always set PMF capable bt default */
    network->security.mfpc = 1;

    if (((network->role == WLAN_BSS_ROLE_UAP) || (network->role == WLAN_BSS_ROLE_STA)) &&
        ((network->security.type == WLAN_SECURITY_WPA3_SAE)
#ifdef CONFIG_OWE
         || (network->security.type == WLAN_SECURITY_OWE_ONLY)
#endif
         ))
    {
        network->security.mfpr = 1;
    }

#ifdef CONFIG_WPA2_ENTP
    /* make sure that if in policy wireless connection is allowed
     * only with WPA2 Enterprise AP then add the network
     */
    if ((network->role == WLAN_BSS_ROLE_STA) &&
        ((network->security.type != WLAN_SECURITY_EAP_TLS) ||
         (network->security.type != WLAN_SECURITY_EAP_PEAP_MSCHAPV2)) &&
        wlan.allow_wpa2_enterprise_ap_only)
    {
        return -WM_E_INVAL;
    }
#endif

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    if ((is_ep_valid_security(network->security.type)) && ((network->security.wpa3_sb == 1U) || (network->security.wpa3_sb_192 == 1U)))
    {
        network->security.mfpr = 1;
    }
#endif
#endif

#ifdef CONFIG_11R
    if ((network->role == WLAN_BSS_ROLE_STA) &&
            ((network->security.type == WLAN_SECURITY_WPA2_FT)
#ifdef CONFIG_WPA_SUPP
             || (network->security.type == WLAN_SECURITY_WPA3_FT_SAE)
#endif
            ) && (network->channel != 0U))
    {
        wlcm_e("Specific channel not allowed in FT security");
        return -WM_E_INVAL;
    }
#endif

    if (!is_valid_security(network->security.type))
    {
        wlcm_e("Invalid security type is configured");
        return -WM_E_INVAL;
    }

    if (network->security.key_mgmt == 0)
    {
        if (network->security.type == WLAN_SECURITY_NONE)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_NONE;
        }
        else if ((network->security.type == WLAN_SECURITY_WPA) || (network->security.type == WLAN_SECURITY_WPA2) || (network->security.type == WLAN_SECURITY_WPA_WPA2_MIXED))
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_PSK;
        }
        else if (network->security.type == WLAN_SECURITY_WPA3_SAE)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_SAE;
        }
#ifdef CONFIG_OWE
        else if (network->security.type == WLAN_SECURITY_OWE_ONLY)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_OWE;
        }
#endif
#ifdef CONFIG_11R
        else if (network->security.type == WLAN_SECURITY_WPA2_FT)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_FT_PSK;
        }
#ifdef CONFIG_WPA_SUPP
        else if (network->security.type == WLAN_SECURITY_WPA3_FT_SAE)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_FT_SAE;
        }
#endif
#endif
        else if (network->security.type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED)
        {
            network->security.key_mgmt = WLAN_KEY_MGMT_PSK | WLAN_KEY_MGMT_SAE;
        }
    }

    if ((network->role == WLAN_BSS_ROLE_UAP) || (network->role == WLAN_BSS_ROLE_STA))
    {
        if (network->role == WLAN_BSS_ROLE_STA)
        {
            if ((network->security.type == WLAN_SECURITY_WPA2) && (network->security.mfpc))
            {
                network->security.key_mgmt |= WLAN_KEY_MGMT_PSK_SHA256;
            }
            if ((network->security.type == WLAN_SECURITY_WPA_WPA2_MIXED) && (network->security.mfpr))
            {
                network->security.key_mgmt |= WLAN_KEY_MGMT_PSK_SHA256;
            }
	}
        if (network->role == WLAN_BSS_ROLE_UAP)
        {
            if ((network->security.type == WLAN_SECURITY_WPA2) && (network->security.mfpr))
            {
                network->security.key_mgmt |= WLAN_KEY_MGMT_PSK_SHA256;
            }
        }
    }

    if (((network->role == WLAN_BSS_ROLE_UAP) || (network->role == WLAN_BSS_ROLE_STA)) &&
        ((((network->security.type == WLAN_SECURITY_WPA) || (network->security.type == WLAN_SECURITY_WPA2) || (network->security.type == WLAN_SECURITY_WPA_WPA2_MIXED)) &&
        (!wlan_key_mgmt_wpa_psk(network->security.key_mgmt)))
#ifdef CONFIG_11R
        || ((network->security.type == WLAN_SECURITY_WPA2_FT) && (!wlan_key_mgmt_ft_psk(network->security.key_mgmt)))
#endif
        || ((network->security.type == WLAN_SECURITY_WPA3_SAE) && (!wlan_key_mgmt_sae(network->security.key_mgmt)))
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
        || ((network->security.type == WLAN_SECURITY_WPA3_FT_SAE) && (!wlan_key_mgmt_ft_sae(network->security.key_mgmt)))
#endif
#endif
        || ((network->security.type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED) && (!wlan_key_mgmt_wpa_psk_sae(network->security.key_mgmt)))
#ifdef CONFIG_OWE
        || ((network->security.type == WLAN_SECURITY_OWE_ONLY) && (!wlan_key_mgmt_owe(network->security.key_mgmt)))
#endif
#ifdef CONFIG_WPA_SUPP_DPP
        || ((network->security.type == WLAN_SECURITY_DPP) && (!wlan_key_mgmt_dpp(network->security.key_mgmt)))
#endif
        ))
    {
        wlcm_e("Invalid security/key mgmt is configured");
        return -WM_E_INVAL;
    }

    if (((network->role == WLAN_BSS_ROLE_UAP) || (network->role == WLAN_BSS_ROLE_STA)) &&
        (network->security.key_mgmt == WLAN_KEY_MGMT_PSK_SHA256) &&
        (!network->security.mfpc && !network->security.mfpr))
    {
        wlcm_e("MFP is not configured");
        return -WM_E_INVAL;
    }

    if (((network->role == WLAN_BSS_ROLE_UAP) || (network->role == WLAN_BSS_ROLE_STA)) &&
        (network->security.type == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED) &&
        (!(network->security.mfpc && !network->security.mfpr)))
    {
        wlcm_e("MFP capable only is allowed");
        return -WM_E_INVAL;
    }

    if (wlan_is_key_valid(network) == false)
    {
        wlcm_e("Invalid passphrase/password is configured");
        return -WM_E_INVAL;
    }

    /* Make sure network type is set correctly if not
     * set correct values as per role*/
    if ((network->type == WLAN_BSS_TYPE_STA) || (network->type == WLAN_BSS_TYPE_ANY))
    {
        if (network->role == WLAN_BSS_ROLE_UAP)
        {
            network->type = WLAN_BSS_TYPE_UAP;
#ifdef CONFIG_WPA_SUPP
            netif = net_get_uap_interface();
#endif
        }
        else if (network->role == WLAN_BSS_ROLE_STA)
        {
            network->type = WLAN_BSS_TYPE_STA;
#ifdef CONFIG_WPA_SUPP
            netif = net_get_sta_interface();
#endif
        }
        else
        { /* Do Nothing */
        }
    }

    if (network->role == WLAN_BSS_ROLE_UAP)
    {
        if (network->channel != 14)
        {
        /* If no capability was configured, set capa up to 11ax by default */
        if (!network->wlan_capa)
            network->wlan_capa =
#ifdef CONFIG_11AX
                WIFI_SUPPORT_11AX |
#endif
#ifdef CONFIG_11AC
                WIFI_SUPPORT_11AC |
#endif
                WIFI_SUPPORT_11N | WIFI_SUPPORT_LEGACY;
        }
        else
        {
            network->wlan_capa = WIFI_SUPPORT_LEGACY;
        }

#ifdef CONFIG_11AX
        if (network->wlan_capa & WIFI_SUPPORT_11AX)
        {
            network->dot11ax = 1;
        }
#endif
#ifdef CONFIG_11AC
        if (network->wlan_capa & WIFI_SUPPORT_11AC)
        {
            network->dot11ac = 1;
        }
#endif
        if (network->wlan_capa & WIFI_SUPPORT_11N)
        {
            network->dot11n = 1;
        }
    }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    if (network->role == WLAN_BSS_ROLE_UAP)
    {

        if (network->ht_capab == 0)
        {
            network->ht_capab = wifi_get_default_ht_capab();
        }
#ifdef CONFIG_11AC
        if (network->vht_capab == 0)
        {
            network->vht_capab = wifi_get_default_vht_capab();
        }
        if (network->vht_oper_chwidth == 0)
        {
            network->vht_oper_chwidth = 1;
        }
#endif
#ifdef CONFIG_11AX
        if (network->he_oper_chwidth == 0)
        {
            network->he_oper_chwidth = 1;
        }
#endif
    }
#endif
    if (network->security.sae_groups == NULL)
    {
        network->security.sae_groups = wlan_string_dup("19");
    }
#ifdef CONFIG_OWE
    if (network->security.owe_groups == NULL)
    {
        network->security.owe_groups = wlan_string_dup("19");
    }
#endif
    if (network->security.group_cipher == 0)
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            network->security.group_cipher = WLAN_CIPHER_GCMP_256;
        }
        else if (network->security.wpa3_sb == 1U)
        {
            network->security.group_cipher = WLAN_CIPHER_CCMP_256;
        }
        else
#endif
        {
            network->security.group_cipher = WLAN_CIPHER_CCMP;
        }
    }
    else
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            if (network->security.group_cipher != WLAN_CIPHER_GCMP_256)
            {
                wlcm_e("Group cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else if (network->security.wpa3_sb == 1U)
        {
            if ((network->security.group_cipher != WLAN_CIPHER_GCMP_256) && (network->security.group_cipher != WLAN_CIPHER_CCMP_256) && (network->security.group_cipher != WLAN_CIPHER_GCMP) && (network->security.group_cipher != WLAN_CIPHER_CCMP))
            {
                wlcm_e("Group cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else
#endif
            if (network->security.type != WLAN_SECURITY_NONE)
        {
                if ((network->security.group_cipher != WLAN_CIPHER_CCMP) && (network->security.group_cipher != WLAN_CIPHER_TKIP))
                {
                    wlcm_e("Group cipher configuration not allowed");
                    return -WM_E_INVAL;
                }
        }
        else
        {
            wlcm_e("Group cipher configuration not allowed");
            return -WM_E_INVAL;
        }
    }

    if (network->security.pairwise_cipher == 0)
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            network->security.pairwise_cipher = WLAN_CIPHER_GCMP_256;
        }
        else if (network->security.wpa3_sb == 1U)
        {
            network->security.pairwise_cipher = WLAN_CIPHER_CCMP_256;
        }
        else
#endif
        {
            network->security.pairwise_cipher = WLAN_CIPHER_CCMP;
        }
    }
    else
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            if (network->security.pairwise_cipher != WLAN_CIPHER_GCMP_256)
            {
                wlcm_e("Pairwise cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else if (network->security.wpa3_sb == 1U)
        {
            if ((network->security.pairwise_cipher != WLAN_CIPHER_GCMP_256) && (network->security.pairwise_cipher != WLAN_CIPHER_CCMP_256) && (network->security.pairwise_cipher != WLAN_CIPHER_GCMP) && (network->security.pairwise_cipher != WLAN_CIPHER_CCMP))
            {
                wlcm_e("Pairwise cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else
#endif
            if (network->security.type != WLAN_SECURITY_NONE)
        {
                if ((network->security.pairwise_cipher != WLAN_CIPHER_CCMP) && (network->security.pairwise_cipher != WLAN_CIPHER_TKIP))
                {
                    wlcm_e("Pairwise cipher configuration not allowed");
                    return -WM_E_INVAL;
                }
        }
        else
        {
            wlcm_e("Pairwise cipher configuration not allowed");
            return -WM_E_INVAL;
        }
    }

    if (network->security.group_mgmt_cipher == 0)
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            network->security.group_mgmt_cipher = WLAN_CIPHER_BIP_GMAC_256;
        }
        else if (network->security.wpa3_sb == 1U)
        {
            network->security.group_mgmt_cipher = WLAN_CIPHER_BIP_CMAC_256;
        }
        else
#endif
        {
            network->security.group_mgmt_cipher = WLAN_CIPHER_AES_128_CMAC;
        }
    }
    else
    {
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
        if (network->security.wpa3_sb_192 == 1U)
        {
            if (network->security.group_mgmt_cipher != WLAN_CIPHER_BIP_GMAC_256)
            {
                wlcm_e("Group mgmt cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else if (network->security.wpa3_sb == 1U)
        {
            if ((network->security.group_mgmt_cipher != WLAN_CIPHER_BIP_GMAC_256) && (network->security.group_mgmt_cipher != WLAN_CIPHER_BIP_CMAC_256) && (network->security.group_mgmt_cipher != WLAN_CIPHER_BIP_GMAC_128) && (network->security.group_mgmt_cipher != WLAN_CIPHER_AES_128_CMAC))
            {
                wlcm_e("Group mgmt cipher configuration not allowed");
                return -WM_E_INVAL;
            }
        }
        else
#endif
            if (network->security.type != WLAN_SECURITY_NONE)
        {
                if (network->security.group_mgmt_cipher != WLAN_CIPHER_AES_128_CMAC)
                {
                    wlcm_e("Group mgmt cipher configuration not allowed");
                    return -WM_E_INVAL;
                }
        }
        else
        {
            wlcm_e("Group mgmt cipher configuration not allowed");
            return -WM_E_INVAL;
        }
    }

#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    if (
#ifdef CONFIG_EAP_TLS
            (wlan_is_eap_tls_security(network->security.type)) ||
#endif
#ifdef CONFIG_EAP_TTLS
            (wlan_is_eap_ttls_security(network->security.type)) ||
#endif
#ifdef CONFIG_EAP_PEAP
            (wlan_is_eap_peap_security(network->security.type)) ||
#endif
#ifdef CONFIG_EAP_FAST
            (wlan_is_eap_fast_security(network->security.type)) ||
#endif
            false)
    {
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
        if (network->role == WLAN_BSS_ROLE_UAP)
        {
            /* Specify CA certificate */
            network->security.ca_cert_len =
                wlan_get_entp_cert_files(FILE_TYPE_ENTP_CA_CERT, &network->security.ca_cert_data);
            if (network->security.ca_cert_len == 0)
            {
                wlan_free_entp_cert_files();
                wlcm_e("CA cert is not configured");
                return -WM_E_INVAL;
            }

            /* Specify Server certificate */
            network->security.server_cert_len =
                wlan_get_entp_cert_files(FILE_TYPE_ENTP_SERVER_CERT, &network->security.server_cert_data);
            if (network->security.server_cert_len == 0)
            {
                wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                os_mem_free(network->security.ca_cert_data);
#endif
                wlcm_e("Server cert is not configured");
                return -WM_E_INVAL;
            }
            /* Specify Server key */
            network->security.server_key_len =
                wlan_get_entp_cert_files(FILE_TYPE_ENTP_SERVER_KEY, &network->security.server_key_data);
            if (network->security.server_key_len == 0)
            {
                wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                os_mem_free(network->security.ca_cert_data);
                os_mem_free(network->security.server_cert_data);
#endif
                wlcm_e("Server key is not configured");
                return -WM_E_INVAL;
            }
            /* Specify DH params */
            network->security.dh_len = wlan_get_entp_cert_files(FILE_TYPE_ENTP_DH_PARAMS, &network->security.dh_data);
            if (network->security.dh_len == 0)
            {
                wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                os_mem_free(network->security.ca_cert_data);
                os_mem_free(network->security.server_cert_data);
                os_mem_free(network->security.server_key_data);
#endif
                wlcm_e("DH params are not configured");
                return -WM_E_INVAL;
            }

#ifdef CONFIG_EAP_FAST
            if (wlan_is_eap_fast_security(network->security.type))
            {
                if (strlen(network->security.pac_opaque_encr_key) != (PAC_OPAQUE_ENCR_KEY_MAX_LENGTH - 1))
                {
                    wlcm_e("Invalid PAC Opaque Encryption key");
                    return -WM_E_INVAL;
                }
                if (strlen(network->security.a_id) != (A_ID_MAX_LENGTH - 1))
                {
                    wlcm_e("Invalid authority identity(a_id)");
                    return -WM_E_INVAL;
                }
            }
#endif
        }
        else
#endif
#endif
        {
            if (false == wlan_is_skip_cert_cfg(network->security.type))
            {
                /* Specify CA certificate */
                network->security.ca_cert_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CA_CERT, &network->security.ca_cert_data);
                if (network->security.ca_cert_len == 0)
                {
                    wlan_free_entp_cert_files();
                    wlcm_e("CA cert is not configured");
                    return -WM_E_INVAL;
                }

                /* Specify Client certificate */
                network->security.client_cert_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CLIENT_CERT, &network->security.client_cert_data);
                if (network->security.client_cert_len == 0)
                {
                    wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                    os_mem_free(network->security.ca_cert_data);
#endif
                    wlcm_e("Client cert is not configured");
                    return -WM_E_INVAL;
                }
                /* Specify Client key */
                network->security.client_key_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CLIENT_KEY, &network->security.client_key_data);
                if (network->security.client_key_len == 0)
                {
                    wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                    os_mem_free(network->security.ca_cert_data);
                    os_mem_free(network->security.client_cert_data);
#endif
                    wlcm_e("Client key is not configured");
                    return -WM_E_INVAL;
                }
            }
        }

        if (WLAN_SECURITY_EAP_TTLS == network->security.type)
        {
            if (network->role == WLAN_BSS_ROLE_STA)
            {

                /* Specify CA certificate2 */
                network->security.ca_cert2_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CA_CERT2, &network->security.ca_cert2_data);
                if (network->security.ca_cert2_len == 0)
                {
                    wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                    os_mem_free(network->security.ca_cert_data);
                    os_mem_free(network->security.client_cert_data);
                    os_mem_free(network->security.client_key_data);
#endif
                    wlcm_e("CA cert2 is not configured");
                    return -WM_E_INVAL;
                }
                /* Specify Client certificate2 */
                network->security.client_cert2_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CLIENT_CERT, &network->security.client_cert2_data);
                if (network->security.client_cert2_len == 0)
                {
                    wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                    os_mem_free(network->security.ca_cert_data);
                    os_mem_free(network->security.client_cert_data);
                    os_mem_free(network->security.client_key_data);
                    os_mem_free(network->security.ca_cert2_data);
#endif
                    wlcm_e("Client cert2 is not configured");
                    return -WM_E_INVAL;
                }
                /* Specify Client key2 */
                network->security.client_key2_len =
                    wlan_get_entp_cert_files(FILE_TYPE_ENTP_CLIENT_KEY, &network->security.client_key2_data);
                if (network->security.client_key_len == 0)
                {
                    wlan_free_entp_cert_files();
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
                    os_mem_free(network->security.ca_cert_data);
                    os_mem_free(network->security.client_cert_data);
                    os_mem_free(network->security.client_key_data);
                    os_mem_free(network->security.ca_cert2_data);
                    os_mem_free(network->security.client_cert2_data);
#endif
                    wlcm_e("Client key2 is not configured");
                    return -WM_E_INVAL;
                }
            }
        }
    }
#endif
#endif
    /* Find a slot for the new network but check all existing networks in
     * case the new one has a duplicate name, which is not allowed. */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0')
        {
            if (strlen(wlan.networks[i].name) == len && !strncmp(wlan.networks[i].name, network->name, len))
            {
                return -WM_E_INVAL;
            }
        }
        else if (pos == -1)
        {
            pos = i;
        }
        else
        { /* Do Nothing */
        }
    }

    if (pos < 0)
    {
        return -WM_E_NOMEM;
    }

    wlan.networks[pos].dtim_period = network->dtim_period;
    wlan.networks[pos].acs_band    = network->acs_band;
    /* save and set private fields */
    (void)memcpy((void *)&wlan.networks[pos], (const void *)network, sizeof(struct wlan_network));
    wlan.networks[pos].ssid_specific    = (uint8_t)(network->ssid[0] != '\0');
    wlan.networks[pos].bssid_specific   = (uint8_t)!is_bssid_any(network->bssid);
    wlan.networks[pos].channel_specific = (uint8_t)(network->channel != 0U);
    if (wlan.networks[pos].channel_specific == 1U)
    {
#ifdef CONFIG_5GHz_SUPPORT
        if (network->channel > MAX_CHANNELS_BG)
        {
            wlan.networks[pos].acs_band    = 1;
        }
        else
#endif
        {
            wlan.networks[pos].acs_band    = 0;
        }
    }

    if (network->security.type != WLAN_SECURITY_WILDCARD)
    {
        wlan.networks[pos].security_specific = 1;
    }

#ifndef CONFIG_WPA_SUPP
    if ((network->role == WLAN_BSS_ROLE_STA) &&
        (network->security.type != WLAN_SECURITY_NONE && network->security.type != WLAN_SECURITY_WEP_OPEN))
    {
        ret = wifi_send_clear_wpa_psk((int)network->role, network->ssid);
        if (ret != WM_SUCCESS)
        {
            return WLAN_ERROR_ACTION;
        }
    }
#endif

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_WPS
    if (!wlan.wps_session_attempt)
    {
#endif
        ret = wpa_supp_add_network(netif, &wlan.networks[pos]);
        if (ret < 0)
        {
            memset((void *)&wlan.networks[pos], 0x00, sizeof(struct wlan_network));
            return -WM_E_NOMEM;
        }
#ifdef CONFIG_WPA_SUPP_WPS
    }
#endif
#endif

    wlan.num_networks++;

    return WM_SUCCESS;
}

uint8_t wlan_check_11n_capa(unsigned int channel)
{
    uint8_t enable_11n = false;
    uint16_t fw_bands  = 0U;

    wifi_get_fw_info(MLAN_BSS_TYPE_UAP, &fw_bands);

    if (channel > 14 && (fw_bands & BAND_AN))
    {
        enable_11n = true;
    }
    else if (channel <= 14 && (fw_bands & BAND_GN))
    {
        enable_11n = true;
    }
    return enable_11n;
}

uint8_t wlan_check_11ac_capa(unsigned int channel)
{
    uint8_t enable_11ac = false;
    uint16_t fw_bands   = 0U;

    wifi_get_fw_info(MLAN_BSS_TYPE_UAP, &fw_bands);

#ifdef CONFIG_11AC
    if (channel > 14 && (fw_bands & BAND_AAC))
    {
        enable_11ac = true;
    }
    else if (channel <= 14 && (fw_bands & BAND_GAC))
    {
        enable_11ac = true;
    }
#endif
    return enable_11ac;
}

uint8_t wlan_check_11ax_capa(unsigned int channel)
{
    uint8_t enable_11ax = false;
    uint16_t fw_bands   = 0U;

    wifi_get_fw_info(MLAN_BSS_TYPE_UAP, &fw_bands);

#ifdef CONFIG_11AX
    if (channel > 14 && (fw_bands & BAND_AAX))
    {
        enable_11ax = true;
    }
    else if (channel <= 14 && (fw_bands & BAND_GAX))
    {
        enable_11ax = true;
    }
#endif
    return enable_11ax;
}

int wlan_remove_network(const char *name)
{
    unsigned int len, i;
#ifdef CONFIG_WPA_SUPP
    int ret = -WM_E_INVAL;
    struct netif *netif = net_get_sta_interface();
#endif

    if (!is_running())
    {
        return WLAN_ERROR_STATE;
    }

    if (name == NULL)
    {
        return -WM_E_INVAL;
    }

    len = strlen(name);

    /* find the first network whose name matches and clear it out */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && strlen(wlan.networks[i].name) == len &&
            !strncmp(wlan.networks[i].name, name, len))
        {
            if (wlan.running && wlan.cur_network_idx == i)
            {
                return WLAN_ERROR_STATE;
            }
            if (wlan.cur_uap_network_idx == i)
            {
            	return WLAN_ERROR_STATE;
            }
#ifdef CONFIG_WPA2_ENTP
            if (wlan.networks[i].security.tls_cert.ca_chain)
            {
                wm_mbedtls_free_cert(wlan.networks[i].security.tls_cert.ca_chain);
            }
            if (wlan.networks[i].security.tls_cert.own_cert)
            {
                wm_mbedtls_free_cert(wlan.networks[i].security.tls_cert.own_cert);
            }
            if (wlan.networks[i].security.tls_cert.own_key)
            {
                wm_mbedtls_free_key(wlan.networks[i].security.tls_cert.own_key);
            }
#endif
#ifdef CONFIG_WPA_SUPP
            if (wlan.networks[i].role == WLAN_BSS_ROLE_STA)
            {
                netif = net_get_sta_interface();
            }
            else if (wlan.networks[i].role == WLAN_BSS_ROLE_UAP)
            {
                netif = net_get_uap_interface();
            }
            else
            {
                /* Do nothing */
            }
            ret = wpa_supp_remove_network(netif, &wlan.networks[i]);
            if (ret < 0)
            {
                return WLAN_ERROR_STATE;
            }

            if (wlan.networks[i].security.sae_groups)
            {
                os_mem_free(wlan.networks[i].security.sae_groups);
                wlan.networks[i].security.sae_groups = NULL;
            }

            if (wlan.networks[i].security.owe_groups)
            {
                os_mem_free(wlan.networks[i].security.owe_groups);
                wlan.networks[i].security.owe_groups = NULL;
            }
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
            if (wlan.networks[i].role == WLAN_BSS_ROLE_STA)
            {
                if (wlan.networks[i].security.ca_cert_data)
                {
                    os_mem_free(wlan.networks[i].security.ca_cert_data);
                }
                if (wlan.networks[i].security.client_cert_data)
                {
                    os_mem_free(wlan.networks[i].security.client_cert_data);
                }
                if (wlan.networks[i].security.client_key_data)
                {
                    os_mem_free(wlan.networks[i].security.client_key_data);
                }
                if (wlan.networks[i].security.ca_cert2_data)
                {
                    os_mem_free(wlan.networks[i].security.ca_cert2_data);
                }
                if (wlan.networks[i].security.client_cert2_data)
                {
                    os_mem_free(wlan.networks[i].security.client_cert2_data);
                }
                if (wlan.networks[i].security.client_key2_data)
                {
                    os_mem_free(wlan.networks[i].security.client_key2_data);
                }
            }
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
            else if (wlan.networks[i].role == WLAN_BSS_ROLE_UAP)
            {
                if (wlan.networks[i].security.ca_cert_data)
                {
                    os_mem_free(wlan.networks[i].security.ca_cert_data);
                }
                if (wlan.networks[i].security.server_cert_data)
                {
                    os_mem_free(wlan.networks[i].security.server_cert_data);
                }
                if (wlan.networks[i].security.server_key_data)
                {
                    os_mem_free(wlan.networks[i].security.server_key_data);
                }
            }
#endif
#endif
#endif
#endif
#ifdef CONFIG_WPA_SUPP_DPP
            if (wlan.networks[i].security.dpp_connector)
            {
                os_mem_free(wlan.networks[i].security.dpp_connector);
            }
            if (wlan.networks[i].security.dpp_c_sign_key)
            {
                os_mem_free(wlan.networks[i].security.dpp_c_sign_key);
            }
            if (wlan.networks[i].security.dpp_net_access_key)
            {
                os_mem_free(wlan.networks[i].security.dpp_net_access_key);
            }
#endif
#endif
            (void)memset(&wlan.networks[i], 0, sizeof(struct wlan_network));
            wlan.num_networks--;
            return WM_SUCCESS;
        }
    }
    /* network name wasn't found */
    return -WM_E_INVAL;
}

int wlan_get_network_count(unsigned int *count)
{
    if (count == NULL)
    {
        return -WM_E_INVAL;
    }

    *count = wlan.num_networks;
    return WM_SUCCESS;
}

int wlan_get_current_network(struct wlan_network *network)
{
    short rssi;
    int snr;

    if (network == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED) || is_state(CM_STA_AUTHENTICATED)))
    {
        (void)memcpy((void *)network, (const void *)&wlan.networks[wlan.cur_network_idx], sizeof(struct wlan_network));

        wlan_get_current_signal_strength(&rssi, &snr);

        network->rssi = rssi;

        return WM_SUCCESS;
    }

    return WLAN_ERROR_STATE;
}

int wlan_get_current_network_ssid(char *ssid)
{
    if (ssid == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED) || is_state(CM_STA_AUTHENTICATED)))
    {
        (void)memcpy((void *)ssid, (const void *)&wlan.networks[wlan.cur_network_idx].ssid, IEEEtypes_SSID_SIZE + 1);

        return WM_SUCCESS;
    }

    return WLAN_ERROR_STATE;
}

int wlan_get_current_network_bssid(char *bssid)
{
    if (bssid == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        (void)memcpy((void *)bssid, (const void *)&wlan.networks[wlan.cur_network_idx].bssid, IEEEtypes_ADDRESS_SIZE);

        return WM_SUCCESS;
    }

    return WLAN_ERROR_STATE;
}

int wlan_get_current_uap_network(struct wlan_network *network)
{
    if (network == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running && (is_uap_state(CM_UAP_IP_UP) || is_uap_state(CM_UAP_STARTED)))
    {
        (void)memcpy((void *)network, (const void *)&wlan.networks[wlan.cur_uap_network_idx],
                     sizeof(struct wlan_network));
        return WM_SUCCESS;
    }
    return WLAN_ERROR_STATE;
}

int wlan_get_current_uap_network_ssid(char *ssid)
{
    if (ssid == NULL)
    {
        return -WM_E_INVAL;
    }

    if (wlan.running && (is_uap_state(CM_UAP_IP_UP) || is_uap_state(CM_UAP_STARTED)))
    {
        (void)memcpy((void *)ssid, (const void *)&wlan.networks[wlan.cur_uap_network_idx].ssid, IEEEtypes_SSID_SIZE + 1);

        return WM_SUCCESS;
    }

    return WLAN_ERROR_STATE;
}

#ifdef CONFIG_SCAN_WITH_RSSIFILTER
int wlan_set_rssi_threshold(int rssithr)
{
    if (rssithr)
        wlan.networks[wlan.cur_network_idx].rssi_threshold = (rssithr < 0 ? rssithr : 0);

    return WM_SUCCESS;
}
#endif

bool is_uap_started(void)
{
    return is_uap_state(CM_UAP_IP_UP);
}
bool is_sta_connected(void)
{
    return (wlan.sta_state == CM_STA_CONNECTED);
}

bool is_sta_ipv4_connected(void)
{
    return (wlan.sta_ipv4_state == CM_STA_CONNECTED);
}

#ifdef CONFIG_IPV6
bool is_sta_ipv6_connected(void)
{
    return (wlan.sta_ipv6_state == CM_STA_CONNECTED);
}
#endif

int wlan_get_network(unsigned int index, struct wlan_network *network)
{
    unsigned int i;
    int pos = -1;

    if (network == NULL || index > ARRAY_SIZE(wlan.networks))
    {
        return -WM_E_INVAL;
    }

    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        ++pos;
        if (wlan.networks[i].name[0] != '\0' && pos == (int)index)
        {
            copy_network(network, &wlan.networks[i]);
            return WM_SUCCESS;
        }
    }

    return -WM_E_INVAL;
}

int wlan_get_current_nf(void)
{
    return -g_data_nf_last;
}

int wlan_get_current_signal_strength(short *rssi, int *snr)
{
    wifi_rssi_info_t rssi_info;
    (void)wifi_send_rssi_info_cmd(&rssi_info);

    *snr  = rssi_info.bcn_rssi_last - rssi_info.bcn_nf_last;
    *rssi = rssi_info.bcn_rssi_last;
    return WM_SUCCESS;
}

int wlan_get_average_signal_strength(short *rssi, int *snr)
{
    wifi_rssi_info_t rssi_info;
    (void)wifi_send_rssi_info_cmd(&rssi_info);

    *snr  = rssi_info.bcn_snr_avg;
    *rssi = rssi_info.bcn_rssi_avg;
    return WM_SUCCESS;
}

int wlan_get_current_rssi(short *rssi)
{
    g_rssi = (uint8_t)(g_data_snr_last - g_data_nf_last);
    *rssi  = (short)(g_rssi - 256U);
    return WM_SUCCESS;
}

int wlan_get_network_byname(char *name, struct wlan_network *network)
{
    unsigned int i;

    if (network == NULL || name == NULL)
    {
        return -WM_E_INVAL;
    }

    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && !strcmp(wlan.networks[i].name, name))
        {
            copy_network(network, &wlan.networks[i]);
            return WM_SUCCESS;
        }
    }

    return -WM_E_INVAL;
}

int wlan_set_network_ip_byname(char *name, struct wlan_ip_config *ip)
{
    unsigned int i;

    if (ip == NULL || name == NULL)
    {
        return -WM_E_INVAL;
    }

    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && !strcmp(wlan.networks[i].name, name))
        {
            memcpy(&(wlan.networks[i].ip), ip, sizeof(struct wlan_ip_config));
            return WM_SUCCESS;
        }
    }

    return -WM_E_INVAL;
}

int wlan_remove_all_network_profiles(void)
{
    unsigned int i;
    int ret;

    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0')
        {
            ret = wlan_remove_network(wlan.networks[i].name);
            if (ret != WM_SUCCESS)
            {
                return -WM_E_INVAL;
            }
        }
    }

    return WM_SUCCESS;
}

int wlan_disconnect(void)
{
    if (!wlan.running)
    {
        return WLAN_ERROR_STATE;
    }

#ifdef CONFIG_HOST_SLEEP
    wakelock_get();
#endif

    (void)send_user_request(CM_STA_USER_REQUEST_DISCONNECT, 0);

#ifdef CONFIG_ECSA
    /*Wait for sta to enter the disconnect state, and then send ECSA cmd*/
    os_thread_sleep(1000);
    wrapper_clear_media_connected_event();
    wlan_switch_to_nondfs_channel();
#endif

    return WM_SUCCESS;
}

int wlan_connect(char *name)
{
    unsigned int len = name != NULL ? strlen(name) : 0U;
    int i            = 0, ret;

    if (!wlan.running)
    {
        return WLAN_ERROR_STATE;
    }

    if (wlan.num_networks == 0U || len == 0U)
    {
        return -WM_E_INVAL;
    }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_WPS
    if (wlan.wps_session_attempt)
    {
        wlcm_d("WPS session is in progress");
        return WLAN_ERROR_STATE;
    }
#endif
#endif

    wlan.roam_reassoc = false;

    /* connect to a specific network */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && strlen(wlan.networks[i].name) == len &&
            !strncmp(wlan.networks[i].name, name, len))
        {
            switch (wlan.networks[i].role)
            {
                case MLAN_BSS_ROLE_UAP:
                    wlcm_e("Invalid bss role. Bss role is uap.");
                    ret = WLAN_ERROR_PARAM;
                    break;
                case MLAN_BSS_ROLE_ANY:
                    wlcm_e("Invalid bss role. Bss role is any.");
                    ret = WLAN_ERROR_PARAM;
                    break;
                default:
                    ret = WLAN_ERROR_NONE;
                    break;
            }

            if(ret != WLAN_ERROR_NONE)
                return ret;

            wlcm_d("taking the scan lock (connect scan)");
            dbg_lock_info();
            ret = os_semaphore_get(&wlan.scan_lock, OS_WAIT_FOREVER);
            if (ret != WM_SUCCESS)
            {
                wlcm_e("failed to get scan lock: 0x%X", ret);
                return WLAN_ERROR_ACTION;
            }
            wlcm_d("got the scan lock (connect scan)");
            wlan.is_scan_lock = 1;
            /* Reset reassoc count as this is set to WLAN_RECONNECT_LIMIT
             * during disconnect */
            wlan.reassoc_count = 0;

            return send_user_request(CM_STA_USER_REQUEST_CONNECT, i);
        }
    }

    /* specified network was not found */
    return -WM_E_INVAL;
}

int wlan_connect_opt(char *name, bool skip_dfs)
{
    int ret = 0;

    mlan_adap->skip_dfs = false;
    if(skip_dfs)
        mlan_adap->skip_dfs = true;

    ret = wlan_connect(name);
    if(ret != WM_SUCCESS)
    {
        mlan_adap->skip_dfs = false;
    }

    return ret;
}

int wlan_reassociate()
{
    int ret;

    if (!wlan.running)
    {
        return WLAN_ERROR_STATE;
    }

    if (wlan.num_networks == 0U)
    {
        return -WM_E_INVAL;
    }

    if (!is_sta_connected())
    {
        wlcm_d("Error: sta connection is required before sending reassociate request");
        return WLAN_ERROR_STATE;
    }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_WPS
    if (wlan.wps_session_attempt)
    {
        wlcm_d("WPS session is in progress");
        return WLAN_ERROR_STATE;
    }
#endif
#endif

    wlcm_d("taking the scan lock (reassociate scan)");
    dbg_lock_info();
    ret = os_semaphore_get(&wlan.scan_lock, OS_WAIT_FOREVER);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("failed to get scan lock: 0x%X", ret);
        return WLAN_ERROR_ACTION;
    }
    wlcm_d("got the scan lock (reassociate scan)");
    wlan.is_scan_lock = 1;

    wlan.roam_reassoc = true;

    ret = send_user_request(CM_STA_USER_REQUEST_CONNECT, wlan.cur_network_idx);
    if (ret != WM_SUCCESS)
    {
        wlcm_d("Error: Reassociate failed");
        wlan.roam_reassoc = false;
        (void)os_semaphore_put(&wlan.scan_lock);
        wlan.is_scan_lock = 0;
    }

    return ret;
}

int wlan_start_network(const char *name)
{
    unsigned int i;
    unsigned int len;

    if (name == NULL)
    {
        return -WM_E_INVAL;
    }

    len = strlen(name);
    if (len == 0 || wlan.num_networks == 0U)
    {
        return -WM_E_INVAL;
    }

    if (is_uap_started() != 0)
    {
        wlcm_e(
            "%s network cannot be started, "
            "as the uAP is already running",
            name);
        return WLAN_ERROR_STATE;
    }

    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].name[0] != '\0' && strlen(wlan.networks[i].name) == len &&
            !strncmp(wlan.networks[i].name, name, len) && (wlan.networks[i].role == WLAN_BSS_ROLE_UAP) &&
            wlan.networks[i].ssid_specific)
        {
#ifdef CONFIG_MULTI_CHAN
            /* when multi-channel is enabled, uap and sta can start on different channel */
            if (wifi_get_mc_policy() == 0)
#endif
            {
                if ((wlan.networks[i].channel_specific) && (wlan.networks[i].channel != 0))
                {
                    wlcm_w(
                        "NOTE: uAP will automatically switch to"
                        " the channel that station is on.");
                    if(is_sta_connected())
                        wlan.networks[i].channel = wlan.networks[wlan.cur_network_idx].channel;
                }
            }
            if (wlan.networks[i].role == WLAN_BSS_ROLE_UAP)
            {
                return send_user_request(CM_UAP_USER_REQUEST_START, i);
            }
        }
    }

    /* specified network was not found */
    return -WM_E_INVAL;
}

int wlan_stop_network(const char *name)
{
    unsigned int i;
    unsigned int len;

    if (name == NULL)
    {
        return -WM_E_INVAL;
    }

    len = strlen(name);
    if (len == 0U || wlan.num_networks == 0U)
    {
        return -WM_E_INVAL;
    }

    wlan_uap_scan_chan_list_set = false;
    /* Search for matching SSID
     * If found send stop request
     */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if ((wlan.networks[i].name[0] == '\0') || (strlen(wlan.networks[i].name) != len) ||
            (strncmp(wlan.networks[i].name, name, len)) != 0)
        {
            continue;
        }

        if (wlan.networks[i].role == WLAN_BSS_ROLE_UAP && wlan.networks[i].ssid_specific)
        {
            net_interface_down(net_get_uap_handle());
            return send_user_request(CM_UAP_USER_REQUEST_STOP, i);
        }
    } /* end of loop */
    /* specified network was not found */
    return -WM_E_INVAL;
}

#if defined(RW610)
int wlan_remove_all_networks(void)
{
#ifdef CONFIG_WPA2_ENTP
    unsigned int i;
#endif
    void *intrfc_handle = NULL;
    /* No need to remove net interfaces here, as they are added only once.
     * Moreover, removing and adding net interface will increase netif_num cumulatively,
     * which will mismatch with "ua2" during creating dhcpd.
     */
#ifdef CONFIG_WPA2_ENTP
    /* find all networks to free security key memory */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].security.tls_cert.ca_chain)
        {
            wm_mbedtls_free_cert(wlan.networks[i].security.tls_cert.ca_chain);
            wlan.networks[i].security.tls_cert.ca_chain = NULL;
        }
        if (wlan.networks[i].security.tls_cert.own_cert)
        {
            wm_mbedtls_free_cert(wlan.networks[i].security.tls_cert.own_cert);
            wlan.networks[i].security.tls_cert.own_cert = NULL;
        }
        if (wlan.networks[i].security.tls_cert.own_key)
        {
            wm_mbedtls_free_key(wlan.networks[i].security.tls_cert.own_key);
            wlan.networks[i].security.tls_cert.own_key = NULL;
        }
    }
#endif

    intrfc_handle = net_get_sta_handle();
    net_interface_down(intrfc_handle);

    intrfc_handle = net_get_uap_handle();
    net_interface_down(intrfc_handle);

    return WM_SUCCESS;
}

void wlan_destroy_all_tasks(void)
{
    os_lock_schedule();

    /* Destroy cm_main thread */
    if (wlan.cm_main_thread)
    {
        os_thread_delete(&wlan.cm_main_thread);
        wlan.cm_main_thread = NULL;
    }

#ifdef CONFIG_WPS2
    /* Destroy wps_main thread */
    if (wlan_wps.wps_main_thread)
    {
        os_thread_delete(&wlan_wps.wps_main_thread);
        wlan_wps.wps_main_thread = NULL;

        if (wlan_wps.wps_scan_done != NULL)
        {
            os_semaphore_delete(&wlan_wps.wps_scan_done);
            wlan_wps.wps_scan_done = NULL;
        }
    }
#endif

    /* Destroy wifidriver thread */
    wifi_destroy_wifidriver_tasks();

    os_unlock_schedule();
}

int wlan_imu_get_task_lock(void)
{
    return wifi_imu_get_task_lock();
}

int wlan_imu_put_task_lock(void)
{
    return wifi_imu_put_task_lock();
}

void wlan_reset(cli_reset_option ResetOption)
{
    if (os_mutex_get(&reset_lock, 0) != WM_SUCCESS)
    {
        PRINTF("already in process...\r\n");
        return;
    }

    if (ResetOption == CLI_DISABLE_WIFI || ResetOption == CLI_RESET_WIFI)
    {
        PRINTF("--- Disable WiFi ---\r\n");
        if (wlan_is_started())
        {
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
            /* Reset host sleep state flag first */
            wlan_host_sleep_state = HOST_SLEEP_DISABLE;
#endif
#endif
#if defined(CONFIG_WPA_SUPP) && defined(CONFIG_UAP_STA_MAC_ADDR_FILTER)
        wlan_set_sta_mac_filter(0, 0, NULL);
#endif
            /*Disconnect form AP if station is associated with an AP.*/
            if (wlan.sta_state > CM_STA_ASSOCIATING)
            {
                wlan_disconnect();
                while (wlan.sta_state != CM_STA_IDLE)
                {
                    os_thread_sleep(os_msec_to_ticks(1000));
                }
            }

            /*Stop current uAP if uAP is started.*/
            if (wlan.uap_state > CM_UAP_CONFIGURED)
            {
                wlan_stop_network(wlan.networks[wlan.cur_uap_network_idx].name);
                while (wlan.uap_state != CM_UAP_INITIALIZING)
                {
                    os_thread_sleep(os_msec_to_ticks(1000));
                }
            }
#ifdef CONFIG_CPU_LOADING
            if(cpu_loading.status != CPU_LOADING_STATUS_DEAD)
                wlan_cpu_loading_stop();
            while(cpu_loading.status != CPU_LOADING_STATUS_DEAD)
            {
                os_thread_sleep(os_msec_to_ticks(50));
            }
#endif
            /* Block TX data */
            wifi_set_tx_status(WIFI_DATA_BLOCK);
            /* Block RX data */
            wifi_set_rx_status(WIFI_DATA_BLOCK);

#ifndef __ZEPHYR__
            /* DHCP Cleanup */
            wlan_dhcp_cleanup();
#endif
#ifdef CONFIG_NCP_BRIDGE
            /* Stop uap provisioning if it started */
            if (uap_prov_deinit_cb)
                uap_prov_deinit_cb();
#endif
            /* Stop and Remove all network interfaces */
            wlan_remove_all_networks();

            (void)net_wlan_deinit();

            wifi_scan_stop();
            mlan_adap->skip_dfs = false;
            if (!wifi_fw_is_hang())
                wifi_send_shutdown_cmd();

#ifdef CONFIG_WPA_SUPP
            wifi_supp_deinit();
            wpa_supp_deinit();
#endif

            /* wait for imu task done */
            wlan_imu_get_task_lock();
            /* Destroy all tasks before touch the global vars */
            wlan_destroy_all_tasks();
#ifdef CONFIG_NCP_BRIDGE
            if (uap_prov_cleanup_cb)
                uap_prov_cleanup_cb();
#endif
#ifdef CONFIG_WPS2
            wps_stop();
#endif /* CONFIG_WPS2 */

#ifdef CONFIG_WPA2_ENTP
            wlan_free_entp_cert_files();
#endif

            wlan_imu_put_task_lock();
            /* Clear wlcmgr */
            wlan_stop();
        }
        power_off_device(LOAD_WIFI_FIRMWARE);
    }

    if (ResetOption == CLI_ENABLE_WIFI || ResetOption == CLI_RESET_WIFI)
    {
        PRINTF("--- Enable WiFi ---\r\n");
        if (!wlan_is_started())
        {
            PRINTF("Initialize WLAN Driver\r\n");
            /* Initialize WIFI Driver */
            if (WM_SUCCESS != (wlan_init(wlan_fw_bin, wlan_fw_bin_len)))
            {
                wlcm_e("wlan init failed\r\n");
                os_mutex_put(&reset_lock);
                assert(0);
                return;
            }

            if (WM_SUCCESS != (wlan_start(wlan_event_callback)))
            {
                wlcm_e("wlan start failed\r\n");
                os_mutex_put(&reset_lock);
                return;
            }

            /* update the netif hwaddr after reset */
            net_wlan_set_mac_address(&wlan.sta_mac[0], &wlan.uap_mac[0]);
            /* Unblock TX data */
            wifi_set_tx_status(WIFI_DATA_RUNNING);
            /* Unblock RX data */
            wifi_set_rx_status(WIFI_DATA_RUNNING);
            wifi_tx_block_cnt = 0;
            wifi_rx_block_cnt = 0;
#if defined(CONFIG_WIFI_BLE_COEX_APP) && (CONFIG_WIFI_BLE_COEX_APP == 1)
#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
            /* Re-enable host sleep for coex app */
            wlan_host_sleep_state = HOST_SLEEP_PERIODIC;
#endif
#endif
#endif
        }
    }

    os_mutex_put(&reset_lock);
    PRINTF("--- Done ---\r\n");
}

static void wlan_mon_thread(os_thread_arg_t data)
{
    unsigned long delay_ms = 5000;
    int ret = 0;
    struct wlan_message msg;

#ifdef CONFIG_PALLADIUM_SUPPORT
    delay_ms = 10;
#endif

#ifdef CONFIG_POWER_MANAGER
    os_timer_create(&wake_timer, "wake_timer", os_msec_to_ticks(5000), &wake_timer_cb, NULL,
                    OS_TIMER_ONE_SHOT, OS_TIMER_NO_ACTIVATE);
#endif
    while (1)
    {
        ret = os_queue_recv(&mon_thread_events, &msg, os_msec_to_ticks(delay_ms));
        if (ret == WM_SUCCESS)
        {
#ifdef CONFIG_HOST_SLEEP
             wlcm_d("got mon thread event: %d", msg.id);
            if (msg.id == HOST_SLEEP_HANDSHAKE)
            {
                ret = wlan_send_host_sleep_int(wlan.wakeup_conditions, MFALSE);
                if (ret != WM_SUCCESS)
                {
                   is_hs_handshake_done = WLAN_HOSTSLEEP_FAIL;
                }
            }
            else if (msg.id == HOST_SLEEP_EXIT)
            {
#ifdef CONFIG_POWER_MANAGER
                if(!wlan_is_manual && wlan_host_sleep_state == HOST_SLEEP_PERIODIC)
                {
                    wakelock_get();
                    os_timer_activate(&wake_timer);
                }
#endif
                wlan_cancel_host_sleep();
            }
#endif
        }
        else
        {
            if (wifi_recovery_enable || wifi_fw_is_hang())
            {
                wlan_reset(CLI_RESET_WIFI);
                wifi_recovery_cnt ++;
            }
            /*
             *  get CAU module temperature and write to firmware SMU in every 5s
             *  can also read FW power status by REG PMU->WLAN_CTRL 0x4003_1068
             *  bit[3:2] == 3 means FW is in sleep status
             */
            if ((mlan_adap != NULL) && (mlan_adap->ps_state == PS_STATE_AWAKE))
            {
#ifdef RW610
                wifi_cau_temperature_write_to_firmware();
#endif
            }
        }
    }
}
#endif // RW610


#ifdef CONFIG_NCP_BRIDGE
int wlan_stop_all_networks(void)
{
    wifi_scan_stop();

    net_interface_down(net_get_sta_handle());
    wlan_disconnect();

    net_interface_down(net_get_uap_handle());
    send_user_request(CM_UAP_USER_REQUEST_STOP, 0);

    return WM_SUCCESS;
}

void wlan_register_uap_prov_deinit_cb(int (*cb)(void))
{
    uap_prov_deinit_cb = cb;
}

void wlan_register_uap_prov_cleanup_cb(void (*cb)(void))
{
    uap_prov_cleanup_cb = cb;
}
#endif

int wlan_get_scan_result(unsigned int index, struct wlan_scan_result *res)
{
    struct wifi_scan_result2 *desc;

    if (res == NULL)
    {
        return -WM_E_INVAL;
    }

    if (!is_running())
    {
        return WLAN_ERROR_STATE;
    }

    if (wifi_get_scan_result(index, &desc) != 0)
    {
        return -WM_FAIL;
    }

    (void)memset(res, 0, sizeof(struct wlan_scan_result));

    (void)memcpy((void *)&res->bssid[0], (const void *)&desc->bssid[0], sizeof(res->bssid));
    (void)memcpy((void *)&res->ssid[0], (const void *)((char *)&desc->ssid[0]), (size_t)desc->ssid_len);
    res->ssid[desc->ssid_len] = (char)0;
    res->ssid_len             = (size_t)desc->ssid_len;
    res->channel              = desc->Channel;
    res->beacon_period        = desc->beacon_period;
    res->dtim_period          = desc->dtim_period;

    if (!desc->is_ibss_bit_set)
    {
        res->role = WLAN_BSS_ROLE_STA;
    }
    res->dot11n = (uint8_t)desc->phtcap_ie_present;
#ifdef CONFIG_11AC
    res->dot11ac = (uint8_t)desc->pvhtcap_ie_present;
#endif
#ifdef CONFIG_11AX
    res->dot11ax = (uint8_t)desc->phecap_ie_present;
#endif

    res->wmm = (uint8_t)desc->wmm_ie_present;
#if defined(CONFIG_WPA_SUPP_WPS)
    if (desc->wps_IE_exist == true)
    {
        res->wps         = desc->wps_IE_exist;
        res->wps_session = desc->wps_session;
    }
#elif defined(CONFIG_WPS2)
    if (desc->wps_IE_exist == true)
        res->wps = desc->wps_IE_exist;
    res->wps_session = desc->wps_session;
#endif
    if (desc->WPA_WPA2_WEP.wpa2_entp != 0U)
    {
        res->wpa2_entp = 1;
    }
    else if (desc->WPA_WPA2_WEP.wpa2_entp_sha256 != 0U)
    {
        res->wpa2_entp_sha256 = 1;
    }
    else if (desc->WPA_WPA2_WEP.wpa3_1x_sha256 != 0U)
    {
        res->wpa3_1x_sha256 = 1;
    }
    else if (desc->WPA_WPA2_WEP.wpa3_1x_sha384 != 0U)
    {
        res->wpa3_1x_sha384 = 1;
    }
    else
    {
        if (desc->WPA_WPA2_WEP.wpa != 0U)
        {
            res->wpa = 1;
        }
        if (desc->WPA_WPA2_WEP.wpa3_sae != 0U)
        {
            res->wpa3_sae = 1;
        }
        if (desc->WPA_WPA2_WEP.owe != 0U)
        {
#ifdef CONFIG_OWE
            res->owe = 1;
#endif
        }
        if (desc->WPA_WPA2_WEP.wpa2 != 0U)
        {
            res->wpa2 = 1;
        }
        if (desc->WPA_WPA2_WEP.wpa2_sha256 != 0U)
        {
            res->wpa2_sha256 = 1;
        }
        if ((desc->WPA_WPA2_WEP.wepStatic != 0U) || (desc->WPA_WPA2_WEP.wepDynamic != 0U))
        {
            res->wep = 1;
        }
    }
#ifdef CONFIG_11R
    if (res->wpa2_entp != 0U)
    {
        res->ft_1x = (t_u8)desc->WPA_WPA2_WEP.ft_1x;
    }
    if (res->wpa2 != 0U)
    {
        res->ft_psk = (t_u8)desc->WPA_WPA2_WEP.ft_psk;
    }
    if (res->wpa3_sae != 0U)
    {
        res->ft_sae = (t_u8)desc->WPA_WPA2_WEP.ft_sae;
    }
    if (res->wpa3_1x_sha384 != 0U)
    {
        res->ft_1x_sha384 = (t_u8)desc->WPA_WPA2_WEP.ft_1x_sha384;
    }
#endif
    res->rssi = desc->RSSI;

    (void)memcpy((void *)&res->trans_bssid[0], (const void *)&desc->trans_bssid[0], sizeof(res->trans_bssid));
    (void)memcpy((void *)&res->trans_ssid[0], (const void *)((char *)&desc->trans_ssid[0]),
                 (unsigned int)desc->trans_ssid_len);
    res->trans_ssid[desc->trans_ssid_len] = (char)0;
    res->trans_ssid_len                   = (unsigned int)desc->trans_ssid_len;

#ifdef CONFIG_11K
    if (desc->neighbor_report_supported == true)
    {
        res->neighbor_report_supported = true;
    }
    else
    {
        res->neighbor_report_supported = false;
    }
#endif

#ifdef CONFIG_11V
    if (desc->bss_transition_supported == true)
    {
        res->bss_transition_supported = true;
    }
    else
    {
        res->bss_transition_supported = false;
    }
#endif

    res->ap_mfpc = desc->ap_mfpc;
    res->ap_mfpr = desc->ap_mfpr;

    return WM_SUCCESS;
}

void wlan_set_cal_data(const uint8_t *cal_data, const unsigned int cal_data_size)
{
    if (cal_data_size > 1)
    {
        wifi_set_cal_data(cal_data, cal_data_size);
    }
}

int wlan_set_mac_addr(uint8_t *mac)
{
    uint8_t ap_mac[MLAN_MAC_ADDR_LENGTH];

    /* Only suppoprt unicast mac */
    if (mac[0] & 0x01)
    {
        return -WM_FAIL;
    }

    if (!is_uap_state(CM_UAP_INITIALIZING) || is_sta_connecting())
    {
        return -WM_FAIL;
    }

    if (wlan.status == WLCMGR_INIT_DONE || wlan.status == WLCMGR_ACTIVATED)
    {
        (void)memcpy(ap_mac, mac, MLAN_MAC_ADDR_LENGTH);
        ap_mac[4] += 1;

        net_wlan_set_mac_address((unsigned char *)mac, (unsigned char *)ap_mac);

        _wifi_set_mac_addr(mac, MLAN_BSS_TYPE_STA);

        _wifi_set_mac_addr(&ap_mac[0], MLAN_BSS_TYPE_UAP);

        /* save the sta mac */
        (void)memcpy(&wlan.sta_mac[0], mac, MLAN_MAC_ADDR_LENGTH);
        /* save the uap mac */
        (void)memcpy(&wlan.uap_mac[0], &ap_mac[0], MLAN_MAC_ADDR_LENGTH);
    }
    else
    {
        wifi_set_mac_addr(mac);
    }
#ifdef CONFIG_WPS2
    (void)memcpy(wps_global.my_mac_addr, mac, MLAN_MAC_ADDR_LENGTH);
    (void)memcpy(wps_global.l2->my_mac_addr, mac, MLAN_MAC_ADDR_LENGTH);
#endif

    return WM_SUCCESS;
}

int wlan_set_uap_mac_addr(uint8_t *mac)
{
    /* Only suppoprt unicast mac */
    if (mac[0] & 0x01)
    {
        return -WM_FAIL;
    }

    if (!is_uap_state(CM_UAP_INITIALIZING))
    {
        return -WM_FAIL;
    }

    if (memcmp(mac, &wlan.sta_mac[0], MLAN_MAC_ADDR_LENGTH) == 0)
    {
        return -WM_FAIL;
    }

    if (wlan.status == WLCMGR_INIT_DONE || wlan.status == WLCMGR_ACTIVATED)
    {
        net_wlan_set_mac_address(NULL, (unsigned char *)mac);

        _wifi_set_mac_addr(mac, MLAN_BSS_TYPE_UAP);

        /* save the uap mac */
        (void)memcpy(&wlan.uap_mac[0], mac, MLAN_MAC_ADDR_LENGTH);
    }
    else
    {
        wifi_set_mac_addr(mac);
    }

    return WM_SUCCESS;
}

int wlan_set_sta_mac_addr(uint8_t *mac)
{
    /* Only suppoprt unicast mac */
    if (mac[0] & 0x01)
    {
        return -WM_FAIL;
    }

    if (is_sta_connecting())
    {
        return -WM_FAIL;
    }

    if (memcmp(mac, &wlan.uap_mac[0], MLAN_MAC_ADDR_LENGTH) == 0)
    {
        return -WM_FAIL;
    }

    if (wlan.status == WLCMGR_INIT_DONE || wlan.status == WLCMGR_ACTIVATED)
    {
        net_wlan_set_mac_address((unsigned char *)mac, NULL);

        _wifi_set_mac_addr(mac, MLAN_BSS_TYPE_STA);

        /* save the sta mac */
        (void)memcpy(&wlan.sta_mac[0], mac, MLAN_MAC_ADDR_LENGTH);
    }
    else
    {
        wifi_set_mac_addr(mac);
    }

    return WM_SUCCESS;
}

int wlan_scan(int (*cb)(unsigned int count))
{
    int ret;

    wlan_scan_params_v2_t wlan_scan_param;

    (void)memset(&wlan_scan_param, 0, sizeof(wlan_scan_params_v2_t));

    wlan_scan_param.cb = cb;

    ret = wlan_scan_with_opt(wlan_scan_param);

    return ret;
}

static int wlan_pscan(int (*cb)(unsigned int count))
{
    struct wlan_network* network = NULL;
    wlan_scan_params_v2_t wlan_scan_param;
    int ret;

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        network = &wlan.networks[wlan.cur_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get network info");
        return -WM_FAIL;
    }

    (void)memset(&wlan_scan_param, 0, sizeof(wlan_scan_params_v2_t));

    wlan_scan_param.cb = cb;

    (void)memcpy((void *)wlan_scan_param.bssid, (const void *)network->bssid, MLAN_MAC_ADDR_LENGTH);

    (void)memcpy((void *)wlan_scan_param.ssid, (const void *)network->ssid, strlen(network->ssid));

    wlan_scan_param.num_channels = 1;

    wlan_scan_param.chan_list[0].chan_number = (t_u8)network->channel;
    wlan_scan_param.chan_list[0].scan_type   = MLAN_SCAN_TYPE_PASSIVE;
    wlan_scan_param.chan_list[0].scan_time   = 200;

    ret = wlan_scan_with_opt(wlan_scan_param);

    return ret;
}

int wlan_scan_with_opt(wlan_scan_params_v2_t t_wlan_scan_param)
{
    int ret;
    uint32_t chan_idx = 0;
    uint32_t t_idx = 0;
    wlan_scan_params_v2_t *wlan_scan_param = NULL;

    if (t_wlan_scan_param.cb == NULL)
    {
        return -WM_E_INVAL;
    }

    if (!is_running() || !is_scanning_allowed())
    {
        return WLAN_ERROR_STATE;
    }

    wlan_scan_param = (wlan_scan_params_v2_t *)os_mem_calloc(sizeof(wlan_scan_params_v2_t));

    if (wlan_scan_param == NULL)
    {
        return -WM_E_NOMEM;
    }

    (void)memcpy((void *)wlan_scan_param, (const void *)&t_wlan_scan_param, sizeof(wlan_scan_params_v2_t));

    if (t_wlan_scan_param.num_channels > 0)
    {
        wlan_scan_param->num_channels = 0;
        (void)memset((void *)&wlan_scan_param->chan_list[0], 0x0, MAX_CHANNEL_LIST * sizeof(wifi_scan_channel_list_t));
#if defined(RW610) && defined(CONFIG_ANT_DETECT)
        for (t_idx = 0; t_idx < ANT_DETECT_MAX_CHANNEL_LIST && t_wlan_scan_param.chan_list[t_idx].chan_number; t_idx++)
#else
        for (t_idx = 0; t_idx < MAX_CHANNEL_LIST && t_wlan_scan_param.chan_list[t_idx].chan_number; t_idx++)
#endif
        {
            if(!wlan_check_channel_by_region_table((mlan_private *)mlan_adap->priv[0], t_wlan_scan_param.chan_list[t_idx].chan_number))
            {
                continue;
            }
            (void)memcpy((void *)&wlan_scan_param->chan_list[chan_idx], (const void *)&t_wlan_scan_param.chan_list[t_idx], sizeof(wifi_scan_channel_list_t));
            chan_idx++;
        }
        wlan_scan_param->num_channels = chan_idx;

        if (chan_idx == 0 && t_wlan_scan_param.num_channels > 0)
        {
            wlcm_e("no valid channel to scan");
            os_mem_free(wlan_scan_param);
            return -WM_E_INVAL;
        }
    }

    wlcm_d("taking the scan lock (user scan)");
    dbg_lock_info();
    ret = os_semaphore_get(&wlan.scan_lock, OS_WAIT_FOREVER);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("failed to get scan lock: 0x%X", ret);
        os_mem_free(wlan_scan_param);
        return -WM_FAIL;
    }
    wlcm_d("got the scan lock (user scan)");
    wlan.is_scan_lock = 1;

    ret = send_user_request(CM_STA_USER_REQUEST_SCAN, (unsigned int)wlan_scan_param);

    if (ret != WM_SUCCESS)
    {
        os_mem_free(wlan_scan_param);
    }

    return ret;
}

int wlan_get_connection_state(enum wlan_connection_state *state)
{
    enum cm_sta_state cur;

    if (state == NULL)
    {
        return -WM_E_INVAL;
    }

    if (!is_running())
    {
        return WLAN_ERROR_STATE;
    }

    if (is_user_scanning() != 0)
    {
        cur = wlan.sta_return_to;
    }
    else
    {
        cur = wlan.sta_state;
    }

    switch (cur)
    {
        case CM_STA_IDLE:
            *state = WLAN_DISCONNECTED;
            break;
        case CM_STA_SCANNING:
            *state = WLAN_SCANNING;
            break;
        case CM_STA_ASSOCIATING:
            *state = WLAN_ASSOCIATING;
            break;
        case CM_STA_ASSOCIATED:
            *state = WLAN_ASSOCIATED;
            break;
        case CM_STA_AUTHENTICATED:
            *state = WLAN_AUTHENTICATED;
            break;
        case CM_STA_REQUESTING_ADDRESS:
        case CM_STA_OBTAINING_ADDRESS:
            *state = WLAN_CONNECTING;
            break;
        case CM_STA_CONNECTED:
            *state = WLAN_CONNECTED;
            break;
        default:
            *state = WLAN_DISCONNECTED;
            break;
    }
    return WM_SUCCESS;
}

int wlan_get_ps_mode(enum wlan_ps_mode *ps_mode)
{
    if (ps_mode == NULL)
    {
        return -WM_E_INVAL;
    }

    *ps_mode = WLAN_ACTIVE;

    if (wlan.cm_ieeeps_configured && wlan.cm_deepsleepps_configured)
    {
        if (is_state(CM_STA_CONNECTED))
        {
            *ps_mode = WLAN_IEEE;
        }
        else
        {
            *ps_mode = WLAN_DEEP_SLEEP;
        }
    }
    else if (wlan.cm_wnmps_configured && wlan.cm_deepsleepps_configured)
    {
        if (is_state(CM_STA_CONNECTED))
        {
            *ps_mode = WLAN_WNM;
        }
        else
        {
            *ps_mode = WLAN_DEEP_SLEEP;
        }
    }
    else if (wlan.cm_wnmps_configured)
    {
        *ps_mode = WLAN_WNM;
    }
    else if (wlan.cm_deepsleepps_configured)
    {
        *ps_mode = WLAN_DEEP_SLEEP;
    }
    else if (wlan.cm_ieeeps_configured)
    {
        *ps_mode = WLAN_IEEE;
    }
    else
    { /* Do Nothing */
    }

    return WM_SUCCESS;
}

int wlan_get_uap_connection_state(enum wlan_connection_state *state)
{
    enum cm_uap_state cur;

    if (state == NULL)
    {
        return -WM_E_INVAL;
    }

    if (!is_running())
    {
        return WLAN_ERROR_STATE;
    }

    cur = wlan.uap_state;

    switch (cur)
    {
        case CM_UAP_INITIALIZING:
        case CM_UAP_CONFIGURED:
            *state = WLAN_UAP_STOPPED;
            break;
        case CM_UAP_STARTED:
        case CM_UAP_IP_UP:
            *state = WLAN_UAP_STARTED;
            break;
        default:
            *state = WLAN_UAP_STOPPED;
            break;
    }
    return WM_SUCCESS;
}

int wlan_get_address(struct wlan_ip_config *addr)
{
    void *if_handle = NULL;
    if (addr == NULL)
    {
        return -WM_E_INVAL;
    }

    if (!is_running() || !is_state(CM_STA_CONNECTED))
    {
        return WLAN_ERROR_STATE;
    }

    if_handle = net_get_mlan_handle();
    if (net_get_if_addr((struct net_ip_config *)addr, if_handle) != 0)
    {
        return -WM_FAIL;
    }

#ifdef CONFIG_IPV6
    if (net_get_if_ipv6_addr((struct net_ip_config *)addr, if_handle) != 0)
    {
        return -WM_FAIL;
    }
#endif

    return WM_SUCCESS;
}

int wlan_get_uap_address(struct wlan_ip_config *addr)
{
    void *if_handle = NULL;
    if (addr == NULL)
    {
        return -WM_E_INVAL;
    }
    if (!is_running() || !is_uap_state(CM_UAP_IP_UP))
    {
        return WLAN_ERROR_STATE;
    }

    if_handle = net_get_uap_handle();
    if (net_get_if_addr((struct net_ip_config *)addr, if_handle) != 0)
    {
        return -WM_FAIL;
    }
    return WM_SUCCESS;
}

int wlan_get_uap_channel(int *channel)
{
    if (channel != NULL)
    {
        *channel = 0;
    }
    else
    {
        return (int)(-WM_E_INVAL);
    }

    return wifi_get_uap_channel(channel);
}


int wlan_get_mac_address(unsigned char *dest)
{
    if (!dest)
        return -WM_E_INVAL;
    (void)memset(dest, 0, MLAN_MAC_ADDR_LENGTH);
    (void)memcpy(dest, &wlan.sta_mac[0], MLAN_MAC_ADDR_LENGTH);
    return WM_SUCCESS;
}

int wlan_get_mac_address_uap(unsigned char *dest)
{
    if (!dest)
        return -WM_E_INVAL;
    (void)memset(dest, 0, MLAN_MAC_ADDR_LENGTH);
    (void)memcpy(dest, &wlan.uap_mac[0], MLAN_MAC_ADDR_LENGTH);
    return WM_SUCCESS;
}


void wlan_wake_up_card(void)
{
    uint32_t resp;

    wifi_wake_up_card(&resp);
}

int wlan_set_ieeeps_cfg(struct wlan_ieeeps_config *ps_cfg)
{
    wlan_configure_null_pkt_interval(ps_cfg->ps_null_interval);

    return send_user_request(CM_STA_USER_REQUEST_PS_ENTER, WLAN_IEEE);
}

void wlan_configure_listen_interval(int listen_interval)
{
    wifi_configure_listen_interval(listen_interval);
}

void wlan_configure_delay_to_ps(unsigned int timeout_ms)
{
    wifi_configure_delay_to_ps(timeout_ms);
}

unsigned short wlan_get_listen_interval()
{
    return wifi_get_listen_interval();
}

unsigned int wlan_get_delay_to_ps()
{
    return wifi_get_delay_to_ps();
}

bool wlan_is_power_save_enabled()
{
    if (wlan.cm_ieeeps_configured
        || wlan.cm_wnmps_configured
        || wlan.cm_deepsleepps_configured)
    {
        return true;
    }

    return false;
}

void wlan_configure_null_pkt_interval(int time_in_secs)
{
    wifi_configure_null_pkt_interval((unsigned int)time_in_secs);
}

int wlan_ieeeps_on(unsigned int wakeup_conditions)
{
    enum wlan_connection_state state;

    if ((!wlan.running) || (wlan_get_uap_connection_state(&state) != 0) || (state == WLAN_UAP_STARTED))
    {
        return -WM_FAIL;
    }

    if (wlan.cm_ieeeps_configured
        || wlan.cm_wnmps_configured
       )
    {
        if (wlan.cm_wnmps_configured == true)
        {
            wlcm_d("wnm ps already enabled: %d, ieee ps could not be enabled", wlan.cm_wnmps_configured);
            return -WM_FAIL;
        }
        else
        {
            wlcm_d("ieee ps already enabled");
        }

        CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_IEEE);
        return WM_SUCCESS;
    }

    return send_user_request(CM_STA_USER_REQUEST_PS_ENTER, WLAN_IEEE);
}

int wlan_ieeeps_off(void)
{
    if (wlan.cm_ieeeps_configured)
    {
        return send_user_request(CM_STA_USER_REQUEST_PS_EXIT, WLAN_IEEE);
    }

    CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_IEEE);
    return WM_SUCCESS;
}

int wlan_wnmps_on(unsigned int wakeup_conditions, t_u16 wnm_sleep_time)
{
    enum wlan_connection_state state;

    if ((!wlan.running) || (wlan_get_uap_connection_state(&state) != 0) || (state == WLAN_UAP_STARTED))
    {
        return -WM_FAIL;
    }

    if (wlan.cm_ieeeps_configured || wlan.cm_wnmps_configured)
    {
        if (wlan.cm_ieeeps_configured == true)
        {
            wlcm_d("ieee ps already enabled: %d, wnm ps could not be enabled", wlan.cm_ieeeps_configured);
            return -WM_FAIL;
        }
        else
        {
            wlcm_d("wnm ps already enabled");
        }

        CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_WNM);
        return WM_SUCCESS;
    }

    wlan.wakeup_conditions   = wakeup_conditions;
    wlan.wnm_sleep_time      = wnm_sleep_time;
    return send_user_request(CM_STA_USER_REQUEST_PS_ENTER, WLAN_WNM);
}

int wlan_wnmps_off()
{
    if (wlan.cm_wnmps_configured)
    {
        return send_user_request(CM_STA_USER_REQUEST_PS_EXIT, WLAN_WNM);
    }

    CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_WNM);
    return WM_SUCCESS;
}

int wlan_deepsleepps_on(void)
{
    enum wlan_connection_state state;

    if ((!wlan.running) || (wlan_get_uap_connection_state(&state) != 0) || (state == WLAN_UAP_STARTED))
    {
        return -WM_FAIL;
    }

    if (wlan.cm_deepsleepps_configured)
    {
        CONNECTION_EVENT(WLAN_REASON_PS_ENTER, (void *)WLAN_DEEP_SLEEP);
        return WM_SUCCESS;
    }

    return send_user_request(CM_STA_USER_REQUEST_PS_ENTER, WLAN_DEEP_SLEEP);
}

int wlan_deepsleepps_off(void)
{
    if (wlan.cm_deepsleepps_configured)
    {
        return send_user_request(CM_STA_USER_REQUEST_PS_EXIT, WLAN_DEEP_SLEEP);
    }

    CONNECTION_EVENT(WLAN_REASON_PS_EXIT, (void *)WLAN_DEEP_SLEEP);
    return WM_SUCCESS;
}

#ifdef CONFIG_WPS2
int wlan_start_wps_pbc()
{
    wlan_wps.wps_state = PROV_WPS_PBC_ENABLED;
    wlan_wps.wps_cmd   = CMD_WPS_PBC;
    wlan_wps.wps_pin   = 0;

    return WM_SUCCESS;
}

void wlan_wps_generate_pin(uint32_t *pin)
{
    wps_generate_pin(pin);
}

int wlan_start_wps_pin(uint32_t pin)
{
    if (wps_validate_pin(pin) != WM_SUCCESS)
    {
        wlcm_d("WPS PIN validation failed for %d", pin);
        return -WM_FAIL;
    }

    wlan_wps.wps_state = PROV_WPS_PIN_ENABLED;
    wlan_wps.wps_cmd   = CMD_WPS_PIN;
    wlan_wps.wps_pin   = pin;

    return WM_SUCCESS;
}
#endif

#ifndef RW610
int wlan_set_antcfg(uint32_t ant, uint16_t evaluate_time)
{
    int rv = wifi_set_antenna(ant, evaluate_time);
    if (rv != WM_SUCCESS)
    {
        wlcm_e("Unable to set antenna");
        return WLAN_ERROR_STATE;
    }

    return WM_SUCCESS;
}

int wlan_get_antcfg(uint32_t *ant, uint16_t *evaluate_time, uint16_t *current_antenna)
{
    int rv = wifi_get_antenna((unsigned int *)ant, evaluate_time, current_antenna);
    if (rv != WM_SUCCESS)
    {
        wlcm_e("Unable to get current antenna");
        return WLAN_ERROR_STATE;
    }

    return WM_SUCCESS;
}
#else
int wlan_set_antcfg(uint32_t ant, uint16_t evaluate_time, uint8_t evaluate_mode)
{
    int rv = wifi_set_antenna(ant, evaluate_time, evaluate_mode);
    if (rv != WM_SUCCESS)
    {
        wlcm_e("Unable to set antenna");
        return WLAN_ERROR_STATE;
    }

    return WM_SUCCESS;
}

int wlan_get_antcfg(uint32_t *ant, uint16_t *evaluate_time, uint8_t *evaluate_mode, uint16_t *current_antenna)
{
    int rv = wifi_get_antenna((unsigned int *)ant, evaluate_time, evaluate_mode, current_antenna);
    if (rv != WM_SUCCESS)
    {
        wlcm_e("Unable to get current antenna");
        return WLAN_ERROR_STATE;
    }

    return WM_SUCCESS;
}
#endif /*RW610*/


int wlan_wlcmgr_send_msg(enum wifi_event event, enum wifi_event_reason reason, void *data)
{
    struct wifi_message msg;

    msg.event  = (uint16_t)event;
    msg.reason = reason;
    msg.data   = (void *)data;

    if (os_queue_send(&wlan.events, &msg, OS_NO_WAIT) == WM_SUCCESS)
    {
        return WM_SUCCESS;
    }

    return -WM_FAIL;
}

/*
  This function validates input string for a valid WEP key, converts
  it to appropriate format

  Returns positive integer equal to size of the output string
  for successful operation or -WM_FAIL in case of failure to convert. Note
  that the output string is not NULL terminated.
 */
int load_wep_key(const uint8_t *input, uint8_t *output, uint8_t *output_len, const unsigned max_output_len)
{
    if (input == NULL || output == NULL)
    {
        return -WM_FAIL;
    }

    unsigned len = *output_len;

    /* fixme: add macros here after mlan integration */
    if (len == 10U || len == 26U)
    {
        /* Looks like this is an hexadecimal key */
        int ret = (int)wm_hex2bin(input, output, max_output_len);
        if (ret == 0)
        {
            return -WM_FAIL;
        }

        len = len / 2U;
    }
    else if (len == 5U || len == 13U)
    {
        /* Looks like this is ASCII key  */
        if (len > max_output_len)
        {
            return -WM_FAIL;
        }

        (void)memcpy((void *)output, (const void *)input, len);
    }
    else
    {
        return -WM_FAIL;
    }

    *output_len = (uint8_t)len;

    return WM_SUCCESS;
}

int get_split_scan_delay_ms(void)
{
    return g_wifi_scan_params.split_scan_delay;
}

char *wlan_get_firmware_version_ext(void)
{
    return wlan.fw_ver_ext.version_str;
}

unsigned int wlan_get_uap_supported_max_clients(void)
{
    return wlan.uap_supported_max_sta_num;
}

int wlan_get_uap_max_clients(unsigned int *max_sta_num)
{
    return wifi_get_uap_max_clients(max_sta_num);
}

int wlan_set_uap_max_clients(unsigned int max_sta_num)
{
    int ret = -WM_FAIL;

    if (is_uap_started() != 0)
    {
        wlcm_e(
                "Cannot set the max station number "
                "as the uAP is already running");
        return -WM_FAIL;
    }
    else if (max_sta_num > wlan.uap_supported_max_sta_num)
    {
        wlcm_e(
                "Maximum supported station number "
                "limit is = %d",
                wlan.uap_supported_max_sta_num);
        return -WM_FAIL;
    }
    else
    {
        ret = wifi_set_uap_max_clients(&max_sta_num);

        if (ret != WM_SUCCESS)
        {
            return ret;
        }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
        struct netif *uap_netif = net_get_uap_interface();

        wpa_supp_set_ap_max_num_sta(uap_netif, max_sta_num);
#endif
#endif
        return ret;
    }
}

int wlan_get_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t index, void *buf, unsigned int *buf_len)
{
    return wifi_get_mgmt_ie((mlan_bss_type)bss_type, index, buf, buf_len);
}

int wlan_set_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t id, void *buf, unsigned int buf_len)
{
    return wifi_set_mgmt_ie((mlan_bss_type)bss_type, id, buf, buf_len);
}

#ifdef SD8801
int wlan_get_ext_coex_stats(wlan_ext_coex_stats_t *ext_coex_stats)
{
    return wifi_get_ext_coex_stats(ext_coex_stats);
}

int wlan_set_ext_coex_config(const wlan_ext_coex_config_t ext_coex_config)
{
    return wifi_set_ext_coex_config(&ext_coex_config);
}
#endif

int wlan_clear_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t index, int mgmt_bitmap_index)
{
    return wifi_clear_mgmt_ie((mlan_bss_type)bss_type, index, mgmt_bitmap_index);
}

int wlan_set_txbfcap(unsigned int tx_bf_cap)
{
    return wifi_set_txbfcap(tx_bf_cap);
}

int wlan_set_htcapinfo(unsigned int htcapinfo)
{
    return wifi_set_htcapinfo(htcapinfo);
}

int wlan_set_httxcfg(unsigned short httxcfg)
{
    return wifi_set_httxcfg(httxcfg);
}

int wlan_set_txratecfg(wlan_ds_rate ds_rate, mlan_bss_type bss_type)
{
    return wifi_set_txratecfg(ds_rate, bss_type);
}

int wlan_get_txratecfg(wlan_ds_rate *ds_rate, mlan_bss_type bss_type)
{
    int ret;

    ret = wifi_get_txratecfg(ds_rate, bss_type);

    if (ret != WM_SUCCESS)
    {
        return ret;
    }

    ret = wifi_get_data_rate(ds_rate, bss_type);

    if (ret != WM_SUCCESS)
    {
        return ret;
    }

    return WM_SUCCESS;
}

int wlan_set_sta_tx_power(t_u32 power_level)
{
    return wifi_set_tx_power(power_level);
}

int wlan_get_sta_tx_power(t_u32 *power_level)
{
    return wifi_get_tx_power(power_level);
}

#ifdef CONFIG_COMPRESS_TX_PWTBL
int wlan_set_region_power_cfg(const t_u8 *data, t_u16 len)
{
    return wifi_set_region_power_cfg(data, len);
}
#endif

int wlan_set_chanlist_and_txpwrlimit(wlan_chanlist_t *chanlist, wlan_txpwrlimit_t *txpwrlimit)
{
    int ret = WM_SUCCESS;

    ret = wlan_set_chanlist(chanlist);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Cannot set Channel List");
        return ret;
    }

    ret = wlan_set_txpwrlimit(txpwrlimit);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Cannot set Tx Power");
    }

    return ret;
}

int wlan_set_chanlist(wlan_chanlist_t *chanlist)
{
    if (chanlist != NULL)
    {
        return wifi_set_chanlist(chanlist);
    }

    return -WM_FAIL;
}

int wlan_get_chanlist(wlan_chanlist_t *chanlist)
{
    if (chanlist != NULL)
    {
        return wifi_get_chanlist(chanlist);
    }

    return -WM_FAIL;
}

int wlan_set_txpwrlimit(wlan_txpwrlimit_t *txpwrlimit)
{
    if (txpwrlimit != NULL)
    {
        return wifi_set_txpwrlimit(txpwrlimit);
    }

    return -WM_FAIL;
}

int wlan_get_txpwrlimit(wifi_SubBand_t subband, wifi_txpwrlimit_t *txpwrlimit)
{
    if (txpwrlimit != NULL)
    {
        (void)memset(txpwrlimit, 0x00, sizeof(wifi_txpwrlimit_t));
        return wifi_get_txpwrlimit(subband, txpwrlimit);
    }

    return -WM_FAIL;
}

#ifdef WLAN_LOW_POWER_ENABLE
int wlan_enable_low_pwr_mode()
{
    if (wlan.status == WLCMGR_INACTIVE)
    {
        wifi_enable_low_pwr_mode();
        return WM_SUCCESS;
    }
    else
        return -WM_FAIL;
}
#endif

void wlan_set_reassoc_control(bool reassoc_control)
{
    wlan.reassoc_control = reassoc_control;
    wlcm_d("Reassoc control %s", reassoc_control ? "enabled" : "disabled");
}

int wlan_set_ed_mac_mode(wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl)
{
    return wifi_set_ed_mac_mode(&wlan_ed_mac_ctrl, MLAN_BSS_TYPE_STA);
}

int wlan_get_ed_mac_mode(wlan_ed_mac_ctrl_t *wlan_ed_mac_ctrl)
{
    return wifi_get_ed_mac_mode(wlan_ed_mac_ctrl, MLAN_BSS_TYPE_STA);
}

int wlan_set_uap_ed_mac_mode(wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl)
{
    return wifi_set_ed_mac_mode(&wlan_ed_mac_ctrl, MLAN_BSS_TYPE_UAP);
}

int wlan_get_uap_ed_mac_mode(wlan_ed_mac_ctrl_t *wlan_ed_mac_ctrl)
{
    return wifi_get_ed_mac_mode(wlan_ed_mac_ctrl, MLAN_BSS_TYPE_UAP);
}

bool wlan_get_11d_enable_status(void)
{
    return wrapper_wlan_11d_support_is_enabled();
}

int wlan_remain_on_channel(const enum wlan_bss_type bss_type,
                           const bool status,
                           const uint8_t channel,
                           const uint32_t duration)
{
    wifi_remain_on_channel_t roc;

    (void)memset(&roc, 0x00, sizeof(wifi_remain_on_channel_t));

    roc.remove = (uint16_t)!status;

    roc.channel = channel;

    roc.remain_period = duration;

#ifdef CONFIG_5GHz_SUPPORT
    if (channel > 14)
    {
        roc.bandcfg = 1;
    }
#endif

    return wifi_send_remain_on_channel_cmd((uint32_t)bss_type, &roc);
}

int wlan_get_otp_user_data(uint8_t *buf, uint16_t len)
{
    if (buf == NULL)
    {
        return -WM_E_INVAL;
    }

    return wifi_get_otp_user_data(buf, len);
}

#ifdef CONFIG_WIFI_GET_LOG
int wlan_get_log(wlan_pkt_stats_t *stats)
{
    if (!stats)
        return -WM_E_INVAL;

    return wifi_get_log(stats, MLAN_BSS_TYPE_STA);
}

int wlan_uap_get_log(wlan_pkt_stats_t *stats)
{
    if (!stats)
        return -WM_E_INVAL;

    return wifi_get_log(stats, MLAN_BSS_TYPE_UAP);
}
#endif

int wlan_get_cal_data(wlan_cal_data_t *cal_data)
{
    if (cal_data == NULL)
    {
        return -WM_E_INVAL;
    }

    return wifi_get_cal_data(cal_data);
}

#ifdef CONFIG_AUTO_RECONNECT
int wlan_auto_reconnect_enable(wlan_auto_reconnect_config_t auto_reconnect_config)
{
    if (is_sta_connected())
    {
        wlcm_e("Can not enable auto reconnect in connected state");
        return -WM_E_INVAL;
    }

    return wifi_auto_reconnect_enable(auto_reconnect_config);
}

int wlan_auto_reconnect_disable(void)
{
    return wifi_auto_reconnect_disable();
}

int wlan_get_auto_reconnect_config(wlan_auto_reconnect_config_t *auto_reconnect_config)
{
    if (auto_reconnect_config == NULL)
    {
        return -WM_E_INVAL;
    }

    return wifi_get_auto_reconnect_config(auto_reconnect_config);
}
#endif

int wlan_get_tsf(uint32_t *tsf_high, uint32_t *tsf_low)
{
    return wifi_get_tsf(tsf_high, tsf_low);
}

int wlan_tcp_keep_alive(wlan_tcp_keep_alive_t *tcp_keep_alive)
{
    int ret;
    unsigned int ipv4_addr;

    ret = wlan_get_ipv4_addr(&ipv4_addr);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Cannot get IP");
        return -WM_FAIL;
    }

    return wifi_tcp_keep_alive(tcp_keep_alive, wlan.sta_mac, ipv4_addr);
}


#ifdef CONFIG_CLOUD_KEEP_ALIVE
/* Here the length of ip_packet for test is 40 */
static t_u16 pkt_len_default = 40;
/* ip packet content */
static t_u8 packet_default[40] = {0x45, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0xff, 0x06, 0x00, 0x00, 0xc0, 0xa8,
                                  0x00, 0x7c, 0xc0, 0xa8, 0x00, 0x8a, 0xc0, 0x03, 0x22, 0xb7, 0xb0, 0xb6, 0x60, 0x9f,
                                  0x42, 0xdd, 0x9e, 0x1e, 0x50, 0x18, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00};

int wlan_save_cloud_keep_alive_params(wlan_cloud_keep_alive_t *cloud_keep_alive,
                                      t_u16 src_port,
                                      t_u16 dst_port,
                                      t_u32 seq_number,
                                      t_u32 ack_number,
                                      t_u8 enable)
{
    if (enable)
    {
        if (cloud_keep_alive == NULL)
        {
            return -WM_E_INVAL;
        }

        if (!is_sta_connected())
        {
            wlcm_e("Can not start cloud keep alive in disconnected state");
            return -WM_E_INVAL;
        }

        if (
			cloud_keep_alive->mkeep_alive_id >= MAX_KEEP_ALIVE_ID)
        {
            wlcm_e("Invalid keep alive id");
            return -WM_E_INVAL;
        }

        /* Get source mac address */
        uint8_t sta_mac[MLAN_MAC_ADDR_LENGTH];
        if (wlan_get_mac_address(sta_mac))
        {
            wlcm_e("Unable to retrieve MAC address\r\n");
        }
        (void)memcpy(cloud_keep_alive->src_mac, sta_mac, MLAN_MAC_ADDR_LENGTH);

        /* Get source ip */
        int ret = -WM_FAIL;
        ret     = wlan_get_ipv4_addr(&cloud_keep_alive->src_ip);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("Cannot get IP");
        }
        (void)memcpy(&cloud_keep_alive_param[cloud_keep_alive->mkeep_alive_id], cloud_keep_alive, sizeof(wlan_cloud_keep_alive_t));
    }
    else
    {
        int i;

        for (i = 0; i < MAX_KEEP_ALIVE_ID; i++)
        {
            cloud_keep_alive = &cloud_keep_alive_param[i];

            if (cloud_keep_alive && cloud_keep_alive->enable && (ntohs(dst_port) == cloud_keep_alive->dst_port))
            {
                /* Copy source port, destination port, sequece number, ack number, window size for keep alive.
                   IP header checksum and TCP pesudo header checksum are calculated by WLAN FW */
                (void)memcpy(packet_default + 12, &cloud_keep_alive->src_ip, sizeof(cloud_keep_alive->src_ip));
                (void)memcpy(packet_default + 16, &cloud_keep_alive->dst_ip, sizeof(cloud_keep_alive->dst_ip));
                (void)memcpy(packet_default + 20, &src_port, sizeof(src_port));
                (void)memcpy(packet_default + 22, &dst_port, sizeof(dst_port));
                (void)memcpy(packet_default + 24, &seq_number, sizeof(seq_number));
                (void)memcpy(packet_default + 28, &ack_number, sizeof(ack_number));

                cloud_keep_alive->pkt_len = pkt_len_default;
                (void)memcpy(cloud_keep_alive->packet, packet_default, cloud_keep_alive->pkt_len);

                cloud_keep_alive->cached = MTRUE;
            }
        }
    }

    return WM_SUCCESS;
}

int wlan_cloud_keep_alive_enabled(t_u32 dst_ip, t_u16 dst_port)
{
    int i;
    wifi_cloud_keep_alive_t *cloud_keep_alive = NULL;

    for (i = 0; i < MAX_KEEP_ALIVE_ID; i++)
    {
        cloud_keep_alive = &cloud_keep_alive_param[i];
        if (cloud_keep_alive && (cloud_keep_alive->dst_ip == dst_ip) && (cloud_keep_alive->dst_port == dst_port))
        {
            return 1;
        }
    }

    return 0;
}

int wlan_start_cloud_keep_alive(void)
{
    int i;
    wifi_cloud_keep_alive_t *cloud_keep_alive = NULL;

    for (i = 0; i < MAX_KEEP_ALIVE_ID; i++)
    {
        cloud_keep_alive = &cloud_keep_alive_param[i];
        if (cloud_keep_alive && cloud_keep_alive->cached && cloud_keep_alive->enable)
        {
            cloud_keep_alive->cached = MFALSE;
            wifi_cloud_keep_alive(cloud_keep_alive, MLAN_ACT_SET, NULL);
        }
    }

    return WM_SUCCESS;
}

int wlan_stop_cloud_keep_alive(wlan_cloud_keep_alive_t *cloud_keep_alive)
{
    t_u8 enable = MTRUE;

    if (cloud_keep_alive == NULL)
        return -WM_E_INVAL;

    wifi_cloud_keep_alive(cloud_keep_alive, MLAN_ACT_GET, &enable);

    if (enable == MFALSE)
    {
        wlcm_e("Cloud keep alive is already stoped");
        return 0;
    }
    return wifi_cloud_keep_alive(cloud_keep_alive, MLAN_ACT_SET, NULL);
}
#endif

uint16_t wlan_get_beacon_period(void)
{
    struct wlan_network* network = NULL;

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        network = &wlan.networks[wlan.cur_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get network info");
        return 0;
    }

    return network->beacon_period;
}

static os_semaphore_t wlan_dtim_sem;
static uint8_t dtim_period;

static int pscan_cb(unsigned int count)
{
    struct wlan_scan_result res;
    unsigned int i;
    int err;

    dtim_period = 0;

    if (count == 0U)
    {
        (void)PRINTF("networks not found\r\n");
        (void)os_semaphore_put(&wlan_dtim_sem);
        return 0;
    }

    for (i = 0; i < count; i++)
    {
        err = wlan_get_scan_result(i, &res);
        if (err != 0)
        {
            (void)PRINTF("Error: can't get scan res %d\r\n", i);
            continue;
        }

        dtim_period = res.dtim_period;
    }

    (void)os_semaphore_put(&wlan_dtim_sem);

    return 0;
}

uint8_t wlan_get_dtim_period(void)
{
    int rv;

    rv = os_semaphore_create(&wlan_dtim_sem, "wlandtimsem");
    if (rv != WM_SUCCESS)
    {
        return 0;
    }

    /* Consume so that 'get' blocks when used later */
    (void)os_semaphore_get(&wlan_dtim_sem, OS_WAIT_FOREVER);

    if (wlan_pscan(pscan_cb) != 0)
    {
        (void)PRINTF("Error: scan request failed\r\n");
        (void)os_semaphore_put(&wlan_dtim_sem);
        (void)os_semaphore_delete(&wlan_dtim_sem);
        return 0;
    }

    /* Wait till scan for DTIM is complete */
    /*TODO:This need to be handled in better way. */
    if (os_semaphore_get(&wlan_dtim_sem, os_msec_to_ticks(500)) != WM_SUCCESS)
    {
        wlcm_e("Do not call this API from wlan event handler\r\n");
        dtim_period = 0;
    }
    (void)os_semaphore_delete(&wlan_dtim_sem);

    return dtim_period;
}

int wlan_get_data_rate(wlan_ds_rate *ds_rate, mlan_bss_type bss_type)
{
    return wifi_get_data_rate(ds_rate, bss_type);
}

static int wlan_set_pmfcfg(uint8_t mfpc, uint8_t mfpr)
{
    if (!mfpc && mfpr)
    {
        return -WM_FAIL;
    }

    return wifi_set_pmfcfg(mfpc, mfpr);
}

int wlan_get_pmfcfg(uint8_t *mfpc, uint8_t *mfpr)
{
    return wifi_get_pmfcfg(mfpc, mfpr);
}

int wlan_uap_get_pmfcfg(uint8_t *mfpc, uint8_t *mfpr)
{
    if (is_uap_started())
    {
        return wifi_uap_get_pmfcfg(mfpc, mfpr);
    }
    return -WM_FAIL;
}


int wlan_set_packet_filters(wlan_flt_cfg_t *flt_cfg)
{
    return wifi_set_packet_filters(flt_cfg);
}

int wlan_set_auto_arp(void)
{
    int ret;
    unsigned int ipv4_addr;
    wlan_flt_cfg_t flt_cfg;

    ret = wlan_get_ipv4_addr(&ipv4_addr);
    if (ret != WM_SUCCESS)
    {
        wlcm_e("Cannot get IP");
        return -WM_FAIL;
    }

    (void)memset(&flt_cfg, 0, sizeof(wlan_flt_cfg_t));

    flt_cfg.criteria = CRITERIA_BROADCAST;
    flt_cfg.nentries = 1;

    flt_cfg.mef_entry[0].mode   = MEF_MODE_HOST_SLEEP; // MBIT(0);
    flt_cfg.mef_entry[0].action = MEF_AUTO_ARP;

    flt_cfg.mef_entry[0].filter_num = 3;

    flt_cfg.mef_entry[0].filter_item[0].type         = TYPE_BYTE_EQ;
    flt_cfg.mef_entry[0].filter_item[0].repeat       = 6;
    flt_cfg.mef_entry[0].filter_item[0].offset       = 0;
    flt_cfg.mef_entry[0].filter_item[0].num_byte_seq = 1;
    flt_cfg.mef_entry[0].filter_item[0].byte_seq[0]  = 0xff;
    flt_cfg.mef_entry[0].rpn[1]                      = RPN_TYPE_AND;

    flt_cfg.mef_entry[0].filter_item[1].type         = TYPE_BYTE_EQ;
    flt_cfg.mef_entry[0].filter_item[1].repeat       = 1;
    flt_cfg.mef_entry[0].filter_item[1].offset       = 20;
    flt_cfg.mef_entry[0].filter_item[1].num_byte_seq = 2;
    (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[1].byte_seq, (const void *)"\x08\x06", 2);
    flt_cfg.mef_entry[0].rpn[2] = RPN_TYPE_AND;

    flt_cfg.mef_entry[0].filter_item[2].type         = TYPE_BYTE_EQ;
    flt_cfg.mef_entry[0].filter_item[2].repeat       = 1;
    flt_cfg.mef_entry[0].filter_item[2].offset       = 46;
    flt_cfg.mef_entry[0].filter_item[2].num_byte_seq = 4;
    (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[2].byte_seq, (const void *)&ipv4_addr, 4);

    return wifi_set_packet_filters(&flt_cfg);
}

#ifndef __ZEPHYR__
#define DIV_ROUND_UP(n, d) (((n) + (d)-1) / (d))
#endif

#ifndef CONFIG_WPA_SUPP
static inline bool is_broadcast_ether_addr(const t_u8 *addr)
{
    return (*(const t_u16 *)(addr + 0) & *(const t_u16 *)(addr + 2) & *(const t_u16 *)(addr + 4)) == 0xffff;
}
#endif

/**
 * @brief is_wowlan_pattern_supported
 *
 * @param priv                 A pointer to moal_private
 * @param pat                 A pointer to wowlan pattern
 * @param byte_seq       A pointer to byte_seq
 *
 * @return                      1 -- support, 0 -- not support
 */
static t_bool is_wowlan_pattern_supported(wifi_wowlan_pattern_t *pat, t_u8 *byte_seq)
{
    int j, k, valid_byte_cnt = 0;
    t_bool dont_care_byte = false;

    for (j = 0; j < DIV_ROUND_UP(pat->pattern_len, 8); j++)
    {
        for (k = 0; k < 8; k++)
        {
            if (pat->mask[j] & 1 << k)
            {
                (void)memcpy((void *)(byte_seq + valid_byte_cnt), (const void *)&pat->pattern[j * 8 + k], 1);
                valid_byte_cnt++;
                if (dont_care_byte)
                    return false;
            }
            else
            {
                if (valid_byte_cnt)
                    dont_care_byte = true;
            }

            if (valid_byte_cnt > MAX_NUM_BYTE_SEQ)
                return false;
        }
    }

    byte_seq[MAX_NUM_BYTE_SEQ] = valid_byte_cnt;

    return true;
}

int wlan_wowlan_cfg_ptn_match(wlan_wowlan_ptn_cfg_t *ptn_cfg)
{
    wlan_flt_cfg_t flt_cfg;
    wifi_mef_entry_t *mef_entry;
    t_u8 byte_seq[MAX_NUM_BYTE_SEQ + 1];
    const t_u8 ipv4_mc_mac[] = {0x33, 0x33};
    const t_u8 ipv6_mc_mac[] = {0x01, 0x00, 0x5e};
    int filt_num = 0, i = 0, ret = 0;
    t_bool first_pat = true;
    memset(&flt_cfg, 0, sizeof(flt_cfg));
    //  mef_cfg.mef_act_type = MEF_ACT_WOWLAN;
    mef_entry = &flt_cfg.mef_entry[0];

    mef_entry->mode   = MEF_MODE_HOST_SLEEP;
    mef_entry->action = MEF_ACTION_ALLOW_AND_WAKEUP_HOST;

    for (i = 0; i < ptn_cfg->n_patterns; i++)
    {
        memset(byte_seq, 0, sizeof(byte_seq));
        if (!is_wowlan_pattern_supported(&ptn_cfg->patterns[i], byte_seq))
        {
            PRINTM(MERROR, "Pattern not supported\n");
            ret = -EOPNOTSUPP;
            return ret;
        }
        if (!ptn_cfg->patterns[i].pkt_offset)
        {
            if (!(byte_seq[0] & 0x01) && (byte_seq[MAX_NUM_BYTE_SEQ] == 1))
            {
                flt_cfg.criteria |= CRITERIA_UNICAST;
                continue;
            }
            else if (is_broadcast_ether_addr(byte_seq))
            {
                flt_cfg.criteria |= CRITERIA_BROADCAST;
                continue;
            }
            else if ((!memcmp(byte_seq, ipv4_mc_mac, 2) && (byte_seq[MAX_NUM_BYTE_SEQ] == 2)) ||
                     (!memcmp(byte_seq, ipv6_mc_mac, 3) && (byte_seq[MAX_NUM_BYTE_SEQ] == 3)))
            {
                flt_cfg.criteria |= CRITERIA_MULTICAST;
                continue;
            }
        }

        //    mef_entry->filter_item[filt_num].fill_flag =
        //          (FILLING_TYPE | FILLING_REPEAT | FILLING_BYTE_SEQ |
        //         FILLING_OFFSET);
        mef_entry->filter_item[filt_num].repeat = 1;
        mef_entry->filter_item[filt_num].offset = ptn_cfg->patterns[i].pkt_offset;
        (void)memcpy((void *)mef_entry->filter_item[filt_num].byte_seq, (const void *)byte_seq, MAX_NUM_BYTE_SEQ);
        mef_entry->filter_item[filt_num].num_byte_seq = byte_seq[MAX_NUM_BYTE_SEQ];
        mef_entry->filter_item[filt_num].type         = TYPE_BYTE_EQ;
        if (first_pat)
            first_pat = false;
        else
            mef_entry->rpn[filt_num] = RPN_TYPE_OR;

        filt_num++;
    }
    if (ptn_cfg->enable)
    {
        //   (void)memset(&flt_cfg, 0, sizeof(wlan_flt_cfg_t));

        flt_cfg.criteria = CRITERIA_UNICAST | CRITERIA_BROADCAST | CRITERIA_MULTICAST;
        flt_cfg.nentries = 1;

        flt_cfg.mef_entry[0].mode   = MEF_MODE_HOST_SLEEP;
        flt_cfg.mef_entry[0].action = MEF_ACTION_ALLOW_AND_WAKEUP_HOST;

        flt_cfg.mef_entry[0].filter_num = 2;

        flt_cfg.mef_entry[0].filter_item[filt_num].type         = TYPE_BYTE_EQ;
        flt_cfg.mef_entry[0].filter_item[filt_num].repeat       = 16;
        flt_cfg.mef_entry[0].filter_item[filt_num].offset       = 56;
        flt_cfg.mef_entry[0].filter_item[filt_num].num_byte_seq = MLAN_MAC_ADDR_LENGTH;
        (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[filt_num].byte_seq, (const void *)wlan.sta_mac,
                     MLAN_MAC_ADDR_LENGTH);
        if (filt_num)
            flt_cfg.mef_entry[0].rpn[filt_num] = RPN_TYPE_OR;
        filt_num++;
        // flt_cfg.mef_entry.filter_item[1].fill_flag	  = (FILLING_TYPE | FILLING_REPEAT | FILLING_BYTE_SEQ |
        // FILLING_OFFSET);
        flt_cfg.mef_entry[0].filter_item[filt_num].type         = TYPE_BYTE_EQ;
        flt_cfg.mef_entry[0].filter_item[filt_num].repeat       = 16;
        flt_cfg.mef_entry[0].filter_item[filt_num].offset       = 28;
        flt_cfg.mef_entry[0].filter_item[filt_num].num_byte_seq = MLAN_MAC_ADDR_LENGTH;
        (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[filt_num].byte_seq, (const void *)wlan.sta_mac,
                     MLAN_MAC_ADDR_LENGTH);
        if (filt_num)
            flt_cfg.mef_entry[0].rpn[filt_num] = RPN_TYPE_OR;
        filt_num++;
    }
    flt_cfg.mef_entry[0].filter_num = filt_num;
    return wifi_set_packet_filters(&flt_cfg);
}


int wlan_set_ipv6_ns_offload()
{
    wlan_flt_cfg_t flt_cfg;

    (void)memset(&flt_cfg, 0, sizeof(wlan_flt_cfg_t));

    flt_cfg.criteria = (MBIT(1) | MBIT(3));
    flt_cfg.nentries = 1;

    flt_cfg.mef_entry[0].mode   = MBIT(0);
    flt_cfg.mef_entry[0].action = 0x40;

    flt_cfg.mef_entry[0].filter_num = 2;

    flt_cfg.mef_entry[0].filter_item[0].type         = TYPE_BYTE_EQ;
    flt_cfg.mef_entry[0].filter_item[0].repeat       = 1;
    flt_cfg.mef_entry[0].filter_item[0].offset       = 20;
    flt_cfg.mef_entry[0].filter_item[0].num_byte_seq = 2;
    (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[0].byte_seq, (const void *)"\x86\xdd", 2);
    flt_cfg.mef_entry[0].rpn[1] = RPN_TYPE_AND;

    flt_cfg.mef_entry[0].filter_item[1].type         = TYPE_BYTE_EQ;
    flt_cfg.mef_entry[0].filter_item[1].repeat       = 1;
    flt_cfg.mef_entry[0].filter_item[1].offset       = 62;
    flt_cfg.mef_entry[0].filter_item[1].num_byte_seq = 1;
    (void)memcpy((void *)flt_cfg.mef_entry[0].filter_item[1].byte_seq, (const void *)"\x87", 1);

    return wifi_set_packet_filters(&flt_cfg);
}

int wlan_get_current_bssid(uint8_t *bssid)
{
    struct wlan_network* network = NULL;

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        network = &wlan.networks[wlan.cur_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get network info");
        return -WM_FAIL;
    }
    if (bssid != NULL)
    {
        (void)memcpy((void *)bssid, (const void *)network->bssid, IEEEtypes_ADDRESS_SIZE);
        return WM_SUCCESS;
    }

    return -WM_FAIL;
}

uint8_t wlan_get_current_channel(void)
{
    struct wlan_network* network = NULL;

    if (wlan.running && (is_state(CM_STA_CONNECTED) || is_state(CM_STA_ASSOCIATED)))
    {
        network = &wlan.networks[wlan.cur_network_idx];
    }

    if (network == NULL)
    {
        wlcm_e("cannot get network info");
        return 0;
    }

    return (uint8_t)network->channel;
}

void wlan_sta_ampdu_tx_enable(void)
{
    wifi_sta_ampdu_tx_enable();
}

void wlan_sta_ampdu_tx_disable(void)
{
    wifi_sta_ampdu_tx_disable();
}

void wlan_sta_ampdu_rx_enable(void)
{
    wifi_sta_ampdu_rx_enable();
}

void wlan_sta_ampdu_rx_disable(void)
{
    wifi_sta_ampdu_rx_disable();
}

void wlan_uap_ampdu_tx_enable(void)
{
    wifi_uap_ampdu_tx_enable();
}

void wlan_uap_ampdu_tx_disable(void)
{
    wifi_uap_ampdu_tx_disable();
}

void wlan_uap_ampdu_rx_enable(void)
{
    wifi_uap_ampdu_rx_enable();
}

void wlan_uap_ampdu_rx_disable(void)
{
    wifi_uap_ampdu_rx_disable();
}


void wlan_uap_set_scan_chan_list(wifi_scan_chan_list_t scan_chan_list)
{
    wlan_uap_scan_chan_list_set = true;
    (void)memcpy((void *)&wlan.scan_chan_list, (const void *)&scan_chan_list, sizeof(wifi_scan_chan_list_t));
}

void wlan_uap_set_beacon_period(const uint16_t beacon_period)
{
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *netif = net_get_uap_interface();

    wpa_supp_set_ap_beacon_int(netif, beacon_period);
#endif
#endif

    wifi_uap_set_beacon_period(beacon_period);
}

int wlan_uap_set_bandwidth(const uint8_t bandwidth)
{
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *netif = net_get_uap_interface();

    wpa_supp_set_ap_bw(netif, bandwidth);
#endif
#endif

    return wifi_uap_set_bandwidth(bandwidth);
}

int wlan_uap_get_bandwidth(uint8_t *bandwidth)
{
    *bandwidth = wifi_uap_get_bandwidth();
    if (*bandwidth == BANDWIDTH_20MHZ || *bandwidth == BANDWIDTH_40MHZ
#ifdef CONFIG_11AC
        || *bandwidth == BANDWIDTH_80MHZ
#endif
    )
    {
        return WM_SUCCESS;
    }
    else
    {
        return -WM_FAIL;
    }
}

int wlan_uap_set_hidden_ssid(const t_u8 hidden_ssid)
{
    if (hidden_ssid != 0 && hidden_ssid != 1 && hidden_ssid != 2)
    {
        return -WM_FAIL;
    }

    if (is_uap_started())
    {
        (void)PRINTF("Pls set hidden_ssid before start uAP.\r\n");
        return -WM_FAIL;
    }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *netif = net_get_uap_interface();

    wpa_supp_set_ap_hidden_ssid(netif, hidden_ssid);
#endif
#endif

    wifi_uap_set_hidden_ssid(hidden_ssid);

    return WM_SUCCESS;
}

void wlan_uap_ctrl_deauth(const bool enable)
{
    (void)wifi_uap_ctrl_deauth(enable);
}

void wlan_uap_set_ecsa(void)
{
    wifi_uap_set_ecsa();
}

void wlan_uap_set_htcapinfo(const uint16_t ht_cap_info)
{
    wifi_uap_set_htcapinfo(ht_cap_info);
}

void wlan_uap_set_httxcfg(unsigned short httxcfg)
{
    wifi_uap_set_httxcfg(httxcfg);
}


int wlan_set_rts(int rts)
{
    return wifi_set_rts(rts, MLAN_BSS_TYPE_STA);
}

int wlan_set_uap_rts(int rts)
{
    return wifi_set_rts(rts, MLAN_BSS_TYPE_UAP);
}

int wlan_set_frag(int frag)
{
    return wifi_set_frag(frag, MLAN_BSS_TYPE_STA);
}

int wlan_set_uap_frag(int frag)
{
    return wifi_set_frag(frag, MLAN_BSS_TYPE_UAP);
}

#ifdef CONFIG_11K
int _wlan_rrm_scan_cb(unsigned int count)
{
    t_u16 i;
    t_u8 *rep_buf = NULL;
    t_u8 *buf_pos = NULL;
    /* The sufficient size is the length including reporting frame body */
    t_u16 suffi_len           = 250U;
    t_u32 pos_last_indication = 0U;
    bool match_ap_found       = false;
    int meas_report_len       = 0;

    /* process scan result */
    rep_buf = (t_u8 *)os_mem_alloc(BEACON_REPORT_BUF_SIZE);
    if (rep_buf == NULL)
    {
        PRINTM(MERROR, "Cannot allocate memory for report buffer");
        return -1;
    }

    (void)memset(rep_buf, 0, BEACON_REPORT_BUF_SIZE);
    buf_pos = rep_buf;
    for (i = 0; i < count; i++)
    {
        if (wlan_rrm_matched_ap_found(&wlan.rrm_scan_cb_param.rep_data, &mlan_adap->pscan_table[i]))
        {
            wlan_add_rm_beacon_report(&wlan.rrm_scan_cb_param.rep_data, &mlan_adap->pscan_table[i], &buf_pos,
                                      BEACON_REPORT_BUF_SIZE - (buf_pos - rep_buf), &pos_last_indication);
        }

        /* If current rep_buf is not enough and still have AP not added, just send the report */
        if ((buf_pos + suffi_len - rep_buf > BEACON_REPORT_BUF_SIZE) && (i < count - 1U) &&
            wlan_rrm_matched_ap_found(&wlan.rrm_scan_cb_param.rep_data, &mlan_adap->pscan_table[i + 1U]))
        {
            match_ap_found  = 1;
            meas_report_len = buf_pos - rep_buf;
            /* send beacon report, not the last one */
            wlan_send_mgmt_rm_beacon_report(wlan.rrm_scan_cb_param.dialog_tok, wlan.sta_mac,
                                            wlan.rrm_scan_cb_param.dst_addr, rep_buf, (t_u32)meas_report_len,
                                            (bool)wlan.rrm_scan_cb_param.protect);
            /* Prepare for the next beacon report */
            (void)memset(rep_buf, 0, BEACON_REPORT_BUF_SIZE);
            buf_pos = rep_buf;
        }

        /* Last AP in scan table, and matched AP found */
        if ((i == count - 1U) && (buf_pos > rep_buf))
        {
            match_ap_found = 1;
            /* Update last indication, the last one */
            if (wlan.rrm_scan_cb_param.rep_data.last_ind != 0U && pos_last_indication != 0U)
            {
                *(char *)pos_last_indication = (char)1U;
            }
            meas_report_len = buf_pos - rep_buf;
            /* send beacon report, the last one */
            wlan_send_mgmt_rm_beacon_report(wlan.rrm_scan_cb_param.dialog_tok, wlan.sta_mac,
                                            wlan.rrm_scan_cb_param.dst_addr, rep_buf, (t_u32)meas_report_len,
                                            (bool)wlan.rrm_scan_cb_param.protect);
        }
    }

    /* If no matched AP found, no beacon report detail */
    if (!match_ap_found)
    {
        *buf_pos++ = (t_u8)MEASURE_REPORT;
        /* Tag length */
        *buf_pos++      = 3;
        *buf_pos++      = wlan.rrm_scan_cb_param.rep_data.token;
        *buf_pos++      = WLAN_RRM_REPORT_MODE_ACCEPT;
        *buf_pos++      = WLAN_RRM_MEASURE_TYPE_BEACON;
        meas_report_len = buf_pos - rep_buf;
        /* send beacon report */
        wlan_send_mgmt_rm_beacon_report(wlan.rrm_scan_cb_param.dialog_tok, wlan.sta_mac,
                                        wlan.rrm_scan_cb_param.dst_addr, rep_buf, (t_u32)meas_report_len,
                                        (bool)wlan.rrm_scan_cb_param.protect);
    }

    os_mem_free(rep_buf);
    return 0;
}

void wlan_rrm_request_scan(wlan_scan_params_v2_t *wlan_scan_param, wlan_rrm_scan_cb_param *scan_cb_param)
{
    char *ssid = NULL;
    char *ssid2 = NULL;

    ssid = wlan_scan_param->ssid[0];
    ssid2 = wlan_scan_param->ssid[1];

    if (wlan_scan_param == NULL || scan_cb_param == NULL)
    {
        wlcm_d("ignoring scan request with NULL scan or cb params");
        return;
    }
    if (!is_scanning_allowed())
    {
        wlcm_d("ignoring scan request in invalid state");
        return;
    }

    (void)memcpy(&wlan.rrm_scan_cb_param, scan_cb_param, sizeof(wlan_rrm_scan_cb_param));

    if (is_uap_started() || is_sta_connected())
        wlan_scan_param->scan_chan_gap = scan_channel_gap;
    else
        wlan_scan_param->scan_chan_gap = (t_u16)0U;

    int ret = wifi_send_scan_cmd((t_u8)BSS_ANY, wlan_scan_param->bssid,
                                 ssid, ssid2,
                                 wlan_scan_param->num_channels, wlan_scan_param->chan_list, wlan_scan_param->num_probes,
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
                                 wlan_scan_param->rssi_threshold,
#endif
                                 wlan_scan_param->scan_chan_gap,
                                 false, false);
    if (ret == WM_SUCCESS)
    {
        wlan.scan_cb       = (int (*)(unsigned int count))(wlan_scan_param->cb);
        wlan.sta_return_to = wlan.sta_state;
        wlan.sta_state     = CM_STA_SCANNING_USER;
    }
    else
    {
        wlcm_e("wifi send scan cmd failed");
    }
}
#endif


void wlan_set_scan_channel_gap(unsigned scan_chan_gap)
{
    scan_channel_gap = (t_u16)scan_chan_gap;
    return;
}

#ifdef CONFIG_11K
int wlan_host_11k_cfg(int enable_11k)
{
#ifdef CONFIG_WPA_SUPP
    wlan.enable_11k = enable_11k;
    return WM_SUCCESS;
#else
    return wifi_host_11k_cfg(enable_11k);
#endif
}

bool wlan_get_host_11k_status()
{
    return wlan.enable_11k;
}

int wlan_host_11k_neighbor_req(const char *ssid)
{
    int ret = -WM_FAIL;
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

    if (!is_sta_connected())
    {
        wlcm_d("Error: sta connection is required before sending neighbor report req");
        return -WM_FAIL;
    }

#ifdef CONFIG_WPA_SUPP
    ret = wpa_supp_send_neighbor_rep(netif, (char *)ssid, 0, 0);
#else
    ret = wifi_host_11k_neighbor_req(ssid);
#endif
    if (ret == WM_SUCCESS)
    {
        wlan.neighbor_req = true;
        (void)os_timer_activate(&wlan.neighbor_req_timer);
    }
    return ret;
}
#endif

#ifdef CONFIG_11V
int wlan_host_11v_bss_trans_query(t_u8 query_reason)
{
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#else
    int ret = -WM_FAIL;
#endif

    if (!is_sta_connected())
    {
        wlcm_d("Error: sta connection is required before sending bss transition query");
        return -WM_FAIL;
    }

#ifdef CONFIG_WPA_SUPP
    return wpa_supp_send_btm_query(netif, query_reason);
#else
    ret = wifi_host_11v_bss_trans_query(query_reason);
    if (ret == WM_SUCCESS)
    {
        wlan.neighbor_req = true;
        (void)os_timer_activate(&wlan.neighbor_req_timer);
    }
    return ret;
#endif
}
#endif

#ifndef CONFIG_WPA_SUPP
#ifdef CONFIG_DRIVER_MBO
int wlan_host_mbo_cfg(int enable_mbo)
{
    return wifi_host_mbo_cfg(enable_mbo);
}

int wlan_mbo_peferch_cfg(t_u8 ch0, t_u8 pefer0, t_u8 ch1, t_u8 pefer1)
{
    uint8_t ap_addr[IEEEtypes_ADDRESS_SIZE];
    if (is_sta_connected())
    {
        (void)wlan_get_current_bssid(ap_addr);
        return wifi_mbo_send_preferch_wnm(wlan.sta_mac, (t_u8 *)ap_addr, ch0, pefer0, ch1, pefer1);
    }
    else
    {
        return wifi_mbo_preferch_cfg(ch0, pefer0, ch1, pefer1);
    }
}
#endif
#endif


#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11AX
int wlan_mbo_peferch_cfg(const char *non_pref_chan)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_mbo_update_non_pref_chan(netif, non_pref_chan);
}

int wlan_mbo_set_cell_capa(t_u8 cell_capa)
{
    struct netif *netif = net_get_sta_interface();

    if (cell_capa != 1 && cell_capa != 2 && cell_capa != 3)
    {
        return -WM_E_PERM;
    }

    return wpa_supp_mbo_set_cell_capa(netif, cell_capa);
}

int wlan_mbo_set_oce(t_u8 oce)
{
    struct netif *netif = net_get_sta_interface();

    if (oce != 1 && oce != 2)
    {
        return -WM_E_PERM;
    }

    return wpa_supp_mbo_set_oce(netif, oce);

}
#endif

int wlan_set_okc(t_u8 okc)
{
    struct netif *netif = net_get_sta_interface();

    if (okc != 0 && okc != 1)
    {
        return -WM_E_PERM;
    }

    return wpa_supp_set_okc(netif, okc);

}

int wlan_pmksa_list(char *buf, size_t buflen)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_pmksa_list(netif, buf, buflen);
}

int wlan_pmksa_flush()
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_pmksa_flush(netif);
}

int wlan_set_scan_interval(int scan_int)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_set_scan_interval(netif, scan_int);
}
#endif

int wlan_set_sta_mac_filter(int filter_mode, int mac_count, unsigned char *mac_addr)
{
#ifdef CONFIG_WPA_SUPP
    return wlan_host_set_sta_mac_filter(filter_mode, mac_count, mac_addr);
#else
    return wifi_set_sta_mac_filter(filter_mode, mac_count, mac_addr);
#endif
}

#ifdef CONFIG_WPA2_ENTP
void wlan_enable_wpa2_enterprise_ap_only()
{
    wlan.allow_wpa2_enterprise_ap_only = true;
    wifi_scan_enable_wpa2_enterprise_ap_only();
}
#endif

void wlan_version_extended(void)
{
#if SDK_DEBUGCONSOLE != DEBUGCONSOLE_DISABLE
    char *version_str;

    version_str = wlan_get_firmware_version_ext();

    (void)PRINTF("WLAN Driver Version   : %s\r\n", WLAN_DRV_VERSION);
    (void)PRINTF("WLAN Firmware Version : %s\r\n", version_str);
#endif
}

#ifdef CONFIG_WIFI_TX_PER_TRACK
void wlan_set_tx_pert(struct wlan_tx_pert_info *tx_pert, mlan_bss_type bss_type)
{
    int ret = WM_SUCCESS;

    ret = wifi_set_tx_pert((void *)tx_pert, bss_type);
    if (ret != WM_SUCCESS)
        (void)PRINTF("Failed to set tx per tracking.\r\n");
    return;
}
#endif

#ifdef CONFIG_TX_RX_HISTOGRAM
void wlan_set_txrx_histogram(struct wlan_txrx_histogram_info *txrx_histogram, t_u8 *data)
{
    int ret = WM_SUCCESS;

    wifi_set_txrx_histogram((void *)txrx_histogram, data);
    if (ret != WM_SUCCESS)
        (void)PRINTF("Failed to set txrx histogram config.\r\n");
    return;
}
#endif

#ifdef CONFIG_ROAMING
int wlan_set_roaming(const int enable, const uint8_t rssi_low_threshold)
{
#ifdef CONFIG_WPA_SUPP
    struct netif *netif = net_get_sta_interface();
#endif

    wlan.roaming_enabled = enable;

#ifdef CONFIG_WPA_SUPP
    wpa_supp_set_okc(netif, wlan.roaming_enabled == true ? 0 : 1);
#endif

    wlan.rssi_low_threshold = rssi_low_threshold;

    return wifi_config_roaming(enable, &wlan.rssi_low_threshold);
}

int wlan_get_roaming_status()
{
    return wlan.roaming_enabled;
}
#endif

#ifdef CONFIG_WIFI_MEM_ACCESS
int wlan_mem_access(uint16_t action, uint32_t addr, uint32_t *value)
{
    return wifi_mem_access(action, addr, value);
}
#endif

#ifdef CONFIG_WIFI_BOOT_SLEEP
int wlan_boot_sleep(uint16_t action, uint16_t *enable)
{

    if ((*enable != 0) && (*enable != 1))
    {
        return -WM_FAIL;
    }

    return wifi_boot_sleep(action, enable);
}
#endif

#ifdef CONFIG_RF_TEST_MODE

int wlan_set_rf_test_mode(void)
{
    wlan_ieeeps_off();
    wlan_deepsleepps_off();
    return wifi_set_rf_test_mode();
}

int wlan_unset_rf_test_mode(void)
{
    (void)wifi_unset_rf_test_mode();
#ifdef CONFIG_WIFI_AUTO_POWER_SAVE
    wlan_deepsleepps_on();
    wlan_ieeeps_on(wlan.wakeup_conditions);
#endif
    return WM_SUCCESS;
}

int wlan_set_rf_channel(const uint8_t channel)
{
    return wifi_set_rf_channel(channel);
}

int wlan_set_rf_radio_mode(const uint8_t mode)
{
    return wifi_set_rf_radio_mode(mode);
}

int wlan_get_rf_channel(uint8_t *channel)
{
    if (channel != NULL)
        return wifi_get_rf_channel(channel);

    return -WM_FAIL;
}

int wlan_get_rf_radio_mode(uint8_t *mode)
{
    if (mode)
        return wifi_get_rf_radio_mode(mode);

    return -WM_FAIL;
}

int wlan_set_rf_bandwidth(const uint8_t bandwidth)
{
    return wifi_set_rf_bandwidth(bandwidth);
}

int wlan_set_rf_band(const uint8_t band)
{
    return wifi_set_rf_band(band);
}

int wlan_get_rf_band(uint8_t *band)
{
    if (band != NULL)
        return wifi_get_rf_band(band);

    return -WM_FAIL;
}

int wlan_get_rf_bandwidth(uint8_t *bandwidth)
{
    if (bandwidth != NULL)
        return wifi_get_rf_bandwidth(bandwidth);

    return -WM_FAIL;
}

int wlan_get_rf_per(uint32_t *rx_tot_pkt_count, uint32_t *rx_mcast_bcast_count, uint32_t *rx_pkt_fcs_error)
{
    if ((rx_tot_pkt_count != NULL) && (rx_mcast_bcast_count != NULL) && (rx_pkt_fcs_error != NULL))
        return wifi_get_rf_per(rx_tot_pkt_count, rx_mcast_bcast_count, rx_pkt_fcs_error);

    return -WM_FAIL;
}

int wlan_set_rf_tx_cont_mode(const uint32_t enable_tx,
                             const uint32_t cw_mode,
                             const uint32_t payload_pattern,
                             const uint32_t cs_mode,
                             const uint32_t act_sub_ch,
                             const uint32_t tx_rate)
{
    return wifi_set_rf_tx_cont_mode(enable_tx, cw_mode, payload_pattern, cs_mode, act_sub_ch, tx_rate);
}

int wlan_set_rf_tx_antenna(const uint8_t antenna)
{
    return wifi_set_rf_tx_antenna(antenna);
}

int wlan_get_rf_tx_antenna(uint8_t *antenna)
{
    if (antenna != NULL)
        return wifi_get_rf_tx_antenna(antenna);

    return -WM_FAIL;
}

int wlan_set_rf_rx_antenna(const uint8_t antenna)
{
    return wifi_set_rf_rx_antenna(antenna);
}

int wlan_get_rf_rx_antenna(uint8_t *antenna)
{
    if (antenna != NULL)
        return wifi_get_rf_rx_antenna(antenna);

    return -WM_FAIL;
}

int wlan_set_rf_tx_power(const uint32_t power, const uint8_t mod, const uint8_t path_id)
{
    return wifi_set_rf_tx_power(power, mod, path_id);
}

int wlan_cfg_rf_he_tb_tx(uint16_t enable,uint16_t qnum,uint16_t aid,uint16_t axq_mu_timer,int16_t tx_power)
{
	return wifi_cfg_rf_he_tb_tx(enable, qnum, aid,axq_mu_timer,tx_power);
}

int wlan_rf_trigger_frame_cfg(uint32_t Enable_tx,uint32_t Standalone_hetb,uint8_t FRAME_CTRL_TYPE,
                              uint8_t FRAME_CTRL_SUBTYPE,uint16_t FRAME_DURATION,uint64_t TriggerType,
							  uint64_t UlLen,uint64_t MoreTF,uint64_t CSRequired,uint64_t UlBw,
							  uint64_t LTFType,uint64_t LTFMode,uint64_t LTFSymbol,uint64_t UlSTBC,
							  uint64_t LdpcESS,uint64_t ApTxPwr,uint64_t PreFecPadFct,
							  uint64_t PeDisambig,uint64_t SpatialReuse,uint64_t Doppler,
							  uint64_t HeSig2,uint32_t AID12,uint32_t RUAllocReg,uint32_t RUAlloc,
							  uint32_t UlCodingType,uint32_t UlMCS,uint32_t UlDCM,uint32_t SSAlloc,
							  uint8_t UlTargetRSSI,uint8_t MPDU_MU_SF,uint8_t TID_AL,uint8_t AC_PL,
							  uint8_t Pref_AC)
{
	return wifi_rf_trigger_frame_cfg(Enable_tx,Standalone_hetb,FRAME_CTRL_TYPE,
                                     FRAME_CTRL_SUBTYPE,FRAME_DURATION,TriggerType,
			                         UlLen,MoreTF,CSRequired,UlBw,LTFType,LTFMode,
			                         LTFSymbol,UlSTBC,LdpcESS,ApTxPwr,PreFecPadFct,
			                         PeDisambig,SpatialReuse,Doppler,HeSig2,AID12,
			                         RUAllocReg,RUAlloc,UlCodingType,UlMCS,UlDCM,
			                         SSAlloc,UlTargetRSSI,MPDU_MU_SF,TID_AL,AC_PL,
			                         Pref_AC);
}

int wlan_set_rf_tx_frame(const uint32_t enable,
                         const uint32_t data_rate,
                         const uint32_t frame_pattern,
                         const uint32_t frame_length,
                         const uint16_t adjust_burst_sifs,
                         const uint32_t burst_sifs_in_us,
                         const uint32_t short_preamble,
                         const uint32_t act_sub_ch,
                         const uint32_t short_gi,
                         const uint32_t adv_coding,
                         const uint32_t tx_bf,
                         const uint32_t gf_mode,
                         const uint32_t stbc,
                         const uint8_t *bssid)
{
    return wifi_set_rf_tx_frame(enable, data_rate, frame_pattern, frame_length, adjust_burst_sifs, burst_sifs_in_us,
                                short_preamble, act_sub_ch, short_gi, adv_coding, tx_bf, gf_mode, stbc, bssid);
}

int wlan_set_rf_otp_mac_addr(uint8_t *mac)
{
    return wifi_set_rf_otp_mac_addr(mac);
}

int wlan_get_rf_otp_mac_addr(uint8_t *mac)
{
    if (mac != NULL)
      return wifi_get_rf_otp_mac_addr(mac);

    return -WM_FAIL;
}

int wlan_set_rf_otp_cal_data(const uint8_t *cal_data, uint32_t cal_data_len)
{
    return wifi_set_rf_otp_cal_data(cal_data, cal_data_len);
}

int wlan_get_rf_otp_cal_data(uint8_t *cal_data)
{
    if (cal_data != NULL)
      return wifi_get_rf_otp_cal_data(cal_data);

    return -WM_FAIL;
}
#endif
#ifdef CONFIG_WIFI_FW_DEBUG
void wlan_register_fw_dump_cb(void (*wlan_usb_init_cb)(void),
                              int (*wlan_usb_mount_cb)(),
                              int (*wlan_usb_file_open_cb)(char *test_file_name),
                              int (*wlan_usb_file_write_cb)(uint8_t *data, size_t data_len),
                              int (*wlan_usb_file_close_cb)())
{
    wlan.wlan_usb_init_cb = wlan_usb_init_cb;
    wifi_register_fw_dump_cb(wlan_usb_mount_cb, wlan_usb_file_open_cb, wlan_usb_file_write_cb, wlan_usb_file_close_cb);
}
#endif

#ifdef CONFIG_WMM
void wlan_wmm_tx_stats_dump(int bss_type)
{
    wifi_wmm_tx_stats_dump(bss_type);
}
#endif

int wlan_send_hostcmd(
    const void *cmd_buf, uint32_t cmd_buf_len, void *host_resp_buf, uint32_t resp_buf_len, uint32_t *reqd_resp_len)
{
    if ((cmd_buf == NULL) || (host_resp_buf == NULL) || (reqd_resp_len == NULL))
    {
        return (int)WM_E_NOMEM;
    }
    if (!cmd_buf_len || !resp_buf_len)
    {
        return (int)WM_E_INVAL;
    }

    return wifi_send_hostcmd(cmd_buf, cmd_buf_len, host_resp_buf, resp_buf_len, reqd_resp_len);
}

#ifdef CONFIG_11AX
int wlan_enable_disable_htc(uint8_t option)
{
    int ret                 = -WM_FAIL;
    uint8_t send_htc_set[]  = {0x8b, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x24, 0x01, 0x01, 0x00, 0x00, 0x00};
    uint8_t debug_resp_buf[32] = {0};
    uint32_t reqd_len       = 0;

    send_htc_set[12] = option;

    ret = wlan_send_hostcmd(send_htc_set, sizeof(send_htc_set) / sizeof(uint8_t), debug_resp_buf, sizeof(debug_resp_buf),
                            &reqd_len);

    return ret;
}

int wlan_send_debug_htc(const uint8_t count,
		const uint8_t vht,
		const uint8_t he,
		const uint8_t rxNss,
		const uint8_t channelWidth,
		const uint8_t ulMuDisable,
		const uint8_t txNSTS,
		const uint8_t erSuDisable,
		const uint8_t dlResoundRecomm,
		const uint8_t ulMuDataDisable)
{
    int ret           = -WM_FAIL;
    int i;
    uint8_t debug_cmd_buf[] = {0x8b, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x11, 0x01, 0x40, 0x01, 0x01, 0x00,
			0x02, 0x00, 0x00, 0x00, 0x00, 0x00};

    uint8_t debug_resp_buf[32] = {0};
    uint32_t reqd_len = 0;

    (void)memset(debug_resp_buf, 0, sizeof(debug_resp_buf));

    debug_cmd_buf[12] = count;
    debug_cmd_buf[13] = vht;
    debug_cmd_buf[14] = he;
    debug_cmd_buf[15] = rxNss;
    debug_cmd_buf[16] = channelWidth;
    debug_cmd_buf[17] = ulMuDisable;
    debug_cmd_buf[18] = txNSTS;
    debug_cmd_buf[19] = erSuDisable;
    debug_cmd_buf[20] = dlResoundRecomm;
    debug_cmd_buf[21] = ulMuDataDisable;

    ret = wlan_send_hostcmd(debug_cmd_buf, sizeof(debug_cmd_buf) / sizeof(uint8_t), debug_resp_buf, sizeof(debug_resp_buf),
                            &reqd_len);
    if (ret == WM_SUCCESS)
    {
        (void)PRINTF("Hostcmd success, response is\r\n");
        for (i = 0; i < reqd_len; i++)
            (void)PRINTF("%x\t", debug_resp_buf[i]);
    }
    else
    {
        (void)PRINTF("Hostcmd failed error: %d", ret);
    }
    return ret;
}
int wlan_set_11ax_tx_omi(const t_u8 interface, const t_u16 tx_omi, const t_u8 tx_option, const t_u8 num_data_pkts)
{
    if (interface == MLAN_BSS_TYPE_STA)
    {

        if (num_data_pkts > 16)
        {
            (void)PRINTF("Minimum value of num_data_pkts should be 1 and maximum should be 16");
            return -WM_FAIL;
        }

        if (is_sta_connected())
        {
            return wifi_set_11ax_tx_omi(MLAN_BSS_TYPE_STA, tx_omi, tx_option, num_data_pkts);
        }
        else
        {
            wifi_d("STA not connected");
            return -WM_FAIL;
        }
    }
    else if (interface == MLAN_BSS_TYPE_UAP)
    {
        if (is_uap_started())
        {
            return wifi_set_11ax_tx_omi(MLAN_BSS_TYPE_UAP, tx_omi, tx_option, num_data_pkts);
        }
        else
        {
            wifi_d("uAP not started");
            return -WM_FAIL;
        }
    }
    else
    {
        wifi_d("Interface not supported");
        return -WM_FAIL;
    }
}

int wlan_set_11ax_tol_time(const t_u32 tol_time)
{
    if (tol_time < 1 || tol_time > 3600)
    {
        wlcm_d("Error: invalid tolerance time value, range[[1..3600]].");
        return -WM_FAIL;
        ;
    }

    if (is_sta_connecting())
    {
        wlcm_d("Pls set OBSS Tolerance Time value before connecting to AP.");
        return -WM_FAIL;
    }

    return wifi_set_11ax_tol_time(tol_time);
}

int wlan_set_11ax_rutxpowerlimit(const void *rutx_pwr_cfg, uint32_t rutx_pwr_cfg_len)
{
    if (rutx_pwr_cfg != NULL)
    {
        return wifi_set_11ax_rutxpowerlimit(rutx_pwr_cfg, rutx_pwr_cfg_len);
    }

    return -WM_FAIL;
}


int wlan_set_11ax_rutxpowerlimit_legacy(const wifi_rutxpwrlimit_t *ru_pwr_cfg)
{
    if (ru_pwr_cfg != NULL)
    {
        return wifi_set_11ax_rutxpowerlimit_legacy(ru_pwr_cfg);
    }

    return -WM_FAIL;
}

int wlan_get_11ax_rutxpowerlimit_legacy(wifi_rutxpwrlimit_t *ru_pwr_cfg)
{
    if (ru_pwr_cfg != NULL)
    {
        (void)memset(ru_pwr_cfg, 0x00, sizeof(wlan_rutxpwrlimit_t));
        return wifi_get_11ax_rutxpowerlimit_legacy(ru_pwr_cfg);
    }

    return -WM_FAIL;
}

/* cfg tables for 11axcfg and twt commands to FW */
static uint8_t g_11ax_cfg_default[] = {
    /* band */
    0x03,
    /* HE cap */
    0xff, 0x00,                                                       // ID
    0x18, 0x00,                                                       // Length
    0x23,                                                             // he capability id
    0x03, 0x08, 0x00, 0x82, 0x00, 0x00,                               // HE MAC capability info
    0x40, 0x50, 0x42, 0x49, 0x0d, 0x00, 0x20, 0x1e, 0x17, 0x31, 0x00, // HE PHY capability info
    0xfd, 0xff, 0xfd, 0xff,                                           // Tx Rx HE-MCS NSS support
    0x88, 0x1f, 0x00, 0x00
};


int wlan_set_11ax_cfg(wlan_11ax_config_t *ax_config)
{
    return wifi_set_11ax_cfg(ax_config);
}

uint8_t * wlan_get_11ax_cfg()
{
    return g_11ax_cfg_default;
}

#ifdef CONFIG_11AX_TWT
static uint8_t g_btwt_cfg_default[] = {/* action */
                               0x01, 0x00,
                               /* sub_id */
                               0x25, 0x01,
                               /* btwt_cfg */
                               0x40, 0x04, 0x63, 0x00, 0x70, 0x02, 0x0a, 0x05};

int wlan_set_btwt_cfg(const wlan_btwt_config_t *btwt_config)
{
    return wifi_set_btwt_cfg(btwt_config);
}

uint8_t * wlan_get_btwt_cfg()
{
    return g_btwt_cfg_default;
}

static uint8_t g_twt_setup_cfg_default[] = {0x01, 0x00, 0x00, 0x01, 0x00, 0x40, 0x00, 0x01, 0x0a, 0x00, 0x02, 0x00};

/* Below macros are defined as in FW under dot11ax_twt.c */
#define TWT_EARLY_WAKEUP_ADJUSTMENT 1000                                // us
#define TWT_SLEEP_MIN               (756 + TWT_EARLY_WAKEUP_ADJUSTMENT) // us
int wlan_set_twt_setup_cfg(const wlan_twt_setup_config_t *twt_setup)
{
    if (((twt_setup->twt_mantissa << twt_setup->twt_exponent) - (twt_setup->twt_wakeup_duration * 256)) < TWT_SLEEP_MIN)
    {
        wlcm_e("Service period (SP) value is : %u us", twt_setup->twt_mantissa << twt_setup->twt_exponent);
        wlcm_e("Wakeup duration (WD) value is : %u us", twt_setup->twt_wakeup_duration * 256);
        wlcm_e("Minimum sleep time (SP - WD) should be greater than: %u us", TWT_SLEEP_MIN);
        return -WM_FAIL;
    }
    return wifi_set_twt_setup_cfg(twt_setup);
}

uint8_t * wlan_get_twt_setup_cfg()
{
    return g_twt_setup_cfg_default;
}

static uint8_t g_twt_teardown_cfg_default[] = {0x00, 0x00, 0x00};

int wlan_set_twt_teardown_cfg(const wlan_twt_teardown_config_t *teardown_config)
{
    return wifi_set_twt_teardown_cfg(teardown_config);
}

uint8_t * wlan_get_twt_teardown_cfg()
{
    return g_twt_teardown_cfg_default;
}

int wlan_get_twt_report(wlan_twt_report_t *twt_report)
{
    return wifi_get_twt_report(twt_report);
}
#endif /* CONFIG_11AX_TWT */
#endif /* CONFIG_11AX */

#ifdef CONFIG_WIFI_CLOCKSYNC
int wlan_get_tsf_info(wlan_tsf_info_t *tsf_info)
{
    return wifi_get_tsf_info(tsf_info);
}
int wlan_set_clocksync_cfg(const wlan_clock_sync_gpio_tsf_t *tsf_latch)
{
    return wifi_set_clocksync_cfg(tsf_latch, (mlan_bss_type)WLAN_BSS_TYPE_STA);
}
#endif /* CONFIG_WIFI_CLOCKSYNC */

#ifdef CONFIG_WIFI_EU_CRYPTO
int wlan_set_crypto_RC4_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 rc4_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 rc4_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 rc4_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > rc4_key_length)
        return -WM_FAIL;
    if (KeyIVLength > rc4_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > rc4_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_RC4_Param;
    Crypto_RC4_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_RC4_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_RC4_Param.KeyLength = KeyLength;
    memcpy(Crypto_RC4_Param.Key, Key, KeyLength);
    Crypto_RC4_Param.DataLength = DataLength;
    Crypto_RC4_Param.Data       = Data;

    t_u16 EncDec = 1;

    return wifi_set_eu_crypto(&Crypto_RC4_Param, CRYPTO_RC4, EncDec);
}

int wlan_set_crypto_RC4_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 rc4_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 rc4_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 rc4_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > rc4_key_length)
        return -WM_FAIL;
    if (KeyIVLength > rc4_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > rc4_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_RC4_Param;
    Crypto_RC4_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_RC4_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_RC4_Param.KeyLength = KeyLength;
    memcpy(Crypto_RC4_Param.Key, Key, KeyLength);
    Crypto_RC4_Param.DataLength = DataLength;
    Crypto_RC4_Param.Data       = Data;

    t_u16 EncDec = 0;

    return wifi_set_eu_crypto(&Crypto_RC4_Param, CRYPTO_RC4, EncDec);
}

int wlan_set_crypto_AES_ECB_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 aes_ecb_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_ecb_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 aes_ecb_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > aes_ecb_key_length)
        return -WM_FAIL;
    if (KeyIVLength > aes_ecb_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > aes_ecb_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_ECB_Param;
    Crypto_AES_ECB_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_AES_ECB_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_AES_ECB_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_ECB_Param.Key, Key, KeyLength);
    Crypto_AES_ECB_Param.DataLength = DataLength;
    Crypto_AES_ECB_Param.Data       = Data;

    t_u16 EncDec = 1;

    return wifi_set_eu_crypto(&Crypto_AES_ECB_Param, CRYPTO_AES_ECB, EncDec);
}

int wlan_set_crypto_AES_ECB_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 aes_ecb_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_ecb_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 aes_ecb_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > aes_ecb_key_length)
        return -WM_FAIL;
    if (KeyIVLength > aes_ecb_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > aes_ecb_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_ECB_Param;
    Crypto_AES_ECB_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_AES_ECB_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_AES_ECB_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_ECB_Param.Key, Key, KeyLength);
    Crypto_AES_ECB_Param.DataLength = DataLength;
    Crypto_AES_ECB_Param.Data       = Data;

    t_u16 EncDec = 0;

    return wifi_set_eu_crypto(&Crypto_AES_ECB_Param, CRYPTO_AES_ECB, EncDec);
}

int wlan_set_crypto_AES_WRAP_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 aes_wrap_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_wrap_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 aes_wrap_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > aes_wrap_key_length)
        return -WM_FAIL;
    if (KeyIVLength > aes_wrap_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > aes_wrap_data_length)
        return -WM_FAIL;

    EU_Crypto Crypto_AES_WRAP_Param;
    Crypto_AES_WRAP_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_AES_WRAP_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_AES_WRAP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_WRAP_Param.Key, Key, KeyLength);
    Crypto_AES_WRAP_Param.DataLength = DataLength;
    Crypto_AES_WRAP_Param.Data       = Data;

    t_u16 EncDec = 1;

    return wifi_set_eu_crypto(&Crypto_AES_WRAP_Param, CRYPTO_AES_WRAP, EncDec);
}

int wlan_set_crypto_AES_WRAP_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength)
{
    t_u16 aes_wrap_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_wrap_keyiv_length = EU_CRYPTO_KEYIV_MAX_LENGTH;
    t_u16 aes_wrap_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

    if (KeyLength > aes_wrap_key_length)
        return -WM_FAIL;
    if (KeyIVLength > aes_wrap_keyiv_length)
        return -WM_FAIL;
    if (*DataLength > aes_wrap_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_WRAP_Param;
    Crypto_AES_WRAP_Param.KeyIVLength = KeyIVLength;
    memcpy(Crypto_AES_WRAP_Param.KeyIV, KeyIV, KeyIVLength);
    Crypto_AES_WRAP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_WRAP_Param.Key, Key, KeyLength);
    Crypto_AES_WRAP_Param.DataLength = DataLength;
    Crypto_AES_WRAP_Param.Data       = Data;

    t_u16 EncDec = 0;

    return wifi_set_eu_crypto(&Crypto_AES_WRAP_Param, CRYPTO_AES_WRAP, EncDec);
}

int wlan_set_crypto_AES_CCMP_encrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength)
{
    t_u16 aes_ccmp_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_ccmp_AAD_length   = EU_CRYPTO_AAD_MAX_LENGTH;
    t_u16 aes_ccmp_Nonce_length = EU_CRYPTO_NONCE_MAX_LENGTH;
    t_u16 aes_ccmp_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif
#if defined(SD8978)
    if (KeyLength == aes_ccmp_key_length)
    {
        return -WM_E_PERM;
    }
#endif

    if (KeyLength > aes_ccmp_key_length)
        return -WM_FAIL;
    if (AADLength > aes_ccmp_AAD_length)
        return -WM_FAIL;
    if (NonceLength > aes_ccmp_Nonce_length)
        return -WM_FAIL;
    if (*DataLength > aes_ccmp_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_CCMP_Param;
    Crypto_AES_CCMP_Param.AADLength = AADLength;
    memcpy(Crypto_AES_CCMP_Param.AAD, AAD, AADLength);
    Crypto_AES_CCMP_Param.NonceLength = NonceLength;
    memcpy(Crypto_AES_CCMP_Param.Nonce, Nonce, NonceLength);
    Crypto_AES_CCMP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_CCMP_Param.Key, Key, KeyLength);
    Crypto_AES_CCMP_Param.DataLength = DataLength;
    Crypto_AES_CCMP_Param.Data       = Data;

    t_u16 EncDec = 1;

    return wifi_set_eu_crypto(&Crypto_AES_CCMP_Param, CRYPTO_AES_CCMP, EncDec);
}

int wlan_set_crypto_AES_CCMP_decrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength)
{
    t_u16 aes_ccmp_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_ccmp_AAD_length   = EU_CRYPTO_AAD_MAX_LENGTH;
    t_u16 aes_ccmp_Nonce_length = EU_CRYPTO_NONCE_MAX_LENGTH;
    t_u16 aes_ccmp_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

#if defined(SD8801)
    return -WM_E_PERM;
#endif

#if defined(SD8978)
    if (KeyLength == aes_ccmp_key_length)
    {
        return -WM_E_PERM;
    }
#endif

    if (KeyLength > aes_ccmp_key_length)
        return -WM_FAIL;
    if (AADLength > aes_ccmp_AAD_length)
        return -WM_FAIL;
    if (NonceLength > aes_ccmp_Nonce_length)
        return -WM_FAIL;
    if (*DataLength > aes_ccmp_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_CCMP_Param;
    Crypto_AES_CCMP_Param.AADLength = AADLength;
    memcpy(Crypto_AES_CCMP_Param.AAD, AAD, AADLength);
    Crypto_AES_CCMP_Param.NonceLength = NonceLength;
    memcpy(Crypto_AES_CCMP_Param.Nonce, Nonce, NonceLength);
    Crypto_AES_CCMP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_CCMP_Param.Key, Key, KeyLength);
    Crypto_AES_CCMP_Param.DataLength = DataLength;
    Crypto_AES_CCMP_Param.Data       = Data;

    t_u16 EncDec = 0;

    return wifi_set_eu_crypto(&Crypto_AES_CCMP_Param, CRYPTO_AES_CCMP, EncDec);
}

int wlan_set_crypto_AES_GCMP_encrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength)
{
#if defined(SD8801) || defined(SD8978)
    return -WM_E_PERM;
#else
    t_u16 aes_gcmp_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_gcmp_AAD_length   = EU_CRYPTO_AAD_MAX_LENGTH;
    t_u16 aes_gcmp_Nonce_length = EU_CRYPTO_NONCE_MAX_LENGTH;
    t_u16 aes_gcmp_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

    if (KeyLength > aes_gcmp_key_length)
        return -WM_FAIL;
    if (AADLength > aes_gcmp_AAD_length)
        return -WM_FAIL;
    if (NonceLength > aes_gcmp_Nonce_length)
        return -WM_FAIL;
    if (*DataLength > aes_gcmp_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_GCMP_Param;
    Crypto_AES_GCMP_Param.AADLength = AADLength;
    memcpy(Crypto_AES_GCMP_Param.AAD, AAD, AADLength);
    Crypto_AES_GCMP_Param.NonceLength = NonceLength;
    memcpy(Crypto_AES_GCMP_Param.Nonce, Nonce, NonceLength);
    Crypto_AES_GCMP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_GCMP_Param.Key, Key, KeyLength);
    Crypto_AES_GCMP_Param.DataLength = DataLength;
    Crypto_AES_GCMP_Param.Data       = Data;

    t_u16 EncDec = 1;

    return wifi_set_eu_crypto(&Crypto_AES_GCMP_Param, CRYPTO_AES_GCMP, EncDec);
#endif
}

int wlan_set_crypto_AES_GCMP_decrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength)
{
#if defined(SD8801) || defined(SD8978)
    return -WM_E_PERM;
#else
    t_u16 aes_gcmp_key_length   = EU_CRYPTO_KEY_MAX_LENGTH;
    t_u16 aes_gcmp_AAD_length   = EU_CRYPTO_AAD_MAX_LENGTH;
    t_u16 aes_gcmp_Nonce_length = EU_CRYPTO_NONCE_MAX_LENGTH;
    t_u16 aes_gcmp_data_length  = EU_CRYPTO_DATA_MAX_LENGTH;

    if (KeyLength > aes_gcmp_key_length)
        return -WM_FAIL;
    if (AADLength > aes_gcmp_AAD_length)
        return -WM_FAIL;
    if (NonceLength > aes_gcmp_Nonce_length)
        return -WM_FAIL;
    if (*DataLength > aes_gcmp_data_length)
        return -WM_FAIL;
    EU_Crypto Crypto_AES_GCMP_Param;
    Crypto_AES_GCMP_Param.AADLength = AADLength;
    memcpy(Crypto_AES_GCMP_Param.AAD, AAD, AADLength);
    Crypto_AES_GCMP_Param.NonceLength = NonceLength;
    memcpy(Crypto_AES_GCMP_Param.Nonce, Nonce, NonceLength);
    Crypto_AES_GCMP_Param.KeyLength = KeyLength;
    memcpy(Crypto_AES_GCMP_Param.Key, Key, KeyLength);
    Crypto_AES_GCMP_Param.DataLength = DataLength;
    Crypto_AES_GCMP_Param.Data       = Data;

    t_u16 EncDec = 0;

    return wifi_set_eu_crypto(&Crypto_AES_GCMP_Param, CRYPTO_AES_GCMP, EncDec);
#endif
}
#endif /* CONFIG_WIFI_EU_CRYPTO */

#ifdef CONFIG_HEAP_DEBUG
void wlan_show_os_mem_stat()
{
    wifi_show_os_mem_stat();
}
#endif

#ifdef CONFIG_MULTI_CHAN
int wlan_set_multi_chan_status(const int status)
{
    return wifi_set_mc_policy(status);
}

int wlan_get_multi_chan_status(int *status)
{
    (*status) = wifi_get_mc_policy();
    return WM_SUCCESS;
}

int wlan_set_drcs_cfg(const wlan_drcs_cfg_t *drcs_cfg, const int num)
{
    return wifi_set_mc_cfg_ext((wifi_drcs_cfg_t *)drcs_cfg, num);
}

int wlan_get_drcs_cfg(wlan_drcs_cfg_t *drcs_cfg, int num)
{
    return wifi_get_mc_cfg_ext((wifi_drcs_cfg_t *)drcs_cfg, num);
}
#endif

#ifdef CONFIG_WPS2
void wlan_set_prov_session(int session)
{
    prov_session_attempt = session;
    wps_conf.prov_session = session;
}

int wlan_get_prov_session(void)
{
    return prov_session_attempt;
}
#endif


#ifdef CONFIG_ECSA

int wlan_uap_set_ecsa_cfg(t_u8 block_tx, t_u8 oper_class, t_u8 channel, t_u8 switch_count, t_u8 band_width)
{
    t_u8 ecsa = MFALSE;
    int ret   = 0;

    ret = wlan_set_uap_ecsa_cfg(block_tx, oper_class, channel, switch_count, band_width, ecsa);

    return ret;
}

#endif
#ifdef CONFIG_11AX
#ifdef CONFIG_MMSF
int wlan_set_mmsf(const t_u8 enable, const t_u8 Density, const t_u8 MMSF)
{
    return wifi_mmsf_cfg(ACTION_SET, (t_u8 *)&enable, (t_u8 *)&Density, (t_u8 *)&MMSF);
}

int wlan_get_mmsf(t_u8 *enable, t_u8 *Density, t_u8 *MMSF)
{
    return wifi_mmsf_cfg(ACTION_GET, enable, Density, MMSF);
}
#endif
#endif
#ifdef CONFIG_SUBSCRIBE_EVENT_SUPPORT
/**
 *  @brief This function subscribe event to firmware.
 *
 *  @param sbitmap    A pointer to specific event from user.
 *  @param thresh_value     A pointer to value from user.
 *  @param freq      A pointer to freq from user.
 *
 *  @return             MLAN_STATUS_SUCCESS, MLAN_STATUS_FAILURE or WM_E_INVAL
 */
int wlan_set_subscribe_event(unsigned int event_id, unsigned int thresh_value, unsigned int freq)
{
    int ret = WM_E_INVAL;
    switch (event_id)
    {
        case EVENT_SUB_RSSI_LOW:
            ret = wifi_set_threshold_rssi_low(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_RSSI_HIGH:
            ret = wifi_set_threshold_rssi_high(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_SNR_LOW:
            ret = wifi_set_threshold_snr_low(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_SNR_HIGH:
            ret = wifi_set_threshold_snr_high(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_MAX_FAIL:
            ret = wifi_set_threshold_max_fail(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_BEACON_MISSED:
            ret = wifi_set_threshold_beacon_miss(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_DATA_RSSI_LOW:
            ret = wifi_set_threshold_data_rssi_low(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_DATA_RSSI_HIGH:
            ret = wifi_set_threshold_data_rssi_high(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_DATA_SNR_LOW:
            ret = wifi_set_threshold_data_snr_low(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_DATA_SNR_HIGH:
            ret = wifi_set_threshold_data_snr_high(mlan_adap->priv[0], thresh_value, freq);
            break;
        case EVENT_SUB_PRE_BEACON_LOST:
            ret = wifi_set_threshold_pre_beacon_lost(mlan_adap->priv[0], thresh_value, freq);
            break;
        default:
            ret = WM_E_INVAL;
            break;
    }
    return ret;
}

int wlan_get_subscribe_event(wlan_ds_subscribe_evt *sub_evt)
{
    int ret = WM_E_INVAL;
    mlan_ds_subscribe_evt msub_evt;
    memset(&msub_evt, 0, sizeof(msub_evt));
    ret = wifi_get_subscribe_event(mlan_adap->priv[0], &msub_evt);
    memcpy((t_u8 *)sub_evt, (t_u8 *)&msub_evt.evt_bitmap, sizeof(wlan_ds_subscribe_evt));
    return ret;
}

int wlan_clear_subscribe_event(unsigned int event_id)
{
    /*bitmap parameter analyse*/
    int evt_bitmap = 0;
    switch (event_id)
    {
        case EVENT_SUB_RSSI_LOW:
            evt_bitmap = SUBSCRIBE_EVT_RSSI_LOW;
            break;
        case EVENT_SUB_RSSI_HIGH:
            evt_bitmap = SUBSCRIBE_EVT_RSSI_HIGH;
            break;
        case EVENT_SUB_SNR_LOW:
            evt_bitmap = SUBSCRIBE_EVT_SNR_LOW;
            break;
        case EVENT_SUB_SNR_HIGH:
            evt_bitmap = SUBSCRIBE_EVT_SNR_HIGH;
            break;
        case EVENT_SUB_MAX_FAIL:
            evt_bitmap = SUBSCRIBE_EVT_MAX_FAIL;
            break;
        case EVENT_SUB_BEACON_MISSED:
            evt_bitmap = SUBSCRIBE_EVT_BEACON_MISSED;
            break;
        case EVENT_SUB_DATA_RSSI_LOW:
            evt_bitmap = SUBSCRIBE_EVT_DATA_RSSI_LOW;
            break;
        case EVENT_SUB_DATA_RSSI_HIGH:
            evt_bitmap = SUBSCRIBE_EVT_DATA_RSSI_HIGH;
            break;
        case EVENT_SUB_DATA_SNR_LOW:
            evt_bitmap = SUBSCRIBE_EVT_DATA_SNR_LOW;
            break;
        case EVENT_SUB_DATA_SNR_HIGH:
            evt_bitmap = SUBSCRIBE_EVT_DATA_SNR_HIGH;
            break;
        case EVENT_SUB_LINK_QUALITY:
            evt_bitmap = SUBSCRIBE_EVT_LINK_QUALITY;
            break;
        case EVENT_SUB_PRE_BEACON_LOST:
            evt_bitmap = SUBSCRIBE_EVT_PRE_BEACON_LOST;
            break;
        default:
            return WM_E_INVAL;
            break;
    }
    return wifi_clear_subscribe_event(mlan_adap->priv[0], evt_bitmap);
}

int wlan_set_threshold_link_quality(unsigned int event_id,
                                    unsigned int link_snr,
                                    unsigned int link_snr_freq,
                                    unsigned int link_rate,
                                    unsigned int link_rate_freq,
                                    unsigned int link_tx_latency,
                                    unsigned int link_tx_lantency_freq)
{
    if (event_id == EVENT_SUB_LINK_QUALITY)
        return wifi_set_threshold_link_quality(mlan_adap->priv[0], link_snr, link_snr_freq, link_rate, link_rate_freq,
                                               link_tx_latency, link_tx_lantency_freq);
    return WM_E_INVAL;
}
#endif

#ifdef CONFIG_WIFI_REG_ACCESS
int wlan_reg_access(wifi_reg_t type, uint16_t action, uint32_t offset, uint32_t *value)
{
    return wifi_reg_access(type, action, offset, value);
}
#endif

#ifdef CONFIG_WMM_UAPSD
static t_u8 uapsd_qos_info             = WMM_UAPSD_QOS_INFO;
static unsigned int uapsd_sleep_period = WMM_UAPSD_SLEEP_PERIOD;
int wlan_wmm_uapsd_qosinfo(t_u8 *qos_info, t_u8 action)
{
    int ret = WM_SUCCESS;

    ret = wifi_wmm_qos_cfg(qos_info, action);
    if (ret == WM_SUCCESS && action == ACTION_SET)
        uapsd_qos_info = *qos_info;

    return ret;
}

int wlan_set_wmm_uapsd(t_u8 uapsd_enable)
{

    if (!is_uap_state(CM_UAP_INITIALIZING) || is_sta_connecting())
    {
        (void)PRINTF("Failed to enable/disable UAPSD, because uAP is up/STA is connecting\n");
        return -WM_FAIL;
    }

    if (uapsd_enable)
    {
        (void)wifi_wmm_qos_cfg(&uapsd_qos_info, 1);
        (void)wifi_sleep_period(&uapsd_sleep_period, 1);
    }
    else
    {
        t_u8 qos_info       = 0;
        unsigned int period = 0;
        (void)wifi_wmm_qos_cfg(&qos_info, 1);
        (void)wifi_sleep_period(&period, 1);
        (void)wlan_ieeeps_off();
    }
	return WM_SUCCESS;
}
int wlan_sleep_period(unsigned int *sleep_period, t_u8 action)
{
    int ret = WM_SUCCESS;

    ret = wifi_sleep_period(sleep_period, action);
    if (ret == WM_SUCCESS && action == ACTION_SET)
        uapsd_sleep_period = *sleep_period;

    return ret;
}

t_u8 wlan_is_wmm_uapsd_enabled(void)
{
    return (mlan_adap ? mlan_adap->pps_uapsd_mode : false);
}
#endif

int wlan_tx_ampdu_prot_mode(tx_ampdu_prot_mode_para *prot_mode, t_u16 action)
{
    return wifi_tx_ampdu_prot_mode(prot_mode, action);
}

int wlan_mef_set_auto_arp(t_u8 mef_action)
{
    int ret, index;
    unsigned int ipv4_addr[2];
    int ipv4_addr_num = 0;
    int filter_num = 0;

    if(!is_sta_ipv4_connected() && !is_uap_started())
    {
        wlcm_e("No connection on STA and uAP is not activated.");
        wlcm_e("Should at least meet one condition.");
        return -WM_E_PERM;
    }

    if (g_flt_cfg.nentries >= MAX_NUM_ENTRIES)
    {
        wlcm_e("Number of MEF entries(%d) exceeds limit(8)!", g_flt_cfg.nentries);
        return -WM_FAIL;
    }

    (void)memset(ipv4_addr, 0x0, sizeof(ipv4_addr));
    if(is_sta_ipv4_connected() != 0)
    {
        ret = wlan_get_ipv4_addr(&ipv4_addr[0]);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("Cannot get STA IP");
            return -WM_FAIL;
        }
        ipv4_addr_num++;
    }
    if(is_uap_started() != 0)
    {
        ret = wlan_get_uap_ipv4_addr(&ipv4_addr[1]);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("Cannot get UAP IP");
            return -WM_FAIL;
        }
        ipv4_addr_num++;
    }
    index = g_flt_cfg.nentries;
    g_flt_cfg.criteria |= (CRITERIA_BROADCAST | CRITERIA_UNICAST);
    g_flt_cfg.nentries++;

    g_flt_cfg.mef_entry[index].mode                        = MEF_MODE_HOST_SLEEP;
    g_flt_cfg.mef_entry[index].action                      = (MEF_AUTO_ARP | (mef_action & 0xF));
    g_flt_cfg.mef_entry[index].filter_num                  = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].type         = TYPE_BYTE_EQ;
    g_flt_cfg.mef_entry[index].filter_item[0].repeat       = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].offset       = IPV4_PKT_OFFSET;
    g_flt_cfg.mef_entry[index].filter_item[0].num_byte_seq = 2;
    (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[0].byte_seq, "\x08\x06", 2);
    g_flt_cfg.mef_entry[index].rpn[1] = RPN_TYPE_AND;

    if(is_sta_ipv4_connected() != 0)
    {
        g_flt_cfg.mef_entry[index].filter_num++;
        filter_num = g_flt_cfg.mef_entry[index].filter_num;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].type         = TYPE_BYTE_EQ;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].repeat       = 1;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].offset       = 46;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].num_byte_seq = 4;
        (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].byte_seq,
                     &ipv4_addr[0], 4); // STA IP address
    }

    if(is_uap_started() != 0)
    {
        g_flt_cfg.mef_entry[index].filter_num++;
        filter_num = g_flt_cfg.mef_entry[index].filter_num;
        if(ipv4_addr_num == 2)
            g_flt_cfg.mef_entry[index].rpn[filter_num] = RPN_TYPE_OR;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].type         = TYPE_BYTE_EQ;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].repeat       = 1;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].offset       = 46;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].num_byte_seq = 4;
        (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].byte_seq,
                     &ipv4_addr[1], 4); // UAP IP address
    }

    return WM_SUCCESS;
}

int wlan_mef_set_auto_ping(t_u8 mef_action)
{
    int ret, index;
    unsigned int ipv4_addr[2];
    int ipv4_addr_num = 0;
    int filter_num = 0;

    if(!is_sta_ipv4_connected() && !is_uap_started())
    {
        wlcm_e("No connection on STA and uAP is not activated.");
        wlcm_e("Should at least meet one condition.");
        return -WM_E_PERM;
    }

    if (g_flt_cfg.nentries >= MAX_NUM_ENTRIES)
    {
        wlcm_e("Number of MEF entries(%d) exceeds limit(8)!", g_flt_cfg.nentries);
        return -WM_FAIL;
    }

    (void)memset(ipv4_addr, 0x0, sizeof(ipv4_addr));
    if(is_sta_ipv4_connected() != 0)
    {
        ret = wlan_get_ipv4_addr(&ipv4_addr[0]);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("Cannot get STA IP");
            return -WM_FAIL;
        }
        ipv4_addr_num++;
    }
    if(is_uap_started() != 0)
    {
        ret = wlan_get_uap_ipv4_addr(&ipv4_addr[1]);
        if (ret != WM_SUCCESS)
        {
            wlcm_e("Cannot get UAP IP");
            return -WM_FAIL;
        }
        ipv4_addr_num++;
    }
    index = g_flt_cfg.nentries;
    g_flt_cfg.criteria |= (CRITERIA_BROADCAST | CRITERIA_UNICAST);
    g_flt_cfg.nentries++;
    g_flt_cfg.mef_entry[index].mode                        = MEF_MODE_HOST_SLEEP;
    g_flt_cfg.mef_entry[index].action                      = (MEF_AUTO_PING | (mef_action & 0xF));
    g_flt_cfg.mef_entry[index].filter_num                  = 2;
    g_flt_cfg.mef_entry[index].filter_item[0].type         = TYPE_BYTE_EQ;
    g_flt_cfg.mef_entry[index].filter_item[0].repeat       = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].offset       = IPV4_PKT_OFFSET;
    g_flt_cfg.mef_entry[index].filter_item[0].num_byte_seq = 2;
    (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[0].byte_seq, "\x08\x00", 2);
    g_flt_cfg.mef_entry[index].rpn[1] = RPN_TYPE_AND;

    g_flt_cfg.mef_entry[index].filter_item[1].type      = TYPE_DNUM_EQ;
    g_flt_cfg.mef_entry[index].filter_item[1].pattern   = ICMP_OF_IP_PROTOCOL;
    g_flt_cfg.mef_entry[index].filter_item[1].offset    = IP_PROTOCOL_OFFSET;
    g_flt_cfg.mef_entry[index].filter_item[1].num_bytes = 1;
    g_flt_cfg.mef_entry[index].rpn[2]                   = RPN_TYPE_AND;

    if(is_sta_ipv4_connected() != 0)
    {
        g_flt_cfg.mef_entry[index].filter_num++;
        filter_num = g_flt_cfg.mef_entry[index].filter_num;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].type         = TYPE_BYTE_EQ;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].repeat       = 1;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].offset       = 38;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].num_byte_seq = 4;
        (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].byte_seq,
                     &ipv4_addr[0], 4); //STA IP address
    }

    if(is_uap_started() != 0)
    {
        g_flt_cfg.mef_entry[index].filter_num++;
        filter_num = g_flt_cfg.mef_entry[index].filter_num;
        if(ipv4_addr_num == 2)
            g_flt_cfg.mef_entry[index].rpn[filter_num - 1] = RPN_TYPE_OR;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].type         = TYPE_BYTE_EQ;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].repeat       = 1;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].offset       = 38;
        g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].num_byte_seq = 4;
        (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[filter_num - 1].byte_seq,
                     &ipv4_addr[1], 4); // UAP IP address
    }

    return WM_SUCCESS;
}

int wlan_set_ipv6_ns_mef(t_u8 mef_action)
{
	int index;

    if (g_flt_cfg.nentries >= MAX_NUM_ENTRIES)
    {
        wlcm_e("Number of MEF entries(%d) exceeds limit(8)!", g_flt_cfg.nentries);
        return -WM_FAIL;
    }

    index = g_flt_cfg.nentries;
    g_flt_cfg.criteria |= (CRITERIA_UNICAST | CRITERIA_MULTICAST);
    g_flt_cfg.nentries++;
    g_flt_cfg.mef_entry[index].mode = MEF_MODE_HOST_SLEEP;
    g_flt_cfg.mef_entry[index].action = (MEF_NS_RESP| (mef_action & 0xF));
    g_flt_cfg.mef_entry[index].filter_num = 2;

	g_flt_cfg.mef_entry[index].filter_item[0].fill_flag = (FILLING_TYPE | FILLING_REPEAT | FILLING_OFFSET | FILLING_BYTE_SEQ);
    g_flt_cfg.mef_entry[index].filter_item[0].type         = TYPE_BYTE_EQ;
    g_flt_cfg.mef_entry[index].filter_item[0].repeat       = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].offset       = IPV4_PKT_OFFSET;
    g_flt_cfg.mef_entry[index].filter_item[0].num_byte_seq = 2;
    (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[0].byte_seq, "\x86\xdd", 2);
    g_flt_cfg.mef_entry[index].rpn[1] = RPN_TYPE_AND;

	g_flt_cfg.mef_entry[index].filter_item[1].fill_flag = (FILLING_TYPE | FILLING_REPEAT | FILLING_OFFSET | FILLING_BYTE_SEQ);
    g_flt_cfg.mef_entry[index].filter_item[1].type         = TYPE_BYTE_EQ;
    g_flt_cfg.mef_entry[index].filter_item[1].repeat       = 1;
    g_flt_cfg.mef_entry[index].filter_item[1].offset       = 62;
    g_flt_cfg.mef_entry[index].filter_item[1].num_byte_seq = 1;
    (void)memcpy(g_flt_cfg.mef_entry[index].filter_item[1].byte_seq, "\x87", 1);

    return WM_SUCCESS;
}

int wlan_mef_set_multicast(t_u8 mef_action)
{
    t_u32 index = 0;

    if (g_flt_cfg.nentries >= MAX_NUM_ENTRIES)
    {
        wlcm_e("Number of MEF entries(%d) exceeds limit(8)!", g_flt_cfg.nentries);
        return -WM_FAIL;
    }
    index = g_flt_cfg.nentries;
    g_flt_cfg.criteria |= (CRITERIA_MULTICAST | CRITERIA_UNICAST);
    g_flt_cfg.nentries++;

    g_flt_cfg.mef_entry[index].mode                        = MEF_MODE_HOST_SLEEP;
    g_flt_cfg.mef_entry[index].action                      = mef_action;
    g_flt_cfg.mef_entry[index].filter_num                  = 2;
    g_flt_cfg.mef_entry[index].filter_item[0].type         = TYPE_BIT_EQ;
    g_flt_cfg.mef_entry[index].filter_item[0].offset       = 0;
    g_flt_cfg.mef_entry[index].filter_item[0].num_byte_seq = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].byte_seq[0]  = 0x01;
    g_flt_cfg.mef_entry[index].filter_item[0].num_mask_seq = 1;
    g_flt_cfg.mef_entry[index].filter_item[0].mask_seq[0]  = 0x01;
    g_flt_cfg.mef_entry[index].rpn[1]                      = RPN_TYPE_OR;

    g_flt_cfg.mef_entry[index].filter_item[1].type         = TYPE_BIT_EQ;
    g_flt_cfg.mef_entry[index].filter_item[1].offset       = 38;
    g_flt_cfg.mef_entry[index].filter_item[1].num_byte_seq = 1;
    g_flt_cfg.mef_entry[index].filter_item[1].byte_seq[0]  = 0xE0;
    g_flt_cfg.mef_entry[index].filter_item[1].num_mask_seq = 1;
    g_flt_cfg.mef_entry[index].filter_item[1].mask_seq[0]  = 0xF0;

    return WM_SUCCESS;
}

int wlan_config_mef(int type, t_u8 mef_action)
{
    int ret = -WM_FAIL;

    if (!wlan_is_started())
    {
        (void)PRINTF("MEF configure is not allowed when WIFI is disabled\r\n");
        return -WM_FAIL;
    }

    switch (type)
    {
        case MEF_TYPE_DELETE:
            (void)memset(&g_flt_cfg, 0, sizeof(wlan_flt_cfg_t));
            ret = wifi_set_packet_filters(&g_flt_cfg);
            if(ret == WM_SUCCESS)
                (void)PRINTF("delete all MEF entries Successful\n\r");
            else
                (void)PRINTF("delete all MEF entries Failed\n\r");
            break;
        case MEF_TYPE_PING:
            ret = wlan_mef_set_auto_ping(mef_action);
            if (ret == WM_SUCCESS)
                (void)PRINTF("Add ping MEF entry successful\n\r");
            else
                (void)PRINTF("Add ping MEF entry Failed\n\r");
            break;
        case MEF_TYPE_ARP:
            ret = wlan_mef_set_auto_arp(mef_action);
            if (ret == WM_SUCCESS)
            {
                (void)PRINTF("Add ARP MEF entry successful\n\r");
            }
            else
                (void)PRINTF("Add ARP MEF entry Failed\n\r");
            break;
        case MEF_TYPE_MULTICAST:
            ret = wlan_mef_set_multicast(mef_action);
            if (ret == WM_SUCCESS)
                (void)PRINTF("Add multicast MEF entry successful\n\r");
            else
                (void)PRINTF("Add multicast MEF entry Failed\n\r");
            break;
        case MEF_TYPE_IPV6_NS:
            ret = wlan_set_ipv6_ns_mef(mef_action);
            if (ret == WM_SUCCESS)
                (void)PRINTF("Add ns MEF entry successful\n\r");
            else
                (void)PRINTF("Add ns MEF entry Failed\n\r");
            break;
        default:
            (void)PRINTF("Error: unknown MEF type:%d", type);
            break;
    }

    return ret;
}

#ifdef CONFIG_CSI
int wlan_register_csi_user_callback(int (*csi_data_recv_callback)(void *buffer, size_t len))
{
    return register_csi_user_callback(csi_data_recv_callback);
}

int wlan_unregister_csi_user_callback(void)
{
    return unregister_csi_user_callback();
}

int wlan_csi_cfg(wlan_csi_config_params_t *csi_params)
{
    int ret = WM_SUCCESS;

    if (csi_params->csi_enable == 1)
    {
        csi_local_buff_init();
    }
    else
    {
        ret = unregister_csi_user_callback();
    }

    ret = wifi_csi_cfg(csi_params);

    return ret;
}
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
void wlan_set_rssi_low_threshold(uint8_t threshold)
{
    wlan.rssi_low_threshold = threshold;

    if (is_sta_connected())
    {
#ifdef CONFIG_ROAMING
        if (wlan.roaming_enabled == true)
        {
            (void)wifi_config_roaming(true, &wlan.rssi_low_threshold);
        }
        else
#endif
        {
            (void)wifi_set_rssi_low_threshold(&wlan.rssi_low_threshold);
        }
    }
}
#endif

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_WPS
static int wlan_remove_wps_network(void)
{
    unsigned int len, i;
    int ret = -WM_E_INVAL;
    struct netif *netif = net_get_sta_interface();

    ret = wpa_supp_cancel_scan(netif);
    /* find the first network whose name matches and clear it out */
    for (i = 0; i < ARRAY_SIZE(wlan.networks); i++)
    {
        if (wlan.networks[i].wps_network)
            ret = wpa_supp_remove_network(netif, &wlan.networks[i]);
    }
    return ret;
}

int wlan_start_wps_pbc(void)
{
    int ret = -WM_FAIL;
    struct netif *netif = net_get_sta_interface();

    if (wlan.wps_session_attempt)
    {
        wlcm_d("WPS session is already in progress");
        return ret;
    }
    wlan_remove_wps_network();
    ret = wpa_supp_start_wps_pbc(netif, 0);

    if (ret == -2)
    {
        wlcm_e("WPS PBC overlap detected");
    }
    return ret;
}

void wlan_wps_generate_pin(uint32_t *pin)
{
    struct netif *netif = net_get_sta_interface();

    wpa_supp_wps_generate_pin(netif, (unsigned int *)pin);
}

int wlan_start_wps_pin(const char *pin)
{
    struct netif *netif = net_get_sta_interface();

    if (wlan.wps_session_attempt)
    {
        wlcm_d("WPS session is already in progress");
        return -WM_FAIL;
    }

    if (wpa_supp_wps_pin_valid(netif, (const unsigned char *)pin) != WM_SUCCESS)
    {
        wlcm_d("WPS PIN validation failed for %s", pin);
        return -WM_FAIL;
    }
    wlan_remove_wps_network();
    return wpa_supp_start_wps_pin(netif, pin, 0);
}

int wlan_wps_cancel(void)
{
    struct netif *netif = net_get_sta_interface();

    if (wlan.wps_session_attempt == 0)
    {
        return WM_SUCCESS;
    }

    return wpa_supp_cancel_wps(netif, 0);
}

#ifdef CONFIG_WPA_SUPP_AP
int wlan_start_ap_wps_pbc(void)
{
    struct netif *netif = net_get_uap_interface();

    if (is_uap_started() == 0)
    {
        wlcm_e("Cannot Start WPS PBC as uAP is not running");
        return -WM_FAIL;
    }

    return wpa_supp_start_wps_pbc(netif, 1);
}

int wlan_start_ap_wps_pin(const char *pin)
{
    struct netif *netif = net_get_uap_interface();

    if (is_uap_started() == 0)
    {
        wlcm_e("Cannot Start WPS PIN as uAP is not running");
        return -WM_FAIL;
    }

    if (wpa_supp_wps_pin_valid(netif, (const unsigned char *)pin) != WM_SUCCESS)
    {
        wlcm_d("WPS PIN validation failed for %s", pin);
        return -WM_FAIL;
    }

    return wpa_supp_start_wps_pin(netif, pin, 1);
}

int wlan_wps_ap_cancel(void)
{
    struct netif *netif = net_get_uap_interface();

    return wpa_supp_cancel_wps(netif, 1);
}
#endif
#endif
#endif

#if defined(CONFIG_WPA2_ENTP) || defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE)
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
static void wlan_entp_cert_cleanup()
{
    if (wlan.ca_cert_data != NULL)
    {
        os_mem_free(wlan.ca_cert_data);
    }
    if (wlan.client_cert_data != NULL)
    {
        os_mem_free(wlan.client_cert_data);
    }
    if (wlan.client_key_data != NULL)
    {
        os_mem_free(wlan.client_key_data);
    }
    if (wlan.ca_cert2_data != NULL)
    {
        os_mem_free(wlan.ca_cert2_data);
    }
    if (wlan.client_cert2_data != NULL)
    {
        os_mem_free(wlan.client_cert2_data);
    }
    if (wlan.client_key2_data != NULL)
    {
        os_mem_free(wlan.client_key2_data);
    }

#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    if (wlan.dh_data != NULL)
    {
        os_mem_free(wlan.dh_data);
    }
    if (wlan.server_cert_data != NULL)
    {
        os_mem_free(wlan.server_cert_data);
    }
    if (wlan.server_key_data != NULL)
    {
        os_mem_free(wlan.server_key_data);
    }
#endif
#endif
}

int wlan_set_entp_cert_files(int cert_type, t_u8 *data, t_u32 data_len)
{
    if (cert_type == FILE_TYPE_ENTP_CA_CERT)
    {
        wlan.ca_cert_data = os_mem_alloc(data_len);
        if (!wlan.ca_cert_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("CA Cert malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.ca_cert_data, data, data_len);
        wlan.ca_cert_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_CERT)
    {
        wlan.client_cert_data = os_mem_alloc(data_len);
        if (!wlan.client_cert_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Client Cert malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.client_cert_data, data, data_len);
        wlan.client_cert_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_KEY)
    {
        wlan.client_key_data = os_mem_alloc(data_len);
        if (!wlan.client_key_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Client Key malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.client_key_data, data, data_len);
        wlan.client_key_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_CA_CERT2)
    {
        wlan.ca_cert2_data = os_mem_alloc(data_len);
        if (!wlan.ca_cert2_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("CA Cert2 malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.ca_cert2_data, data, data_len);
        wlan.ca_cert2_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_CERT2)
    {
        wlan.client_cert2_data = os_mem_alloc(data_len);
        if (!wlan.client_cert2_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Client Cert2 malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.client_cert2_data, data, data_len);
        wlan.client_cert2_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_KEY2)
    {
        wlan.client_key2_data = os_mem_alloc(data_len);
        if (!wlan.client_key2_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Client Key2 malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.client_key2_data, data, data_len);
        wlan.client_key2_len = data_len;
    }
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    else if (cert_type == FILE_TYPE_ENTP_DH_PARAMS)
    {
        wlan.dh_data = os_mem_alloc(data_len);
        if (!wlan.dh_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("DH params malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.dh_data, data, data_len);
        wlan.dh_len = data_len;
    }
#endif
#endif
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    else if (cert_type == FILE_TYPE_ENTP_SERVER_CERT)
    {
        wlan.server_cert_data = os_mem_alloc(data_len);
        if (!wlan.server_cert_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Server Cert malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.server_cert_data, data, data_len);
        wlan.server_cert_len = data_len;
    }
    else if (cert_type == FILE_TYPE_ENTP_SERVER_KEY)
    {
        wlan.server_key_data = os_mem_alloc(data_len);
        if (!wlan.server_key_data)
        {
            wlan_entp_cert_cleanup();
            wlcm_e("Server Key malloc failed");
            return -WM_FAIL;
        }
        memcpy(wlan.server_key_data, data, data_len);
        wlan.server_key_len = data_len;
    }
#endif
#endif
    else
    {
        wlcm_e("Invalid file type");
        return -WM_FAIL;
    }

    return WM_SUCCESS;
}
#endif

t_u32 wlan_get_entp_cert_files(int cert_type, t_u8 **data)
{
    int len = 0;
    if (cert_type == FILE_TYPE_ENTP_CA_CERT)
    {
        *data = wlan.ca_cert_data;
        len   = wlan.ca_cert_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.ca_cert_data)
        {
            *data = (t_u8 *)ca_der;
            len   = ca_der_len;
        }
#endif
        wlan.ca_cert_data = NULL;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_CERT)
    {
        *data = wlan.client_cert_data;
        len   = wlan.client_cert_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.client_cert_data)
        {
            *data = (t_u8 *)client_der;
            len   = client_der_len;
        }
#endif
        wlan.client_cert_data = NULL;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_KEY)
    {
        *data = wlan.client_key_data;
        len   = wlan.client_key_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.client_key_data)
        {
            *data = (t_u8 *)client_key_der;
            len   = client_key_der_len;
        }
#endif
        wlan.client_key_data = NULL;
    }
    if (cert_type == FILE_TYPE_ENTP_CA_CERT2)
    {
        *data = wlan.ca_cert2_data;
        len   = wlan.ca_cert2_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.ca_cert2_data)
        {
            *data = (t_u8 *)ca_der;
            len   = ca_der_len;
        }
#endif
        wlan.ca_cert2_data = NULL;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_CERT2)
    {
        *data = wlan.client_cert2_data;
        len   = wlan.client_cert2_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.client_cert2_data)
        {
            *data = (t_u8 *)client_der;
            len   = client_der_len;
        }
#endif
        wlan.client_cert2_data = NULL;
    }
    else if (cert_type == FILE_TYPE_ENTP_CLIENT_KEY2)
    {
        *data = wlan.client_key2_data;
        len   = wlan.client_key2_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.client_key2_data)
        {
            *data = (t_u8 *)client_key_der;
            len   = client_key_der_len;
        }
#endif
        wlan.client_key2_data = NULL;
    }
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    else if (cert_type == FILE_TYPE_ENTP_DH_PARAMS)
    {
        *data = wlan.dh_data;
        len   = wlan.dh_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.dh_data)
        {
            *data = (t_u8 *)dh_der;
            len   = dh_der_len;
        }
#endif
        wlan.dh_data = NULL;
    }
#endif
#endif
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    else if (cert_type == FILE_TYPE_ENTP_SERVER_CERT)
    {
        *data = wlan.server_cert_data;
        len   = wlan.server_cert_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.server_cert_data)
        {
            *data = (t_u8 *)server_der;
            len   = server_der_len;
        }
#endif
        wlan.server_cert_data = NULL;
    }
    else if (cert_type == FILE_TYPE_ENTP_SERVER_KEY)
    {
        *data = wlan.server_key_data;
        len   = wlan.server_key_len;
#ifndef CONFIG_WIFI_USB_FILE_ACCESS
        if (!wlan.server_key_data)
        {
            *data = (t_u8 *)server_key_der;
            len   = server_key_der_len;
        }
#endif
        wlan.server_key_data = NULL;
    }
#endif
#endif

    return len;
}

void wlan_free_entp_cert_files(void)
{
#ifdef CONFIG_WIFI_USB_FILE_ACCESS
    if (wlan.ca_cert_data != NULL)
    {
        wlan.ca_cert_data = NULL;
        wlan.ca_cert_len  = 0;
    }
    if (wlan.client_cert_data != NULL)
    {
        wlan.client_cert_data = NULL;
        wlan.client_cert_len  = 0;
    }
    if (wlan.client_key_data != NULL)
    {
        wlan.client_key_data = NULL;
        wlan.client_key_len  = 0;
    }
    if (wlan.ca_cert2_data != NULL)
    {
        wlan.ca_cert2_data = NULL;
        wlan.ca_cert2_len  = 0;
    }
    if (wlan.client_cert2_data != NULL)
    {
        wlan.client_cert2_data = NULL;
        wlan.client_cert2_len  = 0;
    }
    if (wlan.client_key2_data != NULL)
    {
        wlan.client_key2_data = NULL;
        wlan.client_key2_len  = 0;
    }
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    if (wlan.dh_data != NULL)
    {
        wlan.dh_data = NULL;
        wlan.dh_len  = 0;
    }
    if (wlan.server_cert_data != NULL)
    {
        wlan.server_cert_data = NULL;
        wlan.server_cert_len  = 0;
    }
    if (wlan.server_key_data != NULL)
    {
        wlan.server_key_data = NULL;
        wlan.server_key_len  = 0;
    }
#endif
#endif
#endif
}
#endif

#ifdef CONFIG_NET_MONITOR
void wlan_register_monitor_user_callback(int (*monitor_data_recv_callback)(void *buffer, t_u16 data_len))
{
    register_monitor_user_callback(monitor_data_recv_callback);
}

void wlan_deregister_net_monitor_user_callback()
{
    deregister_monitor_user_callback();
}

int wlan_net_monitor_cfg(wlan_net_monitor_t *monitor)
{
    bool flag = false;

    if (is_sta_connected() || is_uap_started())
    {
        (void)PRINTF("down the uap and disconnet sta first\n\r");
        return WM_FAIL;
    }

    flag = (1 == monitor->monitor_activity) ? true : false;
    set_monitor_flag(flag);
    return wifi_net_monitor_cfg(monitor);
}
#endif

#ifdef CONFIG_TSP
int wlan_get_tsp_cfg(t_u16 *enable,
                     t_u32 *back_off,
                     t_u32 *highThreshold,
                     t_u32 *lowThreshold,
                     t_u32 *dutycycstep,
                     t_u32 *dutycycmin,
                     int *highthrtemp,
                     int *lowthrtemp,
                     int *currCAUTemp,
                     int *currRFUTemp)
{
    t_u16 action = 0;

    return wifi_tsp_cfg(action, enable, back_off, highThreshold, lowThreshold, dutycycstep, dutycycmin, highthrtemp, lowthrtemp, currCAUTemp, currRFUTemp);
}
int wlan_set_tsp_cfg(t_u16 enable,
                     t_u32 back_off,
                     t_u32 highThreshold,
                     t_u32 lowThreshold,
                     t_u32 dutycycstep,
                     t_u32 dutycycmin,
                     int highthrtemp,
                     int lowthrtemp)
{
    t_u16 action = 1;

    return wifi_tsp_cfg(action, &enable, &back_off, &highThreshold, &lowThreshold, &dutycycstep, &dutycycmin, &highthrtemp, &lowthrtemp, NULL, NULL);
}
#endif

int wlan_get_signal_info(wlan_rssi_info_t *signal)
{
    return wifi_send_rssi_info_cmd(signal);
}

int wlan_get_turbo_mode(t_u8 *mode)
{
    return wifi_get_turbo_mode(mode);
}

int wlan_get_uap_turbo_mode(t_u8 *mode)
{
    return wifi_get_uap_turbo_mode(mode);
}

int wlan_set_turbo_mode(t_u8 mode)
{
    return wifi_set_turbo_mode(mode);
}

int wlan_set_uap_turbo_mode(t_u8 mode)
{
    return wifi_set_uap_turbo_mode(mode);
}

void wlan_set_ps_cfg(t_u16 multiple_dtims,
                     t_u16 bcn_miss_timeout,
                     t_u16 local_listen_interval,
                     t_u16 adhoc_wake_period,
                     t_u16 mode,
                     t_u16 delay_to_ps)
{
    wifi_set_ps_cfg(multiple_dtims, bcn_miss_timeout, local_listen_interval, adhoc_wake_period, mode, delay_to_ps);
}

#if defined(CONFIG_IPS)
int wlan_set_ips(int option)
{
    return wifi_set_ips_config(MLAN_BSS_TYPE_STA, option);
}
#endif

int wlan_set_country_code(const char *alpha2)
{
    int ret;
    t_u8 region_code_rw610;
    unsigned char country3 = 0x20;
    char country_code[COUNTRY_CODE_LEN] = {0};
#ifndef RW610
    char region_code[COUNTRY_CODE_LEN] = {0};
    const char *wlan_region_code = NULL;

    wlan_region_code = wlan_get_wlan_region_code();

    region_code[0] = alpha2[0];
    region_code[1] = alpha2[1];

    if (strstr(wlan_region_code, region_code) == NULL)
    {
        if (strstr(wlan_region_code, "WW") == NULL)
        {
            wlcm_d("%s: Specific region is configured, reconfig not allowed", wlan_region_code);
            return -WM_FAIL;
        }
    }
#endif

    if ((alpha2[2] == 0x4f) || (alpha2[2] == 0x49) || (alpha2[2] == 0x58) || (alpha2[2] == 0x04))
    {
        country3 = alpha2[2];
    }

    country_code[0] = alpha2[0];
    country_code[1] = alpha2[1];
    country_code[2] = country3;

    ret = wlan_11d_region_2_code(mlan_adap, (t_u8 *)country_code, &region_code_rw610);
    if(ret != WM_SUCCESS)
    {
        wlcm_e("%s: Invalid country code.",country_code);
        return ret;
    }

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *netif = net_get_uap_interface();

    ret = wpa_supp_set_ap_country(netif, alpha2, country3);
    if (ret != WM_SUCCESS)
    {
        return -WM_FAIL;
    }
#endif
#endif
    ret = wifi_set_country_code(country_code);
    if (ret != WM_SUCCESS)
        return ret;

#if defined(RW610) && defined(CONFIG_COMPRESS_TX_PWTBL)
    return wlan_set_rg_power_cfg(region_code_rw610);
#else
    return ret;
#endif
}

int wlan_set_country_ie_ignore(uint8_t *ignore)
{
    return wifi_set_country_ie_ignore(ignore);
}

int wlan_set_region_code(unsigned int region_code)
{
    char *country;

    if ((region_code == 0x40) || (region_code == 0x41) || (region_code == 0xFE))
    {
        (void)PRINTF("Region code 0XFF is used for Japan to support channels of both 2.4GHz band and 5GHz band.\r\n");
        return -WM_FAIL;
    }

    country = (char *)wlan_11d_code_2_region(mlan_adap, (unsigned char)region_code);
    return wlan_set_country_code(country);
}

int wlan_get_region_code(unsigned int *region_code)
{
    return wifi_get_region_code(region_code);
}

int wlan_set_11d_state(int bss_type, int state)
{
#ifdef CONFIG_WPA_SUPP_AP
    struct netif *netif;
#endif
    if (bss_type == WLAN_BSS_TYPE_UAP)
    {
#ifdef CONFIG_WPA_SUPP_AP
        netif = net_get_uap_interface();
        wpa_supp_set_ap_11d_state(netif, state);
#endif

        return wlan_enable_uap_11d(state);
    }
    else
    {
        return wlan_enable_11d(state);
    }
}

#ifdef CONFIG_COEX_DUTY_CYCLE
int wlan_single_ant_duty_cycle(t_u16 enable, t_u16 nbTime, t_u16 wlanTime)
{
    return wifi_single_ant_duty_cycle(enable, nbTime, wlanTime);
}

int wlan_dual_ant_duty_cycle(t_u16 enable, t_u16 nbTime, t_u16 wlanTime, t_u16 wlanBlockTime)
{
    return wifi_dual_ant_duty_cycle(enable, nbTime, wlanTime, wlanBlockTime);
}
#endif

#ifdef CONFIG_EXTERNAL_COEX_PTA
int wlan_external_coex_pta_cfg(ext_coex_pta_cfg coex_pta_config)
{
    return wifi_external_coex_pta_cfg(coex_pta_config);
}
#endif

#ifdef CONFIG_WPA_SUPP_DPP
int wlan_dpp_configurator_add(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();
    int ret;

    ret = wpa_supp_dpp_configurator_add(netif, is_ap, cmd);
    if (ret <= 0)
    {
        wlcm_e("DPP add configurator failed!!");
        return -WM_FAIL;
    }
    return ret;
}

void wlan_dpp_configurator_params(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    wpa_supp_dpp_configurator_params(netif, is_ap, cmd);
}

void wlan_dpp_mud_url(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    wpa_supp_dpp_mud_url(netif, is_ap, cmd);
}

int wlan_dpp_bootstrap_gen(int is_ap, const char *cmd)
{
    int id;
    struct netif *netif = net_get_sta_interface();

    id = wpa_supp_dpp_bootstrap_gen(netif, is_ap, cmd);
    if (id < 0)
    {
        wlcm_e("DPP generate qrcode failed!!");
        id = -WM_FAIL;
    }
    return id;
}

const char *wlan_dpp_bootstrap_get_uri(int is_ap, unsigned int id)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_dpp_bootstrap_get_uri(netif, is_ap, id);
}

int wlan_dpp_qr_code(int is_ap, char *uri)
{
    int id;
    struct netif *netif = net_get_sta_interface();

    id = wpa_supp_dpp_qr_code(netif, is_ap, uri);
    if (id < 0)
    {
        wlcm_e("DPP enter QR code failed!!");
        return -WM_FAIL;
    }

    return id;
}

int wlan_dpp_auth_init(int is_ap, const char *cmd)
{
    int ret;
    struct netif *netif = net_get_sta_interface();

    if (!is_ap)
    {
        wifi_set_rx_mgmt_indication(WLAN_BSS_ROLE_STA, WLAN_MGMT_ACTION);
    }
    ret = wpa_supp_dpp_auth_init(netif, is_ap, cmd);
    if (ret < 0)
    {
        wlcm_e("DPP Auth Init failed!!");
        return -WM_FAIL;
    }

    return ret;
}

int wlan_dpp_listen(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_dpp_listen(netif, is_ap, cmd);
}

int wlan_dpp_stop_listen(int is_ap)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_dpp_stop_listen(netif, is_ap);
}

int wlan_dpp_pkex_add(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    if (!is_ap)
    {
        wifi_set_rx_mgmt_indication(WLAN_BSS_ROLE_STA, WLAN_MGMT_ACTION);
    }
    if (wpa_supp_dpp_pkex_add(netif, is_ap, cmd) < 0)
    {
        wlcm_e("DPP add PKEX failed!!");
        return -WM_FAIL;
    }
    return WM_SUCCESS;
}

int wlan_dpp_chirp(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    if (!is_ap)
    {
        wifi_set_rx_mgmt_indication(WLAN_BSS_ROLE_STA, WLAN_MGMT_ACTION);
    }
    return wpa_supp_dpp_chirp(netif, is_ap, cmd);
}

int wlan_dpp_reconfig(const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_dpp_reconfig(netif, cmd);
}

int wlan_dpp_configurator_sign(int is_ap, const char *cmd)
{
    struct netif *netif = net_get_sta_interface();

    return wpa_supp_dpp_configurator_sign(netif, is_ap, cmd);
}
#endif /* CONFIG_WPA_SUPP_DPP */

#ifdef CONFIG_IMD3_CFG
int wlan_imd3_cfg(t_u8 imd3_value)
{
    return wifi_imd3_cfg(imd3_value);
}
#endif

#ifdef CONFIG_WPA_SUPP
int wlan_host_set_sta_mac_filter(int filter_mode, int mac_count, unsigned char *mac_addr)
{
    int ret = 0;
    struct netif *uap_netif = net_get_uap_interface();
    ret = wpa_supp_set_mac_acl(uap_netif, filter_mode, mac_count, mac_addr);
    if (ret < 0)
        return -WM_FAIL;
    else
        return WM_SUCCESS;
}
#endif

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
int wlan_set_indrst_cfg(const wlan_indrst_cfg_t *indrst_cfg)
{
    wlan.ir_mode = indrst_cfg->ir_mode;

    return wifi_set_indrst_cfg(indrst_cfg, (mlan_bss_type)WLAN_BSS_TYPE_STA);
}

int wlan_get_indrst_cfg(wlan_indrst_cfg_t *indrst_cfg)
{
       return wifi_get_indrst_cfg(indrst_cfg, (mlan_bss_type)WLAN_BSS_TYPE_STA);
}

static int wlan_trigger_oob_ind_reset()
{
    (void)wlan_ieeeps_off();

    os_thread_sleep(os_msec_to_ticks(1000));

    (void)wlan_deepsleepps_off();

    os_thread_sleep(os_msec_to_ticks(1000));

#ifdef IR_OUTBAND_TRIGGER_GPIO
    GPIO_PinWrite(IR_OUTBAND_TRIGGER_GPIO, IR_OUTBAND_TRIGGER_GPIO_PIN, 0);

    os_thread_sleep(os_msec_to_ticks(10));

    GPIO_PinWrite(IR_OUTBAND_TRIGGER_GPIO, IR_OUTBAND_TRIGGER_GPIO_PIN, 1);
#endif

    return wifi_trigger_oob_indrst();
}

int wlan_independent_reset()
{
    if (wlan.ir_mode == 1)
    {
        return wlan_trigger_oob_ind_reset();
    }
    else if (wlan.ir_mode == 2)
    {
        return wifi_test_independent_reset();
    }

    return -WM_FAIL;
}
#endif

#ifdef CONFIG_INACTIVITY_TIMEOUT_EXT
int wlan_sta_inactivityto(wlan_inactivity_to_t *inac_to, t_u16 action)
{
    return wifi_sta_inactivityto(inac_to, action);
}
#endif

#ifdef RW610
int32_t wlan_get_temperature()
{
    return wifi_get_temperature();
}
#endif

#ifdef CONFIG_CPU_LOADING

static void wlan_cpu_loading_record_data(void)
{
    memset(cpu_loading.cpu_loading_info, 0, cpu_loading.task_status_len);

    char run_task_name[configMAX_TASK_NAME_LEN];
    char cpu_run_data[20];
    unsigned int value;
    int task_name_index = 0, task_time_index = 0, index = 0, task_index = 0;

    os_get_runtime_stats(cpu_loading.cpu_loading_info);

    uint32_t len_data = strlen(cpu_loading.cpu_loading_info);
    do
    {
        memset(run_task_name, 0, strlen(run_task_name));
        /*Record task name*/
        do
        {
            if(cpu_loading.cpu_loading_info[index] == ' ' && cpu_loading.cpu_loading_info[index + 1] == ' ') // Complete name parsing
                break;
            else
                run_task_name[task_name_index++] = cpu_loading.cpu_loading_info[index++];
        }while(index < len_data);

        do      //Filter out padding spaces between task names and run time values.
        {
            if(cpu_loading.cpu_loading_info[index++] == '\t')
                break;
        } while (index < len_data);

        /*Record task run time*/
        do
        {
            if(cpu_loading.cpu_loading_info[index] < '0' || cpu_loading.cpu_loading_info[index] > '9')
                break;
            cpu_run_data[task_time_index++] = cpu_loading.cpu_loading_info[index++];
        }while(index < len_data);

        cpu_run_data[task_time_index] = '\0';
        get_uint(cpu_run_data, &value, strlen(cpu_run_data));

        if(cpu_loading.index > 0)
        {
            for(int i = 0; i < cpu_loading.task_nums; i++)  // To collect CPU loading info according to fixed task name sequence.
            {
                if(!strcmp(cpu_loading.task_name[i], run_task_name))
                {
                    cpu_loading.data_pre[i] = cpu_loading.data_cur[i];
                    cpu_loading.data_cur[i] = value;
                    break;
                }
            }
        }
        else
        {
            memset(task_string_name[task_index],' ', configMAX_TASK_NAME_LEN);
            task_string_name[task_index][configMAX_TASK_NAME_LEN -1] = '\0';

            memcpy(cpu_loading.task_name[task_index], run_task_name, strlen(run_task_name));
            memcpy(task_string_name[task_index], run_task_name, strlen(run_task_name));
            cpu_loading.data_pre[task_index] = value;
            cpu_loading.data_cur[task_index] = value;
            cpu_loading.first_data[task_index] = value;

            cpu_loading.task_name[task_index][strlen(run_task_name)] = '\0';
        }

        /*Filter percentage value*/
        do
        {
            if(cpu_loading.cpu_loading_info[index] == '\r' && cpu_loading.cpu_loading_info[index + 1] == '\n')
            {
                index += 2;
                break;
            }

            index++;
        }while((index < len_data));

        task_time_index = 0;
        task_name_index = 0;
        task_index ++;

    }while (index < len_data);

    cpu_loading.index ++;
    cpu_loading.sampling_loops --;
}

static void wlan_cpu_loading_handler(os_thread_arg_t data)
{
    for(;;)
    {
        /* Wait till cpu loading timer time out. */
        (void)os_event_notify_get(OS_WAIT_FOREVER);

        if(cpu_loading.sampling_loops == 0)
        {
            wlan_cpu_loading_stop();
        }
        else
        {
            wlan_cpu_loading_record_data();
            if(cpu_loading.index > 1)
                wlan_cpu_loading_info_display();
        }
    }

    os_thread_self_complete(NULL);
}

static void cpu_loading_cb(os_timer_arg_t arg)
{
    (void)os_event_notify_put(cpu_loading.cpu_loading_thread);
}

static int wlan_cpu_loading_start(uint32_t number, uint8_t period)
{
    int ret;

    if(cpu_loading.status == CPU_LOADING_STATUS_DEAD)
    {
        memset(&cpu_loading, 0, sizeof(cpu_loading));
        if(period == 0)
            cpu_loading.sampling_period = CPU_LOADING_PERIOD;
        else
            cpu_loading.sampling_period = period * (CPU_LOADING_PERIOD / 2);

        ret = os_timer_create(&cpu_loading.cpu_loading_timer, "cpu-loading-timer", os_msec_to_ticks(cpu_loading.sampling_period),
                                &cpu_loading_cb, NULL, OS_TIMER_PERIODIC, OS_TIMER_NO_ACTIVATE);
        if (ret != WM_SUCCESS)
        {
            (void)PRINTF("Unable to create cpu loading timer.\r\n");
            return ret;
        }

        ret = os_thread_create(&cpu_loading.cpu_loading_thread, "cpu_loading_task", wlan_cpu_loading_handler, 0,
                                &cpu_loading_stack, OS_PRIO_1);
        if (ret != WM_SUCCESS)
        {
            (void)PRINTF("Unable to create cpu loading thread.\r\n");
            return ret;
        }

        os_get_num_of_tasks(&cpu_loading.task_nums);
        cpu_loading.task_status_len = cpu_loading.task_nums * sizeof(TaskStatus_t);
        cpu_loading.cpu_loading_info = (char *)os_mem_alloc(cpu_loading.task_status_len);
        if (cpu_loading.cpu_loading_info == NULL)
        {
            (void)PRINTF("%s: Failed to alloc cpu loading info\r\n", __func__);
            return -WM_FAIL;
        }

        cpu_loading.index = 0;
        if(number != 0)
            cpu_loading.sampling_loops = number;
        else
            cpu_loading.sampling_loops = CPU_LOADING_KEEPING;

        cpu_loading.status = CPU_LOADING_STATUS_ONGOING;

        memset(cpu_loading.data_cur, 0, sizeof(cpu_loading.data_cur));
        memset(cpu_loading.data_pre, 0, sizeof(cpu_loading.data_pre));
        (void)os_timer_activate(&cpu_loading.cpu_loading_timer);
        return WM_SUCCESS;
    }
    else
    {
        wlcm_e("Unable to start cpu loading timer, pls stop the previous cpu loading test firstly.");
        return -WM_FAIL;
    }
}

int wlan_cpu_loading(uint8_t start, uint32_t number, uint8_t period)
{
    int ret;
    if(start == CPU_LOADING_ACTION_STOP)
    {
        if(cpu_loading.status == CPU_LOADING_STATUS_DEAD)
        {
            (void)PRINTF("Collecting CPU loading info has already ended.\r\n");
            return WM_SUCCESS;
        }
        else
        {
            cpu_loading.sampling_loops = 0;
            os_timer_change(&cpu_loading.cpu_loading_timer, os_msec_to_ticks(100), 0); // Chages value of cpu loading timer to stop cpu loading test quickly.
            if(cpu_loading.status != CPU_LOADING_STATUS_DEAD)
            {
                os_thread_sleep(os_msec_to_ticks(50));
            }
            return WM_SUCCESS;
        }
    }
    else
    {
        return wlan_cpu_loading_start(number, period);
    }
}

#endif

#ifdef CONFIG_AUTO_NULL_TX
int wlan_auto_null_tx(wlan_auto_null_tx_t *auto_null_tx)
{
    if (auto_null_tx == NULL)
    {
        return -WM_E_INVAL;
    }

    return wifi_auto_null_tx(auto_null_tx);
}
#endif

char *wlan_string_dup(const char *s)
{
    char *snew = (char *)os_mem_alloc(strlen(s) + 1);
    if (snew)
        (void)strcpy(snew, s);
    return snew;
}
