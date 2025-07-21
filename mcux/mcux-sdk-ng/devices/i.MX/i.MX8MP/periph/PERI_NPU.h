/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
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
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NPU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NPU.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NPU
 *
 * CMSIS Peripheral Access Layer for NPU
 */

#if !defined(PERI_NPU_H_)
#define PERI_NPU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
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
   -- NPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Peripheral_Access_Layer NPU Peripheral Access Layer
 * @{
 */

/** NPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t AQHICLOCKCONTROL;                  /**< Clock Control Register, offset: 0x0 */
  __I  uint32_t AQHIIDLE;                          /**< Idle Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __I  uint32_t AQAXISTATUS;                       /**< AXI Status Register, offset: 0xC */
  __I  uint32_t AQINTRACKNOWLEDGE;                 /**< Interrupt Acknowledge Register, offset: 0x10 */
  __IO uint32_t AQINTRENBL;                        /**< Interrupt Enable Register, offset: 0x14 */
       uint8_t RESERVED_1[96];
  __IO uint32_t GCTOTALCYCLES;                     /**< Total Cycles Register, offset: 0x78 */
       uint8_t RESERVED_2[132];
  __IO uint32_t GCMODULEPOWERCONTROLS;             /**< Module Power Level Control Register, offset: 0x100 */
       uint8_t RESERVED_3[8];
  __IO uint32_t GCPULSEEATER;                      /**< Pulse eater Control Register, offset: 0x10C */
       uint8_t RESERVED_4[632];
  __IO uint32_t GCREGMMUAHBCONTROL;                /**< MMU Control Register, offset: 0x388 */
  __IO uint32_t GCREGMMUAHBTABLEARRAYBASEADDRESSLOW; /**< MMU Table Array Base Lower 32-bit Address Register, offset: 0x38C */
  __IO uint32_t GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH; /**< MMU Table Array Base Higher 32-bit Address Register, offset: 0x390 */
  __IO uint32_t GCREGMMUAHBTABLEARRAYSIZE;         /**< MMU Table Array Size Control Register, offset: 0x394 */
  __IO uint32_t GCREGMMUAHBSAFENONSECUREADDRESS;   /**< MMU NonSecure Address Register, offset: 0x398 */
  __IO uint32_t GCREGMMUAHBSAFESECUREADDRESS;      /**< MMU Secure Address Register, offset: 0x39C */
       uint8_t RESERVED_5[4];
  __O  uint32_t GCREGCMDBUFFERAHBCTRL;             /**< Command Buffer Control Register, offset: 0x3A4 */
  __IO uint32_t GCREGHIAHBCONTROL;                 /**< MMU Host Interface Control Register, offset: 0x3A8 */
  __IO uint32_t GCREGAXIAHBCONFIG;                 /**< MMU AXI Configuration Register, offset: 0x3AC */
       uint8_t RESERVED_6[100];
  __IO uint32_t AQMEMORYDEBUG;                     /**< Memory Debug Register, offset: 0x414 */
       uint8_t RESERVED_7[20];
  __IO uint32_t AQREGISTERTIMINGCONTROL;           /**< Register Timing Control Register, offset: 0x42C */
       uint8_t RESERVED_8[548];
  __O  uint32_t AQCMDBUFFERADDR;                   /**< Command Buffer Base Address Register, offset: 0x654 */
       uint8_t RESERVED_9[12];
  __I  uint32_t AQFEDEBUGCURCMDADR;                /**< Command Decoder Address Register, offset: 0x664 */
} NPU_Type;

/* ----------------------------------------------------------------------------
   -- NPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NPU_Register_Masks NPU Register Masks
 * @{
 */

/*! @name AQHICLOCKCONTROL - Clock Control Register */
/*! @{ */

#define NPU_AQHICLOCKCONTROL_CLK3D_DIS_MASK      (0x1U)
#define NPU_AQHICLOCKCONTROL_CLK3D_DIS_SHIFT     (0U)
/*! CLK3D_DIS - Disable 3D clock
 *  0b1..The clock is frozen
 */
