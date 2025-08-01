/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EMC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EMC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EMC
 *
 * CMSIS Peripheral Access Layer for EMC
 */

#if !defined(PERI_EMC_H_)
#define PERI_EMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- EMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMC_Peripheral_Access_Layer EMC Peripheral Access Layer
 * @{
 */

/** EMC - Size of Registers Arrays */
#define EMC_DYNAMIC_COUNT                         4u
#define EMC_STATIC_COUNT                          4u

/** EMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTROL;                           /**< Controls operation of the memory controller, offset: 0x0 */
  __I  uint32_t STATUS;                            /**< Provides EMC status information, offset: 0x4 */
  __IO uint32_t CONFIG;                            /**< Configures operation of the memory controller, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t DYNAMICCONTROL;                    /**< Controls dynamic memory operation, offset: 0x20 */
  __IO uint32_t DYNAMICREFRESH;                    /**< Configures dynamic memory refresh, offset: 0x24 */
  __IO uint32_t DYNAMICREADCONFIG;                 /**< Configures dynamic memory read strategy, offset: 0x28 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DYNAMICRP;                         /**< Precharge command period, offset: 0x30 */
  __IO uint32_t DYNAMICRAS;                        /**< Active to precharge command period, offset: 0x34 */
  __IO uint32_t DYNAMICSREX;                       /**< Self-refresh exit time, offset: 0x38 */
  __IO uint32_t DYNAMICAPR;                        /**< Last-data-out to active command time, offset: 0x3C */
  __IO uint32_t DYNAMICDAL;                        /**< Data-in to active command time, offset: 0x40 */
  __IO uint32_t DYNAMICWR;                         /**< Write recovery time, offset: 0x44 */
  __IO uint32_t DYNAMICRC;                         /**< Selects the active to active command period, offset: 0x48 */
  __IO uint32_t DYNAMICRFC;                        /**< Selects the auto-refresh period, offset: 0x4C */
  __IO uint32_t DYNAMICXSR;                        /**< Time for exit self-refresh to active command, offset: 0x50 */
  __IO uint32_t DYNAMICRRD;                        /**< Latency for active bank A to active bank B, offset: 0x54 */
  __IO uint32_t DYNAMICMRD;                        /**< Time for load mode register to active command, offset: 0x58 */
       uint8_t RESERVED_2[36];
  __IO uint32_t STATICEXTENDEDWAIT;                /**< Time for long static memory read and write transfers, offset: 0x80 */
       uint8_t RESERVED_3[124];
  struct {                                         /* offset: 0x100, array step: 0x20 */
    __IO uint32_t DYNAMICCONFIG;                     /**< Configuration information for EMC_DYCSx, array offset: 0x100, array step: 0x20 */
    __IO uint32_t DYNAMICRASCAS;                     /**< RAS and CAS latencies for EMC_DYCSx, array offset: 0x104, array step: 0x20 */
         uint8_t RESERVED_0[24];
  } DYNAMIC[EMC_DYNAMIC_COUNT];
       uint8_t RESERVED_4[128];
  struct {                                         /* offset: 0x200, array step: 0x20 */
    __IO uint32_t STATICCONFIG;                      /**< Configuration for EMC_CSx, array offset: 0x200, array step: 0x20 */
    __IO uint32_t STATICWAITWEN;                     /**< Delay from EMC_CSx to write enable, array offset: 0x204, array step: 0x20 */
    __IO uint32_t STATICWAITOEN;                     /**< Delay from EMC_CSx or address change, whichever is later, to output enable, array offset: 0x208, array step: 0x20 */
    __IO uint32_t STATICWAITRD;                      /**< Delay from EMC_CSx to a read access, array offset: 0x20C, array step: 0x20 */
    __IO uint32_t STATICWAITPAGE;                    /**< Delay for asynchronous page mode sequential accesses for EMC_CSx, array offset: 0x210, array step: 0x20 */
    __IO uint32_t STATICWAITWR;                      /**< Delay from EMC_CSx to a write access, array offset: 0x214, array step: 0x20 */
    __IO uint32_t STATICWAITTURN;                    /**< Number of bus turnaround cycles EMC_CSx, array offset: 0x218, array step: 0x20 */
         uint8_t RESERVED_0[4];
  } STATIC[EMC_STATIC_COUNT];
} EMC_Type;

