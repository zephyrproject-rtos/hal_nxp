/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPC
 *
 * CMSIS Peripheral Access Layer for GPC
 */

#if !defined(PERI_GPC_H_)
#define PERI_GPC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
   -- GPC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Peripheral_Access_Layer GPC Peripheral Access Layer
 * @{
 */

/** GPC - Size of Registers Arrays */
#define GPC_IMR_COUNT                             4u
#define GPC_ISR_COUNT                             4u

/** GPC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CNTR;                              /**< GPC Interface control register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t IMR[GPC_IMR_COUNT];                /**< IRQ masking register 1..IRQ masking register 4, array offset: 0x8, array step: 0x4 */
  __I  uint32_t ISR[GPC_ISR_COUNT];                /**< IRQ status resister 1..IRQ status resister 4, array offset: 0x18, array step: 0x4 */
       uint8_t RESERVED_1[12];
  __IO uint32_t IMR5;                              /**< IRQ masking register 5, offset: 0x34 */
  __I  uint32_t ISR5;                              /**< IRQ status resister 5, offset: 0x38 */
} GPC_Type;

/* ----------------------------------------------------------------------------
   -- GPC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPC_Register_Masks GPC Register Masks
 * @{
 */

/*! @name CNTR - GPC Interface control register */
/*! @{ */

#define GPC_CNTR_MEGA_PDN_REQ_MASK               (0x4U)
#define GPC_CNTR_MEGA_PDN_REQ_SHIFT              (2U)
/*! MEGA_PDN_REQ
 *  0b0..No Request
 *  0b1..Request power down sequence
 */
#define GPC_CNTR_MEGA_PDN_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_CNTR_MEGA_PDN_REQ_SHIFT)) & GPC_CNTR_MEGA_PDN_REQ_MASK)

#define GPC_CNTR_MEGA_PUP_REQ_MASK               (0x8U)
#define GPC_CNTR_MEGA_PUP_REQ_SHIFT              (3U)
/*! MEGA_PUP_REQ
 *  0b0..No Request
 *  0b1..Request power up sequence
 */
#define GPC_CNTR_MEGA_PUP_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << GPC_CNTR_MEGA_PUP_REQ_SHIFT)) & GPC_CNTR_MEGA_PUP_REQ_MASK)

#define GPC_CNTR_PDRAM0_PGE_MASK                 (0x400000U)
#define GPC_CNTR_PDRAM0_PGE_SHIFT                (22U)
/*! PDRAM0_PGE
 *  0b0..FlexRAM PDRAM0 domain will keep power even if the CPU core is powered down.
 *  0b1..FlexRAM PDRAM0 domain will be powered down when the CPU core is powered down..
 */
#define GPC_CNTR_PDRAM0_PGE(x)                   (((uint32_t)(((uint32_t)(x)) << GPC_CNTR_PDRAM0_PGE_SHIFT)) & GPC_CNTR_PDRAM0_PGE_MASK)
/*! @} */

/*! @name IMR - IRQ masking register 1..IRQ masking register 4 */
/*! @{ */

#define GPC_IMR_IMR1_MASK                        (0xFFFFFFFFU)
#define GPC_IMR_IMR1_SHIFT                       (0U)
#define GPC_IMR_IMR1(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_IMR_IMR1_SHIFT)) & GPC_IMR_IMR1_MASK)

#define GPC_IMR_IMR2_MASK                        (0xFFFFFFFFU)
#define GPC_IMR_IMR2_SHIFT                       (0U)
#define GPC_IMR_IMR2(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_IMR_IMR2_SHIFT)) & GPC_IMR_IMR2_MASK)

#define GPC_IMR_IMR3_MASK                        (0xFFFFFFFFU)
#define GPC_IMR_IMR3_SHIFT                       (0U)
#define GPC_IMR_IMR3(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_IMR_IMR3_SHIFT)) & GPC_IMR_IMR3_MASK)

#define GPC_IMR_IMR4_MASK                        (0xFFFFFFFFU)
#define GPC_IMR_IMR4_SHIFT                       (0U)
#define GPC_IMR_IMR4(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_IMR_IMR4_SHIFT)) & GPC_IMR_IMR4_MASK)
/*! @} */

/*! @name ISR - IRQ status resister 1..IRQ status resister 4 */
/*! @{ */

#define GPC_ISR_ISR1_MASK                        (0xFFFFFFFFU)
#define GPC_ISR_ISR1_SHIFT                       (0U)
#define GPC_ISR_ISR1(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_ISR_ISR1_SHIFT)) & GPC_ISR_ISR1_MASK)

#define GPC_ISR_ISR2_MASK                        (0xFFFFFFFFU)
#define GPC_ISR_ISR2_SHIFT                       (0U)
#define GPC_ISR_ISR2(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_ISR_ISR2_SHIFT)) & GPC_ISR_ISR2_MASK)

#define GPC_ISR_ISR3_MASK                        (0xFFFFFFFFU)
#define GPC_ISR_ISR3_SHIFT                       (0U)
#define GPC_ISR_ISR3(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_ISR_ISR3_SHIFT)) & GPC_ISR_ISR3_MASK)

#define GPC_ISR_ISR4_MASK                        (0xFFFFFFFFU)
#define GPC_ISR_ISR4_SHIFT                       (0U)
#define GPC_ISR_ISR4(x)                          (((uint32_t)(((uint32_t)(x)) << GPC_ISR_ISR4_SHIFT)) & GPC_ISR_ISR4_MASK)
/*! @} */

/*! @name IMR5 - IRQ masking register 5 */
/*! @{ */

#define GPC_IMR5_IMR5_MASK                       (0xFFFFFFFFU)
#define GPC_IMR5_IMR5_SHIFT                      (0U)
#define GPC_IMR5_IMR5(x)                         (((uint32_t)(((uint32_t)(x)) << GPC_IMR5_IMR5_SHIFT)) & GPC_IMR5_IMR5_MASK)
/*! @} */

/*! @name ISR5 - IRQ status resister 5 */
/*! @{ */

#define GPC_ISR5_ISR5_MASK                       (0xFFFFFFFFU)
#define GPC_ISR5_ISR5_SHIFT                      (0U)
#define GPC_ISR5_ISR5(x)                         (((uint32_t)(((uint32_t)(x)) << GPC_ISR5_ISR5_SHIFT)) & GPC_ISR5_ISR5_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPC_Register_Masks */


/*!
 * @}
 */ /* end of group GPC_Peripheral_Access_Layer */


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


#endif  /* PERI_GPC_H_ */

