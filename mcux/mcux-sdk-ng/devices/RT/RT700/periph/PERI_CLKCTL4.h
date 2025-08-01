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
**         CMSIS Peripheral Access Layer for CLKCTL4
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
 * @file PERI_CLKCTL4.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CLKCTL4
 *
 * CMSIS Peripheral Access Layer for CLKCTL4
 */

#if !defined(PERI_CLKCTL4_H_)
#define PERI_CLKCTL4_H_                          /**< Symbol preventing repeated inclusion */

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
   -- CLKCTL4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL4_Peripheral_Access_Layer CLKCTL4 Peripheral Access Layer
 * @{
 */

/** CLKCTL4 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t PSCCTL0_MEDIA;                     /**< VDD2_COMP Media Peripheral Clock Control 0, offset: 0x10 */
  __IO uint32_t PSCCTL1_MEDIA;                     /**< VDD2_COMP Media Peripheral Clock Control 1, offset: 0x14 */
       uint8_t RESERVED_1[40];
  __IO uint32_t PSCCTL0_MEDIA_SET;                 /**< VDD2_COMP Media Peripheral Clock Control 0 Set, offset: 0x40 */
  __IO uint32_t PSCCTL1_MEDIA_SET;                 /**< VDD2_COMP Media Peripheral Clock Control 1 Set, offset: 0x44 */
       uint8_t RESERVED_2[40];
  __IO uint32_t PSCCTL0_MEDIA_CLR;                 /**< VDD2_COMP Media Peripheral Clock Control 0 Clear, offset: 0x70 */
  __IO uint32_t PSCCTL1_MEDIA_CLR;                 /**< VDD2_COMP Media Peripheral Clock Control 1 Clear, offset: 0x74 */
       uint8_t RESERVED_3[24];
  __IO uint32_t ONE_SRC_CLKSLICE_ENABLE;           /**< One Source Clock Slice Enable for VDD2_COMP Core, offset: 0x90 */
       uint8_t RESERVED_4[16];
  __IO uint32_t MEDIAVDDNCLKSEL;                   /**< VDDN_MEDIA Clock Source Select, offset: 0xA4 */
       uint8_t RESERVED_5[4];
  __IO uint32_t MEDIAVDDNCLKDIV;                   /**< VDDN_MEDIA Clock Divider, offset: 0xAC */
       uint8_t RESERVED_6[84];
  __IO uint32_t MEDIAMAINCLKSEL;                   /**< Media Main Clock Source Select, offset: 0x104 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MEDIAMAINCLKDIV;                   /**< Media Main Clock Divider, offset: 0x10C */
  __IO uint32_t MDNBASECLKSEL;                     /**< VDDN_MEDIA Base Clock Source Select, offset: 0x110 */
  __IO uint32_t MD2BASECLKSEL;                     /**< VDD2_MEDIA Base Clock Source Select, offset: 0x114 */
       uint8_t RESERVED_8[232];
  __IO uint32_t XSPI2FCLKSEL;                      /**< XSPI2 Functional Clock Source Select, offset: 0x200 */
  __IO uint32_t XSPI2FCLKDIV;                      /**< XSPI2 Functional Clock Divider, offset: 0x204 */
       uint8_t RESERVED_9[24];
  __IO uint32_t USBFCLKSEL;                        /**< USB0 Functional Clock Source Select, offset: 0x220 */
       uint8_t RESERVED_10[28];
  __IO uint32_t EUSBFCLKSEL;                       /**< USB1 (eUSB) Functional Clock Source Select, offset: 0x240 */
       uint8_t RESERVED_11[28];
  __IO uint32_t SDIO0FCLKSEL;                      /**< SDIO0 Functional Clock Source Select, offset: 0x260 */
  __IO uint32_t SDIO0FCLKDIV;                      /**< SDIO0 Functional Clock Divider, offset: 0x264 */
       uint8_t RESERVED_12[24];
  __IO uint32_t SDIO1FCLKSEL;                      /**< SDIO1 Functional Clock Source Select, offset: 0x280 */
  __IO uint32_t SDIO1FCLKDIV;                      /**< SDIO1 Functional Clock Divider, offset: 0x284 */
       uint8_t RESERVED_13[120];
  __IO uint32_t DPHYCLKSEL;                        /**< MIPI_DSI_Host PHY Clock Source Select, offset: 0x300 */
  __IO uint32_t DPHYCLKDIV;                        /**< MIPI_DSI_Host PHY Clock Divider, offset: 0x304 */
  __IO uint32_t DPHYESCCLKSEL;                     /**< MIPI_DSI_Host DPHY Escape Mode Clock Source Select, offset: 0x308 */
  __IO uint32_t DPHYESCRXCLKDIV;                   /**< MIPI_DSI_Host DPHY Escape Mode Receive Clock Divider, offset: 0x30C */
  __IO uint32_t DPHYESCTXCLKDIV;                   /**< MIPI_DSI_Host DPHY Escape Mode Transmit Clock Divider, offset: 0x310 */
       uint8_t RESERVED_14[12];
  __IO uint32_t VGPUCLKSEL;                        /**< VGPU Clock Source Select, offset: 0x320 */
  __IO uint32_t VGPUCLKDIV;                        /**< VGPU Clock Divider, offset: 0x324 */
  __IO uint32_t LPSPI14CLKSEL;                     /**< LPSPI14 Clock Source Select, offset: 0x328 */
  __IO uint32_t LPSPI14CLKDIV;                     /**< LPSPI14 Clock Divider, offset: 0x32C */
  __IO uint32_t LPSPI16CLKSEL;                     /**< LPSPI16 Clock Source Select, offset: 0x330 */
  __IO uint32_t LPSPI16CLKDIV;                     /**< LPSPI16 Clock Divider, offset: 0x334 */
  __IO uint32_t FLEXIOCLKSEL;                      /**< FLEXIO Clock Source Select, offset: 0x338 */
  __IO uint32_t FLEXIOCLKDIV;                      /**< FLEXIO Clock Divider, offset: 0x33C */
  __IO uint32_t LCDIFPIXELCLKSEL;                  /**< LCDIF Pixel Clock Source Select, offset: 0x340 */
  __IO uint32_t LCDIFPIXELCLKDIV;                  /**< LCDIF Pixel Clock Divider, offset: 0x344 */
       uint8_t RESERVED_15[952];
  __IO uint32_t LOWFREQCLKDIV;                     /**< Low frequency Clock Divider, offset: 0x700 */
       uint8_t RESERVED_16[268];
  __IO uint32_t PSCCTL0_SENS;                      /**< VDD1_SENSE Media Peripheral Clock Control 0, offset: 0x810 */
  __IO uint32_t PSCCTL1_SENS;                      /**< VDD1_SENSE Media Peripheral Clock Control 1, offset: 0x814 */
       uint8_t RESERVED_17[40];
  __IO uint32_t PSCCTL0_SENS_SET;                  /**< VDD1_SENSE Media Peripheral Clock Control 0 Set, offset: 0x840 */
  __IO uint32_t PSCCTL1_SENS_SET;                  /**< VDD1_SENSE Media Peripheral Clock Control 1 Set, offset: 0x844 */
       uint8_t RESERVED_18[40];
  __IO uint32_t PSCCTL0_SENS_CLR;                  /**< VDD1_SENSE Media Peripheral Clock Control 0 Clear, offset: 0x870 */
  __IO uint32_t PSCCTL1_SENS_CLR;                  /**< VDD1_SENSE Media Peripheral Clock Control 1 Clear, offset: 0x874 */
       uint8_t RESERVED_19[24];
  __IO uint32_t ONE_SRC_CLKSLICE_ENABLE_SENSE;     /**< One Source Clock Slice Enable for VDD1_SENSE Core, offset: 0x890 */
} CLKCTL4_Type;

/* ----------------------------------------------------------------------------
   -- CLKCTL4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CLKCTL4_Register_Masks CLKCTL4 Register Masks
 * @{
 */

