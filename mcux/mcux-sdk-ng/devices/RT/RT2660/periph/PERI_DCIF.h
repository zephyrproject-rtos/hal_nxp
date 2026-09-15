/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DCIF.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DCIF
 *
 * CMSIS Peripheral Access Layer for DCIF
 */

#if !defined(PERI_DCIF_H_)
#define PERI_DCIF_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- DCIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCIF_Peripheral_Access_Layer DCIF Peripheral Access Layer
 * @{
 */

/** DCIF - Size of Registers Arrays */
#define DCIF_CSC_CSC_COEF_COUNT                   6u
#define DCIF_CSC_COUNT                            2u
#define DCIF_L_CTRLDESC_L_COUNT                   8u
#define DCIF_L_D_COUNT                            2u
#define DCIF_L_PANIC_THRES_L_COUNT                1u
#define DCIF_L_LAYER_SR_L_COUNT                   1u
#define DCIF_L_COUNT                              8u

/** DCIF - Register Layout Typedef */
typedef struct {
  __I  uint32_t VER;                               /**< Version ID Register, offset: 0x0 */
  __IO uint32_t PAR_0;                             /**< Parameter Register 0, offset: 0x4 */
  __I  uint32_t PAR_1;                             /**< Parameter Register 1, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DISP_CTRL;                         /**< Display Control Register, offset: 0x10 */
  __IO uint32_t DISP_PAR;                          /**< Display Parameter Register, offset: 0x14 */
  __IO uint32_t DISP_SIZE;                         /**< Display Size Register, offset: 0x18 */
  __I  uint32_t DISP_SR0;                          /**< Display Status Register 0, offset: 0x1C */
  __I  uint32_t DISP_SR1;                          /**< Display Status Register 1, offset: 0x20 */
  __IO uint32_t IE0_D0;                            /**< Interrupt Enable Register 0 for Domain 0, offset: 0x24 */
  __IO uint32_t IS0_D0;                            /**< Interrupt Status Register 0 for Domain 0, offset: 0x28 */
  __IO uint32_t IE1_D0;                            /**< Interrupt Enable Register 1 for Domain 0, offset: 0x2C */
  __IO uint32_t IS1_D0;                            /**< Interrupt Status Register 1 for Domain 0, offset: 0x30 */
       uint8_t RESERVED_1[8];
  __IO uint32_t CLUT_CTRL;                         /**< CLUT control Register, offset: 0x3C */
  __IO uint32_t DPI_CTRL;                          /**< DPI Control Register, offset: 0x40 */
  __IO uint32_t DPI_HSYN_PAR;                      /**< DPI Horizontal Sync Parameter Register, offset: 0x44 */
  __IO uint32_t DPI_VSYN_PAR;                      /**< DPI Vertical Sync Parameter Register, offset: 0x48 */
  __IO uint32_t DPI_VSYN_HSYN_WIDTH;               /**< DPI Vertical and Horizontal Pulse Width Parameter Register, offset: 0x4C */
  __IO uint32_t GC_CTRL;                           /**< Gamma Correction Control Register, offset: 0x50 */
  __I  uint32_t GC_SR;                             /**< Gamma Correction Status Register, offset: 0x54 */
  __IO uint32_t PDI_CTRL;                          /**< PDI Control Register, offset: 0x58 */
  __IO uint32_t PDI_CNT;                           /**< PDI Count Register, offset: 0x5C */
  __IO uint32_t PDI_TO_CNT;                        /**< PDI Timeout Count Register, offset: 0x60 */
  __IO uint32_t FBD_CTRL;                          /**< Frame Buffer Decompression Control Register, offset: 0x64 */
       uint8_t RESERVED_2[8];
  __IO uint32_t DBI_CTRL;                          /**< DBI Control Register, offset: 0x70 */
  __IO uint32_t DBI_PAR0;                          /**< DBI Parameter 0 Register, offset: 0x74 */
  __IO uint32_t DBI_PAR1;                          /**< DBI Parameter 1 Register, offset: 0x78 */
  __I  uint32_t DBI_SR;                            /**< DBI Status Register, offset: 0x7C */
  __IO uint32_t TXPKTIF_CTRL;                      /**< TX Packet Interface Control Register, offset: 0x80 */
  __IO uint32_t TXPKTIF_PAR0;                      /**< TX Packet Interface Parameter 0 Register, offset: 0x84 */
  __IO uint32_t TXPKTIF_PAR1;                      /**< TX Packet Interface Parameter 1 Register, offset: 0x88 */
  __IO uint32_t TXPKTIF_THRES;                     /**< TX Packet Interface Threshold Register, offset: 0x8C */
  __IO uint32_t TXPKTIF_TO_CNT;                    /**< TX Packet Interface Timeout Count Register, offset: 0x90 */
  __I  uint32_t TXPKTIF_SR0;                       /**< TX Packet Interface Status Register 0, offset: 0x94 */
  __I  uint32_t TXPKTIF_SR1;                       /**< TX Packet Interface Status Register 1, offset: 0x98 */
       uint8_t RESERVED_3[868];
  struct {                                         /* offset: 0x400, array step: 0x20 */
    __IO uint32_t CSC_CTRL;                          /**< Color Space Conversion 0 Control Register..Color Space Conversion 1 Control Register, array offset: 0x400, array step: 0x20 */
    __IO uint32_t CSC_COEF[DCIF_CSC_CSC_COEF_COUNT];   /**< Color Space Conversion 0 Coefficient Register 0..Color Space Conversion 1 Coefficient Register 5, array offset: 0x404, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[4];
  } CSC[DCIF_CSC_COUNT];
       uint8_t RESERVED_4[64448];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t CTRLDESC_L[DCIF_L_CTRLDESC_L_COUNT];   /**< Control Descriptor Register 0 for Layer 0..Control Descriptor Register 7 for Layer 7, array offset: 0x10000, array step: index*0x10000, index2*0x4 */
         uint8_t RESERVED_0[4];
    struct {                                         /* offset: 0x10024, array step: index*0x10000, index2*0x8 */
      __IO uint32_t IE_D;                              /**< Interrupt Enable Register 0 for Domain 1..Interrupt Enable Register 1 for Domain 8, array offset: 0x10024, array step: index*0x10000, index2*0x8 */
      __IO uint32_t IS_D;                              /**< Interrupt Status Register 0 for Domain 1..Interrupt Status Register 1 for Domain 8, array offset: 0x10028, array step: index*0x10000, index2*0x8 */
    } D[DCIF_L_D_COUNT];
         uint8_t RESERVED_1[12];
    __IO uint32_t PANIC_THRES_L[DCIF_L_PANIC_THRES_L_COUNT];   /**< FIFO Panic Threshold Register For Layer 0..FIFO Panic Threshold Register For Layer 7, array offset: 0x10040, array step: index*0x10000, index2*0x4 */
    __I  uint32_t LAYER_SR_L[DCIF_L_LAYER_SR_L_COUNT];   /**< Layer Status Register 0 for Layer 0..Layer Status Register 0 for Layer 7, array offset: 0x10044, array step: index*0x10000, index2*0x4 */
         uint8_t RESERVED_2[40];
    __IO uint32_t FRAME_BUF2_ADDR_LOW_L;             /**< Frame Buffer 2 Low Address for Layer 0..Frame Buffer 2 Low Address for Layer 1, array offset: 0x10070, array step: 0x10000, valid indices: [0-1] */
    __I  uint32_t FRAME_BUF2_ADDR_HIGH_L;            /**< Frame Buffer 2 High Address for Layer 0..Frame Buffer 2 High Address for Layer 1, array offset: 0x10074, array step: 0x10000, valid indices: [0-1] */
         uint8_t RESERVED_3[65416];
  } L[DCIF_L_COUNT];
} DCIF_Type;

/* ----------------------------------------------------------------------------
   -- DCIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCIF_Register_Masks DCIF Register Masks
 * @{
 */

/*! @name VER - Version ID Register */
/*! @{ */

#define DCIF_VER_FEATURE_MASK                    (0xFFFFU)
#define DCIF_VER_FEATURE_SHIFT                   (0U)
/*! FEATURE - Feature Set Number */
#define DCIF_VER_FEATURE(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_VER_FEATURE_SHIFT)) & DCIF_VER_FEATURE_MASK)

#define DCIF_VER_MINOR_MASK                      (0xFF0000U)
#define DCIF_VER_MINOR_SHIFT                     (16U)
/*! MINOR - Minor Version Number */
#define DCIF_VER_MINOR(x)                        (((uint32_t)(((uint32_t)(x)) << DCIF_VER_MINOR_SHIFT)) & DCIF_VER_MINOR_MASK)

#define DCIF_VER_MAJOR_MASK                      (0xFF000000U)
#define DCIF_VER_MAJOR_SHIFT                     (24U)
/*! MAJOR - Major Version Number */
#define DCIF_VER_MAJOR(x)                        (((uint32_t)(((uint32_t)(x)) << DCIF_VER_MAJOR_SHIFT)) & DCIF_VER_MAJOR_MASK)
/*! @} */

/*! @name PAR_0 - Parameter Register 0 */
/*! @{ */

#define DCIF_PAR_0_LAYER_NUM_MASK                (0xFU)
#define DCIF_PAR_0_LAYER_NUM_SHIFT               (0U)
/*! LAYER_NUM - Number Of Layer */
#define DCIF_PAR_0_LAYER_NUM(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_LAYER_NUM_SHIFT)) & DCIF_PAR_0_LAYER_NUM_MASK)

#define DCIF_PAR_0_AXI_DATA_WIDTH_MASK           (0xC0U)
#define DCIF_PAR_0_AXI_DATA_WIDTH_SHIFT          (6U)
/*! AXI_DATA_WIDTH - AXI Bus Data Width
 *  0b00..32 bit
 *  0b01..64 bit
 *  0b10..128 bit
 *  0b11..256 bit
 */
#define DCIF_PAR_0_AXI_DATA_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_AXI_DATA_WIDTH_SHIFT)) & DCIF_PAR_0_AXI_DATA_WIDTH_MASK)

#define DCIF_PAR_0_CLUT_RAM_NUM_MASK             (0x300U)
#define DCIF_PAR_0_CLUT_RAM_NUM_SHIFT            (8U)
/*! CLUT_RAM_NUM - Number of CLUT RAM */
#define DCIF_PAR_0_CLUT_RAM_NUM(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_CLUT_RAM_NUM_SHIFT)) & DCIF_PAR_0_CLUT_RAM_NUM_MASK)

#define DCIF_PAR_0_CSC_NUM_MASK                  (0x3000U)
#define DCIF_PAR_0_CSC_NUM_SHIFT                 (12U)
/*! CSC_NUM - Number of CSC Unit */
#define DCIF_PAR_0_CSC_NUM(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_CSC_NUM_SHIFT)) & DCIF_PAR_0_CSC_NUM_MASK)

#define DCIF_PAR_0_DOMAIN_NUM_MASK               (0x1E00000U)
#define DCIF_PAR_0_DOMAIN_NUM_SHIFT              (21U)
/*! DOMAIN_NUM - Number of CPU Domain */
#define DCIF_PAR_0_DOMAIN_NUM(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_DOMAIN_NUM_SHIFT)) & DCIF_PAR_0_DOMAIN_NUM_MASK)

#define DCIF_PAR_0_BACKUP_MASK                   (0xF0000000U)
#define DCIF_PAR_0_BACKUP_SHIFT                  (28U)
/*! BACKUP - Backup Option */
#define DCIF_PAR_0_BACKUP(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_0_BACKUP_SHIFT)) & DCIF_PAR_0_BACKUP_MASK)
/*! @} */

/*! @name PAR_1 - Parameter Register 1 */
/*! @{ */

#define DCIF_PAR_1_LAYER0_FIFO_SIZE_MASK         (0xFU)
#define DCIF_PAR_1_LAYER0_FIFO_SIZE_SHIFT        (0U)
/*! LAYER0_FIFO_SIZE - Layer 0 FIFO size */
#define DCIF_PAR_1_LAYER0_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER0_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER0_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER1_FIFO_SIZE_MASK         (0xF0U)
#define DCIF_PAR_1_LAYER1_FIFO_SIZE_SHIFT        (4U)
/*! LAYER1_FIFO_SIZE - Layer 1 FIFO size */
#define DCIF_PAR_1_LAYER1_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER1_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER1_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER2_FIFO_SIZE_MASK         (0xF00U)
#define DCIF_PAR_1_LAYER2_FIFO_SIZE_SHIFT        (8U)
/*! LAYER2_FIFO_SIZE - Layer 2 FIFO size */
#define DCIF_PAR_1_LAYER2_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER2_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER2_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER3_FIFO_SIZE_MASK         (0xF000U)
#define DCIF_PAR_1_LAYER3_FIFO_SIZE_SHIFT        (12U)
/*! LAYER3_FIFO_SIZE - Layer 3 FIFO size */
#define DCIF_PAR_1_LAYER3_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER3_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER3_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER4_FIFO_SIZE_MASK         (0xF0000U)
#define DCIF_PAR_1_LAYER4_FIFO_SIZE_SHIFT        (16U)
/*! LAYER4_FIFO_SIZE - Layer 4 FIFO size */
#define DCIF_PAR_1_LAYER4_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER4_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER4_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER5_FIFO_SIZE_MASK         (0xF00000U)
#define DCIF_PAR_1_LAYER5_FIFO_SIZE_SHIFT        (20U)
/*! LAYER5_FIFO_SIZE - Layer 5 FIFO size */
#define DCIF_PAR_1_LAYER5_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER5_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER5_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER6_FIFO_SIZE_MASK         (0xF000000U)
#define DCIF_PAR_1_LAYER6_FIFO_SIZE_SHIFT        (24U)
/*! LAYER6_FIFO_SIZE - Layer 6 FIFO size */
#define DCIF_PAR_1_LAYER6_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER6_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER6_FIFO_SIZE_MASK)

#define DCIF_PAR_1_LAYER7_FIFO_SIZE_MASK         (0xF0000000U)
#define DCIF_PAR_1_LAYER7_FIFO_SIZE_SHIFT        (28U)
/*! LAYER7_FIFO_SIZE - Layer 7 FIFO size */
#define DCIF_PAR_1_LAYER7_FIFO_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PAR_1_LAYER7_FIFO_SIZE_SHIFT)) & DCIF_PAR_1_LAYER7_FIFO_SIZE_MASK)
/*! @} */

/*! @name DISP_CTRL - Display Control Register */
/*! @{ */

#define DCIF_DISP_CTRL_DISP_ON_MASK              (0x1U)
#define DCIF_DISP_CTRL_DISP_ON_SHIFT             (0U)
/*! DISP_ON - Display Panel On/Off Mode
 *  0b0..Display Off
 *  0b1..Display On
 */
#define DCIF_DISP_CTRL_DISP_ON(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_CTRL_DISP_ON_SHIFT)) & DCIF_DISP_CTRL_DISP_ON_MASK)

#define DCIF_DISP_CTRL_DISP_IF_SEL_MASK          (0x6U)
#define DCIF_DISP_CTRL_DISP_IF_SEL_SHIFT         (1U)
/*! DISP_IF_SEL - Display Interface Selection
 *  0b00..DPI
 *  0b01..DBI
 *  0b10..TX Packet Interface
 */
#define DCIF_DISP_CTRL_DISP_IF_SEL(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_CTRL_DISP_IF_SEL_SHIFT)) & DCIF_DISP_CTRL_DISP_IF_SEL_MASK)

#define DCIF_DISP_CTRL_AXI_RD_HOLD_MASK          (0x40000000U)
#define DCIF_DISP_CTRL_AXI_RD_HOLD_SHIFT         (30U)
/*! AXI_RD_HOLD - AXI Read Hold Control
 *  0b0..No action
 *  0b1..Hold fetch request
 */
#define DCIF_DISP_CTRL_AXI_RD_HOLD(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_CTRL_AXI_RD_HOLD_SHIFT)) & DCIF_DISP_CTRL_AXI_RD_HOLD_MASK)

#define DCIF_DISP_CTRL_SW_RST_MASK               (0x80000000U)
#define DCIF_DISP_CTRL_SW_RST_SHIFT              (31U)
/*! SW_RST - Software Reset
 *  0b0..No action
 *  0b1..All internal and status registers are forced into their reset state. configuration registers are not affected.
 */
#define DCIF_DISP_CTRL_SW_RST(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_CTRL_SW_RST_SHIFT)) & DCIF_DISP_CTRL_SW_RST_MASK)
/*! @} */

/*! @name DISP_PAR - Display Parameter Register */
/*! @{ */

#define DCIF_DISP_PAR_BGND_B_MASK                (0xFFU)
#define DCIF_DISP_PAR_BGND_B_SHIFT               (0U)
/*! BGND_B - Background Blue Component */
#define DCIF_DISP_PAR_BGND_B(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_PAR_BGND_B_SHIFT)) & DCIF_DISP_PAR_BGND_B_MASK)

#define DCIF_DISP_PAR_BGND_G_MASK                (0xFF00U)
#define DCIF_DISP_PAR_BGND_G_SHIFT               (8U)
/*! BGND_G - Background Green Component */
#define DCIF_DISP_PAR_BGND_G(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_PAR_BGND_G_SHIFT)) & DCIF_DISP_PAR_BGND_G_MASK)

#define DCIF_DISP_PAR_BGND_R_MASK                (0xFF0000U)
#define DCIF_DISP_PAR_BGND_R_SHIFT               (16U)
/*! BGND_R - Background Red Component */
#define DCIF_DISP_PAR_BGND_R(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_PAR_BGND_R_SHIFT)) & DCIF_DISP_PAR_BGND_R_MASK)

#define DCIF_DISP_PAR_BGND_A_MASK                (0xFF000000U)
#define DCIF_DISP_PAR_BGND_A_SHIFT               (24U)
/*! BGND_A - Background Alpha Component */
#define DCIF_DISP_PAR_BGND_A(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_PAR_BGND_A_SHIFT)) & DCIF_DISP_PAR_BGND_A_MASK)
/*! @} */

/*! @name DISP_SIZE - Display Size Register */
/*! @{ */

#define DCIF_DISP_SIZE_DISP_WIDTH_MASK           (0xFFFU)
#define DCIF_DISP_SIZE_DISP_WIDTH_SHIFT          (0U)
/*! DISP_WIDTH - Display Width */
#define DCIF_DISP_SIZE_DISP_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SIZE_DISP_WIDTH_SHIFT)) & DCIF_DISP_SIZE_DISP_WIDTH_MASK)

#define DCIF_DISP_SIZE_DISP_HEIGHT_MASK          (0xFFF0000U)
#define DCIF_DISP_SIZE_DISP_HEIGHT_SHIFT         (16U)
/*! DISP_HEIGHT - Display Height */
#define DCIF_DISP_SIZE_DISP_HEIGHT(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SIZE_DISP_HEIGHT_SHIFT)) & DCIF_DISP_SIZE_DISP_HEIGHT_MASK)
/*! @} */

/*! @name DISP_SR0 - Display Status Register 0 */
/*! @{ */

#define DCIF_DISP_SR0_AXI_RD_PEND_MASK           (0x1FU)
#define DCIF_DISP_SR0_AXI_RD_PEND_SHIFT          (0U)
/*! AXI_RD_PEND - AXI Read Pending */
#define DCIF_DISP_SR0_AXI_RD_PEND(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR0_AXI_RD_PEND_SHIFT)) & DCIF_DISP_SR0_AXI_RD_PEND_MASK)

#define DCIF_DISP_SR0_TE_PEND_MASK               (0x2000U)
#define DCIF_DISP_SR0_TE_PEND_SHIFT              (13U)
/*! TE_PEND - TE Sync Pending
 *  0b0..Idle
 *  0b1..Pend to send pixel data and waiting TE active
 */
#define DCIF_DISP_SR0_TE_PEND(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR0_TE_PEND_SHIFT)) & DCIF_DISP_SR0_TE_PEND_MASK)

#define DCIF_DISP_SR0_DPI_BUSY_MASK              (0x4000U)
#define DCIF_DISP_SR0_DPI_BUSY_SHIFT             (14U)
/*! DPI_BUSY - DPI Busy
 *  0b0..Idle
 *  0b1..DPI interface is working
 */
#define DCIF_DISP_SR0_DPI_BUSY(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR0_DPI_BUSY_SHIFT)) & DCIF_DISP_SR0_DPI_BUSY_MASK)

#define DCIF_DISP_SR0_AXI_RD_BUSY_MASK           (0x8000U)
#define DCIF_DISP_SR0_AXI_RD_BUSY_SHIFT          (15U)
/*! AXI_RD_BUSY - AXI Read Busy
 *  0b0..Idle
 *  0b1..AXI read is in progress
 */
#define DCIF_DISP_SR0_AXI_RD_BUSY(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR0_AXI_RD_BUSY_SHIFT)) & DCIF_DISP_SR0_AXI_RD_BUSY_MASK)

#define DCIF_DISP_SR0_TXFIFO_CNT_MASK            (0xFF0000U)
#define DCIF_DISP_SR0_TXFIFO_CNT_SHIFT           (16U)
/*! TXFIFO_CNT - TXFIFO Count */
#define DCIF_DISP_SR0_TXFIFO_CNT(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR0_TXFIFO_CNT_SHIFT)) & DCIF_DISP_SR0_TXFIFO_CNT_MASK)
/*! @} */

/*! @name DISP_SR1 - Display Status Register 1 */
/*! @{ */

#define DCIF_DISP_SR1_H_CNT_MASK                 (0xFFFU)
#define DCIF_DISP_SR1_H_CNT_SHIFT                (0U)
/*! H_CNT - Horizontal Count */
#define DCIF_DISP_SR1_H_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR1_H_CNT_SHIFT)) & DCIF_DISP_SR1_H_CNT_MASK)

#define DCIF_DISP_SR1_V_CNT_MASK                 (0xFFF0000U)
#define DCIF_DISP_SR1_V_CNT_SHIFT                (16U)
/*! V_CNT - Vertical Count */
#define DCIF_DISP_SR1_V_CNT(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_DISP_SR1_V_CNT_SHIFT)) & DCIF_DISP_SR1_V_CNT_MASK)
/*! @} */

/*! @name IE0_D0 - Interrupt Enable Register 0 for Domain 0 */
/*! @{ */

#define DCIF_IE0_D0_VSYNC_EN_MASK                (0x1U)
#define DCIF_IE0_D0_VSYNC_EN_SHIFT               (0U)
/*! VSYNC_EN - VSYNC Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_VSYNC_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_VSYNC_EN_SHIFT)) & DCIF_IE0_D0_VSYNC_EN_MASK)

#define DCIF_IE0_D0_UNDERRUN_EN_MASK             (0x2U)
#define DCIF_IE0_D0_UNDERRUN_EN_SHIFT            (1U)
/*! UNDERRUN_EN - Underrun Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_UNDERRUN_EN(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_UNDERRUN_EN_SHIFT)) & DCIF_IE0_D0_UNDERRUN_EN_MASK)

#define DCIF_IE0_D0_VS_BLANK_EN_MASK             (0x4U)
#define DCIF_IE0_D0_VS_BLANK_EN_SHIFT            (2U)
/*! VS_BLANK_EN - Vertical Blanking Period Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_VS_BLANK_EN(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_VS_BLANK_EN_SHIFT)) & DCIF_IE0_D0_VS_BLANK_EN_MASK)

#define DCIF_IE0_D0_PDI_OVERRUN_EN_MASK          (0x8U)
#define DCIF_IE0_D0_PDI_OVERRUN_EN_SHIFT         (3U)
/*! PDI_OVERRUN_EN - PDI Buffer Overrun Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_PDI_OVERRUN_EN(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_PDI_OVERRUN_EN_SHIFT)) & DCIF_IE0_D0_PDI_OVERRUN_EN_MASK)

#define DCIF_IE0_D0_PDI_TIMEOUT_EN_MASK          (0x10U)
#define DCIF_IE0_D0_PDI_TIMEOUT_EN_SHIFT         (4U)
/*! PDI_TIMEOUT_EN - PDI Vsync Timeout Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_PDI_TIMEOUT_EN(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_PDI_TIMEOUT_EN_SHIFT)) & DCIF_IE0_D0_PDI_TIMEOUT_EN_MASK)

#define DCIF_IE0_D0_DBI_DONE_EN_MASK             (0x100U)
#define DCIF_IE0_D0_DBI_DONE_EN_SHIFT            (8U)
/*! DBI_DONE_EN - DBI Command Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_DBI_DONE_EN(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_DBI_DONE_EN_SHIFT)) & DCIF_IE0_D0_DBI_DONE_EN_MASK)

#define DCIF_IE0_D0_TXPKTIF_DONE_EN_MASK         (0x200U)
#define DCIF_IE0_D0_TXPKTIF_DONE_EN_SHIFT        (9U)
/*! TXPKTIF_DONE_EN - TX Packet Interface Command Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_TXPKTIF_DONE_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_TXPKTIF_DONE_EN_SHIFT)) & DCIF_IE0_D0_TXPKTIF_DONE_EN_MASK)

#define DCIF_IE0_D0_TXPKTIF_TIMEOUT_EN_MASK      (0x400U)
#define DCIF_IE0_D0_TXPKTIF_TIMEOUT_EN_SHIFT     (10U)
/*! TXPKTIF_TIMEOUT_EN - TX Packet Interface Timeout Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE0_D0_TXPKTIF_TIMEOUT_EN(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_IE0_D0_TXPKTIF_TIMEOUT_EN_SHIFT)) & DCIF_IE0_D0_TXPKTIF_TIMEOUT_EN_MASK)
/*! @} */

/*! @name IS0_D0 - Interrupt Status Register 0 for Domain 0 */
/*! @{ */

#define DCIF_IS0_D0_VSYNC_MASK                   (0x1U)
#define DCIF_IS0_D0_VSYNC_SHIFT                  (0U)
/*! VSYNC - VSYNC Start Flag
 *  0b0..VSYNC has not started
 *  0b1..VSYNC has started
 */
#define DCIF_IS0_D0_VSYNC(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_VSYNC_SHIFT)) & DCIF_IS0_D0_VSYNC_MASK)

#define DCIF_IS0_D0_UNDERRUN_MASK                (0x2U)
#define DCIF_IS0_D0_UNDERRUN_SHIFT               (1U)
/*! UNDERRUN - Underrun Flag
 *  0b0..Output buffer not underrun
 *  0b1..Output buffer underrun
 */
#define DCIF_IS0_D0_UNDERRUN(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_UNDERRUN_SHIFT)) & DCIF_IS0_D0_UNDERRUN_MASK)

#define DCIF_IS0_D0_VS_BLANK_MASK                (0x4U)
#define DCIF_IS0_D0_VS_BLANK_SHIFT               (2U)
/*! VS_BLANK - Vertical Blanking Period Start Flag
 *  0b0..Vertical blanking period has not started
 *  0b1..Vertical blanking period has started
 */
#define DCIF_IS0_D0_VS_BLANK(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_VS_BLANK_SHIFT)) & DCIF_IS0_D0_VS_BLANK_MASK)

#define DCIF_IS0_D0_PDI_OVERRUN_MASK             (0x8U)
#define DCIF_IS0_D0_PDI_OVERRUN_SHIFT            (3U)
/*! PDI_OVERRUN - PDI Buffer Overrun Flag
 *  0b0..PDI buffer not overrun
 *  0b1..PDI buffer overrun
 */
#define DCIF_IS0_D0_PDI_OVERRUN(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_PDI_OVERRUN_SHIFT)) & DCIF_IS0_D0_PDI_OVERRUN_MASK)

#define DCIF_IS0_D0_PDI_TIMEOUT_MASK             (0x10U)
#define DCIF_IS0_D0_PDI_TIMEOUT_SHIFT            (4U)
/*! PDI_TIMEOUT - PDI Timeout Flag
 *  0b0..No error
 *  0b1..Timeout Error occur
 */
#define DCIF_IS0_D0_PDI_TIMEOUT(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_PDI_TIMEOUT_SHIFT)) & DCIF_IS0_D0_PDI_TIMEOUT_MASK)

#define DCIF_IS0_D0_DBI_DONE_MASK                (0x100U)
#define DCIF_IS0_D0_DBI_DONE_SHIFT               (8U)
/*! DBI_DONE - DBI Command Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS0_D0_DBI_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_DBI_DONE_SHIFT)) & DCIF_IS0_D0_DBI_DONE_MASK)

#define DCIF_IS0_D0_TXPKTIF_DONE_MASK            (0x200U)
#define DCIF_IS0_D0_TXPKTIF_DONE_SHIFT           (9U)
/*! TXPKTIF_DONE - TX Packet Interface Command Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS0_D0_TXPKTIF_DONE(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_TXPKTIF_DONE_SHIFT)) & DCIF_IS0_D0_TXPKTIF_DONE_MASK)

#define DCIF_IS0_D0_TXPKTIF_TIMEOUT_MASK         (0x400U)
#define DCIF_IS0_D0_TXPKTIF_TIMEOUT_SHIFT        (10U)
/*! TXPKTIF_TIMEOUT - TX Packet Interface Timeout Flag
 *  0b0..No error
 *  0b1..Timeout Error occur
 */
#define DCIF_IS0_D0_TXPKTIF_TIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_IS0_D0_TXPKTIF_TIMEOUT_SHIFT)) & DCIF_IS0_D0_TXPKTIF_TIMEOUT_MASK)
/*! @} */

/*! @name IE1_D0 - Interrupt Enable Register 1 for Domain 0 */
/*! @{ */

#define DCIF_IE1_D0_FIFO_PANIC_EN0_MASK          (0x1U)
#define DCIF_IE1_D0_FIFO_PANIC_EN0_SHIFT         (0U)
/*! FIFO_PANIC_EN0 - Enable Layer 0 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN0(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN0_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN0_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN1_MASK          (0x2U)
#define DCIF_IE1_D0_FIFO_PANIC_EN1_SHIFT         (1U)
/*! FIFO_PANIC_EN1 - Enable Layer 1 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN1(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN1_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN1_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN2_MASK          (0x4U)
#define DCIF_IE1_D0_FIFO_PANIC_EN2_SHIFT         (2U)
/*! FIFO_PANIC_EN2 - Enable Layer 2 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN2(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN2_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN2_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN3_MASK          (0x8U)
#define DCIF_IE1_D0_FIFO_PANIC_EN3_SHIFT         (3U)
/*! FIFO_PANIC_EN3 - Enable Layer 3 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN3(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN3_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN3_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN4_MASK          (0x10U)
#define DCIF_IE1_D0_FIFO_PANIC_EN4_SHIFT         (4U)
/*! FIFO_PANIC_EN4 - Enable Layer 4 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN4(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN4_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN4_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN5_MASK          (0x20U)
#define DCIF_IE1_D0_FIFO_PANIC_EN5_SHIFT         (5U)
/*! FIFO_PANIC_EN5 - Enable Layer 5 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN5(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN5_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN5_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN6_MASK          (0x40U)
#define DCIF_IE1_D0_FIFO_PANIC_EN6_SHIFT         (6U)
/*! FIFO_PANIC_EN6 - Enable Layer 6 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN6(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN6_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN6_MASK)

#define DCIF_IE1_D0_FIFO_PANIC_EN7_MASK          (0x80U)
#define DCIF_IE1_D0_FIFO_PANIC_EN7_SHIFT         (7U)
/*! FIFO_PANIC_EN7 - Enable Layer 7 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_PANIC_EN7(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_PANIC_EN7_SHIFT)) & DCIF_IE1_D0_FIFO_PANIC_EN7_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN0_MASK             (0x100U)
#define DCIF_IE1_D0_DMA_ERR_EN0_SHIFT            (8U)
/*! DMA_ERR_EN0 - Enable Layer 0 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN0(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN0_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN0_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN1_MASK             (0x200U)
#define DCIF_IE1_D0_DMA_ERR_EN1_SHIFT            (9U)
/*! DMA_ERR_EN1 - Enable Layer 1 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN1(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN1_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN1_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN2_MASK             (0x400U)
#define DCIF_IE1_D0_DMA_ERR_EN2_SHIFT            (10U)
/*! DMA_ERR_EN2 - Enable Layer 2 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN2(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN2_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN2_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN3_MASK             (0x800U)
#define DCIF_IE1_D0_DMA_ERR_EN3_SHIFT            (11U)
/*! DMA_ERR_EN3 - Enable Layer 3 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN3(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN3_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN3_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN4_MASK             (0x1000U)
#define DCIF_IE1_D0_DMA_ERR_EN4_SHIFT            (12U)
/*! DMA_ERR_EN4 - Enable Layer 4 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN4(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN4_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN4_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN5_MASK             (0x2000U)
#define DCIF_IE1_D0_DMA_ERR_EN5_SHIFT            (13U)
/*! DMA_ERR_EN5 - Enable Layer 5 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN5(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN5_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN5_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN6_MASK             (0x4000U)
#define DCIF_IE1_D0_DMA_ERR_EN6_SHIFT            (14U)
/*! DMA_ERR_EN6 - Enable Layer 6 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN6(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN6_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN6_MASK)

#define DCIF_IE1_D0_DMA_ERR_EN7_MASK             (0x8000U)
#define DCIF_IE1_D0_DMA_ERR_EN7_SHIFT            (15U)
/*! DMA_ERR_EN7 - Enable Layer 7 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_ERR_EN7(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_ERR_EN7_SHIFT)) & DCIF_IE1_D0_DMA_ERR_EN7_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN0_MASK            (0x10000U)
#define DCIF_IE1_D0_DMA_DONE_EN0_SHIFT           (16U)
/*! DMA_DONE_EN0 - Enable Layer 0 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN0(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN0_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN0_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN1_MASK            (0x20000U)
#define DCIF_IE1_D0_DMA_DONE_EN1_SHIFT           (17U)
/*! DMA_DONE_EN1 - Enable Layer 1 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN1(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN1_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN1_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN2_MASK            (0x40000U)
#define DCIF_IE1_D0_DMA_DONE_EN2_SHIFT           (18U)
/*! DMA_DONE_EN2 - Enable Layer 2 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN2(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN2_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN2_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN3_MASK            (0x80000U)
#define DCIF_IE1_D0_DMA_DONE_EN3_SHIFT           (19U)
/*! DMA_DONE_EN3 - Enable Layer 3 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN3(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN3_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN3_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN4_MASK            (0x100000U)
#define DCIF_IE1_D0_DMA_DONE_EN4_SHIFT           (20U)
/*! DMA_DONE_EN4 - Enable Layer 4 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN4(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN4_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN4_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN5_MASK            (0x200000U)
#define DCIF_IE1_D0_DMA_DONE_EN5_SHIFT           (21U)
/*! DMA_DONE_EN5 - Enable Layer 5 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN5(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN5_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN5_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN6_MASK            (0x400000U)
#define DCIF_IE1_D0_DMA_DONE_EN6_SHIFT           (22U)
/*! DMA_DONE_EN6 - Enable Layer 6 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN6(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN6_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN6_MASK)

#define DCIF_IE1_D0_DMA_DONE_EN7_MASK            (0x800000U)
#define DCIF_IE1_D0_DMA_DONE_EN7_SHIFT           (23U)
/*! DMA_DONE_EN7 - Enable Layer 7 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_DMA_DONE_EN7(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_DMA_DONE_EN7_SHIFT)) & DCIF_IE1_D0_DMA_DONE_EN7_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN0_MASK          (0x1000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN0_SHIFT         (24U)
/*! FIFO_EMPTY_EN0 - Enable Layer 0 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN0(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN0_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN0_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN1_MASK          (0x2000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN1_SHIFT         (25U)
/*! FIFO_EMPTY_EN1 - Enable Layer 1 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN1(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN1_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN1_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN2_MASK          (0x4000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN2_SHIFT         (26U)
/*! FIFO_EMPTY_EN2 - Enable Layer 2 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN2(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN2_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN2_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN3_MASK          (0x8000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN3_SHIFT         (27U)
/*! FIFO_EMPTY_EN3 - Enable Layer 3 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN3(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN3_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN3_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN4_MASK          (0x10000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN4_SHIFT         (28U)
/*! FIFO_EMPTY_EN4 - Enable Layer 4 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN4(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN4_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN4_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN5_MASK          (0x20000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN5_SHIFT         (29U)
/*! FIFO_EMPTY_EN5 - Enable Layer 5 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN5(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN5_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN5_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN6_MASK          (0x40000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN6_SHIFT         (30U)
/*! FIFO_EMPTY_EN6 - Enable Layer 6 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN6(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN6_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN6_MASK)

#define DCIF_IE1_D0_FIFO_EMPTY_EN7_MASK          (0x80000000U)
#define DCIF_IE1_D0_FIFO_EMPTY_EN7_SHIFT         (31U)
/*! FIFO_EMPTY_EN7 - Enable Layer 7 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE1_D0_FIFO_EMPTY_EN7(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_IE1_D0_FIFO_EMPTY_EN7_SHIFT)) & DCIF_IE1_D0_FIFO_EMPTY_EN7_MASK)
/*! @} */

/*! @name IS1_D0 - Interrupt Status Register 1 for Domain 0 */
/*! @{ */

#define DCIF_IS1_D0_FIFO_PANIC0_MASK             (0x1U)
#define DCIF_IS1_D0_FIFO_PANIC0_SHIFT            (0U)
/*! FIFO_PANIC0 - Layer 0 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC0(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC0_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC0_MASK)

#define DCIF_IS1_D0_FIFO_PANIC1_MASK             (0x2U)
#define DCIF_IS1_D0_FIFO_PANIC1_SHIFT            (1U)
/*! FIFO_PANIC1 - Layer 1 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC1(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC1_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC1_MASK)

#define DCIF_IS1_D0_FIFO_PANIC2_MASK             (0x4U)
#define DCIF_IS1_D0_FIFO_PANIC2_SHIFT            (2U)
/*! FIFO_PANIC2 - Layer 2 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC2(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC2_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC2_MASK)

#define DCIF_IS1_D0_FIFO_PANIC3_MASK             (0x8U)
#define DCIF_IS1_D0_FIFO_PANIC3_SHIFT            (3U)
/*! FIFO_PANIC3 - Layer 3 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC3(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC3_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC3_MASK)

#define DCIF_IS1_D0_FIFO_PANIC4_MASK             (0x10U)
#define DCIF_IS1_D0_FIFO_PANIC4_SHIFT            (4U)
/*! FIFO_PANIC4 - Layer 4 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC4(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC4_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC4_MASK)

#define DCIF_IS1_D0_FIFO_PANIC5_MASK             (0x20U)
#define DCIF_IS1_D0_FIFO_PANIC5_SHIFT            (5U)
/*! FIFO_PANIC5 - Layer 5 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC5(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC5_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC5_MASK)

#define DCIF_IS1_D0_FIFO_PANIC6_MASK             (0x40U)
#define DCIF_IS1_D0_FIFO_PANIC6_SHIFT            (6U)
/*! FIFO_PANIC6 - Layer 6 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC6(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC6_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC6_MASK)

#define DCIF_IS1_D0_FIFO_PANIC7_MASK             (0x80U)
#define DCIF_IS1_D0_FIFO_PANIC7_SHIFT            (7U)
/*! FIFO_PANIC7 - Layer 7 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS1_D0_FIFO_PANIC7(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_PANIC7_SHIFT)) & DCIF_IS1_D0_FIFO_PANIC7_MASK)

#define DCIF_IS1_D0_DMA_ERR0_MASK                (0x100U)
#define DCIF_IS1_D0_DMA_ERR0_SHIFT               (8U)
/*! DMA_ERR0 - Layer 0 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR0(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR0_SHIFT)) & DCIF_IS1_D0_DMA_ERR0_MASK)

#define DCIF_IS1_D0_DMA_ERR1_MASK                (0x200U)
#define DCIF_IS1_D0_DMA_ERR1_SHIFT               (9U)
/*! DMA_ERR1 - Layer 1 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR1(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR1_SHIFT)) & DCIF_IS1_D0_DMA_ERR1_MASK)

#define DCIF_IS1_D0_DMA_ERR2_MASK                (0x400U)
#define DCIF_IS1_D0_DMA_ERR2_SHIFT               (10U)
/*! DMA_ERR2 - Layer 2 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR2(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR2_SHIFT)) & DCIF_IS1_D0_DMA_ERR2_MASK)

#define DCIF_IS1_D0_DMA_ERR3_MASK                (0x800U)
#define DCIF_IS1_D0_DMA_ERR3_SHIFT               (11U)
/*! DMA_ERR3 - Layer 3 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR3(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR3_SHIFT)) & DCIF_IS1_D0_DMA_ERR3_MASK)

#define DCIF_IS1_D0_DMA_ERR4_MASK                (0x1000U)
#define DCIF_IS1_D0_DMA_ERR4_SHIFT               (12U)
/*! DMA_ERR4 - Layer 4 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR4(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR4_SHIFT)) & DCIF_IS1_D0_DMA_ERR4_MASK)

#define DCIF_IS1_D0_DMA_ERR5_MASK                (0x2000U)
#define DCIF_IS1_D0_DMA_ERR5_SHIFT               (13U)
/*! DMA_ERR5 - Layer 5 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR5(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR5_SHIFT)) & DCIF_IS1_D0_DMA_ERR5_MASK)

#define DCIF_IS1_D0_DMA_ERR6_MASK                (0x4000U)
#define DCIF_IS1_D0_DMA_ERR6_SHIFT               (14U)
/*! DMA_ERR6 - Layer 6 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR6(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR6_SHIFT)) & DCIF_IS1_D0_DMA_ERR6_MASK)

#define DCIF_IS1_D0_DMA_ERR7_MASK                (0x8000U)
#define DCIF_IS1_D0_DMA_ERR7_SHIFT               (15U)
/*! DMA_ERR7 - Layer 7 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS1_D0_DMA_ERR7(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_ERR7_SHIFT)) & DCIF_IS1_D0_DMA_ERR7_MASK)

#define DCIF_IS1_D0_DMA_DONE0_MASK               (0x10000U)
#define DCIF_IS1_D0_DMA_DONE0_SHIFT              (16U)
/*! DMA_DONE0 - Layer 0 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE0(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE0_SHIFT)) & DCIF_IS1_D0_DMA_DONE0_MASK)

#define DCIF_IS1_D0_DMA_DONE1_MASK               (0x20000U)
#define DCIF_IS1_D0_DMA_DONE1_SHIFT              (17U)
/*! DMA_DONE1 - Layer 1 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE1(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE1_SHIFT)) & DCIF_IS1_D0_DMA_DONE1_MASK)

#define DCIF_IS1_D0_DMA_DONE2_MASK               (0x40000U)
#define DCIF_IS1_D0_DMA_DONE2_SHIFT              (18U)
/*! DMA_DONE2 - Layer 2 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE2(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE2_SHIFT)) & DCIF_IS1_D0_DMA_DONE2_MASK)

#define DCIF_IS1_D0_DMA_DONE3_MASK               (0x80000U)
#define DCIF_IS1_D0_DMA_DONE3_SHIFT              (19U)
/*! DMA_DONE3 - Layer 3 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE3(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE3_SHIFT)) & DCIF_IS1_D0_DMA_DONE3_MASK)

#define DCIF_IS1_D0_DMA_DONE4_MASK               (0x100000U)
#define DCIF_IS1_D0_DMA_DONE4_SHIFT              (20U)
/*! DMA_DONE4 - Layer 4 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE4(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE4_SHIFT)) & DCIF_IS1_D0_DMA_DONE4_MASK)

#define DCIF_IS1_D0_DMA_DONE5_MASK               (0x200000U)
#define DCIF_IS1_D0_DMA_DONE5_SHIFT              (21U)
/*! DMA_DONE5 - Layer 5 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE5(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE5_SHIFT)) & DCIF_IS1_D0_DMA_DONE5_MASK)

#define DCIF_IS1_D0_DMA_DONE6_MASK               (0x400000U)
#define DCIF_IS1_D0_DMA_DONE6_SHIFT              (22U)
/*! DMA_DONE6 - Layer 6 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE6(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE6_SHIFT)) & DCIF_IS1_D0_DMA_DONE6_MASK)

#define DCIF_IS1_D0_DMA_DONE7_MASK               (0x800000U)
#define DCIF_IS1_D0_DMA_DONE7_SHIFT              (23U)
/*! DMA_DONE7 - Layer 7 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS1_D0_DMA_DONE7(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_DMA_DONE7_SHIFT)) & DCIF_IS1_D0_DMA_DONE7_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY0_MASK             (0x1000000U)
#define DCIF_IS1_D0_FIFO_EMPTY0_SHIFT            (24U)
/*! FIFO_EMPTY0 - Layer 0 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY0(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY0_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY0_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY1_MASK             (0x2000000U)
#define DCIF_IS1_D0_FIFO_EMPTY1_SHIFT            (25U)
/*! FIFO_EMPTY1 - Layer 1 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY1(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY1_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY1_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY2_MASK             (0x4000000U)
#define DCIF_IS1_D0_FIFO_EMPTY2_SHIFT            (26U)
/*! FIFO_EMPTY2 - Layer 2 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY2(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY2_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY2_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY3_MASK             (0x8000000U)
#define DCIF_IS1_D0_FIFO_EMPTY3_SHIFT            (27U)
/*! FIFO_EMPTY3 - Layer 3 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY3(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY3_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY3_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY4_MASK             (0x10000000U)
#define DCIF_IS1_D0_FIFO_EMPTY4_SHIFT            (28U)
/*! FIFO_EMPTY4 - Layer 4 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY4(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY4_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY4_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY5_MASK             (0x20000000U)
#define DCIF_IS1_D0_FIFO_EMPTY5_SHIFT            (29U)
/*! FIFO_EMPTY5 - Layer 5 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY5(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY5_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY5_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY6_MASK             (0x40000000U)
#define DCIF_IS1_D0_FIFO_EMPTY6_SHIFT            (30U)
/*! FIFO_EMPTY6 - Layer 6 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY6(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY6_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY6_MASK)

#define DCIF_IS1_D0_FIFO_EMPTY7_MASK             (0x80000000U)
#define DCIF_IS1_D0_FIFO_EMPTY7_SHIFT            (31U)
/*! FIFO_EMPTY7 - Layer 7 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS1_D0_FIFO_EMPTY7(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_IS1_D0_FIFO_EMPTY7_SHIFT)) & DCIF_IS1_D0_FIFO_EMPTY7_MASK)
/*! @} */

/*! @name CLUT_CTRL - CLUT control Register */
/*! @{ */

#define DCIF_CLUT_CTRL_CLUT0_SEL_MASK            (0x7U)
#define DCIF_CLUT_CTRL_CLUT0_SEL_SHIFT           (0U)
/*! CLUT0_SEL - Selected Layer For CLUT0.
 *  0b000..Layer 0
 *  0b001..Layer 1
 *  0b010..Layer 2
 *  0b011..Layer 3
 *  0b100..Layer 4
 *  0b101..Layer 5
 *  0b110..Layer 6
 *  0b111..Layer 7
 */
#define DCIF_CLUT_CTRL_CLUT0_SEL(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_CLUT_CTRL_CLUT0_SEL_SHIFT)) & DCIF_CLUT_CTRL_CLUT0_SEL_MASK)

#define DCIF_CLUT_CTRL_CLUT1_SEL_MASK            (0x38U)
#define DCIF_CLUT_CTRL_CLUT1_SEL_SHIFT           (3U)
/*! CLUT1_SEL - Selected Layer For CLUT1.
 *  0b000..Layer 0
 *  0b001..Layer 1
 *  0b010..Layer 2
 *  0b011..Layer 3
 *  0b100..Layer 4
 *  0b101..Layer 5
 *  0b110..Layer 6
 *  0b111..Layer 7
 */
#define DCIF_CLUT_CTRL_CLUT1_SEL(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_CLUT_CTRL_CLUT1_SEL_SHIFT)) & DCIF_CLUT_CTRL_CLUT1_SEL_MASK)

#define DCIF_CLUT_CTRL_CLUT_MUX_MASK             (0x30000000U)
#define DCIF_CLUT_CTRL_CLUT_MUX_SHIFT            (28U)
/*! CLUT_MUX - CLUT MUX
 *  0b00..CLUT0
 *  0b01..CLUT1
 *  0b10..Reserved
 *  0b11..Reserved
 */
#define DCIF_CLUT_CTRL_CLUT_MUX(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_CLUT_CTRL_CLUT_MUX_SHIFT)) & DCIF_CLUT_CTRL_CLUT_MUX_MASK)

#define DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN_MASK  (0x80000000U)
#define DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN_SHIFT (31U)
/*! CLUT_SHADOW_LOAD_EN - CLUT Shadow Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN(x)    (((uint32_t)(((uint32_t)(x)) << DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN_SHIFT)) & DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN_MASK)
/*! @} */

/*! @name DPI_CTRL - DPI Control Register */
/*! @{ */

#define DCIF_DPI_CTRL_HSYNC_POL_MASK             (0x1U)
#define DCIF_DPI_CTRL_HSYNC_POL_SHIFT            (0U)
/*! HSYNC_POL - Hsync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DCIF_DPI_CTRL_HSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_HSYNC_POL_SHIFT)) & DCIF_DPI_CTRL_HSYNC_POL_MASK)

#define DCIF_DPI_CTRL_VSYNC_POL_MASK             (0x2U)
#define DCIF_DPI_CTRL_VSYNC_POL_SHIFT            (1U)
/*! VSYNC_POL - Vsync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DCIF_DPI_CTRL_VSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_VSYNC_POL_SHIFT)) & DCIF_DPI_CTRL_VSYNC_POL_MASK)

#define DCIF_DPI_CTRL_DE_POL_MASK                (0x4U)
#define DCIF_DPI_CTRL_DE_POL_SHIFT               (2U)
/*! DE_POL - DE Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DCIF_DPI_CTRL_DE_POL(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DE_POL_SHIFT)) & DCIF_DPI_CTRL_DE_POL_MASK)

#define DCIF_DPI_CTRL_PCLK_EDGE_MASK             (0x8U)
#define DCIF_DPI_CTRL_PCLK_EDGE_SHIFT            (3U)
/*! PCLK_EDGE - PCLK Edge Select
 *  0b0..Pixel data is launched on the PCLK rising edge
 *  0b1..Pixel data is launched on the PCLK falling edge
 */
#define DCIF_DPI_CTRL_PCLK_EDGE(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_PCLK_EDGE_SHIFT)) & DCIF_DPI_CTRL_PCLK_EDGE_MASK)

#define DCIF_DPI_CTRL_DATA_INV_MASK              (0x10U)
#define DCIF_DPI_CTRL_DATA_INV_SHIFT             (4U)
/*! DATA_INV - Invert Pixel Data
 *  0b0..Not inverted
 *  0b1..Inverted
 */
#define DCIF_DPI_CTRL_DATA_INV(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DATA_INV_SHIFT)) & DCIF_DPI_CTRL_DATA_INV_MASK)

#define DCIF_DPI_CTRL_DEF_BGND_EN_MASK           (0x20U)
#define DCIF_DPI_CTRL_DEF_BGND_EN_SHIFT          (5U)
/*! DEF_BGND_EN - Enable Default BGND
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_DPI_CTRL_DEF_BGND_EN(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DEF_BGND_EN_SHIFT)) & DCIF_DPI_CTRL_DEF_BGND_EN_MASK)

#define DCIF_DPI_CTRL_DPI_CLK_DIS_MASK           (0x40U)
#define DCIF_DPI_CTRL_DPI_CLK_DIS_SHIFT          (6U)
/*! DPI_CLK_DIS - Disable DPI Clock Out
 *  0b0..DPI clock output is always on
 *  0b1..DPI clock output is gated
 */
#define DCIF_DPI_CTRL_DPI_CLK_DIS(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DPI_CLK_DIS_SHIFT)) & DCIF_DPI_CTRL_DPI_CLK_DIS_MASK)

#define DCIF_DPI_CTRL_FETCH_OPT_MASK             (0x300U)
#define DCIF_DPI_CTRL_FETCH_OPT_SHIFT            (8U)
/*! FETCH_OPT - Fetch Option
 *  0b00..Fetch start as soon as FP_V begins
 *  0b01..Fetch start as soon as PW_V begins
 *  0b10..Fetch start as soon as BP_V begins
 *  0b11..Reserved
 */
#define DCIF_DPI_CTRL_FETCH_OPT(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_FETCH_OPT_SHIFT)) & DCIF_DPI_CTRL_FETCH_OPT_MASK)

#define DCIF_DPI_CTRL_DISP_MODE_MASK             (0x3000U)
#define DCIF_DPI_CTRL_DISP_MODE_SHIFT            (12U)
/*! DISP_MODE - Display Mode
 *  0b00..Normal mode. panel content controlled by layer configurations
 *  0b01..Test Mode1(BGND Color Display)
 *  0b10..Test Mode2(Column Color Bar)
 *  0b11..Test Mode3(Row Color Bar)
 */
#define DCIF_DPI_CTRL_DISP_MODE(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DISP_MODE_SHIFT)) & DCIF_DPI_CTRL_DISP_MODE_MASK)

#define DCIF_DPI_CTRL_DATA_PATTERN_MASK          (0xF0000U)
#define DCIF_DPI_CTRL_DATA_PATTERN_SHIFT         (16U)
/*! DATA_PATTERN - Data Pattern
 *  0b0000..RGB
 *  0b0001..RBG
 *  0b0010..GBR
 *  0b0011..GRB
 *  0b0100..BRG
 *  0b0101..BGR
 *  0b0110..RGB555
 *  0b0111..RGB565
 *  0b1000..RGB666
 */
#define DCIF_DPI_CTRL_DATA_PATTERN(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_DATA_PATTERN_SHIFT)) & DCIF_DPI_CTRL_DATA_PATTERN_MASK)

#define DCIF_DPI_CTRL_TXFIFO_FILL_OPT_MASK       (0x30000000U)
#define DCIF_DPI_CTRL_TXFIFO_FILL_OPT_SHIFT      (28U)
/*! TXFIFO_FILL_OPT - Async TXFIFO Fill Option
 *  0b00..Start to fill async TX FIFO as soon as FP_V begins
 *  0b01..Start to fill async TX FIFO as soon as PW_V begins
 *  0b10..Start to fill async TX FIFO as soon as BP_V begins
 *  0b11..Start to fill async TX FIFO as soon as BP_V end
 */
#define DCIF_DPI_CTRL_TXFIFO_FILL_OPT(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_CTRL_TXFIFO_FILL_OPT_SHIFT)) & DCIF_DPI_CTRL_TXFIFO_FILL_OPT_MASK)
/*! @} */

/*! @name DPI_HSYN_PAR - DPI Horizontal Sync Parameter Register */
/*! @{ */

#define DCIF_DPI_HSYN_PAR_FP_H_MASK              (0xFFFU)
#define DCIF_DPI_HSYN_PAR_FP_H_SHIFT             (0U)
/*! FP_H - Horizontal Front Porch */
#define DCIF_DPI_HSYN_PAR_FP_H(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_HSYN_PAR_FP_H_SHIFT)) & DCIF_DPI_HSYN_PAR_FP_H_MASK)

#define DCIF_DPI_HSYN_PAR_BP_H_MASK              (0xFFF0000U)
#define DCIF_DPI_HSYN_PAR_BP_H_SHIFT             (16U)
/*! BP_H - Horizontal Back Porch */
#define DCIF_DPI_HSYN_PAR_BP_H(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_HSYN_PAR_BP_H_SHIFT)) & DCIF_DPI_HSYN_PAR_BP_H_MASK)
/*! @} */

/*! @name DPI_VSYN_PAR - DPI Vertical Sync Parameter Register */
/*! @{ */

#define DCIF_DPI_VSYN_PAR_FP_V_MASK              (0xFFFU)
#define DCIF_DPI_VSYN_PAR_FP_V_SHIFT             (0U)
/*! FP_V - Vertical Front Porch */
#define DCIF_DPI_VSYN_PAR_FP_V(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_VSYN_PAR_FP_V_SHIFT)) & DCIF_DPI_VSYN_PAR_FP_V_MASK)

#define DCIF_DPI_VSYN_PAR_BP_V_MASK              (0xFFF0000U)
#define DCIF_DPI_VSYN_PAR_BP_V_SHIFT             (16U)
/*! BP_V - Vertical Back Porch */
#define DCIF_DPI_VSYN_PAR_BP_V(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_VSYN_PAR_BP_V_SHIFT)) & DCIF_DPI_VSYN_PAR_BP_V_MASK)
/*! @} */

/*! @name DPI_VSYN_HSYN_WIDTH - DPI Vertical and Horizontal Pulse Width Parameter Register */
/*! @{ */

#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_H_MASK       (0xFFFU)
#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_H_SHIFT      (0U)
/*! PW_H - HSYNC Pulse Width */
#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_H(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_VSYN_HSYN_WIDTH_PW_H_SHIFT)) & DCIF_DPI_VSYN_HSYN_WIDTH_PW_H_MASK)

#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_V_MASK       (0xFFF0000U)
#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_V_SHIFT      (16U)
/*! PW_V - VSYNC Pulse Width */
#define DCIF_DPI_VSYN_HSYN_WIDTH_PW_V(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_DPI_VSYN_HSYN_WIDTH_PW_V_SHIFT)) & DCIF_DPI_VSYN_HSYN_WIDTH_PW_V_MASK)
/*! @} */

/*! @name GC_CTRL - Gamma Correction Control Register */
/*! @{ */

#define DCIF_GC_CTRL_GC_EN_MASK                  (0x1U)
#define DCIF_GC_CTRL_GC_EN_SHIFT                 (0U)
/*! GC_EN - Gamma Correction Enable
 *  0b0..No operations occur on the pixels
 *  0b1..The gamma correction operation takes place
 */
#define DCIF_GC_CTRL_GC_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_GC_CTRL_GC_EN_SHIFT)) & DCIF_GC_CTRL_GC_EN_MASK)

#define DCIF_GC_CTRL_GC_B_MASK_MASK              (0x20000000U)
#define DCIF_GC_CTRL_GC_B_MASK_SHIFT             (29U)
/*! GC_B_MASK - Gamma Correction Blue Table Access Mask
 *  0b0..Unmasked
 *  0b1..Not responding to write operations, and return 0 to read operation
 */
#define DCIF_GC_CTRL_GC_B_MASK(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_GC_CTRL_GC_B_MASK_SHIFT)) & DCIF_GC_CTRL_GC_B_MASK_MASK)

#define DCIF_GC_CTRL_GC_G_MASK_MASK              (0x40000000U)
#define DCIF_GC_CTRL_GC_G_MASK_SHIFT             (30U)
/*! GC_G_MASK - Gamma Correction Green Table Access Mask
 *  0b0..Unmasked
 *  0b1..Not responding to write operations, and return 0 to read operation
 */
#define DCIF_GC_CTRL_GC_G_MASK(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_GC_CTRL_GC_G_MASK_SHIFT)) & DCIF_GC_CTRL_GC_G_MASK_MASK)

#define DCIF_GC_CTRL_GC_R_MASK_MASK              (0x80000000U)
#define DCIF_GC_CTRL_GC_R_MASK_SHIFT             (31U)
/*! GC_R_MASK - Gamma Correction Red Table Access Mask
 *  0b0..Unmasked
 *  0b1..Not responding to write operations, and return 0 to read operation
 */
#define DCIF_GC_CTRL_GC_R_MASK(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_GC_CTRL_GC_R_MASK_SHIFT)) & DCIF_GC_CTRL_GC_R_MASK_MASK)
/*! @} */

/*! @name GC_SR - Gamma Correction Status Register */
/*! @{ */

#define DCIF_GC_SR_GC_ERR_ADDR_MASK              (0x3FFU)
#define DCIF_GC_SR_GC_ERR_ADDR_SHIFT             (0U)
/*! GC_ERR_ADDR - Gamma Correction Table Access Address When Access Transfer Error Occur */
#define DCIF_GC_SR_GC_ERR_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_GC_SR_GC_ERR_ADDR_SHIFT)) & DCIF_GC_SR_GC_ERR_ADDR_MASK)

#define DCIF_GC_SR_GC_XFR_STATUS_MASK            (0x80000000U)
#define DCIF_GC_SR_GC_XFR_STATUS_SHIFT           (31U)
/*! GC_XFR_STATUS - Gamma Correction Table Access Transfer Status
 *  0b0..Gamma table read and write operation completed
 *  0b1..Gamma table read and write operation failure. The write data of write operation will be ignored. The read
 *       data of the read operation is invalid.
 */
#define DCIF_GC_SR_GC_XFR_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_GC_SR_GC_XFR_STATUS_SHIFT)) & DCIF_GC_SR_GC_XFR_STATUS_MASK)
/*! @} */

/*! @name PDI_CTRL - PDI Control Register */
/*! @{ */

#define DCIF_PDI_CTRL_PDI_VSYNC_POL_MASK         (0x2U)
#define DCIF_PDI_CTRL_PDI_VSYNC_POL_SHIFT        (1U)
/*! PDI_VSYNC_POL - PDI Input Vsync Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DCIF_PDI_CTRL_PDI_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_VSYNC_POL_SHIFT)) & DCIF_PDI_CTRL_PDI_VSYNC_POL_MASK)

#define DCIF_PDI_CTRL_PDI_DE_POL_MASK            (0x4U)
#define DCIF_PDI_CTRL_PDI_DE_POL_SHIFT           (2U)
/*! PDI_DE_POL - PDI Input DE Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define DCIF_PDI_CTRL_PDI_DE_POL(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_DE_POL_SHIFT)) & DCIF_PDI_CTRL_PDI_DE_POL_MASK)

#define DCIF_PDI_CTRL_PDI_PCLK_EDGE_MASK         (0x8U)
#define DCIF_PDI_CTRL_PDI_PCLK_EDGE_SHIFT        (3U)
/*! PDI_PCLK_EDGE - PDI Input Pixel Clock Edge Select
 *  0b0..Pixel data is launched on the clock rising edge
 *  0b1..Pixel data is launched on the clock falling edge
 */
#define DCIF_PDI_CTRL_PDI_PCLK_EDGE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_PCLK_EDGE_SHIFT)) & DCIF_PDI_CTRL_PDI_PCLK_EDGE_MASK)

#define DCIF_PDI_CTRL_PDI_FETCH_OPT_MASK         (0x10U)
#define DCIF_PDI_CTRL_PDI_FETCH_OPT_SHIFT        (4U)
/*! PDI_FETCH_OPT - PDI Fetch Option
 *  0b0..No Skip
 *  0b1..Skip to fetch the first frame
 */
#define DCIF_PDI_CTRL_PDI_FETCH_OPT(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_FETCH_OPT_SHIFT)) & DCIF_PDI_CTRL_PDI_FETCH_OPT_MASK)

#define DCIF_PDI_CTRL_PDI_SEL_MASK               (0x10000U)
#define DCIF_PDI_CTRL_PDI_SEL_SHIFT              (16U)
/*! PDI_SEL - Select Layer For PDI Input
 *  0b0..Layer 0
 *  0b1..Layer 1
 */
#define DCIF_PDI_CTRL_PDI_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_SEL_SHIFT)) & DCIF_PDI_CTRL_PDI_SEL_MASK)

#define DCIF_PDI_CTRL_PDI_FORMAT_MASK            (0x700000U)
#define DCIF_PDI_CTRL_PDI_FORMAT_SHIFT           (20U)
/*! PDI_FORMAT - PDI Input Pixel Format
 *  0b000..RGB888
 *  0b001..RGB666
 *  0b010..RGB565
 *  0b011..RGB444
 *  0b100..RGB555
 *  0b101..YCbCr422 or YUV422 8-bit
 */
#define DCIF_PDI_CTRL_PDI_FORMAT(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_FORMAT_SHIFT)) & DCIF_PDI_CTRL_PDI_FORMAT_MASK)

#define DCIF_PDI_CTRL_PDI_SYNC_CTRL_MASK         (0x20000000U)
#define DCIF_PDI_CTRL_PDI_SYNC_CTRL_SHIFT        (29U)
/*! PDI_SYNC_CTRL - PDI Sync Control
 *  0b0..No action
 *  0b1..Keep the period of DPI HSYNC is stable
 */
#define DCIF_PDI_CTRL_PDI_SYNC_CTRL(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_SYNC_CTRL_SHIFT)) & DCIF_PDI_CTRL_PDI_SYNC_CTRL_MASK)

#define DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN_MASK    (0x40000000U)
#define DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN_SHIFT   (30U)
/*! PDI_SHADOW_LOAD_EN - PDI Shadow Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN_SHIFT)) & DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN_MASK)

#define DCIF_PDI_CTRL_PDI_EN_MASK                (0x80000000U)
#define DCIF_PDI_CTRL_PDI_EN_SHIFT               (31U)
/*! PDI_EN - PDI Enable
 *  0b0..Disable PDI input data
 *  0b1..Enable PDI input data
 */
#define DCIF_PDI_CTRL_PDI_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CTRL_PDI_EN_SHIFT)) & DCIF_PDI_CTRL_PDI_EN_MASK)
/*! @} */

/*! @name PDI_CNT - PDI Count Register */
/*! @{ */

#define DCIF_PDI_CNT_PDI_P_CNT_MASK              (0xFFFFFFU)
#define DCIF_PDI_CNT_PDI_P_CNT_SHIFT             (0U)
/*! PDI_P_CNT - PDI Pixel Count */
#define DCIF_PDI_CNT_PDI_P_CNT(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_CNT_PDI_P_CNT_SHIFT)) & DCIF_PDI_CNT_PDI_P_CNT_MASK)
/*! @} */

/*! @name PDI_TO_CNT - PDI Timeout Count Register */
/*! @{ */

#define DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT_MASK     (0x3FFFU)
#define DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT_SHIFT    (0U)
/*! PDI_TIMEOUT_CNT - PDI Timeout Count */
#define DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT_SHIFT)) & DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT_MASK)
/*! @} */

/*! @name FBD_CTRL - Frame Buffer Decompression Control Register */
/*! @{ */

#define DCIF_FBD_CTRL_FBD_DATA_PATTERN_MASK      (0xFU)
#define DCIF_FBD_CTRL_FBD_DATA_PATTERN_SHIFT     (0U)
/*! FBD_DATA_PATTERN - FBD Date Pattern
 *  0b1010..RGBA 16 bpp
 *  0b1011..RGB 12 bpp(same configuration as above, but no alpha channel present)
 *  0b1100..RGBA 13 bpp
 *  0b1101..RGB 10 bpp(same configuration as above, but no alpha channel present)
 *  0b1110..RGBA 11 bpp
 *  0b1111..RGB 8 bpp(same configuration as above, but no alpha channel present)
 */
#define DCIF_FBD_CTRL_FBD_DATA_PATTERN(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_FBD_CTRL_FBD_DATA_PATTERN_SHIFT)) & DCIF_FBD_CTRL_FBD_DATA_PATTERN_MASK)

#define DCIF_FBD_CTRL_FBD_SEL_MASK               (0x100U)
#define DCIF_FBD_CTRL_FBD_SEL_SHIFT              (8U)
/*! FBD_SEL - Selected Layer For FBD.
 *  0b0..Layer 0
 *  0b1..Layer 1
 */
#define DCIF_FBD_CTRL_FBD_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_FBD_CTRL_FBD_SEL_SHIFT)) & DCIF_FBD_CTRL_FBD_SEL_MASK)

#define DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN_MASK    (0x40000000U)
#define DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN_SHIFT   (30U)
/*! FBD_SHADOW_LOAD_EN - FBD Shadow Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN_SHIFT)) & DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN_MASK)

#define DCIF_FBD_CTRL_FBD_EN_MASK                (0x80000000U)
#define DCIF_FBD_CTRL_FBD_EN_SHIFT               (31U)
/*! FBD_EN - FBD enable
 *  0b0..No operations occur on the pixels
 *  0b1..The decompression operation takes place
 */
#define DCIF_FBD_CTRL_FBD_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_FBD_CTRL_FBD_EN_SHIFT)) & DCIF_FBD_CTRL_FBD_EN_MASK)
/*! @} */

/*! @name DBI_CTRL - DBI Control Register */
/*! @{ */

#define DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK          (0x1U)
#define DCIF_DBI_CTRL_DBI_CMD_TRIG_SHIFT         (0U)
/*! DBI_CMD_TRIG - Software Trigger For DBI Command
 *  0b0..Do not trigger
 *  0b1..Trigger
 */
#define DCIF_DBI_CTRL_DBI_CMD_TRIG(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_CMD_TRIG_SHIFT)) & DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK)

#define DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK          (0x6U)
#define DCIF_DBI_CTRL_DBI_CMD_TYPE_SHIFT         (1U)
/*! DBI_CMD_TYPE - DBI Command Type
 *  0b00..DBI Read Parameter
 *  0b01..DBI Write Command
 *  0b10..DBI Write Parameter
 *  0b11..DBI Write Pixel Data
 */
#define DCIF_DBI_CTRL_DBI_CMD_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_CMD_TYPE_SHIFT)) & DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK)

#define DCIF_DBI_CTRL_DBI_CSX_FORCE_MASK         (0x40U)
#define DCIF_DBI_CTRL_DBI_CSX_FORCE_SHIFT        (6U)
/*! DBI_CSX_FORCE - DBI CSX Force Control
 *  0b0..No force CSX
 *  0b1..Force CSX output to low
 */
#define DCIF_DBI_CTRL_DBI_CSX_FORCE(x)           (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_CSX_FORCE_SHIFT)) & DCIF_DBI_CTRL_DBI_CSX_FORCE_MASK)

#define DCIF_DBI_CTRL_DBI_TE_SYNC_MASK           (0x80U)
#define DCIF_DBI_CTRL_DBI_TE_SYNC_SHIFT          (7U)
/*! DBI_TE_SYNC - DBI TE (Tering Effect) Input Sync Enable
 *  0b0..No Sync Action
 *  0b1..Sync DBI Write Pixel Data Command by TE
 */
#define DCIF_DBI_CTRL_DBI_TE_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_TE_SYNC_SHIFT)) & DCIF_DBI_CTRL_DBI_TE_SYNC_MASK)

#define DCIF_DBI_CTRL_DBI_TYPE_MASK              (0x300U)
#define DCIF_DBI_CTRL_DBI_TYPE_SHIFT             (8U)
/*! DBI_TYPE - DBI Type
 *  0b00..DBI Type A Interface, Clocked E Mode
 *  0b01..DBI Type A Interface, Fixed E Mode
 *  0b10..DBI Type B Interface
 *  0b11..Reserved
 */
#define DCIF_DBI_CTRL_DBI_TYPE(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_TYPE_SHIFT)) & DCIF_DBI_CTRL_DBI_TYPE_MASK)

#define DCIF_DBI_CTRL_DBI_DATA_PATTERN_MASK      (0x7800U)
#define DCIF_DBI_CTRL_DBI_DATA_PATTERN_SHIFT     (11U)
/*! DBI_DATA_PATTERN - DBI Data Pattern
 *  0b0000..RGB332, used for DBI Type A and Type B 8-bit interface
 *  0b0001..RGB332, used for DBI Type A and Type B 16-bit interface
 *  0b0010..RGB444, used for DBI Type A and Type B 8-bit interface
 *  0b0011..RGB444, used for DBI Type A and Type B 16-bit interface
 *  0b0100..RGB565, used for DBI Type A and Type B 8-bit interface
 *  0b0101..RGB565, used for DBI Type A and Type B 16-bit interface
 *  0b0110..RGB666, used for DBI Type A and Type B 8-bit interface
 *  0b0111..RGB666, used for DBI Type A and Type B 9-bit interface
 *  0b1000..RGB666, used for DBI Type A and Type B 16-bit interface, option 1
 *  0b1001..RGB666, used for DBI Type A and Type B 16-bit interface, option 2
 *  0b1010..RGB888, used for DBI Type A and Type B 8-bit interface
 *  0b1011..RGB888, used for DBI Type A and Type B 16-bit interface, option 1
 *  0b1100..RGB888, used for DBI Type A and Type B 16-bit interface, option 2
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define DCIF_DBI_CTRL_DBI_DATA_PATTERN(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_DATA_PATTERN_SHIFT)) & DCIF_DBI_CTRL_DBI_DATA_PATTERN_MASK)

#define DCIF_DBI_CTRL_DBI_WDATA_MASK             (0xFFFF0000U)
#define DCIF_DBI_CTRL_DBI_WDATA_SHIFT            (16U)
/*! DBI_WDATA - DBI Write Data */
#define DCIF_DBI_CTRL_DBI_WDATA(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_CTRL_DBI_WDATA_SHIFT)) & DCIF_DBI_CTRL_DBI_WDATA_MASK)
/*! @} */

/*! @name DBI_PAR0 - DBI Parameter 0 Register */
/*! @{ */

#define DCIF_DBI_PAR0_WEL_MASK                   (0x7FU)
#define DCIF_DBI_PAR0_WEL_SHIFT                  (0U)
/*! WEL - WRX Low Time */
#define DCIF_DBI_PAR0_WEL(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR0_WEL_SHIFT)) & DCIF_DBI_PAR0_WEL_MASK)

#define DCIF_DBI_PAR0_WEH_MASK                   (0x7F00U)
#define DCIF_DBI_PAR0_WEH_SHIFT                  (8U)
/*! WEH - WRX High Time */
#define DCIF_DBI_PAR0_WEH(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR0_WEH_SHIFT)) & DCIF_DBI_PAR0_WEH_MASK)

#define DCIF_DBI_PAR0_REL_MASK                   (0x7F0000U)
#define DCIF_DBI_PAR0_REL_SHIFT                  (16U)
/*! REL - RDX Low Time */
#define DCIF_DBI_PAR0_REL(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR0_REL_SHIFT)) & DCIF_DBI_PAR0_REL_MASK)

#define DCIF_DBI_PAR0_REH_MASK                   (0x7F000000U)
#define DCIF_DBI_PAR0_REH_SHIFT                  (24U)
/*! REH - RDX High Time */
#define DCIF_DBI_PAR0_REH(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR0_REH_SHIFT)) & DCIF_DBI_PAR0_REH_MASK)
/*! @} */

/*! @name DBI_PAR1 - DBI Parameter 1 Register */
/*! @{ */

#define DCIF_DBI_PAR1_CES_MASK                   (0xFU)
#define DCIF_DBI_PAR1_CES_SHIFT                  (0U)
/*! CES - CSX Setup Time */
#define DCIF_DBI_PAR1_CES(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR1_CES_SHIFT)) & DCIF_DBI_PAR1_CES_MASK)

#define DCIF_DBI_PAR1_CEH_MASK                   (0xF00U)
#define DCIF_DBI_PAR1_CEH_SHIFT                  (8U)
/*! CEH - CSX Hold Time */
#define DCIF_DBI_PAR1_CEH(x)                     (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR1_CEH_SHIFT)) & DCIF_DBI_PAR1_CEH_MASK)

#define DCIF_DBI_PAR1_TXFIFO_THRES_MASK          (0x7F0000U)
#define DCIF_DBI_PAR1_TXFIFO_THRES_SHIFT         (16U)
/*! TXFIFO_THRES - Async TX FIFO Threshold */
#define DCIF_DBI_PAR1_TXFIFO_THRES(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_PAR1_TXFIFO_THRES_SHIFT)) & DCIF_DBI_PAR1_TXFIFO_THRES_MASK)
/*! @} */

/*! @name DBI_SR - DBI Status Register */
/*! @{ */

#define DCIF_DBI_SR_DBI_RDATA_MASK               (0xFFFF0000U)
#define DCIF_DBI_SR_DBI_RDATA_SHIFT              (16U)
/*! DBI_RDATA - DBI Read Data Register */
#define DCIF_DBI_SR_DBI_RDATA(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_DBI_SR_DBI_RDATA_SHIFT)) & DCIF_DBI_SR_DBI_RDATA_MASK)
/*! @} */

/*! @name TXPKTIF_CTRL - TX Packet Interface Control Register */
/*! @{ */

#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_MASK  (0x1U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_SHIFT (0U)
/*! TXPKTIF_CMD_TRIG - Software Trigger For TX Packet Interface Command
 *  0b0..Do not trigger
 *  0b1..Trigger
 */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG(x)    (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_MASK  (0x6U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_SHIFT (1U)
/*! TXPKTIF_CMD_TYPE - TX Packet Interface Command Type
 *  0b00..TX Packet Interface Write Pixel Data Command(DCS command 0x2C, 0x3C)
 *  0b01..TX Packet Interface Set Column Address Command(DCS command 0x2A) + Write Pixel Data Command(DCS command 0x2C, 0x3C)
 *  0b10..TX Packet Interface Set Page Address Command(DCS command 0x2B) + Write Pixel Data Command(DCS command 0x2C, 0x3C)
 *  0b11..TX Packet Interface Set Column Address Command(DCS command 0x2A) + Set Page Address Command(DCS command
 *        0x2B) + Write Pixel Data Command(DCS command 0x2C, 0x3C)
 */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_VC_MASK        (0x30U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_VC_SHIFT       (4U)
/*! TXPKTIF_VC - TX Packet Interface Virtual Channel Number */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_VC(x)          (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_VC_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_VC_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_HS_MODE_MASK   (0x40U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_HS_MODE_SHIFT  (6U)
/*! TXPKTIF_HS_MODE - TX Packet Interface High Speed Data Transfer Mode Enable
 *  0b0..Low Power Mode
 *  0b1..High Speed Mode
 */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_HS_MODE(x)     (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_HS_MODE_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_HS_MODE_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_TE_SYNC_MASK   (0x80U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_TE_SYNC_SHIFT  (7U)
/*! TXPKTIF_TE_SYNC - TX Packet Interface TE(Tering Effect) Input Sync Enable
 *  0b0..No Sync Action
 *  0b1..Sync Write Pixel Data Command by TE
 */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_TE_SYNC(x)     (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_TE_SYNC_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_TE_SYNC_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN_MASK (0x700U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN_SHIFT (8U)
/*! TXPKTIF_DATA_PATTERN - TX Packet Interface Data Pattern
 *  0b000..RGB565, LS byte is transferred first
 *  0b001..RGB565, MS byte is transferred first
 *  0b010..BGR565, LS byte is transferred first
 *  0b011..BGR565, MS byte is transferred first
 *  0b100..RGB888
 *  0b101..BGR888
 */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN(x) (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_DATA_PATTERN_MASK)

#define DCIF_TXPKTIF_CTRL_CMD_REQ_MODE_MASK      (0x8000U)
#define DCIF_TXPKTIF_CTRL_CMD_REQ_MODE_SHIFT     (15U)
/*! CMD_REQ_MODE - TX Packet Interface Command Request Mode
 *  0b0..Continuous mode, command request will be sent regardless of whether the previous request has been completed.
 *  0b1..Wait mode, pkt_tx_cmd_valid will deassert after receiving command request acknowledge, pkt_tx_cmd_valid
 *       will reassert after the previous request has been completed.
 */
#define DCIF_TXPKTIF_CTRL_CMD_REQ_MODE(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_CMD_REQ_MODE_SHIFT)) & DCIF_TXPKTIF_CTRL_CMD_REQ_MODE_MASK)

#define DCIF_TXPKTIF_CTRL_TXPKTIF_BCNT_MASK      (0xFFFF0000U)
#define DCIF_TXPKTIF_CTRL_TXPKTIF_BCNT_SHIFT     (16U)
/*! TXPKTIF_BCNT - TX Packet Interface Transmit Packet Payload Byte Count */
#define DCIF_TXPKTIF_CTRL_TXPKTIF_BCNT(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_CTRL_TXPKTIF_BCNT_SHIFT)) & DCIF_TXPKTIF_CTRL_TXPKTIF_BCNT_MASK)
/*! @} */

/*! @name TXPKTIF_PAR0 - TX Packet Interface Parameter 0 Register */
/*! @{ */

#define DCIF_TXPKTIF_PAR0_SC_MASK                (0xFFFFU)
#define DCIF_TXPKTIF_PAR0_SC_SHIFT               (0U)
/*! SC - Column Start Address */
#define DCIF_TXPKTIF_PAR0_SC(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_PAR0_SC_SHIFT)) & DCIF_TXPKTIF_PAR0_SC_MASK)

#define DCIF_TXPKTIF_PAR0_EC_MASK                (0xFFFF0000U)
#define DCIF_TXPKTIF_PAR0_EC_SHIFT               (16U)
/*! EC - Column End Address */
#define DCIF_TXPKTIF_PAR0_EC(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_PAR0_EC_SHIFT)) & DCIF_TXPKTIF_PAR0_EC_MASK)
/*! @} */

/*! @name TXPKTIF_PAR1 - TX Packet Interface Parameter 1 Register */
/*! @{ */

#define DCIF_TXPKTIF_PAR1_SP_MASK                (0xFFFFU)
#define DCIF_TXPKTIF_PAR1_SP_SHIFT               (0U)
/*! SP - Page Start Address */
#define DCIF_TXPKTIF_PAR1_SP(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_PAR1_SP_SHIFT)) & DCIF_TXPKTIF_PAR1_SP_MASK)

#define DCIF_TXPKTIF_PAR1_EP_MASK                (0xFFFF0000U)
#define DCIF_TXPKTIF_PAR1_EP_SHIFT               (16U)
/*! EP - Page End Address */
#define DCIF_TXPKTIF_PAR1_EP(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_PAR1_EP_SHIFT)) & DCIF_TXPKTIF_PAR1_EP_MASK)
/*! @} */

/*! @name TXPKTIF_THRES - TX Packet Interface Threshold Register */
/*! @{ */

#define DCIF_TXPKTIF_THRES_TXFIFO_THRES_MASK     (0x7FU)
#define DCIF_TXPKTIF_THRES_TXFIFO_THRES_SHIFT    (0U)
/*! TXFIFO_THRES - Async TX FIFO Threshold */
#define DCIF_TXPKTIF_THRES_TXFIFO_THRES(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_THRES_TXFIFO_THRES_SHIFT)) & DCIF_TXPKTIF_THRES_TXFIFO_THRES_MASK)
/*! @} */

/*! @name TXPKTIF_TO_CNT - TX Packet Interface Timeout Count Register */
/*! @{ */

#define DCIF_TXPKTIF_TO_CNT_TIMEOUT_CNT_MASK     (0x1FFFU)
#define DCIF_TXPKTIF_TO_CNT_TIMEOUT_CNT_SHIFT    (0U)
/*! TIMEOUT_CNT - TX Packet Interface Timeout Count */
#define DCIF_TXPKTIF_TO_CNT_TIMEOUT_CNT(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_TO_CNT_TIMEOUT_CNT_SHIFT)) & DCIF_TXPKTIF_TO_CNT_TIMEOUT_CNT_MASK)
/*! @} */

/*! @name TXPKTIF_SR0 - TX Packet Interface Status Register 0 */
/*! @{ */

#define DCIF_TXPKTIF_SR0_REQ_DATA_LEFT_MASK      (0x3FFFFFFU)
#define DCIF_TXPKTIF_SR0_REQ_DATA_LEFT_SHIFT     (0U)
/*! REQ_DATA_LEFT - TX Packet Interface Command Request Pixel Data Left */
#define DCIF_TXPKTIF_SR0_REQ_DATA_LEFT(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_SR0_REQ_DATA_LEFT_SHIFT)) & DCIF_TXPKTIF_SR0_REQ_DATA_LEFT_MASK)
/*! @} */

/*! @name TXPKTIF_SR1 - TX Packet Interface Status Register 1 */
/*! @{ */

#define DCIF_TXPKTIF_SR1_PAYLOAD_DATA_LEFT_MASK  (0x3FFFFFFU)
#define DCIF_TXPKTIF_SR1_PAYLOAD_DATA_LEFT_SHIFT (0U)
/*! PAYLOAD_DATA_LEFT - TX Packet Interface Command Response Payload Data Left */
#define DCIF_TXPKTIF_SR1_PAYLOAD_DATA_LEFT(x)    (((uint32_t)(((uint32_t)(x)) << DCIF_TXPKTIF_SR1_PAYLOAD_DATA_LEFT_SHIFT)) & DCIF_TXPKTIF_SR1_PAYLOAD_DATA_LEFT_MASK)
/*! @} */

/*! @name CSC_CTRL - Color Space Conversion 0 Control Register..Color Space Conversion 1 Control Register */
/*! @{ */

#define DCIF_CSC_CTRL_CSC_EN_MASK                (0x1U)
#define DCIF_CSC_CTRL_CSC_EN_SHIFT               (0U)
/*! CSC_EN - CSC Enable
 *  0b0..No operations occur on the pixels
 *  0b1..The selected CSC operation takes place
 */
#define DCIF_CSC_CTRL_CSC_EN(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_CTRL_CSC_EN_SHIFT)) & DCIF_CSC_CTRL_CSC_EN_MASK)

#define DCIF_CSC_CTRL_CSC_MODE_MASK              (0x2U)
#define DCIF_CSC_CTRL_CSC_MODE_SHIFT             (1U)
/*! CSC_MODE - CSC Mode
 *  0b0..Convert from YUV to RGB
 *  0b1..Convert from YCbCr to RGB
 */
#define DCIF_CSC_CTRL_CSC_MODE(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_CTRL_CSC_MODE_SHIFT)) & DCIF_CSC_CTRL_CSC_MODE_MASK)
/*! @} */

/* The count of DCIF_CSC_CTRL */
#define DCIF_CSC_CTRL_COUNT                      (2U)

/*! @name CSC_COEF - Color Space Conversion 0 Coefficient Register 0..Color Space Conversion 1 Coefficient Register 5 */
/*! @{ */

#define DCIF_CSC_COEF_A1_MASK                    (0x7FFU)
#define DCIF_CSC_COEF_A1_SHIFT                   (0U)
/*! A1 - Coefficient A1 */
#define DCIF_CSC_COEF_A1(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_A1_SHIFT)) & DCIF_CSC_COEF_A1_MASK)

#define DCIF_CSC_COEF_A3_MASK                    (0x7FFU)
#define DCIF_CSC_COEF_A3_SHIFT                   (0U)
/*! A3 - Coefficient A3 */
#define DCIF_CSC_COEF_A3(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_A3_SHIFT)) & DCIF_CSC_COEF_A3_MASK)

#define DCIF_CSC_COEF_B2_MASK                    (0x7FFU)
#define DCIF_CSC_COEF_B2_SHIFT                   (0U)
/*! B2 - Coefficient B2 */
#define DCIF_CSC_COEF_B2(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_B2_SHIFT)) & DCIF_CSC_COEF_B2_MASK)

#define DCIF_CSC_COEF_C1_MASK                    (0x7FFU)
#define DCIF_CSC_COEF_C1_SHIFT                   (0U)
/*! C1 - Coefficient C1 */
#define DCIF_CSC_COEF_C1(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_C1_SHIFT)) & DCIF_CSC_COEF_C1_MASK)

#define DCIF_CSC_COEF_C3_MASK                    (0x7FFU)
#define DCIF_CSC_COEF_C3_SHIFT                   (0U)
/*! C3 - Coefficient C3 */
#define DCIF_CSC_COEF_C3(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_C3_SHIFT)) & DCIF_CSC_COEF_C3_MASK)

#define DCIF_CSC_COEF_D2_MASK                    (0x1FFU)
#define DCIF_CSC_COEF_D2_SHIFT                   (0U)
/*! D2 - Coefficient D2 */
#define DCIF_CSC_COEF_D2(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_D2_SHIFT)) & DCIF_CSC_COEF_D2_MASK)

#define DCIF_CSC_COEF_A2_MASK                    (0x7FF0000U)
#define DCIF_CSC_COEF_A2_SHIFT                   (16U)
/*! A2 - Coefficient A2 */
#define DCIF_CSC_COEF_A2(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_A2_SHIFT)) & DCIF_CSC_COEF_A2_MASK)

#define DCIF_CSC_COEF_B1_MASK                    (0x7FF0000U)
#define DCIF_CSC_COEF_B1_SHIFT                   (16U)
/*! B1 - Coefficient B1 */
#define DCIF_CSC_COEF_B1(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_B1_SHIFT)) & DCIF_CSC_COEF_B1_MASK)

#define DCIF_CSC_COEF_B3_MASK                    (0x7FF0000U)
#define DCIF_CSC_COEF_B3_SHIFT                   (16U)
/*! B3 - Coefficient B3 */
#define DCIF_CSC_COEF_B3(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_B3_SHIFT)) & DCIF_CSC_COEF_B3_MASK)

#define DCIF_CSC_COEF_C2_MASK                    (0x7FF0000U)
#define DCIF_CSC_COEF_C2_SHIFT                   (16U)
/*! C2 - Coefficient C2 */
#define DCIF_CSC_COEF_C2(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_C2_SHIFT)) & DCIF_CSC_COEF_C2_MASK)

#define DCIF_CSC_COEF_D1_MASK                    (0x1FF0000U)
#define DCIF_CSC_COEF_D1_SHIFT                   (16U)
/*! D1 - Coefficient D1 */
#define DCIF_CSC_COEF_D1(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_D1_SHIFT)) & DCIF_CSC_COEF_D1_MASK)

#define DCIF_CSC_COEF_D3_MASK                    (0x1FF0000U)
#define DCIF_CSC_COEF_D3_SHIFT                   (16U)
/*! D3 - Coefficient D3 */
#define DCIF_CSC_COEF_D3(x)                      (((uint32_t)(((uint32_t)(x)) << DCIF_CSC_COEF_D3_SHIFT)) & DCIF_CSC_COEF_D3_MASK)
/*! @} */

/* The count of DCIF_CSC_COEF */
#define DCIF_CSC_COEF_COUNT                      (2U)

/* The count of DCIF_CSC_COEF */
#define DCIF_CSC_COEF_COUNT2                     (6U)

/*! @name CTRLDESC_L - Control Descriptor Register 0 for Layer 0..Control Descriptor Register 7 for Layer 7 */
/*! @{ */

#define DCIF_CTRLDESC_L_AB_MODE_MASK             (0x3U)
#define DCIF_CTRLDESC_L_AB_MODE_SHIFT            (0U)
/*! AB_MODE - Alpha Blending Mode
 *  0b00..Blend with embedded ALPHA
 *  0b01..Blend with global ALPHA
 *  0b10..Reserved
 *  0b11..Blend with Porter Duff enable
 */
#define DCIF_CTRLDESC_L_AB_MODE(x)               (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_AB_MODE_SHIFT)) & DCIF_CTRLDESC_L_AB_MODE_MASK)

#define DCIF_CTRLDESC_L_ADDR_MASK                (0xFFFFFFFFU)
#define DCIF_CTRLDESC_L_ADDR_SHIFT               (0U)
/*! ADDR - Layer Low Address */
#define DCIF_CTRLDESC_L_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_ADDR_SHIFT)) & DCIF_CTRLDESC_L_ADDR_MASK)

#define DCIF_CTRLDESC_L_BCLR_B_MASK              (0xFFU)
#define DCIF_CTRLDESC_L_BCLR_B_SHIFT             (0U)
/*! BCLR_B - Layer Background Blue Component */
#define DCIF_CTRLDESC_L_BCLR_B(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_BCLR_B_SHIFT)) & DCIF_CTRLDESC_L_BCLR_B_MASK)

#define DCIF_CTRLDESC_L_PITCH_MASK               (0xFFFFU)
#define DCIF_CTRLDESC_L_PITCH_SHIFT              (0U)
/*! PITCH - Pitch Size */
#define DCIF_CTRLDESC_L_PITCH(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_PITCH_SHIFT)) & DCIF_CTRLDESC_L_PITCH_MASK)

#define DCIF_CTRLDESC_L_POSX_MASK                (0xFFFU)
#define DCIF_CTRLDESC_L_POSX_SHIFT               (0U)
/*! POSX - Horizontal Position */
#define DCIF_CTRLDESC_L_POSX(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_POSX_SHIFT)) & DCIF_CTRLDESC_L_POSX_MASK)

#define DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE_MASK   (0x3U)
#define DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE_SHIFT  (0U)
/*! S0_S1_FACTOR_MODE - S0_S1_FACTOR_MODE
 *  0b00..using 1
 *  0b01..using 0
 *  0b10..using straight alpha
 *  0b11..using inverse alpha
 */
#define DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(x)     (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE_SHIFT)) & DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE_MASK)

#define DCIF_CTRLDESC_L_WIDTH_MASK               (0xFFFU)
#define DCIF_CTRLDESC_L_WIDTH_SHIFT              (0U)
/*! WIDTH - Width */
#define DCIF_CTRLDESC_L_WIDTH(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_WIDTH_SHIFT)) & DCIF_CTRLDESC_L_WIDTH_MASK)

#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE_MASK (0xCU)
#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE_SHIFT (2U)
/*! S0_GLOBAL_ALPHA_MODE - S0_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha
 *  0b01..using embedded alpha
 *  0b10..using scaled alpha
 *  0b11..Reserved
 */
#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE(x)  (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE_SHIFT)) & DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE_MASK)

#define DCIF_CTRLDESC_L_S0_ALPHA_MODE_MASK       (0x10U)
#define DCIF_CTRLDESC_L_S0_ALPHA_MODE_SHIFT      (4U)
/*! S0_ALPHA_MODE - S0_ALPHA_MODE
 *  0b0..straight mode for s0 alpha
 *  0b1..inverse mode for s0 alpha
 */
#define DCIF_CTRLDESC_L_S0_ALPHA_MODE(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S0_ALPHA_MODE_SHIFT)) & DCIF_CTRLDESC_L_S0_ALPHA_MODE_MASK)

#define DCIF_CTRLDESC_L_S0_COLOR_MODE_MASK       (0x20U)
#define DCIF_CTRLDESC_L_S0_COLOR_MODE_SHIFT      (5U)
/*! S0_COLOR_MODE - S0_COLOR_MODE
 *  0b0..straight mode for s0 color
 *  0b1..multiply mode for s0 color
 */
#define DCIF_CTRLDESC_L_S0_COLOR_MODE(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S0_COLOR_MODE_SHIFT)) & DCIF_CTRLDESC_L_S0_COLOR_MODE_MASK)

#define DCIF_CTRLDESC_L_BCLR_G_MASK              (0xFF00U)
#define DCIF_CTRLDESC_L_BCLR_G_SHIFT             (8U)
/*! BCLR_G - Layer Background Green Component */
#define DCIF_CTRLDESC_L_BCLR_G(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_BCLR_G_SHIFT)) & DCIF_CTRLDESC_L_BCLR_G_MASK)

#define DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE_MASK   (0x300U)
#define DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE_SHIFT  (8U)
/*! S1_S0_FACTOR_MODE - S1_S0_FACTOR_MODE
 *  0b00..using 1
 *  0b01..using 0
 *  0b10..using straight alpha
 *  0b11..using inverse alpha
 */
#define DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(x)     (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE_SHIFT)) & DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE_MASK)

#define DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! S1_GLOBAL_ALPHA_MODE - S1_GLOBAL_ALPHA_MODE
 *  0b00..using global alpha
 *  0b01..using embedded alpha
 *  0b10..using scaled alpha
 *  0b11..Reserved
 */
#define DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE(x)  (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE_SHIFT)) & DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE_MASK)

#define DCIF_CTRLDESC_L_S1_ALPHA_MODE_MASK       (0x1000U)
#define DCIF_CTRLDESC_L_S1_ALPHA_MODE_SHIFT      (12U)
/*! S1_ALPHA_MODE - S1_ALPHA_MODE
 *  0b0..straight mode for s1 alpha
 *  0b1..inverse mode for s1 alpha
 */
#define DCIF_CTRLDESC_L_S1_ALPHA_MODE(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S1_ALPHA_MODE_SHIFT)) & DCIF_CTRLDESC_L_S1_ALPHA_MODE_MASK)

#define DCIF_CTRLDESC_L_S1_COLOR_MODE_MASK       (0x2000U)
#define DCIF_CTRLDESC_L_S1_COLOR_MODE_SHIFT      (13U)
/*! S1_COLOR_MODE - S1_COLOR_MODE
 *  0b0..straight mode for s1 color
 *  0b1..multiply mode for s1 color
 */
#define DCIF_CTRLDESC_L_S1_COLOR_MODE(x)         (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S1_COLOR_MODE_SHIFT)) & DCIF_CTRLDESC_L_S1_COLOR_MODE_MASK)

#define DCIF_CTRLDESC_L_YUV_FORMAT_MASK          (0xC000U)
#define DCIF_CTRLDESC_L_YUV_FORMAT_SHIFT         (14U)
/*! YUV_FORMAT - YUV Format
 *  0b00..YUV format option 0
 *  0b01..YUV format option 1
 *  0b10..YUV format option 2
 *  0b11..YUV format option 3
 */
#define DCIF_CTRLDESC_L_YUV_FORMAT(x)            (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_YUV_FORMAT_SHIFT)) & DCIF_CTRLDESC_L_YUV_FORMAT_MASK)

#define DCIF_CTRLDESC_L_BCLR_PD_CTRL_MASK        (0x8000U)
#define DCIF_CTRLDESC_L_BCLR_PD_CTRL_SHIFT       (15U)
/*! BCLR_PD_CTRL - BCLR Porter Duff Blending Control
 *  0b0..BCLR is blended in porter-duff blend mode
 *  0b1..BCLR is blended in normal blend mode
 */
#define DCIF_CTRLDESC_L_BCLR_PD_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_BCLR_PD_CTRL_SHIFT)) & DCIF_CTRLDESC_L_BCLR_PD_CTRL_MASK)

#define DCIF_CTRLDESC_L_POSX_SIGN_MASK           (0x8000U)
#define DCIF_CTRLDESC_L_POSX_SIGN_SHIFT          (15U)
/*! POSX_SIGN - The Sign Of The POSX
 *  0b0..Positive
 *  0b1..Negative
 */
#define DCIF_CTRLDESC_L_POSX_SIGN(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_POSX_SIGN_SHIFT)) & DCIF_CTRLDESC_L_POSX_SIGN_MASK)

#define DCIF_CTRLDESC_L_BCLR_R_MASK              (0xFF0000U)
#define DCIF_CTRLDESC_L_BCLR_R_SHIFT             (16U)
/*! BCLR_R - Layer Background Red Component */
#define DCIF_CTRLDESC_L_BCLR_R(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_BCLR_R_SHIFT)) & DCIF_CTRLDESC_L_BCLR_R_MASK)

#define DCIF_CTRLDESC_L_GLOBAL_ALPHA_MASK        (0xFF0000U)
#define DCIF_CTRLDESC_L_GLOBAL_ALPHA_SHIFT       (16U)
/*! GLOBAL_ALPHA - Global Alpha */
#define DCIF_CTRLDESC_L_GLOBAL_ALPHA(x)          (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_GLOBAL_ALPHA_SHIFT)) & DCIF_CTRLDESC_L_GLOBAL_ALPHA_MASK)

#define DCIF_CTRLDESC_L_HEIGHT_MASK              (0xFFF0000U)
#define DCIF_CTRLDESC_L_HEIGHT_SHIFT             (16U)
/*! HEIGHT - Height */
#define DCIF_CTRLDESC_L_HEIGHT(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_HEIGHT_SHIFT)) & DCIF_CTRLDESC_L_HEIGHT_MASK)

#define DCIF_CTRLDESC_L_POSY_MASK                (0xFFF0000U)
#define DCIF_CTRLDESC_L_POSY_SHIFT               (16U)
/*! POSY - Vertical Position */
#define DCIF_CTRLDESC_L_POSY(x)                  (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_POSY_SHIFT)) & DCIF_CTRLDESC_L_POSY_MASK)

#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MASK     (0xFF0000U)
#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_SHIFT    (16U)
/*! S0_GLOBAL_ALPHA - S0_GLOBAL_ALPHA */
#define DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_SHIFT)) & DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MASK)

#define DCIF_CTRLDESC_L_T_SIZE_MASK              (0x30000U)
#define DCIF_CTRLDESC_L_T_SIZE_SHIFT             (16U)
/*! T_SIZE - Transaction Size
 *  0b00..64 bytes
 *  0b01..128 bytes
 *  0b10..256 bytes
 *  0b11..Reserved
 */
#define DCIF_CTRLDESC_L_T_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_T_SIZE_SHIFT)) & DCIF_CTRLDESC_L_T_SIZE_MASK)

#define DCIF_CTRLDESC_L_P_SIZE_MASK              (0x700000U)
#define DCIF_CTRLDESC_L_P_SIZE_SHIFT             (20U)
/*! P_SIZE - Payload Size
 *  0b000..64 bytes
 *  0b001..128 bytes
 *  0b010..256 bytes
 *  0b011..512 bytes
 *  0b100..Reserved
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define DCIF_CTRLDESC_L_P_SIZE(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_P_SIZE_SHIFT)) & DCIF_CTRLDESC_L_P_SIZE_MASK)

#define DCIF_CTRLDESC_L_BCLR_A_MASK              (0xFF000000U)
#define DCIF_CTRLDESC_L_BCLR_A_SHIFT             (24U)
/*! BCLR_A - Layer Background Alpha Component */
#define DCIF_CTRLDESC_L_BCLR_A(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_BCLR_A_SHIFT)) & DCIF_CTRLDESC_L_BCLR_A_MASK)

#define DCIF_CTRLDESC_L_FORMAT_MASK              (0xF000000U)
#define DCIF_CTRLDESC_L_FORMAT_SHIFT             (24U)
/*! FORMAT - Layer Format
 *  0b0000..indexed color format - 1 bpp
 *  0b0001..indexed color format - 2 bpp
 *  0b0010..indexed color format - 4 bpp
 *  0b0011..indexed color format - 8 bpp
 *  0b0100..RGB565
 *  0b0101..ARGB1555
 *  0b0110..ARGB4444
 *  0b0111..YCbCr422 or YUV422 8-bit(only for layer 0 ~ layer 1 )
 *  0b1000..RGB888
 *  0b1001..ARGB8888
 *  0b1010..ABGR8888
 *  0b1011..BGR888
 *  0b1100..YCbCr420 or YUV420 8-bit(only for layer 0 ~ layer 1 )
 *  0b1101..YCbCr444 or YUV444 8-bit(only for layer 0 ~ layer 1 )
 */
#define DCIF_CTRLDESC_L_FORMAT(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_FORMAT_SHIFT)) & DCIF_CTRLDESC_L_FORMAT_MASK)

#define DCIF_CTRLDESC_L_SHADOW_LOAD_EN_MASK      (0x40000000U)
#define DCIF_CTRLDESC_L_SHADOW_LOAD_EN_SHIFT     (30U)
/*! SHADOW_LOAD_EN - Shadow Load Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_CTRLDESC_L_SHADOW_LOAD_EN(x)        (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_SHADOW_LOAD_EN_SHIFT)) & DCIF_CTRLDESC_L_SHADOW_LOAD_EN_MASK)

#define DCIF_CTRLDESC_L_EN_MASK                  (0x80000000U)
#define DCIF_CTRLDESC_L_EN_SHIFT                 (31U)
/*! EN - Layer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_CTRLDESC_L_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_EN_SHIFT)) & DCIF_CTRLDESC_L_EN_MASK)

#define DCIF_CTRLDESC_L_POSY_SIGN_MASK           (0x80000000U)
#define DCIF_CTRLDESC_L_POSY_SIGN_SHIFT          (31U)
/*! POSY_SIGN - The Sign Of The POSY
 *  0b0..Positive
 *  0b1..Negative
 */
#define DCIF_CTRLDESC_L_POSY_SIGN(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_CTRLDESC_L_POSY_SIGN_SHIFT)) & DCIF_CTRLDESC_L_POSY_SIGN_MASK)
/*! @} */

/* The count of DCIF_CTRLDESC_L */
#define DCIF_CTRLDESC_L_COUNT                    (8U)

/* The count of DCIF_CTRLDESC_L */
#define DCIF_CTRLDESC_L_COUNT2                   (8U)

/*! @name IE_D - Interrupt Enable Register 0 for Domain 1..Interrupt Enable Register 1 for Domain 8 */
/*! @{ */

#define DCIF_IE_D_FIFO_PANIC_EN0_MASK            (0x1U)
#define DCIF_IE_D_FIFO_PANIC_EN0_SHIFT           (0U)
/*! FIFO_PANIC_EN0 - Enable Layer 0 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN0(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN0_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN0_MASK)

#define DCIF_IE_D_VSYNC_EN_MASK                  (0x1U)
#define DCIF_IE_D_VSYNC_EN_SHIFT                 (0U)
/*! VSYNC_EN - VSYNC Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_VSYNC_EN(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_VSYNC_EN_SHIFT)) & DCIF_IE_D_VSYNC_EN_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN1_MASK            (0x2U)
#define DCIF_IE_D_FIFO_PANIC_EN1_SHIFT           (1U)
/*! FIFO_PANIC_EN1 - Enable Layer 1 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN1(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN1_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN1_MASK)

#define DCIF_IE_D_UNDERRUN_EN_MASK               (0x2U)
#define DCIF_IE_D_UNDERRUN_EN_SHIFT              (1U)
/*! UNDERRUN_EN - Underrun Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_UNDERRUN_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_UNDERRUN_EN_SHIFT)) & DCIF_IE_D_UNDERRUN_EN_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN2_MASK            (0x4U)
#define DCIF_IE_D_FIFO_PANIC_EN2_SHIFT           (2U)
/*! FIFO_PANIC_EN2 - Enable Layer 2 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN2(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN2_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN2_MASK)

#define DCIF_IE_D_VS_BLANK_EN_MASK               (0x4U)
#define DCIF_IE_D_VS_BLANK_EN_SHIFT              (2U)
/*! VS_BLANK_EN - Vertical Blanking Period Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_VS_BLANK_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_VS_BLANK_EN_SHIFT)) & DCIF_IE_D_VS_BLANK_EN_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN3_MASK            (0x8U)
#define DCIF_IE_D_FIFO_PANIC_EN3_SHIFT           (3U)
/*! FIFO_PANIC_EN3 - Enable Layer 3 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN3(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN3_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN3_MASK)

#define DCIF_IE_D_PDI_OVERRUN_EN_MASK            (0x8U)
#define DCIF_IE_D_PDI_OVERRUN_EN_SHIFT           (3U)
/*! PDI_OVERRUN_EN - PDI Buffer Overrun Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_PDI_OVERRUN_EN(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_PDI_OVERRUN_EN_SHIFT)) & DCIF_IE_D_PDI_OVERRUN_EN_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN4_MASK            (0x10U)
#define DCIF_IE_D_FIFO_PANIC_EN4_SHIFT           (4U)
/*! FIFO_PANIC_EN4 - Enable Layer 4 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN4(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN4_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN4_MASK)

#define DCIF_IE_D_PDI_TIMEOUT_EN_MASK            (0x10U)
#define DCIF_IE_D_PDI_TIMEOUT_EN_SHIFT           (4U)
/*! PDI_TIMEOUT_EN - PDI Vsync Timeout Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_PDI_TIMEOUT_EN(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_PDI_TIMEOUT_EN_SHIFT)) & DCIF_IE_D_PDI_TIMEOUT_EN_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN5_MASK            (0x20U)
#define DCIF_IE_D_FIFO_PANIC_EN5_SHIFT           (5U)
/*! FIFO_PANIC_EN5 - Enable Layer 5 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN5(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN5_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN5_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN6_MASK            (0x40U)
#define DCIF_IE_D_FIFO_PANIC_EN6_SHIFT           (6U)
/*! FIFO_PANIC_EN6 - Enable Layer 6 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN6(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN6_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN6_MASK)

#define DCIF_IE_D_FIFO_PANIC_EN7_MASK            (0x80U)
#define DCIF_IE_D_FIFO_PANIC_EN7_SHIFT           (7U)
/*! FIFO_PANIC_EN7 - Enable Layer 7 FIFO Panic Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_PANIC_EN7(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_PANIC_EN7_SHIFT)) & DCIF_IE_D_FIFO_PANIC_EN7_MASK)

#define DCIF_IE_D_DBI_DONE_EN_MASK               (0x100U)
#define DCIF_IE_D_DBI_DONE_EN_SHIFT              (8U)
/*! DBI_DONE_EN - DBI Command Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DBI_DONE_EN(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DBI_DONE_EN_SHIFT)) & DCIF_IE_D_DBI_DONE_EN_MASK)

#define DCIF_IE_D_DMA_ERR_EN0_MASK               (0x100U)
#define DCIF_IE_D_DMA_ERR_EN0_SHIFT              (8U)
/*! DMA_ERR_EN0 - Enable Layer 0 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN0(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN0_SHIFT)) & DCIF_IE_D_DMA_ERR_EN0_MASK)

#define DCIF_IE_D_DMA_ERR_EN1_MASK               (0x200U)
#define DCIF_IE_D_DMA_ERR_EN1_SHIFT              (9U)
/*! DMA_ERR_EN1 - Enable Layer 1 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN1(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN1_SHIFT)) & DCIF_IE_D_DMA_ERR_EN1_MASK)

#define DCIF_IE_D_TXPKTIF_DONE_EN_MASK           (0x200U)
#define DCIF_IE_D_TXPKTIF_DONE_EN_SHIFT          (9U)
/*! TXPKTIF_DONE_EN - TX Packet Interface Command Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_TXPKTIF_DONE_EN(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_TXPKTIF_DONE_EN_SHIFT)) & DCIF_IE_D_TXPKTIF_DONE_EN_MASK)

#define DCIF_IE_D_DMA_ERR_EN2_MASK               (0x400U)
#define DCIF_IE_D_DMA_ERR_EN2_SHIFT              (10U)
/*! DMA_ERR_EN2 - Enable Layer 2 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN2(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN2_SHIFT)) & DCIF_IE_D_DMA_ERR_EN2_MASK)

#define DCIF_IE_D_TXPKTIF_TIMEOUT_EN_MASK        (0x400U)
#define DCIF_IE_D_TXPKTIF_TIMEOUT_EN_SHIFT       (10U)
/*! TXPKTIF_TIMEOUT_EN - TX Packet Interface Timeout Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_TXPKTIF_TIMEOUT_EN(x)          (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_TXPKTIF_TIMEOUT_EN_SHIFT)) & DCIF_IE_D_TXPKTIF_TIMEOUT_EN_MASK)

#define DCIF_IE_D_DMA_ERR_EN3_MASK               (0x800U)
#define DCIF_IE_D_DMA_ERR_EN3_SHIFT              (11U)
/*! DMA_ERR_EN3 - Enable Layer 3 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN3(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN3_SHIFT)) & DCIF_IE_D_DMA_ERR_EN3_MASK)

#define DCIF_IE_D_DMA_ERR_EN4_MASK               (0x1000U)
#define DCIF_IE_D_DMA_ERR_EN4_SHIFT              (12U)
/*! DMA_ERR_EN4 - Enable Layer 4 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN4(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN4_SHIFT)) & DCIF_IE_D_DMA_ERR_EN4_MASK)

#define DCIF_IE_D_DMA_ERR_EN5_MASK               (0x2000U)
#define DCIF_IE_D_DMA_ERR_EN5_SHIFT              (13U)
/*! DMA_ERR_EN5 - Enable Layer 5 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN5(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN5_SHIFT)) & DCIF_IE_D_DMA_ERR_EN5_MASK)

#define DCIF_IE_D_DMA_ERR_EN6_MASK               (0x4000U)
#define DCIF_IE_D_DMA_ERR_EN6_SHIFT              (14U)
/*! DMA_ERR_EN6 - Enable Layer 6 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN6(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN6_SHIFT)) & DCIF_IE_D_DMA_ERR_EN6_MASK)

#define DCIF_IE_D_DMA_ERR_EN7_MASK               (0x8000U)
#define DCIF_IE_D_DMA_ERR_EN7_SHIFT              (15U)
/*! DMA_ERR_EN7 - Enable Layer 7 DMA Error Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_ERR_EN7(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_ERR_EN7_SHIFT)) & DCIF_IE_D_DMA_ERR_EN7_MASK)

#define DCIF_IE_D_DMA_DONE_EN0_MASK              (0x10000U)
#define DCIF_IE_D_DMA_DONE_EN0_SHIFT             (16U)
/*! DMA_DONE_EN0 - Enable Layer 0 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN0(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN0_SHIFT)) & DCIF_IE_D_DMA_DONE_EN0_MASK)

#define DCIF_IE_D_DMA_DONE_EN1_MASK              (0x20000U)
#define DCIF_IE_D_DMA_DONE_EN1_SHIFT             (17U)
/*! DMA_DONE_EN1 - Enable Layer 1 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN1(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN1_SHIFT)) & DCIF_IE_D_DMA_DONE_EN1_MASK)

#define DCIF_IE_D_DMA_DONE_EN2_MASK              (0x40000U)
#define DCIF_IE_D_DMA_DONE_EN2_SHIFT             (18U)
/*! DMA_DONE_EN2 - Enable Layer 2 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN2(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN2_SHIFT)) & DCIF_IE_D_DMA_DONE_EN2_MASK)

#define DCIF_IE_D_DMA_DONE_EN3_MASK              (0x80000U)
#define DCIF_IE_D_DMA_DONE_EN3_SHIFT             (19U)
/*! DMA_DONE_EN3 - Enable Layer 3 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN3(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN3_SHIFT)) & DCIF_IE_D_DMA_DONE_EN3_MASK)

#define DCIF_IE_D_DMA_DONE_EN4_MASK              (0x100000U)
#define DCIF_IE_D_DMA_DONE_EN4_SHIFT             (20U)
/*! DMA_DONE_EN4 - Enable Layer 4 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN4(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN4_SHIFT)) & DCIF_IE_D_DMA_DONE_EN4_MASK)

#define DCIF_IE_D_DMA_DONE_EN5_MASK              (0x200000U)
#define DCIF_IE_D_DMA_DONE_EN5_SHIFT             (21U)
/*! DMA_DONE_EN5 - Enable Layer 5 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN5(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN5_SHIFT)) & DCIF_IE_D_DMA_DONE_EN5_MASK)

#define DCIF_IE_D_DMA_DONE_EN6_MASK              (0x400000U)
#define DCIF_IE_D_DMA_DONE_EN6_SHIFT             (22U)
/*! DMA_DONE_EN6 - Enable Layer 6 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN6(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN6_SHIFT)) & DCIF_IE_D_DMA_DONE_EN6_MASK)

#define DCIF_IE_D_DMA_DONE_EN7_MASK              (0x800000U)
#define DCIF_IE_D_DMA_DONE_EN7_SHIFT             (23U)
/*! DMA_DONE_EN7 - Enable Layer 7 DMA Done Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_DMA_DONE_EN7(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_DMA_DONE_EN7_SHIFT)) & DCIF_IE_D_DMA_DONE_EN7_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN0_MASK            (0x1000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN0_SHIFT           (24U)
/*! FIFO_EMPTY_EN0 - Enable Layer 0 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN0(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN0_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN0_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN1_MASK            (0x2000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN1_SHIFT           (25U)
/*! FIFO_EMPTY_EN1 - Enable Layer 1 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN1(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN1_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN1_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN2_MASK            (0x4000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN2_SHIFT           (26U)
/*! FIFO_EMPTY_EN2 - Enable Layer 2 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN2(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN2_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN2_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN3_MASK            (0x8000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN3_SHIFT           (27U)
/*! FIFO_EMPTY_EN3 - Enable Layer 3 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN3(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN3_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN3_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN4_MASK            (0x10000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN4_SHIFT           (28U)
/*! FIFO_EMPTY_EN4 - Enable Layer 4 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN4(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN4_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN4_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN5_MASK            (0x20000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN5_SHIFT           (29U)
/*! FIFO_EMPTY_EN5 - Enable Layer 5 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN5(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN5_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN5_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN6_MASK            (0x40000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN6_SHIFT           (30U)
/*! FIFO_EMPTY_EN6 - Enable Layer 6 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN6(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN6_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN6_MASK)

#define DCIF_IE_D_FIFO_EMPTY_EN7_MASK            (0x80000000U)
#define DCIF_IE_D_FIFO_EMPTY_EN7_SHIFT           (31U)
/*! FIFO_EMPTY_EN7 - Enable Layer 7 FIFO Empty Interrupt
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_IE_D_FIFO_EMPTY_EN7(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_IE_D_FIFO_EMPTY_EN7_SHIFT)) & DCIF_IE_D_FIFO_EMPTY_EN7_MASK)
/*! @} */

/* The count of DCIF_IE_D */
#define DCIF_IE_D_COUNT                          (8U)

/* The count of DCIF_IE_D */
#define DCIF_IE_D_COUNT2                         (2U)

/*! @name IS_D - Interrupt Status Register 0 for Domain 1..Interrupt Status Register 1 for Domain 8 */
/*! @{ */

#define DCIF_IS_D_FIFO_PANIC0_MASK               (0x1U)
#define DCIF_IS_D_FIFO_PANIC0_SHIFT              (0U)
/*! FIFO_PANIC0 - Layer 0 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC0(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC0_SHIFT)) & DCIF_IS_D_FIFO_PANIC0_MASK)

#define DCIF_IS_D_VSYNC_MASK                     (0x1U)
#define DCIF_IS_D_VSYNC_SHIFT                    (0U)
/*! VSYNC - VSYNC Start Flag
 *  0b0..VSYNC has not started
 *  0b1..VSYNC has started
 */
#define DCIF_IS_D_VSYNC(x)                       (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_VSYNC_SHIFT)) & DCIF_IS_D_VSYNC_MASK)

#define DCIF_IS_D_FIFO_PANIC1_MASK               (0x2U)
#define DCIF_IS_D_FIFO_PANIC1_SHIFT              (1U)
/*! FIFO_PANIC1 - Layer 1 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC1(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC1_SHIFT)) & DCIF_IS_D_FIFO_PANIC1_MASK)

#define DCIF_IS_D_UNDERRUN_MASK                  (0x2U)
#define DCIF_IS_D_UNDERRUN_SHIFT                 (1U)
/*! UNDERRUN - Underrun Flag
 *  0b0..Output buffer not underrun
 *  0b1..Output buffer underrun
 */
#define DCIF_IS_D_UNDERRUN(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_UNDERRUN_SHIFT)) & DCIF_IS_D_UNDERRUN_MASK)

#define DCIF_IS_D_FIFO_PANIC2_MASK               (0x4U)
#define DCIF_IS_D_FIFO_PANIC2_SHIFT              (2U)
/*! FIFO_PANIC2 - Layer 2 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC2(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC2_SHIFT)) & DCIF_IS_D_FIFO_PANIC2_MASK)

#define DCIF_IS_D_VS_BLANK_MASK                  (0x4U)
#define DCIF_IS_D_VS_BLANK_SHIFT                 (2U)
/*! VS_BLANK - Vertical Blanking Period Start Flag
 *  0b0..Vertical blanking period has not started
 *  0b1..Vertical blanking period has started
 */
#define DCIF_IS_D_VS_BLANK(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_VS_BLANK_SHIFT)) & DCIF_IS_D_VS_BLANK_MASK)

#define DCIF_IS_D_FIFO_PANIC3_MASK               (0x8U)
#define DCIF_IS_D_FIFO_PANIC3_SHIFT              (3U)
/*! FIFO_PANIC3 - Layer 3 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC3(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC3_SHIFT)) & DCIF_IS_D_FIFO_PANIC3_MASK)

#define DCIF_IS_D_PDI_OVERRUN_MASK               (0x8U)
#define DCIF_IS_D_PDI_OVERRUN_SHIFT              (3U)
/*! PDI_OVERRUN - PDI Buffer Overrun Flag
 *  0b0..PDI buffer not overrun
 *  0b1..PDI buffer overrun
 */
#define DCIF_IS_D_PDI_OVERRUN(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_PDI_OVERRUN_SHIFT)) & DCIF_IS_D_PDI_OVERRUN_MASK)

#define DCIF_IS_D_FIFO_PANIC4_MASK               (0x10U)
#define DCIF_IS_D_FIFO_PANIC4_SHIFT              (4U)
/*! FIFO_PANIC4 - Layer 4 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC4(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC4_SHIFT)) & DCIF_IS_D_FIFO_PANIC4_MASK)

#define DCIF_IS_D_PDI_TIMEOUT_MASK               (0x10U)
#define DCIF_IS_D_PDI_TIMEOUT_SHIFT              (4U)
/*! PDI_TIMEOUT - PDI Timeout Flag
 *  0b0..No error
 *  0b1..Timeout Error occur
 */
#define DCIF_IS_D_PDI_TIMEOUT(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_PDI_TIMEOUT_SHIFT)) & DCIF_IS_D_PDI_TIMEOUT_MASK)

#define DCIF_IS_D_FIFO_PANIC5_MASK               (0x20U)
#define DCIF_IS_D_FIFO_PANIC5_SHIFT              (5U)
/*! FIFO_PANIC5 - Layer 5 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC5(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC5_SHIFT)) & DCIF_IS_D_FIFO_PANIC5_MASK)

#define DCIF_IS_D_FIFO_PANIC6_MASK               (0x40U)
#define DCIF_IS_D_FIFO_PANIC6_SHIFT              (6U)
/*! FIFO_PANIC6 - Layer 6 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC6(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC6_SHIFT)) & DCIF_IS_D_FIFO_PANIC6_MASK)

#define DCIF_IS_D_FIFO_PANIC7_MASK               (0x80U)
#define DCIF_IS_D_FIFO_PANIC7_SHIFT              (7U)
/*! FIFO_PANIC7 - Layer 7 FIFO Panic Flag
 *  0b0..Not occur
 *  0b1..FIFO panic occur
 */
#define DCIF_IS_D_FIFO_PANIC7(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_PANIC7_SHIFT)) & DCIF_IS_D_FIFO_PANIC7_MASK)

#define DCIF_IS_D_DBI_DONE_MASK                  (0x100U)
#define DCIF_IS_D_DBI_DONE_SHIFT                 (8U)
/*! DBI_DONE - DBI Command Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DBI_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DBI_DONE_SHIFT)) & DCIF_IS_D_DBI_DONE_MASK)

#define DCIF_IS_D_DMA_ERR0_MASK                  (0x100U)
#define DCIF_IS_D_DMA_ERR0_SHIFT                 (8U)
/*! DMA_ERR0 - Layer 0 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR0(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR0_SHIFT)) & DCIF_IS_D_DMA_ERR0_MASK)

#define DCIF_IS_D_DMA_ERR1_MASK                  (0x200U)
#define DCIF_IS_D_DMA_ERR1_SHIFT                 (9U)
/*! DMA_ERR1 - Layer 1 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR1(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR1_SHIFT)) & DCIF_IS_D_DMA_ERR1_MASK)

#define DCIF_IS_D_TXPKTIF_DONE_MASK              (0x200U)
#define DCIF_IS_D_TXPKTIF_DONE_SHIFT             (9U)
/*! TXPKTIF_DONE - TX Packet Interface Command Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_TXPKTIF_DONE(x)                (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_TXPKTIF_DONE_SHIFT)) & DCIF_IS_D_TXPKTIF_DONE_MASK)

#define DCIF_IS_D_DMA_ERR2_MASK                  (0x400U)
#define DCIF_IS_D_DMA_ERR2_SHIFT                 (10U)
/*! DMA_ERR2 - Layer 2 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR2(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR2_SHIFT)) & DCIF_IS_D_DMA_ERR2_MASK)

#define DCIF_IS_D_TXPKTIF_TIMEOUT_MASK           (0x400U)
#define DCIF_IS_D_TXPKTIF_TIMEOUT_SHIFT          (10U)
/*! TXPKTIF_TIMEOUT - TX Packet Interface Timeout Flag
 *  0b0..No error
 *  0b1..Timeout Error occur
 */
#define DCIF_IS_D_TXPKTIF_TIMEOUT(x)             (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_TXPKTIF_TIMEOUT_SHIFT)) & DCIF_IS_D_TXPKTIF_TIMEOUT_MASK)

#define DCIF_IS_D_DMA_ERR3_MASK                  (0x800U)
#define DCIF_IS_D_DMA_ERR3_SHIFT                 (11U)
/*! DMA_ERR3 - Layer 3 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR3(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR3_SHIFT)) & DCIF_IS_D_DMA_ERR3_MASK)

#define DCIF_IS_D_DMA_ERR4_MASK                  (0x1000U)
#define DCIF_IS_D_DMA_ERR4_SHIFT                 (12U)
/*! DMA_ERR4 - Layer 4 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR4(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR4_SHIFT)) & DCIF_IS_D_DMA_ERR4_MASK)

#define DCIF_IS_D_DMA_ERR5_MASK                  (0x2000U)
#define DCIF_IS_D_DMA_ERR5_SHIFT                 (13U)
/*! DMA_ERR5 - Layer 5 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR5(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR5_SHIFT)) & DCIF_IS_D_DMA_ERR5_MASK)

#define DCIF_IS_D_DMA_ERR6_MASK                  (0x4000U)
#define DCIF_IS_D_DMA_ERR6_SHIFT                 (14U)
/*! DMA_ERR6 - Layer 6 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR6(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR6_SHIFT)) & DCIF_IS_D_DMA_ERR6_MASK)

#define DCIF_IS_D_DMA_ERR7_MASK                  (0x8000U)
#define DCIF_IS_D_DMA_ERR7_SHIFT                 (15U)
/*! DMA_ERR7 - Layer 7 DMA Error Flag
 *  0b0..No error
 *  0b1..Error occur
 */
#define DCIF_IS_D_DMA_ERR7(x)                    (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_ERR7_SHIFT)) & DCIF_IS_D_DMA_ERR7_MASK)

#define DCIF_IS_D_DMA_DONE0_MASK                 (0x10000U)
#define DCIF_IS_D_DMA_DONE0_SHIFT                (16U)
/*! DMA_DONE0 - Layer 0 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE0(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE0_SHIFT)) & DCIF_IS_D_DMA_DONE0_MASK)

#define DCIF_IS_D_DMA_DONE1_MASK                 (0x20000U)
#define DCIF_IS_D_DMA_DONE1_SHIFT                (17U)
/*! DMA_DONE1 - Layer 1 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE1(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE1_SHIFT)) & DCIF_IS_D_DMA_DONE1_MASK)

#define DCIF_IS_D_DMA_DONE2_MASK                 (0x40000U)
#define DCIF_IS_D_DMA_DONE2_SHIFT                (18U)
/*! DMA_DONE2 - Layer 2 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE2(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE2_SHIFT)) & DCIF_IS_D_DMA_DONE2_MASK)

#define DCIF_IS_D_DMA_DONE3_MASK                 (0x80000U)
#define DCIF_IS_D_DMA_DONE3_SHIFT                (19U)
/*! DMA_DONE3 - Layer 3 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE3(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE3_SHIFT)) & DCIF_IS_D_DMA_DONE3_MASK)

#define DCIF_IS_D_DMA_DONE4_MASK                 (0x100000U)
#define DCIF_IS_D_DMA_DONE4_SHIFT                (20U)
/*! DMA_DONE4 - Layer 4 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE4(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE4_SHIFT)) & DCIF_IS_D_DMA_DONE4_MASK)

#define DCIF_IS_D_DMA_DONE5_MASK                 (0x200000U)
#define DCIF_IS_D_DMA_DONE5_SHIFT                (21U)
/*! DMA_DONE5 - Layer 5 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE5(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE5_SHIFT)) & DCIF_IS_D_DMA_DONE5_MASK)

#define DCIF_IS_D_DMA_DONE6_MASK                 (0x400000U)
#define DCIF_IS_D_DMA_DONE6_SHIFT                (22U)
/*! DMA_DONE6 - Layer 6 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE6(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE6_SHIFT)) & DCIF_IS_D_DMA_DONE6_MASK)

#define DCIF_IS_D_DMA_DONE7_MASK                 (0x800000U)
#define DCIF_IS_D_DMA_DONE7_SHIFT                (23U)
/*! DMA_DONE7 - Layer 7 DMA Done Flag
 *  0b0..Not finished yet
 *  0b1..Finished
 */
#define DCIF_IS_D_DMA_DONE7(x)                   (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_DMA_DONE7_SHIFT)) & DCIF_IS_D_DMA_DONE7_MASK)

#define DCIF_IS_D_FIFO_EMPTY0_MASK               (0x1000000U)
#define DCIF_IS_D_FIFO_EMPTY0_SHIFT              (24U)
/*! FIFO_EMPTY0 - Layer 0 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY0(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY0_SHIFT)) & DCIF_IS_D_FIFO_EMPTY0_MASK)

#define DCIF_IS_D_FIFO_EMPTY1_MASK               (0x2000000U)
#define DCIF_IS_D_FIFO_EMPTY1_SHIFT              (25U)
/*! FIFO_EMPTY1 - Layer 1 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY1(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY1_SHIFT)) & DCIF_IS_D_FIFO_EMPTY1_MASK)

#define DCIF_IS_D_FIFO_EMPTY2_MASK               (0x4000000U)
#define DCIF_IS_D_FIFO_EMPTY2_SHIFT              (26U)
/*! FIFO_EMPTY2 - Layer 2 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY2(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY2_SHIFT)) & DCIF_IS_D_FIFO_EMPTY2_MASK)

#define DCIF_IS_D_FIFO_EMPTY3_MASK               (0x8000000U)
#define DCIF_IS_D_FIFO_EMPTY3_SHIFT              (27U)
/*! FIFO_EMPTY3 - Layer 3 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY3(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY3_SHIFT)) & DCIF_IS_D_FIFO_EMPTY3_MASK)

#define DCIF_IS_D_FIFO_EMPTY4_MASK               (0x10000000U)
#define DCIF_IS_D_FIFO_EMPTY4_SHIFT              (28U)
/*! FIFO_EMPTY4 - Layer 4 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY4(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY4_SHIFT)) & DCIF_IS_D_FIFO_EMPTY4_MASK)

#define DCIF_IS_D_FIFO_EMPTY5_MASK               (0x20000000U)
#define DCIF_IS_D_FIFO_EMPTY5_SHIFT              (29U)
/*! FIFO_EMPTY5 - Layer 5 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY5(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY5_SHIFT)) & DCIF_IS_D_FIFO_EMPTY5_MASK)

#define DCIF_IS_D_FIFO_EMPTY6_MASK               (0x40000000U)
#define DCIF_IS_D_FIFO_EMPTY6_SHIFT              (30U)
/*! FIFO_EMPTY6 - Layer 6 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY6(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY6_SHIFT)) & DCIF_IS_D_FIFO_EMPTY6_MASK)

#define DCIF_IS_D_FIFO_EMPTY7_MASK               (0x80000000U)
#define DCIF_IS_D_FIFO_EMPTY7_SHIFT              (31U)
/*! FIFO_EMPTY7 - Layer 7 FIFO Empty Flag
 *  0b0..Layer FIFO not underrun
 *  0b1..Layer FIFO underrun
 */
#define DCIF_IS_D_FIFO_EMPTY7(x)                 (((uint32_t)(((uint32_t)(x)) << DCIF_IS_D_FIFO_EMPTY7_SHIFT)) & DCIF_IS_D_FIFO_EMPTY7_MASK)
/*! @} */

/* The count of DCIF_IS_D */
#define DCIF_IS_D_COUNT                          (8U)

/* The count of DCIF_IS_D */
#define DCIF_IS_D_COUNT2                         (2U)

/*! @name PANIC_THRES_L - FIFO Panic Threshold Register For Layer 0..FIFO Panic Threshold Register For Layer 7 */
/*! @{ */

#define DCIF_PANIC_THRES_L_PANIC_THRES_LOW_MASK  (0xFFFU)
#define DCIF_PANIC_THRES_L_PANIC_THRES_LOW_SHIFT (0U)
/*! PANIC_THRES_LOW - Panic Threshold Low Value */
#define DCIF_PANIC_THRES_L_PANIC_THRES_LOW(x)    (((uint32_t)(((uint32_t)(x)) << DCIF_PANIC_THRES_L_PANIC_THRES_LOW_SHIFT)) & DCIF_PANIC_THRES_L_PANIC_THRES_LOW_MASK)

#define DCIF_PANIC_THRES_L_PANIC_THRES_HIGH_MASK (0xFFF0000U)
#define DCIF_PANIC_THRES_L_PANIC_THRES_HIGH_SHIFT (16U)
/*! PANIC_THRES_HIGH - Panic Threshold High Value */
#define DCIF_PANIC_THRES_L_PANIC_THRES_HIGH(x)   (((uint32_t)(((uint32_t)(x)) << DCIF_PANIC_THRES_L_PANIC_THRES_HIGH_SHIFT)) & DCIF_PANIC_THRES_L_PANIC_THRES_HIGH_MASK)

#define DCIF_PANIC_THRES_L_PANIC_REQ_EN_MASK     (0x80000000U)
#define DCIF_PANIC_THRES_L_PANIC_REQ_EN_SHIFT    (31U)
/*! PANIC_REQ_EN - Panic Request Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define DCIF_PANIC_THRES_L_PANIC_REQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_PANIC_THRES_L_PANIC_REQ_EN_SHIFT)) & DCIF_PANIC_THRES_L_PANIC_REQ_EN_MASK)
/*! @} */

/* The count of DCIF_PANIC_THRES_L */
#define DCIF_PANIC_THRES_L_COUNT                 (8U)

/* The count of DCIF_PANIC_THRES_L */
#define DCIF_PANIC_THRES_L_COUNT2                (1U)

/*! @name LAYER_SR_L - Layer Status Register 0 for Layer 0..Layer Status Register 0 for Layer 7 */
/*! @{ */

#define DCIF_LAYER_SR_L_FIFO_CNT_MASK            (0x3FFU)
#define DCIF_LAYER_SR_L_FIFO_CNT_SHIFT           (0U)
/*! FIFO_CNT - Layer FIFO Count */
#define DCIF_LAYER_SR_L_FIFO_CNT(x)              (((uint32_t)(((uint32_t)(x)) << DCIF_LAYER_SR_L_FIFO_CNT_SHIFT)) & DCIF_LAYER_SR_L_FIFO_CNT_MASK)
/*! @} */

/* The count of DCIF_LAYER_SR_L */
#define DCIF_LAYER_SR_L_COUNT                    (8U)

/* The count of DCIF_LAYER_SR_L */
#define DCIF_LAYER_SR_L_COUNT2                   (1U)

/*! @name FRAME_BUF2_ADDR_LOW_L - Frame Buffer 2 Low Address for Layer 0..Frame Buffer 2 Low Address for Layer 1 */
/*! @{ */

#define DCIF_FRAME_BUF2_ADDR_LOW_L_ADDR_MASK     (0xFFFFFFFFU)
#define DCIF_FRAME_BUF2_ADDR_LOW_L_ADDR_SHIFT    (0U)
/*! ADDR - Frame Buffer 2 Address */
#define DCIF_FRAME_BUF2_ADDR_LOW_L_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << DCIF_FRAME_BUF2_ADDR_LOW_L_ADDR_SHIFT)) & DCIF_FRAME_BUF2_ADDR_LOW_L_ADDR_MASK)
/*! @} */

/* The count of DCIF_FRAME_BUF2_ADDR_LOW_L */
#define DCIF_FRAME_BUF2_ADDR_LOW_L_COUNT         (8U)

/* The count of DCIF_FRAME_BUF2_ADDR_HIGH_L */
#define DCIF_FRAME_BUF2_ADDR_HIGH_L_COUNT        (8U)


/*!
 * @}
 */ /* end of group DCIF_Register_Masks */


/*!
 * @}
 */ /* end of group DCIF_Peripheral_Access_Layer */


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


#endif  /* PERI_DCIF_H_ */

