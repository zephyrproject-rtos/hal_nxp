/*
** ###################################################################
**     Processors:          LPC54605J256BD100
**                          LPC54605J256ET100
**                          LPC54605J256ET180
**                          LPC54605J512BD100
**                          LPC54605J512ET100
**                          LPC54605J512ET180
**                          LPC54606J256BD100
**                          LPC54606J256ET100
**                          LPC54606J256ET180
**                          LPC54606J512BD100
**                          LPC54606J512BD208
**                          LPC54606J512ET100
**                          LPC54607J256BD208
**                          LPC54607J256ET180
**                          LPC54607J512ET180
**                          LPC54608J512BD208
**                          LPC54608J512ET180
**                          LPC54616J256ET180
**                          LPC54616J512BD100
**                          LPC54616J512BD208
**                          LPC54616J512ET100
**                          LPC54618J512BD208
**                          LPC54618J512ET180
**                          LPC54628J512ET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SPIFI
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
 * @file PERI_SPIFI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SPIFI
 *
 * CMSIS Peripheral Access Layer for SPIFI
 */

#if !defined(PERI_SPIFI_H_)
#define PERI_SPIFI_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54605J256BD100) || defined(CPU_LPC54605J256ET100) || defined(CPU_LPC54605J256ET180) || defined(CPU_LPC54605J512BD100) || defined(CPU_LPC54605J512ET100) || defined(CPU_LPC54605J512ET180))
#include "LPC54605_COMMON.h"
#elif (defined(CPU_LPC54606J256BD100) || defined(CPU_LPC54606J256ET100) || defined(CPU_LPC54606J256ET180) || defined(CPU_LPC54606J512BD100) || defined(CPU_LPC54606J512BD208) || defined(CPU_LPC54606J512ET100))
#include "LPC54606_COMMON.h"
#elif (defined(CPU_LPC54607J256BD208) || defined(CPU_LPC54607J256ET180) || defined(CPU_LPC54607J512ET180))
#include "LPC54607_COMMON.h"
#elif (defined(CPU_LPC54608J512BD208) || defined(CPU_LPC54608J512ET180))
#include "LPC54608_COMMON.h"
#elif (defined(CPU_LPC54616J256ET180) || defined(CPU_LPC54616J512BD100) || defined(CPU_LPC54616J512BD208) || defined(CPU_LPC54616J512ET100))
#include "LPC54616_COMMON.h"
#elif (defined(CPU_LPC54618J512BD208) || defined(CPU_LPC54618J512ET180))
#include "LPC54618_COMMON.h"
#elif (defined(CPU_LPC54628J512ET180))
#include "LPC54628_COMMON.h"
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
   -- SPIFI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPIFI_Peripheral_Access_Layer SPIFI Peripheral Access Layer
 * @{
 */

/** SPIFI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< SPIFI control register, offset: 0x0 */
  __IO uint32_t CMD;                               /**< SPIFI command register, offset: 0x4 */
  __IO uint32_t ADDR;                              /**< SPIFI address register, offset: 0x8 */
  __IO uint32_t IDATA;                             /**< SPIFI intermediate data register, offset: 0xC */
  __IO uint32_t CLIMIT;                            /**< SPIFI limit register, offset: 0x10 */
  __IO uint32_t DATA;                              /**< SPIFI data register, offset: 0x14 */
  __IO uint32_t MCMD;                              /**< SPIFI memory command register, offset: 0x18 */
  __IO uint32_t STAT;                              /**< SPIFI status register, offset: 0x1C */
} SPIFI_Type;

/* ----------------------------------------------------------------------------
   -- SPIFI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPIFI_Register_Masks SPIFI Register Masks
 * @{
 */

/*! @name CTRL - SPIFI control register */
/*! @{ */

#define SPIFI_CTRL_TIMEOUT_MASK                  (0xFFFFU)
#define SPIFI_CTRL_TIMEOUT_SHIFT                 (0U)
/*! TIMEOUT - This field contains the number of serial clock periods without the processor reading
 *    data in memory mode, which will cause the SPIFI hardware to terminate the command by driving
 *    the CS pin high and negating the CMD bit in the Status register. (This allows the flash memory
 *    to enter a lower-power state.) If the processor reads data from the flash region after a
 *    time-out, the command in the Memory Command Register is issued again.
 */
#define SPIFI_CTRL_TIMEOUT(x)                    (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_TIMEOUT_SHIFT)) & SPIFI_CTRL_TIMEOUT_MASK)

