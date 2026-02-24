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
**         CMSIS Peripheral Access Layer for extdst5c
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
 * @file PERI_extdst5c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for extdst5c
 *
 * CMSIS Peripheral Access Layer for extdst5c
 */

#if !defined(PERI_EXTDST5C_H_)
#define PERI_EXTDST5C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- extdst5c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst5c_Peripheral_Access_Layer extdst5c Peripheral Access Layer
 * @{
 */

/** extdst5c - Register Layout Typedef */
typedef struct {
  __O  uint32_t EXTD5LU;                           /**< extdst5_LockUnlock, offset: 0x0 */
  __I  uint32_t EXTD5LS;                           /**< extdst5_LockStatus, offset: 0x4 */
  __IO uint32_t EXTD5S;                            /**< extdst5_Static, offset: 0x8 */
  __IO uint32_t EXTD5D;                            /**< extdst5_Dynamic, offset: 0xC */
  __IO uint32_t EXTD5R;                            /**< extdst5_Request, offset: 0x10 */
  __O  uint32_t EXTD5TR;                           /**< extdst5_Trigger, offset: 0x14 */
  __I  uint32_t EXTD5ST;                           /**< extdst5_Status, offset: 0x18 */
} extdst5c_Type;

/* ----------------------------------------------------------------------------
   -- extdst5c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst5c_Register_Masks extdst5c Register Masks
 * @{
 */

/*! @name EXTD5LU - extdst5_LockUnlock */
/*! @{ */

#define extdst5c_EXTD5LU_exd5LUnl_MASK           (0xFFFFFFFFU)
#define extdst5c_EXTD5LU_exd5LUnl_SHIFT          (0U)
/*! exd5LUnl - extdst5_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define extdst5c_EXTD5LU_exd5LUnl(x)             (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5LU_exd5LUnl_SHIFT)) & extdst5c_EXTD5LU_exd5LUnl_MASK)
/*! @} */

/*! @name EXTD5LS - extdst5_LockStatus */
/*! @{ */

#define extdst5c_EXTD5LS_exd5LS_MASK             (0x1U)
#define extdst5c_EXTD5LS_exd5LS_SHIFT            (0U)
/*! exd5LS - extdst5_LockStatus */
#define extdst5c_EXTD5LS_exd5LS(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5LS_exd5LS_SHIFT)) & extdst5c_EXTD5LS_exd5LS_MASK)

#define extdst5c_EXTD5LS_exd5PS_MASK             (0x10U)
#define extdst5c_EXTD5LS_exd5PS_SHIFT            (4U)
/*! exd5PS - extdst5_PrivilegeStatus */
#define extdst5c_EXTD5LS_exd5PS(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5LS_exd5PS_SHIFT)) & extdst5c_EXTD5LS_exd5PS_MASK)

#define extdst5c_EXTD5LS_exd5FS_MASK             (0x100U)
#define extdst5c_EXTD5LS_exd5FS_SHIFT            (8U)
/*! exd5FS - extdst5_FreezeStatus */
#define extdst5c_EXTD5LS_exd5FS(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5LS_exd5FS_SHIFT)) & extdst5c_EXTD5LS_exd5FS_MASK)
/*! @} */

/*! @name EXTD5S - extdst5_Static */
/*! @{ */

#define extdst5c_EXTD5S_exd5ShEn_MASK            (0x1U)
#define extdst5c_EXTD5S_exd5ShEn_SHIFT           (0U)
/*! exd5ShEn - extdst5_ShdEn */
#define extdst5c_EXTD5S_exd5ShEn(x)              (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5S_exd5ShEn_SHIFT)) & extdst5c_EXTD5S_exd5ShEn_MASK)

#define extdst5c_EXTD5S_exd5podo_MASK            (0x10U)
#define extdst5c_EXTD5S_exd5podo_SHIFT           (4U)
/*! exd5podo - extdst5_powerdown */
#define extdst5c_EXTD5S_exd5podo(x)              (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5S_exd5podo_SHIFT)) & extdst5c_EXTD5S_exd5podo_MASK)

#define extdst5c_EXTD5S_exd5SM_MASK              (0x100U)
#define extdst5c_EXTD5S_exd5SM_SHIFT             (8U)
/*! exd5SM - extdst5_Sync_Mode
 *  0b0..Reconfig pipeline after explicit trigger
 *  0b1..Reconfig pipeline after every kick when idle
 */
#define extdst5c_EXTD5S_exd5SM(x)                (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5S_exd5SM_SHIFT)) & extdst5c_EXTD5S_exd5SM_MASK)

#define extdst5c_EXTD5S_exd5SWR_MASK             (0x800U)
#define extdst5c_EXTD5S_exd5SWR_SHIFT            (11U)
/*! exd5SWR - extdst5_SW_Reset
 *  0b0..Normal Operation
 *  0b1..Software Reset
 */
#define extdst5c_EXTD5S_exd5SWR(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5S_exd5SWR_SHIFT)) & extdst5c_EXTD5S_exd5SWR_MASK)

#define extdst5c_EXTD5S_exd5div_MASK             (0xFF0000U)
#define extdst5c_EXTD5S_exd5div_SHIFT            (16U)
/*! exd5div - extdst5_div */
#define extdst5c_EXTD5S_exd5div(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5S_exd5div_SHIFT)) & extdst5c_EXTD5S_exd5div_MASK)
/*! @} */

/*! @name EXTD5D - extdst5_Dynamic */
/*! @{ */

#define extdst5c_EXTD5D_exd5ssel_MASK            (0x3FU)
#define extdst5c_EXTD5D_exd5ssel_SHIFT           (0U)
/*! exd5ssel - extdst5_src_sel
 *  0b000000..Unit extdst5 input port src is disabled
 *  0b010100..Unit extdst5 input port src is connected to output of unit layerblend1
 *  0b010101..Unit extdst5 input port src is connected to output of unit layerblend2
 *  0b010110..Unit extdst5 input port src is connected to output of unit layerblend3
 *  0b010111..Unit extdst5 input port src is connected to output of unit layerblend4
 *  0b011000..Unit extdst5 input port src is connected to output of unit layerblend5
 */
#define extdst5c_EXTD5D_exd5ssel(x)              (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5D_exd5ssel_SHIFT)) & extdst5c_EXTD5D_exd5ssel_MASK)
/*! @} */

/*! @name EXTD5R - extdst5_Request */
/*! @{ */

#define extdst5c_EXTD5R_exd5sSLR_MASK            (0x1U)
#define extdst5c_EXTD5R_exd5sSLR_SHIFT           (0U)
/*! exd5sSLR - extdst5_sel_ShdLdReq */
#define extdst5c_EXTD5R_exd5sSLR(x)              (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5R_exd5sSLR_SHIFT)) & extdst5c_EXTD5R_exd5sSLR_MASK)

#define extdst5c_EXTD5R_exd5SLR_MASK             (0x7FFEU)
#define extdst5c_EXTD5R_exd5SLR_SHIFT            (1U)
/*! exd5SLR - extdst5_ShdLdReq */
#define extdst5c_EXTD5R_exd5SLR(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5R_exd5SLR_SHIFT)) & extdst5c_EXTD5R_exd5SLR_MASK)
/*! @} */

/*! @name EXTD5TR - extdst5_Trigger */
/*! @{ */

#define extdst5c_EXTD5TR_exd5ST_MASK             (0x1U)
#define extdst5c_EXTD5TR_exd5ST_SHIFT            (0U)
/*! exd5ST - extdst5_Sync_Trigger */
#define extdst5c_EXTD5TR_exd5ST(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5TR_exd5ST_SHIFT)) & extdst5c_EXTD5TR_exd5ST_MASK)

#define extdst5c_EXTD5TR_exd5tsc_MASK            (0x10U)
#define extdst5c_EXTD5TR_exd5tsc_SHIFT           (4U)
/*! exd5tsc - extdst5_trigger_sequence_complete */
#define extdst5c_EXTD5TR_exd5tsc(x)              (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5TR_exd5tsc_SHIFT)) & extdst5c_EXTD5TR_exd5tsc_MASK)
/*! @} */

/*! @name EXTD5ST - extdst5_Status */
/*! @{ */

#define extdst5c_EXTD5ST_exd5pist_MASK           (0x3U)
#define extdst5c_EXTD5ST_exd5pist_SHIFT          (0U)
/*! exd5pist - extdst5_pipeline_status
 *  0b00..Pipeline with endpoint extdst5 is empty
 *  0b01..Pipeline with endpoint extdst5 is currently processing one operation
 *  0b10..Pipeline with endpoint extdst5 is currently processing one operation with a second one already kicked to be processed afterwards
 *  0b11..reserved
 */
#define extdst5c_EXTD5ST_exd5pist(x)             (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5ST_exd5pist_SHIFT)) & extdst5c_EXTD5ST_exd5pist_MASK)

#define extdst5c_EXTD5ST_exd5sb_MASK             (0x100U)
#define extdst5c_EXTD5ST_exd5sb_SHIFT            (8U)
/*! exd5sb - extdst5_sync_busy
 *  0b0..extdst5 synchronizer is idle
 *  0b1..extdst5 synchronizer is busy
 */
#define extdst5c_EXTD5ST_exd5sb(x)               (((uint32_t)(((uint32_t)(x)) << extdst5c_EXTD5ST_exd5sb_SHIFT)) & extdst5c_EXTD5ST_exd5sb_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group extdst5c_Register_Masks */


/*!
 * @}
 */ /* end of group extdst5c_Peripheral_Access_Layer */


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


#endif  /* PERI_EXTDST5C_H_ */

