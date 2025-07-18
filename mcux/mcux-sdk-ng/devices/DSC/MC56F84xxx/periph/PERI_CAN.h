/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CAN
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CAN.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAN
 *
 * CMSIS Peripheral Access Layer for CAN
 */

#if !defined(PERI_CAN_H_)
#define PERI_CAN_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Size of Registers Arrays */
#define CAN_MB_COUNT                              16u
#define CAN_RXIMR_COUNT                           16u

/** CAN - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32_t CTRL1;                             /**< Control 1 register, offset: 0x2 */
  __IO uint32_t TIMER;                             /**< Free Running Timer, offset: 0x4 */
       uint16_t RESERVED_0[2];
  __IO uint32_t RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x8 */
  __IO uint32_t RX14MASK;                          /**< Rx 14 Mask register, offset: 0xA */
  __IO uint32_t RX15MASK;                          /**< Rx 15 Mask register, offset: 0xC */
  __IO uint32_t ECR;                               /**< Error Counter, offset: 0xE */
  __IO uint32_t ESR1;                              /**< Error and Status 1 register, offset: 0x10 */
       uint16_t RESERVED_1[2];
  __IO uint32_t IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x14 */
       uint16_t RESERVED_2[2];
  __IO uint32_t IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x18 */
  __IO uint32_t CTRL2;                             /**< Control 2 register, offset: 0x1A */
  __I  uint32_t ESR2;                              /**< Error and Status 2 register, offset: 0x1C */
       uint16_t RESERVED_3[4];
  __I  uint32_t CRCR;                              /**< CRC Register, offset: 0x22 */
  __IO uint32_t RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x24 */
  __I  uint32_t RXFIR;                             /**< Rx FIFO Information Register, offset: 0x26 */
       uint16_t RESERVED_4[4];
  __I  uint32_t DBG1;                              /**< Debug 1 register, offset: 0x2C */
       uint16_t RESERVED_5[18];
  struct {                                         /* offset: 0x40, array step: 0x8 */
    __IO uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x40, array step: 0x8 */
    __IO uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x42, array step: 0x8 */
    __IO uint32_t WORD0;                             /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x44, array step: 0x8 */
    __IO uint32_t WORD1;                             /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x46, array step: 0x8 */
  } MB[CAN_MB_COUNT];
       uint16_t RESERVED_6[896];
  __IO uint32_t RXIMR[CAN_RXIMR_COUNT];            /**< Rx Individual Mask Registers, array offset: 0x440, array step: 0x2 */
} CAN_Type;

/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define CAN_MCR_MAXMB_MASK                       (0x7FUL)
#define CAN_MCR_MAXMB_SHIFT                      (0UL)
/*! MAXMB - Number Of The Last Message Buffer */
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MAXMB_SHIFT)) & CAN_MCR_MAXMB_MASK)

#define CAN_MCR_IDAM_MASK                        (0x300UL)
#define CAN_MCR_IDAM_SHIFT                       (8UL)
/*! IDAM - ID Acceptance Mode
 *  0b00..Format A: One full ID (standard and extended) per ID Filter Table element.
 *  0b01..Format B: Two full standard IDs or two partial 14-bit (standard and extended) IDs per ID Filter Table element.
 *  0b10..Format C: Four partial 8-bit Standard IDs per ID Filter Table element.
 *  0b11..Format D: All frames rejected.
 */
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IDAM_SHIFT)) & CAN_MCR_IDAM_MASK)

#define CAN_MCR_AEN_MASK                         (0x1000UL)
#define CAN_MCR_AEN_SHIFT                        (12UL)
/*! AEN - Abort Enable
 *  0b0..Abort disabled.
 *  0b1..Abort enabled.
 */
#define CAN_MCR_AEN(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_MCR_AEN_SHIFT)) & CAN_MCR_AEN_MASK)

#define CAN_MCR_LPRIOEN_MASK                     (0x2000UL)
#define CAN_MCR_LPRIOEN_SHIFT                    (13UL)
/*! LPRIOEN - Local Priority Enable
 *  0b0..Local Priority disabled.
 *  0b1..Local Priority enabled.
 */
#define CAN_MCR_LPRIOEN(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPRIOEN_SHIFT)) & CAN_MCR_LPRIOEN_MASK)

#define CAN_MCR_IRMQ_MASK                        (0x10000UL)
#define CAN_MCR_IRMQ_SHIFT                       (16UL)
/*! IRMQ - Individual Rx Masking And Queue Enable
 *  0b0..Individual Rx masking and queue feature are disabled. For backward compatibility with legacy
 *       applications, the reading of C/S word locks the MB even if it is EMPTY.
 *  0b1..Individual Rx masking and queue feature are enabled.
 */
#define CAN_MCR_IRMQ(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_IRMQ_SHIFT)) & CAN_MCR_IRMQ_MASK)

#define CAN_MCR_SRXDIS_MASK                      (0x20000UL)
#define CAN_MCR_SRXDIS_SHIFT                     (17UL)
/*! SRXDIS - Self Reception Disable
 *  0b0..Self reception enabled.
 *  0b1..Self reception disabled.
 */
#define CAN_MCR_SRXDIS(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SRXDIS_SHIFT)) & CAN_MCR_SRXDIS_MASK)

#define CAN_MCR_DOZE_MASK                        (0x40000UL)
#define CAN_MCR_DOZE_SHIFT                       (18UL)
/*! DOZE - Doze Mode Enable
 *  0b0..FlexCAN is not enabled to enter low-power mode when Doze mode is requested.
 *  0b1..FlexCAN is enabled to enter low-power mode when Doze mode is requested.
 */
#define CAN_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_DOZE_SHIFT)) & CAN_MCR_DOZE_MASK)

#define CAN_MCR_WAKSRC_MASK                      (0x80000UL)
#define CAN_MCR_WAKSRC_SHIFT                     (19UL)
/*! WAKSRC - Wake Up Source
 *  0b0..FlexCAN uses the unfiltered Rx input to detect recessive to dominant edges on the CAN bus.
 *  0b1..FlexCAN uses the filtered Rx input to detect recessive to dominant edges on the CAN bus.
 */
