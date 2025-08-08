/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MCM
 *
 * CMSIS Peripheral Access Layer for MCM
 */

#if !defined(PERI_MCM_H_)
#define PERI_MCM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[12];
  __IO uint32_t CPCR;                              /**< Core Platform Control, offset: 0xC */
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __I  uint32_t FADR;                              /**< Write Buffer Fault Address, offset: 0x20 */
  __I  uint32_t FATR;                              /**< Store Buffer Fault Attributes, offset: 0x24 */
  __I  uint32_t FDR;                               /**< Store Buffer Fault Data, offset: 0x28 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CPCR2;                             /**< Core Platform Control 2, offset: 0x34 */
       uint8_t RESERVED_3[976];
  __IO uint32_t LMDR2;                             /**< Local Memory Descriptor 2, offset: 0x408 */
       uint8_t RESERVED_4[116];
  __IO uint32_t LMPECR;                            /**< LMEM Parity Control, offset: 0x480 */
       uint8_t RESERVED_5[4];
  __IO uint32_t LMPEIR;                            /**< LMEM Parity Interrupt, offset: 0x488 */
       uint8_t RESERVED_6[4];
  __I  uint32_t LMFAR;                             /**< LMEM Fault Address, offset: 0x490 */
  __I  uint32_t LMFATR;                            /**< LMEM Fault Attribute, offset: 0x494 */
       uint8_t RESERVED_7[8];
  __I  uint32_t LMFDHR;                            /**< LMEM Fault Data High, offset: 0x4A0 */
  __I  uint32_t LMFDLR;                            /**< LMEM Fault Data Low, offset: 0x4A4 */
} MCM_Type;

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name CPCR - Core Platform Control */
/*! @{ */

#define MCM_CPCR_CBRR_MASK                       (0x200U)
#define MCM_CPCR_CBRR_SHIFT                      (9U)
/*! CBRR - Crossbar Round-robin Arbitration Enable
 *  0b0..Fixed-priority arbitration
 *  0b1..Round-robin arbitration
 */
#define MCM_CPCR_CBRR(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CBRR_SHIFT)) & MCM_CPCR_CBRR_MASK)

#define MCM_CPCR_PFLEXSTALL_MASK                 (0x10000U)
#define MCM_CPCR_PFLEXSTALL_SHIFT                (16U)
/*! PFLEXSTALL - Flash Stall Enable
 *  0b0..Flash stall is disabled when flash is busy.
 *  0b1..Flash stall is enabled when flash is busy.
 */
#define MCM_CPCR_PFLEXSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_PFLEXSTALL_SHIFT)) & MCM_CPCR_PFLEXSTALL_MASK)
/*! @} */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define MCM_ISCR_CWBER_MASK                      (0x10U)
#define MCM_ISCR_CWBER_SHIFT                     (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define MCM_ISCR_CWBER(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBER_SHIFT)) & MCM_ISCR_CWBER_MASK)

#define MCM_ISCR_CPES_MASK                       (0x20U)
#define MCM_ISCR_CPES_SHIFT                      (5U)
/*! CPES - Cache Parity Error Status
 *  0b0..A cache parity error is not detected.
 *  0b1..A cache parity error is detected.
 */
#define MCM_ISCR_CPES(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CPES_SHIFT)) & MCM_ISCR_CPES_MASK)

#define MCM_ISCR_FIOC_MASK                       (0x100U)
#define MCM_ISCR_FIOC_SHIFT                      (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define MCM_ISCR_FIOC(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOC_SHIFT)) & MCM_ISCR_FIOC_MASK)

#define MCM_ISCR_FDZC_MASK                       (0x200U)
#define MCM_ISCR_FDZC_SHIFT                      (9U)
/*! FDZC - FPU Divide-by-zero Interrupt Status
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
/*! FUFC - FPU Underflow Interrupt status
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

#define MCM_ISCR_CWBEE_MASK                      (0x100000U)
#define MCM_ISCR_CWBEE_SHIFT                     (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable error interrupt
 *  0b1..Enable error interrupt
 */
