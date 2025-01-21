/*
** ###################################################################
**     Processors:          MCXW727AMFTA_cm33_core0
**                          MCXW727AMFTA_cm33_core1
**                          MCXW727CMFTA_cm33_core0
**                          MCXW727CMFTA_cm33_core1
**                          MCXW727DMFTA_cm33_core0
**                          MCXW727DMFTA_cm33_core1
**
**     Version:             rev. 1.0, 2024-10-13
**     Build:               b241128
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VBAT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**
** ###################################################################
*/

/*!
 * @file VBAT.h
 * @version 1.0
 * @date 2024-10-13
 * @brief CMSIS Peripheral Access Layer for VBAT
 *
 * CMSIS Peripheral Access Layer for VBAT
 */

#if !defined(VBAT_H_)
#define VBAT_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW727AMFTA_cm33_core0))
#include "MCXW727A_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727AMFTA_cm33_core1))
#include "MCXW727A_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core0))
#include "MCXW727C_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core1))
#include "MCXW727C_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core0))
#include "MCXW727D_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core1))
#include "MCXW727D_cm33_core1_COMMON.h"
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
   -- VBAT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Peripheral_Access_Layer VBAT Peripheral Access Layer
 * @{
 */

/** VBAT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t STATUSA;                           /**< Status A, offset: 0x10 */
       uint8_t RESERVED_1[4];
  __IO uint32_t IRQENA;                            /**< Interrupt Enable A, offset: 0x18 */
       uint8_t RESERVED_2[4];
  __IO uint32_t WAKENA;                            /**< Wake-up Enable A, offset: 0x20 */
       uint8_t RESERVED_3[12];
  __IO uint32_t LOCKA;                             /**< Lock A, offset: 0x30 */
       uint8_t RESERVED_4[460];
  __IO uint32_t FROCTLA;                           /**< FRO16K Control A, offset: 0x200 */
       uint8_t RESERVED_5[20];
  __IO uint32_t FROLCKA;                           /**< FRO16K Lock A, offset: 0x218 */
       uint8_t RESERVED_6[4];
  __IO uint32_t FROCLKE;                           /**< FRO16K Clock Enable, offset: 0x220 */
       uint8_t RESERVED_7[220];
  __IO uint32_t LDOCTLA;                           /**< LDO_RAM Control A, offset: 0x300 */
       uint8_t RESERVED_8[20];
  __IO uint32_t LDOLCKA;                           /**< LDO_RAM Lock A, offset: 0x318 */
       uint8_t RESERVED_9[4];
  __IO uint32_t LDORAMC;                           /**< RAM Control, offset: 0x320 */
       uint8_t RESERVED_10[12];
  __IO uint32_t LDOTIMER0;                         /**< Bandgap Timer 0, offset: 0x330 */
       uint8_t RESERVED_11[4];
  __IO uint32_t LDOTIMER1;                         /**< Bandgap Timer 1, offset: 0x338 */
} VBAT_Type;

/* ----------------------------------------------------------------------------
   -- VBAT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VBAT_Register_Masks VBAT Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define VBAT_VERID_FEATURE_MASK                  (0xFFFFU)
#define VBAT_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number */
#define VBAT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_FEATURE_SHIFT)) & VBAT_VERID_FEATURE_MASK)

#define VBAT_VERID_MINOR_MASK                    (0xFF0000U)
#define VBAT_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define VBAT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MINOR_SHIFT)) & VBAT_VERID_MINOR_MASK)

#define VBAT_VERID_MAJOR_MASK                    (0xFF000000U)
#define VBAT_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define VBAT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_VERID_MAJOR_SHIFT)) & VBAT_VERID_MAJOR_MASK)
/*! @} */

/*! @name STATUSA - Status A */
/*! @{ */

#define VBAT_STATUSA_POR_DET_MASK                (0x1U)
#define VBAT_STATUSA_POR_DET_SHIFT               (0U)
/*! POR_DET - POR Detect Flag
 *  0b0..Not reset
 *  0b0..No effect
 *  0b1..Reset
 *  0b1..Clear the flag
 */
#define VBAT_STATUSA_POR_DET(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_POR_DET_SHIFT)) & VBAT_STATUSA_POR_DET_MASK)

#define VBAT_STATUSA_WAKEUP_FLAG_MASK            (0x2U)
#define VBAT_STATUSA_WAKEUP_FLAG_SHIFT           (1U)
/*! WAKEUP_FLAG - Wakeup Pin Flag
 *  0b0..Not asserted
 *  0b0..No effect
 *  0b1..Asserted
 *  0b1..Clear the flag
 */
