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
**         CMSIS Peripheral Access Layer for xpc
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
 * @file PERI_xpc.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for xpc
 *
 * CMSIS Peripheral Access Layer for xpc
 */

#if !defined(PERI_XPC_H_)
#define PERI_XPC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- xpc Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup xpc_Peripheral_Access_Layer xpc Peripheral Access Layer
 * @{
 */

/** xpc - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONTR;                             /**< Control, offset: 0x0 */
  __IO uint32_t TIMER;                             /**< Timer, offset: 0x4 */
  __IO uint32_t MEASTICO;                          /**< MeasurementTimeControl, offset: 0x8 */
  __IO uint32_t SWTAG;                             /**< SW_Tag, offset: 0xC */
  __I  uint32_t MEASTIME;                          /**< MeasurementTime, offset: 0x10 */
  __I  uint32_t GLOBALC;                           /**< Global_Counter, offset: 0x14 */
  __IO uint32_t MU00SWIT;                          /**< MU00_Switch, offset: 0x18 */
  __I  uint32_t MU00DACO;                          /**< MU00_Data_Counter, offset: 0x1C */
  __I  uint32_t MU00BUCO;                          /**< MU00_Busy_Counter, offset: 0x20 */
  __I  uint32_t MU00TRCO;                          /**< MU00_Transfer_Counter, offset: 0x24 */
  __I  uint32_t MU00ADCO;                          /**< MU00_Addrbusy_Counter, offset: 0x28 */
  __I  uint32_t MU00LACO;                          /**< MU00_Latency_Counter, offset: 0x2C */
  __IO uint32_t MU01SWIT;                          /**< MU01_Switch, offset: 0x30 */
  __I  uint32_t MU01DACO;                          /**< MU01_Data_Counter, offset: 0x34 */
  __I  uint32_t MU01BUCO;                          /**< MU01_Busy_Counter, offset: 0x38 */
  __I  uint32_t MU01TRCO;                          /**< MU01_Transfer_Counter, offset: 0x3C */
  __I  uint32_t MU01ADCO;                          /**< MU01_Addrbusy_Counter, offset: 0x40 */
  __I  uint32_t MU01LACO;                          /**< MU01_Latency_Counter, offset: 0x44 */
  __IO uint32_t MU02SWIT;                          /**< MU02_Switch, offset: 0x48 */
  __I  uint32_t MU02DACO;                          /**< MU02_Data_Counter, offset: 0x4C */
  __I  uint32_t MU02BUCO;                          /**< MU02_Busy_Counter, offset: 0x50 */
  __I  uint32_t MU02TRCO;                          /**< MU02_Transfer_Counter, offset: 0x54 */
  __I  uint32_t MU02ADCO;                          /**< MU02_Addrbusy_Counter, offset: 0x58 */
  __I  uint32_t MU02LACO;                          /**< MU02_Latency_Counter, offset: 0x5C */
  __IO uint32_t MU03SWIT;                          /**< MU03_Switch, offset: 0x60 */
  __I  uint32_t MU03DACO;                          /**< MU03_Data_Counter, offset: 0x64 */
  __I  uint32_t MU03BUOU;                          /**< MU03_Busy_Counter, offset: 0x68 */
  __I  uint32_t MU03TRCO;                          /**< MU03_Transfer_Counter, offset: 0x6C */
  __I  uint32_t MU03ADCO;                          /**< MU03_Addrbusy_Counter, offset: 0x70 */
  __I  uint32_t MU03LACO;                          /**< MU03_Latency_Counter, offset: 0x74 */
  __IO uint32_t MU04SWIT;                          /**< MU04_Switch, offset: 0x78 */
  __I  uint32_t MU04DACO;                          /**< MU04_Data_Counter, offset: 0x7C */
  __I  uint32_t MU04BUCO;                          /**< MU04_Busy_Counter, offset: 0x80 */
  __I  uint32_t MU04TRCO;                          /**< MU04_Transfer_Counter, offset: 0x84 */
  __I  uint32_t MU04ADCO;                          /**< MU04_Addrbusy_Counter, offset: 0x88 */
  __I  uint32_t MU04LACO;                          /**< MU04_Latency_Counter, offset: 0x8C */
} xpc_Type;

