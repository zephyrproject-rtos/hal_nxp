/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PUF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PUF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PUF
 *
 * CMSIS Peripheral Access Layer for PUF
 */

#if !defined(PERI_PUF_H_)
#define PERI_PUF_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- PUF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Peripheral_Access_Layer PUF Peripheral Access Layer
 * @{
 */

/** PUF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  __I  uint32_t ORR;                               /**< Operation Result, offset: 0x4 */
  __IO uint32_t SR;                                /**< Status, offset: 0x8 */
  __I  uint32_t AR;                                /**< Allow, offset: 0xC */
  __IO uint32_t IER;                               /**< Interrupt Enable, offset: 0x10 */
  __IO uint32_t IMR;                               /**< Interrupt Mask, offset: 0x14 */
  __IO uint32_t ISR;                               /**< Interrupt Status, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DATA_DEST;                         /**< Data Destination, offset: 0x20 */
       uint8_t RESERVED_1[124];
  __O  uint32_t DIR;                               /**< Data Input, offset: 0xA0 */
       uint8_t RESERVED_2[4];
  __I  uint32_t DOR;                               /**< Data Output, offset: 0xA8 */
       uint8_t RESERVED_3[20];
  __IO uint32_t MISC;                              /**< Miscellaneous, offset: 0xC0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t IF_SR;                             /**< Interface Status, offset: 0xD0 */
       uint8_t RESERVED_5[8];
  __I  uint32_t PSR;                               /**< PUF Score, offset: 0xDC */
  __I  uint32_t HW_RUC0;                           /**< Hardware Restrict User Context 0, offset: 0xE0 */
  __I  uint32_t HW_RUC1;                           /**< Hardware Restrict User Context 1, offset: 0xE4 */
       uint8_t RESERVED_6[12];
  __I  uint32_t HW_INFO;                           /**< Hardware Information, offset: 0xF4 */
  __I  uint32_t HW_ID;                             /**< Hardware Identifier, offset: 0xF8 */
  __I  uint32_t HW_VER;                            /**< Hardware Version, offset: 0xFC */
  __IO uint32_t CONFIG;                            /**< PUF command blocking configuration, offset: 0x100 */
  __IO uint32_t SEC_LOCK;                          /**< Security level lock, offset: 0x104 */
  __IO uint32_t APP_CTX_MASK;                      /**< Application defined context mask, offset: 0x108 */
  __IO uint32_t PUF_MEM_CTRL;                      /**< PUF mem control, offset: 0x10C */
} PUF_Type;

/* ----------------------------------------------------------------------------
   -- PUF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PUF_Register_Masks PUF Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define PUF_CR_ZEROIZE_MASK                      (0x1U)
#define PUF_CR_ZEROIZE_SHIFT                     (0U)
/*! ZEROIZE - Zeroize operation
 *  0b0..Does not begin zeroize operation (disabled).
 *  0b1..Begins the zeroize operation (enabled).
 */
#define PUF_CR_ZEROIZE(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CR_ZEROIZE_SHIFT)) & PUF_CR_ZEROIZE_MASK)

#define PUF_CR_ENROLL_MASK                       (0x2U)
#define PUF_CR_ENROLL_SHIFT                      (1U)
/*! ENROLL - Enroll operation
 *  0b0..Does not begin enroll operation (disabled).
 *  0b1..Begins the enroll operation (enabled).
 */
#define PUF_CR_ENROLL(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_CR_ENROLL_SHIFT)) & PUF_CR_ENROLL_MASK)

#define PUF_CR_START_MASK                        (0x4U)
#define PUF_CR_START_SHIFT                       (2U)
/*! START - Start operation
 *  0b0..Does not begin start operation (disabled).
 *  0b1..Begins the start operation (enabled).
 */
#define PUF_CR_START(x)                          (((uint32_t)(((uint32_t)(x)) << PUF_CR_START_SHIFT)) & PUF_CR_START_MASK)

#define PUF_CR_RECONSTRUCT_MASK                  (0x8U)
#define PUF_CR_RECONSTRUCT_SHIFT                 (3U)
/*! RECONSTRUCT - Reconstruct operation
 *  0b0..Reconstruct operation disabled
 *  0b1..Reconstruct operation enabled
 */
#define PUF_CR_RECONSTRUCT(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_CR_RECONSTRUCT_SHIFT)) & PUF_CR_RECONSTRUCT_MASK)

#define PUF_CR_STOP_MASK                         (0x20U)
#define PUF_CR_STOP_SHIFT                        (5U)
/*! STOP - Stop operation
 *  0b0..Stop operation disabled
 *  0b1..Stop operation enabled
 */
#define PUF_CR_STOP(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_CR_STOP_SHIFT)) & PUF_CR_STOP_MASK)

#define PUF_CR_GET_KEY_MASK                      (0x40U)
#define PUF_CR_GET_KEY_SHIFT                     (6U)
/*! GET_KEY - Get Key operation
 *  0b0..Get Key operation disabled
 *  0b1..Get Key operation enabled
 */
#define PUF_CR_GET_KEY(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_CR_GET_KEY_SHIFT)) & PUF_CR_GET_KEY_MASK)

#define PUF_CR_UNWRAP_MASK                       (0x80U)
#define PUF_CR_UNWRAP_SHIFT                      (7U)
/*! UNWRAP - Unwrap operation
 *  0b0..Unwrap operation disabled
 *  0b1..Unwrap operation enabled
 */
#define PUF_CR_UNWRAP(x)                         (((uint32_t)(((uint32_t)(x)) << PUF_CR_UNWRAP_SHIFT)) & PUF_CR_UNWRAP_MASK)

