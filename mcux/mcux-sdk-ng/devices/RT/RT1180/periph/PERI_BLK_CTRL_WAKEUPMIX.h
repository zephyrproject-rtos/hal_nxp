/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_WAKEUPMIX.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_WAKEUPMIX
 */

#if !defined(PERI_BLK_CTRL_WAKEUPMIX_H_)
#define PERI_BLK_CTRL_WAKEUPMIX_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- BLK_CTRL_WAKEUPMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer BLK_CTRL_WAKEUPMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_WAKEUPMIX - Size of Registers Arrays */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_COUNT        5u
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_COUNT      5u

/** BLK_CTRL_WAKEUPMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t IPG_DEBUG1;                        /**< IPG DEBUG mask bit, offset: 0x4 */
  __IO uint32_t IPG_DEBUG2;                        /**< IPG DEBUG mask bit, offset: 0x8 */
  __IO uint32_t IPG_DEBUG3;                        /**< IPG DEBUG mask bit, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t SSI;                               /**< SSI master low power mode control, offset: 0x14 */
  __IO uint32_t ECAT_MISC_CFG;                     /**< EtherCAT miscellaneous configuration, offset: 0x18 */
  __IO uint32_t DEXSC_ERR;                         /**< DEXSC error response configuration, offset: 0x1C */
  __IO uint32_t USBPHY_MISC_CTRL;                  /**< USBPHY miscellaneous control, offset: 0x20 */
  __IO uint32_t NETC_PORT_MISC_CFG;                /**< NETC Port miscellaneous configuration, offset: 0x24 */
  __IO uint32_t M7_NMI_CLR;                        /**< M7 NMI interrupt clear register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t QTIMER_CTRL1;                      /**< Qtimer miscellaneous control register 1, offset: 0x30 */
  __IO uint32_t QTIMER_CTRL2;                      /**< Qtimer miscellaneous control register 2, offset: 0x34 */
  __IO uint32_t SAI2_MCLK_CTRL;                    /**< SAI2 MCLK control register, offset: 0x38 */
  __IO uint32_t SAI3_MCLK_CTRL;                    /**< SAI3 MCLK control register, offset: 0x3C */
  __IO uint32_t SAI4_MCLK_CTRL;                    /**< SAI4 MCLK control register, offset: 0x40 */
  __IO uint32_t XBAR_DIR_CTRL1;                    /**< XBAR IO direction control register, offset: 0x44 */
  __IO uint32_t XBAR_DIR_CTRL2;                    /**< XBAR IO direction control register, offset: 0x48 */
  __IO uint32_t LPIT_TRIG_SEL;                     /**< LPIT trigger input select register, offset: 0x4C */
  __IO uint32_t AXI_ATTR_CFG;                      /**< AXI bus attribute configuration register, offset: 0x50 */
  __IO uint32_t SRAMCR0;                           /**< SRAM Control Register 0, offset: 0x54 */
  __IO uint32_t SRAMCR1;                           /**< SRAM Control Register 1, offset: 0x58 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SLAVE_STOP_MODE_CFG;               /**< Slave stop mode configure register, offset: 0x60 */
       uint8_t RESERVED_4[16];
  __IO uint32_t I3C2_ASYNC_WAKEUP_CTRL;            /**< I3C2 async wakeup control register, offset: 0x74 */
  __IO uint32_t XBAR_AOI_WE;                       /**< XBAR and AOI write protect register, offset: 0x78 */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL1;              /**< XBAR trigger synchronizer control register1, offset: 0x7C */
  __IO uint32_t XBAR_TRIG_SYNC_CTRL2;              /**< XBAR trigger synchronizer control register2, offset: 0x80 */
       uint8_t RESERVED_5[124];
  __IO uint32_t NETC_LINK_CFG[BLK_CTRL_WAKEUPMIX_NETC_LINK_COUNT]; /**< NETC link configuration for port0..NETC link configuration for port4, array offset: 0x100, array step: 0x4 */
  __IO uint32_t NETC_REVMII_DLL[BLK_CTRL_WAKEUPMIX_NETC_REVMII_COUNT]; /**< NETC RevMII RGMII delay line configuration for port0..NETC RevMII RGMII delay line configuration for port4, array offset: 0x114, array step: 0x4 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SAFETY_CLK_MON_CS;                 /**< Safety clock monitor control and status register, offset: 0x130 */
  __IO uint32_t SAFETY_CLK_MON_TH;                 /**< Safety clock monitor threshold register, offset: 0x134 */
       uint8_t RESERVED_7[8];
  __IO uint32_t EMC_B1_IO_CTRL;                    /**< GPIO_EMC_B1 bank IO control, offset: 0x140 */
  __IO uint32_t EMC_B2_IO_CTRL;                    /**< GPIO_EMC_B2 bank IO control, offset: 0x144 */
  __IO uint32_t SD_B1_IO_CTRL;                     /**< GPIO_SD_B1 bank IO control, offset: 0x148 */
  __IO uint32_t SD_B2_IO_CTRL;                     /**< GPIO_SD_B2 bank IO control, offset: 0x14C */
  __IO uint32_t GPIO_B1_IO_CTRL;                   /**< GPIO_B1 bank IO control, offset: 0x150 */
  __IO uint32_t GPIO_B2_IO_CTRL;                   /**< GPIO_B2 bank IO control, offset: 0x154 */
  __IO uint32_t MISC_IO_CTRL;                      /**< Miscellaneous control register of IO, offset: 0x158 */
} BLK_CTRL_WAKEUPMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_WAKEUPMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_WAKEUPMIX_Register_Masks BLK_CTRL_WAKEUPMIX Register Masks
 * @{
 */

/*! @name IPG_DEBUG1 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_CAN2_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_CAN2_SHIFT (0U)
/*! M33_CAN2 - CAN2 debug halted mode with M7
 *  0b0..CAN2 does not enter debug halted mode with CM33
 *  0b1..CAN2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_EDMA4_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_EDMA4_SHIFT (1U)
/*! M33_EDMA4 - EDMA4 debug halted mode with M33
 *  0b0..EDMA4 does not enter debug halted mode with CM33
 *  0b1..EDMA4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO1_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO1_SHIFT (2U)
/*! M33_FLEXIO1 - FLEXIO1 debug halted mode with M33
 *  0b0..FLEXIO1 does not enter debug halted mode with CM33
 *  0b1..FLEXIO1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO2_SHIFT (3U)
/*! M33_FLEXIO2 - FLEXIO2 debug halted mode with M33
 *  0b0..FLEXIO2 does not enter debug halted mode with CM33
 *  0b1..FLEXIO2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C3_SHIFT (4U)
/*! M33_LPI2C3 - LPI2C3 debug halted mode with M33
 *  0b0..LPI2C3 does not enter debug halted mode with CM33
 *  0b1..enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C4_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C4_SHIFT (5U)
/*! M33_LPI2C4 - LPI2C4 debug halted mode with M33
 *  0b0..LPI2C4 does not enter debug halted mode with CM33
 *  0b1..LPI2C4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPIT2_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPIT2_SHIFT (6U)
/*! M33_LPIT2 - LPIT2 debug halted mode with M33
 *  0b0..LPIT2 does not enter debug halted mode with CM33
 *  0b1..LPIT2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI3_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI3_SHIFT (7U)
/*! M33_LPSPI3 - LPSPI3 debug halted mode with M33
 *  0b0..LPSPI3 does not enter debug halted mode with CM33
 *  0b1..LPSPI3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI4_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI4_SHIFT (8U)
/*! M33_LPSPI4 - LPSPI4 debug halted mode with M33
 *  0b0..LPSPI4 does not enter debug halted mode with CM33
 *  0b1..LPSPI4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPTMR2_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPTMR2_SHIFT (9U)
/*! M33_LPTMR2 - LPTMR2 debug halted mode with M33
 *  0b0..LPTMR2 does not enter debug halted mode with CM33
 *  0b1..LPTMR2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM3_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM3_SHIFT (10U)
/*! M33_TPM3 - debug halted mode with M33
 *  0b0..TPM3 does not enter debug halted mode with CM33
 *  0b1..TPM3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM4_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM4_SHIFT (11U)
/*! M33_TPM4 - TPM3 debug halted mode with M33
 *  0b0..does not enter debug halted mode with CM33
 *  0b1..enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM5_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM5_SHIFT (12U)
/*! M33_TPM5 - TPM5 debug halted mode with M33
 *  0b0..TPM5 does not enter debug halted mode with CM33
 *  0b1..TPM5 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM6_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM6_SHIFT (13U)
/*! M33_TPM6 - TPM6 debug halted mode with M33
 *  0b0..TPM6 does not enter debug halted mode with CM33
 *  0b1..TPM6 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG3_SHIFT (14U)
/*! M33_WDOG3 - WDOG3 debug halted mode with M33
 *  0b0..WDOG3 does not enter debug halted mode with CM33
 *  0b1..WDOG3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG4_SHIFT (15U)
/*! M33_WDOG4 - WDOG4 debug halted mode with M33
 *  0b0..WDOG4 does not enter debug halted mode with CM33
 *  0b1..WDOG4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M33_WDOG4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_CAN2_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_CAN2_SHIFT (16U)
/*! M7_CAN2 - CAN2 debug halted mode with M7
 *  0b0..CAN2 does not enter debug halted mode with CM7
 *  0b1..CAN2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_CAN2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_CAN2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_CAN2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_EDMA4_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_EDMA4_SHIFT (17U)
/*! M7_EDMA4 - EDMA4 debug halted mode with M7
 *  0b0..EDMA4 does not enter debug halted mode with CM7
 *  0b1..EDMA4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_EDMA4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_EDMA4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_EDMA4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO1_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO1_SHIFT (18U)
/*! M7_FLEXIO1 - FLEXIO1 debug halted mode with M7
 *  0b0..FLEXIO1 does not enter debug halted mode with CM7
 *  0b1..FLEXIO1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO2_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO2_SHIFT (19U)
/*! M7_FLEXIO2 - FLEXIO2 debug halted mode with M7
 *  0b0..FLEXIO2 does not enter debug halted mode with CM7
 *  0b1..FLEXIO2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_FLEXIO2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C3_SHIFT (20U)
/*! M7_LPI2C3 - LPI2C3 debug halted mode with M7
 *  0b0..LPI2C3 does not enter debug halted mode with CM7
 *  0b1..LPI2C3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C4_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C4_SHIFT (21U)
/*! M7_LPI2C4 - LPI2C4 debug halted mode with M7
 *  0b0..LPI2C4 does not enter debug halted mode with CM7
 *  0b1..LPI2C4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPI2C4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPIT2_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPIT2_SHIFT (22U)
/*! M7_LPIT2 - LPIT2 debug halted mode with M7
 *  0b0..LPIT2 does not enter debug halted mode with CM7
 *  0b1..LPIT2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPIT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPIT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPIT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI3_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI3_SHIFT (23U)
/*! M7_LPSPI3 - WDOG3 debug halted mode with M7
 *  0b0..WDOD3 does not enter debug halted mode with CM7
 *  0b1..WDOG3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI4_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI4_SHIFT (24U)
/*! M7_LPSPI4 - LPSPI4 debug halted mode with M7
 *  0b0..LPSPI4 does not enter debug halted mode with CM7
 *  0b1..LPSPI4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPSPI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPTMR2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPTMR2_SHIFT (25U)
/*! M7_LPTMR2 - LPTMR2 debug halted mode with M7
 *  0b0..LPTMR2 does not enter debug halted mode with CM7
 *  0b1..LPTMR2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPTMR2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPTMR2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_LPTMR2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM3_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM3_SHIFT (26U)
/*! M7_TPM3 - TPM3 debug halted mode with M7
 *  0b0..TPM3 does not enter debug halted mode with CM7
 *  0b1..TPM3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM4_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM4_SHIFT (27U)
/*! M7_TPM4 - TPM4 debug halted mode with M7
 *  0b0..TPM4 does not enter debug halted mode with CM7
 *  0b1..TPM4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM5_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM5_SHIFT (28U)
/*! M7_TPM5 - TPM5 debug halted mode with M7
 *  0b0..TPM5 does not enter debug halted mode with CM7
 *  0b1..TPM5 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM6_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM6_SHIFT (29U)
/*! M7_TPM6 - TPM6 debug halted mode with M7
 *  0b0..TPM5 does not enter debug halted mode with CM7
 *  0b1..TPM5 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_TPM6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG3_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG3_SHIFT (30U)
/*! M7_WDOG3 - WDOG3 debug halted mode with M7 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG4_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG4_SHIFT (31U)
/*! M7_WDOG4 - WDOG4 debug halted mode with M7 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG1_M7_WDOG4_MASK)
/*! @} */

/*! @name IPG_DEBUG2 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_WDOG5_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_WDOG5_SHIFT (0U)
/*! M33_WDOG5 - WDOG5 debug halted mode with M7
 *  0b0..WDOG5 does not enter debug halted mode with CM33
 *  0b1..WDOG5 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPTMR3_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPTMR3_SHIFT (1U)
/*! M33_LPTMR3 - LPTMR3 debug halted mode with M33
 *  0b0..LPTMR3 does not enter debug halted mode with CM33
 *  0b1..LPTMR3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPTMR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPTMR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPTMR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI5_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI5_SHIFT (2U)
/*! M33_LPSPI5 - LPSPI5 debug halted mode with M33
 *  0b0..LPSPI5 does not enter debug halted mode with CM33
 *  0b1..LPSPI5 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI6_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI6_SHIFT (3U)
/*! M33_LPSPI6 - LPSPI6 debug halted mode with M33
 *  0b0..LPSPI6 does not enter debug halted mode with CM33
 *  0b1..LPSPI6 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPIT3_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPIT3_SHIFT (4U)
/*! M33_LPIT3 - LPIT3 debug halted mode with M33
 *  0b0..LPIT3 does not enter debug halted mode with CM33
 *  0b1..LPIT3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C5_SHIFT (5U)
/*! M33_LPI2C5 - LPI2C5 debug halted mode with M33
 *  0b0..LPI2C5 does not enter debug halted mode with CM33
 *  0b1..LPI2C5 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C6_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C6_SHIFT (6U)
/*! M33_LPI2C6 - LPI2C6 debug halted mode with M33
 *  0b0..LPI2C6 does not enter debug halted mode with CM33
 *  0b1..LPI2C6 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_GPT2_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_GPT2_SHIFT (7U)
/*! M33_GPT2 - GPT2 debug halted mode with M33
 *  0b0..GPT2 does not enter debug halted mode with CM33
 *  0b1..GPT2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM1_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM1_SHIFT (8U)
/*! M33_FLEXPWM1 - FLEXPWM1 debug halted mode with M33
 *  0b0..FLEXPWM1 does not enter debug halted mode with CM33
 *  0b1..FLEXPWM1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM2_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM2_SHIFT (9U)
/*! M33_FLEXPWM2 - FLEXPWM2 debug halted mode with M33
 *  0b0..FLEXPWM2 does not enter debug halted mode with CM33
 *  0b1..FLEXPWM2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM3_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM3_SHIFT (10U)
/*! M33_FLEXPWM3 - FLEXPWM3 debug halted mode with M33
 *  0b0..FLEXPWM3 does not enter debug halted mode with CM33
 *  0b1..FLEXPWM3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM4_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM4_SHIFT (11U)
/*! M33_FLEXPWM4 - FLEXPWM4 debug halted mode with M33
 *  0b0..FLEXPWM4 does not enter debug halted mode with CM33
 *  0b1..FLEXPWM4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_FLEXPWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_MIC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_MIC_SHIFT (12U)
/*! M33_MIC - MIC debug halted mode with M33
 *  0b0..MIC does not enter debug halted mode with CM33
 *  0b1..MIC enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_MIC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_MIC_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_MIC_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI2_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI2_SHIFT (13U)
/*! M33_SAI2 - SAI2 debug halted mode with M33
 *  0b0..SAI2 does not enter debug halted mode with CM33
 *  0b1..SAI2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI3_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI3_SHIFT (14U)
/*! M33_SAI3 - SAI3 debug halted mode with M33
 *  0b0..SAI3 does not enter debug halted mode with CM33
 *  0b1..SAI3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI4_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI4_SHIFT (15U)
/*! M33_SAI4 - SAI4 debug halted mode with M33
 *  0b0..SAI4 does not enter debug halted mode with CM33
 *  0b1..SAI4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M33_SAI4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_WDOG5_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_WDOG5_SHIFT (16U)
/*! M7_WDOG5 - WDOG5 debug halted mode with M7
 *  0b0..WDOG5 does not enter debug halted mode with CM7
 *  0b1..WDOG5 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_WDOG5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_WDOG5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPTMR3_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPTMR3_SHIFT (17U)
/*! M7_LPTMR3 - LPTMR3 debug halted mode with M7
 *  0b0..LPTMR3 does not enter debug halted mode with CM7
 *  0b1..LPTMR3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPTMR3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPTMR3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPTMR3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI5_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI5_SHIFT (18U)
/*! M7_LPSPI5 - LPTMR3 debug halted mode with M7
 *  0b0..LPTMR3 does not enter debug halted mode with CM7
 *  0b1..enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI6_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI6_SHIFT (19U)
/*! M7_LPSPI6 - LPSPI6 debug halted mode with M7
 *  0b0..LPSPI6 does not enter debug halted mode with CM7
 *  0b1..LPSPI6 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPSPI6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPIT3_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPIT3_SHIFT (20U)
/*! M7_LPIT3 - LPIT3 debug halted mode with M7
 *  0b0..LPIT3 does not enter debug halted mode with CM7
 *  0b1..LPIT3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPIT3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPIT3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPIT3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C5_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C5_SHIFT (21U)
/*! M7_LPI2C5 - LPI2C5 debug halted mode with M7
 *  0b0..LPI2C5 does not enter debug halted mode with CM7
 *  0b1..LPI2C5 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C6_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C6_SHIFT (22U)
/*! M7_LPI2C6 - LPI2C6" debug halted mode with M7
 *  0b0..LPI2C6" does not enter debug halted mode with CM7
 *  0b1..LPI2C6" enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_LPI2C6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_GPT2_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_GPT2_SHIFT (23U)
/*! M7_GPT2 - GPT2 debug halted mode with M7
 *  0b0..GPT2 does not enter debug halted mode with CM7
 *  0b1..GPT2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_GPT2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_GPT2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_GPT2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM1_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM1_SHIFT (24U)
/*! M7_FLEXPWM1 - FLEXPWM1 debug halted mode with M7
 *  0b0..FLEXPWM1 does not enter debug halted mode with CM7
 *  0b1..FLEXPWM1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM2_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM2_SHIFT (25U)
/*! M7_FLEXPWM2 - FLEXPWM2 debug halted mode with M7
 *  0b0..FLEXPWM2 does not enter debug halted mode with CM7
 *  0b1..FLEXPWM2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM3_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM3_SHIFT (26U)
/*! M7_FLEXPWM3 - FLEXPWM3 debug halted mode with M7
 *  0b0..FLEXPWM3 does not enter debug halted mode with CM7
 *  0b1..FLEXPWM3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM4_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM4_SHIFT (27U)
/*! M7_FLEXPWM4 - FLEXPWM4 debug halted mode with M7
 *  0b0..FLEXPWM4 does not enter debug halted mode with CM7
 *  0b1..FLEXPWM4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_FLEXPWM4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_MIC_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_MIC_SHIFT (28U)
/*! M7_MIC - MIC debug halted mode with M7
 *  0b0..MIC does not enter debug halted mode with CM7
 *  0b1..MIC enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_MIC(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_MIC_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_MIC_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI2_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI2_SHIFT (29U)
/*! M7_SAI2 - SAI2 debug halted mode with M7
 *  0b0..SAI2 does not enter debug halted mode with CM7
 *  0b1..SAI2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI3_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI3_SHIFT (30U)
/*! M7_SAI3 - SAI3 debug halted mode with M7
 *  0b0..SAI3 does not enter debug halted mode with CM7
 *  0b1..SAI3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI4_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI4_SHIFT (31U)
/*! M7_SAI4 - SAI4 debug halted mode with M7
 *  0b0..SAI4 does not enter debug halted mode with CM7
 *  0b1..SAI4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG2_M7_SAI4_MASK)
/*! @} */

/*! @name IPG_DEBUG3 - IPG DEBUG mask bit */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC1_SHIFT (0U)
/*! M33_SINC1 - I3C2 debug halted mode with M33
 *  0b0..I3C2 does not enter debug halted mode with CM33
 *  0b1..I3C2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC2_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC2_SHIFT (1U)
/*! M33_SINC2 - SINC2 debug halted mode with M33
 *  0b0..SINC2 does not enter debug halted mode with CM33
 *  0b1..SINC2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC3_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC3_SHIFT (2U)
/*! M33_SINC3 - SINC3 debug halted mode with M33
 *  0b0..SINC3 does not enter debug halted mode with CM33
 *  0b1..SINC3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER1_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER1_SHIFT (3U)
/*! M33_QTIMER1 - QTIMER1 debug halted mode with M33
 *  0b0..QTIMER1 does not enter debug halted mode with CM33
 *  0b1..QTIMER1 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER2_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER2_SHIFT (4U)
/*! M33_QTIMER2 - QTIMER2 debug halted mode with M33
 *  0b0..QTIMER2 does not enter debug halted mode with CM33
 *  0b1..QTIMER2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER3_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER3_SHIFT (5U)
/*! M33_QTIMER3 - QTIMER3 debug halted mode with M33
 *  0b0..QTIMER3 does not enter debug halted mode with CM33
 *  0b1..QTIMER3 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER4_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER4_SHIFT (6U)
/*! M33_QTIMER4 - QTIMER4 debug halted mode with M33
 *  0b0..QTIMER4 does not enter debug halted mode with CM33
 *  0b1..QTIMER4 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER5_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER5_SHIFT (7U)
/*! M33_QTIMER5 - QTIMER5 debug halted mode with M33
 *  0b0..QTIMER5 does not enter debug halted mode with CM33
 *  0b1..QTIMER5 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER6_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER6_SHIFT (8U)
/*! M33_QTIMER6 - QTIMER6 debug halted mode with M33
 *  0b0..QTIMER6 does not enter debug halted mode with CM33
 *  0b1..QTIMER6 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER7_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER7_SHIFT (9U)
/*! M33_QTIMER7 - QTIMER7 debug halted mode with M33
 *  0b0..QTIMER7 does not enter debug halted mode with CM33
 *  0b1..QTIMER7 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER8_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER8_SHIFT (10U)
/*! M33_QTIMER8 - QTIMER8 debug halted mode with M33
 *  0b0..QTIMER8 does not enter debug halted mode with CM33
 *  0b1..QTIMER8 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_QTIMER8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_I3C2_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_I3C2_SHIFT (11U)
/*! M33_I3C2 - I3C2 debug halted mode with M33
 *  0b0..I3C2 does not enter debug halted mode with CM33
 *  0b1..I3C2 enters debug halted mode when CM33 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M33_I3C2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC1_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC1_SHIFT (16U)
/*! M7_SINC1 - SINC1 debug halted mode with M7
 *  0b0..SINC1 does not enter debug halted mode with CM7
 *  0b1..SINC1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC2_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC2_SHIFT (17U)
/*! M7_SINC2 - SINC2 debug halted mode with M7
 *  0b0..SINC2 does not enter debug halted mode with CM7
 *  0b1..SINC2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC3_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC3_SHIFT (18U)
/*! M7_SINC3 - SINC3 debug halted mode with M7
 *  0b0..SINC3 does not enter debug halted mode with CM7
 *  0b1..SINC3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_SINC3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER1_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER1_SHIFT (19U)
/*! M7_QTIMER1 - QTIMER1 debug halted mode with M7
 *  0b0..QTIMER1 does not enter debug halted mode with CM7
 *  0b1..QTIMER1 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER1_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER1_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER2_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER2_SHIFT (20U)
/*! M7_QTIMER2 - QTIMER2 debug halted mode with M7
 *  0b0..QTIMER2 does not enter debug halted mode with CM7
 *  0b1..QTIMER2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER2_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER3_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER3_SHIFT (21U)
/*! M7_QTIMER3 - QTIMER3 debug halted mode with M7
 *  0b0..QTIMER3 does not enter debug halted mode with CM7
 *  0b1..QTIMER3 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER3_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER3_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER4_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER4_SHIFT (22U)
/*! M7_QTIMER4 - QTIMER4 debug halted mode with M7
 *  0b0..QTIMER4 does not enter debug halted mode with CM7
 *  0b1..QTIMER4 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER4_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER4_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER5_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER5_SHIFT (23U)
/*! M7_QTIMER5 - QTIMER5 debug halted mode with M7
 *  0b0..QTIMER5 does not enter debug halted mode with CM7
 *  0b1..QTIMER5 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER5_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER5_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER6_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER6_SHIFT (24U)
/*! M7_QTIMER6 - debug halted mode with M7
 *  0b0..does not enter debug halted mode with CM7
 *  0b1..enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER6_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER6_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER7_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER7_SHIFT (25U)
/*! M7_QTIMER7 - QTIMER7 debug halted mode with M7
 *  0b0..QTIMER7 does not enter debug halted mode with CM7
 *  0b1..QTIMER7 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER7_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER7_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER8_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER8_SHIFT (26U)
/*! M7_QTIMER8 - QTIMER8 debug halted mode with M7
 *  0b0..QTIMER8 does not enter debug halted mode with CM7
 *  0b1..QTIMER8 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER8_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_QTIMER8_MASK)

#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_I3C2_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_I3C2_SHIFT (27U)
/*! M7_I3C2 - debug halted mode with M7
 *  0b0..I3C2 does not enter debug halted mode with CM7
 *  0b1..I3C2 enters debug halted mode when CM7 is debug halted
 */
#define BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_I3C2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_I3C2_SHIFT)) & BLK_CTRL_WAKEUPMIX_IPG_DEBUG3_M7_I3C2_MASK)
/*! @} */

/*! @name SSI - SSI master low power mode control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SSI_SSI_IDLE_MASK     (0x1U)
#define BLK_CTRL_WAKEUPMIX_SSI_SSI_IDLE_SHIFT    (0U)
/*! SSI_IDLE - WAKEUP Domain to M7 SSI master idle
 *  0b0..WAKEUP Domain to M7 SSI master is not idle
 *  0b1..WAKEUP Domain to M7 SSI master is idle
 */
#define BLK_CTRL_WAKEUPMIX_SSI_SSI_IDLE(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SSI_SSI_IDLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SSI_SSI_IDLE_MASK)

#define BLK_CTRL_WAKEUPMIX_SSI_BLKHOLE_MODE_B_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_SSI_BLKHOLE_MODE_B_SHIFT (1U)
/*! BLKHOLE_MODE_B - WAKEUP Domain to M7 SSI master blackhole mode
 *  0b0..WAKEUP Domain to M7 SSI master will exit blackhole mode
 *  0b1..WAKEUP Domain to M7 SSI master will enter blackhole mode
 */
#define BLK_CTRL_WAKEUPMIX_SSI_BLKHOLE_MODE_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SSI_BLKHOLE_MODE_B_SHIFT)) & BLK_CTRL_WAKEUPMIX_SSI_BLKHOLE_MODE_B_MASK)

#define BLK_CTRL_WAKEUPMIX_SSI_PAUSE_MODE_MASK   (0x4U)
#define BLK_CTRL_WAKEUPMIX_SSI_PAUSE_MODE_SHIFT  (2U)
/*! PAUSE_MODE - WAKEUP Domain to M7 SSI master pause mode
 *  0b0..WAKEUP Domain to M7 SSI master will enter pause mode
 *  0b1..WAKEUP Domain to M7 SSI master will exit pause mode
 */
#define BLK_CTRL_WAKEUPMIX_SSI_PAUSE_MODE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SSI_PAUSE_MODE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SSI_PAUSE_MODE_MASK)
/*! @} */

/*! @name ECAT_MISC_CFG - EtherCAT miscellaneous configuration */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL0_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL0_SHIFT (0U)
/*! RMII_SEL0 - RMII mode selection for EtherCAT port 0
 *  0b0..EtherCAT port0 is in MII mode
 *  0b1..EtherCAT port0 is in RMII mode
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL0_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL0_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL1_SHIFT (1U)
/*! RMII_SEL1 - RMII mode selection for EtherCAT port 1
 *  0b0..EtherCAT port1 is in MII mode
 *  0b1..EtherCAT port1 is in RMII mode
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL1_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_SEL1_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_EN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_EN_SHIFT (2U)
/*! GLB_EN - Global enable of EtherCAT
 *  0b0..EtherCAT is off
 *  0b1..EtherCAT is on
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_RST_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_RST_SHIFT (3U)
/*! GLB_RST - Global reset of EtherCAT
 *  0b0..EtherCAT is out of reset
 *  0b1..EtherCAT is held in reset
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_RST(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_RST_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_GLB_RST_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR0_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR0_SHIFT (8U)
/*! RMII_REF_CLK_DIR0 - RMII Port0 REF_CLK direction control
 *  0b0..RMII REF_CLK is input
 *  0b1..RMII REF_CLK is output driven by ECAT_CLK_ROOT/2
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR0_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR0_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR1_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR1_SHIFT (9U)
/*! RMII_REF_CLK_DIR1 - RMII Port1 REF_CLK direction control
 *  0b0..RMII REF_CLK is input
 *  0b1..RMII REF_CLK is output driven by ECAT_CLK_ROOT/2
 */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR1_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_RMII_REF_CLK_DIR1_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_SHIFT (16U)
/*! PHY_OFFSET - EtherCAT PHY_OFFSET */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_VEC_MASK (0x3E0000U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_VEC_SHIFT (17U)
/*! PHY_OFFSET_VEC - EtherCAT PHY_OFFSET_VEC */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_VEC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_VEC_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_PHY_OFFSET_VEC_MASK)

#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_EEPROM_SIZE_OPTION_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_EEPROM_SIZE_OPTION_SHIFT (22U)
/*! EEPROM_SIZE_OPTION - EtherCAT EEPROM SIZE OPTION */
#define BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_EEPROM_SIZE_OPTION(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_EEPROM_SIZE_OPTION_SHIFT)) & BLK_CTRL_WAKEUPMIX_ECAT_MISC_CFG_EEPROM_SIZE_OPTION_MASK)
/*! @} */

/*! @name DEXSC_ERR - DEXSC error response configuration */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_SHIFT (0U)
/*! EXC_ERR_RESP_EN - Exclusive error response enable
 *  0b0..OKAY response
 *  0b1..SLVError response
 */
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_DEXSC_ERR_EXC_ERR_RESP_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_SHIFT (1U)
/*! LOCK_EXC_ERR_RESP_EN - Lock bit of EXC_ERR_RESP_EN */
#define BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_DEXSC_ERR_LOCK_EXC_ERR_RESP_EN_MASK)
/*! @} */

/*! @name USBPHY_MISC_CTRL - USBPHY miscellaneous control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_IPG_CLK_ACTIVE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_IPG_CLK_ACTIVE_SHIFT (0U)
/*! USBPHY1_IPG_CLK_ACTIVE - USBPHY1 register access clock enable */
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_IPG_CLK_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_IPG_CLK_ACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_IPG_CLK_ACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_IPG_CLK_ACTIVE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_IPG_CLK_ACTIVE_SHIFT (8U)
/*! USBPHY2_IPG_CLK_ACTIVE - USBPHY2 register access clock enable */
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_IPG_CLK_ACTIVE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_IPG_CLK_ACTIVE_SHIFT)) & BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_IPG_CLK_ACTIVE_MASK)

