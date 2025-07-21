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
**         CMSIS Peripheral Access Layer for DTRC
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
 * @file PERI_DTRC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DTRC
 *
 * CMSIS Peripheral Access Layer for DTRC
 */

#if !defined(PERI_DTRC_H_)
#define PERI_DTRC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- DTRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DTRC_Peripheral_Access_Layer DTRC Peripheral Access Layer
 * @{
 */

/** DTRC - Size of Registers Arrays */
#define DTRC_FRAME_REGISTERS_COUNT                2u

/** DTRC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x60 */
    __IO uint32_t FDYDSADDR;                         /**< Luma video data start address, array offset: 0x0, array step: 0x60 */
    __IO uint32_t FDCDSADDR;                         /**< Chroma video data start address, array offset: 0x4, array step: 0x60 */
    __IO uint32_t FDYTSADDR;                         /**< Luma table data start address, array offset: 0x8, array step: 0x60 */
    __IO uint32_t FDCTSADDR;                         /**< Chroma table data start address, array offset: 0xC, array step: 0x60 */
    __IO uint32_t FSIZE;                             /**< Frame size, array offset: 0x10, array step: 0x60 */
    __IO uint32_t FSYSSA;                            /**< Luma data slave start address, array offset: 0x14, array step: 0x60 */
    __IO uint32_t FSYSEA;                            /**< Luma data slave end address, array offset: 0x18, array step: 0x60 */
    __IO uint32_t FSUVSSA;                           /**< Chroma data slave start address, array offset: 0x1C, array step: 0x60 */
    __IO uint32_t FSUVSEA;                           /**< Chroma data slave end address, array offset: 0x20, array step: 0x60 */
    __IO uint32_t FCROPORIG;                         /**< Cropped picture origin, array offset: 0x24, array step: 0x60 */
    __IO uint32_t FCROPSIZE;                         /**< Cropped picture size, array offset: 0x28, array step: 0x60 */
    __IO uint32_t FDCTL;                             /**< Frame data control, array offset: 0x2C, array step: 0x60 */
         uint8_t RESERVED_0[48];
  } FRAME_REGISTERS[DTRC_FRAME_REGISTERS_COUNT];
  __IO uint32_t DTRCINTEN;                         /**< DTRC Interrupt enables, offset: 0xC0 */
  __IO uint32_t FDINTR;                            /**< DTRC Interrupt Requests, offset: 0xC4 */
  __IO uint32_t DTCTRL;                            /**< DTRC Control, offset: 0xC8 */
  __IO uint32_t ARIDR;                             /**< ARIDR, offset: 0xCC */
  __IO uint32_t DTID2DDR;                          /**< DTID2DDR, offset: 0xD0 */
  __I  uint32_t DTRCCONFIG;                        /**< DTRCCONFIG, offset: 0xD4 */
  __I  uint32_t DTRCVERSION;                       /**< DTRC Version, offset: 0xD8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t PFCTRL;                            /**< Performance counter control, offset: 0xF0 */
  __IO uint32_t PFCR;                              /**< Performance counter, offset: 0xF4 */
  __IO uint32_t TOCR;                              /**< Time Out Cycles, offset: 0xF8 */
} DTRC_Type;

/* ----------------------------------------------------------------------------
   -- DTRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DTRC_Register_Masks DTRC Register Masks
 * @{
 */

/*! @name FDYDSADDR - Luma video data start address */
/*! @{ */

#define DTRC_FDYDSADDR_F0DYDSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDYDSADDR_F0DYDSADDR_SHIFT          (0U)
/*! F0DYDSADDR - Luma video data start address */
#define DTRC_FDYDSADDR_F0DYDSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDYDSADDR_F0DYDSADDR_SHIFT)) & DTRC_FDYDSADDR_F0DYDSADDR_MASK)

#define DTRC_FDYDSADDR_F1DYDSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDYDSADDR_F1DYDSADDR_SHIFT          (0U)
/*! F1DYDSADDR - Luma video data start address */
#define DTRC_FDYDSADDR_F1DYDSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDYDSADDR_F1DYDSADDR_SHIFT)) & DTRC_FDYDSADDR_F1DYDSADDR_MASK)
/*! @} */

/* The count of DTRC_FDYDSADDR */
#define DTRC_FDYDSADDR_COUNT                     (2U)

/*! @name FDCDSADDR - Chroma video data start address */
/*! @{ */

#define DTRC_FDCDSADDR_F0DCDSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDCDSADDR_F0DCDSADDR_SHIFT          (0U)
/*! F0DCDSADDR - Chroma video data start address */
#define DTRC_FDCDSADDR_F0DCDSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDCDSADDR_F0DCDSADDR_SHIFT)) & DTRC_FDCDSADDR_F0DCDSADDR_MASK)

#define DTRC_FDCDSADDR_F1DCDSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDCDSADDR_F1DCDSADDR_SHIFT          (0U)
/*! F1DCDSADDR - Chroma video data start address */
#define DTRC_FDCDSADDR_F1DCDSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDCDSADDR_F1DCDSADDR_SHIFT)) & DTRC_FDCDSADDR_F1DCDSADDR_MASK)
/*! @} */

/* The count of DTRC_FDCDSADDR */
#define DTRC_FDCDSADDR_COUNT                     (2U)

/*! @name FDYTSADDR - Luma table data start address */
/*! @{ */

#define DTRC_FDYTSADDR_F0DYTSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDYTSADDR_F0DYTSADDR_SHIFT          (0U)
/*! F0DYTSADDR - Luma table data start address */
#define DTRC_FDYTSADDR_F0DYTSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDYTSADDR_F0DYTSADDR_SHIFT)) & DTRC_FDYTSADDR_F0DYTSADDR_MASK)

