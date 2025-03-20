/*
** ###################################################################
**     Processors:          KW47B42Z83AFTA_cm33_core0
**                          KW47B42Z83AFTA_cm33_core1
**                          KW47B42Z96AFTA_cm33_core0
**                          KW47B42Z96AFTA_cm33_core1
**                          KW47B42Z97AFTA_cm33_core0
**                          KW47B42Z97AFTA_cm33_core1
**                          KW47B42ZB2AFTA_cm33_core0
**                          KW47B42ZB2AFTA_cm33_core1
**                          KW47B42ZB3AFTA_cm33_core0
**                          KW47B42ZB3AFTA_cm33_core1
**                          KW47B42ZB6AFTA_cm33_core0
**                          KW47B42ZB6AFTA_cm33_core1
**                          KW47B42ZB7AFTA_cm33_core0
**                          KW47B42ZB7AFTA_cm33_core1
**                          KW47Z42082AFTA
**                          KW47Z42092AFTA
**                          KW47Z420B2AFTA
**                          KW47Z420B3AFTA
**
**     Version:             rev. 1.0, 2024-10-13
**     Build:               b241128
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UART
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**
** ###################################################################
*/

/*!
 * @file UART.h
 * @version 1.0
 * @date 2024-10-13
 * @brief CMSIS Peripheral Access Layer for UART
 *
 * CMSIS Peripheral Access Layer for UART
 */

#if !defined(UART_H_)
#define UART_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW47B42Z83AFTA_cm33_core0))
#include "KW47B42Z83_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z83AFTA_cm33_core1))
#include "KW47B42Z83_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core0))
#include "KW47B42Z96_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core1))
#include "KW47B42Z96_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core0))
#include "KW47B42Z97_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core1))
#include "KW47B42Z97_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core0))
#include "KW47B42ZB2_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core1))
#include "KW47B42ZB2_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core0))
#include "KW47B42ZB3_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core1))
#include "KW47B42ZB3_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core0))
#include "KW47B42ZB6_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core1))
#include "KW47B42ZB6_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0))
#include "KW47B42ZB7_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1))
#include "KW47B42ZB7_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47Z42082AFTA))
#include "KW47Z42082_COMMON.h"
#elif (defined(CPU_KW47Z42092AFTA))
#include "KW47Z42092_COMMON.h"
#elif (defined(CPU_KW47Z420B2AFTA))
#include "KW47Z420B2_COMMON.h"
#elif (defined(CPU_KW47Z420B3AFTA))
#include "KW47Z420B3_COMMON.h"
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
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[64];
  __IO uint16_t BRB_THR_DLL;                       /**< ", offset: 0x40 */
       uint8_t RESERVED_1[2];
  __IO uint16_t DLH_IER;                           /**< ", offset: 0x44 */
       uint8_t RESERVED_2[2];
  __IO uint16_t IIR_FCR;                           /**< ", offset: 0x48 */
       uint8_t RESERVED_3[2];
  __IO uint16_t LCR;                               /**< Line Control, offset: 0x4C */
       uint8_t RESERVED_4[2];
  __IO uint16_t MCR;                               /**< Modem Control, offset: 0x50 */
       uint8_t RESERVED_5[2];
  __I  uint16_t LSR;                               /**< Line Status, offset: 0x54 */
       uint8_t RESERVED_6[2];
  __I  uint16_t MSR;                               /**< Modem Status, offset: 0x58 */
       uint8_t RESERVED_7[2];
  __IO uint16_t SCR;                               /**< Scratch Pad, offset: 0x5C */
       uint8_t RESERVED_8[94];
  __I  uint16_t USR;                               /**< UART Status, offset: 0xBC */
       uint8_t RESERVED_9[2];
  __IO uint16_t TFL;                               /**< Transmit FIFO Level, offset: 0xC0 */
       uint8_t RESERVED_10[2];
  __IO uint16_t RFL;                               /**< Receive FIFO Level, offset: 0xC4 */
} UART_Type;

/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/*! @name BRB_THR_DLL - " */
/*! @{ */

