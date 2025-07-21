/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CMC_LPAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CMC_LPAC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CMC_LPAC
 *
 * CMSIS Peripheral Access Layer for CMC_LPAC
 */

#if !defined(PERI_CMC_LPAC_H_)
#define PERI_CMC_LPAC_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- CMC_LPAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_LPAC_Peripheral_Access_Layer CMC_LPAC Peripheral Access Layer
 * @{
 */

/** CMC_LPAC - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
       uint8_t RESERVED_0[108];
  __IO uint32_t LPAV_PSDORF;                       /**< Audio Video Domain Power Switch Domain Out of Reset Interrupt Flag Register, offset: 0x70 */
  __IO uint32_t LPAV_PSDORIE;                      /**< Audio Video Domain Power Switch Domain Out of Reset Interrupt Enable Register, offset: 0x74 */
  __I  uint32_t LPAV_PSDS;                         /**< Audio Video Domain Power Switch Domain Status Register, offset: 0x78 */
} CMC_LPAC_Type;

/* ----------------------------------------------------------------------------
   -- CMC_LPAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMC_LPAC_Register_Masks CMC_LPAC Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define CMC_LPAC_VERID_FEATURE_MASK              (0xFFFFU)
#define CMC_LPAC_VERID_FEATURE_SHIFT             (0U)
/*! FEATURE - Feature Specification Number */
#define CMC_LPAC_VERID_FEATURE(x)                (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_VERID_FEATURE_SHIFT)) & CMC_LPAC_VERID_FEATURE_MASK)

#define CMC_LPAC_VERID_MINOR_MASK                (0xFF0000U)
#define CMC_LPAC_VERID_MINOR_SHIFT               (16U)
/*! MINOR - Minor Version Number */
#define CMC_LPAC_VERID_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_VERID_MINOR_SHIFT)) & CMC_LPAC_VERID_MINOR_MASK)

#define CMC_LPAC_VERID_MAJOR_MASK                (0xFF000000U)
#define CMC_LPAC_VERID_MAJOR_SHIFT               (24U)
/*! MAJOR - Major Version Number */
#define CMC_LPAC_VERID_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_VERID_MAJOR_SHIFT)) & CMC_LPAC_VERID_MAJOR_MASK)
/*! @} */

/*! @name LPAV_PSDORF - Audio Video Domain Power Switch Domain Out of Reset Interrupt Flag Register */
/*! @{ */

#define CMC_LPAC_LPAV_PSDORF_GPU3D_MASK          (0x1U)
#define CMC_LPAC_LPAV_PSDORF_GPU3D_SHIFT         (0U)
/*! GPU3D - GPU3D Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..GPU3D Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..GPU3D Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_GPU3D(x)            (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_GPU3D_SHIFT)) & CMC_LPAC_LPAV_PSDORF_GPU3D_MASK)

#define CMC_LPAC_LPAV_PSDORF_HIFI4_MASK          (0x2U)
#define CMC_LPAC_LPAV_PSDORF_HIFI4_SHIFT         (1U)
/*! HIFI4 - HIFI4 Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..HIFI4 Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..HIFI4 Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_HIFI4(x)            (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_HIFI4_SHIFT)) & CMC_LPAC_LPAV_PSDORF_HIFI4_MASK)

#define CMC_LPAC_LPAV_PSDORF_DDR_MASK            (0x4U)
#define CMC_LPAC_LPAV_PSDORF_DDR_SHIFT           (2U)
/*! DDR - DDR Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..DDR Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..DDR Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_DDR(x)              (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_DDR_SHIFT)) & CMC_LPAC_LPAV_PSDORF_DDR_MASK)

#define CMC_LPAC_LPAV_PSDORF_PXP_EPDC_MASK       (0x8U)
#define CMC_LPAC_LPAV_PSDORF_PXP_EPDC_SHIFT      (3U)
/*! PXP_EPDC - PXP/EPDC Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..PXP/EPDC Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..PXP/EPDC Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_PXP_EPDC(x)         (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_PXP_EPDC_SHIFT)) & CMC_LPAC_LPAV_PSDORF_PXP_EPDC_MASK)

#define CMC_LPAC_LPAV_PSDORF_MIPI_DSI_MASK       (0x10U)
#define CMC_LPAC_LPAV_PSDORF_MIPI_DSI_SHIFT      (4U)
/*! MIPI_DSI - MIPI-DSI Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..MIPI-DSI Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..MIPI-DSI Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_MIPI_DSI(x)         (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_MIPI_DSI_SHIFT)) & CMC_LPAC_LPAV_PSDORF_MIPI_DSI_MASK)

#define CMC_LPAC_LPAV_PSDORF_MIPI_CSI_MASK       (0x20U)
#define CMC_LPAC_LPAV_PSDORF_MIPI_CSI_SHIFT      (5U)
/*! MIPI_CSI - MIPI-CSI Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..MIPI-CSI Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..MIPI-CSI Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_MIPI_CSI(x)         (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_MIPI_CSI_SHIFT)) & CMC_LPAC_LPAV_PSDORF_MIPI_CSI_MASK)

#define CMC_LPAC_LPAV_PSDORF_NIC_AV_MASK         (0x40U)
#define CMC_LPAC_LPAV_PSDORF_NIC_AV_SHIFT        (6U)
/*! NIC_AV - NIC_AV/Periph Power Switch Domain Out of Reset Interrupt Flag
 *  0b0..NIC_AV/Periph Power Switch Domain in reset or user has cleared it by writing 1 to clear.
 *  0b1..NIC_AV/Periph Power switch domain out of reset interrupt flag. This bit is asserted only once after the power switch domain exits the reset.
 */