#define MCM_ISCR_CWBEE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CWBEE_SHIFT)) & MCM_ISCR_CWBEE_MASK)

#define MCM_ISCR_CPEE_MASK                       (0x200000U)
#define MCM_ISCR_CPEE_SHIFT                      (21U)
/*! CPEE - Cache Parity Error Enable
 *  0b0..Disable error interrupt.
 *  0b1..Enable error interrupt.
 */
#define MCM_ISCR_CPEE(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_CPEE_SHIFT)) & MCM_ISCR_CPEE_MASK)

#define MCM_ISCR_FIOCE_MASK                      (0x1000000U)
#define MCM_ISCR_FIOCE_SHIFT                     (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable interrupt
 *  0b1..Enable interrupt
 */
#define MCM_ISCR_FIOCE(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_ISCR_FIOCE_SHIFT)) & MCM_ISCR_FIOCE_MASK)

#define MCM_ISCR_FDZCE_MASK                      (0x2000000U)
#define MCM_ISCR_FDZCE_SHIFT                     (25U)
/*! FDZCE - FPU Divide-by-zero Interrupt Enable
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

/*! @name FADR - Write Buffer Fault Address */
/*! @{ */

#define MCM_FADR_ADDRESS_MASK                    (0xFFFFFFFFU)
#define MCM_FADR_ADDRESS_SHIFT                   (0U)
/*! ADDRESS - Fault address */
#define MCM_FADR_ADDRESS(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_FADR_ADDRESS_SHIFT)) & MCM_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define MCM_FATR_BEDA_MASK                       (0x1U)
#define MCM_FATR_BEDA_SHIFT                      (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define MCM_FATR_BEDA(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEDA_SHIFT)) & MCM_FATR_BEDA_MASK)

#define MCM_FATR_BEMD_MASK                       (0x2U)
#define MCM_FATR_BEMD_SHIFT                      (1U)
/*! BEMD - Bus Error Privilege level
 *  0b0..User mode
 *  0b1..Supervisor/privileged mode
 */
#define MCM_FATR_BEMD(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMD_SHIFT)) & MCM_FATR_BEMD_MASK)

#define MCM_FATR_BESZ_MASK                       (0x30U)
#define MCM_FATR_BESZ_SHIFT                      (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit access
 *  0b01..16-bit access
 *  0b10..32-bit access
 *  0b11..Reserved
 */
#define MCM_FATR_BESZ(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BESZ_SHIFT)) & MCM_FATR_BESZ_MASK)

#define MCM_FATR_BEWT_MASK                       (0x80U)
#define MCM_FATR_BEWT_SHIFT                      (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read access
 *  0b1..Write access
 */
#define MCM_FATR_BEWT(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEWT_SHIFT)) & MCM_FATR_BEWT_MASK)

#define MCM_FATR_BEMN_MASK                       (0xF00U)
#define MCM_FATR_BEMN_SHIFT                      (8U)
/*! BEMN - Bus Error Master Number */
#define MCM_FATR_BEMN(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEMN_SHIFT)) & MCM_FATR_BEMN_MASK)

#define MCM_FATR_BEOVR_MASK                      (0x80000000U)
#define MCM_FATR_BEOVR_SHIFT                     (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No bus error overrun
 *  0b1..Bus error overrun occurred. The FADR and FDR registers and the other FATR bits will not be updated to reflect this new bus error.
 */
#define MCM_FATR_BEOVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_FATR_BEOVR_SHIFT)) & MCM_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define MCM_FDR_DATA_MASK                        (0xFFFFFFFFU)
#define MCM_FDR_DATA_SHIFT                       (0U)
/*! DATA - Fault Data */
#define MCM_FDR_DATA(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_FDR_DATA_SHIFT)) & MCM_FDR_DATA_MASK)
/*! @} */

/*! @name CPCR2 - Core Platform Control 2 */
/*! @{ */

#define MCM_CPCR2_CCBC_MASK                      (0x1U)
#define MCM_CPCR2_CCBC_SHIFT                     (0U)
/*! CCBC - Clear Code Bus Cache
 *  0b0..No effect
 *  0b1..Clear code bus cache
 */
