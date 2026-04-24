/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260324
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_S_AONMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_S_AONMIX
 */

#if !defined(PERI_BLK_CTRL_S_AONMIX_H_)
#define PERI_BLK_CTRL_S_AONMIX_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- BLK_CTRL_S_AONMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Peripheral_Access_Layer BLK_CTRL_S_AONMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_S_AONMIX - Size of Registers Arrays */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT          8u
#define BLK_CTRL_S_AONMIX_CA55_IRQ_COUNT          6u
#define BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT           8u

/** BLK_CTRL_S_AONMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CM33_IRQ_MASK[BLK_CTRL_S_AONMIX_CM33_IRQ_COUNT]; /**< Cortex-M33 Interrupt Mask0..Cortex-M33 Interrupt Mask7, array offset: 0x0, array step: 0x4 */
  __IO uint32_t CM33_IRQ_MASK8;                    /**< Cortex-M33 Interrupt Mask8, offset: 0x20 */
  __IO uint32_t CM33_IRQ_MASK9;                    /**< Cortex-M33 Interrupt Mask9, offset: 0x24 */
  __IO uint32_t CM33_IRQ_MASK10;                   /**< Cortex-M33 Interrupt Mask10, offset: 0x28 */
  __IO uint32_t CM33_IRQ_MASK11;                   /**< Cortex-M33 Interrupt Mask11, offset: 0x2C */
  __IO uint32_t CM33_IRQ_MASK12;                   /**< Cortex-M33 Interrupt Mask12, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CA55_IRQ_MASK[BLK_CTRL_S_AONMIX_CA55_IRQ_COUNT]; /**< Cortex-A55 Interrupt Mask0..Cortex-A55 Interrupt Mask5, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CA55_IRQ_MASK6;                    /**< Cortex-A55 Interrupt Mask6, offset: 0x58 */
  __IO uint32_t CA55_IRQ_MASK7;                    /**< Cortex-A55 Interrupt Mask7, offset: 0x5C */
  __IO uint32_t CA55_IRQ_MASK8;                    /**< Cortex-A55 Interrupt Mask8, offset: 0x60 */
  __IO uint32_t CA55_IRQ_MASK9;                    /**< Cortex-A55 Interrupt Mask9, offset: 0x64 */
  __IO uint32_t CA55_IRQ_MASK10;                   /**< Cortex-A55 Interrupt Mask10, offset: 0x68 */
  __IO uint32_t CA55_IRQ_MASK11;                   /**< Cortex-A55 Interrupt Mask11, offset: 0x6C */
  __IO uint32_t CA55_IRQ_MASK12;                   /**< Cortex-A55 Interrupt Mask12, offset: 0x70 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CM7_IRQ_MASK[BLK_CTRL_S_AONMIX_CM7_IRQ_COUNT]; /**< Cortex-M7 Interrupt Mask0..Cortex-M7 Interrupt Mask7, array offset: 0x80, array step: 0x4 */
  __IO uint32_t CM7_IRQ_MASK8;                     /**< Cortex-M7 Interrupt Mask8, offset: 0xA0 */
  __IO uint32_t CM7_IRQ_MASK9;                     /**< Cortex-M7 Interrupt Mask9, offset: 0xA4 */
  __IO uint32_t CM7_IRQ_MASK10;                    /**< Cortex-M7 Interrupt Mask10, offset: 0xA8 */
  __IO uint32_t CM7_IRQ_MASK11;                    /**< Cortex-M7 Interrupt Mask11, offset: 0xAC */
  __IO uint32_t CM7_IRQ_MASK12;                    /**< Cortex-M7 Interrupt Mask12, offset: 0xB0 */
       uint8_t RESERVED_2[76];
  __IO uint32_t INITSVTOR;                         /**< Cortex-M33 Restart Secure Address, offset: 0x100 */
  __IO uint32_t INITNSVTOR;                        /**< Cortex-M33 Restart Non-Secure Address, offset: 0x104 */
  __IO uint32_t INITVTOR;                          /**< Cortex-M7 Restart Address, offset: 0x108 */
       uint8_t RESERVED_3[20];
  __IO uint32_t M33_CFG;                           /**< Cortex-M33 Configuration, offset: 0x120 */
  __IO uint32_t M7_CFG;                            /**< Cortex-M7 Configuration, offset: 0x124 */
       uint8_t RESERVED_4[8];
  __IO uint32_t AXBS_AON_CTRL;                     /**< AXBS AON Priority Control, offset: 0x130 */
  __IO uint32_t DAP_ACCESS_STKYBIT;                /**< DAP Access Configuration, offset: 0x134 */
  __IO uint32_t LP_HANDSHAKE_ELE;                  /**< Low Power Handshake for ELE, offset: 0x138 */
  __IO uint32_t LP_HANDSHAKE2_ELE;                 /**< Low Power Handshake 2 for ELE, offset: 0x13C */
  __IO uint32_t LP_HANDSHAKE3_ELE;                 /**< Low Power Handshake 3 for ELE, offset: 0x140 */
  __IO uint32_t LP_HANDSHAKE_SM;                   /**< Low Power Handshake for System Manager, offset: 0x144 */
  __IO uint32_t LP_HANDSHAKE2_SM;                  /**< Low Power Handshake 2 for System Manager, offset: 0x148 */
  __IO uint32_t LP_HANDSHAKE3_SM;                  /**< Low Power Handshake 3 for System Manager, offset: 0x14C */
  __IO uint32_t SM_LP_HANDSHAKE_STATUS;            /**< Low Power Handshake Status for System Manager, offset: 0x150 */
       uint8_t RESERVED_5[12];
  __IO uint32_t CA55_CPUWAIT;                      /**< CPU Wait Mode Configuration for Cortex-A55, offset: 0x160 */
  __IO uint32_t CA55_RVBARADDR0_L;                 /**< Cortex-A55 CPU0 Boot Address Low, offset: 0x164 */
  __IO uint32_t CA55_RVBARADDR0_H;                 /**< Cortex-A55 CPU0 Boot Address High, offset: 0x168 */
  __IO uint32_t CA55_RVBARADDR1_L;                 /**< Cortex-A55 CPU1 Boot Address Low, offset: 0x16C */
  __IO uint32_t CA55_RVBARADDR1_H;                 /**< Cortex-A55 CPU1 Boot Address High, offset: 0x170 */
  __IO uint32_t CA55_RVBARADDR2_L;                 /**< Cortex-A55 CPU2 Boot Address Low, offset: 0x174 */
  __IO uint32_t CA55_RVBARADDR2_H;                 /**< Cortex-A55 CPU2 Boot Address High, offset: 0x178 */
  __IO uint32_t CA55_RVBARADDR3_L;                 /**< Cortex-A55 CPU3 Boot Address Low, offset: 0x17C */
  __IO uint32_t CA55_RVBARADDR3_H;                 /**< Cortex-A55 CPU3 Boot Address High, offset: 0x180 */
       uint8_t RESERVED_6[28];
  __IO uint32_t ELE_IRQ_MASK;                      /**< ELE Interrupt Mask, offset: 0x1A0 */
  __IO uint32_t ELE_RESET_REQ_MASK;                /**< ELE Reset Mask, offset: 0x1A4 */
  __IO uint32_t ELE_HALT_STATUS;                   /**< ELE Halt Status, offset: 0x1A8 */
  __IO uint32_t CA55_MODE;                         /**< Cortex-A55 Cores Boot Mode Control, offset: 0x1AC */
  __IO uint32_t NMI_MASK;                          /**< NMI Mask, offset: 0x1B0 */
  __IO uint32_t NMI_CLR;                           /**< NMI Clear, offset: 0x1B4 */
  __IO uint32_t WDOG_ANY_MASK;                     /**< Watchdog Any Mask, offset: 0x1B8 */
       uint8_t RESERVED_7[4];
  __IO uint32_t MISC_CFG;                          /**< Miscellaneous Configuration, offset: 0x1C0 */
       uint8_t RESERVED_8[4];
  __I  uint32_t ELE_GPO_STATUS;                    /**< ELE GPO Status, offset: 0x1C8 */
  __I  uint32_t ELE_RST_REQ_STAT;                  /**< ELE Reset Request Status, offset: 0x1CC */
  __I  uint32_t ELE_IRQ_REQ_STAT;                  /**< ELE Interrupt Request Status, offset: 0x1D0 */
  __IO uint32_t VDET_CORE;                         /**< VDETECT Interrupt Mask, offset: 0x1D4 */
       uint8_t RESERVED_9[8];
  __IO uint32_t ELE_RESET_REQ_LOCK;                /**< EdgeLock Enclave Reset Requests Mask Lock, offset: 0x1E0 */
} BLK_CTRL_S_AONMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_S_AONMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_S_AONMIX_Register_Masks BLK_CTRL_S_AONMIX Register Masks
 * @{
 */

/*! @name CM33_IRQ_MASK - Cortex-M33 Interrupt Mask0..Cortex-M33 Interrupt Mask7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_SHIFT  (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_M_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM33_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK_COUNT    (8U)

/*! @name CM33_IRQ_MASK8 - Cortex-M33 Interrupt Mask8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_SHIFT (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK9 - Cortex-M33 Interrupt Mask9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_SHIFT (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK10 - Cortex-M33 Interrupt Mask10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_SHIFT (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK11 - Cortex-M33 Interrupt Mask11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_SHIFT (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name CM33_IRQ_MASK12 - Cortex-M33 Interrupt Mask12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_M_SHIFT (0U)
/*! m - Cortex-M33 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM33_IRQ_MASK12_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK - Cortex-A55 Interrupt Mask0..Cortex-A55 Interrupt Mask5 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_M_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_M_SHIFT  (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_M(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_M_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CA55_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK_COUNT    (6U)

/*! @name CA55_IRQ_MASK6 - Cortex-A55 Interrupt Mask6 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK6_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK7 - Cortex-A55 Interrupt Mask7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK7_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK8 - Cortex-A55 Interrupt Mask8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK9 - Cortex-A55 Interrupt Mask9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK10 - Cortex-A55 Interrupt Mask10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK11 - Cortex-A55 Interrupt Mask11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name CA55_IRQ_MASK12 - Cortex-A55 Interrupt Mask12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_M_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_M_SHIFT (0U)
/*! m - Cortex-A55 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_M(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_M_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_IRQ_MASK12_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK - Cortex-M7 Interrupt Mask0..Cortex-M7 Interrupt Mask7 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_MASK    (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_SHIFT   (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_M_MASK)
/*! @} */

/* The count of BLK_CTRL_S_AONMIX_CM7_IRQ_MASK */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK_COUNT     (8U)

/*! @name CM7_IRQ_MASK8 - Cortex-M7 Interrupt Mask8 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_SHIFT  (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK8_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK9 - Cortex-M7 Interrupt Mask9 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_MASK   (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_SHIFT  (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK9_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK10 - Cortex-M7 Interrupt Mask10 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_SHIFT (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK10_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK11 - Cortex-M7 Interrupt Mask11 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_SHIFT (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK11_M_MASK)
/*! @} */

/*! @name CM7_IRQ_MASK12 - Cortex-M7 Interrupt Mask12 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_M_MASK  (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_M_SHIFT (0U)
/*! m - Cortex-M7 Interrupt Mask */
#define BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_M(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_M_SHIFT)) & BLK_CTRL_S_AONMIX_CM7_IRQ_MASK12_M_MASK)
/*! @} */

/*! @name INITSVTOR - Cortex-M33 Restart Secure Address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITSVTOR_M33_MASK     (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITSVTOR_M33_SHIFT    (0U)
/*! m33 - Cortex-M33 Restart Secure Address */
#define BLK_CTRL_S_AONMIX_INITSVTOR_M33(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITSVTOR_M33_SHIFT)) & BLK_CTRL_S_AONMIX_INITSVTOR_M33_MASK)
/*! @} */

/*! @name INITNSVTOR - Cortex-M33 Restart Non-Secure Address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33_MASK    (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33_SHIFT   (0U)
/*! m33 - Cortex-M33 Restart Non-Secure Address */
#define BLK_CTRL_S_AONMIX_INITNSVTOR_M33(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITNSVTOR_M33_SHIFT)) & BLK_CTRL_S_AONMIX_INITNSVTOR_M33_MASK)
/*! @} */

/*! @name INITVTOR - Cortex-M7 Restart Address */
/*! @{ */

#define BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK       (0xFFFFFF80U)
#define BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT      (7U)
/*! M7 - Cortex-M7 Restart Address */
#define BLK_CTRL_S_AONMIX_INITVTOR_M7(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_INITVTOR_M7_SHIFT)) & BLK_CTRL_S_AONMIX_INITVTOR_M7_MASK)
/*! @} */

/*! @name M33_CFG - Cortex-M33 Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK      (0x4U)
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT     (2U)
/*! WAIT - Cortex-M33 CPU Wait Mode
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_WAIT(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK  (0x18U)
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT (3U)
/*! TCM_SIZE - Cortex-M33 TCM Size
 *  0b00..Regular TCM, 256KB Code TCM, and 256KB Sys TCM
 *  0b01..Double Code TCM and 512KB Code TCM
 *  0b10..Double Sys TCM and 512KB Sys TCM
 *  0b11..Reserved
 */
#define BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M33_CFG_TCM_SIZE_MASK)
/*! @} */

/*! @name M7_CFG - Cortex-M7 Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK   (0x7U)
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT  (0U)
/*! TCM_SIZE - Cortex-M7 TCM Size
 *  0b000..Regular TCM, 256KB ITCM, and 256KB DTCM
 *  0b001..Double ITCM and 512KB ITCM
 *  0b010..Double DTCM and 512KB DTCM
 *  0b100..HALF ITCM, 128KB ITCM, and 384KB DTCM
 *  0b101..HALF DTCM, 384KB ITCM, and 128KB DTCM
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_TCM_SIZE_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK       (0x10U)
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT      (4U)
/*! WAIT - Cortex-M7 CPU Wait
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_WAIT(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT (5U)
/*! CORECLK_FORCE_ON - Force Cortex-M7 Core Clock ON
 *  0b0..Not running
 *  0b1..Running
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_CORECLK_FORCE_ON_MASK)

#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT (6U)
/*! HCLK_FORCE_ON - Cortex-M7 Platform AHB Clock Enable
 *  0b0..Not running (gated) and TCM is not accessible.
 *  0b1..Running (enabled) and TCM is accessible.
 */
#define BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_SHIFT)) & BLK_CTRL_S_AONMIX_M7_CFG_HCLK_FORCE_ON_MASK)
/*! @} */

/*! @name AXBS_AON_CTRL - AXBS AON Priority Control */
/*! @{ */

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT (0U)
/*! FORCE_ROUND_ROBIN - Force Round Robin Enable
 *  0b0..Disables
 *  0b1..Enables (default)
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_FORCE_ROUND_ROBIN_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT (1U)
/*! M0_HIGH_PRIORITY - M0 High Priority Control
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M0_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT (2U)
/*! M1_HIGH_PRIORITY - M1 High Priority Control
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M1_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT (3U)
/*! M2_HIGH_PRIORITY - M2 High Priority Control
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M2_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT (4U)
/*! M3_HIGH_PRIORITY - M3 High Priority Control
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M3_HIGH_PRIORITY_MASK)

#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT (5U)
/*! M4_HIGH_PRIORITY - M4 High Priority Control
 *  0b0..Default priority
 *  0b1..High priority
 */
#define BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_SHIFT)) & BLK_CTRL_S_AONMIX_AXBS_AON_CTRL_M4_HIGH_PRIORITY_MASK)
/*! @} */

/*! @name DAP_ACCESS_STKYBIT - DAP Access Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT (0U)
/*! M33 - Cortex-M33 DAP Access
 *  0b0..Cortex-M33 core cannot be accessed by DAP
 *  0b1..Cortex-M33 core can be accessed by DAP
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_M33_MASK)

#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT (1U)
/*! A55 - Cortex-A55 DAP Access
 *  0b0..Cortex-A55 core cannot be accessed by DAP
 *  0b1..Cortex-A55 core can be accessed by DAP
 */
#define BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_SHIFT)) & BLK_CTRL_S_AONMIX_DAP_ACCESS_STKYBIT_A55_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_ELE - Low Power Handshake for ELE */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_SHIFT (1U)
/*! aonmix - AON Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_SHIFT (2U)
/*! M33_platform - Cortex-M33 Platform Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M33_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT (3U)
/*! ELE - ELE Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_SHIFT (5U)
/*! Cameramix - Camera Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_SHIFT (7U)
/*! A55_cpu0 - Cortex-A55 CPU0 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_SHIFT (8U)
/*! A55_cpu1 - Cortex-A55 CPU1 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_SHIFT (9U)
/*! A55_cpu2 - Cortex-A55 CPU2 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_SHIFT (10U)
/*! A55_cpu3 - Cortex-A55 CPU3 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_SHIFT (11U)
/*! A55_platform - Cortex-A55 Platform Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_SHIFT (12U)
/*! ddrmix_top - DDR Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDRMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_SHIFT (13U)
/*! ddr_phy - DDR PHY Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DDR_PHY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_SHIFT (14U)
/*! display - Display Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_SHIFT (15U)
/*! gpu - GPU Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_SHIFT (16U)
/*! hsio_top - HSIO Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_SHIFT (17U)
/*! hsio_aon - HSIO AON Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_SHIFT (18U)
/*! m7mix - Cortex-M7 Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_M7MIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_SHIFT (19U)
/*! netc - NETC Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_SHIFT (20U)
/*! noc - NOC Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_SHIFT (21U)
/*! npu - NPU Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_SHIFT (22U)
/*! vpu - VPU Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_SHIFT (23U)
/*! wakeupmix_top - WAKEUPMIX TOP Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_SHIFT (24U)
/*! wakeupmix_jtag - WAKEUPMIX JTAG Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_JTAG_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_SHIFT (25U)
/*! wakeupmix_wdog_3_4 - WAKEUPMIX WDOG3 and WDOG4 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_SHIFT (26U)
/*! wakeupmix_wdog5 - WAKEUPMIX WDOG5 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_WAKEUPMIX_WDOG5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_SHIFT (30U)
/*! aonmix_power - AON Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_ELE_AONMIX_POWER_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_ELE - Low Power Handshake 2 for ELE */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_SHIFT (0U)
/*! cameramix - Camera Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_SHIFT (2U)
/*! A55_cpu0 - Cortex-A55 CPU0 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_SHIFT (3U)
/*! A55_cpu1 - Cortex-A55 CPU1 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_SHIFT (4U)
/*! A55_cpu2 - Cortex-A55 CPU2 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_SHIFT (5U)
/*! A55_cpu3 - Cortex-A55 CPU3 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_SHIFT (6U)
/*! A55_platform - Cortex-A55 Platform Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_SHIFT (7U)
/*! ddr - DDR Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DDR_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_SHIFT (8U)
/*! display - Display Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_SHIFT (9U)
/*! gpu - GPU Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_SHIFT (10U)
/*! hsio_top - HSIO Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_SHIFT (11U)
/*! hsio_aon - HSIO_AON Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_SHIFT (12U)
/*! m7_platform - Cortex-M7 Platform Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_M7_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_SHIFT (13U)
/*! netc - NETC domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_SHIFT (14U)
/*! noc - NOC Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_SHIFT (15U)
/*! npu - NPU Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_SHIFT (16U)
/*! vpu - VPU Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_SHIFT (17U)
/*! wakeup - WAKEUP Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_WAKEUP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_SHIFT (20U)
/*! osc24mhz - OSC 24MHz Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_ELE_OSC24MHZ_MASK)
/*! @} */

/*! @name LP_HANDSHAKE3_ELE - Low Power Handshake 3 for ELE */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_ON_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_ON_SHIFT (0U)
/*! M33_TROUT_CLK_ON - Cortex-M33 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_ON_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_ON_SHIFT (1U)
/*! A55_TROUT_CLK_ON - Cortex-A55 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_ON_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_ON_SHIFT (2U)
/*! M7_TROUT_CLK_ON - Cortex-M7 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_ON_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_ON_SHIFT (3U)
/*! CAMERAMIX_TROUT_CLK_ON - CAMERAMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_ON_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_ON_SHIFT (4U)
/*! NOCMIX_TROUT_CLK_ON - NOCMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_ON_SHIFT (5U)
/*! VPUMIX_TROUT_CLK_ON - VPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_ON_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_ON_SHIFT (6U)
/*! NETCMIX_TROUT_CLK_ON - NETCMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_ON_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_ON_SHIFT (7U)
/*! DDRMIX_TROUT_CLK_ON - DDRMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_ON_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_ON_SHIFT (8U)
/*! NPUMIX_TROUT_CLK_ON - NPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_ON_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_ON_SHIFT (9U)
/*! DISPLAYMIX_TROUT_CLK_ON - DISPLAYMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_ON_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_ON_SHIFT (10U)
/*! HSIOMIX_TROUT_CLK_ON - HSIOMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_ON_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_ON_SHIFT (11U)
/*! GPUMIX_TROUT_CLK_ON - GPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_ON_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_ON_SHIFT (12U)
/*! WAKEUPMIX_TROUT_CLK_ON - WAKEUPMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_ON_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_ON_SHIFT (13U)
/*! XSPI_TROUT_CLK_ON - XSPI Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_ON_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_ON_SHIFT (14U)
/*! V2X_TROUT_CLK_ON - V2X Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_OFF_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_OFF_SHIFT (16U)
/*! M33_TROUT_CLK_OFF - Cortex-M33 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M33_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_OFF_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_OFF_SHIFT (17U)
/*! A55_TROUT_CLK_OFF - Cortex-A55 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_A55_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_OFF_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_OFF_SHIFT (18U)
/*! M7_TROUT_CLK_OFF - Cortex-M7 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_M7_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_OFF_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_OFF_SHIFT (19U)
/*! CAMERAMIX_TROUT_CLK_OFF - CAMERAMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_CAMERAMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_OFF_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_OFF_SHIFT (20U)
/*! NOCMIX_TROUT_CLK_OFF - NOCMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NOCMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_OFF_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_OFF_SHIFT (21U)
/*! VPUMIX_TROUT_CLK_OFF - VPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_VPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_OFF_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_OFF_SHIFT (22U)
/*! NETCMIX_TROUT_CLK_OFF - NETCMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NETCMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_OFF_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_OFF_SHIFT (23U)
/*! DDRMIX_TROUT_CLK_OFF - DDRMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DDRMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_OFF_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_OFF_SHIFT (24U)
/*! NPUMIX_TROUT_CLK_OFF - NPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_NPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_OFF_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_OFF_SHIFT (25U)
/*! DISPLAYMIX_TROUT_CLK_OFF - DISPLAYMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_DISPLAYMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_OFF_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_OFF_SHIFT (26U)
/*! HSIOMIX_TROUT_CLK_OFF - HSIOMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_HSIOMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_OFF_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_OFF_SHIFT (27U)
/*! GPUMIX_TROUT_CLK_OFF - GPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_GPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_OFF_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_OFF_SHIFT (28U)
/*! WAKEUPMIX_TROUT_CLK_OFF - WAKEUPMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_WAKEUPMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_OFF_MASK (0x20000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_OFF_SHIFT (29U)
/*! XSPI_TROUT_CLK_OFF - XSPI Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_XSPI_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_OFF_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_OFF_SHIFT (30U)
/*! V2X_TROUT_CLK_OFF - V2X Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_ELE_V2X_TROUT_CLK_OFF_MASK)
/*! @} */

/*! @name LP_HANDSHAKE_SM - Low Power Handshake for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_SHIFT (1U)
/*! aonmix - AON Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_SHIFT (2U)
/*! M33_platform - Cortex-M33 Platform Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M33_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT (3U)
/*! ELE - ELE Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_ELE_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_SHIFT (5U)
/*! Cameramix - Camera Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_SHIFT (7U)
/*! A55_cpu0 - Cortex-A55 CPU0 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_SHIFT (8U)
/*! A55_cpu1 - Cortex-A55 CPU1 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_SHIFT (9U)
/*! A55_cpu2 - Cortex-A55 CPU2 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_SHIFT (10U)
/*! A55_cpu3 - Cortex-A55 CPU3 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_SHIFT (11U)
/*! A55_platform - Cortex-A55 Platform Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_SHIFT (12U)
/*! ddrmix_top - DDR Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDRMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_SHIFT (13U)
/*! ddr_phy - DDR PHY Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DDR_PHY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_SHIFT (14U)
/*! display - Display Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_SHIFT (15U)
/*! gpu - GPU Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_SHIFT (16U)
/*! hsio_top - HSIO Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_SHIFT (17U)
/*! hsio_aon - HSIO AON Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_SHIFT (18U)
/*! m7mix - Cortex-M7 Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_M7MIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_SHIFT (19U)
/*! netc - NETC Domain Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_SHIFT (20U)
/*! noc - NOC Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_SHIFT (21U)
/*! npu - NPU Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_SHIFT (22U)
/*! vpu - VPU Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_SHIFT (23U)
/*! wakeupmix_top - WAKEUPMIX TOP Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_SHIFT (24U)
/*! wakeupmix_jtag - WAKEUPMIX JTAG Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_JTAG_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_SHIFT (25U)
/*! wakeupmix_wdog_3_4 - WAKEUPMIX WDOG3 and WDOG4 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG_3_4_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_SHIFT (26U)
/*! wakeupmix_wdog5 - WAKEUPMIX WDOG5 Cold Reset Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_WAKEUPMIX_WDOG5_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_SHIFT (30U)
/*! aonmix_power - AON Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE_SM_AONMIX_POWER_MASK)
/*! @} */

/*! @name LP_HANDSHAKE2_SM - Low Power Handshake 2 for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_SHIFT (0U)
/*! cameramix - Camera Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_CAMERAMIX_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_SHIFT (2U)
/*! A55_cpu0 - Cortex-A55 CPU0 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU0_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_SHIFT (3U)
/*! A55_cpu1 - Cortex-A55 CPU1 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU1_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_SHIFT (4U)
/*! A55_cpu2 - Cortex-A55 CPU2 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU2_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_SHIFT (5U)
/*! A55_cpu3 - Cortex-A55 CPU3 Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_CPU3_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_SHIFT (6U)
/*! A55_platform - Cortex-A55 Platform Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_A55_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_SHIFT (7U)
/*! ddr - DDR Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DDR_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_SHIFT (8U)
/*! display - Display Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_DISPLAY_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_SHIFT (9U)
/*! gpu - GPU Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_GPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_SHIFT (10U)
/*! hsio_top - HSIO Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_TOP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_SHIFT (11U)
/*! hsio_aon - HSIO AON Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_HSIO_AON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_SHIFT (12U)
/*! m7_platform - Cortex-M7 Platform Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_M7_PLATFORM_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_SHIFT (13U)
/*! netc - NETC Domain Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NETC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_SHIFT (14U)
/*! noc - NOC Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NOC_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_MASK (0x8000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_SHIFT (15U)
/*! npu - NPU Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_NPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_SHIFT (16U)
/*! vpu - VPU Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_VPU_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_SHIFT (17U)
/*! wakeup - WAKEUP Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_WAKEUP_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_SHIFT (20U)
/*! osc24mhz - OSC 24MHz Low Power Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE2_SM_OSC24MHZ_MASK)
/*! @} */

/*! @name LP_HANDSHAKE3_SM - Low Power Handshake 3 for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_ON_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_ON_SHIFT (0U)
/*! M33_TROUT_CLK_ON - Cortex-M33 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_ON_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_ON_SHIFT (1U)
/*! A55_TROUT_CLK_ON - Cortex-A55 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_ON_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_ON_SHIFT (2U)
/*! M7_TROUT_CLK_ON - Cortex-M7 Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_ON_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_ON_SHIFT (3U)
/*! CAMERAMIX_TROUT_CLK_ON - CAMERAMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_ON_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_ON_SHIFT (4U)
/*! NOCMIX_TROUT_CLK_ON - NOCMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_ON_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_ON_SHIFT (5U)
/*! VPUMIX_TROUT_CLK_ON - VPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_ON_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_ON_SHIFT (6U)
/*! NETCMIX_TROUT_CLK_ON - NETCMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_ON_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_ON_SHIFT (7U)
/*! DDRMIX_TROUT_CLK_ON - DDRMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_ON_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_ON_SHIFT (8U)
/*! NPUMIX_TROUT_CLK_ON - NPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_ON_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_ON_SHIFT (9U)
/*! DISPLAYMIX_TROUT_CLK_ON - DISPLAYMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_ON_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_ON_SHIFT (10U)
/*! HSIOMIX_TROUT_CLK_ON - HSIOMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_ON_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_ON_SHIFT (11U)
/*! GPUMIX_TROUT_CLK_ON - GPUMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_ON_MASK (0x1000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_ON_SHIFT (12U)
/*! WAKEUPMIX_TROUT_CLK_ON - WAKEUPMIX Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_ON_MASK (0x2000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_ON_SHIFT (13U)
/*! XSPI_TROUT_CLK_ON - XSPI Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_ON_MASK (0x4000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_ON_SHIFT (14U)
/*! V2X_TROUT_CLK_ON - V2X Trout Clock ON Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_ON(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_ON_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_ON_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_OFF_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_OFF_SHIFT (16U)
/*! M33_TROUT_CLK_OFF - Cortex-M33 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M33_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_OFF_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_OFF_SHIFT (17U)
/*! A55_TROUT_CLK_OFF - Cortex-A55 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_A55_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_OFF_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_OFF_SHIFT (18U)
/*! M7_TROUT_CLK_OFF - Cortex-M7 Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_M7_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_OFF_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_OFF_SHIFT (19U)
/*! CAMERAMIX_TROUT_CLK_OFF - CAMERAMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_CAMERAMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_OFF_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_OFF_SHIFT (20U)
/*! NOCMIX_TROUT_CLK_OFF - NOCMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NOCMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_OFF_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_OFF_SHIFT (21U)
/*! VPUMIX_TROUT_CLK_OFF - VPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_VPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_OFF_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_OFF_SHIFT (22U)
/*! NETCMIX_TROUT_CLK_OFF - NETCMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NETCMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_OFF_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_OFF_SHIFT (23U)
/*! DDRMIX_TROUT_CLK_OFF - DDRMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DDRMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_OFF_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_OFF_SHIFT (24U)
/*! NPUMIX_TROUT_CLK_OFF - NPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_NPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_OFF_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_OFF_SHIFT (25U)
/*! DISPLAYMIX_TROUT_CLK_OFF - DISPLAYMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_DISPLAYMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_OFF_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_OFF_SHIFT (26U)
/*! HSIOMIX_TROUT_CLK_OFF - HSIOMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_HSIOMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_OFF_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_OFF_SHIFT (27U)
/*! GPUMIX_TROUT_CLK_OFF - GPUMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_GPUMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_OFF_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_OFF_SHIFT (28U)
/*! WAKEUPMIX_TROUT_CLK_OFF - WAKEUPMIX Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_WAKEUPMIX_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_OFF_MASK (0x20000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_OFF_SHIFT (29U)
/*! XSPI_TROUT_CLK_OFF - XSPI Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_XSPI_TROUT_CLK_OFF_MASK)

#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_OFF_MASK (0x40000000U)
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_OFF_SHIFT (30U)
/*! V2X_TROUT_CLK_OFF - V2X Trout Clock OFF Handshake Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_OFF(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_OFF_SHIFT)) & BLK_CTRL_S_AONMIX_LP_HANDSHAKE3_SM_V2X_TROUT_CLK_OFF_MASK)
/*! @} */

/*! @name SM_LP_HANDSHAKE_STATUS - Low Power Handshake Status for System Manager */
/*! @{ */

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_SHIFT (0U)
/*! ack - Low Power Request Acknowledge
 *  0b0..No acknowledgement
 *  0b1..Acknowledgement
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_ACK_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_SHIFT (1U)
/*! stat - Clock/Reset/Power Status
 *  0b0..OFF
 *  0b1..ON
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_STAT_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK (0x1FCU)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT (2U)
/*! idx - Active Low Power Request ID */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_IDX_MASK)

