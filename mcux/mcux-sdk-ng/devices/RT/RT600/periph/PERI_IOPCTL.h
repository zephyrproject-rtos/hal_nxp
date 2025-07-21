/*
** ###################################################################
**     Processors:          MIMXRT633SFAWBR
**                          MIMXRT633SFFOB
**                          MIMXRT633SFVKB
**                          MIMXRT685SFAWBR_cm33
**                          MIMXRT685SFAWBR_dsp
**                          MIMXRT685SFFOB_cm33
**                          MIMXRT685SFFOB_dsp
**                          MIMXRT685SFVKB_cm33
**                          MIMXRT685SFVKB_dsp
**                          MIMXRT685SVFVKB_cm33
**                          MIMXRT685SVFVKB_dsp
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for IOPCTL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-06-19)
**         Initial version.
**     - rev. 2.0 (2019-11-12)
**         Base on rev 0.95 RM (B0 Header)
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_IOPCTL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for IOPCTL
 *
 * CMSIS Peripheral Access Layer for IOPCTL
 */

#if !defined(PERI_IOPCTL_H_)
#define PERI_IOPCTL_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT633SFAWBR) || defined(CPU_MIMXRT633SFFOB) || defined(CPU_MIMXRT633SFVKB))
#include "MIMXRT633S_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_cm33) || defined(CPU_MIMXRT685SFFOB_cm33) || defined(CPU_MIMXRT685SFVKB_cm33) || defined(CPU_MIMXRT685SVFVKB_cm33))
#include "MIMXRT685S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT685SFAWBR_dsp) || defined(CPU_MIMXRT685SFFOB_dsp) || defined(CPU_MIMXRT685SFVKB_dsp) || defined(CPU_MIMXRT685SVFVKB_dsp))
#include "MIMXRT685S_dsp_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- IOPCTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL_Peripheral_Access_Layer IOPCTL Peripheral Access Layer
 * @{
 */

/** IOPCTL - Size of Registers Arrays */
#define IOPCTL_PIO_COUNT                          8u
#define IOPCTL_PIO_PIO_COUNT                      32u

/** IOPCTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t PIO[IOPCTL_PIO_COUNT][IOPCTL_PIO_PIO_COUNT]; /**< iop pad control register for port0 to port5, array offset: 0x0, array step: index*0x80, index2*0x4 */
  __IO uint32_t FC15_I2C_SCL;                      /**< Special Registers (No GPIO Function), offset: 0x400 */
  __IO uint32_t FC15_I2C_SDA;                      /**< Special Registers (No GPIO Function), offset: 0x404 */
} IOPCTL_Type;

/* ----------------------------------------------------------------------------
   -- IOPCTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IOPCTL_Register_Masks IOPCTL Register Masks
 * @{
 */

/*! @name PIO - iop pad control register for port0 to port5 */
/*! @{ */

#define IOPCTL_PIO_FSEL_MASK                     (0xFU)
#define IOPCTL_PIO_FSEL_SHIFT                    (0U)
/*! FSEL - Function Selector. . .(FSELs Sources can be found in the next several pages.)
 *  0b0000..Function 0.
 *  0b0001..Function 1.
 *  0b0010..Function 2.
 *  0b0011..Function 3.
 *  0b0100..Function 4.
 *  0b0101..Function 5.
 *  0b0110..Function 6.
 *  0b0111..Function 7.
 *  0b1000..Function 8.
 *  0b1001..Function 9.
 *  0b1010..Function 10.
 *  0b1011..Function 11.
 *  0b1100..Function 12.
 *  0b1101..Function 13.
 *  0b1110..Function 14.
 *  0b1111..Function 15.
 */
#define IOPCTL_PIO_FSEL(x)                       (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_FSEL_SHIFT)) & IOPCTL_PIO_FSEL_MASK)

