/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for STCU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_STCU.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for STCU
 *
 * CMSIS Peripheral Access Layer for STCU
 */

#if !defined(PERI_STCU_H_)
#define PERI_STCU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- STCU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STCU_Peripheral_Access_Layer STCU Peripheral Access Layer
 * @{
 */

/** STCU - Size of Registers Arrays */
#define STCU_LB_COUNT                             1u
#define STCU_MB_CTRL_COUNT                        12u

/** STCU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t RUNSW;                             /**< STCU2 Run Software, offset: 0x4 */
  __O  uint32_t SKC;                               /**< STCU2 SK Code, offset: 0x8 */
  __IO uint32_t CFG;                               /**< STCU2 Configuration, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t WDG;                               /**< STCU2 Watchdog Granularity, offset: 0x14 */
       uint8_t RESERVED_2[12];
  __IO uint32_t ERR_STAT;                          /**< STCU2 Error, offset: 0x24 */
  __IO uint32_t ERR_FM;                            /**< STCU2 Error FM, offset: 0x28 */
       uint8_t RESERVED_3[32];
  __I  uint32_t LBSSW0;                            /**< STCU2 Online LBIST Status, offset: 0x4C */
       uint8_t RESERVED_4[12];
  __I  uint32_t LBESW0;                            /**< STCU2 Online LBIST End Flag, offset: 0x5C */
       uint8_t RESERVED_5[12];
  __IO uint32_t LBRMSW0;                           /**< STCU2 Online LBIST Reset Management, offset: 0x6C */
       uint8_t RESERVED_6[12];
  __IO uint32_t LBUFM0;                            /**< STCU2 Online LBIST Unrecoverable FM, offset: 0x7C */
       uint8_t RESERVED_7[140];
  __I  uint32_t MBSSW0;                            /**< STCU2 Online MBIST Status, offset: 0x10C */
       uint8_t RESERVED_8[60];
  __I  uint32_t MBESW0;                            /**< STCU2 Online MBIST End Flag, offset: 0x14C */
       uint8_t RESERVED_9[60];
  __IO uint32_t MBUFM0;                            /**< STCU2 MBIST Unrecoverable FM, offset: 0x18C */
       uint8_t RESERVED_10[112];
  struct {                                         /* offset: 0x200, array step: 0x30 */
    __IO uint32_t CTRL;                              /**< STCU2 LBIST Control, array offset: 0x200, array step: 0x30 */
    __IO uint32_t PCS;                               /**< STCU2 LBIST PC Stop, array offset: 0x204, array step: 0x30 */
         uint8_t RESERVED_0[24];
    __IO uint32_t MISRELSW;                          /**< STCU2 Online LBIST MISR Expected Low, array offset: 0x220, array step: 0x30 */
    __IO uint32_t MISREHSW;                          /**< STCU2 Online LBIST MISR Expected High, array offset: 0x224, array step: 0x30 */
    __I  uint32_t MISRRLSW;                          /**< STCU2 Online LBIST MISR Read Low, array offset: 0x228, array step: 0x30 */
    __I  uint32_t MISRRHSW;                          /**< STCU2 Online LBIST MISR Read High, array offset: 0x22C, array step: 0x30 */
  } LB[STCU_LB_COUNT];
       uint8_t RESERVED_11[8144];
  __IO uint32_t ALGOSEL;                           /**< STCU2 Algorithm Select, offset: 0x2200 */
       uint8_t RESERVED_12[8];
  __IO uint32_t STGGR;                             /**< STCU2 MBIST Stagger, offset: 0x220C */
  __IO uint32_t BSTART;                            /**< STCU2 BIST Start, offset: 0x2210 */
  __IO uint32_t MB_CTRL[STCU_MB_CTRL_COUNT];       /**< STCU2 MBIST Control, array offset: 0x2214, array step: 0x4 */
} STCU_Type;

/* ----------------------------------------------------------------------------
   -- STCU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup STCU_Register_Masks STCU Register Masks
 * @{
 */

/*! @name RUNSW - STCU2 Run Software */
/*! @{ */

#define STCU_RUNSW_RUNSW_MASK                    (0x1U)
#define STCU_RUNSW_RUNSW_SHIFT                   (0U)
/*! RUNSW
 *  0b0..Idle
 *  0b1..Online self-testing procedure is running
 */
#define STCU_RUNSW_RUNSW(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_RUNSW_SHIFT)) & STCU_RUNSW_RUNSW_MASK)

#define STCU_RUNSW_LBSWPLLEN_MASK                (0x100U)
#define STCU_RUNSW_LBSWPLLEN_SHIFT               (8U)
/*! LBSWPLLEN
 *  0b0..Online LBIST is executed without using the on-chip PLL.
 *  0b1..Online LBIST is executed using the PLL configuration provided by the software. STCU2 does not take the
 *       PLL control but monitors the PLL lock signal to check if PLL is working correctly.
 */
#define STCU_RUNSW_LBSWPLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_LBSWPLLEN_SHIFT)) & STCU_RUNSW_LBSWPLLEN_MASK)

#define STCU_RUNSW_MBSWPLLEN_MASK                (0x200U)
#define STCU_RUNSW_MBSWPLLEN_SHIFT               (9U)
/*! MBSWPLLEN
 *  0b0..Online MBIST is executed without using the on-chip PLL.
 *  0b1..Online MBIST is executed using the PLL configuration provided by software. STCU2 does not take the PLL
 *       control but monitors the PLL lock signal to check if PLL is working correctly.
 */
#define STCU_RUNSW_MBSWPLLEN(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_RUNSW_MBSWPLLEN_SHIFT)) & STCU_RUNSW_MBSWPLLEN_MASK)
/*! @} */

/*! @name SKC - STCU2 SK Code */
/*! @{ */

#define STCU_SKC_SKC_MASK                        (0xFFFFFFFFU)
#define STCU_SKC_SKC_SHIFT                       (0U)
/*! SKC - STCU2 SK Code */
#define STCU_SKC_SKC(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_SKC_SKC_SHIFT)) & STCU_SKC_SKC_MASK)
/*! @} */

/*! @name CFG - STCU2 Configuration */
/*! @{ */

#define STCU_CFG_CLK_CFG_MASK                    (0x7U)
#define STCU_CFG_CLK_CFG_SHIFT                   (0U)
/*! CLK_CFG
 *  0b000..sys_clk/1
 *  0b001..sys_clk/2
 *  0b010..sys_clk/3
 *  0b011..sys_clk/4
 *  0b100..sys_clk/5
 *  0b101..sys_clk/6
 *  0b110..sys_clk/7
 *  0b111..sys_clk/8
 */
#define STCU_CFG_CLK_CFG(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_CFG_CLK_CFG_SHIFT)) & STCU_CFG_CLK_CFG_MASK)

#define STCU_CFG_WRP_MASK                        (0x100U)
#define STCU_CFG_WRP_SHIFT                       (8U)
#define STCU_CFG_WRP(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_CFG_WRP_SHIFT)) & STCU_CFG_WRP_MASK)

