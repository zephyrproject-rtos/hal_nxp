/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCTL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSCTL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSCTL
 *
 * CMSIS Peripheral Access Layer for SYSCTL
 */

#if !defined(PERI_SYSCTL_H_)
#define PERI_SYSCTL_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- SYSCTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL_Peripheral_Access_Layer SYSCTL Peripheral Access Layer
 * @{
 */

/** SYSCTL - Size of Registers Arrays */
#define SYSCTL_FCCTRLSEL_COUNT                    8u
#define SYSCTL_SHAREDCTRLSET_COUNT                2u

/** SYSCTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t UPDATELCKOUT;                      /**< Write Lock Out, offset: 0x0 */
       uint8_t RESERVED_0[60];
  __IO uint32_t FCCTRLSEL[SYSCTL_FCCTRLSEL_COUNT]; /**< Shared Signal Select for Flexcomm 0..Shared Signal Select for Flexcomm 7, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_1[32];
  __IO uint32_t SHAREDCTRLSET[SYSCTL_SHAREDCTRLSET_COUNT]; /**< Shared Signal Set 0..Shared Signal Set 1, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_2[248];
  __IO uint32_t CODE_GRAY_LSB;                     /**< Gray Code LSB Input, offset: 0x180 */
  __IO uint32_t CODE_GRAY_MSB;                     /**< Gray Code MSB Input, offset: 0x184 */
  __I  uint32_t CODE_BIN_LSB;                      /**< Binary Code LSB Input, offset: 0x188 */
  __I  uint32_t CODE_BIN_MSB;                      /**< Binary Code MSB Input, offset: 0x18C */
} SYSCTL_Type;

/* ----------------------------------------------------------------------------
   -- SYSCTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL_Register_Masks SYSCTL Register Masks
 * @{
 */

/*! @name UPDATELCKOUT - Write Lock Out */
/*! @{ */

#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT_MASK    (0x1U)
#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT_SHIFT   (0U)
/*! UPDATELCKOUT - Lock Out
 *  0b0..Normal Mode: Allow writes to all registers.
 *  0b1..Protected Mode: Do not allow writes to all registers except UPDATELCKOUT.
 */
#define SYSCTL_UPDATELCKOUT_UPDATELCKOUT(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_UPDATELCKOUT_UPDATELCKOUT_SHIFT)) & SYSCTL_UPDATELCKOUT_UPDATELCKOUT_MASK)
/*! @} */

/*! @name FCCTRLSEL - Shared Signal Select for Flexcomm 0..Shared Signal Select for Flexcomm 7 */
/*! @{ */

#define SYSCTL_FCCTRLSEL_SCKINSEL_MASK           (0x3U)
#define SYSCTL_FCCTRLSEL_SCKINSEL_SHIFT          (0U)
/*! SCKINSEL - SCK Input Select
 *  0b00..Selects the dedicated FCn_SCK signal
 *  0b01..Selects from shared signal set 0 (SHAREDCTRLSET0)
 *  0b10..Selects from shared signal set 1 (SHAREDCTRLSET1)
 *  0b11..Reserved
 */
#define SYSCTL_FCCTRLSEL_SCKINSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL_FCCTRLSEL_SCKINSEL_SHIFT)) & SYSCTL_FCCTRLSEL_SCKINSEL_MASK)

#define SYSCTL_FCCTRLSEL_WSINSEL_MASK            (0x300U)
#define SYSCTL_FCCTRLSEL_WSINSEL_SHIFT           (8U)
/*! WSINSEL - WS Input Select
 *  0b00..Selects the dedicated FCn_TXD_SCL_MISO_WS signal
 *  0b01..Selects from shared signal set 0 (SHAREDCTRLSET0)
 *  0b10..Selects from shared signal set 1 (SHAREDCTRLSET1)
 *  0b11..Reserved
 */
#define SYSCTL_FCCTRLSEL_WSINSEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCTL_FCCTRLSEL_WSINSEL_SHIFT)) & SYSCTL_FCCTRLSEL_WSINSEL_MASK)