#define NPU_AQHICLOCKCONTROL_CLK3D_DIS(x)        (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_CLK3D_DIS_SHIFT)) & NPU_AQHICLOCKCONTROL_CLK3D_DIS_MASK)

#define NPU_AQHICLOCKCONTROL_CLK2D_DIS_MASK      (0x2U)
#define NPU_AQHICLOCKCONTROL_CLK2D_DIS_SHIFT     (1U)
/*! CLK2D_DIS - Disable 2D clock */
#define NPU_AQHICLOCKCONTROL_CLK2D_DIS(x)        (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_CLK2D_DIS_SHIFT)) & NPU_AQHICLOCKCONTROL_CLK2D_DIS_MASK)

#define NPU_AQHICLOCKCONTROL_FSCALE_VAL_MASK     (0x1FCU)
#define NPU_AQHICLOCKCONTROL_FSCALE_VAL_SHIFT    (2U)
/*! FSCALE_VAL - Core clock frequency scale value */
#define NPU_AQHICLOCKCONTROL_FSCALE_VAL(x)       (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_FSCALE_VAL_SHIFT)) & NPU_AQHICLOCKCONTROL_FSCALE_VAL_MASK)

#define NPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_MASK (0x200U)
#define NPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_SHIFT (9U)
/*! FSCALE_CMD_LOAD - Core clock frequency scale value enable
 *  0b1..The frequency scale factor is updated with the value FSCALE_VAL[6:0]. The bit sets back to 0 after that.
 */
#define NPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_SHIFT)) & NPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_MASK)

#define NPU_AQHICLOCKCONTROL_DIS_RAM_CLK_GATING_MASK (0x400U)
#define NPU_AQHICLOCKCONTROL_DIS_RAM_CLK_GATING_SHIFT (10U)
/*! DIS_RAM_CLK_GATING - Disable clock gating for RAMs */
#define NPU_AQHICLOCKCONTROL_DIS_RAM_CLK_GATING(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_DIS_RAM_CLK_GATING_SHIFT)) & NPU_AQHICLOCKCONTROL_DIS_RAM_CLK_GATING_MASK)

#define NPU_AQHICLOCKCONTROL_DIS_RAM_PWR_OPT_MASK (0x2000U)
#define NPU_AQHICLOCKCONTROL_DIS_RAM_PWR_OPT_SHIFT (13U)
/*! DIS_RAM_PWR_OPT - Disable RAM power optimization */
#define NPU_AQHICLOCKCONTROL_DIS_RAM_PWR_OPT(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_DIS_RAM_PWR_OPT_SHIFT)) & NPU_AQHICLOCKCONTROL_DIS_RAM_PWR_OPT_MASK)

#define NPU_AQHICLOCKCONTROL_IDLE3_D_MASK        (0x10000U)
#define NPU_AQHICLOCKCONTROL_IDLE3_D_SHIFT       (16U)
/*! IDLE3_D - 3D pipe is idle */
#define NPU_AQHICLOCKCONTROL_IDLE3_D(x)          (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_IDLE3_D_SHIFT)) & NPU_AQHICLOCKCONTROL_IDLE3_D_MASK)

#define NPU_AQHICLOCKCONTROL_ISOLATE_GPU_MASK    (0x80000U)
#define NPU_AQHICLOCKCONTROL_ISOLATE_GPU_SHIFT   (19U)
/*! ISOLATE_GPU - Isolate GPU */
#define NPU_AQHICLOCKCONTROL_ISOLATE_GPU(x)      (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_ISOLATE_GPU_SHIFT)) & NPU_AQHICLOCKCONTROL_ISOLATE_GPU_MASK)