/* ----------------------------------------------------------------------------
   -- xpc Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup xpc_Register_Masks xpc Register Masks
 * @{
 */

/*! @name CONTR - Control */
/*! @{ */

#define xpc_CONTR_Enable_MASK                    (0x1U)
#define xpc_CONTR_Enable_SHIFT                   (0U)
/*! Enable - Enable */
#define xpc_CONTR_Enable(x)                      (((uint32_t)(((uint32_t)(x)) << xpc_CONTR_Enable_SHIFT)) & xpc_CONTR_Enable_MASK)

#define xpc_CONTR_Mode1_MASK                     (0x6U)
#define xpc_CONTR_Mode1_SHIFT                    (1U)
/*! Mode1 - Mode
 *  0b00..Manual measurement end
 *  0b01..Timer controlled measurement end
 *  0b10..Continuous measurement; retriggered by reading SW_Tag register
 */
#define xpc_CONTR_Mode1(x)                       (((uint32_t)(((uint32_t)(x)) << xpc_CONTR_Mode1_SHIFT)) & xpc_CONTR_Mode1_MASK)

#define xpc_CONTR_IncrMode_MASK                  (0x40000000U)
#define xpc_CONTR_IncrMode_SHIFT                 (30U)
/*! IncrMode - IncrementMode */
#define xpc_CONTR_IncrMode(x)                    (((uint32_t)(((uint32_t)(x)) << xpc_CONTR_IncrMode_SHIFT)) & xpc_CONTR_IncrMode_MASK)

#define xpc_CONTR_OTCDis_MASK                    (0x80000000U)
#define xpc_CONTR_OTCDis_SHIFT                   (31U)
/*! OTCDis - OTCDisable */
#define xpc_CONTR_OTCDis(x)                      (((uint32_t)(((uint32_t)(x)) << xpc_CONTR_OTCDis_SHIFT)) & xpc_CONTR_OTCDis_MASK)
/*! @} */

/*! @name TIMER - Timer */
/*! @{ */

#define xpc_TIMER_Load_MASK                      (0xFFFFFFFU)
#define xpc_TIMER_Load_SHIFT                     (0U)
/*! Load - Load */
#define xpc_TIMER_Load(x)                        (((uint32_t)(((uint32_t)(x)) << xpc_TIMER_Load_SHIFT)) & xpc_TIMER_Load_MASK)

#define xpc_TIMER_Divider_MASK                   (0xF0000000U)
#define xpc_TIMER_Divider_SHIFT                  (28U)
/*! Divider - Divider */
#define xpc_TIMER_Divider(x)                     (((uint32_t)(((uint32_t)(x)) << xpc_TIMER_Divider_SHIFT)) & xpc_TIMER_Divider_MASK)
/*! @} */

/*! @name MEASTICO - MeasurementTimeControl */
/*! @{ */

#define xpc_MEASTICO_MTDiv_MASK                  (0xFFFFFU)
#define xpc_MEASTICO_MTDiv_SHIFT                 (0U)
/*! MTDiv - MTDivider */
#define xpc_MEASTICO_MTDiv(x)                    (((uint32_t)(((uint32_t)(x)) << xpc_MEASTICO_MTDiv_SHIFT)) & xpc_MEASTICO_MTDiv_MASK)

#define xpc_MEASTICO_MTEnable_MASK               (0x80000000U)
#define xpc_MEASTICO_MTEnable_SHIFT              (31U)
/*! MTEnable - MTEnable */
#define xpc_MEASTICO_MTEnable(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MEASTICO_MTEnable_SHIFT)) & xpc_MEASTICO_MTEnable_MASK)
/*! @} */

/*! @name SWTAG - SW_Tag */
/*! @{ */

#define xpc_SWTAG_Tag_MASK                       (0xFFFFFFFFU)
#define xpc_SWTAG_Tag_SHIFT                      (0U)
/*! Tag - Tag */
#define xpc_SWTAG_Tag(x)                         (((uint32_t)(((uint32_t)(x)) << xpc_SWTAG_Tag_SHIFT)) & xpc_SWTAG_Tag_MASK)
/*! @} */

