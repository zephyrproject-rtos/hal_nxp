/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ANALOG_FRO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ANALOG_FRO.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ANALOG_FRO
 *
 * CMSIS Peripheral Access Layer for ANALOG_FRO
 */

#if !defined(ANALOG_FRO_H_)
#define ANALOG_FRO_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ANALOG_FRO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_FRO_Peripheral_Access_Layer ANALOG_FRO Peripheral Access Layer
 * @{
 */

/** ANALOG_FRO - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Control Status, offset: 0x200 */
    __IO uint32_t SET;                               /**< Control Status, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Control Status, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Control Status, offset: 0x20C */
  } CSR;
  struct {                                         /* offset: 0x210 */
    __IO uint32_t RW;                                /**< Trim Configuration 1, offset: 0x210 */
    __IO uint32_t SET;                               /**< Trim Configuration 1, offset: 0x214 */
    __IO uint32_t CLR;                               /**< Trim Configuration 1, offset: 0x218 */
    __IO uint32_t TOG;                               /**< Trim Configuration 1, offset: 0x21C */
  } CNFG1;
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Trim Configuration 2, offset: 0x220 */
    __IO uint32_t SET;                               /**< Trim Configuration 2, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Trim Configuration 2, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Trim Configuration 2, offset: 0x22C */
  } CNFG2;
  struct {                                         /* offset: 0x230 */
    __IO uint32_t RW;                                /**< FRO Trim, offset: 0x230 */
    __IO uint32_t SET;                               /**< FRO Trim, offset: 0x234 */
    __IO uint32_t CLR;                               /**< FRO Trim, offset: 0x238 */
    __IO uint32_t TOG;                               /**< FRO Trim, offset: 0x23C */
  } FROTRIM;
  struct {                                         /* offset: 0x240 */
    __IO uint32_t RW;                                /**< FRO Expected Trim Count, offset: 0x240 */
    __IO uint32_t SET;                               /**< FRO Expected Trim Count, offset: 0x244 */
    __IO uint32_t CLR;                               /**< FRO Expected Trim Count, offset: 0x248 */
    __IO uint32_t TOG;                               /**< FRO Expected Trim Count, offset: 0x24C */
  } TEXPCNT;
  struct {                                         /* offset: 0x250 */
    __I  uint32_t RW;                                /**< FRO Auto Tune Trim, offset: 0x250 */
    __I  uint32_t SET;                               /**< FRO Auto Tune Trim, offset: 0x254 */
    __I  uint32_t CLR;                               /**< FRO Auto Tune Trim, offset: 0x258 */
    __I  uint32_t TOG;                               /**< FRO Auto Tune Trim, offset: 0x25C */
  } AUTOTRIM;
  struct {                                         /* offset: 0x260 */
    __I  uint32_t RW;                                /**< FRO Trim Count, offset: 0x260 */
    __I  uint32_t SET;                               /**< FRO Trim Count, offset: 0x264 */
    __I  uint32_t CLR;                               /**< FRO Trim Count, offset: 0x268 */
    __I  uint32_t TOG;                               /**< FRO Trim Count, offset: 0x26C */
  } TRIMCNT;
} ANALOG_FRO_Type;

/* ----------------------------------------------------------------------------
   -- ANALOG_FRO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_FRO_Register_Masks ANALOG_FRO Register Masks
 * @{
 */

/*! @name CSR - Control Status */
/*! @{ */