#define PUF_CR_WRAP_GENERATED_RANDOM_MASK        (0x100U)
#define PUF_CR_WRAP_GENERATED_RANDOM_SHIFT       (8U)
/*! WRAP_GENERATED_RANDOM - Wrap Generated Random operation
 *  0b0..Wrap generated random operation disabled
 *  0b1..Wrap generated random operation enabled
 */
#define PUF_CR_WRAP_GENERATED_RANDOM(x)          (((uint32_t)(((uint32_t)(x)) << PUF_CR_WRAP_GENERATED_RANDOM_SHIFT)) & PUF_CR_WRAP_GENERATED_RANDOM_MASK)

#define PUF_CR_WRAP_MASK                         (0x200U)
#define PUF_CR_WRAP_SHIFT                        (9U)
/*! WRAP - Wrap operation
 *  0b0..Wrap operation disabled
 *  0b1..Wrap operation enabled
 */
#define PUF_CR_WRAP(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_CR_WRAP_SHIFT)) & PUF_CR_WRAP_MASK)

#define PUF_CR_GENERATE_RANDOM_MASK              (0x8000U)
#define PUF_CR_GENERATE_RANDOM_SHIFT             (15U)
/*! GENERATE_RANDOM - Generate Random operation
 *  0b0..Generate Random operation disabled
 *  0b1..Generate Random operation enabled
 */
#define PUF_CR_GENERATE_RANDOM(x)                (((uint32_t)(((uint32_t)(x)) << PUF_CR_GENERATE_RANDOM_SHIFT)) & PUF_CR_GENERATE_RANDOM_MASK)

#define PUF_CR_TEST_MEMORY_MASK                  (0x40000000U)
#define PUF_CR_TEST_MEMORY_SHIFT                 (30U)
/*! TEST_MEMORY - Test memory operation
 *  0b0..Test memory operation is disabled.
 *  0b1..Test memory operation is enabled.
 */
#define PUF_CR_TEST_MEMORY(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_CR_TEST_MEMORY_SHIFT)) & PUF_CR_TEST_MEMORY_MASK)

#define PUF_CR_TEST_PUF_MASK                     (0x80000000U)
#define PUF_CR_TEST_PUF_SHIFT                    (31U)
/*! TEST_PUF - Test PUF operation
 *  0b0..Test PUF operation is disabled.
 *  0b1..Test PUF operation is enabled.
 */
#define PUF_CR_TEST_PUF(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_CR_TEST_PUF_SHIFT)) & PUF_CR_TEST_PUF_MASK)
/*! @} */

/*! @name ORR - Operation Result */
/*! @{ */

#define PUF_ORR_RESULT_CODE_MASK                 (0xFFU)
#define PUF_ORR_RESULT_CODE_SHIFT                (0U)
/*! RESULT_CODE - Result code of last operation
 *  0b00000000..Indicates that the last operation was successful or operation is in progress.
 *  0b11110000..Indicates that the AC is not for the current product/version.
 *  0b11110001..Indicates that the AC in the second phase is not for the current product/version.
 *  0b11110010..Indicates that the AC is corrupted.
 *  0b11110011..Indicates that the AC in the second phase is corrupted.
 *  0b11110100..Indicates that the authentication of the provided AC failed.
 *  0b11110101..Indicates that the authentication of the provided AC failed in the second phase.
 *  0b11110110..Indicates that the SRAM PUF quality verification fails.
 *  0b11110111..Indicates that the incorrect or unsupported context is provided.
 *  0b11111000..Indicates that a data destination was set that is not allowed according to other settings and the current PUF state.
 *  0b11111111..Indicates that the PUF SRAM access has failed.
 */
#define PUF_ORR_RESULT_CODE(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_ORR_RESULT_CODE_SHIFT)) & PUF_ORR_RESULT_CODE_MASK)

#define PUF_ORR_LAST_OPERATION_MASK              (0xFF000000U)
#define PUF_ORR_LAST_OPERATION_SHIFT             (24U)
/*! LAST_OPERATION - Last operation type
 *  0b00000000..Indicates that the operation is in progress.
 *  0b00000001..Indicates that the last operation was Enroll.
 *  0b00000010..Indicates that the last operation was Start.
 *  0b00000011..Indicates that the last operation was Reconstruct
 *  0b00000101..Indicates that the last operation was Stop.
 *  0b00000110..Indicates that the last operation was Get Key.
 *  0b00000111..Indicates that the last operation was Unwrap.
 *  0b00001000..Indicates that the last operation was Wrap Generated Random.
 *  0b00001001..Indicates that the last operation was Wrap.
 *  0b00001111..Indicates that the last operation was Generate Random.
 *  0b00011110..Indicates that the last operation was Test Memory.
 *  0b00011111..Indicates that the last operation was Test PUF.
 *  0b00100000..Indicates that the last operation was Initialization.
 *  0b00101111..Indicates that the last operation was Zeroize.
 */
#define PUF_ORR_LAST_OPERATION(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ORR_LAST_OPERATION_SHIFT)) & PUF_ORR_LAST_OPERATION_MASK)
/*! @} */

/*! @name SR - Status */
/*! @{ */

#define PUF_SR_BUSY_MASK                         (0x1U)
#define PUF_SR_BUSY_SHIFT                        (0U)
/*! BUSY - Operation in progress
 *  0b0..Indicates no operation is performed and the hardware is idle
 *  0b1..Indicates the operation is in progress and the hardware is busy
 */
#define PUF_SR_BUSY(x)                           (((uint32_t)(((uint32_t)(x)) << PUF_SR_BUSY_SHIFT)) & PUF_SR_BUSY_MASK)

#define PUF_SR_OK_MASK                           (0x2U)
#define PUF_SR_OK_SHIFT                          (1U)
/*! OK - Last operation successful
 *  0b0..Resets value, no special meaning
 *  0b1..Indicates that the last operation is successful
 */
