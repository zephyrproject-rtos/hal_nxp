/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b240823
**
**     Abstract:
**         CMSIS Peripheral Access Layer for POWERQUAD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**
** ###################################################################
*/

/*!
 * @file POWERQUAD.h
 * @version 5.0
 * @date 2023-04-27
 * @brief CMSIS Peripheral Access Layer for POWERQUAD
 *
 * CMSIS Peripheral Access Layer for POWERQUAD
 */

#if !defined(POWERQUAD_H_)
#define POWERQUAD_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- POWERQUAD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERQUAD_Peripheral_Access_Layer POWERQUAD Peripheral Access Layer
 * @{
 */

/** POWERQUAD - Size of Registers Arrays */
#define POWERQUAD_GPREG_COUNT                     16u
#define POWERQUAD_COMPREGS_COUNT                  8u

/** POWERQUAD - Register Layout Typedef */
typedef struct {
  __IO uint32_t OUTBASE;                           /**< Output Base, offset: 0x0 */
  __IO uint32_t OUTFORMAT;                         /**< Output Format, offset: 0x4 */
  __IO uint32_t TMPBASE;                           /**< Temporary Base, offset: 0x8 */
  __IO uint32_t TMPFORMAT;                         /**< Temporary Format, offset: 0xC */
  __IO uint32_t INABASE;                           /**< Input A Base, offset: 0x10 */
  __IO uint32_t INAFORMAT;                         /**< Input A Format, offset: 0x14 */
  __IO uint32_t INBBASE;                           /**< Input B Base, offset: 0x18 */
  __IO uint32_t INBFORMAT;                         /**< Input B Format, offset: 0x1C */
       uint8_t RESERVED_0[224];
  __IO uint32_t CONTROL;                           /**< Control, offset: 0x100 */
  __IO uint32_t LENGTH;                            /**< Length, offset: 0x104 */
  __IO uint32_t CPPRE;                             /**< Coprocessor Pre-scale, offset: 0x108 */
  __IO uint32_t MISC;                              /**< Miscellaneous, offset: 0x10C */
  __IO uint32_t CURSORY;                           /**< Cursory, offset: 0x110 */
       uint8_t RESERVED_1[108];
  __IO uint32_t CORDIC_X;                          /**< Cordic input X, offset: 0x180 */
  __IO uint32_t CORDIC_Y;                          /**< Cordic Input Y, offset: 0x184 */
  __IO uint32_t CORDIC_Z;                          /**< Cordic Input Z, offset: 0x188 */
  __IO uint32_t ERRSTAT;                           /**< Error Status, offset: 0x18C */
  __IO uint32_t INTREN;                            /**< Interrupt Enable, offset: 0x190 */
  __IO uint32_t EVENTEN;                           /**< Event Enable, offset: 0x194 */
  __IO uint32_t INTRSTAT;                          /**< Interrupt Status, offset: 0x198 */
       uint8_t RESERVED_2[100];
  __IO uint32_t GPREG[POWERQUAD_GPREG_COUNT];      /**< General Purpose Register Bank n, array offset: 0x200, array step: 0x4 */
  __IO uint32_t COMPREG[POWERQUAD_COMPREGS_COUNT]; /**< Compute Register Bank n, array offset: 0x240, array step: 0x4 */
} POWERQUAD_Type;

/* ----------------------------------------------------------------------------
   -- POWERQUAD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup POWERQUAD_Register_Masks POWERQUAD Register Masks
 * @{
 */

/*! @name OUTBASE - Output Base */
/*! @{ */

#define POWERQUAD_OUTBASE_OUTBASE_MASK           (0xFFFFFFFFU)
#define POWERQUAD_OUTBASE_OUTBASE_SHIFT          (0U)
/*! OUTBASE - Base address register for the output region */
#define POWERQUAD_OUTBASE_OUTBASE(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_OUTBASE_OUTBASE_SHIFT)) & POWERQUAD_OUTBASE_OUTBASE_MASK)
/*! @} */

/*! @name OUTFORMAT - Output Format */
/*! @{ */

#define POWERQUAD_OUTFORMAT_OUT_FORMATINT_MASK   (0x3U)
#define POWERQUAD_OUTFORMAT_OUT_FORMATINT_SHIFT  (0U)
/*! OUT_FORMATINT - Output Internal Format */
#define POWERQUAD_OUTFORMAT_OUT_FORMATINT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_OUTFORMAT_OUT_FORMATINT_SHIFT)) & POWERQUAD_OUTFORMAT_OUT_FORMATINT_MASK)

#define POWERQUAD_OUTFORMAT_OUT_FORMATEXT_MASK   (0x30U)
#define POWERQUAD_OUTFORMAT_OUT_FORMATEXT_SHIFT  (4U)
/*! OUT_FORMATEXT - Output External Format */
#define POWERQUAD_OUTFORMAT_OUT_FORMATEXT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_OUTFORMAT_OUT_FORMATEXT_SHIFT)) & POWERQUAD_OUTFORMAT_OUT_FORMATEXT_MASK)

#define POWERQUAD_OUTFORMAT_OUT_SCALER_MASK      (0xFF00U)
#define POWERQUAD_OUTFORMAT_OUT_SCALER_SHIFT     (8U)
/*! OUT_SCALER - Output Scaler Value */
#define POWERQUAD_OUTFORMAT_OUT_SCALER(x)        (((uint32_t)(((uint32_t)(x)) << POWERQUAD_OUTFORMAT_OUT_SCALER_SHIFT)) & POWERQUAD_OUTFORMAT_OUT_SCALER_MASK)
/*! @} */

/*! @name TMPBASE - Temporary Base */
/*! @{ */

#define POWERQUAD_TMPBASE_TMPBASE_MASK           (0xFFFFFFFFU)
#define POWERQUAD_TMPBASE_TMPBASE_SHIFT          (0U)
/*! TMPBASE - Base address register for the temporary region */
#define POWERQUAD_TMPBASE_TMPBASE(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_TMPBASE_TMPBASE_SHIFT)) & POWERQUAD_TMPBASE_TMPBASE_MASK)
/*! @} */

/*! @name TMPFORMAT - Temporary Format */
/*! @{ */

#define POWERQUAD_TMPFORMAT_TMP_FORMATINT_MASK   (0x3U)
#define POWERQUAD_TMPFORMAT_TMP_FORMATINT_SHIFT  (0U)
/*! TMP_FORMATINT - Temporary Internal Format */
#define POWERQUAD_TMPFORMAT_TMP_FORMATINT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_TMPFORMAT_TMP_FORMATINT_SHIFT)) & POWERQUAD_TMPFORMAT_TMP_FORMATINT_MASK)

#define POWERQUAD_TMPFORMAT_TMP_FORMATEXT_MASK   (0x30U)
#define POWERQUAD_TMPFORMAT_TMP_FORMATEXT_SHIFT  (4U)
/*! TMP_FORMATEXT - Temporary External Format */
#define POWERQUAD_TMPFORMAT_TMP_FORMATEXT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_TMPFORMAT_TMP_FORMATEXT_SHIFT)) & POWERQUAD_TMPFORMAT_TMP_FORMATEXT_MASK)

#define POWERQUAD_TMPFORMAT_TMP_SCALER_MASK      (0xFF00U)
#define POWERQUAD_TMPFORMAT_TMP_SCALER_SHIFT     (8U)
/*! TMP_SCALER - Temporary Scaler Value */
#define POWERQUAD_TMPFORMAT_TMP_SCALER(x)        (((uint32_t)(((uint32_t)(x)) << POWERQUAD_TMPFORMAT_TMP_SCALER_SHIFT)) & POWERQUAD_TMPFORMAT_TMP_SCALER_MASK)
/*! @} */

/*! @name INABASE - Input A Base */
/*! @{ */

#define POWERQUAD_INABASE_INABASE_MASK           (0xFFFFFFFFU)
#define POWERQUAD_INABASE_INABASE_SHIFT          (0U)
/*! INABASE - Input A Base */
#define POWERQUAD_INABASE_INABASE(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INABASE_INABASE_SHIFT)) & POWERQUAD_INABASE_INABASE_MASK)
/*! @} */

/*! @name INAFORMAT - Input A Format */
/*! @{ */

#define POWERQUAD_INAFORMAT_INA_FORMATINT_MASK   (0x3U)
#define POWERQUAD_INAFORMAT_INA_FORMATINT_SHIFT  (0U)
/*! INA_FORMATINT - Input A Internal Format */
#define POWERQUAD_INAFORMAT_INA_FORMATINT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INAFORMAT_INA_FORMATINT_SHIFT)) & POWERQUAD_INAFORMAT_INA_FORMATINT_MASK)

#define POWERQUAD_INAFORMAT_INA_FORMATEXT_MASK   (0x30U)
#define POWERQUAD_INAFORMAT_INA_FORMATEXT_SHIFT  (4U)
/*! INA_FORMATEXT - Input A External Format */
#define POWERQUAD_INAFORMAT_INA_FORMATEXT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INAFORMAT_INA_FORMATEXT_SHIFT)) & POWERQUAD_INAFORMAT_INA_FORMATEXT_MASK)

#define POWERQUAD_INAFORMAT_INA_SCALER_MASK      (0xFF00U)
#define POWERQUAD_INAFORMAT_INA_SCALER_SHIFT     (8U)
/*! INA_SCALER - Input A Scaler Value */
#define POWERQUAD_INAFORMAT_INA_SCALER(x)        (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INAFORMAT_INA_SCALER_SHIFT)) & POWERQUAD_INAFORMAT_INA_SCALER_MASK)
/*! @} */

/*! @name INBBASE - Input B Base */
/*! @{ */

#define POWERQUAD_INBBASE_INBBASE_MASK           (0xFFFFFFFFU)
#define POWERQUAD_INBBASE_INBBASE_SHIFT          (0U)
/*! INBBASE - Input B Base */
#define POWERQUAD_INBBASE_INBBASE(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INBBASE_INBBASE_SHIFT)) & POWERQUAD_INBBASE_INBBASE_MASK)
/*! @} */

/*! @name INBFORMAT - Input B Format */
/*! @{ */

#define POWERQUAD_INBFORMAT_INB_FORMATINT_MASK   (0x3U)
#define POWERQUAD_INBFORMAT_INB_FORMATINT_SHIFT  (0U)
/*! INB_FORMATINT - Input B Internal Format */
#define POWERQUAD_INBFORMAT_INB_FORMATINT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INBFORMAT_INB_FORMATINT_SHIFT)) & POWERQUAD_INBFORMAT_INB_FORMATINT_MASK)

#define POWERQUAD_INBFORMAT_INB_FORMATEXT_MASK   (0x30U)
#define POWERQUAD_INBFORMAT_INB_FORMATEXT_SHIFT  (4U)
/*! INB_FORMATEXT - Input B External Format */
#define POWERQUAD_INBFORMAT_INB_FORMATEXT(x)     (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INBFORMAT_INB_FORMATEXT_SHIFT)) & POWERQUAD_INBFORMAT_INB_FORMATEXT_MASK)

#define POWERQUAD_INBFORMAT_INB_SCALER_MASK      (0xFF00U)
#define POWERQUAD_INBFORMAT_INB_SCALER_SHIFT     (8U)
/*! INB_SCALER - Input B Scaler Value */
#define POWERQUAD_INBFORMAT_INB_SCALER(x)        (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INBFORMAT_INB_SCALER_SHIFT)) & POWERQUAD_INBFORMAT_INB_SCALER_MASK)
/*! @} */

/*! @name CONTROL - Control */
/*! @{ */

#define POWERQUAD_CONTROL_DECODE_OPCODE_MASK     (0xFU)
#define POWERQUAD_CONTROL_DECODE_OPCODE_SHIFT    (0U)
/*! DECODE_OPCODE - Decode Opcode */
#define POWERQUAD_CONTROL_DECODE_OPCODE(x)       (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CONTROL_DECODE_OPCODE_SHIFT)) & POWERQUAD_CONTROL_DECODE_OPCODE_MASK)

#define POWERQUAD_CONTROL_DECODE_MACHINE_MASK    (0xF0U)
#define POWERQUAD_CONTROL_DECODE_MACHINE_SHIFT   (4U)
/*! DECODE_MACHINE - Decode Machine */
#define POWERQUAD_CONTROL_DECODE_MACHINE(x)      (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CONTROL_DECODE_MACHINE_SHIFT)) & POWERQUAD_CONTROL_DECODE_MACHINE_MASK)

#define POWERQUAD_CONTROL_INST_BUSY_MASK         (0x80000000U)
#define POWERQUAD_CONTROL_INST_BUSY_SHIFT        (31U)
/*! INST_BUSY - Instruction Busy */
#define POWERQUAD_CONTROL_INST_BUSY(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CONTROL_INST_BUSY_SHIFT)) & POWERQUAD_CONTROL_INST_BUSY_MASK)
/*! @} */

/*! @name LENGTH - Length */
/*! @{ */

#define POWERQUAD_LENGTH_INST_LENGTH_MASK        (0xFFFFFFFFU)
#define POWERQUAD_LENGTH_INST_LENGTH_SHIFT       (0U)
/*! INST_LENGTH - Instruction Length */
#define POWERQUAD_LENGTH_INST_LENGTH(x)          (((uint32_t)(((uint32_t)(x)) << POWERQUAD_LENGTH_INST_LENGTH_SHIFT)) & POWERQUAD_LENGTH_INST_LENGTH_MASK)
/*! @} */

/*! @name CPPRE - Coprocessor Pre-scale */
/*! @{ */

#define POWERQUAD_CPPRE_CPPRE_IN_MASK            (0xFFU)
#define POWERQUAD_CPPRE_CPPRE_IN_SHIFT           (0U)
/*! CPPRE_IN - Input */
#define POWERQUAD_CPPRE_CPPRE_IN(x)              (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CPPRE_CPPRE_IN_SHIFT)) & POWERQUAD_CPPRE_CPPRE_IN_MASK)

#define POWERQUAD_CPPRE_CPPRE_OUT_MASK           (0xFF00U)
#define POWERQUAD_CPPRE_CPPRE_OUT_SHIFT          (8U)
/*! CPPRE_OUT - Output */
#define POWERQUAD_CPPRE_CPPRE_OUT(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CPPRE_CPPRE_OUT_SHIFT)) & POWERQUAD_CPPRE_CPPRE_OUT_MASK)

#define POWERQUAD_CPPRE_CPPRE_SAT_MASK           (0x10000U)
#define POWERQUAD_CPPRE_CPPRE_SAT_SHIFT          (16U)
/*! CPPRE_SAT - Saturation
 *  0b0..No saturation
 *  0b1..Forces sub-32 bit saturation
 */
#define POWERQUAD_CPPRE_CPPRE_SAT(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CPPRE_CPPRE_SAT_SHIFT)) & POWERQUAD_CPPRE_CPPRE_SAT_MASK)

#define POWERQUAD_CPPRE_CPPRE_SAT8_MASK          (0x20000U)
#define POWERQUAD_CPPRE_CPPRE_SAT8_SHIFT         (17U)
/*! CPPRE_SAT8 - Saturation 8
 *  0b0..8 bits
 *  0b1..16 bits
 */
#define POWERQUAD_CPPRE_CPPRE_SAT8(x)            (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CPPRE_CPPRE_SAT8_SHIFT)) & POWERQUAD_CPPRE_CPPRE_SAT8_MASK)
/*! @} */

/*! @name MISC - Miscellaneous */
/*! @{ */

#define POWERQUAD_MISC_INST_MISC_MASK            (0xFFFFFFFFU)
#define POWERQUAD_MISC_INST_MISC_SHIFT           (0U)
/*! INST_MISC - For Matrix : Used for scaling factor */
#define POWERQUAD_MISC_INST_MISC(x)              (((uint32_t)(((uint32_t)(x)) << POWERQUAD_MISC_INST_MISC_SHIFT)) & POWERQUAD_MISC_INST_MISC_MASK)
/*! @} */

/*! @name CURSORY - Cursory */
/*! @{ */

#define POWERQUAD_CURSORY_CURSORY_MASK           (0x1U)
#define POWERQUAD_CURSORY_CURSORY_SHIFT          (0U)
/*! CURSORY - Cursory Mode
 *  0b0..Disable Cursory mode
 *  0b1..Enable Cursory Mode
 */
#define POWERQUAD_CURSORY_CURSORY(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CURSORY_CURSORY_SHIFT)) & POWERQUAD_CURSORY_CURSORY_MASK)
/*! @} */

/*! @name CORDIC_X - Cordic input X */
/*! @{ */

#define POWERQUAD_CORDIC_X_CORDIC_X_MASK         (0xFFFFFFFFU)
#define POWERQUAD_CORDIC_X_CORDIC_X_SHIFT        (0U)
/*! CORDIC_X - Cordic Input x */
#define POWERQUAD_CORDIC_X_CORDIC_X(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CORDIC_X_CORDIC_X_SHIFT)) & POWERQUAD_CORDIC_X_CORDIC_X_MASK)
/*! @} */

/*! @name CORDIC_Y - Cordic Input Y */
/*! @{ */

#define POWERQUAD_CORDIC_Y_CORDIC_Y_MASK         (0xFFFFFFFFU)
#define POWERQUAD_CORDIC_Y_CORDIC_Y_SHIFT        (0U)
/*! CORDIC_Y - Cordic Input y */
#define POWERQUAD_CORDIC_Y_CORDIC_Y(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CORDIC_Y_CORDIC_Y_SHIFT)) & POWERQUAD_CORDIC_Y_CORDIC_Y_MASK)
/*! @} */

/*! @name CORDIC_Z - Cordic Input Z */
/*! @{ */

#define POWERQUAD_CORDIC_Z_CORDIC_Z_MASK         (0xFFFFFFFFU)
#define POWERQUAD_CORDIC_Z_CORDIC_Z_SHIFT        (0U)
/*! CORDIC_Z - Cordic Input z */
#define POWERQUAD_CORDIC_Z_CORDIC_Z(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_CORDIC_Z_CORDIC_Z_SHIFT)) & POWERQUAD_CORDIC_Z_CORDIC_Z_MASK)
/*! @} */

/*! @name ERRSTAT - Error Status */
/*! @{ */

#define POWERQUAD_ERRSTAT_OVERFLOW_MASK          (0x1U)
#define POWERQUAD_ERRSTAT_OVERFLOW_SHIFT         (0U)
/*! OVERFLOW - Floating Point Overflow
 *  0b0..No Error
 *  0b1..Error on Floating Point Overflow
 */
#define POWERQUAD_ERRSTAT_OVERFLOW(x)            (((uint32_t)(((uint32_t)(x)) << POWERQUAD_ERRSTAT_OVERFLOW_SHIFT)) & POWERQUAD_ERRSTAT_OVERFLOW_MASK)

#define POWERQUAD_ERRSTAT_NAN_MASK               (0x2U)
#define POWERQUAD_ERRSTAT_NAN_SHIFT              (1U)
/*! NAN - Floating Point NaN
 *  0b0..No Error
 *  0b1..Error on Floating Point NaN
 */
#define POWERQUAD_ERRSTAT_NAN(x)                 (((uint32_t)(((uint32_t)(x)) << POWERQUAD_ERRSTAT_NAN_SHIFT)) & POWERQUAD_ERRSTAT_NAN_MASK)

#define POWERQUAD_ERRSTAT_FIXEDOVERFLOW_MASK     (0x4U)
#define POWERQUAD_ERRSTAT_FIXEDOVERFLOW_SHIFT    (2U)
/*! FIXEDOVERFLOW - Fixed Point Overflow
 *  0b0..No Error
 *  0b1..Error on Fixed Point Overflow
 */
#define POWERQUAD_ERRSTAT_FIXEDOVERFLOW(x)       (((uint32_t)(((uint32_t)(x)) << POWERQUAD_ERRSTAT_FIXEDOVERFLOW_SHIFT)) & POWERQUAD_ERRSTAT_FIXEDOVERFLOW_MASK)

#define POWERQUAD_ERRSTAT_UNDERFLOW_MASK         (0x8U)
#define POWERQUAD_ERRSTAT_UNDERFLOW_SHIFT        (3U)
/*! UNDERFLOW - Underflow
 *  0b0..No Error
 *  0b1..Error on Underflow
 */
#define POWERQUAD_ERRSTAT_UNDERFLOW(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_ERRSTAT_UNDERFLOW_SHIFT)) & POWERQUAD_ERRSTAT_UNDERFLOW_MASK)

#define POWERQUAD_ERRSTAT_BUSERROR_MASK          (0x10U)
#define POWERQUAD_ERRSTAT_BUSERROR_SHIFT         (4U)
/*! BUSERROR - Bus Error
 *  0b0..No Error
 *  0b1..Error on Bus
 */
#define POWERQUAD_ERRSTAT_BUSERROR(x)            (((uint32_t)(((uint32_t)(x)) << POWERQUAD_ERRSTAT_BUSERROR_SHIFT)) & POWERQUAD_ERRSTAT_BUSERROR_MASK)
/*! @} */

/*! @name INTREN - Interrupt Enable */
/*! @{ */

#define POWERQUAD_INTREN_INTR_OFLOW_MASK         (0x1U)
#define POWERQUAD_INTREN_INTR_OFLOW_SHIFT        (0U)
/*! INTR_OFLOW - Interrupt Floating Point Overflow
 *  0b0..Disable
 *  0b1..Enable interrupt on floating point overflow
 */
#define POWERQUAD_INTREN_INTR_OFLOW(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_OFLOW_SHIFT)) & POWERQUAD_INTREN_INTR_OFLOW_MASK)

#define POWERQUAD_INTREN_INTR_NAN_MASK           (0x2U)
#define POWERQUAD_INTREN_INTR_NAN_SHIFT          (1U)
/*! INTR_NAN - Interrupt Floating Point NaN
 *  0b0..Disable
 *  0b1..Enable interrupt on floating point NaN
 */
#define POWERQUAD_INTREN_INTR_NAN(x)             (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_NAN_SHIFT)) & POWERQUAD_INTREN_INTR_NAN_MASK)

#define POWERQUAD_INTREN_INTR_FIXED_MASK         (0x4U)
#define POWERQUAD_INTREN_INTR_FIXED_SHIFT        (2U)
/*! INTR_FIXED - Interrupt on Fixed Point Overflow
 *  0b0..Disable
 *  0b1..Enable interrupt on fixed point overflow
 */
#define POWERQUAD_INTREN_INTR_FIXED(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_FIXED_SHIFT)) & POWERQUAD_INTREN_INTR_FIXED_MASK)

#define POWERQUAD_INTREN_INTR_UFLOW_MASK         (0x8U)
#define POWERQUAD_INTREN_INTR_UFLOW_SHIFT        (3U)
/*! INTR_UFLOW - Interrupt on Subnormal Truncation
 *  0b0..Disable
 *  0b1..Enable interrupt on subnormal truncation
 */
#define POWERQUAD_INTREN_INTR_UFLOW(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_UFLOW_SHIFT)) & POWERQUAD_INTREN_INTR_UFLOW_MASK)

#define POWERQUAD_INTREN_INTR_BERR_MASK          (0x10U)
#define POWERQUAD_INTREN_INTR_BERR_SHIFT         (4U)
/*! INTR_BERR - Interrupt on AHBM Bus Error
 *  0b0..Disable
 *  0b1..Enable interrupt on AHBM Bus Error
 */
#define POWERQUAD_INTREN_INTR_BERR(x)            (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_BERR_SHIFT)) & POWERQUAD_INTREN_INTR_BERR_MASK)

#define POWERQUAD_INTREN_INTR_COMP_MASK          (0x80U)
#define POWERQUAD_INTREN_INTR_COMP_SHIFT         (7U)
/*! INTR_COMP - Interrupt on Instruction Completion
 *  0b0..Disable
 *  0b1..Enable interrupt on instruction completion
 */
#define POWERQUAD_INTREN_INTR_COMP(x)            (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTREN_INTR_COMP_SHIFT)) & POWERQUAD_INTREN_INTR_COMP_MASK)
/*! @} */

/*! @name EVENTEN - Event Enable */
/*! @{ */

#define POWERQUAD_EVENTEN_EVENT_OFLOW_MASK       (0x1U)
#define POWERQUAD_EVENTEN_EVENT_OFLOW_SHIFT      (0U)
/*! EVENT_OFLOW - Event Trigger on Floating Point Overflow
 *  0b0..Disable
 *  0b1..Enable event trigger on Floating point overflow
 */
#define POWERQUAD_EVENTEN_EVENT_OFLOW(x)         (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_OFLOW_SHIFT)) & POWERQUAD_EVENTEN_EVENT_OFLOW_MASK)

#define POWERQUAD_EVENTEN_EVENT_NAN_MASK         (0x2U)
#define POWERQUAD_EVENTEN_EVENT_NAN_SHIFT        (1U)
/*! EVENT_NAN - Event Trigger on Floating Point NaN
 *  0b0..Disable
 *  0b1..Enable event trigger on floating point NaN
 */
#define POWERQUAD_EVENTEN_EVENT_NAN(x)           (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_NAN_SHIFT)) & POWERQUAD_EVENTEN_EVENT_NAN_MASK)

#define POWERQUAD_EVENTEN_EVENT_FIXED_MASK       (0x4U)
#define POWERQUAD_EVENTEN_EVENT_FIXED_SHIFT      (2U)
/*! EVENT_FIXED - Event Trigger on Fixed Point Overflow
 *  0b0..Disable
 *  0b1..Enable event trigger on fixed point overflow
 */
#define POWERQUAD_EVENTEN_EVENT_FIXED(x)         (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_FIXED_SHIFT)) & POWERQUAD_EVENTEN_EVENT_FIXED_MASK)

#define POWERQUAD_EVENTEN_EVENT_UFLOW_MASK       (0x8U)
#define POWERQUAD_EVENTEN_EVENT_UFLOW_SHIFT      (3U)
/*! EVENT_UFLOW - Event Trigger on Subnormal Truncation
 *  0b0..Disable
 *  0b1..Enable event trigger on subnormal truncation
 */
#define POWERQUAD_EVENTEN_EVENT_UFLOW(x)         (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_UFLOW_SHIFT)) & POWERQUAD_EVENTEN_EVENT_UFLOW_MASK)

#define POWERQUAD_EVENTEN_EVENT_BERR_MASK        (0x10U)
#define POWERQUAD_EVENTEN_EVENT_BERR_SHIFT       (4U)
/*! EVENT_BERR - Event Trigger on AHBM Bus Error
 *  0b0..Disable
 *  0b1..Enable event trigger on AHBM bus error
 */
#define POWERQUAD_EVENTEN_EVENT_BERR(x)          (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_BERR_SHIFT)) & POWERQUAD_EVENTEN_EVENT_BERR_MASK)

#define POWERQUAD_EVENTEN_EVENT_COMP_MASK        (0x80U)
#define POWERQUAD_EVENTEN_EVENT_COMP_SHIFT       (7U)
/*! EVENT_COMP - Event Trigger on Instruction Completion
 *  0b0..Disable
 *  0b1..Enable event trigger on instruction completion
 */
#define POWERQUAD_EVENTEN_EVENT_COMP(x)          (((uint32_t)(((uint32_t)(x)) << POWERQUAD_EVENTEN_EVENT_COMP_SHIFT)) & POWERQUAD_EVENTEN_EVENT_COMP_MASK)
/*! @} */

/*! @name INTRSTAT - Interrupt Status */
/*! @{ */

#define POWERQUAD_INTRSTAT_INTR_STAT_MASK        (0x1U)
#define POWERQUAD_INTRSTAT_INTR_STAT_SHIFT       (0U)
/*! INTR_STAT - Interrupt Status
 *  0b0..No new interrupt
 *  0b1..Interrupt captured
 */
#define POWERQUAD_INTRSTAT_INTR_STAT(x)          (((uint32_t)(((uint32_t)(x)) << POWERQUAD_INTRSTAT_INTR_STAT_SHIFT)) & POWERQUAD_INTRSTAT_INTR_STAT_MASK)
/*! @} */

/*! @name GPREG - General Purpose Register Bank n */
/*! @{ */

#define POWERQUAD_GPREG_GPREG_MASK               (0xFFFFFFFFU)
#define POWERQUAD_GPREG_GPREG_SHIFT              (0U)
/*! GPREG - General Purpose Register Bank */
#define POWERQUAD_GPREG_GPREG(x)                 (((uint32_t)(((uint32_t)(x)) << POWERQUAD_GPREG_GPREG_SHIFT)) & POWERQUAD_GPREG_GPREG_MASK)
/*! @} */

/*! @name COMPREGS_COMPREG - Compute Register Bank n */
/*! @{ */

#define POWERQUAD_COMPREGS_COMPREG_COMPREG_MASK  (0xFFFFFFFFU)
#define POWERQUAD_COMPREGS_COMPREG_COMPREG_SHIFT (0U)
/*! COMPREG - Compute Register Bank */
#define POWERQUAD_COMPREGS_COMPREG_COMPREG(x)    (((uint32_t)(((uint32_t)(x)) << POWERQUAD_COMPREGS_COMPREG_COMPREG_SHIFT)) & POWERQUAD_COMPREGS_COMPREG_COMPREG_MASK)
/*! @} */

/* The count of POWERQUAD_COMPREGS_COMPREG */
#define POWERQUAD_COMPREGS_COMPREG_COUNT         (8U)


/*!
 * @}
 */ /* end of group POWERQUAD_Register_Masks */


/*!
 * @}
 */ /* end of group POWERQUAD_Peripheral_Access_Layer */


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


#endif  /* POWERQUAD_H_ */