/* ----------------------------------------------------------------------------
   -- EMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EMC_Register_Masks EMC Register Masks
 * @{
 */

/*! @name CONTROL - Controls operation of the memory controller */
/*! @{ */

#define EMC_CONTROL_E_MASK                       (0x1U)
#define EMC_CONTROL_E_SHIFT                      (0U)
/*! E - EMC Enable. */
#define EMC_CONTROL_E(x)                         (((uint32_t)(((uint32_t)(x)) << EMC_CONTROL_E_SHIFT)) & EMC_CONTROL_E_MASK)

#define EMC_CONTROL_M_MASK                       (0x2U)
#define EMC_CONTROL_M_SHIFT                      (1U)
/*! M - Address mirror. */
#define EMC_CONTROL_M(x)                         (((uint32_t)(((uint32_t)(x)) << EMC_CONTROL_M_SHIFT)) & EMC_CONTROL_M_MASK)

#define EMC_CONTROL_L_MASK                       (0x4U)
#define EMC_CONTROL_L_SHIFT                      (2U)
/*! L - Low-power mode. */
#define EMC_CONTROL_L(x)                         (((uint32_t)(((uint32_t)(x)) << EMC_CONTROL_L_SHIFT)) & EMC_CONTROL_L_MASK)
/*! @} */

/*! @name STATUS - Provides EMC status information */
/*! @{ */

#define EMC_STATUS_B_MASK                        (0x1U)
#define EMC_STATUS_B_SHIFT                       (0U)
/*! B - Busy. */
#define EMC_STATUS_B(x)                          (((uint32_t)(((uint32_t)(x)) << EMC_STATUS_B_SHIFT)) & EMC_STATUS_B_MASK)

#define EMC_STATUS_S_MASK                        (0x2U)
#define EMC_STATUS_S_SHIFT                       (1U)
/*! S - Write buffer status. */
#define EMC_STATUS_S(x)                          (((uint32_t)(((uint32_t)(x)) << EMC_STATUS_S_SHIFT)) & EMC_STATUS_S_MASK)

#define EMC_STATUS_SA_MASK                       (0x4U)
#define EMC_STATUS_SA_SHIFT                      (2U)
/*! SA - Self-refresh acknowledge. */
#define EMC_STATUS_SA(x)                         (((uint32_t)(((uint32_t)(x)) << EMC_STATUS_SA_SHIFT)) & EMC_STATUS_SA_MASK)
/*! @} */

/*! @name CONFIG - Configures operation of the memory controller */
/*! @{ */

#define EMC_CONFIG_EM_MASK                       (0x1U)
#define EMC_CONFIG_EM_SHIFT                      (0U)
/*! EM - Endian mode. */
#define EMC_CONFIG_EM(x)                         (((uint32_t)(((uint32_t)(x)) << EMC_CONFIG_EM_SHIFT)) & EMC_CONFIG_EM_MASK)

#define EMC_CONFIG_CLKR_MASK                     (0x100U)
#define EMC_CONFIG_CLKR_SHIFT                    (8U)
/*! CLKR - This bit must contain 0 for proper operation of the EMC. */
#define EMC_CONFIG_CLKR(x)                       (((uint32_t)(((uint32_t)(x)) << EMC_CONFIG_CLKR_SHIFT)) & EMC_CONFIG_CLKR_MASK)
/*! @} */

/*! @name DYNAMICCONTROL - Controls dynamic memory operation */
/*! @{ */

#define EMC_DYNAMICCONTROL_CE_MASK               (0x1U)
#define EMC_DYNAMICCONTROL_CE_SHIFT              (0U)
/*! CE - Dynamic memory clock enable. */
#define EMC_DYNAMICCONTROL_CE(x)                 (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICCONTROL_CE_SHIFT)) & EMC_DYNAMICCONTROL_CE_MASK)

