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
**         CMSIS Peripheral Access Layer for CCM
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
 * @file PERI_CCM.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CCM
 *
 * CMSIS Peripheral Access Layer for CCM
 */

#if !defined(PERI_CCM_H_)
#define PERI_CCM_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Peripheral_Access_Layer CCM Peripheral Access Layer
 * @{
 */

/** CCM - Size of Registers Arrays */
#define CCM_PLL_CTRL_COUNT                        39u
#define CCM_CCGR_COUNT                            191u
#define CCM_ROOT_COUNT                            142u

/** CCM - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR0;                              /**< General Purpose Register, offset: 0x0 */
  __IO uint32_t GPR0_SET;                          /**< General Purpose Register, offset: 0x4 */
  __IO uint32_t GPR0_CLR;                          /**< General Purpose Register, offset: 0x8 */
  __IO uint32_t GPR0_TOG;                          /**< General Purpose Register, offset: 0xC */
       uint8_t RESERVED_0[2032];
  struct {                                         /* offset: 0x800, array step: 0x10 */
    __IO uint32_t PLL_CTRL;                          /**< CCM PLL Control Register, array offset: 0x800, array step: 0x10 */
    __IO uint32_t PLL_CTRL_SET;                      /**< CCM PLL Control Register, array offset: 0x804, array step: 0x10 */
    __IO uint32_t PLL_CTRL_CLR;                      /**< CCM PLL Control Register, array offset: 0x808, array step: 0x10 */
    __IO uint32_t PLL_CTRL_TOG;                      /**< CCM PLL Control Register, array offset: 0x80C, array step: 0x10 */
  } PLL_CTRL[CCM_PLL_CTRL_COUNT];
       uint8_t RESERVED_1[13712];
  struct {                                         /* offset: 0x4000, array step: 0x10 */
    __IO uint32_t CCGR;                              /**< CCM Clock Gating Register, array offset: 0x4000, array step: 0x10 */
    __IO uint32_t CCGR_SET;                          /**< CCM Clock Gating Register, array offset: 0x4004, array step: 0x10 */
    __IO uint32_t CCGR_CLR;                          /**< CCM Clock Gating Register, array offset: 0x4008, array step: 0x10 */
    __IO uint32_t CCGR_TOG;                          /**< CCM Clock Gating Register, array offset: 0x400C, array step: 0x10 */
  } CCGR[CCM_CCGR_COUNT];
       uint8_t RESERVED_2[13328];
  struct {                                         /* offset: 0x8000, array step: 0x80 */
    __IO uint32_t TARGET_ROOT;                       /**< Target Register, array offset: 0x8000, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t TARGET_ROOT_SET;                   /**< Target Register, array offset: 0x8004, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t TARGET_ROOT_CLR;                   /**< Target Register, array offset: 0x8008, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t TARGET_ROOT_TOG;                   /**< Target Register, array offset: 0x800C, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t MISC;                              /**< Miscellaneous Register, array offset: 0x8010, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t MISC_ROOT_SET;                     /**< Miscellaneous Register, array offset: 0x8014, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t MISC_ROOT_CLR;                     /**< Miscellaneous Register, array offset: 0x8018, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t MISC_ROOT_TOG;                     /**< Miscellaneous Register, array offset: 0x801C, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t POST;                              /**< Post Divider Register, array offset: 0x8020, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t POST_ROOT_SET;                     /**< Post Divider Register, array offset: 0x8024, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t POST_ROOT_CLR;                     /**< Post Divider Register, array offset: 0x8028, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t POST_ROOT_TOG;                     /**< Post Divider Register, array offset: 0x802C, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t PRE;                               /**< Pre Divider Register, array offset: 0x8030, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t PRE_ROOT_SET;                      /**< Pre Divider Register, array offset: 0x8034, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t PRE_ROOT_CLR;                      /**< Pre Divider Register, array offset: 0x8038, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t PRE_ROOT_TOG;                      /**< Pre Divider Register, array offset: 0x803C, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
         uint8_t RESERVED_0[48];
    __IO uint32_t ACCESS_CTRL;                       /**< Access Control Register, array offset: 0x8070, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t ACCESS_CTRL_ROOT_SET;              /**< Access Control Register, array offset: 0x8074, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t ACCESS_CTRL_ROOT_CLR;              /**< Access Control Register, array offset: 0x8078, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
    __IO uint32_t ACCESS_CTRL_ROOT_TOG;              /**< Access Control Register, array offset: 0x807C, array step: 0x80, valid indices: [0-4, 16-27, 32-37, 48-49, 64-141] */
  } ROOT[CCM_ROOT_COUNT];
} CCM_Type;

/* ----------------------------------------------------------------------------
   -- CCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CCM_Register_Masks CCM Register Masks
 * @{
 */

/*! @name GPR0 - General Purpose Register */
/*! @{ */

#define CCM_GPR0_GP0_MASK                        (0xFFFFFFFFU)
#define CCM_GPR0_GP0_SHIFT                       (0U)
#define CCM_GPR0_GP0(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_GP0_SHIFT)) & CCM_GPR0_GP0_MASK)
/*! @} */

/*! @name GPR0_SET - General Purpose Register */
/*! @{ */

