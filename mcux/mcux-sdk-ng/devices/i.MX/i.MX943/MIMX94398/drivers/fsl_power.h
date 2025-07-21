/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_POWER_H
#define FSL_POWER_H

/*!
 * @addtogroup PWR_driver
 * @{
 */

/*! @file */

/* Includes */
#include "fsl_common.h"

#if CONFIG_DIRECT
/* Defines */
#define PWR_NUM_MIX_SLICE               19U

#define PWR_MIX_SLICE_IDX_ANA           0U
#define PWR_MIX_SLICE_IDX_AON           1U
#define PWR_MIX_SLICE_IDX_BBSM          2U
#define PWR_MIX_SLICE_IDX_M7_1          3U
#define PWR_MIX_SLICE_IDX_CCMSRCGPC     4U
#define PWR_MIX_SLICE_IDX_A55C0         5U
#define PWR_MIX_SLICE_IDX_A55C1         6U
#define PWR_MIX_SLICE_IDX_A55C2         7U
#define PWR_MIX_SLICE_IDX_A55C3         8U
#define PWR_MIX_SLICE_IDX_A55P          9U
#define PWR_MIX_SLICE_IDX_DDR           10U
#define PWR_MIX_SLICE_IDX_DISPLAY       11U
#define PWR_MIX_SLICE_IDX_M7_0          12U
#define PWR_MIX_SLICE_IDX_HSIO_TOP      13U
#define PWR_MIX_SLICE_IDX_HSIO_WAON     14U
#define PWR_MIX_SLICE_IDX_NETC          15U
#define PWR_MIX_SLICE_IDX_NOC           16U
#define PWR_MIX_SLICE_IDX_NPU           17U
#define PWR_MIX_SLICE_IDX_WAKEUP        18U

#define PWR_MEM_SLICE_IDX_AON           0U
#define PWR_MEM_SLICE_IDX_M7_1          1U
#define PWR_MEM_SLICE_IDX_A55C0         2U
#define PWR_MEM_SLICE_IDX_A55C1         3U
#define PWR_MEM_SLICE_IDX_A55C2         4U
#define PWR_MEM_SLICE_IDX_A55C3         5U
#define PWR_MEM_SLICE_IDX_A55P          6U
#define PWR_MEM_SLICE_IDX_A55L3         7U
#define PWR_MEM_SLICE_IDX_DDR           8U
#define PWR_MEM_SLICE_IDX_DISPLAY       9U
#define PWR_MEM_SLICE_IDX_M7_0          10U
#define PWR_MEM_SLICE_IDX_HSIO          11U
#define PWR_MEM_SLICE_IDX_NETC          12U
#define PWR_MEM_SLICE_IDX_NOC1          13U
#define PWR_MEM_SLICE_IDX_NOC2          14U
#define PWR_MEM_SLICE_IDX_NPU           15U
#define PWR_MEM_SLICE_IDX_WAKEUP        16U

#define PWR_MIX_SLICE_IDX_A55C_LAST     PWR_MIX_SLICE_IDX_A55C3

#define PWR_MIX_PSW_STAT_MASK           SRC_XSPR_FUNC_STAT_PSW_STAT_MASK
#define PWR_MIX_PSW_STAT_PUP            SRC_XSPR_FUNC_STAT_PSW_STAT(0U)
#define PWR_MIX_PSW_STAT_PDN            SRC_XSPR_FUNC_STAT_PSW_STAT(1U)

#define PWR_MIX_FUNC_STAT_MASK                  \
    (SRC_XSPR_FUNC_STAT_SYSMAN_STAT_MASK |      \
     SRC_XSPR_FUNC_STAT_MEM_STAT_MASK |         \
     SRC_XSPR_FUNC_STAT_A55_HDSK_STAT_MASK |    \
     SRC_XSPR_FUNC_STAT_SSAR_STAT_MASK |        \
     SRC_XSPR_FUNC_STAT_ISO_STAT_MASK |         \
     SRC_XSPR_FUNC_STAT_RST_STAT_MASK |         \
     SRC_XSPR_FUNC_STAT_PSW_STAT_MASK)

