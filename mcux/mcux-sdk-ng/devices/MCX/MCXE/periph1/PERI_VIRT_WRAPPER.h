/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VIRT_WRAPPER
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
 * @file PERI_VIRT_WRAPPER.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for VIRT_WRAPPER
 *
 * CMSIS Peripheral Access Layer for VIRT_WRAPPER
 */

#if !defined(PERI_VIRT_WRAPPER_H_)
#define PERI_VIRT_WRAPPER_H_                     /**< Symbol preventing repeated inclusion */

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
/*!
 * @brief VIRT_WRAPPER PAC mapping slot.
 */
typedef enum _virt_wrapper_slot
{
    kVIRT_WRAPPER_PDAC0  = 0x3U, /*!< Map to PDAC0 address. */
    kVIRT_WRAPPER_PDAC1  = 0x0U, /*!< Map to PDAC1 address. */
} virt_wrapper_slot_t;
/*!
 * @brief SIUL2 virtual address mapping.
 *
 * @param siul2_addr SIUL2 peripheral address.
 * @param slot VIRT_WRAPPER slot.
 *
 * @return SIUL2 virtual address.
 */
#define SIUL2_VIRT_ADDR(siul2_addr, slot) (((uint32_t)(siul2_addr) == 0x40290000U) ? (((slot) == kVIRT_WRAPPER_PDAC1) ? 0x40298000U : (uint32_t)(siul2_addr)) : (uint32_t)(siul2_addr))


/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Peripheral_Access_Layer VIRT_WRAPPER Peripheral Access Layer
 * @{
 */

/** VIRT_WRAPPER - Size of Registers Arrays */
#define VIRT_WRAPPER_REG_A_COUNT                  32u
#define VIRT_WRAPPER_REG_B_COUNT                  32u
#define VIRT_WRAPPER_REG_C_COUNT                  1u
#define VIRT_WRAPPER_REG_D_COUNT                  1u

/** VIRT_WRAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t REG_A[VIRT_WRAPPER_REG_A_COUNT];   /**< Parameter_n Register, array offset: 0x0, array step: 0x4 */
  __IO uint32_t REG_B[VIRT_WRAPPER_REG_B_COUNT];   /**< Parameter_n Register, array offset: 0x80, array step: 0x4 */
  __IO uint32_t REG_C[VIRT_WRAPPER_REG_C_COUNT];   /**< Parameter_n Register, array offset: 0x100, array step: 0x4 */
  __IO uint32_t REG_D[VIRT_WRAPPER_REG_D_COUNT];   /**< Parameter_n Register, array offset: 0x104, array step: 0x4 */
} VIRT_WRAPPER_Type;

/* ----------------------------------------------------------------------------
   -- VIRT_WRAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIRT_WRAPPER_Register_Masks VIRT_WRAPPER Register Masks
 * @{
 */

/*! @name REG_A - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_A_PAD_0_MASK            (0x3U)
#define VIRT_WRAPPER_REG_A_PAD_0_SHIFT           (0U)
/*! PAD_0 - PAD_0 */
#define VIRT_WRAPPER_REG_A_PAD_0(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_0_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_0_MASK)

#define VIRT_WRAPPER_REG_A_PAD_1_MASK            (0xCU)
#define VIRT_WRAPPER_REG_A_PAD_1_SHIFT           (2U)
/*! PAD_1 - PAD_1 */
#define VIRT_WRAPPER_REG_A_PAD_1(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_1_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_1_MASK)

#define VIRT_WRAPPER_REG_A_PAD_2_MASK            (0x30U)
#define VIRT_WRAPPER_REG_A_PAD_2_SHIFT           (4U)
/*! PAD_2 - PAD_2 */
#define VIRT_WRAPPER_REG_A_PAD_2(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_2_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_2_MASK)

#define VIRT_WRAPPER_REG_A_PAD_3_MASK            (0xC0U)
#define VIRT_WRAPPER_REG_A_PAD_3_SHIFT           (6U)
/*! PAD_3 - PAD_3 */
#define VIRT_WRAPPER_REG_A_PAD_3(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_3_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_3_MASK)

#define VIRT_WRAPPER_REG_A_PAD_4_MASK            (0x300U)
#define VIRT_WRAPPER_REG_A_PAD_4_SHIFT           (8U)
/*! PAD_4 - PAD_4 */
#define VIRT_WRAPPER_REG_A_PAD_4(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_4_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_4_MASK)

#define VIRT_WRAPPER_REG_A_PAD_5_MASK            (0xC00U)
#define VIRT_WRAPPER_REG_A_PAD_5_SHIFT           (10U)
/*! PAD_5 - PAD_5 */
#define VIRT_WRAPPER_REG_A_PAD_5(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_5_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_5_MASK)

