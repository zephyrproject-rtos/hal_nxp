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
**         CMSIS Peripheral Access Layer for RSTCTL4
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
 * @file PERI_RSTCTL4.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RSTCTL4
 *
 * CMSIS Peripheral Access Layer for RSTCTL4
 */

#if !defined(PERI_RSTCTL4_H_)
#define PERI_RSTCTL4_H_                          /**< Symbol preventing repeated inclusion */

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
   -- RSTCTL4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL4_Peripheral_Access_Layer RSTCTL4 Peripheral Access Layer
 * @{
 */

/** RSTCTL4 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PRSTCTL0;                          /**< Media Domain Peripheral Reset Control 0, offset: 0x10 */
  __IO uint32_t PRSTCTL1;                          /**< Media Domain (Interface) Peripheral Reset Control 1, offset: 0x14 */
       uint8_t RESERVED_1[40];
  __O  uint32_t PRSTCTL0_SET;                      /**< Media Domain Peripheral Reset Control 0 SET, offset: 0x40 */
  __O  uint32_t PRSTCTL1_SET;                      /**< Media Domain (Interface) Peripheral Reset Control 1 SET, offset: 0x44 */
       uint8_t RESERVED_2[40];
  __O  uint32_t PRSTCTL0_CLR;                      /**< Media Domain Peripheral Reset Control 0 CLR, offset: 0x70 */
  __O  uint32_t PRSTCTL1_CLR;                      /**< Media Domain (Interface) Peripheral Reset Control 1 CLR, offset: 0x74 */
} RSTCTL4_Type;

/* ----------------------------------------------------------------------------
   -- RSTCTL4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RSTCTL4_Register_Masks RSTCTL4 Register Masks
 * @{
 */

/*! @name PRSTCTL0 - Media Domain Peripheral Reset Control 0 */
/*! @{ */

#define RSTCTL4_PRSTCTL0_VGPU_MASK               (0x4U)
#define RSTCTL4_PRSTCTL0_VGPU_SHIFT              (2U)
/*! VGPU - VGPU Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_VGPU(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_VGPU_SHIFT)) & RSTCTL4_PRSTCTL0_VGPU_MASK)

#define RSTCTL4_PRSTCTL0_LCDIF_MASK              (0x8U)
#define RSTCTL4_PRSTCTL0_LCDIF_SHIFT             (3U)
/*! LCDIF - LCDIF Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_LCDIF(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_LCDIF_SHIFT)) & RSTCTL4_PRSTCTL0_LCDIF_MASK)

#define RSTCTL4_PRSTCTL0_MIPI_DSI_HOST_MASK      (0x10U)
#define RSTCTL4_PRSTCTL0_MIPI_DSI_HOST_SHIFT     (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_MIPI_DSI_HOST(x)        (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_MIPI_DSI_HOST_SHIFT)) & RSTCTL4_PRSTCTL0_MIPI_DSI_HOST_MASK)

#define RSTCTL4_PRSTCTL0_EZHV_MASK               (0x20U)
#define RSTCTL4_PRSTCTL0_EZHV_SHIFT              (5U)
/*! EZHV - EZHV Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_EZHV(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_EZHV_SHIFT)) & RSTCTL4_PRSTCTL0_EZHV_MASK)

#define RSTCTL4_PRSTCTL0_JPEGDEC_MASK            (0x40U)
#define RSTCTL4_PRSTCTL0_JPEGDEC_SHIFT           (6U)
/*! JPEGDEC - JPEGDEC Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_JPEGDEC(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_JPEGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_JPEGDEC_MASK)

#define RSTCTL4_PRSTCTL0_PNGDEC_MASK             (0x80U)
#define RSTCTL4_PRSTCTL0_PNGDEC_SHIFT            (7U)
/*! PNGDEC - PNGDEC Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_PNGDEC(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_PNGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_PNGDEC_MASK)

#define RSTCTL4_PRSTCTL0_XSPI2_MASK              (0x100U)
#define RSTCTL4_PRSTCTL0_XSPI2_SHIFT             (8U)
/*! XSPI2 - XSPI2 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_XSPI2(x)                (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_XSPI2_SHIFT)) & RSTCTL4_PRSTCTL0_XSPI2_MASK)

#define RSTCTL4_PRSTCTL0_LPSPI14_MASK            (0x2000U)
#define RSTCTL4_PRSTCTL0_LPSPI14_SHIFT           (13U)
/*! LPSPI14 - LPSPI14 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_LPSPI14(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_LPSPI14_SHIFT)) & RSTCTL4_PRSTCTL0_LPSPI14_MASK)

#define RSTCTL4_PRSTCTL0_LPSPI16_MASK            (0x4000U)
#define RSTCTL4_PRSTCTL0_LPSPI16_SHIFT           (14U)
/*! LPSPI16 - LPSPI16 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_LPSPI16(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_LPSPI16_SHIFT)) & RSTCTL4_PRSTCTL0_LPSPI16_MASK)

#define RSTCTL4_PRSTCTL0_FLEXIO0_MASK            (0x8000U)
#define RSTCTL4_PRSTCTL0_FLEXIO0_SHIFT           (15U)
/*! FLEXIO0 - FLEXIO0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_FLEXIO0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_FLEXIO0_SHIFT)) & RSTCTL4_PRSTCTL0_FLEXIO0_MASK)
/*! @} */