#define SPIFI_CTRL_CSHIGH_MASK                   (0xF0000U)
#define SPIFI_CTRL_CSHIGH_SHIFT                  (16U)
/*! CSHIGH - This field controls the minimum CS high time, expressed as a number of serial clock periods minus one. */
#define SPIFI_CTRL_CSHIGH(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_CSHIGH_SHIFT)) & SPIFI_CTRL_CSHIGH_MASK)

#define SPIFI_CTRL_D_PRFTCH_DIS_MASK             (0x200000U)
#define SPIFI_CTRL_D_PRFTCH_DIS_SHIFT            (21U)
/*! D_PRFTCH_DIS - This bit allows conditioning of memory mode prefetches based on the AHB HPROT
 *    (instruction/data) access information. A 1 in this register means that the SPIFI will not attempt
 *    a speculative prefetch when it encounters data accesses.
 */
#define SPIFI_CTRL_D_PRFTCH_DIS(x)               (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_D_PRFTCH_DIS_SHIFT)) & SPIFI_CTRL_D_PRFTCH_DIS_MASK)

#define SPIFI_CTRL_INTEN_MASK                    (0x400000U)
#define SPIFI_CTRL_INTEN_SHIFT                   (22U)
/*! INTEN - If this bit is 1 when a command ends, the SPIFI will assert its interrupt request
 *    output. See INTRQ in the status register for further details.
 */
#define SPIFI_CTRL_INTEN(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_INTEN_SHIFT)) & SPIFI_CTRL_INTEN_MASK)

#define SPIFI_CTRL_MODE3_MASK                    (0x800000U)
#define SPIFI_CTRL_MODE3_SHIFT                   (23U)
/*! MODE3 - SPI Mode 3 select.
 *  0b0..SCK LOW. The SPIFI drives SCK low after the rising edge at which the last bit of each command is
 *       captured, and keeps it low while CS is HIGH.
 *  0b1..SCK HIGH. the SPIFI keeps SCK high after the rising edge for the last bit of each command and while CS is
 *       HIGH, and drives it low after it drives CS LOW. (Known serial flash devices can handle either mode, but
 *       some devices may require a particular mode for proper operation.) MODE3, RFCLK, and FBCLK should not all be
 *       1, because in this case there is no final falling edge on SCK on which to sample the last data bit of the
 *       frame.
 */
#define SPIFI_CTRL_MODE3(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_MODE3_SHIFT)) & SPIFI_CTRL_MODE3_MASK)

#define SPIFI_CTRL_PRFTCH_DIS_MASK               (0x8000000U)
#define SPIFI_CTRL_PRFTCH_DIS_SHIFT              (27U)
/*! PRFTCH_DIS - Cache prefetching enable. The SPIFI includes an internal cache. A 1 in this bit disables prefetching of cache lines.
 *  0b0..Enable. Cache prefetching enabled.
 *  0b1..Disable. Disables prefetching of cache lines.
 */
#define SPIFI_CTRL_PRFTCH_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_PRFTCH_DIS_SHIFT)) & SPIFI_CTRL_PRFTCH_DIS_MASK)

#define SPIFI_CTRL_DUAL_MASK                     (0x10000000U)
#define SPIFI_CTRL_DUAL_SHIFT                    (28U)
/*! DUAL - Select dual protocol.
 *  0b0..Quad protocol. This protocol uses IO3:0.
 *  0b1..Dual protocol. This protocol uses IO1:0.
 */
#define SPIFI_CTRL_DUAL(x)                       (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_DUAL_SHIFT)) & SPIFI_CTRL_DUAL_MASK)

#define SPIFI_CTRL_RFCLK_MASK                    (0x20000000U)
#define SPIFI_CTRL_RFCLK_SHIFT                   (29U)
/*! RFCLK - Select active clock edge for input data.
 *  0b0..Rising edge. Read data is sampled on rising edges on the clock, as in classic SPI operation.
 *  0b1..Falling edge. Read data is sampled on falling edges of the clock, allowing a full serial clock of of time
 *       in order to maximize the serial clock frequency. MODE3, RFCLK, and FBCLK should not all be 1, because in
 *       this case there is no final falling edge on SCK on which to sample the last data bit of the frame.
 */
#define SPIFI_CTRL_RFCLK(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_RFCLK_SHIFT)) & SPIFI_CTRL_RFCLK_MASK)

#define SPIFI_CTRL_FBCLK_MASK                    (0x40000000U)
#define SPIFI_CTRL_FBCLK_SHIFT                   (30U)
/*! FBCLK - Feedback clock select.
 *  0b0..Internal clock. The SPIFI samples read data using an internal clock.
 *  0b1..Feedback clock. Read data is sampled using a feedback clock from the SCK pin. This allows slightly more
 *       time for each received bit. MODE3, RFCLK, and FBCLK should not all be 1, because in this case there is no
 *       final falling edge on SCK on which to sample the last data bit of the frame.
 */