#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_WAKEUP_IRQ_CLEAR_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_WAKEUP_IRQ_CLEAR_SHIFT (16U)
/*! USBPHY1_WAKEUP_IRQ_CLEAR - Clear USBPHY1 wakeup interrupt holding register */
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_WAKEUP_IRQ_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_WAKEUP_IRQ_CLEAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY1_WAKEUP_IRQ_CLEAR_MASK)

#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_WAKEUP_IRQ_CLEAR_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_WAKEUP_IRQ_CLEAR_SHIFT (24U)
/*! USBPHY2_WAKEUP_IRQ_CLEAR - Clear USBPHY2 wakeup interrupt holding register */
#define BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_WAKEUP_IRQ_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_WAKEUP_IRQ_CLEAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_USBPHY_MISC_CTRL_USBPHY2_WAKEUP_IRQ_CLEAR_MASK)
/*! @} */

/*! @name NETC_PORT_MISC_CFG - NETC Port miscellaneous configuration */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT0_RMII_REF_CLK_DIR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT0_RMII_REF_CLK_DIR_SHIFT (0U)
/*! PORT0_RMII_REF_CLK_DIR - Port0 RMII Reference clock direction control */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT0_RMII_REF_CLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT0_RMII_REF_CLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT0_RMII_REF_CLK_DIR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT1_RMII_REF_CLK_DIR_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT1_RMII_REF_CLK_DIR_SHIFT (1U)
/*! PORT1_RMII_REF_CLK_DIR - Port1 RMII Reference clock direction control
 *  0b0..Port1 RMII Reference clock is input
 *  0b1..Port1 RMII Reference clock is output
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT1_RMII_REF_CLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT1_RMII_REF_CLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT1_RMII_REF_CLK_DIR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT2_RMII_REF_CLK_DIR_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT2_RMII_REF_CLK_DIR_SHIFT (2U)
/*! PORT2_RMII_REF_CLK_DIR - Port2 RMII Reference clock direction control
 *  0b0..Port2 RMII Reference clock is input
 *  0b1..Port2 RMII Reference clock is output
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT2_RMII_REF_CLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT2_RMII_REF_CLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT2_RMII_REF_CLK_DIR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT3_RMII_REF_CLK_DIR_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT3_RMII_REF_CLK_DIR_SHIFT (3U)
/*! PORT3_RMII_REF_CLK_DIR - Port3 RMII Reference clock direction control
 *  0b0..Port3 RMII Reference clock is input
 *  0b1..Port3 RMII Reference clock is output
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT3_RMII_REF_CLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT3_RMII_REF_CLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT3_RMII_REF_CLK_DIR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT4_RMII_REF_CLK_DIR_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT4_RMII_REF_CLK_DIR_SHIFT (4U)
/*! PORT4_RMII_REF_CLK_DIR - Port4 RMII Reference clock direction control
 *  0b0..Port4 RMII Reference clock is input
 *  0b1..Port4 RMII Reference clock is output
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT4_RMII_REF_CLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT4_RMII_REF_CLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_PORT4_RMII_REF_CLK_DIR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_CFG_IERB_LOCK_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_CFG_IERB_LOCK_SHIFT (8U)
/*! CFG_IERB_LOCK - Default value for IERB NETCRR[LOCK] bit. Determines write accessibility of IERB registers after power-on-reset
 *  0b0..Unlocked after power-on-reset. Normal read/write access to all IERB registers
 *  0b1..Locked after power-on-reset. Write access inhibited to all IERB registers, except NETCRR
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_CFG_IERB_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_CFG_IERB_LOCK_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_CFG_IERB_LOCK_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_EXT_CLK_SEL_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_EXT_CLK_SEL_SHIFT (24U)
/*! TMR_EXT_CLK_SEL - 1588 timer external clock selection
 *  0b0..CCM tmr_1588_clk_root is selected
 *  0b1..External pin is selected
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_EXT_CLK_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_EXT_CLK_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_EXT_CLK_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG1_SEL_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG1_SEL_SHIFT (25U)
/*! TMR_TRIG1_SEL - 1588 timer trigger1 input selection
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG1_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG1_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG1_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG2_SEL_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG2_SEL_SHIFT (26U)
/*! TMR_TRIG2_SEL - 1588 timer trigger2 input selection
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG2_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG2_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_PORT_MISC_CFG_TMR_TRIG2_SEL_MASK)
/*! @} */

