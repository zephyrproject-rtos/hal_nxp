/*
 *  Copyright 2008-2023 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

/*! \file wlan.h
 * \brief WLAN Connection Manager
 *
 * The WLAN Connection Manager (WLCMGR) is one of the core components that
 * provides WiFi-level functionality like scanning for networks,
 * starting a network (Access Point) and associating / disassociating with
 * other wireless networks. The WLCMGR manages two logical interfaces,
 * the station interface and the micro-AP interface.
 * Both these interfaces can be active at the same time.
 *
 * \section wlan_usage Usage
 *
 * The WLCMGR is initialized by calling \ref wlan_init() and started by
 * calling \ref wlan_start(), one of the arguments of this function is a
 * callback handler. Many of the WLCMGR tasks are asynchronous in nature,
 * and the events are provided by invoking the callback handler.
 * The various usage scenarios of the WLCMGR are outlined below:
 *
 * - <b>Scanning:</b> A call to wlan_scan() initiates an asynchronous scan of
 *      the nearby wireless networks. The results are reported via the callback
 *      handler.
 * - <b>Network Profiles:</b> Starting / stopping wireless interfaces or
 *      associating / disassociating with other wireless networks is managed
 *      through network profiles. The network profiles record details about the
 *      wireless network like the SSID, type of security, security passphrase
 *      among other things. The network profiles can be managed by means of the
 *      \ref wlan_add_network() and \ref wlan_remove_network() calls.
 * - <b>Association:</b> The \ref wlan_connect() and \ref wlan_disconnect()
 *      calls can be used to manage connectivity with other wireless networks
 *      (Access Points). These calls manage the station interface of the system.
 * - <b>Starting a Wireless Network:</b> The \ref wlan_start_network()
 *       and \ref wlan_stop_network() calls can be used to start/stop
 *       our own (micro-AP) network. These calls manage
 *       the micro-AP interface of the system.
 *
 * @cond uml_diag
 *
 * \section WLCMGR_station_sm Station State Machine
 *
 * The WLAN Connection Manager station state diagram is as shown below. The Yellow boxes
 * indicate the various states. The top half is the name of the state, and the
 * bottom half consists of any code that is executed on entering that
 * state. Labels on the transitions indicate when that particular transition is
 * taken.
 *
 * @startuml{station.jpg}
 *
 * [*] --> Initializing
 * Initializing: net_wlan_init()
 * Initializing -down-> Idle : Success
 *
 * Idle -right-> Scanning : wlan_connect(WPA/WPA2/Mixed/Open)
 * Idle -left-> Configuring : wlan_connect(WEP)
 * Idle -down-> Scanning_User: wlan_scan()
 *
 * Scanning_User: report_scan_results()
 * Scanning_User -up-> Idle: scan_success
 *
 * Scanning: handle_scan_results()
 * Scanning -left-> Scanning : scan_success
 * Scanning -down-> Associating: Success
 * Configuring: wifi_send_wep_key_material_cmd()
 * Configuring -down-> Scanning: Success
 *
 * Associating: configure_security(), wifi_assoc()
 * Associating -down->Associated: assoc_success
 * Associating -up->Scanning: assoc_failure
 *
 * Associated -down-> Requesting_Address: authentication_success
 * Associated -up-> Idle: authentication_failure, disassociation, deauthentication
 *
 * Requesting_Address: net_configure_address()
 * Requesting_Address -down-> Connected: static_ip
 * Requesting_Address -left-> Obtaining_Address: dhcp_ip
 *
 * Obtaining_Address: dhcp_start()
 * Obtaining_Address -down-> Connected: dhcp_success
 * Obtaining_Address -up-> Idle: dhcp_failure
 *
 * Connected: net_configure_dns()
 * Connected -up-> Idle: lins_loss, channel_switch, wlan_disconnect()
 *
 * @enduml
 *
 * \section WLCMGR_uap_sm Micro-AP State Machine
 *
 * The WLAN Connection Manager micro-AP state diagram is as shown below. The Yellow boxes
 * indicate the various states. The top half is the name of the state, and the
 * bottom half consists of any code that is executed on entering that
 * state. Labels on the transitions indicate when that particular transition is
 * taken.
 *
 * @startuml{uap.jpg}
 *
 * [*] --> Initializing
 * Initializing: net_wlan_init()
 * Initializing -down-> Configured: wlan_start_network()
 *
 * Configured: do_start()
 * Configured -down-> Started: up_started
 *
 * Started: net_configure_address()
 * Started -down-> Up: uap_addr_config
 *
 * Up -up-> Initializing: wlan_stop_network()
 * Started -up-> Initializing: wlan_stop_network()
 *
 * @enduml
 *
 * @endcond
 */

#ifndef __WLAN_H__
#define __WLAN_H__

#ifdef __ZEPHYR__
#include <nxp_wifi.h>
#endif

#include <wmtypes.h>
#include <wmerrno.h>
#include <stdint.h>
#include <wifi_events.h>
#include <wifi.h>

#define WLAN_DRV_VERSION "v1.3.r48.p9"

#ifdef CONFIG_WPA2_ENTP
#include <wm_mbedtls_helper_api.h>
#endif

#define ARG_UNUSED(x) (void)(x)
/* Configuration */

#ifndef CONFIG_WLAN_KNOWN_NETWORKS
#define CONFIG_WLAN_KNOWN_NETWORKS 5U
#endif

#include <wmlog.h>
#define wlcm_e(...) wmlog_e("wlcm", ##__VA_ARGS__)
#define wlcm_w(...) wmlog_w("wlcm", ##__VA_ARGS__)

#ifdef CONFIG_WLCMGR_DEBUG
#define wlcm_d(...) wmlog("wlcm", ##__VA_ARGS__)
#else
#define wlcm_d(...)
#endif /* ! CONFIG_WLCMGR_DEBUG */

/** Action GET */
#define ACTION_GET (0U)
/** Action SET */
#define ACTION_SET (1)

/** Maximum SSID length */
#ifndef IEEEtypes_SSID_SIZE
#define IEEEtypes_SSID_SIZE 32U
#endif /* IEEEtypes_SSID_SIZE */

/** MAC Address length */
#ifndef IEEEtypes_ADDRESS_SIZE
#define IEEEtypes_ADDRESS_SIZE 6
#endif /* IEEEtypes_ADDRESS_SIZE */

#ifdef CONFIG_HOST_SLEEP
#ifdef CONFIG_POWER_MANAGER
extern os_queue_t *mon_thread_event_queue;
#endif
#endif

typedef enum
{
    BSS_INFRASTRUCTURE = 1,
    BSS_INDEPENDENT,
    BSS_ANY
} IEEEtypes_Bss_t;

/* The possible types of Basic Service Sets */

/** The number of times that the WLAN Connection Manager will look for a
 *  network before giving up. */
#ifdef CONFIG_MAX_RESCAN_LIMIT
#define WLAN_RESCAN_LIMIT CONFIG_MAX_RESCAN_LIMIT
#else
#ifdef CONFIG_WPA_SUPP
#define WLAN_RESCAN_LIMIT 30U
#else
#define WLAN_RESCAN_LIMIT 5U
#endif /* CONFIG_WPA_SUPP */
#endif /* CONFIG_MAX_RESCAN_LIMIT */

#define WLAN_11D_SCAN_LIMIT 3U
/** The number of times that the WLAN Connection Manager will attempt a
 * reconnection with the network before giving up. */
#define WLAN_RECONNECT_LIMIT 5U
/** The minimum length for network names, see \ref wlan_network.  This must
 *  be between 1 and \ref WLAN_NETWORK_NAME_MAX_LENGTH */
#define WLAN_NETWORK_NAME_MIN_LENGTH 1U
/** The space reserved for storing network names, \ref wlan_network */
#define WLAN_NETWORK_NAME_MAX_LENGTH 32U
/** The space reserved for storing PSK (password) phrases. */
/* Min WPA2 passphrase can be upto 8 ASCII chars */
#define WLAN_PSK_MIN_LENGTH 8U
/** Max WPA2 passphrase can be upto 63 ASCII chars or 64 hexadecimal digits*/
#define WLAN_PSK_MAX_LENGTH 65U
/** Min WPA3 password can be upto 8 ASCII chars */
#define WLAN_PASSWORD_MIN_LENGTH 8U
/** Max WPA3 password can be upto 255 ASCII chars */
#define WLAN_PASSWORD_MAX_LENGTH 255U
/** Max WPA2 Enterprise identity can be upto 256 characters */
#define IDENTITY_MAX_LENGTH 64U
/** Max WPA2 Enterprise password can be upto 256 unicode characters */
#define PASSWORD_MAX_LENGTH 128U
/** Max identities for EAP server users */
#define MAX_USERS 8U
/** Encryption key for EAP-FAST PAC-Opaque values. This key must be a secret, random value. It is configured as a
 * 16-octet value in hex format. */
#define PAC_OPAQUE_ENCR_KEY_MAX_LENGTH 33U
/** A-ID indicates the identity of the authority that issues PACs. The A-ID should be unique across all issuing servers.
 * A-ID to be 16 octets in length */
#define A_ID_MAX_LENGTH 33U
/** MAX CA Cert hash len */
#define HASH_MAX_LENGTH 40U
/** MAX domain len */
#define DOMAIN_MATCH_MAX_LENGTH 64U

#ifdef CONFIG_WLAN_KNOWN_NETWORKS
/** The size of the list of known networks maintained by the WLAN
   Connection Manager */
#define WLAN_MAX_KNOWN_NETWORKS CONFIG_WLAN_KNOWN_NETWORKS
#else
#error "CONFIG_WLAN_KNOWN_NETWORKS is not defined"
#endif /* CONFIG_WLAN_KNOWN_NETWORKS */
/** Length of a pairwise master key (PMK).  It's always 256 bits (32 Bytes) */
#define WLAN_PMK_LENGTH 32

#ifdef CONFIG_WMM_UAPSD
#define WMM_UAPSD_QOS_INFO     0x0F
#define WMM_UAPSD_SLEEP_PERIOD 20
#endif


/* Max number of sta filter list can be upto 16 */
#define WLAN_MAX_STA_FILTER_NUM 16

/* The length of wlan mac address */
#define WLAN_MAC_ADDR_LENGTH 6

/* Error Codes */

/** The operation was successful. */
#define WLAN_ERROR_NONE 0
/** The operation failed due to an error with one or more parameters. */
#define WLAN_ERROR_PARAM 1
/** The operation could not be performed because there is not enough memory. */
#define WLAN_ERROR_NOMEM 2
/** The operation could not be performed in the current system state. */
#define WLAN_ERROR_STATE 3
/** The operation failed due to an internal error. */
#define WLAN_ERROR_ACTION 4
/** The operation to change power state could not be performed*/
#define WLAN_ERROR_PS_ACTION 5
/** The requested feature is not supported*/
#define WLAN_ERROR_NOT_SUPPORTED 6

/*
 * HOST_WAKEUP_GPIO_PIN / CARD_WAKEUP_GPIO_PIN
 *
 *   this GPIO PIN number defines the default config. This is chip
 *   specific, and a compile time setting depending on the system
 *   board level build!
 */
#if defined(SD8997) || defined(SD9098) || defined(SD9064) || defined(RW610)
#define HOST_WAKEUP_GPIO_PIN 12
#define CARD_WAKEUP_GPIO_PIN 13
#elif defined(SD9177)
#define HOST_WAKEUP_GPIO_PIN 17
#define CARD_WAKEUP_GPIO_PIN 16
#elif defined(WIFI_88W8987_BOARD_MURATA_1ZM_M2)
#define HOST_WAKEUP_GPIO_PIN 13
#define CARD_WAKEUP_GPIO_PIN 16
#elif defined(WIFI_IW416_BOARD_MURATA_1XK_M2)
#define HOST_WAKEUP_GPIO_PIN 2
#define CARD_WAKEUP_GPIO_PIN 16
#else
#define HOST_WAKEUP_GPIO_PIN 1
#define CARD_WAKEUP_GPIO_PIN 16
#endif

#define WLAN_MGMT_DIASSOC MBIT(10)
#define WLAN_MGMT_AUTH    MBIT(11)
#define WLAN_MGMT_DEAUTH  MBIT(12)
/** BITMAP for Action frame */
#define WLAN_MGMT_ACTION MBIT(13)

#ifdef CONFIG_WMM_UAPSD
#define WMM_UAPSD_QOS_INFO     0x0F
#define WMM_UAPSD_SLEEP_PERIOD 20
#endif

#define WLAN_KEY_MGMT_IEEE8021X             MBIT(0)
#define WLAN_KEY_MGMT_PSK                   MBIT(1)
#define WLAN_KEY_MGMT_NONE                  MBIT(2)
#define WLAN_KEY_MGMT_IEEE8021X_NO_WPA      MBIT(3)
#define WLAN_KEY_MGMT_WPA_NONE              MBIT(4)
#define WLAN_KEY_MGMT_FT_IEEE8021X          MBIT(5)
#define WLAN_KEY_MGMT_FT_PSK                MBIT(6)
#define WLAN_KEY_MGMT_IEEE8021X_SHA256      MBIT(7)
#define WLAN_KEY_MGMT_PSK_SHA256            MBIT(8)
#define WLAN_KEY_MGMT_WPS                   MBIT(9)
#define WLAN_KEY_MGMT_SAE                   MBIT(10)
#define WLAN_KEY_MGMT_FT_SAE                MBIT(11)
#define WLAN_KEY_MGMT_WAPI_PSK              MBIT(12)
#define WLAN_KEY_MGMT_WAPI_CERT             MBIT(13)
#define WLAN_KEY_MGMT_CCKM                  MBIT(14)
#define WLAN_KEY_MGMT_OSEN                  MBIT(15)
#define WLAN_KEY_MGMT_IEEE8021X_SUITE_B     MBIT(16)
#define WLAN_KEY_MGMT_IEEE8021X_SUITE_B_192 MBIT(17)
#define WLAN_KEY_MGMT_FILS_SHA256           MBIT(18)
#define WLAN_KEY_MGMT_FILS_SHA384           MBIT(19)
#define WLAN_KEY_MGMT_FT_FILS_SHA256        MBIT(20)
#define WLAN_KEY_MGMT_FT_FILS_SHA384        MBIT(21)
#define WLAN_KEY_MGMT_OWE                   MBIT(22)
#define WLAN_KEY_MGMT_DPP                   MBIT(23)
#define WLAN_KEY_MGMT_FT_IEEE8021X_SHA384   MBIT(24)
#define WLAN_KEY_MGMT_PASN                  MBIT(25)

#define WLAN_KEY_MGMT_FT                                                                                            \
    (WLAN_KEY_MGMT_FT_PSK | WLAN_KEY_MGMT_FT_IEEE8021X | WLAN_KEY_MGMT_FT_IEEE8021X_SHA384 | WLAN_KEY_MGMT_FT_SAE | \
     WLAN_KEY_MGMT_FT_FILS_SHA256 | WLAN_KEY_MGMT_FT_FILS_SHA384)

#ifdef CONFIG_WPA_SUPP

#define WLAN_CIPHER_NONE         MBIT(0)
#define WLAN_CIPHER_WEP40        MBIT(1)
#define WLAN_CIPHER_WEP104       MBIT(2)
#define WLAN_CIPHER_TKIP         MBIT(3)
#define WLAN_CIPHER_CCMP         MBIT(4)
#define WLAN_CIPHER_AES_128_CMAC MBIT(5)
#define WLAN_CIPHER_GCMP         MBIT(6)
#define WLAN_CIPHER_SMS4         MBIT(7)
#define WLAN_CIPHER_GCMP_256     MBIT(8)
#define WLAN_CIPHER_CCMP_256     MBIT(9)
#define WLAN_CIPHER_BIP_GMAC_128 MBIT(11)
#define WLAN_CIPHER_BIP_GMAC_256 MBIT(12)
#define WLAN_CIPHER_BIP_CMAC_256 MBIT(13)
#define WLAN_CIPHER_GTK_NOT_USED MBIT(14)

#endif

/** Enum for wlan errors*/
enum wm_wlan_errno
{
    WM_E_WLAN_ERRNO_BASE = MOD_ERROR_START(MOD_WLAN),
    /** The Firmware download operation failed. */
    WLAN_ERROR_FW_DNLD_FAILED,
    /** The Firmware ready register not set. */
    WLAN_ERROR_FW_NOT_READY,
    /** The WiFi card not found. */
    WLAN_ERROR_CARD_NOT_DETECTED,
    /** The WiFi Firmware not found. */
    WLAN_ERROR_FW_NOT_DETECTED,
    /** BSSID not found in scan list */
    WLAN_BSSID_NOT_FOUND_IN_SCAN_LIST,
};

/* Events and States */

/** WLAN Connection Manager event reason */
enum wlan_event_reason
{
    /** The WLAN Connection Manager has successfully connected to a network and
     *  is now in the \ref WLAN_CONNECTED state. */
    WLAN_REASON_SUCCESS,
    /** The WLAN Connection Manager has successfully authenticated to a network and
     *  is now in the \ref WLAN_ASSOCIATED state. */
    WLAN_REASON_AUTH_SUCCESS,
    /** The WLAN Connection Manager failed to connect before actual
     * connection attempt with AP due to incorrect wlan network profile.
     * or The WLAN Connection Manager failed to reconnect to previously connected
     * network and it is now in the \ref WLAN_DISCONNECTED state.*/
    WLAN_REASON_CONNECT_FAILED,
    /** The WLAN Connection Manager could not find the network that it was
     *  connecting to and it is now in the \ref WLAN_DISCONNECTED state. */
    WLAN_REASON_NETWORK_NOT_FOUND,
    /** The WLAN Connection Manager could not find the network in bg scan during roam attempt that it was
     *  connecting to and it is now in the \ref WLAN_CONNECTED state with previous AP. */
    WLAN_REASON_BGSCAN_NETWORK_NOT_FOUND,
    /** The WLAN Connection Manager failed to authenticate with the network
     *  and is now in the \ref WLAN_DISCONNECTED state. */
    WLAN_REASON_NETWORK_AUTH_FAILED,
    /** DHCP lease has been renewed.*/
    WLAN_REASON_ADDRESS_SUCCESS,
    /** The WLAN Connection Manager failed to obtain an IP address
     *  or TCP stack configuration has failed or the IP address
     *  configuration was lost due to a DHCP error.  The system is
     *  now in the \ref WLAN_DISCONNECTED state. */
    WLAN_REASON_ADDRESS_FAILED,
    /** The WLAN Connection Manager has lost the link to the current network. */
    WLAN_REASON_LINK_LOST,
    /** The WLAN Connection Manager has received the channel switch
     * announcement from the current network. */
    WLAN_REASON_CHAN_SWITCH,
    /** The WLAN Connection Manager has disconnected from the WPS network
     *  (or has canceled a connection attempt) by request and is now in the
     *  WLAN_DISCONNECTED state. */
    WLAN_REASON_WPS_DISCONNECT,
    /** The WLAN Connection Manager has disconnected from the current network
     *  (or has canceled a connection attempt) by request and is now in the
     *  WLAN_DISCONNECTED state. */
    WLAN_REASON_USER_DISCONNECT,
    /** The WLAN Connection Manager is initialized and is ready for use.
     *  That is, it's now possible to scan or to connect to a network. */
    WLAN_REASON_INITIALIZED,
    /** The WLAN Connection Manager has failed to initialize and is therefore
     *  not running. It is not possible to scan or to connect to a network.  The
     *  WLAN Connection Manager should be stopped and started again via
     *  wlan_stop() and wlan_start() respectively. */
    WLAN_REASON_INITIALIZATION_FAILED,
#if defined(CONFIG_WIFI_IND_DNLD)
    /** The WLAN Connection Manager has entered in hang mode. */
    WLAN_REASON_FW_HANG,
    /** The WLAN Connection Manager has reset fw successfully. */
    WLAN_REASON_FW_RESET,
#endif
    /** The WLAN Connection Manager has entered power save mode. */
    WLAN_REASON_PS_ENTER,
    /** The WLAN Connection Manager has exited from power save mode. */
    WLAN_REASON_PS_EXIT,
    /** The WLAN Connection Manager has started uAP */
    WLAN_REASON_UAP_SUCCESS,
    /** A wireless client has joined uAP's BSS network */
    WLAN_REASON_UAP_CLIENT_ASSOC,
    /** A wireless client has auhtenticated and connected to uAP's BSS network */
    WLAN_REASON_UAP_CLIENT_CONN,
    /** A wireless client has left uAP's BSS network */
    WLAN_REASON_UAP_CLIENT_DISSOC,
    /** The WLAN Connection Manager has failed to start uAP */
    WLAN_REASON_UAP_START_FAILED,
    /** The WLAN Connection Manager has failed to stop uAP */
    WLAN_REASON_UAP_STOP_FAILED,
    /** The WLAN Connection Manager has stopped uAP */
    WLAN_REASON_UAP_STOPPED,
    /** The WLAN Connection Manager has received subscribed RSSI low event on station interface as per configured
       threshold and frequency. If CONFIG_11K, CONFIG_11V, CONFIG_11R or CONFIG_ROAMING enabled then RSSI low event is
       processed internally.*/
    WLAN_REASON_RSSI_LOW,
#ifdef CONFIG_SUBSCRIBE_EVENT_SUPPORT
    /** The WLAN Connection Manager has received subscribed RSSI high event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_RSSI_HIGH,
    /** The WLAN Connection Manager has received subscribed SNR low event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_SNR_LOW,
    /** The WLAN Connection Manager has received subscribed SNR high event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_SNR_HIGH,
    /** The WLAN Connection Manager has received subscribed Max fail event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_MAX_FAIL,
    /** The WLAN Connection Manager has received subscribed Beacon missed fail event on station interface as per
       configured threshold and frequency. */
    WLAN_REASON_BEACON_MISSED,
    /** The WLAN Connection Manager has received subscribed Data RSSI low event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_DATA_RSSI_LOW,
    /** The WLAN Connection Manager has received subscribed Data RSSI high event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_DATA_RSSI_HIGH,
    /** The WLAN Connection Manager has received subscribed Data SNR low event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_DATA_SNR_LOW,
    /** The WLAN Connection Manager has received subscribed Data SNR high event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_DATA_SNR_HIGH,
    /** The WLAN Connection Manager has received subscribed LINK QUALITY event on station interface as per configured
    link_snr threshold and frequency, link_rate threshold and frequency, link_tx_latency threshold and frequency*/
    WLAN_REASON_LINK_QUALITY,
    /** The WLAN Connection Manager has received subscribed Pre beacon lost event on station interface as per configured
       threshold and frequency. */
    WLAN_REASON_PRE_BEACON_LOST,
#endif
#ifdef CONFIG_NCP_BRIDGE
    /** Scan is done */
    WLAN_REASON_SCAN_DONE,
    /** WPS session is done */
    WLAN_REASON_WPS_SESSION_DONE,
#endif
};

/** Wakeup events for which wakeup will occur */
enum wlan_wakeup_event_t
{
    /** Wakeup on broadcast  */
    WAKE_ON_ALL_BROADCAST = 1,
    /** Wakeup on unicast  */
    WAKE_ON_UNICAST = 1 << 1,
    /** Wakeup on MAC event  */
    WAKE_ON_MAC_EVENT = 1 << 2,
    /** Wakeup on multicast  */
    WAKE_ON_MULTICAST = 1 << 3,
    /** Wakeup on ARP broadcast  */
    WAKE_ON_ARP_BROADCAST = 1 << 4,
    /** Wakeup on receiving a management frame  */
    WAKE_ON_MGMT_FRAME = 1 << 6,
};

/** WLAN station/micro-AP/Wi-Fi Direct Connection/Status state */
enum wlan_connection_state
{
    /** The WLAN Connection Manager is not connected and no connection attempt
     *  is in progress.  It is possible to connect to a network or scan. */
    WLAN_DISCONNECTED,
    /** The WLAN Connection Manager is not connected but it is currently
     *  attempting to connect to a network.  It is not possible to scan at this
     *  time.  It is possible to connect to a different network. */
    WLAN_CONNECTING,
    /** The WLAN Connection Manager is not connected but associated. */
    WLAN_ASSOCIATED,
    /** The WLAN Connection Manager is not connected but authenticated. */
    WLAN_AUTHENTICATED,
    /** The WLAN Connection Manager is connected.  It is possible to scan and
     *  connect to another network at this time.  Information about the current
     *  network configuration is available. */
    WLAN_CONNECTED,
    /** The WLAN Connection Manager has started uAP */
    WLAN_UAP_STARTED,
    /** The WLAN Connection Manager has stopped uAP */
    WLAN_UAP_STOPPED,
    /** The WLAN Connection Manager is not connected and network scan
     * is in progress. */
    WLAN_SCANNING,
    /** The WLAN Connection Manager is not connected and network association
     * is in progress. */
    WLAN_ASSOCIATING,
};

/* Data Structures */

/** Station Power save mode */
typedef enum wlan_ps_mode
{
    /** Active mode */
    WLAN_ACTIVE = 0,
    /** IEEE power save mode */
    WLAN_IEEE,
    /** Deep sleep power save mode */
    WLAN_DEEP_SLEEP,
    /** IEEE and Deep sleep power save mode */
    WLAN_IEEE_DEEP_SLEEP,
    /** WNM power save mode */
    WLAN_WNM,
    /** WNM and Deep sleep power save mode */
    WLAN_WNM_DEEP_SLEEP,
} wlan_ps_mode;

enum wlan_ps_state
{
    PS_STATE_AWAKE = 0,
    PS_STATE_PRE_SLEEP,
    PS_STATE_SLEEP_CFM,
    PS_STATE_SLEEP
};

typedef enum _ENH_PS_MODES
{
    GET_PS        = 0,
    SLEEP_CONFIRM = 5,
    EXT_PS_PARAM  = 6,
    DIS_WNM_PS = 0xfc,
    EN_WNM_PS  = 0xfd,
    DIS_AUTO_PS = 0xfe,
    EN_AUTO_PS  = 0xff,
} ENH_PS_MODES;

typedef enum _Host_Sleep_Action
{
    HS_CONFIGURE = 0x0001,
    HS_ACTIVATE  = 0x0002,
} Host_Sleep_Action;

typedef PACK_START struct
{
    uint8_t action;
    uint8_t result;
} PACK_END wnm_sleep_result_t;

#ifdef CONFIG_CSI
enum wlan_csi_opt
{
    CSI_FILTER_OPT_ADD = 0,
    CSI_FILTER_OPT_DELETE,
    CSI_FILTER_OPT_CLEAR,
    CSI_FILTER_OPT_DUMP,
};
#endif

enum wlan_monitor_opt
{
    MONITOR_FILTER_OPT_ADD_MAC = 0,
    MONITOR_FILTER_OPT_DELETE_MAC,
    MONITOR_FILTER_OPT_CLEAR_MAC,
    MONITOR_FILTER_OPT_DUMP,
};


/** Scan Result */
struct wlan_scan_result
{
    /** The network SSID, represented as a NULL-terminated C string of 0 to 32
     *  characters.  If the network has a hidden SSID, this will be the empty
     *  string.
     */
    char ssid[33];
    /** SSID length */
    unsigned int ssid_len;
    /** The network BSSID, represented as a 6-byte array. */
    char bssid[6];
    /** The network channel. */
    unsigned int channel;
    /** The network wireless type. */
    enum wlan_bss_type type;
    /** The network wireless mode. */
    enum wlan_bss_role role;

    /* network features */
    /** The network supports 802.11N.  This is set to 0 if the network does not
     *  support 802.11N or if the system does not have 802.11N support enabled. */
    unsigned dot11n : 1;
#ifdef CONFIG_11AC
    /** The network supports 802.11AC.  This is set to 0 if the network does not
     *  support 802.11AC or if the system does not have 802.11AC support enabled. */
    unsigned dot11ac : 1;
#endif
#ifdef CONFIG_11AX
    /** The network supports 802.11AX.  This is set to 0 if the network does not
     *  support 802.11AX or if the system does not have 802.11AX support enabled. */
    unsigned dot11ax : 1;
#endif

