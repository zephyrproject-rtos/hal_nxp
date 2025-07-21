/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SIM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SIM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SIM
 *
 * CMSIS Peripheral Access Layer for SIM
 */

#if !defined(PERI_SIM_H_)
#define PERI_SIM_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CHIPCTRL;                          /**< Chip Control Register, offset: 0x4 */
       uint8_t RESERVED_1[28];
  __IO uint32_t SDID;                              /**< System Device Identification Register, offset: 0x24 */
       uint8_t RESERVED_2[36];
  __IO uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
  __I  uint32_t FCFG2;                             /**< Flash Configuration Register 2, offset: 0x50 */
       uint8_t RESERVED_3[4];
  __I  uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x58 */
  __I  uint32_t UIDM;                              /**< Unique Identification Register Mid Middle, offset: 0x5C */
  __I  uint32_t UIDL;                              /**< Unique Identification Register Mid Low, offset: 0x60 */
       uint8_t RESERVED_4[12];
  __IO uint32_t MISC2;                             /**< MISC2 Register, offset: 0x70 */
} SIM_Type;

/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/*! @name CHIPCTRL - Chip Control Register */
/*! @{ */

#define SIM_CHIPCTRL_FBSL_MASK                   (0x300U)
#define SIM_CHIPCTRL_FBSL_SHIFT                  (8U)
/*! FBSL - FLEXBUS security level
 *  0b00..All off-chip access(instruction and data) via the Flexbus or sdram are disallowed
 *  0b01..All off-chip access(instruction and data) via the Flexbus or sdram are disallowed
 *  0b10..off-chip instruction access are disallowed, data access are allowed
 *  0b11..off-chip instruction access and data access are allowed
 */
#define SIM_CHIPCTRL_FBSL(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_CHIPCTRL_FBSL_SHIFT)) & SIM_CHIPCTRL_FBSL_MASK)
/*! @} */

/*! @name SDID - System Device Identification Register */
/*! @{ */

#define SIM_SDID_PINID_MASK                      (0xFU)
#define SIM_SDID_PINID_SHIFT                     (0U)
/*! PINID - PINID
 *  0b1000..176-pin
 */
#define SIM_SDID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_PINID_SHIFT)) & SIM_SDID_PINID_MASK)

#define SIM_SDID_DIEID_MASK                      (0xF80U)
#define SIM_SDID_DIEID_SHIFT                     (7U)
/*! DIEID - DIEID */
#define SIM_SDID_DIEID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_DIEID_SHIFT)) & SIM_SDID_DIEID_MASK)

#define SIM_SDID_REVID_MASK                      (0xF000U)
#define SIM_SDID_REVID_SHIFT                     (12U)
/*! REVID - REVID */
#define SIM_SDID_REVID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_REVID_SHIFT)) & SIM_SDID_REVID_MASK)

#define SIM_SDID_SERIESID_MASK                   (0xF00000U)
#define SIM_SDID_SERIESID_SHIFT                  (20U)
/*! SERIESID - SERIESID */
#define SIM_SDID_SERIESID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SERIESID_SHIFT)) & SIM_SDID_SERIESID_MASK)

#define SIM_SDID_SUBFAMID_MASK                   (0xF000000U)
#define SIM_SDID_SUBFAMID_SHIFT                  (24U)
/*! SUBFAMID - SUBFAMID
 *  0b0000..L3A
 */
#define SIM_SDID_SUBFAMID(x)                     (((uint32_t)(((uint32_t)(x)) << SIM_SDID_SUBFAMID_SHIFT)) & SIM_SDID_SUBFAMID_MASK)

#define SIM_SDID_FAMID_MASK                      (0xF0000000U)
#define SIM_SDID_FAMID_SHIFT                     (28U)
/*! FAMID - FAMID
 *  0b0000..K32
 */
#define SIM_SDID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_SDID_FAMID_SHIFT)) & SIM_SDID_FAMID_MASK)
/*! @} */

/*! @name FCFG1 - Flash Configuration Register 1 */
/*! @{ */

#define SIM_FCFG1_FLASHDIS_MASK                  (0x1U)
#define SIM_FCFG1_FLASHDIS_SHIFT                 (0U)
/*! FLASHDIS - Flash disable
 *  0b0..Flash is enabled
 *  0b1..Flash is disabled
 */
#define SIM_FCFG1_FLASHDIS(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDIS_SHIFT)) & SIM_FCFG1_FLASHDIS_MASK)

#define SIM_FCFG1_FLASHDOZE_MASK                 (0x2U)
#define SIM_FCFG1_FLASHDOZE_SHIFT                (1U)
/*! FLASHDOZE - Flash Doze
 *  0b0..Flash remains enabled during Doze mode
 *  0b1..Flash is disabled for the duration of Doze mode
 */
#define SIM_FCFG1_FLASHDOZE(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLASHDOZE_SHIFT)) & SIM_FCFG1_FLASHDOZE_MASK)

#define SIM_FCFG1_FLSAUTODISEN_MASK              (0x4U)
#define SIM_FCFG1_FLSAUTODISEN_SHIFT             (2U)
/*! FLSAUTODISEN - Flash auto disable enabled.
 *  0b0..Disable flash auto disable function
 *  0b1..Enable flash auto disable function
 */
#define SIM_FCFG1_FLSAUTODISEN(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLSAUTODISEN_SHIFT)) & SIM_FCFG1_FLSAUTODISEN_MASK)

