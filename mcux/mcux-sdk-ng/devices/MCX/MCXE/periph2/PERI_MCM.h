/*
** ###################################################################
**     Processors:          MCXE246VLH
**                          MCXE246VLL
**                          MCXE246VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250424
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_MCM.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE246VLH) || defined(CPU_MCXE246VLL) || defined(CPU_MCXE246VLQ))
#include "MCXE246_COMMON.h"
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
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Size of Registers Arrays */
#define MCM_LMDR_COUNT                            2u

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t CPCR;                              /**< Core Platform Control Register, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control Register, offset: 0x10 */
       uint8_t RESERVED_1[28];
  __IO uint32_t PID;                               /**< Process ID Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
       uint8_t RESERVED_3[956];
  __IO uint32_t LMDR[MCM_LMDR_COUNT];              /**< Local Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
  __IO uint32_t LMDR2;                             /**< Local Memory Descriptor Register2, offset: 0x408 */
       uint8_t RESERVED_4[116];
  __IO uint32_t LMPECR;                            /**< LMEM Parity and ECC Control Register, offset: 0x480 */
       uint8_t RESERVED_5[4];
  __IO uint32_t LMPEIR;                            /**< LMEM Parity and ECC Interrupt Register, offset: 0x488 */
       uint8_t RESERVED_6[4];
  __I  uint32_t LMFAR;                             /**< LMEM Fault Address Register, offset: 0x490 */
  __I  uint32_t LMFATR;                            /**< LMEM Fault Attribute Register, offset: 0x494 */
       uint8_t RESERVED_7[8];
  __I  uint32_t LMFDHR;                            /**< LMEM Fault Data High Register, offset: 0x4A0 */
  __I  uint32_t LMFDLR;                            /**< LMEM Fault Data Low Register, offset: 0x4A4 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define MCM_PLASC_ASC_MASK                       (0xFFU)
#define MCM_PLASC_ASC_SHIFT                      (0U)
/*! ASC - Each bit in the ASC field indicates whether there is a corresponding connection to the
 *    crossbar switch's slave input port.
 *  0b00000000..A bus slave connection to AXBS input port n is absent
 *  0b00000001..A bus slave connection to AXBS input port n is present
 */
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC_SHIFT)) & MCM_PLASC_ASC_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
/*! @{ */

#define MCM_PLAMC_AMC_MASK                       (0xFFU)
#define MCM_PLAMC_AMC_SHIFT                      (0U)
/*! AMC - Each bit in the AMC field indicates whether there is a corresponding connection to the AXBS master input port.
 *  0b00000000..A bus master connection to AXBS input port n is absent
 *  0b00000001..A bus master connection to AXBS input port n is present
 */
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC_SHIFT)) & MCM_PLAMC_AMC_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control Register */
/*! @{ */

#define MCM_CPCR_HLT_FSM_ST_MASK                 (0x3U)
#define MCM_CPCR_HLT_FSM_ST_SHIFT                (0U)
/*! HLT_FSM_ST - AXBS Halt State Machine Status
 *  0b00..Waiting for request
 *  0b01..Waiting for platform idle
 *  0b10..Unused state
 *  0b11..Platform stalled
 */
#define MCM_CPCR_HLT_FSM_ST(x)                   (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_HLT_FSM_ST_SHIFT)) & MCM_CPCR_HLT_FSM_ST_MASK)

#define MCM_CPCR_AXBS_HLT_REQ_MASK               (0x4U)
#define MCM_CPCR_AXBS_HLT_REQ_SHIFT              (2U)
/*! AXBS_HLT_REQ - AXBS Halt Request
 *  0b0..AXBS is not receiving halt request
 *  0b1..AXBS is receiving halt request
 */
#define MCM_CPCR_AXBS_HLT_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_AXBS_HLT_REQ_SHIFT)) & MCM_CPCR_AXBS_HLT_REQ_MASK)

#define MCM_CPCR_AXBS_HLTD_MASK                  (0x8U)
#define MCM_CPCR_AXBS_HLTD_SHIFT                 (3U)
/*! AXBS_HLTD - AXBS Halted
 *  0b0..AXBS is not currently halted
 *  0b1..AXBS is currently halted
 */
