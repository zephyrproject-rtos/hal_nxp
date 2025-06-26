/*
** ###################################################################
**     Processors:          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 5.0, 2021-03-01
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LCDIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**
** ###################################################################
*/

/*!
 * @file LCDIF.h
 * @version 5.0
 * @date 2021-03-01
 * @brief CMSIS Peripheral Access Layer for LCDIF
 *
 * CMSIS Peripheral Access Layer for LCDIF
 */

#if !defined(LCDIF_H_)
#define LCDIF_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- LCDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Peripheral_Access_Layer LCDIF Peripheral Access Layer
 * @{
 */

/** LCDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< LCDIF display control Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< LCDIF display control Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< LCDIF display control Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< LCDIF display control Register, offset: 0xC */
  __IO uint32_t DISP_PARA;                         /**< Display Parameter Register, offset: 0x10 */
  __IO uint32_t DISP_SIZE;                         /**< Display Size Register, offset: 0x14 */
  __IO uint32_t HSYN_PARA;                         /**< Horizontal Sync Parameter Register, offset: 0x18 */
  __IO uint32_t VSYN_PARA;                         /**< Vertical Sync Parameter Register, offset: 0x1C */
  __IO uint32_t VSYN_HSYN_WIDTH;                   /**< Vertical and Horizontal Pulse Width Parameter Register, offset: 0x20 */
  __IO uint32_t INT_STATUS_D0;                     /**< Interrupt Status Register for domain 0, offset: 0x24 */
  __IO uint32_t INT_ENABLE_D0;                     /**< Interrupt Enable Register for domain 0, offset: 0x28 */
       uint8_t RESERVED_0[4];
  __IO uint32_t INT_STATUS_D1;                     /**< Interrupt Status Register for domain 0, offset: 0x30 */
  __IO uint32_t INT_ENABLE_D1;                     /**< Interrupt Enable Register for domain 0, offset: 0x34 */
       uint8_t RESERVED_1[456];
  __IO uint32_t CTRLDESCL0_1;                      /**< Control Descriptor Layer Register 1, offset: 0x200 */
       uint8_t RESERVED_2[4];
  __IO uint32_t CTRLDESCL0_3;                      /**< Control Descriptor Layer Register 3, offset: 0x208 */
  __IO uint32_t CTRLDESCL_LOW0_4;                  /**< Control Descriptor Layer Register 4, offset: 0x20C */
  __IO uint32_t CTRLDESCL_HIGH0_4;                 /**< Control Descriptor Layer Register 4, offset: 0x210 */
  __IO uint32_t CTRLDESCL0_5;                      /**< Control Descriptor Layer Register 5, offset: 0x214 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CSC0_CTRL;                         /**< Color Space Conversion Ctrl Register, offset: 0x21C */
  __IO uint32_t CSC0_COEF0;                        /**< Color Space Conversion Coefficient Register 0, offset: 0x220 */
  __IO uint32_t CSC0_COEF1;                        /**< Color Space Conversion Coefficient Register 1, offset: 0x224 */
  __IO uint32_t CSC0_COEF2;                        /**< Color Space Conversion Coefficient Register 2, offset: 0x228 */
  __IO uint32_t CSC0_COEF3;                        /**< Color Space Conversion Coefficient Register 3, offset: 0x22C */
  __IO uint32_t CSC0_COEF4;                        /**< Color Space Conversion Coefficient Register 4, offset: 0x230 */
  __IO uint32_t CSC0_COEF5;                        /**< Color Space Conversion Coefficient Register 0, offset: 0x234 */
  __IO uint32_t PANIC0_THRES;                      /**< Memory request priority threshold register, offset: 0x238 */
} LCDIF_Type;

/* ----------------------------------------------------------------------------
   -- LCDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Register_Masks LCDIF Register Masks
 * @{
 */

/*! @name CTRL - LCDIF display control Register */
/*! @{ */

#define LCDIF_CTRL_INV_HS_MASK                   (0x1U)
#define LCDIF_CTRL_INV_HS_SHIFT                  (0U)
/*! INV_HS - Invert Horizontal synchronization signal.
 *  0b0..HSYNC signal not inverted (active HIGH).
 *  0b1..Invert HSYNC signal (active LOW).
 */
#define LCDIF_CTRL_INV_HS(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INV_HS_SHIFT)) & LCDIF_CTRL_INV_HS_MASK)

#define LCDIF_CTRL_INV_VS_MASK                   (0x2U)
#define LCDIF_CTRL_INV_VS_SHIFT                  (1U)
/*! INV_VS - Invert Vertical synchronization signal.
 *  0b0..VSYNC signal not inverted (active HIGH).
 *  0b1..Invert VSYNC signal (active LOW).
 */
#define LCDIF_CTRL_INV_VS(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INV_VS_SHIFT)) & LCDIF_CTRL_INV_VS_MASK)

#define LCDIF_CTRL_INV_DE_MASK                   (0x4U)
#define LCDIF_CTRL_INV_DE_SHIFT                  (2U)
/*! INV_DE - Invert Data Enable polarity
 *  0b0..Data enable is active high
 *  0b1..Data enable is active low
 */
#define LCDIF_CTRL_INV_DE(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INV_DE_SHIFT)) & LCDIF_CTRL_INV_DE_MASK)

#define LCDIF_CTRL_INV_PXCK_MASK                 (0x8U)
#define LCDIF_CTRL_INV_PXCK_SHIFT                (3U)
/*! INV_PXCK - Polarity change of Pixel Clock.
 *  0b0..Display samples data on the falling edge
 *  0b1..Display samples data on the rising edge
 */
#define LCDIF_CTRL_INV_PXCK(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INV_PXCK_SHIFT)) & LCDIF_CTRL_INV_PXCK_MASK)

#define LCDIF_CTRL_NEG_MASK                      (0x10U)
#define LCDIF_CTRL_NEG_SHIFT                     (4U)
/*! NEG - Indicates if value at the output (pixel data output) needs to be negated.
 *  0b0..Output is to remain same
 *  0b1..Output to be negated
 */