#define MCM_CPCR2_CCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CCBC_SHIFT)) & MCM_CPCR2_CCBC_MASK)

#define MCM_CPCR2_DCCWB_MASK                     (0x2U)
#define MCM_CPCR2_DCCWB_SHIFT                    (1U)
/*! DCCWB - Disable Code Cache Write Buffer
 *  0b0..Enable code cache write buffer
 *  0b1..Disable code cache write buffer
 */
#define MCM_CPCR2_DCCWB(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCCWB_SHIFT)) & MCM_CPCR2_DCCWB_MASK)

#define MCM_CPCR2_FCCNA_MASK                     (0x4U)
#define MCM_CPCR2_FCCNA_SHIFT                    (2U)
/*! FCCNA - Force Code Cache to No Allocation
 *  0b0..Force code cache to allocation
 *  0b1..Force code cache to no allocation
 */
#define MCM_CPCR2_FCCNA(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_FCCNA_SHIFT)) & MCM_CPCR2_FCCNA_MASK)

#define MCM_CPCR2_DCBC_MASK                      (0x8U)
#define MCM_CPCR2_DCBC_SHIFT                     (3U)
/*! DCBC - Disable Code Bus cache
 *  0b0..Enable code bus cache
 *  0b1..Disable code bus cache
 */
#define MCM_CPCR2_DCBC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_DCBC_SHIFT)) & MCM_CPCR2_DCBC_MASK)

#define MCM_CPCR2_CBCS_MASK                      (0xF0U)
#define MCM_CPCR2_CBCS_SHIFT                     (4U)
/*! CBCS - Code Bus Cache Size
 *  0b0000..0 KB
 *  0b0001..1 KB
 *  0b0010..2 KB
 *  0b0011..4 KB
 *  0b0100..8 KB
 *  0b0101..16 KB
 *  0b0110..32 KB
 */
#define MCM_CPCR2_CBCS(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_CBCS_SHIFT)) & MCM_CPCR2_CBCS_MASK)

#define MCM_CPCR2_PCCMCTRL_MASK                  (0x10000U)
#define MCM_CPCR2_PCCMCTRL_SHIFT                 (16U)
/*! PCCMCTRL - Bypass Fixed Code Cache Map
 *  0b0..The fixed code cache map is not bypassed
 *  0b1..The fixed code cache map is bypassed
 */
#define MCM_CPCR2_PCCMCTRL(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_PCCMCTRL_SHIFT)) & MCM_CPCR2_PCCMCTRL_MASK)

#define MCM_CPCR2_LCCPWB_MASK                    (0x20000U)
#define MCM_CPCR2_LCCPWB_SHIFT                   (17U)
/*! LCCPWB - Limit Code Cache Peripheral Write Buffering
 *  0b0..Code cache peripheral write buffering is not limited: if write buffer is enabled, bufferable write is buffered.
 *  0b1..Code cache peripheral write buffering is limited: only bufferable and cachable write is buffered.
 */
#define MCM_CPCR2_LCCPWB(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_CPCR2_LCCPWB_SHIFT)) & MCM_CPCR2_LCCPWB_MASK)
/*! @} */

/*! @name LMDR2 - Local Memory Descriptor 2 */
/*! @{ */

#define MCM_LMDR2_PCPME_MASK                     (0x20U)
#define MCM_LMDR2_PCPME_SHIFT                    (5U)
/*! PCPME - PC Parity Enable
 *  0b0..PC parity is disabled.
 *  0b1..PC parity is enabled.
 */
#define MCM_LMDR2_PCPME(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_PCPME_SHIFT)) & MCM_LMDR2_PCPME_MASK)

#define MCM_LMDR2_PCPFE_MASK                     (0x80U)
#define MCM_LMDR2_PCPFE_SHIFT                    (7U)
/*! PCPFE - PC Parity Fault Report Enable
 *  0b0..PC parity fault report is disabled.
 *  0b1..PC parity fault report is enabled.
 */
#define MCM_LMDR2_PCPFE(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_PCPFE_SHIFT)) & MCM_LMDR2_PCPFE_MASK)

