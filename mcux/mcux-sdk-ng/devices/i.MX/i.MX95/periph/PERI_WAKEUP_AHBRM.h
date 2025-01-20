/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKEUP_AHBRM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file WAKEUP_AHBRM.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for WAKEUP_AHBRM
 *
 * CMSIS Peripheral Access Layer for WAKEUP_AHBRM
 */

#if !defined(WAKEUP_AHBRM_H_)
#define WAKEUP_AHBRM_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- WAKEUP_AHBRM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AHBRM_Peripheral_Access_Layer WAKEUP_AHBRM Peripheral Access Layer
 * @{
 */

/** WAKEUP_AHBRM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __O  uint32_t CR;                                /**< Control, offset: 0x800 */
  __I  uint32_t SR;                                /**< Status tag, offset: 0x804 */
  __I  uint32_t TAG;                               /**< Virtual tag, offset: 0x808 */
  __I  uint32_t DATA;                              /**< Physical Address Data, offset: 0x80C */
  __O  uint32_t DID_CR;                            /**< Domain ID Control, offset: 0x810 */
  __I  uint32_t DID_SR;                            /**< Domain ID Status tag, offset: 0x814 */
} WAKEUP_AHBRM_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_AHBRM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_AHBRM_Register_Masks WAKEUP_AHBRM Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define WAKEUP_AHBRM_CR_ENB_MASK                 (0x1U)
#define WAKEUP_AHBRM_CR_ENB_SHIFT                (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus master (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus masters are simply passed through
 *       the module as if it was disabled.
 */
#define WAKEUP_AHBRM_CR_ENB(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_ENB_SHIFT)) & WAKEUP_AHBRM_CR_ENB_MASK)

#define WAKEUP_AHBRM_CR_INV_MASK                 (0x4U)
#define WAKEUP_AHBRM_CR_INV_SHIFT                (2U)
/*! INV - Invalidate Tag register. */
#define WAKEUP_AHBRM_CR_INV(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_INV_SHIFT)) & WAKEUP_AHBRM_CR_INV_MASK)

#define WAKEUP_AHBRM_CR_LK_MASK                  (0x8U)
#define WAKEUP_AHBRM_CR_LK_SHIFT                 (3U)
/*! LK - Sticky lock bit. */
#define WAKEUP_AHBRM_CR_LK(x)                    (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_LK_SHIFT)) & WAKEUP_AHBRM_CR_LK_MASK)

#define WAKEUP_AHBRM_CR_RADDR_MASK               (0xFFFFF80U)
#define WAKEUP_AHBRM_CR_RADDR_SHIFT              (7U)
/*! RADDR - Remap address. */
#define WAKEUP_AHBRM_CR_RADDR(x)                 (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_CR_RADDR_SHIFT)) & WAKEUP_AHBRM_CR_RADDR_MASK)
/*! @} */

/*! @name SR - Status tag */
/*! @{ */

#define WAKEUP_AHBRM_SR_ENB_MASK                 (0x1U)
#define WAKEUP_AHBRM_SR_ENB_SHIFT                (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus master (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus masters are simply passed through
 *       the module as if it was disabled.
 */
#define WAKEUP_AHBRM_SR_ENB(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_SR_ENB_SHIFT)) & WAKEUP_AHBRM_SR_ENB_MASK)

#define WAKEUP_AHBRM_SR_INV_MASK                 (0x4U)
#define WAKEUP_AHBRM_SR_INV_SHIFT                (2U)
/*! INV - Invalidate Tag register. */
#define WAKEUP_AHBRM_SR_INV(x)                   (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_SR_INV_SHIFT)) & WAKEUP_AHBRM_SR_INV_MASK)

#define WAKEUP_AHBRM_SR_LK_MASK                  (0x8U)
#define WAKEUP_AHBRM_SR_LK_SHIFT                 (3U)
/*! LK - Sticky lock bit. */
#define WAKEUP_AHBRM_SR_LK(x)                    (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_SR_LK_SHIFT)) & WAKEUP_AHBRM_SR_LK_MASK)

#define WAKEUP_AHBRM_SR_RADDR_MASK               (0xFFFFF80U)
#define WAKEUP_AHBRM_SR_RADDR_SHIFT              (7U)
/*! RADDR - Remap address. */
#define WAKEUP_AHBRM_SR_RADDR(x)                 (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_SR_RADDR_SHIFT)) & WAKEUP_AHBRM_SR_RADDR_MASK)
/*! @} */

/*! @name TAG - Virtual tag */
/*! @{ */