/*! @name PSCCTL0_MEDIA - VDD2_COMP Media Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL4_PSCCTL0_MEDIA_VGPU_MASK          (0x4U)
#define CLKCTL4_PSCCTL0_MEDIA_VGPU_SHIFT         (2U)
/*! VGPU - VGPU Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_VGPU(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_VGPU_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_MIPI_DSI_HOST_MASK (0x10U)
#define CLKCTL4_PSCCTL0_MEDIA_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_MIPI_DSI_HOST(x)   (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_LPSPI16_MASK       (0x20U)
#define CLKCTL4_PSCCTL0_MEDIA_LPSPI16_SHIFT      (5U)
/*! LPSPI16 - LPSPT16 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_LPSPI16(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_LPSPI14_MASK       (0x40U)
#define CLKCTL4_PSCCTL0_MEDIA_LPSPI14_SHIFT      (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_LPSPI14(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_XSPI2_MASK         (0x100U)
#define CLKCTL4_PSCCTL0_MEDIA_XSPI2_SHIFT        (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_XSPI2(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_MMU2_MASK          (0x800U)
#define CLKCTL4_PSCCTL0_MEDIA_MMU2_SHIFT         (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_MMU2(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_MMU2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY5_MASK       (0x2000U)
#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY5_SHIFT      (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY5(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_FLEXIO0_MASK       (0x8000U)
#define CLKCTL4_PSCCTL0_MEDIA_FLEXIO0_SHIFT      (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_FLEXIO0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_LCDIF_MASK         (0x400000U)
#define CLKCTL4_PSCCTL0_MEDIA_LCDIF_SHIFT        (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_LCDIF(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SYSCON4_MASK       (0x800000U)
#define CLKCTL4_PSCCTL0_MEDIA_SYSCON4_SHIFT      (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SYSCON4(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_JPEGDEC_MASK       (0x1000000U)
#define CLKCTL4_PSCCTL0_MEDIA_JPEGDEC_SHIFT      (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_JPEGDEC(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_PNGDEC_MASK        (0x2000000U)
#define CLKCTL4_PSCCTL0_MEDIA_PNGDEC_SHIFT       (25U)
/*! PNGDEC - PNGDEC Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_PNGDEC(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_EZHV_MASK          (0x4000000U)
#define CLKCTL4_PSCCTL0_MEDIA_EZHV_SHIFT         (26U)
/*! EZHV - EZHV Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_EZHV(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_EZHV_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_AXBS_EZH_MASK      (0x10000000U)
#define CLKCTL4_PSCCTL0_MEDIA_AXBS_EZH_SHIFT     (28U)
/*! AXBS_EZH - AXBS for EZHV Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_AXBS_EZH(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY2_MASK       (0x20000000U)
#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY2_SHIFT      (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_GLIKEY2(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_MEDIA - VDD2_COMP Media Peripheral Clock Control 1 */
/*! @{ */

#define CLKCTL4_PSCCTL1_MEDIA_USB0_MASK          (0x1U)
#define CLKCTL4_PSCCTL1_MEDIA_USB0_SHIFT         (0U)
/*! USB0 - USB0 and USBPHY0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_USB0(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_USB0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_USB0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_USB1_MASK          (0x4U)
#define CLKCTL4_PSCCTL1_MEDIA_USB1_SHIFT         (2U)
/*! USB1 - USB1 and eUSBPHY Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_USB1(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_USB1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_USB1_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_USDHC0_MASK        (0x10U)
#define CLKCTL4_PSCCTL1_MEDIA_USDHC0_SHIFT       (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_USDHC0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_USDHC1_MASK        (0x20U)
#define CLKCTL4_PSCCTL1_MEDIA_USDHC1_SHIFT       (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_USDHC1(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_USDHC1_MASK)
/*! @} */

/*! @name PSCCTL0_MEDIA_SET - VDD2_COMP Media Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL4_PSCCTL0_MEDIA_SET_VGPU_MASK      (0x4U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_VGPU_SHIFT     (2U)
/*! VGPU - VGPU Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_VGPU(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_VGPU_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_MIPI_DSI_HOST_MASK (0x10U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_MIPI_DSI_HOST(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI16_MASK   (0x20U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI16_SHIFT  (5U)
/*! LPSPI16 - LPSPI16 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI16(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI14_MASK   (0x40U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI14_SHIFT  (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI14(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_XSPI2_MASK     (0x100U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_XSPI2_SHIFT    (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_XSPI2(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_MMU2_MASK      (0x800U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_MMU2_SHIFT     (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_MMU2(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_MMU2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY5_MASK   (0x2000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY5_SHIFT  (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY5(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_FLEXIO0_MASK   (0x8000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_FLEXIO0_SHIFT  (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_FLEXIO0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_LCDIF_MASK     (0x400000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_LCDIF_SHIFT    (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_LCDIF(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_SYSCON4_MASK   (0x800000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_SYSCON4_SHIFT  (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_SYSCON4(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_JPEGDEC_MASK   (0x1000000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_JPEGDEC_SHIFT  (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_JPEGDEC(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_PNGDEC_MASK    (0x2000000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_PNGDEC_SHIFT   (25U)
/*! PNGDEC - PNGDEC Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_PNGDEC(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_EZHV_MASK      (0x4000000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_EZHV_SHIFT     (26U)
/*! EZHV - EZHV Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_EZHV(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_EZHV_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_AXBS_EZH_MASK  (0x10000000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_AXBS_EZH_SHIFT (28U)
/*! AXBS_EZH - AXBS for EZHV Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_AXBS_EZH(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY2_MASK   (0x20000000U)
#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY2_SHIFT  (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY2(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_SET_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_MEDIA_SET - VDD2_COMP Media Peripheral Clock Control 1 Set */
/*! @{ */

#define CLKCTL4_PSCCTL1_MEDIA_SET_USB0_MASK      (0x1U)
#define CLKCTL4_PSCCTL1_MEDIA_SET_USB0_SHIFT     (0U)
/*! USB0 - USB0 and USBPHY0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_SET_USB0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_SET_USB0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_SET_USB0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_SET_USB1_MASK      (0x4U)
#define CLKCTL4_PSCCTL1_MEDIA_SET_USB1_SHIFT     (2U)
/*! USB1 - USB1 and eUSBPHY Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_SET_USB1(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_SET_USB1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_SET_USB1_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC0_MASK    (0x10U)
#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC0_SHIFT   (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_SET_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_SET_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC1_MASK    (0x20U)
#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC1_SHIFT   (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_MEDIA_SET_USDHC1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_SET_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_SET_USDHC1_MASK)
/*! @} */

/*! @name PSCCTL0_MEDIA_CLR - VDD2_COMP Media Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL4_PSCCTL0_MEDIA_CLR_VGPU_MASK      (0x4U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_VGPU_SHIFT     (2U)
/*! VGPU - VGPU Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_VGPU(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_VGPU_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_MIPI_DSI_HOST_MASK (0x10U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_MIPI_DSI_HOST(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI16_MASK   (0x20U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI16_SHIFT  (5U)
/*! LPSPI16 - LPSPI16 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI16(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI14_MASK   (0x40U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI14_SHIFT  (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI14(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_XSPI2_MASK     (0x100U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_XSPI2_SHIFT    (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_XSPI2(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_MMU2_MASK      (0x800U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_MMU2_SHIFT     (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_MMU2(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_MMU2_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY5_MASK   (0x2000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY5_SHIFT  (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY5(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_FLEXIO0_MASK   (0x8000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_FLEXIO0_SHIFT  (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_FLEXIO0(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_LCDIF_MASK     (0x400000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LCDIF_SHIFT    (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_LCDIF(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_SYSCON4_MASK   (0x800000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_SYSCON4_SHIFT  (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_SYSCON4(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_JPEGDEC_MASK   (0x1000000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_JPEGDEC_SHIFT  (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_JPEGDEC(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_PNGDEC_MASK    (0x2000000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_PNGDEC_SHIFT   (25U)
/*! PNGDEC - PNG Decoder Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_PNGDEC(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_EZHV_MASK      (0x4000000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_EZHV_SHIFT     (26U)
/*! EZHV - EZHV Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_EZHV(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_EZHV_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_AXBS_EZH_MASK  (0x10000000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_AXBS_EZH_SHIFT (28U)
/*! AXBS_EZH - AXBS_EZHV Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_AXBS_EZH(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY2_MASK   (0x20000000U)
#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY2_SHIFT  (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY2(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_MEDIA_CLR_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_MEDIA_CLR - VDD2_COMP Media Peripheral Clock Control 1 Clear */
/*! @{ */

