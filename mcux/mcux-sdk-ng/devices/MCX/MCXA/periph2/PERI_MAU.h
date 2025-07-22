/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MAU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_MAU.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for MAU
 *
 * CMSIS Peripheral Access Layer for MAU
 */

#if !defined(PERI_MAU_H_)
#define PERI_MAU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
   -- MAU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAU_Peripheral_Access_Layer MAU Peripheral Access Layer
 * @{
 */

/** MAU - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SYS_CTLR;                          /**< System Control, offset: 0x10 */
  __IO uint32_t GEXP_STATUS_IE;                    /**< General Exception Status Interrupt Enable, offset: 0x14 */
  __IO uint32_t GEXP_STATUS;                       /**< General Exception Status, offset: 0x18 */
       uint8_t RESERVED_1[20];
  __IO uint32_t OP_CTRL;                           /**< Operation Control, offset: 0x30 */
       uint8_t RESERVED_2[4];
  __IO uint32_t RES_STATUS_IE;                     /**< Result Status Interrupt Enable, offset: 0x38 */
  __IO uint32_t RES_STATUS;                        /**< Result Status, offset: 0x3C */
  __IO uint32_t RES0;                              /**< Result Register 0, offset: 0x40 */
  __IO uint32_t RES1;                              /**< Result Register 1, offset: 0x44 */
  __IO uint32_t RES2;                              /**< Result Register 2, offset: 0x48 */
  __IO uint32_t RES3;                              /**< Result Register 3, offset: 0x4C */
} MAU_Type;

/* ----------------------------------------------------------------------------
   -- MAU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MAU_Register_Masks MAU Register Masks
 * @{
 */

/*! @name SYS_CTLR - System Control */
/*! @{ */

#define MAU_SYS_CTLR_ACG_EN_MASK                 (0x1U)
#define MAU_SYS_CTLR_ACG_EN_SHIFT                (0U)
/*! ACG_EN - Automatic Clock Gating Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_SYS_CTLR_ACG_EN(x)                   (((uint32_t)(((uint32_t)(x)) << MAU_SYS_CTLR_ACG_EN_SHIFT)) & MAU_SYS_CTLR_ACG_EN_MASK)
/*! @} */

/*! @name GEXP_STATUS_IE - General Exception Status Interrupt Enable */
/*! @{ */

#define MAU_GEXP_STATUS_IE_ERROR_IE_MASK         (0x1U)
#define MAU_GEXP_STATUS_IE_ERROR_IE_SHIFT        (0U)
/*! ERROR_IE - Direct operation Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_GEXP_STATUS_IE_ERROR_IE(x)           (((uint32_t)(((uint32_t)(x)) << MAU_GEXP_STATUS_IE_ERROR_IE_SHIFT)) & MAU_GEXP_STATUS_IE_ERROR_IE_MASK)
/*! @} */

/*! @name GEXP_STATUS - General Exception Status */
/*! @{ */

#define MAU_GEXP_STATUS_ERROR_MASK               (0x1U)
#define MAU_GEXP_STATUS_ERROR_SHIFT              (0U)
/*! ERROR - Direct operation Error
 *  0b0..No error is generated.
 *  0b1..An error is generated.
 */
#define MAU_GEXP_STATUS_ERROR(x)                 (((uint32_t)(((uint32_t)(x)) << MAU_GEXP_STATUS_ERROR_SHIFT)) & MAU_GEXP_STATUS_ERROR_MASK)
/*! @} */

/*! @name OP_CTRL - Operation Control */
/*! @{ */

#define MAU_OP_CTRL_OVDT_EN_RES0_MASK            (0x1U)
#define MAU_OP_CTRL_OVDT_EN_RES0_SHIFT           (0U)
/*! OVDT_EN_RES0 - Override RES0 Data Type Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_OP_CTRL_OVDT_EN_RES0(x)              (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_EN_RES0_SHIFT)) & MAU_OP_CTRL_OVDT_EN_RES0_MASK)

#define MAU_OP_CTRL_OVDT_RES0_MASK               (0x6U)
#define MAU_OP_CTRL_OVDT_RES0_SHIFT              (1U)
/*! OVDT_RES0 - Override RES0 Data Type
 *  0b00..UINT
 *  0b01..INT
 *  0b10..Q1.X
 *  0b11..FLOAT
 */