#define EMC_DYNAMICCONTROL_CS_MASK               (0x2U)
#define EMC_DYNAMICCONTROL_CS_SHIFT              (1U)
/*! CS - Dynamic memory clock control. */
#define EMC_DYNAMICCONTROL_CS(x)                 (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICCONTROL_CS_SHIFT)) & EMC_DYNAMICCONTROL_CS_MASK)

#define EMC_DYNAMICCONTROL_SR_MASK               (0x4U)
#define EMC_DYNAMICCONTROL_SR_SHIFT              (2U)
/*! SR - Self-refresh request, EMCSREFREQ. */
#define EMC_DYNAMICCONTROL_SR(x)                 (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICCONTROL_SR_SHIFT)) & EMC_DYNAMICCONTROL_SR_MASK)

#define EMC_DYNAMICCONTROL_MMC_MASK              (0x20U)
#define EMC_DYNAMICCONTROL_MMC_SHIFT             (5U)
/*! MMC - Memory clock control. */
#define EMC_DYNAMICCONTROL_MMC(x)                (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICCONTROL_MMC_SHIFT)) & EMC_DYNAMICCONTROL_MMC_MASK)

#define EMC_DYNAMICCONTROL_I_MASK                (0x180U)
#define EMC_DYNAMICCONTROL_I_SHIFT               (7U)
/*! I - SDRAM initialization. */
#define EMC_DYNAMICCONTROL_I(x)                  (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICCONTROL_I_SHIFT)) & EMC_DYNAMICCONTROL_I_MASK)
/*! @} */

/*! @name DYNAMICREFRESH - Configures dynamic memory refresh */
/*! @{ */

#define EMC_DYNAMICREFRESH_REFRESH_MASK          (0x7FFU)
#define EMC_DYNAMICREFRESH_REFRESH_SHIFT         (0U)
/*! REFRESH - Refresh timer. */
#define EMC_DYNAMICREFRESH_REFRESH(x)            (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICREFRESH_REFRESH_SHIFT)) & EMC_DYNAMICREFRESH_REFRESH_MASK)
/*! @} */

/*! @name DYNAMICREADCONFIG - Configures dynamic memory read strategy */
/*! @{ */

#define EMC_DYNAMICREADCONFIG_RD_MASK            (0x3U)
#define EMC_DYNAMICREADCONFIG_RD_SHIFT           (0U)
/*! RD - Read data strategy. */
#define EMC_DYNAMICREADCONFIG_RD(x)              (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICREADCONFIG_RD_SHIFT)) & EMC_DYNAMICREADCONFIG_RD_MASK)
/*! @} */

/*! @name DYNAMICRP - Precharge command period */
/*! @{ */

#define EMC_DYNAMICRP_TRP_MASK                   (0xFU)
#define EMC_DYNAMICRP_TRP_SHIFT                  (0U)
/*! TRP - Precharge command period. */
#define EMC_DYNAMICRP_TRP(x)                     (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICRP_TRP_SHIFT)) & EMC_DYNAMICRP_TRP_MASK)
/*! @} */

/*! @name DYNAMICRAS - Active to precharge command period */
/*! @{ */

#define EMC_DYNAMICRAS_TRAS_MASK                 (0xFU)
#define EMC_DYNAMICRAS_TRAS_SHIFT                (0U)
/*! TRAS - Active to precharge command period. */
#define EMC_DYNAMICRAS_TRAS(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICRAS_TRAS_SHIFT)) & EMC_DYNAMICRAS_TRAS_MASK)
/*! @} */

/*! @name DYNAMICSREX - Self-refresh exit time */
/*! @{ */

#define EMC_DYNAMICSREX_TSREX_MASK               (0xFU)
#define EMC_DYNAMICSREX_TSREX_SHIFT              (0U)
/*! TSREX - Self-refresh exit time. */
#define EMC_DYNAMICSREX_TSREX(x)                 (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICSREX_TSREX_SHIFT)) & EMC_DYNAMICSREX_TSREX_MASK)
/*! @} */