/*! @name MEASTIME - MeasurementTime */
/*! @{ */

#define xpc_MEASTIME_Time_MASK                   (0xFFFFFFFFU)
#define xpc_MEASTIME_Time_SHIFT                  (0U)
/*! Time - Time */
#define xpc_MEASTIME_Time(x)                     (((uint32_t)(((uint32_t)(x)) << xpc_MEASTIME_Time_SHIFT)) & xpc_MEASTIME_Time_MASK)
/*! @} */

/*! @name GLOBALC - Global_Counter */
/*! @{ */

#define xpc_GLOBALC_Global_MASK                  (0xFFFFFFFFU)
#define xpc_GLOBALC_Global_SHIFT                 (0U)
/*! Global - Global */
#define xpc_GLOBALC_Global(x)                    (((uint32_t)(((uint32_t)(x)) << xpc_GLOBALC_Global_SHIFT)) & xpc_GLOBALC_Global_MASK)
/*! @} */

/*! @name MU00SWIT - MU00_Switch */
/*! @{ */

#define xpc_MU00SWIT_MU00Sel_MASK                (0xFU)
#define xpc_MU00SWIT_MU00Sel_SHIFT               (0U)
/*! MU00Sel - MU00_Select
 *  0b0000..fetchlayer0 read direction (ACLK clock)
 *  0b0001..fetchlayer1 read direction (ACLK clock)
 *  0b0010..fetchyuv3 read direction (ACLK clock)
 *  0b0011..fetchyuv0 read direction (ACLK clock)
 *  0b0100..fetchyuv1 read direction (ACLK clock)
 *  0b0101..fetcheco0 read direction (ACLK clock)
 *  0b0110..fetcheco1 read direction (ACLK clock)
 *  0b0111..fetchdecode9 read direction (ACLK clock)
 *  0b1000..fetchrot9 read direction (ACLK clock)
 *  0b1001..fetcheco9 read direction (ACLK clock)
 *  0b1010..store9 write direction (ACLK clock)
 *  0b1011..cmdseq read direction (ACLK clock)
 *  0b1100..cmdseq write direction (ACLK clock)
 */
#define xpc_MU00SWIT_MU00Sel(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU00SWIT_MU00Sel_SHIFT)) & xpc_MU00SWIT_MU00Sel_MASK)
/*! @} */

/*! @name MU00DACO - MU00_Data_Counter */
/*! @{ */

#define xpc_MU00DACO_MU00Data_MASK               (0xFFFFFFFFU)
#define xpc_MU00DACO_MU00Data_SHIFT              (0U)
/*! MU00Data - MU00_Data */
#define xpc_MU00DACO_MU00Data(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU00DACO_MU00Data_SHIFT)) & xpc_MU00DACO_MU00Data_MASK)
/*! @} */

/*! @name MU00BUCO - MU00_Busy_Counter */
/*! @{ */

#define xpc_MU00BUCO_MU00Busy_MASK               (0xFFFFFFFFU)
#define xpc_MU00BUCO_MU00Busy_SHIFT              (0U)
/*! MU00Busy - MU00_Busy */
#define xpc_MU00BUCO_MU00Busy(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU00BUCO_MU00Busy_SHIFT)) & xpc_MU00BUCO_MU00Busy_MASK)
/*! @} */

/*! @name MU00TRCO - MU00_Transfer_Counter */
/*! @{ */

#define xpc_MU00TRCO_MU00Tran_MASK               (0xFFFFFFFFU)
#define xpc_MU00TRCO_MU00Tran_SHIFT              (0U)
/*! MU00Tran - MU00_Transfer */
#define xpc_MU00TRCO_MU00Tran(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU00TRCO_MU00Tran_SHIFT)) & xpc_MU00TRCO_MU00Tran_MASK)
/*! @} */

/*! @name MU00ADCO - MU00_Addrbusy_Counter */
/*! @{ */

