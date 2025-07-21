/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FGPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FGPIO.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FGPIO
 *
 * CMSIS Peripheral Access Layer for FGPIO
 */

#if !defined(PERI_FGPIO_H_)
#define PERI_FGPIO_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- FGPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Peripheral_Access_Layer FGPIO Peripheral Access Layer
 * @{
 */

/** FGPIO - Size of Registers Arrays */
#define FGPIO_BDACP0_COUNT                        4u

/** FGPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __IO uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __IO uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __IO uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __IO uint32_t BDACP0[FGPIO_BDACP0_COUNT];        /**< Port Byte Domain Access Control Register 0, array offset: 0x20, array step: 0x4 */
} FGPIO_Type;

/* ----------------------------------------------------------------------------
   -- FGPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Masks FGPIO Register Masks
 * @{
 */

/*! @name PDOR - Port Data Output Register */
/*! @{ */

#define FGPIO_PDOR_PDO_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDOR_PDO_SHIFT                     (0U)
/*! PDO - Port Data Output */
#define FGPIO_PDOR_PDO(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDOR_PDO_SHIFT)) & FGPIO_PDOR_PDO_MASK)
/*! @} */

/*! @name PSOR - Port Set Output Register */
/*! @{ */

#define FGPIO_PSOR_PTSO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PSOR_PTSO_SHIFT                    (0U)
/*! PTSO - Port Set Output */
#define FGPIO_PSOR_PTSO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PSOR_PTSO_SHIFT)) & FGPIO_PSOR_PTSO_MASK)
/*! @} */

/*! @name PCOR - Port Clear Output Register */
/*! @{ */

#define FGPIO_PCOR_PTCO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PCOR_PTCO_SHIFT                    (0U)
/*! PTCO - Port Clear Output */
#define FGPIO_PCOR_PTCO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PCOR_PTCO_SHIFT)) & FGPIO_PCOR_PTCO_MASK)
/*! @} */

/*! @name PTOR - Port Toggle Output Register */
/*! @{ */

#define FGPIO_PTOR_PTTO_MASK                     (0xFFFFFFFFU)
#define FGPIO_PTOR_PTTO_SHIFT                    (0U)
/*! PTTO - Port Toggle Output */
#define FGPIO_PTOR_PTTO(x)                       (((uint32_t)(((uint32_t)(x)) << FGPIO_PTOR_PTTO_SHIFT)) & FGPIO_PTOR_PTTO_MASK)
/*! @} */

/*! @name PDIR - Port Data Input Register */
/*! @{ */

#define FGPIO_PDIR_PDI_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDIR_PDI_SHIFT                     (0U)
/*! PDI - Port Data Input */
#define FGPIO_PDIR_PDI(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDIR_PDI_SHIFT)) & FGPIO_PDIR_PDI_MASK)
/*! @} */

/*! @name PDDR - Port Data Direction Register */
/*! @{ */

#define FGPIO_PDDR_PDD_MASK                      (0xFFFFFFFFU)
#define FGPIO_PDDR_PDD_SHIFT                     (0U)
/*! PDD - Port Data Direction */
#define FGPIO_PDDR_PDD(x)                        (((uint32_t)(((uint32_t)(x)) << FGPIO_PDDR_PDD_SHIFT)) & FGPIO_PDDR_PDD_MASK)
/*! @} */

/*! @name BDACP0 - Port Byte Domain Access Control Register 0 */
/*! @{ */

#define FGPIO_BDACP0_D0ACP_MASK                  (0x7U)
#define FGPIO_BDACP0_D0ACP_SHIFT                 (0U)
/*! D0ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D0ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D0ACP_SHIFT)) & FGPIO_BDACP0_D0ACP_MASK)

#define FGPIO_BDACP0_D1ACP_MASK                  (0x38U)
#define FGPIO_BDACP0_D1ACP_SHIFT                 (3U)
/*! D1ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D1ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D1ACP_SHIFT)) & FGPIO_BDACP0_D1ACP_MASK)

#define FGPIO_BDACP0_D2ACP_MASK                  (0x1C0U)
#define FGPIO_BDACP0_D2ACP_SHIFT                 (6U)
/*! D2ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D2ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D2ACP_SHIFT)) & FGPIO_BDACP0_D2ACP_MASK)

#define FGPIO_BDACP0_D3ACP_MASK                  (0xE00U)
#define FGPIO_BDACP0_D3ACP_SHIFT                 (9U)
/*! D3ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D3ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D3ACP_SHIFT)) & FGPIO_BDACP0_D3ACP_MASK)

#define FGPIO_BDACP0_D4ACP_MASK                  (0x7000U)
#define FGPIO_BDACP0_D4ACP_SHIFT                 (12U)
/*! D4ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D4ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D4ACP_SHIFT)) & FGPIO_BDACP0_D4ACP_MASK)

#define FGPIO_BDACP0_D5ACP_MASK                  (0x38000U)
#define FGPIO_BDACP0_D5ACP_SHIFT                 (15U)
/*! D5ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D5ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D5ACP_SHIFT)) & FGPIO_BDACP0_D5ACP_MASK)

#define FGPIO_BDACP0_D6ACP_MASK                  (0x1C0000U)
#define FGPIO_BDACP0_D6ACP_SHIFT                 (18U)
/*! D6ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D6ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D6ACP_SHIFT)) & FGPIO_BDACP0_D6ACP_MASK)

#define FGPIO_BDACP0_D7ACP_MASK                  (0xE00000U)
#define FGPIO_BDACP0_D7ACP_SHIFT                 (21U)
/*! D7ACP - Domain Access Control Policy */
#define FGPIO_BDACP0_D7ACP(x)                    (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_D7ACP_SHIFT)) & FGPIO_BDACP0_D7ACP_MASK)

#define FGPIO_BDACP0_LK2_MASK                    (0x60000000U)
#define FGPIO_BDACP0_LK2_SHIFT                   (29U)
/*! LK2 - LK2
 *  0b00..Entire DxACP can be written.
 *  0b01..Entire DxACP can be written.
 *  0b10..Domain x can only update the DxACP field; no other D*ACP fields can be written.
 *  0b11..DxACP is locked (read-only) until the next reset.
 */
#define FGPIO_BDACP0_LK2(x)                      (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_LK2_SHIFT)) & FGPIO_BDACP0_LK2_MASK)

#define FGPIO_BDACP0_VLD_MASK                    (0x80000000U)
#define FGPIO_BDACP0_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..The DxACP assignment is invalid.
 *  0b1..The DxACP assignment is valid.
 */
#define FGPIO_BDACP0_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << FGPIO_BDACP0_VLD_SHIFT)) & FGPIO_BDACP0_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FGPIO_Register_Masks */


/*!
 * @}
 */ /* end of group FGPIO_Peripheral_Access_Layer */


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


#endif  /* PERI_FGPIO_H_ */

