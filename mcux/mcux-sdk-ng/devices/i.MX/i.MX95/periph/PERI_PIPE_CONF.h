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
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PIPE_CONF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
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
 * @file PIPE_CONF.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for PIPE_CONF
 *
 * CMSIS Peripheral Access Layer for PIPE_CONF
 */

#if !defined(PIPE_CONF_H_)
#define PIPE_CONF_H_                             /**< Symbol preventing repeated inclusion */

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
   -- PIPE_CONF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIPE_CONF_Peripheral_Access_Layer PIPE_CONF Peripheral Access Layer
 * @{
 */

/** PIPE_CONF - Size of Registers Arrays */
#define PIPE_CONF_NEO_PIPE_TRIG_ARRAY_COUNT       1u
#define PIPE_CONF_NEO_PIPE_IMG_CONF_ARRAY_COUNT   1u

/** PIPE_CONF - Register Layout Typedef */
typedef struct {
  __IO uint32_t SOFT_RESET;                        /**< NEO Soft Reset, offset: 0x0 */
  __IO uint32_t BUS_TXPARAM;                       /**< NEO Bus Transaction Parameter Register, offset: 0x4 */
  __IO uint32_t REG_XFR_DIS;                       /**< NEO Register Transfer Error Disable, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CSI_CTRL;                          /**< NEO CSI Control, offset: 0x10 */
  __IO uint32_t FRAME_NUM;                         /**< NEO Frame Number, offset: 0x14 */
  __IO uint32_t REG_SHD_CTRL;                      /**< NEO Register Shadowing Control, offset: 0x18 */
  __IO uint32_t REG_SHD_CMD;                       /**< NEO Register Shadowing Command, offset: 0x1C */
  __IO uint32_t TRIG_CAM[PIPE_CONF_NEO_PIPE_TRIG_ARRAY_COUNT]; /**< NEO Camera 0 Trigger, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[12];
  struct {                                         /* offset: 0x30, array step: 0x40 */
    __IO uint32_t IMG_CONF_CAM;                      /**< NEO Camera 0 Image Configuration, array offset: 0x30, array step: 0x40 */
    __IO uint32_t IMG_SIZE_CAM;                      /**< NEO Camera 0 Image Size Register, array offset: 0x34, array step: 0x40 */
         uint8_t RESERVED_0[4];
    __IO uint32_t IMG0_IN_ADDR_CAM;                  /**< NEO Camera 0 Input Image 0 Base Address Register, array offset: 0x3C, array step: 0x40 */
    __IO uint32_t IMG1_IN_ADDR_CAM;                  /**< NEO Camera 0 Input Image 1 Base Address, array offset: 0x40, array step: 0x40 */
    __IO uint32_t OUTCH0_ADDR_CAM;                   /**< NEO Camera 0 Output Channel 0 Base Address Register, array offset: 0x44, array step: 0x40 */
    __IO uint32_t OUTCH1_ADDR_CAM;                   /**< NEO Camera 0 Output Channel 1 Base Address Register, array offset: 0x48, array step: 0x40 */
    __IO uint32_t OUTIR_ADDR_CAM;                    /**< NEO Camera 0 Output IR Component Base Address Register, array offset: 0x4C, array step: 0x40 */
    __IO uint32_t IMG0_IN_LS_CAM;                    /**< NEO Camera 0 Input Image 0 Line Stride Register, array offset: 0x50, array step: 0x40 */
    __IO uint32_t IMG1_IN_LS_CAM;                    /**< NEO Camera 0 Input Image 1 Line Stride Register, array offset: 0x54, array step: 0x40 */
    __IO uint32_t OUTCH0_LS_CAM;                     /**< NEO Camera 0 Output Y Component Line Stride Register, array offset: 0x58, array step: 0x40 */
    __IO uint32_t OUTCH1_LS_CAM;                     /**< NEO Camera 0 Output Channel 1 Component Line Stride Register, array offset: 0x5C, array step: 0x40 */
    __IO uint32_t OUTIR_LS_CAM;                      /**< NEO Camera 0 Output IR Component Line Stride Register, array offset: 0x60, array step: 0x40 */
    __IO uint32_t SKIP_CTRL;                         /**< NEO Camera 0 Pixel Skip Control Register, array offset: 0x64, array step: 0x40 */
    __IO uint32_t INT_EN;                            /**< NEO Camera 0 Interrupt Enable Register, array offset: 0x68, array step: 0x40 */
    __IO uint32_t INT_STAT;                          /**< NEO Camera 0 Interrupt Status Register, array offset: 0x6C, array step: 0x40 */
  } NEO_PIPE_IMG_CONF_ARRAY[PIPE_CONF_NEO_PIPE_IMG_CONF_ARRAY_COUNT];
  __IO uint32_t CSI_STAT;                          /**< NEO CSI Timing Status Register, offset: 0x70 */
} PIPE_CONF_Type;

/* ----------------------------------------------------------------------------
   -- PIPE_CONF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIPE_CONF_Register_Masks PIPE_CONF Register Masks
 * @{
 */