#define SPIFI_CTRL_FBCLK(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_FBCLK_SHIFT)) & SPIFI_CTRL_FBCLK_MASK)

#define SPIFI_CTRL_DMAEN_MASK                    (0x80000000U)
#define SPIFI_CTRL_DMAEN_SHIFT                   (31U)
/*! DMAEN - A 1 in this bit enables the DMA Request output from the SPIFI. Set this bit only when a
 *    DMA channel is used to transfer data in peripheral mode. Do not set this bit when a DMA
 *    channel is used for memory-to-memory transfers from the SPIFI memory area. DMAEN should only be used
 *    in Command mode.
 */
#define SPIFI_CTRL_DMAEN(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CTRL_DMAEN_SHIFT)) & SPIFI_CTRL_DMAEN_MASK)
/*! @} */

/*! @name CMD - SPIFI command register */
/*! @{ */

#define SPIFI_CMD_DATALEN_MASK                   (0x3FFFU)
#define SPIFI_CMD_DATALEN_SHIFT                  (0U)
/*! DATALEN - Except when the POLL bit in this register is 1, this field controls how many data
 *    bytes are in the command. 0 indicates that the command does not contain a data field.
 */
#define SPIFI_CMD_DATALEN(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_DATALEN_SHIFT)) & SPIFI_CMD_DATALEN_MASK)

#define SPIFI_CMD_POLL_MASK                      (0x4000U)
#define SPIFI_CMD_POLL_SHIFT                     (14U)
/*! POLL - This bit should be written as 1 only with an opcode that a) contains an input data field,
 *    and b) causes the serial flash device to return byte status repetitively (e.g., a Read Status
 *    command). When this bit is 1, the SPIFI hardware continues to read bytes until the test
 *    specified by the DATALEN field is met. The hardware tests the bit in each status byte selected by
 *    DATALEN bits 2:0, until a bit is found that is equal to DATALEN bit 3. When the test succeeds,
 *    the SPIFI captures the byte that meets this test so that it can be read from the Data
 *    Register, and terminates the command by raising CS. The end-of-command interrupt can be enabled to
 *    inform software when this occurs
 */
#define SPIFI_CMD_POLL(x)                        (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_POLL_SHIFT)) & SPIFI_CMD_POLL_MASK)

#define SPIFI_CMD_DOUT_MASK                      (0x8000U)
#define SPIFI_CMD_DOUT_SHIFT                     (15U)
/*! DOUT - If the DATALEN field is not zero, this bit controls the direction of the data:
 *  0b0..Input from serial flash.
 *  0b1..Output to serial flash.
 */
#define SPIFI_CMD_DOUT(x)                        (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_DOUT_SHIFT)) & SPIFI_CMD_DOUT_MASK)

#define SPIFI_CMD_INTLEN_MASK                    (0x70000U)
#define SPIFI_CMD_INTLEN_SHIFT                   (16U)
/*! INTLEN - This field controls how many intermediate bytes precede the data. (Each such byte may
 *    require 8 or 2 SCK cycles, depending on whether the intermediate field is in serial, 2-bit, or
 *    4-bit format.) Intermediate bytes are output by the SPIFI, and include post-address control
 *    information, dummy and delay bytes. See the description of the Intermediate Data register for
 *    the contents of such bytes.
 */
#define SPIFI_CMD_INTLEN(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_INTLEN_SHIFT)) & SPIFI_CMD_INTLEN_MASK)

#define SPIFI_CMD_FIELDFORM_MASK                 (0x180000U)
#define SPIFI_CMD_FIELDFORM_SHIFT                (19U)
/*! FIELDFORM - This field controls how the fields of the command are sent.
 *  0b00..All serial. All fields of the command are serial.
 *  0b01..Quad/dual data. Data field is quad/dual, other fields are serial.
 *  0b10..Serial opcode. Opcode field is serial. Other fields are quad/dual.
 *  0b11..All quad/dual. All fields of the command are in quad/dual format.
 */
#define SPIFI_CMD_FIELDFORM(x)                   (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_FIELDFORM_SHIFT)) & SPIFI_CMD_FIELDFORM_MASK)

