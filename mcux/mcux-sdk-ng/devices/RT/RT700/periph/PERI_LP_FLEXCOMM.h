/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LP_FLEXCOMM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LP_FLEXCOMM.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LP_FLEXCOMM
 *
 * CMSIS Peripheral Access Layer for LP_FLEXCOMM
 */

#if !defined(PERI_LP_FLEXCOMM_H_)
#define PERI_LP_FLEXCOMM_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- LP_FLEXCOMM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LP_FLEXCOMM_Peripheral_Access_Layer LP_FLEXCOMM Peripheral Access Layer
 * @{
 */

/** LP_FLEXCOMM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4084];
  __I  uint32_t ISTAT;                             /**< Interrupt Status, offset: 0xFF4 */
  __IO uint32_t PSELID;                            /**< Peripheral Select and ID, offset: 0xFF8 */
} LP_FLEXCOMM_Type;

/* ----------------------------------------------------------------------------
   -- LP_FLEXCOMM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LP_FLEXCOMM_Register_Masks LP_FLEXCOMM Register Masks
 * @{
 */

/*! @name ISTAT - Interrupt Status */
/*! @{ */

#define LP_FLEXCOMM_ISTAT_UARTTX_MASK            (0x1U)
#define LP_FLEXCOMM_ISTAT_UARTTX_SHIFT           (0U)
/*! UARTTX - UART TX Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_UARTTX(x)              (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_UARTTX_SHIFT)) & LP_FLEXCOMM_ISTAT_UARTTX_MASK)

#define LP_FLEXCOMM_ISTAT_UARTRX_MASK            (0x2U)
#define LP_FLEXCOMM_ISTAT_UARTRX_SHIFT           (1U)
/*! UARTRX - UART RX Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_UARTRX(x)              (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_UARTRX_SHIFT)) & LP_FLEXCOMM_ISTAT_UARTRX_MASK)

#define LP_FLEXCOMM_ISTAT_SPI_MASK               (0x4U)
#define LP_FLEXCOMM_ISTAT_SPI_SHIFT              (2U)
/*! SPI - SPI Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_SPI(x)                 (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_SPI_SHIFT)) & LP_FLEXCOMM_ISTAT_SPI_MASK)

#define LP_FLEXCOMM_ISTAT_I2CM_MASK              (0x10U)
#define LP_FLEXCOMM_ISTAT_I2CM_SHIFT             (4U)
/*! I2CM - I2C Controller Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_I2CM(x)                (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_I2CM_SHIFT)) & LP_FLEXCOMM_ISTAT_I2CM_MASK)

#define LP_FLEXCOMM_ISTAT_I2CS_MASK              (0x20U)
#define LP_FLEXCOMM_ISTAT_I2CS_SHIFT             (5U)
/*! I2CS - I2C Subordinate Interrupt
 *  0b0..Clear
 *  0b1..Set
 */
#define LP_FLEXCOMM_ISTAT_I2CS(x)                (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_ISTAT_I2CS_SHIFT)) & LP_FLEXCOMM_ISTAT_I2CS_MASK)
/*! @} */

/*! @name PSELID - Peripheral Select and ID */
/*! @{ */

#define LP_FLEXCOMM_PSELID_PERSEL_MASK           (0x7U)
#define LP_FLEXCOMM_PSELID_PERSEL_SHIFT          (0U)
/*! PERSEL - Peripheral Select
 *  0b000..No peripheral selected
 *  0b001..UART
 *  0b010..SPI
 *  0b011..I2C
 *  0b111..UART and I2C
 */
#define LP_FLEXCOMM_PSELID_PERSEL(x)             (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_PERSEL_SHIFT)) & LP_FLEXCOMM_PSELID_PERSEL_MASK)

#define LP_FLEXCOMM_PSELID_LOCK_MASK             (0x8U)
#define LP_FLEXCOMM_PSELID_LOCK_SHIFT            (3U)
/*! LOCK - Lock
 *  0b0..PERSEL is writable
 *  0b1..PERSEL is not writable
 */
#define LP_FLEXCOMM_PSELID_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_LOCK_SHIFT)) & LP_FLEXCOMM_PSELID_LOCK_MASK)

#define LP_FLEXCOMM_PSELID_UARTPRESENT_MASK      (0x10U)
#define LP_FLEXCOMM_PSELID_UARTPRESENT_SHIFT     (4U)
/*! UARTPRESENT - UART Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_UARTPRESENT(x)        (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_UARTPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_UARTPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_SPIPRESENT_MASK       (0x20U)
#define LP_FLEXCOMM_PSELID_SPIPRESENT_SHIFT      (5U)
/*! SPIPRESENT - SPI Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_SPIPRESENT(x)         (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_SPIPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_SPIPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_I2CPRESENT_MASK       (0x40U)
#define LP_FLEXCOMM_PSELID_I2CPRESENT_SHIFT      (6U)
/*! I2CPRESENT - I2C Present
 *  0b0..Not supported
 *  0b1..Supported
 */
#define LP_FLEXCOMM_PSELID_I2CPRESENT(x)         (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_I2CPRESENT_SHIFT)) & LP_FLEXCOMM_PSELID_I2CPRESENT_MASK)

#define LP_FLEXCOMM_PSELID_ID_MASK               (0xFFFFF000U)
#define LP_FLEXCOMM_PSELID_ID_SHIFT              (12U)
/*! ID - LP_FLEXCOMM interface ID */
#define LP_FLEXCOMM_PSELID_ID(x)                 (((uint32_t)(((uint32_t)(x)) << LP_FLEXCOMM_PSELID_ID_SHIFT)) & LP_FLEXCOMM_PSELID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LP_FLEXCOMM_Register_Masks */


/*!
 * @}
 */ /* end of group LP_FLEXCOMM_Peripheral_Access_Layer */


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


#endif  /* PERI_LP_FLEXCOMM_H_ */

