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
**         CMSIS Peripheral Access Layer for locald25
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
 * @file PERI_locald25.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald25
 *
 * CMSIS Peripheral Access Layer for locald25
 */

#if !defined(PERI_LOCALD25_H_)
#define PERI_LOCALD25_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald25 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald25_Peripheral_Access_Layer locald25 Peripheral Access Layer
 * @{
 */

/** locald25 - Register Layout Typedef */
typedef struct {
  __I  uint32_t LDTR000;                           /**< lddetread000, offset: 0x0 */
  __I  uint32_t LDTRD001;                          /**< lddetread001, offset: 0x4 */
  __I  uint32_t LDTRD002;                          /**< lddetread002, offset: 0x8 */
  __I  uint32_t LDTRD003;                          /**< lddetread003, offset: 0xC */
} locald25_Type;

/* ----------------------------------------------------------------------------
   -- locald25 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald25_Register_Masks locald25 Register Masks
 * @{
 */

/*! @name LDTR000 - lddetread000 */
/*! @{ */

#define locald25_LDTR000_ldapla1_MASK            (0xFFFFU)
#define locald25_LDTR000_ldapla1_SHIFT           (0U)
/*! ldapla1 - ldapla1 */
#define locald25_LDTR000_ldapla1(x)              (((uint32_t)(((uint32_t)(x)) << locald25_LDTR000_ldapla1_SHIFT)) & locald25_LDTR000_ldapla1_MASK)

#define locald25_LDTR000_ldapla0_MASK            (0xFFFF0000U)
#define locald25_LDTR000_ldapla0_SHIFT           (16U)
/*! ldapla0 - ldapla0 */
#define locald25_LDTR000_ldapla0(x)              (((uint32_t)(((uint32_t)(x)) << locald25_LDTR000_ldapla0_SHIFT)) & locald25_LDTR000_ldapla0_MASK)
/*! @} */

/*! @name LDTRD001 - lddetread001 */
/*! @{ */

#define locald25_LDTRD001_ldapla3_MASK           (0xFFFFU)
#define locald25_LDTRD001_ldapla3_SHIFT          (0U)
/*! ldapla3 - ldapla3 */
#define locald25_LDTRD001_ldapla3(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD001_ldapla3_SHIFT)) & locald25_LDTRD001_ldapla3_MASK)

#define locald25_LDTRD001_ldapla2_MASK           (0xFFFF0000U)
#define locald25_LDTRD001_ldapla2_SHIFT          (16U)
/*! ldapla2 - ldapla2 */
#define locald25_LDTRD001_ldapla2(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD001_ldapla2_SHIFT)) & locald25_LDTRD001_ldapla2_MASK)
/*! @} */

/*! @name LDTRD002 - lddetread002 */
/*! @{ */

#define locald25_LDTRD002_ldaplb1_MASK           (0xFFFFU)
#define locald25_LDTRD002_ldaplb1_SHIFT          (0U)
/*! ldaplb1 - ldaplb1 */
#define locald25_LDTRD002_ldaplb1(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD002_ldaplb1_SHIFT)) & locald25_LDTRD002_ldaplb1_MASK)

#define locald25_LDTRD002_ldaplb0_MASK           (0xFFFF0000U)
#define locald25_LDTRD002_ldaplb0_SHIFT          (16U)
/*! ldaplb0 - ldaplb0 */
#define locald25_LDTRD002_ldaplb0(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD002_ldaplb0_SHIFT)) & locald25_LDTRD002_ldaplb0_MASK)
/*! @} */

/*! @name LDTRD003 - lddetread003 */
/*! @{ */

#define locald25_LDTRD003_ldaplb3_MASK           (0xFFFFU)
#define locald25_LDTRD003_ldaplb3_SHIFT          (0U)
/*! ldaplb3 - ldaplb3 */
#define locald25_LDTRD003_ldaplb3(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD003_ldaplb3_SHIFT)) & locald25_LDTRD003_ldaplb3_MASK)

#define locald25_LDTRD003_ldaplb2_MASK           (0xFFFF0000U)
#define locald25_LDTRD003_ldaplb2_SHIFT          (16U)
/*! ldaplb2 - ldaplb2 */
#define locald25_LDTRD003_ldaplb2(x)             (((uint32_t)(((uint32_t)(x)) << locald25_LDTRD003_ldaplb2_SHIFT)) & locald25_LDTRD003_ldaplb2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald25_Register_Masks */


/*!
 * @}
 */ /* end of group locald25_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD25_H_ */