#define UART_BRB_THR_DLL_BRB_THR_DLL_MASK        (0xFFU)
#define UART_BRB_THR_DLL_BRB_THR_DLL_SHIFT       (0U)
/*! brb_thr_dll - " */
#define UART_BRB_THR_DLL_BRB_THR_DLL(x)          (((uint16_t)(((uint16_t)(x)) << UART_BRB_THR_DLL_BRB_THR_DLL_SHIFT)) & UART_BRB_THR_DLL_BRB_THR_DLL_MASK)
/*! @} */

/*! @name DLH_IER - " */
/*! @{ */

#define UART_DLH_IER_DLH_IER_MASK                (0xFFU)
#define UART_DLH_IER_DLH_IER_SHIFT               (0U)
/*! dlh_ier - " */
#define UART_DLH_IER_DLH_IER(x)                  (((uint16_t)(((uint16_t)(x)) << UART_DLH_IER_DLH_IER_SHIFT)) & UART_DLH_IER_DLH_IER_MASK)
/*! @} */

/*! @name IIR_FCR - " */
/*! @{ */

#define UART_IIR_FCR_IIR_FCR_MASK                (0xFFU)
#define UART_IIR_FCR_IIR_FCR_SHIFT               (0U)
/*! iir_fcr - " */
#define UART_IIR_FCR_IIR_FCR(x)                  (((uint16_t)(((uint16_t)(x)) << UART_IIR_FCR_IIR_FCR_SHIFT)) & UART_IIR_FCR_IIR_FCR_MASK)
/*! @} */

/*! @name LCR - Line Control */
/*! @{ */

#define UART_LCR_WLS_MASK                        (0x3U)
#define UART_LCR_WLS_SHIFT                       (0U)
/*! WLS - " */
#define UART_LCR_WLS(x)                          (((uint16_t)(((uint16_t)(x)) << UART_LCR_WLS_SHIFT)) & UART_LCR_WLS_MASK)

#define UART_LCR_STOP_MASK                       (0x4U)
#define UART_LCR_STOP_SHIFT                      (2U)
#define UART_LCR_STOP(x)                         (((uint16_t)(((uint16_t)(x)) << UART_LCR_STOP_SHIFT)) & UART_LCR_STOP_MASK)

#define UART_LCR_PAR_EN_MASK                     (0x8U)
#define UART_LCR_PAR_EN_SHIFT                    (3U)
#define UART_LCR_PAR_EN(x)                       (((uint16_t)(((uint16_t)(x)) << UART_LCR_PAR_EN_SHIFT)) & UART_LCR_PAR_EN_MASK)

#define UART_LCR_PAR_SEL_MASK                    (0x10U)
#define UART_LCR_PAR_SEL_SHIFT                   (4U)
/*! Par_Sel - " */
#define UART_LCR_PAR_SEL(x)                      (((uint16_t)(((uint16_t)(x)) << UART_LCR_PAR_SEL_SHIFT)) & UART_LCR_PAR_SEL_MASK)

#define UART_LCR_BRK_MASK                        (0x40U)
#define UART_LCR_BRK_SHIFT                       (6U)
#define UART_LCR_BRK(x)                          (((uint16_t)(((uint16_t)(x)) << UART_LCR_BRK_SHIFT)) & UART_LCR_BRK_MASK)

#define UART_LCR_DIV_LATCH_RD_WRT_MASK           (0x80U)
#define UART_LCR_DIV_LATCH_RD_WRT_SHIFT          (7U)
/*! Div_Latch_Rd_Wrt - " */
#define UART_LCR_DIV_LATCH_RD_WRT(x)             (((uint16_t)(((uint16_t)(x)) << UART_LCR_DIV_LATCH_RD_WRT_SHIFT)) & UART_LCR_DIV_LATCH_RD_WRT_MASK)
/*! @} */

/*! @name MCR - Modem Control */
/*! @{ */