/*! @name PRSTCTL1 - Media Domain (Interface) Peripheral Reset Control 1 */
/*! @{ */

#define RSTCTL4_PRSTCTL1_USB0_MASK               (0x1U)
#define RSTCTL4_PRSTCTL1_USB0_SHIFT              (0U)
/*! USB0 - USB0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_USB0(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_USB0_SHIFT)) & RSTCTL4_PRSTCTL1_USB0_MASK)

#define RSTCTL4_PRSTCTL1_USBPHY0_MASK            (0x2U)
#define RSTCTL4_PRSTCTL1_USBPHY0_SHIFT           (1U)
/*! USBPHY0 - USBPHY0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_USBPHY0(x)              (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_USBPHY0_SHIFT)) & RSTCTL4_PRSTCTL1_USBPHY0_MASK)

#define RSTCTL4_PRSTCTL1_USB1_MASK               (0x4U)
#define RSTCTL4_PRSTCTL1_USB1_SHIFT              (2U)
/*! USB1 - USB1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_USB1(x)                 (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_USB1_SHIFT)) & RSTCTL4_PRSTCTL1_USB1_MASK)

#define RSTCTL4_PRSTCTL1_USDHC0_MASK             (0x10U)
#define RSTCTL4_PRSTCTL1_USDHC0_SHIFT            (4U)
/*! uSDHC0 - uSDHC0 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_USDHC0(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_USDHC0_SHIFT)) & RSTCTL4_PRSTCTL1_USDHC0_MASK)

#define RSTCTL4_PRSTCTL1_USDHC1_MASK             (0x20U)
#define RSTCTL4_PRSTCTL1_USDHC1_SHIFT            (5U)
/*! uSDHC1 - uSDHC1 Reset
 *  0b0..Clears reset.
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_USDHC1(x)               (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_USDHC1_SHIFT)) & RSTCTL4_PRSTCTL1_USDHC1_MASK)
/*! @} */

/*! @name PRSTCTL0_SET - Media Domain Peripheral Reset Control 0 SET */
/*! @{ */

#define RSTCTL4_PRSTCTL0_SET_VGPU_MASK           (0x4U)
#define RSTCTL4_PRSTCTL0_SET_VGPU_SHIFT          (2U)
/*! VGPU - VGPU Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_VGPU(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_VGPU_SHIFT)) & RSTCTL4_PRSTCTL0_SET_VGPU_MASK)

#define RSTCTL4_PRSTCTL0_SET_LCDIF_MASK          (0x8U)
#define RSTCTL4_PRSTCTL0_SET_LCDIF_SHIFT         (3U)
/*! LCDIF - LCDIF Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_LCDIF(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_LCDIF_SHIFT)) & RSTCTL4_PRSTCTL0_SET_LCDIF_MASK)

#define RSTCTL4_PRSTCTL0_SET_MIPI_DSI_HOST_MASK  (0x10U)
#define RSTCTL4_PRSTCTL0_SET_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_MIPI_DSI_HOST(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_MIPI_DSI_HOST_SHIFT)) & RSTCTL4_PRSTCTL0_SET_MIPI_DSI_HOST_MASK)

#define RSTCTL4_PRSTCTL0_SET_EZHV_MASK           (0x20U)
#define RSTCTL4_PRSTCTL0_SET_EZHV_SHIFT          (5U)
/*! EZHV - EZHV Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_EZHV(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_EZHV_SHIFT)) & RSTCTL4_PRSTCTL0_SET_EZHV_MASK)

#define RSTCTL4_PRSTCTL0_SET_JPEGDEC_MASK        (0x40U)
#define RSTCTL4_PRSTCTL0_SET_JPEGDEC_SHIFT       (6U)
/*! JPEGDEC - JPEGDEC Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_JPEGDEC(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_JPEGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_SET_JPEGDEC_MASK)

#define RSTCTL4_PRSTCTL0_SET_PNGDEC_MASK         (0x80U)
#define RSTCTL4_PRSTCTL0_SET_PNGDEC_SHIFT        (7U)
/*! PNGDEC - PNGDEC Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_PNGDEC(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_PNGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_SET_PNGDEC_MASK)

#define RSTCTL4_PRSTCTL0_SET_XSPI2_MASK          (0x100U)
#define RSTCTL4_PRSTCTL0_SET_XSPI2_SHIFT         (8U)
/*! XSPI2 - XSPI2 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_XSPI2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_XSPI2_SHIFT)) & RSTCTL4_PRSTCTL0_SET_XSPI2_MASK)

#define RSTCTL4_PRSTCTL0_SET_LPSPI14_MASK        (0x2000U)
#define RSTCTL4_PRSTCTL0_SET_LPSPI14_SHIFT       (13U)
/*! LPSPI14 - LPSPI14 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_LPSPI14(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_LPSPI14_SHIFT)) & RSTCTL4_PRSTCTL0_SET_LPSPI14_MASK)

#define RSTCTL4_PRSTCTL0_SET_LPSPI16_MASK        (0x4000U)
#define RSTCTL4_PRSTCTL0_SET_LPSPI16_SHIFT       (14U)
/*! LPSPI16 - LPSPI16 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_LPSPI16(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_LPSPI16_SHIFT)) & RSTCTL4_PRSTCTL0_SET_LPSPI16_MASK)

#define RSTCTL4_PRSTCTL0_SET_FLEXIO0_MASK        (0x8000U)
#define RSTCTL4_PRSTCTL0_SET_FLEXIO0_SHIFT       (15U)
/*! FLEXIO0 - FLEXIO0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL0_SET_FLEXIO0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_SET_FLEXIO0_SHIFT)) & RSTCTL4_PRSTCTL0_SET_FLEXIO0_MASK)
/*! @} */

