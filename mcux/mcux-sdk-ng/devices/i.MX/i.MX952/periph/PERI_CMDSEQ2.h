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
**         CMSIS Peripheral Access Layer for cmdseq2
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
 * @file PERI_cmdseq2.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for cmdseq2
 *
 * CMSIS Peripheral Access Layer for cmdseq2
 */

#if !defined(PERI_CMDSEQ2_H_)
#define PERI_CMDSEQ2_H_                          /**< Symbol preventing repeated inclusion */

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
   -- cmdseq2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseq2_Peripheral_Access_Layer cmdseq2 Peripheral Access Layer
 * @{
 */

/** cmdseq2 - Register Layout Typedef */
typedef struct {
  __O  uint32_t LU;                                /**< LockUnlock, offset: 0x0 */
  __I  uint32_t LOCKS;                             /**< LockStatus, offset: 0x4 */
  __IO uint32_t BUFADR;                            /**< BufferAddress, offset: 0x8 */
  __IO uint32_t BUFAMSB;                           /**< BufferAddressMSB, offset: 0xC */
  __IO uint32_t BUFSIZE;                           /**< BufferSize, offset: 0x10 */
  __IO uint32_t WATERCON;                          /**< WatermarkControl, offset: 0x14 */
  __O  uint32_t CONTR;                             /**< Control, offset: 0x18 */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x1C */
  __IO uint32_t PREFWIS;                           /**< PrefetchWindowStart, offset: 0x20 */
  __IO uint32_t PREFWISM;                          /**< PrefetchWindowStartMSB, offset: 0x24 */
  __IO uint32_t PREFWIE;                           /**< PrefetchWindowEnd, offset: 0x28 */
  __IO uint32_t PREFWIEM;                          /**< PrefetchWindowEndMSB, offset: 0x2C */
} cmdseq2_Type;

/* ----------------------------------------------------------------------------
   -- cmdseq2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup cmdseq2_Register_Masks cmdseq2 Register Masks
 * @{
 */

/*! @name LU - LockUnlock */
/*! @{ */

#define cmdseq2_LU_LkUn_MASK                     (0xFFFFFFFFU)
#define cmdseq2_LU_LkUn_SHIFT                    (0U)
/*! LkUn - LockUnlock
 *  0b01010110010100011111011101100011..Decrements the unlock counter. When the counter value is null, lock protection is active. Reset counter value is 1.
 *  0b01101001000111011011100100110110..Increments the unlock counter. Max allowed value is 15.
 *  0b10101110111010010101110011011100..Enables privilege protection. Disabled after reset.
 *  0b10110101111000100100011001101110..Disables privilege protection.
 *  0b11111011111010001011000111100110..Freezes current protection status. Writing keys to this register has no more effect until reset.
 */
#define cmdseq2_LU_LkUn(x)                       (((uint32_t)(((uint32_t)(x)) << cmdseq2_LU_LkUn_SHIFT)) & cmdseq2_LU_LkUn_MASK)
/*! @} */

/*! @name LOCKS - LockStatus */
/*! @{ */

#define cmdseq2_LOCKS_LkSus_MASK                 (0x1U)
#define cmdseq2_LOCKS_LkSus_SHIFT                (0U)
/*! LkSus - LockStatus */
#define cmdseq2_LOCKS_LkSus(x)                   (((uint32_t)(((uint32_t)(x)) << cmdseq2_LOCKS_LkSus_SHIFT)) & cmdseq2_LOCKS_LkSus_MASK)

#define cmdseq2_LOCKS_PriSt_MASK                 (0x10U)
#define cmdseq2_LOCKS_PriSt_SHIFT                (4U)
/*! PriSt - PrivilegeStatus */
#define cmdseq2_LOCKS_PriSt(x)                   (((uint32_t)(((uint32_t)(x)) << cmdseq2_LOCKS_PriSt_SHIFT)) & cmdseq2_LOCKS_PriSt_MASK)

#define cmdseq2_LOCKS_FreezeS_MASK               (0x100U)
#define cmdseq2_LOCKS_FreezeS_SHIFT              (8U)
/*! FreezeS - FreezeStatus */
#define cmdseq2_LOCKS_FreezeS(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseq2_LOCKS_FreezeS_SHIFT)) & cmdseq2_LOCKS_FreezeS_MASK)
/*! @} */

/*! @name BUFADR - BufferAddress */
/*! @{ */

#define cmdseq2_BUFADR_Local_MASK                (0x1U)
#define cmdseq2_BUFADR_Local_SHIFT               (0U)
/*! Local - Local */
#define cmdseq2_BUFADR_Local(x)                  (((uint32_t)(((uint32_t)(x)) << cmdseq2_BUFADR_Local_SHIFT)) & cmdseq2_BUFADR_Local_MASK)

#define cmdseq2_BUFADR_Addr_MASK                 (0xFFFFFFE0U)
#define cmdseq2_BUFADR_Addr_SHIFT                (5U)
/*! Addr - Addr */
#define cmdseq2_BUFADR_Addr(x)                   (((uint32_t)(((uint32_t)(x)) << cmdseq2_BUFADR_Addr_SHIFT)) & cmdseq2_BUFADR_Addr_MASK)
/*! @} */

/*! @name BUFAMSB - BufferAddressMSB */
/*! @{ */

#define cmdseq2_BUFAMSB_AddrMSB_MASK             (0xFFU)
#define cmdseq2_BUFAMSB_AddrMSB_SHIFT            (0U)
/*! AddrMSB - AddrMSB */
#define cmdseq2_BUFAMSB_AddrMSB(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_BUFAMSB_AddrMSB_SHIFT)) & cmdseq2_BUFAMSB_AddrMSB_MASK)
/*! @} */

/*! @name BUFSIZE - BufferSize */
/*! @{ */

#define cmdseq2_BUFSIZE_Size_MASK                (0xFFF8U)
#define cmdseq2_BUFSIZE_Size_SHIFT               (3U)
/*! Size - Size */
#define cmdseq2_BUFSIZE_Size(x)                  (((uint32_t)(((uint32_t)(x)) << cmdseq2_BUFSIZE_Size_SHIFT)) & cmdseq2_BUFSIZE_Size_MASK)
/*! @} */

/*! @name WATERCON - WatermarkControl */
/*! @{ */

#define cmdseq2_WATERCON_LowWM_MASK              (0xFFFFU)
#define cmdseq2_WATERCON_LowWM_SHIFT             (0U)
/*! LowWM - LowWM */
#define cmdseq2_WATERCON_LowWM(x)                (((uint32_t)(((uint32_t)(x)) << cmdseq2_WATERCON_LowWM_SHIFT)) & cmdseq2_WATERCON_LowWM_MASK)

#define cmdseq2_WATERCON_HighWM_MASK             (0xFFFF0000U)
#define cmdseq2_WATERCON_HighWM_SHIFT            (16U)
/*! HighWM - HighWM */
#define cmdseq2_WATERCON_HighWM(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_WATERCON_HighWM_SHIFT)) & cmdseq2_WATERCON_HighWM_MASK)
/*! @} */

/*! @name CONTR - Control */
/*! @{ */

#define cmdseq2_CONTR_ClrAxiw_MASK               (0x1U)
#define cmdseq2_CONTR_ClrAxiw_SHIFT              (0U)
/*! ClrAxiw - ClrAxiw */
#define cmdseq2_CONTR_ClrAxiw(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseq2_CONTR_ClrAxiw_SHIFT)) & cmdseq2_CONTR_ClrAxiw_MASK)

#define cmdseq2_CONTR_ClrRbuf_MASK               (0x4U)
#define cmdseq2_CONTR_ClrRbuf_SHIFT              (2U)
/*! ClrRbuf - ClrRbuf */
#define cmdseq2_CONTR_ClrRbuf(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseq2_CONTR_ClrRbuf_SHIFT)) & cmdseq2_CONTR_ClrRbuf_MASK)

#define cmdseq2_CONTR_ClrCmdB_MASK               (0x8U)
#define cmdseq2_CONTR_ClrCmdB_SHIFT              (3U)
/*! ClrCmdB - ClrCmdBuf */
#define cmdseq2_CONTR_ClrCmdB(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseq2_CONTR_ClrCmdB_SHIFT)) & cmdseq2_CONTR_ClrCmdB_MASK)

#define cmdseq2_CONTR_Clear_MASK                 (0x10U)
#define cmdseq2_CONTR_Clear_SHIFT                (4U)
/*! Clear - Clear */
#define cmdseq2_CONTR_Clear(x)                   (((uint32_t)(((uint32_t)(x)) << cmdseq2_CONTR_Clear_SHIFT)) & cmdseq2_CONTR_Clear_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define cmdseq2_STATUS_FIFOSpac_MASK             (0x1FFFFU)
#define cmdseq2_STATUS_FIFOSpac_SHIFT            (0U)
/*! FIFOSpac - FIFOSpace */
#define cmdseq2_STATUS_FIFOSpac(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_FIFOSpac_SHIFT)) & cmdseq2_STATUS_FIFOSpac_MASK)

#define cmdseq2_STATUS_FIFOEmpt_MASK             (0x1000000U)
#define cmdseq2_STATUS_FIFOEmpt_SHIFT            (24U)
/*! FIFOEmpt - FIFOEmpty */
#define cmdseq2_STATUS_FIFOEmpt(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_FIFOEmpt_SHIFT)) & cmdseq2_STATUS_FIFOEmpt_MASK)

#define cmdseq2_STATUS_FIFOFull_MASK             (0x2000000U)
#define cmdseq2_STATUS_FIFOFull_SHIFT            (25U)
/*! FIFOFull - FIFOFull */
#define cmdseq2_STATUS_FIFOFull(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_FIFOFull_SHIFT)) & cmdseq2_STATUS_FIFOFull_MASK)

#define cmdseq2_STATUS_FIFOWMSt_MASK             (0x4000000U)
#define cmdseq2_STATUS_FIFOWMSt_SHIFT            (26U)
/*! FIFOWMSt - FIFOWMState */
#define cmdseq2_STATUS_FIFOWMSt(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_FIFOWMSt_SHIFT)) & cmdseq2_STATUS_FIFOWMSt_MASK)

#define cmdseq2_STATUS_Watchdog_MASK             (0x8000000U)
#define cmdseq2_STATUS_Watchdog_SHIFT            (27U)
/*! Watchdog - Watchdog */
#define cmdseq2_STATUS_Watchdog(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_Watchdog_SHIFT)) & cmdseq2_STATUS_Watchdog_MASK)

#define cmdseq2_STATUS_ReadBusy_MASK             (0x10000000U)
#define cmdseq2_STATUS_ReadBusy_SHIFT            (28U)
/*! ReadBusy - ReadBusy */
#define cmdseq2_STATUS_ReadBusy(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_ReadBusy_SHIFT)) & cmdseq2_STATUS_ReadBusy_MASK)

#define cmdseq2_STATUS_WrtBusy_MASK              (0x20000000U)
#define cmdseq2_STATUS_WrtBusy_SHIFT             (29U)
/*! WrtBusy - WriteBusy */
#define cmdseq2_STATUS_WrtBusy(x)                (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_WrtBusy_SHIFT)) & cmdseq2_STATUS_WrtBusy_MASK)

#define cmdseq2_STATUS_Idle_MASK                 (0x40000000U)
#define cmdseq2_STATUS_Idle_SHIFT                (30U)
/*! Idle - Idle */
#define cmdseq2_STATUS_Idle(x)                   (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_Idle_SHIFT)) & cmdseq2_STATUS_Idle_MASK)

#define cmdseq2_STATUS_ErrHalt_MASK              (0x80000000U)
#define cmdseq2_STATUS_ErrHalt_SHIFT             (31U)
/*! ErrHalt - ErrorHalt */
#define cmdseq2_STATUS_ErrHalt(x)                (((uint32_t)(((uint32_t)(x)) << cmdseq2_STATUS_ErrHalt_SHIFT)) & cmdseq2_STATUS_ErrHalt_MASK)
/*! @} */

/*! @name PREFWIS - PrefetchWindowStart */
/*! @{ */

#define cmdseq2_PREFWIS_PWStart_MASK             (0xFFFFFFFCU)
#define cmdseq2_PREFWIS_PWStart_SHIFT            (2U)
/*! PWStart - PWStart */
#define cmdseq2_PREFWIS_PWStart(x)               (((uint32_t)(((uint32_t)(x)) << cmdseq2_PREFWIS_PWStart_SHIFT)) & cmdseq2_PREFWIS_PWStart_MASK)
/*! @} */

/*! @name PREFWISM - PrefetchWindowStartMSB */
/*! @{ */

#define cmdseq2_PREFWISM_PWStaMSB_MASK           (0xFFU)
#define cmdseq2_PREFWISM_PWStaMSB_SHIFT          (0U)
/*! PWStaMSB - PWStartMSB */
#define cmdseq2_PREFWISM_PWStaMSB(x)             (((uint32_t)(((uint32_t)(x)) << cmdseq2_PREFWISM_PWStaMSB_SHIFT)) & cmdseq2_PREFWISM_PWStaMSB_MASK)
/*! @} */

/*! @name PREFWIE - PrefetchWindowEnd */
/*! @{ */

#define cmdseq2_PREFWIE_PWEnd_MASK               (0xFFFFFFFCU)
#define cmdseq2_PREFWIE_PWEnd_SHIFT              (2U)
/*! PWEnd - PWEnd */
#define cmdseq2_PREFWIE_PWEnd(x)                 (((uint32_t)(((uint32_t)(x)) << cmdseq2_PREFWIE_PWEnd_SHIFT)) & cmdseq2_PREFWIE_PWEnd_MASK)
/*! @} */

/*! @name PREFWIEM - PrefetchWindowEndMSB */
/*! @{ */

#define cmdseq2_PREFWIEM_PWEndMSB_MASK           (0xFFU)
#define cmdseq2_PREFWIEM_PWEndMSB_SHIFT          (0U)
/*! PWEndMSB - PWEndMSB */
#define cmdseq2_PREFWIEM_PWEndMSB(x)             (((uint32_t)(((uint32_t)(x)) << cmdseq2_PREFWIEM_PWEndMSB_SHIFT)) & cmdseq2_PREFWIEM_PWEndMSB_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group cmdseq2_Register_Masks */


/*!
 * @}
 */ /* end of group cmdseq2_Peripheral_Access_Layer */


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


#endif  /* PERI_CMDSEQ2_H_ */