#define STCU_CFG_LB_DELAY_MASK                   (0x1FE000U)
#define STCU_CFG_LB_DELAY_SHIFT                  (13U)
#define STCU_CFG_LB_DELAY(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_CFG_LB_DELAY_SHIFT)) & STCU_CFG_LB_DELAY_MASK)

#define STCU_CFG_PTR_MASK                        (0x7FE00000U)
#define STCU_CFG_PTR_SHIFT                       (21U)
#define STCU_CFG_PTR(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_CFG_PTR_SHIFT)) & STCU_CFG_PTR_MASK)
/*! @} */

/*! @name WDG - STCU2 Watchdog Granularity */
/*! @{ */

#define STCU_WDG_WDGEOC_MASK                     (0xFFFFFFFFU)
#define STCU_WDG_WDGEOC_SHIFT                    (0U)
#define STCU_WDG_WDGEOC(x)                       (((uint32_t)(((uint32_t)(x)) << STCU_WDG_WDGEOC_SHIFT)) & STCU_WDG_WDGEOC_MASK)
/*! @} */

/*! @name ERR_STAT - STCU2 Error */
/*! @{ */

#define STCU_ERR_STAT_RFSF_MASK                  (0x100U)
#define STCU_ERR_STAT_RFSF_SHIFT                 (8U)
/*! RFSF
 *  0b0..No errors that trigger the Recoverable Faults condition
 *  0b1..There are errors that trigger the Recoverable Faults condition
 */
#define STCU_ERR_STAT_RFSF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_RFSF_SHIFT)) & STCU_ERR_STAT_RFSF_MASK)

#define STCU_ERR_STAT_UFSF_MASK                  (0x200U)
#define STCU_ERR_STAT_UFSF_SHIFT                 (9U)
/*! UFSF
 *  0b0..No errors that trigger the UF condition.
 *  0b1..There are errors that trigger the UF condition.
 */
#define STCU_ERR_STAT_UFSF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_UFSF_SHIFT)) & STCU_ERR_STAT_UFSF_MASK)

#define STCU_ERR_STAT_INVPSW_MASK                (0x10000U)
#define STCU_ERR_STAT_INVPSW_SHIFT               (16U)
/*! INVPSW
 *  0b0..Valid linked pointer list
 *  0b1..Invalid linked pointer list. The following conditions set this bit: Initial LBIST orMBIST pointer is out
 *       of range; LBIST is selected when MBIST is concurrently running or vice versa; Error in the LBIST/MBIST
 *       linking (execution generates an infinite loop).
 */
#define STCU_ERR_STAT_INVPSW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_INVPSW_SHIFT)) & STCU_ERR_STAT_INVPSW_MASK)

#define STCU_ERR_STAT_ENGESW_MASK                (0x20000U)
#define STCU_ERR_STAT_ENGESW_SHIFT               (17U)
/*! ENGESW
 *  0b0..Valid engine execution
 *  0b1..Invalid engine execution. The error conditions that set this bit are FSM, protocol error, and so on.
 */
#define STCU_ERR_STAT_ENGESW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_ENGESW_SHIFT)) & STCU_ERR_STAT_ENGESW_MASK)

#define STCU_ERR_STAT_WDTOSW_MASK                (0x80000U)
#define STCU_ERR_STAT_WDTOSW_SHIFT               (19U)
/*! WDTOSW
 *  0b0..LBIST and MBIST time slots completed within the assigned watchdog time.
 *  0b1..LBIST and MBIST time slots not completed within the assigned watchdog time or there are internal mismatches among End of Execution signals.
 */
#define STCU_ERR_STAT_WDTOSW(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_WDTOSW_SHIFT)) & STCU_ERR_STAT_WDTOSW_MASK)

#define STCU_ERR_STAT_LOCKESW_MASK               (0x100000U)
#define STCU_ERR_STAT_LOCKESW_SHIFT              (20U)
/*! LOCKESW
 *  0b0..In case PLL is enabled, it is correctly locked during the self-test sequence
 *  0b1..When the PLL is enabled, this flag highlights that there has been an unexpected PLL unlock(loss-of-lock)
 *       event during the online self-test sequence execution. The online self-test run is stopped and the status
 *       of the currently running LBISTs or MBISTs is saved in the related registers. The LOCK signal is monitored
 *       during the LBIST run when RUNSW[LBSWPLLEN] is set and/or during the MBIST run when RUNSW[MBSWPLLEN] = 1.
 */
#define STCU_ERR_STAT_LOCKESW(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ERR_STAT_LOCKESW_SHIFT)) & STCU_ERR_STAT_LOCKESW_MASK)
/*! @} */

/*! @name ERR_FM - STCU2 Error FM */
/*! @{ */

#define STCU_ERR_FM_INVPUFM_MASK                 (0x1U)
#define STCU_ERR_FM_INVPUFM_SHIFT                (0U)
/*! INVPUFM
 *  0b0..Recoverable Fault Mapping
 *  0b1..Unrecoverable Mapping
 */
#define STCU_ERR_FM_INVPUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_INVPUFM_SHIFT)) & STCU_ERR_FM_INVPUFM_MASK)

#define STCU_ERR_FM_ENGEUFM_MASK                 (0x2U)
#define STCU_ERR_FM_ENGEUFM_SHIFT                (1U)
/*! ENGEUFM
 *  0b0..Recoverable Fault Mapping
 *  0b1..Unrecoverable Fault Mapping
 */
#define STCU_ERR_FM_ENGEUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_ENGEUFM_SHIFT)) & STCU_ERR_FM_ENGEUFM_MASK)

#define STCU_ERR_FM_WDTOUFM_MASK                 (0x8U)
#define STCU_ERR_FM_WDTOUFM_SHIFT                (3U)
/*! WDTOUFM
 *  0b0..Recoverable Fault Mapping
 *  0b1..Unrecoverable Fault Mapping
 */
#define STCU_ERR_FM_WDTOUFM(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_WDTOUFM_SHIFT)) & STCU_ERR_FM_WDTOUFM_MASK)

#define STCU_ERR_FM_LOCKEUFM_MASK                (0x10U)
#define STCU_ERR_FM_LOCKEUFM_SHIFT               (4U)
/*! LOCKEUFM
 *  0b0..Recoverable Fault Mapping
 *  0b1..Unrecoverable Fault Mapping
 */
#define STCU_ERR_FM_LOCKEUFM(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_ERR_FM_LOCKEUFM_SHIFT)) & STCU_ERR_FM_LOCKEUFM_MASK)
/*! @} */

/*! @name LBSSW0 - STCU2 Online LBIST Status */
/*! @{ */

#define STCU_LBSSW0_LBSSW0_MASK                  (0x1U)
#define STCU_LBSSW0_LBSSW0_SHIFT                 (0U)
/*! LBSSW0 - LBSSW0
 *  0b0..Failed LBIST execution
 *  0b1..Successful LBIST execution
 */
#define STCU_LBSSW0_LBSSW0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBSSW0_LBSSW0_SHIFT)) & STCU_LBSSW0_LBSSW0_MASK)
/*! @} */

