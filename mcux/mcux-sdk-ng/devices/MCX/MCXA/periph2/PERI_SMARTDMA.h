/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SMARTDMA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_SMARTDMA.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for SMARTDMA
 *
 * CMSIS Peripheral Access Layer for SMARTDMA
 */

#if !defined(PERI_SMARTDMA_H_)
#define PERI_SMARTDMA_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
   -- SMARTDMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTDMA_Peripheral_Access_Layer SMARTDMA Peripheral Access Layer
 * @{
 */

/** SMARTDMA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[32];
  __IO uint32_t BOOTADR;                           /**< Boot Address, offset: 0x20 */
  __IO uint32_t CTRL;                              /**< Control, offset: 0x24 */
  __I  uint32_t PC;                                /**< Program Counter, offset: 0x28 */
  __I  uint32_t SP;                                /**< Stack Pointer, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t ARM2EZH;                           /**< ARM to EZH Interrupt Control, offset: 0x40 */
  __IO uint32_t EZH2ARM;                           /**< EZH to ARM Trigger, offset: 0x44 */
  __IO uint32_t PENDTRAP;                          /**< Pending Trap Control, offset: 0x48 */
} SMARTDMA_Type;

/* ----------------------------------------------------------------------------
   -- SMARTDMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTDMA_Register_Masks SMARTDMA Register Masks
 * @{
 */

/*! @name BOOTADR - Boot Address */
/*! @{ */

#define SMARTDMA_BOOTADR_ADDR_MASK               (0xFFFFFFFCU)
#define SMARTDMA_BOOTADR_ADDR_SHIFT              (2U)
/*! ADDR - 32-bit boot address, the boot address should be 4-byte aligned. */
#define SMARTDMA_BOOTADR_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << SMARTDMA_BOOTADR_ADDR_SHIFT)) & SMARTDMA_BOOTADR_ADDR_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define SMARTDMA_CTRL_START_MASK                 (0x1U)
#define SMARTDMA_CTRL_START_SHIFT                (0U)
/*! START - Start Bit Ignition */
#define SMARTDMA_CTRL_START(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_START_SHIFT)) & SMARTDMA_CTRL_START_MASK)

#define SMARTDMA_CTRL_EXF_MASK                   (0x2U)
#define SMARTDMA_CTRL_EXF_SHIFT                  (1U)
/*! EXF - External Flag */
#define SMARTDMA_CTRL_EXF(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_EXF_SHIFT)) & SMARTDMA_CTRL_EXF_MASK)

#define SMARTDMA_CTRL_ERRDIS_MASK                (0x4U)
#define SMARTDMA_CTRL_ERRDIS_SHIFT               (2U)
/*! ERRDIS - Error Disable */
#define SMARTDMA_CTRL_ERRDIS(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_ERRDIS_SHIFT)) & SMARTDMA_CTRL_ERRDIS_MASK)

#define SMARTDMA_CTRL_BUFEN_MASK                 (0x8U)
#define SMARTDMA_CTRL_BUFEN_SHIFT                (3U)
/*! BUFEN - Buffer Enable */
#define SMARTDMA_CTRL_BUFEN(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_BUFEN_SHIFT)) & SMARTDMA_CTRL_BUFEN_MASK)

#define SMARTDMA_CTRL_SYNCEN_MASK                (0x10U)
#define SMARTDMA_CTRL_SYNCEN_SHIFT               (4U)
/*! SYNCEN - Sync Enable */
#define SMARTDMA_CTRL_SYNCEN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_SYNCEN_SHIFT)) & SMARTDMA_CTRL_SYNCEN_MASK)

#define SMARTDMA_CTRL_WKEY_MASK                  (0xFFFF0000U)
#define SMARTDMA_CTRL_WKEY_SHIFT                 (16U)
/*! WKEY - Write Key */
#define SMARTDMA_CTRL_WKEY(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTDMA_CTRL_WKEY_SHIFT)) & SMARTDMA_CTRL_WKEY_MASK)
/*! @} */

/*! @name PC - Program Counter */
/*! @{ */

#define SMARTDMA_PC_PC_MASK                      (0xFFFFFFFFU)
#define SMARTDMA_PC_PC_SHIFT                     (0U)
/*! PC - Program Counter */
#define SMARTDMA_PC_PC(x)                        (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PC_PC_SHIFT)) & SMARTDMA_PC_PC_MASK)
/*! @} */

/*! @name SP - Stack Pointer */
/*! @{ */

#define SMARTDMA_SP_SP_MASK                      (0xFFFFFFFFU)
#define SMARTDMA_SP_SP_SHIFT                     (0U)
/*! SP - Stack Pointer */
#define SMARTDMA_SP_SP(x)                        (((uint32_t)(((uint32_t)(x)) << SMARTDMA_SP_SP_SHIFT)) & SMARTDMA_SP_SP_MASK)
/*! @} */

/*! @name ARM2EZH - ARM to EZH Interrupt Control */
/*! @{ */

#define SMARTDMA_ARM2EZH_IE_MASK                 (0x3U)
#define SMARTDMA_ARM2EZH_IE_SHIFT                (0U)
/*! IE - Interrupt Enable */
#define SMARTDMA_ARM2EZH_IE(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_IE_SHIFT)) & SMARTDMA_ARM2EZH_IE_MASK)

#define SMARTDMA_ARM2EZH_GP_MASK                 (0xFFFFFFFCU)
#define SMARTDMA_ARM2EZH_GP_SHIFT                (2U)
/*! GP - General purpose register bits */
#define SMARTDMA_ARM2EZH_GP(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_ARM2EZH_GP_SHIFT)) & SMARTDMA_ARM2EZH_GP_MASK)
/*! @} */

/*! @name EZH2ARM - EZH to ARM Trigger */
/*! @{ */

#define SMARTDMA_EZH2ARM_GP_MASK                 (0xFFFFFFFFU)
#define SMARTDMA_EZH2ARM_GP_SHIFT                (0U)
/*! GP - General purpose register bits Writing to EZH2ARM triggers the ARM interrupt when ARM2EZH [1:0] == 2h */
#define SMARTDMA_EZH2ARM_GP(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTDMA_EZH2ARM_GP_SHIFT)) & SMARTDMA_EZH2ARM_GP_MASK)
/*! @} */

/*! @name PENDTRAP - Pending Trap Control */
/*! @{ */

#define SMARTDMA_PENDTRAP_STATUS_MASK            (0xFFU)
#define SMARTDMA_PENDTRAP_STATUS_SHIFT           (0U)
/*! STATUS - Status Flag or Pending Trap Request */
#define SMARTDMA_PENDTRAP_STATUS(x)              (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_STATUS_SHIFT)) & SMARTDMA_PENDTRAP_STATUS_MASK)

#define SMARTDMA_PENDTRAP_POL_MASK               (0xFF00U)
#define SMARTDMA_PENDTRAP_POL_SHIFT              (8U)
/*! POL - Polarity */
#define SMARTDMA_PENDTRAP_POL(x)                 (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_POL_SHIFT)) & SMARTDMA_PENDTRAP_POL_MASK)

#define SMARTDMA_PENDTRAP_EN_MASK                (0xFF0000U)
#define SMARTDMA_PENDTRAP_EN_SHIFT               (16U)
/*! EN - Enable Pending Trap */
#define SMARTDMA_PENDTRAP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTDMA_PENDTRAP_EN_SHIFT)) & SMARTDMA_PENDTRAP_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMARTDMA_Register_Masks */


/*!
 * @}
 */ /* end of group SMARTDMA_Peripheral_Access_Layer */


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


#endif  /* PERI_SMARTDMA_H_ */

