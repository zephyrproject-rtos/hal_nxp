/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PIT
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
 * @file PERI_PIT.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for PIT
 *
 * CMSIS Peripheral Access Layer for PIT
 */

#if !defined(PERI_PIT_H_)
#define PERI_PIT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Size of Registers Arrays */
#define PIT_CHANNEL_COUNT                         4u

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PIT Module Control, offset: 0x0 */
       uint8_t RESERVED_0[220];
  __I  uint32_t LTMR64H;                           /**< PIT Upper Lifetimer, offset: 0xE0, available only on: PIT_0 (missing on PIT_1) */
  __I  uint32_t LTMR64L;                           /**< PIT Lower Lifetimer, offset: 0xE4, available only on: PIT_0 (missing on PIT_1) */
       uint8_t RESERVED_1[4];
  __IO uint32_t RTI_LDVAL_STAT;                    /**< RTI Timer Load Value Sync Status, offset: 0xEC, available only on: PIT_0 (missing on PIT_1) */
  __IO uint32_t RTI_LDVAL;                         /**< RTI Timer Load Value, offset: 0xF0, available only on: PIT_0 (missing on PIT_1) */
  __I  uint32_t RTI_CVAL;                          /**< Current RTI Timer Value, offset: 0xF4, available only on: PIT_0 (missing on PIT_1) */
  __IO uint32_t RTI_TCTRL;                         /**< RTI Timer Control, offset: 0xF8, available only on: PIT_0 (missing on PIT_1) */
  __IO uint32_t RTI_TFLG;                          /**< RTI Timer Interrupt Flag, offset: 0xFC, available only on: PIT_0 (missing on PIT_1) */
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[PIT_CHANNEL_COUNT];
} PIT_Type;

/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/*! @name MCR - PIT Module Control */
/*! @{ */

#define PIT_MCR_FRZ_MASK                         (0x1U)
#define PIT_MCR_FRZ_SHIFT                        (0U)
/*! FRZ - Freeze
 *  0b0..Timers run in Debug mode
 *  0b1..Timers stop in Debug mode
 */
#define PIT_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x)) << PIT_MCR_FRZ_SHIFT)) & PIT_MCR_FRZ_MASK)

#define PIT_MCR_MDIS_MASK                        (0x2U)
#define PIT_MCR_MDIS_SHIFT                       (1U)
/*! MDIS - Module Disable for PIT
 *  0b0..Enables
 *  0b1..Disables
 */
#define PIT_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_SHIFT)) & PIT_MCR_MDIS_MASK)

#define PIT_MCR_MDIS_RTI_MASK                    (0x4U)
#define PIT_MCR_MDIS_RTI_SHIFT                   (2U)
/*! MDIS_RTI - Module Disable for RTI
 *  0b0..Enables
 *  0b1..Disables
 */
#define PIT_MCR_MDIS_RTI(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_MCR_MDIS_RTI_SHIFT)) & PIT_MCR_MDIS_RTI_MASK)
/*! @} */

/*! @name LTMR64H - PIT Upper Lifetimer */
/*! @{ */

#define PIT_LTMR64H_LTH_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64H_LTH_SHIFT                    (0U)
/*! LTH - Lifetimer Value */
#define PIT_LTMR64H_LTH(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64H_LTH_SHIFT)) & PIT_LTMR64H_LTH_MASK)
/*! @} */

/*! @name LTMR64L - PIT Lower Lifetimer */
/*! @{ */

#define PIT_LTMR64L_LTL_MASK                     (0xFFFFFFFFU)
#define PIT_LTMR64L_LTL_SHIFT                    (0U)
/*! LTL - Lifetimer Value */
#define PIT_LTMR64L_LTL(x)                       (((uint32_t)(((uint32_t)(x)) << PIT_LTMR64L_LTL_SHIFT)) & PIT_LTMR64L_LTL_MASK)
/*! @} */

/*! @name RTI_LDVAL_STAT - RTI Timer Load Value Sync Status */
/*! @{ */

#define PIT_RTI_LDVAL_STAT_RT_STAT_MASK          (0x1U)
#define PIT_RTI_LDVAL_STAT_RT_STAT_SHIFT         (0U)
/*! RT_STAT - Sync Status
 *  0b0..Clears status
 *  0b0..Not loaded
 *  0b1..Clears status
 *  0b1..Loaded
 */
#define PIT_RTI_LDVAL_STAT_RT_STAT(x)            (((uint32_t)(((uint32_t)(x)) << PIT_RTI_LDVAL_STAT_RT_STAT_SHIFT)) & PIT_RTI_LDVAL_STAT_RT_STAT_MASK)
/*! @} */

/*! @name RTI_LDVAL - RTI Timer Load Value */
/*! @{ */

#define PIT_RTI_LDVAL_TSV_MASK                   (0xFFFFFFFFU)
#define PIT_RTI_LDVAL_TSV_SHIFT                  (0U)
/*! TSV - Timer Start Value */
#define PIT_RTI_LDVAL_TSV(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_LDVAL_TSV_SHIFT)) & PIT_RTI_LDVAL_TSV_MASK)
/*! @} */

