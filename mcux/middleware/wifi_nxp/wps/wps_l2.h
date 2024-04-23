/** @file wps_l2.h
 *
 *  @brief This file contains definition for layer 2 socket functions.
 *
 *  Copyright 2008-2022 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 */

#ifndef _WPS_L2_H_
#define _WPS_L2_H_

#ifndef ETH_P_EAPOL
/** Ethernet protocol EAPOL */
#define ETH_P_EAPOL 0x888e
#endif

#define PF_PACKET 17 /* Packet family.  */
#define AF_PACKET PF_PACKET
#ifdef CONFIG_WPA2_ENTP
#define ETH_FRAME_LEN 1400
#else
#define ETH_FRAME_LEN 1200
#endif

struct l2_ethhdr
{
    /** Ethernet destination address */
    u8 h_dest[ETH_ALEN];
    /** Ethernet source address */
    u8 h_source[ETH_ALEN];
    /** Protocol */
    u16 h_proto;
} __attribute__((packed));

/**
 * @brief wps_l2_init - Initialize l2_packet interface
 * rx_callback function will be called with src_addr pointing to the source
 * address (MAC address) of the the packet. If l2_hdr is set to 0, buf
 * points to len bytes of the payload after the layer 2 header and similarly,
 * TX buffers start with payload. This behavior can be changed by setting
 * l2_hdr=1 to include the layer 2 header in the data buffer.
 * @param ifname: Interface name
 * @param protocol: Ethernet protocol number in host byte order
 * @param rx_callback: Callback function that will be called for each received packet
 * @param l2_hdr: 1 = include layer 2 header, 0 = do not include header
 * @return Pointer to internal data or %NULL on failure
 *
 */
WPS_L2_INFO *wps_l2_init(const char *ifname,
                         unsigned short protocol,
                         void (*rx_callback)(const u8 *src_addr, const u8 *buf, size_t len));

/**
 * @brief wps_l2_deinit - Deinitialize l2_packet interface
 * @param l2 Pointer to internal l2_packet data from wps_l2_init()
 * @return None
 */
void wps_l2_deinit(WPS_L2_INFO *l2);

/**
 * @brief wps_l2_get_mac - Get own layer 2 address
 * @param l2 Pointer to internal l2_packet data from wps_l2_init()
 * @param addr Buffer for the own address (6 bytes)
 * @return 0 on success, -1 on failure
 */
int wps_l2_get_mac(WPS_L2_INFO *l2, u8 *addr);

/**
 * @brief wps_l2_send - Send a packet
 * @param l2 Pointer to internal l2_packet data from wps_l2_init()
 * @param dst_addr Destination address for the packet (only used if l2_hdr == 0)
 * @param proto Protocol/ethertype for the packet in host byte order (only used if
 *             l2_hdr == 0)
 * @param buf Packet contents to be sent; including layer 2 header if l2_hdr was
 *           set to 1 in wps_l2_init() call. Otherwise, only the payload of the packet
 *           is included.
 * @param len  Length of the buffer (including l2 header only if l2_hdr == 1)
 * @return >=0 on success, <0 on failure
 */
int wps_l2_send(WPS_L2_INFO *l2, const u8 *dst_addr, u16 proto, const u8 *buf, size_t len);
void wps_l2_receive(const u8 *src_addr, const u8 *buf, size_t len);
#endif /* _WPS_L2_H_ */
