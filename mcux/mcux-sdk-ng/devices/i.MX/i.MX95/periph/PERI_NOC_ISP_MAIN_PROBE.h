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
**         CMSIS Peripheral Access Layer for NOC_ISP_MAIN_PROBE
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
 * @file NOC_ISP_MAIN_PROBE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_ISP_MAIN_PROBE
 *
 * CMSIS Peripheral Access Layer for NOC_ISP_MAIN_PROBE
 */

#if !defined(NOC_ISP_MAIN_PROBE_H_)
#define NOC_ISP_MAIN_PROBE_H_                    /**< Symbol preventing repeated inclusion */

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
   -- NOC_ISP_MAIN_PROBE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_ISP_MAIN_PROBE_Peripheral_Access_Layer NOC_ISP_MAIN_PROBE Peripheral Access Layer
 * @{
 */

/** NOC_ISP_MAIN_PROBE - Size of Registers Arrays */
#define NOC_ISP_MAIN_PROBE_COUNTERS_COUNT         10u

/** NOC_ISP_MAIN_PROBE - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID_COREID;                         /**< Core ID, offset: 0x0 */
  __I  uint32_t ID_REVISIONID;                     /**< Revision ID, offset: 0x4 */
  __IO uint32_t MAINCTL;                           /**< Main Control, offset: 0x8 */
  __IO uint32_t CFGCTL;                            /**< Configuration Control, offset: 0xC */
       uint8_t RESERVED_0[20];
  __IO uint32_t STATPERIOD;                        /**< Statistics Period, offset: 0x24 */
  __O  uint32_t STATGO;                            /**< StatGo, offset: 0x28 */
       uint8_t RESERVED_1[472];
  struct {                                         /* offset: 0x204, array step: 0x10 */
    __IO uint32_t SRC;                               /**< Counters n Source, array offset: 0x204, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __I  uint32_t VAL;                               /**< Counters n Value, array offset: 0x20C, array step: 0x10 */
         uint8_t RESERVED_1[4];
  } COUNTERS[NOC_ISP_MAIN_PROBE_COUNTERS_COUNT];
} NOC_ISP_MAIN_PROBE_Type;

/* ----------------------------------------------------------------------------
   -- NOC_ISP_MAIN_PROBE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_ISP_MAIN_PROBE_Register_Masks NOC_ISP_MAIN_PROBE Register Masks
 * @{
 */

/*! @name ID_COREID - Core ID */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_ID_COREID_CORETYPEID_MASK (0xFFU)
#define NOC_ISP_MAIN_PROBE_ID_COREID_CORETYPEID_SHIFT (0U)
#define NOC_ISP_MAIN_PROBE_ID_COREID_CORETYPEID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_ID_COREID_CORETYPEID_SHIFT)) & NOC_ISP_MAIN_PROBE_ID_COREID_CORETYPEID_MASK)

#define NOC_ISP_MAIN_PROBE_ID_COREID_CORECHECKSUM_MASK (0xFFFFFF00U)
#define NOC_ISP_MAIN_PROBE_ID_COREID_CORECHECKSUM_SHIFT (8U)
#define NOC_ISP_MAIN_PROBE_ID_COREID_CORECHECKSUM(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_ID_COREID_CORECHECKSUM_SHIFT)) & NOC_ISP_MAIN_PROBE_ID_COREID_CORECHECKSUM_MASK)
/*! @} */

/*! @name ID_REVISIONID - Revision ID */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_USERID_MASK (0xFFU)
#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_USERID_SHIFT (0U)
#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_USERID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_ID_REVISIONID_USERID_SHIFT)) & NOC_ISP_MAIN_PROBE_ID_REVISIONID_USERID_MASK)

#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_NOCID_MASK (0xFFFFFF00U)
#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_NOCID_SHIFT (8U)
#define NOC_ISP_MAIN_PROBE_ID_REVISIONID_NOCID(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_ID_REVISIONID_NOCID_SHIFT)) & NOC_ISP_MAIN_PROBE_ID_REVISIONID_NOCID_MASK)
/*! @} */