#define IOPCTL_PIO_PUPDENA_MASK                  (0x10U)
#define IOPCTL_PIO_PUPDENA_SHIFT                 (4U)
/*! PUPDENA - Pullup / Pulldown Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_PIO_PUPDENA(x)                    (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_PUPDENA_SHIFT)) & IOPCTL_PIO_PUPDENA_MASK)

#define IOPCTL_PIO_PUPDSEL_MASK                  (0x20U)
#define IOPCTL_PIO_PUPDSEL_SHIFT                 (5U)
/*! PUPDSEL - Pullup or Pulldown Selector. . .
 *  0b0..Pull-down.
 *  0b1..Pull-up.
 */
#define IOPCTL_PIO_PUPDSEL(x)                    (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_PUPDSEL_SHIFT)) & IOPCTL_PIO_PUPDSEL_MASK)

#define IOPCTL_PIO_IBENA_MASK                    (0x40U)
#define IOPCTL_PIO_IBENA_SHIFT                   (6U)
/*! IBENA - Input Buffer Enable. .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_PIO_IBENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_IBENA_SHIFT)) & IOPCTL_PIO_IBENA_MASK)

#define IOPCTL_PIO_SLEWRATE_MASK                 (0x80U)
#define IOPCTL_PIO_SLEWRATE_SHIFT                (7U)
/*! SLEWRATE - Slew Rate Control. . .
 *  0b0..Slew Rate is Normal.
 *  0b1..Slew Rate Slow.
 */
#define IOPCTL_PIO_SLEWRATE(x)                   (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_SLEWRATE_SHIFT)) & IOPCTL_PIO_SLEWRATE_MASK)

#define IOPCTL_PIO_FULLDRIVE_MASK                (0x100U)
#define IOPCTL_PIO_FULLDRIVE_SHIFT               (8U)
/*! FULLDRIVE - Drive Selector. . .
 *  0b0..Normal Drive.
 *  0b1..Full Drive.
 */
#define IOPCTL_PIO_FULLDRIVE(x)                  (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_FULLDRIVE_SHIFT)) & IOPCTL_PIO_FULLDRIVE_MASK)

#define IOPCTL_PIO_AMENA_MASK                    (0x200U)
#define IOPCTL_PIO_AMENA_SHIFT                   (9U)
/*! AMENA - Analog Mux Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_PIO_AMENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_AMENA_SHIFT)) & IOPCTL_PIO_AMENA_MASK)

#define IOPCTL_PIO_ODENA_MASK                    (0x400U)
#define IOPCTL_PIO_ODENA_SHIFT                   (10U)
/*! ODENA - Pseudo Output Drain Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_PIO_ODENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_ODENA_SHIFT)) & IOPCTL_PIO_ODENA_MASK)

#define IOPCTL_PIO_IIENA_MASK                    (0x800U)
#define IOPCTL_PIO_IIENA_SHIFT                   (11U)
/*! IIENA - Input Invert Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_PIO_IIENA(x)                      (((uint32_t)(((uint32_t)(x)) << IOPCTL_PIO_IIENA_SHIFT)) & IOPCTL_PIO_IIENA_MASK)
/*! @} */

/* The count of IOPCTL_PIO */
#define IOPCTL_PIO_COUNT2                        (32U)

/*! @name FC15_I2C_SCL - Special Registers (No GPIO Function) */
/*! @{ */

#define IOPCTL_FC15_I2C_SCL_FSEL_MASK            (0xFU)
#define IOPCTL_FC15_I2C_SCL_FSEL_SHIFT           (0U)
/*! FSEL - Function Selector. . .(FSELs Sources can be found in the next several pages.)
 *  0b0000..Function 0.
 *  0b0001..Function 1.
 *  0b0010..Function 2.
 *  0b0011..Function 3.
 *  0b0100..Function 4.
 *  0b0101..Function 5.
 *  0b0110..Function 6.
 *  0b0111..Function 7.
 *  0b1000..Function 8.
 *  0b1001..Function 9.
 *  0b1010..Function 10.
 *  0b1011..Function 11.
 *  0b1100..Function 12.
 *  0b1101..Function 13.
 *  0b1110..Function 14.
 *  0b1111..Function 15.
 */
#define IOPCTL_FC15_I2C_SCL_FSEL(x)              (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_FSEL_SHIFT)) & IOPCTL_FC15_I2C_SCL_FSEL_MASK)