/*! @name DYNAMICAPR - Last-data-out to active command time */
/*! @{ */

#define EMC_DYNAMICAPR_TAPR_MASK                 (0xFU)
#define EMC_DYNAMICAPR_TAPR_SHIFT                (0U)
/*! TAPR - Last-data-out to active command time. */
#define EMC_DYNAMICAPR_TAPR(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICAPR_TAPR_SHIFT)) & EMC_DYNAMICAPR_TAPR_MASK)
/*! @} */

/*! @name DYNAMICDAL - Data-in to active command time */
/*! @{ */

#define EMC_DYNAMICDAL_TDAL_MASK                 (0xFU)
#define EMC_DYNAMICDAL_TDAL_SHIFT                (0U)
/*! TDAL - Data-in to active command. */
#define EMC_DYNAMICDAL_TDAL(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICDAL_TDAL_SHIFT)) & EMC_DYNAMICDAL_TDAL_MASK)
/*! @} */

/*! @name DYNAMICWR - Write recovery time */
/*! @{ */

#define EMC_DYNAMICWR_TWR_MASK                   (0xFU)
#define EMC_DYNAMICWR_TWR_SHIFT                  (0U)
/*! TWR - Write recovery time. */
#define EMC_DYNAMICWR_TWR(x)                     (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICWR_TWR_SHIFT)) & EMC_DYNAMICWR_TWR_MASK)
/*! @} */

/*! @name DYNAMICRC - Selects the active to active command period */
/*! @{ */

#define EMC_DYNAMICRC_TRC_MASK                   (0x1FU)
#define EMC_DYNAMICRC_TRC_SHIFT                  (0U)
/*! TRC - Active to active command period. */
#define EMC_DYNAMICRC_TRC(x)                     (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICRC_TRC_SHIFT)) & EMC_DYNAMICRC_TRC_MASK)
/*! @} */

/*! @name DYNAMICRFC - Selects the auto-refresh period */
/*! @{ */

#define EMC_DYNAMICRFC_TRFC_MASK                 (0x1FU)
#define EMC_DYNAMICRFC_TRFC_SHIFT                (0U)
/*! TRFC - Auto-refresh period and auto-refresh to active command period. */
#define EMC_DYNAMICRFC_TRFC(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICRFC_TRFC_SHIFT)) & EMC_DYNAMICRFC_TRFC_MASK)
/*! @} */

/*! @name DYNAMICXSR - Time for exit self-refresh to active command */
/*! @{ */

#define EMC_DYNAMICXSR_TXSR_MASK                 (0x1FU)
#define EMC_DYNAMICXSR_TXSR_SHIFT                (0U)
/*! TXSR - Exit self-refresh to active command time. */
#define EMC_DYNAMICXSR_TXSR(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICXSR_TXSR_SHIFT)) & EMC_DYNAMICXSR_TXSR_MASK)
/*! @} */

/*! @name DYNAMICRRD - Latency for active bank A to active bank B */
/*! @{ */

#define EMC_DYNAMICRRD_TRRD_MASK                 (0xFU)
#define EMC_DYNAMICRRD_TRRD_SHIFT                (0U)
/*! TRRD - Active bank A to active bank B latency 0x0 - 0xE = n + 1 clock cycles. */
#define EMC_DYNAMICRRD_TRRD(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICRRD_TRRD_SHIFT)) & EMC_DYNAMICRRD_TRRD_MASK)
/*! @} */

/*! @name DYNAMICMRD - Time for load mode register to active command */
/*! @{ */

#define EMC_DYNAMICMRD_TMRD_MASK                 (0xFU)
#define EMC_DYNAMICMRD_TMRD_SHIFT                (0U)
/*! TMRD - Load mode register to active command time. */
#define EMC_DYNAMICMRD_TMRD(x)                   (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMICMRD_TMRD_SHIFT)) & EMC_DYNAMICMRD_TMRD_MASK)
/*! @} */

