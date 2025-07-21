/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for APBH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_APBH.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for APBH
 *
 * CMSIS Peripheral Access Layer for APBH
 */

#if !defined(PERI_APBH_H_)
#define PERI_APBH_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- APBH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup APBH_Peripheral_Access_Layer APBH Peripheral Access Layer
 * @{
 */

/** APBH - Size of Registers Arrays */
#define APBH_CH_CFGn_COUNT                        16u

/** APBH - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL0;                             /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x0 */
  __IO uint32_t CTRL0_SET;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x4 */
  __IO uint32_t CTRL0_CLR;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0x8 */
  __IO uint32_t CTRL0_TOG;                         /**< AHB to APBH Bridge Control and Status Register 0, offset: 0xC */
  __IO uint32_t CTRL1;                             /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x10 */
  __IO uint32_t CTRL1_SET;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x14 */
  __IO uint32_t CTRL1_CLR;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x18 */
  __IO uint32_t CTRL1_TOG;                         /**< AHB to APBH Bridge Control and Status Register 1, offset: 0x1C */
  __IO uint32_t CTRL2;                             /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x20 */
  __IO uint32_t CTRL2_SET;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x24 */
  __IO uint32_t CTRL2_CLR;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x28 */
  __IO uint32_t CTRL2_TOG;                         /**< AHB to APBH Bridge Control and Status Register 2, offset: 0x2C */
  __IO uint32_t CHANNEL_CTRL;                      /**< AHB to APBH Bridge Channel Register, offset: 0x30 */
  __IO uint32_t CHANNEL_CTRL_SET;                  /**< AHB to APBH Bridge Channel Register, offset: 0x34 */
  __IO uint32_t CHANNEL_CTRL_CLR;                  /**< AHB to APBH Bridge Channel Register, offset: 0x38 */
  __IO uint32_t CHANNEL_CTRL_TOG;                  /**< AHB to APBH Bridge Channel Register, offset: 0x3C */
       uint32_t DEVSEL;                            /**< AHB to APBH DMA Device Assignment Register, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DMA_BURST_SIZE;                    /**< AHB to APBH DMA burst size, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DEBUGr;                            /**< AHB to APBH DMA Debug Register, offset: 0x60, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
       uint8_t RESERVED_2[156];
  struct {                                         /* offset: 0x100, array step: 0x70 */
    __I  uint32_t CH_CURCMDAR;                       /**< APBH DMA Channel n Current Command Address Register, array offset: 0x100, array step: 0x70 */
         uint8_t RESERVED_0[12];
    __IO uint32_t CH_NXTCMDAR;                       /**< APBH DMA Channel n Next Command Address Register, array offset: 0x110, array step: 0x70 */
         uint8_t RESERVED_1[12];
    __I  uint32_t CH_CMD;                            /**< APBH DMA Channel n Command Register, array offset: 0x120, array step: 0x70 */
         uint8_t RESERVED_2[12];
    __I  uint32_t CH_BAR;                            /**< APBH DMA Channel n Buffer Address Register, array offset: 0x130, array step: 0x70 */
         uint8_t RESERVED_3[12];
    __IO uint32_t CH_SEMA;                           /**< APBH DMA Channel n Semaphore Register, array offset: 0x140, array step: 0x70 */
         uint8_t RESERVED_4[12];
    __I  uint32_t CH_DEBUG1;                         /**< AHB to APBH DMA Channel n Debug Information, array offset: 0x150, array step: 0x70 */
         uint8_t RESERVED_5[12];
    __I  uint32_t CH_DEBUG2;                         /**< AHB to APBH DMA Channel n Debug Information, array offset: 0x160, array step: 0x70 */
         uint8_t RESERVED_6[12];
  } CH_CFGn[APBH_CH_CFGn_COUNT];
  __I  uint32_t VERSION;                           /**< APBH Bridge Version Register, offset: 0x800 */
} APBH_Type;

/* ----------------------------------------------------------------------------
   -- APBH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup APBH_Register_Masks APBH Register Masks
 * @{
 */

/*! @name CTRL0 - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_CLKGATE_CHANNEL_MASK          (0xFFFFU)
#define APBH_CTRL0_CLKGATE_CHANNEL_SHIFT         (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_CLKGATE_CHANNEL(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_RSVD0_MASK                    (0xFFF0000U)
#define APBH_CTRL0_RSVD0_SHIFT                   (16U)
#define APBH_CTRL0_RSVD0(x)                      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_RSVD0_SHIFT)) & APBH_CTRL0_RSVD0_MASK)

#define APBH_CTRL0_APB_BURST_EN_MASK             (0x10000000U)
#define APBH_CTRL0_APB_BURST_EN_SHIFT            (28U)
#define APBH_CTRL0_APB_BURST_EN(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_APB_BURST_EN_SHIFT)) & APBH_CTRL0_APB_BURST_EN_MASK)

#define APBH_CTRL0_AHB_BURST8_EN_MASK            (0x20000000U)
#define APBH_CTRL0_AHB_BURST8_EN_SHIFT           (29U)
#define APBH_CTRL0_AHB_BURST8_EN(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_CLKGATE_MASK                  (0x40000000U)
#define APBH_CTRL0_CLKGATE_SHIFT                 (30U)
#define APBH_CTRL0_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLKGATE_SHIFT)) & APBH_CTRL0_CLKGATE_MASK)

#define APBH_CTRL0_SFTRST_MASK                   (0x80000000U)
#define APBH_CTRL0_SFTRST_SHIFT                  (31U)
#define APBH_CTRL0_SFTRST(x)                     (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SFTRST_SHIFT)) & APBH_CTRL0_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_SET - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_SET_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_SET_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_SET_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_SET_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_SET_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_SET_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_SET_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_RSVD0_SHIFT)) & APBH_CTRL0_SET_RSVD0_MASK)

#define APBH_CTRL0_SET_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_SET_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_SET_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_APB_BURST_EN_SHIFT)) & APBH_CTRL0_SET_APB_BURST_EN_MASK)

#define APBH_CTRL0_SET_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_SET_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_SET_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_SET_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_SET_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_SET_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_SET_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_CLKGATE_SHIFT)) & APBH_CTRL0_SET_CLKGATE_MASK)

#define APBH_CTRL0_SET_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_SET_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_SET_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_SET_SFTRST_SHIFT)) & APBH_CTRL0_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_CLR - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_CLR_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_CLR_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_CLR_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_CLR_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_CLR_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_CLR_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_CLR_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_RSVD0_SHIFT)) & APBH_CTRL0_CLR_RSVD0_MASK)

#define APBH_CTRL0_CLR_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_CLR_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_CLR_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_APB_BURST_EN_SHIFT)) & APBH_CTRL0_CLR_APB_BURST_EN_MASK)

#define APBH_CTRL0_CLR_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_CLR_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_CLR_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_CLR_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_CLR_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_CLR_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_CLR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_CLKGATE_SHIFT)) & APBH_CTRL0_CLR_CLKGATE_MASK)

#define APBH_CTRL0_CLR_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_CLR_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_CLR_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_CLR_SFTRST_SHIFT)) & APBH_CTRL0_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL0_TOG - AHB to APBH Bridge Control and Status Register 0 */
/*! @{ */

