/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TRDC_MGR_MEGA
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRDC_MGR_MEGA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRDC_MGR_MEGA
 *
 * CMSIS Peripheral Access Layer for TRDC_MGR_MEGA
 */

#if !defined(PERI_TRDC_MGR_MEGA_H_)
#define PERI_TRDC_MGR_MEGA_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- TRDC_MGR_MEGA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_MGR_MEGA_Peripheral_Access_Layer TRDC_MGR_MEGA Peripheral Access Layer
 * @{
 */

/** TRDC_MGR_MEGA - Size of Registers Arrays */
#define TRDC_MGR_MEGA_DERRLOC_COUNT               16u

/** TRDC_MGR_MEGA - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRDC_CR;                           /**< TRDC Register, offset: 0x0 */
       uint8_t RESERVED_0[236];
  __I  uint32_t TRDC_HWCFG0;                       /**< TRDC Hardware Configuration Register 0, offset: 0xF0 */
  __I  uint32_t TRDC_HWCFG1;                       /**< TRDC Hardware Configuration Register 1, offset: 0xF4 */
       uint8_t RESERVED_1[8];
  __I  uint8_t DACFG0;                             /**< Domain Assignment Configuration Register, offset: 0x100 */
  __I  uint8_t DACFG1;                             /**< Domain Assignment Configuration Register, offset: 0x101 */
  __I  uint8_t DACFG2;                             /**< Domain Assignment Configuration Register, offset: 0x102 */
  __I  uint8_t DACFG3;                             /**< Domain Assignment Configuration Register, offset: 0x103 */
  __I  uint8_t DACFG4;                             /**< Domain Assignment Configuration Register, offset: 0x104 */
  __I  uint8_t DACFG5;                             /**< Domain Assignment Configuration Register, offset: 0x105 */
  __I  uint8_t DACFG6;                             /**< Domain Assignment Configuration Register, offset: 0x106 */
  __I  uint8_t DACFG7;                             /**< Domain Assignment Configuration Register, offset: 0x107 */
  __I  uint8_t DACFG8;                             /**< Domain Assignment Configuration Register, offset: 0x108 */
  __I  uint8_t DACFG9;                             /**< Domain Assignment Configuration Register, offset: 0x109 */
  __I  uint8_t DACFG10;                            /**< Domain Assignment Configuration Register, offset: 0x10A */
  __I  uint8_t DACFG11;                            /**< Domain Assignment Configuration Register, offset: 0x10B */
  __I  uint8_t DACFG12;                            /**< Domain Assignment Configuration Register, offset: 0x10C */
  __I  uint8_t DACFG13;                            /**< Domain Assignment Configuration Register, offset: 0x10D */
  __I  uint8_t DACFG14;                            /**< Domain Assignment Configuration Register, offset: 0x10E */
  __I  uint8_t DACFG15;                            /**< Domain Assignment Configuration Register, offset: 0x10F */
  __I  uint8_t DACFG16;                            /**< Domain Assignment Configuration Register, offset: 0x110 */
  __I  uint8_t DACFG17;                            /**< Domain Assignment Configuration Register, offset: 0x111 */
  __I  uint8_t DACFG18;                            /**< Domain Assignment Configuration Register, offset: 0x112 */
  __I  uint8_t DACFG19;                            /**< Domain Assignment Configuration Register, offset: 0x113 */
  __I  uint8_t DACFG20;                            /**< Domain Assignment Configuration Register, offset: 0x114 */
  __I  uint8_t DACFG21;                            /**< Domain Assignment Configuration Register, offset: 0x115 */
  __I  uint8_t DACFG22;                            /**< Domain Assignment Configuration Register, offset: 0x116 */
  __I  uint8_t DACFG23;                            /**< Domain Assignment Configuration Register, offset: 0x117 */
  __I  uint8_t DACFG24;                            /**< Domain Assignment Configuration Register, offset: 0x118 */
  __I  uint8_t DACFG25;                            /**< Domain Assignment Configuration Register, offset: 0x119 */
  __I  uint8_t DACFG26;                            /**< Domain Assignment Configuration Register, offset: 0x11A */
  __I  uint8_t DACFG27;                            /**< Domain Assignment Configuration Register, offset: 0x11B */
  __I  uint8_t DACFG28;                            /**< Domain Assignment Configuration Register, offset: 0x11C */
  __I  uint8_t DACFG29;                            /**< Domain Assignment Configuration Register, offset: 0x11D */
  __I  uint8_t DACFG30;                            /**< Domain Assignment Configuration Register, offset: 0x11E */
  __I  uint8_t DACFG31;                            /**< Domain Assignment Configuration Register, offset: 0x11F */
  __I  uint8_t DACFG32;                            /**< Domain Assignment Configuration Register, offset: 0x120 */
  __I  uint8_t DACFG33;                            /**< Domain Assignment Configuration Register, offset: 0x121 */
  __I  uint8_t DACFG34;                            /**< Domain Assignment Configuration Register, offset: 0x122 */
  __I  uint8_t DACFG35;                            /**< Domain Assignment Configuration Register, offset: 0x123 */
  __I  uint8_t DACFG36;                            /**< Domain Assignment Configuration Register, offset: 0x124 */
  __I  uint8_t DACFG37;                            /**< Domain Assignment Configuration Register, offset: 0x125 */
  __I  uint8_t DACFG38;                            /**< Domain Assignment Configuration Register, offset: 0x126 */
  __I  uint8_t DACFG39;                            /**< Domain Assignment Configuration Register, offset: 0x127 */
  __I  uint8_t DACFG40;                            /**< Domain Assignment Configuration Register, offset: 0x128 */
  __I  uint8_t DACFG41;                            /**< Domain Assignment Configuration Register, offset: 0x129 */
  __I  uint8_t DACFG42;                            /**< Domain Assignment Configuration Register, offset: 0x12A */
  __I  uint8_t DACFG43;                            /**< Domain Assignment Configuration Register, offset: 0x12B */
  __I  uint8_t DACFG44;                            /**< Domain Assignment Configuration Register, offset: 0x12C */
  __I  uint8_t DACFG45;                            /**< Domain Assignment Configuration Register, offset: 0x12D */
  __I  uint8_t DACFG46;                            /**< Domain Assignment Configuration Register, offset: 0x12E */
  __I  uint8_t DACFG47;                            /**< Domain Assignment Configuration Register, offset: 0x12F */
  __I  uint8_t DACFG48;                            /**< Domain Assignment Configuration Register, offset: 0x130 */
  __I  uint8_t DACFG49;                            /**< Domain Assignment Configuration Register, offset: 0x131 */
       uint8_t RESERVED_2[142];
  __IO uint32_t TRDC_IDAU_CR;                      /**< TRDC IDAU Control Register, offset: 0x1C0 */
       uint8_t RESERVED_3[28];
  __IO uint32_t TRDC_FLW_CTL;                      /**< TRDC FLW Control, offset: 0x1E0 */
  __I  uint32_t TRDC_FLW_PBASE;                    /**< TRDC FLW Physical Base, offset: 0x1E4 */
  __IO uint32_t TRDC_FLW_ABASE;                    /**< TRDC FLW Array Base, offset: 0x1E8 */
  __IO uint32_t TRDC_FLW_BCNT;                     /**< TRDC FLW Block Count, offset: 0x1EC */
       uint8_t RESERVED_4[12];
  __IO uint32_t TRDC_FDID;                         /**< TRDC Fault Domain ID, offset: 0x1FC */
  __I  uint32_t TRDC_DERRLOC[TRDC_MGR_MEGA_DERRLOC_COUNT]; /**< TRDC Domain Error Location Register, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[1472];
  __IO uint32_t MDA_W0_0_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x800 */
       uint8_t RESERVED_6[28];
  __IO uint32_t MDA_W0_1_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x820 */
       uint8_t RESERVED_7[28];
  __IO uint32_t MDA_W0_2_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x840 */
       uint8_t RESERVED_8[28];
  __IO uint32_t MDA_W0_3_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x860 */
       uint8_t RESERVED_9[28];
  __IO uint32_t MDA_W0_4_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x880 */
       uint8_t RESERVED_10[28];
  __IO uint32_t MDA_W0_5_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x8A0 */
       uint8_t RESERVED_11[28];
  __IO uint32_t MDA_W0_6_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x8C0 */
       uint8_t RESERVED_12[28];
  __IO uint32_t MDA_W0_7_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x8E0 */
       uint8_t RESERVED_13[28];
  __IO uint32_t MDA_W0_8_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x900 */
       uint8_t RESERVED_14[28];
  __IO uint32_t MDA_W0_9_DFMT1;                    /**< DAC Initiator Domain Assignment Register, offset: 0x920 */
       uint8_t RESERVED_15[28];
  __IO uint32_t MDA_W0_10_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x940 */
       uint8_t RESERVED_16[28];
  __IO uint32_t MDA_W0_11_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x960 */
       uint8_t RESERVED_17[28];
  __IO uint32_t MDA_W0_12_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x980 */
       uint8_t RESERVED_18[28];
  __IO uint32_t MDA_W0_13_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x9A0 */
       uint8_t RESERVED_19[28];
  __IO uint32_t MDA_W0_14_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x9C0 */
       uint8_t RESERVED_20[28];
  __IO uint32_t MDA_W0_15_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0x9E0 */
       uint8_t RESERVED_21[28];
  __IO uint32_t MDA_W0_16_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xA00 */
       uint8_t RESERVED_22[28];
  __IO uint32_t MDA_W0_17_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xA20 */
       uint8_t RESERVED_23[28];
  __IO uint32_t MDA_W0_18_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xA40 */
       uint8_t RESERVED_24[28];
  __IO uint32_t MDA_W0_19_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xA60 */
       uint8_t RESERVED_25[28];
  __IO uint32_t MDA_W0_20_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xA80 */
       uint8_t RESERVED_26[28];
  __IO uint32_t MDA_W0_21_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xAA0 */
       uint8_t RESERVED_27[28];
  __IO uint32_t MDA_W0_22_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xAC0 */
       uint8_t RESERVED_28[28];
  __IO uint32_t MDA_W0_23_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xAE0 */
       uint8_t RESERVED_29[28];
  __IO uint32_t MDA_W0_24_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xB00 */
       uint8_t RESERVED_30[28];
  __IO uint32_t MDA_W0_25_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xB20 */
       uint8_t RESERVED_31[28];
  __IO uint32_t MDA_W0_26_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xB40 */
       uint8_t RESERVED_32[28];
  __IO uint32_t MDA_W0_27_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xB60 */
       uint8_t RESERVED_33[28];
  __IO uint32_t MDA_W0_28_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xB80 */
       uint8_t RESERVED_34[28];
  __IO uint32_t MDA_W0_29_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xBA0 */
       uint8_t RESERVED_35[28];
  __IO uint32_t MDA_W0_30_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xBC0 */
       uint8_t RESERVED_36[28];
  __IO uint32_t MDA_W0_31_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xBE0 */
       uint8_t RESERVED_37[28];
  __IO uint32_t MDA_W0_32_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xC00 */
       uint8_t RESERVED_38[28];
  __IO uint32_t MDA_W0_33_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xC20 */
       uint8_t RESERVED_39[28];
  __IO uint32_t MDA_W0_34_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xC40 */
       uint8_t RESERVED_40[28];
  __IO uint32_t MDA_W0_35_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xC60 */
       uint8_t RESERVED_41[28];
  __IO uint32_t MDA_W0_36_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xC80 */
       uint8_t RESERVED_42[28];
  __IO uint32_t MDA_W0_37_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xCA0 */
       uint8_t RESERVED_43[28];
  __IO uint32_t MDA_W0_38_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xCC0 */
       uint8_t RESERVED_44[28];
  __IO uint32_t MDA_W0_39_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xCE0 */
       uint8_t RESERVED_45[28];
  __IO uint32_t MDA_W0_40_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xD00 */
       uint8_t RESERVED_46[28];
  __IO uint32_t MDA_W0_41_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xD20 */
       uint8_t RESERVED_47[28];
  __IO uint32_t MDA_W0_42_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xD40 */
       uint8_t RESERVED_48[28];
  __IO uint32_t MDA_W0_43_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xD60 */
       uint8_t RESERVED_49[28];
  __IO uint32_t MDA_W0_44_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xD80 */
       uint8_t RESERVED_50[28];
  __IO uint32_t MDA_W0_45_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xDA0 */
       uint8_t RESERVED_51[28];
  __IO uint32_t MDA_W0_46_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xDC0 */
       uint8_t RESERVED_52[28];
  __IO uint32_t MDA_W0_47_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xDE0 */
       uint8_t RESERVED_53[28];
  __IO uint32_t MDA_W0_48_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xE00 */
       uint8_t RESERVED_54[28];
  __IO uint32_t MDA_W0_49_DFMT1;                   /**< DAC Initiator Domain Assignment Register, offset: 0xE20 */
} TRDC_MGR_MEGA_Type;

