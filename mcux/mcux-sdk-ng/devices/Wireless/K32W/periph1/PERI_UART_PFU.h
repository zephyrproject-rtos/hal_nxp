/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for UART_PFU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_UART_PFU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for UART_PFU
 *
 * CMSIS Peripheral Access Layer for UART_PFU
 */

#if !defined(PERI_UART_PFU_H_)
#define PERI_UART_PFU_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
   -- UART_PFU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_PFU_Peripheral_Access_Layer UART_PFU Peripheral Access Layer
 * @{
 */

/** UART_PFU - Register Layout Typedef */
typedef struct {
  __IO uint16_t CONTROL;                           /**< ", offset: 0x0 */
       uint8_t RESERVED_0[2];
  __IO uint16_t INTERRUPT_TX_EMPTY_THRESHOLD;      /**< ", offset: 0x4 */
       uint8_t RESERVED_1[2];
  __IO uint16_t INTERRUPT_RX_EMPTY_THRESHOLD;      /**< ", offset: 0x8 */
       uint8_t RESERVED_2[2];
  __IO uint16_t RTS_ASSERT_TRIGGER;                /**< ", offset: 0xC */
       uint8_t RESERVED_3[2];
  __IO uint16_t RX_DEASSERT_TRIGGER;               /**< ", offset: 0x10 */
       uint8_t RESERVED_4[2];
  __IO uint16_t INTERRUPT_EVENT_MASK;              /**< ", offset: 0x14 */
       uint8_t RESERVED_5[2];
  __IO uint16_t INTERRUPT_STATUS_MASK;             /**< ", offset: 0x18 */
       uint8_t RESERVED_6[2];
  __IO uint16_t INTERRUPT_RESET_SELECTION;         /**< ", offset: 0x1C */
       uint8_t RESERVED_7[2];
  __I  uint16_t INTERRUPT_STATUS;                  /**< ", offset: 0x20 */
       uint8_t RESERVED_8[2];
  __I  uint16_t SIU_PFU_STATUS;                    /**< ", offset: 0x24 */
       uint8_t RESERVED_9[2];
  __I  uint16_t SIU_PFU_RFL;                       /**< ", offset: 0x28 */
       uint8_t RESERVED_10[2];
  __I  uint16_t SIU_PFU_TFL;                       /**< ", offset: 0x2C */
       uint8_t RESERVED_11[18];
  __IO uint16_t SIU_COUNT_VALUE_LOW;               /**< ", offset: 0x40 */
       uint8_t RESERVED_12[2];
  __IO uint16_t SIU_COUNT_VALUE_1;                 /**< ", offset: 0x44 */
       uint8_t RESERVED_13[2];
  __IO uint16_t SIU_COUNT_VALUE_2;                 /**< ", offset: 0x48 */
       uint8_t RESERVED_14[2];
  __IO uint16_t SIU_COUNT_VALUE_3;                 /**< ", offset: 0x4C */
       uint8_t RESERVED_15[2];
  __IO uint16_t SIU_MISC;                          /**< ", offset: 0x50 */
} UART_PFU_Type;

/* ----------------------------------------------------------------------------
   -- UART_PFU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_PFU_Register_Masks UART_PFU Register Masks
 * @{
 */

/*! @name CONTROL - " */
/*! @{ */

#define UART_PFU_CONTROL_DEFLT_UART_INT_SEL_MASK (0x1U)
#define UART_PFU_CONTROL_DEFLT_UART_INT_SEL_SHIFT (0U)
/*! Deflt_UART_Int_Sel - Default UART Interrupt Select */
#define UART_PFU_CONTROL_DEFLT_UART_INT_SEL(x)   (((uint16_t)(((uint16_t)(x)) << UART_PFU_CONTROL_DEFLT_UART_INT_SEL_SHIFT)) & UART_PFU_CONTROL_DEFLT_UART_INT_SEL_MASK)

#define UART_PFU_CONTROL_DEFLT_RTS_SEL_MASK      (0x6U)
#define UART_PFU_CONTROL_DEFLT_RTS_SEL_SHIFT     (1U)
/*! Deflt_RTS_Sel - Default RTS Select */
#define UART_PFU_CONTROL_DEFLT_RTS_SEL(x)        (((uint16_t)(((uint16_t)(x)) << UART_PFU_CONTROL_DEFLT_RTS_SEL_SHIFT)) & UART_PFU_CONTROL_DEFLT_RTS_SEL_MASK)

#define UART_PFU_CONTROL_TFL_RFL_MON_SEL_MASK    (0x8U)
#define UART_PFU_CONTROL_TFL_RFL_MON_SEL_SHIFT   (3U)
/*! TFL_RFL_Mon_Sel - TFL RFL Monitor Select */
#define UART_PFU_CONTROL_TFL_RFL_MON_SEL(x)      (((uint16_t)(((uint16_t)(x)) << UART_PFU_CONTROL_TFL_RFL_MON_SEL_SHIFT)) & UART_PFU_CONTROL_TFL_RFL_MON_SEL_MASK)

#define UART_PFU_CONTROL_DEBUG_MON_SEL_MASK      (0x30U)
#define UART_PFU_CONTROL_DEBUG_MON_SEL_SHIFT     (4U)
/*! Debug_Mon_Sel - Debug Moniter Select */
#define UART_PFU_CONTROL_DEBUG_MON_SEL(x)        (((uint16_t)(((uint16_t)(x)) << UART_PFU_CONTROL_DEBUG_MON_SEL_SHIFT)) & UART_PFU_CONTROL_DEBUG_MON_SEL_MASK)
/*! @} */

/*! @name INTERRUPT_TX_EMPTY_THRESHOLD - " */
/*! @{ */

#define UART_PFU_INTERRUPT_TX_EMPTY_THRESHOLD_INT_TX_EMPTY_THR_MASK (0x1FFU)
#define UART_PFU_INTERRUPT_TX_EMPTY_THRESHOLD_INT_TX_EMPTY_THR_SHIFT (0U)
/*! Int_Tx_Empty_Thr - Interrupt Tx Empty Threshold */
#define UART_PFU_INTERRUPT_TX_EMPTY_THRESHOLD_INT_TX_EMPTY_THR(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_TX_EMPTY_THRESHOLD_INT_TX_EMPTY_THR_SHIFT)) & UART_PFU_INTERRUPT_TX_EMPTY_THRESHOLD_INT_TX_EMPTY_THR_MASK)
/*! @} */

/*! @name INTERRUPT_RX_EMPTY_THRESHOLD - " */
/*! @{ */

#define UART_PFU_INTERRUPT_RX_EMPTY_THRESHOLD_INT_RX_THR_MASK (0x1FFU)
#define UART_PFU_INTERRUPT_RX_EMPTY_THRESHOLD_INT_RX_THR_SHIFT (0U)
/*! Int_Rx_Thr - Interrupt Rx Threshold */
#define UART_PFU_INTERRUPT_RX_EMPTY_THRESHOLD_INT_RX_THR(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_RX_EMPTY_THRESHOLD_INT_RX_THR_SHIFT)) & UART_PFU_INTERRUPT_RX_EMPTY_THRESHOLD_INT_RX_THR_MASK)
/*! @} */

/*! @name RTS_ASSERT_TRIGGER - " */
/*! @{ */

#define UART_PFU_RTS_ASSERT_TRIGGER_RX_RTS_ASRT_THR_MASK (0x1FFU)
#define UART_PFU_RTS_ASSERT_TRIGGER_RX_RTS_ASRT_THR_SHIFT (0U)
/*! Rx_RTS_Asrt_Thr - Rx RTS Assert Threshold */
#define UART_PFU_RTS_ASSERT_TRIGGER_RX_RTS_ASRT_THR(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_RTS_ASSERT_TRIGGER_RX_RTS_ASRT_THR_SHIFT)) & UART_PFU_RTS_ASSERT_TRIGGER_RX_RTS_ASRT_THR_MASK)
/*! @} */

/*! @name RX_DEASSERT_TRIGGER - " */
/*! @{ */

#define UART_PFU_RX_DEASSERT_TRIGGER_RX_RTS_DEASRT_THR_MASK (0x1FFU)
#define UART_PFU_RX_DEASSERT_TRIGGER_RX_RTS_DEASRT_THR_SHIFT (0U)
/*! Rx_RTS_Deasrt_Thr - Rx RTS Deassert Threshold */
#define UART_PFU_RX_DEASSERT_TRIGGER_RX_RTS_DEASRT_THR(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_RX_DEASSERT_TRIGGER_RX_RTS_DEASRT_THR_SHIFT)) & UART_PFU_RX_DEASSERT_TRIGGER_RX_RTS_DEASRT_THR_MASK)
/*! @} */

/*! @name INTERRUPT_EVENT_MASK - " */
/*! @{ */

#define UART_PFU_INTERRUPT_EVENT_MASK_DW_APB_UART_MASK_MASK (0x1U)
#define UART_PFU_INTERRUPT_EVENT_MASK_DW_APB_UART_MASK_SHIFT (0U)
/*! DW_APB_UART_Mask - DW APB UART Mask */
#define UART_PFU_INTERRUPT_EVENT_MASK_DW_APB_UART_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_EVENT_MASK_DW_APB_UART_MASK_SHIFT)) & UART_PFU_INTERRUPT_EVENT_MASK_DW_APB_UART_MASK_MASK)

#define UART_PFU_INTERRUPT_EVENT_MASK_INT_TX_EMPTY_MASK_MASK (0x2U)
#define UART_PFU_INTERRUPT_EVENT_MASK_INT_TX_EMPTY_MASK_SHIFT (1U)
/*! Int_Tx_Empty_Mask - Interrupt Tx Empty Mask */
#define UART_PFU_INTERRUPT_EVENT_MASK_INT_TX_EMPTY_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_EVENT_MASK_INT_TX_EMPTY_MASK_SHIFT)) & UART_PFU_INTERRUPT_EVENT_MASK_INT_TX_EMPTY_MASK_MASK)

#define UART_PFU_INTERRUPT_EVENT_MASK_INT_RX_MASK_MASK (0x4U)
#define UART_PFU_INTERRUPT_EVENT_MASK_INT_RX_MASK_SHIFT (2U)
/*! Int_Rx_Mask - Interrupt Rx Mask */
#define UART_PFU_INTERRUPT_EVENT_MASK_INT_RX_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_EVENT_MASK_INT_RX_MASK_SHIFT)) & UART_PFU_INTERRUPT_EVENT_MASK_INT_RX_MASK_MASK)
/*! @} */

/*! @name INTERRUPT_STATUS_MASK - " */
/*! @{ */

#define UART_PFU_INTERRUPT_STATUS_MASK_DW_APB_UART_INT_STATUS_MASK_MASK (0x1U)
#define UART_PFU_INTERRUPT_STATUS_MASK_DW_APB_UART_INT_STATUS_MASK_SHIFT (0U)
/*! DW_APB_UART_Int_Status_Mask - DW APB UART Interrupt Status Mask */
#define UART_PFU_INTERRUPT_STATUS_MASK_DW_APB_UART_INT_STATUS_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_MASK_DW_APB_UART_INT_STATUS_MASK_SHIFT)) & UART_PFU_INTERRUPT_STATUS_MASK_DW_APB_UART_INT_STATUS_MASK_MASK)

#define UART_PFU_INTERRUPT_STATUS_MASK_INT_TX_EMPTY_STATUS_MASK_MASK (0x2U)
#define UART_PFU_INTERRUPT_STATUS_MASK_INT_TX_EMPTY_STATUS_MASK_SHIFT (1U)
/*! Int_Tx_Empty_Status_Mask - Interrupt Tx Empty Status Mask */
#define UART_PFU_INTERRUPT_STATUS_MASK_INT_TX_EMPTY_STATUS_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_MASK_INT_TX_EMPTY_STATUS_MASK_SHIFT)) & UART_PFU_INTERRUPT_STATUS_MASK_INT_TX_EMPTY_STATUS_MASK_MASK)

#define UART_PFU_INTERRUPT_STATUS_MASK_INT_RX_STATUS_MASK_MASK (0x4U)
#define UART_PFU_INTERRUPT_STATUS_MASK_INT_RX_STATUS_MASK_SHIFT (2U)
/*! Int_Rx_Status_Mask - Interrupt Rx Status Mask */
#define UART_PFU_INTERRUPT_STATUS_MASK_INT_RX_STATUS_MASK(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_MASK_INT_RX_STATUS_MASK_SHIFT)) & UART_PFU_INTERRUPT_STATUS_MASK_INT_RX_STATUS_MASK_MASK)
/*! @} */

/*! @name INTERRUPT_RESET_SELECTION - " */
/*! @{ */

#define UART_PFU_INTERRUPT_RESET_SELECTION_IRS_MASK (0x7U)
#define UART_PFU_INTERRUPT_RESET_SELECTION_IRS_SHIFT (0U)
/*! IRS - Interrupt Reset Select Configures to ISR Bit Settings */
#define UART_PFU_INTERRUPT_RESET_SELECTION_IRS(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_RESET_SELECTION_IRS_SHIFT)) & UART_PFU_INTERRUPT_RESET_SELECTION_IRS_MASK)
/*! @} */

/*! @name INTERRUPT_STATUS - " */
/*! @{ */

#define UART_PFU_INTERRUPT_STATUS_DW_APB_UART_INT_MASK (0x1U)
#define UART_PFU_INTERRUPT_STATUS_DW_APB_UART_INT_SHIFT (0U)
/*! DW_APB_UART_Int - DW_APB_UART_Int Status */
#define UART_PFU_INTERRUPT_STATUS_DW_APB_UART_INT(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_DW_APB_UART_INT_SHIFT)) & UART_PFU_INTERRUPT_STATUS_DW_APB_UART_INT_MASK)

#define UART_PFU_INTERRUPT_STATUS_INT_TX_EMPTY_MASK (0x2U)
#define UART_PFU_INTERRUPT_STATUS_INT_TX_EMPTY_SHIFT (1U)
/*! Int_Tx_Empty - Interrupt Tx Empty */
#define UART_PFU_INTERRUPT_STATUS_INT_TX_EMPTY(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_INT_TX_EMPTY_SHIFT)) & UART_PFU_INTERRUPT_STATUS_INT_TX_EMPTY_MASK)

#define UART_PFU_INTERRUPT_STATUS_INT_RX_MASK    (0x4U)
#define UART_PFU_INTERRUPT_STATUS_INT_RX_SHIFT   (2U)
/*! Int_Rx - Interrupt Rx */
#define UART_PFU_INTERRUPT_STATUS_INT_RX(x)      (((uint16_t)(((uint16_t)(x)) << UART_PFU_INTERRUPT_STATUS_INT_RX_SHIFT)) & UART_PFU_INTERRUPT_STATUS_INT_RX_MASK)
/*! @} */

/*! @name SIU_PFU_STATUS - " */
/*! @{ */

#define UART_PFU_SIU_PFU_STATUS_RTS_N_MASK       (0x1U)
#define UART_PFU_SIU_PFU_STATUS_RTS_N_SHIFT      (0U)
/*! RTS_n - RTS_n Signal Status */
#define UART_PFU_SIU_PFU_STATUS_RTS_N(x)         (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_PFU_STATUS_RTS_N_SHIFT)) & UART_PFU_SIU_PFU_STATUS_RTS_N_MASK)

#define UART_PFU_SIU_PFU_STATUS_SIU_PFU_RTS_N_MASK (0x2U)
#define UART_PFU_SIU_PFU_STATUS_SIU_PFU_RTS_N_SHIFT (1U)
/*! SIU_PFU_RTS_n - SIU_PFU_RTS_n Signal Status */
#define UART_PFU_SIU_PFU_STATUS_SIU_PFU_RTS_N(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_PFU_STATUS_SIU_PFU_RTS_N_SHIFT)) & UART_PFU_SIU_PFU_STATUS_SIU_PFU_RTS_N_MASK)
/*! @} */

/*! @name SIU_PFU_RFL - " */
/*! @{ */

#define UART_PFU_SIU_PFU_RFL_RFL_MASK            (0x1FFU)
#define UART_PFU_SIU_PFU_RFL_RFL_SHIFT           (0U)
/*! RFL - Receive FIFO Level */
#define UART_PFU_SIU_PFU_RFL_RFL(x)              (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_PFU_RFL_RFL_SHIFT)) & UART_PFU_SIU_PFU_RFL_RFL_MASK)
/*! @} */

/*! @name SIU_PFU_TFL - " */
/*! @{ */

#define UART_PFU_SIU_PFU_TFL_TFL_MASK            (0x1FFU)
#define UART_PFU_SIU_PFU_TFL_TFL_SHIFT           (0U)
/*! TFL - Transmit FIFO Level */
#define UART_PFU_SIU_PFU_TFL_TFL(x)              (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_PFU_TFL_TFL_SHIFT)) & UART_PFU_SIU_PFU_TFL_TFL_MASK)
/*! @} */

/*! @name SIU_COUNT_VALUE_LOW - " */
/*! @{ */

#define UART_PFU_SIU_COUNT_VALUE_LOW_SIU_CNT_VAL_LOW_MASK (0xFFU)
#define UART_PFU_SIU_COUNT_VALUE_LOW_SIU_CNT_VAL_LOW_SHIFT (0U)
/*! SIU_Cnt_Val_Low - Count Value Low */
#define UART_PFU_SIU_COUNT_VALUE_LOW_SIU_CNT_VAL_LOW(x) (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_COUNT_VALUE_LOW_SIU_CNT_VAL_LOW_SHIFT)) & UART_PFU_SIU_COUNT_VALUE_LOW_SIU_CNT_VAL_LOW_MASK)
/*! @} */

/*! @name SIU_COUNT_VALUE_1 - " */
/*! @{ */

#define UART_PFU_SIU_COUNT_VALUE_1_SIU_CNT1_MASK (0xFFU)
#define UART_PFU_SIU_COUNT_VALUE_1_SIU_CNT1_SHIFT (0U)
/*! SIU_Cnt1 - Count Value Register 1 */
#define UART_PFU_SIU_COUNT_VALUE_1_SIU_CNT1(x)   (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_COUNT_VALUE_1_SIU_CNT1_SHIFT)) & UART_PFU_SIU_COUNT_VALUE_1_SIU_CNT1_MASK)
/*! @} */

/*! @name SIU_COUNT_VALUE_2 - " */
/*! @{ */

#define UART_PFU_SIU_COUNT_VALUE_2_SIU_CNT2_MASK (0xFFU)
#define UART_PFU_SIU_COUNT_VALUE_2_SIU_CNT2_SHIFT (0U)
/*! SIU_Cnt2 - Count Value Register 2 */
#define UART_PFU_SIU_COUNT_VALUE_2_SIU_CNT2(x)   (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_COUNT_VALUE_2_SIU_CNT2_SHIFT)) & UART_PFU_SIU_COUNT_VALUE_2_SIU_CNT2_MASK)
/*! @} */

/*! @name SIU_COUNT_VALUE_3 - " */
/*! @{ */

#define UART_PFU_SIU_COUNT_VALUE_3_SIU_CNT3_MASK (0xFFU)
#define UART_PFU_SIU_COUNT_VALUE_3_SIU_CNT3_SHIFT (0U)
/*! SIU_Cnt3 - Count Value Register 3 */
#define UART_PFU_SIU_COUNT_VALUE_3_SIU_CNT3(x)   (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_COUNT_VALUE_3_SIU_CNT3_SHIFT)) & UART_PFU_SIU_COUNT_VALUE_3_SIU_CNT3_MASK)
/*! @} */

/*! @name SIU_MISC - " */
/*! @{ */

#define UART_PFU_SIU_MISC_SIU_MISC0_MASK         (0x1U)
#define UART_PFU_SIU_MISC_SIU_MISC0_SHIFT        (0U)
/*! SIU_MISC0 - SIU Miscellaneous Bit[0] */
#define UART_PFU_SIU_MISC_SIU_MISC0(x)           (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_MISC_SIU_MISC0_SHIFT)) & UART_PFU_SIU_MISC_SIU_MISC0_MASK)

#define UART_PFU_SIU_MISC_SIU_MISC1_MASK         (0x2U)
#define UART_PFU_SIU_MISC_SIU_MISC1_SHIFT        (1U)
/*! SIU_MISC1 - SIU Miscellaneous Bit[1] */
#define UART_PFU_SIU_MISC_SIU_MISC1(x)           (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_MISC_SIU_MISC1_SHIFT)) & UART_PFU_SIU_MISC_SIU_MISC1_MASK)

#define UART_PFU_SIU_MISC_SIU_MISC2_MASK         (0x4U)
#define UART_PFU_SIU_MISC_SIU_MISC2_SHIFT        (2U)
/*! SIU_MISC2 - SIU Miscellaneous Bit[2] */
#define UART_PFU_SIU_MISC_SIU_MISC2(x)           (((uint16_t)(((uint16_t)(x)) << UART_PFU_SIU_MISC_SIU_MISC2_SHIFT)) & UART_PFU_SIU_MISC_SIU_MISC2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group UART_PFU_Register_Masks */


/*!
 * @}
 */ /* end of group UART_PFU_Peripheral_Access_Layer */


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


#endif  /* PERI_UART_PFU_H_ */

