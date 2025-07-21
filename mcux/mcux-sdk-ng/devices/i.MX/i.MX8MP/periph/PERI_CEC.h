/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CEC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CEC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CEC
 *
 * CMSIS Peripheral Access Layer for CEC
 */

#if !defined(PERI_CEC_H_)
#define PERI_CEC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CEC_Peripheral_Access_Layer CEC Peripheral Access Layer
 * @{
 */

/** CEC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CEC_CTRL;                           /**< CEC Control Register This register handles the main control of the CEC initiator., offset: 0x0 */
       uint8_t RESERVED_0[1];
  __IO uint8_t CEC_MASK;                           /**< CEC Interrupt Mask Register This read/write register masks/unmasks the interrupt events., offset: 0x2 */
       uint8_t RESERVED_1[2];
  __IO uint8_t CEC_ADDR_L;                         /**< CEC Logical Address Register Low This register indicates the logical address(es) allocated to the CEC device., offset: 0x5 */
  __IO uint8_t CEC_ADDR_H;                         /**< CEC Logical Address Register High This register indicates the logical address(es) allocated to the CEC device., offset: 0x6 */
  __IO uint8_t CEC_TX_CNT;                         /**< CEC TX Frame Size Register This register indicates the size of the frame in bytes (including header and data blocks), which are available in the transmitter data buffer., offset: 0x7 */
  __I  uint8_t CEC_RX_CNT;                         /**< CEC RX Frame Size Register This register indicates the size of the frame in bytes (including header and data blocks), which are available in the receiver data buffer., offset: 0x8 */
       uint8_t RESERVED_2[39];
  __IO uint8_t CEC_LOCK;                           /**< CEC Buffer Lock Register, offset: 0x30 */
  __IO uint8_t CEC_WAKEUPCTRL;                     /**< CEC Wake-up Control Register After receiving a message in the CEC_RX_DATA1 (OPCODE) registers, the CEC engine verifies the message opcode[7:0] against one of the previously defined values to generate the wake-up status: Wakeupstatus is 1 when: received opcode is 0x04 and opcode0x04en is 1 or received opcode is 0x0D and opcode0x0Den is 1 or received opcode is 0x41 and opcode0x41en is 1 or received opcode is 0x42 and opcode0x42en is 1 or received opcode is 0x44 and opcode0x44en is 1 or received opcode is 0x70 and opcode0x70en is 1 or received opcode is 0x82 and opcode0x82en is 1 or received opcode is 0x86 and opcode0x86en is 1 Wakeupstatus is 0 when none of the previous conditions are true., offset: 0x31 */
} CEC_Type;

/* ----------------------------------------------------------------------------
   -- CEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CEC_Register_Masks CEC Register Masks
 * @{
 */

/*! @name CEC_CTRL - CEC Control Register This register handles the main control of the CEC initiator. */
/*! @{ */

#define CEC_CEC_CTRL_SEND_MASK                   (0x1U)
#define CEC_CEC_CTRL_SEND_SHIFT                  (0U)
/*! send - - 1'b1: Set by software to trigger CEC sending a frame as an initiator. */
#define CEC_CEC_CTRL_SEND(x)                     (((uint8_t)(((uint8_t)(x)) << CEC_CEC_CTRL_SEND_SHIFT)) & CEC_CEC_CTRL_SEND_MASK)

#define CEC_CEC_CTRL_FRAME_TYP_MASK              (0x6U)
#define CEC_CEC_CTRL_FRAME_TYP_SHIFT             (1U)
/*! frame_typ - - 2'b00: Signal Free Time = 3-bit periods. */
#define CEC_CEC_CTRL_FRAME_TYP(x)                (((uint8_t)(((uint8_t)(x)) << CEC_CEC_CTRL_FRAME_TYP_SHIFT)) & CEC_CEC_CTRL_FRAME_TYP_MASK)

#define CEC_CEC_CTRL_BC_NACK_MASK                (0x8U)
#define CEC_CEC_CTRL_BC_NACK_SHIFT               (3U)
/*! bc_nack - - 1'b1: Set by software to NACK the received broadcast message. */
#define CEC_CEC_CTRL_BC_NACK(x)                  (((uint8_t)(((uint8_t)(x)) << CEC_CEC_CTRL_BC_NACK_SHIFT)) & CEC_CEC_CTRL_BC_NACK_MASK)

