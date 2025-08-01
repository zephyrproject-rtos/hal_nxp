/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FRO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FRO.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FRO
 *
 * CMSIS Peripheral Access Layer for FRO
 */

#if !defined(PERI_FRO_H_)
#define PERI_FRO_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- FRO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_Peripheral_Access_Layer FRO Peripheral Access Layer
 * @{
 */

/** FRO - Register Layout Typedef */
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
       uint8_t RESERVED_1[16];
  struct {                                         /* offset: 0x240 */
    __IO uint32_t RW;                                /**< FRO Trim, offset: 0x240 */
    __IO uint32_t SET;                               /**< FRO Trim, offset: 0x244 */
    __IO uint32_t CLR;                               /**< FRO Trim, offset: 0x248 */
    __IO uint32_t TOG;                               /**< FRO Trim, offset: 0x24C */
  } FROTRIM;
  struct {                                         /* offset: 0x250 */
    __IO uint32_t RW;                                /**< FRO Expected Trim Count, offset: 0x250 */
    __IO uint32_t SET;                               /**< FRO Expected Trim Count, offset: 0x254 */
    __IO uint32_t CLR;                               /**< FRO Expected Trim Count, offset: 0x258 */
    __IO uint32_t TOG;                               /**< FRO Expected Trim Count, offset: 0x25C */
  } TEXPCNT;
  struct {                                         /* offset: 0x260 */
    __I  uint32_t RW;                                /**< FRO Auto Tune Trim, offset: 0x260 */
    __I  uint32_t SET;                               /**< FRO Auto Tune Trim, offset: 0x264 */
    __I  uint32_t CLR;                               /**< FRO Auto Tune Trim, offset: 0x268 */
    __I  uint32_t TOG;                               /**< FRO Auto Tune Trim, offset: 0x26C */
  } AUTOTRIM;
  struct {                                         /* offset: 0x270 */
    __I  uint32_t RW;                                /**< FRO Trim Count, offset: 0x270 */
    __I  uint32_t SET;                               /**< FRO Trim Count, offset: 0x274 */
    __I  uint32_t CLR;                               /**< FRO Trim Count, offset: 0x278 */
    __I  uint32_t TOG;                               /**< FRO Trim Count, offset: 0x27C */
  } TRIMCNT;
} FRO_Type;

/* ----------------------------------------------------------------------------
   -- FRO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FRO_Register_Masks FRO Register Masks
 * @{
 */

/*! @name CSR - Control Status */
/*! @{ */

#define FRO_CSR_FROEN_MASK                       (0x1U)
#define FRO_CSR_FROEN_SHIFT                      (0U)
/*! FROEN - FRO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_FROEN(x)                         (((uint32_t)(((uint32_t)(x)) << FRO_CSR_FROEN_SHIFT)) & FRO_CSR_FROEN_MASK)

#define FRO_CSR_TREN_MASK                        (0x10U)
#define FRO_CSR_TREN_SHIFT                       (4U)
/*! TREN - FRO Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_TREN(x)                          (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TREN_SHIFT)) & FRO_CSR_TREN_MASK)

#define FRO_CSR_TRUPEN_MASK                      (0x20U)
#define FRO_CSR_TRUPEN_SHIFT                     (5U)
/*! TRUPEN - FRO Autotrim Update Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_TRUPEN(x)                        (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRUPEN_SHIFT)) & FRO_CSR_TRUPEN_MASK)

#define FRO_CSR_COARSEN_MASK                     (0x40U)
#define FRO_CSR_COARSEN_SHIFT                    (6U)
/*! COARSEN - Coarse Trim Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CSR_COARSEN(x)                       (((uint32_t)(((uint32_t)(x)) << FRO_CSR_COARSEN_SHIFT)) & FRO_CSR_COARSEN_MASK)

#define FRO_CSR_TUNEONCE_MASK                    (0x80U)
#define FRO_CSR_TUNEONCE_SHIFT                   (7U)
/*! TUNEONCE - Tune Once Control */
#define FRO_CSR_TUNEONCE(x)                      (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNEONCE_SHIFT)) & FRO_CSR_TUNEONCE_MASK)

#define FRO_CSR_CLKGATE_MASK                     (0x1F00U)
#define FRO_CSR_CLKGATE_SHIFT                    (8U)
/*! CLKGATE - FRO Clock Enable
 *  0b0xxxx..Disables FRO divider 8 clock
 *  0b1xxxx..Enables FRO divider 8 clock
 *  0bx0xxx..Disables FRO divider 6 clock
 *  0bx1xxx..Enables FRO divider 6 clock
 *  0bxx0xx..Disables FRO divider 3 clock
 *  0bxx1xx..Enables FRO divider 3 clock
 *  0bxxx0x..Disables FRO divider 2 clock
 *  0bxxx1x..Enables FRO divider 2 clock
 *  0bxxxx0..Disables FRO divider 1 clock
 *  0bxxxx1..Enables FRO divider 1 clock
 */
