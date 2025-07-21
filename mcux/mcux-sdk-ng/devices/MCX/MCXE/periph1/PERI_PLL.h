/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PLL
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
 * @file PERI_PLL.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for PLL
 *
 * CMSIS Peripheral Access Layer for PLL
 */

#if !defined(PERI_PLL_H_)
#define PERI_PLL_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Peripheral_Access_Layer PLL Peripheral Access Layer
 * @{
 */

/** PLL - Size of Registers Arrays */
#define PLL_PLLODIV_COUNT                         2u

/** PLL - Register Layout Typedef */
typedef struct {
  __IO uint32_t PLLCR;                             /**< PLL Control, offset: 0x0 */
  __IO uint32_t PLLSR;                             /**< PLL Status, offset: 0x4 */
  __IO uint32_t PLLDV;                             /**< PLL Divider, offset: 0x8 */
  __IO uint32_t PLLFM;                             /**< PLL Frequency Modulation, offset: 0xC */
  __IO uint32_t PLLFD;                             /**< PLL Fractional Divider, offset: 0x10 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PLLCAL2;                           /**< PLL Calibration Register 2, offset: 0x18 */
       uint8_t RESERVED_1[100];
  __IO uint32_t PLLODIV[PLL_PLLODIV_COUNT];        /**< PLL Output Divider, array offset: 0x80, array step: 0x4 */
} PLL_Type;

/* ----------------------------------------------------------------------------
   -- PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Register_Masks PLL Register Masks
 * @{
 */

/*! @name PLLCR - PLL Control */
/*! @{ */

#define PLL_PLLCR_PLLPD_MASK                     (0x80000000U)
#define PLL_PLLCR_PLLPD_SHIFT                    (31U)
/*! PLLPD - PLL Power Down
 *  0b0..Powered up
 *  0b1..Powered down
 */
#define PLL_PLLCR_PLLPD(x)                       (((uint32_t)(((uint32_t)(x)) << PLL_PLLCR_PLLPD_SHIFT)) & PLL_PLLCR_PLLPD_MASK)
/*! @} */

/*! @name PLLSR - PLL Status */
/*! @{ */

#define PLL_PLLSR_LOCK_MASK                      (0x4U)
#define PLL_PLLSR_LOCK_SHIFT                     (2U)
/*! LOCK - Lock Status
 *  0b0..Unlocked
 *  0b1..Locked
 */
#define PLL_PLLSR_LOCK(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_PLLSR_LOCK_SHIFT)) & PLL_PLLSR_LOCK_MASK)

#define PLL_PLLSR_LOL_MASK                       (0x8U)
#define PLL_PLLSR_LOL_SHIFT                      (3U)
/*! LOL - Loss-Of-Lock Flag
 *  0b0..No loss of lock detected
 *  0b1..Loss of lock detected
 */
#define PLL_PLLSR_LOL(x)                         (((uint32_t)(((uint32_t)(x)) << PLL_PLLSR_LOL_SHIFT)) & PLL_PLLSR_LOL_MASK)
/*! @} */

/*! @name PLLDV - PLL Divider */
/*! @{ */

#define PLL_PLLDV_MFI_MASK                       (0xFFU)
#define PLL_PLLDV_MFI_SHIFT                      (0U)
/*! MFI - Integer Portion Of Loop Divider */
#define PLL_PLLDV_MFI(x)                         (((uint32_t)(((uint32_t)(x)) << PLL_PLLDV_MFI_SHIFT)) & PLL_PLLDV_MFI_MASK)

#define PLL_PLLDV_RDIV_MASK                      (0x7000U)
#define PLL_PLLDV_RDIV_SHIFT                     (12U)
/*! RDIV - Input Clock Predivider
 *  0b000..Divide by 1
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 3
 *  0b100..Divide by 4
 *  0b101..Divide by 5
 *  0b110..Divide by 6
 *  0b111..Divide by 7
 */
#define PLL_PLLDV_RDIV(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_PLLDV_RDIV_SHIFT)) & PLL_PLLDV_RDIV_MASK)

#define PLL_PLLDV_ODIV2_MASK                     (0x7E000000U)
#define PLL_PLLDV_ODIV2_SHIFT                    (25U)
/*! ODIV2 - Output frequency divider for raw PLL clock. */
#define PLL_PLLDV_ODIV2(x)                       (((uint32_t)(((uint32_t)(x)) << PLL_PLLDV_ODIV2_SHIFT)) & PLL_PLLDV_ODIV2_MASK)
/*! @} */

/*! @name PLLFM - PLL Frequency Modulation */
/*! @{ */

#define PLL_PLLFM_STEPNO_MASK                    (0x7FFU)
#define PLL_PLLFM_STEPNO_SHIFT                   (0U)
/*! STEPNO - Number Of Steps Of Modulation Period Or Frequency Modulation */
#define PLL_PLLFM_STEPNO(x)                      (((uint32_t)(((uint32_t)(x)) << PLL_PLLFM_STEPNO_SHIFT)) & PLL_PLLFM_STEPNO_MASK)

#define PLL_PLLFM_STEPSIZE_MASK                  (0x3FF0000U)
#define PLL_PLLFM_STEPSIZE_SHIFT                 (16U)
/*! STEPSIZE - Frequency Modulation Step Size */
#define PLL_PLLFM_STEPSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_PLLFM_STEPSIZE_SHIFT)) & PLL_PLLFM_STEPSIZE_MASK)

#define PLL_PLLFM_SPREADCTL_MASK                 (0x20000000U)
#define PLL_PLLFM_SPREADCTL_SHIFT                (29U)
/*! SPREADCTL - Modulation Type Selection
 *  0b0..Reserved
 *  0b1..Spread below nominal frequency
 */
#define PLL_PLLFM_SPREADCTL(x)                   (((uint32_t)(((uint32_t)(x)) << PLL_PLLFM_SPREADCTL_SHIFT)) & PLL_PLLFM_SPREADCTL_MASK)

#define PLL_PLLFM_SSCGBYP_MASK                   (0x40000000U)
#define PLL_PLLFM_SSCGBYP_SHIFT                  (30U)
/*! SSCGBYP - Frequency Modulation (Spread Spectrum Clock Generation) Bypass
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define PLL_PLLFM_SSCGBYP(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_PLLFM_SSCGBYP_SHIFT)) & PLL_PLLFM_SSCGBYP_MASK)
/*! @} */

/*! @name PLLFD - PLL Fractional Divider */
/*! @{ */

#define PLL_PLLFD_MFN_MASK                       (0x7FFFU)
#define PLL_PLLFD_MFN_SHIFT                      (0U)
/*! MFN - Numerator Of Fractional Loop Division Factor */
#define PLL_PLLFD_MFN(x)                         (((uint32_t)(((uint32_t)(x)) << PLL_PLLFD_MFN_SHIFT)) & PLL_PLLFD_MFN_MASK)

#define PLL_PLLFD_SDM3_MASK                      (0x10000000U)
#define PLL_PLLFD_SDM3_SHIFT                     (28U)
/*! SDM3 - Fractional Mode Configuration */
#define PLL_PLLFD_SDM3(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_PLLFD_SDM3_SHIFT)) & PLL_PLLFD_SDM3_MASK)

#define PLL_PLLFD_SDM2_MASK                      (0x20000000U)
#define PLL_PLLFD_SDM2_SHIFT                     (29U)
/*! SDM2 - Fractional Mode Configuration */
#define PLL_PLLFD_SDM2(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_PLLFD_SDM2_SHIFT)) & PLL_PLLFD_SDM2_MASK)

#define PLL_PLLFD_SDMEN_MASK                     (0x40000000U)
#define PLL_PLLFD_SDMEN_SHIFT                    (30U)
/*! SDMEN - Fractional Mode Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PLL_PLLFD_SDMEN(x)                       (((uint32_t)(((uint32_t)(x)) << PLL_PLLFD_SDMEN_SHIFT)) & PLL_PLLFD_SDMEN_MASK)
/*! @} */

/*! @name PLLCAL2 - PLL Calibration Register 2 */
/*! @{ */

#define PLL_PLLCAL2_ULKCTL_MASK                  (0x180U)
#define PLL_PLLCAL2_ULKCTL_SHIFT                 (7U)
/*! ULKCTL - Unlock Control Accuracy
 *  0b00..Unlock range = Expected value +/- 9 (recommended when PLLFM[SSCGBYP] = 1)
 *  0b01..Unlock range = Expected value +/- 17 (recommended when PLLFM[SSCGBYP] = 0)
 *  0b10..Unlock range = Expected value +/- 33
 *  0b11..Unlock range = Expected value +/- 5
 */
#define PLL_PLLCAL2_ULKCTL(x)                    (((uint32_t)(((uint32_t)(x)) << PLL_PLLCAL2_ULKCTL_SHIFT)) & PLL_PLLCAL2_ULKCTL_MASK)
/*! @} */

/*! @name PLLODIV - PLL Output Divider */
/*! @{ */

#define PLL_PLLODIV_DIV_MASK                     (0xF0000U)
#define PLL_PLLODIV_DIV_SHIFT                    (16U)
/*! DIV - Division Value */
#define PLL_PLLODIV_DIV(x)                       (((uint32_t)(((uint32_t)(x)) << PLL_PLLODIV_DIV_SHIFT)) & PLL_PLLODIV_DIV_MASK)

#define PLL_PLLODIV_DE_MASK                      (0x80000000U)
#define PLL_PLLODIV_DE_SHIFT                     (31U)
/*! DE - Divider Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PLL_PLLODIV_DE(x)                        (((uint32_t)(((uint32_t)(x)) << PLL_PLLODIV_DE_SHIFT)) & PLL_PLLODIV_DE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLL_Register_Masks */


/*!
 * @}
 */ /* end of group PLL_Peripheral_Access_Layer */


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


#endif  /* PERI_PLL_H_ */

