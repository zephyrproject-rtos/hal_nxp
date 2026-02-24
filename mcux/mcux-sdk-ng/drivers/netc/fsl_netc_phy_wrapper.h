/*
 * Copyright 2023, 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_NETC_PHY_WRAPPER_H_
#define _FSL_NETC_PHY_WRAPPER_H_

#include "fsl_common.h"
#include "fsl_netc_mdio.h"

/*! @brief Functions for mapped general register address  */
#define getPhyReg(reg) ((uint16_t)(((uint32_t)(reg) >> 1U) & 0xFFFFU))
#define getPhyDev(reg) ((uint8_t)(((uint32_t)(reg) >> 17U) & 0x1FU))

/*! @brief MAC ADAPTER */
#define REG_MAC_ADAPTER_LOCK_PHY   0x200U
#define REG_MAC_ADAPTER_LOCK_MPLLA 0x204U
#define REG_MAC_ADAPTER_LOCK_MPLLB 0x208U
#define REG_MAC_ADAPTER_LOCK_ROM   0x20cU
#define REG_MAC_ADAPTER_LOCK_RAM   0x210U
#define REG_MAC_ADAPTER_LOCK_EVENT 0x214U

#define REG_MAC_ADAPTER_LOCK_LOCK_OWNER_MASK   0x000fU
#define REG_MAC_ADAPTER_LOCK_LOCK_OWNER_SHIFT  0U
#define REG_MAC_ADAPTER_LOCK_LOCK              0x0080U
#define REG_MAC_ADAPTER_LOCK_LOCK_WHOAMI_MASK  0xf000U
#define REG_MAC_ADAPTER_LOCK_LOCK_WHOAMI_SHIFT 12U

