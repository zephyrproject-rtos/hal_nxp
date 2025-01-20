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
**         CMSIS Peripheral Access Layer for GCM
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
 * @file GCM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for GCM
 *
 * CMSIS Peripheral Access Layer for GCM
 */

#if !defined(GCM_H_)
#define GCM_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- GCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GCM_Peripheral_Access_Layer GCM Peripheral Access Layer
 * @{
 */

/** GCM - Size of Registers Arrays */
#define GCM_NEO_PIPE2_GCM_CONF_COUNT              1u

/** GCM - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x84 */
    __IO uint32_t IMAT0_CAM;                         /**< Camera 0 GCM Input Matrix 0 Register, array offset: 0x0, array step: 0x84 */
    __IO uint32_t IMAT1_CAM;                         /**< Camera 0 GCM Input Matrix 1 Register, array offset: 0x4, array step: 0x84 */
         uint8_t RESERVED_0[4];
    __IO uint32_t IMAT2_CAM;                         /**< Camera 0 GCM Input Matrix 2 Register, array offset: 0xC, array step: 0x84 */
    __IO uint32_t IMAT3_CAM;                         /**< Camera 0 GCM Input Matrix 3 Register, array offset: 0x10, array step: 0x84 */
         uint8_t RESERVED_1[4];
    __IO uint32_t IMAT4_CAM;                         /**< Camera 0 GCM Input Matrix 4 Register, array offset: 0x18, array step: 0x84 */
    __IO uint32_t IMAT5_CAM;                         /**< Camera 0 GCM Input Matrix 5 Register, array offset: 0x1C, array step: 0x84 */
    __IO uint32_t IOFFSET0_CAM;                      /**< Camera 0 GCM Input Offset0 Register, array offset: 0x20, array step: 0x84 */
    __IO uint32_t IOFFSET1_CAM;                      /**< Camera 0 GCM Input Offset1 Register, array offset: 0x24, array step: 0x84 */
    __IO uint32_t IOFFSET2_CAM;                      /**< Camera 0 GCM Input Offset2 Register, array offset: 0x28, array step: 0x84 */
         uint8_t RESERVED_2[4];
    __IO uint32_t OMAT0_CAM;                         /**< Camera 0 GCM Output Matrix 0 Register, array offset: 0x30, array step: 0x84 */
    __IO uint32_t OMAT1_CAM;                         /**< Camera 0 GCM Output Matrix 1 Register, array offset: 0x34, array step: 0x84 */
    __IO uint32_t OMAT2_CAM;                         /**< Camera 0 GCM Output Matrix 2 Register, array offset: 0x38, array step: 0x84 */
    __IO uint32_t OMAT3_CAM;                         /**< Camera 0 GCM Output Matrix 3 Register, array offset: 0x3C, array step: 0x84 */
    __IO uint32_t OMAT4_CAM;                         /**< Camera 0 GCM Output Matrix 4 Register, array offset: 0x40, array step: 0x84 */
    __IO uint32_t OMAT5_CAM;                         /**< Camera 0 GCM Output Matrix 5 Register, array offset: 0x44, array step: 0x84 */
    __IO uint32_t OOFFSET0_CAM;                      /**< Camera 0 GCM Output Offset 0 Register, array offset: 0x48, array step: 0x84 */
    __IO uint32_t OOFFSET1_CAM;                      /**< Camera 0 GCM Output Offset 1 Register, array offset: 0x4C, array step: 0x84 */
    __IO uint32_t OOFFSET2_CAM;                      /**< Camera 0 GCM Output Offset 2 Register, array offset: 0x50, array step: 0x84 */
         uint8_t RESERVED_3[12];
    __IO uint32_t GAMMA0_CAM;                        /**< Camera 0 GCM Gamma 0 Register, array offset: 0x60, array step: 0x84 */
    __IO uint32_t GAMMA1_CAM;                        /**< Camera 0 GCM Gamma 1 Register, array offset: 0x64, array step: 0x84 */
    __IO uint32_t GAMMA2_CAM;                        /**< Camera 0 GCM Gamma 2 Register, array offset: 0x68, array step: 0x84 */
    __IO uint32_t BLKLVL0_CTRL_CAM;                  /**< Camera 0 Linear 0 Control, array offset: 0x6C, array step: 0x84 */
    __IO uint32_t BLKLVL1_CTRL_CAM;                  /**< Camera 0 Linear 1 Control, array offset: 0x70, array step: 0x84 */
    __IO uint32_t BLKLVL2_CTRL_CAM;                  /**< Camera 0 Linear 2 Control, array offset: 0x74, array step: 0x84 */
    __IO uint32_t LOWTH_CTRL01_CAM;                  /**< Camera 0 Linear Threshold channel 0 and 1, array offset: 0x78, array step: 0x84 */
    __IO uint32_t LOWTH_CTRL2_CAM;                   /**< Camera 0 Threshold channel 2, array offset: 0x7C, array step: 0x84 */
    __IO uint32_t MAT_CONFG_CAM;                     /**< Camera 0 GCM Configuration Register, array offset: 0x80, array step: 0x84 */
  } NEO_PIPE2_GCM_CONF[GCM_NEO_PIPE2_GCM_CONF_COUNT];
} GCM_Type;

