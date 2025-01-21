/*
** ###################################################################
**     Processors:          LPC802M001JDH16
**                          LPC802M001JDH20
**                          LPC802M001JHI33
**                          LPC802M011JDH20
**                          LPC802UK
**
**     Version:             rev. 1.0, 2018-01-09
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-01-09)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file GPIO.h
 * @version 1.0
 * @date 2018-01-09
 * @brief CMSIS Peripheral Access Layer for GPIO
 *
 * CMSIS Peripheral Access Layer for GPIO
 */

#if !defined(GPIO_H_)
#define GPIO_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC802M001JDH16) || defined(CPU_LPC802M001JDH20) || defined(CPU_LPC802M001JHI33) || defined(CPU_LPC802M011JDH20) || defined(CPU_LPC802UK))
#include "LPC802_COMMON.h"
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
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Size of Registers Arrays */
#define GPIO_B_COUNT                              2u
#define GPIO_B_B_COUNT                            32u
#define GPIO_W_COUNT                              2u
#define GPIO_W_W_COUNT                            32u
#define GPIO_DIR_COUNT                            1u
#define GPIO_MASK_COUNT                           1u
#define GPIO_PIN_COUNT                            1u
#define GPIO_MPIN_COUNT                           1u
#define GPIO_SET_COUNT                            1u
#define GPIO_CLR_COUNT                            1u
#define GPIO_NOT_COUNT                            1u
#define GPIO_DIRSET_COUNT                         1u
#define GPIO_DIRCLR_COUNT                         1u
#define GPIO_DIRNOT_COUNT                         1u

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint8_t B[GPIO_B_COUNT][GPIO_B_B_COUNT];    /**< Byte pin registers for all port 0 and 1 GPIO pins, array offset: 0x0, array step: index*0x20, index2*0x1, valid indices: [0][0-31], [1][0-21] */
       uint8_t RESERVED_0[4032];
  __IO uint32_t W[GPIO_W_COUNT][GPIO_W_W_COUNT];   /**< Word pin registers for all port 0 and 1 GPIO pins, array offset: 0x1000, array step: index*0x80, index2*0x4, valid indices: [0][0-31], [1][0-21] */
       uint8_t RESERVED_1[3840];
  __IO uint32_t DIR[GPIO_DIR_COUNT];               /**< Direction registers, array offset: 0x2000, array step: 0x4 */
       uint8_t RESERVED_2[124];
  __IO uint32_t MASK[GPIO_MASK_COUNT];             /**< Mask register, array offset: 0x2080, array step: 0x4 */
       uint8_t RESERVED_3[124];
  __IO uint32_t PIN[GPIO_PIN_COUNT];               /**< Port pin register, array offset: 0x2100, array step: 0x4 */
       uint8_t RESERVED_4[124];
  __IO uint32_t MPIN[GPIO_MPIN_COUNT];             /**< Masked port register, array offset: 0x2180, array step: 0x4 */
       uint8_t RESERVED_5[124];
  __IO uint32_t SET[GPIO_SET_COUNT];               /**< Write: Set register for port Read: output bits for port, array offset: 0x2200, array step: 0x4 */
       uint8_t RESERVED_6[124];
  __O  uint32_t CLR[GPIO_CLR_COUNT];               /**< Clear port, array offset: 0x2280, array step: 0x4 */
       uint8_t RESERVED_7[124];
  __O  uint32_t NOT[GPIO_NOT_COUNT];               /**< Toggle port, array offset: 0x2300, array step: 0x4 */
       uint8_t RESERVED_8[124];
  __O  uint32_t DIRSET[GPIO_DIRSET_COUNT];         /**< Set pin direction bits for port, array offset: 0x2380, array step: 0x4 */
       uint8_t RESERVED_9[124];
  __O  uint32_t DIRCLR[GPIO_DIRCLR_COUNT];         /**< Clear pin direction bits for port, array offset: 0x2400, array step: 0x4 */
       uint8_t RESERVED_10[124];
  __O  uint32_t DIRNOT[GPIO_DIRNOT_COUNT];         /**< Toggle pin direction bits for port, array offset: 0x2480, array step: 0x4 */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name B - Byte pin registers for all port 0 and 1 GPIO pins */