/*! @brief PMA MMD */
#define REG_PMA_RX_LSTS                                0x10040U
#define REG_PMA_RX_LSTS_RX_VALID_0                     0x1000U
#define REG_PMA_MP_12G_16G_25G_TX_GENCTRL0             0x10060U
#define REG_PMA_TX_GENCTRL0_TX_RST_0                   0x0100U
#define REG_PMA_TX_GENCTRL0_TX_DT_EN_0                 0x1000U
#define REG_PMA_MP_12G_16G_25G_TX_GENCTRL1             0x10062U
#define REG_PMA_TX_GENCTRL1_VBOOST_EN_0                0x0010U
#define REG_PMA_TX_GENCTRL1_VBOOST_LVL_MASK            0x0700U
#define REG_PMA_TX_GENCTRL1_VBOOST_LVL(x)              (((x) << 8U) & 0x0700U)
#define REG_PMA_TX_GENCTRL1_TX_CLK_RDY_0               0x1000U
#define REG_PMA_MP_12G_16G_TX_GENCTRL2                 0x10064U
#define REG_PMA_TX_GENCTRL2_TX_REQ_0                   0x0001U
#define REG_PMA_TX_GENCTRL2_TX0_WIDTH_MASK             0x0300U
#define REG_PMA_TX_GENCTRL2_TX0_WIDTH(x)               (((x) << 8U) & 0x0300U)
#define REG_PMA_MP_12G_16G_25G_TX_BOOST_CTRL           0x10066U
#define REG_PMA_TX_BOOST_CTRL_TX0_IBOOST_MASK          0x000fU
#define REG_PMA_TX_BOOST_CTRL_TX0_IBOOST(x)            ((x) & 0x000fU)
#define REG_PMA_MP_12G_16G_25G_TX_RATE_CTRL            0x10068U
#define REG_PMA_TX_RATE_CTRL_TX0_RATE_MASK             0x0007U
#define REG_PMA_TX_RATE_CTRL_TX0_RATE(x)               ((x) & 0x0007U)
#define REG_PMA_MP_12G_16G_25G_TX_POWER_STATE_CTRL     0x1006AU
#define REG_PMA_POWER_STATE_CTRL_TX0_PSTATE_MASK       0x0003U
#define REG_PMA_POWER_STATE_CTRL_TX0_PSTATE(x)         ((x) & 0x0003U)
#define REG_PMA_POWER_STATE_CTRL_TX_DISABLE_0          0x0100U
#define REG_PMA_MP_12G_16G_25G_TX_EQ_CTRL0             0x1006CU
#define REG_PMA_TX_EQ_CTRL0_TX_EQ_PRE_MASK             0x003fU
#define REG_PMA_TX_EQ_CTRL0_TX_EQ_PRE(x)               ((x) & 0x003fU)
#define REG_PMA_TX_EQ_CTRL0_TX_EQ_MAIN_MASK            0x3f00U
#define REG_PMA_TX_EQ_CTRL0_TX_EQ_MAIN(x)              (((x) << 8U) & 0x3f00U)
#define REG_PMA_MP_12G_16G_25G_TX_EQ_CTRL1             0x1006EU
#define REG_PMA_TX_EQ_CTRL1_TX_EQ_POST_MASK            0x003fU
#define REG_PMA_TX_EQ_CTRL1_TX_EQ_POST(x)              ((x) & 0x003fU)
#define REG_PMA_MP_16G_25G_TX_MISC_CTRL0               0x1007CU
#define REG_PMA_TX_MISC_CTRL0_TX0_MISC_MASK            0x00ffU
#define REG_PMA_TX_MISC_CTRL0_TX0_MISC(x)              ((x) & 0x00ffU)
#define REG_PMA_MP_12G_16G_25G_TX_STS                  0x10080U
#define REG_PMA_TX_STS_TX_ACK_0                        0x0001U
#define REG_PMA_MP_12G_16G_25G_RX_GENCTRL0             0x100A0U
#define REG_PMA_RX_GENCTRL0_RX_DT_EN_0                 0x0100U
#define REG_PMA_MP_12G_16G_25G_RX_GENCTRL1             0x100A2U
#define REG_PMA_RX_GENCTRL1_RX_RST_0                   0x0010U
#define REG_PMA_RX_GENCTRL1_RX_TERM_ACDC_0             0x0100U
#define REG_PMA_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0        0x1000U
#define REG_PMA_MP_12G_16G_RX_GENCTRL2                 0x100A4U
#define REG_PMA_RX_GENCTRL2_RX_REQ_0                   0x0001U
#define REG_PMA_RX_GENCTRL2_RX0_WIDTH_MASK             0x0300U
#define REG_PMA_RX_GENCTRL2_RX0_WIDTH(x)               (((x) << 8U) & 0x0300U)
#define REG_PMA_MP_12G_16G_RX_GENCTRL3                 0x100A6U
#define REG_PMA_RX_GENCTRL3_LOS_TRSHLD_0_MASK          0x0007U
#define REG_PMA_RX_GENCTRL3_LOS_TRSHLD_0(x)            ((x) & 0x0007U)
#define REG_PMA_RX_GENCTRL3_LOS_LFPS_EN_0              0x1000U
#define REG_PMA_MP_12G_16G_25G_RX_RATE_CTRL            0x100A8U
#define REG_PMA_RX_RATE_CTRL_RX0_RATE_MASK             0x0003U
#define REG_PMA_RX_RATE_CTRL_RX0_RATE(x)               ((x) & 0x0003U)
#define REG_PMA_MP_12G_16G_25G_RX_POWER_STATE_CTRL     0x100AAU
#define REG_PMA_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK    0x0003U
#define REG_PMA_RX_POWER_STATE_CTRL_RX0_PSTATE(x)      ((x) & 0x0003U)
#define REG_PMA_RX_POWER_STATE_CTRL_RX_DISABLE_0       0x0100U
#define REG_PMA_MP_12G_16G_25G_RX_CDR_CTRL             0x100ACU
#define REG_PMA_RX_CDR_CTRL_CDR_SSC_EN_0               0x0010U
#define REG_PMA_RX_CDR_CTRL_VCO_LOW_FREQ_0             0x0100U
#define REG_PMA_MP_12G_16G_25G_RX_ATTN_CTRL            0x100AEU
#define REG_PMA_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK       0x0007U
#define REG_PMA_RX_ATTN_CTRL_RX0_EQ_ATT_LVL(x)         ((x) & 0x0007U)
#define REG_PMA_MP_16G_25G_RX_EQ_CTRL0                 0x100B0U
#define REG_PMA_RX_EQ_CTRL0_CTLE_BOOST_0_MASK          0x001fU
#define REG_PMA_RX_EQ_CTRL0_CTLE_BOOST_0(x)            ((x) & 0x001fU)
#define REG_PMA_RX_EQ_CTRL0_CTLE_POLE_0_MASK           0x0060U
#define REG_PMA_RX_EQ_CTRL0_CTLE_POLE_0(x)             (((x) << 5U) & 0x0060U)
#define REG_PMA_RX_EQ_CTRL0_VGA2_GAIN_0_MASK           0x0700U
#define REG_PMA_RX_EQ_CTRL0_VGA2_GAIN_0(x)             (((x) << 8U) & 0x0700U)
#define REG_PMA_RX_EQ_CTRL0_VGA1_GAIN_0_MASK           0x7000U
#define REG_PMA_RX_EQ_CTRL0_VGA1_GAIN_0(x)             (((x) << 12U) & 0x7000U)
#define REG_PMA_MP_12G_16G_25G_RX_EQ_CTRL4             0x100B8U
#define REG_PMA_RX_EQ_CTRL4_CONT_ADAPT_0               0x0001U
#define REG_PMA_RX_EQ_CTRL4_RX_AD_REQ                  0x1000U
#define REG_PMA_MP_16G_25G_RX_EQ_CTRL5                 0x100BAU
#define REG_PMA_RX_EQ_CTRL5_RX_ADPT_SEL_0              0x0001U
#define REG_PMA_RX_EQ_CTRL5_RX0_ADPT_MODE_MASK         0x0030U
#define REG_PMA_RX_EQ_CTRL5_RX0_ADPT_MODE(x)           (((x) << 4U) & 0x0030U)
#define REG_PMA_MP_12G_AFE_DFE_EN_CTRL                 0x100BAU
#define REG_PMA_AFE_DFE_EN_CTRL_AFE_EN_0               0x0001U
#define REG_PMA_AFE_DFE_EN_CTRL_DFE_EN_0               0x0010U
#define REG_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0           0x100BCU
#define REG_PMA_DFE_TAP_CTRL0_DFE_TAP1_0_MASK          0x00ffU
#define REG_PMA_DFE_TAP_CTRL0_DFE_TAP1_0(x)            ((x) & 0x00ffU)
#define REG_PMA_MP_12G_16G_25G_RX_STS                  0x100C0U
#define REG_PMA_RX_STS_RX_ACK_0                        0x0001U
#define REG_PMA_MP_16G_RX_CDR_CTRL1                    0x100C8U
#define REG_PMA_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0        0x0001U
#define REG_PMA_RX_CDR_CTRL1_VCO_STEP_CTRL_0           0x0010U
#define REG_PMA_RX_CDR_CTRL1_VCO_FRQBAND_0_MASK        0x0300U
#define REG_PMA_RX_CDR_CTRL1_VCO_FRQBAND_0(x)          (((x) << 8U) & 0x0300U)
#define REG_PMA_MP_16G_25G_RX_PPM_CTRL0                0x100CAU
#define REG_PMA_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_MASK      0x001fU
#define REG_PMA_RX_PPM_CTRL0_RX0_CDR_PPM_MAX(x)        ((x) & 0x001fU)
#define REG_PMA_MP_16G_25G_RX_GENCTRL4                 0x100D0U
#define REG_PMA_RX_GENCTRL4_RX_DFE_BYP_0               0x0100U
#define REG_PMA_MP_16G_25G_RX_MISC_CTRL0               0x100D2U
#define REG_PMA_RX_MISC_CTRL0_RX0_MISC_MASK            0x00ffU
#define REG_PMA_RX_MISC_CTRL0_RX0_MISC(x)              ((x) & 0x00ffU)
#define REG_PMA_MP_16G_25G_RX_IQ_CTRL0                 0x100D6U
#define REG_PMA_RX_IQ_CTRL0_RX0_MARGIN_IQ_MASK         0x007fU
#define REG_PMA_RX_IQ_CTRL0_RX0_MARGIN_IQ(x)           ((x) & 0x007fU)
#define REG_PMA_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK          0x0f00U
#define REG_PMA_RX_IQ_CTRL0_RX0_DELTA_IQ(x)            (((x) << 8U) & 0x0f00U)
#define REG_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL           0x100E0U
#define REG_PMA_MPLL_CMN_CTRL_MPLL_EN_0                0x0001U
#define REG_PMA_MPLL_CMN_CTRL_MPLLB_SEL_0              0x0010U
#define REG_PMA_MP_12G_16G_MPLLA_CTRL0                 0x100E2U
#define REG_PMA_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK      0x00ffU
#define REG_PMA_MPLLA_CTRL0_MPLLA_MULTIPLIER(x)        ((x) & 0x00ffU)
#define REG_PMA_MPLLA_CTRL0_MPLLA_CAL_DISABLE          0x8000U
#define REG_PMA_MP_16G_MPLLA_CTRL1                     0x100E4U
#define REG_PMA_MPLLA_CTRL1_MPLLA_SSC_EN               0x0001U
#define REG_PMA_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL          0x0010U
#define REG_PMA_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK      0xffe0U
#define REG_PMA_MPLLA_CTRL1_MPLLA_FRACN_CTRL(x)        (((x) << 5U) & 0xffe0U)
#define REG_PMA_MP_12G_16G_MPLLA_CTRL2                 0x100E6U
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK        0x007fU
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV_MULT(x)          ((x) & 0x007fU)
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV_CLK_EN           0x0080U
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN          0x0100U
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN         0x0200U
#define REG_PMA_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN       0x0400U
#define REG_PMA_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK      0x1800U
#define REG_PMA_MPLLA_CTRL2_MPLLA_TX_CLK_DIV(x)        (((x) << 11U) & 0x1800U)
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV_MULT_MASK     0x00ffU
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV_MULT(x)       ((x) & 0x00ffU)
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV8_CLK_EN       0x0100U
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV10_CLK_EN      0x0200U
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV_CLK_EN        0x0400U
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_TX_CLK_DIV_MASK   0x3800U
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_TX_CLK_DIV(x)     (((x) << 11U) & 0x3800U)
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_DIV16P5_CLK_EN    0x4000U
#define REG_PMA_MPLLA_CTRL2_V2_MPLLA_WRD_DIV2_EN       0x8000U
#define REG_PMA_MP_12G_16G_MPLLB_CTRL0                 0x100E8U
#define REG_PMA_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK      0x00ffU
#define REG_PMA_MPLLB_CTRL0_MPLLB_MULTIPLIER(x)        ((x) & 0x00ffU)
#define REG_PMA_MPLLB_CTRL0_MPLLB_CAL_DISABLE          0x8000U
#define REG_PMA_MP_12G_16G_MPLLB_CTRL1                 0x100EAU
#define REG_PMA_MPLLB_CTRL1_MPLLB_SSC_EN               0x0001U
#define REG_PMA_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL          0x0010U
#define REG_PMA_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK      0xffe0U
#define REG_PMA_MPLLB_CTRL1_MPLLB_FRACN_CTRL(x)        (((x) << 5U) & 0xffe0U)
#define REG_PMA_MP_12G_16G_MPLLB_CTRL2                 0x100ECU
#define REG_PMA_MPLLB_CTRL2_MPLLB_DIV_MULT_MASK        0x007fU
#define REG_PMA_MPLLB_CTRL2_MPLLB_DIV_MULT(x)          ((x) & 0x007fU)
#define REG_PMA_MPLLB_CTRL2_MPLLB_DIV_CLK_EN           0x0080U
#define REG_PMA_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN          0x0100U
#define REG_PMA_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN         0x0200U
#define REG_PMA_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_MASK      0x1800U
#define REG_PMA_MPLLB_CTRL2_MPLLB_TX_CLK_DIV(x)        (((x) << 11U) & 0x1800U)
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV_MULT_MASK     0x00ffU
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV_MULT(x)       ((x) & 0x00ffU)
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV8_CLK_EN       0x0100U
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV10_CLK_EN      0x0200U
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_DIV_CLK_EN        0x0400U
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_TX_CLK_DIV_MASK   0x3800U
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_TX_CLK_DIV(x)     (((x) << 11U) & 0x3800U)
#define REG_PMA_MPLLB_CTRL2_V2_MPLLB_WRD_DIV2_EN       0x8000U
#define REG_PMA_MP_16G_MPLLA_CTRL3                     0x100EEU
#define REG_PMA_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK       0xffffU
#define REG_PMA_MPLLA_CTRL3_MPLLA_BANDWIDTH(x)         ((x) & 0xffffU)
#define REG_PMA_MP_16G_MPLLB_CTRL3                     0x100F0U
#define REG_PMA_MPLL_CTRL3_MPLLB_BANDWIDTH_MASK        0xffffU
#define REG_PMA_MPLL_CTRL3_MPLLB_BANDWIDTH(x)          ((x) & 0xffffU)
#define REG_PMA_MP_16G_MPLLA_CTRL4                     0x100F2U
#define REG_PMA_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_MASK 0x0fffU
#define REG_PMA_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT(x)   ((x) & 0x0fffU)
#define REG_PMA_MP_16G_MPLLA_CTRL5                     0x100F4U
#define REG_PMA_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_MASK  0x00ffU
#define REG_PMA_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK(x)    ((x) & 0x00ffU)
#define REG_PMA_MPLLA_CTRL5_MPLLA_SSC_SPD_EN           0x0100U
#define REG_PMA_MP_16G_MPLLB_CTRL4                     0x100F6U
#define REG_PMA_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT_MASK 0x0fffU
#define REG_PMA_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT(x)   ((x) & 0x0fffU)
#define REG_PMA_MP_16G_MPLLB_CTRL5                     0x100F8U
#define REG_PMA_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK_MASK  0x00ffU
#define REG_PMA_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK(x)    ((x) & 0x00ffU)
#define REG_PMA_MPLLB_CTRL5_MPLLB_SSC_SPD_EN           0x0100U
#define REG_PMA_MP_12G_16G_25G_MISC_CTRL0              0x10120U
#define REG_PMA_MISC_CTRL0_RX_VREF_CTRL_MASK           0x1f00U
#define REG_PMA_MISC_CTRL0_RX_VREF_CTRL(x)             (((x) << 8U) & 0x1f00U)
#define REG_PMA_MP_12G_16G_25G_REF_CLK_CTRL            0x10122U
#define REG_PMA_REF_CLK_CTRL_REF_USE_PAD               0x0002U
#define REG_PMA_REF_CLK_CTRL_REF_CLK_DIV2              0x0004U
#define REG_PMA_REF_CLK_CTRL_REF_RANGE_MASK            0x0038U
#define REG_PMA_REF_CLK_CTRL_REF_RANGE(x)              (((x) << 3U) & 0x0038U)
#define REG_PMA_REF_CLK_CTRL_REF_MPLLA_DIV2            0x0040U
#define REG_PMA_REF_CLK_CTRL_REF_MPLLB_DIV2            0x0080U
#define REG_PMA_MP_12G_16G_25G_VCO_CAL_LD0             0x10124U
#define REG_PMA_VCO_CAL_LD0_VCO_LD_VAL_0_MASK          0x1fffU
#define REG_PMA_VCO_CAL_LD0_VCO_LD_VAL_0(x)            ((x) & 0x1fffU)
#define REG_PMA_MP_16G_25G_VCO_CAL_REF0                0x1012CU
#define REG_PMA_VCO_CAL_REF0_VCO_REF_LD_0_MASK         0x007fU
#define REG_PMA_VCO_CAL_REF0_VCO_REF_LD_0(x)           ((x) & 0x007fU)
#define REG_PMA_VCO_CAL_REF0_V2_VCO_REF_LD_0_MASK      0x003fU
#define REG_PMA_VCO_CAL_REF0_V2_VCO_REF_LD_0(x)        ((x) & 0x003fU)
#define REG_PMA_MP_12G_16G_25G_MISC_STS                0x10130U
#define REG_PMA_MISC_STS_RX_ADPT_ACK                   0x1000U
#define REG_PMA_MP_12G_16G_25G_SRAM                    0x10136U
#define REG_PMA_SRAM_INIT_DN                           0x0001U
#define REG_PMA_SRAM_EXT_LD_DN                         0x0002U
#define REG_PMA_MP_16G_25G_MISC_CTRL2                  0x10138U
#define REG_PMA_MISC_CTRL2_SUP_MISC_MASK               0x00ffU
#define REG_PMA_MISC_CTRL2_SUP_MISC(x)                 ((x) & 0x00ffU)