#define CMC_LPAC_LPAV_PSDORF_NIC_AV(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORF_NIC_AV_SHIFT)) & CMC_LPAC_LPAV_PSDORF_NIC_AV_MASK)
/*! @} */

/*! @name LPAV_PSDORIE - Audio Video Domain Power Switch Domain Out of Reset Interrupt Enable Register */
/*! @{ */

#define CMC_LPAC_LPAV_PSDORIE_GPU3D_MASK         (0x1U)
#define CMC_LPAC_LPAV_PSDORIE_GPU3D_SHIFT        (0U)
/*! GPU3D - GPU3D Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..GPU3D Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..GPU3D Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_GPU3D(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_GPU3D_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_GPU3D_MASK)

#define CMC_LPAC_LPAV_PSDORIE_HIFI4_MASK         (0x2U)
#define CMC_LPAC_LPAV_PSDORIE_HIFI4_SHIFT        (1U)
/*! HIFI4 - HIFI4 Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..HIFI4 Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..HIFI4 Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_HIFI4(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_HIFI4_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_HIFI4_MASK)

#define CMC_LPAC_LPAV_PSDORIE_DDR_MASK           (0x4U)
#define CMC_LPAC_LPAV_PSDORIE_DDR_SHIFT          (2U)
/*! DDR - DDR Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..DDR Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..DDR Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_DDR(x)             (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_DDR_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_DDR_MASK)

#define CMC_LPAC_LPAV_PSDORIE_PXP_EPDC_MASK      (0x8U)
#define CMC_LPAC_LPAV_PSDORIE_PXP_EPDC_SHIFT     (3U)
/*! PXP_EPDC - PXP/EPDC Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..PXP/EPDC Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..PXP/EPDC Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_PXP_EPDC(x)        (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_PXP_EPDC_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_PXP_EPDC_MASK)

#define CMC_LPAC_LPAV_PSDORIE_MIPI_DSI_MASK      (0x10U)
#define CMC_LPAC_LPAV_PSDORIE_MIPI_DSI_SHIFT     (4U)
/*! MIPI_DSI - MIPI-DSI Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..MIPI-DSI Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..MIPI-DSI Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_MIPI_DSI(x)        (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_MIPI_DSI_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_MIPI_DSI_MASK)

#define CMC_LPAC_LPAV_PSDORIE_MIPI_CSI_MASK      (0x20U)
#define CMC_LPAC_LPAV_PSDORIE_MIPI_CSI_SHIFT     (5U)
/*! MIPI_CSI - MIPI-CSI Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..MIPI-CSI Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..MIPI-CSI Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_MIPI_CSI(x)        (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_MIPI_CSI_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_MIPI_CSI_MASK)

#define CMC_LPAC_LPAV_PSDORIE_NIC_AV_MASK        (0x40U)
#define CMC_LPAC_LPAV_PSDORIE_NIC_AV_SHIFT       (6U)
/*! NIC_AV - NIC_AV/Periph Power Switch Domain Out of Reset Interrupt Enable
 *  0b0..NIC_AV/Periph Power Switch does not generate interrupt when domain gets out of reset.
 *  0b1..NIC_AV/Periph Power Switch generates interrupt when domain gets out of reset.
 */
