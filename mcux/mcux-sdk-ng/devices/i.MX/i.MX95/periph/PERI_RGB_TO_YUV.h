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
**         CMSIS Peripheral Access Layer for RGB_TO_YUV
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
 * @file RGB_TO_YUV.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for RGB_TO_YUV
 *
 * CMSIS Peripheral Access Layer for RGB_TO_YUV
 */

#if !defined(RGB_TO_YUV_H_)
#define RGB_TO_YUV_H_                            /**< Symbol preventing repeated inclusion */

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
   -- RGB_TO_YUV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RGB_TO_YUV_Peripheral_Access_Layer RGB_TO_YUV Peripheral Access Layer
 * @{
 */

/** RGB_TO_YUV - Size of Registers Arrays */
#define RGB_TO_YUV_NEO_PIPE2_CSC_CONF_COUNT       1u

/** RGB_TO_YUV - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2C */
    __IO uint32_t GAIN_CTRL_CAM;                     /**< Camera 0 CSC Gain Control Register, array offset: 0x0, array step: 0x2C */
    __IO uint32_t MAT0_CAM;                          /**< Camera 0 CSC Matrix 0 Register, array offset: 0x4, array step: 0x2C */
    __IO uint32_t MAT1_CAM;                          /**< Camera 0 CSC Matrix 1 Register, array offset: 0x8, array step: 0x2C */
    __IO uint32_t MAT2_CAM;                          /**< Camera 0 CSC Matrix 2 Register, array offset: 0xC, array step: 0x2C */
    __IO uint32_t MAT3_CAM;                          /**< Camera 0 CSC Matrix 3 Register, array offset: 0x10, array step: 0x2C */
    __IO uint32_t MAT4_CAM;                          /**< Camera 0 CSC Matrix 4 Register, array offset: 0x14, array step: 0x2C */
    __IO uint32_t MAT5_CAM;                          /**< Camera 0 CSC Matrix 5 Register, array offset: 0x18, array step: 0x2C */
         uint8_t RESERVED_0[4];
    __IO uint32_t OFFSET0_CAM;                       /**< Camera 0 CSC Offset 0 Register, array offset: 0x20, array step: 0x2C */
    __IO uint32_t OFFSET1_CAM;                       /**< Camera 0 CSC Offset 1 Register, array offset: 0x24, array step: 0x2C */
    __IO uint32_t OFFSET2_CAM;                       /**< Camera 0 CSC Offset 2 Register, array offset: 0x28, array step: 0x2C */
  } NEO_PIPE2_CSC_CONF[RGB_TO_YUV_NEO_PIPE2_CSC_CONF_COUNT];
} RGB_TO_YUV_Type;

/* ----------------------------------------------------------------------------
   -- RGB_TO_YUV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RGB_TO_YUV_Register_Masks RGB_TO_YUV Register Masks
 * @{
 */

/*! @name GAIN_CTRL_CAM - Camera 0 CSC Gain Control Register */
/*! @{ */

#define RGB_TO_YUV_GAIN_CTRL_CAM_RGAIN_MASK      (0xFFFFU)
#define RGB_TO_YUV_GAIN_CTRL_CAM_RGAIN_SHIFT     (0U)
#define RGB_TO_YUV_GAIN_CTRL_CAM_RGAIN(x)        (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_GAIN_CTRL_CAM_RGAIN_SHIFT)) & RGB_TO_YUV_GAIN_CTRL_CAM_RGAIN_MASK)

#define RGB_TO_YUV_GAIN_CTRL_CAM_BGAIN_MASK      (0xFFFF0000U)
#define RGB_TO_YUV_GAIN_CTRL_CAM_BGAIN_SHIFT     (16U)
#define RGB_TO_YUV_GAIN_CTRL_CAM_BGAIN(x)        (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_GAIN_CTRL_CAM_BGAIN_SHIFT)) & RGB_TO_YUV_GAIN_CTRL_CAM_BGAIN_MASK)
/*! @} */

/* The count of RGB_TO_YUV_GAIN_CTRL_CAM */
#define RGB_TO_YUV_GAIN_CTRL_CAM_COUNT           (1U)

/*! @name MAT0_CAM - Camera 0 CSC Matrix 0 Register */
/*! @{ */

#define RGB_TO_YUV_MAT0_CAM_R0C0_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT0_CAM_R0C0_SHIFT           (0U)
#define RGB_TO_YUV_MAT0_CAM_R0C0(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT0_CAM_R0C0_SHIFT)) & RGB_TO_YUV_MAT0_CAM_R0C0_MASK)

#define RGB_TO_YUV_MAT0_CAM_R0C1_MASK            (0xFFFF0000U)
#define RGB_TO_YUV_MAT0_CAM_R0C1_SHIFT           (16U)
#define RGB_TO_YUV_MAT0_CAM_R0C1(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT0_CAM_R0C1_SHIFT)) & RGB_TO_YUV_MAT0_CAM_R0C1_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT0_CAM */
#define RGB_TO_YUV_MAT0_CAM_COUNT                (1U)

/*! @name MAT1_CAM - Camera 0 CSC Matrix 1 Register */
/*! @{ */

#define RGB_TO_YUV_MAT1_CAM_R0C2_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT1_CAM_R0C2_SHIFT           (0U)
#define RGB_TO_YUV_MAT1_CAM_R0C2(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT1_CAM_R0C2_SHIFT)) & RGB_TO_YUV_MAT1_CAM_R0C2_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT1_CAM */
#define RGB_TO_YUV_MAT1_CAM_COUNT                (1U)