#define MAU_OP_CTRL_OVDT_RES0(x)                 (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_RES0_SHIFT)) & MAU_OP_CTRL_OVDT_RES0_MASK)

#define MAU_OP_CTRL_OVDT_EN_RES1_MASK            (0x100U)
#define MAU_OP_CTRL_OVDT_EN_RES1_SHIFT           (8U)
/*! OVDT_EN_RES1 - Override RES1 Data Type Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_OP_CTRL_OVDT_EN_RES1(x)              (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_EN_RES1_SHIFT)) & MAU_OP_CTRL_OVDT_EN_RES1_MASK)

#define MAU_OP_CTRL_OVDT_RES1_MASK               (0x600U)
#define MAU_OP_CTRL_OVDT_RES1_SHIFT              (9U)
/*! OVDT_RES1 - Override RES1 Data Type
 *  0b00..UINT
 *  0b01..INT
 *  0b10..Q1.X
 *  0b11..FLOAT
 */
#define MAU_OP_CTRL_OVDT_RES1(x)                 (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_RES1_SHIFT)) & MAU_OP_CTRL_OVDT_RES1_MASK)

#define MAU_OP_CTRL_OVDT_EN_RES2_MASK            (0x10000U)
#define MAU_OP_CTRL_OVDT_EN_RES2_SHIFT           (16U)
/*! OVDT_EN_RES2 - Override RES2 Data Type Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_OP_CTRL_OVDT_EN_RES2(x)              (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_EN_RES2_SHIFT)) & MAU_OP_CTRL_OVDT_EN_RES2_MASK)

#define MAU_OP_CTRL_OVDT_RES2_MASK               (0x60000U)
#define MAU_OP_CTRL_OVDT_RES2_SHIFT              (17U)
/*! OVDT_RES2 - Override RES2 Data Type
 *  0b00..UINT
 *  0b01..INT
 *  0b10..Q1.X
 *  0b11..FLOAT
 */
#define MAU_OP_CTRL_OVDT_RES2(x)                 (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_RES2_SHIFT)) & MAU_OP_CTRL_OVDT_RES2_MASK)

#define MAU_OP_CTRL_OVDT_EN_RES3_MASK            (0x1000000U)
#define MAU_OP_CTRL_OVDT_EN_RES3_SHIFT           (24U)
/*! OVDT_EN_RES3 - Override RES3 Data Type Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_OP_CTRL_OVDT_EN_RES3(x)              (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_EN_RES3_SHIFT)) & MAU_OP_CTRL_OVDT_EN_RES3_MASK)

#define MAU_OP_CTRL_OVDT_RES3_MASK               (0x6000000U)
#define MAU_OP_CTRL_OVDT_RES3_SHIFT              (25U)
/*! OVDT_RES3 - Override RES3 Data Type
 *  0b00..UINT
 *  0b01..INT
 *  0b10..Q1.X
 *  0b11..FLOAT
 */
#define MAU_OP_CTRL_OVDT_RES3(x)                 (((uint32_t)(((uint32_t)(x)) << MAU_OP_CTRL_OVDT_RES3_SHIFT)) & MAU_OP_CTRL_OVDT_RES3_MASK)
/*! @} */

/*! @name RES_STATUS_IE - Result Status Interrupt Enable */
/*! @{ */

