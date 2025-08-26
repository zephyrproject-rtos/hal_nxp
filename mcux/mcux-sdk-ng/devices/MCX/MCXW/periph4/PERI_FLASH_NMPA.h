/*
** ###################################################################
**     Processors:          MCXW235BIHNAR
**                          MCXW235BIUKAR
**                          MCXW236AIHNAR
**                          MCXW236AIUKAR
**                          MCXW236BIHNAR
**                          MCXW236BIUKAR
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250624
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FLASH_NMPA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-03-08)
**         Initial version based on v0.1UM
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FLASH_NMPA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FLASH_NMPA
 *
 * CMSIS Peripheral Access Layer for FLASH_NMPA
 */

#if !defined(PERI_FLASH_NMPA_H_)
#define PERI_FLASH_NMPA_H_                       /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXW235BIHNAR) || defined(CPU_MCXW235BIUKAR))
#include "MCXW235_COMMON.h"
#elif (defined(CPU_MCXW236AIHNAR) || defined(CPU_MCXW236AIUKAR) || defined(CPU_MCXW236BIHNAR) || defined(CPU_MCXW236BIUKAR))
#include "MCXW236_COMMON.h"
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
   -- FLASH_NMPA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_NMPA_Peripheral_Access_Layer FLASH_NMPA Peripheral Access Layer
 * @{
 */

/** FLASH_NMPA - Size of Registers Arrays */
#define FLASH_NMPA_UUID_UUID_ARRAY_UUID_ARRAY_COUNT 4u
#define FLASH_NMPA_SHA256_DIGEST_COUNT            8u
#define FLASH_NMPA_FMUPARAM0_FMUPARAM0_ARRAY_FMUPARAM0_ARRAY_COUNT 4u
#define FLASH_NMPA_FMUPARAM1_FMUPARAM1_ARRAY_FMUPARAM1_ARRAY_COUNT 4u
#define FLASH_NMPA_FMUPARAM2_FMUPARAM2_ARRAY_FMUPARAM2_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO0_GPO0_ARRAY_GPO0_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO1_GPO1_ARRAY_GPO1_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO2_GPO2_ARRAY_GPO2_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO3_GPO3_ARRAY_GPO3_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO4_GPO4_ARRAY_GPO4_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO5_GPO5_ARRAY_GPO5_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO6_GPO6_ARRAY_GPO6_ARRAY_COUNT 4u
#define FLASH_NMPA_GPO7_GPO7_ARRAY_GPO7_ARRAY_COUNT 4u

/** FLASH_NMPA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2816];
  __IO uint32_t TRNG_CONTROL;                      /**< offset: 0xB00 */
  __IO uint32_t TRNG_PKRRNG;                       /**< offset: 0xB04 */
  __IO uint32_t TRNG_PKRMAX;                       /**< offset: 0xB08 */
  __IO uint32_t TRNG_SDCTL;                        /**< offset: 0xB0C */
  __IO uint32_t TRNG_SBLIM;                        /**< offset: 0xB10 */
  __IO uint32_t TRNG_FRQMIN;                       /**< offset: 0xB14 */
  __IO uint32_t TRNG_FRQMAX;                       /**< offset: 0xB18 */
  __IO uint32_t TRNG_SCML;                         /**< offset: 0xB1C */
  __IO uint32_t TRNG_SCR1L;                        /**< offset: 0xB20 */
  __IO uint32_t TRNG_SCR2L;                        /**< offset: 0xB24 */
  __IO uint32_t TRNG_SCR3L;                        /**< offset: 0xB28 */
  __IO uint32_t TRNG_SCR4L;                        /**< offset: 0xB2C */
  __IO uint32_t TRNG_SCR5L;                        /**< offset: 0xB30 */
  __IO uint32_t TRNG_SCR6PL;                       /**< offset: 0xB34 */
       uint8_t RESERVED_1[40];
  __IO uint32_t DEVICE_TYPE;                       /**< offset: 0xB60 */
       uint8_t RESERVED_2[4];
  struct {                                         /* offset: 0xB68 */
    __IO uint32_t BLE_DEFAULT_ADDRESS0;              /**< BLE_DEFAULT_ADDRESS part 1, offset: 0xB68 */
    __IO uint32_t BLE_DEFAULT_ADDRESS1;              /**< BLE_DEFAULT_ADDRESS part 2, offset: 0xB6C */
  } BLE_DEFAULT_ADDRESS;
  union {                                          /* offset: 0xB70 */
    struct {                                         /* offset: 0xB70 */
      __IO uint32_t UUID_0;                            /**< offset: 0xB70 */
      __IO uint32_t UUID_1;                            /**< offset: 0xB74 */
      __IO uint32_t UUID_2;                            /**< offset: 0xB78 */
      __IO uint32_t UUID_3;                            /**< offset: 0xB7C */
    } UUID;
    __IO uint32_t UUID_ARRAY[FLASH_NMPA_UUID_UUID_ARRAY_UUID_ARRAY_COUNT];   /**< array offset: 0xB70, array step: 0x4 */
  };
  __IO uint32_t PERIPHENCFG;                       /**< offset: 0xB80 */
  __IO uint32_t RAMSIZECFG;                        /**< offset: 0xB84 */
  __IO uint32_t FLASHSIZECFG;                      /**< offset: 0xB88 */
  __IO uint32_t DIS_ROM_HIDING;                    /**< offset: 0xB8C */
  __IO uint32_t RINGO_0;                           /**< offset: 0xB90 */
  __IO uint32_t RINGO_1;                           /**< offset: 0xB94 */
  __IO uint32_t RINGO_2;                           /**< offset: 0xB98 */
  __IO uint32_t PUF_SRAM;                          /**< offset: 0xB9C */
  __IO uint32_t BOD;                               /**< BOD, offset: 0xBA0 */
  __IO uint32_t LDO_MEM;                           /**< LDO_MEM, offset: 0xBA4 */
  __IO uint32_t LDO_DIG;                           /**< LDO_DIG, offset: 0xBA8 */
  __IO uint32_t BLE_TEST;                          /**< BLE_TEST, offset: 0xBAC */
       uint8_t RESERVED_3[16];
  __IO uint32_t DCDC_POWER_PROFILE_LOW;            /**< offset: 0xBC0 */
  __IO uint32_t DCDC_POWER_PROFILE_MEDIUM;         /**< offset: 0xBC4 */
  __IO uint32_t DCDC_POWER_PROFILE_HIGH;           /**< offset: 0xBC8 */
       uint8_t RESERVED_4[20];
  __IO uint32_t SHA256_DIGEST[FLASH_NMPA_SHA256_DIGEST_COUNT]; /**< SHA-256 DIGEST (0000 - 0BEC and 1800 - 187C) ROM Patch Area + NXP Area + GPO SHA256_DIGEST0 for DIGEST[31:0] SHA256_DIGEST1 for DIGEST[63:32] SHA256_DIGEST2 for DIGEST[95:64] SHA256_DIGEST3 for DIGEST[127:96] SHA256_DIGEST4 for DIGEST[159:128] SHA256_DIGEST5 for DIGEST[191:160] SHA256_DIGEST6 for DIGEST[223:192] SHA256_DIGEST7 for DIGEST[255:224], array offset: 0xBE0, array step: 0x4 */
       uint8_t RESERVED_5[1024];
  __IO uint32_t LOTID_0;                           /**< MCXW23 Lot ID, offset: 0x1000 */
  __IO uint32_t LOTID_1;                           /**< MCXW23 Lot ID, offset: 0x1004 */
  __IO uint32_t WAFERID;                           /**< MCXW23 Wafer ID, offset: 0x1008 */
  __IO uint32_t DIE_X_Y;                           /**< MCXW23 Die Coordinates, offset: 0x100C */
       uint8_t RESERVED_6[1520];
  union {                                          /* offset: 0x1600 */
    struct {                                         /* offset: 0x1600 */
      __IO uint32_t FMUPARM0_0;                        /**< General FMU parameters, offset: 0x1600 */
      __IO uint32_t FMUPARM0_1;                        /**< General FMU parameters, offset: 0x1604 */
      __IO uint32_t FMUPARM0_2;                        /**< General FMU parameters, offset: 0x1608 */
      __IO uint32_t FMUPARM0_3;                        /**< General FMU parameters, offset: 0x160C */
    } FMUPARAM0;
    __IO uint32_t FMUPARAM0_ARRAY[FLASH_NMPA_FMUPARAM0_FMUPARAM0_ARRAY_FMUPARAM0_ARRAY_COUNT];   /**< General FMU parameters, array offset: 0x1600, array step: 0x4 */
  };
  union {                                          /* offset: 0x1610 */
    struct {                                         /* offset: 0x1610 */
      __IO uint32_t FMUPARM1_0;                        /**< SMW timer options, SMW setting options, offset: 0x1610 */
      __IO uint32_t FMUPARM1_1;                        /**< SMW timer options, SMW setting options, offset: 0x1614 */
      __IO uint32_t FMUPARM1_2;                        /**< SMW timer options, SMW setting options, offset: 0x1618 */
      __IO uint32_t FMUPARM1_3;                        /**< SMW timer options, SMW setting options, offset: 0x161C */
    } FMUPARAM1;
    __IO uint32_t FMUPARAM1_ARRAY[FLASH_NMPA_FMUPARAM1_FMUPARAM1_ARRAY_FMUPARAM1_ARRAY_COUNT];   /**< SMW timer options, SMW setting options, array offset: 0x1610, array step: 0x4 */
  };
  union {                                          /* offset: 0x1620 */
    struct {                                         /* offset: 0x1620 */
      __IO uint32_t FMUPARM2_0;                        /**< SMW setting options continued, SMW smart program/erase options, offset: 0x1620 */
      __IO uint32_t FMUPARM2_1;                        /**< SMW setting options continued, SMW smart program/erase options, offset: 0x1624 */
      __IO uint32_t FMUPARM2_2;                        /**< SMW setting options continued, SMW smart program/erase options, offset: 0x1628 */
      __IO uint32_t FMUPARM2_3;                        /**< SMW setting options continued, SMW smart program/erase options, offset: 0x162C */
    } FMUPARAM2;
    __IO uint32_t FMUPARAM2_ARRAY[FLASH_NMPA_FMUPARAM2_FMUPARAM2_ARRAY_FMUPARAM2_ARRAY_COUNT];   /**< SMW setting options continued, SMW smart program/erase options, array offset: 0x1620, array step: 0x4 */
  };
  __IO uint32_t FMUPARM3;                          /**< SMW smart erase options continued, offset: 0x1630 */
       uint8_t RESERVED_7[12];
  __IO uint32_t FMUPARM4;                          /**< Array size (see MSIZE register), offset: 0x1640 */
       uint8_t RESERVED_8[12];
  __IO uint32_t FMUPARM5;                          /**< TME control (see FTEST register), offset: 0x1650 */
       uint8_t RESERVED_9[396];
  __IO uint32_t SOCTRIMEN;                         /**< C0DE_C0DE field at [31:0] to enable loading of SoC trim settings, offset: 0x17E0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t SOCTRIMECC;                        /**< C0DE_C0DE field at [31:0] for controlling ECC decoder while fetching SoC trim settings, offset: 0x17F0 */
       uint8_t RESERVED_11[12];
  union {                                          /* offset: 0x1800 */
    struct {                                         /* offset: 0x1800 */
      __IO uint32_t GPO0_0;                            /**< GPO0 register 0 description, offset: 0x1800 */
      __IO uint32_t GPO0_1;                            /**< GPO0 register 1 description, offset: 0x1804 */
      __IO uint32_t GPO0_2;                            /**< GPO0 register 2 description, offset: 0x1808 */
      __IO uint32_t GPO0_3;                            /**< GPO0 register 3 description, offset: 0x180C */
    } GPO0;
    __IO uint32_t GPO0_ARRAY[FLASH_NMPA_GPO0_GPO0_ARRAY_GPO0_ARRAY_COUNT];   /**< GPO0 array description, array offset: 0x1800, array step: 0x4 */
  };
  union {                                          /* offset: 0x1810 */
    struct {                                         /* offset: 0x1810 */
      __IO uint32_t GPO1_0;                            /**< GPO1 register 0 description, offset: 0x1810 */
      __IO uint32_t GPO1_1;                            /**< GPO1 register 1 description, offset: 0x1814 */
      __IO uint32_t GPO1_2;                            /**< GPO1 register 2 description, offset: 0x1818 */
      __IO uint32_t GPO1_3;                            /**< GPO1 register 3 description, offset: 0x181C */
    } GPO1;
    __IO uint32_t GPO1_ARRAY[FLASH_NMPA_GPO1_GPO1_ARRAY_GPO1_ARRAY_COUNT];   /**< GPO1 array description, array offset: 0x1810, array step: 0x4 */
  };
  union {                                          /* offset: 0x1820 */
    struct {                                         /* offset: 0x1820 */
      __IO uint32_t GPO2_0;                            /**< GPO2 register 0 description, offset: 0x1820 */
      __IO uint32_t GPO2_1;                            /**< GPO2 register 1 description, offset: 0x1824 */
      __IO uint32_t GPO2_2;                            /**< GPO2 register 2 description, offset: 0x1828 */
      __IO uint32_t GPO2_3;                            /**< GPO2 register 3 description, offset: 0x182C */
    } GPO2;
    __IO uint32_t GPO2_ARRAY[FLASH_NMPA_GPO2_GPO2_ARRAY_GPO2_ARRAY_COUNT];   /**< GPO2 array description, array offset: 0x1820, array step: 0x4 */
  };
  union {                                          /* offset: 0x1830 */
    struct {                                         /* offset: 0x1830 */
      __IO uint32_t GPO3_0;                            /**< GPO3 register 0 description, offset: 0x1830 */
      __IO uint32_t GPO3_1;                            /**< GPO3 register 1 description, offset: 0x1834 */
      __IO uint32_t GPO3_2;                            /**< GPO3 register 2 description, offset: 0x1838 */
      __IO uint32_t GPO3_3;                            /**< GPO3 register 3 description, offset: 0x183C */
    } GPO3;
    __IO uint32_t GPO3_ARRAY[FLASH_NMPA_GPO3_GPO3_ARRAY_GPO3_ARRAY_COUNT];   /**< GPO3 array description, array offset: 0x1830, array step: 0x4 */
  };
  union {                                          /* offset: 0x1840 */
    struct {                                         /* offset: 0x1840 */
      __IO uint32_t GPO4_0;                            /**< GPO4 register 0 description, offset: 0x1840 */
      __IO uint32_t GPO4_1;                            /**< GPO4 register 1 description, offset: 0x1844 */
      __IO uint32_t GPO4_2;                            /**< GPO4 register 2 description, offset: 0x1848 */
      __IO uint32_t GPO4_3;                            /**< GPO4 register 3 description, offset: 0x184C */
    } GPO4;
    __IO uint32_t GPO4_ARRAY[FLASH_NMPA_GPO4_GPO4_ARRAY_GPO4_ARRAY_COUNT];   /**< GPO4 array description, array offset: 0x1840, array step: 0x4 */
  };
  union {                                          /* offset: 0x1850 */
    struct {                                         /* offset: 0x1850 */
      __IO uint32_t GPO5_0;                            /**< GPO5 register 0 description, offset: 0x1850 */
      __IO uint32_t GPO5_1;                            /**< GPO5 register 1 description, offset: 0x1854 */
      __IO uint32_t GPO5_2;                            /**< GPO5 register 2 description, offset: 0x1858 */
      __IO uint32_t GPO5_3;                            /**< GPO5 register 3 description, offset: 0x185C */
    } GPO5;
    __IO uint32_t GPO5_ARRAY[FLASH_NMPA_GPO5_GPO5_ARRAY_GPO5_ARRAY_COUNT];   /**< GPO5 array description, array offset: 0x1850, array step: 0x4 */
  };
  union {                                          /* offset: 0x1860 */
    struct {                                         /* offset: 0x1860 */
      __IO uint32_t GPO6_0;                            /**< GPO6 register 0 description, offset: 0x1860 */
      __IO uint32_t GPO6_1;                            /**< GPO6 register 1 description, offset: 0x1864 */
      __IO uint32_t GPO6_2;                            /**< GPO6 register 2 description, offset: 0x1868 */
      __IO uint32_t GPO6_3;                            /**< GPO6 register 3 description, offset: 0x186C */
    } GPO6;
    __IO uint32_t GPO6_ARRAY[FLASH_NMPA_GPO6_GPO6_ARRAY_GPO6_ARRAY_COUNT];   /**< GPO6 array description, array offset: 0x1860, array step: 0x4 */
  };
  union {                                          /* offset: 0x1870 */
    struct {                                         /* offset: 0x1870 */
      __IO uint32_t GPO7_0;                            /**< GPO7 register 0 description, offset: 0x1870 */
      __IO uint32_t GPO7_1;                            /**< GPO7 register 1 description, offset: 0x1874 */
      __IO uint32_t GPO7_2;                            /**< GPO7 register 2 description, offset: 0x1878 */
      __IO uint32_t GPO7_3;                            /**< GPO7 register 3 description, offset: 0x187C */
    } GPO7;
    __IO uint32_t GPO7_ARRAY[FLASH_NMPA_GPO7_GPO7_ARRAY_GPO7_ARRAY_COUNT];   /**< GPO7 array description, array offset: 0x1870, array step: 0x4 */
  };
} FLASH_NMPA_Type;

