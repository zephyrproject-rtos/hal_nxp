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
**         CMSIS Peripheral Access Layer for NOC_PROBE_MAIN_PROBE
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
 * @file NOC_PROBE_MAIN_PROBE.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for NOC_PROBE_MAIN_PROBE
 *
 * CMSIS Peripheral Access Layer for NOC_PROBE_MAIN_PROBE
 */

#if !defined(NOC_PROBE_MAIN_PROBE_H_)
#define NOC_PROBE_MAIN_PROBE_H_                  /**< Symbol preventing repeated inclusion */

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
   -- NOC_PROBE_MAIN_PROBE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_PROBE_MAIN_PROBE_Peripheral_Access_Layer NOC_PROBE_MAIN_PROBE Peripheral Access Layer
 * @{
 */

/** NOC_PROBE_MAIN_PROBE - Size of Registers Arrays */
#define NOC_PROBE_MAIN_PROBE_COUNTERS_COUNT       10u

/** NOC_PROBE_MAIN_PROBE - Register Layout Typedef */
typedef struct {
  __I  uint32_t ID_COREID;                         /**< Core ID, offset: 0x0 */
  __I  uint32_t ID_REVISIONID;                     /**< Revision ID, offset: 0x4 */
  __IO uint32_t MAINCTL;                           /**< Main Control, offset: 0x8 */
  __IO uint32_t CFGCTL;                            /**< Configuration Control, offset: 0xC */
  __IO uint32_t TRACEPORTSEL;                      /**< Trace Port Select, offset: 0x10 */
  __IO uint32_t FILTERLUT;                         /**< Filter Lookup Table, offset: 0x14 */
  __IO uint32_t TRACEALARMEN;                      /**< Trace Alarm Enable, offset: 0x18 */
  __I  uint32_t TRACEALARMSTATUS;                  /**< Trace Alarm Status, offset: 0x1C */
  __O  uint32_t TRACEALARMCLR;                     /**< Trace Alarm Clear, offset: 0x20 */
  __IO uint32_t STATPERIOD;                        /**< Statistics Period, offset: 0x24 */
  __O  uint32_t STATGO;                            /**< StatGo, offset: 0x28 */
       uint8_t RESERVED_0[84];
  __IO uint32_t FILTERS_0_ROUTEIDBASE;             /**< Filter n Route ID Base, offset: 0x80 */
  __IO uint32_t FILTERS_0_ROUTEIDMASK;             /**< Filter n Route ID Mask, offset: 0x84 */
  __IO uint32_t FILTERS_0_ADDRBASE_LOW;            /**< Filter n Addr Base Low, offset: 0x88 */
  __IO uint32_t FILTERS_0_ADDRBASE_HIGH;           /**< Filter n Addr Base High, offset: 0x8C */
  __IO uint32_t FILTERS_0_WINDOWSIZE;              /**< Filter n Window Size, offset: 0x90 */
  __IO uint32_t FILTERS_0_SECURITYBASE;            /**< Filter n Security Base, offset: 0x94 */
  __IO uint32_t FILTERS_0_SECURITYMASK;            /**< Filter n Security Mask, offset: 0x98 */
  __IO uint32_t FILTERS_0_OPCODE;                  /**< Filter n Packet Probe, offset: 0x9C */
  __IO uint32_t FILTERS_0_STATUS;                  /**< Filter n Status, offset: 0xA0 */
  __IO uint32_t FILTERS_0_LENGTH;                  /**< Filter n Length, offset: 0xA4 */
  __IO uint32_t PROBE_MAIN_PROBE_FILTERS_0_URGENCY; /**< offset: 0xA8 */
       uint8_t RESERVED_1[52];
  __IO uint32_t FILTERS_1_ROUTEIDBASE;             /**< Filter n Route ID Base, offset: 0xE0 */
  __IO uint32_t FILTERS_1_ROUTEIDMASK;             /**< Filter n Route ID Mask, offset: 0xE4 */
  __IO uint32_t FILTERS_1_ADDRBASE_LOW;            /**< Filter n Addr Base Low, offset: 0xE8 */
  __IO uint32_t FILTERS_1_ADDRBASE_HIGH;           /**< Filter n Addr Base High, offset: 0xEC */
  __IO uint32_t FILTERS_1_WINDOWSIZE;              /**< Filter n Window Size, offset: 0xF0 */
  __IO uint32_t FILTERS_1_SECURITYBASE;            /**< Filter n Security Base, offset: 0xF4 */
  __IO uint32_t FILTERS_1_SECURITYMASK;            /**< Filter n Security Mask, offset: 0xF8 */
  __IO uint32_t FILTERS_1_OPCODE;                  /**< Filter n Packet Probe, offset: 0xFC */
  __IO uint32_t FILTERS_1_STATUS;                  /**< Filter n Status, offset: 0x100 */
  __IO uint32_t FILTERS_1_LENGTH;                  /**< Filter n Length, offset: 0x104 */
  __IO uint32_t PROBE_MAIN_PROBE_FILTERS_1_URGENCY; /**< offset: 0x108 */
       uint8_t RESERVED_2[244];
  struct {                                         /* offset: 0x200, array step: 0x10 */
    __IO uint32_t PORTSEL;                           /**< Counters n Port Select, array offset: 0x200, array step: 0x10 */
    __IO uint32_t SRC;                               /**< Counters n Source, array offset: 0x204, array step: 0x10 */
         uint8_t RESERVED_0[4];
    __I  uint32_t VAL;                               /**< Counters n Value, array offset: 0x20C, array step: 0x10 */
  } COUNTERS[NOC_PROBE_MAIN_PROBE_COUNTERS_COUNT];
} NOC_PROBE_MAIN_PROBE_Type;

/* ----------------------------------------------------------------------------
   -- NOC_PROBE_MAIN_PROBE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NOC_PROBE_MAIN_PROBE_Register_Masks NOC_PROBE_MAIN_PROBE Register Masks
 * @{
 */

/*! @name ID_COREID - Core ID */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORETYPEID_MASK (0xFFU)
#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORETYPEID_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORETYPEID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_ID_COREID_CORETYPEID_SHIFT)) & NOC_PROBE_MAIN_PROBE_ID_COREID_CORETYPEID_MASK)

#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORECHECKSUM_MASK (0xFFFFFF00U)
#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORECHECKSUM_SHIFT (8U)
#define NOC_PROBE_MAIN_PROBE_ID_COREID_CORECHECKSUM(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_ID_COREID_CORECHECKSUM_SHIFT)) & NOC_PROBE_MAIN_PROBE_ID_COREID_CORECHECKSUM_MASK)
/*! @} */

/*! @name ID_REVISIONID - Revision ID */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_USERID_MASK (0xFFU)
#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_USERID_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_USERID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_ID_REVISIONID_USERID_SHIFT)) & NOC_PROBE_MAIN_PROBE_ID_REVISIONID_USERID_MASK)

#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_NOCID_MASK (0xFFFFFF00U)
#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_NOCID_SHIFT (8U)
#define NOC_PROBE_MAIN_PROBE_ID_REVISIONID_NOCID(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_ID_REVISIONID_NOCID_SHIFT)) & NOC_PROBE_MAIN_PROBE_ID_REVISIONID_NOCID_MASK)
/*! @} */

/*! @name MAINCTL - Main Control */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_MAINCTL_ERREN_MASK  (0x1U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_ERREN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_ERREN(x)    (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_ERREN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_ERREN_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_TRACEEN_MASK (0x2U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_TRACEEN_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_TRACEEN(x)  (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_TRACEEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_TRACEEN_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_PAYLOADEN_MASK (0x4U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_PAYLOADEN_SHIFT (2U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_PAYLOADEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_PAYLOADEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_PAYLOADEN_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATEN_MASK (0x8U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATEN_SHIFT (3U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATEN(x)   (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_STATEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_STATEN_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_ALARMEN_MASK (0x10U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_ALARMEN_SHIFT (4U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_ALARMEN(x)  (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_ALARMEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_ALARMEN_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATCONDDUMP_MASK (0x20U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATCONDDUMP_SHIFT (5U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_STATCONDDUMP(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_STATCONDDUMP_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_STATCONDDUMP_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_MASK (0x40U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_SHIFT (6U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_INTRUSIVEMODE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_INTRUSIVEMODE_MASK)

#define NOC_PROBE_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_MASK (0x80U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_SHIFT (7U)
#define NOC_PROBE_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_MAINCTL_FILTBYTEALWAYSCHAINABLEEN_MASK)
/*! @} */

/*! @name CFGCTL - Configuration Control */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_CFGCTL_GLOBALEN_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_CFGCTL_GLOBALEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_CFGCTL_GLOBALEN(x)  (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_CFGCTL_GLOBALEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_CFGCTL_GLOBALEN_MASK)

#define NOC_PROBE_MAIN_PROBE_CFGCTL_ACTIVE_MASK  (0x2U)
#define NOC_PROBE_MAIN_PROBE_CFGCTL_ACTIVE_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_CFGCTL_ACTIVE(x)    (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_CFGCTL_ACTIVE_SHIFT)) & NOC_PROBE_MAIN_PROBE_CFGCTL_ACTIVE_MASK)
/*! @} */

/*! @name TRACEPORTSEL - Trace Port Select */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_TRACEPORTSEL_TRACEPORTSEL_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_TRACEPORTSEL_TRACEPORTSEL_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_TRACEPORTSEL_TRACEPORTSEL(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_TRACEPORTSEL_TRACEPORTSEL_SHIFT)) & NOC_PROBE_MAIN_PROBE_TRACEPORTSEL_TRACEPORTSEL_MASK)
/*! @} */

/*! @name FILTERLUT - Filter Lookup Table */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERLUT_FILTERLUT_MASK (0xFU)
#define NOC_PROBE_MAIN_PROBE_FILTERLUT_FILTERLUT_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_FILTERLUT_FILTERLUT(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERLUT_FILTERLUT_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERLUT_FILTERLUT_MASK)
/*! @} */

/*! @name TRACEALARMEN - Trace Alarm Enable */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_TRACEALARMEN_TRACEALARMEN_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMEN_TRACEALARMEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMEN_TRACEALARMEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_TRACEALARMEN_TRACEALARMEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_TRACEALARMEN_TRACEALARMEN_MASK)
/*! @} */

/*! @name TRACEALARMSTATUS - Trace Alarm Status */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_TRACEALARMSTATUS_TRACEALARMSTATUS_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMSTATUS_TRACEALARMSTATUS_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMSTATUS_TRACEALARMSTATUS(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_TRACEALARMSTATUS_TRACEALARMSTATUS_SHIFT)) & NOC_PROBE_MAIN_PROBE_TRACEALARMSTATUS_TRACEALARMSTATUS_MASK)
/*! @} */

/*! @name TRACEALARMCLR - Trace Alarm Clear */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_TRACEALARMCLR_TRACEALARMCLR_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMCLR_TRACEALARMCLR_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_TRACEALARMCLR_TRACEALARMCLR(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_TRACEALARMCLR_TRACEALARMCLR_SHIFT)) & NOC_PROBE_MAIN_PROBE_TRACEALARMCLR_TRACEALARMCLR_MASK)
/*! @} */

/*! @name STATPERIOD - Statistics Period */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_STATPERIOD_STATPERIOD_MASK (0x1FU)
#define NOC_PROBE_MAIN_PROBE_STATPERIOD_STATPERIOD_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_STATPERIOD_STATPERIOD(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_STATPERIOD_STATPERIOD_SHIFT)) & NOC_PROBE_MAIN_PROBE_STATPERIOD_STATPERIOD_MASK)
/*! @} */

/*! @name STATGO - StatGo */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_STATGO_STATGO_MASK  (0x1U)
#define NOC_PROBE_MAIN_PROBE_STATGO_STATGO_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_STATGO_STATGO(x)    (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_STATGO_STATGO_SHIFT)) & NOC_PROBE_MAIN_PROBE_STATGO_STATGO_MASK)
/*! @} */

/*! @name FILTERS_0_ROUTEIDBASE - Filter n Route ID Base */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDBASE_FILTERS_ROUTEIDBASE_MASK (0xFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDBASE_FILTERS_ROUTEIDBASE_SHIFT (0U)
/*! FILTERS_ROUTEIDBASE - Filter n Route ID Base */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDBASE_FILTERS_ROUTEIDBASE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDBASE_FILTERS_ROUTEIDBASE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDBASE_FILTERS_ROUTEIDBASE_MASK)
/*! @} */

/*! @name FILTERS_0_ROUTEIDMASK - Filter n Route ID Mask */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDMASK_FILTERS_ROUTEIDMASK_MASK (0xFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDMASK_FILTERS_ROUTEIDMASK_SHIFT (0U)
/*! FILTERS_ROUTEIDMASK - Filter n Route ID Mask */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDMASK_FILTERS_ROUTEIDMASK(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDMASK_FILTERS_ROUTEIDMASK_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_ROUTEIDMASK_FILTERS_ROUTEIDMASK_MASK)
/*! @} */

/*! @name FILTERS_0_ADDRBASE_LOW - Filter n Addr Base Low */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_MASK (0xFFFFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_SHIFT (0U)
/*! FILTERS_ADDRBASE_LOW - Address LSB register */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_MASK)
/*! @} */

/*! @name FILTERS_0_ADDRBASE_HIGH - Filter n Addr Base High */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_MASK (0xFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_SHIFT (0U)
/*! FILTERS_ADDRBASE_HIGH - Address MSB register */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_MASK)
/*! @} */

/*! @name FILTERS_0_WINDOWSIZE - Filter n Window Size */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_WINDOWSIZE_FILTERS_WINDOWSIZE_MASK (0x3FU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_WINDOWSIZE_FILTERS_WINDOWSIZE_SHIFT (0U)
/*! FILTERS_WINDOWSIZE - Window Size */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_WINDOWSIZE_FILTERS_WINDOWSIZE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_WINDOWSIZE_FILTERS_WINDOWSIZE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_WINDOWSIZE_FILTERS_WINDOWSIZE_MASK)
/*! @} */

/*! @name FILTERS_0_SECURITYBASE - Filter n Security Base */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYBASE_FILTERS_SECURITYBASE_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYBASE_FILTERS_SECURITYBASE_SHIFT (0U)
/*! FILTERS_SECURITYBASE - Security Base */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYBASE_FILTERS_SECURITYBASE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYBASE_FILTERS_SECURITYBASE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYBASE_FILTERS_SECURITYBASE_MASK)
/*! @} */

/*! @name FILTERS_0_SECURITYMASK - Filter n Security Mask */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYMASK_FILTERS_0_SECURITYMASK_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYMASK_FILTERS_0_SECURITYMASK_SHIFT (0U)
/*! FILTERS_0_SECURITYMASK - Security Mask */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYMASK_FILTERS_0_SECURITYMASK(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYMASK_FILTERS_0_SECURITYMASK_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_SECURITYMASK_FILTERS_0_SECURITYMASK_MASK)
/*! @} */

/*! @name FILTERS_0_OPCODE - Filter n Packet Probe */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_RDEN_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_RDEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_RDEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_RDEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_RDEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_WREN_MASK (0x2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_WREN_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_WREN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_WREN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_WREN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_LOCKEN_MASK (0x4U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_LOCKEN_SHIFT (2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_LOCKEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_LOCKEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_LOCKEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_URGEN_MASK (0x8U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_URGEN_SHIFT (3U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_URGEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_URGEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_OPCODE_URGEN_MASK)
/*! @} */

/*! @name FILTERS_0_STATUS - Filter n Status */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_REQEN_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_REQEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_REQEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_REQEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_REQEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_RSPEN_MASK (0x2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_RSPEN_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_RSPEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_RSPEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_STATUS_RSPEN_MASK)
/*! @} */

/*! @name FILTERS_0_LENGTH - Filter n Length */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_0_LENGTH_FILTERS_0_LENGTH_MASK (0xFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_LENGTH_FILTERS_0_LENGTH_SHIFT (0U)
/*! FILTERS_0_LENGTH - Length */
#define NOC_PROBE_MAIN_PROBE_FILTERS_0_LENGTH_FILTERS_0_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_0_LENGTH_FILTERS_0_LENGTH_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_0_LENGTH_FILTERS_0_LENGTH_MASK)
/*! @} */

/*! @name PROBE_MAIN_PROBE_FILTERS_0_URGENCY -  */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_0_URGENCY_FILTERS_0_URGENCY_MASK (0x3U)
#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_0_URGENCY_FILTERS_0_URGENCY_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_0_URGENCY_FILTERS_0_URGENCY(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_0_URGENCY_FILTERS_0_URGENCY_SHIFT)) & NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_0_URGENCY_FILTERS_0_URGENCY_MASK)
/*! @} */

/*! @name FILTERS_1_ROUTEIDBASE - Filter n Route ID Base */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDBASE_FILTERS_ROUTEIDBASE_MASK (0xFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDBASE_FILTERS_ROUTEIDBASE_SHIFT (0U)
/*! FILTERS_ROUTEIDBASE - Filter n Route ID Base */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDBASE_FILTERS_ROUTEIDBASE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDBASE_FILTERS_ROUTEIDBASE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDBASE_FILTERS_ROUTEIDBASE_MASK)
/*! @} */

/*! @name FILTERS_1_ROUTEIDMASK - Filter n Route ID Mask */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDMASK_FILTERS_ROUTEIDMASK_MASK (0xFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDMASK_FILTERS_ROUTEIDMASK_SHIFT (0U)
/*! FILTERS_ROUTEIDMASK - Filter n Route ID Mask */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDMASK_FILTERS_ROUTEIDMASK(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDMASK_FILTERS_ROUTEIDMASK_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_ROUTEIDMASK_FILTERS_ROUTEIDMASK_MASK)
/*! @} */

/*! @name FILTERS_1_ADDRBASE_LOW - Filter n Addr Base Low */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_MASK (0xFFFFFFFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_SHIFT (0U)
/*! FILTERS_ADDRBASE_LOW - Address LSB register */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_LOW_FILTERS_ADDRBASE_LOW_MASK)
/*! @} */

/*! @name FILTERS_1_ADDRBASE_HIGH - Filter n Addr Base High */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_MASK (0xFFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_SHIFT (0U)
/*! FILTERS_ADDRBASE_HIGH - Address MSB register */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_ADDRBASE_HIGH_FILTERS_ADDRBASE_HIGH_MASK)
/*! @} */

/*! @name FILTERS_1_WINDOWSIZE - Filter n Window Size */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_WINDOWSIZE_FILTERS_WINDOWSIZE_MASK (0x3FU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_WINDOWSIZE_FILTERS_WINDOWSIZE_SHIFT (0U)
/*! FILTERS_WINDOWSIZE - Window Size */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_WINDOWSIZE_FILTERS_WINDOWSIZE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_WINDOWSIZE_FILTERS_WINDOWSIZE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_WINDOWSIZE_FILTERS_WINDOWSIZE_MASK)
/*! @} */

/*! @name FILTERS_1_SECURITYBASE - Filter n Security Base */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYBASE_FILTERS_SECURITYBASE_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYBASE_FILTERS_SECURITYBASE_SHIFT (0U)
/*! FILTERS_SECURITYBASE - Security Base */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYBASE_FILTERS_SECURITYBASE(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYBASE_FILTERS_SECURITYBASE_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYBASE_FILTERS_SECURITYBASE_MASK)
/*! @} */

/*! @name FILTERS_1_SECURITYMASK - Filter n Security Mask */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYMASK_FILTERS_1_SECURITYMASK_MASK (0x7U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYMASK_FILTERS_1_SECURITYMASK_SHIFT (0U)
/*! FILTERS_1_SECURITYMASK - Security Mask */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYMASK_FILTERS_1_SECURITYMASK(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYMASK_FILTERS_1_SECURITYMASK_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_SECURITYMASK_FILTERS_1_SECURITYMASK_MASK)
/*! @} */

/*! @name FILTERS_1_OPCODE - Filter n Packet Probe */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_RDEN_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_RDEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_RDEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_RDEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_RDEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_WREN_MASK (0x2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_WREN_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_WREN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_WREN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_WREN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_LOCKEN_MASK (0x4U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_LOCKEN_SHIFT (2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_LOCKEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_LOCKEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_LOCKEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_URGEN_MASK (0x8U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_URGEN_SHIFT (3U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_URGEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_URGEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_OPCODE_URGEN_MASK)
/*! @} */

/*! @name FILTERS_1_STATUS - Filter n Status */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_REQEN_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_REQEN_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_REQEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_REQEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_REQEN_MASK)

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_RSPEN_MASK (0x2U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_RSPEN_SHIFT (1U)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_RSPEN(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_RSPEN_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_STATUS_RSPEN_MASK)
/*! @} */

/*! @name FILTERS_1_LENGTH - Filter n Length */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_FILTERS_1_LENGTH_FILTERS_1_LENGTH_MASK (0xFU)
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_LENGTH_FILTERS_1_LENGTH_SHIFT (0U)
/*! FILTERS_1_LENGTH - Length */
#define NOC_PROBE_MAIN_PROBE_FILTERS_1_LENGTH_FILTERS_1_LENGTH(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_FILTERS_1_LENGTH_FILTERS_1_LENGTH_SHIFT)) & NOC_PROBE_MAIN_PROBE_FILTERS_1_LENGTH_FILTERS_1_LENGTH_MASK)
/*! @} */

/*! @name PROBE_MAIN_PROBE_FILTERS_1_URGENCY -  */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_1_URGENCY_FILTERS_1_URGENCY_MASK (0x3U)
#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_1_URGENCY_FILTERS_1_URGENCY_SHIFT (0U)
#define NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_1_URGENCY_FILTERS_1_URGENCY(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_1_URGENCY_FILTERS_1_URGENCY_SHIFT)) & NOC_PROBE_MAIN_PROBE_PROBE_MAIN_PROBE_FILTERS_1_URGENCY_FILTERS_1_URGENCY_MASK)
/*! @} */

/*! @name PORTSEL - Counters n Port Select */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_PORTSEL_COUNTERS_PORTSEL_MASK (0x1U)
#define NOC_PROBE_MAIN_PROBE_PORTSEL_COUNTERS_PORTSEL_SHIFT (0U)
/*! COUNTERS_PORTSEL - Port Select */
#define NOC_PROBE_MAIN_PROBE_PORTSEL_COUNTERS_PORTSEL(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_PORTSEL_COUNTERS_PORTSEL_SHIFT)) & NOC_PROBE_MAIN_PROBE_PORTSEL_COUNTERS_PORTSEL_MASK)
/*! @} */

/* The count of NOC_PROBE_MAIN_PROBE_PORTSEL */
#define NOC_PROBE_MAIN_PROBE_PORTSEL_COUNT       (10U)

/*! @name SRC - Counters n Source */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_SRC_INTEVENT_MASK   (0x1FU)
#define NOC_PROBE_MAIN_PROBE_SRC_INTEVENT_SHIFT  (0U)
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
#define NOC_PROBE_MAIN_PROBE_SRC_INTEVENT(x)     (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_SRC_INTEVENT_SHIFT)) & NOC_PROBE_MAIN_PROBE_SRC_INTEVENT_MASK)
/*! @} */

/* The count of NOC_PROBE_MAIN_PROBE_SRC */
#define NOC_PROBE_MAIN_PROBE_SRC_COUNT           (10U)

/*! @name VAL - Counters n Value */
/*! @{ */

#define NOC_PROBE_MAIN_PROBE_VAL_COUNTERS_VAL_MASK (0xFFFFFU)
#define NOC_PROBE_MAIN_PROBE_VAL_COUNTERS_VAL_SHIFT (0U)
/*! COUNTERS_VAL - Value */
#define NOC_PROBE_MAIN_PROBE_VAL_COUNTERS_VAL(x) (((uint32_t)(((uint32_t)(x)) << NOC_PROBE_MAIN_PROBE_VAL_COUNTERS_VAL_SHIFT)) & NOC_PROBE_MAIN_PROBE_VAL_COUNTERS_VAL_MASK)
/*! @} */

/* The count of NOC_PROBE_MAIN_PROBE_VAL */
#define NOC_PROBE_MAIN_PROBE_VAL_COUNT           (10U)


/*!
 * @}
 */ /* end of group NOC_PROBE_MAIN_PROBE_Register_Masks */


/*!
 * @}
 */ /* end of group NOC_PROBE_MAIN_PROBE_Peripheral_Access_Layer */


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


#endif  /* NOC_PROBE_MAIN_PROBE_H_ */

