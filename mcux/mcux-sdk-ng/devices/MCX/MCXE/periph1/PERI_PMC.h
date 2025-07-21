/*
** ###################################################################
**     Processor:           MCXE31BMPB
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
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVSC;                              /**< Low Voltage Status and Control Register, offset: 0x0 */
  __IO uint32_t CONFIG;                            /**< PMC Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[4];
  __I  uint32_t VERID;                             /**< Version ID register, offset: 0xC */
} PMC_Type;

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVSC - Low Voltage Status and Control Register */
/*! @{ */

#define PMC_LVSC_HVDAF_MASK                      (0x1U)
#define PMC_LVSC_HVDAF_SHIFT                     (0U)
/*! HVDAF - HVDA flag on VDD_HV_A domain in FPM
 *  0b0..HVDAS has not changed.
 *  0b1..HVDAS has changed.
 */
#define PMC_LVSC_HVDAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAF_SHIFT)) & PMC_LVSC_HVDAF_MASK)

#define PMC_LVSC_HVDBF_MASK                      (0x2U)
#define PMC_LVSC_HVDBF_SHIFT                     (1U)
/*! HVDBF - HVDB flag on VDD_HV_B domain in FPM
 *  0b0..HVDBS has not changed.
 *  0b1..HVDBS has changed.
 */
#define PMC_LVSC_HVDBF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDBF_SHIFT)) & PMC_LVSC_HVDBF_MASK)

#define PMC_LVSC_HVD25F_MASK                     (0x4U)
#define PMC_LVSC_HVD25F_SHIFT                    (2U)
/*! HVD25F - HVD25 flag on V25 domain in FPM
 *  0b0..HVD25S has not changed.
 *  0b1..HVD25S has changed.
 */
#define PMC_LVSC_HVD25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25F_SHIFT)) & PMC_LVSC_HVD25F_MASK)

#define PMC_LVSC_HVD11F_MASK                     (0x8U)
#define PMC_LVSC_HVD11F_SHIFT                    (3U)
/*! HVD11F - HVD11 flag on V11 domain in FPM
 *  0b0..HVD11S has not changed.
 *  0b1..HVD11S has changed.
 */
#define PMC_LVSC_HVD11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11F_SHIFT)) & PMC_LVSC_HVD11F_MASK)

#define PMC_LVSC_LVD5AF_MASK                     (0x10U)
#define PMC_LVSC_LVD5AF_SHIFT                    (4U)
/*! LVD5AF - LVD5A flag on VDD_HV_A domain in FPM
 *  0b0..LVD5AS has not changed.
 *  0b1..LVD5AS has changed.
 */
#define PMC_LVSC_LVD5AF(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AF_SHIFT)) & PMC_LVSC_LVD5AF_MASK)

#define PMC_LVSC_LVD15F_MASK                     (0x20U)
#define PMC_LVSC_LVD15F_SHIFT                    (5U)
/*! LVD15F - LVD15 flag on V15 domain in FPM
 *  0b0..LVD15S has not changed.
 *  0b1..LVD15S has changed.
 */
#define PMC_LVSC_LVD15F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD15F_SHIFT)) & PMC_LVSC_LVD15F_MASK)

#define PMC_LVSC_HVDAS_MASK                      (0x100U)
#define PMC_LVSC_HVDAS_SHIFT                     (8U)
/*! HVDAS - HVDA status on VDD_HV_A domain in FPM
 *  0b0..Voltage on VDD_HV_A is below high-voltage detect threshold or LPM.
 *  0b1..Voltage on VDD_HV_A is above high-voltage detect threshold and FPM.
 */
#define PMC_LVSC_HVDAS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDAS_SHIFT)) & PMC_LVSC_HVDAS_MASK)

#define PMC_LVSC_HVDBS_MASK                      (0x200U)
#define PMC_LVSC_HVDBS_SHIFT                     (9U)
/*! HVDBS - HVDB status on VDD_HV_B domain in FPM
 *  0b0..Voltage on VDD_HV_B is below high-voltage detect threshold or LPM.
 *  0b1..Voltage on VDD_HV_B is above high-voltage detect threshold and FPM.
 */