#define MCM_CPCR_AXBS_HLTD(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_AXBS_HLTD_SHIFT)) & MCM_CPCR_AXBS_HLTD_MASK)

#define MCM_CPCR_FMC_PF_IDLE_MASK                (0x10U)
#define MCM_CPCR_FMC_PF_IDLE_SHIFT               (4U)
/*! FMC_PF_IDLE - Flash Memory Controller Program Flash Idle
 *  0b0..FMC program flash is not idle
 *  0b1..FMC program flash is currently idle
 */
#define MCM_CPCR_FMC_PF_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_FMC_PF_IDLE_SHIFT)) & MCM_CPCR_FMC_PF_IDLE_MASK)

#define MCM_CPCR_PBRIDGE_IDLE_MASK               (0x40U)
#define MCM_CPCR_PBRIDGE_IDLE_SHIFT              (6U)
/*! PBRIDGE_IDLE - Peripheral Bridge Idle
 *  0b0..PBRIDGE is not idle
 *  0b1..PBRIDGE is currently idle
 */
#define MCM_CPCR_PBRIDGE_IDLE(x)                 (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_PBRIDGE_IDLE_SHIFT)) & MCM_CPCR_PBRIDGE_IDLE_MASK)

#define MCM_CPCR_CBRR_MASK                       (0x200U)
#define MCM_CPCR_CBRR_SHIFT                      (9U)
/*! CBRR - Crossbar Round-robin Arbitration Enable
 *  0b0..Fixed-priority arbitration
 *  0b1..Round-robin arbitration
 */
#define MCM_CPCR_CBRR(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CBRR_SHIFT)) & MCM_CPCR_CBRR_MASK)

#define MCM_CPCR_SRAMUAP_MASK                    (0x3000000U)
#define MCM_CPCR_SRAMUAP_SHIFT                   (24U)
/*! SRAMUAP - SRAM_U Arbitration Priority
 *  0b00..Round robin
 *  0b01..Special round robin (favors SRAM backdoor accesses over the processor)
 *  0b10..Fixed priority. Processor has highest, backdoor has lowest
 *  0b11..Fixed priority. Backdoor has highest, processor has lowest
 */
#define MCM_CPCR_SRAMUAP(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_SRAMUAP_SHIFT)) & MCM_CPCR_SRAMUAP_MASK)

#define MCM_CPCR_SRAMUWP_MASK                    (0x4000000U)
#define MCM_CPCR_SRAMUWP_SHIFT                   (26U)
/*! SRAMUWP - SRAM_U Write Protect */
#define MCM_CPCR_SRAMUWP(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_SRAMUWP_SHIFT)) & MCM_CPCR_SRAMUWP_MASK)

#define MCM_CPCR_SRAMLAP_MASK                    (0x30000000U)
#define MCM_CPCR_SRAMLAP_SHIFT                   (28U)
/*! SRAMLAP - SRAM_L Arbitration Priority
 *  0b00..Round robin
 *  0b01..Special round robin (favors SRAM backdoor accesses over the processor)
 *  0b10..Fixed priority. Processor has highest, backdoor has lowest
 *  0b11..Fixed priority. Backdoor has highest, processor has lowest
 */
#define MCM_CPCR_SRAMLAP(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_SRAMLAP_SHIFT)) & MCM_CPCR_SRAMLAP_MASK)

#define MCM_CPCR_SRAMLWP_MASK                    (0x40000000U)
#define MCM_CPCR_SRAMLWP_SHIFT                   (30U)
/*! SRAMLWP - SRAM_L Write Protect */
#define MCM_CPCR_SRAMLWP(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_SRAMLWP_SHIFT)) & MCM_CPCR_SRAMLWP_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control Register */
/*! @{ */

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FDZC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZC_SHIFT)) & MCM_ISCR_FDZC_MASK)

#define MCM_ISCR_FOFC_MASK                       (0x400U)
#define MCM_ISCR_FOFC_SHIFT                      (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FOFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFC_SHIFT)) & MCM_ISCR_FOFC_MASK)

