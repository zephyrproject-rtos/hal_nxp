/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_PPGC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_PPGC.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_PPGC
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_PPGC
 */

#if !defined(PERI_DWC_DDRPHYA_PPGC_H_)
#define PERI_DWC_DDRPHYA_PPGC_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- DWC_DDRPHYA_PPGC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_PPGC_Peripheral_Access_Layer DWC_DDRPHYA_PPGC Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_PPGC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[34];
  __IO uint16_t PPGCCTRL1;                         /**< PPGC Control1, offset: 0x22 */
       uint8_t RESERVED_1[6];
  __IO uint16_t PPGCLANE2CRCINMAP0;                /**< PPGC lane mapping for stressful pattern generation., offset: 0x2A */
  __IO uint16_t PPGCLANE2CRCINMAP1;                /**< PPGC lane mapping for stressful pattern generation., offset: 0x2C */
       uint8_t RESERVED_2[26];
  __IO uint16_t PRBSTAPDLY0_I0;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x48 */
  __IO uint16_t PRBSTAPDLY1_I0;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x4A */
  __IO uint16_t PRBSTAPDLY2_I0;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x4C */
  __IO uint16_t PRBSTAPDLY3_I0;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x4E */
       uint8_t RESERVED_3[16];
  __IO uint16_t GENPRBSBYTE0;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x60 */
  __IO uint16_t GENPRBSBYTE1;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x62 */
  __IO uint16_t GENPRBSBYTE2;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x64 */
  __IO uint16_t GENPRBSBYTE3;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x66 */
  __IO uint16_t GENPRBSBYTE4;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x68 */
  __IO uint16_t GENPRBSBYTE5;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x6A */
  __IO uint16_t GENPRBSBYTE6;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x6C */
  __IO uint16_t GENPRBSBYTE7;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x6E */
  __IO uint16_t GENPRBSBYTE8;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x70 */
  __IO uint16_t GENPRBSBYTE9;                      /**< PRBS Gen/Chk Polynomial select control., offset: 0x72 */
  __IO uint16_t GENPRBSBYTE10;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x74 */
  __IO uint16_t GENPRBSBYTE11;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x76 */
  __IO uint16_t GENPRBSBYTE12;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x78 */
  __IO uint16_t GENPRBSBYTE13;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x7A */
  __IO uint16_t GENPRBSBYTE14;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x7C */
  __IO uint16_t GENPRBSBYTE15;                     /**< PRBS Gen/Chk Polynomial select control., offset: 0x7E */
       uint8_t RESERVED_4[64];
  __IO uint16_t PRBSGENCTL;                        /**< PPGC mode control., offset: 0xC0 */
  __IO uint16_t PRBSGENSTATELO;                    /**< TX PPGC seed for low order bits., offset: 0xC2 */
  __IO uint16_t PRBSGENSTATEHI;                    /**< TX PPGC seed for high order bits., offset: 0xC4 */
  __IO uint16_t PRBSCHKSTATELO;                    /**< RX PPGC seed for low order bits., offset: 0xC6 */
  __IO uint16_t PRBSCHKSTATEHI;                    /**< RX PPGC seed for high order bits., offset: 0xC8 */
  __IO uint16_t PRBSGENCTL1;                       /**< PPGC per lane pattern/PRBS control, offset: 0xCA */
  __IO uint16_t PRBSGENCTL2;                       /**< PPGC pattern stress mode control., offset: 0xCC */
       uint8_t RESERVED_5[378];
  __IO uint16_t PRBSTAPDLY0_I1;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x248 */
  __IO uint16_t PRBSTAPDLY1_I1;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x24A */
  __IO uint16_t PRBSTAPDLY2_I1;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x24C */
  __IO uint16_t PRBSTAPDLY3_I1;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x24E */
       uint8_t RESERVED_6[504];
  __IO uint16_t PRBSTAPDLY0_I2;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x448 */
  __IO uint16_t PRBSTAPDLY1_I2;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x44A */
  __IO uint16_t PRBSTAPDLY2_I2;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x44C */
  __IO uint16_t PRBSTAPDLY3_I2;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x44E */
       uint8_t RESERVED_7[504];
  __IO uint16_t PRBSTAPDLY0_I3;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x648 */
  __IO uint16_t PRBSTAPDLY1_I3;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x64A */
  __IO uint16_t PRBSTAPDLY2_I3;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x64C */
  __IO uint16_t PRBSTAPDLY3_I3;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x64E */
       uint8_t RESERVED_8[504];
  __IO uint16_t PRBSTAPDLY0_I4;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x848 */
  __IO uint16_t PRBSTAPDLY1_I4;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x84A */
  __IO uint16_t PRBSTAPDLY2_I4;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x84C */
  __IO uint16_t PRBSTAPDLY3_I4;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x84E */
       uint8_t RESERVED_9[504];
  __IO uint16_t PRBSTAPDLY0_I5;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xA48 */
  __IO uint16_t PRBSTAPDLY1_I5;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xA4A */
  __IO uint16_t PRBSTAPDLY2_I5;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xA4C */
  __IO uint16_t PRBSTAPDLY3_I5;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xA4E */
       uint8_t RESERVED_10[504];
  __IO uint16_t PRBSTAPDLY0_I6;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xC48 */
  __IO uint16_t PRBSTAPDLY1_I6;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xC4A */
  __IO uint16_t PRBSTAPDLY2_I6;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xC4C */
  __IO uint16_t PRBSTAPDLY3_I6;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xC4E */
       uint8_t RESERVED_11[504];
  __IO uint16_t PRBSTAPDLY0_I7;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xE48 */
  __IO uint16_t PRBSTAPDLY1_I7;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xE4A */
  __IO uint16_t PRBSTAPDLY2_I7;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xE4C */
  __IO uint16_t PRBSTAPDLY3_I7;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0xE4E */
       uint8_t RESERVED_12[504];
  __IO uint16_t PRBSTAPDLY0_I8;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x1048 */
  __IO uint16_t PRBSTAPDLY1_I8;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x104A */
  __IO uint16_t PRBSTAPDLY2_I8;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x104C */
  __IO uint16_t PRBSTAPDLY3_I8;                    /**< Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset., offset: 0x104E */
} DWC_DDRPHYA_PPGC_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_PPGC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_PPGC_Register_Masks DWC_DDRPHYA_PPGC Register Masks
 * @{
 */

/*! @name PPGCCTRL1 - PPGC Control1 */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PPGCCTRL1_RFU_PPGCCtrl1_MASK (0x1EU)
#define DWC_DDRPHYA_PPGC_PPGCCTRL1_RFU_PPGCCtrl1_SHIFT (1U)
/*! RFU_PPGCCtrl1 - RFU_PPGCCtrl1 */
#define DWC_DDRPHYA_PPGC_PPGCCTRL1_RFU_PPGCCtrl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PPGCCTRL1_RFU_PPGCCtrl1_SHIFT)) & DWC_DDRPHYA_PPGC_PPGCCTRL1_RFU_PPGCCtrl1_MASK)
/*! @} */

/*! @name PPGCLANE2CRCINMAP0 - PPGC lane mapping for stressful pattern generation. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP0_RFU_PpgcLane2CrcInMap0_MASK (0xFFFU)
#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP0_RFU_PpgcLane2CrcInMap0_SHIFT (0U)
/*! RFU_PpgcLane2CrcInMap0 - RFU_PpgcLane2CrcInMap0 */
#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP0_RFU_PpgcLane2CrcInMap0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP0_RFU_PpgcLane2CrcInMap0_SHIFT)) & DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP0_RFU_PpgcLane2CrcInMap0_MASK)
/*! @} */

/*! @name PPGCLANE2CRCINMAP1 - PPGC lane mapping for stressful pattern generation. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP1_RFU_PpgcLane2CrcInMap1_MASK (0xFFFU)
#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP1_RFU_PpgcLane2CrcInMap1_SHIFT (0U)
/*! RFU_PpgcLane2CrcInMap1 - RFU_PpgcLane2CrcInMap1 */
#define DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP1_RFU_PpgcLane2CrcInMap1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP1_RFU_PpgcLane2CrcInMap1_SHIFT)) & DWC_DDRPHYA_PPGC_PPGCLANE2CRCINMAP1_RFU_PpgcLane2CrcInMap1_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I0 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I0_PrbsTapDly0_i0_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I0_PrbsTapDly0_i0_SHIFT (0U)
/*! PrbsTapDly0_i0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I0_PrbsTapDly0_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I0_PrbsTapDly0_i0_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I0_PrbsTapDly0_i0_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I0 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I0_PrbsTapDly1_i0_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I0_PrbsTapDly1_i0_SHIFT (0U)
/*! PrbsTapDly1_i0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I0_PrbsTapDly1_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I0_PrbsTapDly1_i0_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I0_PrbsTapDly1_i0_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I0 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I0_PrbsTapDly2_i0_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I0_PrbsTapDly2_i0_SHIFT (0U)
/*! PrbsTapDly2_i0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I0_PrbsTapDly2_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I0_PrbsTapDly2_i0_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I0_PrbsTapDly2_i0_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I0 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I0_PrbsTapDly3_i0_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I0_PrbsTapDly3_i0_SHIFT (0U)
/*! PrbsTapDly3_i0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I0_PrbsTapDly3_i0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I0_PrbsTapDly3_i0_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I0_PrbsTapDly3_i0_MASK)
/*! @} */

/*! @name GENPRBSBYTE0 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE0_GenPrbsByte0_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE0_GenPrbsByte0_SHIFT (0U)
/*! GenPrbsByte0 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE0_GenPrbsByte0(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE0_GenPrbsByte0_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE0_GenPrbsByte0_MASK)
/*! @} */

/*! @name GENPRBSBYTE1 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE1_GenPrbsByte1_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE1_GenPrbsByte1_SHIFT (0U)
/*! GenPrbsByte1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE1_GenPrbsByte1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE1_GenPrbsByte1_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE1_GenPrbsByte1_MASK)
/*! @} */

/*! @name GENPRBSBYTE2 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE2_GenPrbsByte2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE2_GenPrbsByte2_SHIFT (0U)
/*! GenPrbsByte2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE2_GenPrbsByte2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE2_GenPrbsByte2_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE2_GenPrbsByte2_MASK)
/*! @} */

/*! @name GENPRBSBYTE3 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE3_GenPrbsByte3_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE3_GenPrbsByte3_SHIFT (0U)
/*! GenPrbsByte3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE3_GenPrbsByte3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE3_GenPrbsByte3_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE3_GenPrbsByte3_MASK)
/*! @} */

/*! @name GENPRBSBYTE4 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE4_GenPrbsByte4_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE4_GenPrbsByte4_SHIFT (0U)
/*! GenPrbsByte4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE4_GenPrbsByte4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE4_GenPrbsByte4_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE4_GenPrbsByte4_MASK)
/*! @} */

/*! @name GENPRBSBYTE5 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE5_GenPrbsByte5_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE5_GenPrbsByte5_SHIFT (0U)
/*! GenPrbsByte5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE5_GenPrbsByte5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE5_GenPrbsByte5_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE5_GenPrbsByte5_MASK)
/*! @} */

/*! @name GENPRBSBYTE6 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE6_GenPrbsByte6_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE6_GenPrbsByte6_SHIFT (0U)
/*! GenPrbsByte6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE6_GenPrbsByte6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE6_GenPrbsByte6_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE6_GenPrbsByte6_MASK)
/*! @} */

/*! @name GENPRBSBYTE7 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE7_GenPrbsByte7_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE7_GenPrbsByte7_SHIFT (0U)
/*! GenPrbsByte7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE7_GenPrbsByte7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE7_GenPrbsByte7_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE7_GenPrbsByte7_MASK)
/*! @} */

/*! @name GENPRBSBYTE8 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE8_GenPrbsByte8_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE8_GenPrbsByte8_SHIFT (0U)
/*! GenPrbsByte8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE8_GenPrbsByte8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE8_GenPrbsByte8_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE8_GenPrbsByte8_MASK)
/*! @} */

/*! @name GENPRBSBYTE9 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE9_GenPrbsByte9_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE9_GenPrbsByte9_SHIFT (0U)
/*! GenPrbsByte9 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE9_GenPrbsByte9(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE9_GenPrbsByte9_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE9_GenPrbsByte9_MASK)
/*! @} */

/*! @name GENPRBSBYTE10 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE10_GenPrbsByte10_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE10_GenPrbsByte10_SHIFT (0U)
/*! GenPrbsByte10 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE10_GenPrbsByte10(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE10_GenPrbsByte10_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE10_GenPrbsByte10_MASK)
/*! @} */

/*! @name GENPRBSBYTE11 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE11_GenPrbsByte11_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE11_GenPrbsByte11_SHIFT (0U)
/*! GenPrbsByte11 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE11_GenPrbsByte11(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE11_GenPrbsByte11_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE11_GenPrbsByte11_MASK)
/*! @} */

/*! @name GENPRBSBYTE12 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE12_GenPrbsByte12_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE12_GenPrbsByte12_SHIFT (0U)
/*! GenPrbsByte12 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE12_GenPrbsByte12(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE12_GenPrbsByte12_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE12_GenPrbsByte12_MASK)
/*! @} */

/*! @name GENPRBSBYTE13 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE13_GenPrbsByte13_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE13_GenPrbsByte13_SHIFT (0U)
/*! GenPrbsByte13 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE13_GenPrbsByte13(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE13_GenPrbsByte13_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE13_GenPrbsByte13_MASK)
/*! @} */

/*! @name GENPRBSBYTE14 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE14_GenPrbsByte14_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE14_GenPrbsByte14_SHIFT (0U)
/*! GenPrbsByte14 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE14_GenPrbsByte14(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE14_GenPrbsByte14_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE14_GenPrbsByte14_MASK)
/*! @} */

/*! @name GENPRBSBYTE15 - PRBS Gen/Chk Polynomial select control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_GENPRBSBYTE15_GenPrbsByte15_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE15_GenPrbsByte15_SHIFT (0U)
/*! GenPrbsByte15 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_GENPRBSBYTE15_GenPrbsByte15(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_GENPRBSBYTE15_GenPrbsByte15_SHIFT)) & DWC_DDRPHYA_PPGC_GENPRBSBYTE15_GenPrbsByte15_MASK)
/*! @} */

/*! @name PRBSGENCTL - PPGC mode control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSGENCTL_RFU_PrbsGenCtl_MASK (0x7FU)
#define DWC_DDRPHYA_PPGC_PRBSGENCTL_RFU_PrbsGenCtl_SHIFT (0U)
/*! RFU_PrbsGenCtl - RFU_PrbsGenCtl */
#define DWC_DDRPHYA_PPGC_PRBSGENCTL_RFU_PrbsGenCtl(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSGENCTL_RFU_PrbsGenCtl_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSGENCTL_RFU_PrbsGenCtl_MASK)
/*! @} */

/*! @name PRBSGENSTATELO - TX PPGC seed for low order bits. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSGENSTATELO_PrbsGenStateLo_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSGENSTATELO_PrbsGenStateLo_SHIFT (0U)
/*! PrbsGenStateLo - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSGENSTATELO_PrbsGenStateLo(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSGENSTATELO_PrbsGenStateLo_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSGENSTATELO_PrbsGenStateLo_MASK)
/*! @} */

/*! @name PRBSGENSTATEHI - TX PPGC seed for high order bits. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSGENSTATEHI_PrbsGenStateHi_MASK (0x7FU)
#define DWC_DDRPHYA_PPGC_PRBSGENSTATEHI_PrbsGenStateHi_SHIFT (0U)
/*! PrbsGenStateHi - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSGENSTATEHI_PrbsGenStateHi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSGENSTATEHI_PrbsGenStateHi_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSGENSTATEHI_PrbsGenStateHi_MASK)
/*! @} */

/*! @name PRBSCHKSTATELO - RX PPGC seed for low order bits. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSCHKSTATELO_PrbsChkStateLo_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSCHKSTATELO_PrbsChkStateLo_SHIFT (0U)
/*! PrbsChkStateLo - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSCHKSTATELO_PrbsChkStateLo(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSCHKSTATELO_PrbsChkStateLo_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSCHKSTATELO_PrbsChkStateLo_MASK)
/*! @} */

/*! @name PRBSCHKSTATEHI - RX PPGC seed for high order bits. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSCHKSTATEHI_PrbsChkStateHi_MASK (0x7FU)
#define DWC_DDRPHYA_PPGC_PRBSCHKSTATEHI_PrbsChkStateHi_SHIFT (0U)
/*! PrbsChkStateHi - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSCHKSTATEHI_PrbsChkStateHi(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSCHKSTATEHI_PrbsChkStateHi_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSCHKSTATEHI_PrbsChkStateHi_MASK)
/*! @} */

/*! @name PRBSGENCTL1 - PPGC per lane pattern/PRBS control */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSGENCTL1_RFU_PrbsGenCtl1_MASK (0x1FFU)
#define DWC_DDRPHYA_PPGC_PRBSGENCTL1_RFU_PrbsGenCtl1_SHIFT (0U)
/*! RFU_PrbsGenCtl1 - RFU_PrbsGenCtl1 */
#define DWC_DDRPHYA_PPGC_PRBSGENCTL1_RFU_PrbsGenCtl1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSGENCTL1_RFU_PrbsGenCtl1_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSGENCTL1_RFU_PrbsGenCtl1_MASK)
/*! @} */

/*! @name PRBSGENCTL2 - PPGC pattern stress mode control. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSGENCTL2_RFU_PrbsGenCtl2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSGENCTL2_RFU_PrbsGenCtl2_SHIFT (0U)
/*! RFU_PrbsGenCtl2 - RFU_PrbsGenCtl2 */
#define DWC_DDRPHYA_PPGC_PRBSGENCTL2_RFU_PrbsGenCtl2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSGENCTL2_RFU_PrbsGenCtl2_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSGENCTL2_RFU_PrbsGenCtl2_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I1 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I1_PrbsTapDly0_i1_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I1_PrbsTapDly0_i1_SHIFT (0U)
/*! PrbsTapDly0_i1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I1_PrbsTapDly0_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I1_PrbsTapDly0_i1_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I1_PrbsTapDly0_i1_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I1 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I1_PrbsTapDly1_i1_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I1_PrbsTapDly1_i1_SHIFT (0U)
/*! PrbsTapDly1_i1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I1_PrbsTapDly1_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I1_PrbsTapDly1_i1_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I1_PrbsTapDly1_i1_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I1 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I1_PrbsTapDly2_i1_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I1_PrbsTapDly2_i1_SHIFT (0U)
/*! PrbsTapDly2_i1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I1_PrbsTapDly2_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I1_PrbsTapDly2_i1_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I1_PrbsTapDly2_i1_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I1 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I1_PrbsTapDly3_i1_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I1_PrbsTapDly3_i1_SHIFT (0U)
/*! PrbsTapDly3_i1 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I1_PrbsTapDly3_i1(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I1_PrbsTapDly3_i1_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I1_PrbsTapDly3_i1_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I2 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I2_PrbsTapDly0_i2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I2_PrbsTapDly0_i2_SHIFT (0U)
/*! PrbsTapDly0_i2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I2_PrbsTapDly0_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I2_PrbsTapDly0_i2_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I2_PrbsTapDly0_i2_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I2 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I2_PrbsTapDly1_i2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I2_PrbsTapDly1_i2_SHIFT (0U)
/*! PrbsTapDly1_i2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I2_PrbsTapDly1_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I2_PrbsTapDly1_i2_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I2_PrbsTapDly1_i2_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I2 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I2_PrbsTapDly2_i2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I2_PrbsTapDly2_i2_SHIFT (0U)
/*! PrbsTapDly2_i2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I2_PrbsTapDly2_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I2_PrbsTapDly2_i2_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I2_PrbsTapDly2_i2_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I2 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I2_PrbsTapDly3_i2_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I2_PrbsTapDly3_i2_SHIFT (0U)
/*! PrbsTapDly3_i2 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I2_PrbsTapDly3_i2(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I2_PrbsTapDly3_i2_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I2_PrbsTapDly3_i2_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I3 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I3_PrbsTapDly0_i3_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I3_PrbsTapDly0_i3_SHIFT (0U)
/*! PrbsTapDly0_i3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I3_PrbsTapDly0_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I3_PrbsTapDly0_i3_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I3_PrbsTapDly0_i3_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I3 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I3_PrbsTapDly1_i3_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I3_PrbsTapDly1_i3_SHIFT (0U)
/*! PrbsTapDly1_i3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I3_PrbsTapDly1_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I3_PrbsTapDly1_i3_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I3_PrbsTapDly1_i3_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I3 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I3_PrbsTapDly2_i3_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I3_PrbsTapDly2_i3_SHIFT (0U)
/*! PrbsTapDly2_i3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I3_PrbsTapDly2_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I3_PrbsTapDly2_i3_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I3_PrbsTapDly2_i3_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I3 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I3_PrbsTapDly3_i3_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I3_PrbsTapDly3_i3_SHIFT (0U)
/*! PrbsTapDly3_i3 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I3_PrbsTapDly3_i3(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I3_PrbsTapDly3_i3_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I3_PrbsTapDly3_i3_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I4 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I4_PrbsTapDly0_i4_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I4_PrbsTapDly0_i4_SHIFT (0U)
/*! PrbsTapDly0_i4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I4_PrbsTapDly0_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I4_PrbsTapDly0_i4_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I4_PrbsTapDly0_i4_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I4 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I4_PrbsTapDly1_i4_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I4_PrbsTapDly1_i4_SHIFT (0U)
/*! PrbsTapDly1_i4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I4_PrbsTapDly1_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I4_PrbsTapDly1_i4_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I4_PrbsTapDly1_i4_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I4 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I4_PrbsTapDly2_i4_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I4_PrbsTapDly2_i4_SHIFT (0U)
/*! PrbsTapDly2_i4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I4_PrbsTapDly2_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I4_PrbsTapDly2_i4_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I4_PrbsTapDly2_i4_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I4 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I4_PrbsTapDly3_i4_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I4_PrbsTapDly3_i4_SHIFT (0U)
/*! PrbsTapDly3_i4 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I4_PrbsTapDly3_i4(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I4_PrbsTapDly3_i4_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I4_PrbsTapDly3_i4_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I5 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I5_PrbsTapDly0_i5_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I5_PrbsTapDly0_i5_SHIFT (0U)
/*! PrbsTapDly0_i5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I5_PrbsTapDly0_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I5_PrbsTapDly0_i5_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I5_PrbsTapDly0_i5_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I5 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I5_PrbsTapDly1_i5_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I5_PrbsTapDly1_i5_SHIFT (0U)
/*! PrbsTapDly1_i5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I5_PrbsTapDly1_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I5_PrbsTapDly1_i5_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I5_PrbsTapDly1_i5_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I5 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I5_PrbsTapDly2_i5_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I5_PrbsTapDly2_i5_SHIFT (0U)
/*! PrbsTapDly2_i5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I5_PrbsTapDly2_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I5_PrbsTapDly2_i5_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I5_PrbsTapDly2_i5_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I5 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I5_PrbsTapDly3_i5_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I5_PrbsTapDly3_i5_SHIFT (0U)
/*! PrbsTapDly3_i5 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I5_PrbsTapDly3_i5(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I5_PrbsTapDly3_i5_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I5_PrbsTapDly3_i5_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I6 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I6_PrbsTapDly0_i6_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I6_PrbsTapDly0_i6_SHIFT (0U)
/*! PrbsTapDly0_i6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I6_PrbsTapDly0_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I6_PrbsTapDly0_i6_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I6_PrbsTapDly0_i6_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I6 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I6_PrbsTapDly1_i6_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I6_PrbsTapDly1_i6_SHIFT (0U)
/*! PrbsTapDly1_i6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I6_PrbsTapDly1_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I6_PrbsTapDly1_i6_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I6_PrbsTapDly1_i6_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I6 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I6_PrbsTapDly2_i6_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I6_PrbsTapDly2_i6_SHIFT (0U)
/*! PrbsTapDly2_i6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I6_PrbsTapDly2_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I6_PrbsTapDly2_i6_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I6_PrbsTapDly2_i6_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I6 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I6_PrbsTapDly3_i6_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I6_PrbsTapDly3_i6_SHIFT (0U)
/*! PrbsTapDly3_i6 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I6_PrbsTapDly3_i6(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I6_PrbsTapDly3_i6_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I6_PrbsTapDly3_i6_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I7 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I7_PrbsTapDly0_i7_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I7_PrbsTapDly0_i7_SHIFT (0U)
/*! PrbsTapDly0_i7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I7_PrbsTapDly0_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I7_PrbsTapDly0_i7_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I7_PrbsTapDly0_i7_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I7 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I7_PrbsTapDly1_i7_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I7_PrbsTapDly1_i7_SHIFT (0U)
/*! PrbsTapDly1_i7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I7_PrbsTapDly1_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I7_PrbsTapDly1_i7_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I7_PrbsTapDly1_i7_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I7 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I7_PrbsTapDly2_i7_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I7_PrbsTapDly2_i7_SHIFT (0U)
/*! PrbsTapDly2_i7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I7_PrbsTapDly2_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I7_PrbsTapDly2_i7_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I7_PrbsTapDly2_i7_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I7 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I7_PrbsTapDly3_i7_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I7_PrbsTapDly3_i7_SHIFT (0U)
/*! PrbsTapDly3_i7 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I7_PrbsTapDly3_i7(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I7_PrbsTapDly3_i7_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I7_PrbsTapDly3_i7_MASK)
/*! @} */

/*! @name PRBSTAPDLY0_I8 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I8_PrbsTapDly0_i8_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I8_PrbsTapDly0_i8_SHIFT (0U)
/*! PrbsTapDly0_i8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I8_PrbsTapDly0_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I8_PrbsTapDly0_i8_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY0_I8_PrbsTapDly0_i8_MASK)
/*! @} */

/*! @name PRBSTAPDLY1_I8 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I8_PrbsTapDly1_i8_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I8_PrbsTapDly1_i8_SHIFT (0U)
/*! PrbsTapDly1_i8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I8_PrbsTapDly1_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I8_PrbsTapDly1_i8_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY1_I8_PrbsTapDly1_i8_MASK)
/*! @} */

/*! @name PRBSTAPDLY2_I8 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I8_PrbsTapDly2_i8_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I8_PrbsTapDly2_i8_SHIFT (0U)
/*! PrbsTapDly2_i8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I8_PrbsTapDly2_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I8_PrbsTapDly2_i8_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY2_I8_PrbsTapDly2_i8_MASK)
/*! @} */

/*! @name PRBSTAPDLY3_I8 - Per lane Dual purposed CSRs for 32b pattern or PRBS starting offset. */
/*! @{ */

#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I8_PrbsTapDly3_i8_MASK (0xFFFFU)
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I8_PrbsTapDly3_i8_SHIFT (0U)
/*! PrbsTapDly3_i8 - Reserved for PHY training firmware use. */
#define DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I8_PrbsTapDly3_i8(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I8_PrbsTapDly3_i8_SHIFT)) & DWC_DDRPHYA_PPGC_PRBSTAPDLY3_I8_PrbsTapDly3_i8_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_PPGC_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_PPGC_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_PPGC_H_ */