/*! @name MAINCTL - Main Control */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_MAINCTL_ERREN_MASK    (0x1U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_ERREN_SHIFT   (0U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_ERREN(x)      (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_ERREN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_ERREN_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_TRACEEN_MASK  (0x2U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_TRACEEN_SHIFT (1U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_TRACEEN(x)    (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_TRACEEN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_TRACEEN_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_PAYLOADEN_MASK (0x4U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_PAYLOADEN_SHIFT (2U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_PAYLOADEN(x)  (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_PAYLOADEN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_PAYLOADEN_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_STATEN_MASK   (0x8U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_STATEN_SHIFT  (3U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_STATEN(x)     (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_STATEN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_STATEN_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_ALARMEN_MASK  (0x10U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_ALARMEN_SHIFT (4U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_ALARMEN(x)    (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_ALARMEN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_ALARMEN_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_STATCONDDUMP_MASK (0x20U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_STATCONDDUMP_SHIFT (5U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_STATCONDDUMP(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_STATCONDDUMP_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_STATCONDDUMP_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_MASK (0x40U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_SHIFT (6U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_INTRUSIVEMODE(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_MASK)

#define NOC_ISP_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_MASK (0x80U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_SHIFT (7U)
#define NOC_ISP_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_SHIFT)) & NOC_ISP_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_MASK)
/*! @} */

/*! @name CFGCTL - Configuration Control */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_CFGCTL_GLOBALEN_MASK  (0x1U)
#define NOC_ISP_MAIN_PROBE_CFGCTL_GLOBALEN_SHIFT (0U)
#define NOC_ISP_MAIN_PROBE_CFGCTL_GLOBALEN(x)    (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_CFGCTL_GLOBALEN_SHIFT)) & NOC_ISP_MAIN_PROBE_CFGCTL_GLOBALEN_MASK)

#define NOC_ISP_MAIN_PROBE_CFGCTL_ACTIVE_MASK    (0x2U)
#define NOC_ISP_MAIN_PROBE_CFGCTL_ACTIVE_SHIFT   (1U)
#define NOC_ISP_MAIN_PROBE_CFGCTL_ACTIVE(x)      (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_CFGCTL_ACTIVE_SHIFT)) & NOC_ISP_MAIN_PROBE_CFGCTL_ACTIVE_MASK)
/*! @} */

/*! @name STATPERIOD - Statistics Period */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_STATPERIOD_STATPERIOD_MASK (0x1FU)
#define NOC_ISP_MAIN_PROBE_STATPERIOD_STATPERIOD_SHIFT (0U)
#define NOC_ISP_MAIN_PROBE_STATPERIOD_STATPERIOD(x) (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_STATPERIOD_STATPERIOD_SHIFT)) & NOC_ISP_MAIN_PROBE_STATPERIOD_STATPERIOD_MASK)
/*! @} */

/*! @name STATGO - StatGo */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_STATGO_STATGO_MASK    (0x1U)
#define NOC_ISP_MAIN_PROBE_STATGO_STATGO_SHIFT   (0U)
#define NOC_ISP_MAIN_PROBE_STATGO_STATGO(x)      (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_STATGO_STATGO_SHIFT)) & NOC_ISP_MAIN_PROBE_STATGO_STATGO_MASK)
/*! @} */

/*! @name SRC - Counters n Source */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_SRC_INTEVENT_MASK     (0x1FU)
#define NOC_ISP_MAIN_PROBE_SRC_INTEVENT_SHIFT    (0U)
/*! INTEVENT
 *  0b00000..the counter is disabled.
 *  0b00001..counts Idle cycles (Vld=0 out of a packet).
 *  0b00010..counts effective transfer cycles (Vld=1 and Rdy=1).
 *  0b00011..counts busy cycles (Vld=1 and Rdy=0).
 *  0b00100..counts wait cycles (Vld=0 inside a packet).
 *  0b00101..counts locked-idle cycles (Vld=0 out of a packet and inside a Lock).
 *  0b00110..counts packets (Vld=1 and Head=1 and Rdy=1).
 *  0b00111..counts the packet candidates after the LUT (can be used also as "always" count).
 *  0b01000..counts the total number of bytes (count += 2**Len).
 *  0b01001..counts the cycles where pressure level > 0 (Press[0]=1).
 *  0b01010..counts the cycles where pressure level > 1 (Press[1]=1).
 *  0b01011..counts the cycles where pressure level > 2 (Press[2]=1).
 *  0b01100..counts the packet candidates after the Filter 0.
 *  0b01101..counts the packet candidates after the Filter 1.
 *  0b01110..counts the packet candidates after the Filter 2.
 *  0b01111..counts the packet candidates after the Filter 3.
 *  0b10000..counts the wrap-arround of the counter 2N in the counter 2N+1 (OFF for counter 2N).
 *  0b10001..counts the packet enabled byte on each LUT hit.
 *  0b10010..counts the packet len in byte unit on each LUT hit.
 *  0b10011..counts the packet enabled byte on each FILT_i hit (connected only counter idx = i % nFilter).
 *  0b10100..counts the packet len in byte unit on each FILT_i hit (connected only counter idx = i % nFilter).
 *  0b10101..counts the cycles where pressure level > 0 (Press[3]=1).
 *  0b10110..counts the cycles where pressure level > 0 (Press[4]=1).
 *  0b10111..counts the cycles where pressure level > 0 (Press[5]=1).
 *  0b11000..counts the cycles where pressure level > 0 (Press[6]=1).
 *  0b11001..reserved
 *  0b11010..reserved
 *  0b11011..reserved
 *  0b11100..reserved
 *  0b11101..reserved
 *  0b11110..reserved
 *  0b11111..reserved
 */
#define NOC_ISP_MAIN_PROBE_SRC_INTEVENT(x)       (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_SRC_INTEVENT_SHIFT)) & NOC_ISP_MAIN_PROBE_SRC_INTEVENT_MASK)

#define NOC_ISP_MAIN_PROBE_SRC_EXTEVENT_MASK     (0x20U)
#define NOC_ISP_MAIN_PROBE_SRC_EXTEVENT_SHIFT    (5U)
#define NOC_ISP_MAIN_PROBE_SRC_EXTEVENT(x)       (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_SRC_EXTEVENT_SHIFT)) & NOC_ISP_MAIN_PROBE_SRC_EXTEVENT_MASK)
/*! @} */

/* The count of NOC_ISP_MAIN_PROBE_SRC */
#define NOC_ISP_MAIN_PROBE_SRC_COUNT             (10U)

/*! @name VAL - Counters n Value */
/*! @{ */

#define NOC_ISP_MAIN_PROBE_VAL_COUNTERS_VAL_MASK (0xFFFFFU)
#define NOC_ISP_MAIN_PROBE_VAL_COUNTERS_VAL_SHIFT (0U)
/*! COUNTERS_VAL - Value */
#define NOC_ISP_MAIN_PROBE_VAL_COUNTERS_VAL(x)   (((uint32_t)(((uint32_t)(x)) << NOC_ISP_MAIN_PROBE_VAL_COUNTERS_VAL_SHIFT)) & NOC_ISP_MAIN_PROBE_VAL_COUNTERS_VAL_MASK)
/*! @} */

/* The count of NOC_ISP_MAIN_PROBE_VAL */
#define NOC_ISP_MAIN_PROBE_VAL_COUNT             (10U)


/*!
 * @}
 */ /* end of group NOC_ISP_MAIN_PROBE_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_ISP_MAIN_PROBE_Peripheral_Access_Layer */


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


#endif  /* NOC_ISP_MAIN_PROBE_H_ */