#define VBAT_STATUSA_WAKEUP_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_WAKEUP_FLAG_SHIFT)) & VBAT_STATUSA_WAKEUP_FLAG_MASK)

#define VBAT_STATUSA_TIMER0_FLAG_MASK            (0x4U)
#define VBAT_STATUSA_TIMER0_FLAG_SHIFT           (2U)
/*! TIMER0_FLAG - Bandgap Timer 0 Flag
 *  0b0..Not reached
 *  0b0..No effect
 *  0b1..Reached
 *  0b1..Clear the flag
 */
#define VBAT_STATUSA_TIMER0_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_TIMER0_FLAG_SHIFT)) & VBAT_STATUSA_TIMER0_FLAG_MASK)

#define VBAT_STATUSA_TIMER1_FLAG_MASK            (0x8U)
#define VBAT_STATUSA_TIMER1_FLAG_SHIFT           (3U)
/*! TIMER1_FLAG - Bandgap Timer 1 Flag
 *  0b0..Not reached
 *  0b0..No effect
 *  0b1..Reached
 *  0b1..Clear the flag
 */
#define VBAT_STATUSA_TIMER1_FLAG(x)              (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_TIMER1_FLAG_SHIFT)) & VBAT_STATUSA_TIMER1_FLAG_MASK)

#define VBAT_STATUSA_LDO_RDY_MASK                (0x10U)
#define VBAT_STATUSA_LDO_RDY_SHIFT               (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disabled (not ready)
 *  0b1..Enabled (ready)
 */
#define VBAT_STATUSA_LDO_RDY(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_STATUSA_LDO_RDY_SHIFT)) & VBAT_STATUSA_LDO_RDY_MASK)
/*! @} */

/*! @name IRQENA - Interrupt Enable A */
/*! @{ */

#define VBAT_IRQENA_POR_DET_MASK                 (0x1U)
#define VBAT_IRQENA_POR_DET_SHIFT                (0U)
/*! POR_DET - POR Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_POR_DET(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_POR_DET_SHIFT)) & VBAT_IRQENA_POR_DET_MASK)

#define VBAT_IRQENA_WAKEUP_FLAG_MASK             (0x2U)
#define VBAT_IRQENA_WAKEUP_FLAG_SHIFT            (1U)
/*! WAKEUP_FLAG - Wakeup Pin Flag
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_WAKEUP_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_WAKEUP_FLAG_SHIFT)) & VBAT_IRQENA_WAKEUP_FLAG_MASK)

#define VBAT_IRQENA_TIMER0_FLAG_MASK             (0x4U)
#define VBAT_IRQENA_TIMER0_FLAG_SHIFT            (2U)
/*! TIMER0_FLAG - Bandgap Timer 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_TIMER0_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_TIMER0_FLAG_SHIFT)) & VBAT_IRQENA_TIMER0_FLAG_MASK)

#define VBAT_IRQENA_TIMER1_FLAG_MASK             (0x8U)
#define VBAT_IRQENA_TIMER1_FLAG_SHIFT            (3U)
/*! TIMER1_FLAG - Bandgap Timer 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_TIMER1_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_TIMER1_FLAG_SHIFT)) & VBAT_IRQENA_TIMER1_FLAG_MASK)

#define VBAT_IRQENA_LDO_RDY_MASK                 (0x10U)
#define VBAT_IRQENA_LDO_RDY_SHIFT                (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_IRQENA_LDO_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_IRQENA_LDO_RDY_SHIFT)) & VBAT_IRQENA_LDO_RDY_MASK)
/*! @} */

/*! @name WAKENA - Wake-up Enable A */
/*! @{ */

