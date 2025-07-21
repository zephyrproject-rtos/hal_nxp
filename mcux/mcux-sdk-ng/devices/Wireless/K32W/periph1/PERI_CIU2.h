/*
** ###################################################################
**     Processor:           K32W1480VFTA
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CIU2
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-01-18)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_CIU2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CIU2
 *
 * CMSIS Peripheral Access Layer for CIU2
 */

#if !defined(PERI_CIU2_H_)
#define PERI_CIU2_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32W1480VFTA))
#include "K32W1480_COMMON.h"
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
   -- CIU2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CIU2_Peripheral_Access_Layer CIU2 Peripheral Access Layer
 * @{
 */

/** CIU2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t CIU2_CLK_ENABLE;                   /**< Clock enable, offset: 0x0 */
  __IO uint32_t CIU2_ECO_0;                        /**< ECO Register 0, offset: 0x4 */
  __IO uint32_t CIU2_ECO_1;                        /**< ECO Register 1, offset: 0x8 */
  __IO uint32_t CIU2_ECO_2;                        /**< ECO Register 2, offset: 0xC */
  __IO uint32_t CIU2_ECO_3;                        /**< ECO Register 3, offset: 0x10 */
  __IO uint32_t CIU2_ECO_4;                        /**< ECO Register 4, offset: 0x14 */
  __IO uint32_t CIU2_ECO_5;                        /**< ECO Register 5, offset: 0x18 */
  __IO uint32_t CIU2_ECO_6;                        /**< ECO Register 6, offset: 0x1C */
  __IO uint32_t CIU2_ECO_7;                        /**< ECO Register 7, offset: 0x20 */
  __IO uint32_t CIU2_ECO_8;                        /**< ECO Register 8, offset: 0x24 */
  __IO uint32_t CIU2_ECO_9;                        /**< ECO Register 9, offset: 0x28 */
  __IO uint32_t CIU2_ECO_10;                       /**< ECO Register 10, offset: 0x2C */
  __IO uint32_t CIU2_ECO_11;                       /**< ECO Register 11, offset: 0x30 */
  __IO uint32_t CIU2_ECO_12;                       /**< ECO Register 12, offset: 0x34 */
  __IO uint32_t CIU2_ECO_13;                       /**< ECO Register 13, offset: 0x38 */
  __IO uint32_t CIU2_ECO_14;                       /**< ECO Register 14, offset: 0x3C */
  __IO uint32_t CIU2_ECO_15;                       /**< ECO Register 15, offset: 0x40 */
       uint8_t RESERVED_0[188];
  __IO uint32_t CIU2_CLK_ENABLE4;                  /**< Clock Enable 4, offset: 0x100 */
  __IO uint32_t CIU2_CLK_ENABLE5;                  /**< Clock Enable 5, offset: 0x104 */
  __IO uint32_t CIU2_CLK_CPU2CLK_CTRL;             /**< CPU2_AHB2 Clock Control, offset: 0x108 */
  __IO uint32_t CIU2_CLK_UARTCLK_CTRL;             /**< UART Clock Control, offset: 0x10C */
  __IO uint32_t CIU2_CLK_LBU2_BTRTU1_CTRL;         /**< LBU2 BT_RTU1 Clock Control, offset: 0x110 */
       uint8_t RESERVED_1[4];
  __IO uint32_t CIU2_CLK_CP15_DIS3;                /**< Clock Auto Shut-off Enable3, offset: 0x118 */
  __IO uint32_t CIU2_RST_SW3;                      /**< Software Module Reset, offset: 0x11C */
  __IO uint32_t CIU2_MEM_WRTC3;                    /**< Memory WRTC Control 3, offset: 0x120 */
  __IO uint32_t CIU2_MEM_WRTC4;                    /**< Memory WRTC Control 4, offset: 0x124 */
  __IO uint32_t CIU2_MEM_PWDN3;                    /**< Memory Powerdown Control, offset: 0x128 */
       uint8_t RESERVED_2[20];
  __IO uint32_t CIU2_BLE_CTRL;                     /**< BLE Control and Status, offset: 0x140 */
  __I  uint32_t CIU2_AHB2_TO_LAST_ADDR;            /**< AHB2 Timeout Last Address, offset: 0x144 */
  __I  uint32_t CIU2_AHB2_TO_CUR_ADDR;             /**< AHB2 Current Timeout Address, offset: 0x148 */
  __IO uint32_t CIU2_AHB2_TO_CTRL;                 /**< AHB2 ARB Control, offset: 0x14C */
  __IO uint32_t CIU2_AHB2_SMU1_ACCESS_ADDR;        /**< AHB2 to SMU1 Accessible Address, offset: 0x150 */
  __IO uint32_t CIU2_AHB2_SMU1_ACCESS_MASK;        /**< AHB2 to SMU1 Accessible Mask, offset: 0x154 */
  __IO uint32_t CIU2_CPU2_FABRIC_ARB_CTRL;         /**< CPU2 fabric arbiter control, offset: 0x158 */
  __IO uint32_t CIU2_CPU2_ICODE_INV_ADDR_CTRL;     /**< CPU2 Icode invalid address access control, offset: 0x15C */
  __I  uint32_t CIU2_CPU2_ICODE_INV_ADDR;          /**< CPU2 Icode invalid address, offset: 0x160 */
  __IO uint32_t CIU2_CPU2_DCODE_INV_ADDR_CTRL;     /**< CPU2 Dcode invalid address access control, offset: 0x164 */
  __I  uint32_t CIU2_CPU2_DCODE_INV_ADDR;          /**< CPU2 Dcode invalid address, offset: 0x168 */
  __IO uint32_t CIU2_CPU_CPU2_CTRL;                /**< CPU2 control register, offset: 0x16C */
  __IO uint32_t CIU2_BRF_CTRL;                     /**< BRF Control and Status, offset: 0x170 */
  __IO uint32_t CIU2_BRF_EXTRA_PORT;               /**< BRF Extra Port Connection, offset: 0x174 */
       uint8_t RESERVED_3[4];
  __IO uint32_t CIU2_BRF_ECO_CTRL;                 /**< BRF ECO Control, offset: 0x17C */
  __IO uint32_t CIU2_BTU_CTRL;                     /**< BTU Control and Status, offset: 0x180 */
  __IO uint32_t CIU2_BT_PS;                        /**< BT Clock Power Save, offset: 0x184 */
  __IO uint32_t CIU2_BT_PS2;                       /**< BT Clock Power Save 2, offset: 0x188 */
  __IO uint32_t CIU2_BT_REF_CTRL;                  /**< BT Ref Control, offset: 0x18C */
       uint8_t RESERVED_4[4];
  __IO uint32_t CIU2_BT_PS3;                       /**< BT Clock Power Save 3, offset: 0x194 */
  __IO uint32_t CIU2_BTU_ECO_CTRL;                 /**< BTU ECO Control, offset: 0x198 */
       uint8_t RESERVED_5[4];
  __IO uint32_t CIU2_INT_MASK;                     /**< CIU2 Interrupt Mask, offset: 0x1A0 */
  __IO uint32_t CIU2_INT_SELECT;                   /**< CIU2 Interrupt Select, offset: 0x1A4 */
  __IO uint32_t CIU2_INT_EVENT_MASK;               /**< CIU2 Interrupt Event Mask, offset: 0x1A8 */
  __I  uint32_t CIU2_INT_STATUS;                   /**< CIU2 Interrupt Status, offset: 0x1AC */
  __IO uint32_t CPU2_ERR_INT_MASK;                 /**< CPU2 ERR Interrupt Mask, offset: 0x1B0 */
  __IO uint32_t CPU2_ERR_INT_SELECT;               /**< CPU2 ERR Interrupt Clear Select, offset: 0x1B4 */
  __IO uint32_t CPU2_ERR_INT_EVENT_MASK;           /**< CPU2 ERR Interrupt Event Mask, offset: 0x1B8 */
  __I  uint32_t CPU2_ERR_INT_STATUS;               /**< CPU2 ERR Interrupt Status, offset: 0x1BC */
  __IO uint32_t CPU2_ERR_INT2_MASK;                /**< CPU2 ERR Interrupt 2 Mask, offset: 0x1C0 */
  __IO uint32_t CPU2_ERR_INT2_SELECT;              /**< CPU2 ERR Interrupt 2 Clear Select, offset: 0x1C4 */
  __IO uint32_t CPU2_ERR_INT2_EVENT_MASK;          /**< CPU2 ERR Interrupt 2 Event Mask, offset: 0x1C8 */
  __I  uint32_t CPU2_ERR_INT2_STATUS;              /**< CPU2 ERR Interrupt 2 Status, offset: 0x1CC */
  __IO uint32_t CIU2_CPU_CPU2_MSG_CTRL;            /**< CPU2 message register, offset: 0x1D0 */
  __IO uint32_t CIU2_IMU_CPU1_WR_MSG_TO_CPU2;      /**< CPU1 write message to CPU2, offset: 0x1D4 */
  __I  uint32_t CIU2_IMU_CPU1_RD_MSG_FROM_CPU2;    /**< CPU1 read message from CPU2, offset: 0x1D8 */
  __I  uint32_t CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS; /**< CPU1 to CPU2 message FIFO status, offset: 0x1DC */
  __IO uint32_t CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL;  /**< CPU1 to CPU2 message FIFO control, offset: 0x1E0 */
  __I  uint32_t CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG; /**< CPU2 last message read (from cpu1), offset: 0x1E4 */
  __IO uint32_t CIU2_IMU_CPU2_WR_MSG_TO_CPU1;      /**< CPU2 write message to CPU1, offset: 0x1E8 */
  __I  uint32_t CIU2_IMU_CPU2_RD_MSG_FROM_CPU1;    /**< CPU2 read message from CPU1, offset: 0x1EC */
  __I  uint32_t CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS; /**< CPU2 to CPU1 message FIFO status, offset: 0x1F0 */
  __IO uint32_t CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL;  /**< CPU2 to CPU1 message FIFO control, offset: 0x1F4 */
  __I  uint32_t CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG; /**< CPU1 last message read (from cpu2), offset: 0x1F8 */
       uint8_t RESERVED_6[4];
  __IO uint32_t CIU2_BCA1_CPU2_INT_MASK;           /**< BCA1 to CPU2 Interrupt Mask, offset: 0x200 */
  __IO uint32_t CIU2_BCA1_CPU2_INT_SELECT;         /**< BCA1 to CPU2 Interrupt Select, offset: 0x204 */
  __IO uint32_t CIU2_BCA1_CPU2_INT_EVENT_MASK;     /**< BCA1 to CPU2 Interrupt Event Mask, offset: 0x208 */
  __I  uint32_t CIU2_BCA1_CPU2_INT_STATUS;         /**< BCA1 to CPU2 Interrupt Status, offset: 0x20C */
  __IO uint32_t CIU2_APU_BYPASS1;                  /**< CIU2 APU Bypass Register 1, offset: 0x210 */
  __IO uint32_t CIU2_CPU2_LMU_STA_BYPASS0;         /**< LMU static bank control byapss0 Register for CPU2 mem, offset: 0x214 */
  __IO uint32_t CIU2_CPU2_LMU_STA_BYPASS1;         /**< LMU static bank control byapss1 Register for CPU2, offset: 0x218 */
  __IO uint32_t CIU2_CPU2_LMU_STA_BYPASS2;         /**< LMU static bank byapss2 Register for CPU2, offset: 0x21C */
  __IO uint32_t CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS;  /**< LMU G2Bist control byapss Register for CPU2, offset: 0x220 */
       uint8_t RESERVED_7[8];
  __IO uint32_t CIU2_APU_PWR_CTRL_BYPASS1;         /**< APU power control Bypass Register 1, offset: 0x22C */
  __IO uint32_t CIU2_AHB2AHB_BRIDGE_CTRL;          /**< AHB2AHB Bridge Control Register, offset: 0x230 */
  __IO uint32_t CIU2_AHB1_AHB2_TO_CLEAR;           /**< AHB1 AHB2 timeout logic clear register, offset: 0x234 */
  __I  uint32_t CIU2_CPU_CPU2_DBG_STAT;            /**< CPU2 debug register, offset: 0x238 */
  __IO uint32_t CIU2_CPU_CPU1_CTRL;                /**< CPU1 control register, offset: 0x23C */
  __IO uint32_t CIU2_TESTBUS_CTRL;                 /**< CPU2 debug register, offset: 0x240 */
       uint8_t RESERVED_8[12];
  __IO uint32_t CIU2_LBC_CTRL;                     /**< LBC Control and Status, offset: 0x250 */
  __IO uint32_t CIU2_LBC_SLPCLK_NCO;               /**< LBC NCO Step for Sleep Clock, offset: 0x254 */
} CIU2_Type;

/* ----------------------------------------------------------------------------
   -- CIU2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CIU2_Register_Masks CIU2 Register Masks
 * @{
 */

/*! @name CIU2_CLK_ENABLE - Clock enable */
/*! @{ */

#define CIU2_CIU2_CLK_ENABLE_AHB2_CLK_ENABLE_MASK (0x20000000U)
#define CIU2_CIU2_CLK_ENABLE_AHB2_CLK_ENABLE_SHIFT (29U)
/*! ahb2_clk_enable - Clock ahb2_clk enable signal. Ahb2_clk enable. 1: enable, 0: disable */
#define CIU2_CIU2_CLK_ENABLE_AHB2_CLK_ENABLE(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE_AHB2_CLK_ENABLE_SHIFT)) & CIU2_CIU2_CLK_ENABLE_AHB2_CLK_ENABLE_MASK)

#define CIU2_CIU2_CLK_ENABLE_CPU1_DIV_CLK_ENABLE_MASK (0x40000000U)
#define CIU2_CIU2_CLK_ENABLE_CPU1_DIV_CLK_ENABLE_SHIFT (30U)
/*! cpu1_div_clk_enable - Clock cpu1_div_clk enable signal. cpu1_div_clk enable. 1: enable, 0: disable */
#define CIU2_CIU2_CLK_ENABLE_CPU1_DIV_CLK_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE_CPU1_DIV_CLK_ENABLE_SHIFT)) & CIU2_CIU2_CLK_ENABLE_CPU1_DIV_CLK_ENABLE_MASK)

#define CIU2_CIU2_CLK_ENABLE_SOC_AHB_CLK_SEL_MASK (0x80000000U)
#define CIU2_CIU2_CLK_ENABLE_SOC_AHB_CLK_SEL_SHIFT (31U)
/*! soc_ahb_clk_sel - Clock selection for soc_ahb_clk. 0: AHB2_CLK, 1: CPU1_CLK_DIV */
#define CIU2_CIU2_CLK_ENABLE_SOC_AHB_CLK_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE_SOC_AHB_CLK_SEL_SHIFT)) & CIU2_CIU2_CLK_ENABLE_SOC_AHB_CLK_SEL_MASK)
/*! @} */

/*! @name CIU2_ECO_0 - ECO Register 0 */
/*! @{ */

#define CIU2_CIU2_ECO_0_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_0_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_0_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_0_SPARE_SHIFT)) & CIU2_CIU2_ECO_0_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_1 - ECO Register 1 */
/*! @{ */

#define CIU2_CIU2_ECO_1_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_1_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_1_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_1_SPARE_SHIFT)) & CIU2_CIU2_ECO_1_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_2 - ECO Register 2 */
/*! @{ */

#define CIU2_CIU2_ECO_2_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_2_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_2_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_2_SPARE_SHIFT)) & CIU2_CIU2_ECO_2_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_3 - ECO Register 3 */
/*! @{ */

