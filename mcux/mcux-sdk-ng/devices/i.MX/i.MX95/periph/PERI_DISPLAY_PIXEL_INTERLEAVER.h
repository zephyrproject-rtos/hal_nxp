/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_PIXEL_INTERLEAVER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DISPLAY_PIXEL_INTERLEAVER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DISPLAY_PIXEL_INTERLEAVER
 *
 * CMSIS Peripheral Access Layer for DISPLAY_PIXEL_INTERLEAVER
 */

#if !defined(DISPLAY_PIXEL_INTERLEAVER_H_)
#define DISPLAY_PIXEL_INTERLEAVER_H_             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- DISPLAY_PIXEL_INTERLEAVER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_PIXEL_INTERLEAVER_Peripheral_Access_Layer DISPLAY_PIXEL_INTERLEAVER Peripheral Access Layer
 * @{
 */

/** DISPLAY_PIXEL_INTERLEAVER - Size of Registers Arrays */
#define DISPLAY_PIXEL_INTERLEAVER_DISPLAY_COUNT   2u

/** DISPLAY_PIXEL_INTERLEAVER - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x10000 */
    __IO uint32_t CTRL;                              /**< DISP_IN0 Control Register..DISP_IN1 Control Register, array offset: 0x0, array step: 0x10000 */
         uint8_t RESERVED_0[28];
    __IO uint32_t SWRST;                             /**< DISP_IN0 Software Reset Control Register..DISP_IN1 Software Reset Control Register, array offset: 0x20, array step: 0x10000 */
         uint8_t RESERVED_1[12];
    __IO uint32_t IE;                                /**< DISP_IN0 Interrupt Enable Register..DISP_IN1 Interrupt Enable Register, array offset: 0x30, array step: 0x10000 */
         uint8_t RESERVED_2[12];
    __IO uint32_t IS;                                /**< DISP_IN0 Interrupt Status Register..DISP_IN1 Interrupt Status Register, array offset: 0x40, array step: 0x10000 */
         uint8_t RESERVED_3[12];
    __IO uint32_t ICTRL;                             /**< DISP_IN0 Interleaving Control Register..DISP_IN1 Interleaving Control Register, array offset: 0x50, array step: 0x10000 */
         uint8_t RESERVED_4[65452];
  } DISPLAY[DISPLAY_PIXEL_INTERLEAVER_DISPLAY_COUNT];
} DISPLAY_PIXEL_INTERLEAVER_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_PIXEL_INTERLEAVER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_PIXEL_INTERLEAVER_Register_Masks DISPLAY_PIXEL_INTERLEAVER Register Masks
 * @{
 */

/*! @name CTRL - DISP_IN0 Control Register..DISP_IN1 Control Register */
/*! @{ */

#define DISPLAY_PIXEL_INTERLEAVER_CTRL_HSYNC_POLARITY_MASK (0x200U)
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_HSYNC_POLARITY_SHIFT (9U)
/*! HSYNC_POLARITY - Hsync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_CTRL_HSYNC_POLARITY_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_CTRL_HSYNC_POLARITY_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_CTRL_VSYNC_POLARITY_MASK (0x400U)
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_VSYNC_POLARITY_SHIFT (10U)
/*! VSYNC_POLARITY - Vsync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_CTRL_VSYNC_POLARITY_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_CTRL_VSYNC_POLARITY_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_CTRL_DE_POLARITY_MASK (0x800U)
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_DE_POLARITY_SHIFT (11U)
/*! DE_POLARITY - DE Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_DE_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_CTRL_DE_POLARITY_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_CTRL_DE_POLARITY_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_CTRL_PIXEL_FORMAT_MASK (0x1000U)
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_PIXEL_FORMAT_SHIFT (12U)
/*! PIXEL_FORMAT - Pixel Format
 *  0b0..RGB format
 *  0b1..YUV format
 */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_PIXEL_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_CTRL_PIXEL_FORMAT_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_CTRL_PIXEL_FORMAT_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_CTRL_YUV_CONV_MASK (0x2000U)
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_YUV_CONV_SHIFT (13U)
/*! YUV_CONV - YUV444 to YUV422 Conversion Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_YUV_CONV(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_CTRL_YUV_CONV_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_CTRL_YUV_CONV_MASK)
/*! @} */

/* The count of DISPLAY_PIXEL_INTERLEAVER_CTRL */
#define DISPLAY_PIXEL_INTERLEAVER_CTRL_COUNT     (2U)

/*! @name SWRST - DISP_IN0 Software Reset Control Register..DISP_IN1 Software Reset Control Register */
/*! @{ */

#define DISPLAY_PIXEL_INTERLEAVER_SWRST_SW_RST_MASK (0x2U)
#define DISPLAY_PIXEL_INTERLEAVER_SWRST_SW_RST_SHIFT (1U)
/*! SW_RST - Software Reset
 *  0b0..No action
 *  0b1..Software reset is available
 */
#define DISPLAY_PIXEL_INTERLEAVER_SWRST_SW_RST(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_SWRST_SW_RST_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_SWRST_SW_RST_MASK)
/*! @} */

/* The count of DISPLAY_PIXEL_INTERLEAVER_SWRST */
#define DISPLAY_PIXEL_INTERLEAVER_SWRST_COUNT    (2U)

/*! @name IE - DISP_IN0 Interrupt Enable Register..DISP_IN1 Interrupt Enable Register */
/*! @{ */

#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE0_MASK (0x1U)
#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE0_SHIFT (0U)
/*! FOVF_IE0 - FIFO 0 Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE0_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE0_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE1_MASK (0x2U)
#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE1_SHIFT (1U)
/*! FOVF_IE1 - FIFO 1 Overflow Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE1_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_IE_FOVF_IE1_MASK)
/*! @} */

/* The count of DISPLAY_PIXEL_INTERLEAVER_IE */
#define DISPLAY_PIXEL_INTERLEAVER_IE_COUNT       (2U)

/*! @name IS - DISP_IN0 Interrupt Status Register..DISP_IN1 Interrupt Status Register */
/*! @{ */

#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS0_MASK (0x1U)
#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS0_SHIFT (0U)
/*! FOVF_IS0 - FIFO 0 Overflow Interrupt Status
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS0_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS0_MASK)

#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS1_MASK (0x2U)
#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS1_SHIFT (1U)
/*! FOVF_IS1 - FIFO 1 Overflow Interrupt Status
 *  0b0..Did not occur
 *  0b1..Occurred
 */
#define DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS1_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_IS_FOVF_IS1_MASK)
/*! @} */

/* The count of DISPLAY_PIXEL_INTERLEAVER_IS */
#define DISPLAY_PIXEL_INTERLEAVER_IS_COUNT       (2U)

/*! @name ICTRL - DISP_IN0 Interleaving Control Register..DISP_IN1 Interleaving Control Register */
/*! @{ */

#define DISPLAY_PIXEL_INTERLEAVER_ICTRL_WIDTH_MASK (0xFFFU)
#define DISPLAY_PIXEL_INTERLEAVER_ICTRL_WIDTH_SHIFT (0U)
/*! WIDTH - Width Control for Interleaving Operation */
#define DISPLAY_PIXEL_INTERLEAVER_ICTRL_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_INTERLEAVER_ICTRL_WIDTH_SHIFT)) & DISPLAY_PIXEL_INTERLEAVER_ICTRL_WIDTH_MASK)
/*! @} */

/* The count of DISPLAY_PIXEL_INTERLEAVER_ICTRL */
#define DISPLAY_PIXEL_INTERLEAVER_ICTRL_COUNT    (2U)


/*!
 * @}
 */ /* end of group DISPLAY_PIXEL_INTERLEAVER_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_PIXEL_INTERLEAVER_Peripheral_Access_Layer */


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


#endif  /* DISPLAY_PIXEL_INTERLEAVER_H_ */