#define VBAT_WAKENA_POR_DET_MASK                 (0x1U)
#define VBAT_WAKENA_POR_DET_SHIFT                (0U)
/*! POR_DET - POR Detect
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_POR_DET(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_POR_DET_SHIFT)) & VBAT_WAKENA_POR_DET_MASK)

#define VBAT_WAKENA_WAKEUP_FLAG_MASK             (0x2U)
#define VBAT_WAKENA_WAKEUP_FLAG_SHIFT            (1U)
/*! WAKEUP_FLAG - Wake-up Pin Flag
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_WAKEUP_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_WAKEUP_FLAG_SHIFT)) & VBAT_WAKENA_WAKEUP_FLAG_MASK)

#define VBAT_WAKENA_TIMER0_FLAG_MASK             (0x4U)
#define VBAT_WAKENA_TIMER0_FLAG_SHIFT            (2U)
/*! TIMER0_FLAG - Bandgap Timer 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_TIMER0_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_TIMER0_FLAG_SHIFT)) & VBAT_WAKENA_TIMER0_FLAG_MASK)

#define VBAT_WAKENA_TIMER1_FLAG_MASK             (0x8U)
#define VBAT_WAKENA_TIMER1_FLAG_SHIFT            (3U)
/*! TIMER1_FLAG - Bandgap Timer 2
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_TIMER1_FLAG(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_TIMER1_FLAG_SHIFT)) & VBAT_WAKENA_TIMER1_FLAG_MASK)

#define VBAT_WAKENA_LDO_RDY_MASK                 (0x10U)
#define VBAT_WAKENA_LDO_RDY_SHIFT                (4U)
/*! LDO_RDY - LDO Ready
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_WAKENA_LDO_RDY(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_WAKENA_LDO_RDY_SHIFT)) & VBAT_WAKENA_LDO_RDY_MASK)
/*! @} */

/*! @name LOCKA - Lock A */
/*! @{ */

#define VBAT_LOCKA_LOCK_MASK                     (0x1U)
#define VBAT_LOCKA_LOCK_SHIFT                    (0U)
/*! LOCK - Lock
 *  0b0..Disables lock
 *  0b1..Enables lock. Cleared by VBAT POR.
 */
#define VBAT_LOCKA_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << VBAT_LOCKA_LOCK_SHIFT)) & VBAT_LOCKA_LOCK_MASK)
/*! @} */

/*! @name FROCTLA - FRO16K Control A */
/*! @{ */

#define VBAT_FROCTLA_FRO_EN_MASK                 (0x1U)
#define VBAT_FROCTLA_FRO_EN_SHIFT                (0U)
/*! FRO_EN - FRO16K Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_FROCTLA_FRO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_FROCTLA_FRO_EN_SHIFT)) & VBAT_FROCTLA_FRO_EN_MASK)
/*! @} */

/*! @name FROLCKA - FRO16K Lock A */
/*! @{ */

#define VBAT_FROLCKA_LOCK_MASK                   (0x1U)
#define VBAT_FROLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_FROLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROLCKA_LOCK_SHIFT)) & VBAT_FROLCKA_LOCK_MASK)
/*! @} */

/*! @name FROCLKE - FRO16K Clock Enable */
/*! @{ */

#define VBAT_FROCLKE_CLKE_MASK                   (0x1U)
#define VBAT_FROCLKE_CLKE_SHIFT                  (0U)
/*! CLKE - Clock Enable */
#define VBAT_FROCLKE_CLKE(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_FROCLKE_CLKE_SHIFT)) & VBAT_FROCLKE_CLKE_MASK)
/*! @} */

/*! @name LDOCTLA - LDO_RAM Control A */
/*! @{ */

#define VBAT_LDOCTLA_BG_EN_MASK                  (0x1U)
#define VBAT_LDOCTLA_BG_EN_SHIFT                 (0U)
/*! BG_EN - Bandgap Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOCTLA_BG_EN(x)                    (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_BG_EN_SHIFT)) & VBAT_LDOCTLA_BG_EN_MASK)

#define VBAT_LDOCTLA_LDO_EN_MASK                 (0x2U)
#define VBAT_LDOCTLA_LDO_EN_SHIFT                (1U)
/*! LDO_EN - LDO Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOCTLA_LDO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_LDO_EN_SHIFT)) & VBAT_LDOCTLA_LDO_EN_MASK)

#define VBAT_LDOCTLA_REFRESH_EN_MASK             (0x4U)
#define VBAT_LDOCTLA_REFRESH_EN_SHIFT            (2U)
/*! REFRESH_EN - Refresh Enable
 *  0b0..Refresh mode is disabled
 *  0b1..Refresh mode is enabled for low power operation
 */
#define VBAT_LDOCTLA_REFRESH_EN(x)               (((uint32_t)(((uint32_t)(x)) << VBAT_LDOCTLA_REFRESH_EN_SHIFT)) & VBAT_LDOCTLA_REFRESH_EN_MASK)
/*! @} */

/*! @name LDOLCKA - LDO_RAM Lock A */
/*! @{ */

