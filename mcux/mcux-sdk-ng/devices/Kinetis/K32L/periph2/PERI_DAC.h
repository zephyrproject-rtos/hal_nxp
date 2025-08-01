/*
** ###################################################################
**     Processors:          K32L2B11VFM0A
**                          K32L2B11VFT0A
**                          K32L2B11VLH0A
**                          K32L2B11VMP0A
**                          K32L2B21VFM0A
**                          K32L2B21VFT0A
**                          K32L2B21VLH0A
**                          K32L2B21VMP0A
**                          K32L2B31VFM0A
**                          K32L2B31VFT0A
**                          K32L2B31VLH0A
**                          K32L2B31VMP0A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DAC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-07-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DAC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DAC
 *
 * CMSIS Peripheral Access Layer for DAC
 */

#if !defined(PERI_DAC_H_)
#define PERI_DAC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2B11VFM0A) || defined(CPU_K32L2B11VFT0A) || defined(CPU_K32L2B11VLH0A) || defined(CPU_K32L2B11VMP0A))
#include "K32L2B11A_COMMON.h"
#elif (defined(CPU_K32L2B21VFM0A) || defined(CPU_K32L2B21VFT0A) || defined(CPU_K32L2B21VLH0A) || defined(CPU_K32L2B21VMP0A))
#include "K32L2B21A_COMMON.h"
#elif (defined(CPU_K32L2B31VFM0A) || defined(CPU_K32L2B31VFT0A) || defined(CPU_K32L2B31VLH0A) || defined(CPU_K32L2B31VMP0A))
#include "K32L2B31A_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Size of Registers Arrays */
#define DAC_DAT_COUNT                             2u

/** DAC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x2 */
    __IO uint8_t DATL;                               /**< DAC Data Low Register, array offset: 0x0, array step: 0x2 */
    __IO uint8_t DATH;                               /**< DAC Data High Register, array offset: 0x1, array step: 0x2 */
  } DAT[DAC_DAT_COUNT];
       uint8_t RESERVED_0[28];
  __IO uint8_t SR;                                 /**< DAC Status Register, offset: 0x20 */
  __IO uint8_t C0;                                 /**< DAC Control Register, offset: 0x21 */
  __IO uint8_t C1;                                 /**< DAC Control Register 1, offset: 0x22 */
  __IO uint8_t C2;                                 /**< DAC Control Register 2, offset: 0x23 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name DATL - DAC Data Low Register */
/*! @{ */

#define DAC_DATL_DATA0_MASK                      (0xFFU)
#define DAC_DATL_DATA0_SHIFT                     (0U)
/*! DATA0 - DATA0 */
#define DAC_DATL_DATA0(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_DATL_DATA0_SHIFT)) & DAC_DATL_DATA0_MASK)
/*! @} */

/* The count of DAC_DATL */
#define DAC_DATL_COUNT                           (2U)

/*! @name DATH - DAC Data High Register */
/*! @{ */

#define DAC_DATH_DATA1_MASK                      (0xFU)
#define DAC_DATH_DATA1_SHIFT                     (0U)
/*! DATA1 - DATA1 */
#define DAC_DATH_DATA1(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_DATH_DATA1_SHIFT)) & DAC_DATH_DATA1_MASK)
/*! @} */

/* The count of DAC_DATH */
#define DAC_DATH_COUNT                           (2U)

/*! @name SR - DAC Status Register */
/*! @{ */

#define DAC_SR_DACBFRPBF_MASK                    (0x1U)
#define DAC_SR_DACBFRPBF_SHIFT                   (0U)
/*! DACBFRPBF - DAC Buffer Read Pointer Bottom Position Flag
 *  0b0..The DAC buffer read pointer is not equal to C2[DACBFUP].
 *  0b1..The DAC buffer read pointer is equal to C2[DACBFUP].
 */
#define DAC_SR_DACBFRPBF(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_SR_DACBFRPBF_SHIFT)) & DAC_SR_DACBFRPBF_MASK)

#define DAC_SR_DACBFRPTF_MASK                    (0x2U)
#define DAC_SR_DACBFRPTF_SHIFT                   (1U)
/*! DACBFRPTF - DAC Buffer Read Pointer Top Position Flag
 *  0b0..The DAC buffer read pointer is not zero.
 *  0b1..The DAC buffer read pointer is zero.
 */
#define DAC_SR_DACBFRPTF(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_SR_DACBFRPTF_SHIFT)) & DAC_SR_DACBFRPTF_MASK)
/*! @} */

/*! @name C0 - DAC Control Register */
/*! @{ */

#define DAC_C0_DACBBIEN_MASK                     (0x1U)
#define DAC_C0_DACBBIEN_SHIFT                    (0U)
/*! DACBBIEN - DAC Buffer Read Pointer Bottom Flag Interrupt Enable
 *  0b0..The DAC buffer read pointer bottom flag interrupt is disabled.
 *  0b1..The DAC buffer read pointer bottom flag interrupt is enabled.
 */
#define DAC_C0_DACBBIEN(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACBBIEN_SHIFT)) & DAC_C0_DACBBIEN_MASK)

