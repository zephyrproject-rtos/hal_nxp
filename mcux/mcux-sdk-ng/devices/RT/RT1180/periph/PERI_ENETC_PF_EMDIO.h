/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ENETC_PF_EMDIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ENETC_PF_EMDIO.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ENETC_PF_EMDIO
 *
 * CMSIS Peripheral Access Layer for ENETC_PF_EMDIO
 */

#if !defined(PERI_ENETC_PF_EMDIO_H_)
#define PERI_ENETC_PF_EMDIO_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- ENETC_PF_EMDIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PF_EMDIO_Peripheral_Access_Layer ENETC_PF_EMDIO Peripheral Access Layer
 * @{
 */

/** ENETC_PF_EMDIO - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[7168];
  __IO uint32_t EMDIO_CFG;                         /**< External MDIO configuration register, offset: 0x1C00 */
  __IO uint32_t EMDIO_CTL;                         /**< External MDIO interface control register, offset: 0x1C04 */
  __IO uint32_t EMDIO_DATA;                        /**< External MDIO interface data register, offset: 0x1C08 */
  __IO uint32_t EMDIO_ADDR;                        /**< External MDIO register address register, offset: 0x1C0C */
  __I  uint32_t EMDIO_STAT;                        /**< External MDIO status register, offset: 0x1C10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t PHY_STATUS_CFG;                    /**< PHY status configuration register, offset: 0x1C20 */
  __IO uint32_t PHY_STATUS_CTL;                    /**< PHY status control register, offset: 0x1C24 */
  __I  uint32_t PHY_STATUS_DATA;                   /**< PHY status data register, offset: 0x1C28 */
  __IO uint32_t PHY_STATUS_ADDR;                   /**< PHY status register address register, offset: 0x1C2C */
  __IO uint32_t PHY_STATUS_EVENT;                  /**< PHY status event register, offset: 0x1C30 */
  __IO uint32_t PHY_STATUS_MASK;                   /**< PHY status mask register, offset: 0x1C34 */
       uint8_t RESERVED_2[8];
  __I  uint32_t MDIO_CFG;                          /**< MDIO configuration register, offset: 0x1C40 */
} ENETC_PF_EMDIO_Type;

/* ----------------------------------------------------------------------------
   -- ENETC_PF_EMDIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_PF_EMDIO_Register_Masks ENETC_PF_EMDIO Register Masks
 * @{
 */

/*! @name EMDIO_CFG - External MDIO configuration register */
/*! @{ */

#define ENETC_PF_EMDIO_EMDIO_CFG_BSY2_MASK       (0x1U)
#define ENETC_PF_EMDIO_EMDIO_CFG_BSY2_SHIFT      (0U)
/*! BSY2 - Busy 2 (same as bit 31)
 *  0b0..An MDIO transaction is not occurring; software may access other MDIO registers.
 *  0b1..An MDIO transaction is occurring.
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_BSY2(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_BSY2_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_BSY2_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_RD_ER_MASK (0x2U)
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_RD_ER_SHIFT (1U)
/*! MDIO_RD_ER
 *  0b0..No error
 *  0b1..The last read transaction received no response from a PHY; any data read should be considered invalid
 *       (for example, the PHY address does not match any PHY available on the MDIO bus).
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_RD_ER(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_MDIO_RD_ER_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_MDIO_RD_ER_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_HOLD_MASK  (0x1CU)
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_HOLD_SHIFT (2U)
/*! MDIO_HOLD
 *  0b000..1 NETC cycle
 *  0b001..3 NETC cycles
 *  0b010..5 NETC cycles (default - recommended value)
 *  0b011..7 NETC cycles
 *  0b100..9 NETC cycles
 *  0b101..11 NETC cycles
 *  0b110..13 NETC cycles
 *  0b111..15 NETC cycles
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_HOLD(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_MDIO_HOLD_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_MDIO_HOLD_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_PRE_DIS_MASK    (0x20U)
#define ENETC_PF_EMDIO_EMDIO_CFG_PRE_DIS_SHIFT   (5U)
/*! PRE_DIS
 *  0b0..Generation of MDIO preamble is enabled (default operation).
 *  0b1..Generation of MDIO preamble is disabled
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_PRE_DIS(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_PRE_DIS_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_PRE_DIS_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_ENC45_MASK      (0x40U)
#define ENETC_PF_EMDIO_EMDIO_CFG_ENC45_SHIFT     (6U)
/*! ENC45
 *  0b0..Clause 22 transactions are used.
 *  0b1..Clause 45 transactions are used.
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_ENC45(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_ENC45_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_ENC45_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_CLK_DIV_MASK (0xFF80U)
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_CLK_DIV_SHIFT (7U)
/*! MDIO_CLK_DIV - MDIO Clock Divisor */
#define ENETC_PF_EMDIO_EMDIO_CFG_MDIO_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_MDIO_CLK_DIV_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_MDIO_CLK_DIV_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_WHOAMI_MASK     (0x70000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_WHOAMI_SHIFT    (16U)
/*! WHOAMI - Returns the virtual port ID. */
#define ENETC_PF_EMDIO_EMDIO_CFG_WHOAMI(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_WHOAMI_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_WHOAMI_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_EHOLD_MASK      (0x400000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_EHOLD_SHIFT     (22U)
/*! EHOLD - Extended HOLD
 *  0b0..Normal operation. MDIO hold time is specified in .
 *  0b1..Extended Operation
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_EHOLD(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_EHOLD_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_EHOLD_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_NEG_MASK        (0x800000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_NEG_SHIFT       (23U)
/*! NEG
 *  0b0..Normal operation - positive edge
 *  0b1..MDIO is driven by master on MDC negative edge (default for external MDIOs)
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_NEG(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_NEG_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_NEG_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_ADDR_ERR_MASK   (0x10000000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_ADDR_ERR_SHIFT  (28U)
/*! ADDR_ERR
 *  0b0..Normal
 *  0b1..Error. An access control violation has occurred. The request address used does not match the MDIO PHY's
 *       address (clause 22) or MDIO port address (clause 45) assigned.
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_ADDR_ERR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_ADDR_ERR_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_ADDR_ERR_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_CIM_MASK        (0x20000000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_CIM_SHIFT       (29U)
/*! CIM
 *  0b0..Masked
 *  0b1..Enabled
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_CIM(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_CIM_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_CIM_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_CMP_MASK        (0x40000000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_CMP_SHIFT       (30U)
/*! CMP - MDIO Command Completion
 *  0b0..An MDIO command completion did not occur.
 *  0b1..An MDIO command completion occurred.
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_CMP(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_CMP_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_CMP_MASK)

#define ENETC_PF_EMDIO_EMDIO_CFG_BSY1_MASK       (0x80000000U)
#define ENETC_PF_EMDIO_EMDIO_CFG_BSY1_SHIFT      (31U)
/*! BSY1 - Busy 1
 *  0b0..An MDIO transaction is not occurring; software may access other MDIO registers.
 *  0b1..An MDIO transaction is occurring.
 */
