/*
** ###################################################################
**     Processors:          MCXE317MPA
**                          MCXE317MPB
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MDM_AP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_MDM_AP.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for MDM_AP
 *
 * CMSIS Peripheral Access Layer for MDM_AP
 */

#if !defined(PERI_MDM_AP_H_)
#define PERI_MDM_AP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE317MPA) || defined(CPU_MCXE317MPB))
#include "MCXE317_COMMON.h"
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
   -- MDM_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Peripheral_Access_Layer MDM_AP Peripheral Access Layer
 * @{
 */

/** MDM_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t MDMAPSTTS;                         /**< Status, offset: 0x0 */
  __IO uint32_t MDMAPCTL;                          /**< Control, offset: 0x4 */
       uint8_t RESERVED_0[40];
  __IO uint32_t MDMAPWIREN;                        /**< WIR Enable, offset: 0x30 */
  __I  uint32_t MDMAPWIRSTTS;                      /**< WIR Status, offset: 0x34 */
  __IO uint32_t MDMAPWIRREL;                       /**< WIR Release, offset: 0x38 */
       uint8_t RESERVED_1[192];
  __I  uint32_t ID;                                /**< Identity, offset: 0xFC */
} MDM_AP_Type;

/* ----------------------------------------------------------------------------
   -- MDM_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MDM_AP_Register_Masks MDM_AP Register Masks
 * @{
 */

/*! @name MDMAPSTTS - Status */
/*! @{ */

#define MDM_AP_MDMAPSTTS_DESTRST_MASK            (0x2U)
#define MDM_AP_MDMAPSTTS_DESTRST_SHIFT           (1U)
/*! DESTRST - Destructive Reset
 *  0b0..Not in destructive reset
 *  0b1..In destructive reset
 */
#define MDM_AP_MDMAPSTTS_DESTRST(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_DESTRST_SHIFT)) & MDM_AP_MDMAPSTTS_DESTRST_MASK)

#define MDM_AP_MDMAPSTTS_FUNCRST_MASK            (0x4U)
#define MDM_AP_MDMAPSTTS_FUNCRST_SHIFT           (2U)
/*! FUNCRST - Functional Reset
 *  0b0..Not in functional reset
 *  0b1..In functional reset
 */
#define MDM_AP_MDMAPSTTS_FUNCRST(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_FUNCRST_SHIFT)) & MDM_AP_MDMAPSTTS_FUNCRST_MASK)

#define MDM_AP_MDMAPSTTS_CM70HLT_MASK            (0x1000U)
#define MDM_AP_MDMAPSTTS_CM70HLT_SHIFT           (12U)
/*! CM70HLT - Cortex-M7_0 Halted
 *  0b0..Core is not halted
 *  0b1..Core is halted
 */
#define MDM_AP_MDMAPSTTS_CM70HLT(x)              (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70HLT_SHIFT)) & MDM_AP_MDMAPSTTS_CM70HLT_MASK)

#define MDM_AP_MDMAPSTTS_CM70DPSLP_MASK          (0x10000U)
#define MDM_AP_MDMAPSTTS_CM70DPSLP_SHIFT         (16U)
/*! CM70DPSLP - Cortex-M7_0 Deep Sleep
 *  0b0..Not in Deep Sleep mode
 *  0b1..In Deep Sleep mode
 */
#define MDM_AP_MDMAPSTTS_CM70DPSLP(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70DPSLP_SHIFT)) & MDM_AP_MDMAPSTTS_CM70DPSLP_MASK)

#define MDM_AP_MDMAPSTTS_CM70SLPNG_MASK          (0x100000U)
#define MDM_AP_MDMAPSTTS_CM70SLPNG_SHIFT         (20U)
/*! CM70SLPNG - Cortex-M7_0 Sleeping
 *  0b0..Not in Sleep mode
 *  0b1..In Sleep mode
 */
#define MDM_AP_MDMAPSTTS_CM70SLPNG(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70SLPNG_SHIFT)) & MDM_AP_MDMAPSTTS_CM70SLPNG_MASK)

#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD_MASK       (0x10000000U)
#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD_SHIFT      (28U)
/*! CM70DBGRSTRD - Cortex-M7_0 Debug Restarted
 *  0b0..In Debug mode
 *  0b1..In Normal mode
 */
#define MDM_AP_MDMAPSTTS_CM70DBGRSTRD(x)         (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPSTTS_CM70DBGRSTRD_SHIFT)) & MDM_AP_MDMAPSTTS_CM70DBGRSTRD_MASK)
/*! @} */

/*! @name MDMAPCTL - Control */
/*! @{ */

#define MDM_AP_MDMAPCTL_SYSRESETREQ_MASK         (0x10U)
#define MDM_AP_MDMAPCTL_SYSRESETREQ_SHIFT        (4U)
/*! SYSRESETREQ - System Destructive Reset
 *  0b0..Deasserted
 *  0b1..Asserted
 */
#define MDM_AP_MDMAPCTL_SYSRESETREQ(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SYSRESETREQ_SHIFT)) & MDM_AP_MDMAPCTL_SYSRESETREQ_MASK)