/*! @name LBESW0 - STCU2 Online LBIST End Flag */
/*! @{ */

#define STCU_LBESW0_LBESW0_MASK                  (0x1U)
#define STCU_LBESW0_LBESW0_SHIFT                 (0U)
/*! LBESW0 - LBESW
 *  0b0..LBIST execution not yet completed
 *  0b1..LBIST execution finished
 */
#define STCU_LBESW0_LBESW0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBESW0_LBESW0_SHIFT)) & STCU_LBESW0_LBESW0_MASK)
/*! @} */

/*! @name LBRMSW0 - STCU2 Online LBIST Reset Management */
/*! @{ */

#define STCU_LBRMSW0_LBRMSW0_MASK                (0x1U)
#define STCU_LBRMSW0_LBRMSW0_SHIFT               (0U)
/*! LBRMSW0 - LBRMSW
 *  0b0..Dedicated functional reset is pulsed at the end of LBIST run
 *  0b1..Global functional reset is pulsed at the end of LBIST run
 */
#define STCU_LBRMSW0_LBRMSW0(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_LBRMSW0_LBRMSW0_SHIFT)) & STCU_LBRMSW0_LBRMSW0_MASK)
/*! @} */

/*! @name LBUFM0 - STCU2 Online LBIST Unrecoverable FM */
/*! @{ */

#define STCU_LBUFM0_LBUFM0_MASK                  (0x1U)
#define STCU_LBUFM0_LBUFM0_SHIFT                 (0U)
/*! LBUFM0
 *  0b0..Recoverable Fault mapping
 *  0b1..Unrecoverable Fault mapping
 */
#define STCU_LBUFM0_LBUFM0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_LBUFM0_LBUFM0_SHIFT)) & STCU_LBUFM0_LBUFM0_MASK)
/*! @} */

/*! @name MBSSW0 - STCU2 Online MBIST Status */
/*! @{ */

#define STCU_MBSSW0_MBSSW0_MASK                  (0x1U)
#define STCU_MBSSW0_MBSSW0_SHIFT                 (0U)
/*! MBSSW0 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW0_SHIFT)) & STCU_MBSSW0_MBSSW0_MASK)

#define STCU_MBSSW0_MBSSW1_MASK                  (0x2U)
#define STCU_MBSSW0_MBSSW1_SHIFT                 (1U)
/*! MBSSW1 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW1(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW1_SHIFT)) & STCU_MBSSW0_MBSSW1_MASK)

#define STCU_MBSSW0_MBSSW2_MASK                  (0x4U)
#define STCU_MBSSW0_MBSSW2_SHIFT                 (2U)
/*! MBSSW2 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW2(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW2_SHIFT)) & STCU_MBSSW0_MBSSW2_MASK)

#define STCU_MBSSW0_MBSSW3_MASK                  (0x8U)
#define STCU_MBSSW0_MBSSW3_SHIFT                 (3U)
/*! MBSSW3 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW3(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW3_SHIFT)) & STCU_MBSSW0_MBSSW3_MASK)

#define STCU_MBSSW0_MBSSW4_MASK                  (0x10U)
#define STCU_MBSSW0_MBSSW4_SHIFT                 (4U)
/*! MBSSW4 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW4(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW4_SHIFT)) & STCU_MBSSW0_MBSSW4_MASK)

#define STCU_MBSSW0_MBSSW5_MASK                  (0x20U)
#define STCU_MBSSW0_MBSSW5_SHIFT                 (5U)
/*! MBSSW5 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW5(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW5_SHIFT)) & STCU_MBSSW0_MBSSW5_MASK)

#define STCU_MBSSW0_MBSSW6_MASK                  (0x40U)
#define STCU_MBSSW0_MBSSW6_SHIFT                 (6U)
/*! MBSSW6 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW6(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW6_SHIFT)) & STCU_MBSSW0_MBSSW6_MASK)

#define STCU_MBSSW0_MBSSW7_MASK                  (0x80U)
#define STCU_MBSSW0_MBSSW7_SHIFT                 (7U)
/*! MBSSW7 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW7(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW7_SHIFT)) & STCU_MBSSW0_MBSSW7_MASK)

#define STCU_MBSSW0_MBSSW8_MASK                  (0x100U)
#define STCU_MBSSW0_MBSSW8_SHIFT                 (8U)
/*! MBSSW8 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW8(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW8_SHIFT)) & STCU_MBSSW0_MBSSW8_MASK)

#define STCU_MBSSW0_MBSSW9_MASK                  (0x200U)
#define STCU_MBSSW0_MBSSW9_SHIFT                 (9U)
/*! MBSSW9 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW9(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW9_SHIFT)) & STCU_MBSSW0_MBSSW9_MASK)

#define STCU_MBSSW0_MBSSW10_MASK                 (0x400U)
#define STCU_MBSSW0_MBSSW10_SHIFT                (10U)
/*! MBSSW10 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW10(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW10_SHIFT)) & STCU_MBSSW0_MBSSW10_MASK)

#define STCU_MBSSW0_MBSSW11_MASK                 (0x800U)
#define STCU_MBSSW0_MBSSW11_SHIFT                (11U)
/*! MBSSW11 - MBSSW
 *  0b0..Failed MBIST execution
 *  0b1..No fault detected during the MBIST execution
 */
#define STCU_MBSSW0_MBSSW11(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBSSW0_MBSSW11_SHIFT)) & STCU_MBSSW0_MBSSW11_MASK)
/*! @} */

/*! @name MBESW0 - STCU2 Online MBIST End Flag */
/*! @{ */

