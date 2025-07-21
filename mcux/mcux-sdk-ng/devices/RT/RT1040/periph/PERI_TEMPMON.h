/*
** ###################################################################
**     Processors:          MIMXRT1041DFP6B
**                          MIMXRT1041DJM6B
**                          MIMXRT1041XFP5B
**                          MIMXRT1041XJM5B
**                          MIMXRT1042DFP6B
**                          MIMXRT1042DJM6B
**                          MIMXRT1042XFP5B
**                          MIMXRT1042XJM5B
**                          MIMXRT1043DFP6B
**                          MIMXRT1043XFP5B
**                          MIMXRT1046DFQ6B
**                          MIMXRT1046XFQ5B
**
**     Version:             rev. 1.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for TEMPMON
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2021-07-20)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TEMPMON.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TEMPMON
 *
 * CMSIS Peripheral Access Layer for TEMPMON
 */

#if !defined(PERI_TEMPMON_H_)
#define PERI_TEMPMON_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1041DFP6B) || defined(CPU_MIMXRT1041DJM6B) || defined(CPU_MIMXRT1041XFP5B) || defined(CPU_MIMXRT1041XJM5B))
#include "MIMXRT1041_COMMON.h"
#elif (defined(CPU_MIMXRT1042DFP6B) || defined(CPU_MIMXRT1042DJM6B) || defined(CPU_MIMXRT1042XFP5B) || defined(CPU_MIMXRT1042XJM5B))
#include "MIMXRT1042_COMMON.h"
#elif (defined(CPU_MIMXRT1043DFP6B) || defined(CPU_MIMXRT1043XFP5B))
#include "MIMXRT1043_COMMON.h"
#elif (defined(CPU_MIMXRT1046DFQ6B) || defined(CPU_MIMXRT1046XFQ5B))
#include "MIMXRT1046_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- TEMPMON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPMON_Peripheral_Access_Layer TEMPMON Peripheral Access Layer
 * @{
 */

/** TEMPMON - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[384];
  __IO uint32_t TEMPSENSE0;                        /**< Tempsensor Control Register 0, offset: 0x180 */
  __IO uint32_t TEMPSENSE0_SET;                    /**< Tempsensor Control Register 0, offset: 0x184 */
  __IO uint32_t TEMPSENSE0_CLR;                    /**< Tempsensor Control Register 0, offset: 0x188 */
  __IO uint32_t TEMPSENSE0_TOG;                    /**< Tempsensor Control Register 0, offset: 0x18C */
  __IO uint32_t TEMPSENSE1;                        /**< Tempsensor Control Register 1, offset: 0x190 */
  __IO uint32_t TEMPSENSE1_SET;                    /**< Tempsensor Control Register 1, offset: 0x194 */
  __IO uint32_t TEMPSENSE1_CLR;                    /**< Tempsensor Control Register 1, offset: 0x198 */
  __IO uint32_t TEMPSENSE1_TOG;                    /**< Tempsensor Control Register 1, offset: 0x19C */
       uint8_t RESERVED_1[240];
  __IO uint32_t TEMPSENSE2;                        /**< Tempsensor Control Register 2, offset: 0x290 */
  __IO uint32_t TEMPSENSE2_SET;                    /**< Tempsensor Control Register 2, offset: 0x294 */
  __IO uint32_t TEMPSENSE2_CLR;                    /**< Tempsensor Control Register 2, offset: 0x298 */
  __IO uint32_t TEMPSENSE2_TOG;                    /**< Tempsensor Control Register 2, offset: 0x29C */
} TEMPMON_Type;

/* ----------------------------------------------------------------------------
   -- TEMPMON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TEMPMON_Register_Masks TEMPMON Register Masks
 * @{
 */

/*! @name TEMPSENSE0 - Tempsensor Control Register 0 */
/*! @{ */

#define TEMPMON_TEMPSENSE0_POWER_DOWN_MASK       (0x1U)
#define TEMPMON_TEMPSENSE0_POWER_DOWN_SHIFT      (0U)
/*! POWER_DOWN
 *  0b0..Enable power to the temperature sensor.
 *  0b1..Power down the temperature sensor.
 */