#define CCM_GPR0_SET_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_SET_GP0_SHIFT                   (0U)
#define CCM_GPR0_SET_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_SET_GP0_SHIFT)) & CCM_GPR0_SET_GP0_MASK)
/*! @} */

/*! @name GPR0_CLR - General Purpose Register */
/*! @{ */

#define CCM_GPR0_CLR_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_CLR_GP0_SHIFT                   (0U)
#define CCM_GPR0_CLR_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_CLR_GP0_SHIFT)) & CCM_GPR0_CLR_GP0_MASK)
/*! @} */

/*! @name GPR0_TOG - General Purpose Register */
/*! @{ */

#define CCM_GPR0_TOG_GP0_MASK                    (0xFFFFFFFFU)
#define CCM_GPR0_TOG_GP0_SHIFT                   (0U)
#define CCM_GPR0_TOG_GP0(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_GPR0_TOG_GP0_SHIFT)) & CCM_GPR0_TOG_GP0_MASK)
/*! @} */

/*! @name PLL_CTRL - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_SETTING0_MASK               (0x3U)
#define CCM_PLL_CTRL_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING0_SHIFT)) & CCM_PLL_CTRL_SETTING0_MASK)

#define CCM_PLL_CTRL_SETTING1_MASK               (0x30U)
#define CCM_PLL_CTRL_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING1_SHIFT)) & CCM_PLL_CTRL_SETTING1_MASK)

#define CCM_PLL_CTRL_SETTING2_MASK               (0x300U)
#define CCM_PLL_CTRL_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING2_SHIFT)) & CCM_PLL_CTRL_SETTING2_MASK)

#define CCM_PLL_CTRL_SETTING3_MASK               (0x3000U)
#define CCM_PLL_CTRL_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SETTING3_SHIFT)) & CCM_PLL_CTRL_SETTING3_MASK)
/*! @} */

/*! @name PLL_CTRL_SET - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_SET_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_SET_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING0_SHIFT)) & CCM_PLL_CTRL_SET_SETTING0_MASK)

#define CCM_PLL_CTRL_SET_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_SET_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING1_SHIFT)) & CCM_PLL_CTRL_SET_SETTING1_MASK)

#define CCM_PLL_CTRL_SET_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_SET_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING2_SHIFT)) & CCM_PLL_CTRL_SET_SETTING2_MASK)

#define CCM_PLL_CTRL_SET_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_SET_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_SET_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_SET_SETTING3_SHIFT)) & CCM_PLL_CTRL_SET_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_SET */
#define CCM_PLL_CTRL_SET_COUNT                   (39U)

/*! @name PLL_CTRL_CLR - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_CLR_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_CLR_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING0_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING0_MASK)

#define CCM_PLL_CTRL_CLR_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_CLR_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING1_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING1_MASK)

#define CCM_PLL_CTRL_CLR_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_CLR_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING2_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING2_MASK)

#define CCM_PLL_CTRL_CLR_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_CLR_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_CLR_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_CLR_SETTING3_SHIFT)) & CCM_PLL_CTRL_CLR_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_CLR */
#define CCM_PLL_CTRL_CLR_COUNT                   (39U)

/*! @name PLL_CTRL_TOG - CCM PLL Control Register */
/*! @{ */

#define CCM_PLL_CTRL_TOG_SETTING0_MASK           (0x3U)
#define CCM_PLL_CTRL_TOG_SETTING0_SHIFT          (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING0(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING0_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING0_MASK)

#define CCM_PLL_CTRL_TOG_SETTING1_MASK           (0x30U)
#define CCM_PLL_CTRL_TOG_SETTING1_SHIFT          (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING1(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING1_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING1_MASK)

#define CCM_PLL_CTRL_TOG_SETTING2_MASK           (0x300U)
#define CCM_PLL_CTRL_TOG_SETTING2_SHIFT          (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING2(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING2_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING2_MASK)

#define CCM_PLL_CTRL_TOG_SETTING3_MASK           (0x3000U)
#define CCM_PLL_CTRL_TOG_SETTING3_SHIFT          (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_PLL_CTRL_TOG_SETTING3(x)             (((uint32_t)(((uint32_t)(x)) << CCM_PLL_CTRL_TOG_SETTING3_SHIFT)) & CCM_PLL_CTRL_TOG_SETTING3_MASK)
/*! @} */

/* The count of CCM_PLL_CTRL_TOG */
#define CCM_PLL_CTRL_TOG_COUNT                   (39U)

/*! @name CCGR - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_SETTING0_MASK                   (0x3U)
#define CCM_CCGR_SETTING0_SHIFT                  (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING0(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING0_SHIFT)) & CCM_CCGR_SETTING0_MASK)

#define CCM_CCGR_SETTING1_MASK                   (0x30U)
#define CCM_CCGR_SETTING1_SHIFT                  (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING1(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING1_SHIFT)) & CCM_CCGR_SETTING1_MASK)

#define CCM_CCGR_SETTING2_MASK                   (0x300U)
#define CCM_CCGR_SETTING2_SHIFT                  (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING2(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING2_SHIFT)) & CCM_CCGR_SETTING2_MASK)

#define CCM_CCGR_SETTING3_MASK                   (0x3000U)
#define CCM_CCGR_SETTING3_SHIFT                  (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SETTING3(x)                     (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SETTING3_SHIFT)) & CCM_CCGR_SETTING3_MASK)
/*! @} */