/* ----------------------------------------------------------------------------
   -- GCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GCM_Register_Masks GCM Register Masks
 * @{
 */

/*! @name IMAT0_CAM - Camera 0 GCM Input Matrix 0 Register */
/*! @{ */

#define GCM_IMAT0_CAM_R0C0_MASK                  (0xFFFFU)
#define GCM_IMAT0_CAM_R0C0_SHIFT                 (0U)
#define GCM_IMAT0_CAM_R0C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT0_CAM_R0C0_SHIFT)) & GCM_IMAT0_CAM_R0C0_MASK)

#define GCM_IMAT0_CAM_R0C1_MASK                  (0xFFFF0000U)
#define GCM_IMAT0_CAM_R0C1_SHIFT                 (16U)
#define GCM_IMAT0_CAM_R0C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT0_CAM_R0C1_SHIFT)) & GCM_IMAT0_CAM_R0C1_MASK)
/*! @} */

/* The count of GCM_IMAT0_CAM */
#define GCM_IMAT0_CAM_COUNT                      (1U)

/*! @name IMAT1_CAM - Camera 0 GCM Input Matrix 1 Register */
/*! @{ */

#define GCM_IMAT1_CAM_R0C2_MASK                  (0xFFFFU)
#define GCM_IMAT1_CAM_R0C2_SHIFT                 (0U)
#define GCM_IMAT1_CAM_R0C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT1_CAM_R0C2_SHIFT)) & GCM_IMAT1_CAM_R0C2_MASK)
/*! @} */

/* The count of GCM_IMAT1_CAM */
#define GCM_IMAT1_CAM_COUNT                      (1U)

/*! @name IMAT2_CAM - Camera 0 GCM Input Matrix 2 Register */
/*! @{ */

#define GCM_IMAT2_CAM_R1C0_MASK                  (0xFFFFU)
#define GCM_IMAT2_CAM_R1C0_SHIFT                 (0U)
#define GCM_IMAT2_CAM_R1C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT2_CAM_R1C0_SHIFT)) & GCM_IMAT2_CAM_R1C0_MASK)

#define GCM_IMAT2_CAM_R1C1_MASK                  (0xFFFF0000U)
#define GCM_IMAT2_CAM_R1C1_SHIFT                 (16U)
#define GCM_IMAT2_CAM_R1C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT2_CAM_R1C1_SHIFT)) & GCM_IMAT2_CAM_R1C1_MASK)
/*! @} */

/* The count of GCM_IMAT2_CAM */
#define GCM_IMAT2_CAM_COUNT                      (1U)

/*! @name IMAT3_CAM - Camera 0 GCM Input Matrix 3 Register */
/*! @{ */

#define GCM_IMAT3_CAM_R1C2_MASK                  (0xFFFFU)
#define GCM_IMAT3_CAM_R1C2_SHIFT                 (0U)
#define GCM_IMAT3_CAM_R1C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT3_CAM_R1C2_SHIFT)) & GCM_IMAT3_CAM_R1C2_MASK)
/*! @} */

