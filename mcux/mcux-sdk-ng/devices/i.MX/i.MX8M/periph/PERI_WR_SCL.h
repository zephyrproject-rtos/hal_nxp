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
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WR_SCL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WR_SCL.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WR_SCL
 *
 * CMSIS Peripheral Access Layer for WR_SCL
 */

#if !defined(PERI_WR_SCL_H_)
#define PERI_WR_SCL_H_                           /**< Symbol preventing repeated inclusion */

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
   -- WR_SCL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WR_SCL_Peripheral_Access_Layer WR_SCL Peripheral Access Layer
 * @{
 */

/** WR_SCL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control register for Context Loader., offset: 0x0 */
    __IO uint32_t SET;                               /**< Control register for Context Loader., offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control register for Context Loader., offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control register for Context Loader., offset: 0xC */
  } CTRL_STATUS;
  __IO uint32_t BASE_ADDR;                         /**< Holds the base address, offset: 0x10 */
  __IO uint32_t PITCH;                             /**< Pitch, offset: 0x14 */
} WR_SCL_Type;

/* ----------------------------------------------------------------------------
   -- WR_SCL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WR_SCL_Register_Masks WR_SCL Register Masks
 * @{
 */

/*! @name CTRL_STATUS - Control register for Context Loader. */
/*! @{ */

#define WR_SCL_CTRL_STATUS_ENABLE_MASK           (0x1U)
#define WR_SCL_CTRL_STATUS_ENABLE_SHIFT          (0U)
/*! ENABLE - Enable / Busy */
#define WR_SCL_CTRL_STATUS_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_ENABLE_SHIFT)) & WR_SCL_CTRL_STATUS_ENABLE_MASK)

#define WR_SCL_CTRL_STATUS_REPEAT_MASK           (0x2U)
#define WR_SCL_CTRL_STATUS_REPEAT_SHIFT          (1U)
/*! REPEAT - Repeat feature */
#define WR_SCL_CTRL_STATUS_REPEAT(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_REPEAT_SHIFT)) & WR_SCL_CTRL_STATUS_REPEAT_MASK)

#define WR_SCL_CTRL_STATUS_BPP_MASK              (0x1CU)
#define WR_SCL_CTRL_STATUS_BPP_SHIFT             (2U)
/*! BPP - Bits per pixel */
#define WR_SCL_CTRL_STATUS_BPP(x)                (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_BPP_SHIFT)) & WR_SCL_CTRL_STATUS_BPP_MASK)

#define WR_SCL_CTRL_STATUS_T_SIZE_MASK           (0x60U)
#define WR_SCL_CTRL_STATUS_T_SIZE_SHIFT          (5U)
/*! T_SIZE - Transaction Size */
#define WR_SCL_CTRL_STATUS_T_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_T_SIZE_SHIFT)) & WR_SCL_CTRL_STATUS_T_SIZE_MASK)

#define WR_SCL_CTRL_STATUS_P_SIZE_MASK           (0x380U)
#define WR_SCL_CTRL_STATUS_P_SIZE_SHIFT          (7U)
/*! P_SIZE - Payload Size */
#define WR_SCL_CTRL_STATUS_P_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_P_SIZE_SHIFT)) & WR_SCL_CTRL_STATUS_P_SIZE_MASK)

#define WR_SCL_CTRL_STATUS_P_FREQ_MASK           (0x3FC00U)
#define WR_SCL_CTRL_STATUS_P_FREQ_SHIFT          (10U)
/*! P_FREQ - Payload frequency */
#define WR_SCL_CTRL_STATUS_P_FREQ(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_P_FREQ_SHIFT)) & WR_SCL_CTRL_STATUS_P_FREQ_MASK)

#define WR_SCL_CTRL_STATUS_FIFO_SIZE_MASK        (0x1FC0000U)
#define WR_SCL_CTRL_STATUS_FIFO_SIZE_SHIFT       (18U)
/*! FIFO_SIZE - Size of FIFO in design */
#define WR_SCL_CTRL_STATUS_FIFO_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_FIFO_SIZE_SHIFT)) & WR_SCL_CTRL_STATUS_FIFO_SIZE_MASK)

#define WR_SCL_CTRL_STATUS_FRAME_COMP_EN_MASK    (0x10000000U)
#define WR_SCL_CTRL_STATUS_FRAME_COMP_EN_SHIFT   (28U)
/*! FRAME_COMP_EN - Write error IRQ enable */
#define WR_SCL_CTRL_STATUS_FRAME_COMP_EN(x)      (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_FRAME_COMP_EN_SHIFT)) & WR_SCL_CTRL_STATUS_FRAME_COMP_EN_MASK)

#define WR_SCL_CTRL_STATUS_FRAME_COMP_MASK       (0x20000000U)
#define WR_SCL_CTRL_STATUS_FRAME_COMP_SHIFT      (29U)
/*! FRAME_COMP - Indicates the current frame being processed has finished. */
#define WR_SCL_CTRL_STATUS_FRAME_COMP(x)         (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_FRAME_COMP_SHIFT)) & WR_SCL_CTRL_STATUS_FRAME_COMP_MASK)

#define WR_SCL_CTRL_STATUS_WR_ERR_EN_MASK        (0x40000000U)
#define WR_SCL_CTRL_STATUS_WR_ERR_EN_SHIFT       (30U)
/*! WR_ERR_EN - Write error IRQ enable */
#define WR_SCL_CTRL_STATUS_WR_ERR_EN(x)          (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_WR_ERR_EN_SHIFT)) & WR_SCL_CTRL_STATUS_WR_ERR_EN_MASK)

#define WR_SCL_CTRL_STATUS_WR_ERR_MASK           (0x80000000U)
#define WR_SCL_CTRL_STATUS_WR_ERR_SHIFT          (31U)
/*! WR_ERR - Indicates a write error on the axi interface. */
#define WR_SCL_CTRL_STATUS_WR_ERR(x)             (((uint32_t)(((uint32_t)(x)) << WR_SCL_CTRL_STATUS_WR_ERR_SHIFT)) & WR_SCL_CTRL_STATUS_WR_ERR_MASK)
/*! @} */

/*! @name BASE_ADDR - Holds the base address */
/*! @{ */

#define WR_SCL_BASE_ADDR_BASE_ADDR_MASK          (0xFFFFFFFFU)
#define WR_SCL_BASE_ADDR_BASE_ADDR_SHIFT         (0U)
/*! BASE_ADDR - Base address */
#define WR_SCL_BASE_ADDR_BASE_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << WR_SCL_BASE_ADDR_BASE_ADDR_SHIFT)) & WR_SCL_BASE_ADDR_BASE_ADDR_MASK)
/*! @} */

/*! @name PITCH - Pitch */
/*! @{ */

#define WR_SCL_PITCH_PITCH_MASK                  (0xFFFFU)
#define WR_SCL_PITCH_PITCH_SHIFT                 (0U)
/*! PITCH - Vertical pitch for memory address calculation. */
#define WR_SCL_PITCH_PITCH(x)                    (((uint32_t)(((uint32_t)(x)) << WR_SCL_PITCH_PITCH_SHIFT)) & WR_SCL_PITCH_PITCH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WR_SCL_Register_Masks */


/*!
 * @}
 */ /* end of group WR_SCL_Peripheral_Access_Layer */


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


#endif  /* PERI_WR_SCL_H_ */