#define TEMPMON_TEMPSENSE0_POWER_DOWN(x)         (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_POWER_DOWN_SHIFT)) & TEMPMON_TEMPSENSE0_POWER_DOWN_MASK)

#define TEMPMON_TEMPSENSE0_MEASURE_TEMP_MASK     (0x2U)
#define TEMPMON_TEMPSENSE0_MEASURE_TEMP_SHIFT    (1U)
/*! MEASURE_TEMP
 *  0b0..Do not start the measurement process.
 *  0b1..Start the measurement process.
 */
#define TEMPMON_TEMPSENSE0_MEASURE_TEMP(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_MEASURE_TEMP_SHIFT)) & TEMPMON_TEMPSENSE0_MEASURE_TEMP_MASK)

#define TEMPMON_TEMPSENSE0_FINISHED_MASK         (0x4U)
#define TEMPMON_TEMPSENSE0_FINISHED_SHIFT        (2U)
/*! FINISHED
 *  0b0..Last measurement is not ready yet.
 *  0b1..Last measurement is valid.
 */
#define TEMPMON_TEMPSENSE0_FINISHED(x)           (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_FINISHED_SHIFT)) & TEMPMON_TEMPSENSE0_FINISHED_MASK)

#define TEMPMON_TEMPSENSE0_TEMP_CNT_MASK         (0xFFF00U)
#define TEMPMON_TEMPSENSE0_TEMP_CNT_SHIFT        (8U)
#define TEMPMON_TEMPSENSE0_TEMP_CNT(x)           (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TEMP_CNT_SHIFT)) & TEMPMON_TEMPSENSE0_TEMP_CNT_MASK)

#define TEMPMON_TEMPSENSE0_ALARM_VALUE_MASK      (0xFFF00000U)
#define TEMPMON_TEMPSENSE0_ALARM_VALUE_SHIFT     (20U)
#define TEMPMON_TEMPSENSE0_ALARM_VALUE(x)        (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE0_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE0_SET - Tempsensor Control Register 0 */
/*! @{ */

#define TEMPMON_TEMPSENSE0_SET_POWER_DOWN_MASK   (0x1U)
#define TEMPMON_TEMPSENSE0_SET_POWER_DOWN_SHIFT  (0U)
/*! POWER_DOWN
 *  0b0..Enable power to the temperature sensor.
 *  0b1..Power down the temperature sensor.
 */
#define TEMPMON_TEMPSENSE0_SET_POWER_DOWN(x)     (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_SET_POWER_DOWN_SHIFT)) & TEMPMON_TEMPSENSE0_SET_POWER_DOWN_MASK)

#define TEMPMON_TEMPSENSE0_SET_MEASURE_TEMP_MASK (0x2U)
#define TEMPMON_TEMPSENSE0_SET_MEASURE_TEMP_SHIFT (1U)
/*! MEASURE_TEMP
 *  0b0..Do not start the measurement process.
 *  0b1..Start the measurement process.
 */
#define TEMPMON_TEMPSENSE0_SET_MEASURE_TEMP(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_SET_MEASURE_TEMP_SHIFT)) & TEMPMON_TEMPSENSE0_SET_MEASURE_TEMP_MASK)

#define TEMPMON_TEMPSENSE0_SET_FINISHED_MASK     (0x4U)
#define TEMPMON_TEMPSENSE0_SET_FINISHED_SHIFT    (2U)
/*! FINISHED
 *  0b0..Last measurement is not ready yet.
 *  0b1..Last measurement is valid.
 */
#define TEMPMON_TEMPSENSE0_SET_FINISHED(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_SET_FINISHED_SHIFT)) & TEMPMON_TEMPSENSE0_SET_FINISHED_MASK)

#define TEMPMON_TEMPSENSE0_SET_TEMP_CNT_MASK     (0xFFF00U)
#define TEMPMON_TEMPSENSE0_SET_TEMP_CNT_SHIFT    (8U)
#define TEMPMON_TEMPSENSE0_SET_TEMP_CNT(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_SET_TEMP_CNT_SHIFT)) & TEMPMON_TEMPSENSE0_SET_TEMP_CNT_MASK)

