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
**         CMSIS Peripheral Access Layer for SYSCON4
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
 * @file PERI_SYSCON4.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCON4
 *
 * CMSIS Peripheral Access Layer for SYSCON4
 */

#if !defined(PERI_SYSCON4_H_)
#define PERI_SYSCON4_H_                          /**< Symbol preventing repeated inclusion */

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
   -- SYSCON4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON4_Peripheral_Access_Layer SYSCON4 Peripheral Access Layer
 * @{
 */

/** SYSCON4 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[40];
  __IO uint32_t MMU2_MEM_CTRL;                     /**< MMU2 Memory Control, offset: 0x28 */
  __IO uint32_t XSPI2_MEM_CTRL;                    /**< XSPI2 Memory Control, offset: 0x2C */
  __IO uint32_t EZHV_MEM_CTRL;                     /**< EZH-V Memory Control, offset: 0x30 */
  __IO uint32_t LCDIF_MEM_CTRL;                    /**< LCDIF Memory Control, offset: 0x34 */
       uint8_t RESERVED_1[4];
  __IO uint32_t JPEGDEC_MEM_CTRL;                  /**< JPEGDEC Memory Control, offset: 0x3C */
  __IO uint32_t PNGDEC_MEM_CTRL;                   /**< PNGDEC Memory Control, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MIPI_MEM_CTRL;                     /**< MIPI Memory Control, offset: 0x48 */
  __IO uint32_t VGPU_MEM_CTRL;                     /**< VGPU Memory Control, offset: 0x4C */
       uint8_t RESERVED_3[128];
  __IO uint32_t EZHV_RSTBASE;                      /**< EZH-V Reset Base, offset: 0xD0 */
  __IO uint32_t EZHV_RSTMTVEC;                     /**< EZH-V MTVEC Reset Value, offset: 0xD4 */
  __IO uint32_t EZHV_RSTSTVEC;                     /**< EZH-V STVEC Reset Value, offset: 0xD8 */
  __IO uint32_t EZHV_VOFFSET_T;                    /**< EZH-V Interrupt Vector Offset, offset: 0xDC */
  __IO uint32_t EZHV2ARM_INT_EN;                   /**< EZH-V To Arm Interrupt Enable, offset: 0xE0 */
  __IO uint32_t EZHV2ARM_INT_CHAN;                 /**< EZH-V Interrupt Channel, offset: 0xE4 */
  __IO uint32_t ARM2EZHV_INT_CTRL;                 /**< Arm To EZH-V Interrupt Control, offset: 0xE8 */
       uint8_t RESERVED_4[68];
  __IO uint32_t MIPI_DSI_CTRL;                     /**< MIPI_DSI Control, offset: 0x130 */
       uint8_t RESERVED_5[332];
  __IO uint32_t MEDIA_AUTOGATE_EN;                 /**< VDD2_MEDIA Auto Gating Enable, offset: 0x280 */
       uint8_t RESERVED_6[652];
  __IO uint32_t USB0_MEM_CTRL;                     /**< USB0 Memory Control, offset: 0x510 */
  __IO uint32_t USB1_MEM_CTRL;                     /**< USB1 Memory Control, offset: 0x514 */
  __IO uint32_t USDHC0_MEM_CTRL;                   /**< uSDHC0 Memory Control, offset: 0x518 */
  __IO uint32_t USDHC1_MEM_CTRL;                   /**< uSDHC1 Memory Control, offset: 0x51C */
       uint8_t RESERVED_7[260];
  __IO uint32_t GPIO_BANK4_CFG;                    /**< PIO4 Configuration, offset: 0x624 */
  __IO uint32_t GPIO_BANK5_CFG;                    /**< PIO5 Configuration, offset: 0x628 */
  __IO uint32_t GPIO_BANK6_CFG;                    /**< PIO6 Configuration, offset: 0x62C */
       uint8_t RESERVED_8[32];
  __IO uint32_t USBPHY0_CLK_ACTIVE;                /**< USBPHY0 CLK Active, offset: 0x650 */
} SYSCON4_Type;