#define PWR_MIX_FUNC_STAT_PUP                   \
    (SRC_XSPR_FUNC_STAT_SYSMAN_STAT(0U) |       \
     SRC_XSPR_FUNC_STAT_MEM_STAT(0U) |          \
     SRC_XSPR_FUNC_STAT_A55_HDSK_STAT(0U) |     \
     SRC_XSPR_FUNC_STAT_SSAR_STAT(0U) |         \
     SRC_XSPR_FUNC_STAT_ISO_STAT(0U) |          \
     SRC_XSPR_FUNC_STAT_RST_STAT(1U) |          \
     SRC_XSPR_FUNC_STAT_PSW_STAT(0U))

#define PWR_MIX_FUNC_STAT_PDN                   \
    (SRC_XSPR_FUNC_STAT_SYSMAN_STAT(1U) |       \
     SRC_XSPR_FUNC_STAT_MEM_STAT(1U) |          \
     SRC_XSPR_FUNC_STAT_A55_HDSK_STAT(1U) |     \
     SRC_XSPR_FUNC_STAT_SSAR_STAT(1U) |         \
     SRC_XSPR_FUNC_STAT_ISO_STAT(1U) |          \
     SRC_XSPR_FUNC_STAT_RST_STAT(0U) |          \
     SRC_XSPR_FUNC_STAT_PSW_STAT(1U))

#define PWR_MIX_FLAG_SWITCHABLE         (1U << 0U)  /* MIX can be switched OFF */
#define PWR_MIX_FLAG_LPMSET             (1U << 1U)  /* MIX LPM can be set */
#define PWR_MIX_FLAG_SSI_TIMEOUT        (1U << 2U)  /* MIX supports SSI timeout */

/* Macro to convert CPU ID to GPC domain ID
 * Note:  AUTHEN_CTRL.WHITE_LIST assignments use macro
 *        to define LPM voting logic mappings.  Offset
 *        mapping to GPC domain by TRDC ID assigned to M33
 *        to avoid collisions between WHITE_LIST access control
 *        and LPM voting logic.
 */
#define CM33_TRDC_ID                2U
#define CPU2GPC(cpuId)              ((cpuId) + CM33_TRDC_ID)

#define WHITELIST_MASK(cpuId)           (1UL << (CPU2GPC(cpuId)))
#define LPMSETTING_MASK(cpuId)          (0x7ULL << ((CPU2GPC(cpuId) << 2U)))
#define LPMSETTING_DOM(cpuId, lpmVal)   (((uint64_t) lpmVal) << ((CPU2GPC(cpuId) << 2U)))
#define LPMSETTING_VAL(cpuId, lpmReg)   ((((uint64_t) lpmReg) & LPMSETTING_MASK(cpuId)) >> ((CPU2GPC(cpuId) << 2U)))

#define PWR_GPC_REQ_MIX_ID_M7_0         0U
#define PWR_GPC_REQ_MIX_ID_S500         1U
#define PWR_GPC_REQ_MIX_ID_NPU          2U
#define PWR_GPC_REQ_MIX_ID_A55          3U
#define PWR_GPC_REQ_MIX_ID_M33          4U
#define PWR_GPC_REQ_MIX_ID_AON          5U
#define PWR_GPC_REQ_MIX_ID_DDR          6U
#define PWR_GPC_REQ_MIX_ID_WAKEUP       7U
#define PWR_GPC_REQ_MIX_ID_NOC          8U
#define PWR_GPC_REQ_MIX_ID_M7_1         9U
#define PWR_GPC_REQ_MIX_ID_HSIO         10U
#define PWR_GPC_REQ_MIX_ID_M33_S        11U
#define PWR_GPC_REQ_MIX_ID_NETC         12U
#define PWR_GPC_REQ_MIX_ID_DISPLAY      13U