#define LCDIF_CTRL_NEG(x)                        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_NEG_SHIFT)) & LCDIF_CTRL_NEG_MASK)

#define LCDIF_CTRL_fetch_start_option_MASK       (0x300U)
#define LCDIF_CTRL_fetch_start_option_SHIFT      (8U)
/*! fetch_start_option - Indicates when to start fetching for new frame. This signals also decide the shadow load, fifo clear time
 *  0b00..fetch start as soon as FPV begins(as the end of the data_enable)
 *  0b01..fetch start as soon as PWV begins
 *  0b10..fetch start as soon as BPV begins
 *  0b11..fetch start as soon as RESV begins(still have hsync blanking for margin)
 */
#define LCDIF_CTRL_fetch_start_option(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_fetch_start_option_SHIFT)) & LCDIF_CTRL_fetch_start_option_MASK)

#define LCDIF_CTRL_SW_RESET_MASK                 (0x80000000U)
#define LCDIF_CTRL_SW_RESET_SHIFT                (31U)
/*! SW_RESET - SW_RESET
 *  0b0..No action
 *  0b1..All LCDIF internal registers are forced into their reset state. User registers are not affected.
 */
#define LCDIF_CTRL_SW_RESET(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SW_RESET_SHIFT)) & LCDIF_CTRL_SW_RESET_MASK)
/*! @} */

/*! @name CTRL_SET - LCDIF display control Register */
/*! @{ */

#define LCDIF_CTRL_SET_INV_HS_MASK               (0x1U)
#define LCDIF_CTRL_SET_INV_HS_SHIFT              (0U)
/*! INV_HS - Invert Horizontal synchronization signal.
 *  0b0..HSYNC signal not inverted (active HIGH).
 *  0b1..Invert HSYNC signal (active LOW).
 */
#define LCDIF_CTRL_SET_INV_HS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INV_HS_SHIFT)) & LCDIF_CTRL_SET_INV_HS_MASK)

#define LCDIF_CTRL_SET_INV_VS_MASK               (0x2U)
#define LCDIF_CTRL_SET_INV_VS_SHIFT              (1U)
/*! INV_VS - Invert Vertical synchronization signal.
 *  0b0..VSYNC signal not inverted (active HIGH).
 *  0b1..Invert VSYNC signal (active LOW).
 */
#define LCDIF_CTRL_SET_INV_VS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INV_VS_SHIFT)) & LCDIF_CTRL_SET_INV_VS_MASK)

#define LCDIF_CTRL_SET_INV_DE_MASK               (0x4U)
#define LCDIF_CTRL_SET_INV_DE_SHIFT              (2U)
/*! INV_DE - Invert Data Enable polarity
 *  0b0..Data enable is active high
 *  0b1..Data enable is active low
 */
#define LCDIF_CTRL_SET_INV_DE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INV_DE_SHIFT)) & LCDIF_CTRL_SET_INV_DE_MASK)

#define LCDIF_CTRL_SET_INV_PXCK_MASK             (0x8U)
#define LCDIF_CTRL_SET_INV_PXCK_SHIFT            (3U)
/*! INV_PXCK - Polarity change of Pixel Clock.
 *  0b0..Display samples data on the falling edge
 *  0b1..Display samples data on the rising edge
 */
#define LCDIF_CTRL_SET_INV_PXCK(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INV_PXCK_SHIFT)) & LCDIF_CTRL_SET_INV_PXCK_MASK)

#define LCDIF_CTRL_SET_NEG_MASK                  (0x10U)
#define LCDIF_CTRL_SET_NEG_SHIFT                 (4U)
/*! NEG - Indicates if value at the output (pixel data output) needs to be negated.
 *  0b0..Output is to remain same
 *  0b1..Output to be negated
 */
#define LCDIF_CTRL_SET_NEG(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_NEG_SHIFT)) & LCDIF_CTRL_SET_NEG_MASK)

#define LCDIF_CTRL_SET_fetch_start_option_MASK   (0x300U)
#define LCDIF_CTRL_SET_fetch_start_option_SHIFT  (8U)
/*! fetch_start_option - Indicates when to start fetching for new frame. This signals also decide the shadow load, fifo clear time
 *  0b00..fetch start as soon as FPV begins(as the end of the data_enable)
 *  0b01..fetch start as soon as PWV begins
 *  0b10..fetch start as soon as BPV begins
 *  0b11..fetch start as soon as RESV begins(still have hsync blanking for margin)
 */
#define LCDIF_CTRL_SET_fetch_start_option(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_fetch_start_option_SHIFT)) & LCDIF_CTRL_SET_fetch_start_option_MASK)

#define LCDIF_CTRL_SET_SW_RESET_MASK             (0x80000000U)
#define LCDIF_CTRL_SET_SW_RESET_SHIFT            (31U)
/*! SW_RESET - SW_RESET
 *  0b0..No action
 *  0b1..All LCDIF internal registers are forced into their reset state. User registers are not affected.
 */
#define LCDIF_CTRL_SET_SW_RESET(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_SW_RESET_SHIFT)) & LCDIF_CTRL_SET_SW_RESET_MASK)
/*! @} */

/*! @name CTRL_CLR - LCDIF display control Register */
/*! @{ */

#define LCDIF_CTRL_CLR_INV_HS_MASK               (0x1U)
#define LCDIF_CTRL_CLR_INV_HS_SHIFT              (0U)
/*! INV_HS - Invert Horizontal synchronization signal.
 *  0b0..HSYNC signal not inverted (active HIGH).
 *  0b1..Invert HSYNC signal (active LOW).
 */
#define LCDIF_CTRL_CLR_INV_HS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INV_HS_SHIFT)) & LCDIF_CTRL_CLR_INV_HS_MASK)

#define LCDIF_CTRL_CLR_INV_VS_MASK               (0x2U)
#define LCDIF_CTRL_CLR_INV_VS_SHIFT              (1U)
/*! INV_VS - Invert Vertical synchronization signal.
 *  0b0..VSYNC signal not inverted (active HIGH).
 *  0b1..Invert VSYNC signal (active LOW).
 */