#define CIU2_CIU2_ECO_3_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_3_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_3_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_3_SPARE_SHIFT)) & CIU2_CIU2_ECO_3_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_4 - ECO Register 4 */
/*! @{ */

#define CIU2_CIU2_ECO_4_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_4_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_4_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_4_SPARE_SHIFT)) & CIU2_CIU2_ECO_4_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_5 - ECO Register 5 */
/*! @{ */

#define CIU2_CIU2_ECO_5_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_5_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_5_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_5_SPARE_SHIFT)) & CIU2_CIU2_ECO_5_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_6 - ECO Register 6 */
/*! @{ */

#define CIU2_CIU2_ECO_6_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_6_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_6_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_6_SPARE_SHIFT)) & CIU2_CIU2_ECO_6_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_7 - ECO Register 7 */
/*! @{ */

#define CIU2_CIU2_ECO_7_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_7_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_7_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_7_SPARE_SHIFT)) & CIU2_CIU2_ECO_7_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_8 - ECO Register 8 */
/*! @{ */

#define CIU2_CIU2_ECO_8_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_8_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_8_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_8_SPARE_SHIFT)) & CIU2_CIU2_ECO_8_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_9 - ECO Register 9 */
/*! @{ */

#define CIU2_CIU2_ECO_9_SPARE_MASK               (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_9_SPARE_SHIFT              (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_9_SPARE(x)                 (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_9_SPARE_SHIFT)) & CIU2_CIU2_ECO_9_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_10 - ECO Register 10 */
/*! @{ */

#define CIU2_CIU2_ECO_10_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_10_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_10_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_10_SPARE_SHIFT)) & CIU2_CIU2_ECO_10_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_11 - ECO Register 11 */
/*! @{ */

#define CIU2_CIU2_ECO_11_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_11_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_11_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_11_SPARE_SHIFT)) & CIU2_CIU2_ECO_11_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_12 - ECO Register 12 */
/*! @{ */

#define CIU2_CIU2_ECO_12_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_12_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_12_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_12_SPARE_SHIFT)) & CIU2_CIU2_ECO_12_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_13 - ECO Register 13 */
/*! @{ */

#define CIU2_CIU2_ECO_13_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_13_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_13_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_13_SPARE_SHIFT)) & CIU2_CIU2_ECO_13_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_14 - ECO Register 14 */
/*! @{ */

#define CIU2_CIU2_ECO_14_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_14_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_14_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_14_SPARE_SHIFT)) & CIU2_CIU2_ECO_14_SPARE_MASK)
/*! @} */

/*! @name CIU2_ECO_15 - ECO Register 15 */
/*! @{ */

#define CIU2_CIU2_ECO_15_SPARE_MASK              (0xFFFFFFFFU)
#define CIU2_CIU2_ECO_15_SPARE_SHIFT             (0U)
/*! spare - Eco Reserve Register */
#define CIU2_CIU2_ECO_15_SPARE(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_ECO_15_SPARE_SHIFT)) & CIU2_CIU2_ECO_15_SPARE_MASK)
/*! @} */

/*! @name CIU2_CLK_ENABLE4 - Clock Enable 4 */
/*! @{ */

#define CIU2_CIU2_CLK_ENABLE4_BIST_AHB2_CLK_GATING_EN_MASK (0x1U)
#define CIU2_CIU2_CLK_ENABLE4_BIST_AHB2_CLK_GATING_EN_SHIFT (0U)
/*! bist_ahb2_clk_gating_en - CPU2 Redbist and Rombist Clock for ITCM/DTCM/SQU/BROM */
#define CIU2_CIU2_CLK_ENABLE4_BIST_AHB2_CLK_GATING_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BIST_AHB2_CLK_GATING_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BIST_AHB2_CLK_GATING_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_ADDR_MASK_DIS_MASK (0x2U)
#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_ADDR_MASK_DIS_SHIFT (1U)
/*! bru_ahb2_addr_mask_dis - CPU2 ROM Address Mask Selection */
#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_ADDR_MASK_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_ADDR_MASK_DIS_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_ADDR_MASK_DIS_MASK)

#define CIU2_CIU2_CLK_ENABLE4_ITCM_AHB2_DYN_CLK_GATING_DIS_MASK (0x4U)
#define CIU2_CIU2_CLK_ENABLE4_ITCM_AHB2_DYN_CLK_GATING_DIS_SHIFT (2U)
/*! itcm_ahb2_dyn_clk_gating_dis - CPU2 ITCM Dynamic Clock Gating Feature */
#define CIU2_CIU2_CLK_ENABLE4_ITCM_AHB2_DYN_CLK_GATING_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_ITCM_AHB2_DYN_CLK_GATING_DIS_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_ITCM_AHB2_DYN_CLK_GATING_DIS_MASK)

#define CIU2_CIU2_CLK_ENABLE4_DTCM_AHB2_DYN_CLK_GATING_DIS_MASK (0x8U)
#define CIU2_CIU2_CLK_ENABLE4_DTCM_AHB2_DYN_CLK_GATING_DIS_SHIFT (3U)
/*! dtcm_ahb2_dyn_clk_gating_dis - CPU2 DTCM Dynamic Clock Gating Feature */
#define CIU2_CIU2_CLK_ENABLE4_DTCM_AHB2_DYN_CLK_GATING_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_DTCM_AHB2_DYN_CLK_GATING_DIS_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_DTCM_AHB2_DYN_CLK_GATING_DIS_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_DYN_CLK_GATING_DIS_MASK (0x10U)
#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_DYN_CLK_GATING_DIS_SHIFT (4U)
/*! bru_ahb2_dyn_clk_gating_dis - CPU2 ROM Dynamic Clock Gating Feature */
#define CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_DYN_CLK_GATING_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_DYN_CLK_GATING_DIS_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BRU_AHB2_DYN_CLK_GATING_DIS_MASK)

#define CIU2_CIU2_CLK_ENABLE4_SMU2_DYN_CLK_GATING_DIS_MASK (0x20U)
#define CIU2_CIU2_CLK_ENABLE4_SMU2_DYN_CLK_GATING_DIS_SHIFT (5U)
/*! smu2_dyn_clk_gating_dis - SMU2 Dynamic Clock Gating Feature */
#define CIU2_CIU2_CLK_ENABLE4_SMU2_DYN_CLK_GATING_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_SMU2_DYN_CLK_GATING_DIS_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_SMU2_DYN_CLK_GATING_DIS_MASK)

#define CIU2_CIU2_CLK_ENABLE4_EBRAM_BIST_CLK_EN_MASK (0x100U)
#define CIU2_CIU2_CLK_ENABLE4_EBRAM_BIST_CLK_EN_SHIFT (8U)
/*! ebram_bist_clk_en - EBRAM BIST Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_EBRAM_BIST_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_EBRAM_BIST_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_EBRAM_BIST_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BT_ECLK_EN_MASK    (0x200U)
#define CIU2_CIU2_CLK_ENABLE4_BT_ECLK_EN_SHIFT   (9U)
/*! bt_eclk_en - BTU EBC Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BT_ECLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BT_ECLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BT_ECLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BT_4MCLK_EN_MASK   (0x400U)
#define CIU2_CIU2_CLK_ENABLE4_BT_4MCLK_EN_SHIFT  (10U)
/*! bt_4mclk_en - BTU 4 MHz Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BT_4MCLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BT_4MCLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BT_4MCLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BTU_AHB_CLK_EN_MASK (0x2000U)
#define CIU2_CIU2_CLK_ENABLE4_BTU_AHB_CLK_EN_SHIFT (13U)
/*! btu_ahb_clk_en - BTU AHB Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BTU_AHB_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BTU_AHB_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BTU_AHB_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_SIU_CLK_EN_MASK    (0x4000U)
#define CIU2_CIU2_CLK_ENABLE4_SIU_CLK_EN_SHIFT   (14U)
/*! siu_clk_en - BT SIU (UART) clock enable */
#define CIU2_CIU2_CLK_ENABLE4_SIU_CLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_SIU_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_SIU_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_SMU2_AHB_CLK_EN_MASK (0x10000U)
#define CIU2_CIU2_CLK_ENABLE4_SMU2_AHB_CLK_EN_SHIFT (16U)
/*! smu2_ahb_clk_en - SMU2 AHB Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_SMU2_AHB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_SMU2_AHB_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_SMU2_AHB_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_HPU2_CIU_CLK_EN_MASK (0x80000U)
#define CIU2_CIU2_CLK_ENABLE4_HPU2_CIU_CLK_EN_SHIFT (19U)
/*! hpu2_ciu_clk_en - HPU2 CIU Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_HPU2_CIU_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_HPU2_CIU_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_HPU2_CIU_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BLE_AHB_CLK_EN_MASK (0x100000U)
#define CIU2_CIU2_CLK_ENABLE4_BLE_AHB_CLK_EN_SHIFT (20U)
/*! ble_ahb_clk_en - BLE ARM Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BLE_AHB_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BLE_AHB_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BLE_AHB_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BLE_SYS_CLK_EN_MASK (0x200000U)
#define CIU2_CIU2_CLK_ENABLE4_BLE_SYS_CLK_EN_SHIFT (21U)
/*! ble_sys_clk_en - BLE SYS Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BLE_SYS_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BLE_SYS_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BLE_SYS_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BLE_AEU_CLK_EN_MASK (0x400000U)
#define CIU2_CIU2_CLK_ENABLE4_BLE_AEU_CLK_EN_SHIFT (22U)
/*! ble_aeu_clk_en - BT/BLE AEU Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BLE_AEU_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BLE_AEU_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BLE_AEU_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BT_16M_CLK_EN_MASK (0x800000U)
#define CIU2_CIU2_CLK_ENABLE4_BT_16M_CLK_EN_SHIFT (23U)
/*! bt_16m_clk_en - BT 16MHz Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_BT_16M_CLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BT_16M_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BT_16M_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_DBUS_CLK_EN_MASK   (0x1000000U)
#define CIU2_CIU2_CLK_ENABLE4_DBUS_CLK_EN_SHIFT  (24U)
/*! dbus_clk_en - BLE DBUS Clock Enable */
#define CIU2_CIU2_CLK_ENABLE4_DBUS_CLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_DBUS_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_DBUS_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_SIU_AHB2_CLK_EN_MASK (0x20000000U)
#define CIU2_CIU2_CLK_ENABLE4_SIU_AHB2_CLK_EN_SHIFT (29U)
/*! siu_ahb2_clk_en - BT SIU (UART) AHB clock enable */
#define CIU2_CIU2_CLK_ENABLE4_SIU_AHB2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_SIU_AHB2_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_SIU_AHB2_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE4_BTRTU1_CLK_EN_MASK (0x40000000U)
#define CIU2_CIU2_CLK_ENABLE4_BTRTU1_CLK_EN_SHIFT (30U)
/*! btrtu1_clk_en - BT RTU1 clock enable */
#define CIU2_CIU2_CLK_ENABLE4_BTRTU1_CLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE4_BTRTU1_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE4_BTRTU1_CLK_EN_MASK)
/*! @} */

/*! @name CIU2_CLK_ENABLE5 - Clock Enable 5 */
/*! @{ */

#define CIU2_CIU2_CLK_ENABLE5_ITCM_AHB2_CLK_EN_MASK (0x7U)
#define CIU2_CIU2_CLK_ENABLE5_ITCM_AHB2_CLK_EN_SHIFT (0U)
/*! itcm_ahb2_clk_en - Enable CPU2 ITCM Banks 1-2 */
#define CIU2_CIU2_CLK_ENABLE5_ITCM_AHB2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_ITCM_AHB2_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_ITCM_AHB2_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_BT_ADMA_AHB_CLK_EN_MASK (0x8U)
#define CIU2_CIU2_CLK_ENABLE5_BT_ADMA_AHB_CLK_EN_SHIFT (3U)
/*! bt_adma_ahb_clk_en - BT ADMA AHB Clock Enable */
#define CIU2_CIU2_CLK_ENABLE5_BT_ADMA_AHB_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_BT_ADMA_AHB_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_BT_ADMA_AHB_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_CIU2_REG_CLK_EN_MASK (0x80U)
#define CIU2_CIU2_CLK_ENABLE5_CIU2_REG_CLK_EN_SHIFT (7U)
/*! ciu2_reg_clk_en - CIU2 Reg Clock Enable */
#define CIU2_CIU2_CLK_ENABLE5_CIU2_REG_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_CIU2_REG_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_CIU2_REG_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_BR_AHB2_CLK_EN_MASK (0x7FFF00U)
#define CIU2_CIU2_CLK_ENABLE5_BR_AHB2_CLK_EN_SHIFT (8U)
/*! br_ahb2_clk_en - CPU2 BROM AHB Clock Enable */
#define CIU2_CIU2_CLK_ENABLE5_BR_AHB2_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_BR_AHB2_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_BR_AHB2_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_BTU_MCLK_EN_MASK   (0x800000U)
#define CIU2_CIU2_CLK_ENABLE5_BTU_MCLK_EN_SHIFT  (23U)
/*! btu_mclk_en - BTU MCLK Enalbe */
#define CIU2_CIU2_CLK_ENABLE5_BTU_MCLK_EN(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_BTU_MCLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_BTU_MCLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_SMU2_BANK_CLK_EN_MASK (0x7000000U)
#define CIU2_CIU2_CLK_ENABLE5_SMU2_BANK_CLK_EN_SHIFT (24U)
/*! smu2_bank_clk_en - SMU2 bank Clock Enable */
#define CIU2_CIU2_CLK_ENABLE5_SMU2_BANK_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_SMU2_BANK_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_SMU2_BANK_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_SIF_CLK_SEL_MASK   (0x8000000U)
#define CIU2_CIU2_CLK_ENABLE5_SIF_CLK_SEL_SHIFT  (27U)
/*! sif_clk_sel - SIF Clock Select */
#define CIU2_CIU2_CLK_ENABLE5_SIF_CLK_SEL(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_SIF_CLK_SEL_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_SIF_CLK_SEL_MASK)

#define CIU2_CIU2_CLK_ENABLE5_CPU2_GATEHCLK_EN_MASK (0x10000000U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_GATEHCLK_EN_SHIFT (28U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_GATEHCLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_CPU2_GATEHCLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_CPU2_GATEHCLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_CPU2_FABRIC_CLK_EN_MASK (0x20000000U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_FABRIC_CLK_EN_SHIFT (29U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_FABRIC_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_CPU2_FABRIC_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_CPU2_FABRIC_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_CPU2_MEM_SLV_CLK_EN_MASK (0x40000000U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_MEM_SLV_CLK_EN_SHIFT (30U)
#define CIU2_CIU2_CLK_ENABLE5_CPU2_MEM_SLV_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_CPU2_MEM_SLV_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_CPU2_MEM_SLV_CLK_EN_MASK)

#define CIU2_CIU2_CLK_ENABLE5_SIF_AHB2_CLK_EN_MASK (0x80000000U)
#define CIU2_CIU2_CLK_ENABLE5_SIF_AHB2_CLK_EN_SHIFT (31U)
/*! sif_ahb2_clk_en - SIF ahb2 Clock Enalbe */
#define CIU2_CIU2_CLK_ENABLE5_SIF_AHB2_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_ENABLE5_SIF_AHB2_CLK_EN_SHIFT)) & CIU2_CIU2_CLK_ENABLE5_SIF_AHB2_CLK_EN_MASK)
/*! @} */

/*! @name CIU2_CLK_CPU2CLK_CTRL - CPU2_AHB2 Clock Control */
/*! @{ */