#define VIRT_WRAPPER_REG_A_PAD_6_MASK            (0x3000U)
#define VIRT_WRAPPER_REG_A_PAD_6_SHIFT           (12U)
/*! PAD_6 - PAD_6 */
#define VIRT_WRAPPER_REG_A_PAD_6(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_6_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_6_MASK)

#define VIRT_WRAPPER_REG_A_PAD_7_MASK            (0xC000U)
#define VIRT_WRAPPER_REG_A_PAD_7_SHIFT           (14U)
/*! PAD_7 - PAD_7 */
#define VIRT_WRAPPER_REG_A_PAD_7(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_7_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_7_MASK)

#define VIRT_WRAPPER_REG_A_PAD_8_MASK            (0x30000U)
#define VIRT_WRAPPER_REG_A_PAD_8_SHIFT           (16U)
/*! PAD_8 - PAD_8 */
#define VIRT_WRAPPER_REG_A_PAD_8(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_8_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_8_MASK)

#define VIRT_WRAPPER_REG_A_PAD_9_MASK            (0xC0000U)
#define VIRT_WRAPPER_REG_A_PAD_9_SHIFT           (18U)
/*! PAD_9 - PAD_9 */
#define VIRT_WRAPPER_REG_A_PAD_9(x)              (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_9_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_9_MASK)

#define VIRT_WRAPPER_REG_A_PAD_10_MASK           (0x300000U)
#define VIRT_WRAPPER_REG_A_PAD_10_SHIFT          (20U)
/*! PAD_10 - PAD_10 */
#define VIRT_WRAPPER_REG_A_PAD_10(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_10_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_10_MASK)

#define VIRT_WRAPPER_REG_A_PAD_11_MASK           (0xC00000U)
#define VIRT_WRAPPER_REG_A_PAD_11_SHIFT          (22U)
/*! PAD_11 - PAD_11 */
#define VIRT_WRAPPER_REG_A_PAD_11(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_11_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_11_MASK)

#define VIRT_WRAPPER_REG_A_PAD_12_MASK           (0x3000000U)
#define VIRT_WRAPPER_REG_A_PAD_12_SHIFT          (24U)
/*! PAD_12 - PAD_12 */
#define VIRT_WRAPPER_REG_A_PAD_12(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_12_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_12_MASK)

#define VIRT_WRAPPER_REG_A_PAD_13_MASK           (0xC000000U)
#define VIRT_WRAPPER_REG_A_PAD_13_SHIFT          (26U)
/*! PAD_13 - PAD_13 */
#define VIRT_WRAPPER_REG_A_PAD_13(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_13_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_13_MASK)

#define VIRT_WRAPPER_REG_A_PAD_14_MASK           (0x30000000U)
#define VIRT_WRAPPER_REG_A_PAD_14_SHIFT          (28U)
/*! PAD_14 - PAD_14 */
#define VIRT_WRAPPER_REG_A_PAD_14(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_14_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_14_MASK)

#define VIRT_WRAPPER_REG_A_PAD_15_MASK           (0xC0000000U)
#define VIRT_WRAPPER_REG_A_PAD_15_SHIFT          (30U)
/*! PAD_15 - PAD_15 */
#define VIRT_WRAPPER_REG_A_PAD_15(x)             (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_A_PAD_15_SHIFT)) & VIRT_WRAPPER_REG_A_PAD_15_MASK)
/*! @} */