#define NPU_AQHICLOCKCONTROL_MULTI_PIPE_REG_SEL_MASK (0xF00000U)
#define NPU_AQHICLOCKCONTROL_MULTI_PIPE_REG_SEL_SHIFT (20U)
/*! MULTI_PIPE_REG_SEL - Multiple Pipe Register Select */
#define NPU_AQHICLOCKCONTROL_MULTI_PIPE_REG_SEL(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQHICLOCKCONTROL_MULTI_PIPE_REG_SEL_SHIFT)) & NPU_AQHICLOCKCONTROL_MULTI_PIPE_REG_SEL_MASK)
/*! @} */

/*! @name AQHIIDLE - Idle Status Register */
/*! @{ */

#define NPU_AQHIIDLE_IDLE_FE_MASK                (0x1U)
#define NPU_AQHIIDLE_IDLE_FE_SHIFT               (0U)
/*! IDLE_FE - FE is idle */
#define NPU_AQHIIDLE_IDLE_FE(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_AQHIIDLE_IDLE_FE_SHIFT)) & NPU_AQHIIDLE_IDLE_FE_MASK)

#define NPU_AQHIIDLE_IDLE_SH_MASK                (0x8U)
#define NPU_AQHIIDLE_IDLE_SH_SHIFT               (3U)
/*! IDLE_SH - SH is idle */
#define NPU_AQHIIDLE_IDLE_SH(x)                  (((uint32_t)(((uint32_t)(x)) << NPU_AQHIIDLE_IDLE_SH_SHIFT)) & NPU_AQHIIDLE_IDLE_SH_MASK)

#define NPU_AQHIIDLE_AXI_LP_MASK                 (0x80000000U)
#define NPU_AQHIIDLE_AXI_LP_SHIFT                (31U)
/*! AXI_LP - AXI is in low power mode */
#define NPU_AQHIIDLE_AXI_LP(x)                   (((uint32_t)(((uint32_t)(x)) << NPU_AQHIIDLE_AXI_LP_SHIFT)) & NPU_AQHIIDLE_AXI_LP_MASK)
/*! @} */

/*! @name AQAXISTATUS - AXI Status Register */
/*! @{ */

#define NPU_AQAXISTATUS_WR_ERR_ID_MASK           (0xFU)
#define NPU_AQAXISTATUS_WR_ERR_ID_SHIFT          (0U)
/*! WR_ERR_ID - Write Error ID */
#define NPU_AQAXISTATUS_WR_ERR_ID(x)             (((uint32_t)(((uint32_t)(x)) << NPU_AQAXISTATUS_WR_ERR_ID_SHIFT)) & NPU_AQAXISTATUS_WR_ERR_ID_MASK)

#define NPU_AQAXISTATUS_RD_ERR_ID_MASK           (0xF0U)
#define NPU_AQAXISTATUS_RD_ERR_ID_SHIFT          (4U)
/*! RD_ERR_ID - Read Error ID */
#define NPU_AQAXISTATUS_RD_ERR_ID(x)             (((uint32_t)(((uint32_t)(x)) << NPU_AQAXISTATUS_RD_ERR_ID_SHIFT)) & NPU_AQAXISTATUS_RD_ERR_ID_MASK)

#define NPU_AQAXISTATUS_DET_WR_ERR_MASK          (0x100U)
#define NPU_AQAXISTATUS_DET_WR_ERR_SHIFT         (8U)
/*! DET_WR_ERR - Detect Write Error
 *  0b1..Detect write error
 */
#define NPU_AQAXISTATUS_DET_WR_ERR(x)            (((uint32_t)(((uint32_t)(x)) << NPU_AQAXISTATUS_DET_WR_ERR_SHIFT)) & NPU_AQAXISTATUS_DET_WR_ERR_MASK)

#define NPU_AQAXISTATUS_DET_RD_ERR_MASK          (0x200U)
#define NPU_AQAXISTATUS_DET_RD_ERR_SHIFT         (9U)
/*! DET_RD_ERR - Detect Read Error
 *  0b1..Detect read error
 */
#define NPU_AQAXISTATUS_DET_RD_ERR(x)            (((uint32_t)(((uint32_t)(x)) << NPU_AQAXISTATUS_DET_RD_ERR_SHIFT)) & NPU_AQAXISTATUS_DET_RD_ERR_MASK)
/*! @} */