#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB0_MASK      (0x1U)
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB0_SHIFT     (0U)
/*! USB0 - USB0 and USBPHY0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB0(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_CLR_USB0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_CLR_USB0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB1_MASK      (0x4U)
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB1_SHIFT     (2U)
/*! USB1 - USB1 and eUSBPHY Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USB1(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_CLR_USB1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_CLR_USB1_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC0_MASK    (0x10U)
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC0_SHIFT   (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC1_MASK    (0x20U)
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC1_SHIFT   (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC1(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_MEDIA_CLR_USDHC1_MASK)
/*! @} */

/*! @name ONE_SRC_CLKSLICE_ENABLE - One Source Clock Slice Enable for VDD2_COMP Core */
/*! @{ */

#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_USBPHY_REFCLK_EN_MASK (0x1U)
#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_USBPHY_REFCLK_EN_SHIFT (0U)
/*! USBPHY_REFCLK_EN - USBPHY0 Reference Clock
 *  0b0..Gates USBPHY0 reference clock.
 *  0b1..Enables USBPHY0 reference clock.
 */
#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_USBPHY_REFCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_USBPHY_REFCLK_EN_SHIFT)) & CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_USBPHY_REFCLK_EN_MASK)
/*! @} */

/*! @name MEDIAVDDNCLKSEL - VDDN_MEDIA Clock Source Select */
/*! @{ */

#define CLKCTL4_MEDIAVDDNCLKSEL_SEL_MASK         (0x3U)
#define CLKCTL4_MEDIAVDDNCLKSEL_SEL_SHIFT        (0U)
/*! SEL - VDDN Clock Source Select
 *  0b00..baseclk_mdn
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd2
 */
#define CLKCTL4_MEDIAVDDNCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAVDDNCLKSEL_SEL_SHIFT)) & CLKCTL4_MEDIAVDDNCLKSEL_SEL_MASK)
/*! @} */

/*! @name MEDIAVDDNCLKDIV - VDDN_MEDIA Clock Divider */
/*! @{ */

#define CLKCTL4_MEDIAVDDNCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL4_MEDIAVDDNCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_MEDIAVDDNCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAVDDNCLKDIV_DIV_SHIFT)) & CLKCTL4_MEDIAVDDNCLKDIV_DIV_MASK)

#define CLKCTL4_MEDIAVDDNCLKDIV_BUSY_MASK        (0x10000000U)
#define CLKCTL4_MEDIAVDDNCLKDIV_BUSY_SHIFT       (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_MEDIAVDDNCLKDIV_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAVDDNCLKDIV_BUSY_SHIFT)) & CLKCTL4_MEDIAVDDNCLKDIV_BUSY_MASK)

#define CLKCTL4_MEDIAVDDNCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL4_MEDIAVDDNCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_MEDIAVDDNCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAVDDNCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_MEDIAVDDNCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MEDIAMAINCLKSEL - Media Main Clock Source Select */
/*! @{ */

#define CLKCTL4_MEDIAMAINCLKSEL_SEL_MASK         (0x3U)
#define CLKCTL4_MEDIAMAINCLKSEL_SEL_SHIFT        (0U)
/*! SEL - Media Main Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd2
 */
#define CLKCTL4_MEDIAMAINCLKSEL_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAMAINCLKSEL_SEL_SHIFT)) & CLKCTL4_MEDIAMAINCLKSEL_SEL_MASK)
/*! @} */

/*! @name MEDIAMAINCLKDIV - Media Main Clock Divider */
/*! @{ */

#define CLKCTL4_MEDIAMAINCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL4_MEDIAMAINCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_MEDIAMAINCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAMAINCLKDIV_DIV_SHIFT)) & CLKCTL4_MEDIAMAINCLKDIV_DIV_MASK)

#define CLKCTL4_MEDIAMAINCLKDIV_BUSY_MASK        (0x10000000U)
#define CLKCTL4_MEDIAMAINCLKDIV_BUSY_SHIFT       (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_MEDIAMAINCLKDIV_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAMAINCLKDIV_BUSY_SHIFT)) & CLKCTL4_MEDIAMAINCLKDIV_BUSY_MASK)

#define CLKCTL4_MEDIAMAINCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL4_MEDIAMAINCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_MEDIAMAINCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MEDIAMAINCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_MEDIAMAINCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name MDNBASECLKSEL - VDDN_MEDIA Base Clock Source Select */
/*! @{ */

#define CLKCTL4_MDNBASECLKSEL_SEL_MASK           (0x3U)
#define CLKCTL4_MDNBASECLKSEL_SEL_SHIFT          (0U)
/*! SEL - VDDN_MEDIA Base Clock Source Select
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL4_MDNBASECLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MDNBASECLKSEL_SEL_SHIFT)) & CLKCTL4_MDNBASECLKSEL_SEL_MASK)
/*! @} */

/*! @name MD2BASECLKSEL - VDD2_MEDIA Base Clock Source Select */
/*! @{ */

#define CLKCTL4_MD2BASECLKSEL_SEL_MASK           (0x3U)
#define CLKCTL4_MD2BASECLKSEL_SEL_SHIFT          (0U)
/*! SEL - Media VDD2 Base Clock Source Select
 *  0b00..fro1_div3
 *  0b01..fro1_max
 *  0b10..fro0_div3
 *  0b11..1m_lposc
 */
#define CLKCTL4_MD2BASECLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_MD2BASECLKSEL_SEL_SHIFT)) & CLKCTL4_MD2BASECLKSEL_SEL_MASK)
/*! @} */

/*! @name XSPI2FCLKSEL - XSPI2 Functional Clock Source Select */
/*! @{ */

#define CLKCTL4_XSPI2FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL4_XSPI2FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - XSPI2 Clock Source Select
 *  0b00..baseclk_comn
 *  0b01..audio_pll_pfd1
 *  0b10..fro0_max
 *  0b11..main_pll_pfd3
 */
#define CLKCTL4_XSPI2FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_XSPI2FCLKSEL_SEL_SHIFT)) & CLKCTL4_XSPI2FCLKSEL_SEL_MASK)

#define CLKCTL4_XSPI2FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL4_XSPI2FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for XSPI2 clock.
 *  0b1..Enables mux output for XSPI2 clock.
 */
#define CLKCTL4_XSPI2FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_XSPI2FCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_XSPI2FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name XSPI2FCLKDIV - XSPI2 Functional Clock Divider */
/*! @{ */

#define CLKCTL4_XSPI2FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL4_XSPI2FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_XSPI2FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_XSPI2FCLKDIV_DIV_SHIFT)) & CLKCTL4_XSPI2FCLKDIV_DIV_MASK)

#define CLKCTL4_XSPI2FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL4_XSPI2FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_XSPI2FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_XSPI2FCLKDIV_BUSY_SHIFT)) & CLKCTL4_XSPI2FCLKDIV_BUSY_MASK)

#define CLKCTL4_XSPI2FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL4_XSPI2FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_XSPI2FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_XSPI2FCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_XSPI2FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name USBFCLKSEL - USB0 Functional Clock Source Select */
/*! @{ */

#define CLKCTL4_USBFCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL4_USBFCLKSEL_SEL_SHIFT             (0U)
/*! SEL - Clock Source Select
 *  0b00..wake32k_clk
 *  0b01..1m_lposc
 *  0b10..osc_clk_usb
 *  0b11..Reserved
 */
#define CLKCTL4_USBFCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL4_USBFCLKSEL_SEL_SHIFT)) & CLKCTL4_USBFCLKSEL_SEL_MASK)

#define CLKCTL4_USBFCLKSEL_SEL_EN_MASK           (0x4U)
#define CLKCTL4_USBFCLKSEL_SEL_EN_SHIFT          (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates USB0 clock. It is necessary to read back bit3 with the value of 1 to confirm the clock is already gated then go ahead.
 *  0b1..Enables USB0 clock.
 */
#define CLKCTL4_USBFCLKSEL_SEL_EN(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_USBFCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_USBFCLKSEL_SEL_EN_MASK)

#define CLKCTL4_USBFCLKSEL_GATED_FLAG_MASK       (0x8U)
#define CLKCTL4_USBFCLKSEL_GATED_FLAG_SHIFT      (3U)
/*! GATED_FLAG - Gate Flag
 *  0b0..The USB0 fclk is not gated.
 *  0b1..The USB0 fclk is gated.
 */
#define CLKCTL4_USBFCLKSEL_GATED_FLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_USBFCLKSEL_GATED_FLAG_SHIFT)) & CLKCTL4_USBFCLKSEL_GATED_FLAG_MASK)
/*! @} */

