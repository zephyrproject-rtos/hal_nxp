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
**         CMSIS Peripheral Access Layer for PHYCONFIGURATION
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
 * @file PERI_PHYCONFIGURATION.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PHYCONFIGURATION
 *
 * CMSIS Peripheral Access Layer for PHYCONFIGURATION
 */

#if !defined(PERI_PHYCONFIGURATION_H_)
#define PERI_PHYCONFIGURATION_H_                 /**< Symbol preventing repeated inclusion */

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
   -- PHYCONFIGURATION Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHYCONFIGURATION_Peripheral_Access_Layer PHYCONFIGURATION Peripheral Access Layer
 * @{
 */

/** PHYCONFIGURATION - Register Layout Typedef */
typedef struct {
  __IO uint8_t PHY_CONF0;                          /**< PHY Configuration Register This register holds the power down, data enable polarity, and interface control of the HDMI Source PHY control., offset: 0x0 */
  __IO uint8_t PHY_TST0;                           /**< PHY Test Interface Register 0 PHY TX mapped test interface (control)., offset: 0x1 */
  __IO uint8_t PHY_TST1;                           /**< PHY Test Interface Register 1 PHY TX mapped text interface (data in)., offset: 0x2 */
  __I  uint8_t PHY_TST2;                           /**< PHY Test Interface Register 2 PHY TX mapped text interface (data out)., offset: 0x3 */
  __I  uint8_t PHY_STAT0;                          /**< PHY RXSENSE, PLL Lock, and HPD Status Register This register contains the following active high packet sent status indications., offset: 0x4 */
  __I  uint8_t PHY_INT0;                           /**< PHY RXSENSE, PLL Lock, and HPD Interrupt Register This register contains the interrupt indication of the PHY_STAT0 status interrupts., offset: 0x5 */
  __IO uint8_t PHY_MASK0;                          /**< PHY RXSENSE, PLL Lock, and HPD Mask Register Mask register for generation of PHY_INT0 interrupts., offset: 0x6 */
  __IO uint8_t PHY_POL0;                           /**< PHY RXSENSE, PLL Lock, and HPD Polarity Register Polarity register for generation of PHY_INT0 interrupts., offset: 0x7 */
       uint8_t RESERVED_0[24];
  __IO uint8_t PHY_I2CM_SLAVE;                     /**< PHY I2C Slave Address Configuration Register, offset: 0x20 */
  __IO uint8_t PHY_I2CM_ADDRESS;                   /**< PHY I2C Address Configuration Register This register writes the address for read and write operations., offset: 0x21 */
  __IO uint8_t PHY_I2CM_DATAO_1;                   /**< PHY I2C Data Write Register 1, offset: 0x22 */
  __IO uint8_t PHY_I2CM_DATAO_0;                   /**< PHY I2C Data Write Register 0, offset: 0x23 */
  __I  uint8_t PHY_I2CM_DATAI_1;                   /**< PHY I2C Data Read Register 1, offset: 0x24 */
  __I  uint8_t PHY_I2CM_DATAI_0;                   /**< PHY I2C Data Read Register 0, offset: 0x25 */
  __O  uint8_t PHY_I2CM_OPERATION;                 /**< PHY I2C RD/RD_EXT/WR Operation Register This register requests read and write operations from the I2C Master PHY., offset: 0x26 */
  __IO uint8_t PHY_I2CM_INT;                       /**< PHY I2C Done Interrupt Register This register contains and configures I2C master PHY done interrupt., offset: 0x27 */
  __IO uint8_t PHY_I2CM_CTLINT;                    /**< PHY I2C error Interrupt Register This register contains and configures the I2C master PHY error interrupts., offset: 0x28 */
  __IO uint8_t PHY_I2CM_DIV;                       /**< PHY I2C Speed control Register This register wets the I2C Master PHY to work in either Fast or Standard mode., offset: 0x29 */
  __IO uint8_t PHY_I2CM_SOFTRSTZ;                  /**< PHY I2C SW reset control register This register sets the I2C Master PHY software reset., offset: 0x2A */
  __IO uint8_t PHY_I2CM_SS_SCL_HCNT_1_ADDR;        /**< PHY I2C Slow Speed SCL High Level Control Register 1, offset: 0x2B */
  __IO uint8_t PHY_I2CM_SS_SCL_HCNT_0_ADDR;        /**< PHY I2C Slow Speed SCL High Level Control Register 0, offset: 0x2C */
  __IO uint8_t PHY_I2CM_SS_SCL_LCNT_1_ADDR;        /**< PHY I2C Slow Speed SCL Low Level Control Register 1, offset: 0x2D */
  __IO uint8_t PHY_I2CM_SS_SCL_LCNT_0_ADDR;        /**< PHY I2C Slow Speed SCL Low Level Control Register 0, offset: 0x2E */
  __IO uint8_t PHY_I2CM_FS_SCL_HCNT_1_ADDR;        /**< PHY I2C Fast Speed SCL High Level Control Register 1, offset: 0x2F */
  __IO uint8_t PHY_I2CM_FS_SCL_HCNT_0_ADDR;        /**< PHY I2C Fast Speed SCL High Level Control Register 0, offset: 0x30 */
  __IO uint8_t PHY_I2CM_FS_SCL_LCNT_1_ADDR;        /**< PHY I2C Fast Speed SCL Low Level Control Register 1, offset: 0x31 */
  __IO uint8_t PHY_I2CM_FS_SCL_LCNT_0_ADDR;        /**< PHY I2C Fast Speed SCL Low Level Control Register 0, offset: 0x32 */
  __IO uint8_t PHY_I2CM_SDA_HOLD;                  /**< PHY I2C SDA HOLD Control Register, offset: 0x33 */
  __IO uint8_t JTAG_PHY_CONFIG;                    /**< PHY I2C/JTAG I/O Configuration Control Register, offset: 0x34 */
  __IO uint8_t JTAG_PHY_TAP_TCK;                   /**< PHY JTAG Clock Control Register, offset: 0x35 */
  __IO uint8_t JTAG_PHY_TAP_IN;                    /**< PHY JTAG TAP In Control Register, offset: 0x36 */
  __I  uint8_t JTAG_PHY_TAP_OUT;                   /**< PHY JTAG TAP Out Control Register, offset: 0x37 */
  __IO uint8_t JTAG_PHY_ADDR;                      /**< PHY JTAG Address Control Register, offset: 0x38 */
} PHYCONFIGURATION_Type;

/* ----------------------------------------------------------------------------
   -- PHYCONFIGURATION Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHYCONFIGURATION_Register_Masks PHYCONFIGURATION Register Masks
 * @{
 */

/*! @name PHY_CONF0 - PHY Configuration Register This register holds the power down, data enable polarity, and interface control of the HDMI Source PHY control. */
/*! @{ */

#define PHYCONFIGURATION_PHY_CONF0_SELDIPIF_MASK (0x1U)
#define PHYCONFIGURATION_PHY_CONF0_SELDIPIF_SHIFT (0U)
/*! seldipif - Select interface control. */
#define PHYCONFIGURATION_PHY_CONF0_SELDIPIF(x)   (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_SELDIPIF_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_SELDIPIF_MASK)

#define PHYCONFIGURATION_PHY_CONF0_SELDATAENPOL_MASK (0x2U)
#define PHYCONFIGURATION_PHY_CONF0_SELDATAENPOL_SHIFT (1U)
/*! seldataenpol - Select data enable polarity. */
#define PHYCONFIGURATION_PHY_CONF0_SELDATAENPOL(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_SELDATAENPOL_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_SELDATAENPOL_MASK)

#define PHYCONFIGURATION_PHY_CONF0_ENHPDRXSENSE_MASK (0x4U)
#define PHYCONFIGURATION_PHY_CONF0_ENHPDRXSENSE_SHIFT (2U)
/*! enhpdrxsense - PHY ENHPDRXSENSE signal. */
#define PHYCONFIGURATION_PHY_CONF0_ENHPDRXSENSE(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_ENHPDRXSENSE_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_ENHPDRXSENSE_MASK)

#define PHYCONFIGURATION_PHY_CONF0_TXPWRON_MASK  (0x8U)
#define PHYCONFIGURATION_PHY_CONF0_TXPWRON_SHIFT (3U)
/*! txpwron - PHY TXPWRON signal. */
#define PHYCONFIGURATION_PHY_CONF0_TXPWRON(x)    (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_TXPWRON_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_TXPWRON_MASK)

#define PHYCONFIGURATION_PHY_CONF0_PDDQ_MASK     (0x10U)
#define PHYCONFIGURATION_PHY_CONF0_PDDQ_SHIFT    (4U)
/*! pddq - PHY PDDQ signal. */
#define PHYCONFIGURATION_PHY_CONF0_PDDQ(x)       (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_PDDQ_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_PDDQ_MASK)

#define PHYCONFIGURATION_PHY_CONF0_SPARECTRL_MASK (0x20U)
#define PHYCONFIGURATION_PHY_CONF0_SPARECTRL_SHIFT (5U)
/*! sparectrl - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_CONF0_SPARECTRL(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_SPARECTRL_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_SPARECTRL_MASK)

#define PHYCONFIGURATION_PHY_CONF0_SPARES_1_MASK (0x40U)
#define PHYCONFIGURATION_PHY_CONF0_SPARES_1_SHIFT (6U)
/*! spares_1 - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_CONF0_SPARES_1(x)   (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_SPARES_1_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_SPARES_1_MASK)

#define PHYCONFIGURATION_PHY_CONF0_SPARES_2_MASK (0x80U)
#define PHYCONFIGURATION_PHY_CONF0_SPARES_2_SHIFT (7U)
/*! spares_2 - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_CONF0_SPARES_2(x)   (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_CONF0_SPARES_2_SHIFT)) & PHYCONFIGURATION_PHY_CONF0_SPARES_2_MASK)
/*! @} */

/*! @name PHY_TST0 - PHY Test Interface Register 0 PHY TX mapped test interface (control). */
/*! @{ */

#define PHYCONFIGURATION_PHY_TST0_SPARE_0_MASK   (0x1U)
#define PHYCONFIGURATION_PHY_TST0_SPARE_0_SHIFT  (0U)
/*! spare_0 - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST0_SPARE_0(x)     (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST0_SPARE_0_SHIFT)) & PHYCONFIGURATION_PHY_TST0_SPARE_0_MASK)

#define PHYCONFIGURATION_PHY_TST0_SPARE_1_MASK   (0xEU)
#define PHYCONFIGURATION_PHY_TST0_SPARE_1_SHIFT  (1U)
/*! spare_1 - Reserved as "spare" bit with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST0_SPARE_1(x)     (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST0_SPARE_1_SHIFT)) & PHYCONFIGURATION_PHY_TST0_SPARE_1_MASK)

#define PHYCONFIGURATION_PHY_TST0_SPARE_3_MASK   (0x10U)
#define PHYCONFIGURATION_PHY_TST0_SPARE_3_SHIFT  (4U)
/*! spare_3 - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST0_SPARE_3(x)     (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST0_SPARE_3_SHIFT)) & PHYCONFIGURATION_PHY_TST0_SPARE_3_MASK)

#define PHYCONFIGURATION_PHY_TST0_SPARE_4_MASK   (0x20U)
#define PHYCONFIGURATION_PHY_TST0_SPARE_4_SHIFT  (5U)
/*! spare_4 - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST0_SPARE_4(x)     (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST0_SPARE_4_SHIFT)) & PHYCONFIGURATION_PHY_TST0_SPARE_4_MASK)

#define PHYCONFIGURATION_PHY_TST0_SPARE_2_MASK   (0xC0U)
#define PHYCONFIGURATION_PHY_TST0_SPARE_2_SHIFT  (6U)
/*! spare_2 - Reserved as "spare" bit with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST0_SPARE_2(x)     (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST0_SPARE_2_SHIFT)) & PHYCONFIGURATION_PHY_TST0_SPARE_2_MASK)
/*! @} */

/*! @name PHY_TST1 - PHY Test Interface Register 1 PHY TX mapped text interface (data in). */
/*! @{ */

#define PHYCONFIGURATION_PHY_TST1_SPARE_MASK     (0xFFU)
#define PHYCONFIGURATION_PHY_TST1_SPARE_SHIFT    (0U)
/*! spare - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST1_SPARE(x)       (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST1_SPARE_SHIFT)) & PHYCONFIGURATION_PHY_TST1_SPARE_MASK)
/*! @} */

/*! @name PHY_TST2 - PHY Test Interface Register 2 PHY TX mapped text interface (data out). */
/*! @{ */

#define PHYCONFIGURATION_PHY_TST2_SPARE_MASK     (0xFFU)
#define PHYCONFIGURATION_PHY_TST2_SPARE_SHIFT    (0U)
/*! spare - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_TST2_SPARE(x)       (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_TST2_SPARE_SHIFT)) & PHYCONFIGURATION_PHY_TST2_SPARE_MASK)
/*! @} */

/*! @name PHY_STAT0 - PHY RXSENSE, PLL Lock, and HPD Status Register This register contains the following active high packet sent status indications. */
/*! @{ */

#define PHYCONFIGURATION_PHY_STAT0_TX_PHY_LOCK_MASK (0x1U)
#define PHYCONFIGURATION_PHY_STAT0_TX_PHY_LOCK_SHIFT (0U)
/*! TX_PHY_LOCK - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_TX_PHY_LOCK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_TX_PHY_LOCK_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_TX_PHY_LOCK_MASK)

#define PHYCONFIGURATION_PHY_STAT0_HPD_MASK      (0x2U)
#define PHYCONFIGURATION_PHY_STAT0_HPD_SHIFT     (1U)
/*! HPD - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_HPD(x)        (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_HPD_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_HPD_MASK)

#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_0_MASK (0x10U)
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_0_SHIFT (4U)
/*! RX_SENSE_0 - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_RX_SENSE_0_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_RX_SENSE_0_MASK)

#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_1_MASK (0x20U)
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_1_SHIFT (5U)
/*! RX_SENSE_1 - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_RX_SENSE_1_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_RX_SENSE_1_MASK)

#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_2_MASK (0x40U)
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_2_SHIFT (6U)
/*! RX_SENSE_2 - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_2(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_RX_SENSE_2_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_RX_SENSE_2_MASK)

#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_3_MASK (0x80U)
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_3_SHIFT (7U)
/*! RX_SENSE_3 - Status bit. */
#define PHYCONFIGURATION_PHY_STAT0_RX_SENSE_3(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_STAT0_RX_SENSE_3_SHIFT)) & PHYCONFIGURATION_PHY_STAT0_RX_SENSE_3_MASK)
/*! @} */

/*! @name PHY_INT0 - PHY RXSENSE, PLL Lock, and HPD Interrupt Register This register contains the interrupt indication of the PHY_STAT0 status interrupts. */
/*! @{ */

#define PHYCONFIGURATION_PHY_INT0_TX_PHY_LOCK_MASK (0x1U)
#define PHYCONFIGURATION_PHY_INT0_TX_PHY_LOCK_SHIFT (0U)
/*! TX_PHY_LOCK - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_TX_PHY_LOCK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_TX_PHY_LOCK_SHIFT)) & PHYCONFIGURATION_PHY_INT0_TX_PHY_LOCK_MASK)

#define PHYCONFIGURATION_PHY_INT0_HPD_MASK       (0x2U)
#define PHYCONFIGURATION_PHY_INT0_HPD_SHIFT      (1U)
/*! HPD - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_HPD(x)         (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_HPD_SHIFT)) & PHYCONFIGURATION_PHY_INT0_HPD_MASK)

#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_0_MASK (0x10U)
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_0_SHIFT (4U)
/*! RX_SENSE_0 - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_0(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_RX_SENSE_0_SHIFT)) & PHYCONFIGURATION_PHY_INT0_RX_SENSE_0_MASK)

#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_1_MASK (0x20U)
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_1_SHIFT (5U)
/*! RX_SENSE_1 - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_1(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_RX_SENSE_1_SHIFT)) & PHYCONFIGURATION_PHY_INT0_RX_SENSE_1_MASK)

#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_2_MASK (0x40U)
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_2_SHIFT (6U)
/*! RX_SENSE_2 - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_2(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_RX_SENSE_2_SHIFT)) & PHYCONFIGURATION_PHY_INT0_RX_SENSE_2_MASK)

#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_3_MASK (0x80U)
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_3_SHIFT (7U)
/*! RX_SENSE_3 - Interrupt indication bit. */
#define PHYCONFIGURATION_PHY_INT0_RX_SENSE_3(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_INT0_RX_SENSE_3_SHIFT)) & PHYCONFIGURATION_PHY_INT0_RX_SENSE_3_MASK)
/*! @} */

/*! @name PHY_MASK0 - PHY RXSENSE, PLL Lock, and HPD Mask Register Mask register for generation of PHY_INT0 interrupts. */
/*! @{ */

#define PHYCONFIGURATION_PHY_MASK0_TX_PHY_LOCK_MASK (0x1U)
#define PHYCONFIGURATION_PHY_MASK0_TX_PHY_LOCK_SHIFT (0U)
/*! TX_PHY_LOCK - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_TX_PHY_LOCK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_TX_PHY_LOCK_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_TX_PHY_LOCK_MASK)

#define PHYCONFIGURATION_PHY_MASK0_HPD_MASK      (0x2U)
#define PHYCONFIGURATION_PHY_MASK0_HPD_SHIFT     (1U)
/*! HPD - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_HPD(x)        (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_HPD_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_HPD_MASK)

#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_0_MASK (0x10U)
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_0_SHIFT (4U)
/*! RX_SENSE_0 - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_RX_SENSE_0_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_RX_SENSE_0_MASK)

#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_1_MASK (0x20U)
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_1_SHIFT (5U)
/*! RX_SENSE_1 - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_RX_SENSE_1_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_RX_SENSE_1_MASK)

#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_2_MASK (0x40U)
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_2_SHIFT (6U)
/*! RX_SENSE_2 - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_2(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_RX_SENSE_2_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_RX_SENSE_2_MASK)

#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_3_MASK (0x80U)
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_3_SHIFT (7U)
/*! RX_SENSE_3 - Mask bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_MASK0_RX_SENSE_3(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_MASK0_RX_SENSE_3_SHIFT)) & PHYCONFIGURATION_PHY_MASK0_RX_SENSE_3_MASK)
/*! @} */

/*! @name PHY_POL0 - PHY RXSENSE, PLL Lock, and HPD Polarity Register Polarity register for generation of PHY_INT0 interrupts. */
/*! @{ */

#define PHYCONFIGURATION_PHY_POL0_TX_PHY_LOCK_MASK (0x1U)
#define PHYCONFIGURATION_PHY_POL0_TX_PHY_LOCK_SHIFT (0U)
/*! TX_PHY_LOCK - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_TX_PHY_LOCK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_TX_PHY_LOCK_SHIFT)) & PHYCONFIGURATION_PHY_POL0_TX_PHY_LOCK_MASK)

#define PHYCONFIGURATION_PHY_POL0_HPD_MASK       (0x2U)
#define PHYCONFIGURATION_PHY_POL0_HPD_SHIFT      (1U)
/*! HPD - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_HPD(x)         (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_HPD_SHIFT)) & PHYCONFIGURATION_PHY_POL0_HPD_MASK)

#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_0_MASK (0x10U)
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_0_SHIFT (4U)
/*! RX_SENSE_0 - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_0(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_RX_SENSE_0_SHIFT)) & PHYCONFIGURATION_PHY_POL0_RX_SENSE_0_MASK)

#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_1_MASK (0x20U)
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_1_SHIFT (5U)
/*! RX_SENSE_1 - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_1(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_RX_SENSE_1_SHIFT)) & PHYCONFIGURATION_PHY_POL0_RX_SENSE_1_MASK)

#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_2_MASK (0x40U)
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_2_SHIFT (6U)
/*! RX_SENSE_2 - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_2(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_RX_SENSE_2_SHIFT)) & PHYCONFIGURATION_PHY_POL0_RX_SENSE_2_MASK)

#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_3_MASK (0x80U)
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_3_SHIFT (7U)
/*! RX_SENSE_3 - Polarity bit for PHY_INT0. */
#define PHYCONFIGURATION_PHY_POL0_RX_SENSE_3(x)  (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_POL0_RX_SENSE_3_SHIFT)) & PHYCONFIGURATION_PHY_POL0_RX_SENSE_3_MASK)
/*! @} */

/*! @name PHY_I2CM_SLAVE - PHY I2C Slave Address Configuration Register */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SLAVE_SLAVEADDR_MASK (0x7FU)
#define PHYCONFIGURATION_PHY_I2CM_SLAVE_SLAVEADDR_SHIFT (0U)
/*! slaveaddr - Slave address to be sent during read and write operations. */
#define PHYCONFIGURATION_PHY_I2CM_SLAVE_SLAVEADDR(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SLAVE_SLAVEADDR_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SLAVE_SLAVEADDR_MASK)
/*! @} */

/*! @name PHY_I2CM_ADDRESS - PHY I2C Address Configuration Register This register writes the address for read and write operations. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_ADDRESS_ADDRESS_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_ADDRESS_ADDRESS_SHIFT (0U)
/*! address - Register address for read and write operations */
#define PHYCONFIGURATION_PHY_I2CM_ADDRESS_ADDRESS(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_ADDRESS_ADDRESS_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_ADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name PHY_I2CM_DATAO_1 - PHY I2C Data Write Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_DATAO_1_DATAO_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_DATAO_1_DATAO_SHIFT (0U)
/*! datao - Data MSB (datao[15:8]) to be written on register pointed by phy_i2cm_address [7:0]. */
#define PHYCONFIGURATION_PHY_I2CM_DATAO_1_DATAO(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DATAO_1_DATAO_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DATAO_1_DATAO_MASK)
/*! @} */

/*! @name PHY_I2CM_DATAO_0 - PHY I2C Data Write Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_DATAO_0_DATAO_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_DATAO_0_DATAO_SHIFT (0U)
/*! datao - Data LSB (datao[7:0]) to be written on register pointed by phy_i2cm_address [7:0]. */
#define PHYCONFIGURATION_PHY_I2CM_DATAO_0_DATAO(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DATAO_0_DATAO_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DATAO_0_DATAO_MASK)
/*! @} */

/*! @name PHY_I2CM_DATAI_1 - PHY I2C Data Read Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_DATAI_1_DATAI_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_DATAI_1_DATAI_SHIFT (0U)
/*! datai - Data MSB (datai[15:8]) read from register pointed by phy_i2cm_address[7:0]. */
#define PHYCONFIGURATION_PHY_I2CM_DATAI_1_DATAI(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DATAI_1_DATAI_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DATAI_1_DATAI_MASK)
/*! @} */

/*! @name PHY_I2CM_DATAI_0 - PHY I2C Data Read Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_DATAI_0_DATAI_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_DATAI_0_DATAI_SHIFT (0U)
/*! datai - Data LSB (datai[7:0]) read from register pointed by phy_i2cm_address[7:0]. */
#define PHYCONFIGURATION_PHY_I2CM_DATAI_0_DATAI(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DATAI_0_DATAI_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DATAI_0_DATAI_MASK)
/*! @} */

/*! @name PHY_I2CM_OPERATION - PHY I2C RD/RD_EXT/WR Operation Register This register requests read and write operations from the I2C Master PHY. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_OPERATION_RD_MASK (0x1U)
#define PHYCONFIGURATION_PHY_I2CM_OPERATION_RD_SHIFT (0U)
/*! rd - Read operation request */
#define PHYCONFIGURATION_PHY_I2CM_OPERATION_RD(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_OPERATION_RD_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_OPERATION_RD_MASK)

#define PHYCONFIGURATION_PHY_I2CM_OPERATION_WR_MASK (0x10U)
#define PHYCONFIGURATION_PHY_I2CM_OPERATION_WR_SHIFT (4U)
/*! wr - Write operation request */
#define PHYCONFIGURATION_PHY_I2CM_OPERATION_WR(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_OPERATION_WR_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_OPERATION_WR_MASK)
/*! @} */

/*! @name PHY_I2CM_INT - PHY I2C Done Interrupt Register This register contains and configures I2C master PHY done interrupt. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_STATUS_MASK (0x1U)
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_STATUS_SHIFT (0U)
/*! done_status - Operation done status bit. */
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_STATUS(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_INT_DONE_STATUS_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_INT_DONE_STATUS_MASK)

#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_INTERRUPT_MASK (0x2U)
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_INTERRUPT_SHIFT (1U)
/*! done_interrupt - Operation done interrupt bit. */
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_INTERRUPT(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_INT_DONE_INTERRUPT_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_INT_DONE_INTERRUPT_MASK)

#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_MASK_MASK (0x4U)
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_MASK_SHIFT (2U)
/*! done_mask - Done interrupt mask signal */
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_MASK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_INT_DONE_MASK_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_INT_DONE_MASK_MASK)