#define UART_MCR_DTR_POL_MASK                    (0x1U)
#define UART_MCR_DTR_POL_SHIFT                   (0U)
/*! DTR_Pol - " */
#define UART_MCR_DTR_POL(x)                      (((uint16_t)(((uint16_t)(x)) << UART_MCR_DTR_POL_SHIFT)) & UART_MCR_DTR_POL_MASK)

#define UART_MCR_RTS_POL_MASK                    (0x2U)
#define UART_MCR_RTS_POL_SHIFT                   (1U)
/*! RTS_Pol - " */
#define UART_MCR_RTS_POL(x)                      (((uint16_t)(((uint16_t)(x)) << UART_MCR_RTS_POL_SHIFT)) & UART_MCR_RTS_POL_MASK)

#define UART_MCR_OUT_POL_MASK                    (0x4U)
#define UART_MCR_OUT_POL_SHIFT                   (2U)
#define UART_MCR_OUT_POL(x)                      (((uint16_t)(((uint16_t)(x)) << UART_MCR_OUT_POL_SHIFT)) & UART_MCR_OUT_POL_MASK)

#define UART_MCR_OUT2_POL_MASK                   (0x8U)
#define UART_MCR_OUT2_POL_SHIFT                  (3U)
#define UART_MCR_OUT2_POL(x)                     (((uint16_t)(((uint16_t)(x)) << UART_MCR_OUT2_POL_SHIFT)) & UART_MCR_OUT2_POL_MASK)

#define UART_MCR_LOOP_BACK_MASK                  (0x10U)
#define UART_MCR_LOOP_BACK_SHIFT                 (4U)
/*! Loop_Back - " */
#define UART_MCR_LOOP_BACK(x)                    (((uint16_t)(((uint16_t)(x)) << UART_MCR_LOOP_BACK_SHIFT)) & UART_MCR_LOOP_BACK_MASK)

#define UART_MCR_AF_CTRL_EN_MASK                 (0x20U)
#define UART_MCR_AF_CTRL_EN_SHIFT                (5U)
/*! AF_Ctrl_En - " */
#define UART_MCR_AF_CTRL_EN(x)                   (((uint16_t)(((uint16_t)(x)) << UART_MCR_AF_CTRL_EN_SHIFT)) & UART_MCR_AF_CTRL_EN_MASK)

#define UART_MCR_SIR_EN_MASK                     (0x40U)
#define UART_MCR_SIR_EN_SHIFT                    (6U)
/*! SIR_En - " */
#define UART_MCR_SIR_EN(x)                       (((uint16_t)(((uint16_t)(x)) << UART_MCR_SIR_EN_SHIFT)) & UART_MCR_SIR_EN_MASK)
/*! @} */

/*! @name LSR - Line Status */
/*! @{ */

#define UART_LSR_DATA_RX_STAT_MASK               (0x1U)
#define UART_LSR_DATA_RX_STAT_SHIFT              (0U)
#define UART_LSR_DATA_RX_STAT(x)                 (((uint16_t)(((uint16_t)(x)) << UART_LSR_DATA_RX_STAT_SHIFT)) & UART_LSR_DATA_RX_STAT_MASK)

#define UART_LSR_OVERRUN_ERR_MASK                (0x2U)
#define UART_LSR_OVERRUN_ERR_SHIFT               (1U)
/*! Overrun_Err - " */
#define UART_LSR_OVERRUN_ERR(x)                  (((uint16_t)(((uint16_t)(x)) << UART_LSR_OVERRUN_ERR_SHIFT)) & UART_LSR_OVERRUN_ERR_MASK)

#define UART_LSR_PAR_ERR_MASK                    (0x4U)
#define UART_LSR_PAR_ERR_SHIFT                   (2U)
/*! Par_Err - " */
#define UART_LSR_PAR_ERR(x)                      (((uint16_t)(((uint16_t)(x)) << UART_LSR_PAR_ERR_SHIFT)) & UART_LSR_PAR_ERR_MASK)