#define STCU_MBESW0_MBESW0_MASK                  (0x1U)
#define STCU_MBESW0_MBESW0_SHIFT                 (0U)
/*! MBESW0
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW0_SHIFT)) & STCU_MBESW0_MBESW0_MASK)

#define STCU_MBESW0_MBESW1_MASK                  (0x2U)
#define STCU_MBESW0_MBESW1_SHIFT                 (1U)
/*! MBESW1
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW1(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW1_SHIFT)) & STCU_MBESW0_MBESW1_MASK)

#define STCU_MBESW0_MBESW2_MASK                  (0x4U)
#define STCU_MBESW0_MBESW2_SHIFT                 (2U)
/*! MBESW2
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW2(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW2_SHIFT)) & STCU_MBESW0_MBESW2_MASK)

#define STCU_MBESW0_MBESW3_MASK                  (0x8U)
#define STCU_MBESW0_MBESW3_SHIFT                 (3U)
/*! MBESW3
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW3(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW3_SHIFT)) & STCU_MBESW0_MBESW3_MASK)

#define STCU_MBESW0_MBESW4_MASK                  (0x10U)
#define STCU_MBESW0_MBESW4_SHIFT                 (4U)
/*! MBESW4
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW4(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW4_SHIFT)) & STCU_MBESW0_MBESW4_MASK)

#define STCU_MBESW0_MBESW5_MASK                  (0x20U)
#define STCU_MBESW0_MBESW5_SHIFT                 (5U)
/*! MBESW5
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW5(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW5_SHIFT)) & STCU_MBESW0_MBESW5_MASK)

#define STCU_MBESW0_MBESW6_MASK                  (0x40U)
#define STCU_MBESW0_MBESW6_SHIFT                 (6U)
/*! MBESW6
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW6(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW6_SHIFT)) & STCU_MBESW0_MBESW6_MASK)

#define STCU_MBESW0_MBESW7_MASK                  (0x80U)
#define STCU_MBESW0_MBESW7_SHIFT                 (7U)
/*! MBESW7
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW7(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW7_SHIFT)) & STCU_MBESW0_MBESW7_MASK)

#define STCU_MBESW0_MBESW8_MASK                  (0x100U)
#define STCU_MBESW0_MBESW8_SHIFT                 (8U)
/*! MBESW8
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW8(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW8_SHIFT)) & STCU_MBESW0_MBESW8_MASK)

#define STCU_MBESW0_MBESW9_MASK                  (0x200U)
#define STCU_MBESW0_MBESW9_SHIFT                 (9U)
/*! MBESW9
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW9(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW9_SHIFT)) & STCU_MBESW0_MBESW9_MASK)

#define STCU_MBESW0_MBESW10_MASK                 (0x400U)
#define STCU_MBESW0_MBESW10_SHIFT                (10U)
/*! MBESW10
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW10(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW10_SHIFT)) & STCU_MBESW0_MBESW10_MASK)

#define STCU_MBESW0_MBESW11_MASK                 (0x800U)
#define STCU_MBESW0_MBESW11_SHIFT                (11U)
/*! MBESW11
 *  0b0..MBIST execution still ongoing
 *  0b1..MBIST execution finished
 */
#define STCU_MBESW0_MBESW11(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBESW0_MBESW11_SHIFT)) & STCU_MBESW0_MBESW11_MASK)
/*! @} */

/*! @name MBUFM0 - STCU2 MBIST Unrecoverable FM */
/*! @{ */

#define STCU_MBUFM0_MBUFM0_MASK                  (0x1U)
#define STCU_MBUFM0_MBUFM0_SHIFT                 (0U)
/*! MBUFM0 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM0(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM0_SHIFT)) & STCU_MBUFM0_MBUFM0_MASK)

#define STCU_MBUFM0_MBUFM1_MASK                  (0x2U)
#define STCU_MBUFM0_MBUFM1_SHIFT                 (1U)
/*! MBUFM1 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM1(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM1_SHIFT)) & STCU_MBUFM0_MBUFM1_MASK)

#define STCU_MBUFM0_MBUFM2_MASK                  (0x4U)
#define STCU_MBUFM0_MBUFM2_SHIFT                 (2U)
/*! MBUFM2 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM2(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM2_SHIFT)) & STCU_MBUFM0_MBUFM2_MASK)

#define STCU_MBUFM0_MBUFM3_MASK                  (0x8U)
#define STCU_MBUFM0_MBUFM3_SHIFT                 (3U)
/*! MBUFM3 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM3(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM3_SHIFT)) & STCU_MBUFM0_MBUFM3_MASK)

#define STCU_MBUFM0_MBUFM4_MASK                  (0x10U)
#define STCU_MBUFM0_MBUFM4_SHIFT                 (4U)
/*! MBUFM4 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM4(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM4_SHIFT)) & STCU_MBUFM0_MBUFM4_MASK)

#define STCU_MBUFM0_MBUFM5_MASK                  (0x20U)
#define STCU_MBUFM0_MBUFM5_SHIFT                 (5U)
/*! MBUFM5 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM5(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM5_SHIFT)) & STCU_MBUFM0_MBUFM5_MASK)

#define STCU_MBUFM0_MBUFM6_MASK                  (0x40U)
#define STCU_MBUFM0_MBUFM6_SHIFT                 (6U)
/*! MBUFM6 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM6(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM6_SHIFT)) & STCU_MBUFM0_MBUFM6_MASK)

#define STCU_MBUFM0_MBUFM7_MASK                  (0x80U)
#define STCU_MBUFM0_MBUFM7_SHIFT                 (7U)
/*! MBUFM7 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM7(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM7_SHIFT)) & STCU_MBUFM0_MBUFM7_MASK)

#define STCU_MBUFM0_MBUFM8_MASK                  (0x100U)
#define STCU_MBUFM0_MBUFM8_SHIFT                 (8U)
/*! MBUFM8 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM8(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM8_SHIFT)) & STCU_MBUFM0_MBUFM8_MASK)

#define STCU_MBUFM0_MBUFM9_MASK                  (0x200U)
#define STCU_MBUFM0_MBUFM9_SHIFT                 (9U)
/*! MBUFM9 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM9(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM9_SHIFT)) & STCU_MBUFM0_MBUFM9_MASK)

#define STCU_MBUFM0_MBUFM10_MASK                 (0x400U)
#define STCU_MBUFM0_MBUFM10_SHIFT                (10U)
/*! MBUFM10 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM10(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM10_SHIFT)) & STCU_MBUFM0_MBUFM10_MASK)

#define STCU_MBUFM0_MBUFM11_MASK                 (0x800U)
#define STCU_MBUFM0_MBUFM11_SHIFT                (11U)
/*! MBUFM11 - MBESW
 *  0b0..Recoverable fault mapping
 *  0b1..Unrecoverable fault mapping
 */
#define STCU_MBUFM0_MBUFM11(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_MBUFM0_MBUFM11_SHIFT)) & STCU_MBUFM0_MBUFM11_MASK)
/*! @} */

/*! @name CTRL - STCU2 LBIST Control */
/*! @{ */

#define STCU_CTRL_CWS_MASK                       (0x3FU)
#define STCU_CTRL_CWS_SHIFT                      (0U)
/*! CWS
 *  0b000000..Illegal
 *  0b000001..Controller waits 1 shift cycle for capture to finish.
 *  0b000010..Controller waits 2 shift cycles for capture to finish.
 *  0b000011..Controller waits 3 shift cycles for capture to finish.
 *  0b000100..Controller waits 4 shift cycles for capture to finish.
 *  0b000101..Controller waits 5 shift cycles for capture to finish.
 *  0b000110..Controller waits 6 shift cycles for capture to finish.
 *  0b000111..Controller waits 7 shift cycles for capture to finish.
 */
#define STCU_CTRL_CWS(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_CWS_SHIFT)) & STCU_CTRL_CWS_MASK)

#define STCU_CTRL_SCEN_ON_MASK                   (0xF00U)
#define STCU_CTRL_SCEN_ON_SHIFT                  (8U)
/*! SCEN_ON
 *  0b0000..0 delay cycles
 *  0b0001..1 delay cycle
 *  0b0010..2 delay cycles
 *  0b0011..3 delay cycles
 *  0b0100..4 delay cycles
 *  0b0101..5 delay cycles
 *  0b0110..6 delay cycles
 *  0b0111..7 delay cycles
 *  0b1000..8 delay cycles
 *  0b1001..9 delay cycles
 *  0b1010..10 delay cycles
 *  0b1011..11 delay cycles
 *  0b1100..12 delay cycles
 *  0b1101..13 delay cycles
 *  0b1110..14 delay cycles
 *  0b1111..15 delay cycles
 */