/* ----------------------------------------------------------------------------
   -- TRDC_MGR_MEGA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRDC_MGR_MEGA_Register_Masks TRDC_MGR_MEGA Register Masks
 * @{
 */

/*! @name TRDC_CR - TRDC Register */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_CR_GVLDM_MASK         (0x1U)
#define TRDC_MGR_MEGA_TRDC_CR_GVLDM_SHIFT        (0U)
/*! GVLDM - Global Valid for Domain Assignment Controllers
 *  0b0..TRDC DACs are disabled.
 *  0b1..TRDC DACs are enabled.
 */
#define TRDC_MGR_MEGA_TRDC_CR_GVLDM(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_CR_GVLDM_SHIFT)) & TRDC_MGR_MEGA_TRDC_CR_GVLDM_MASK)

#define TRDC_MGR_MEGA_TRDC_CR_HRL_MASK           (0x1EU)
#define TRDC_MGR_MEGA_TRDC_CR_HRL_SHIFT          (1U)
/*! HRL - Hardware Revision Level */
#define TRDC_MGR_MEGA_TRDC_CR_HRL(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_CR_HRL_SHIFT)) & TRDC_MGR_MEGA_TRDC_CR_HRL_MASK)

#define TRDC_MGR_MEGA_TRDC_CR_GVLDB_MASK         (0x4000U)
#define TRDC_MGR_MEGA_TRDC_CR_GVLDB_SHIFT        (14U)
/*! GVLDB - Global Valid for Memory Block Checkers
 *  0b0..TRDC MBCs are disabled.
 *  0b1..TRDC MBCs are enabled.
 */
