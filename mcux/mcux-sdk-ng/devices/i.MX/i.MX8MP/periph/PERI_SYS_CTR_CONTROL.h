/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYS_CTR_CONTROL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 *
 * CMSIS Peripheral Access Layer for SYS_CTR_CONTROL
 */

#if !defined(PERI_SYS_CTR_CONTROL_H_)
#define PERI_SYS_CTR_CONTROL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
  __IO uint32_t CNTCR;                             /**< Counter Control Register, offset: 0x0 */
  __I  uint32_t CNTSR;                             /**< Counter Status Register, offset: 0x4 */
  __IO uint32_t CNTCV0;                            /**< Counter Count Value Low Register, offset: 0x8 */
  __IO uint32_t CNTCV1;                            /**< Counter Count Value High Register, offset: 0xC */
       uint8_t RESERVED_0[16];
  __I  uint32_t CNTFID0;                           /**< Frequency Modes Table 0 Register, offset: 0x20 */
  __I  uint32_t CNTFID1;                           /**< Frequency Modes Table 1 Register, offset: 0x24 */
  __I  uint32_t CNTFID2;                           /**< Frequency Modes Table 2 Register, offset: 0x28 */
       uint8_t RESERVED_1[4004];
  __I  uint32_t CNTID0;                            /**< Counter ID Register, offset: 0xFD0 */
} SYS_CTR_CONTROL_Type;

/* ----------------------------------------------------------------------------
   -- SYS_CTR_CONTROL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYS_CTR_CONTROL_Register_Masks SYS_CTR_CONTROL Register Masks
 * @{
 */

/*! @name CNTCR - Counter Control Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCR_EN_MASK            (0x1U)
#define SYS_CTR_CONTROL_CNTCR_EN_SHIFT           (0U)
/*! EN
 *  0b0..Counter disabled
 *  0b1..Counter enabled
 */
#define SYS_CTR_CONTROL_CNTCR_EN(x)              (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_EN_SHIFT)) & SYS_CTR_CONTROL_CNTCR_EN_MASK)

#define SYS_CTR_CONTROL_CNTCR_HDBG_MASK          (0x2U)
#define SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT         (1U)
/*! HDBG
 *  0b0..The assertion of the debug input is ignored.
 *  0b1..The assertion of the debug input causes the System Counter to halt.
 */
#define SYS_CTR_CONTROL_CNTCR_HDBG(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_HDBG_SHIFT)) & SYS_CTR_CONTROL_CNTCR_HDBG_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT         (8U)
/*! FCR0
 *  0b0..No change.
 *  0b1..Select frequency modes table entry 0, the base frequency.
 */
#define SYS_CTR_CONTROL_CNTCR_FCR0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR0_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR0_MASK)

#define SYS_CTR_CONTROL_CNTCR_FCR1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT         (9U)
/*! FCR1
 *  0b0..No change.
 *  0b1..Select frequency modes table entry 1, the base frequency.
 */
#define SYS_CTR_CONTROL_CNTCR_FCR1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCR_FCR1_SHIFT)) & SYS_CTR_CONTROL_CNTCR_FCR1_MASK)
/*! @} */

/*! @name CNTSR - Counter Status Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTSR_DBGH_MASK          (0x1U)
#define SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT         (0U)
/*! DBGH
 *  0b0..Counter is not halted by debug.
 *  0b1..Counter is halted by debug.
 */
#define SYS_CTR_CONTROL_CNTSR_DBGH(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_DBGH_SHIFT)) & SYS_CTR_CONTROL_CNTSR_DBGH_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA0_MASK          (0x100U)
#define SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT         (8U)
/*! FCA0
 *  0b0..Base frequency is not selected.
 *  0b1..Base frequency is selected.
 */
#define SYS_CTR_CONTROL_CNTSR_FCA0(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA0_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA0_MASK)

#define SYS_CTR_CONTROL_CNTSR_FCA1_MASK          (0x200U)
#define SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT         (9U)
/*! FCA1
 *  0b0..Base frequency is not selected.
 *  0b1..Base frequency is selected.
 */
#define SYS_CTR_CONTROL_CNTSR_FCA1(x)            (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTSR_FCA1_SHIFT)) & SYS_CTR_CONTROL_CNTSR_FCA1_MASK)
/*! @} */

/*! @name CNTCV0 - Counter Count Value Low Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK       (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT      (0U)
#define SYS_CTR_CONTROL_CNTCV0_CNTCV0(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV0_CNTCV0_SHIFT)) & SYS_CTR_CONTROL_CNTCV0_CNTCV0_MASK)
/*! @} */

/*! @name CNTCV1 - Counter Count Value High Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK       (0x1FFFFFFU)
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT      (0U)
#define SYS_CTR_CONTROL_CNTCV1_CNTCV1(x)         (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTCV1_CNTCV1_SHIFT)) & SYS_CTR_CONTROL_CNTCV1_CNTCV1_MASK)
/*! @} */

/*! @name CNTFID0 - Frequency Modes Table 0 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT    (0U)
#define SYS_CTR_CONTROL_CNTFID0_CNTFID0(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID0_CNTFID0_SHIFT)) & SYS_CTR_CONTROL_CNTFID0_CNTFID0_MASK)
/*! @} */

/*! @name CNTFID1 - Frequency Modes Table 1 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT    (0U)
#define SYS_CTR_CONTROL_CNTFID1_CNTFID1(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID1_CNTFID1_SHIFT)) & SYS_CTR_CONTROL_CNTFID1_CNTFID1_MASK)
/*! @} */

/*! @name CNTFID2 - Frequency Modes Table 2 Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK     (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT    (0U)
#define SYS_CTR_CONTROL_CNTFID2_CNTFID2(x)       (((uint32_t)(((uint32_t)(x)) << SYS_CTR_CONTROL_CNTFID2_CNTFID2_SHIFT)) & SYS_CTR_CONTROL_CNTFID2_CNTFID2_MASK)
/*! @} */

/*! @name CNTID0 - Counter ID Register */
/*! @{ */

#define SYS_CTR_CONTROL_CNTID0_CNTID_MASK        (0xFFFFFFFFU)
#define SYS_CTR_CONTROL_CNTID0_CNTID_SHIFT       (0U)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_SYS_CTR_CONTROL_H_ */