/* The count of GCM_IMAT3_CAM */
#define GCM_IMAT3_CAM_COUNT                      (1U)

/*! @name IMAT4_CAM - Camera 0 GCM Input Matrix 4 Register */
/*! @{ */

#define GCM_IMAT4_CAM_R2C0_MASK                  (0xFFFFU)
#define GCM_IMAT4_CAM_R2C0_SHIFT                 (0U)
#define GCM_IMAT4_CAM_R2C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT4_CAM_R2C0_SHIFT)) & GCM_IMAT4_CAM_R2C0_MASK)

#define GCM_IMAT4_CAM_R2C1_MASK                  (0xFFFF0000U)
#define GCM_IMAT4_CAM_R2C1_SHIFT                 (16U)
#define GCM_IMAT4_CAM_R2C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT4_CAM_R2C1_SHIFT)) & GCM_IMAT4_CAM_R2C1_MASK)
/*! @} */

/* The count of GCM_IMAT4_CAM */
#define GCM_IMAT4_CAM_COUNT                      (1U)

/*! @name IMAT5_CAM - Camera 0 GCM Input Matrix 5 Register */
/*! @{ */

#define GCM_IMAT5_CAM_R2C2_MASK                  (0xFFFFU)
#define GCM_IMAT5_CAM_R2C2_SHIFT                 (0U)
#define GCM_IMAT5_CAM_R2C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_IMAT5_CAM_R2C2_SHIFT)) & GCM_IMAT5_CAM_R2C2_MASK)
/*! @} */

/* The count of GCM_IMAT5_CAM */
#define GCM_IMAT5_CAM_COUNT                      (1U)

/*! @name IOFFSET0_CAM - Camera 0 GCM Input Offset0 Register */
/*! @{ */

#define GCM_IOFFSET0_CAM_OFFSET0_MASK            (0xFFFFU)
#define GCM_IOFFSET0_CAM_OFFSET0_SHIFT           (0U)
#define GCM_IOFFSET0_CAM_OFFSET0(x)              (((uint32_t)(((uint32_t)(x)) << GCM_IOFFSET0_CAM_OFFSET0_SHIFT)) & GCM_IOFFSET0_CAM_OFFSET0_MASK)
/*! @} */

/* The count of GCM_IOFFSET0_CAM */
#define GCM_IOFFSET0_CAM_COUNT                   (1U)

/*! @name IOFFSET1_CAM - Camera 0 GCM Input Offset1 Register */
/*! @{ */

#define GCM_IOFFSET1_CAM_OFFSET1_MASK            (0xFFFFU)
#define GCM_IOFFSET1_CAM_OFFSET1_SHIFT           (0U)
#define GCM_IOFFSET1_CAM_OFFSET1(x)              (((uint32_t)(((uint32_t)(x)) << GCM_IOFFSET1_CAM_OFFSET1_SHIFT)) & GCM_IOFFSET1_CAM_OFFSET1_MASK)
/*! @} */

/* The count of GCM_IOFFSET1_CAM */
#define GCM_IOFFSET1_CAM_COUNT                   (1U)

/*! @name IOFFSET2_CAM - Camera 0 GCM Input Offset2 Register */
/*! @{ */

#define GCM_IOFFSET2_CAM_OFFSET2_MASK            (0xFFFFU)
#define GCM_IOFFSET2_CAM_OFFSET2_SHIFT           (0U)
#define GCM_IOFFSET2_CAM_OFFSET2(x)              (((uint32_t)(((uint32_t)(x)) << GCM_IOFFSET2_CAM_OFFSET2_SHIFT)) & GCM_IOFFSET2_CAM_OFFSET2_MASK)
/*! @} */

/* The count of GCM_IOFFSET2_CAM */
#define GCM_IOFFSET2_CAM_COUNT                   (1U)

/*! @name OMAT0_CAM - Camera 0 GCM Output Matrix 0 Register */
/*! @{ */

#define GCM_OMAT0_CAM_R0C0_MASK                  (0xFFFFU)
#define GCM_OMAT0_CAM_R0C0_SHIFT                 (0U)
#define GCM_OMAT0_CAM_R0C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT0_CAM_R0C0_SHIFT)) & GCM_OMAT0_CAM_R0C0_MASK)