#define TRDC_MGR_MEGA_TRDC_CR_GVLDB(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_CR_GVLDB_SHIFT)) & TRDC_MGR_MEGA_TRDC_CR_GVLDB_MASK)

#define TRDC_MGR_MEGA_TRDC_CR_GVLDR_MASK         (0x8000U)
#define TRDC_MGR_MEGA_TRDC_CR_GVLDR_SHIFT        (15U)
/*! GVLDR - Global Valid for Memory Region Checkers
 *  0b0..TRDC MRCs are disabled.
 *  0b1..TRDC MRCs are enabled.
 */
#define TRDC_MGR_MEGA_TRDC_CR_GVLDR(x)           (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_CR_GVLDR_SHIFT)) & TRDC_MGR_MEGA_TRDC_CR_GVLDR_MASK)

#define TRDC_MGR_MEGA_TRDC_CR_LK1_MASK           (0x40000000U)
#define TRDC_MGR_MEGA_TRDC_CR_LK1_SHIFT          (30U)
/*! LK1 - Lock Status
 *  0b0..The CR can be written by any secure privileged write.
 *  0b1..The CR is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_TRDC_CR_LK1(x)             (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_CR_LK1_SHIFT)) & TRDC_MGR_MEGA_TRDC_CR_LK1_MASK)
/*! @} */