#define APBH_CTRL0_TOG_CLKGATE_CHANNEL_MASK      (0xFFFFU)
#define APBH_CTRL0_TOG_CLKGATE_CHANNEL_SHIFT     (0U)
/*! CLKGATE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CTRL0_TOG_CLKGATE_CHANNEL(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_CLKGATE_CHANNEL_SHIFT)) & APBH_CTRL0_TOG_CLKGATE_CHANNEL_MASK)

#define APBH_CTRL0_TOG_RSVD0_MASK                (0xFFF0000U)
#define APBH_CTRL0_TOG_RSVD0_SHIFT               (16U)
#define APBH_CTRL0_TOG_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_RSVD0_SHIFT)) & APBH_CTRL0_TOG_RSVD0_MASK)

#define APBH_CTRL0_TOG_APB_BURST_EN_MASK         (0x10000000U)
#define APBH_CTRL0_TOG_APB_BURST_EN_SHIFT        (28U)
#define APBH_CTRL0_TOG_APB_BURST_EN(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_APB_BURST_EN_SHIFT)) & APBH_CTRL0_TOG_APB_BURST_EN_MASK)

#define APBH_CTRL0_TOG_AHB_BURST8_EN_MASK        (0x20000000U)
#define APBH_CTRL0_TOG_AHB_BURST8_EN_SHIFT       (29U)
#define APBH_CTRL0_TOG_AHB_BURST8_EN(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_AHB_BURST8_EN_SHIFT)) & APBH_CTRL0_TOG_AHB_BURST8_EN_MASK)

#define APBH_CTRL0_TOG_CLKGATE_MASK              (0x40000000U)
#define APBH_CTRL0_TOG_CLKGATE_SHIFT             (30U)
#define APBH_CTRL0_TOG_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_CLKGATE_SHIFT)) & APBH_CTRL0_TOG_CLKGATE_MASK)

#define APBH_CTRL0_TOG_SFTRST_MASK               (0x80000000U)
#define APBH_CTRL0_TOG_SFTRST_SHIFT              (31U)
#define APBH_CTRL0_TOG_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CTRL0_TOG_SFTRST_SHIFT)) & APBH_CTRL0_TOG_SFTRST_MASK)
/*! @} */

/*! @name CTRL1 - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_MASK         (0x1U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_SHIFT        (0U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_MASK         (0x2U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_SHIFT        (1U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_MASK         (0x4U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_SHIFT        (2U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_MASK         (0x8U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_SHIFT        (3U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_MASK         (0x10U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_SHIFT        (4U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_MASK         (0x20U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_SHIFT        (5U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_MASK         (0x40U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_SHIFT        (6U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_MASK         (0x80U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_SHIFT        (7U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_MASK         (0x100U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_SHIFT        (8U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_MASK         (0x200U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_SHIFT        (9U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_MASK        (0x400U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_SHIFT       (10U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_MASK        (0x800U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_SHIFT       (11U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_MASK        (0x1000U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_SHIFT       (12U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_MASK        (0x2000U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_SHIFT       (13U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_MASK        (0x4000U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_SHIFT       (14U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_MASK        (0x8000U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_SHIFT       (15U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_MASK      (0x10000U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_SHIFT     (16U)
#define APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_MASK      (0x20000U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_SHIFT     (17U)
#define APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_MASK      (0x40000U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_SHIFT     (18U)
#define APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_MASK      (0x80000U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_SHIFT     (19U)
#define APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_MASK      (0x100000U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_SHIFT     (20U)
#define APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_MASK      (0x200000U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_SHIFT     (21U)
#define APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_MASK      (0x400000U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_SHIFT     (22U)
#define APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_MASK      (0x800000U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_SHIFT     (23U)
#define APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_MASK      (0x1000000U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_SHIFT     (24U)
#define APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_MASK      (0x2000000U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_SHIFT     (25U)
#define APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_MASK     (0x4000000U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_SHIFT    (26U)
#define APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_MASK     (0x8000000U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_SHIFT    (27U)
#define APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_MASK     (0x10000000U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_SHIFT    (28U)
#define APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_MASK     (0x20000000U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_SHIFT    (29U)
#define APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_MASK     (0x40000000U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_SHIFT    (30U)
#define APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_MASK     (0x80000000U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_SHIFT    (31U)
#define APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_SET - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_SET_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_CLR - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_CLR_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL1_TOG - AHB to APBH Bridge Control and Status Register 1 */
/*! @{ */

#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_MASK     (0x1U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_SHIFT    (0U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_MASK     (0x2U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_SHIFT    (1U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_MASK     (0x4U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_SHIFT    (2U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_MASK     (0x8U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_SHIFT    (3U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_MASK     (0x10U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_SHIFT    (4U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_MASK     (0x20U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_SHIFT    (5U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_MASK     (0x40U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_SHIFT    (6U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_MASK     (0x80U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_SHIFT    (7U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_MASK     (0x100U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_SHIFT    (8U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_MASK     (0x200U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_SHIFT    (9U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_MASK    (0x400U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_SHIFT   (10U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_MASK    (0x800U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_SHIFT   (11U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_MASK    (0x1000U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_SHIFT   (12U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_MASK    (0x2000U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_SHIFT   (13U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_MASK    (0x4000U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_SHIFT   (14U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_MASK    (0x8000U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_SHIFT   (15U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_SHIFT)) & APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_MASK)

