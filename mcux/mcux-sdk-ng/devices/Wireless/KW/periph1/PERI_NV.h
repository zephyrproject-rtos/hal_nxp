/*
** ###################################################################
**     Processors:          MKW21D256VHA5
**                          MKW21D512VHA5
**                          MKW22D512VHA5
**                          MKW24D512VHA5
**
**     Version:             rev. 2.0, 2015-01-06
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NV
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2013-11-22)
**         Initial version.
**     - rev. 2.0 (2015-01-06)
**         update of SystemInit() imlementation
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**         Register accessor macros added to the memory map.
**         MCG - bit LOLS in MCG_S register renamed to LOLS0.
**         DAC0 registers removed.
**
** ###################################################################
*/

/*!
 * @file NV.h
 * @version 2.0
 * @date 2015-01-06
 * @brief CMSIS Peripheral Access Layer for NV
 *
 * CMSIS Peripheral Access Layer for NV
 */

#if !defined(NV_H_)
#define NV_H_                                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5_COMMON.h"
#elif (defined(CPU_MKW21D256VHA5) || defined(CPU_MKW21D512VHA5))
#include "MKW21D5WS_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5_COMMON.h"
#elif (defined(CPU_MKW22D512VHA5))
#include "MKW22D5WS_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5_COMMON.h"
#elif (defined(CPU_MKW24D512VHA5))
#include "MKW24D5WS_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3., offset: 0x0 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2., offset: 0x1 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1., offset: 0x2 */
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0., offset: 0x3 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7., offset: 0x4 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6., offset: 0x5 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5., offset: 0x6 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4., offset: 0x7 */
  __I  uint8_t FPROT3;                             /**< Non-volatile P-Flash Protection 1 - Low Register, offset: 0x8 */
  __I  uint8_t FPROT2;                             /**< Non-volatile P-Flash Protection 1 - High Register, offset: 0x9 */
  __I  uint8_t FPROT1;                             /**< Non-volatile P-Flash Protection 0 - Low Register, offset: 0xA */
  __I  uint8_t FPROT0;                             /**< Non-volatile P-Flash Protection 0 - High Register, offset: 0xB */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xC */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xD */
  __I  uint8_t FEPROT;                             /**< Non-volatile EERAM Protection Register, offset: 0xE */
  __I  uint8_t FDPROT;                             /**< Non-volatile D-Flash Protection Register, offset: 0xF */
} NV_Type;

/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/*! @name BACKKEY3 - Backdoor Comparison Key 3. */
/*! @{ */

#define NV_BACKKEY3_KEY_MASK                     (0xFFU)
#define NV_BACKKEY3_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY3_KEY_SHIFT)) & NV_BACKKEY3_KEY_MASK)
/*! @} */

/*! @name BACKKEY2 - Backdoor Comparison Key 2. */
/*! @{ */

#define NV_BACKKEY2_KEY_MASK                     (0xFFU)
#define NV_BACKKEY2_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY2_KEY_SHIFT)) & NV_BACKKEY2_KEY_MASK)
/*! @} */

/*! @name BACKKEY1 - Backdoor Comparison Key 1. */
/*! @{ */

#define NV_BACKKEY1_KEY_MASK                     (0xFFU)
#define NV_BACKKEY1_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY1_KEY_SHIFT)) & NV_BACKKEY1_KEY_MASK)
/*! @} */

/*! @name BACKKEY0 - Backdoor Comparison Key 0. */
/*! @{ */

#define NV_BACKKEY0_KEY_MASK                     (0xFFU)
#define NV_BACKKEY0_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY0_KEY_SHIFT)) & NV_BACKKEY0_KEY_MASK)
/*! @} */

/*! @name BACKKEY7 - Backdoor Comparison Key 7. */
/*! @{ */

#define NV_BACKKEY7_KEY_MASK                     (0xFFU)
#define NV_BACKKEY7_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY7_KEY_SHIFT)) & NV_BACKKEY7_KEY_MASK)
/*! @} */

/*! @name BACKKEY6 - Backdoor Comparison Key 6. */
/*! @{ */

#define NV_BACKKEY6_KEY_MASK                     (0xFFU)
#define NV_BACKKEY6_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY6_KEY_SHIFT)) & NV_BACKKEY6_KEY_MASK)
/*! @} */

/*! @name BACKKEY5 - Backdoor Comparison Key 5. */
/*! @{ */

#define NV_BACKKEY5_KEY_MASK                     (0xFFU)
#define NV_BACKKEY5_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY5_KEY_SHIFT)) & NV_BACKKEY5_KEY_MASK)
/*! @} */

/*! @name BACKKEY4 - Backdoor Comparison Key 4. */
/*! @{ */

#define NV_BACKKEY4_KEY_MASK                     (0xFFU)
#define NV_BACKKEY4_KEY_SHIFT                    (0U)
/*! KEY - Backdoor Comparison Key. */
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x)) << NV_BACKKEY4_KEY_SHIFT)) & NV_BACKKEY4_KEY_MASK)
/*! @} */

/*! @name FPROT3 - Non-volatile P-Flash Protection 1 - Low Register */
/*! @{ */

#define NV_FPROT3_PROT_MASK                      (0xFFU)
#define NV_FPROT3_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT3_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT3_PROT_SHIFT)) & NV_FPROT3_PROT_MASK)
/*! @} */

