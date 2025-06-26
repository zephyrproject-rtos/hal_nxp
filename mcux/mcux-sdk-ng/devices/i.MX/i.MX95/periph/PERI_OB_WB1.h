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
**         CMSIS Peripheral Access Layer for OB_WB1
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
 * @file OB_WB1.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for OB_WB1
 *
 * CMSIS Peripheral Access Layer for OB_WB1
 */

#if !defined(OB_WB1_H_)
#define OB_WB1_H_                                /**< Symbol preventing repeated inclusion */

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
   -- OB_WB1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OB_WB1_Peripheral_Access_Layer OB_WB1 Peripheral Access Layer
 * @{
 */

/** OB_WB1 - Size of Registers Arrays */
#define OB_WB1_NEO_PIPE1_OB_WB_CONF_COUNT         1u

/** OB_WB1 - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x14 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 OB WB Control Register, array offset: 0x0, array step: 0x14 */
    __IO uint32_t R_CTRL_CAM;                        /**< Camera 0 OB_WB Red Channel Control Register, array offset: 0x4, array step: 0x14 */
    __IO uint32_t GR_CTRL_CAM;                       /**< Camera 0 OB_WB GreenR Channel Control Register, array offset: 0x8, array step: 0x14 */
    __IO uint32_t GB_CTRL_CAM;                       /**< Camera 0 OB_WB GreenB Channel Control Register, array offset: 0xC, array step: 0x14 */
    __IO uint32_t B_CTRL_CAM;                        /**< Camera 0 OB_WB Blue Channel Control Register, array offset: 0x10, array step: 0x14 */
  } NEO_PIPE1_OB_WB_CONF[OB_WB1_NEO_PIPE1_OB_WB_CONF_COUNT];
} OB_WB1_Type;

/* ----------------------------------------------------------------------------
   -- OB_WB1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OB_WB1_Register_Masks OB_WB1 Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 OB WB Control Register */
/*! @{ */

#define OB_WB1_CTRL_CAM_OBPP_MASK                (0xCU)
#define OB_WB1_CTRL_CAM_OBPP_SHIFT               (2U)
/*! OBPP
 *  0b00..12bpp
 *  0b01..14bpp
 *  0b10..16bpp
 */
#define OB_WB1_CTRL_CAM_OBPP(x)                  (((uint32_t)(((uint32_t)(x)) << OB_WB1_CTRL_CAM_OBPP_SHIFT)) & OB_WB1_CTRL_CAM_OBPP_MASK)
/*! @} */

/* The count of OB_WB1_CTRL_CAM */
#define OB_WB1_CTRL_CAM_COUNT                    (1U)

/*! @name R_CTRL_CAM - Camera 0 OB_WB Red Channel Control Register */
/*! @{ */

#define OB_WB1_R_CTRL_CAM_OFFSET_MASK            (0xFFFFU)
#define OB_WB1_R_CTRL_CAM_OFFSET_SHIFT           (0U)
#define OB_WB1_R_CTRL_CAM_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << OB_WB1_R_CTRL_CAM_OFFSET_SHIFT)) & OB_WB1_R_CTRL_CAM_OFFSET_MASK)

#define OB_WB1_R_CTRL_CAM_GAIN_MASK              (0xFFFF0000U)
#define OB_WB1_R_CTRL_CAM_GAIN_SHIFT             (16U)
#define OB_WB1_R_CTRL_CAM_GAIN(x)                (((uint32_t)(((uint32_t)(x)) << OB_WB1_R_CTRL_CAM_GAIN_SHIFT)) & OB_WB1_R_CTRL_CAM_GAIN_MASK)
/*! @} */

/* The count of OB_WB1_R_CTRL_CAM */
#define OB_WB1_R_CTRL_CAM_COUNT                  (1U)

/*! @name GR_CTRL_CAM - Camera 0 OB_WB GreenR Channel Control Register */
/*! @{ */

#define OB_WB1_GR_CTRL_CAM_OFFSET_MASK           (0xFFFFU)
#define OB_WB1_GR_CTRL_CAM_OFFSET_SHIFT          (0U)
#define OB_WB1_GR_CTRL_CAM_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << OB_WB1_GR_CTRL_CAM_OFFSET_SHIFT)) & OB_WB1_GR_CTRL_CAM_OFFSET_MASK)

#define OB_WB1_GR_CTRL_CAM_GAIN_MASK             (0xFFFF0000U)
#define OB_WB1_GR_CTRL_CAM_GAIN_SHIFT            (16U)
#define OB_WB1_GR_CTRL_CAM_GAIN(x)               (((uint32_t)(((uint32_t)(x)) << OB_WB1_GR_CTRL_CAM_GAIN_SHIFT)) & OB_WB1_GR_CTRL_CAM_GAIN_MASK)
/*! @} */

/* The count of OB_WB1_GR_CTRL_CAM */
#define OB_WB1_GR_CTRL_CAM_COUNT                 (1U)

/*! @name GB_CTRL_CAM - Camera 0 OB_WB GreenB Channel Control Register */
/*! @{ */

#define OB_WB1_GB_CTRL_CAM_OFFSET_MASK           (0xFFFFU)
#define OB_WB1_GB_CTRL_CAM_OFFSET_SHIFT          (0U)
#define OB_WB1_GB_CTRL_CAM_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << OB_WB1_GB_CTRL_CAM_OFFSET_SHIFT)) & OB_WB1_GB_CTRL_CAM_OFFSET_MASK)

#define OB_WB1_GB_CTRL_CAM_GAIN_MASK             (0xFFFF0000U)
#define OB_WB1_GB_CTRL_CAM_GAIN_SHIFT            (16U)
#define OB_WB1_GB_CTRL_CAM_GAIN(x)               (((uint32_t)(((uint32_t)(x)) << OB_WB1_GB_CTRL_CAM_GAIN_SHIFT)) & OB_WB1_GB_CTRL_CAM_GAIN_MASK)
/*! @} */

/* The count of OB_WB1_GB_CTRL_CAM */
#define OB_WB1_GB_CTRL_CAM_COUNT                 (1U)

/*! @name B_CTRL_CAM - Camera 0 OB_WB Blue Channel Control Register */
/*! @{ */

#define OB_WB1_B_CTRL_CAM_OFFSET_MASK            (0xFFFFU)
#define OB_WB1_B_CTRL_CAM_OFFSET_SHIFT           (0U)
#define OB_WB1_B_CTRL_CAM_OFFSET(x)              (((uint32_t)(((uint32_t)(x)) << OB_WB1_B_CTRL_CAM_OFFSET_SHIFT)) & OB_WB1_B_CTRL_CAM_OFFSET_MASK)

#define OB_WB1_B_CTRL_CAM_GAIN_MASK              (0xFFFF0000U)
#define OB_WB1_B_CTRL_CAM_GAIN_SHIFT             (16U)
#define OB_WB1_B_CTRL_CAM_GAIN(x)                (((uint32_t)(((uint32_t)(x)) << OB_WB1_B_CTRL_CAM_GAIN_SHIFT)) & OB_WB1_B_CTRL_CAM_GAIN_MASK)
/*! @} */

/* The count of OB_WB1_B_CTRL_CAM */
#define OB_WB1_B_CTRL_CAM_COUNT                  (1U)


/*!
 * @}
 */ /* end of group OB_WB1_Register_Masks */


/*!
 * @}
 */ /* end of group OB_WB1_Peripheral_Access_Layer */


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


#endif  /* OB_WB1_H_ */

