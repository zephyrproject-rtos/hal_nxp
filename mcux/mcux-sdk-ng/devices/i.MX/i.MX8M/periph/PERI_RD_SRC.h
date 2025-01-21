/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 4.0, 2018-01-26
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RD_SRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**
** ###################################################################
*/

/*!
 * @file RD_SRC.h
 * @version 4.0
 * @date 2018-01-26
 * @brief CMSIS Peripheral Access Layer for RD_SRC
 *
 * CMSIS Peripheral Access Layer for RD_SRC
 */

#if !defined(RD_SRC_H_)
#define RD_SRC_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- RD_SRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RD_SRC_Peripheral_Access_Layer RD_SRC Peripheral Access Layer
 * @{
 */

/** RD_SRC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control register for Read surface., offset: 0x0 */
    __IO uint32_t SET;                               /**< Control register for Read surface., offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control register for Read surface., offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control register for Read surface., offset: 0xC */
  } CTRL_STATUS;
  __IO uint32_t BASE_ADDR;                         /**< Read Surface Base address, offset: 0x10 */
  __IO uint32_t PITCH;                             /**< Read surface vertical pitch, offset: 0x14 */
  __IO uint32_t WIDTH;                             /**< Source frame buffer width, offset: 0x18 */
  __IO uint32_t HEIGHT;                            /**< Height of frame to be read, offset: 0x1C */
} RD_SRC_Type;

/* ----------------------------------------------------------------------------
   -- RD_SRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RD_SRC_Register_Masks RD_SRC Register Masks
 * @{
 */

/*! @name CTRL_STATUS - Control register for Read surface. */
/*! @{ */

#define RD_SRC_CTRL_STATUS_ENABLE_MASK           (0x1U)
#define RD_SRC_CTRL_STATUS_ENABLE_SHIFT          (0U)
/*! ENABLE - Read surface enable. */
#define RD_SRC_CTRL_STATUS_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_ENABLE_SHIFT)) & RD_SRC_CTRL_STATUS_ENABLE_MASK)

#define RD_SRC_CTRL_STATUS_BPP_MASK              (0x1CU)
#define RD_SRC_CTRL_STATUS_BPP_SHIFT             (2U)
/*! BPP - Bits per pixel */
#define RD_SRC_CTRL_STATUS_BPP(x)                (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_BPP_SHIFT)) & RD_SRC_CTRL_STATUS_BPP_MASK)

#define RD_SRC_CTRL_STATUS_T_SIZE_MASK           (0x60U)
#define RD_SRC_CTRL_STATUS_T_SIZE_SHIFT          (5U)
/*! T_SIZE - Transaction Size (T_SIZE) */
#define RD_SRC_CTRL_STATUS_T_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_T_SIZE_SHIFT)) & RD_SRC_CTRL_STATUS_T_SIZE_MASK)

#define RD_SRC_CTRL_STATUS_P_SIZE_MASK           (0x380U)
#define RD_SRC_CTRL_STATUS_P_SIZE_SHIFT          (7U)
/*! P_SIZE - Payload size (P_SIZE) */
#define RD_SRC_CTRL_STATUS_P_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_P_SIZE_SHIFT)) & RD_SRC_CTRL_STATUS_P_SIZE_MASK)

#define RD_SRC_CTRL_STATUS_FRAME_COMP_EN_MASK    (0x4000U)
#define RD_SRC_CTRL_STATUS_FRAME_COMP_EN_SHIFT   (14U)
/*! FRAME_COMP_EN - Frame complete IRQ enable */
#define RD_SRC_CTRL_STATUS_FRAME_COMP_EN(x)      (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_FRAME_COMP_EN_SHIFT)) & RD_SRC_CTRL_STATUS_FRAME_COMP_EN_MASK)

#define RD_SRC_CTRL_STATUS_RD_ERR_EN_MASK        (0x8000U)
#define RD_SRC_CTRL_STATUS_RD_ERR_EN_SHIFT       (15U)
/*! RD_ERR_EN - AXI Read Error IRQ enable */
#define RD_SRC_CTRL_STATUS_RD_ERR_EN(x)          (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_RD_ERR_EN_SHIFT)) & RD_SRC_CTRL_STATUS_RD_ERR_EN_MASK)