/*! @name SOFT_RESET - NEO Soft Reset */
/*! @{ */

#define PIPE_CONF_SOFT_RESET_SOFT_RESET_MASK     (0x1U)
#define PIPE_CONF_SOFT_RESET_SOFT_RESET_SHIFT    (0U)
#define PIPE_CONF_SOFT_RESET_SOFT_RESET(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_SOFT_RESET_SOFT_RESET_SHIFT)) & PIPE_CONF_SOFT_RESET_SOFT_RESET_MASK)

#define PIPE_CONF_SOFT_RESET_HARD_RESET_MASK     (0x2U)
#define PIPE_CONF_SOFT_RESET_HARD_RESET_SHIFT    (1U)
#define PIPE_CONF_SOFT_RESET_HARD_RESET(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_SOFT_RESET_HARD_RESET_SHIFT)) & PIPE_CONF_SOFT_RESET_HARD_RESET_MASK)
/*! @} */

/*! @name BUS_TXPARAM - NEO Bus Transaction Parameter Register */
/*! @{ */

#define PIPE_CONF_BUS_TXPARAM_OTLT_MASK          (0xFFU)
#define PIPE_CONF_BUS_TXPARAM_OTLT_SHIFT         (0U)
#define PIPE_CONF_BUS_TXPARAM_OTLT(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_BUS_TXPARAM_OTLT_SHIFT)) & PIPE_CONF_BUS_TXPARAM_OTLT_MASK)

#define PIPE_CONF_BUS_TXPARAM_OTHT_MASK          (0xFF00U)
#define PIPE_CONF_BUS_TXPARAM_OTHT_SHIFT         (8U)
#define PIPE_CONF_BUS_TXPARAM_OTHT(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_BUS_TXPARAM_OTHT_SHIFT)) & PIPE_CONF_BUS_TXPARAM_OTHT_MASK)

#define PIPE_CONF_BUS_TXPARAM_POSTQOS_MASK       (0xFF0000U)
#define PIPE_CONF_BUS_TXPARAM_POSTQOS_SHIFT      (16U)
/*! POSTQOS
 *  0b00000000..Post QOS threshold is 10
 *  0b00000001..Post QOS threshold is 64 (that is 64 * field value)
 *  0b00000010..Post QOS threshold is 128 (that is 64 * field value)
 *  0b00000011..Post QOS threshold is 192 (that is 64 * field value)
 *  0b11111110..Post QOS threshold is 16256 (that is 64 * field value)
 *  0b11111111..Post QOS is disabled
 */
#define PIPE_CONF_BUS_TXPARAM_POSTQOS(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_BUS_TXPARAM_POSTQOS_SHIFT)) & PIPE_CONF_BUS_TXPARAM_POSTQOS_MASK)

#define PIPE_CONF_BUS_TXPARAM_BSIZE_MASK         (0xFF000000U)
#define PIPE_CONF_BUS_TXPARAM_BSIZE_SHIFT        (24U)
/*! BSIZE
 *  0b00000000..Each burst has maximum of 4 beats
 *  0b00000001..Each burst has maximum of 8 beats
 *  0b00000010..Each burst has maximum of 16 beats
 */
#define PIPE_CONF_BUS_TXPARAM_BSIZE(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_BUS_TXPARAM_BSIZE_SHIFT)) & PIPE_CONF_BUS_TXPARAM_BSIZE_MASK)
/*! @} */

/*! @name REG_XFR_DIS - NEO Register Transfer Error Disable */
/*! @{ */

#define PIPE_CONF_REG_XFR_DIS_XFR_ERR_DIS_MASK   (0x80000000U)
#define PIPE_CONF_REG_XFR_DIS_XFR_ERR_DIS_SHIFT  (31U)
#define PIPE_CONF_REG_XFR_DIS_XFR_ERR_DIS(x)     (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_REG_XFR_DIS_XFR_ERR_DIS_SHIFT)) & PIPE_CONF_REG_XFR_DIS_XFR_ERR_DIS_MASK)
/*! @} */

/*! @name CSI_CTRL - NEO CSI Control */
/*! @{ */

#define PIPE_CONF_CSI_CTRL_VID0_MASK             (0x1FU)
#define PIPE_CONF_CSI_CTRL_VID0_SHIFT            (0U)
#define PIPE_CONF_CSI_CTRL_VID0(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_CTRL_VID0_SHIFT)) & PIPE_CONF_CSI_CTRL_VID0_MASK)

#define PIPE_CONF_CSI_CTRL_VID1_MASK             (0x1F00U)
#define PIPE_CONF_CSI_CTRL_VID1_SHIFT            (8U)
#define PIPE_CONF_CSI_CTRL_VID1(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_CTRL_VID1_SHIFT)) & PIPE_CONF_CSI_CTRL_VID1_MASK)