#define GCM_OMAT0_CAM_R0C1_MASK                  (0xFFFF0000U)
#define GCM_OMAT0_CAM_R0C1_SHIFT                 (16U)
#define GCM_OMAT0_CAM_R0C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT0_CAM_R0C1_SHIFT)) & GCM_OMAT0_CAM_R0C1_MASK)
/*! @} */

/* The count of GCM_OMAT0_CAM */
#define GCM_OMAT0_CAM_COUNT                      (1U)

/*! @name OMAT1_CAM - Camera 0 GCM Output Matrix 1 Register */
/*! @{ */

#define GCM_OMAT1_CAM_R0C2_MASK                  (0xFFFFU)
#define GCM_OMAT1_CAM_R0C2_SHIFT                 (0U)
#define GCM_OMAT1_CAM_R0C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT1_CAM_R0C2_SHIFT)) & GCM_OMAT1_CAM_R0C2_MASK)
/*! @} */

/* The count of GCM_OMAT1_CAM */
#define GCM_OMAT1_CAM_COUNT                      (1U)

/*! @name OMAT2_CAM - Camera 0 GCM Output Matrix 2 Register */
/*! @{ */

#define GCM_OMAT2_CAM_R1C0_MASK                  (0xFFFFU)
#define GCM_OMAT2_CAM_R1C0_SHIFT                 (0U)
#define GCM_OMAT2_CAM_R1C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT2_CAM_R1C0_SHIFT)) & GCM_OMAT2_CAM_R1C0_MASK)

#define GCM_OMAT2_CAM_R1C1_MASK                  (0xFFFF0000U)
#define GCM_OMAT2_CAM_R1C1_SHIFT                 (16U)
#define GCM_OMAT2_CAM_R1C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT2_CAM_R1C1_SHIFT)) & GCM_OMAT2_CAM_R1C1_MASK)
/*! @} */

/* The count of GCM_OMAT2_CAM */
#define GCM_OMAT2_CAM_COUNT                      (1U)

/*! @name OMAT3_CAM - Camera 0 GCM Output Matrix 3 Register */
/*! @{ */

#define GCM_OMAT3_CAM_R1C2_MASK                  (0xFFFFU)
#define GCM_OMAT3_CAM_R1C2_SHIFT                 (0U)
#define GCM_OMAT3_CAM_R1C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT3_CAM_R1C2_SHIFT)) & GCM_OMAT3_CAM_R1C2_MASK)
/*! @} */

/* The count of GCM_OMAT3_CAM */
#define GCM_OMAT3_CAM_COUNT                      (1U)

/*! @name OMAT4_CAM - Camera 0 GCM Output Matrix 4 Register */
/*! @{ */

#define GCM_OMAT4_CAM_R2C0_MASK                  (0xFFFFU)
#define GCM_OMAT4_CAM_R2C0_SHIFT                 (0U)
#define GCM_OMAT4_CAM_R2C0(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT4_CAM_R2C0_SHIFT)) & GCM_OMAT4_CAM_R2C0_MASK)

#define GCM_OMAT4_CAM_R2C1_MASK                  (0xFFFF0000U)
#define GCM_OMAT4_CAM_R2C1_SHIFT                 (16U)
#define GCM_OMAT4_CAM_R2C1(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT4_CAM_R2C1_SHIFT)) & GCM_OMAT4_CAM_R2C1_MASK)
/*! @} */

/* The count of GCM_OMAT4_CAM */
#define GCM_OMAT4_CAM_COUNT                      (1U)

/*! @name OMAT5_CAM - Camera 0 GCM Output Matrix 5 Register */
/*! @{ */

#define GCM_OMAT5_CAM_R2C2_MASK                  (0xFFFFU)
#define GCM_OMAT5_CAM_R2C2_SHIFT                 (0U)
#define GCM_OMAT5_CAM_R2C2(x)                    (((uint32_t)(((uint32_t)(x)) << GCM_OMAT5_CAM_R2C2_SHIFT)) & GCM_OMAT5_CAM_R2C2_MASK)
/*! @} */