#define DTRC_FDYTSADDR_F1DYTSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDYTSADDR_F1DYTSADDR_SHIFT          (0U)
/*! F1DYTSADDR - Luma table data start address */
#define DTRC_FDYTSADDR_F1DYTSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDYTSADDR_F1DYTSADDR_SHIFT)) & DTRC_FDYTSADDR_F1DYTSADDR_MASK)
/*! @} */

/* The count of DTRC_FDYTSADDR */
#define DTRC_FDYTSADDR_COUNT                     (2U)

/*! @name FDCTSADDR - Chroma table data start address */
/*! @{ */

#define DTRC_FDCTSADDR_F0DCTSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDCTSADDR_F0DCTSADDR_SHIFT          (0U)
/*! F0DCTSADDR - Chroma table data start address */
#define DTRC_FDCTSADDR_F0DCTSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTSADDR_F0DCTSADDR_SHIFT)) & DTRC_FDCTSADDR_F0DCTSADDR_MASK)

#define DTRC_FDCTSADDR_F1DCTSADDR_MASK           (0xFFFFFFFFU)
#define DTRC_FDCTSADDR_F1DCTSADDR_SHIFT          (0U)
/*! F1DCTSADDR - Chroma table data start address */
#define DTRC_FDCTSADDR_F1DCTSADDR(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTSADDR_F1DCTSADDR_SHIFT)) & DTRC_FDCTSADDR_F1DCTSADDR_MASK)
/*! @} */

/* The count of DTRC_FDCTSADDR */
#define DTRC_FDCTSADDR_COUNT                     (2U)

/*! @name FSIZE - Frame size */
/*! @{ */

#define DTRC_FSIZE_F0WIDTH_MASK                  (0x3FFU)
#define DTRC_FSIZE_F0WIDTH_SHIFT                 (0U)
/*! F0WIDTH - Frame width */
#define DTRC_FSIZE_F0WIDTH(x)                    (((uint32_t)(((uint32_t)(x)) << DTRC_FSIZE_F0WIDTH_SHIFT)) & DTRC_FSIZE_F0WIDTH_MASK)

#define DTRC_FSIZE_F1WIDTH_MASK                  (0x3FFU)
#define DTRC_FSIZE_F1WIDTH_SHIFT                 (0U)
/*! F1WIDTH - Frame width */
#define DTRC_FSIZE_F1WIDTH(x)                    (((uint32_t)(((uint32_t)(x)) << DTRC_FSIZE_F1WIDTH_SHIFT)) & DTRC_FSIZE_F1WIDTH_MASK)

#define DTRC_FSIZE_F0HEIGHT_MASK                 (0x3FF0000U)
#define DTRC_FSIZE_F0HEIGHT_SHIFT                (16U)
/*! F0HEIGHT - Frame height */
#define DTRC_FSIZE_F0HEIGHT(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSIZE_F0HEIGHT_SHIFT)) & DTRC_FSIZE_F0HEIGHT_MASK)

#define DTRC_FSIZE_F1HEIGHT_MASK                 (0x3FF0000U)
#define DTRC_FSIZE_F1HEIGHT_SHIFT                (16U)
/*! F1HEIGHT - Frame height */
#define DTRC_FSIZE_F1HEIGHT(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSIZE_F1HEIGHT_SHIFT)) & DTRC_FSIZE_F1HEIGHT_MASK)
/*! @} */

/* The count of DTRC_FSIZE */
#define DTRC_FSIZE_COUNT                         (2U)

/*! @name FSYSSA - Luma data slave start address */
/*! @{ */

#define DTRC_FSYSSA_F0YSTRBYPASS_MASK            (0x1U)
#define DTRC_FSYSSA_F0YSTRBYPASS_SHIFT           (0U)
/*! F0YSTRBYPASS - Luma Start Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSYSSA_F0YSTRBYPASS(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSSA_F0YSTRBYPASS_SHIFT)) & DTRC_FSYSSA_F0YSTRBYPASS_MASK)

#define DTRC_FSYSSA_F1YSTRBYPASS_MASK            (0x1U)
#define DTRC_FSYSSA_F1YSTRBYPASS_SHIFT           (0U)
/*! F1YSTRBYPASS - Luma Start Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSYSSA_F1YSTRBYPASS(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSSA_F1YSTRBYPASS_SHIFT)) & DTRC_FSYSSA_F1YSTRBYPASS_MASK)

#define DTRC_FSYSSA_F0SYSSA_MASK                 (0xFFFFFFF0U)
#define DTRC_FSYSSA_F0SYSSA_SHIFT                (4U)
/*! F0SYSSA - Luma data slave start address */
#define DTRC_FSYSSA_F0SYSSA(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSSA_F0SYSSA_SHIFT)) & DTRC_FSYSSA_F0SYSSA_MASK)

#define DTRC_FSYSSA_F1SYSSA_MASK                 (0xFFFFFFF0U)
#define DTRC_FSYSSA_F1SYSSA_SHIFT                (4U)
/*! F1SYSSA - Luma data slave start address */
#define DTRC_FSYSSA_F1SYSSA(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSSA_F1SYSSA_SHIFT)) & DTRC_FSYSSA_F1SYSSA_MASK)
/*! @} */

/* The count of DTRC_FSYSSA */
#define DTRC_FSYSSA_COUNT                        (2U)

/*! @name FSYSEA - Luma data slave end address */
/*! @{ */

