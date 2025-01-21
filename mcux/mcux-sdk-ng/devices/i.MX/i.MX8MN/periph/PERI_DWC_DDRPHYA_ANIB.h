/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 2.0, 2019-09-23
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**
** ###################################################################
*/

/*!
 * @file DWC_DDRPHYA_ANIB.h
 * @version 2.0
 * @date 2019-09-23
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
 */

#if !defined(DWC_DDRPHYA_ANIB_H_)
#define DWC_DDRPHYA_ANIB_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- DWC_DDRPHYA_ANIB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_ANIB_Peripheral_Access_Layer DWC_DDRPHYA_ANIB Peripheral Access Layer
 * @{
 */

/** DWC_DDRPHYA_ANIB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[52];
  __IO uint16_t MTESTMUXSEL;                       /**< Digital Observation Pin control, offset: 0x34 */
       uint8_t RESERVED_1[24];
  __IO uint16_t AFORCEDRVCONT;                     /**< Force Address/Command Driven (Lanes A3-A0), offset: 0x4E */
  __IO uint16_t AFORCETRICONT;                     /**< Force Address/Command Tristate (Lanes A3-A0), offset: 0x50 */
       uint8_t RESERVED_2[52];
  __IO uint16_t ATXIMPEDANCE;                      /**< Address TX impedance controls, offset: 0x86 */
       uint8_t RESERVED_3[30];
  __I  uint16_t ATESTPRBSERR;                      /**< Address Loopback PRBS Error status for an entire ACX4 block, offset: 0xA6 */
       uint8_t RESERVED_4[2];
  __IO uint16_t ATXSLEWRATE;                       /**< Address TX slew rate and predriver controls, offset: 0xAA */
  __I  uint16_t ATESTPRBSERRCNT;                   /**< Address Loopback Test Result register, offset: 0xAC */
       uint8_t RESERVED_5[82];
  __IO uint16_t ATXDLY_P0;                         /**< Address/Command Delay, per pstate., offset: 0x100 */
       uint8_t RESERVED_6[2097150];
  __IO uint16_t ATXDLY_P1;                         /**< Address/Command Delay, per pstate., offset: 0x200100 */
       uint8_t RESERVED_7[2097150];
  __IO uint16_t ATXDLY_P2;                         /**< Address/Command Delay, per pstate., offset: 0x400100 */
       uint8_t RESERVED_8[2097150];
  __IO uint16_t ATXDLY_P3;                         /**< Address/Command Delay, per pstate., offset: 0x600100 */
} DWC_DDRPHYA_ANIB_Type;

/* ----------------------------------------------------------------------------
   -- DWC_DDRPHYA_ANIB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DWC_DDRPHYA_ANIB_Register_Masks DWC_DDRPHYA_ANIB Register Masks
 * @{
 */

/*! @name MTESTMUXSEL - Digital Observation Pin control */
/*! @{ */

#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MtestMuxSel_MASK (0x3FU)
#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MtestMuxSel_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MtestMuxSel(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_MTESTMUXSEL_MtestMuxSel_SHIFT)) & DWC_DDRPHYA_ANIB_MTESTMUXSEL_MtestMuxSel_MASK)
/*! @} */

/*! @name AFORCEDRVCONT - Force Address/Command Driven (Lanes A3-A0) */
/*! @{ */

#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AForceDrvCont_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AForceDrvCont_SHIFT (0U)
/*! AForceDrvCont - Force continuous drive, per-lane, of the ACX4 instance controlled by this
 *    register Setting this register will cause the PHY to drive the target lane when dfi_init_complete==1
 *    Bit [0] = controls lane 0 of the target ACX4 block Bit [1] = controls lane 1 of the target
 *    ACX4 block Bit [2] = controls lane 2 of the target ACX4 block Bit [3] = controls lane 3 of the
 *    target ACX4 block
 */
#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AForceDrvCont(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AForceDrvCont_SHIFT)) & DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AForceDrvCont_MASK)
/*! @} */