#define PWR_GPC_REQ_STATE_CLK_GATE      1U
#define PWR_GPC_REQ_STATE_CLK_CHANGE    2U
#define PWR_GPC_REQ_STATE_RESET         3U
#define PWR_GPC_REQ_STATE_POWER         4U
#define PWR_GPC_REQ_STATE_RETENTION     5U

#define PWR_GPC_HS_RST_AON              1U
#define PWR_GPC_HS_RST_M33P             2U
#define PWR_GPC_HS_RST_ELE              3U
#define PWR_GPC_HS_RST_M7_1             5U
#define PWR_GPC_HS_RST_A55C0            7U
#define PWR_GPC_HS_RST_A55C1            8U
#define PWR_GPC_HS_RST_A55C2            9U
#define PWR_GPC_HS_RST_A55C3            10U
#define PWR_GPC_HS_RST_A55P             11U
#define PWR_GPC_HS_RST_DDR              12U
#define PWR_GPC_HS_RST_DDRPHY           13U
#define PWR_GPC_HS_RST_DISPLAY          14U
#define PWR_GPC_HS_RST_M7_0             15U
#define PWR_GPC_HS_RST_HSIO             16U
#define PWR_GPC_HS_RST_HSIOAON          17U
#define PWR_GPC_HS_RST_NETC             18U
#define PWR_GPC_HS_RST_M33S_PLAT        19U
#define PWR_GPC_HS_RST_M33S             20U
#define PWR_GPC_HS_RST_NOC              21U
#define PWR_GPC_HS_RST_NPU              22U
#define PWR_GPC_HS_RST_WAKEUP           23U
#define PWR_GPC_HS_RST_JTAG             24U
#define PWR_GPC_HS_RST_WDOG_3_4         25U
#define PWR_GPC_HS_RST_WDOG5            26U

/* FIXME, the index should start from 30 */
#define PWR_GPC_HS_PWR_M7_1             0U
#define PWR_GPC_HS_PWR_A55C0            2U
#define PWR_GPC_HS_PWR_A55C1            3U
#define PWR_GPC_HS_PWR_A55C2            4U
#define PWR_GPC_HS_PWR_A55C3            5U
#define PWR_GPC_HS_PWR_A55P             6U
#define PWR_GPC_HS_PWR_DDR              7U
#define PWR_GPC_HS_PWR_DISPLAY          8U
#define PWR_GPC_HS_PWR_M7_0             9U
#define PWR_GPC_HS_PWR_HSIO             10U
#define PWR_GPC_HS_PWR_HSIOAON          11U
#define PWR_GPC_HS_PWR_NETC             12U
#define PWR_GPC_HS_PWR_NOC              13U
#define PWR_GPC_HS_PWR_NPU              14U
#define PWR_GPC_HS_PWR_WAKEUP           15U


/* Types */
/*!
 * Power MIX management structure
 */
typedef struct
{
    uint32_t flags;             /*!< MIX capabilities */
    uint32_t memMask;           /*!< Bitmask of MEM slice instances */
    uint32_t retainMask;        /*!< Bitmask of MEM slices always retained */
    uint32_t cpuMask;           /*!< CPU mask */
    uint32_t ipIsoMask;         /*!< ISO mask */
    uint32_t gpcReqMaskRst;     /*!< GPC reset request mask */
    uint32_t gpcReqMaskPwr;     /*!< GPC power request mask */
    uint32_t authenCtrl;        /*!< MIX authentication control */
    uint64_t lpmSetting;        /*!< MIX LPM setting */
    uint32_t ssiLpcgIdx;        /*!< SSI Q-Channel LPCG instance */
} pwrmix_mgmt_info_t;

/*!
 * Structure containing SM LP handshake details
 */
typedef struct 
{
    uint32_t srcMixIdx;     /*!< SRX MIX identifier for the active LP request */
    uint32_t req;           /*!< Active LP request */
    uint32_t stat;          /*!< Active LP request status */
} pwr_lp_hs_mode;