#define DTRC_FSYSEA_F0YETRBYPASS_MASK            (0x1U)
#define DTRC_FSYSEA_F0YETRBYPASS_SHIFT           (0U)
/*! F0YETRBYPASS - End Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSYSEA_F0YETRBYPASS(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSEA_F0YETRBYPASS_SHIFT)) & DTRC_FSYSEA_F0YETRBYPASS_MASK)

#define DTRC_FSYSEA_F1YETRBYPASS_MASK            (0x1U)
#define DTRC_FSYSEA_F1YETRBYPASS_SHIFT           (0U)
/*! F1YETRBYPASS - End Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSYSEA_F1YETRBYPASS(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSEA_F1YETRBYPASS_SHIFT)) & DTRC_FSYSEA_F1YETRBYPASS_MASK)

#define DTRC_FSYSEA_F0SYSEA_MASK                 (0xFFFFFFF0U)
#define DTRC_FSYSEA_F0SYSEA_SHIFT                (4U)
/*! F0SYSEA - Luma data slave end address */
#define DTRC_FSYSEA_F0SYSEA(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSEA_F0SYSEA_SHIFT)) & DTRC_FSYSEA_F0SYSEA_MASK)

#define DTRC_FSYSEA_F1SYSEA_MASK                 (0xFFFFFFF0U)
#define DTRC_FSYSEA_F1SYSEA_SHIFT                (4U)
/*! F1SYSEA - Luma data slave end address */
#define DTRC_FSYSEA_F1SYSEA(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FSYSEA_F1SYSEA_SHIFT)) & DTRC_FSYSEA_F1SYSEA_MASK)
/*! @} */

/* The count of DTRC_FSYSEA */
#define DTRC_FSYSEA_COUNT                        (2U)

/*! @name FSUVSSA - Chroma data slave start address */
/*! @{ */

#define DTRC_FSUVSSA_F0CSTRBYPASS_MASK           (0x1U)
#define DTRC_FSUVSSA_F0CSTRBYPASS_SHIFT          (0U)
/*! F0CSTRBYPASS - Chroma Start Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSUVSSA_F0CSTRBYPASS(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSSA_F0CSTRBYPASS_SHIFT)) & DTRC_FSUVSSA_F0CSTRBYPASS_MASK)

#define DTRC_FSUVSSA_F1CSTRBYPASS_MASK           (0x1U)
#define DTRC_FSUVSSA_F1CSTRBYPASS_SHIFT          (0U)
/*! F1CSTRBYPASS - Chroma Start Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSUVSSA_F1CSTRBYPASS(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSSA_F1CSTRBYPASS_SHIFT)) & DTRC_FSUVSSA_F1CSTRBYPASS_MASK)

#define DTRC_FSUVSSA_F0SUVSSA_MASK               (0xFFFFFFF0U)
#define DTRC_FSUVSSA_F0SUVSSA_SHIFT              (4U)
/*! F0SUVSSA - Chroma data slave start address */
#define DTRC_FSUVSSA_F0SUVSSA(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSSA_F0SUVSSA_SHIFT)) & DTRC_FSUVSSA_F0SUVSSA_MASK)

#define DTRC_FSUVSSA_F1SUVSSA_MASK               (0xFFFFFFF0U)
#define DTRC_FSUVSSA_F1SUVSSA_SHIFT              (4U)
/*! F1SUVSSA - Chroma data slave start address */
#define DTRC_FSUVSSA_F1SUVSSA(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSSA_F1SUVSSA_SHIFT)) & DTRC_FSUVSSA_F1SUVSSA_MASK)
/*! @} */

/* The count of DTRC_FSUVSSA */
#define DTRC_FSUVSSA_COUNT                       (2U)

/*! @name FSUVSEA - Chroma data slave end address */
/*! @{ */

#define DTRC_FSUVSEA_F0CETRBYPASS_MASK           (0x1U)
#define DTRC_FSUVSEA_F0CETRBYPASS_SHIFT          (0U)
/*! F0CETRBYPASS - End Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSUVSEA_F0CETRBYPASS(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSEA_F0CETRBYPASS_SHIFT)) & DTRC_FSUVSEA_F0CETRBYPASS_MASK)

#define DTRC_FSUVSEA_F1CETRBYPASS_MASK           (0x1U)
#define DTRC_FSUVSEA_F1CETRBYPASS_SHIFT          (0U)
/*! F1CETRBYPASS - End Tile to Raster scan Bypass
 *  0b0..All ARADDR does NOT bypass the tile-to-rasterscan logic.
 *  0b1..All ARADDR bypasses the tile-to-rasterscan logic.
 */
#define DTRC_FSUVSEA_F1CETRBYPASS(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSEA_F1CETRBYPASS_SHIFT)) & DTRC_FSUVSEA_F1CETRBYPASS_MASK)

#define DTRC_FSUVSEA_F0SUVSEA_MASK               (0xFFFFFFF0U)
#define DTRC_FSUVSEA_F0SUVSEA_SHIFT              (4U)
/*! F0SUVSEA - Chroma data slave end address */
#define DTRC_FSUVSEA_F0SUVSEA(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSEA_F0SUVSEA_SHIFT)) & DTRC_FSUVSEA_F0SUVSEA_MASK)

#define DTRC_FSUVSEA_F1SUVSEA_MASK               (0xFFFFFFF0U)
#define DTRC_FSUVSEA_F1SUVSEA_SHIFT              (4U)
/*! F1SUVSEA - Chroma data slave end address */
#define DTRC_FSUVSEA_F1SUVSEA(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FSUVSEA_F1SUVSEA_SHIFT)) & DTRC_FSUVSEA_F1SUVSEA_MASK)
/*! @} */

/* The count of DTRC_FSUVSEA */
#define DTRC_FSUVSEA_COUNT                       (2U)

/*! @name FCROPORIG - Cropped picture origin */
/*! @{ */

#define DTRC_FCROPORIG_F0CROPORIGX_MASK          (0x1FFFU)
#define DTRC_FCROPORIG_F0CROPORIGX_SHIFT         (0U)
/*! F0CROPORIGX - Cropped picture x origin */
#define DTRC_FCROPORIG_F0CROPORIGX(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPORIG_F0CROPORIGX_SHIFT)) & DTRC_FCROPORIG_F0CROPORIGX_MASK)