#define TEMPMON_TEMPSENSE0_SET_ALARM_VALUE_MASK  (0xFFF00000U)
#define TEMPMON_TEMPSENSE0_SET_ALARM_VALUE_SHIFT (20U)
#define TEMPMON_TEMPSENSE0_SET_ALARM_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_SET_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE0_SET_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE0_CLR - Tempsensor Control Register 0 */
/*! @{ */

#define TEMPMON_TEMPSENSE0_CLR_POWER_DOWN_MASK   (0x1U)
#define TEMPMON_TEMPSENSE0_CLR_POWER_DOWN_SHIFT  (0U)
/*! POWER_DOWN
 *  0b0..Enable power to the temperature sensor.
 *  0b1..Power down the temperature sensor.
 */
#define TEMPMON_TEMPSENSE0_CLR_POWER_DOWN(x)     (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_CLR_POWER_DOWN_SHIFT)) & TEMPMON_TEMPSENSE0_CLR_POWER_DOWN_MASK)

#define TEMPMON_TEMPSENSE0_CLR_MEASURE_TEMP_MASK (0x2U)
#define TEMPMON_TEMPSENSE0_CLR_MEASURE_TEMP_SHIFT (1U)
/*! MEASURE_TEMP
 *  0b0..Do not start the measurement process.
 *  0b1..Start the measurement process.
 */
#define TEMPMON_TEMPSENSE0_CLR_MEASURE_TEMP(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_CLR_MEASURE_TEMP_SHIFT)) & TEMPMON_TEMPSENSE0_CLR_MEASURE_TEMP_MASK)

#define TEMPMON_TEMPSENSE0_CLR_FINISHED_MASK     (0x4U)
#define TEMPMON_TEMPSENSE0_CLR_FINISHED_SHIFT    (2U)
/*! FINISHED
 *  0b0..Last measurement is not ready yet.
 *  0b1..Last measurement is valid.
 */
#define TEMPMON_TEMPSENSE0_CLR_FINISHED(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_CLR_FINISHED_SHIFT)) & TEMPMON_TEMPSENSE0_CLR_FINISHED_MASK)

#define TEMPMON_TEMPSENSE0_CLR_TEMP_CNT_MASK     (0xFFF00U)
#define TEMPMON_TEMPSENSE0_CLR_TEMP_CNT_SHIFT    (8U)
#define TEMPMON_TEMPSENSE0_CLR_TEMP_CNT(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_CLR_TEMP_CNT_SHIFT)) & TEMPMON_TEMPSENSE0_CLR_TEMP_CNT_MASK)

#define TEMPMON_TEMPSENSE0_CLR_ALARM_VALUE_MASK  (0xFFF00000U)
#define TEMPMON_TEMPSENSE0_CLR_ALARM_VALUE_SHIFT (20U)
#define TEMPMON_TEMPSENSE0_CLR_ALARM_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_CLR_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE0_CLR_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE0_TOG - Tempsensor Control Register 0 */
/*! @{ */

#define TEMPMON_TEMPSENSE0_TOG_POWER_DOWN_MASK   (0x1U)
#define TEMPMON_TEMPSENSE0_TOG_POWER_DOWN_SHIFT  (0U)
/*! POWER_DOWN
 *  0b0..Enable power to the temperature sensor.
 *  0b1..Power down the temperature sensor.
 */
#define TEMPMON_TEMPSENSE0_TOG_POWER_DOWN(x)     (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TOG_POWER_DOWN_SHIFT)) & TEMPMON_TEMPSENSE0_TOG_POWER_DOWN_MASK)

#define TEMPMON_TEMPSENSE0_TOG_MEASURE_TEMP_MASK (0x2U)
#define TEMPMON_TEMPSENSE0_TOG_MEASURE_TEMP_SHIFT (1U)
/*! MEASURE_TEMP
 *  0b0..Do not start the measurement process.
 *  0b1..Start the measurement process.
 */
#define TEMPMON_TEMPSENSE0_TOG_MEASURE_TEMP(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TOG_MEASURE_TEMP_SHIFT)) & TEMPMON_TEMPSENSE0_TOG_MEASURE_TEMP_MASK)