#define PUF_SR_OK(x)                             (((uint32_t)(((uint32_t)(x)) << PUF_SR_OK_SHIFT)) & PUF_SR_OK_MASK)

#define PUF_SR_ERROR_MASK                        (0x4U)
#define PUF_SR_ERROR_SHIFT                       (2U)
/*! ERROR - Last operation failed
 *  0b0..Resets value, no special meaning
 *  0b1..Indicates that the last operation failed
 */
#define PUF_SR_ERROR(x)                          (((uint32_t)(((uint32_t)(x)) << PUF_SR_ERROR_SHIFT)) & PUF_SR_ERROR_MASK)

#define PUF_SR_ZEROIZED_MASK                     (0x8U)
#define PUF_SR_ZEROIZED_SHIFT                    (3U)
/*! ZEROIZED - Zeroized or Locked state
 *  0b0..Indicates that the state is not locked
 *  0b1..Indicates that the state is zeroized or locked
 */
#define PUF_SR_ZEROIZED(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_SR_ZEROIZED_SHIFT)) & PUF_SR_ZEROIZED_MASK)

#define PUF_SR_REJECTED_MASK                     (0x10U)
#define PUF_SR_REJECTED_SHIFT                    (4U)
/*! REJECTED - Operation rejected
 *  0b0..Indicates that the last command was not rejected
 *  0b1..Indicates that the last command was rejected
 */
#define PUF_SR_REJECTED(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_SR_REJECTED_SHIFT)) & PUF_SR_REJECTED_MASK)

#define PUF_SR_DI_REQUEST_MASK                   (0x20U)
#define PUF_SR_DI_REQUEST_SHIFT                  (5U)
/*! DI_REQUEST - Indicates the request for data in transfer via the DIR register
 *  0b0..Indicates no request for data in transfer through DIR register
 *  0b1..Indicates the request for data in transfer through DIR register
 */
#define PUF_SR_DI_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_SR_DI_REQUEST_SHIFT)) & PUF_SR_DI_REQUEST_MASK)

#define PUF_SR_DO_REQUEST_MASK                   (0x40U)
#define PUF_SR_DO_REQUEST_SHIFT                  (6U)
/*! DO_REQUEST - Indicates the request for data out transfer via the DOR register
 *  0b0..Indicates no request for data out transfer through DOR register
 *  0b1..Indicates the request for data out transfer through DOR register
 */
#define PUF_SR_DO_REQUEST(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_SR_DO_REQUEST_SHIFT)) & PUF_SR_DO_REQUEST_MASK)
/*! @} */

/*! @name AR - Allow */
/*! @{ */

#define PUF_AR_ALLOW_ENROLL_MASK                 (0x2U)
#define PUF_AR_ALLOW_ENROLL_SHIFT                (1U)
/*! ALLOW_ENROLL - Enroll operation
 *  0b0..Indicates that the Enroll operation is not allowed
 *  0b1..Indicates that the Enroll operation is allowed
 */
#define PUF_AR_ALLOW_ENROLL(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_ENROLL_SHIFT)) & PUF_AR_ALLOW_ENROLL_MASK)

#define PUF_AR_ALLOW_START_MASK                  (0x4U)
#define PUF_AR_ALLOW_START_SHIFT                 (2U)
/*! ALLOW_START - Start operation
 *  0b0..Indicates that the Start operation is not allowed
 *  0b1..Indicates that the Start operation is allowed
 */
#define PUF_AR_ALLOW_START(x)                    (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_START_SHIFT)) & PUF_AR_ALLOW_START_MASK)

#define PUF_AR_ALLOW_RECONSTRUCT_MASK            (0x8U)
#define PUF_AR_ALLOW_RECONSTRUCT_SHIFT           (3U)
/*! ALLOW_RECONSTRUCT - Reconstruct operation
 *  0b0..Indicates that the Reconstruct operation is not allowed
 *  0b1..Indicates that the Reconstruct operation is allowed
 */
#define PUF_AR_ALLOW_RECONSTRUCT(x)              (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_RECONSTRUCT_SHIFT)) & PUF_AR_ALLOW_RECONSTRUCT_MASK)

#define PUF_AR_ALLOW_STOP_MASK                   (0x20U)
#define PUF_AR_ALLOW_STOP_SHIFT                  (5U)
/*! ALLOW_STOP - Stop operation
 *  0b0..Indicates that the Stop operation is not allowed
 *  0b1..Indicates that the Stop operation is allowed
 */
#define PUF_AR_ALLOW_STOP(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_STOP_SHIFT)) & PUF_AR_ALLOW_STOP_MASK)

#define PUF_AR_ALLOW_GET_KEY_MASK                (0x40U)
#define PUF_AR_ALLOW_GET_KEY_SHIFT               (6U)
/*! ALLOW_GET_KEY - Get Key operation
 *  0b0..Indicates that the Get Key operation is not allowed
 *  0b1..Indicates that the Get Key operation is allowed
 */
#define PUF_AR_ALLOW_GET_KEY(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_GET_KEY_SHIFT)) & PUF_AR_ALLOW_GET_KEY_MASK)

#define PUF_AR_ALLOW_UNWRAP_MASK                 (0x80U)
#define PUF_AR_ALLOW_UNWRAP_SHIFT                (7U)
/*! ALLOW_UNWRAP - Unwrap operation
 *  0b0..Indicates that the Unwrap operation is not allowed
 *  0b1..Indicates that the Unwrap operation is allowed
 */
#define PUF_AR_ALLOW_UNWRAP(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_UNWRAP_SHIFT)) & PUF_AR_ALLOW_UNWRAP_MASK)

