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
**         CMSIS Peripheral Access Layer for SIM_LPAV
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
 * @file PERI_SIM_LPAV.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM_LPAV
 *
 * CMSIS Peripheral Access Layer for SIM_LPAV
 */

#if !defined(PERI_SIM_LPAV_H_)
#define PERI_SIM_LPAV_H_                         /**< Symbol preventing repeated inclusion */

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
   -- SIM_LPAV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_LPAV_Peripheral_Access_Layer SIM_LPAV Peripheral Access Layer
 * @{
 */

/** SIM_LPAV - Register Layout Typedef */
typedef struct {
  __IO uint32_t GPR0;                              /**< HW AVD_SIM General Purpose Register 0, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SYSCTRL0;                          /**< Audio-Video Domain System Control Register 0, offset: 0x8 */
       uint8_t RESERVED_1[8];
  __IO uint32_t LPDDR_CTRL;                        /**< LPDDR Control Register, offset: 0x14 */
  __IO uint32_t LPDDR_CTRL2;                       /**< LPDDR Control Register, offset: 0x18 */
  __IO uint32_t DEFAULT_QOS;                       /**< Default Value Register for Quality of Service (QoS), offset: 0x1C */
  __IO uint32_t PANIC_QOS;                         /**< Panic Value Register for Quality of Service (QoS), offset: 0x20 */
  __IO uint32_t SAI_MULTISYNC_ENABLE_SELECTOR;     /**< SAI 6 and 7 Transmitter/Receiver Multi-Synchronous Enable Source, offset: 0x24 */
  __I  uint32_t HIFI4_GPR0;                        /**< HiFi4 DSP General Purpose Register, offset: 0x28 */
  __I  uint32_t HIFI4_GPR1;                        /**< HiFi4 DSP General Purpose Register, offset: 0x2C */
  __I  uint32_t HIFI4_GPR2;                        /**< HiFi4 DSP General Purpose Register, offset: 0x30 */
  __IO uint32_t AXI_CACHE_OVERRIDE;                /**< Audio-Video Domain AXI Cache Override, offset: 0x34 */
} SIM_LPAV_Type;

/* ----------------------------------------------------------------------------
   -- SIM_LPAV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_LPAV_Register_Masks SIM_LPAV Register Masks
 * @{
 */

/*! @name GPR0 - HW AVD_SIM General Purpose Register 0 */
/*! @{ */

#define SIM_LPAV_GPR0_GPR0_MASK                  (0x1U)
#define SIM_LPAV_GPR0_GPR0_SHIFT                 (0U)
/*! GPR0 - General Purpose Read/Write Register */
#define SIM_LPAV_GPR0_GPR0(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_GPR0_GPR0_SHIFT)) & SIM_LPAV_GPR0_GPR0_MASK)
/*! @} */

/*! @name SYSCTRL0 - Audio-Video Domain System Control Register 0 */
/*! @{ */

#define SIM_LPAV_SYSCTRL0_DSI_CM_MASK            (0x2U)
#define SIM_LPAV_SYSCTRL0_DSI_CM_SHIFT           (1U)
/*! DSI_CM - DSI Mode Control */
#define SIM_LPAV_SYSCTRL0_DSI_CM(x)              (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_CM_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_CM_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_SD_MASK            (0x4U)
#define SIM_LPAV_SYSCTRL0_DSI_SD_SHIFT           (2U)
/*! DSI_SD - DSI Shutdown Control */
#define SIM_LPAV_SYSCTRL0_DSI_SD(x)              (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_SD_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_SD_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_RST_DPI_N_MASK     (0x8U)
#define SIM_LPAV_SYSCTRL0_DSI_RST_DPI_N_SHIFT    (3U)
/*! DSI_RST_DPI_N - DSI Reset DPI */
#define SIM_LPAV_SYSCTRL0_DSI_RST_DPI_N(x)       (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_RST_DPI_N_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_RST_DPI_N_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_RST_ESC_N_MASK     (0x10U)
#define SIM_LPAV_SYSCTRL0_DSI_RST_ESC_N_SHIFT    (4U)
/*! DSI_RST_ESC_N - DSI Reset Escape */
#define SIM_LPAV_SYSCTRL0_DSI_RST_ESC_N(x)       (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_RST_ESC_N_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_RST_ESC_N_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_RST_BYTE_N_MASK    (0x20U)
#define SIM_LPAV_SYSCTRL0_DSI_RST_BYTE_N_SHIFT   (5U)
/*! DSI_RST_BYTE_N - DSI Reset Byte */
#define SIM_LPAV_SYSCTRL0_DSI_RST_BYTE_N(x)      (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_RST_BYTE_N_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_RST_BYTE_N_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_CONT_CLK_MODE_MASK (0x100U)
#define SIM_LPAV_SYSCTRL0_DSI_CONT_CLK_MODE_SHIFT (8U)
/*! DSI_CONT_CLK_MODE - DSI Counter Control Mode */
#define SIM_LPAV_SYSCTRL0_DSI_CONT_CLK_MODE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_CONT_CLK_MODE_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_CONT_CLK_MODE_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_DPI2_EPDC_DCNANO_MUX_SEL_MASK (0x200U)
#define SIM_LPAV_SYSCTRL0_DSI_DPI2_EPDC_DCNANO_MUX_SEL_SHIFT (9U)
/*! DSI_DPI2_EPDC_DCNANO_MUX_SEL - DSI Source Control */
#define SIM_LPAV_SYSCTRL0_DSI_DPI2_EPDC_DCNANO_MUX_SEL(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_DPI2_EPDC_DCNANO_MUX_SEL_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_DPI2_EPDC_DCNANO_MUX_SEL_MASK)

#define SIM_LPAV_SYSCTRL0_DSI_ALIGN_SW_MASK      (0x1000U)
#define SIM_LPAV_SYSCTRL0_DSI_ALIGN_SW_SHIFT     (12U)
/*! DSI_ALIGN_SW - Configures the DSI-PHY to Enable High Speed Sync Token Alignment */
#define SIM_LPAV_SYSCTRL0_DSI_ALIGN_SW(x)        (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_DSI_ALIGN_SW_SHIFT)) & SIM_LPAV_SYSCTRL0_DSI_ALIGN_SW_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_STALL_MASK   (0x2000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_STALL_SHIFT  (13U)
/*! HIFI4_DSP_STALL - Stall HIFI4 DSP Execution */
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_STALL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_DSP_STALL_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_DSP_STALL_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_OCD_HALT_MASK (0x4000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_OCD_HALT_SHIFT (14U)
/*! HIFI4_DSP_OCD_HALT - Halt HiFi4 DSP Execution into OCD Halt Mode when Processor Comes Out of Reset */
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_OCD_HALT(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_DSP_OCD_HALT_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_DSP_OCD_HALT_MASK)

#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_PWRUP_MASK (0x8000U)
#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_PWRUP_SHIFT (15U)
/*! MIPI_DSI_ULPS_PWRUP - Enables MIPI-DSI to Exit ULPS00 gracefully */
#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_PWRUP(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_PWRUP_SHIFT)) & SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_PWRUP_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_RST_MASK     (0x10000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_RST_SHIFT    (16U)
/*! HIFI4_DSP_RST - Controls the HiFi4 DSP Reset */
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_RST(x)       (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_DSP_RST_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_DSP_RST_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_CLK_EN_MASK      (0x20000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_CLK_EN_SHIFT     (17U)
/*! HIFI4_CLK_EN - HiFi4 Clock Enable */
#define SIM_LPAV_SYSCTRL0_HIFI4_CLK_EN(x)        (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_CLK_EN_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_CLK_EN_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_PBCLK_EN_MASK    (0x40000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_PBCLK_EN_SHIFT   (18U)
/*! HIFI4_PBCLK_EN - HiFi4 PBCLK Clock Enable */
#define SIM_LPAV_SYSCTRL0_HIFI4_PBCLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_PBCLK_EN_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_PBCLK_EN_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_PLAT_CLK_EN_MASK (0x80000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_PLAT_CLK_EN_SHIFT (19U)
/*! HIFI4_PLAT_CLK_EN - HiFi4 Platform Clock Enable */
#define SIM_LPAV_SYSCTRL0_HIFI4_PLAT_CLK_EN(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_PLAT_CLK_EN_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_PLAT_CLK_EN_MASK)

#define SIM_LPAV_SYSCTRL0_LPAV_MODULE_DEBUG_MASK (0xF00000U)
#define SIM_LPAV_SYSCTRL0_LPAV_MODULE_DEBUG_SHIFT (20U)
/*! LPAV_MODULE_DEBUG - Low-Power Audio-Video Mode Debug */
#define SIM_LPAV_SYSCTRL0_LPAV_MODULE_DEBUG(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_LPAV_MODULE_DEBUG_SHIFT)) & SIM_LPAV_SYSCTRL0_LPAV_MODULE_DEBUG_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_RST_MASK (0x2000000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_RST_SHIFT (25U)
/*! HIFI4_DSP_DBG_RST - Reset HiFi4 DSP Debug Logic */
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_RST(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_RST_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_RST_MASK)

#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_MODE_MASK (0x4000000U)
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_MODE_SHIFT (26U)
/*! HIFI4_DSP_DBG_MODE - HiFi4 DSP in OCD Halt or Other Debug Mode */
#define SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_MODE(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_MODE_SHIFT)) & SIM_LPAV_SYSCTRL0_HIFI4_DSP_DBG_MODE_MASK)

#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_ACTIVE_MASK (0xF8000000U)
#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_ACTIVE_SHIFT (27U)
/*! MIPI_DSI_ULPS_ACTIVE - MIPI-DSI ULPS Status Bits */
#define SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_ACTIVE_SHIFT)) & SIM_LPAV_SYSCTRL0_MIPI_DSI_ULPS_ACTIVE_MASK)
/*! @} */

/*! @name LPDDR_CTRL - LPDDR Control Register */
/*! @{ */

#define SIM_LPAV_LPDDR_CTRL_LPDDR_ERROR_MASK     (0xFU)
#define SIM_LPAV_LPDDR_CTRL_LPDDR_ERROR_SHIFT    (0U)
/*! LPDDR_ERROR - LPDDR Error */
#define SIM_LPAV_LPDDR_CTRL_LPDDR_ERROR(x)       (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_LPDDR_ERROR_SHIFT)) & SIM_LPAV_LPDDR_CTRL_LPDDR_ERROR_MASK)

#define SIM_LPAV_LPDDR_CTRL_LPDDR_DONE_MASK      (0x10U)
#define SIM_LPAV_LPDDR_CTRL_LPDDR_DONE_SHIFT     (4U)
/*! LPDDR_DONE - LPDDR Done */
#define SIM_LPAV_LPDDR_CTRL_LPDDR_DONE(x)        (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_LPDDR_DONE_SHIFT)) & SIM_LPAV_LPDDR_CTRL_LPDDR_DONE_MASK)

#define SIM_LPAV_LPDDR_CTRL_ENABLE_HSHK_TIMEOUT_MASK (0x20U)
#define SIM_LPAV_LPDDR_CTRL_ENABLE_HSHK_TIMEOUT_SHIFT (5U)
/*! ENABLE_HSHK_TIMEOUT - Enables Internal Timeout Counter to be Active */
#define SIM_LPAV_LPDDR_CTRL_ENABLE_HSHK_TIMEOUT(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_ENABLE_HSHK_TIMEOUT_SHIFT)) & SIM_LPAV_LPDDR_CTRL_ENABLE_HSHK_TIMEOUT_MASK)

#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_ACK_MASK (0x40U)
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_ACK_SHIFT (6U)
/*! SOC_FREQ_CHG_ACK - LPDDR Frequency Change Acknowledge */
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_ACK(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_ACK_SHIFT)) & SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_ACK_MASK)

#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_REQ_MASK (0x80U)
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_REQ_SHIFT (7U)
/*! SOC_FREQ_CHG_REQ - LPDDR Frequency Change Request */
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_REQ(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_REQ_SHIFT)) & SIM_LPAV_LPDDR_CTRL_SOC_FREQ_CHG_REQ_MASK)