#define CAN_MCR_WAKSRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKSRC_SHIFT)) & CAN_MCR_WAKSRC_MASK)

#define CAN_MCR_LPMACK_MASK                      (0x100000UL)
#define CAN_MCR_LPMACK_SHIFT                     (20UL)
/*! LPMACK - Low-Power Mode Acknowledge
 *  0b0..FlexCAN is not in a low-power mode.
 *  0b1..FlexCAN is in a low-power mode.
 */
#define CAN_MCR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_LPMACK_SHIFT)) & CAN_MCR_LPMACK_MASK)

#define CAN_MCR_WRNEN_MASK                       (0x200000UL)
#define CAN_MCR_WRNEN_SHIFT                      (21UL)
/*! WRNEN - Warning Interrupt Enable
 *  0b0..TWRNINT and RWRNINT bits are zero, independent of the values in the error counters.
 *  0b1..TWRNINT and RWRNINT bits are set when the respective error counter transitions from less than 96 to greater than or equal to 96.
 */
#define CAN_MCR_WRNEN(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WRNEN_SHIFT)) & CAN_MCR_WRNEN_MASK)

#define CAN_MCR_SLFWAK_MASK                      (0x400000UL)
#define CAN_MCR_SLFWAK_SHIFT                     (22UL)
/*! SLFWAK - Self Wake Up
 *  0b0..FlexCAN Self Wake Up feature is disabled.
 *  0b1..FlexCAN Self Wake Up feature is enabled.
 */
#define CAN_MCR_SLFWAK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SLFWAK_SHIFT)) & CAN_MCR_SLFWAK_MASK)

#define CAN_MCR_SUPV_MASK                        (0x800000UL)
#define CAN_MCR_SUPV_SHIFT                       (23UL)
/*! SUPV - Supervisor Mode
 *  0b0..FlexCAN is in User mode. Affected registers allow both Supervisor and Unrestricted accesses .
 *  0b1..FlexCAN is in Supervisor mode. Affected registers allow only Supervisor access. Unrestricted access
 *       behaves as though the access was done to an unimplemented register location .
 */
#define CAN_MCR_SUPV(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SUPV_SHIFT)) & CAN_MCR_SUPV_MASK)

#define CAN_MCR_FRZACK_MASK                      (0x1000000UL)
#define CAN_MCR_FRZACK_SHIFT                     (24UL)
/*! FRZACK - Freeze Mode Acknowledge
 *  0b0..FlexCAN not in Freeze mode, prescaler running.
 *  0b1..FlexCAN in Freeze mode, prescaler stopped.
 */
#define CAN_MCR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZACK_SHIFT)) & CAN_MCR_FRZACK_MASK)

#define CAN_MCR_SOFTRST_MASK                     (0x2000000UL)
#define CAN_MCR_SOFTRST_SHIFT                    (25UL)
/*! SOFTRST - Soft Reset
 *  0b0..No reset request.
 *  0b1..Resets the registers affected by soft reset.
 */
#define CAN_MCR_SOFTRST(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_MCR_SOFTRST_SHIFT)) & CAN_MCR_SOFTRST_MASK)

#define CAN_MCR_WAKMSK_MASK                      (0x4000000UL)
#define CAN_MCR_WAKMSK_SHIFT                     (26UL)
/*! WAKMSK - Wake Up Interrupt Mask
 *  0b0..Wake Up Interrupt is disabled.
 *  0b1..Wake Up Interrupt is enabled.
 */
#define CAN_MCR_WAKMSK(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_WAKMSK_SHIFT)) & CAN_MCR_WAKMSK_MASK)

#define CAN_MCR_NOTRDY_MASK                      (0x8000000UL)
#define CAN_MCR_NOTRDY_SHIFT                     (27UL)
/*! NOTRDY - FlexCAN Not Ready
 *  0b0..FlexCAN module is either in Normal mode, Listen-Only mode or Loop-Back mode.
 *  0b1..FlexCAN module is either in Disable mode , Doze mode , Stop mode or Freeze mode.
 */
#define CAN_MCR_NOTRDY(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_MCR_NOTRDY_SHIFT)) & CAN_MCR_NOTRDY_MASK)

#define CAN_MCR_HALT_MASK                        (0x10000000UL)
#define CAN_MCR_HALT_SHIFT                       (28UL)
/*! HALT - Halt FlexCAN
 *  0b0..No Freeze mode request.
 *  0b1..Enters Freeze mode if the FRZ bit is asserted.
 */
#define CAN_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_HALT_SHIFT)) & CAN_MCR_HALT_MASK)

#define CAN_MCR_RFEN_MASK                        (0x20000000UL)
#define CAN_MCR_RFEN_SHIFT                       (29UL)
/*! RFEN - Rx FIFO Enable
 *  0b0..Rx FIFO not enabled.
 *  0b1..Rx FIFO enabled.
 */
#define CAN_MCR_RFEN(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_RFEN_SHIFT)) & CAN_MCR_RFEN_MASK)

#define CAN_MCR_FRZ_MASK                         (0x40000000UL)
#define CAN_MCR_FRZ_SHIFT                        (30UL)
/*! FRZ - Freeze Enable
 *  0b0..Not enabled to enter Freeze mode.
 *  0b1..Enabled to enter Freeze mode.
 */
#define CAN_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_MCR_FRZ_SHIFT)) & CAN_MCR_FRZ_MASK)

#define CAN_MCR_MDIS_MASK                        (0x80000000UL)
#define CAN_MCR_MDIS_SHIFT                       (31UL)
/*! MDIS - Module Disable
 *  0b0..Enable the FlexCAN module.
 *  0b1..Disable the FlexCAN module.
 */
#define CAN_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_MCR_MDIS_SHIFT)) & CAN_MCR_MDIS_MASK)
/*! @} */

/*! @name CTRL1 - Control 1 register */
/*! @{ */

#define CAN_CTRL1_PROPSEG_MASK                   (0x7UL)
#define CAN_CTRL1_PROPSEG_SHIFT                  (0UL)
/*! PROPSEG - Propagation Segment */
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PROPSEG_SHIFT)) & CAN_CTRL1_PROPSEG_MASK)