#define PMC_LVSC_HVDBS(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVDBS_SHIFT)) & PMC_LVSC_HVDBS_MASK)

#define PMC_LVSC_HVD25S_MASK                     (0x400U)
#define PMC_LVSC_HVD25S_SHIFT                    (10U)
/*! HVD25S - HVD25 status on V25 domain in FPM
 *  0b0..Voltage on V25 is below high-voltage detect threshold or LPM.
 *  0b1..Voltage on V25 is above high-voltage detect threshold and FPM.
 */
#define PMC_LVSC_HVD25S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD25S_SHIFT)) & PMC_LVSC_HVD25S_MASK)

#define PMC_LVSC_HVD11S_MASK                     (0x800U)
#define PMC_LVSC_HVD11S_SHIFT                    (11U)
/*! HVD11S - HVD11 status on V11 domain in FPM
 *  0b0..Voltage on V11 is below high-voltage detect threshold or LPM.
 *  0b1..Voltage on V11 is above high-voltage detect threshold and FPM.
 */
#define PMC_LVSC_HVD11S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_HVD11S_SHIFT)) & PMC_LVSC_HVD11S_MASK)

#define PMC_LVSC_LVD5AS_MASK                     (0x1000U)
#define PMC_LVSC_LVD5AS_SHIFT                    (12U)
/*! LVD5AS - LVD5A status on VDD_HV_A domain in FPM
 *  0b0..Voltage on VDD_HV_A is above low-voltage detect threshold
 *  0b1..Voltage on VDD_HV_A is below low-voltage detect threshold
 */
#define PMC_LVSC_LVD5AS(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD5AS_SHIFT)) & PMC_LVSC_LVD5AS_MASK)

#define PMC_LVSC_LVD15S_MASK                     (0x2000U)
#define PMC_LVSC_LVD15S_SHIFT                    (13U)
/*! LVD15S - LVD15 status on V15 domain in FPM
 *  0b0..Voltage on V15 is above low-voltage detect threshold or LPM.
 *  0b1..Voltage on V15 is below low-voltage detect threshold and FPM.
 */
#define PMC_LVSC_LVD15S(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVD15S_SHIFT)) & PMC_LVSC_LVD15S_MASK)

#define PMC_LVSC_LVRAF_MASK                      (0x10000U)
#define PMC_LVSC_LVRAF_SHIFT                     (16U)
/*! LVRAF - LVRA flag on VDD_HV_A domain in FPM
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVRAF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRAF_SHIFT)) & PMC_LVSC_LVRAF_MASK)

#define PMC_LVSC_LVRALPF_MASK                    (0x20000U)
#define PMC_LVSC_LVRALPF_SHIFT                   (17U)
/*! LVRALPF - LVRALP flag on VDD_HV_A domain
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVRALPF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRALPF_SHIFT)) & PMC_LVSC_LVRALPF_MASK)

#define PMC_LVSC_LVRBF_MASK                      (0x40000U)
#define PMC_LVSC_LVRBF_SHIFT                     (18U)
/*! LVRBF - LVRB flag on VDD_HV_B domain in FPM
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVRBF(x)                        (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRBF_SHIFT)) & PMC_LVSC_LVRBF_MASK)

#define PMC_LVSC_LVRBLPF_MASK                    (0x80000U)
#define PMC_LVSC_LVRBLPF_SHIFT                   (19U)
/*! LVRBLPF - LVRBLP flag on VDD_HV_B domain
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVRBLPF(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVRBLPF_SHIFT)) & PMC_LVSC_LVRBLPF_MASK)

#define PMC_LVSC_LVR25F_MASK                     (0x100000U)
#define PMC_LVSC_LVR25F_SHIFT                    (20U)
/*! LVR25F - LVR25 flag on V25 domain in FPM
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVR25F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25F_SHIFT)) & PMC_LVSC_LVR25F_MASK)

#define PMC_LVSC_LVR25LPF_MASK                   (0x200000U)
#define PMC_LVSC_LVR25LPF_SHIFT                  (21U)
/*! LVR25LPF - LVR25LP flag on V25 domain
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVR25LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR25LPF_SHIFT)) & PMC_LVSC_LVR25LPF_MASK)

#define PMC_LVSC_LVR11F_MASK                     (0x400000U)
#define PMC_LVSC_LVR11F_SHIFT                    (22U)
/*! LVR11F - LVR11 flag on V11 domain in FPM
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVR11F(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11F_SHIFT)) & PMC_LVSC_LVR11F_MASK)

#define PMC_LVSC_LVR11LPF_MASK                   (0x800000U)
#define PMC_LVSC_LVR11LPF_SHIFT                  (23U)
/*! LVR11LPF - LVR11LP flag on V11 domain
 *  0b0..No low-voltage reset event has occurred
 *  0b1..Low-voltage reset event has occurred
 */