#define MAU_RES_STATUS_IE_RES0_IE_MASK           (0x1U)
#define MAU_RES_STATUS_IE_RES0_IE_SHIFT          (0U)
/*! RES0_IE - RES0 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_RES_STATUS_IE_RES0_IE(x)             (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_IE_RES0_IE_SHIFT)) & MAU_RES_STATUS_IE_RES0_IE_MASK)

#define MAU_RES_STATUS_IE_RES1_IE_MASK           (0x2U)
#define MAU_RES_STATUS_IE_RES1_IE_SHIFT          (1U)
/*! RES1_IE - RES1 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_RES_STATUS_IE_RES1_IE(x)             (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_IE_RES1_IE_SHIFT)) & MAU_RES_STATUS_IE_RES1_IE_MASK)

#define MAU_RES_STATUS_IE_RES2_IE_MASK           (0x4U)
#define MAU_RES_STATUS_IE_RES2_IE_SHIFT          (2U)
/*! RES2_IE - RES2 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_RES_STATUS_IE_RES2_IE(x)             (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_IE_RES2_IE_SHIFT)) & MAU_RES_STATUS_IE_RES2_IE_MASK)

#define MAU_RES_STATUS_IE_RES3_IE_MASK           (0x8U)
#define MAU_RES_STATUS_IE_RES3_IE_SHIFT          (3U)
/*! RES3_IE - RES3 Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define MAU_RES_STATUS_IE_RES3_IE(x)             (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_IE_RES3_IE_SHIFT)) & MAU_RES_STATUS_IE_RES3_IE_MASK)
/*! @} */

/*! @name RES_STATUS - Result Status */
/*! @{ */

#define MAU_RES_STATUS_RES0_NX_MASK              (0x1U)
#define MAU_RES_STATUS_RES0_NX_SHIFT             (0U)
/*! RES0_NX - RES0 IEEE Inexact Flag
 *  0b0..The result is not rounded.
 *  0b1..The result is rounded, and as a result some digits lost.
 */
#define MAU_RES_STATUS_RES0_NX(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_NX_SHIFT)) & MAU_RES_STATUS_RES0_NX_MASK)

#define MAU_RES_STATUS_RES0_UF_MASK              (0x2U)
#define MAU_RES_STATUS_RES0_UF_SHIFT             (1U)
/*! RES0_UF - RES0 IEEE Underflow Flag
 *  0b0..No tiny non-zero result is detected.
 *  0b1..A tiny non-zero result is detected.
 */
#define MAU_RES_STATUS_RES0_UF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_UF_SHIFT)) & MAU_RES_STATUS_RES0_UF_MASK)

#define MAU_RES_STATUS_RES0_OF_MASK              (0x4U)
#define MAU_RES_STATUS_RES0_OF_SHIFT             (2U)
/*! RES0_OF - RES0 IEEE Overflow Flag
 *  0b0..The result format's largest finite number is not exceeded.
 *  0b1..The result format's largest finite number is exceeded.
 */
#define MAU_RES_STATUS_RES0_OF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_OF_SHIFT)) & MAU_RES_STATUS_RES0_OF_MASK)

#define MAU_RES_STATUS_RES0_DZ_MASK              (0x8U)
#define MAU_RES_STATUS_RES0_DZ_SHIFT             (3U)
/*! RES0_DZ - RES0 IEEE Divide by Zero Flag
 *  0b0..No exact infinite result is defined for an operation on finite operands.
 *  0b1..An exact infinite result is defined for an operation on finite operands.
 */
#define MAU_RES_STATUS_RES0_DZ(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_DZ_SHIFT)) & MAU_RES_STATUS_RES0_DZ_MASK)

#define MAU_RES_STATUS_RES0_NV_MASK              (0x10U)
#define MAU_RES_STATUS_RES0_NV_SHIFT             (4U)
/*! RES0_NV - RES0 IEEE Invalid Flag
 *  0b0..There is usefully definable result.
 *  0b1..There is no usefully definable result.
 */
#define MAU_RES_STATUS_RES0_NV(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_NV_SHIFT)) & MAU_RES_STATUS_RES0_NV_MASK)

#define MAU_RES_STATUS_RES0_ERR_MASK             (0x20U)
#define MAU_RES_STATUS_RES0_ERR_SHIFT            (5U)
/*! RES0_ERR - RES0 Indirect Operation Error Flag
 *  0b0..No invalid indirect operation is detected.
 *  0b1..An invalid indirect operation error is detected.
 */