/*! @brief XS PCS MMD */
#define REG_PCS_CTRL1                      0x0U
#define REG_PCS_CTRL1_RESET                0x8000U
#define REG_PCS_CTRL2                      0xEU
#define REG_PCS_CTRL2_PCS_TYPE_SEL_MASK    0x000fU
#define REG_PCS_CTRL2_PCS_TYPE_SEL(x)      ((x) & 0x000fU)
#define REG_PCS_DIG_CTRL1                  0x10000U
#define REG_PCS_DIG_CTRL1_EN_2_5G_MODE     0x0004U
#define REG_PCS_DIG_CTRL1_USXG_EN          0x0200U
#define REG_PCS_DIG_CTRL1_USRA_RST         0x0400U
#define REG_PCS_DIG_CTRL1_VR_RST           0x8000U
#define REG_PCS_XAUI_CTRL                  0x10008U
#define REG_PCS_XAUI_CTRL_XAUI_MODE        0x0001U
#define REG_PCS_DEBUG_CTRL                 0x1000AU
#define REG_PCS_DEBUG_CTRL_SUPRESS_LOS_DET 0x0010U
#define REG_PCS_DEBUG_CTRL_RX_DT_EN_CTL    0x0040U
#define REG_PCS_DEBUG_CTRL_TX_PMBL_CTL     0x0100U
#define REG_PCS_KR_CTRL1                   0x1000EU
#define REG_PCS_KR_CTRL1_USXG_MODE_MASK    0x1c00U
#define REG_PCS_KR_CTRL1_USXG_MODE(x)      (((x) << 10U) & 0x1c00U)

