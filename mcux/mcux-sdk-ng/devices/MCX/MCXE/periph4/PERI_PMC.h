/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PMC
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
 * @file PERI_PMC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for PMC
 *
 * CMSIS Peripheral Access Layer for PMC
 */

#if !defined(PERI_PMC_H_)
#define PERI_PMC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVSC;                              /**< Low Voltage Status And Control, offset: 0x0 */
  __IO uint32_t CONFIG;                            /**< PMC Configuration, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __I  uint32_t VERID;                             /**< Version ID, offset: 0xC */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVSC - Low Voltage Status And Control */
/*! @{ */

#define PMC_LVSC_HVDAF_MASK                      (0x1U)
#define PMC_LVSC_HVDAF_SHIFT                     (0U)
/*! HVDAF - HVDA Flag On VDD_HV_A Power Domain In FPM
 *  0b0..Did not change
 *  0b0..No effect
 *  0b1..Changed
 *  0b1..Clear the flag
 */
#define PMC_LVSC_HVDAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAF_SHIFT)) & PMC_LVSC_HVDAF_MASK)

#define PMC_LVSC_HVD25F_MASK                     (0x4U)
#define PMC_LVSC_HVD25F_SHIFT                    (2U)
/*! HVD25F - HVD25 Flag On V25 Power Domain In FPM
 *  0b0..Did not change
 *  0b0..No effect
 *  0b1..Changed
 *  0b1..Clear the flag
 */
#define PMC_LVSC_HVD25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25F_SHIFT)) & PMC_LVSC_HVD25F_MASK)

#define PMC_LVSC_HVD11F_MASK                     (0x8U)
#define PMC_LVSC_HVD11F_SHIFT                    (3U)
/*! HVD11F - HVD11 Flag On V11 Power Domain In FPM
 *  0b0..Did not change
 *  0b0..No effect
 *  0b1..Changed
 *  0b1..Clear the flag
 */
#define PMC_LVSC_HVD11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11F_SHIFT)) & PMC_LVSC_HVD11F_MASK)

#define PMC_LVSC_LVD5AF_MASK                     (0x10U)
#define PMC_LVSC_LVD5AF_SHIFT                    (4U)
/*! LVD5AF - LVD5A Flag On VDD_HV_A Power Domain In FPM
 *  0b0..Did not change
 *  0b0..No effect
 *  0b1..Changed
 *  0b1..Clear the flag
 */
#define PMC_LVSC_LVD5AF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AF_SHIFT)) & PMC_LVSC_LVD5AF_MASK)

#define PMC_LVSC_HVDAS_MASK                      (0x100U)
#define PMC_LVSC_HVDAS_SHIFT                     (8U)
/*! HVDAS - HVDA Status On VDD_HV_A Power Domain In FPM
 *  0b0..Voltage is below threshold or chip is in LPM
 *  0b1..Voltage is above threshold and chip is in FPM
 */
#define PMC_LVSC_HVDAS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAS_SHIFT)) & PMC_LVSC_HVDAS_MASK)

#define PMC_LVSC_HVD25S_MASK                     (0x400U)
#define PMC_LVSC_HVD25S_SHIFT                    (10U)
/*! HVD25S - HVD25 Status On V25 Power Domain In FPM
 *  0b0..Voltage is below threshold or chip is in LPM
 *  0b1..Voltage is above threshold and chip is in FPM
 */
#define PMC_LVSC_HVD25S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25S_SHIFT)) & PMC_LVSC_HVD25S_MASK)

#define PMC_LVSC_HVD11S_MASK                     (0x800U)
#define PMC_LVSC_HVD11S_SHIFT                    (11U)
/*! HVD11S - HVD11 Status On V11 Power Domain In FPM
 *  0b0..Voltage is below threshold or chip is in LPM
 *  0b1..Voltage is above threshold and chip is in FPM
 */
#define PMC_LVSC_HVD11S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11S_SHIFT)) & PMC_LVSC_HVD11S_MASK)

#define PMC_LVSC_LVD5AS_MASK                     (0x1000U)
#define PMC_LVSC_LVD5AS_SHIFT                    (12U)
/*! LVD5AS - LVD5A Status On VDD_HV_A Power Domain In FPM
 *  0b0..Above
 *  0b1..Below
 */
#define PMC_LVSC_LVD5AS(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AS_SHIFT)) & PMC_LVSC_LVD5AS_MASK)