/* The count of GCM_OMAT5_CAM */
#define GCM_OMAT5_CAM_COUNT                      (1U)

/*! @name OOFFSET0_CAM - Camera 0 GCM Output Offset 0 Register */
/*! @{ */

#define GCM_OOFFSET0_CAM_OFFSET0_MASK            (0x1FFFU)
#define GCM_OOFFSET0_CAM_OFFSET0_SHIFT           (0U)
#define GCM_OOFFSET0_CAM_OFFSET0(x)              (((uint32_t)(((uint32_t)(x)) << GCM_OOFFSET0_CAM_OFFSET0_SHIFT)) & GCM_OOFFSET0_CAM_OFFSET0_MASK)
/*! @} */

/* The count of GCM_OOFFSET0_CAM */
#define GCM_OOFFSET0_CAM_COUNT                   (1U)

/*! @name OOFFSET1_CAM - Camera 0 GCM Output Offset 1 Register */
/*! @{ */

#define GCM_OOFFSET1_CAM_OFFSET1_MASK            (0x1FFFU)
#define GCM_OOFFSET1_CAM_OFFSET1_SHIFT           (0U)
#define GCM_OOFFSET1_CAM_OFFSET1(x)              (((uint32_t)(((uint32_t)(x)) << GCM_OOFFSET1_CAM_OFFSET1_SHIFT)) & GCM_OOFFSET1_CAM_OFFSET1_MASK)
/*! @} */

/* The count of GCM_OOFFSET1_CAM */
#define GCM_OOFFSET1_CAM_COUNT                   (1U)

/*! @name OOFFSET2_CAM - Camera 0 GCM Output Offset 2 Register */
/*! @{ */

#define GCM_OOFFSET2_CAM_OFFSET2_MASK            (0x1FFFU)
#define GCM_OOFFSET2_CAM_OFFSET2_SHIFT           (0U)
#define GCM_OOFFSET2_CAM_OFFSET2(x)              (((uint32_t)(((uint32_t)(x)) << GCM_OOFFSET2_CAM_OFFSET2_SHIFT)) & GCM_OOFFSET2_CAM_OFFSET2_MASK)
/*! @} */

/* The count of GCM_OOFFSET2_CAM */
#define GCM_OOFFSET2_CAM_COUNT                   (1U)

/*! @name GAMMA0_CAM - Camera 0 GCM Gamma 0 Register */
/*! @{ */

#define GCM_GAMMA0_CAM_GAMMA0_MASK               (0x1FFU)
#define GCM_GAMMA0_CAM_GAMMA0_SHIFT              (0U)
#define GCM_GAMMA0_CAM_GAMMA0(x)                 (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA0_CAM_GAMMA0_SHIFT)) & GCM_GAMMA0_CAM_GAMMA0_MASK)

#define GCM_GAMMA0_CAM_OFFSET0_MASK              (0xFFF0000U)
#define GCM_GAMMA0_CAM_OFFSET0_SHIFT             (16U)
#define GCM_GAMMA0_CAM_OFFSET0(x)                (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA0_CAM_OFFSET0_SHIFT)) & GCM_GAMMA0_CAM_OFFSET0_MASK)
/*! @} */

/* The count of GCM_GAMMA0_CAM */
#define GCM_GAMMA0_CAM_COUNT                     (1U)

/*! @name GAMMA1_CAM - Camera 0 GCM Gamma 1 Register */
/*! @{ */

#define GCM_GAMMA1_CAM_GAMMA1_MASK               (0x1FFU)
#define GCM_GAMMA1_CAM_GAMMA1_SHIFT              (0U)
#define GCM_GAMMA1_CAM_GAMMA1(x)                 (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA1_CAM_GAMMA1_SHIFT)) & GCM_GAMMA1_CAM_GAMMA1_MASK)

#define GCM_GAMMA1_CAM_OFFSET1_MASK              (0xFFF0000U)
#define GCM_GAMMA1_CAM_OFFSET1_SHIFT             (16U)
#define GCM_GAMMA1_CAM_OFFSET1(x)                (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA1_CAM_OFFSET1_SHIFT)) & GCM_GAMMA1_CAM_OFFSET1_MASK)
/*! @} */

