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
**         CMSIS Peripheral Access Layer for AXI_SWITCH_ASIB
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
 * @file PERI_AXI_SWITCH_ASIB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AXI_SWITCH_ASIB
 *
 * CMSIS Peripheral Access Layer for AXI_SWITCH_ASIB
 */

#if !defined(PERI_AXI_SWITCH_ASIB_H_)
#define PERI_AXI_SWITCH_ASIB_H_                  /**< Symbol preventing repeated inclusion */

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
   -- AXI_SWITCH_ASIB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXI_SWITCH_ASIB_Peripheral_Access_Layer AXI_SWITCH_ASIB Peripheral Access Layer
 * @{
 */

/** AXI_SWITCH_ASIB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t READ_QOS;                          /**< Read channel QoS value, offset: 0x100 */
  __IO uint32_t WRITE_QOS;                         /**< WRITE channel QoS value, offset: 0x104 */
  __IO uint32_t FN_MOD;                            /**< Issuing Functionality Modification, offset: 0x108 */
} AXI_SWITCH_ASIB_Type;

/* ----------------------------------------------------------------------------
   -- AXI_SWITCH_ASIB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AXI_SWITCH_ASIB_Register_Masks AXI_SWITCH_ASIB Register Masks
 * @{
 */

/*! @name READ_QOS - Read channel QoS value */
/*! @{ */

#define AXI_SWITCH_ASIB_READ_QOS_READ_QOS_MASK   (0xFU)
#define AXI_SWITCH_ASIB_READ_QOS_READ_QOS_SHIFT  (0U)
/*! READ_QOS - Read channel QoS value */
#define AXI_SWITCH_ASIB_READ_QOS_READ_QOS(x)     (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_ASIB_READ_QOS_READ_QOS_SHIFT)) & AXI_SWITCH_ASIB_READ_QOS_READ_QOS_MASK)
/*! @} */

/*! @name WRITE_QOS - WRITE channel QoS value */
/*! @{ */

#define AXI_SWITCH_ASIB_WRITE_QOS_WRITE_QOS_MASK (0xFU)
#define AXI_SWITCH_ASIB_WRITE_QOS_WRITE_QOS_SHIFT (0U)
/*! WRITE_QOS - Write channel QoS value */
#define AXI_SWITCH_ASIB_WRITE_QOS_WRITE_QOS(x)   (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_ASIB_WRITE_QOS_WRITE_QOS_SHIFT)) & AXI_SWITCH_ASIB_WRITE_QOS_WRITE_QOS_MASK)
/*! @} */

/*! @name FN_MOD - Issuing Functionality Modification */
/*! @{ */

#define AXI_SWITCH_ASIB_FN_MOD_WRITE_QOS_MASK    (0x3U)
#define AXI_SWITCH_ASIB_FN_MOD_WRITE_QOS_SHIFT   (0U)
/*! WRITE_QOS - Write channel QoS value */
#define AXI_SWITCH_ASIB_FN_MOD_WRITE_QOS(x)      (((uint32_t)(((uint32_t)(x)) << AXI_SWITCH_ASIB_FN_MOD_WRITE_QOS_SHIFT)) & AXI_SWITCH_ASIB_FN_MOD_WRITE_QOS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AXI_SWITCH_ASIB_Register_Masks */


/*!
 * @}
 */ /* end of group AXI_SWITCH_ASIB_Peripheral_Access_Layer */


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


#endif  /* PERI_AXI_SWITCH_ASIB_H_ */

