/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SDA_AP
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
 * @file PERI_SDA_AP.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for SDA_AP
 *
 * CMSIS Peripheral Access Layer for SDA_AP
 */

#if !defined(PERI_SDA_AP_H_)
#define PERI_SDA_AP_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
   -- SDA_AP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDA_AP_Peripheral_Access_Layer SDA_AP Peripheral Access Layer
 * @{
 */

/** SDA_AP - Size of Registers Arrays */
#define SDA_AP_KEYCHAL_COUNT                      8u
#define SDA_AP_KEYRESP_COUNT                      8u

/** SDA_AP - Register Layout Typedef */
typedef struct {
  __I  uint32_t AUTHSTTS;                          /**< Authentication Status, offset: 0x0 */
  __IO uint32_t AUTHCTL;                           /**< Authentication Control, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __I  uint32_t KEYCHAL[SDA_AP_KEYCHAL_COUNT];     /**< Key Challenge, array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[16];
  __IO uint32_t KEYRESP[SDA_AP_KEYRESP_COUNT];     /**< Key Response, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[16];
  __I  uint32_t UID0;                              /**< User Identification 0, offset: 0x70 */
  __I  uint32_t UID1;                              /**< User Identification 1, offset: 0x74 */
       uint8_t RESERVED_3[8];
  __IO uint32_t DBGENCTRL;                         /**< Debug Enable Control, offset: 0x80 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SDAAPRSTCTRL;                      /**< Reset Control, offset: 0x90 */
       uint8_t RESERVED_5[12];
  __I  uint32_t SDAAPGENSTATUS0;                   /**< SDA_AP Generic Status, offset: 0xA0 */
  __IO uint32_t SDAAPGENCTRL0;                     /**< Generic Control 0, offset: 0xA4 */
       uint8_t RESERVED_6[8];
  __I  uint32_t SDAAPGENSTATUS1;                   /**< SDA_AP Generic Status, offset: 0xB0 */
       uint8_t RESERVED_7[12];
  __I  uint32_t SDAAPGENSTATUS2;                   /**< SDA_AP Generic Status, offset: 0xC0 */
       uint8_t RESERVED_8[12];
  __I  uint32_t SDAAPGENSTATUS3;                   /**< SDA_AP Generic Status, offset: 0xD0 */
       uint8_t RESERVED_9[12];
  __I  uint32_t SDAAPGENSTATUS4;                   /**< SDA_AP Generic Status, offset: 0xE0 */
       uint8_t RESERVED_10[24];
  __I  uint32_t ID;                                /**< Identity, offset: 0xFC */
} SDA_AP_Type;

/* ----------------------------------------------------------------------------
   -- SDA_AP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDA_AP_Register_Masks SDA_AP Register Masks
 * @{
 */

/*! @name AUTHSTTS - Authentication Status */
/*! @{ */

#define SDA_AP_AUTHSTTS_CHALRDY_MASK             (0x1U)
#define SDA_AP_AUTHSTTS_CHALRDY_SHIFT            (0U)
/*! CHALRDY - Challenge Ready
 *  0b0..Challenge is not ready
 *  0b1..Challenge is ready
 */
#define SDA_AP_AUTHSTTS_CHALRDY(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_CHALRDY_SHIFT)) & SDA_AP_AUTHSTTS_CHALRDY_MASK)

#define SDA_AP_AUTHSTTS_UIDSTATUS_MASK           (0x4U)
#define SDA_AP_AUTHSTTS_UIDSTATUS_SHIFT          (2U)
/*! UIDSTATUS - User Identification Status
 *  0b0..UID is not ready and is invalid
 *  0b1..UID is ready and is valid
 */
#define SDA_AP_AUTHSTTS_UIDSTATUS(x)             (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_UIDSTATUS_SHIFT)) & SDA_AP_AUTHSTTS_UIDSTATUS_MASK)

#define SDA_AP_AUTHSTTS_SWAPPDBG_MASK            (0x8U)
#define SDA_AP_AUTHSTTS_SWAPPDBG_SHIFT           (3U)
/*! SWAPPDBG - Software Application Debug
 *  0b0..Software application debug disabled
 *  0b1..Software application debug enabled
 */
#define SDA_AP_AUTHSTTS_SWAPPDBG(x)              (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_SWAPPDBG_SHIFT)) & SDA_AP_AUTHSTTS_SWAPPDBG_MASK)

#define SDA_AP_AUTHSTTS_APPDBGEN_MASK            (0x40000000U)
#define SDA_AP_AUTHSTTS_APPDBGEN_SHIFT           (30U)
/*! APPDBGEN - Application Debug Enabled or Disabled
 *  0b0..Application debug disabled
 *  0b1..Application debug enabled
 */
#define SDA_AP_AUTHSTTS_APPDBGEN(x)              (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHSTTS_APPDBGEN_SHIFT)) & SDA_AP_AUTHSTTS_APPDBGEN_MASK)
/*! @} */

/*! @name AUTHCTL - Authentication Control */
/*! @{ */

#define SDA_AP_AUTHCTL_HSEAUTHREQ_MASK           (0x1U)
#define SDA_AP_AUTHCTL_HSEAUTHREQ_SHIFT          (0U)
/*! HSEAUTHREQ - Debug Enablement Authentication Request
 *  0b0..Does not start the authentication request
 *  0b1..Starts the authentication request
 */
#define SDA_AP_AUTHCTL_HSEAUTHREQ(x)             (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHCTL_HSEAUTHREQ_SHIFT)) & SDA_AP_AUTHCTL_HSEAUTHREQ_MASK)

#define SDA_AP_AUTHCTL_HSENEWDATACTL_MASK        (0x2U)
#define SDA_AP_AUTHCTL_HSENEWDATACTL_SHIFT       (1U)
/*! HSENEWDATACTL - New Data Control
 *  0b0..Does not indicate that the debugger has consumed the data registers
 *  0b1..Indicates that the debugger has consumed the data registers
 */
#define SDA_AP_AUTHCTL_HSENEWDATACTL(x)          (((uint32_t)(((uint32_t)(x)) << SDA_AP_AUTHCTL_HSENEWDATACTL_SHIFT)) & SDA_AP_AUTHCTL_HSENEWDATACTL_MASK)
/*! @} */

/*! @name KEYCHAL - Key Challenge */
/*! @{ */

#define SDA_AP_KEYCHAL_KEYCHAL_MASK              (0xFFFFFFFFU)
#define SDA_AP_KEYCHAL_KEYCHAL_SHIFT             (0U)
/*! KEYCHAL - Debug Enablement Key Challenge */
#define SDA_AP_KEYCHAL_KEYCHAL(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYCHAL_KEYCHAL_SHIFT)) & SDA_AP_KEYCHAL_KEYCHAL_MASK)
/*! @} */

/*! @name KEYRESP - Key Response */
/*! @{ */

#define SDA_AP_KEYRESP_KEYRESP_MASK              (0xFFFFFFFFU)
#define SDA_AP_KEYRESP_KEYRESP_SHIFT             (0U)
/*! KEYRESP - Debug Enablement Key Response */
#define SDA_AP_KEYRESP_KEYRESP(x)                (((uint32_t)(((uint32_t)(x)) << SDA_AP_KEYRESP_KEYRESP_SHIFT)) & SDA_AP_KEYRESP_KEYRESP_MASK)
/*! @} */

/*! @name UID0 - User Identification 0 */
/*! @{ */

#define SDA_AP_UID0_UID0_MASK                    (0xFFFFFFFFU)
#define SDA_AP_UID0_UID0_SHIFT                   (0U)
/*! UID0 - User ID 0 */
#define SDA_AP_UID0_UID0(x)                      (((uint32_t)(((uint32_t)(x)) << SDA_AP_UID0_UID0_SHIFT)) & SDA_AP_UID0_UID0_MASK)
/*! @} */

/*! @name UID1 - User Identification 1 */
/*! @{ */

#define SDA_AP_UID1_UID1_MASK                    (0xFFFFFFFFU)
#define SDA_AP_UID1_UID1_SHIFT                   (0U)
/*! UID1 - User ID 1 */
#define SDA_AP_UID1_UID1(x)                      (((uint32_t)(((uint32_t)(x)) << SDA_AP_UID1_UID1_SHIFT)) & SDA_AP_UID1_UID1_MASK)
/*! @} */

/*! @name DBGENCTRL - Debug Enable Control */
/*! @{ */

#define SDA_AP_DBGENCTRL_GDBGEN_MASK             (0x10U)
#define SDA_AP_DBGENCTRL_GDBGEN_SHIFT            (4U)
/*! GDBGEN - Global Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_GDBGEN(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_GDBGEN_SHIFT)) & SDA_AP_DBGENCTRL_GDBGEN_MASK)

#define SDA_AP_DBGENCTRL_GNIDEN_MASK             (0x20U)
#define SDA_AP_DBGENCTRL_GNIDEN_SHIFT            (5U)
/*! GNIDEN - Global Non-Invasive Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_GNIDEN(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_GNIDEN_SHIFT)) & SDA_AP_DBGENCTRL_GNIDEN_MASK)

#define SDA_AP_DBGENCTRL_GSPIDEN_MASK            (0x40U)
#define SDA_AP_DBGENCTRL_GSPIDEN_SHIFT           (6U)
/*! GSPIDEN - Global Secure Privileged Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_GSPIDEN(x)              (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_GSPIDEN_SHIFT)) & SDA_AP_DBGENCTRL_GSPIDEN_MASK)

#define SDA_AP_DBGENCTRL_GSPNIDEN_MASK           (0x80U)
#define SDA_AP_DBGENCTRL_GSPNIDEN_SHIFT          (7U)
/*! GSPNIDEN - Global Secure Privileged Non-Invasive Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_GSPNIDEN(x)             (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_GSPNIDEN_SHIFT)) & SDA_AP_DBGENCTRL_GSPNIDEN_MASK)

#define SDA_AP_DBGENCTRL_CDBGEN_MASK             (0x10000000U)
#define SDA_AP_DBGENCTRL_CDBGEN_SHIFT            (28U)
/*! CDBGEN - Core Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_CDBGEN(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_CDBGEN_SHIFT)) & SDA_AP_DBGENCTRL_CDBGEN_MASK)

#define SDA_AP_DBGENCTRL_CNIDEN_MASK             (0x20000000U)
#define SDA_AP_DBGENCTRL_CNIDEN_SHIFT            (29U)
/*! CNIDEN - Core Non-Invasive Debug Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define SDA_AP_DBGENCTRL_CNIDEN(x)               (((uint32_t)(((uint32_t)(x)) << SDA_AP_DBGENCTRL_CNIDEN_SHIFT)) & SDA_AP_DBGENCTRL_CNIDEN_MASK)
/*! @} */

/*! @name SDAAPRSTCTRL - Reset Control */
/*! @{ */

#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM70_MASK    (0x2000000U)
#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM70_SHIFT   (25U)
/*! RSTRELTLCM70 - Reset Release Cortex-M7_0
 *  0b0..Core is in reset
 *  0b1..Reset is released
 */
#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM70(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPRSTCTRL_RSTRELTLCM70_SHIFT)) & SDA_AP_SDAAPRSTCTRL_RSTRELTLCM70_MASK)

#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM71_MASK    (0x4000000U)
#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM71_SHIFT   (26U)
/*! RSTRELTLCM71 - Reset Release Cortex-M7_1
 *  0b0..Core is in reset
 *  0b1..Reset is released
 */
#define SDA_AP_SDAAPRSTCTRL_RSTRELTLCM71(x)      (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPRSTCTRL_RSTRELTLCM71_SHIFT)) & SDA_AP_SDAAPRSTCTRL_RSTRELTLCM71_MASK)
/*! @} */

/*! @name SDAAPGENSTATUS0 - SDA_AP Generic Status */
/*! @{ */

#define SDA_AP_SDAAPGENSTATUS0_SDAAPGENSTATUS_MASK (0xFFFFFFFFU)
#define SDA_AP_SDAAPGENSTATUS0_SDAAPGENSTATUS_SHIFT (0U)
/*! SDAAPGENSTATUS - DAP Generic Status */
#define SDA_AP_SDAAPGENSTATUS0_SDAAPGENSTATUS(x) (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENSTATUS0_SDAAPGENSTATUS_SHIFT)) & SDA_AP_SDAAPGENSTATUS0_SDAAPGENSTATUS_MASK)
/*! @} */

/*! @name SDAAPGENCTRL0 - Generic Control 0 */
/*! @{ */

#define SDA_AP_SDAAPGENCTRL0_JTAG_CR_EN_MASK     (0x1U)
#define SDA_AP_SDAAPGENCTRL0_JTAG_CR_EN_SHIFT    (0U)
/*! JTAG_CR_EN - JTAG CR Enable
 *  0b0..Function performed on the basis of SWJ-DP mode
 *  0b1..Function performed on the basis of JTAG mode
 */
#define SDA_AP_SDAAPGENCTRL0_JTAG_CR_EN(x)       (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENCTRL0_JTAG_CR_EN_SHIFT)) & SDA_AP_SDAAPGENCTRL0_JTAG_CR_EN_MASK)
/*! @} */

/*! @name SDAAPGENSTATUS1 - SDA_AP Generic Status */
/*! @{ */

#define SDA_AP_SDAAPGENSTATUS1_SDAAPGENSTATUS_MASK (0xFFFFFFFFU)
#define SDA_AP_SDAAPGENSTATUS1_SDAAPGENSTATUS_SHIFT (0U)
/*! SDAAPGENSTATUS - DAP Generic Status */
#define SDA_AP_SDAAPGENSTATUS1_SDAAPGENSTATUS(x) (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENSTATUS1_SDAAPGENSTATUS_SHIFT)) & SDA_AP_SDAAPGENSTATUS1_SDAAPGENSTATUS_MASK)
/*! @} */

/*! @name SDAAPGENSTATUS2 - SDA_AP Generic Status */
/*! @{ */

#define SDA_AP_SDAAPGENSTATUS2_SDAAPGENSTATUS_MASK (0xFFFFFFFFU)
#define SDA_AP_SDAAPGENSTATUS2_SDAAPGENSTATUS_SHIFT (0U)
/*! SDAAPGENSTATUS - DAP Generic Status */
#define SDA_AP_SDAAPGENSTATUS2_SDAAPGENSTATUS(x) (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENSTATUS2_SDAAPGENSTATUS_SHIFT)) & SDA_AP_SDAAPGENSTATUS2_SDAAPGENSTATUS_MASK)
/*! @} */

/*! @name SDAAPGENSTATUS3 - SDA_AP Generic Status */
/*! @{ */

#define SDA_AP_SDAAPGENSTATUS3_SDAAPGENSTATUS_MASK (0xFFFFFFFFU)
#define SDA_AP_SDAAPGENSTATUS3_SDAAPGENSTATUS_SHIFT (0U)
/*! SDAAPGENSTATUS - DAP Generic Status */
#define SDA_AP_SDAAPGENSTATUS3_SDAAPGENSTATUS(x) (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENSTATUS3_SDAAPGENSTATUS_SHIFT)) & SDA_AP_SDAAPGENSTATUS3_SDAAPGENSTATUS_MASK)
/*! @} */

/*! @name SDAAPGENSTATUS4 - SDA_AP Generic Status */
/*! @{ */

#define SDA_AP_SDAAPGENSTATUS4_SDAAPGENSTATUS_MASK (0xFFFFFFFFU)
#define SDA_AP_SDAAPGENSTATUS4_SDAAPGENSTATUS_SHIFT (0U)
/*! SDAAPGENSTATUS - DAP Generic Status */
#define SDA_AP_SDAAPGENSTATUS4_SDAAPGENSTATUS(x) (((uint32_t)(((uint32_t)(x)) << SDA_AP_SDAAPGENSTATUS4_SDAAPGENSTATUS_SHIFT)) & SDA_AP_SDAAPGENSTATUS4_SDAAPGENSTATUS_MASK)
/*! @} */

/*! @name ID - Identity */
/*! @{ */

#define SDA_AP_ID_ID_MASK                        (0xFFFFFFFFU)
#define SDA_AP_ID_ID_SHIFT                       (0U)
/*! ID - Identity */
#define SDA_AP_ID_ID(x)                          (((uint32_t)(((uint32_t)(x)) << SDA_AP_ID_ID_SHIFT)) & SDA_AP_ID_ID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SDA_AP_Register_Masks */


/*!
 * @}
 */ /* end of group SDA_AP_Peripheral_Access_Layer */


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


#endif  /* PERI_SDA_AP_H_ */