#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT (9U)
/*! autoack - Auto Acknowledge Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_SHIFT)) & BLK_CTRL_S_AONMIX_SM_LP_HANDSHAKE_STATUS_AUTOACK_MASK)
/*! @} */

/*! @name CA55_CPUWAIT - CPU Wait Mode Configuration for Cortex-A55 */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT (0U)
/*! CPU0_WAIT - CPU Wait Mode For CPU0
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU0_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT (1U)
/*! CPU1_WAIT - CPU Wait Mode For CPU1
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU1_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT (2U)
/*! CPU2_WAIT - CPU Wait Mode For CPU2
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU2_WAIT_MASK)

#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT (3U)
/*! CPU3_WAIT - CPU Wait Mode For CPU3
 *  0b0..Core works normally
 *  0b1..Core stops working
 */
#define BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_CPUWAIT_CPU3_WAIT_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_L - Cortex-A55 CPU0 Boot Address Low */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT (0U)
/*! ADDR0_L - Cortex-A55 CPU0 Boot Address Low */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_L_ADDR0_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR0_H - Cortex-A55 CPU0 Boot Address High */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT (0U)
/*! ADDR0_H - Cortex-A55 CPU0 Boot Address High */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR0_H_ADDR0_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_L - Cortex-A55 CPU1 Boot Address Low */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT (0U)
/*! ADDR1_L - Cortex-A55 CPU1 Boot Address Low */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_L_ADDR1_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR1_H - Cortex-A55 CPU1 Boot Address High */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT (0U)
/*! ADDR1_H - Cortex-A55 CPU1 Boot Address High */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR1_H_ADDR1_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR2_L - Cortex-A55 CPU2 Boot Address Low */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_SHIFT (0U)
/*! ADDR2_L - Cortex-A55 CPU2 Boot Address Low */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_L_ADDR2_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR2_H - Cortex-A55 CPU2 Boot Address High */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_SHIFT (0U)
/*! ADDR2_H - Cortex-A55 CPU2 Boot Address High */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR2_H_ADDR2_H_MASK)
/*! @} */