    /** The network supports WMM.  This is set to 0 if the network does not
     *  support WMM or if the system does not have WMM support enabled. */
    unsigned wmm : 1;
#if defined(CONFIG_WPA_SUPP_WPS) || defined(CONFIG_WPS2)
    /** The network supports WPS.  This is set to 0 if the network does not
     *  support WPS or if the system does not have WPS support enabled. */
    unsigned wps : 1;
    /** WPS Type PBC/PIN */
    unsigned int wps_session;
#endif
    /** The network uses WEP security. */
    unsigned wep : 1;
    /** The network uses WPA security. */
    unsigned wpa : 1;
    /** The network uses WPA2 security */
    unsigned wpa2 : 1;
    /** The network uses WPA2 SHA256 security */
    unsigned wpa2_sha256 : 1;
#ifdef CONFIG_OWE
    /** The network uses OWE security */
    unsigned owe : 1;
#endif
    /** The network uses WPA3 SAE security */
    unsigned wpa3_sae : 1;
    /** The network uses WPA2 Enterprise security */
    unsigned wpa2_entp : 1;
    /** The network uses WPA2 Enterprise SHA256 security */
    unsigned wpa2_entp_sha256 : 1;
    /** The network uses WPA3 Enterprise SHA256 security */
    unsigned wpa3_1x_sha256 : 1;
    /** The network uses WPA3 Enterprise SHA384 security */
    unsigned wpa3_1x_sha384 : 1;
#ifdef CONFIG_11R
    /** The network uses FT 802.1x security (For internal use only)*/
    unsigned ft_1x : 1;
    /** The network uses FT 892.1x SHA384 security */
    unsigned ft_1x_sha384 : 1;
    /** The network uses FT PSK security (For internal use only)*/
    unsigned ft_psk : 1;
    /** The network uses FT SAE security (For internal use only)*/
    unsigned ft_sae : 1;
#endif
    /** The signal strength of the beacon */
    unsigned char rssi;
    /** The network SSID, represented as a NULL-terminated C string of 0 to 32
     *  characters.  If the network has a hidden SSID, this will be the empty
     *  string.
     */
    char trans_ssid[33];
    /** SSID length */
    unsigned int trans_ssid_len;
    /** The network BSSID, represented as a 6-byte array. */
    char trans_bssid[6];

    /** Beacon Period */
    uint16_t beacon_period;

    /** DTIM Period */
    uint8_t dtim_period;

    /** MFPC bit of AP*/
    t_u8 ap_mfpc;
    /** MFPR bit of AP*/
    t_u8 ap_mfpr;

#ifdef CONFIG_11K
    /** Neigbort report support (For internal use only)*/
    bool neighbor_report_supported;
#endif
#ifdef CONFIG_11V
    /** bss transition support (For internal use only)*/
    bool bss_transition_supported;
#endif
};

typedef enum
{
    Band_2_4_GHz = 0,
    Band_5_GHz   = 1,
    Band_4_GHz   = 2,

} ChanBand_e;

#define NUM_CHAN_BAND_ENUMS 3

typedef enum
{
    ChanWidth_20_MHz = 0,
    ChanWidth_10_MHz = 1,
    ChanWidth_40_MHz = 2,
    ChanWidth_80_MHz = 3,
} ChanWidth_e;

typedef enum
{
    SECONDARY_CHAN_NONE  = 0,
    SECONDARY_CHAN_ABOVE = 1,
    SECONDARY_CHAN_BELOW = 3,
    // reserved 2, 4~255
} Chan2Offset_e;

typedef enum
{
    MANUAL_MODE = 0,
    ACS_MODE    = 1,
} ScanMode_e;

typedef PACK_START struct
{
    ChanBand_e chanBand : 2;
    ChanWidth_e chanWidth : 2;
    Chan2Offset_e chan2Offset : 2;
    ScanMode_e scanMode : 2;
} PACK_END BandConfig_t;

typedef PACK_START struct
{
    BandConfig_t bandConfig;
    uint8_t chanNum;

} PACK_END ChanBandInfo_t;


#ifdef CONFIG_5GHz_SUPPORT
#define DFS_REC_HDR_LEN (8)
#define DFS_REC_HDR_NUM (10)
#define BIN_COUNTER_LEN (7)

typedef PACK_START struct _Event_Radar_Detected_Info
{
    t_u32 detect_count;
    t_u8 reg_domain;    /*1=fcc, 2=etsi, 3=mic*/
    t_u8 main_det_type; /*0=none, 1=pw(chirp), 2=pri(radar)*/
    t_u16 pw_chirp_type;
    t_u8 pw_chirp_idx;
    t_u8 pw_value;
    t_u8 pri_radar_type;
    t_u8 pri_binCnt;
    t_u8 binCounter[BIN_COUNTER_LEN];
    t_u8 numDfsRecords;
    t_u8 dfsRecordHdrs[DFS_REC_HDR_NUM][DFS_REC_HDR_LEN];
    t_u32 reallyPassed;
} PACK_END Event_Radar_Detected_Info;
#endif

/** Network security types*/
enum wlan_security_type
{
    /** The network does not use security. */
    WLAN_SECURITY_NONE,
    /** The network uses WEP security with open key. */
    WLAN_SECURITY_WEP_OPEN,
    /** The network uses WEP security with shared key. */
    WLAN_SECURITY_WEP_SHARED,
    /** The network uses WPA security with PSK. */
    WLAN_SECURITY_WPA,
    /** The network uses WPA2 security with PSK. */
    WLAN_SECURITY_WPA2,
    /** The network uses WPA/WPA2 mixed security with PSK */
    WLAN_SECURITY_WPA_WPA2_MIXED,
#ifdef CONFIG_11R
    /** The network uses WPA2 security with PSK FT. */
    WLAN_SECURITY_WPA2_FT,
#endif
    /** The network uses WPA3 security with SAE. */
    WLAN_SECURITY_WPA3_SAE,
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
    /** The network uses WPA3 security with SAE FT. */
    WLAN_SECURITY_WPA3_FT_SAE,
#endif
#endif
    /** The network uses WPA2/WPA3 SAE mixed security with PSK. */
    WLAN_SECURITY_WPA2_WPA3_SAE_MIXED,
#ifdef CONFIG_OWE
    /** The network uses OWE only security without Transition mode support. */
    WLAN_SECURITY_OWE_ONLY,
#endif
#if defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE) || defined(CONFIG_WPA2_ENTP)
    /** The network uses WPA2 Enterprise EAP-TLS security
     * The identity field in \ref wlan_network structure is used */
    WLAN_SECURITY_EAP_TLS,
#endif
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_TLS
    /** The network uses WPA2 Enterprise EAP-TLS SHA256 security
     * The identity field in \ref wlan_network structure is used */
    WLAN_SECURITY_EAP_TLS_SHA256,
#ifdef CONFIG_11R
    /** The network uses WPA2 Enterprise EAP-TLS FT security
     * The identity field in \ref wlan_network structure is used */
    WLAN_SECURITY_EAP_TLS_FT,
    /** The network uses WPA2 Enterprise EAP-TLS FT SHA384 security
     * The identity field in \ref wlan_network structure is used */
    WLAN_SECURITY_EAP_TLS_FT_SHA384,
#endif
#endif
#ifdef CONFIG_EAP_TTLS
    /** The network uses WPA2 Enterprise EAP-TTLS security
     * The identity field in \ref wlan_network structure is used */
    WLAN_SECURITY_EAP_TTLS,
#ifdef CONFIG_EAP_MSCHAPV2
    /** The network uses WPA2 Enterprise EAP-TTLS-MSCHAPV2 security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_TTLS_MSCHAPV2,
#endif
#endif
#endif
#if defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE) || defined(CONFIG_PEAP_MSCHAPV2) || defined(CONFIG_WPA2_ENTP)
    /** The network uses WPA2 Enterprise EAP-PEAP-MSCHAPV2 security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_PEAP_MSCHAPV2,
#endif
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_PEAP
#ifdef CONFIG_EAP_TLS
    /** The network uses WPA2 Enterprise EAP-PEAP-TLS security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_PEAP_TLS,
#endif
#ifdef CONFIG_EAP_GTC
    /** The network uses WPA2 Enterprise EAP-PEAP-GTC security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_PEAP_GTC,
#endif
#endif
#ifdef CONFIG_EAP_FAST
#ifdef CONFIG_EAP_MSCHAPV2
    /** The network uses WPA2 Enterprise EAP-FAST-MSCHAPV2 security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_FAST_MSCHAPV2,
#endif
#ifdef CONFIG_EAP_GTC
    /** The network uses WPA2 Enterprise EAP-FAST-GTC security
     * The anonymous identity, identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_FAST_GTC,
#endif
#endif
#ifdef CONFIG_EAP_SIM
    /** The network uses WPA2 Enterprise EAP-SIM security
     * The identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_SIM,
#endif
#ifdef CONFIG_EAP_AKA
    /** The network uses WPA2 Enterprise EAP-AKA security
     * The identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_AKA,
#endif
#ifdef CONFIG_EAP_AKA_PRIME
    /** The network uses WPA2 Enterprise EAP-AKA-PRIME security
     * The identity and password fields in
     * \ref wlan_network structure are used */
    WLAN_SECURITY_EAP_AKA_PRIME,
#endif
#endif
#ifdef CONFIG_WPA_SUPP_DPP
    /** The network uses DPP security with NAK(Net Access Key) */
    WLAN_SECURITY_DPP,
#endif
    /** The network can use any security method. This is often used when
     * the user only knows the name and passphrase but not the security
     * type.  */
    WLAN_SECURITY_WILDCARD,
};

#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_TLS
/** EAP TLS Cipher types*/
enum eap_tls_cipher_type
{
    EAP_TLS_NONE,
    /** EAP TLS with ECDH & ECDSA with p384 */
    EAP_TLS_ECC_P384,
    /** EAP TLS with ECDH & RSA with > 3K */
    EAP_TLS_RSA_3K,
};
#endif
#endif

/** Wlan Cipher structure */
struct wlan_cipher
{
    /** 1 bit value can be set for none */
    uint16_t none : 1;
    /** 1 bit value can be set for wep40 */
    uint16_t wep40 : 1;
    /** 1 bit value can be set for wep104 */
    uint16_t wep104 : 1;
    /** 1 bit value can be set for tkip */
    uint16_t tkip : 1;
    /** 1 bit valuecan be set for ccmp */
    uint16_t ccmp : 1;
    /**  1 bit valuecan be set for aes 128 cmac */
    uint16_t aes_128_cmac : 1;
    /** 1 bit value can be set for gcmp */
    uint16_t gcmp : 1;
    /** 1 bit value can be set for sms4 */
    uint16_t sms4 : 1;
    /** 1 bit value can be set for gcmp 256 */
    uint16_t gcmp_256 : 1;
    /** 1 bit valuecan be set for ccmp 256 */
    uint16_t ccmp_256 : 1;
    /** 1 bit is reserved */
    uint16_t rsvd : 1;
    /** 1 bit value can be set for bip gmac 128 */
    uint16_t bip_gmac_128 : 1;
    /** 1 bit value can be set for bip gmac 256 */
    uint16_t bip_gmac_256 : 1;
    /** 1 bit value can be set for bip cmac 256 */
    uint16_t bip_cmac_256 : 1;
    /** 1 bit valuecan be set for gtk not used */
    uint16_t gtk_not_used : 1;
    /** 4 bits are reserved */
    uint16_t rsvd2 : 2;
};

static inline int is_valid_security(int security)
{
    /*Currently only these modes are supported */
    if ((security == WLAN_SECURITY_NONE) || (security == WLAN_SECURITY_WEP_OPEN) || (security == WLAN_SECURITY_WPA) ||
        (security == WLAN_SECURITY_WPA2) ||
#ifdef CONFIG_11R
        (security == WLAN_SECURITY_WPA2_FT) ||
#endif
        (security == WLAN_SECURITY_WPA_WPA2_MIXED) ||
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
#ifdef CONFIG_EAP_TLS
        (security == WLAN_SECURITY_EAP_TLS) || (security == WLAN_SECURITY_EAP_TLS_SHA256) ||
#ifdef CONFIG_11R
        (security == WLAN_SECURITY_EAP_TLS_FT) || (security == WLAN_SECURITY_EAP_TLS_FT_SHA384) ||
#endif
#endif
#ifdef CONFIG_EAP_TTLS
        (security == WLAN_SECURITY_EAP_TTLS) ||
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_TTLS_MSCHAPV2) ||
#endif
#endif
#ifdef CONFIG_EAP_PEAP
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_PEAP_MSCHAPV2) ||
#endif
#ifdef CONFIG_EAP_TLS
        (security == WLAN_SECURITY_EAP_PEAP_TLS) ||
#endif
#ifdef CONFIG_EAP_GTC
        (security == WLAN_SECURITY_EAP_PEAP_GTC) ||
#endif
#endif
#ifdef CONFIG_EAP_FAST
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_FAST_MSCHAPV2) ||
#endif
#ifdef CONFIG_EAP_GTC
        (security == WLAN_SECURITY_EAP_FAST_GTC) ||
#endif
#endif
#ifdef CONFIG_EAP_SIM
        (security == WLAN_SECURITY_EAP_SIM) ||
#endif
#ifdef CONFIG_EAP_AKA
        (security == WLAN_SECURITY_EAP_AKA) ||
#endif
#ifdef CONFIG_EAP_AKA_PRIME
        (security == WLAN_SECURITY_EAP_AKA_PRIME) ||
#endif
#else
#ifdef CONFIG_WPA2_ENTP
        (security == WLAN_SECURITY_EAP_TLS) ||
#endif
#ifdef CONFIG_PEAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_PEAP_MSCHAPV2) ||
#endif
#endif /* CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE */
#ifdef CONFIG_OWE
        (security == WLAN_SECURITY_OWE_ONLY) ||
#endif
        (security == WLAN_SECURITY_WPA3_SAE) || (security == WLAN_SECURITY_WPA2_WPA3_SAE_MIXED) ||
#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11R
        (security == WLAN_SECURITY_WPA3_FT_SAE) ||
#endif
#endif
        (security == WLAN_SECURITY_WILDCARD))
    {
        return 1;
    }
    return 0;
}

#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
static inline int is_ep_valid_security(int security)
{
    /*Currently only these modes are supported */
    if (
#ifdef CONFIG_EAP_TLS
        (security == WLAN_SECURITY_EAP_TLS) || (security == WLAN_SECURITY_EAP_TLS_SHA256) ||
#ifdef CONFIG_11R
        (security == WLAN_SECURITY_EAP_TLS_FT) || (security == WLAN_SECURITY_EAP_TLS_FT_SHA384) ||
#endif
#endif
#ifdef CONFIG_EAP_TTLS
        (security == WLAN_SECURITY_EAP_TTLS) ||
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_TTLS_MSCHAPV2) ||
#endif
#endif
#ifdef CONFIG_EAP_PEAP
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_PEAP_MSCHAPV2) ||
#endif
#ifdef CONFIG_EAP_TLS
        (security == WLAN_SECURITY_EAP_PEAP_TLS) ||
#endif
#ifdef CONFIG_EAP_GTC
        (security == WLAN_SECURITY_EAP_PEAP_GTC) ||
#endif
#endif
#ifdef CONFIG_EAP_FAST
#ifdef CONFIG_EAP_MSCHAPV2
        (security == WLAN_SECURITY_EAP_FAST_MSCHAPV2) ||
#endif
#ifdef CONFIG_EAP_GTC
        (security == WLAN_SECURITY_EAP_FAST_GTC) ||
#endif
#endif
#ifdef CONFIG_EAP_SIM
        (security == WLAN_SECURITY_EAP_SIM) ||
#endif
#ifdef CONFIG_EAP_AKA
        (security == WLAN_SECURITY_EAP_AKA) ||
#endif
#ifdef CONFIG_EAP_AKA_PRIME
        (security == WLAN_SECURITY_EAP_AKA_PRIME) ||
#endif
        false)
    {
        return 1;
    }
    return 0;
}
#endif

/** Network security configuration */
struct wlan_network_security
{
    /** Type of network security to use specified by enum
     * wlan_security_type. */
    enum wlan_security_type type;
    /** Key management type */
    int key_mgmt;
    /** Type of network security Group Cipher suite used internally*/
    struct wlan_cipher mcstCipher;
    /** Type of network security Pairwise Cipher suite used internally*/
    struct wlan_cipher ucstCipher;
#ifdef CONFIG_WPA_SUPP
    /** Proactive Key Caching */
    unsigned pkc : 1;
    /** Type of network security Group Cipher suite */
    int group_cipher;
    /** Type of network security Pairwise Cipher suite */
    int pairwise_cipher;
    /** Type of network security Pairwise Cipher suite */
    int group_mgmt_cipher;
#endif
    /** Is PMF required */
    bool is_pmf_required;
    /** Pre-shared key (network password).  For WEP networks this is a hex byte
     * sequence of length psk_len, for WPA and WPA2 networks this is an ASCII
     * pass-phrase of length psk_len.  This field is ignored for networks with no
     * security. */
    char psk[WLAN_PSK_MAX_LENGTH];
    /** Length of the WEP key or WPA/WPA2 pass phrase, \ref WLAN_PSK_MIN_LENGTH to \ref
     * WLAN_PSK_MAX_LENGTH.  Ignored for networks with no security. */
    uint8_t psk_len;
    /** WPA3 SAE password, for WPA3 SAE networks this is an ASCII
     * password of length password_len.  This field is ignored for networks with no
     * security. */
    char password[WLAN_PASSWORD_MAX_LENGTH + 1];
    /** Length of the WPA3 SAE Password, \ref WLAN_PASSWORD_MIN_LENGTH to \ref
     * WLAN_PASSWORD_MAX_LENGTH.  Ignored for networks with no security. */
    size_t password_len;
    /** SAE Groups */
    char *sae_groups;
    /** PWE derivation */
    uint8_t pwe_derivation;
    /** transition disable */
    uint8_t transition_disable;
#ifdef CONFIG_OWE
    /** OWE Groups */
    char *owe_groups;
#endif
    /** Pairwise Master Key.  When pmk_valid is set, this is the PMK calculated
     * from the PSK for WPA/PSK networks.  If pmk_valid is not set, this field
     * is not valid.  When adding networks with \ref wlan_add_network, users
     * can initialize pmk and set pmk_valid in lieu of setting the psk.  After
     * successfully connecting to a WPA/PSK network, users can call \ref
     * wlan_get_current_network to inspect pmk_valid and pmk.  Thus, the pmk
     * value can be populated in subsequent calls to \ref wlan_add_network.
     * This saves the CPU time required to otherwise calculate the PMK.
     */
    char pmk[WLAN_PMK_LENGTH];

    /** Flag reporting whether pmk is valid or not. */
    bool pmk_valid;
    /** Management Frame Protection Capable (MFPC) */
    bool mfpc;
    /** Management Frame Protection Required (MFPR) */
    bool mfpr;
#ifdef CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE
    /** WPA3 Enterprise mode */
    unsigned wpa3_sb : 1;
    /** WPA3 Enterprise Suite B 192 mode */
    unsigned wpa3_sb_192 : 1;
#ifdef CONFIG_EAP_PEAP
    /** PEAP version */
    unsigned eap_ver : 1;
    /** PEAP label */
    unsigned peap_label : 1;
    /** crypto_binding option can be used to control \ref WLAN_SECURITY_EAP_PEAP_MSCHAPV2, \ref
     * WLAN_SECURITY_EAP_PEAP_TLS and \ref WLAN_SECURITY_EAP_PEAP_GTC version 0 cryptobinding behavior: 0 = do not use
     * cryptobinding (default) 1 = use cryptobinding if server supports it 2 = require cryptobinding */
    uint8_t eap_crypto_binding;
#endif
#if defined(CONFIG_EAP_SIM) || defined(CONFIG_EAP_AKA) || defined(CONFIG_EAP_AKA_PRIME)
    /** eap_result_ind=1 can be used to enable \ref WLAN_SECURITY_EAP_SIM, \ref WLAN_SECURITY_EAP_AKA and \ref
     * WLAN_SECURITY_EAP_AKA_PRIME to use protected result indication.*/
    unsigned eap_result_ind : 1;
#endif
#ifdef CONFIG_EAP_TLS
    /** Cipher for EAP TLS */
    unsigned char tls_cipher;
#endif
    /** Identity string for EAP */
    char identity[IDENTITY_MAX_LENGTH];
    /** Anonymous identity string for EAP */
    char anonymous_identity[IDENTITY_MAX_LENGTH];
    /** Password string for EAP. This field can include
     * either the plaintext password (using ASCII or
     * hex string) */
    char eap_password[PASSWORD_MAX_LENGTH];
    /** CA cert blob in PEM/DER format */
    unsigned char *ca_cert_data;
    /** CA cert blob len */
    size_t ca_cert_len;
    /** Client cert blob in PEM/DER format */
    unsigned char *client_cert_data;
    /** Client cert blob len */
    size_t client_cert_len;
    /** Client key blob */
    unsigned char *client_key_data;
    /** Client key blob len */
    size_t client_key_len;
    /** Client key password */
    char client_key_passwd[PASSWORD_MAX_LENGTH];
    /** CA cert HASH */
    char ca_cert_hash[HASH_MAX_LENGTH];
    /** Domain */
    char domain_match[DOMAIN_MATCH_MAX_LENGTH];
    /** Domain Suffix */
    char domain_suffix_match[DOMAIN_MATCH_MAX_LENGTH]; /*suffix max length same as full domain name length*/
    /** CA cert2 blob in PEM/DER format */
    unsigned char *ca_cert2_data;
    /** CA cert2 blob len */
    size_t ca_cert2_len;
    /** Client cert2 blob in PEM/DER format */
    unsigned char *client_cert2_data;
    /** Client cert2 blob len */
    size_t client_cert2_len;
    /** Client key2 blob */
    unsigned char *client_key2_data;
    /** Client key2 blob len */
    size_t client_key2_len;
    /** Client key2 password */
    char client_key2_passwd[PASSWORD_MAX_LENGTH];
#ifdef CONFIG_HOSTAPD
#ifdef CONFIG_WPA_SUPP_CRYPTO_AP_ENTERPRISE
    /** DH params blob */
    unsigned char *dh_data;
    /** DH params blob len */
    size_t dh_len;
    /** Server cert blob in PEM/DER format */
    unsigned char *server_cert_data;
    /** Server cert blob len */
    size_t server_cert_len;
    /** Server key blob */
    unsigned char *server_key_data;
    /** Server key blob len */
    size_t server_key_len;
    /** Server key password */
    char server_key_passwd[PASSWORD_MAX_LENGTH];
    /** Number of EAP users */
    size_t nusers;
    /** User Identities */
    char identities[MAX_USERS][IDENTITY_MAX_LENGTH];
    /** User Passwords */
    char passwords[MAX_USERS][PASSWORD_MAX_LENGTH];
#ifdef CONFIG_EAP_FAST
    /** Encryption key for EAP-FAST PAC-Opaque values */
    char pac_opaque_encr_key[PAC_OPAQUE_ENCR_KEY_MAX_LENGTH];
    /** EAP-FAST authority identity (A-ID) */
    char a_id[A_ID_MAX_LENGTH];
    /** EAP-FAST provisioning modes:
     * 0 = provisioning disabled
     * 1 = only anonymous provisioning allowed
     * 2 = only authenticated provisioning allowed
     * 3 = both provisioning modes allowed (default)
     */
    uint8_t fast_prov;
#endif
#endif
#endif
#elif defined(CONFIG_WPA2_ENTP)
    /** TLS client cert configuration */
    wm_mbedtls_cert_t tls_cert;
    /** mbedtls_ssl_config handle */
    mbedtls_ssl_config *wlan_ctx;
    /** mbedtls_ssl_context handle */
    mbedtls_ssl_context *wlan_ssl;
#endif
#ifdef CONFIG_WPA_SUPP_DPP
    unsigned char *dpp_connector;
    unsigned char *dpp_c_sign_key;
    unsigned char *dpp_net_access_key;
#endif
};

/* Configuration for wireless scanning */
#define MAX_CHANNEL_LIST 6
struct wifi_scan_params_t
{
    uint8_t *bssid;
    char *ssid;
    int channel[MAX_CHANNEL_LIST];
    IEEEtypes_Bss_t bss_type;
    int scan_duration;
    int split_scan_delay;
};

#ifdef CONFIG_WIFI_GET_LOG
/** Wi-Fi firmware stat from \ref wifi_pkt_stats_t
 */
typedef wifi_pkt_stats_t wlan_pkt_stats_t;
#endif

/** Configuration for Wireless scan channel list from
 * \ref wifi_scan_channel_list_t
 */
typedef wifi_scan_channel_list_t wlan_scan_channel_list_t;
/** Configuration for wireless scanning parameters v2 from
 * \ref wifi_scan_params_v2_t
 */
typedef wifi_scan_params_v2_t wlan_scan_params_v2_t;


/** Configuration for Wireless Calibration data from
 * \ref wifi_cal_data_t
 */
typedef wifi_cal_data_t wlan_cal_data_t;

#ifdef CONFIG_AUTO_RECONNECT
/** Configuration for Auto reconnect configuration from
 * \ref wifi_auto_reconnect_config_t
 */
typedef wifi_auto_reconnect_config_t wlan_auto_reconnect_config_t;
#endif

/** Configuration for Memory Efficient Filters in Wi-Fi firmware from
 * \ref wifi_flt_cfg_t
 */
typedef wifi_flt_cfg_t wlan_flt_cfg_t;

/** Configuration for wowlan pattern parameters from
 * \ref wifi_wowlan_ptn_cfg_t
 */
typedef wifi_wowlan_ptn_cfg_t wlan_wowlan_ptn_cfg_t;
/** Configuration for TCP Keep alive parameters from
 * \ref wifi_tcp_keep_alive_t
 */
typedef wifi_tcp_keep_alive_t wlan_tcp_keep_alive_t;

#ifdef CONFIG_CLOUD_KEEP_ALIVE
/** Configuration for Cloud Keep alive parameters from
 * \ref wifi_cloud_keep_alive_t
 */
typedef wifi_cloud_keep_alive_t wlan_cloud_keep_alive_t;
#endif

/** Configuration for TX Rate and Get data rate from
 * \ref wifi_ds_rate
 */
typedef wifi_ds_rate wlan_ds_rate;
/** Configuration for ED MAC Control parameters from
 * \ref wifi_ed_mac_ctrl_t
 */
typedef wifi_ed_mac_ctrl_t wlan_ed_mac_ctrl_t;
/** Configuration for Band from
 * \ref wifi_bandcfg_t
 */
typedef wifi_bandcfg_t wlan_bandcfg_t;
/** Configuration for CW Mode parameters from
 * \ref wifi_cw_mode_ctrl_t
 */
typedef wifi_cw_mode_ctrl_t wlan_cw_mode_ctrl_t;
/** Configuration for Channel list from
 * \ref wifi_chanlist_t
 */
typedef wifi_chanlist_t wlan_chanlist_t;
/** Configuration for TX Pwr Limit from
 * \ref wifi_txpwrlimit_t
 */
typedef wifi_txpwrlimit_t wlan_txpwrlimit_t;
#ifdef SD8801
/** Statistic of External Coex from
 * \ref wifi_ext_coex_config_t
 */
typedef wifi_ext_coex_stats_t wlan_ext_coex_stats_t;
/** Configuration for External Coex from
 * \ref wifi_ext_coex_config_t
 */
typedef wifi_ext_coex_config_t wlan_ext_coex_config_t;
#endif

#ifdef CONFIG_11AX
/** Configuration for RU TX Pwr Limit from
 * \ref wifi_rutxpwrlimit_t
 */
typedef wifi_rutxpwrlimit_t wlan_rutxpwrlimit_t;
/** Configuration for 11AX capabilities
 * \ref wifi_11ax_config_t
 */
typedef wifi_11ax_config_t wlan_11ax_config_t;
#ifdef CONFIG_11AX_TWT
/** Configuration for TWT Setup
 * \ref wifi_twt_setup_config_t
 */
typedef wifi_twt_setup_config_t wlan_twt_setup_config_t;
/** Configuration for TWT Teardown
 * \ref wifi_twt_teardown_config_t
 */
typedef wifi_twt_teardown_config_t wlan_twt_teardown_config_t;
/** Configuration for Broadcast TWT Setup
 * \ref wifi_btwt_config_t
 */
typedef wifi_btwt_config_t wlan_btwt_config_t;
/** Configuration for TWT Report
 * \ref wifi_twt_report_t
 */
typedef wifi_twt_report_t wlan_twt_report_t;
#endif /* CONFIG_11AX_TWT */
#ifdef CONFIG_MMSF
#define WLAN_AMPDU_DENSITY 0x30
#define WLAN_AMPDU_MMSF    0x6
#endif
#endif
#ifdef CONFIG_WIFI_CLOCKSYNC
/** Configuration for Clock Sync GPIO TSF latch
 * \ref wifi_clock_sync_gpio_tsf_t
 */
typedef wifi_clock_sync_gpio_tsf_t wlan_clock_sync_gpio_tsf_t;
/** Configuration for TSF info
 * \ref wifi_tsf_info_t
 */
typedef wifi_tsf_info_t wlan_tsf_info_t;
#endif

#ifdef CONFIG_MULTI_CHAN
/** Configuration for multi-channel switch
 * \ref wifi_drcs_cfg_t
 */
typedef wifi_drcs_cfg_t wlan_drcs_cfg_t;
#endif

typedef wifi_mgmt_frame_t wlan_mgmt_frame_t;


#ifdef CONFIG_CSI
/** Configuration for Csi Config Params from
 * \ref wifi_csi_config_params_t
 */
typedef wifi_csi_config_params_t wlan_csi_config_params_t;
#endif

#ifdef CONFIG_NET_MONITOR
/** Configuration for Net monitor from
 * \ref wifi_net_monitor_t
 */