#define CAN_CTRL1_LOM_MASK                       (0x8UL)
#define CAN_CTRL1_LOM_SHIFT                      (3UL)
/*! LOM - Listen-Only Mode
 *  0b0..Listen-Only mode is deactivated.
 *  0b1..FlexCAN module operates in Listen-Only mode.
 */
#define CAN_CTRL1_LOM(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LOM_SHIFT)) & CAN_CTRL1_LOM_MASK)

#define CAN_CTRL1_LBUF_MASK                      (0x10UL)
#define CAN_CTRL1_LBUF_SHIFT                     (4UL)
/*! LBUF - Lowest Buffer Transmitted First
 *  0b0..Buffer with highest priority is transmitted first.
 *  0b1..Lowest number buffer is transmitted first.
 */
#define CAN_CTRL1_LBUF(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LBUF_SHIFT)) & CAN_CTRL1_LBUF_MASK)

#define CAN_CTRL1_TSYN_MASK                      (0x20UL)
#define CAN_CTRL1_TSYN_SHIFT                     (5UL)
/*! TSYN - Timer Sync
 *  0b0..Timer Sync feature disabled
 *  0b1..Timer Sync feature enabled
 */
#define CAN_CTRL1_TSYN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TSYN_SHIFT)) & CAN_CTRL1_TSYN_MASK)

#define CAN_CTRL1_BOFFREC_MASK                   (0x40UL)
#define CAN_CTRL1_BOFFREC_SHIFT                  (6UL)
/*! BOFFREC - Bus Off Recovery
 *  0b0..Automatic recovering from Bus Off state enabled, according to CAN Spec 2.0 part B.
 *  0b1..Automatic recovering from Bus Off state disabled.
 */
#define CAN_CTRL1_BOFFREC(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFREC_SHIFT)) & CAN_CTRL1_BOFFREC_MASK)

#define CAN_CTRL1_SMP_MASK                       (0x80UL)
#define CAN_CTRL1_SMP_SHIFT                      (7UL)
/*! SMP - CAN Bit Sampling
 *  0b0..Just one sample is used to determine the bit value.
 *  0b1..Three samples are used to determine the value of the received bit: the regular one (sample point) and 2
 *       preceding samples; a majority rule is used.
 */
#define CAN_CTRL1_SMP(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_SMP_SHIFT)) & CAN_CTRL1_SMP_MASK)

#define CAN_CTRL1_RWRNMSK_MASK                   (0x400UL)
#define CAN_CTRL1_RWRNMSK_SHIFT                  (10UL)
/*! RWRNMSK - Rx Warning Interrupt Mask
 *  0b0..Rx Warning Interrupt disabled.
 *  0b1..Rx Warning Interrupt enabled.
 */
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RWRNMSK_SHIFT)) & CAN_CTRL1_RWRNMSK_MASK)

#define CAN_CTRL1_TWRNMSK_MASK                   (0x800UL)
#define CAN_CTRL1_TWRNMSK_SHIFT                  (11UL)
/*! TWRNMSK - Tx Warning Interrupt Mask
 *  0b0..Tx Warning Interrupt disabled.
 *  0b1..Tx Warning Interrupt enabled.
 */
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_TWRNMSK_SHIFT)) & CAN_CTRL1_TWRNMSK_MASK)

#define CAN_CTRL1_LPB_MASK                       (0x1000UL)
#define CAN_CTRL1_LPB_SHIFT                      (12UL)
/*! LPB - Loop Back Mode
 *  0b0..Loop Back disabled.
 *  0b1..Loop Back enabled.
 */
#define CAN_CTRL1_LPB(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_LPB_SHIFT)) & CAN_CTRL1_LPB_MASK)

#define CAN_CTRL1_CLKSRC_MASK                    (0x2000UL)
#define CAN_CTRL1_CLKSRC_SHIFT                   (13UL)
/*! CLKSRC - CAN Engine Clock Source
 *  0b0..The CAN engine clock source is the oscillator clock. Under this condition, the oscillator clock frequency must be lower than the bus clock.
 *  0b1..The CAN engine clock source is the peripheral clock.
 */
#define CAN_CTRL1_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_CLKSRC_SHIFT)) & CAN_CTRL1_CLKSRC_MASK)

#define CAN_CTRL1_ERRMSK_MASK                    (0x4000UL)
#define CAN_CTRL1_ERRMSK_SHIFT                   (14UL)
/*! ERRMSK - Error Mask
 *  0b0..Error interrupt disabled.
 *  0b1..Error interrupt enabled.
 */
#define CAN_CTRL1_ERRMSK(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_ERRMSK_SHIFT)) & CAN_CTRL1_ERRMSK_MASK)

#define CAN_CTRL1_BOFFMSK_MASK                   (0x8000UL)
#define CAN_CTRL1_BOFFMSK_SHIFT                  (15UL)
/*! BOFFMSK - Bus Off Mask
 *  0b0..Bus Off interrupt disabled.
 *  0b1..Bus Off interrupt enabled.
 */
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_BOFFMSK_SHIFT)) & CAN_CTRL1_BOFFMSK_MASK)

#define CAN_CTRL1_PSEG2_MASK                     (0x70000UL)
#define CAN_CTRL1_PSEG2_SHIFT                    (16UL)
/*! PSEG2 - Phase Segment 2 */
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG2_SHIFT)) & CAN_CTRL1_PSEG2_MASK)

#define CAN_CTRL1_PSEG1_MASK                     (0x380000UL)
#define CAN_CTRL1_PSEG1_SHIFT                    (19UL)
/*! PSEG1 - Phase Segment 1 */
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PSEG1_SHIFT)) & CAN_CTRL1_PSEG1_MASK)

#define CAN_CTRL1_RJW_MASK                       (0xC00000UL)
#define CAN_CTRL1_RJW_SHIFT                      (22UL)
/*! RJW - Resync Jump Width */
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_RJW_SHIFT)) & CAN_CTRL1_RJW_MASK)