#define LCDIF_CTRL_CLR_INV_VS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INV_VS_SHIFT)) & LCDIF_CTRL_CLR_INV_VS_MASK)

#define LCDIF_CTRL_CLR_INV_DE_MASK               (0x4U)
#define LCDIF_CTRL_CLR_INV_DE_SHIFT              (2U)
/*! INV_DE - Invert Data Enable polarity
 *  0b0..Data enable is active high
 *  0b1..Data enable is active low
 */
#define LCDIF_CTRL_CLR_INV_DE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INV_DE_SHIFT)) & LCDIF_CTRL_CLR_INV_DE_MASK)

#define LCDIF_CTRL_CLR_INV_PXCK_MASK             (0x8U)
#define LCDIF_CTRL_CLR_INV_PXCK_SHIFT            (3U)
/*! INV_PXCK - Polarity change of Pixel Clock.
 *  0b0..Display samples data on the falling edge
 *  0b1..Display samples data on the rising edge
 */
#define LCDIF_CTRL_CLR_INV_PXCK(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INV_PXCK_SHIFT)) & LCDIF_CTRL_CLR_INV_PXCK_MASK)

#define LCDIF_CTRL_CLR_NEG_MASK                  (0x10U)
#define LCDIF_CTRL_CLR_NEG_SHIFT                 (4U)
/*! NEG - Indicates if value at the output (pixel data output) needs to be negated.
 *  0b0..Output is to remain same
 *  0b1..Output to be negated
 */
#define LCDIF_CTRL_CLR_NEG(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_NEG_SHIFT)) & LCDIF_CTRL_CLR_NEG_MASK)

#define LCDIF_CTRL_CLR_fetch_start_option_MASK   (0x300U)
#define LCDIF_CTRL_CLR_fetch_start_option_SHIFT  (8U)
/*! fetch_start_option - Indicates when to start fetching for new frame. This signals also decide the shadow load, fifo clear time
 *  0b00..fetch start as soon as FPV begins(as the end of the data_enable)
 *  0b01..fetch start as soon as PWV begins
 *  0b10..fetch start as soon as BPV begins
 *  0b11..fetch start as soon as RESV begins(still have hsync blanking for margin)
 */
#define LCDIF_CTRL_CLR_fetch_start_option(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_fetch_start_option_SHIFT)) & LCDIF_CTRL_CLR_fetch_start_option_MASK)

#define LCDIF_CTRL_CLR_SW_RESET_MASK             (0x80000000U)
#define LCDIF_CTRL_CLR_SW_RESET_SHIFT            (31U)
/*! SW_RESET - SW_RESET
 *  0b0..No action
 *  0b1..All LCDIF internal registers are forced into their reset state. User registers are not affected.
 */
#define LCDIF_CTRL_CLR_SW_RESET(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_SW_RESET_SHIFT)) & LCDIF_CTRL_CLR_SW_RESET_MASK)
/*! @} */

/*! @name CTRL_TOG - LCDIF display control Register */
/*! @{ */

#define LCDIF_CTRL_TOG_INV_HS_MASK               (0x1U)
#define LCDIF_CTRL_TOG_INV_HS_SHIFT              (0U)
/*! INV_HS - Invert Horizontal synchronization signal.
 *  0b0..HSYNC signal not inverted (active HIGH).
 *  0b1..Invert HSYNC signal (active LOW).
 */
#define LCDIF_CTRL_TOG_INV_HS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INV_HS_SHIFT)) & LCDIF_CTRL_TOG_INV_HS_MASK)

#define LCDIF_CTRL_TOG_INV_VS_MASK               (0x2U)
#define LCDIF_CTRL_TOG_INV_VS_SHIFT              (1U)
/*! INV_VS - Invert Vertical synchronization signal.
 *  0b0..VSYNC signal not inverted (active HIGH).
 *  0b1..Invert VSYNC signal (active LOW).
 */
#define LCDIF_CTRL_TOG_INV_VS(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INV_VS_SHIFT)) & LCDIF_CTRL_TOG_INV_VS_MASK)

#define LCDIF_CTRL_TOG_INV_DE_MASK               (0x4U)
#define LCDIF_CTRL_TOG_INV_DE_SHIFT              (2U)
/*! INV_DE - Invert Data Enable polarity
 *  0b0..Data enable is active high
 *  0b1..Data enable is active low
 */
#define LCDIF_CTRL_TOG_INV_DE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INV_DE_SHIFT)) & LCDIF_CTRL_TOG_INV_DE_MASK)

#define LCDIF_CTRL_TOG_INV_PXCK_MASK             (0x8U)
#define LCDIF_CTRL_TOG_INV_PXCK_SHIFT            (3U)
/*! INV_PXCK - Polarity change of Pixel Clock.
 *  0b0..Display samples data on the falling edge
 *  0b1..Display samples data on the rising edge
 */
#define LCDIF_CTRL_TOG_INV_PXCK(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INV_PXCK_SHIFT)) & LCDIF_CTRL_TOG_INV_PXCK_MASK)

#define LCDIF_CTRL_TOG_NEG_MASK                  (0x10U)
#define LCDIF_CTRL_TOG_NEG_SHIFT                 (4U)
/*! NEG - Indicates if value at the output (pixel data output) needs to be negated.
 *  0b0..Output is to remain same
 *  0b1..Output to be negated
 */
#define LCDIF_CTRL_TOG_NEG(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_NEG_SHIFT)) & LCDIF_CTRL_TOG_NEG_MASK)

#define LCDIF_CTRL_TOG_fetch_start_option_MASK   (0x300U)
#define LCDIF_CTRL_TOG_fetch_start_option_SHIFT  (8U)
/*! fetch_start_option - Indicates when to start fetching for new frame. This signals also decide the shadow load, fifo clear time
 *  0b00..fetch start as soon as FPV begins(as the end of the data_enable)
 *  0b01..fetch start as soon as PWV begins
 *  0b10..fetch start as soon as BPV begins
 *  0b11..fetch start as soon as RESV begins(still have hsync blanking for margin)
 */
