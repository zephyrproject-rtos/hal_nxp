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
**         CMSIS Peripheral Access Layer for extdst0c
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
 * @file PERI_extdst0c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for extdst0c
 *
 * CMSIS Peripheral Access Layer for extdst0c
 */

#if !defined(PERI_EXTDST0C_H_)
#define PERI_EXTDST0C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- extdst0c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst0c_Peripheral_Access_Layer extdst0c Peripheral Access Layer
 * @{
 */

/** extdst0c - Register Layout Typedef */
typedef struct {
  __O  uint32_t EXTD0LU;                           /**< extdst0_LockUnlock, offset: 0x0 */
  __I  uint32_t EXTD0LS;                           /**< extdst0_LockStatus, offset: 0x4 */
  __IO uint32_t EXTD0S;                            /**< extdst0_Static, offset: 0x8 */
  __IO uint32_t EXTD0D;                            /**< extdst0_Dynamic, offset: 0xC */
  __IO uint32_t EXTD0R;                            /**< extdst0_Request, offset: 0x10 */
  __O  uint32_t EXTD0TR;                           /**< extdst0_Trigger, offset: 0x14 */
  __I  uint32_t EXTD0ST;                           /**< extdst0_Status, offset: 0x18 */
} extdst0c_Type;

/* ----------------------------------------------------------------------------
   -- extdst0c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst0c_Register_Masks extdst0c Register Masks
 * @{
 */

/*! @name EXTD0LU - extdst0_LockUnlock */
/*! @{ */

#define extdst0c_EXTD0LU_exd0LUnl_MASK           (0xFFFFFFFFU)
#define extdst0c_EXTD0LU_exd0LUnl_SHIFT          (0U)
/*! exd0LUnl - extdst0_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define extdst0c_EXTD0LU_exd0LUnl(x)             (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0LU_exd0LUnl_SHIFT)) & extdst0c_EXTD0LU_exd0LUnl_MASK)
/*! @} */

/*! @name EXTD0LS - extdst0_LockStatus */
/*! @{ */

#define extdst0c_EXTD0LS_exd0LS_MASK             (0x1U)
#define extdst0c_EXTD0LS_exd0LS_SHIFT            (0U)
/*! exd0LS - extdst0_LockStatus */
#define extdst0c_EXTD0LS_exd0LS(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0LS_exd0LS_SHIFT)) & extdst0c_EXTD0LS_exd0LS_MASK)

#define extdst0c_EXTD0LS_exd0PS_MASK             (0x10U)
#define extdst0c_EXTD0LS_exd0PS_SHIFT            (4U)
/*! exd0PS - extdst0_PrivilegeStatus */
#define extdst0c_EXTD0LS_exd0PS(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0LS_exd0PS_SHIFT)) & extdst0c_EXTD0LS_exd0PS_MASK)

#define extdst0c_EXTD0LS_exd0FS_MASK             (0x100U)
#define extdst0c_EXTD0LS_exd0FS_SHIFT            (8U)
/*! exd0FS - extdst0_FreezeStatus */
#define extdst0c_EXTD0LS_exd0FS(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0LS_exd0FS_SHIFT)) & extdst0c_EXTD0LS_exd0FS_MASK)
/*! @} */

/*! @name EXTD0S - extdst0_Static */
/*! @{ */

#define extdst0c_EXTD0S_exd0ShdE_MASK            (0x1U)
#define extdst0c_EXTD0S_exd0ShdE_SHIFT           (0U)
/*! exd0ShdE - extdst0_ShdEn */
#define extdst0c_EXTD0S_exd0ShdE(x)              (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0S_exd0ShdE_SHIFT)) & extdst0c_EXTD0S_exd0ShdE_MASK)

#define extdst0c_EXTD0S_exd0podo_MASK            (0x10U)
#define extdst0c_EXTD0S_exd0podo_SHIFT           (4U)
/*! exd0podo - extdst0_powerdown */
#define extdst0c_EXTD0S_exd0podo(x)              (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0S_exd0podo_SHIFT)) & extdst0c_EXTD0S_exd0podo_MASK)

#define extdst0c_EXTD0S_exd0SM_MASK              (0x100U)
#define extdst0c_EXTD0S_exd0SM_SHIFT             (8U)
/*! exd0SM - extdst0_Sync_Mode
 *  0b0..Reconfig pipeline after explicit trigger
 *  0b1..Reconfig pipeline after every kick when idle
 */
#define extdst0c_EXTD0S_exd0SM(x)                (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0S_exd0SM_SHIFT)) & extdst0c_EXTD0S_exd0SM_MASK)

#define extdst0c_EXTD0S_exd0SWR_MASK             (0x800U)
#define extdst0c_EXTD0S_exd0SWR_SHIFT            (11U)
/*! exd0SWR - extdst0_SW_Reset
 *  0b0..Normal Operation
 *  0b1..Software Reset
 */
#define extdst0c_EXTD0S_exd0SWR(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0S_exd0SWR_SHIFT)) & extdst0c_EXTD0S_exd0SWR_MASK)

#define extdst0c_EXTD0S_exd0div_MASK             (0xFF0000U)
#define extdst0c_EXTD0S_exd0div_SHIFT            (16U)
/*! exd0div - extdst0_div */
#define extdst0c_EXTD0S_exd0div(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0S_exd0div_SHIFT)) & extdst0c_EXTD0S_exd0div_MASK)
/*! @} */

/*! @name EXTD0D - extdst0_Dynamic */
/*! @{ */

#define extdst0c_EXTD0D_exd0ssel_MASK            (0x3FU)
#define extdst0c_EXTD0D_exd0ssel_SHIFT           (0U)
/*! exd0ssel - extdst0_src_sel
 *  0b000000..Unit extdst0 input port src is disabled
 *  0b010100..Unit extdst0 input port src is connected to output of unit layerblend1
 *  0b010101..Unit extdst0 input port src is connected to output of unit layerblend2
 *  0b010110..Unit extdst0 input port src is connected to output of unit layerblend3
 *  0b010111..Unit extdst0 input port src is connected to output of unit layerblend4
 *  0b011000..Unit extdst0 input port src is connected to output of unit layerblend5
 */
#define extdst0c_EXTD0D_exd0ssel(x)              (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0D_exd0ssel_SHIFT)) & extdst0c_EXTD0D_exd0ssel_MASK)
/*! @} */

/*! @name EXTD0R - extdst0_Request */
/*! @{ */

#define extdst0c_EXTD0R_exd0sSLR_MASK            (0x1U)
#define extdst0c_EXTD0R_exd0sSLR_SHIFT           (0U)
/*! exd0sSLR - extdst0_sel_ShdLdReq */
#define extdst0c_EXTD0R_exd0sSLR(x)              (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0R_exd0sSLR_SHIFT)) & extdst0c_EXTD0R_exd0sSLR_MASK)

#define extdst0c_EXTD0R_exd0SLd_MASK             (0x7FFEU)
#define extdst0c_EXTD0R_exd0SLd_SHIFT            (1U)
/*! exd0SLd - extdst0_ShdLdReq */
#define extdst0c_EXTD0R_exd0SLd(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0R_exd0SLd_SHIFT)) & extdst0c_EXTD0R_exd0SLd_MASK)
/*! @} */

/*! @name EXTD0TR - extdst0_Trigger */
/*! @{ */

#define extdst0c_EXTD0TR_exd0ST_MASK             (0x1U)
#define extdst0c_EXTD0TR_exd0ST_SHIFT            (0U)
/*! exd0ST - extdst0_Sync_Trigger */
#define extdst0c_EXTD0TR_exd0ST(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0TR_exd0ST_SHIFT)) & extdst0c_EXTD0TR_exd0ST_MASK)

#define extdst0c_EXTD0TR_exd0tsc_MASK            (0x10U)
#define extdst0c_EXTD0TR_exd0tsc_SHIFT           (4U)
/*! exd0tsc - extdst0_trigger_sequence_complete */
#define extdst0c_EXTD0TR_exd0tsc(x)              (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0TR_exd0tsc_SHIFT)) & extdst0c_EXTD0TR_exd0tsc_MASK)
/*! @} */

/*! @name EXTD0ST - extdst0_Status */
/*! @{ */

#define extdst0c_EXTD0ST_exd0pist_MASK           (0x3U)
#define extdst0c_EXTD0ST_exd0pist_SHIFT          (0U)
/*! exd0pist - extdst0_pipeline_status
 *  0b00..Pipeline with endpoint extdst0 is empty
 *  0b01..Pipeline with endpoint extdst0 is currently processing one operation
 *  0b10..Pipeline with endpoint extdst0 is currently processing one operation with a second one already kicked to be processed afterwards
 *  0b11..reserved
 */
#define extdst0c_EXTD0ST_exd0pist(x)             (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0ST_exd0pist_SHIFT)) & extdst0c_EXTD0ST_exd0pist_MASK)

#define extdst0c_EXTD0ST_exd0sb_MASK             (0x100U)
#define extdst0c_EXTD0ST_exd0sb_SHIFT            (8U)
/*! exd0sb - extdst0_sync_busy
 *  0b0..extdst0 synchronizer is idle
 *  0b1..extdst0 synchronizer is busy
 */
#define extdst0c_EXTD0ST_exd0sb(x)               (((uint32_t)(((uint32_t)(x)) << extdst0c_EXTD0ST_exd0sb_SHIFT)) & extdst0c_EXTD0ST_exd0sb_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group extdst0c_Register_Masks */


/*!
 * @}
 */ /* end of group extdst0c_Peripheral_Access_Layer */


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


#endif  /* PERI_EXTDST0C_H_ */

