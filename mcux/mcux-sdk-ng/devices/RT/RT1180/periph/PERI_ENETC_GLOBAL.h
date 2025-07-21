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
**         CMSIS Peripheral Access Layer for ENETC_GLOBAL
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
 * @file PERI_ENETC_GLOBAL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ENETC_GLOBAL
 *
 * CMSIS Peripheral Access Layer for ENETC_GLOBAL
 */

#if !defined(PERI_ENETC_GLOBAL_H_)
#define PERI_ENETC_GLOBAL_H_                     /**< Symbol preventing repeated inclusion */

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
   -- ENETC_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_GLOBAL_Peripheral_Access_Layer ENETC_GLOBAL Peripheral Access Layer
 * @{
 */

/** ENETC_GLOBAL - Size of Registers Arrays */
#define ENETC_GLOBAL_PCE_SL_COUNT                 1u
#define ENETC_GLOBAL_HTA_LOOP_COUNT               1u
#define ENETC_GLOBAL_ARRAY_NUM_RC_COUNT           1u
#define ENETC_GLOBAL_G_BOOT_COUNT                 2u

/** ENETC_GLOBAL - Register Layout Typedef */
typedef struct {
  __I  uint32_t SMCAPR;                            /**< Shared memory capability register, offset: 0x0 */
  __I  uint32_t SMDTR;                             /**< Shared memory depletion threshold register, offset: 0x4 */
  __I  uint32_t SMACR;                             /**< Shared memory available count register, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t SMCLWMR;                           /**< Shared memory count low watermark register, offset: 0x10 */
  __I  uint32_t SMBUCR;                            /**< Shared memory buffer unassigned count register, offset: 0x14 */
  __I  uint32_t SMBUCHWMR;                         /**< Shared memory buffer unassigned count high watermark register, offset: 0x18 */
  __I  uint32_t SMLCR;                             /**< Shared memory loss count register, offset: 0x1C */
  __I  uint32_t HBTCAPR;                           /**< Hash bucket table capability register, offset: 0x20 */
  __I  uint32_t HBTOR0;                            /**< Hash bucket table operational register 0, offset: 0x24 */
       uint8_t RESERVED_1[4];
  __I  uint32_t HBTOR2;                            /**< Hash bucket table operational register 2, offset: 0x2C */
       uint8_t RESERVED_2[16];
  __I  uint32_t SMERBCAPR;                         /**< Shared memory ENETC receive buffer capability register, offset: 0x40 */
  __I  uint32_t SMERBOR0;                          /**< Shared memory ENETC receive buffer operational register 0, offset: 0x44 */
  __I  uint32_t SMERBOR1;                          /**< Shared memory ENETC receive buffer operational 1, offset: 0x48 */
       uint8_t RESERVED_3[180];
  struct {                                         /* offset: 0x100, array step: 0x8 */
    __I  uint32_t PCEOR;                             /**< PCE 0 operational register, array offset: 0x100, array step: 0x8 */
    __I  uint32_t RFEOR;                             /**< Replication Forwarding Engine 0 operational register, array offset: 0x104, array step: 0x8 */
  } PCE_SL[ENETC_GLOBAL_PCE_SL_COUNT];
       uint8_t RESERVED_4[92];
  __I  uint32_t NETCCLKR;                          /**< NETC clock register, offset: 0x164 */
       uint8_t RESERVED_5[152];
  struct {                                         /* offset: 0x200, array step: 0x28 */
    __I  uint32_t HTACAPR;                           /**< HTA 0 capability register, array offset: 0x200, array step: 0x28 */
    __I  uint32_t HTARFCOR;                          /**< HTA 0 receive frame count operational register, array offset: 0x204, array step: 0x28 */
    __I  uint32_t HTAHPBCOR;                         /**< HTA 0 high priority byte count operational register, array offset: 0x208, array step: 0x28 */
    __I  uint32_t HTALPBCOR;                         /**< HTA 0 low priority byte count operational register, array offset: 0x20C, array step: 0x28 */
         uint8_t RESERVED_0[20];
    __I  uint32_t HTATFCOR;                          /**< HTA 0 transmit frame count operational register, array offset: 0x224, array step: 0x28 */
  } HTA_LOOP[ENETC_GLOBAL_HTA_LOOP_COUNT];
       uint8_t RESERVED_6[216];
  struct {                                         /* offset: 0x300, array step: 0x10 */
    __IO uint32_t RCSBRLAR;                          /**< Root complex 0 system bus read latency average register, array offset: 0x300, array step: 0x10 */
    __I  uint32_t RCSBRLHWMR;                        /**< Root complex 0 system bus read latency high watermark register, array offset: 0x304, array step: 0x10 */
    __IO uint32_t RCSBWLAR;                          /**< Root complex 0 system bus write latency average register, array offset: 0x308, array step: 0x10 */
    __I  uint32_t RCSBWLHWMR;                        /**< Root complex 0 system bus write latency high watermark register, array offset: 0x30C, array step: 0x10 */
  } ARRAY_NUM_RC[ENETC_GLOBAL_ARRAY_NUM_RC_COUNT];
       uint8_t RESERVED_7[2280];
  __I  uint32_t IPBRR0;                            /**< IP block revision register 0, offset: 0xBF8 */
  __I  uint32_t IPBRR1;                            /**< IP block revision register 1, offset: 0xBFC */
       uint8_t RESERVED_8[256];
  __I  uint32_t FBLPR[ENETC_GLOBAL_G_BOOT_COUNT];  /**< Function boot loader parameter register 0..Function boot loader parameter register 1, array offset: 0xD00, array step: 0x4 */
       uint8_t RESERVED_9[280];
  union {                                          /* offset: 0xE20 */
    struct {                                         /* offset: 0xE20 */
      __IO uint32_t EMDIOUFSBECR;                      /**< EMDIO uncorrectable fatal system bus error configuration register, offset: 0xE20, available only on: EMDIO_GLOBAL (missing on ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL, TMR0_GLOBAL) */
      __IO uint32_t EMDIOUFSBESR;                      /**< EMDIO uncorrectable fatal system bus error status register, offset: 0xE24, available only on: EMDIO_GLOBAL (missing on ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL, TMR0_GLOBAL) */
    } EMDIO;
    struct {                                         /* offset: 0xE20 */
      __IO uint32_t TUFSBECR;                          /**< Timer uncorrectable fatal system bus error configuration register, offset: 0xE20, available only on: TMR0_GLOBAL (missing on EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL) */
      __IO uint32_t TUFSBESR;                          /**< Timer uncorrectable fatal system bus error status register, offset: 0xE24, available only on: TMR0_GLOBAL (missing on EMDIO_GLOBAL, ENETC0_GLOBAL, ENETC1_GLOBAL, SW0_GLOBAL) */
    } TIMER;
  };
} ENETC_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- ENETC_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENETC_GLOBAL_Register_Masks ENETC_GLOBAL Register Masks
 * @{
 */

/*! @name SMCAPR - Shared memory capability register */
/*! @{ */

#define ENETC_GLOBAL_SMCAPR_NUM_WORDS_MASK       (0xFFFFFFU)
#define ENETC_GLOBAL_SMCAPR_NUM_WORDS_SHIFT      (0U)
#define ENETC_GLOBAL_SMCAPR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMCAPR_NUM_WORDS_SHIFT)) & ENETC_GLOBAL_SMCAPR_NUM_WORDS_MASK)
/*! @} */

/*! @name SMDTR - Shared memory depletion threshold register */
/*! @{ */

#define ENETC_GLOBAL_SMDTR_THRESH_MASK           (0xFFFFFFU)
#define ENETC_GLOBAL_SMDTR_THRESH_SHIFT          (0U)
#define ENETC_GLOBAL_SMDTR_THRESH(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMDTR_THRESH_SHIFT)) & ENETC_GLOBAL_SMDTR_THRESH_MASK)
/*! @} */

/*! @name SMACR - Shared memory available count register */
/*! @{ */

#define ENETC_GLOBAL_SMACR_COUNT_MASK            (0xFFFFFFU)
#define ENETC_GLOBAL_SMACR_COUNT_SHIFT           (0U)
#define ENETC_GLOBAL_SMACR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMACR_COUNT_SHIFT)) & ENETC_GLOBAL_SMACR_COUNT_MASK)
/*! @} */

/*! @name SMCLWMR - Shared memory count low watermark register */
/*! @{ */

#define ENETC_GLOBAL_SMCLWMR_WATERMARK_MASK      (0xFFFFFFU)
#define ENETC_GLOBAL_SMCLWMR_WATERMARK_SHIFT     (0U)
#define ENETC_GLOBAL_SMCLWMR_WATERMARK(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMCLWMR_WATERMARK_SHIFT)) & ENETC_GLOBAL_SMCLWMR_WATERMARK_MASK)
/*! @} */

/*! @name SMBUCR - Shared memory buffer unassigned count register */
/*! @{ */

#define ENETC_GLOBAL_SMBUCR_COUNT_MASK           (0xFFFFFFU)
#define ENETC_GLOBAL_SMBUCR_COUNT_SHIFT          (0U)
#define ENETC_GLOBAL_SMBUCR_COUNT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMBUCR_COUNT_SHIFT)) & ENETC_GLOBAL_SMBUCR_COUNT_MASK)
/*! @} */

/*! @name SMBUCHWMR - Shared memory buffer unassigned count high watermark register */
/*! @{ */

#define ENETC_GLOBAL_SMBUCHWMR_WATERMARK_MASK    (0xFFFFFFU)
#define ENETC_GLOBAL_SMBUCHWMR_WATERMARK_SHIFT   (0U)
#define ENETC_GLOBAL_SMBUCHWMR_WATERMARK(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMBUCHWMR_WATERMARK_SHIFT)) & ENETC_GLOBAL_SMBUCHWMR_WATERMARK_MASK)
/*! @} */

/*! @name SMLCR - Shared memory loss count register */
/*! @{ */

#define ENETC_GLOBAL_SMLCR_COUNT_MASK            (0xFFFFFFU)
#define ENETC_GLOBAL_SMLCR_COUNT_SHIFT           (0U)
#define ENETC_GLOBAL_SMLCR_COUNT(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMLCR_COUNT_SHIFT)) & ENETC_GLOBAL_SMLCR_COUNT_MASK)

#define ENETC_GLOBAL_SMLCR_IFLC_MASK             (0x40000000U)
#define ENETC_GLOBAL_SMLCR_IFLC_SHIFT            (30U)
#define ENETC_GLOBAL_SMLCR_IFLC(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMLCR_IFLC_SHIFT)) & ENETC_GLOBAL_SMLCR_IFLC_MASK)

#define ENETC_GLOBAL_SMLCR_IFDC_MASK             (0x80000000U)
#define ENETC_GLOBAL_SMLCR_IFDC_SHIFT            (31U)
#define ENETC_GLOBAL_SMLCR_IFDC(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMLCR_IFDC_SHIFT)) & ENETC_GLOBAL_SMLCR_IFDC_MASK)
/*! @} */

/*! @name HBTCAPR - Hash bucket table capability register */
/*! @{ */

#define ENETC_GLOBAL_HBTCAPR_NUM_ENTRIES_MASK    (0xFFFFU)
#define ENETC_GLOBAL_HBTCAPR_NUM_ENTRIES_SHIFT   (0U)
#define ENETC_GLOBAL_HBTCAPR_NUM_ENTRIES(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTCAPR_NUM_ENTRIES_SHIFT)) & ENETC_GLOBAL_HBTCAPR_NUM_ENTRIES_MASK)

#define ENETC_GLOBAL_HBTCAPR_MAX_COL_MASK        (0x7000000U)
#define ENETC_GLOBAL_HBTCAPR_MAX_COL_SHIFT       (24U)
#define ENETC_GLOBAL_HBTCAPR_MAX_COL(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTCAPR_MAX_COL_SHIFT)) & ENETC_GLOBAL_HBTCAPR_MAX_COL_MASK)

#define ENETC_GLOBAL_HBTCAPR_MAX_VISITS_MASK     (0xF0000000U)
#define ENETC_GLOBAL_HBTCAPR_MAX_VISITS_SHIFT    (28U)
#define ENETC_GLOBAL_HBTCAPR_MAX_VISITS(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTCAPR_MAX_VISITS_SHIFT)) & ENETC_GLOBAL_HBTCAPR_MAX_VISITS_MASK)
/*! @} */

/*! @name HBTOR0 - Hash bucket table operational register 0 */
/*! @{ */

#define ENETC_GLOBAL_HBTOR0_NUM_ENTRIES_MASK     (0xFFFFU)
#define ENETC_GLOBAL_HBTOR0_NUM_ENTRIES_SHIFT    (0U)
#define ENETC_GLOBAL_HBTOR0_NUM_ENTRIES(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTOR0_NUM_ENTRIES_SHIFT)) & ENETC_GLOBAL_HBTOR0_NUM_ENTRIES_MASK)

#define ENETC_GLOBAL_HBTOR0_HWM_ENTRIES_MASK     (0xFFFF0000U)
#define ENETC_GLOBAL_HBTOR0_HWM_ENTRIES_SHIFT    (16U)
#define ENETC_GLOBAL_HBTOR0_HWM_ENTRIES(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTOR0_HWM_ENTRIES_SHIFT)) & ENETC_GLOBAL_HBTOR0_HWM_ENTRIES_MASK)
/*! @} */

/*! @name HBTOR2 - Hash bucket table operational register 2 */
/*! @{ */

#define ENETC_GLOBAL_HBTOR2_RUN_AVG_FRACT_MASK   (0xFFU)
#define ENETC_GLOBAL_HBTOR2_RUN_AVG_FRACT_SHIFT  (0U)
#define ENETC_GLOBAL_HBTOR2_RUN_AVG_FRACT(x)     (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTOR2_RUN_AVG_FRACT_SHIFT)) & ENETC_GLOBAL_HBTOR2_RUN_AVG_FRACT_MASK)

#define ENETC_GLOBAL_HBTOR2_RUN_AVG_INT_MASK     (0xFF00U)
#define ENETC_GLOBAL_HBTOR2_RUN_AVG_INT_SHIFT    (8U)
#define ENETC_GLOBAL_HBTOR2_RUN_AVG_INT(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTOR2_RUN_AVG_INT_SHIFT)) & ENETC_GLOBAL_HBTOR2_RUN_AVG_INT_MASK)

#define ENETC_GLOBAL_HBTOR2_HWM_COL_MASK         (0xF0000U)
#define ENETC_GLOBAL_HBTOR2_HWM_COL_SHIFT        (16U)
#define ENETC_GLOBAL_HBTOR2_HWM_COL(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HBTOR2_HWM_COL_SHIFT)) & ENETC_GLOBAL_HBTOR2_HWM_COL_MASK)
/*! @} */

/*! @name SMERBCAPR - Shared memory ENETC receive buffer capability register */
/*! @{ */

#define ENETC_GLOBAL_SMERBCAPR_THRESH_MASK       (0xFFFFFFU)
#define ENETC_GLOBAL_SMERBCAPR_THRESH_SHIFT      (0U)
#define ENETC_GLOBAL_SMERBCAPR_THRESH(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMERBCAPR_THRESH_SHIFT)) & ENETC_GLOBAL_SMERBCAPR_THRESH_MASK)

#define ENETC_GLOBAL_SMERBCAPR_WORD_SIZE_MASK    (0x30000000U)
#define ENETC_GLOBAL_SMERBCAPR_WORD_SIZE_SHIFT   (28U)
#define ENETC_GLOBAL_SMERBCAPR_WORD_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMERBCAPR_WORD_SIZE_SHIFT)) & ENETC_GLOBAL_SMERBCAPR_WORD_SIZE_MASK)

#define ENETC_GLOBAL_SMERBCAPR_MLOC_MASK         (0xC0000000U)
#define ENETC_GLOBAL_SMERBCAPR_MLOC_SHIFT        (30U)
#define ENETC_GLOBAL_SMERBCAPR_MLOC(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMERBCAPR_MLOC_SHIFT)) & ENETC_GLOBAL_SMERBCAPR_MLOC_MASK)
/*! @} */

/*! @name SMERBOR0 - Shared memory ENETC receive buffer operational register 0 */
/*! @{ */

#define ENETC_GLOBAL_SMERBOR0_AMOUNT_MASK        (0xFFFFFFU)
#define ENETC_GLOBAL_SMERBOR0_AMOUNT_SHIFT       (0U)
#define ENETC_GLOBAL_SMERBOR0_AMOUNT(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMERBOR0_AMOUNT_SHIFT)) & ENETC_GLOBAL_SMERBOR0_AMOUNT_MASK)
/*! @} */

/*! @name SMERBOR1 - Shared memory ENETC receive buffer operational 1 */
/*! @{ */

#define ENETC_GLOBAL_SMERBOR1_WATERMARK_MASK     (0xFFFFFFU)
#define ENETC_GLOBAL_SMERBOR1_WATERMARK_SHIFT    (0U)
#define ENETC_GLOBAL_SMERBOR1_WATERMARK(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_SMERBOR1_WATERMARK_SHIFT)) & ENETC_GLOBAL_SMERBOR1_WATERMARK_MASK)
/*! @} */

/*! @name PCEOR - PCE 0 operational register */
/*! @{ */

#define ENETC_GLOBAL_PCEOR_NUM_FRAMES_MASK       (0x3FU)
#define ENETC_GLOBAL_PCEOR_NUM_FRAMES_SHIFT      (0U)
#define ENETC_GLOBAL_PCEOR_NUM_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_PCEOR_NUM_FRAMES_SHIFT)) & ENETC_GLOBAL_PCEOR_NUM_FRAMES_MASK)

#define ENETC_GLOBAL_PCEOR_HWM_FRAMES_MASK       (0x3F00U)
#define ENETC_GLOBAL_PCEOR_HWM_FRAMES_SHIFT      (8U)
#define ENETC_GLOBAL_PCEOR_HWM_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_PCEOR_HWM_FRAMES_SHIFT)) & ENETC_GLOBAL_PCEOR_HWM_FRAMES_MASK)

#define ENETC_GLOBAL_PCEOR_MAX_FRAMES_MASK       (0x3F0000U)
#define ENETC_GLOBAL_PCEOR_MAX_FRAMES_SHIFT      (16U)
#define ENETC_GLOBAL_PCEOR_MAX_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_PCEOR_MAX_FRAMES_SHIFT)) & ENETC_GLOBAL_PCEOR_MAX_FRAMES_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_PCEOR */
#define ENETC_GLOBAL_PCEOR_COUNT                 (1U)

/*! @name RFEOR - Replication Forwarding Engine 0 operational register */
/*! @{ */

#define ENETC_GLOBAL_RFEOR_NUM_FRAMES_MASK       (0x3FU)
#define ENETC_GLOBAL_RFEOR_NUM_FRAMES_SHIFT      (0U)
#define ENETC_GLOBAL_RFEOR_NUM_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RFEOR_NUM_FRAMES_SHIFT)) & ENETC_GLOBAL_RFEOR_NUM_FRAMES_MASK)

#define ENETC_GLOBAL_RFEOR_HWM_FRAMES_MASK       (0x3F00U)
#define ENETC_GLOBAL_RFEOR_HWM_FRAMES_SHIFT      (8U)
#define ENETC_GLOBAL_RFEOR_HWM_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RFEOR_HWM_FRAMES_SHIFT)) & ENETC_GLOBAL_RFEOR_HWM_FRAMES_MASK)

#define ENETC_GLOBAL_RFEOR_MAX_FRAMES_MASK       (0x3F0000U)
#define ENETC_GLOBAL_RFEOR_MAX_FRAMES_SHIFT      (16U)
#define ENETC_GLOBAL_RFEOR_MAX_FRAMES(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RFEOR_MAX_FRAMES_SHIFT)) & ENETC_GLOBAL_RFEOR_MAX_FRAMES_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_RFEOR */
#define ENETC_GLOBAL_RFEOR_COUNT                 (1U)

/*! @name NETCCLKR - NETC clock register */
/*! @{ */

#define ENETC_GLOBAL_NETCCLKR_FREQ_MASK          (0x7FFU)
#define ENETC_GLOBAL_NETCCLKR_FREQ_SHIFT         (0U)
/*! FREQ - Frequency */
#define ENETC_GLOBAL_NETCCLKR_FREQ(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_NETCCLKR_FREQ_SHIFT)) & ENETC_GLOBAL_NETCCLKR_FREQ_MASK)
/*! @} */

/*! @name HTACAPR - HTA 0 capability register */
/*! @{ */

#define ENETC_GLOBAL_HTACAPR_MAX_RX_FRAMES_MASK  (0xFFU)
#define ENETC_GLOBAL_HTACAPR_MAX_RX_FRAMES_SHIFT (0U)
#define ENETC_GLOBAL_HTACAPR_MAX_RX_FRAMES(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTACAPR_MAX_RX_FRAMES_SHIFT)) & ENETC_GLOBAL_HTACAPR_MAX_RX_FRAMES_MASK)

#define ENETC_GLOBAL_HTACAPR_MAX_TX_FRAMES_MASK  (0xFF00U)
#define ENETC_GLOBAL_HTACAPR_MAX_TX_FRAMES_SHIFT (8U)
#define ENETC_GLOBAL_HTACAPR_MAX_TX_FRAMES(x)    (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTACAPR_MAX_TX_FRAMES_SHIFT)) & ENETC_GLOBAL_HTACAPR_MAX_TX_FRAMES_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_HTACAPR */
#define ENETC_GLOBAL_HTACAPR_COUNT               (1U)

/*! @name HTARFCOR - HTA 0 receive frame count operational register */
/*! @{ */

#define ENETC_GLOBAL_HTARFCOR_HP_COUNT_MASK      (0xFFU)
#define ENETC_GLOBAL_HTARFCOR_HP_COUNT_SHIFT     (0U)
#define ENETC_GLOBAL_HTARFCOR_HP_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTARFCOR_HP_COUNT_SHIFT)) & ENETC_GLOBAL_HTARFCOR_HP_COUNT_MASK)

#define ENETC_GLOBAL_HTARFCOR_HP_HWM_MASK        (0xFF00U)
#define ENETC_GLOBAL_HTARFCOR_HP_HWM_SHIFT       (8U)
#define ENETC_GLOBAL_HTARFCOR_HP_HWM(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTARFCOR_HP_HWM_SHIFT)) & ENETC_GLOBAL_HTARFCOR_HP_HWM_MASK)

#define ENETC_GLOBAL_HTARFCOR_LP_COUNT_MASK      (0xFF0000U)
#define ENETC_GLOBAL_HTARFCOR_LP_COUNT_SHIFT     (16U)
#define ENETC_GLOBAL_HTARFCOR_LP_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTARFCOR_LP_COUNT_SHIFT)) & ENETC_GLOBAL_HTARFCOR_LP_COUNT_MASK)

#define ENETC_GLOBAL_HTARFCOR_LP_HWM_MASK        (0xFF000000U)
#define ENETC_GLOBAL_HTARFCOR_LP_HWM_SHIFT       (24U)
#define ENETC_GLOBAL_HTARFCOR_LP_HWM(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTARFCOR_LP_HWM_SHIFT)) & ENETC_GLOBAL_HTARFCOR_LP_HWM_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_HTARFCOR */
#define ENETC_GLOBAL_HTARFCOR_COUNT              (1U)

/*! @name HTAHPBCOR - HTA 0 high priority byte count operational register */
/*! @{ */

#define ENETC_GLOBAL_HTAHPBCOR_HP_COUNT_MASK     (0xFFFFU)
#define ENETC_GLOBAL_HTAHPBCOR_HP_COUNT_SHIFT    (0U)
#define ENETC_GLOBAL_HTAHPBCOR_HP_COUNT(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTAHPBCOR_HP_COUNT_SHIFT)) & ENETC_GLOBAL_HTAHPBCOR_HP_COUNT_MASK)

#define ENETC_GLOBAL_HTAHPBCOR_HWM_MASK          (0xFFFF0000U)
#define ENETC_GLOBAL_HTAHPBCOR_HWM_SHIFT         (16U)
#define ENETC_GLOBAL_HTAHPBCOR_HWM(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTAHPBCOR_HWM_SHIFT)) & ENETC_GLOBAL_HTAHPBCOR_HWM_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_HTAHPBCOR */
#define ENETC_GLOBAL_HTAHPBCOR_COUNT             (1U)

/*! @name HTALPBCOR - HTA 0 low priority byte count operational register */
/*! @{ */

#define ENETC_GLOBAL_HTALPBCOR_LP_COUNT_MASK     (0xFFFFU)
#define ENETC_GLOBAL_HTALPBCOR_LP_COUNT_SHIFT    (0U)
#define ENETC_GLOBAL_HTALPBCOR_LP_COUNT(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTALPBCOR_LP_COUNT_SHIFT)) & ENETC_GLOBAL_HTALPBCOR_LP_COUNT_MASK)

#define ENETC_GLOBAL_HTALPBCOR_HWM_MASK          (0xFFFF0000U)
#define ENETC_GLOBAL_HTALPBCOR_HWM_SHIFT         (16U)
#define ENETC_GLOBAL_HTALPBCOR_HWM(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTALPBCOR_HWM_SHIFT)) & ENETC_GLOBAL_HTALPBCOR_HWM_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_HTALPBCOR */
#define ENETC_GLOBAL_HTALPBCOR_COUNT             (1U)

/*! @name HTATFCOR - HTA 0 transmit frame count operational register */
/*! @{ */

#define ENETC_GLOBAL_HTATFCOR_HP_COUNT_MASK      (0xFFU)
#define ENETC_GLOBAL_HTATFCOR_HP_COUNT_SHIFT     (0U)
#define ENETC_GLOBAL_HTATFCOR_HP_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTATFCOR_HP_COUNT_SHIFT)) & ENETC_GLOBAL_HTATFCOR_HP_COUNT_MASK)

#define ENETC_GLOBAL_HTATFCOR_HP_HWM_MASK        (0xFF00U)
#define ENETC_GLOBAL_HTATFCOR_HP_HWM_SHIFT       (8U)
#define ENETC_GLOBAL_HTATFCOR_HP_HWM(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTATFCOR_HP_HWM_SHIFT)) & ENETC_GLOBAL_HTATFCOR_HP_HWM_MASK)

#define ENETC_GLOBAL_HTATFCOR_LP_COUNT_MASK      (0xFF0000U)
#define ENETC_GLOBAL_HTATFCOR_LP_COUNT_SHIFT     (16U)
#define ENETC_GLOBAL_HTATFCOR_LP_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTATFCOR_LP_COUNT_SHIFT)) & ENETC_GLOBAL_HTATFCOR_LP_COUNT_MASK)

#define ENETC_GLOBAL_HTATFCOR_LP_HWM_MASK        (0xFF000000U)
#define ENETC_GLOBAL_HTATFCOR_LP_HWM_SHIFT       (24U)
#define ENETC_GLOBAL_HTATFCOR_LP_HWM(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_HTATFCOR_LP_HWM_SHIFT)) & ENETC_GLOBAL_HTATFCOR_LP_HWM_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_HTATFCOR */
#define ENETC_GLOBAL_HTATFCOR_COUNT              (1U)

/*! @name RCSBRLAR - Root complex 0 system bus read latency average register */
/*! @{ */

#define ENETC_GLOBAL_RCSBRLAR_FRACT_MASK         (0xFFU)
#define ENETC_GLOBAL_RCSBRLAR_FRACT_SHIFT        (0U)
#define ENETC_GLOBAL_RCSBRLAR_FRACT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBRLAR_FRACT_SHIFT)) & ENETC_GLOBAL_RCSBRLAR_FRACT_MASK)

#define ENETC_GLOBAL_RCSBRLAR_INT_MASK           (0xFFF00U)
#define ENETC_GLOBAL_RCSBRLAR_INT_SHIFT          (8U)
#define ENETC_GLOBAL_RCSBRLAR_INT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBRLAR_INT_SHIFT)) & ENETC_GLOBAL_RCSBRLAR_INT_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_RCSBRLAR */
#define ENETC_GLOBAL_RCSBRLAR_COUNT              (1U)

/*! @name RCSBRLHWMR - Root complex 0 system bus read latency high watermark register */
/*! @{ */

#define ENETC_GLOBAL_RCSBRLHWMR_FRACT_MASK       (0xFFU)
#define ENETC_GLOBAL_RCSBRLHWMR_FRACT_SHIFT      (0U)
#define ENETC_GLOBAL_RCSBRLHWMR_FRACT(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBRLHWMR_FRACT_SHIFT)) & ENETC_GLOBAL_RCSBRLHWMR_FRACT_MASK)

#define ENETC_GLOBAL_RCSBRLHWMR_INT_MASK         (0xFFF00U)
#define ENETC_GLOBAL_RCSBRLHWMR_INT_SHIFT        (8U)
#define ENETC_GLOBAL_RCSBRLHWMR_INT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBRLHWMR_INT_SHIFT)) & ENETC_GLOBAL_RCSBRLHWMR_INT_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_RCSBRLHWMR */
#define ENETC_GLOBAL_RCSBRLHWMR_COUNT            (1U)

/*! @name RCSBWLAR - Root complex 0 system bus write latency average register */
/*! @{ */

#define ENETC_GLOBAL_RCSBWLAR_FRACT_MASK         (0xFFU)
#define ENETC_GLOBAL_RCSBWLAR_FRACT_SHIFT        (0U)
#define ENETC_GLOBAL_RCSBWLAR_FRACT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBWLAR_FRACT_SHIFT)) & ENETC_GLOBAL_RCSBWLAR_FRACT_MASK)

#define ENETC_GLOBAL_RCSBWLAR_INT_MASK           (0xFFF00U)
#define ENETC_GLOBAL_RCSBWLAR_INT_SHIFT          (8U)
#define ENETC_GLOBAL_RCSBWLAR_INT(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBWLAR_INT_SHIFT)) & ENETC_GLOBAL_RCSBWLAR_INT_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_RCSBWLAR */
#define ENETC_GLOBAL_RCSBWLAR_COUNT              (1U)

/*! @name RCSBWLHWMR - Root complex 0 system bus write latency high watermark register */
/*! @{ */

#define ENETC_GLOBAL_RCSBWLHWMR_FRACT_MASK       (0xFFU)
#define ENETC_GLOBAL_RCSBWLHWMR_FRACT_SHIFT      (0U)
#define ENETC_GLOBAL_RCSBWLHWMR_FRACT(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBWLHWMR_FRACT_SHIFT)) & ENETC_GLOBAL_RCSBWLHWMR_FRACT_MASK)

#define ENETC_GLOBAL_RCSBWLHWMR_INT_MASK         (0xFFF00U)
#define ENETC_GLOBAL_RCSBWLHWMR_INT_SHIFT        (8U)
#define ENETC_GLOBAL_RCSBWLHWMR_INT(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_RCSBWLHWMR_INT_SHIFT)) & ENETC_GLOBAL_RCSBWLHWMR_INT_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_RCSBWLHWMR */
#define ENETC_GLOBAL_RCSBWLHWMR_COUNT            (1U)

/*! @name IPBRR0 - IP block revision register 0 */
/*! @{ */

#define ENETC_GLOBAL_IPBRR0_IP_MN_MASK           (0xFFU)
#define ENETC_GLOBAL_IPBRR0_IP_MN_SHIFT          (0U)
#define ENETC_GLOBAL_IPBRR0_IP_MN(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR0_IP_MN_SHIFT)) & ENETC_GLOBAL_IPBRR0_IP_MN_MASK)

#define ENETC_GLOBAL_IPBRR0_IP_MJ_MASK           (0xFF00U)
#define ENETC_GLOBAL_IPBRR0_IP_MJ_SHIFT          (8U)
#define ENETC_GLOBAL_IPBRR0_IP_MJ(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR0_IP_MJ_SHIFT)) & ENETC_GLOBAL_IPBRR0_IP_MJ_MASK)

#define ENETC_GLOBAL_IPBRR0_IP_ID_MASK           (0xFFFF0000U)
#define ENETC_GLOBAL_IPBRR0_IP_ID_SHIFT          (16U)
#define ENETC_GLOBAL_IPBRR0_IP_ID(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR0_IP_ID_SHIFT)) & ENETC_GLOBAL_IPBRR0_IP_ID_MASK)
/*! @} */

/*! @name IPBRR1 - IP block revision register 1 */
/*! @{ */

#define ENETC_GLOBAL_IPBRR1_IP_CFG_MASK          (0xFFU)
#define ENETC_GLOBAL_IPBRR1_IP_CFG_SHIFT         (0U)
#define ENETC_GLOBAL_IPBRR1_IP_CFG(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR1_IP_CFG_SHIFT)) & ENETC_GLOBAL_IPBRR1_IP_CFG_MASK)

#define ENETC_GLOBAL_IPBRR1_IP_MNT_MASK          (0xFF00U)
#define ENETC_GLOBAL_IPBRR1_IP_MNT_SHIFT         (8U)
#define ENETC_GLOBAL_IPBRR1_IP_MNT(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR1_IP_MNT_SHIFT)) & ENETC_GLOBAL_IPBRR1_IP_MNT_MASK)

#define ENETC_GLOBAL_IPBRR1_IP_INT_MASK          (0xFF0000U)
#define ENETC_GLOBAL_IPBRR1_IP_INT_SHIFT         (16U)
#define ENETC_GLOBAL_IPBRR1_IP_INT(x)            (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_IPBRR1_IP_INT_SHIFT)) & ENETC_GLOBAL_IPBRR1_IP_INT_MASK)
/*! @} */

/*! @name FBLPR - Function boot loader parameter register 0..Function boot loader parameter register 1 */
/*! @{ */

#define ENETC_GLOBAL_FBLPR_PARAM_VAL_MASK        (0xFFFFFFFFU)
#define ENETC_GLOBAL_FBLPR_PARAM_VAL_SHIFT       (0U)
#define ENETC_GLOBAL_FBLPR_PARAM_VAL(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_FBLPR_PARAM_VAL_SHIFT)) & ENETC_GLOBAL_FBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of ENETC_GLOBAL_FBLPR */
#define ENETC_GLOBAL_FBLPR_COUNT                 (2U)

/*! @name EMDIOUFSBECR - EMDIO uncorrectable fatal system bus error configuration register */
/*! @{ */

#define ENETC_GLOBAL_EMDIOUFSBECR_RD_MASK        (0x80000000U)
#define ENETC_GLOBAL_EMDIOUFSBECR_RD_SHIFT       (31U)
/*! RD - Report disable */
#define ENETC_GLOBAL_EMDIOUFSBECR_RD(x)          (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_EMDIOUFSBECR_RD_SHIFT)) & ENETC_GLOBAL_EMDIOUFSBECR_RD_MASK)
/*! @} */

/*! @name EMDIOUFSBESR - EMDIO uncorrectable fatal system bus error status register */
/*! @{ */

#define ENETC_GLOBAL_EMDIOUFSBESR_SB_ID_MASK     (0xFU)
#define ENETC_GLOBAL_EMDIOUFSBESR_SB_ID_SHIFT    (0U)
/*! SB_ID - System Bus ID */
#define ENETC_GLOBAL_EMDIOUFSBESR_SB_ID(x)       (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_EMDIOUFSBESR_SB_ID_SHIFT)) & ENETC_GLOBAL_EMDIOUFSBESR_SB_ID_MASK)

#define ENETC_GLOBAL_EMDIOUFSBESR_M_MASK         (0x40000000U)
#define ENETC_GLOBAL_EMDIOUFSBESR_M_SHIFT        (30U)
/*! M - Multiple */
#define ENETC_GLOBAL_EMDIOUFSBESR_M(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_EMDIOUFSBESR_M_SHIFT)) & ENETC_GLOBAL_EMDIOUFSBESR_M_MASK)

#define ENETC_GLOBAL_EMDIOUFSBESR_SBE_MASK       (0x80000000U)
#define ENETC_GLOBAL_EMDIOUFSBESR_SBE_SHIFT      (31U)
/*! SBE - System bus error */
#define ENETC_GLOBAL_EMDIOUFSBESR_SBE(x)         (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_EMDIOUFSBESR_SBE_SHIFT)) & ENETC_GLOBAL_EMDIOUFSBESR_SBE_MASK)
/*! @} */

/*! @name TUFSBECR - Timer uncorrectable fatal system bus error configuration register */
/*! @{ */

#define ENETC_GLOBAL_TUFSBECR_RD_MASK            (0x80000000U)
#define ENETC_GLOBAL_TUFSBECR_RD_SHIFT           (31U)
/*! RD - Report disable */
#define ENETC_GLOBAL_TUFSBECR_RD(x)              (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_TUFSBECR_RD_SHIFT)) & ENETC_GLOBAL_TUFSBECR_RD_MASK)
/*! @} */

/*! @name TUFSBESR - Timer uncorrectable fatal system bus error status register */
/*! @{ */

#define ENETC_GLOBAL_TUFSBESR_SB_ID_MASK         (0xFU)
#define ENETC_GLOBAL_TUFSBESR_SB_ID_SHIFT        (0U)
/*! SB_ID - System Bus ID */
#define ENETC_GLOBAL_TUFSBESR_SB_ID(x)           (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_TUFSBESR_SB_ID_SHIFT)) & ENETC_GLOBAL_TUFSBESR_SB_ID_MASK)

#define ENETC_GLOBAL_TUFSBESR_M_MASK             (0x40000000U)
#define ENETC_GLOBAL_TUFSBESR_M_SHIFT            (30U)
/*! M - Multiple */
#define ENETC_GLOBAL_TUFSBESR_M(x)               (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_TUFSBESR_M_SHIFT)) & ENETC_GLOBAL_TUFSBESR_M_MASK)

#define ENETC_GLOBAL_TUFSBESR_SBE_MASK           (0x80000000U)
#define ENETC_GLOBAL_TUFSBESR_SBE_SHIFT          (31U)
/*! SBE - System bus error */
#define ENETC_GLOBAL_TUFSBESR_SBE(x)             (((uint32_t)(((uint32_t)(x)) << ENETC_GLOBAL_TUFSBESR_SBE_SHIFT)) & ENETC_GLOBAL_TUFSBESR_SBE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENETC_GLOBAL_Register_Masks */


/*!
 * @}
 */ /* end of group ENETC_GLOBAL_Peripheral_Access_Layer */


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


#endif  /* PERI_ENETC_GLOBAL_H_ */