#define CEC_CEC_CTRL_STANDBY_MASK                (0x10U)
#define CEC_CEC_CTRL_STANDBY_SHIFT               (4U)
/*! standby - - 1: CEC controller responds with a NACK to all messages and generates a wakeup status for opcode. */
#define CEC_CEC_CTRL_STANDBY(x)                  (((uint8_t)(((uint8_t)(x)) << CEC_CEC_CTRL_STANDBY_SHIFT)) & CEC_CEC_CTRL_STANDBY_MASK)

#define CEC_CEC_CTRL_SLOWDRVSUPPORT_DISABLE_MASK (0x20U)
#define CEC_CEC_CTRL_SLOWDRVSUPPORT_DISABLE_SHIFT (5U)
/*! slowdrvsupport_disable - - 1: CEC controller supports IO drivers with risetime of up to 1 CEC clock period. */
#define CEC_CEC_CTRL_SLOWDRVSUPPORT_DISABLE(x)   (((uint8_t)(((uint8_t)(x)) << CEC_CEC_CTRL_SLOWDRVSUPPORT_DISABLE_SHIFT)) & CEC_CEC_CTRL_SLOWDRVSUPPORT_DISABLE_MASK)
/*! @} */

/*! @name CEC_MASK - CEC Interrupt Mask Register This read/write register masks/unmasks the interrupt events. */
/*! @{ */

#define CEC_CEC_MASK_DONE_MASK                   (0x1U)
#define CEC_CEC_MASK_DONE_SHIFT                  (0U)
/*! done - The current transmission is successful (for initiator only) */
#define CEC_CEC_MASK_DONE(x)                     (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_DONE_SHIFT)) & CEC_CEC_MASK_DONE_MASK)

#define CEC_CEC_MASK_EOM_MASK                    (0x2U)
#define CEC_CEC_MASK_EOM_SHIFT                   (1U)
/*! eom - EOM is detected so that the received data is ready in the receiver data buffer (for follower only) */
#define CEC_CEC_MASK_EOM(x)                      (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_EOM_SHIFT)) & CEC_CEC_MASK_EOM_MASK)

#define CEC_CEC_MASK_NACK_MASK                   (0x4U)
#define CEC_CEC_MASK_NACK_SHIFT                  (2U)
/*! nack - A frame is not acknowledged in a directly addressed message. */
#define CEC_CEC_MASK_NACK(x)                     (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_NACK_SHIFT)) & CEC_CEC_MASK_NACK_MASK)

#define CEC_CEC_MASK_ARB_LOST_MASK               (0x8U)
#define CEC_CEC_MASK_ARB_LOST_SHIFT              (3U)
/*! arb_lost - The initiator losses the CEC line arbitration to a second initiator. */
#define CEC_CEC_MASK_ARB_LOST(x)                 (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_ARB_LOST_SHIFT)) & CEC_CEC_MASK_ARB_LOST_MASK)

#define CEC_CEC_MASK_ERROR_INITIATOR_MASK        (0x10U)
#define CEC_CEC_MASK_ERROR_INITIATOR_SHIFT       (4U)
/*! error_initiator - An error is detected on a CEC line (for initiator only). */
#define CEC_CEC_MASK_ERROR_INITIATOR(x)          (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_ERROR_INITIATOR_SHIFT)) & CEC_CEC_MASK_ERROR_INITIATOR_MASK)

#define CEC_CEC_MASK_ERROR_FLOW_MASK             (0x20U)
#define CEC_CEC_MASK_ERROR_FLOW_SHIFT            (5U)
/*! error_flow - An error is notified by a follower. */
#define CEC_CEC_MASK_ERROR_FLOW(x)               (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_ERROR_FLOW_SHIFT)) & CEC_CEC_MASK_ERROR_FLOW_MASK)

#define CEC_CEC_MASK_WAKEUP_MASK                 (0x40U)
#define CEC_CEC_MASK_WAKEUP_SHIFT                (6U)
/*! wakeup - Follower wake-up signal mask */
#define CEC_CEC_MASK_WAKEUP(x)                   (((uint8_t)(((uint8_t)(x)) << CEC_CEC_MASK_WAKEUP_SHIFT)) & CEC_CEC_MASK_WAKEUP_MASK)
/*! @} */

/*! @name CEC_ADDR_L - CEC Logical Address Register Low This register indicates the logical address(es) allocated to the CEC device. */
/*! @{ */

