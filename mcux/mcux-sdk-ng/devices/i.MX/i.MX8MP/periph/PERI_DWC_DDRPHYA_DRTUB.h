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
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
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
 * @file PERI_DWC_DDRPHYA_DRTUB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_DRTUB
 */

#if !defined(PERI_DWC_DDRPHYA_DRTUB_H_)
#define PERI_DWC_DDRPHYA_DRTUB_H_                /**< Symbol preventing repeated inclusion */

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
   -- DWC_DDRPHYA_DRTUB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DRTUB_Peripheral_Access_Layer DWC_DDRPHYA_DRTUB Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_DRTUB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint16_t UCCLKHCLKENABLES;                  /**< Ucclk and Hclk enables, offset: 0x100 */
  __IO uint16_t CURPSTATE0B;                       /**< PIE current Pstate value, offset: 0x102 */
       uint8_t RESERVED_1[214];
  __I  uint16_t CUSTPUBREV;                        /**< Customer settable by the customer, offset: 0x1DA */
  __I  uint16_t PUBREV;                            /**< The hardware version of this PUB, excluding the PHY, offset: 0x1DC */
} DWC_DDRPHYA_DRTUB_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_DRTUB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_DRTUB_Register_Masks DWC_DDRPHYA_DRTUB Register Masks
 * @{
 */

/*! @name UCCLKHCLKENABLES - Ucclk and Hclk enables */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UCCLKEN_MASK (0x1U)
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UCCLKEN_SHIFT (0U)
/*! UcclkEn - When training has completed (and assuming no further need for the microcontroller),
 *    the enable should be set to 0 to reduce power.
 */
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UCCLKEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UCCLKEN_SHIFT)) & DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_UCCLKEN_MASK)

#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HCLKEN_MASK (0x2U)
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HCLKEN_SHIFT (1U)
/*! HclkEn - When training has completed (and assuming no further need for the training hardware),
 *    the enable should be set to 0 to reduce power.
 */
#define DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HCLKEN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HCLKEN_SHIFT)) & DWC_DDRPHYA_DRTUB_UCCLKHCLKENABLES_HCLKEN_MASK)
/*! @} */

/*! @name CURPSTATE0B - PIE current Pstate value */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CURPSTATE0B_MASK (0xFU)
#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CURPSTATE0B_SHIFT (0U)
/*! CurPstate0b - PIE current Pstate value This register is used to select values for writing by the
 *    Pstate sequencer and is written in the beginning of the Pstate switch.
 */
#define DWC_DDRPHYA_DRTUB_CURPSTATE0B_CURPSTATE0B(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_CURPSTATE0B_CURPSTATE0B_SHIFT)) & DWC_DDRPHYA_DRTUB_CURPSTATE0B_CURPSTATE0B_MASK)
/*! @} */

/*! @name CUSTPUBREV - Customer settable by the customer */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_MASK (0x3FU)
#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_SHIFT (0U)
/*! CUSTPUBREV - The customer settable PUB version number. */
#define DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_SHIFT)) & DWC_DDRPHYA_DRTUB_CUSTPUBREV_CUSTPUBREV_MASK)
/*! @} */

/*! @name PUBREV - The hardware version of this PUB, excluding the PHY */
/*! @{ */

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_MASK     (0xFU)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_SHIFT    (0U)
/*! PUBMNR - Indicates minor update of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMNR_MASK)

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_MASK     (0xF0U)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_SHIFT    (4U)
/*! PUBMDR - Indicates moderate revision of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMDR_MASK)

#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_MASK     (0xFF00U)
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_SHIFT    (8U)
/*! PUBMJR - Indicates major revision of the PUB. */
#define DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR(x)       (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_SHIFT)) & DWC_DDRPHYA_DRTUB_PUBREV_PUBMJR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DRTUB_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_DRTUB_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_DRTUB_H_ */