/*! @name CCGR_SET - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_SET_SETTING0_MASK               (0x3U)
#define CCM_CCGR_SET_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING0_SHIFT)) & CCM_CCGR_SET_SETTING0_MASK)

#define CCM_CCGR_SET_SETTING1_MASK               (0x30U)
#define CCM_CCGR_SET_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING1_SHIFT)) & CCM_CCGR_SET_SETTING1_MASK)

#define CCM_CCGR_SET_SETTING2_MASK               (0x300U)
#define CCM_CCGR_SET_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING2_SHIFT)) & CCM_CCGR_SET_SETTING2_MASK)

#define CCM_CCGR_SET_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_SET_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_SET_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_SET_SETTING3_SHIFT)) & CCM_CCGR_SET_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_SET */
#define CCM_CCGR_SET_COUNT                       (191U)

/*! @name CCGR_CLR - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_CLR_SETTING0_MASK               (0x3U)
#define CCM_CCGR_CLR_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING0_SHIFT)) & CCM_CCGR_CLR_SETTING0_MASK)

#define CCM_CCGR_CLR_SETTING1_MASK               (0x30U)
#define CCM_CCGR_CLR_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING1_SHIFT)) & CCM_CCGR_CLR_SETTING1_MASK)

#define CCM_CCGR_CLR_SETTING2_MASK               (0x300U)
#define CCM_CCGR_CLR_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING2_SHIFT)) & CCM_CCGR_CLR_SETTING2_MASK)

#define CCM_CCGR_CLR_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_CLR_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_CLR_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_CLR_SETTING3_SHIFT)) & CCM_CCGR_CLR_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_CLR */
#define CCM_CCGR_CLR_COUNT                       (191U)

/*! @name CCGR_TOG - CCM Clock Gating Register */
/*! @{ */

#define CCM_CCGR_TOG_SETTING0_MASK               (0x3U)
#define CCM_CCGR_TOG_SETTING0_SHIFT              (0U)
/*! SETTING0
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING0(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING0_SHIFT)) & CCM_CCGR_TOG_SETTING0_MASK)

#define CCM_CCGR_TOG_SETTING1_MASK               (0x30U)
#define CCM_CCGR_TOG_SETTING1_SHIFT              (4U)
/*! SETTING1
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING1(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING1_SHIFT)) & CCM_CCGR_TOG_SETTING1_MASK)

#define CCM_CCGR_TOG_SETTING2_MASK               (0x300U)
#define CCM_CCGR_TOG_SETTING2_SHIFT              (8U)
/*! SETTING2
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING2(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING2_SHIFT)) & CCM_CCGR_TOG_SETTING2_MASK)

#define CCM_CCGR_TOG_SETTING3_MASK               (0x3000U)
#define CCM_CCGR_TOG_SETTING3_SHIFT              (12U)
/*! SETTING3
 *  0b00..Domain clocks not needed
 *  0b01..Domain clocks needed when in RUN
 *  0b10..Domain clocks needed when in RUN and WAIT
 *  0b11..Domain clocks needed all the time
 */
#define CCM_CCGR_TOG_SETTING3(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_CCGR_TOG_SETTING3_SHIFT)) & CCM_CCGR_TOG_SETTING3_MASK)
/*! @} */

/* The count of CCM_CCGR_TOG */
#define CCM_CCGR_TOG_COUNT                       (191U)

/*! @name TARGET_ROOT - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_POST_PODF_MASK           (0x3FU)
#define CCM_TARGET_ROOT_POST_PODF_SHIFT          (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_POST_PODF(x)             (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_POST_PODF_MASK)

#define CCM_TARGET_ROOT_PRE_PODF_MASK            (0x70000U)
#define CCM_TARGET_ROOT_PRE_PODF_SHIFT           (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_PRE_PODF(x)              (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_MUX_MASK                 (0x7000000U)
#define CCM_TARGET_ROOT_MUX_SHIFT                (24U)
#define CCM_TARGET_ROOT_MUX(x)                   (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_MUX_SHIFT)) & CCM_TARGET_ROOT_MUX_MASK)

#define CCM_TARGET_ROOT_ENABLE_MASK              (0x10000000U)
#define CCM_TARGET_ROOT_ENABLE_SHIFT             (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_ENABLE_SHIFT)) & CCM_TARGET_ROOT_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT */
#define CCM_TARGET_ROOT_COUNT                    (142U)

/*! @name TARGET_ROOT_SET - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_SET_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_SET_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_SET_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_SET_POST_PODF_MASK)

#define CCM_TARGET_ROOT_SET_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_SET_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_SET_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_SET_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_SET_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_SET_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_SET_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_MUX_SHIFT)) & CCM_TARGET_ROOT_SET_MUX_MASK)

#define CCM_TARGET_ROOT_SET_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_SET_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_SET_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_SET_ENABLE_SHIFT)) & CCM_TARGET_ROOT_SET_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_SET */
#define CCM_TARGET_ROOT_SET_COUNT                (142U)