/*! @name MAT2_CAM - Camera 0 CSC Matrix 2 Register */
/*! @{ */

#define RGB_TO_YUV_MAT2_CAM_R1C0_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT2_CAM_R1C0_SHIFT           (0U)
#define RGB_TO_YUV_MAT2_CAM_R1C0(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT2_CAM_R1C0_SHIFT)) & RGB_TO_YUV_MAT2_CAM_R1C0_MASK)

#define RGB_TO_YUV_MAT2_CAM_R1C1_MASK            (0xFFFF0000U)
#define RGB_TO_YUV_MAT2_CAM_R1C1_SHIFT           (16U)
#define RGB_TO_YUV_MAT2_CAM_R1C1(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT2_CAM_R1C1_SHIFT)) & RGB_TO_YUV_MAT2_CAM_R1C1_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT2_CAM */
#define RGB_TO_YUV_MAT2_CAM_COUNT                (1U)

/*! @name MAT3_CAM - Camera 0 CSC Matrix 3 Register */
/*! @{ */

#define RGB_TO_YUV_MAT3_CAM_R1C2_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT3_CAM_R1C2_SHIFT           (0U)
#define RGB_TO_YUV_MAT3_CAM_R1C2(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT3_CAM_R1C2_SHIFT)) & RGB_TO_YUV_MAT3_CAM_R1C2_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT3_CAM */
#define RGB_TO_YUV_MAT3_CAM_COUNT                (1U)

/*! @name MAT4_CAM - Camera 0 CSC Matrix 4 Register */
/*! @{ */

#define RGB_TO_YUV_MAT4_CAM_R2C0_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT4_CAM_R2C0_SHIFT           (0U)
#define RGB_TO_YUV_MAT4_CAM_R2C0(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT4_CAM_R2C0_SHIFT)) & RGB_TO_YUV_MAT4_CAM_R2C0_MASK)

#define RGB_TO_YUV_MAT4_CAM_R2C1_MASK            (0xFFFF0000U)
#define RGB_TO_YUV_MAT4_CAM_R2C1_SHIFT           (16U)
#define RGB_TO_YUV_MAT4_CAM_R2C1(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT4_CAM_R2C1_SHIFT)) & RGB_TO_YUV_MAT4_CAM_R2C1_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT4_CAM */
#define RGB_TO_YUV_MAT4_CAM_COUNT                (1U)

/*! @name MAT5_CAM - Camera 0 CSC Matrix 5 Register */
/*! @{ */

#define RGB_TO_YUV_MAT5_CAM_R2C2_MASK            (0xFFFFU)
#define RGB_TO_YUV_MAT5_CAM_R2C2_SHIFT           (0U)
#define RGB_TO_YUV_MAT5_CAM_R2C2(x)              (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_MAT5_CAM_R2C2_SHIFT)) & RGB_TO_YUV_MAT5_CAM_R2C2_MASK)
/*! @} */

/* The count of RGB_TO_YUV_MAT5_CAM */
#define RGB_TO_YUV_MAT5_CAM_COUNT                (1U)

/*! @name OFFSET0_CAM - Camera 0 CSC Offset 0 Register */
/*! @{ */

#define RGB_TO_YUV_OFFSET0_CAM_OFFSET_MASK       (0x1FFFFFU)
#define RGB_TO_YUV_OFFSET0_CAM_OFFSET_SHIFT      (0U)
#define RGB_TO_YUV_OFFSET0_CAM_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_OFFSET0_CAM_OFFSET_SHIFT)) & RGB_TO_YUV_OFFSET0_CAM_OFFSET_MASK)
/*! @} */

/* The count of RGB_TO_YUV_OFFSET0_CAM */
#define RGB_TO_YUV_OFFSET0_CAM_COUNT             (1U)

/*! @name OFFSET1_CAM - Camera 0 CSC Offset 1 Register */
/*! @{ */

#define RGB_TO_YUV_OFFSET1_CAM_OFFSET_MASK       (0x1FFFFFU)
#define RGB_TO_YUV_OFFSET1_CAM_OFFSET_SHIFT      (0U)
#define RGB_TO_YUV_OFFSET1_CAM_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_OFFSET1_CAM_OFFSET_SHIFT)) & RGB_TO_YUV_OFFSET1_CAM_OFFSET_MASK)
/*! @} */

/* The count of RGB_TO_YUV_OFFSET1_CAM */
#define RGB_TO_YUV_OFFSET1_CAM_COUNT             (1U)

/*! @name OFFSET2_CAM - Camera 0 CSC Offset 2 Register */
/*! @{ */

#define RGB_TO_YUV_OFFSET2_CAM_OFFSET_MASK       (0x1FFFFFU)
#define RGB_TO_YUV_OFFSET2_CAM_OFFSET_SHIFT      (0U)
#define RGB_TO_YUV_OFFSET2_CAM_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << RGB_TO_YUV_OFFSET2_CAM_OFFSET_SHIFT)) & RGB_TO_YUV_OFFSET2_CAM_OFFSET_MASK)
/*! @} */

/* The count of RGB_TO_YUV_OFFSET2_CAM */
#define RGB_TO_YUV_OFFSET2_CAM_COUNT             (1U)


/*!
 * @}
 */ /* end of group RGB_TO_YUV_Register_Masks */


/*!
 * @}
 */ /* end of group RGB_TO_YUV_Peripheral_Access_Layer */


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


#endif  /* RGB_TO_YUV_H_ */