#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_MASK  (0x10000U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_SHIFT (16U)
#define APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH0_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_MASK  (0x20000U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_SHIFT (17U)
#define APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH1_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_MASK  (0x40000U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_SHIFT (18U)
#define APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH2_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_MASK  (0x80000U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_SHIFT (19U)
#define APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH3_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_MASK  (0x100000U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_SHIFT (20U)
#define APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH4_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_MASK  (0x200000U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_SHIFT (21U)
#define APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH5_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_MASK  (0x400000U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_SHIFT (22U)
#define APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH6_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_MASK  (0x800000U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_SHIFT (23U)
#define APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH7_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_MASK  (0x1000000U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_SHIFT (24U)
#define APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH8_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_MASK  (0x2000000U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_SHIFT (25U)
#define APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN(x)    (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH9_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_MASK (0x4000000U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_SHIFT (26U)
#define APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH10_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_MASK (0x8000000U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_SHIFT (27U)
#define APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH11_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_MASK (0x10000000U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_SHIFT (28U)
#define APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH12_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_MASK (0x20000000U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_SHIFT (29U)
#define APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH13_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_MASK (0x40000000U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_SHIFT (30U)
#define APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH14_CMDCMPLT_IRQ_EN_MASK)

#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_MASK (0x80000000U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_SHIFT (31U)
#define APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_SHIFT)) & APBH_CTRL1_TOG_CH15_CMDCMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name CTRL2 - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_CH0_ERROR_IRQ_MASK            (0x1U)
#define APBH_CTRL2_CH0_ERROR_IRQ_SHIFT           (0U)
#define APBH_CTRL2_CH0_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH1_ERROR_IRQ_MASK            (0x2U)
#define APBH_CTRL2_CH1_ERROR_IRQ_SHIFT           (1U)
#define APBH_CTRL2_CH1_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH2_ERROR_IRQ_MASK            (0x4U)
#define APBH_CTRL2_CH2_ERROR_IRQ_SHIFT           (2U)
#define APBH_CTRL2_CH2_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH3_ERROR_IRQ_MASK            (0x8U)
#define APBH_CTRL2_CH3_ERROR_IRQ_SHIFT           (3U)
#define APBH_CTRL2_CH3_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH4_ERROR_IRQ_MASK            (0x10U)
#define APBH_CTRL2_CH4_ERROR_IRQ_SHIFT           (4U)
#define APBH_CTRL2_CH4_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH5_ERROR_IRQ_MASK            (0x20U)
#define APBH_CTRL2_CH5_ERROR_IRQ_SHIFT           (5U)
#define APBH_CTRL2_CH5_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH6_ERROR_IRQ_MASK            (0x40U)
#define APBH_CTRL2_CH6_ERROR_IRQ_SHIFT           (6U)
#define APBH_CTRL2_CH6_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH7_ERROR_IRQ_MASK            (0x80U)
#define APBH_CTRL2_CH7_ERROR_IRQ_SHIFT           (7U)
#define APBH_CTRL2_CH7_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH8_ERROR_IRQ_MASK            (0x100U)
#define APBH_CTRL2_CH8_ERROR_IRQ_SHIFT           (8U)
#define APBH_CTRL2_CH8_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH9_ERROR_IRQ_MASK            (0x200U)
#define APBH_CTRL2_CH9_ERROR_IRQ_SHIFT           (9U)
#define APBH_CTRL2_CH9_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH10_ERROR_IRQ_MASK           (0x400U)
#define APBH_CTRL2_CH10_ERROR_IRQ_SHIFT          (10U)
#define APBH_CTRL2_CH10_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH11_ERROR_IRQ_MASK           (0x800U)
#define APBH_CTRL2_CH11_ERROR_IRQ_SHIFT          (11U)
#define APBH_CTRL2_CH11_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH12_ERROR_IRQ_MASK           (0x1000U)
#define APBH_CTRL2_CH12_ERROR_IRQ_SHIFT          (12U)
#define APBH_CTRL2_CH12_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH13_ERROR_IRQ_MASK           (0x2000U)
#define APBH_CTRL2_CH13_ERROR_IRQ_SHIFT          (13U)
#define APBH_CTRL2_CH13_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH14_ERROR_IRQ_MASK           (0x4000U)
#define APBH_CTRL2_CH14_ERROR_IRQ_SHIFT          (14U)
#define APBH_CTRL2_CH14_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH15_ERROR_IRQ_MASK           (0x8000U)
#define APBH_CTRL2_CH15_ERROR_IRQ_SHIFT          (15U)
#define APBH_CTRL2_CH15_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_CH0_ERROR_STATUS_MASK         (0x10000U)
#define APBH_CTRL2_CH0_ERROR_STATUS_SHIFT        (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH0_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH1_ERROR_STATUS_MASK         (0x20000U)
#define APBH_CTRL2_CH1_ERROR_STATUS_SHIFT        (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH1_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH2_ERROR_STATUS_MASK         (0x40000U)
#define APBH_CTRL2_CH2_ERROR_STATUS_SHIFT        (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH2_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH3_ERROR_STATUS_MASK         (0x80000U)
#define APBH_CTRL2_CH3_ERROR_STATUS_SHIFT        (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH3_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH4_ERROR_STATUS_MASK         (0x100000U)
#define APBH_CTRL2_CH4_ERROR_STATUS_SHIFT        (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH4_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH5_ERROR_STATUS_MASK         (0x200000U)
#define APBH_CTRL2_CH5_ERROR_STATUS_SHIFT        (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH5_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH6_ERROR_STATUS_MASK         (0x400000U)
#define APBH_CTRL2_CH6_ERROR_STATUS_SHIFT        (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH6_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH7_ERROR_STATUS_MASK         (0x800000U)
#define APBH_CTRL2_CH7_ERROR_STATUS_SHIFT        (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH7_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH8_ERROR_STATUS_MASK         (0x1000000U)
#define APBH_CTRL2_CH8_ERROR_STATUS_SHIFT        (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH8_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH9_ERROR_STATUS_MASK         (0x2000000U)
#define APBH_CTRL2_CH9_ERROR_STATUS_SHIFT        (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH9_ERROR_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH10_ERROR_STATUS_MASK        (0x4000000U)
#define APBH_CTRL2_CH10_ERROR_STATUS_SHIFT       (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH10_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH11_ERROR_STATUS_MASK        (0x8000000U)
#define APBH_CTRL2_CH11_ERROR_STATUS_SHIFT       (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH11_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH12_ERROR_STATUS_MASK        (0x10000000U)
#define APBH_CTRL2_CH12_ERROR_STATUS_SHIFT       (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH12_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH13_ERROR_STATUS_MASK        (0x20000000U)
#define APBH_CTRL2_CH13_ERROR_STATUS_SHIFT       (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH13_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH14_ERROR_STATUS_MASK        (0x40000000U)
#define APBH_CTRL2_CH14_ERROR_STATUS_SHIFT       (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH14_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_CH15_ERROR_STATUS_MASK        (0x80000000U)
#define APBH_CTRL2_CH15_ERROR_STATUS_SHIFT       (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CH15_ERROR_STATUS(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_SET - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_SET_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_SET_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_SET_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_SET_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_SET_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_SET_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_SET_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_SET_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_SET_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_SET_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_SET_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_SET_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_SET_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_SET_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_SET_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_SET_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_SET_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_SET_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_SET_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_SET_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_SET_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_SET_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_SET_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_SET_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_SET_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_SET_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_SET_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_SET_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_SET_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_SET_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_SET_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_SET_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_SET_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_SET_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_SET_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_SET_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_SET_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_SET_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_SET_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_SET_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_SET_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_SET_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_SET_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_SET_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_SET_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_SET_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_SET_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_SET_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_SET_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_SET_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_SET_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_SET_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_SET_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_SET_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_SET_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_CLR - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_CLR_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_CLR_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_CLR_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_CLR_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_CLR_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_CLR_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_CLR_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_CLR_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_CLR_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_CLR_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_CLR_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_CLR_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_CLR_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_CLR_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_CLR_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_CLR_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_CLR_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_CLR_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_CLR_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_CLR_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_CLR_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_CLR_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_CLR_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_CLR_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_CLR_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_CLR_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_CLR_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_CLR_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_CLR_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_CLR_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_CLR_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_CLR_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_CLR_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_CLR_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_CLR_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_CLR_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_CLR_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_CLR_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_CLR_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_CLR_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_CLR_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_CLR_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_CLR_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_CLR_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_CLR_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_CLR_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_CLR_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_CLR_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_CLR_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_CLR_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_CLR_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_CLR_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_CLR_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_CLR_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_CLR_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CTRL2_TOG - AHB to APBH Bridge Control and Status Register 2 */
/*! @{ */

