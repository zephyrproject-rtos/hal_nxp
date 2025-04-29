/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*==========================================================================*/
/*!
 * @addtogroup MX943_RST_driver
 * @{
 *
 * @file
 * @brief
 *
 * Header file containing the API for the MX943 Reset Driver.
 */
/*==========================================================================*/

#ifndef DRV_RST_H
#define DRV_RST_H

/* Includes */

#include "fsl_common.h"

/* Defines */

#ifndef DOXYGEN

#define RST_NUM_REASONS                 32UL

#define RST_REASON_CM33_LOCKUP          0U
#define RST_REASON_CM33_SWREQ           1U
#define RST_REASON_CM7_0_LOCKUP         2U
#define RST_REASON_CM7_0_SWREQ          3U
#define RST_REASON_FCCU                 4U
#define RST_REASON_JTAG_SW              5U
#define RST_REASON_ELE                  6U
#define RST_REASON_TEMPSENSE            7U
#define RST_REASON_WDOG1                8U
#define RST_REASON_WDOG2                9U
#define RST_REASON_WDOG3                10U
#define RST_REASON_WDOG4                11U
#define RST_REASON_WDOG5                12U
#define RST_REASON_JTAG                 13U
#define RST_REASON_WDOG6                14U
#define RST_REASON_WDOG7                15U
#define RST_REASON_WDOG8                16U
#define RST_REASON_WO_NETC              17U
#define RST_REASON_CM33_S_LOCKUP        18U
#define RST_REASON_CM33_S_SWREQ         19U
#define RST_REASON_CM7_1_LOCKUP         20U
#define RST_REASON_CM7_1_SWREQ          21U
#define RST_REASON_CM33_EXC             22U
#define RST_REASON_UNUSED0              23U
#define RST_REASON_UNUSED1              24U
#define RST_REASON_UNUSED2              25U
#define RST_REASON_UNUSED3              26U
#define RST_REASON_UNUSED4              27U
#define RST_REASON_UNUSED5              28U
#define RST_REASON_UNUSED6              29U
#define RST_REASON_UNUSED7              30U
#define RST_REASON_POR                  31U

#define RST_LINE_CTRL_DEASSERT          0U
#define RST_LINE_CTRL_ASSERT            1U
#define RST_LINE_CTRL_TOGGLE            2U
#define RST_LINE_CTRL_UNKNOWN           3U

#define RST_NUM_LINE                    58U

/* Individual resets (IRST) */
#define RST_LINE_A55C0_NCPUPORESET      0U
#define RST_LINE_A55C0_NCORERESET       1U
#define RST_LINE_A55C1_NCPUPORESET      2U
#define RST_LINE_A55C1_NCORERESET       3U
#define RST_LINE_A55C2_NCPUPORESET      4U
#define RST_LINE_A55C2_NCORERESET       5U
#define RST_LINE_A55C3_NCPUPORESET      6U
#define RST_LINE_A55C3_NCORERESET       7U
#define RST_LINE_A55P_NPRESET           8U
#define RST_LINE_A55P_NSPORESET         9U
#define RST_LINE_A55P_NSRESET           10U
#define RST_LINE_A55P_NATRESET          11U
#define RST_LINE_A55P_NGICRESET         12U
#define RST_LINE_A55P_NPERIPHRESET      13U
#define RST_LINE_DDRPHY_PRESETN         14U
#define RST_LINE_DDRPHY_RESETN          15U
#define RST_LINE_DISP0_RESETN           16U
#define RST_LINE_DISP1_RESETN           17U
#define RST_LINE_LVDS_RESETN            18U
#define RST_LINE_USB1PHY_RESETN         19U
#define RST_LINE_USB2PHY_RESETN         20U
#define RST_LINE_PCIE1PHY_RESETN        21U
#define RST_LINE_PCIE2PHY_RESETN        22U
#define RST_LINE_ENETPHY_PCS_RESETN     23U
#define RST_LINE_ECAT_IP_RESETN         24U
#define RST_LINE_V2X_RESETB             25U
#define RST_LINE_BISS_RESETN            26U
#define RST_LINE_ENDAT3_RESETN          27U
#define RST_LINE_ENDAT2_RESETN          28U
#define RST_LINE_HIPERFACE_RESETN       29U