#define CAN_CTRL1_PRESDIV_MASK                   (0xFF000000UL)
#define CAN_CTRL1_PRESDIV_SHIFT                  (24UL)
/*! PRESDIV - Prescaler Division Factor */
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CTRL1_PRESDIV_SHIFT)) & CAN_CTRL1_PRESDIV_MASK)
/*! @} */

/*! @name TIMER - Free Running Timer */
/*! @{ */

#define CAN_TIMER_TIMER_MASK                     (0xFFFFUL)
#define CAN_TIMER_TIMER_SHIFT                    (0UL)
/*! TIMER - Timer Value */
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_TIMER_TIMER_SHIFT)) & CAN_TIMER_TIMER_MASK)
/*! @} */

/*! @name RXMGMASK - Rx Mailboxes Global Mask Register */
/*! @{ */

#define CAN_RXMGMASK_MG_MASK                     (0xFFFFFFFFUL)
#define CAN_RXMGMASK_MG_SHIFT                    (0UL)
/*! MG - Rx Mailboxes Global Mask Bits
 *  0b00000000000000000000000000000000..The corresponding bit in the filter is "don't care."
 *  0b00000000000000000000000000000001..The corresponding bit in the filter is checked.
 */
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_RXMGMASK_MG_SHIFT)) & CAN_RXMGMASK_MG_MASK)
/*! @} */

/*! @name RX14MASK - Rx 14 Mask register */
/*! @{ */

#define CAN_RX14MASK_RX14M_MASK                  (0xFFFFFFFFUL)
#define CAN_RX14MASK_RX14M_SHIFT                 (0UL)
/*! RX14M - Rx Buffer 14 Mask Bits
 *  0b00000000000000000000000000000000..The corresponding bit in the filter is "don't care."
 *  0b00000000000000000000000000000001..The corresponding bit in the filter is checked.
 */
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x)) << CAN_RX14MASK_RX14M_SHIFT)) & CAN_RX14MASK_RX14M_MASK)
/*! @} */

/*! @name RX15MASK - Rx 15 Mask register */
/*! @{ */

#define CAN_RX15MASK_RX15M_MASK                  (0xFFFFFFFFUL)
#define CAN_RX15MASK_RX15M_SHIFT                 (0UL)
/*! RX15M - Rx Buffer 15 Mask Bits
 *  0b00000000000000000000000000000000..The corresponding bit in the filter is "don't care."
 *  0b00000000000000000000000000000001..The corresponding bit in the filter is checked.
 */
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x)) << CAN_RX15MASK_RX15M_SHIFT)) & CAN_RX15MASK_RX15M_MASK)
/*! @} */

/*! @name ECR - Error Counter */
/*! @{ */

#define CAN_ECR_TXERRCNT_MASK                    (0xFFUL)
#define CAN_ECR_TXERRCNT_SHIFT                   (0UL)
/*! TXERRCNT - Transmit Error Counter */
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ECR_TXERRCNT_SHIFT)) & CAN_ECR_TXERRCNT_MASK)

#define CAN_ECR_RXERRCNT_MASK                    (0xFF00UL)
#define CAN_ECR_RXERRCNT_SHIFT                   (8UL)
/*! RXERRCNT - Receive Error Counter */
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ECR_RXERRCNT_SHIFT)) & CAN_ECR_RXERRCNT_MASK)
/*! @} */

/*! @name ESR1 - Error and Status 1 register */
/*! @{ */

#define CAN_ESR1_WAKINT_MASK                     (0x1UL)
#define CAN_ESR1_WAKINT_SHIFT                    (0UL)
/*! WAKINT - Wake-Up Interrupt
 *  0b0..No such occurrence.
 *  0b1..Indicates a recessive to dominant transition was received on the CAN bus.
 */
#define CAN_ESR1_WAKINT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_WAKINT_SHIFT)) & CAN_ESR1_WAKINT_MASK)

#define CAN_ESR1_ERRINT_MASK                     (0x2UL)
#define CAN_ESR1_ERRINT_SHIFT                    (1UL)
/*! ERRINT - Error Interrupt
 *  0b0..No such occurrence.
 *  0b1..Indicates setting of any Error Bit in the Error and Status Register.
 */
#define CAN_ESR1_ERRINT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ERRINT_SHIFT)) & CAN_ESR1_ERRINT_MASK)

#define CAN_ESR1_BOFFINT_MASK                    (0x4UL)
#define CAN_ESR1_BOFFINT_SHIFT                   (2UL)
/*! BOFFINT - Bus Off Interrupt
 *  0b0..No such occurrence.
 *  0b1..FlexCAN module entered Bus Off state.
 */
#define CAN_ESR1_BOFFINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BOFFINT_SHIFT)) & CAN_ESR1_BOFFINT_MASK)

#define CAN_ESR1_RX_MASK                         (0x8UL)
#define CAN_ESR1_RX_SHIFT                        (3UL)
/*! RX - FlexCAN In Reception
 *  0b0..FlexCAN is not receiving a message.
 *  0b1..FlexCAN is receiving a message.
 */
#define CAN_ESR1_RX(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RX_SHIFT)) & CAN_ESR1_RX_MASK)

#define CAN_ESR1_FLTCONF_MASK                    (0x30UL)
#define CAN_ESR1_FLTCONF_SHIFT                   (4UL)
/*! FLTCONF - Fault Confinement State
 *  0b00..Error Active
 *  0b01..Error Passive
 *  0b1x..Bus Off
 */
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FLTCONF_SHIFT)) & CAN_ESR1_FLTCONF_MASK)

#define CAN_ESR1_TX_MASK                         (0x40UL)
#define CAN_ESR1_TX_SHIFT                        (6UL)
/*! TX - FlexCAN In Transmission
 *  0b0..FlexCAN is not transmitting a message.
 *  0b1..FlexCAN is transmitting a message.
 */
#define CAN_ESR1_TX(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TX_SHIFT)) & CAN_ESR1_TX_MASK)

#define CAN_ESR1_IDLE_MASK                       (0x80UL)
#define CAN_ESR1_IDLE_SHIFT                      (7UL)
/*! IDLE
 *  0b0..No such occurrence.
 *  0b1..CAN bus is now IDLE.
 */