#define UART_LSR_FRAME_ERR_MASK                  (0x8U)
#define UART_LSR_FRAME_ERR_SHIFT                 (3U)
/*! Frame_Err - " */
#define UART_LSR_FRAME_ERR(x)                    (((uint16_t)(((uint16_t)(x)) << UART_LSR_FRAME_ERR_SHIFT)) & UART_LSR_FRAME_ERR_MASK)

#define UART_LSR_BI_MASK                         (0x10U)
#define UART_LSR_BI_SHIFT                        (4U)
#define UART_LSR_BI(x)                           (((uint16_t)(((uint16_t)(x)) << UART_LSR_BI_SHIFT)) & UART_LSR_BI_MASK)

#define UART_LSR_THRE_MASK                       (0x20U)
#define UART_LSR_THRE_SHIFT                      (5U)
#define UART_LSR_THRE(x)                         (((uint16_t)(((uint16_t)(x)) << UART_LSR_THRE_SHIFT)) & UART_LSR_THRE_MASK)

#define UART_LSR_TX_EMPTY_MASK                   (0x40U)
#define UART_LSR_TX_EMPTY_SHIFT                  (6U)
/*! Tx_Empty - " */
#define UART_LSR_TX_EMPTY(x)                     (((uint16_t)(((uint16_t)(x)) << UART_LSR_TX_EMPTY_SHIFT)) & UART_LSR_TX_EMPTY_MASK)

#define UART_LSR_RX_FIFO_ERR_MASK                (0x80U)
#define UART_LSR_RX_FIFO_ERR_SHIFT               (7U)
#define UART_LSR_RX_FIFO_ERR(x)                  (((uint16_t)(((uint16_t)(x)) << UART_LSR_RX_FIFO_ERR_SHIFT)) & UART_LSR_RX_FIFO_ERR_MASK)
/*! @} */

/*! @name MSR - Modem Status */
/*! @{ */

#define UART_MSR_DCTS_MASK                       (0x1U)
#define UART_MSR_DCTS_SHIFT                      (0U)
#define UART_MSR_DCTS(x)                         (((uint16_t)(((uint16_t)(x)) << UART_MSR_DCTS_SHIFT)) & UART_MSR_DCTS_MASK)

#define UART_MSR_DDSR_MASK                       (0x2U)
#define UART_MSR_DDSR_SHIFT                      (1U)
#define UART_MSR_DDSR(x)                         (((uint16_t)(((uint16_t)(x)) << UART_MSR_DDSR_SHIFT)) & UART_MSR_DDSR_MASK)

#define UART_MSR_TERI_MASK                       (0x4U)
#define UART_MSR_TERI_SHIFT                      (2U)
#define UART_MSR_TERI(x)                         (((uint16_t)(((uint16_t)(x)) << UART_MSR_TERI_SHIFT)) & UART_MSR_TERI_MASK)

#define UART_MSR_DDCD_MASK                       (0x8U)
#define UART_MSR_DDCD_SHIFT                      (3U)
#define UART_MSR_DDCD(x)                         (((uint16_t)(((uint16_t)(x)) << UART_MSR_DDCD_SHIFT)) & UART_MSR_DDCD_MASK)

#define UART_MSR_CTS_MASK                        (0x10U)
#define UART_MSR_CTS_SHIFT                       (4U)
#define UART_MSR_CTS(x)                          (((uint16_t)(((uint16_t)(x)) << UART_MSR_CTS_SHIFT)) & UART_MSR_CTS_MASK)

#define UART_MSR_DSR_MASK                        (0x20U)
#define UART_MSR_DSR_SHIFT                       (5U)
#define UART_MSR_DSR(x)                          (((uint16_t)(((uint16_t)(x)) << UART_MSR_DSR_SHIFT)) & UART_MSR_DSR_MASK)

#define UART_MSR_RI_MASK                         (0x40U)
#define UART_MSR_RI_SHIFT                        (6U)
#define UART_MSR_RI(x)                           (((uint16_t)(((uint16_t)(x)) << UART_MSR_RI_SHIFT)) & UART_MSR_RI_MASK)

