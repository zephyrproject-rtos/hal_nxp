/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef FSL_NETC_SOC_H_
#define FSL_NETC_SOC_H_

#include "netc_hw/fsl_netc_hw.h"
#include "netc_hw/fsl_netc_hw_enetc.h"
#include "netc_hw/fsl_netc_hw_si.h"

/*
 * i.MX937 NETC timer (ENETC_PF_TMR_Type) uses ALL_REG_ARRAYS[0].xxx layout.
 * The common NETC driver (fsl_netc_timer.c, etc.) expects flat members.
 * Provide compatibility macros mapping flat names to ALL_REG_ARRAYS[0].
 */
#define TMR_PCI_HDR_TYPE0   TMR0_PCI_HDR_TYPE0
#define EMDIO_PCI_HDR_TYPE0 EMDIO0_PCI_HDR_TYPE0

#define TMR_ID           ALL_REG_ARRAYS[0].TMR_ID
#define TMR_CAPR         ALL_REG_ARRAYS[0].TMR_CAPR
#define TMR_FRT_L        ALL_REG_ARRAYS[0].TMR_FRT_L
#define TMR_FRT_H        ALL_REG_ARRAYS[0].TMR_FRT_H
#define TMR_SRT_L        ALL_REG_ARRAYS[0].TMR_SRT_L
#define TMR_SRT_H        ALL_REG_ARRAYS[0].TMR_SRT_H
#define TMR_DEF_CNT_L    ALL_REG_ARRAYS[0].TMR_DEF_CNT_L
#define TMR_DEF_CNT_H    ALL_REG_ARRAYS[0].TMR_DEF_CNT_H
#define TMR_CTRL         ALL_REG_ARRAYS[0].TMR_CTRL
#define TMR_TEVENT       ALL_REG_ARRAYS[0].TMR_TEVENT
#define TMR_TEMASK       ALL_REG_ARRAYS[0].TMR_TEMASK
#define TMR_MSIVEC       ALL_REG_ARRAYS[0].TMR_MSIVEC
#define TMR_STAT         ALL_REG_ARRAYS[0].TMR_STAT
#define TMR_CNT_L        ALL_REG_ARRAYS[0].TMR_CNT_L
#define TMR_CNT_H        ALL_REG_ARRAYS[0].TMR_CNT_H
#define TMR_ADD          ALL_REG_ARRAYS[0].TMR_ADD
#define TMR_ACC          ALL_REG_ARRAYS[0].TMR_ACC
#define TMR_PRSC         ALL_REG_ARRAYS[0].TMR_PRSC
#define TMR_ECTRL        ALL_REG_ARRAYS[0].TMR_ECTRL
#define TMROFF_L         ALL_REG_ARRAYS[0].TMROFF_L
#define TMROFF_H         ALL_REG_ARRAYS[0].TMROFF_H
#define TMR_ALARMM       ALL_REG_ARRAYS[0].TMR_ALARMM
#define TMR_ALARM_CTRL   ALL_REG_ARRAYS[0].TMR_ALARM_CTRL
#define TMR_FIPER        ALL_REG_ARRAYS[0].TMR_FIPER
#define TMR_FIPER_CTRL   ALL_REG_ARRAYS[0].TMR_FIPER_CTRL
#define TMR_ETTSN        ALL_REG_ARRAYS[0].TMR_ETTSN
#define TMR_CUR_TIME_L   ALL_REG_ARRAYS[0].TMR_CUR_TIME_L
#define TMR_CUR_TIME_H   ALL_REG_ARRAYS[0].TMR_CUR_TIME_H
#define TMR_PARAM        ALL_REG_ARRAYS[0].TMR_PARAM

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

/* i.MX937 has 2 external trigger stamp FIFOs */
typedef enum _netc_timer_exttrig_index
{
    kNETC_TimerExtTrig1 = 0,
    kNETC_TimerExtTrig2,
} netc_timer_exttrig_index_t;

typedef enum _netc_timer_ref_clk
{
    kNETC_TimerEnetTimer1_Clk = 0,
    kNETC_TimerSystemClk,
    kNETC_TimerExtRefClk,
} netc_timer_ref_clk_t;

#if defined(__cplusplus)
extern "C" {
#endif

void NETC_SocGetBaseResource(netc_enetc_hw_t *hw, netc_hw_si_idx_t si);
uint32_t NETC_SocGetFuncInstance(netc_hw_eth_port_idx_t port);
status_t NETC_SocPreInitVsi(netc_enetc_hw_t *hw, netc_hw_si_idx_t si);

#if defined(__cplusplus)
}
#endif

#endif /* FSL_NETC_SOC_H_ */