#define PIPE_CONF_CSI_CTRL_SSEN_MASK             (0x20000000U)
#define PIPE_CONF_CSI_CTRL_SSEN_SHIFT            (29U)
#define PIPE_CONF_CSI_CTRL_SSEN(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_CTRL_SSEN_SHIFT)) & PIPE_CONF_CSI_CTRL_SSEN_MASK)

#define PIPE_CONF_CSI_CTRL_DEVL_MASK             (0x40000000U)
#define PIPE_CONF_CSI_CTRL_DEVL_SHIFT            (30U)
#define PIPE_CONF_CSI_CTRL_DEVL(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_CTRL_DEVL_SHIFT)) & PIPE_CONF_CSI_CTRL_DEVL_MASK)

#define PIPE_CONF_CSI_CTRL_CSI_EN_MASK           (0x80000000U)
#define PIPE_CONF_CSI_CTRL_CSI_EN_SHIFT          (31U)
/*! CSI_EN
 *  0b0..CSI streaming is disabled. Input image(s) are read from system memory.
 *  0b1..CSI streaming is enabled. No read operation is done on system memory. Minimum image width that can be programmed is 256 pixels.
 */
#define PIPE_CONF_CSI_CTRL_CSI_EN(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_CTRL_CSI_EN_SHIFT)) & PIPE_CONF_CSI_CTRL_CSI_EN_MASK)
/*! @} */

/*! @name FRAME_NUM - NEO Frame Number */
/*! @{ */

#define PIPE_CONF_FRAME_NUM_CURR_FRAME_MASK      (0xFFFFU)
#define PIPE_CONF_FRAME_NUM_CURR_FRAME_SHIFT     (0U)
#define PIPE_CONF_FRAME_NUM_CURR_FRAME(x)        (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_FRAME_NUM_CURR_FRAME_SHIFT)) & PIPE_CONF_FRAME_NUM_CURR_FRAME_MASK)

#define PIPE_CONF_FRAME_NUM_SHD_FRAME_MASK       (0xFFFF0000U)
#define PIPE_CONF_FRAME_NUM_SHD_FRAME_SHIFT      (16U)
#define PIPE_CONF_FRAME_NUM_SHD_FRAME(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_FRAME_NUM_SHD_FRAME_SHIFT)) & PIPE_CONF_FRAME_NUM_SHD_FRAME_MASK)
/*! @} */

/*! @name REG_SHD_CTRL - NEO Register Shadowing Control */
/*! @{ */

#define PIPE_CONF_REG_SHD_CTRL_CTRL_MASK         (0x80000000U)
#define PIPE_CONF_REG_SHD_CTRL_CTRL_SHIFT        (31U)
/*! CTRL
 *  0b0..Register shadowing is done at every frame/context start.
 *  0b1..Register shadowing is done at frame/context start if the shadowing command register is set to 1.
 */
#define PIPE_CONF_REG_SHD_CTRL_CTRL(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_REG_SHD_CTRL_CTRL_SHIFT)) & PIPE_CONF_REG_SHD_CTRL_CTRL_MASK)
/*! @} */

/*! @name REG_SHD_CMD - NEO Register Shadowing Command */
/*! @{ */

#define PIPE_CONF_REG_SHD_CMD_CMD_MASK           (0xFFFFFFFFU)
#define PIPE_CONF_REG_SHD_CMD_CMD_SHIFT          (0U)
#define PIPE_CONF_REG_SHD_CMD_CMD(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_REG_SHD_CMD_CMD_SHIFT)) & PIPE_CONF_REG_SHD_CMD_CMD_MASK)
/*! @} */

/*! @name TRIG_CAM - NEO Camera 0 Trigger */
/*! @{ */

#define PIPE_CONF_TRIG_CAM_TRIGGER_MASK          (0xFFFFFFFFU)
#define PIPE_CONF_TRIG_CAM_TRIGGER_SHIFT         (0U)
#define PIPE_CONF_TRIG_CAM_TRIGGER(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_TRIG_CAM_TRIGGER_SHIFT)) & PIPE_CONF_TRIG_CAM_TRIGGER_MASK)
/*! @} */

/* The count of PIPE_CONF_TRIG_CAM */
#define PIPE_CONF_TRIG_CAM_COUNT                 (1U)

/*! @name IMG_CONF_CAM - NEO Camera 0 Image Configuration */
/*! @{ */

#define PIPE_CONF_IMG_CONF_CAM_IBPP0_MASK        (0xFU)
#define PIPE_CONF_IMG_CONF_CAM_IBPP0_SHIFT       (0U)
/*! IBPP0
 *  0b0000..12 bpp (packed into 16 bits)
 *  0b0001..14 bpp (packed into 16 bits)
 *  0b0010..16 bpp (packed into 16 bits)
 *  0b0011..20 bpp (packed into 32 bits)
 *  0b0100..10 bpp (packed into 16 bits)
 *  0b0101..10 bpp packed (3 pixels packed into 32 bits)
 *  0b0110..8 bpp (packed into 8 bits)
 */
#define PIPE_CONF_IMG_CONF_CAM_IBPP0(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_IBPP0_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_IBPP0_MASK)