#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_MASK  (0x100U)
#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_SHIFT (8U)
/*! ALLOW_WRAP_GENERATED_RANDOM - Wrap Generated Random operation
 *  0b0..Indicates that the Wrap Generated Random operation is not allowed
 *  0b1..Indicates that the Wrap Generated Random operation is allowed
 */
#define PUF_AR_ALLOW_WRAP_GENERATED_RANDOM(x)    (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_SHIFT)) & PUF_AR_ALLOW_WRAP_GENERATED_RANDOM_MASK)

#define PUF_AR_ALLOW_WRAP_MASK                   (0x200U)
#define PUF_AR_ALLOW_WRAP_SHIFT                  (9U)
/*! ALLOW_WRAP - Wrap operation
 *  0b0..Indicates that the Wrap operation is not allowed
 *  0b1..Indicates that the Wrap operation is allowed
 */
#define PUF_AR_ALLOW_WRAP(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_WRAP_SHIFT)) & PUF_AR_ALLOW_WRAP_MASK)

#define PUF_AR_ALLOW_GENERATE_RANDOM_MASK        (0x8000U)
#define PUF_AR_ALLOW_GENERATE_RANDOM_SHIFT       (15U)
/*! ALLOW_GENERATE_RANDOM - Generate Random operation
 *  0b0..Indicates that the Generate Random operation is not allowed
 *  0b1..Indicates that the Generate Random operation is allowed
 */
#define PUF_AR_ALLOW_GENERATE_RANDOM(x)          (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_GENERATE_RANDOM_SHIFT)) & PUF_AR_ALLOW_GENERATE_RANDOM_MASK)

#define PUF_AR_ALLOW_TEST_MEMORY_MASK            (0x40000000U)
#define PUF_AR_ALLOW_TEST_MEMORY_SHIFT           (30U)
/*! ALLOW_TEST_MEMORY
 *  0b0..Indicates that the Test Memory operation is not allowed
 *  0b1..Indicates that the Test Memory operation is allowed
 */
#define PUF_AR_ALLOW_TEST_MEMORY(x)              (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_TEST_MEMORY_SHIFT)) & PUF_AR_ALLOW_TEST_MEMORY_MASK)

#define PUF_AR_ALLOW_TEST_PUF_MASK               (0x80000000U)
#define PUF_AR_ALLOW_TEST_PUF_SHIFT              (31U)
/*! ALLOW_TEST_PUF - Test PUF operation
 *  0b0..Test PUF operation is not allowed
 *  0b1..Test PUF operation is allowed
 */
#define PUF_AR_ALLOW_TEST_PUF(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_AR_ALLOW_TEST_PUF_SHIFT)) & PUF_AR_ALLOW_TEST_PUF_MASK)
/*! @} */

/*! @name IER - Interrupt Enable */
/*! @{ */

#define PUF_IER_INT_EN_MASK                      (0x1U)
#define PUF_IER_INT_EN_SHIFT                     (0U)
/*! INT_EN - Interrupt enable
 *  0b0..Disables all PUF interrupts
 *  0b1..Enables all PUF interrupts that are enabled in the Interrupt Mask register
 */
#define PUF_IER_INT_EN(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_IER_INT_EN_SHIFT)) & PUF_IER_INT_EN_MASK)
/*! @} */

/*! @name IMR - Interrupt Mask */
/*! @{ */

#define PUF_IMR_INT_EN_BUSY_MASK                 (0x1U)
#define PUF_IMR_INT_EN_BUSY_SHIFT                (0U)
/*! INT_EN_BUSY - Busy interrupt
 *  0b0..Disables the busy interrupt
 *  0b1..Enables the busy interrupt
 */
#define PUF_IMR_INT_EN_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_BUSY_SHIFT)) & PUF_IMR_INT_EN_BUSY_MASK)

#define PUF_IMR_INT_EN_OK_MASK                   (0x2U)
#define PUF_IMR_INT_EN_OK_SHIFT                  (1U)
/*! INT_EN_OK - Ok interrupt
 *  0b0..Disables the Ok interrupt
 *  0b1..Enables the Ok interrupt
 */
#define PUF_IMR_INT_EN_OK(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_OK_SHIFT)) & PUF_IMR_INT_EN_OK_MASK)

#define PUF_IMR_INT_EN_ERROR_MASK                (0x4U)
#define PUF_IMR_INT_EN_ERROR_SHIFT               (2U)
/*! INT_EN_ERROR - Error interrupt
 *  0b0..Disables the error interrupt
 *  0b1..Enables the error interrupt
 */
#define PUF_IMR_INT_EN_ERROR(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_ERROR_SHIFT)) & PUF_IMR_INT_EN_ERROR_MASK)

#define PUF_IMR_INT_EN_ZEROIZED_MASK             (0x8U)
#define PUF_IMR_INT_EN_ZEROIZED_SHIFT            (3U)
/*! INT_EN_ZEROIZED - Zeroized interrupt
 *  0b0..Disables the zeroized interrupt
 *  0b1..Enables the zeroized interrupt
 */
#define PUF_IMR_INT_EN_ZEROIZED(x)               (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_ZEROIZED_SHIFT)) & PUF_IMR_INT_EN_ZEROIZED_MASK)

#define PUF_IMR_INT_EN_REJECTED_MASK             (0x10U)
#define PUF_IMR_INT_EN_REJECTED_SHIFT            (4U)
/*! INT_EN_REJECTED - Rejected interrupt
 *  0b0..Disables the rejected interrupt
 *  0b1..Enables the rejected interrupt
 */
#define PUF_IMR_INT_EN_REJECTED(x)               (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_REJECTED_SHIFT)) & PUF_IMR_INT_EN_REJECTED_MASK)