#define PMC_LVSC_LVRAF_MASK                      (0x10000U)
#define PMC_LVSC_LVRAF_SHIFT                     (16U)
/*! LVRAF - LVRA Flag On VDD_HV_A Power Domain In FPM
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVRAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRAF_SHIFT)) & PMC_LVSC_LVRAF_MASK)

#define PMC_LVSC_LVRALPF_MASK                    (0x20000U)
#define PMC_LVSC_LVRALPF_SHIFT                   (17U)
/*! LVRALPF - LVRALP Flag On VDD_HV_A Power Domain
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVRALPF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRALPF_SHIFT)) & PMC_LVSC_LVRALPF_MASK)

#define PMC_LVSC_LVR25F_MASK                     (0x100000U)
#define PMC_LVSC_LVR25F_SHIFT                    (20U)
/*! LVR25F - LVR25 Flag On V25 Power Domain In FPM
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVR25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25F_SHIFT)) & PMC_LVSC_LVR25F_MASK)

#define PMC_LVSC_LVR25LPF_MASK                   (0x200000U)
#define PMC_LVSC_LVR25LPF_SHIFT                  (21U)
/*! LVR25LPF - LVR25LP Flag On V25 Power Domain
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVR25LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25LPF_SHIFT)) & PMC_LVSC_LVR25LPF_MASK)

#define PMC_LVSC_LVR11F_MASK                     (0x400000U)
#define PMC_LVSC_LVR11F_SHIFT                    (22U)
/*! LVR11F - LVR11 Flag On V11 Power Domain In FPM
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVR11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11F_SHIFT)) & PMC_LVSC_LVR11F_MASK)

#define PMC_LVSC_LVR11LPF_MASK                   (0x800000U)
#define PMC_LVSC_LVR11LPF_SHIFT                  (23U)
/*! LVR11LPF - LVR11LP Flag On V11 Power Domain
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_LVR11LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11LPF_SHIFT)) & PMC_LVSC_LVR11LPF_MASK)

#define PMC_LVSC_GNG25OSCF_MASK                  (0x1000000U)
#define PMC_LVSC_GNG25OSCF_SHIFT                 (24U)
/*! GNG25OSCF - Go/No Go Detect Flag On OSC Part of V25 Power Domain
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_GNG25OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG25OSCF_SHIFT)) & PMC_LVSC_GNG25OSCF_MASK)

#define PMC_LVSC_GNG11OSCF_MASK                  (0x2000000U)
#define PMC_LVSC_GNG11OSCF_SHIFT                 (25U)
/*! GNG11OSCF - Go/No Go Detect Flag On OSC Part Of V11 Power Domain
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_GNG11OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG11OSCF_SHIFT)) & PMC_LVSC_GNG11OSCF_MASK)

#define PMC_LVSC_PORF_MASK                       (0x80000000U)
#define PMC_LVSC_PORF_SHIFT                      (31U)
/*! PORF - POR Flag
 *  0b0..Event did not occur
 *  0b0..No effect
 *  0b1..Clear the flag
 *  0b1..Event occurred
 */
#define PMC_LVSC_PORF(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_PORF_SHIFT)) & PMC_LVSC_PORF_MASK)
/*! @} */

/*! @name CONFIG - PMC Configuration */
/*! @{ */

#define PMC_CONFIG_FASTREC_MASK                  (0x4U)
#define PMC_CONFIG_FASTREC_SHIFT                 (2U)
/*! FASTREC - Fast Recovery From LPM Enable
 *  0b0..Normal
 *  0b1..Fast
 */
#define PMC_CONFIG_FASTREC(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_FASTREC_SHIFT)) & PMC_CONFIG_FASTREC_MASK)

#define PMC_CONFIG_LPM25EN_MASK                  (0x8U)
#define PMC_CONFIG_LPM25EN_SHIFT                 (3U)
/*! LPM25EN - V25 Power Domain Enable During LPM
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define PMC_CONFIG_LPM25EN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LPM25EN_SHIFT)) & PMC_CONFIG_LPM25EN_MASK)

#define PMC_CONFIG_HVDIE_MASK                    (0x100U)
#define PMC_CONFIG_HVDIE_SHIFT                   (8U)
/*! HVDIE - High Voltage Detect Interrupt Enable
 *  0b0..HVD hardware interrupt is disabled (use polling)
 *  0b1..Request an HVD hardware interrupt when HVDAF=1, HVDBF=1, HVD25F=1, or HVD11F=1
 */
#define PMC_CONFIG_HVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_HVDIE_SHIFT)) & PMC_CONFIG_HVDIE_MASK)

#define PMC_CONFIG_LVDIE_MASK                    (0x200U)
#define PMC_CONFIG_LVDIE_SHIFT                   (9U)
/*! LVDIE - Low Voltage Detect Interrupt Enable
 *  0b0..LVD hardware interrupt is disabled (use polling)
 *  0b1..Request an LVD hardware interrupt when LVDA5F = 1
 */
#define PMC_CONFIG_LVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVDIE_SHIFT)) & PMC_CONFIG_LVDIE_MASK)
/*! @} */

/*! @name VERID - Version ID */
/*! @{ */

#define PMC_VERID_LMFEAT_MASK                    (0x1U)
#define PMC_VERID_LMFEAT_SHIFT                   (0U)
/*! LMFEAT - Last-Mile Regulator Feature
 *  0b0..Not available
 *  0b1..Available
 */
#define PMC_VERID_LMFEAT(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_VERID_LMFEAT_SHIFT)) & PMC_VERID_LMFEAT_MASK)

#define PMC_VERID_MINOR_MASK                     (0xFF0000U)
#define PMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MINOR_SHIFT)) & PMC_VERID_MINOR_MASK)

#define PMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define PMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define PMC_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MAJOR_SHIFT)) & PMC_VERID_MAJOR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


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


#endif  /* PERI_PMC_H_ */