/*! @name AQINTRACKNOWLEDGE - Interrupt Acknowledge Register */
/*! @{ */

#define NPU_AQINTRACKNOWLEDGE_INTR_VEC_MASK      (0xFFFFFFFFU)
#define NPU_AQINTRACKNOWLEDGE_INTR_VEC_SHIFT     (0U)
/*! INTR_VEC - Interrupt Vector */
#define NPU_AQINTRACKNOWLEDGE_INTR_VEC(x)        (((uint32_t)(((uint32_t)(x)) << NPU_AQINTRACKNOWLEDGE_INTR_VEC_SHIFT)) & NPU_AQINTRACKNOWLEDGE_INTR_VEC_MASK)
/*! @} */

/*! @name AQINTRENBL - Interrupt Enable Register */
/*! @{ */

#define NPU_AQINTRENBL_INTR_ENBL_VEC_MASK        (0xFFFFFFFFU)
#define NPU_AQINTRENBL_INTR_ENBL_VEC_SHIFT       (0U)
/*! INTR_ENBL_VEC - Interrupt Vector Enable */
#define NPU_AQINTRENBL_INTR_ENBL_VEC(x)          (((uint32_t)(((uint32_t)(x)) << NPU_AQINTRENBL_INTR_ENBL_VEC_SHIFT)) & NPU_AQINTRENBL_INTR_ENBL_VEC_MASK)
/*! @} */

/*! @name GCTOTALCYCLES - Total Cycles Register */
/*! @{ */

#define NPU_GCTOTALCYCLES_CYCLES_MASK            (0xFFFFFFFFU)
#define NPU_GCTOTALCYCLES_CYCLES_SHIFT           (0U)
/*! CYCLES - Cycles */
#define NPU_GCTOTALCYCLES_CYCLES(x)              (((uint32_t)(((uint32_t)(x)) << NPU_GCTOTALCYCLES_CYCLES_SHIFT)) & NPU_GCTOTALCYCLES_CYCLES_MASK)
/*! @} */

/*! @name GCMODULEPOWERCONTROLS - Module Power Level Control Register */
/*! @{ */

#define NPU_GCMODULEPOWERCONTROLS_EN_MOD_CLK_GATING_MASK (0x1U)
#define NPU_GCMODULEPOWERCONTROLS_EN_MOD_CLK_GATING_SHIFT (0U)
/*! EN_MOD_CLK_GATING - Enables module level clock gating */
#define NPU_GCMODULEPOWERCONTROLS_EN_MOD_CLK_GATING(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCMODULEPOWERCONTROLS_EN_MOD_CLK_GATING_SHIFT)) & NPU_GCMODULEPOWERCONTROLS_EN_MOD_CLK_GATING_MASK)

#define NPU_GCMODULEPOWERCONTROLS_DIS_STALL_MOD_CLK_GATING_MASK (0x2U)
#define NPU_GCMODULEPOWERCONTROLS_DIS_STALL_MOD_CLK_GATING_SHIFT (1U)
/*! DIS_STALL_MOD_CLK_GATING - Disables module level clock gating for stall condition */
#define NPU_GCMODULEPOWERCONTROLS_DIS_STALL_MOD_CLK_GATING(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCMODULEPOWERCONTROLS_DIS_STALL_MOD_CLK_GATING_SHIFT)) & NPU_GCMODULEPOWERCONTROLS_DIS_STALL_MOD_CLK_GATING_MASK)

#define NPU_GCMODULEPOWERCONTROLS_DIS_STARVE_MOD_CLK_GATING_MASK (0x4U)
#define NPU_GCMODULEPOWERCONTROLS_DIS_STARVE_MOD_CLK_GATING_SHIFT (2U)
/*! DIS_STARVE_MOD_CLK_GATING - Disables module level clock gating for starve/idle condition */
#define NPU_GCMODULEPOWERCONTROLS_DIS_STARVE_MOD_CLK_GATING(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCMODULEPOWERCONTROLS_DIS_STARVE_MOD_CLK_GATING_SHIFT)) & NPU_GCMODULEPOWERCONTROLS_DIS_STARVE_MOD_CLK_GATING_MASK)

