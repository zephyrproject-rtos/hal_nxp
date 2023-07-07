/*
 * Copyright 2020-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef GMAC_IP_TYPES_H
#define GMAC_IP_TYPES_H

/**
*   @file
*
*   @addtogroup GMAC_DRIVER GMAC Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gmac_Ip_Device_Registers.h"
#include "Gmac_Ip_Features.h"
#include "Gmac_Ip_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GMAC_IP_TYPES_VENDOR_ID                      43
#define GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION       7
#define GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION    0
#define GMAC_IP_TYPES_SW_MAJOR_VERSION               3
#define GMAC_IP_TYPES_SW_MINOR_VERSION               0
#define GMAC_IP_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Gmac_Ip_Device_Registers.h */
#if (GMAC_IP_TYPES_VENDOR_ID != GMAC_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Gmac_Ip_Types.h and Gmac_Ip_Device_Registers.h have different vendor ids"
#endif
#if (( GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION != GMAC_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Types.h and Gmac_Ip_Device_Registers.h are different"
#endif
#if (( GMAC_IP_TYPES_SW_MAJOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     ( GMAC_IP_TYPES_SW_MINOR_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     ( GMAC_IP_TYPES_SW_PATCH_VERSION != GMAC_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Types.h and Gmac_Ip_Device_Registers.h are different"
#endif

/* Checks against Gmac_Ip_Features.h */
#if (GMAC_IP_TYPES_VENDOR_ID != GMAC_IP_FEATURES_VENDOR_ID)
    #error "Gmac_Ip_Types.h and Gmac_Ip_Features.h have different vendor ids"