#define ENETC_PF_EMDIO_EMDIO_CFG_BSY1(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CFG_BSY1_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CFG_BSY1_MASK)
/*! @} */

/*! @name EMDIO_CTL - External MDIO interface control register */
/*! @{ */

#define ENETC_PF_EMDIO_EMDIO_CTL_DEV_ADDR_MASK   (0x1FU)
#define ENETC_PF_EMDIO_EMDIO_CTL_DEV_ADDR_SHIFT  (0U)
/*! DEV_ADDR - 5-bit MDIO device address (Clause 45) / register address (Clause 22) */
#define ENETC_PF_EMDIO_EMDIO_CTL_DEV_ADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CTL_DEV_ADDR_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CTL_DEV_ADDR_MASK)

#define ENETC_PF_EMDIO_EMDIO_CTL_PORT_ADDR_MASK  (0x3E0U)
#define ENETC_PF_EMDIO_EMDIO_CTL_PORT_ADDR_SHIFT (5U)
/*! PORT_ADDR - 5-bit MDIO port address (Clause 45) / PHY address (Clause 22) */
#define ENETC_PF_EMDIO_EMDIO_CTL_PORT_ADDR(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CTL_PORT_ADDR_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CTL_PORT_ADDR_MASK)

#define ENETC_PF_EMDIO_EMDIO_CTL_POST_INC_MASK   (0x4000U)
#define ENETC_PF_EMDIO_EMDIO_CTL_POST_INC_SHIFT  (14U)
/*! POST_INC - MDIO read with address post-increment initiation. Self-clearing once transaction is complete. */
#define ENETC_PF_EMDIO_EMDIO_CTL_POST_INC(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CTL_POST_INC_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CTL_POST_INC_MASK)

#define ENETC_PF_EMDIO_EMDIO_CTL_READ_MASK       (0x8000U)
#define ENETC_PF_EMDIO_EMDIO_CTL_READ_SHIFT      (15U)
/*! READ - MDIO read initiation. */
#define ENETC_PF_EMDIO_EMDIO_CTL_READ(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CTL_READ_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CTL_READ_MASK)

#define ENETC_PF_EMDIO_EMDIO_CTL_BSY_MASK        (0x80000000U)
#define ENETC_PF_EMDIO_EMDIO_CTL_BSY_SHIFT       (31U)
/*! BSY - MDIO busy */
#define ENETC_PF_EMDIO_EMDIO_CTL_BSY(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_CTL_BSY_SHIFT)) & ENETC_PF_EMDIO_EMDIO_CTL_BSY_MASK)
/*! @} */