/*! @brief VS MII MMD */
#define REG_MII_CTRL                                0x0U
#define REG_MII_CTRL_SS5                            0x0020U
#define REG_MII_CTRL_SS6                            0x0040U
#define REG_MII_CTRL_AN_ENABLE                      0x1000U
#define REG_MII_CTRL_SS13                           0x2000U
#define REG_MII_CTRL_RST                            0x8000U
#define REG_MII_STS                                 0x2U
#define REG_MII_STS_LINK_STS                        0x0004U
#define REG_MII_DIG_CTRL1                           0x10000U
#define REG_MII_DIG_CTRL1_EN_2_5G_MODE              0x0004U
#define REG_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE         0x0008U
#define REG_MII_DIG_CTRL1_VR_RST                    0x8000U
#define REG_MII_AN_CTRL                             0x10002U
#define REG_MII_AN_CTRL_MII_AN_INTR_EN              0x0001U
#define REG_MII_AN_CTRL_TX_CONFIG                   0x0008U
#define REG_MII_AN_INTR_STS                         0x10004U
#define REG_MII_AN_INTR_STS_CL37_ANCMPLT_INTR       0x0001U
#define REG_MII_LINK_TIMER_CTRL                     0x10014U
#define REG_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK 0xffffU
#define REG_MII_LINK_TIMER_CTRL_CL37_LINK_TIME(x)   ((x) & 0xffffU)

