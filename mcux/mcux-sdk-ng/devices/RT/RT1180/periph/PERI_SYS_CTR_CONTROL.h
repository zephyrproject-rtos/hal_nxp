/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYS_CTR_CONTROL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 */

#if !defined(PERI_SYS_CTR_CONTROL_H_)
#define PERI_SYS_CTR_CONTROL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- SYS_CTR_CONTROL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Peripheral_Access_Layer SYS_CTR_CONTROL Peripheral Access Layer
 * @{
 */

/** SYS_CTR_CONTROL - Register Layout Typedef */
typedef struct {
  __IO uint32_t CNTCR;                             /**< Counter Control, offset: 0x0 */
  __I  uint32_t CNTSR;                             /**< Counter Status, offset: 0x4 */
  __IO uint32_t CNTCV0;                            /**< Counter Count Value Low, offset: 0x8 */
  __IO uint32_t CNTCV1;                            /**< Counter Count Value High, offset: 0xC */
       uint8_t RESERVED_0[16];
  __I  uint32_t CNTFID0;                           /**< Frequency-Modes Table 0, offset: 0x20 */
  __I  uint32_t CNTFID1;                           /**< Frequency-Modes Table 1, offset: 0x24 */
  __I  uint32_t CNTFID2;                           /**< Frequency-Modes Table 2, offset: 0x28 */
       uint8_t RESERVED_1[148];
  __IO uint32_t CNTCR2;                            /**< Counter Control 2, offset: 0xC0 */
       uint8_t RESERVED_2[3852];
  __I  uint32_t CNTID0;                            /**< Counter ID, offset: 0xFD0 */
} SYS_CTR_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Register_Masks SYS_CTR_CONTROL Register Masks
 * @{
 */

/*! @name CNTCR - Counter Control */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR_EN_MASK            (0x1U)
#define SYS_CTR_CONTROL_CNTCR_EN_SHIFT           (0U)
/*! EN - Enable Counting
 *  0b0..Disable
 *  0b1..Enable
 */
#define SYS_CTR_CONTROL_CNTCR_EN(x)              (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR_EN_MASK)

#define SYS_CTR_CONTROL_CNTCR_HDBG_MASK          (0x2U)
#define SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT         (1U)
/*! HDBG - Enable Debug Halt
 *  0b0..Ignored
 *  0b1..Causes SYS_CTR to halt
 */
#define SYS_CTR_CONTROL_CNTCR_HDBG(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT)) & SYS_CTR_CONTROL_CNTCR_HDBG_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT         (8U)
/*! FCR0 - Frequency Change Request, ID 0
 *  0b0..No change
 *  0b1..Base frequency
 */
#define SYS_CTR_CONTROL_CNTCR_FCR0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR0_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT         (9U)
/*! FCR1 - Frequency Change Request, ID 1
 *  0b0..No change
 *  0b1..Base frequency
 */
#define SYS_CTR_CONTROL_CNTCR_FCR1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR1_MASK)
/*! @} */

/*! @name CNTSR - Counter Status */
/*! @{ */

#define SYS_CTR_CONTROL_CNTSR_DBGH_MASK          (0x1U)
#define SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT         (0U)
/*! DBGH - Debug Halt
 *  0b0..Did not halt
 *  0b1..Halted
 */
#define SYS_CTR_CONTROL_CNTSR_DBGH(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT)) & SYS_CTR_CONTROL_CNTSR_DBGH_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT         (8U)
/*! FCA0 - Frequency Change Acknowledge, ID 0
 *  0b0..Not selected
 *  0b1..Selected
 */
#define SYS_CTR_CONTROL_CNTSR_FCA0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA0_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT         (9U)
/*! FCA1 - Frequency Change Acknowledge, ID 1
 *  0b0..Not selected
 *  0b1..Selected
 */
#define SYS_CTR_CONTROL_CNTSR_FCA1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA1_MASK)
/*! @} */

/*! @name CNTCV0 - Counter Count Value Low */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK       (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT      (0U)
/*! CNTCV0 - Counter Count Value Bits [31:0] */
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT)) & SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK)
/*! @} */

/*! @name CNTCV1 - Counter Count Value High */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK       (0xFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT      (0U)
/*! CNTCV1 - Counter Count Value Bits [55:32] */
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT)) & SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK)
/*! @} */

/*! @name CNTFID0 - Frequency-Modes Table 0 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT    (0U)
/*! CNTFID0 - Counter Frequency ID 0 */
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT)) & SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK)
/*! @} */

/*! @name CNTFID1 - Frequency-Modes Table 1 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT    (0U)
/*! CNTFID1 - Counter Frequency ID 1 */
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT)) & SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK)
/*! @} */

/*! @name CNTFID2 - Frequency-Modes Table 2 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT    (0U)
/*! CNTFID2 - Counter Frequency ID 2 */
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT)) & SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK)
/*! @} */

/*! @name CNTCR2 - Counter Control 2 */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN_MASK      (0x1U)
#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN_SHIFT     (0U)
/*! HWFC_EN - Hardware Frequency Change Enable
 *  0b0..No effect
 *  0b1..Same as performed via software
 */
#define SYS_CTR_CONTROL_CNTCR2_HWFC_EN(x)        (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR2_HWFC_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR2_HWFC_EN_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID */
/*! @{ */

#define SYS_CTR_CONTROL_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT       (0U)
/*! CNTID - Counter Identification */
#define SYS_CTR_CONTROL_CNTID0_CNTID(x)          (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT)) & SYS_CTR_CONTROL_CNTID0_CNTID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Register_Masks */


/*!
 * @}
 */ /* end of group SYS_CTR_CONTROL_Peripheral_Access_Layer */


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


#endif  /* PERI_SYS_CTR_CONTROL_H_ */

