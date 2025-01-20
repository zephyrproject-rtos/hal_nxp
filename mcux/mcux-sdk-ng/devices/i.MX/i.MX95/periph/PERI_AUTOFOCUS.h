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
**         CMSIS Peripheral Access Layer for AUTOFOCUS
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
 * @file AUTOFOCUS.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for AUTOFOCUS
 *
 * CMSIS Peripheral Access Layer for AUTOFOCUS
 */

#if !defined(AUTOFOCUS_H_)
#define AUTOFOCUS_H_                             /**< Symbol preventing repeated inclusion */

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
   -- AUTOFOCUS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUTOFOCUS_Peripheral_Access_Layer AUTOFOCUS Peripheral Access Layer
 * @{
 */

/** AUTOFOCUS - Size of Registers Arrays */
#define AUTOFOCUS_NEO_PIPE2_AF_CONF_ROI_COUNT     9u
#define AUTOFOCUS_NEO_PIPE2_AF_CONF_FILTER_COUNT  2u
#define AUTOFOCUS_NEO_PIPE2_AF_CONF_SUM_COUNT     9u
#define AUTOFOCUS_NEO_PIPE2_AF_CONF_COUNT         1u

/** AUTOFOCUS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0xB8 */
    struct {                                         /* offset: 0x0, array step: index*0xB8, index2*0x8 */
      __IO uint32_t POS_CAM;                           /**< Camera 0 Autofocus ROI 0 Position Register..Camera 0 Autofocus ROI 8 Position Register, array offset: 0x0, array step: index*0xB8, index2*0x8 */
      __IO uint32_t SIZE_CAM;                          /**< Camera 0 Autofocus ROI 0 Size Register..Camera 0 Autofocus ROI 8 Size Register, array offset: 0x4, array step: index*0xB8, index2*0x8 */
    } ROI[AUTOFOCUS_NEO_PIPE2_AF_CONF_ROI_COUNT];
         uint8_t RESERVED_0[8];
    struct {                                         /* offset: 0x50, array step: index*0xB8, index2*0x10 */
      __IO uint32_t FIL_COEFFS0_CAM;                   /**< Camera 0 Autofocus Filter 0 Coefficient Set 0 Register..Camera 0 Autofocus Filter 1 Coefficient Set 0 Register, array offset: 0x50, array step: index*0xB8, index2*0x10 */
      __IO uint32_t FIL_COEFFS1_CAM;                   /**< Camera 0 Autofocus Filter 0 Coefficient Set 1 Register..Camera 0 Autofocus Filter 1 Coefficient Set 1 Register, array offset: 0x54, array step: index*0xB8, index2*0x10 */
      __IO uint32_t FIL_COEFFS2_CAM;                   /**< Camera 0 Autofocus Filter 0 Coefficient Set 2 Register..Camera 0 Autofocus Filter 1 Coefficient Set 2 Register, array offset: 0x58, array step: index*0xB8, index2*0x10 */
      __IO uint32_t FIL_SHIFT_CAM;                     /**< Camera 0 Autofocus Filter 0 Shift Register..Camera 0 Autofocus Filter 1 Shift Register, array offset: 0x5C, array step: index*0xB8, index2*0x10 */
    } FILTER[AUTOFOCUS_NEO_PIPE2_AF_CONF_FILTER_COUNT];
    struct {                                         /* offset: 0x70, array step: index*0xB8, index2*0x8 */
      __I  uint32_t ROI_SUM0_CAM;                      /**< Camera 0 Autofocus ROI 0 SUM Filter 0 Register..Camera 0 Autofocus ROI 8 SUM Filter 0 Register, array offset: 0x70, array step: index*0xB8, index2*0x8 */
      __I  uint32_t ROI_SUM1_CAM;                      /**< Camera 0 Autofocus ROI 0 SUM Filter 1 Register..Camera 0 Autofocus ROI 8 SUM Filter 1 Register, array offset: 0x74, array step: index*0xB8, index2*0x8 */
    } SUM[AUTOFOCUS_NEO_PIPE2_AF_CONF_SUM_COUNT];
  } NEO_PIPE2_AF_CONF[AUTOFOCUS_NEO_PIPE2_AF_CONF_COUNT];
} AUTOFOCUS_Type;

/* ----------------------------------------------------------------------------
   -- AUTOFOCUS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AUTOFOCUS_Register_Masks AUTOFOCUS Register Masks
 * @{
 */

/*! @name POS_CAM - Camera 0 Autofocus ROI 0 Position Register..Camera 0 Autofocus ROI 8 Position Register */
/*! @{ */

#define AUTOFOCUS_POS_CAM_XPOS_MASK              (0xFFFFU)
#define AUTOFOCUS_POS_CAM_XPOS_SHIFT             (0U)
#define AUTOFOCUS_POS_CAM_XPOS(x)                (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_POS_CAM_XPOS_SHIFT)) & AUTOFOCUS_POS_CAM_XPOS_MASK)

