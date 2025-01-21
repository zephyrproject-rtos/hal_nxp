/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AON_MCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file AON_MCM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AON_MCM
 *
 * CMSIS Peripheral Access Layer for AON_MCM
 */

#if !defined(AON_MCM_H_)
#define AON_MCM_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- AON_MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_MCM_Peripheral_Access_Layer AON_MCM Peripheral Access Layer
 * @{
 */

/** AON_MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t ISCR;                              /**< Interrupt Status and Control, offset: 0x10 */
  __IO uint32_t ETBCC;                             /**< ETB Counter Control, offset: 0x14 */
  __IO uint32_t ETBRR;                             /**< ETB Reload, offset: 0x18 */
  __I  uint32_t ETBCV;                             /**< ETB Counter Value, offset: 0x1C */
  __I  uint32_t FADR;                              /**< Write Buffer Fault Address, offset: 0x20 */
  __I  uint32_t FATR;                              /**< Store Buffer Fault Attributes, offset: 0x24 */
  __I  uint32_t FDR;                               /**< Store Buffer Fault Data, offset: 0x28 */
} AON_MCM_Type;

/* ----------------------------------------------------------------------------
   -- AON_MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AON_MCM_Register_Masks AON_MCM Register Masks
 * @{
 */

/*! @name ISCR - Interrupt Status and Control */
/*! @{ */

#define AON_MCM_ISCR_IRQ_MASK                    (0x2U)
#define AON_MCM_ISCR_IRQ_SHIFT                   (1U)
/*! IRQ - ETB-Related Interrupt Pending
 *  0b0..No pending IRQ
 *  0b1..Pending IRQ
 */
#define AON_MCM_ISCR_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_IRQ_SHIFT)) & AON_MCM_ISCR_IRQ_MASK)

#define AON_MCM_ISCR_NMI_MASK                    (0x4U)
#define AON_MCM_ISCR_NMI_SHIFT                   (2U)
/*! NMI - Nonmaskable Interrupt Pending
 *  0b0..No pending NMI
 *  0b1..Pending NMI
 */
#define AON_MCM_ISCR_NMI(x)                      (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_NMI_SHIFT)) & AON_MCM_ISCR_NMI_MASK)

#define AON_MCM_ISCR_DHREQ_MASK                  (0x8U)
#define AON_MCM_ISCR_DHREQ_SHIFT                 (3U)
/*! DHREQ - Debug Halt Request Indicator
 *  0b0..Not initiated
 *  0b1..Initiated
 */
#define AON_MCM_ISCR_DHREQ(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_DHREQ_SHIFT)) & AON_MCM_ISCR_DHREQ_MASK)

#define AON_MCM_ISCR_CWBER_MASK                  (0x10U)
#define AON_MCM_ISCR_CWBER_SHIFT                 (4U)
/*! CWBER - Cache Write Buffer Error Status
 *  0b0..No error
 *  0b1..Error occurred
 */
#define AON_MCM_ISCR_CWBER(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_CWBER_SHIFT)) & AON_MCM_ISCR_CWBER_MASK)

#define AON_MCM_ISCR_FIOC_MASK                   (0x100U)
#define AON_MCM_ISCR_FIOC_SHIFT                  (8U)
/*! FIOC - FPU Invalid Operation Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FIOC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIOC_SHIFT)) & AON_MCM_ISCR_FIOC_MASK)

#define AON_MCM_ISCR_FDZC_MASK                   (0x200U)
#define AON_MCM_ISCR_FDZC_SHIFT                  (9U)
/*! FDZC - FPU Divide-by-Zero Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FDZC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FDZC_SHIFT)) & AON_MCM_ISCR_FDZC_MASK)

#define AON_MCM_ISCR_FOFC_MASK                   (0x400U)
#define AON_MCM_ISCR_FOFC_SHIFT                  (10U)
/*! FOFC - FPU Overflow Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FOFC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FOFC_SHIFT)) & AON_MCM_ISCR_FOFC_MASK)

#define AON_MCM_ISCR_FUFC_MASK                   (0x800U)
#define AON_MCM_ISCR_FUFC_SHIFT                  (11U)
/*! FUFC - FPU Underflow Interrupt status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FUFC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FUFC_SHIFT)) & AON_MCM_ISCR_FUFC_MASK)

#define AON_MCM_ISCR_FIXC_MASK                   (0x1000U)
#define AON_MCM_ISCR_FIXC_SHIFT                  (12U)
/*! FIXC - FPU Inexact Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FIXC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIXC_SHIFT)) & AON_MCM_ISCR_FIXC_MASK)

#define AON_MCM_ISCR_FIDC_MASK                   (0x8000U)
#define AON_MCM_ISCR_FIDC_SHIFT                  (15U)
/*! FIDC - FPU Input Denormal Interrupt Status
 *  0b0..No interrupt
 *  0b1..Interrupt occurred
 */