#define LCDIF_CTRL_TOG_fetch_start_option(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_fetch_start_option_SHIFT)) & LCDIF_CTRL_TOG_fetch_start_option_MASK)

#define LCDIF_CTRL_TOG_SW_RESET_MASK             (0x80000000U)
#define LCDIF_CTRL_TOG_SW_RESET_SHIFT            (31U)
/*! SW_RESET - SW_RESET
 *  0b0..No action
 *  0b1..All LCDIF internal registers are forced into their reset state. User registers are not affected.
 */
#define LCDIF_CTRL_TOG_SW_RESET(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_SW_RESET_SHIFT)) & LCDIF_CTRL_TOG_SW_RESET_MASK)
/*! @} */

/*! @name DISP_PARA - Display Parameter Register */
/*! @{ */

#define LCDIF_DISP_PARA_BGND_B_MASK              (0xFFU)
#define LCDIF_DISP_PARA_BGND_B_SHIFT             (0U)
/*! BGND_B - Blue component of the default color displayed in the sectors where no layer is active. */
#define LCDIF_DISP_PARA_BGND_B(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_BGND_B_SHIFT)) & LCDIF_DISP_PARA_BGND_B_MASK)

#define LCDIF_DISP_PARA_BGND_G_MASK              (0xFF00U)
#define LCDIF_DISP_PARA_BGND_G_SHIFT             (8U)
/*! BGND_G - Green component of the default color displayed in the sectors where no layer is active. */
#define LCDIF_DISP_PARA_BGND_G(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_BGND_G_SHIFT)) & LCDIF_DISP_PARA_BGND_G_MASK)

#define LCDIF_DISP_PARA_BGND_R_MASK              (0xFF0000U)
#define LCDIF_DISP_PARA_BGND_R_SHIFT             (16U)
/*! BGND_R - Red component of the default color displayed in the sectors where no layer is active. */
#define LCDIF_DISP_PARA_BGND_R(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_BGND_R_SHIFT)) & LCDIF_DISP_PARA_BGND_R_MASK)

#define LCDIF_DISP_PARA_DISP_MODE_MASK           (0x3000000U)
#define LCDIF_DISP_PARA_DISP_MODE_SHIFT          (24U)
/*! DISP_MODE - LCDIF operating mode.
 *  0b00..Normal mode. Panel content controlled by layer configuration.
 *  0b01..Test Mode1.(BGND Color Display)
 *  0b10..Test Mode2.(Column Color Bar)
 *  0b11..Test Mode3.(Row Color Bar)
 */
#define LCDIF_DISP_PARA_DISP_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_DISP_MODE_SHIFT)) & LCDIF_DISP_PARA_DISP_MODE_MASK)

#define LCDIF_DISP_PARA_LINE_PATTERN_MASK        (0x3C000000U)
#define LCDIF_DISP_PARA_LINE_PATTERN_SHIFT       (26U)
/*! LINE_PATTERN - LCDIF line output order.
 *  0b0000..RGB/YUV.
 *  0b0001..RBG.
 *  0b0010..GBR.
 *  0b0011..GRB/UYV.
 *  0b0100..BRG.
 *  0b0101..BGR.
 *  0b0110..RGB555.
 *  0b0111..RGB565.
 *  0b1000..YUYV at [16:0].
 *  0b1001..UYVY at [16:0].
 *  0b1010..YVYU at [16:0].
 *  0b1011..YUYV at [16:0].
 *  0b1100..YUYV at [23:8].
 *  0b1101..UYVY at [23:8].
 *  0b1110..YVYU at [23:8].
 *  0b1111..YUYV at [23:8].
 */
#define LCDIF_DISP_PARA_LINE_PATTERN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_LINE_PATTERN_SHIFT)) & LCDIF_DISP_PARA_LINE_PATTERN_MASK)

#define LCDIF_DISP_PARA_SWAP_EN_MASK             (0x40000000U)
#define LCDIF_DISP_PARA_SWAP_EN_SHIFT            (30U)
/*! SWAP_EN - output data swap enable.
 *  0b0..swap disable
 *  0b1..swap enbale, output data will swap the high 16bits with the low 16bits.
 */
#define LCDIF_DISP_PARA_SWAP_EN(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_SWAP_EN_SHIFT)) & LCDIF_DISP_PARA_SWAP_EN_MASK)

#define LCDIF_DISP_PARA_DISP_ON_MASK             (0x80000000U)
#define LCDIF_DISP_PARA_DISP_ON_SHIFT            (31U)
/*! DISP_ON - Display panel On/Off mode.
 *  0b0..Display Off.
 *  0b1..Display On.
 */
#define LCDIF_DISP_PARA_DISP_ON(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_PARA_DISP_ON_SHIFT)) & LCDIF_DISP_PARA_DISP_ON_MASK)
/*! @} */

/*! @name DISP_SIZE - Display Size Register */
/*! @{ */

#define LCDIF_DISP_SIZE_DELTA_X_MASK             (0xFFFFU)
#define LCDIF_DISP_SIZE_DELTA_X_SHIFT            (0U)
/*! DELTA_X - Sets the display size horizontal resolution in pixels. */
#define LCDIF_DISP_SIZE_DELTA_X(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_SIZE_DELTA_X_SHIFT)) & LCDIF_DISP_SIZE_DELTA_X_MASK)

#define LCDIF_DISP_SIZE_DELTA_Y_MASK             (0xFFFF0000U)
#define LCDIF_DISP_SIZE_DELTA_Y_SHIFT            (16U)
/*! DELTA_Y - Sets the display size vertical resolution in pixels. */
#define LCDIF_DISP_SIZE_DELTA_Y(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISP_SIZE_DELTA_Y_SHIFT)) & LCDIF_DISP_SIZE_DELTA_Y_MASK)
/*! @} */

/*! @name HSYN_PARA - Horizontal Sync Parameter Register */
/*! @{ */