/*! @name TARGET_ROOT_CLR - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_CLR_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_CLR_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_CLR_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_CLR_POST_PODF_MASK)

#define CCM_TARGET_ROOT_CLR_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_CLR_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_CLR_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_CLR_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_CLR_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_CLR_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_CLR_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_MUX_SHIFT)) & CCM_TARGET_ROOT_CLR_MUX_MASK)

#define CCM_TARGET_ROOT_CLR_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_CLR_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_CLR_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_CLR_ENABLE_SHIFT)) & CCM_TARGET_ROOT_CLR_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_CLR */
#define CCM_TARGET_ROOT_CLR_COUNT                (142U)

/*! @name TARGET_ROOT_TOG - Target Register */
/*! @{ */

#define CCM_TARGET_ROOT_TOG_POST_PODF_MASK       (0x3FU)
#define CCM_TARGET_ROOT_TOG_POST_PODF_SHIFT      (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_TARGET_ROOT_TOG_POST_PODF(x)         (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_POST_PODF_SHIFT)) & CCM_TARGET_ROOT_TOG_POST_PODF_MASK)

#define CCM_TARGET_ROOT_TOG_PRE_PODF_MASK        (0x70000U)
#define CCM_TARGET_ROOT_TOG_PRE_PODF_SHIFT       (16U)
/*! PRE_PODF
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_TARGET_ROOT_TOG_PRE_PODF(x)          (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_PRE_PODF_SHIFT)) & CCM_TARGET_ROOT_TOG_PRE_PODF_MASK)

#define CCM_TARGET_ROOT_TOG_MUX_MASK             (0x7000000U)
#define CCM_TARGET_ROOT_TOG_MUX_SHIFT            (24U)
#define CCM_TARGET_ROOT_TOG_MUX(x)               (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_MUX_SHIFT)) & CCM_TARGET_ROOT_TOG_MUX_MASK)

#define CCM_TARGET_ROOT_TOG_ENABLE_MASK          (0x10000000U)
#define CCM_TARGET_ROOT_TOG_ENABLE_SHIFT         (28U)
/*! ENABLE
 *  0b0..clock root is OFF
 *  0b1..clock root is ON
 */
#define CCM_TARGET_ROOT_TOG_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << CCM_TARGET_ROOT_TOG_ENABLE_SHIFT)) & CCM_TARGET_ROOT_TOG_ENABLE_MASK)
/*! @} */

/* The count of CCM_TARGET_ROOT_TOG */
#define CCM_TARGET_ROOT_TOG_COUNT                (142U)

/*! @name MISC - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_AUTHEN_FAIL_MASK                (0x1U)
#define CCM_MISC_AUTHEN_FAIL_SHIFT               (0U)
#define CCM_MISC_AUTHEN_FAIL(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_MISC_AUTHEN_FAIL_SHIFT)) & CCM_MISC_AUTHEN_FAIL_MASK)

#define CCM_MISC_TIMEOUT_MASK                    (0x10U)
#define CCM_MISC_TIMEOUT_SHIFT                   (4U)
#define CCM_MISC_TIMEOUT(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_MISC_TIMEOUT_SHIFT)) & CCM_MISC_TIMEOUT_MASK)

#define CCM_MISC_VIOLATE_MASK                    (0x100U)
#define CCM_MISC_VIOLATE_SHIFT                   (8U)
#define CCM_MISC_VIOLATE(x)                      (((uint32_t)(((uint32_t)(x)) << CCM_MISC_VIOLATE_SHIFT)) & CCM_MISC_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC */
#define CCM_MISC_COUNT                           (142U)

/*! @name MISC_ROOT_SET - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_SET_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_SET_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_SET_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_SET_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_SET_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_SET_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_SET_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_SET_TIMEOUT_MASK)

#define CCM_MISC_ROOT_SET_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_SET_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_SET_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_SET_VIOLATE_SHIFT)) & CCM_MISC_ROOT_SET_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_SET */
#define CCM_MISC_ROOT_SET_COUNT                  (142U)

/*! @name MISC_ROOT_CLR - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_CLR_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_CLR_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_CLR_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_CLR_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_CLR_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_CLR_TIMEOUT_MASK)

#define CCM_MISC_ROOT_CLR_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_CLR_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_CLR_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_CLR_VIOLATE_SHIFT)) & CCM_MISC_ROOT_CLR_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_CLR */
#define CCM_MISC_ROOT_CLR_COUNT                  (142U)

/*! @name MISC_ROOT_TOG - Miscellaneous Register */
/*! @{ */

#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL_MASK       (0x1U)
#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL_SHIFT      (0U)
#define CCM_MISC_ROOT_TOG_AUTHEN_FAIL(x)         (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_AUTHEN_FAIL_SHIFT)) & CCM_MISC_ROOT_TOG_AUTHEN_FAIL_MASK)

#define CCM_MISC_ROOT_TOG_TIMEOUT_MASK           (0x10U)
#define CCM_MISC_ROOT_TOG_TIMEOUT_SHIFT          (4U)
#define CCM_MISC_ROOT_TOG_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_TIMEOUT_SHIFT)) & CCM_MISC_ROOT_TOG_TIMEOUT_MASK)