#define SPIFI_CMD_FRAMEFORM_MASK                 (0xE00000U)
#define SPIFI_CMD_FRAMEFORM_SHIFT                (21U)
/*! FRAMEFORM - This field controls the opcode and address fields.
 *  0b000..Reserved.
 *  0b001..Opcode. Opcode only, no address.
 *  0b010..Opcode one byte. Opcode, least significant byte of address.
 *  0b011..Opcode two bytes. Opcode, two least significant bytes of address.
 *  0b100..Opcode three bytes. Opcode, three least significant bytes of address.
 *  0b101..Opcode four bytes. Opcode, 4 bytes of address.
 *  0b110..No opcode three bytes. No opcode, 3 least significant bytes of address.
 *  0b111..No opcode four bytes. No opcode, 4 bytes of address.
 */
#define SPIFI_CMD_FRAMEFORM(x)                   (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_FRAMEFORM_SHIFT)) & SPIFI_CMD_FRAMEFORM_MASK)

#define SPIFI_CMD_OPCODE_MASK                    (0xFF000000U)
#define SPIFI_CMD_OPCODE_SHIFT                   (24U)
/*! OPCODE - The opcode of the command (not used for some FRAMEFORM values). */
#define SPIFI_CMD_OPCODE(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_CMD_OPCODE_SHIFT)) & SPIFI_CMD_OPCODE_MASK)
/*! @} */

/*! @name ADDR - SPIFI address register */
/*! @{ */

#define SPIFI_ADDR_ADDRESS_MASK                  (0xFFFFFFFFU)
#define SPIFI_ADDR_ADDRESS_SHIFT                 (0U)
/*! ADDRESS - Address. */
#define SPIFI_ADDR_ADDRESS(x)                    (((uint32_t)(((uint32_t)(x)) << SPIFI_ADDR_ADDRESS_SHIFT)) & SPIFI_ADDR_ADDRESS_MASK)
/*! @} */

/*! @name IDATA - SPIFI intermediate data register */
/*! @{ */

#define SPIFI_IDATA_IDATA_MASK                   (0xFFFFFFFFU)
#define SPIFI_IDATA_IDATA_SHIFT                  (0U)
/*! IDATA - Value of intermediate bytes. */
#define SPIFI_IDATA_IDATA(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_IDATA_IDATA_SHIFT)) & SPIFI_IDATA_IDATA_MASK)
/*! @} */

/*! @name CLIMIT - SPIFI limit register */
/*! @{ */

#define SPIFI_CLIMIT_CLIMIT_MASK                 (0xFFFFFFFFU)
#define SPIFI_CLIMIT_CLIMIT_SHIFT                (0U)
/*! CLIMIT - Zero-based upper limit of cacheable memory */
#define SPIFI_CLIMIT_CLIMIT(x)                   (((uint32_t)(((uint32_t)(x)) << SPIFI_CLIMIT_CLIMIT_SHIFT)) & SPIFI_CLIMIT_CLIMIT_MASK)
/*! @} */

/*! @name DATA - SPIFI data register */
/*! @{ */

#define SPIFI_DATA_DATA_MASK                     (0xFFFFFFFFU)
#define SPIFI_DATA_DATA_SHIFT                    (0U)
/*! DATA - Input or output data */
#define SPIFI_DATA_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << SPIFI_DATA_DATA_SHIFT)) & SPIFI_DATA_DATA_MASK)
/*! @} */

/*! @name MCMD - SPIFI memory command register */
/*! @{ */

#define SPIFI_MCMD_POLL_MASK                     (0x4000U)
#define SPIFI_MCMD_POLL_SHIFT                    (14U)
/*! POLL - This bit should be written as 0. */
#define SPIFI_MCMD_POLL(x)                       (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_POLL_SHIFT)) & SPIFI_MCMD_POLL_MASK)

#define SPIFI_MCMD_DOUT_MASK                     (0x8000U)
#define SPIFI_MCMD_DOUT_SHIFT                    (15U)
/*! DOUT - This bit should be written as 0. */
#define SPIFI_MCMD_DOUT(x)                       (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_DOUT_SHIFT)) & SPIFI_MCMD_DOUT_MASK)

#define SPIFI_MCMD_INTLEN_MASK                   (0x70000U)
#define SPIFI_MCMD_INTLEN_SHIFT                  (16U)
/*! INTLEN - This field controls how many intermediate bytes precede the data. (Each such byte may
 *    require 8 or 2 SCK cycles, depending on whether the intermediate field is in serial, 2-bit, or
 *    4-bit format.) Intermediate bytes are output by the SPIFI, and include post-address control
 *    information, dummy and delay bytes. See the description of the Intermediate Data register for
 *    the contents of such bytes.
 */