/*! @name CA55_RVBARADDR3_L - Cortex-A55 CPU3 Boot Address Low */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_MASK (0xFFFFFFFFU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_SHIFT (0U)
/*! ADDR3_L - Cortex-A55 CPU3 Boot Address Low */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_L_ADDR3_L_MASK)
/*! @} */

/*! @name CA55_RVBARADDR3_H - Cortex-A55 CPU3 Boot Address High */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_MASK (0x3FU)
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_SHIFT (0U)
/*! ADDR3_H - Cortex-A55 CPU3 Boot Address High */
#define BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_RVBARADDR3_H_ADDR3_H_MASK)
/*! @} */

/*! @name ELE_IRQ_MASK - ELE Interrupt Mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET0_SHIFT (0U)
/*! noclk_fdet0 - ELE fdet0 Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET0_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET0_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET1_SHIFT (1U)
/*! noclk_fdet1 - ELE fdet1 Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET2_SHIFT (2U)
/*! noclk_fdet2 - ELE fdet2 Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET3_SHIFT (3U)
/*! noclk_fdet3 - ELE fdet3 Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET3_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_NOCLK_FDET3_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_32K_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_32K_SHIFT (4U)
/*! reset_req_32k - LMDA Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_32K_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_32K_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_SHIFT (5U)
/*! reset_req - LMDA Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_SYS_FAIL_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_SYS_FAIL_SHIFT (6U)
/*! sys_fail - LMDA System Failure Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_SHIFT (7U)
/*! lc_bricked - LMDA BRICK Lifecycle Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_SHIFT (9U)
/*! wdg_reset - WDOG Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_WDG_RESET_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_RX_FULL_MASK_MASK (0x10000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_RX_FULL_MASK_SHIFT (16U)
/*! mu0a_int_rx_full_mask - MU0A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_MASK (0x20000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_SHIFT (17U)
/*! mu0a_int_tx_empty_mask - MU0A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU0A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_RX_FULL_MASK_MASK (0x40000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_RX_FULL_MASK_SHIFT (18U)
/*! mu1a_int_rx_full_mask - MU1A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_MASK (0x80000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_SHIFT (19U)
/*! mu1a_int_tx_empty_mask - MU1A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU1A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_RX_FULL_MASK_MASK (0x100000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_RX_FULL_MASK_SHIFT (20U)
/*! mu2a_int_rx_full_mask - MU2A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_MASK (0x200000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_SHIFT (21U)
/*! mu2a_int_tx_empty_mask - MU2A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU2A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_RX_FULL_MASK_MASK (0x400000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_RX_FULL_MASK_SHIFT (22U)
/*! mu3a_int_rx_full_mask - MU3A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_MASK (0x800000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_SHIFT (23U)
/*! mu3a_int_tx_empty_mask - MU3A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU3A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_RX_FULL_MASK_MASK (0x1000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_RX_FULL_MASK_SHIFT (24U)
/*! mu4a_int_rx_full_mask - MU4A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_MASK (0x2000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_SHIFT (25U)
/*! mu4a_int_tx_empty_mask - MU4A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU4A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_RX_FULL_MASK_MASK (0x4000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_RX_FULL_MASK_SHIFT (26U)
/*! mu5a_int_rx_full_mask - MU5A Rx Full Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_RX_FULL_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_RX_FULL_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_RX_FULL_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_MASK (0x8000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_SHIFT (27U)
/*! mu5a_int_tx_empty_mask - MU5A Tx Empty Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_MU5A_INT_TX_EMPTY_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_EVENT_SYS_MASK_MASK (0x10000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_EVENT_SYS_MASK_SHIFT (28U)
/*! event_sys_mask - EVENT_SYS Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_EVENT_SYS_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_EVENT_SYS_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_EVENT_SYS_MASK_MASK)

#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_OCOTP_CONT_EDC_ERR_MASK (0x20000000U)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_OCOTP_CONT_EDC_ERR_SHIFT (29U)
/*! ocotp_cont_edc_err - OCOTP Controller Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_OCOTP_CONT_EDC_ERR(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_OCOTP_CONT_EDC_ERR_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_MASK_OCOTP_CONT_EDC_ERR_MASK)
/*! @} */