#define APBH_CTRL2_TOG_CH0_ERROR_IRQ_MASK        (0x1U)
#define APBH_CTRL2_TOG_CH0_ERROR_IRQ_SHIFT       (0U)
#define APBH_CTRL2_TOG_CH0_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH0_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH0_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH1_ERROR_IRQ_MASK        (0x2U)
#define APBH_CTRL2_TOG_CH1_ERROR_IRQ_SHIFT       (1U)
#define APBH_CTRL2_TOG_CH1_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH1_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH1_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH2_ERROR_IRQ_MASK        (0x4U)
#define APBH_CTRL2_TOG_CH2_ERROR_IRQ_SHIFT       (2U)
#define APBH_CTRL2_TOG_CH2_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH2_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH2_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH3_ERROR_IRQ_MASK        (0x8U)
#define APBH_CTRL2_TOG_CH3_ERROR_IRQ_SHIFT       (3U)
#define APBH_CTRL2_TOG_CH3_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH3_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH3_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH4_ERROR_IRQ_MASK        (0x10U)
#define APBH_CTRL2_TOG_CH4_ERROR_IRQ_SHIFT       (4U)
#define APBH_CTRL2_TOG_CH4_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH4_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH4_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH5_ERROR_IRQ_MASK        (0x20U)
#define APBH_CTRL2_TOG_CH5_ERROR_IRQ_SHIFT       (5U)
#define APBH_CTRL2_TOG_CH5_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH5_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH5_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH6_ERROR_IRQ_MASK        (0x40U)
#define APBH_CTRL2_TOG_CH6_ERROR_IRQ_SHIFT       (6U)
#define APBH_CTRL2_TOG_CH6_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH6_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH6_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH7_ERROR_IRQ_MASK        (0x80U)
#define APBH_CTRL2_TOG_CH7_ERROR_IRQ_SHIFT       (7U)
#define APBH_CTRL2_TOG_CH7_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH7_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH7_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH8_ERROR_IRQ_MASK        (0x100U)
#define APBH_CTRL2_TOG_CH8_ERROR_IRQ_SHIFT       (8U)
#define APBH_CTRL2_TOG_CH8_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH8_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH8_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH9_ERROR_IRQ_MASK        (0x200U)
#define APBH_CTRL2_TOG_CH9_ERROR_IRQ_SHIFT       (9U)
#define APBH_CTRL2_TOG_CH9_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH9_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH9_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH10_ERROR_IRQ_MASK       (0x400U)
#define APBH_CTRL2_TOG_CH10_ERROR_IRQ_SHIFT      (10U)
#define APBH_CTRL2_TOG_CH10_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH10_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH10_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH11_ERROR_IRQ_MASK       (0x800U)
#define APBH_CTRL2_TOG_CH11_ERROR_IRQ_SHIFT      (11U)
#define APBH_CTRL2_TOG_CH11_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH11_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH11_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH12_ERROR_IRQ_MASK       (0x1000U)
#define APBH_CTRL2_TOG_CH12_ERROR_IRQ_SHIFT      (12U)
#define APBH_CTRL2_TOG_CH12_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH12_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH12_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH13_ERROR_IRQ_MASK       (0x2000U)
#define APBH_CTRL2_TOG_CH13_ERROR_IRQ_SHIFT      (13U)
#define APBH_CTRL2_TOG_CH13_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH13_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH13_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH14_ERROR_IRQ_MASK       (0x4000U)
#define APBH_CTRL2_TOG_CH14_ERROR_IRQ_SHIFT      (14U)
#define APBH_CTRL2_TOG_CH14_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH14_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH14_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH15_ERROR_IRQ_MASK       (0x8000U)
#define APBH_CTRL2_TOG_CH15_ERROR_IRQ_SHIFT      (15U)
#define APBH_CTRL2_TOG_CH15_ERROR_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH15_ERROR_IRQ_SHIFT)) & APBH_CTRL2_TOG_CH15_ERROR_IRQ_MASK)