typedef wifi_net_monitor_t wlan_net_monitor_t;
#endif

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
/** Configuration for GPIO independent reset
 * \ref wifi_indrst_cfg_t
 */
typedef wifi_indrst_cfg_t wlan_indrst_cfg_t;
#endif

#ifdef CONFIG_11AX
/** Configuration for TX Rate Setting from
 * \ref txrate_setting
 */
typedef txrate_setting wlan_txrate_setting;
#endif

/** Configuration for RSSI information
 * \ref wifi_rssi_info_t
 */
typedef wifi_rssi_info_t wlan_rssi_info_t;

#ifdef CONFIG_EXTERNAL_COEX_PTA
#define MIN_SAMP_TIMING              20
#define MAX_SAMP_TIMING              200
#define COEX_PTA_FEATURE_ENABLE      1
#define COEX_PTA_FEATURE_DISABLE     0
#define POL_GRANT_PIN_HIGH           0
#define POL_GRANT_PIN_LOW            1
#define STATE_INPUT_DISABLE          0
#define STATE_PTA_PIN                1
#define STATE_PRIORITY_PIN           2
#define SAMPLE_TIMING_VALUE          100
#define EXT_COEX_PTA_INTERFACE       5
#define EXT_COEX_WCI2_INTERFACE      6
#define EXT_COEX_WCI2_GPIO_INTERFACE 7

typedef struct _external_coex_pta_cfg
{
    /** Enable: 0x01, Disable: 0x00 */
    t_u8 enabled;
    /** Enable ExtWifiBtArb: 0x01, Disable ExWifiBtArb: 0x00 */
    t_u8 ext_WifiBtArb;
    /** Active high: 0x00, Active low: 0x01 */
    t_u8 polGrantPin;
    /**  Enable PriPtaInt: 0x01, Disable PriPtaInt: 0x00 */
    t_u8 enable_PriPtaInt;
    /** State input disable: 0x00, State info is from state pin: 0x01, State info is sampled on priority pin: 0x02 */
    t_u8 enable_StatusFromPta;
    /** Timing to sample Priority bit */
    t_u16 setPriSampTiming;
    /** Timing to sample Tx/Rx info */
    t_u16 setStateInfoSampTiming;
    /** Enable external traffic Tx/Rx Priority: 0x01, Disable external traffic Tx/Rx Priority: 0x00 */
    t_u8 extRadioTrafficPrio;
    /** Enable wci-2 interface: 0x01, Disable wci-2 interface: 0x00 */
    t_u8 extCoexHwIntWci2;
} ext_coex_pta_cfg;
#endif

int verify_scan_duration_value(int scan_duration);
int verify_scan_channel_value(int channel);
int verify_split_scan_delay(int delay);
int set_scan_params(struct wifi_scan_params_t *wifi_scan_params);
int get_scan_params(struct wifi_scan_params_t *wifi_scan_params);
int wlan_get_current_rssi(short *rssi);
int wlan_get_current_nf(void);

/** Address types to be used by the element wlan_ip_config.addr_type below
 */
enum address_types
{
    /** static IP address */
    ADDR_TYPE_STATIC = 0,
    /** Dynamic  IP address*/
    ADDR_TYPE_DHCP = 1,
    /** Link level address */
    ADDR_TYPE_LLA = 2,
};

/** This data structure represents an IPv4 address */
struct ipv4_config
{
    /** Set to \ref ADDR_TYPE_DHCP to use DHCP to obtain the IP address or
     *  \ref ADDR_TYPE_STATIC to use a static IP. In case of static IP
     *  address ip, gw, netmask and dns members must be specified.  When
     *  using DHCP, the ip, gw, netmask and dns are overwritten by the
     *  values obtained from the DHCP server. They should be zeroed out if
     *  not used. */
    enum address_types addr_type;
    /** The system's IP address in network order. */
    unsigned address;
    /** The system's default gateway in network order. */
    unsigned gw;
    /** The system's subnet mask in network order. */
    unsigned netmask;
    /** The system's primary dns server in network order. */
    unsigned dns1;
    /** The system's secondary dns server in network order. */
    unsigned dns2;
};

#ifdef CONFIG_IPV6
/** This data structure represents an IPv6 address */
struct ipv6_config
{
    /** The system's IPv6 address in network order. */
    unsigned address[4];
    /** The address type: linklocal, site-local or global. */
    unsigned char addr_type;
    /** The state of IPv6 address (Tentative, Preferred, etc). */
    unsigned char addr_state;
};
#endif

/** Network IP configuration.
 *
 *  This data structure represents the network IP configuration
 *  for IPv4 as well as IPv6 addresses
 */
struct wlan_ip_config
{
#ifdef CONFIG_IPV6
    /** The network IPv6 address configuration that should be
     * associated with this interface. */
    struct ipv6_config ipv6[CONFIG_MAX_IPV6_ADDRESSES];
    /** The network IPv6 valid addresses count */
    size_t ipv6_count;
#endif
    /** The network IPv4 address configuration that should be
     * associated with this interface. */
    struct ipv4_config ipv4;
};

/** WLAN Network Profile
 *
 *  This data structure represents a WLAN network profile. It consists of an
 *  arbitrary name, WiFi configuration, and IP address configuration.
 *
 *  Every network profile is associated with one of the two interfaces. The
 *  network profile can be used for the station interface (i.e. to connect to an
 *  Access Point) by setting the role field to \ref
 *  WLAN_BSS_ROLE_STA. The network profile can be used for the micro-AP
 *  interface (i.e. to start a network of our own.) by setting the mode field to
 *  \ref WLAN_BSS_ROLE_UAP.
 *
 *  If the mode field is \ref WLAN_BSS_ROLE_STA, either of the SSID or
 *  BSSID fields are used to identify the network, while the other members like
 *  channel and security settings characterize the network.
 *
 *  If the mode field is \ref WLAN_BSS_ROLE_UAP, the SSID, channel and security
 *  fields are used to define the network to be started.
 *
 *  In both the above cases, the address field is used to determine the type of
 *  address assignment to be used for this interface.
 */
struct wlan_network
{
#ifdef CONFIG_WPA_SUPP
    /** Identifier for network profile */
    int id;
    /* wps_network marks the network is for wps*/
    int wps_network;
#endif
    /** The name of this network profile.  Each network profile that is
     *  added to the WLAN Connection Manager must have a unique name. */
    char name[WLAN_NETWORK_NAME_MAX_LENGTH + 1];
    /** The network SSID, represented as a C string of up to 32 characters
     *  in length.
     *  If this profile is used in the micro-AP mode, this field is
     *  used as the SSID of the network.
     *  If this profile is used in the station mode, this field is
     *  used to identify the network. Set the first byte of the SSID to NULL
     *  (a 0-length string) to use only the BSSID to find the network.
     */
    char ssid[IEEEtypes_SSID_SIZE + 1];
    /** The network BSSID, represented as a 6-byte array.
     *  If this profile is used in the micro-AP mode, this field is
     *  ignored.
     *  If this profile is used in the station mode, this field is
     *  used to identify the network. Set all 6 bytes to 0 to use any BSSID,
     *  in which case only the SSID will be used to find the network.
     */
    char bssid[IEEEtypes_ADDRESS_SIZE];
    /** The channel for this network.
     *
     *  If this profile is used in micro-AP mode, this field
     *  specifies the channel to start the micro-AP interface on. Set this
     *  to 0 for auto channel selection.
     *
     *  If this profile is used in the station mode, this constrains the
     *  channel on which the network to connect should be present. Set this
     *  to 0 to allow the network to be found on any channel. */
    unsigned int channel;
    /** The secondary channel offset **/
    uint8_t sec_channel_offset;
    /** The ACS band if set channel to 0. **/
    uint16_t acs_band;
    /** RSSI */
    int rssi;
#ifdef CONFIG_SCAN_WITH_RSSIFILTER
    /** Rssi threshold */
    short rssi_threshold;
#endif
#ifdef CONFIG_WPA_SUPP
    /** HT capabilities */
    unsigned short ht_capab;
#ifdef CONFIG_11AC
    /** VHT capabilities */
    unsigned int vht_capab;
    /** VHT bandwidth */
    unsigned char vht_oper_chwidth;
#endif
#ifdef CONFIG_11AX
    /** HE bandwidth */
    unsigned char he_oper_chwidth;
#endif
#endif
    /** BSS type */
    enum wlan_bss_type type;
    /** The network wireless mode enum wlan_bss_role. Set this
     *  to specify what type of wireless network mode to use.
     *  This can either be \ref WLAN_BSS_ROLE_STA for use in
     *  the station mode, or it can be \ref WLAN_BSS_ROLE_UAP
     *  for use in the micro-AP mode. */
    enum wlan_bss_role role;
    /** The network security configuration specified by struct
     * wlan_network_security for the network. */
    struct wlan_network_security security;
    /** The network IP address configuration specified by struct
     * wlan_ip_config that should be associated with this interface. */
    struct wlan_ip_config ip;
#ifdef CONFIG_WPA2_ENTP
    char identity[IDENTITY_MAX_LENGTH];
#ifdef CONFIG_PEAP_MSCHAPV2
    char anonymous_identity[IDENTITY_MAX_LENGTH];
    char password[PASSWORD_MAX_LENGTH];
#endif
#endif

    /* Private Fields */

    /**
     * If set to 1, the ssid field contains the specific SSID for this
     * network.
     * The WLAN Connection Manager will only connect to networks whose SSID
     * matches.  If set to 0, the ssid field contents are not used when
     * deciding whether to connect to a network, the BSSID field is used
     * instead and any network whose BSSID matches is accepted.
     *
     * This field will be set to 1 if the network is added with the SSID
     * specified (not an empty string), otherwise it is set to 0.
     */
    unsigned ssid_specific : 1;
#ifdef CONFIG_OWE
    /**
     * If set to 1, the ssid field contains the transitional SSID for this
     * network.
     */
    unsigned trans_ssid_specific : 1;
#endif
    /** If set to 1, the bssid field contains the specific BSSID for this
     *  network.  The WLAN Connection Manager will not connect to any other
     *  network with the same SSID unless the BSSID matches.  If set to 0, the
     *  WLAN Connection Manager will connect to any network whose SSID matches.
     *
     *  This field will be set to 1 if the network is added with the BSSID
     *  specified (not set to all zeroes), otherwise it is set to 0. */
    unsigned bssid_specific : 1;
    /**
     * If set to 1, the channel field contains the specific channel for this
     * network.  The WLAN Connection Manager will not look for this network on
     * any other channel.  If set to 0, the WLAN Connection Manager will look
     * for this network on any available channel.
     *
     * This field will be set to 1 if the network is added with the channel
     * specified (not set to 0), otherwise it is set to 0. */
    unsigned channel_specific : 1;
    /**
     * If set to 0, any security that matches is used. This field is
     * internally set when the security type parameter above is set to
     * WLAN_SECURITY_WILDCARD.
     */
    unsigned security_specific : 1;
#ifdef CONFIG_WPS2
    /** This indicates this network is used as an internal network for
     * WPS */
    unsigned wps_specific : 1;
#endif

    /** The network supports 802.11N. (For internal use only) */
    unsigned dot11n : 1;
#ifdef CONFIG_11AC
    /** The network supports 802.11AC. (For internal use only) */
    unsigned dot11ac : 1;
#endif
#ifdef CONFIG_11AX
    /** The network supports 802.11AX. (For internal use only) */
    unsigned dot11ax : 1;
#endif

#ifdef CONFIG_11R
    /** Mobility Domain ID */
    uint16_t mdid;
    /** The network uses FT 802.1x security (For internal use only)*/
    unsigned ft_1x : 1;
    /** The network uses FT PSK security (For internal use only)*/
    unsigned ft_psk : 1;
    /** The network uses FT SAE security (For internal use only)*/
    unsigned ft_sae : 1;
#endif
#ifdef CONFIG_OWE
    /** OWE Transition mode */
    unsigned int owe_trans_mode;
    /** The network transitional SSID, represented as a C string of up to 32 characters
     *  in length.
     *
     * This field is used internally.
     */
    char trans_ssid[IEEEtypes_SSID_SIZE + 1];
    /** Transitional SSID length
     *
     * This field is used internally.
     */
    unsigned int trans_ssid_len;
#endif
    /** Beacon period of associated BSS */
    uint16_t beacon_period;
    /** DTIM period of associated BSS */
    uint8_t dtim_period;
    /** Wireless capabilities of uAP network 802.11n, 802.11ac or/and 802.11ax*/
    uint8_t wlan_capa;
#ifdef CONFIG_11V
    /** BTM mode */
    uint8_t btm_mode;
    /** bss transition support (For internal use only)*/
    bool bss_transition_supported;
#endif
#ifdef CONFIG_11K
    /** Neighbor report support (For internal use only)*/
    bool neighbor_report_supported;
#endif
};

struct wlan_ieeeps_config
{
    /** PS null interval in seconds */
    t_u32 ps_null_interval;
    /** Multiple DTIM interval */
    t_u32 multiple_dtim_interval;
    /** Listen interval */
    t_u32 listen_interval;
    /** Adhoc awake period */
    t_u32 adhoc_awake_period;
    /** Beacon miss timeout in milliseconds */
    t_u32 bcn_miss_timeout;
    /** Delay to PS in milliseconds */
    t_s32 delay_to_ps;
    /** PS mode */
    t_u32 ps_mode;
};

#ifdef CONFIG_WIFI_TX_PER_TRACK
/** Tx Per Tracking Structure
 * Driver sets tx per tracking statistic to fw.
 * Fw will check tx packet error rate periodically and
 * report PER to host if per is high.
 */
struct wlan_tx_pert_info
{
    /** Enable/Disable tx per tracking */
    t_u8 tx_pert_check;
    /** Check period(unit sec) */
    t_u8 tx_pert_check_peroid;
    /** (Fail TX packet)/(Total TX packet) ratio(unit 10%)
     * default: 5
     */
    t_u8 tx_pert_check_ratio;
    /** A watermark of check number(default 5) */
    t_u16 tx_pert_check_num;
};
#endif
#if defined(RW610)
typedef enum
{
    CLI_DISABLE_WIFI,
    CLI_ENABLE_WIFI,
    CLI_RESET_WIFI,
} cli_reset_option;
#endif

#ifdef CONFIG_HOST_SLEEP
enum wlan_hostsleep_event
{
    HOST_SLEEP_HANDSHAKE = 1,
    HOST_SLEEP_EXIT,
};

enum wlan_hostsleep_state
{
    HOST_SLEEP_DISABLE,
    HOST_SLEEP_ONESHOT,
    HOST_SLEEP_PERIODIC,
};

#define WLAN_HOSTSLEEP_SUCCESS    1
#define WLAN_HOSTSLEEP_IN_PROCESS 2
#define WLAN_HOSTSLEEP_FAIL       3
#endif

#ifdef CONFIG_TX_RX_HISTOGRAM
struct wlan_txrx_histogram_info
{
    /**  Enable or disable  */
    t_u8 enable;
    /** Choose to get TX, RX or both */
    t_u16 action;
};

#define FLAG_TX_HISTOGRAM       0x01
#define FLAG_RX_HISTOGRAM       0x02
#define DISABLE_TX_RX_HISTOGRAM 0x00
#define ENABLE_TX_RX_HISTOGRAM  0x01
#define GET_TX_RX_HISTOGRAM     0x02

/** TX histiogram ht statistic parameters */
typedef struct _tx_pkt_ht_rate_info
{
    /** tx packet counter of MCS0~MCS15 */
    t_u32 htmcs_txcnt[16];
    /** tx packet's short GI counter of MCS0~MCS15 */
    t_u32 htsgi_txcnt[16];
    /** tx STBC packet counter of MCS0~MCS15 */
    t_u32 htstbcrate_txcnt[16];
} tx_pkt_ht_rate_info;
/** TX histiogram vht statistic parameters */
typedef struct _tx_pkt_vht_rate_info
{
    /** tx packet counter of MCS0~MCS9 */
    t_u32 vhtmcs_txcnt[10];
    /** tx packet's short GI counter of MCS0~MCS9 */
    t_u32 vhtsgi_txcnt[10];
    /** tx STBC packet counter of MCS0~MCS9 */
    t_u32 vhtstbcrate_txcnt[10];
} tx_pkt_vht_rate_info;
/** TX histiogram he statistic parameters */
typedef struct _tx_pkt_he_rate_info
{
    /** tx packet counter of MCS0~MCS11 */
    t_u32 hemcs_txcnt[12];
    /** tx STBC packet counter of MCS0~MCS11 */
    t_u32 hestbcrate_txcnt[12];
} tx_pkt_he_rate_info;
/** TX histogram statistic parameters*/
typedef struct _tx_pkt_rate_info
{
    /** tx packet counter of every NSS, NSS=1,2 */
    t_u32 nss_txcnt[2];
    /** tx packet counter of every bandwith */
    t_u32 bandwidth_txcnt[3];
    /** different preamble tx packet counter */
    t_u32 preamble_txcnt[4];
    /** tx packet counter of using LDPC coding */
    t_u32 ldpc_txcnt;
    /** transmitted RTS counter */
    t_u32 rts_txcnt;
    /** RSSI of ack */
    t_s32 ack_RSSI;
} tx_pkt_rate_info;
/** RX histiogram ht statistic parameters */
typedef struct _rx_pkt_ht_rate_info
{
    /** Rx packet counter of MCS0~MCS15 */
    t_u32 htmcs_rxcnt[16];
    /** Rx packet's short GI counter of MCS0~MCS15 */
    t_u32 htsgi_rxcnt[16];
    /** Rx STBC packet counter of MCS0~MCS15 */
    t_u32 htstbcrate_rxcnt[16];
} rx_pkt_ht_rate_info;
/** RX histiogram vht statistic parameters */
typedef struct _rx_pkt_vht_rate_info
{
    /** Rx packet counter of MCS0~MCS9 */
    t_u32 vhtmcs_rxcnt[10];
    /** Rx packet's short GI counter of MCS0~MCS9 */
    t_u32 vhtsgi_rxcnt[10];
    /** Rx STBC packet counter of MCS0~MCS9 */
    t_u32 vhtstbcrate_rxcnt[10];
} rx_pkt_vht_rate_info;
/** RX histiogram he statistic parameters */
typedef struct _rx_pkt_he_rate_info
{
    /** Rx packet counter of MCS0~MCS11 */
    t_u32 hemcs_rxcnt[12];
    /** Rx STBC packet counter of MCS0~MCS11 */
    t_u32 hestbcrate_rxcnt[12];
} rx_pkt_he_rate_info;
/** RX histogram statistic parameters*/
typedef struct _rx_pkt_rate_info
{
    /** Rx packet counter of every NSS, NSS=1,2 */
    t_u32 nss_rxcnt[2];
    /** Received packet counter which using STBC */
    t_u32 nsts_rxcnt;
    /** Rx packet counter of every bandwith */
    t_u32 bandwidth_rxcnt[3];
    /** Different preamble Rx packet counter */
    t_u32 preamble_rxcnt[6];
    /** VHT SIGA2 LDPC bit*/
    t_u32 ldpc_txbfcnt[2];
    /**  Average RSSI */
    t_s32 rssi_value[2];
    /** RSSI value of path A */
    t_s32 rssi_chain0[4];
    /** RSSI value of path B */
    t_s32 rssi_chain1[4];
} rx_pkt_rate_info;
#endif

#define TX_AMPDU_RTS_CTS            0
#define TX_AMPDU_CTS_2_SELF         1
#define TX_AMPDU_DISABLE_PROTECTION 2
#define TX_AMPDU_DYNAMIC_RTS_CTS    3

/** tx_ampdu_prot_mode parameters */
typedef struct _tx_ampdu_prot_mode_para
{
    /** set prot mode */
    int mode;
} tx_ampdu_prot_mode_para;

typedef wifi_uap_client_disassoc_t wlan_uap_client_disassoc_t;

#ifdef CONFIG_INACTIVITY_TIMEOUT_EXT
typedef wifi_inactivity_to_t wlan_inactivity_to_t;
#endif

/* WLAN Connection Manager API */

/** Initialize the SDIO driver and create the wifi driver thread.
 *
 * \param[in]  fw_start_addr Start address of the WLAN firmware.
 * \param[in]  size Size of the WLAN firmware.
 *
 * \return WM_SUCCESS if the WLAN Connection Manager service has
 *         initialized successfully.
 * \return Negative value if initialization failed.
 */
int wlan_init(const uint8_t *fw_start_addr, const size_t size);

/** Start the WLAN Connection Manager service.
 *
 * This function starts the WLAN Connection Manager.
 *
 * \note The status of the WLAN Connection Manager is notified asynchronously
 * through the callback, \a cb, with a WLAN_REASON_INITIALIZED event
 * (if initialization succeeded) or WLAN_REASON_INITIALIZATION_FAILED
 * (if initialization failed).
 *
 * \note If the WLAN Connection Manager fails to initialize, the caller should
 * stop WLAN Connection Manager via wlan_stop() and try wlan_start() again.
 *
 * \param[in] cb A pointer to a callback function that handles WLAN events. All
 * further WLCMGR events will be notified in this callback. Refer to enum
 * \ref wlan_event_reason for the various events for which this callback is called.
 *
 * \return WM_SUCCESS if the WLAN Connection Manager service has started
 *         successfully.
 * \return -WM_E_INVAL if the \a cb pointer is NULL.
 * \return -WM_FAIL if an internal error occurred.
 * \return WLAN_ERROR_STATE if the WLAN Connection Manager is already running.
 */
int wlan_start(int (*cb)(enum wlan_event_reason reason, void *data));

/** Stop the WLAN Connection Manager service.
 *
 *  This function stops the WLAN Connection Manager, causing station interface
 *  to disconnect from the currently connected network and stop the
 *  micro-AP interface.
 *
 *  \return WM_SUCCESS if the WLAN Connection Manager service has been
 *          stopped successfully.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not
 *          running.
 */
int wlan_stop(void);

/** Deinitialize SDIO driver, send shutdown command to WLAN firmware
 *  and delete the wifi driver thread.
 *  \param action Additional action to be taken with deinit
 *			WLAN_ACTIVE: no action to be taken
 */
void wlan_deinit(int action);

#ifdef CONFIG_WPS2
/** Generate valid PIN for WPS session.
 *
 *  This function generate PIN for WPS PIN session.
 *
 * \param[in]  pin A pointer to WPS pin to be generated.
 */
void wlan_wps_generate_pin(uint32_t *pin);

/** Start WPS PIN session.
 *
 *  This function starts WPS PIN session.
 *
 * \param[in]  pin Pin for WPS session.
 *
 * \return WM_SUCCESS if the pin entered is valid.
 * \return -WM_FAIL if invalid pin entered.
 */
int wlan_start_wps_pin(uint32_t pin);

/** Start WPS PBC session.
 *
 *  This function starts WPS PBC session.
 *
 * \return  WM_SUCCESS if successful
 */
int wlan_start_wps_pbc(void);
/**
 * Set None/WPS/802.1x session.
 *
 *\param[in] session       0 -- PROV_NON_SESSION_ATTEMPT, 1 -- PROV_WPS_SESSION_ATTEMPT, 2 -- PROV_ENTP_SESSION_ATTEMPT.
 */
void wlan_set_prov_session(int session);

/**
 * Get connect session type.
 *
 * \return 0 -- PROV_NON_SESSION_ATTEMPT, 1 -- PROV_WPS_SESSION_ATTEMPT, 2 -- PROV_ENTP_SESSION_ATTEMPT.
 */
int wlan_get_prov_session(void);
#endif

/** Stop and Remove all wireless network profiles.
 *
 *  \return WM_SUCCESS if successful.
 */
int wlan_remove_all_network_profiles(void);

#if defined(RW610)
/** Reset driver.
 *  \param ResetOption option including enable, disable or reset wifi driver
 *  can be chosen.
 */
void wlan_reset(cli_reset_option ResetOption);
/** Stop and Remove all wireless network (Access Point).
 *
 *  \return WM_SUCCESS if successful.
 */
int wlan_remove_all_networks(void);
/**
 * This API destroy all tasks.
 */
void wlan_destroy_all_tasks(void);
/** Retrieve the status information of if wlan started.
 *
 *  \return TRUE if started.
 *  \return FALSE if not started.
 */
int wlan_is_started();

#endif // RW610


#ifdef CONFIG_NCP_BRIDGE
/** uap provisioning deinit callback function */
void wlan_register_uap_prov_deinit_cb(int (*cb)(void));
/** uap provisioning cleanup callback function */
void wlan_register_uap_prov_cleanup_cb(void (*cb)(void));
/** Stop all wireless network.
 *
 *  \return WM_SUCCESS if successful.
 */
int wlan_stop_all_networks(void);
#endif

#ifdef CONFIG_RX_ABORT_CFG
struct wlan_rx_abort_cfg
{
    /** Enable/Disable Rx abort config */
    t_u8 enable;
    /** Rx weak RSSI pkt threshold */
    int rssi_threshold;
};
#endif

#ifdef CONFIG_RX_ABORT_CFG_EXT
struct wlan_rx_abort_cfg_ext
{
    /** Enable/disable dyn rx abort on weak pkt rssi */
    int enable;
    /** specify rssi margin */
    int rssi_margin;
    /** specify ceil rssi threshold */
    int ceil_rssi_threshold;
    /** specify floor rssi threshold */
    int floor_rssi_threshold;
    /** current dynamic rssi threshold */
    int current_dynamic_rssi_threshold;
    /** rssi config: default or user configured */
    int rssi_default_config;
    /** EDMAC status */
    int edmac_enable;
};
#endif

#ifdef CONFIG_CCK_DESENSE_CFG
#define CCK_DESENSE_MODE_DISABLED 0
#define CCK_DESENSE_MODE_DYNAMIC  1
#define CCK_DESENSE_MODE_DYN_ENH  2

struct wlan_cck_desense_cfg
{
    /** cck desense mode: 0:disable 1:normal 2:dynamic */
    t_u16 mode;
    /** specify rssi margin */
    int margin;
    /** specify ceil rssi threshold */
    int ceil_thresh;
    /** cck desense "on" interval count */
    int num_on_intervals;
    /** cck desense "off" interval count */
    int num_off_intervals;
};
#endif
#ifdef CONFIG_RX_ABORT_CFG
/**
 * Set/Get RX abort configure to/from Fw.
 *
 * \param[in,out] cfg A pointer to information buffer
 * \param[in] action Command action: GET or SET
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_get_rx_abort_cfg(struct wlan_rx_abort_cfg *cfg, t_u16 action);
#endif

#ifdef CONFIG_RX_ABORT_CFG_EXT
/**
 * Set Dynamic RX abort config to Fw.
 *
 * \param[in] cfg A pointer to information buffer
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_rx_abort_cfg_ext(const struct wlan_rx_abort_cfg_ext *cfg);

/**
 * Get Dynamic RX abort config from Fw.
 *
 * \param[in,out] cfg A pointer to information buffer
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_rx_abort_cfg_ext(struct wlan_rx_abort_cfg_ext *cfg);
#endif

#ifdef CONFIG_CCK_DESENSE_CFG
/**
 * Set/Get CCK Desense configure to/from Fw.
 *
 * \param[in,out] cfg A pointer to information buffer
 * \param[in] action Command action: GET or SET
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_get_cck_desense_cfg(struct wlan_cck_desense_cfg *cfg, t_u16 action);
#endif

/** WLAN initialize micro-AP network information
 *
 * This API intializes a default micro-AP network. The network ssid, passphrase
 * is initialized to NULL. Channel is set to auto. The IP Address of the
 * micro-AP interface is 192.168.10.1/255.255.255.0. Network name is set to
 * 'uap-network'.
 *
 * \param[out] net Pointer to the initialized micro-AP network
 */
void wlan_initialize_uap_network(struct wlan_network *net);

/** WLAN initialize station network information
 *
 * This API intializes a default station network. The network ssid, passphrase
 * is initialized to NULL. Channel is set to auto.
 *
 * \param[out] net Pointer to the initialized micro-AP network
 */
void wlan_initialize_sta_network(struct wlan_network *net);

