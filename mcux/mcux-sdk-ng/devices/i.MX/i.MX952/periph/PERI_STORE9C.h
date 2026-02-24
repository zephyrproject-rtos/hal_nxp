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
**         CMSIS Peripheral Access Layer for store9c
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
 * @file PERI_store9c.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for store9c
 *
 * CMSIS Peripheral Access Layer for store9c
 */

#if !defined(PERI_STORE9C_H_)
#define PERI_STORE9C_H_                          /**< Symbol preventing repeated inclusion */

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
   -- store9c Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup store9c_Peripheral_Access_Layer store9c Peripheral Access Layer
 * @{
 */

/** store9c - Register Layout Typedef */
typedef struct {
  __O  uint32_t STOR9LU;                           /**< store9_LockUnlock, offset: 0x0 */
  __I  uint32_t STOR9LS;                           /**< store9_LockStatus, offset: 0x4 */
  __IO uint32_t STOR9STC;                          /**< store9_Static, offset: 0x8 */
  __IO uint32_t STOR9D;                            /**< store9_Dynamic, offset: 0xC */
  __IO uint32_t STOR9R;                            /**< store9_Request, offset: 0x10 */
  __O  uint32_t STOR9T;                            /**< store9_Trigger, offset: 0x14 */
  __I  uint32_t STOR9STS;                          /**< store9_Status, offset: 0x18 */
} store9c_Type;

/* ----------------------------------------------------------------------------
   -- store9c Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup store9c_Register_Masks store9c Register Masks
 * @{
 */

/*! @name STOR9LU - store9_LockUnlock */
/*! @{ */

#define store9c_STOR9LU_sto9LUnl_MASK            (0xFFFFFFFFU)
#define store9c_STOR9LU_sto9LUnl_SHIFT           (0U)
/*! sto9LUnl - store9_LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define store9c_STOR9LU_sto9LUnl(x)              (((uint32_t)(((uint32_t)(x)) << store9c_STOR9LU_sto9LUnl_SHIFT)) & store9c_STOR9LU_sto9LUnl_MASK)
/*! @} */

/*! @name STOR9LS - store9_LockStatus */
/*! @{ */

#define store9c_STOR9LS_sto9LSt_MASK             (0x1U)
#define store9c_STOR9LS_sto9LSt_SHIFT            (0U)
/*! sto9LSt - store9_LockStatus */
#define store9c_STOR9LS_sto9LSt(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9LS_sto9LSt_SHIFT)) & store9c_STOR9LS_sto9LSt_MASK)

#define store9c_STOR9LS_sto9PS_MASK              (0x10U)
#define store9c_STOR9LS_sto9PS_SHIFT             (4U)
/*! sto9PS - store9_PrivilegeStatus */
#define store9c_STOR9LS_sto9PS(x)                (((uint32_t)(((uint32_t)(x)) << store9c_STOR9LS_sto9PS_SHIFT)) & store9c_STOR9LS_sto9PS_MASK)

#define store9c_STOR9LS_sto9FS_MASK              (0x100U)
#define store9c_STOR9LS_sto9FS_SHIFT             (8U)
/*! sto9FS - store9_FreezeStatus */
#define store9c_STOR9LS_sto9FS(x)                (((uint32_t)(((uint32_t)(x)) << store9c_STOR9LS_sto9FS_SHIFT)) & store9c_STOR9LS_sto9FS_MASK)
/*! @} */

/*! @name STOR9STC - store9_Static */
/*! @{ */

#define store9c_STOR9STC_sto9ShEn_MASK           (0x1U)
#define store9c_STOR9STC_sto9ShEn_SHIFT          (0U)
/*! sto9ShEn - store9_ShdEn */
#define store9c_STOR9STC_sto9ShEn(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STC_sto9ShEn_SHIFT)) & store9c_STOR9STC_sto9ShEn_MASK)

#define store9c_STOR9STC_sto9podo_MASK           (0x10U)
#define store9c_STOR9STC_sto9podo_SHIFT          (4U)
/*! sto9podo - store9_powerdown */
#define store9c_STOR9STC_sto9podo(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STC_sto9podo_SHIFT)) & store9c_STOR9STC_sto9podo_MASK)

#define store9c_STOR9STC_sto9SyMo_MASK           (0x100U)
#define store9c_STOR9STC_sto9SyMo_SHIFT          (8U)
/*! sto9SyMo - store9_Sync_Mode
 *  0b0..Reconfig pipeline after explicit trigger
 *  0b1..Reconfig pipeline after every kick when idle
 */
#define store9c_STOR9STC_sto9SyMo(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STC_sto9SyMo_SHIFT)) & store9c_STOR9STC_sto9SyMo_MASK)

#define store9c_STOR9STC_sto9SWR_MASK            (0x800U)
#define store9c_STOR9STC_sto9SWR_SHIFT           (11U)
/*! sto9SWR - store9_SW_Reset
 *  0b0..Normal Operation
 *  0b1..Software Reset
 */
#define store9c_STOR9STC_sto9SWR(x)              (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STC_sto9SWR_SHIFT)) & store9c_STOR9STC_sto9SWR_MASK)

#define store9c_STOR9STC_store9dv_MASK           (0xFF0000U)
#define store9c_STOR9STC_store9dv_SHIFT          (16U)
/*! store9dv - store9_div */
#define store9c_STOR9STC_store9dv(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STC_store9dv_SHIFT)) & store9c_STOR9STC_store9dv_MASK)
/*! @} */

/*! @name STOR9D - store9_Dynamic */
/*! @{ */

#define store9c_STOR9D_sto9srcs_MASK             (0x3FU)
#define store9c_STOR9D_sto9srcs_SHIFT            (0U)
/*! sto9srcs - store9_src_sel
 *  0b000000..Unit store9 input port src is disabled
 *  0b000100..Unit store9 input port src is connected to output of unit blitblend9
 *  0b000101..Unit store9 input port src is connected to output of unit fetchrot9
 *  0b000110..Unit store9 input port src is connected to output of unit fetchdecode9
 *  0b001000..Unit store9 input port src is connected to output of unit hscaler9
 *  0b001001..Unit store9 input port src is connected to output of unit vscaler9
 *  0b001010..Unit store9 input port src is connected to output of unit filter9
 */
#define store9c_STOR9D_sto9srcs(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9D_sto9srcs_SHIFT)) & store9c_STOR9D_sto9srcs_MASK)
/*! @} */

/*! @name STOR9R - store9_Request */
/*! @{ */

#define store9c_STOR9R_sto9sSLR_MASK             (0x1U)
#define store9c_STOR9R_sto9sSLR_SHIFT            (0U)
/*! sto9sSLR - store9_sel_ShdLdReq */
#define store9c_STOR9R_sto9sSLR(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9R_sto9sSLR_SHIFT)) & store9c_STOR9R_sto9sSLR_MASK)

#define store9c_STOR9R_sto9ShLR_MASK             (0x7FFEU)
#define store9c_STOR9R_sto9ShLR_SHIFT            (1U)
/*! sto9ShLR - store9_ShdLdReq */
#define store9c_STOR9R_sto9ShLR(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9R_sto9ShLR_SHIFT)) & store9c_STOR9R_sto9ShLR_MASK)
/*! @} */

/*! @name STOR9T - store9_Trigger */
/*! @{ */

#define store9c_STOR9T_sto9SyTr_MASK             (0x1U)
#define store9c_STOR9T_sto9SyTr_SHIFT            (0U)
/*! sto9SyTr - store9_Sync_Trigger */
#define store9c_STOR9T_sto9SyTr(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9T_sto9SyTr_SHIFT)) & store9c_STOR9T_sto9SyTr_MASK)

#define store9c_STOR9T_sto9trsc_MASK             (0x10U)
#define store9c_STOR9T_sto9trsc_SHIFT            (4U)
/*! sto9trsc - store9_trigger_sequence_complete */
#define store9c_STOR9T_sto9trsc(x)               (((uint32_t)(((uint32_t)(x)) << store9c_STOR9T_sto9trsc_SHIFT)) & store9c_STOR9T_sto9trsc_MASK)
/*! @} */

/*! @name STOR9STS - store9_Status */
/*! @{ */

#define store9c_STOR9STS_sto9pist_MASK           (0x3U)
#define store9c_STOR9STS_sto9pist_SHIFT          (0U)
/*! sto9pist - store9_pipeline_status
 *  0b00..Pipeline with endpoint store9 is empty
 *  0b01..Pipeline with endpoint store9 is currently processing one operation
 *  0b10..Pipeline with endpoint store9 is currently processing one operation with a second one already kicked to be processed afterwards
 *  0b11..reserved
 */
#define store9c_STOR9STS_sto9pist(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STS_sto9pist_SHIFT)) & store9c_STOR9STS_sto9pist_MASK)

#define store9c_STOR9STS_sto9sybu_MASK           (0x100U)
#define store9c_STOR9STS_sto9sybu_SHIFT          (8U)
/*! sto9sybu - store9_sync_busy
 *  0b0..store9 synchronizer is idle
 *  0b1..store9 synchronizer is busy
 */
#define store9c_STOR9STS_sto9sybu(x)             (((uint32_t)(((uint32_t)(x)) << store9c_STOR9STS_sto9sybu_SHIFT)) & store9c_STOR9STS_sto9sybu_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group store9c_Register_Masks */


/*!
 * @}
 */ /* end of group store9c_Peripheral_Access_Layer */


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


#endif  /* PERI_STORE9C_H_ */

