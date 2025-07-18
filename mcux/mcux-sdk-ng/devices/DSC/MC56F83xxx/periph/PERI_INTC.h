/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INTC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2019-09-23)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_INTC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INTC
 *
 * CMSIS Peripheral Access Layer for INTC
 */

#if !defined(PERI_INTC_H_)
#define PERI_INTC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(VECTOR_TYPE_T_)
#define VECTOR_TYPE_T_
/*!
 * @addtogroup Interrupt_vector_numbers
 * @{
 */

/*!
 * @brief Structure for the vector table
 *
 * The vector table refer to interrupt vector table in RM
 * Generally used for fast interrupt setting, checking current interrupt type.
 */
typedef enum _vector_type
{
    kHW_RESET_VECTORn               = 0,           /**< Vector no.0 */
    kCOP_RESET_VECTORn              = 1,           /**< Vector no.1 */
    kILLEGAL_OP_VECTORn             = 2,           /**< Vector no.2 */
    kSWI3_VECTORn                   = 3,           /**< Vector no.3 */
    kOVERFLOW_VECTORn               = 4,           /**< Vector no.4 */
    kMISALIGNED_VECTORn             = 5,           /**< Vector no.5 */
    kSTPCNT_VECTORn                 = 6,           /**< Vector no.6 */
    kBKPT_VECTORn                   = 7,           /**< Vector no.7 */
    kTRBUF_VECTORn                  = 8,           /**< Vector no.8 */
    kTX_REG_VECTORn                 = 9,           /**< Vector no.9 */
    kRX_REG_VECTORn                 = 10,          /**< Vector no.10 */
    kBUS_ERR_VECTORn                = 11,          /**< Vector no.11 */
    kReserved12_VECTORn             = 12,          /**< Vector no.12 */
    kReserved13_VECTORn             = 13,          /**< Vector no.13 */
    kReserved14_VECTORn             = 14,          /**< Vector no.14 */
    kSWI2_VECTORn                   = 15,          /**< Vector no.15 */
    kSWI1_VECTORn                   = 16,          /**< Vector no.16 */
    kSWI0_VECTORn                   = 17,          /**< Vector no.17 */
    kXBARA_VECTORn                  = 18,          /**< Vector no.18 */
    kLVI1_VECTORn                   = 19,          /**< Vector no.19 */
    kOCCS_VECTORn                   = 20,          /**< Vector no.20 */
    kTMRB_3_VECTORn                 = 21,          /**< Vector no.21 */
    kTMRB_2_VECTORn                 = 22,          /**< Vector no.22 */
    kTMRB_1_VECTORn                 = 23,          /**< Vector no.23 */
    kTMRB_0_VECTORn                 = 24,          /**< Vector no.24 */
    kTMRA_3_VECTORn                 = 25,          /**< Vector no.25 */
    kTMRA_2_VECTORn                 = 26,          /**< Vector no.26 */
    kTMRA_1_VECTORn                 = 27,          /**< Vector no.27 */
    kTMRA_0_VECTORn                 = 28,          /**< Vector no.28 */
    kADC12_CC1_VECTORn              = 29,          /**< Vector no.29 */
    kADC12_CC0_VECTORn              = 30,          /**< Vector no.30 */
    kADC12_ERR_VECTORn              = 31,          /**< Vector no.31 */
    kDMA_ERR_VECTORn                = 32,          /**< Vector no.32 */
    kDMA3_VECTORn                   = 33,          /**< Vector no.33 */
    kDMA2_VECTORn                   = 34,          /**< Vector no.34 */
    kDMA1_VECTORn                   = 35,          /**< Vector no.35 */
    kDMA0_VECTORn                   = 36,          /**< Vector no.36 */
    kCAN_MB_OR_VECTORn              = 37,          /**< Vector no.37 */
    kCAN_BUS_OFF_VECTORn            = 38,          /**< Vector no.38 */
    kCAN_ERROR_VECTORn              = 39,          /**< Vector no.39 */
    kCAN_TX_WARN_VECTORn            = 40,          /**< Vector no.40 */
    kCAN_RX_WARN_VECTORn            = 41,          /**< Vector no.41 */
    kCAN_WAKEUP_VECTORn             = 42,          /**< Vector no.42 */
    kReserved43_VECTORn             = 43,          /**< Vector no.43 */
    kQSCI2_RERR_VECTORn             = 43,          /**< Vector no.43 */
    kReserved44_VECTORn             = 44,          /**< Vector no.44 */
    kQSCI2_RCV_VECTORn              = 44,          /**< Vector no.44 */
    kReserved45_VECTORn             = 45,          /**< Vector no.45 */
    kQSCI2_TRIDLE_VECTORn           = 45,          /**< Vector no.45 */
    kReserved46_VECTORn             = 46,          /**< Vector no.46 */
    kQSCI2_TDRE_VECTORn             = 46,          /**< Vector no.46 */
    kQSCI1_RERR_VECTORn             = 47,          /**< Vector no.47 */
    kQSCI1_RCV_VECTORn              = 48,          /**< Vector no.48 */
    kQSCI1_TRIDLE_VECTORn           = 49,          /**< Vector no.49 */
    kQSCI1_TDRE_VECTORn             = 50,          /**< Vector no.50 */
    kQSCI0_RERR_VECTORn             = 51,          /**< Vector no.51 */
    kQSCI0_RCV_VECTORn              = 52,          /**< Vector no.52 */
    kQSCI0_TRIDLE_VECTORn           = 53,          /**< Vector no.53 */
    kQSCI0_TDRE_VECTORn             = 54,          /**< Vector no.54 */
    kReserved55_VECTORn             = 55,          /**< Vector no.55 */
    kReserved56_VECTORn             = 56,          /**< Vector no.56 */
    kReserved57_VECTORn             = 57,          /**< Vector no.57 */
    kQSPI1_XMIT_VECTORn             = 57,          /**< Vector no.57 */
    kReserved58_VECTORn             = 58,          /**< Vector no.58 */
    kQSPI1_RCV_VECTORn              = 58,          /**< Vector no.58 */
    kQSPI0_XMIT_VECTORn             = 59,          /**< Vector no.59 */
    kQSPI0_RCV_VECTORn              = 60,          /**< Vector no.60 */
    kI2C1_VECTORn                   = 61,          /**< Vector no.61 */
    kI2C0_VECTORn                   = 62,          /**< Vector no.62 */
    kReserved63_VECTORn             = 63,          /**< Vector no.63 */
    kReserved64_VECTORn             = 64,          /**< Vector no.64 */
    kReserved65_VECTORn             = 65,          /**< Vector no.65 */
    keFlexPWMB_FAULT_VECTORn        = 66,          /**< Vector no.66 */
    keFlexPWMB_RERR_VECTORn         = 67,          /**< Vector no.67 */
    keFlexPWMB_CAP_VECTORn          = 68,          /**< Vector no.68 */
    keFlexPWMB_RELOAD3_VECTORn      = 69,          /**< Vector no.69 */
    keFlexPWMB_CMP3_VECTORn         = 70,          /**< Vector no.70 */
    keFlexPWMB_RELOAD2_VECTORn      = 71,          /**< Vector no.71 */
    keFlexPWMB_CMP2_VECTORn         = 72,          /**< Vector no.72 */
    keFlexPWMB_RELOAD1_VECTORn      = 73,          /**< Vector no.73 */
    keFlexPWMB_CMP1_VECTORn         = 74,          /**< Vector no.74 */
    keFlexPWMB_RELOAD0_VECTORn      = 75,          /**< Vector no.75 */
    keFlexPWMB_CMP0_VECTORn         = 76,          /**< Vector no.76 */
    keFlexPWMA_FAULT_VECTORn        = 77,          /**< Vector no.77 */
    keFlexPWMA_RERR_VECTORn         = 78,          /**< Vector no.78 */
    keFlexPWMA_CAP_VECTORn          = 79,          /**< Vector no.79 */
    keFlexPWMA_RELOAD3_VECTORn      = 80,          /**< Vector no.80 */
    keFlexPWMA_CMP3_VECTORn         = 81,          /**< Vector no.81 */
    keFlexPWMA_RELOAD2_VECTORn      = 82,          /**< Vector no.82 */
    keFlexPWMA_CMP2_VECTORn         = 83,          /**< Vector no.83 */
    keFlexPWMA_RELOAD1_VECTORn      = 84,          /**< Vector no.84 */
    keFlexPWMA_CMP1_VECTORn         = 85,          /**< Vector no.85 */
    keFlexPWMA_RELOAD0_VECTORn      = 86,          /**< Vector no.86 */
    keFlexPWMA_CMP0_VECTORn         = 87,          /**< Vector no.87 */
    kFTFE_RDCOL_VECTORn             = 88,          /**< Vector no.88 */
    kFTFE_CC_VECTORn                = 89,          /**< Vector no.89 */
    kCMPD_VECTORn                   = 90,          /**< Vector no.90 */
    kCMPC_VECTORn                   = 91,          /**< Vector no.91 */
    kCMPB_VECTORn                   = 92,          /**< Vector no.92 */
    kCMPA_VECTORn                   = 93,          /**< Vector no.93 */
    kPIT1_ROLLOVR_VECTORn           = 94,          /**< Vector no.94 */
    kPIT0_ROLLOVR_VECTORn           = 95,          /**< Vector no.95 */
    kFTFE_DFD_VECTORn               = 96,          /**< Vector no.96 */
    kReserved97_VECTORn             = 97,          /**< Vector no.97 */
    kReserved98_VECTORn             = 98,          /**< Vector no.98 */
    kReserved99_VECTORn             = 99,          /**< Vector no.99 */
    kReserved100_VECTORn            = 100,         /**< Vector no.100 */
    kGPIOG_VECTORn                  = 101,         /**< Vector no.101 */
    kGPIOF_VECTORn                  = 102,         /**< Vector no.102 */
    kGPIOE_VECTORn                  = 103,         /**< Vector no.103 */
    kGPIOD_VECTORn                  = 104,         /**< Vector no.104 */
    kGPIOC_VECTORn                  = 105,         /**< Vector no.105 */
    kGPIOB_VECTORn                  = 106,         /**< Vector no.106 */
    kGPIOA_VECTORn                  = 107,         /**< Vector no.107 */
    kCOP_INT_VECTORn                = 108,         /**< Vector no.108 */
    kEWM_INT_VECTORn                = 109,         /**< Vector no.109 */
    kSWILP_VECTORn                  = 110,         /**< Vector no.110 */
    kReserved111_VECTORn            = 111,         /**< Vector no.111 */
    kUSB_VECTORn                    = 111,         /**< Vector no.111 */
} vector_type_t;

