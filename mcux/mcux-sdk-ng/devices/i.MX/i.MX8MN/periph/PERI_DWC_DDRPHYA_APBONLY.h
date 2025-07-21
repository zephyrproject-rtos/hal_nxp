/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_APBONLY
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_APBONLY.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_APBONLY
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_APBONLY
 */

#if !defined(PERI_DWC_DDRPHYA_APBONLY_H_)
#define PERI_DWC_DDRPHYA_APBONLY_H_              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- DWC_DDRPHYA_APBONLY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_APBONLY_Peripheral_Access_Layer DWC_DDRPHYA_APBONLY Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_APBONLY - Register Layout Typedef */
typedef struct {
  __IO uint16_t MICROCONTMUXSEL;                   /**< PMU Config Mux Select, offset: 0x0 */
       uint8_t RESERVED_0[6];
  __I  uint16_t UCTSHADOWREGS;                     /**< PMU/Controller Protocol - Controller Read-only Shadow, offset: 0x8 */
       uint8_t RESERVED_1[86];
  __IO uint16_t DCTWRITEONLY;                      /**< Reserved for future use., offset: 0x60 */
  __IO uint16_t DCTWRITEPROT;                      /**< DCT downstream mailbox protocol CSR., offset: 0x62 */
  __I  uint16_t UCTWRITEONLYSHADOW;                /**< Read-only view of the csr UctDatWriteOnly, offset: 0x64 */
       uint8_t RESERVED_2[2];
  __I  uint16_t UCTDATWRITEONLYSHADOW;             /**< Read-only view of the csr UctDatWriteOnly, offset: 0x68 */
       uint8_t RESERVED_3[4];
  __IO uint16_t DFICFGRDDATAVALIDTICKS;            /**< Number of DfiClk ticks required for valid csr Rd Data., offset: 0x6E */
       uint8_t RESERVED_4[194];
  __IO uint16_t MICRORESET;                        /**< Controls reset and clock shutdown on the local microcontroller, offset: 0x132 */
       uint8_t RESERVED_5[192];
  __I  uint16_t DFIINITCOMPLETESHADOW;             /**< dfi_init_complete - Controller Read-only Shadow, offset: 0x1F4 */
} DWC_DDRPHYA_APBONLY_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_APBONLY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_APBONLY_Register_Masks DWC_DDRPHYA_APBONLY Register Masks
 * @{
 */

/*! @name MICROCONTMUXSEL - PMU Config Mux Select */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MicroContMuxSel_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MicroContMuxSel_SHIFT (0U)
/*! MicroContMuxSel - This register controls access to the PHY configuration registers. */
#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MicroContMuxSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MicroContMuxSel_SHIFT)) & DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MicroContMuxSel_MASK)
/*! @} */

/*! @name UCTSHADOWREGS - PMU/Controller Protocol - Controller Read-only Shadow */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctWriteProtShadow_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctWriteProtShadow_SHIFT (0U)
/*! UctWriteProtShadow - When set to 0, the PMU has a message for the user */
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctWriteProtShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctWriteProtShadow_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctWriteProtShadow_MASK)

#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctDatWriteProtShadow_MASK (0x2U)
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctDatWriteProtShadow_SHIFT (1U)
/*! UctDatWriteProtShadow - Reserved for future use. */
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctDatWriteProtShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctDatWriteProtShadow_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UctDatWriteProtShadow_MASK)
/*! @} */

/*! @name DCTWRITEONLY - Reserved for future use. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DctWriteOnly_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DctWriteOnly_SHIFT (0U)
/*! DctWriteOnly - Reserved for future use. */
#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DctWriteOnly(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DctWriteOnly_SHIFT)) & DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DctWriteOnly_MASK)
/*! @} */

/*! @name DCTWRITEPROT - DCT downstream mailbox protocol CSR. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DctWriteProt_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DctWriteProt_SHIFT (0U)
/*! DctWriteProt - By setting this register to 0, the user acknowledges the receipt of the message. */
#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DctWriteProt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DctWriteProt_SHIFT)) & DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DctWriteProt_MASK)
/*! @} */

/*! @name UCTWRITEONLYSHADOW - Read-only view of the csr UctDatWriteOnly */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UctWriteOnlyShadow_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UctWriteOnlyShadow_SHIFT (0U)
/*! UctWriteOnlyShadow - Used to pass the message ID for major messages. */
#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UctWriteOnlyShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UctWriteOnlyShadow_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UctWriteOnlyShadow_MASK)
/*! @} */

/*! @name UCTDATWRITEONLYSHADOW - Read-only view of the csr UctDatWriteOnly */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UctDatWriteOnlyShadow_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UctDatWriteOnlyShadow_SHIFT (0U)
/*! UctDatWriteOnlyShadow - Used to pass the upper 16 bits for streaming messages. */
#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UctDatWriteOnlyShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UctDatWriteOnlyShadow_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UctDatWriteOnlyShadow_MASK)
/*! @} */

/*! @name DFICFGRDDATAVALIDTICKS - Number of DfiClk ticks required for valid csr Rd Data. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DfiCfgRdDataValidTicks_MASK (0x3FU)
#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DfiCfgRdDataValidTicks_SHIFT (0U)
/*! DfiCfgRdDataValidTicks - Roundtrip delay of a register read access. */
#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DfiCfgRdDataValidTicks(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DfiCfgRdDataValidTicks_SHIFT)) & DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DfiCfgRdDataValidTicks_MASK)
/*! @} */

/*! @name MICRORESET - Controls reset and clock shutdown on the local microcontroller */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_MICRORESET_StallToMicro_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_StallToMicro_SHIFT (0U)
/*! StallToMicro - Set this bit to stall the microcontroller by hardware. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_StallToMicro(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_StallToMicro_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_StallToMicro_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_TestWakeup_MASK (0x2U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_TestWakeup_SHIFT (1U)
/*! TestWakeup - Reserved. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_TestWakeup(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_TestWakeup_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_TestWakeup_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMicro_MASK (0x4U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMicro_SHIFT (2U)
/*! RSVDMicro - RSVD */
#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMicro(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMicro_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMicro_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_ResetToMicro_MASK (0x8U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_ResetToMicro_SHIFT (3U)
/*! ResetToMicro - Set this bit to apply synchronous reset to the microcontroller. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_ResetToMicro(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_ResetToMicro_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_ResetToMicro_MASK)
/*! @} */

/*! @name DFIINITCOMPLETESHADOW - dfi_init_complete - Controller Read-only Shadow */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DfiInitCompleteShadow_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DfiInitCompleteShadow_SHIFT (0U)
/*! DfiInitCompleteShadow - This csr presents a read-only view (a shadow) of the Register
 *    DfiInitComplete which is used by the sequencer to control the state of dfi_init_complete.
 */
#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DfiInitCompleteShadow(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DfiInitCompleteShadow_SHIFT)) & DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DfiInitCompleteShadow_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_APBONLY_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_APBONLY_Peripheral_Access_Layer */


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


#endif  /* PERI_DWC_DDRPHYA_APBONLY_H_ */

