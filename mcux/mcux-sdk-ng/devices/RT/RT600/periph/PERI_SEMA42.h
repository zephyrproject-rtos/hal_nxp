/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SEMA42
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SEMA42.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SEMA42
 *
 * CMSIS Peripheral Access Layer for SEMA42
 */

#if !defined(PERI_SEMA42_H_)
#define PERI_SEMA42_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
   -- SEMA42 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Peripheral_Access_Layer SEMA42 Peripheral Access Layer
 * @{
 */

/** SEMA42 - Register Layout Typedef */
typedef struct {
  __IO uint8_t GATE3;                              /**< Semphores2 Gate n, offset: 0x0 */
  __IO uint8_t GATE2;                              /**< Semphores2 Gate n, offset: 0x1 */
  __IO uint8_t GATE1;                              /**< Semphores2 Gate n, offset: 0x2 */
  __IO uint8_t GATE0;                              /**< Semphores2 Gate n, offset: 0x3 */
  __IO uint8_t GATE7;                              /**< Semphores2 Gate n, offset: 0x4 */
  __IO uint8_t GATE6;                              /**< Semphores2 Gate n, offset: 0x5 */
  __IO uint8_t GATE5;                              /**< Semphores2 Gate n, offset: 0x6 */
  __IO uint8_t GATE4;                              /**< Semphores2 Gate n, offset: 0x7 */
  __IO uint8_t GATE11;                             /**< Semphores2 Gate n, offset: 0x8 */
  __IO uint8_t GATE10;                             /**< Semphores2 Gate n, offset: 0x9 */
  __IO uint8_t GATE9;                              /**< Semphores2 Gate n, offset: 0xA */
  __IO uint8_t GATE8;                              /**< Semphores2 Gate n, offset: 0xB */
  __IO uint8_t GATE15;                             /**< Semphores2 Gate n, offset: 0xC */
  __IO uint8_t GATE14;                             /**< Semphores2 Gate n, offset: 0xD */
  __IO uint8_t GATE13;                             /**< Semphores2 Gate n, offset: 0xE */
  __IO uint8_t GATE12;                             /**< Semphores2 Gate n, offset: 0xF */
       uint8_t RESERVED_0[50];
  union {                                          /* offset: 0x42 */
    __I  uint16_t RSTGT_R;                           /**< Reset Gate Read, offset: 0x42 */
    __O  uint16_t RSTGT_W;                           /**< Reset Gate Write, offset: 0x42 */
  };
} SEMA42_Type;

/* ----------------------------------------------------------------------------
   -- SEMA42 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SEMA42_Register_Masks SEMA42 Register Masks
 * @{
 */

/*! @name GATE3 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE3_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE3_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE3_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE3_GTFSM_SHIFT)) & SEMA42_GATE3_GTFSM_MASK)
/*! @} */

/*! @name GATE2 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE2_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE2_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE2_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE2_GTFSM_SHIFT)) & SEMA42_GATE2_GTFSM_MASK)
/*! @} */

/*! @name GATE1 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE1_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE1_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE1_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE1_GTFSM_SHIFT)) & SEMA42_GATE1_GTFSM_MASK)
/*! @} */

/*! @name GATE0 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE0_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE0_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE0_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE0_GTFSM_SHIFT)) & SEMA42_GATE0_GTFSM_MASK)
/*! @} */

/*! @name GATE7 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE7_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE7_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE7_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE7_GTFSM_SHIFT)) & SEMA42_GATE7_GTFSM_MASK)
/*! @} */

/*! @name GATE6 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE6_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE6_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE6_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE6_GTFSM_SHIFT)) & SEMA42_GATE6_GTFSM_MASK)
/*! @} */

/*! @name GATE5 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE5_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE5_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE5_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE5_GTFSM_SHIFT)) & SEMA42_GATE5_GTFSM_MASK)
/*! @} */

/*! @name GATE4 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE4_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE4_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE4_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE4_GTFSM_SHIFT)) & SEMA42_GATE4_GTFSM_MASK)
/*! @} */

/*! @name GATE11 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE11_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE11_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE11_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE11_GTFSM_SHIFT)) & SEMA42_GATE11_GTFSM_MASK)
/*! @} */

/*! @name GATE10 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE10_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE10_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE10_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE10_GTFSM_SHIFT)) & SEMA42_GATE10_GTFSM_MASK)
/*! @} */

/*! @name GATE9 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE9_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE9_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE9_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE9_GTFSM_SHIFT)) & SEMA42_GATE9_GTFSM_MASK)
/*! @} */

/*! @name GATE8 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE8_GTFSM_MASK                  (0xFU)
#define SEMA42_GATE8_GTFSM_SHIFT                 (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE8_GTFSM(x)                    (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE8_GTFSM_SHIFT)) & SEMA42_GATE8_GTFSM_MASK)
/*! @} */

/*! @name GATE15 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE15_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE15_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE15_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE15_GTFSM_SHIFT)) & SEMA42_GATE15_GTFSM_MASK)
/*! @} */

/*! @name GATE14 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE14_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE14_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE14_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE14_GTFSM_SHIFT)) & SEMA42_GATE14_GTFSM_MASK)
/*! @} */

/*! @name GATE13 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE13_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE13_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE13_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE13_GTFSM_SHIFT)) & SEMA42_GATE13_GTFSM_MASK)
/*! @} */

/*! @name GATE12 - Semphores2 Gate n */
/*! @{ */

#define SEMA42_GATE12_GTFSM_MASK                 (0xFU)
#define SEMA42_GATE12_GTFSM_SHIFT                (0U)
/*! GTFSM - ate Finite State Machine. The hardware gate is maintained in a 16-state implementation
 *  0b0000..The gate is unlocked (free).
 *  0b0001..The gate has been locked by processor 0.
 *  0b0010..The gate has been locked by processor 1.
 */
#define SEMA42_GATE12_GTFSM(x)                   (((uint8_t)(((uint8_t)(x)) << SEMA42_GATE12_GTFSM_SHIFT)) & SEMA42_GATE12_GTFSM_MASK)
/*! @} */

/*! @name RSTGT_R - Reset Gate Read */
/*! @{ */

#define SEMA42_RSTGT_R_RSTGTN_MASK               (0xFFU)
#define SEMA42_RSTGT_R_RSTGTN_SHIFT              (0U)
/*! RSTGTN - RSTGTN */
#define SEMA42_RSTGT_R_RSTGTN(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGTN_SHIFT)) & SEMA42_RSTGT_R_RSTGTN_MASK)

#define SEMA42_RSTGT_R_RSTGMS_MASK               (0xF00U)
#define SEMA42_RSTGT_R_RSTGMS_SHIFT              (8U)
/*! RSTGMS - RSTGMS */
#define SEMA42_RSTGT_R_RSTGMS(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGMS_SHIFT)) & SEMA42_RSTGT_R_RSTGMS_MASK)

#define SEMA42_RSTGT_R_RSTGSM_MASK               (0x3000U)
#define SEMA42_RSTGT_R_RSTGSM_SHIFT              (12U)
/*! RSTGSM - RSTGSM
 *  0b00..Idle, waiting for the first data pattern write.
 *  0b01..Waiting for the second data pattern write.
 *  0b10..The 2-write sequence has completed. Generate the specified gate reset(s). After the reset is performed,
 *        this machine returns to the idle (waiting for first data pattern write) state. The "01" state persists
 *        for only one clock cycle. Software cannot observe this state.
 *  0b11..This state encoding is never used and therefore reserved.
 */
#define SEMA42_RSTGT_R_RSTGSM(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_RSTGSM_SHIFT)) & SEMA42_RSTGT_R_RSTGSM_MASK)

#define SEMA42_RSTGT_R_ROZ_MASK                  (0xC000U)
#define SEMA42_RSTGT_R_ROZ_SHIFT                 (14U)
/*! ROZ - ROZ */
#define SEMA42_RSTGT_R_ROZ(x)                    (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_R_ROZ_SHIFT)) & SEMA42_RSTGT_R_ROZ_MASK)
/*! @} */

/*! @name RSTGT_W - Reset Gate Write */
/*! @{ */

#define SEMA42_RSTGT_W_RSTGTN_MASK               (0xFFU)
#define SEMA42_RSTGT_W_RSTGTN_SHIFT              (0U)
/*! RSTGTN - RSTGTN */
#define SEMA42_RSTGT_W_RSTGTN(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_W_RSTGTN_SHIFT)) & SEMA42_RSTGT_W_RSTGTN_MASK)

#define SEMA42_RSTGT_W_RSTGDP_MASK               (0xFF00U)
#define SEMA42_RSTGT_W_RSTGDP_SHIFT              (8U)
/*! RSTGDP - RSTGDP */
#define SEMA42_RSTGT_W_RSTGDP(x)                 (((uint16_t)(((uint16_t)(x)) << SEMA42_RSTGT_W_RSTGDP_SHIFT)) & SEMA42_RSTGT_W_RSTGDP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SEMA42_Register_Masks */


/*!
 * @}
 */ /* end of group SEMA42_Peripheral_Access_Layer */


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


#endif  /* PERI_SEMA42_H_ */