#define STCU_CTRL_SCEN_ON(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SCEN_ON_SHIFT)) & STCU_CTRL_SCEN_ON_MASK)

#define STCU_CTRL_SCEN_OFF_MASK                  (0xF000U)
#define STCU_CTRL_SCEN_OFF_SHIFT                 (12U)
/*! SCEN_OFF
 *  0b0000..0 delay cycles
 *  0b0001..1 delay cycle
 *  0b0010..2 delay cycles
 *  0b0011..3 delay cycles
 *  0b0100..4 delay cycles
 *  0b0101..5 delay cycles
 *  0b0110..6 delay cycles
 *  0b0111..7 delay cycles
 *  0b1000..8 delay cycles
 *  0b1001..9 delay cycles
 *  0b1010..10 delay cycles
 *  0b1011..11 delay cycles
 *  0b1100..12 delay cycles
 *  0b1101..13 delay cycles
 *  0b1110..14 delay cycles
 *  0b1111..15 delay cycles
 */
#define STCU_CTRL_SCEN_OFF(x)                    (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SCEN_OFF_SHIFT)) & STCU_CTRL_SCEN_OFF_MASK)

#define STCU_CTRL_SHS_MASK                       (0x70000U)
#define STCU_CTRL_SHS_SHIFT                      (16U)
/*! SHS
 *  0b000..Shift at full rate (BIST clock).
 *  0b001..Shift at 1/2 rate (BIST clock).
 *  0b010..Shift at 1/3 rate (BIST clock).
 *  0b011..Shift at 1/4 rate (BIST clock).
 *  0b100..Shift at 1/5 rate (BIST clock).
 *  0b101..Shift at 1/6 rate (BIST clock).
 *  0b110..Shift at 1/7 rate (BIST clock).
 *  0b111..Shift at 1/8 rate (BIST clock).
 */
#define STCU_CTRL_SHS(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_SHS_SHIFT)) & STCU_CTRL_SHS_MASK)

#define STCU_CTRL_PTR_MASK                       (0x7FE00000U)
#define STCU_CTRL_PTR_SHIFT                      (21U)
#define STCU_CTRL_PTR(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_PTR_SHIFT)) & STCU_CTRL_PTR_MASK)

#define STCU_CTRL_CSM_MASK                       (0x80000000U)
#define STCU_CTRL_CSM_SHIFT                      (31U)
/*! CSM
 *  0b0..Sequential mode
 *  0b1..Concurrent mode
 */
#define STCU_CTRL_CSM(x)                         (((uint32_t)(((uint32_t)(x)) << STCU_CTRL_CSM_SHIFT)) & STCU_CTRL_CSM_MASK)
/*! @} */

/* The count of STCU_CTRL */
#define STCU_CTRL_COUNT                          (1U)

/*! @name PCS - STCU2 LBIST PC Stop */
/*! @{ */

#define STCU_PCS_PCS_MASK                        (0x3FFFFFFU)
#define STCU_PCS_PCS_SHIFT                       (0U)
/*! PCS - PCS */
#define STCU_PCS_PCS(x)                          (((uint32_t)(((uint32_t)(x)) << STCU_PCS_PCS_SHIFT)) & STCU_PCS_PCS_MASK)
/*! @} */

/* The count of STCU_PCS */
#define STCU_PCS_COUNT                           (1U)

/*! @name MISRELSW - STCU2 Online LBIST MISR Expected Low */
/*! @{ */

#define STCU_MISRELSW_MISRESWx_MASK              (0xFFFFFFFFU)
#define STCU_MISRELSW_MISRESWx_SHIFT             (0U)
#define STCU_MISRELSW_MISRESWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISRELSW_MISRESWx_SHIFT)) & STCU_MISRELSW_MISRESWx_MASK)
/*! @} */

/* The count of STCU_MISRELSW */
#define STCU_MISRELSW_COUNT                      (1U)

/*! @name MISREHSW - STCU2 Online LBIST MISR Expected High */
/*! @{ */

#define STCU_MISREHSW_MISRESWx_MASK              (0xFFFFFFFFU)
#define STCU_MISREHSW_MISRESWx_SHIFT             (0U)
#define STCU_MISREHSW_MISRESWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISREHSW_MISRESWx_SHIFT)) & STCU_MISREHSW_MISRESWx_MASK)
/*! @} */

/* The count of STCU_MISREHSW */
#define STCU_MISREHSW_COUNT                      (1U)

/*! @name MISRRLSW - STCU2 Online LBIST MISR Read Low */
/*! @{ */

#define STCU_MISRRLSW_MISRRSWx_MASK              (0xFFFFFFFFU)
#define STCU_MISRRLSW_MISRRSWx_SHIFT             (0U)
/*! MISRRSWx - MISRRSWx */
#define STCU_MISRRLSW_MISRRSWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISRRLSW_MISRRSWx_SHIFT)) & STCU_MISRRLSW_MISRRSWx_MASK)
/*! @} */

/* The count of STCU_MISRRLSW */
#define STCU_MISRRLSW_COUNT                      (1U)

/*! @name MISRRHSW - STCU2 Online LBIST MISR Read High */
/*! @{ */

#define STCU_MISRRHSW_MISRRSWx_MASK              (0xFFFFFFFFU)
#define STCU_MISRRHSW_MISRRSWx_SHIFT             (0U)
/*! MISRRSWx - MISRRSWx */
#define STCU_MISRRHSW_MISRRSWx(x)                (((uint32_t)(((uint32_t)(x)) << STCU_MISRRHSW_MISRRSWx_SHIFT)) & STCU_MISRRHSW_MISRRSWx_MASK)
/*! @} */

/* The count of STCU_MISRRHSW */
#define STCU_MISRRHSW_COUNT                      (1U)

/*! @name ALGOSEL - STCU2 Algorithm Select */
/*! @{ */

