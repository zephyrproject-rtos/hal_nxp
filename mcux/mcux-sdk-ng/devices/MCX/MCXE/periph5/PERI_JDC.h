/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for JDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_JDC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for JDC
 *
 * CMSIS Peripheral Access Layer for JDC
 */

#if !defined(PERI_JDC_H_)
#define PERI_JDC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- JDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JDC_Peripheral_Access_Layer JDC Peripheral Access Layer
 * @{
 */

/** JDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32_t MSR;                               /**< Module Status Register, offset: 0x4 */
  __IO uint32_t JOUT_IPS;                          /**< JTAG Output Data Register, offset: 0x8 */
  __I  uint32_t JIN_IPS;                           /**< JTAG Input Data Register, offset: 0xC */
} JDC_Type;

/* ----------------------------------------------------------------------------
   -- JDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JDC_Register_Masks JDC Register Masks
 * @{
 */

/*! @name MCR - Module Configuration Register */
/*! @{ */

#define JDC_MCR_JOUT_IEN_MASK                    (0x1U)
#define JDC_MCR_JOUT_IEN_SHIFT                   (0U)
/*! JOUT_IEN - JOUT Interrupt Enable
 *  0b0..Setting MSR[JOUT_INT] bit does not assert the JOUT interrupt
 *  0b1..Setting MSR[JOUT_INT] bit asserts the JOUT interrupt
 */
#define JDC_MCR_JOUT_IEN(x)                      (((uint32_t)(((uint32_t)(x)) << JDC_MCR_JOUT_IEN_SHIFT)) & JDC_MCR_JOUT_IEN_MASK)

#define JDC_MCR_JIN_IEN_MASK                     (0x10000U)
#define JDC_MCR_JIN_IEN_SHIFT                    (16U)
/*! JIN_IEN - JIN Interrupt Enable
 *  0b0..Setting MSR[JIN_INT] bit does not assert the JIN interrupt
 *  0b1..Setting MSR[JIN_INT] bit asserts the JIN interrupt
 */
#define JDC_MCR_JIN_IEN(x)                       (((uint32_t)(((uint32_t)(x)) << JDC_MCR_JIN_IEN_SHIFT)) & JDC_MCR_JIN_IEN_MASK)
/*! @} */

/*! @name MSR - Module Status Register */
/*! @{ */

#define JDC_MSR_JOUT_INT_MASK                    (0x1U)
#define JDC_MSR_JOUT_INT_SHIFT                   (0U)
/*! JOUT_INT - JOUT Interrupt
 *  0b0..Cleared by writing logic 1
 *  0b1..Set when JOUT_RDY bit is cleared by tool reading JOUT register
 */
#define JDC_MSR_JOUT_INT(x)                      (((uint32_t)(((uint32_t)(x)) << JDC_MSR_JOUT_INT_SHIFT)) & JDC_MSR_JOUT_INT_MASK)

#define JDC_MSR_JOUT_RDY_MASK                    (0x4U)
#define JDC_MSR_JOUT_RDY_SHIFT                   (2U)
/*! JOUT_RDY - JOUT Ready (read only)
 *  0b0..Cleared upon tool read of JOUT register via JTAG port
 *  0b1..Set when new data is written to the JOUT_IPS register
 */
#define JDC_MSR_JOUT_RDY(x)                      (((uint32_t)(((uint32_t)(x)) << JDC_MSR_JOUT_RDY_SHIFT)) & JDC_MSR_JOUT_RDY_MASK)

#define JDC_MSR_JIN_INT_MASK                     (0x10000U)
#define JDC_MSR_JIN_INT_SHIFT                    (16U)
/*! JIN_INT - JIN Interrupt
 *  0b0..Cleared by writing logic 1
 *  0b1..Set when new data is written to the JIN_IPS register
 */
#define JDC_MSR_JIN_INT(x)                       (((uint32_t)(((uint32_t)(x)) << JDC_MSR_JIN_INT_SHIFT)) & JDC_MSR_JIN_INT_MASK)

#define JDC_MSR_JIN_RDY_MASK                     (0x40000U)
#define JDC_MSR_JIN_RDY_SHIFT                    (18U)
/*! JIN_RDY - JIN Ready (read only)
 *  0b0..Cleared upon software read of JIN_IPS contents via IPS
 *  0b1..Set when new data is written to the JIN_IPS register
 */
#define JDC_MSR_JIN_RDY(x)                       (((uint32_t)(((uint32_t)(x)) << JDC_MSR_JIN_RDY_SHIFT)) & JDC_MSR_JIN_RDY_MASK)
/*! @} */

/*! @name JOUT_IPS - JTAG Output Data Register */
/*! @{ */

#define JDC_JOUT_IPS_Data_MASK                   (0xFFFFFFFFU)
#define JDC_JOUT_IPS_Data_SHIFT                  (0U)
/*! Data - JOUT_IPS Data */
#define JDC_JOUT_IPS_Data(x)                     (((uint32_t)(((uint32_t)(x)) << JDC_JOUT_IPS_Data_SHIFT)) & JDC_JOUT_IPS_Data_MASK)
/*! @} */

/*! @name JIN_IPS - JTAG Input Data Register */
/*! @{ */

#define JDC_JIN_IPS_Data_MASK                    (0xFFFFFFFFU)
#define JDC_JIN_IPS_Data_SHIFT                   (0U)
/*! Data - JIN_IPS data */
#define JDC_JIN_IPS_Data(x)                      (((uint32_t)(((uint32_t)(x)) << JDC_JIN_IPS_Data_SHIFT)) & JDC_JIN_IPS_Data_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group JDC_Register_Masks */


/*!
 * @}
 */ /* end of group JDC_Peripheral_Access_Layer */


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


#endif  /* PERI_JDC_H_ */