#define DTRC_FCROPORIG_F1CROPORIGX_MASK          (0x1FFFU)
#define DTRC_FCROPORIG_F1CROPORIGX_SHIFT         (0U)
/*! F1CROPORIGX - Cropped picture x origin */
#define DTRC_FCROPORIG_F1CROPORIGX(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPORIG_F1CROPORIGX_SHIFT)) & DTRC_FCROPORIG_F1CROPORIGX_MASK)

#define DTRC_FCROPORIG_F0CROPORIGY_MASK          (0x1FFF0000U)
#define DTRC_FCROPORIG_F0CROPORIGY_SHIFT         (16U)
/*! F0CROPORIGY - Cropped picture y origin */
#define DTRC_FCROPORIG_F0CROPORIGY(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPORIG_F0CROPORIGY_SHIFT)) & DTRC_FCROPORIG_F0CROPORIGY_MASK)

#define DTRC_FCROPORIG_F1CROPORIGY_MASK          (0x1FFF0000U)
#define DTRC_FCROPORIG_F1CROPORIGY_SHIFT         (16U)
/*! F1CROPORIGY - Cropped picture y origin */
#define DTRC_FCROPORIG_F1CROPORIGY(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPORIG_F1CROPORIGY_SHIFT)) & DTRC_FCROPORIG_F1CROPORIGY_MASK)
/*! @} */

/* The count of DTRC_FCROPORIG */
#define DTRC_FCROPORIG_COUNT                     (2U)

/*! @name FCROPSIZE - Cropped picture size */
/*! @{ */

#define DTRC_FCROPSIZE_F0CROPWIDTH_MASK          (0x1FFFU)
#define DTRC_FCROPSIZE_F0CROPWIDTH_SHIFT         (0U)
/*! F0CROPWIDTH - Cropped picture width */
#define DTRC_FCROPSIZE_F0CROPWIDTH(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPSIZE_F0CROPWIDTH_SHIFT)) & DTRC_FCROPSIZE_F0CROPWIDTH_MASK)

#define DTRC_FCROPSIZE_F1CROPWIDTH_MASK          (0x1FFFU)
#define DTRC_FCROPSIZE_F1CROPWIDTH_SHIFT         (0U)
/*! F1CROPWIDTH - Cropped picture width */
#define DTRC_FCROPSIZE_F1CROPWIDTH(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPSIZE_F1CROPWIDTH_SHIFT)) & DTRC_FCROPSIZE_F1CROPWIDTH_MASK)

#define DTRC_FCROPSIZE_F0CROPHEIGHT_MASK         (0x1FFF0000U)
#define DTRC_FCROPSIZE_F0CROPHEIGHT_SHIFT        (16U)
/*! F0CROPHEIGHT - Cropped picture height */
#define DTRC_FCROPSIZE_F0CROPHEIGHT(x)           (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPSIZE_F0CROPHEIGHT_SHIFT)) & DTRC_FCROPSIZE_F0CROPHEIGHT_MASK)

#define DTRC_FCROPSIZE_F1CROPHEIGHT_MASK         (0x1FFF0000U)
#define DTRC_FCROPSIZE_F1CROPHEIGHT_SHIFT        (16U)
/*! F1CROPHEIGHT - Cropped picture height */
#define DTRC_FCROPSIZE_F1CROPHEIGHT(x)           (((uint32_t)(((uint32_t)(x)) << DTRC_FCROPSIZE_F1CROPHEIGHT_SHIFT)) & DTRC_FCROPSIZE_F1CROPHEIGHT_MASK)
/*! @} */

/* The count of DTRC_FCROPSIZE */
#define DTRC_FCROPSIZE_COUNT                     (2U)

/*! @name FDCTL - Frame data control */
/*! @{ */

#define DTRC_FDCTL_F0FRAMECFG_MASK               (0x1U)
#define DTRC_FDCTL_F0FRAMECFG_SHIFT              (0U)
/*! F0FRAMECFG - Frame configuration ready
 *  0b0..Frame 0 configuration is not ready.
 *  0b1..Frame 0 configuration is ready and decompress can start for the frame. All other configuration, such as
 *       main8/main10 are updated before setting this bit to 1. If there is no G1/G2 video transaction, set this bit
 *       to 0.
 */
#define DTRC_FDCTL_F0FRAMECFG(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F0FRAMECFG_SHIFT)) & DTRC_FDCTL_F0FRAMECFG_MASK)

#define DTRC_FDCTL_F1FRAMECFG_MASK               (0x1U)
#define DTRC_FDCTL_F1FRAMECFG_SHIFT              (0U)
/*! F1FRAMECFG - Frame configuration ready
 *  0b0..Frame 0 configuration is not ready.
 *  0b1..Frame 0 configuration is ready and decompress can start for the frame. All other configuration, such as
 *       main8/main10 are updated before setting this bit to 1. If there is no G1/G2 video transaction, set this bit
 *       to 0.
 */
#define DTRC_FDCTL_F1FRAMECFG(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F1FRAMECFG_SHIFT)) & DTRC_FDCTL_F1FRAMECFG_MASK)

#define DTRC_FDCTL_F0PIXELBITDEPTH_MASK          (0x2U)
#define DTRC_FDCTL_F0PIXELBITDEPTH_SHIFT         (1U)
/*! F0PIXELBITDEPTH - Pixel bit depth
 *  0b0..10-bit pixel depth
 *  0b1..8-bit pixel depth
 */
#define DTRC_FDCTL_F0PIXELBITDEPTH(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F0PIXELBITDEPTH_SHIFT)) & DTRC_FDCTL_F0PIXELBITDEPTH_MASK)

