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
**         CMSIS Peripheral Access Layer for NETC_PSEUDO_LINK
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
 * @file PERI_NETC_PSEUDO_LINK.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NETC_PSEUDO_LINK
 *
 * CMSIS Peripheral Access Layer for NETC_PSEUDO_LINK
 */

#if !defined(PERI_NETC_PSEUDO_LINK_H_)
#define PERI_NETC_PSEUDO_LINK_H_                 /**< Symbol preventing repeated inclusion */

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
   -- NETC_PSEUDO_LINK Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PSEUDO_LINK_Peripheral_Access_Layer NETC_PSEUDO_LINK Peripheral Access Layer
 * @{
 */

/** NETC_PSEUDO_LINK - Size of Registers Arrays */
#define NETC_PSEUDO_LINK_PPMROCR_COUNT            2u
#define NETC_PSEUDO_LINK_PPMRUFCR_COUNT           2u
#define NETC_PSEUDO_LINK_PPMRMFCR_COUNT           2u
#define NETC_PSEUDO_LINK_PPMRBFCR_COUNT           2u
#define NETC_PSEUDO_LINK_PPMTOCR_COUNT            2u
#define NETC_PSEUDO_LINK_PPMTUFCR_COUNT           2u
#define NETC_PSEUDO_LINK_PPMTMFCR_COUNT           2u
#define NETC_PSEUDO_LINK_PPMTBFCR_COUNT           2u

/** NETC_PSEUDO_LINK - Register Layout Typedef */
typedef struct {
  __I  uint32_t PPMSR;                             /**< Port pseudo MAC status register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t PPMCR;                             /**< Port pseudo MAC configuration register, offset: 0x10, available only on: ENETC1_PSEUDO_MAC_PORT (missing on SW0_PSEUDO_MAC_PORT4) */
       uint8_t RESERVED_1[108];
  __I  uint32_t PPMROCR[NETC_PSEUDO_LINK_PPMROCR_COUNT]; /**< Port pseudo MAC receive octets counter, array offset: 0x80, array step: 0x4 */
  __I  uint32_t PPMRUFCR[NETC_PSEUDO_LINK_PPMRUFCR_COUNT]; /**< Port pseudo MAC receive unicast frame counter register, array offset: 0x88, array step: 0x4 */
  __I  uint32_t PPMRMFCR[NETC_PSEUDO_LINK_PPMRMFCR_COUNT]; /**< Port pseudo MAC receive multicast frame counter register, array offset: 0x90, array step: 0x4 */
  __I  uint32_t PPMRBFCR[NETC_PSEUDO_LINK_PPMRBFCR_COUNT]; /**< Port pseudo MAC receive broadcast frame counter register, array offset: 0x98, array step: 0x4 */
       uint8_t RESERVED_2[32];
  __I  uint32_t PPMTOCR[NETC_PSEUDO_LINK_PPMTOCR_COUNT]; /**< Port pseudo MAC transmit octets counter, array offset: 0xC0, array step: 0x4 */
  __I  uint32_t PPMTUFCR[NETC_PSEUDO_LINK_PPMTUFCR_COUNT]; /**< Port pseudo MAC transmit unicast frame counter register, array offset: 0xC8, array step: 0x4 */
  __I  uint32_t PPMTMFCR[NETC_PSEUDO_LINK_PPMTMFCR_COUNT]; /**< Port pseudo MAC transmit multicast frame counter register, array offset: 0xD0, array step: 0x4 */
  __I  uint32_t PPMTBFCR[NETC_PSEUDO_LINK_PPMTBFCR_COUNT]; /**< Port pseudo MAC transmit broadcast frame counter register, array offset: 0xD8, array step: 0x4 */
} NETC_PSEUDO_LINK_Type;

/* ----------------------------------------------------------------------------
   -- NETC_PSEUDO_LINK Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_PSEUDO_LINK_Register_Masks NETC_PSEUDO_LINK Register Masks
 * @{
 */

/*! @name PPMSR - Port pseudo MAC status register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMSR_LSTATE_MASK       (0x1U)
#define NETC_PSEUDO_LINK_PPMSR_LSTATE_SHIFT      (0U)
#define NETC_PSEUDO_LINK_PPMSR_LSTATE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMSR_LSTATE_SHIFT)) & NETC_PSEUDO_LINK_PPMSR_LSTATE_MASK)

#define NETC_PSEUDO_LINK_PPMSR_RSTATE_MASK       (0x100U)
#define NETC_PSEUDO_LINK_PPMSR_RSTATE_SHIFT      (8U)
#define NETC_PSEUDO_LINK_PPMSR_RSTATE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMSR_RSTATE_SHIFT)) & NETC_PSEUDO_LINK_PPMSR_RSTATE_MASK)
/*! @} */

/*! @name PPMCR - Port pseudo MAC configuration register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMCR_TXPAD_MASK        (0x10000U)
#define NETC_PSEUDO_LINK_PPMCR_TXPAD_SHIFT       (16U)
/*! TXPAD - Transmit Padding */
#define NETC_PSEUDO_LINK_PPMCR_TXPAD(x)          (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMCR_TXPAD_SHIFT)) & NETC_PSEUDO_LINK_PPMCR_TXPAD_MASK)
/*! @} */

/*! @name PPMROCR - Port pseudo MAC receive octets counter */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMROCR_ROCT_MASK       (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMROCR_ROCT_SHIFT      (0U)
#define NETC_PSEUDO_LINK_PPMROCR_ROCT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMROCR_ROCT_SHIFT)) & NETC_PSEUDO_LINK_PPMROCR_ROCT_MASK)
/*! @} */

/*! @name PPMRUFCR - Port pseudo MAC receive unicast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMRUFCR_RUCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMRUFCR_RUCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMRUFCR_RUCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMRUFCR_RUCA_SHIFT)) & NETC_PSEUDO_LINK_PPMRUFCR_RUCA_MASK)
/*! @} */

/*! @name PPMRMFCR - Port pseudo MAC receive multicast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMRMFCR_RMCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMRMFCR_RMCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMRMFCR_RMCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMRMFCR_RMCA_SHIFT)) & NETC_PSEUDO_LINK_PPMRMFCR_RMCA_MASK)
/*! @} */

/*! @name PPMRBFCR - Port pseudo MAC receive broadcast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMRBFCR_RBCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMRBFCR_RBCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMRBFCR_RBCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMRBFCR_RBCA_SHIFT)) & NETC_PSEUDO_LINK_PPMRBFCR_RBCA_MASK)
/*! @} */

/*! @name PPMTOCR - Port pseudo MAC transmit octets counter */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMTOCR_TOCT_MASK       (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMTOCR_TOCT_SHIFT      (0U)
#define NETC_PSEUDO_LINK_PPMTOCR_TOCT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMTOCR_TOCT_SHIFT)) & NETC_PSEUDO_LINK_PPMTOCR_TOCT_MASK)
/*! @} */

/*! @name PPMTUFCR - Port pseudo MAC transmit unicast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMTUFCR_TUCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMTUFCR_TUCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMTUFCR_TUCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMTUFCR_TUCA_SHIFT)) & NETC_PSEUDO_LINK_PPMTUFCR_TUCA_MASK)
/*! @} */

/*! @name PPMTMFCR - Port pseudo MAC transmit multicast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMTMFCR_TMCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMTMFCR_TMCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMTMFCR_TMCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMTMFCR_TMCA_SHIFT)) & NETC_PSEUDO_LINK_PPMTMFCR_TMCA_MASK)
/*! @} */

/*! @name PPMTBFCR - Port pseudo MAC transmit broadcast frame counter register */
/*! @{ */

#define NETC_PSEUDO_LINK_PPMTBFCR_TBCA_MASK      (0xFFFFFFFFU)
#define NETC_PSEUDO_LINK_PPMTBFCR_TBCA_SHIFT     (0U)
#define NETC_PSEUDO_LINK_PPMTBFCR_TBCA(x)        (((uint32_t)(((uint32_t)(x)) << NETC_PSEUDO_LINK_PPMTBFCR_TBCA_SHIFT)) & NETC_PSEUDO_LINK_PPMTBFCR_TBCA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_PSEUDO_LINK_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_PSEUDO_LINK_Peripheral_Access_Layer */


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


#endif  /* PERI_NETC_PSEUDO_LINK_H_ */