/*! @brief E16 MEM MAP */
#define REG_IDCODE_LO                                      0x0U
#define REG_IDCODE_HI                                      0x4U
#define REG_GLOBAL_CTRL_EX_0                               0x114U
#define REG_GLOBAL_CTRL_EX_0_PHY_SRAM_BYPASS               0x0001U
#define REG_GLOBAL_CTRL_EX_0_XPCS0_SEL                     0x0010U
#define REG_GLOBAL_CTRL_EX_0_XPCS1_SEL                     0x0020U
#define REG_GLOBAL_CTRL_EX_0_MPLLA_SEL                     0x0040U
#define REG_GLOBAL_CTRL_EX_0_MPLLB_SEL                     0x0080U
#define REG_GLOBAL_CTRL_EX_0_PHY_SUP_MISC_MASK             0xff00U
#define REG_GLOBAL_CTRL_EX_0_PHY_SUP_MISC(x)               (((x) << 8U) & 0xff00U)
#define REG_GLOBAL_CTRL_EX_4                               0x124U
#define REG_GLOBAL_CTRL_EX_4_PHY_PCS_PWR_STABLE            0x0100U
#define REG_GLOBAL_CTRL_EX_4_PHY_PMA_PWR_STABLE            0x4000U
#define REG_MPLLA_CTRL_EX_0                                0xacU
#define REG_MPLLA_CTRL_EX_0_MPLLA_CFG_DRIVER_MASK          0x0f00U
#define REG_MPLLA_CTRL_EX_0_MPLLA_CFG_DRIVER_SHIFT         (8U)
#define REG_MPLLA_CTRL_EX_0_MPLLA_CFG_DRIVER               (((x) << 8U) & 0x0f00U)
#define REG_MPLLB_CTRL_EX_0                                0xacU
#define REG_MPLLB_CTRL_EX_0_MPLLB_CFG_DRIVER_MASK          0x0f00U
#define REG_MPLLB_CTRL_EX_0_MPLLB_CFG_DRIVER_SHIFT         (8U)
#define REG_MPLLB_CTRL_EX_0_MPLLB_CFG_DRIVER               (((x) << 8U) & 0x0f00U)
#define REG_L0_RX_VCO_OVRD_OUT_0                           0x20cU
#define REG_L0_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_MASK 0x1ff8U
#define REG_L0_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE(x)   (((x) << 3U) & 0x1ff8U)
#define REG_L0_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN  0x8000U
#define REG_L0_RX_VCO_OVRD_OUT_2                           0x214U
#define REG_L0_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK  0x0001U