/*! @name PRSTCTL1_SET - Media Domain (Interface) Peripheral Reset Control 1 SET */
/*! @{ */

#define RSTCTL4_PRSTCTL1_SET_USB0_MASK           (0x1U)
#define RSTCTL4_PRSTCTL1_SET_USB0_SHIFT          (0U)
/*! USB0 - USB0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_SET_USB0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_SET_USB0_SHIFT)) & RSTCTL4_PRSTCTL1_SET_USB0_MASK)

#define RSTCTL4_PRSTCTL1_SET_USBPHY0_MASK        (0x2U)
#define RSTCTL4_PRSTCTL1_SET_USBPHY0_SHIFT       (1U)
/*! USBPHY0 - USBPHY0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_SET_USBPHY0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_SET_USBPHY0_SHIFT)) & RSTCTL4_PRSTCTL1_SET_USBPHY0_MASK)

#define RSTCTL4_PRSTCTL1_SET_USB1_MASK           (0x4U)
#define RSTCTL4_PRSTCTL1_SET_USB1_SHIFT          (2U)
/*! USB1 - USB1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_SET_USB1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_SET_USB1_SHIFT)) & RSTCTL4_PRSTCTL1_SET_USB1_MASK)

#define RSTCTL4_PRSTCTL1_SET_USDHC0_MASK         (0x10U)
#define RSTCTL4_PRSTCTL1_SET_USDHC0_SHIFT        (4U)
/*! uSDHC0 - uSDHC0 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_SET_USDHC0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_SET_USDHC0_SHIFT)) & RSTCTL4_PRSTCTL1_SET_USDHC0_MASK)

#define RSTCTL4_PRSTCTL1_SET_USDHC1_MASK         (0x20U)
#define RSTCTL4_PRSTCTL1_SET_USDHC1_SHIFT        (5U)
/*! uSDHC1 - uSDHC1 Reset
 *  0b0..No effect
 *  0b1..Sets reset.
 */
#define RSTCTL4_PRSTCTL1_SET_USDHC1(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_SET_USDHC1_SHIFT)) & RSTCTL4_PRSTCTL1_SET_USDHC1_MASK)
/*! @} */

/*! @name PRSTCTL0_CLR - Media Domain Peripheral Reset Control 0 CLR */
/*! @{ */