/*! @name STATICEXTENDEDWAIT - Time for long static memory read and write transfers */
/*! @{ */

#define EMC_STATICEXTENDEDWAIT_EXTENDEDWAIT_MASK (0x3FFU)
#define EMC_STATICEXTENDEDWAIT_EXTENDEDWAIT_SHIFT (0U)
/*! EXTENDEDWAIT - Extended wait time out. */
#define EMC_STATICEXTENDEDWAIT_EXTENDEDWAIT(x)   (((uint32_t)(((uint32_t)(x)) << EMC_STATICEXTENDEDWAIT_EXTENDEDWAIT_SHIFT)) & EMC_STATICEXTENDEDWAIT_EXTENDEDWAIT_MASK)
/*! @} */

/*! @name DYNAMIC_DYNAMICCONFIG - Configuration information for EMC_DYCSx */
/*! @{ */

#define EMC_DYNAMIC_DYNAMICCONFIG_MD_MASK        (0x18U)
#define EMC_DYNAMIC_DYNAMICCONFIG_MD_SHIFT       (3U)
/*! MD - Memory device. */
#define EMC_DYNAMIC_DYNAMICCONFIG_MD(x)          (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICCONFIG_MD_SHIFT)) & EMC_DYNAMIC_DYNAMICCONFIG_MD_MASK)

#define EMC_DYNAMIC_DYNAMICCONFIG_AM0_MASK       (0x1F80U)
#define EMC_DYNAMIC_DYNAMICCONFIG_AM0_SHIFT      (7U)
/*! AM0 - See Table 933. */
#define EMC_DYNAMIC_DYNAMICCONFIG_AM0(x)         (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICCONFIG_AM0_SHIFT)) & EMC_DYNAMIC_DYNAMICCONFIG_AM0_MASK)

#define EMC_DYNAMIC_DYNAMICCONFIG_AM1_MASK       (0x4000U)
#define EMC_DYNAMIC_DYNAMICCONFIG_AM1_SHIFT      (14U)
/*! AM1 - See Table 933. */
#define EMC_DYNAMIC_DYNAMICCONFIG_AM1(x)         (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICCONFIG_AM1_SHIFT)) & EMC_DYNAMIC_DYNAMICCONFIG_AM1_MASK)

#define EMC_DYNAMIC_DYNAMICCONFIG_B_MASK         (0x80000U)
#define EMC_DYNAMIC_DYNAMICCONFIG_B_SHIFT        (19U)
/*! B - Buffer enable. */
#define EMC_DYNAMIC_DYNAMICCONFIG_B(x)           (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICCONFIG_B_SHIFT)) & EMC_DYNAMIC_DYNAMICCONFIG_B_MASK)

#define EMC_DYNAMIC_DYNAMICCONFIG_P_MASK         (0x100000U)
#define EMC_DYNAMIC_DYNAMICCONFIG_P_SHIFT        (20U)
/*! P - Write protect. */
#define EMC_DYNAMIC_DYNAMICCONFIG_P(x)           (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICCONFIG_P_SHIFT)) & EMC_DYNAMIC_DYNAMICCONFIG_P_MASK)
/*! @} */

/* The count of EMC_DYNAMIC_DYNAMICCONFIG */
#define EMC_DYNAMIC_DYNAMICCONFIG_COUNT          (4U)

/*! @name DYNAMIC_DYNAMICRASCAS - RAS and CAS latencies for EMC_DYCSx */
/*! @{ */

#define EMC_DYNAMIC_DYNAMICRASCAS_RAS_MASK       (0x3U)
#define EMC_DYNAMIC_DYNAMICRASCAS_RAS_SHIFT      (0U)
/*! RAS - RAS latency (active to read/write delay). */
#define EMC_DYNAMIC_DYNAMICRASCAS_RAS(x)         (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICRASCAS_RAS_SHIFT)) & EMC_DYNAMIC_DYNAMICRASCAS_RAS_MASK)