#define CAN_ESR1_IDLE(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_IDLE_SHIFT)) & CAN_ESR1_IDLE_MASK)

#define CAN_ESR1_RXWRN_MASK                      (0x100UL)
#define CAN_ESR1_RXWRN_SHIFT                     (8UL)
/*! RXWRN - Rx Error Warning
 *  0b0..No such occurrence.
 *  0b1..RXERRCNT is greater than or equal to 96.
 */
#define CAN_ESR1_RXWRN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RXWRN_SHIFT)) & CAN_ESR1_RXWRN_MASK)

#define CAN_ESR1_TXWRN_MASK                      (0x200UL)
#define CAN_ESR1_TXWRN_SHIFT                     (9UL)
/*! TXWRN - TX Error Warning
 *  0b0..No such occurrence.
 *  0b1..TXERRCNT is greater than or equal to 96.
 */
#define CAN_ESR1_TXWRN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TXWRN_SHIFT)) & CAN_ESR1_TXWRN_MASK)

#define CAN_ESR1_STFERR_MASK                     (0x400UL)
#define CAN_ESR1_STFERR_SHIFT                    (10UL)
/*! STFERR - Stuffing Error
 *  0b0..No such occurrence.
 *  0b1..A Stuffing Error occurred since last read of this register.
 */
#define CAN_ESR1_STFERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_STFERR_SHIFT)) & CAN_ESR1_STFERR_MASK)

#define CAN_ESR1_FRMERR_MASK                     (0x800UL)
#define CAN_ESR1_FRMERR_SHIFT                    (11UL)
/*! FRMERR - Form Error
 *  0b0..No such occurrence.
 *  0b1..A Form Error occurred since last read of this register.
 */
#define CAN_ESR1_FRMERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_FRMERR_SHIFT)) & CAN_ESR1_FRMERR_MASK)

#define CAN_ESR1_CRCERR_MASK                     (0x1000UL)
#define CAN_ESR1_CRCERR_SHIFT                    (12UL)
/*! CRCERR - Cyclic Redundancy Check Error
 *  0b0..No such occurrence.
 *  0b1..A CRC error occurred since last read of this register.
 */
#define CAN_ESR1_CRCERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_CRCERR_SHIFT)) & CAN_ESR1_CRCERR_MASK)

#define CAN_ESR1_ACKERR_MASK                     (0x2000UL)
#define CAN_ESR1_ACKERR_SHIFT                    (13UL)
/*! ACKERR - Acknowledge Error
 *  0b0..No such occurrence.
 *  0b1..An ACK error occurred since last read of this register.
 */
#define CAN_ESR1_ACKERR(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_ACKERR_SHIFT)) & CAN_ESR1_ACKERR_MASK)

#define CAN_ESR1_BIT0ERR_MASK                    (0x4000UL)
#define CAN_ESR1_BIT0ERR_SHIFT                   (14UL)
/*! BIT0ERR - Bit0 Error
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as dominant is received as recessive.
 */
#define CAN_ESR1_BIT0ERR(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT0ERR_SHIFT)) & CAN_ESR1_BIT0ERR_MASK)

#define CAN_ESR1_BIT1ERR_MASK                    (0x8000UL)
#define CAN_ESR1_BIT1ERR_SHIFT                   (15UL)
/*! BIT1ERR - Bit1 Error
 *  0b0..No such occurrence.
 *  0b1..At least one bit sent as recessive is received as dominant.
 */
#define CAN_ESR1_BIT1ERR(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_BIT1ERR_SHIFT)) & CAN_ESR1_BIT1ERR_MASK)

#define CAN_ESR1_RWRNINT_MASK                    (0x10000UL)
#define CAN_ESR1_RWRNINT_SHIFT                   (16UL)
/*! RWRNINT - Rx Warning Interrupt Flag
 *  0b0..No such occurrence.
 *  0b1..The Rx error counter transitioned from less than 96 to greater than or equal to 96.
 */
#define CAN_ESR1_RWRNINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_RWRNINT_SHIFT)) & CAN_ESR1_RWRNINT_MASK)

#define CAN_ESR1_TWRNINT_MASK                    (0x20000UL)
#define CAN_ESR1_TWRNINT_SHIFT                   (17UL)
/*! TWRNINT - Tx Warning Interrupt Flag
 *  0b0..No such occurrence.
 *  0b1..The Tx error counter transitioned from less than 96 to greater than or equal to 96.
 */
#define CAN_ESR1_TWRNINT(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_TWRNINT_SHIFT)) & CAN_ESR1_TWRNINT_MASK)

#define CAN_ESR1_SYNCH_MASK                      (0x40000UL)
#define CAN_ESR1_SYNCH_SHIFT                     (18UL)
/*! SYNCH - CAN Synchronization Status
 *  0b0..FlexCAN is not synchronized to the CAN bus.
 *  0b1..FlexCAN is synchronized to the CAN bus.
 */
#define CAN_ESR1_SYNCH(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_ESR1_SYNCH_SHIFT)) & CAN_ESR1_SYNCH_MASK)
/*! @} */

/*! @name IMASK1 - Interrupt Masks 1 register */
/*! @{ */

#define CAN_IMASK1_BUFLM_MASK                    (0xFFFFFFFFUL)
#define CAN_IMASK1_BUFLM_SHIFT                   (0UL)
/*! BUFLM - Buffer MB i Mask
 *  0b00000000000000000000000000000000..The corresponding buffer Interrupt is disabled.
 *  0b00000000000000000000000000000001..The corresponding buffer Interrupt is enabled.
 */
#define CAN_IMASK1_BUFLM(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IMASK1_BUFLM_SHIFT)) & CAN_IMASK1_BUFLM_MASK)
/*! @} */

/*! @name IFLAG1 - Interrupt Flags 1 register */
/*! @{ */