#define CCM_MISC_ROOT_TOG_VIOLATE_MASK           (0x100U)
#define CCM_MISC_ROOT_TOG_VIOLATE_SHIFT          (8U)
#define CCM_MISC_ROOT_TOG_VIOLATE(x)             (((uint32_t)(((uint32_t)(x)) << CCM_MISC_ROOT_TOG_VIOLATE_SHIFT)) & CCM_MISC_ROOT_TOG_VIOLATE_MASK)
/*! @} */

/* The count of CCM_MISC_ROOT_TOG */
#define CCM_MISC_ROOT_TOG_COUNT                  (142U)

/*! @name POST - Post Divider Register */
/*! @{ */

#define CCM_POST_POST_PODF_MASK                  (0x3FU)
#define CCM_POST_POST_PODF_SHIFT                 (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_POST_PODF(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_POST_POST_PODF_SHIFT)) & CCM_POST_POST_PODF_MASK)

#define CCM_POST_BUSY1_MASK                      (0x80U)
#define CCM_POST_BUSY1_SHIFT                     (7U)
#define CCM_POST_BUSY1(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_POST_BUSY1_SHIFT)) & CCM_POST_BUSY1_MASK)

#define CCM_POST_SELECT_MASK                     (0x10000000U)
#define CCM_POST_SELECT_SHIFT                    (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_SELECT(x)                       (((uint32_t)(((uint32_t)(x)) << CCM_POST_SELECT_SHIFT)) & CCM_POST_SELECT_MASK)

#define CCM_POST_BUSY2_MASK                      (0x80000000U)
#define CCM_POST_BUSY2_SHIFT                     (31U)
#define CCM_POST_BUSY2(x)                        (((uint32_t)(((uint32_t)(x)) << CCM_POST_BUSY2_SHIFT)) & CCM_POST_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST */
#define CCM_POST_COUNT                           (142U)

/*! @name POST_ROOT_SET - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_SET_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_SET_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_SET_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_POST_PODF_SHIFT)) & CCM_POST_ROOT_SET_POST_PODF_MASK)

#define CCM_POST_ROOT_SET_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_SET_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_SET_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_BUSY1_SHIFT)) & CCM_POST_ROOT_SET_BUSY1_MASK)

#define CCM_POST_ROOT_SET_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_SET_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_SET_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_SELECT_SHIFT)) & CCM_POST_ROOT_SET_SELECT_MASK)

#define CCM_POST_ROOT_SET_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_SET_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_SET_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_SET_BUSY2_SHIFT)) & CCM_POST_ROOT_SET_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_SET */
#define CCM_POST_ROOT_SET_COUNT                  (142U)

/*! @name POST_ROOT_CLR - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_CLR_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_CLR_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_CLR_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_POST_PODF_SHIFT)) & CCM_POST_ROOT_CLR_POST_PODF_MASK)

#define CCM_POST_ROOT_CLR_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_CLR_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_CLR_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_BUSY1_SHIFT)) & CCM_POST_ROOT_CLR_BUSY1_MASK)

#define CCM_POST_ROOT_CLR_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_CLR_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_CLR_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_SELECT_SHIFT)) & CCM_POST_ROOT_CLR_SELECT_MASK)

#define CCM_POST_ROOT_CLR_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_CLR_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_CLR_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_CLR_BUSY2_SHIFT)) & CCM_POST_ROOT_CLR_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_CLR */
#define CCM_POST_ROOT_CLR_COUNT                  (142U)

/*! @name POST_ROOT_TOG - Post Divider Register */
/*! @{ */

#define CCM_POST_ROOT_TOG_POST_PODF_MASK         (0x3FU)
#define CCM_POST_ROOT_TOG_POST_PODF_SHIFT        (0U)
/*! POST_PODF
 *  0b000000..Divide by 1
 *  0b000001..Divide by 2
 *  0b000010..Divide by 3
 *  0b000011..Divide by 4
 *  0b000100..Divide by 5
 *  0b000101..Divide by 6
 *  0b111111..Divide by 64
 */
#define CCM_POST_ROOT_TOG_POST_PODF(x)           (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_POST_PODF_SHIFT)) & CCM_POST_ROOT_TOG_POST_PODF_MASK)

#define CCM_POST_ROOT_TOG_BUSY1_MASK             (0x80U)
#define CCM_POST_ROOT_TOG_BUSY1_SHIFT            (7U)
#define CCM_POST_ROOT_TOG_BUSY1(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_BUSY1_SHIFT)) & CCM_POST_ROOT_TOG_BUSY1_MASK)

#define CCM_POST_ROOT_TOG_SELECT_MASK            (0x10000000U)
#define CCM_POST_ROOT_TOG_SELECT_SHIFT           (28U)
/*! SELECT
 *  0b0..select branch A
 *  0b1..select branch B
 */
#define CCM_POST_ROOT_TOG_SELECT(x)              (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_SELECT_SHIFT)) & CCM_POST_ROOT_TOG_SELECT_MASK)