/*! @name EMDIO_DATA - External MDIO interface data register */
/*! @{ */

#define ENETC_PF_EMDIO_EMDIO_DATA_MDIO_DATA_MASK (0xFFFFU)
#define ENETC_PF_EMDIO_EMDIO_DATA_MDIO_DATA_SHIFT (0U)
/*! MDIO_DATA - 16-bit MDIO data. */
#define ENETC_PF_EMDIO_EMDIO_DATA_MDIO_DATA(x)   (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_DATA_MDIO_DATA_SHIFT)) & ENETC_PF_EMDIO_EMDIO_DATA_MDIO_DATA_MASK)
/*! @} */

/*! @name EMDIO_ADDR - External MDIO register address register */
/*! @{ */

#define ENETC_PF_EMDIO_EMDIO_ADDR_REGADDR_MASK   (0xFFFFU)
#define ENETC_PF_EMDIO_EMDIO_ADDR_REGADDR_SHIFT  (0U)
/*! REGADDR - MDIO PHY register address. */
#define ENETC_PF_EMDIO_EMDIO_ADDR_REGADDR(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_ADDR_REGADDR_SHIFT)) & ENETC_PF_EMDIO_EMDIO_ADDR_REGADDR_MASK)
/*! @} */

/*! @name EMDIO_STAT - External MDIO status register */
/*! @{ */

#define ENETC_PF_EMDIO_EMDIO_STAT_BSY_MASK       (0x1U)
#define ENETC_PF_EMDIO_EMDIO_STAT_BSY_SHIFT      (0U)
/*! BSY - Global MDIO busy */
#define ENETC_PF_EMDIO_EMDIO_STAT_BSY(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_STAT_BSY_SHIFT)) & ENETC_PF_EMDIO_EMDIO_STAT_BSY_MASK)

#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_MASK  (0x1F00U)
#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_SHIFT (8U)
/*! WHT_LIST - PHY white list */
#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_SHIFT)) & ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_MASK)

#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_ENA_MASK (0x8000U)
#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_ENA_SHIFT (15U)
/*! WHT_LIST_ENA - PHY white list enable */
#define ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_ENA(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_ENA_SHIFT)) & ENETC_PF_EMDIO_EMDIO_STAT_WHT_LIST_ENA_MASK)

#define ENETC_PF_EMDIO_EMDIO_STAT_PORT_ID_MASK   (0x70000U)
#define ENETC_PF_EMDIO_EMDIO_STAT_PORT_ID_SHIFT  (16U)
/*! PORT_ID - Port ID */
#define ENETC_PF_EMDIO_EMDIO_STAT_PORT_ID(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_STAT_PORT_ID_SHIFT)) & ENETC_PF_EMDIO_EMDIO_STAT_PORT_ID_MASK)

#define ENETC_PF_EMDIO_EMDIO_STAT_REQ_TYPE_MASK  (0x80000U)
#define ENETC_PF_EMDIO_EMDIO_STAT_REQ_TYPE_SHIFT (19U)
/*! REQ_TYPE - Port ID */
#define ENETC_PF_EMDIO_EMDIO_STAT_REQ_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_EMDIO_STAT_REQ_TYPE_SHIFT)) & ENETC_PF_EMDIO_EMDIO_STAT_REQ_TYPE_MASK)
/*! @} */