#define PUF_IMR_INT_EN_DI_REQUEST_MASK           (0x20U)
#define PUF_IMR_INT_EN_DI_REQUEST_SHIFT          (5U)
/*! INT_EN_DI_REQUEST - Data in request interrupt
 *  0b0..Disables the data in request interrupt
 *  0b1..Enables the data in request interrupt
 */
#define PUF_IMR_INT_EN_DI_REQUEST(x)             (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_DI_REQUEST_SHIFT)) & PUF_IMR_INT_EN_DI_REQUEST_MASK)

#define PUF_IMR_INT_EN_DO_REQUEST_MASK           (0x40U)
#define PUF_IMR_INT_EN_DO_REQUEST_SHIFT          (6U)
/*! INT_EN_DO_REQUEST - Data out request interrupt
 *  0b0..Disables the data out request interrupt
 *  0b1..Enables the data out request interrupt
 */
#define PUF_IMR_INT_EN_DO_REQUEST(x)             (((uint32_t)(((uint32_t)(x)) << PUF_IMR_INT_EN_DO_REQUEST_SHIFT)) & PUF_IMR_INT_EN_DO_REQUEST_MASK)
/*! @} */

/*! @name ISR - Interrupt Status */
/*! @{ */

#define PUF_ISR_INT_BUSY_MASK                    (0x1U)
#define PUF_ISR_INT_BUSY_SHIFT                   (0U)
/*! INT_BUSY - Negative edge occurred on Busy
 *  0b0..Does not have busy interrupt
 *  0b1..int_busy (an operation has completed) interrupt appears
 */
#define PUF_ISR_INT_BUSY(x)                      (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_BUSY_SHIFT)) & PUF_ISR_INT_BUSY_MASK)

#define PUF_ISR_INT_OK_MASK                      (0x2U)
#define PUF_ISR_INT_OK_SHIFT                     (1U)
/*! INT_OK - Positive edge occurred on Ok
 *  0b0..Does not have OK interrupt
 *  0b1..int_ok (an operation has successfully completed) interrupt appears
 */
#define PUF_ISR_INT_OK(x)                        (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_OK_SHIFT)) & PUF_ISR_INT_OK_MASK)

#define PUF_ISR_INT_ERROR_MASK                   (0x4U)
#define PUF_ISR_INT_ERROR_SHIFT                  (2U)
/*! INT_ERROR - Positive edge occurred on Error
 *  0b0..Does not have error interrupt
 *  0b1..int_error (an operation failed) interrupt appears
 */
#define PUF_ISR_INT_ERROR(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_ERROR_SHIFT)) & PUF_ISR_INT_ERROR_MASK)

#define PUF_ISR_INT_ZEROIZED_MASK                (0x8U)
#define PUF_ISR_INT_ZEROIZED_SHIFT               (3U)
/*! INT_ZEROIZED - Positive edge occurred on Zeroized
 *  0b0..Does not have zeroized interrupt
 *  0b1..zeroized (PUF has moved to the zeroized or locked state) interrupt appears
 */
#define PUF_ISR_INT_ZEROIZED(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_ZEROIZED_SHIFT)) & PUF_ISR_INT_ZEROIZED_MASK)

#define PUF_ISR_INT_REJECTED_MASK                (0x10U)
#define PUF_ISR_INT_REJECTED_SHIFT               (4U)
/*! INT_REJECTED - Positive edge occurred on Rejected
 *  0b0..Does not have rejected interrupt
 *  0b1..rejected (a command was rejected) interrupt appears
 */
#define PUF_ISR_INT_REJECTED(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_REJECTED_SHIFT)) & PUF_ISR_INT_REJECTED_MASK)

#define PUF_ISR_INT_DI_REQUEST_MASK              (0x20U)
#define PUF_ISR_INT_DI_REQUEST_SHIFT             (5U)
/*! INT_DI_REQUEST - Positive edge occurred on di_request
 *  0b0..Does not have di_request interrupt
 *  0b1..di_request (data in transfer is requested through the DIR register) interrupt appears
 */
#define PUF_ISR_INT_DI_REQUEST(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_DI_REQUEST_SHIFT)) & PUF_ISR_INT_DI_REQUEST_MASK)

#define PUF_ISR_INT_DO_REQUEST_MASK              (0x40U)
#define PUF_ISR_INT_DO_REQUEST_SHIFT             (6U)
/*! INT_DO_REQUEST - Positive edge occurred on do_request
 *  0b0..Does not have do_request interrupt
 *  0b1..do_request (data out transfer is requested through the DOR register) interrupt appears
 */
#define PUF_ISR_INT_DO_REQUEST(x)                (((uint32_t)(((uint32_t)(x)) << PUF_ISR_INT_DO_REQUEST_SHIFT)) & PUF_ISR_INT_DO_REQUEST_MASK)
/*! @} */

/*! @name DATA_DEST - Data Destination */
/*! @{ */

#define PUF_DATA_DEST_DEST_DOR_MASK              (0x1U)
#define PUF_DATA_DEST_DEST_DOR_SHIFT             (0U)
/*! DEST_DOR - Key available via the DOR register
 *  0b0..Key is unavailable through DOR register. If DEST_DOR is set to 0, you can set DEST_SO to 1 to make key available
 *  0b1..Key is available through DOR register
 */
#define PUF_DATA_DEST_DEST_DOR(x)                (((uint32_t)(((uint32_t)(x)) << PUF_DATA_DEST_DEST_DOR_SHIFT)) & PUF_DATA_DEST_DEST_DOR_MASK)

#define PUF_DATA_DEST_DEST_SO_MASK               (0x2U)
#define PUF_DATA_DEST_DEST_SO_SHIFT              (1U)
/*! DEST_SO - Key available to ELS
 *  0b0..Key is unavailable through HW bus to ELS. If DEST_SO is set to 0, you can set DEST_DOR to 1 to make key available
 *  0b1..Key is available through HW bus to ELS
 */