/*! @name FPROT2 - Non-volatile P-Flash Protection 1 - High Register */
/*! @{ */

#define NV_FPROT2_PROT_MASK                      (0xFFU)
#define NV_FPROT2_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT2_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT2_PROT_SHIFT)) & NV_FPROT2_PROT_MASK)
/*! @} */

/*! @name FPROT1 - Non-volatile P-Flash Protection 0 - Low Register */
/*! @{ */

#define NV_FPROT1_PROT_MASK                      (0xFFU)
#define NV_FPROT1_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT1_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT1_PROT_SHIFT)) & NV_FPROT1_PROT_MASK)
/*! @} */

/*! @name FPROT0 - Non-volatile P-Flash Protection 0 - High Register */
/*! @{ */

#define NV_FPROT0_PROT_MASK                      (0xFFU)
#define NV_FPROT0_PROT_SHIFT                     (0U)
/*! PROT - P-Flash Region Protect */
#define NV_FPROT0_PROT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FPROT0_PROT_SHIFT)) & NV_FPROT0_PROT_MASK)
/*! @} */

/*! @name FSEC - Non-volatile Flash Security Register */
/*! @{ */

#define NV_FSEC_SEC_MASK                         (0x3U)
#define NV_FSEC_SEC_SHIFT                        (0U)
/*! SEC - Flash Security
 *  0b10..MCU security status is unsecure
 *  0b11..MCU security status is secure
 */
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x)) << NV_FSEC_SEC_SHIFT)) & NV_FSEC_SEC_MASK)

#define NV_FSEC_FSLACC_MASK                      (0xCU)
#define NV_FSEC_FSLACC_SHIFT                     (2U)
/*! FSLACC - Freescale Failure Analysis Access Code
 *  0b10..Freescale factory access denied
 *  0b11..Freescale factory access granted
 */
#define NV_FSEC_FSLACC(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FSEC_FSLACC_SHIFT)) & NV_FSEC_FSLACC_MASK)

#define NV_FSEC_MEEN_MASK                        (0x30U)
#define NV_FSEC_MEEN_SHIFT                       (4U)
/*! MEEN
 *  0b10..Mass erase is disabled
 *  0b11..Mass erase is enabled
 */
#define NV_FSEC_MEEN(x)                          (((uint8_t)(((uint8_t)(x)) << NV_FSEC_MEEN_SHIFT)) & NV_FSEC_MEEN_MASK)

#define NV_FSEC_KEYEN_MASK                       (0xC0U)
#define NV_FSEC_KEYEN_SHIFT                      (6U)
/*! KEYEN - Backdoor Key Security Enable
 *  0b10..Backdoor key access enabled
 *  0b11..Backdoor key access disabled
 */
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x)) << NV_FSEC_KEYEN_SHIFT)) & NV_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FOPT - Non-volatile Flash Option Register */
/*! @{ */

#define NV_FOPT_LPBOOT_MASK                      (0x1U)
#define NV_FOPT_LPBOOT_SHIFT                     (0U)
/*! LPBOOT
 *  0b0..Low-power boot
 *  0b1..Normal boot
 */
#define NV_FOPT_LPBOOT(x)                        (((uint8_t)(((uint8_t)(x)) << NV_FOPT_LPBOOT_SHIFT)) & NV_FOPT_LPBOOT_MASK)

#define NV_FOPT_EZPORT_DIS_MASK                  (0x2U)
#define NV_FOPT_EZPORT_DIS_SHIFT                 (1U)
/*! EZPORT_DIS
 *  0b0..EzPort operation is disabled
 *  0b1..EzPort operation is enabled
 */
#define NV_FOPT_EZPORT_DIS(x)                    (((uint8_t)(((uint8_t)(x)) << NV_FOPT_EZPORT_DIS_SHIFT)) & NV_FOPT_EZPORT_DIS_MASK)

#define NV_FOPT_NMI_DIS_MASK                     (0x4U)
#define NV_FOPT_NMI_DIS_SHIFT                    (2U)
/*! NMI_DIS
 *  0b0..NMI interrupts are always blocked
 *  0b1..NMI_b pin/interrupts reset default to enabled
 */
#define NV_FOPT_NMI_DIS(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FOPT_NMI_DIS_SHIFT)) & NV_FOPT_NMI_DIS_MASK)
/*! @} */

/*! @name FEPROT - Non-volatile EERAM Protection Register */
/*! @{ */

#define NV_FEPROT_EPROT_MASK                     (0xFFU)
#define NV_FEPROT_EPROT_SHIFT                    (0U)
#define NV_FEPROT_EPROT(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FEPROT_EPROT_SHIFT)) & NV_FEPROT_EPROT_MASK)
/*! @} */

/*! @name FDPROT - Non-volatile D-Flash Protection Register */
/*! @{ */

#define NV_FDPROT_DPROT_MASK                     (0xFFU)
#define NV_FDPROT_DPROT_SHIFT                    (0U)
/*! DPROT - D-Flash Region Protect */
#define NV_FDPROT_DPROT(x)                       (((uint8_t)(((uint8_t)(x)) << NV_FDPROT_DPROT_SHIFT)) & NV_FDPROT_DPROT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NV_Register_Masks */


/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* NV_H_ */