#define DTRC_FDCTL_F1PIXELBITDEPTH_MASK          (0x2U)
#define DTRC_FDCTL_F1PIXELBITDEPTH_SHIFT         (1U)
/*! F1PIXELBITDEPTH - Pixel bit depth
 *  0b0..10-bit pixel depth
 *  0b1..8-bit pixel depth
 */
#define DTRC_FDCTL_F1PIXELBITDEPTH(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F1PIXELBITDEPTH_SHIFT)) & DTRC_FDCTL_F1PIXELBITDEPTH_MASK)

#define DTRC_FDCTL_F0DECOMPRESS_MASK             (0x20000U)
#define DTRC_FDCTL_F0DECOMPRESS_SHIFT            (17U)
/*! F0DECOMPRESS - Decompress bypass
 *  0b0..G2 reference frame is compressed.
 *  0b1..G2/G1 reference frame is not compressed.
 */
#define DTRC_FDCTL_F0DECOMPRESS(x)               (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F0DECOMPRESS_SHIFT)) & DTRC_FDCTL_F0DECOMPRESS_MASK)

#define DTRC_FDCTL_F1DECOMPRESS_MASK             (0x20000U)
#define DTRC_FDCTL_F1DECOMPRESS_SHIFT            (17U)
/*! F1DECOMPRESS - Decompress bypass
 *  0b0..G2 reference frame is compressed.
 *  0b1..G2/G1 reference frame is not compressed.
 */
#define DTRC_FDCTL_F1DECOMPRESS(x)               (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F1DECOMPRESS_SHIFT)) & DTRC_FDCTL_F1DECOMPRESS_MASK)

#define DTRC_FDCTL_F0CROPENABLE_MASK             (0x40000U)
#define DTRC_FDCTL_F0CROPENABLE_SHIFT            (18U)
/*! F0CROPENABLE - Cropped enable */
#define DTRC_FDCTL_F0CROPENABLE(x)               (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F0CROPENABLE_SHIFT)) & DTRC_FDCTL_F0CROPENABLE_MASK)

#define DTRC_FDCTL_F1CROPENABLE_MASK             (0x40000U)
#define DTRC_FDCTL_F1CROPENABLE_SHIFT            (18U)
/*! F1CROPENABLE - Cropped enable */
#define DTRC_FDCTL_F1CROPENABLE(x)               (((uint32_t)(((uint32_t)(x)) << DTRC_FDCTL_F1CROPENABLE_SHIFT)) & DTRC_FDCTL_F1CROPENABLE_MASK)
/*! @} */

/* The count of DTRC_FDCTL */
#define DTRC_FDCTL_COUNT                         (2U)

/*! @name DTRCINTEN - DTRC Interrupt enables */
/*! @{ */

#define DTRC_DTRCINTEN_FRAMEFETCHDONE_EN_MASK    (0x1U)
#define DTRC_DTRCINTEN_FRAMEFETCHDONE_EN_SHIFT   (0U)
/*! FRAMEFETCHDONE_EN - Frame fetch done interrupt enable
 *  0b0..Frame fetch done interrupt disabled.
 *  0b1..Frame fetch done interrupt enabled.
 */
#define DTRC_DTRCINTEN_FRAMEFETCHDONE_EN(x)      (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCINTEN_FRAMEFETCHDONE_EN_SHIFT)) & DTRC_DTRCINTEN_FRAMEFETCHDONE_EN_MASK)

#define DTRC_DTRCINTEN_BUSERROR_EN_MASK          (0x2U)
#define DTRC_DTRCINTEN_BUSERROR_EN_SHIFT         (1U)
/*! BUSERROR_EN - Bus error interrupt enable
 *  0b0..Bus error interrupt disabled.
 *  0b1..Bus error interrupt enabled.
 */
#define DTRC_DTRCINTEN_BUSERROR_EN(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCINTEN_BUSERROR_EN_SHIFT)) & DTRC_DTRCINTEN_BUSERROR_EN_MASK)

#define DTRC_DTRCINTEN_TIMEOUT_EN_MASK           (0x4U)
#define DTRC_DTRCINTEN_TIMEOUT_EN_SHIFT          (2U)
/*! TIMEOUT_EN - Time out enable
 *  0b0..Time out disabled.
 *  0b1..Time out enabled.
 */
#define DTRC_DTRCINTEN_TIMEOUT_EN(x)             (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCINTEN_TIMEOUT_EN_SHIFT)) & DTRC_DTRCINTEN_TIMEOUT_EN_MASK)

#define DTRC_DTRCINTEN_SLFRAMEFETCHDONE_EN_MASK  (0x8U)
#define DTRC_DTRCINTEN_SLFRAMEFETCHDONE_EN_SHIFT (3U)
/*! SLFRAMEFETCHDONE_EN - Slave frame fetch done
 *  0b0..Slave frame fetch done disabled.
 *  0b1..Slave frame fetch done enabled.
 */
#define DTRC_DTRCINTEN_SLFRAMEFETCHDONE_EN(x)    (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCINTEN_SLFRAMEFETCHDONE_EN_SHIFT)) & DTRC_DTRCINTEN_SLFRAMEFETCHDONE_EN_MASK)

#define DTRC_DTRCINTEN_HOTRESETFINISH_EN_MASK    (0x10U)
#define DTRC_DTRCINTEN_HOTRESETFINISH_EN_SHIFT   (4U)
/*! HOTRESETFINISH_EN - Hot reset finish
 *  0b0..Hot reset finish disabled.
 *  0b1..Hot reset finish enabled.
 */
#define DTRC_DTRCINTEN_HOTRESETFINISH_EN(x)      (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCINTEN_HOTRESETFINISH_EN_SHIFT)) & DTRC_DTRCINTEN_HOTRESETFINISH_EN_MASK)
/*! @} */