/*! @name EUSBFCLKSEL - USB1 (eUSB) Functional Clock Source Select */
/*! @{ */

#define CLKCTL4_EUSBFCLKSEL_SEL_MASK             (0x3U)
#define CLKCTL4_EUSBFCLKSEL_SEL_SHIFT            (0U)
/*! SEL - USB1 Clock Source Select
 *  0b00..wake32k_clk
 *  0b01..1m_lposc
 *  0b10..osc_clk_eusb
 *  0b11..Reserved
 */
#define CLKCTL4_EUSBFCLKSEL_SEL(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL4_EUSBFCLKSEL_SEL_SHIFT)) & CLKCTL4_EUSBFCLKSEL_SEL_MASK)

#define CLKCTL4_EUSBFCLKSEL_SEL_EN_MASK          (0x4U)
#define CLKCTL4_EUSBFCLKSEL_SEL_EN_SHIFT         (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for USB1 functional clock. It is necessary to read back bit3 with the value of 1 to
 *       confirm the clock is already gated then go ahead.
 *  0b1..Enables mux output for USB1 functional clock.
 */
#define CLKCTL4_EUSBFCLKSEL_SEL_EN(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_EUSBFCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_EUSBFCLKSEL_SEL_EN_MASK)

#define CLKCTL4_EUSBFCLKSEL_GATED_FLAG_MASK      (0x8U)
#define CLKCTL4_EUSBFCLKSEL_GATED_FLAG_SHIFT     (3U)
/*! GATED_FLAG - Gate Flag
 *  0b0..The USB1 functional clock is not gated.
 *  0b1..The USB1 functional clock is gated.
 */
#define CLKCTL4_EUSBFCLKSEL_GATED_FLAG(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_EUSBFCLKSEL_GATED_FLAG_SHIFT)) & CLKCTL4_EUSBFCLKSEL_GATED_FLAG_MASK)
/*! @} */

/*! @name SDIO0FCLKSEL - SDIO0 Functional Clock Source Select */
/*! @{ */

#define CLKCTL4_SDIO0FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL4_SDIO0FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - SDIO0 Functional Clock Source Select
 *  0b00..baseclk_mdn
 *  0b01..audio_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd2
 */
#define CLKCTL4_SDIO0FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKSEL_SEL_SHIFT)) & CLKCTL4_SDIO0FCLKSEL_SEL_MASK)

#define CLKCTL4_SDIO0FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL4_SDIO0FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for SD/MMC/SDIO interface 0 clock.
 *  0b1..Enables mux output for SD/MMC/SDIO interface 0 clock.
 */
#define CLKCTL4_SDIO0FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_SDIO0FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SDIO0FCLKDIV - SDIO0 Functional Clock Divider */
/*! @{ */

#define CLKCTL4_SDIO0FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL4_SDIO0FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_SDIO0FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKDIV_DIV_SHIFT)) & CLKCTL4_SDIO0FCLKDIV_DIV_MASK)

#define CLKCTL4_SDIO0FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL4_SDIO0FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_SDIO0FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKDIV_BUSY_SHIFT)) & CLKCTL4_SDIO0FCLKDIV_BUSY_MASK)

#define CLKCTL4_SDIO0FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL4_SDIO0FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_SDIO0FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKDIV_RESET_SHIFT)) & CLKCTL4_SDIO0FCLKDIV_RESET_MASK)

#define CLKCTL4_SDIO0FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL4_SDIO0FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_SDIO0FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKDIV_HALT_SHIFT)) & CLKCTL4_SDIO0FCLKDIV_HALT_MASK)

#define CLKCTL4_SDIO0FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL4_SDIO0FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_SDIO0FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO0FCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_SDIO0FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name SDIO1FCLKSEL - SDIO1 Functional Clock Source Select */
/*! @{ */

#define CLKCTL4_SDIO1FCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL4_SDIO1FCLKSEL_SEL_SHIFT           (0U)
/*! SEL - SDIO1 Clock Source Select
 *  0b00..VDDN_MEDIA base clock
 *  0b01..Audio PLL PFD0 clock
 *  0b10..fro0_max
 *  0b11..Main PLL PFD1 clock
 */
#define CLKCTL4_SDIO1FCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKSEL_SEL_SHIFT)) & CLKCTL4_SDIO1FCLKSEL_SEL_MASK)

#define CLKCTL4_SDIO1FCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL4_SDIO1FCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for SD/MMC/SDIO interface 1 clock.
 *  0b1..Enables mux output for SD/MMC/SDIO interface 1 clock.
 */
#define CLKCTL4_SDIO1FCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_SDIO1FCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name SDIO1FCLKDIV - SDIO1 Functional Clock Divider */
/*! @{ */

#define CLKCTL4_SDIO1FCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL4_SDIO1FCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_SDIO1FCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKDIV_DIV_SHIFT)) & CLKCTL4_SDIO1FCLKDIV_DIV_MASK)

#define CLKCTL4_SDIO1FCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL4_SDIO1FCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_SDIO1FCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKDIV_BUSY_SHIFT)) & CLKCTL4_SDIO1FCLKDIV_BUSY_MASK)

#define CLKCTL4_SDIO1FCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL4_SDIO1FCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_SDIO1FCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKDIV_RESET_SHIFT)) & CLKCTL4_SDIO1FCLKDIV_RESET_MASK)

#define CLKCTL4_SDIO1FCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL4_SDIO1FCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_SDIO1FCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKDIV_HALT_SHIFT)) & CLKCTL4_SDIO1FCLKDIV_HALT_MASK)

#define CLKCTL4_SDIO1FCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL4_SDIO1FCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_SDIO1FCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_SDIO1FCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_SDIO1FCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYCLKSEL - MIPI_DSI_Host PHY Clock Source Select */
/*! @{ */

#define CLKCTL4_DPHYCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL4_DPHYCLKSEL_SEL_SHIFT             (0U)
/*! SEL - MIPI_DSI_Host PHY Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..Reserved
 *  0b10..fro0_max
 *  0b11..audio_pll_pfd2
 */
#define CLKCTL4_DPHYCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKSEL_SEL_SHIFT)) & CLKCTL4_DPHYCLKSEL_SEL_MASK)

#define CLKCTL4_DPHYCLKSEL_SEL_EN_MASK           (0x4U)
#define CLKCTL4_DPHYCLKSEL_SEL_EN_SHIFT          (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for MIPI_DSI_Host PHY clock.
 *  0b1..Enables mux output for MIPI_DSI_Host PHY clock.
 */
#define CLKCTL4_DPHYCLKSEL_SEL_EN(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_DPHYCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name DPHYCLKDIV - MIPI_DSI_Host PHY Clock Divider */
/*! @{ */

#define CLKCTL4_DPHYCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL4_DPHYCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_DPHYCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKDIV_DIV_SHIFT)) & CLKCTL4_DPHYCLKDIV_DIV_MASK)

#define CLKCTL4_DPHYCLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL4_DPHYCLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_DPHYCLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKDIV_BUSY_SHIFT)) & CLKCTL4_DPHYCLKDIV_BUSY_MASK)

#define CLKCTL4_DPHYCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL4_DPHYCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_DPHYCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKDIV_RESET_SHIFT)) & CLKCTL4_DPHYCLKDIV_RESET_MASK)

#define CLKCTL4_DPHYCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL4_DPHYCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_DPHYCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKDIV_HALT_SHIFT)) & CLKCTL4_DPHYCLKDIV_HALT_MASK)

#define CLKCTL4_DPHYCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL4_DPHYCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_DPHYCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_DPHYCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYESCCLKSEL - MIPI_DSI_Host DPHY Escape Mode Clock Source Select */
/*! @{ */

#define CLKCTL4_DPHYESCCLKSEL_SEL_MASK           (0x3U)
#define CLKCTL4_DPHYESCCLKSEL_SEL_SHIFT          (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..main_pll_pfd1
 *  0b10..fro0_max
 *  0b11..audio_pll_pfd2
 */
#define CLKCTL4_DPHYESCCLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCCLKSEL_SEL_SHIFT)) & CLKCTL4_DPHYESCCLKSEL_SEL_MASK)

#define CLKCTL4_DPHYESCCLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL4_DPHYESCCLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for MIPI_DSI_Host DPHY clock.
 *  0b1..Enables mux output for MIPI_DSI_Host DPHY clock.
 */