#define EMC_DYNAMIC_DYNAMICRASCAS_CAS_MASK       (0x300U)
#define EMC_DYNAMIC_DYNAMICRASCAS_CAS_SHIFT      (8U)
/*! CAS - CAS latency. */
#define EMC_DYNAMIC_DYNAMICRASCAS_CAS(x)         (((uint32_t)(((uint32_t)(x)) << EMC_DYNAMIC_DYNAMICRASCAS_CAS_SHIFT)) & EMC_DYNAMIC_DYNAMICRASCAS_CAS_MASK)
/*! @} */

/* The count of EMC_DYNAMIC_DYNAMICRASCAS */
#define EMC_DYNAMIC_DYNAMICRASCAS_COUNT          (4U)

/*! @name STATIC_STATICCONFIG - Configuration for EMC_CSx */
/*! @{ */

#define EMC_STATIC_STATICCONFIG_MW_MASK          (0x3U)
#define EMC_STATIC_STATICCONFIG_MW_SHIFT         (0U)
/*! MW - Memory width. */
#define EMC_STATIC_STATICCONFIG_MW(x)            (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_MW_SHIFT)) & EMC_STATIC_STATICCONFIG_MW_MASK)

#define EMC_STATIC_STATICCONFIG_PM_MASK          (0x8U)
#define EMC_STATIC_STATICCONFIG_PM_SHIFT         (3U)
/*! PM - Page mode. */
#define EMC_STATIC_STATICCONFIG_PM(x)            (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_PM_SHIFT)) & EMC_STATIC_STATICCONFIG_PM_MASK)

#define EMC_STATIC_STATICCONFIG_PC_MASK          (0x40U)
#define EMC_STATIC_STATICCONFIG_PC_SHIFT         (6U)
/*! PC - Chip select polarity. */
#define EMC_STATIC_STATICCONFIG_PC(x)            (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_PC_SHIFT)) & EMC_STATIC_STATICCONFIG_PC_MASK)

#define EMC_STATIC_STATICCONFIG_PB_MASK          (0x80U)
#define EMC_STATIC_STATICCONFIG_PB_SHIFT         (7U)
/*! PB - Byte lane state. */
#define EMC_STATIC_STATICCONFIG_PB(x)            (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_PB_SHIFT)) & EMC_STATIC_STATICCONFIG_PB_MASK)

#define EMC_STATIC_STATICCONFIG_EW_MASK          (0x100U)
#define EMC_STATIC_STATICCONFIG_EW_SHIFT         (8U)
/*! EW - Extended wait (EW) uses the EMCStaticExtendedWait register to time both the read and write
 *    transfers rather than the EMCStaticWaitRd and EMCStaticWaitWr registers.
 */
#define EMC_STATIC_STATICCONFIG_EW(x)            (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_EW_SHIFT)) & EMC_STATIC_STATICCONFIG_EW_MASK)

#define EMC_STATIC_STATICCONFIG_B_MASK           (0x80000U)
#define EMC_STATIC_STATICCONFIG_B_SHIFT          (19U)
/*! B - Buffer enable [2]. */
#define EMC_STATIC_STATICCONFIG_B(x)             (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_B_SHIFT)) & EMC_STATIC_STATICCONFIG_B_MASK)

#define EMC_STATIC_STATICCONFIG_P_MASK           (0x100000U)
#define EMC_STATIC_STATICCONFIG_P_SHIFT          (20U)
/*! P - Write protect. */
#define EMC_STATIC_STATICCONFIG_P(x)             (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICCONFIG_P_SHIFT)) & EMC_STATIC_STATICCONFIG_P_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICCONFIG */
#define EMC_STATIC_STATICCONFIG_COUNT            (4U)

/*! @name STATIC_STATICWAITWEN - Delay from EMC_CSx to write enable */
/*! @{ */