#define CAN_IFLAG1_BUF4TO0I_MASK                 (0x1FUL)
#define CAN_IFLAG1_BUF4TO0I_SHIFT                (0UL)
/*! BUF4TO0I - Buffer MB i Interrupt Or "reserved"
 *  0b00000..The corresponding buffer has no occurrence of successfully completed transmission or reception when MCR[RFEN]=0.
 *  0b00001..The corresponding buffer has successfully completed transmission or reception when MCR[RFEN]=0.
 */
#define CAN_IFLAG1_BUF4TO0I(x)                   (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF4TO0I_SHIFT)) & CAN_IFLAG1_BUF4TO0I_MASK)

#define CAN_IFLAG1_BUF5I_MASK                    (0x20UL)
#define CAN_IFLAG1_BUF5I_SHIFT                   (5UL)
/*! BUF5I - Buffer MB5 Interrupt Or "Frames available in Rx FIFO"
 *  0b0..No occurrence of MB5 completing transmission/reception when MCR[RFEN]=0, or of frame(s) available in the Rx FIFO, when MCR[RFEN]=1
 *  0b1..MB5 completed transmission/reception when MCR[RFEN]=0, or frame(s) available in the Rx FIFO when MCR[RFEN]=1
 */
#define CAN_IFLAG1_BUF5I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF5I_SHIFT)) & CAN_IFLAG1_BUF5I_MASK)

#define CAN_IFLAG1_BUF6I_MASK                    (0x40UL)
#define CAN_IFLAG1_BUF6I_SHIFT                   (6UL)
/*! BUF6I - Buffer MB6 Interrupt Or "Rx FIFO Warning"
 *  0b0..No occurrence of MB6 completing transmission/reception when MCR[RFEN]=0, or of Rx FIFO almost full when MCR[RFEN]=1
 *  0b1..MB6 completed transmission/reception when MCR[RFEN]=0, or Rx FIFO almost full when MCR[RFEN]=1
 */
#define CAN_IFLAG1_BUF6I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF6I_SHIFT)) & CAN_IFLAG1_BUF6I_MASK)

#define CAN_IFLAG1_BUF7I_MASK                    (0x80UL)
#define CAN_IFLAG1_BUF7I_SHIFT                   (7UL)
/*! BUF7I - Buffer MB7 Interrupt Or "Rx FIFO Overflow"
 *  0b0..No occurrence of MB7 completing transmission/reception when MCR[RFEN]=0, or of Rx FIFO overflow when MCR[RFEN]=1
 *  0b1..MB7 completed transmission/reception when MCR[RFEN]=0, or Rx FIFO overflow when MCR[RFEN]=1
 */
#define CAN_IFLAG1_BUF7I(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF7I_SHIFT)) & CAN_IFLAG1_BUF7I_MASK)

#define CAN_IFLAG1_BUF31TO8I_MASK                (0xFFFFFF00UL)
#define CAN_IFLAG1_BUF31TO8I_SHIFT               (8UL)
/*! BUF31TO8I - Buffer MBi Interrupt
 *  0b000000000000000000000000..The corresponding buffer has no occurrence of successfully completed transmission or reception.
 *  0b000000000000000000000001..The corresponding buffer has successfully completed transmission or reception.
 */
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x)) << CAN_IFLAG1_BUF31TO8I_SHIFT)) & CAN_IFLAG1_BUF31TO8I_MASK)
/*! @} */

/*! @name CTRL2 - Control 2 register */
/*! @{ */

#define CAN_CTRL2_EACEN_MASK                     (0x10000UL)
#define CAN_CTRL2_EACEN_SHIFT                    (16UL)
/*! EACEN - Entire Frame Arbitration Field Comparison Enable For Rx Mailboxes
 *  0b0..Rx Mailbox filter's IDE bit is always compared and RTR is never compared despite mask bits.
 *  0b1..Enables the comparison of both Rx Mailbox filter's IDE and RTR bit with their corresponding bits within
 *       the incoming frame. Mask bits do apply.
 */
#define CAN_CTRL2_EACEN(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_EACEN_SHIFT)) & CAN_CTRL2_EACEN_MASK)

#define CAN_CTRL2_RRS_MASK                       (0x20000UL)
#define CAN_CTRL2_RRS_SHIFT                      (17UL)
/*! RRS - Remote Request Storing
 *  0b0..Remote Response Frame is generated.
 *  0b1..Remote Request Frame is stored.
 */
#define CAN_CTRL2_RRS(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RRS_SHIFT)) & CAN_CTRL2_RRS_MASK)

#define CAN_CTRL2_MRP_MASK                       (0x40000UL)
#define CAN_CTRL2_MRP_SHIFT                      (18UL)
/*! MRP - Mailboxes Reception Priority
 *  0b0..Matching starts from Rx FIFO and continues on Mailboxes.
 *  0b1..Matching starts from Mailboxes and continues on Rx FIFO.
 */
#define CAN_CTRL2_MRP(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_MRP_SHIFT)) & CAN_CTRL2_MRP_MASK)

#define CAN_CTRL2_TASD_MASK                      (0xF80000UL)
#define CAN_CTRL2_TASD_SHIFT                     (19UL)
/*! TASD - Tx Arbitration Start Delay */
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_TASD_SHIFT)) & CAN_CTRL2_TASD_MASK)

#define CAN_CTRL2_RFFN_MASK                      (0xF000000UL)
#define CAN_CTRL2_RFFN_SHIFT                     (24UL)
/*! RFFN - Number Of Rx FIFO Filters */
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_RFFN_SHIFT)) & CAN_CTRL2_RFFN_MASK)

#define CAN_CTRL2_WRMFRZ_MASK                    (0x10000000UL)
#define CAN_CTRL2_WRMFRZ_SHIFT                   (28UL)
/*! WRMFRZ - Write-Access To Memory In Freeze Mode
 *  0b0..Maintain the write access restrictions.
 *  0b1..Enable unrestricted write access to FlexCAN memory.
 */
#define CAN_CTRL2_WRMFRZ(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_CTRL2_WRMFRZ_SHIFT)) & CAN_CTRL2_WRMFRZ_MASK)
/*! @} */

/*! @name ESR2 - Error and Status 2 register */
/*! @{ */