#define CIU2_CIU2_CLK_CPU2CLK_CTRL_T1_FREQ_SEL_MASK (0xFU)
#define CIU2_CIU2_CLK_CPU2CLK_CTRL_T1_FREQ_SEL_SHIFT (0U)
/*! t1_freq_sel - AHB2 Clock Frequency Select */
#define CIU2_CIU2_CLK_CPU2CLK_CTRL_T1_FREQ_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CPU2CLK_CTRL_T1_FREQ_SEL_SHIFT)) & CIU2_CIU2_CLK_CPU2CLK_CTRL_T1_FREQ_SEL_MASK)
/*! @} */

/*! @name CIU2_CLK_UARTCLK_CTRL - UART Clock Control */
/*! @{ */

#define CIU2_CIU2_CLK_UARTCLK_CTRL_REFCLK_SEL_MASK (0x1U)
#define CIU2_CIU2_CLK_UARTCLK_CTRL_REFCLK_SEL_SHIFT (0U)
/*! refclk_sel - Reference Clock Select */
#define CIU2_CIU2_CLK_UARTCLK_CTRL_REFCLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_UARTCLK_CTRL_REFCLK_SEL_SHIFT)) & CIU2_CIU2_CLK_UARTCLK_CTRL_REFCLK_SEL_MASK)

#define CIU2_CIU2_CLK_UARTCLK_CTRL_NCO_STEP_SIZE_MASK (0xFFFFFF80U)
#define CIU2_CIU2_CLK_UARTCLK_CTRL_NCO_STEP_SIZE_SHIFT (7U)
/*! nco_step_size - Programmable UART Clock Frequency */
#define CIU2_CIU2_CLK_UARTCLK_CTRL_NCO_STEP_SIZE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_UARTCLK_CTRL_NCO_STEP_SIZE_SHIFT)) & CIU2_CIU2_CLK_UARTCLK_CTRL_NCO_STEP_SIZE_MASK)
/*! @} */

/*! @name CIU2_CLK_LBU2_BTRTU1_CTRL - LBU2 BT_RTU1 Clock Control */
/*! @{ */

#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_LBU2_USE_REFCLK_MASK (0x2U)
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_LBU2_USE_REFCLK_SHIFT (1U)
/*! lbu2_use_refclk - Static bit set by FW based on Reference Clock Frequency. If reference clock
 *    frequency is lower and LBU can not support high baud rate of UART, then FW will set
 *    soc_use_ref_mode = 0. This is an indication for Bluetooth subsystem that there is some IP which need PLL
 *    to function which is LBU in this case.
 */
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_LBU2_USE_REFCLK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_LBU2_USE_REFCLK_SHIFT)) & CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_LBU2_USE_REFCLK_MASK)

#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_TIMER1_USE_SLP_CLK_MASK (0x800U)
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_TIMER1_USE_SLP_CLK_SHIFT (11U)
/*! btrtu1_timer1_use_slp_clk - Timer 1 BT_RTU1 Clock */
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_TIMER1_USE_SLP_CLK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_TIMER1_USE_SLP_CLK_SHIFT)) & CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_TIMER1_USE_SLP_CLK_MASK)

#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_USE_REF_CLK_MASK (0x1000U)
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_USE_REF_CLK_SHIFT (12U)
/*! btrtu1_use_ref_clk - Static bit set by FW. If it is required that timers need not be programmed
 *    with dynamic switching of T1/Reference, the BT_RTU1 source clock is set on reference clock so
 *    that the timer are not distrubed.
 */
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_USE_REF_CLK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_USE_REF_CLK_SHIFT)) & CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_USE_REF_CLK_MASK)

#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_DBG_CLK_CTRL_MASK (0x8000U)
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_DBG_CLK_CTRL_SHIFT (15U)
#define CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_DBG_CLK_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_DBG_CLK_CTRL_SHIFT)) & CIU2_CIU2_CLK_LBU2_BTRTU1_CTRL_BTRTU1_DBG_CLK_CTRL_MASK)
/*! @} */

/*! @name CIU2_CLK_CP15_DIS3 - Clock Auto Shut-off Enable3 */
/*! @{ */

#define CIU2_CIU2_CLK_CP15_DIS3_BR_AHB2_CLK_MASK (0xFFFFU)
#define CIU2_CIU2_CLK_CP15_DIS3_BR_AHB2_CLK_SHIFT (0U)
/*! br_ahb2_clk - BRU_AHB2 Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_BR_AHB2_CLK(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_BR_AHB2_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_BR_AHB2_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_IMEM_AHB2_CLK_MASK (0x1E00000U)
#define CIU2_CIU2_CLK_CP15_DIS3_IMEM_AHB2_CLK_SHIFT (21U)
/*! imem_ahb2_clk - IMEM_AHB2 Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_IMEM_AHB2_CLK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_IMEM_AHB2_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_IMEM_AHB2_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_DMEM_AHB2_CLK_MASK (0x6000000U)
#define CIU2_CIU2_CLK_CP15_DIS3_DMEM_AHB2_CLK_SHIFT (25U)
/*! dmem_ahb2_clk - DMEM_AHB2 Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_DMEM_AHB2_CLK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_DMEM_AHB2_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_DMEM_AHB2_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_ARB_AHB2_CLK_MASK (0x10000000U)
#define CIU2_CIU2_CLK_CP15_DIS3_ARB_AHB2_CLK_SHIFT (28U)
/*! arb_ahb2_clk - AHB2 Arbiter Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_ARB_AHB2_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_ARB_AHB2_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_ARB_AHB2_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_DEC_AHB2_CLK_MASK (0x20000000U)
#define CIU2_CIU2_CLK_CP15_DIS3_DEC_AHB2_CLK_SHIFT (29U)
/*! dec_ahb2_clk - AHB2 Decoder Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_DEC_AHB2_CLK(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_DEC_AHB2_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_DEC_AHB2_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_BTU_AHB_CLK_MASK (0x40000000U)
#define CIU2_CIU2_CLK_CP15_DIS3_BTU_AHB_CLK_SHIFT (30U)
/*! btu_ahb_clk - BTU Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_BTU_AHB_CLK(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_BTU_AHB_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_BTU_AHB_CLK_MASK)

#define CIU2_CIU2_CLK_CP15_DIS3_BLE_AHB_CLK_MASK (0x80000000U)
#define CIU2_CIU2_CLK_CP15_DIS3_BLE_AHB_CLK_SHIFT (31U)
/*! ble_ahb_clk - BLE Shut Off */
#define CIU2_CIU2_CLK_CP15_DIS3_BLE_AHB_CLK(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CLK_CP15_DIS3_BLE_AHB_CLK_SHIFT)) & CIU2_CIU2_CLK_CP15_DIS3_BLE_AHB_CLK_MASK)
/*! @} */

/*! @name CIU2_RST_SW3 - Software Module Reset */
/*! @{ */

#define CIU2_CIU2_RST_SW3_BTU_AHB_CLK__MASK      (0x1U)
#define CIU2_CIU2_RST_SW3_BTU_AHB_CLK__SHIFT     (0U)
/*! btu_ahb_clk_ - BTU (ARM_Clk) Soft Reset */
#define CIU2_CIU2_RST_SW3_BTU_AHB_CLK_(x)        (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BTU_AHB_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_BTU_AHB_CLK__MASK)

#define CIU2_CIU2_RST_SW3_BLE_SOC__MASK          (0x2U)
#define CIU2_CIU2_RST_SW3_BLE_SOC__SHIFT         (1U)
/*! ble_soc_ - BLE SoC Soft Reset */
#define CIU2_CIU2_RST_SW3_BLE_SOC_(x)            (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BLE_SOC__SHIFT)) & CIU2_CIU2_RST_SW3_BLE_SOC__MASK)

#define CIU2_CIU2_RST_SW3_BT_COMMON__MASK        (0x4U)
#define CIU2_CIU2_RST_SW3_BT_COMMON__SHIFT       (2U)
/*! bt_common_ - BT Common Soft Rest */
#define CIU2_CIU2_RST_SW3_BT_COMMON_(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BT_COMMON__SHIFT)) & CIU2_CIU2_RST_SW3_BT_COMMON__MASK)

#define CIU2_CIU2_RST_SW3_CPU2_CORE__MASK        (0x10U)
#define CIU2_CIU2_RST_SW3_CPU2_CORE__SHIFT       (4U)
/*! cpu2_core_ - CPU2 core reset */
#define CIU2_CIU2_RST_SW3_CPU2_CORE_(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_CPU2_CORE__SHIFT)) & CIU2_CIU2_RST_SW3_CPU2_CORE__MASK)

#define CIU2_CIU2_RST_SW3_CPU2_TCM__MASK         (0x20U)
#define CIU2_CIU2_RST_SW3_CPU2_TCM__SHIFT        (5U)
/*! cpu2_tcm_ - CPU2 TCM/DMA/Arbiter reset */
#define CIU2_CIU2_RST_SW3_CPU2_TCM_(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_CPU2_TCM__SHIFT)) & CIU2_CIU2_RST_SW3_CPU2_TCM__MASK)

#define CIU2_CIU2_RST_SW3_ARB_AHB2_CLK__MASK     (0x80U)
#define CIU2_CIU2_RST_SW3_ARB_AHB2_CLK__SHIFT    (7U)
/*! arb_ahb2_clk_ - AHB2 Arbiter Soft Reset */
#define CIU2_CIU2_RST_SW3_ARB_AHB2_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_ARB_AHB2_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_ARB_AHB2_CLK__MASK)

#define CIU2_CIU2_RST_SW3_DEC_AHB2_CLK__MASK     (0x100U)
#define CIU2_CIU2_RST_SW3_DEC_AHB2_CLK__SHIFT    (8U)
/*! dec_ahb2_clk_ - AHB2 Decoder Mux Soft Reset */
#define CIU2_CIU2_RST_SW3_DEC_AHB2_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_DEC_AHB2_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_DEC_AHB2_CLK__MASK)

#define CIU2_CIU2_RST_SW3_BRU_AHB2_CLK__MASK     (0x200U)
#define CIU2_CIU2_RST_SW3_BRU_AHB2_CLK__SHIFT    (9U)
/*! bru_ahb2_clk_ - BRU_AHB2 Soft Reset */
#define CIU2_CIU2_RST_SW3_BRU_AHB2_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BRU_AHB2_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_BRU_AHB2_CLK__MASK)

#define CIU2_CIU2_RST_SW3_BT_UART_N_MASK         (0x400U)
#define CIU2_CIU2_RST_SW3_BT_UART_N_SHIFT        (10U)
/*! bt_uart_n - BT UART soft reset */
#define CIU2_CIU2_RST_SW3_BT_UART_N(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BT_UART_N_SHIFT)) & CIU2_CIU2_RST_SW3_BT_UART_N_MASK)

#define CIU2_CIU2_RST_SW3_SIU_AHB2_CLK_N_MASK    (0x800U)
#define CIU2_CIU2_RST_SW3_SIU_AHB2_CLK_N_SHIFT   (11U)
/*! siu_ahb2_clk_n - BT SIU (UART) AHB soft reset */
#define CIU2_CIU2_RST_SW3_SIU_AHB2_CLK_N(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_SIU_AHB2_CLK_N_SHIFT)) & CIU2_CIU2_RST_SW3_SIU_AHB2_CLK_N_MASK)

#define CIU2_CIU2_RST_SW3_SMU2_AHB_CLK__MASK     (0x10000U)
#define CIU2_CIU2_RST_SW3_SMU2_AHB_CLK__SHIFT    (16U)
/*! smu2_ahb_clk_ - SMU2 (AHB_Clk) Soft Reset */
#define CIU2_CIU2_RST_SW3_SMU2_AHB_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_SMU2_AHB_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_SMU2_AHB_CLK__MASK)

#define CIU2_CIU2_RST_SW3_SIF__MASK              (0x40000U)
#define CIU2_CIU2_RST_SW3_SIF__SHIFT             (18U)
/*! sif_ - sif clock Soft Reset */
#define CIU2_CIU2_RST_SW3_SIF_(x)                (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_SIF__SHIFT)) & CIU2_CIU2_RST_SW3_SIF__MASK)

#define CIU2_CIU2_RST_SW3_SIF_AHB2_CLK__MASK     (0x80000U)
#define CIU2_CIU2_RST_SW3_SIF_AHB2_CLK__SHIFT    (19U)
/*! sif_ahb2_clk_ - sif ahb2 Clock Soft Reset */
#define CIU2_CIU2_RST_SW3_SIF_AHB2_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_SIF_AHB2_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_SIF_AHB2_CLK__MASK)

#define CIU2_CIU2_RST_SW3_HPU2__MASK             (0x100000U)
#define CIU2_CIU2_RST_SW3_HPU2__SHIFT            (20U)
/*! hpu2_ - HPU2 Reset */
#define CIU2_CIU2_RST_SW3_HPU2_(x)               (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_HPU2__SHIFT)) & CIU2_CIU2_RST_SW3_HPU2__MASK)

#define CIU2_CIU2_RST_SW3_CIU2_AHB_CLK__MASK     (0x400000U)
#define CIU2_CIU2_RST_SW3_CIU2_AHB_CLK__SHIFT    (22U)
/*! ciu2_ahb_clk_ - CIU2 AHB Soft Reset */
#define CIU2_CIU2_RST_SW3_CIU2_AHB_CLK_(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_CIU2_AHB_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_CIU2_AHB_CLK__MASK)

#define CIU2_CIU2_RST_SW3_BRF_PR__MASK           (0x4000000U)
#define CIU2_CIU2_RST_SW3_BRF_PR__SHIFT          (26U)
/*! brf_pr_ - BRF_PR Reset */
#define CIU2_CIU2_RST_SW3_BRF_PR_(x)             (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BRF_PR__SHIFT)) & CIU2_CIU2_RST_SW3_BRF_PR__MASK)

#define CIU2_CIU2_RST_SW3_WD2_CHIP_RST_DISABLE_MASK (0x10000000U)
#define CIU2_CIU2_RST_SW3_WD2_CHIP_RST_DISABLE_SHIFT (28U)
#define CIU2_CIU2_RST_SW3_WD2_CHIP_RST_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_WD2_CHIP_RST_DISABLE_SHIFT)) & CIU2_CIU2_RST_SW3_WD2_CHIP_RST_DISABLE_MASK)

#define CIU2_CIU2_RST_SW3_WD2_CPU2_RST_DISABLE_MASK (0x20000000U)
#define CIU2_CIU2_RST_SW3_WD2_CPU2_RST_DISABLE_SHIFT (29U)
#define CIU2_CIU2_RST_SW3_WD2_CPU2_RST_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_WD2_CPU2_RST_DISABLE_SHIFT)) & CIU2_CIU2_RST_SW3_WD2_CPU2_RST_DISABLE_MASK)

#define CIU2_CIU2_RST_SW3_BT_16M_CLK__MASK       (0x40000000U)
#define CIU2_CIU2_RST_SW3_BT_16M_CLK__SHIFT      (30U)
/*! bt_16m_clk_ - Bt 16M clock reset */
#define CIU2_CIU2_RST_SW3_BT_16M_CLK_(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BT_16M_CLK__SHIFT)) & CIU2_CIU2_RST_SW3_BT_16M_CLK__MASK)