#define PMC_LVSC_LVR11LPF(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_LVR11LPF_SHIFT)) & PMC_LVSC_LVR11LPF_MASK)

#define PMC_LVSC_GNG25OSCF_MASK                  (0x1000000U)
#define PMC_LVSC_GNG25OSCF_SHIFT                 (24U)
/*! GNG25OSCF - GO/NoGo detect flag on Osc part of V25 domain
 *  0b0..No event has occurred
 *  0b1..NoGo event has occurred
 */
#define PMC_LVSC_GNG25OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG25OSCF_SHIFT)) & PMC_LVSC_GNG25OSCF_MASK)

#define PMC_LVSC_GNG11OSCF_MASK                  (0x2000000U)
#define PMC_LVSC_GNG11OSCF_SHIFT                 (25U)
/*! GNG11OSCF - Go/NoGo detect flag on Osc part of V11 domain
 *  0b0..No event has occurred
 *  0b1..NoGo event has occurred
 */
#define PMC_LVSC_GNG11OSCF(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_GNG11OSCF_SHIFT)) & PMC_LVSC_GNG11OSCF_MASK)

#define PMC_LVSC_PORF_MASK                       (0x80000000U)
#define PMC_LVSC_PORF_SHIFT                      (31U)
/*! PORF - POR flag
 *  0b0..No power-on reset event has occurred
 *  0b1..Power-on reset event has occurred
 */
#define PMC_LVSC_PORF(x)                         (((uint32_t)(((uint32_t)(x)) << PMC_LVSC_PORF_SHIFT)) & PMC_LVSC_PORF_MASK)
/*! @} */

/*! @name CONFIG - PMC Configuration Register */
/*! @{ */

#define PMC_CONFIG_LMEN_MASK                     (0x1U)
#define PMC_CONFIG_LMEN_SHIFT                    (0U)
/*! LMEN - Last Mile regulator enable bit
 *  0b0..Last Mile regulator is disabled.
 *  0b1..Last Mile regulator is enabled.
 */
#define PMC_CONFIG_LMEN(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LMEN_SHIFT)) & PMC_CONFIG_LMEN_MASK)

#define PMC_CONFIG_LMBCTLEN_MASK                 (0x2U)
#define PMC_CONFIG_LMBCTLEN_SHIFT                (1U)
/*! LMBCTLEN - Last Mile regulator base control enable bit
 *  0b0..External BCTL regulator for V15 disabled
 *  0b1..External BCTL regulator for V15 enabled
 */
#define PMC_CONFIG_LMBCTLEN(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LMBCTLEN_SHIFT)) & PMC_CONFIG_LMBCTLEN_MASK)

#define PMC_CONFIG_FASTREC_MASK                  (0x4U)
#define PMC_CONFIG_FASTREC_SHIFT                 (2U)
/*! FASTREC - Fast recovery from LPM enable bit
 *  0b0..Normal recovery time from LPM
 *  0b1..Fast recovery time from LPM
 */
#define PMC_CONFIG_FASTREC(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_FASTREC_SHIFT)) & PMC_CONFIG_FASTREC_MASK)