#define xpc_MU00ADCO_MU00Addr_MASK               (0xFFFFFFFFU)
#define xpc_MU00ADCO_MU00Addr_SHIFT              (0U)
/*! MU00Addr - MU00_Addrbusy */
#define xpc_MU00ADCO_MU00Addr(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU00ADCO_MU00Addr_SHIFT)) & xpc_MU00ADCO_MU00Addr_MASK)
/*! @} */

/*! @name MU00LACO - MU00_Latency_Counter */
/*! @{ */

#define xpc_MU00LACO_MU00Lat_MASK                (0xFFFFFFFFU)
#define xpc_MU00LACO_MU00Lat_SHIFT               (0U)
/*! MU00Lat - MU00_Latency */
#define xpc_MU00LACO_MU00Lat(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU00LACO_MU00Lat_SHIFT)) & xpc_MU00LACO_MU00Lat_MASK)
/*! @} */

/*! @name MU01SWIT - MU01_Switch */
/*! @{ */

#define xpc_MU01SWIT_MU01Sel_MASK                (0xFU)
#define xpc_MU01SWIT_MU01Sel_SHIFT               (0U)
/*! MU01Sel - MU01_Select
 *  0b0000..fetchlayer0 read direction (ACLK clock)
 *  0b0001..fetchlayer1 read direction (ACLK clock)
 *  0b0010..fetchyuv3 read direction (ACLK clock)
 *  0b0011..fetchyuv0 read direction (ACLK clock)
 *  0b0100..fetchyuv1 read direction (ACLK clock)
 *  0b0101..fetcheco0 read direction (ACLK clock)
 *  0b0110..fetcheco1 read direction (ACLK clock)
 *  0b0111..fetchdecode9 read direction (ACLK clock)
 *  0b1000..fetchrot9 read direction (ACLK clock)
 *  0b1001..fetcheco9 read direction (ACLK clock)
 *  0b1010..store9 write direction (ACLK clock)
 *  0b1011..cmdseq read direction (ACLK clock)
 *  0b1100..cmdseq write direction (ACLK clock)
 */
#define xpc_MU01SWIT_MU01Sel(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU01SWIT_MU01Sel_SHIFT)) & xpc_MU01SWIT_MU01Sel_MASK)
/*! @} */

/*! @name MU01DACO - MU01_Data_Counter */
/*! @{ */

#define xpc_MU01DACO_MU01Data_MASK               (0xFFFFFFFFU)
#define xpc_MU01DACO_MU01Data_SHIFT              (0U)
/*! MU01Data - MU01_Data */
#define xpc_MU01DACO_MU01Data(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU01DACO_MU01Data_SHIFT)) & xpc_MU01DACO_MU01Data_MASK)
/*! @} */

/*! @name MU01BUCO - MU01_Busy_Counter */
/*! @{ */

#define xpc_MU01BUCO_MU01Busy_MASK               (0xFFFFFFFFU)
#define xpc_MU01BUCO_MU01Busy_SHIFT              (0U)
/*! MU01Busy - MU01_Busy */
#define xpc_MU01BUCO_MU01Busy(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU01BUCO_MU01Busy_SHIFT)) & xpc_MU01BUCO_MU01Busy_MASK)
/*! @} */

/*! @name MU01TRCO - MU01_Transfer_Counter */
/*! @{ */

#define xpc_MU01TRCO_MU01Tran_MASK               (0xFFFFFFFFU)
#define xpc_MU01TRCO_MU01Tran_SHIFT              (0U)
/*! MU01Tran - MU01_Transfer */
#define xpc_MU01TRCO_MU01Tran(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU01TRCO_MU01Tran_SHIFT)) & xpc_MU01TRCO_MU01Tran_MASK)
/*! @} */

/*! @name MU01ADCO - MU01_Addrbusy_Counter */
/*! @{ */

#define xpc_MU01ADCO_MU01Addr_MASK               (0xFFFFFFFFU)
#define xpc_MU01ADCO_MU01Addr_SHIFT              (0U)
/*! MU01Addr - MU01_Addrbusy */
#define xpc_MU01ADCO_MU01Addr(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU01ADCO_MU01Addr_SHIFT)) & xpc_MU01ADCO_MU01Addr_MASK)
/*! @} */