#define CAN_ESR2_IMB_MASK                        (0x2000UL)
#define CAN_ESR2_IMB_SHIFT                       (13UL)
/*! IMB - Inactive Mailbox
 *  0b0..If ESR2[VPS] is asserted, the ESR2[LPTM] is not an inactive Mailbox.
 *  0b1..If ESR2[VPS] is asserted, there is at least one inactive Mailbox. LPTM content is the number of the first one.
 */
#define CAN_ESR2_IMB(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_IMB_SHIFT)) & CAN_ESR2_IMB_MASK)

#define CAN_ESR2_VPS_MASK                        (0x4000UL)
#define CAN_ESR2_VPS_SHIFT                       (14UL)
/*! VPS - Valid Priority Status
 *  0b0..Contents of IMB and LPTM are invalid.
 *  0b1..Contents of IMB and LPTM are valid.
 */
#define CAN_ESR2_VPS(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_VPS_SHIFT)) & CAN_ESR2_VPS_MASK)

#define CAN_ESR2_LPTM_MASK                       (0x7F0000UL)
#define CAN_ESR2_LPTM_SHIFT                      (16UL)
/*! LPTM - Lowest Priority Tx Mailbox */
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_ESR2_LPTM_SHIFT)) & CAN_ESR2_LPTM_MASK)
/*! @} */

/*! @name CRCR - CRC Register */
/*! @{ */

#define CAN_CRCR_TXCRC_MASK                      (0x7FFFUL)
#define CAN_CRCR_TXCRC_SHIFT                     (0UL)
/*! TXCRC - CRC Transmitted */
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_TXCRC_SHIFT)) & CAN_CRCR_TXCRC_MASK)

#define CAN_CRCR_MBCRC_MASK                      (0x7F0000UL)
#define CAN_CRCR_MBCRC_SHIFT                     (16UL)
/*! MBCRC - CRC Mailbox */
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x)) << CAN_CRCR_MBCRC_SHIFT)) & CAN_CRCR_MBCRC_MASK)
/*! @} */

/*! @name RXFGMASK - Rx FIFO Global Mask register */
/*! @{ */

#define CAN_RXFGMASK_FGM_MASK                    (0xFFFFFFFFUL)
#define CAN_RXFGMASK_FGM_SHIFT                   (0UL)
/*! FGM - Rx FIFO Global Mask Bits
 *  0b00000000000000000000000000000000..The corresponding bit in the filter is "don't care."
 *  0b00000000000000000000000000000001..The corresponding bit in the filter is checked.
 */
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x)) << CAN_RXFGMASK_FGM_SHIFT)) & CAN_RXFGMASK_FGM_MASK)
/*! @} */

/*! @name RXFIR - Rx FIFO Information Register */
/*! @{ */

#define CAN_RXFIR_IDHIT_MASK                     (0x1FFUL)
#define CAN_RXFIR_IDHIT_SHIFT                    (0UL)
/*! IDHIT - Identifier Acceptance Filter Hit Indicator */
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x)) << CAN_RXFIR_IDHIT_SHIFT)) & CAN_RXFIR_IDHIT_MASK)
/*! @} */

/*! @name DBG1 - Debug 1 register */
/*! @{ */

#define CAN_DBG1_CFSM_MASK                       (0x3FUL)
#define CAN_DBG1_CFSM_SHIFT                      (0UL)
/*! CFSM - CAN Finite State Machine. */
#define CAN_DBG1_CFSM(x)                         (((uint32_t)(((uint32_t)(x)) << CAN_DBG1_CFSM_SHIFT)) & CAN_DBG1_CFSM_MASK)

#define CAN_DBG1_CBN_MASK                        (0x1F000000UL)
#define CAN_DBG1_CBN_SHIFT                       (24UL)
/*! CBN - CAN Bit Number. */
#define CAN_DBG1_CBN(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_DBG1_CBN_SHIFT)) & CAN_DBG1_CBN_MASK)
/*! @} */

/*! @name CS - Message Buffer 0 CS Register..Message Buffer 15 CS Register */
/*! @{ */

#define CAN_CS_TIME_STAMP_MASK                   (0xFFFFUL)
#define CAN_CS_TIME_STAMP_SHIFT                  (0UL)
/*! TIME_STAMP - Free-Running Counter Time stamp. This 16-bit field is a copy of the Free-Running
 *    Timer, captured for Tx and Rx frames at the time when the beginning of the Identifier field
 *    appears on the CAN bus.
 */
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x)) << CAN_CS_TIME_STAMP_SHIFT)) & CAN_CS_TIME_STAMP_MASK)

#define CAN_CS_DLC_MASK                          (0xF0000UL)
#define CAN_CS_DLC_SHIFT                         (16UL)
/*! DLC - Length of the data to be stored/transmitted. */
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_DLC_SHIFT)) & CAN_CS_DLC_MASK)

#define CAN_CS_RTR_MASK                          (0x100000UL)
#define CAN_CS_RTR_SHIFT                         (20UL)
/*! RTR - Remote Transmission Request. One/zero for remote/data frame. */
#define CAN_CS_RTR(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_RTR_SHIFT)) & CAN_CS_RTR_MASK)

#define CAN_CS_IDE_MASK                          (0x200000UL)
#define CAN_CS_IDE_SHIFT                         (21UL)
/*! IDE - ID Extended. One/zero for extended/standard format frame. */
#define CAN_CS_IDE(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_IDE_SHIFT)) & CAN_CS_IDE_MASK)

#define CAN_CS_SRR_MASK                          (0x400000UL)
#define CAN_CS_SRR_SHIFT                         (22UL)
/*! SRR - Substitute Remote Request. Contains a fixed recessive bit. */
#define CAN_CS_SRR(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_SRR_SHIFT)) & CAN_CS_SRR_MASK)

#define CAN_CS_CODE_MASK                         (0xF000000UL)
#define CAN_CS_CODE_SHIFT                        (24UL)
/*! CODE - Reserved */
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_CS_CODE_SHIFT)) & CAN_CS_CODE_MASK)

