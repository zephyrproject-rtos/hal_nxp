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
 * @file PERI_DWC_DDRPHYA_APBONLY.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_APBONLY
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_APBONLY
 */

#if !defined(PERI_DWC_DDRPHYA_APBONLY_H_)
#define PERI_DWC_DDRPHYA_APBONLY_H_              /**< Symbol preventing repeated inclusion */

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

#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MICROCONTMUXSEL_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MICROCONTMUXSEL_SHIFT (0U)
/*! MicroContMuxSel - This register controls access to the PHY configuration registers. */
#define DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MICROCONTMUXSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MICROCONTMUXSEL_SHIFT)) & DWC_DDRPHYA_APBONLY_MICROCONTMUXSEL_MICROCONTMUXSEL_MASK)
/*! @} */

/*! @name UCTSHADOWREGS - PMU/Controller Protocol - Controller Read-only Shadow */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTWRITEPROTSHADOW_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTWRITEPROTSHADOW_SHIFT (0U)
/*! UctWriteProtShadow - When set to 0, the PMU has a message for the user */
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTWRITEPROTSHADOW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTWRITEPROTSHADOW_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTWRITEPROTSHADOW_MASK)

#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW_MASK (0x2U)
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW_SHIFT (1U)
/*! UctDatWriteProtShadow - Reserved for future use. */
#define DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTSHADOWREGS_UCTDATWRITEPROTSHADOW_MASK)
/*! @} */

/*! @name DCTWRITEONLY - Reserved for future use. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DCTWRITEONLY_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DCTWRITEONLY_SHIFT (0U)
/*! DctWriteOnly - Reserved for future use. */
#define DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DCTWRITEONLY(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DCTWRITEONLY_SHIFT)) & DWC_DDRPHYA_APBONLY_DCTWRITEONLY_DCTWRITEONLY_MASK)
/*! @} */

/*! @name DCTWRITEPROT - DCT downstream mailbox protocol CSR. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DCTWRITEPROT_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DCTWRITEPROT_SHIFT (0U)
/*! DctWriteProt - By setting this register to 0, the user acknowledges the receipt of the message. */
#define DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DCTWRITEPROT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DCTWRITEPROT_SHIFT)) & DWC_DDRPHYA_APBONLY_DCTWRITEPROT_DCTWRITEPROT_MASK)
/*! @} */

/*! @name UCTWRITEONLYSHADOW - Read-only view of the csr UctDatWriteOnly */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW_SHIFT (0U)
/*! UctWriteOnlyShadow - Used to pass the message ID for major messages. */
#define DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTWRITEONLYSHADOW_UCTWRITEONLYSHADOW_MASK)
/*! @} */

/*! @name UCTDATWRITEONLYSHADOW - Read-only view of the csr UctDatWriteOnly */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW_MASK (0xFFFFU)
#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW_SHIFT (0U)
/*! UctDatWriteOnlyShadow - Used to pass the upper 16 bits for streaming messages. */
#define DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW_SHIFT)) & DWC_DDRPHYA_APBONLY_UCTDATWRITEONLYSHADOW_UCTDATWRITEONLYSHADOW_MASK)
/*! @} */

/*! @name DFICFGRDDATAVALIDTICKS - Number of DfiClk ticks required for valid csr Rd Data. */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKS_MASK (0x3FU)
#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKS_SHIFT (0U)
/*! DfiCfgRdDataValidTicks - Roundtrip delay of a register read access. */
#define DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKS(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKS_SHIFT)) & DWC_DDRPHYA_APBONLY_DFICFGRDDATAVALIDTICKS_DFICFGRDDATAVALIDTICKS_MASK)
/*! @} */

/*! @name MICRORESET - Controls reset and clock shutdown on the local microcontroller */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_MICRORESET_STALLTOMICRO_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_STALLTOMICRO_SHIFT (0U)
/*! StallToMicro - Set this bit to stall the microcontroller by hardware. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_STALLTOMICRO(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_STALLTOMICRO_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_STALLTOMICRO_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_TESTWAKEUP_MASK (0x2U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_TESTWAKEUP_SHIFT (1U)
/*! TestWakeup - Reserved. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_TESTWAKEUP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_TESTWAKEUP_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_TESTWAKEUP_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMICRO_MASK (0x4U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMICRO_SHIFT (2U)
/*! RSVDMicro - RSVD */
#define DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMICRO(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMICRO_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_RSVDMICRO_MASK)

#define DWC_DDRPHYA_APBONLY_MICRORESET_RESETTOMICRO_MASK (0x8U)
#define DWC_DDRPHYA_APBONLY_MICRORESET_RESETTOMICRO_SHIFT (3U)
/*! ResetToMicro - Set this bit to apply synchronous reset to the microcontroller. */
#define DWC_DDRPHYA_APBONLY_MICRORESET_RESETTOMICRO(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_MICRORESET_RESETTOMICRO_SHIFT)) & DWC_DDRPHYA_APBONLY_MICRORESET_RESETTOMICRO_MASK)
/*! @} */

/*! @name DFIINITCOMPLETESHADOW - dfi_init_complete - Controller Read-only Shadow */
/*! @{ */

#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW_MASK (0x1U)
#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW_SHIFT (0U)
/*! DfiInitCompleteShadow - This csr presents a read-only view (a shadow) of the Register
 *    DfiInitComplete which is used by the sequencer to control the state of dfi_init_complete.
 */
#define DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW_SHIFT)) & DWC_DDRPHYA_APBONLY_DFIINITCOMPLETESHADOW_DFIINITCOMPLETESHADOW_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DWC_DDRPHYA_APBONLY_H_ */