#define LCDIF_HSYN_PARA_FP_H_MASK                (0xFFFFU)
#define LCDIF_HSYN_PARA_FP_H_SHIFT               (0U)
/*! FP_H - HSYNC front-porch pulse width (in pixel clock cycles). Pulse width has a minimum value of 1. */
#define LCDIF_HSYN_PARA_FP_H(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYN_PARA_FP_H_SHIFT)) & LCDIF_HSYN_PARA_FP_H_MASK)

#define LCDIF_HSYN_PARA_BP_H_MASK                (0xFFFF0000U)
#define LCDIF_HSYN_PARA_BP_H_SHIFT               (16U)
/*! BP_H - HSYNC back-porch pulse width (in pixel clock cycles). Pulse width has a minimum value of 1. */
#define LCDIF_HSYN_PARA_BP_H(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYN_PARA_BP_H_SHIFT)) & LCDIF_HSYN_PARA_BP_H_MASK)
/*! @} */

/*! @name VSYN_PARA - Vertical Sync Parameter Register */
/*! @{ */

#define LCDIF_VSYN_PARA_FP_V_MASK                (0xFFFFU)
#define LCDIF_VSYN_PARA_FP_V_SHIFT               (0U)
/*! FP_V - VSYNC front-porch pulse width (in horizontal line cycles). Pulse width has a minimum value of 1. */
#define LCDIF_VSYN_PARA_FP_V(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYN_PARA_FP_V_SHIFT)) & LCDIF_VSYN_PARA_FP_V_MASK)

#define LCDIF_VSYN_PARA_BP_V_MASK                (0xFFFF0000U)
#define LCDIF_VSYN_PARA_BP_V_SHIFT               (16U)
/*! BP_V - VSYNC back-porch pulse width (in horizontal line cycles). Pulse width has a minimum value of 1. */
#define LCDIF_VSYN_PARA_BP_V(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYN_PARA_BP_V_SHIFT)) & LCDIF_VSYN_PARA_BP_V_MASK)
/*! @} */

/*! @name VSYN_HSYN_WIDTH - Vertical and Horizontal Pulse Width Parameter Register */
/*! @{ */

#define LCDIF_VSYN_HSYN_WIDTH_PW_H_MASK          (0xFFFFU)
#define LCDIF_VSYN_HSYN_WIDTH_PW_H_SHIFT         (0U)
/*! PW_H - HSYNC active pulse width (in pixel clock cycles). Pulse width has a minimum value of 1. */
#define LCDIF_VSYN_HSYN_WIDTH_PW_H(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYN_HSYN_WIDTH_PW_H_SHIFT)) & LCDIF_VSYN_HSYN_WIDTH_PW_H_MASK)

#define LCDIF_VSYN_HSYN_WIDTH_PW_V_MASK          (0xFFFF0000U)
#define LCDIF_VSYN_HSYN_WIDTH_PW_V_SHIFT         (16U)
/*! PW_V - VSYNC active pulse width (in horizontal line cycles). Pulse width has a minimum value of 1. */
#define LCDIF_VSYN_HSYN_WIDTH_PW_V(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYN_HSYN_WIDTH_PW_V_SHIFT)) & LCDIF_VSYN_HSYN_WIDTH_PW_V_MASK)
/*! @} */

/*! @name INT_STATUS_D0 - Interrupt Status Register for domain 0 */
/*! @{ */

#define LCDIF_INT_STATUS_D0_VSYNC_MASK           (0x1U)
#define LCDIF_INT_STATUS_D0_VSYNC_SHIFT          (0U)
/*! VSYNC - Interrupt flag to indicate that the vertical synchronization phase(The beginning of a frame). */
#define LCDIF_INT_STATUS_D0_VSYNC(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_VSYNC_SHIFT)) & LCDIF_INT_STATUS_D0_VSYNC_MASK)

#define LCDIF_INT_STATUS_D0_UNDERRUN_MASK        (0x2U)
#define LCDIF_INT_STATUS_D0_UNDERRUN_SHIFT       (1U)
/*! UNDERRUN - Interrupt flag to indicate the output buffer underrun condition. */
#define LCDIF_INT_STATUS_D0_UNDERRUN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_UNDERRUN_SHIFT)) & LCDIF_INT_STATUS_D0_UNDERRUN_MASK)

#define LCDIF_INT_STATUS_D0_VS_BLANK_MASK        (0x4U)
#define LCDIF_INT_STATUS_D0_VS_BLANK_SHIFT       (2U)
/*! VS_BLANK - Interrupt flag to indicate vertical blanking period. */
#define LCDIF_INT_STATUS_D0_VS_BLANK(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_VS_BLANK_SHIFT)) & LCDIF_INT_STATUS_D0_VS_BLANK_MASK)

#define LCDIF_INT_STATUS_D0_DMA_ERR_MASK         (0x100U)
#define LCDIF_INT_STATUS_D0_DMA_ERR_SHIFT        (8U)
/*! DMA_ERR - Interrupt flag to indicate that which PLANE has Read Error on the AXI interface. */
#define LCDIF_INT_STATUS_D0_DMA_ERR(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_DMA_ERR_SHIFT)) & LCDIF_INT_STATUS_D0_DMA_ERR_MASK)

#define LCDIF_INT_STATUS_D0_DMA_DONE_MASK        (0x10000U)
#define LCDIF_INT_STATUS_D0_DMA_DONE_SHIFT       (16U)
/*! DMA_DONE - Interrupt flag to indicate that which PLANE has fetched the last pixel from memory. */
#define LCDIF_INT_STATUS_D0_DMA_DONE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_DMA_DONE_SHIFT)) & LCDIF_INT_STATUS_D0_DMA_DONE_MASK)

#define LCDIF_INT_STATUS_D0_FIFO_EMPTY_MASK      (0x1000000U)
#define LCDIF_INT_STATUS_D0_FIFO_EMPTY_SHIFT     (24U)
/*! FIFO_EMPTY - Interrupt flag to indicate that which FIFO in the pixel blending underflowed. */
#define LCDIF_INT_STATUS_D0_FIFO_EMPTY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D0_FIFO_EMPTY_SHIFT)) & LCDIF_INT_STATUS_D0_FIFO_EMPTY_MASK)
/*! @} */