#define IOPCTL_FC15_I2C_SCL_PUPDENA_MASK         (0x10U)
#define IOPCTL_FC15_I2C_SCL_PUPDENA_SHIFT        (4U)
/*! PUPDENA - Pullup / Pulldown Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SCL_PUPDENA(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_PUPDENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_PUPDENA_MASK)

#define IOPCTL_FC15_I2C_SCL_PUPDSEL_MASK         (0x20U)
#define IOPCTL_FC15_I2C_SCL_PUPDSEL_SHIFT        (5U)
/*! PUPDSEL - Pullup or Pulldown Selector. . .
 *  0b0..Pull-down.
 *  0b1..Pull-up.
 */
#define IOPCTL_FC15_I2C_SCL_PUPDSEL(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_PUPDSEL_SHIFT)) & IOPCTL_FC15_I2C_SCL_PUPDSEL_MASK)

#define IOPCTL_FC15_I2C_SCL_IBENA_MASK           (0x40U)
#define IOPCTL_FC15_I2C_SCL_IBENA_SHIFT          (6U)
/*! IBENA - Input Buffer Enable. .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SCL_IBENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_IBENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_IBENA_MASK)

#define IOPCTL_FC15_I2C_SCL_SLEWRATE_MASK        (0x80U)
#define IOPCTL_FC15_I2C_SCL_SLEWRATE_SHIFT       (7U)
/*! SLEWRATE - Slew Rate Control. . .
 *  0b0..Slew Rate is Normal.
 *  0b1..Slew Rate Slow.
 */
#define IOPCTL_FC15_I2C_SCL_SLEWRATE(x)          (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_SLEWRATE_SHIFT)) & IOPCTL_FC15_I2C_SCL_SLEWRATE_MASK)

#define IOPCTL_FC15_I2C_SCL_FULLDRIVE_MASK       (0x100U)
#define IOPCTL_FC15_I2C_SCL_FULLDRIVE_SHIFT      (8U)
/*! FULLDRIVE - Drive Selector. . .
 *  0b0..Normal Drive.
 *  0b1..Full Drive.
 */
#define IOPCTL_FC15_I2C_SCL_FULLDRIVE(x)         (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_FULLDRIVE_SHIFT)) & IOPCTL_FC15_I2C_SCL_FULLDRIVE_MASK)

#define IOPCTL_FC15_I2C_SCL_AMENA_MASK           (0x200U)
#define IOPCTL_FC15_I2C_SCL_AMENA_SHIFT          (9U)
/*! AMENA - Analog Mux Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SCL_AMENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_AMENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_AMENA_MASK)

#define IOPCTL_FC15_I2C_SCL_ODENA_MASK           (0x400U)
#define IOPCTL_FC15_I2C_SCL_ODENA_SHIFT          (10U)
/*! ODENA - Pseudo Output Drain Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SCL_ODENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_ODENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_ODENA_MASK)

#define IOPCTL_FC15_I2C_SCL_IIENA_MASK           (0x800U)
#define IOPCTL_FC15_I2C_SCL_IIENA_SHIFT          (11U)
/*! IIENA - Input Invert Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SCL_IIENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SCL_IIENA_SHIFT)) & IOPCTL_FC15_I2C_SCL_IIENA_MASK)
/*! @} */

/*! @name FC15_I2C_SDA - Special Registers (No GPIO Function) */
/*! @{ */

#define IOPCTL_FC15_I2C_SDA_FSEL_MASK            (0xFU)
#define IOPCTL_FC15_I2C_SDA_FSEL_SHIFT           (0U)
/*! FSEL - Function Selector. . .(FSELs Sources can be found in the next several pages.)
 *  0b0000..Function 0.
 *  0b0001..Function 1.
 *  0b0010..Function 2.
 *  0b0011..Function 3.
 *  0b0100..Function 4.
 *  0b0101..Function 5.
 *  0b0110..Function 6.
 *  0b0111..Function 7.
 *  0b1000..Function 8.
 *  0b1001..Function 9.
 *  0b1010..Function 10.
 *  0b1011..Function 11.
 *  0b1100..Function 12.
 *  0b1101..Function 13.
 *  0b1110..Function 14.
 *  0b1111..Function 15.
 */