/*! @name M7_NMI_CLR - M7 NMI interrupt clear register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_M7_NMI_CLR_M7_NMI_CLEAR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_M7_NMI_CLR_M7_NMI_CLEAR_SHIFT (0U)
/*! M7_NMI_CLEAR - Clear CM7 NMI holding register */
#define BLK_CTRL_WAKEUPMIX_M7_NMI_CLR_M7_NMI_CLEAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_M7_NMI_CLR_M7_NMI_CLEAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_M7_NMI_CLR_M7_NMI_CLEAR_MASK)
/*! @} */

/*! @name QTIMER_CTRL1 - Qtimer miscellaneous control register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_SHIFT (0U)
/*! QTIMER1_TMR_CNTS_FREEZE - QTIMER1 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_SHIFT (1U)
/*! QTIMER1_TMR0_INPUT_SEL - QTIMER1 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_SHIFT (2U)
/*! QTIMER1_TMR1_INPUT_SEL - QTIMER1 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_SHIFT (3U)
/*! QTIMER1_TMR2_INPUT_SEL - QTIMER1 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_SHIFT (4U)
/*! QTIMER1_TMR3_INPUT_SEL - QTIMER1 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER1_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_SHIFT (8U)
/*! QTIMER2_TMR_CNTS_FREEZE - QTIMER2 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_SHIFT (9U)
/*! QTIMER2_TMR0_INPUT_SEL - QTIMER2 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_SHIFT (10U)
/*! QTIMER2_TMR1_INPUT_SEL - QTIMER2 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_SHIFT (11U)
/*! QTIMER2_TMR2_INPUT_SEL - QTIMER2 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_SHIFT (12U)
/*! QTIMER2_TMR3_INPUT_SEL - QTIMER2 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER2_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_SHIFT (16U)
/*! QTIMER3_TMR_CNTS_FREEZE - QTIMER3 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and ouput flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_SHIFT (17U)
/*! QTIMER3_TMR0_INPUT_SEL - QTIMER3 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_SHIFT (18U)
/*! QTIMER3_TMR1_INPUT_SEL - QTIMER3 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_SHIFT (19U)
/*! QTIMER3_TMR2_INPUT_SEL - QTIMER3 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_SHIFT (20U)
/*! QTIMER3_TMR3_INPUT_SEL - QTIMER3 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER3_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_SHIFT (24U)
/*! QTIMER4_TMR_CNTS_FREEZE - QTIMER4 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_SHIFT (25U)
/*! QTIMER4_TMR0_INPUT_SEL - QTIMER4 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_SHIFT (26U)
/*! QTIMER4_TMR1_INPUT_SEL - QTIMER4 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_SHIFT (27U)
/*! QTIMER4_TMR2_INPUT_SEL - QTIMER4 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_SHIFT (28U)
/*! QTIMER4_TMR3_INPUT_SEL - QTIMER4 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL1_QTIMER4_TMR3_INPUT_SEL_MASK)
/*! @} */