/** Add a network profile to the list of known networks.
 *
 *  This function copies the contents of \a network to the list of known
 *  networks in the WLAN Connection Manager.  The network's 'name' field must be
 *  unique and between \ref WLAN_NETWORK_NAME_MIN_LENGTH and \ref
 *  WLAN_NETWORK_NAME_MAX_LENGTH characters.  The network must specify at least
 *  an SSID or BSSID.  The WLAN Connection Manager may store up to
 *  WLAN_MAX_KNOWN_NETWORKS networks.
 *
 *  \note Profiles for the station interface may be added only when the station
 *  interface is in the \ref WLAN_DISCONNECTED or \ref WLAN_CONNECTED state.
 *
 *  \note This API can be used to add profiles for station or
 *  micro-AP interfaces.
 *
 *  \param[in] network A pointer to the \ref wlan_network that will be copied
 *             to the list of known networks in the WLAN Connection Manager
 *             successfully.
 *
 *  \return WM_SUCCESS if the contents pointed to by \a network have been
 *          added to the WLAN Connection Manager.
 *  \return -WM_E_INVAL if \a network is NULL or the network name
 *          is not unique or the network name length is not valid
 *          or network security is \ref WLAN_SECURITY_WPA3_SAE but
 *          Management Frame Protection Capable is not enabled.
 *          in \ref wlan_network_security field. if network security type is
 *          \ref WLAN_SECURITY_WPA or \ref WLAN_SECURITY_WPA2 or \ref
 *          WLAN_SECURITY_WPA_WPA2_MIXED, but the passphrase length is less
 *          than 8 or greater than 63, or the psk length equal to 64 but not
 *          hexadecimal digits. if network security type is \ref WLAN_SECURITY_WPA3_SAE,
 *          but the password length is less than 8 or greater than 255.
 *          if network security type is \ref WLAN_SECURITY_WEP_OPEN or
 *          \ref WLAN_SECURITY_WEP_SHARED.
 *  \return -WM_E_NOMEM if there was no room to add the network.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager
 *          was running and not in the \ref WLAN_DISCONNECTED,
 *          \ref WLAN_ASSOCIATED or \ref WLAN_CONNECTED state.
 */
int wlan_add_network(struct wlan_network *network);

/** Remove a network profile from the list of known networks.
 *
 *  This function removes a network (identified by its name) from the WLAN
 *  Connection Manager, disconnecting from that network if connected.
 *
 *  \note This function is asynchronous if it is called while the WLAN
 *  Connection Manager is running and connected to the network to be removed.
 *  In that case, the WLAN Connection Manager will disconnect from the network
 *  and generate an event with reason \ref WLAN_REASON_USER_DISCONNECT. This
 *  function is synchronous otherwise.
 *
 *  \note This API can be used to remove profiles for station or
 *  micro-AP interfaces. Station network will not be removed if it is
 *  in \ref WLAN_CONNECTED state and uAP network will not be removed
 *  if it is in \ref WLAN_UAP_STARTED state.
 *
 *  \param[in] name A pointer to the string representing the name of the
 *             network to remove.
 *
 *  \return WM_SUCCESS if the network named \a name was removed from the
 *          WLAN Connection Manager successfully. Otherwise,
 *          the network is not removed.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *          running and the station interface was not in the \ref
 *          WLAN_DISCONNECTED state.
 *  \return -WM_E_INVAL if \a name is NULL or the network was not found in
 *          the list of known networks.
 *  \return -WM_FAIL if an internal error occurred
 *          while trying to disconnect from the network specified for
 *          removal.
 */
int wlan_remove_network(const char *name);

/** Connect to a wireless network (Access Point).
 *
 *  When this function is called, WLAN Connection Manager starts connection attempts
 *  to the network specified by \a name. The connection result will be notified
 *  asynchronously to the WLCMGR callback when the connection process has
 *  completed.
 *
 *  When connecting to a network, the event refers to the connection
 *  attempt to that network.
 *
 *  Calling this function when the station interface is in the \ref
 *  WLAN_DISCONNECTED state will, if successful, cause the interface to
 *  transition into the \ref WLAN_CONNECTING state.  If the connection attempt
 *  succeeds, the station interface will transition to the \ref WLAN_CONNECTED state,
 *  otherwise it will return to the \ref WLAN_DISCONNECTED state.  If this
 *  function is called while the station interface is in the \ref
 *  WLAN_CONNECTING or \ref WLAN_CONNECTED state, the WLAN Connection Manager
 *  will first cancel its connection attempt or disconnect from the network,
 *  respectively, and generate an event with reason \ref
 *  WLAN_REASON_USER_DISCONNECT. This will be followed by a second event that
 *  reports the result of the new connection attempt.
 *
 *  If the connection attempt was successful the WLCMGR callback is notified
 *  with the event \ref WLAN_REASON_SUCCESS, while if the connection attempt
 *  fails then either of the events, \ref WLAN_REASON_NETWORK_NOT_FOUND, \ref
 *  WLAN_REASON_NETWORK_AUTH_FAILED, \ref WLAN_REASON_CONNECT_FAILED
 *  or \ref WLAN_REASON_ADDRESS_FAILED are reported as appropriate.
 *
 *  \param[in] name A pointer to a string representing the name of the network
 *              to connect to.
 *
 *  \return WM_SUCCESS if a connection attempt was started successfully
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running.
 *  \return -WM_E_INVAL if there are no known networks to connect to
 *          or the network specified by \a name is not in the list
 *          of known networks or network \a name is NULL.
 *  \return -WM_FAIL if an internal error has occurred.
 */
int wlan_connect(char *name);

/** Connect to a wireless network (Access Point) with options.
 *
 *  When this function is called, WLAN Connection Manager starts connection attempts
 *  to the network specified by \a name. The connection result will be notified
 *  asynchronously to the WLCMGR callback when the connection process has
 *  completed.
 *
 *  When connecting to a network, the event refers to the connection
 *  attempt to that network.
 *
 *  Calling this function when the station interface is in the \ref
 *  WLAN_DISCONNECTED state will, if successful, cause the interface to
 *  transition into the \ref WLAN_CONNECTING state.  If the connection attempt
 *  succeeds, the station interface will transition to the \ref WLAN_CONNECTED state,
 *  otherwise it will return to the \ref WLAN_DISCONNECTED state.  If this
 *  function is called while the station interface is in the \ref
 *  WLAN_CONNECTING or \ref WLAN_CONNECTED state, the WLAN Connection Manager
 *  will first cancel its connection attempt or disconnect from the network,
 *  respectively, and generate an event with reason \ref
 *  WLAN_REASON_USER_DISCONNECT. This will be followed by a second event that
 *  reports the result of the new connection attempt.
 *
 *  If the connection attempt was successful the WLCMGR callback is notified
 *  with the event \ref WLAN_REASON_SUCCESS, while if the connection attempt
 *  fails then either of the events, \ref WLAN_REASON_NETWORK_NOT_FOUND, \ref
 *  WLAN_REASON_NETWORK_AUTH_FAILED, \ref WLAN_REASON_CONNECT_FAILED
 *  or \ref WLAN_REASON_ADDRESS_FAILED are reported as appropriate.
 *
 *  \param[in] name A pointer to a string representing the name of the network
 *              to connect to.
 *  \param[in] skip_dfs Option to skip DFS channel when doing scan.
 *
 *  \return WM_SUCCESS if a connection attempt was started successfully
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running.
 *  \return -WM_E_INVAL if there are no known networks to connect to
 *          or the network specified by \a name is not in the list
 *          of known networks or network \a name is NULL.
 *  \return -WM_FAIL if an internal error has occurred.
 */
int wlan_connect_opt(char *name, bool skip_dfs);

/** Reassociate to a wireless network (Access Point).
 *
 *  When this function is called, WLAN Connection Manager starts reassociation
 *  attempts using same SSID as currently connected network .
 *  The connection result will be notified asynchronously to the WLCMGR
 *  callback when the connection process has completed.
 *
 *  When connecting to a network, the event refers to the connection
 *  attempt to that network.
 *
 *  Calling this function when the station interface is in the \ref
 *  WLAN_DISCONNECTED state will have no effect.
 *
 *  Calling this function when the station interface is in the \ref
 *  WLAN_CONNECTED state will, if successful, cause the interface to
 *  reassociate to another network(AP).
 *
 *  If the connection attempt was successful the WLCMGR callback is notified
 *  with the event \ref WLAN_REASON_SUCCESS, while if the connection attempt
 *  fails then either of the events, \ref WLAN_REASON_NETWORK_AUTH_FAILED,
 *  \ref WLAN_REASON_CONNECT_FAILED or \ref WLAN_REASON_ADDRESS_FAILED
 *  are reported as appropriate.
 *
 *  \return WM_SUCCESS if a reassociation attempt was started successfully
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running.
 *          or WLAN Connection Manager was not in \ref WLAN_CONNECTED state.
 *  \return -WM_E_INVAL if there are no known networks to connect to
 *  \return -WM_FAIL if an internal error has occurred.
 */
int wlan_reassociate();

/** Disconnect from the current wireless network (Access Point).
 *
 *  When this function is called, the WLAN Connection Manager attempts to disconnect
 *  the station interface from its currently connected network (or cancel an in-progress
 *  connection attempt) and return to the \ref WLAN_DISCONNECTED state. Calling
 *  this function has no effect if the station interface is already
 *  disconnected.
 *
 *  \note This is an asynchronous function and successful disconnection will be
 *  notified using the \ref WLAN_REASON_USER_DISCONNECT.
 *
 * \return  WM_SUCCESS if successful
 * \return  WLAN_ERROR_STATE otherwise
 */
int wlan_disconnect(void);

/** Start a wireless network (Access Point).
 *
 *  When this function is called, the WLAN Connection Manager starts the network
 *  specified by \a name. The network with the specified \a name must be
 *  first added using \ref wlan_add_network and must be a micro-AP network with
 *  a valid SSID.
 *
 *  \note The WLCMGR callback is asynchronously notified of the status. On
 *  success, the event \ref WLAN_REASON_UAP_SUCCESS is reported, while on
 *  failure, the event \ref WLAN_REASON_UAP_START_FAILED is reported.
 *
 *  \param[in] name A pointer to string representing the name of the network
 *             to connect to.
 *
 *  \return WM_SUCCESS if successful.
 *  \return WLAN_ERROR_STATE if in power save state or uAP already running.
 *  \return -WM_E_INVAL if \a name was NULL or the network \a
 *          name was not found or it not have a specified SSID.
 */
int wlan_start_network(const char *name);

/** Stop a wireless network (Access Point).
 *
 *  When this function is called, the WLAN Connection Manager stops the network
 *  specified by \a name. The specified network must be a valid micro-AP
 *  network that has already been started.
 *
 *  \note The WLCMGR callback is asynchronously notified of the status. On
 *  success, the event \ref WLAN_REASON_UAP_STOPPED is reported, while on
 *  failure, the event \ref WLAN_REASON_UAP_STOP_FAILED is reported.
 *
 *  \param[in] name A pointer to a string representing the name of the network
 *             to stop.
 *
 *  \return WM_SUCCESS if successful.
 *  \return WLAN_ERROR_STATE if uAP is in power save state.
 *  \return -WM_E_INVAL if \a name was NULL or the network \a
 *          name was not found or that the network \a name is not a micro-AP
 *          network or it is a micro-AP network but does not have a specified
 *          SSID.
 */
int wlan_stop_network(const char *name);

/** Retrieve the wireless MAC address of station interface.
 *
 *  This function copies the MAC address of the station interface to sta mac address and uAP interface to uap mac
 * address.
 *
 *  \param[out] dest A pointer to a 6-byte array where the MAC address will be
 *              copied.
 *
 *  \return WM_SUCCESS if the MAC address was copied.
 *  \return -WM_E_INVAL if \a sta_mac or uap_mac is NULL.
 */
int wlan_get_mac_address(uint8_t *dest);

/** Retrieve the wireless MAC address of micro-AP interface.
 *
 *  This function copies the MAC address of the wireless interface to
 *  the 6-byte array pointed to by \a dest.  In the event of an error, nothing
 *  is copied to \a dest.
 *
 *  \param[out] dest A pointer to a 6-byte array where the MAC address will be
 *              copied.
 *
 *  \return WM_SUCCESS if the MAC address was copied.
 *  \return -WM_E_INVAL if \a dest is NULL.
 */
int wlan_get_mac_address_uap(uint8_t *dest);

/** Retrieve the IP address configuration of the station interface.
 *
 *  This function retrieves the IP address configuration
 *  of the station interface and copies it to the memory
 *  location pointed to by \a addr.
 *
 *  \note This function may only be called when the station interface is in the
 *  \ref WLAN_CONNECTED state.
 *
 *  \param[out] addr A pointer to the \ref wlan_ip_config.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a addr is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running or was
 *          not in the \ref WLAN_CONNECTED state.
 *  \return -WM_FAIL if an internal error
 *          occurred when retrieving IP address information from the
 *          TCP stack.
 */
int wlan_get_address(struct wlan_ip_config *addr);

/** Retrieve the IP address of micro-AP interface.
 *
 *  This function retrieves the current IP address configuration of micro-AP
 *  and copies it to the memory location pointed to by \a addr.
 *
 *  \note This function may only be called when the micro-AP interface is in the
 *  \ref WLAN_UAP_STARTED state.
 *
 *  \param[out] addr A pointer to the \ref wlan_ip_config.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a addr is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running or
 *          the micro-AP interface was not in the \ref WLAN_UAP_STARTED state.
 *  \return -WM_FAIL if an internal error
 *          occurred when retrieving IP address information from the
 *          TCP stack.
 */
int wlan_get_uap_address(struct wlan_ip_config *addr);

/** Retrieve the channel of micro-AP interface.
 *
 *  This function retrieves the channel number of micro-AP
 *  and copies it to the memory location pointed to by \a channel.
 *
 *  \note This function may only be called when the micro-AP interface is in the
 *  \ref WLAN_UAP_STARTED state.
 *
 *  \param[out] channel A pointer to variable that stores channel number.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a channel is NULL.
 *  \return -WM_FAIL if an internal error has occurred.
 */
int wlan_get_uap_channel(int *channel);

/** Retrieve the current network configuration of station interface.
 *
 *  This function retrieves the current network configuration of station
 *  interface when the station interface is in the \ref WLAN_CONNECTED
 *  state.
 *
 *  \param[out] network A pointer to the \ref wlan_network.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *          not running or not in the \ref WLAN_CONNECTED state.
 */
int wlan_get_current_network(struct wlan_network *network);

/** Retrieve the current network ssid of station interface.
 *
 *  This function retrieves the current network ssid of station
 *  interface when the station interface is in the \ref WLAN_CONNECTED
 *  state.
 *
 *  \param[out] ssid A pointer to the ssid.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *          not running or not in the \ref WLAN_CONNECTED state.
 */
int wlan_get_current_network_ssid(char *ssid);

/** Retrieve the current network bssid of station interface.
 *
 *  This function retrieves the current network bssid of station
 *  interface when the station interface is in the \ref WLAN_CONNECTED
 *  state.
 *
 *  \param[out] bssid A pointer to the bssid.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *          not running or not in the \ref WLAN_CONNECTED state.
 */
int wlan_get_current_network_bssid(char *bssid);

/** Retrieve the current network configuration of micro-AP interface.
 *
 *  This function retrieves the current network configuration of micro-AP
 *  interface when the micro-AP interface is in the \ref WLAN_UAP_STARTED state.
 *
 *  \param[out] network A pointer to the \ref wlan_network.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *           not running or not in the \ref WLAN_UAP_STARTED state.
 */
int wlan_get_current_uap_network(struct wlan_network *network);

/** Retrieve the current network ssid of micro-AP interface.
 *
 *  This function retrieves the current network ssid of micro-AP
 *  interface when the micro-AP interface is in the \ref WLAN_UAP_STARTED state.
 *
 *  \param[out] ssid A pointer to the ssid.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *           not running or not in the \ref WLAN_UAP_STARTED state.
 */
int wlan_get_current_uap_network_ssid(char *ssid);

#ifdef CONFIG_SCAN_WITH_RSSIFILTER
int wlan_set_rssi_threshold(int rssithr);
#endif

/** Retrieve the status information of the micro-AP interface.
 *
 *  \return TRUE if micro-AP interface is in \ref WLAN_UAP_STARTED state.
 *  \return FALSE otherwise.
 */
bool is_uap_started(void);

/** Retrieve the status information of the station interface.
 *
 *  \return TRUE if station interface is in \ref WLAN_CONNECTED state.
 *  \return FALSE otherwise.
 */
bool is_sta_connected(void);

/** Retrieve the status information of the ipv4 network of station interface.
 *
 *  \return TRUE if ipv4 network of station interface is in \ref WLAN_CONNECTED
 *  state.
 *  \return FALSE otherwise.
 */
bool is_sta_ipv4_connected(void);

#ifdef CONFIG_IPV6
/** Retrieve the status information of the ipv6 network of station interface.
 *
 *  \return TRUE if ipv6 network of station interface is in \ref WLAN_CONNECTED
 *  state.
 *  \return FALSE otherwise.
 */
bool is_sta_ipv6_connected(void);
#endif

/** Retrieve the information about a known network using \a index.
 *
 *  This function retrieves the contents of a network at \a index in the
 *  list of known networks maintained by the WLAN Connection Manager and
 *  copies it to the location pointed to by \a network.
 *
 *  \note \ref wlan_get_network_count() may be used to retrieve the number
 *  of known networks. \ref wlan_get_network() may be used to retrieve
 *  information about networks at \a index 0 to one minus the number of networks.
 *
 *  \note This function may be called regardless of whether the WLAN Connection
 *  Manager is running. Calls to this function are synchronous.
 *
 *  \param[in] index The index of the network to retrieve.
 *  \param[out] network A pointer to the \ref wlan_network where the network
 *              configuration for the network at \a index will be copied.
 *
 *  \returns WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL or \a index is out of range.
 */
int wlan_get_network(unsigned int index, struct wlan_network *network);

/** Retrieve information about a known network using \a name.
 *
 *  This function retrieves the contents of a named network in the
 *  list of known networks maintained by the WLAN Connection Manager and
 *  copies it to the location pointed to by \a network.
 *
 *  \note This function may be called regardless of whether the WLAN Connection
 *  Manager is running. Calls to this function are synchronous.
 *
 *  \param[in] name The name of the network to retrieve.
 *  \param[out] network A pointer to the \ref wlan_network where the network
 *              configuration for the network having name as \a name will be copied.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a network is NULL or \a name is NULL.
 */
int wlan_get_network_byname(char *name, struct wlan_network *network);

/** Retrieve the number of networks known to the WLAN Connection Manager.
 *
 *  This function retrieves the number of known networks in the list maintained
 *  by the WLAN Connection Manager and copies it to \a count.
 *
 *  \note This function may be called regardless of whether the WLAN Connection
 *  Manager is running. Calls to this function are synchronous.
 *
 *  \param[out] count A pointer to the memory location where the number of
 *              networks will be copied.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a count is NULL.
 */
int wlan_get_network_count(unsigned int *count);

/** Retrieve the connection state of station interface.
 *
 *  This function retrieves the connection state of station interface, which is
 *  one of \ref WLAN_DISCONNECTED, \ref WLAN_CONNECTING, \ref WLAN_ASSOCIATED
 *  or \ref WLAN_CONNECTED.
 *
 *  \param[out] state A pointer to the \ref wlan_connection_state where the
 *         current connection state will be copied.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a state is NULL
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running.
 */
int wlan_get_connection_state(enum wlan_connection_state *state);

/** Retrieve the connection state of micro-AP interface.
 *
 *  This function retrieves the connection state of micro-AP interface, which is
 *  one of \ref WLAN_UAP_STARTED, or \ref WLAN_UAP_STOPPED.
 *
 *  \param[out] state A pointer to the \ref wlan_connection_state where the
 *         current connection state will be copied.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a state is NULL
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was not running.
 */
int wlan_get_uap_connection_state(enum wlan_connection_state *state);

/** Scan for wireless networks.
 *
 *  When this function is called, the WLAN Connection Manager starts scan
 *  for wireless networks. On completion of the scan the WLAN Connection Manager
 *  will call the specified callback function \a cb. The callback function can then
 *  retrieve the scan results by using the \ref wlan_get_scan_result() function.
 *
 *  \note This function may only be called when the station interface is in the
 *  \ref WLAN_DISCONNECTED or \ref WLAN_CONNECTED state. Scanning is disabled
 *  in the \ref WLAN_CONNECTING state.
 *
 *  \note This function will block until it can issue a scan request if called
 *  while another scan is in progress.
 *
 *  \param[in] cb A pointer to the function that will be called to handle scan
 *         results when they are available.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_NOMEM if failed to allocated memory for \ref
 *	     wlan_scan_params_v2_t structure.
 *  \return -WM_E_INVAL if \a cb scan result callack functio pointer is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *           not running or not in the \ref WLAN_DISCONNECTED or \ref
 *           WLAN_CONNECTED states.
 *  \return -WM_FAIL if an internal error has occurred and
 *           the system is unable to scan.
 */
int wlan_scan(int (*cb)(unsigned int count));

/** Scan for wireless networks using options provided.
 *
 *  When this function is called, the WLAN Connection Manager starts scan
 *  for wireless networks. On completion of the scan the WLAN Connection Manager
 *  will call the specified callback function \a cb. The callback function
 *  can then retrieve the scan results by using the \ref wlan_get_scan_result()
 *  function.
 *
 *  \note This function may only be called when the station interface is in the
 *  \ref WLAN_DISCONNECTED or \ref WLAN_CONNECTED state. Scanning is disabled
 *  in the \ref WLAN_CONNECTING state.
 *
 *  \note This function will block until it can issue a scan request if called
 *  while another scan is in progress.
 *
 *  \param[in] t_wlan_scan_param  A \ref wlan_scan_params_v2_t structure holding
 *	       a pointer to function that will be called
 *	       to handle scan results when they are available,
 *	       SSID of a wireless network, BSSID of a wireless network,
 *	       number of channels with scan type information and number of
 *	       probes.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_NOMEM if failed to allocated memory for \ref
 *	     wlan_scan_params_v2_t structure.
 *  \return -WM_E_INVAL if \a cb scan result callack function pointer is NULL.
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager was
 *           not running or not in the \ref WLAN_DISCONNECTED or \ref
 *           WLAN_CONNECTED states.
 *  \return -WM_FAIL if an internal error has occurred and
 *           the system is unable to scan.
 */
int wlan_scan_with_opt(wlan_scan_params_v2_t t_wlan_scan_param);

/** Retrieve a scan result.
 *
 *  This function may be called to retrieve scan results when the WLAN
 *  Connection Manager has finished scanning. It must be called from within the
 *  scan result callback (see \ref wlan_scan()) as scan results are valid
 *  only in that context. The callback argument 'count' provides the number
 *  of scan results that may be retrieved and \ref wlan_get_scan_result() may
 *  be used to retrieve scan results at \a index 0 through that number.
 *
 *  \note This function may only be called in the context of the scan results
 *  callback.
 *
 *  \note Calls to this function are synchronous.
 *
 *  \param[in] index The scan result to retrieve.
 *  \param[out] res A pointer to the \ref wlan_scan_result where the scan
 *              result information will be copied.
 *
 *  \return WM_SUCCESS if successful.
 *  \return -WM_E_INVAL if \a res is NULL
 *  \return WLAN_ERROR_STATE if the WLAN Connection Manager
 *          was not running
 *  \return -WM_FAIL if the scan result at \a
 *          index could not be retrieved (that is, \a index
 *          is out of range).
 */
int wlan_get_scan_result(unsigned int index, struct wlan_scan_result *res);

#ifdef WLAN_LOW_POWER_ENABLE
/**
 * Enable Low Power Mode in Wireless Firmware.
 *
 * \note When low power mode is enabled, the output power will be clipped at
 * ~+10dBm and the expected PA current is expected to be in the 80-90 mA
 * range for b/g/n modes.
 *
 * This function may be called to enable low power mode in firmware.
 * This should be called before \ref wlan_init() function.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 *
 */
int wlan_enable_low_pwr_mode();
#endif

/**
 * Configure ED MAC mode for Station in Wireless Firmware.
 *
 * \note When ed mac mode is enabled,
 * Wireless Firmware will behave following way:
 *
 * when background noise had reached -70dB or above,
 * WiFi chipset/module should hold data transmitting
 * until condition is removed.
 * It is applicable for both 5GHz and 2.4GHz bands.
 *
 * \param[in] wlan_ed_mac_ctrl  Struct with following parameters
 *	 ed_ctrl_2g	     0  - disable EU adaptivity for 2.4GHz band
 *                           1  - enable EU adaptivity for 2.4GHz band
 *
 *       ed_offset_2g        0  - Default Energy Detect threshold (Default: 0x9)
 *                           offset value range: 0x80 to 0x7F
 *
 * \note If 5GH enabled then add following parameters
 *
 *       ed_ctrl_5g          0  - disable EU adaptivity for 5GHz band
 *                           1  - enable EU adaptivity for 5GHz band
 *
 *       ed_offset_5g        0  - Default Energy Detect threshold(Default: 0xC)
 *                           offset value range: 0x80 to 0x7F
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 *
 */
int wlan_set_ed_mac_mode(wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl);

/**
 * Configure ED MAC mode for Micro AP in Wireless Firmware.
 *
 * \note When ed mac mode is enabled,
 * Wireless Firmware will behave following way:
 *
 * when background noise had reached -70dB or above,
 * WiFi chipset/module should hold data transmitting
 * until condition is removed.
 * It is applicable for both 5GHz and 2.4GHz bands.
 *
 * \param[in] wlan_ed_mac_ctrl  Struct with following parameters
 *	 ed_ctrl_2g	     0  - disable EU adaptivity for 2.4GHz band
 *                           1  - enable EU adaptivity for 2.4GHz band
 *
 *       ed_offset_2g        0  - Default Energy Detect threshold (Default: 0x9)
 *                           offset value range: 0x80 to 0x7F
 *
 * \note If 5GH enabled then add following parameters
 *
 *       ed_ctrl_5g          0  - disable EU adaptivity for 5GHz band
 *                           1  - enable EU adaptivity for 5GHz band
 *
 *       ed_offset_5g        0  - Default Energy Detect threshold(Default: 0xC)
 *                           offset value range: 0x80 to 0x7F
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 *
 */
int wlan_set_uap_ed_mac_mode(wlan_ed_mac_ctrl_t wlan_ed_mac_ctrl);

/**
 * This API can be used to get current ED MAC MODE configuration for Station.
 *
 * \param[out] wlan_ed_mac_ctrl A pointer to \ref wlan_ed_mac_ctrl_t
 * 			with parameters mentioned in above set API.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 *
 */
int wlan_get_ed_mac_mode(wlan_ed_mac_ctrl_t *wlan_ed_mac_ctrl);

/**
 * This API can be used to get current ED MAC MODE configuration for Micro AP.
 *
 * \param[out] wlan_ed_mac_ctrl A pointer to \ref wlan_ed_mac_ctrl_t
 * 			with parameters mentioned in above set API.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 *
 */
int wlan_get_uap_ed_mac_mode(wlan_ed_mac_ctrl_t *wlan_ed_mac_ctrl);

/** Set wireless calibration data in WLAN firmware.
 *
 * This function may be called to set wireless calibration data in firmware.
 * This should be call before \ref wlan_init() function.
 *
 * \param[in] cal_data The calibration data buffer
 * \param[in] cal_data_size Size of calibration data buffer.
 *
 */
void wlan_set_cal_data(const uint8_t *cal_data, const unsigned int cal_data_size);

/** Set wireless MAC Address in WLAN firmware.
 *
 * This function may be called to set wireless MAC Address in firmware.
 * This should be call before \ref wlan_init() function.
 * When called after wlan init done, the incoming mac is treated as the sta mac address directly. And mac[4] plus 1 the
 * modifed mac as the UAP mac address.
 *
 * \param[in] mac The MAC Address in 6 byte array format like
 *                uint8_t mac[] = { 0x00, 0x50, 0x43, 0x21, 0x19, 0x6E};
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_mac_addr(uint8_t *mac);

/** Set wireless MAC Address for STA in WLAN firmware.
 *
 * This function may be called to set wireless MAC Address in firmware.
 * This should be call before \ref wlan_init() function.
 * When called after wlan init done, it will set only STA MAC adderess.
 *
 * \param[in] mac The MAC Address in 6 byte array format like
 *                uint8_t mac[] = { 0x00, 0x50, 0x43, 0x21, 0x19, 0x6E};
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_sta_mac_addr(uint8_t *mac);

/** Set wireless MAC Address for uAP in WLAN firmware.
 *
 * This function may be called to set wireless MAC Address in firmware.
 * This should be call before \ref wlan_init() function.
 * When called after wlan init done, it will set only uAP MAC address.
 *
 * \param[in] mac The MAC Address in 6 byte array format like
 *                uint8_t mac[] = { 0x00, 0x50, 0x43, 0x21, 0x19, 0x6E};
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_uap_mac_addr(uint8_t *mac);

#ifdef CONFIG_WMM_UAPSD
/** Set QOS info in WLAN firmware.
 *
 * \param[in] qos_info UAPSD QOS info.
 * \param[in] action Set/get action.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_wmm_uapsd_qosinfo(t_u8 *qos_info, t_u8 action);
/** Enable/disable UAPSD in WLAN firmware.
 *
 * \param[in] uapsd_enable Enable/disable UAPSD.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_wmm_uapsd(t_u8 uapsd_enable);
/** Set/get UAPSD sleep period in WLAN firmware.
 *
 * \param[in] sleep_period UAPSD sleep period.
 * \param[in] action Set/get action.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_sleep_period(unsigned int *sleep_period, t_u8 action);
/** Check if UAPSD is enabled or not.
 *
 * \return true if UAPSD is enabled.
 * \return false if UAPSD is disabled.
 */
t_u8 wlan_is_wmm_uapsd_enabled(void);
#endif

