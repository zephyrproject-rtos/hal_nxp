/*
 *  Copyright 2008-2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 */

#include <mlan_api.h>
#include <wmlog.h>
#ifdef RW610
#include <wifi-imu.h>
#else
#include <wifi-sdio.h>
#endif
#include <wifi-internal.h>

#define NET_MAC_ADDR_LEN 6

#define NET_IPV4_ADDR_U32(x) (x).in_addr.s_addr

/*
 * Packets of this type need o be handled
 * for WPS and Supplicant
 */
#define ETHTYPE_EAPOL 0x888EU /* EAPOL */

/* This is an Token-Ring LLC structure */
struct eth_llc_hdr
{
    t_u8 dsap;      /* destination SAP */
    t_u8 ssap;      /* source SAP */
    t_u8 llc;       /* LLC control field */
    t_u8 protid[3]; /* protocol id */
    t_u16 type;     /* ether type field */
} __packed;

#define SIZEOF_ETH_LLC_HDR (8U)
#define SIZEOF_ETH_HDR     (14U)

/* Define those to better describe your network interface. */
#define IFNAME0 'm'
#define IFNAME1 'l'

/*
 * It was observed that Wi-Fi card does not wakeup
 * immediately after call to wlan_wakeup_card.
 * The code tries to wakeup the card by writing
 * in SDIO register.
 * It waits for 20 ms for AWAKE event from Wi-Fi card,
 * if AWAKE event is not generated or received  by MCU code
 * it returns error and does not send a packet out.
 * This is observed with  8801 Wi-Fi card.
 * So for 8801 based platforms the wait time is now 35 ms.
 */

#if CONFIG_WiFi_878x
#define MAX_WAIT_TIME 20
#else
#define MAX_WAIT_TIME 35
#endif
#define MAX_INTERFACES_SUPPORTED 3U

/* The time to block waiting for input. */
#define emacBLOCK_TIME_WAITING_FOR_INPUT ((portTickType)100)
/*------------------------------------------------------*/
extern int wlan_get_mac_address(uint8_t *dest);
extern void wlan_wake_up_card(void);

#if CONFIG_P2P
mlan_status wlan_send_gen_sdio_cmd(uint8_t *buf, uint32_t buflen);
#endif
#if CONFIG_P2P
extern int wlan_get_wfd_mac_address(t_u8 *);
extern int wfd_bss_type;
#endif

#if CONFIG_WPS2
void (*wps_rx_callback)(const t_u8 *buf, size_t len);
#endif

#if CONFIG_WPA_SUPP
// void (*l2_packet_rx_callback)(const struct pbuf *p);
#endif /* CONFIG_HOST_SUPP */

#if UAP_SUPPORT
void wrapper_wlan_update_uap_rxrate_info(RxPD *rxpd);
#endif

int wrapper_wlan_handle_rx_packet(t_u16 datalen, RxPD *rxpd, void *p, void *payload);

#if CONFIG_NET_MONITOR
void user_recv_monitor_data(const t_u8 *rcvdata);
#endif