/*! @name QTIMER_CTRL2 - Qtimer miscellaneous control register 2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_SHIFT (0U)
/*! QTIMER5_TMR_CNTS_FREEZE - QTIMER5 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_SHIFT (1U)
/*! QTIMER5_TMR0_INPUT_SEL - QTIMER5 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_SHIFT (2U)
/*! QTIMER5_TMR1_INPUT_SEL - QTIMER5 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_SHIFT (3U)
/*! QTIMER5_TMR2_INPUT_SEL - QTIMER5 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_SHIFT (4U)
/*! QTIMER5_TMR3_INPUT_SEL - QTIMER5 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER5_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_SHIFT (8U)
/*! QTIMER6_TMR_CNTS_FREEZE - QTIMER6 timer counter freeze */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_SHIFT (9U)
/*! QTIMER6_TMR0_INPUT_SEL - QTIMER6 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_SHIFT (10U)
/*! QTIMER6_TMR1_INPUT_SEL - QTIMER6 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_SHIFT (11U)
/*! QTIMER6_TMR2_INPUT_SEL - QTIMER6 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_SHIFT (12U)
/*! QTIMER6_TMR3_INPUT_SEL - QTIMER6 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER6_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_SHIFT (16U)
/*! QTIMER7_TMR_CNTS_FREEZE - QTIMER7 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_SHIFT (17U)
/*! QTIMER7_TMR0_INPUT_SEL - QTIMER7 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_SHIFT (18U)
/*! QTIMER7_TMR1_INPUT_SEL - QTIMER7 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_SHIFT (19U)
/*! QTIMER7_TMR2_INPUT_SEL - QTIMER7 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_SHIFT (20U)
/*! QTIMER7_TMR3_INPUT_SEL - QTIMER7 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER7_TMR3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_SHIFT (24U)
/*! QTIMER8_TMR_CNTS_FREEZE - QTIMER8 timer counter freeze
 *  0b0..Timer counter works normally
 *  0b1..Reset counter and output flags
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR_CNTS_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_SHIFT (25U)
/*! QTIMER8_TMR0_INPUT_SEL - QTIMER8 TMR0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_SHIFT (26U)
/*! QTIMER8_TMR1_INPUT_SEL - QTIMER8 TMR1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_SHIFT (27U)
/*! QTIMER8_TMR2_INPUT_SEL - QTIMER8 TMR2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_SHIFT (28U)
/*! QTIMER8_TMR3_INPUT_SEL - QTIMER8 TMR3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_QTIMER_CTRL2_QTIMER8_TMR3_INPUT_SEL_MASK)
/*! @} */