#define MCM_ISCR_FUFC_MASK                       (0x800U)
#define MCM_ISCR_FUFC_SHIFT                      (11U)
/*! FUFC - FPU Underflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FUFC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFC_SHIFT)) & MCM_ISCR_FUFC_MASK)

#define MCM_ISCR_FIXC_MASK                       (0x1000U)
#define MCM_ISCR_FIXC_SHIFT                      (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIXC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXC_SHIFT)) & MCM_ISCR_FIXC_MASK)

#define MCM_ISCR_FIDC_MASK                       (0x8000U)
#define MCM_ISCR_FIDC_SHIFT                      (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIDC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDC_SHIFT)) & MCM_ISCR_FIDC_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FDZCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FDZCE_SHIFT)) & MCM_ISCR_FDZCE_MASK)

#define MCM_ISCR_FOFCE_MASK                      (0x4000000U)
#define MCM_ISCR_FOFCE_SHIFT                     (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FOFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FOFCE_SHIFT)) & MCM_ISCR_FOFCE_MASK)

#define MCM_ISCR_FUFCE_MASK                      (0x8000000U)
#define MCM_ISCR_FUFCE_SHIFT                     (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FUFCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FUFCE_SHIFT)) & MCM_ISCR_FUFCE_MASK)

#define MCM_ISCR_FIXCE_MASK                      (0x10000000U)
#define MCM_ISCR_FIXCE_SHIFT                     (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIXCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIXCE_SHIFT)) & MCM_ISCR_FIXCE_MASK)

#define MCM_ISCR_FIDCE_MASK                      (0x80000000U)
#define MCM_ISCR_FIDCE_SHIFT                     (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIDCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIDCE_SHIFT)) & MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name PID - Process ID Register */
/*! @{ */

#define MCM_PID_PID_MASK                         (0xFFU)
#define MCM_PID_PID_SHIFT                        (0U)
/*! PID - M0_PID and M1_PID for MPU */
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_PID_PID_SHIFT)) & MCM_PID_PID_MASK)
/*! @} */

/*! @name CPO - Compute Operation Control Register */
/*! @{ */

#define MCM_CPO_CPOREQ_MASK                      (0x1U)
#define MCM_CPO_CPOREQ_SHIFT                     (0U)
/*! CPOREQ - Compute Operation Request
 *  0b0..Request is cleared.
 *  0b1..Request Compute Operation.
 */
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOREQ_SHIFT)) & MCM_CPO_CPOREQ_MASK)

#define MCM_CPO_CPOACK_MASK                      (0x2U)
#define MCM_CPO_CPOACK_SHIFT                     (1U)
/*! CPOACK - Compute Operation Acknowledge
 *  0b0..Compute operation entry has not completed or compute operation exit has completed.
 *  0b1..Compute operation entry has completed or compute operation exit has not completed.
 */
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOACK_SHIFT)) & MCM_CPO_CPOACK_MASK)

#define MCM_CPO_CPOWOI_MASK                      (0x4U)
#define MCM_CPO_CPOWOI_SHIFT                     (2U)
/*! CPOWOI - Compute Operation Wakeup On Interrupt
 *  0b0..No effect.
 *  0b1..When set, the CPOREQ is cleared on any interrupt or exception vector fetch.
 */
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOWOI_SHIFT)) & MCM_CPO_CPOWOI_MASK)
/*! @} */

/*! @name LMDR - Local Memory Descriptor Register */
/*! @{ */

#define MCM_LMDR_CF0_MASK                        (0xFU)
#define MCM_LMDR_CF0_SHIFT                       (0U)
/*! CF0 - Control Field 0 */
#define MCM_LMDR_CF0(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_CF0_SHIFT)) & MCM_LMDR_CF0_MASK)

#define MCM_LMDR_MT_MASK                         (0xE000U)
#define MCM_LMDR_MT_SHIFT                        (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 */
#define MCM_LMDR_MT(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_MT_SHIFT)) & MCM_LMDR_MT_MASK)

#define MCM_LMDR_LOCK_MASK                       (0x10000U)
#define MCM_LMDR_LOCK_SHIFT                      (16U)
/*! LOCK - LOCK
 *  0b0..Writes to the LMDRn[7:0] are allowed.
 *  0b1..Writes to the LMDRn[7:0] are ignored.
 */