#define PUF_DATA_DEST_DEST_SO(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_DATA_DEST_DEST_SO_SHIFT)) & PUF_DATA_DEST_DEST_SO_MASK)
/*! @} */

/*! @name DIR - Data Input */
/*! @{ */

#define PUF_DIR_DI_MASK                          (0xFFFFFFFFU)
#define PUF_DIR_DI_SHIFT                         (0U)
/*! DI - Input data */
#define PUF_DIR_DI(x)                            (((uint32_t)(((uint32_t)(x)) << PUF_DIR_DI_SHIFT)) & PUF_DIR_DI_MASK)
/*! @} */

/*! @name DOR - Data Output */
/*! @{ */

#define PUF_DOR_DO_MASK                          (0xFFFFFFFFU)
#define PUF_DOR_DO_SHIFT                         (0U)
/*! DO - Output data */
#define PUF_DOR_DO(x)                            (((uint32_t)(((uint32_t)(x)) << PUF_DOR_DO_SHIFT)) & PUF_DOR_DO_MASK)
/*! @} */

/*! @name MISC - Miscellaneous */
/*! @{ */

#define PUF_MISC_DATA_ENDIANNESS_MASK            (0x1U)
#define PUF_MISC_DATA_ENDIANNESS_SHIFT           (0U)
/*! DATA_ENDIANNESS - Defines the endianness of data in DIR and DOR:
 *  0b0..Little endian
 *  0b1..Big endian (default)
 */
#define PUF_MISC_DATA_ENDIANNESS(x)              (((uint32_t)(((uint32_t)(x)) << PUF_MISC_DATA_ENDIANNESS_SHIFT)) & PUF_MISC_DATA_ENDIANNESS_MASK)
/*! @} */

/*! @name IF_SR - Interface Status */
/*! @{ */

#define PUF_IF_SR_APB_ERROR_MASK                 (0x1U)
#define PUF_IF_SR_APB_ERROR_SHIFT                (0U)
/*! APB_ERROR - APB error
 *  0b0..No APB error has occurred
 *  0b1..Indicates an APB error has occurred
 */
#define PUF_IF_SR_APB_ERROR(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_IF_SR_APB_ERROR_SHIFT)) & PUF_IF_SR_APB_ERROR_MASK)
/*! @} */

/*! @name PSR - PUF Score */
/*! @{ */

#define PUF_PSR_PUF_SCORE_MASK                   (0xFU)
#define PUF_PSR_PUF_SCORE_SHIFT                  (0U)
/*! PUF_SCORE - Provides the PUF score obtained during the last Test PUF, Enroll or Start operation. */
#define PUF_PSR_PUF_SCORE(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_PSR_PUF_SCORE_SHIFT)) & PUF_PSR_PUF_SCORE_MASK)
/*! @} */

/*! @name HW_RUC0 - Hardware Restrict User Context 0 */
/*! @{ */

#define PUF_HW_RUC0_LC_STATE_MASK                (0xFFU)
#define PUF_HW_RUC0_LC_STATE_SHIFT               (0U)
/*! lc_state - Current life cycle state of the device. */
#define PUF_HW_RUC0_LC_STATE(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_LC_STATE_SHIFT)) & PUF_HW_RUC0_LC_STATE_MASK)

#define PUF_HW_RUC0_BOOT_STATE_MASK              (0xFFFF00U)
#define PUF_HW_RUC0_BOOT_STATE_SHIFT             (8U)
/*! boot_state - Reflects current temporal boot status. */
#define PUF_HW_RUC0_BOOT_STATE(x)                (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_BOOT_STATE_SHIFT)) & PUF_HW_RUC0_BOOT_STATE_MASK)

#define PUF_HW_RUC0_CPU0_DEBUG_MASK              (0x1000000U)
#define PUF_HW_RUC0_CPU0_DEBUG_SHIFT             (24U)
/*! cpu0_debug - Cortex-M33 (CPU0) debug status */
#define PUF_HW_RUC0_CPU0_DEBUG(x)                (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_CPU0_DEBUG_SHIFT)) & PUF_HW_RUC0_CPU0_DEBUG_MASK)

#define PUF_HW_RUC0_DSP_DEBUG_MASK               (0x4000000U)
#define PUF_HW_RUC0_DSP_DEBUG_SHIFT              (26U)
/*! dsp_debug - DSP debug status.
 *  0b0..No external debugger is connected to the device at least once after power on reset has occurred
 *  0b1..Indicates an external debugger is connected to the device at least once after power on reset has occurred
 */
#define PUF_HW_RUC0_DSP_DEBUG(x)                 (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_DSP_DEBUG_SHIFT)) & PUF_HW_RUC0_DSP_DEBUG_MASK)

#define PUF_HW_RUC0_ACCESS_LEVEL_MASK            (0xF0000000U)
#define PUF_HW_RUC0_ACCESS_LEVEL_SHIFT           (28U)
/*! access_level - Reflects current TrustZone security level of the CPU. */
#define PUF_HW_RUC0_ACCESS_LEVEL(x)              (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC0_ACCESS_LEVEL_SHIFT)) & PUF_HW_RUC0_ACCESS_LEVEL_MASK)
/*! @} */

/*! @name HW_RUC1 - Hardware Restrict User Context 1 */
/*! @{ */

#define PUF_HW_RUC1_APP_CTX_MASK                 (0xFFFFFFFFU)
#define PUF_HW_RUC1_APP_CTX_SHIFT                (0U)
/*! APP_CTX - Restrict user context 1 */
#define PUF_HW_RUC1_APP_CTX(x)                   (((uint32_t)(((uint32_t)(x)) << PUF_HW_RUC1_APP_CTX_SHIFT)) & PUF_HW_RUC1_APP_CTX_MASK)
/*! @} */

