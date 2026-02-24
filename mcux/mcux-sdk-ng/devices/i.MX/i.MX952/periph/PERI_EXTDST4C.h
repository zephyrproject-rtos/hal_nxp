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
**         CMSIS Peripheral Access Layer for extdst4c
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
 * @file PERI_extdst4c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for extdst4c
 *
 * CMSIS Peripheral Access Layer for extdst4c
 */

#if !defined(PERI_EXTDST4C_H_)
#define PERI_EXTDST4C_H_                         /**< Symbol preventing repeated inclusion */

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
   -- extdst4c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst4c_Peripheral_Access_Layer extdst4c Peripheral Access Layer
 * @{
 */

/** extdst4c - Register Layout Typedef */
typedef struct {
  __O  uint32_t EXTD4LU;                           /**< extdst4_LockUnlock, offset: 0x0 */
  __I  uint32_t EXTD4LS;                           /**< extdst4_LockStatus, offset: 0x4 */
  __IO uint32_t EXTD4S;                            /**< extdst4_Static, offset: 0x8 */
  __IO uint32_t EXTD4D;                            /**< extdst4_Dynamic, offset: 0xC */
  __IO uint32_t EXTD4R;                            /**< extdst4_Request, offset: 0x10 */
  __O  uint32_t EXTD4TR;                           /**< extdst4_Trigger, offset: 0x14 */
  __I  uint32_t EXTD4ST;                           /**< extdst4_Status, offset: 0x18 */
} extdst4c_Type;

/* ----------------------------------------------------------------------------
   -- extdst4c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup extdst4c_Register_Masks extdst4c Register Masks
 * @{
 */

/*! @name EXTD4LU - extdst4_LockUnlock */
/*! @{ */

#define extdst4c_EXTD4LU_exd4LUnl_MASK           (0xFFFFFFFFU)
#define extdst4c_EXTD4LU_exd4LUnl_SHIFT          (0U)
/*! exd4LUnl - extdst4_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define extdst4c_EXTD4LU_exd4LUnl(x)             (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4LU_exd4LUnl_SHIFT)) & extdst4c_EXTD4LU_exd4LUnl_MASK)
/*! @} */

/*! @name EXTD4LS - extdst4_LockStatus */
/*! @{ */

#define extdst4c_EXTD4LS_exd4LS_MASK             (0x1U)
#define extdst4c_EXTD4LS_exd4LS_SHIFT            (0U)
/*! exd4LS - extdst4_LockStatus */
#define extdst4c_EXTD4LS_exd4LS(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4LS_exd4LS_SHIFT)) & extdst4c_EXTD4LS_exd4LS_MASK)

#define extdst4c_EXTD4LS_exd4PS_MASK             (0x10U)
#define extdst4c_EXTD4LS_exd4PS_SHIFT            (4U)
/*! exd4PS - extdst4_PrivilegeStatus */
#define extdst4c_EXTD4LS_exd4PS(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4LS_exd4PS_SHIFT)) & extdst4c_EXTD4LS_exd4PS_MASK)

#define extdst4c_EXTD4LS_exd4FS_MASK             (0x100U)
#define extdst4c_EXTD4LS_exd4FS_SHIFT            (8U)
/*! exd4FS - extdst4_FreezeStatus */
#define extdst4c_EXTD4LS_exd4FS(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4LS_exd4FS_SHIFT)) & extdst4c_EXTD4LS_exd4FS_MASK)
/*! @} */

/*! @name EXTD4S - extdst4_Static */
/*! @{ */

#define extdst4c_EXTD4S_exd4ShdE_MASK            (0x1U)
#define extdst4c_EXTD4S_exd4ShdE_SHIFT           (0U)
/*! exd4ShdE - extdst4_ShdEn */
#define extdst4c_EXTD4S_exd4ShdE(x)              (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4S_exd4ShdE_SHIFT)) & extdst4c_EXTD4S_exd4ShdE_MASK)

#define extdst4c_EXTD4S_exd4podo_MASK            (0x10U)
#define extdst4c_EXTD4S_exd4podo_SHIFT           (4U)
/*! exd4podo - extdst4_powerdown */
#define extdst4c_EXTD4S_exd4podo(x)              (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4S_exd4podo_SHIFT)) & extdst4c_EXTD4S_exd4podo_MASK)

#define extdst4c_EXTD4S_exd4SM_MASK              (0x100U)
#define extdst4c_EXTD4S_exd4SM_SHIFT             (8U)
/*! exd4SM - extdst4_Sync_Mode
 *  0b0..Reconfig pipeline after explicit trigger
 *  0b1..Reconfig pipeline after every kick when idle
 */
#define extdst4c_EXTD4S_exd4SM(x)                (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4S_exd4SM_SHIFT)) & extdst4c_EXTD4S_exd4SM_MASK)

#define extdst4c_EXTD4S_exd4SWR_MASK             (0x800U)
#define extdst4c_EXTD4S_exd4SWR_SHIFT            (11U)
/*! exd4SWR - extdst4_SW_Reset
 *  0b0..Normal Operation
 *  0b1..Software Reset
 */
#define extdst4c_EXTD4S_exd4SWR(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4S_exd4SWR_SHIFT)) & extdst4c_EXTD4S_exd4SWR_MASK)

#define extdst4c_EXTD4S_exd4div_MASK             (0xFF0000U)
#define extdst4c_EXTD4S_exd4div_SHIFT            (16U)
/*! exd4div - extdst4_div */
#define extdst4c_EXTD4S_exd4div(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4S_exd4div_SHIFT)) & extdst4c_EXTD4S_exd4div_MASK)
/*! @} */

/*! @name EXTD4D - extdst4_Dynamic */
/*! @{ */

#define extdst4c_EXTD4D_exd4ssel_MASK            (0x3FU)
#define extdst4c_EXTD4D_exd4ssel_SHIFT           (0U)
/*! exd4ssel - extdst4_src_sel
 *  0b000000..Unit extdst4 input port src is disabled
 *  0b010100..Unit extdst4 input port src is connected to output of unit layerblend1
 *  0b010101..Unit extdst4 input port src is connected to output of unit layerblend2
 *  0b010110..Unit extdst4 input port src is connected to output of unit layerblend3
 *  0b010111..Unit extdst4 input port src is connected to output of unit layerblend4
 *  0b011000..Unit extdst4 input port src is connected to output of unit layerblend5
 */
#define extdst4c_EXTD4D_exd4ssel(x)              (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4D_exd4ssel_SHIFT)) & extdst4c_EXTD4D_exd4ssel_MASK)
/*! @} */

/*! @name EXTD4R - extdst4_Request */
/*! @{ */

#define extdst4c_EXTD4R_exd4sSLR_MASK            (0x1U)
#define extdst4c_EXTD4R_exd4sSLR_SHIFT           (0U)
/*! exd4sSLR - extdst4_sel_ShdLdReq */
#define extdst4c_EXTD4R_exd4sSLR(x)              (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4R_exd4sSLR_SHIFT)) & extdst4c_EXTD4R_exd4sSLR_MASK)

#define extdst4c_EXTD4R_exd4SLR_MASK             (0x7FFEU)
#define extdst4c_EXTD4R_exd4SLR_SHIFT            (1U)
/*! exd4SLR - extdst4_ShdLdReq */
#define extdst4c_EXTD4R_exd4SLR(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4R_exd4SLR_SHIFT)) & extdst4c_EXTD4R_exd4SLR_MASK)
/*! @} */

/*! @name EXTD4TR - extdst4_Trigger */
/*! @{ */

#define extdst4c_EXTD4TR_exd4ST_MASK             (0x1U)
#define extdst4c_EXTD4TR_exd4ST_SHIFT            (0U)
/*! exd4ST - extdst4_Sync_Trigger */
#define extdst4c_EXTD4TR_exd4ST(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4TR_exd4ST_SHIFT)) & extdst4c_EXTD4TR_exd4ST_MASK)

#define extdst4c_EXTD4TR_exd4tsec_MASK           (0x10U)
#define extdst4c_EXTD4TR_exd4tsec_SHIFT          (4U)
/*! exd4tsec - extdst4_trigger_sequence_complete */
#define extdst4c_EXTD4TR_exd4tsec(x)             (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4TR_exd4tsec_SHIFT)) & extdst4c_EXTD4TR_exd4tsec_MASK)
/*! @} */

/*! @name EXTD4ST - extdst4_Status */
/*! @{ */

#define extdst4c_EXTD4ST_exd4pist_MASK           (0x3U)
#define extdst4c_EXTD4ST_exd4pist_SHIFT          (0U)
/*! exd4pist - extdst4_pipeline_status
 *  0b00..Pipeline with endpoint extdst4 is empty
 *  0b01..Pipeline with endpoint extdst4 is currently processing one operation
 *  0b10..Pipeline with endpoint extdst4 is currently processing one operation with a second one already kicked to be processed afterwards
 *  0b11..reserved
 */
#define extdst4c_EXTD4ST_exd4pist(x)             (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4ST_exd4pist_SHIFT)) & extdst4c_EXTD4ST_exd4pist_MASK)

#define extdst4c_EXTD4ST_exd4sb_MASK             (0x100U)
#define extdst4c_EXTD4ST_exd4sb_SHIFT            (8U)
/*! exd4sb - extdst4_sync_busy
 *  0b0..extdst4 synchronizer is idle
 *  0b1..extdst4 synchronizer is busy
 */
#define extdst4c_EXTD4ST_exd4sb(x)               (((uint32_t)(((uint32_t)(x)) << extdst4c_EXTD4ST_exd4sb_SHIFT)) & extdst4c_EXTD4ST_exd4sb_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group extdst4c_Register_Masks */


/*!
 * @}
 */ /* end of group extdst4c_Peripheral_Access_Layer */


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


#endif  /* PERI_EXTDST4C_H_ */

