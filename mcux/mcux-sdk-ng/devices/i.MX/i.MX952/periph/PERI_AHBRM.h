/*
** ###################################################################
**     Processors:          MIMX9522xxVTx_ca55
**                          MIMX9522xxVTx_cm33
**                          MIMX9522xxVTx_cm7
**                          MIMX9522xxVZx_ca55
**                          MIMX9522xxVZx_cm33
**                          MIMX9522xxVZx_cm7
**                          MIMX9523xxVTx_ca55
**                          MIMX9523xxVTx_cm33
**                          MIMX9523xxVTx_cm7
**                          MIMX9523xxVZx_ca55
**                          MIMX9523xxVZx_cm33
**                          MIMX9523xxVZx_cm7
**                          MIMX9524xxVTx_ca55
**                          MIMX9524xxVTx_cm33
**                          MIMX9524xxVTx_cm7
**                          MIMX9524xxVZx_ca55
**                          MIMX9524xxVZx_cm33
**                          MIMX9524xxVZx_cm7
**                          MIMX9525xxVTx_ca55
**                          MIMX9525xxVTx_cm33
**                          MIMX9525xxVTx_cm7
**                          MIMX9525xxVZx_ca55
**                          MIMX9525xxVZx_cm33
**                          MIMX9525xxVZx_cm7
**                          MIMX9528xxVTx_ca55
**                          MIMX9528xxVTx_cm33
**                          MIMX9528xxVTx_cm7
**                          MIMX9528xxVZx_ca55
**                          MIMX9528xxVZx_cm33
**                          MIMX9528xxVZx_cm7
**                          MIMX9529xxVTx_ca55
**                          MIMX9529xxVTx_cm33
**                          MIMX9529xxVTx_cm7
**                          MIMX9529xxVZx_ca55
**                          MIMX9529xxVZx_cm33
**                          MIMX9529xxVZx_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b260416
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHBRM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AHBRM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHBRM
 *
 * CMSIS Peripheral Access Layer for AHBRM
 */

#if !defined(PERI_AHBRM_H_)
#define PERI_AHBRM_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9522xxVTx_ca55) || defined(CPU_MIMX9522xxVZx_ca55))
#include "MIMX9522_ca55_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm33) || defined(CPU_MIMX9522xxVZx_cm33))
#include "MIMX9522_cm33_COMMON.h"
#elif (defined(CPU_MIMX9522xxVTx_cm7) || defined(CPU_MIMX9522xxVZx_cm7))
#include "MIMX9522_cm7_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_ca55) || defined(CPU_MIMX9523xxVZx_ca55))
#include "MIMX9523_ca55_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm33) || defined(CPU_MIMX9523xxVZx_cm33))
#include "MIMX9523_cm33_COMMON.h"
#elif (defined(CPU_MIMX9523xxVTx_cm7) || defined(CPU_MIMX9523xxVZx_cm7))
#include "MIMX9523_cm7_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_ca55) || defined(CPU_MIMX9524xxVZx_ca55))
#include "MIMX9524_ca55_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm33) || defined(CPU_MIMX9524xxVZx_cm33))
#include "MIMX9524_cm33_COMMON.h"
#elif (defined(CPU_MIMX9524xxVTx_cm7) || defined(CPU_MIMX9524xxVZx_cm7))
#include "MIMX9524_cm7_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_ca55) || defined(CPU_MIMX9525xxVZx_ca55))
#include "MIMX9525_ca55_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm33) || defined(CPU_MIMX9525xxVZx_cm33))
#include "MIMX9525_cm33_COMMON.h"
#elif (defined(CPU_MIMX9525xxVTx_cm7) || defined(CPU_MIMX9525xxVZx_cm7))
#include "MIMX9525_cm7_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_ca55) || defined(CPU_MIMX9528xxVZx_ca55))
#include "MIMX9528_ca55_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm33) || defined(CPU_MIMX9528xxVZx_cm33))
#include "MIMX9528_cm33_COMMON.h"
#elif (defined(CPU_MIMX9528xxVTx_cm7) || defined(CPU_MIMX9528xxVZx_cm7))
#include "MIMX9528_cm7_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_ca55) || defined(CPU_MIMX9529xxVZx_ca55))
#include "MIMX9529_ca55_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm33) || defined(CPU_MIMX9529xxVZx_cm33))
#include "MIMX9529_cm33_COMMON.h"
#elif (defined(CPU_MIMX9529xxVTx_cm7) || defined(CPU_MIMX9529xxVZx_cm7))
#include "MIMX9529_cm7_COMMON.h"
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
   -- AHBRM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBRM_Peripheral_Access_Layer AHBRM Peripheral Access Layer
 * @{
 */

/** AHBRM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __O  uint32_t CR;                                /**< Control, offset: 0x800 */
  __I  uint32_t SR;                                /**< Status tag, offset: 0x804 */
  __I  uint32_t TAG;                               /**< Virtual tag, offset: 0x808 */
  __I  uint32_t DATA;                              /**< Physical Address Data, offset: 0x80C */
  __O  uint32_t DID_CR;                            /**< Domain ID Control, offset: 0x810 */
  __I  uint32_t DID_SR;                            /**< Domain ID Status tag, offset: 0x814 */
} AHBRM_Type;