#define PIPE_CONF_IMG_CONF_CAM_INALIGN0_MASK     (0x10U)
#define PIPE_CONF_IMG_CONF_CAM_INALIGN0_SHIFT    (4U)
/*! INALIGN0
 *  0b0..LSB aligned - lower order bits hold pixel value
 *  0b1..MSB aligned - higher order bits hold pixel values
 */
#define PIPE_CONF_IMG_CONF_CAM_INALIGN0(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_INALIGN0_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_INALIGN0_MASK)

#define PIPE_CONF_IMG_CONF_CAM_LPALIGN0_MASK     (0x20U)
#define PIPE_CONF_IMG_CONF_CAM_LPALIGN0_SHIFT    (5U)
/*! LPALIGN0
 *  0b0..LSB aligned - load the active pixel value towards the LSBs
 *  0b1..MSB aligned - load the active pixel value towards the MSBs
 */
#define PIPE_CONF_IMG_CONF_CAM_LPALIGN0(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_LPALIGN0_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_LPALIGN0_MASK)

#define PIPE_CONF_IMG_CONF_CAM_IBPP1_MASK        (0xF0000U)
#define PIPE_CONF_IMG_CONF_CAM_IBPP1_SHIFT       (16U)
/*! IBPP1
 *  0b0000..12 bpp (packed into 16 bits)
 *  0b0001..14 bpp (packed into 16 bits)
 *  0b0010..16 bpp (packed into 16 bits)
 *  0b0011..Reserved
 *  0b0100..10 bpp (packed into 16 bits)
 *  0b0101..10 bpp packed (3 pixels packed into 32 bits)
 *  0b0110..8 bpp (packed into 8 bits)
 */
#define PIPE_CONF_IMG_CONF_CAM_IBPP1(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_IBPP1_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_IBPP1_MASK)

#define PIPE_CONF_IMG_CONF_CAM_INALIGN1_MASK     (0x100000U)
#define PIPE_CONF_IMG_CONF_CAM_INALIGN1_SHIFT    (20U)
/*! INALIGN1
 *  0b0..LSB aligned - lower order bits hold pixel value
 *  0b1..MSB aligned - higher order bits hold pixel values
 */
#define PIPE_CONF_IMG_CONF_CAM_INALIGN1(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_INALIGN1_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_INALIGN1_MASK)

#define PIPE_CONF_IMG_CONF_CAM_LPALIGN1_MASK     (0x200000U)
#define PIPE_CONF_IMG_CONF_CAM_LPALIGN1_SHIFT    (21U)
/*! LPALIGN1
 *  0b0..LSB aligned - load the active pixel value towards the LSBs
 *  0b1..MSB aligned - load the active pixel value towards the MSBs
 */
#define PIPE_CONF_IMG_CONF_CAM_LPALIGN1(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_CONF_CAM_LPALIGN1_SHIFT)) & PIPE_CONF_IMG_CONF_CAM_LPALIGN1_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG_CONF_CAM */
#define PIPE_CONF_IMG_CONF_CAM_COUNT             (1U)

/*! @name IMG_SIZE_CAM - NEO Camera 0 Image Size Register */
/*! @{ */

#define PIPE_CONF_IMG_SIZE_CAM_WIDTH_MASK        (0xFFFFU)
#define PIPE_CONF_IMG_SIZE_CAM_WIDTH_SHIFT       (0U)
#define PIPE_CONF_IMG_SIZE_CAM_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_SIZE_CAM_WIDTH_SHIFT)) & PIPE_CONF_IMG_SIZE_CAM_WIDTH_MASK)

#define PIPE_CONF_IMG_SIZE_CAM_HEIGHT_MASK       (0xFFFF0000U)
#define PIPE_CONF_IMG_SIZE_CAM_HEIGHT_SHIFT      (16U)
#define PIPE_CONF_IMG_SIZE_CAM_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG_SIZE_CAM_HEIGHT_SHIFT)) & PIPE_CONF_IMG_SIZE_CAM_HEIGHT_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG_SIZE_CAM */
#define PIPE_CONF_IMG_SIZE_CAM_COUNT             (1U)

/*! @name IMG0_IN_ADDR_CAM - NEO Camera 0 Input Image 0 Base Address Register */
/*! @{ */

#define PIPE_CONF_IMG0_IN_ADDR_CAM_ADDR_MASK     (0xFFFFFFFFU)
#define PIPE_CONF_IMG0_IN_ADDR_CAM_ADDR_SHIFT    (0U)
#define PIPE_CONF_IMG0_IN_ADDR_CAM_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG0_IN_ADDR_CAM_ADDR_SHIFT)) & PIPE_CONF_IMG0_IN_ADDR_CAM_ADDR_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG0_IN_ADDR_CAM */
#define PIPE_CONF_IMG0_IN_ADDR_CAM_COUNT         (1U)

/*! @name IMG1_IN_ADDR_CAM - NEO Camera 0 Input Image 1 Base Address */
/*! @{ */

