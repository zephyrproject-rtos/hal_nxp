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
**         CMSIS Peripheral Access Layer for I2C
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
 * @file PERI_I2C.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for I2C
 *
 * CMSIS Peripheral Access Layer for I2C
 */

#if !defined(PERI_I2C_H_)
#define PERI_I2C_H_                              /**< Symbol preventing repeated inclusion */

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
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  __IO uint16_t IADR;                              /**< I2C Address Register, offset: 0x0 */
       uint8_t RESERVED_0[2];
  __IO uint16_t IFDR;                              /**< I2C Frequency Divider Register, offset: 0x4 */
       uint8_t RESERVED_1[2];
  __IO uint16_t I2CR;                              /**< I2C Control Register, offset: 0x8 */
       uint8_t RESERVED_2[2];
  __IO uint16_t I2SR;                              /**< I2C Status Register, offset: 0xC */
       uint8_t RESERVED_3[2];
  __IO uint16_t I2DR;                              /**< I2C Data I/O Register, offset: 0x10 */
} I2C_Type;

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/*! @name IADR - I2C Address Register */
/*! @{ */

#define I2C_IADR_ADR_MASK                        (0xFEU)
#define I2C_IADR_ADR_SHIFT                       (1U)
#define I2C_IADR_ADR(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_IADR_ADR_SHIFT)) & I2C_IADR_ADR_MASK)
/*! @} */

/*! @name IFDR - I2C Frequency Divider Register */
/*! @{ */

#define I2C_IFDR_IC_MASK                         (0x3FU)
#define I2C_IFDR_IC_SHIFT                        (0U)
#define I2C_IFDR_IC(x)                           (((uint16_t)(((uint16_t)(x)) << I2C_IFDR_IC_SHIFT)) & I2C_IFDR_IC_MASK)
/*! @} */

/*! @name I2CR - I2C Control Register */
/*! @{ */

#define I2C_I2CR_RSTA_MASK                       (0x4U)
#define I2C_I2CR_RSTA_SHIFT                      (2U)
/*! RSTA
 *  0b0..No repeat start
 *  0b1..Generates a Repeated Start condition
 */
#define I2C_I2CR_RSTA(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_RSTA_SHIFT)) & I2C_I2CR_RSTA_MASK)

#define I2C_I2CR_TXAK_MASK                       (0x8U)
#define I2C_I2CR_TXAK_SHIFT                      (3U)
/*! TXAK
 *  0b0..An acknowledge signal is sent to the bus at the ninth clock bit after receiving one byte of data.
 *  0b1..No acknowledge signal response is sent (that is, the acknowledge bit = 1).
 */
#define I2C_I2CR_TXAK(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_TXAK_SHIFT)) & I2C_I2CR_TXAK_MASK)

#define I2C_I2CR_MTX_MASK                        (0x10U)
#define I2C_I2CR_MTX_SHIFT                       (4U)
/*! MTX
 *  0b0..Receive.When a slave is addressed, the software should set MTX according to the slave read/write bit in
 *       the I2C status register (I2C_I2SR[SRW]).
 *  0b1..Transmit.In Master mode, MTX should be set according to the type of transfer required. Therefore, for address cycles, MTX is always 1.
 */
#define I2C_I2CR_MTX(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_MTX_SHIFT)) & I2C_I2CR_MTX_MASK)

#define I2C_I2CR_MSTA_MASK                       (0x20U)
#define I2C_I2CR_MSTA_SHIFT                      (5U)
/*! MSTA
 *  0b0..Slave mode. Changing MSTA from 1 to 0 generates a Stop and selects Slave mode.
 *  0b1..Master mode. Changing MSTA from 0 to 1 signals a Start on the bus and selects Master mode.
 */
#define I2C_I2CR_MSTA(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_MSTA_SHIFT)) & I2C_I2CR_MSTA_MASK)

#define I2C_I2CR_IIEN_MASK                       (0x40U)
#define I2C_I2CR_IIEN_SHIFT                      (6U)
/*! IIEN
 *  0b0..I2C interrupts are disabled, but the status flag I2C_I2SR[IIF] continues to be set when an Interrupt condition occurs.
 *  0b1..I2C interrupts are enabled. An I2C interrupt occurs if I2C_I2SR[IIF] is also set.
 */
