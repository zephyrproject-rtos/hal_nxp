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
**         CMSIS Peripheral Access Layer for GDET
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
 * @file PERI_GDET.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GDET
 *
 * CMSIS Peripheral Access Layer for GDET
 */

#if !defined(PERI_GDET_H_)
#define PERI_GDET_H_                             /**< Symbol preventing repeated inclusion */

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
   -- GDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Peripheral_Access_Layer GDET Peripheral Access Layer
 * @{
 */

/** GDET - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t GDET_ENABLE1;                      /**< Enable register, offset: 0x8 */
       uint8_t RESERVED_1[2044];
  __IO uint32_t GDET_DLY_CTRL;                     /**< GDET delay control register, offset: 0x808 */
  __O  uint32_t GDET_CTRL_CLR;                     /**< GDET Clear Control register, offset: 0x80C */
} GDET_Type;

/* ----------------------------------------------------------------------------
   -- GDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDET_Register_Masks GDET Register Masks
 * @{
 */

/*! @name GDET_ENABLE1 - Enable register */
/*! @{ */

#define GDET_GDET_ENABLE1_EN1_MASK               (0x1U)
#define GDET_GDET_ENABLE1_EN1_SHIFT              (0U)
#define GDET_GDET_ENABLE1_EN1(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_EN1_SHIFT)) & GDET_GDET_ENABLE1_EN1_MASK)

#define GDET_GDET_ENABLE1_RFU_MASK               (0xFFFFFFFEU)
#define GDET_GDET_ENABLE1_RFU_SHIFT              (1U)
#define GDET_GDET_ENABLE1_RFU(x)                 (((uint32_t)(((uint32_t)(x)) << GDET_GDET_ENABLE1_RFU_SHIFT)) & GDET_GDET_ENABLE1_RFU_MASK)
/*! @} */

/*! @name GDET_DLY_CTRL - GDET delay control register */
/*! @{ */

#define GDET_GDET_DLY_CTRL_VOL_SEL_MASK          (0x3U)
#define GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT         (0U)
#define GDET_GDET_DLY_CTRL_VOL_SEL(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_VOL_SEL_SHIFT)) & GDET_GDET_DLY_CTRL_VOL_SEL_MASK)

#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK      (0x4U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT     (2U)
#define GDET_GDET_DLY_CTRL_SW_VOL_CTRL(x)        (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_SW_VOL_CTRL_SHIFT)) & GDET_GDET_DLY_CTRL_SW_VOL_CTRL_MASK)

#define GDET_GDET_DLY_CTRL_RFU_MASK              (0xFFFFFFF8U)
#define GDET_GDET_DLY_CTRL_RFU_SHIFT             (3U)
#define GDET_GDET_DLY_CTRL_RFU(x)                (((uint32_t)(((uint32_t)(x)) << GDET_GDET_DLY_CTRL_RFU_SHIFT)) & GDET_GDET_DLY_CTRL_RFU_MASK)
/*! @} */

/*! @name GDET_CTRL_CLR - GDET Clear Control register */
/*! @{ */

#define GDET_GDET_CTRL_CLR_SFT_RST_MASK          (0x1U)
#define GDET_GDET_CTRL_CLR_SFT_RST_SHIFT         (0U)
#define GDET_GDET_CTRL_CLR_SFT_RST(x)            (((uint32_t)(((uint32_t)(x)) << GDET_GDET_CTRL_CLR_SFT_RST_SHIFT)) & GDET_GDET_CTRL_CLR_SFT_RST_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GDET_Register_Masks */


/*!
 * @}
 */ /* end of group GDET_Peripheral_Access_Layer */


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


#endif  /* PERI_GDET_H_ */

