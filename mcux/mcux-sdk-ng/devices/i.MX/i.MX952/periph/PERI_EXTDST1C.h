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
**         CMSIS Peripheral Access Layer for extdst1c
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
 * @file PERI_extdst1c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for extdst1c
 *
 * CMSIS Peripheral Access Layer for extdst1c
 */

#if !defined(PERI_EXTDST1C_H_)
#define PERI_EXTDST1C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- extdst1c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst1c_Peripheral_Access_Layer extdst1c Peripheral Access Layer
 * @{
 */

/** extdst1c - Register Layout Typedef */
typedef struct {
  __O  uint32_t EXTD1LU;                           /**< extdst1_LockUnlock, offset: 0x0 */
  __I  uint32_t EXTD1LS;                           /**< extdst1_LockStatus, offset: 0x4 */
  __IO uint32_t EXTD1S;                            /**< extdst1_Static, offset: 0x8 */
  __IO uint32_t EXTD1D;                            /**< extdst1_Dynamic, offset: 0xC */
  __IO uint32_t EXTD1R;                            /**< extdst1_Request, offset: 0x10 */
  __O  uint32_t EXTD1TR;                           /**< extdst1_Trigger, offset: 0x14 */
  __I  uint32_t EXTD1ST;                           /**< extdst1_Status, offset: 0x18 */
} extdst1c_Type;

/* ----------------------------------------------------------------------------
   -- extdst1c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst1c_Register_Masks extdst1c Register Masks
 * @{
 */

/*! @name EXTD1LU - extdst1_LockUnlock */
/*! @{ */

#define extdst1c_EXTD1LU_exd1LUnl_MASK           (0xFFFFFFFFU)
#define extdst1c_EXTD1LU_exd1LUnl_SHIFT          (0U)
/*! exd1LUnl - extdst1_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define extdst1c_EXTD1LU_exd1LUnl(x)             (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1LU_exd1LUnl_SHIFT)) & extdst1c_EXTD1LU_exd1LUnl_MASK)
/*! @} */

/*! @name EXTD1LS - extdst1_LockStatus */
/*! @{ */

#define extdst1c_EXTD1LS_exd1LS_MASK             (0x1U)
#define extdst1c_EXTD1LS_exd1LS_SHIFT            (0U)
/*! exd1LS - extdst1_LockStatus */
#define extdst1c_EXTD1LS_exd1LS(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1LS_exd1LS_SHIFT)) & extdst1c_EXTD1LS_exd1LS_MASK)

#define extdst1c_EXTD1LS_exd1PS_MASK             (0x10U)
#define extdst1c_EXTD1LS_exd1PS_SHIFT            (4U)
/*! exd1PS - extdst1_PrivilegeStatus */
#define extdst1c_EXTD1LS_exd1PS(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1LS_exd1PS_SHIFT)) & extdst1c_EXTD1LS_exd1PS_MASK)

#define extdst1c_EXTD1LS_exd1FS_MASK             (0x100U)
#define extdst1c_EXTD1LS_exd1FS_SHIFT            (8U)
/*! exd1FS - extdst1_FreezeStatus */
#define extdst1c_EXTD1LS_exd1FS(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1LS_exd1FS_SHIFT)) & extdst1c_EXTD1LS_exd1FS_MASK)
/*! @} */

/*! @name EXTD1S - extdst1_Static */
/*! @{ */

#define extdst1c_EXTD1S_exd1ShdE_MASK            (0x1U)
#define extdst1c_EXTD1S_exd1ShdE_SHIFT           (0U)
/*! exd1ShdE - extdst1_ShdEn */
#define extdst1c_EXTD1S_exd1ShdE(x)              (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1S_exd1ShdE_SHIFT)) & extdst1c_EXTD1S_exd1ShdE_MASK)

#define extdst1c_EXTD1S_exd1podo_MASK            (0x10U)
#define extdst1c_EXTD1S_exd1podo_SHIFT           (4U)
/*! exd1podo - extdst1_powerdown */
#define extdst1c_EXTD1S_exd1podo(x)              (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1S_exd1podo_SHIFT)) & extdst1c_EXTD1S_exd1podo_MASK)

#define extdst1c_EXTD1S_exd1SM_MASK              (0x100U)
#define extdst1c_EXTD1S_exd1SM_SHIFT             (8U)
/*! exd1SM - extdst1_Sync_Mode
 *  0b0..Reconfig pipeline after explicit trigger
 *  0b1..Reconfig pipeline after every kick when idle
 */
#define extdst1c_EXTD1S_exd1SM(x)                (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1S_exd1SM_SHIFT)) & extdst1c_EXTD1S_exd1SM_MASK)

#define extdst1c_EXTD1S_exd1SWR_MASK             (0x800U)
#define extdst1c_EXTD1S_exd1SWR_SHIFT            (11U)
/*! exd1SWR - extdst1_SW_Reset
 *  0b0..Normal Operation
 *  0b1..Software Reset
 */
#define extdst1c_EXTD1S_exd1SWR(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1S_exd1SWR_SHIFT)) & extdst1c_EXTD1S_exd1SWR_MASK)

#define extdst1c_EXTD1S_exd1div_MASK             (0xFF0000U)
#define extdst1c_EXTD1S_exd1div_SHIFT            (16U)
/*! exd1div - extdst1_div */
#define extdst1c_EXTD1S_exd1div(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1S_exd1div_SHIFT)) & extdst1c_EXTD1S_exd1div_MASK)
/*! @} */

/*! @name EXTD1D - extdst1_Dynamic */
/*! @{ */

#define extdst1c_EXTD1D_exd1ssel_MASK            (0x3FU)
#define extdst1c_EXTD1D_exd1ssel_SHIFT           (0U)
/*! exd1ssel - extdst1_src_sel
 *  0b000000..Unit extdst1 input port src is disabled
 *  0b010100..Unit extdst1 input port src is connected to output of unit layerblend1
 *  0b010101..Unit extdst1 input port src is connected to output of unit layerblend2
 *  0b010110..Unit extdst1 input port src is connected to output of unit layerblend3
 *  0b010111..Unit extdst1 input port src is connected to output of unit layerblend4
 *  0b011000..Unit extdst1 input port src is connected to output of unit layerblend5
 */
#define extdst1c_EXTD1D_exd1ssel(x)              (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1D_exd1ssel_SHIFT)) & extdst1c_EXTD1D_exd1ssel_MASK)
/*! @} */

/*! @name EXTD1R - extdst1_Request */
/*! @{ */

#define extdst1c_EXTD1R_exd1sSLR_MASK            (0x1U)
#define extdst1c_EXTD1R_exd1sSLR_SHIFT           (0U)
/*! exd1sSLR - extdst1_sel_ShdLdReq */
#define extdst1c_EXTD1R_exd1sSLR(x)              (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1R_exd1sSLR_SHIFT)) & extdst1c_EXTD1R_exd1sSLR_MASK)

#define extdst1c_EXTD1R_exd1SLR_MASK             (0x7FFEU)
#define extdst1c_EXTD1R_exd1SLR_SHIFT            (1U)
/*! exd1SLR - extdst1_ShdLdReq */
#define extdst1c_EXTD1R_exd1SLR(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1R_exd1SLR_SHIFT)) & extdst1c_EXTD1R_exd1SLR_MASK)
/*! @} */

/*! @name EXTD1TR - extdst1_Trigger */
/*! @{ */

#define extdst1c_EXTD1TR_exd1ST_MASK             (0x1U)
#define extdst1c_EXTD1TR_exd1ST_SHIFT            (0U)
/*! exd1ST - extdst1_Sync_Trigger */
#define extdst1c_EXTD1TR_exd1ST(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1TR_exd1ST_SHIFT)) & extdst1c_EXTD1TR_exd1ST_MASK)

#define extdst1c_EXTD1TR_exd1tsc_MASK            (0x10U)
#define extdst1c_EXTD1TR_exd1tsc_SHIFT           (4U)
/*! exd1tsc - extdst1_trigger_sequence_complete */
#define extdst1c_EXTD1TR_exd1tsc(x)              (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1TR_exd1tsc_SHIFT)) & extdst1c_EXTD1TR_exd1tsc_MASK)
/*! @} */

/*! @name EXTD1ST - extdst1_Status */
/*! @{ */

#define extdst1c_EXTD1ST_exd1pist_MASK           (0x3U)
#define extdst1c_EXTD1ST_exd1pist_SHIFT          (0U)
/*! exd1pist - extdst1_pipeline_status
 *  0b00..Pipeline with endpoint extdst1 is empty
 *  0b01..Pipeline with endpoint extdst1 is currently processing one operation
 *  0b10..Pipeline with endpoint extdst1 is currently processing one operation with a second one already kicked to be processed afterwards
 *  0b11..reserved
 */
#define extdst1c_EXTD1ST_exd1pist(x)             (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1ST_exd1pist_SHIFT)) & extdst1c_EXTD1ST_exd1pist_MASK)

#define extdst1c_EXTD1ST_exd1sb_MASK             (0x100U)
#define extdst1c_EXTD1ST_exd1sb_SHIFT            (8U)
/*! exd1sb - extdst1_sync_busy
 *  0b0..extdst1 synchronizer is idle
 *  0b1..extdst1 synchronizer is busy
 */
#define extdst1c_EXTD1ST_exd1sb(x)               (((uint32_t)(((uint32_t)(x)) << extdst1c_EXTD1ST_exd1sb_SHIFT)) & extdst1c_EXTD1ST_exd1sb_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group extdst1c_Register_Masks */


/*!
 * @}
 */ /* end of group extdst1c_Peripheral_Access_Layer */


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


#endif  /* PERI_EXTDST1C_H_ */

