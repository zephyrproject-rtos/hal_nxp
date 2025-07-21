/*
** ###################################################################
**     Processors:          LPC844M201JBD48
**                          LPC844M201JBD64
**                          LPC844M201JHI33
**                          LPC844M201JHI48
**                          LPC845M301JBD48
**                          LPC845M301JBD64
**                          LPC845M301JHI33
**                          LPC845M301JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MTB
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MTB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MTB
 *
 * CMSIS Peripheral Access Layer for MTB
 */

#if !defined(PERI_MTB_H_)
#define PERI_MTB_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC844M201JBD48) || defined(CPU_LPC844M201JBD64) || defined(CPU_LPC844M201JHI33) || defined(CPU_LPC844M201JHI48))
#include "LPC844_COMMON.h"
#elif (defined(CPU_LPC845M301JBD48) || defined(CPU_LPC845M301JBD64) || defined(CPU_LPC845M301JHI33) || defined(CPU_LPC845M301JHI48))
#include "LPC845_COMMON.h"
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
   -- MTB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Peripheral_Access_Layer MTB Peripheral Access Layer
 * @{
 */

/** MTB - Register Layout Typedef */
typedef struct {
  __IO uint32_t POSITION;                          /**< POSITION Register, offset: 0x0 */
  __IO uint32_t MASTER;                            /**< MASTER Register, offset: 0x4 */
  __IO uint32_t FLOW;                              /**< FLOW Register, offset: 0x8 */
  __I  uint32_t BASE;                              /**< Indicates where the SRAM is located in the processor memory map. This register is provided to enable auto discovery of the MTB SRAM location, by a debug agent., offset: 0xC */
} MTB_Type;

/* ----------------------------------------------------------------------------
   -- MTB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_Register_Masks MTB Register Masks
 * @{
 */

/*! @name POSITION - POSITION Register */
/*! @{ */

#define MTB_POSITION_WRAP_MASK                   (0x4U)
#define MTB_POSITION_WRAP_SHIFT                  (2U)
/*! WRAP - This bit is set to 1 automatically when the POINTER value wraps as determined by the
 *    MASTER.MASK field in the MASTER Trace Control Register.
 */
#define MTB_POSITION_WRAP(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_POSITION_WRAP_SHIFT)) & MTB_POSITION_WRAP_MASK)

#define MTB_POSITION_POINTER_MASK                (0xFFFFFFF8U)
#define MTB_POSITION_POINTER_SHIFT               (3U)
/*! POINTER - Trace packet location pointer. Because a packet consists of two words, the POINTER
 *    field is the location of the first word of a packet. This field contains bits [31:3] of the
 *    address, in the SRAM, where the next trace packet will be written. The field points to an unused
 *    location and is automatically incremented. A debug agent can calculate the system address, on
 *    the AHB-Lite bus, of the SRAM location pointed to by the POSITION register using the following
 *    equation: system address = BASE + ((P + (2AWIDTH - (BASE MOD 2AWIDTH))) MOD 2AWIDTH). Where P =
 *    POSITION AND 0xFFFF_FFF8. Where BASE is the BASE register value
 */
#define MTB_POSITION_POINTER(x)                  (((uint32_t)(((uint32_t)(x)) << MTB_POSITION_POINTER_SHIFT)) & MTB_POSITION_POINTER_MASK)
/*! @} */

/*! @name MASTER - MASTER Register */
/*! @{ */

#define MTB_MASTER_MASK_MASK                     (0x1FU)
#define MTB_MASTER_MASK_SHIFT                    (0U)
/*! MASK - This value determines the maximum size of the trace buffer in SRAM. It specifies the
 *    most-significant bit of the POSITION.POINTER field that can be updated by automatic increment. If
 *    the trace tries to advance past this power of two, the POSITION.WRAP bit is set to 1, the
 *    POSITION.POINTER[MASK:0] bits are set to zero, and the POSITION.POINTER[AWIDTH-4:MASK+1] bits
 *    remain unchanged. This field causes the trace packet information to be stored in a circular buffer
 *    of size 2(MASK+4) bytes, that can be positioned in memory at multiples of this size. Valid
 *    values of this field are zero to AWIDTH-4. Values greater than the maximum have the same effect
 *    as the maximum.
 */
#define MTB_MASTER_MASK(x)                       (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_MASK_SHIFT)) & MTB_MASTER_MASK_MASK)

#define MTB_MASTER_TSTARTEN_MASK                 (0x20U)
#define MTB_MASTER_TSTARTEN_SHIFT                (5U)
/*! TSTARTEN - Trace start input enable. If this bit is 1 and the TSTART signal is HIGH, then the EN
 *    bit is set to 1. Tracing continues until a stop condition occurs.
 */
#define MTB_MASTER_TSTARTEN(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_TSTARTEN_SHIFT)) & MTB_MASTER_TSTARTEN_MASK)

#define MTB_MASTER_TSTOPEN_MASK                  (0x40U)
#define MTB_MASTER_TSTOPEN_SHIFT                 (6U)
/*! TSTOPEN - Trace stop input enable. If this bit is 1 and the TSTOP signal is HIGH, then the EN
 *    bit is set to 0. If a trace packet is being written to memory, the write is completed before
 *    tracing is stopped.
 */
#define MTB_MASTER_TSTOPEN(x)                    (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_TSTOPEN_SHIFT)) & MTB_MASTER_TSTOPEN_MASK)

#define MTB_MASTER_SFRWPRIV_MASK                 (0x80U)
#define MTB_MASTER_SFRWPRIV_SHIFT                (7U)
/*! SFRWPRIV - Special Function Register Write Privilege bit. If this bit is 0, then User or
 *    Privileged AHB-Lite read and write accesses to the Special Function Registers are permitted. If this
 *    bit is 1, then only Privileged write accesses are permitted and User write accesses are
 *    ignored. The HPROT[1] signal determines if an access is User or Privileged.
 */
#define MTB_MASTER_SFRWPRIV(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_SFRWPRIV_SHIFT)) & MTB_MASTER_SFRWPRIV_MASK)

#define MTB_MASTER_RAMPRIV_MASK                  (0x100U)
#define MTB_MASTER_RAMPRIV_SHIFT                 (8U)
/*! RAMPRIV - SRAM Privilege bit. If this bit is 0, then User or Privileged AHB-Lite read and write
 *    accesses to the SRAM are permitted. If this bit is 1, then only Privileged AHB-Lite read and
 *    write accesses to the SRAM are permitted and User accesses are RAZ/WI. The HPROT[1] signal
 *    determines if an access is User or Privileged.
 */
#define MTB_MASTER_RAMPRIV(x)                    (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_RAMPRIV_SHIFT)) & MTB_MASTER_RAMPRIV_MASK)

#define MTB_MASTER_HALTREQ_MASK                  (0x200U)
#define MTB_MASTER_HALTREQ_SHIFT                 (9U)
/*! HALTREQ - Halt request bit. This bit is connected to the halt request signal of the trace logic,
 *    EDBGRQ. When HALTREQ is set to 1, EDBGRQ is asserted if DBGEN is also HIGH. The HALTREQ bit
 *    can be automatically set to 1 using the FLOW.WATERMARK field.
 */
#define MTB_MASTER_HALTREQ(x)                    (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_HALTREQ_SHIFT)) & MTB_MASTER_HALTREQ_MASK)

#define MTB_MASTER_EN_MASK                       (0x80000000U)
#define MTB_MASTER_EN_SHIFT                      (31U)
/*! EN - Main trace enable bit. When this bit is 1 trace data is written into the SRAM memory
 *    location addressed by POSITION.POINTER. The POSITION.POINTER value auto increments after the trace
 *    data packet is written. The EN bit can be automatically set to 0 using the FLOW.WATERMARK field
 *    and the FLOW.AUTOSTOP bit. The EN bit is automatically set to 1 if the TSTARTEN bit is 1 and
 *    the TSTART signal is HIGH. The EN bit is automatically set to 0 if TSTOPEN bit is 1 and the
 *    TSTOP signal is HIGH.
 */
#define MTB_MASTER_EN(x)                         (((uint32_t)(((uint32_t)(x)) << MTB_MASTER_EN_SHIFT)) & MTB_MASTER_EN_MASK)
/*! @} */

/*! @name FLOW - FLOW Register */
/*! @{ */

#define MTB_FLOW_AUTOSTOP_MASK                   (0x1U)
#define MTB_FLOW_AUTOSTOP_SHIFT                  (0U)
/*! AUTOSTOP - If this bit is 1 and WATERMARK is equal to POSITION.POINTER, then the MASTER.EN bit
 *    is automatically set to 0. This stops tracing.
 */
#define MTB_FLOW_AUTOSTOP(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_FLOW_AUTOSTOP_SHIFT)) & MTB_FLOW_AUTOSTOP_MASK)

#define MTB_FLOW_AUTOHALT_MASK                   (0x2U)
#define MTB_FLOW_AUTOHALT_SHIFT                  (1U)
/*! AUTOHALT - If this bit is 1 and WATERMARK is equal to POSITION.POINTER, then the MASTER.HALTREQ
 *    bit is automatically set to 1. If the DBGEN signal is HIGH, the MTB asserts this halt request
 *    to the Cortex-M0+ processor by asserting the EDBGRQ signal.
 */
#define MTB_FLOW_AUTOHALT(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_FLOW_AUTOHALT_SHIFT)) & MTB_FLOW_AUTOHALT_MASK)

#define MTB_FLOW_WATERMARK_MASK                  (0xFFFFFFF8U)
#define MTB_FLOW_WATERMARK_SHIFT                 (3U)
/*! WATERMARK - WATERMARK value. This field contains an address in the same format as the
 *    POSITION.POINTER field. When the POSITION.POINTER matches the WATERMARK field value, actions defined by
 *    the AUTOHALT and AUTOSTOP bits are performed.
 */
#define MTB_FLOW_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x)) << MTB_FLOW_WATERMARK_SHIFT)) & MTB_FLOW_WATERMARK_MASK)
/*! @} */

/*! @name BASE - Indicates where the SRAM is located in the processor memory map. This register is provided to enable auto discovery of the MTB SRAM location, by a debug agent. */
/*! @{ */

#define MTB_BASE_BASE_MASK                       (0xFFFFFFFFU)
#define MTB_BASE_BASE_SHIFT                      (0U)
/*! BASE - The value provided is the value of the SRAMBASEADDR[31:0] signal. */
#define MTB_BASE_BASE(x)                         (((uint32_t)(((uint32_t)(x)) << MTB_BASE_BASE_SHIFT)) & MTB_BASE_BASE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MTB_Register_Masks */


/*!
 * @}
 */ /* end of group MTB_Peripheral_Access_Layer */


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


#endif  /* PERI_MTB_H_ */