#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_COPY_MASK   (0x600U)
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_COPY_SHIFT  (9U)
/*! SOC_FREQ_COPY - SoC Frequency Copy */
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_COPY(x)     (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_SOC_FREQ_COPY_SHIFT)) & SIM_LPAV_LPDDR_CTRL_SOC_FREQ_COPY_MASK)

#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_REQ_MASK    (0x800U)
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_REQ_SHIFT   (11U)
/*! SOC_FREQ_REQ - Frequency Change Request */
#define SIM_LPAV_LPDDR_CTRL_SOC_FREQ_REQ(x)      (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_SOC_FREQ_REQ_SHIFT)) & SIM_LPAV_LPDDR_CTRL_SOC_FREQ_REQ_MASK)

#define SIM_LPAV_LPDDR_CTRL_SOC_LP_CMD_MASK      (0x1F8000U)
#define SIM_LPAV_LPDDR_CTRL_SOC_LP_CMD_SHIFT     (15U)
/*! SOC_LP_CMD - Low Power Command Code to Send Requests to LPDDR Controller for Low Power or DFS */
#define SIM_LPAV_LPDDR_CTRL_SOC_LP_CMD(x)        (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_SOC_LP_CMD_SHIFT)) & SIM_LPAV_LPDDR_CTRL_SOC_LP_CMD_MASK)

