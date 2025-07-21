/*
** ###################################################################
**     Processors:          MCXW727AMFTA_cm33_core0
**                          MCXW727AMFTA_cm33_core1
**                          MCXW727CMFTA_cm33_core0
**                          MCXW727CMFTA_cm33_core1
**                          MCXW727DMFTA_cm33_core0
**                          MCXW727DMFTA_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
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
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
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

#if (defined(CPU_MCXW727AMFTA_cm33_core0))
#include "MCXW727A_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727AMFTA_cm33_core1))
#include "MCXW727A_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core0))
#include "MCXW727C_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core1))
#include "MCXW727C_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core0))
#include "MCXW727D_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core1))
#include "MCXW727D_cm33_core1_COMMON.h"
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