#define TEMPMON_TEMPSENSE0_TOG_FINISHED_MASK     (0x4U)
#define TEMPMON_TEMPSENSE0_TOG_FINISHED_SHIFT    (2U)
/*! FINISHED
 *  0b0..Last measurement is not ready yet.
 *  0b1..Last measurement is valid.
 */
#define TEMPMON_TEMPSENSE0_TOG_FINISHED(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TOG_FINISHED_SHIFT)) & TEMPMON_TEMPSENSE0_TOG_FINISHED_MASK)

#define TEMPMON_TEMPSENSE0_TOG_TEMP_CNT_MASK     (0xFFF00U)
#define TEMPMON_TEMPSENSE0_TOG_TEMP_CNT_SHIFT    (8U)
#define TEMPMON_TEMPSENSE0_TOG_TEMP_CNT(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TOG_TEMP_CNT_SHIFT)) & TEMPMON_TEMPSENSE0_TOG_TEMP_CNT_MASK)

#define TEMPMON_TEMPSENSE0_TOG_ALARM_VALUE_MASK  (0xFFF00000U)
#define TEMPMON_TEMPSENSE0_TOG_ALARM_VALUE_SHIFT (20U)
#define TEMPMON_TEMPSENSE0_TOG_ALARM_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE0_TOG_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE0_TOG_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE1 - Tempsensor Control Register 1 */
/*! @{ */

#define TEMPMON_TEMPSENSE1_MEASURE_FREQ_MASK     (0xFFFFU)
#define TEMPMON_TEMPSENSE1_MEASURE_FREQ_SHIFT    (0U)
/*! MEASURE_FREQ
 *  0b0000000000000000..Defines a single measurement with no repeat.
 *  0b0000000000000001..Updates the temperature value at a RTC clock rate.
 *  0b0000000000000010..Updates the temperature value at a RTC/2 clock rate.
 *  0b1111111111111111..Determines a two second sample period with a 32.768KHz RTC clock. Exact timings depend on the accuracy of the RTC clock.
 */
#define TEMPMON_TEMPSENSE1_MEASURE_FREQ(x)       (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE1_MEASURE_FREQ_SHIFT)) & TEMPMON_TEMPSENSE1_MEASURE_FREQ_MASK)
/*! @} */

/*! @name TEMPSENSE1_SET - Tempsensor Control Register 1 */
/*! @{ */

#define TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ_MASK (0xFFFFU)
#define TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ_SHIFT (0U)
/*! MEASURE_FREQ
 *  0b0000000000000000..Defines a single measurement with no repeat.
 *  0b0000000000000001..Updates the temperature value at a RTC clock rate.
 *  0b0000000000000010..Updates the temperature value at a RTC/2 clock rate.
 *  0b1111111111111111..Determines a two second sample period with a 32.768KHz RTC clock. Exact timings depend on the accuracy of the RTC clock.
 */
#define TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ_SHIFT)) & TEMPMON_TEMPSENSE1_SET_MEASURE_FREQ_MASK)
/*! @} */

/*! @name TEMPSENSE1_CLR - Tempsensor Control Register 1 */
/*! @{ */

#define TEMPMON_TEMPSENSE1_CLR_MEASURE_FREQ_MASK (0xFFFFU)
#define TEMPMON_TEMPSENSE1_CLR_MEASURE_FREQ_SHIFT (0U)
/*! MEASURE_FREQ
 *  0b0000000000000000..Defines a single measurement with no repeat.
 *  0b0000000000000001..Updates the temperature value at a RTC clock rate.
 *  0b0000000000000010..Updates the temperature value at a RTC/2 clock rate.
 *  0b1111111111111111..Determines a two second sample period with a 32.768KHz RTC clock. Exact timings depend on the accuracy of the RTC clock.
 */
#define TEMPMON_TEMPSENSE1_CLR_MEASURE_FREQ(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE1_CLR_MEASURE_FREQ_SHIFT)) & TEMPMON_TEMPSENSE1_CLR_MEASURE_FREQ_MASK)
/*! @} */

/*! @name TEMPSENSE1_TOG - Tempsensor Control Register 1 */
/*! @{ */

