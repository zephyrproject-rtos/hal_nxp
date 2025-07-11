/*
 * Copyright 2024-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_NETC_SOC_H_
#define _FSL_NETC_SOC_H_

#include "netc_hw/fsl_netc_hw.h"

#define TMR_PCI_HDR_TYPE0   TMR0_PCI_HDR_TYPE0
#define EMDIO_PCI_HDR_TYPE0 EMDIO0_PCI_HDR_TYPE0

/*! @brief Switch port numbers(Port0 ~ 3 in Switch Core). */
#define NETC_SOC_SWT_PORT_NUM (4U)

/*! @brief The Switch function register base address offset.(SW0_PCI_HDR_TYPE0) */
#define NETC_SOC_SWT_PCIE_FUNC_OFFSET (5U)
#define NETC_SOC_SWT_MSI_FUNC_OFFSET  (0U)

/*! @name NETC register map. */
/*@{*/
#define NETC_SWT_COMMON_BASE_OFFSET (0x1000U)  /*!< The ENETC common register base address offset. */
#define NETC_SWT_GLOBAL_BASE_OFFSET (0x70000U) /*!< The Switch global register base address offset. */
/*@}*/

/*
 *                port3  port2  port1  port0
 * 0x08 = 0b 0000   1      0      0      0
 * It means that input frame will forward to switch port3
 */
#ifndef NETC_SOC_INPUT_FRM_SWT_PORT_BITMAP
#define NETC_SOC_INPUT_FRM_SWT_PORT_BITMAP (0x08)
#endif

/*! @brief Station interface index enumerator */
typedef enum _netc_hw_si_idx
{
    kNETC_ENETC0PSI0 = (0U << 8U) | (0U << 4U) | 0U, /*!< ENETC0 PSI0, index 0 */
    kNETC_ENETC1PSI0 = (1U << 8U) | (0U << 4U) | 1U, /*!< ENETC1 PSI0, index 1 */
    kNETC_ENETC2PSI0 = (2U << 8U) | (0U << 4U) | 2U, /*!< ENETC2 PSI0, index 2 */
    kNETC_ENETC3PSI0 = (3U << 8U) | (0U << 4U) | 3U, /*!< ENETC3 PSI0, index 3 */
    kNETC_ENETC3VSI1 = (3U << 8U) | (1U << 4U) | 4U, /*!< ENETC3 VSI1, index 4 */
    kNETC_ENETC3VSI2 = (3U << 8U) | (2U << 4U) | 5U, /*!< ENETC3 VSI2, index 5 */
    kNETC_ENETC3VSI3 = (3U << 8U) | (3U << 4U) | 6U, /*!< ENETC3 VSI3, index 6 */
} netc_hw_si_idx_t;

/*! @brief Ethernet MAC port resource for the NETC module */
typedef enum _netc_hw_eth_port_idx
{
    kNETC_ENETC0EthPort   = 0U, /*!< Ethernet MAC port3(Eth2) for ENETC0 */
    kNETC_ENETC1EthPort   = 1U, /*!< Ethernet MAC port4(Eth3) for ENETC1 */
    kNETC_ENETC2EthPort   = 2U, /*!< Ethernet MAC port5(Eth4) for ENETC2 */
    kNETC_SWITCH0EthPort0 = 3U, /*!< Ethernet MAC port0(Eth0) for SWITCH */
    kNETC_SWITCH0EthPort1 = 4U, /*!< Ethernet MAC port1(Eth1) for SWITCH */
    kNETC_SWITCH0EthPort2 = 5U, /*!< Ethernet MAC port2(Eth2) for SWITCH */
} netc_hw_eth_port_idx_t;

/*!
 * @brief Enumeration for NETC timer external trigger index
 */
typedef enum _netc_timer_exttrig_index
{
    kNETC_TimerExtTrig1 = 0,
    kNETC_TimerExtTrig2,
} netc_timer_exttrig_index_t;

/*!
 * @brief Get register map resource
 *
 * @param handle  The enetc hw handle.
 * @param si      The SI object.
 */
void NETC_SocGetBaseResource(netc_enetc_hw_t *hw, netc_hw_si_idx_t si);

/*!
 * @brief Get func instance from mac port
 *
 * @param port  The enetc mac port.
 * @return uint32_t
 */
uint32_t NETC_SocGetFuncInstance(netc_hw_eth_port_idx_t port);

#endif /* _FSL_NETC_SOC_H_ */