#define MAU_RES_STATUS_RES0_ERR(x)               (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_ERR_SHIFT)) & MAU_RES_STATUS_RES0_ERR_MASK)

#define MAU_RES_STATUS_RES0_OVWR_MASK            (0x40U)
#define MAU_RES_STATUS_RES0_OVWR_SHIFT           (6U)
/*! RES0_OVWR - RES0 Overwrite Flag
 *  0b0..The value of RES0 has been read.
 *  0b1..The value of RES0 has not been read yet and is overwritten by a new MAUWRAP result.
 */
#define MAU_RES_STATUS_RES0_OVWR(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_OVWR_SHIFT)) & MAU_RES_STATUS_RES0_OVWR_MASK)

#define MAU_RES_STATUS_RES0_FULL_MASK            (0x80U)
#define MAU_RES_STATUS_RES0_FULL_SHIFT           (7U)
/*! RES0_FULL - RES0 Full Flag
 *  0b0..RES0 has not updated and cannot be read.
 *  0b1..RES0 has updated and can be read.
 */
#define MAU_RES_STATUS_RES0_FULL(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES0_FULL_SHIFT)) & MAU_RES_STATUS_RES0_FULL_MASK)

#define MAU_RES_STATUS_RES1_NX_MASK              (0x100U)
#define MAU_RES_STATUS_RES1_NX_SHIFT             (8U)
/*! RES1_NX - RES1 IEEE Inexact Flag
 *  0b0..The result is not rounded.
 *  0b1..The result is rounded, and as a result some digits lost.
 */
#define MAU_RES_STATUS_RES1_NX(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_NX_SHIFT)) & MAU_RES_STATUS_RES1_NX_MASK)

#define MAU_RES_STATUS_RES1_UF_MASK              (0x200U)
#define MAU_RES_STATUS_RES1_UF_SHIFT             (9U)
/*! RES1_UF - RES1 IEEE Underflow Flag
 *  0b0..No tiny non-zero result is detected.
 *  0b1..A tiny non-zero result is detected.
 */
#define MAU_RES_STATUS_RES1_UF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_UF_SHIFT)) & MAU_RES_STATUS_RES1_UF_MASK)

#define MAU_RES_STATUS_RES1_OF_MASK              (0x400U)
#define MAU_RES_STATUS_RES1_OF_SHIFT             (10U)
/*! RES1_OF - RES1 IEEE Overflow Flag
 *  0b0..The result format's largest finite number is not exceeded.
 *  0b1..The result format's largest finite number is exceeded.
 */
#define MAU_RES_STATUS_RES1_OF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_OF_SHIFT)) & MAU_RES_STATUS_RES1_OF_MASK)

#define MAU_RES_STATUS_RES1_DZ_MASK              (0x800U)
#define MAU_RES_STATUS_RES1_DZ_SHIFT             (11U)
/*! RES1_DZ - RES1 IEEE Divide by Zero Flag
 *  0b0..No exact infinite result is defined for an operation on finite operands.
 *  0b1..An exact infinite result is defined for an operation on finite operands.
 */
#define MAU_RES_STATUS_RES1_DZ(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_DZ_SHIFT)) & MAU_RES_STATUS_RES1_DZ_MASK)

#define MAU_RES_STATUS_RES1_NV_MASK              (0x1000U)
#define MAU_RES_STATUS_RES1_NV_SHIFT             (12U)
/*! RES1_NV - RES1 IEEE Invalid Flag
 *  0b0..There is usefully definable result.
 *  0b1..There is no usefully definable result.
 */
#define MAU_RES_STATUS_RES1_NV(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_NV_SHIFT)) & MAU_RES_STATUS_RES1_NV_MASK)

#define MAU_RES_STATUS_RES1_ERR_MASK             (0x2000U)
#define MAU_RES_STATUS_RES1_ERR_SHIFT            (13U)
/*! RES1_ERR - RES1 Indirect Operation Error Flag
 *  0b0..No invalid indirect operation is detected.
 *  0b1..An invalid indirect operation error is detected.
 */
