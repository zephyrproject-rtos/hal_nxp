/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for AHB_ADDR_REMAP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_AHB_ADDR_REMAP.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for AHB_ADDR_REMAP
 *
 * CMSIS Peripheral Access Layer for AHB_ADDR_REMAP
 */

#if !defined(PERI_AHB_ADDR_REMAP_H_)
#define PERI_AHB_ADDR_REMAP_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- AHB_ADDR_REMAP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_ADDR_REMAP_Peripheral_Access_Layer AHB_ADDR_REMAP Peripheral Access Layer
 * @{
 */

/** AHB_ADDR_REMAP - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[2048];
  __O  uint32_t CR;                                /**< Control, offset: 0x800 */
  __I  uint32_t SR;                                /**< Status tag, offset: 0x804 */
  __I  uint32_t TAG;                               /**< Virtual tag, offset: 0x808 */
  __I  uint32_t DATA;                              /**< Physical Address Data, offset: 0x80C */
} AHB_ADDR_REMAP_Type;

/* ----------------------------------------------------------------------------
   -- AHB_ADDR_REMAP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AHB_ADDR_REMAP_Register_Masks AHB_ADDR_REMAP Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define AHB_ADDR_REMAP_CR_ENB_MASK               (0x1U)
#define AHB_ADDR_REMAP_CR_ENB_SHIFT              (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus master (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus masters are simply passed through
 *       the module as if it was disabled.
 */
#define AHB_ADDR_REMAP_CR_ENB(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_CR_ENB_SHIFT)) & AHB_ADDR_REMAP_CR_ENB_MASK)

#define AHB_ADDR_REMAP_CR_INV_MASK               (0x4U)
#define AHB_ADDR_REMAP_CR_INV_SHIFT              (2U)
/*! INV - Invalidate Tag register. */
#define AHB_ADDR_REMAP_CR_INV(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_CR_INV_SHIFT)) & AHB_ADDR_REMAP_CR_INV_MASK)

#define AHB_ADDR_REMAP_CR_LK_MASK                (0x8U)
#define AHB_ADDR_REMAP_CR_LK_SHIFT               (3U)
/*! LK - Sticky lock bit. */
#define AHB_ADDR_REMAP_CR_LK(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_CR_LK_SHIFT)) & AHB_ADDR_REMAP_CR_LK_MASK)

#define AHB_ADDR_REMAP_CR_RADDR_MASK             (0xFFFFF80U)
#define AHB_ADDR_REMAP_CR_RADDR_SHIFT            (7U)
/*! RADDR - Remap address. */
#define AHB_ADDR_REMAP_CR_RADDR(x)               (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_CR_RADDR_SHIFT)) & AHB_ADDR_REMAP_CR_RADDR_MASK)
/*! @} */

/*! @name SR - Status tag */
/*! @{ */

#define AHB_ADDR_REMAP_SR_ENB_MASK               (0x1U)
#define AHB_ADDR_REMAP_SR_ENB_SHIFT              (0U)
/*! ENB - Enable Remap.
 *  0b0..The module is disabled and all input AHB addresses & attributes are simply routed to the output AHB address & attributes buses.
 *  0b1..All AHB addresses from the designed bus master (typically a processor core) are remapped using the
 *       constant offset defined by the CR[RADDR] field. AHB accesses from other bus masters are simply passed through
 *       the module as if it was disabled.
 */
#define AHB_ADDR_REMAP_SR_ENB(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_SR_ENB_SHIFT)) & AHB_ADDR_REMAP_SR_ENB_MASK)

#define AHB_ADDR_REMAP_SR_INV_MASK               (0x4U)
#define AHB_ADDR_REMAP_SR_INV_SHIFT              (2U)
/*! INV - Invalidate Tag register. */
#define AHB_ADDR_REMAP_SR_INV(x)                 (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_SR_INV_SHIFT)) & AHB_ADDR_REMAP_SR_INV_MASK)

#define AHB_ADDR_REMAP_SR_LK_MASK                (0x8U)
#define AHB_ADDR_REMAP_SR_LK_SHIFT               (3U)
/*! LK - Sticky lock bit. */
#define AHB_ADDR_REMAP_SR_LK(x)                  (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_SR_LK_SHIFT)) & AHB_ADDR_REMAP_SR_LK_MASK)

#define AHB_ADDR_REMAP_SR_RADDR_MASK             (0xFFFFF80U)
#define AHB_ADDR_REMAP_SR_RADDR_SHIFT            (7U)
/*! RADDR - Remap address. */
#define AHB_ADDR_REMAP_SR_RADDR(x)               (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_SR_RADDR_SHIFT)) & AHB_ADDR_REMAP_SR_RADDR_MASK)
/*! @} */

/*! @name TAG - Virtual tag */
/*! @{ */

#define AHB_ADDR_REMAP_TAG_VLD_MASK              (0x1U)
#define AHB_ADDR_REMAP_TAG_VLD_SHIFT             (0U)
/*! VLD - This bit indicates the validity of the entry.
 *  0b0..Disabled.
 *  0b1..Enabled.
 */
#define AHB_ADDR_REMAP_TAG_VLD(x)                (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_TAG_VLD_SHIFT)) & AHB_ADDR_REMAP_TAG_VLD_MASK)

#define AHB_ADDR_REMAP_TAG_VADDR_MASK            (0xFFFFFF80U)
#define AHB_ADDR_REMAP_TAG_VADDR_SHIFT           (7U)
/*! VADDR - This bit indicates the virtual address. */
#define AHB_ADDR_REMAP_TAG_VADDR(x)              (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_TAG_VADDR_SHIFT)) & AHB_ADDR_REMAP_TAG_VADDR_MASK)
/*! @} */

/*! @name DATA - Physical Address Data */
/*! @{ */

#define AHB_ADDR_REMAP_DATA_VADDRL_MASK          (0x7FU)
#define AHB_ADDR_REMAP_DATA_VADDRL_SHIFT         (0U)
/*! VADDRL - This bit indicates the low portion of the virtual address. */
#define AHB_ADDR_REMAP_DATA_VADDRL(x)            (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_DATA_VADDRL_SHIFT)) & AHB_ADDR_REMAP_DATA_VADDRL_MASK)

#define AHB_ADDR_REMAP_DATA_PADDR_MASK           (0xFFFFF80U)
#define AHB_ADDR_REMAP_DATA_PADDR_SHIFT          (7U)
/*! PADDR - This bit indicates the physical address. */
#define AHB_ADDR_REMAP_DATA_PADDR(x)             (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_DATA_PADDR_SHIFT)) & AHB_ADDR_REMAP_DATA_PADDR_MASK)

#define AHB_ADDR_REMAP_DATA_VADDRH_MASK          (0xF0000000U)
#define AHB_ADDR_REMAP_DATA_VADDRH_SHIFT         (28U)
/*! VADDRH - This bit indicates the high portion of the virtual address. */
#define AHB_ADDR_REMAP_DATA_VADDRH(x)            (((uint32_t)(((uint32_t)(x)) << AHB_ADDR_REMAP_DATA_VADDRH_SHIFT)) & AHB_ADDR_REMAP_DATA_VADDRH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group AHB_ADDR_REMAP_Register_Masks */


/*!
 * @}
 */ /* end of group AHB_ADDR_REMAP_Peripheral_Access_Layer */


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


#endif  /* PERI_AHB_ADDR_REMAP_H_ */