#define MCM_LMDR2_MT_MASK                        (0xE000U)
#define MCM_LMDR2_MT_SHIFT                       (13U)
/*! MT - Memory Type
 *  0b000..SRAM_L
 *  0b001..SRAM_U
 *  0b010..PC Cache
 *  0b011..PS Cache
 */
#define MCM_LMDR2_MT(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_MT_SHIFT)) & MCM_LMDR2_MT_MASK)

#define MCM_LMDR2_RO_MASK                        (0x10000U)
#define MCM_LMDR2_RO_SHIFT                       (16U)
/*! RO - Read-Only
 *  0b0..Writes to the corresponding LMDRn[7:0] are allowed.
 *  0b1..Writes to the corresponding LMDRn[7:0] are ignored.
 */
#define MCM_LMDR2_RO(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_RO_SHIFT)) & MCM_LMDR2_RO_MASK)

#define MCM_LMDR2_DPW_MASK                       (0xE0000U)
#define MCM_LMDR2_DPW_SHIFT                      (17U)
/*! DPW - LMEM Data Path Width
 *  0b000-0b001..Reserved
 *  0b010..LMEMn 32-bit wide
 *  0b011..LMEMn 64-bit wide
 *  0b100-0b111..Reserved
 */
#define MCM_LMDR2_DPW(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_DPW_SHIFT)) & MCM_LMDR2_DPW_MASK)

#define MCM_LMDR2_WY_MASK                        (0xF00000U)
#define MCM_LMDR2_WY_SHIFT                       (20U)
/*! WY - Level 1 Cache Ways
 *  0b0000..No Cache
 *  0b0010..2-Way Set Associative
 *  0b0100..4-Way Set Associative
 *  0b1000..8-Way Set Associative
 */
#define MCM_LMDR2_WY(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_WY_SHIFT)) & MCM_LMDR2_WY_MASK)

#define MCM_LMDR2_LMSZ_MASK                      (0xF000000U)
#define MCM_LMDR2_LMSZ_SHIFT                     (24U)
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
#define MCM_LMDR2_LMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZ_SHIFT)) & MCM_LMDR2_LMSZ_MASK)

#define MCM_LMDR2_LMSZH_MASK                     (0x10000000U)
#define MCM_LMDR2_LMSZH_SHIFT                    (28U)
/*! LMSZH - LMEM Size Hole
 *  0b0..LMEMn is a power-of-2 capacity.
 *  0b1..LMEMn is a capacity of 0.75 * LMSZ.
 */
#define MCM_LMDR2_LMSZH(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_LMSZH_SHIFT)) & MCM_LMDR2_LMSZH_MASK)

#define MCM_LMDR2_V_MASK                         (0x80000000U)
#define MCM_LMDR2_V_SHIFT                        (31U)
/*! V - Valid
 *  0b0..LMEMn is not present.
 *  0b1..LMEMn is present.
 */
#define MCM_LMDR2_V(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR2_V_SHIFT)) & MCM_LMDR2_V_MASK)
/*! @} */

/*! @name LMPECR - LMEM Parity Control */
/*! @{ */

#define MCM_LMPECR_ECPR_MASK                     (0x100000U)
#define MCM_LMPECR_ECPR_SHIFT                    (20U)
/*! ECPR - Enable Cache Parity Reporting
 *  0b0..Cache parity reporting is disabled
 *  0b1..Cache parity reporting is enabled
 */
#define MCM_LMPECR_ECPR(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMPECR_ECPR_SHIFT)) & MCM_LMPECR_ECPR_MASK)
/*! @} */

/*! @name LMPEIR - LMEM Parity Interrupt */
/*! @{ */

#define MCM_LMPEIR_PE_MASK                       (0xFF0000U)
#define MCM_LMPEIR_PE_SHIFT                      (16U)
/*! PE - Parity Error */
#define MCM_LMPEIR_PE(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_PE_SHIFT)) & MCM_LMPEIR_PE_MASK)