#ifdef CONFIG_WIFI_TX_BUFF
/** Reconfigure wifi tx buffer size in WLAN firmware.
 *
 * This function may be called to reconfigure wifi tx buffer size in firmware.
 * This should be call before \ref wlan_init() function.
 *
 * \param[in] buf_size The new buffer size
 *
 * \param[in] bss_type 0: STA, 1: uAP
 *
 */
void wlan_recfg_tx_buf_size(uint16_t buf_size, mlan_bss_type bss_type);
#endif

#ifdef CONFIG_WIFI_TX_PER_TRACK
/** Set Tx PER tracking config.
 * This function may be called to set Tx PER tracking in firmware.
 *
 * \param[in] tx_pert User configured parameters of Tx PER tracking
 *            period, ratio and number of tx packets.
 *
 * \param[in] bss_type BSS type for STA or uAP.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
void wlan_set_tx_pert(struct wlan_tx_pert_info *tx_pert, mlan_bss_type bss_type);
#endif

#ifdef CONFIG_TX_RX_HISTOGRAM
/** Set Tx Rx histogram config.
 * This function may be called to set Tx Rx histogram config.
 *
 * \param[in] txrx_histogram User configured parameters of Tx Rx histogram
 *            including enable and action.
 * \param[out] data Tx Rx histogram data from fw.
 */
void wlan_set_txrx_histogram(struct wlan_txrx_histogram_info *txrx_histogram, t_u8 *data);
#endif

#ifdef CONFIG_ROAMING
/** Set soft roaming config.
 *
 * This function may be called to enable/disable soft roaming
 * by specifying the RSSI threshold.
 *
 * \note <b>RSSI Threshold setting for soft roaming</b>:
 * The provided RSSI low threshold value is used to subscribe
 * RSSI low event from firmware, on reception of this event
 * background scan is started in firmware with same RSSI
 * threshold to find out APs with better signal strength than
 * RSSI threshold.
 *
 * If AP is found then roam attempt is initiated, otherwise
 * background scan started again till limit reaches to
 * BG_SCAN_LIMIT.
 *
 * If still AP is not found then WLAN connection manager sends
 * \ref WLAN_REASON_BGSCAN_NETWORK_NOT_FOUND event to
 * application. In this case,
 * if application again wants to use soft roaming then it
 * can call this API again or use
 * \ref wlan_set_rssi_low_threshold API to set RSSI low
 * threshold again.
 *
 * \param[in] enable Enable/disable roaming.
 * \param[in] rssi_low_threshold RSSI low threshold value
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_roaming(const int enable, const uint8_t rssi_low_threshold);

int wlan_get_roaming_status();
#endif

#ifdef CONFIG_HOST_SLEEP
#ifdef RW610
/** Wowlan configure.
 * This function may be called to config host sleep in firmware.
 *
 * \param[in] is_mef Flag to indicate use MEF condition or not.
 * \param[in] wake_up_conds Bit map of default condition.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_wowlan_config(uint8_t is_mef, t_u32 wake_up_conds);

/** Host sleep configure.
 * This function may be called to config host sleep in firmware.
 *
 * \param[in] is_manual Flag to indicate host enter low power mode with power manager or by command.
 * \param[in] is_periodic Flag to indicate host enter low power periodically or once with power manager.
 */
void wlan_config_host_sleep(bool is_manual, t_u8 is_periodic);
#endif /*RW610*/

/** Cancel host sleep.
 * This function may be called to cancel host sleep in firmware.
 */
void wlan_cancel_host_sleep();

/** Clear host sleep configurations in driver.
 * This function clears all the host sleep related configures in driver.
 */
void wlan_clear_host_sleep_config();

/** This function set multicast MEF entry
 *
 * \param[in] mef_action To be 0--discard and not wake host, 1--discard and wake host 3--allow and wake host.
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_multicast(t_u8 mef_action);
/** This function sent host sleep events to mon_thread
 * \param[in] id Event ID.
 * \param[in] data Pointer to event msg.
 */
status_t wlan_hs_send_event(int id, void *data);
#endif

/** Set configuration parameters of IEEE power save mode.
 *
 * \param [in] ps_cfg : powersave configuratiuon includes multiple parameters.
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_set_ieeeps_cfg(struct wlan_ieeeps_config *ps_cfg);

/** Configure Listen interval of IEEE power save mode.
 *
 * \note <b>Delivery Traffic Indication Message (DTIM)</b>:
 * It is a concept in 802.11
 * It is a time duration after which AP will send out buffered
 * BROADCAST / MULTICAST data and stations connected to the AP
 * should wakeup to take this broadcast / multicast data.

 * \note <b>Traffic Indication Map (TIM)</b>:
 * It is a bitmap which the AP sends with each beacon.
 * The bitmap has one bit each for a station connected to AP.
 *
 * \note Each station is recognized by an Association Id (AID).
 * If AID is say 1 bit number 1 is set in the bitmap if
 * unicast data is present with AP in its buffer for station with AID = 1
 * Ideally AP does not buffer any unicast data it just sends
 * unicast data to the station on every beacon when station
 * is not sleeping.\n
 * When broadcast data / multicast data is to be send AP sets bit 0
 * of TIM indicating broadcast / multicast.\n
 * The occurrence of DTIM is defined by AP.\n
 * Each beacon has a number indicating period at which DTIM occurs.\n
 * The number is expressed in terms of number of beacons.\n
 * This period is called DTIM Period / DTIM interval.\n
 * For example:\n
 *     If AP has DTIM period = 3 the stations connected to AP
 *     have to wake up (if they are sleeping) to receive
 *     broadcast /multicast data on every third beacon.\n
 * Generic:\n
 *     When DTIM period is X
 *     AP buffers broadcast data / multicast data for X beacons.
 *     Then it transmits the data no matter whether station is awake or not.\n
 * Listen interval:\n
 * This is time interval on station side which indicates when station
 * will be awake to listen i.e. accept data.\n
 * Long listen interval:\n
 * It comes into picture when station sleeps (IEEEPS) and it does
 * not want to wake up on every DTIM
 * So station is not worried about broadcast data/multicast data
 * in this case.\n
 * This should be a design decision what should be chosen
 * Firmware suggests values which are about 3 times DTIM
 * at the max to gain optimal usage and reliability.\n
 * In the IEEEPS power save mode, the WiFi firmware goes to sleep and
 * periodically wakes up to check if the AP has any pending packets for it. A
 * longer listen interval implies that the WiFi card stays in power save for a
 * longer duration at the cost of additional delays while receiving data.
 * Please note that choosing incorrect value for listen interval will
 * causes poor response from device during data transfer.
 * Actual listen interval selected by firmware is equal to closest DTIM.\n
 * For e.g.:-\n
 *            AP beacon period : 100 ms\n
 *            AP DTIM period : 2\n
 *            Application request value: 500ms\n
 *            Actual listen interval = 400ms (This is the closest DTIM).
 * Actual listen interval set will be a multiple of DTIM closest to but
 * lower than the value provided by the application.\n
 *
 *  \note This API can be called before/after association.
 *  The configured listen interval will be used in subsequent association
 *  attempt.
 *
 *  \param [in]  listen_interval Listen interval as below\n
 *               0 : Unchanged,\n
 *              -1 : Disable,\n
 *             1-49: Value in beacon intervals,\n
 *            >= 50: Value in TUs\n
 */
void wlan_configure_listen_interval(int listen_interval);

void wlan_configure_delay_to_ps(unsigned int timeout_ms);

unsigned short wlan_get_listen_interval();

unsigned int wlan_get_delay_to_ps();

bool wlan_is_power_save_enabled();

/** Configure Null packet interval of IEEE power save mode.
 *
 *  \note In IEEEPS station sends a NULL packet to AP to indicate that
 *  the station is alive and AP should not kick it off.
 *  If null packet is not send some APs may disconnect station
 *  which might lead to a loss of connectivity.
 *  The time is specified in seconds.
 *  Default value is 30 seconds.
 *
 *  \note This API should be called before configuring IEEEPS
 *
 *  \param [in] time_in_secs : -1 Disables null packet transmission,
 *                              0  Null packet interval is unchanged,
 *                              n  Null packet interval in seconds.
 */
void wlan_configure_null_pkt_interval(int time_in_secs);

#ifndef RW610
/** This API can be used to set the mode of Tx/Rx antenna.
 * If SAD is enabled, this API can also used to set SAD antenna
 * evaluate time interval(antenna mode must be antenna diversity
 * when set SAD evaluate time interval).
 *
 * \param[in] ant Antenna valid values are 1, 2 and 65535
 *                1 : Tx/Rx antenna 1
 *                2 : Tx/Rx antenna 2
 *	          0xFFFF: Tx/Rx antenna diversity
 * \param[in] evaluate_time
 *	      SAD evaluate time interval, default value is 6s(0x1770).
 *
 * \return WM_SUCCESS if successful.
 * \return WLAN_ERROR_STATE if unsuccessful.
 *
 */
int wlan_set_antcfg(uint32_t ant, uint16_t evaluate_time);

/** This API can be used to get the mode of Tx/Rx antenna.
 * If SAD is enabled, this API can also used to get SAD antenna
 * evaluate time interval(antenna mode must be antenna diversity
 * when set SAD evaluate time interval).
 *
 * \param[out] ant pointer to antenna variable.
 * \param[out] evaluate_time pointer to evaluate_time variable for SAD.
 * \param[out] current_antenna pointer to current antenna.
 *
 * \return WM_SUCCESS if successful.
 * \return WLAN_ERROR_STATE if unsuccessful.
 */
int wlan_get_antcfg(uint32_t *ant, uint16_t *evaluate_time, uint16_t *current_antenna);
#else
/** This API can be used to set the mode of Tx/Rx antenna.
 * If SAD is enabled, this API can also used to set SAD antenna
 * evaluate time interval(antenna mode must be antenna diversity
 * when set SAD evaluate time interval).
 *
 * \param[in] ant Antenna valid values are 1, 2 and 65535
 *                1 : Tx/Rx antenna 1
 *                2 : Tx/Rx antenna 2
 *	          0xFFFF: Tx/Rx antenna diversity
 * \param[in] evaluate_time
 *	      SAD evaluate time interval, default value is 6s(0x1770).
 *  \param[in] evaluate_mode
 *	            0: PCB Ant  + Ext Ant0
 *              1: Ext Ant0 + Ext Ant1
 *              2: PCB Ant  + Ext Ant1
 *           0xFF: Default divisity mode.
 *
 * \return WM_SUCCESS if successful.
 * \return WLAN_ERROR_STATE if unsuccessful.
 *
 */
int wlan_set_antcfg(uint32_t ant, uint16_t evaluate_time, uint8_t evaluate_mode);

/** This API can be used to get the mode of Tx/Rx antenna.
 * If SAD is enabled, this API can also used to get SAD antenna
 * evaluate time interval(antenna mode must be antenna diversity
 * when set SAD evaluate time interval).
 *
 * \param[out] ant pointer to antenna variable.
 * \param[out] evaluate_time pointer to evaluate_time variable for SAD.
 * \param[out] current_mode pointer to evaluate_mode.
 * \param[out] current_antenna pointer to current antenna.
 *
 * \return WM_SUCCESS if successful.
 * \return WLAN_ERROR_STATE if unsuccessful.
 */
int wlan_get_antcfg(uint32_t *ant, uint16_t *evaluate_time, uint8_t *evaluate_mode, uint16_t *current_antenna);
#endif /*RW610*/

/** Get the wifi firmware version extension string.
 *
 * \note This API does not allocate memory for pointer.
 *       It just returns pointer of WLCMGR internal static
 *       buffer. So no need to free the pointer by caller.
 *
 * \return wifi firmware version extension string pointer stored in
 *         WLCMGR
 */
char *wlan_get_firmware_version_ext(void);

/** Use this API to print wlan driver and firmware extended version.
 */
void wlan_version_extended(void);

/**
 * Use this API to get the TSF from Wi-Fi firmware.
 *
 * \param[in] tsf_high Pointer to store TSF higher 32bits.
 * \param[in] tsf_low Pointer to store TSF lower 32bits.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 *
 */
int wlan_get_tsf(uint32_t *tsf_high, uint32_t *tsf_low);

/** Enable IEEEPS with Host Sleep Configuration
 *
 * When enabled, it opportunistically puts the wireless card into IEEEPS mode.
 * Before putting the Wireless card in power
 * save this also sets the hostsleep configuration on the card as
 * specified. This makes the card generate a wakeup for the processor if
 * any of the wakeup conditions are met.
 *
 * \param[in] wakeup_conditions conditions to wake the host. This should
 *            be a logical OR of the conditions in \ref wlan_wakeup_event_t.
 *            Typically devices would want to wake up on
 *            \ref WAKE_ON_ALL_BROADCAST,
 *            \ref WAKE_ON_UNICAST,
 *            \ref WAKE_ON_MAC_EVENT.
 *            \ref WAKE_ON_MULTICAST,
 *            \ref WAKE_ON_ARP_BROADCAST,
 *            \ref WAKE_ON_MGMT_FRAME
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_ieeeps_on(unsigned int wakeup_conditions);

/** Turn off IEEE Power Save mode.
 *
 * \note This call is asynchronous. The system will exit the power-save mode
 *       only when all requisite conditions are met.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_ieeeps_off(void);

/** Enable WNM with Host Sleep Configuration
 *
 * When enabled, it opportunistically puts the wireless card into IEEEPS mode.
 * Before putting the Wireless card in power
 * save this also sets the hostsleep configuration on the card as
 * specified. This makes the card generate a wakeup for the processor if
 * any of the wakeup conditions are met.
 *
 * \param[in] wakeup_conditions conditions to wake the host. This should
 *            be a logical OR of the conditions in \ref wlan_wakeup_event_t.
 *            Typically devices would want to wake up on
 *            \ref WAKE_ON_ALL_BROADCAST,
 *            \ref WAKE_ON_UNICAST,
 *            \ref WAKE_ON_MAC_EVENT.
 *            \ref WAKE_ON_MULTICAST,
 *            \ref WAKE_ON_ARP_BROADCAST,
 *            \ref WAKE_ON_MGMT_FRAME
 * \param[in] wnm_sleep_time wnm sleep interval.(number of dtims)
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_wnmps_on(unsigned int wakeup_conditions, t_u16 wnm_sleep_time);

/** Turn off WNM Power Save mode.
 *
 * \note This call is asynchronous. The system will exit the power-save mode
 *       only when all requisite conditions are met.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_wnmps_off(void);

/** Turn on Deep Sleep Power Save mode.
 *
 * \note This call is asynchronous. The system will enter the power-save mode
 * only when all requisite conditions are met. For example, wlan should be
 * disconnected for this to work.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_deepsleepps_on(void);

/** Turn off Deep Sleep Power Save mode.
 *
 * \note This call is asynchronous. The system will exit the power-save mode
 *       only when all requisite conditions are met.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL otherwise.
 *
 */
int wlan_deepsleepps_off(void);

/**
 * Use this API to configure the TCP Keep alive parameters in Wi-Fi firmware.
 * \ref wlan_tcp_keep_alive_t provides the parameters which are available
 * for configuration.
 *
 * \note To reset current TCP Keep alive configuration just pass the reset with
 * value 1, all other parameters are ignored in this case.
 *
 * \note Please note that this API must be called after successful connection
 * and before putting Wi-Fi card in IEEE power save mode.
 *
 * \param[in] keep_alive A pointer to \ref wlan_tcp_keep_alive_t
 * 		with following parameters.
 * 	         enable Enable keep alive
 *               reset  Reset keep alive
 *   	         timeout Keep alive timeout
 *   	         interval Keep alive interval
 *               max_keep_alives Maximum keep alives
 *   		 dst_mac Destination MAC address
 *   		 dst_ip Destination IP
 *   		 dst_tcp_port Destination TCP port
 *   		 src_tcp_port Source TCP port
 *   		 seq_no Sequence number
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_tcp_keep_alive(wlan_tcp_keep_alive_t *keep_alive);


/**
 * Use this API to get the beacon period of associated BSS.
 *
 * \return beacon_period if operation is successful.
 * \return 0 if command fails.
 */
uint16_t wlan_get_beacon_period(void);

/**
 * Use this API to get the dtim period of associated BSS.
 *
 * \return dtim_period if operation is successful.
 * \return 0 if DTIM IE Is not found in AP's Probe response.
 * \note This API should not be called from WLAN event handler
 *        registered by application during \ref wlan_start.
 */
uint8_t wlan_get_dtim_period(void);

/**
 * Use this API to get the current tx and rx rates along with
 * bandwidth and guard interval information if rate is 11N.
 *
 * \param[in] ds_rate A pointer to structure which will have
 *            tx, rx rate information along with bandwidth and guard
 *	      interval information.
 *
 * \param[in] bss_type 0: STA, 1: uAP
 *
 * \note If rate is greater than 11 then it is 11N rate and from 12
 *       MCS0 rate starts. The bandwidth mapping is like value 0 is for
 *	 20MHz, 1 is 40MHz, 2 is for 80MHz.
 *	 The guard interval value zero means Long otherwise Short.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_data_rate(wlan_ds_rate *ds_rate, mlan_bss_type bss_type);

/**
 * Use this API to get the set management frame protection parameters for sta.
 *
 * \param[out] mfpc: Management Frame Protection Capable (MFPC)
 *                       1: Management Frame Protection Capable
 *                       0: Management Frame Protection not Capable
 * \param[out] mfpr: Management Frame Protection Required (MFPR)
 *                       1: Management Frame Protection Required
 *                       0: Management Frame Protection Optional
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_pmfcfg(uint8_t *mfpc, uint8_t *mfpr);

/**
 * Use this API to get the set management frame protection parameters for Uap.
 *
 * \param[out] mfpc: Management Frame Protection Capable (MFPC)
 *                       1: Management Frame Protection Capable
 *                       0: Management Frame Protection not Capable
 * \param[out] mfpr: Management Frame Protection Required (MFPR)
 *                       1: Management Frame Protection Required
 *                       0: Management Frame Protection Optional
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_uap_get_pmfcfg(uint8_t *mfpc, uint8_t *mfpr);


/**
 * Use this API to set packet filters in Wi-Fi firmware.
 *
 * \param[in] flt_cfg A pointer to structure which holds the
 *	      the packet filters in same way as given below.\n
 *
 * MEF Configuration command\n
 * mefcfg={\n
 * Criteria: bit0-broadcast, bit1-unicast, bit3-multicast\n
 * Criteria=2 		Unicast frames are received during hostsleepmode\n
 * NumEntries=1		Number of activated MEF entries\n
 * mef_entry_0: example filters to match TCP destination port 80 send by 192.168.0.88 pkt or magic pkt.\n
 * mef_entry_0={\n
 *  mode: bit0--hostsleep mode, bit1--non hostsleep mode\n
 *  mode=1		HostSleep mode\n
 *  action: 0--discard and not wake host, 1--discard and wake host 3--allow and wake host\n
 *  action=3	Allow and Wake host\n
 *  filter_num=3    Number of filter\n
 *   RPN only support "&&" and "||" operator,space can not be removed between operator.\n
 *   RPN=Filter_0 && Filter_1 || Filter_2\n
 *   Byte comparison filter's type is 0x41,Decimal comparison filter's type is 0x42,\n
 *   Bit comparison filter's type is  0x43\n
 *  Filter_0 is decimal comparison filter, it always with type=0x42\n
 *  Decimal filter always has type, pattern, offset, numbyte 4 field\n
 *  Filter_0 will match rx pkt with TCP destination port 80\n
 *  Filter_0={\n
 *    type=0x42	      decimal comparison filter\n
 *    pattern=80      80 is the decimal constant to be compared\n
 *    offset=44	      44 is the byte offset of the field in RX pkt to be compare\n
 *    numbyte=2       2 is the number of bytes of the field\n
 *  }\n
 *  Filter_1 is Byte comparison filter, it always with type=0x41\n
 *  Byte filter always has type, byte, repeat, offset 4 filed\n
 *  Filter_1 will match rx pkt send by IP address 192.168.0.88\n
 *  Filter_1={\n
 *   type=0x41         Byte comparison filter\n
 *   repeat=1          1 copies of 'c0:a8:00:58'\n
 *   byte=c0:a8:00:58  'c0:a8:00:58' is the byte sequence constant with each byte\n
 *   in hex format, with ':' as delimiter between two byte.\n
 *   offset=34         34 is the byte offset of the equal length field of rx'd pkt.\n
 *  }\n
 *  Filter_2 is Magic packet, it will looking for 16 contiguous copies of '00:50:43:20:01:02' from\n
 *  the rx pkt's offset 14\n
 *  Filter_2={\n
 *   type=0x41	       Byte comparison filter\n
 *   repeat=16         16 copies of '00:50:43:20:01:02'\n
 *   byte=00:50:43:20:01:02  # '00:50:43:20:01:02' is the byte sequence constant\n
 *   offset=14	       14 is the byte offset of the equal length field of rx'd pkt.\n
 *  }\n
 * }\n
 * }\n
 * Above filters can be set by filling values in following way in \ref wlan_flt_cfg_t structure.\n
 * wlan_flt_cfg_t flt_cfg;\n
 * uint8_t byte_seq1[] = {0xc0, 0xa8, 0x00, 0x58};\n
 * uint8_t byte_seq2[] = {0x00, 0x50, 0x43, 0x20, 0x01, 0x02};\n
 *\n
 * memset(&flt_cfg, 0, sizeof(wlan_flt_cfg_t));\n
 *\n
 * flt_cfg.criteria = 2;\n
 * flt_cfg.nentries = 1;\n
 *\n
 * flt_cfg.mef_entry.mode = 1;\n
 * flt_cfg.mef_entry.action = 3;\n
 *\n
 * flt_cfg.mef_entry.filter_num = 3;\n
 *\n
 * flt_cfg.mef_entry.filter_item[0].type = TYPE_DNUM_EQ;\n
 * flt_cfg.mef_entry.filter_item[0].pattern = 80;\n
 * flt_cfg.mef_entry.filter_item[0].offset = 44;\n
 * flt_cfg.mef_entry.filter_item[0].num_bytes = 2;\n
 *\n
 * flt_cfg.mef_entry.filter_item[1].type = TYPE_BYTE_EQ;\n
 * flt_cfg.mef_entry.filter_item[1].repeat = 1;\n
 * flt_cfg.mef_entry.filter_item[1].offset = 34;\n
 * flt_cfg.mef_entry.filter_item[1].num_byte_seq = 4;\n
 * memcpy(flt_cfg.mef_entry.filter_item[1].byte_seq, byte_seq1, 4);\n
 * flt_cfg.mef_entry.rpn[1] = RPN_TYPE_AND;\n
 *\n
 * flt_cfg.mef_entry.filter_item[2].type = TYPE_BYTE_EQ;\n
 * flt_cfg.mef_entry.filter_item[2].repeat = 16;\n
 * flt_cfg.mef_entry.filter_item[2].offset = 14;\n
 * flt_cfg.mef_entry.filter_item[2].num_byte_seq = 6;\n
 * memcpy(flt_cfg.mef_entry.filter_item[2].byte_seq, byte_seq2, 6);\n
 * flt_cfg.mef_entry.rpn[2] = RPN_TYPE_OR;\n
 *
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_packet_filters(wlan_flt_cfg_t *flt_cfg);

/**
 * Use this API to enable ARP Offload in Wi-Fi firmware
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_auto_arp(void);


/**
 * Use this API to enable WOWLAN on magic pkt rx in Wi-Fi firmware
 *
 * \param[in] ptn_cfg A pointer to \ref wlan_wowlan_ptn_cfg_t containing Wake on WLAN pattern configuration
 *
 *\return WM_SUCCESS if operation is successful.
 *\return -WM_FAIL if command fails
 */
int wlan_wowlan_cfg_ptn_match(wlan_wowlan_ptn_cfg_t *ptn_cfg);
/**
 * Use this API to enable NS Offload in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_ipv6_ns_offload();

#ifdef CONFIG_HOST_SLEEP

/** WLCMGR host sleep pre configuration */
void wlan_hs_pre_cfg(void);

/** WLCMGR host sleep post configuration */
void wlan_hs_post_cfg(void);

/**
 * Use this API to configure host sleep params in Wi-Fi firmware.
 *
 * \param[in] wakeup_condition  bit 0: WAKE_ON_ALL_BROADCAST
 *                              bit 1: WAKE_ON_UNICAST
 *                              bit 2: WAKE_ON_MAC_EVENT
 *                              bit 3: WAKE_ON_MULTICAST
 *                              bit 4: WAKE_ON_ARP_BROADCAST
 *                              bit 6: WAKE_ON_MGMT_FRAME
 *                              All bit 0 discard and not wakeup host
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_send_host_sleep(uint32_t wakeup_condition);

/**
 * Use this API to get host sleep wakeup reason from Wi-Fi firmware.
 *
 * \param[out] hs_wakeup_reason wakeupReason:
 *                              0: unknown
 *                              1: Broadcast data matched
 *                              2: Multicast data matched
 *                              3: Unicast data matched
 *                              4: Maskable event matched
 *                              5. Non-maskable event matched
 *                              6: Non-maskable condition matched (EAPoL rekey)
 *                              7: Magic pattern matched
 *                              Others: reserved. (set to 0)
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_wakeup_reason(uint16_t *hs_wakeup_reason);
#endif

/**
 * Use this API to get the BSSID of associated BSS.
 *
 * \param[in] bssid A pointer to array to store the BSSID.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_current_bssid(uint8_t *bssid);

/**
 * Use this API to get the channel number of associated BSS.
 *
 * \return channel number if operation is successful.
 * \return 0 if command fails.
 */
uint8_t wlan_get_current_channel(void);

#ifdef CONFIG_WIFI_GET_LOG
/**
 * Use this API to get the various statistics of sta from Wi-Fi firmware like
 * number of beacons received, missed and so on.
 *
 * \param[in] stats A pointer to structure where stats collected from Wi-Fi firmware
 *	      will be copied.
 * \note Please explore the elements of the \ref wlan_pkt_stats_t strucutre for
 * 	 more information on stats.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_log(wlan_pkt_stats_t *stats);

/**
 * Use this API to get the various statistics of uap from Wi-Fi firmware like
 * number of beacons received, missed and so on.
 *
 * \param[in] stats A pointer to structure where stats collected from Wi-Fi firmware
 *	      will be copied.
 * \note Please explore the elements of the \ref wlan_pkt_stats_t strucutre for
 * 	 more information on stats.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_uap_get_log(wlan_pkt_stats_t *stats);
#endif

/** Get station interface power save mode.
 *
 * \param[out] ps_mode A pointer to \ref wlan_ps_mode where station interface
 * 	      power save mode will be stored.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_E_INVAL if \a ps_mode was NULL.
 */
int wlan_get_ps_mode(enum wlan_ps_mode *ps_mode);

/** Send message to WLAN Connection Manager thread.
 *
 * \param[in] event An event from \ref wifi_event.
 * \param[in] reason A reason code.
 * \param[in] data A pointer to data buffer associated with event.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if failed.
 */
int wlan_wlcmgr_send_msg(enum wifi_event event, enum wifi_event_reason reason, void *data);

/** Register WFA basic WLAN CLI commands
 *
 * This function registers basic WLAN CLI commands like showing
 * version information, MAC address
 *
 * \note This function can only be called by the application after
 * \ref wlan_init() called.
 *
 * \return WLAN_ERROR_NONE if the CLI commands were registered or
 * \return WLAN_ERROR_ACTION if they were not registered (for example
 *   if this function was called while the CLI commands were already
 *   registered).
 */
int wlan_wfa_basic_cli_init(void);

/** Unregister WFA basic WLAN CLI commands
 *
 * This function unregisters basic WLAN CLI commands like showing
 * version information, MAC address
 *
 * \note This function can only be called by the application after
 * \ref wlan_init() called.
 *
 * \return WLAN_ERROR_NONE if the CLI commands were unregistered or
 * \return WLAN_ERROR_ACTION if they were not unregistered
 */
int wlan_wfa_basic_cli_deinit(void);

/** Register basic WLAN CLI commands
 *
 * This function registers basic WLAN CLI commands like showing
 * version information, MAC address
 *
 * \note This function can only be called by the application after
 * \ref wlan_init() called.
 *
 * \note This function gets called by \ref wlan_cli_init(), hence
 * only one function out of these two functions should be called in
 * the application.
 *
 * \return WLAN_ERROR_NONE if the CLI commands were registered or
 * \return WLAN_ERROR_ACTION if they were not registered (for example
 *   if this function was called while the CLI commands were already
 *   registered).
 */
int wlan_basic_cli_init(void);

/** Unregister basic WLAN CLI commands
 *
 * This function unregisters basic WLAN CLI commands like showing
 * version information, MAC address
 *
 * \note This function can only be called by the application after
 * \ref wlan_init() called.
 *
 * \note This function gets called by \ref wlan_cli_init(), hence
 * only one function out of these two functions should be called in
 * the application.
 *
 * \return WLAN_ERROR_NONE if the CLI commands were unregistered or
 * \return WLAN_ERROR_ACTION if they were not unregistered (for example
 *   if this function was called while the CLI commands were already
 *   registered).
 */
