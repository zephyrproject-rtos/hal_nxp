/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_NETC_SOC_H_
#define FSL_NETC_SOC_H_

#include "netc_hw/fsl_netc_hw.h"
#include "netc_hw/fsl_netc_hw_enetc.h"
#include "netc_hw/fsl_netc_hw_si.h"

#define TMR_PCI_HDR_TYPE0   TMR0_PCI_HDR_TYPE0
#define EMDIO_PCI_HDR_TYPE0 EMDIO0_PCI_HDR_TYPE0

/*! @brief MDIO Manageable Device ID */
#define PHY_DEV_GLOBAL    0x0U
#define PHY_PCS_DEV_VEND2 0x1fU

/*! @brief Station interface index enumerator */
typedef enum _netc_hw_si_idx
{
    kNETC_ENETC0PSI0 = (0U << 8U) | (0U << 4U) | 0U, /*!< ENETC0 PSI0, index 0 */
    kNETC_ENETC1PSI0 = (1U << 8U) | (0U << 4U) | 1U, /*!< ENETC1 PSI0, index 1 */
    kNETC_ENETC0VSI0 = (0U << 8U) | (1U << 4U) | 2U, /*!< ENETC0 VSI0, index 2 */
    kNETC_ENETC1VSI0 = (1U << 8U) | (1U << 4U) | 3U, /*!< ENETC1 VSI0, index 3 */
} netc_hw_si_idx_t;

/*! @brief Ethernet MAC port resource for the NETC module */
typedef enum _netc_hw_eth_port_idx
{
    kNETC_ENETC0EthPort = 0U, /*!< Ethernet MAC port for ENETC0 */
    kNETC_ENETC1EthPort = 1U, /*!< Ethernet MAC port for ENETC1 */
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
 * @brief Enumeration for NETC timer reference clock
 */
typedef enum _netc_timer_ref_clk
{
    kNETC_TimerEnetTimer1_Clk = 0,
    kNETC_TimerSystemClk,
    kNETC_TimerExtRefClk,
} netc_timer_ref_clk_t;

#if defined(__cplusplus)
extern "C" {
#endif

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

/*!
 * @brief Preinit VSIs
 *
 * @param hw      The enetc hw handle.
 * @param si      The SI object.
 * @return status_t
 */
status_t NETC_SocPreInitVsi(netc_enetc_hw_t *hw, netc_hw_si_idx_t si);
#if defined(__cplusplus)
}
#endif
#endif /* FSL_NETC_SOC_H_ */