/*! @name TRDC_HWCFG0 - TRDC Hardware Configuration Register 0 */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_HWCFG0_NDID_MASK      (0x1FU)
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NDID_SHIFT     (0U)
/*! NDID - Number of domains */
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NDID(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG0_NDID_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG0_NDID_MASK)

#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMSTR_MASK     (0xFF00U)
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMSTR_SHIFT    (8U)
/*! NMSTR - Number of bus initiators */
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMSTR(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG0_NMSTR_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG0_NMSTR_MASK)

#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMBC_MASK      (0xF0000U)
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMBC_SHIFT     (16U)
/*! NMBC - Number of MBCs */
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMBC(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG0_NMBC_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG0_NMBC_MASK)

#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMRC_MASK      (0x1F000000U)
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMRC_SHIFT     (24U)
/*! NMRC - Number of MRCs */
#define TRDC_MGR_MEGA_TRDC_HWCFG0_NMRC(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG0_NMRC_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG0_NMRC_MASK)

#define TRDC_MGR_MEGA_TRDC_HWCFG0_MID_MASK       (0xE0000000U)
#define TRDC_MGR_MEGA_TRDC_HWCFG0_MID_SHIFT      (29U)
/*! MID - Module ID */
#define TRDC_MGR_MEGA_TRDC_HWCFG0_MID(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG0_MID_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name TRDC_HWCFG1 - TRDC Hardware Configuration Register 1 */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_HWCFG1_DID_MASK       (0xFU)
#define TRDC_MGR_MEGA_TRDC_HWCFG1_DID_SHIFT      (0U)
/*! DID - Domain identifier number */
#define TRDC_MGR_MEGA_TRDC_HWCFG1_DID(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_HWCFG1_DID_SHIFT)) & TRDC_MGR_MEGA_TRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name DACFG0 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG0_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG0_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG0_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG0_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG0_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG0_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG0_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG0_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG0_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG0_NCM_MASK)
/*! @} */

/*! @name DACFG1 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG1_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG1_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG1_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG1_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG1_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG1_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG1_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG1_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG1_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG1_NCM_MASK)
/*! @} */

/*! @name DACFG2 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG2_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG2_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG2_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG2_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG2_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG2_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG2_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG2_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG2_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG2_NCM_MASK)
/*! @} */

/*! @name DACFG3 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG3_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG3_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG3_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG3_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG3_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG3_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG3_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG3_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG3_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG3_NCM_MASK)
/*! @} */

/*! @name DACFG4 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG4_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG4_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG4_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG4_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG4_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG4_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG4_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG4_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG4_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG4_NCM_MASK)
/*! @} */

/*! @name DACFG5 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG5_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG5_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG5_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG5_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG5_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG5_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG5_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG5_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG5_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG5_NCM_MASK)
/*! @} */

/*! @name DACFG6 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG6_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG6_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG6_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG6_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG6_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG6_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG6_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG6_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG6_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG6_NCM_MASK)
/*! @} */

/*! @name DACFG7 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG7_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG7_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG7_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG7_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG7_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG7_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG7_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG7_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG7_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG7_NCM_MASK)
/*! @} */

/*! @name DACFG8 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG8_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG8_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG8_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG8_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG8_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG8_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG8_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG8_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG8_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG8_NCM_MASK)
/*! @} */

/*! @name DACFG9 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG9_NMDAR_MASK          (0xFU)
#define TRDC_MGR_MEGA_DACFG9_NMDAR_SHIFT         (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG9_NMDAR(x)            (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG9_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG9_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG9_NCM_MASK            (0x80U)
#define TRDC_MGR_MEGA_DACFG9_NCM_SHIFT           (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG9_NCM(x)              (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG9_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG9_NCM_MASK)
/*! @} */

/*! @name DACFG10 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG10_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG10_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG10_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG10_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG10_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG10_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG10_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG10_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG10_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG10_NCM_MASK)
/*! @} */

/*! @name DACFG11 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG11_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG11_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG11_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG11_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG11_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG11_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG11_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG11_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG11_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG11_NCM_MASK)
/*! @} */

/*! @name DACFG12 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG12_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG12_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG12_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG12_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG12_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG12_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG12_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG12_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG12_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG12_NCM_MASK)
/*! @} */

/*! @name DACFG13 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG13_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG13_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG13_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG13_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG13_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG13_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG13_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG13_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG13_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG13_NCM_MASK)
/*! @} */