#define RSTCTL4_PRSTCTL0_CLR_VGPU_MASK           (0x4U)
#define RSTCTL4_PRSTCTL0_CLR_VGPU_SHIFT          (2U)
/*! VGPU - VGPU Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_VGPU(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_VGPU_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_VGPU_MASK)

#define RSTCTL4_PRSTCTL0_CLR_LCDIF_MASK          (0x8U)
#define RSTCTL4_PRSTCTL0_CLR_LCDIF_SHIFT         (3U)
/*! LCDIF - LCDIF Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_LCDIF(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_LCDIF_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_LCDIF_MASK)

#define RSTCTL4_PRSTCTL0_CLR_MIPI_DSI_HOST_MASK  (0x10U)
#define RSTCTL4_PRSTCTL0_CLR_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_MIPI_DSI_HOST(x)    (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_MIPI_DSI_HOST_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_MIPI_DSI_HOST_MASK)

#define RSTCTL4_PRSTCTL0_CLR_EZHV_MASK           (0x20U)
#define RSTCTL4_PRSTCTL0_CLR_EZHV_SHIFT          (5U)
/*! EZHV - EZHV Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_EZHV(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_EZHV_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_EZHV_MASK)

#define RSTCTL4_PRSTCTL0_CLR_JPEGDEC_MASK        (0x40U)
#define RSTCTL4_PRSTCTL0_CLR_JPEGDEC_SHIFT       (6U)
/*! JPEGDEC - JPEGDEC Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_JPEGDEC(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_JPEGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_JPEGDEC_MASK)

#define RSTCTL4_PRSTCTL0_CLR_PNGDEC_MASK         (0x80U)
#define RSTCTL4_PRSTCTL0_CLR_PNGDEC_SHIFT        (7U)
/*! PNGDEC - PNGDEC Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_PNGDEC(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_PNGDEC_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_PNGDEC_MASK)

#define RSTCTL4_PRSTCTL0_CLR_XSPI2_MASK          (0x100U)
#define RSTCTL4_PRSTCTL0_CLR_XSPI2_SHIFT         (8U)
/*! XSPI2 - XSPI2 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_XSPI2(x)            (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_XSPI2_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_XSPI2_MASK)

#define RSTCTL4_PRSTCTL0_CLR_LPSPI14_MASK        (0x2000U)
#define RSTCTL4_PRSTCTL0_CLR_LPSPI14_SHIFT       (13U)
/*! LPSPI14 - LPSPI14 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_LPSPI14(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_LPSPI14_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_LPSPI14_MASK)

#define RSTCTL4_PRSTCTL0_CLR_LPSPI16_MASK        (0x4000U)
#define RSTCTL4_PRSTCTL0_CLR_LPSPI16_SHIFT       (14U)
/*! LPSPI16 - LPSPI16 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_LPSPI16(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_LPSPI16_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_LPSPI16_MASK)

#define RSTCTL4_PRSTCTL0_CLR_FLEXIO0_MASK        (0x8000U)
#define RSTCTL4_PRSTCTL0_CLR_FLEXIO0_SHIFT       (15U)
/*! FLEXIO0 - FLEXIO0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL0_CLR_FLEXIO0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL0_CLR_FLEXIO0_SHIFT)) & RSTCTL4_PRSTCTL0_CLR_FLEXIO0_MASK)
/*! @} */

/*! @name PRSTCTL1_CLR - Media Domain (Interface) Peripheral Reset Control 1 CLR */
/*! @{ */

#define RSTCTL4_PRSTCTL1_CLR_USB0_MASK           (0x1U)
#define RSTCTL4_PRSTCTL1_CLR_USB0_SHIFT          (0U)
/*! USB0 - USB0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL1_CLR_USB0(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_CLR_USB0_SHIFT)) & RSTCTL4_PRSTCTL1_CLR_USB0_MASK)

#define RSTCTL4_PRSTCTL1_CLR_USBPHY0_MASK        (0x2U)
#define RSTCTL4_PRSTCTL1_CLR_USBPHY0_SHIFT       (1U)
/*! USBPHY0 - USBPHY0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL1_CLR_USBPHY0(x)          (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_CLR_USBPHY0_SHIFT)) & RSTCTL4_PRSTCTL1_CLR_USBPHY0_MASK)

#define RSTCTL4_PRSTCTL1_CLR_USB1_MASK           (0x4U)
#define RSTCTL4_PRSTCTL1_CLR_USB1_SHIFT          (2U)
/*! USB1 - USB1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL1_CLR_USB1(x)             (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_CLR_USB1_SHIFT)) & RSTCTL4_PRSTCTL1_CLR_USB1_MASK)

#define RSTCTL4_PRSTCTL1_CLR_USDHC0_MASK         (0x10U)
#define RSTCTL4_PRSTCTL1_CLR_USDHC0_SHIFT        (4U)
/*! uSDHC0 - uSDHC0 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL1_CLR_USDHC0(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_CLR_USDHC0_SHIFT)) & RSTCTL4_PRSTCTL1_CLR_USDHC0_MASK)

#define RSTCTL4_PRSTCTL1_CLR_USDHC1_MASK         (0x20U)
#define RSTCTL4_PRSTCTL1_CLR_USDHC1_SHIFT        (5U)
/*! uSDHC1 - uSDHC1 Reset
 *  0b0..No effect
 *  0b1..Clears reset.
 */
#define RSTCTL4_PRSTCTL1_CLR_USDHC1(x)           (((uint32_t)(((uint32_t)(x)) << RSTCTL4_PRSTCTL1_CLR_USDHC1_SHIFT)) & RSTCTL4_PRSTCTL1_CLR_USDHC1_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RSTCTL4_Register_Masks */


/*!
 * @}
 */ /* end of group RSTCTL4_Peripheral_Access_Layer */


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


#endif  /* PERI_RSTCTL4_H_ */