/*! @name FDINTR - DTRC Interrupt Requests */
/*! @{ */

#define DTRC_FDINTR_FRAMEFETCHDONE_MASK          (0x1U)
#define DTRC_FDINTR_FRAMEFETCHDONE_SHIFT         (0U)
/*! FRAMEFETCHDONE - Frame fetch done interrupt */
#define DTRC_FDINTR_FRAMEFETCHDONE(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FDINTR_FRAMEFETCHDONE_SHIFT)) & DTRC_FDINTR_FRAMEFETCHDONE_MASK)

#define DTRC_FDINTR_BUSERROR_MASK                (0x2U)
#define DTRC_FDINTR_BUSERROR_SHIFT               (1U)
/*! BUSERROR - Bus error interrupt */
#define DTRC_FDINTR_BUSERROR(x)                  (((uint32_t)(((uint32_t)(x)) << DTRC_FDINTR_BUSERROR_SHIFT)) & DTRC_FDINTR_BUSERROR_MASK)

#define DTRC_FDINTR_TIMEOUT_MASK                 (0x4U)
#define DTRC_FDINTR_TIMEOUT_SHIFT                (2U)
/*! TIMEOUT - Time out interrupt */
#define DTRC_FDINTR_TIMEOUT(x)                   (((uint32_t)(((uint32_t)(x)) << DTRC_FDINTR_TIMEOUT_SHIFT)) & DTRC_FDINTR_TIMEOUT_MASK)

#define DTRC_FDINTR_SLFRAMEFETCHDONE_MASK        (0x8U)
#define DTRC_FDINTR_SLFRAMEFETCHDONE_SHIFT       (3U)
/*! SLFRAMEFETCHDONE - Slave frame fetch done interrupt */
#define DTRC_FDINTR_SLFRAMEFETCHDONE(x)          (((uint32_t)(((uint32_t)(x)) << DTRC_FDINTR_SLFRAMEFETCHDONE_SHIFT)) & DTRC_FDINTR_SLFRAMEFETCHDONE_MASK)

#define DTRC_FDINTR_HOTRESETFINISH_MASK          (0x10U)
#define DTRC_FDINTR_HOTRESETFINISH_SHIFT         (4U)
/*! HOTRESETFINISH - Hot reset finish interrupt */
#define DTRC_FDINTR_HOTRESETFINISH(x)            (((uint32_t)(((uint32_t)(x)) << DTRC_FDINTR_HOTRESETFINISH_SHIFT)) & DTRC_FDINTR_HOTRESETFINISH_MASK)
/*! @} */

/*! @name DTCTRL - DTRC Control */
/*! @{ */

#define DTRC_DTCTRL_ARIDRCFG_MASK                (0x3U)
#define DTRC_DTCTRL_ARIDRCFG_SHIFT               (0U)
/*! ARIDRCFG - ARIDR configuration
 *  0b00..All ARID is de-tiled.
 *  0b01..ARID in ARIDR is de-tiled, and others are bypass. NOTE: ARID[0] specify decode luma or chroma, so 4
 *        ARIDs in ARIDR should include both of ARID[0] ==1 and ARID[0] ==0.
 *  0b10..ARID in ARIDR is bypass_de-tile, and others are de-tiled.
 *  0b11..Same as 2'b01.
 */
#define DTRC_DTCTRL_ARIDRCFG(x)                  (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_ARIDRCFG_SHIFT)) & DTRC_DTCTRL_ARIDRCFG_MASK)

#define DTRC_DTCTRL_HOTRESETTRIG_MASK            (0x4U)
#define DTRC_DTCTRL_HOTRESETTRIG_SHIFT           (2U)
/*! HOTRESETTRIG - Hot reset trigger */
#define DTRC_DTCTRL_HOTRESETTRIG(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_HOTRESETTRIG_SHIFT)) & DTRC_DTCTRL_HOTRESETTRIG_MASK)

#define DTRC_DTCTRL_G1G2DATA_MASK                (0x8U)
#define DTRC_DTCTRL_G1G2DATA_SHIFT               (3U)
/*! G1G2DATA - G2 or G1 source data
 *  0b0..The source data is G2 data.
 *  0b1..The source data is G1 tile data
 */
#define DTRC_DTCTRL_G1G2DATA(x)                  (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_G1G2DATA_SHIFT)) & DTRC_DTCTRL_G1G2DATA_MASK)

#define DTRC_DTCTRL_AXIMAXBURSTL_MASK            (0xFF0U)
#define DTRC_DTCTRL_AXIMAXBURSTL_SHIFT           (4U)
/*! AXIMAXBURSTL - Maximum burst length of AXI master port */
#define DTRC_DTCTRL_AXIMAXBURSTL(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_AXIMAXBURSTL_SHIFT)) & DTRC_DTCTRL_AXIMAXBURSTL_MASK)

#define DTRC_DTCTRL_BYTESWAP_SLRAST_MASK         (0xF000U)
#define DTRC_DTCTRL_BYTESWAP_SLRAST_SHIFT        (12U)
/*! BYTESWAP_SLRAST - Byte swap mode for slave interface raster scan data */
#define DTRC_DTCTRL_BYTESWAP_SLRAST(x)           (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_BYTESWAP_SLRAST_SHIFT)) & DTRC_DTCTRL_BYTESWAP_SLRAST_MASK)

#define DTRC_DTCTRL_BYTESWAP_MCOMPTILE_MASK      (0xF0000U)
#define DTRC_DTCTRL_BYTESWAP_MCOMPTILE_SHIFT     (16U)
/*! BYTESWAP_MCOMPTILE - Byte swap mode for master interface compressed data and tiled data */
#define DTRC_DTCTRL_BYTESWAP_MCOMPTILE(x)        (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_BYTESWAP_MCOMPTILE_SHIFT)) & DTRC_DTCTRL_BYTESWAP_MCOMPTILE_MASK)