#define APBH_CTRL2_TOG_CH0_ERROR_STATUS_MASK     (0x10000U)
#define APBH_CTRL2_TOG_CH0_ERROR_STATUS_SHIFT    (16U)
/*! CH0_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH0_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH0_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH0_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH1_ERROR_STATUS_MASK     (0x20000U)
#define APBH_CTRL2_TOG_CH1_ERROR_STATUS_SHIFT    (17U)
/*! CH1_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH1_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH1_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH1_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH2_ERROR_STATUS_MASK     (0x40000U)
#define APBH_CTRL2_TOG_CH2_ERROR_STATUS_SHIFT    (18U)
/*! CH2_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH2_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH2_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH2_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH3_ERROR_STATUS_MASK     (0x80000U)
#define APBH_CTRL2_TOG_CH3_ERROR_STATUS_SHIFT    (19U)
/*! CH3_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH3_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH3_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH3_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH4_ERROR_STATUS_MASK     (0x100000U)
#define APBH_CTRL2_TOG_CH4_ERROR_STATUS_SHIFT    (20U)
/*! CH4_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH4_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH4_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH4_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH5_ERROR_STATUS_MASK     (0x200000U)
#define APBH_CTRL2_TOG_CH5_ERROR_STATUS_SHIFT    (21U)
/*! CH5_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH5_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH5_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH5_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH6_ERROR_STATUS_MASK     (0x400000U)
#define APBH_CTRL2_TOG_CH6_ERROR_STATUS_SHIFT    (22U)
/*! CH6_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH6_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH6_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH6_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH7_ERROR_STATUS_MASK     (0x800000U)
#define APBH_CTRL2_TOG_CH7_ERROR_STATUS_SHIFT    (23U)
/*! CH7_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH7_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH7_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH7_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH8_ERROR_STATUS_MASK     (0x1000000U)
#define APBH_CTRL2_TOG_CH8_ERROR_STATUS_SHIFT    (24U)
/*! CH8_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH8_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH8_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH8_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH9_ERROR_STATUS_MASK     (0x2000000U)
#define APBH_CTRL2_TOG_CH9_ERROR_STATUS_SHIFT    (25U)
/*! CH9_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH9_ERROR_STATUS(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH9_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH9_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH10_ERROR_STATUS_MASK    (0x4000000U)
#define APBH_CTRL2_TOG_CH10_ERROR_STATUS_SHIFT   (26U)
/*! CH10_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH10_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH10_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH10_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH11_ERROR_STATUS_MASK    (0x8000000U)
#define APBH_CTRL2_TOG_CH11_ERROR_STATUS_SHIFT   (27U)
/*! CH11_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH11_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH11_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH11_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH12_ERROR_STATUS_MASK    (0x10000000U)
#define APBH_CTRL2_TOG_CH12_ERROR_STATUS_SHIFT   (28U)
/*! CH12_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH12_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH12_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH12_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH13_ERROR_STATUS_MASK    (0x20000000U)
#define APBH_CTRL2_TOG_CH13_ERROR_STATUS_SHIFT   (29U)
/*! CH13_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH13_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH13_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH13_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH14_ERROR_STATUS_MASK    (0x40000000U)
#define APBH_CTRL2_TOG_CH14_ERROR_STATUS_SHIFT   (30U)
/*! CH14_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH14_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH14_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH14_ERROR_STATUS_MASK)

#define APBH_CTRL2_TOG_CH15_ERROR_STATUS_MASK    (0x80000000U)
#define APBH_CTRL2_TOG_CH15_ERROR_STATUS_SHIFT   (31U)
/*! CH15_ERROR_STATUS
 *  0b0..An early termination from the device causes error IRQ.
 *  0b1..An AHB bus error causes error IRQ.
 */
#define APBH_CTRL2_TOG_CH15_ERROR_STATUS(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CTRL2_TOG_CH15_ERROR_STATUS_SHIFT)) & APBH_CTRL2_TOG_CH15_ERROR_STATUS_MASK)
/*! @} */

/*! @name CHANNEL_CTRL - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL_MASK    (0xFFFFU)
#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL_SHIFT   (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_FREEZE_CHANNEL(x)      (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_RESET_CHANNEL_MASK     (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_RESET_CHANNEL_SHIFT    (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_RESET_CHANNEL(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_SET - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_SET_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_SET_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_SET_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_CLR - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_CLR_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_CLR_RESET_CHANNEL_MASK)
/*! @} */

/*! @name CHANNEL_CTRL_TOG - AHB to APBH Bridge Channel Register */
/*! @{ */

#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_MASK (0xFFFFU)
#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_SHIFT (0U)
/*! FREEZE_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL(x)  (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_TOG_FREEZE_CHANNEL_MASK)

#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_MASK (0xFFFF0000U)
#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_SHIFT (16U)
/*! RESET_CHANNEL
 *  0b0000000000000001..NAND0
 *  0b0000000000000010..NAND1
 *  0b0000000000000100..NAND2
 *  0b0000000000001000..NAND3
 *  0b0000000000010000..NAND4
 *  0b0000000000100000..NAND5
 *  0b0000000001000000..NAND6
 *  0b0000000010000000..NAND7
 *  0b0000000100000000..SSP
 */
#define APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL(x)   (((uint32_t)(((uint32_t)(x)) << APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_SHIFT)) & APBH_CHANNEL_CTRL_TOG_RESET_CHANNEL_MASK)
/*! @} */

/*! @name DMA_BURST_SIZE - AHB to APBH DMA burst size */
/*! @{ */

#define APBH_DMA_BURST_SIZE_CH0_MASK             (0x3U)
#define APBH_DMA_BURST_SIZE_CH0_SHIFT            (0U)
#define APBH_DMA_BURST_SIZE_CH0(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH0_SHIFT)) & APBH_DMA_BURST_SIZE_CH0_MASK)

#define APBH_DMA_BURST_SIZE_CH1_MASK             (0xCU)
#define APBH_DMA_BURST_SIZE_CH1_SHIFT            (2U)
#define APBH_DMA_BURST_SIZE_CH1(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH1_SHIFT)) & APBH_DMA_BURST_SIZE_CH1_MASK)

#define APBH_DMA_BURST_SIZE_CH2_MASK             (0x30U)
#define APBH_DMA_BURST_SIZE_CH2_SHIFT            (4U)
#define APBH_DMA_BURST_SIZE_CH2(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH2_SHIFT)) & APBH_DMA_BURST_SIZE_CH2_MASK)