/*! @name RTI_CVAL - Current RTI Timer Value */
/*! @{ */

#define PIT_RTI_CVAL_TVL_MASK                    (0xFFFFFFFFU)
#define PIT_RTI_CVAL_TVL_SHIFT                   (0U)
/*! TVL - Current Timer Value */
#define PIT_RTI_CVAL_TVL(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_RTI_CVAL_TVL_SHIFT)) & PIT_RTI_CVAL_TVL_MASK)
/*! @} */

/*! @name RTI_TCTRL - RTI Timer Control */
/*! @{ */

#define PIT_RTI_TCTRL_TEN_MASK                   (0x1U)
#define PIT_RTI_TCTRL_TEN_SHIFT                  (0U)
/*! TEN - Timer Enable Bit
 *  0b0..Disables
 *  0b1..Enables. The RTI timer begins counting down.
 */
#define PIT_RTI_TCTRL_TEN(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TCTRL_TEN_SHIFT)) & PIT_RTI_TCTRL_TEN_MASK)

#define PIT_RTI_TCTRL_TIE_MASK                   (0x2U)
#define PIT_RTI_TCTRL_TIE_SHIFT                  (1U)
/*! TIE - Timer Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PIT_RTI_TCTRL_TIE(x)                     (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TCTRL_TIE_SHIFT)) & PIT_RTI_TCTRL_TIE_MASK)
/*! @} */

/*! @name RTI_TFLG - RTI Timer Interrupt Flag */
/*! @{ */

#define PIT_RTI_TFLG_TIF_MASK                    (0x1U)
#define PIT_RTI_TFLG_TIF_SHIFT                   (0U)
/*! TIF - Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Timer still counting down
 *  0b1..Clears the flag
 *  0b1..Timer has expired
 */
#define PIT_RTI_TFLG_TIF(x)                      (((uint32_t)(((uint32_t)(x)) << PIT_RTI_TFLG_TIF_SHIFT)) & PIT_RTI_TFLG_TIF_MASK)
/*! @} */

/*! @name LDVAL - Timer Load Value */
/*! @{ */

#define PIT_LDVAL_TSV_MASK                       (0xFFFFFFFFU)
#define PIT_LDVAL_TSV_SHIFT                      (0U)
/*! TSV - Timer Start Value */
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_LDVAL_TSV_SHIFT)) & PIT_LDVAL_TSV_MASK)
/*! @} */

/* The count of PIT_LDVAL */
#define PIT_LDVAL_COUNT                          (4U)

/*! @name CVAL - Current Timer Value */
/*! @{ */

#define PIT_CVAL_TVL_MASK                        (0xFFFFFFFFU)
#define PIT_CVAL_TVL_SHIFT                       (0U)
/*! TVL - Timer Value */
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_CVAL_TVL_SHIFT)) & PIT_CVAL_TVL_MASK)
/*! @} */

/* The count of PIT_CVAL */
#define PIT_CVAL_COUNT                           (4U)

/*! @name TCTRL - Timer Control */
/*! @{ */

#define PIT_TCTRL_TEN_MASK                       (0x1U)
#define PIT_TCTRL_TEN_SHIFT                      (0U)
/*! TEN - Timer Enable
 *  0b0..Disables
 *  0b1..Enables. The timer begins counting down.
 */
#define PIT_TCTRL_TEN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TEN_SHIFT)) & PIT_TCTRL_TEN_MASK)

#define PIT_TCTRL_TIE_MASK                       (0x2U)
#define PIT_TCTRL_TIE_SHIFT                      (1U)
/*! TIE - Timer Interrupt Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define PIT_TCTRL_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_TIE_SHIFT)) & PIT_TCTRL_TIE_MASK)

#define PIT_TCTRL_CHN_MASK                       (0x4U)
#define PIT_TCTRL_CHN_SHIFT                      (2U)
/*! CHN - Chain Mode
 *  0b0..Unchains
 *  0b1..Chains
 */
#define PIT_TCTRL_CHN(x)                         (((uint32_t)(((uint32_t)(x)) << PIT_TCTRL_CHN_SHIFT)) & PIT_TCTRL_CHN_MASK)
/*! @} */

/* The count of PIT_TCTRL */
#define PIT_TCTRL_COUNT                          (4U)

/*! @name TFLG - Timer Flag */
/*! @{ */

#define PIT_TFLG_TIF_MASK                        (0x1U)
#define PIT_TFLG_TIF_SHIFT                       (0U)
/*! TIF - Timer Interrupt Flag
 *  0b0..No effect
 *  0b0..Timer has not expired
 *  0b1..Clears flag
 *  0b1..Timer expired
 */
#define PIT_TFLG_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << PIT_TFLG_TIF_SHIFT)) & PIT_TFLG_TIF_MASK)
/*! @} */

/* The count of PIT_TFLG */
#define PIT_TFLG_COUNT                           (4U)


/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


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


#endif  /* PERI_PIT_H_ */