#define DTRC_DTCTRL_BYTESWAP_MTABLE_MASK         (0xF00000U)
#define DTRC_DTCTRL_BYTESWAP_MTABLE_SHIFT        (20U)
/*! BYTESWAP_MTABLE - Byte swap mode for master interface table data */
#define DTRC_DTCTRL_BYTESWAP_MTABLE(x)           (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_BYTESWAP_MTABLE_SHIFT)) & DTRC_DTCTRL_BYTESWAP_MTABLE_MASK)

#define DTRC_DTCTRL_BYTESWAP_M_NONG1G2_MASK      (0xF000000U)
#define DTRC_DTCTRL_BYTESWAP_M_NONG1G2_SHIFT     (24U)
/*! BYTESWAP_M_NONG1G2 - Byte swap mode for master interface non-G1/G2 data */
#define DTRC_DTCTRL_BYTESWAP_M_NONG1G2(x)        (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_BYTESWAP_M_NONG1G2_SHIFT)) & DTRC_DTCTRL_BYTESWAP_M_NONG1G2_MASK)

#define DTRC_DTCTRL_MERGEG1G2_ARIDEN_MASK        (0x10000000U)
#define DTRC_DTCTRL_MERGEG1G2_ARIDEN_SHIFT       (28U)
/*! MERGEG1G2_ARIDEN - Merge G2/G1 ARID enable
 *  0b0..G2/G1 transactions at AXI master interface use different id for table/chroma and data/luma according to DTID2DDR definition.
 *  0b1..All G2/G1 transactions at AXI master interface use the same id configured in DTID2DDR[15:8] Please note
 *       that DTID2DDR[15:8] and DTID2DDR[7:0] still need to be set the same way as when DTCTRL[28] is 0.
 */
#define DTRC_DTCTRL_MERGEG1G2_ARIDEN(x)          (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_MERGEG1G2_ARIDEN_SHIFT)) & DTRC_DTCTRL_MERGEG1G2_ARIDEN_MASK)

#define DTRC_DTCTRL_RAST_ENDIAN_MASK             (0x20000000U)
#define DTRC_DTCTRL_RAST_ENDIAN_SHIFT            (29U)
/*! RAST_ENDIAN - Raster endian mode
 *  0b0..10-bit output format is little-endian. Byte swap setting of DTCTRL[15:12] is used.
 *  0b1..10-bit output format is big-endian. Byte swap setting of DTCTRL[15:12] is ignored.
 */
#define DTRC_DTCTRL_RAST_ENDIAN(x)               (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_RAST_ENDIAN_SHIFT)) & DTRC_DTCTRL_RAST_ENDIAN_MASK)

#define DTRC_DTCTRL_ADDR_ARID_MASK               (0x40000000U)
#define DTRC_DTCTRL_ADDR_ARID_SHIFT              (30U)
/*! ADDR_ARID - ADDR_ARID
 *  0b0..By ARID (See bit[1:0] of this register).
 *  0b1..By ARADDR
 */
#define DTRC_DTCTRL_ADDR_ARID(x)                 (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_ADDR_ARID_SHIFT)) & DTRC_DTCTRL_ADDR_ARID_MASK)

#define DTRC_DTCTRL_FRBUFF_PTR_MASK              (0x80000000U)
#define DTRC_DTCTRL_FRBUFF_PTR_SHIFT             (31U)
/*! FRBUFF_PTR - FRBUFF_PTR
 *  0b0..Configure frame 0 registers.
 *  0b1..Configure frame 1 registers.
 */
#define DTRC_DTCTRL_FRBUFF_PTR(x)                (((uint32_t)(((uint32_t)(x)) << DTRC_DTCTRL_FRBUFF_PTR_SHIFT)) & DTRC_DTCTRL_FRBUFF_PTR_MASK)
/*! @} */

/*! @name ARIDR - ARIDR */
/*! @{ */

#define DTRC_ARIDR_ARIDR_MASK                    (0xFFFFFFFFU)
#define DTRC_ARIDR_ARIDR_SHIFT                   (0U)
/*! ARIDR - ARIDR */
#define DTRC_ARIDR_ARIDR(x)                      (((uint32_t)(((uint32_t)(x)) << DTRC_ARIDR_ARIDR_SHIFT)) & DTRC_ARIDR_ARIDR_MASK)
/*! @} */

/*! @name DTID2DDR - DTID2DDR */
/*! @{ */

#define DTRC_DTID2DDR_ARID_COMPR_MASK            (0xFFU)
#define DTRC_DTID2DDR_ARID_COMPR_SHIFT           (0U)
/*! ARID_COMPR - ARID_COMPR */
#define DTRC_DTID2DDR_ARID_COMPR(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_DTID2DDR_ARID_COMPR_SHIFT)) & DTRC_DTID2DDR_ARID_COMPR_MASK)

#define DTRC_DTID2DDR_ARID_TABLE_MASK            (0xFF00U)
#define DTRC_DTID2DDR_ARID_TABLE_SHIFT           (8U)
/*! ARID_TABLE - ARID_TABLE */
#define DTRC_DTID2DDR_ARID_TABLE(x)              (((uint32_t)(((uint32_t)(x)) << DTRC_DTID2DDR_ARID_TABLE_SHIFT)) & DTRC_DTID2DDR_ARID_TABLE_MASK)
/*! @} */

/*! @name DTRCCONFIG - DTRCCONFIG */
/*! @{ */