#define AON_MCM_ISCR_FIDC(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIDC_SHIFT)) & AON_MCM_ISCR_FIDC_MASK)

#define AON_MCM_ISCR_CWBEE_MASK                  (0x100000U)
#define AON_MCM_ISCR_CWBEE_SHIFT                 (20U)
/*! CWBEE - Cache Write Buffer Error Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_CWBEE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_CWBEE_SHIFT)) & AON_MCM_ISCR_CWBEE_MASK)

#define AON_MCM_ISCR_FIOCE_MASK                  (0x1000000U)
#define AON_MCM_ISCR_FIOCE_SHIFT                 (24U)
/*! FIOCE - FPU Invalid Operation Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FIOCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIOCE_SHIFT)) & AON_MCM_ISCR_FIOCE_MASK)

#define AON_MCM_ISCR_FDZCE_MASK                  (0x2000000U)
#define AON_MCM_ISCR_FDZCE_SHIFT                 (25U)
/*! FDZCE - FPU Divide-by-Zero Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FDZCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FDZCE_SHIFT)) & AON_MCM_ISCR_FDZCE_MASK)

#define AON_MCM_ISCR_FOFCE_MASK                  (0x4000000U)
#define AON_MCM_ISCR_FOFCE_SHIFT                 (26U)
/*! FOFCE - FPU Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FOFCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FOFCE_SHIFT)) & AON_MCM_ISCR_FOFCE_MASK)

#define AON_MCM_ISCR_FUFCE_MASK                  (0x8000000U)
#define AON_MCM_ISCR_FUFCE_SHIFT                 (27U)
/*! FUFCE - FPU Underflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FUFCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FUFCE_SHIFT)) & AON_MCM_ISCR_FUFCE_MASK)

#define AON_MCM_ISCR_FIXCE_MASK                  (0x10000000U)
#define AON_MCM_ISCR_FIXCE_SHIFT                 (28U)
/*! FIXCE - FPU Inexact Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FIXCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIXCE_SHIFT)) & AON_MCM_ISCR_FIXCE_MASK)

#define AON_MCM_ISCR_FIDCE_MASK                  (0x80000000U)
#define AON_MCM_ISCR_FIDCE_SHIFT                 (31U)
/*! FIDCE - FPU Input Denormal Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ISCR_FIDCE(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ISCR_FIDCE_SHIFT)) & AON_MCM_ISCR_FIDCE_MASK)
/*! @} */

/*! @name ETBCC - ETB Counter Control */
/*! @{ */

#define AON_MCM_ETBCC_CNTEN_MASK                 (0x1U)
#define AON_MCM_ETBCC_CNTEN_SHIFT                (0U)
/*! CNTEN - Counter Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define AON_MCM_ETBCC_CNTEN(x)                   (((uint32_t)(((uint32_t)(x)) << AON_MCM_ETBCC_CNTEN_SHIFT)) & AON_MCM_ETBCC_CNTEN_MASK)

#define AON_MCM_ETBCC_RSPT_MASK                  (0x6U)
#define AON_MCM_ETBCC_RSPT_SHIFT                 (1U)
/*! RSPT - Response Type
 *  0b00..No response
 *  0b01..Generate a normal interrupt
 *  0b10..Generate an NMI
 *  0b11..Generate a debug halt
 */
#define AON_MCM_ETBCC_RSPT(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ETBCC_RSPT_SHIFT)) & AON_MCM_ETBCC_RSPT_MASK)

#define AON_MCM_ETBCC_RLRQ_MASK                  (0x8U)
#define AON_MCM_ETBCC_RLRQ_SHIFT                 (3U)
/*! RLRQ - Reload Request
 *  0b0..No effect
 *  0b1..Reload the counter (clear pending interrupt requests)
 */
#define AON_MCM_ETBCC_RLRQ(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_ETBCC_RLRQ_SHIFT)) & AON_MCM_ETBCC_RLRQ_MASK)
/*! @} */

/*! @name ETBRR - ETB Reload */
/*! @{ */