#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_POL_MASK (0x8U)
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_POL_SHIFT (3U)
/*! done_pol - Done interrupt polarity configuration */
#define PHYCONFIGURATION_PHY_I2CM_INT_DONE_POL(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_INT_DONE_POL_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_INT_DONE_POL_MASK)
/*! @} */

/*! @name PHY_I2CM_CTLINT - PHY I2C error Interrupt Register This register contains and configures the I2C master PHY error interrupts. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_STATUS_MASK (0x1U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_STATUS_SHIFT (0U)
/*! arbitration_status - Arbitration error status bit. */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_STATUS(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_STATUS_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_STATUS_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_INTERRUPT_MASK (0x2U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_INTERRUPT_SHIFT (1U)
/*! arbitration_interrupt - Arbitration error interrupt bit {arbitration_interrupt =
 *    (arbitration_mask==0b) && (arbitration_status==arbitration_pol)} Note: This bit field is read by the sticky
 *    bits present on the ih_i2cmphy_stat0 register.
 */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_INTERRUPT(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_INTERRUPT_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_INTERRUPT_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_MASK_MASK (0x4U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_MASK_SHIFT (2U)
/*! arbitration_mask - Arbitration error interrupt mask signal. */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_MASK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_MASK_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_MASK_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_POL_MASK (0x8U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_POL_SHIFT (3U)
/*! arbitration_pol - Arbitration error interrupt polarity configuration. */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_POL(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_POL_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_ARBITRATION_POL_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_STATUS_MASK (0x10U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_STATUS_SHIFT (4U)
/*! nack_status - Not acknowledge error status bit. */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_STATUS(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_STATUS_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_STATUS_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_INTERRUPT_MASK (0x20U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_INTERRUPT_SHIFT (5U)
/*! nack_interrupt - Not acknowledge error interrupt bit. */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_INTERRUPT(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_INTERRUPT_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_INTERRUPT_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_MASK_MASK (0x40U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_MASK_SHIFT (6U)
/*! nack_mask - Not acknowledge error interrupt mask signal */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_MASK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_MASK_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_MASK_MASK)

#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_POL_MASK (0x80U)
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_POL_SHIFT (7U)
/*! nack_pol - Not acknowledge error interrupt polarity configuration */
#define PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_POL(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_POL_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_CTLINT_NACK_POL_MASK)
/*! @} */

/*! @name PHY_I2CM_DIV - PHY I2C Speed control Register This register wets the I2C Master PHY to work in either Fast or Standard mode. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_DIV_SPARE_MASK (0x7U)
#define PHYCONFIGURATION_PHY_I2CM_DIV_SPARE_SHIFT (0U)
/*! spare - Reserved as "spare" register with no associated functionality. */
#define PHYCONFIGURATION_PHY_I2CM_DIV_SPARE(x)   (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DIV_SPARE_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DIV_SPARE_MASK)

#define PHYCONFIGURATION_PHY_I2CM_DIV_FAST_STD_MODE_MASK (0x8U)
#define PHYCONFIGURATION_PHY_I2CM_DIV_FAST_STD_MODE_SHIFT (3U)
/*! fast_std_mode - Sets the I2C Master to work in Fast Mode or Standard Mode: 1: Fast Mode 0: Standard Mode */
#define PHYCONFIGURATION_PHY_I2CM_DIV_FAST_STD_MODE(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_DIV_FAST_STD_MODE_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_DIV_FAST_STD_MODE_MASK)
/*! @} */

/*! @name PHY_I2CM_SOFTRSTZ - PHY I2C SW reset control register This register sets the I2C Master PHY software reset. */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_MASK (0x1U)
#define PHYCONFIGURATION_PHY_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_SHIFT (0U)
/*! i2c_softrstz - I2C Master Software Reset. */
#define PHYCONFIGURATION_PHY_I2CM_SOFTRSTZ_I2C_SOFTRSTZ(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_MASK)
/*! @} */

/*! @name PHY_I2CM_SS_SCL_HCNT_1_ADDR - PHY I2C Slow Speed SCL High Level Control Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_SHIFT (0U)
/*! i2cmp_ss_scl_hcnt1 - PHY I2C Slow Speed SCL High Level Control Register 1 */
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_MASK)
/*! @} */

/*! @name PHY_I2CM_SS_SCL_HCNT_0_ADDR - PHY I2C Slow Speed SCL High Level Control Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_SHIFT (0U)
/*! i2cmp_ss_scl_hcnt0 - PHY I2C Slow Speed SCL High Level Control Register 0 */
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_MASK)
/*! @} */

/*! @name PHY_I2CM_SS_SCL_LCNT_1_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_SHIFT (0U)
/*! i2cmp_ss_scl_lcnt1 - PHY I2C Slow Speed SCL Low Level Control Register 1 */
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_MASK)
/*! @} */

/*! @name PHY_I2CM_SS_SCL_LCNT_0_ADDR - PHY I2C Slow Speed SCL Low Level Control Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_SHIFT (0U)
/*! i2cmp_ss_scl_lcnt0 - PHY I2C Slow Speed SCL Low Level Control Register 0 */
#define PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_MASK)
/*! @} */

/*! @name PHY_I2CM_FS_SCL_HCNT_1_ADDR - PHY I2C Fast Speed SCL High Level Control Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_SHIFT (0U)
/*! i2cmp_fs_scl_hcnt1 - PHY I2C Fast Speed SCL High Level Control Register 1 */
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_MASK)
/*! @} */

/*! @name PHY_I2CM_FS_SCL_HCNT_0_ADDR - PHY I2C Fast Speed SCL High Level Control Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_SHIFT (0U)
/*! i2cmp_fs_scl_hcnt0 - PHY I2C Fast Speed SCL High Level Control Register 0 */
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_MASK)
/*! @} */

/*! @name PHY_I2CM_FS_SCL_LCNT_1_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 1 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_SHIFT (0U)
/*! i2cmp_fs_scl_lcnt1 - PHY I2C Fast Speed SCL Low Level Control Register 1 */
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_MASK)
/*! @} */

/*! @name PHY_I2CM_FS_SCL_LCNT_0_ADDR - PHY I2C Fast Speed SCL Low Level Control Register 0 */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_SHIFT (0U)
/*! i2cmp_fs_scl_lcnt0 - PHY I2C Fast Speed SCL Low Level Control Register 0 */
#define PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_MASK)
/*! @} */

/*! @name PHY_I2CM_SDA_HOLD - PHY I2C SDA HOLD Control Register */
/*! @{ */

#define PHYCONFIGURATION_PHY_I2CM_SDA_HOLD_OSDA_HOLD_MASK (0xFFU)
#define PHYCONFIGURATION_PHY_I2CM_SDA_HOLD_OSDA_HOLD_SHIFT (0U)
/*! osda_hold - Defines the number of SFR clock cycles to meet tHD:DAT (300 ns) osda_hold =
 *    round_to_high_integer (300 ns / (1/isfrclk_frequency))
 */
#define PHYCONFIGURATION_PHY_I2CM_SDA_HOLD_OSDA_HOLD(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_PHY_I2CM_SDA_HOLD_OSDA_HOLD_SHIFT)) & PHYCONFIGURATION_PHY_I2CM_SDA_HOLD_OSDA_HOLD_MASK)
/*! @} */

/*! @name JTAG_PHY_CONFIG - PHY I2C/JTAG I/O Configuration Control Register */
/*! @{ */

#define PHYCONFIGURATION_JTAG_PHY_CONFIG_JTAG_TRST_N_MASK (0x1U)
#define PHYCONFIGURATION_JTAG_PHY_CONFIG_JTAG_TRST_N_SHIFT (0U)
/*! jtag_trst_n - Configures the JTAG PHY interface output pin JTAG_TRST_N when in internal control
 *    mode (iphy_ext_ctrl=1'b0) or ophyext_jtag_trst_n when PHY_EXTERNAL=1.
 */
#define PHYCONFIGURATION_JTAG_PHY_CONFIG_JTAG_TRST_N(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_CONFIG_JTAG_TRST_N_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_CONFIG_JTAG_TRST_N_MASK)

#define PHYCONFIGURATION_JTAG_PHY_CONFIG_I2C_JTAGZ_MASK (0x10U)
#define PHYCONFIGURATION_JTAG_PHY_CONFIG_I2C_JTAGZ_SHIFT (4U)
/*! i2c_jtagz - Configures the JTAG PHY interface output pin I2C_JTAGZ to select the PHY
 *    configuration interface when in internal control mode (iphy_ext_ctrl=1'b0) or ophyext_jtag_i2c_jtagz when
 *    PHY_EXTERNAL=1.
 */
#define PHYCONFIGURATION_JTAG_PHY_CONFIG_I2C_JTAGZ(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_CONFIG_I2C_JTAGZ_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_CONFIG_I2C_JTAGZ_MASK)
/*! @} */

/*! @name JTAG_PHY_TAP_TCK - PHY JTAG Clock Control Register */
/*! @{ */

#define PHYCONFIGURATION_JTAG_PHY_TAP_TCK_JTAG_TCK_MASK (0x1U)
#define PHYCONFIGURATION_JTAG_PHY_TAP_TCK_JTAG_TCK_SHIFT (0U)
/*! jtag_tck - Configures the JTAG PHY interface pin JTAG_TCK when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or ophyext_jtag_tck when PHY_EXTERNAL=1.
 */
#define PHYCONFIGURATION_JTAG_PHY_TAP_TCK_JTAG_TCK(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_TAP_TCK_JTAG_TCK_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_TAP_TCK_JTAG_TCK_MASK)
/*! @} */

/*! @name JTAG_PHY_TAP_IN - PHY JTAG TAP In Control Register */
/*! @{ */

#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TDI_MASK (0x1U)
#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TDI_SHIFT (0U)
/*! jtag_tdi - Configures the JTAG PHY interface pin JTAG_TDI when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or ophyext_jtag_tdi when PHY_EXTERNAL=1.
 */
#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TDI(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TDI_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TDI_MASK)

#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TMS_MASK (0x10U)
#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TMS_SHIFT (4U)
/*! jtag_tms - Configures the JTAG PHY interface pin JTAG_TMS when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or ophyext_jtag_tms when PHY_EXTERNAL=1.
 */
#define PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TMS(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TMS_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_TAP_IN_JTAG_TMS_MASK)
/*! @} */

/*! @name JTAG_PHY_TAP_OUT - PHY JTAG TAP Out Control Register */
/*! @{ */

#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_MASK (0x1U)
#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_SHIFT (0U)
/*! jtag_tdo - Read JTAG PHY interface input pin JTAG_TDO when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or iphyext_jtag_tdo when PHY_EXTERNAL=1
 */
#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_MASK)

#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_EN_MASK (0x10U)
#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_EN_SHIFT (4U)
/*! jtag_tdo_en - Read JTAG PHY interface input pin JTAG_TDO_EN when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or iphyext_jtag_tdo_en when PHY_EXTERNAL=1
 */
#define PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_EN(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_EN_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_TAP_OUT_JTAG_TDO_EN_MASK)
/*! @} */

/*! @name JTAG_PHY_ADDR - PHY JTAG Address Control Register */
/*! @{ */

#define PHYCONFIGURATION_JTAG_PHY_ADDR_JTAG_ADDR_MASK (0xFFU)
#define PHYCONFIGURATION_JTAG_PHY_ADDR_JTAG_ADDR_SHIFT (0U)
/*! jtag_addr - Configures the JTAG PHY interface pin JTAG_ADDR[7:0] when in internal control mode
 *    (iphy_ext_ctrl=1'b0) or iphyext_jtag_addr[7:0] when PHY_EXTERNAL=1
 */
#define PHYCONFIGURATION_JTAG_PHY_ADDR_JTAG_ADDR(x) (((uint8_t)(((uint8_t)(x)) << PHYCONFIGURATION_JTAG_PHY_ADDR_JTAG_ADDR_SHIFT)) & PHYCONFIGURATION_JTAG_PHY_ADDR_JTAG_ADDR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PHYCONFIGURATION_Register_Masks */


/*!
 * @}
 */ /* end of group PHYCONFIGURATION_Peripheral_Access_Layer */


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


#endif  /* PERI_PHYCONFIGURATION_H_ */