#define SIM_LPAV_LPDDR_CTRL_LPDDR_AUTO_LP_MODE_DISABLE_MASK (0x1000000U)
#define SIM_LPAV_LPDDR_CTRL_LPDDR_AUTO_LP_MODE_DISABLE_SHIFT (24U)
/*! LPDDR_AUTO_LP_MODE_DISABLE - Automatic Low Power Mode Acknowledge */
#define SIM_LPAV_LPDDR_CTRL_LPDDR_AUTO_LP_MODE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_LPDDR_AUTO_LP_MODE_DISABLE_SHIFT)) & SIM_LPAV_LPDDR_CTRL_LPDDR_AUTO_LP_MODE_DISABLE_MASK)

#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_INT_ENABLE_MASK (0x40000000U)
#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_INT_ENABLE_SHIFT (30U)
/*! Q_ALMOST_FULL_INT_ENABLE - Interrupt Enable for Queue Almost Full Threshold */
#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_INT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_INT_ENABLE_SHIFT)) & SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_INT_ENABLE_MASK)

#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_MASK   (0x80000000U)
#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_SHIFT  (31U)
/*! Q_ALMOST_FULL - Queue Almost Full Status */
#define SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL(x)     (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_SHIFT)) & SIM_LPAV_LPDDR_CTRL_Q_ALMOST_FULL_MASK)
/*! @} */