#define PIPE_CONF_IMG1_IN_ADDR_CAM_ADDR_MASK     (0xFFFFFFFFU)
#define PIPE_CONF_IMG1_IN_ADDR_CAM_ADDR_SHIFT    (0U)
#define PIPE_CONF_IMG1_IN_ADDR_CAM_ADDR(x)       (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG1_IN_ADDR_CAM_ADDR_SHIFT)) & PIPE_CONF_IMG1_IN_ADDR_CAM_ADDR_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG1_IN_ADDR_CAM */
#define PIPE_CONF_IMG1_IN_ADDR_CAM_COUNT         (1U)

/*! @name OUTCH0_ADDR_CAM - NEO Camera 0 Output Channel 0 Base Address Register */
/*! @{ */

#define PIPE_CONF_OUTCH0_ADDR_CAM_ADDR_MASK      (0xFFFFFFFFU)
#define PIPE_CONF_OUTCH0_ADDR_CAM_ADDR_SHIFT     (0U)
#define PIPE_CONF_OUTCH0_ADDR_CAM_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTCH0_ADDR_CAM_ADDR_SHIFT)) & PIPE_CONF_OUTCH0_ADDR_CAM_ADDR_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTCH0_ADDR_CAM */
#define PIPE_CONF_OUTCH0_ADDR_CAM_COUNT          (1U)

/*! @name OUTCH1_ADDR_CAM - NEO Camera 0 Output Channel 1 Base Address Register */
/*! @{ */

#define PIPE_CONF_OUTCH1_ADDR_CAM_ADDR_MASK      (0xFFFFFFFFU)
#define PIPE_CONF_OUTCH1_ADDR_CAM_ADDR_SHIFT     (0U)
#define PIPE_CONF_OUTCH1_ADDR_CAM_ADDR(x)        (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTCH1_ADDR_CAM_ADDR_SHIFT)) & PIPE_CONF_OUTCH1_ADDR_CAM_ADDR_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTCH1_ADDR_CAM */
#define PIPE_CONF_OUTCH1_ADDR_CAM_COUNT          (1U)

/*! @name OUTIR_ADDR_CAM - NEO Camera 0 Output IR Component Base Address Register */
/*! @{ */

#define PIPE_CONF_OUTIR_ADDR_CAM_ADDR_MASK       (0xFFFFFFFFU)
#define PIPE_CONF_OUTIR_ADDR_CAM_ADDR_SHIFT      (0U)
#define PIPE_CONF_OUTIR_ADDR_CAM_ADDR(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTIR_ADDR_CAM_ADDR_SHIFT)) & PIPE_CONF_OUTIR_ADDR_CAM_ADDR_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTIR_ADDR_CAM */
#define PIPE_CONF_OUTIR_ADDR_CAM_COUNT           (1U)

/*! @name IMG0_IN_LS_CAM - NEO Camera 0 Input Image 0 Line Stride Register */
/*! @{ */

#define PIPE_CONF_IMG0_IN_LS_CAM_LS_MASK         (0xFFFFFFF0U)
#define PIPE_CONF_IMG0_IN_LS_CAM_LS_SHIFT        (4U)
#define PIPE_CONF_IMG0_IN_LS_CAM_LS(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG0_IN_LS_CAM_LS_SHIFT)) & PIPE_CONF_IMG0_IN_LS_CAM_LS_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG0_IN_LS_CAM */
#define PIPE_CONF_IMG0_IN_LS_CAM_COUNT           (1U)

/*! @name IMG1_IN_LS_CAM - NEO Camera 0 Input Image 1 Line Stride Register */
/*! @{ */

#define PIPE_CONF_IMG1_IN_LS_CAM_LS_MASK         (0xFFFFFFF0U)
#define PIPE_CONF_IMG1_IN_LS_CAM_LS_SHIFT        (4U)
#define PIPE_CONF_IMG1_IN_LS_CAM_LS(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_IMG1_IN_LS_CAM_LS_SHIFT)) & PIPE_CONF_IMG1_IN_LS_CAM_LS_MASK)
/*! @} */

/* The count of PIPE_CONF_IMG1_IN_LS_CAM */
#define PIPE_CONF_IMG1_IN_LS_CAM_COUNT           (1U)

/*! @name OUTCH0_LS_CAM - NEO Camera 0 Output Y Component Line Stride Register */
/*! @{ */

#define PIPE_CONF_OUTCH0_LS_CAM_LS_MASK          (0xFFFFFFF0U)
#define PIPE_CONF_OUTCH0_LS_CAM_LS_SHIFT         (4U)
#define PIPE_CONF_OUTCH0_LS_CAM_LS(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTCH0_LS_CAM_LS_SHIFT)) & PIPE_CONF_OUTCH0_LS_CAM_LS_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTCH0_LS_CAM */
#define PIPE_CONF_OUTCH0_LS_CAM_COUNT            (1U)

/*! @name OUTCH1_LS_CAM - NEO Camera 0 Output Channel 1 Component Line Stride Register */
/*! @{ */