#define I2C_I2CR_IIEN(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_IIEN_SHIFT)) & I2C_I2CR_IIEN_MASK)

#define I2C_I2CR_IEN_MASK                        (0x80U)
#define I2C_I2CR_IEN_SHIFT                       (7U)
/*! IEN
 *  0b0..The block is disabled, but registers can still be accessed.
 *  0b1..The I2C is enabled. This bit must be set before any other I2C_I2CR bits have an effect.
 */
#define I2C_I2CR_IEN(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2CR_IEN_SHIFT)) & I2C_I2CR_IEN_MASK)
/*! @} */

/*! @name I2SR - I2C Status Register */
/*! @{ */

#define I2C_I2SR_RXAK_MASK                       (0x1U)
#define I2C_I2SR_RXAK_SHIFT                      (0U)
/*! RXAK
 *  0b0..An "acknowledge" signal was received after the completion of an 8-bit data transmission on the bus.
 *  0b1..A "No acknowledge" signal was detected at the ninth clock.
 */
#define I2C_I2SR_RXAK(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_RXAK_SHIFT)) & I2C_I2SR_RXAK_MASK)

#define I2C_I2SR_IIF_MASK                        (0x2U)
#define I2C_I2SR_IIF_SHIFT                       (1U)
/*! IIF
 *  0b0..No I2C interrupt pending.
 *  0b1..An interrupt is pending.This causes a processor interrupt request (if the interrupt enable is asserted
 *       [IIEN = 1]). The interrupt is set when one of the following occurs: One byte transfer is completed (the
 *       interrupt is set at the falling edge of the ninth clock). An address is received that matches its own specific
 *       address in Slave Receive mode. Arbitration is lost.
 */
#define I2C_I2SR_IIF(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_IIF_SHIFT)) & I2C_I2SR_IIF_MASK)

#define I2C_I2SR_SRW_MASK                        (0x4U)
#define I2C_I2SR_SRW_SHIFT                       (2U)
/*! SRW
 *  0b0..Slave receive, master writing to slave
 *  0b1..Slave transmit, master reading from slave
 */
#define I2C_I2SR_SRW(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_SRW_SHIFT)) & I2C_I2SR_SRW_MASK)

#define I2C_I2SR_IAL_MASK                        (0x10U)
#define I2C_I2SR_IAL_SHIFT                       (4U)
/*! IAL
 *  0b0..No arbitration lost.
 *  0b1..Arbitration is lost.
 */
#define I2C_I2SR_IAL(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_IAL_SHIFT)) & I2C_I2SR_IAL_MASK)

#define I2C_I2SR_IBB_MASK                        (0x20U)
#define I2C_I2SR_IBB_SHIFT                       (5U)
/*! IBB
 *  0b0..Bus is idle. If a Stop signal is detected, IBB is cleared.
 *  0b1..Bus is busy. When Start is detected, IBB is set.
 */
#define I2C_I2SR_IBB(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_IBB_SHIFT)) & I2C_I2SR_IBB_MASK)

#define I2C_I2SR_IAAS_MASK                       (0x40U)
#define I2C_I2SR_IAAS_SHIFT                      (6U)
/*! IAAS
 *  0b0..Not addressed
 *  0b1..Addressed as a slave. Set when its own address (I2C_IADR) matches the calling address.
 */
#define I2C_I2SR_IAAS(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_IAAS_SHIFT)) & I2C_I2SR_IAAS_MASK)

#define I2C_I2SR_ICF_MASK                        (0x80U)
#define I2C_I2SR_ICF_SHIFT                       (7U)
/*! ICF
 *  0b0..Transfer is in progress.
 *  0b1..Transfer is complete. This bit is set by the falling edge of the ninth clock of the last byte transfer.
 */
#define I2C_I2SR_ICF(x)                          (((uint16_t)(((uint16_t)(x)) << I2C_I2SR_ICF_SHIFT)) & I2C_I2SR_ICF_MASK)
/*! @} */

/*! @name I2DR - I2C Data I/O Register */
/*! @{ */

#define I2C_I2DR_DATA_MASK                       (0xFFU)
#define I2C_I2DR_DATA_SHIFT                      (0U)
#define I2C_I2DR_DATA(x)                         (((uint16_t)(((uint16_t)(x)) << I2C_I2DR_DATA_SHIFT)) & I2C_I2DR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


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


#endif  /* PERI_I2C_H_ */