#define NPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_MASK (0xF0U)
#define NPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_SHIFT (4U)
/*! TURN_ON_COUNTER - Number of clock cycles to wait after turning on the clock */
#define NPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_SHIFT)) & NPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_MASK)

#define NPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_MASK (0xFFFF0000U)
#define NPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_SHIFT (16U)
/*! TURN_OFF_COUNTER - Counter value for clock gating the module if the module is idle for this amount of clock cycles */
#define NPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_SHIFT)) & NPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_MASK)
/*! @} */

/*! @name GCPULSEEATER - Pulse eater Control Register */
/*! @{ */

#define NPU_GCPULSEEATER_FSCALE_CMD_LOAD_SH_MASK (0x1U)
#define NPU_GCPULSEEATER_FSCALE_CMD_LOAD_SH_SHIFT (0U)
/*! FSCALE_CMD_LOAD_SH - Fscale_cmd_load for shader */
#define NPU_GCPULSEEATER_FSCALE_CMD_LOAD_SH(x)   (((uint32_t)(((uint32_t)(x)) << NPU_GCPULSEEATER_FSCALE_CMD_LOAD_SH_SHIFT)) & NPU_GCPULSEEATER_FSCALE_CMD_LOAD_SH_MASK)

#define NPU_GCPULSEEATER_FSCALE_VAL_SH_MASK      (0xFEU)
#define NPU_GCPULSEEATER_FSCALE_VAL_SH_SHIFT     (1U)
/*! FSCALE_VAL_SH - Fscale value for shader */
#define NPU_GCPULSEEATER_FSCALE_VAL_SH(x)        (((uint32_t)(((uint32_t)(x)) << NPU_GCPULSEEATER_FSCALE_VAL_SH_SHIFT)) & NPU_GCPULSEEATER_FSCALE_VAL_SH_MASK)
/*! @} */

/*! @name GCREGMMUAHBCONTROL - MMU Control Register */
/*! @{ */

#define NPU_GCREGMMUAHBCONTROL_MMU_MASK          (0x1U)
#define NPU_GCREGMMUAHBCONTROL_MMU_SHIFT         (0U)
/*! MMU - Enable the MMU
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_GCREGMMUAHBCONTROL_MMU(x)            (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBCONTROL_MMU_SHIFT)) & NPU_GCREGMMUAHBCONTROL_MMU_MASK)
/*! @} */

/*! @name GCREGMMUAHBTABLEARRAYBASEADDRESSLOW - MMU Table Array Base Lower 32-bit Address Register */
/*! @{ */

#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSLOW_ADDRESS_MASK (0xFFFFFFFFU)
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSLOW_ADDRESS_SHIFT (0U)
/*! ADDRESS - Address */
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSLOW_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSLOW_ADDRESS_SHIFT)) & NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSLOW_ADDRESS_MASK)
/*! @} */

/*! @name GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH - MMU Table Array Base Higher 32-bit Address Register */
/*! @{ */

#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_MASK (0xFFU)
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHIFT (0U)
/*! MASTER_TLB - Upper 8-bits of the master TLB address to form a true 40-bit address */
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHIFT)) & NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_MASK)

#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SECURE_MASK (0x100U)
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SECURE_SHIFT (8U)
/*! MASTER_TLB_SECURE - Bit that defines whether the master TLB address is secure or not */
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SECURE(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SECURE_SHIFT)) & NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SECURE_MASK)

#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHAREABLE_MASK (0x200U)
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHAREABLE_SHIFT (9U)
/*! MASTER_TLB_SHAREABLE - Bit that defines whether the master TLB address is shareable or not */
#define NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHAREABLE(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHAREABLE_SHIFT)) & NPU_GCREGMMUAHBTABLEARRAYBASEADDRESSHIGH_MASTER_TLB_SHAREABLE_MASK)
/*! @} */