#define CLKCTL4_DPHYESCCLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_DPHYESCCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name DPHYESCRXCLKDIV - MIPI_DSI_Host DPHY Escape Mode Receive Clock Divider */
/*! @{ */

#define CLKCTL4_DPHYESCRXCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL4_DPHYESCRXCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_DPHYESCRXCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCRXCLKDIV_DIV_SHIFT)) & CLKCTL4_DPHYESCRXCLKDIV_DIV_MASK)

#define CLKCTL4_DPHYESCRXCLKDIV_BUSY_MASK        (0x10000000U)
#define CLKCTL4_DPHYESCRXCLKDIV_BUSY_SHIFT       (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_DPHYESCRXCLKDIV_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCRXCLKDIV_BUSY_SHIFT)) & CLKCTL4_DPHYESCRXCLKDIV_BUSY_MASK)

#define CLKCTL4_DPHYESCRXCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL4_DPHYESCRXCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_DPHYESCRXCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCRXCLKDIV_RESET_SHIFT)) & CLKCTL4_DPHYESCRXCLKDIV_RESET_MASK)

#define CLKCTL4_DPHYESCRXCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL4_DPHYESCRXCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_DPHYESCRXCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCRXCLKDIV_HALT_SHIFT)) & CLKCTL4_DPHYESCRXCLKDIV_HALT_MASK)

#define CLKCTL4_DPHYESCRXCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL4_DPHYESCRXCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_DPHYESCRXCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCRXCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_DPHYESCRXCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name DPHYESCTXCLKDIV - MIPI_DSI_Host DPHY Escape Mode Transmit Clock Divider */
/*! @{ */

#define CLKCTL4_DPHYESCTXCLKDIV_DIV_MASK         (0xFFU)
#define CLKCTL4_DPHYESCTXCLKDIV_DIV_SHIFT        (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_DPHYESCTXCLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCTXCLKDIV_DIV_SHIFT)) & CLKCTL4_DPHYESCTXCLKDIV_DIV_MASK)

#define CLKCTL4_DPHYESCTXCLKDIV_BUSY_MASK        (0x10000000U)
#define CLKCTL4_DPHYESCTXCLKDIV_BUSY_SHIFT       (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_DPHYESCTXCLKDIV_BUSY(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCTXCLKDIV_BUSY_SHIFT)) & CLKCTL4_DPHYESCTXCLKDIV_BUSY_MASK)

#define CLKCTL4_DPHYESCTXCLKDIV_RESET_MASK       (0x20000000U)
#define CLKCTL4_DPHYESCTXCLKDIV_RESET_SHIFT      (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_DPHYESCTXCLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCTXCLKDIV_RESET_SHIFT)) & CLKCTL4_DPHYESCTXCLKDIV_RESET_MASK)

#define CLKCTL4_DPHYESCTXCLKDIV_HALT_MASK        (0x40000000U)
#define CLKCTL4_DPHYESCTXCLKDIV_HALT_SHIFT       (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_DPHYESCTXCLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCTXCLKDIV_HALT_SHIFT)) & CLKCTL4_DPHYESCTXCLKDIV_HALT_MASK)

#define CLKCTL4_DPHYESCTXCLKDIV_REQFLAG_MASK     (0x80000000U)
#define CLKCTL4_DPHYESCTXCLKDIV_REQFLAG_SHIFT    (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_DPHYESCTXCLKDIV_REQFLAG(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_DPHYESCTXCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_DPHYESCTXCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name VGPUCLKSEL - VGPU Clock Source Select */
/*! @{ */

#define CLKCTL4_VGPUCLKSEL_SEL_MASK              (0x3U)
#define CLKCTL4_VGPUCLKSEL_SEL_SHIFT             (0U)
/*! SEL - VGPU Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..main_pll_pfd0
 *  0b10..fro0_max
 *  0b11..main_pll_pfd2
 */
#define CLKCTL4_VGPUCLKSEL_SEL(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKSEL_SEL_SHIFT)) & CLKCTL4_VGPUCLKSEL_SEL_MASK)

#define CLKCTL4_VGPUCLKSEL_SEL_EN_MASK           (0x4U)
#define CLKCTL4_VGPUCLKSEL_SEL_EN_SHIFT          (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for VGPU clock.
 *  0b1..Enables mux output for VGPU clock.
 */
#define CLKCTL4_VGPUCLKSEL_SEL_EN(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_VGPUCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name VGPUCLKDIV - VGPU Clock Divider */
/*! @{ */

#define CLKCTL4_VGPUCLKDIV_DIV_MASK              (0xFFU)
#define CLKCTL4_VGPUCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_VGPUCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKDIV_DIV_SHIFT)) & CLKCTL4_VGPUCLKDIV_DIV_MASK)

#define CLKCTL4_VGPUCLKDIV_BUSY_MASK             (0x10000000U)
#define CLKCTL4_VGPUCLKDIV_BUSY_SHIFT            (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_VGPUCLKDIV_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKDIV_BUSY_SHIFT)) & CLKCTL4_VGPUCLKDIV_BUSY_MASK)

#define CLKCTL4_VGPUCLKDIV_RESET_MASK            (0x20000000U)
#define CLKCTL4_VGPUCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_VGPUCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKDIV_RESET_SHIFT)) & CLKCTL4_VGPUCLKDIV_RESET_MASK)

#define CLKCTL4_VGPUCLKDIV_HALT_MASK             (0x40000000U)
#define CLKCTL4_VGPUCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_VGPUCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKDIV_HALT_SHIFT)) & CLKCTL4_VGPUCLKDIV_HALT_MASK)

#define CLKCTL4_VGPUCLKDIV_REQFLAG_MASK          (0x80000000U)
#define CLKCTL4_VGPUCLKDIV_REQFLAG_SHIFT         (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_VGPUCLKDIV_REQFLAG(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_VGPUCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_VGPUCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LPSPI14CLKSEL - LPSPI14 Clock Source Select */
/*! @{ */

#define CLKCTL4_LPSPI14CLKSEL_SEL_MASK           (0x3U)
#define CLKCTL4_LPSPI14CLKSEL_SEL_SHIFT          (0U)
/*! SEL - Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..fro0_max
 *  0b10..main_pll_pfd0
 *  0b11..fro1_max
 */
#define CLKCTL4_LPSPI14CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKSEL_SEL_SHIFT)) & CLKCTL4_LPSPI14CLKSEL_SEL_MASK)

#define CLKCTL4_LPSPI14CLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL4_LPSPI14CLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for LPSPI14 clock.
 *  0b1..Enables mux output for LPSPI14 clock.
 */
#define CLKCTL4_LPSPI14CLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKSEL_SEL_EN_SHIFT)) & CLKCTL4_LPSPI14CLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name LPSPI14CLKDIV - LPSPI14 Clock Divider */
/*! @{ */

#define CLKCTL4_LPSPI14CLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL4_LPSPI14CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_LPSPI14CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKDIV_DIV_SHIFT)) & CLKCTL4_LPSPI14CLKDIV_DIV_MASK)

#define CLKCTL4_LPSPI14CLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL4_LPSPI14CLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_LPSPI14CLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKDIV_BUSY_SHIFT)) & CLKCTL4_LPSPI14CLKDIV_BUSY_MASK)

#define CLKCTL4_LPSPI14CLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL4_LPSPI14CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_LPSPI14CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKDIV_RESET_SHIFT)) & CLKCTL4_LPSPI14CLKDIV_RESET_MASK)

#define CLKCTL4_LPSPI14CLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL4_LPSPI14CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_LPSPI14CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKDIV_HALT_SHIFT)) & CLKCTL4_LPSPI14CLKDIV_HALT_MASK)

#define CLKCTL4_LPSPI14CLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL4_LPSPI14CLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_LPSPI14CLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI14CLKDIV_REQFLAG_SHIFT)) & CLKCTL4_LPSPI14CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LPSPI16CLKSEL - LPSPI16 Clock Source Select */
/*! @{ */

#define CLKCTL4_LPSPI16CLKSEL_SEL_MASK           (0x3U)
#define CLKCTL4_LPSPI16CLKSEL_SEL_SHIFT          (0U)
/*! SEL - LPSPI16 Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..fro0_max
 *  0b10..main_pll_pfd0
 *  0b11..fro1_max
 */