#define MCM_LMDR_LOCK(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_LOCK_SHIFT)) & MCM_LMDR_LOCK_MASK)

#define MCM_LMDR_DPW_MASK                        (0xE0000U)
#define MCM_LMDR_DPW_SHIFT                       (17U)
/*! DPW
 *  0b000-0b001..Reserved
 *  0b010..LMEMn 32-bits wide
 *  0b011..LMEMn 64-bits wide
 *  0b100-0b111..Reserved
 */
#define MCM_LMDR_DPW(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_DPW_SHIFT)) & MCM_LMDR_DPW_MASK)

#define MCM_LMDR_WY_MASK                         (0xF00000U)
#define MCM_LMDR_WY_SHIFT                        (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No Cache
 *  0b0010..2-Way Set Associative
 *  0b0100..4-Way Set Associative
 */
#define MCM_LMDR_WY(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_WY_SHIFT)) & MCM_LMDR_WY_MASK)

#define MCM_LMDR_LMSZ_MASK                       (0xF000000U)
#define MCM_LMDR_LMSZ_SHIFT                      (24U)
/*! LMSZ - LMEM Size
 *  0b0000..no LMEMn (0 KB)
 *  0b0001..1 KB LMEMn
 *  0b0010..2 KB LMEMn
 *  0b0011..4 KB LMEMn
 *  0b0100..8 KB LMEMn
 *  0b0101..16 KB LMEMn
 *  0b0110..32 KB LMEMn
 *  0b0111..64 KB LMEMn
 *  0b1000..128 KB LMEMn
 *  0b1001..256 KB LMEMn
 *  0b1010..512 KB LMEMn
 *  0b1011..1024 KB LMEMn
 *  0b1100..2048 KB LMEMn
 *  0b1101..4096 KB LMEMn
 *  0b1110..8192 KB LMEMn
 *  0b1111..16384 KB LMEMn
 */
#define MCM_LMDR_LMSZ(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_LMSZ_SHIFT)) & MCM_LMDR_LMSZ_MASK)

#define MCM_LMDR_LMSZH_MASK                      (0x10000000U)
#define MCM_LMDR_LMSZH_SHIFT                     (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEMn is a power-of-2 capacity.
 *  0b1..LMEMn is not a power-of-2, with a capacity is 0.75 * LMSZ.
 */
#define MCM_LMDR_LMSZH(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_LMSZH_SHIFT)) & MCM_LMDR_LMSZH_MASK)

#define MCM_LMDR_V_MASK                          (0x80000000U)
#define MCM_LMDR_V_SHIFT                         (31U)
/*! V - Local Memory Valid
 *  0b0..LMEMn is not present.
 *  0b1..LMEMn is present.
 */
#define MCM_LMDR_V(x)                            (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_V_SHIFT)) & MCM_LMDR_V_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor Register2 */
/*! @{ */

#define MCM_LMDR2_CF1_MASK                       (0xF0U)
#define MCM_LMDR2_CF1_SHIFT                      (4U)
/*! CF1 - Control Field 1 */
#define MCM_LMDR2_CF1(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_CF1_SHIFT)) & MCM_LMDR2_CF1_MASK)

#define MCM_LMDR2_MT_MASK                        (0xE000U)
#define MCM_LMDR2_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b010..PC Cache
 */
#define MCM_LMDR2_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_MT_SHIFT)) & MCM_LMDR2_MT_MASK)

#define MCM_LMDR2_LOCK_MASK                      (0x10000U)
#define MCM_LMDR2_LOCK_SHIFT                     (16U)
/*! LOCK - LOCK
 *  0b0..Writes to the LMDRn[7:0] are allowed.
 *  0b1..Writes to the LMDRn[7:0] are ignored.
 */
#define MCM_LMDR2_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LOCK_SHIFT)) & MCM_LMDR2_LOCK_MASK)