/* ----------------------------------------------------------------------------
   -- SYSCON4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCON4_Register_Masks SYSCON4 Register Masks
 * @{
 */

/*! @name MMU2_MEM_CTRL - MMU2 Memory Control */
/*! @{ */

#define SYSCON4_MMU2_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_MMU2_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_MMU2_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_MMU2_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_MMU2_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_MMU2_MEM_CTRL_MEM_IG_MASK        (0x100U)
#define SYSCON4_MMU2_MEM_CTRL_MEM_IG_SHIFT       (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_MMU2_MEM_CTRL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON4_MMU2_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_MMU2_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name XSPI2_MEM_CTRL - XSPI2 Memory Control */
/*! @{ */

#define SYSCON4_XSPI2_MEM_CTRL_MEM_STDBY_MASK    (0x80U)
#define SYSCON4_XSPI2_MEM_CTRL_MEM_STDBY_SHIFT   (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_XSPI2_MEM_CTRL_MEM_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_XSPI2_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_XSPI2_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_XSPI2_MEM_CTRL_MEM_WIG_MASK      (0x100U)
#define SYSCON4_XSPI2_MEM_CTRL_MEM_WIG_SHIFT     (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_XSPI2_MEM_CTRL_MEM_WIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_XSPI2_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_XSPI2_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_XSPI2_MEM_CTRL_MEM_RIG_MASK      (0x200U)
#define SYSCON4_XSPI2_MEM_CTRL_MEM_RIG_SHIFT     (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_XSPI2_MEM_CTRL_MEM_RIG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_XSPI2_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_XSPI2_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name EZHV_MEM_CTRL - EZH-V Memory Control */
/*! @{ */

#define SYSCON4_EZHV_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_EZHV_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_EZHV_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_EZHV_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_EZHV_MEM_CTRL_MEM_IG_MASK        (0x100U)
#define SYSCON4_EZHV_MEM_CTRL_MEM_IG_SHIFT       (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_EZHV_MEM_CTRL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_EZHV_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name LCDIF_MEM_CTRL - LCDIF Memory Control */
/*! @{ */

#define SYSCON4_LCDIF_MEM_CTRL_MEM_STDBY_MASK    (0x80U)
#define SYSCON4_LCDIF_MEM_CTRL_MEM_STDBY_SHIFT   (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_LCDIF_MEM_CTRL_MEM_STDBY(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_LCDIF_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_LCDIF_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_LCDIF_MEM_CTRL_MEM_IG_MASK       (0x100U)
#define SYSCON4_LCDIF_MEM_CTRL_MEM_IG_SHIFT      (8U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_LCDIF_MEM_CTRL_MEM_IG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_LCDIF_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_LCDIF_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name JPEGDEC_MEM_CTRL - JPEGDEC Memory Control */
/*! @{ */