/*! @name INT_ENABLE_D0 - Interrupt Enable Register for domain 0 */
/*! @{ */

#define LCDIF_INT_ENABLE_D0_VSYNC_EN_MASK        (0x1U)
#define LCDIF_INT_ENABLE_D0_VSYNC_EN_SHIFT       (0U)
/*! VSYNC_EN - Enable Interrupt flag to indicate that the vertical synchronization phase(The beginning of a frame). */
#define LCDIF_INT_ENABLE_D0_VSYNC_EN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_VSYNC_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_VSYNC_EN_MASK)

#define LCDIF_INT_ENABLE_D0_UNDERRUN_EN_MASK     (0x2U)
#define LCDIF_INT_ENABLE_D0_UNDERRUN_EN_SHIFT    (1U)
/*! UNDERRUN_EN - Enable Interrupt flag to indicate the output buffer underrun condition. */
#define LCDIF_INT_ENABLE_D0_UNDERRUN_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_UNDERRUN_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_UNDERRUN_EN_MASK)

#define LCDIF_INT_ENABLE_D0_VS_BLANK_EN_MASK     (0x4U)
#define LCDIF_INT_ENABLE_D0_VS_BLANK_EN_SHIFT    (2U)
/*! VS_BLANK_EN - Enable Interrupt flag to indicate vertical blanking period. */
#define LCDIF_INT_ENABLE_D0_VS_BLANK_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_VS_BLANK_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_VS_BLANK_EN_MASK)

#define LCDIF_INT_ENABLE_D0_DMA_ERR_EN_MASK      (0x100U)
#define LCDIF_INT_ENABLE_D0_DMA_ERR_EN_SHIFT     (8U)
/*! DMA_ERR_EN - Enable Interrupt flag to indicate that which PLANE has Read Error on the AXI interface. */
#define LCDIF_INT_ENABLE_D0_DMA_ERR_EN(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_DMA_ERR_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_DMA_ERR_EN_MASK)

#define LCDIF_INT_ENABLE_D0_DMA_DONE_EN_MASK     (0x10000U)
#define LCDIF_INT_ENABLE_D0_DMA_DONE_EN_SHIFT    (16U)
/*! DMA_DONE_EN - Enable Interrupt flag to indicate that which PLANE has fetched the last pixel from memory. */
#define LCDIF_INT_ENABLE_D0_DMA_DONE_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_DMA_DONE_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_DMA_DONE_EN_MASK)

#define LCDIF_INT_ENABLE_D0_FIFO_EMPTY_EN_MASK   (0x1000000U)
#define LCDIF_INT_ENABLE_D0_FIFO_EMPTY_EN_SHIFT  (24U)
/*! FIFO_EMPTY_EN - Enable Interrupt flag to indicate that which FIFO in the pixel blending underflowed. */
#define LCDIF_INT_ENABLE_D0_FIFO_EMPTY_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D0_FIFO_EMPTY_EN_SHIFT)) & LCDIF_INT_ENABLE_D0_FIFO_EMPTY_EN_MASK)
/*! @} */

/*! @name INT_STATUS_D1 - Interrupt Status Register for domain 0 */
/*! @{ */

#define LCDIF_INT_STATUS_D1_PLANE_PANIC_MASK     (0x1U)
#define LCDIF_INT_STATUS_D1_PLANE_PANIC_SHIFT    (0U)
/*! PLANE_PANIC - plane panic to indicate that which FIFO reaches the panic threshold. */
#define LCDIF_INT_STATUS_D1_PLANE_PANIC(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_STATUS_D1_PLANE_PANIC_SHIFT)) & LCDIF_INT_STATUS_D1_PLANE_PANIC_MASK)
/*! @} */

/*! @name INT_ENABLE_D1 - Interrupt Enable Register for domain 0 */
/*! @{ */

#define LCDIF_INT_ENABLE_D1_PLANE_PANIC_EN_MASK  (0x1U)
#define LCDIF_INT_ENABLE_D1_PLANE_PANIC_EN_SHIFT (0U)
/*! PLANE_PANIC_EN - Enable Interrupt flag to indicate that which FIFO in the pixel blending underflowed. */
#define LCDIF_INT_ENABLE_D1_PLANE_PANIC_EN(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_INT_ENABLE_D1_PLANE_PANIC_EN_SHIFT)) & LCDIF_INT_ENABLE_D1_PLANE_PANIC_EN_MASK)
/*! @} */

/*! @name CTRLDESCL0_1 - Control Descriptor Layer Register 1 */
/*! @{ */

#define LCDIF_CTRLDESCL0_1_WIDTH_MASK            (0xFFFFU)
#define LCDIF_CTRLDESCL0_1_WIDTH_SHIFT           (0U)
/*! WIDTH - Width of the layer in pixels. */
#define LCDIF_CTRLDESCL0_1_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_1_WIDTH_SHIFT)) & LCDIF_CTRLDESCL0_1_WIDTH_MASK)

#define LCDIF_CTRLDESCL0_1_HEIGHT_MASK           (0xFFFF0000U)
#define LCDIF_CTRLDESCL0_1_HEIGHT_SHIFT          (16U)
/*! HEIGHT - Height of the layer in pixels. */
#define LCDIF_CTRLDESCL0_1_HEIGHT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_1_HEIGHT_SHIFT)) & LCDIF_CTRLDESCL0_1_HEIGHT_MASK)
/*! @} */

/*! @name CTRLDESCL0_3 - Control Descriptor Layer Register 3 */
/*! @{ */

#define LCDIF_CTRLDESCL0_3_PITCH_MASK            (0xFFFFU)
#define LCDIF_CTRLDESCL0_3_PITCH_SHIFT           (0U)
/*! PITCH - Number of bytes between 2 vertically adjacent pixels in system memory. Byte granularity
 *    is supported, but SW should align to 64B boundry.
 */
#define LCDIF_CTRLDESCL0_3_PITCH(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_3_PITCH_SHIFT)) & LCDIF_CTRLDESCL0_3_PITCH_MASK)
/*! @} */