#define SYSCTL_FCCTRLSEL_DATAINSEL_MASK          (0x30000U)
#define SYSCTL_FCCTRLSEL_DATAINSEL_SHIFT         (16U)
/*! DATAINSEL - DATA Input Select
 *  0b00..Selects the dedicated FCn_RXD_SDA_MOSI_DATA input
 *  0b01..Selects from shared signal set 0 (SHAREDCTRLSET0)
 *  0b10..Selects from shared signal set 1 (SHAREDCTRLSET1)
 *  0b11..Reserved
 */
#define SYSCTL_FCCTRLSEL_DATAINSEL(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL_FCCTRLSEL_DATAINSEL_SHIFT)) & SYSCTL_FCCTRLSEL_DATAINSEL_MASK)

#define SYSCTL_FCCTRLSEL_DATAOUTSEL_MASK         (0x3000000U)
#define SYSCTL_FCCTRLSEL_DATAOUTSEL_SHIFT        (24U)
/*! DATAOUTSEL - DATA Output Select
 *  0b00..Selects the dedicated FCn_RXD_SDA_MOSI_DATA output
 *  0b01..Selects from shared signal set 0 (SHAREDCTRLSET0)
 *  0b10..Selects from shared signal set 1 (SHAREDCTRLSET1)
 *  0b11..Reserved
 */
#define SYSCTL_FCCTRLSEL_DATAOUTSEL(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL_FCCTRLSEL_DATAOUTSEL_SHIFT)) & SYSCTL_FCCTRLSEL_DATAOUTSEL_MASK)
/*! @} */

/*! @name SHAREDCTRLSET - Shared Signal Set 0..Shared Signal Set 1 */
/*! @{ */

#define SYSCTL_SHAREDCTRLSET_SHAREDSCKSEL_MASK   (0x7U)
#define SYSCTL_SHAREDCTRLSET_SHAREDSCKSEL_SHIFT  (0U)
/*! SHAREDSCKSEL - SCK Source Select
 *  0b000..Flexcomm 0
 *  0b001..Flexcomm 1
 *  0b010..Flexcomm 2
 *  0b011..Reserved
 *  0b100..Flexcomm 4
 *  0b101..Flexcomm 5
 *  0b110..Flexcomm 6
 *  0b111..Flexcomm 7
 */
#define SYSCTL_SHAREDCTRLSET_SHAREDSCKSEL(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_SHAREDSCKSEL_SHIFT)) & SYSCTL_SHAREDCTRLSET_SHAREDSCKSEL_MASK)

#define SYSCTL_SHAREDCTRLSET_SHAREDWSSEL_MASK    (0x70U)
#define SYSCTL_SHAREDCTRLSET_SHAREDWSSEL_SHIFT   (4U)
/*! SHAREDWSSEL - WS Source Select
 *  0b000..Flexcomm 0
 *  0b001..Flexcomm 1
 *  0b010..Flexcomm 2
 *  0b011..Reserved
 *  0b100..Flexcomm 4
 *  0b101..Flexcomm 5
 *  0b110..Flexcomm 6
 *  0b111..Flexcomm 7
 */
#define SYSCTL_SHAREDCTRLSET_SHAREDWSSEL(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_SHAREDWSSEL_SHIFT)) & SYSCTL_SHAREDCTRLSET_SHAREDWSSEL_MASK)

#define SYSCTL_SHAREDCTRLSET_SHAREDDATASEL_MASK  (0x700U)
#define SYSCTL_SHAREDCTRLSET_SHAREDDATASEL_SHIFT (8U)
/*! SHAREDDATASEL - DATA Input Source Select
 *  0b000..Flexcomm 0
 *  0b001..Flexcomm 1
 *  0b010..Flexcomm 2
 *  0b011..Reserved
 *  0b100..Flexcomm 4
 *  0b101..Flexcomm 5
 *  0b110..Flexcomm 6
 *  0b111..Flexcomm 7
 */
#define SYSCTL_SHAREDCTRLSET_SHAREDDATASEL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_SHAREDDATASEL_SHIFT)) & SYSCTL_SHAREDCTRLSET_SHAREDDATASEL_MASK)