/*! @name DACFG14 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG14_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG14_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG14_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG14_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG14_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG14_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG14_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG14_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG14_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG14_NCM_MASK)
/*! @} */

/*! @name DACFG15 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG15_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG15_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG15_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG15_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG15_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG15_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG15_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG15_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG15_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG15_NCM_MASK)
/*! @} */

/*! @name DACFG16 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG16_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG16_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG16_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG16_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG16_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG16_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG16_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG16_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG16_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG16_NCM_MASK)
/*! @} */

/*! @name DACFG17 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG17_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG17_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG17_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG17_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG17_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG17_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG17_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG17_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG17_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG17_NCM_MASK)
/*! @} */

/*! @name DACFG18 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG18_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG18_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG18_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG18_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG18_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG18_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG18_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG18_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG18_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG18_NCM_MASK)
/*! @} */

/*! @name DACFG19 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG19_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG19_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG19_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG19_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG19_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG19_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG19_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG19_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG19_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG19_NCM_MASK)
/*! @} */

/*! @name DACFG20 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG20_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG20_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG20_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG20_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG20_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG20_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG20_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG20_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG20_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG20_NCM_MASK)
/*! @} */

/*! @name DACFG21 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG21_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG21_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG21_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG21_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG21_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG21_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG21_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG21_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG21_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG21_NCM_MASK)
/*! @} */

/*! @name DACFG22 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG22_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG22_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG22_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG22_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG22_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG22_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG22_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG22_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG22_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG22_NCM_MASK)
/*! @} */

/*! @name DACFG23 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG23_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG23_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG23_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG23_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG23_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG23_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG23_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG23_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG23_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG23_NCM_MASK)
/*! @} */

/*! @name DACFG24 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG24_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG24_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG24_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG24_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG24_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG24_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG24_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG24_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG24_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG24_NCM_MASK)
/*! @} */

/*! @name DACFG25 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG25_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG25_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG25_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG25_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG25_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG25_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG25_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG25_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG25_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG25_NCM_MASK)
/*! @} */

/*! @name DACFG26 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG26_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG26_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG26_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG26_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG26_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG26_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG26_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG26_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG26_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG26_NCM_MASK)
/*! @} */

/*! @name DACFG27 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG27_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG27_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG27_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG27_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG27_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG27_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG27_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG27_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG27_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG27_NCM_MASK)
/*! @} */

/*! @name DACFG28 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG28_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG28_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG28_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG28_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG28_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG28_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG28_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG28_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG28_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG28_NCM_MASK)
/*! @} */

/*! @name DACFG29 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG29_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG29_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG29_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG29_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG29_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG29_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG29_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG29_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG29_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG29_NCM_MASK)
/*! @} */

/*! @name DACFG30 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG30_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG30_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG30_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG30_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG30_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG30_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG30_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG30_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG30_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG30_NCM_MASK)
/*! @} */

/*! @name DACFG31 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG31_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG31_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG31_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG31_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG31_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG31_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG31_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG31_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG31_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG31_NCM_MASK)
/*! @} */

/*! @name DACFG32 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG32_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG32_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG32_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG32_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG32_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG32_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG32_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG32_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG32_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG32_NCM_MASK)
/*! @} */

/*! @name DACFG33 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG33_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG33_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG33_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG33_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG33_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG33_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG33_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG33_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG33_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG33_NCM_MASK)
/*! @} */

/*! @name DACFG34 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG34_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG34_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG34_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG34_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG34_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG34_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG34_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG34_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG34_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG34_NCM_MASK)
/*! @} */

/*! @name DACFG35 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG35_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG35_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG35_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG35_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG35_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG35_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG35_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG35_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG35_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG35_NCM_MASK)
/*! @} */

/*! @name DACFG36 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG36_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG36_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG36_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG36_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG36_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG36_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG36_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG36_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG36_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG36_NCM_MASK)
/*! @} */

/*! @name DACFG37 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG37_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG37_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG37_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG37_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG37_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG37_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG37_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG37_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG37_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG37_NCM_MASK)
/*! @} */

/*! @name DACFG38 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG38_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG38_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG38_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG38_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG38_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG38_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG38_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG38_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG38_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG38_NCM_MASK)
/*! @} */

/*! @name DACFG39 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG39_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG39_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG39_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG39_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG39_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG39_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG39_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG39_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG39_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG39_NCM_MASK)
/*! @} */

/*! @name DACFG40 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG40_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG40_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG40_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG40_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG40_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG40_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG40_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG40_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG40_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG40_NCM_MASK)
/*! @} */

/*! @name DACFG41 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG41_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG41_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG41_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG41_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG41_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG41_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG41_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG41_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG41_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG41_NCM_MASK)
/*! @} */

/*! @name DACFG42 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG42_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG42_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG42_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG42_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG42_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG42_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG42_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG42_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG42_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG42_NCM_MASK)
/*! @} */

/*! @name DACFG43 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG43_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG43_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG43_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG43_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG43_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG43_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG43_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG43_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG43_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG43_NCM_MASK)
/*! @} */

/*! @name DACFG44 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG44_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG44_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG44_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG44_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG44_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG44_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG44_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG44_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG44_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG44_NCM_MASK)
/*! @} */