#define DTRC_DTRCCONFIG_G1G2_KEEPORDER_MASK      (0x2U)
#define DTRC_DTRCCONFIG_G1G2_KEEPORDER_SHIFT     (1U)
/*! G1G2_KEEPORDER - G1G2_KEEPORDER
 *  0b0..Not supported. DTRC sends out data transactions as soon as they are ready regardless of the address
 *       transactions order, The master connected to AXI slave interface must recognize the data transactions by the RID.
 *  0b1..Supported, DTRC ensure return read data from a sequence of read transactions in the same order in which it received the address.
 */
#define DTRC_DTRCCONFIG_G1G2_KEEPORDER(x)        (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCCONFIG_G1G2_KEEPORDER_SHIFT)) & DTRC_DTRCCONFIG_G1G2_KEEPORDER_MASK)

#define DTRC_DTRCCONFIG_AXI_MAXBURSTL_MASK       (0x4U)
#define DTRC_DTRCCONFIG_AXI_MAXBURSTL_SHIFT      (2U)
/*! AXI_MAXBURSTL - AXI_MAXBURSTL
 *  0b0..Not supported.
 *  0b1..Supported. DTRC sends the G1/G2 relating requests with ARLEN <= (the maximum burst length - 1). The
 *       maximum burst length is set by DTCTRL[16:8].
 */
#define DTRC_DTRCCONFIG_AXI_MAXBURSTL(x)         (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCCONFIG_AXI_MAXBURSTL_SHIFT)) & DTRC_DTRCCONFIG_AXI_MAXBURSTL_MASK)

#define DTRC_DTRCCONFIG_G1TILE_INPUT_MASK        (0x8U)
#define DTRC_DTRCCONFIG_G1TILE_INPUT_SHIFT       (3U)
/*! G1TILE_INPUT - G1TILE_INPUT
 *  0b0..Not supported.
 *  0b1..Supported.
 */
#define DTRC_DTRCCONFIG_G1TILE_INPUT(x)          (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCCONFIG_G1TILE_INPUT_SHIFT)) & DTRC_DTRCCONFIG_G1TILE_INPUT_MASK)

#define DTRC_DTRCCONFIG_MAX_PIC_WIDTH_MASK       (0x30U)
#define DTRC_DTRCCONFIG_MAX_PIC_WIDTH_SHIFT      (4U)
/*! MAX_PIC_WIDTH - MAX_PIC_WIDTH
 *  0b00..4096
 *  0b01..1920
 *  0b10..Reserved.
 *  0b11..Reserved.
 */
#define DTRC_DTRCCONFIG_MAX_PIC_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCCONFIG_MAX_PIC_WIDTH_SHIFT)) & DTRC_DTRCCONFIG_MAX_PIC_WIDTH_MASK)
/*! @} */

/*! @name DTRCVERSION - DTRC Version */
/*! @{ */

#define DTRC_DTRCVERSION_CUST_VERSION_MASK       (0xFU)
#define DTRC_DTRCVERSION_CUST_VERSION_SHIFT      (0U)
/*! CUST_VERSION - CUST_VERSION */
#define DTRC_DTRCVERSION_CUST_VERSION(x)         (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCVERSION_CUST_VERSION_SHIFT)) & DTRC_DTRCVERSION_CUST_VERSION_MASK)

#define DTRC_DTRCVERSION_MINOR_MASK              (0x3F0U)
#define DTRC_DTRCVERSION_MINOR_SHIFT             (4U)
/*! MINOR - MINOR */
#define DTRC_DTRCVERSION_MINOR(x)                (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCVERSION_MINOR_SHIFT)) & DTRC_DTRCVERSION_MINOR_MASK)

#define DTRC_DTRCVERSION_MAJOR_MASK              (0xFC00U)
#define DTRC_DTRCVERSION_MAJOR_SHIFT             (10U)
/*! MAJOR - MAJOR */
#define DTRC_DTRCVERSION_MAJOR(x)                (((uint32_t)(((uint32_t)(x)) << DTRC_DTRCVERSION_MAJOR_SHIFT)) & DTRC_DTRCVERSION_MAJOR_MASK)
/*! @} */

/*! @name PFCTRL - Performance counter control */
/*! @{ */

#define DTRC_PFCTRL_PFC_EN_MASK                  (0x1U)
#define DTRC_PFCTRL_PFC_EN_SHIFT                 (0U)
/*! PFC_EN - PFC_EN
 *  0b0..Performance Counter disabled.
 *  0b1..Performance Counter enabled.
 */
#define DTRC_PFCTRL_PFC_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DTRC_PFCTRL_PFC_EN_SHIFT)) & DTRC_PFCTRL_PFC_EN_MASK)
/*! @} */

/*! @name PFCR - Performance counter */
/*! @{ */

#define DTRC_PFCR_PFCR_MASK                      (0xFFFFFFFFU)
#define DTRC_PFCR_PFCR_SHIFT                     (0U)
/*! PFCR - Performance Counter */
#define DTRC_PFCR_PFCR(x)                        (((uint32_t)(((uint32_t)(x)) << DTRC_PFCR_PFCR_SHIFT)) & DTRC_PFCR_PFCR_MASK)
/*! @} */

/*! @name TOCR - Time Out Cycles */
/*! @{ */

#define DTRC_TOCR_TOCR_MASK                      (0xFFFFFFFFU)
#define DTRC_TOCR_TOCR_SHIFT                     (0U)
/*! TOCR - Time Out Cycles */
#define DTRC_TOCR_TOCR(x)                        (((uint32_t)(((uint32_t)(x)) << DTRC_TOCR_TOCR_SHIFT)) & DTRC_TOCR_TOCR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DTRC_Register_Masks */


/*!
 * @}
 */ /* end of group DTRC_Peripheral_Access_Layer */


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


#endif  /* PERI_DTRC_H_ */