/*! @name LPDDR_CTRL2 - LPDDR Control Register */
/*! @{ */

#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_TYPE_MASK  (0x1FU)
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_TYPE_SHIFT (0U)
/*! PHY_FREQ_TYPE - Code for New System LPDDR4/4x Frequency: */
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_TYPE(x)    (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_TYPE_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_TYPE_MASK)

#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_ACK_MASK (0x40U)
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_ACK_SHIFT (6U)
/*! PHY_FREQ_CHG_ACK - PHY Frequency Change Acknowledge */
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_ACK(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_ACK_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_ACK_MASK)

#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_REQ_MASK (0x80U)
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_REQ_SHIFT (7U)
/*! PHY_FREQ_CHG_REQ - PHY Frequency Change Request */
#define SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_REQ(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_REQ_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_PHY_FREQ_CHG_REQ_MASK)

#define SIM_LPAV_LPDDR_CTRL2_DFS_INT_ENABLE_MASK (0x4000U)
#define SIM_LPAV_LPDDR_CTRL2_DFS_INT_ENABLE_SHIFT (14U)
/*! DFS_INT_ENABLE - Enable Interrupt for The DSF handshake */
#define SIM_LPAV_LPDDR_CTRL2_DFS_INT_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_DFS_INT_ENABLE_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_DFS_INT_ENABLE_MASK)