#define ANALOG_FRO_CSR_FROEN_MASK                (0x1U)
#define ANALOG_FRO_CSR_FROEN_SHIFT               (0U)
/*! FROEN - FRO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CSR_FROEN(x)                  (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_FROEN_SHIFT)) & ANALOG_FRO_CSR_FROEN_MASK)

#define ANALOG_FRO_CSR_SMODE_MASK                (0x2U)
#define ANALOG_FRO_CSR_SMODE_SHIFT               (1U)
/*! SMODE - Suspend Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CSR_SMODE(x)                  (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_SMODE_SHIFT)) & ANALOG_FRO_CSR_SMODE_MASK)

#define ANALOG_FRO_CSR_TREN_MASK                 (0x10U)
#define ANALOG_FRO_CSR_TREN_SHIFT                (4U)
/*! TREN - FRO Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CSR_TREN(x)                   (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TREN_SHIFT)) & ANALOG_FRO_CSR_TREN_MASK)

#define ANALOG_FRO_CSR_TRUPEN_MASK               (0x20U)
#define ANALOG_FRO_CSR_TRUPEN_SHIFT              (5U)
/*! TRUPEN - FRO Autotrim Update Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CSR_TRUPEN(x)                 (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TRUPEN_SHIFT)) & ANALOG_FRO_CSR_TRUPEN_MASK)

#define ANALOG_FRO_CSR_COARSEN_MASK              (0x40U)
#define ANALOG_FRO_CSR_COARSEN_SHIFT             (6U)
/*! COARSEN - Coarse Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CSR_COARSEN(x)                (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_COARSEN_SHIFT)) & ANALOG_FRO_CSR_COARSEN_MASK)

#define ANALOG_FRO_CSR_TUNEONCE_MASK             (0x80U)
#define ANALOG_FRO_CSR_TUNEONCE_SHIFT            (7U)
/*! TUNEONCE - Tune Once Control */
#define ANALOG_FRO_CSR_TUNEONCE(x)               (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TUNEONCE_SHIFT)) & ANALOG_FRO_CSR_TUNEONCE_MASK)

#define ANALOG_FRO_CSR_CLKGATE_MASK              (0x1F00U)
#define ANALOG_FRO_CSR_CLKGATE_SHIFT             (8U)
/*! CLKGATE - FRO Clock Enable
 *  0bxxxx0..Disables FRO divider 1 clock
 *  0bxxxx1..Enables FRO divider 1 clock
 *  0bxxx0x..Disables FRO divider 2 clock
 *  0bxxx1x..Enables FRO divider 2 clock
 *  0bxx0xx..Disables FRO divider 3 clock
 *  0bxx1xx..Enables FRO divider 3 clock
 *  0bx0xxx..Disables FRO divider 6 clock
 *  0bx1xxx..Enables FRO divider 6 clock
 *  0b0xxxx..Disables FRO divider 10 clock
 *  0b1xxxx..Enables FRO divider 10 clock
 */
#define ANALOG_FRO_CSR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_CLKGATE_SHIFT)) & ANALOG_FRO_CSR_CLKGATE_MASK)

#define ANALOG_FRO_CSR_LOL_ERR_MASK              (0x10000U)
#define ANALOG_FRO_CSR_LOL_ERR_SHIFT             (16U)
/*! LOL_ERR - Loss-of-Lock Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define ANALOG_FRO_CSR_LOL_ERR(x)                (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_LOL_ERR_SHIFT)) & ANALOG_FRO_CSR_LOL_ERR_MASK)

#define ANALOG_FRO_CSR_TUNE_ERR_MASK             (0x20000U)
#define ANALOG_FRO_CSR_TUNE_ERR_SHIFT            (17U)
/*! TUNE_ERR - Tune Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define ANALOG_FRO_CSR_TUNE_ERR(x)               (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TUNE_ERR_SHIFT)) & ANALOG_FRO_CSR_TUNE_ERR_MASK)

#define ANALOG_FRO_CSR_TRUPREQ_MASK              (0x40000U)
#define ANALOG_FRO_CSR_TRUPREQ_SHIFT             (18U)
/*! TRUPREQ - Trim Update Request Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define ANALOG_FRO_CSR_TRUPREQ(x)                (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TRUPREQ_SHIFT)) & ANALOG_FRO_CSR_TRUPREQ_MASK)

#define ANALOG_FRO_CSR_TRIM_LOCK_MASK            (0x1000000U)
#define ANALOG_FRO_CSR_TRIM_LOCK_SHIFT           (24U)
/*! TRIM_LOCK - FRO Trim Lock Flag
 *  0b0..Not locked
 *  0b1..Locked
 */
#define ANALOG_FRO_CSR_TRIM_LOCK(x)              (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TRIM_LOCK_SHIFT)) & ANALOG_FRO_CSR_TRIM_LOCK_MASK)

#define ANALOG_FRO_CSR_TUNEONCE_DONE_MASK        (0x2000000U)
#define ANALOG_FRO_CSR_TUNEONCE_DONE_SHIFT       (25U)
/*! TUNEONCE_DONE - FRO Tune Once Done Flag
 *  0b0..Not complete
 *  0b1..Complete
 */