#define UART_MSR_DCD_MASK                        (0x80U)
#define UART_MSR_DCD_SHIFT                       (7U)
/*! DCD - " */
#define UART_MSR_DCD(x)                          (((uint16_t)(((uint16_t)(x)) << UART_MSR_DCD_SHIFT)) & UART_MSR_DCD_MASK)
/*! @} */

/*! @name SCR - Scratch Pad */
/*! @{ */

#define UART_SCR_SCRATCH_MASK                    (0xFFU)
#define UART_SCR_SCRATCH_SHIFT                   (0U)
#define UART_SCR_SCRATCH(x)                      (((uint16_t)(((uint16_t)(x)) << UART_SCR_SCRATCH_SHIFT)) & UART_SCR_SCRATCH_MASK)
/*! @} */

/*! @name USR - UART Status */
/*! @{ */

#define UART_USR_UART_BUSY_MASK                  (0x1U)
#define UART_USR_UART_BUSY_SHIFT                 (0U)
#define UART_USR_UART_BUSY(x)                    (((uint16_t)(((uint16_t)(x)) << UART_USR_UART_BUSY_SHIFT)) & UART_USR_UART_BUSY_MASK)

#define UART_USR_TX_FIFO_NOT_FULL_MASK           (0x2U)
#define UART_USR_TX_FIFO_NOT_FULL_SHIFT          (1U)
/*! Tx_FIFO_Not_Full - " */
#define UART_USR_TX_FIFO_NOT_FULL(x)             (((uint16_t)(((uint16_t)(x)) << UART_USR_TX_FIFO_NOT_FULL_SHIFT)) & UART_USR_TX_FIFO_NOT_FULL_MASK)

#define UART_USR_TX_FIFO_EMPTY_MASK              (0x4U)
#define UART_USR_TX_FIFO_EMPTY_SHIFT             (2U)
#define UART_USR_TX_FIFO_EMPTY(x)                (((uint16_t)(((uint16_t)(x)) << UART_USR_TX_FIFO_EMPTY_SHIFT)) & UART_USR_TX_FIFO_EMPTY_MASK)

#define UART_USR_RX_FIFO_NOT_EMPTY_MASK          (0x8U)
#define UART_USR_RX_FIFO_NOT_EMPTY_SHIFT         (3U)
#define UART_USR_RX_FIFO_NOT_EMPTY(x)            (((uint16_t)(((uint16_t)(x)) << UART_USR_RX_FIFO_NOT_EMPTY_SHIFT)) & UART_USR_RX_FIFO_NOT_EMPTY_MASK)

#define UART_USR_RX_FIFO_FULL_MASK               (0x10U)
#define UART_USR_RX_FIFO_FULL_SHIFT              (4U)
/*! Rx_FIFO_Full - " */
#define UART_USR_RX_FIFO_FULL(x)                 (((uint16_t)(((uint16_t)(x)) << UART_USR_RX_FIFO_FULL_SHIFT)) & UART_USR_RX_FIFO_FULL_MASK)
/*! @} */

/*! @name TFL - Transmit FIFO Level */
/*! @{ */

#define UART_TFL_FIFO_ADDR_WIDTH_MASK            (0x1U)
#define UART_TFL_FIFO_ADDR_WIDTH_SHIFT           (0U)
#define UART_TFL_FIFO_ADDR_WIDTH(x)              (((uint16_t)(((uint16_t)(x)) << UART_TFL_FIFO_ADDR_WIDTH_SHIFT)) & UART_TFL_FIFO_ADDR_WIDTH_MASK)
/*! @} */

/*! @name RFL - Receive FIFO Level */
/*! @{ */

#define UART_RFL_FIF_ADDR_WIDTH_MASK             (0x1U)
#define UART_RFL_FIF_ADDR_WIDTH_SHIFT            (0U)
#define UART_RFL_FIF_ADDR_WIDTH(x)               (((uint16_t)(((uint16_t)(x)) << UART_RFL_FIF_ADDR_WIDTH_SHIFT)) & UART_RFL_FIF_ADDR_WIDTH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UART_Register_Masks */


/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


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


#endif  /* UART_H_ */