/*! @{ */

#define GPIO_B_PBYTE_MASK                        (0x1U)
#define GPIO_B_PBYTE_SHIFT                       (0U)
/*! PBYTE - Read: state of the pin PIOm_n, regardless of direction, masking, or alternate function,
 *    except that pins configured as analog I/O always read as 0. One register for each port pin.
 *    Supported pins depends on the specific device and package. Write: loads the pin's output bit.
 *    One register for each port pin. Supported pins depends on the specific device and package.
 */
#define GPIO_B_PBYTE(x)                          (((uint8_t)(((uint8_t)(x)) << GPIO_B_PBYTE_SHIFT)) & GPIO_B_PBYTE_MASK)
/*! @} */

/* The count of GPIO_B */
#define GPIO_B_COUNT2                            (32U)

/*! @name W - Word pin registers for all port 0 and 1 GPIO pins */
/*! @{ */

#define GPIO_W_PWORD_MASK                        (0x3FFFFU)
#define GPIO_W_PWORD_SHIFT                       (0U)
/*! PWORD - Read 0: pin PIOm_n is LOW. Write 0: clear output bit. Read 0xFFFF FFFF: pin PIOm_n is
 *    HIGH. Write any value 0x0000 0001 to 0xFFFF FFFF: set output bit. Only 0 or 0xFFFF FFFF can be
 *    read. Writing any value other than 0 will set the output bit. One register for each port pin.
 *    Supported pins depends on the specific device and package.
 */
#define GPIO_W_PWORD(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_W_PWORD_SHIFT)) & GPIO_W_PWORD_MASK)
/*! @} */

/* The count of GPIO_W */
#define GPIO_W_COUNT2                            (32U)

/*! @name DIR - Direction registers */
/*! @{ */

#define GPIO_DIR_DIRP_MASK                       (0x3FFFFU)
#define GPIO_DIR_DIRP_SHIFT                      (0U)
/*! DIRP - Selects pin direction for pin PIOm_n (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported
 *    pins depends on the specific device and package. 0 = input. 1 = output.
 */
#define GPIO_DIR_DIRP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_DIR_DIRP_SHIFT)) & GPIO_DIR_DIRP_MASK)
/*! @} */

/*! @name MASK - Mask register */
/*! @{ */

#define GPIO_MASK_MASKP_MASK                     (0x3FFFFU)
#define GPIO_MASK_MASKP_SHIFT                    (0U)
/*! MASKP - Controls which bits corresponding to PIOm_n are active in the MPORT register (bit 0 =
 *    PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on the specific device and package. 0 =
 *    Read MPORT: pin state; write MPORT: load output bit. 1 = Read MPORT: 0; write MPORT: output bit
 *    not affected.
 */
#define GPIO_MASK_MASKP(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_MASK_MASKP_SHIFT)) & GPIO_MASK_MASKP_MASK)
/*! @} */

/*! @name PIN - Port pin register */
/*! @{ */

#define GPIO_PIN_PORT_MASK                       (0x3FFFFU)
#define GPIO_PIN_PORT_SHIFT                      (0U)
/*! PORT - Reads pin states or loads output bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported
 *    pins depends on the specific device and package. 0 = Read: pin is low; write: clear output bit.
 *    1 = Read: pin is high; write: set output bit.
 */
#define GPIO_PIN_PORT(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_PIN_PORT_SHIFT)) & GPIO_PIN_PORT_MASK)
/*! @} */

/*! @name MPIN - Masked port register */
/*! @{ */

#define GPIO_MPIN_MPORTP_MASK                    (0x3FFFFU)
#define GPIO_MPIN_MPORTP_SHIFT                   (0U)
/*! MPORTP - Masked port register (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on
 *    the specific device and package. 0 = Read: pin is LOW and/or the corresponding bit in the MASK
 *    register is 1; write: clear output bit if the corresponding bit in the MASK register is 0. 1
 *    = Read: pin is HIGH and the corresponding bit in the MASK register is 0; write: set output bit
 *    if the corresponding bit in the MASK register is 0.
 */
