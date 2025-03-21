/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 2.0, 2024-05-28
**     Build:               b241121
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PVTS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**
** ###################################################################
*/

/*!
 * @file PVTS.h
 * @version 2.0
 * @date 2024-05-28
 * @brief CMSIS Peripheral Access Layer for PVTS
 *
 * CMSIS Peripheral Access Layer for PVTS
 */

#if !defined(PVTS_H_)
#define PVTS_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- PVTS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PVTS_Peripheral_Access_Layer PVTS Peripheral Access Layer
 * @{
 */

/** PVTS - Size of Registers Arrays */
#define PVTS_PVT_COUNT                            2u

/** PVTS - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x80 */
    __IO uint32_t RED_DEL_CTRL;                      /**< Red Delay Control, array offset: 0x0, array step: 0x80 */
         uint8_t RESERVED_0[8];
    __IO uint32_t RED_ALERT_CNT;                     /**< Red Alert Counter, array offset: 0xC, array step: 0x80 */
    __IO uint32_t RED_ALERT_CNT_CTRL;                /**< Red Alert Counter Control, array offset: 0x10, array step: 0x80 */
         uint8_t RESERVED_1[12];
    __IO uint32_t AMBER_DEL_CTRL;                    /**< Amber Delay Control, array offset: 0x20, array step: 0x80 */
    __IO uint32_t AMBER_RING_OSC_CTRL;               /**< Amber Ring OSC Control, array offset: 0x24, array step: 0x80 */
    __I  uint32_t AMBER_RING_CNT;                    /**< Amber Ring OSC Counter, array offset: 0x28, array step: 0x80 */
    __IO uint32_t AMBER_ALERT_CNT;                   /**< Amber Alert Counter, array offset: 0x2C, array step: 0x80 */
    __IO uint32_t AMBER_ALERT_CNT_CTRL;              /**< Amber Alert Counter Control, array offset: 0x30, array step: 0x80 */
         uint8_t RESERVED_2[76];
  } PVT[PVTS_PVT_COUNT];
} PVTS_Type;

/* ----------------------------------------------------------------------------
   -- PVTS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PVTS_Register_Masks PVTS Register Masks
 * @{
 */

/*! @name RED_DEL_CTRL - Red Delay Control */
/*! @{ */

#define PVTS_RED_DEL_CTRL_DELAY0_MASK            (0x1FU)
#define PVTS_RED_DEL_CTRL_DELAY0_SHIFT           (0U)
/*! DELAY0 - Red Delay Section 0 */
#define PVTS_RED_DEL_CTRL_DELAY0(x)              (((uint32_t)(((uint32_t)(x)) << PVTS_RED_DEL_CTRL_DELAY0_SHIFT)) & PVTS_RED_DEL_CTRL_DELAY0_MASK)

#define PVTS_RED_DEL_CTRL_DELAY1_MASK            (0x3E0U)
#define PVTS_RED_DEL_CTRL_DELAY1_SHIFT           (5U)
/*! DELAY1 - Red Delay Section 1 */
#define PVTS_RED_DEL_CTRL_DELAY1(x)              (((uint32_t)(((uint32_t)(x)) << PVTS_RED_DEL_CTRL_DELAY1_SHIFT)) & PVTS_RED_DEL_CTRL_DELAY1_MASK)
/*! @} */

/* The count of PVTS_RED_DEL_CTRL */
#define PVTS_RED_DEL_CTRL_COUNT                  (2U)

/*! @name RED_ALERT_CNT - Red Alert Counter */
/*! @{ */

#define PVTS_RED_ALERT_CNT_CNT_MASK              (0xFFFFFU)
#define PVTS_RED_ALERT_CNT_CNT_SHIFT             (0U)
/*! CNT - Counter */
#define PVTS_RED_ALERT_CNT_CNT(x)                (((uint32_t)(((uint32_t)(x)) << PVTS_RED_ALERT_CNT_CNT_SHIFT)) & PVTS_RED_ALERT_CNT_CNT_MASK)
/*! @} */

/* The count of PVTS_RED_ALERT_CNT */
#define PVTS_RED_ALERT_CNT_COUNT                 (2U)

/*! @name RED_ALERT_CNT_CTRL - Red Alert Counter Control */
/*! @{ */

#define PVTS_RED_ALERT_CNT_CTRL_CNTEN_MASK       (0x1U)
#define PVTS_RED_ALERT_CNT_CTRL_CNTEN_SHIFT      (0U)
/*! CNTEN - Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PVTS_RED_ALERT_CNT_CTRL_CNTEN(x)         (((uint32_t)(((uint32_t)(x)) << PVTS_RED_ALERT_CNT_CTRL_CNTEN_SHIFT)) & PVTS_RED_ALERT_CNT_CTRL_CNTEN_MASK)
/*! @} */

/* The count of PVTS_RED_ALERT_CNT_CTRL */
#define PVTS_RED_ALERT_CNT_CTRL_COUNT            (2U)

/*! @name AMBER_DEL_CTRL - Amber Delay Control */
/*! @{ */

