/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file BBSM_BLK_CTRL_BBSMMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
 *
 * CMSIS Peripheral Access Layer for BBSM_BLK_CTRL_BBSMMIX
 */

#if !defined(BBSM_BLK_CTRL_BBSMMIX_H_)
#define BBSM_BLK_CTRL_BBSMMIX_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
  __IO uint32_t SXOSC_CTRL;                        /**< SXOSC Control Register, offset: 0x0 */
  __IO uint32_t SNVS_CLKRST_CTRL;                  /**< snvs_clkrst Control Register, offset: 0x4 */
} BBSM_BLK_CTRL_BBSMMIX_Type;

/* ----------------------------------------------------------------------------
   -- BBSM_BLK_CTRL_BBSMMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BBSM_BLK_CTRL_BBSMMIX_Register_Masks BBSM_BLK_CTRL_BBSMMIX Register Masks
 * @{
 */

/*! @name SXOSC_CTRL - SXOSC Control Register */
/*! @{ */

#define BBSM_BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_MASK (0x10000U)
#define BBSM_BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_SHIFT (16U)
/*! pwd_lv - Power down/enable signal
 *  0b0..Power up
 *  0b1..Power down
 */
#define BBSM_BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SXOSC_CTRL_pwd_lv_MASK)
/*! @} */

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
/*! tst_xtal_fast - Indicates fast external XTAL crystal
 *  0b0..Fast external XTAL crystal is disabled
 *  0b1..Fast external XTAL crystal is enabled
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_fast_MASK)

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK (0x4000U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT (14U)
/*! tst_xtal_slow - Indicates slow external XTAL crystal
 *  0b1..Slow external XTAL crystal is enabled
 *  0b0..Slow external XTAL crystal is disabled
 */
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow(x) (((uint32_t)(((uint32_t)(x)) << BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_SHIFT)) & BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_tst_xtal_slow_MASK)

#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_MASK (0x8000U)
#define BBSM_BLK_CTRL_BBSMMIX_SNVS_CLKRST_CTRL_xtal_ok_SHIFT (15U)
/*! xtal_ok - Indicates XTAL clock is in frequency range and source of 32 kHz clock
 *  0b0..XTAL clock is not in frequency range and source of 32 KHz clock
 *  0b1..XTAL clock is in frequency range and source of 32 KHz clock
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


#endif  /* BBSM_BLK_CTRL_BBSMMIX_H_ */

