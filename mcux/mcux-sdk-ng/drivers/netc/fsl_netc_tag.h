/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_NETC_SWITCH_TAG_H_
#define FSL_NETC_SWITCH_TAG_H_

#if defined(FSL_FEATURE_NETC_HAS_SWITCH_TAG) && FSL_FEATURE_NETC_HAS_SWITCH_TAG

#define NETC_SWITCH_DEFAULT_ETHER_TYPE 0x3AFD

/*! @brief Switch tag type */
typedef enum _netc_swt_tag_type
{
    kNETC_TagForward, /*!< Normal frame process. */
    kNETC_TagToPort,  /*!< The frame must be transmitted out a specific switch port. */
    kNETC_TagToHost,  /*!< Frames that are redirected or copied to the switch management port. */
} netc_swt_tag_type_t;

/*! @brief Switch tag subtype */
typedef enum _netc_swt_tag_subtype
{
    kNETC_TagToPortNoTs = 0,  /*!< Normal frame process. */
    kNETC_TagToPortOneStepTs, /*!< The frame must be transmitted out a specific switch port. */
    kNETC_TagToPortTwoStepTs, /*!< Frames that are redirected or copied to the switch management port. */
    kNETC_TagToPortAllTs,     /*!< Frames that are redirected or copied to the switch management port. */

    kNETC_TagToHostNoTs = 0,  /*!< Frames that are redirected or copied to the switch management port. */
    kNETC_TagToHostRxTs,      /*!< Frames that are redirected or copied to the switch management port. */
    kNETC_TagToHostTxTs,      /*!< Frames that are redirected or copied to the switch management port. */
} netc_swt_tag_subtype_t;

#pragma pack(1)
/*! @brief Switch tag common part */
typedef struct _netc_swt_tag_common
{
    uint16_t tpid;        /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint16_t subType : 4; /*!< Specific feature is based on tag type. Refer to @netc_swt_tag_subtype_t. */
    uint16_t type : 4;    /*!< Tag type. Refer to @netc_swt_tag_type_t. */
    uint16_t qv : 1;      /*!< QoS Valid. */
    uint16_t : 1;         /*!< Reserved. */
    uint16_t ipv : 3;     /*!< Internal Priority Value. */
    uint16_t : 1;         /*!< Reserved. */
    uint16_t dr : 2;      /*!< Drop Resilience. */
    uint8_t swtId : 3;    /*!< Switch ID. */
    uint8_t port : 5;     /*!< Switch port. */
} netc_swt_tag_common_t;

/*! @brief Switch tag for forward */
typedef struct _netc_swt_tag_forward
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint8_t pm : 1;               /*!< Port Masquerading. */
    uint8_t : 7;                  /*!< Reserved. */
} netc_swt_tag_forward_t;

/*! @brief Switch tag for to_port without timestamp */
typedef struct _netc_swt_tag_port_no_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint8_t : 8;                  /*!< Reserved. */
} netc_swt_tag_port_no_ts_t;

/*! @brief Switch tag for to_port with one-step timestamp */
typedef struct _netc_swt_tag_port_one_step_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint8_t : 8;                  /*!< Reserved. */
    uint32_t timestamp;           /*!< Timestamp. */
} netc_swt_tag_port_one_step_ts_t;

/*! @brief Switch tag for to_port without two-step timestamp */
typedef struct _netc_swt_tag_port_two_step_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint8_t tsReqId : 4;          /*!< Timestamp Request Identifier. */
    uint8_t : 4;                  /*!< Reserved. */
} netc_swt_tag_port_two_step_ts_t;

/*! @brief Switch tag for to_port with all timestamps */
typedef struct _netc_swt_tag_port_all_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint8_t tsReqId : 4;          /*!< Timestamp Request Identifier. */
    uint8_t : 4;                  /*!< Reserved. */
    uint32_t timestamp;           /*!< Timestamp. */
} netc_swt_tag_port_all_ts_t;

/*! @brief Switch tag for to_host */
typedef struct _netc_swt_tag_host
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint16_t : 4;                 /*!< Reserved. */
    uint16_t hostReason : 4;      /*!< Host reason. */
} netc_swt_tag_host_t;

/*! @brief Switch tag for to_host with timestamp */
typedef struct _netc_swt_tag_host_rx_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint16_t : 4;                 /*!< Reserved. */
    uint16_t hostReason : 4;      /*!< Host reason. */
    uint64_t timestamp;           /*!< Timestamp. */
} netc_swt_tag_host_rx_ts_t;

/*! @brief Switch tag for to_host with timestamp */
typedef struct _netc_swt_tag_host_tx_ts
{
    netc_swt_tag_common_t comTag; /*!< Tag Protocol Identifier to identify the tag as an NXP switch tag. */
    uint16_t tsReqId : 4;         /*!< Timestamp Request Identifier. */
    uint16_t hostReason : 4;      /*!< Host reason. */
    uint64_t timestamp;           /*!< Timestamp. */
} netc_swt_tag_host_tx_ts_t;
#pragma pack()

#endif /* FSL_FEATURE_NETC_HAS_SWITCH_TAG */

#endif /* FSL_NETC_SWITCH_TAG_H_ */