#define IOPCTL_FC15_I2C_SDA_FSEL(x)              (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_FSEL_SHIFT)) & IOPCTL_FC15_I2C_SDA_FSEL_MASK)

#define IOPCTL_FC15_I2C_SDA_PUPDENA_MASK         (0x10U)
#define IOPCTL_FC15_I2C_SDA_PUPDENA_SHIFT        (4U)
/*! PUPDENA - Pullup / Pulldown Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SDA_PUPDENA(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_PUPDENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_PUPDENA_MASK)

#define IOPCTL_FC15_I2C_SDA_PUPDSEL_MASK         (0x20U)
#define IOPCTL_FC15_I2C_SDA_PUPDSEL_SHIFT        (5U)
/*! PUPDSEL - Pullup or Pulldown Selector. . .
 *  0b0..Pull-down.
 *  0b1..Pull-up.
 */
#define IOPCTL_FC15_I2C_SDA_PUPDSEL(x)           (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_PUPDSEL_SHIFT)) & IOPCTL_FC15_I2C_SDA_PUPDSEL_MASK)

#define IOPCTL_FC15_I2C_SDA_IBENA_MASK           (0x40U)
#define IOPCTL_FC15_I2C_SDA_IBENA_SHIFT          (6U)
/*! IBENA - Input Buffer Enable. .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SDA_IBENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_IBENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_IBENA_MASK)

#define IOPCTL_FC15_I2C_SDA_SLEWRATE_MASK        (0x80U)
#define IOPCTL_FC15_I2C_SDA_SLEWRATE_SHIFT       (7U)
/*! SLEWRATE - Slew Rate Control. . .
 *  0b0..Slew Rate is Normal.
 *  0b1..Slew Rate Slow.
 */
#define IOPCTL_FC15_I2C_SDA_SLEWRATE(x)          (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_SLEWRATE_SHIFT)) & IOPCTL_FC15_I2C_SDA_SLEWRATE_MASK)

#define IOPCTL_FC15_I2C_SDA_FULLDRIVE_MASK       (0x100U)
#define IOPCTL_FC15_I2C_SDA_FULLDRIVE_SHIFT      (8U)
/*! FULLDRIVE - Drive Selector. . .
 *  0b0..Normal Drive.
 *  0b1..Full Drive.
 */
#define IOPCTL_FC15_I2C_SDA_FULLDRIVE(x)         (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_FULLDRIVE_SHIFT)) & IOPCTL_FC15_I2C_SDA_FULLDRIVE_MASK)

#define IOPCTL_FC15_I2C_SDA_AMENA_MASK           (0x200U)
#define IOPCTL_FC15_I2C_SDA_AMENA_SHIFT          (9U)
/*! AMENA - Analog Mux Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SDA_AMENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_AMENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_AMENA_MASK)

#define IOPCTL_FC15_I2C_SDA_ODENA_MASK           (0x400U)
#define IOPCTL_FC15_I2C_SDA_ODENA_SHIFT          (10U)
/*! ODENA - Pseudo Output Drain Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SDA_ODENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_ODENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_ODENA_MASK)

#define IOPCTL_FC15_I2C_SDA_IIENA_MASK           (0x800U)
#define IOPCTL_FC15_I2C_SDA_IIENA_SHIFT          (11U)
/*! IIENA - Input Invert Enable. . .
 *  0b0..Disable.
 *  0b1..Enable.
 */
#define IOPCTL_FC15_I2C_SDA_IIENA(x)             (((uint32_t)(((uint32_t)(x)) << IOPCTL_FC15_I2C_SDA_IIENA_SHIFT)) & IOPCTL_FC15_I2C_SDA_IIENA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group IOPCTL_Register_Masks */


/*!
 * @}
 */ /* end of group IOPCTL_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_IOPCTL_H_ */