#define PMC_CONFIG_LPM25EN_MASK                  (0x8U)
#define PMC_CONFIG_LPM25EN_SHIFT                 (3U)
/*! LPM25EN - V25 domain enable bit during LPM
 *  0b0..V25 regulator and LVR25LP are disabled in LPM.
 *  0b1..V25 regulator and LVR25LP are enabled in LPM.
 */
#define PMC_CONFIG_LPM25EN(x)                    (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LPM25EN_SHIFT)) & PMC_CONFIG_LPM25EN_MASK)

#define PMC_CONFIG_LVRBLPEN_MASK                 (0x10U)
#define PMC_CONFIG_LVRBLPEN_SHIFT                (4U)
/*! LVRBLPEN - LVRBLP enable bit during LPM
 *  0b0..Low-voltage reset detection is disabled in LPM.
 *  0b1..Low-voltage reset detection is enabled in LPM.
 */
#define PMC_CONFIG_LVRBLPEN(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVRBLPEN_SHIFT)) & PMC_CONFIG_LVRBLPEN_MASK)

#define PMC_CONFIG_HVDIE_MASK                    (0x100U)
#define PMC_CONFIG_HVDIE_SHIFT                   (8U)
/*! HVDIE - High voltage detect interrupt enable
 *  0b0..HVD hardware interrupt is disabled (use polling).
 *  0b1..Request an HVD hardware interrupt when HVDAF=1, HVDBF=1, HVD25F=1, or HVD11F=1.
 */
#define PMC_CONFIG_HVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_HVDIE_SHIFT)) & PMC_CONFIG_HVDIE_MASK)

#define PMC_CONFIG_LVDIE_MASK                    (0x200U)
#define PMC_CONFIG_LVDIE_SHIFT                   (9U)
/*! LVDIE - Low voltage detect interrupt enable
 *  0b0..LVD hardware interrupt is disabled (use polling).
 *  0b1..Request an LVD hardware interrupt when LVDA5F=1 or LVD15F=1.
 */
#define PMC_CONFIG_LVDIE(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LVDIE_SHIFT)) & PMC_CONFIG_LVDIE_MASK)

#define PMC_CONFIG_LMAUTOEN_MASK                 (0x10000U)
#define PMC_CONFIG_LMAUTOEN_SHIFT                (16U)
/*! LMAUTOEN - Last Mile regulator auto turn over bit
 *  0b0..Auto turnover disabled
 *  0b1..Auto turnover enabled
 */
#define PMC_CONFIG_LMAUTOEN(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LMAUTOEN_SHIFT)) & PMC_CONFIG_LMAUTOEN_MASK)

#define PMC_CONFIG_LMSTAT_MASK                   (0x20000U)
#define PMC_CONFIG_LMSTAT_SHIFT                  (17U)
/*! LMSTAT - Last Mile regulator status bit
 *  0b0..Last Mile Regulator is off
 *  0b1..Last Mile Regulator is on
 */
#define PMC_CONFIG_LMSTAT(x)                     (((uint32_t)(((uint32_t)(x)) << PMC_CONFIG_LMSTAT_SHIFT)) & PMC_CONFIG_LMSTAT_MASK)
/*! @} */

/*! @name VERID - Version ID register */
/*! @{ */

#define PMC_VERID_LMFEAT_MASK                    (0x1U)
#define PMC_VERID_LMFEAT_SHIFT                   (0U)
/*! LMFEAT - Last Mile Regulator Feature
 *  0b0..No Last Mile regulator
 *  0b1..Last Mile regulator (1.5V to 1.1V) is available
 */
#define PMC_VERID_LMFEAT(x)                      (((uint32_t)(((uint32_t)(x)) << PMC_VERID_LMFEAT_SHIFT)) & PMC_VERID_LMFEAT_MASK)

#define PMC_VERID_MINOR_MASK                     (0xFF0000U)
#define PMC_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor version number */
#define PMC_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PMC_VERID_MINOR_SHIFT)) & PMC_VERID_MINOR_MASK)

#define PMC_VERID_MAJOR_MASK                     (0xFF000000U)
#define PMC_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major version number */
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

