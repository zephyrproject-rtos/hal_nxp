/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MMDVSQ
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-30)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MMDVSQ.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MMDVSQ
 *
 * CMSIS Peripheral Access Layer for MMDVSQ
 */

#if !defined(PERI_MMDVSQ_H_)
#define PERI_MMDVSQ_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
   -- MMDVSQ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Peripheral_Access_Layer MMDVSQ Peripheral Access Layer
 * @{
 */

/** MMDVSQ - Register Layout Typedef */
typedef struct {
  __IO uint32_t DEND;                              /**< Dividend Register, offset: 0x0 */
  __IO uint32_t DSOR;                              /**< Divisor Register, offset: 0x4 */
  __IO uint32_t CSR;                               /**< Control/Status Register, offset: 0x8 */
  __IO uint32_t RES;                               /**< Result Register, offset: 0xC */
  __O  uint32_t RCND;                              /**< Radicand Register, offset: 0x10 */
} MMDVSQ_Type;

/* ----------------------------------------------------------------------------
   -- MMDVSQ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MMDVSQ_Register_Masks MMDVSQ Register Masks
 * @{
 */

/*! @name DEND - Dividend Register */
/*! @{ */

#define MMDVSQ_DEND_DIVIDEND_MASK                (0xFFFFFFFFU)
#define MMDVSQ_DEND_DIVIDEND_SHIFT               (0U)
/*! DIVIDEND - Dividend */
#define MMDVSQ_DEND_DIVIDEND(x)                  (((uint32_t)(((uint32_t)(x)) << MMDVSQ_DEND_DIVIDEND_SHIFT)) & MMDVSQ_DEND_DIVIDEND_MASK)
/*! @} */

/*! @name DSOR - Divisor Register */
/*! @{ */

#define MMDVSQ_DSOR_DIVISOR_MASK                 (0xFFFFFFFFU)
#define MMDVSQ_DSOR_DIVISOR_SHIFT                (0U)
/*! DIVISOR - Divisor */
#define MMDVSQ_DSOR_DIVISOR(x)                   (((uint32_t)(((uint32_t)(x)) << MMDVSQ_DSOR_DIVISOR_SHIFT)) & MMDVSQ_DSOR_DIVISOR_MASK)
/*! @} */

/*! @name CSR - Control/Status Register */
/*! @{ */

#define MMDVSQ_CSR_SRT_MASK                      (0x1U)
#define MMDVSQ_CSR_SRT_SHIFT                     (0U)
/*! SRT - Start
 *  0b0..No operation initiated
 *  0b1..If CSR[DFS] = 1, then initiate a divide calculation, else ignore
 */
#define MMDVSQ_CSR_SRT(x)                        (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_SRT_SHIFT)) & MMDVSQ_CSR_SRT_MASK)

#define MMDVSQ_CSR_USGN_MASK                     (0x2U)
#define MMDVSQ_CSR_USGN_SHIFT                    (1U)
/*! USGN - Unsigned calculation
 *  0b0..Perform a signed divide
 *  0b1..Perform an unsigned divide
 */
#define MMDVSQ_CSR_USGN(x)                       (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_USGN_SHIFT)) & MMDVSQ_CSR_USGN_MASK)

#define MMDVSQ_CSR_REM_MASK                      (0x4U)
#define MMDVSQ_CSR_REM_SHIFT                     (2U)
/*! REM - REMainder calculation
 *  0b0..Return the quotient in the RES for the divide calculation
 *  0b1..Return the remainder in the RES for the divide calculation
 */
#define MMDVSQ_CSR_REM(x)                        (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_REM_SHIFT)) & MMDVSQ_CSR_REM_MASK)

#define MMDVSQ_CSR_DZE_MASK                      (0x8U)
#define MMDVSQ_CSR_DZE_SHIFT                     (3U)
/*! DZE - Divide-by-Zero-Enable
 *  0b0..Reads of the RES register return the register contents
 *  0b1..If CSR[DZ] = 1, an attempted read of RES register is error terminated to signal a divide-by-zero, else the register contents are returned
 */
#define MMDVSQ_CSR_DZE(x)                        (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_DZE_SHIFT)) & MMDVSQ_CSR_DZE_MASK)

#define MMDVSQ_CSR_DZ_MASK                       (0x10U)
#define MMDVSQ_CSR_DZ_SHIFT                      (4U)
/*! DZ - Divide-by-Zero
 *  0b0..The last divide operation had a non-zero divisor, that is, DSOR != 0
 *  0b1..The last divide operation had a zero divisor, that is, DSOR = 0
 */
#define MMDVSQ_CSR_DZ(x)                         (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_DZ_SHIFT)) & MMDVSQ_CSR_DZ_MASK)

#define MMDVSQ_CSR_DFS_MASK                      (0x20U)
#define MMDVSQ_CSR_DFS_SHIFT                     (5U)
/*! DFS - Disable Fast Start
 *  0b0..A divide operation is initiated by a write to the DSOR register
 *  0b1..A divide operation is initiated by a write to the CSR register with CSR[SRT] = 1
 */
#define MMDVSQ_CSR_DFS(x)                        (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_DFS_SHIFT)) & MMDVSQ_CSR_DFS_MASK)

#define MMDVSQ_CSR_SQRT_MASK                     (0x20000000U)
#define MMDVSQ_CSR_SQRT_SHIFT                    (29U)
/*! SQRT - SQUARE ROOT
 *  0b0..Current or last MMDVSQ operation was not a square root
 *  0b1..Current or last MMDVSQ operation was a square root
 */
#define MMDVSQ_CSR_SQRT(x)                       (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_SQRT_SHIFT)) & MMDVSQ_CSR_SQRT_MASK)

#define MMDVSQ_CSR_DIV_MASK                      (0x40000000U)
#define MMDVSQ_CSR_DIV_SHIFT                     (30U)
/*! DIV - DIVIDE
 *  0b0..Current or last MMDVSQ operation was not a divide
 *  0b1..Current or last MMDVSQ operation was a divide
 */
#define MMDVSQ_CSR_DIV(x)                        (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_DIV_SHIFT)) & MMDVSQ_CSR_DIV_MASK)

#define MMDVSQ_CSR_BUSY_MASK                     (0x80000000U)
#define MMDVSQ_CSR_BUSY_SHIFT                    (31U)
/*! BUSY - BUSY
 *  0b0..MMDVSQ is idle
 *  0b1..MMDVSQ is busy performing a divide or square root calculation
 */
#define MMDVSQ_CSR_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << MMDVSQ_CSR_BUSY_SHIFT)) & MMDVSQ_CSR_BUSY_MASK)
/*! @} */

/*! @name RES - Result Register */
/*! @{ */

#define MMDVSQ_RES_RESULT_MASK                   (0xFFFFFFFFU)
#define MMDVSQ_RES_RESULT_SHIFT                  (0U)
/*! RESULT - Result */
#define MMDVSQ_RES_RESULT(x)                     (((uint32_t)(((uint32_t)(x)) << MMDVSQ_RES_RESULT_SHIFT)) & MMDVSQ_RES_RESULT_MASK)
/*! @} */

/*! @name RCND - Radicand Register */
/*! @{ */

#define MMDVSQ_RCND_RADICAND_MASK                (0xFFFFFFFFU)
#define MMDVSQ_RCND_RADICAND_SHIFT               (0U)
/*! RADICAND - Radicand */
#define MMDVSQ_RCND_RADICAND(x)                  (((uint32_t)(((uint32_t)(x)) << MMDVSQ_RCND_RADICAND_SHIFT)) & MMDVSQ_RCND_RADICAND_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MMDVSQ_Register_Masks */


/*!
 * @}
 */ /* end of group MMDVSQ_Peripheral_Access_Layer */


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


#endif  /* PERI_MMDVSQ_H_ */