#define CIU2_CIU2_RST_SW3_BT_ADMA__MASK          (0x80000000U)
#define CIU2_CIU2_RST_SW3_BT_ADMA__SHIFT         (31U)
/*! bt_adma_ - BT ADMA Soft Reset */
#define CIU2_CIU2_RST_SW3_BT_ADMA_(x)            (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_RST_SW3_BT_ADMA__SHIFT)) & CIU2_CIU2_RST_SW3_BT_ADMA__MASK)
/*! @} */

/*! @name CIU2_MEM_WRTC3 - Memory WRTC Control 3 */
/*! @{ */

#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_MASK     (0x700U)
#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_SHIFT    (8U)
/*! ble_rom_rtc - BLE ROM RTC */
#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_REF_MASK (0x3000U)
#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_REF_SHIFT (12U)
/*! ble_rom_rtc_ref - BLE ROM RTC_REF */
#define CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_REF(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_REF_SHIFT)) & CIU2_CIU2_MEM_WRTC3_BLE_ROM_RTC_REF_MASK)
/*! @} */

/*! @name CIU2_MEM_WRTC4 - Memory WRTC Control 4 */
/*! @{ */

#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_RTC_MASK   (0x3U)
#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_RTC_SHIFT  (0U)
/*! cpu2_itcm_rtc - CPU2 ITCM RTC */
#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_RTC(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_WTC_MASK   (0xCU)
#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_WTC_SHIFT  (2U)
/*! cpu2_itcm_wtc - CPU2 ITCM WTC */
#define CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_WTC(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_WTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_ITCM_WTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_RTC_MASK   (0x30U)
#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_RTC_SHIFT  (4U)
/*! cpu2_dtcm_rtc - CPU2 DTCM RTC */
#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_RTC(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_WTC_MASK   (0xC0U)
#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_WTC_SHIFT  (6U)
/*! cpu2_dtcm_wtc - CPU2 DTCM WTC */
#define CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_WTC(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_WTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_DTCM_WTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_SMU2_RTC_MASK        (0x300U)
#define CIU2_CIU2_MEM_WRTC4_SMU2_RTC_SHIFT       (8U)
/*! smu2_rtc - SMU2 RTC */
#define CIU2_CIU2_MEM_WRTC4_SMU2_RTC(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_SMU2_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_SMU2_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_SMU2_WTC_MASK        (0xC00U)
#define CIU2_CIU2_MEM_WRTC4_SMU2_WTC_SHIFT       (10U)
/*! smu2_wtc - SMU2 WTC */
#define CIU2_CIU2_MEM_WRTC4_SMU2_WTC(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_SMU2_WTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_SMU2_WTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_MASK    (0x7000U)
#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_SHIFT   (12U)
/*! cpu2_bru_rtc - CPU2 BROM RTC */
#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_REF_MASK (0x30000U)
#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_REF_SHIFT (16U)
/*! cpu2_bru_rtc_ref - CPU2 BROM RTC_REF */
#define CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_REF(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_REF_SHIFT)) & CIU2_CIU2_MEM_WRTC4_CPU2_BRU_RTC_REF_MASK)

#define CIU2_CIU2_MEM_WRTC4_BTU_RTC_MASK         (0xC0000U)
#define CIU2_CIU2_MEM_WRTC4_BTU_RTC_SHIFT        (18U)
/*! btu_rtc - BTU EBRAM RTC */
#define CIU2_CIU2_MEM_WRTC4_BTU_RTC(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_BTU_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_BTU_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_BTU_WTC_MASK         (0x300000U)
#define CIU2_CIU2_MEM_WRTC4_BTU_WTC_SHIFT        (20U)
/*! btu_wtc - BTU EBRAM WTC */
#define CIU2_CIU2_MEM_WRTC4_BTU_WTC(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_BTU_WTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_BTU_WTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_BLE_RTC_MASK         (0xC000000U)
#define CIU2_CIU2_MEM_WRTC4_BLE_RTC_SHIFT        (26U)
/*! ble_rtc - ble RTC */
#define CIU2_CIU2_MEM_WRTC4_BLE_RTC(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_BLE_RTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_BLE_RTC_MASK)

#define CIU2_CIU2_MEM_WRTC4_BLE_WTC_MASK         (0x30000000U)
#define CIU2_CIU2_MEM_WRTC4_BLE_WTC_SHIFT        (28U)
/*! ble_wtc - ble WTC */
#define CIU2_CIU2_MEM_WRTC4_BLE_WTC(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_WRTC4_BLE_WTC_SHIFT)) & CIU2_CIU2_MEM_WRTC4_BLE_WTC_MASK)
/*! @} */

/*! @name CIU2_MEM_PWDN3 - Memory Powerdown Control */
/*! @{ */

#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_VAL_MASK (0x1U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_VAL_SHIFT (0U)
/*! cpu2_bru_bypass_val - Firmware Bypass value for CPU2 Boot ROM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_VAL_MASK (0x2U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_VAL_SHIFT (1U)
/*! cpu2_dtcm_bypass_val - Firmware Bypass value for CPU2 DTCM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_VAL_MASK (0x4U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_VAL_SHIFT (2U)
/*! cpu2_itcm_bypass_val - Firmware Bypass value for CPU2 ITCM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_VAL_MASK (0x10U)
#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_VAL_SHIFT (4U)
/*! smu2_bypass_val - Firmware Bypass value for SMU2 Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_VAL(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_VAL_MASK  (0x20U)
#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_VAL_SHIFT (5U)
/*! siu_bypass_val - Firmware Bypass value for UART Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_VAL(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_VAL_MASK  (0x40U)
#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_VAL_SHIFT (6U)
/*! btu_bypass_val - Firmware Bypass value for BTU Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_VAL(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_VAL_MASK (0x200U)
#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_VAL_SHIFT (9U)
/*! bt_adma_bypass_val - Firmware Bypass value for BT ADMA Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_VAL_SHIFT)) & CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_VAL_MASK)

#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_EN_MASK (0x10000U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_EN_SHIFT (16U)
/*! cpu2_bru_bypass_en - Firmware Bypass Enable for CPU2 Boot ROM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_BRU_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_EN_MASK (0x20000U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_EN_SHIFT (17U)
/*! cpu2_dtcm_bypass_en - Firmware Bypass Enable for CPU2 DTCM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_DTCM_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_EN_MASK (0x40000U)
#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_EN_SHIFT (18U)
/*! cpu2_itcm_bypass_en - Firmware Bypass Enable for CPU2 ITCM Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_CPU2_ITCM_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_EN_MASK  (0x100000U)
#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_EN_SHIFT (20U)
/*! smu2_bypass_en - Firmware Bypass Enable for SMU2 Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_EN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_SMU2_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_EN_MASK   (0x200000U)
#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_EN_SHIFT  (21U)
/*! siu_bypass_en - Firmware Bypass Enable for UART Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_EN(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_SIU_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_EN_MASK   (0x400000U)
#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_EN_SHIFT  (22U)
/*! btu_bypass_en - Firmware Bypass Enable for BTU Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_EN(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_BTU_BYPASS_EN_MASK)

#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_EN_MASK (0x2000000U)
#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_EN_SHIFT (25U)
/*! bt_adma_bypass_en - Firmware Bypass Enable for BT ADMA Memories Power Down */
#define CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_EN_SHIFT)) & CIU2_CIU2_MEM_PWDN3_BT_ADMA_BYPASS_EN_MASK)
/*! @} */

/*! @name CIU2_BLE_CTRL - BLE Control and Status */
/*! @{ */

#define CIU2_CIU2_BLE_CTRL_BT_AES_CLK_FREQ_SEL_MASK (0x100U)
#define CIU2_CIU2_BLE_CTRL_BT_AES_CLK_FREQ_SEL_SHIFT (8U)
/*! bt_aes_clk_freq_sel - btu_aes_clk Frequency Select */
#define CIU2_CIU2_BLE_CTRL_BT_AES_CLK_FREQ_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BLE_CTRL_BT_AES_CLK_FREQ_SEL_SHIFT)) & CIU2_CIU2_BLE_CTRL_BT_AES_CLK_FREQ_SEL_MASK)
/*! @} */

/*! @name CIU2_AHB2_TO_LAST_ADDR - AHB2 Timeout Last Address */
/*! @{ */

#define CIU2_CIU2_AHB2_TO_LAST_ADDR_ADDRESS_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_AHB2_TO_LAST_ADDR_ADDRESS_SHIFT (0U)
/*! address - Last AHB2 Address Right Before the Current Timeout */
#define CIU2_CIU2_AHB2_TO_LAST_ADDR_ADDRESS(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_LAST_ADDR_ADDRESS_SHIFT)) & CIU2_CIU2_AHB2_TO_LAST_ADDR_ADDRESS_MASK)
/*! @} */

/*! @name CIU2_AHB2_TO_CUR_ADDR - AHB2 Current Timeout Address */
/*! @{ */

#define CIU2_CIU2_AHB2_TO_CUR_ADDR_ADDRESS_MASK  (0xFFFFFFFFU)
#define CIU2_CIU2_AHB2_TO_CUR_ADDR_ADDRESS_SHIFT (0U)
/*! address - Current_TO_Addr */
#define CIU2_CIU2_AHB2_TO_CUR_ADDR_ADDRESS(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CUR_ADDR_ADDRESS_SHIFT)) & CIU2_CIU2_AHB2_TO_CUR_ADDR_ADDRESS_MASK)
/*! @} */

/*! @name CIU2_AHB2_TO_CTRL - AHB2 ARB Control */
/*! @{ */

#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_SLAVE_ID_MASK (0xFU)
#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_SLAVE_ID_SHIFT (0U)
/*! current_to_slave_id - Current_TO_Slave_ID */
#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_SLAVE_ID_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_SLAVE_ID_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_SLAVE_ID_MASK (0xF0U)
#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_SLAVE_ID_SHIFT (4U)
/*! last_to_slave_id - Last_TO_Slave_ID */
#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_SLAVE_ID_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_SLAVE_ID_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_MASTER_ID_MASK (0xF00U)
#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_MASTER_ID_SHIFT (8U)
/*! current_to_master_id - AHB2 Current_TO_Master_ID */
#define CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_MASTER_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_MASTER_ID_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_CURRENT_TO_MASTER_ID_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_MASTER_ID_MASK (0xF000U)
#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_MASTER_ID_SHIFT (12U)
/*! last_to_master_id - AHB2 Last_TO_Master_ID */
#define CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_MASTER_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_MASTER_ID_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_LAST_TO_MASTER_ID_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_SMU1_MEM_PROT_DIS_MASK (0x10000U)
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_SMU1_MEM_PROT_DIS_SHIFT (16U)
/*! ahb2_smu1_mem_prot_dis - Disable SMU1 Memory Protection from AHB2 side */
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_SMU1_MEM_PROT_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_AHB2_SMU1_MEM_PROT_DIS_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_AHB2_SMU1_MEM_PROT_DIS_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_IMEM_PROT_DIS_MASK (0x20000U)
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_IMEM_PROT_DIS_SHIFT (17U)
/*! ahb2_cpu2_imem_prot_dis - 1 = Disable CPU2 Imem Memory Protection from AHB2 side and allow AHB2 to read/write Imem */
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_IMEM_PROT_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_IMEM_PROT_DIS_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_IMEM_PROT_DIS_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_DMEM_PROT_DIS_MASK (0x40000U)
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_DMEM_PROT_DIS_SHIFT (18U)
/*! ahb2_cpu2_dmem_prot_dis - 1 = Disable CPU2 Dmem Memory Protection from AHB2 side and allow AHB2 to read/write Dmem */
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_DMEM_PROT_DIS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_DMEM_PROT_DIS_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_AHB2_CPU2_DMEM_PROT_DIS_MASK)

#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_TIMEOUT_MODE_MASK (0xC0000000U)
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_TIMEOUT_MODE_SHIFT (30U)
/*! ahb2_timeout_mode - AHB2_TimeoutMode[1:0] */
#define CIU2_CIU2_AHB2_TO_CTRL_AHB2_TIMEOUT_MODE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_TO_CTRL_AHB2_TIMEOUT_MODE_SHIFT)) & CIU2_CIU2_AHB2_TO_CTRL_AHB2_TIMEOUT_MODE_MASK)
/*! @} */

/*! @name CIU2_AHB2_SMU1_ACCESS_ADDR - AHB2 to SMU1 Accessible Address */
/*! @{ */

#define CIU2_CIU2_AHB2_SMU1_ACCESS_ADDR_AHB2_SMU1_ACCESS_ADDR_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_AHB2_SMU1_ACCESS_ADDR_AHB2_SMU1_ACCESS_ADDR_SHIFT (0U)
/*! ahb2_smu1_access_addr - SMU1 Accessible Memory Address from AHB2 side */
#define CIU2_CIU2_AHB2_SMU1_ACCESS_ADDR_AHB2_SMU1_ACCESS_ADDR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_SMU1_ACCESS_ADDR_AHB2_SMU1_ACCESS_ADDR_SHIFT)) & CIU2_CIU2_AHB2_SMU1_ACCESS_ADDR_AHB2_SMU1_ACCESS_ADDR_MASK)
/*! @} */

/*! @name CIU2_AHB2_SMU1_ACCESS_MASK - AHB2 to SMU1 Accessible Mask */
/*! @{ */

#define CIU2_CIU2_AHB2_SMU1_ACCESS_MASK_AHB2_SMU1_ACCESS_MASK_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_AHB2_SMU1_ACCESS_MASK_AHB2_SMU1_ACCESS_MASK_SHIFT (0U)
/*! ahb2_smu1_access_mask - SMU1 Accessible Memory Mask from AHB2 side */
#define CIU2_CIU2_AHB2_SMU1_ACCESS_MASK_AHB2_SMU1_ACCESS_MASK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2_SMU1_ACCESS_MASK_AHB2_SMU1_ACCESS_MASK_SHIFT)) & CIU2_CIU2_AHB2_SMU1_ACCESS_MASK_AHB2_SMU1_ACCESS_MASK_MASK)
/*! @} */