#define APBH_DMA_BURST_SIZE_CH3_MASK             (0xC0U)
#define APBH_DMA_BURST_SIZE_CH3_SHIFT            (6U)
#define APBH_DMA_BURST_SIZE_CH3(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH3_SHIFT)) & APBH_DMA_BURST_SIZE_CH3_MASK)

#define APBH_DMA_BURST_SIZE_CH4_MASK             (0x300U)
#define APBH_DMA_BURST_SIZE_CH4_SHIFT            (8U)
#define APBH_DMA_BURST_SIZE_CH4(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH4_SHIFT)) & APBH_DMA_BURST_SIZE_CH4_MASK)

#define APBH_DMA_BURST_SIZE_CH5_MASK             (0xC00U)
#define APBH_DMA_BURST_SIZE_CH5_SHIFT            (10U)
#define APBH_DMA_BURST_SIZE_CH5(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH5_SHIFT)) & APBH_DMA_BURST_SIZE_CH5_MASK)

#define APBH_DMA_BURST_SIZE_CH6_MASK             (0x3000U)
#define APBH_DMA_BURST_SIZE_CH6_SHIFT            (12U)
#define APBH_DMA_BURST_SIZE_CH6(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH6_SHIFT)) & APBH_DMA_BURST_SIZE_CH6_MASK)

#define APBH_DMA_BURST_SIZE_CH7_MASK             (0xC000U)
#define APBH_DMA_BURST_SIZE_CH7_SHIFT            (14U)
#define APBH_DMA_BURST_SIZE_CH7(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH7_SHIFT)) & APBH_DMA_BURST_SIZE_CH7_MASK)

#define APBH_DMA_BURST_SIZE_CH8_MASK             (0x30000U)
#define APBH_DMA_BURST_SIZE_CH8_SHIFT            (16U)
/*! CH8
 *  0b00..BURST0
 *  0b01..BURST4
 *  0b10..BURST8
 */
#define APBH_DMA_BURST_SIZE_CH8(x)               (((uint32_t)(((uint32_t)(x)) << APBH_DMA_BURST_SIZE_CH8_SHIFT)) & APBH_DMA_BURST_SIZE_CH8_MASK)
/*! @} */

/*! @name DEBUG - AHB to APBH DMA Debug Register */
/*! @{ */

#define APBH_DEBUG_GPMI_ONE_FIFO_MASK            (0x1U)
#define APBH_DEBUG_GPMI_ONE_FIFO_SHIFT           (0U)
#define APBH_DEBUG_GPMI_ONE_FIFO(x)              (((uint32_t)(((uint32_t)(x)) << APBH_DEBUG_GPMI_ONE_FIFO_SHIFT)) & APBH_DEBUG_GPMI_ONE_FIFO_MASK)
/*! @} */

/*! @name CH_CURCMDAR - APBH DMA Channel n Current Command Address Register */
/*! @{ */

#define APBH_CH_CURCMDAR_CMD_ADDR_MASK           (0xFFFFFFFFU)
#define APBH_CH_CURCMDAR_CMD_ADDR_SHIFT          (0U)
#define APBH_CH_CURCMDAR_CMD_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH_CURCMDAR_CMD_ADDR_SHIFT)) & APBH_CH_CURCMDAR_CMD_ADDR_MASK)
/*! @} */

/* The count of APBH_CH_CURCMDAR */
#define APBH_CH_CURCMDAR_COUNT                   (16U)

/*! @name CH_NXTCMDAR - APBH DMA Channel n Next Command Address Register */
/*! @{ */

#define APBH_CH_NXTCMDAR_CMD_ADDR_MASK           (0xFFFFFFFFU)
#define APBH_CH_NXTCMDAR_CMD_ADDR_SHIFT          (0U)
#define APBH_CH_NXTCMDAR_CMD_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << APBH_CH_NXTCMDAR_CMD_ADDR_SHIFT)) & APBH_CH_NXTCMDAR_CMD_ADDR_MASK)
/*! @} */

/* The count of APBH_CH_NXTCMDAR */
#define APBH_CH_NXTCMDAR_COUNT                   (16U)

/*! @name CH_CMD - APBH DMA Channel n Command Register */
/*! @{ */

#define APBH_CH_CMD_COMMAND_MASK                 (0x3U)
#define APBH_CH_CMD_COMMAND_SHIFT                (0U)
/*! COMMAND
 *  0b00..Perform any requested PIO word transfers but terminate command before any DMA transfer.
 *  0b01..Perform any requested PIO word transfers and then perform a DMA transfer from the peripheral for the specified number of bytes.
 *  0b10..Perform any requested PIO word transfers and then perform a DMA transfer to the peripheral for the specified number of bytes.
 *  0b11..Perform any requested PIO word transfers and then perform a conditional branch to the next chained
 *        device. Follow the NEXCMD_ADDR pointer if the perpheral sense is true. Follow the BUFFER_ADDRESS as a chain
 *        pointer if the peripheral sense line is false.
 */
#define APBH_CH_CMD_COMMAND(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_COMMAND_SHIFT)) & APBH_CH_CMD_COMMAND_MASK)

#define APBH_CH_CMD_CHAIN_MASK                   (0x4U)
#define APBH_CH_CMD_CHAIN_SHIFT                  (2U)
#define APBH_CH_CMD_CHAIN(x)                     (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_CHAIN_SHIFT)) & APBH_CH_CMD_CHAIN_MASK)

#define APBH_CH_CMD_IRQONCMPLT_MASK              (0x8U)
#define APBH_CH_CMD_IRQONCMPLT_SHIFT             (3U)
#define APBH_CH_CMD_IRQONCMPLT(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_IRQONCMPLT_SHIFT)) & APBH_CH_CMD_IRQONCMPLT_MASK)

#define APBH_CH_CMD_NANDLOCK_MASK                (0x10U)
#define APBH_CH_CMD_NANDLOCK_SHIFT               (4U)
#define APBH_CH_CMD_NANDLOCK(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_NANDLOCK_SHIFT)) & APBH_CH_CMD_NANDLOCK_MASK)

#define APBH_CH_CMD_NANDWAIT4READY_MASK          (0x20U)
#define APBH_CH_CMD_NANDWAIT4READY_SHIFT         (5U)
#define APBH_CH_CMD_NANDWAIT4READY(x)            (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_NANDWAIT4READY_SHIFT)) & APBH_CH_CMD_NANDWAIT4READY_MASK)