/*!
 * @brief ENET_PHY modes supported
 */
typedef enum _phy_mode
{
    kNETC_SGMII1G = 0U,
    kNETC_SGMII2G5,
#if !(defined(FSL_FEATURE_NETC_HAS_NO_XGMII) && FSL_FEATURE_NETC_HAS_NO_XGMII)
    kNETC_XGMII10GAuto,
    kNETC_XGMII10G,
#endif
    kNETC_XFI,
} phy_mode_t;

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief ENET_PHY mode init
 *
 * @param handle  mdio handle.
 * @param mode  phy mode.
 * @return status_t
 */
status_t NETC_PHYInit(netc_mdio_handle_t *handle, phy_mode_t mode);

/*!
 * @brief NETC PHY WRAPPER read register
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param devAddr  device address.
 * @param regAddr  register offset.
 * @param val  read value.
 * @return status_t
 */
status_t NETC_PHYRead(netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t *val);

/*!
 * @brief NETC PHY WRAPPER write register
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param devAddr  device address.
 * @param regAddr  register offset.
 * @param val  value to write.
 * @return status_t
 */
status_t NETC_PHYWrite(netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t val);

/*!
 * @brief NETC PHY WRAPPER write register bits
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param devAddr  device address.
 * @param regAddr  register offset.
 * @param mask  mask to write.
 * @param val  val to write.
 * @return status_t
 */