#define CCM_POST_ROOT_TOG_BUSY2_MASK             (0x80000000U)
#define CCM_POST_ROOT_TOG_BUSY2_SHIFT            (31U)
#define CCM_POST_ROOT_TOG_BUSY2(x)               (((uint32_t)(((uint32_t)(x)) << CCM_POST_ROOT_TOG_BUSY2_SHIFT)) & CCM_POST_ROOT_TOG_BUSY2_MASK)
/*! @} */

/* The count of CCM_POST_ROOT_TOG */
#define CCM_POST_ROOT_TOG_COUNT                  (142U)

/*! @name PRE - Pre Divider Register */
/*! @{ */

#define CCM_PRE_PRE_PODF_B_MASK                  (0x7U)
#define CCM_PRE_PRE_PODF_B_SHIFT                 (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_PRE_PODF_B(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_PRE_PRE_PODF_B_SHIFT)) & CCM_PRE_PRE_PODF_B_MASK)

#define CCM_PRE_BUSY0_MASK                       (0x8U)
#define CCM_PRE_BUSY0_SHIFT                      (3U)
#define CCM_PRE_BUSY0(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY0_SHIFT)) & CCM_PRE_BUSY0_MASK)

#define CCM_PRE_MUX_B_MASK                       (0x700U)
#define CCM_PRE_MUX_B_SHIFT                      (8U)
#define CCM_PRE_MUX_B(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_MUX_B_SHIFT)) & CCM_PRE_MUX_B_MASK)

#define CCM_PRE_EN_B_MASK                        (0x1000U)
#define CCM_PRE_EN_B_SHIFT                       (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_EN_B(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_PRE_EN_B_SHIFT)) & CCM_PRE_EN_B_MASK)

#define CCM_PRE_BUSY1_MASK                       (0x8000U)
#define CCM_PRE_BUSY1_SHIFT                      (15U)
#define CCM_PRE_BUSY1(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY1_SHIFT)) & CCM_PRE_BUSY1_MASK)

#define CCM_PRE_PRE_PODF_A_MASK                  (0x70000U)
#define CCM_PRE_PRE_PODF_A_SHIFT                 (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_PRE_PODF_A(x)                    (((uint32_t)(((uint32_t)(x)) << CCM_PRE_PRE_PODF_A_SHIFT)) & CCM_PRE_PRE_PODF_A_MASK)

#define CCM_PRE_BUSY3_MASK                       (0x80000U)
#define CCM_PRE_BUSY3_SHIFT                      (19U)
#define CCM_PRE_BUSY3(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY3_SHIFT)) & CCM_PRE_BUSY3_MASK)

#define CCM_PRE_MUX_A_MASK                       (0x7000000U)
#define CCM_PRE_MUX_A_SHIFT                      (24U)
#define CCM_PRE_MUX_A(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_MUX_A_SHIFT)) & CCM_PRE_MUX_A_MASK)

#define CCM_PRE_EN_A_MASK                        (0x10000000U)
#define CCM_PRE_EN_A_SHIFT                       (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_EN_A(x)                          (((uint32_t)(((uint32_t)(x)) << CCM_PRE_EN_A_SHIFT)) & CCM_PRE_EN_A_MASK)

#define CCM_PRE_BUSY4_MASK                       (0x80000000U)
#define CCM_PRE_BUSY4_SHIFT                      (31U)
#define CCM_PRE_BUSY4(x)                         (((uint32_t)(((uint32_t)(x)) << CCM_PRE_BUSY4_SHIFT)) & CCM_PRE_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE */
#define CCM_PRE_COUNT                            (142U)

/*! @name PRE_ROOT_SET - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_SET_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_SET_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_SET_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_SET_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_SET_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_SET_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_SET_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY0_SHIFT)) & CCM_PRE_ROOT_SET_BUSY0_MASK)

#define CCM_PRE_ROOT_SET_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_SET_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_SET_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_MUX_B_SHIFT)) & CCM_PRE_ROOT_SET_MUX_B_MASK)

#define CCM_PRE_ROOT_SET_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_SET_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_SET_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_EN_B_SHIFT)) & CCM_PRE_ROOT_SET_EN_B_MASK)

#define CCM_PRE_ROOT_SET_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_SET_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_SET_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY1_SHIFT)) & CCM_PRE_ROOT_SET_BUSY1_MASK)

#define CCM_PRE_ROOT_SET_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_SET_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_SET_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_SET_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_SET_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_SET_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_SET_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY3_SHIFT)) & CCM_PRE_ROOT_SET_BUSY3_MASK)

#define CCM_PRE_ROOT_SET_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_SET_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_SET_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_MUX_A_SHIFT)) & CCM_PRE_ROOT_SET_MUX_A_MASK)

#define CCM_PRE_ROOT_SET_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_SET_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_SET_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_EN_A_SHIFT)) & CCM_PRE_ROOT_SET_EN_A_MASK)

#define CCM_PRE_ROOT_SET_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_SET_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_SET_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_SET_BUSY4_SHIFT)) & CCM_PRE_ROOT_SET_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_SET */
#define CCM_PRE_ROOT_SET_COUNT                   (142U)