#define MAU_RES_STATUS_RES1_ERR(x)               (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_ERR_SHIFT)) & MAU_RES_STATUS_RES1_ERR_MASK)

#define MAU_RES_STATUS_RES1_OVWR_MASK            (0x4000U)
#define MAU_RES_STATUS_RES1_OVWR_SHIFT           (14U)
/*! RES1_OVWR - RES1 Overwrite Flag
 *  0b0..The value of RES1 has been read.
 *  0b1..The value of RES1 has not been read yet and is overwritten by a new MAUWRAP result.
 */
#define MAU_RES_STATUS_RES1_OVWR(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_OVWR_SHIFT)) & MAU_RES_STATUS_RES1_OVWR_MASK)

#define MAU_RES_STATUS_RES1_FULL_MASK            (0x8000U)
#define MAU_RES_STATUS_RES1_FULL_SHIFT           (15U)
/*! RES1_FULL - RES1 Full Flag
 *  0b0..RES1 has not updated and cannot be read.
 *  0b1..RES1 has updated and can be read.
 */
#define MAU_RES_STATUS_RES1_FULL(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES1_FULL_SHIFT)) & MAU_RES_STATUS_RES1_FULL_MASK)

#define MAU_RES_STATUS_RES2_NX_MASK              (0x10000U)
#define MAU_RES_STATUS_RES2_NX_SHIFT             (16U)
/*! RES2_NX - RES2 IEEE Inexact Flag
 *  0b0..The result is not rounded.
 *  0b1..The result is rounded, and as a result some digits lost.
 */
#define MAU_RES_STATUS_RES2_NX(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_NX_SHIFT)) & MAU_RES_STATUS_RES2_NX_MASK)

#define MAU_RES_STATUS_RES2_UF_MASK              (0x20000U)
#define MAU_RES_STATUS_RES2_UF_SHIFT             (17U)
/*! RES2_UF - RES2 IEEE Underflow Flag
 *  0b0..No tiny non-zero result is detected.
 *  0b1..A tiny non-zero result is detected.
 */
#define MAU_RES_STATUS_RES2_UF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_UF_SHIFT)) & MAU_RES_STATUS_RES2_UF_MASK)

#define MAU_RES_STATUS_RES2_OF_MASK              (0x40000U)
#define MAU_RES_STATUS_RES2_OF_SHIFT             (18U)
/*! RES2_OF - RES2 IEEE Overflow Flag
 *  0b0..The result format's largest finite number is not exceeded.
 *  0b1..The result format's largest finite number is exceeded.
 */
#define MAU_RES_STATUS_RES2_OF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_OF_SHIFT)) & MAU_RES_STATUS_RES2_OF_MASK)

#define MAU_RES_STATUS_RES2_DZ_MASK              (0x80000U)
#define MAU_RES_STATUS_RES2_DZ_SHIFT             (19U)
/*! RES2_DZ - RES2 IEEE Divide by Zero Flag
 *  0b0..No exact infinite result is defined for an operation on finite operands.
 *  0b1..An exact infinite result is defined for an operation on finite operands.
 */
#define MAU_RES_STATUS_RES2_DZ(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_DZ_SHIFT)) & MAU_RES_STATUS_RES2_DZ_MASK)

#define MAU_RES_STATUS_RES2_NV_MASK              (0x100000U)
#define MAU_RES_STATUS_RES2_NV_SHIFT             (20U)
/*! RES2_NV - RES2 IEEE Invalid Flag
 *  0b0..There is usefully definable result.
 *  0b1..There is no usefully definable result.
 */
#define MAU_RES_STATUS_RES2_NV(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_NV_SHIFT)) & MAU_RES_STATUS_RES2_NV_MASK)