/* The count of GCM_GAMMA1_CAM */
#define GCM_GAMMA1_CAM_COUNT                     (1U)

/*! @name GAMMA2_CAM - Camera 0 GCM Gamma 2 Register */
/*! @{ */

#define GCM_GAMMA2_CAM_GAMMA2_MASK               (0x1FFU)
#define GCM_GAMMA2_CAM_GAMMA2_SHIFT              (0U)
#define GCM_GAMMA2_CAM_GAMMA2(x)                 (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA2_CAM_GAMMA2_SHIFT)) & GCM_GAMMA2_CAM_GAMMA2_MASK)

#define GCM_GAMMA2_CAM_OFFSET2_MASK              (0xFFF0000U)
#define GCM_GAMMA2_CAM_OFFSET2_SHIFT             (16U)
#define GCM_GAMMA2_CAM_OFFSET2(x)                (((uint32_t)(((uint32_t)(x)) << GCM_GAMMA2_CAM_OFFSET2_SHIFT)) & GCM_GAMMA2_CAM_OFFSET2_MASK)
/*! @} */

/* The count of GCM_GAMMA2_CAM */
#define GCM_GAMMA2_CAM_COUNT                     (1U)

/*! @name BLKLVL0_CTRL_CAM - Camera 0 Linear 0 Control */
/*! @{ */

#define GCM_BLKLVL0_CTRL_CAM_OFFSET0_MASK        (0xFFFFU)
#define GCM_BLKLVL0_CTRL_CAM_OFFSET0_SHIFT       (0U)
#define GCM_BLKLVL0_CTRL_CAM_OFFSET0(x)          (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL0_CTRL_CAM_OFFSET0_SHIFT)) & GCM_BLKLVL0_CTRL_CAM_OFFSET0_MASK)

#define GCM_BLKLVL0_CTRL_CAM_GAIN0_MASK          (0xFFFF0000U)
#define GCM_BLKLVL0_CTRL_CAM_GAIN0_SHIFT         (16U)
#define GCM_BLKLVL0_CTRL_CAM_GAIN0(x)            (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL0_CTRL_CAM_GAIN0_SHIFT)) & GCM_BLKLVL0_CTRL_CAM_GAIN0_MASK)
/*! @} */

/* The count of GCM_BLKLVL0_CTRL_CAM */
#define GCM_BLKLVL0_CTRL_CAM_COUNT               (1U)

/*! @name BLKLVL1_CTRL_CAM - Camera 0 Linear 1 Control */
/*! @{ */

#define GCM_BLKLVL1_CTRL_CAM_OFFSET1_MASK        (0xFFFFU)
#define GCM_BLKLVL1_CTRL_CAM_OFFSET1_SHIFT       (0U)
#define GCM_BLKLVL1_CTRL_CAM_OFFSET1(x)          (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL1_CTRL_CAM_OFFSET1_SHIFT)) & GCM_BLKLVL1_CTRL_CAM_OFFSET1_MASK)

#define GCM_BLKLVL1_CTRL_CAM_GAIN1_MASK          (0xFFFF0000U)
#define GCM_BLKLVL1_CTRL_CAM_GAIN1_SHIFT         (16U)
#define GCM_BLKLVL1_CTRL_CAM_GAIN1(x)            (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL1_CTRL_CAM_GAIN1_SHIFT)) & GCM_BLKLVL1_CTRL_CAM_GAIN1_MASK)
/*! @} */

/* The count of GCM_BLKLVL1_CTRL_CAM */
#define GCM_BLKLVL1_CTRL_CAM_COUNT               (1U)

/*! @name BLKLVL2_CTRL_CAM - Camera 0 Linear 2 Control */
/*! @{ */

#define GCM_BLKLVL2_CTRL_CAM_OFFSET2_MASK        (0xFFFFU)
#define GCM_BLKLVL2_CTRL_CAM_OFFSET2_SHIFT       (0U)
#define GCM_BLKLVL2_CTRL_CAM_OFFSET2(x)          (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL2_CTRL_CAM_OFFSET2_SHIFT)) & GCM_BLKLVL2_CTRL_CAM_OFFSET2_MASK)