/*! @name HW_INFO - Hardware Information */
/*! @{ */

#define PUF_HW_INFO_CONFIG_WRAP_MASK             (0x1000000U)
#define PUF_HW_INFO_CONFIG_WRAP_SHIFT            (24U)
/*! CONFIG_WRAP - Wrap configuration
 *  0b0..Indicates that Wrap is not included
 *  0b1..Indicates that Wrap is included
 */
#define PUF_HW_INFO_CONFIG_WRAP(x)               (((uint32_t)(((uint32_t)(x)) << PUF_HW_INFO_CONFIG_WRAP_SHIFT)) & PUF_HW_INFO_CONFIG_WRAP_MASK)

#define PUF_HW_INFO_CONFIG_TYPE_MASK             (0xF0000000U)
#define PUF_HW_INFO_CONFIG_TYPE_SHIFT            (28U)
/*! CONFIG_TYPE - PUF configuration
 *  0b0001..Indicates that PUF configuration is Safe.
 *  0b0010..Indicates that PUF configuration is Plus.
 */
#define PUF_HW_INFO_CONFIG_TYPE(x)               (((uint32_t)(((uint32_t)(x)) << PUF_HW_INFO_CONFIG_TYPE_SHIFT)) & PUF_HW_INFO_CONFIG_TYPE_MASK)
/*! @} */

/*! @name HW_ID - Hardware Identifier */
/*! @{ */

#define PUF_HW_ID_HW_ID_MASK                     (0xFFFFFFFFU)
#define PUF_HW_ID_HW_ID_SHIFT                    (0U)
/*! HW_ID - Provides the hardware identifier. IP level has ID, which has 32 bits to record current hardware identifier */
#define PUF_HW_ID_HW_ID(x)                       (((uint32_t)(((uint32_t)(x)) << PUF_HW_ID_HW_ID_SHIFT)) & PUF_HW_ID_HW_ID_MASK)
/*! @} */

/*! @name HW_VER - Hardware Version */
/*! @{ */

#define PUF_HW_VER_HW_REV_MASK                   (0xFFU)
#define PUF_HW_VER_HW_REV_SHIFT                  (0U)
/*! HW_REV - Provides the hardware version, patch part */
#define PUF_HW_VER_HW_REV(x)                     (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_REV_SHIFT)) & PUF_HW_VER_HW_REV_MASK)

#define PUF_HW_VER_HW_VERSION_MINOR_MASK         (0xFF00U)
#define PUF_HW_VER_HW_VERSION_MINOR_SHIFT        (8U)
/*! HW_VERSION_MINOR - Provides the hardware version, minor part */
#define PUF_HW_VER_HW_VERSION_MINOR(x)           (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_VERSION_MINOR_SHIFT)) & PUF_HW_VER_HW_VERSION_MINOR_MASK)

#define PUF_HW_VER_HW_VERSION_MAJOR_MASK         (0xFF0000U)
#define PUF_HW_VER_HW_VERSION_MAJOR_SHIFT        (16U)
/*! HW_VERSION_MAJOR - Provides the hardware version, major part */
#define PUF_HW_VER_HW_VERSION_MAJOR(x)           (((uint32_t)(((uint32_t)(x)) << PUF_HW_VER_HW_VERSION_MAJOR_SHIFT)) & PUF_HW_VER_HW_VERSION_MAJOR_MASK)
/*! @} */

/*! @name CONFIG - PUF command blocking configuration */
/*! @{ */

#define PUF_CONFIG_DIS_PUF_ENROLL_MASK           (0x2U)
#define PUF_CONFIG_DIS_PUF_ENROLL_SHIFT          (1U)
/*! DIS_PUF_ENROLL - Disable PUF enroll command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_ENROLL(x)             (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_ENROLL_SHIFT)) & PUF_CONFIG_DIS_PUF_ENROLL_MASK)

#define PUF_CONFIG_DIS_PUF_START_MASK            (0x4U)
#define PUF_CONFIG_DIS_PUF_START_SHIFT           (2U)
/*! DIS_PUF_START - Disable PUF start command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_START(x)              (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_START_SHIFT)) & PUF_CONFIG_DIS_PUF_START_MASK)

#define PUF_CONFIG_DIS_PUF_RECONSTRUCT_MASK      (0x8U)
#define PUF_CONFIG_DIS_PUF_RECONSTRUCT_SHIFT     (3U)
/*! DIS_PUF_RECONSTRUCT - Disable PUF reconstruct command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_RECONSTRUCT(x)        (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_RECONSTRUCT_SHIFT)) & PUF_CONFIG_DIS_PUF_RECONSTRUCT_MASK)

#define PUF_CONFIG_DIS_PUF_STOP_MASK             (0x20U)
#define PUF_CONFIG_DIS_PUF_STOP_SHIFT            (5U)
/*! DIS_PUF_STOP - Disable PUF stop command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_STOP(x)               (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_STOP_SHIFT)) & PUF_CONFIG_DIS_PUF_STOP_MASK)

#define PUF_CONFIG_DIS_PUF_GET_KEY_MASK          (0x40U)
#define PUF_CONFIG_DIS_PUF_GET_KEY_SHIFT         (6U)
/*! DIS_PUF_GET_KEY - Disable PUF get key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GET_KEY(x)            (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GET_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_GET_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY_MASK       (0x80U)
#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY_SHIFT      (7U)
/*! DIS_PUF_UNWRAP_KEY - Disable PUF unwrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_UNWRAP_KEY(x)         (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_UNWRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_UNWRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_MASK     (0x100U)
#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_SHIFT    (8U)
/*! DIS_PUF_GEN_WRAP_KEY - Disable PUF generate and wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY(x)       (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_GEN_WRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_WRAP_KEY_MASK         (0x200U)
#define PUF_CONFIG_DIS_PUF_WRAP_KEY_SHIFT        (9U)
/*! DIS_PUF_WRAP_KEY - Disable PUF wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_WRAP_KEY(x)           (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_WRAP_KEY_SHIFT)) & PUF_CONFIG_DIS_PUF_WRAP_KEY_MASK)

#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_MASK (0x8000U)
#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_SHIFT (15U)
/*! DIS_PUF_GEN_RANDOM_NUMBER - Disable PUF generate and wrap key command
 *  0b0..Command enabled
 *  0b1..Command disabled
 */