#define SYSCTL_SHAREDCTRLSET_FC0DATAOUTEN_MASK   (0x10000U)
#define SYSCTL_SHAREDCTRLSET_FC0DATAOUTEN_SHIFT  (16U)
/*! FC0DATAOUTEN - DATAOUT Enable for Flexcomm 0
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC0DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC0DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC0DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC1DATAOUTEN_MASK   (0x20000U)
#define SYSCTL_SHAREDCTRLSET_FC1DATAOUTEN_SHIFT  (17U)
/*! FC1DATAOUTEN - DATAOUT Enable for Flexcomm 1
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC1DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC1DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC1DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC2DATAOUTEN_MASK   (0x40000U)
#define SYSCTL_SHAREDCTRLSET_FC2DATAOUTEN_SHIFT  (18U)
/*! FC2DATAOUTEN - DATAOUT Enable for Flexcomm 2
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC2DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC2DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC2DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC4DATAOUTEN_MASK   (0x100000U)
#define SYSCTL_SHAREDCTRLSET_FC4DATAOUTEN_SHIFT  (20U)
/*! FC4DATAOUTEN - DATAOUT Enable for Flexcomm 4
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC4DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC4DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC4DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC5DATAOUTEN_MASK   (0x200000U)
#define SYSCTL_SHAREDCTRLSET_FC5DATAOUTEN_SHIFT  (21U)
/*! FC5DATAOUTEN - DATAOUT Enable for Flexcomm 5
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC5DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC5DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC5DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC6DATAOUTEN_MASK   (0x400000U)
#define SYSCTL_SHAREDCTRLSET_FC6DATAOUTEN_SHIFT  (22U)
/*! FC6DATAOUTEN - DATAOUT Enable for Flexcomm 6
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC6DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC6DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC6DATAOUTEN_MASK)

#define SYSCTL_SHAREDCTRLSET_FC7DATAOUTEN_MASK   (0x800000U)
#define SYSCTL_SHAREDCTRLSET_FC7DATAOUTEN_SHIFT  (23U)
/*! FC7DATAOUTEN - DATAOUT Enable for Flexcomm 7
 *  0b0..Does not contribute
 *  0b1..Contributes
 */
#define SYSCTL_SHAREDCTRLSET_FC7DATAOUTEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL_SHAREDCTRLSET_FC7DATAOUTEN_SHIFT)) & SYSCTL_SHAREDCTRLSET_FC7DATAOUTEN_MASK)
/*! @} */

/*! @name CODE_GRAY_LSB - Gray Code LSB Input */
/*! @{ */

#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_MASK  (0xFFFFFFFFU)
#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_SHIFT (0U)
/*! CODE_GRAY_LSB - Gray code (least-significant) */
#define SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_SHIFT)) & SYSCTL_CODE_GRAY_LSB_CODE_GRAY_LSB_MASK)
/*! @} */

/*! @name CODE_GRAY_MSB - Gray Code MSB Input */
/*! @{ */

#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_MASK  (0x3FFU)
#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_SHIFT (0U)
/*! CODE_GRAY_MSB - Gray code (most-significant) */
#define SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_SHIFT)) & SYSCTL_CODE_GRAY_MSB_CODE_GRAY_MSB_MASK)
/*! @} */

/*! @name CODE_BIN_LSB - Binary Code LSB Input */
/*! @{ */

#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_MASK    (0xFFFFFFFFU)
#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_SHIFT   (0U)
/*! CODE_BIN_LSB - Binary converted code (least-significant) */
#define SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_SHIFT)) & SYSCTL_CODE_BIN_LSB_CODE_BIN_LSB_MASK)
/*! @} */

/*! @name CODE_BIN_MSB - Binary Code MSB Input */
/*! @{ */

#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_MASK    (0x3FFU)
#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_SHIFT   (0U)
/*! CODE_BIN_MSB - Binary converted code (most-significant) */
#define SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB(x)      (((uint32_t)(((uint32_t)(x)) << SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_SHIFT)) & SYSCTL_CODE_BIN_MSB_CODE_BIN_MSB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCTL_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCTL_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSCTL_H_ */