#define GPIO_MPIN_MPORTP(x)                      (((uint32_t)(((uint32_t)(x)) << GPIO_MPIN_MPORTP_SHIFT)) & GPIO_MPIN_MPORTP_MASK)
/*! @} */

/*! @name SET - Write: Set register for port Read: output bits for port */
/*! @{ */

#define GPIO_SET_SETP_MASK                       (0x3FFFFU)
#define GPIO_SET_SETP_SHIFT                      (0U)
/*! SETP - Read or set output bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on
 *    the specific device and package. 0 = Read: output bit: write: no operation. 1 = Read: output
 *    bit; write: set output bit.
 */
#define GPIO_SET_SETP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_SET_SETP_SHIFT)) & GPIO_SET_SETP_MASK)
/*! @} */

/*! @name CLR - Clear port */
/*! @{ */

#define GPIO_CLR_CLRP_MASK                       (0x3FFFFU)
#define GPIO_CLR_CLRP_SHIFT                      (0U)
/*! CLRP - Clear output bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on the
 *    specific device and package. 0 = No operation. 1 = Clear output bit.
 */
#define GPIO_CLR_CLRP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_CLR_CLRP_SHIFT)) & GPIO_CLR_CLRP_MASK)
/*! @} */

/*! @name NOT - Toggle port */
/*! @{ */

#define GPIO_NOT_NOTP_MASK                       (0x3FFFFU)
#define GPIO_NOT_NOTP_SHIFT                      (0U)
/*! NOTP - Toggle output bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on the
 *    specific device and package. 0 = no operation. 1 = Toggle output bit.
 */
#define GPIO_NOT_NOTP(x)                         (((uint32_t)(((uint32_t)(x)) << GPIO_NOT_NOTP_SHIFT)) & GPIO_NOT_NOTP_MASK)
/*! @} */

/*! @name DIRSET - Set pin direction bits for port */
/*! @{ */

#define GPIO_DIRSET_DIRSETP_MASK                 (0x3FFFFU)
#define GPIO_DIRSET_DIRSETP_SHIFT                (0U)
/*! DIRSETP - Set direction bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on
 *    the specific device and package. 0 = No operation. 1 = Set direction bit.
 */
#define GPIO_DIRSET_DIRSETP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRSET_DIRSETP_SHIFT)) & GPIO_DIRSET_DIRSETP_MASK)
/*! @} */

/*! @name DIRCLR - Clear pin direction bits for port */
/*! @{ */

#define GPIO_DIRCLR_DIRCLRP_MASK                 (0x3FFFFU)
#define GPIO_DIRCLR_DIRCLRP_SHIFT                (0U)
/*! DIRCLRP - Clear direction bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends on
 *    the specific device and package. 0 = No operation. 1 = Clear direction bit.
 */
#define GPIO_DIRCLR_DIRCLRP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRCLR_DIRCLRP_SHIFT)) & GPIO_DIRCLR_DIRCLRP_MASK)
/*! @} */

/*! @name DIRNOT - Toggle pin direction bits for port */
/*! @{ */

#define GPIO_DIRNOT_DIRNOTP_MASK                 (0x3FFFFU)
#define GPIO_DIRNOT_DIRNOTP_SHIFT                (0U)
/*! DIRNOTP - Toggle direction bits (bit 0 = PIOn_0, bit 1 = PIOn_1, etc.). Supported pins depends
 *    on the specific device and package. 0 = no operation. 1 = Toggle direction bit.
 */
#define GPIO_DIRNOT_DIRNOTP(x)                   (((uint32_t)(((uint32_t)(x)) << GPIO_DIRNOT_DIRNOTP_SHIFT)) & GPIO_DIRNOT_DIRNOTP_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


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


#endif  /* GPIO_H_ */