/*! @name CTRLDESCL_LOW0_4 - Control Descriptor Layer Register 4 */
/*! @{ */

#define LCDIF_CTRLDESCL_LOW0_4_ADDR_LOW_MASK     (0xFFFFFFFFU)
#define LCDIF_CTRLDESCL_LOW0_4_ADDR_LOW_SHIFT    (0U)
/*! ADDR_LOW - Address of layer data in the memory. The address programmed should be 64-bit aligned. */
#define LCDIF_CTRLDESCL_LOW0_4_ADDR_LOW(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL_LOW0_4_ADDR_LOW_SHIFT)) & LCDIF_CTRLDESCL_LOW0_4_ADDR_LOW_MASK)
/*! @} */

/*! @name CTRLDESCL_HIGH0_4 - Control Descriptor Layer Register 4 */
/*! @{ */

#define LCDIF_CTRLDESCL_HIGH0_4_ADDR_HIGH_MASK   (0xFU)
#define LCDIF_CTRLDESCL_HIGH0_4_ADDR_HIGH_SHIFT  (0U)
/*! ADDR_HIGH - Address of layer data in the memory. The address programmed should be 64-bit aligned. */
#define LCDIF_CTRLDESCL_HIGH0_4_ADDR_HIGH(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL_HIGH0_4_ADDR_HIGH_SHIFT)) & LCDIF_CTRLDESCL_HIGH0_4_ADDR_HIGH_MASK)
/*! @} */

/*! @name CTRLDESCL0_5 - Control Descriptor Layer Register 5 */
/*! @{ */

#define LCDIF_CTRLDESCL0_5_YUV_FORMAT_MASK       (0xC000U)
#define LCDIF_CTRLDESCL0_5_YUV_FORMAT_SHIFT      (14U)
/*! YUV_FORMAT - The YUV422 input format selection.
 *  0b00..The YUV422 32bit memory is {Y2,V1,Y1,U1}
 *  0b01..The YUV422 32bit memory is {Y2,U1,Y1,V1}
 *  0b10..The YUV422 32bit memory is {V1,Y2,U1,Y1}
 *  0b11..The YUV422 32bit memory is {U1,Y2,V1,Y1}
 */
#define LCDIF_CTRLDESCL0_5_YUV_FORMAT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_5_YUV_FORMAT_SHIFT)) & LCDIF_CTRLDESCL0_5_YUV_FORMAT_MASK)

#define LCDIF_CTRLDESCL0_5_BPP_MASK              (0xF000000U)
#define LCDIF_CTRLDESCL0_5_BPP_SHIFT             (24U)
/*! BPP - Layer encoding format (bit per pixel)
 *  0b0100..16 bpp (RGB565)
 *  0b0101..16 bpp (ARGB1555)
 *  0b0110..16 bpp (ARGB4444)
 *  0b0111..YCbCr422
 *  0b1000..24 bpp (RGB888)
 *  0b1001..32 bpp (ARGB8888)
 *  0b1010..32 bpp (ABGR8888)
 */
#define LCDIF_CTRLDESCL0_5_BPP(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_5_BPP_SHIFT)) & LCDIF_CTRLDESCL0_5_BPP_MASK)

#define LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN_MASK   (0x40000000U)
#define LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN_SHIFT  (30U)
/*! SHADOW_LOAD_EN - Shadow Load Enable */
#define LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN_SHIFT)) & LCDIF_CTRLDESCL0_5_SHADOW_LOAD_EN_MASK)

#define LCDIF_CTRLDESCL0_5_EN_MASK               (0x80000000U)
#define LCDIF_CTRLDESCL0_5_EN_SHIFT              (31U)
/*! EN - Enable the layer for DMA.
 *  0b0..OFF
 *  0b1..ON
 */
#define LCDIF_CTRLDESCL0_5_EN(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRLDESCL0_5_EN_SHIFT)) & LCDIF_CTRLDESCL0_5_EN_MASK)
/*! @} */

/*! @name CSC0_CTRL - Color Space Conversion Ctrl Register */
/*! @{ */

#define LCDIF_CSC0_CTRL_BYPASS_MASK              (0x1U)
#define LCDIF_CSC0_CTRL_BYPASS_SHIFT             (0U)
/*! BYPASS - This bit controls whether the pixels entering the CSC2 unit get converted or not. When
 *    BYPASS is set, no operations occur on the pixels. When BYPASS is cleared, the selected CSC
 *    operation takes place.
 */
#define LCDIF_CSC0_CTRL_BYPASS(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_CTRL_BYPASS_SHIFT)) & LCDIF_CSC0_CTRL_BYPASS_MASK)

#define LCDIF_CSC0_CTRL_CSC_MODE_MASK            (0x6U)
#define LCDIF_CSC0_CTRL_CSC_MODE_SHIFT           (1U)
/*! CSC_MODE - This field controls how the CSC unit operates on pixels when the CSC is not bypassed.
 *    0x0 YUV2RGB--Convert from YUV to RGB. 0x1 YCbCr2RGB-- Convert from YCbCr to RGB. 0x2 RGB2YUV
 *    -- Convert from RGB to YUV. 0x3 RGB2YCbCr -- Convert from RGB to YCbCr.
 */
#define LCDIF_CSC0_CTRL_CSC_MODE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_CTRL_CSC_MODE_SHIFT)) & LCDIF_CSC0_CTRL_CSC_MODE_MASK)
/*! @} */

/*! @name CSC0_COEF0 - Color Space Conversion Coefficient Register 0 */
/*! @{ */

#define LCDIF_CSC0_COEF0_A1_MASK                 (0x7FFU)
#define LCDIF_CSC0_COEF0_A1_SHIFT                (0U)
/*! A1 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF0_A1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF0_A1_SHIFT)) & LCDIF_CSC0_COEF0_A1_MASK)

#define LCDIF_CSC0_COEF0_A2_MASK                 (0x7FF0000U)
#define LCDIF_CSC0_COEF0_A2_SHIFT                (16U)
/*! A2 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF0_A2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF0_A2_SHIFT)) & LCDIF_CSC0_COEF0_A2_MASK)
/*! @} */