#endif
#if (( GMAC_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != GMAC_IP_FEATURES_AR_RELEASE_MAJOR_VERSION) || \
     ( GMAC_IP_TYPES_AR_RELEASE_MINOR_VERSION    != GMAC_IP_FEATURES_AR_RELEASE_MINOR_VERSION) || \
     ( GMAC_IP_TYPES_AR_RELEASE_REVISION_VERSION != GMAC_IP_FEATURES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Gmac_Ip_Types.h and Gmac_Ip_Features.h are different"
#endif
#if (( GMAC_IP_TYPES_SW_MAJOR_VERSION != GMAC_IP_FEATURES_SW_MAJOR_VERSION) || \
     ( GMAC_IP_TYPES_SW_MINOR_VERSION != GMAC_IP_FEATURES_SW_MINOR_VERSION) || \
     ( GMAC_IP_TYPES_SW_PATCH_VERSION != GMAC_IP_FEATURES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gmac_Ip_Types.h and Gmac_Ip_Features.h are different"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Return values
 * @implements Gmac_Ip_StatusType_structure
 */
typedef enum
{
    /* Generic error codes */
    GMAC_STATUS_SUCCESS                    = 0x000U,   /*!< Generic operation success status */
    GMAC_STATUS_ERROR                      = 0x001U,   /*!< Generic operation failure status */
    GMAC_STATUS_BUSY                       = 0x002U,   /*!< Generic operation busy status */
    GMAC_STATUS_TIMEOUT                    = 0x003U,   /*!< Generic operation timeout status */
    GMAC_STATUS_UNSUPPORTED                = 0x004U,   /*!< Generic operation unsupported status */
    GMAC_STATUS_CACHE_ERROR                = 0x005U,   /*!< Generic operation cache operation failed */

    /* GMAC specific error codes */
    GMAC_STATUS_RX_QUEUE_EMPTY             = 0xA01U,   /*!< There is no available frame in the receive queue */
    GMAC_STATUS_TX_QUEUE_FULL              = 0xA02U,   /*!< There is no available space for the frame in the transmit queue */
    GMAC_STATUS_BUFF_NOT_FOUND             = 0xA03U,   /*!< The specified buffer was not found in the queue */
    GMAC_STATUS_TX_BUFF_BUSY               = 0xA04U,   /*!< All internal TX buffers are currently in use */
    GMAC_STATUS_TX_BUFF_OVERFLOW           = 0xA05U    /*!< The requested TX buffer length cannot*/
} Gmac_Ip_StatusType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Common interrupt sources
 * @implements Gmac_Ip_InterruptType_structure
 */
typedef enum
{
#if FEATURE_GMAC_RGMII_EN || FEATURE_GMAC_SMII_EN
    GMAC_MAC_INTERRUPT_RGSMIIIS = GMAC_MAC_INTERRUPT_STATUS_RGSMIIIS_MASK,
#endif
    GMAC_MAC_INTERRUPT_PHYIS   = GMAC_MAC_INTERRUPT_STATUS_PHYIS_MASK,
#if FEATURE_GMAC_PMT_EN
    GMAC_MAC_INTERRUPT_PMTIS   = GMAC_MAC_INTERRUPT_STATUS_PMTIS_MASK,
#endif
    GMAC_MAC_INTERRUPT_MMCIS   = GMAC_MAC_INTERRUPT_STATUS_MMCIS_MASK,
    GMAC_MAC_INTERRUPT_MMCRXIS = GMAC_MAC_INTERRUPT_STATUS_MMCRXIS_MASK,
    GMAC_MAC_INTERRUPT_MMCTXIS = GMAC_MAC_INTERRUPT_STATUS_MMCTXIS_MASK,
    GMAC_MAC_INTERRUPT_TSIS    = GMAC_MAC_INTERRUPT_STATUS_TSIS_MASK,
    GMAC_MAC_INTERRUPT_TXSTSIS = GMAC_MAC_INTERRUPT_STATUS_TXSTSIS_MASK,
    GMAC_MAC_INTERRUPT_RXSTSIS = GMAC_MAC_INTERRUPT_STATUS_RXSTSIS_MASK,
    GMAC_MAC_INTERRUPT_FPEIS   = GMAC_MAC_INTERRUPT_STATUS_FPEIS_MASK,
    GMAC_MAC_INTERRUPT_MDIOIS  = GMAC_MAC_INTERRUPT_STATUS_MDIOIS_MASK,
    GMAC_MAC_INTERRUPT_MFTIS   = GMAC_MAC_INTERRUPT_STATUS_MFTIS_MASK,
    GMAC_MAC_INTERRUPT_MFRIS   = GMAC_MAC_INTERRUPT_STATUS_MFRIS_MASK
} Gmac_Ip_InterruptType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Channel interrupt sources
 * @implements Gmac_Ip_ChInterruptType_structure
 */
typedef enum
{
    GMAC_CH_INTERRUPT_TI  = GMAC_DMA_CH0_STATUS_TI_MASK,
    GMAC_CH_INTERRUPT_TPS = GMAC_DMA_CH0_STATUS_TPS_MASK,
    GMAC_CH_INTERRUPT_TBU = GMAC_DMA_CH0_STATUS_TBU_MASK,
    GMAC_CH_INTERRUPT_RI  = GMAC_DMA_CH0_STATUS_RI_MASK,
    GMAC_CH_INTERRUPT_RBU = GMAC_DMA_CH0_STATUS_RBU_MASK,
    GMAC_CH_INTERRUPT_RPS = GMAC_DMA_CH0_STATUS_RPS_MASK,
    GMAC_CH_INTERRUPT_RWT = GMAC_DMA_CH0_STATUS_RWT_MASK,
    GMAC_CH_INTERRUPT_ETI = GMAC_DMA_CH0_STATUS_ETI_MASK,
    GMAC_CH_INTERRUPT_ERI = GMAC_DMA_CH0_STATUS_ERI_MASK,
    GMAC_CH_INTERRUPT_FBE = GMAC_DMA_CH0_STATUS_FBE_MASK,
    GMAC_CH_INTERRUPT_CDE = GMAC_DMA_CH0_STATUS_CDE_MASK,
    GMAC_CH_INTERRUPT_TEB = GMAC_DMA_CH0_STATUS_TEB_MASK,
    GMAC_CH_INTERRUPT_REB = GMAC_DMA_CH0_STATUS_REB_MASK
} Gmac_Ip_ChInterruptType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Configurations related to the operating mode of the MAC.
 * @implements Gmac_Ip_MacConfigType_structure
 */
typedef enum
{
    GMAC_MAC_CONFIG_SA_INSERTION = GMAC_MAC_CONFIGURATION_SARC(2U),         /*!< Configures MAC address inserted in SA field. */
    GMAC_MAC_CONFIG_SA_REPLACEMENT = GMAC_MAC_CONFIGURATION_SARC(3U),       /*!< Configures MAC address replaced in SA field. */
    GMAC_MAC_CONFIG_CHECKSUM_OFFLOAD = GMAC_MAC_CONFIGURATION_IPC_MASK,     /*!< Enables the IPv4 header checksum checking and IPv4 or IPv6 TCP, UDP, or ICMP payload
                                                                                 checksum checking. */
    GMAC_MAC_CONFIG_CRC_STRIPPING = GMAC_MAC_CONFIGURATION_CST_MASK,        /*!< The last four bytes (FCS) of all packets of Ether type (type field greater than 1,536)
                                                                                 are stripped and dropped before forwarding the packet to the application. */
    GMAC_MAC_CONFIG_AUTO_PAD = GMAC_MAC_CONFIGURATION_ACS_MASK,             /*!< The MAC strips the Pad or FCS field on the incoming packets only if the value of the
                                                                                 length field is less than 1,536 bytes. */
    GMAC_MAC_CONFIG_JUMBO_PKT_EN = GMAC_MAC_CONFIGURATION_JE_MASK,          /*!< The MAC allows jumbo packets of 9,018 bytes (9,022 bytes for VLAN tagged packets). */
    GMAC_MAC_CONFIG_LOOPBACK = GMAC_MAC_CONFIGURATION_LM_MASK,              /*!< MAC operates in the loopback mode at GMII or MII. */
    GMAC_MAC_CONFIG_ENABLE_CRS_FD = GMAC_MAC_CONFIGURATION_ECRSFD_MASK,     /*!< The MAC transmitter checks the CRS signal before packet transmission in the full-duplex
                                                                                 mode. The MAC starts the transmission only when the CRS signal is low. */
    GMAC_MAC_CONFIG_DISABLE_RECEIVE_OWN_HD = GMAC_MAC_CONFIGURATION_DO_MASK, /*!< The MAC disables the reception of packets when the gmii_txen_o is asserted in the
                                                                                 half-duplex mode. */
    GMAC_MAC_CONFIG_DISABLE_CRS_HD = GMAC_MAC_CONFIGURATION_DCRS_MASK,      /*!< The MAC transmitter ignores the (G)MII CRS signal during packet transmission in the
                                                                                 half-duplex mode. As a result, no errors are generated because of Loss of Carrier or
                                                                                 No Carrier during transmission. */
    GMAC_MAC_CONFIG_DISABLE_RETRY = GMAC_MAC_CONFIGURATION_DR_MASK,         /*!< The MAC attempts only one transmission. When a collision occurs on the (G)MII interface,
                                                                                 the MAC ignores the current packet transmission and reports a Packet Abort with excessive
                                                                                 collision error in the Tx packet status. */
    GMAC_MAC_CONFIG_DEFERRAL_CHECK_HD = GMAC_MAC_CONFIGURATION_DC_MASK      /*!< The deferral check function is enabled in the MAC. The MAC issues a Packet Abort status,
                                                                                 along with the excessive deferral error bit set in the Tx packet status, when the Tx
                                                                                 state machine is deferred for more than 24,288 bit times in 10/100 Mbps mode (155,680 bits
                                                                                 times in 1000/2500 Mbps operation). Deferral begins when the transmitter is ready to transmit,
                                                                                 but it is prevented because of an active carrier sense signal (CRS) on (G)MII. */
} Gmac_Ip_MacConfigType;
/** @endcond */


/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Configurations related to the MAC filters for incoming frames.
 */
typedef enum
{
    GMAC_PKT_FILTER_RECV_ALL = (sint32)GMAC_MAC_PACKET_FILTER_RA_MASK,              /*!< Passes all received packets to the application, irrespective of whether
                                                                                         they pass the address filter or not. */
    GMAC_PKT_FILTER_HASH_OR_PERFECT_FILTER = GMAC_MAC_PACKET_FILTER_HPF_MASK,       /*!< The address filter passes a packet if it matches either the perfect filtering or
                                                                                         hash filtering. */
    GMAC_PKT_FILTER_BLOCK_CONTROL_PKTS = GMAC_MAC_PACKET_FILTER_PCF(0U),            /*!< Blocks all control packets from reaching the application. */
    GMAC_PKT_FILTER_BLOCK_PAUSE_PKTS = GMAC_MAC_PACKET_FILTER_PCF(1U),              /*!< Forwards all control packets except Pause packets to the application even
                                                                                         if they fail the Address filter. */
    GMAC_PKT_FILTER_PASS_ALL_CONTROL_PKTS = GMAC_MAC_PACKET_FILTER_PCF(2U),         /*!< Forwards all control packets to the application even if they fail the
                                                                                         Address filter. */
    GMAC_PKT_FILTER_PASS_CONTROL_PKTS_ADDR_MATCH = GMAC_MAC_PACKET_FILTER_PCF(3U),  /*!< Forwards the control packets that pass the Address filter. */
    GMAC_PKT_FILTER_DISABLE_BROADCAST = GMAC_MAC_PACKET_FILTER_DBF_MASK,            /*!< Blocks all incoming broadcast packets. */
    GMAC_PKT_FILTER_PASS_ALL_MULTICAST = GMAC_MAC_PACKET_FILTER_PM_MASK,            /*!< All received packets with a multicast destination address are passed. */
    GMAC_PKT_FILTER_DST_ADDR_INV_FILTER_EN = GMAC_MAC_PACKET_FILTER_DAIF_MASK,      /*!< The Address checking operates in inverse filtering mode for the destination
                                                                                         address comparison for both unicast and multicast packets. */
    GMAC_PKT_FILTER_HASH_MULTICAST = GMAC_MAC_PACKET_FILTER_HMC_MASK,               /*!< The destination address filtering of received multicast packets is done
                                                                                         according to the hash table. */
    GMAC_PKT_FILTER_HASH_UNICAST = GMAC_MAC_PACKET_FILTER_HUC_MASK,                 /*!< The destination address filtering of received unicast packets is done
                                                                                         according to the hash table. */
    GMAC_PKT_FILTER_PROMISCUOUS_MODE = GMAC_MAC_PACKET_FILTER_PR_MASK,               /*!< Passes all incoming packets irrespective of the destination or source address. */
} Gmac_Ip_PacketFilterConfigType;
/** @endcond */

/*!
 * @brief Statistics counters enumeration
 * @implements Gmac_Ip_CounterType_structure
 */
typedef enum
{
    GMAC_CTR_TX_OCTET_COUNT_GOOD_BAD,
    GMAC_CTR_TX_PACKET_COUNT_GOOD_BAD,
    GMAC_CTR_TX_BROADCAST_PACKETS_GOOD,
    GMAC_CTR_TX_MULTICAST_PACKETS_GOOD,
    GMAC_CTR_TX_64OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_65TO127OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_128TO255OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_256TO511OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_512TO1023OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_UNICAST_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_MULTICAST_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_BROADCAST_PACKETS_GOOD_BAD,
    GMAC_CTR_TX_UNDERFLOW_ERROR_PACKETS,
    GMAC_CTR_TX_SINGLE_COLLISION_GOOD_PACKETS,
    GMAC_CTR_TX_MULTIPLE_COLLISION_GOOD_PACKETS,
    GMAC_CTR_TX_DEFERRED_PACKETS,
    GMAC_CTR_TX_LATE_COLLISION_PACKETS,
    GMAC_CTR_TX_EXCESSIVE_COLLISION_PACKETS,
    GMAC_CTR_TX_CARRIER_ERROR_PACKETS,
    GMAC_CTR_TX_OCTET_COUNT_GOOD,
    GMAC_CTR_TX_PACKET_COUNT_GOOD,
    GMAC_CTR_TX_EXCESSIVE_DEFERRAL_ERROR,
    GMAC_CTR_TX_PAUSE_PACKETS,
    GMAC_CTR_TX_VLAN_PACKETS_GOOD,
    GMAC_CTR_TX_OSIZE_PACKETS_GOOD,
    GMAC_CTR_RESERVED,
    GMAC_CTR_RX_PACKETS_COUNT_GOOD_BAD,
    GMAC_CTR_RX_OCTET_COUNT_GOOD_BAD,
    GMAC_CTR_RX_OCTET_COUNT_GOOD,
    GMAC_CTR_RX_BROADCAST_PACKETS_GOOD,
    GMAC_CTR_RX_MULTICAST_PACKETS_GOOD,
    GMAC_CTR_RX_CRC_ERROR_PACKETS,
    GMAC_CTR_RX_ALIGNMENT_ERROR_PACKETS,
    GMAC_CTR_RX_RUNT_ERROR_PACKETS,
    GMAC_CTR_RX_JABBER_ERROR_PACKETS,
    GMAC_CTR_RX_UNDERSIZE_PACKETS_GOOD,
    GMAC_CTR_RX_OVERSIZE_PACKETS_GOOD,
    GMAC_CTR_RX_64OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_65TO127OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_128TO255OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_256TO511OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_512TO1023OCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_UNICAST_PACKETS_GOOD,
    GMAC_CTR_RX_LENGTH_ERROR_PACKETS,
    GMAC_CTR_RX_OUT_OF_RANGE_TYPE_PACKETS,
    GMAC_CTR_RX_PAUSE_PACKETS,
    GMAC_CTR_RX_FIFO_OVERFLOW_PACKETS,
    GMAC_CTR_RX_VLAN_PACKETS_GOOD_BAD,
    GMAC_CTR_RX_WATCHDOG_ERROR_PACKETS,
    GMAC_CTR_RX_RECEIVE_ERROR_PACKETS,
    GMAC_CTR_RX_CONTROL_PACKETS_GOOD,
    GMAC_CTR_NUMBER_OF_COUNTERS
} Gmac_Ip_CounterType;

/*!
 * @brief Controller power state indication
 */
typedef enum
{
    GMAC_PSTATE_INACTIVE = 0U,  /* Controller is powered on and Transmitter/Receiver are disabled */
    GMAC_PSTATE_ACTIVE   = 1U,  /* Controller is powered on and Transmitter/Receiver are enabled */
    GMAC_PSTATE_SLEEP    = 2U,  /* Controller is sleeping (WoL or LPI) and waiting for wake-up packet */
    GMAC_PSTATE_RESET    = 3U   /* Controller is resetting its internal logic and registers */
} Gmac_Ip_PowerStateType;

/*!
 * @brief Media Independent Interface speed selection
 * @implements Gmac_Ip_SpeedType_structure
 */
typedef enum
{
    GMAC_SPEED_1G    = 0U, /*!< Speed 1 Gbps. */
    GMAC_SPEED_10M   = 2U, /*!< Speed 10 Mbps. */
    GMAC_SPEED_100M  = 3U, /*!< Speed 100 Mbps. */
#if FEATURE_OVERCLOCKED_EN
    GMAC_SPEED_200M  = GMAC_SPEED_100M, /*!< Speed 200 Mbps. */
#endif
#if FEATURE_GMAC_SGMII_EN
    GMAC_SPEED_2500M = 4U  /*!< Speed 2500 Mbps. */
#endif
} Gmac_Ip_SpeedType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Media Independent Interface full-/half-duplex selection
 * @implements Gmac_Ip_DuplexType_structure
 */
typedef enum
{
    GMAC_HALF_DUPLEX = 0U, /*!< Half-duplex mode. */
    GMAC_FULL_DUPLEX       /*!< Full-duplex mode. */
} Gmac_Ip_DuplexType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Media Independent Interface mode selection
 * @implements Gmac_Ip_MiiModeType_structure
 */
typedef enum
{
    GMAC_MII_MODE = 0U,      /*!< MII mode for data interface. */
#if FEATURE_GMAC_RGMII_EN
    GMAC_RGMII_MODE = 1U,    /*!< RGMII mode for data interface. */
#endif
    GMAC_RMII_MODE = 4U,     /*!< RMII mode for data interface. */
#if FEATURE_GMAC_SGMII_EN
    GMAC_SGMII_MODE          /*!< SGMII mode for data interface. */
#endif
} Gmac_Ip_MiiModeType;
/** @endcond */

/*!
 * @brief Source/Destination address filter selection
 * @implements Gmac_Ip_MacAddrFilterType_structure
 */
typedef enum
{
    GMAC_DST_ADRR_FILTER     = 0U,   /*!< Destination address filter. */
    GMAC_SRC_ADDR_FILTER     = 1U,   /*!< Source address filter. */
    GMAC_SRC_ADDR_INV_FILTER = 2U    /*!< Source address inverse filter. */
} Gmac_Ip_MacAddrFilterType;

/*!
 * @brief CRC and Pad insertion control
 * @implements Gmac_Ip_CrcPadControlType_structure
 */
typedef enum
{
    GMAC_CRC_AND_PAD_INSERTION = 0U,  /*!< Appends the CRC at the end of the transmitted packet of length greater than or equal
                                           to 60 bytes. Appends padding and CRC to a packet with length less than 60 bytes.*/
    GMAC_CRC_INSERTION         = 1U,  /*!< Appends the CRC at the end of the transmitted packet but it does not append padding.
                                           The application should ensure that the padding bytes are present in the packet being transferred. */
    GMAC_CRC_INSERTION_DISABLE = 2U,  /*!< Does not append the CRC at the end of the transmitted packet. The application should
                                           ensure that the padding and CRC bytes are present in the packet being transferred. */
    GMAC_CRC_REPLACEMENT       = 3U   /*!< Replaces the last four bytes of the transmitted packet with recalculated CRC bytes.
                                           The application should ensure that the padding and CRC bytes are present in the packet being transferred. */
} Gmac_Ip_CrcPadControlType;

/*!
 * @brief Checksum insertion control
 * @implements Gmac_Ip_ChecksumInsControlType_structure
 */
typedef enum
{
    GMAC_CHECKSUM_INSERTION_DISABLE          = 0U,  /*!< Checksum insertion is disabled. */
    GMAC_CHECKSUM_INSERTION_IP               = 1U,  /*!< IP header checksum calculation and insertion are enabled. */
    GMAC_CHECKSUM_INSERTION_PROTO_NO_PSEUDOH = 2U,  /*!< Protocol checksum calculation and insertion are enabled,
                                                         but pseudo-header checksum is not calculated in hardware. */
    GMAC_CHECKSUM_INSERTION_PROTO_PSEUDOH    = 3U   /*!< Protocol checksum calculation and insertion are enabled,
                                                         and pseudo-header checksum is calculated in hardware. */
} Gmac_Ip_ChecksumInsControlType;

/*!
 * @brief Type of payload encapsulated in the IP datagram
 * @implements Gmac_Ip_PayloadType_structure
 */
typedef enum
{
    GMAC_IP_PAYLOAD_TYPE_UNKNOWN = 0U,   /*!< Unknown type or IP payload not processed. */
    GMAC_IP_PAYLOAD_TYPE_UDP     = 1U,   /*!< UDP packet. */
    GMAC_IP_PAYLOAD_TYPE_TCP     = 2U,   /*!< TCP packet. */
    GMAC_IP_PAYLOAD_TYPE_ICMP    = 3U    /*!< ICMP packet. */
} Gmac_Ip_PayloadType;

/*!
 * @brief VLAN type
 * @implements Gmac_Ip_VlanType_structure
 */
typedef enum
{
    GMAC_VLAN_TYPE_C_VLAN = 0U,   /*!< C-VLAN type (0x8100). */
    GMAC_VLAN_TYPE_S_VLAN = 1U,   /*!< S-VLAN type (0x88A8). */
} Gmac_Ip_VlanType;

/*!
 * @brief VLAN tag and type deletion, insertion, or replacement control for transmitted packets
 * @implements Gmac_Ip_VlanInsControlType_structure
 */
typedef enum
{
    GMAC_VLAN_TAG_NO_CONTROL  = 0U,   /*!< The VLAN tag is not altered in the packet to be transmitted. */
    GMAC_VLAN_TAG_DELETION    = 1U,   /*!< The VLAN tag is deleted from the packet to be transmitted. */
    GMAC_VLAN_TAG_INSERTION   = 2U,   /*!< The VLAN tag is inserted in the packet to be transmitted. */
    GMAC_VLAN_TAG_REPLACEMENT = 3U    /*!< The VLAN tag is replaced in the packet to be transmitted. */
} Gmac_Ip_VlanInsControlType;

/*!
 * @brief VLAN tag stripping control for received packets.
 * @implements Gmac_Ip_VlanStripControlType_structure
 */
typedef enum
{
    GMAC_VLAN_TAG_DO_NOT_STRIP         = 0U,  /*!< Does not strip the inner VLAN tag in the received packet. */
    GMAC_VLAN_TAG_STRIP_IF_FILTER_PASS = 1U,  /*!< Strips the inner VLAN tag in the received packet if the VLAN filter passes. */
    GMAC_VLAN_TAG_STRIP_IF_FILTER_FAIL = 2U,  /*!< Strips the inner VLAN tag in the received packet if the VLAN filter fails. */
    GMAC_VLAN_TAG_ALWAYS_STRIP         = 3U,  /*!< Always strips the inner VLAN tag in the received packet. */
} Gmac_Ip_VlanStripControlType;

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief VLAN PCP Enumeration
 */
typedef enum
{
    GMAC_VLAN_PRIORITY_0 = 0x01U,
    GMAC_VLAN_PRIORITY_1 = 0x02U,
    GMAC_VLAN_PRIORITY_2 = 0x04U,
    GMAC_VLAN_PRIORITY_3 = 0x08U,
    GMAC_VLAN_PRIORITY_4 = 0x10U,
    GMAC_VLAN_PRIORITY_5 = 0x20U,
    GMAC_VLAN_PRIORITY_6 = 0x40U,
    GMAC_VLAN_PRIORITY_7 = 0x80U
} Gmac_Ip_VlanPriorityType;
/** @endcond */

/*!
 * @brief System time correction offset.
 * @implements Gmac_Ip_SysTimeCorrOffsetType_structure
 */
typedef enum
{
    GMAC_SYS_TIME_CORR_POSITIVE = 0U,  /*!< Correction value is added to the system time. */
    GMAC_SYS_TIME_CORR_NEGATIVE = 1U,  /*!< Correction value is subtracted from the system time. */
} Gmac_Ip_SysTimeCorrOffsetType;

/*!
 * @brief Transmitter scheduling algorithm.
 * @implements Gmac_Ip_TxSchedAlgoType_structure
 */
typedef enum {
    GMAC_SCHED_ALGO_WRR  = 0U,  /*!< Weighted round robin algorithm. */
    GMAC_SCHED_ALGO_WFQ  = 1U,  /*!< Weighted fair queueing algorithm. */
    GMAC_SCHED_ALGO_DWRR = 2U,  /*!< Deficit weighted round robin algorithm. */
    GMAC_SCHED_ALGO_SP   = 3U   /*!< Strict priority algorithm. */
} Gmac_Ip_TxSchedAlgoType;

/*!
 * @brief Available Tx threshold values.
 * @implements Gmac_Ip_TxThresholdType_structure
 */
typedef enum {
    GMAC_TRESHOLD_32_BYTES  = 0U,
    GMAC_TRESHOLD_64_BYTES  = 1U,
    GMAC_TRESHOLD_96_BYTES  = 2U,
    GMAC_TRESHOLD_128_BYTES = 3U,
    GMAC_TRESHOLD_192_BYTES = 4U,
    GMAC_TRESHOLD_256_BYTES = 5U,
    GMAC_TRESHOLD_384_BYTES = 6U,
    GMAC_TRESHOLD_512_BYTES = 7U
} Gmac_Ip_TxThresholdType;

#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
/*!
 * @brief Automotive safety errors.
 */
typedef enum {
    GMAC_SAF_ERR_CSR_EMPTY_DATA           = 0x01U,  /*!< Unreachable CSR Interface Error */
    GMAC_SAF_ERR_ECC                      = 0x02U,  /*!< Uncorrectable ECC Data or Address Error */
    GMAC_SAF_ERR_FSM_STATE_PARITY         = 0x04U,  /*!< Uncorrectable FSM State Parity Error */
    GMAC_SAF_ERR_FSM_TIMEOUT              = 0x08U,  /*!< Uncorrectable FSM Timeout Error */
    GMAC_SAF_ERR_DATA_PATH_PARITY         = 0x10U,  /*!< Uncorrectable Data Path Parity Error */
    GMAC_SAF_ERR_MASTER_INTERFACE_TIMEOUT = 0x20U   /*!< Uncorrectable Master Interface Timeout Error */
} Gmac_Ip_SafetyErrorType;

/*!
 * @brief Callback function invoked when a safety event is encountered
 */
typedef void (*Gmac_Ip_SafetyCallbackType)(const uint8 Instance, const Gmac_Ip_SafetyErrorType Error);
#endif

/*!
 * @brief Callback function invoked when a general event is encountered
 */
typedef void (*Gmac_Ip_CallbackType)(const uint8 Instance);

/*!
 * @brief Callback function invoked when a channel event is encountered
 */
typedef void (*Gmac_Ip_ChCallbackType)(const uint8 Instance, const uint8 Channel);

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Available queue operation mode values
 */
typedef enum
{
    GMAC_OP_MODE_DISABLE = 0U,  /*!< Queue not enabled */
    GMAC_OP_MODE_AVB     = 1U,  /*!< Queue enabled for Audio-Video Bridging */
    GMAC_OP_MODE_DCB_GEN = 2U   /*!< Queue enabled for Data Center Bridging or Generic Traffic */
} Gmac_Ip_OperationModeType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Send/Receive internal buffer descriptor
 * @implements Gmac_Ip_BufferDescriptorType_structure
 */
typedef struct
{
    uint32 Des0;
    uint32 Des1;
    uint32 Des2;
    uint32 Des3;
    uint32 Info0;
    uint32 Info1;
    uint32 Padding0;
    uint32 Padding1;
} Gmac_Ip_BufferDescriptorType;
/** @endcond */

typedef struct
{
    uint32 TimeInterval;
    uint8 GateControl;
}Gmac_Ip_TxGateControl;

typedef struct sGmac_Ip_TxTimeAwareShaper
{
    uint32 BaseTimeSecond;
    uint32 BaseTimeNanoSecond;
    uint32 CycleTimeSecond;
    uint32 CycleTimeNanoSecond;
    uint32 ExtendedTime;
    uint16 GateControlDepth;
    uint16 ReleaseAdvanceTime;
    uint16 HoldAdvanceTime;
    uint8 PreemptionClassic;
    const Gmac_Ip_TxGateControl *GateControlList;
}Gmac_Ip_TxTimeAwareShaper;

/*!
 * @brief Specialization of ring configuration for Tx Rings
 */
typedef struct sGmac_Ip_TxRingConfigType
{
    uint32 Weight;                          /*!< Scheduling weight/quantum for DCB queues */
    uint32 IdleSlopeCredit;                 /*!< Idle slope credit for AVB queues */
    uint32 SendSlopeCredit;                 /*!< Send slope credit for AVB queues */
    uint32 HiCredit;                        /*!< High credit limit for AVB queues */
    sint32 LoCredit;                        /*!< Low credit limit for AVB queues */
    Gmac_Ip_BufferDescriptorType *RingDesc; /*!< Buffer descriptor ring start address. */
    Gmac_Ip_ChCallbackType Callback;        /*!< Callback function for current channel. */
    uint8 *Buffer;                          /*!< Buffer data pool start address */
    uint32 Interrupts;                      /*!< Channel interrupt sources. A logical OR of "Gmac_Ip_ChInterruptType". */
    uint16 BufferLen;                       /*!< Length of each individual buffer in a pool */
    uint16 RingSize;                        /*!< Buffer descriptors number. */
    uint8 PriorityMask;                     /*!< A logical OR of "Gmac_Ip_VlanPriorityType". */
    uint8 DmaBurstLength;                   /*!< Maximum number of beats in one DMA block data transfer. */
    Gmac_Ip_OperationModeType QueueOpMode;  /*!< Queue operation mode */
} Gmac_Ip_TxRingConfigType;


/*!
 * @brief Specialization of ring configuration for Rx Rings
 * @implements Gmac_Ip_BufferConfigType_structure
 */
typedef struct sGmac_Ip_RxRingConfigType
{
    Gmac_Ip_BufferDescriptorType *RingDesc; /*!< Buffer descriptor ring start address. */
    Gmac_Ip_ChCallbackType Callback;        /*!< Callback function for current channel. */
    uint8 *Buffer;                          /*!< Buffer data pool start address */
    uint32 Interrupts;                      /*!< Channel interrupt sources. A logical OR of "Gmac_Ip_ChInterruptType". */
    uint16 BufferLen;                       /*!< Length of each individual buffer in a pool */
    uint16 RingSize;                        /*!< Buffer descriptors number. */
    uint8 PriorityMask;                     /*!< A logical OR of "Gmac_Ip_VlanPriorityType". */
    uint8 DmaBurstLength;                   /*!< Maximum number of beats in one DMA block data transfer. */
} Gmac_Ip_RxRingConfigType;


/*!
 * @brief Send/Receive buffer information for the user
 * @implements Gmac_Ip_BufferType_structure
 */
typedef struct
{
    uint8 *Data;    /*!< Pointer to the data buffer */
    uint16 Length;  /*!< Length of the data buffer */
} Gmac_Ip_BufferType;

/*!
 * @brief Defines the timestamp
 * @implements Gmac_Ip_TimestampType_structure
 */
typedef struct
{
    uint32 nanoseconds;  /*!< Nanoseconds part of the time. */
    uint32 seconds;      /*!< The 32 least significant bits of the 48 bits seconds part of the time. */
    uint16 secondsHi;    /*!< The 16 most significant bits of the 48 bit seconds part of the time. */
} Gmac_Ip_TimestampType;

/*!
 * @brief Defines a structure to configure the system time
 * @implements Gmac_Ip_SysTimeConfigType_structure
 */
typedef struct
{
    uint8 SubSecondInc;                        /*!< The value in nanoseconds to be accumulated every clock cycle. */
    uint8 SubNanoSecondsInc;                   /*!< The value in sub-nanoseconds to be accumulated every clock cycle, represented in nanoseconds multiplied by 2^8.
                                                    For example, if the required increment is 5.3ns, then subSecondInc should be 0x05 and subNanosecondsInc should
                                                    be 0x4C (0.3 * 2^8). */
    Gmac_Ip_TimestampType * InitialTimestamp;  /*!< Nanoseconds part of the time. */
} Gmac_Ip_SysTimeConfigType;

/*!
 * @brief Transmit options for a particular frame.
 * @implements Gmac_Ip_TxOptionsType_structure
 */
typedef struct
{
    boolean NoInt;                               /*!< Does not generate interrupt on transmit completion. */
    Gmac_Ip_CrcPadControlType CrcPadIns;         /*!< Controls the CRC and pad insertion for Tx packet. */
    Gmac_Ip_ChecksumInsControlType ChecksumIns;  /*!< Controls the IP checksum insertion for Tx packet. */
} Gmac_Ip_TxOptionsType;

/*!
 * @brief Detailed status of a transmit buffer descriptor
 * @implements Gmac_Ip_TxInfoType_structure
 */
typedef struct
{
    uint32 ErrMask;            /*!< Mask of GMAC_TX_ERR_*, representing the errors that occurred. */
    Gmac_Ip_TimestampType Timestamp;  /*!< The timestamp of the transmitted packet. */
} Gmac_Ip_TxInfoType;

/*! @brief When set, it indicates that the Checksum Offload engine detected an IP header error. */
#define GMAC_TX_ERR_IP_HEADER_ERROR         (0x00001U)

/*! @brief When set, it indicates that the MAC transmitter has experienced a jabber time-out. */
#define GMAC_TX_ERR_JABBER_TIMEOUT          (0x04000U)

/*! @brief When set, it indicates that the GMAC module flushed the packet because of a
 *         software flush command given by the CPU. */
#define GMAC_TX_ERR_PACKET_FLUSHED          (0x02000U)

/*! @brief When set, it indicates that the Checksum Offload engine had a failure and did not
 *         insert any checksum into the encapsulated TCP, UDP, or ICMP payload. */
#define GMAC_TX_ERR_PAYLOAD_CHECKSUM_ERROR  (0x01000U)

/*! @brief When set, it indicates that Loss of Carrier occurred during packet transmission.
 *         This is valid only for the packets transmitted without collision and when the MAC
 *         operates in the half-duplex mode. */
#define GMAC_TX_ERR_LOSS_OF_CARRIER         (0x00800U)

/*! @brief When set, it indicates that the carrier sense signal form the PHY was not asserted
 *        during transmission. */
#define GMAC_TX_ERR_NO_CARRIER              (0x00400U)

/*! @brief When set, it indicates that packet transmission was aborted because a collision
 *         occurred after the collision window (64 byte times including Preamble in MII mode
 *         and 512 byte times including Preamble and Carrier Extension in GMII mode).
 *         This bit is not valid if Underflow Error is set. */
#define GMAC_TX_ERR_LATE_COLLISION          (0x00200U)

/*! @brief When set, it indicates that the transmission was aborted after 16 successive
 *         collisions while attempting to transmit the current packet. */
#define GMAC_TX_ERR_EXCESSIVE_COLLISION     (0x00100U)

/*! @brief When set, it indicates that the transmission ended because of excessive deferral of
 *         over 24,288 bit times (155,680 bits times in 1000 Mbps mode or Jumbo Packet enabled mode)
 *         if deferral check was set at init. */
#define GMAC_TX_ERR_EXCESSIVE_DEFERRAL      (0x00008U)

/*! @brief When set, it indicates that the MAC aborted the packet because the data arrived late
 *         from the system memory. */
#define GMAC_TX_ERR_UNDERFLOW_ERROR         (0x00004U)

/*!
 * @brief Detailed status of a receive buffer descriptor
 * @implements Gmac_Ip_RxInfoType_structure
 */
typedef struct
{
    uint32 ErrMask;                    /*!< Mask of GMAC_RX_ERR_* , representing the errors that occurred. */
    uint16 PktLen;                     /*!< Byte length of the received packet that was transferred to system memory (including CRC). */
    Gmac_Ip_PayloadType PayloadType;   /*!< The type of payload encapsulated in the IP datagram (this field is valid only if the
                                            Checksum Offloading feature is enabled when initializing the GMAC module). */
    boolean Ipv6;                      /*!< Indicates that the frame is an IPv6 frame (this field is valid only if the
                                            Checksum Offloading feature is enabled when initializing the GMAC module). */
    boolean Ipv4;                      /*!< Indicates that the frame is an IPv4 frame (this field is valid only if the
                                            Checksum Offloading feature is enabled when initializing the GMAC module). */
    boolean IpPayloadErr;              /*!< Indicates that an IP payload error has occurred (this field is valid only if the
                                            Checksum Offloading feature is enabled when initializing the GMAC module). */
    boolean IpHeaderErr;               /*!< Indicates that an IP header error has occurred (this field is valid only if the
                                            Checksum Offloading feature is enabled when initializing the GMAC module). */
    uint16 OuterVlanTag;               /*!< Contains the outer VLAN tag of the received packet. */
    uint16 InnerVlanTag;               /*!< Contains the inner VLAN tag of the received packet. This is valid only when
                                            Double VLAN tag processing is enabled. */
    Gmac_Ip_TimestampType Timestamp;   /*!< The timestamp of the received packet. */
} Gmac_Ip_RxInfoType;

/*! @brief When this bit is set, it indicates that a CRC Error occurred on the received packet. */
#define GMAC_RX_ERR_CRC_ERROR           (0x01000000U)

/*! @brief When this bit is set, it indicates that the received packet has a non-integer multiple
 *         of bytes (odd nibbles). This bit is valid only in the MII Mode. */
#define GMAC_RX_ERR_DRIBBLE_ERROR       (0x00080000U)

/*! @brief When this bit is set, it indicates that the Receive error signal and Receive data valid signal
 *         are asserted during packet reception. This error also includes carrier extension error
 *         in the GMII and half-duplex mode. */
#define GMAC_RX_ERR_RECEIVE_ERROR       (0x00100000U)

/*! @brief When this bit is set, it indicates that the Receive Watchdog Timer has expired while
 *         receiving the current packet. The current packet is truncated after watchdog timeout. */
#define GMAC_RX_ERR_WATCHDOG_TIMEOUT    (0x00400000U)

/*! @brief When this bit is set, it indicates that the received packet is damaged because of
 *         buffer overflow in Rx FIFO. */
#define GMAC_RX_ERR_OVERFLOW_ERROR      (0x00200000U)

/*! @brief When this bit is set, it indicates that the packet length exceeds the specified maximum
 *         Ethernet size of 1518, 1522, or 2000 bytes (9018 or 9022 bytes if jumbo packet enable is set). */
#define GMAC_RX_ERR_GIANT_PACKET        (0x00800000U)

/*!
 * @brief Defines the VLAN configuration structure
 * @implements Gmac_Ip_VlanConfigType_structure
 */
typedef struct
{
    boolean EnDoubleVlan;                        /*!< Enables processing of up to two VLAN tags on Tx and Rx (if present). */
    boolean EnSvlan;                             /*!< Enables MAC transmitter and receiver to consider the S-VLAN packets (Type = 0x88A8) as valid VLAN tagged packets. */
    Gmac_Ip_VlanInsControlType OuterVlanIns;     /*!< Selects if outer VLAN tag and type are deleted, inserted or replaced in transmitted packets. */
    Gmac_Ip_VlanInsControlType InnerVlanIns;     /*!< Selects if inner VLAN tag and type are deleted, inserted or replaced in transmitted packets. Effective only if double
                                                      VLAN processing is enabled. */
    Gmac_Ip_VlanStripControlType OuterVlanStrip; /*!< Selects if outer VLAN tag is stripped in received packets. */
    Gmac_Ip_VlanStripControlType InnerVlanStrip; /*!< Selects if inner VLAN tag is stripped in received packets. */
} Gmac_Ip_VlanConfigType;
#if (FEATURE_GMAC_VLAN_RX_FILTERS_NUM > 0U)
/*!
 * @brief Defines the VLAN filtering and matching options for received packets
 * @implements Gmac_Ip_VlanRxFilterType_structure
 */
typedef struct
{
    boolean EnInnerVlanMatch;  /*!< When true, the MAC receiver enables operation on the inner VLAN tag (if present). When false, the MAC receiver enables
                                    operation on the outer VLAN tag (if present). */
    boolean EnSvlanMatch;      /*!< When true, the MAC receiver enables filtering or matching for S-VLAN (Type = 0x88A8) packets. When false, the MAC
                                    receiver enables filtering or matching for C-VLAN (Type = 0x8100) packets. */
    boolean DisVlanTypeMatch;  /*!< When true, the MAC does not check whether the inner VLAN tag (if inner VLAN match is enabled) is of type S-VLAN or C-VLAN.
                                    When false, the MAC filters or matches the inner VLAN tag (if inner VLAN match is enabled) only when VLAN tag type is
                                    similar to the one specified by the Enable S-VLAN Match for received Frames.*/
    boolean EnInverseMatch;    /*!< When true, enables VLAN tag inverse filter match. */
    boolean En12bitMatch;      /*!< When true, a 12-bit VLAN identifier is used for comparing and filtering instead of the complete 16-bit VLAN tag.
                                    When false, the complete 16-bit VLAN tag is compared. */
} Gmac_Ip_VlanRxFilterType;
#endif
/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Defines the GMAC module configuration structure
 * @implements Gmac_Ip_ConfigType_structure
 */
typedef struct sGmac_Ip_ConfigType
{
    uint8 RxRingCount;                         /*!< The number of Receive rings to be used by the driver. */
    uint8 TxRingCount;                         /*!< The number of Transmit rings to be used by the driver. */
#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
    uint32 SafetyInterrupts;                   /*!< Safety interrupt sources. A logical OR of "Gmac_Ip_SafetyErrorType". */
    Gmac_Ip_SafetyCallbackType SafetyCallback; /*!< Safety callback function. */
#endif
    uint32 Interrupts;                         /*!< General interrupt sources. A logical OR of "Gmac_Ip_InterruptType". */
    Gmac_Ip_CallbackType Callback;             /*!< Callback function */
    Gmac_Ip_MiiModeType MiiMode;               /*!< MII mode. */
    Gmac_Ip_TxSchedAlgoType TxSchedAlgo;       /*!< Configures the global Tx scheduling algorithm affecting all Tx Queues */
    /* MAC configuration */
    Gmac_Ip_SpeedType Speed;                   /*!< Speed. */
    Gmac_Ip_DuplexType Duplex;                 /*!< Duplex. */
    uint32 MacConfig;                          /*!< Configures the operating mode of the MAC. A logical OR of "Gmac_Ip_MacConfigType". */
    uint32 MacPktFilterConfig;                 /*!< Configures the MAC packet filter. A logical OR of "Gmac_Ip_PacketFilterConfigType". */
    boolean EnableCtrl;                        /*!< Configures whether the controller is enabled at initialization. */
} Gmac_Ip_ConfigType;
/** @endcond */

/** @cond DRIVER_INTERNAL_USE_ONLY */
/*!
 * @brief Internal driver state structure
 * @implements Gmac_Ip_StateType_structure
 */
typedef struct sGmac_Ip_StateType
{
#if (FEATURE_GMAC_ASP_ALL || FEATURE_GMAC_ASP_ECC)
    Gmac_Ip_SafetyCallbackType SafetyCallback;                              /*!< Callback function for safety interrupts. */
#endif
    Gmac_Ip_CallbackType Callback;                                          /*!< Callback function for general interrupts. */
    Gmac_Ip_ChCallbackType RxChCallback[FEATURE_GMAC_NUM_CHANNELS];         /*!< Callback function for receive channels. */
    Gmac_Ip_ChCallbackType TxChCallback[FEATURE_GMAC_NUM_CHANNELS];         /*!< Callback function for transmit channels. */
    Gmac_Ip_BufferDescriptorType *TxCurrentDesc[FEATURE_GMAC_NUM_CHANNELS]; /*!< The current available transmit buffer descriptor pointer array. */
    Gmac_Ip_BufferDescriptorType *RxCurrentDesc[FEATURE_GMAC_NUM_CHANNELS]; /*!< The current available receive buffer descriptor pointer array. */
    Gmac_Ip_BufferDescriptorType *RxAllocDesc[FEATURE_GMAC_NUM_CHANNELS];   /*!< Pointer array used for enqueuing Rx buffers provided using Gmac_Ip_ProvideRxBuff. */
    uint16 RxRingCount;
    uint16 TxRingCount;
} Gmac_Ip_StateType;
/** @endcond */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* GMAC_IP_TYPES_H */