#define GCM_BLKLVL2_CTRL_CAM_GAIN2_MASK          (0xFFFF0000U)
#define GCM_BLKLVL2_CTRL_CAM_GAIN2_SHIFT         (16U)
#define GCM_BLKLVL2_CTRL_CAM_GAIN2(x)            (((uint32_t)(((uint32_t)(x)) << GCM_BLKLVL2_CTRL_CAM_GAIN2_SHIFT)) & GCM_BLKLVL2_CTRL_CAM_GAIN2_MASK)
/*! @} */

/* The count of GCM_BLKLVL2_CTRL_CAM */
#define GCM_BLKLVL2_CTRL_CAM_COUNT               (1U)

/*! @name LOWTH_CTRL01_CAM - Camera 0 Linear Threshold channel 0 and 1 */
/*! @{ */

#define GCM_LOWTH_CTRL01_CAM_THRESHOLD0_MASK     (0xFFFFU)
#define GCM_LOWTH_CTRL01_CAM_THRESHOLD0_SHIFT    (0U)
#define GCM_LOWTH_CTRL01_CAM_THRESHOLD0(x)       (((uint32_t)(((uint32_t)(x)) << GCM_LOWTH_CTRL01_CAM_THRESHOLD0_SHIFT)) & GCM_LOWTH_CTRL01_CAM_THRESHOLD0_MASK)

#define GCM_LOWTH_CTRL01_CAM_THRESHOLD1_MASK     (0xFFFF0000U)
#define GCM_LOWTH_CTRL01_CAM_THRESHOLD1_SHIFT    (16U)
#define GCM_LOWTH_CTRL01_CAM_THRESHOLD1(x)       (((uint32_t)(((uint32_t)(x)) << GCM_LOWTH_CTRL01_CAM_THRESHOLD1_SHIFT)) & GCM_LOWTH_CTRL01_CAM_THRESHOLD1_MASK)
/*! @} */

/* The count of GCM_LOWTH_CTRL01_CAM */
#define GCM_LOWTH_CTRL01_CAM_COUNT               (1U)

/*! @name LOWTH_CTRL2_CAM - Camera 0 Threshold channel 2 */
/*! @{ */

#define GCM_LOWTH_CTRL2_CAM_THRESHOLD2_MASK      (0xFFFFU)
#define GCM_LOWTH_CTRL2_CAM_THRESHOLD2_SHIFT     (0U)
#define GCM_LOWTH_CTRL2_CAM_THRESHOLD2(x)        (((uint32_t)(((uint32_t)(x)) << GCM_LOWTH_CTRL2_CAM_THRESHOLD2_SHIFT)) & GCM_LOWTH_CTRL2_CAM_THRESHOLD2_MASK)
/*! @} */

/* The count of GCM_LOWTH_CTRL2_CAM */
#define GCM_LOWTH_CTRL2_CAM_COUNT                (1U)

/*! @name MAT_CONFG_CAM - Camera 0 GCM Configuration Register */
/*! @{ */

#define GCM_MAT_CONFG_CAM_SIGN_CONFG_MASK        (0x1U)
#define GCM_MAT_CONFG_CAM_SIGN_CONFG_SHIFT       (0U)
/*! SIGN_CONFG
 *  0b0..Signed
 *  0b1..Unsigned
 */
#define GCM_MAT_CONFG_CAM_SIGN_CONFG(x)          (((uint32_t)(((uint32_t)(x)) << GCM_MAT_CONFG_CAM_SIGN_CONFG_SHIFT)) & GCM_MAT_CONFG_CAM_SIGN_CONFG_MASK)
/*! @} */

/* The count of GCM_MAT_CONFG_CAM */
#define GCM_MAT_CONFG_CAM_COUNT                  (1U)


/*!
 * @}
 */ /* end of group GCM_Register_Masks */


/*!
 * @}
 */ /* end of group GCM_Peripheral_Access_Layer */


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


#endif  /* GCM_H_ */