#define STCU_ALGOSEL_ALGOSEL0_MASK               (0x1U)
#define STCU_ALGOSEL_ALGOSEL0_SHIFT              (0U)
/*! ALGOSEL0 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL0(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL0_SHIFT)) & STCU_ALGOSEL_ALGOSEL0_MASK)

#define STCU_ALGOSEL_ALGOSEL1_MASK               (0x2U)
#define STCU_ALGOSEL_ALGOSEL1_SHIFT              (1U)
/*! ALGOSEL1 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL1(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL1_SHIFT)) & STCU_ALGOSEL_ALGOSEL1_MASK)

#define STCU_ALGOSEL_ALGOSEL2_MASK               (0x4U)
#define STCU_ALGOSEL_ALGOSEL2_SHIFT              (2U)
/*! ALGOSEL2 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL2(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL2_SHIFT)) & STCU_ALGOSEL_ALGOSEL2_MASK)

#define STCU_ALGOSEL_ALGOSEL3_MASK               (0x8U)
#define STCU_ALGOSEL_ALGOSEL3_SHIFT              (3U)
/*! ALGOSEL3 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL3(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL3_SHIFT)) & STCU_ALGOSEL_ALGOSEL3_MASK)

#define STCU_ALGOSEL_ALGOSEL4_MASK               (0x10U)
#define STCU_ALGOSEL_ALGOSEL4_SHIFT              (4U)
/*! ALGOSEL4 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL4(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL4_SHIFT)) & STCU_ALGOSEL_ALGOSEL4_MASK)

#define STCU_ALGOSEL_ALGOSEL5_MASK               (0x20U)
#define STCU_ALGOSEL_ALGOSEL5_SHIFT              (5U)
/*! ALGOSEL5 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL5(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL5_SHIFT)) & STCU_ALGOSEL_ALGOSEL5_MASK)

#define STCU_ALGOSEL_ALGOSEL6_MASK               (0x40U)
#define STCU_ALGOSEL_ALGOSEL6_SHIFT              (6U)
/*! ALGOSEL6 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL6(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL6_SHIFT)) & STCU_ALGOSEL_ALGOSEL6_MASK)

#define STCU_ALGOSEL_ALGOSEL7_MASK               (0x80U)
#define STCU_ALGOSEL_ALGOSEL7_SHIFT              (7U)
/*! ALGOSEL7 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL7(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL7_SHIFT)) & STCU_ALGOSEL_ALGOSEL7_MASK)

#define STCU_ALGOSEL_ALGOSEL8_MASK               (0x100U)
#define STCU_ALGOSEL_ALGOSEL8_SHIFT              (8U)
/*! ALGOSEL8 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL8(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL8_SHIFT)) & STCU_ALGOSEL_ALGOSEL8_MASK)

#define STCU_ALGOSEL_ALGOSEL9_MASK               (0x200U)
#define STCU_ALGOSEL_ALGOSEL9_SHIFT              (9U)
/*! ALGOSEL9 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL9(x)                 (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL9_SHIFT)) & STCU_ALGOSEL_ALGOSEL9_MASK)

#define STCU_ALGOSEL_ALGOSEL10_MASK              (0x400U)
#define STCU_ALGOSEL_ALGOSEL10_SHIFT             (10U)
/*! ALGOSEL10 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL10(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL10_SHIFT)) & STCU_ALGOSEL_ALGOSEL10_MASK)

#define STCU_ALGOSEL_ALGOSEL11_MASK              (0x800U)
#define STCU_ALGOSEL_ALGOSEL11_SHIFT             (11U)
/*! ALGOSEL11 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL11(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL11_SHIFT)) & STCU_ALGOSEL_ALGOSEL11_MASK)

#define STCU_ALGOSEL_ALGOSEL12_MASK              (0x1000U)
#define STCU_ALGOSEL_ALGOSEL12_SHIFT             (12U)
/*! ALGOSEL12 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL12(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL12_SHIFT)) & STCU_ALGOSEL_ALGOSEL12_MASK)

#define STCU_ALGOSEL_ALGOSEL13_MASK              (0x2000U)
#define STCU_ALGOSEL_ALGOSEL13_SHIFT             (13U)
/*! ALGOSEL13 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL13(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL13_SHIFT)) & STCU_ALGOSEL_ALGOSEL13_MASK)

#define STCU_ALGOSEL_ALGOSEL14_MASK              (0x4000U)
#define STCU_ALGOSEL_ALGOSEL14_SHIFT             (14U)
/*! ALGOSEL14 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL14(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL14_SHIFT)) & STCU_ALGOSEL_ALGOSEL14_MASK)

#define STCU_ALGOSEL_ALGOSEL15_MASK              (0x8000U)
#define STCU_ALGOSEL_ALGOSEL15_SHIFT             (15U)
/*! ALGOSEL15 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL15(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL15_SHIFT)) & STCU_ALGOSEL_ALGOSEL15_MASK)

#define STCU_ALGOSEL_ALGOSEL16_MASK              (0x10000U)
#define STCU_ALGOSEL_ALGOSEL16_SHIFT             (16U)
/*! ALGOSEL16 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL16(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL16_SHIFT)) & STCU_ALGOSEL_ALGOSEL16_MASK)

#define STCU_ALGOSEL_ALGOSEL17_MASK              (0x20000U)
#define STCU_ALGOSEL_ALGOSEL17_SHIFT             (17U)
/*! ALGOSEL17 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL17(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL17_SHIFT)) & STCU_ALGOSEL_ALGOSEL17_MASK)

#define STCU_ALGOSEL_ALGOSEL18_MASK              (0x40000U)
#define STCU_ALGOSEL_ALGOSEL18_SHIFT             (18U)
/*! ALGOSEL18 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL18(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL18_SHIFT)) & STCU_ALGOSEL_ALGOSEL18_MASK)

#define STCU_ALGOSEL_ALGOSEL19_MASK              (0x80000U)
#define STCU_ALGOSEL_ALGOSEL19_SHIFT             (19U)
/*! ALGOSEL19 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL19(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL19_SHIFT)) & STCU_ALGOSEL_ALGOSEL19_MASK)

#define STCU_ALGOSEL_ALGOSEL20_MASK              (0x100000U)
#define STCU_ALGOSEL_ALGOSEL20_SHIFT             (20U)
/*! ALGOSEL20 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL20(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL20_SHIFT)) & STCU_ALGOSEL_ALGOSEL20_MASK)

#define STCU_ALGOSEL_ALGOSEL21_MASK              (0x200000U)
#define STCU_ALGOSEL_ALGOSEL21_SHIFT             (21U)
/*! ALGOSEL21 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL21(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL21_SHIFT)) & STCU_ALGOSEL_ALGOSEL21_MASK)

#define STCU_ALGOSEL_ALGOSEL22_MASK              (0x400000U)
#define STCU_ALGOSEL_ALGOSEL22_SHIFT             (22U)
/*! ALGOSEL22 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL22(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL22_SHIFT)) & STCU_ALGOSEL_ALGOSEL22_MASK)

#define STCU_ALGOSEL_ALGOSEL23_MASK              (0x800000U)
#define STCU_ALGOSEL_ALGOSEL23_SHIFT             (23U)
/*! ALGOSEL23 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL23(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL23_SHIFT)) & STCU_ALGOSEL_ALGOSEL23_MASK)

#define STCU_ALGOSEL_ALGOSEL24_MASK              (0x1000000U)
#define STCU_ALGOSEL_ALGOSEL24_SHIFT             (24U)
/*! ALGOSEL24 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL24(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL24_SHIFT)) & STCU_ALGOSEL_ALGOSEL24_MASK)

#define STCU_ALGOSEL_ALGOSEL25_MASK              (0x2000000U)
#define STCU_ALGOSEL_ALGOSEL25_SHIFT             (25U)
/*! ALGOSEL25 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL25(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL25_SHIFT)) & STCU_ALGOSEL_ALGOSEL25_MASK)

#define STCU_ALGOSEL_ALGOSEL26_MASK              (0x4000000U)
#define STCU_ALGOSEL_ALGOSEL26_SHIFT             (26U)
/*! ALGOSEL26 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL26(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL26_SHIFT)) & STCU_ALGOSEL_ALGOSEL26_MASK)

#define STCU_ALGOSEL_ALGOSEL27_MASK              (0x8000000U)
#define STCU_ALGOSEL_ALGOSEL27_SHIFT             (27U)
/*! ALGOSEL27 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL27(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL27_SHIFT)) & STCU_ALGOSEL_ALGOSEL27_MASK)

#define STCU_ALGOSEL_ALGOSEL28_MASK              (0x10000000U)
#define STCU_ALGOSEL_ALGOSEL28_SHIFT             (28U)
/*! ALGOSEL28 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL28(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL28_SHIFT)) & STCU_ALGOSEL_ALGOSEL28_MASK)

#define STCU_ALGOSEL_ALGOSEL29_MASK              (0x20000000U)
#define STCU_ALGOSEL_ALGOSEL29_SHIFT             (29U)
/*! ALGOSEL29 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL29(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL29_SHIFT)) & STCU_ALGOSEL_ALGOSEL29_MASK)

#define STCU_ALGOSEL_ALGOSEL30_MASK              (0x40000000U)
#define STCU_ALGOSEL_ALGOSEL30_SHIFT             (30U)
/*! ALGOSEL30 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL30(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL30_SHIFT)) & STCU_ALGOSEL_ALGOSEL30_MASK)

#define STCU_ALGOSEL_ALGOSEL31_MASK              (0x80000000U)
#define STCU_ALGOSEL_ALGOSEL31_SHIFT             (31U)
/*! ALGOSEL31 - Algorithm Select */
#define STCU_ALGOSEL_ALGOSEL31(x)                (((uint32_t)(((uint32_t)(x)) << STCU_ALGOSEL_ALGOSEL31_SHIFT)) & STCU_ALGOSEL_ALGOSEL31_MASK)
/*! @} */