/*! @name SAI2_MCLK_CTRL - SAI2 MCLK control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK3_SEL_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK3_SEL_SHIFT (0U)
/*! SAI2_MCLK3_SEL - SAI2 MCLK3 source select
 *  0b00..SPDIF_CLK_ROOT
 *  0b01..spdif_tx_clk2
 *  0b10..spdif_srclk
 *  0b11..spdif_outclock
 */
#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK3_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK3_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK3_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK_DIR_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK_DIR_SHIFT (8U)
/*! SAI2_MCLK_DIR - SAI2_MCLK IO direction control. IOMUX need select SAI2 MCLK function.
 *  0b0..SAI2_MCLK is input signal
 *  0b1..SAI2_MCLK is output signal
 */
#define BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI2_MCLK_CTRL_SAI2_MCLK_DIR_MASK)
/*! @} */

/*! @name SAI3_MCLK_CTRL - SAI3 MCLK control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK3_SEL_MASK (0x3U)
#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK3_SEL_SHIFT (0U)
/*! SAI3_MCLK3_SEL - SAI3 MCLK3 source select
 *  0b00..SPDIF_CLK_ROOT
 *  0b01..spdif_tx_clk2
 *  0b10..spdif_srclk
 *  0b11..spdif_outclock
 */
#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK3_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK3_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK3_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK_DIR_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK_DIR_SHIFT (8U)
/*! SAI3_MCLK_DIR - SAI3_MCLK IO direction control. IOMUX need select SAI3 MCLK function.
 *  0b0..SAI3_MCLK is input signal
 *  0b1..SAI3_MCLK is output signal
 */
#define BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI3_MCLK_CTRL_SAI3_MCLK_DIR_MASK)
/*! @} */

/*! @name SAI4_MCLK_CTRL - SAI4 MCLK control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK1_SEL_MASK (0x7U)
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK1_SEL_SHIFT (0U)
/*! SAI4_MCLK1_SEL - SAI4 MCLK1 source select
 *  0b000..SAI4_CLK_ROOT
 *  0b001..SAI2_CLK_ROOT
 *  0b011..SAI3_CLK_ROOT
 *  0b100..SAI4 MCLK IO pin
 *  0b101..SAI2 MCLK IO pin
 *  0b110..SAI3 MCLK IO pin
 *  0b111..Reserved
 */
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK1_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK1_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK1_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK2_SEL_MASK (0x38U)
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK2_SEL_SHIFT (3U)
/*! SAI4_MCLK2_SEL - SAI4 MCLK2 source select
 *  0b000..SAI4_CLK_ROOT
 *  0b001..SAI2_CLK_ROOT
 *  0b011..SAI3_CLK_ROOT
 *  0b100..SAI4 MCLK IO pin
 *  0b101..SAI2 MCLK IO pin
 *  0b110..SAI3 MCLK IO pin
 *  0b111..Reserved
 */
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK2_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK2_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK2_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK3_SEL_MASK (0xC0U)
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK3_SEL_SHIFT (6U)
/*! SAI4_MCLK3_SEL - SAI4 MCLK3 source select
 *  0b00..SPDIF_CLK_ROOT
 *  0b01..spdif_tx_clk2
 *  0b10..spdif_srclk
 *  0b11..spdif_outclock
 */
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK3_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK3_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK3_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK_DIR_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK_DIR_SHIFT (8U)
/*! SAI4_MCLK_DIR - SAI4_MCLK IO direction control. IOMUX need select SAI4 MCLK function. */
#define BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK_DIR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK_DIR_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAI4_MCLK_CTRL_SAI4_MCLK_DIR_MASK)
/*! @} */

/*! @name XBAR_DIR_CTRL1 - XBAR IO direction control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_SHIFT (4U)
/*! IOMUXC_XBAR_DIR_SEL_4 - IOMUXC XBAR_INOUT4 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_4_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_SHIFT (5U)
/*! IOMUXC_XBAR_DIR_SEL_5 - IOMUXC XBAR_INOUT5 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_5_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_MASK (0x40U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_SHIFT (6U)
/*! IOMUXC_XBAR_DIR_SEL_6 - IOMUXC XBAR_INOUT6 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_6_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_MASK (0x80U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_SHIFT (7U)
/*! IOMUXC_XBAR_DIR_SEL_7 - IOMUXC XBAR_INOUT7 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_7_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_SHIFT (8U)
/*! IOMUXC_XBAR_DIR_SEL_8 - IOMUXC XBAR_INOUT8 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_8_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_SHIFT (9U)
/*! IOMUXC_XBAR_DIR_SEL_9 - IOMUXC XBAR_INOUT9 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_9_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_SHIFT (10U)
/*! IOMUXC_XBAR_DIR_SEL_10 - IOMUXC XBAR_INOUT10 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_10_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_SHIFT (11U)
/*! IOMUXC_XBAR_DIR_SEL_11 - IOMUXC XBAR_INOUT11 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_11_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_SHIFT (12U)
/*! IOMUXC_XBAR_DIR_SEL_12 - IOMUXC XBAR_INOUT12 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_12_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_SHIFT (13U)
/*! IOMUXC_XBAR_DIR_SEL_13 - IOMUXC XBAR_INOUT13 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_13_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_SHIFT (14U)
/*! IOMUXC_XBAR_DIR_SEL_14 - IOMUXC XBAR_INOUT14 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_14_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_SHIFT (15U)
/*! IOMUXC_XBAR_DIR_SEL_15 - IOMUXC XBAR_INOUT15 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_15_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_SHIFT (16U)
/*! IOMUXC_XBAR_DIR_SEL_16 - IOMUXC XBAR_INOUT16 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_16_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_SHIFT (17U)
/*! IOMUXC_XBAR_DIR_SEL_17 - IOMUXC XBAR_INOUT17 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_17_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_SHIFT (18U)
/*! IOMUXC_XBAR_DIR_SEL_18 - IOMUXC XBAR_INOUT18 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_18_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_SHIFT (19U)
/*! IOMUXC_XBAR_DIR_SEL_19 - IOMUXC XBAR_INOUT19 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_19_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_SHIFT (20U)
/*! IOMUXC_XBAR_DIR_SEL_20 - IOMUXC XBAR_INOUT20 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_20_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_MASK (0x200000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_SHIFT (21U)
/*! IOMUXC_XBAR_DIR_SEL_21 - IOMUXC XBAR_INOUT21 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_21_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_MASK (0x400000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_SHIFT (22U)
/*! IOMUXC_XBAR_DIR_SEL_22 - IOMUXC XBAR_INOUT22 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_22_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_MASK (0x800000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_SHIFT (23U)
/*! IOMUXC_XBAR_DIR_SEL_23 - IOMUXC XBAR_INOUT23 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_23_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_SHIFT (24U)
/*! IOMUXC_XBAR_DIR_SEL_24 - IOMUXC XBAR_INOUT24 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_24_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_MASK (0x2000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_SHIFT (25U)
/*! IOMUXC_XBAR_DIR_SEL_25 - IOMUXC XBAR_INOUT25 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_25_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_MASK (0x4000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_SHIFT (26U)
/*! IOMUXC_XBAR_DIR_SEL_26 - IOMUXC XBAR_INOUT26 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_26_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_MASK (0x8000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_SHIFT (27U)
/*! IOMUXC_XBAR_DIR_SEL_27 - IOMUXC XBAR_INOUT27 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_27_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_MASK (0x10000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_SHIFT (28U)
/*! IOMUXC_XBAR_DIR_SEL_28 - IOMUXC XBAR_INOUT28 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_28_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_MASK (0x20000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_SHIFT (29U)
/*! IOMUXC_XBAR_DIR_SEL_29 - IOMUXC XBAR_INOUT29 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_29_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_MASK (0x40000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_SHIFT (30U)
/*! IOMUXC_XBAR_DIR_SEL_30 - IOMUXC XBAR_INOUT30 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_30_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_SHIFT (31U)
/*! IOMUXC_XBAR_DIR_SEL_31 - IOMUXC XBAR_INOUT31 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL1_IOMUXC_XBAR_DIR_SEL_31_MASK)
/*! @} */