/*! @name CSC0_COEF1 - Color Space Conversion Coefficient Register 1 */
/*! @{ */

#define LCDIF_CSC0_COEF1_A3_MASK                 (0x7FFU)
#define LCDIF_CSC0_COEF1_A3_SHIFT                (0U)
/*! A3 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF1_A3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF1_A3_SHIFT)) & LCDIF_CSC0_COEF1_A3_MASK)

#define LCDIF_CSC0_COEF1_B1_MASK                 (0x7FF0000U)
#define LCDIF_CSC0_COEF1_B1_SHIFT                (16U)
/*! B1 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF1_B1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF1_B1_SHIFT)) & LCDIF_CSC0_COEF1_B1_MASK)
/*! @} */

/*! @name CSC0_COEF2 - Color Space Conversion Coefficient Register 2 */
/*! @{ */

#define LCDIF_CSC0_COEF2_B2_MASK                 (0x7FFU)
#define LCDIF_CSC0_COEF2_B2_SHIFT                (0U)
/*! B2 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF2_B2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF2_B2_SHIFT)) & LCDIF_CSC0_COEF2_B2_MASK)

#define LCDIF_CSC0_COEF2_B3_MASK                 (0x7FF0000U)
#define LCDIF_CSC0_COEF2_B3_SHIFT                (16U)
/*! B3 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF2_B3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF2_B3_SHIFT)) & LCDIF_CSC0_COEF2_B3_MASK)
/*! @} */

/*! @name CSC0_COEF3 - Color Space Conversion Coefficient Register 3 */
/*! @{ */

#define LCDIF_CSC0_COEF3_C1_MASK                 (0x7FFU)
#define LCDIF_CSC0_COEF3_C1_SHIFT                (0U)
/*! C1 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF3_C1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF3_C1_SHIFT)) & LCDIF_CSC0_COEF3_C1_MASK)

#define LCDIF_CSC0_COEF3_C2_MASK                 (0x7FF0000U)
#define LCDIF_CSC0_COEF3_C2_SHIFT                (16U)
/*! C2 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF3_C2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF3_C2_SHIFT)) & LCDIF_CSC0_COEF3_C2_MASK)
/*! @} */

/*! @name CSC0_COEF4 - Color Space Conversion Coefficient Register 4 */
/*! @{ */

#define LCDIF_CSC0_COEF4_C3_MASK                 (0x7FFU)
#define LCDIF_CSC0_COEF4_C3_SHIFT                (0U)
/*! C3 - Two's complement coefficient offset. This coefficient has a sign bit, 2 bits integer, and 8
 *    bits of fraction as ###.####_####.
 */
#define LCDIF_CSC0_COEF4_C3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF4_C3_SHIFT)) & LCDIF_CSC0_COEF4_C3_MASK)

#define LCDIF_CSC0_COEF4_D1_MASK                 (0x1FF0000U)
#define LCDIF_CSC0_COEF4_D1_SHIFT                (16U)
/*! D1 - Two's complement D1 coefficient integer offset to be added. */
#define LCDIF_CSC0_COEF4_D1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF4_D1_SHIFT)) & LCDIF_CSC0_COEF4_D1_MASK)
/*! @} */

/*! @name CSC0_COEF5 - Color Space Conversion Coefficient Register 0 */
/*! @{ */

#define LCDIF_CSC0_COEF5_D2_MASK                 (0x1FFU)
#define LCDIF_CSC0_COEF5_D2_SHIFT                (0U)
/*! D2 - Two's complement D2 coefficient integer offset to be added. */
#define LCDIF_CSC0_COEF5_D2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF5_D2_SHIFT)) & LCDIF_CSC0_COEF5_D2_MASK)

#define LCDIF_CSC0_COEF5_D3_MASK                 (0x1FF0000U)
#define LCDIF_CSC0_COEF5_D3_SHIFT                (16U)
/*! D3 - Two's complement D3 coefficient integer offset to be added. */
#define LCDIF_CSC0_COEF5_D3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC0_COEF5_D3_SHIFT)) & LCDIF_CSC0_COEF5_D3_MASK)
/*! @} */

/*! @name PANIC0_THRES - Memory request priority threshold register */
/*! @{ */

#define LCDIF_PANIC0_THRES_PANIC_THRES_HIGH_MASK (0x1FFU)
#define LCDIF_PANIC0_THRES_PANIC_THRES_HIGH_SHIFT (0U)
/*! PANIC_THRES_HIGH - This value should be set to a value of pixels, from (0+1)*128bits to
 *    (511+1)*128bits. When the number of pixels in the input pixel FIFO is more than this value, the panic
 *    control output will be removed.This signal can be used to raise the access LCDIF's access
 *    priority.
 */
#define LCDIF_PANIC0_THRES_PANIC_THRES_HIGH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_PANIC0_THRES_PANIC_THRES_HIGH_SHIFT)) & LCDIF_PANIC0_THRES_PANIC_THRES_HIGH_MASK)

#define LCDIF_PANIC0_THRES_PANIC_THRES_LOW_MASK  (0x1FF0000U)
#define LCDIF_PANIC0_THRES_PANIC_THRES_LOW_SHIFT (16U)
/*! PANIC_THRES_LOW - This value should be set to a value of pixels, from (0+1)*128bits to
 *    (511+1)*128bits. When the number of pixels in the input pixel FIFO is less than this value, the panic
 *    control output will be raised.This signal can be used to raise the access LCDIF's access
 *    priority.
 */
#define LCDIF_PANIC0_THRES_PANIC_THRES_LOW(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_PANIC0_THRES_PANIC_THRES_LOW_SHIFT)) & LCDIF_PANIC0_THRES_PANIC_THRES_LOW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LCDIF_Register_Masks */


/*!
 * @}
 */ /* end of group LCDIF_Peripheral_Access_Layer */


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


#endif  /* LCDIF_H_ */

