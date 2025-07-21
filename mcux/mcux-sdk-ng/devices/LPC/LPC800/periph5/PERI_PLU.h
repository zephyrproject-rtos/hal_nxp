/*
** ###################################################################
**     Processors:          LPC804M101JDH20
**                          LPC804M101JDH24
**                          LPC804M101JHI33
**                          LPC804M111JDH24
**                          LPC804UK
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PLU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PLU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PLU
 *
 * CMSIS Peripheral Access Layer for PLU
 */

#if !defined(PERI_PLU_H_)
#define PERI_PLU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC804M101JDH20) || defined(CPU_LPC804M101JDH24) || defined(CPU_LPC804M101JHI33) || defined(CPU_LPC804M111JDH24) || defined(CPU_LPC804UK))
#include "LPC804_COMMON.h"
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
   -- PLU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Peripheral_Access_Layer PLU Peripheral Access Layer
 * @{
 */

/** PLU - Size of Registers Arrays */
#define PLU_LUT_INP_COUNT                         5u
#define PLU_LUT_COUNT                             26u
#define PLU_LUT_T_COUNT                           26u
#define PLU_OUTPUT_MUX_COUNT                      8u

/** PLU - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x20 */
    __IO uint32_t INP_MUX[PLU_LUT_INP_COUNT];        /**< LUT0 input 0 MUX..LUT25 input 4 MUX, array offset: 0x0, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[12];
  } LUT[PLU_LUT_COUNT];
       uint8_t RESERVED_0[1216];
  __IO uint32_t LUT_TRUTH[PLU_LUT_T_COUNT];        /**< Specifies the Truth Table contents for LUT0..Specifies the Truth Table contents for LUT25, array offset: 0x800, array step: 0x4 */
       uint8_t RESERVED_1[152];
  __I  uint32_t OUTPUTS;                           /**< Provides the current state of the 8 designated PLU Outputs., offset: 0x900 */
       uint8_t RESERVED_2[764];
  __IO uint32_t OUTPUT_MUX[PLU_OUTPUT_MUX_COUNT];  /**< Selects the source to be connected to PLU Output 0..Selects the source to be connected to PLU Output 7, array offset: 0xC00, array step: 0x4 */
} PLU_Type;

/* ----------------------------------------------------------------------------
   -- PLU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLU_Register_Masks PLU Register Masks
 * @{
 */

/*! @name LUT_INP_MUX - LUT0 input 0 MUX..LUT25 input 4 MUX */
/*! @{ */

#define PLU_LUT_INP_MUX_LUTn_INPx_MASK           (0x3FU)
#define PLU_LUT_INP_MUX_LUTn_INPx_SHIFT          (0U)
/*! LUTn_INPx - Selects the input source to be connected to LUT25 input4. For each LUT, the slot
 *    associated with the output from LUTn itself is tied low.
 *  0b000000..The PLU primary inputs 0.
 *  0b000001..The PLU primary inputs 1.
 *  0b000010..The PLU primary inputs 2.
 *  0b000011..The PLU primary inputs 3.
 *  0b000100..The PLU primary inputs 4.
 *  0b000101..The PLU primary inputs 5.
 *  0b000110..The output of LUT0.
 *  0b000111..The output of LUT1.
 *  0b001000..The output of LUT2.
 *  0b001001..The output of LUT3.
 *  0b001010..The output of LUT4.
 *  0b001011..The output of LUT5.
 *  0b001100..The output of LUT6.
 *  0b001101..The output of LUT7.
 *  0b001110..The output of LUT8.
 *  0b001111..The output of LUT9.
 *  0b010000..The output of LUT10.
 *  0b010001..The output of LUT11.
 *  0b010010..The output of LUT12.
 *  0b010011..The output of LUT13.
 *  0b010100..The output of LUT14.
 *  0b010101..The output of LUT15.
 *  0b010110..The output of LUT16.
 *  0b010111..The output of LUT17.
 *  0b011000..The output of LUT18.
 *  0b011001..The output of LUT19.
 *  0b011010..The output of LUT20.
 *  0b011011..The output of LUT21.
 *  0b011100..The output of LUT22.
 *  0b011101..The output of LUT23.
 *  0b011110..The output of LUT24.
 *  0b011111..The output of LUT25.
 *  0b100000..state(0).
 *  0b100001..state(1).
 *  0b100010..state(2).
 *  0b100011..state(3).
 */