/*! @name STGGR - STCU2 MBIST Stagger */
/*! @{ */

#define STCU_STGGR_STAG_MASK                     (0xFFFFFFFFU)
#define STCU_STGGR_STAG_SHIFT                    (0U)
/*! STAG - STAG */
#define STCU_STGGR_STAG(x)                       (((uint32_t)(((uint32_t)(x)) << STCU_STGGR_STAG_SHIFT)) & STCU_STGGR_STAG_MASK)
/*! @} */

/*! @name BSTART - STCU2 BIST Start */
/*! @{ */

#define STCU_BSTART_BSTART0_MASK                 (0x1U)
#define STCU_BSTART_BSTART0_SHIFT                (0U)
/*! BSTART0 - BIST Start */
#define STCU_BSTART_BSTART0(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART0_SHIFT)) & STCU_BSTART_BSTART0_MASK)

#define STCU_BSTART_BSTART1_MASK                 (0x2U)
#define STCU_BSTART_BSTART1_SHIFT                (1U)
/*! BSTART1 - BIST Start */
#define STCU_BSTART_BSTART1(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART1_SHIFT)) & STCU_BSTART_BSTART1_MASK)

#define STCU_BSTART_BSTART2_MASK                 (0x4U)
#define STCU_BSTART_BSTART2_SHIFT                (2U)
/*! BSTART2 - BIST Start */
#define STCU_BSTART_BSTART2(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART2_SHIFT)) & STCU_BSTART_BSTART2_MASK)

#define STCU_BSTART_BSTART3_MASK                 (0x8U)
#define STCU_BSTART_BSTART3_SHIFT                (3U)
/*! BSTART3 - BIST Start */
#define STCU_BSTART_BSTART3(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART3_SHIFT)) & STCU_BSTART_BSTART3_MASK)

#define STCU_BSTART_BSTART4_MASK                 (0x10U)
#define STCU_BSTART_BSTART4_SHIFT                (4U)
/*! BSTART4 - BIST Start */
#define STCU_BSTART_BSTART4(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART4_SHIFT)) & STCU_BSTART_BSTART4_MASK)

#define STCU_BSTART_BSTART5_MASK                 (0x20U)
#define STCU_BSTART_BSTART5_SHIFT                (5U)
/*! BSTART5 - BIST Start */
#define STCU_BSTART_BSTART5(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART5_SHIFT)) & STCU_BSTART_BSTART5_MASK)

#define STCU_BSTART_BSTART6_MASK                 (0x40U)
#define STCU_BSTART_BSTART6_SHIFT                (6U)
/*! BSTART6 - BIST Start */
#define STCU_BSTART_BSTART6(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART6_SHIFT)) & STCU_BSTART_BSTART6_MASK)

#define STCU_BSTART_BSTART7_MASK                 (0x80U)
#define STCU_BSTART_BSTART7_SHIFT                (7U)
/*! BSTART7 - BIST Start */
#define STCU_BSTART_BSTART7(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART7_SHIFT)) & STCU_BSTART_BSTART7_MASK)

#define STCU_BSTART_BSTART8_MASK                 (0x100U)
#define STCU_BSTART_BSTART8_SHIFT                (8U)
/*! BSTART8 - BIST Start */
#define STCU_BSTART_BSTART8(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART8_SHIFT)) & STCU_BSTART_BSTART8_MASK)

#define STCU_BSTART_BSTART9_MASK                 (0x200U)
#define STCU_BSTART_BSTART9_SHIFT                (9U)
/*! BSTART9 - BIST Start */
#define STCU_BSTART_BSTART9(x)                   (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART9_SHIFT)) & STCU_BSTART_BSTART9_MASK)

#define STCU_BSTART_BSTART10_MASK                (0x400U)
#define STCU_BSTART_BSTART10_SHIFT               (10U)
/*! BSTART10 - BIST Start */
#define STCU_BSTART_BSTART10(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART10_SHIFT)) & STCU_BSTART_BSTART10_MASK)

#define STCU_BSTART_BSTART11_MASK                (0x800U)
#define STCU_BSTART_BSTART11_SHIFT               (11U)
/*! BSTART11 - BIST Start */
#define STCU_BSTART_BSTART11(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART11_SHIFT)) & STCU_BSTART_BSTART11_MASK)

#define STCU_BSTART_BSTART12_MASK                (0x1000U)
#define STCU_BSTART_BSTART12_SHIFT               (12U)
/*! BSTART12 - BIST Start */
#define STCU_BSTART_BSTART12(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART12_SHIFT)) & STCU_BSTART_BSTART12_MASK)

#define STCU_BSTART_BSTART13_MASK                (0x2000U)
#define STCU_BSTART_BSTART13_SHIFT               (13U)
/*! BSTART13 - BIST Start */
#define STCU_BSTART_BSTART13(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART13_SHIFT)) & STCU_BSTART_BSTART13_MASK)