/*! @name MU01LACO - MU01_Latency_Counter */
/*! @{ */

#define xpc_MU01LACO_MU01Lat_MASK                (0xFFFFFFFFU)
#define xpc_MU01LACO_MU01Lat_SHIFT               (0U)
/*! MU01Lat - MU01_Latency */
#define xpc_MU01LACO_MU01Lat(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU01LACO_MU01Lat_SHIFT)) & xpc_MU01LACO_MU01Lat_MASK)
/*! @} */

/*! @name MU02SWIT - MU02_Switch */
/*! @{ */

#define xpc_MU02SWIT_MU02Sel_MASK                (0xFU)
#define xpc_MU02SWIT_MU02Sel_SHIFT               (0U)
/*! MU02Sel - MU02_Select
 *  0b0000..fetchlayer0 read direction (ACLK clock)
 *  0b0001..fetchlayer1 read direction (ACLK clock)
 *  0b0010..fetchyuv3 read direction (ACLK clock)
 *  0b0011..fetchyuv0 read direction (ACLK clock)
 *  0b0100..fetchyuv1 read direction (ACLK clock)
 *  0b0101..fetcheco0 read direction (ACLK clock)
 *  0b0110..fetcheco1 read direction (ACLK clock)
 *  0b0111..fetchdecode9 read direction (ACLK clock)
 *  0b1000..fetchrot9 read direction (ACLK clock)
 *  0b1001..fetcheco9 read direction (ACLK clock)
 *  0b1010..store9 write direction (ACLK clock)
 *  0b1011..cmdseq read direction (ACLK clock)
 *  0b1100..cmdseq write direction (ACLK clock)
 */
#define xpc_MU02SWIT_MU02Sel(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU02SWIT_MU02Sel_SHIFT)) & xpc_MU02SWIT_MU02Sel_MASK)
/*! @} */

/*! @name MU02DACO - MU02_Data_Counter */
/*! @{ */

#define xpc_MU02DACO_MU02Data_MASK               (0xFFFFFFFFU)
#define xpc_MU02DACO_MU02Data_SHIFT              (0U)
/*! MU02Data - MU02_Data */
#define xpc_MU02DACO_MU02Data(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU02DACO_MU02Data_SHIFT)) & xpc_MU02DACO_MU02Data_MASK)
/*! @} */

/*! @name MU02BUCO - MU02_Busy_Counter */
/*! @{ */

#define xpc_MU02BUCO_MU02Busy_MASK               (0xFFFFFFFFU)
#define xpc_MU02BUCO_MU02Busy_SHIFT              (0U)
/*! MU02Busy - MU02_Busy */
#define xpc_MU02BUCO_MU02Busy(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU02BUCO_MU02Busy_SHIFT)) & xpc_MU02BUCO_MU02Busy_MASK)
/*! @} */

/*! @name MU02TRCO - MU02_Transfer_Counter */
/*! @{ */

#define xpc_MU02TRCO_MU02Tran_MASK               (0xFFFFFFFFU)
#define xpc_MU02TRCO_MU02Tran_SHIFT              (0U)
/*! MU02Tran - MU02_Transfer */
#define xpc_MU02TRCO_MU02Tran(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU02TRCO_MU02Tran_SHIFT)) & xpc_MU02TRCO_MU02Tran_MASK)
/*! @} */

/*! @name MU02ADCO - MU02_Addrbusy_Counter */
/*! @{ */

#define xpc_MU02ADCO_MU02Addr_MASK               (0xFFFFFFFFU)
#define xpc_MU02ADCO_MU02Addr_SHIFT              (0U)
/*! MU02Addr - MU02_Addrbusy */
#define xpc_MU02ADCO_MU02Addr(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU02ADCO_MU02Addr_SHIFT)) & xpc_MU02ADCO_MU02Addr_MASK)
/*! @} */

/*! @name MU02LACO - MU02_Latency_Counter */
/*! @{ */

