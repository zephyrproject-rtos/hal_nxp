/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WAKEUP_DMA_CRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
 * @file PERI_WAKEUP_DMA_CRC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WAKEUP_DMA_CRC
 *
 * CMSIS Peripheral Access Layer for WAKEUP_DMA_CRC
 */

#if !defined(PERI_WAKEUP_DMA_CRC_H_)
#define PERI_WAKEUP_DMA_CRC_H_                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- WAKEUP_DMA_CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_DMA_CRC_Peripheral_Access_Layer WAKEUP_DMA_CRC Peripheral Access Layer
 * @{
 */

/** WAKEUP_DMA_CRC - Size of Registers Arrays */
#define WAKEUP_DMA_CRC_CONTROL_REGISTER_COUNT     8u

/** WAKEUP_DMA_CRC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GEC;                               /**< Global Enable CRC Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x10 */
    __IO uint32_t CTL;                               /**< CRC Control Register, array offset: 0x10, array step: 0x10 */
    __IO uint32_t ICRC;                              /**< Initial CRC Value Register, array offset: 0x14, array step: 0x10 */
    __I  uint32_t FCRC;                              /**< Final CRC Value Register, array offset: 0x18, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } CONTROL_REGISTER[WAKEUP_DMA_CRC_CONTROL_REGISTER_COUNT];
} WAKEUP_DMA_CRC_Type;

/* ----------------------------------------------------------------------------
   -- WAKEUP_DMA_CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WAKEUP_DMA_CRC_Register_Masks WAKEUP_DMA_CRC Register Masks
 * @{
 */

/*! @name GEC - Global Enable CRC Register */
/*! @{ */

#define WAKEUP_DMA_CRC_GEC_GBL_EN_MASK           (0x1U)
#define WAKEUP_DMA_CRC_GEC_GBL_EN_SHIFT          (0U)
/*! GBL_EN - Global Enable bit
 *  0b0..Disable CRC in all channels.
 *  0b1..Enable CRC in all channels.
 */
#define WAKEUP_DMA_CRC_GEC_GBL_EN(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_GEC_GBL_EN_SHIFT)) & WAKEUP_DMA_CRC_GEC_GBL_EN_MASK)

#define WAKEUP_DMA_CRC_GEC_SWAP_BYTE_MASK        (0x80U)
#define WAKEUP_DMA_CRC_GEC_SWAP_BYTE_SHIFT       (7U)
/*! SWAP_BYTE - Swap Byte
 *  0b0..Do not swap.
 *  0b1..Byte-wise swap on the input data.
 */
#define WAKEUP_DMA_CRC_GEC_SWAP_BYTE(x)          (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_GEC_SWAP_BYTE_SHIFT)) & WAKEUP_DMA_CRC_GEC_SWAP_BYTE_MASK)
/*! @} */

/*! @name CTL - CRC Control Register */
/*! @{ */

#define WAKEUP_DMA_CRC_CTL_CH_SEL_MASK           (0x3FU)
#define WAKEUP_DMA_CRC_CTL_CH_SEL_SHIFT          (0U)
/*! CH_SEL - Channel Select
 *  0b000000..Select Channel 0.
 *  0b000001..Select Channel 1.
 *  0b111110..Select Channel 62.
 *  0b111111..Select Channel 63.
 */
#define WAKEUP_DMA_CRC_CTL_CH_SEL(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_CH_SEL_SHIFT)) & WAKEUP_DMA_CRC_CTL_CH_SEL_MASK)

#define WAKEUP_DMA_CRC_CTL_POLY_SEL_MASK         (0x700U)
#define WAKEUP_DMA_CRC_CTL_POLY_SEL_SHIFT        (8U)
/*! POLY_SEL - Polynomial Select
 *  0b000..Select CRC-32 0x04C11DB7.
 *  0b001..Select CRC-32 0x1EDC6F41.
 *  0b010..Select CRC-32 0xF4ACFB13.
 *  0b011..Select CRC-16 0x1021.
 *  0b100..Select CRC-8 0x2F.
 *  0b101..Select CRC-8 0x1D.
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define WAKEUP_DMA_CRC_CTL_POLY_SEL(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_POLY_SEL_SHIFT)) & WAKEUP_DMA_CRC_CTL_POLY_SEL_MASK)

#define WAKEUP_DMA_CRC_CTL_CS_XOR_MASK           (0x1000U)
#define WAKEUP_DMA_CRC_CTL_CS_XOR_SHIFT          (12U)
/*! CS_XOR
 *  0b0..Do not apply the XOR.
 *  0b1..Perform XOR of FFFFFFFFh to the checksum for CRC-32, FFFFh for CRC-16, and FFh for CRC-8.
 */
#define WAKEUP_DMA_CRC_CTL_CS_XOR(x)             (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_CS_XOR_SHIFT)) & WAKEUP_DMA_CRC_CTL_CS_XOR_MASK)

#define WAKEUP_DMA_CRC_CTL_CS_SWAP_MASK          (0x2000U)
#define WAKEUP_DMA_CRC_CTL_CS_SWAP_SHIFT         (13U)
/*! CS_SWAP
 *  0b0..Do not swap.
 *  0b1..Perform bit-wise swap within each byte of the checksum result.
 */
#define WAKEUP_DMA_CRC_CTL_CS_SWAP(x)            (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_CS_SWAP_SHIFT)) & WAKEUP_DMA_CRC_CTL_CS_SWAP_MASK)

#define WAKEUP_DMA_CRC_CTL_SWAP_BIT_MASK         (0x4000U)
#define WAKEUP_DMA_CRC_CTL_SWAP_BIT_SHIFT        (14U)
/*! SWAP_BIT - Swap Bit
 *  0b0..Do not swap.
 *  0b1..Perform bit-wise swap within each byte of the input data.
 */
#define WAKEUP_DMA_CRC_CTL_SWAP_BIT(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_SWAP_BIT_SHIFT)) & WAKEUP_DMA_CRC_CTL_SWAP_BIT_MASK)

#define WAKEUP_DMA_CRC_CTL_INIT_SEL_MASK         (0x8000U)
#define WAKEUP_DMA_CRC_CTL_INIT_SEL_SHIFT        (15U)
/*! INIT_SEL - Initial values of the CRC
 *  0b0..Initialize CRC with the content of the Initial CRC Value Register (ICRC).
 *  0b1..Continue accumulating previous CRC values stored in Final CRC Value Register (FCRC).
 */
#define WAKEUP_DMA_CRC_CTL_INIT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_INIT_SEL_SHIFT)) & WAKEUP_DMA_CRC_CTL_INIT_SEL_MASK)

#define WAKEUP_DMA_CRC_CTL_MODE_MASK             (0x70000U)
#define WAKEUP_DMA_CRC_CTL_MODE_SHIFT            (16U)
/*! MODE - CRC Mode
 *  0b000..Normal CRC Mode. All other combinations are invalid.
 */
#define WAKEUP_DMA_CRC_CTL_MODE(x)               (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_MODE_SHIFT)) & WAKEUP_DMA_CRC_CTL_MODE_MASK)

#define WAKEUP_DMA_CRC_CTL_EN_MASK               (0x80000000U)
#define WAKEUP_DMA_CRC_CTL_EN_SHIFT              (31U)
/*! EN - CRC Logic
 *  0b0..Disable CRC.
 *  0b1..Enable CRC.
 */
#define WAKEUP_DMA_CRC_CTL_EN(x)                 (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_CTL_EN_SHIFT)) & WAKEUP_DMA_CRC_CTL_EN_MASK)
/*! @} */

/* The count of WAKEUP_DMA_CRC_CTL */
#define WAKEUP_DMA_CRC_CTL_COUNT                 (8U)

/*! @name ICRC - Initial CRC Value Register */
/*! @{ */

#define WAKEUP_DMA_CRC_ICRC_INI_CRC_VAL_MASK     (0xFFFFFFFFU)
#define WAKEUP_DMA_CRC_ICRC_INI_CRC_VAL_SHIFT    (0U)
/*! INI_CRC_VAL - Initial CRC Value */
#define WAKEUP_DMA_CRC_ICRC_INI_CRC_VAL(x)       (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_ICRC_INI_CRC_VAL_SHIFT)) & WAKEUP_DMA_CRC_ICRC_INI_CRC_VAL_MASK)
/*! @} */

/* The count of WAKEUP_DMA_CRC_ICRC */
#define WAKEUP_DMA_CRC_ICRC_COUNT                (8U)

/*! @name FCRC - Final CRC Value Register */
/*! @{ */

#define WAKEUP_DMA_CRC_FCRC_CHKSUM_VAL_MASK      (0xFFFFFFFFU)
#define WAKEUP_DMA_CRC_FCRC_CHKSUM_VAL_SHIFT     (0U)
/*! CHKSUM_VAL - Final CRC Value */
#define WAKEUP_DMA_CRC_FCRC_CHKSUM_VAL(x)        (((uint32_t)(((uint32_t)(x)) << WAKEUP_DMA_CRC_FCRC_CHKSUM_VAL_SHIFT)) & WAKEUP_DMA_CRC_FCRC_CHKSUM_VAL_MASK)
/*! @} */

/* The count of WAKEUP_DMA_CRC_FCRC */
#define WAKEUP_DMA_CRC_FCRC_COUNT                (8U)


/*!
 * @}
 */ /* end of group WAKEUP_DMA_CRC_Register_Masks */


/*!
 * @}
 */ /* end of group WAKEUP_DMA_CRC_Peripheral_Access_Layer */


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


#endif  /* PERI_WAKEUP_DMA_CRC_H_ */