#define SIM_FCFG1_FLSAUTODISWD_MASK              (0x3FF8U)
#define SIM_FCFG1_FLSAUTODISWD_SHIFT             (3U)
/*! FLSAUTODISWD - The clock counter for time period of flash auto disable. */
#define SIM_FCFG1_FLSAUTODISWD(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_FLSAUTODISWD_SHIFT)) & SIM_FCFG1_FLSAUTODISWD_MASK)

#define SIM_FCFG1_CORE1_SRAMSIZE_MASK            (0xF0000U)
#define SIM_FCFG1_CORE1_SRAMSIZE_SHIFT           (16U)
/*! CORE1_SRAMSIZE
 *  0b1001..CM0+ has 128 KB SRAM
 */
#define SIM_FCFG1_CORE1_SRAMSIZE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_CORE1_SRAMSIZE_SHIFT)) & SIM_FCFG1_CORE1_SRAMSIZE_MASK)

#define SIM_FCFG1_CORE0_SRAMSIZE_MASK            (0xF00000U)
#define SIM_FCFG1_CORE0_SRAMSIZE_SHIFT           (20U)
/*! CORE0_SRAMSIZE
 *  0b1010..CM4 has 256 KB SRAM
 */
#define SIM_FCFG1_CORE0_SRAMSIZE(x)              (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_CORE0_SRAMSIZE_SHIFT)) & SIM_FCFG1_CORE0_SRAMSIZE_MASK)

#define SIM_FCFG1_CORE1_PFSIZE_MASK              (0xF000000U)
#define SIM_FCFG1_CORE1_PFSIZE_SHIFT             (24U)
/*! CORE1_PFSIZE
 *  0b1010..CM0+ has 256 KB flash size.
 */
#define SIM_FCFG1_CORE1_PFSIZE(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_CORE1_PFSIZE_SHIFT)) & SIM_FCFG1_CORE1_PFSIZE_MASK)

#define SIM_FCFG1_CORE0_PFSIZE_MASK              (0xF0000000U)
#define SIM_FCFG1_CORE0_PFSIZE_SHIFT             (28U)
/*! CORE0_PFSIZE
 *  0b1100..CM4 has 1 MB flash size.
 */
#define SIM_FCFG1_CORE0_PFSIZE(x)                (((uint32_t)(((uint32_t)(x)) << SIM_FCFG1_CORE0_PFSIZE_SHIFT)) & SIM_FCFG1_CORE0_PFSIZE_MASK)
/*! @} */

/*! @name FCFG2 - Flash Configuration Register 2 */
/*! @{ */

#define SIM_FCFG2_MAXADDR2_MASK                  (0x3F0000U)
#define SIM_FCFG2_MAXADDR2_SHIFT                 (16U)
/*! MAXADDR2 - Max Address lock */
#define SIM_FCFG2_MAXADDR2(x)                    (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR2_SHIFT)) & SIM_FCFG2_MAXADDR2_MASK)

#define SIM_FCFG2_MAXADDR01_MASK                 (0x7F000000U)
#define SIM_FCFG2_MAXADDR01_SHIFT                (24U)
/*! MAXADDR01 - Max Address lock */
#define SIM_FCFG2_MAXADDR01(x)                   (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_MAXADDR01_SHIFT)) & SIM_FCFG2_MAXADDR01_MASK)

#define SIM_FCFG2_SWAP_MASK                      (0x80000000U)
#define SIM_FCFG2_SWAP_SHIFT                     (31U)
/*! SWAP - SWAP
 *  0b0..Logical P-flash Block 0 is located at relative address 0x0000
 *  0b1..Logical P-flash Block 1 is located at relative address 0x0000
 */
#define SIM_FCFG2_SWAP(x)                        (((uint32_t)(((uint32_t)(x)) << SIM_FCFG2_SWAP_SHIFT)) & SIM_FCFG2_SWAP_MASK)
/*! @} */

/*! @name UIDH - Unique Identification Register High */
/*! @{ */

#define SIM_UIDH_UID_MASK                        (0xFFFFU)
#define SIM_UIDH_UID_SHIFT                       (0U)
/*! UID - Unique Identification */
#define SIM_UIDH_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDH_UID_SHIFT)) & SIM_UIDH_UID_MASK)
/*! @} */

/*! @name UIDM - Unique Identification Register Mid Middle */
/*! @{ */

#define SIM_UIDM_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDM_UID_SHIFT                       (0U)
/*! UID - Unique Identification */
#define SIM_UIDM_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDM_UID_SHIFT)) & SIM_UIDM_UID_MASK)
/*! @} */

/*! @name UIDL - Unique Identification Register Mid Low */
/*! @{ */

#define SIM_UIDL_UID_MASK                        (0xFFFFFFFFU)
#define SIM_UIDL_UID_SHIFT                       (0U)
/*! UID - Unique Identification */
#define SIM_UIDL_UID(x)                          (((uint32_t)(((uint32_t)(x)) << SIM_UIDL_UID_SHIFT)) & SIM_UIDL_UID_MASK)
/*! @} */

/*! @name MISC2 - MISC2 Register */
/*! @{ */

#define SIM_MISC2_SYSTICK_CLK_EN_MASK            (0x1U)
#define SIM_MISC2_SYSTICK_CLK_EN_SHIFT           (0U)
/*! systick_clk_en - Systick clock enable
 *  0b0..Systick clock is disabled
 *  0b1..Systick clock is enabled
 */
#define SIM_MISC2_SYSTICK_CLK_EN(x)              (((uint32_t)(((uint32_t)(x)) << SIM_MISC2_SYSTICK_CLK_EN_SHIFT)) & SIM_MISC2_SYSTICK_CLK_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


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


#endif  /* PERI_SIM_H_ */

