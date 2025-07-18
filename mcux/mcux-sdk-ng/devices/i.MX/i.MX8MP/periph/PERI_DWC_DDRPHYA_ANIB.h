/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DWC_DDRPHYA_ANIB.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
 *
 * CMSIS Peripheral Access Layer for DWC_DDRPHYA_ANIB
 */

#if !defined(PERI_DWC_DDRPHYA_ANIB_H_)
#define PERI_DWC_DDRPHYA_ANIB_H_                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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

#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MTESTMUXSEL_MASK (0x3FU)
#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MTESTMUXSEL_SHIFT (0U)
/*! MtestMuxSel - Controls for the 64-1 mux for asynchronous data to the Digital Observation Pin. */
#define DWC_DDRPHYA_ANIB_MTESTMUXSEL_MTESTMUXSEL(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_MTESTMUXSEL_MTESTMUXSEL_SHIFT)) & DWC_DDRPHYA_ANIB_MTESTMUXSEL_MTESTMUXSEL_MASK)
/*! @} */

/*! @name AFORCEDRVCONT - Force Address/Command Driven (Lanes A3-A0) */
/*! @{ */

#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AFORCEDRVCONT_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AFORCEDRVCONT_SHIFT (0U)
/*! AForceDrvCont - Force continuous drive, per-lane, of the ACX4 instance controlled by this
 *    register Setting this register will cause the PHY to drive the target lane when dfi_init_complete==1
 *    Bit [0] = controls lane 0 of the target ACX4 block Bit [1] = controls lane 1 of the target
 *    ACX4 block Bit [2] = controls lane 2 of the target ACX4 block Bit [3] = controls lane 3 of the
 *    target ACX4 block
 */
#define DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AFORCEDRVCONT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AFORCEDRVCONT_SHIFT)) & DWC_DDRPHYA_ANIB_AFORCEDRVCONT_AFORCEDRVCONT_MASK)
/*! @} */

/*! @name AFORCETRICONT - Force Address/Command Tristate (Lanes A3-A0) */
/*! @{ */

#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AFORCETRICONT_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AFORCETRICONT_SHIFT (0U)
/*! AForceTriCont - Force tristate control, per-lane, of the ACX4 instance controlled by this
 *    register Setting this register will cause the PHY to tristate the target lane when
 *    dfi_init_complete==1 Bit [0] = controls lane 0 of the target ACX4 block Bit [1] = controls lane 1 of the target
 *    ACX4 block Bit [2] = controls lane 2 of the target ACX4 block Bit [3] = controls lane 3 of
 *    the target ACX4 block
 */
#define DWC_DDRPHYA_ANIB_AFORCETRICONT_AFORCETRICONT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_AFORCETRICONT_AFORCETRICONT_SHIFT)) & DWC_DDRPHYA_ANIB_AFORCETRICONT_AFORCETRICONT_MASK)
/*! @} */

/*! @name ATXIMPEDANCE - Address TX impedance controls */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENP_MASK (0x1FU)
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENP_SHIFT (0U)
/*! ADrvStrenP - 5 bit bus used to select the target pull up output impedance. */
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENP(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENP_SHIFT)) & DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENP_MASK)

#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENN_MASK (0x3E0U)
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENN_SHIFT (5U)
/*! ADrvStrenN - 5 bit bus used to select the target pull down output impedance. */
#define DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENN(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENN_SHIFT)) & DWC_DDRPHYA_ANIB_ATXIMPEDANCE_ADRVSTRENN_MASK)
/*! @} */

/*! @name ATESTPRBSERR - Address Loopback PRBS Error status for an entire ACX4 block */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATESTPRBSERR_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATESTPRBSERR_SHIFT (0U)
/*! ATestPrbsErr - Overall error indicator for each prbs bump checker. */
#define DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATESTPRBSERR(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATESTPRBSERR_SHIFT)) & DWC_DDRPHYA_ANIB_ATESTPRBSERR_ATESTPRBSERR_MASK)
/*! @} */

/*! @name ATXSLEWRATE - Address TX slew rate and predriver controls */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREP_MASK (0xFU)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREP_SHIFT (0U)
/*! ATxPreP - 4 bit binary trim for the driver pull up slew rate. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREP(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREP_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREP_MASK)

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREN_MASK (0xF0U)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREN_SHIFT (4U)
/*! ATxPreN - 4 bit binary trim for the driver pull down slew rate. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREN(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREN_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREN_MASK)

#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREDRVMODE_MASK (0x700U)
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREDRVMODE_SHIFT (8U)
/*! ATxPreDrvMode - Controls predrivers to adjust timing of turn-on and turn-off of pull-up and pull-down segments. */
#define DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREDRVMODE(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREDRVMODE_SHIFT)) & DWC_DDRPHYA_ANIB_ATXSLEWRATE_ATXPREDRVMODE_MASK)
/*! @} */

/*! @name ATESTPRBSERRCNT - Address Loopback Test Result register */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATESTPRBSERRCNT_MASK (0xFFFFU)
#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATESTPRBSERRCNT_SHIFT (0U)
/*! ATestPrbsErrCnt - Overall error indicator for each prbs bump checker. */
#define DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATESTPRBSERRCNT(x) (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATESTPRBSERRCNT_SHIFT)) & DWC_DDRPHYA_ANIB_ATESTPRBSERRCNT_ATESTPRBSERRCNT_MASK)
/*! @} */

/*! @name ATXDLY_P0 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATXDLY_P0_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATXDLY_P0_SHIFT (0U)
/*! ATxDly_p0 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P0_ATXDLY_P0(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P0_ATXDLY_P0_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P0_ATXDLY_P0_MASK)
/*! @} */

/*! @name ATXDLY_P1 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATXDLY_P1_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATXDLY_P1_SHIFT (0U)
/*! ATxDly_p1 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P1_ATXDLY_P1(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P1_ATXDLY_P1_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P1_ATXDLY_P1_MASK)
/*! @} */

/*! @name ATXDLY_P2 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATXDLY_P2_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATXDLY_P2_SHIFT (0U)
/*! ATxDly_p2 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P2_ATXDLY_P2(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P2_ATXDLY_P2_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P2_ATXDLY_P2_MASK)
/*! @} */

/*! @name ATXDLY_P3 - Address/Command Delay, per pstate. */
/*! @{ */

#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATXDLY_P3_MASK (0x7FU)
#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATXDLY_P3_SHIFT (0U)
/*! ATxDly_p3 - Trained for LPDDR3/4 to generate timed address and command signals to the DRAMs, per ACX4. */
#define DWC_DDRPHYA_ANIB_ATXDLY_P3_ATXDLY_P3(x)  (((uint16_t)(((uint16_t)(x)) << DWC_DDRPHYA_ANIB_ATXDLY_P3_ATXDLY_P3_SHIFT)) & DWC_DDRPHYA_ANIB_ATXDLY_P3_ATXDLY_P3_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DWC_DDRPHYA_ANIB_H_ */