#define MAU_RES_STATUS_RES2_ERR_MASK             (0x200000U)
#define MAU_RES_STATUS_RES2_ERR_SHIFT            (21U)
/*! RES2_ERR - RES2 Indirect Operation Error Flag
 *  0b0..No invalid indirect operation is detected.
 *  0b1..An invalid indirect operation error is detected.
 */
#define MAU_RES_STATUS_RES2_ERR(x)               (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_ERR_SHIFT)) & MAU_RES_STATUS_RES2_ERR_MASK)

#define MAU_RES_STATUS_RES2_OVWR_MASK            (0x400000U)
#define MAU_RES_STATUS_RES2_OVWR_SHIFT           (22U)
/*! RES2_OVWR - RES2 Overwrite Flag
 *  0b0..The value of RES2 has been read.
 *  0b1..The value of RES2 has not been read yet and is overwritten by a new MAUWRAP result.
 */
#define MAU_RES_STATUS_RES2_OVWR(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_OVWR_SHIFT)) & MAU_RES_STATUS_RES2_OVWR_MASK)

#define MAU_RES_STATUS_RES2_FULL_MASK            (0x800000U)
#define MAU_RES_STATUS_RES2_FULL_SHIFT           (23U)
/*! RES2_FULL - RES2 Full Flag
 *  0b0..RES2 has not updated and cannot be read.
 *  0b1..RES2 has updated and can be read.
 */
#define MAU_RES_STATUS_RES2_FULL(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES2_FULL_SHIFT)) & MAU_RES_STATUS_RES2_FULL_MASK)

#define MAU_RES_STATUS_RES3_NX_MASK              (0x1000000U)
#define MAU_RES_STATUS_RES3_NX_SHIFT             (24U)
/*! RES3_NX - RES3 IEEE Inexact Flag
 *  0b0..The result is not rounded.
 *  0b1..The result is rounded, and as a result some digits lost.
 */
#define MAU_RES_STATUS_RES3_NX(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_NX_SHIFT)) & MAU_RES_STATUS_RES3_NX_MASK)

#define MAU_RES_STATUS_RES3_UF_MASK              (0x2000000U)
#define MAU_RES_STATUS_RES3_UF_SHIFT             (25U)
/*! RES3_UF - RES3 IEEE Underflow Flag
 *  0b0..No tiny non-zero result is detected.
 *  0b1..A tiny non-zero result is detected.
 */
#define MAU_RES_STATUS_RES3_UF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_UF_SHIFT)) & MAU_RES_STATUS_RES3_UF_MASK)

#define MAU_RES_STATUS_RES3_OF_MASK              (0x4000000U)
#define MAU_RES_STATUS_RES3_OF_SHIFT             (26U)
/*! RES3_OF - RES3 IEEE Overflow Flag
 *  0b0..The result format's largest finite number is not exceeded.
 *  0b1..The result format's largest finite number is exceeded.
 */
#define MAU_RES_STATUS_RES3_OF(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_OF_SHIFT)) & MAU_RES_STATUS_RES3_OF_MASK)

#define MAU_RES_STATUS_RES3_DZ_MASK              (0x8000000U)
#define MAU_RES_STATUS_RES3_DZ_SHIFT             (27U)
/*! RES3_DZ - RES3 IEEE Divide by Zero Flag
 *  0b0..No exact infinite result is defined for an operation on finite operands.
 *  0b1..An exact infinite result is defined for an operation on finite operands.
 */
#define MAU_RES_STATUS_RES3_DZ(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_DZ_SHIFT)) & MAU_RES_STATUS_RES3_DZ_MASK)

#define MAU_RES_STATUS_RES3_NV_MASK              (0x10000000U)
#define MAU_RES_STATUS_RES3_NV_SHIFT             (28U)
/*! RES3_NV - RES3 IEEE Invalid Flag
 *  0b0..There is usefully definable result.
 *  0b1..There is no usefully definable result.
 */
#define MAU_RES_STATUS_RES3_NV(x)                (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_NV_SHIFT)) & MAU_RES_STATUS_RES3_NV_MASK)