#define CLKCTL4_LPSPI16CLKSEL_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKSEL_SEL_SHIFT)) & CLKCTL4_LPSPI16CLKSEL_SEL_MASK)

#define CLKCTL4_LPSPI16CLKSEL_SEL_EN_MASK        (0x4U)
#define CLKCTL4_LPSPI16CLKSEL_SEL_EN_SHIFT       (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for LPSPI16 clock.
 *  0b1..Enables mux output for LPSPI16 clock.
 */
#define CLKCTL4_LPSPI16CLKSEL_SEL_EN(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKSEL_SEL_EN_SHIFT)) & CLKCTL4_LPSPI16CLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name LPSPI16CLKDIV - LPSPI16 Clock Divider */
/*! @{ */

#define CLKCTL4_LPSPI16CLKDIV_DIV_MASK           (0xFFU)
#define CLKCTL4_LPSPI16CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_LPSPI16CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKDIV_DIV_SHIFT)) & CLKCTL4_LPSPI16CLKDIV_DIV_MASK)

#define CLKCTL4_LPSPI16CLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL4_LPSPI16CLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_LPSPI16CLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKDIV_BUSY_SHIFT)) & CLKCTL4_LPSPI16CLKDIV_BUSY_MASK)

#define CLKCTL4_LPSPI16CLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL4_LPSPI16CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_LPSPI16CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKDIV_RESET_SHIFT)) & CLKCTL4_LPSPI16CLKDIV_RESET_MASK)

#define CLKCTL4_LPSPI16CLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL4_LPSPI16CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_LPSPI16CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKDIV_HALT_SHIFT)) & CLKCTL4_LPSPI16CLKDIV_HALT_MASK)

#define CLKCTL4_LPSPI16CLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL4_LPSPI16CLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_LPSPI16CLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LPSPI16CLKDIV_REQFLAG_SHIFT)) & CLKCTL4_LPSPI16CLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name FLEXIOCLKSEL - FLEXIO Clock Source Select */
/*! @{ */

#define CLKCTL4_FLEXIOCLKSEL_SEL_MASK            (0x3U)
#define CLKCTL4_FLEXIOCLKSEL_SEL_SHIFT           (0U)
/*! SEL - FLEXIO Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..fro0_max
 *  0b10..fro1_max
 *  0b11..main_pll_pfd3
 */
#define CLKCTL4_FLEXIOCLKSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKSEL_SEL_SHIFT)) & CLKCTL4_FLEXIOCLKSEL_SEL_MASK)

#define CLKCTL4_FLEXIOCLKSEL_SEL_EN_MASK         (0x4U)
#define CLKCTL4_FLEXIOCLKSEL_SEL_EN_SHIFT        (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for FLEXIO clock.
 *  0b1..Enables mux output for FLEXIO clock.
 */
#define CLKCTL4_FLEXIOCLKSEL_SEL_EN(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_FLEXIOCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name FLEXIOCLKDIV - FLEXIO Clock Divider */
/*! @{ */

#define CLKCTL4_FLEXIOCLKDIV_DIV_MASK            (0xFFU)
#define CLKCTL4_FLEXIOCLKDIV_DIV_SHIFT           (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_FLEXIOCLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKDIV_DIV_SHIFT)) & CLKCTL4_FLEXIOCLKDIV_DIV_MASK)

#define CLKCTL4_FLEXIOCLKDIV_BUSY_MASK           (0x10000000U)
#define CLKCTL4_FLEXIOCLKDIV_BUSY_SHIFT          (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_FLEXIOCLKDIV_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKDIV_BUSY_SHIFT)) & CLKCTL4_FLEXIOCLKDIV_BUSY_MASK)

#define CLKCTL4_FLEXIOCLKDIV_RESET_MASK          (0x20000000U)
#define CLKCTL4_FLEXIOCLKDIV_RESET_SHIFT         (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_FLEXIOCLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKDIV_RESET_SHIFT)) & CLKCTL4_FLEXIOCLKDIV_RESET_MASK)

#define CLKCTL4_FLEXIOCLKDIV_HALT_MASK           (0x40000000U)
#define CLKCTL4_FLEXIOCLKDIV_HALT_SHIFT          (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_FLEXIOCLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKDIV_HALT_SHIFT)) & CLKCTL4_FLEXIOCLKDIV_HALT_MASK)

#define CLKCTL4_FLEXIOCLKDIV_REQFLAG_MASK        (0x80000000U)
#define CLKCTL4_FLEXIOCLKDIV_REQFLAG_SHIFT       (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_FLEXIOCLKDIV_REQFLAG(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_FLEXIOCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_FLEXIOCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LCDIFPIXELCLKSEL - LCDIF Pixel Clock Source Select */
/*! @{ */

#define CLKCTL4_LCDIFPIXELCLKSEL_SEL_MASK        (0x3U)
#define CLKCTL4_LCDIFPIXELCLKSEL_SEL_SHIFT       (0U)
/*! SEL - LCDIF Pixel Clock Source Select
 *  0b00..baseclk_md2
 *  0b01..main_pll_pfd2
 *  0b10..fro0_max
 *  0b11..audio_pll_pfd1
 */
#define CLKCTL4_LCDIFPIXELCLKSEL_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKSEL_SEL_SHIFT)) & CLKCTL4_LCDIFPIXELCLKSEL_SEL_MASK)

#define CLKCTL4_LCDIFPIXELCLKSEL_SEL_EN_MASK     (0x4U)
#define CLKCTL4_LCDIFPIXELCLKSEL_SEL_EN_SHIFT    (2U)
/*! SEL_EN - Clock Mux Output Enable
 *  0b0..Gates mux output for LCDIF clock.
 *  0b1..Enables mux output for LCDIF clock.
 */
#define CLKCTL4_LCDIFPIXELCLKSEL_SEL_EN(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKSEL_SEL_EN_SHIFT)) & CLKCTL4_LCDIFPIXELCLKSEL_SEL_EN_MASK)
/*! @} */

/*! @name LCDIFPIXELCLKDIV - LCDIF Pixel Clock Divider */
/*! @{ */

#define CLKCTL4_LCDIFPIXELCLKDIV_DIV_MASK        (0xFFU)
#define CLKCTL4_LCDIFPIXELCLKDIV_DIV_SHIFT       (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_LCDIFPIXELCLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKDIV_DIV_SHIFT)) & CLKCTL4_LCDIFPIXELCLKDIV_DIV_MASK)

#define CLKCTL4_LCDIFPIXELCLKDIV_BUSY_MASK       (0x10000000U)
#define CLKCTL4_LCDIFPIXELCLKDIV_BUSY_SHIFT      (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_LCDIFPIXELCLKDIV_BUSY(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKDIV_BUSY_SHIFT)) & CLKCTL4_LCDIFPIXELCLKDIV_BUSY_MASK)

#define CLKCTL4_LCDIFPIXELCLKDIV_RESET_MASK      (0x20000000U)
#define CLKCTL4_LCDIFPIXELCLKDIV_RESET_SHIFT     (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_LCDIFPIXELCLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKDIV_RESET_SHIFT)) & CLKCTL4_LCDIFPIXELCLKDIV_RESET_MASK)

#define CLKCTL4_LCDIFPIXELCLKDIV_HALT_MASK       (0x40000000U)
#define CLKCTL4_LCDIFPIXELCLKDIV_HALT_SHIFT      (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_LCDIFPIXELCLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKDIV_HALT_SHIFT)) & CLKCTL4_LCDIFPIXELCLKDIV_HALT_MASK)

#define CLKCTL4_LCDIFPIXELCLKDIV_REQFLAG_MASK    (0x80000000U)
#define CLKCTL4_LCDIFPIXELCLKDIV_REQFLAG_SHIFT   (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_LCDIFPIXELCLKDIV_REQFLAG(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LCDIFPIXELCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_LCDIFPIXELCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name LOWFREQCLKDIV - Low frequency Clock Divider */
/*! @{ */

#define CLKCTL4_LOWFREQCLKDIV_DIV_MASK           (0xFFFFU)
#define CLKCTL4_LOWFREQCLKDIV_DIV_SHIFT          (0U)
/*! DIV - Clock Divider Value Select */
#define CLKCTL4_LOWFREQCLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LOWFREQCLKDIV_DIV_SHIFT)) & CLKCTL4_LOWFREQCLKDIV_DIV_MASK)