#define ANALOG_FRO_CSR_TUNEONCE_DONE(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CSR_TUNEONCE_DONE_SHIFT)) & ANALOG_FRO_CSR_TUNEONCE_DONE_MASK)
/*! @} */

/*! @name CNFG1 - Trim Configuration 1 */
/*! @{ */

#define ANALOG_FRO_CNFG1_REFDIV_MASK             (0x7FFU)
#define ANALOG_FRO_CNFG1_REFDIV_SHIFT            (0U)
/*! REFDIV - OSC Reference Clock Divider */
#define ANALOG_FRO_CNFG1_REFDIV(x)               (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_REFDIV_SHIFT)) & ANALOG_FRO_CNFG1_REFDIV_MASK)

#define ANALOG_FRO_CNFG1_FSTUPEN_MASK            (0x800U)
#define ANALOG_FRO_CNFG1_FSTUPEN_SHIFT           (11U)
/*! FSTUPEN - FRO Fast Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CNFG1_FSTUPEN(x)              (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_FSTUPEN_SHIFT)) & ANALOG_FRO_CNFG1_FSTUPEN_MASK)

#define ANALOG_FRO_CNFG1_LOL_ERR_IE_MASK         (0x1000U)
#define ANALOG_FRO_CNFG1_LOL_ERR_IE_SHIFT        (12U)
/*! LOL_ERR_IE - Loss-of-Lock Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CNFG1_LOL_ERR_IE(x)           (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_LOL_ERR_IE_SHIFT)) & ANALOG_FRO_CNFG1_LOL_ERR_IE_MASK)

#define ANALOG_FRO_CNFG1_TUNE_ERR_IE_MASK        (0x2000U)
#define ANALOG_FRO_CNFG1_TUNE_ERR_IE_SHIFT       (13U)
/*! TUNE_ERR_IE - Tune Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CNFG1_TUNE_ERR_IE(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_TUNE_ERR_IE_SHIFT)) & ANALOG_FRO_CNFG1_TUNE_ERR_IE_MASK)

#define ANALOG_FRO_CNFG1_TRUPREQ_IE_MASK         (0x4000U)
#define ANALOG_FRO_CNFG1_TRUPREQ_IE_SHIFT        (14U)
/*! TRUPREQ_IE - Trim Update Request Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANALOG_FRO_CNFG1_TRUPREQ_IE(x)           (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_TRUPREQ_IE_SHIFT)) & ANALOG_FRO_CNFG1_TRUPREQ_IE_MASK)

#define ANALOG_FRO_CNFG1_RFCLKCNT_MASK           (0xFFFF0000U)
#define ANALOG_FRO_CNFG1_RFCLKCNT_SHIFT          (16U)
/*! RFCLKCNT - Reference Clock Counter */
#define ANALOG_FRO_CNFG1_RFCLKCNT(x)             (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG1_RFCLKCNT_SHIFT)) & ANALOG_FRO_CNFG1_RFCLKCNT_MASK)
/*! @} */

/*! @name CNFG2 - Trim Configuration 2 */
/*! @{ */

#define ANALOG_FRO_CNFG2_FRODIV_MASK             (0x7U)
#define ANALOG_FRO_CNFG2_FRODIV_SHIFT            (0U)
/*! FRODIV - FRO Clock Divider */
#define ANALOG_FRO_CNFG2_FRODIV(x)               (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG2_FRODIV_SHIFT)) & ANALOG_FRO_CNFG2_FRODIV_MASK)

#define ANALOG_FRO_CNFG2_CLKGATE_MASK            (0x10U)
#define ANALOG_FRO_CNFG2_CLKGATE_SHIFT           (4U)
/*! CLKGATE - FRO 8M Clock Gate Enable */
#define ANALOG_FRO_CNFG2_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG2_CLKGATE_SHIFT)) & ANALOG_FRO_CNFG2_CLKGATE_MASK)