#define PIPE_CONF_OUTCH1_LS_CAM_LS_MASK          (0xFFFFFFF0U)
#define PIPE_CONF_OUTCH1_LS_CAM_LS_SHIFT         (4U)
#define PIPE_CONF_OUTCH1_LS_CAM_LS(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTCH1_LS_CAM_LS_SHIFT)) & PIPE_CONF_OUTCH1_LS_CAM_LS_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTCH1_LS_CAM */
#define PIPE_CONF_OUTCH1_LS_CAM_COUNT            (1U)

/*! @name OUTIR_LS_CAM - NEO Camera 0 Output IR Component Line Stride Register */
/*! @{ */

#define PIPE_CONF_OUTIR_LS_CAM_LS_MASK           (0xFFFFFFF0U)
#define PIPE_CONF_OUTIR_LS_CAM_LS_SHIFT          (4U)
#define PIPE_CONF_OUTIR_LS_CAM_LS(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_OUTIR_LS_CAM_LS_SHIFT)) & PIPE_CONF_OUTIR_LS_CAM_LS_MASK)
/*! @} */

/* The count of PIPE_CONF_OUTIR_LS_CAM */
#define PIPE_CONF_OUTIR_LS_CAM_COUNT             (1U)

/*! @name SKIP_CTRL - NEO Camera 0 Pixel Skip Control Register */
/*! @{ */

#define PIPE_CONF_SKIP_CTRL_PRESKIP_MASK         (0xFFFFU)
#define PIPE_CONF_SKIP_CTRL_PRESKIP_SHIFT        (0U)
#define PIPE_CONF_SKIP_CTRL_PRESKIP(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_SKIP_CTRL_PRESKIP_SHIFT)) & PIPE_CONF_SKIP_CTRL_PRESKIP_MASK)

#define PIPE_CONF_SKIP_CTRL_POSTSKIP_MASK        (0xFFFF0000U)
#define PIPE_CONF_SKIP_CTRL_POSTSKIP_SHIFT       (16U)
#define PIPE_CONF_SKIP_CTRL_POSTSKIP(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_SKIP_CTRL_POSTSKIP_SHIFT)) & PIPE_CONF_SKIP_CTRL_POSTSKIP_MASK)
/*! @} */

/* The count of PIPE_CONF_SKIP_CTRL */
#define PIPE_CONF_SKIP_CTRL_COUNT                (1U)

/*! @name INT_EN - NEO Camera 0 Interrupt Enable Register */
/*! @{ */

#define PIPE_CONF_INT_EN_EN_FS1_MASK             (0x1U)
#define PIPE_CONF_INT_EN_EN_FS1_SHIFT            (0U)
#define PIPE_CONF_INT_EN_EN_FS1(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_FS1_SHIFT)) & PIPE_CONF_INT_EN_EN_FS1_MASK)

#define PIPE_CONF_INT_EN_EN_FS2_MASK             (0x2U)
#define PIPE_CONF_INT_EN_EN_FS2_SHIFT            (1U)
#define PIPE_CONF_INT_EN_EN_FS2(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_FS2_SHIFT)) & PIPE_CONF_INT_EN_EN_FS2_MASK)

#define PIPE_CONF_INT_EN_EN_FD1_MASK             (0x4U)
#define PIPE_CONF_INT_EN_EN_FD1_SHIFT            (2U)
#define PIPE_CONF_INT_EN_EN_FD1(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_FD1_SHIFT)) & PIPE_CONF_INT_EN_EN_FD1_MASK)

#define PIPE_CONF_INT_EN_EN_FD2_MASK             (0x8U)
#define PIPE_CONF_INT_EN_EN_FD2_SHIFT            (3U)
#define PIPE_CONF_INT_EN_EN_FD2(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_FD2_SHIFT)) & PIPE_CONF_INT_EN_EN_FD2_MASK)

#define PIPE_CONF_INT_EN_EN_STATD_MASK           (0x10U)
#define PIPE_CONF_INT_EN_EN_STATD_SHIFT          (4U)
#define PIPE_CONF_INT_EN_EN_STATD(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_STATD_SHIFT)) & PIPE_CONF_INT_EN_EN_STATD_MASK)

#define PIPE_CONF_INT_EN_EN_DRCD_MASK            (0x20U)
#define PIPE_CONF_INT_EN_EN_DRCD_SHIFT           (5U)
#define PIPE_CONF_INT_EN_EN_DRCD(x)              (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_DRCD_SHIFT)) & PIPE_CONF_INT_EN_EN_DRCD_MASK)

#define PIPE_CONF_INT_EN_EN_BUS_ERR_MASK         (0xF0000U)
#define PIPE_CONF_INT_EN_EN_BUS_ERR_SHIFT        (16U)
#define PIPE_CONF_INT_EN_EN_BUS_ERR(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_BUS_ERR_SHIFT)) & PIPE_CONF_INT_EN_EN_BUS_ERR_MASK)