#define APBH_CH_CMD_SEMAPHORE_MASK               (0x40U)
#define APBH_CH_CMD_SEMAPHORE_SHIFT              (6U)
#define APBH_CH_CMD_SEMAPHORE(x)                 (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_SEMAPHORE_SHIFT)) & APBH_CH_CMD_SEMAPHORE_MASK)

#define APBH_CH_CMD_WAIT4ENDCMD_MASK             (0x80U)
#define APBH_CH_CMD_WAIT4ENDCMD_SHIFT            (7U)
#define APBH_CH_CMD_WAIT4ENDCMD(x)               (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_WAIT4ENDCMD_SHIFT)) & APBH_CH_CMD_WAIT4ENDCMD_MASK)

#define APBH_CH_CMD_HALTONTERMINATE_MASK         (0x100U)
#define APBH_CH_CMD_HALTONTERMINATE_SHIFT        (8U)
#define APBH_CH_CMD_HALTONTERMINATE(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_HALTONTERMINATE_SHIFT)) & APBH_CH_CMD_HALTONTERMINATE_MASK)

#define APBH_CH_CMD_CMDWORDS_MASK                (0xF000U)
#define APBH_CH_CMD_CMDWORDS_SHIFT               (12U)
#define APBH_CH_CMD_CMDWORDS(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_CMDWORDS_SHIFT)) & APBH_CH_CMD_CMDWORDS_MASK)

#define APBH_CH_CMD_XFER_COUNT_MASK              (0xFFFF0000U)
#define APBH_CH_CMD_XFER_COUNT_SHIFT             (16U)
#define APBH_CH_CMD_XFER_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << APBH_CH_CMD_XFER_COUNT_SHIFT)) & APBH_CH_CMD_XFER_COUNT_MASK)
/*! @} */

/* The count of APBH_CH_CMD */
#define APBH_CH_CMD_COUNT                        (16U)

/*! @name CH_BAR - APBH DMA Channel n Buffer Address Register */
/*! @{ */

#define APBH_CH_BAR_ADDRESS_MASK                 (0xFFFFFFFFU)
#define APBH_CH_BAR_ADDRESS_SHIFT                (0U)
#define APBH_CH_BAR_ADDRESS(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH_BAR_ADDRESS_SHIFT)) & APBH_CH_BAR_ADDRESS_MASK)
/*! @} */

/* The count of APBH_CH_BAR */
#define APBH_CH_BAR_COUNT                        (16U)

/*! @name CH_SEMA - APBH DMA Channel n Semaphore Register */
/*! @{ */

#define APBH_CH_SEMA_INCREMENT_SEMA_MASK         (0xFFU)
#define APBH_CH_SEMA_INCREMENT_SEMA_SHIFT        (0U)
#define APBH_CH_SEMA_INCREMENT_SEMA(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH_SEMA_INCREMENT_SEMA_SHIFT)) & APBH_CH_SEMA_INCREMENT_SEMA_MASK)

#define APBH_CH_SEMA_PHORE_MASK                  (0xFF0000U)
#define APBH_CH_SEMA_PHORE_SHIFT                 (16U)
#define APBH_CH_SEMA_PHORE(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH_SEMA_PHORE_SHIFT)) & APBH_CH_SEMA_PHORE_MASK)
/*! @} */

/* The count of APBH_CH_SEMA */
#define APBH_CH_SEMA_COUNT                       (16U)

/*! @name CH_DEBUG1 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH_DEBUG1_STATEMACHINE_MASK         (0x1FU)
#define APBH_CH_DEBUG1_STATEMACHINE_SHIFT        (0U)
/*! STATEMACHINE
 *  0b00000..This is the idle state of the DMA state machine.
 *  0b00001..State in which the DMA is waiting to receive the first word of a command.
 *  0b00010..State in which the DMA is waiting to receive the third word of a command.
 *  0b00011..State in which the DMA is waiting to receive the second word of a command.
 *  0b00100..The state machine processes the descriptor command field in this state and branches accordingly.
 *  0b00101..The state machine waits in this state for the PIO APB cycles to complete.
 *  0b00110..State in which the DMA is waiting to receive the fourth word of a command, or waiting to receive the
 *           PIO words when PIO count is greater than 1.
 *  0b00111..This state determines whether another PIO cycle needs to occur before starting DMA transfers.
 *  0b01000..During a read transfers, the state machine enters this state waiting for the last bytes to be pushed out on the APB.
 *  0b01001..When an AHB read request occurs, the state machine waits in this state for the AHB transfer to complete.
 *  0b01100..During DMA Write transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01101..During DMA Read transfers, the state machine waits in this state until the AHB master arbiter accepts the request from this channel.
 *  0b01110..Upon completion of the DMA transfers, this state checks the value of the Chain bit and branches accordingly.
 *  0b01111..The state machine goes to this state after the DMA transfers are complete, and determines what step to take next.
 *  0b10100..When a terminate signal is set, the state machine enters this state until the current AHB transfer is completed.
 *  0b10101..When the Wait for Command End bit is set, the state machine enters this state until the DMA device indicates that the command is complete.
 *  0b11100..During DMA Write transfers, the state machine waits in this state until the AHB master completes the write to the AHB memory space.
 *  0b11101..If HALTONTERMINATE is set and a terminate signal is set, the state machine enters this state and
 *           effectively halts. A channel reset is required to exit this state
 *  0b11110..If the Chain bit is a 0, the state machine enters this state and effectively halts.
 *  0b11111..When the NAND Wait for Ready bit is set, the state machine enters this state until the GPMI device
 *           indicates that the external device is ready.
 */
#define APBH_CH_DEBUG1_STATEMACHINE(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_STATEMACHINE_SHIFT)) & APBH_CH_DEBUG1_STATEMACHINE_MASK)

#define APBH_CH_DEBUG1_RSVD1_MASK                (0xFFFE0U)
#define APBH_CH_DEBUG1_RSVD1_SHIFT               (5U)
#define APBH_CH_DEBUG1_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_RSVD1_SHIFT)) & APBH_CH_DEBUG1_RSVD1_MASK)