#define DAC_C0_DACBTIEN_MASK                     (0x2U)
#define DAC_C0_DACBTIEN_SHIFT                    (1U)
/*! DACBTIEN - DAC Buffer Read Pointer Top Flag Interrupt Enable
 *  0b0..The DAC buffer read pointer top flag interrupt is disabled.
 *  0b1..The DAC buffer read pointer top flag interrupt is enabled.
 */
#define DAC_C0_DACBTIEN(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACBTIEN_SHIFT)) & DAC_C0_DACBTIEN_MASK)

#define DAC_C0_LPEN_MASK                         (0x8U)
#define DAC_C0_LPEN_SHIFT                        (3U)
/*! LPEN - DAC Low Power Control
 *  0b0..High-Power mode
 *  0b1..Low-Power mode
 */
#define DAC_C0_LPEN(x)                           (((uint8_t)(((uint8_t)(x)) << DAC_C0_LPEN_SHIFT)) & DAC_C0_LPEN_MASK)

#define DAC_C0_DACSWTRG_MASK                     (0x10U)
#define DAC_C0_DACSWTRG_SHIFT                    (4U)
/*! DACSWTRG - DAC Software Trigger
 *  0b0..The DAC soft trigger is not valid.
 *  0b1..The DAC soft trigger is valid.
 */
#define DAC_C0_DACSWTRG(x)                       (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACSWTRG_SHIFT)) & DAC_C0_DACSWTRG_MASK)

#define DAC_C0_DACTRGSEL_MASK                    (0x20U)
#define DAC_C0_DACTRGSEL_SHIFT                   (5U)
/*! DACTRGSEL - DAC Trigger Select
 *  0b0..The DAC hardware trigger is selected.
 *  0b1..The DAC software trigger is selected.
 */
#define DAC_C0_DACTRGSEL(x)                      (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACTRGSEL_SHIFT)) & DAC_C0_DACTRGSEL_MASK)

#define DAC_C0_DACRFS_MASK                       (0x40U)
#define DAC_C0_DACRFS_SHIFT                      (6U)
/*! DACRFS - DAC Reference Select
 *  0b0..The DAC selects DACREF_1 as the reference voltage.
 *  0b1..The DAC selects DACREF_2 as the reference voltage.
 */
#define DAC_C0_DACRFS(x)                         (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACRFS_SHIFT)) & DAC_C0_DACRFS_MASK)

#define DAC_C0_DACEN_MASK                        (0x80U)
#define DAC_C0_DACEN_SHIFT                       (7U)
/*! DACEN - DAC Enable
 *  0b0..The DAC system is disabled.
 *  0b1..The DAC system is enabled.
 */
#define DAC_C0_DACEN(x)                          (((uint8_t)(((uint8_t)(x)) << DAC_C0_DACEN_SHIFT)) & DAC_C0_DACEN_MASK)
/*! @} */

/*! @name C1 - DAC Control Register 1 */
/*! @{ */

#define DAC_C1_DACBFEN_MASK                      (0x1U)
#define DAC_C1_DACBFEN_SHIFT                     (0U)
/*! DACBFEN - DAC Buffer Enable
 *  0b0..Buffer read pointer is disabled. The converted data is always the first word of the buffer.
 *  0b1..Buffer read pointer is enabled. The converted data is the word that the read pointer points to. It means
 *       converted data can be from any word of the buffer.
 */
#define DAC_C1_DACBFEN(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C1_DACBFEN_SHIFT)) & DAC_C1_DACBFEN_MASK)

#define DAC_C1_DACBFMD_MASK                      (0x6U)
#define DAC_C1_DACBFMD_SHIFT                     (1U)
/*! DACBFMD - DAC Buffer Work Mode Select
 *  0b00..Normal mode
 *  0b01..Reserved
 *  0b10..One-Time Scan mode
 *  0b11..FIFO mode
 */
#define DAC_C1_DACBFMD(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C1_DACBFMD_SHIFT)) & DAC_C1_DACBFMD_MASK)

#define DAC_C1_DMAEN_MASK                        (0x80U)
#define DAC_C1_DMAEN_SHIFT                       (7U)
/*! DMAEN - DMA Enable Select
 *  0b0..DMA is disabled.
 *  0b1..DMA is enabled. When DMA is enabled, the DMA request will be generated by original interrupts. The
 *       interrupts will not be presented on this module at the same time.
 */
#define DAC_C1_DMAEN(x)                          (((uint8_t)(((uint8_t)(x)) << DAC_C1_DMAEN_SHIFT)) & DAC_C1_DMAEN_MASK)
/*! @} */

/*! @name C2 - DAC Control Register 2 */
/*! @{ */

#define DAC_C2_DACBFUP_MASK                      (0x1U)
#define DAC_C2_DACBFUP_SHIFT                     (0U)
/*! DACBFUP - DAC Buffer Upper Limit */
#define DAC_C2_DACBFUP(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C2_DACBFUP_SHIFT)) & DAC_C2_DACBFUP_MASK)

#define DAC_C2_DACBFRP_MASK                      (0x10U)
#define DAC_C2_DACBFRP_SHIFT                     (4U)
/*! DACBFRP - DAC Buffer Read Pointer */
#define DAC_C2_DACBFRP(x)                        (((uint8_t)(((uint8_t)(x)) << DAC_C2_DACBFRP_SHIFT)) & DAC_C2_DACBFRP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_DAC_H_ */