#define PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER(x)  (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_SHIFT)) & PUF_CONFIG_DIS_PUF_GEN_RANDOM_NUMBER_MASK)

#define PUF_CONFIG_DIS_PUF_TEST_MEMORY_MASK      (0x40000000U)
#define PUF_CONFIG_DIS_PUF_TEST_MEMORY_SHIFT     (30U)
/*! DIS_PUF_TEST_MEMORY - Disable PUF test memory command */
#define PUF_CONFIG_DIS_PUF_TEST_MEMORY(x)        (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_TEST_MEMORY_SHIFT)) & PUF_CONFIG_DIS_PUF_TEST_MEMORY_MASK)

#define PUF_CONFIG_DIS_PUF_TEST_MASK             (0x80000000U)
#define PUF_CONFIG_DIS_PUF_TEST_SHIFT            (31U)
/*! DIS_PUF_TEST - Disable PUF test command */
#define PUF_CONFIG_DIS_PUF_TEST(x)               (((uint32_t)(((uint32_t)(x)) << PUF_CONFIG_DIS_PUF_TEST_SHIFT)) & PUF_CONFIG_DIS_PUF_TEST_MASK)
/*! @} */

/*! @name SEC_LOCK - Security level lock */
/*! @{ */

#define PUF_SEC_LOCK_SEC_LEVEL_MASK              (0x3U)
#define PUF_SEC_LOCK_SEC_LEVEL_SHIFT             (0U)
/*! SEC_LEVEL - Security Level
 *  0b00..Non-secure and non-privileged Master
 *  0b01..Non-secure and privileged Master
 *  0b10..Secure and non-privileged Master
 *  0b11..Secure and privileged Master
 */
#define PUF_SEC_LOCK_SEC_LEVEL(x)                (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_SEC_LEVEL_SHIFT)) & PUF_SEC_LOCK_SEC_LEVEL_MASK)

#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_MASK    (0xCU)
#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_SHIFT   (2U)
/*! ANTI_POLE_SEC_LEVEL - Anti-pole of security level
 *  0b00..Secure and privileged Master
 *  0b01..Secure and non-privileged Master
 *  0b10..Non-secure and privileged Master
 *  0b11..Non-secure and non-privileged Master
 */
#define PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL(x)      (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_SHIFT)) & PUF_SEC_LOCK_ANTI_POLE_SEC_LEVEL_MASK)

#define PUF_SEC_LOCK_PATTERN_MASK                (0xFFF0U)
#define PUF_SEC_LOCK_PATTERN_SHIFT               (4U)
/*! PATTERN - Pattern */
#define PUF_SEC_LOCK_PATTERN(x)                  (((uint32_t)(((uint32_t)(x)) << PUF_SEC_LOCK_PATTERN_SHIFT)) & PUF_SEC_LOCK_PATTERN_MASK)
/*! @} */

/*! @name APP_CTX_MASK - Application defined context mask */
/*! @{ */

#define PUF_APP_CTX_MASK_APP_CTX_MASK_MASK       (0xFFFFFFFFU)
#define PUF_APP_CTX_MASK_APP_CTX_MASK_SHIFT      (0U)
/*! APP_CTX_MASK - Application defined context */
#define PUF_APP_CTX_MASK_APP_CTX_MASK(x)         (((uint32_t)(((uint32_t)(x)) << PUF_APP_CTX_MASK_APP_CTX_MASK_SHIFT)) & PUF_APP_CTX_MASK_APP_CTX_MASK_MASK)
/*! @} */

/*! @name PUF_MEM_CTRL - PUF mem control */
/*! @{ */

#define PUF_PUF_MEM_CTRL_POWERON_MASK            (0x1U)
#define PUF_PUF_MEM_CTRL_POWERON_SHIFT           (0U)
/*! POWERON - PUF mem power on
 *  0b0..PUF mem power off
 *  0b1..PUF mem power on
 */
#define PUF_PUF_MEM_CTRL_POWERON(x)              (((uint32_t)(((uint32_t)(x)) << PUF_PUF_MEM_CTRL_POWERON_SHIFT)) & PUF_PUF_MEM_CTRL_POWERON_MASK)

#define PUF_PUF_MEM_CTRL_CLK_GATE_EN_MASK        (0x2U)
#define PUF_PUF_MEM_CTRL_CLK_GATE_EN_SHIFT       (1U)
/*! CLK_GATE_EN - PUF mem clock gating enable
 *  0b0..PUF mem clock gating disable
 *  0b1..PUF mem clock is gated by chip select
 */
#define PUF_PUF_MEM_CTRL_CLK_GATE_EN(x)          (((uint32_t)(((uint32_t)(x)) << PUF_PUF_MEM_CTRL_CLK_GATE_EN_SHIFT)) & PUF_PUF_MEM_CTRL_CLK_GATE_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PUF_Register_Masks */


/*!
 * @}
 */ /* end of group PUF_Peripheral_Access_Layer */


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


#endif  /* PERI_PUF_H_ */