/* ----------------------------------------------------------------------------
   -- AHBRM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHBRM_Register_Masks AHBRM Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define AHBRM_CR_ENB_MASK                        (0x1U)
#define AHBRM_CR_ENB_SHIFT                       (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus initiator (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus initiators are simply passed
 *       through the module as if it was disabled.
 */
#define AHBRM_CR_ENB(x)                          (((uint32_t)(((uint32_t)(x)) << AHBRM_CR_ENB_SHIFT)) & AHBRM_CR_ENB_MASK)

#define AHBRM_CR_INV_MASK                        (0x4U)
#define AHBRM_CR_INV_SHIFT                       (2U)
/*! INV - Invalidate Tag register. */
#define AHBRM_CR_INV(x)                          (((uint32_t)(((uint32_t)(x)) << AHBRM_CR_INV_SHIFT)) & AHBRM_CR_INV_MASK)

#define AHBRM_CR_LK_MASK                         (0x8U)
#define AHBRM_CR_LK_SHIFT                        (3U)
/*! LK - Sticky lock bit. */
#define AHBRM_CR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << AHBRM_CR_LK_SHIFT)) & AHBRM_CR_LK_MASK)

#define AHBRM_CR_RADDR_MASK                      (0xFFFFF80U)
#define AHBRM_CR_RADDR_SHIFT                     (7U)
/*! RADDR - Remap address. */
#define AHBRM_CR_RADDR(x)                        (((uint32_t)(((uint32_t)(x)) << AHBRM_CR_RADDR_SHIFT)) & AHBRM_CR_RADDR_MASK)
/*! @} */

/*! @name SR - Status tag */
/*! @{ */

#define AHBRM_SR_ENB_MASK                        (0x1U)
#define AHBRM_SR_ENB_SHIFT                       (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus initiator (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus initiators are simply passed
 *       through the module as if it was disabled.
 */
#define AHBRM_SR_ENB(x)                          (((uint32_t)(((uint32_t)(x)) << AHBRM_SR_ENB_SHIFT)) & AHBRM_SR_ENB_MASK)

#define AHBRM_SR_INV_MASK                        (0x4U)
#define AHBRM_SR_INV_SHIFT                       (2U)
/*! INV - Invalidate Tag register. */
#define AHBRM_SR_INV(x)                          (((uint32_t)(((uint32_t)(x)) << AHBRM_SR_INV_SHIFT)) & AHBRM_SR_INV_MASK)

#define AHBRM_SR_LK_MASK                         (0x8U)
#define AHBRM_SR_LK_SHIFT                        (3U)
/*! LK - Sticky lock bit. */
#define AHBRM_SR_LK(x)                           (((uint32_t)(((uint32_t)(x)) << AHBRM_SR_LK_SHIFT)) & AHBRM_SR_LK_MASK)

#define AHBRM_SR_RADDR_MASK                      (0xFFFFF80U)
#define AHBRM_SR_RADDR_SHIFT                     (7U)
/*! RADDR - Remap address. */
#define AHBRM_SR_RADDR(x)                        (((uint32_t)(((uint32_t)(x)) << AHBRM_SR_RADDR_SHIFT)) & AHBRM_SR_RADDR_MASK)
/*! @} */

/*! @name TAG - Virtual tag */
/*! @{ */