#define PVTS_AMBER_DEL_CTRL_DELAY0_MASK          (0x1FU)
#define PVTS_AMBER_DEL_CTRL_DELAY0_SHIFT         (0U)
/*! DELAY0 - Amber Delay Section 0 */
#define PVTS_AMBER_DEL_CTRL_DELAY0(x)            (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_DEL_CTRL_DELAY0_SHIFT)) & PVTS_AMBER_DEL_CTRL_DELAY0_MASK)

#define PVTS_AMBER_DEL_CTRL_DELAY1_MASK          (0x3E0U)
#define PVTS_AMBER_DEL_CTRL_DELAY1_SHIFT         (5U)
/*! DELAY1 - Amber Delay Section 1 */
#define PVTS_AMBER_DEL_CTRL_DELAY1(x)            (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_DEL_CTRL_DELAY1_SHIFT)) & PVTS_AMBER_DEL_CTRL_DELAY1_MASK)
/*! @} */

/* The count of PVTS_AMBER_DEL_CTRL */
#define PVTS_AMBER_DEL_CTRL_COUNT                (2U)

/*! @name AMBER_RING_OSC_CTRL - Amber Ring OSC Control */
/*! @{ */

#define PVTS_AMBER_RING_OSC_CTRL_RINGOSCEN_MASK  (0x1U)
#define PVTS_AMBER_RING_OSC_CTRL_RINGOSCEN_SHIFT (0U)
/*! RINGOSCEN - Amber Ring Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PVTS_AMBER_RING_OSC_CTRL_RINGOSCEN(x)    (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_RING_OSC_CTRL_RINGOSCEN_SHIFT)) & PVTS_AMBER_RING_OSC_CTRL_RINGOSCEN_MASK)

#define PVTS_AMBER_RING_OSC_CTRL_CNTEN_MASK      (0x2U)
#define PVTS_AMBER_RING_OSC_CTRL_CNTEN_SHIFT     (1U)
/*! CNTEN - Amber Ring OSC Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PVTS_AMBER_RING_OSC_CTRL_CNTEN(x)        (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_RING_OSC_CTRL_CNTEN_SHIFT)) & PVTS_AMBER_RING_OSC_CTRL_CNTEN_MASK)

#define PVTS_AMBER_RING_OSC_CTRL_CNTRST_MASK     (0x4U)
#define PVTS_AMBER_RING_OSC_CTRL_CNTRST_SHIFT    (2U)
/*! CNTRST - Amber Ring OSC Counter Reset
 *  0b0..Not resets
 *  0b1..Resets
 */
#define PVTS_AMBER_RING_OSC_CTRL_CNTRST(x)       (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_RING_OSC_CTRL_CNTRST_SHIFT)) & PVTS_AMBER_RING_OSC_CTRL_CNTRST_MASK)
/*! @} */

/* The count of PVTS_AMBER_RING_OSC_CTRL */
#define PVTS_AMBER_RING_OSC_CTRL_COUNT           (2U)

/*! @name AMBER_RING_CNT - Amber Ring OSC Counter */
/*! @{ */

#define PVTS_AMBER_RING_CNT_CNT_MASK             (0xFFFFFFFFU)
#define PVTS_AMBER_RING_CNT_CNT_SHIFT            (0U)
/*! CNT - Counter */
#define PVTS_AMBER_RING_CNT_CNT(x)               (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_RING_CNT_CNT_SHIFT)) & PVTS_AMBER_RING_CNT_CNT_MASK)
/*! @} */

/* The count of PVTS_AMBER_RING_CNT */
#define PVTS_AMBER_RING_CNT_COUNT                (2U)

/*! @name AMBER_ALERT_CNT - Amber Alert Counter */
/*! @{ */

#define PVTS_AMBER_ALERT_CNT_CNT_MASK            (0xFFFFFU)
#define PVTS_AMBER_ALERT_CNT_CNT_SHIFT           (0U)
/*! CNT - Counter */
#define PVTS_AMBER_ALERT_CNT_CNT(x)              (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_ALERT_CNT_CNT_SHIFT)) & PVTS_AMBER_ALERT_CNT_CNT_MASK)
/*! @} */

/* The count of PVTS_AMBER_ALERT_CNT */
#define PVTS_AMBER_ALERT_CNT_COUNT               (2U)

/*! @name AMBER_ALERT_CNT_CTRL - Amber Alert Counter Control */
/*! @{ */

#define PVTS_AMBER_ALERT_CNT_CTRL_CNTEN_MASK     (0x1U)
#define PVTS_AMBER_ALERT_CNT_CTRL_CNTEN_SHIFT    (0U)
/*! CNTEN - Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PVTS_AMBER_ALERT_CNT_CTRL_CNTEN(x)       (((uint32_t)(((uint32_t)(x)) << PVTS_AMBER_ALERT_CNT_CTRL_CNTEN_SHIFT)) & PVTS_AMBER_ALERT_CNT_CTRL_CNTEN_MASK)
/*! @} */

/* The count of PVTS_AMBER_ALERT_CNT_CTRL */
#define PVTS_AMBER_ALERT_CNT_CTRL_COUNT          (2U)


/*!
 * @}
 */ /* end of group PVTS_Register_Masks */


/*!
 * @}
 */ /* end of group PVTS_Peripheral_Access_Layer */


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


#endif  /* PVTS_H_ */