#define CMC_LPAC_LPAV_PSDORIE_NIC_AV(x)          (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDORIE_NIC_AV_SHIFT)) & CMC_LPAC_LPAV_PSDORIE_NIC_AV_MASK)
/*! @} */

/*! @name LPAV_PSDS - Audio Video Domain Power Switch Domain Status Register */
/*! @{ */

#define CMC_LPAC_LPAV_PSDS_GPU3D_MASK            (0x1U)
#define CMC_LPAC_LPAV_PSDS_GPU3D_SHIFT           (0U)
/*! GPU3D - GPU3D Power Switch Domain Status
 *  0b0..GPU3D Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..GPU3D Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_GPU3D(x)              (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_GPU3D_SHIFT)) & CMC_LPAC_LPAV_PSDS_GPU3D_MASK)

#define CMC_LPAC_LPAV_PSDS_HIFI4_MASK            (0x2U)
#define CMC_LPAC_LPAV_PSDS_HIFI4_SHIFT           (1U)
/*! HIFI4 - HIFI4 Power Switch Domain Status
 *  0b0..HIFI4 Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..HIFI4 Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_HIFI4(x)              (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_HIFI4_SHIFT)) & CMC_LPAC_LPAV_PSDS_HIFI4_MASK)

#define CMC_LPAC_LPAV_PSDS_DDR_MASK              (0x4U)
#define CMC_LPAC_LPAV_PSDS_DDR_SHIFT             (2U)
/*! DDR - DDR Power Switch Domain Status
 *  0b0..DDR Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..DDR Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_DDR(x)                (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_DDR_SHIFT)) & CMC_LPAC_LPAV_PSDS_DDR_MASK)

#define CMC_LPAC_LPAV_PSDS_PXP_EPDC_MASK         (0x8U)
#define CMC_LPAC_LPAV_PSDS_PXP_EPDC_SHIFT        (3U)
/*! PXP_EPDC - PXP/EPDC Power Switch Domain Status
 *  0b0..PXP/EPDC Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..PXP/EPDC Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_PXP_EPDC(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_PXP_EPDC_SHIFT)) & CMC_LPAC_LPAV_PSDS_PXP_EPDC_MASK)

#define CMC_LPAC_LPAV_PSDS_MIPI_DSI_MASK         (0x10U)
#define CMC_LPAC_LPAV_PSDS_MIPI_DSI_SHIFT        (4U)
/*! MIPI_DSI - MIPI-DSI Power Switch Domain Status
 *  0b0..MIPI-DSI Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..MIPI-DSI Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_MIPI_DSI(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_MIPI_DSI_SHIFT)) & CMC_LPAC_LPAV_PSDS_MIPI_DSI_MASK)

#define CMC_LPAC_LPAV_PSDS_MIPI_CSI_MASK         (0x20U)
#define CMC_LPAC_LPAV_PSDS_MIPI_CSI_SHIFT        (5U)
/*! MIPI_CSI - MIPI-CSI Power Switch Domain Status
 *  0b0..MIPI-CSI Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..MIPI-CSI Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_MIPI_CSI(x)           (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_MIPI_CSI_SHIFT)) & CMC_LPAC_LPAV_PSDS_MIPI_CSI_MASK)

#define CMC_LPAC_LPAV_PSDS_NIC_AV_MASK           (0x40U)
#define CMC_LPAC_LPAV_PSDS_NIC_AV_SHIFT          (6U)
/*! NIC_AV - NIC_AV/Periph Power Switch Domain Status
 *  0b0..NIC_AV/Periph Power switch is open and not ready for read/write. Power switch domain is in reset.
 *  0b1..NIC_AV/Periph Power switch is closed and in normal operation. Power switch domain is out of reset.
 */
#define CMC_LPAC_LPAV_PSDS_NIC_AV(x)             (((uint32_t)(((uint32_t)(x)) << CMC_LPAC_LPAV_PSDS_NIC_AV_SHIFT)) & CMC_LPAC_LPAV_PSDS_NIC_AV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CMC_LPAC_Register_Masks */


/*!
 * @}
 */ /* end of group CMC_LPAC_Peripheral_Access_Layer */


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


#endif  /* PERI_CMC_LPAC_H_ */