/*! @name ELE_RESET_REQ_MASK - ELE Reset Mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET0_SHIFT (0U)
/*! noclk_fdet0 - ELE fdet0 Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET0_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET0_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET1_SHIFT (1U)
/*! noclk_fdet1 - ELE fdet1 Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET2_SHIFT (2U)
/*! noclk_fdet2 - ELE fdet2 Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET3_SHIFT (3U)
/*! noclk_fdet3 - ELE fdet3 Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET3_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_NOCLK_FDET3_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_RESET_REQ_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_RESET_REQ_SHIFT (4U)
/*! sys_reset_req - System Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_32K_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_32K_SHIFT (5U)
/*! reset_req_32k - LMDA Reset Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_32K(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_32K_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_32K_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_SHIFT (6U)
/*! reset_req - LMDA Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_FAIL_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_FAIL_SHIFT (7U)
/*! sys_fail - LMDA System Failure Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_SHIFT (8U)
/*! lc_bricked - LMDA BRICK Lifecycle Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_SHIFT (10U)
/*! wdg_reset - WDOG Reset Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_MASK_WDG_RESET_MASK)
/*! @} */

/*! @name ELE_HALT_STATUS - ELE Halt Status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_RESUME_ACK_HOLD_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_RESUME_ACK_HOLD_SHIFT (0U)
/*! SCM_RESUME_ACK_HOLD - ELE RESUME Interrupt Request
 *  0b0..No action
 *  0b0..Not asserted
 *  0b1..Asserted
 *  0b1..Clears flag
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_RESUME_ACK_HOLD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_RESUME_ACK_HOLD_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_RESUME_ACK_HOLD_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_HALT_ACK_HOLD_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_HALT_ACK_HOLD_SHIFT (1U)
/*! SCM_HALT_ACK_HOLD - ELE HALT interrupt request
 *  0b0..No action
 *  0b0..Not asserted
 *  0b1..Asserted
 *  0b1..Clears flag
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_HALT_ACK_HOLD(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_HALT_ACK_HOLD_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_SCM_HALT_ACK_HOLD_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_RESUME_ACK_IRQ_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_RESUME_ACK_IRQ_SHIFT (8U)
/*! DIS_RESUME_ACK_IRQ - SCM_RESUME_ACK_HOLD Disable
 *  0b0..Not disable
 *  0b1..Disables
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_RESUME_ACK_IRQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_RESUME_ACK_IRQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_RESUME_ACK_IRQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_HALT_ACK_IRQ_MASK (0x200U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_HALT_ACK_IRQ_SHIFT (9U)
/*! DIS_HALT_ACK_IRQ - SCM_HALT_ACK_HOLD Disable
 *  0b0..Not disable
 *  0b1..Disables
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_HALT_ACK_IRQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_HALT_ACK_IRQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_DIS_HALT_ACK_IRQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_43_EN_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_43_EN_SHIFT (10U)
/*! IRQ_43_EN - ELE RESUME Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_43_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_43_EN_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_43_EN_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_202_EN_MASK (0x800U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_202_EN_SHIFT (11U)
/*! IRQ_202_EN - ELE HALT Interrupt Enable
 *  0b0..Enables
 *  0b1..Disables
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_202_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_202_EN_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_IRQ_202_EN_MASK)

#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_CSSI_CPU_HALTED_MASK (0x80000000U)
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_CSSI_CPU_HALTED_SHIFT (31U)
/*! CSSI_CPU_HALTED - ELE CPU HALT Status
 *  0b0..Running
 *  0b1..Halted
 */