#define MAU_RES_STATUS_RES3_ERR_MASK             (0x20000000U)
#define MAU_RES_STATUS_RES3_ERR_SHIFT            (29U)
/*! RES3_ERR - RES3 Indirect Operation Error Flag
 *  0b0..No invalid indirect operation is detected.
 *  0b1..An invalid indirect operation error is detected.
 */
#define MAU_RES_STATUS_RES3_ERR(x)               (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_ERR_SHIFT)) & MAU_RES_STATUS_RES3_ERR_MASK)

#define MAU_RES_STATUS_RES3_OVWR_MASK            (0x40000000U)
#define MAU_RES_STATUS_RES3_OVWR_SHIFT           (30U)
/*! RES3_OVWR - RES3 Overwrite Flag
 *  0b0..The value of RES3 has been read.
 *  0b1..The value of RES3 has not been read yet and is overwritten by a new MAUWRAP result.
 */
#define MAU_RES_STATUS_RES3_OVWR(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_OVWR_SHIFT)) & MAU_RES_STATUS_RES3_OVWR_MASK)

#define MAU_RES_STATUS_RES3_FULL_MASK            (0x80000000U)
#define MAU_RES_STATUS_RES3_FULL_SHIFT           (31U)
/*! RES3_FULL - RES3 Full Flag
 *  0b0..RES3 has not updated and cannot be read.
 *  0b1..RES3 has updated and can be read.
 */
#define MAU_RES_STATUS_RES3_FULL(x)              (((uint32_t)(((uint32_t)(x)) << MAU_RES_STATUS_RES3_FULL_SHIFT)) & MAU_RES_STATUS_RES3_FULL_MASK)
/*! @} */

/*! @name RES0 - Result Register 0 */
/*! @{ */

#define MAU_RES0_MAU_RES0_MASK                   (0xFFFFFFFFU)
#define MAU_RES0_MAU_RES0_SHIFT                  (0U)
/*! MAU_RES0 - MAUWRAP Result Register 0 */
#define MAU_RES0_MAU_RES0(x)                     (((uint32_t)(((uint32_t)(x)) << MAU_RES0_MAU_RES0_SHIFT)) & MAU_RES0_MAU_RES0_MASK)
/*! @} */

/*! @name RES1 - Result Register 1 */
/*! @{ */

#define MAU_RES1_MAU_RES1_MASK                   (0xFFFFFFFFU)
#define MAU_RES1_MAU_RES1_SHIFT                  (0U)
/*! MAU_RES1 - MAUWRAP Result Register 1 */
#define MAU_RES1_MAU_RES1(x)                     (((uint32_t)(((uint32_t)(x)) << MAU_RES1_MAU_RES1_SHIFT)) & MAU_RES1_MAU_RES1_MASK)
/*! @} */

/*! @name RES2 - Result Register 2 */
/*! @{ */

#define MAU_RES2_MAU_RES2_MASK                   (0xFFFFFFFFU)
#define MAU_RES2_MAU_RES2_SHIFT                  (0U)
/*! MAU_RES2 - MAUWRAP Result Register 2 */
#define MAU_RES2_MAU_RES2(x)                     (((uint32_t)(((uint32_t)(x)) << MAU_RES2_MAU_RES2_SHIFT)) & MAU_RES2_MAU_RES2_MASK)
/*! @} */

/*! @name RES3 - Result Register 3 */
/*! @{ */

#define MAU_RES3_MAU_RES3_MASK                   (0xFFFFFFFFU)
#define MAU_RES3_MAU_RES3_SHIFT                  (0U)
/*! MAU_RES3 - MAUWRAP Result Register 3 */
#define MAU_RES3_MAU_RES3(x)                     (((uint32_t)(((uint32_t)(x)) << MAU_RES3_MAU_RES3_SHIFT)) & MAU_RES3_MAU_RES3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MAU_Register_Masks */


/*!
 * @}
 */ /* end of group MAU_Peripheral_Access_Layer */


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


#endif  /* PERI_MAU_H_ */