#define MCM_LMDR2_DPW_MASK                       (0xE0000U)
#define MCM_LMDR2_DPW_SHIFT                      (17U)
/*! DPW
 *  0b000-0b001..Reserved
 *  0b010..LMEMn 32-bits wide
 *  0b011..LMEMn 64-bits wide
 *  0b100-0b111..Reserved
 */
#define MCM_LMDR2_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_DPW_SHIFT)) & MCM_LMDR2_DPW_MASK)

#define MCM_LMDR2_WY_MASK                        (0xF00000U)
#define MCM_LMDR2_WY_SHIFT                       (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No Cache
 *  0b0010..2-Way Set Associative
 *  0b0100..4-Way Set Associative
 */
#define MCM_LMDR2_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_WY_SHIFT)) & MCM_LMDR2_WY_MASK)

#define MCM_LMDR2_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR2_LMSZ_SHIFT                     (24U)
/*! LMSZ - LMEM Size
 *  0b0100..4 KB LMEMn
 */
#define MCM_LMDR2_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZ_SHIFT)) & MCM_LMDR2_LMSZ_MASK)

#define MCM_LMDR2_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR2_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEMn is a power-of-2 capacity.
 *  0b1..LMEMn is not a power-of-2, with a capacity is 0.75 * LMSZ.
 */
#define MCM_LMDR2_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZH_SHIFT)) & MCM_LMDR2_LMSZH_MASK)

#define MCM_LMDR2_V_MASK                         (0x80000000U)
#define MCM_LMDR2_V_SHIFT                        (31U)
/*! V - Local Memory Valid
 *  0b0..LMEMn is not present.
 *  0b1..LMEMn is present.
 */
#define MCM_LMDR2_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_V_SHIFT)) & MCM_LMDR2_V_MASK)
/*! @} */

/*! @name LMPECR - LMEM Parity and ECC Control Register */
/*! @{ */

#define MCM_LMPECR_ERNCR_MASK                    (0x1U)
#define MCM_LMPECR_ERNCR_SHIFT                   (0U)
/*! ERNCR - Enable RAM ECC Noncorrectable Reporting
 *  0b0..Reporting disabled
 *  0b1..Reporting enabled
 */
#define MCM_LMPECR_ERNCR(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMPECR_ERNCR_SHIFT)) & MCM_LMPECR_ERNCR_MASK)

#define MCM_LMPECR_ER1BR_MASK                    (0x100U)
#define MCM_LMPECR_ER1BR_SHIFT                   (8U)
/*! ER1BR - Enable RAM ECC 1 Bit Reporting
 *  0b0..Reporting disabled
 *  0b1..Reporting enabled
 */
#define MCM_LMPECR_ER1BR(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMPECR_ER1BR_SHIFT)) & MCM_LMPECR_ER1BR_MASK)

#define MCM_LMPECR_ECPR_MASK                     (0x100000U)
#define MCM_LMPECR_ECPR_SHIFT                    (20U)
/*! ECPR - Enable Cache Parity Reporting
 *  0b0..Reporting disabled
 *  0b1..Reporting enabled
 */
#define MCM_LMPECR_ECPR(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMPECR_ECPR_SHIFT)) & MCM_LMPECR_ECPR_MASK)
/*! @} */

/*! @name LMPEIR - LMEM Parity and ECC Interrupt Register */
/*! @{ */

#define MCM_LMPEIR_ENC_MASK                      (0xFFU)
#define MCM_LMPEIR_ENC_SHIFT                     (0U)
/*! ENC - ENCn = ECC Noncorrectable Error n */
#define MCM_LMPEIR_ENC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_ENC_SHIFT)) & MCM_LMPEIR_ENC_MASK)

#define MCM_LMPEIR_E1B_MASK                      (0xFF00U)
#define MCM_LMPEIR_E1B_SHIFT                     (8U)
/*! E1B - E1Bn = ECC 1-bit Error n */
#define MCM_LMPEIR_E1B(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_E1B_SHIFT)) & MCM_LMPEIR_E1B_MASK)

#define MCM_LMPEIR_PE_MASK                       (0xFF0000U)
#define MCM_LMPEIR_PE_SHIFT                      (16U)
/*! PE - Cache Parity Error */
#define MCM_LMPEIR_PE(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_PE_SHIFT)) & MCM_LMPEIR_PE_MASK)