#define SIM_LPAV_LPDDR_CTRL2_DFS_INTERRUPT_MASK  (0x8000U)
#define SIM_LPAV_LPDDR_CTRL2_DFS_INTERRUPT_SHIFT (15U)
/*! DFS_INTERRUPT - DFS interrupt */
#define SIM_LPAV_LPDDR_CTRL2_DFS_INTERRUPT(x)    (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_DFS_INTERRUPT_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_DFS_INTERRUPT_MASK)

#define SIM_LPAV_LPDDR_CTRL2_LPDDR_MAX_CLKDIV_EN_MASK (0x10000U)
#define SIM_LPAV_LPDDR_CTRL2_LPDDR_MAX_CLKDIV_EN_SHIFT (16U)
/*! LPDDR_MAX_CLKDIV_EN - LPDDR Maximum Clock Divider Enable */
#define SIM_LPAV_LPDDR_CTRL2_LPDDR_MAX_CLKDIV_EN(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_LPDDR_MAX_CLKDIV_EN_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_LPDDR_MAX_CLKDIV_EN_MASK)

#define SIM_LPAV_LPDDR_CTRL2_LPDDR_EN_CLKGATE_MASK (0x20000U)
#define SIM_LPAV_LPDDR_CTRL2_LPDDR_EN_CLKGATE_SHIFT (17U)
/*! LPDDR_EN_CLKGATE - LPDDR Enable Clock Gate */
#define SIM_LPAV_LPDDR_CTRL2_LPDDR_EN_CLKGATE(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_LPDDR_CTRL2_LPDDR_EN_CLKGATE_SHIFT)) & SIM_LPAV_LPDDR_CTRL2_LPDDR_EN_CLKGATE_MASK)
/*! @} */

/*! @name DEFAULT_QOS - Default Value Register for Quality of Service (QoS) */
/*! @{ */

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AR_QOS_MASK (0xFU)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AR_QOS_SHIFT (0U)
/*! DEFAULT_ISI_Y_AR_QOS - Default Value Register for Quality of Service (QoS) AXI Read Channel Corresponding to ISI Y Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AR_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AR_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AW_QOS_MASK (0xF0U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AW_QOS_SHIFT (4U)
/*! DEFAULT_ISI_Y_AW_QOS - Default Value Register for Quality of Service (QoS) AXI Write Channel Corresponding to ISI Y Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AW_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_Y_AW_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AR_QOS_MASK (0xF00U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AR_QOS_SHIFT (8U)
/*! DEFAULT_ISI_U_AR_QOS - Default Value Register for Quality of Service (QoS) AXI Read Channel Corresponding to ISI U Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AR_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AR_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AW_QOS_MASK (0xF000U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AW_QOS_SHIFT (12U)
/*! DEFAULT_ISI_U_AW_QOS - Default Value Register for Quality of Service (QoS) AXI Write Channel Corresponding to ISI U Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AW_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_U_AW_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AR_QOS_MASK (0xF0000U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AR_QOS_SHIFT (16U)
/*! DEFAULT_ISI_V_AR_QOS - Default Value Register for Quality of Service (QoS) AXI Read Channel Corresponding to ISI V Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AR_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AR_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AW_QOS_MASK (0xF00000U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AW_QOS_SHIFT (20U)
/*! DEFAULT_ISI_V_AW_QOS - Default Value Register for Quality of Service (QoS) AXI Write Channel Corresponding to ISI V Buffer Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AW_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_ISI_V_AW_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AW_QOS_MASK (0xF000000U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AW_QOS_SHIFT (24U)
/*! DEFAULT_EPDC_AW_QOS - EPDC Quality of Service (QoS) AXI Write Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AW_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AW_QOS_MASK)

#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AR_QOS_MASK (0xF0000000U)
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AR_QOS_SHIFT (28U)
/*! DEFAULT_EPDC_AR_QOS - EPDC Default Value Register for Quality of Service (QoS) AXI Read Channel */
#define SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AR_QOS_SHIFT)) & SIM_LPAV_DEFAULT_QOS_DEFAULT_EPDC_AR_QOS_MASK)
/*! @} */