/*! @name REG_B - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_B_INMUX_0_MASK          (0x3U)
#define VIRT_WRAPPER_REG_B_INMUX_0_SHIFT         (0U)
/*! INMUX_0 - INMUX_0 */
#define VIRT_WRAPPER_REG_B_INMUX_0(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_0_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_0_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_1_MASK          (0xCU)
#define VIRT_WRAPPER_REG_B_INMUX_1_SHIFT         (2U)
/*! INMUX_1 - INMUX_1 */
#define VIRT_WRAPPER_REG_B_INMUX_1(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_1_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_1_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_2_MASK          (0x30U)
#define VIRT_WRAPPER_REG_B_INMUX_2_SHIFT         (4U)
/*! INMUX_2 - INMUX_2 */
#define VIRT_WRAPPER_REG_B_INMUX_2(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_2_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_2_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_3_MASK          (0xC0U)
#define VIRT_WRAPPER_REG_B_INMUX_3_SHIFT         (6U)
/*! INMUX_3 - INMUX_3 */
#define VIRT_WRAPPER_REG_B_INMUX_3(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_3_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_3_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_4_MASK          (0x300U)
#define VIRT_WRAPPER_REG_B_INMUX_4_SHIFT         (8U)
/*! INMUX_4 - INMUX_4 */
#define VIRT_WRAPPER_REG_B_INMUX_4(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_4_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_4_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_5_MASK          (0xC00U)
#define VIRT_WRAPPER_REG_B_INMUX_5_SHIFT         (10U)
/*! INMUX_5 - INMUX_5 */
#define VIRT_WRAPPER_REG_B_INMUX_5(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_5_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_5_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_6_MASK          (0x3000U)
#define VIRT_WRAPPER_REG_B_INMUX_6_SHIFT         (12U)
/*! INMUX_6 - INMUX_6 */
#define VIRT_WRAPPER_REG_B_INMUX_6(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_6_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_6_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_7_MASK          (0xC000U)
#define VIRT_WRAPPER_REG_B_INMUX_7_SHIFT         (14U)
/*! INMUX_7 - INMUX_7 */
#define VIRT_WRAPPER_REG_B_INMUX_7(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_7_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_7_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_8_MASK          (0x30000U)
#define VIRT_WRAPPER_REG_B_INMUX_8_SHIFT         (16U)
/*! INMUX_8 - INMUX_8 */
#define VIRT_WRAPPER_REG_B_INMUX_8(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_8_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_8_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_9_MASK          (0xC0000U)
#define VIRT_WRAPPER_REG_B_INMUX_9_SHIFT         (18U)
/*! INMUX_9 - INMUX_9 */
#define VIRT_WRAPPER_REG_B_INMUX_9(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_9_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_9_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_10_MASK         (0x300000U)
#define VIRT_WRAPPER_REG_B_INMUX_10_SHIFT        (20U)
/*! INMUX_10 - INMUX_10 */
#define VIRT_WRAPPER_REG_B_INMUX_10(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_10_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_10_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_11_MASK         (0xC00000U)
#define VIRT_WRAPPER_REG_B_INMUX_11_SHIFT        (22U)
/*! INMUX_11 - INMUX_11 */
#define VIRT_WRAPPER_REG_B_INMUX_11(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_11_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_11_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_12_MASK         (0x3000000U)
#define VIRT_WRAPPER_REG_B_INMUX_12_SHIFT        (24U)
/*! INMUX_12 - INMUX_12 */
#define VIRT_WRAPPER_REG_B_INMUX_12(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_12_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_12_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_13_MASK         (0xC000000U)
#define VIRT_WRAPPER_REG_B_INMUX_13_SHIFT        (26U)
/*! INMUX_13 - INMUX_13 */
#define VIRT_WRAPPER_REG_B_INMUX_13(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_13_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_13_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_14_MASK         (0x30000000U)
#define VIRT_WRAPPER_REG_B_INMUX_14_SHIFT        (28U)
/*! INMUX_14 - INMUX_14 */
#define VIRT_WRAPPER_REG_B_INMUX_14(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_14_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_14_MASK)

#define VIRT_WRAPPER_REG_B_INMUX_15_MASK         (0xC0000000U)
#define VIRT_WRAPPER_REG_B_INMUX_15_SHIFT        (30U)
/*! INMUX_15 - INMUX_15 */
#define VIRT_WRAPPER_REG_B_INMUX_15(x)           (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_B_INMUX_15_SHIFT)) & VIRT_WRAPPER_REG_B_INMUX_15_MASK)
/*! @} */

/*! @name REG_C - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_C_INTC_CTRL_MASK        (0x3U)
#define VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT       (0U)
/*! INTC_CTRL - Interrupt register control */
#define VIRT_WRAPPER_REG_C_INTC_CTRL(x)          (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_C_INTC_CTRL_SHIFT)) & VIRT_WRAPPER_REG_C_INTC_CTRL_MASK)
/*! @} */

/*! @name REG_D - Parameter_n Register */
/*! @{ */

#define VIRT_WRAPPER_REG_D_REG_GCR_MASK          (0xC0000000U)
#define VIRT_WRAPPER_REG_D_REG_GCR_SHIFT         (30U)
/*! REG_GCR - GCR Register Of REG_PROT */
#define VIRT_WRAPPER_REG_D_REG_GCR(x)            (((uint32_t)(((uint32_t)(x)) << VIRT_WRAPPER_REG_D_REG_GCR_SHIFT)) & VIRT_WRAPPER_REG_D_REG_GCR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Register_Masks */


/*!
 * @}
 */ /* end of group VIRT_WRAPPER_Peripheral_Access_Layer */


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


#endif  /* PERI_VIRT_WRAPPER_H_ */