#define BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_CSSI_CPU_HALTED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_CSSI_CPU_HALTED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_HALT_STATUS_CSSI_CPU_HALTED_MASK)
/*! @} */

/*! @name CA55_MODE - Cortex-A55 Cores Boot Mode Control */
/*! @{ */

#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK (0xFU)
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT (0U)
/*! AA64nAA32 - Cortex-A55 Core Initial Mode Control */
#define BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_SHIFT)) & BLK_CTRL_S_AONMIX_CA55_MODE_AA64NAA32_MASK)
/*! @} */

/*! @name NMI_MASK - NMI Mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK     (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT    (0U)
/*! CM33 - Cortex-M33 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM33(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK      (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT     (1U)
/*! CM7 - Cortex-M7 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_CM7(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_CM7_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT (2U)
/*! NMI_PIN_MASK - NMI PIN Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_NMI_PIN_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT (3U)
/*! WDG1_NMI_MASK - Watchdog1 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG1_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT (4U)
/*! WDG2_NMI_MASK - Watchdog2 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG2_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT (5U)
/*! WDG3_NMI_MASK - Watchdog3 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG3_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT (6U)
/*! WDG4_NMI_MASK - Watchdog4 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG4_NMI_MASK_MASK)

#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT (7U)
/*! WDG5_NMI_MASK - Watchdog5 NMI Mask
 *  0b0..NMI is usable
 *  0b1..NMI is masked
 */