#define EMC_STATIC_STATICWAITWEN_WAITWEN_MASK    (0xFU)
#define EMC_STATIC_STATICWAITWEN_WAITWEN_SHIFT   (0U)
/*! WAITWEN - Wait write enable. */
#define EMC_STATIC_STATICWAITWEN_WAITWEN(x)      (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITWEN_WAITWEN_SHIFT)) & EMC_STATIC_STATICWAITWEN_WAITWEN_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITWEN */
#define EMC_STATIC_STATICWAITWEN_COUNT           (4U)

/*! @name STATIC_STATICWAITOEN - Delay from EMC_CSx or address change, whichever is later, to output enable */
/*! @{ */

#define EMC_STATIC_STATICWAITOEN_WAITOEN_MASK    (0xFU)
#define EMC_STATIC_STATICWAITOEN_WAITOEN_SHIFT   (0U)
/*! WAITOEN - Wait output enable. */
#define EMC_STATIC_STATICWAITOEN_WAITOEN(x)      (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITOEN_WAITOEN_SHIFT)) & EMC_STATIC_STATICWAITOEN_WAITOEN_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITOEN */
#define EMC_STATIC_STATICWAITOEN_COUNT           (4U)

/*! @name STATIC_STATICWAITRD - Delay from EMC_CSx to a read access */
/*! @{ */

#define EMC_STATIC_STATICWAITRD_WAITRD_MASK      (0x1FU)
#define EMC_STATIC_STATICWAITRD_WAITRD_SHIFT     (0U)
/*! WAITRD - . */
#define EMC_STATIC_STATICWAITRD_WAITRD(x)        (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITRD_WAITRD_SHIFT)) & EMC_STATIC_STATICWAITRD_WAITRD_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITRD */
#define EMC_STATIC_STATICWAITRD_COUNT            (4U)

/*! @name STATIC_STATICWAITPAGE - Delay for asynchronous page mode sequential accesses for EMC_CSx */
/*! @{ */

#define EMC_STATIC_STATICWAITPAGE_WAITPAGE_MASK  (0x1FU)
#define EMC_STATIC_STATICWAITPAGE_WAITPAGE_SHIFT (0U)
/*! WAITPAGE - Asynchronous page mode read after the first read wait states. */
#define EMC_STATIC_STATICWAITPAGE_WAITPAGE(x)    (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITPAGE_WAITPAGE_SHIFT)) & EMC_STATIC_STATICWAITPAGE_WAITPAGE_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITPAGE */
#define EMC_STATIC_STATICWAITPAGE_COUNT          (4U)

/*! @name STATIC_STATICWAITWR - Delay from EMC_CSx to a write access */
/*! @{ */

#define EMC_STATIC_STATICWAITWR_WAITWR_MASK      (0x1FU)
#define EMC_STATIC_STATICWAITWR_WAITWR_SHIFT     (0U)
/*! WAITWR - Write wait states. */
#define EMC_STATIC_STATICWAITWR_WAITWR(x)        (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITWR_WAITWR_SHIFT)) & EMC_STATIC_STATICWAITWR_WAITWR_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITWR */
#define EMC_STATIC_STATICWAITWR_COUNT            (4U)

/*! @name STATIC_STATICWAITTURN - Number of bus turnaround cycles EMC_CSx */
/*! @{ */

#define EMC_STATIC_STATICWAITTURN_WAITTURN_MASK  (0xFU)
#define EMC_STATIC_STATICWAITTURN_WAITTURN_SHIFT (0U)
/*! WAITTURN - Bus turn-around cycles. */
#define EMC_STATIC_STATICWAITTURN_WAITTURN(x)    (((uint32_t)(((uint32_t)(x)) << EMC_STATIC_STATICWAITTURN_WAITTURN_SHIFT)) & EMC_STATIC_STATICWAITTURN_WAITTURN_MASK)
/*! @} */

/* The count of EMC_STATIC_STATICWAITTURN */
#define EMC_STATIC_STATICWAITTURN_COUNT          (4U)


/*!
 * @}
 */ /* end of group EMC_Register_Masks */


/*!
 * @}
 */ /* end of group EMC_Peripheral_Access_Layer */


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


#endif  /* PERI_EMC_H_ */

