/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDMAARM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SDMAARM.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SDMAARM
 *
 * CMSIS Peripheral Access Layer for SDMAARM
 */

#if !defined(PERI_SDMAARM_H_)
#define PERI_SDMAARM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- SDMAARM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMAARM_Peripheral_Access_Layer SDMAARM Peripheral Access Layer
 * @{
 */

/** SDMAARM - Size of Registers Arrays */
#define SDMAARM_SDMA_CHNPRI_COUNT                 32u
#define SDMAARM_CHNENBL_COUNT                     48u

/** SDMAARM - Register Layout Typedef */
typedef struct {
  __IO uint32_t MC0PTR;                            /**< Arm platform Channel 0 Pointer, offset: 0x0 */
  __IO uint32_t INTR;                              /**< Channel Interrupts, offset: 0x4 */
  __IO uint32_t STOP_STAT;                         /**< Channel Stop/Channel Status, offset: 0x8 */
  __IO uint32_t HSTART;                            /**< Channel Start, offset: 0xC */
  __IO uint32_t EVTOVR;                            /**< Channel Event Override, offset: 0x10 */
  __IO uint32_t DSPOVR;                            /**< Channel BP Override, offset: 0x14 */
  __IO uint32_t HOSTOVR;                           /**< Channel Arm platform Override, offset: 0x18 */
  __IO uint32_t EVTPEND;                           /**< Channel Event Pending, offset: 0x1C */
       uint8_t RESERVED_0[4];
  __I  uint32_t RESET;                             /**< Reset Register, offset: 0x24 */
  __I  uint32_t EVTERR;                            /**< DMA Request Error Register, offset: 0x28 */
  __IO uint32_t INTRMASK;                          /**< Channel Arm platform Interrupt Mask, offset: 0x2C */
  __I  uint32_t PSW;                               /**< Schedule Status, offset: 0x30 */
  __I  uint32_t EVTERRDBG;                         /**< DMA Request Error Register, offset: 0x34 */
  __IO uint32_t CONFIG;                            /**< Configuration Register, offset: 0x38 */
  __IO uint32_t SDMA_LOCK;                         /**< SDMA LOCK, offset: 0x3C */
  __IO uint32_t ONCE_ENB;                          /**< OnCE Enable, offset: 0x40 */
  __IO uint32_t ONCE_DATA;                         /**< OnCE Data Register, offset: 0x44 */
  __IO uint32_t ONCE_INSTR;                        /**< OnCE Instruction Register, offset: 0x48 */
  __I  uint32_t ONCE_STAT;                         /**< OnCE Status Register, offset: 0x4C */
  __IO uint32_t ONCE_CMD;                          /**< OnCE Command Register, offset: 0x50 */
       uint8_t RESERVED_1[4];
  __IO uint32_t ILLINSTADDR;                       /**< Illegal Instruction Trap Address, offset: 0x58 */
  __IO uint32_t CHN0ADDR;                          /**< Channel 0 Boot Address, offset: 0x5C */
  __I  uint32_t EVT_MIRROR;                        /**< DMA Requests, offset: 0x60 */
  __I  uint32_t EVT_MIRROR2;                       /**< DMA Requests 2, offset: 0x64 */
       uint8_t RESERVED_2[8];
  __IO uint32_t XTRIG_CONF1;                       /**< Cross-Trigger Events Configuration Register 1, offset: 0x70 */
  __IO uint32_t XTRIG_CONF2;                       /**< Cross-Trigger Events Configuration Register 2, offset: 0x74 */
       uint8_t RESERVED_3[136];
  __IO uint32_t SDMA_CHNPRI[SDMAARM_SDMA_CHNPRI_COUNT]; /**< Channel Priority Registers, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_4[128];
  __IO uint32_t CHNENBL[SDMAARM_CHNENBL_COUNT];    /**< Channel Enable RAM, array offset: 0x200, array step: 0x4 */
} SDMAARM_Type;

/* ----------------------------------------------------------------------------
   -- SDMAARM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDMAARM_Register_Masks SDMAARM Register Masks
 * @{
 */

/*! @name MC0PTR - Arm platform Channel 0 Pointer */
/*! @{ */

#define SDMAARM_MC0PTR_MC0PTR_MASK               (0xFFFFFFFFU)
#define SDMAARM_MC0PTR_MC0PTR_SHIFT              (0U)
#define SDMAARM_MC0PTR_MC0PTR(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_MC0PTR_MC0PTR_SHIFT)) & SDMAARM_MC0PTR_MC0PTR_MASK)
/*! @} */

/*! @name INTR - Channel Interrupts */
/*! @{ */

#define SDMAARM_INTR_HI_MASK                     (0xFFFFFFFFU)
#define SDMAARM_INTR_HI_SHIFT                    (0U)
#define SDMAARM_INTR_HI(x)                       (((uint32_t)(((uint32_t)(x)) << SDMAARM_INTR_HI_SHIFT)) & SDMAARM_INTR_HI_MASK)
/*! @} */

/*! @name STOP_STAT - Channel Stop/Channel Status */
/*! @{ */

#define SDMAARM_STOP_STAT_HE_MASK                (0xFFFFFFFFU)
#define SDMAARM_STOP_STAT_HE_SHIFT               (0U)
#define SDMAARM_STOP_STAT_HE(x)                  (((uint32_t)(((uint32_t)(x)) << SDMAARM_STOP_STAT_HE_SHIFT)) & SDMAARM_STOP_STAT_HE_MASK)
/*! @} */

/*! @name HSTART - Channel Start */
/*! @{ */

#define SDMAARM_HSTART_HSTART_HE_MASK            (0xFFFFFFFFU)
#define SDMAARM_HSTART_HSTART_HE_SHIFT           (0U)
#define SDMAARM_HSTART_HSTART_HE(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_HSTART_HSTART_HE_SHIFT)) & SDMAARM_HSTART_HSTART_HE_MASK)
/*! @} */

/*! @name EVTOVR - Channel Event Override */
/*! @{ */

#define SDMAARM_EVTOVR_EO_MASK                   (0xFFFFFFFFU)
#define SDMAARM_EVTOVR_EO_SHIFT                  (0U)
#define SDMAARM_EVTOVR_EO(x)                     (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVTOVR_EO_SHIFT)) & SDMAARM_EVTOVR_EO_MASK)
/*! @} */

/*! @name DSPOVR - Channel BP Override */
/*! @{ */

#define SDMAARM_DSPOVR_DO_MASK                   (0xFFFFFFFFU)
#define SDMAARM_DSPOVR_DO_SHIFT                  (0U)
/*! DO
 *  0b00000000000000000000000000000000..- Reserved
 *  0b00000000000000000000000000000001..- Reset value.
 */
#define SDMAARM_DSPOVR_DO(x)                     (((uint32_t)(((uint32_t)(x)) << SDMAARM_DSPOVR_DO_SHIFT)) & SDMAARM_DSPOVR_DO_MASK)
/*! @} */

/*! @name HOSTOVR - Channel Arm platform Override */
/*! @{ */

#define SDMAARM_HOSTOVR_HO_MASK                  (0xFFFFFFFFU)
#define SDMAARM_HOSTOVR_HO_SHIFT                 (0U)
#define SDMAARM_HOSTOVR_HO(x)                    (((uint32_t)(((uint32_t)(x)) << SDMAARM_HOSTOVR_HO_SHIFT)) & SDMAARM_HOSTOVR_HO_MASK)
/*! @} */

/*! @name EVTPEND - Channel Event Pending */
/*! @{ */

#define SDMAARM_EVTPEND_EP_MASK                  (0xFFFFFFFFU)
#define SDMAARM_EVTPEND_EP_SHIFT                 (0U)
#define SDMAARM_EVTPEND_EP(x)                    (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVTPEND_EP_SHIFT)) & SDMAARM_EVTPEND_EP_MASK)
/*! @} */

/*! @name RESET - Reset Register */
/*! @{ */

#define SDMAARM_RESET_RESET_MASK                 (0x1U)
#define SDMAARM_RESET_RESET_SHIFT                (0U)
#define SDMAARM_RESET_RESET(x)                   (((uint32_t)(((uint32_t)(x)) << SDMAARM_RESET_RESET_SHIFT)) & SDMAARM_RESET_RESET_MASK)

#define SDMAARM_RESET_RESCHED_MASK               (0x2U)
#define SDMAARM_RESET_RESCHED_SHIFT              (1U)
#define SDMAARM_RESET_RESCHED(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_RESET_RESCHED_SHIFT)) & SDMAARM_RESET_RESCHED_MASK)
/*! @} */

/*! @name EVTERR - DMA Request Error Register */
/*! @{ */

#define SDMAARM_EVTERR_CHNERR_MASK               (0xFFFFFFFFU)
#define SDMAARM_EVTERR_CHNERR_SHIFT              (0U)
#define SDMAARM_EVTERR_CHNERR(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVTERR_CHNERR_SHIFT)) & SDMAARM_EVTERR_CHNERR_MASK)
/*! @} */

/*! @name INTRMASK - Channel Arm platform Interrupt Mask */
/*! @{ */

#define SDMAARM_INTRMASK_HIMASK_MASK             (0xFFFFFFFFU)
#define SDMAARM_INTRMASK_HIMASK_SHIFT            (0U)
#define SDMAARM_INTRMASK_HIMASK(x)               (((uint32_t)(((uint32_t)(x)) << SDMAARM_INTRMASK_HIMASK_SHIFT)) & SDMAARM_INTRMASK_HIMASK_MASK)
/*! @} */

/*! @name PSW - Schedule Status */
/*! @{ */

#define SDMAARM_PSW_CCR_MASK                     (0xFU)
#define SDMAARM_PSW_CCR_SHIFT                    (0U)
#define SDMAARM_PSW_CCR(x)                       (((uint32_t)(((uint32_t)(x)) << SDMAARM_PSW_CCR_SHIFT)) & SDMAARM_PSW_CCR_MASK)

#define SDMAARM_PSW_CCP_MASK                     (0xF0U)
#define SDMAARM_PSW_CCP_SHIFT                    (4U)
/*! CCP
 *  0b0000..No running channel
 *  0b0001..Active channel priority
 */
#define SDMAARM_PSW_CCP(x)                       (((uint32_t)(((uint32_t)(x)) << SDMAARM_PSW_CCP_SHIFT)) & SDMAARM_PSW_CCP_MASK)

#define SDMAARM_PSW_NCR_MASK                     (0x1F00U)
#define SDMAARM_PSW_NCR_SHIFT                    (8U)
#define SDMAARM_PSW_NCR(x)                       (((uint32_t)(((uint32_t)(x)) << SDMAARM_PSW_NCR_SHIFT)) & SDMAARM_PSW_NCR_MASK)

#define SDMAARM_PSW_NCP_MASK                     (0xE000U)
#define SDMAARM_PSW_NCP_SHIFT                    (13U)
/*! NCP
 *  0b000..No running channel
 *  0b001..Active channel priority
 */
#define SDMAARM_PSW_NCP(x)                       (((uint32_t)(((uint32_t)(x)) << SDMAARM_PSW_NCP_SHIFT)) & SDMAARM_PSW_NCP_MASK)
/*! @} */

/*! @name EVTERRDBG - DMA Request Error Register */
/*! @{ */

#define SDMAARM_EVTERRDBG_CHNERR_MASK            (0xFFFFFFFFU)
#define SDMAARM_EVTERRDBG_CHNERR_SHIFT           (0U)
#define SDMAARM_EVTERRDBG_CHNERR(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVTERRDBG_CHNERR_SHIFT)) & SDMAARM_EVTERRDBG_CHNERR_MASK)
/*! @} */

/*! @name CONFIG - Configuration Register */
/*! @{ */

#define SDMAARM_CONFIG_CSM_MASK                  (0x3U)
#define SDMAARM_CONFIG_CSM_SHIFT                 (0U)
/*! CSM
 *  0b00..static
 *  0b01..dynamic low power
 *  0b10..dynamic with no loop
 *  0b11..dynamic
 */
#define SDMAARM_CONFIG_CSM(x)                    (((uint32_t)(((uint32_t)(x)) << SDMAARM_CONFIG_CSM_SHIFT)) & SDMAARM_CONFIG_CSM_MASK)

#define SDMAARM_CONFIG_ACR_MASK                  (0x10U)
#define SDMAARM_CONFIG_ACR_SHIFT                 (4U)
/*! ACR
 *  0b0..Arm platform DMA interface frequency equals twice core frequency
 *  0b1..Arm platform DMA interface frequency equals core frequency
 */
#define SDMAARM_CONFIG_ACR(x)                    (((uint32_t)(((uint32_t)(x)) << SDMAARM_CONFIG_ACR_SHIFT)) & SDMAARM_CONFIG_ACR_MASK)

#define SDMAARM_CONFIG_RTDOBS_MASK               (0x800U)
#define SDMAARM_CONFIG_RTDOBS_SHIFT              (11U)
/*! RTDOBS
 *  0b0..RTD pins disabled
 *  0b1..RTD pins enabled
 */
#define SDMAARM_CONFIG_RTDOBS(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_CONFIG_RTDOBS_SHIFT)) & SDMAARM_CONFIG_RTDOBS_MASK)

#define SDMAARM_CONFIG_DSPDMA_MASK               (0x1000U)
#define SDMAARM_CONFIG_DSPDMA_SHIFT              (12U)
/*! DSPDMA
 *  0b0..- Reset Value
 *  0b1..- Reserved
 */
#define SDMAARM_CONFIG_DSPDMA(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_CONFIG_DSPDMA_SHIFT)) & SDMAARM_CONFIG_DSPDMA_MASK)
/*! @} */

/*! @name SDMA_LOCK - SDMA LOCK */
/*! @{ */

#define SDMAARM_SDMA_LOCK_LOCK_MASK              (0x1U)
#define SDMAARM_SDMA_LOCK_LOCK_SHIFT             (0U)
/*! LOCK
 *  0b0..LOCK disengaged.
 *  0b1..LOCK enabled.
 */
#define SDMAARM_SDMA_LOCK_LOCK(x)                (((uint32_t)(((uint32_t)(x)) << SDMAARM_SDMA_LOCK_LOCK_SHIFT)) & SDMAARM_SDMA_LOCK_LOCK_MASK)

#define SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR_MASK   (0x2U)
#define SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR_SHIFT  (1U)
/*! SRESET_LOCK_CLR
 *  0b0..Software Reset does not clear the LOCK bit.
 *  0b1..Software Reset clears the LOCK bit.
 */
#define SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(x)     (((uint32_t)(((uint32_t)(x)) << SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR_SHIFT)) & SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR_MASK)
/*! @} */

/*! @name ONCE_ENB - OnCE Enable */
/*! @{ */

#define SDMAARM_ONCE_ENB_ENB_MASK                (0x1U)
#define SDMAARM_ONCE_ENB_ENB_SHIFT               (0U)
#define SDMAARM_ONCE_ENB_ENB(x)                  (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_ENB_ENB_SHIFT)) & SDMAARM_ONCE_ENB_ENB_MASK)
/*! @} */

/*! @name ONCE_DATA - OnCE Data Register */
/*! @{ */

#define SDMAARM_ONCE_DATA_DATA_MASK              (0xFFFFFFFFU)
#define SDMAARM_ONCE_DATA_DATA_SHIFT             (0U)
#define SDMAARM_ONCE_DATA_DATA(x)                (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_DATA_DATA_SHIFT)) & SDMAARM_ONCE_DATA_DATA_MASK)
/*! @} */

/*! @name ONCE_INSTR - OnCE Instruction Register */
/*! @{ */

#define SDMAARM_ONCE_INSTR_INSTR_MASK            (0xFFFFU)
#define SDMAARM_ONCE_INSTR_INSTR_SHIFT           (0U)
#define SDMAARM_ONCE_INSTR_INSTR(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_INSTR_INSTR_SHIFT)) & SDMAARM_ONCE_INSTR_INSTR_MASK)
/*! @} */

/*! @name ONCE_STAT - OnCE Status Register */
/*! @{ */

#define SDMAARM_ONCE_STAT_ECDR_MASK              (0x7U)
#define SDMAARM_ONCE_STAT_ECDR_SHIFT             (0U)
/*! ECDR
 *  0b000..1 matched addra_cond
 *  0b001..1 matched addrb_cond
 *  0b010..1 matched data_cond
 */
#define SDMAARM_ONCE_STAT_ECDR(x)                (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_ECDR_SHIFT)) & SDMAARM_ONCE_STAT_ECDR_MASK)

#define SDMAARM_ONCE_STAT_MST_MASK               (0x80U)
#define SDMAARM_ONCE_STAT_MST_SHIFT              (7U)
/*! MST
 *  0b0..The JTAG interface controls the OnCE.
 *  0b1..The Arm platform peripheral interface controls the OnCE.
 */
#define SDMAARM_ONCE_STAT_MST(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_MST_SHIFT)) & SDMAARM_ONCE_STAT_MST_MASK)

#define SDMAARM_ONCE_STAT_SWB_MASK               (0x100U)
#define SDMAARM_ONCE_STAT_SWB_SHIFT              (8U)
#define SDMAARM_ONCE_STAT_SWB(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_SWB_SHIFT)) & SDMAARM_ONCE_STAT_SWB_MASK)

#define SDMAARM_ONCE_STAT_ODR_MASK               (0x200U)
#define SDMAARM_ONCE_STAT_ODR_SHIFT              (9U)
#define SDMAARM_ONCE_STAT_ODR(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_ODR_SHIFT)) & SDMAARM_ONCE_STAT_ODR_MASK)

#define SDMAARM_ONCE_STAT_EDR_MASK               (0x400U)
#define SDMAARM_ONCE_STAT_EDR_SHIFT              (10U)
#define SDMAARM_ONCE_STAT_EDR(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_EDR_SHIFT)) & SDMAARM_ONCE_STAT_EDR_MASK)

#define SDMAARM_ONCE_STAT_RCV_MASK               (0x800U)
#define SDMAARM_ONCE_STAT_RCV_SHIFT              (11U)
#define SDMAARM_ONCE_STAT_RCV(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_RCV_SHIFT)) & SDMAARM_ONCE_STAT_RCV_MASK)

#define SDMAARM_ONCE_STAT_PST_MASK               (0xF000U)
#define SDMAARM_ONCE_STAT_PST_SHIFT              (12U)
/*! PST
 *  0b0000..Program
 *  0b0001..Data
 *  0b0010..Change of Flow
 *  0b0010..Change of Flow in Sleep
 *  0b0011..Change Flow in Loop in Sleep
 *  0b0011..Change of Flow in Loop
 *  0b0100..Debug
 *  0b0101..Functional Unit
 *  0b0110..Sleep
 *  0b0111..Save
 *  0b1000..Program in Sleep
 *  0b1001..Data in Sleep
 *  0b1100..Debug in Sleep
 *  0b1101..Functional Unit in Sleep
 *  0b1110..Sleep after Reset
 *  0b1111..Restore
 */
#define SDMAARM_ONCE_STAT_PST(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_STAT_PST_SHIFT)) & SDMAARM_ONCE_STAT_PST_MASK)
/*! @} */

/*! @name ONCE_CMD - OnCE Command Register */
/*! @{ */

#define SDMAARM_ONCE_CMD_CMD_MASK                (0xFU)
#define SDMAARM_ONCE_CMD_CMD_SHIFT               (0U)
/*! CMD
 *  0b0000..rstatus
 *  0b0001..dmov
 *  0b0010..exec_once
 *  0b0011..run_core
 *  0b0100..exec_core
 *  0b0101..debug_rqst
 *  0b0110..rbuffer
 */
#define SDMAARM_ONCE_CMD_CMD(x)                  (((uint32_t)(((uint32_t)(x)) << SDMAARM_ONCE_CMD_CMD_SHIFT)) & SDMAARM_ONCE_CMD_CMD_MASK)
/*! @} */

/*! @name ILLINSTADDR - Illegal Instruction Trap Address */
/*! @{ */

#define SDMAARM_ILLINSTADDR_ILLINSTADDR_MASK     (0x3FFFU)
#define SDMAARM_ILLINSTADDR_ILLINSTADDR_SHIFT    (0U)
#define SDMAARM_ILLINSTADDR_ILLINSTADDR(x)       (((uint32_t)(((uint32_t)(x)) << SDMAARM_ILLINSTADDR_ILLINSTADDR_SHIFT)) & SDMAARM_ILLINSTADDR_ILLINSTADDR_MASK)
/*! @} */

/*! @name CHN0ADDR - Channel 0 Boot Address */
/*! @{ */

#define SDMAARM_CHN0ADDR_CHN0ADDR_MASK           (0x3FFFU)
#define SDMAARM_CHN0ADDR_CHN0ADDR_SHIFT          (0U)
#define SDMAARM_CHN0ADDR_CHN0ADDR(x)             (((uint32_t)(((uint32_t)(x)) << SDMAARM_CHN0ADDR_CHN0ADDR_SHIFT)) & SDMAARM_CHN0ADDR_CHN0ADDR_MASK)

#define SDMAARM_CHN0ADDR_SMSZ_MASK               (0x4000U)
#define SDMAARM_CHN0ADDR_SMSZ_SHIFT              (14U)
/*! SMSZ
 *  0b0..24 words per context
 *  0b1..32 words per context
 */
#define SDMAARM_CHN0ADDR_SMSZ(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_CHN0ADDR_SMSZ_SHIFT)) & SDMAARM_CHN0ADDR_SMSZ_MASK)
/*! @} */

/*! @name EVT_MIRROR - DMA Requests */
/*! @{ */

#define SDMAARM_EVT_MIRROR_EVENTS_MASK           (0xFFFFFFFFU)
#define SDMAARM_EVT_MIRROR_EVENTS_SHIFT          (0U)
/*! EVENTS
 *  0b00000000000000000000000000000000..DMA request event not pending
 *  0b00000000000000000000000000000001..DMA request event pending
 */
#define SDMAARM_EVT_MIRROR_EVENTS(x)             (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVT_MIRROR_EVENTS_SHIFT)) & SDMAARM_EVT_MIRROR_EVENTS_MASK)
/*! @} */

/*! @name EVT_MIRROR2 - DMA Requests 2 */
/*! @{ */

#define SDMAARM_EVT_MIRROR2_EVENTS_MASK          (0xFFFFU)
#define SDMAARM_EVT_MIRROR2_EVENTS_SHIFT         (0U)
/*! EVENTS
 *  0b0000000000000000..- DMA request event not pending
 */
#define SDMAARM_EVT_MIRROR2_EVENTS(x)            (((uint32_t)(((uint32_t)(x)) << SDMAARM_EVT_MIRROR2_EVENTS_SHIFT)) & SDMAARM_EVT_MIRROR2_EVENTS_MASK)
/*! @} */

/*! @name XTRIG_CONF1 - Cross-Trigger Events Configuration Register 1 */
/*! @{ */

#define SDMAARM_XTRIG_CONF1_NUM0_MASK            (0x3FU)
#define SDMAARM_XTRIG_CONF1_NUM0_SHIFT           (0U)
#define SDMAARM_XTRIG_CONF1_NUM0(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_NUM0_SHIFT)) & SDMAARM_XTRIG_CONF1_NUM0_MASK)

#define SDMAARM_XTRIG_CONF1_CNF0_MASK            (0x40U)
#define SDMAARM_XTRIG_CONF1_CNF0_SHIFT           (6U)
/*! CNF0
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF1_CNF0(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_CNF0_SHIFT)) & SDMAARM_XTRIG_CONF1_CNF0_MASK)

#define SDMAARM_XTRIG_CONF1_NUM1_MASK            (0x3F00U)
#define SDMAARM_XTRIG_CONF1_NUM1_SHIFT           (8U)
#define SDMAARM_XTRIG_CONF1_NUM1(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_NUM1_SHIFT)) & SDMAARM_XTRIG_CONF1_NUM1_MASK)

#define SDMAARM_XTRIG_CONF1_CNF1_MASK            (0x4000U)
#define SDMAARM_XTRIG_CONF1_CNF1_SHIFT           (14U)
/*! CNF1
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF1_CNF1(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_CNF1_SHIFT)) & SDMAARM_XTRIG_CONF1_CNF1_MASK)

#define SDMAARM_XTRIG_CONF1_NUM2_MASK            (0x3F0000U)
#define SDMAARM_XTRIG_CONF1_NUM2_SHIFT           (16U)
#define SDMAARM_XTRIG_CONF1_NUM2(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_NUM2_SHIFT)) & SDMAARM_XTRIG_CONF1_NUM2_MASK)

#define SDMAARM_XTRIG_CONF1_CNF2_MASK            (0x400000U)
#define SDMAARM_XTRIG_CONF1_CNF2_SHIFT           (22U)
/*! CNF2
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF1_CNF2(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_CNF2_SHIFT)) & SDMAARM_XTRIG_CONF1_CNF2_MASK)

#define SDMAARM_XTRIG_CONF1_NUM3_MASK            (0x3F000000U)
#define SDMAARM_XTRIG_CONF1_NUM3_SHIFT           (24U)
#define SDMAARM_XTRIG_CONF1_NUM3(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_NUM3_SHIFT)) & SDMAARM_XTRIG_CONF1_NUM3_MASK)

#define SDMAARM_XTRIG_CONF1_CNF3_MASK            (0x40000000U)
#define SDMAARM_XTRIG_CONF1_CNF3_SHIFT           (30U)
/*! CNF3
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF1_CNF3(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF1_CNF3_SHIFT)) & SDMAARM_XTRIG_CONF1_CNF3_MASK)
/*! @} */

/*! @name XTRIG_CONF2 - Cross-Trigger Events Configuration Register 2 */
/*! @{ */

#define SDMAARM_XTRIG_CONF2_NUM4_MASK            (0x3FU)
#define SDMAARM_XTRIG_CONF2_NUM4_SHIFT           (0U)
#define SDMAARM_XTRIG_CONF2_NUM4(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_NUM4_SHIFT)) & SDMAARM_XTRIG_CONF2_NUM4_MASK)

#define SDMAARM_XTRIG_CONF2_CNF4_MASK            (0x40U)
#define SDMAARM_XTRIG_CONF2_CNF4_SHIFT           (6U)
/*! CNF4
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF2_CNF4(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_CNF4_SHIFT)) & SDMAARM_XTRIG_CONF2_CNF4_MASK)

#define SDMAARM_XTRIG_CONF2_NUM5_MASK            (0x3F00U)
#define SDMAARM_XTRIG_CONF2_NUM5_SHIFT           (8U)
#define SDMAARM_XTRIG_CONF2_NUM5(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_NUM5_SHIFT)) & SDMAARM_XTRIG_CONF2_NUM5_MASK)

#define SDMAARM_XTRIG_CONF2_CNF5_MASK            (0x4000U)
#define SDMAARM_XTRIG_CONF2_CNF5_SHIFT           (14U)
/*! CNF5
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF2_CNF5(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_CNF5_SHIFT)) & SDMAARM_XTRIG_CONF2_CNF5_MASK)

#define SDMAARM_XTRIG_CONF2_NUM6_MASK            (0x3F0000U)
#define SDMAARM_XTRIG_CONF2_NUM6_SHIFT           (16U)
#define SDMAARM_XTRIG_CONF2_NUM6(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_NUM6_SHIFT)) & SDMAARM_XTRIG_CONF2_NUM6_MASK)

#define SDMAARM_XTRIG_CONF2_CNF6_MASK            (0x400000U)
#define SDMAARM_XTRIG_CONF2_CNF6_SHIFT           (22U)
/*! CNF6
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF2_CNF6(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_CNF6_SHIFT)) & SDMAARM_XTRIG_CONF2_CNF6_MASK)

#define SDMAARM_XTRIG_CONF2_NUM7_MASK            (0x3F000000U)
#define SDMAARM_XTRIG_CONF2_NUM7_SHIFT           (24U)
#define SDMAARM_XTRIG_CONF2_NUM7(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_NUM7_SHIFT)) & SDMAARM_XTRIG_CONF2_NUM7_MASK)

#define SDMAARM_XTRIG_CONF2_CNF7_MASK            (0x40000000U)
#define SDMAARM_XTRIG_CONF2_CNF7_SHIFT           (30U)
/*! CNF7
 *  0b0..channel
 *  0b1..DMA request
 */
#define SDMAARM_XTRIG_CONF2_CNF7(x)              (((uint32_t)(((uint32_t)(x)) << SDMAARM_XTRIG_CONF2_CNF7_SHIFT)) & SDMAARM_XTRIG_CONF2_CNF7_MASK)
/*! @} */

/*! @name SDMA_CHNPRI - Channel Priority Registers */
/*! @{ */

#define SDMAARM_SDMA_CHNPRI_CHNPRIn_MASK         (0x7U)
#define SDMAARM_SDMA_CHNPRI_CHNPRIn_SHIFT        (0U)
#define SDMAARM_SDMA_CHNPRI_CHNPRIn(x)           (((uint32_t)(((uint32_t)(x)) << SDMAARM_SDMA_CHNPRI_CHNPRIn_SHIFT)) & SDMAARM_SDMA_CHNPRI_CHNPRIn_MASK)
/*! @} */

/*! @name CHNENBL - Channel Enable RAM */
/*! @{ */

#define SDMAARM_CHNENBL_ENBLn_MASK               (0xFFFFFFFFU)
#define SDMAARM_CHNENBL_ENBLn_SHIFT              (0U)
#define SDMAARM_CHNENBL_ENBLn(x)                 (((uint32_t)(((uint32_t)(x)) << SDMAARM_CHNENBL_ENBLn_SHIFT)) & SDMAARM_CHNENBL_ENBLn_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDMAARM_Register_Masks */


/*!
 * @}
 */ /* end of group SDMAARM_Peripheral_Access_Layer */


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


#endif  /* PERI_SDMAARM_H_ */