status_t NETC_PHYWriteBits(
    netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t mask, uint16_t val);

/*!
 * @brief NETC PHY WRAPPER poll register bit
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param devAddr  device address.
 * @param regAddr  register offset.
 * @param mask  mask to poll.
 * @param is_set  poll set or not.
 * @return status_t
 */
status_t NETC_PHYPollBit(
    netc_mdio_handle_t *handle, bool pcs, uint8_t devAddr, uint32_t regAddr, uint16_t mask, uint16_t is_set);

/*!
 * @brief NETC PHY WRAPPER write register bits (based on mapped general register address)
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param reg  register address.
 * @param mask mask to write.
 * @param val  value to write.
 * @return status_t
 */
status_t NETC_PHYWriteRegBits(
    netc_mdio_handle_t *handle, bool pcs, volatile uint16_t *reg, uint16_t mask, uint16_t val);

/*!
 * @brief NETC PHY WRAPPER read register (based on mapped general register address)
 *
 * @param handle  mdio handle.
 * @param pcs  pcs.
 * @param reg  register address.
 * @param val  read value.
 * @return status_t
 */
status_t NETC_PHYReadReg(netc_mdio_handle_t *handle, bool pcs, const volatile uint16_t *reg, uint16_t *val);
#if defined(__cplusplus)
}
#endif
#endif /* _FSL_NETC_PHY_WRAPPER_H_ */