#define MCM_LMPEIR_PEELOC_MASK                   (0x1F000000U)
#define MCM_LMPEIR_PEELOC_SHIFT                  (24U)
/*! PEELOC - Error Location */
#define MCM_LMPEIR_PEELOC(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_PEELOC_SHIFT)) & MCM_LMPEIR_PEELOC_MASK)

#define MCM_LMPEIR_V_MASK                        (0x80000000U)
#define MCM_LMPEIR_V_SHIFT                       (31U)
/*! V - Valid bit */
#define MCM_LMPEIR_V(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_V_SHIFT)) & MCM_LMPEIR_V_MASK)
/*! @} */

/*! @name LMFAR - LMEM Fault Address */
/*! @{ */

#define MCM_LMFAR_EFADD_MASK                     (0xFFFFFFFFU)
#define MCM_LMFAR_EFADD_SHIFT                    (0U)
/*! EFADD - Fault Address */
#define MCM_LMFAR_EFADD(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFAR_EFADD_SHIFT)) & MCM_LMFAR_EFADD_MASK)
/*! @} */

/*! @name LMFATR - LMEM Fault Attribute */
/*! @{ */

#define MCM_LMFATR_PEFPRT_MASK                   (0xFU)
#define MCM_LMFATR_PEFPRT_SHIFT                  (0U)
/*! PEFPRT - Parity Fault Protection Signal */
#define MCM_LMFATR_PEFPRT(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFPRT_SHIFT)) & MCM_LMFATR_PEFPRT_MASK)

#define MCM_LMFATR_PEFSIZE_MASK                  (0x70U)
#define MCM_LMFATR_PEFSIZE_SHIFT                 (4U)
/*! PEFSIZE - PEFSIZE
 *  0b000..8-bit access
 *  0b001..16-bit access
 *  0b010..32-bit access
 *  0b011..64-bit access
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MCM_LMFATR_PEFSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFSIZE_SHIFT)) & MCM_LMFATR_PEFSIZE_MASK)

#define MCM_LMFATR_PEFW_MASK                     (0x80U)
#define MCM_LMFATR_PEFW_SHIFT                    (7U)
/*! PEFW - Parity Fault Write
 *  0b0..Read fault
 *  0b1..Write fault
 */
#define MCM_LMFATR_PEFW(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFW_SHIFT)) & MCM_LMFATR_PEFW_MASK)

#define MCM_LMFATR_BKD_MASK                      (0x8000U)
#define MCM_LMFATR_BKD_SHIFT                     (15U)
/*! BKD - Backdoor Access
 *  0b0..Core access
 *  0b1..Backdoor access
 */
#define MCM_LMFATR_BKD(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_BKD_SHIFT)) & MCM_LMFATR_BKD_MASK)

#define MCM_LMFATR_PEFSYN_MASK                   (0xFF0000U)
#define MCM_LMFATR_PEFSYN_SHIFT                  (16U)
/*! PEFSYN - Parity Fault Syndrome */
#define MCM_LMFATR_PEFSYN(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFSYN_SHIFT)) & MCM_LMFATR_PEFSYN_MASK)

#define MCM_LMFATR_OVR_MASK                      (0x80000000U)
#define MCM_LMFATR_OVR_SHIFT                     (31U)
/*! OVR - Overrun
 *  0b0..There is sigle fault or no fault.
 *  0b1..There are multiple faults
 */
#define MCM_LMFATR_OVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_OVR_SHIFT)) & MCM_LMFATR_OVR_MASK)
/*! @} */

/*! @name LMFDHR - LMEM Fault Data High */
/*! @{ */

#define MCM_LMFDHR_PEFDH_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDHR_PEFDH_SHIFT                   (0U)
/*! PEFDH - PEFDH */
#define MCM_LMFDHR_PEFDH(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMFDHR_PEFDH_SHIFT)) & MCM_LMFDHR_PEFDH_MASK)
/*! @} */

/*! @name LMFDLR - LMEM Fault Data Low */
/*! @{ */

#define MCM_LMFDLR_PEFDL_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDLR_PEFDL_SHIFT                   (0U)
/*! PEFDL - PEFDL */
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