#define CLKCTL4_LOWFREQCLKDIV_BUSY_MASK          (0x10000000U)
#define CLKCTL4_LOWFREQCLKDIV_BUSY_SHIFT         (28U)
/*! BUSY - Busy Flag
 *  0b0..The CLKOUT is outputted with the new divider value.
 *  0b1..A change is being made to the divider value.
 */
#define CLKCTL4_LOWFREQCLKDIV_BUSY(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LOWFREQCLKDIV_BUSY_SHIFT)) & CLKCTL4_LOWFREQCLKDIV_BUSY_MASK)

#define CLKCTL4_LOWFREQCLKDIV_RESET_MASK         (0x20000000U)
#define CLKCTL4_LOWFREQCLKDIV_RESET_SHIFT        (29U)
/*! RESET - Divider Counter Reset
 *  0b0..No effect
 *  0b1..Resets the divider counter.
 */
#define CLKCTL4_LOWFREQCLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LOWFREQCLKDIV_RESET_SHIFT)) & CLKCTL4_LOWFREQCLKDIV_RESET_MASK)

#define CLKCTL4_LOWFREQCLKDIV_HALT_MASK          (0x40000000U)
#define CLKCTL4_LOWFREQCLKDIV_HALT_SHIFT         (30U)
/*! HALT - Divider Counter Halt
 *  0b0..No effect
 *  0b1..Halts (stops) the divider counter.
 */
#define CLKCTL4_LOWFREQCLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LOWFREQCLKDIV_HALT_SHIFT)) & CLKCTL4_LOWFREQCLKDIV_HALT_MASK)

#define CLKCTL4_LOWFREQCLKDIV_REQFLAG_MASK       (0x80000000U)
#define CLKCTL4_LOWFREQCLKDIV_REQFLAG_SHIFT      (31U)
/*! REQFLAG - Request Flag
 *  0b0..The change to the divider value has been finished.
 *  0b1..The change is being made to the divider value.
 */
#define CLKCTL4_LOWFREQCLKDIV_REQFLAG(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_LOWFREQCLKDIV_REQFLAG_SHIFT)) & CLKCTL4_LOWFREQCLKDIV_REQFLAG_MASK)
/*! @} */

/*! @name PSCCTL0_SENS - VDD1_SENSE Media Peripheral Clock Control 0 */
/*! @{ */

#define CLKCTL4_PSCCTL0_SENS_VGPU_MASK           (0x4U)
#define CLKCTL4_PSCCTL0_SENS_VGPU_SHIFT          (2U)
/*! VGPU - VGPU Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_VGPU(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_SENS_VGPU_MASK)

#define CLKCTL4_PSCCTL0_SENS_MIPI_DSI_HOST_MASK  (0x10U)
#define CLKCTL4_PSCCTL0_SENS_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_MIPI_DSI_HOST(x)    (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_SENS_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_SENS_LPSPI16_MASK        (0x20U)
#define CLKCTL4_PSCCTL0_SENS_LPSPI16_SHIFT       (5U)
/*! LPSPI16 - LPSPT16 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_LPSPI16(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_SENS_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_SENS_LPSPI14_MASK        (0x40U)
#define CLKCTL4_PSCCTL0_SENS_LPSPI14_SHIFT       (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_LPSPI14(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_SENS_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_SENS_XSPI2_MASK          (0x100U)
#define CLKCTL4_PSCCTL0_SENS_XSPI2_SHIFT         (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_XSPI2(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_SENS_MMU2_MASK           (0x800U)
#define CLKCTL4_PSCCTL0_SENS_MMU2_SHIFT          (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_MMU2(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_MMU2_MASK)

#define CLKCTL4_PSCCTL0_SENS_GLIKEY5_MASK        (0x2000U)
#define CLKCTL4_PSCCTL0_SENS_GLIKEY5_SHIFT       (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_GLIKEY5(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_SENS_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_SENS_FLEXIO0_MASK        (0x8000U)
#define CLKCTL4_PSCCTL0_SENS_FLEXIO0_SHIFT       (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_FLEXIO0(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_SENS_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_SENS_LCDIF_MASK          (0x400000U)
#define CLKCTL4_PSCCTL0_SENS_LCDIF_SHIFT         (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_LCDIF(x)            (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_SENS_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_SENS_SYSCON4_MASK        (0x800000U)
#define CLKCTL4_PSCCTL0_SENS_SYSCON4_SHIFT       (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SYSCON4(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_SENS_JPEGDEC_MASK        (0x1000000U)
#define CLKCTL4_PSCCTL0_SENS_JPEGDEC_SHIFT       (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_JPEGDEC(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_PNGDEC_MASK         (0x2000000U)
#define CLKCTL4_PSCCTL0_SENS_PNGDEC_SHIFT        (25U)
/*! PNGDEC - PNGDEC Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_PNGDEC(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_EZHV_MASK           (0x4000000U)
#define CLKCTL4_PSCCTL0_SENS_EZHV_SHIFT          (26U)
/*! EZHV - EZHV Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_EZHV(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_SENS_EZHV_MASK)

#define CLKCTL4_PSCCTL0_SENS_AXBS_EZH_MASK       (0x10000000U)
#define CLKCTL4_PSCCTL0_SENS_AXBS_EZH_SHIFT      (28U)
/*! AXBS_EZH - AXBS for EZHV Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_AXBS_EZH(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_SENS_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_SENS_GLIKEY2_MASK        (0x20000000U)
#define CLKCTL4_PSCCTL0_SENS_GLIKEY2_SHIFT       (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_GLIKEY2(x)          (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_SENS - VDD1_SENSE Media Peripheral Clock Control 1 */
/*! @{ */

#define CLKCTL4_PSCCTL1_SENS_USB0_MASK           (0x1U)
#define CLKCTL4_PSCCTL1_SENS_USB0_SHIFT          (0U)
/*! USB0 - USB0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_USB0(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_USB0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_USB0_MASK)

#define CLKCTL4_PSCCTL1_SENS_USB1_MASK           (0x4U)
#define CLKCTL4_PSCCTL1_SENS_USB1_SHIFT          (2U)
/*! USB1 - USB1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_USB1(x)             (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_USB1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_USB1_MASK)

#define CLKCTL4_PSCCTL1_SENS_USDHC0_MASK         (0x10U)
#define CLKCTL4_PSCCTL1_SENS_USDHC0_SHIFT        (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_USDHC0(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_SENS_USDHC1_MASK         (0x20U)
#define CLKCTL4_PSCCTL1_SENS_USDHC1_SHIFT        (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..Disable
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_USDHC1(x)           (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_USDHC1_MASK)
/*! @} */

/*! @name PSCCTL0_SENS_SET - VDD1_SENSE Media Peripheral Clock Control 0 Set */
/*! @{ */

#define CLKCTL4_PSCCTL0_SENS_SET_VGPU_MASK       (0x4U)
#define CLKCTL4_PSCCTL0_SENS_SET_VGPU_SHIFT      (2U)
/*! VGPU - VGPU Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_VGPU(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_VGPU_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_MIPI_DSI_HOST_MASK (0x10U)
#define CLKCTL4_PSCCTL0_SENS_SET_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_MIPI_DSI_HOST(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI16_MASK    (0x20U)
#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI16_SHIFT   (5U)
/*! LPSPI16 - LPSPI16 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI16(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI14_MASK    (0x40U)
#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI14_SHIFT   (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_LPSPI14(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_XSPI2_MASK      (0x100U)
#define CLKCTL4_PSCCTL0_SENS_SET_XSPI2_SHIFT     (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_XSPI2(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_MMU2_MASK       (0x800U)
#define CLKCTL4_PSCCTL0_SENS_SET_MMU2_SHIFT      (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_MMU2(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_MMU2_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY5_MASK    (0x2000U)
#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY5_SHIFT   (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY5(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_FLEXIO0_MASK    (0x8000U)
#define CLKCTL4_PSCCTL0_SENS_SET_FLEXIO0_SHIFT   (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_FLEXIO0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_LCDIF_MASK      (0x400000U)
#define CLKCTL4_PSCCTL0_SENS_SET_LCDIF_SHIFT     (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_LCDIF(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_SYSCON4_MASK    (0x800000U)
#define CLKCTL4_PSCCTL0_SENS_SET_SYSCON4_SHIFT   (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_SYSCON4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_JPEGDEC_MASK    (0x1000000U)
#define CLKCTL4_PSCCTL0_SENS_SET_JPEGDEC_SHIFT   (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_JPEGDEC(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_PNGDEC_MASK     (0x2000000U)
#define CLKCTL4_PSCCTL0_SENS_SET_PNGDEC_SHIFT    (25U)
/*! PNGDEC - PNGDEC Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_PNGDEC(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_EZHV_MASK       (0x4000000U)
#define CLKCTL4_PSCCTL0_SENS_SET_EZHV_SHIFT      (26U)
/*! EZHV - EZHV Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_EZHV(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_EZHV_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_AXBS_EZH_MASK   (0x10000000U)
#define CLKCTL4_PSCCTL0_SENS_SET_AXBS_EZH_SHIFT  (28U)
/*! AXBS_EZH - AXBS for EZHV Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_AXBS_EZH(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY2_MASK    (0x20000000U)
#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY2_SHIFT   (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL0_SENS_SET_GLIKEY2(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_SET_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_SET_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_SENS_SET - VDD1_SENSE Media Peripheral Clock Control 1 Set */
/*! @{ */