#define FRO_CSR_CLKGATE(x)                       (((uint32_t)(((uint32_t)(x)) << FRO_CSR_CLKGATE_SHIFT)) & FRO_CSR_CLKGATE_MASK)

#define FRO_CSR_LOL_ERR_MASK                     (0x10000U)
#define FRO_CSR_LOL_ERR_SHIFT                    (16U)
/*! LOL_ERR - Loss-of-Lock Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_LOL_ERR(x)                       (((uint32_t)(((uint32_t)(x)) << FRO_CSR_LOL_ERR_SHIFT)) & FRO_CSR_LOL_ERR_MASK)

#define FRO_CSR_TUNE_ERR_MASK                    (0x20000U)
#define FRO_CSR_TUNE_ERR_SHIFT                   (17U)
/*! TUNE_ERR - Tune Error Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_TUNE_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNE_ERR_SHIFT)) & FRO_CSR_TUNE_ERR_MASK)

#define FRO_CSR_TRUPREQ_MASK                     (0x40000U)
#define FRO_CSR_TRUPREQ_SHIFT                    (18U)
/*! TRUPREQ - Trim Update Request Flag
 *  0b0..Not detected
 *  0b1..Detected
 */
#define FRO_CSR_TRUPREQ(x)                       (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRUPREQ_SHIFT)) & FRO_CSR_TRUPREQ_MASK)

#define FRO_CSR_TRIM_LOCK_MASK                   (0x1000000U)
#define FRO_CSR_TRIM_LOCK_SHIFT                  (24U)
/*! TRIM_LOCK - FRO Trim Lock Flag
 *  0b0..Not locked
 *  0b1..Locked
 */
#define FRO_CSR_TRIM_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TRIM_LOCK_SHIFT)) & FRO_CSR_TRIM_LOCK_MASK)

#define FRO_CSR_TUNEONCE_DONE_MASK               (0x2000000U)
#define FRO_CSR_TUNEONCE_DONE_SHIFT              (25U)
/*! TUNEONCE_DONE - FRO Tune Once Done Flag
 *  0b0..Not complete
 *  0b1..Complete
 */
#define FRO_CSR_TUNEONCE_DONE(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_CSR_TUNEONCE_DONE_SHIFT)) & FRO_CSR_TUNEONCE_DONE_MASK)
/*! @} */

/*! @name CNFG1 - Trim Configuration 1 */
/*! @{ */

#define FRO_CNFG1_REFDIV_MASK                    (0x7FFU)
#define FRO_CNFG1_REFDIV_SHIFT                   (0U)
/*! REFDIV - OSC Reference Clock Divider */
#define FRO_CNFG1_REFDIV(x)                      (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_REFDIV_SHIFT)) & FRO_CNFG1_REFDIV_MASK)

#define FRO_CNFG1_FSTUPEN_MASK                   (0x800U)
#define FRO_CNFG1_FSTUPEN_SHIFT                  (11U)
/*! FSTUPEN - FRO Fast Startup Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_FSTUPEN(x)                     (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_FSTUPEN_SHIFT)) & FRO_CNFG1_FSTUPEN_MASK)

#define FRO_CNFG1_LOL_ERR_IE_MASK                (0x1000U)
#define FRO_CNFG1_LOL_ERR_IE_SHIFT               (12U)
/*! LOL_ERR_IE - Loss-of-Lock Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_LOL_ERR_IE(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_LOL_ERR_IE_SHIFT)) & FRO_CNFG1_LOL_ERR_IE_MASK)

#define FRO_CNFG1_TUNE_ERR_IE_MASK               (0x2000U)
#define FRO_CNFG1_TUNE_ERR_IE_SHIFT              (13U)
/*! TUNE_ERR_IE - Tune Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_TUNE_ERR_IE(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_TUNE_ERR_IE_SHIFT)) & FRO_CNFG1_TUNE_ERR_IE_MASK)

#define FRO_CNFG1_TRUPREQ_IE_MASK                (0x4000U)
#define FRO_CNFG1_TRUPREQ_IE_SHIFT               (14U)
/*! TRUPREQ_IE - Trim Update Request Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define FRO_CNFG1_TRUPREQ_IE(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_TRUPREQ_IE_SHIFT)) & FRO_CNFG1_TRUPREQ_IE_MASK)

#define FRO_CNFG1_RFCLKCNT_MASK                  (0xFFFF0000U)
#define FRO_CNFG1_RFCLKCNT_SHIFT                 (16U)
/*! RFCLKCNT - Reference Clock Counter */
#define FRO_CNFG1_RFCLKCNT(x)                    (((uint32_t)(((uint32_t)(x)) << FRO_CNFG1_RFCLKCNT_SHIFT)) & FRO_CNFG1_RFCLKCNT_MASK)
/*! @} */

