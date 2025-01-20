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
**         CMSIS Peripheral Access Layer for EE
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
 * @file EE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for EE
 *
 * CMSIS Peripheral Access Layer for EE
 */

#if !defined(EE_H_)
#define EE_H_                                    /**< Symbol preventing repeated inclusion */

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
   -- EE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EE_Peripheral_Access_Layer EE Peripheral Access Layer
 * @{
 */

/** EE - Size of Registers Arrays */
#define EE_NEO_PIPE2_EE_CONF_COUNT                1u

/** EE - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x14 */
    __IO uint32_t CTRL_CAM;                          /**< Camera 0 EE Control Register, array offset: 0x0, array step: 0x14 */
    __IO uint32_t CORING_CAM;                        /**< Camera 0 EE Coring Register, array offset: 0x4, array step: 0x14 */
    __IO uint32_t CLIP_CAM;                          /**< Camera 0 EE Clip Register, array offset: 0x8, array step: 0x14 */
    __IO uint32_t MASKGAIN_CAM;                      /**< Camera 0 EE Mask Gain Register, array offset: 0xC, array step: 0x14 */
    __I  uint32_t EDGECNT_CAM;                       /**< Camera 0 EE Edge Count Register, array offset: 0x10, array step: 0x14 */
  } NEO_PIPE2_EE_CONF[EE_NEO_PIPE2_EE_CONF_COUNT];
} EE_Type;

/* ----------------------------------------------------------------------------
   -- EE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EE_Register_Masks EE Register Masks
 * @{
 */

/*! @name CTRL_CAM - Camera 0 EE Control Register */
/*! @{ */

#define EE_CTRL_CAM_DEBUG_MASK                   (0x300U)
#define EE_CTRL_CAM_DEBUG_SHIFT                  (8U)
/*! DEBUG - Debug / Tuning view
 *  0b00..off
 *  0b01..edge pixels+texture
 *  0b10..edge pixels+black
 */
#define EE_CTRL_CAM_DEBUG(x)                     (((uint32_t)(((uint32_t)(x)) << EE_CTRL_CAM_DEBUG_SHIFT)) & EE_CTRL_CAM_DEBUG_MASK)

#define EE_CTRL_CAM_ENABLE_MASK                  (0x80000000U)
#define EE_CTRL_CAM_ENABLE_SHIFT                 (31U)
/*! ENABLE
 *  0b0..off
 *  0b1..on
 */
#define EE_CTRL_CAM_ENABLE(x)                    (((uint32_t)(((uint32_t)(x)) << EE_CTRL_CAM_ENABLE_SHIFT)) & EE_CTRL_CAM_ENABLE_MASK)
/*! @} */

/* The count of EE_CTRL_CAM */
#define EE_CTRL_CAM_COUNT                        (1U)

/*! @name CORING_CAM - Camera 0 EE Coring Register */
/*! @{ */

#define EE_CORING_CAM_CORING_MASK                (0xFFFFFU)
#define EE_CORING_CAM_CORING_SHIFT               (0U)
#define EE_CORING_CAM_CORING(x)                  (((uint32_t)(((uint32_t)(x)) << EE_CORING_CAM_CORING_SHIFT)) & EE_CORING_CAM_CORING_MASK)
/*! @} */

/* The count of EE_CORING_CAM */
#define EE_CORING_CAM_COUNT                      (1U)

/*! @name CLIP_CAM - Camera 0 EE Clip Register */
/*! @{ */

#define EE_CLIP_CAM_CLIP_MASK                    (0xFFFFFU)
#define EE_CLIP_CAM_CLIP_SHIFT                   (0U)
#define EE_CLIP_CAM_CLIP(x)                      (((uint32_t)(((uint32_t)(x)) << EE_CLIP_CAM_CLIP_SHIFT)) & EE_CLIP_CAM_CLIP_MASK)
/*! @} */

/* The count of EE_CLIP_CAM */
#define EE_CLIP_CAM_COUNT                        (1U)

/*! @name MASKGAIN_CAM - Camera 0 EE Mask Gain Register */
/*! @{ */

#define EE_MASKGAIN_CAM_GAIN_MASK                (0xFFU)
#define EE_MASKGAIN_CAM_GAIN_SHIFT               (0U)
#define EE_MASKGAIN_CAM_GAIN(x)                  (((uint32_t)(((uint32_t)(x)) << EE_MASKGAIN_CAM_GAIN_SHIFT)) & EE_MASKGAIN_CAM_GAIN_MASK)
/*! @} */

/* The count of EE_MASKGAIN_CAM */
#define EE_MASKGAIN_CAM_COUNT                    (1U)

/*! @name EDGECNT_CAM - Camera 0 EE Edge Count Register */
/*! @{ */

#define EE_EDGECNT_CAM_EDGE_PIXELS_MASK          (0xFFFFFFU)
#define EE_EDGECNT_CAM_EDGE_PIXELS_SHIFT         (0U)
#define EE_EDGECNT_CAM_EDGE_PIXELS(x)            (((uint32_t)(((uint32_t)(x)) << EE_EDGECNT_CAM_EDGE_PIXELS_SHIFT)) & EE_EDGECNT_CAM_EDGE_PIXELS_MASK)
/*! @} */

/* The count of EE_EDGECNT_CAM */
#define EE_EDGECNT_CAM_COUNT                     (1U)


/*!
 * @}
 */ /* end of group EE_Register_Masks */


/*!
 * @}
 */ /* end of group EE_Peripheral_Access_Layer */


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


#endif  /* EE_H_ */