#define APBH_CH_DEBUG1_WR_FIFO_FULL_MASK         (0x100000U)
#define APBH_CH_DEBUG1_WR_FIFO_FULL_SHIFT        (20U)
#define APBH_CH_DEBUG1_WR_FIFO_FULL(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_WR_FIFO_FULL_SHIFT)) & APBH_CH_DEBUG1_WR_FIFO_FULL_MASK)

#define APBH_CH_DEBUG1_WR_FIFO_EMPTY_MASK        (0x200000U)
#define APBH_CH_DEBUG1_WR_FIFO_EMPTY_SHIFT       (21U)
#define APBH_CH_DEBUG1_WR_FIFO_EMPTY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_WR_FIFO_EMPTY_SHIFT)) & APBH_CH_DEBUG1_WR_FIFO_EMPTY_MASK)

#define APBH_CH_DEBUG1_RD_FIFO_FULL_MASK         (0x400000U)
#define APBH_CH_DEBUG1_RD_FIFO_FULL_SHIFT        (22U)
#define APBH_CH_DEBUG1_RD_FIFO_FULL(x)           (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_RD_FIFO_FULL_SHIFT)) & APBH_CH_DEBUG1_RD_FIFO_FULL_MASK)

#define APBH_CH_DEBUG1_RD_FIFO_EMPTY_MASK        (0x800000U)
#define APBH_CH_DEBUG1_RD_FIFO_EMPTY_SHIFT       (23U)
#define APBH_CH_DEBUG1_RD_FIFO_EMPTY(x)          (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_RD_FIFO_EMPTY_SHIFT)) & APBH_CH_DEBUG1_RD_FIFO_EMPTY_MASK)

#define APBH_CH_DEBUG1_NEXTCMDADDRVALID_MASK     (0x1000000U)
#define APBH_CH_DEBUG1_NEXTCMDADDRVALID_SHIFT    (24U)
#define APBH_CH_DEBUG1_NEXTCMDADDRVALID(x)       (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_NEXTCMDADDRVALID_SHIFT)) & APBH_CH_DEBUG1_NEXTCMDADDRVALID_MASK)

#define APBH_CH_DEBUG1_LOCK_MASK                 (0x2000000U)
#define APBH_CH_DEBUG1_LOCK_SHIFT                (25U)
#define APBH_CH_DEBUG1_LOCK(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_LOCK_SHIFT)) & APBH_CH_DEBUG1_LOCK_MASK)

#define APBH_CH_DEBUG1_READY_MASK                (0x4000000U)
#define APBH_CH_DEBUG1_READY_SHIFT               (26U)
#define APBH_CH_DEBUG1_READY(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_READY_SHIFT)) & APBH_CH_DEBUG1_READY_MASK)

#define APBH_CH_DEBUG1_SENSE_MASK                (0x8000000U)
#define APBH_CH_DEBUG1_SENSE_SHIFT               (27U)
#define APBH_CH_DEBUG1_SENSE(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_SENSE_SHIFT)) & APBH_CH_DEBUG1_SENSE_MASK)

#define APBH_CH_DEBUG1_END_MASK                  (0x10000000U)
#define APBH_CH_DEBUG1_END_SHIFT                 (28U)
#define APBH_CH_DEBUG1_END(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_END_SHIFT)) & APBH_CH_DEBUG1_END_MASK)

#define APBH_CH_DEBUG1_KICK_MASK                 (0x20000000U)
#define APBH_CH_DEBUG1_KICK_SHIFT                (29U)
#define APBH_CH_DEBUG1_KICK(x)                   (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_KICK_SHIFT)) & APBH_CH_DEBUG1_KICK_MASK)

#define APBH_CH_DEBUG1_BURST_MASK                (0x40000000U)
#define APBH_CH_DEBUG1_BURST_SHIFT               (30U)
#define APBH_CH_DEBUG1_BURST(x)                  (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_BURST_SHIFT)) & APBH_CH_DEBUG1_BURST_MASK)

#define APBH_CH_DEBUG1_REQ_MASK                  (0x80000000U)
#define APBH_CH_DEBUG1_REQ_SHIFT                 (31U)
#define APBH_CH_DEBUG1_REQ(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG1_REQ_SHIFT)) & APBH_CH_DEBUG1_REQ_MASK)
/*! @} */

/* The count of APBH_CH_DEBUG1 */
#define APBH_CH_DEBUG1_COUNT                     (16U)

/*! @name CH_DEBUG2 - AHB to APBH DMA Channel n Debug Information */
/*! @{ */

#define APBH_CH_DEBUG2_AHB_BYTES_MASK            (0xFFFFU)
#define APBH_CH_DEBUG2_AHB_BYTES_SHIFT           (0U)
#define APBH_CH_DEBUG2_AHB_BYTES(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG2_AHB_BYTES_SHIFT)) & APBH_CH_DEBUG2_AHB_BYTES_MASK)

#define APBH_CH_DEBUG2_APB_BYTES_MASK            (0xFFFF0000U)
#define APBH_CH_DEBUG2_APB_BYTES_SHIFT           (16U)
#define APBH_CH_DEBUG2_APB_BYTES(x)              (((uint32_t)(((uint32_t)(x)) << APBH_CH_DEBUG2_APB_BYTES_SHIFT)) & APBH_CH_DEBUG2_APB_BYTES_MASK)
/*! @} */

/* The count of APBH_CH_DEBUG2 */
#define APBH_CH_DEBUG2_COUNT                     (16U)

/*! @name VERSION - APBH Bridge Version Register */
/*! @{ */

#define APBH_VERSION_STEP_MASK                   (0xFFFFU)
#define APBH_VERSION_STEP_SHIFT                  (0U)
#define APBH_VERSION_STEP(x)                     (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_STEP_SHIFT)) & APBH_VERSION_STEP_MASK)

#define APBH_VERSION_MINOR_MASK                  (0xFF0000U)
#define APBH_VERSION_MINOR_SHIFT                 (16U)
#define APBH_VERSION_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_MINOR_SHIFT)) & APBH_VERSION_MINOR_MASK)

#define APBH_VERSION_MAJOR_MASK                  (0xFF000000U)
#define APBH_VERSION_MAJOR_SHIFT                 (24U)
#define APBH_VERSION_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << APBH_VERSION_MAJOR_SHIFT)) & APBH_VERSION_MAJOR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group APBH_Register_Masks */


/*!
 * @}
 */ /* end of group APBH_Peripheral_Access_Layer */


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


#endif  /* PERI_APBH_H_ */