#define VBAT_LDOLCKA_LOCK_MASK                   (0x1U)
#define VBAT_LDOLCKA_LOCK_SHIFT                  (0U)
/*! LOCK - Lock
 *  0b0..Do not block
 *  0b1..Block
 */
#define VBAT_LDOLCKA_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDOLCKA_LOCK_SHIFT)) & VBAT_LDOLCKA_LOCK_MASK)
/*! @} */

/*! @name LDORAMC - RAM Control */
/*! @{ */

#define VBAT_LDORAMC_ISO_MASK                    (0x1U)
#define VBAT_LDORAMC_ISO_SHIFT                   (0U)
/*! ISO - Isolate SRAM
 *  0b0..State follows the chip power modes
 *  0b1..Isolates SRAM and places it in Low-Power Retention mode
 */
#define VBAT_LDORAMC_ISO(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_ISO_SHIFT)) & VBAT_LDORAMC_ISO_MASK)

#define VBAT_LDORAMC_SWI_MASK                    (0x2U)
#define VBAT_LDORAMC_SWI_SHIFT                   (1U)
/*! SWI - Switch SRAM
 *  0b0..Supply follows the chip power modes
 *  0b1..LDO_RAM powers the array
 */
#define VBAT_LDORAMC_SWI(x)                      (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_SWI_SHIFT)) & VBAT_LDORAMC_SWI_MASK)

#define VBAT_LDORAMC_RET0_MASK                   (0x100U)
#define VBAT_LDORAMC_RET0_SHIFT                  (8U)
/*! RET0 - Retention
 *  0b0..Corresponding SRAM array is retained in low-power modes
 *  0b1..Corresponding SRAM array is not retained in low-power modes
 */
#define VBAT_LDORAMC_RET0(x)                     (((uint32_t)(((uint32_t)(x)) << VBAT_LDORAMC_RET0_SHIFT)) & VBAT_LDORAMC_RET0_MASK)
/*! @} */

/*! @name LDOTIMER0 - Bandgap Timer 0 */
/*! @{ */

#define VBAT_LDOTIMER0_TIMCFG_MASK               (0x7U)
#define VBAT_LDOTIMER0_TIMCFG_SHIFT              (0U)
/*! TIMCFG - Timeout Configuration
 *  0b000..1 s
 *  0b001..500 ms
 *  0b010..250 ms
 *  0b011..125 ms
 *  0b100..62.5 ms
 *  0b101..31.25 ms
 *  0b110..15.625 ms
 *  0b111..7.8125 ms
 */
#define VBAT_LDOTIMER0_TIMCFG(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER0_TIMCFG_SHIFT)) & VBAT_LDOTIMER0_TIMCFG_MASK)

#define VBAT_LDOTIMER0_TIMEN_MASK                (0x80000000U)
#define VBAT_LDOTIMER0_TIMEN_SHIFT               (31U)
/*! TIMEN - Bandgap Timeout Period Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOTIMER0_TIMEN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER0_TIMEN_SHIFT)) & VBAT_LDOTIMER0_TIMEN_MASK)
/*! @} */

/*! @name LDOTIMER1 - Bandgap Timer 1 */
/*! @{ */

#define VBAT_LDOTIMER1_TIMCFG_MASK               (0xFFFFFFU)
#define VBAT_LDOTIMER1_TIMCFG_SHIFT              (0U)
/*! TIMCFG - Timeout Configuration */
#define VBAT_LDOTIMER1_TIMCFG(x)                 (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER1_TIMCFG_SHIFT)) & VBAT_LDOTIMER1_TIMCFG_MASK)

#define VBAT_LDOTIMER1_TIMEN_MASK                (0x80000000U)
#define VBAT_LDOTIMER1_TIMEN_SHIFT               (31U)
/*! TIMEN - Bandgap Timeout Period Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VBAT_LDOTIMER1_TIMEN(x)                  (((uint32_t)(((uint32_t)(x)) << VBAT_LDOTIMER1_TIMEN_SHIFT)) & VBAT_LDOTIMER1_TIMEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VBAT_Register_Masks */

/* Backward compatibility */
#define VBAT_LDORAMC_RET_MASK VBAT_LDORAMC_RET0_MASK
#define VBAT_LDORAMC_RET VBAT_LDORAMC_RET0


/*!
 * @}
 */ /* end of group VBAT_Peripheral_Access_Layer */


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


#endif  /* VBAT_H_ */