/*! @name PRE_ROOT_CLR - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_CLR_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_CLR_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_CLR_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_CLR_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_CLR_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_CLR_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_CLR_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY0_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY0_MASK)

#define CCM_PRE_ROOT_CLR_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_CLR_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_CLR_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_MUX_B_SHIFT)) & CCM_PRE_ROOT_CLR_MUX_B_MASK)

#define CCM_PRE_ROOT_CLR_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_CLR_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_CLR_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_EN_B_SHIFT)) & CCM_PRE_ROOT_CLR_EN_B_MASK)

#define CCM_PRE_ROOT_CLR_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_CLR_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_CLR_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY1_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY1_MASK)

#define CCM_PRE_ROOT_CLR_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_CLR_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_CLR_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_CLR_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_CLR_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_CLR_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_CLR_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY3_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY3_MASK)

#define CCM_PRE_ROOT_CLR_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_CLR_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_CLR_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_MUX_A_SHIFT)) & CCM_PRE_ROOT_CLR_MUX_A_MASK)

#define CCM_PRE_ROOT_CLR_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_CLR_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_CLR_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_EN_A_SHIFT)) & CCM_PRE_ROOT_CLR_EN_A_MASK)

#define CCM_PRE_ROOT_CLR_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_CLR_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_CLR_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_CLR_BUSY4_SHIFT)) & CCM_PRE_ROOT_CLR_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_CLR */
#define CCM_PRE_ROOT_CLR_COUNT                   (142U)

/*! @name PRE_ROOT_TOG - Pre Divider Register */
/*! @{ */

#define CCM_PRE_ROOT_TOG_PRE_PODF_B_MASK         (0x7U)
#define CCM_PRE_ROOT_TOG_PRE_PODF_B_SHIFT        (0U)
/*! PRE_PODF_B
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_TOG_PRE_PODF_B(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_PRE_PODF_B_SHIFT)) & CCM_PRE_ROOT_TOG_PRE_PODF_B_MASK)

#define CCM_PRE_ROOT_TOG_BUSY0_MASK              (0x8U)
#define CCM_PRE_ROOT_TOG_BUSY0_SHIFT             (3U)
#define CCM_PRE_ROOT_TOG_BUSY0(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY0_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY0_MASK)

#define CCM_PRE_ROOT_TOG_MUX_B_MASK              (0x700U)
#define CCM_PRE_ROOT_TOG_MUX_B_SHIFT             (8U)
#define CCM_PRE_ROOT_TOG_MUX_B(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_MUX_B_SHIFT)) & CCM_PRE_ROOT_TOG_MUX_B_MASK)

#define CCM_PRE_ROOT_TOG_EN_B_MASK               (0x1000U)
#define CCM_PRE_ROOT_TOG_EN_B_SHIFT              (12U)
/*! EN_B
 *  0b0..Clock shutdown
 *  0b1..Clock ON
 */
#define CCM_PRE_ROOT_TOG_EN_B(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_EN_B_SHIFT)) & CCM_PRE_ROOT_TOG_EN_B_MASK)

#define CCM_PRE_ROOT_TOG_BUSY1_MASK              (0x8000U)
#define CCM_PRE_ROOT_TOG_BUSY1_SHIFT             (15U)
#define CCM_PRE_ROOT_TOG_BUSY1(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY1_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY1_MASK)

#define CCM_PRE_ROOT_TOG_PRE_PODF_A_MASK         (0x70000U)
#define CCM_PRE_ROOT_TOG_PRE_PODF_A_SHIFT        (16U)
/*! PRE_PODF_A
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 3
 *  0b011..Divide by 4
 *  0b100..Divide by 5
 *  0b101..Divide by 6
 *  0b110..Divide by 7
 *  0b111..Divide by 8
 */
#define CCM_PRE_ROOT_TOG_PRE_PODF_A(x)           (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_PRE_PODF_A_SHIFT)) & CCM_PRE_ROOT_TOG_PRE_PODF_A_MASK)

#define CCM_PRE_ROOT_TOG_BUSY3_MASK              (0x80000U)
#define CCM_PRE_ROOT_TOG_BUSY3_SHIFT             (19U)
#define CCM_PRE_ROOT_TOG_BUSY3(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY3_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY3_MASK)

#define CCM_PRE_ROOT_TOG_MUX_A_MASK              (0x7000000U)
#define CCM_PRE_ROOT_TOG_MUX_A_SHIFT             (24U)
#define CCM_PRE_ROOT_TOG_MUX_A(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_MUX_A_SHIFT)) & CCM_PRE_ROOT_TOG_MUX_A_MASK)

#define CCM_PRE_ROOT_TOG_EN_A_MASK               (0x10000000U)
#define CCM_PRE_ROOT_TOG_EN_A_SHIFT              (28U)
/*! EN_A
 *  0b0..Clock shutdown
 *  0b1..clock ON
 */
#define CCM_PRE_ROOT_TOG_EN_A(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_EN_A_SHIFT)) & CCM_PRE_ROOT_TOG_EN_A_MASK)

#define CCM_PRE_ROOT_TOG_BUSY4_MASK              (0x80000000U)
#define CCM_PRE_ROOT_TOG_BUSY4_SHIFT             (31U)
#define CCM_PRE_ROOT_TOG_BUSY4(x)                (((uint32_t)(((uint32_t)(x)) << CCM_PRE_ROOT_TOG_BUSY4_SHIFT)) & CCM_PRE_ROOT_TOG_BUSY4_MASK)
/*! @} */

