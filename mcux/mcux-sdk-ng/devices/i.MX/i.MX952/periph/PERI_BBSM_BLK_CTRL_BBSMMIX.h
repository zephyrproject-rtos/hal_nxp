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
**         CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
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
 * @file PERI_BBSM_BLK_CTRL_BBSMMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
 *
 * CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
 */

#if !defined(PERI_BBSM_BLK_CTRL_BBSMMIX_H_)
#define PERI_BBSM_BLK_CTRL_BBSMMIX_H_            /**< Symbol preventing repeated inclusion */

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
   -- BBSM_BLK_CTRL_BBSMMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BBSM_BLK_CTRL_BBSMMIX_Peripheral_Access_Layer BBSM_BLK_CTRL_BBSMMIX Peripheral Access Layer
 * @{
 */

/** BBSM_BLK_CTRL_BBSMMIX - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t SNVS_CLKRST_CTRL;                  /**< snvs_clkrst Control Register, offset: 0x4 */
} BBSM_BLK_CTRL_BBSMMIX_Type;

/* ----------------------------------------------------------------------------
   -- BBSM_BLK_CTRL_BBSMMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BBSM_BLK_CTRL_BBSMMIX_Register_Masks BBSM_BLK_CTRL_BBSMMIX Register Masks
 * @{
 */

/*! @name SNVS_CLKRST_CTRL - snvs_clkrst Control Register */
/*! @{ */

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_MASK (0xF0U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_SHIFT (4U)
/*! test_sel - Test select inputs
 *  0b0000..Normal functional mode
 *  0b1000..Bandgap buffer to ADC enabled for ADC test
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_test_sel_MASK)

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_MASK (0x2000U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_SHIFT (13U)
/*! tst_xtal_fast - Indicates that XTAL clock frequency is higher than 48 kHz
 *  0b0..XTAL clock is not too fast
 *  0b1..XTAL clock is too fast
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_MASK)

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK (0x4000U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT (14U)
/*! tst_xtal_slow - Indicates that XTAL clock frequency is lower than 20 kHz
 *  0b0..XTAL clock is not too slow
 *  0b1..XTAL clock is too slow
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK)

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_MASK (0x8000U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_SHIFT (15U)
/*! xtal_ok - Indicates XTAL clock is in frequency range and is the source of 32 kHz clock
 *  0b0..XTAL clock is not in frequency range and is not source of 32 kHz clock
 *  0b1..XTAL clock is in frequency range and is source of 32 kHz clock
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BBSM_BLK_CTRL_BBSMMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BBSM_BLK_CTRL_BBSMMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BBSM_BLK_CTRL_BBSMMIX_H_ */