/* Regional resets (RSTR) */      
#define RST_LINE_ANAMIX                 30U
#define RST_LINE_AONMIX_TOP             31U
#define RST_LINE_AONMIX_M33             32U
#define RST_LINE_AONMIX_ELE             33U
#define RST_LINE_BBSMMIX                34U
#define RST_LINE_M71MIX                 35U
#define RST_LINE_CCMSRCGPCMIX           36U
#define RST_LINE_CORTEXAMIX_CORE0       37U
#define RST_LINE_CORTEXAMIX_CORE1       38U
#define RST_LINE_CORTEXAMIX_CORE2       39U
#define RST_LINE_CORTEXAMIX_CORE3       40U
#define RST_LINE_CORTEXAMIX_PLATFORM    41U
#define RST_LINE_DDRMIX_TOP             42U
#define RST_LINE_DDRMIX_PHY             43U
#define RST_LINE_DISPLAYMIX             44U
#define RST_LINE_M70MIX                 45U
#define RST_LINE_HSIOMIX_TOP            46U
#define RST_LINE_HSIOMIX_WAON           47U
#define RST_LINE_NETCMIX                48U
#define RST_LINE_NETCMIX_M33            49U
#define RST_LINE_NETCMIX_WDOG_7_8       50U
#define RST_LINE_NOCMIX                 51U
#define RST_LINE_NOCMIX_WDOG_3_4        52U
#define RST_LINE_NPUMIX                 53U
#define RST_LINE_WAKEUPMIX_TOP          54U
#define RST_LINE_WAKEUPMIX_JTAG         55U
#define RST_LINE_WAKEUPMIX_WDOG_5       56U
#define RST_LINE_WAKEUPMIX_WDOG_6       57U

#define SRC_MIX_BASE_PTRS               SRC_XSPR_BASE_PTRS
#define A55_HDSK_ACK_CTRL_CNT_MODE_MASK SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE_MASK
#define A55_HDSK_ACK_CTRL_CNT_MODE_MASK SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE_MASK
#define A55_HDSK_ACK_CTRL_CNT_MODE      SRC_XSPR_A55_HDSK_ACK_CTRL_CNT_MODE
#define FUNC_STAT_PSW_STAT_MASK         SRC_XSPR_FUNC_STAT_PSW_STAT_MASK
#define FUNC_STAT_MEM_STAT_MASK         SRC_XSPR_FUNC_STAT_MEM_STAT_MASK
#define AUTHEN_CTRL_LPM_MODE_MASK       SRC_XSPR_AUTHEN_CTRL_LPM_MODE_MASK
#define AUTHEN_CTRL_WHITELIST_SHIFT     SRC_XSPR_AUTHEN_CTRL_WHITE_LIST_SHIFT
#define SLICE_SW_CTRL_PDN_SOFT_MASK     SRC_XSPR_SLICE_SW_CTRL_PDN_SOFT_MASK

#endif

/* Types */

/*! SRC power region mix slice register structure */
typedef SRC_XSPR_Type src_mix_slice_t;

/*! SRC power region memory slice register structure */
typedef SRC_MEM_Type src_mem_slice_t;

/*! SRC general register structure */
typedef SRC_GEN_Type src_generic_t;

/*! Structure for reset line details */
typedef struct
{
    uint32_t lineMask;      /*!< Reset line control mask register */
    __IO uint32_t *lineReg; /*!< Reset line control register */
    uint32_t statMask;      /*!< Reset line status mask */
    __I uint32_t *statReg;  /*!< Reset line status register */
    bool assertLow;         /*!< Assert signal (low/high) */
    uint32_t toggleUsec;    /*!< Delay during reset toggle */
} rst_line_info_t;

/* Functions */

/*!
 * Get system reset reason
 *
 * This function allows caller to get reset reason from SRESR (SRC recent event
 * status register).
 *
 * @return Returns system reset reason captured by SRES (SRC Reset Events
 *         Status) register. Defaults to reset reason as POR if SRES bits are
 *         cleared.
 */
uint32_t RST_SystemGetResetReason(void);

/*!
 * Clear system reset reason
 *
 * @param[in]       resetReason       Reset reason identifier
 *
 * This function allows caller to clear given \a resetReason in SRESR (SRC
 * recent event status register).
 */
void RST_SystemClearResetReason(uint32_t resetReason);

/*!
 * Request system reset
 *
 * This function allows caller to request system reset.
 */
void RST_SystemRequestReset(void);

/* Externs */

/*! Reset line information */
extern rst_line_info_t const g_rstLineInfo[];

#endif /* DRV_RST_H */

/** @} */