#define PLU_LUT_INP_MUX_LUTn_INPx(x)             (((uint32_t)(((uint32_t)(x)) << PLU_LUT_INP_MUX_LUTn_INPx_SHIFT)) & PLU_LUT_INP_MUX_LUTn_INPx_MASK)
/*! @} */

/* The count of PLU_LUT_INP_MUX */
#define PLU_LUT_INP_MUX_COUNT                    (26U)

/* The count of PLU_LUT_INP_MUX */
#define PLU_LUT_INP_MUX_COUNT2                   (5U)

/*! @name LUT_TRUTH - Specifies the Truth Table contents for LUT0..Specifies the Truth Table contents for LUT25 */
/*! @{ */

#define PLU_LUT_TRUTH_LUTn_TRUTH_MASK            (0xFFFFFFFFU)
#define PLU_LUT_TRUTH_LUTn_TRUTH_SHIFT           (0U)
/*! LUTn_TRUTH - Specifies the Truth Table contents for LUT25.. */
#define PLU_LUT_TRUTH_LUTn_TRUTH(x)              (((uint32_t)(((uint32_t)(x)) << PLU_LUT_TRUTH_LUTn_TRUTH_SHIFT)) & PLU_LUT_TRUTH_LUTn_TRUTH_MASK)
/*! @} */

/* The count of PLU_LUT_TRUTH */
#define PLU_LUT_TRUTH_COUNT                      (26U)

/*! @name OUTPUTS - Provides the current state of the 8 designated PLU Outputs. */
/*! @{ */

#define PLU_OUTPUTS_OUTPUT_STATE_MASK            (0xFFU)
#define PLU_OUTPUTS_OUTPUT_STATE_SHIFT           (0U)
/*! OUTPUT_STATE - Provides the current state of the 8 designated PLU Outputs.. */
#define PLU_OUTPUTS_OUTPUT_STATE(x)              (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUTS_OUTPUT_STATE_SHIFT)) & PLU_OUTPUTS_OUTPUT_STATE_MASK)
/*! @} */

/*! @name OUTPUT_MUX - Selects the source to be connected to PLU Output 0..Selects the source to be connected to PLU Output 7 */
/*! @{ */

#define PLU_OUTPUT_MUX_OUTPUTn_MASK              (0x1FU)
#define PLU_OUTPUT_MUX_OUTPUTn_SHIFT             (0U)
/*! OUTPUTn - Selects the source to be connected to PLU Output 7.
 *  0b00000..The PLU output 0.
 *  0b00001..The PLU output 1.
 *  0b00010..The PLU output 2.
 *  0b00011..The PLU output 3.
 *  0b00100..The PLU output 4.
 *  0b00101..The PLU output 5.
 *  0b00110..The PLU output 6.
 *  0b00111..The PLU output 7.
 *  0b01000..The PLU output 8.
 *  0b01001..The PLU output 9.
 *  0b01010..The PLU output 10.
 *  0b01011..The PLU output 11.
 *  0b01100..The PLU output 12.
 *  0b01101..The PLU output 13.
 *  0b01110..The PLU output 14.
 *  0b01111..The PLU output 15.
 *  0b10000..The PLU output 16.
 *  0b10001..The PLU output 17.
 *  0b10010..The PLU output 18.
 *  0b10011..The PLU output 19.
 *  0b10100..The PLU output 20.
 *  0b10101..The PLU output 21.
 *  0b10110..The PLU output 22.
 *  0b10111..The PLU output 23.
 *  0b11000..The PLU output 24.
 *  0b11001..The PLU output 25.
 *  0b11010..state(0).
 *  0b11011..state(1).
 *  0b11100..state(2).
 *  0b11101..state(3).
 */
#define PLU_OUTPUT_MUX_OUTPUTn(x)                (((uint32_t)(((uint32_t)(x)) << PLU_OUTPUT_MUX_OUTPUTn_SHIFT)) & PLU_OUTPUT_MUX_OUTPUTn_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLU_Register_Masks */


/*!
 * @}
 */ /* end of group PLU_Peripheral_Access_Layer */


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


#endif  /* PERI_PLU_H_ */