#define AON_MCM_ETBRR_RELOAD_MASK                (0x7FFU)
#define AON_MCM_ETBRR_RELOAD_SHIFT               (0U)
/*! RELOAD - Byte Count Reload Value */
#define AON_MCM_ETBRR_RELOAD(x)                  (((uint32_t)(((uint32_t)(x)) << AON_MCM_ETBRR_RELOAD_SHIFT)) & AON_MCM_ETBRR_RELOAD_MASK)
/*! @} */

/*! @name ETBCV - ETB Counter Value */
/*! @{ */

#define AON_MCM_ETBCV_COUNTER_MASK               (0x7FFU)
#define AON_MCM_ETBCV_COUNTER_SHIFT              (0U)
/*! COUNTER - Byte Count Counter Value */
#define AON_MCM_ETBCV_COUNTER(x)                 (((uint32_t)(((uint32_t)(x)) << AON_MCM_ETBCV_COUNTER_SHIFT)) & AON_MCM_ETBCV_COUNTER_MASK)
/*! @} */

/*! @name FADR - Write Buffer Fault Address */
/*! @{ */

#define AON_MCM_FADR_ADDRESS_MASK                (0xFFFFFFFFU)
#define AON_MCM_FADR_ADDRESS_SHIFT               (0U)
/*! ADDRESS - Fault Address */
#define AON_MCM_FADR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x)) << AON_MCM_FADR_ADDRESS_SHIFT)) & AON_MCM_FADR_ADDRESS_MASK)
/*! @} */

/*! @name FATR - Store Buffer Fault Attributes */
/*! @{ */

#define AON_MCM_FATR_BEDA_MASK                   (0x1U)
#define AON_MCM_FATR_BEDA_SHIFT                  (0U)
/*! BEDA - Bus Error Data Access Type
 *  0b0..Instruction
 *  0b1..Data
 */
#define AON_MCM_FATR_BEDA(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BEDA_SHIFT)) & AON_MCM_FATR_BEDA_MASK)

#define AON_MCM_FATR_BEMD_MASK                   (0x2U)
#define AON_MCM_FATR_BEMD_SHIFT                  (1U)
/*! BEMD - Bus Error Privilege Level
 *  0b0..User mode
 *  0b1..Supervisor or privileged mode
 */
#define AON_MCM_FATR_BEMD(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BEMD_SHIFT)) & AON_MCM_FATR_BEMD_MASK)

#define AON_MCM_FATR_BESZ_MASK                   (0x30U)
#define AON_MCM_FATR_BESZ_SHIFT                  (4U)
/*! BESZ - Bus Error Size
 *  0b00..8-bit
 *  0b01..16-bit
 *  0b10..32-bit
 *  0b11..
 */
#define AON_MCM_FATR_BESZ(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BESZ_SHIFT)) & AON_MCM_FATR_BESZ_MASK)

#define AON_MCM_FATR_BEWT_MASK                   (0x80U)
#define AON_MCM_FATR_BEWT_SHIFT                  (7U)
/*! BEWT - Bus Error Write
 *  0b0..Read
 *  0b1..Write
 */
#define AON_MCM_FATR_BEWT(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BEWT_SHIFT)) & AON_MCM_FATR_BEWT_MASK)

#define AON_MCM_FATR_BEMN_MASK                   (0xF00U)
#define AON_MCM_FATR_BEMN_SHIFT                  (8U)
/*! BEMN - Bus Error Master Number */
#define AON_MCM_FATR_BEMN(x)                     (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BEMN_SHIFT)) & AON_MCM_FATR_BEMN_MASK)

#define AON_MCM_FATR_BEOVR_MASK                  (0x80000000U)
#define AON_MCM_FATR_BEOVR_SHIFT                 (31U)
/*! BEOVR - Bus Error Overrun
 *  0b0..No overrun
 *  0b1..Overrun
 */
#define AON_MCM_FATR_BEOVR(x)                    (((uint32_t)(((uint32_t)(x)) << AON_MCM_FATR_BEOVR_SHIFT)) & AON_MCM_FATR_BEOVR_MASK)
/*! @} */

/*! @name FDR - Store Buffer Fault Data */
/*! @{ */

#define AON_MCM_FDR_DATA_MASK                    (0xFFFFFFFFU)
#define AON_MCM_FDR_DATA_SHIFT                   (0U)
/*! DATA - Fault Data */
#define AON_MCM_FDR_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << AON_MCM_FDR_DATA_SHIFT)) & AON_MCM_FDR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AON_MCM_Register_Masks */


/*!
 * @}
 */ /* end of group AON_MCM_Peripheral_Access_Layer */


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


#endif  /* AON_MCM_H_ */