/*! @name DACFG45 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG45_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG45_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG45_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG45_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG45_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG45_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG45_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG45_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG45_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG45_NCM_MASK)
/*! @} */

/*! @name DACFG46 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG46_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG46_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG46_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG46_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG46_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG46_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG46_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG46_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG46_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG46_NCM_MASK)
/*! @} */

/*! @name DACFG47 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG47_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG47_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG47_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG47_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG47_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG47_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG47_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG47_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG47_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG47_NCM_MASK)
/*! @} */

/*! @name DACFG48 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG48_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG48_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG48_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG48_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG48_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG48_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG48_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG48_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG48_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG48_NCM_MASK)
/*! @} */

/*! @name DACFG49 - Domain Assignment Configuration Register */
/*! @{ */

#define TRDC_MGR_MEGA_DACFG49_NMDAR_MASK         (0xFU)
#define TRDC_MGR_MEGA_DACFG49_NMDAR_SHIFT        (0U)
/*! NMDAR - Number of initiator domain assignment registers for bus initiator m */
#define TRDC_MGR_MEGA_DACFG49_NMDAR(x)           (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG49_NMDAR_SHIFT)) & TRDC_MGR_MEGA_DACFG49_NMDAR_MASK)

#define TRDC_MGR_MEGA_DACFG49_NCM_MASK           (0x80U)
#define TRDC_MGR_MEGA_DACFG49_NCM_SHIFT          (7U)
/*! NCM - Non-CPU Initiator
 *  0b0..Bus initiator is a processor.
 *  0b1..Bus initiator is a non-processor.
 */
#define TRDC_MGR_MEGA_DACFG49_NCM(x)             (((uint8_t)(((uint8_t)(x)) << TRDC_MGR_MEGA_DACFG49_NCM_SHIFT)) & TRDC_MGR_MEGA_DACFG49_NCM_MASK)
/*! @} */