/*! @name PANIC_QOS - Panic Value Register for Quality of Service (QoS) */
/*! @{ */

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AR_QOS_MASK (0xFU)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AR_QOS_SHIFT (0U)
/*! PANIC_ISI_Y_AR_QOS - Panic Value Register for Quality of Service (QoS) AXI Read Channel Corresponding to ISI Y Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AR_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AR_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AW_QOS_MASK (0xF0U)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AW_QOS_SHIFT (4U)
/*! PANIC_ISI_Y_AW_QOS - Panic Value Register for Quality of Service (QoS) AXI Write Channel Corresponding to ISI Y Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AW_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_Y_AW_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AR_QOS_MASK (0xF00U)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AR_QOS_SHIFT (8U)
/*! PANIC_ISI_U_AR_QOS - Panic Value Register for Quality of Service (QoS) AXI Read Channel Corresponding to ISI U Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AR_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AR_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AW_QOS_MASK (0xF000U)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AW_QOS_SHIFT (12U)
/*! PANIC_ISI_U_AW_QOS - Panic Value Register for Quality of Service (QoS) AXI Write Channel Corresponding to ISI U Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AW_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_U_AW_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AR_QOS_MASK (0xF0000U)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AR_QOS_SHIFT (16U)
/*! PANIC_ISI_V_AR_QOS - Panic Value Register for Quality of Service (QoS) AXI Read Channel corresponding to ISI V Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AR_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AR_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AR_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AW_QOS_MASK (0xF00000U)
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AW_QOS_SHIFT (20U)
/*! PANIC_ISI_V_AW_QOS - Panic Value Register for Quality of Service (QoS) AXI Write Channel corresponding to ISI V Buffer Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AW_QOS(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AW_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_ISI_V_AW_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AW_QOS_MASK (0xF000000U)
#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AW_QOS_SHIFT (24U)
/*! PANIC_EPDC_AW_QOS - EPDC Panic Value Register for Quality of Service (QoS) AXI Write Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AW_QOS(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_EPDC_AW_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_EPDC_AW_QOS_MASK)

#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AR_QOS_MASK (0xF0000000U)
#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AR_QOS_SHIFT (28U)
/*! PANIC_EPDC_AR_QOS - EPDC Panic Value Register for Quality of Service (QoS) AXI Read Channel */
#define SIM_LPAV_PANIC_QOS_PANIC_EPDC_AR_QOS(x)  (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_PANIC_QOS_PANIC_EPDC_AR_QOS_SHIFT)) & SIM_LPAV_PANIC_QOS_PANIC_EPDC_AR_QOS_MASK)
/*! @} */

/*! @name SAI_MULTISYNC_ENABLE_SELECTOR - SAI 6 and 7 Transmitter/Receiver Multi-Synchronous Enable Source */
/*! @{ */

#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI6_MULTISYNC_ENABLE_SELECTOR_MASK (0x7U)
#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI6_MULTISYNC_ENABLE_SELECTOR_SHIFT (0U)
/*! SAI6_MULTISYNC_ENABLE_SELECTOR - SAI6 Multi-Sync Enable Source */
#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI6_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI6_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI6_MULTISYNC_ENABLE_SELECTOR_MASK)

#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI7_MULTISYNC_ENABLE_SELECTOR_MASK (0x700U)
#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI7_MULTISYNC_ENABLE_SELECTOR_SHIFT (8U)
/*! SAI7_MULTISYNC_ENABLE_SELECTOR - SAI7 Multi-Sync Enable Source */
#define SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI7_MULTISYNC_ENABLE_SELECTOR(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI7_MULTISYNC_ENABLE_SELECTOR_SHIFT)) & SIM_LPAV_SAI_MULTISYNC_ENABLE_SELECTOR_SAI7_MULTISYNC_ENABLE_SELECTOR_MASK)
/*! @} */

/*! @name HIFI4_GPR0 - HiFi4 DSP General Purpose Register */
/*! @{ */