/*! @name PHY_STATUS_CFG - PHY status configuration register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_CFG_BSY_MASK   (0x1U)
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_BSY_SHIFT  (0U)
/*! BSY - MDIO busy */
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_BSY(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_CFG_BSY_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_CFG_BSY_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_CFG_MDIO_RD_ER_MASK (0x2U)
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_MDIO_RD_ER_SHIFT (1U)
/*! MDIO_RD_ER - MDIO read error */
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_MDIO_RD_ER(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_CFG_MDIO_RD_ER_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_CFG_MDIO_RD_ER_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_CFG_STATUS_INTERVAL_MASK (0xFFFF0000U)
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_STATUS_INTERVAL_SHIFT (16U)
/*! STATUS_INTERVAL - PHY status read interval */
#define ENETC_PF_EMDIO_PHY_STATUS_CFG_STATUS_INTERVAL(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_CFG_STATUS_INTERVAL_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_CFG_STATUS_INTERVAL_MASK)
/*! @} */

/*! @name PHY_STATUS_CTL - PHY status control register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_CTL_DEV_ADDR_MASK (0x1FU)
#define ENETC_PF_EMDIO_PHY_STATUS_CTL_DEV_ADDR_SHIFT (0U)
/*! DEV_ADDR - 5-bit MDIO device address (Clause 45) / register address (Clause 22) */
#define ENETC_PF_EMDIO_PHY_STATUS_CTL_DEV_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_CTL_DEV_ADDR_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_CTL_DEV_ADDR_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_CTL_PORT_ADDR_MASK (0x3E0U)
#define ENETC_PF_EMDIO_PHY_STATUS_CTL_PORT_ADDR_SHIFT (5U)
/*! PORT_ADDR - 5-bit MDIO port address (Clause 45) / PHY address (Clause 22) */
#define ENETC_PF_EMDIO_PHY_STATUS_CTL_PORT_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_CTL_PORT_ADDR_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_CTL_PORT_ADDR_MASK)
/*! @} */

/*! @name PHY_STATUS_DATA - PHY status data register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_DATA_MDIO_DATA_MASK (0xFFFFU)
#define ENETC_PF_EMDIO_PHY_STATUS_DATA_MDIO_DATA_SHIFT (0U)
/*! MDIO_DATA - 16-bit MDIO data */
#define ENETC_PF_EMDIO_PHY_STATUS_DATA_MDIO_DATA(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_DATA_MDIO_DATA_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_DATA_MDIO_DATA_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_DATA_CURR_CNT_MASK (0xFFFF0000U)
#define ENETC_PF_EMDIO_PHY_STATUS_DATA_CURR_CNT_SHIFT (16U)
/*! CURR_CNT - Current count */
#define ENETC_PF_EMDIO_PHY_STATUS_DATA_CURR_CNT(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_DATA_CURR_CNT_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_DATA_CURR_CNT_MASK)
/*! @} */

/*! @name PHY_STATUS_ADDR - PHY status register address register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_ADDR_REGADDR_MASK (0xFFFFU)
#define ENETC_PF_EMDIO_PHY_STATUS_ADDR_REGADDR_SHIFT (0U)
/*! REGADDR - MDIO PHY register address. Address of the register within the Clause 45 PHY device from which data is to be read. */
#define ENETC_PF_EMDIO_PHY_STATUS_ADDR_REGADDR(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_ADDR_REGADDR_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_ADDR_REGADDR_MASK)
/*! @} */

/*! @name PHY_STATUS_EVENT - PHY status event register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_HL_MASK (0xFFFFU)
#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_HL_SHIFT (0U)
/*! STATUS_EVENT_HL - Status event high-to-low. Set to 1 if a 1->0 transition on a corresponding data bit has occurred. Write 1 to clear. */
#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_HL(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_HL_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_HL_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_LH_MASK (0xFFFF0000U)
#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_LH_SHIFT (16U)
/*! STATUS_EVENT_LH - Status event low-to-high. Set to 1 if a 0->1 transition on a corresponding data bit has occurred. Write 1 to clear. */
#define ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_LH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_LH_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_EVENT_STATUS_EVENT_LH_MASK)
/*! @} */

/*! @name PHY_STATUS_MASK - PHY status mask register */
/*! @{ */

#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_HL_MASK (0xFFFFU)
#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_HL_SHIFT (0U)
/*! STATUS_MASK_HL - Status high-to-low mask. If set to 1, assert an interrupt if the corresponding event bit is set. */
#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_HL(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_HL_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_HL_MASK)

#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_LH_MASK (0xFFFF0000U)
#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_LH_SHIFT (16U)
/*! STATUS_MASK_LH - Status mask low-to-high. If set to 1, assert an interrupt if the corresponding event bit is set. */
#define ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_LH(x) (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_LH_SHIFT)) & ENETC_PF_EMDIO_PHY_STATUS_MASK_STATUS_MASK_LH_MASK)
/*! @} */

/*! @name MDIO_CFG - MDIO configuration register */
/*! @{ */

#define ENETC_PF_EMDIO_MDIO_CFG_MDIO_MODE_MASK   (0x10U)
#define ENETC_PF_EMDIO_MDIO_CFG_MDIO_MODE_SHIFT  (4U)
/*! MDIO_MODE - MDIO pin mode */
#define ENETC_PF_EMDIO_MDIO_CFG_MDIO_MODE(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_MDIO_CFG_MDIO_MODE_SHIFT)) & ENETC_PF_EMDIO_MDIO_CFG_MDIO_MODE_MASK)

#define ENETC_PF_EMDIO_MDIO_CFG_MDC_MODE_MASK    (0x20U)
#define ENETC_PF_EMDIO_MDIO_CFG_MDC_MODE_SHIFT   (5U)
/*! MDC_MODE - MDC pin mode */
#define ENETC_PF_EMDIO_MDIO_CFG_MDC_MODE(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_PF_EMDIO_MDIO_CFG_MDC_MODE_SHIFT)) & ENETC_PF_EMDIO_MDIO_CFG_MDC_MODE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENETC_PF_EMDIO_Register_Masks */


/*!
 * @}
 */ /* end of group ENETC_PF_EMDIO_Peripheral_Access_Layer */


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


#endif  /* PERI_ENETC_PF_EMDIO_H_ */