/* The count of CCM_PRE_ROOT_TOG */
#define CCM_PRE_ROOT_TOG_COUNT                   (142U)

/*! @name ACCESS_CTRL - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_DOMAIN0_INFO_MASK        (0xFU)
#define CCM_ACCESS_CTRL_DOMAIN0_INFO_SHIFT       (0U)
#define CCM_ACCESS_CTRL_DOMAIN0_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN1_INFO_MASK        (0xF0U)
#define CCM_ACCESS_CTRL_DOMAIN1_INFO_SHIFT       (4U)
#define CCM_ACCESS_CTRL_DOMAIN1_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN2_INFO_MASK        (0xF00U)
#define CCM_ACCESS_CTRL_DOMAIN2_INFO_SHIFT       (8U)
#define CCM_ACCESS_CTRL_DOMAIN2_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_DOMAIN3_INFO_MASK        (0xF000U)
#define CCM_ACCESS_CTRL_DOMAIN3_INFO_SHIFT       (12U)
#define CCM_ACCESS_CTRL_DOMAIN3_INFO(x)          (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_OWNER_ID_MASK            (0x30000U)
#define CCM_ACCESS_CTRL_OWNER_ID_SHIFT           (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_OWNER_ID(x)              (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_MUTEX_MASK               (0x100000U)
#define CCM_ACCESS_CTRL_MUTEX_SHIFT              (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_MUTEX(x)                 (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_MUTEX_MASK)

#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_MASK   (0x1000000U)
#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_SHIFT  (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN0_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_MASK   (0x2000000U)
#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_SHIFT  (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN1_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_MASK   (0x4000000U)
#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_SHIFT  (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN2_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_MASK   (0x8000000U)
#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_SHIFT  (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_DOMAIN3_WHITELIST(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_SEMA_EN_MASK             (0x10000000U)
#define CCM_ACCESS_CTRL_SEMA_EN_SHIFT            (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_SEMA_EN(x)               (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_LOCK_MASK                (0x80000000U)
#define CCM_ACCESS_CTRL_LOCK_SHIFT               (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_LOCK(x)                  (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_LOCK_SHIFT)) & CCM_ACCESS_CTRL_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL */
#define CCM_ACCESS_CTRL_COUNT                    (142U)

/*! @name ACCESS_CTRL_ROOT_SET - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_SET_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_SET_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_SET_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_SET_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_SET_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_SET_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_SET */
#define CCM_ACCESS_CTRL_ROOT_SET_COUNT           (142U)

/*! @name ACCESS_CTRL_ROOT_CLR - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_CLR_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_CLR_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_CLR_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_CLR */
#define CCM_ACCESS_CTRL_ROOT_CLR_COUNT           (142U)

/*! @name ACCESS_CTRL_ROOT_TOG - Access Control Register */
/*! @{ */

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_MASK (0xFU)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_SHIFT (0U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_MASK (0xF0U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_SHIFT (4U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_MASK (0xF00U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_SHIFT (8U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_MASK (0xF000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_SHIFT (12U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_INFO_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_MASK   (0x30000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_SHIFT  (16U)
/*! OWNER_ID
 *  0b00..domaino
 *  0b01..domain1
 *  0b10..domain2
 *  0b11..domain3
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID(x)     (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_OWNER_ID_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_MASK      (0x100000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_SHIFT     (20U)
/*! MUTEX
 *  0b0..Semaphore is free to take
 *  0b1..Semaphore is taken
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_MUTEX(x)        (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_MUTEX_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_MASK (0x1000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_SHIFT (24U)
/*! DOMAIN0_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN0_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_MASK (0x2000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_SHIFT (25U)
/*! DOMAIN1_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN1_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_MASK (0x4000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_SHIFT (26U)
/*! DOMAIN2_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN2_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_MASK (0x8000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_SHIFT (27U)
/*! DOMAIN3_WHITELIST
 *  0b0..Domain cannot change the setting
 *  0b1..Domain can change the setting
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST(x) (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_DOMAIN3_WHITELIST_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_MASK    (0x10000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_SHIFT   (28U)
/*! SEMA_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN(x)      (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_SEMA_EN_MASK)

#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK_MASK       (0x80000000U)
#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK_SHIFT      (31U)
/*! LOCK
 *  0b0..Access control inactive
 *  0b1..Access control active
 */
#define CCM_ACCESS_CTRL_ROOT_TOG_LOCK(x)         (((uint32_t)(((uint32_t)(x)) << CCM_ACCESS_CTRL_ROOT_TOG_LOCK_SHIFT)) & CCM_ACCESS_CTRL_ROOT_TOG_LOCK_MASK)
/*! @} */

/* The count of CCM_ACCESS_CTRL_ROOT_TOG */
#define CCM_ACCESS_CTRL_ROOT_TOG_COUNT           (142U)


/*!
 * @}
 */ /* end of group CCM_Register_Masks */


/*!
 * @}
 */ /* end of group CCM_Peripheral_Access_Layer */


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


#endif  /* PERI_CCM_H_ */