#define AHBRM_TAG_VLD_MASK                       (0x1U)
#define AHBRM_TAG_VLD_SHIFT                      (0U)
/*! VLD - This bit indicates the validity of the entry.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define AHBRM_TAG_VLD(x)                         (((uint32_t)(((uint32_t)(x)) << AHBRM_TAG_VLD_SHIFT)) & AHBRM_TAG_VLD_MASK)

#define AHBRM_TAG_VADDR_MASK                     (0xFFFFFF80U)
#define AHBRM_TAG_VADDR_SHIFT                    (7U)
/*! VADDR - This bit indicates the virtual address. */
#define AHBRM_TAG_VADDR(x)                       (((uint32_t)(((uint32_t)(x)) << AHBRM_TAG_VADDR_SHIFT)) & AHBRM_TAG_VADDR_MASK)
/*! @} */

/*! @name DATA - Physical Address Data */
/*! @{ */

#define AHBRM_DATA_VADDRL_MASK                   (0x7FU)
#define AHBRM_DATA_VADDRL_SHIFT                  (0U)
/*! VADDRL - This bit indicates the low portion of the virtual address. */
#define AHBRM_DATA_VADDRL(x)                     (((uint32_t)(((uint32_t)(x)) << AHBRM_DATA_VADDRL_SHIFT)) & AHBRM_DATA_VADDRL_MASK)

#define AHBRM_DATA_PADDR_MASK                    (0xFFFFF80U)
#define AHBRM_DATA_PADDR_SHIFT                   (7U)
/*! PADDR - This bit indicates the physical address. */
#define AHBRM_DATA_PADDR(x)                      (((uint32_t)(((uint32_t)(x)) << AHBRM_DATA_PADDR_SHIFT)) & AHBRM_DATA_PADDR_MASK)

#define AHBRM_DATA_VADDRH_MASK                   (0xF0000000U)
#define AHBRM_DATA_VADDRH_SHIFT                  (28U)
/*! VADDRH - This bit indicates the high portion of the virtual address. */
#define AHBRM_DATA_VADDRH(x)                     (((uint32_t)(((uint32_t)(x)) << AHBRM_DATA_VADDRH_SHIFT)) & AHBRM_DATA_VADDRH_MASK)
/*! @} */

/*! @name DID_CR - Domain ID Control */
/*! @{ */

#define AHBRM_DID_CR_LK_MASK                     (0x1U)
#define AHBRM_DID_CR_LK_SHIFT                    (0U)
/*! LK - Sticky lock bit. */
#define AHBRM_DID_CR_LK(x)                       (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_CR_LK_SHIFT)) & AHBRM_DID_CR_LK_MASK)

#define AHBRM_DID_CR_MSK_MASK                    (0xF000000U)
#define AHBRM_DID_CR_MSK_SHIFT                   (24U)
/*! MSK - Domain ID match mask. */
#define AHBRM_DID_CR_MSK(x)                      (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_CR_MSK_SHIFT)) & AHBRM_DID_CR_MSK_MASK)

#define AHBRM_DID_CR_VAL_MASK                    (0xF0000000U)
#define AHBRM_DID_CR_VAL_SHIFT                   (28U)
/*! VAL - Domain ID match value. */
#define AHBRM_DID_CR_VAL(x)                      (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_CR_VAL_SHIFT)) & AHBRM_DID_CR_VAL_MASK)
/*! @} */

/*! @name DID_SR - Domain ID Status tag */
/*! @{ */

#define AHBRM_DID_SR_LK_MASK                     (0x1U)
#define AHBRM_DID_SR_LK_SHIFT                    (0U)
/*! LK - Sticky lock bit. */
#define AHBRM_DID_SR_LK(x)                       (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_SR_LK_SHIFT)) & AHBRM_DID_SR_LK_MASK)

#define AHBRM_DID_SR_MSK_MASK                    (0xF000000U)
#define AHBRM_DID_SR_MSK_SHIFT                   (24U)
/*! MSK - Domain ID match mask. */
#define AHBRM_DID_SR_MSK(x)                      (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_SR_MSK_SHIFT)) & AHBRM_DID_SR_MSK_MASK)

#define AHBRM_DID_SR_VAL_MASK                    (0xF0000000U)
#define AHBRM_DID_SR_VAL_SHIFT                   (28U)
/*! VAL - Domain ID match value. */
#define AHBRM_DID_SR_VAL(x)                      (((uint32_t)(((uint32_t)(x)) << AHBRM_DID_SR_VAL_SHIFT)) & AHBRM_DID_SR_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHBRM_Register_Masks */


/*!
 * @}
 */ /* end of group AHBRM_Peripheral_Access_Layer */


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


#endif  /* PERI_AHBRM_H_ */