/*! @name GCREGMMUAHBTABLEARRAYSIZE - MMU Table Array Size Control Register */
/*! @{ */

#define NPU_GCREGMMUAHBTABLEARRAYSIZE_SIZE_MASK  (0xFFFFU)
#define NPU_GCREGMMUAHBTABLEARRAYSIZE_SIZE_SHIFT (0U)
/*! SIZE - Size */
#define NPU_GCREGMMUAHBTABLEARRAYSIZE_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBTABLEARRAYSIZE_SIZE_SHIFT)) & NPU_GCREGMMUAHBTABLEARRAYSIZE_SIZE_MASK)
/*! @} */

/*! @name GCREGMMUAHBSAFENONSECUREADDRESS - MMU NonSecure Address Register */
/*! @{ */

#define NPU_GCREGMMUAHBSAFENONSECUREADDRESS_ADDRESS_MASK (0xFFFFFFFFU)
#define NPU_GCREGMMUAHBSAFENONSECUREADDRESS_ADDRESS_SHIFT (0U)
/*! ADDRESS - Address */
#define NPU_GCREGMMUAHBSAFENONSECUREADDRESS_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBSAFENONSECUREADDRESS_ADDRESS_SHIFT)) & NPU_GCREGMMUAHBSAFENONSECUREADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name GCREGMMUAHBSAFESECUREADDRESS - MMU Secure Address Register */
/*! @{ */

#define NPU_GCREGMMUAHBSAFESECUREADDRESS_ADDRESS_MASK (0xFFFFFFFFU)
#define NPU_GCREGMMUAHBSAFESECUREADDRESS_ADDRESS_SHIFT (0U)
/*! ADDRESS - Address */
#define NPU_GCREGMMUAHBSAFESECUREADDRESS_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGMMUAHBSAFESECUREADDRESS_ADDRESS_SHIFT)) & NPU_GCREGMMUAHBSAFESECUREADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name GCREGCMDBUFFERAHBCTRL - Command Buffer Control Register */
/*! @{ */

#define NPU_GCREGCMDBUFFERAHBCTRL_PREFETCH_MASK  (0xFFFFU)
#define NPU_GCREGCMDBUFFERAHBCTRL_PREFETCH_SHIFT (0U)
/*! PREFETCH - Prefetch */
#define NPU_GCREGCMDBUFFERAHBCTRL_PREFETCH(x)    (((uint32_t)(((uint32_t)(x)) << NPU_GCREGCMDBUFFERAHBCTRL_PREFETCH_SHIFT)) & NPU_GCREGCMDBUFFERAHBCTRL_PREFETCH_MASK)

#define NPU_GCREGCMDBUFFERAHBCTRL_ENABLE_MASK    (0x10000U)
#define NPU_GCREGCMDBUFFERAHBCTRL_ENABLE_SHIFT   (16U)
/*! ENABLE - Enable the command parser
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_GCREGCMDBUFFERAHBCTRL_ENABLE(x)      (((uint32_t)(((uint32_t)(x)) << NPU_GCREGCMDBUFFERAHBCTRL_ENABLE_SHIFT)) & NPU_GCREGCMDBUFFERAHBCTRL_ENABLE_MASK)
/*! @} */

/*! @name GCREGHIAHBCONTROL - MMU Host Interface Control Register */
/*! @{ */

#define NPU_GCREGHIAHBCONTROL_SOFT_RESET_MASK    (0x1U)
#define NPU_GCREGHIAHBCONTROL_SOFT_RESET_SHIFT   (0U)
/*! SOFT_RESET - Soft Reset
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_GCREGHIAHBCONTROL_SOFT_RESET(x)      (((uint32_t)(((uint32_t)(x)) << NPU_GCREGHIAHBCONTROL_SOFT_RESET_SHIFT)) & NPU_GCREGHIAHBCONTROL_SOFT_RESET_MASK)

#define NPU_GCREGHIAHBCONTROL_DEBUG_MODE_MASK    (0x2U)
#define NPU_GCREGHIAHBCONTROL_DEBUG_MODE_SHIFT   (1U)
/*! DEBUG_MODE - Debug Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define NPU_GCREGHIAHBCONTROL_DEBUG_MODE(x)      (((uint32_t)(((uint32_t)(x)) << NPU_GCREGHIAHBCONTROL_DEBUG_MODE_SHIFT)) & NPU_GCREGHIAHBCONTROL_DEBUG_MODE_MASK)
/*! @} */