/*! @name CIU2_CPU2_FABRIC_ARB_CTRL - CPU2 fabric arbiter control */
/*! @{ */

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_BRST_TERM_CNT_MASK (0x3U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_BRST_TERM_CNT_SHIFT (0U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_BRST_TERM_CNT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_BRST_TERM_CNT_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_BRST_TERM_CNT_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_BRST_TERM_CNT_MASK (0xCU)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_BRST_TERM_CNT_SHIFT (2U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_BRST_TERM_CNT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_BRST_TERM_CNT_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_BRST_TERM_CNT_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_NOBURSTTERM_MASK (0x10U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_NOBURSTTERM_SHIFT (4U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_NOBURSTTERM(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_NOBURSTTERM_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_NOBURSTTERM_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_PRIORITY_MASK (0x60U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_PRIORITY_SHIFT (5U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_PRIORITY_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_PRIORITY_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_ROUND_ROBIN_EN_MASK (0x80U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_ROUND_ROBIN_EN_SHIFT (7U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_ROUND_ROBIN_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_ROUND_ROBIN_EN_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_DMEM_ROUND_ROBIN_EN_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_NOBURSTTERM_MASK (0x100U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_NOBURSTTERM_SHIFT (8U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_NOBURSTTERM(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_NOBURSTTERM_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_NOBURSTTERM_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_PRIORITY_MASK (0x600U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_PRIORITY_SHIFT (9U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_PRIORITY_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_PRIORITY_MASK)

#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_ROUND_ROBIN_EN_MASK (0x800U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_ROUND_ROBIN_EN_SHIFT (11U)
#define CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_ROUND_ROBIN_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_ROUND_ROBIN_EN_SHIFT)) & CIU2_CIU2_CPU2_FABRIC_ARB_CTRL_IMEM_ROUND_ROBIN_EN_MASK)
/*! @} */

/*! @name CIU2_CPU2_ICODE_INV_ADDR_CTRL - CPU2 Icode invalid address access control */
/*! @{ */

#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_MASK (0xFU)
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_SHIFT (0U)
/*! last2_inv_addr_slave_id - Last2_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_MASK (0xF0U)
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_SHIFT (4U)
/*! last_inv_addr_slave_id - Last_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_MASK (0xF00U)
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_SHIFT (8U)
/*! cur_inv_addr_slave_id - Cur_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_MASK (0xC0000000U)
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_SHIFT (30U)
/*! haddr_icod_sel - There are 3 haddr which can be observed by selecting this: */
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_HADDR_ICOD_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_SHIFT)) & CIU2_CIU2_CPU2_ICODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_MASK)
/*! @} */

/*! @name CIU2_CPU2_ICODE_INV_ADDR - CPU2 Icode invalid address */
/*! @{ */

#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_HADDR_INV_ADDR_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_HADDR_INV_ADDR_SHIFT (0U)
/*! haddr_inv_addr - based on CIU_CPU2_ICODE_INV_ADDR_CTRL[31:30], the address status is obsrved in this register */
#define CIU2_CIU2_CPU2_ICODE_INV_ADDR_HADDR_INV_ADDR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_ICODE_INV_ADDR_HADDR_INV_ADDR_SHIFT)) & CIU2_CIU2_CPU2_ICODE_INV_ADDR_HADDR_INV_ADDR_MASK)
/*! @} */

/*! @name CIU2_CPU2_DCODE_INV_ADDR_CTRL - CPU2 Dcode invalid address access control */
/*! @{ */

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_MASK (0xFU)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_SHIFT (0U)
/*! last2_inv_addr_slave_id - Last2_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_MASK (0xF0U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_SHIFT (4U)
/*! last_inv_addr_slave_id - Last_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_MASK (0xF00U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_SHIFT (8U)
/*! cur_inv_addr_slave_id - Cur_inv_addr_Slave_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_SLAVE_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_MASTER_ID_MASK (0xF000U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_MASTER_ID_SHIFT (12U)
/*! last2_inv_addr_master_id - Last2_inv_addr_master_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_MASTER_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_MASTER_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST2_INV_ADDR_MASTER_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_MASTER_ID_MASK (0xF0000U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_MASTER_ID_SHIFT (16U)
/*! last_inv_addr_master_id - Last_inv_addr_master_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_MASTER_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_MASTER_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_LAST_INV_ADDR_MASTER_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_MASTER_ID_MASK (0xF00000U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_MASTER_ID_SHIFT (20U)
/*! cur_inv_addr_master_id - Cur_inv_addr_master_ID */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_MASTER_ID(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_MASTER_ID_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_CUR_INV_ADDR_MASTER_ID_MASK)

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_MASK (0xC0000000U)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_SHIFT (30U)
/*! haddr_icod_sel - There are 3 haddr which can be observed by selecting this: */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_HADDR_ICOD_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_CTRL_HADDR_ICOD_SEL_MASK)
/*! @} */

/*! @name CIU2_CPU2_DCODE_INV_ADDR - CPU2 Dcode invalid address */
/*! @{ */

#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_HADDR_INV_ADDR_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_HADDR_INV_ADDR_SHIFT (0U)
/*! haddr_inv_addr - based on CIU_CPU2_DCODE_INV_ADDR_CTRL[31:30], the address status is obsrved in this register */
#define CIU2_CIU2_CPU2_DCODE_INV_ADDR_HADDR_INV_ADDR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_DCODE_INV_ADDR_HADDR_INV_ADDR_SHIFT)) & CIU2_CIU2_CPU2_DCODE_INV_ADDR_HADDR_INV_ADDR_MASK)
/*! @} */

/*! @name CIU2_CPU_CPU2_CTRL - CPU2 control register */
/*! @{ */

#define CIU2_CIU2_CPU_CPU2_CTRL_VINITHI_MASK     (0x1U)
#define CIU2_CIU2_CPU_CPU2_CTRL_VINITHI_SHIFT    (0U)
#define CIU2_CIU2_CPU_CPU2_CTRL_VINITHI(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_VINITHI_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_VINITHI_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_JTAG_CHAIN_BYPASS_MASK (0x4U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_JTAG_CHAIN_BYPASS_SHIFT (2U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_JTAG_CHAIN_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU2_JTAG_CHAIN_BYPASS_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU2_JTAG_CHAIN_BYPASS_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_IMEM_MUX_EN_MASK (0x10U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_IMEM_MUX_EN_SHIFT (4U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_IMEM_MUX_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_IMEM_MUX_EN_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_IMEM_MUX_EN_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_DMEM_MUX_EN_MASK (0x20U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_DMEM_MUX_EN_SHIFT (5U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_DMEM_MUX_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_DMEM_MUX_EN_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU2_BOOT_DMEM_MUX_EN_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_DBG_CTRL_MASK (0xFFF0000U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_DBG_CTRL_SHIFT (16U)
/*! cpu2_dbg_ctrl - cpu2 debug control */
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU2_DBG_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU2_DBG_CTRL_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU2_DBG_CTRL_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU3_RESET_INT_MASK (0x20000000U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU3_RESET_INT_SHIFT (29U)
/*! cpu3_reset_int - cpu2 fw resets cpu3(or cpu3 fw resets cpu2 if this register is used by cpu3) */
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU3_RESET_INT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU3_RESET_INT_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU3_RESET_INT_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_DSR_WKUP_IN_USE_MASK (0x40000000U)
#define CIU2_CIU2_CPU_CPU2_CTRL_DSR_WKUP_IN_USE_SHIFT (30U)
/*! dsr_wkup_in_use - dsr wkup when dsr_wkup_in_use = 1'b1 */
#define CIU2_CIU2_CPU_CPU2_CTRL_DSR_WKUP_IN_USE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_DSR_WKUP_IN_USE_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_DSR_WKUP_IN_USE_MASK)

#define CIU2_CIU2_CPU_CPU2_CTRL_CPU1_RESET_INT_MASK (0x80000000U)
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU1_RESET_INT_SHIFT (31U)
/*! cpu1_reset_int - cpu2 fw resets cpu1( or cpu3 fw resets cpu1 if this register is used by cpu3) */
#define CIU2_CIU2_CPU_CPU2_CTRL_CPU1_RESET_INT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_CTRL_CPU1_RESET_INT_SHIFT)) & CIU2_CIU2_CPU_CPU2_CTRL_CPU1_RESET_INT_MASK)
/*! @} */

/*! @name CIU2_BRF_CTRL - BRF Control and Status */
/*! @{ */

#define CIU2_CIU2_BRF_CTRL_AHB_SLV_BRF_SER_EN_MASK (0x1U)
#define CIU2_CIU2_BRF_CTRL_AHB_SLV_BRF_SER_EN_SHIFT (0U)
/*! ahb_slv_brf_ser_en - When set to 1, BRF serial interface will be accessed thru AHB slave memory mapped from 0xA800A000 to 0xA8011FFF */
#define CIU2_CIU2_BRF_CTRL_AHB_SLV_BRF_SER_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_CTRL_AHB_SLV_BRF_SER_EN_SHIFT)) & CIU2_CIU2_BRF_CTRL_AHB_SLV_BRF_SER_EN_MASK)

#define CIU2_CIU2_BRF_CTRL_SEL_BRF_TO_SSU_DUMP_PATH_MASK (0x2U)
#define CIU2_CIU2_BRF_CTRL_SEL_BRF_TO_SSU_DUMP_PATH_SHIFT (1U)
/*! sel_brf_to_ssu_dump_path - When set to 0, select BRF to SSU dump path */
#define CIU2_CIU2_BRF_CTRL_SEL_BRF_TO_SSU_DUMP_PATH(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_CTRL_SEL_BRF_TO_SSU_DUMP_PATH_SHIFT)) & CIU2_CIU2_BRF_CTRL_SEL_BRF_TO_SSU_DUMP_PATH_MASK)

#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_EN_MASK (0x100U)
#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_EN_SHIFT (8U)
#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_EN_SHIFT)) & CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_EN_MASK)

#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_VAL_MASK (0x200U)
#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_VAL_SHIFT (9U)
/*! ciu_brf_ref1x_clk_ctrl_bypass_val - 1. brf ref clk 1x is enabled */
#define CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_VAL_SHIFT)) & CIU2_CIU2_BRF_CTRL_CIU_BRF_REF1X_CLK_CTRL_BYPASS_VAL_MASK)

#define CIU2_CIU2_BRF_CTRL_BRF_CHIP_RDY_MASK     (0x80000000U)
#define CIU2_CIU2_BRF_CTRL_BRF_CHIP_RDY_SHIFT    (31U)
/*! brf_chip_rdy - BRF Chip_Rdy Status */
#define CIU2_CIU2_BRF_CTRL_BRF_CHIP_RDY(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_CTRL_BRF_CHIP_RDY_SHIFT)) & CIU2_CIU2_BRF_CTRL_BRF_CHIP_RDY_MASK)
/*! @} */

/*! @name CIU2_BRF_EXTRA_PORT - BRF Extra Port Connection */
/*! @{ */

#define CIU2_CIU2_BRF_EXTRA_PORT_SOC_BRF_EXTRA_MASK (0xFU)
#define CIU2_CIU2_BRF_EXTRA_PORT_SOC_BRF_EXTRA_SHIFT (0U)
/*! soc_brf_extra - SOC_BRF_EXTRA[3:0] */
#define CIU2_CIU2_BRF_EXTRA_PORT_SOC_BRF_EXTRA(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_EXTRA_PORT_SOC_BRF_EXTRA_SHIFT)) & CIU2_CIU2_BRF_EXTRA_PORT_SOC_BRF_EXTRA_MASK)
/*! @} */

/*! @name CIU2_BRF_ECO_CTRL - BRF ECO Control */
/*! @{ */

#define CIU2_CIU2_BRF_ECO_CTRL_ECO_BITS_MASK     (0xFFFFFFFFU)
#define CIU2_CIU2_BRF_ECO_CTRL_ECO_BITS_SHIFT    (0U)
/*! eco_bits - Reserved */
#define CIU2_CIU2_BRF_ECO_CTRL_ECO_BITS(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BRF_ECO_CTRL_ECO_BITS_SHIFT)) & CIU2_CIU2_BRF_ECO_CTRL_ECO_BITS_MASK)
/*! @} */

/*! @name CIU2_BTU_CTRL - BTU Control and Status */
/*! @{ */

#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_MASK    (0x1U)
#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_SHIFT   (0U)
/*! btu_cipher_en - Bluetooth Cipher Logic */
#define CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_SHIFT)) & CIU2_CIU2_BTU_CTRL_BTU_CIPHER_EN_MASK)

#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_MASK (0x2U)
#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_SHIFT (1U)
/*! dbus_high_speed_sel - Dbus High Speed Select Signal for Greater than 4 MHz */
#define CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_DBUS_HIGH_SPEED_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_MASK       (0xCU)
#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_SHIFT      (2U)
/*! bt_clk_sel - Bluetooth sys Clock Select */
#define CIU2_CIU2_BTU_CTRL_BT_CLK_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_BT_CLK_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_MASK    (0x700U)
#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_SHIFT   (8U)
/*! bt_ip_ser_sel - bt_ip_ser_sel */
#define CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_SHIFT)) & CIU2_CIU2_BTU_CTRL_BT_IP_SER_SEL_MASK)

#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_MASK    (0x80000000U)
#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_SHIFT   (31U)
/*! btu_mc_wakeup - BTU MC_Wakeup Status */
#define CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_SHIFT)) & CIU2_CIU2_BTU_CTRL_BTU_MC_WAKEUP_MASK)
/*! @} */

/*! @name CIU2_BT_PS - BT Clock Power Save */
/*! @{ */

#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_MVAL_MASK    (0x3FFFFFFU)
#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_MVAL_SHIFT   (0U)
/*! bt_mclk_nco_mval - BT_MCLK NCO Module Step Control (default 0x0) */
#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_MVAL(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS_BT_MCLK_NCO_MVAL_SHIFT)) & CIU2_CIU2_BT_PS_BT_MCLK_NCO_MVAL_MASK)

#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_EN_MASK      (0x4000000U)
#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_EN_SHIFT     (26U)
/*! bt_mclk_nco_en - BT_MCLK_NCO logic to count */
#define CIU2_CIU2_BT_PS_BT_MCLK_NCO_EN(x)        (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS_BT_MCLK_NCO_EN_SHIFT)) & CIU2_CIU2_BT_PS_BT_MCLK_NCO_EN_MASK)

#define CIU2_CIU2_BT_PS_BT_MCLK_TBG_NCO_SEL_MASK (0x8000000U)
#define CIU2_CIU2_BT_PS_BT_MCLK_TBG_NCO_SEL_SHIFT (27U)
/*! bt_mclk_tbg_nco_sel - BT_4M_PCM_CLK */
#define CIU2_CIU2_BT_PS_BT_MCLK_TBG_NCO_SEL(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS_BT_MCLK_TBG_NCO_SEL_SHIFT)) & CIU2_CIU2_BT_PS_BT_MCLK_TBG_NCO_SEL_MASK)

#define CIU2_CIU2_BT_PS_BT_MCLK_FROM_SOC_SEL_MASK (0x10000000U)
#define CIU2_CIU2_BT_PS_BT_MCLK_FROM_SOC_SEL_SHIFT (28U)
/*! bt_mclk_from_soc_sel - BT_MCLK */
#define CIU2_CIU2_BT_PS_BT_MCLK_FROM_SOC_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS_BT_MCLK_FROM_SOC_SEL_SHIFT)) & CIU2_CIU2_BT_PS_BT_MCLK_FROM_SOC_SEL_MASK)
/*! @} */

/*! @name CIU2_BT_PS2 - BT Clock Power Save 2 */
/*! @{ */

#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_MVAL_MASK (0x3FFFFFFU)
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_MVAL_SHIFT (0U)
/*! bt_pcm_clk_nco_mval - BT_PCM_CLK NCO Module Step Control (default 0x0) */
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_MVAL(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_MVAL_SHIFT)) & CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_MVAL_MASK)

#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_EN_MASK  (0x4000000U)
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_EN_SHIFT (26U)
/*! bt_pcm_clk_nco_en - BT_PCM_CLK_NCO logic to count */
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_EN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_EN_SHIFT)) & CIU2_CIU2_BT_PS2_BT_PCM_CLK_NCO_EN_MASK)

#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_TBG_NCO_SEL_MASK (0x8000000U)
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_TBG_NCO_SEL_SHIFT (27U)
/*! bt_pcm_clk_tbg_nco_sel - BT_4M_PCM_CLK */
#define CIU2_CIU2_BT_PS2_BT_PCM_CLK_TBG_NCO_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS2_BT_PCM_CLK_TBG_NCO_SEL_SHIFT)) & CIU2_CIU2_BT_PS2_BT_PCM_CLK_TBG_NCO_SEL_MASK)
/*! @} */

/*! @name CIU2_BT_REF_CTRL - BT Ref Control */
/*! @{ */

#define CIU2_CIU2_BT_REF_CTRL_NCO_EN_MASK        (0x1U)
#define CIU2_CIU2_BT_REF_CTRL_NCO_EN_SHIFT       (0U)
/*! nco_en - Bluetooth Reference Clock NCO Enable information to APU. */
#define CIU2_CIU2_BT_REF_CTRL_NCO_EN(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_REF_CTRL_NCO_EN_SHIFT)) & CIU2_CIU2_BT_REF_CTRL_NCO_EN_MASK)

#define CIU2_CIU2_BT_REF_CTRL_NCO_SEL_MASK       (0x2U)
#define CIU2_CIU2_BT_REF_CTRL_NCO_SEL_SHIFT      (1U)
/*! nco_sel - Bluetooth Reference Clock NCO Select Value */
#define CIU2_CIU2_BT_REF_CTRL_NCO_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_REF_CTRL_NCO_SEL_SHIFT)) & CIU2_CIU2_BT_REF_CTRL_NCO_SEL_MASK)

#define CIU2_CIU2_BT_REF_CTRL_NCO_GEN_MASK       (0x3FFFCU)
#define CIU2_CIU2_BT_REF_CTRL_NCO_GEN_SHIFT      (2U)
/*! nco_gen - Bluetooth Reference Clock NCO Gen Value */
#define CIU2_CIU2_BT_REF_CTRL_NCO_GEN(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_REF_CTRL_NCO_GEN_SHIFT)) & CIU2_CIU2_BT_REF_CTRL_NCO_GEN_MASK)

#define CIU2_CIU2_BT_REF_CTRL_BT_CLK_NCO_REFCLK_SEL_MASK (0x100000U)
#define CIU2_CIU2_BT_REF_CTRL_BT_CLK_NCO_REFCLK_SEL_SHIFT (20U)
/*! bt_clk_nco_refclk_sel - BT clk (bt sys clk) selection */
#define CIU2_CIU2_BT_REF_CTRL_BT_CLK_NCO_REFCLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_REF_CTRL_BT_CLK_NCO_REFCLK_SEL_SHIFT)) & CIU2_CIU2_BT_REF_CTRL_BT_CLK_NCO_REFCLK_SEL_MASK)
/*! @} */

/*! @name CIU2_BT_PS3 - BT Clock Power Save 3 */
/*! @{ */

#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_STEP_CTRL_MASK (0x3FFFFFFU)
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_STEP_CTRL_SHIFT (0U)
/*! btu_16m_clk_nco_step_ctrl - BT_16M_CLK NCO Module Step Control */
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_STEP_CTRL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_STEP_CTRL_SHIFT)) & CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_STEP_CTRL_MASK)

#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_EN_MASK (0x4000000U)
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_EN_SHIFT (26U)
/*! btu_16m_clk_nco_en - BTU 16M Clock NCO Enable */
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_EN(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_EN_SHIFT)) & CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_EN_MASK)

#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_SEL_MASK (0x8000000U)
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_SEL_SHIFT (27U)
/*! btu_16m_clk_nco_sel - BTU 16M clock NCO Select Value */
#define CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_SEL(x)  (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_SEL_SHIFT)) & CIU2_CIU2_BT_PS3_BTU_16M_CLK_NCO_SEL_MASK)

#define CIU2_CIU2_BT_PS3_BTU_CLK_NCO_MODE_MASK   (0x20000000U)
#define CIU2_CIU2_BT_PS3_BTU_CLK_NCO_MODE_SHIFT  (29U)
/*! btu_clk_nco_mode - BTU Clock source from ref clock (nco mode) */
#define CIU2_CIU2_BT_PS3_BTU_CLK_NCO_MODE(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BT_PS3_BTU_CLK_NCO_MODE_SHIFT)) & CIU2_CIU2_BT_PS3_BTU_CLK_NCO_MODE_MASK)
/*! @} */

/*! @name CIU2_BTU_ECO_CTRL - BTU ECO Control */
/*! @{ */

#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_MASK     (0xFFFFFFFFU)
#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_SHIFT    (0U)
/*! eco_bits - Reserved */
#define CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS(x)       (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_SHIFT)) & CIU2_CIU2_BTU_ECO_CTRL_ECO_BITS_MASK)
/*! @} */

/*! @name CIU2_INT_MASK - CIU2 Interrupt Mask */
/*! @{ */

#define CIU2_CIU2_INT_MASK_MASK_MASK             (0xFFFFFFFFU)
#define CIU2_CIU2_INT_MASK_MASK_SHIFT            (0U)
/*! mask - Interrupt Mask for CIU2 Interrupts */
#define CIU2_CIU2_INT_MASK_MASK(x)               (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_MASK_MASK_SHIFT)) & CIU2_CIU2_INT_MASK_MASK_MASK)
/*! @} */

/*! @name CIU2_INT_SELECT - CIU2 Interrupt Select */
/*! @{ */

#define CIU2_CIU2_INT_SELECT_SEL_MASK            (0xFFFFFFFFU)
#define CIU2_CIU2_INT_SELECT_SEL_SHIFT           (0U)
/*! sel - Interrupt Read/Write Clear for CIU2 Interrupts */
#define CIU2_CIU2_INT_SELECT_SEL(x)              (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_SELECT_SEL_SHIFT)) & CIU2_CIU2_INT_SELECT_SEL_MASK)
/*! @} */

/*! @name CIU2_INT_EVENT_MASK - CIU2 Interrupt Event Mask */
/*! @{ */

#define CIU2_CIU2_INT_EVENT_MASK_MASK_MASK       (0xFFFFFFFFU)
#define CIU2_CIU2_INT_EVENT_MASK_MASK_SHIFT      (0U)
/*! mask - Interrupt Event Mask for CIU2 Interrupts */
#define CIU2_CIU2_INT_EVENT_MASK_MASK(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_EVENT_MASK_MASK_SHIFT)) & CIU2_CIU2_INT_EVENT_MASK_MASK_MASK)
/*! @} */

/*! @name CIU2_INT_STATUS - CIU2 Interrupt Status */
/*! @{ */

#define CIU2_CIU2_INT_STATUS_CIU_ISR_MASK        (0xFFFFFFFFU)
#define CIU2_CIU2_INT_STATUS_CIU_ISR_SHIFT       (0U)
/*! ciu_isr - CIU2 Interrupt Status (ISR) */
#define CIU2_CIU2_INT_STATUS_CIU_ISR(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_INT_STATUS_CIU_ISR_SHIFT)) & CIU2_CIU2_INT_STATUS_CIU_ISR_MASK)
/*! @} */

/*! @name CPU2_ERR_INT_MASK - CPU2 ERR Interrupt Mask */
/*! @{ */

#define CIU2_CPU2_ERR_INT_MASK_MASK_MASK         (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT_MASK_MASK_SHIFT        (0U)
/*! mask - Interrupt Mask for CPU2 ERR Interrupts */
#define CIU2_CPU2_ERR_INT_MASK_MASK(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT_MASK_MASK_SHIFT)) & CIU2_CPU2_ERR_INT_MASK_MASK_MASK)
/*! @} */

/*! @name CPU2_ERR_INT_SELECT - CPU2 ERR Interrupt Clear Select */
/*! @{ */

#define CIU2_CPU2_ERR_INT_SELECT_SEL_MASK        (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT_SELECT_SEL_SHIFT       (0U)
/*! sel - Interrupt Read/Write Clear for CPU2 ERR Interrupts */
#define CIU2_CPU2_ERR_INT_SELECT_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT_SELECT_SEL_SHIFT)) & CIU2_CPU2_ERR_INT_SELECT_SEL_MASK)
/*! @} */

/*! @name CPU2_ERR_INT_EVENT_MASK - CPU2 ERR Interrupt Event Mask */
/*! @{ */

#define CIU2_CPU2_ERR_INT_EVENT_MASK_MASK_MASK   (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT_EVENT_MASK_MASK_SHIFT  (0U)
/*! mask - Interrupt Event Mask for CPU2 ERR Interrupts */
#define CIU2_CPU2_ERR_INT_EVENT_MASK_MASK(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT_EVENT_MASK_MASK_SHIFT)) & CIU2_CPU2_ERR_INT_EVENT_MASK_MASK_MASK)
/*! @} */

/*! @name CPU2_ERR_INT_STATUS - CPU2 ERR Interrupt Status */
/*! @{ */

#define CIU2_CPU2_ERR_INT_STATUS_ERR_ISR_MASK    (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT_STATUS_ERR_ISR_SHIFT   (0U)
/*! err_isr - CPU2 ERR Interrupt Status (ISR) */
#define CIU2_CPU2_ERR_INT_STATUS_ERR_ISR(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT_STATUS_ERR_ISR_SHIFT)) & CIU2_CPU2_ERR_INT_STATUS_ERR_ISR_MASK)
/*! @} */

/*! @name CPU2_ERR_INT2_MASK - CPU2 ERR Interrupt 2 Mask */
/*! @{ */

#define CIU2_CPU2_ERR_INT2_MASK_MASK_MASK        (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT2_MASK_MASK_SHIFT       (0U)
/*! mask - Interrupt Mask for CPU2 ERR Interrupts 2 */
#define CIU2_CPU2_ERR_INT2_MASK_MASK(x)          (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT2_MASK_MASK_SHIFT)) & CIU2_CPU2_ERR_INT2_MASK_MASK_MASK)
/*! @} */

/*! @name CPU2_ERR_INT2_SELECT - CPU2 ERR Interrupt 2 Clear Select */
/*! @{ */

#define CIU2_CPU2_ERR_INT2_SELECT_SEL_MASK       (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT2_SELECT_SEL_SHIFT      (0U)
/*! sel - Interrupt Read/Write Clear for CPU2 ERR Interrupts 2 */
#define CIU2_CPU2_ERR_INT2_SELECT_SEL(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT2_SELECT_SEL_SHIFT)) & CIU2_CPU2_ERR_INT2_SELECT_SEL_MASK)
/*! @} */

/*! @name CPU2_ERR_INT2_EVENT_MASK - CPU2 ERR Interrupt 2 Event Mask */
/*! @{ */

#define CIU2_CPU2_ERR_INT2_EVENT_MASK_MASK_MASK  (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT2_EVENT_MASK_MASK_SHIFT (0U)
/*! mask - Interrupt Event Mask for CPU2 ERR Interrupts 2 */
#define CIU2_CPU2_ERR_INT2_EVENT_MASK_MASK(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT2_EVENT_MASK_MASK_SHIFT)) & CIU2_CPU2_ERR_INT2_EVENT_MASK_MASK_MASK)
/*! @} */

/*! @name CPU2_ERR_INT2_STATUS - CPU2 ERR Interrupt 2 Status */
/*! @{ */

#define CIU2_CPU2_ERR_INT2_STATUS_ERR_ISR_MASK   (0xFFFFFFFFU)
#define CIU2_CPU2_ERR_INT2_STATUS_ERR_ISR_SHIFT  (0U)
/*! err_isr - CPU1 ERR Interrupt 2 Status (ISR) */
#define CIU2_CPU2_ERR_INT2_STATUS_ERR_ISR(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CPU2_ERR_INT2_STATUS_ERR_ISR_SHIFT)) & CIU2_CPU2_ERR_INT2_STATUS_ERR_ISR_MASK)
/*! @} */

/*! @name CIU2_CPU_CPU2_MSG_CTRL - CPU2 message register */
/*! @{ */

#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_RDY_MASK (0x1U)
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_RDY_SHIFT (0U)
/*! cpu1_to_cpu2_msg_rdy - CPU1 Message for CPU2 is ready. This is self clearing bit. The CPU1
 *    writes 1 to indicate that message for CPU2 is ready. This generates an Interrupt to CPU2 via APU.
 *    This is old schem and we should use IMU based scheme.
 */
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_RDY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_RDY_SHIFT)) & CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_RDY_MASK)