#define AUTOFOCUS_POS_CAM_YPOS_MASK              (0xFFFF0000U)
#define AUTOFOCUS_POS_CAM_YPOS_SHIFT             (16U)
#define AUTOFOCUS_POS_CAM_YPOS(x)                (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_POS_CAM_YPOS_SHIFT)) & AUTOFOCUS_POS_CAM_YPOS_MASK)
/*! @} */

/* The count of AUTOFOCUS_POS_CAM */
#define AUTOFOCUS_POS_CAM_COUNT                  (1U)

/* The count of AUTOFOCUS_POS_CAM */
#define AUTOFOCUS_POS_CAM_COUNT2                 (9U)

/*! @name SIZE_CAM - Camera 0 Autofocus ROI 0 Size Register..Camera 0 Autofocus ROI 8 Size Register */
/*! @{ */

#define AUTOFOCUS_SIZE_CAM_WIDTH_MASK            (0xFFFFU)
#define AUTOFOCUS_SIZE_CAM_WIDTH_SHIFT           (0U)
#define AUTOFOCUS_SIZE_CAM_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_SIZE_CAM_WIDTH_SHIFT)) & AUTOFOCUS_SIZE_CAM_WIDTH_MASK)

#define AUTOFOCUS_SIZE_CAM_HEIGHT_MASK           (0xFFFF0000U)
#define AUTOFOCUS_SIZE_CAM_HEIGHT_SHIFT          (16U)
#define AUTOFOCUS_SIZE_CAM_HEIGHT(x)             (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_SIZE_CAM_HEIGHT_SHIFT)) & AUTOFOCUS_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of AUTOFOCUS_SIZE_CAM */
#define AUTOFOCUS_SIZE_CAM_COUNT                 (1U)

/* The count of AUTOFOCUS_SIZE_CAM */
#define AUTOFOCUS_SIZE_CAM_COUNT2                (9U)

/*! @name FIL_COEFFS0_CAM - Camera 0 Autofocus Filter 0 Coefficient Set 0 Register..Camera 0 Autofocus Filter 1 Coefficient Set 0 Register */
/*! @{ */

#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF0_MASK    (0xFFU)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF0_SHIFT   (0U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF0(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS0_CAM_COEFF0_SHIFT)) & AUTOFOCUS_FIL_COEFFS0_CAM_COEFF0_MASK)

#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF1_MASK    (0xFF00U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF1_SHIFT   (8U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF1(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS0_CAM_COEFF1_SHIFT)) & AUTOFOCUS_FIL_COEFFS0_CAM_COEFF1_MASK)

#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF2_MASK    (0xFF0000U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF2_SHIFT   (16U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF2(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS0_CAM_COEFF2_SHIFT)) & AUTOFOCUS_FIL_COEFFS0_CAM_COEFF2_MASK)

#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF3_MASK    (0xFF000000U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF3_SHIFT   (24U)
#define AUTOFOCUS_FIL_COEFFS0_CAM_COEFF3(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS0_CAM_COEFF3_SHIFT)) & AUTOFOCUS_FIL_COEFFS0_CAM_COEFF3_MASK)
/*! @} */

/* The count of AUTOFOCUS_FIL_COEFFS0_CAM */
#define AUTOFOCUS_FIL_COEFFS0_CAM_COUNT          (1U)

/* The count of AUTOFOCUS_FIL_COEFFS0_CAM */
#define AUTOFOCUS_FIL_COEFFS0_CAM_COUNT2         (2U)

/*! @name FIL_COEFFS1_CAM - Camera 0 Autofocus Filter 0 Coefficient Set 1 Register..Camera 0 Autofocus Filter 1 Coefficient Set 1 Register */
/*! @{ */

#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF4_MASK    (0xFFU)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF4_SHIFT   (0U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF4(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS1_CAM_COEFF4_SHIFT)) & AUTOFOCUS_FIL_COEFFS1_CAM_COEFF4_MASK)

#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF5_MASK    (0xFF00U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF5_SHIFT   (8U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF5(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS1_CAM_COEFF5_SHIFT)) & AUTOFOCUS_FIL_COEFFS1_CAM_COEFF5_MASK)

#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF6_MASK    (0xFF0000U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF6_SHIFT   (16U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF6(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS1_CAM_COEFF6_SHIFT)) & AUTOFOCUS_FIL_COEFFS1_CAM_COEFF6_MASK)

#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF7_MASK    (0xFF000000U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF7_SHIFT   (24U)
#define AUTOFOCUS_FIL_COEFFS1_CAM_COEFF7(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS1_CAM_COEFF7_SHIFT)) & AUTOFOCUS_FIL_COEFFS1_CAM_COEFF7_MASK)
/*! @} */