#define STCU_BSTART_BSTART14_MASK                (0x4000U)
#define STCU_BSTART_BSTART14_SHIFT               (14U)
/*! BSTART14 - BIST Start */
#define STCU_BSTART_BSTART14(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART14_SHIFT)) & STCU_BSTART_BSTART14_MASK)

#define STCU_BSTART_BSTART15_MASK                (0x8000U)
#define STCU_BSTART_BSTART15_SHIFT               (15U)
/*! BSTART15 - BIST Start */
#define STCU_BSTART_BSTART15(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART15_SHIFT)) & STCU_BSTART_BSTART15_MASK)

#define STCU_BSTART_BSTART16_MASK                (0x10000U)
#define STCU_BSTART_BSTART16_SHIFT               (16U)
/*! BSTART16 - BIST Start */
#define STCU_BSTART_BSTART16(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART16_SHIFT)) & STCU_BSTART_BSTART16_MASK)

#define STCU_BSTART_BSTART17_MASK                (0x20000U)
#define STCU_BSTART_BSTART17_SHIFT               (17U)
/*! BSTART17 - BIST Start */
#define STCU_BSTART_BSTART17(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART17_SHIFT)) & STCU_BSTART_BSTART17_MASK)

#define STCU_BSTART_BSTART18_MASK                (0x40000U)
#define STCU_BSTART_BSTART18_SHIFT               (18U)
/*! BSTART18 - BIST Start */
#define STCU_BSTART_BSTART18(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART18_SHIFT)) & STCU_BSTART_BSTART18_MASK)

#define STCU_BSTART_BSTART19_MASK                (0x80000U)
#define STCU_BSTART_BSTART19_SHIFT               (19U)
/*! BSTART19 - BIST Start */
#define STCU_BSTART_BSTART19(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART19_SHIFT)) & STCU_BSTART_BSTART19_MASK)

#define STCU_BSTART_BSTART20_MASK                (0x100000U)
#define STCU_BSTART_BSTART20_SHIFT               (20U)
/*! BSTART20 - BIST Start */
#define STCU_BSTART_BSTART20(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART20_SHIFT)) & STCU_BSTART_BSTART20_MASK)

#define STCU_BSTART_BSTART21_MASK                (0x200000U)
#define STCU_BSTART_BSTART21_SHIFT               (21U)
/*! BSTART21 - BIST Start */
#define STCU_BSTART_BSTART21(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART21_SHIFT)) & STCU_BSTART_BSTART21_MASK)

#define STCU_BSTART_BSTART22_MASK                (0x400000U)
#define STCU_BSTART_BSTART22_SHIFT               (22U)
/*! BSTART22 - BIST Start */
#define STCU_BSTART_BSTART22(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART22_SHIFT)) & STCU_BSTART_BSTART22_MASK)

#define STCU_BSTART_BSTART23_MASK                (0x800000U)
#define STCU_BSTART_BSTART23_SHIFT               (23U)
/*! BSTART23 - BIST Start */
#define STCU_BSTART_BSTART23(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART23_SHIFT)) & STCU_BSTART_BSTART23_MASK)

#define STCU_BSTART_BSTART24_MASK                (0x1000000U)
#define STCU_BSTART_BSTART24_SHIFT               (24U)
/*! BSTART24 - BIST Start */
#define STCU_BSTART_BSTART24(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART24_SHIFT)) & STCU_BSTART_BSTART24_MASK)

#define STCU_BSTART_BSTART25_MASK                (0x2000000U)
#define STCU_BSTART_BSTART25_SHIFT               (25U)
/*! BSTART25 - BIST Start */
#define STCU_BSTART_BSTART25(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART25_SHIFT)) & STCU_BSTART_BSTART25_MASK)

#define STCU_BSTART_BSTART26_MASK                (0x4000000U)
#define STCU_BSTART_BSTART26_SHIFT               (26U)
/*! BSTART26 - BIST Start */
#define STCU_BSTART_BSTART26(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART26_SHIFT)) & STCU_BSTART_BSTART26_MASK)

#define STCU_BSTART_BSTART27_MASK                (0x8000000U)
#define STCU_BSTART_BSTART27_SHIFT               (27U)
/*! BSTART27 - BIST Start */
#define STCU_BSTART_BSTART27(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART27_SHIFT)) & STCU_BSTART_BSTART27_MASK)

#define STCU_BSTART_BSTART28_MASK                (0x10000000U)
#define STCU_BSTART_BSTART28_SHIFT               (28U)
/*! BSTART28 - BIST Start */
#define STCU_BSTART_BSTART28(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART28_SHIFT)) & STCU_BSTART_BSTART28_MASK)

#define STCU_BSTART_BSTART29_MASK                (0x20000000U)
#define STCU_BSTART_BSTART29_SHIFT               (29U)
/*! BSTART29 - BIST Start */
#define STCU_BSTART_BSTART29(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART29_SHIFT)) & STCU_BSTART_BSTART29_MASK)

#define STCU_BSTART_BSTART30_MASK                (0x40000000U)
#define STCU_BSTART_BSTART30_SHIFT               (30U)
/*! BSTART30 - BIST Start */
#define STCU_BSTART_BSTART30(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART30_SHIFT)) & STCU_BSTART_BSTART30_MASK)

#define STCU_BSTART_BSTART31_MASK                (0x80000000U)
#define STCU_BSTART_BSTART31_SHIFT               (31U)
/*! BSTART31 - BIST Start */
#define STCU_BSTART_BSTART31(x)                  (((uint32_t)(((uint32_t)(x)) << STCU_BSTART_BSTART31_SHIFT)) & STCU_BSTART_BSTART31_MASK)
/*! @} */

/*! @name MB_CTRL - STCU2 MBIST Control */
/*! @{ */

#define STCU_MB_CTRL_BSEL_MASK                   (0x100000U)
#define STCU_MB_CTRL_BSEL_SHIFT                  (20U)
/*! BSEL - BSEL
 *  0b0..Selected BIST is not selected for execution.
 *  0b1..Selected BIST is selected for execution.
 */
#define STCU_MB_CTRL_BSEL(x)                     (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_BSEL_SHIFT)) & STCU_MB_CTRL_BSEL_MASK)

#define STCU_MB_CTRL_PTR_MASK                    (0x7FE00000U)
#define STCU_MB_CTRL_PTR_SHIFT                   (21U)
/*! PTR - PTR */
#define STCU_MB_CTRL_PTR(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_PTR_SHIFT)) & STCU_MB_CTRL_PTR_MASK)

#define STCU_MB_CTRL_CSM_MASK                    (0x80000000U)
#define STCU_MB_CTRL_CSM_SHIFT                   (31U)
/*! CSM - CSM
 *  0b0..Sequential mode
 *  0b1..Concurrent mode
 */
#define STCU_MB_CTRL_CSM(x)                      (((uint32_t)(((uint32_t)(x)) << STCU_MB_CTRL_CSM_SHIFT)) & STCU_MB_CTRL_CSM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group STCU_Register_Masks */


/*!
 * @}
 */ /* end of group STCU_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_STCU_H_ */