#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_RDY_MASK (0x2U)
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_RDY_SHIFT (1U)
/*! cpu3_to_cpu2_msg_rdy - CPU3 Message for CPU2 is ready. This is self clearing bit. The CPU3
 *    writes 1 to indicate that message for CPU2 is ready. This generates an Interrupt to CPU2 via APU.
 *    This is old schem and we should use IMU based scheme.
 */
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_RDY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_RDY_SHIFT)) & CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_RDY_MASK)

#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_PROCESS_DONE_MASK (0x100U)
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_PROCESS_DONE_SHIFT (8U)
/*! cpu1_to_cpu2_msg_process_done - CPU1 Message for CPU2 has been read by CPU2 and executed. This
 *    is self clearing bit. The CPU2 writes 1 to indicate that message send by CPU1 is executed. This
 *    generates an Interrupt to CPU1 via CIU1.
 */
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_PROCESS_DONE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_PROCESS_DONE_SHIFT)) & CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU1_TO_CPU2_MSG_PROCESS_DONE_MASK)

#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_PROCESS_DONE_MASK (0x200U)
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_PROCESS_DONE_SHIFT (9U)
/*! cpu3_to_cpu2_msg_process_done - CPU3 Message for CPU2 has been read by CPU2 and executed. This
 *    is self clearing bit. The CPU2 writes 1 to indicate that message send by CPU3 is executed. This
 *    generates an Interrupt to CPU3 via CIU3.
 */
#define CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_PROCESS_DONE(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_PROCESS_DONE_SHIFT)) & CIU2_CIU2_CPU_CPU2_MSG_CTRL_CPU3_TO_CPU2_MSG_PROCESS_DONE_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU1_WR_MSG_TO_CPU2 - CPU1 write message to CPU2 */
/*! @{ */

#define CIU2_CIU2_IMU_CPU1_WR_MSG_TO_CPU2_CPU1_WR_MSG_CPU2_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU1_WR_MSG_TO_CPU2_CPU1_WR_MSG_CPU2_SHIFT (0U)
/*! cpu1_wr_msg_cpu2 - Write CPU1 message data to CPU2 (push to FIFO) */
#define CIU2_CIU2_IMU_CPU1_WR_MSG_TO_CPU2_CPU1_WR_MSG_CPU2(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_WR_MSG_TO_CPU2_CPU1_WR_MSG_CPU2_SHIFT)) & CIU2_CIU2_IMU_CPU1_WR_MSG_TO_CPU2_CPU1_WR_MSG_CPU2_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU1_RD_MSG_FROM_CPU2 - CPU1 read message from CPU2 */
/*! @{ */