#define RD_SRC_CTRL_STATUS_FIFO_SIZE_MASK        (0x7F0000U)
#define RD_SRC_CTRL_STATUS_FIFO_SIZE_SHIFT       (16U)
/*! FIFO_SIZE - FIFO size */
#define RD_SRC_CTRL_STATUS_FIFO_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_FIFO_SIZE_SHIFT)) & RD_SRC_CTRL_STATUS_FIFO_SIZE_MASK)

#define RD_SRC_CTRL_STATUS_FRAME_COMP_MASK       (0x40000000U)
#define RD_SRC_CTRL_STATUS_FRAME_COMP_SHIFT      (30U)
/*! FRAME_COMP - Frame processing complete */
#define RD_SRC_CTRL_STATUS_FRAME_COMP(x)         (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_FRAME_COMP_SHIFT)) & RD_SRC_CTRL_STATUS_FRAME_COMP_MASK)

#define RD_SRC_CTRL_STATUS_RD_ERR_MASK           (0x80000000U)
#define RD_SRC_CTRL_STATUS_RD_ERR_SHIFT          (31U)
/*! RD_ERR - AXI Read Error */
#define RD_SRC_CTRL_STATUS_RD_ERR(x)             (((uint32_t)(((uint32_t)(x)) << RD_SRC_CTRL_STATUS_RD_ERR_SHIFT)) & RD_SRC_CTRL_STATUS_RD_ERR_MASK)
/*! @} */

/*! @name BASE_ADDR - Read Surface Base address */
/*! @{ */

#define RD_SRC_BASE_ADDR_BASE_ADDR_MASK          (0xFFFFFFFFU)
#define RD_SRC_BASE_ADDR_BASE_ADDR_SHIFT         (0U)
/*! BASE_ADDR - Base address */
#define RD_SRC_BASE_ADDR_BASE_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << RD_SRC_BASE_ADDR_BASE_ADDR_SHIFT)) & RD_SRC_BASE_ADDR_BASE_ADDR_MASK)
/*! @} */

/*! @name PITCH - Read surface vertical pitch */
/*! @{ */

#define RD_SRC_PITCH_PITCH_MASK                  (0xFFFFU)
#define RD_SRC_PITCH_PITCH_SHIFT                 (0U)
/*! PITCH - Pitch */
#define RD_SRC_PITCH_PITCH(x)                    (((uint32_t)(((uint32_t)(x)) << RD_SRC_PITCH_PITCH_SHIFT)) & RD_SRC_PITCH_PITCH_MASK)
/*! @} */

/*! @name WIDTH - Source frame buffer width */
/*! @{ */

#define RD_SRC_WIDTH_WIDTH_MASK                  (0xFFFFU)
#define RD_SRC_WIDTH_WIDTH_SHIFT                 (0U)
/*! WIDTH - Width */
#define RD_SRC_WIDTH_WIDTH(x)                    (((uint32_t)(((uint32_t)(x)) << RD_SRC_WIDTH_WIDTH_SHIFT)) & RD_SRC_WIDTH_WIDTH_MASK)
/*! @} */

/*! @name HEIGHT - Height of frame to be read */
/*! @{ */

#define RD_SRC_HEIGHT_HEIGHT_MASK                (0xFFFFU)
#define RD_SRC_HEIGHT_HEIGHT_SHIFT               (0U)
/*! HEIGHT - Height */
#define RD_SRC_HEIGHT_HEIGHT(x)                  (((uint32_t)(((uint32_t)(x)) << RD_SRC_HEIGHT_HEIGHT_SHIFT)) & RD_SRC_HEIGHT_HEIGHT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RD_SRC_Register_Masks */


/*!
 * @}
 */ /* end of group RD_SRC_Peripheral_Access_Layer */


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


#endif  /* RD_SRC_H_ */