/*! @name AFORCETRICONT - Force Address/Command Tristate (Lanes A3-A0) */
/*! @{ */

#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AForceTriCont_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AForceTriCont_SHIFT (0U)
/*! AForceTriCont - Force tristate control, per-lane, of the ACX4 instance controlled by this
 *    register Setting this register will cause the PHY to tristate the target lane when
 *    dfi_init_complete==1 Bit [0] = controls lane 0 of the target ACX4 block Bit [1] = controls lane 1 of the target
 *    ACX4 block Bit [2] = controls lane 2 of the target ACX4 block Bit [3] = controls lane 3 of
 *    the target ACX4 block
 */
#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AForceTriCont(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_AFORCETRICONT_AForceTriCont_SHIFT)) & DWC_DDRPHYA_ANIB_AFORCETRICONT_AForceTriCont_MASK)
/*! @} */

/*! @name ATXIMPEDANCE - Address TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenP_MASK (0x1FU)
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenP_SHIFT (0U)
/*! ADrvStrenP - 5 bit bus used to select the target pull up output impedance. */
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenP_SHIFT)) & DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenP_MASK)

#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenN_MASK (0x3E0U)
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenN_SHIFT (5U)
/*! ADrvStrenN - 5 bit bus used to select the target pull down output impedance. */
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenN_SHIFT)) & DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADrvStrenN_MASK)
/*! @} */

/*! @name ATESTPRBSERR - Address Loopback PRBS Error status for an entire ACX4 block */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATestPrbsErr_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATestPrbsErr_SHIFT (0U)
/*! ATestPrbsErr - Overall error indicator for each prbs bump checker. */
#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATestPrbsErr(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATestPrbsErr_SHIFT)) & DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATestPrbsErr_MASK)
/*! @} */

/*! @name ATXSLEWRATE - Address TX slew rate and predriver controls */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreP_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreP_SHIFT (0U)
/*! ATxPreP - 4 bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreP(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreP_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreP_MASK)

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreN_MASK (0xF0U)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreN_SHIFT (4U)
/*! ATxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreN(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreN_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreN_MASK)

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreDrvMode_MASK (0x700U)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreDrvMode_SHIFT (8U)
/*! ATxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreDrvMode(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreDrvMode_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATxPreDrvMode_MASK)
/*! @} */

/*! @name ATESTPRBSERRCNT - Address Loopback Test Result register */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATestPrbsErrCnt_MASK (0xFFFFU)
#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATestPrbsErrCnt_SHIFT (0U)
/*! ATestPrbsErrCnt - Overall error indicator for each prbs bump checker. */
#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATestPrbsErrCnt(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATestPrbsErrCnt_SHIFT)) & DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATestPrbsErrCnt_MASK)
/*! @} */

/*! @name ATXDLY_P0 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATxDly_p0_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATxDly_p0_SHIFT (0U)
/*! ATxDly_p0 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATxDly_p0(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P0_ATxDly_p0_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P0_ATxDly_p0_MASK)
/*! @} */

/*! @name ATXDLY_P1 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATxDly_p1_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATxDly_p1_SHIFT (0U)
/*! ATxDly_p1 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATxDly_p1(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P1_ATxDly_p1_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P1_ATxDly_p1_MASK)
/*! @} */

/*! @name ATXDLY_P2 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATxDly_p2_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATxDly_p2_SHIFT (0U)
/*! ATxDly_p2 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATxDly_p2(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P2_ATxDly_p2_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P2_ATxDly_p2_MASK)
/*! @} */

/*! @name ATXDLY_P3 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATxDly_p3_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATxDly_p3_SHIFT (0U)
/*! ATxDly_p3 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATxDly_p3(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P3_ATxDly_p3_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P3_ATxDly_p3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_ANIB_Register_Masks */


/*!
 * @}
 */ /* end of group DWC_DDRPHYA_ANIB_Peripheral_Access_Layer */


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


#endif  /* DWC_DDRPHYA_ANIB_H_ */