/* Functions */
bool PWR_Init(uint32_t srcMixIdx);
bool PWR_IsParentPowered(uint32_t srcMixIdx);
bool PWR_AnyChildPowered(uint32_t srcMixIdx);
uint32_t PWR_NumChildPowered(uint32_t srcMixIdx);
void PWR_SystemPowerDown(void);
void PWR_LpHandshakeMaskSet(uint32_t srcMixIdx, bool enableHandshake);
void PWR_EleLpHandshakeMaskSet(uint32_t srcMixIdx, bool enableHandshake);
void PWR_LpHandshakeModeGet(pwr_lp_hs_mode *lpHsMode);
void PWR_LpHandshakeAck(void);
void PWR_MixPowerSet(uint32_t srcMixIdx, bool power_on);

/* Externs */
extern pwrmix_mgmt_info_t const g_pwrMixMgmtInfo[];
#else
#define POWER_NUM_MIX_SLICE               19U

#define POWER_MIX_SLICE_IDX_ANA           0U
#define POWER_MIX_SLICE_IDX_AON           1U
#define POWER_MIX_SLICE_IDX_BBSM          2U
#define POWER_MIX_SLICE_IDX_M7_1          3U
#define POWER_MIX_SLICE_IDX_CCMSRCGPC     4U
#define POWER_MIX_SLICE_IDX_A55C0         5U
#define POWER_MIX_SLICE_IDX_A55C1         6U
#define POWER_MIX_SLICE_IDX_A55C2         7U
#define POWER_MIX_SLICE_IDX_A55C3         8U
#define POWER_MIX_SLICE_IDX_A55P          9U
#define POWER_MIX_SLICE_IDX_DDR           10U
#define POWER_MIX_SLICE_IDX_DISPLAY       11U
#define POWER_MIX_SLICE_IDX_M7_0          12U
#define POWER_MIX_SLICE_IDX_HSIO_TOP      13U
#define POWER_MIX_SLICE_IDX_HSIO_WAON     14U
#define POWER_MIX_SLICE_IDX_NETC          15U
#define POWER_MIX_SLICE_IDX_NOC           16U
#define POWER_MIX_SLICE_IDX_NPU           17U
#define POWER_MIX_SLICE_IDX_WAKEUP        18U

#define POWER_MEM_SLICE_IDX_AON           0U
#define POWER_MEM_SLICE_IDX_M7_1          1U
#define POWER_MEM_SLICE_IDX_A55C0         2U
#define POWER_MEM_SLICE_IDX_A55C1         3U
#define POWER_MEM_SLICE_IDX_A55C2         4U
#define POWER_MEM_SLICE_IDX_A55C3         5U
#define POWER_MEM_SLICE_IDX_A55P          6U
#define POWER_MEM_SLICE_IDX_A55L3         7U
#define POWER_MEM_SLICE_IDX_DDR           8U
#define POWER_MEM_SLICE_IDX_DISPLAY       9U
#define POWER_MEM_SLICE_IDX_M7_0          10U
#define POWER_MEM_SLICE_IDX_HSIO          11U
#define POWER_MEM_SLICE_IDX_NETC          12U
#define POWER_MEM_SLICE_IDX_NOC1          13U
#define POWER_MEM_SLICE_IDX_NOC2          14U
#define POWER_MEM_SLICE_IDX_NPU           15U
#define POWER_MEM_SLICE_IDX_WAKEUP        16U

#define POWER_MIX_SLICE_IDX_A55C_LAST     POWER_MIX_SLICE_IDX_A55C3

typedef struct _pwr_s
{
    uint32_t did;
    uint32_t st;
} pwr_s_t;

int32_t POWER_SetState(pwr_s_t *pwr_st);
uint32_t POWER_GetState(pwr_s_t *pwr_st);
#endif

#endif /* FSL_POWER_H */

/** @} */