int wlan_basic_cli_deinit(void);

/** Register WLAN CLI commands.
 *
 *  Try to register the WLAN CLI commands with the CLI subsystem. This
 *  function is available for the application for use.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \note This function internally calls \ref wlan_basic_cli_init(), hence
 *  only one function out of these two functions should be called in
 *  the application.
 *
 *  \return WM_SUCCESS if the CLI commands were registered or
 *  \return -WM_FAIL if they were not (for example if this function
 *          was called while the CLI commands were already registered).
 */
int wlan_cli_init(void);

/** Unregister WLAN CLI commands.
 *
 *  Try to unregister the WLAN CLI commands with the CLI subsystem. This
 *  function is available for the application for use.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \note This function internally calls \ref wlan_basic_cli_deinit(), hence
 *  only one function out of these two functions should be called in
 *  the application.
 *
 *  \return WM_SUCCESS if the CLI commands were unregistered or
 *  \return -WM_FAIL if they were not (for example if this function
 *          was called while the CLI commands were already unregistered).
 */
int wlan_cli_deinit(void);

/** Register WLAN enhanced CLI commands.
 *
 *  Register the WLAN enhanced CLI commands like set or get tx-power,
 *  tx-datarate, tx-modulation etc with the CLI subsystem.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \return WM_SUCCESS if the CLI commands were registered or
 *  \return -WM_FAIL if they were not (for example if this function
 *           was called while the CLI commands were already registered).
 */
int wlan_enhanced_cli_init(void);

/** Unregister WLAN enhanced CLI commands.
 *
 *  Unregister the WLAN enhanced CLI commands like set or get tx-power,
 *  tx-datarate, tx-modulation etc with the CLI subsystem.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \return WM_SUCCESS if the CLI commands were unregistered or
 *  \return -WM_FAIL if they were not unregistered.
 */

int wlan_enhanced_cli_deinit(void);

#ifdef CONFIG_RF_TEST_MODE
/** Register WLAN Test Mode CLI commands.
 *
 *  Register the WLAN Test Mode CLI commands like set or get channel,
 *  band, bandwidth, PER and more with the CLI subsystem.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \return WM_SUCCESS if the CLI commands were registered or
 *  \return -WM_FAIL if they were not (for example if this function
 *           was called while the CLI commands were already registered).
 */
int wlan_test_mode_cli_init(void);

/** Unregister WLAN Test Mode CLI commands.
 *
 *  Unregister the WLAN Test Mode CLI commands like set or get channel,
 *  band, bandwidth, PER and more with the CLI subsystem.
 *
 *  \note This function can only be called by the application after \ref wlan_init()
 *  called.
 *
 *  \return WM_SUCCESS if the CLI commands were unregistered or
 *  \return -WM_FAIL if they were not unregistered
 */
int wlan_test_mode_cli_deinit(void);
#endif

/**
 * Get maximum number of WLAN firmware supported stations that
 * will be allowed to connect to the uAP.
 *
 * \return Maximum number of WLAN firmware supported stations.
 *
 * \note Get operation is allowed in any uAP state.
 */
unsigned int wlan_get_uap_supported_max_clients(void);

/**
 * Get current maximum number of stations that
 * will be allowed to connect to the uAP.
 *
 * \param[out] max_sta_num A pointer to variable where current maximum
 *             number of stations of uAP interface will be stored.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 * \note Get operation is allowed in any uAP state.
 */
int wlan_get_uap_max_clients(unsigned int *max_sta_num);

/**
 * Set maximum number of stations that will be allowed to connect to the uAP.
 *
 * \param[in] max_sta_num Number of maximum stations for uAP.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 * \note Set operation in not allowed in \ref WLAN_UAP_STARTED state.
 */
int wlan_set_uap_max_clients(unsigned int max_sta_num);

/**
 * This API can be used to configure some of parameters in HTCapInfo IE
 *       (such as Short GI, Channel BW, and Green field support)
 *
 * \param[in] htcapinfo This is a bitmap and should be used as following\n
 *               Bit 29: Green field enable/disable\n
 *               Bit 26: Rx STBC Support enable/disable. (As we support\n
 *                       single spatial stream only 1 bit is used for Rx STBC)\n
 *               Bit 25: Tx STBC support enable/disable.\n
 *               Bit 24: Short GI in 40 Mhz enable/disable\n
 *               Bit 23: Short GI in 20 Mhz enable/disable\n
 *               Bit 22: Rx LDPC enable/disable\n
 *               Bit 17: 20/40 Mhz enable disable.\n
 *               Bit  8: Enable/disable 40Mhz Intolarent bit in ht capinfo.\n
 *                       0 will reset this bit and 1 will set this bit in\n
 *                       htcapinfo attached in assoc request.\n
 *               All others are reserved and should be set to 0.\n
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_htcapinfo(unsigned int htcapinfo);

/**
 * This API can be used to configure various 11n specific configuration
 *       for transmit (such as Short GI, Channel BW and Green field support)
 *
 * \param[in] httxcfg This is a bitmap and should be used as following\n
 *               Bit 15-10: Reserved set to 0\n
 *               Bit 9-8: Rx STBC set to 0x01\n
 *               BIT9 BIT8  Description\n
 *               0    0     No spatial streams\n
 *               0    1     One spatial streams supported\n
 *               1    0     Reserved\n
 *               1    1     Reserved\n
 *               Bit 7: STBC enable/disable\n
 *               Bit 6: Short GI in 40 Mhz enable/disable\n
 *               Bit 5: Short GI in 20 Mhz enable/disable\n
 *               Bit 4: Green field enable/disable\n
 *               Bit 3-2: Reserved set to 1\n
 *               Bit 1: 20/40 Mhz enable disable.\n
 *               Bit 0: LDPC enable/disable\n
 *
 *       When Bit 1 is set then firmware could transmit in 20Mhz or 40Mhz based\n
 *       on rate adaptation. When this bit is reset then firmware will only\n
 *       transmit in 20Mhz.\n
 *
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_httxcfg(unsigned short httxcfg);

/**
 * This API can be used to set the transmit data rate.
 *
 * \note The data rate can be set only after association.
 *
 * \param[in] ds_rate struct contains following fields
 *             sub_command It should be WIFI_DS_RATE_CFG
 *             and rate_cfg should have following parameters.\n
 *              rate_format - This parameter specifies
 *                              the data rate format used
 *                              in this command\n
 *               0:    LG\n
 *               1:    HT\n
 *               2:    VHT\n
 *               0xff: Auto\n
 *
 *              index - This parameter specifies the rate or MCS index\n
 *              If  rate_format is 0 (LG),\n
 *               0       1 Mbps\n
 *               1       2 Mbps\n
 *               2       5.5 Mbps\n
 *               3       11 Mbps\n
 *               4       6 Mbps\n
 *               5       9 Mbps\n
 *               6       12 Mbps\n
 *               7       18 Mbps\n
 *               8       24 Mbps\n
 *               9       36 Mbps\n
 *               10      48 Mbps\n
 *               11      54 Mbps\n
 *              If  rate_format is 1 (HT),\n
 *               0       MCS0\n
 *               1       MCS1\n
 *               2       MCS2\n
 *               3       MCS3\n
 *               4       MCS4\n
 *               5       MCS5\n
 *               6       MCS6\n
 *               7       MCS7\n
 *	        If STREAM_2X2\n
 *               8       MCS8\n
 *               9       MCS9\n
 *               10      MCS10\n
 *               11      MCS11\n
 *               12      MCS12\n
 *               13      MCS13\n
 *               14      MCS14\n
 *               15      MCS15\n
 *              If  rate_format is 2 (VHT),\n
 *               0       MCS0\n
 *               1       MCS1\n
 *               2       MCS2\n
 *               3       MCS3\n
 *               4       MCS4\n
 *               5       MCS5\n
 *               6       MCS6\n
 *               7       MCS7\n
 *               8       MCS8\n
 *               9       MCS9\n
 *              nss - This parameter specifies the NSS.\n
 *			It is valid only for VHT\n
 *              If  rate_format is 2 (VHT),\n
 *               1       NSS1\n
 *               2       NSS2\n
 *
 * \param[in] bss_type 0: STA, 1: uAP
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_txratecfg(wlan_ds_rate ds_rate, mlan_bss_type bss_type);

/**
 * This API can be used to get the transmit data rate.
 *
 * \param[in] ds_rate A pointer to \ref wlan_ds_rate where Tx Rate
 * 		configuration will be stored.
 * \param[in] bss_type 0: STA, 1: uAP
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_get_txratecfg(wlan_ds_rate *ds_rate, mlan_bss_type bss_type);

/**
 * Get Station interface transmit power
 *
 * \param[out] power_level Transmit power level.
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_get_sta_tx_power(t_u32 *power_level);

/**
 * Set Station interface transmit power
 *
 * \param[in] power_level Transmit power level.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_sta_tx_power(t_u32 power_level);

/**
 * Set World Wide Safe Mode Tx Power Limits
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_wwsm_txpwrlimit(void);

#ifndef RW610
/**
 * Get wlan region code from tx power config
 *
 * \return wlan region code in string format.
 *
 */
const char *wlan_get_wlan_region_code(void);
#endif

/**
 * Get Management IE for given BSS type (interface) and index.
 *
 * \param[in] bss_type 0: STA, 1: uAP
 * \param[in] index IE index.
 *
 * \param[out] buf Buffer to store requested IE data.
 * \param[out] buf_len To store length of IE data.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_get_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t index, void *buf, unsigned int *buf_len);

/**
 * Set Management IE for given BSS type (interface) and index.
 *
 * \param[in] bss_type 0: STA, 1: uAP
 * \param[in] id Type/ID of Management IE.
 * \param[in] buf Buffer containing IE data.
 * \param[in] buf_len Length of IE data.
 *
 * \return IE index if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t id, void *buf, unsigned int buf_len);

#ifdef SD8801
/**
 * Get External Radio Coex statistics.
 *
 * \param[out] ext_coex_stats A pointer to structure to get coex statistics.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_get_ext_coex_stats(wlan_ext_coex_stats_t *ext_coex_stats);

/**
 * Set External Radio Coex configuration.
 *
 * \param[in] ext_coex_config to apply coex configuration.
 *
 * \return IE index if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_set_ext_coex_config(const wlan_ext_coex_config_t ext_coex_config);
#endif

/**
 * Clear Management IE for given BSS type (interface) and index.
 *
 * \param[in] bss_type 0: STA, 1: uAP
 * \param[in] index IE index.
 * \param[in] mgmt_bitmap_index mgmt bitmap index.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_FAIL if unsuccessful.
 *
 */
int wlan_clear_mgmt_ie(enum wlan_bss_type bss_type, IEEEtypes_ElementId_t index, int mgmt_bitmap_index);

/**
 * Get current status of 11d support.
 *
 * \return true if 11d support is enabled by application.
 * \return false if not enabled.
 *
 */
bool wlan_get_11d_enable_status(void);

/**
 * Get current RSSI and Signal to Noise ratio from WLAN firmware.
 *
 * \param[in] rssi A pointer to variable to store current RSSI
 * \param[in] snr A pointer to variable to store current SNR.
 *
 * \return WM_SUCCESS if successful.
 */
int wlan_get_current_signal_strength(short *rssi, int *snr);

/**
 * Get average RSSI and Signal to Noise ratio from WLAN firmware.
 *
 * \param[in] rssi A pointer to variable to store current RSSI
 * \param[in] snr A pointer to variable to store current SNR.
 *
 * \return WM_SUCCESS if successful.
 */
int wlan_get_average_signal_strength(short *rssi, int *snr);

/**
 * This API is is used to set/cancel the remain on channel configuration.
 *
 * \note When status is false, channel and duration parameters are
 * ignored.
 *
 * \param[in] bss_type The interface to set channel  bss_type 0: STA, 1: uAP
 * \param[in] status false : Cancel the remain on channel configuration
 *                   true : Set the remain on channel configuration
 * \param[in] channel The channel to configure
 * \param[in] duration The duration for which to
 *	      remain on channel in milliseconds.
 *
 * \return WM_SUCCESS on success or error code.
 *
 */
int wlan_remain_on_channel(const enum wlan_bss_type bss_type,
                           const bool status,
                           const uint8_t channel,
                           const uint32_t duration);

/**
 * Get User Data from OTP Memory
 *
 * \param[in] buf Pointer to buffer where data will be stored
 * \param[in] len Number of bytes to read
 *
 * \return WM_SUCCESS if user data read operation is successful.
 * \return -WM_E_INVAL if buf is not valid or of insufficient size.
 * \return -WM_FAIL if user data field is not present or command fails.
 */
int wlan_get_otp_user_data(uint8_t *buf, uint16_t len);

/**
 * Get calibration data from WLAN firmware
 *
 * \param[out] cal_data Pointer to calibration data structure where
 *	      calibration data and it's length will be stored.
 *
 * \return WM_SUCCESS if cal data read operation is successful.
 * \return -WM_E_INVAL if cal_data is not valid.
 * \return -WM_FAIL if command fails.
 *
 * \note The user of this API should free the allocated buffer for
 *	 calibration data.
 */
int wlan_get_cal_data(wlan_cal_data_t *cal_data);

#ifdef CONFIG_COMPRESS_TX_PWTBL
/**
 * Set the compressed Tx PWR Limit configuration.
 *
 * \param[in] data A pointer to TX PWR Limit configuration.
 * \param[in] len Length of TX PWR Limit configuration.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 */
int wlan_set_region_power_cfg(const t_u8 *data, t_u16 len);
#endif

/**
 * Set the Channel List and TRPC channel configuration.
 *
 * \param[in] chanlist A poiner to \ref wlan_chanlist_t Channel List configuration.
 * \param[in] txpwrlimit A pointer to \ref wlan_txpwrlimit_t TX PWR Limit configuration.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 */
int wlan_set_chanlist_and_txpwrlimit(wlan_chanlist_t *chanlist, wlan_txpwrlimit_t *txpwrlimit);

/**
 * Set the Channel List configuration.
 *
 * \param[in] chanlist A pointer to \ref wlan_chanlist_t Channel List configuration.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 * \note If Region Enforcement Flag is enabled in the OTP then this API will
 * not take effect.
 */
int wlan_set_chanlist(wlan_chanlist_t *chanlist);

/**
 * Get the Channel List configuration.
 *
 * \param[out] chanlist A pointer to \ref wlan_chanlist_t Channel List configuration.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 * \note The \ref wlan_chanlist_t struct allocates memory for a maximum of 54
 * channels.
 *
 */
int wlan_get_chanlist(wlan_chanlist_t *chanlist);

/**
 * Set the TRPC channel configuration.
 *
 * \param[in] txpwrlimit A pointer to \ref wlan_txpwrlimit_t TX PWR Limit configuration.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 */
int wlan_set_txpwrlimit(wlan_txpwrlimit_t *txpwrlimit);

/**
 * Get the TRPC channel configuration.
 *
 * \param[in] subband  Where subband is:\n
 *              0x00 2G subband  (2.4G: channel 1-14)\n
 *              0x10 5G subband0 (5G: channel 36,40,44,48,\n
 *                                            52,56,60,64)\n
 *              0x11 5G subband1 (5G: channel 100,104,108,112,\n
 *                                            116,120,124,128,\n
 *                                            132,136,140,144)\n
 *              0x12 5G subband2 (5G: channel 149,153,157,161,165,172)\n
 *              0x13 5G subband3 (5G: channel 183,184,185,187,188,\n
 *                                            189, 192,196;\n
 *                                5G: channel 7,8,11,12,16,34)\n
 *
 * \param[out] txpwrlimit A pointer to \ref wlan_txpwrlimit_t TX PWR
 * 		Limit configuration structure where Wi-Fi firmware
 * 		configuration will get copied.
 *
 * \return WM_SUCCESS on success, error otherwise.
 *
 * \note application can use print_txpwrlimit API to print the
 *	 content of the txpwrlimit structure.
 */
int wlan_get_txpwrlimit(wifi_SubBand_t subband, wifi_txpwrlimit_t *txpwrlimit);

#ifdef CONFIG_AUTO_RECONNECT
/**
 * Enable Auto Reconnect feature in WLAN firmware.
 *
 * \param[in] auto_reconnect_config Auto Reconnect configuration
 *	      structure holding following parameters:
 *	      1. reconnect counter(0x1-0xff) - The number of times the WLAN
 *		 firmware retries connection attempt with AP.
 *				The value 0xff means retry forever.
 *				(default 0xff).
 *	      2. reconnect interval(0x0-0xff) - Time gap in seconds between
 *				each connection attempt (default 10).
 *	      3. flags - Bit 0:
 *			 Set to 1: Firmware should report link-loss to host
 *				if AP rejects authentication/association
 *				while reconnecting.
 *			 Set to 0: Default behaviour: Firmware does not report
 *				link-loss to host on AP rejection and
 *				continues internally.
 *			 Bit 1-15: Reserved.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 *
 */
int wlan_auto_reconnect_enable(wlan_auto_reconnect_config_t auto_reconnect_config);

/**
 * Disable Auto Reconnect feature in WLAN firmware.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 *
 */
int wlan_auto_reconnect_disable(void);

/**
 * Get Auto Reconnect configuration from WLAN firmware.
 *
 * \param[out] auto_reconnect_config Auto Reconnect configuration
 *	       structure where response from WLAN firmware will
 *	       get stored.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_E_INVAL if auto_reconnect_config is not valid.
 * \return -WM_FAIL if command fails.
 *
 */
int wlan_get_auto_reconnect_config(wlan_auto_reconnect_config_t *auto_reconnect_config);
#endif
/**
 * Set Reassociation Control in WLAN Connection Manager
 * \note Reassociation is enabled by default in the WLAN Connection Manager.
 *
 * \param[in] reassoc_control Reassociation enable/disable
 *
 */
void wlan_set_reassoc_control(bool reassoc_control);

/** API to set the beacon period of uAP
 *
 *\param[in] beacon_period Beacon period in TU (1 TU = 1024 micro seconds)
 *
 *\note Please call this API before calling uAP start API.
 *
 */
void wlan_uap_set_beacon_period(const uint16_t beacon_period);

/** API to set the bandwidth of uAP
 *
 *\param[in] bandwidth Wi-Fi AP Bandwidth (20MHz/40MHz)
    1: 20 MHz 2: 40 MHz 3: 80 MHz
 *
 *\return WM_SUCCESS if successful otherwise failure.
 *\return -WM_FAIL if command fails.
 *
 *\note Please call this API before calling uAP start API.
 *\note Default bandwidth setting is 40 MHz.
 *
 */
int wlan_uap_set_bandwidth(const uint8_t bandwidth);

/** API to Get the bandwidth of uAP
 *
 *\param[out] bandwidth Wi-Fi AP Bandwidth (20MHz/40MHz)
    1: 20 MHz 2: 40 MHz 3: 80 MHz
 *
 *\return WM_SUCCESS if successful otherwise failure.
 *\return -WM_FAIL if command fails.
 *
 *\note Please call this API before calling uAP start API.
 *
 */
int wlan_uap_get_bandwidth(uint8_t *bandwidth);

/** API to control SSID broadcast capability of uAP
 *
 * This API enables/disables the SSID broadcast feature
 * (also known as the hidden SSID feature). When broadcast SSID
 * is enabled, the AP responds to probe requests from client stations
 * that contain null SSID. When broadcast SSID is disabled, the AP
 * does not respond to probe requests that contain null SSID and
 * generates beacons that contain null SSID.
 *
 *\param[in] hidden_ssid Hidden SSID control
 *           hidden_ssid=0: broadcast SSID in beacons.
 *           hidden_ssid=1: send empty SSID (length=0) in beacon.
 *           hidden_ssid=2: clear SSID (ACSII 0), but keep the original length
 *
 *\return WM_SUCCESS if successful otherwise failure.
 *\return -WM_FAIL if command fails.
 *
 *\note Please call this API before calling uAP start API.
 *
 */
int wlan_uap_set_hidden_ssid(const t_u8 hidden_ssid);

/** API to control the deauth during uAP channel switch
 *
 *\param[in] enable 0 -- Wi-Fi firmware will use default behaviour.
 *		    1 -- Wi-Fi firmware will not send deauth packet
 *		         when uap move to another channel.
 *
 *\note Please call this API before calling uAP start API.
 *
 */
void wlan_uap_ctrl_deauth(const bool enable);

/** API to enable channel switch announcement functionality on uAP.
 *
 *\note Please call this API before calling uAP start API. Also
 *	note that 11N should be enabled on uAP. The channel switch announcement IE
 *	is transmitted in 7 beacons before the channel switch, during a station
 *	connection attempt on a different channel with Ex-AP.
 *
 */
void wlan_uap_set_ecsa(void);

/** API to set the HT Capability Information of uAP
 *
 *\param[in] ht_cap_info - This is a bitmap and should be used as following\n
 *             Bit 15: L Sig TxOP protection - reserved, set to 0 \n
 *             Bit 14: 40 MHz intolerant - reserved, set to 0 \n
 *             Bit 13: PSMP - reserved, set to 0 \n
 *             Bit 12: DSSS Cck40MHz mode\n
 *             Bit 11: Maximal AMSDU size - reserved, set to 0 \n
 *             Bit 10: Delayed BA - reserved, set to 0 \n
 *             Bits 9:8: Rx STBC - reserved, set to 0 \n
 *             Bit 7: Tx STBC - reserved, set to 0 \n
 *             Bit 6: Short GI 40 MHz\n
 *             Bit 5: Short GI 20 MHz\n
 *             Bit 4: GF preamble\n
 *             Bits 3:2: MIMO power save - reserved, set to 0 \n
 *             Bit 1: SuppChanWidth - set to 0 for 2.4 GHz band \n
 *             Bit 0: LDPC coding - reserved, set to 0 \n
 *
 *\note Please call this API before calling uAP start API.
 *
 */
void wlan_uap_set_htcapinfo(const uint16_t ht_cap_info);

/**
 * This API can be used to configure various 11n specific configuration
 *       for transmit (such as Short GI, Channel BW and Green field support)
 *       for uAP interface.
 *
 * \param[in] httxcfg This is a bitmap and should be used as following\n
 *               Bit 15-8: Reserved set to 0\n
 *               Bit 7: STBC enable/disable\n
 *               Bit 6: Short GI in 40 Mhz enable/disable\n
 *               Bit 5: Short GI in 20 Mhz enable/disable\n
 *               Bit 4: Green field enable/disable\n
 *               Bit 3-2: Reserved set to 1\n
 *               Bit 1: 20/40 Mhz enable disable.\n
 *               Bit 0: LDPC enable/disable\n
 *
 *       When Bit 1 is set then firmware could transmit in 20Mhz or 40Mhz based\n
 *       on rate adaptation. When this bit is reset then firmware will only\n
 *       transmit in 20Mhz.\n
 *
 *\note Please call this API before calling uAP start API.
 *
 */
void wlan_uap_set_httxcfg(unsigned short httxcfg);

/**
 * This API can be used to enable AMPDU support on the go
 * when station is a transmitter.
 *
 * \note By default the station AMPDU TX support is on if
 * configuration option is enabled in defconfig.
 */
void wlan_sta_ampdu_tx_enable(void);

/**
 * This API can be used to disable AMPDU support on the go
 * when station is a transmitter.
 *
 *\note By default the station AMPDU RX support is on if
 * configuration option is enabled in defconfig.
 *
 */
void wlan_sta_ampdu_tx_disable(void);

/**
 * This API can be used to enable AMPDU support on the go
 * when station is a receiver.
 */
void wlan_sta_ampdu_rx_enable(void);

/**
 * This API can be used to disable AMPDU support on the go
 * when station is a receiver.
 */
void wlan_sta_ampdu_rx_disable(void);

/**
 * This API can be used to enable AMPDU support on the go
 * when uap is a transmitter.
 *
 * \note By default the uap AMPDU TX support is on if
 * configuration option is enabled in defconfig.
 */
void wlan_uap_ampdu_tx_enable(void);

/**
 * This API can be used to disable AMPDU support on the go
 * when uap is a transmitter.
 *
 *\note By default the uap AMPDU RX support is on if
 * configuration option is enabled in defconfig.
 *
 */
void wlan_uap_ampdu_tx_disable(void);

/**
 * This API can be used to enable AMPDU support on the go
 * when uap is a receiver.
 */
void wlan_uap_ampdu_rx_enable(void);

/**
 * This API can be used to disable AMPDU support on the go
 * when uap is a receiver.
 */
void wlan_uap_ampdu_rx_disable(void);


/**
 * Set number of channels and channel number used during automatic
 * channel selection of uAP.
 *
 *\param[in] scan_chan_list A structure holding the number of channels and
 *	     channel numbers.
 *
 *\note Please call this API before uAP start API in order to set the user
 *      defined channels, otherwise it will have no effect. There is no need
 *      to call this API every time before uAP start, if once set same channel
 *      configuration will get used in all upcoming uAP start call. If user
 *      wish to change the channels at run time then it make sense to call
 *      this API before every uAP start API.
 */
void wlan_uap_set_scan_chan_list(wifi_scan_chan_list_t scan_chan_list);

#ifdef CONFIG_WPA2_ENTP

/**
 * Use this API if application want to allow station
 * connection to WPA2 Enterprise ap profiles only.
 *
 * If called the in scan result only the WPA2 Enterprise AP
 * will be listed and station network profile only with WPA2
 * Enterprise security will be allowed to add to network profile
 * list.
 */
void wlan_enable_wpa2_enterprise_ap_only();
#endif