#define CLKCTL4_PSCCTL1_SENS_SET_USB0_MASK       (0x1U)
#define CLKCTL4_PSCCTL1_SENS_SET_USB0_SHIFT      (0U)
/*! USB0 - USB0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_SET_USB0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_SET_USB0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_SET_USB0_MASK)

#define CLKCTL4_PSCCTL1_SENS_SET_USB1_MASK       (0x4U)
#define CLKCTL4_PSCCTL1_SENS_SET_USB1_SHIFT      (2U)
/*! USB1 - USB1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_SET_USB1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_SET_USB1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_SET_USB1_MASK)

#define CLKCTL4_PSCCTL1_SENS_SET_USDHC0_MASK     (0x10U)
#define CLKCTL4_PSCCTL1_SENS_SET_USDHC0_SHIFT    (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_SET_USDHC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_SET_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_SET_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_SENS_SET_USDHC1_MASK     (0x20U)
#define CLKCTL4_PSCCTL1_SENS_SET_USDHC1_SHIFT    (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..No effect
 *  0b1..Enable
 */
#define CLKCTL4_PSCCTL1_SENS_SET_USDHC1(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_SET_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_SET_USDHC1_MASK)
/*! @} */

/*! @name PSCCTL0_SENS_CLR - VDD1_SENSE Media Peripheral Clock Control 0 Clear */
/*! @{ */

#define CLKCTL4_PSCCTL0_SENS_CLR_VGPU_MASK       (0x4U)
#define CLKCTL4_PSCCTL0_SENS_CLR_VGPU_SHIFT      (2U)
/*! VGPU - VGPU Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_VGPU(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_VGPU_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_VGPU_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_MIPI_DSI_HOST_MASK (0x10U)
#define CLKCTL4_PSCCTL0_SENS_CLR_MIPI_DSI_HOST_SHIFT (4U)
/*! MIPI_DSI_HOST - MIPI_DSI_HOST Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_MIPI_DSI_HOST(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_MIPI_DSI_HOST_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_MIPI_DSI_HOST_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI16_MASK    (0x20U)
#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI16_SHIFT   (5U)
/*! LPSPI16 - LPSPI16 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI16(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_LPSPI16_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_LPSPI16_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI14_MASK    (0x40U)
#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI14_SHIFT   (6U)
/*! LPSPI14 - LPSPI14 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_LPSPI14(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_LPSPI14_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_LPSPI14_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_XSPI2_MASK      (0x100U)
#define CLKCTL4_PSCCTL0_SENS_CLR_XSPI2_SHIFT     (8U)
/*! XSPI2 - XSPI2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_XSPI2(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_XSPI2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_XSPI2_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_MMU2_MASK       (0x800U)
#define CLKCTL4_PSCCTL0_SENS_CLR_MMU2_SHIFT      (11U)
/*! MMU2 - MMU2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_MMU2(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_MMU2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_MMU2_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY5_MASK    (0x2000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY5_SHIFT   (13U)
/*! GLIKEY5 - GLIKEY5 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY5(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY5_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY5_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_FLEXIO0_MASK    (0x8000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_FLEXIO0_SHIFT   (15U)
/*! FLEXIO0 - FLEXIO0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_FLEXIO0(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_FLEXIO0_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_FLEXIO0_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_LCDIF_MASK      (0x400000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_LCDIF_SHIFT     (22U)
/*! LCDIF - LCDIF Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_LCDIF(x)        (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_LCDIF_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_LCDIF_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_SYSCON4_MASK    (0x800000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_SYSCON4_SHIFT   (23U)
/*! SYSCON4 - SYSCON4 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_SYSCON4(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_SYSCON4_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_SYSCON4_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_JPEGDEC_MASK    (0x1000000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_JPEGDEC_SHIFT   (24U)
/*! JPEGDEC - JPEGDEC Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_JPEGDEC(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_JPEGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_JPEGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_PNGDEC_MASK     (0x2000000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_PNGDEC_SHIFT    (25U)
/*! PNGDEC - PNG Decoder Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_PNGDEC(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_PNGDEC_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_PNGDEC_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_EZHV_MASK       (0x4000000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_EZHV_SHIFT      (26U)
/*! EZHV - EZHV Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_EZHV(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_EZHV_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_EZHV_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_AXBS_EZH_MASK   (0x10000000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_AXBS_EZH_SHIFT  (28U)
/*! AXBS_EZH - AXBS_EZHV Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_AXBS_EZH(x)     (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_AXBS_EZH_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_AXBS_EZH_MASK)

#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY2_MASK    (0x20000000U)
#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY2_SHIFT   (29U)
/*! GLIKEY2 - GLIKEY2 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY2(x)      (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY2_SHIFT)) & CLKCTL4_PSCCTL0_SENS_CLR_GLIKEY2_MASK)
/*! @} */

/*! @name PSCCTL1_SENS_CLR - VDD1_SENSE Media Peripheral Clock Control 1 Clear */
/*! @{ */

#define CLKCTL4_PSCCTL1_SENS_CLR_USB0_MASK       (0x1U)
#define CLKCTL4_PSCCTL1_SENS_CLR_USB0_SHIFT      (0U)
/*! USB0 - USB0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_SENS_CLR_USB0(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_CLR_USB0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_CLR_USB0_MASK)

#define CLKCTL4_PSCCTL1_SENS_CLR_USB1_MASK       (0x4U)
#define CLKCTL4_PSCCTL1_SENS_CLR_USB1_SHIFT      (2U)
/*! USB1 - USB1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_SENS_CLR_USB1(x)         (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_CLR_USB1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_CLR_USB1_MASK)

#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC0_MASK     (0x10U)
#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC0_SHIFT    (4U)
/*! uSDHC0 - uSDHC0 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC0(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_CLR_USDHC0_SHIFT)) & CLKCTL4_PSCCTL1_SENS_CLR_USDHC0_MASK)

#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC1_MASK     (0x20U)
#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC1_SHIFT    (5U)
/*! uSDHC1 - uSDHC1 Clock
 *  0b0..No effect
 *  0b1..Disable
 */
#define CLKCTL4_PSCCTL1_SENS_CLR_USDHC1(x)       (((uint32_t)(((uint32_t)(x)) << CLKCTL4_PSCCTL1_SENS_CLR_USDHC1_SHIFT)) & CLKCTL4_PSCCTL1_SENS_CLR_USDHC1_MASK)
/*! @} */

/*! @name ONE_SRC_CLKSLICE_ENABLE_SENSE - One Source Clock Slice Enable for VDD1_SENSE Core */
/*! @{ */

#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_SENSE_USBPHY_REFCLK_EN_MASK (0x1U)
#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_SENSE_USBPHY_REFCLK_EN_SHIFT (0U)
/*! USBPHY_REFCLK_EN - USBPHY0 Reference Clock
 *  0b0..Gates USBPHY0 reference clock.
 *  0b1..Enables USBPHY0 reference clock.
 */
#define CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_SENSE_USBPHY_REFCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_SENSE_USBPHY_REFCLK_EN_SHIFT)) & CLKCTL4_ONE_SRC_CLKSLICE_ENABLE_SENSE_USBPHY_REFCLK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CLKCTL4_Register_Masks */


/*!
 * @}
 */ /* end of group CLKCTL4_Peripheral_Access_Layer */


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


#endif  /* PERI_CLKCTL4_H_ */