#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_CPU1_RD_MSG_CPU2_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_CPU1_RD_MSG_CPU2_SHIFT (0U)
/*! cpu1_rd_msg_cpu2 - CPU1 read message data from CPU2 (pop from FIFO) */
#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_CPU1_RD_MSG_CPU2(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_CPU1_RD_MSG_CPU2_SHIFT)) & CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_CPU1_RD_MSG_CPU2_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS - CPU1 to CPU2 message FIFO status */
/*! @{ */

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_LOCKED_MASK (0x1U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_LOCKED_SHIFT (0U)
/*! cpu1_to_cpu2_msg_fifo_locked - cpu1_to_cpu2_msg_fifo_locked */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_LOCKED_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_LOCKED_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_ALMOST_FULL_MASK (0x2U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_ALMOST_FULL_SHIFT (1U)
/*! cpu1_to_cpu2_msg_fifo_almost_full - cpu1_to_cpu2_msg_fifo_almost_full (based upon FIFO watermark) */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_ALMOST_FULL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_ALMOST_FULL_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_ALMOST_FULL_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_FULL_MASK (0x4U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_FULL_SHIFT (2U)
/*! cpu1_to_cpu2_msg_fifo_full - cpu1_to_cpu2_msg_fifo_full (based upon FIFO depth) */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_FULL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_FULL_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_FULL_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_EMPTY_MASK (0x8U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_EMPTY_SHIFT (3U)
/*! cpu1_to_cpu2_msg_fifo_empty - cpu1_to_cpu2_msg_fifo_empty */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_EMPTY_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_EMPTY_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_COUNT_MASK (0x1F0U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_COUNT_SHIFT (4U)
/*! cpu1_to_cpu2_msg_count - cpu1_to_cpu2_msg_count */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_COUNT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_COUNT_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_COUNT_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_WR_PTR_MASK (0xF0000U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_WR_PTR_SHIFT (16U)
/*! cpu1_to_cpu2_msg_fifo_wr_ptr - cpu1 to cpu2 msg fifo write pointer for debug */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_WR_PTR_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_WR_PTR_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_RD_PTR_MASK (0xF00000U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_RD_PTR_SHIFT (20U)
/*! cpu1_to_cpu2_msg_fifo_rd_ptr - cpu1 to cpu2 msg fifo read pointer for debug */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_RD_PTR_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_STATUS_CPU1_TO_CPU2_MSG_FIFO_RD_PTR_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL - CPU1 to CPU2 message FIFO control */
/*! @{ */

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_RDY_INT_CLR_MASK (0x1U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_RDY_INT_CLR_SHIFT (0U)
/*! cpu1_msg_rdy_int_clr - Writing 1 to this bit will clear message ready interrupt to CPU1 (self clear bit) */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_RDY_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_RDY_INT_CLR_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_RDY_INT_CLR_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_SP_AV_INT_CLR_MASK (0x100U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_SP_AV_INT_CLR_SHIFT (8U)
/*! cpu1_msg_sp_av_int_clr - Writing 1 to this bit will clear message space available interrupt to CPU1 (self clear bit) */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_SP_AV_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_SP_AV_INT_CLR_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_MSG_SP_AV_INT_CLR_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_TO_CPU2_MSG_FIFO_FLUSH_MASK (0x10000U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_TO_CPU2_MSG_FIFO_FLUSH_SHIFT (16U)
/*! cpu1_to_cpu2_msg_fifo_flush - Writing 1 to this bit will flush cpu1_to_cpu2 message fifo */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_TO_CPU2_MSG_FIFO_FLUSH(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_TO_CPU2_MSG_FIFO_FLUSH_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_TO_CPU2_MSG_FIFO_FLUSH_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_WAIT_FOR_ACK_MASK (0x20000U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_WAIT_FOR_ACK_SHIFT (17U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_WAIT_FOR_ACK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_WAIT_FOR_ACK_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_WAIT_FOR_ACK_MASK)

#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_CPU2_MSG_FIFO_FULL_WATERMARK_MASK (0xF00000U)
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_CPU2_MSG_FIFO_FULL_WATERMARK_SHIFT (20U)
/*! cpu1_cpu2_msg_fifo_full_watermark - cpu1_to_cpu2 message fifo full watermark (space avail intr based upon it) */
#define CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_CPU2_MSG_FIFO_FULL_WATERMARK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_CPU2_MSG_FIFO_FULL_WATERMARK_SHIFT)) & CIU2_CIU2_IMU_CPU1_CPU2_MSG_FIFO_CNTL_CPU1_CPU2_MSG_FIFO_FULL_WATERMARK_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG - CPU2 last message read (from cpu1) */
/*! @{ */

#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG_CPU2_RD_MSG_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG_CPU2_RD_MSG_SHIFT (0U)
/*! cpu2_rd_msg - CPU2 last message read (from cpu1) */
#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG_CPU2_RD_MSG(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG_CPU2_RD_MSG_SHIFT)) & CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_VAL_DBG_CPU2_RD_MSG_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU2_WR_MSG_TO_CPU1 - CPU2 write message to CPU1 */
/*! @{ */

#define CIU2_CIU2_IMU_CPU2_WR_MSG_TO_CPU1_CPU2_WR_MSG_CPU1_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU2_WR_MSG_TO_CPU1_CPU2_WR_MSG_CPU1_SHIFT (0U)
/*! cpu2_wr_msg_cpu1 - Write CPU2 message data to CPU1 (push to FIFO) */
#define CIU2_CIU2_IMU_CPU2_WR_MSG_TO_CPU1_CPU2_WR_MSG_CPU1(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_WR_MSG_TO_CPU1_CPU2_WR_MSG_CPU1_SHIFT)) & CIU2_CIU2_IMU_CPU2_WR_MSG_TO_CPU1_CPU2_WR_MSG_CPU1_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU2_RD_MSG_FROM_CPU1 - CPU2 read message from CPU1 */
/*! @{ */

#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_CPU2_RD_MSG_CPU1_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_CPU2_RD_MSG_CPU1_SHIFT (0U)
/*! cpu2_rd_msg_cpu1 - CPU2 read message data from CPU1 (pop from FIFO) */
#define CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_CPU2_RD_MSG_CPU1(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_CPU2_RD_MSG_CPU1_SHIFT)) & CIU2_CIU2_IMU_CPU2_RD_MSG_FROM_CPU1_CPU2_RD_MSG_CPU1_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS - CPU2 to CPU1 message FIFO status */
/*! @{ */

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_LOCKED_MASK (0x1U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_LOCKED_SHIFT (0U)
/*! cpu2_to_cpu1_msg_fifo_locked - cpu2_to_cpu1_msg_fifo_locked */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_LOCKED(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_LOCKED_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_LOCKED_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_ALMOST_FULL_MASK (0x2U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_ALMOST_FULL_SHIFT (1U)
/*! cpu2_to_cpu1_msg_fifo_almost_full - cpu2_to_cpu1_msg_fifo_almost_full (based upon FIFO watermark) */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_ALMOST_FULL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_ALMOST_FULL_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_ALMOST_FULL_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_FULL_MASK (0x4U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_FULL_SHIFT (2U)
/*! cpu2_to_cpu1_msg_fifo_full - cpu2_to_cpu1_msg_fifo_full (based upon FIFO depth) */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_FULL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_FULL_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_FULL_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_EMPTY_MASK (0x8U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_EMPTY_SHIFT (3U)
/*! cpu2_to_cpu1_msg_fifo_empty - cpu2_to_cpu1_msg_fifo_empty */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_EMPTY(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_EMPTY_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_EMPTY_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_COUNT_MASK (0x1F0U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_COUNT_SHIFT (4U)
/*! cpu2_to_cpu1_msg_count - cpu2_to_cpu1_msg_count */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_COUNT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_COUNT_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_COUNT_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_WR_PTR_MASK (0xF0000U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_WR_PTR_SHIFT (16U)
/*! cpu2_to_cpu1_msg_fifo_wr_ptr - cpu1 to cpu2 msg fifo write pointer for debug */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_WR_PTR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_WR_PTR_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_WR_PTR_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_RD_PTR_MASK (0xF00000U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_RD_PTR_SHIFT (20U)
/*! cpu2_to_cpu1_msg_fifo_rd_ptr - cpu1 to cpu2 msg fifo read pointer for debug */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_RD_PTR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_RD_PTR_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_STATUS_CPU2_TO_CPU1_MSG_FIFO_RD_PTR_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL - CPU2 to CPU1 message FIFO control */
/*! @{ */

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_RDY_INT_CLR_MASK (0x1U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_RDY_INT_CLR_SHIFT (0U)
/*! cpu2_msg_rdy_int_clr - Writing 1 to this bit will clear message ready interrupt to CPU2 (self clear bit) */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_RDY_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_RDY_INT_CLR_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_RDY_INT_CLR_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_SP_AV_INT_CLR_MASK (0x100U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_SP_AV_INT_CLR_SHIFT (8U)
/*! cpu2_msg_sp_av_int_clr - Writing 1 to this bit will clear message space available interrupt to CPU2 (self clear bit) */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_SP_AV_INT_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_SP_AV_INT_CLR_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_MSG_SP_AV_INT_CLR_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_TO_CPU1_MSG_FIFO_FLUSH_MASK (0x10000U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_TO_CPU1_MSG_FIFO_FLUSH_SHIFT (16U)
/*! cpu2_to_cpu1_msg_fifo_flush - Writing 1 to this bit will flush cpu2_to_cpu1 message fifo */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_TO_CPU1_MSG_FIFO_FLUSH(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_TO_CPU1_MSG_FIFO_FLUSH_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_TO_CPU1_MSG_FIFO_FLUSH_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_WAIT_FOR_ACK_MASK (0x20000U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_WAIT_FOR_ACK_SHIFT (17U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_WAIT_FOR_ACK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_WAIT_FOR_ACK_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_WAIT_FOR_ACK_MASK)

#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_CPU1_MSG_FIFO_FULL_WATERMARK_MASK (0xF00000U)
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_CPU1_MSG_FIFO_FULL_WATERMARK_SHIFT (20U)
/*! cpu2_cpu1_msg_fifo_full_watermark - cpu2_to_cpu1 message fifo full watermark (space avail intr based upon it) */
#define CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_CPU1_MSG_FIFO_FULL_WATERMARK(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_CPU1_MSG_FIFO_FULL_WATERMARK_SHIFT)) & CIU2_CIU2_IMU_CPU2_CPU1_MSG_FIFO_CNTL_CPU2_CPU1_MSG_FIFO_FULL_WATERMARK_MASK)
/*! @} */

/*! @name CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG - CPU1 last message read (from cpu2) */
/*! @{ */

#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG_CPU1_RD_MSG_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG_CPU1_RD_MSG_SHIFT (0U)
/*! cpu1_rd_msg - CPU1 last message read (from cpu2) */
#define CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG_CPU1_RD_MSG(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG_CPU1_RD_MSG_SHIFT)) & CIU2_CIU2_IMU_CPU1_RD_MSG_FROM_CPU2_VAL_DBG_CPU1_RD_MSG_MASK)
/*! @} */

/*! @name CIU2_BCA1_CPU2_INT_MASK - BCA1 to CPU2 Interrupt Mask */
/*! @{ */

#define CIU2_CIU2_BCA1_CPU2_INT_MASK_IMR_MASK    (0xFFFFFFFFU)
#define CIU2_CIU2_BCA1_CPU2_INT_MASK_IMR_SHIFT   (0U)
/*! imr - Interrupt Mask for BCA1 to CPU2 Interrupts */
#define CIU2_CIU2_BCA1_CPU2_INT_MASK_IMR(x)      (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BCA1_CPU2_INT_MASK_IMR_SHIFT)) & CIU2_CIU2_BCA1_CPU2_INT_MASK_IMR_MASK)
/*! @} */

/*! @name CIU2_BCA1_CPU2_INT_SELECT - BCA1 to CPU2 Interrupt Select */
/*! @{ */

#define CIU2_CIU2_BCA1_CPU2_INT_SELECT_RSR_MASK  (0xFFFFFFFFU)
#define CIU2_CIU2_BCA1_CPU2_INT_SELECT_RSR_SHIFT (0U)
/*! rsr - Interrupt Read/Write Clear for BCA1 to CPU2 Interrupts */
#define CIU2_CIU2_BCA1_CPU2_INT_SELECT_RSR(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BCA1_CPU2_INT_SELECT_RSR_SHIFT)) & CIU2_CIU2_BCA1_CPU2_INT_SELECT_RSR_MASK)
/*! @} */

/*! @name CIU2_BCA1_CPU2_INT_EVENT_MASK - BCA1 to CPU2 Interrupt Event Mask */
/*! @{ */

#define CIU2_CIU2_BCA1_CPU2_INT_EVENT_MASK_SMR_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_BCA1_CPU2_INT_EVENT_MASK_SMR_SHIFT (0U)
/*! smr - Interrupt Event Mask for BCA1 to CPU2 Interrupts */
#define CIU2_CIU2_BCA1_CPU2_INT_EVENT_MASK_SMR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BCA1_CPU2_INT_EVENT_MASK_SMR_SHIFT)) & CIU2_CIU2_BCA1_CPU2_INT_EVENT_MASK_SMR_MASK)
/*! @} */

/*! @name CIU2_BCA1_CPU2_INT_STATUS - BCA1 to CPU2 Interrupt Status */
/*! @{ */

#define CIU2_CIU2_BCA1_CPU2_INT_STATUS_ISR_MASK  (0xFFFFFFFFU)
#define CIU2_CIU2_BCA1_CPU2_INT_STATUS_ISR_SHIFT (0U)
/*! isr - BCA1 to CPU2 Interrupt Status */
#define CIU2_CIU2_BCA1_CPU2_INT_STATUS_ISR(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_BCA1_CPU2_INT_STATUS_ISR_SHIFT)) & CIU2_CIU2_BCA1_CPU2_INT_STATUS_ISR_MASK)
/*! @} */

/*! @name CIU2_APU_BYPASS1 - CIU2 APU Bypass Register 1 */
/*! @{ */

#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_EN_MASK (0x1U)
#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_EN_SHIFT (0U)
/*! brf_clk_en_bypass_en - Firmware Bypass BRF_Clk_En */
#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_VAL_MASK (0x2U)
#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_VAL_SHIFT (1U)
/*! brf_clk_en_bypass_val - Firmware Bypass Value for BRF_Clk_En (active high signal) */
#define CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BRF_CLK_EN_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_EN_MASK (0x4U)
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_EN_SHIFT (2U)
/*! bt_aes_clk_en_bypass_en - Firmware Bypass for Btu_Aes_Clk */
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_VAL_MASK (0x8U)
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_VAL_SHIFT (3U)
/*! bt_aes_clk_en_bypass_val - Firmware Bypass Value for Btu_Aes_Clk */
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_EN_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_EN_MASK (0x10U)
#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_EN_SHIFT (4U)
/*! soc_clk_en2_T1_bypass_en - Firmware Bypass for SoC_Clk_En2 */
#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_VAL_MASK (0x20U)
#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_VAL_SHIFT (5U)
/*! soc_clk_en2_T1_bypass_val - Firmware Bypass Value for SoC_Clk_En2(active high signal) */
#define CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_SOC_CLK_EN2_T1_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_SEL_MASK (0xC0U)
#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_SEL_SHIFT (6U)
/*! tbg_btu_clk_en_bypass_sel - TBG512_320_176_BTU_Clk_En_Sel to TBG512_320_176 of CAU */
#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_SEL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_SEL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_SEL_MASK)

#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_EN_MASK (0x100U)
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_EN_SHIFT (8U)
/*! bt_aes_clk_sel_bypass_en - Firmware Bypass for Btu_Aes_Clk_Sel */
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_VAL_MASK (0x200U)
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_VAL_SHIFT (9U)
/*! bt_aes_clk_sel_bypass_val - Firmware Bypass Value for Btu_Aes_Clk_Sel */
#define CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_BT_AES_CLK_SEL_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_VAL_MASK (0x400U)
#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_VAL_SHIFT (10U)
/*! tbg_btu_clk_en_bypass_val - TBG512_320_176_BTU_Clk_En Bypass Value */
#define CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_BYPASS1_TBG_BTU_CLK_EN_BYPASS_VAL_MASK)
/*! @} */

/*! @name CIU2_CPU2_LMU_STA_BYPASS0 - LMU static bank control byapss0 Register for CPU2 mem */
/*! @{ */

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_EN_MASK (0xFFU)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_EN_SHIFT (0U)
/*! lmu_sta_banks_iso_en_bp_en - Firmware Bypass enable for lmu static banks iso_en */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_VAL_MASK (0xFF00U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_VAL_SHIFT (8U)
/*! lmu_sta_banks_iso_en_bp_val - Firmware Bypass value for lmu static banks iso_en */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_ISO_EN_BP_VAL_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_EN_MASK (0xFF0000U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_EN_SHIFT (16U)
/*! lmu_sta_banks_psw_en_bp_en - Firmware Bypass enable for lmu static banks psw_en */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_VAL_MASK (0xFF000000U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_VAL_SHIFT (24U)
/*! lmu_sta_banks_psw_en_bp_val - Firmware Bypass value for lmu static banks psw_en */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS0_LMU_STA_BANKS_PSW_EN_BP_VAL_MASK)
/*! @} */

/*! @name CIU2_CPU2_LMU_STA_BYPASS1 - LMU static bank control byapss1 Register for CPU2 */
/*! @{ */

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_EN_MASK (0xFFU)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_EN_SHIFT (0U)
/*! lmu_sta_banks_sram_pd_bp_en - Firmware Bypass enable for lmu static banks sram_pd */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_VAL_MASK (0xFF00U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_VAL_SHIFT (8U)
/*! lmu_sta_banks_sram_pd_bp_val - Firmware Bypass value for lmu static banks sram_pd */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_SRAM_PD_BP_VAL_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_EN_MASK (0xFF0000U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_EN_SHIFT (16U)
/*! lmu_sta_banks_fnrst_bp_en - Firmware Bypass enable for lmu static banks fnrst */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_VAL_MASK (0xFF000000U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_VAL_SHIFT (24U)
/*! lmu_sta_banks_fnrst_bp_val - Firmware Bypass value for lmu static banks fnrst */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS1_LMU_STA_BANKS_FNRST_BP_VAL_MASK)
/*! @} */

/*! @name CIU2_CPU2_LMU_STA_BYPASS2 - LMU static bank byapss2 Register for CPU2 */
/*! @{ */

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_EN_MASK (0xFFU)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_EN_SHIFT (0U)
/*! lmu_sta_banks_vddmc_sw_pd_ctrl_bp_en - Firmware Bypass enable for lmu static banks vddmc_sw_pd_ctrl */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_VAL_MASK (0xFF00U)
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_VAL_SHIFT (8U)
/*! lmu_sta_banks_vddmc_sw_pd_ctrl_bp_val - Firmware Bypass value for lmu static banks vddmc_sw_pd_ctrl */
#define CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_STA_BYPASS2_LMU_STA_BANKS_VDDMC_SW_PD_CTRL_BP_VAL_MASK)
/*! @} */

/*! @name CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS - LMU G2Bist control byapss Register for CPU2 */
/*! @{ */

#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_EN_MASK (0x1U)
#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_EN_SHIFT (0U)
/*! lmu_cpu2_sta_pwrdmn_rpr_req_bp_en - Firmware Bypass enable for CPU2 static banks lmu powerdomain repair request */
#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_EN_SHIFT)) & CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_EN_MASK)

#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_VAL_MASK (0xFEU)
#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_VAL_SHIFT (1U)
/*! lmu_cpu2_sta_pwrdmn_rpr_req_bp_val - Firmware Bypass value for CPU2 static banks lmu powerdomain repair request */
#define CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_VAL_SHIFT)) & CIU2_CIU2_CPU2_LMU_G2BIST_CTRL_BYPASS_LMU_CPU2_STA_PWRDMN_RPR_REQ_BP_VAL_MASK)
/*! @} */

/*! @name CIU2_APU_PWR_CTRL_BYPASS1 - APU power control Bypass Register 1 */
/*! @{ */

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_VAL_MASK (0x1U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_VAL_SHIFT (0U)
/*! brf_psw_bypass_val - brf Power Switch Control */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_EN_MASK (0x2U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_EN_SHIFT (1U)
/*! brf_psw_bypass_en - brf Power Switch Control Enable */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_PSW_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_VAL_MASK (0x4U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_VAL_SHIFT (2U)
/*! brf_fwbar_bypass_val - brf Firewallbar Control */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_EN_MASK (0x8U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_EN_SHIFT (3U)
/*! brf_fwbar_bypass_en - brf Firewallbar Control Enable */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_FWBAR_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_VAL_MASK (0x10U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_VAL_SHIFT (4U)
/*! brf_iso_en_bypass_val - brf Isolation Cell Control */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_EN_MASK (0x20U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_EN_SHIFT (5U)
/*! brf_iso_en_bypass_en - brf Isolation Cell Control Enable */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_ISO_EN_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_VAL_MASK (0x40U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_VAL_SHIFT (6U)
/*! brf_clk_div_rstb_bypass_val - Firmware Bypass Value for brf Clk_Div_Rstb (active low signal) */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_EN_MASK (0x80U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_EN_SHIFT (7U)
/*! brf_clk_div_rstb_bypass_en - Firmware Bypass brf Clk_Div_Rstb from APU */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_CLK_DIV_RSTB_BYPASS_EN_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_VAL_MASK (0x100U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_VAL_SHIFT (8U)
/*! brf_sram_pd_bypass_val - Firmware Bypass Value for SRAM_PD (active high signal) */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_VAL(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_VAL_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_VAL_MASK)

#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_EN_MASK (0x200U)
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_EN_SHIFT (9U)
/*! brf_sram_pd_bypass_en - Firmware Bypass SRAM_PD from APU */
#define CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_EN_SHIFT)) & CIU2_CIU2_APU_PWR_CTRL_BYPASS1_BRF_SRAM_PD_BYPASS_EN_MASK)
/*! @} */

/*! @name CIU2_AHB2AHB_BRIDGE_CTRL - AHB2AHB Bridge Control Register */
/*! @{ */

#define CIU2_CIU2_AHB2AHB_BRIDGE_CTRL_PREFETCH_HSEL_EN_MASK (0x1U)
#define CIU2_CIU2_AHB2AHB_BRIDGE_CTRL_PREFETCH_HSEL_EN_SHIFT (0U)
/*! prefetch_hsel_en - ahb2ahb bridge pre-fetch hsel enable */
#define CIU2_CIU2_AHB2AHB_BRIDGE_CTRL_PREFETCH_HSEL_EN(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB2AHB_BRIDGE_CTRL_PREFETCH_HSEL_EN_SHIFT)) & CIU2_CIU2_AHB2AHB_BRIDGE_CTRL_PREFETCH_HSEL_EN_MASK)
/*! @} */

/*! @name CIU2_AHB1_AHB2_TO_CLEAR - AHB1 AHB2 timeout logic clear register */
/*! @{ */

#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_AHB2_TIMEOUT_CLEAR_MASK (0x100U)
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_AHB2_TIMEOUT_CLEAR_SHIFT (8U)
/*! ahb2_timeout_clear - After the timeout happended on AHB2 bus, the cpu will read the ERR ISR and
 *    read the bus state which cause the timeout and then set this bit to 1 to clear the AHB2
 *    timeout logic to start recroding next transaction. This is self clearing bit
 */
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_AHB2_TIMEOUT_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB1_AHB2_TO_CLEAR_AHB2_TIMEOUT_CLEAR_SHIFT)) & CIU2_CIU2_AHB1_AHB2_TO_CLEAR_AHB2_TIMEOUT_CLEAR_MASK)

#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_DCODE_INV_ADDR_CLR_MASK (0x200U)
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_DCODE_INV_ADDR_CLR_SHIFT (9U)
/*! cpu2_dcode_inv_addr_clr - After the invalid address int happended on CPU2 dcode bus, the cpu2
 *    will read the ERR ISR and read the bus state which cause the timeout and then set this bit to 1
 *    to clear the CPU2 Dcode invalid addr logic to start recroding next transaction. This is self
 *    clearing bit
 */
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_DCODE_INV_ADDR_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_DCODE_INV_ADDR_CLR_SHIFT)) & CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_DCODE_INV_ADDR_CLR_MASK)

#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_ICODE_INV_ADDR_CLR_MASK (0x400U)
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_ICODE_INV_ADDR_CLR_SHIFT (10U)
/*! cpu2_icode_inv_addr_clr - After the invalid address int happended on CPU2 icode bus, the cpu2
 *    will read the ERR ISR and read the bus state which cause the timeout and then set this bit to 1
 *    to clear the CPU2 Icode invalid addr logic to start recroding next transaction. This is self
 *    clearing bit
 */
#define CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_ICODE_INV_ADDR_CLR(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_ICODE_INV_ADDR_CLR_SHIFT)) & CIU2_CIU2_AHB1_AHB2_TO_CLEAR_CPU2_ICODE_INV_ADDR_CLR_MASK)
/*! @} */

/*! @name CIU2_CPU_CPU2_DBG_STAT - CPU2 debug register */
/*! @{ */

#define CIU2_CIU2_CPU_CPU2_DBG_STAT_CPU2_RO_STATUS_MASK (0xFFFFFFFFU)
#define CIU2_CIU2_CPU_CPU2_DBG_STAT_CPU2_RO_STATUS_SHIFT (0U)
/*! cpu2_ro_status - cpu2 debug output */
#define CIU2_CIU2_CPU_CPU2_DBG_STAT_CPU2_RO_STATUS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU2_DBG_STAT_CPU2_RO_STATUS_SHIFT)) & CIU2_CIU2_CPU_CPU2_DBG_STAT_CPU2_RO_STATUS_MASK)
/*! @} */

/*! @name CIU2_CPU_CPU1_CTRL - CPU1 control register */
/*! @{ */

#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_JTAG_CHAIN_BYPASS_MASK (0x20000U)
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_JTAG_CHAIN_BYPASS_SHIFT (17U)
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_JTAG_CHAIN_BYPASS(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU1_CTRL_CPU1_JTAG_CHAIN_BYPASS_SHIFT)) & CIU2_CIU2_CPU_CPU1_CTRL_CPU1_JTAG_CHAIN_BYPASS_MASK)

#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_CPU2_MSG_SCHEME_MASK (0x40000U)
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_CPU2_MSG_SCHEME_SHIFT (18U)
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU1_CPU2_MSG_SCHEME(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU1_CTRL_CPU1_CPU2_MSG_SCHEME_SHIFT)) & CIU2_CIU2_CPU_CPU1_CTRL_CPU1_CPU2_MSG_SCHEME_MASK)

#define CIU2_CIU2_CPU_CPU1_CTRL_CPU2_RESET_INT_MASK (0x80000000U)
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU2_RESET_INT_SHIFT (31U)
/*! cpu2_reset_int - cpu1 fw reset cpu2 */
#define CIU2_CIU2_CPU_CPU1_CTRL_CPU2_RESET_INT(x) (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_CPU_CPU1_CTRL_CPU2_RESET_INT_SHIFT)) & CIU2_CIU2_CPU_CPU1_CTRL_CPU2_RESET_INT_MASK)
/*! @} */

/*! @name CIU2_TESTBUS_CTRL - CPU2 debug register */
/*! @{ */

#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_MASK  (0xFU)
#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_SHIFT (0U)
/*! testbus_sel - Select testbus debug output */
#define CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_SHIFT)) & CIU2_CIU2_TESTBUS_CTRL_TESTBUS_SEL_MASK)
/*! @} */

/*! @name CIU2_LBC_CTRL - LBC Control and Status */
/*! @{ */

#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_MASK       (0x1U)
#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_SHIFT      (0U)
/*! lbc_nco_en - LBC NCO Enable Signal */
#define CIU2_CIU2_LBC_CTRL_LBC_NCO_EN(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_SHIFT)) & CIU2_CIU2_LBC_CTRL_LBC_NCO_EN_MASK)

#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_MASK   (0x60U)
#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_SHIFT  (5U)
/*! lbc_debug_ctrl - LBC Debug Control Signal */
#define CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL(x)     (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_SHIFT)) & CIU2_CIU2_LBC_CTRL_LBC_DEBUG_CTRL_MASK)

#define CIU2_CIU2_LBC_CTRL_DEJIT_EN_MASK         (0x10000U)
#define CIU2_CIU2_LBC_CTRL_DEJIT_EN_SHIFT        (16U)
/*! dejit_en - De-jitter Enable */
#define CIU2_CIU2_LBC_CTRL_DEJIT_EN(x)           (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_DEJIT_EN_SHIFT)) & CIU2_CIU2_LBC_CTRL_DEJIT_EN_MASK)

#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_MASK       (0x20000U)
#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_SHIFT      (17U)
/*! auto_dejit - Auto de-jitter */
#define CIU2_CIU2_LBC_CTRL_AUTO_DEJIT(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_SHIFT)) & CIU2_CIU2_LBC_CTRL_AUTO_DEJIT_MASK)

#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK      (0x40000U)
#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_SHIFT     (18U)
/*! man_sel_nco - Manual select NCO */
#define CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO(x)        (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_SHIFT)) & CIU2_CIU2_LBC_CTRL_MAN_SEL_NCO_MASK)

#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_MASK  (0x800000U)
#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_SHIFT (23U)
/*! nco_lpo_ramp_dn - Status nco_lpo_ramp_dn */
#define CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_SHIFT)) & CIU2_CIU2_LBC_CTRL_NCO_LPO_RAMP_DN_MASK)

#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_MASK (0x1000000U)
#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_SHIFT (24U)
/*! ref_lpo_clk_good - Status ref_lpo_clk_good */
#define CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD(x)   (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_SHIFT)) & CIU2_CIU2_LBC_CTRL_REF_LPO_CLK_GOOD_MASK)

#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_MASK  (0x2000000U)
#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_SHIFT (25U)
/*! ref_lpo_ramp_dn - Status ref_lpo_ramp_dn */
#define CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_SHIFT)) & CIU2_CIU2_LBC_CTRL_REF_LPO_RAMP_DN_MASK)

#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_MASK  (0x4000000U)
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_SHIFT (26U)
/*! lpo_clk_sel_fsm - Status lpo_clk_sel_fsm */
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_SHIFT)) & CIU2_CIU2_LBC_CTRL_LPO_CLK_SEL_FSM_MASK)

#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_MASK  (0xF8000000U)
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_SHIFT (27U)
/*! lpo_clk_3k2_cnt - Status lpo_clk_3k2_cnt, 3.2KHz Count */
#define CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT(x)    (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_SHIFT)) & CIU2_CIU2_LBC_CTRL_LPO_CLK_3K2_CNT_MASK)
/*! @} */

/*! @name CIU2_LBC_SLPCLK_NCO - LBC NCO Step for Sleep Clock */
/*! @{ */

#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP_MASK       (0xFFFFFFFFU)
#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP_SHIFT      (0U)
/*! step - LBC NCO step for sleep clock. Please refer to design spreadsheet for more details. */
#define CIU2_CIU2_LBC_SLPCLK_NCO_STEP(x)         (((uint32_t)(((uint32_t)(x)) << CIU2_CIU2_LBC_SLPCLK_NCO_STEP_SHIFT)) & CIU2_CIU2_LBC_SLPCLK_NCO_STEP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CIU2_Register_Masks */

/*! @brief IMU message link between current CPU and remote peer CPU. */
typedef enum
{
    kIMU_LinkCpu1Cpu2 = 0, /*! Message link between CPU1 and CPU2. */
    kIMU_LinkMax           /*! Message link count used for boundary check. */
} imu_link_t;

/*! @brief IMU base register for current CPU. */
#define IMU_CUR_CPU_BASE(link) (&(CIU2->CIU2_IMU_CPU1_WR_MSG_TO_CPU2))
/*! @brief IMU base register for peer CPU. */
#define IMU_PEER_CPU_BASE(link) (&(CIU2->CIU2_IMU_CPU2_WR_MSG_TO_CPU1))

/*! @brief IMU CPU index for current CPU. */
#define IMU_CPU_INDEX (1U)


/*!
 * @}
 */ /* end of group CIU2_Peripheral_Access_Layer */


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


#endif  /* PERI_CIU2_H_ */