#define CAN_CS_ESI_MASK                          (0x20000000UL)
#define CAN_CS_ESI_SHIFT                         (29UL)
/*! ESI - Reserved */
#define CAN_CS_ESI(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_ESI_SHIFT)) & CAN_CS_ESI_MASK)

#define CAN_CS_BRS_MASK                          (0x40000000UL)
#define CAN_CS_BRS_SHIFT                         (30UL)
/*! BRS - Reserved */
#define CAN_CS_BRS(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_BRS_SHIFT)) & CAN_CS_BRS_MASK)

#define CAN_CS_EDL_MASK                          (0x80000000UL)
#define CAN_CS_EDL_SHIFT                         (31UL)
/*! EDL - Reserved */
#define CAN_CS_EDL(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_CS_EDL_SHIFT)) & CAN_CS_EDL_MASK)
/*! @} */

/* The count of CAN_CS */
#define CAN_CS_COUNT                             (16U)

/*! @name ID - Message Buffer 0 ID Register..Message Buffer 15 ID Register */
/*! @{ */

#define CAN_ID_EXT_MASK                          (0x3FFFFUL)
#define CAN_ID_EXT_SHIFT                         (0UL)
/*! EXT - Contains extended (LOW word) identifier of message buffer. */
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_ID_EXT_SHIFT)) & CAN_ID_EXT_MASK)

#define CAN_ID_STD_MASK                          (0x1FFC0000UL)
#define CAN_ID_STD_SHIFT                         (18UL)
/*! STD - Contains standard/extended (HIGH word) identifier of message buffer. */
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x)) << CAN_ID_STD_SHIFT)) & CAN_ID_STD_MASK)

#define CAN_ID_PRIO_MASK                         (0xE0000000UL)
#define CAN_ID_PRIO_SHIFT                        (29UL)
/*! PRIO - Local priority. This 3-bit fieldis only used when LPRIO_EN bit is set in MCR and it only
 *    makes sense for Tx buffers. These bits are not transmitted. They are appended to the regular
 *    ID to define the transmission priority.
 */
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x)) << CAN_ID_PRIO_SHIFT)) & CAN_ID_PRIO_MASK)
/*! @} */

/* The count of CAN_ID */
#define CAN_ID_COUNT                             (16U)

/*! @name WORD0 - Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register */
/*! @{ */

#define CAN_WORD0_DATA_BYTE_3_MASK               (0xFFUL)
#define CAN_WORD0_DATA_BYTE_3_SHIFT              (0UL)
/*! DATA_BYTE_3 - Data byte 3 of Rx/Tx frame. */
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_3_SHIFT)) & CAN_WORD0_DATA_BYTE_3_MASK)

#define CAN_WORD0_DATA_BYTE_2_MASK               (0xFF00UL)
#define CAN_WORD0_DATA_BYTE_2_SHIFT              (8UL)
/*! DATA_BYTE_2 - Data byte 2 of Rx/Tx frame. */
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_2_SHIFT)) & CAN_WORD0_DATA_BYTE_2_MASK)

#define CAN_WORD0_DATA_BYTE_1_MASK               (0xFF0000UL)
#define CAN_WORD0_DATA_BYTE_1_SHIFT              (16UL)
/*! DATA_BYTE_1 - Data byte 1 of Rx/Tx frame. */
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_1_SHIFT)) & CAN_WORD0_DATA_BYTE_1_MASK)

#define CAN_WORD0_DATA_BYTE_0_MASK               (0xFF000000UL)
#define CAN_WORD0_DATA_BYTE_0_SHIFT              (24UL)
/*! DATA_BYTE_0 - Data byte 0 of Rx/Tx frame. */
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD0_DATA_BYTE_0_SHIFT)) & CAN_WORD0_DATA_BYTE_0_MASK)
/*! @} */

/* The count of CAN_WORD0 */
#define CAN_WORD0_COUNT                          (16U)

/*! @name WORD1 - Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register */
/*! @{ */

#define CAN_WORD1_DATA_BYTE_7_MASK               (0xFFUL)
#define CAN_WORD1_DATA_BYTE_7_SHIFT              (0UL)
/*! DATA_BYTE_7 - Data byte 7 of Rx/Tx frame. */
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_7_SHIFT)) & CAN_WORD1_DATA_BYTE_7_MASK)

#define CAN_WORD1_DATA_BYTE_6_MASK               (0xFF00UL)
#define CAN_WORD1_DATA_BYTE_6_SHIFT              (8UL)
/*! DATA_BYTE_6 - Data byte 6 of Rx/Tx frame. */
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_6_SHIFT)) & CAN_WORD1_DATA_BYTE_6_MASK)

#define CAN_WORD1_DATA_BYTE_5_MASK               (0xFF0000UL)
#define CAN_WORD1_DATA_BYTE_5_SHIFT              (16UL)
/*! DATA_BYTE_5 - Data byte 5 of Rx/Tx frame. */
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_5_SHIFT)) & CAN_WORD1_DATA_BYTE_5_MASK)

#define CAN_WORD1_DATA_BYTE_4_MASK               (0xFF000000UL)
#define CAN_WORD1_DATA_BYTE_4_SHIFT              (24UL)
/*! DATA_BYTE_4 - Data byte 4 of Rx/Tx frame. */
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x)) << CAN_WORD1_DATA_BYTE_4_SHIFT)) & CAN_WORD1_DATA_BYTE_4_MASK)
/*! @} */

/* The count of CAN_WORD1 */
#define CAN_WORD1_COUNT                          (16U)

/*! @name RXIMR - Rx Individual Mask Registers */
/*! @{ */

#define CAN_RXIMR_MI_MASK                        (0xFFFFFFFFUL)
#define CAN_RXIMR_MI_SHIFT                       (0UL)
/*! MI - Individual Mask Bits
 *  0b00000000000000000000000000000000..The corresponding bit in the filter is "don't care."
 *  0b00000000000000000000000000000001..The corresponding bit in the filter is checked.
 */
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x)) << CAN_RXIMR_MI_SHIFT)) & CAN_RXIMR_MI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAN_Register_Masks */


/*!
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */


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


#endif  /* PERI_CAN_H_ */

