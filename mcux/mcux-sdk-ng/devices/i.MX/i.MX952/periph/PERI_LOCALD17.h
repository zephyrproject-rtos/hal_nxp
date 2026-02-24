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
**         CMSIS Peripheral Access Layer for locald17
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
 * @file PERI_locald17.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for locald17
 *
 * CMSIS Peripheral Access Layer for locald17
 */

#if !defined(PERI_LOCALD17_H_)
#define PERI_LOCALD17_H_                         /**< Symbol preventing repeated inclusion */

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
   -- locald17 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald17_Peripheral_Access_Layer locald17 Peripheral Access Layer
 * @{
 */

/** locald17 - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDBLR000;                          /**< ldblreg000, offset: 0x0 */
  __IO uint32_t LDBLR001;                          /**< ldblreg001, offset: 0x4 */
  __IO uint32_t LDBLR002;                          /**< ldblreg002, offset: 0x8 */
  __IO uint32_t LDBLR003;                          /**< ldblreg003, offset: 0xC */
  __IO uint32_t LDBLR004;                          /**< ldblreg004, offset: 0x10 */
} locald17_Type;

/* ----------------------------------------------------------------------------
   -- locald17 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup locald17_Register_Masks locald17 Register Masks
 * @{
 */

/*! @name LDBLR000 - ldblreg000 */
/*! @{ */

#define locald17_LDBLR000_blselect_MASK          (0x30000000U)
#define locald17_LDBLR000_blselect_SHIFT         (28U)
/*! blselect - blselect */
#define locald17_LDBLR000_blselect(x)            (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR000_blselect_SHIFT)) & locald17_LDBLR000_blselect_MASK)
/*! @} */

/*! @name LDBLR001 - ldblreg001 */
/*! @{ */

#define locald17_LDBLR001_blpgain_MASK           (0x1FFFU)
#define locald17_LDBLR001_blpgain_SHIFT          (0U)
/*! blpgain - blpgain */
#define locald17_LDBLR001_blpgain(x)             (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR001_blpgain_SHIFT)) & locald17_LDBLR001_blpgain_MASK)

#define locald17_LDBLR001_bllimith_MASK          (0xFFFF0000U)
#define locald17_LDBLR001_bllimith_SHIFT         (16U)
/*! bllimith - bllimit_h */
#define locald17_LDBLR001_bllimith(x)            (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR001_bllimith_SHIFT)) & locald17_LDBLR001_bllimith_MASK)
/*! @} */

/*! @name LDBLR002 - ldblreg002 */
/*! @{ */

#define locald17_LDBLR002_bloffset_MASK          (0xFFFU)
#define locald17_LDBLR002_bloffset_SHIFT         (0U)
/*! bloffset - bloffset */
#define locald17_LDBLR002_bloffset(x)            (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR002_bloffset_SHIFT)) & locald17_LDBLR002_bloffset_MASK)

#define locald17_LDBLR002_blgain_MASK            (0xFFF0000U)
#define locald17_LDBLR002_blgain_SHIFT           (16U)
/*! blgain - blgain */
#define locald17_LDBLR002_blgain(x)              (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR002_blgain_SHIFT)) & locald17_LDBLR002_blgain_MASK)
/*! @} */

/*! @name LDBLR003 - ldblreg003 */
/*! @{ */

#define locald17_LDBLR003_blpwmwi_MASK           (0x1FFFFU)
#define locald17_LDBLR003_blpwmwi_SHIFT          (0U)
/*! blpwmwi - blpwmwidth */
#define locald17_LDBLR003_blpwmwi(x)             (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR003_blpwmwi_SHIFT)) & locald17_LDBLR003_blpwmwi_MASK)

#define locald17_LDBLR003_blbyrev_MASK           (0x100000U)
#define locald17_LDBLR003_blbyrev_SHIFT          (20U)
/*! blbyrev - blbyterev */
#define locald17_LDBLR003_blbyrev(x)             (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR003_blbyrev_SHIFT)) & locald17_LDBLR003_blbyrev_MASK)

#define locald17_LDBLR003_blbitrev_MASK          (0x200000U)
#define locald17_LDBLR003_blbitrev_SHIFT         (21U)
/*! blbitrev - blbitrev */
#define locald17_LDBLR003_blbitrev(x)            (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR003_blbitrev_SHIFT)) & locald17_LDBLR003_blbitrev_MASK)

#define locald17_LDBLR003_blformat_MASK          (0x7000000U)
#define locald17_LDBLR003_blformat_SHIFT         (24U)
/*! blformat - blformat */
#define locald17_LDBLR003_blformat(x)            (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR003_blformat_SHIFT)) & locald17_LDBLR003_blformat_MASK)
/*! @} */

/*! @name LDBLR004 - ldblreg004 */
/*! @{ */

#define locald17_LDBLR004_ldvashi_MASK           (0x1U)
#define locald17_LDBLR004_ldvashi_SHIFT          (0U)
/*! ldvashi - ldvashift */
#define locald17_LDBLR004_ldvashi(x)             (((uint32_t)(((uint32_t)(x)) << locald17_LDBLR004_ldvashi_SHIFT)) & locald17_LDBLR004_ldvashi_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group locald17_Register_Masks */


/*!
 * @}
 */ /* end of group locald17_Peripheral_Access_Layer */


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


#endif  /* PERI_LOCALD17_H_ */