/* ----------------------------------------------------------------------------
   -- FLASH_NMPA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FLASH_NMPA_Register_Masks FLASH_NMPA Register Masks
 * @{
 */

/*! @name TRNG_CONTROL -  */
/*! @{ */

#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_SAMP_MODE_MASK (0x3U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_SAMP_MODE_SHIFT (0U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_SAMP_MODE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_SAMP_MODE_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_SAMP_MODE_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_OSC_DIV_MASK (0xCU)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_OSC_DIV_SHIFT (2U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_OSC_DIV(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_OSC_DIV_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_OSC_DIV_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_FOR_SCLK_MASK (0x80U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_FOR_SCLK_SHIFT (7U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_FOR_SCLK(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_FOR_SCLK_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_MCTL_FOR_SCLK_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_LRUN_MAX_MASK (0xFF00U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_LRUN_MAX_SHIFT (8U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_LRUN_MAX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_LRUN_MAX_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_LRUN_MAX_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_RTY_CT_MASK (0xF0000U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_RTY_CT_SHIFT (16U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_RTY_CT(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_RTY_CT_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_SCMISC_RTY_CT_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_SEC_CFG_NO_PRGM_MASK (0x20000000U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SEC_CFG_NO_PRGM_SHIFT (29U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_SEC_CFG_NO_PRGM(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_SEC_CFG_NO_PRGM_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_SEC_CFG_NO_PRGM_MASK)

#define FLASH_NMPA_TRNG_CONTROL_TRNG_VALID_MASK  (0x80000000U)
#define FLASH_NMPA_TRNG_CONTROL_TRNG_VALID_SHIFT (31U)
/*! TRNG_VALID - This field indicates if the other TRNG values in flash are valid and can be copied to the HW block. */
#define FLASH_NMPA_TRNG_CONTROL_TRNG_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_CONTROL_TRNG_VALID_SHIFT)) & FLASH_NMPA_TRNG_CONTROL_TRNG_VALID_MASK)
/*! @} */

/*! @name TRNG_PKRRNG -  */
/*! @{ */

#define FLASH_NMPA_TRNG_PKRRNG_TRNG_PKR_RNG_MASK (0xFFFFU)
#define FLASH_NMPA_TRNG_PKRRNG_TRNG_PKR_RNG_SHIFT (0U)
#define FLASH_NMPA_TRNG_PKRRNG_TRNG_PKR_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_PKRRNG_TRNG_PKR_RNG_SHIFT)) & FLASH_NMPA_TRNG_PKRRNG_TRNG_PKR_RNG_MASK)
/*! @} */

/*! @name TRNG_PKRMAX -  */
/*! @{ */

#define FLASH_NMPA_TRNG_PKRMAX_TRNG_PKR_MAX_MASK (0xFFFFFFU)
#define FLASH_NMPA_TRNG_PKRMAX_TRNG_PKR_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_PKRMAX_TRNG_PKR_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_PKRMAX_TRNG_PKR_MAX_SHIFT)) & FLASH_NMPA_TRNG_PKRMAX_TRNG_PKR_MAX_MASK)
/*! @} */

/*! @name TRNG_SDCTL -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SDCTL_TRNG_SAMP_SIZE_MASK (0xFFFFU)
#define FLASH_NMPA_TRNG_SDCTL_TRNG_SAMP_SIZE_SHIFT (0U)
#define FLASH_NMPA_TRNG_SDCTL_TRNG_SAMP_SIZE(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SDCTL_TRNG_SAMP_SIZE_SHIFT)) & FLASH_NMPA_TRNG_SDCTL_TRNG_SAMP_SIZE_MASK)

#define FLASH_NMPA_TRNG_SDCTL_TRNG_ENT_DLY_MASK  (0xFFFF0000U)
#define FLASH_NMPA_TRNG_SDCTL_TRNG_ENT_DLY_SHIFT (16U)
#define FLASH_NMPA_TRNG_SDCTL_TRNG_ENT_DLY(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SDCTL_TRNG_ENT_DLY_SHIFT)) & FLASH_NMPA_TRNG_SDCTL_TRNG_ENT_DLY_MASK)
/*! @} */

/*! @name TRNG_SBLIM -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SBLIM_TRNG_SB_LIM_MASK   (0x3FFU)
#define FLASH_NMPA_TRNG_SBLIM_TRNG_SB_LIM_SHIFT  (0U)
#define FLASH_NMPA_TRNG_SBLIM_TRNG_SB_LIM(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SBLIM_TRNG_SB_LIM_SHIFT)) & FLASH_NMPA_TRNG_SBLIM_TRNG_SB_LIM_MASK)
/*! @} */

/*! @name TRNG_FRQMIN -  */
/*! @{ */

#define FLASH_NMPA_TRNG_FRQMIN_TRNG_FRQ_MIN_MASK (0x3FFFFFU)
#define FLASH_NMPA_TRNG_FRQMIN_TRNG_FRQ_MIN_SHIFT (0U)
#define FLASH_NMPA_TRNG_FRQMIN_TRNG_FRQ_MIN(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_FRQMIN_TRNG_FRQ_MIN_SHIFT)) & FLASH_NMPA_TRNG_FRQMIN_TRNG_FRQ_MIN_MASK)
/*! @} */

/*! @name TRNG_FRQMAX -  */
/*! @{ */

#define FLASH_NMPA_TRNG_FRQMAX_TRNG_FRQ_MAX_MASK (0x3FFFFFU)
#define FLASH_NMPA_TRNG_FRQMAX_TRNG_FRQ_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_FRQMAX_TRNG_FRQ_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_FRQMAX_TRNG_FRQ_MAX_SHIFT)) & FLASH_NMPA_TRNG_FRQMAX_TRNG_FRQ_MAX_MASK)
/*! @} */

/*! @name TRNG_SCML -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_MAX_MASK  (0xFFFFU)
#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_MAX(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCML_TRNG_MONO_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCML_TRNG_MONO_MAX_MASK)

#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_RNG_MASK  (0xFFFF0000U)
#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCML_TRNG_MONO_RNG(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCML_TRNG_MONO_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCML_TRNG_MONO_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR1L -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_MAX_MASK (0x7FFFU)
#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_RNG_MASK (0x7FFF0000U)
#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR1L_TRNG_RUN1_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR2L -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_MAX_MASK (0x3FFFU)
#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_RNG_MASK (0x3FFF0000U)
#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR2L_TRNG_RUN2_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR3L -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_MAX_MASK (0x1FFFU)
#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_RNG_MASK (0x1FFF0000U)
#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR3L_TRNG_RUN3_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR4L -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_MAX_MASK (0xFFFU)
#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_RNG_MASK (0xFFF0000U)
#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR4L_TRNG_RUN4_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR5L -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_MAX_MASK (0x7FFU)
#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_MAX(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_RNG_MASK (0x7FF0000U)
#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_RNG(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR5L_TRNG_RUN5_RNG_MASK)
/*! @} */

/*! @name TRNG_SCR6PL -  */
/*! @{ */

#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_MAX_MASK (0x7FFU)
#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_MAX_SHIFT (0U)
#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_MAX(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_MAX_SHIFT)) & FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_MAX_MASK)