/*! @name TRDC_IDAU_CR - TRDC IDAU Control Register */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_VLD_MASK      (0x1U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_VLD_SHIFT     (0U)
/*! VLD - Valid */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_VLD(x)        (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_VLD_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_VLD_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_CFGSECEXT_MASK (0x8U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_CFGSECEXT_SHIFT (3U)
/*! CFGSECEXT - Configure Security Extension
 *  0b0..Armv8M Security Extension is disabled
 *  0b1..Armv8-M Security Extension is enabled
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_CFGSECEXT(x)  (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_CFGSECEXT_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_CFGSECEXT_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUSDIS_MASK  (0x10U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUSDIS_SHIFT (4U)
/*! MPUSDIS - Secure Memory Protection Unit Disabled
 *  0b0..Secure MPU is enabled
 *  0b1..Secure MPU is disabled
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUSDIS(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUSDIS_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUSDIS_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUNSDIS_MASK (0x20U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUNSDIS_SHIFT (5U)
/*! MPUNSDIS - NonSecure Memory Protection Unit Disabled
 *  0b0..Nonsecure MPU is enabled
 *  0b1..Nonsecure MPU is disabled
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUNSDIS(x)   (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUNSDIS_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_MPUNSDIS_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_SAUDIS_MASK   (0x40U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_SAUDIS_SHIFT  (6U)
/*! SAUDIS - Security Attribution Unit Disable
 *  0b0..SAU is enabled
 *  0b1..SAU is disabled
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_SAUDIS(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_SAUDIS_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_SAUDIS_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSVTAIRCR_MASK (0x100U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT (8U)
/*! LKSVTAIRCR - Lock Secure VTOR, Application interrupt and Reset Control Registers
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the VTOR_S, AIRCR[PRIS], and AIRCR[BFHFNMINS] registers
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSVTAIRCR(x) (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSVTAIRCR_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSVTAIRCR_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSVTOR_MASK (0x200U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSVTOR_SHIFT (9U)
/*! LKNSVTOR - Lock Nonsecure Vector Table Offset Register
 *  0b0..Unlock this register
 *  0b1..Disable writes to the VTOR_NS register
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSVTOR(x)   (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSVTOR_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSVTOR_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSMPU_MASK   (0x400U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSMPU_SHIFT  (10U)
/*! LKSMPU - Lock Secure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL, MPU_RNR, MPU_RBAR, MPU_RLAR, MPU_RBAR_An and MPU_RLAR_An from software or
 *       from a debug agent connected to the processor in Secure state
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSMPU(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSMPU_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSMPU_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSMPU_MASK  (0x800U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSMPU_SHIFT (11U)
/*! LKNSMPU - Lock Nonsecure MPU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the MPU_CTRL_NS, MPU_RNR_NS, MPU_RBAR_NS, MPU_RLAR_NS, MPU_RBAR_A_NSn and
 *       MPU_RLAR_A_NSn from software or from a debug agent connected to the processor
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSMPU(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSMPU_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_LKNSMPU_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSAU_MASK    (0x1000U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSAU_SHIFT   (12U)
/*! LKSAU - Lock SAU
 *  0b0..Unlock these registers
 *  0b1..Disable writes to the SAU_CTRL, SAU_RNR, SAU_RBAR and SAU_RLAR registers from software or from a debug agent connected to the processor
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSAU(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSAU_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_LKSAU_MASK)

#define TRDC_MGR_MEGA_TRDC_IDAU_CR_PCURRNS_MASK  (0x80000000U)
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_PCURRNS_SHIFT (31U)
/*! PCURRNS - Processor current security
 *  0b0..Processor is in Secure state
 *  0b1..Processor is in Nonsecure state
 */
#define TRDC_MGR_MEGA_TRDC_IDAU_CR_PCURRNS(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_IDAU_CR_PCURRNS_SHIFT)) & TRDC_MGR_MEGA_TRDC_IDAU_CR_PCURRNS_MASK)
/*! @} */

/*! @name TRDC_FLW_CTL - TRDC FLW Control */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_FLW_CTL_LK_MASK       (0x40000000U)
#define TRDC_MGR_MEGA_TRDC_FLW_CTL_LK_SHIFT      (30U)
/*! LK - Lock bit
 *  0b0..FLW registers may be modified.
 *  0b1..FLW registers are locked until the next reset.
 */
#define TRDC_MGR_MEGA_TRDC_FLW_CTL_LK(x)         (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_CTL_LK_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_CTL_LK_MASK)

#define TRDC_MGR_MEGA_TRDC_FLW_CTL_V_MASK        (0x80000000U)
#define TRDC_MGR_MEGA_TRDC_FLW_CTL_V_SHIFT       (31U)
/*! V - Valid bit
 *  0b0..FLW function is disabled.
 *  0b1..FLW function is enabled.
 */
#define TRDC_MGR_MEGA_TRDC_FLW_CTL_V(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_CTL_V_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_CTL_V_MASK)
/*! @} */

/*! @name TRDC_FLW_PBASE - TRDC FLW Physical Base */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_FLW_PBASE_PBASE_MASK  (0xFFFFFFFFU)
#define TRDC_MGR_MEGA_TRDC_FLW_PBASE_PBASE_SHIFT (0U)
/*! PBASE - Physical base address */
#define TRDC_MGR_MEGA_TRDC_FLW_PBASE_PBASE(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_PBASE_PBASE_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_PBASE_PBASE_MASK)
/*! @} */

/*! @name TRDC_FLW_ABASE - TRDC FLW Array Base */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_L_MASK (0x3F8000U)
#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_L_SHIFT (15U)
/*! ABASE_L - Array base address low */
#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_L(x)  (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_L_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_L_MASK)

#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_H_MASK (0xFFC00000U)
#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_H_SHIFT (22U)
/*! ABASE_H - Array base address high */
#define TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_H(x)  (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_H_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_ABASE_ABASE_H_MASK)
/*! @} */

/*! @name TRDC_FLW_BCNT - TRDC FLW Block Count */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_FLW_BCNT_BCNT_MASK    (0x7FFFU)
#define TRDC_MGR_MEGA_TRDC_FLW_BCNT_BCNT_SHIFT   (0U)
/*! BCNT - Block Count */
#define TRDC_MGR_MEGA_TRDC_FLW_BCNT_BCNT(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FLW_BCNT_BCNT_SHIFT)) & TRDC_MGR_MEGA_TRDC_FLW_BCNT_BCNT_MASK)
/*! @} */

/*! @name TRDC_FDID - TRDC Fault Domain ID */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_FDID_FDID_MASK        (0xFU)
#define TRDC_MGR_MEGA_TRDC_FDID_FDID_SHIFT       (0U)
/*! FDID - Domain ID of Faulted Access */
#define TRDC_MGR_MEGA_TRDC_FDID_FDID(x)          (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_FDID_FDID_SHIFT)) & TRDC_MGR_MEGA_TRDC_FDID_FDID_MASK)
/*! @} */

/*! @name TRDC_DERRLOC - TRDC Domain Error Location Register */
/*! @{ */

#define TRDC_MGR_MEGA_TRDC_DERRLOC_MBCINST_MASK  (0xFFU)
#define TRDC_MGR_MEGA_TRDC_DERRLOC_MBCINST_SHIFT (0U)
/*! MBCINST - MBC instance */
#define TRDC_MGR_MEGA_TRDC_DERRLOC_MBCINST(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_DERRLOC_MBCINST_SHIFT)) & TRDC_MGR_MEGA_TRDC_DERRLOC_MBCINST_MASK)

#define TRDC_MGR_MEGA_TRDC_DERRLOC_MRCINST_MASK  (0xFFFF0000U)
#define TRDC_MGR_MEGA_TRDC_DERRLOC_MRCINST_SHIFT (16U)
/*! MRCINST - MRC instance */
#define TRDC_MGR_MEGA_TRDC_DERRLOC_MRCINST(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_TRDC_DERRLOC_MRCINST_SHIFT)) & TRDC_MGR_MEGA_TRDC_DERRLOC_MRCINST_MASK)
/*! @} */

/* The count of TRDC_MGR_MEGA_TRDC_DERRLOC */
#define TRDC_MGR_MEGA_TRDC_DERRLOC_COUNT         (16U)

/*! @name MDA_W0_0_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_0_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_0_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_1_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_1_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_1_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_2_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_2_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_2_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_3_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_3_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_3_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_3_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_4_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_4_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_4_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_5_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_5_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_5_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_6_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_6_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_6_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_7_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_7_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_7_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_8_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_8_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_8_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_9_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DID_MASK    (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DID_SHIFT   (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DID(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_PA_MASK     (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_PA_SHIFT    (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_PA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_SA_MASK     (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_SA_SHIFT    (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_SA(x)       (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DIDB_MASK   (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DIDB_SHIFT  (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DIDB(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DFMT_MASK   (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DFMT_SHIFT  (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DFMT(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_LK1_MASK    (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_LK1_SHIFT   (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_LK1(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_VLD_MASK    (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_VLD_SHIFT   (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_9_DFMT1_VLD(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_9_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_10_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_10_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_10_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_11_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_11_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_11_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_12_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_12_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_12_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_12_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_13_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_13_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_13_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_13_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_14_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_14_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_14_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_14_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_15_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_15_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_15_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_15_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_16_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_16_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_16_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_16_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_17_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_17_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_17_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_17_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_18_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_18_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_18_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_18_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_19_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_19_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_19_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_19_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_20_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_20_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_20_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_20_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_21_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_21_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_21_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_21_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_22_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_22_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_22_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_22_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_23_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_23_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_23_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_23_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_24_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_24_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_24_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_24_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_25_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_25_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_25_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_25_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_26_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_26_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_26_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_26_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_27_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_27_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_27_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_27_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_28_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_28_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_28_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_28_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_29_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_29_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_29_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_29_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_30_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_30_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_30_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_30_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_31_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_31_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_31_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_31_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_32_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_32_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_32_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_32_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_33_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_33_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_33_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_33_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_34_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_34_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_34_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_34_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_35_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_35_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_35_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_35_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_36_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_36_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_36_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_36_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_37_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_37_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_37_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_37_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_38_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_38_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_38_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_38_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_39_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_39_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_39_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_39_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_40_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_40_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_40_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_40_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_41_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_41_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_41_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_41_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_42_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_42_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_42_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_42_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_43_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_43_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_43_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_43_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_44_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_44_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_44_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_44_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_45_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_45_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_45_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_45_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_46_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_46_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_46_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_46_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_47_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_47_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_47_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_47_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_48_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_48_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_48_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_48_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_49_DFMT1 - DAC Initiator Domain Assignment Register */
/*! @{ */

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DID_MASK   (0xFU)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DID_SHIFT  (0U)
/*! DID - Domain identifier */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DID(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DID_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DID_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_PA_MASK    (0x30U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_PA_SHIFT   (4U)
/*! PA - Privileged attribute
 *  0b00..Force the bus attribute for this initiator to user.
 *  0b01..Force the bus attribute for this initiator to privileged.
 *  0b10..Use the bus initiator's privileged/user attribute directly.
 *  0b11..Use the bus initiator's privileged/user attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_PA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_PA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_PA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_SA_MASK    (0xC0U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_SA_SHIFT   (6U)
/*! SA - Secure attribute
 *  0b00..Force the bus attribute for this initiator to secure.
 *  0b01..Force the bus attribute for this initiator to nonsecure.
 *  0b10..Use the bus initiator's secure/nonsecure attribute directly.
 *  0b11..Use the bus initiator's secure/nonsecure attribute directly.
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_SA(x)      (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_SA_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_SA_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DIDB_MASK  (0x100U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DIDB_SHIFT (8U)
/*! DIDB - DID Bypass
 *  0b0..Use MDAn[3:0] as the domain identifier.
 *  0b1..Use the DID input as the domain identifier.
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DIDB(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DIDB_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DIDB_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DFMT_MASK  (0x20000000U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DFMT_SHIFT (29U)
/*! DFMT - Domain format
 *  0b0..Processor-core domain assignment
 *  0b1..Non-processor domain assignment
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DFMT(x)    (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DFMT_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_DFMT_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_LK1_MASK   (0x40000000U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_LK1_SHIFT  (30U)
/*! LK1 - 1-bit Lock
 *  0b0..Register can be written by any secure privileged write.
 *  0b1..Register is locked (read-only) until the next reset.
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_LK1(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_LK1_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_LK1_MASK)

#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_VLD_MASK   (0x80000000U)
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_VLD_SHIFT  (31U)
/*! VLD - Valid
 *  0b0..The Wr domain assignment is invalid.
 *  0b1..The Wr domain assignment is valid.
 */
#define TRDC_MGR_MEGA_MDA_W0_49_DFMT1_VLD(x)     (((uint32_t)(((uint32_t)(x)) << TRDC_MGR_MEGA_MDA_W0_49_DFMT1_VLD_SHIFT)) & TRDC_MGR_MEGA_MDA_W0_49_DFMT1_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRDC_MGR_MEGA_Register_Masks */


/*!
 * @}
 */ /* end of group TRDC_MGR_MEGA_Peripheral_Access_Layer */


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


#endif  /* PERI_TRDC_MGR_MEGA_H_ */