/**
 * Set the rts threshold of sta in WLAN firmware.
 *
 * \param[in] rts the value of rts threshold configuration.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_rts(int rts);

/**
 * Set the rts threshold of uap in WLAN firmware.
 *
 * \param[in] rts the value of rts threshold configuration.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_uap_rts(int rts);

/**
 * Set the fragment threshold of sta in WLAN firmware.
 *
 * \param[in] frag the value of fragment threshold configuration.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_frag(int frag);

/**
 * Set the fragment threshold of uap in WLAN firmware.
 *
 * \param[in] frag the value of fragment threshold configuration.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_uap_frag(int frag);


/**
 * Set the sta mac filter in Wi-Fi firmware.
 *
 * \param[in] filter_mode channel filter mode (disable/white/black list)
 * \param[in] mac_count the count of mac list
 * \param[in] mac_addr the pointer to mac address list
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_sta_mac_filter(int filter_mode, int mac_count, unsigned char *mac_addr);

static inline void print_mac(const char *mac)
{
    (void)PRINTF("%02X:%02X:%02X:%02X:%02X:%02X ", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

#ifdef CONFIG_RF_TEST_MODE

/**
 * Set the RF Test Mode on in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_rf_test_mode(void);

/**
 * UnSet the RF Test Mode on in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_unset_rf_test_mode(void);

/**
 * Set the RF Channel in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] channel The channel number to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_channel(const uint8_t channel);

/**
 * Set the RF radio mode in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] mode The radio mode number to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_radio_mode(const uint8_t mode);

/**
 * Get the RF Channel from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] channel A Pointer to a variable where channel number to get.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_channel(uint8_t *channel);

/**
 * Get the RF Radio mode from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] mode A Pointer to a variable where radio mode number to get.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_radio_mode(uint8_t *mode);

/**
 * Set the RF Band in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] band The bandwidth to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_band(const uint8_t band);

/**
 * Get the RF Band from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] band A Pointer to a variable where RF Band is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_band(uint8_t *band);

/**
 * Set the RF Bandwidth in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] bandwidth The bandwidth to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_bandwidth(const uint8_t bandwidth);

/**
 * Get the RF Bandwidth from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] bandwidth A Pointer to a variable where bandwidth to get.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_bandwidth(uint8_t *bandwidth);

/**
 * Get the RF PER from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] rx_tot_pkt_count A Pointer to a variable where Rx Total packet count to get.
 * \param[out] rx_mcast_bcast_count A Pointer to a variable where Rx Total Multicast/Broadcast packet count to get.
 * \param[out] rx_pkt_fcs_error A Pointer to a variable where Rx Total packet count with FCS error to get.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_per(uint32_t *rx_tot_pkt_count, uint32_t *rx_mcast_bcast_count, uint32_t *rx_pkt_fcs_error);

/**
 * Set the RF Tx continuous mode in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] enable_tx Enable Tx.
 * \param[in] cw_mode Set CW Mode.
 * \param[in] payload_pattern Set Payload Pattern.
 * \param[in] cs_mode Set CS Mode.
 * \param[in] act_sub_ch Act Sub Ch
 * \param[in] tx_rate Set Tx Rate.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_tx_cont_mode(const uint32_t enable_tx,
                             const uint32_t cw_mode,
                             const uint32_t payload_pattern,
                             const uint32_t cs_mode,
                             const uint32_t act_sub_ch,
                             const uint32_t tx_rate);

/**
 * Set the RF HE TB TX in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] enable Enable/Disable trigger response mode
 * \param[in] qnum AXQ to be used for the trigger response frame
 * \param[in] aid AID of the peer to which response is to be generated
 * \param[in] axq_mu_timer MU timer for the AXQ on which response is sent
 * \param[in] tx_power TxPwr to be configured for the response
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_cfg_rf_he_tb_tx(uint16_t enable, uint16_t qnum, uint16_t aid, uint16_t axq_mu_timer, int16_t tx_power);

/**
 * Set the RF Trigger Frame Config in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] Enable_tx Enable or Disable trigger frame transmission.
 * \param[in] Standalone_hetb Enable or Disable Standalone HE TB support.
 * \param[in] FRAME_CTRL_TYPE Frame control type.
 * \param[in] FRAME_CTRL_SUBTYPE Frame control subtype.
 * \param[in] FRAME_DURATION Max Duration time.
 * \param[in] TriggerType Identifies the Trigger frame variant and its encoding.
 * \param[in] UlLen Indicates the value of the L-SIG LENGTH field of the solicited HE TB PPDU.
 * \param[in] MoreTF Indicates whether a subsequent Trigger frame is scheduled for transmission.
 * \param[in] CSRequired Required to use ED to sense the medium and to consider the medium state and the NAV in
 * determining whether to respond. \param[in] UlBw Indicates the bandwidth in the HE-SIG-A field of the HE TB PPDU.
 * \param[in] LTFType Indicates the LTF type of the HE TB PPDU response.
 * \param[in] LTFMode Indicates the LTF mode for an HE TB PPDU.
 * \param[in] LTFSymbol Indicates the number of LTF symbols present in the HE TB PPDU.
 * \param[in] UlSTBC Indicates the status of STBC encoding for the solicited HE TB PPDUs.
 * \param[in] LdpcESS Indicates the status of the LDPC extra symbol segment.
 * \param[in] ApTxPwr Indicates the AP’s combined transmit power at the transmit antenna connector of all the antennas
 * used to transmit the triggering PPDU. \param[in] PreFecPadFct Indicates the pre-FEC padding factor. \param[in]
 * PeDisambig Indicates PE disambiguity. \param[in] SpatialReuse Carries the values to be included in the Spatial Reuse
 * fields in the HE-SIG-A field of the solicited HE TB PPDUs. \param[in] Doppler Indicate that a midamble is present in
 * the HE TB PPDU. \param[in] HeSig2 Carries the value to be included in the Reserved field in the HE-SIG-A2 subfield of
 * the solicited HE TB PPDUs. \param[in] AID12 If set to 0 allocates one or more contiguous RA-RUs for associated STAs.
 * \param[in] RUAllocReg RUAllocReg.
 * \param[in] RUAlloc Identifies the size and the location of the RU.
 * \param[in] UlCodingType Indicates the code type of the solicited HE TB PPDU.
 * \param[in] UlMCS Indicates the HE-MCS of the solicited HE TB PPDU.
 * \param[in] UlDCM Indicates DCM of the solicited HE TB PPDU.
 * \param[in] SSAlloc Indicates the spatial streams of the solicited HE TB PPDU.
 * \param[in] UlTargetRSSI Indicates the expected receive signal power.
 * \param[in] MPDU_MU_SF Used for calculating the value by which the minimum MPDU start spacing is multiplied.
 * \param[in] TID_AL Indicates the MPDUs allowed in an A-MPDU carried in the HE TB PPDU and the maximum number of TIDs
 * that can be aggregated by the STA in the A-MPDU. \param[in] AC_PL Reserved. \param[in] Pref_AC Indicates the lowest
 * AC that is recommended for aggregation of MPDUs in the A-MPDU contained in the HE TB PPDU sent as a response to the
 * Trigger frame.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_rf_trigger_frame_cfg(uint32_t Enable_tx,
                              uint32_t Standalone_hetb,
                              uint8_t FRAME_CTRL_TYPE,
                              uint8_t FRAME_CTRL_SUBTYPE,
                              uint16_t FRAME_DURATION,
                              uint64_t TriggerType,
                              uint64_t UlLen,
                              uint64_t MoreTF,
                              uint64_t CSRequired,
                              uint64_t UlBw,
                              uint64_t LTFType,
                              uint64_t LTFMode,
                              uint64_t LTFSymbol,
                              uint64_t UlSTBC,
                              uint64_t LdpcESS,
                              uint64_t ApTxPwr,
                              uint64_t PreFecPadFct,
                              uint64_t PeDisambig,
                              uint64_t SpatialReuse,
                              uint64_t Doppler,
                              uint64_t HeSig2,
                              uint32_t AID12,
                              uint32_t RUAllocReg,
                              uint32_t RUAlloc,
                              uint32_t UlCodingType,
                              uint32_t UlMCS,
                              uint32_t UlDCM,
                              uint32_t SSAlloc,
                              uint8_t UlTargetRSSI,
                              uint8_t MPDU_MU_SF,
                              uint8_t TID_AL,
                              uint8_t AC_PL,
                              uint8_t Pref_AC);

/**
 * Set the RF Tx Antenna in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] antenna The Tx antenna to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_tx_antenna(const uint8_t antenna);

/**
 * Get the RF Tx Antenna from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] antenna A Pointer to a variable where Tx antenna is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_tx_antenna(uint8_t *antenna);

/**
 * Set the RF Rx Antenna in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] antenna The Rx antenna to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_rx_antenna(const uint8_t antenna);

/**
 * Get the RF Rx Antenna from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] antenna A Pointer to a variable where Rx antenna is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_rx_antenna(uint8_t *antenna);

/**
 * Set the RF Tx Power in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] power The RF Tx Power to be set in Wi-Fi firmware.
 *                  For RW610, 20M bandwidth max linear output power is 20db per data sheet.
 * \param[in] mod The modulation to be set in Wi-Fi firmware.
 * \param[in] path_id The Path ID to be set in Wi-Fi firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_tx_power(const uint32_t power, const uint8_t mod, const uint8_t path_id);

/**
 * Set the RF Tx Frame in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] enable Enable/Disable RF Tx Frame
 * \param[in] data_rate Rate Index corresponding to legacy/HT/VHT rates
 * \param[in] frame_pattern Payload Pattern
 * \param[in] frame_length Payload Length
 * \param[in] adjust_burst_sifs Enabl/Disable Adjust Burst SIFS3 Gap
 * \param[in] burst_sifs_in_us Burst SIFS in us
 * \param[in] short_preamble Enable/Disable Short Preamble
 * \param[in] act_sub_ch Enable/Disable Active SubChannel
 * \param[in] short_gi Short Guard Interval
 * \param[in] adv_coding Enable/Disable Adv Coding
 * \param[in] tx_bf Enable/Disable Beamforming
 * \param[in] gf_mode Enable/Disable GreenField Mode
 * \param[in] stbc Enable/Disable STBC
 * \param[in] bssid BSSID
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
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
                         const uint8_t *bssid);

/**
 * Set the RF OTP MAC address in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] mac A Pointer to a variable where OTP MAC address is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_otp_mac_addr(uint8_t *mac);

/**
 * Get the RF OTP MAC address from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] mac A Pointer to a variable where OTP MAC address is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_otp_mac_addr(uint8_t *mac);

/**
 * Set the RF OTP cal data in Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[in] cal_data A Pointer to a variable where OTP cal data is to be stored.
 * \param[in] cal_data_len The length of OTP cal data.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_set_rf_otp_cal_data(const uint8_t *cal_data, uint32_t cal_data_len);

/**
 * Get the RF OTP cal data from Wi-Fi firmware.
 *
 * \note Please call \ref wlan_set_rf_test_mode API before using this API.
 *
 * \param[out] cal_data A Pointer to a variable where OTP cal data is to be stored.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_get_rf_otp_cal_data(uint8_t *cal_data);
#endif
#ifdef CONFIG_WIFI_FW_DEBUG
/** This function registers callbacks which are used to generate FW Dump on USB
 * device.
 *
 * \param[in] wlan_usb_init_cb Callback to initialize usb device.
 * \param[in] wlan_usb_mount_cb Callback to mount usb device.
 * \param[in] wlan_usb_file_open_cb Callback to open file on usb device for FW dump.
 * \param[in] wlan_usb_file_write_cb Callback to write FW dump data to opened file.
 * \param[in] wlan_usb_file_close_cb Callback to close FW dump file.
 *
 */
void wlan_register_fw_dump_cb(void (*wlan_usb_init_cb)(void),
                              int (*wlan_usb_mount_cb)(),
                              int (*wlan_usb_file_open_cb)(char *test_file_name),
                              int (*wlan_usb_file_write_cb)(uint8_t *data, size_t data_len),
                              int (*wlan_usb_file_close_cb)());

#endif

#ifdef CONFIG_WIFI_EU_CRYPTO
#define EU_CRYPTO_DATA_MAX_LENGTH  1300U
#define EU_CRYPTO_KEY_MAX_LENGTH   32U
#define EU_CRYPTO_KEYIV_MAX_LENGTH 32U
#define EU_CRYPTO_NONCE_MAX_LENGTH 14U
#define EU_CRYPTO_AAD_MAX_LENGTH   32U

/** Set Crypto RC4 algorithm encrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 *
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the encrypted
 * data. The value of DataLength is updated to the encrypted data length. The length of the encrypted data is the same
 * as the origin DataLength.
 */
int wlan_set_crypto_RC4_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto RC4 algorithm decrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the decrypted
 * data. The value of DataLength is updated to the decrypted data length. The length of the decrypted data is the same
 * as the origin DataLength.
 */
int wlan_set_crypto_RC4_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto AES_ECB algorithm encrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the encrypted
 * data. The value of DataLength is updated to the encrypted data length. The length of the encrypted data is the same
 * as the origin DataLength.
 */
int wlan_set_crypto_AES_ECB_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto AES_ECB algorithm decrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the decrypted
 * data. The value of DataLength is updated to the decrypted data length. The length of the decrypted data is the same
 * as the origin DataLength.
 */
int wlan_set_crypto_AES_ECB_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto AES_WRAP algorithm encrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the encrypted
 * data. The value of DataLength is updated to the encrypted data length. The encrypted data is 8 bytes more than the
 * original data. Therefore, the address pointed to by Data needs to reserve enough space.
 */
int wlan_set_crypto_AES_WRAP_encrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto AES_WRAP algorithm decrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] KeyIV KeyIV
 * \param[in] KeyIVLength The maximum keyIV length is 32.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the decrypted
 * data. The value of DataLength is updated to the decrypted data length. The decrypted data is 8 bytes less than the
 * original data.
 */
int wlan_set_crypto_AES_WRAP_decrypt(
    const t_u8 *Key, const t_u16 KeyLength, const t_u8 *KeyIV, const t_u16 KeyIVLength, t_u8 *Data, t_u16 *DataLength);

/** Set Crypto AES_CCMP algorithm encrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] AAD AAD
 * \param[in] AADLength The maximum AAD length is 32.
 * \param[in] Nonce Nonce
 * \param[in] NonceLength The maximum Nonce length is 14.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the encrypted
 * data. The value of DataLength is updated to the encrypted data length. The encrypted data is 8 or 16 bytes more than
 * the original data. Therefore, the address pointed to by Data needs to reserve enough space.
 */
int wlan_set_crypto_AES_CCMP_encrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength);

/** Set Crypto AES_CCMP algorithm decrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] AAD AAD
 * \param[in] AADLength The maximum AAD length is 32.
 * \param[in] Nonce Nonce
 * \param[in] NonceLength The maximum Nonce length is 14.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the decrypted
 * data. The value of DataLength is updated to the decrypted data length. The decrypted data is 8 or 16 bytes less than
 * the original data.
 */
int wlan_set_crypto_AES_CCMP_decrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength);

/** Set Crypto AES_GCMP algorithm encrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] AAD AAD
 * \param[in] AADLength The maximum AAD length is 32.
 * \param[in] Nonce Nonce
 * \param[in] NonceLength The maximum Nonce length is 14.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the encrypted
 * data. The value of DataLength is updated to the encrypted data length. The encrypted data is 16 bytes more than the
 * original data. Therefore, the address pointed to by Data needs to reserve enough space.
 */
int wlan_set_crypto_AES_GCMP_encrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength);

/** Set Crypto AES_CCMP algorithm decrypt command param.
 *
 * \param[in] Key key
 * \param[in] KeyLength The maximum key length is 32.
 * \param[in] AAD AAD
 * \param[in] AADLength The maximum AAD length is 32.
 * \param[in] Nonce Nonce
 * \param[in] NonceLength The maximum Nonce length is 14.
 * \param[in] Data Data
 * \param[in] DataLength The maximum Data length is 1300.
 * \return WM_SUCCESS if successful.
 * \return -WM_E_PERM if not supported.
 * \return -WM_FAIL if failure.
 *
 * \note If the function returns WM_SUCCESS, the data in the memory pointed to by Data is overwritten by the decrypted
 * data. The value of DataLength is updated to the decrypted data length. The decrypted data is 16 bytes less than the
 * original data.
 */
int wlan_set_crypto_AES_GCMP_decrypt(const t_u8 *Key,
                                     const t_u16 KeyLength,
                                     const t_u8 *AAD,
                                     const t_u16 AADLength,
                                     const t_u8 *Nonce,
                                     const t_u16 NonceLength,
                                     t_u8 *Data,
                                     t_u16 *DataLength);
#endif

#ifdef CONFIG_WIFI_MEM_ACCESS
/** This function reads/writes adapter memory location value.
 *
 *\param[in]        action      0 -- read, 1 -- write
 *\param[in]        addr        Specifies the memory address that is to be read/write.
 *\param[in/out]    value       Value if specified, stand for write action, then that value will be written to that
 *offset in the specified register. Value should be specified in hexadecimal. Otherwise, it stands for read action, the
 *value is updated with read value.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_mem_access(uint16_t action, uint32_t addr, uint32_t *value);
#endif

#ifdef CONFIG_WIFI_BOOT_SLEEP
/** This function get/set wlan boot sleep enable status.
 *
 *\param[in]        action      0 -- get, 1 -- set
 *\param[in/out]    enable      If action is get then enable value is used to store firmware returned Value otherwise it
 *is set in firmware.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_boot_sleep(uint16_t action, uint16_t *enable);
#endif

/**
 * This function sends the host command to f/w and copies back response to caller provided buffer in case of
 * success Response from firmware is not parsed by this function but just copied back to the caller buffer.
 *
 *  \param[in]    cmd_buf         Buffer containing the host command with header
 *  \param[in]    cmd_buf_len     length of valid bytes in cmd_buf
 *  \param[out]   host_resp_buf        Caller provided buffer, in case of success command response is copied to this
 * buffer Can be same as cmd_buf \param[in]    resp_buf_len    resp_buf's allocated length \param[out]   reqd_resp_len
 * length of valid bytes in response buffer if successful otherwise invalid. \return                       WM_SUCCESS in
 * case of success. \return                       WM_E_INBIG in case cmd_buf_len is bigger than the commands that can be
 * handled by driver. \return                       WM_E_INSMALL in case cmd_buf_len is smaller than the minimum length.
 * Minimum length is atleast the length of command header. Please see Note for same. \return WM_E_OUTBIG in case the
 * resp_buf_len is not sufficient to copy response from firmware. reqd_resp_len is updated with the response size.
 *  \return                       WM_E_INVAL in case cmd_buf_len and resp_buf_len have invalid values.
 *  \return                       WM_E_NOMEM in case cmd_buf, resp_buf and reqd_resp_len are NULL
 *  \note                         Brief on the Command Header: Start 8 bytes of cmd_buf should have these values set.
 *                                Firmware would update resp_buf with these 8 bytes at the start.\n
 *                                2 bytes : Command.\n
 *                                2 bytes : Size.\n
 *                                2 bytes : Sequence number.\n
 *                                2 bytes : Result.\n
 *                                Rest of buffer length is Command/Response Body.
 */

int wlan_send_hostcmd(
    const void *cmd_buf, uint32_t cmd_buf_len, void *host_resp_buf, uint32_t resp_buf_len, uint32_t *reqd_resp_len);

#ifdef CONFIG_11AX
/**
 * This function is used to set HTC parameter.
 *
 *  \param[in]    count
 *  \param[in]    vht
 *  \param[in]    he
 *  \param[in]    rxNss
 *  \param[in]    channelWidth
 *  \param[in]    ulMuDisable
 *  \param[in]    txNSTS
 *  \param[in]    erSuDisable
 *  \param[in]    dlResoundRecomm
 *  \param[in]    ulMuDataDisable
 *
 * \return WM_SUCCESS if operation is successful, otherwise failure
 */
int wlan_send_debug_htc(const uint8_t count,
                        const uint8_t vht,
                        const uint8_t he,
                        const uint8_t rxNss,
                        const uint8_t channelWidth,
                        const uint8_t ulMuDisable,
                        const uint8_t txNSTS,
                        const uint8_t erSuDisable,
                        const uint8_t dlResoundRecomm,
                        const uint8_t ulMuDataDisable);

/**
 * This function is used to enable/disable HTC.
 *
 *  \param[in]    option         1 => Enable; 0 => Disable
 *
 * \return WM_SUCCESS if operation is successful, otherwise failure
 */
int wlan_enable_disable_htc(uint8_t option);
#endif

#ifdef CONFIG_11AX
/**
 * Use this API to set the set 11AX Tx OMI.
 *
 * \param[in] interface Interface type STA or uAP.
 * \param[in] tx_omi value to be sent to Firmware
 * \param[in] tx_option value to be sent to Firmware
 *            1: send OMI in QoS data.
 * \param[in] num_data_pkts value to be sent to Firmware
 *            num_data_pkts is applied only if OMI is sent in QoS data frame.
 *            It specifies the number of consecutive data frames containing the OMI.
 *            Minimum value is 1
 *            Maximum value is 16
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_11ax_tx_omi(const t_u8 interface, const t_u16 tx_omi, const t_u8 tx_option, const t_u8 num_data_pkts);
/**
 * Set 802_11 AX OBSS Narrow Bandwidth RU Tolerance Time
 * In uplink transmission, AP sends a trigger frame to all the stations that will be involved in the upcoming
 *transmission, and then these stations transmit Trigger-based(TB) PPDU in response to the trigger frame. If STA
 *connects to AP which channel is set to 100,STA doesn't support 26 tones RU. The API should be called when station is
 *in disconnected state.
 *
 *
 * \param[in] tol_time     Valid range [1...3600]
 *          tolerance time is in unit of seconds.
 *			STA periodically check AP's beacon for ext cap bit79 (OBSS Narrow bandwidth RU in ofdma tolerance support)
 * 			and set 20 tone RU tolerance time if ext cap bit79 is not set
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_11ax_tol_time(const t_u32 tol_time);
/**
 * Use this API to set the RU tx power limit.
 *
 * \param[in] rutx_pwr_cfg       11AX rutxpwr of sub-bands to be sent to Firmware.
 * \param[in] rutx_pwr_cfg_len   Size of rutx_pwr_cfg buffer.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_11ax_rutxpowerlimit(const void *rutx_pwr_cfg, uint32_t rutx_pwr_cfg_len);

/**
 * Use this API to set the RU tx power limit by channel based approach.
 *
 * \param[in] ru_pwr_cfg       11AX rutxpwr of channels to be sent to Firmware.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_11ax_rutxpowerlimit_legacy(const wlan_rutxpwrlimit_t *ru_pwr_cfg);

/**
 * Use this API to get the RU tx power limit by channel based approach.
 *
 * \param[in] ru_pwr_cfg   11AX rutxpwr of channels to be get from Firmware
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_get_11ax_rutxpowerlimit_legacy(wlan_rutxpwrlimit_t *ru_pwr_cfg);

/** Set 11ax config params
 *
 * \param[in, out] ax_config 11AX config parameters to be sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_11ax_cfg(wlan_11ax_config_t *ax_config);

/** Get default 11ax config params
 *
 * \return 11AX config parameters default array.
 */
uint8_t *wlan_get_11ax_cfg();

#ifdef CONFIG_11AX_TWT
/** Set btwt config params
 *
 * \param[in] btwt_config Broadcast TWT Setup parameters to be sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_btwt_cfg(const wlan_btwt_config_t *btwt_config);

/** Get btwt config params
 *
 * \return Broadcast TWT Setup parameters default config array.
 */
uint8_t *wlan_get_btwt_cfg();

/** Set twt setup config params
 *
 * \param[in] twt_setup TWT Setup parameters to be sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_twt_setup_cfg(const wlan_twt_setup_config_t *twt_setup);

/** Get twt setup config params
 *
 * \return TWT Setup parameters default array.
 */
uint8_t *wlan_get_twt_setup_cfg();

/** Set twt teardown config params
 *
 * \param[in] teardown_config TWT Teardown parameters sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_twt_teardown_cfg(const wlan_twt_teardown_config_t *teardown_config);

/** Get twt teardown config params
 *
 * \return TWT Teardown parameters default array
 */
uint8_t *wlan_get_twt_teardown_cfg();

/** Get twt report
 *
 * \param[out] twt_report TWT Report parameter.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_twt_report(wlan_twt_report_t *twt_report);
#endif /* CONFIG_11AX_TWT */

#ifdef CONFIG_MMSF
/**
 * Set 11AX AMPDU Density config.
 * \param[in] enable     0 - Disbale MMSF;  1 - Enable MMSF
 * \param[in] Density    ampdu Density value. Default value is 0x30.
 * \param[in] MMSF       ampdu MMSF value. Default value is 0x6.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_mmsf(const t_u8 enable, const t_u8 Density, const t_u8 MMSF);

/**
 * Get 11AX AMPDU Density config.
 * \param[out] enable     0 - Disbale MMSF;  1 - Enable MMSF
 * \param[out] Density    ampdu Density value. Default value is 0x30.
 * \param[out] MMSF       ampdu MMSF value. Default value is 0x6.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_mmsf(t_u8 *enable, t_u8 *Density, t_u8 *MMSF);
#endif
#endif /* CONFIG_11AX */

#ifdef CONFIG_WIFI_CLOCKSYNC
/** Set Clock Sync GPIO based TSF
 *
 * \param[in] tsf_latch Clock Sync TSF latch parameters to be sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_clocksync_cfg(const wlan_clock_sync_gpio_tsf_t *tsf_latch);
/** Get TSF info from firmware using GPIO latch
 *
 * \param[out] tsf_info TSF info parameter received from Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_tsf_info(wlan_tsf_info_t *tsf_info);
#endif /* CONFIG_WIFI_CLOCKSYNC */

#ifdef CONFIG_HEAP_DEBUG
/**
 * Show os mem alloc and free info.
 *
 */
void wlan_show_os_mem_stat();
#endif

#ifdef CONFIG_MULTI_CHAN
/**
 * Set multi-channel status disable/enable.
 * \param[in]      status       multi channel status
 * 0-disable, 1-enable
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_multi_chan_status(const int status);

/**
 * Get multi-channel status disable/enable.
 * \param[out]      status       multi channel status
 * 0-disable, 1-enable
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_multi_chan_status(int *status);

/**
 * Set multi-channel config.
 * \param[in]      num       array length of drcs_cfg[]
 * \param[in] drcs_cfg  multi-channel config, maybe an array
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_drcs_cfg(const wlan_drcs_cfg_t *drcs_cfg, const int num);

/**
 * Get multi-channel config.
 * \param[in]      num       array length of drcs_cfg[]
 * \param[out] drcs_cfg  multi-channel config, maybe an array
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_drcs_cfg(wlan_drcs_cfg_t *drcs_cfg, int num);
#endif

#ifdef CONFIG_11R
/**
 * Start FT roaming : This API is used to initiate fast BSS transition based
 * roaming.
 *
 * \param[in] bssid       BSSID of AP to roam
 * \param[in] channel     Channel of AP to roam
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_ft_roam(const t_u8 *bssid, const t_u8 channel);
#endif

/**
 * This API can be used to start/stop the management frame forwards
 * to host through datapath.
 *
 * \param[in] bss_type The interface from which management frame needs to be
 *            collected 0: STA, 1: uAP

 * \param[in] mgmt_subtype_mask     Management Subtype Mask
 *            If Bit X is set in mask, it means that IEEE Management Frame
 *            SubTyoe X is to be filtered and passed through to host.
 *            Bit                   Description
 *            [31:14]               Reserved
 *            [13]                  Action frame
 *            [12:9]                Reserved
 *            [8]                   Beacon
 *            [7:6]                 Reserved
 *            [5]                   Probe response
 *            [4]                   Probe request
 *            [3]                   Reassociation response
 *            [2]                   Reassociation request
 *            [1]                   Association response
 *            [0]                   Association request
 *            Support multiple bits set.
 *            0 = stop forward frame
 *            1 = start forward frame
 *\param[in] rx_mgmt_callback The receive callback where the received management
 *           frames are passed.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 *
 * \note Pass Management Subtype Mask all zero to disable all the management
 *       frame forward to host.
 */
int wlan_rx_mgmt_indication(const enum wlan_bss_type bss_type,
                            const uint32_t mgmt_subtype_mask,
                            int (*rx_mgmt_callback)(const enum wlan_bss_type bss_type,
                                                    const wlan_mgmt_frame_t *frame,
                                                    const size_t len));

#ifdef CONFIG_WMM
void wlan_wmm_tx_stats_dump(int bss_type);
#endif

/**
 * Set scan channel gap.
 * \param[in] scan_chan_gap      Time gap to be used between two consecutive channels scan.
 *
 */
void wlan_set_scan_channel_gap(unsigned scan_chan_gap);

#ifdef CONFIG_11K
/**
 * enable/disable host 11k feature
 *
 * \param[in] enable_11k the value of 11k configuration.
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_host_11k_cfg(int enable_11k);

bool wlan_get_host_11k_status();

/**
 * host send neighbor report request
 *
 * \param[in] ssid the SSID for neighbor report
 * \note ssid parameter is optional
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_host_11k_neighbor_req(const char *ssid);
#endif

#ifdef CONFIG_11V
/**
 * host send bss transition management query
 *
 * \param[in] query_reason BTM request query reason code
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_host_11v_bss_trans_query(t_u8 query_reason);
#endif

#ifndef CONFIG_WPA_SUPP
#ifdef CONFIG_DRIVER_MBO
/**
 * enable/disable MBO feature
 *
 * \param[in] enable_mbo the value of mbo configuration.
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_host_mbo_cfg(int enable_mbo);

/**
 * mbo channel operation preference configuration
 *
 * \param[in] ch0 channel number.
 * \param[in] prefer0 operation preference for ch0.
 * \param[in] ch1 channel number.
 * \param[in] prefer1 operation preference for ch1.
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_mbo_peferch_cfg(t_u8 ch0, t_u8 pefer0, t_u8 ch1, t_u8 pefer1);
#endif
#endif


#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_11AX
/**
 * Multi Band Operation (MBO) non-preferred channels
 *
 * A space delimited list of non-preferred channels where each channel is a colon delimited list of values.
 *
 * Format:
 *
 * non_pref_chan=oper_class:chan:preference:reason
 * Example:
 *
 * non_pref_chan=81:5:10:2 81:1:0:2 81:9:0:2
 *
 * \param[in] non_pref_chan list of non-preferred channels.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_mbo_peferch_cfg(const char *non_pref_chan);

/**
 * MBO set Cellular Data Capabilities
 *
 * \param[in] cell_capa 1 = Cellular data connection available
 * 2 = Cellular data connection not available
 * 3 = Not cellular capable (default)
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_mbo_set_cell_capa(t_u8 cell_capa);

/**
 * Optimized Connectivity Experience (OCE)
 *
 * \param[in] oce Enable OCE features
 * 1 = Enable OCE in non-AP STA mode (default; disabled if the driver
 * does not indicate support for OCE in STA mode).
 * 2 = Enable OCE in STA-CFON mode.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_mbo_set_oce(t_u8 oce);
#endif

/**
 * Opportunistic Key Caching (also known as Proactive Key Caching) default
 * This parameter can be used to set the default behavior for the
 * proactive_key_caching parameter. By default, OKC is disabled unless enabled
 * with the global okc=1 parameter or with the per-network
 * pkc(proactive_key_caching)=1 parameter. With okc=1, OKC is enabled by default, but
 * can be disabled with per-network pkc(proactive_key_caching)=0 parameter.
 *
 * \param[in] okc Enable Opportunistic Key Caching
 *
 * 0 = Disable OKC (default)
 * 1 = Enable OKC
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_okc(t_u8 okc);

/**
 * Dump text list of entries in PMKSA cache
 *
 * \param[out] buf Buffer to save PMKSA cache text list
 * \param[in] buflen length of the buffer
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_pmksa_list(char *buf, size_t buflen);

/**
 * Flush PTKSA cache entries
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_pmksa_flush();

/**
 * Set wpa supplicant scan interval in seconds
 *
 * \param[in] scan_int Scan interval in seconds
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_scan_interval(int scan_int);
#endif


#ifdef CONFIG_ECSA
/**
 * Send the ecsa config parameter to FW.
 *
 *\param[in] block_tx      0 -- no need to block traffic,1 -- need block traffic.
 *\param[in] oper_class    Operating class according to IEEE std802.11 spec, refer to Annex E,
 *                         when 0 is used, automatically get operclass through band_width and channel.
 *\param[in] channel       The channel will switch to.
 *\param[in] switch_count  Channel switch time to send ECSA ie, unit is 110ms.
 *\param[in] band_width    Channel width switch to(optional), only for 5G channels.
 *                         Depends on the hardware capabilities, when the hardware does not support, it will
 *automatically downgrade. Redfinch support 20M. 0 -- 20MHZ, 1 -- 40M above, 3 -- 40M below, 4 -- 80M, 5 -- 160M
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_uap_set_ecsa_cfg(t_u8 block_tx, t_u8 oper_class, t_u8 channel, t_u8 switch_count, t_u8 band_width);
#endif

#ifdef CONFIG_SUBSCRIBE_EVENT_SUPPORT

/*Type enum definition of subscribe event*/
typedef enum
{
    /** Event Id for subscribe event rssi low */
    EVENT_SUB_RSSI_LOW = 0,
    /** Event Id for subscribe event rssi high */
    EVENT_SUB_RSSI_HIGH,
    /** Event Id for subscribe event snr low */
    EVENT_SUB_SNR_LOW,
    /** Event Id for subscribe event snr high */
    EVENT_SUB_SNR_HIGH,
    /** Event Id for subscribe event max fail */
    EVENT_SUB_MAX_FAIL,
    /** Event Id for subscribe event beacon missed */
    EVENT_SUB_BEACON_MISSED,
    /** Event Id for subscribe event data rssi low */
    EVENT_SUB_DATA_RSSI_LOW,
    /** Event Id for subscribe event data rssi high */
    EVENT_SUB_DATA_RSSI_HIGH,
    /** Event Id for subscribe event data snr low */
    EVENT_SUB_DATA_SNR_LOW,
    /** Event Id for subscribe event data snr high */
    EVENT_SUB_DATA_SNR_HIGH,
    /** Event Id for subscribe event link quality */
    EVENT_SUB_LINK_QUALITY,
    /** Event Id for subscribe event pre_beacon_lost */
    EVENT_SUB_PRE_BEACON_LOST,
    /** Fail event id */
    MAX_EVENT_ID,
} sub_event_id;