#define SPIFI_MCMD_INTLEN(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_INTLEN_SHIFT)) & SPIFI_MCMD_INTLEN_MASK)

#define SPIFI_MCMD_FIELDFORM_MASK                (0x180000U)
#define SPIFI_MCMD_FIELDFORM_SHIFT               (19U)
/*! FIELDFORM - This field controls how the fields of the command are sent.
 *  0b00..All serial. All fields of the command are serial.
 *  0b01..Quad/dual data. Data field is quad/dual, other fields are serial.
 *  0b10..Serial opcode. Opcode field is serial. Other fields are quad/dual.
 *  0b11..All quad/dual. All fields of the command are in quad/dual format.
 */
#define SPIFI_MCMD_FIELDFORM(x)                  (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_FIELDFORM_SHIFT)) & SPIFI_MCMD_FIELDFORM_MASK)

#define SPIFI_MCMD_FRAMEFORM_MASK                (0xE00000U)
#define SPIFI_MCMD_FRAMEFORM_SHIFT               (21U)
/*! FRAMEFORM - This field controls the opcode and address fields.
 *  0b000..Reserved.
 *  0b001..Opcode. Opcode only, no address.
 *  0b010..Opcode one byte. Opcode, least-significant byte of address.
 *  0b011..Opcode two bytes. Opcode, 2 least-significant bytes of address.
 *  0b100..Opcode three bytes. Opcode, 3 least-significant bytes of address.
 *  0b101..Opcode four bytes. Opcode, 4 bytes of address.
 *  0b110..No opcode three bytes. No opcode, 3 least-significant bytes of address.
 *  0b111..No opcode, 4 bytes of address.
 */
#define SPIFI_MCMD_FRAMEFORM(x)                  (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_FRAMEFORM_SHIFT)) & SPIFI_MCMD_FRAMEFORM_MASK)

#define SPIFI_MCMD_OPCODE_MASK                   (0xFF000000U)
#define SPIFI_MCMD_OPCODE_SHIFT                  (24U)
/*! OPCODE - The opcode of the command (not used for some FRAMEFORM values). */
#define SPIFI_MCMD_OPCODE(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_MCMD_OPCODE_SHIFT)) & SPIFI_MCMD_OPCODE_MASK)
/*! @} */

/*! @name STAT - SPIFI status register */
/*! @{ */

#define SPIFI_STAT_MCINIT_MASK                   (0x1U)
#define SPIFI_STAT_MCINIT_SHIFT                  (0U)
/*! MCINIT - This bit is set when software successfully writes the Memory Command register, and is
 *    cleared by Reset or by writing a 1 to the RESET bit in this register.
 */
#define SPIFI_STAT_MCINIT(x)                     (((uint32_t)(((uint32_t)(x)) << SPIFI_STAT_MCINIT_SHIFT)) & SPIFI_STAT_MCINIT_MASK)

#define SPIFI_STAT_CMD_MASK                      (0x2U)
#define SPIFI_STAT_CMD_SHIFT                     (1U)
/*! CMD - This bit is 1 when the Command register is written. It is cleared by a hardware reset, a
 *    write to the RESET bit in this register, or the deassertion of CS which indicates that the
 *    command has completed communication with the SPI Flash.
 */
#define SPIFI_STAT_CMD(x)                        (((uint32_t)(((uint32_t)(x)) << SPIFI_STAT_CMD_SHIFT)) & SPIFI_STAT_CMD_MASK)

#define SPIFI_STAT_RESET_MASK                    (0x10U)
#define SPIFI_STAT_RESET_SHIFT                   (4U)
/*! RESET - Write a 1 to this bit to abort a current command or memory mode. This bit is cleared
 *    when the hardware is ready for a new command to be written to the Command register.
 */
#define SPIFI_STAT_RESET(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_STAT_RESET_SHIFT)) & SPIFI_STAT_RESET_MASK)

#define SPIFI_STAT_INTRQ_MASK                    (0x20U)
#define SPIFI_STAT_INTRQ_SHIFT                   (5U)
/*! INTRQ - This bit reflects the SPIFI interrupt request. Write a 1 to this bit to clear it. This
 *    bit is set when a CMD was previously 1 and has been cleared due to the deassertion of CS.
 */
#define SPIFI_STAT_INTRQ(x)                      (((uint32_t)(((uint32_t)(x)) << SPIFI_STAT_INTRQ_SHIFT)) & SPIFI_STAT_INTRQ_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SPIFI_Register_Masks */


/*!
 * @}
 */ /* end of group SPIFI_Peripheral_Access_Layer */


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


#endif  /* PERI_SPIFI_H_ */

