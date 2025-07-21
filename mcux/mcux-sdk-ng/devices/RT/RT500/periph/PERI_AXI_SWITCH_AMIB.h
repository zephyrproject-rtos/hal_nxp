/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AXI_SWITCH_AMIB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AXI_SWITCH_AMIB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AXI_SWITCH_AMIB
 *
 * CMSIS Peripheral Access Layer for AXI_SWITCH_AMIB
 */

#if !defined(PERI_AXI_SWITCH_AMIB_H_)
#define PERI_AXI_SWITCH_AMIB_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- AXI_SWITCH_AMIB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXI_SWITCH_AMIB_Peripheral_Access_Layer AXI_SWITCH_AMIB Peripheral Access Layer
 * @{
 */

/** AXI_SWITCH_AMIB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t FN_MOD_BM_ISS;                     /**< Bus Matrix Issuing Functionality Modification., offset: 0x8 */
       uint8_t RESERVED_1[24];
  __IO uint32_t FN_MOD2;                           /**< Bypass Merge, offset: 0x24 */
       uint8_t RESERVED_2[224];
  __IO uint32_t FN_MOD;                            /**< Issuing Functionality Modification, offset: 0x108 */
} AXI_SWITCH_AMIB_Type;

/* ----------------------------------------------------------------------------
   -- AXI_SWITCH_AMIB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXI_SWITCH_AMIB_Register_Masks AXI_SWITCH_AMIB Register Masks
 * @{
 */

/*! @name FN_MOD_BM_ISS - Bus Matrix Issuing Functionality Modification. */
/*! @{ */

#define AXI_SWITCH_AMIB_FN_MOD_BM_ISS_FN_MOD_BM_ISS_MASK (0x3U)
#define AXI_SWITCH_AMIB_FN_MOD_BM_ISS_FN_MOD_BM_ISS_SHIFT (0U)
/*! FN_MOD_BM_ISS - Read channel QoS value */
#define AXI_SWITCH_AMIB_FN_MOD_BM_ISS_FN_MOD_BM_ISS(x) (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_AMIB_FN_MOD_BM_ISS_FN_MOD_BM_ISS_SHIFT)) & AXI_SWITCH_AMIB_FN_MOD_BM_ISS_FN_MOD_BM_ISS_MASK)
/*! @} */

/*! @name FN_MOD2 - Bypass Merge */
/*! @{ */

#define AXI_SWITCH_AMIB_FN_MOD2_FN_MOD2_MASK     (0x1U)
#define AXI_SWITCH_AMIB_FN_MOD2_FN_MOD2_SHIFT    (0U)
/*! FN_MOD2 - Bypass Merge */
#define AXI_SWITCH_AMIB_FN_MOD2_FN_MOD2(x)       (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_AMIB_FN_MOD2_FN_MOD2_SHIFT)) & AXI_SWITCH_AMIB_FN_MOD2_FN_MOD2_MASK)
/*! @} */

/*! @name FN_MOD - Issuing Functionality Modification */
/*! @{ */

#define AXI_SWITCH_AMIB_FN_MOD_FN_MOD_MASK       (0x3U)
#define AXI_SWITCH_AMIB_FN_MOD_FN_MOD_SHIFT      (0U)
/*! FN_MOD - Bypass Merge */
#define AXI_SWITCH_AMIB_FN_MOD_FN_MOD(x)         (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_AMIB_FN_MOD_FN_MOD_SHIFT)) & AXI_SWITCH_AMIB_FN_MOD_FN_MOD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AXI_SWITCH_AMIB_Register_Masks */


/*!
 * @}
 */ /* end of group AXI_SWITCH_AMIB_Peripheral_Access_Layer */


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


#endif  /* PERI_AXI_SWITCH_AMIB_H_ */