/* The count of AUTOFOCUS_FIL_COEFFS1_CAM */
#define AUTOFOCUS_FIL_COEFFS1_CAM_COUNT          (1U)

/* The count of AUTOFOCUS_FIL_COEFFS1_CAM */
#define AUTOFOCUS_FIL_COEFFS1_CAM_COUNT2         (2U)

/*! @name FIL_COEFFS2_CAM - Camera 0 Autofocus Filter 0 Coefficient Set 2 Register..Camera 0 Autofocus Filter 1 Coefficient Set 2 Register */
/*! @{ */

#define AUTOFOCUS_FIL_COEFFS2_CAM_COEFF8_MASK    (0xFFU)
#define AUTOFOCUS_FIL_COEFFS2_CAM_COEFF8_SHIFT   (0U)
#define AUTOFOCUS_FIL_COEFFS2_CAM_COEFF8(x)      (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_COEFFS2_CAM_COEFF8_SHIFT)) & AUTOFOCUS_FIL_COEFFS2_CAM_COEFF8_MASK)
/*! @} */

/* The count of AUTOFOCUS_FIL_COEFFS2_CAM */
#define AUTOFOCUS_FIL_COEFFS2_CAM_COUNT          (1U)

/* The count of AUTOFOCUS_FIL_COEFFS2_CAM */
#define AUTOFOCUS_FIL_COEFFS2_CAM_COUNT2         (2U)

/*! @name FIL_SHIFT_CAM - Camera 0 Autofocus Filter 0 Shift Register..Camera 0 Autofocus Filter 1 Shift Register */
/*! @{ */

#define AUTOFOCUS_FIL_SHIFT_CAM_SHIFT_MASK       (0x1FU)
#define AUTOFOCUS_FIL_SHIFT_CAM_SHIFT_SHIFT      (0U)
#define AUTOFOCUS_FIL_SHIFT_CAM_SHIFT(x)         (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_FIL_SHIFT_CAM_SHIFT_SHIFT)) & AUTOFOCUS_FIL_SHIFT_CAM_SHIFT_MASK)
/*! @} */

/* The count of AUTOFOCUS_FIL_SHIFT_CAM */
#define AUTOFOCUS_FIL_SHIFT_CAM_COUNT            (1U)

/* The count of AUTOFOCUS_FIL_SHIFT_CAM */
#define AUTOFOCUS_FIL_SHIFT_CAM_COUNT2           (2U)

/*! @name ROI_SUM0_CAM - Camera 0 Autofocus ROI 0 SUM Filter 0 Register..Camera 0 Autofocus ROI 8 SUM Filter 0 Register */
/*! @{ */

#define AUTOFOCUS_ROI_SUM0_CAM_SUM_MASK          (0xFFFFFFFFU)
#define AUTOFOCUS_ROI_SUM0_CAM_SUM_SHIFT         (0U)
#define AUTOFOCUS_ROI_SUM0_CAM_SUM(x)            (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_ROI_SUM0_CAM_SUM_SHIFT)) & AUTOFOCUS_ROI_SUM0_CAM_SUM_MASK)
/*! @} */

/* The count of AUTOFOCUS_ROI_SUM0_CAM */
#define AUTOFOCUS_ROI_SUM0_CAM_COUNT             (1U)

/* The count of AUTOFOCUS_ROI_SUM0_CAM */
#define AUTOFOCUS_ROI_SUM0_CAM_COUNT2            (9U)

/*! @name ROI_SUM1_CAM - Camera 0 Autofocus ROI 0 SUM Filter 1 Register..Camera 0 Autofocus ROI 8 SUM Filter 1 Register */
/*! @{ */

#define AUTOFOCUS_ROI_SUM1_CAM_SUM_MASK          (0xFFFFFFFFU)
#define AUTOFOCUS_ROI_SUM1_CAM_SUM_SHIFT         (0U)
#define AUTOFOCUS_ROI_SUM1_CAM_SUM(x)            (((uint32_t)(((uint32_t)(x)) << AUTOFOCUS_ROI_SUM1_CAM_SUM_SHIFT)) & AUTOFOCUS_ROI_SUM1_CAM_SUM_MASK)
/*! @} */

/* The count of AUTOFOCUS_ROI_SUM1_CAM */
#define AUTOFOCUS_ROI_SUM1_CAM_COUNT             (1U)

/* The count of AUTOFOCUS_ROI_SUM1_CAM */
#define AUTOFOCUS_ROI_SUM1_CAM_COUNT2            (9U)


/*!
 * @}
 */ /* end of group AUTOFOCUS_Register_Masks */


/*!
 * @}
 */ /* end of group AUTOFOCUS_Peripheral_Access_Layer */


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


#endif  /* AUTOFOCUS_H_ */

