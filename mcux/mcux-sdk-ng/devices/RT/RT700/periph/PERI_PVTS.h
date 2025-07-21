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
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PVTS
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PVTS.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PVTS
 *
 * CMSIS Peripheral Access Layer for PVTS
 */

#if !defined(PERI_PVTS_H_)
#define PERI_PVTS_H_                             /**< Symbol preventing repeated inclusion */

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
         uint8_t RESERVED_0[32];
    __IO uint32_t DEL_CTRL;                          /**< Delay Control, array offset: 0x20, array step: 0x80 */
         uint8_t RESERVED_1[8];
    __IO uint32_t ALERT_CNT;                         /**< Alert Counter, array offset: 0x2C, array step: 0x80 */
    __IO uint32_t ALERT_CNT_CTRL;                    /**< Alert Counter Control, array offset: 0x30, array step: 0x80 */
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

/*! @name DEL_CTRL - Delay Control */
/*! @{ */

#define PVTS_DEL_CTRL_DELAY0_MASK                (0x1FU)
#define PVTS_DEL_CTRL_DELAY0_SHIFT               (0U)
/*! DELAY0 - Delay Section 0 */
#define PVTS_DEL_CTRL_DELAY0(x)                  (((uint32_t)(((uint32_t)(x)) << PVTS_DEL_CTRL_DELAY0_SHIFT)) & PVTS_DEL_CTRL_DELAY0_MASK)

#define PVTS_DEL_CTRL_DELAY1_MASK                (0x3E0U)
#define PVTS_DEL_CTRL_DELAY1_SHIFT               (5U)
/*! DELAY1 - Delay Section 1 */
#define PVTS_DEL_CTRL_DELAY1(x)                  (((uint32_t)(((uint32_t)(x)) << PVTS_DEL_CTRL_DELAY1_SHIFT)) & PVTS_DEL_CTRL_DELAY1_MASK)
/*! @} */

/* The count of PVTS_DEL_CTRL */
#define PVTS_DEL_CTRL_COUNT                      (2U)

/*! @name ALERT_CNT - Alert Counter */
/*! @{ */

#define PVTS_ALERT_CNT_CNT_MASK                  (0xFFFFFU)
#define PVTS_ALERT_CNT_CNT_SHIFT                 (0U)
/*! CNT - Counter */
#define PVTS_ALERT_CNT_CNT(x)                    (((uint32_t)(((uint32_t)(x)) << PVTS_ALERT_CNT_CNT_SHIFT)) & PVTS_ALERT_CNT_CNT_MASK)
/*! @} */

/* The count of PVTS_ALERT_CNT */
#define PVTS_ALERT_CNT_COUNT                     (2U)

/*! @name ALERT_CNT_CTRL - Alert Counter Control */
/*! @{ */

#define PVTS_ALERT_CNT_CTRL_CNTEN_MASK           (0x1U)
#define PVTS_ALERT_CNT_CTRL_CNTEN_SHIFT          (0U)
/*! CNTEN - Counter Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PVTS_ALERT_CNT_CTRL_CNTEN(x)             (((uint32_t)(((uint32_t)(x)) << PVTS_ALERT_CNT_CTRL_CNTEN_SHIFT)) & PVTS_ALERT_CNT_CTRL_CNTEN_MASK)
/*! @} */

/* The count of PVTS_ALERT_CNT_CTRL */
#define PVTS_ALERT_CNT_CTRL_COUNT                (2U)


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


#endif  /* PERI_PVTS_H_ */