/* @} */
#endif /* VECTOR_TYPE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- INTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTC_Peripheral_Access_Layer INTC Peripheral Access Layer
 * @{
 */

/** INTC - Register Layout Typedef */
typedef struct {
  __IO uint16_t IPR0;                              /**< Interrupt Priority Register 0, offset: 0x0 */
  __IO uint16_t IPR1;                              /**< Interrupt Priority Register 1, offset: 0x1 */
  __IO uint16_t IPR2;                              /**< Interrupt Priority Register 2, offset: 0x2 */
  __IO uint16_t IPR3;                              /**< Interrupt Priority Register 3, offset: 0x3 */
  __IO uint16_t IPR4;                              /**< Interrupt Priority Register 4, offset: 0x4 */
  __IO uint16_t IPR5;                              /**< Interrupt Priority Register 5, offset: 0x5 */
  __IO uint16_t IPR6;                              /**< Interrupt Priority Register 6, offset: 0x6 */
  __IO uint16_t IPR7;                              /**< Interrupt Priority Register 7, offset: 0x7 */
  __IO uint16_t IPR8;                              /**< Interrupt Priority Register 8, offset: 0x8 */
  __IO uint16_t IPR9;                              /**< Interrupt Priority Register 9, offset: 0x9 */
  __IO uint16_t IPR10;                             /**< Interrupt Priority Register 10, offset: 0xA */
  __IO uint16_t IPR11;                             /**< Interrupt Priority Register 11, offset: 0xB */
  __IO uint16_t IPR12;                             /**< Interrupt Priority Register 12, offset: 0xC */
  __IO uint16_t VBA;                               /**< Vector Base Address Register, offset: 0xD */
  __IO uint16_t FIM0;                              /**< Fast Interrupt 0 Match Register, offset: 0xE */
  __IO uint16_t FIVAL0;                            /**< Fast Interrupt 0 Vector Address Low Register, offset: 0xF */
  __IO uint16_t FIVAH0;                            /**< Fast Interrupt 0 Vector Address High Register, offset: 0x10 */
  __IO uint16_t FIM1;                              /**< Fast Interrupt 1 Match Register, offset: 0x11 */
  __IO uint16_t FIVAL1;                            /**< Fast Interrupt 1 Vector Address Low Register, offset: 0x12 */
  __IO uint16_t FIVAH1;                            /**< Fast Interrupt 1 Vector Address High Register, offset: 0x13 */
  __I  uint16_t IRQP0;                             /**< IRQ Pending Register 0, offset: 0x14 */
  __I  uint16_t IRQP1;                             /**< IRQ Pending Register 1, offset: 0x15 */
  __I  uint16_t IRQP2;                             /**< IRQ Pending Register 2, offset: 0x16 */
  __I  uint16_t IRQP3;                             /**< IRQ Pending Register 3, offset: 0x17 */
  __I  uint16_t IRQP4;                             /**< IRQ Pending Register 4, offset: 0x18 */
  __I  uint16_t IRQP5;                             /**< IRQ Pending Register 5, offset: 0x19 */
  __I  uint16_t IRQP6;                             /**< IRQ Pending Register 6, offset: 0x1A */
  __IO uint16_t CTRL;                              /**< Control Register, offset: 0x1B */
} INTC_Type;

/* ----------------------------------------------------------------------------
   -- INTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTC_Register_Masks INTC Register Masks
 * @{
 */

/*! @name IPR0 - Interrupt Priority Register 0 */
/*! @{ */

#define INTC_IPR0_STPCNT_MASK                    (0x3U)
#define INTC_IPR0_STPCNT_SHIFT                   (0U)
/*! STPCNT - EOnCE Step Counter Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_STPCNT(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_STPCNT_SHIFT)) & INTC_IPR0_STPCNT_MASK)

#define INTC_IPR0_BKPT_MASK                      (0xCU)
#define INTC_IPR0_BKPT_SHIFT                     (2U)
/*! BKPT - EOnCE Breakpoint Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_BKPT(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_BKPT_SHIFT)) & INTC_IPR0_BKPT_MASK)

#define INTC_IPR0_TRBUF_MASK                     (0x30U)
#define INTC_IPR0_TRBUF_SHIFT                    (4U)
/*! TRBUF - EOnCE Trace Buffer Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_TRBUF(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_TRBUF_SHIFT)) & INTC_IPR0_TRBUF_MASK)

#define INTC_IPR0_TX_REG_MASK                    (0xC0U)
#define INTC_IPR0_TX_REG_SHIFT                   (6U)
/*! TX_REG - EOnCE Transmit Register Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_TX_REG(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_TX_REG_SHIFT)) & INTC_IPR0_TX_REG_MASK)

#define INTC_IPR0_RX_REG_MASK                    (0x300U)
#define INTC_IPR0_RX_REG_SHIFT                   (8U)
/*! RX_REG - EOnCE Receive Register Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_RX_REG(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_RX_REG_SHIFT)) & INTC_IPR0_RX_REG_MASK)

#define INTC_IPR0_BUS_ERR_MASK                   (0xC00U)
#define INTC_IPR0_BUS_ERR_SHIFT                  (10U)
/*! BUS_ERR - Bus Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR0_BUS_ERR(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_IPR0_BUS_ERR_SHIFT)) & INTC_IPR0_BUS_ERR_MASK)
/*! @} */

/*! @name IPR1 - Interrupt Priority Register 1 */
/*! @{ */

#define INTC_IPR1_XBARA_MASK                     (0xCU)
#define INTC_IPR1_XBARA_SHIFT                    (2U)
/*! XBARA - Inter-Peripheral Crossbar Switch A (XBARA) Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR1_XBARA(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_XBARA_SHIFT)) & INTC_IPR1_XBARA_MASK)

#define INTC_IPR1_LVI1_MASK                      (0x30U)
#define INTC_IPR1_LVI1_SHIFT                     (4U)
/*! LVI1 - Low Voltage Detector Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR1_LVI1(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_LVI1_SHIFT)) & INTC_IPR1_LVI1_MASK)

#define INTC_IPR1_OCCS_MASK                      (0xC0U)
#define INTC_IPR1_OCCS_SHIFT                     (6U)
/*! OCCS - PLL Loss of Reference or Change in Lock Status Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 1
 *  0b10..IRQ Priority Level 2
 *  0b11..IRQ Priority Level 3
 */
#define INTC_IPR1_OCCS(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_OCCS_SHIFT)) & INTC_IPR1_OCCS_MASK)

#define INTC_IPR1_TMRB_3_MASK                    (0x300U)
#define INTC_IPR1_TMRB_3_SHIFT                   (8U)
/*! TMRB_3 - Timer B Channel 3 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR1_TMRB_3(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_TMRB_3_SHIFT)) & INTC_IPR1_TMRB_3_MASK)

#define INTC_IPR1_TMRB_2_MASK                    (0xC00U)
#define INTC_IPR1_TMRB_2_SHIFT                   (10U)
/*! TMRB_2 - Timer B Channel 2 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR1_TMRB_2(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_TMRB_2_SHIFT)) & INTC_IPR1_TMRB_2_MASK)

#define INTC_IPR1_TMRB_1_MASK                    (0x3000U)
#define INTC_IPR1_TMRB_1_SHIFT                   (12U)
/*! TMRB_1 - Timer B Channel 1 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR1_TMRB_1(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_TMRB_1_SHIFT)) & INTC_IPR1_TMRB_1_MASK)

#define INTC_IPR1_TMRB_0_MASK                    (0xC000U)
#define INTC_IPR1_TMRB_0_SHIFT                   (14U)
/*! TMRB_0 - Timer B Channel 0 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR1_TMRB_0(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR1_TMRB_0_SHIFT)) & INTC_IPR1_TMRB_0_MASK)
/*! @} */

/*! @name IPR2 - Interrupt Priority Register 2 */
/*! @{ */

#define INTC_IPR2_TMRA_3_MASK                    (0x3U)
#define INTC_IPR2_TMRA_3_SHIFT                   (0U)
/*! TMRA_3 - Timer A Channel 3 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_TMRA_3(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_TMRA_3_SHIFT)) & INTC_IPR2_TMRA_3_MASK)

#define INTC_IPR2_TMRA_2_MASK                    (0xCU)
#define INTC_IPR2_TMRA_2_SHIFT                   (2U)
/*! TMRA_2 - Timer A Channel 2 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_TMRA_2(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_TMRA_2_SHIFT)) & INTC_IPR2_TMRA_2_MASK)

#define INTC_IPR2_TMRA_1_MASK                    (0x30U)
#define INTC_IPR2_TMRA_1_SHIFT                   (4U)
/*! TMRA_1 - Timer A Channel 1 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_TMRA_1(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_TMRA_1_SHIFT)) & INTC_IPR2_TMRA_1_MASK)

#define INTC_IPR2_TMRA_0_MASK                    (0xC0U)
#define INTC_IPR2_TMRA_0_SHIFT                   (6U)
/*! TMRA_0 - Timer A Channel 0 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_TMRA_0(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_TMRA_0_SHIFT)) & INTC_IPR2_TMRA_0_MASK)

#define INTC_IPR2_ADC_CC1_MASK                   (0x300U)
#define INTC_IPR2_ADC_CC1_SHIFT                  (8U)
/*! ADC_CC1 - ADC_CYC Conversion Complete Interrupt Priority Level (converter B in non-simultaneous parallel scan mode)
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_ADC_CC1(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_ADC_CC1_SHIFT)) & INTC_IPR2_ADC_CC1_MASK)

#define INTC_IPR2_ADC_CC0_MASK                   (0xC00U)
#define INTC_IPR2_ADC_CC0_SHIFT                  (10U)
/*! ADC_CC0 - ADC_CYC Conversion Complete Interrupt Priority Level (any scan type except converter B
 *    in non-simultaneous parallel scan mode)
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_ADC_CC0(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_ADC_CC0_SHIFT)) & INTC_IPR2_ADC_CC0_MASK)

#define INTC_IPR2_ADC_ERR_MASK                   (0x3000U)
#define INTC_IPR2_ADC_ERR_SHIFT                  (12U)
/*! ADC_ERR - ADC_CYC Zero Crossing, High Limit, or Low Limit Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_ADC_ERR(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_ADC_ERR_SHIFT)) & INTC_IPR2_ADC_ERR_MASK)

#define INTC_IPR2_DMA_ERR_MASK                   (0xC000U)
#define INTC_IPR2_DMA_ERR_SHIFT                  (14U)
/*! DMA_ERR - DMA Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR2_DMA_ERR(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_IPR2_DMA_ERR_SHIFT)) & INTC_IPR2_DMA_ERR_MASK)
/*! @} */

/*! @name IPR3 - Interrupt Priority Register 3 */
/*! @{ */

#define INTC_IPR3_DMACH3_MASK                    (0x3U)
#define INTC_IPR3_DMACH3_SHIFT                   (0U)
/*! DMACH3 - DMA Channel 3 Service Request Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_DMACH3(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_DMACH3_SHIFT)) & INTC_IPR3_DMACH3_MASK)

#define INTC_IPR3_DMACH2_MASK                    (0xCU)
#define INTC_IPR3_DMACH2_SHIFT                   (2U)
/*! DMACH2 - DMA Channel 2 Service Request Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_DMACH2(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_DMACH2_SHIFT)) & INTC_IPR3_DMACH2_MASK)

#define INTC_IPR3_DMACH1_MASK                    (0x30U)
#define INTC_IPR3_DMACH1_SHIFT                   (4U)
/*! DMACH1 - DMA Channel 1 Service Request Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_DMACH1(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_DMACH1_SHIFT)) & INTC_IPR3_DMACH1_MASK)

#define INTC_IPR3_DMACH0_MASK                    (0xC0U)
#define INTC_IPR3_DMACH0_SHIFT                   (6U)
/*! DMACH0 - DMA Channel 0 Service Request Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_DMACH0(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_DMACH0_SHIFT)) & INTC_IPR3_DMACH0_MASK)

#define INTC_IPR3_CAN_MB_OR_MASK                 (0x300U)
#define INTC_IPR3_CAN_MB_OR_SHIFT                (8U)
/*! CAN_MB_OR - CAN Message Buffer Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_CAN_MB_OR(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_CAN_MB_OR_SHIFT)) & INTC_IPR3_CAN_MB_OR_MASK)

#define INTC_IPR3_CAN_BUS_OFF_MASK               (0xC00U)
#define INTC_IPR3_CAN_BUS_OFF_SHIFT              (10U)
/*! CAN_BUS_OFF - CAN Bus Off Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_CAN_BUS_OFF(x)                 (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_CAN_BUS_OFF_SHIFT)) & INTC_IPR3_CAN_BUS_OFF_MASK)

#define INTC_IPR3_CAN_ERROR_MASK                 (0x3000U)
#define INTC_IPR3_CAN_ERROR_SHIFT                (12U)
/*! CAN_ERROR - CAN Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_CAN_ERROR(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_CAN_ERROR_SHIFT)) & INTC_IPR3_CAN_ERROR_MASK)

#define INTC_IPR3_CAN_TX_WARN_MASK               (0xC000U)
#define INTC_IPR3_CAN_TX_WARN_SHIFT              (14U)
/*! CAN_TX_WARN - CAN Transmit Warning Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR3_CAN_TX_WARN(x)                 (((uint16_t)(((uint16_t)(x)) << INTC_IPR3_CAN_TX_WARN_SHIFT)) & INTC_IPR3_CAN_TX_WARN_MASK)
/*! @} */

/*! @name IPR4 - Interrupt Priority Register 4 */
/*! @{ */

#define INTC_IPR4_CAN_RX_WARN_MASK               (0x3U)
#define INTC_IPR4_CAN_RX_WARN_SHIFT              (0U)
/*! CAN_RX_WARN - CAN Receive Warning Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_CAN_RX_WARN(x)                 (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_CAN_RX_WARN_SHIFT)) & INTC_IPR4_CAN_RX_WARN_MASK)

#define INTC_IPR4_CAN_WAKEUP_MASK                (0xCU)
#define INTC_IPR4_CAN_WAKEUP_SHIFT               (2U)
/*! CAN_WAKEUP - CAN Wakeup Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_CAN_WAKEUP(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_CAN_WAKEUP_SHIFT)) & INTC_IPR4_CAN_WAKEUP_MASK)

#define INTC_IPR4_QSCI2_RERR_MASK                (0x30U)
#define INTC_IPR4_QSCI2_RERR_SHIFT               (4U)
/*! QSCI2_RERR - QSCI 2 Receiver Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI2_RERR(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI2_RERR_SHIFT)) & INTC_IPR4_QSCI2_RERR_MASK)

#define INTC_IPR4_QSCI2_RCV_MASK                 (0xC0U)
#define INTC_IPR4_QSCI2_RCV_SHIFT                (6U)
/*! QSCI2_RCV - QSCI 2 Receive Data Register Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI2_RCV(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI2_RCV_SHIFT)) & INTC_IPR4_QSCI2_RCV_MASK)

#define INTC_IPR4_QSCI2_TRIDLE_MASK              (0x300U)
#define INTC_IPR4_QSCI2_TRIDLE_SHIFT             (8U)
/*! QSCI2_TRIDLE - QSCI 2 Transmitter and Receiver Idle Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI2_TRIDLE(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI2_TRIDLE_SHIFT)) & INTC_IPR4_QSCI2_TRIDLE_MASK)

#define INTC_IPR4_QSCI2_TDRE_MASK                (0xC00U)
#define INTC_IPR4_QSCI2_TDRE_SHIFT               (10U)
/*! QSCI2_TDRE - QSCI 2 Transmit Data Register Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI2_TDRE(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI2_TDRE_SHIFT)) & INTC_IPR4_QSCI2_TDRE_MASK)

#define INTC_IPR4_QSCI1_RERR_MASK                (0x3000U)
#define INTC_IPR4_QSCI1_RERR_SHIFT               (12U)
/*! QSCI1_RERR - QSCI 1 Receiver Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI1_RERR(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI1_RERR_SHIFT)) & INTC_IPR4_QSCI1_RERR_MASK)

#define INTC_IPR4_QSCI1_RCV_MASK                 (0xC000U)
#define INTC_IPR4_QSCI1_RCV_SHIFT                (14U)
/*! QSCI1_RCV - QSCI 1 Receive Data Register Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR4_QSCI1_RCV(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR4_QSCI1_RCV_SHIFT)) & INTC_IPR4_QSCI1_RCV_MASK)
/*! @} */

/*! @name IPR5 - Interrupt Priority Register 5 */
/*! @{ */

#define INTC_IPR5_QSCI1_TRIDLE_MASK              (0x3U)
#define INTC_IPR5_QSCI1_TRIDLE_SHIFT             (0U)
/*! QSCI1_TRIDLE - QSCI 1 Transmitter and Receiver Idle Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI1_TRIDLE(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI1_TRIDLE_SHIFT)) & INTC_IPR5_QSCI1_TRIDLE_MASK)

#define INTC_IPR5_QSCI1_TDRE_MASK                (0xCU)
#define INTC_IPR5_QSCI1_TDRE_SHIFT               (2U)
/*! QSCI1_TDRE - QSCI 1 Transmit Data Register Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI1_TDRE(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI1_TDRE_SHIFT)) & INTC_IPR5_QSCI1_TDRE_MASK)

#define INTC_IPR5_QSCI0_RERR_MASK                (0x30U)
#define INTC_IPR5_QSCI0_RERR_SHIFT               (4U)
/*! QSCI0_RERR - QSCI0 Receiver Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI0_RERR(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI0_RERR_SHIFT)) & INTC_IPR5_QSCI0_RERR_MASK)

#define INTC_IPR5_QSCI0_RCV_MASK                 (0xC0U)
#define INTC_IPR5_QSCI0_RCV_SHIFT                (6U)
/*! QSCI0_RCV - QSCI 0 Receive Data Register Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI0_RCV(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI0_RCV_SHIFT)) & INTC_IPR5_QSCI0_RCV_MASK)

#define INTC_IPR5_QSCI0_TRIDLE_MASK              (0x300U)
#define INTC_IPR5_QSCI0_TRIDLE_SHIFT             (8U)
/*! QSCI0_TRIDLE - QSCI 0 Transmitter and Receiver Idle Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI0_TRIDLE(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI0_TRIDLE_SHIFT)) & INTC_IPR5_QSCI0_TRIDLE_MASK)

#define INTC_IPR5_QSCI0_TDRE_MASK                (0xC00U)
#define INTC_IPR5_QSCI0_TDRE_SHIFT               (10U)
/*! QSCI0_TDRE - QSCI 0 Transmit Data Register Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR5_QSCI0_TDRE(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR5_QSCI0_TDRE_SHIFT)) & INTC_IPR5_QSCI0_TDRE_MASK)
/*! @} */

/*! @name IPR6 - Interrupt Priority Register 6 */
/*! @{ */

#define INTC_IPR6_QSPI1_XMIT_MASK                (0x3U)
#define INTC_IPR6_QSPI1_XMIT_SHIFT               (0U)
/*! QSPI1_XMIT - QSPI1 Transmitter Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_QSPI1_XMIT(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_QSPI1_XMIT_SHIFT)) & INTC_IPR6_QSPI1_XMIT_MASK)

#define INTC_IPR6_QSPI1_RCV_MASK                 (0xCU)
#define INTC_IPR6_QSPI1_RCV_SHIFT                (2U)
/*! QSPI1_RCV - QSPI1 Receiver Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_QSPI1_RCV(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_QSPI1_RCV_SHIFT)) & INTC_IPR6_QSPI1_RCV_MASK)

#define INTC_IPR6_QSPI0_XMIT_MASK                (0x30U)
#define INTC_IPR6_QSPI0_XMIT_SHIFT               (4U)
/*! QSPI0_XMIT - QSPI0 Transmitter Empty Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_QSPI0_XMIT(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_QSPI0_XMIT_SHIFT)) & INTC_IPR6_QSPI0_XMIT_MASK)

#define INTC_IPR6_QSPI0_RCV_MASK                 (0xC0U)
#define INTC_IPR6_QSPI0_RCV_SHIFT                (6U)
/*! QSPI0_RCV - QSPI0 Receiver Full Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_QSPI0_RCV(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_QSPI0_RCV_SHIFT)) & INTC_IPR6_QSPI0_RCV_MASK)

#define INTC_IPR6_IIC1_MASK                      (0x300U)
#define INTC_IPR6_IIC1_SHIFT                     (8U)
/*! IIC1 - I2C1 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_IIC1(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_IIC1_SHIFT)) & INTC_IPR6_IIC1_MASK)

#define INTC_IPR6_IIC0_MASK                      (0xC00U)
#define INTC_IPR6_IIC0_SHIFT                     (10U)
/*! IIC0 - I2C0 Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR6_IIC0(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR6_IIC0_SHIFT)) & INTC_IPR6_IIC0_MASK)
/*! @} */

/*! @name IPR7 - Interrupt Priority Register 7 */
/*! @{ */

#define INTC_IPR7_PWMB_FAULT_MASK                (0xCU)
#define INTC_IPR7_PWMB_FAULT_SHIFT               (2U)
/*! PWMB_FAULT - PWMB Fault Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_FAULT(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_FAULT_SHIFT)) & INTC_IPR7_PWMB_FAULT_MASK)

#define INTC_IPR7_PWMB_RERR_MASK                 (0x30U)
#define INTC_IPR7_PWMB_RERR_SHIFT                (4U)
/*! PWMB_RERR - PWMB Reload Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_RERR(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_RERR_SHIFT)) & INTC_IPR7_PWMB_RERR_MASK)

#define INTC_IPR7_PWMB_CAP_MASK                  (0xC0U)
#define INTC_IPR7_PWMB_CAP_SHIFT                 (6U)
/*! PWMB_CAP - PWMB Submodule Capture Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_CAP(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_CAP_SHIFT)) & INTC_IPR7_PWMB_CAP_MASK)

#define INTC_IPR7_PWMB_RELOAD3_MASK              (0x300U)
#define INTC_IPR7_PWMB_RELOAD3_SHIFT             (8U)
/*! PWMB_RELOAD3 - PWMB Submodule 3 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_RELOAD3(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_RELOAD3_SHIFT)) & INTC_IPR7_PWMB_RELOAD3_MASK)

#define INTC_IPR7_PWMB_CMP3_MASK                 (0xC00U)
#define INTC_IPR7_PWMB_CMP3_SHIFT                (10U)
/*! PWMB_CMP3 - PWMB Submodule 3 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_CMP3(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_CMP3_SHIFT)) & INTC_IPR7_PWMB_CMP3_MASK)

#define INTC_IPR7_PWMB_RELOAD2_MASK              (0x3000U)
#define INTC_IPR7_PWMB_RELOAD2_SHIFT             (12U)
/*! PWMB_RELOAD2 - PWMB Submodule 2 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_RELOAD2(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_RELOAD2_SHIFT)) & INTC_IPR7_PWMB_RELOAD2_MASK)

#define INTC_IPR7_PWMB_CMP2_MASK                 (0xC000U)
#define INTC_IPR7_PWMB_CMP2_SHIFT                (14U)
/*! PWMB_CMP2 - PWMB Submodule 2 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR7_PWMB_CMP2(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR7_PWMB_CMP2_SHIFT)) & INTC_IPR7_PWMB_CMP2_MASK)
/*! @} */

/*! @name IPR8 - Interrupt Priority Register 8 */
/*! @{ */

#define INTC_IPR8_PWMB_RELOAD1_MASK              (0x3U)
#define INTC_IPR8_PWMB_RELOAD1_SHIFT             (0U)
/*! PWMB_RELOAD1 - PWMB Submodule 1 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMB_RELOAD1(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMB_RELOAD1_SHIFT)) & INTC_IPR8_PWMB_RELOAD1_MASK)

#define INTC_IPR8_PWMB_CMP1_MASK                 (0xCU)
#define INTC_IPR8_PWMB_CMP1_SHIFT                (2U)
/*! PWMB_CMP1 - PWMB Submodule 1 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMB_CMP1(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMB_CMP1_SHIFT)) & INTC_IPR8_PWMB_CMP1_MASK)

#define INTC_IPR8_PWMB_RELOAD0_MASK              (0x30U)
#define INTC_IPR8_PWMB_RELOAD0_SHIFT             (4U)
/*! PWMB_RELOAD0 - PWMB Submodule 0 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMB_RELOAD0(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMB_RELOAD0_SHIFT)) & INTC_IPR8_PWMB_RELOAD0_MASK)

#define INTC_IPR8_PWMB_CMP0_MASK                 (0xC0U)
#define INTC_IPR8_PWMB_CMP0_SHIFT                (6U)
/*! PWMB_CMP0 - PWMB Submodule 0 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMB_CMP0(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMB_CMP0_SHIFT)) & INTC_IPR8_PWMB_CMP0_MASK)

#define INTC_IPR8_PWMA_FAULT_MASK                (0x300U)
#define INTC_IPR8_PWMA_FAULT_SHIFT               (8U)
/*! PWMA_FAULT - PWMA Fault Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMA_FAULT(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMA_FAULT_SHIFT)) & INTC_IPR8_PWMA_FAULT_MASK)

#define INTC_IPR8_PWMA_RERR_MASK                 (0xC00U)
#define INTC_IPR8_PWMA_RERR_SHIFT                (10U)
/*! PWMA_RERR - PWMA Reload Error Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMA_RERR(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMA_RERR_SHIFT)) & INTC_IPR8_PWMA_RERR_MASK)

#define INTC_IPR8_PWMA_CAP_MASK                  (0x3000U)
#define INTC_IPR8_PWMA_CAP_SHIFT                 (12U)
/*! PWMA_CAP - PWMA Submodule Capture Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMA_CAP(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMA_CAP_SHIFT)) & INTC_IPR8_PWMA_CAP_MASK)

#define INTC_IPR8_PWMA_RELOAD3_MASK              (0xC000U)
#define INTC_IPR8_PWMA_RELOAD3_SHIFT             (14U)
/*! PWMA_RELOAD3 - PWMA Submodule 3 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR8_PWMA_RELOAD3(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR8_PWMA_RELOAD3_SHIFT)) & INTC_IPR8_PWMA_RELOAD3_MASK)
/*! @} */

/*! @name IPR9 - Interrupt Priority Register 9 */
/*! @{ */

#define INTC_IPR9_PWMA_CMP3_MASK                 (0x3U)
#define INTC_IPR9_PWMA_CMP3_SHIFT                (0U)
/*! PWMA_CMP3 - PWMA Submodule 3 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_CMP3(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_CMP3_SHIFT)) & INTC_IPR9_PWMA_CMP3_MASK)

#define INTC_IPR9_PWMA_RELOAD2_MASK              (0xCU)
#define INTC_IPR9_PWMA_RELOAD2_SHIFT             (2U)
/*! PWMA_RELOAD2 - PWMA Submodule 2 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_RELOAD2(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_RELOAD2_SHIFT)) & INTC_IPR9_PWMA_RELOAD2_MASK)

#define INTC_IPR9_PWMA_CMP2_MASK                 (0x30U)
#define INTC_IPR9_PWMA_CMP2_SHIFT                (4U)
/*! PWMA_CMP2 - PWMA Submodule 2 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_CMP2(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_CMP2_SHIFT)) & INTC_IPR9_PWMA_CMP2_MASK)

#define INTC_IPR9_PWMA_RELOAD1_MASK              (0xC0U)
#define INTC_IPR9_PWMA_RELOAD1_SHIFT             (6U)
/*! PWMA_RELOAD1 - PWMA Submodule 1 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_RELOAD1(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_RELOAD1_SHIFT)) & INTC_IPR9_PWMA_RELOAD1_MASK)

#define INTC_IPR9_PWMA_CMP1_MASK                 (0x300U)
#define INTC_IPR9_PWMA_CMP1_SHIFT                (8U)
/*! PWMA_CMP1 - PWMA Submodule 1 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_CMP1(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_CMP1_SHIFT)) & INTC_IPR9_PWMA_CMP1_MASK)

#define INTC_IPR9_PWMA_RELOAD0_MASK              (0xC00U)
#define INTC_IPR9_PWMA_RELOAD0_SHIFT             (10U)
/*! PWMA_RELOAD0 - PWMA Submodule 0 Reload Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_RELOAD0(x)                (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_RELOAD0_SHIFT)) & INTC_IPR9_PWMA_RELOAD0_MASK)

#define INTC_IPR9_PWMA_CMP0_MASK                 (0x3000U)
#define INTC_IPR9_PWMA_CMP0_SHIFT                (12U)
/*! PWMA_CMP0 - PWMA Submodule 0 Compare Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_PWMA_CMP0(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_PWMA_CMP0_SHIFT)) & INTC_IPR9_PWMA_CMP0_MASK)

#define INTC_IPR9_FTFE_RDCOL_MASK                (0xC000U)
#define INTC_IPR9_FTFE_RDCOL_SHIFT               (14U)
/*! FTFE_RDCOL - Flash module Access Error Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR9_FTFE_RDCOL(x)                  (((uint16_t)(((uint16_t)(x)) << INTC_IPR9_FTFE_RDCOL_SHIFT)) & INTC_IPR9_FTFE_RDCOL_MASK)
/*! @} */

/*! @name IPR10 - Interrupt Priority Register 10 */
/*! @{ */

#define INTC_IPR10_FTFE_CC_MASK                  (0x3U)
#define INTC_IPR10_FTFE_CC_SHIFT                 (0U)
/*! FTFE_CC - Flash module Command Complete Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_FTFE_CC(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_FTFE_CC_SHIFT)) & INTC_IPR10_FTFE_CC_MASK)

#define INTC_IPR10_CMPD_MASK                     (0xCU)
#define INTC_IPR10_CMPD_SHIFT                    (2U)
/*! CMPD - Comparator D Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_CMPD(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_CMPD_SHIFT)) & INTC_IPR10_CMPD_MASK)

#define INTC_IPR10_CMPC_MASK                     (0x30U)
#define INTC_IPR10_CMPC_SHIFT                    (4U)
/*! CMPC - Comparator C Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_CMPC(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_CMPC_SHIFT)) & INTC_IPR10_CMPC_MASK)

#define INTC_IPR10_CMPB_MASK                     (0xC0U)
#define INTC_IPR10_CMPB_SHIFT                    (6U)
/*! CMPB - Comparator B Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_CMPB(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_CMPB_SHIFT)) & INTC_IPR10_CMPB_MASK)

#define INTC_IPR10_CMPA_MASK                     (0x300U)
#define INTC_IPR10_CMPA_SHIFT                    (8U)
/*! CMPA - Comparator A Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_CMPA(x)                       (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_CMPA_SHIFT)) & INTC_IPR10_CMPA_MASK)

#define INTC_IPR10_PIT1_ROLLOVR_MASK             (0xC00U)
#define INTC_IPR10_PIT1_ROLLOVR_SHIFT            (10U)
/*! PIT1_ROLLOVR - PIT1 Roll Over Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_PIT1_ROLLOVR(x)               (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_PIT1_ROLLOVR_SHIFT)) & INTC_IPR10_PIT1_ROLLOVR_MASK)

#define INTC_IPR10_PIT0_ROLLOVR_MASK             (0x3000U)
#define INTC_IPR10_PIT0_ROLLOVR_SHIFT            (12U)
/*! PIT0_ROLLOVR - PIT0 Roll Over Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_PIT0_ROLLOVR(x)               (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_PIT0_ROLLOVR_SHIFT)) & INTC_IPR10_PIT0_ROLLOVR_MASK)

#define INTC_IPR10_FTFE_DFD_MASK                 (0xC000U)
#define INTC_IPR10_FTFE_DFD_SHIFT                (14U)
/*! FTFE_DFD - Flash module Double-bit Fault Detect Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR10_FTFE_DFD(x)                   (((uint16_t)(((uint16_t)(x)) << INTC_IPR10_FTFE_DFD_SHIFT)) & INTC_IPR10_FTFE_DFD_MASK)
/*! @} */

/*! @name IPR11 - Interrupt Priority Register 11 */
/*! @{ */

#define INTC_IPR11_GPIOG_MASK                    (0x300U)
#define INTC_IPR11_GPIOG_SHIFT                   (8U)
/*! GPIOG - GPIO G Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR11_GPIOG(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR11_GPIOG_SHIFT)) & INTC_IPR11_GPIOG_MASK)

#define INTC_IPR11_GPIOF_MASK                    (0xC00U)
#define INTC_IPR11_GPIOF_SHIFT                   (10U)
/*! GPIOF - GPIO F Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR11_GPIOF(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR11_GPIOF_SHIFT)) & INTC_IPR11_GPIOF_MASK)

#define INTC_IPR11_GPIOE_MASK                    (0x3000U)
#define INTC_IPR11_GPIOE_SHIFT                   (12U)
/*! GPIOE - GPIO E Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR11_GPIOE(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR11_GPIOE_SHIFT)) & INTC_IPR11_GPIOE_MASK)

#define INTC_IPR11_GPIOD_MASK                    (0xC000U)
#define INTC_IPR11_GPIOD_SHIFT                   (14U)
/*! GPIOD - GPIO D Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR11_GPIOD(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR11_GPIOD_SHIFT)) & INTC_IPR11_GPIOD_MASK)
/*! @} */

/*! @name IPR12 - Interrupt Priority Register 12 */
/*! @{ */

#define INTC_IPR12_GPIOC_MASK                    (0x3U)
#define INTC_IPR12_GPIOC_SHIFT                   (0U)
/*! GPIOC - GPIO C Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_GPIOC(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_GPIOC_SHIFT)) & INTC_IPR12_GPIOC_MASK)

#define INTC_IPR12_GPIOB_MASK                    (0xCU)
#define INTC_IPR12_GPIOB_SHIFT                   (2U)
/*! GPIOB - GPIO B Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_GPIOB(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_GPIOB_SHIFT)) & INTC_IPR12_GPIOB_MASK)

#define INTC_IPR12_GPIOA_MASK                    (0x30U)
#define INTC_IPR12_GPIOA_SHIFT                   (4U)
/*! GPIOA - GPIO A Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_GPIOA(x)                      (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_GPIOA_SHIFT)) & INTC_IPR12_GPIOA_MASK)

#define INTC_IPR12_COP_INT_MASK                  (0xC0U)
#define INTC_IPR12_COP_INT_SHIFT                 (6U)
/*! COP_INT - COP Watchdog Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_COP_INT(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_COP_INT_SHIFT)) & INTC_IPR12_COP_INT_MASK)

#define INTC_IPR12_EWM_INT_MASK                  (0x300U)
#define INTC_IPR12_EWM_INT_SHIFT                 (8U)
/*! EWM_INT - External Watchdog Monitor Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_EWM_INT(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_EWM_INT_SHIFT)) & INTC_IPR12_EWM_INT_MASK)

#define INTC_IPR12_USB_MASK                      (0x3000U)
#define INTC_IPR12_USB_SHIFT                     (12U)
/*! USB - USB Interrupt Priority Level
 *  0b00..IRQ disabled (default)
 *  0b01..IRQ Priority Level 0
 *  0b10..IRQ Priority Level 1
 *  0b11..IRQ Priority Level 2
 */
#define INTC_IPR12_USB(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_IPR12_USB_SHIFT)) & INTC_IPR12_USB_MASK)
/*! @} */

/*! @name VBA - Vector Base Address Register */
/*! @{ */

#define INTC_VBA_VECTOR_BASE_ADDRESS_MASK        (0x1FFFU)
#define INTC_VBA_VECTOR_BASE_ADDRESS_SHIFT       (0U)
/*! VECTOR_BASE_ADDRESS - Interrupt Vector Base Address */
#define INTC_VBA_VECTOR_BASE_ADDRESS(x)          (((uint16_t)(((uint16_t)(x)) << INTC_VBA_VECTOR_BASE_ADDRESS_SHIFT)) & INTC_VBA_VECTOR_BASE_ADDRESS_MASK)
/*! @} */

/*! @name FIM0 - Fast Interrupt 0 Match Register */
/*! @{ */

#define INTC_FIM0_FAST_INTERRUPT_0_MASK          (0x7FU)
#define INTC_FIM0_FAST_INTERRUPT_0_SHIFT         (0U)
/*! FAST_INTERRUPT_0 - Fast Interrupt 0 Vector Number */
#define INTC_FIM0_FAST_INTERRUPT_0(x)            (((uint16_t)(((uint16_t)(x)) << INTC_FIM0_FAST_INTERRUPT_0_SHIFT)) & INTC_FIM0_FAST_INTERRUPT_0_MASK)
/*! @} */

/*! @name FIVAL0 - Fast Interrupt 0 Vector Address Low Register */
/*! @{ */

#define INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_MASK (0xFFFFU)
#define INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_SHIFT (0U)
#define INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW(x)   (((uint16_t)(((uint16_t)(x)) << INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_SHIFT)) & INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_MASK)
/*! @} */

/*! @name FIVAH0 - Fast Interrupt 0 Vector Address High Register */
/*! @{ */

#define INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_MASK (0x1FU)
#define INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_SHIFT (0U)
/*! FI_0_VECTOR_ADDRESS_HIGH - Upper 5 bits of vector address for fast interrupt 0 */
#define INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH(x)  (((uint16_t)(((uint16_t)(x)) << INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_SHIFT)) & INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_MASK)
/*! @} */

/*! @name FIM1 - Fast Interrupt 1 Match Register */
/*! @{ */

#define INTC_FIM1_FAST_INTERRUPT_1_MASK          (0x7FU)
#define INTC_FIM1_FAST_INTERRUPT_1_SHIFT         (0U)
/*! FAST_INTERRUPT_1 - Fast Interrupt 1 Vector Number */
#define INTC_FIM1_FAST_INTERRUPT_1(x)            (((uint16_t)(((uint16_t)(x)) << INTC_FIM1_FAST_INTERRUPT_1_SHIFT)) & INTC_FIM1_FAST_INTERRUPT_1_MASK)
/*! @} */

/*! @name FIVAL1 - Fast Interrupt 1 Vector Address Low Register */
/*! @{ */

#define INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_MASK (0xFFFFU)
#define INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_SHIFT (0U)
/*! FI_1_VECTOR_ADDRESS_LOW - Lower 16 bits of vector address for fast interrupt 1 */
#define INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW(x)   (((uint16_t)(((uint16_t)(x)) << INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_SHIFT)) & INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_MASK)
/*! @} */

/*! @name FIVAH1 - Fast Interrupt 1 Vector Address High Register */
/*! @{ */

#define INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_MASK (0x1FU)
#define INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_SHIFT (0U)
#define INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH(x)  (((uint16_t)(((uint16_t)(x)) << INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_SHIFT)) & INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_MASK)
/*! @} */

/*! @name IRQP0 - IRQ Pending Register 0 */
/*! @{ */

#define INTC_IRQP0_PENDING_MASK                  (0xFFFEU)
#define INTC_IRQP0_PENDING_SHIFT                 (1U)
/*! PENDING - Pending IRQs
 *  0b000000000000000..IRQ pending for this vector number
 *  0b000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP0_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP0_PENDING_SHIFT)) & INTC_IRQP0_PENDING_MASK)
/*! @} */

/*! @name IRQP1 - IRQ Pending Register 1 */
/*! @{ */

#define INTC_IRQP1_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP1_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP1_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP1_PENDING_SHIFT)) & INTC_IRQP1_PENDING_MASK)
/*! @} */

/*! @name IRQP2 - IRQ Pending Register 2 */
/*! @{ */

#define INTC_IRQP2_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP2_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP2_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP2_PENDING_SHIFT)) & INTC_IRQP2_PENDING_MASK)
/*! @} */

/*! @name IRQP3 - IRQ Pending Register 3 */
/*! @{ */

#define INTC_IRQP3_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP3_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP3_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP3_PENDING_SHIFT)) & INTC_IRQP3_PENDING_MASK)
/*! @} */

/*! @name IRQP4 - IRQ Pending Register 4 */
/*! @{ */

#define INTC_IRQP4_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP4_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP4_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP4_PENDING_SHIFT)) & INTC_IRQP4_PENDING_MASK)
/*! @} */

/*! @name IRQP5 - IRQ Pending Register 5 */
/*! @{ */

#define INTC_IRQP5_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP5_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP5_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP5_PENDING_SHIFT)) & INTC_IRQP5_PENDING_MASK)
/*! @} */

/*! @name IRQP6 - IRQ Pending Register 6 */
/*! @{ */

#define INTC_IRQP6_PENDING_MASK                  (0xFFFFU)
#define INTC_IRQP6_PENDING_SHIFT                 (0U)
/*! PENDING - Pending IRQs
 *  0b0000000000000000..IRQ pending for this vector number
 *  0b0000000000000001..No IRQ pending for this vector number
 */
#define INTC_IRQP6_PENDING(x)                    (((uint16_t)(((uint16_t)(x)) << INTC_IRQP6_PENDING_SHIFT)) & INTC_IRQP6_PENDING_MASK)
/*! @} */

/*! @name CTRL - Control Register */
/*! @{ */

#define INTC_CTRL_INT_DIS_MASK                   (0x20U)
#define INTC_CTRL_INT_DIS_SHIFT                  (5U)
/*! INT_DIS - Interrupt disable
 *  0b0..Normal operation. (default)
 *  0b1..All interrupts disabled.
 */
#define INTC_CTRL_INT_DIS(x)                     (((uint16_t)(((uint16_t)(x)) << INTC_CTRL_INT_DIS_SHIFT)) & INTC_CTRL_INT_DIS_MASK)

#define INTC_CTRL_VAB_MASK                       (0x1FC0U)
#define INTC_CTRL_VAB_SHIFT                      (6U)
/*! VAB - Vector number */
#define INTC_CTRL_VAB(x)                         (((uint16_t)(((uint16_t)(x)) << INTC_CTRL_VAB_SHIFT)) & INTC_CTRL_VAB_MASK)

#define INTC_CTRL_IPIC_MASK                      (0x6000U)
#define INTC_CTRL_IPIC_SHIFT                     (13U)
/*! IPIC - Interrupt Priority Level
 *  0b00..Required nested exception priority levels are 0, 1, 2, or 3.
 *  0b01..Required nested exception priority levels are 1, 2, or 3.
 *  0b10..Required nested exception priority levels are 2 or3.
 *  0b11..Required nested exception priority level is 3.
 */
#define INTC_CTRL_IPIC(x)                        (((uint16_t)(((uint16_t)(x)) << INTC_CTRL_IPIC_SHIFT)) & INTC_CTRL_IPIC_MASK)

#define INTC_CTRL_INT_MASK                       (0x8000U)
#define INTC_CTRL_INT_SHIFT                      (15U)
/*! INT - Interrupt
 *  0b0..No interrupt is being sent to the core.
 *  0b1..An interrupt is being sent to the core.
 */
#define INTC_CTRL_INT(x)                         (((uint16_t)(((uint16_t)(x)) << INTC_CTRL_INT_SHIFT)) & INTC_CTRL_INT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INTC_Register_Masks */


/*!
 * @}
 */ /* end of group INTC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_INTC_H_ */

