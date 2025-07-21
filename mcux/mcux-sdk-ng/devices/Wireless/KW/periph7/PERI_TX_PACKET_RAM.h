/*
** ###################################################################
**     Processors:          KW45B41Z52AFPA
**                          KW45B41Z52AFTA
**                          KW45B41Z53AFPA
**                          KW45B41Z53AFTA
**                          KW45B41Z82AFPA
**                          KW45B41Z82AFTA
**                          KW45B41Z83AFPA
**                          KW45B41Z83AFPA_NBU
**                          KW45B41Z83AFTA
**                          KW45B41Z83AFTA_NBU
**                          KW45Z41052AFPA
**                          KW45Z41052AFTA
**                          KW45Z41053AFPA
**                          KW45Z41053AFTA
**                          KW45Z41082AFPA
**                          KW45Z41082AFTA
**                          KW45Z41083AFPA
**                          KW45Z41083AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TX_PACKET_RAM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-12)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TX_PACKET_RAM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TX_PACKET_RAM
 *
 * CMSIS Peripheral Access Layer for TX_PACKET_RAM
 */

#if !defined(PERI_TX_PACKET_RAM_H_)
#define PERI_TX_PACKET_RAM_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW45B41Z52AFPA) || defined(CPU_KW45B41Z52AFTA))
#include "KW45B41Z52_COMMON.h"
#elif (defined(CPU_KW45B41Z53AFPA) || defined(CPU_KW45B41Z53AFTA))
#include "KW45B41Z53_COMMON.h"
#elif (defined(CPU_KW45B41Z82AFPA) || defined(CPU_KW45B41Z82AFTA))
#include "KW45B41Z82_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA) || defined(CPU_KW45B41Z83AFTA))
#include "KW45B41Z83_COMMON.h"
#elif (defined(CPU_KW45B41Z83AFPA_NBU) || defined(CPU_KW45B41Z83AFTA_NBU))
#include "KW45B41Z83_NBU_COMMON.h"
#elif (defined(CPU_KW45Z41052AFPA) || defined(CPU_KW45Z41052AFTA))
#include "KW45Z41052_COMMON.h"
#elif (defined(CPU_KW45Z41053AFPA) || defined(CPU_KW45Z41053AFTA))
#include "KW45Z41053_COMMON.h"
#elif (defined(CPU_KW45Z41082AFPA) || defined(CPU_KW45Z41082AFTA))
#include "KW45Z41082_COMMON.h"
#elif (defined(CPU_KW45Z41083AFPA) || defined(CPU_KW45Z41083AFTA))
#include "KW45Z41083_COMMON.h"
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
   -- TX_PACKET_RAM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TX_PACKET_RAM_Peripheral_Access_Layer TX_PACKET_RAM Peripheral Access Layer
 * @{
 */

/** TX_PACKET_RAM - Size of Registers Arrays */
#define TX_PACKET_RAM_PACKET_RAM_COUNT            1024u

/** TX_PACKET_RAM - Register Layout Typedef */
typedef struct {
  __IO uint32_t PACKET_RAM[TX_PACKET_RAM_PACKET_RAM_COUNT]; /**< Shared Packet RAM for multiple Link Layer usage., array offset: 0x0, array step: 0x4 */
} TX_PACKET_RAM_Type;

/* ----------------------------------------------------------------------------
   -- TX_PACKET_RAM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TX_PACKET_RAM_Register_Masks TX_PACKET_RAM Register Masks
 * @{
 */

/*! @name PACKET_RAM - Shared Packet RAM for multiple Link Layer usage. */
/*! @{ */

#define TX_PACKET_RAM_PACKET_RAM_RAM_MASK        (0xFFFFFFFFU)
#define TX_PACKET_RAM_PACKET_RAM_RAM_SHIFT       (0U)
/*! RAM - One entry in the packet RAM */
#define TX_PACKET_RAM_PACKET_RAM_RAM(x)          (((uint32_t)(((uint32_t)(x)) << TX_PACKET_RAM_PACKET_RAM_RAM_SHIFT)) & TX_PACKET_RAM_PACKET_RAM_RAM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TX_PACKET_RAM_Register_Masks */


/*!
 * @}
 */ /* end of group TX_PACKET_RAM_Peripheral_Access_Layer */


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


#endif  /* PERI_TX_PACKET_RAM_H_ */