#define SIM_LPAV_HIFI4_GPR0_DOUBLEEXCEPTIONERROR_MASK (0x10000U)
#define SIM_LPAV_HIFI4_GPR0_DOUBLEEXCEPTIONERROR_SHIFT (16U)
/*! DOUBLEEXCEPTIONERROR - Double Exception Error */
#define SIM_LPAV_HIFI4_GPR0_DOUBLEEXCEPTIONERROR(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_HIFI4_GPR0_DOUBLEEXCEPTIONERROR_SHIFT)) & SIM_LPAV_HIFI4_GPR0_DOUBLEEXCEPTIONERROR_MASK)

#define SIM_LPAV_HIFI4_GPR0_PFATALERROR_MASK     (0x20000U)
#define SIM_LPAV_HIFI4_GPR0_PFATALERROR_SHIFT    (17U)
/*! PFATALERROR - Fatal Error */
#define SIM_LPAV_HIFI4_GPR0_PFATALERROR(x)       (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_HIFI4_GPR0_PFATALERROR_SHIFT)) & SIM_LPAV_HIFI4_GPR0_PFATALERROR_MASK)

#define SIM_LPAV_HIFI4_GPR0_PFAULTINFOVALID_MASK (0x40000U)
#define SIM_LPAV_HIFI4_GPR0_PFAULTINFOVALID_SHIFT (18U)
/*! PFAULTINFOVALID - Fault Information Valid */
#define SIM_LPAV_HIFI4_GPR0_PFAULTINFOVALID(x)   (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_HIFI4_GPR0_PFAULTINFOVALID_SHIFT)) & SIM_LPAV_HIFI4_GPR0_PFAULTINFOVALID_MASK)
/*! @} */

/*! @name HIFI4_GPR1 - HiFi4 DSP General Purpose Register */
/*! @{ */

#define SIM_LPAV_HIFI4_GPR1_PFAULTINFO_MASK      (0xFFFFFFFFU)
#define SIM_LPAV_HIFI4_GPR1_PFAULTINFO_SHIFT     (0U)
/*! PFAULTINFO - Fault Information Register */
#define SIM_LPAV_HIFI4_GPR1_PFAULTINFO(x)        (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_HIFI4_GPR1_PFAULTINFO_SHIFT)) & SIM_LPAV_HIFI4_GPR1_PFAULTINFO_MASK)
/*! @} */

/*! @name HIFI4_GPR2 - HiFi4 DSP General Purpose Register */
/*! @{ */

#define SIM_LPAV_HIFI4_GPR2_TIE_EXPSTATE_MASK    (0xFFFFFFFFU)
#define SIM_LPAV_HIFI4_GPR2_TIE_EXPSTATE_SHIFT   (0U)
/*! TIE_EXPSTATE - GPIO32 Option TIE Output State */
#define SIM_LPAV_HIFI4_GPR2_TIE_EXPSTATE(x)      (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_HIFI4_GPR2_TIE_EXPSTATE_SHIFT)) & SIM_LPAV_HIFI4_GPR2_TIE_EXPSTATE_MASK)
/*! @} */

/*! @name AXI_CACHE_OVERRIDE - Audio-Video Domain AXI Cache Override */
/*! @{ */

#define SIM_LPAV_AXI_CACHE_OVERRIDE_AXI_CACHE_OVERRIDE_MASK (0xFFFFFFFFU)
#define SIM_LPAV_AXI_CACHE_OVERRIDE_AXI_CACHE_OVERRIDE_SHIFT (0U)
/*! AXI_CACHE_OVERRIDE - Audio-Video Domain AXI Cache Override */
#define SIM_LPAV_AXI_CACHE_OVERRIDE_AXI_CACHE_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << SIM_LPAV_AXI_CACHE_OVERRIDE_AXI_CACHE_OVERRIDE_SHIFT)) & SIM_LPAV_AXI_CACHE_OVERRIDE_AXI_CACHE_OVERRIDE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_LPAV_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_LPAV_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_LPAV_H_ */