#define xpc_MU02LACO_MU02Lat_MASK                (0xFFFFFFFFU)
#define xpc_MU02LACO_MU02Lat_SHIFT               (0U)
/*! MU02Lat - MU02_Latency */
#define xpc_MU02LACO_MU02Lat(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU02LACO_MU02Lat_SHIFT)) & xpc_MU02LACO_MU02Lat_MASK)
/*! @} */

/*! @name MU03SWIT - MU03_Switch */
/*! @{ */

#define xpc_MU03SWIT_MU03Sel_MASK                (0xFU)
#define xpc_MU03SWIT_MU03Sel_SHIFT               (0U)
/*! MU03Sel - MU03_Select
 *  0b0000..fetchlayer0 read direction (ACLK clock)
 *  0b0001..fetchlayer1 read direction (ACLK clock)
 *  0b0010..fetchyuv3 read direction (ACLK clock)
 *  0b0011..fetchyuv0 read direction (ACLK clock)
 *  0b0100..fetchyuv1 read direction (ACLK clock)
 *  0b0101..fetcheco0 read direction (ACLK clock)
 *  0b0110..fetcheco1 read direction (ACLK clock)
 *  0b0111..fetchdecode9 read direction (ACLK clock)
 *  0b1000..fetchrot9 read direction (ACLK clock)
 *  0b1001..fetcheco9 read direction (ACLK clock)
 *  0b1010..store9 write direction (ACLK clock)
 *  0b1011..cmdseq read direction (ACLK clock)
 *  0b1100..cmdseq write direction (ACLK clock)
 */
#define xpc_MU03SWIT_MU03Sel(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU03SWIT_MU03Sel_SHIFT)) & xpc_MU03SWIT_MU03Sel_MASK)
/*! @} */

/*! @name MU03DACO - MU03_Data_Counter */
/*! @{ */

#define xpc_MU03DACO_MU03Data_MASK               (0xFFFFFFFFU)
#define xpc_MU03DACO_MU03Data_SHIFT              (0U)
/*! MU03Data - MU03_Data */
#define xpc_MU03DACO_MU03Data(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU03DACO_MU03Data_SHIFT)) & xpc_MU03DACO_MU03Data_MASK)
/*! @} */

/*! @name MU03BUOU - MU03_Busy_Counter */
/*! @{ */

#define xpc_MU03BUOU_MU03Busy_MASK               (0xFFFFFFFFU)
#define xpc_MU03BUOU_MU03Busy_SHIFT              (0U)
/*! MU03Busy - MU03_Busy */
#define xpc_MU03BUOU_MU03Busy(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU03BUOU_MU03Busy_SHIFT)) & xpc_MU03BUOU_MU03Busy_MASK)
/*! @} */

/*! @name MU03TRCO - MU03_Transfer_Counter */
/*! @{ */

#define xpc_MU03TRCO_MU03Tran_MASK               (0xFFFFFFFFU)
#define xpc_MU03TRCO_MU03Tran_SHIFT              (0U)
/*! MU03Tran - MU03_Transfer */
#define xpc_MU03TRCO_MU03Tran(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU03TRCO_MU03Tran_SHIFT)) & xpc_MU03TRCO_MU03Tran_MASK)
/*! @} */

/*! @name MU03ADCO - MU03_Addrbusy_Counter */
/*! @{ */

#define xpc_MU03ADCO_MU03Addr_MASK               (0xFFFFFFFFU)
#define xpc_MU03ADCO_MU03Addr_SHIFT              (0U)
/*! MU03Addr - MU03_Addrbusy */
#define xpc_MU03ADCO_MU03Addr(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU03ADCO_MU03Addr_SHIFT)) & xpc_MU03ADCO_MU03Addr_MASK)
/*! @} */

/*! @name MU03LACO - MU03_Latency_Counter */
/*! @{ */

#define xpc_MU03LACO_MU03Lat_MASK                (0xFFFFFFFFU)
#define xpc_MU03LACO_MU03Lat_SHIFT               (0U)
/*! MU03Lat - MU03_Latency */
#define xpc_MU03LACO_MU03Lat(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU03LACO_MU03Lat_SHIFT)) & xpc_MU03LACO_MU03Lat_MASK)
/*! @} */