#define PIPE_CONF_INT_EN_EN_CSI_TERR_MASK        (0x20000000U)
#define PIPE_CONF_INT_EN_EN_CSI_TERR_SHIFT       (29U)
#define PIPE_CONF_INT_EN_EN_CSI_TERR(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_CSI_TERR_SHIFT)) & PIPE_CONF_INT_EN_EN_CSI_TERR_MASK)

#define PIPE_CONF_INT_EN_EN_TRIG_ERR_MASK        (0x40000000U)
#define PIPE_CONF_INT_EN_EN_TRIG_ERR_SHIFT       (30U)
#define PIPE_CONF_INT_EN_EN_TRIG_ERR(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_EN_EN_TRIG_ERR_SHIFT)) & PIPE_CONF_INT_EN_EN_TRIG_ERR_MASK)
/*! @} */

/* The count of PIPE_CONF_INT_EN */
#define PIPE_CONF_INT_EN_COUNT                   (1U)

/*! @name INT_STAT - NEO Camera 0 Interrupt Status Register */
/*! @{ */

#define PIPE_CONF_INT_STAT_S_FS1_MASK            (0x1U)
#define PIPE_CONF_INT_STAT_S_FS1_SHIFT           (0U)
#define PIPE_CONF_INT_STAT_S_FS1(x)              (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_FS1_SHIFT)) & PIPE_CONF_INT_STAT_S_FS1_MASK)

#define PIPE_CONF_INT_STAT_S_FS2_MASK            (0x2U)
#define PIPE_CONF_INT_STAT_S_FS2_SHIFT           (1U)
#define PIPE_CONF_INT_STAT_S_FS2(x)              (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_FS2_SHIFT)) & PIPE_CONF_INT_STAT_S_FS2_MASK)

#define PIPE_CONF_INT_STAT_S_FD1_MASK            (0x4U)
#define PIPE_CONF_INT_STAT_S_FD1_SHIFT           (2U)
#define PIPE_CONF_INT_STAT_S_FD1(x)              (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_FD1_SHIFT)) & PIPE_CONF_INT_STAT_S_FD1_MASK)

#define PIPE_CONF_INT_STAT_S_FD2_MASK            (0x8U)
#define PIPE_CONF_INT_STAT_S_FD2_SHIFT           (3U)
#define PIPE_CONF_INT_STAT_S_FD2(x)              (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_FD2_SHIFT)) & PIPE_CONF_INT_STAT_S_FD2_MASK)

#define PIPE_CONF_INT_STAT_S_STATD_MASK          (0x10U)
#define PIPE_CONF_INT_STAT_S_STATD_SHIFT         (4U)
#define PIPE_CONF_INT_STAT_S_STATD(x)            (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_STATD_SHIFT)) & PIPE_CONF_INT_STAT_S_STATD_MASK)

#define PIPE_CONF_INT_STAT_S_DRCD_MASK           (0x20U)
#define PIPE_CONF_INT_STAT_S_DRCD_SHIFT          (5U)
#define PIPE_CONF_INT_STAT_S_DRCD(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_DRCD_SHIFT)) & PIPE_CONF_INT_STAT_S_DRCD_MASK)

#define PIPE_CONF_INT_STAT_S_BUS_ERR_MASK        (0xF0000U)
#define PIPE_CONF_INT_STAT_S_BUS_ERR_SHIFT       (16U)
#define PIPE_CONF_INT_STAT_S_BUS_ERR(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_BUS_ERR_SHIFT)) & PIPE_CONF_INT_STAT_S_BUS_ERR_MASK)

#define PIPE_CONF_INT_STAT_S_CSI_TERR_MASK       (0x20000000U)
#define PIPE_CONF_INT_STAT_S_CSI_TERR_SHIFT      (29U)
#define PIPE_CONF_INT_STAT_S_CSI_TERR(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_CSI_TERR_SHIFT)) & PIPE_CONF_INT_STAT_S_CSI_TERR_MASK)

#define PIPE_CONF_INT_STAT_S_TRIG_ERR_MASK       (0x40000000U)
#define PIPE_CONF_INT_STAT_S_TRIG_ERR_SHIFT      (30U)
/*! S_TRIG_ERR
 *  0b0..No trigger error
 *  0b1..Trigger error generated
 */
#define PIPE_CONF_INT_STAT_S_TRIG_ERR(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_S_TRIG_ERR_SHIFT)) & PIPE_CONF_INT_STAT_S_TRIG_ERR_MASK)

#define PIPE_CONF_INT_STAT_BUSY_MASK             (0x80000000U)
#define PIPE_CONF_INT_STAT_BUSY_SHIFT            (31U)
/*! BUSY
 *  0b0..Pipeline is ready to accept more triggers
 *  0b1..Pipeline is busy, and cannot accept more triggers
 */
#define PIPE_CONF_INT_STAT_BUSY(x)               (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_INT_STAT_BUSY_SHIFT)) & PIPE_CONF_INT_STAT_BUSY_MASK)
/*! @} */

/* The count of PIPE_CONF_INT_STAT */
#define PIPE_CONF_INT_STAT_COUNT                 (1U)