/*! @name XBAR_DIR_CTRL2 - XBAR IO direction control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_SHIFT (0U)
/*! IOMUXC_XBAR_DIR_SEL_32 - IOMUXC XBAR_INOUT32 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_32_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_SHIFT (1U)
/*! IOMUXC_XBAR_DIR_SEL_33 - IOMUXC XBAR_INOUT33 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_33_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_SHIFT (2U)
/*! IOMUXC_XBAR_DIR_SEL_34 - IOMUXC XBAR_INOUT34 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_34_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_SHIFT (3U)
/*! IOMUXC_XBAR_DIR_SEL_35 - IOMUXC XBAR_INOUT35 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_35_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_SHIFT (4U)
/*! IOMUXC_XBAR_DIR_SEL_36 - IOMUXC XBAR_INOUT36 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_36_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_SHIFT (5U)
/*! IOMUXC_XBAR_DIR_SEL_37 - IOMUXC XBAR_INOUT37 function direction select
 *  0b0..XBAR_INOUT as input
 *  0b1..XBAR_INOUT as output
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_DIR_CTRL2_IOMUXC_XBAR_DIR_SEL_37_MASK)
/*! @} */

/*! @name LPIT_TRIG_SEL - LPIT trigger input select register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_SHIFT (0U)
/*! LPIT1_TRIG0_INPUT_SEL - LPIT1 TRIG0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_SHIFT (1U)
/*! LPIT1_TRIG1_INPUT_SEL - LPIT1 TRIG1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_SHIFT (2U)
/*! LPIT1_TRIG2_INPUT_SEL - LPIT1 TRIG2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_SHIFT (3U)
/*! LPIT1_TRIG3_INPUT_SEL - LPIT1 TRIG3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT1_TRIG3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_SHIFT (8U)
/*! LPIT2_TRIG0_INPUT_SEL - LPIT2 TRIG0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_MASK (0x200U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_SHIFT (9U)
/*! LPIT2_TRIG1_INPUT_SEL - LPIT2 TRIG1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_SHIFT (10U)
/*! LPIT2_TRIG2_INPUT_SEL - LPIT2 TRIG2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_SHIFT (11U)
/*! LPIT2_TRIG3_INPUT_SEL - LPIT2 TRIG3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT2_TRIG3_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_SHIFT (16U)
/*! LPIT3_TRIG0_INPUT_SEL - LPIT3 TRIG0 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG0_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_SHIFT (17U)
/*! LPIT3_TRIG1_INPUT_SEL - LPIT3 TRIG1 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG1_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_MASK (0x40000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_SHIFT (18U)
/*! LPIT3_TRIG2_INPUT_SEL - LPIT3 TRIG2 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG2_INPUT_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_MASK (0x80000U)
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_SHIFT (19U)
/*! LPIT3_TRIG3_INPUT_SEL - LPIT3 TRIG3 input select
 *  0b0..Input from IOMUX
 *  0b1..Input from XBAR
 */
#define BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_LPIT_TRIG_SEL_LPIT3_TRIG3_INPUT_SEL_MASK)
/*! @} */

/*! @name AXI_ATTR_CFG - AXI bus attribute configuration register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT (0U)
/*! ARCACHE_USDHC1 - uSDHC1 block cacheable attribute value of AXI read transactions
 *  0b0..Cacheable attribute is off for read transactions
 *  0b1..Cacheable attribute is on for read transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT (1U)
/*! AWCACHE_USDHC1 - uSDHC1 block cacheable attribute value of AXI write transactions
 *  0b0..Cacheable attribute is off for write transactions
 *  0b1..Cacheable attribute is on for write transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC1_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT (2U)
/*! ARCACHE_USDHC2 - uSDHC2 block cacheable attribute value of AXI read transactions
 *  0b0..Cacheable attribute is off for read transactions
 *  0b1..Cacheable attribute is on for read transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT (3U)
/*! AWCACHE_USDHC2 - uSDHC2 block cacheable attribute value of AXI write transactions
 *  0b0..Cacheable attribute is off for write transactions
 *  0b1..Cacheable attribute is on for write transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USDHC2_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USB_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USB_SHIFT (4U)
/*! ARCACHE_USB - USB block cacheable attribute value of AXI read transactions
 *  0b0..Cacheable attribute is off for read transactions
 *  0b1..Cacheable attribute is on for read transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USB(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USB_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_ARCACHE_USB_MASK)

#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USB_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USB_SHIFT (5U)
/*! AWCACHE_USB - USB block cacheable attribute value of AXI write transactions
 *  0b0..Cacheable attribute is off for write transactions
 *  0b1..Cacheable attribute is on for write transactions
 */
#define BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USB(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USB_SHIFT)) & BLK_CTRL_WAKEUPMIX_AXI_ATTR_CFG_AWCACHE_USB_MASK)
/*! @} */

