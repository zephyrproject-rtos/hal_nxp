/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_SMM.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for SMM
 *
 * CMSIS Peripheral Access Layer for SMM
 */

#if !defined(PERI_SMM_H_)
#define PERI_SMM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- SMM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMM_Peripheral_Access_Layer SMM Peripheral Access Layer
 * @{
 */

/** SMM - Size of Registers Arrays */
#define SMM_LTCHD_CNT_RTC_COUNT                   3u

/** SMM - Register Layout Typedef */
typedef struct {
  __IO uint32_t CNFG;                              /**< Configuration, offset: 0x0 */
  __IO uint32_t WKUP_MAIN;                         /**< Main CPU wakeup source, offset: 0x4 */
  __IO uint32_t AON_CPU;                           /**< AON CPU wakeup source, offset: 0x8 */
  __I  uint32_t WKUP_STAT;                         /**< Wakeup sources status, offset: 0xC */
  __IO uint32_t STAT;                              /**< Status, offset: 0x10 */
  __IO uint32_t PWDN_CONFIG;                       /**< Power Down configuration, offset: 0x14 */
  __IO uint32_t DPSLP_COUNT;                       /**< Deep Sleep count, offset: 0x18 */
  __IO uint32_t RTC_DCDC_CNTRL;                    /**< RTC DCDC Control, offset: 0x1C */
  __IO uint32_t RTC_XTAL_CONFG1;                   /**< RTC analog XTAL configuration, offset: 0x20 */
  __IO uint32_t RTC_XTAL_CONFG2;                   /**< RTC analog XTAL configuration, offset: 0x24 */
       uint8_t RESERVED_0[4];
  __IO uint32_t LSB_BCKP1;                         /**< Backup LSB1, offset: 0x2C */
  __IO uint32_t MSB_BCKP1;                         /**< Backup MSB1, offset: 0x30 */
  __IO uint32_t LSB_BCKP2;                         /**< Backup LSB2, offset: 0x34 */
  __IO uint32_t MSB_BCKP2;                         /**< Backup MSB2, offset: 0x38 */
       uint8_t RESERVED_1[12];
  __IO uint32_t MEMORY_RTN;                        /**< Memory retain, offset: 0x48 */
  __IO uint32_t BIAS_CTRL;                         /**< RTC analog XTAL bias control, offset: 0x4C */
       uint8_t RESERVED_2[12];
  __IO uint32_t XTAL_TRIM;                         /**< XTAL Trim, offset: 0x5C */
       uint8_t RESERVED_3[224];
  __IO uint32_t TAMP_CTRL;                         /**< Tamper Control, offset: 0x140 */
  __I  uint32_t LATCHED_RTC_COUNTER[SMM_LTCHD_CNT_RTC_COUNT]; /**< Latched RTC Counter, array offset: 0x144, array step: 0x4 */
} SMM_Type;

/* ----------------------------------------------------------------------------
   -- SMM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMM_Register_Masks SMM Register Masks
 * @{
 */

/*! @name CNFG - Configuration */
/*! @{ */

#define SMM_CNFG_EXT_INTP_POL_MASK               (0x1U)
#define SMM_CNFG_EXT_INTP_POL_SHIFT              (0U)
/*! EXT_INTP_POL - External interrupt polarity
 *  0b0..Rising
 *  0b1..Falling
 */
#define SMM_CNFG_EXT_INTP_POL(x)                 (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_EXT_INTP_POL_SHIFT)) & SMM_CNFG_EXT_INTP_POL_MASK)

#define SMM_CNFG_EXT_INTP_MASK_MASK              (0x2U)
#define SMM_CNFG_EXT_INTP_MASK_SHIFT             (1U)
/*! EXT_INTP_MASK - External interrupt mask */
#define SMM_CNFG_EXT_INTP_MASK(x)                (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_EXT_INTP_MASK_SHIFT)) & SMM_CNFG_EXT_INTP_MASK_MASK)

#define SMM_CNFG_DSLP_COUNT_USE_MASK             (0x4U)
#define SMM_CNFG_DSLP_COUNT_USE_SHIFT            (2U)
/*! DSLP_COUNT_USE - Deep Sleep counter for use */
#define SMM_CNFG_DSLP_COUNT_USE(x)               (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_DSLP_COUNT_USE_SHIFT)) & SMM_CNFG_DSLP_COUNT_USE_MASK)

#define SMM_CNFG_DSLP_COUNT_STRT_MASK            (0x8U)
#define SMM_CNFG_DSLP_COUNT_STRT_SHIFT           (3U)
/*! DSLP_COUNT_STRT - Deep Sleep counter start */
#define SMM_CNFG_DSLP_COUNT_STRT(x)              (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_DSLP_COUNT_STRT_SHIFT)) & SMM_CNFG_DSLP_COUNT_STRT_MASK)

#define SMM_CNFG_DSLP_COUNT_RST_MASK             (0x10U)
#define SMM_CNFG_DSLP_COUNT_RST_SHIFT            (4U)
/*! DSLP_COUNT_RST - Deep Sleep counter reset */
#define SMM_CNFG_DSLP_COUNT_RST(x)               (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_DSLP_COUNT_RST_SHIFT)) & SMM_CNFG_DSLP_COUNT_RST_MASK)

#define SMM_CNFG_WTCHDG_USE_INT_MASK             (0x20U)
#define SMM_CNFG_WTCHDG_USE_INT_SHIFT            (5U)
/*! WTCHDG_USE_INT - Watchdog alarm use
 *  0b0..Reset to AON CPU
 *  0b1..Interrupt to AON CPU
 */
#define SMM_CNFG_WTCHDG_USE_INT(x)               (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_WTCHDG_USE_INT_SHIFT)) & SMM_CNFG_WTCHDG_USE_INT_MASK)

#define SMM_CNFG_MAIN_ISO_DSBL_MASK              (0x40U)
#define SMM_CNFG_MAIN_ISO_DSBL_SHIFT             (6U)
/*! MAIN_ISO_DSBL - Main CPU I/O ISO */
#define SMM_CNFG_MAIN_ISO_DSBL(x)                (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_MAIN_ISO_DSBL_SHIFT)) & SMM_CNFG_MAIN_ISO_DSBL_MASK)

#define SMM_CNFG_AON_ISO_DSBL_MASK               (0x80U)
#define SMM_CNFG_AON_ISO_DSBL_SHIFT              (7U)
/*! AON_ISO_DSBL - AON CPU I/O ISO signals */
#define SMM_CNFG_AON_ISO_DSBL(x)                 (((uint32_t)(((uint32_t)(x)) << SMM_CNFG_AON_ISO_DSBL_SHIFT)) & SMM_CNFG_AON_ISO_DSBL_MASK)
/*! @} */

/*! @name WKUP_MAIN - Main CPU wakeup source */
/*! @{ */

#define SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK     (0xFFFFU)
#define SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_SHIFT    (0U)
/*! WKUP_SRC_MAIN_CPU - Bit selection of the wakeup sources to the main CPU */
#define SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU(x)       (((uint32_t)(((uint32_t)(x)) << SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_SHIFT)) & SMM_WKUP_MAIN_WKUP_SRC_MAIN_CPU_MASK)
/*! @} */

/*! @name AON_CPU - AON CPU wakeup source */
/*! @{ */

#define SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK        (0xFFFFU)
#define SMM_AON_CPU_WKUP_SRC_AON_CPU_SHIFT       (0U)
/*! WKUP_SRC_AON_CPU - Selections of the wakeup sources to the AON CPU */
#define SMM_AON_CPU_WKUP_SRC_AON_CPU(x)          (((uint32_t)(((uint32_t)(x)) << SMM_AON_CPU_WKUP_SRC_AON_CPU_SHIFT)) & SMM_AON_CPU_WKUP_SRC_AON_CPU_MASK)
/*! @} */

/*! @name WKUP_STAT - Wakeup sources status */
/*! @{ */

#define SMM_WKUP_STAT_WKUP_SRCS_MASK             (0xFFFFU)
#define SMM_WKUP_STAT_WKUP_SRCS_SHIFT            (0U)
/*! WKUP_SRCS - Wakeup sources status */
#define SMM_WKUP_STAT_WKUP_SRCS(x)               (((uint32_t)(((uint32_t)(x)) << SMM_WKUP_STAT_WKUP_SRCS_SHIFT)) & SMM_WKUP_STAT_WKUP_SRCS_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define SMM_STAT_DPD_END_MASK                    (0x1U)
#define SMM_STAT_DPD_END_SHIFT                   (0U)
/*! DPD_END - Deep Sleep, Power Down, and Deep Power Down end */
#define SMM_STAT_DPD_END(x)                      (((uint32_t)(((uint32_t)(x)) << SMM_STAT_DPD_END_SHIFT)) & SMM_STAT_DPD_END_MASK)

#define SMM_STAT_DPD_STATE_MASK                  (0xEU)
#define SMM_STAT_DPD_STATE_SHIFT                 (1U)
/*! DPD_STATE - Deep Sleep, Power Down, and Deep Power Down state
 *  0b000..All on
 *  0b001..Deep Sleep
 *  0b010..DPD1
 *  0b011..PD1
 *  0b100..DPD2
 *  0b101..DPD3
 *  0b110..Shutdown
 */
#define SMM_STAT_DPD_STATE(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_STAT_DPD_STATE_SHIFT)) & SMM_STAT_DPD_STATE_MASK)

#define SMM_STAT_EXT_INT_A_MASK                  (0x10U)
#define SMM_STAT_EXT_INT_A_SHIFT                 (4U)
/*! EXT_INT_A - External interrupt active */
#define SMM_STAT_EXT_INT_A(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_STAT_EXT_INT_A_SHIFT)) & SMM_STAT_EXT_INT_A_MASK)

#define SMM_STAT_COMP_MATCH_MASK                 (0x20U)
#define SMM_STAT_COMP_MATCH_SHIFT                (5U)
/*! COMP_MATCH - Comparator match */
#define SMM_STAT_COMP_MATCH(x)                   (((uint32_t)(((uint32_t)(x)) << SMM_STAT_COMP_MATCH_SHIFT)) & SMM_STAT_COMP_MATCH_MASK)

#define SMM_STAT_DPSLP_CNTR_M_MASK               (0x40U)
#define SMM_STAT_DPSLP_CNTR_M_SHIFT              (6U)
/*! DPSLP_CNTR_M - Deep Sleep counter match */
#define SMM_STAT_DPSLP_CNTR_M(x)                 (((uint32_t)(((uint32_t)(x)) << SMM_STAT_DPSLP_CNTR_M_SHIFT)) & SMM_STAT_DPSLP_CNTR_M_MASK)

#define SMM_STAT_DPD_SEQ_END_MASK                (0x80U)
#define SMM_STAT_DPD_SEQ_END_SHIFT               (7U)
/*! DPD_SEQ_END - Deep Sleep, Powe Down, and Deep Power Down sequence end */
#define SMM_STAT_DPD_SEQ_END(x)                  (((uint32_t)(((uint32_t)(x)) << SMM_STAT_DPD_SEQ_END_SHIFT)) & SMM_STAT_DPD_SEQ_END_MASK)

#define SMM_STAT_COMP_MATCH_IE_EN_MASK           (0x100U)
#define SMM_STAT_COMP_MATCH_IE_EN_SHIFT          (8U)
/*! COMP_MATCH_IE_EN - Comparator match interrupt enable */
#define SMM_STAT_COMP_MATCH_IE_EN(x)             (((uint32_t)(((uint32_t)(x)) << SMM_STAT_COMP_MATCH_IE_EN_SHIFT)) & SMM_STAT_COMP_MATCH_IE_EN_MASK)

#define SMM_STAT_DPSLP_CNTR_IE_EN_MASK           (0x200U)
#define SMM_STAT_DPSLP_CNTR_IE_EN_SHIFT          (9U)
/*! DPSLP_CNTR_IE_EN - Deep Sleep counter interrupt enable */
#define SMM_STAT_DPSLP_CNTR_IE_EN(x)             (((uint32_t)(((uint32_t)(x)) << SMM_STAT_DPSLP_CNTR_IE_EN_SHIFT)) & SMM_STAT_DPSLP_CNTR_IE_EN_MASK)

#define SMM_STAT_RST_B_WKP_MASK                  (0x400U)
#define SMM_STAT_RST_B_WKP_SHIFT                 (10U)
/*! RST_B_WKP - RESET_B Wakeup */
#define SMM_STAT_RST_B_WKP(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_STAT_RST_B_WKP_SHIFT)) & SMM_STAT_RST_B_WKP_MASK)

#define SMM_STAT_QCH_EN_MASK                     (0x1000U)
#define SMM_STAT_QCH_EN_SHIFT                    (12U)
/*! QCH_EN - Q channel timeout enable */
#define SMM_STAT_QCH_EN(x)                       (((uint32_t)(((uint32_t)(x)) << SMM_STAT_QCH_EN_SHIFT)) & SMM_STAT_QCH_EN_MASK)

#define SMM_STAT_QCH_INT_MASK                    (0x2000U)
#define SMM_STAT_QCH_INT_SHIFT                   (13U)
/*! QCH_INT - Q channel timeout interrupt */
#define SMM_STAT_QCH_INT(x)                      (((uint32_t)(((uint32_t)(x)) << SMM_STAT_QCH_INT_SHIFT)) & SMM_STAT_QCH_INT_MASK)

#define SMM_STAT_QCH_DNY_IE_MASK                 (0x4000U)
#define SMM_STAT_QCH_DNY_IE_SHIFT                (14U)
/*! QCH_DNY_IE - Q channel deny interrupt enable */
#define SMM_STAT_QCH_DNY_IE(x)                   (((uint32_t)(((uint32_t)(x)) << SMM_STAT_QCH_DNY_IE_SHIFT)) & SMM_STAT_QCH_DNY_IE_MASK)

#define SMM_STAT_QCH_DNY_INT_MASK                (0x8000U)
#define SMM_STAT_QCH_DNY_INT_SHIFT               (15U)
/*! QCH_DNY_INT - Q channel deny interrupt */
#define SMM_STAT_QCH_DNY_INT(x)                  (((uint32_t)(((uint32_t)(x)) << SMM_STAT_QCH_DNY_INT_SHIFT)) & SMM_STAT_QCH_DNY_INT_MASK)
/*! @} */

/*! @name PWDN_CONFIG - Power Down configuration */
/*! @{ */

#define SMM_PWDN_CONFIG_DPD_STRT_MASK            (0x1U)
#define SMM_PWDN_CONFIG_DPD_STRT_SHIFT           (0U)
/*! DPD_STRT - Start */
#define SMM_PWDN_CONFIG_DPD_STRT(x)              (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_DPD_STRT_SHIFT)) & SMM_PWDN_CONFIG_DPD_STRT_MASK)

#define SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_MASK     (0x2U)
#define SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_SHIFT    (1U)
/*! DPD1_VDD1P1_SRC - DPD1 VDD1P1 power supply
 *  0b0..Keep as is
 *  0b1..Move to Low Power mode of the DCDC fixed.
 */
#define SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC(x)       (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_SHIFT)) & SMM_PWDN_CONFIG_DPD1_VDD1P1_SRC_MASK)

#define SMM_PWDN_CONFIG_ADVC2P0_DPD2_ACT_MASK    (0x4U)
#define SMM_PWDN_CONFIG_ADVC2P0_DPD2_ACT_SHIFT   (2U)
/*! ADVC2P0_DPD2_ACT - ADVC2P0 DPD2 active */
#define SMM_PWDN_CONFIG_ADVC2P0_DPD2_ACT(x)      (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_ADVC2P0_DPD2_ACT_SHIFT)) & SMM_PWDN_CONFIG_ADVC2P0_DPD2_ACT_MASK)

#define SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_MASK     (0x8U)
#define SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_SHIFT    (3U)
/*! BGR_DSBL_DPD_PD - BGR disable
 *  0b0..Disable
 *  0b1..Enable
 */
#define SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD(x)       (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_SHIFT)) & SMM_PWDN_CONFIG_BGR_DSBL_DPD_PD_MASK)

#define SMM_PWDN_CONFIG_DPD3_SHTDWN_MASK         (0x20U)
#define SMM_PWDN_CONFIG_DPD3_SHTDWN_SHIFT        (5U)
/*! DPD3_SHTDWN - Shutdown */
#define SMM_PWDN_CONFIG_DPD3_SHTDWN(x)           (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_DPD3_SHTDWN_SHIFT)) & SMM_PWDN_CONFIG_DPD3_SHTDWN_MASK)

#define SMM_PWDN_CONFIG_DPD2_AON_MASK            (0x40U)
#define SMM_PWDN_CONFIG_DPD2_AON_SHIFT           (6U)
/*! DPD2_AON - DPD2 AON */
#define SMM_PWDN_CONFIG_DPD2_AON(x)              (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_DPD2_AON_SHIFT)) & SMM_PWDN_CONFIG_DPD2_AON_MASK)

#define SMM_PWDN_CONFIG_DPD_ABRT_MASK            (0x80U)
#define SMM_PWDN_CONFIG_DPD_ABRT_SHIFT           (7U)
/*! DPD_ABRT - Abort Deep Sleep Power Down */
#define SMM_PWDN_CONFIG_DPD_ABRT(x)              (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_DPD_ABRT_SHIFT)) & SMM_PWDN_CONFIG_DPD_ABRT_MASK)

#define SMM_PWDN_CONFIG_Q_TMT_EN_MASK            (0x100U)
#define SMM_PWDN_CONFIG_Q_TMT_EN_SHIFT           (8U)
/*! Q_TMT_EN - Q timeout enable */
#define SMM_PWDN_CONFIG_Q_TMT_EN(x)              (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_Q_TMT_EN_SHIFT)) & SMM_PWDN_CONFIG_Q_TMT_EN_MASK)

#define SMM_PWDN_CONFIG_AON_DPD_SL_CLK_MASK      (0x200U)
#define SMM_PWDN_CONFIG_AON_DPD_SL_CLK_SHIFT     (9U)
/*! AON_DPD_SL_CLK - AON Deep Sleep and Deep Power Down slow clock
 *  0b0..Move to 32KHz at DPD2
 *  0b1..Remain at AON_CLK at DPD2
 */
#define SMM_PWDN_CONFIG_AON_DPD_SL_CLK(x)        (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_AON_DPD_SL_CLK_SHIFT)) & SMM_PWDN_CONFIG_AON_DPD_SL_CLK_MASK)

#define SMM_PWDN_CONFIG_WKUP_CPU_M_MASK          (0x400U)
#define SMM_PWDN_CONFIG_WKUP_CPU_M_SHIFT         (10U)
/*! WKUP_CPU_M - Wakeup main CPU */
#define SMM_PWDN_CONFIG_WKUP_CPU_M(x)            (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_WKUP_CPU_M_SHIFT)) & SMM_PWDN_CONFIG_WKUP_CPU_M_MASK)

#define SMM_PWDN_CONFIG_SRAM_CNTRL_MASK          (0x3800U)
#define SMM_PWDN_CONFIG_SRAM_CNTRL_SHIFT         (11U)
/*! SRAM_CNTRL - SRAM Bn PS control */
#define SMM_PWDN_CONFIG_SRAM_CNTRL(x)            (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_SRAM_CNTRL_SHIFT)) & SMM_PWDN_CONFIG_SRAM_CNTRL_MASK)

#define SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK      (0x4000U)
#define SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_SHIFT     (14U)
/*! CTRL_SRAM_DPD2 - SRAM Bn PS control during DPD2 */
#define SMM_PWDN_CONFIG_CTRL_SRAM_DPD2(x)        (((uint32_t)(((uint32_t)(x)) << SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_SHIFT)) & SMM_PWDN_CONFIG_CTRL_SRAM_DPD2_MASK)
/*! @} */

/*! @name DPSLP_COUNT - Deep Sleep count */
/*! @{ */

#define SMM_DPSLP_COUNT_DPSLP_CNT_MASK           (0xFFFFU)
#define SMM_DPSLP_COUNT_DPSLP_CNT_SHIFT          (0U)
/*! DPSLP_CNT - Deep Sleep counter */
#define SMM_DPSLP_COUNT_DPSLP_CNT(x)             (((uint32_t)(((uint32_t)(x)) << SMM_DPSLP_COUNT_DPSLP_CNT_SHIFT)) & SMM_DPSLP_COUNT_DPSLP_CNT_MASK)
/*! @} */

/*! @name RTC_DCDC_CNTRL - RTC DCDC Control */
/*! @{ */

#define SMM_RTC_DCDC_CNTRL_LDO_CONFIG_MASK       (0x3FU)
#define SMM_RTC_DCDC_CNTRL_LDO_CONFIG_SHIFT      (0U)
/*! LDO_CONFIG - RTC LP LDO voltage configuration */
#define SMM_RTC_DCDC_CNTRL_LDO_CONFIG(x)         (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_LDO_CONFIG_SHIFT)) & SMM_RTC_DCDC_CNTRL_LDO_CONFIG_MASK)

#define SMM_RTC_DCDC_CNTRL_LDO_EN_MASK           (0x40U)
#define SMM_RTC_DCDC_CNTRL_LDO_EN_SHIFT          (6U)
/*! LDO_EN - RTC LDO enable */
#define SMM_RTC_DCDC_CNTRL_LDO_EN(x)             (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_LDO_EN_SHIFT)) & SMM_RTC_DCDC_CNTRL_LDO_EN_MASK)

#define SMM_RTC_DCDC_CNTRL_ANA_RESET_N_MASK      (0x200U)
#define SMM_RTC_DCDC_CNTRL_ANA_RESET_N_SHIFT     (9U)
/*! ANA_RESET_N - RTC analog reset */
#define SMM_RTC_DCDC_CNTRL_ANA_RESET_N(x)        (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_ANA_RESET_N_SHIFT)) & SMM_RTC_DCDC_CNTRL_ANA_RESET_N_MASK)

#define SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK       (0x400U)
#define SMM_RTC_DCDC_CNTRL_DGTL_RST_N_SHIFT      (10U)
/*! DGTL_RST_N - RTC digital block reset */
#define SMM_RTC_DCDC_CNTRL_DGTL_RST_N(x)         (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_DGTL_RST_N_SHIFT)) & SMM_RTC_DCDC_CNTRL_DGTL_RST_N_MASK)

#define SMM_RTC_DCDC_CNTRL_ISO_MASK              (0x800U)
#define SMM_RTC_DCDC_CNTRL_ISO_SHIFT             (11U)
/*! ISO - RTC ISO signal */
#define SMM_RTC_DCDC_CNTRL_ISO(x)                (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_ISO_SHIFT)) & SMM_RTC_DCDC_CNTRL_ISO_MASK)

#define SMM_RTC_DCDC_CNTRL_STOP_DIG_CLK_MASK     (0x1000U)
#define SMM_RTC_DCDC_CNTRL_STOP_DIG_CLK_SHIFT    (12U)
/*! STOP_DIG_CLK - Stop digital clock */
#define SMM_RTC_DCDC_CNTRL_STOP_DIG_CLK(x)       (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_STOP_DIG_CLK_SHIFT)) & SMM_RTC_DCDC_CNTRL_STOP_DIG_CLK_MASK)

#define SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_MASK    (0x2000U)
#define SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_SHIFT   (13U)
/*! LDO_PULDWN_EN - RTC LDO pulldown */
#define SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN(x)      (((uint32_t)(((uint32_t)(x)) << SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_SHIFT)) & SMM_RTC_DCDC_CNTRL_LDO_PULDWN_EN_MASK)
/*! @} */

/*! @name RTC_XTAL_CONFG1 - RTC analog XTAL configuration */
/*! @{ */

#define SMM_RTC_XTAL_CONFG1_XTAL_EN_MASK         (0x1U)
#define SMM_RTC_XTAL_CONFG1_XTAL_EN_SHIFT        (0U)
/*! XTAL_EN - XTAL enable */
#define SMM_RTC_XTAL_CONFG1_XTAL_EN(x)           (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG1_XTAL_EN_SHIFT)) & SMM_RTC_XTAL_CONFG1_XTAL_EN_MASK)

#define SMM_RTC_XTAL_CONFG1_AMPSEL_MASK          (0x6U)
#define SMM_RTC_XTAL_CONFG1_AMPSEL_SHIFT         (1U)
/*! AMPSEL - XTAL AMPSEL */
#define SMM_RTC_XTAL_CONFG1_AMPSEL(x)            (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG1_AMPSEL_SHIFT)) & SMM_RTC_XTAL_CONFG1_AMPSEL_MASK)

#define SMM_RTC_XTAL_CONFG1_CMP_IBIAS_SOX_MASK   (0x3800U)
#define SMM_RTC_XTAL_CONFG1_CMP_IBIAS_SOX_SHIFT  (11U)
/*! CMP_IBIAS_SOX - XTAL CMP IBIAS SOX */
#define SMM_RTC_XTAL_CONFG1_CMP_IBIAS_SOX(x)     (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG1_CMP_IBIAS_SOX_SHIFT)) & SMM_RTC_XTAL_CONFG1_CMP_IBIAS_SOX_MASK)

#define SMM_RTC_XTAL_CONFG1_FAIL_RST_EN_MASK     (0x4000U)
#define SMM_RTC_XTAL_CONFG1_FAIL_RST_EN_SHIFT    (14U)
/*! FAIL_RST_EN - Enable XTAL fail reset */
#define SMM_RTC_XTAL_CONFG1_FAIL_RST_EN(x)       (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG1_FAIL_RST_EN_SHIFT)) & SMM_RTC_XTAL_CONFG1_FAIL_RST_EN_MASK)

#define SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN_MASK    (0x8000U)
#define SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN_SHIFT   (15U)
/*! CRNT_MROR_EN - RTC current mirror enable */
#define SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN(x)      (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN_SHIFT)) & SMM_RTC_XTAL_CONFG1_CRNT_MROR_EN_MASK)
/*! @} */

/*! @name RTC_XTAL_CONFG2 - RTC analog XTAL configuration */
/*! @{ */

#define SMM_RTC_XTAL_CONFG2_DLY_IBIAS_SOX_MASK   (0xFU)
#define SMM_RTC_XTAL_CONFG2_DLY_IBIAS_SOX_SHIFT  (0U)
/*! DLY_IBIAS_SOX - DLY IBIAS SOX */
#define SMM_RTC_XTAL_CONFG2_DLY_IBIAS_SOX(x)     (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_DLY_IBIAS_SOX_SHIFT)) & SMM_RTC_XTAL_CONFG2_DLY_IBIAS_SOX_MASK)

#define SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_MASK      (0x10U)
#define SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_SHIFT     (4U)
/*! CAP_BNK_EN - XTAL AMPSEL */
#define SMM_RTC_XTAL_CONFG2_CAP_BNK_EN(x)        (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_SHIFT)) & SMM_RTC_XTAL_CONFG2_CAP_BNK_EN_MASK)

#define SMM_RTC_XTAL_CONFG2_SOX_EN_MASK          (0x20U)
#define SMM_RTC_XTAL_CONFG2_SOX_EN_SHIFT         (5U)
/*! SOX_EN - Switching mode control enable */
#define SMM_RTC_XTAL_CONFG2_SOX_EN(x)            (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_SOX_EN_SHIFT)) & SMM_RTC_XTAL_CONFG2_SOX_EN_MASK)

#define SMM_RTC_XTAL_CONFG2_GMSEL_MASK           (0xC0U)
#define SMM_RTC_XTAL_CONFG2_GMSEL_SHIFT          (6U)
/*! GMSEL - Selects the GM setting */
#define SMM_RTC_XTAL_CONFG2_GMSEL(x)             (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_GMSEL_SHIFT)) & SMM_RTC_XTAL_CONFG2_GMSEL_MASK)

#define SMM_RTC_XTAL_CONFG2_HYSTEL_MASK          (0x100U)
#define SMM_RTC_XTAL_CONFG2_HYSTEL_SHIFT         (8U)
/*! HYSTEL - Hysteresis value for Schmitt trigger */
#define SMM_RTC_XTAL_CONFG2_HYSTEL(x)            (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_HYSTEL_SHIFT)) & SMM_RTC_XTAL_CONFG2_HYSTEL_MASK)

#define SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX_MASK   (0x600U)
#define SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX_SHIFT  (9U)
/*! SUPDET_TM_SOX - SUPDET TM SOX */
#define SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX(x)     (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX_SHIFT)) & SMM_RTC_XTAL_CONFG2_SUPDET_TM_SOX_MASK)

#define SMM_RTC_XTAL_CONFG2_XTM_MASK             (0x800U)
#define SMM_RTC_XTAL_CONFG2_XTM_SHIFT            (11U)
/*! XTM - XTM */
#define SMM_RTC_XTAL_CONFG2_XTM(x)               (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_XTM_SHIFT)) & SMM_RTC_XTAL_CONFG2_XTM_MASK)

#define SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX_MASK     (0x7000U)
#define SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX_SHIFT    (12U)
/*! DLY_CAP_SOX - DLY CAP SOX */
#define SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX(x)       (((uint32_t)(((uint32_t)(x)) << SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX_SHIFT)) & SMM_RTC_XTAL_CONFG2_DLY_CAP_SOX_MASK)
/*! @} */

/*! @name LSB_BCKP1 - Backup LSB1 */
/*! @{ */

#define SMM_LSB_BCKP1_LSB1_MASK                  (0xFFFFU)
#define SMM_LSB_BCKP1_LSB1_SHIFT                 (0U)
/*! LSB1 - LSB1 */
#define SMM_LSB_BCKP1_LSB1(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_LSB_BCKP1_LSB1_SHIFT)) & SMM_LSB_BCKP1_LSB1_MASK)
/*! @} */

/*! @name MSB_BCKP1 - Backup MSB1 */
/*! @{ */

#define SMM_MSB_BCKP1_MSB1_MASK                  (0xFFFFU)
#define SMM_MSB_BCKP1_MSB1_SHIFT                 (0U)
/*! MSB1 - MSB1 */
#define SMM_MSB_BCKP1_MSB1(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_MSB_BCKP1_MSB1_SHIFT)) & SMM_MSB_BCKP1_MSB1_MASK)
/*! @} */

/*! @name LSB_BCKP2 - Backup LSB2 */
/*! @{ */

#define SMM_LSB_BCKP2_LSB2_MASK                  (0xFFFFU)
#define SMM_LSB_BCKP2_LSB2_SHIFT                 (0U)
/*! LSB2 - LSB2 */
#define SMM_LSB_BCKP2_LSB2(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_LSB_BCKP2_LSB2_SHIFT)) & SMM_LSB_BCKP2_LSB2_MASK)
/*! @} */

/*! @name MSB_BCKP2 - Backup MSB2 */
/*! @{ */

#define SMM_MSB_BCKP2_MSB2_MASK                  (0xFFFFU)
#define SMM_MSB_BCKP2_MSB2_SHIFT                 (0U)
/*! MSB2 - MSB2 */
#define SMM_MSB_BCKP2_MSB2(x)                    (((uint32_t)(((uint32_t)(x)) << SMM_MSB_BCKP2_MSB2_SHIFT)) & SMM_MSB_BCKP2_MSB2_MASK)
/*! @} */

/*! @name MEMORY_RTN - Memory retain */
/*! @{ */

#define SMM_MEMORY_RTN_RETAIN_EN_MASK            (0x1U)
#define SMM_MEMORY_RTN_RETAIN_EN_SHIFT           (0U)
/*! RETAIN_EN - Retain enable */
#define SMM_MEMORY_RTN_RETAIN_EN(x)              (((uint32_t)(((uint32_t)(x)) << SMM_MEMORY_RTN_RETAIN_EN_SHIFT)) & SMM_MEMORY_RTN_RETAIN_EN_MASK)

#define SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET_MASK    (0x3FEU)
#define SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET_SHIFT   (1U)
/*! MAIN_CPU_SRAM_RET - SRAM retain */
#define SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET(x)      (((uint32_t)(((uint32_t)(x)) << SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET_SHIFT)) & SMM_MEMORY_RTN_MAIN_CPU_SRAM_RET_MASK)

#define SMM_MEMORY_RTN_CPU_RAM_PWD_MASK          (0x1C00U)
#define SMM_MEMORY_RTN_CPU_RAM_PWD_SHIFT         (10U)
/*! CPU_RAM_PWD - AON CPU core RAM powerdown */
#define SMM_MEMORY_RTN_CPU_RAM_PWD(x)            (((uint32_t)(((uint32_t)(x)) << SMM_MEMORY_RTN_CPU_RAM_PWD_SHIFT)) & SMM_MEMORY_RTN_CPU_RAM_PWD_MASK)

#define SMM_MEMORY_RTN_IVS_EN_MASK               (0x4000U)
#define SMM_MEMORY_RTN_IVS_EN_SHIFT              (14U)
/*! IVS_EN - IVS enable */
#define SMM_MEMORY_RTN_IVS_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SMM_MEMORY_RTN_IVS_EN_SHIFT)) & SMM_MEMORY_RTN_IVS_EN_MASK)
/*! @} */

/*! @name BIAS_CTRL - RTC analog XTAL bias control */
/*! @{ */

#define SMM_BIAS_CTRL_BIAS_EN_MASK               (0x1U)
#define SMM_BIAS_CTRL_BIAS_EN_SHIFT              (0U)
/*! BIAS_EN - Enable XTAL */
#define SMM_BIAS_CTRL_BIAS_EN(x)                 (((uint32_t)(((uint32_t)(x)) << SMM_BIAS_CTRL_BIAS_EN_SHIFT)) & SMM_BIAS_CTRL_BIAS_EN_MASK)

#define SMM_BIAS_CTRL_COARSE_MASK                (0x3CU)
#define SMM_BIAS_CTRL_COARSE_SHIFT               (2U)
/*! COARSE - Coarse value */
#define SMM_BIAS_CTRL_COARSE(x)                  (((uint32_t)(((uint32_t)(x)) << SMM_BIAS_CTRL_COARSE_SHIFT)) & SMM_BIAS_CTRL_COARSE_MASK)

#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_1na_MASK (0x400U)
#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_1na_SHIFT (10U)
/*! en_osc_iref_cm_trim_1na - en_osc_iref_cm_trim_1na */
#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_1na(x) (((uint32_t)(((uint32_t)(x)) << SMM_BIAS_CTRL_en_osc_iref_cm_trim_1na_SHIFT)) & SMM_BIAS_CTRL_en_osc_iref_cm_trim_1na_MASK)

#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_2na_MASK (0x800U)
#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_2na_SHIFT (11U)
/*! en_osc_iref_cm_trim_2na - en_osc_iref_cm_trim_2na */
#define SMM_BIAS_CTRL_en_osc_iref_cm_trim_2na(x) (((uint32_t)(((uint32_t)(x)) << SMM_BIAS_CTRL_en_osc_iref_cm_trim_2na_SHIFT)) & SMM_BIAS_CTRL_en_osc_iref_cm_trim_2na_MASK)

#define SMM_BIAS_CTRL_xtal_sox_4p_dis_MASK       (0x1000U)
#define SMM_BIAS_CTRL_xtal_sox_4p_dis_SHIFT      (12U)
/*! xtal_sox_4p_dis - xtal_sox_4p_dis */
#define SMM_BIAS_CTRL_xtal_sox_4p_dis(x)         (((uint32_t)(((uint32_t)(x)) << SMM_BIAS_CTRL_xtal_sox_4p_dis_SHIFT)) & SMM_BIAS_CTRL_xtal_sox_4p_dis_MASK)
/*! @} */

/*! @name XTAL_TRIM - XTAL Trim */
/*! @{ */

#define SMM_XTAL_TRIM_TRIM_DIR_MASK              (0x3FFU)
#define SMM_XTAL_TRIM_TRIM_DIR_SHIFT             (0U)
/*! TRIM_DIR - XTAL Trim interval */
#define SMM_XTAL_TRIM_TRIM_DIR(x)                (((uint32_t)(((uint32_t)(x)) << SMM_XTAL_TRIM_TRIM_DIR_SHIFT)) & SMM_XTAL_TRIM_TRIM_DIR_MASK)

#define SMM_XTAL_TRIM_TRIM_VAL_MASK              (0x400U)
#define SMM_XTAL_TRIM_TRIM_VAL_SHIFT             (10U)
/*! TRIM_VAL - XTAL Trim up */
#define SMM_XTAL_TRIM_TRIM_VAL(x)                (((uint32_t)(((uint32_t)(x)) << SMM_XTAL_TRIM_TRIM_VAL_SHIFT)) & SMM_XTAL_TRIM_TRIM_VAL_MASK)
/*! @} */

/*! @name TAMP_CTRL - Tamper Control */
/*! @{ */

#define SMM_TAMP_CTRL_READ_CNTR_STRT_MASK        (0x80U)
#define SMM_TAMP_CTRL_READ_CNTR_STRT_SHIFT       (7U)
/*! READ_CNTR_STRT - Read RTC Counter Latched Start */
#define SMM_TAMP_CTRL_READ_CNTR_STRT(x)          (((uint32_t)(((uint32_t)(x)) << SMM_TAMP_CTRL_READ_CNTR_STRT_SHIFT)) & SMM_TAMP_CTRL_READ_CNTR_STRT_MASK)

#define SMM_TAMP_CTRL_READ_SEC_KEY_MASK          (0x100U)
#define SMM_TAMP_CTRL_READ_SEC_KEY_SHIFT         (8U)
/*! READ_SEC_KEY - Read Secure Key Start */
#define SMM_TAMP_CTRL_READ_SEC_KEY(x)            (((uint32_t)(((uint32_t)(x)) << SMM_TAMP_CTRL_READ_SEC_KEY_SHIFT)) & SMM_TAMP_CTRL_READ_SEC_KEY_MASK)

#define SMM_TAMP_CTRL_READ_CNTR_READY_MASK       (0x200U)
#define SMM_TAMP_CTRL_READ_CNTR_READY_SHIFT      (9U)
/*! READ_CNTR_READY - Read RTC Counter Latched Ready */
#define SMM_TAMP_CTRL_READ_CNTR_READY(x)         (((uint32_t)(((uint32_t)(x)) << SMM_TAMP_CTRL_READ_CNTR_READY_SHIFT)) & SMM_TAMP_CTRL_READ_CNTR_READY_MASK)

#define SMM_TAMP_CTRL_SEC_KEY_READY_MASK         (0x400U)
#define SMM_TAMP_CTRL_SEC_KEY_READY_SHIFT        (10U)
/*! SEC_KEY_READY - Secure Key Ready */
#define SMM_TAMP_CTRL_SEC_KEY_READY(x)           (((uint32_t)(((uint32_t)(x)) << SMM_TAMP_CTRL_SEC_KEY_READY_SHIFT)) & SMM_TAMP_CTRL_SEC_KEY_READY_MASK)

#define SMM_TAMP_CTRL_TEMP_DET_MASK              (0x3000U)
#define SMM_TAMP_CTRL_TEMP_DET_SHIFT             (12U)
/*! TEMP_DET - Tamper Detected */
#define SMM_TAMP_CTRL_TEMP_DET(x)                (((uint32_t)(((uint32_t)(x)) << SMM_TAMP_CTRL_TEMP_DET_SHIFT)) & SMM_TAMP_CTRL_TEMP_DET_MASK)
/*! @} */

/*! @name LATCHED_RTC_COUNTER - Latched RTC Counter */
/*! @{ */

#define SMM_LATCHED_RTC_COUNTER_Latched_RTC_Counter_MASK (0xFFFFU)
#define SMM_LATCHED_RTC_COUNTER_Latched_RTC_Counter_SHIFT (0U)
/*! Latched_RTC_Counter - Latched_RTC_Counter[x+15:x] */
#define SMM_LATCHED_RTC_COUNTER_Latched_RTC_Counter(x) (((uint32_t)(((uint32_t)(x)) << SMM_LATCHED_RTC_COUNTER_Latched_RTC_Counter_SHIFT)) & SMM_LATCHED_RTC_COUNTER_Latched_RTC_Counter_MASK)
/*! @} */

/* The count of SMM_LATCHED_RTC_COUNTER */
#define SMM_LATCHED_RTC_COUNTER_COUNT            (3U)


/*!
 * @}
 */ /* end of group SMM_Register_Masks */


/*!
 * @}
 */ /* end of group SMM_Peripheral_Access_Layer */


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


#endif  /* PERI_SMM_H_ */