/*! @name CSI_STAT - NEO CSI Timing Status Register */
/*! @{ */

#define PIPE_CONF_CSI_STAT_S_SL_LP0_MASK         (0x1U)
#define PIPE_CONF_CSI_STAT_S_SL_LP0_SHIFT        (0U)
#define PIPE_CONF_CSI_STAT_S_SL_LP0(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_SL_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_SL_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_SF_LP0_MASK         (0x2U)
#define PIPE_CONF_CSI_STAT_S_SF_LP0_SHIFT        (1U)
#define PIPE_CONF_CSI_STAT_S_SF_LP0(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_SF_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_SF_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_DO_LP0_MASK         (0x4U)
#define PIPE_CONF_CSI_STAT_S_DO_LP0_SHIFT        (2U)
#define PIPE_CONF_CSI_STAT_S_DO_LP0(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_DO_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_DO_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_LOC_LP0_MASK        (0x8U)
#define PIPE_CONF_CSI_STAT_S_LOC_LP0_SHIFT       (3U)
#define PIPE_CONF_CSI_STAT_S_LOC_LP0(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LOC_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_LOC_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_LO_LP0_MASK         (0x10U)
#define PIPE_CONF_CSI_STAT_S_LO_LP0_SHIFT        (4U)
#define PIPE_CONF_CSI_STAT_S_LO_LP0(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LO_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_LO_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_CMD_LP0_MASK        (0x20U)
#define PIPE_CONF_CSI_STAT_S_CMD_LP0_SHIFT       (5U)
#define PIPE_CONF_CSI_STAT_S_CMD_LP0(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_CMD_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_CMD_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_LL_LP0_MASK         (0x40U)
#define PIPE_CONF_CSI_STAT_S_LL_LP0_SHIFT        (6U)
#define PIPE_CONF_CSI_STAT_S_LL_LP0(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LL_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_LL_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_DATA_LP0_MASK       (0x80U)
#define PIPE_CONF_CSI_STAT_S_DATA_LP0_SHIFT      (7U)
#define PIPE_CONF_CSI_STAT_S_DATA_LP0(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_DATA_LP0_SHIFT)) & PIPE_CONF_CSI_STAT_S_DATA_LP0_MASK)

#define PIPE_CONF_CSI_STAT_S_SL_LP1_MASK         (0x10000U)
#define PIPE_CONF_CSI_STAT_S_SL_LP1_SHIFT        (16U)
#define PIPE_CONF_CSI_STAT_S_SL_LP1(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_SL_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_SL_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_SF_LP1_MASK         (0x20000U)
#define PIPE_CONF_CSI_STAT_S_SF_LP1_SHIFT        (17U)
#define PIPE_CONF_CSI_STAT_S_SF_LP1(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_SF_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_SF_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_DO_LP1_MASK         (0x40000U)
#define PIPE_CONF_CSI_STAT_S_DO_LP1_SHIFT        (18U)
#define PIPE_CONF_CSI_STAT_S_DO_LP1(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_DO_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_DO_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_LOC_LP1_MASK        (0x80000U)
#define PIPE_CONF_CSI_STAT_S_LOC_LP1_SHIFT       (19U)
#define PIPE_CONF_CSI_STAT_S_LOC_LP1(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LOC_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_LOC_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_LO_LP1_MASK         (0x100000U)
#define PIPE_CONF_CSI_STAT_S_LO_LP1_SHIFT        (20U)
#define PIPE_CONF_CSI_STAT_S_LO_LP1(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LO_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_LO_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_CMD_LP1_MASK        (0x200000U)
#define PIPE_CONF_CSI_STAT_S_CMD_LP1_SHIFT       (21U)
#define PIPE_CONF_CSI_STAT_S_CMD_LP1(x)          (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_CMD_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_CMD_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_LL_LP1_MASK         (0x400000U)
#define PIPE_CONF_CSI_STAT_S_LL_LP1_SHIFT        (22U)
#define PIPE_CONF_CSI_STAT_S_LL_LP1(x)           (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_LL_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_LL_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_DATA_LP1_MASK       (0x800000U)
#define PIPE_CONF_CSI_STAT_S_DATA_LP1_SHIFT      (23U)
#define PIPE_CONF_CSI_STAT_S_DATA_LP1(x)         (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_DATA_LP1_SHIFT)) & PIPE_CONF_CSI_STAT_S_DATA_LP1_MASK)

#define PIPE_CONF_CSI_STAT_S_STOP_MASK           (0x80000000U)
#define PIPE_CONF_CSI_STAT_S_STOP_SHIFT          (31U)
#define PIPE_CONF_CSI_STAT_S_STOP(x)             (((uint32_t)(((uint32_t)(x)) << PIPE_CONF_CSI_STAT_S_STOP_SHIFT)) & PIPE_CONF_CSI_STAT_S_STOP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PIPE_CONF_Register_Masks */


/*!
 * @}
 */ /* end of group PIPE_CONF_Peripheral_Access_Layer */


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


#endif  /* PIPE_CONF_H_ */