/*! @name GCREGAXIAHBCONFIG - MMU AXI Configuration Register */
/*! @{ */

#define NPU_GCREGAXIAHBCONFIG_AWID_MASK          (0xFU)
#define NPU_GCREGAXIAHBCONFIG_AWID_SHIFT         (0U)
#define NPU_GCREGAXIAHBCONFIG_AWID(x)            (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_AWID_SHIFT)) & NPU_GCREGAXIAHBCONFIG_AWID_MASK)

#define NPU_GCREGAXIAHBCONFIG_ARID_MASK          (0xF0U)
#define NPU_GCREGAXIAHBCONFIG_ARID_SHIFT         (4U)
#define NPU_GCREGAXIAHBCONFIG_ARID(x)            (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_ARID_SHIFT)) & NPU_GCREGAXIAHBCONFIG_ARID_MASK)

#define NPU_GCREGAXIAHBCONFIG_AWCACHE_MASK       (0xF00U)
#define NPU_GCREGAXIAHBCONFIG_AWCACHE_SHIFT      (8U)
/*! AWCACHE - AW Cache value */
#define NPU_GCREGAXIAHBCONFIG_AWCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_AWCACHE_SHIFT)) & NPU_GCREGAXIAHBCONFIG_AWCACHE_MASK)

#define NPU_GCREGAXIAHBCONFIG_ARCACHE_MASK       (0xF000U)
#define NPU_GCREGAXIAHBCONFIG_ARCACHE_SHIFT      (12U)
/*! ARCACHE - AR Cache value */
#define NPU_GCREGAXIAHBCONFIG_ARCACHE(x)         (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_ARCACHE_SHIFT)) & NPU_GCREGAXIAHBCONFIG_ARCACHE_MASK)

#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_SHARED_MASK (0x30000U)
#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_SHARED_SHIFT (16U)
/*! AXDOMAIN_SHARED - Ax Domain value */
#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_SHARED(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_AXDOMAIN_SHARED_SHIFT)) & NPU_GCREGAXIAHBCONFIG_AXDOMAIN_SHARED_MASK)

#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_NON_SHARED_MASK (0xC0000U)
#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_NON_SHARED_SHIFT (18U)
/*! AXDOMAIN_NON_SHARED - Ax Domain value */
#define NPU_GCREGAXIAHBCONFIG_AXDOMAIN_NON_SHARED(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_AXDOMAIN_NON_SHARED_SHIFT)) & NPU_GCREGAXIAHBCONFIG_AXDOMAIN_NON_SHARED_MASK)

#define NPU_GCREGAXIAHBCONFIG_AXCACHE_OVERRIDE_SHARED_MASK (0xF00000U)
#define NPU_GCREGAXIAHBCONFIG_AXCACHE_OVERRIDE_SHARED_SHIFT (20U)
/*! AXCACHE_OVERRIDE_SHARED - Ax Cache value */
#define NPU_GCREGAXIAHBCONFIG_AXCACHE_OVERRIDE_SHARED(x) (((uint32_t)(((uint32_t)(x)) << NPU_GCREGAXIAHBCONFIG_AXCACHE_OVERRIDE_SHARED_SHIFT)) & NPU_GCREGAXIAHBCONFIG_AXCACHE_OVERRIDE_SHARED_MASK)
/*! @} */

/*! @name AQMEMORYDEBUG - Memory Debug Register */
/*! @{ */

