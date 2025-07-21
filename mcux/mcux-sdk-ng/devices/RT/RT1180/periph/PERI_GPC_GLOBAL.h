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
**         CMSIS Peripheral Access Layer for GPC_GLOBAL
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
 * @file PERI_GPC_GLOBAL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC_GLOBAL
 *
 * CMSIS Peripheral Access Layer for GPC_GLOBAL
 */

#if !defined(PERI_GPC_GLOBAL_H_)
#define PERI_GPC_GLOBAL_H_                       /**< Symbol preventing repeated inclusion */

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
   -- GPC_GLOBAL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Peripheral_Access_Layer GPC_GLOBAL Peripheral Access Layer
 * @{
 */

/** GPC_GLOBAL - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t AUTHEN_CTRL;                       /**< GPC Global Authentication Control, offset: 0x4 */
       uint8_t RESERVED_1[8];
  __IO uint32_t GPC_CPU0_DOMAIN;                   /**< GPC CPU0 domain assignment, offset: 0x10 */
  __IO uint32_t GPC_CPU1_DOMAIN;                   /**< GPC CPU1 domain assignment, offset: 0x14 */
       uint8_t RESERVED_2[12];
  __IO uint32_t GPC_MASTER;                        /**< GPC master CPU configuration, offset: 0x24 */
       uint8_t RESERVED_3[472];
  __IO uint32_t GPC_ROSC_CTRL;                     /**< RCOSC control, offset: 0x200 */
} GPC_GLOBAL_Type;

/* ----------------------------------------------------------------------------
   -- GPC_GLOBAL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_GLOBAL_Register_Masks GPC_GLOBAL Register Masks
 * @{
 */

/*! @name AUTHEN_CTRL - GPC Global Authentication Control */
/*! @{ */

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_MASK     (0x80U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_SHIFT    (7U)
/*! LOCK_CFG - Configuration lock
 *  0b0..The value of low power configuration fields are not locked.
 *  0b1..The value of low power configuration fields are locked. Refer to the function field of each gpc_global registers.
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG(x)       (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_CFG_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_USER_MASK         (0x100U)
#define GPC_GLOBAL_AUTHEN_CTRL_USER_SHIFT        (8U)
/*! USER - Allow user mode access
 *  0b0..Allow only privilege mode to access CPU mode control registers
 *  0b1..Allow both privilege and user mode to access CPU mode control registers
 */
#define GPC_GLOBAL_AUTHEN_CTRL_USER(x)           (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_USER_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_USER_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_MASK    (0x200U)
#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_SHIFT   (9U)
/*! NONSECURE - Allow non-secure mode access
 *  0b0..Allow only secure mode to access CPU mode registers
 *  0b1..Allow both secure and non-secure mode to access CPU mode control registers.
 */
#define GPC_GLOBAL_AUTHEN_CTRL_NONSECURE(x)      (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_NONSECURE_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_MASK (0x800U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_SHIFT (11U)
/*! LOCK_SETTING - Lock NONSECURE and USER
 *  0b0..NONSECURE and USER fields are not locked
 *  0b1..NONSECURE and USER fields are locked
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING(x)   (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_SETTING_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_MASK    (0x8000U)
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_SHIFT   (15U)
/*! LOCK_LIST - White list lock
 *  0b0..WHITE_LIST is not locked
 *  0b1..WHITE_LIST is locked
 */
#define GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST(x)      (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_LOCK_LIST_MASK)

#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_MASK   (0xFFFF0000U)
#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_SHIFT  (16U)
/*! WHITE_LIST - Domain ID white list */
#define GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_SHIFT)) & GPC_GLOBAL_AUTHEN_CTRL_WHITE_LIST_MASK)
/*! @} */

/*! @name GPC_CPU0_DOMAIN - GPC CPU0 domain assignment */
/*! @{ */

#define GPC_GLOBAL_GPC_CPU0_DOMAIN_CPU0_DOMAIN_MASK (0xFFFFU)
#define GPC_GLOBAL_GPC_CPU0_DOMAIN_CPU0_DOMAIN_SHIFT (0U)
/*! CPU0_DOMAIN - CPU0 domain assignment */
#define GPC_GLOBAL_GPC_CPU0_DOMAIN_CPU0_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_CPU0_DOMAIN_CPU0_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_CPU0_DOMAIN_CPU0_DOMAIN_MASK)
/*! @} */

/*! @name GPC_CPU1_DOMAIN - GPC CPU1 domain assignment */
/*! @{ */

#define GPC_GLOBAL_GPC_CPU1_DOMAIN_CPU1_DOMAIN_MASK (0xFFFFU)
#define GPC_GLOBAL_GPC_CPU1_DOMAIN_CPU1_DOMAIN_SHIFT (0U)
/*! CPU1_DOMAIN - CPU1 domain assignment */
#define GPC_GLOBAL_GPC_CPU1_DOMAIN_CPU1_DOMAIN(x) (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_CPU1_DOMAIN_CPU1_DOMAIN_SHIFT)) & GPC_GLOBAL_GPC_CPU1_DOMAIN_CPU1_DOMAIN_MASK)
/*! @} */

/*! @name GPC_MASTER - GPC master CPU configuration */
/*! @{ */

#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_MASK   (0x1U)
#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_SHIFT  (0U)
/*! CPU0_MASTER - Setting to 1 means CPU0 is the master CPU of its domain
 *  0b0..CPU0 is not the master CPU of its domain
 *  0b1..CPU0 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU0_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU0_MASTER_MASK)

#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_MASK   (0x2U)
#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_SHIFT  (1U)
/*! CPU1_MASTER - Setting to 1 means CPU1 is the master CPU of its domain
 *  0b0..CPU1 is not the master CPU of its domain
 *  0b1..CPU1 is the master CPU of its domain
 */
#define GPC_GLOBAL_GPC_MASTER_CPU1_MASTER(x)     (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_SHIFT)) & GPC_GLOBAL_GPC_MASTER_CPU1_MASTER_MASK)
/*! @} */

/*! @name GPC_ROSC_CTRL - RCOSC control */
/*! @{ */

#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK (0x1U)
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT (0U)
/*! ROSC_OFF_EN - Shut off the 24 MHz RCOSC clock when system sleep
 *  0b0..Keep 24 MHz ROSC clock running during system sleep
 *  0b1..Shut off 24 MHz ROSC clock during system sleep
 */
#define GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN(x)  (((uint32_t)(((uint32_t)(x)) << GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_SHIFT)) & GPC_GLOBAL_GPC_ROSC_CTRL_ROSC_OFF_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_GLOBAL_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_GLOBAL_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_GLOBAL_H_ */