#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_STDBY_MASK  (0x80U)
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_STDBY_SHIFT (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_STDBY(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON4_JPEGDEC_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_JPEGDEC_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_WIG_MASK    (0x100U)
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_WIG_SHIFT   (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_WIG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_JPEGDEC_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_JPEGDEC_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_RIG_MASK    (0x200U)
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_RIG_SHIFT   (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_RIG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_JPEGDEC_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_JPEGDEC_MEM_CTRL_MEM_RIG_MASK)

#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_IG_MASK     (0x400U)
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_IG_SHIFT    (10U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_JPEGDEC_MEM_CTRL_MEM_IG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_JPEGDEC_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_JPEGDEC_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name PNGDEC_MEM_CTRL - PNGDEC Memory Control */
/*! @{ */

#define SYSCON4_PNGDEC_MEM_CTRL_MEM_STDBY_MASK   (0x80U)
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_STDBY_SHIFT  (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON4_PNGDEC_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_PNGDEC_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_PNGDEC_MEM_CTRL_MEM_WIG_MASK     (0x100U)
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_WIG_SHIFT    (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_WIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_PNGDEC_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_PNGDEC_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_PNGDEC_MEM_CTRL_MEM_RIG_MASK     (0x200U)
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_RIG_SHIFT    (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_RIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_PNGDEC_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_PNGDEC_MEM_CTRL_MEM_RIG_MASK)

#define SYSCON4_PNGDEC_MEM_CTRL_MEM_IG_MASK      (0x400U)
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_IG_SHIFT     (10U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_PNGDEC_MEM_CTRL_MEM_IG(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_PNGDEC_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_PNGDEC_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name MIPI_MEM_CTRL - MIPI Memory Control */
/*! @{ */

#define SYSCON4_MIPI_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_MIPI_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_MIPI_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_MIPI_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_MIPI_MEM_CTRL_MEM_WIG_MASK       (0x100U)
#define SYSCON4_MIPI_MEM_CTRL_MEM_WIG_SHIFT      (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_MIPI_MEM_CTRL_MEM_WIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_MIPI_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_MIPI_MEM_CTRL_MEM_RIG_MASK       (0x200U)
#define SYSCON4_MIPI_MEM_CTRL_MEM_RIG_SHIFT      (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_MIPI_MEM_CTRL_MEM_RIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_MIPI_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name VGPU_MEM_CTRL - VGPU Memory Control */
/*! @{ */

#define SYSCON4_VGPU_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_VGPU_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_VGPU_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_VGPU_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_VGPU_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_VGPU_MEM_CTRL_MEM_WIG_MASK       (0x100U)
#define SYSCON4_VGPU_MEM_CTRL_MEM_WIG_SHIFT      (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_VGPU_MEM_CTRL_MEM_WIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_VGPU_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_VGPU_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_VGPU_MEM_CTRL_MEM_RIG_MASK       (0x200U)
#define SYSCON4_VGPU_MEM_CTRL_MEM_RIG_SHIFT      (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_VGPU_MEM_CTRL_MEM_RIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_VGPU_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_VGPU_MEM_CTRL_MEM_RIG_MASK)

#define SYSCON4_VGPU_MEM_CTRL_MEM_IG_MASK        (0x400U)
#define SYSCON4_VGPU_MEM_CTRL_MEM_IG_SHIFT       (10U)
/*! MEM_IG - Memory Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_VGPU_MEM_CTRL_MEM_IG(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON4_VGPU_MEM_CTRL_MEM_IG_SHIFT)) & SYSCON4_VGPU_MEM_CTRL_MEM_IG_MASK)
/*! @} */

/*! @name EZHV_RSTBASE - EZH-V Reset Base */
/*! @{ */

#define SYSCON4_EZHV_RSTBASE_EZHV_RSTBASE_MASK   (0x3FFFFFFFU)
#define SYSCON4_EZHV_RSTBASE_EZHV_RSTBASE_SHIFT  (0U)
/*! EZHV_RSTBASE - Reset Exception Handler Base Address */
#define SYSCON4_EZHV_RSTBASE_EZHV_RSTBASE(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_RSTBASE_EZHV_RSTBASE_SHIFT)) & SYSCON4_EZHV_RSTBASE_EZHV_RSTBASE_MASK)
/*! @} */

/*! @name EZHV_RSTMTVEC - EZH-V MTVEC Reset Value */
/*! @{ */

#define SYSCON4_EZHV_RSTMTVEC_EZHV_RSTMTVEC_MASK (0xFFFFFFFFU)
#define SYSCON4_EZHV_RSTMTVEC_EZHV_RSTMTVEC_SHIFT (0U)
/*! EZHV_RSTMTVEC - Reset Value of CSRs MTVEC */
#define SYSCON4_EZHV_RSTMTVEC_EZHV_RSTMTVEC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_RSTMTVEC_EZHV_RSTMTVEC_SHIFT)) & SYSCON4_EZHV_RSTMTVEC_EZHV_RSTMTVEC_MASK)
/*! @} */

/*! @name EZHV_RSTSTVEC - EZH-V STVEC Reset Value */
/*! @{ */

#define SYSCON4_EZHV_RSTSTVEC_EZHV_RSTSTVEC_MASK (0xFFFFFFFFU)
#define SYSCON4_EZHV_RSTSTVEC_EZHV_RSTSTVEC_SHIFT (0U)
/*! EZHV_RSTSTVEC - Reset Value of CSRs STVEC */
#define SYSCON4_EZHV_RSTSTVEC_EZHV_RSTSTVEC(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_RSTSTVEC_EZHV_RSTSTVEC_SHIFT)) & SYSCON4_EZHV_RSTSTVEC_EZHV_RSTSTVEC_MASK)
/*! @} */

/*! @name EZHV_VOFFSET_T - EZH-V Interrupt Vector Offset */
/*! @{ */

#define SYSCON4_EZHV_VOFFSET_T_EZHV_VOFFSET_T_MASK (0x3FFFU)
#define SYSCON4_EZHV_VOFFSET_T_EZHV_VOFFSET_T_SHIFT (0U)
/*! EZHV_VOFFSET_T - Interrupt Vector Offset for Vectored Interrupts */
#define SYSCON4_EZHV_VOFFSET_T_EZHV_VOFFSET_T(x) (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV_VOFFSET_T_EZHV_VOFFSET_T_SHIFT)) & SYSCON4_EZHV_VOFFSET_T_EZHV_VOFFSET_T_MASK)
/*! @} */

/*! @name EZHV2ARM_INT_EN - EZH-V To Arm Interrupt Enable */
/*! @{ */

#define SYSCON4_EZHV2ARM_INT_EN_INT_EN_MASK      (0xFFFFU)
#define SYSCON4_EZHV2ARM_INT_EN_INT_EN_SHIFT     (0U)
/*! INT_EN - Interrupt Enable */
#define SYSCON4_EZHV2ARM_INT_EN_INT_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV2ARM_INT_EN_INT_EN_SHIFT)) & SYSCON4_EZHV2ARM_INT_EN_INT_EN_MASK)

#define SYSCON4_EZHV2ARM_INT_EN_CPU0_RXEV_EN_MASK (0x10000U)
#define SYSCON4_EZHV2ARM_INT_EN_CPU0_RXEV_EN_SHIFT (16U)
/*! CPU0_RXEV_EN - CPU0 RXEV Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_EZHV2ARM_INT_EN_CPU0_RXEV_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV2ARM_INT_EN_CPU0_RXEV_EN_SHIFT)) & SYSCON4_EZHV2ARM_INT_EN_CPU0_RXEV_EN_MASK)

#define SYSCON4_EZHV2ARM_INT_EN_CPU1_RXEV_EN_MASK (0x20000U)
#define SYSCON4_EZHV2ARM_INT_EN_CPU1_RXEV_EN_SHIFT (17U)
/*! CPU1_RXEV_EN - CPU1 RXEV Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_EZHV2ARM_INT_EN_CPU1_RXEV_EN(x)  (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV2ARM_INT_EN_CPU1_RXEV_EN_SHIFT)) & SYSCON4_EZHV2ARM_INT_EN_CPU1_RXEV_EN_MASK)
/*! @} */

/*! @name EZHV2ARM_INT_CHAN - EZH-V Interrupt Channel */
/*! @{ */

#define SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_MASK  (0xFFFFU)
#define SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_SHIFT (0U)
/*! INT_CHAN - EZH-V Interrupt Outputs */
#define SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_SHIFT)) & SYSCON4_EZHV2ARM_INT_CHAN_INT_CHAN_MASK)
/*! @} */

/*! @name ARM2EZHV_INT_CTRL - Arm To EZH-V Interrupt Control */
/*! @{ */

#define SYSCON4_ARM2EZHV_INT_CTRL_MEIP_MASK      (0x1U)
#define SYSCON4_ARM2EZHV_INT_CTRL_MEIP_SHIFT     (0U)
/*! MEIP - Machine External Input Interrupt Request
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_ARM2EZHV_INT_CTRL_MEIP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_ARM2EZHV_INT_CTRL_MEIP_SHIFT)) & SYSCON4_ARM2EZHV_INT_CTRL_MEIP_MASK)

#define SYSCON4_ARM2EZHV_INT_CTRL_SEIP_MASK      (0x2U)
#define SYSCON4_ARM2EZHV_INT_CTRL_SEIP_SHIFT     (1U)
/*! SEIP - Supervisor External Input Interrupt Request
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_ARM2EZHV_INT_CTRL_SEIP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_ARM2EZHV_INT_CTRL_SEIP_SHIFT)) & SYSCON4_ARM2EZHV_INT_CTRL_SEIP_MASK)

#define SYSCON4_ARM2EZHV_INT_CTRL_MSIP_MASK      (0x4U)
#define SYSCON4_ARM2EZHV_INT_CTRL_MSIP_SHIFT     (2U)
/*! MSIP - Machine Software Input Interrupt Request
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_ARM2EZHV_INT_CTRL_MSIP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_ARM2EZHV_INT_CTRL_MSIP_SHIFT)) & SYSCON4_ARM2EZHV_INT_CTRL_MSIP_MASK)

#define SYSCON4_ARM2EZHV_INT_CTRL_MTIP_MASK      (0x8U)
#define SYSCON4_ARM2EZHV_INT_CTRL_MTIP_SHIFT     (3U)
/*! MTIP - Machine Timer Input Interrupt Request
 *  0b0..Disables
 *  0b1..Enables
 */
#define SYSCON4_ARM2EZHV_INT_CTRL_MTIP(x)        (((uint32_t)(((uint32_t)(x)) << SYSCON4_ARM2EZHV_INT_CTRL_MTIP_SHIFT)) & SYSCON4_ARM2EZHV_INT_CTRL_MTIP_MASK)
/*! @} */

/*! @name MIPI_DSI_CTRL - MIPI_DSI Control */
/*! @{ */

#define SYSCON4_MIPI_DSI_CTRL_DSI_SD_MASK        (0x1U)
#define SYSCON4_MIPI_DSI_CTRL_DSI_SD_SHIFT       (0U)
/*! DSI_SD - DSI Shutdown Control
 *  0b0..Do not send
 *  0b1..Send
 */
#define SYSCON4_MIPI_DSI_CTRL_DSI_SD(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_DSI_CTRL_DSI_SD_SHIFT)) & SYSCON4_MIPI_DSI_CTRL_DSI_SD_MASK)

#define SYSCON4_MIPI_DSI_CTRL_DSI_CM_MASK        (0x2U)
#define SYSCON4_MIPI_DSI_CTRL_DSI_CM_SHIFT       (1U)
/*! DSI_CM - DSI Color Mode Control
 *  0b0..Normal (full color) mode
 *  0b1..Low color mode (8-bit)
 */
#define SYSCON4_MIPI_DSI_CTRL_DSI_CM(x)          (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_DSI_CTRL_DSI_CM_SHIFT)) & SYSCON4_MIPI_DSI_CTRL_DSI_CM_MASK)

#define SYSCON4_MIPI_DSI_CTRL_DSI_TX_ACTIVE_MASK (0x4U)
#define SYSCON4_MIPI_DSI_CTRL_DSI_TX_ACTIVE_SHIFT (2U)
/*! DSI_TX_ACTIVE - DSI Transmit Active */
#define SYSCON4_MIPI_DSI_CTRL_DSI_TX_ACTIVE(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON4_MIPI_DSI_CTRL_DSI_TX_ACTIVE_SHIFT)) & SYSCON4_MIPI_DSI_CTRL_DSI_TX_ACTIVE_MASK)
/*! @} */

/*! @name MEDIA_AUTOGATE_EN - VDD2_MEDIA Auto Gating Enable */
/*! @{ */

#define SYSCON4_MEDIA_AUTOGATE_EN_MATRIX_EN_MASK (0x1U)
#define SYSCON4_MEDIA_AUTOGATE_EN_MATRIX_EN_SHIFT (0U)
/*! MATRIX_EN - VDD2_MEDIA Automatic Clock Gating Enable
 *  0b0..Disables clock gating (continuous clock)
 *  0b1..Enables clock gating
 */
#define SYSCON4_MEDIA_AUTOGATE_EN_MATRIX_EN(x)   (((uint32_t)(((uint32_t)(x)) << SYSCON4_MEDIA_AUTOGATE_EN_MATRIX_EN_SHIFT)) & SYSCON4_MEDIA_AUTOGATE_EN_MATRIX_EN_MASK)
/*! @} */

/*! @name USB0_MEM_CTRL - USB0 Memory Control */
/*! @{ */

#define SYSCON4_USB0_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_USB0_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB0_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_USB0_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_USB0_MEM_CTRL_MEM_WIG_MASK       (0x100U)
#define SYSCON4_USB0_MEM_CTRL_MEM_WIG_SHIFT      (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB0_MEM_CTRL_MEM_WIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB0_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_USB0_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_USB0_MEM_CTRL_MEM_RIG_MASK       (0x200U)
#define SYSCON4_USB0_MEM_CTRL_MEM_RIG_SHIFT      (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB0_MEM_CTRL_MEM_RIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB0_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_USB0_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name USB1_MEM_CTRL - USB1 Memory Control */
/*! @{ */

#define SYSCON4_USB1_MEM_CTRL_MEM_STDBY_MASK     (0x80U)
#define SYSCON4_USB1_MEM_CTRL_MEM_STDBY_SHIFT    (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB1_MEM_CTRL_MEM_STDBY(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_USB1_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_USB1_MEM_CTRL_MEM_WIG_MASK       (0x100U)
#define SYSCON4_USB1_MEM_CTRL_MEM_WIG_SHIFT      (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB1_MEM_CTRL_MEM_WIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB1_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_USB1_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_USB1_MEM_CTRL_MEM_RIG_MASK       (0x200U)
#define SYSCON4_USB1_MEM_CTRL_MEM_RIG_SHIFT      (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USB1_MEM_CTRL_MEM_RIG(x)         (((uint32_t)(((uint32_t)(x)) << SYSCON4_USB1_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_USB1_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name USDHC0_MEM_CTRL - uSDHC0 Memory Control */
/*! @{ */

#define SYSCON4_USDHC0_MEM_CTRL_MEM_STDBY_MASK   (0x80U)
#define SYSCON4_USDHC0_MEM_CTRL_MEM_STDBY_SHIFT  (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC0_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC0_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_USDHC0_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_USDHC0_MEM_CTRL_MEM_WIG_MASK     (0x100U)
#define SYSCON4_USDHC0_MEM_CTRL_MEM_WIG_SHIFT    (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC0_MEM_CTRL_MEM_WIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC0_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_USDHC0_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_USDHC0_MEM_CTRL_MEM_RIG_MASK     (0x200U)
#define SYSCON4_USDHC0_MEM_CTRL_MEM_RIG_SHIFT    (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC0_MEM_CTRL_MEM_RIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC0_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_USDHC0_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name USDHC1_MEM_CTRL - uSDHC1 Memory Control */
/*! @{ */

#define SYSCON4_USDHC1_MEM_CTRL_MEM_STDBY_MASK   (0x80U)
#define SYSCON4_USDHC1_MEM_CTRL_MEM_STDBY_SHIFT  (7U)
/*! MEM_STDBY - Memory Standby Mode
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC1_MEM_CTRL_MEM_STDBY(x)     (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC1_MEM_CTRL_MEM_STDBY_SHIFT)) & SYSCON4_USDHC1_MEM_CTRL_MEM_STDBY_MASK)

#define SYSCON4_USDHC1_MEM_CTRL_MEM_WIG_MASK     (0x100U)
#define SYSCON4_USDHC1_MEM_CTRL_MEM_WIG_SHIFT    (8U)
/*! MEM_WIG - Memory Write Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC1_MEM_CTRL_MEM_WIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC1_MEM_CTRL_MEM_WIG_SHIFT)) & SYSCON4_USDHC1_MEM_CTRL_MEM_WIG_MASK)

#define SYSCON4_USDHC1_MEM_CTRL_MEM_RIG_MASK     (0x200U)
#define SYSCON4_USDHC1_MEM_CTRL_MEM_RIG_SHIFT    (9U)
/*! MEM_RIG - Memory Read Input Gating
 *  0b0..Inactive
 *  0b1..Active
 */
#define SYSCON4_USDHC1_MEM_CTRL_MEM_RIG(x)       (((uint32_t)(((uint32_t)(x)) << SYSCON4_USDHC1_MEM_CTRL_MEM_RIG_SHIFT)) & SYSCON4_USDHC1_MEM_CTRL_MEM_RIG_MASK)
/*! @} */

/*! @name GPIO_BANK4_CFG - PIO4 Configuration */
/*! @{ */

#define SYSCON4_GPIO_BANK4_CFG_BANK4_CFG_MASK    (0x80000000U)
#define SYSCON4_GPIO_BANK4_CFG_BANK4_CFG_SHIFT   (31U)
/*! BANK4_CFG - Transmit Driver Size Configuration
 *  0b0..1.8 V
 *  0b1..1.2 V
 */
#define SYSCON4_GPIO_BANK4_CFG_BANK4_CFG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_GPIO_BANK4_CFG_BANK4_CFG_SHIFT)) & SYSCON4_GPIO_BANK4_CFG_BANK4_CFG_MASK)
/*! @} */

/*! @name GPIO_BANK5_CFG - PIO5 Configuration */
/*! @{ */

#define SYSCON4_GPIO_BANK5_CFG_BANK5_CFG_MASK    (0x80000000U)
#define SYSCON4_GPIO_BANK5_CFG_BANK5_CFG_SHIFT   (31U)
/*! BANK5_CFG - Transmit Driver Size Configuration
 *  0b0..1.8 V
 *  0b1..1.2 V
 */
#define SYSCON4_GPIO_BANK5_CFG_BANK5_CFG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_GPIO_BANK5_CFG_BANK5_CFG_SHIFT)) & SYSCON4_GPIO_BANK5_CFG_BANK5_CFG_MASK)
/*! @} */

/*! @name GPIO_BANK6_CFG - PIO6 Configuration */
/*! @{ */

#define SYSCON4_GPIO_BANK6_CFG_BANK6_CFG_MASK    (0x80000000U)
#define SYSCON4_GPIO_BANK6_CFG_BANK6_CFG_SHIFT   (31U)
/*! BANK6_CFG - Transmit Driver Size Configuration
 *  0b0..1.8 V
 *  0b1..1.2 V
 */
#define SYSCON4_GPIO_BANK6_CFG_BANK6_CFG(x)      (((uint32_t)(((uint32_t)(x)) << SYSCON4_GPIO_BANK6_CFG_BANK6_CFG_SHIFT)) & SYSCON4_GPIO_BANK6_CFG_BANK6_CFG_MASK)
/*! @} */

/*! @name USBPHY0_CLK_ACTIVE - USBPHY0 CLK Active */
/*! @{ */

#define SYSCON4_USBPHY0_CLK_ACTIVE_IPG_CLK_ACTIVE_MASK (0x1U)
#define SYSCON4_USBPHY0_CLK_ACTIVE_IPG_CLK_ACTIVE_SHIFT (0U)
/*! IPG_CLK_ACTIVE - IPG_CLK Active
 *  0b0..IPG_CLK is inactive
 *  0b1..IPG_CLK is active
 */
#define SYSCON4_USBPHY0_CLK_ACTIVE_IPG_CLK_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << SYSCON4_USBPHY0_CLK_ACTIVE_IPG_CLK_ACTIVE_SHIFT)) & SYSCON4_USBPHY0_CLK_ACTIVE_IPG_CLK_ACTIVE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCON4_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCON4_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCON4_H_ */