#define NPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_MASK (0xFFU)
#define NPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_SHIFT (0U)
/*! MAX_OUTSTANDING_READS - Maximum Outstanding Reads */
#define NPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_SHIFT)) & NPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_MASK)
/*! @} */

/*! @name AQREGISTERTIMINGCONTROL - Register Timing Control Register */
/*! @{ */

#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_MASK (0xFFU)
#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_SHIFT (0U)
/*! FOR_RF1P - For 1 port RAM */
#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF1P(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_MASK (0xFF00U)
#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_SHIFT (8U)
/*! FOR_RF2P - For 2 port RAM */
#define NPU_AQREGISTERTIMINGCONTROL_FOR_RF2P(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_FAST_RTC_MASK (0x30000U)
#define NPU_AQREGISTERTIMINGCONTROL_FAST_RTC_SHIFT (16U)
/*! FAST_RTC - RTC for fast RAM */
#define NPU_AQREGISTERTIMINGCONTROL_FAST_RTC(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_FAST_RTC_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_FAST_RTC_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_FAST_WTC_MASK (0xC0000U)
#define NPU_AQREGISTERTIMINGCONTROL_FAST_WTC_SHIFT (18U)
/*! FAST_WTC - WTC for fast RAM */
#define NPU_AQREGISTERTIMINGCONTROL_FAST_WTC(x)  (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_FAST_WTC_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_FAST_WTC_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_MASK (0x100000U)
#define NPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_SHIFT (20U)
/*! POWER_DOWN - Power Down Memory */
#define NPU_AQREGISTERTIMINGCONTROL_POWER_DOWN(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_MASK (0x200000U)
#define NPU_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_SHIFT (21U)
/*! DEEP_SLEEP - Deep sleep */
#define NPU_AQREGISTERTIMINGCONTROL_DEEP_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_DEEP_SLEEP_MASK)

#define NPU_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_MASK (0x400000U)
#define NPU_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_SHIFT (22U)
/*! LIGHT_SLEEP - Light sleep */
#define NPU_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << NPU_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_SHIFT)) & NPU_AQREGISTERTIMINGCONTROL_LIGHT_SLEEP_MASK)
/*! @} */

/*! @name AQCMDBUFFERADDR - Command Buffer Base Address Register */
/*! @{ */

#define NPU_AQCMDBUFFERADDR_ADDRESS_MASK         (0x7FFFFFFFU)
#define NPU_AQCMDBUFFERADDR_ADDRESS_SHIFT        (0U)
/*! ADDRESS - Address */
#define NPU_AQCMDBUFFERADDR_ADDRESS(x)           (((uint32_t)(((uint32_t)(x)) << NPU_AQCMDBUFFERADDR_ADDRESS_SHIFT)) & NPU_AQCMDBUFFERADDR_ADDRESS_MASK)

#define NPU_AQCMDBUFFERADDR_TYPE_MASK            (0x80000000U)
#define NPU_AQCMDBUFFERADDR_TYPE_SHIFT           (31U)
/*! TYPE - Type
 *  0b0..System
 *  0b1..Virtual System
 */
#define NPU_AQCMDBUFFERADDR_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << NPU_AQCMDBUFFERADDR_TYPE_SHIFT)) & NPU_AQCMDBUFFERADDR_TYPE_MASK)
/*! @} */

/*! @name AQFEDEBUGCURCMDADR - Command Decoder Address Register */
/*! @{ */

#define NPU_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_MASK  (0xFFFFFFF8U)
#define NPU_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_SHIFT (3U)
/*! CUR_CMD_ADR - Command decoder Address */
#define NPU_AQFEDEBUGCURCMDADR_CUR_CMD_ADR(x)    (((uint32_t)(((uint32_t)(x)) << NPU_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_SHIFT)) & NPU_AQFEDEBUGCURCMDADR_CUR_CMD_ADR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NPU_Register_Masks */


/*!
 * @}
 */ /* end of group NPU_Peripheral_Access_Layer */


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


#endif  /* PERI_NPU_H_ */