/*! @name MU04SWIT - MU04_Switch */
/*! @{ */

#define xpc_MU04SWIT_MU04Sel_MASK                (0xFU)
#define xpc_MU04SWIT_MU04Sel_SHIFT               (0U)
/*! MU04Sel - MU04_Select
 *  0b0000..fetchlayer0 read direction (ACLK clock)
 *  0b0001..fetchlayer1 read direction (ACLK clock)
 *  0b0010..fetchyuv3 read direction (ACLK clock)
 *  0b0011..fetchyuv0 read direction (ACLK clock)
 *  0b0100..fetchyuv1 read direction (ACLK clock)
 *  0b0101..fetcheco0 read direction (ACLK clock)
 *  0b0110..fetcheco1 read direction (ACLK clock)
 *  0b0111..fetchdecode9 read direction (ACLK clock)
 *  0b1000..fetchrot9 read direction (ACLK clock)
 *  0b1001..fetcheco9 read direction (ACLK clock)
 *  0b1010..store9 write direction (ACLK clock)
 *  0b1011..cmdseq read direction (ACLK clock)
 *  0b1100..cmdseq write direction (ACLK clock)
 */
#define xpc_MU04SWIT_MU04Sel(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU04SWIT_MU04Sel_SHIFT)) & xpc_MU04SWIT_MU04Sel_MASK)
/*! @} */

/*! @name MU04DACO - MU04_Data_Counter */
/*! @{ */

#define xpc_MU04DACO_MU04Data_MASK               (0xFFFFFFFFU)
#define xpc_MU04DACO_MU04Data_SHIFT              (0U)
/*! MU04Data - MU04_Data */
#define xpc_MU04DACO_MU04Data(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU04DACO_MU04Data_SHIFT)) & xpc_MU04DACO_MU04Data_MASK)
/*! @} */

/*! @name MU04BUCO - MU04_Busy_Counter */
/*! @{ */

#define xpc_MU04BUCO_MU04Busy_MASK               (0xFFFFFFFFU)
#define xpc_MU04BUCO_MU04Busy_SHIFT              (0U)
/*! MU04Busy - MU04_Busy */
#define xpc_MU04BUCO_MU04Busy(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU04BUCO_MU04Busy_SHIFT)) & xpc_MU04BUCO_MU04Busy_MASK)
/*! @} */

/*! @name MU04TRCO - MU04_Transfer_Counter */
/*! @{ */

#define xpc_MU04TRCO_MU04Tran_MASK               (0xFFFFFFFFU)
#define xpc_MU04TRCO_MU04Tran_SHIFT              (0U)
/*! MU04Tran - MU04_Transfer */
#define xpc_MU04TRCO_MU04Tran(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU04TRCO_MU04Tran_SHIFT)) & xpc_MU04TRCO_MU04Tran_MASK)
/*! @} */

/*! @name MU04ADCO - MU04_Addrbusy_Counter */
/*! @{ */

#define xpc_MU04ADCO_MU04Addr_MASK               (0xFFFFFFFFU)
#define xpc_MU04ADCO_MU04Addr_SHIFT              (0U)
/*! MU04Addr - MU04_Addrbusy */
#define xpc_MU04ADCO_MU04Addr(x)                 (((uint32_t)(((uint32_t)(x)) << xpc_MU04ADCO_MU04Addr_SHIFT)) & xpc_MU04ADCO_MU04Addr_MASK)
/*! @} */

/*! @name MU04LACO - MU04_Latency_Counter */
/*! @{ */

#define xpc_MU04LACO_MU04Lat_MASK                (0xFFFFFFFFU)
#define xpc_MU04LACO_MU04Lat_SHIFT               (0U)
/*! MU04Lat - MU04_Latency */
#define xpc_MU04LACO_MU04Lat(x)                  (((uint32_t)(((uint32_t)(x)) << xpc_MU04LACO_MU04Lat_SHIFT)) & xpc_MU04LACO_MU04Lat_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group xpc_Register_Masks */


/*!
 * @}
 */ /* end of group xpc_Peripheral_Access_Layer */


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


#endif  /* PERI_XPC_H_ */

