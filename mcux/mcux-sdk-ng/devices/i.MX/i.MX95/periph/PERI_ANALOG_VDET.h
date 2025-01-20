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
**         CMSIS Peripheral Access Layer for ANALOG_VDET
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
 * @file ANALOG_VDET.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ANALOG_VDET
 *
 * CMSIS Peripheral Access Layer for ANALOG_VDET
 */

#if !defined(ANALOG_VDET_H_)
#define ANALOG_VDET_H_                           /**< Symbol preventing repeated inclusion */

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
   -- ANALOG_VDET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_VDET_Peripheral_Access_Layer ANALOG_VDET Peripheral Access Layer
 * @{
 */

/** ANALOG_VDET - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[528];
  __I  uint32_t TRIM;                              /**< Trim Control, offset: 0x210 */
} ANALOG_VDET_Type;

/* ----------------------------------------------------------------------------
   -- ANALOG_VDET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANALOG_VDET_Register_Masks ANALOG_VDET Register Masks
 * @{
 */

/*! @name TRIM - Trim Control */
/*! @{ */

#define ANALOG_VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_MASK (0x1FU)
#define ANALOG_VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_SHIFT (0U)
/*! CORE_HVD_TRIM_CTRL_LV - Core HVD Threshold Value */
#define ANALOG_VDET_TRIM_CORE_HVD_TRIM_CTRL_LV(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_SHIFT)) & ANALOG_VDET_TRIM_CORE_HVD_TRIM_CTRL_LV_MASK)

#define ANALOG_VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_MASK (0x1F00U)
#define ANALOG_VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_SHIFT (8U)
/*! CORE_LVD_TRIM_CTRL_LV - Core LVD Threshold Value */
#define ANALOG_VDET_TRIM_CORE_LVD_TRIM_CTRL_LV(x) (((uint32_t)(((uint32_t)(x)) << ANALOG_VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_SHIFT)) & ANALOG_VDET_TRIM_CORE_LVD_TRIM_CTRL_LV_MASK)

#define ANALOG_VDET_TRIM_HV_LVD_TRIM_CTRL_LV_MASK (0x1F0000U)
#define ANALOG_VDET_TRIM_HV_LVD_TRIM_CTRL_LV_SHIFT (16U)
/*! HV_LVD_TRIM_CTRL_LV - Core HV LVD Threshold Value */
#define ANALOG_VDET_TRIM_HV_LVD_TRIM_CTRL_LV(x)  (((uint32_t)(((uint32_t)(x)) << ANALOG_VDET_TRIM_HV_LVD_TRIM_CTRL_LV_SHIFT)) & ANALOG_VDET_TRIM_HV_LVD_TRIM_CTRL_LV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANALOG_VDET_Register_Masks */


/*!
 * @}
 */ /* end of group ANALOG_VDET_Peripheral_Access_Layer */


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


#endif  /* ANALOG_VDET_H_ */