#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_RNG_MASK (0x7FF0000U)
#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_RNG_SHIFT (16U)
#define FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_RNG(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_RNG_SHIFT)) & FLASH_NMPA_TRNG_SCR6PL_TRNG_RUN6P_RNG_MASK)
/*! @} */

/*! @name DEVICE_TYPE -  */
/*! @{ */

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK (0xFFFFU)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT (0U)
/*! DEVICE_TYPE_NUM - Device type number. (E.g : MCXW23 stored as 5204 decimal) */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_NUM_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK (0x10000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT (16U)
/*! DEVICE_TYPE_SEC - Security device type: 0: NHS52xx (Non Secure Family) 1: NHS52Sxx (Secure Family) */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_SEC_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK (0xF00000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT (20U)
/*! DEVICE_TYPE_PKG - Device package type: 0010 : HVQFN 0100 : VFBGA 1000 : WLCSP */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PKG_MASK)

#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK (0xFF000000U)
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT (24U)
/*! DEVICE_TYPE_PIN - Number of pins on the package. */
#define FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_SHIFT)) & FLASH_NMPA_DEVICE_TYPE_DEVICE_TYPE_PIN_MASK)
/*! @} */

/*! @name BLE_DEFAULT_ADDRESS0 - BLE_DEFAULT_ADDRESS part 1 */
/*! @{ */

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_MASK (0xFFFFFFU)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_SHIFT (0U)
/*! BLE_DEFAULT_ADDRESS_23_0 - Bits 24 downto 0 of the BLE Default Address to be used when BLE_DEFAULT_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_23_0_MASK)

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_MASK (0xFF000000U)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_SHIFT (24U)
/*! BLE_DEFAULT_ADDRESS_VALID - Use 48-bit value from BLE_DEFAULT_ADDRESS field as BLE address when
 *    this field is equal to 0xA5 and BLE_DEFAULT_ADDRESS_VALID_DP = 0xC3. If these fields are
 *    different from 0xC3A5, use a random number as BLE address
 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS0_BLE_DEFAULT_ADDRESS_VALID_MASK)
/*! @} */

/*! @name BLE_DEFAULT_ADDRESS1 - BLE_DEFAULT_ADDRESS part 2 */
/*! @{ */

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_MASK (0xFFFFFFU)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_SHIFT (0U)
/*! BLE_DEFAULT_ADDRESS_47_24 - Bits 47 downto 24 of the BLE Default Address to be used when BLE_DEFAULT_ADDRESS_VALID field is equal to 0xC3A5 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_47_24_MASK)

#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_MASK (0xFF000000U)
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_SHIFT (24U)
/*! BLE_DEFAULT_ADDRESS_VALID_DP - Use 48-bit value from BLE_DEFAULT_ADDRESS field as BLE address
 *    when this field is equal to 0xC3 and BLE_DEFAULT_ADDRESS_VALID = 0xA5. If these fields are
 *    different from 0xC3A5, use a random number as BLE address
 */
#define FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_SHIFT)) & FLASH_NMPA_BLE_DEFAULT_ADDRESS1_BLE_DEFAULT_ADDRESS_VALID_DP_MASK)
/*! @} */

/*! @name UUID_0 -  */
/*! @{ */

#define FLASH_NMPA_UUID_0_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_0_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_0_FIELD_SHIFT)) & FLASH_NMPA_UUID_0_FIELD_MASK)
/*! @} */

/*! @name UUID_1 -  */
/*! @{ */

#define FLASH_NMPA_UUID_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_1_FIELD_SHIFT)) & FLASH_NMPA_UUID_1_FIELD_MASK)
/*! @} */

/*! @name UUID_2 -  */
/*! @{ */

#define FLASH_NMPA_UUID_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_2_FIELD_SHIFT)) & FLASH_NMPA_UUID_2_FIELD_MASK)
/*! @} */

/*! @name UUID_3 -  */
/*! @{ */

#define FLASH_NMPA_UUID_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_UUID_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_3_FIELD_SHIFT)) & FLASH_NMPA_UUID_3_FIELD_MASK)
/*! @} */

/*! @name UUID_ARRAY -  */
/*! @{ */

#define FLASH_NMPA_UUID_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_UUID_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_UUID_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_UUID_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_UUID_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_UUID_ARRAY */
#define FLASH_NMPA_UUID_ARRAY_COUNT              (4U)

/*! @name PERIPHENCFG -  */
/*! @{ */

#define FLASH_NMPA_PERIPHENCFG_PERIPHERAL_CONFIGURATION_MASK (0xFFFFU)
#define FLASH_NMPA_PERIPHENCFG_PERIPHERAL_CONFIGURATION_SHIFT (0U)
#define FLASH_NMPA_PERIPHENCFG_PERIPHERAL_CONFIGURATION(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PERIPHENCFG_PERIPHERAL_CONFIGURATION_SHIFT)) & FLASH_NMPA_PERIPHENCFG_PERIPHERAL_CONFIGURATION_MASK)

#define FLASH_NMPA_PERIPHENCFG_MCM33_ENABLE_MASK (0x80000000U)
#define FLASH_NMPA_PERIPHENCFG_MCM33_ENABLE_SHIFT (31U)
#define FLASH_NMPA_PERIPHENCFG_MCM33_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PERIPHENCFG_MCM33_ENABLE_SHIFT)) & FLASH_NMPA_PERIPHENCFG_MCM33_ENABLE_MASK)
/*! @} */

/*! @name RAMSIZECFG -  */
/*! @{ */

#define FLASH_NMPA_RAMSIZECFG_SRAM_CONFIGURATION_MASK (0xFFFFFFFFU)
#define FLASH_NMPA_RAMSIZECFG_SRAM_CONFIGURATION_SHIFT (0U)
#define FLASH_NMPA_RAMSIZECFG_SRAM_CONFIGURATION(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RAMSIZECFG_SRAM_CONFIGURATION_SHIFT)) & FLASH_NMPA_RAMSIZECFG_SRAM_CONFIGURATION_MASK)
/*! @} */

/*! @name FLASHSIZECFG -  */
/*! @{ */

#define FLASH_NMPA_FLASHSIZECFG_FLASH_CONFIGURATION_MASK (0xFFFFFFFFU)
#define FLASH_NMPA_FLASHSIZECFG_FLASH_CONFIGURATION_SHIFT (0U)
#define FLASH_NMPA_FLASHSIZECFG_FLASH_CONFIGURATION(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FLASHSIZECFG_FLASH_CONFIGURATION_SHIFT)) & FLASH_NMPA_FLASHSIZECFG_FLASH_CONFIGURATION_MASK)
/*! @} */

/*! @name DIS_ROM_HIDING -  */
/*! @{ */

#define FLASH_NMPA_DIS_ROM_HIDING_DIS_ROM_HIDING_MASK (0xFFFFFFFFU)
#define FLASH_NMPA_DIS_ROM_HIDING_DIS_ROM_HIDING_SHIFT (0U)
/*! DIS_ROM_HIDING - When 0x3CC35AA5 ROM hiding feture is disabled. All other values critical ROM is hidden. */
#define FLASH_NMPA_DIS_ROM_HIDING_DIS_ROM_HIDING(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DIS_ROM_HIDING_DIS_ROM_HIDING_SHIFT)) & FLASH_NMPA_DIS_ROM_HIDING_DIS_ROM_HIDING_MASK)
/*! @} */

/*! @name RINGO_0 -  */
/*! @{ */

#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL_VALID_MASK (0x1U)
#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL_VALID_SHIFT (0U)
/*! RINGO_0_CTRL_VALID - 1: RINGO_0_CTRL is valid. */
#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_0_RINGO_0_CTRL_VALID_SHIFT)) & FLASH_NMPA_RINGO_0_RINGO_0_CTRL_VALID_MASK)

#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL_MASK     (0xFFFFFFFEU)
#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL_SHIFT    (1U)
/*! RINGO_0_CTRL - To copy RINGO_0_CTRL = ANACTRL->RINGO0_CTRL[30:0] */
#define FLASH_NMPA_RINGO_0_RINGO_0_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_0_RINGO_0_CTRL_SHIFT)) & FLASH_NMPA_RINGO_0_RINGO_0_CTRL_MASK)
/*! @} */

/*! @name RINGO_1 -  */
/*! @{ */

#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL_VALID_MASK (0x1U)
#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL_VALID_SHIFT (0U)
/*! RINGO_1_CTRL_VALID - 1: RINGO_1_CTRL is valid. */
#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_1_RINGO_1_CTRL_VALID_SHIFT)) & FLASH_NMPA_RINGO_1_RINGO_1_CTRL_VALID_MASK)

#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL_MASK     (0xFFFFFFFEU)
#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL_SHIFT    (1U)
/*! RINGO_1_CTRL - To copy RINGO_1_CTRL = ANACTRL->RINGO1_CTRL[30:0] */
#define FLASH_NMPA_RINGO_1_RINGO_1_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_1_RINGO_1_CTRL_SHIFT)) & FLASH_NMPA_RINGO_1_RINGO_1_CTRL_MASK)
/*! @} */

/*! @name RINGO_2 -  */
/*! @{ */

#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL_VALID_MASK (0x1U)
#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL_VALID_SHIFT (0U)
/*! RINGO_2_CTRL_VALID - 1: RINGO_2_CTRL is valid. */
#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_2_RINGO_2_CTRL_VALID_SHIFT)) & FLASH_NMPA_RINGO_2_RINGO_2_CTRL_VALID_MASK)

#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL_MASK     (0xFFFFFFFEU)
#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL_SHIFT    (1U)
/*! RINGO_2_CTRL - To copy RINGO_2_CTRL = ANACTRL->RINGO2_CTRL[30:0] */
#define FLASH_NMPA_RINGO_2_RINGO_2_CTRL(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_RINGO_2_RINGO_2_CTRL_SHIFT)) & FLASH_NMPA_RINGO_2_RINGO_2_CTRL_MASK)
/*! @} */

/*! @name PUF_SRAM -  */
/*! @{ */

#define FLASH_NMPA_PUF_SRAM_PUF_SRAM_VALID_MASK  (0x1U)
#define FLASH_NMPA_PUF_SRAM_PUF_SRAM_VALID_SHIFT (0U)
/*! PUF_SRAM_VALID - 1: PUF_SRAM is valid. */
#define FLASH_NMPA_PUF_SRAM_PUF_SRAM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_PUF_SRAM_VALID_SHIFT)) & FLASH_NMPA_PUF_SRAM_PUF_SRAM_VALID_MASK)

#define FLASH_NMPA_PUF_SRAM_mode_MASK            (0x2U)
#define FLASH_NMPA_PUF_SRAM_mode_SHIFT           (1U)
/*! mode - PUF SRAM Controller operating mode */
#define FLASH_NMPA_PUF_SRAM_mode(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_mode_SHIFT)) & FLASH_NMPA_PUF_SRAM_mode_MASK)

#define FLASH_NMPA_PUF_SRAM_ckgating_MASK        (0x4U)
#define FLASH_NMPA_PUF_SRAM_ckgating_SHIFT       (2U)
/*! ckgating - PUF SRAM Clock Gating control */
#define FLASH_NMPA_PUF_SRAM_ckgating(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_ckgating_SHIFT)) & FLASH_NMPA_PUF_SRAM_ckgating_MASK)

#define FLASH_NMPA_PUF_SRAM_SMB_MASK             (0x700U)
#define FLASH_NMPA_PUF_SRAM_SMB_SHIFT            (8U)
/*! SMB - Source Biasing voltage.
 *  0b000..Disable.
 *  0b100..Low leakage.
 *  0b101..Medium leakage.
 *  0b110..Highest leakage.
 *  0b111..Highest leakage.
 */
#define FLASH_NMPA_PUF_SRAM_SMB(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_SMB_SHIFT)) & FLASH_NMPA_PUF_SRAM_SMB_MASK)

#define FLASH_NMPA_PUF_SRAM_RM_MASK              (0xF800U)
#define FLASH_NMPA_PUF_SRAM_RM_SHIFT             (11U)
/*! RM - Read Margin control settings. */
#define FLASH_NMPA_PUF_SRAM_RM(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_RM_SHIFT)) & FLASH_NMPA_PUF_SRAM_RM_MASK)

#define FLASH_NMPA_PUF_SRAM_WM_MASK              (0x70000U)
#define FLASH_NMPA_PUF_SRAM_WM_SHIFT             (16U)
/*! WM - Write Margin control settings. */
#define FLASH_NMPA_PUF_SRAM_WM(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_WM_SHIFT)) & FLASH_NMPA_PUF_SRAM_WM_MASK)

#define FLASH_NMPA_PUF_SRAM_RAM_MASK             (0x180000U)
#define FLASH_NMPA_PUF_SRAM_RAM_SHIFT            (19U)
/*! RAM - SRAM Read Assist settings */
#define FLASH_NMPA_PUF_SRAM_RAM(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_RAM_SHIFT)) & FLASH_NMPA_PUF_SRAM_RAM_MASK)

#define FLASH_NMPA_PUF_SRAM_WAM_MASK             (0xE00000U)
#define FLASH_NMPA_PUF_SRAM_WAM_SHIFT            (21U)
/*! WAM - SRAM Write Assist settings */
#define FLASH_NMPA_PUF_SRAM_WAM(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_PUF_SRAM_WAM_SHIFT)) & FLASH_NMPA_PUF_SRAM_WAM_MASK)
/*! @} */

/*! @name BOD - BOD */
/*! @{ */

#define FLASH_NMPA_BOD_BOD1_TRIM_VALID_MASK      (0x1U)
#define FLASH_NMPA_BOD_BOD1_TRIM_VALID_SHIFT     (0U)
/*! BOD1_TRIM_VALID - BOD1_TRIM_VALID */
#define FLASH_NMPA_BOD_BOD1_TRIM_VALID(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD1_TRIM_VALID_SHIFT)) & FLASH_NMPA_BOD_BOD1_TRIM_VALID_MASK)

#define FLASH_NMPA_BOD_BOD1_TRIGLVL_MASK         (0x3EU)
#define FLASH_NMPA_BOD_BOD1_TRIGLVL_SHIFT        (1U)
/*! BOD1_TRIGLVL - BOD1_TRIGLVL */
#define FLASH_NMPA_BOD_BOD1_TRIGLVL(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD1_TRIGLVL_SHIFT)) & FLASH_NMPA_BOD_BOD1_TRIGLVL_MASK)

#define FLASH_NMPA_BOD_BOD1_HYST_MASK            (0xC0U)
#define FLASH_NMPA_BOD_BOD1_HYST_SHIFT           (6U)
/*! BOD1_HYST - BOD1_HYST */
#define FLASH_NMPA_BOD_BOD1_HYST(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD1_HYST_SHIFT)) & FLASH_NMPA_BOD_BOD1_HYST_MASK)

#define FLASH_NMPA_BOD_BOD1_MODE_MASK            (0x100U)
#define FLASH_NMPA_BOD_BOD1_MODE_SHIFT           (8U)
/*! BOD1_MODE - BOD1_MODE */
#define FLASH_NMPA_BOD_BOD1_MODE(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD1_MODE_SHIFT)) & FLASH_NMPA_BOD_BOD1_MODE_MASK)

#define FLASH_NMPA_BOD_BOD1_LVLSEL_MASK          (0x200U)
#define FLASH_NMPA_BOD_BOD1_LVLSEL_SHIFT         (9U)
/*! BOD1_LVLSEL - BOD1_LVLSEL */
#define FLASH_NMPA_BOD_BOD1_LVLSEL(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD1_LVLSEL_SHIFT)) & FLASH_NMPA_BOD_BOD1_LVLSEL_MASK)

#define FLASH_NMPA_BOD_BOD2_TRIM_VALID_MASK      (0x10000U)
#define FLASH_NMPA_BOD_BOD2_TRIM_VALID_SHIFT     (16U)
/*! BOD2_TRIM_VALID - BOD2_TRIM_VALID */
#define FLASH_NMPA_BOD_BOD2_TRIM_VALID(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD2_TRIM_VALID_SHIFT)) & FLASH_NMPA_BOD_BOD2_TRIM_VALID_MASK)

#define FLASH_NMPA_BOD_BOD2_TRIGLVL_MASK         (0x3E0000U)
#define FLASH_NMPA_BOD_BOD2_TRIGLVL_SHIFT        (17U)
/*! BOD2_TRIGLVL - BOD2_TRIGLVL */
#define FLASH_NMPA_BOD_BOD2_TRIGLVL(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD2_TRIGLVL_SHIFT)) & FLASH_NMPA_BOD_BOD2_TRIGLVL_MASK)

#define FLASH_NMPA_BOD_BOD2_HYST_MASK            (0xC00000U)
#define FLASH_NMPA_BOD_BOD2_HYST_SHIFT           (22U)
/*! BOD2_HYST - BOD2_HYST */
#define FLASH_NMPA_BOD_BOD2_HYST(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD2_HYST_SHIFT)) & FLASH_NMPA_BOD_BOD2_HYST_MASK)

#define FLASH_NMPA_BOD_BOD2_MODE_MASK            (0x1000000U)
#define FLASH_NMPA_BOD_BOD2_MODE_SHIFT           (24U)
/*! BOD2_MODE - BOD2_MODE */
#define FLASH_NMPA_BOD_BOD2_MODE(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD2_MODE_SHIFT)) & FLASH_NMPA_BOD_BOD2_MODE_MASK)

#define FLASH_NMPA_BOD_BOD2_LVLSEL_MASK          (0x2000000U)
#define FLASH_NMPA_BOD_BOD2_LVLSEL_SHIFT         (25U)
/*! BOD2_LVLSEL - BOD2_LVLSEL */
#define FLASH_NMPA_BOD_BOD2_LVLSEL(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BOD_BOD2_LVLSEL_SHIFT)) & FLASH_NMPA_BOD_BOD2_LVLSEL_MASK)
/*! @} */

/*! @name LDO_MEM - LDO_MEM */
/*! @{ */

#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_VALID_SHIFT (0U)
/*! ACTIVE_TRIM_VALID - ACTIVE_TRIM_VALID */
#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_VALID(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_MASK      (0x3EU)
#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_SHIFT     (1U)
/*! ACTIVE_TRIM - ACTIVE_TRIM */
#define FLASH_NMPA_LDO_MEM_ACTIVE_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_SHIFT)) & FLASH_NMPA_LDO_MEM_ACTIVE_TRIM_MASK)

#define FLASH_NMPA_LDO_MEM_DSLP_TRIM_VALID_MASK  (0x100U)
#define FLASH_NMPA_LDO_MEM_DSLP_TRIM_VALID_SHIFT (8U)
/*! DSLP_TRIM_VALID - DSLP_TRIM_VALID */
#define FLASH_NMPA_LDO_MEM_DSLP_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_DSLP_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_MEM_DSLP_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_MEM_DSLP_TRIM_MASK        (0x3E00U)
#define FLASH_NMPA_LDO_MEM_DSLP_TRIM_SHIFT       (9U)
/*! DSLP_TRIM - DSLP_TRIM */
#define FLASH_NMPA_LDO_MEM_DSLP_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_DSLP_TRIM_SHIFT)) & FLASH_NMPA_LDO_MEM_DSLP_TRIM_MASK)

#define FLASH_NMPA_LDO_MEM_PDWN_TRIM_VALID_MASK  (0x10000U)
#define FLASH_NMPA_LDO_MEM_PDWN_TRIM_VALID_SHIFT (16U)
/*! PDWN_TRIM_VALID - PDWN_TRIM_VALID */
#define FLASH_NMPA_LDO_MEM_PDWN_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_PDWN_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_MEM_PDWN_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_MEM_PDWN_TRIM_MASK        (0x3E0000U)
#define FLASH_NMPA_LDO_MEM_PDWN_TRIM_SHIFT       (17U)
/*! PDWN_TRIM - PDWN_TRIM */
#define FLASH_NMPA_LDO_MEM_PDWN_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_PDWN_TRIM_SHIFT)) & FLASH_NMPA_LDO_MEM_PDWN_TRIM_MASK)

#define FLASH_NMPA_LDO_MEM_DPDW_TRIM_VALID_MASK  (0x1000000U)
#define FLASH_NMPA_LDO_MEM_DPDW_TRIM_VALID_SHIFT (24U)
/*! DPDW_TRIM_VALID - DPDW_TRIM_VALID */
#define FLASH_NMPA_LDO_MEM_DPDW_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_DPDW_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_MEM_DPDW_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_MEM_DPDW_TRIM_MASK        (0x3E000000U)
#define FLASH_NMPA_LDO_MEM_DPDW_TRIM_SHIFT       (25U)
/*! DPDW_TRIM - DPDW_TRIM */
#define FLASH_NMPA_LDO_MEM_DPDW_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_MEM_DPDW_TRIM_SHIFT)) & FLASH_NMPA_LDO_MEM_DPDW_TRIM_MASK)
/*! @} */

/*! @name LDO_DIG - LDO_DIG */
/*! @{ */

#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_VALID_SHIFT (0U)
/*! ACTIVE_TRIM_VALID - ACTIVE_TRIM_VALID */
#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_VALID(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_MASK      (0x3EU)
#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_SHIFT     (1U)
/*! ACTIVE_TRIM - ACTIVE_TRIM */
#define FLASH_NMPA_LDO_DIG_ACTIVE_TRIM(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_SHIFT)) & FLASH_NMPA_LDO_DIG_ACTIVE_TRIM_MASK)

#define FLASH_NMPA_LDO_DIG_DSLP_TRIM_VALID_MASK  (0x100U)
#define FLASH_NMPA_LDO_DIG_DSLP_TRIM_VALID_SHIFT (8U)
/*! DSLP_TRIM_VALID - DSLP_TRIM_VALID */
#define FLASH_NMPA_LDO_DIG_DSLP_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_DSLP_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_DIG_DSLP_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_DIG_DSLP_TRIM_MASK        (0x3E00U)
#define FLASH_NMPA_LDO_DIG_DSLP_TRIM_SHIFT       (9U)
/*! DSLP_TRIM - DSLP_TRIM */
#define FLASH_NMPA_LDO_DIG_DSLP_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_DSLP_TRIM_SHIFT)) & FLASH_NMPA_LDO_DIG_DSLP_TRIM_MASK)

#define FLASH_NMPA_LDO_DIG_PDWN_TRIM_VALID_MASK  (0x10000U)
#define FLASH_NMPA_LDO_DIG_PDWN_TRIM_VALID_SHIFT (16U)
/*! PDWN_TRIM_VALID - PDWN_TRIM_VALID */
#define FLASH_NMPA_LDO_DIG_PDWN_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_PDWN_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_DIG_PDWN_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_DIG_PDWN_TRIM_MASK        (0x3E0000U)
#define FLASH_NMPA_LDO_DIG_PDWN_TRIM_SHIFT       (17U)
/*! PDWN_TRIM - PDWN_TRIM */
#define FLASH_NMPA_LDO_DIG_PDWN_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_PDWN_TRIM_SHIFT)) & FLASH_NMPA_LDO_DIG_PDWN_TRIM_MASK)

#define FLASH_NMPA_LDO_DIG_DPDW_TRIM_VALID_MASK  (0x1000000U)
#define FLASH_NMPA_LDO_DIG_DPDW_TRIM_VALID_SHIFT (24U)
/*! DPDW_TRIM_VALID - DPDW_TRIM_VALID */
#define FLASH_NMPA_LDO_DIG_DPDW_TRIM_VALID(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_DPDW_TRIM_VALID_SHIFT)) & FLASH_NMPA_LDO_DIG_DPDW_TRIM_VALID_MASK)

#define FLASH_NMPA_LDO_DIG_DPDW_TRIM_MASK        (0x3E000000U)
#define FLASH_NMPA_LDO_DIG_DPDW_TRIM_SHIFT       (25U)
/*! DPDW_TRIM - DPDW_TRIM */
#define FLASH_NMPA_LDO_DIG_DPDW_TRIM(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LDO_DIG_DPDW_TRIM_SHIFT)) & FLASH_NMPA_LDO_DIG_DPDW_TRIM_MASK)
/*! @} */

/*! @name BLE_TEST - BLE_TEST */
/*! @{ */

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_MASK (0x10U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_SHIFT (4U)
/*! CHAN15_LRS8_PWR_LIMIT_SPUR - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_MASK (0x20U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_SHIFT (5U)
/*! CHAN31_LRS8_PWR_LIMIT_SPUR - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_MASK (0x40U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_SHIFT (6U)
/*! CHAN15_BLE1_PWR_LIMIT_SPUR - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_MASK (0x80U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_SHIFT (7U)
/*! CHAN31_BLE1_PWR_LIMIT_SPUR - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on SPUR production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_SPUR_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_MASK (0x100U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_SHIFT (8U)
/*! CHAN15_LRS8_PWR_LIMIT_NO_TEST - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_MASK (0x200U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_SHIFT (9U)
/*! CHAN31_LRS8_PWR_LIMIT_NO_TEST - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_MASK (0x400U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_SHIFT (10U)
/*! CHAN15_BLE1_PWR_LIMIT_NO_TEST - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_MASK (0x800U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_SHIFT (11U)
/*! CHAN31_BLE1_PWR_LIMIT_NO_TEST - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_NO_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_MASK (0x100000U)
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_SHIFT (20U)
/*! CHAN15_LRS8_PWR_LIMIT_MOD - Indicates if power on channel 15 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_LRS8_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_MASK (0x200000U)
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_SHIFT (21U)
/*! CHAN31_LRS8_PWR_LIMIT_MOD - Indicates if power on channel 31 and PHY LRS8 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_LRS8_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_MASK (0x400000U)
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_SHIFT (22U)
/*! CHAN15_BLE1_PWR_LIMIT_MOD - Indicates if power on channel 15 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN15_BLE1_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_MASK (0x800000U)
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_SHIFT (23U)
/*! CHAN31_BLE1_PWR_LIMIT_MOD - Indicates if power on channel 31 and PHY BLE1 must be limited to 2dBm (based on modulation production test result) */
#define FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_SHIFT)) & FLASH_NMPA_BLE_TEST_CHAN31_BLE1_PWR_LIMIT_MOD_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_MASK   (0x1000000U)
#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_SHIFT  (24U)
/*! BLE_SPUR_TEST - If 0x1, BLE SPUR production test is run and passing */
#define FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_SPUR_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_MASK    (0x2000000U)
#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_SHIFT   (25U)
/*! BLE_MOD_TEST - If 0x1, BLE SPUR production test is run and passing */
#define FLASH_NMPA_BLE_TEST_BLE_MOD_TEST(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_MOD_TEST_MASK)

#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST_MASK     (0x4000000U)
#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST_SHIFT    (26U)
/*! BLE_NO_TEST - If 0x1, BLE NO production test is run but tx power limit is forced */
#define FLASH_NMPA_BLE_TEST_BLE_NO_TEST(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_BLE_TEST_BLE_NO_TEST_SHIFT)) & FLASH_NMPA_BLE_TEST_BLE_NO_TEST_MASK)
/*! @} */

/*! @name DCDC_POWER_PROFILE_LOW -  */
/*! @{ */

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DCDC_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DCDC_TRIM_VALID_SHIFT (0U)
/*! DCDC_TRIM_VALID - DCDC is trimmed. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DCDC_TRIM_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DCDC_TRIM_VALID_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DCDC_TRIM_VALID_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_RC_MASK (0x7EU)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_RC_SHIFT (1U)
/*! RC - Constant On-Time calibration. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_RC(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_RC_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_RC_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICOMP_MASK (0x180U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICOMP_SHIFT (7U)
/*! ICOMP - Select the type of ZCD comparator. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICOMP(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICOMP_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICOMP_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ISEL_MASK (0x600U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ISEL_SHIFT (9U)
/*! ISEL - Alter Internal biasing currents. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ISEL(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ISEL_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ISEL_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICENABLE_MASK (0x800U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICENABLE_SHIFT (11U)
/*! ICENABLE - Selection of auto scaling of COT period with variations in VDD. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_ICENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_TMOS_MASK (0x1F000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_TMOS_SHIFT (12U)
/*! TMOS - One-shot generator reference current trimming signal. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_TMOS(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_TMOS_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_TMOS_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DISABLEISENSE_MASK (0x20000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DISABLEISENSE_SHIFT (17U)
/*! DISABLEISENSE - Disable Current sensing. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DISABLEISENSE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DISABLEISENSE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_DISABLEISENSE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_MASK (0x3C0000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_SHIFT (18U)
/*! VOUT - Set output regulation voltage. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_SLICINGENABLE_MASK (0x400000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_SLICINGENABLE_SHIFT (22U)
/*! SLICINGENABLE - Enable staggered switching of power switches. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_SLICINGENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_SLICINGENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_SLICINGENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_INDUCTORCLAMPENABLE_MASK (0x800000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_INDUCTORCLAMPENABLE_SHIFT (23U)
/*! INDUCTORCLAMPENABLE - Enable shorting of Inductor during PFM idle time. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_INDUCTORCLAMPENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_INDUCTORCLAMPENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_INDUCTORCLAMPENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_PWD_MASK (0xF000000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_PWD_SHIFT (24U)
/*! VOUT_PWD - Set output regulation voltage during Deep Sleep. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_PWD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_PWD_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_LOW_VOUT_PWD_MASK)
/*! @} */

/*! @name DCDC_POWER_PROFILE_MEDIUM -  */
/*! @{ */

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DCDC_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DCDC_TRIM_VALID_SHIFT (0U)
/*! DCDC_TRIM_VALID - DCDC is trimed. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DCDC_TRIM_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DCDC_TRIM_VALID_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DCDC_TRIM_VALID_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_RC_MASK (0x7EU)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_RC_SHIFT (1U)
/*! RC - Constant On-Time calibration. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_RC(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_RC_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_RC_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICOMP_MASK (0x180U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICOMP_SHIFT (7U)
/*! ICOMP - Select the type of ZCD comparator. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICOMP(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICOMP_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICOMP_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ISEL_MASK (0x600U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ISEL_SHIFT (9U)
/*! ISEL - Alter Internal biasing currents. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ISEL(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ISEL_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ISEL_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICENABLE_MASK (0x800U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICENABLE_SHIFT (11U)
/*! ICENABLE - Selection of auto scaling of COT period with variations in VDD. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_ICENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_TMOS_MASK (0x1F000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_TMOS_SHIFT (12U)
/*! TMOS - One-shot generator reference current trimming signal. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_TMOS(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_TMOS_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_TMOS_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DISABLEISENSE_MASK (0x20000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DISABLEISENSE_SHIFT (17U)
/*! DISABLEISENSE - Disable Current sensing. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DISABLEISENSE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DISABLEISENSE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_DISABLEISENSE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_MASK (0x3C0000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_SHIFT (18U)
/*! VOUT - Set output regulation voltage. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_SLICINGENABLE_MASK (0x400000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_SLICINGENABLE_SHIFT (22U)
/*! SLICINGENABLE - Enable staggered switching of power switches. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_SLICINGENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_SLICINGENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_SLICINGENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_INDUCTORCLAMPENABLE_MASK (0x800000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_INDUCTORCLAMPENABLE_SHIFT (23U)
/*! INDUCTORCLAMPENABLE - Enable shorting of Inductor during PFM idle time. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_INDUCTORCLAMPENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_INDUCTORCLAMPENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_INDUCTORCLAMPENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_PWD_MASK (0xF000000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_PWD_SHIFT (24U)
/*! VOUT_PWD - Set output regulation voltage during Deep Sleep. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_PWD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_PWD_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_MEDIUM_VOUT_PWD_MASK)
/*! @} */

/*! @name DCDC_POWER_PROFILE_HIGH -  */
/*! @{ */

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DCDC_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DCDC_TRIM_VALID_SHIFT (0U)
/*! DCDC_TRIM_VALID - DCDC is trimed. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DCDC_TRIM_VALID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DCDC_TRIM_VALID_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DCDC_TRIM_VALID_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_RC_MASK (0x7EU)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_RC_SHIFT (1U)
/*! RC - Constant On-Time calibration. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_RC(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_RC_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_RC_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICOMP_MASK (0x180U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICOMP_SHIFT (7U)
/*! ICOMP - Select the type of ZCD comparator. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICOMP(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICOMP_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICOMP_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ISEL_MASK (0x600U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ISEL_SHIFT (9U)
/*! ISEL - Alter Internal biasing currents. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ISEL(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ISEL_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ISEL_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICENABLE_MASK (0x800U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICENABLE_SHIFT (11U)
/*! ICENABLE - Selection of auto scaling of COT period with variations in VDD. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_ICENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_TMOS_MASK (0x1F000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_TMOS_SHIFT (12U)
/*! TMOS - One-shot generator reference current trimming signal. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_TMOS(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_TMOS_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_TMOS_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DISABLEISENSE_MASK (0x20000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DISABLEISENSE_SHIFT (17U)
/*! DISABLEISENSE - Disable Current sensing. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DISABLEISENSE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DISABLEISENSE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_DISABLEISENSE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_MASK (0x3C0000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_SHIFT (18U)
/*! VOUT - Set output regulation voltage. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_SLICINGENABLE_MASK (0x400000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_SLICINGENABLE_SHIFT (22U)
/*! SLICINGENABLE - Enable staggered switching of power switches. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_SLICINGENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_SLICINGENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_SLICINGENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_INDUCTORCLAMPENABLE_MASK (0x800000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_INDUCTORCLAMPENABLE_SHIFT (23U)
/*! INDUCTORCLAMPENABLE - Enable shorting of Inductor during PFM idle time. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_INDUCTORCLAMPENABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_INDUCTORCLAMPENABLE_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_INDUCTORCLAMPENABLE_MASK)

#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_PWD_MASK (0xF000000U)
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_PWD_SHIFT (24U)
/*! VOUT_PWD - Set output regulation voltage during Deep Sleep. */
#define FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_PWD(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_PWD_SHIFT)) & FLASH_NMPA_DCDC_POWER_PROFILE_HIGH_VOUT_PWD_MASK)
/*! @} */

/*! @name SHA256_DIGEST - SHA-256 DIGEST (0000 - 0BEC and 1800 - 187C) ROM Patch Area + NXP Area + GPO SHA256_DIGEST0 for DIGEST[31:0] SHA256_DIGEST1 for DIGEST[63:32] SHA256_DIGEST2 for DIGEST[95:64] SHA256_DIGEST3 for DIGEST[127:96] SHA256_DIGEST4 for DIGEST[159:128] SHA256_DIGEST5 for DIGEST[191:160] SHA256_DIGEST6 for DIGEST[223:192] SHA256_DIGEST7 for DIGEST[255:224] */
/*! @{ */

#define FLASH_NMPA_SHA256_DIGEST_FIELD_MASK      (0xFFFFFFFFU)
#define FLASH_NMPA_SHA256_DIGEST_FIELD_SHIFT     (0U)
/*! FIELD - . */
#define FLASH_NMPA_SHA256_DIGEST_FIELD(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_SHA256_DIGEST_FIELD_SHIFT)) & FLASH_NMPA_SHA256_DIGEST_FIELD_MASK)
/*! @} */

/*! @name LOTID_0 - MCXW23 Lot ID */
/*! @{ */

#define FLASH_NMPA_LOTID_0_LOTID_31_0_MASK       (0xFFFFFFFFU)
#define FLASH_NMPA_LOTID_0_LOTID_31_0_SHIFT      (0U)
/*! LOTID_31_0 - Bits 31 downto 0 for LotID */
#define FLASH_NMPA_LOTID_0_LOTID_31_0(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LOTID_0_LOTID_31_0_SHIFT)) & FLASH_NMPA_LOTID_0_LOTID_31_0_MASK)
/*! @} */

/*! @name LOTID_1 - MCXW23 Lot ID */
/*! @{ */

#define FLASH_NMPA_LOTID_1_LOTID_63_32_MASK      (0xFFFFFFFFU)
#define FLASH_NMPA_LOTID_1_LOTID_63_32_SHIFT     (0U)
/*! LOTID_63_32 - Bits 63 downto 32 for LotID */
#define FLASH_NMPA_LOTID_1_LOTID_63_32(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_LOTID_1_LOTID_63_32_SHIFT)) & FLASH_NMPA_LOTID_1_LOTID_63_32_MASK)
/*! @} */

/*! @name WAFERID - MCXW23 Wafer ID */
/*! @{ */

#define FLASH_NMPA_WAFERID_WAFERID_MASK          (0xFFFFFFFFU)
#define FLASH_NMPA_WAFERID_WAFERID_SHIFT         (0U)
/*! WAFERID - WaferID */
#define FLASH_NMPA_WAFERID_WAFERID(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_WAFERID_WAFERID_SHIFT)) & FLASH_NMPA_WAFERID_WAFERID_MASK)
/*! @} */

/*! @name DIE_X_Y - MCXW23 Die Coordinates */
/*! @{ */

#define FLASH_NMPA_DIE_X_Y_DIE_X_MASK            (0xFFFFU)
#define FLASH_NMPA_DIE_X_Y_DIE_X_SHIFT           (0U)
/*! DIE_X - Die X coordinates */
#define FLASH_NMPA_DIE_X_Y_DIE_X(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DIE_X_Y_DIE_X_SHIFT)) & FLASH_NMPA_DIE_X_Y_DIE_X_MASK)

#define FLASH_NMPA_DIE_X_Y_DIE_Y_MASK            (0xFFFF0000U)
#define FLASH_NMPA_DIE_X_Y_DIE_Y_SHIFT           (16U)
/*! DIE_Y - Die Y coordinates */
#define FLASH_NMPA_DIE_X_Y_DIE_Y(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_DIE_X_Y_DIE_Y_SHIFT)) & FLASH_NMPA_DIE_X_Y_DIE_Y_MASK)
/*! @} */

/*! @name FMUPARM0_0 - General FMU parameters */
/*! @{ */

#define FLASH_NMPA_FMUPARM0_0_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM0_0_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM0_0_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM0_0_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM0_0_FIELD_MASK)
/*! @} */

/*! @name FMUPARM0_1 - General FMU parameters */
/*! @{ */

#define FLASH_NMPA_FMUPARM0_1_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM0_1_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM0_1_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM0_1_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM0_1_FIELD_MASK)
/*! @} */

/*! @name FMUPARM0_2 - General FMU parameters */
/*! @{ */

#define FLASH_NMPA_FMUPARM0_2_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM0_2_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM0_2_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM0_2_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM0_2_FIELD_MASK)
/*! @} */

/*! @name FMUPARM0_3 - General FMU parameters */
/*! @{ */

#define FLASH_NMPA_FMUPARM0_3_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM0_3_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM0_3_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM0_3_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM0_3_FIELD_MASK)
/*! @} */

/*! @name FMUPARAM0_ARRAY - General FMU parameters */
/*! @{ */

#define FLASH_NMPA_FMUPARAM0_ARRAY_FIELD_MASK    (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARAM0_ARRAY_FIELD_SHIFT   (0U)
#define FLASH_NMPA_FMUPARAM0_ARRAY_FIELD(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARAM0_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_FMUPARAM0_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_FMUPARAM0_ARRAY */
#define FLASH_NMPA_FMUPARAM0_ARRAY_COUNT         (4U)

/*! @name FMUPARM1_0 - SMW timer options, SMW setting options */
/*! @{ */

#define FLASH_NMPA_FMUPARM1_0_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM1_0_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM1_0_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM1_0_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM1_0_FIELD_MASK)
/*! @} */

/*! @name FMUPARM1_1 - SMW timer options, SMW setting options */
/*! @{ */

#define FLASH_NMPA_FMUPARM1_1_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM1_1_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM1_1_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM1_1_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM1_1_FIELD_MASK)
/*! @} */

/*! @name FMUPARM1_2 - SMW timer options, SMW setting options */
/*! @{ */

#define FLASH_NMPA_FMUPARM1_2_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM1_2_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM1_2_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM1_2_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM1_2_FIELD_MASK)
/*! @} */

/*! @name FMUPARM1_3 - SMW timer options, SMW setting options */
/*! @{ */

#define FLASH_NMPA_FMUPARM1_3_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM1_3_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM1_3_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM1_3_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM1_3_FIELD_MASK)
/*! @} */

/*! @name FMUPARAM1_ARRAY - SMW timer options, SMW setting options */
/*! @{ */

#define FLASH_NMPA_FMUPARAM1_ARRAY_FIELD_MASK    (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARAM1_ARRAY_FIELD_SHIFT   (0U)
#define FLASH_NMPA_FMUPARAM1_ARRAY_FIELD(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARAM1_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_FMUPARAM1_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_FMUPARAM1_ARRAY */
#define FLASH_NMPA_FMUPARAM1_ARRAY_COUNT         (4U)

/*! @name FMUPARM2_0 - SMW setting options continued, SMW smart program/erase options */
/*! @{ */

#define FLASH_NMPA_FMUPARM2_0_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM2_0_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM2_0_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM2_0_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM2_0_FIELD_MASK)
/*! @} */

/*! @name FMUPARM2_1 - SMW setting options continued, SMW smart program/erase options */
/*! @{ */

#define FLASH_NMPA_FMUPARM2_1_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM2_1_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM2_1_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM2_1_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM2_1_FIELD_MASK)
/*! @} */

/*! @name FMUPARM2_2 - SMW setting options continued, SMW smart program/erase options */
/*! @{ */

#define FLASH_NMPA_FMUPARM2_2_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM2_2_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM2_2_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM2_2_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM2_2_FIELD_MASK)
/*! @} */

/*! @name FMUPARM2_3 - SMW setting options continued, SMW smart program/erase options */
/*! @{ */

#define FLASH_NMPA_FMUPARM2_3_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM2_3_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM2_3_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM2_3_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM2_3_FIELD_MASK)
/*! @} */

/*! @name FMUPARAM2_ARRAY - SMW setting options continued, SMW smart program/erase options */
/*! @{ */

#define FLASH_NMPA_FMUPARAM2_ARRAY_FIELD_MASK    (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARAM2_ARRAY_FIELD_SHIFT   (0U)
#define FLASH_NMPA_FMUPARAM2_ARRAY_FIELD(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARAM2_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_FMUPARAM2_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_FMUPARAM2_ARRAY */
#define FLASH_NMPA_FMUPARAM2_ARRAY_COUNT         (4U)

/*! @name FMUPARM3 - SMW smart erase options continued */
/*! @{ */

#define FLASH_NMPA_FMUPARM3_FIELD_MASK           (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM3_FIELD_SHIFT          (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM3_FIELD(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM3_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM3_FIELD_MASK)
/*! @} */

/*! @name FMUPARM4 - Array size (see MSIZE register) */
/*! @{ */

#define FLASH_NMPA_FMUPARM4_FIELD_MASK           (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM4_FIELD_SHIFT          (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM4_FIELD(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM4_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM4_FIELD_MASK)
/*! @} */

/*! @name FMUPARM5 - TME control (see FTEST register) */
/*! @{ */

#define FLASH_NMPA_FMUPARM5_FIELD_MASK           (0xFFFFFFFFU)
#define FLASH_NMPA_FMUPARM5_FIELD_SHIFT          (0U)
/*! FIELD - . */
#define FLASH_NMPA_FMUPARM5_FIELD(x)             (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_FMUPARM5_FIELD_SHIFT)) & FLASH_NMPA_FMUPARM5_FIELD_MASK)
/*! @} */

/*! @name SOCTRIMEN - C0DE_C0DE field at [31:0] to enable loading of SoC trim settings */
/*! @{ */

#define FLASH_NMPA_SOCTRIMEN_FIELD_MASK          (0xFFFFFFFFU)
#define FLASH_NMPA_SOCTRIMEN_FIELD_SHIFT         (0U)
/*! FIELD - . */
#define FLASH_NMPA_SOCTRIMEN_FIELD(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_SOCTRIMEN_FIELD_SHIFT)) & FLASH_NMPA_SOCTRIMEN_FIELD_MASK)
/*! @} */

/*! @name SOCTRIMECC - C0DE_C0DE field at [31:0] for controlling ECC decoder while fetching SoC trim settings */
/*! @{ */

#define FLASH_NMPA_SOCTRIMECC_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_SOCTRIMECC_FIELD_SHIFT        (0U)
/*! FIELD - . */
#define FLASH_NMPA_SOCTRIMECC_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_SOCTRIMECC_FIELD_SHIFT)) & FLASH_NMPA_SOCTRIMECC_FIELD_MASK)
/*! @} */

/*! @name GPO0_0 - GPO0 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO0_0_FRO_TRIM_VALID_MASK    (0x1U)
#define FLASH_NMPA_GPO0_0_FRO_TRIM_VALID_SHIFT   (0U)
#define FLASH_NMPA_GPO0_0_FRO_TRIM_VALID(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_FRO_TRIM_VALID_SHIFT)) & FLASH_NMPA_GPO0_0_FRO_TRIM_VALID_MASK)

#define FLASH_NMPA_GPO0_0_FRO32K_NTAT_MASK       (0xEU)
#define FLASH_NMPA_GPO0_0_FRO32K_NTAT_SHIFT      (1U)
#define FLASH_NMPA_GPO0_0_FRO32K_NTAT(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_FRO32K_NTAT_SHIFT)) & FLASH_NMPA_GPO0_0_FRO32K_NTAT_MASK)

#define FLASH_NMPA_GPO0_0_FRO32K_PTAT_MASK       (0x70U)
#define FLASH_NMPA_GPO0_0_FRO32K_PTAT_SHIFT      (4U)
#define FLASH_NMPA_GPO0_0_FRO32K_PTAT(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_FRO32K_PTAT_SHIFT)) & FLASH_NMPA_GPO0_0_FRO32K_PTAT_MASK)

#define FLASH_NMPA_GPO0_0_FRO32K_CAPCAL_MASK     (0xFF80U)
#define FLASH_NMPA_GPO0_0_FRO32K_CAPCAL_SHIFT    (7U)
#define FLASH_NMPA_GPO0_0_FRO32K_CAPCAL(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_FRO32K_CAPCAL_SHIFT)) & FLASH_NMPA_GPO0_0_FRO32K_CAPCAL_MASK)

#define FLASH_NMPA_GPO0_0_FIELD_MASK             (0x3FFF0000U)
#define FLASH_NMPA_GPO0_0_FIELD_SHIFT            (16U)
#define FLASH_NMPA_GPO0_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_FIELD_SHIFT)) & FLASH_NMPA_GPO0_0_FIELD_MASK)

#define FLASH_NMPA_GPO0_0_PMIC_ONLY_MASK         (0x40000000U)
#define FLASH_NMPA_GPO0_0_PMIC_ONLY_SHIFT        (30U)
#define FLASH_NMPA_GPO0_0_PMIC_ONLY(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_PMIC_ONLY_SHIFT)) & FLASH_NMPA_GPO0_0_PMIC_ONLY_MASK)

#define FLASH_NMPA_GPO0_0_DCDC_MASK              (0x80000000U)
#define FLASH_NMPA_GPO0_0_DCDC_SHIFT             (31U)
#define FLASH_NMPA_GPO0_0_DCDC(x)                (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_0_DCDC_SHIFT)) & FLASH_NMPA_GPO0_0_DCDC_MASK)
/*! @} */

/*! @name GPO0_1 - GPO0 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO0_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO0_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO0_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_1_FIELD_SHIFT)) & FLASH_NMPA_GPO0_1_FIELD_MASK)
/*! @} */

/*! @name GPO0_2 - GPO0 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO0_2_SYSTEM_SPEED_CODE_MASK (0x3U)
#define FLASH_NMPA_GPO0_2_SYSTEM_SPEED_CODE_SHIFT (0U)
/*! SYSTEM_SPEED_CODE - System speed code */
#define FLASH_NMPA_GPO0_2_SYSTEM_SPEED_CODE(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_2_SYSTEM_SPEED_CODE_SHIFT)) & FLASH_NMPA_GPO0_2_SYSTEM_SPEED_CODE_MASK)

#define FLASH_NMPA_GPO0_2_FLASH_CTRL_OPMODE_MASK (0xCU)
#define FLASH_NMPA_GPO0_2_FLASH_CTRL_OPMODE_SHIFT (2U)
/*! FLASH_CTRL_OPMODE - System speed code */
#define FLASH_NMPA_GPO0_2_FLASH_CTRL_OPMODE(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_2_FLASH_CTRL_OPMODE_SHIFT)) & FLASH_NMPA_GPO0_2_FLASH_CTRL_OPMODE_MASK)

#define FLASH_NMPA_GPO0_2_FIELD_MASK             (0xFFFFFFF0U)
#define FLASH_NMPA_GPO0_2_FIELD_SHIFT            (4U)
#define FLASH_NMPA_GPO0_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_2_FIELD_SHIFT)) & FLASH_NMPA_GPO0_2_FIELD_MASK)
/*! @} */

/*! @name GPO0_3 - GPO0 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO0_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO0_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO0_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_3_FIELD_SHIFT)) & FLASH_NMPA_GPO0_3_FIELD_MASK)
/*! @} */

/*! @name GPO0_ARRAY - GPO0 array description */
/*! @{ */

#define FLASH_NMPA_GPO0_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO0_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO0_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO0_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO0_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO0_ARRAY */
#define FLASH_NMPA_GPO0_ARRAY_COUNT              (4U)

/*! @name GPO1_0 - GPO1 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO1_0_FINAL_TEST_NOT_DONE_MASK (0xFU)
#define FLASH_NMPA_GPO1_0_FINAL_TEST_NOT_DONE_SHIFT (0U)
/*! FINAL_TEST_NOT_DONE - FINAL_TEST_NOT_DONE[7:4]: 1010 : Final Test Not Done. All Other values: Final Test Done. */
#define FLASH_NMPA_GPO1_0_FINAL_TEST_NOT_DONE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_FINAL_TEST_NOT_DONE_SHIFT)) & FLASH_NMPA_GPO1_0_FINAL_TEST_NOT_DONE_MASK)

#define FLASH_NMPA_GPO1_0_PARTCONFIG_MASK        (0x7F0U)
#define FLASH_NMPA_GPO1_0_PARTCONFIG_SHIFT       (4U)
/*! PARTCONFIG - Device type number. (E.g : MCXW23 stored as 04 decimal) */
#define FLASH_NMPA_GPO1_0_PARTCONFIG(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_PARTCONFIG_SHIFT)) & FLASH_NMPA_GPO1_0_PARTCONFIG_MASK)

#define FLASH_NMPA_GPO1_0_DEVICE_TYPE_SEC_MASK   (0x800U)
#define FLASH_NMPA_GPO1_0_DEVICE_TYPE_SEC_SHIFT  (11U)
/*! DEVICE_TYPE_SEC - Security device type: 0: NHS52xx (Non Secure Family) 1: NHS52Sxx (Secure Family) */
#define FLASH_NMPA_GPO1_0_DEVICE_TYPE_SEC(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_DEVICE_TYPE_SEC_SHIFT)) & FLASH_NMPA_GPO1_0_DEVICE_TYPE_SEC_MASK)

#define FLASH_NMPA_GPO1_0_SRAM_SIZE_MASK         (0xF000U)
#define FLASH_NMPA_GPO1_0_SRAM_SIZE_SHIFT        (12U)
/*! SRAM_SIZE - SRAM_SIZE[3:0] */
#define FLASH_NMPA_GPO1_0_SRAM_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_SRAM_SIZE_SHIFT)) & FLASH_NMPA_GPO1_0_SRAM_SIZE_MASK)

#define FLASH_NMPA_GPO1_0_CM33_SECURITY_EXTENSION_DISABLE_MASK (0xF0000U)
#define FLASH_NMPA_GPO1_0_CM33_SECURITY_EXTENSION_DISABLE_SHIFT (16U)
/*! CM33_SECURITY_EXTENSION_DISABLE - CM33_SECURITY_EXTENSION_DISABLE[7:4]: 1010 : CM33 Security
 *    Extension is disabled. All Other values: CM33 Security Extension is enabled.
 */
#define FLASH_NMPA_GPO1_0_CM33_SECURITY_EXTENSION_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_CM33_SECURITY_EXTENSION_DISABLE_SHIFT)) & FLASH_NMPA_GPO1_0_CM33_SECURITY_EXTENSION_DISABLE_MASK)

#define FLASH_NMPA_GPO1_0_FIELD_MASK             (0xF00000U)
#define FLASH_NMPA_GPO1_0_FIELD_SHIFT            (20U)
/*! FIELD - . */
#define FLASH_NMPA_GPO1_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_FIELD_SHIFT)) & FLASH_NMPA_GPO1_0_FIELD_MASK)

#define FLASH_NMPA_GPO1_0_ROM_REVISION_MINOR_MASK (0xF000000U)
#define FLASH_NMPA_GPO1_0_ROM_REVISION_MINOR_SHIFT (24U)
/*! ROM_REVISION_MINOR - ROM Revision-Minor [3:0] */
#define FLASH_NMPA_GPO1_0_ROM_REVISION_MINOR(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_ROM_REVISION_MINOR_SHIFT)) & FLASH_NMPA_GPO1_0_ROM_REVISION_MINOR_MASK)

#define FLASH_NMPA_GPO1_0_METAL_REVISION_ID_MASK (0xF0000000U)
#define FLASH_NMPA_GPO1_0_METAL_REVISION_ID_SHIFT (28U)
/*! METAL_REVISION_ID - METAL REVISION ID[3:0] */
#define FLASH_NMPA_GPO1_0_METAL_REVISION_ID(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_0_METAL_REVISION_ID_SHIFT)) & FLASH_NMPA_GPO1_0_METAL_REVISION_ID_MASK)
/*! @} */

/*! @name GPO1_1 - GPO1 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO1_1_ROM_PATCH_VERSION_MASK (0xFU)
#define FLASH_NMPA_GPO1_1_ROM_PATCH_VERSION_SHIFT (0U)
/*! ROM_PATCH_VERSION - ROM Patch Version [3:0] */
#define FLASH_NMPA_GPO1_1_ROM_PATCH_VERSION(x)   (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_1_ROM_PATCH_VERSION_SHIFT)) & FLASH_NMPA_GPO1_1_ROM_PATCH_VERSION_MASK)

#define FLASH_NMPA_GPO1_1_CUSTOMER_REVISION_ID_MASK (0xF0U)
#define FLASH_NMPA_GPO1_1_CUSTOMER_REVISION_ID_SHIFT (4U)
/*! CUSTOMER_REVISION_ID - CUSTOMER REVISION ID[3:0] */
#define FLASH_NMPA_GPO1_1_CUSTOMER_REVISION_ID(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_1_CUSTOMER_REVISION_ID_SHIFT)) & FLASH_NMPA_GPO1_1_CUSTOMER_REVISION_ID_MASK)

#define FLASH_NMPA_GPO1_1_FIELD_MASK             (0xFFFFFF00U)
#define FLASH_NMPA_GPO1_1_FIELD_SHIFT            (8U)
#define FLASH_NMPA_GPO1_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_1_FIELD_SHIFT)) & FLASH_NMPA_GPO1_1_FIELD_MASK)
/*! @} */

/*! @name GPO1_2 - GPO1 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO1_2_OVS_DONE_MASK          (0x1U)
#define FLASH_NMPA_GPO1_2_OVS_DONE_SHIFT         (0U)
/*! OVS_DONE - Over-voltage stress test done */
#define FLASH_NMPA_GPO1_2_OVS_DONE(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_2_OVS_DONE_SHIFT)) & FLASH_NMPA_GPO1_2_OVS_DONE_MASK)

#define FLASH_NMPA_GPO1_2_OVS_PASS_MASK          (0x2U)
#define FLASH_NMPA_GPO1_2_OVS_PASS_SHIFT         (1U)
/*! OVS_PASS - Over-voltage stress test done */
#define FLASH_NMPA_GPO1_2_OVS_PASS(x)            (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_2_OVS_PASS_SHIFT)) & FLASH_NMPA_GPO1_2_OVS_PASS_MASK)

#define FLASH_NMPA_GPO1_2_FIELD_MASK             (0xFFFFFFFCU)
#define FLASH_NMPA_GPO1_2_FIELD_SHIFT            (2U)
#define FLASH_NMPA_GPO1_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_2_FIELD_SHIFT)) & FLASH_NMPA_GPO1_2_FIELD_MASK)
/*! @} */

/*! @name GPO1_3 - GPO1 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO1_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO1_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO1_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_3_FIELD_SHIFT)) & FLASH_NMPA_GPO1_3_FIELD_MASK)
/*! @} */

/*! @name GPO1_ARRAY - GPO1 array description */
/*! @{ */

#define FLASH_NMPA_GPO1_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO1_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO1_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO1_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO1_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO1_ARRAY */
#define FLASH_NMPA_GPO1_ARRAY_COUNT              (4U)

/*! @name GPO2_0 - GPO2 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO2_0_FRO192M_TRIM_VALID_MASK (0x1U)
#define FLASH_NMPA_GPO2_0_FRO192M_TRIM_VALID_SHIFT (0U)
/*! FRO192M_TRIM_VALID - FRO192M_TRIM_VALID */
#define FLASH_NMPA_GPO2_0_FRO192M_TRIM_VALID(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FRO192M_TRIM_VALID_SHIFT)) & FLASH_NMPA_GPO2_0_FRO192M_TRIM_VALID_MASK)

#define FLASH_NMPA_GPO2_0_FRO192M_BIASTRIM_MASK  (0x7EU)
#define FLASH_NMPA_GPO2_0_FRO192M_BIASTRIM_SHIFT (1U)
/*! FRO192M_BIASTRIM - Coarse frequency trim loaded in PMC_FRO192M_BIAS register. */
#define FLASH_NMPA_GPO2_0_FRO192M_BIASTRIM(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FRO192M_BIASTRIM_SHIFT)) & FLASH_NMPA_GPO2_0_FRO192M_BIASTRIM_MASK)

#define FLASH_NMPA_GPO2_0_FIELD0_MASK            (0x80U)
#define FLASH_NMPA_GPO2_0_FIELD0_SHIFT           (7U)
#define FLASH_NMPA_GPO2_0_FIELD0(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FIELD0_SHIFT)) & FLASH_NMPA_GPO2_0_FIELD0_MASK)

#define FLASH_NMPA_GPO2_0_FRO192M_TEMPTRIM_MASK  (0x3F00U)
#define FLASH_NMPA_GPO2_0_FRO192M_TEMPTRIM_SHIFT (8U)
/*! FRO192M_TEMPTRIM - Temperature coefficient loaded in PMC_FRO192M_TC. */
#define FLASH_NMPA_GPO2_0_FRO192M_TEMPTRIM(x)    (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FRO192M_TEMPTRIM_SHIFT)) & FLASH_NMPA_GPO2_0_FRO192M_TEMPTRIM_MASK)

#define FLASH_NMPA_GPO2_0_FIELD1_MASK            (0xC000U)
#define FLASH_NMPA_GPO2_0_FIELD1_SHIFT           (14U)
#define FLASH_NMPA_GPO2_0_FIELD1(x)              (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FIELD1_SHIFT)) & FLASH_NMPA_GPO2_0_FIELD1_MASK)

#define FLASH_NMPA_GPO2_0_FRO192M_DACTRIM_MASK   (0xFF0000U)
#define FLASH_NMPA_GPO2_0_FRO192M_DACTRIM_SHIFT  (16U)
/*! FRO192M_DACTRIM - Fine frequency trim loaded in PMC_FRO192M_CUR_DAC. */
#define FLASH_NMPA_GPO2_0_FRO192M_DACTRIM(x)     (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FRO192M_DACTRIM_SHIFT)) & FLASH_NMPA_GPO2_0_FRO192M_DACTRIM_MASK)

#define FLASH_NMPA_GPO2_0_FLASH_SIZE_MASK        (0xF000000U)
#define FLASH_NMPA_GPO2_0_FLASH_SIZE_SHIFT       (24U)
/*! FLASH_SIZE - (For NHS5200) 0000 : 0 KB 0001 : 128 KB 0010 : 256 KB 0011 : 386 KB 0100 : 512 KB
 *    0101 : 640 KB 0110 : 768 KB 0111 : 896 KB 1000 : 1024 KB All others : RESERVED
 */
#define FLASH_NMPA_GPO2_0_FLASH_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_FLASH_SIZE_SHIFT)) & FLASH_NMPA_GPO2_0_FLASH_SIZE_MASK)

#define FLASH_NMPA_GPO2_0_CM33_SECURITY_EXTENSION_DISABLE_MASK (0xF0000000U)
#define FLASH_NMPA_GPO2_0_CM33_SECURITY_EXTENSION_DISABLE_SHIFT (28U)
/*! CM33_SECURITY_EXTENSION_DISABLE - CM33_SECURITY_EXTENSION_DISABLE[3:0]: 1010 : CPU0 Security
 *    Extension is disabled. All Other values: CPU0 Security Extension is enabled.
 */
#define FLASH_NMPA_GPO2_0_CM33_SECURITY_EXTENSION_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_0_CM33_SECURITY_EXTENSION_DISABLE_SHIFT)) & FLASH_NMPA_GPO2_0_CM33_SECURITY_EXTENSION_DISABLE_MASK)
/*! @} */

/*! @name GPO2_1 - GPO2 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO2_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO2_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO2_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_1_FIELD_SHIFT)) & FLASH_NMPA_GPO2_1_FIELD_MASK)
/*! @} */

/*! @name GPO2_2 - GPO2 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO2_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO2_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO2_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_2_FIELD_SHIFT)) & FLASH_NMPA_GPO2_2_FIELD_MASK)
/*! @} */

/*! @name GPO2_3 - GPO2 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO2_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO2_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO2_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_3_FIELD_SHIFT)) & FLASH_NMPA_GPO2_3_FIELD_MASK)
/*! @} */

/*! @name GPO2_ARRAY - GPO2 array description */
/*! @{ */

#define FLASH_NMPA_GPO2_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO2_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO2_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO2_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO2_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO2_ARRAY */
#define FLASH_NMPA_GPO2_ARRAY_COUNT              (4U)

/*! @name GPO3_0 - GPO3 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO3_0_BANDGAP_TC0_MASK       (0x1FU)
#define FLASH_NMPA_GPO3_0_BANDGAP_TC0_SHIFT      (0U)
#define FLASH_NMPA_GPO3_0_BANDGAP_TC0(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_BANDGAP_TC0_SHIFT)) & FLASH_NMPA_GPO3_0_BANDGAP_TC0_MASK)

#define FLASH_NMPA_GPO3_0_BANDGAP_BIAS_MASK      (0x3E0U)
#define FLASH_NMPA_GPO3_0_BANDGAP_BIAS_SHIFT     (5U)
#define FLASH_NMPA_GPO3_0_BANDGAP_BIAS(x)        (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_BANDGAP_BIAS_SHIFT)) & FLASH_NMPA_GPO3_0_BANDGAP_BIAS_MASK)

#define FLASH_NMPA_GPO3_0_BANDGAP_TC2_MASK       (0xC00U)
#define FLASH_NMPA_GPO3_0_BANDGAP_TC2_SHIFT      (10U)
#define FLASH_NMPA_GPO3_0_BANDGAP_TC2(x)         (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_BANDGAP_TC2_SHIFT)) & FLASH_NMPA_GPO3_0_BANDGAP_TC2_MASK)

#define FLASH_NMPA_GPO3_0_BANDGAP_LP_DC_MASK     (0xF000U)
#define FLASH_NMPA_GPO3_0_BANDGAP_LP_DC_SHIFT    (12U)
#define FLASH_NMPA_GPO3_0_BANDGAP_LP_DC(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_BANDGAP_LP_DC_SHIFT)) & FLASH_NMPA_GPO3_0_BANDGAP_LP_DC_MASK)

#define FLASH_NMPA_GPO3_0_FRO1M_FREQ_SEL_MASK    (0x7F0000U)
#define FLASH_NMPA_GPO3_0_FRO1M_FREQ_SEL_SHIFT   (16U)
#define FLASH_NMPA_GPO3_0_FRO1M_FREQ_SEL(x)      (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_FRO1M_FREQ_SEL_SHIFT)) & FLASH_NMPA_GPO3_0_FRO1M_FREQ_SEL_MASK)

#define FLASH_NMPA_GPO3_0_FIELD_MASK             (0x1800000U)
#define FLASH_NMPA_GPO3_0_FIELD_SHIFT            (23U)
#define FLASH_NMPA_GPO3_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_FIELD_SHIFT)) & FLASH_NMPA_GPO3_0_FIELD_MASK)

#define FLASH_NMPA_GPO3_0_MODELNUM_EXTENSION_MASK (0xE000000U)
#define FLASH_NMPA_GPO3_0_MODELNUM_EXTENSION_SHIFT (25U)
/*! MODELNUM_EXTENSION - ModelNumber extension[2:0] */
#define FLASH_NMPA_GPO3_0_MODELNUM_EXTENSION(x)  (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_MODELNUM_EXTENSION_SHIFT)) & FLASH_NMPA_GPO3_0_MODELNUM_EXTENSION_MASK)

#define FLASH_NMPA_GPO3_0_FINAL_TEST_NOT_DONE_MASK (0xF0000000U)
#define FLASH_NMPA_GPO3_0_FINAL_TEST_NOT_DONE_SHIFT (28U)
/*! FINAL_TEST_NOT_DONE - FINAL_TEST_NOT_DONE[3:0]: 1010 : Final Test Not Done. All Other values: Final Test Done. */
#define FLASH_NMPA_GPO3_0_FINAL_TEST_NOT_DONE(x) (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_0_FINAL_TEST_NOT_DONE_SHIFT)) & FLASH_NMPA_GPO3_0_FINAL_TEST_NOT_DONE_MASK)
/*! @} */

/*! @name GPO3_1 - GPO3 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO3_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO3_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO3_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_1_FIELD_SHIFT)) & FLASH_NMPA_GPO3_1_FIELD_MASK)
/*! @} */

/*! @name GPO3_2 - GPO3 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO3_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO3_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO3_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_2_FIELD_SHIFT)) & FLASH_NMPA_GPO3_2_FIELD_MASK)
/*! @} */

/*! @name GPO3_3 - GPO3 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO3_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO3_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO3_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_3_FIELD_SHIFT)) & FLASH_NMPA_GPO3_3_FIELD_MASK)
/*! @} */

/*! @name GPO3_ARRAY - GPO3 array description */
/*! @{ */

#define FLASH_NMPA_GPO3_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO3_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO3_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO3_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO3_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO3_ARRAY */
#define FLASH_NMPA_GPO3_ARRAY_COUNT              (4U)

/*! @name GPO4_0 - GPO4 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO4_0_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO4_0_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO4_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO4_0_FIELD_SHIFT)) & FLASH_NMPA_GPO4_0_FIELD_MASK)
/*! @} */

/*! @name GPO4_1 - GPO4 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO4_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO4_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO4_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO4_1_FIELD_SHIFT)) & FLASH_NMPA_GPO4_1_FIELD_MASK)
/*! @} */

/*! @name GPO4_2 - GPO4 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO4_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO4_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO4_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO4_2_FIELD_SHIFT)) & FLASH_NMPA_GPO4_2_FIELD_MASK)
/*! @} */

/*! @name GPO4_3 - GPO4 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO4_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO4_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO4_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO4_3_FIELD_SHIFT)) & FLASH_NMPA_GPO4_3_FIELD_MASK)
/*! @} */

/*! @name GPO4_ARRAY - GPO4 array description */
/*! @{ */

#define FLASH_NMPA_GPO4_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO4_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO4_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO4_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO4_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO4_ARRAY */
#define FLASH_NMPA_GPO4_ARRAY_COUNT              (4U)

/*! @name GPO5_0 - GPO5 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO5_0_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO5_0_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO5_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO5_0_FIELD_SHIFT)) & FLASH_NMPA_GPO5_0_FIELD_MASK)
/*! @} */

/*! @name GPO5_1 - GPO5 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO5_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO5_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO5_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO5_1_FIELD_SHIFT)) & FLASH_NMPA_GPO5_1_FIELD_MASK)
/*! @} */

/*! @name GPO5_2 - GPO5 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO5_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO5_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO5_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO5_2_FIELD_SHIFT)) & FLASH_NMPA_GPO5_2_FIELD_MASK)
/*! @} */

/*! @name GPO5_3 - GPO5 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO5_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO5_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO5_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO5_3_FIELD_SHIFT)) & FLASH_NMPA_GPO5_3_FIELD_MASK)
/*! @} */

/*! @name GPO5_ARRAY - GPO5 array description */
/*! @{ */

#define FLASH_NMPA_GPO5_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO5_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO5_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO5_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO5_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO5_ARRAY */
#define FLASH_NMPA_GPO5_ARRAY_COUNT              (4U)

/*! @name GPO6_0 - GPO6 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO6_0_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO6_0_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO6_0_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO6_0_FIELD_SHIFT)) & FLASH_NMPA_GPO6_0_FIELD_MASK)
/*! @} */

/*! @name GPO6_1 - GPO6 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO6_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO6_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO6_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO6_1_FIELD_SHIFT)) & FLASH_NMPA_GPO6_1_FIELD_MASK)
/*! @} */

/*! @name GPO6_2 - GPO6 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO6_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO6_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO6_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO6_2_FIELD_SHIFT)) & FLASH_NMPA_GPO6_2_FIELD_MASK)
/*! @} */

/*! @name GPO6_3 - GPO6 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO6_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO6_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO6_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO6_3_FIELD_SHIFT)) & FLASH_NMPA_GPO6_3_FIELD_MASK)
/*! @} */

/*! @name GPO6_ARRAY - GPO6 array description */
/*! @{ */

#define FLASH_NMPA_GPO6_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO6_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO6_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO6_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO6_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO6_ARRAY */
#define FLASH_NMPA_GPO6_ARRAY_COUNT              (4U)

/*! @name GPO7_0 - GPO7 register 0 description */
/*! @{ */

#define FLASH_NMPA_GPO7_0_SOCTRIM_VALID_MASK     (0xFFFFFFFFU)
#define FLASH_NMPA_GPO7_0_SOCTRIM_VALID_SHIFT    (0U)
/*! SOCTRIM_VALID - GPO bits valid */
#define FLASH_NMPA_GPO7_0_SOCTRIM_VALID(x)       (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO7_0_SOCTRIM_VALID_SHIFT)) & FLASH_NMPA_GPO7_0_SOCTRIM_VALID_MASK)
/*! @} */

/*! @name GPO7_1 - GPO7 register 1 description */
/*! @{ */

#define FLASH_NMPA_GPO7_1_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO7_1_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO7_1_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO7_1_FIELD_SHIFT)) & FLASH_NMPA_GPO7_1_FIELD_MASK)
/*! @} */

/*! @name GPO7_2 - GPO7 register 2 description */
/*! @{ */

#define FLASH_NMPA_GPO7_2_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO7_2_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO7_2_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO7_2_FIELD_SHIFT)) & FLASH_NMPA_GPO7_2_FIELD_MASK)
/*! @} */

/*! @name GPO7_3 - GPO7 register 3 description */
/*! @{ */

#define FLASH_NMPA_GPO7_3_FIELD_MASK             (0xFFFFFFFFU)
#define FLASH_NMPA_GPO7_3_FIELD_SHIFT            (0U)
#define FLASH_NMPA_GPO7_3_FIELD(x)               (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO7_3_FIELD_SHIFT)) & FLASH_NMPA_GPO7_3_FIELD_MASK)
/*! @} */

/*! @name GPO7_ARRAY - GPO7 array description */
/*! @{ */

#define FLASH_NMPA_GPO7_ARRAY_FIELD_MASK         (0xFFFFFFFFU)
#define FLASH_NMPA_GPO7_ARRAY_FIELD_SHIFT        (0U)
#define FLASH_NMPA_GPO7_ARRAY_FIELD(x)           (((uint32_t)(((uint32_t)(x)) << FLASH_NMPA_GPO7_ARRAY_FIELD_SHIFT)) & FLASH_NMPA_GPO7_ARRAY_FIELD_MASK)
/*! @} */

/* The count of FLASH_NMPA_GPO7_ARRAY */
#define FLASH_NMPA_GPO7_ARRAY_COUNT              (4U)


/*!
 * @}
 */ /* end of group FLASH_NMPA_Register_Masks */


/*!
 * @}
 */ /* end of group FLASH_NMPA_Peripheral_Access_Layer */


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


#endif  /* PERI_FLASH_NMPA_H_ */