#define ANALOG_FRO_CNFG2_TRIM1_DELAY_MASK        (0xFFF0000U)
#define ANALOG_FRO_CNFG2_TRIM1_DELAY_SHIFT       (16U)
/*! TRIM1_DELAY - Trim 1 Delay Register */
#define ANALOG_FRO_CNFG2_TRIM1_DELAY(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_CNFG2_TRIM1_DELAY_SHIFT)) & ANALOG_FRO_CNFG2_TRIM1_DELAY_MASK)
/*! @} */

/*! @name FROTRIM - FRO Trim */
/*! @{ */

#define ANALOG_FRO_FROTRIM_FINE_TRIM_MASK        (0x7FU)
#define ANALOG_FRO_FROTRIM_FINE_TRIM_SHIFT       (0U)
/*! FINE_TRIM - Fine Trim */
#define ANALOG_FRO_FROTRIM_FINE_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_FROTRIM_FINE_TRIM_SHIFT)) & ANALOG_FRO_FROTRIM_FINE_TRIM_MASK)

#define ANALOG_FRO_FROTRIM_COARSE_TRIM_MASK      (0xF80U)
#define ANALOG_FRO_FROTRIM_COARSE_TRIM_SHIFT     (7U)
/*! COARSE_TRIM - Coarse Trim */
#define ANALOG_FRO_FROTRIM_COARSE_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_FROTRIM_COARSE_TRIM_SHIFT)) & ANALOG_FRO_FROTRIM_COARSE_TRIM_MASK)

#define ANALOG_FRO_FROTRIM_TRIMTEMP_MASK         (0x3F0000U)
#define ANALOG_FRO_FROTRIM_TRIMTEMP_SHIFT        (16U)
/*! TRIMTEMP - Trim Temperature */
#define ANALOG_FRO_FROTRIM_TRIMTEMP(x)           (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_FROTRIM_TRIMTEMP_SHIFT)) & ANALOG_FRO_FROTRIM_TRIMTEMP_MASK)
/*! @} */

/*! @name TEXPCNT - FRO Expected Trim Count */
/*! @{ */

#define ANALOG_FRO_TEXPCNT_TEXPCNT_MASK          (0xFFFFU)
#define ANALOG_FRO_TEXPCNT_TEXPCNT_SHIFT         (0U)
/*! TEXPCNT - Trim Expected Count */
#define ANALOG_FRO_TEXPCNT_TEXPCNT(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_TEXPCNT_TEXPCNT_SHIFT)) & ANALOG_FRO_TEXPCNT_TEXPCNT_MASK)

#define ANALOG_FRO_TEXPCNT_TEXPCNT_RANGE_MASK    (0xFF0000U)
#define ANALOG_FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT   (16U)
/*! TEXPCNT_RANGE - Trim Expected Count Range */
#define ANALOG_FRO_TEXPCNT_TEXPCNT_RANGE(x)      (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT)) & ANALOG_FRO_TEXPCNT_TEXPCNT_RANGE_MASK)
/*! @} */

/*! @name AUTOTRIM - FRO Auto Tune Trim */
/*! @{ */

#define ANALOG_FRO_AUTOTRIM_AUTOTRIM_MASK        (0xFFFU)
#define ANALOG_FRO_AUTOTRIM_AUTOTRIM_SHIFT       (0U)
/*! AUTOTRIM - Auto Tune Trim Value */
#define ANALOG_FRO_AUTOTRIM_AUTOTRIM(x)          (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_AUTOTRIM_AUTOTRIM_SHIFT)) & ANALOG_FRO_AUTOTRIM_AUTOTRIM_MASK)
/*! @} */

/*! @name TRIMCNT - FRO Trim Count */
/*! @{ */

#define ANALOG_FRO_TRIMCNT_TRIMCNT_MASK          (0xFFFFFFFFU)
#define ANALOG_FRO_TRIMCNT_TRIMCNT_SHIFT         (0U)
/*! TRIMCNT - Trim Expected Count */
#define ANALOG_FRO_TRIMCNT_TRIMCNT(x)            (((uint32_t)(((uint32_t)(x)) << ANALOG_FRO_TRIMCNT_TRIMCNT_SHIFT)) & ANALOG_FRO_TRIMCNT_TRIMCNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANALOG_FRO_Register_Masks */


/*!
 * @}
 */ /* end of group ANALOG_FRO_Peripheral_Access_Layer */


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


#endif  /* ANALOG_FRO_H_ */