/*! @name SRAMCR0 - SRAM Control Register 0 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO_MASK      (0xFFU)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO_SHIFT     (0U)
/*! BTO - AHB Bus Timeout Wait Cycle */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_BTO_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN_MASK    (0x100U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN_SHIFT   (8U)
/*! BTOEN - AHB Bus Timeout Enable
 *  0b0..AHB bus timeout counter is not enabled.
 *  0b1..AHB bus timeout counter is enabled.
 */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_BTOEN_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_PS_MASK       (0x200U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_PS_SHIFT      (9U)
/*! PS - Port Size
 *  0b0..8bit
 *  0b1..16bit
 */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_PS(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_PS_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_PS_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AM_MASK       (0x400U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AM_SHIFT      (10U)
/*! AM - Address Mode
 *  0b0..Address/Data MUX mode (ADMUX)
 *  0b1..Address/Data non-MUX mode (Non-ADMUX)
 */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AM(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_AM_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_AM_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP_MASK     (0x800U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP_SHIFT    (11U)
/*! ADVP - ADV# polarity
 *  0b0..ADV# is active low.
 *  0b1..ADV# is active high.
 */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_ADVP_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CES_MASK      (0xF000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CES_SHIFT     (12U)
/*! CES - CE setup time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CES(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_CES_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_CES_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH_MASK      (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH_SHIFT     (16U)
/*! CEH - CE hold time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_CEH_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AS_MASK       (0xF00000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AS_SHIFT      (20U)
/*! AS - Address setup time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AS(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_AS_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_AS_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AH_MASK       (0xF000000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AH_SHIFT      (24U)
/*! AH - Address hold time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_AH(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_AH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_AH_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR0_TA_MASK       (0xF0000000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_TA_SHIFT      (28U)
/*! TA - Turnaround time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR0_TA(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR0_TA_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR0_TA_MASK)
/*! @} */

/*! @name SRAMCR1 - SRAM Control Register 1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL_MASK      (0x3FU)
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL_SHIFT     (0U)
/*! WEL - WE low time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR1_WEL_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH_MASK      (0x3C0U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH_SHIFT     (6U)
/*! WEH - WE high time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR1_WEH_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REL_MASK      (0xFC00U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REL_SHIFT     (10U)
/*! REL - RE low time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REL(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR1_REL_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR1_REL_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REH_MASK      (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REH_SHIFT     (16U)
/*! REH - RE high time */
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_REH(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR1_REH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR1_REH_MASK)

#define BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE_MASK      (0x300000U)
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE_SHIFT     (20U)
/*! PRE - Prescaler timer
 *  0b00..Time granularity is 1 clock cycle.
 *  0b01..Time granularity is 2 clock cycles.
 *  0b10..Time granularity is 3 clock cycles.
 *  0b11..Time granularity is 4 clock cycles.
 */
#define BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SRAMCR1_PRE_MASK)
/*! @} */

/*! @name SLAVE_STOP_MODE_CFG - Slave stop mode configure register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC1_IPG_STOP_MODE_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC1_IPG_STOP_MODE_SHIFT (4U)
/*! ADC1_IPG_STOP_MODE - ADC1 stop mode selection.
 *  0b0..This module is functional in Stop Mode
 *  0b1..This module is not functional in Stop Mode
 */
#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC1_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC1_IPG_STOP_MODE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC1_IPG_STOP_MODE_MASK)

#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC2_IPG_STOP_MODE_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC2_IPG_STOP_MODE_SHIFT (5U)
/*! ADC2_IPG_STOP_MODE - ADC2 stop mode selection.
 *  0b0..This module is functional in Stop Mode
 *  0b1..This module is not functional in Stop Mode
 */
#define BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC2_IPG_STOP_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC2_IPG_STOP_MODE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SLAVE_STOP_MODE_CFG_ADC2_IPG_STOP_MODE_MASK)
/*! @} */

/*! @name I3C2_ASYNC_WAKEUP_CTRL - I3C2 async wakeup control register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_CLR_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_CLR_SHIFT (0U)
/*! IRQ_CLR - Async wakeup interrupt clear */
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_CLR_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_CLR_MASK)

#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_STATUS_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_STATUS_SHIFT (16U)
/*! IRQ_STATUS - Async wakeup interrupt status
 *  0b0..Interrupt not asserted
 *  0b1..Interrupt asserted
 */
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_STATUS_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_STATUS_MASK)

#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_EN_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_EN_SHIFT (31U)
/*! IRQ_EN - Master mode async wakeup interrupt enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_I3C2_ASYNC_WAKEUP_CTRL_IRQ_EN_MASK)
/*! @} */

/*! @name XBAR_AOI_WE - XBAR and AOI write protect register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_MASK   (0x1U)
#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_SHIFT  (0U)
/*! WE - Write Enable to XBAR and AOI
 *  0b0..Write is disabled
 *  0b1..Write is enabled
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_AOI_WE_WE_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL1 - XBAR trigger synchronizer control register1 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_MASK (0xFFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_SHIFT (0U)
/*! POL_SEL - Trigger out polarity select
 *  0b00000000..Same as trigger in
 *  0b00000001..Invert trigger in
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_POL_SEL_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_MASK (0xFF00U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_SHIFT (8U)
/*! ASYNC_EN - Asynchronous trigger in enable
 *  0b00000000..Trigger in is synchronous
 *  0b00000001..Trigger in is asynchronous
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_ASYNC_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_SYNC_ENABLE_MASK (0xFF0000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_SYNC_ENABLE_SHIFT (16U)
/*! SYNC_ENABLE - Trigger out synchronizer enable
 *  0b00000000..Channel is disabled
 *  0b00000001..Channel is enabled
 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_SYNC_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_SYNC_ENABLE_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL1_SYNC_ENABLE_MASK)
/*! @} */

/*! @name XBAR_TRIG_SYNC_CTRL2 - XBAR trigger synchronizer control register2 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH0_MASK (0xFU)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH0_SHIFT (0U)
/*! PULSE_WIDTH0 - Pulse width control register of channel0 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH0_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH0_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH1_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH1_SHIFT (4U)
/*! PULSE_WIDTH1 - Pulse width control register of channel1 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH1_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH1_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH2_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH2_SHIFT (8U)
/*! PULSE_WIDTH2 - Pulse width control register of channel2 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH2_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH2_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH3_MASK (0xF000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH3_SHIFT (12U)
/*! PULSE_WIDTH3 - Pulse width control register of channel3 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH3_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH3_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH4_MASK (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH4_SHIFT (16U)
/*! PULSE_WIDTH4 - Pulse width control register of channel4 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH4_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH4_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH5_MASK (0xF00000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH5_SHIFT (20U)
/*! PULSE_WIDTH5 - Pulse width control register of channel5 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH5_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH5_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH6_MASK (0xF000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH6_SHIFT (24U)
/*! PULSE_WIDTH6 - Pulse width control register of channel6 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH6(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH6_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH6_MASK)

#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH7_MASK (0xF0000000U)
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH7_SHIFT (28U)
/*! PULSE_WIDTH7 - Pulse width control register of channel7 */
#define BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH7(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH7_SHIFT)) & BLK_CTRL_WAKEUPMIX_XBAR_TRIG_SYNC_CTRL2_PULSE_WIDTH7_MASK)
/*! @} */

/*! @name NETC_LINK_CFG - NETC link configuration for port0..NETC link configuration for port4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_MII_PROT_MASK (0xFU)
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_MII_PROT_SHIFT (0U)
/*! MII_PROT - MII protocol selection
 *  0b0000..MII
 *  0b0001..RMII
 *  0b0010..RGMII
 *  0b0100-0b1111..Reserved
 */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_MII_PROT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_MII_PROT_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_MII_PROT_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_IO_VAR_MASK (0xF0000U)
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_IO_VAR_SHIFT (16U)
/*! IO_VAR - IO variant selection
 *  0b0000..None
 *  0b0001-0b1110..Reserved
 */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_IO_VAR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_IO_VAR_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_IO_VAR_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_RATE_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_RATE_SHIFT (24U)
/*! REVMII_RATE - When REVMII=1 and MII_PROT=MII, this bit configures RevMII rates, otherwise this field has no meaning.
 *  0b0..MII interface is operating at 100Mbps
 *  0b1..MII interface is operating at 10Mbps
 */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_RATE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_RATE_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_RATE_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_MASK (0x80000000U)
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_SHIFT (31U)
/*! REVMII - RevMII selection
 *  0b0..RevMII not selected
 *  0b1..RevMII selected
 */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_REVMII_MASK)
/*! @} */

/* The count of BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG */
#define BLK_CTRL_WAKEUPMIX_NETC_LINK_CFG_COUNT   (5U)

/*! @name NETC_REVMII_DLL - NETC RevMII RGMII delay line configuration for port0..NETC RevMII RGMII delay line configuration for port4 */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_DLY_TARGET_MASK (0xFU)
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_DLY_TARGET_SHIFT (0U)
/*! DLY_TARGET - Delay target of slave delay line */
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_DLY_TARGET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_DLY_TARGET_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_DLY_TARGET_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_REF_LOCK_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_REF_LOCK_SHIFT (16U)
/*! REF_LOCK - Reference delay line lock flag
 *  0b0..Reference delay line is not locked
 *  0b1..Reference delay line is locked
 */
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_REF_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_REF_LOCK_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_REF_LOCK_MASK)

#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_SLV_LOCK_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_SLV_LOCK_SHIFT (17U)
/*! SLV_LOCK - Slave delay line lock flag
 *  0b0..Slave delay line is not locked
 *  0b1..Slave delay line is locked
 */
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_SLV_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_SLV_LOCK_SHIFT)) & BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_SLV_LOCK_MASK)
/*! @} */

/* The count of BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL */
#define BLK_CTRL_WAKEUPMIX_NETC_REVMII_DLL_COUNT (5U)

/*! @name SAFETY_CLK_MON_CS - Safety clock monitor control and status register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_MON_EN_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_MON_EN_SHIFT (0U)
/*! MON_EN - Monitor enable bit
 *  0b0..The monitor is off
 *  0b1..The monitor is on
 */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_MON_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_MON_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_MON_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_IRQ_EN_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_IRQ_EN_SHIFT (1U)
/*! IRQ_EN - Interrupt enable
 *  0b0..Clock failure will not assert interrupt
 *  0b1..Clock failure will assert interrupt
 */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_IRQ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_IRQ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_FAST_RST_EN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_FAST_RST_EN_SHIFT (2U)
/*! FAST_RST_EN - Reset out enable
 *  0b0..Clock failure will not assert EWM_OUT
 *  0b1..Clock failure will assert EWM_OUT_b immediately regardless EWM state
 */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_FAST_RST_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_FAST_RST_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_FAST_RST_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_CLR_MASK (0x100U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_CLR_SHIFT (8U)
/*! STAT_CLR - Status clear
 *  0b0..No effect to clock failure status bit
 *  0b1..Clear clock failure status bit
 */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_CLR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_CLR_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_CLR_MASK)

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_MASK (0x1000000U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_SHIFT (24U)
/*! STAT - XBAR_OUT220 clock failure status
 *  0b0..No failure detected by the monitor
 *  0b1..Clock failure has been detected by the monitor
 */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_CS_STAT_MASK)
/*! @} */

/*! @name SAFETY_CLK_MON_TH - Safety clock monitor threshold register */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_LOW_MASK (0xFFFFU)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_LOW_SHIFT (0U)
/*! TH_LOW - Threshold low value */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_LOW(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_LOW_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_LOW_MASK)

#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_HIGH_MASK (0xFFFF0000U)
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_HIGH_SHIFT (16U)
/*! TH_HIGH - Threshold high value */
#define BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_HIGH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_HIGH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SAFETY_CLK_MON_TH_TH_HIGH_MASK)
/*! @} */

/*! @name EMC_B1_IO_CTRL - GPIO_EMC_B1 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FREEZE_SHIFT (0U)
/*! GPIO_EMC1_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPTQ_SHIFT (1U)
/*! GPIO_EMC1_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPEN_SHIFT (2U)
/*! GPIO_EMC1_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_EMC1_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCP_SHIFT (4U)
/*! GPIO_EMC1_RASRCP - GPIO_EMC_B1 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCN_SHIFT (8U)
/*! GPIO_EMC1_RASRCN - GPIO_EMC_B1 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SELECT_NASRC_SHIFT (12U)
/*! GPIO_EMC1_SELECT_NASRC - GPIO_EMC1_NASRC selection */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_EMC1_REFGEN_SLEEP - GPIO_EMC_B1 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_EMC1_SUPLYDET_LATCH - GPIO_EMC_B1 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_SHIFT (15U)
/*! GPIO_EMC1_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPOK_SHIFT (20U)
/*! GPIO_EMC1_COMPOK - GPIO_EMC_B1 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_NASRC_SHIFT (21U)
/*! GPIO_EMC1_NASRC - GPIO_EMC_B1 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B1_IO_CTRL_GPIO_EMC1_NASRC_MASK)
/*! @} */

/*! @name EMC_B2_IO_CTRL - GPIO_EMC_B2 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FREEZE_SHIFT (0U)
/*! GPIO_EMC2_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPTQ_SHIFT (1U)
/*! GPIO_EMC2_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPEN_SHIFT (2U)
/*! GPIO_EMC2_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_EMC2_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCP_SHIFT (4U)
/*! GPIO_EMC2_RASRCP - GPIO_EMC_B2 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCN_SHIFT (8U)
/*! GPIO_EMC2_RASRCN - GPIO_EMC_B2 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SELECT_NASRC_SHIFT (12U)
/*! GPIO_EMC2_SELECT_NASRC - GPIO_EMC2_NASRC selection
 *  0b0..Show the 4-bit PMOS compensation codes in GPIO_EMC2_NASRC field
 *  0b1..Show the 4-bit NMOS compensation codes in GPIO_EMC2_NASRC field
 */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_EMC2_REFGEN_SLEEP - GPIO_EMC_B2 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_EMC2_SUPLYDET_LATCH - GPIO_EMC_B2 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_SHIFT (15U)