#define BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_MASK_WDG5_NMI_MASK_MASK)
/*! @} */

/*! @name NMI_CLR - NMI Clear */
/*! @{ */

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK      (0x1U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT     (0U)
/*! CM33 - Cortex-M33 NMI Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM33(x)        (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM33_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM33_MASK)

#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK       (0x2U)
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT      (1U)
/*! CM7 - Cortex-M7 NMI Clear
 *  0b0..Not clear
 *  0b1..Clears
 */
#define BLK_CTRL_S_AONMIX_NMI_CLR_CM7(x)         (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_NMI_CLR_CM7_SHIFT)) & BLK_CTRL_S_AONMIX_NMI_CLR_CM7_MASK)
/*! @} */

/*! @name WDOG_ANY_MASK - Watchdog Any Mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT (0U)
/*! wdog1 - WDOG1 Timeout Signal Masks
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG1_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT (1U)
/*! wdog2 - WDOG2 Timeout Signal Masks
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG2_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT (2U)
/*! wdog3 - WDOG3 Timeout Signal Masks
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG3_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT (3U)
/*! wdog4 - WDOG4 Timeout Signal Masks
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG4_MASK)

#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT (4U)
/*! wdog5 - WDOG5 Timeout Signal Masks
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_SHIFT)) & BLK_CTRL_S_AONMIX_WDOG_ANY_MASK_WDOG5_MASK)
/*! @} */

/*! @name MISC_CFG - Miscellaneous Configuration */
/*! @{ */

#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_SHIFT (0U)
/*! netc_cfg_ierb_lock - IERB Register Access Configuration
 *  0b0..Unlocked after NETC reset. Normal read/write access to all IERB registers.
 *  0b1..Locked after NETC reset. Write access inhibited to all IERB registers, except NETCRR.
 */
#define BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_SHIFT)) & BLK_CTRL_S_AONMIX_MISC_CFG_NETC_CFG_IERB_LOCK_MASK)
/*! @} */

/*! @name ELE_GPO_STATUS - ELE GPO Status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_SHIFT (0U)
/*! ELE_GPO_8 - ELE GPO Status */
#define BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_GPO_STATUS_ELE_GPO_8_MASK)
/*! @} */

/*! @name ELE_RST_REQ_STAT - ELE Reset Request Status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_MASK (0xFFFFU)
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_SHIFT (0U)
/*! GROUP_A - Group A CSSI Events */
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_A_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_MASK (0xFFFF0000U)
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_SHIFT (16U)
/*! GROUP_B - Group B RST Events */
#define BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RST_REQ_STAT_GROUP_B_MASK)
/*! @} */

/*! @name ELE_IRQ_REQ_STAT - ELE Interrupt Request Status */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK (0xFFFFU)
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT (0U)
/*! GROUP_C - Group C Interrupts Events */
#define BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_IRQ_REQ_STAT_GROUP_C_MASK)
/*! @} */

/*! @name VDET_CORE - VDETECT Interrupt Mask */
/*! @{ */

#define BLK_CTRL_S_AONMIX_VDET_CORE_HVD_OUT_LATCH_LV_MASK_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_VDET_CORE_HVD_OUT_LATCH_LV_MASK_SHIFT (0U)
/*! hvd_out_latch_lv_mask - VDET High Voltage Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_VDET_CORE_HVD_OUT_LATCH_LV_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_VDET_CORE_HVD_OUT_LATCH_LV_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_VDET_CORE_HVD_OUT_LATCH_LV_MASK_MASK)

#define BLK_CTRL_S_AONMIX_VDET_CORE_LVD_OUT_LATCH_LV_MASK_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_VDET_CORE_LVD_OUT_LATCH_LV_MASK_SHIFT (1U)
/*! lvd_out_latch_lv_mask - VDET Low Voltage Interrupt Mask
 *  0b0..Unmask
 *  0b1..Mask
 */
#define BLK_CTRL_S_AONMIX_VDET_CORE_LVD_OUT_LATCH_LV_MASK(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_VDET_CORE_LVD_OUT_LATCH_LV_MASK_SHIFT)) & BLK_CTRL_S_AONMIX_VDET_CORE_LVD_OUT_LATCH_LV_MASK_MASK)
/*! @} */

/*! @name ELE_RESET_REQ_LOCK - EdgeLock Enclave Reset Requests Mask Lock */
/*! @{ */

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET0_MASK (0x1U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET0_SHIFT (0U)
/*! noclk_fdet0 - ELE fdet0 Reset Mask Lock Bit
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET0(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET0_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET0_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET1_MASK (0x2U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET1_SHIFT (1U)
/*! noclk_fdet1 - ELE fdet1 Reset Mask Lock Bit
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET1(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET1_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET1_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET2_MASK (0x4U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET2_SHIFT (2U)
/*! noclk_fdet2 - ELE fdet2 Reset Mask Lock Bit
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET2(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET2_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET2_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET3_MASK (0x8U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET3_SHIFT (3U)
/*! noclk_fdet3 - ELE fdet3 Reset Mask Lock Bit
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET3(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET3_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_NOCLK_FDET3_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_SYS_RESET_REQ_MASK (0x10U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_SYS_RESET_REQ_SHIFT (4U)
/*! sys_reset_req - System Reset Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_SYS_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_SYS_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_SYS_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_32K_RESET_REQ_MASK (0x20U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_32K_RESET_REQ_SHIFT (5U)
/*! lmda_32k_reset_req - LMDA Reset Interrupt Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_32K_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_32K_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_32K_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_RESET_REQ_MASK (0x40U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_RESET_REQ_SHIFT (6U)
/*! lmda_reset_req - LMDA Reset Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_RESET_REQ(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_RESET_REQ_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_RESET_REQ_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_SYS_FAIL_MASK (0x80U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_SYS_FAIL_SHIFT (7U)
/*! lmda_sys_fail - LMDA System Failure Reset Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_SYS_FAIL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_SYS_FAIL_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LMDA_SYS_FAIL_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LC_BRICKED_MASK (0x100U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LC_BRICKED_SHIFT (8U)
/*! lc_bricked - LMDA BRICK Lifecycle Reset Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LC_BRICKED(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LC_BRICKED_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_LC_BRICKED_MASK)

#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_WDG_RESET_MASK (0x400U)
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_WDG_RESET_SHIFT (10U)
/*! wdg_reset - WDOG Reset Mask Lock
 *  0b0..Unlocks
 *  0b1..Locks
 */
#define BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_WDG_RESET(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_WDG_RESET_SHIFT)) & BLK_CTRL_S_AONMIX_ELE_RESET_REQ_LOCK_WDG_RESET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_S_AONMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_S_AONMIX_H_ */

