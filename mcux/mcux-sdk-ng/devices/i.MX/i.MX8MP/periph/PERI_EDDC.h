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
**         CMSIS Peripheral Access Layer for EDDC
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
 * @file PERI_EDDC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EDDC
 *
 * CMSIS Peripheral Access Layer for EDDC
 */

#if !defined(PERI_EDDC_H_)
#define PERI_EDDC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- EDDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDDC_Peripheral_Access_Layer EDDC Peripheral Access Layer
 * @{
 */

/** EDDC - Register Layout Typedef */
typedef struct {
  __IO uint8_t I2CM_SLAVE;                         /**< I2C DDC Slave address Configuration Register, offset: 0x0 */
  __IO uint8_t I2CM_ADDRESS;                       /**< I2C DDC Address Configuration Register, offset: 0x1 */
  __IO uint8_t I2CM_DATAO;                         /**< I2C DDC Data Write Register, offset: 0x2 */
  __I  uint8_t I2CM_DATAI;                         /**< I2C DDC Data read Register, offset: 0x3 */
  __O  uint8_t I2CM_OPERATION;                     /**< I2C DDC RD/RD_EXT/WR Operation Register Read and write operation request., offset: 0x4 */
  __IO uint8_t I2CM_INT;                           /**< I2C DDC Done Interrupt Register This register configures the I2C master interrupts., offset: 0x5 */
  __IO uint8_t I2CM_CTLINT;                        /**< I2C DDC error Interrupt Register This register configures the I2C master arbitration lost and not acknowledge error interrupts., offset: 0x6 */
  __IO uint8_t I2CM_DIV;                           /**< I2C DDC Speed Control Register This register configures the division relation between master and scl clock., offset: 0x7 */
  __IO uint8_t I2CM_SEGADDR;                       /**< I2C DDC Segment Address Configuration Register This register configures the segment address for extended R/W destination and is used for EDID reading operations, particularly for the Extended Data Read Operation for Enhanced DDC., offset: 0x8 */
  __IO uint8_t I2CM_SOFTRSTZ;                      /**< I2C DDC Software Reset Control Register This register resets the I2C master., offset: 0x9 */
  __IO uint8_t I2CM_SEGPTR;                        /**< I2C DDC Segment Pointer Register This register configures the segment pointer for extended RD/WR request., offset: 0xA */
  __IO uint8_t I2CM_SS_SCL_HCNT_1_ADDR;            /**< I2C DDC Slow Speed SCL High Level Control Register 1, offset: 0xB */
  __IO uint8_t I2CM_SS_SCL_HCNT_0_ADDR;            /**< I2C DDC Slow Speed SCL High Level Control Register 0, offset: 0xC */
  __IO uint8_t I2CM_SS_SCL_LCNT_1_ADDR;            /**< I2C DDC Slow Speed SCL Low Level Control Register 1, offset: 0xD */
  __IO uint8_t I2CM_SS_SCL_LCNT_0_ADDR;            /**< I2C DDC Slow Speed SCL Low Level Control Register 0, offset: 0xE */
  __IO uint8_t I2CM_FS_SCL_HCNT_1_ADDR;            /**< I2C DDC Fast Speed SCL High Level Control Register 1, offset: 0xF */
  __IO uint8_t I2CM_FS_SCL_HCNT_0_ADDR;            /**< I2C DDC Fast Speed SCL High Level Control Register 0, offset: 0x10 */
  __IO uint8_t I2CM_FS_SCL_LCNT_1_ADDR;            /**< I2C DDC Fast Speed SCL Low Level Control Register 1, offset: 0x11 */
  __IO uint8_t I2CM_FS_SCL_LCNT_0_ADDR;            /**< I2C DDC Fast Speed SCL Low Level Control Register 0, offset: 0x12 */
  __IO uint8_t I2CM_SDA_HOLD;                      /**< I2C DDC SDA Hold Register, offset: 0x13 */
  __IO uint8_t I2CM_SCDC_READ_UPDATE;              /**< SCDC Control Register This register configures the SCDC update status read through the I2C master interface., offset: 0x14 */
       uint8_t RESERVED_0[11];
  __I  uint8_t I2CM_READ_BUFF0;                    /**< I2C Master Sequential Read Buffer Register 0, offset: 0x20 */
  __I  uint8_t I2CM_READ_BUFF1;                    /**< I2C Master Sequential Read Buffer Register 1, offset: 0x21 */
  __I  uint8_t I2CM_READ_BUFF2;                    /**< I2C Master Sequential Read Buffer Register 2, offset: 0x22 */
  __I  uint8_t I2CM_READ_BUFF3;                    /**< I2C Master Sequential Read Buffer Register 3, offset: 0x23 */
  __I  uint8_t I2CM_READ_BUFF4;                    /**< I2C Master Sequential Read Buffer Register 4, offset: 0x24 */
  __I  uint8_t I2CM_READ_BUFF5;                    /**< I2C Master Sequential Read Buffer Register 5, offset: 0x25 */
  __I  uint8_t I2CM_READ_BUFF6;                    /**< I2C Master Sequential Read Buffer Register 6, offset: 0x26 */
  __I  uint8_t I2CM_READ_BUFF7;                    /**< I2C Master Sequential Read Buffer Register 7, offset: 0x27 */
       uint8_t RESERVED_1[8];
  __I  uint8_t I2CM_SCDC_UPDATE0;                  /**< I2C SCDC Read Update Register 0, offset: 0x30 */
  __I  uint8_t I2CM_SCDC_UPDATE1;                  /**< I2C SCDC Read Update Register 1, offset: 0x31 */
} EDDC_Type;

/* ----------------------------------------------------------------------------
   -- EDDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EDDC_Register_Masks EDDC Register Masks
 * @{
 */

/*! @name I2CM_SLAVE - I2C DDC Slave address Configuration Register */
/*! @{ */

#define EDDC_I2CM_SLAVE_SLAVEADDR_MASK           (0x7FU)
#define EDDC_I2CM_SLAVE_SLAVEADDR_SHIFT          (0U)
/*! slaveaddr - Slave address to be sent during read and write normal operations. */
#define EDDC_I2CM_SLAVE_SLAVEADDR(x)             (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SLAVE_SLAVEADDR_SHIFT)) & EDDC_I2CM_SLAVE_SLAVEADDR_MASK)
/*! @} */

/*! @name I2CM_ADDRESS - I2C DDC Address Configuration Register */
/*! @{ */

#define EDDC_I2CM_ADDRESS_ADDRESS_MASK           (0xFFU)
#define EDDC_I2CM_ADDRESS_ADDRESS_SHIFT          (0U)
/*! address - Register address for read and write operations */
#define EDDC_I2CM_ADDRESS_ADDRESS(x)             (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_ADDRESS_ADDRESS_SHIFT)) & EDDC_I2CM_ADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name I2CM_DATAO - I2C DDC Data Write Register */
/*! @{ */

#define EDDC_I2CM_DATAO_DATAO_MASK               (0xFFU)
#define EDDC_I2CM_DATAO_DATAO_SHIFT              (0U)
/*! datao - Data to be written on register pointed by address[7:0]. */
#define EDDC_I2CM_DATAO_DATAO(x)                 (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_DATAO_DATAO_SHIFT)) & EDDC_I2CM_DATAO_DATAO_MASK)
/*! @} */

/*! @name I2CM_DATAI - I2C DDC Data read Register */
/*! @{ */

#define EDDC_I2CM_DATAI_DATAI_MASK               (0xFFU)
#define EDDC_I2CM_DATAI_DATAI_SHIFT              (0U)
/*! datai - Data read from register pointed by address[7:0]. */
#define EDDC_I2CM_DATAI_DATAI(x)                 (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_DATAI_DATAI_SHIFT)) & EDDC_I2CM_DATAI_DATAI_MASK)
/*! @} */

/*! @name I2CM_OPERATION - I2C DDC RD/RD_EXT/WR Operation Register Read and write operation request. */
/*! @{ */

#define EDDC_I2CM_OPERATION_RD_MASK              (0x1U)
#define EDDC_I2CM_OPERATION_RD_SHIFT             (0U)
/*! rd - Single byte read operation request */
#define EDDC_I2CM_OPERATION_RD(x)                (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_RD_SHIFT)) & EDDC_I2CM_OPERATION_RD_MASK)

#define EDDC_I2CM_OPERATION_RD_EXT_MASK          (0x2U)
#define EDDC_I2CM_OPERATION_RD_EXT_SHIFT         (1U)
/*! rd_ext - After writing 1'b1 to rd_ext bit a extended data read operation is started (E-DDC read operation). */
#define EDDC_I2CM_OPERATION_RD_EXT(x)            (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_RD_EXT_SHIFT)) & EDDC_I2CM_OPERATION_RD_EXT_MASK)

#define EDDC_I2CM_OPERATION_RD8_MASK             (0x4U)
#define EDDC_I2CM_OPERATION_RD8_SHIFT            (2U)
/*! rd8 - Sequential read operation request. */
#define EDDC_I2CM_OPERATION_RD8(x)               (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_RD8_SHIFT)) & EDDC_I2CM_OPERATION_RD8_MASK)

#define EDDC_I2CM_OPERATION_RD8_EXT_MASK         (0x8U)
#define EDDC_I2CM_OPERATION_RD8_EXT_SHIFT        (3U)
/*! rd8_ext - Extended sequential read operation request. */
#define EDDC_I2CM_OPERATION_RD8_EXT(x)           (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_RD8_EXT_SHIFT)) & EDDC_I2CM_OPERATION_RD8_EXT_MASK)

#define EDDC_I2CM_OPERATION_WR_MASK              (0x10U)
#define EDDC_I2CM_OPERATION_WR_SHIFT             (4U)
/*! wr - Single byte write operation request. */
#define EDDC_I2CM_OPERATION_WR(x)                (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_WR_SHIFT)) & EDDC_I2CM_OPERATION_WR_MASK)

#define EDDC_I2CM_OPERATION_BUSCLEAR_MASK        (0x20U)
#define EDDC_I2CM_OPERATION_BUSCLEAR_SHIFT       (5U)
/*! busclear - bus clear operation request. */
#define EDDC_I2CM_OPERATION_BUSCLEAR(x)          (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_OPERATION_BUSCLEAR_SHIFT)) & EDDC_I2CM_OPERATION_BUSCLEAR_MASK)
/*! @} */

/*! @name I2CM_INT - I2C DDC Done Interrupt Register This register configures the I2C master interrupts. */
/*! @{ */

#define EDDC_I2CM_INT_DONE_MASK_MASK             (0x4U)
#define EDDC_I2CM_INT_DONE_MASK_SHIFT            (2U)
/*! done_mask - Done interrupt mask signal. */
#define EDDC_I2CM_INT_DONE_MASK(x)               (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_INT_DONE_MASK_SHIFT)) & EDDC_I2CM_INT_DONE_MASK_MASK)

#define EDDC_I2CM_INT_READ_REQ_MASK_MASK         (0x40U)
#define EDDC_I2CM_INT_READ_REQ_MASK_SHIFT        (6U)
/*! read_req_mask - Read request interruption mask signal. */
#define EDDC_I2CM_INT_READ_REQ_MASK(x)           (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_INT_READ_REQ_MASK_SHIFT)) & EDDC_I2CM_INT_READ_REQ_MASK_MASK)
/*! @} */

/*! @name I2CM_CTLINT - I2C DDC error Interrupt Register This register configures the I2C master arbitration lost and not acknowledge error interrupts. */
/*! @{ */

#define EDDC_I2CM_CTLINT_ARBITRATION_MASK_MASK   (0x4U)
#define EDDC_I2CM_CTLINT_ARBITRATION_MASK_SHIFT  (2U)
/*! arbitration_mask - Arbitration error interrupt mask signal. */
#define EDDC_I2CM_CTLINT_ARBITRATION_MASK(x)     (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_CTLINT_ARBITRATION_MASK_SHIFT)) & EDDC_I2CM_CTLINT_ARBITRATION_MASK_MASK)

#define EDDC_I2CM_CTLINT_NACK_MASK_MASK          (0x40U)
#define EDDC_I2CM_CTLINT_NACK_MASK_SHIFT         (6U)
/*! nack_mask - Not acknowledge error interrupt mask signal. */
#define EDDC_I2CM_CTLINT_NACK_MASK(x)            (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_CTLINT_NACK_MASK_SHIFT)) & EDDC_I2CM_CTLINT_NACK_MASK_MASK)
/*! @} */

/*! @name I2CM_DIV - I2C DDC Speed Control Register This register configures the division relation between master and scl clock. */
/*! @{ */

#define EDDC_I2CM_DIV_SPARE_MASK                 (0x7U)
#define EDDC_I2CM_DIV_SPARE_SHIFT                (0U)
/*! spare - Reserved as "spare" bit with no associated functionality. */
#define EDDC_I2CM_DIV_SPARE(x)                   (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_DIV_SPARE_SHIFT)) & EDDC_I2CM_DIV_SPARE_MASK)

#define EDDC_I2CM_DIV_FAST_STD_MODE_MASK         (0x8U)
#define EDDC_I2CM_DIV_FAST_STD_MODE_SHIFT        (3U)
/*! fast_std_mode - Sets the I2C Master to work in Fast Mode or Standard Mode: 1: Fast Mode 0: Standard Mode */
#define EDDC_I2CM_DIV_FAST_STD_MODE(x)           (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_DIV_FAST_STD_MODE_SHIFT)) & EDDC_I2CM_DIV_FAST_STD_MODE_MASK)
/*! @} */

/*! @name I2CM_SEGADDR - I2C DDC Segment Address Configuration Register This register configures the segment address for extended R/W destination and is used for EDID reading operations, particularly for the Extended Data Read Operation for Enhanced DDC. */
/*! @{ */

#define EDDC_I2CM_SEGADDR_SEG_ADDR_MASK          (0x7FU)
#define EDDC_I2CM_SEGADDR_SEG_ADDR_SHIFT         (0U)
/*! seg_addr - I2C DDC Segment Address Configuration Register */
#define EDDC_I2CM_SEGADDR_SEG_ADDR(x)            (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SEGADDR_SEG_ADDR_SHIFT)) & EDDC_I2CM_SEGADDR_SEG_ADDR_MASK)
/*! @} */

/*! @name I2CM_SOFTRSTZ - I2C DDC Software Reset Control Register This register resets the I2C master. */
/*! @{ */

#define EDDC_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_MASK     (0x1U)
#define EDDC_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_SHIFT    (0U)
/*! i2c_softrstz - I2C Master Software Reset. */
#define EDDC_I2CM_SOFTRSTZ_I2C_SOFTRSTZ(x)       (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_SHIFT)) & EDDC_I2CM_SOFTRSTZ_I2C_SOFTRSTZ_MASK)
/*! @} */

/*! @name I2CM_SEGPTR - I2C DDC Segment Pointer Register This register configures the segment pointer for extended RD/WR request. */
/*! @{ */

#define EDDC_I2CM_SEGPTR_SEGPTR_MASK             (0xFFU)
#define EDDC_I2CM_SEGPTR_SEGPTR_SHIFT            (0U)
/*! segptr - I2C DDC Segment Pointer Register */
#define EDDC_I2CM_SEGPTR_SEGPTR(x)               (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SEGPTR_SEGPTR_SHIFT)) & EDDC_I2CM_SEGPTR_SEGPTR_MASK)
/*! @} */

/*! @name I2CM_SS_SCL_HCNT_1_ADDR - I2C DDC Slow Speed SCL High Level Control Register 1 */
/*! @{ */

#define EDDC_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_MASK (0xFFU)
#define EDDC_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_SHIFT (0U)
/*! i2cmp_ss_scl_hcnt1 - I2C DDC Slow Speed SCL High Level Control Register 1 */
#define EDDC_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_SHIFT)) & EDDC_I2CM_SS_SCL_HCNT_1_ADDR_I2CMP_SS_SCL_HCNT1_MASK)
/*! @} */

/*! @name I2CM_SS_SCL_HCNT_0_ADDR - I2C DDC Slow Speed SCL High Level Control Register 0 */
/*! @{ */

#define EDDC_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_MASK (0xFFU)
#define EDDC_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_SHIFT (0U)
/*! i2cmp_ss_scl_hcnt0 - I2C DDC Slow Speed SCL High Level Control Register 0 */
#define EDDC_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_SHIFT)) & EDDC_I2CM_SS_SCL_HCNT_0_ADDR_I2CMP_SS_SCL_HCNT0_MASK)
/*! @} */

/*! @name I2CM_SS_SCL_LCNT_1_ADDR - I2C DDC Slow Speed SCL Low Level Control Register 1 */
/*! @{ */

#define EDDC_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_MASK (0xFFU)
#define EDDC_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_SHIFT (0U)
/*! i2cmp_ss_scl_lcnt1 - I2C DDC Slow Speed SCL Low Level Control Register 1 */
#define EDDC_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_SHIFT)) & EDDC_I2CM_SS_SCL_LCNT_1_ADDR_I2CMP_SS_SCL_LCNT1_MASK)
/*! @} */

/*! @name I2CM_SS_SCL_LCNT_0_ADDR - I2C DDC Slow Speed SCL Low Level Control Register 0 */
/*! @{ */

#define EDDC_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_MASK (0xFFU)
#define EDDC_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_SHIFT (0U)
/*! i2cmp_ss_scl_lcnt0 - I2C DDC Slow Speed SCL Low Level Control Register 0 */
#define EDDC_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_SHIFT)) & EDDC_I2CM_SS_SCL_LCNT_0_ADDR_I2CMP_SS_SCL_LCNT0_MASK)
/*! @} */

/*! @name I2CM_FS_SCL_HCNT_1_ADDR - I2C DDC Fast Speed SCL High Level Control Register 1 */
/*! @{ */

#define EDDC_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_MASK (0xFFU)
#define EDDC_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_SHIFT (0U)
/*! i2cmp_fs_scl_hcnt1 - I2C DDC Fast Speed SCL High Level Control Register 1 */
#define EDDC_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_SHIFT)) & EDDC_I2CM_FS_SCL_HCNT_1_ADDR_I2CMP_FS_SCL_HCNT1_MASK)
/*! @} */

/*! @name I2CM_FS_SCL_HCNT_0_ADDR - I2C DDC Fast Speed SCL High Level Control Register 0 */
/*! @{ */

#define EDDC_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_MASK (0xFFU)
#define EDDC_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_SHIFT (0U)
/*! i2cmp_fs_scl_hcnt0 - I2C DDC Fast Speed SCL High Level Control Register 0 */
#define EDDC_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_SHIFT)) & EDDC_I2CM_FS_SCL_HCNT_0_ADDR_I2CMP_FS_SCL_HCNT0_MASK)
/*! @} */

/*! @name I2CM_FS_SCL_LCNT_1_ADDR - I2C DDC Fast Speed SCL Low Level Control Register 1 */
/*! @{ */

#define EDDC_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_MASK (0xFFU)
#define EDDC_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_SHIFT (0U)
/*! i2cmp_fs_scl_lcnt1 - I2C DDC Fast Speed SCL Low Level Control Register 1 */
#define EDDC_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_SHIFT)) & EDDC_I2CM_FS_SCL_LCNT_1_ADDR_I2CMP_FS_SCL_LCNT1_MASK)
/*! @} */

/*! @name I2CM_FS_SCL_LCNT_0_ADDR - I2C DDC Fast Speed SCL Low Level Control Register 0 */
/*! @{ */

#define EDDC_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_MASK (0xFFU)
#define EDDC_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_SHIFT (0U)
/*! i2cmp_fs_scl_lcnt0 - I2C DDC Fast Speed SCL Low Level Control Register 0 */
#define EDDC_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_SHIFT)) & EDDC_I2CM_FS_SCL_LCNT_0_ADDR_I2CMP_FS_SCL_LCNT0_MASK)
/*! @} */

/*! @name I2CM_SDA_HOLD - I2C DDC SDA Hold Register */
/*! @{ */

#define EDDC_I2CM_SDA_HOLD_OSDA_HOLD_MASK        (0xFFU)
#define EDDC_I2CM_SDA_HOLD_OSDA_HOLD_SHIFT       (0U)
/*! osda_hold - Defines the number of SFR clock cycles to meet tHD;DAT (300 ns) osda_hold =
 *    round_to_high_integer (300 ns / (1 / isfrclk_frequency))
 */
#define EDDC_I2CM_SDA_HOLD_OSDA_HOLD(x)          (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SDA_HOLD_OSDA_HOLD_SHIFT)) & EDDC_I2CM_SDA_HOLD_OSDA_HOLD_MASK)
/*! @} */

/*! @name I2CM_SCDC_READ_UPDATE - SCDC Control Register This register configures the SCDC update status read through the I2C master interface. */
/*! @{ */

#define EDDC_I2CM_SCDC_READ_UPDATE_READ_UPDATE_MASK (0x1U)
#define EDDC_I2CM_SCDC_READ_UPDATE_READ_UPDATE_SHIFT (0U)
/*! read_update - When set to 1'b1, a SCDC Update Read is performed and the read data loaded into
 *    registers i2cm_scdc_update0 and i2cm_scdc_update1.
 */
#define EDDC_I2CM_SCDC_READ_UPDATE_READ_UPDATE(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SCDC_READ_UPDATE_READ_UPDATE_SHIFT)) & EDDC_I2CM_SCDC_READ_UPDATE_READ_UPDATE_MASK)

#define EDDC_I2CM_SCDC_READ_UPDATE_READ_REQUEST_EN_MASK (0x10U)
#define EDDC_I2CM_SCDC_READ_UPDATE_READ_REQUEST_EN_SHIFT (4U)
/*! read_request_en - Read request enabled. */
#define EDDC_I2CM_SCDC_READ_UPDATE_READ_REQUEST_EN(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SCDC_READ_UPDATE_READ_REQUEST_EN_SHIFT)) & EDDC_I2CM_SCDC_READ_UPDATE_READ_REQUEST_EN_MASK)

#define EDDC_I2CM_SCDC_READ_UPDATE_UPDTRD_VSYNCPOLL_EN_MASK (0x20U)
#define EDDC_I2CM_SCDC_READ_UPDATE_UPDTRD_VSYNCPOLL_EN_SHIFT (5U)
/*! updtrd_vsyncpoll_en - Update read polling enabled. */
#define EDDC_I2CM_SCDC_READ_UPDATE_UPDTRD_VSYNCPOLL_EN(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SCDC_READ_UPDATE_UPDTRD_VSYNCPOLL_EN_SHIFT)) & EDDC_I2CM_SCDC_READ_UPDATE_UPDTRD_VSYNCPOLL_EN_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF0 - I2C Master Sequential Read Buffer Register 0 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF0_I2CM_READ_BUFF0_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF0_I2CM_READ_BUFF0_SHIFT (0U)
/*! i2cm_read_buff0 - Byte 0 of a I2C read buffer sequential read (from address i2cm_address) */
#define EDDC_I2CM_READ_BUFF0_I2CM_READ_BUFF0(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF0_I2CM_READ_BUFF0_SHIFT)) & EDDC_I2CM_READ_BUFF0_I2CM_READ_BUFF0_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF1 - I2C Master Sequential Read Buffer Register 1 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF1_I2CM_READ_BUFF1_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF1_I2CM_READ_BUFF1_SHIFT (0U)
/*! i2cm_read_buff1 - Byte 1 of a I2C read buffer sequential read (from address i2cm_address+1) */
#define EDDC_I2CM_READ_BUFF1_I2CM_READ_BUFF1(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF1_I2CM_READ_BUFF1_SHIFT)) & EDDC_I2CM_READ_BUFF1_I2CM_READ_BUFF1_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF2 - I2C Master Sequential Read Buffer Register 2 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF2_I2CM_READ_BUFF2_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF2_I2CM_READ_BUFF2_SHIFT (0U)
/*! i2cm_read_buff2 - Byte 2 of a I2C read buffer sequential read (from address i2cm_address+2) */
#define EDDC_I2CM_READ_BUFF2_I2CM_READ_BUFF2(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF2_I2CM_READ_BUFF2_SHIFT)) & EDDC_I2CM_READ_BUFF2_I2CM_READ_BUFF2_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF3 - I2C Master Sequential Read Buffer Register 3 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF3_I2CM_READ_BUFF3_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF3_I2CM_READ_BUFF3_SHIFT (0U)
/*! i2cm_read_buff3 - Byte 3 of a I2C read buffer sequential read (from address i2cm_address+3) */
#define EDDC_I2CM_READ_BUFF3_I2CM_READ_BUFF3(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF3_I2CM_READ_BUFF3_SHIFT)) & EDDC_I2CM_READ_BUFF3_I2CM_READ_BUFF3_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF4 - I2C Master Sequential Read Buffer Register 4 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF4_I2CM_READ_BUFF4_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF4_I2CM_READ_BUFF4_SHIFT (0U)
/*! i2cm_read_buff4 - Byte 4 of a I2C read buffer sequential read (from address i2cm_address+4) */
#define EDDC_I2CM_READ_BUFF4_I2CM_READ_BUFF4(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF4_I2CM_READ_BUFF4_SHIFT)) & EDDC_I2CM_READ_BUFF4_I2CM_READ_BUFF4_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF5 - I2C Master Sequential Read Buffer Register 5 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF5_I2CM_READ_BUFF5_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF5_I2CM_READ_BUFF5_SHIFT (0U)
/*! i2cm_read_buff5 - Byte 5 of a I2C read buffer sequential read (from address i2cm_address+5) */
#define EDDC_I2CM_READ_BUFF5_I2CM_READ_BUFF5(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF5_I2CM_READ_BUFF5_SHIFT)) & EDDC_I2CM_READ_BUFF5_I2CM_READ_BUFF5_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF6 - I2C Master Sequential Read Buffer Register 6 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF6_I2CM_READ_BUFF6_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF6_I2CM_READ_BUFF6_SHIFT (0U)
/*! i2cm_read_buff6 - Byte 6 of a I2C read buffer sequential read (from address i2cm_address+6) */
#define EDDC_I2CM_READ_BUFF6_I2CM_READ_BUFF6(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF6_I2CM_READ_BUFF6_SHIFT)) & EDDC_I2CM_READ_BUFF6_I2CM_READ_BUFF6_MASK)
/*! @} */

/*! @name I2CM_READ_BUFF7 - I2C Master Sequential Read Buffer Register 7 */
/*! @{ */

#define EDDC_I2CM_READ_BUFF7_I2CM_READ_BUFF7_MASK (0xFFU)
#define EDDC_I2CM_READ_BUFF7_I2CM_READ_BUFF7_SHIFT (0U)
/*! i2cm_read_buff7 - Byte 7 of a I2C read buffer sequential read (from address i2cm_address+7) */
#define EDDC_I2CM_READ_BUFF7_I2CM_READ_BUFF7(x)  (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_READ_BUFF7_I2CM_READ_BUFF7_SHIFT)) & EDDC_I2CM_READ_BUFF7_I2CM_READ_BUFF7_MASK)
/*! @} */

/*! @name I2CM_SCDC_UPDATE0 - I2C SCDC Read Update Register 0 */
/*! @{ */

#define EDDC_I2CM_SCDC_UPDATE0_I2CM_SCDC_UPDATE0_MASK (0xFFU)
#define EDDC_I2CM_SCDC_UPDATE0_I2CM_SCDC_UPDATE0_SHIFT (0U)
/*! i2cm_scdc_update0 - Byte 0 of a SCDC I2C update sequential read */
#define EDDC_I2CM_SCDC_UPDATE0_I2CM_SCDC_UPDATE0(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SCDC_UPDATE0_I2CM_SCDC_UPDATE0_SHIFT)) & EDDC_I2CM_SCDC_UPDATE0_I2CM_SCDC_UPDATE0_MASK)
/*! @} */

/*! @name I2CM_SCDC_UPDATE1 - I2C SCDC Read Update Register 1 */
/*! @{ */

#define EDDC_I2CM_SCDC_UPDATE1_I2CM_SCDC_UPDATE1_MASK (0xFFU)
#define EDDC_I2CM_SCDC_UPDATE1_I2CM_SCDC_UPDATE1_SHIFT (0U)
/*! i2cm_scdc_update1 - Byte 1 of a SCDC I2C update sequential read */
#define EDDC_I2CM_SCDC_UPDATE1_I2CM_SCDC_UPDATE1(x) (((uint8_t)(((uint8_t)(x)) << EDDC_I2CM_SCDC_UPDATE1_I2CM_SCDC_UPDATE1_SHIFT)) & EDDC_I2CM_SCDC_UPDATE1_I2CM_SCDC_UPDATE1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group EDDC_Register_Masks */


/*!
 * @}
 */ /* end of group EDDC_Peripheral_Access_Layer */


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


#endif  /* PERI_EDDC_H_ */