/** Type definition of wlan_ds_subscribe_evt for subscribe events */
typedef wifi_ds_subscribe_evt wlan_ds_subscribe_evt;

/**
 * Subscribe specified event from the Wi-Fi firmware. Wi-Fi firmware will report the registered event to driver upon
 * configured report conditions are met. \param[in] event_id event to register as per \ref sub_event_id \param[in]
 * thresh_value threshold value (dBm) \param[in] freq event frequency 0--report once, 1--report everytime happened, N --
 * report only happened > N consecutive times.
 */
int wlan_set_subscribe_event(unsigned int event_id, unsigned int thresh_value, unsigned int freq);
/**
 * Get all subscribed events from Wi-Fi firmware along with threshold value and report frequency.
 * \param[in] sub_evt A pointer to \ref wlan_ds_subscribe_evt to store the events data.
 */
int wlan_get_subscribe_event(wlan_ds_subscribe_evt *sub_evt);
/**
 * cancel the subscribe event to firmware
 * \param[in] event_id event id to clear as per \ref sub_event_id
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_clear_subscribe_event(unsigned int event_id);
/**
 * subscibe link quality event
 * \param[in] event_id event id to clear as per \ref sub_event_id
 * \param[in] link_snr link quality snr value
 * \param[in] link_snr_freq link quality snr freq
 * \param[in] link_rate link quality rate
 * \param[in] link_rate_freq link quality rate freq
 * \param[in] link_tx_latency link quality write lantency
 * \param[in] link_tx_lantency_freq link quality write lantency freq
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_threshold_link_quality(unsigned int evend_id,
                                    unsigned int link_snr,
                                    unsigned int link_snr_freq,
                                    unsigned int link_rate,
                                    unsigned int link_rate_freq,
                                    unsigned int link_tx_latency,
                                    unsigned int link_tx_lantency_freq);
#endif

#ifdef CONFIG_TSP
/**
 * get TSP(Thermal Safeguard Protection) configuration.
 * TSP algorithm moniters PA Tj and primarily backs off data throughput.
 * \param[out] enable    enable/disable tsp algothrim
 * \param[out] back_off     power back off   [0...20]dB
 * \param[out] highThreshold     high threshold  [0...300]°C
 * \param[out] lowThreshold     low threshold   [0...300]°C
 *          High Threshold must be greater than Low Threshold.
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_tsp_cfg(t_u16 *enable,
                     t_u32 *back_off,
                     t_u32 *highThreshold,
                     t_u32 *lowThreshold,
                     t_u32 *dutycycstep,
                     t_u32 *dutycycmin,
                     int *highthrtemp,
                     int *lowthrtemp,
                     int *currCAUTemp,
                     int *currRFUTemp);
/**
 * set TSP(Thermal Safeguard Protection) configuration.
 * TSP algorithm moniters PA Tj and primarily backs off data throughput.
 * \param[in] enable    enable/disable tsp algothrim
 * \param[in] back_off     power back off   [0...20]dB
 * \param[in] highThreshold     high threshold  [0...300]°C
 * \param[in] lowThreshold     low threshold   [0...300]°C
 *          High Threshold must be greater than Low Threshold.
 * \return WM_SUCCESS if successful otherwise failure.
 */

int wlan_set_tsp_cfg(t_u16 enable,
                     t_u32 back_off,
                     t_u32 highThreshold,
                     t_u32 lowThreshold,
                     t_u32 dutycycstep,
                     t_u32 dutycycmin,
                     int highthrtemp,
                     int lowthrtemp);
#endif

#ifdef CONFIG_WIFI_REG_ACCESS
/** This function reads/writes adapter registers value.
 *
 *\param[in]        type        Register type: 1 -- MAC, 2 -- BBP, 3 -- RF.
 *\param[in]        action      0 -- read, 1 -- write
 *\param[in]        offset      Specifies the offset location that is to be read/write.
 *\param[in/out]    value       Value if specified, stand for write action, then that value will be written to that
 *offset in the specified register. Value should be specified in hexadecimal. Otherwise, it stands for read action, the
 *value is updated with read value.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_reg_access(wifi_reg_t type, uint16_t action, uint32_t offset, uint32_t *value);
#endif

/**
 * Set/Get Tx ampdu prot mode.
 *
 * \param[in, out] prot_mode    Tx ampdu prot mode
 * \param[in]     action       Command action
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_tx_ampdu_prot_mode(tx_ampdu_prot_mode_para *prot_mode, t_u16 action);

struct wlan_message
{
    t_u16 id;
    void *data;
};

enum wlan_mef_type
{
    MEF_TYPE_DELETE = 0,
    MEF_TYPE_PING,
    MEF_TYPE_ARP,
    MEF_TYPE_MULTICAST,
    MEF_TYPE_IPV6_NS,
    MEF_TYPE_END,
};
/** This function set auto ARP configuration.
 *
 * \param[in] mef_action  To be 0--discard and not wake host, 1--discard and wake host 3--allow and wake host.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_mef_set_auto_arp(t_u8 mef_action);
/** This function set auto ping configuration.
 *
 * \param[in] mef_action  To be 0--discard and not wake host, 1--discard and wake host 3--allow and wake host.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 *
 */
int wlan_mef_set_auto_ping(t_u8 mef_action);
/** This function set/delete mef entries configuration.
 *
 * \param[in] type        MEF type: MEF_TYPE_DELETE, MEF_TYPE_AUTO_PING, MEF_TYPE_AUTO_ARP
 * \param[in] mef_action  To be 0--discard and not wake host, 1--discard and wake host 3--allow and wake host.
 *
 * \return WM_SUCCESS if the call was successful.
 * \return -WM_FAIL if failed.
 */
int wlan_config_mef(int type, t_u8 mef_action);
/**
 * Use this API to enable IPv6 Neighbor Solicitation offload in Wi-Fi firmware
 *
 * \param[in] mef_action  0--discard and not wake host, 1--discard and wake host 3--allow and wake host.
 *
 * \return WM_SUCCESS if operation is successful.
 * \return -WM_FAIL if command fails.
 */
int wlan_set_ipv6_ns_mef(t_u8 mef_action);

#ifdef CONFIG_CSI
/**
 * Send the csi config parameter to FW.
 *
 *\param[in] csi_params Csi config parameter
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_csi_cfg(wlan_csi_config_params_t *csi_params);

/** This function registers callback which are used to deliver CSI data to user.
 *
 * \param[in] csi_data_recv_callback Callback to deliver CSI data and max data length is 768 bytes.
 * Pls save data as soon as possible in callback
 * Type of callback return vale is int.
 *
 *          Memory layout of buffer:
 *          size(byte)                         items
 *          2                                  buffer len[bit 0:12]
 *          2                                  CSI signature, 0xABCD fixed
 *          4                                  User defined HeaderID
 *          2                                  Packet info
 *          2                                  Frame control field for the received packet
 *          8                                  Timestamp when packet received
 *          6                                  Received Packet Destination MAC Address
 *          6                                  Received Packet Source MAC Address
 *          1                                  RSSI for antenna A
 *          1                                  RSSI for antenna B
 *          1                                  Noise floor for antenna A
 *          1                                  Noise floor for antenna B
 *          1                                  Rx signal strength above noise floor
 *          1                                  Channel
 *          2                                  user defined Chip ID
 *          4                                  Reserved
 *          4                                  CSI data length in DWORDs
 *                                             CSI data
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_register_csi_user_callback(int (*csi_data_recv_callback)(void *buffer, size_t len));

/** This function unregisters callback which are used to deliver CSI data to user.
 *
 * \return  WM_SUCCESS if successful
 */
int wlan_unregister_csi_user_callback(void);
#endif

#if defined(CONFIG_11K) || defined(CONFIG_11V) || defined(CONFIG_ROAMING)
/**
 * Use this API to set the RSSI threshold value for low RSSI event subscription.
 * When RSSI falls below this threshold firmware will generate the low RSSI event to driver.
 * This low RSSI event is used when either of CONFIG_11R, CONFIG_11K, CONFIG_11V or CONFIG_ROAMING is enabled.
 * NOTE: By default rssi low threshold is set at -70 dbm
 *
 * \param[in]     threshold      Threshold rssi value to be set
 *
 */
void wlan_set_rssi_low_threshold(uint8_t threshold);
#endif

#ifdef CONFIG_WPA_SUPP
#ifdef CONFIG_WPA_SUPP_WPS
/** Generate valid PIN for WPS session.
 *
 *  This function generate PIN for WPS PIN session.
 *
 * \param[in]  pin A pointer to WPS pin to be generated.
 */
void wlan_wps_generate_pin(uint32_t *pin);

/** Start WPS PIN session.
 *
 *  This function starts WPS PIN session.
 *
 * \param[in]  pin Pin for WPS session.
 *
 * \return WM_SUCCESS if the pin entered is valid.
 * \return -WM_FAIL if invalid pin entered.
 */
int wlan_start_wps_pin(const char *pin);

/** Start WPS PBC session.
 *
 *  This function starts WPS PBC session.
 *
 * \return  WM_SUCCESS if successful
 * \return -WM_FAIL if invalid pin entered.
 *
 */
int wlan_start_wps_pbc(void);

/** Cancel WPS session.
 *
 *  This function cancels ongoing WPS session.
 *
 * \return  WM_SUCCESS if successful
 * \return -WM_FAIL if invalid pin entered.
 *
 */
int wlan_wps_cancel(void);

#ifdef CONFIG_WPA_SUPP_AP
/** Start WPS PIN session.
 *
 *  This function starts AP WPS PIN session.
 *
 * \param[in]  pin Pin for WPS session.
 *
 * \return WM_SUCCESS if the pin entered is valid.
 * \return -WM_FAIL if invalid pin entered.
 */
int wlan_start_ap_wps_pin(const char *pin);

/** Start WPS PBC session.
 *
 *  This function starts AP WPS PBC session.
 *
 * \return  WM_SUCCESS if successful
 * \return -WM_FAIL if invalid pin entered.
 *
 */
int wlan_start_ap_wps_pbc(void);

/** Cancel AP's WPS session.
 *
 *  This function cancels ongoing WPS session.
 *
 * \return  WM_SUCCESS if successful
 * \return -WM_FAIL if invalid pin entered.
 *
 */
int wlan_wps_ap_cancel(void);
#endif
#endif
#endif

#if defined(CONFIG_WPA2_ENTP) || defined(CONFIG_WPA_SUPP_CRYPTO_ENTERPRISE)
#define FILE_TYPE_NONE              0
#define FILE_TYPE_ENTP_CA_CERT      1
#define FILE_TYPE_ENTP_CLIENT_CERT  2
#define FILE_TYPE_ENTP_CLIENT_KEY   3
#define FILE_TYPE_ENTP_CA_CERT2     4
#define FILE_TYPE_ENTP_CLIENT_CERT2 5
#define FILE_TYPE_ENTP_CLIENT_KEY2  6

#ifdef CONFIG_HOSTAPD
#define FILE_TYPE_ENTP_SERVER_CERT 8
#define FILE_TYPE_ENTP_SERVER_KEY  9
#define FILE_TYPE_ENTP_DH_PARAMS   10
#endif

/** This function specifies the enterprise certificate file
 *  This function must be used before adding network profile. It will store certificate data
 *  in "wlan" global structure. When adding new network profile, it will be get by
 *  wlan_get_entp_cert_files(), and put into profile security structure after mbedtls parse.
 *
 * \param[in]        cert_type   certificate file type:
 * 1 -- FILE_TYPE_ENTP_CA_CERT,
 * 2 -- FILE_TYPE_ENTP_CLIENT_CERT,
 * 3 -- FILE_TYPE_ENTP_CLIENT_KEY.
 * \param[in]        data        raw data
 * \param[in]        data_len    size of raw data
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_entp_cert_files(int cert_type, t_u8 *data, t_u32 data_len);

/** This function get enterprise certificate data from "wlan" global structure           *
 * \param[in]        cert_type   certificate file type:
 * 1 -- FILE_TYPE_ENTP_CA_CERT,
 * 2 -- FILE_TYPE_ENTP_CLIENT_CERT,
 * 3 -- FILE_TYPE_ENTP_CLIENT_KEY.
 * \param[in]        data        raw data
 *
 * \return size of raw data
 */
t_u32 wlan_get_entp_cert_files(int cert_type, t_u8 **data);

/** This function free the temporary memory of enterprise certificate data
 *  After add new enterprise network profile, the certificate data has been parsed by mbedtls into another data, which
 * can be freed.
 *
 */
void wlan_free_entp_cert_files(void);
#endif

#ifdef CONFIG_NET_MONITOR
/**
 * Send the net monitor config parameter to FW.
 *
 *\param[in] monitor Monitor config parameter
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_net_monitor_cfg(wlan_net_monitor_t *monitor);

/** This function registers callback which are used to deliver monitor data to user.
 *
 * \param[in] monitor_data_recv_callback Callback to deliver monitor data and data length to user.
 *          Memory layout of buffer:
 *          offset(byte)                        items
 *          0                                   rssi
 *          1                                   802.11 mac header
 *          1 + 'size of 802.11 mac header'     frame body
 *
 * \return void
 */
void wlan_register_monitor_user_callback(int (*monitor_data_recv_callback)(void *buffer, t_u16 data_len));

/** This function deregisters monitor callback.
 *
 * \return void
 */
void wlan_deregister_net_monitor_user_callback();
#endif

/** Check if 11n(2G or 5G) is supported by hardware or not.
 *
 * \param[in] channel Channel number.
 *
 * \return true if 11n is supported or false if not.
 */
uint8_t wlan_check_11n_capa(unsigned int channel);

/** Check if 11ac(2G or 5G) is supported by hardware or not.
 *
 * \param[in] channel Channel number.
 *
 * \return true if 11ac is supported or false if not.
 */
uint8_t wlan_check_11ac_capa(unsigned int channel);

/** Check if 11ax(2G or 5G) is supported by hardware or not.
 *
 * \param[in] channel Channel number.
 *
 * \return true if 11ax is supported or false if not.
 */
uint8_t wlan_check_11ax_capa(unsigned int channel);

#if defined(CONFIG_IPS)
/**
 * Config IEEE power save mode(IPS).If the option is 1, the ips hardware listens to beacon frames after WLAN CPU enters
 * power save mode. When there is work needed to done by WLAN CPU, WLAN CPU will be woken up by ips hardware. \param[in]
 * option    0/1  disable/enable ips
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_ips(int option);
#endif

/**
 * Get rssi information.
 * \param[out] signal    rssi infomation get report buffer
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_signal_info(wlan_rssi_info_t *signal);

#if defined(CONFIG_COMPRESS_TX_PWTBL)
/**
 * set region power table
 * \param[in] region_code region code
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_rg_power_cfg(t_u16 region_code);
#endif

/**
 * Get Turbo mode.
 * \param[out] mode    turbo mode
 *                          0: disable turbo mode
 *                          1: turbo mode 1
 *                          2: turbo mode 2
 *                          3: turbo mode 3
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_turbo_mode(t_u8 *mode);

/**
 * Get UAP Turbo mode.
 * \param[out] mode    turbo mode
 *                          0: disable turbo mode
 *                          1: turbo mode 1
 *                          2: turbo mode 2
 *                          3: turbo mode 3
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_uap_turbo_mode(t_u8 *mode);

/**
 * Set Turbo mode.
 * \param[in] mode    turbo mode
 *                          0: disable turbo mode
 *                          1: turbo mode 1
 *                          2: turbo mode 2
 *                          3: turbo mode 3
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_turbo_mode(t_u8 mode);

/**
 * Set UAP Turbo mode.
 * \param[in] mode    turbo mode
 *                          0: disable turbo mode
 *                          1: turbo mode 1
 *                          2: turbo mode 2
 *                          3: turbo mode 3
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_uap_turbo_mode(t_u8 mode);

/**
 * set ps configuration.
 * Currently only used to modify multiple dtim.
 * \param[in] multiple_dtims        num dtims, range [1,20]
 * \param[in] bcn_miss_timeout      becaon miss interval
 * \param[in] local_listen_interval local listen interval
 * \param[in] adhoc_wake_period     adhoc awake period
 * \param[in] mode                  mode - (0x01 - firmware to automatically choose PS_POLL or NULL mode,
 *                                          0x02 - PS_POLL,
 *                                          0x03 - NULL mode )
 * \param[in] delay_to_ps           Delay to PS in milliseconds
 */
void wlan_set_ps_cfg(t_u16 multiple_dtims,
                     t_u16 bcn_miss_timeout,
                     t_u16 local_listen_interval,
                     t_u16 adhoc_wake_period,
                     t_u16 mode,
                     t_u16 delay_to_ps);

#ifdef CONFIG_CLOUD_KEEP_ALIVE
/**
 * Save start cloud keep alive parameters
 *
 * \param[in] cloud_keep_alive    cloud keep alive information
 * \param[in] src_port Source port
 * \param[in] dst_port Destination port
 * \param[in] seq_number Sequence number
 * \param[in] ack_number Acknowledgement number
 * \param[in] enable Enable
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_save_cloud_keep_alive_params(wlan_cloud_keep_alive_t *cloud_keep_alive,
                                      t_u16 src_port,
                                      t_u16 dst_port,
                                      t_u32 seq_number,
                                      t_u32 ack_number,
                                      t_u8 enable);

/**
 * Get cloud keep alive status for given destination ip and port
 *
 * \param[in] dst_ip Destination ip address
 * \param[in] dst_port Destination port
 *
 * \return 1 if enabled otherwise 0.
 */
int wlan_cloud_keep_alive_enabled(t_u32 dst_ip, t_u16 dst_port);

/**
 * Start cloud keep alive
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_start_cloud_keep_alive(void);
/**
 * Stop cloud keep alive
 * \param[in] cloud_keep_alive    cloud keep alive information
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_stop_cloud_keep_alive(wlan_cloud_keep_alive_t *cloud_keep_alive);
#endif

/**
 * Set country code
 *
 * \note This API should be called after WLAN is initialized
 * but before starting uAP interface.
 *
 * \param[in] alpha2 country code in 3 octets string, 2 octets country code and 1 octet environment
 *            2 octets country code supported:
 *            WW : World Wide Safe
 *            US : US FCC
 *            CA : IC Canada
 *            SG : Singapore
 *            EU : ETSI
 *            AU : Australia
 *            KR : Republic Of Korea
 *            FR : France
 *            JP : Japan
 *            CN : China
 *
 * For the third octet, STA is always 0.
 * For uAP environment:
 * All environments of the current frequency band and country (default)
 * alpha2[2]=0x20
 * Outdoor environment only
 * alpha2[2]=0x4f
 * Indoor environment only
 * alpha2[2]=0x49
 * Noncountry entity (country_code=XX)
 * alpha[2]=0x58
 * IEEE 802.11 standard Annex E table indication: 0x01 .. 0x1f
 * Annex E, Table E-4 (Global operating classes)
 * alpha[2]=0x04
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_country_code(const char *alpha2);

/** Set ignore region code
 *
 * \param[in] ignore     0: Don't ignore 1: ignore
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_country_ie_ignore(uint8_t *ignore);

/** Set region code
 *
 * \param[in] region_code
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_region_code(unsigned int region_code);

/** Get region code
 *
 * \param[out] region_code pointer
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_region_code(unsigned int *region_code);

/** Set STA/uAP 80211d feature enable/disable
 *
 * \param[in] bss_type 0: STA, 1: uAP
 * \param[in] state    0: disable, 1: enable
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_11d_state(int bss_type, int state);

#ifdef CONFIG_COEX_DUTY_CYCLE
/**
 * Set single ant duty cycle.
 * \param[in] enable
 * \param[in] nbTime
 * \param[in] wlanTime
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_single_ant_duty_cycle(t_u16 enable, t_u16 nbTime, t_u16 wlanTime);

/**
 * Set dual ant duty cycle.
 * \param[in] enable
 * \param[in] nbTime
 * \param[in] wlanTime
 * \param[in] wlanBlockTime
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dual_ant_duty_cycle(t_u16 enable, t_u16 nbTime, t_u16 wlanTime, t_u16 wlanBlockTime);
#endif

#ifdef CONFIG_EXTERNAL_COEX_PTA
/**
 * Set external coex pta parameters.
 * \param[in] coex_pta_config
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_external_coex_pta_cfg(ext_coex_pta_cfg coex_pta_config);
#endif

#ifdef CONFIG_WPA_SUPP_DPP
/** Add a DPP Configurator
 *
 *  If this device is DPP Configurator, add it to get configurator ID.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "curve=P-256"
 *
 * \return configurator ID if successful otherwise failure.
 */
int wlan_dpp_configurator_add(int is_ap, const char *cmd);

/** Set DPP Configurator parameter
 *
 *  set DPP configurator params.
 *  for example:" conf=<sta-dpp/ap-dpp> ssid=<hex ssid> configurator=conf_id"
 *  #space character exists between " & conf word.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      " conf=<sta-dpp/ap-dpp/sta-psk> ssid=<hex ssid> configurator=conf_id..."
 *
 * \return void
 */
void wlan_dpp_configurator_params(int is_ap, const char *cmd);

/** MUD URL for Enrollee's DPP Configuration Request (optional)
 *
 *  Wi-Fi_CERTIFIED_Easy_Connect_Test_Plan_v3.0.pdf
 *  5.1.23 STAUT sends the MUD URL
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "https://example.com/mud"
 *
 * \return void
 */
void wlan_dpp_mud_url(int is_ap, const char *cmd);

/** Generate QR code
 *
 *  This function generates QR code and return bootstrap-id
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "type=qrcode mac=<mac-address-of-device> chan=<operating-class/channel>..."
 *
 * \return bootstrap-id if successful otherwise failure.
 */
int wlan_dpp_bootstrap_gen(int is_ap, const char *cmd);

/** Get QR code by bootstrap-id
 *
 *  This function get QR code string by bootstrap-id
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  id       bootstrap-id
 *
 * \return QR code string if successful otherwise NULL.
 */
const char *wlan_dpp_bootstrap_get_uri(int is_ap, unsigned int id);

/** Enter the QR code in the DPP device.
 *
 *  This function set the QR code and return qr-code-id.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  uri      QR code provided by other device.
 *
 * \return qr-code-id if successful otherwise failure.
 */
int wlan_dpp_qr_code(int is_ap, char *uri);

/** Send provisioning Auth request to responder.
 *
 *  This function send Auth request to responder by qr-code-id.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      " peer=<qr-code-id> conf=<sta-dpp/ap-dpp/sta-psk> ...."
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_auth_init(int is_ap, const char *cmd);

/** Make device listen to DPP request.
 *
 *  Responder generates QR code and listening on its operating channel to wait Auth request.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "<frequency>"
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_listen(int is_ap, const char *cmd);

/** DPP stop listen
 *
 *  Stop dpp listen and clear listen frequency
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_stop_listen(int is_ap);

/** Set bootstrapping through PKEX(Public Key Exchange)
 *
 *  Support in-band bootstrapping through PKEX
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "own=<bootstrap_id> identifier=<string> code=<string>"
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_pkex_add(int is_ap, const char *cmd);

/** sends DPP presence announcement.
 *
 *  Send DPP presence announcement from responder.
 *  After the Initiator enters the QRcode URI provided by the Responder,
 *  the Responder sends the presence announcement to trigger Auth Request from Initiator.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      "own=<bootstrap id> listen=<freq> ..."
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_chirp(int is_ap, const char *cmd);

/** DPP reconfig
 *
 *  DPP reconfig and make a new DPP connection.
 *
 * \param[in]  cmd      "<network id> ..."
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_reconfig(const char *cmd);

/** Configurator configures itself as an Enrollee AP/STA
 *
 *  Wi-Fi_CERTIFIED_Easy_Connect_Test_Plan_v3.0.pdf
 *  5.3.8 & 5.3.9 Configurator configures itself as an Enrollee AP/STA
 *
 *  for example:" conf=<sta-dpp/ap-dpp> ssid=<hex ssid> configurator=conf_id"
 *  #space character exists between " & conf word.
 *
 * \param[in]  is_ap    0 is sta, 1 is uap
 * \param[in]  cmd      " conf=<sta-dpp/ap-dpp/sta-psk> ssid=<hex ssid> configurator=conf_id..."
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_dpp_configurator_sign(int is_ap, const char *cmd);
#endif

#ifdef CONFIG_IMD3_CFG
/**
 * Set imd validation parameters.
 * \param[in] imd3_value   disable imd3: imd3_value = 0;
 *                         enable imd3: low 4 bits: enable, high 4 bits: isolation index.
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_imd3_cfg(t_u8 imd3_value);
#endif

int wlan_host_set_sta_mac_filter(int filter_mode, int mac_count, unsigned char *mac_addr);

#if defined(CONFIG_WIFI_IND_RESET) && defined(CONFIG_WIFI_IND_DNLD)
/**
 * Set GPIO independent reset configuration
 *
 * \param[in] indrst_cfg GPIO independent reset config to be sent to Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_set_indrst_cfg(const wifi_indrst_cfg_t *indrst_cfg);

/* Get GPIO independent reset configuration
 *
 * \param[out] indrst_cfg GPIO independent reset config set in Firmware
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_get_indrst_cfg(wifi_indrst_cfg_t *indrst_cfg);

/** Test Independent Firmware reset
 *
 * This function will either send cmd that will cause timeout in firmware or
 * send GPIO pulse that will cause out of band reset in firmware as per configuration
 * int earlier \ref wlan_set_indrst_cfg API.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_independent_reset();

#endif

int wlan_set_network_ip_byname(char *name, struct wlan_ip_config *ip);

#ifdef CONFIG_INACTIVITY_TIMEOUT_EXT
/**
 * Get/Set inactivity timeout extend
 * \param[in] inac_to
 * \param[in] action
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_sta_inactivityto(wlan_inactivity_to_t *inac_to, t_u16 action);
#endif

#ifdef RW610
/**
 * Get board temperature.
 * \return board temperature.
 */
int32_t wlan_get_temperature(void);
#endif

#ifdef CONFIG_CPU_LOADING
/**
 * Set parameters for cpu loading test.
 *
 * \param[in]  start    0 stop test, 1 start test.
 * \param[in]  number   The number of cpu loading test.
 * \param[in]  period   The period of cpu loading test.
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_cpu_loading(uint8_t start, uint32_t number, uint8_t period);
#endif

#ifdef CONFIG_AUTO_NULL_TX
/** Configuration for auto null tx parameters from
 * \ref wifi_auto_null_tx_t
 */
typedef wifi_auto_null_tx_t wlan_auto_null_tx_t;

/**
 * Start/Stop auto tx null
 *
 * \return WM_SUCCESS if successful otherwise failure.
 */
int wlan_auto_null_tx(wlan_auto_null_tx_t *auto_null_tx);
#endif

/**
 * allocate a copy of a string
 *
 */
char *wlan_string_dup(const char *s);

#endif /* __WLAN_H__ */