#define MCM_LMPEIR_PEELOC_MASK                   (0x1F000000U)
#define MCM_LMPEIR_PEELOC_SHIFT                  (24U)
/*! PEELOC - Parity or ECC Error Location
 *  0b00000..Non-correctable ECC event from SRAM_L
 *  0b00001..Non-correctable ECC event from SRAM_U
 *  0b01000..1-bit correctable ECC event from SRAM_L
 *  0b01001..1-bit correctable ECC event from SRAM_U
 *  0b01110..PC tag parity error
 *  0b01111..PC data parity error
 */
#define MCM_LMPEIR_PEELOC(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_PEELOC_SHIFT)) & MCM_LMPEIR_PEELOC_MASK)

#define MCM_LMPEIR_V_MASK                        (0x80000000U)
#define MCM_LMPEIR_V_SHIFT                       (31U)
/*! V - Valid Bit */
#define MCM_LMPEIR_V(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_V_SHIFT)) & MCM_LMPEIR_V_MASK)
/*! @} */

/*! @name LMFAR - LMEM Fault Address Register */
/*! @{ */

#define MCM_LMFAR_EFADD_MASK                     (0xFFFFFFFFU)
#define MCM_LMFAR_EFADD_SHIFT                    (0U)
/*! EFADD - ECC Fault Address */
#define MCM_LMFAR_EFADD(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFAR_EFADD_SHIFT)) & MCM_LMFAR_EFADD_MASK)
/*! @} */

/*! @name LMFATR - LMEM Fault Attribute Register */
/*! @{ */

#define MCM_LMFATR_PEFPRT_MASK                   (0xFU)
#define MCM_LMFATR_PEFPRT_SHIFT                  (0U)
/*! PEFPRT - Parity/ECC Fault Protection */
#define MCM_LMFATR_PEFPRT(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFPRT_SHIFT)) & MCM_LMFATR_PEFPRT_MASK)

#define MCM_LMFATR_PEFSIZE_MASK                  (0x70U)
#define MCM_LMFATR_PEFSIZE_SHIFT                 (4U)
/*! PEFSIZE - Parity/ECC Fault Master Size
 *  0b000..8-bit access
 *  0b001..16-bit access
 *  0b010..32-bit access
 *  0b011..64-bit access
 *  0b1xx..Reserved
 */
#define MCM_LMFATR_PEFSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFSIZE_SHIFT)) & MCM_LMFATR_PEFSIZE_MASK)

#define MCM_LMFATR_PEFW_MASK                     (0x80U)
#define MCM_LMFATR_PEFW_SHIFT                    (7U)
#define MCM_LMFATR_PEFW(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFW_SHIFT)) & MCM_LMFATR_PEFW_MASK)

#define MCM_LMFATR_PEFMST_MASK                   (0xFF00U)
#define MCM_LMFATR_PEFMST_SHIFT                  (8U)
#define MCM_LMFATR_PEFMST(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFMST_SHIFT)) & MCM_LMFATR_PEFMST_MASK)

#define MCM_LMFATR_OVR_MASK                      (0x80000000U)
#define MCM_LMFATR_OVR_SHIFT                     (31U)
/*! OVR - Overrun */
#define MCM_LMFATR_OVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_OVR_SHIFT)) & MCM_LMFATR_OVR_MASK)
/*! @} */

/*! @name LMFDHR - LMEM Fault Data High Register */
/*! @{ */

#define MCM_LMFDHR_PEFDH_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDHR_PEFDH_SHIFT                   (0U)
#define MCM_LMFDHR_PEFDH(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMFDHR_PEFDH_SHIFT)) & MCM_LMFDHR_PEFDH_MASK)
/*! @} */

/*! @name LMFDLR - LMEM Fault Data Low Register */
/*! @{ */

#define MCM_LMFDLR_PEFDL_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDLR_PEFDL_SHIFT                   (0U)
#define MCM_LMFDLR_PEFDL(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMFDLR_PEFDL_SHIFT)) & MCM_LMFDLR_PEFDL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MCM_H_ */