/*! @name CNFG2 - Trim Configuration 2 */
/*! @{ */

#define FRO_CNFG2_TRIM2_DELAY_MASK               (0xFFFU)
#define FRO_CNFG2_TRIM2_DELAY_SHIFT              (0U)
/*! TRIM2_DELAY - Trim 2 Delay Register */
#define FRO_CNFG2_TRIM2_DELAY(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_CNFG2_TRIM2_DELAY_SHIFT)) & FRO_CNFG2_TRIM2_DELAY_MASK)

#define FRO_CNFG2_TRIM1_DELAY_MASK               (0xFFF0000U)
#define FRO_CNFG2_TRIM1_DELAY_SHIFT              (16U)
/*! TRIM1_DELAY - Trim 1 Delay Register */
#define FRO_CNFG2_TRIM1_DELAY(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_CNFG2_TRIM1_DELAY_SHIFT)) & FRO_CNFG2_TRIM1_DELAY_MASK)
/*! @} */

/*! @name FROTRIM - FRO Trim */
/*! @{ */

#define FRO_FROTRIM_FINE_TRIM_MASK               (0x7FU)
#define FRO_FROTRIM_FINE_TRIM_SHIFT              (0U)
/*! FINE_TRIM - Fine Trim */
#define FRO_FROTRIM_FINE_TRIM(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_FINE_TRIM_SHIFT)) & FRO_FROTRIM_FINE_TRIM_MASK)

#define FRO_FROTRIM_COARSE_TRIM_MASK             (0xF80U)
#define FRO_FROTRIM_COARSE_TRIM_SHIFT            (7U)
/*! COARSE_TRIM - Coarse Trim */
#define FRO_FROTRIM_COARSE_TRIM(x)               (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_COARSE_TRIM_SHIFT)) & FRO_FROTRIM_COARSE_TRIM_MASK)

#define FRO_FROTRIM_TRIMTEMP_MASK                (0x3F0000U)
#define FRO_FROTRIM_TRIMTEMP_SHIFT               (16U)
/*! TRIMTEMP - Trim Temperature */
#define FRO_FROTRIM_TRIMTEMP(x)                  (((uint32_t)(((uint32_t)(x)) << FRO_FROTRIM_TRIMTEMP_SHIFT)) & FRO_FROTRIM_TRIMTEMP_MASK)
/*! @} */

/*! @name TEXPCNT - FRO Expected Trim Count */
/*! @{ */

#define FRO_TEXPCNT_TEXPCNT_MASK                 (0xFFFFU)
#define FRO_TEXPCNT_TEXPCNT_SHIFT                (0U)
/*! TEXPCNT - Trim Expected Count */
#define FRO_TEXPCNT_TEXPCNT(x)                   (((uint32_t)(((uint32_t)(x)) << FRO_TEXPCNT_TEXPCNT_SHIFT)) & FRO_TEXPCNT_TEXPCNT_MASK)

#define FRO_TEXPCNT_TEXPCNT_RANGE_MASK           (0xFF0000U)
#define FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT          (16U)
/*! TEXPCNT_RANGE - Trim Expected Count Range */
#define FRO_TEXPCNT_TEXPCNT_RANGE(x)             (((uint32_t)(((uint32_t)(x)) << FRO_TEXPCNT_TEXPCNT_RANGE_SHIFT)) & FRO_TEXPCNT_TEXPCNT_RANGE_MASK)
/*! @} */

/*! @name AUTOTRIM - FRO Auto Tune Trim */
/*! @{ */

#define FRO_AUTOTRIM_AUTOTRIM_MASK               (0xFFFU)
#define FRO_AUTOTRIM_AUTOTRIM_SHIFT              (0U)
/*! AUTOTRIM - Auto Tune Trim Value */
#define FRO_AUTOTRIM_AUTOTRIM(x)                 (((uint32_t)(((uint32_t)(x)) << FRO_AUTOTRIM_AUTOTRIM_SHIFT)) & FRO_AUTOTRIM_AUTOTRIM_MASK)
/*! @} */

/*! @name TRIMCNT - FRO Trim Count */
/*! @{ */

#define FRO_TRIMCNT_TRIMCNT_MASK                 (0xFFFFFFFFU)
#define FRO_TRIMCNT_TRIMCNT_SHIFT                (0U)
/*! TRIMCNT - Trim Count */
#define FRO_TRIMCNT_TRIMCNT(x)                   (((uint32_t)(((uint32_t)(x)) << FRO_TRIMCNT_TRIMCNT_SHIFT)) & FRO_TRIMCNT_TRIMCNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FRO_Register_Masks */


/*!
 * @}
 */ /* end of group FRO_Peripheral_Access_Layer */


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


#endif  /* PERI_FRO_H_ */