/*! GPIO_EMC2_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPOK_SHIFT (20U)
/*! GPIO_EMC2_COMPOK - GPIO_EMC_B2 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_NASRC_SHIFT (21U)
/*! GPIO_EMC2_NASRC - GPIO_EMC_B2 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_EMC_B2_IO_CTRL_GPIO_EMC2_NASRC_MASK)
/*! @} */

/*! @name SD_B1_IO_CTRL - GPIO_SD_B1 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FREEZE_SHIFT (0U)
/*! GPIO_SD1_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPTQ_SHIFT (1U)
/*! GPIO_SD1_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPEN_SHIFT (2U)
/*! GPIO_SD1_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_SD1_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCP_SHIFT (4U)
/*! GPIO_SD1_RASRCP - GPIO_SD_B1 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCN_SHIFT (8U)
/*! GPIO_SD1_RASRCN - GPIO_SD_B1 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SELECT_NASRC_SHIFT (12U)
/*! GPIO_SD1_SELECT_NASRC - GPIO_SD1_NASRC selection */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_SD1_REFGEN_SLEEP - GPIO_SD_B1 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_SD1_SUPLYDET_LATCH - GPIO_SD_B1 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_SHIFT (15U)
/*! GPIO_SD1_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPOK_SHIFT (20U)
/*! GPIO_SD1_COMPOK - GPIO_SD_B1 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_NASRC_SHIFT (21U)
/*! GPIO_SD1_NASRC - GPIO_SD_B1 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B1_IO_CTRL_GPIO_SD1_NASRC_MASK)
/*! @} */

/*! @name SD_B2_IO_CTRL - GPIO_SD_B2 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FREEZE_SHIFT (0U)
/*! GPIO_SD2_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPTQ_SHIFT (1U)
/*! GPIO_SD2_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPEN_SHIFT (2U)
/*! GPIO_SD2_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_SD2_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCP_SHIFT (4U)
/*! GPIO_SD2_RASRCP - GPIO_SD_B2 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCN_SHIFT (8U)
/*! GPIO_SD2_RASRCN - GPIO_SD_B2 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SELECT_NASRC_SHIFT (12U)
/*! GPIO_SD2_SELECT_NASRC - GPIO_SD2_NASRC selection */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_SD2_REFGEN_SLEEP - GPIO_SD_B2 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_SD2_SUPLYDET_LATCH - GPIO_SD_B2 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_SHIFT (15U)
/*! GPIO_SD2_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPOK_SHIFT (20U)
/*! GPIO_SD2_COMPOK - GPIO_SD_B2 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_NASRC_SHIFT (21U)
/*! GPIO_SD2_NASRC - GPIO_SD_B2 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_SD_B2_IO_CTRL_GPIO_SD2_NASRC_MASK)
/*! @} */

/*! @name GPIO_B1_IO_CTRL - GPIO_B1 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FREEZE_SHIFT (0U)
/*! GPIO_B1_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPTQ_SHIFT (1U)
/*! GPIO_B1_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPEN_SHIFT (2U)
/*! GPIO_B1_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_B1_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCP_SHIFT (4U)
/*! GPIO_B1_RASRCP - GPIO_B1 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCN_SHIFT (8U)
/*! GPIO_B1_RASRCN - GPIO_B1 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SELECT_NASRC_SHIFT (12U)
/*! GPIO_B1_SELECT_NASRC - GPIO_B1_NASRC selection
 *  0b0..Show the 4-bit PMOS compensation codes in GPIO_B1_NASRC field
 *  0b1..Show the 4-bit NMOS compensation codes in GPIO_B1_NASRC field
 */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_B1_REFGEN_SLEEP - GPIO_B1 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_B1_SUPLYDET_LATCH - GPIO_B1 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_SHIFT (15U)
/*! GPIO_B1_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPOK_SHIFT (20U)
/*! GPIO_B1_COMPOK - GPIO_B1 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_NASRC_SHIFT (21U)
/*! GPIO_B1_NASRC - GPIO_B1 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B1_IO_CTRL_GPIO_B1_NASRC_MASK)
/*! @} */

/*! @name GPIO_B2_IO_CTRL - GPIO_B2 bank IO control */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FREEZE_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FREEZE_SHIFT (0U)
/*! GPIO_B2_FREEZE - Compensation code freeze */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FREEZE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FREEZE_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FREEZE_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPTQ_MASK (0x2U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPTQ_SHIFT (1U)
/*! GPIO_B2_COMPTQ - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPTQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPTQ_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPTQ_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPEN_MASK (0x4U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPEN_SHIFT (2U)
/*! GPIO_B2_COMPEN - COMPEN and COMPTQ control the operating modes of the compensation cell */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPEN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPEN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPEN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_EN_MASK (0x8U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_EN_SHIFT (3U)
/*! GPIO_B2_FASTFRZ_EN - Compensation code fast freeze enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_EN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_EN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCP_MASK (0xF0U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCP_SHIFT (4U)
/*! GPIO_B2_RASRCP - GPIO_B2 IO bank's 4-bit PMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCP_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCP_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCN_MASK (0xF00U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCN_SHIFT (8U)
/*! GPIO_B2_RASRCN - GPIO_B2 IO bank's 4-bit NMOS compensation codes from core */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCN_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_RASRCN_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SELECT_NASRC_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SELECT_NASRC_SHIFT (12U)
/*! GPIO_B2_SELECT_NASRC - GPIO_B2_NASRC selection */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SELECT_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SELECT_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SELECT_NASRC_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_REFGEN_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_REFGEN_SLEEP_SHIFT (13U)
/*! GPIO_B2_REFGEN_SLEEP - GPIO_B2 IO bank reference voltage generator cell sleep enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_REFGEN_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_REFGEN_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_REFGEN_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SUPLYDET_LATCH_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SUPLYDET_LATCH_SHIFT (14U)
/*! GPIO_B2_SUPLYDET_LATCH - GPIO_B2 IO bank power supply mode latch enable */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SUPLYDET_LATCH(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SUPLYDET_LATCH_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_SUPLYDET_LATCH_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_SHIFT (15U)
/*! GPIO_B2_FASTFRZ - Compensation code fast-freeze */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_FASTFRZ_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPOK_MASK (0x100000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPOK_SHIFT (20U)
/*! GPIO_B2_COMPOK - GPIO_B2 IO bank compensation OK flag */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPOK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPOK_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_COMPOK_MASK)

#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_NASRC_MASK (0x1E00000U)
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_NASRC_SHIFT (21U)
/*! GPIO_B2_NASRC - GPIO_B2 IO bank compensation codes */
#define BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_NASRC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_NASRC_SHIFT)) & BLK_CTRL_WAKEUPMIX_GPIO_B2_IO_CTRL_GPIO_B2_NASRC_MASK)
/*! @} */

/*! @name MISC_IO_CTRL - Miscellaneous control register of IO */
/*! @{ */

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_MASK (0x1U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_SHIFT (0U)
/*! I3C_ON_CHIP_STRONG_PULL_DIS - Disable I3C on-chip strong pull for I3C2
 *  0b0..On-chip strong pull is enabled
 *  0b1..On-chip strong pull is disabled
 */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_I3C_ON_CHIP_STRONG_PULL_DIS_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_HIGH_RANGE_MASK (0x10U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_HIGH_RANGE_SHIFT (4U)
/*! GPIO_AD_HIGH_RANGE - GPIO_AD IO bank supply voltage range selection for GPIO_AD_00 to GPIO_AD_17 */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_HIGH_RANGE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_HIGH_RANGE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_HIGH_RANGE_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_LOW_RANGE_MASK (0x20U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_LOW_RANGE_SHIFT (5U)
/*! GPIO_AD_LOW_RANGE - GPIO_AD IO bank supply voltage range selection for GPIO_AD_00 to GPIO_AD_17 */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_LOW_RANGE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_LOW_RANGE_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_GPIO_AD_LOW_RANGE_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC1_SLEEP_MASK (0x400U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC1_SLEEP_SHIFT (10U)
/*! SUPLYDET_EMC1_SLEEP - GPIO_EMC_B1 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC1_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC1_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC1_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC2_SLEEP_MASK (0x800U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC2_SLEEP_SHIFT (11U)
/*! SUPLYDET_EMC2_SLEEP - GPIO_EMC_B2 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC2_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC2_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_EMC2_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD1_SLEEP_MASK (0x1000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD1_SLEEP_SHIFT (12U)
/*! SUPLYDET_SD1_SLEEP - GPIO_SD_B1 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD1_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD1_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD1_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD2_SLEEP_MASK (0x2000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD2_SLEEP_SHIFT (13U)
/*! SUPLYDET_SD2_SLEEP - GPIO_SD_B2 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD2_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD2_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_SD2_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B1_SLEEP_MASK (0x4000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B1_SLEEP_SHIFT (14U)
/*! SUPLYDET_GPIO_B1_SLEEP - GPIO_GPIO_B1 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B1_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B1_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B1_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B2_SLEEP_MASK (0x8000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B2_SLEEP_SHIFT (15U)
/*! SUPLYDET_GPIO_B2_SLEEP - GPIO_GPIO_B1 IO bank supply voltage detector sleep mode enable */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B2_SLEEP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B2_SLEEP_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_SUPLYDET_GPIO_B2_SLEEP_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT0_POL_MASK (0x10000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT0_POL_SHIFT (16U)
/*! ECAT_LINK_ACT0_POL - ECAT_LINK_ACT[0] polarity control */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT0_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT0_POL_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT0_POL_MASK)

#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT1_POL_MASK (0x20000U)
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT1_POL_SHIFT (17U)
/*! ECAT_LINK_ACT1_POL - ECAT_LINK_ACT[1] polarity control */
#define BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT1_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT1_POL_SHIFT)) & BLK_CTRL_WAKEUPMIX_MISC_IO_CTRL_ECAT_LINK_ACT1_POL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_WAKEUPMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_WAKEUPMIX_H_ */