#define CEC_CEC_ADDR_L_CEC_ADDR_L_0_MASK         (0x1U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_0_SHIFT        (0U)
/*! cec_addr_l_0 - Logical address 0 - Device TV */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_0(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_0_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_0_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_1_MASK         (0x2U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_1_SHIFT        (1U)
/*! cec_addr_l_1 - Logical address 1 - Recording Device 1 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_1(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_1_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_1_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_2_MASK         (0x4U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_2_SHIFT        (2U)
/*! cec_addr_l_2 - Logical address 2 - Recording Device 2 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_2(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_2_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_2_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_3_MASK         (0x8U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_3_SHIFT        (3U)
/*! cec_addr_l_3 - Logical address 3 - Tuner 1 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_3(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_3_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_3_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_4_MASK         (0x10U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_4_SHIFT        (4U)
/*! cec_addr_l_4 - Logical address 4 - Playback Device 1 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_4(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_4_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_4_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_5_MASK         (0x20U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_5_SHIFT        (5U)
/*! cec_addr_l_5 - Logical address 5 - Audio System */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_5(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_5_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_5_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_6_MASK         (0x40U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_6_SHIFT        (6U)
/*! cec_addr_l_6 - Logical address 6 - Tuner 2 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_6(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_6_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_6_MASK)

#define CEC_CEC_ADDR_L_CEC_ADDR_L_7_MASK         (0x80U)
#define CEC_CEC_ADDR_L_CEC_ADDR_L_7_SHIFT        (7U)
/*! cec_addr_l_7 - Logical address 7 - Tuner 3 */
#define CEC_CEC_ADDR_L_CEC_ADDR_L_7(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_L_CEC_ADDR_L_7_SHIFT)) & CEC_CEC_ADDR_L_CEC_ADDR_L_7_MASK)
/*! @} */

/*! @name CEC_ADDR_H - CEC Logical Address Register High This register indicates the logical address(es) allocated to the CEC device. */
/*! @{ */

#define CEC_CEC_ADDR_H_CEC_ADDR_H_0_MASK         (0x1U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_0_SHIFT        (0U)
/*! cec_addr_h_0 - Logical address 8 - Playback Device 2 */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_0(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_0_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_0_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_1_MASK         (0x2U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_1_SHIFT        (1U)
/*! cec_addr_h_1 - Logical address 9 - Playback Device 3 */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_1(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_1_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_1_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_2_MASK         (0x4U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_2_SHIFT        (2U)
/*! cec_addr_h_2 - Logical address 10 - Tuner 4 */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_2(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_2_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_2_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_3_MASK         (0x8U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_3_SHIFT        (3U)
/*! cec_addr_h_3 - Logical address 11 - Playback Device 3 */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_3(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_3_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_3_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_4_MASK         (0x10U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_4_SHIFT        (4U)
/*! cec_addr_h_4 - Logical address 12 - Reserved */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_4(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_4_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_4_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_5_MASK         (0x20U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_5_SHIFT        (5U)
/*! cec_addr_h_5 - Logical address 13 - Reserved */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_5(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_5_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_5_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_6_MASK         (0x40U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_6_SHIFT        (6U)
/*! cec_addr_h_6 - Logical address 14 - Free use */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_6(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_6_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_6_MASK)

#define CEC_CEC_ADDR_H_CEC_ADDR_H_7_MASK         (0x80U)
#define CEC_CEC_ADDR_H_CEC_ADDR_H_7_SHIFT        (7U)
/*! cec_addr_h_7 - Logical address 15 - Unregistered (as initiator address), Broadcast (as destination address) */
#define CEC_CEC_ADDR_H_CEC_ADDR_H_7(x)           (((uint8_t)(((uint8_t)(x)) << CEC_CEC_ADDR_H_CEC_ADDR_H_7_SHIFT)) & CEC_CEC_ADDR_H_CEC_ADDR_H_7_MASK)
/*! @} */

/*! @name CEC_TX_CNT - CEC TX Frame Size Register This register indicates the size of the frame in bytes (including header and data blocks), which are available in the transmitter data buffer. */
/*! @{ */

#define CEC_CEC_TX_CNT_CEC_TX_CNT_MASK           (0x1FU)
#define CEC_CEC_TX_CNT_CEC_TX_CNT_SHIFT          (0U)
/*! cec_tx_cnt - CEC Transmitter Counter register 5'd0: No data needs to be transmitted 5'd1: Frame size is 1 byte . */
#define CEC_CEC_TX_CNT_CEC_TX_CNT(x)             (((uint8_t)(((uint8_t)(x)) << CEC_CEC_TX_CNT_CEC_TX_CNT_SHIFT)) & CEC_CEC_TX_CNT_CEC_TX_CNT_MASK)
/*! @} */

/*! @name CEC_RX_CNT - CEC RX Frame Size Register This register indicates the size of the frame in bytes (including header and data blocks), which are available in the receiver data buffer. */
/*! @{ */

#define CEC_CEC_RX_CNT_CEC_RX_CNT_MASK           (0x1FU)
#define CEC_CEC_RX_CNT_CEC_RX_CNT_SHIFT          (0U)
/*! cec_rx_cnt - CEC Receiver Counter register: 5'd0: No data received 5'd1: 1-byte data is received . */
#define CEC_CEC_RX_CNT_CEC_RX_CNT(x)             (((uint8_t)(((uint8_t)(x)) << CEC_CEC_RX_CNT_CEC_RX_CNT_SHIFT)) & CEC_CEC_RX_CNT_CEC_RX_CNT_MASK)
/*! @} */

/*! @name CEC_LOCK - CEC Buffer Lock Register */
/*! @{ */

#define CEC_CEC_LOCK_LOCKED_BUFFER_MASK          (0x1U)
#define CEC_CEC_LOCK_LOCKED_BUFFER_SHIFT         (0U)
/*! locked_buffer - When a frame is received, this bit would be active. */
#define CEC_CEC_LOCK_LOCKED_BUFFER(x)            (((uint8_t)(((uint8_t)(x)) << CEC_CEC_LOCK_LOCKED_BUFFER_SHIFT)) & CEC_CEC_LOCK_LOCKED_BUFFER_MASK)
/*! @} */

/*! @name CEC_WAKEUPCTRL - CEC Wake-up Control Register After receiving a message in the CEC_RX_DATA1 (OPCODE) registers, the CEC engine verifies the message opcode[7:0] against one of the previously defined values to generate the wake-up status: Wakeupstatus is 1 when: received opcode is 0x04 and opcode0x04en is 1 or received opcode is 0x0D and opcode0x0Den is 1 or received opcode is 0x41 and opcode0x41en is 1 or received opcode is 0x42 and opcode0x42en is 1 or received opcode is 0x44 and opcode0x44en is 1 or received opcode is 0x70 and opcode0x70en is 1 or received opcode is 0x82 and opcode0x82en is 1 or received opcode is 0x86 and opcode0x86en is 1 Wakeupstatus is 0 when none of the previous conditions are true. */
/*! @{ */

#define CEC_CEC_WAKEUPCTRL_OPCODE0X04EN_MASK     (0x1U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X04EN_SHIFT    (0U)
/*! opcode0x04en - OPCODE 0x04 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X04EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X04EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X04EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X0DEN_MASK     (0x2U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X0DEN_SHIFT    (1U)
/*! opcode0x0Den - OPCODE 0x0D wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X0DEN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X0DEN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X0DEN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X41EN_MASK     (0x4U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X41EN_SHIFT    (2U)
/*! opcode0x41en - OPCODE 0x41 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X41EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X41EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X41EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X42EN_MASK     (0x8U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X42EN_SHIFT    (3U)
/*! opcode0x42en - OPCODE 0x42 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X42EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X42EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X42EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X44EN_MASK     (0x10U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X44EN_SHIFT    (4U)
/*! opcode0x44en - OPCODE 0x44 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X44EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X44EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X44EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X70EN_MASK     (0x20U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X70EN_SHIFT    (5U)
/*! opcode0x70en - OPCODE 0x70 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X70EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X70EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X70EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X82EN_MASK     (0x40U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X82EN_SHIFT    (6U)
/*! opcode0x82en - OPCODE 0x82 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X82EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X82EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X82EN_MASK)

#define CEC_CEC_WAKEUPCTRL_OPCODE0X86EN_MASK     (0x80U)
#define CEC_CEC_WAKEUPCTRL_OPCODE0X86EN_SHIFT    (7U)
/*! opcode0x86en - OPCODE 0x86 wake up enable */
#define CEC_CEC_WAKEUPCTRL_OPCODE0X86EN(x)       (((uint8_t)(((uint8_t)(x)) << CEC_CEC_WAKEUPCTRL_OPCODE0X86EN_SHIFT)) & CEC_CEC_WAKEUPCTRL_OPCODE0X86EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CEC_Register_Masks */


/*!
 * @}
 */ /* end of group CEC_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_CEC_H_ */