#define TEMPMON_TEMPSENSE1_TOG_MEASURE_FREQ_MASK (0xFFFFU)
#define TEMPMON_TEMPSENSE1_TOG_MEASURE_FREQ_SHIFT (0U)
/*! MEASURE_FREQ
 *  0b0000000000000000..Defines a single measurement with no repeat.
 *  0b0000000000000001..Updates the temperature value at a RTC clock rate.
 *  0b0000000000000010..Updates the temperature value at a RTC/2 clock rate.
 *  0b1111111111111111..Determines a two second sample period with a 32.768KHz RTC clock. Exact timings depend on the accuracy of the RTC clock.
 */
#define TEMPMON_TEMPSENSE1_TOG_MEASURE_FREQ(x)   (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE1_TOG_MEASURE_FREQ_SHIFT)) & TEMPMON_TEMPSENSE1_TOG_MEASURE_FREQ_MASK)
/*! @} */

/*! @name TEMPSENSE2 - Tempsensor Control Register 2 */
/*! @{ */

#define TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE_MASK  (0xFFFU)
#define TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE_SHIFT (0U)
#define TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE(x)    (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_LOW_ALARM_VALUE_MASK)

#define TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE_MASK (0xFFF0000U)
#define TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE_SHIFT (16U)
#define TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE(x)  (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_PANIC_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE2_SET - Tempsensor Control Register 2 */
/*! @{ */

#define TEMPMON_TEMPSENSE2_SET_LOW_ALARM_VALUE_MASK (0xFFFU)
#define TEMPMON_TEMPSENSE2_SET_LOW_ALARM_VALUE_SHIFT (0U)
#define TEMPMON_TEMPSENSE2_SET_LOW_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_SET_LOW_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_SET_LOW_ALARM_VALUE_MASK)

#define TEMPMON_TEMPSENSE2_SET_PANIC_ALARM_VALUE_MASK (0xFFF0000U)
#define TEMPMON_TEMPSENSE2_SET_PANIC_ALARM_VALUE_SHIFT (16U)
#define TEMPMON_TEMPSENSE2_SET_PANIC_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_SET_PANIC_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_SET_PANIC_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE2_CLR - Tempsensor Control Register 2 */
/*! @{ */

#define TEMPMON_TEMPSENSE2_CLR_LOW_ALARM_VALUE_MASK (0xFFFU)
#define TEMPMON_TEMPSENSE2_CLR_LOW_ALARM_VALUE_SHIFT (0U)
#define TEMPMON_TEMPSENSE2_CLR_LOW_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_CLR_LOW_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_CLR_LOW_ALARM_VALUE_MASK)

#define TEMPMON_TEMPSENSE2_CLR_PANIC_ALARM_VALUE_MASK (0xFFF0000U)
#define TEMPMON_TEMPSENSE2_CLR_PANIC_ALARM_VALUE_SHIFT (16U)
#define TEMPMON_TEMPSENSE2_CLR_PANIC_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_CLR_PANIC_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_CLR_PANIC_ALARM_VALUE_MASK)
/*! @} */

/*! @name TEMPSENSE2_TOG - Tempsensor Control Register 2 */
/*! @{ */

#define TEMPMON_TEMPSENSE2_TOG_LOW_ALARM_VALUE_MASK (0xFFFU)
#define TEMPMON_TEMPSENSE2_TOG_LOW_ALARM_VALUE_SHIFT (0U)
#define TEMPMON_TEMPSENSE2_TOG_LOW_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_TOG_LOW_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_TOG_LOW_ALARM_VALUE_MASK)

#define TEMPMON_TEMPSENSE2_TOG_PANIC_ALARM_VALUE_MASK (0xFFF0000U)
#define TEMPMON_TEMPSENSE2_TOG_PANIC_ALARM_VALUE_SHIFT (16U)
#define TEMPMON_TEMPSENSE2_TOG_PANIC_ALARM_VALUE(x) (((uint32_t)(((uint32_t)(x)) << TEMPMON_TEMPSENSE2_TOG_PANIC_ALARM_VALUE_SHIFT)) & TEMPMON_TEMPSENSE2_TOG_PANIC_ALARM_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TEMPMON_Register_Masks */


/*!
 * @}
 */ /* end of group TEMPMON_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_TEMPMON_H_ */

