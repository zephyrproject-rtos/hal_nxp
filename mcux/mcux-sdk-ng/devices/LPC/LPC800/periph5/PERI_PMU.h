/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**                          LPC804UK
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PMU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PMU
 *
 * CMSIS Peripheral Access Layer for PMU
 */

#if !defined(PERI_PMU_H_)
#define PERI_PMU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC804M101JDH20) || defined(CPU_LPC804M101JDH24) || defined(CPU_LPC804M101JHI33) || defined(CPU_LPC804M111JDH24) || defined(CPU_LPC804UK))
#include "LPC804_COMMON.h"
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
   -- PMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Peripheral_Access_Layer PMU Peripheral Access Layer
 * @{
 */

/** PMU - Size of Registers Arrays */
#define PMU_GPREG_COUNT                           5u

/** PMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCON;                              /**< Power control register, offset: 0x0 */
  __IO uint32_t GPREG[PMU_GPREG_COUNT];            /**< General purpose register N, array offset: 0x4, array step: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t WUSRCREG;                          /**< Pin wake-up source register, offset: 0x20 */
  __IO uint32_t WUENAREG;                          /**< Pin wake-up enable register, offset: 0x24 */
} PMU_Type;

/* ----------------------------------------------------------------------------
   -- PMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMU_Register_Masks PMU Register Masks
 * @{
 */

/*! @name PCON - Power control register */
/*! @{ */

#define PMU_PCON_PM_MASK                         (0x7U)
#define PMU_PCON_PM_SHIFT                        (0U)
/*! PM - Power mode
 *  0b000..Default. The part is in active or sleep mode.
 *  0b001..Deep-sleep mode. ARM WFI will enter Deep-sleep mode.
 *  0b010..Power-down mode. ARM WFI will enter Power-down mode.
 *  0b011..Deep power-down mode. ARM WFI will enter Deep-power down mode (ARM Cortex-M0+ core powered-down).
 */
#define PMU_PCON_PM(x)                           (((uint32_t)(((uint32_t)(x)) << PMU_PCON_PM_SHIFT)) & PMU_PCON_PM_MASK)

#define PMU_PCON_NODPD_MASK                      (0x8U)
#define PMU_PCON_NODPD_SHIFT                     (3U)
/*! NODPD - A 1 in this bit prevents entry to Deep power-down mode when 0x3 is written to the PM
 *    field above, the SLEEPDEEP bit is set, and a WFI is executed. This bit is cleared only by
 *    power-on reset, so writing a one to this bit locks the part in a mode in which Deep power-down mode
 *    is blocked.
 */
#define PMU_PCON_NODPD(x)                        (((uint32_t)(((uint32_t)(x)) << PMU_PCON_NODPD_SHIFT)) & PMU_PCON_NODPD_MASK)

#define PMU_PCON_SLEEPFLAG_MASK                  (0x100U)
#define PMU_PCON_SLEEPFLAG_SHIFT                 (8U)
/*! SLEEPFLAG - Sleep mode flag
 *  0b0..Active mode. Read: No power-down mode entered. Part is in Active mode. Write: No effect.
 *  0b1..Low power mode. Read: Sleep, Deep-sleep or Power-down mode entered. Write: Writing a 1 clears the SLEEPFLAG bit to 0.
 */
#define PMU_PCON_SLEEPFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << PMU_PCON_SLEEPFLAG_SHIFT)) & PMU_PCON_SLEEPFLAG_MASK)

#define PMU_PCON_DPDFLAG_MASK                    (0x800U)
#define PMU_PCON_DPDFLAG_SHIFT                   (11U)
/*! DPDFLAG - Deep power-down flag
 *  0b0..Not Deep power-down. Read: Deep power-down mode not entered. Write: No effect.
 *  0b1..Deep power-down. Read: Deep power-down mode entered. Write: Clear the Deep power-down flag.
 */
#define PMU_PCON_DPDFLAG(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_PCON_DPDFLAG_SHIFT)) & PMU_PCON_DPDFLAG_MASK)
/*! @} */

/*! @name GPREG - General purpose register N */
/*! @{ */

#define PMU_GPREG_GPDATA_MASK                    (0xFFFFFFFFU)
#define PMU_GPREG_GPDATA_SHIFT                   (0U)
/*! GPDATA - Data retained during Deep power-down mode. */
#define PMU_GPREG_GPDATA(x)                      (((uint32_t)(((uint32_t)(x)) << PMU_GPREG_GPDATA_SHIFT)) & PMU_GPREG_GPDATA_MASK)
/*! @} */

/*! @name WUSRCREG - Pin wake-up source register */
/*! @{ */

#define PMU_WUSRCREG_WUSRCREG_MASK               (0xFFU)
#define PMU_WUSRCREG_WUSRCREG_SHIFT              (0U)
/*! WUSRCREG - Pin wake-up source */
#define PMU_WUSRCREG_WUSRCREG(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_WUSRCREG_WUSRCREG_SHIFT)) & PMU_WUSRCREG_WUSRCREG_MASK)
/*! @} */

/*! @name WUENAREG - Pin wake-up enable register */
/*! @{ */

#define PMU_WUENAREG_WUENAREG_MASK               (0xFFU)
#define PMU_WUENAREG_WUENAREG_SHIFT              (0U)
/*! WUENAREG - Pin wake-up enable */
#define PMU_WUENAREG_WUENAREG(x)                 (((uint32_t)(((uint32_t)(x)) << PMU_WUENAREG_WUENAREG_SHIFT)) & PMU_WUENAREG_WUENAREG_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMU_Register_Masks */


/*!
 * @}
 */ /* end of group PMU_Peripheral_Access_Layer */


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


#endif  /* PERI_PMU_H_ */