#define MDM_AP_MDMAPCTL_SYSFUNCRST_MASK          (0x20U)
#define MDM_AP_MDMAPCTL_SYSFUNCRST_SHIFT         (5U)
/*! SYSFUNCRST - System Functional Reset
 *  0b0..Deasserted
 *  0b1..Asserted
 */
#define MDM_AP_MDMAPCTL_SYSFUNCRST(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SYSFUNCRST_SHIFT)) & MDM_AP_MDMAPCTL_SYSFUNCRST_MASK)

#define MDM_AP_MDMAPCTL_CM70DBGREQ_MASK          (0x100U)
#define MDM_AP_MDMAPCTL_CM70DBGREQ_SHIFT         (8U)
/*! CM70DBGREQ - Cortex-M7_0 Debug Request
 *  0b0..Debug request is not generated
 *  0b1..Debug request is generated
 */
#define MDM_AP_MDMAPCTL_CM70DBGREQ(x)            (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM70DBGREQ_SHIFT)) & MDM_AP_MDMAPCTL_CM70DBGREQ_MASK)

#define MDM_AP_MDMAPCTL_POR_WDG_DIS_MASK         (0x8000U)
#define MDM_AP_MDMAPCTL_POR_WDG_DIS_SHIFT        (15U)
/*! POR_WDG_DIS - Power Watchdog Status
 *  0b0..Power watchdog is disabled
 *  0b1..Power watchdog is enabled
 */
#define MDM_AP_MDMAPCTL_POR_WDG_DIS(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_POR_WDG_DIS_SHIFT)) & MDM_AP_MDMAPCTL_POR_WDG_DIS_MASK)

#define MDM_AP_MDMAPCTL_SWOOVRD_MASK             (0x400000U)
#define MDM_AP_MDMAPCTL_SWOOVRD_SHIFT            (22U)
/*! SWOOVRD - SWO Override
 *  0b0..Not overridden, and SWO generates the trace response
 *  0b1..Is overridden
 */
#define MDM_AP_MDMAPCTL_SWOOVRD(x)               (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_SWOOVRD_SHIFT)) & MDM_AP_MDMAPCTL_SWOOVRD_MASK)

#define MDM_AP_MDMAPCTL_CM70DBGRSRT_MASK         (0x10000000U)
#define MDM_AP_MDMAPCTL_CM70DBGRSRT_SHIFT        (28U)
/*! CM70DBGRSRT - Cortex-M7_0 Debug Restart
 *  0b0..Normal operation
 *  0b1..Request asserted
 */
#define MDM_AP_MDMAPCTL_CM70DBGRSRT(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPCTL_CM70DBGRSRT_SHIFT)) & MDM_AP_MDMAPCTL_CM70DBGRSRT_MASK)
/*! @} */

/*! @name MDMAPWIREN - WIR Enable */
/*! @{ */

#define MDM_AP_MDMAPWIREN_LWPWREN_MASK           (0x1U)
#define MDM_AP_MDMAPWIREN_LWPWREN_SHIFT          (0U)
/*! LWPWREN - Low Power Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define MDM_AP_MDMAPWIREN_LWPWREN(x)             (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIREN_LWPWREN_SHIFT)) & MDM_AP_MDMAPWIREN_LWPWREN_MASK)
/*! @} */

/*! @name MDMAPWIRSTTS - WIR Status */
/*! @{ */

#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_MASK (0xFFFFFFFFU)
#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_SHIFT (0U)
/*! MDM_DAP_WIR_STATUS - MDM_AP WIR Status */
#define MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_SHIFT)) & MDM_AP_MDMAPWIRSTTS_MDM_DAP_WIR_STATUS_MASK)
/*! @} */

/*! @name MDMAPWIRREL - WIR Release */
/*! @{ */

#define MDM_AP_MDMAPWIRREL_WTRSTRGM_MASK         (0x1U)
#define MDM_AP_MDMAPWIRREL_WTRSTRGM_SHIFT        (0U)
/*! WTRSTRGM - Wait In Reset B
 *  0b0..Normal operation
 *  0b1..Wait supported
 */
#define MDM_AP_MDMAPWIRREL_WTRSTRGM(x)           (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRREL_WTRSTRGM_SHIFT)) & MDM_AP_MDMAPWIRREL_WTRSTRGM_MASK)

#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_MASK      (0x2U)
#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_SHIFT     (1U)
/*! PRVNTRSTRGM - Prevent Reset
 *  0b0..Normal operation
 *  0b1..MC_RGM prevented
 */
#define MDM_AP_MDMAPWIRREL_PRVNTRSTRGM(x)        (((uint32_t)(((uint32_t)(x)) << MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_SHIFT)) & MDM_AP_MDMAPWIRREL_PRVNTRSTRGM_MASK)
/*! @} */

/*! @name ID - Identity */
/*! @{ */

#define MDM_AP_ID_ID_MASK                        (0xFFFFFFFFU)
#define MDM_AP_ID_ID_SHIFT                       (0U)
/*! ID - Identity */
#define MDM_AP_ID_ID(x)                          (((uint32_t)(((uint32_t)(x)) << MDM_AP_ID_ID_SHIFT)) & MDM_AP_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MDM_AP_Register_Masks */


/*!
 * @}
 */ /* end of group MDM_AP_Peripheral_Access_Layer */


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


#endif  /* PERI_MDM_AP_H_ */