#define WAKEUP_AHBRM_TAG_VLD_MASK                (0x1U)
#define WAKEUP_AHBRM_TAG_VLD_SHIFT               (0U)
/*! VLD - This bit indicates the validity of the entry.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define WAKEUP_AHBRM_TAG_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_TAG_VLD_SHIFT)) & WAKEUP_AHBRM_TAG_VLD_MASK)

#define WAKEUP_AHBRM_TAG_VADDR_MASK              (0xFFFFFF80U)
#define WAKEUP_AHBRM_TAG_VADDR_SHIFT             (7U)
/*! VADDR - This bit indicates the virtual address. */
#define WAKEUP_AHBRM_TAG_VADDR(x)                (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_TAG_VADDR_SHIFT)) & WAKEUP_AHBRM_TAG_VADDR_MASK)
/*! @} */

/*! @name DATA - Physical Address Data */
/*! @{ */

#define WAKEUP_AHBRM_DATA_VADDRL_MASK            (0x7FU)
#define WAKEUP_AHBRM_DATA_VADDRL_SHIFT           (0U)
/*! VADDRL - This bit indicates the low portion of the virtual address. */
#define WAKEUP_AHBRM_DATA_VADDRL(x)              (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DATA_VADDRL_SHIFT)) & WAKEUP_AHBRM_DATA_VADDRL_MASK)

#define WAKEUP_AHBRM_DATA_PADDR_MASK             (0xFFFFF80U)
#define WAKEUP_AHBRM_DATA_PADDR_SHIFT            (7U)
/*! PADDR - This bit indicates the physical address. */
#define WAKEUP_AHBRM_DATA_PADDR(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DATA_PADDR_SHIFT)) & WAKEUP_AHBRM_DATA_PADDR_MASK)

#define WAKEUP_AHBRM_DATA_VADDRH_MASK            (0xF0000000U)
#define WAKEUP_AHBRM_DATA_VADDRH_SHIFT           (28U)
/*! VADDRH - This bit indicates the high portion of the virtual address. */
#define WAKEUP_AHBRM_DATA_VADDRH(x)              (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DATA_VADDRH_SHIFT)) & WAKEUP_AHBRM_DATA_VADDRH_MASK)
/*! @} */

/*! @name DID_CR - Domain ID Control */
/*! @{ */

#define WAKEUP_AHBRM_DID_CR_LK_MASK              (0x1U)
#define WAKEUP_AHBRM_DID_CR_LK_SHIFT             (0U)
/*! LK - Sticky lock bit. */
#define WAKEUP_AHBRM_DID_CR_LK(x)                (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_CR_LK_SHIFT)) & WAKEUP_AHBRM_DID_CR_LK_MASK)

#define WAKEUP_AHBRM_DID_CR_MSK_MASK             (0xF000000U)
#define WAKEUP_AHBRM_DID_CR_MSK_SHIFT            (24U)
/*! MSK - Domain ID match mask. */
#define WAKEUP_AHBRM_DID_CR_MSK(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_CR_MSK_SHIFT)) & WAKEUP_AHBRM_DID_CR_MSK_MASK)

#define WAKEUP_AHBRM_DID_CR_VAL_MASK             (0xF0000000U)
#define WAKEUP_AHBRM_DID_CR_VAL_SHIFT            (28U)
/*! VAL - Domain ID match value. */
#define WAKEUP_AHBRM_DID_CR_VAL(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_CR_VAL_SHIFT)) & WAKEUP_AHBRM_DID_CR_VAL_MASK)
/*! @} */

/*! @name DID_SR - Domain ID Status tag */
/*! @{ */

#define WAKEUP_AHBRM_DID_SR_LK_MASK              (0x1U)
#define WAKEUP_AHBRM_DID_SR_LK_SHIFT             (0U)
/*! LK - Sticky lock bit. */
#define WAKEUP_AHBRM_DID_SR_LK(x)                (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_SR_LK_SHIFT)) & WAKEUP_AHBRM_DID_SR_LK_MASK)

#define WAKEUP_AHBRM_DID_SR_MSK_MASK             (0xF000000U)
#define WAKEUP_AHBRM_DID_SR_MSK_SHIFT            (24U)
/*! MSK - Domain ID match mask. */
#define WAKEUP_AHBRM_DID_SR_MSK(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_SR_MSK_SHIFT)) & WAKEUP_AHBRM_DID_SR_MSK_MASK)

#define WAKEUP_AHBRM_DID_SR_VAL_MASK             (0xF0000000U)
#define WAKEUP_AHBRM_DID_SR_VAL_SHIFT            (28U)
/*! VAL - Domain ID match value. */
#define WAKEUP_AHBRM_DID_SR_VAL(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_AHBRM_DID_SR_VAL_SHIFT)) & WAKEUP_AHBRM_DID_SR_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WAKEUP_AHBRM_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_AHBRM_Peripheral_Access_Layer */


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


#endif  /* WAKEUP_AHBRM_H_ */

