/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for EPDC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_EPDC.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for EPDC
 *
 * CMSIS Peripheral Access Layer for EPDC
 */

#if !defined(PERI_EPDC_H_)
#define PERI_EPDC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- EPDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPDC_Peripheral_Access_Layer EPDC Peripheral Access Layer
 * @{
 */

/** EPDC - Size of Registers Arrays */
#define EPDC_PIGEON_X_COUNT                       17u

/** EPDC - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Control Register, offset: 0x0 */
    __IO uint32_t SET;                               /**< Control Register, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Control Register, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Control Register, offset: 0xC */
  } CTRL;
  __IO uint32_t WB_ADDR_TCE;                       /**< Working Buffer Address for TCE, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t WVADDR;                            /**< Waveform Address Pointer, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t WB_ADDR;                           /**< Working Buffer Address, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t RES;                               /**< Screen Resolution, offset: 0x40 */
       uint8_t RESERVED_3[12];
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Format Control Register, offset: 0x50 */
    __IO uint32_t SET;                               /**< Format Control Register, offset: 0x54 */
    __IO uint32_t CLR;                               /**< Format Control Register, offset: 0x58 */
    __IO uint32_t TOG;                               /**< Format Control Register, offset: 0x5C */
  } FORMAT;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< Working Buffer Field Setting, offset: 0x60 */
    __IO uint32_t SET;                               /**< Working Buffer Field Setting, offset: 0x64 */
    __IO uint32_t CLR;                               /**< Working Buffer Field Setting, offset: 0x68 */
    __IO uint32_t TOG;                               /**< Working Buffer Field Setting, offset: 0x6C */
  } WB_FIELD0;
  struct {                                         /* offset: 0x70 */
    __IO uint32_t RW;                                /**< Working Buffer Field Setting, offset: 0x70 */
    __IO uint32_t SET;                               /**< Working Buffer Field Setting, offset: 0x74 */
    __IO uint32_t CLR;                               /**< Working Buffer Field Setting, offset: 0x78 */
    __IO uint32_t TOG;                               /**< Working Buffer Field Setting, offset: 0x7C */
  } WB_FIELD1;
  struct {                                         /* offset: 0x80 */
    __IO uint32_t RW;                                /**< Working Buffer Field Setting, offset: 0x80 */
    __IO uint32_t SET;                               /**< Working Buffer Field Setting, offset: 0x84 */
    __IO uint32_t CLR;                               /**< Working Buffer Field Setting, offset: 0x88 */
    __IO uint32_t TOG;                               /**< Working Buffer Field Setting, offset: 0x8C */
  } WB_FIELD2;
  struct {                                         /* offset: 0x90 */
    __IO uint32_t RW;                                /**< Working Buffer Field Setting, offset: 0x90 */
    __IO uint32_t SET;                               /**< Working Buffer Field Setting, offset: 0x94 */
    __IO uint32_t CLR;                               /**< Working Buffer Field Setting, offset: 0x98 */
    __IO uint32_t TOG;                               /**< Working Buffer Field Setting, offset: 0x9C */
  } WB_FIELD3;
  struct {                                         /* offset: 0xA0 */
    __IO uint32_t RW;                                /**< FIFO control register, offset: 0xA0 */
    __IO uint32_t SET;                               /**< FIFO control register, offset: 0xA4 */
    __IO uint32_t CLR;                               /**< FIFO control register, offset: 0xA8 */
    __IO uint32_t TOG;                               /**< FIFO control register, offset: 0xAC */
  } FIFOCTRL;
       uint8_t RESERVED_4[80];
  __IO uint32_t UPD_ADDR;                          /**< Update Region Address, offset: 0x100 */
       uint8_t RESERVED_5[12];
  __IO uint32_t UPD_STRIDE;                        /**< Update Region Stride, offset: 0x110 */
       uint8_t RESERVED_6[12];
  __IO uint32_t UPD_CORD;                          /**< Update Command Co-ordinate, offset: 0x120 */
       uint8_t RESERVED_7[28];
  __IO uint32_t UPD_SIZE;                          /**< Update Command Size, offset: 0x140 */
       uint8_t RESERVED_8[28];
  struct {                                         /* offset: 0x160 */
    __IO uint32_t RW;                                /**< Update Command Control, offset: 0x160 */
    __IO uint32_t SET;                               /**< Update Command Control, offset: 0x164 */
    __IO uint32_t CLR;                               /**< Update Command Control, offset: 0x168 */
    __IO uint32_t TOG;                               /**< Update Command Control, offset: 0x16C */
  } UPD_CTRL;
       uint8_t RESERVED_9[16];
  struct {                                         /* offset: 0x180 */
    __IO uint32_t RW;                                /**< Update Fixed Pixel Control, offset: 0x180 */
    __IO uint32_t SET;                               /**< Update Fixed Pixel Control, offset: 0x184 */
    __IO uint32_t CLR;                               /**< Update Fixed Pixel Control, offset: 0x188 */
    __IO uint32_t TOG;                               /**< Update Fixed Pixel Control, offset: 0x18C */
  } UPD_FIXED;
       uint8_t RESERVED_10[16];
  __IO uint32_t TEMP;                              /**< Temperature Register, offset: 0x1A0 */
       uint8_t RESERVED_11[28];
  __IO uint32_t AUTOWV_LUT;                        /**< Waveform Mode Lookup Table Control Register., offset: 0x1C0 */
       uint8_t RESERVED_12[28];
  struct {                                         /* offset: 0x1E0 */
    __IO uint32_t RW;                                /**< LUT Standby Register - LUT 31~0, offset: 0x1E0 */
    __IO uint32_t SET;                               /**< LUT Standby Register - LUT 31~0, offset: 0x1E4 */
    __IO uint32_t CLR;                               /**< LUT Standby Register - LUT 31~0, offset: 0x1E8 */
    __IO uint32_t TOG;                               /**< LUT Standby Register - LUT 31~0, offset: 0x1EC */
  } LUT_STANDBY1;
  struct {                                         /* offset: 0x1F0 */
    __IO uint32_t RW;                                /**< LUT Standby Register - LUT 63~32, offset: 0x1F0 */
    __IO uint32_t SET;                               /**< LUT Standby Register - LUT 63~32, offset: 0x1F4 */
    __IO uint32_t CLR;                               /**< LUT Standby Register - LUT 63~32, offset: 0x1F8 */
    __IO uint32_t TOG;                               /**< LUT Standby Register - LUT 63~32, offset: 0x1FC */
  } LUT_STANDBY2;
  struct {                                         /* offset: 0x200 */
    __IO uint32_t RW;                                /**< Timing Control Engine Control Register, offset: 0x200 */
    __IO uint32_t SET;                               /**< Timing Control Engine Control Register, offset: 0x204 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Control Register, offset: 0x208 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Control Register, offset: 0x20C */
  } TCE_CTRL;
       uint8_t RESERVED_13[16];
  struct {                                         /* offset: 0x220 */
    __IO uint32_t RW;                                /**< Timing Control Engine Source-Driver Config Register, offset: 0x220 */
    __IO uint32_t SET;                               /**< Timing Control Engine Source-Driver Config Register, offset: 0x224 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Source-Driver Config Register, offset: 0x228 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Source-Driver Config Register, offset: 0x22C */
  } TCE_SDCFG;
       uint8_t RESERVED_14[16];
  struct {                                         /* offset: 0x240 */
    __IO uint32_t RW;                                /**< Timing Control Engine Gate-Driver Config Register, offset: 0x240 */
    __IO uint32_t SET;                               /**< Timing Control Engine Gate-Driver Config Register, offset: 0x244 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Gate-Driver Config Register, offset: 0x248 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Gate-Driver Config Register, offset: 0x24C */
  } TCE_GDCFG;
       uint8_t RESERVED_15[16];
  struct {                                         /* offset: 0x260 */
    __IO uint32_t RW;                                /**< Timing Control Engine Horizontal Timing Register 1, offset: 0x260 */
    __IO uint32_t SET;                               /**< Timing Control Engine Horizontal Timing Register 1, offset: 0x264 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Horizontal Timing Register 1, offset: 0x268 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Horizontal Timing Register 1, offset: 0x26C */
  } TCE_HSCAN1;
       uint8_t RESERVED_16[16];
  struct {                                         /* offset: 0x280 */
    __IO uint32_t RW;                                /**< Timing Control Engine Horizontal Timing Register 2, offset: 0x280 */
    __IO uint32_t SET;                               /**< Timing Control Engine Horizontal Timing Register 2, offset: 0x284 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Horizontal Timing Register 2, offset: 0x288 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Horizontal Timing Register 2, offset: 0x28C */
  } TCE_HSCAN2;
       uint8_t RESERVED_17[16];
  struct {                                         /* offset: 0x2A0 */
    __IO uint32_t RW;                                /**< Timing Control Engine Vertical Timing Register, offset: 0x2A0 */
    __IO uint32_t SET;                               /**< Timing Control Engine Vertical Timing Register, offset: 0x2A4 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Vertical Timing Register, offset: 0x2A8 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Vertical Timing Register, offset: 0x2AC */
  } TCE_VSCAN;
       uint8_t RESERVED_18[16];
  struct {                                         /* offset: 0x2C0 */
    __IO uint32_t RW;                                /**< Timing Control Engine OE timing control Register, offset: 0x2C0 */
    __IO uint32_t SET;                               /**< Timing Control Engine OE timing control Register, offset: 0x2C4 */
    __IO uint32_t CLR;                               /**< Timing Control Engine OE timing control Register, offset: 0x2C8 */
    __IO uint32_t TOG;                               /**< Timing Control Engine OE timing control Register, offset: 0x2CC */
  } TCE_OE;
       uint8_t RESERVED_19[16];
  struct {                                         /* offset: 0x2E0 */
    __IO uint32_t RW;                                /**< Timing Control Engine Driver Polarity Register, offset: 0x2E0 */
    __IO uint32_t SET;                               /**< Timing Control Engine Driver Polarity Register, offset: 0x2E4 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Driver Polarity Register, offset: 0x2E8 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Driver Polarity Register, offset: 0x2EC */
  } TCE_POLARITY;
       uint8_t RESERVED_20[16];
  struct {                                         /* offset: 0x300 */
    __IO uint32_t RW;                                /**< Timing Control Engine Timing Register 1, offset: 0x300 */
    __IO uint32_t SET;                               /**< Timing Control Engine Timing Register 1, offset: 0x304 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Timing Register 1, offset: 0x308 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Timing Register 1, offset: 0x30C */
  } TCE_TIMING1;
  struct {                                         /* offset: 0x310 */
    __IO uint32_t RW;                                /**< Timing Control Engine Timing Register 2, offset: 0x310 */
    __IO uint32_t SET;                               /**< Timing Control Engine Timing Register 2, offset: 0x314 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Timing Register 2, offset: 0x318 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Timing Register 2, offset: 0x31C */
  } TCE_TIMING2;
  struct {                                         /* offset: 0x320 */
    __IO uint32_t RW;                                /**< Timing Control Engine Timing Register 3, offset: 0x320 */
    __IO uint32_t SET;                               /**< Timing Control Engine Timing Register 3, offset: 0x324 */
    __IO uint32_t CLR;                               /**< Timing Control Engine Timing Register 3, offset: 0x328 */
    __IO uint32_t TOG;                               /**< Timing Control Engine Timing Register 3, offset: 0x32C */
  } TCE_TIMING3;
       uint8_t RESERVED_21[80];
  struct {                                         /* offset: 0x380 */
    __IO uint32_t RW;                                /**< Pigeon Mode Control Register 0, offset: 0x380 */
    __IO uint32_t SET;                               /**< Pigeon Mode Control Register 0, offset: 0x384 */
    __IO uint32_t CLR;                               /**< Pigeon Mode Control Register 0, offset: 0x388 */
    __IO uint32_t TOG;                               /**< Pigeon Mode Control Register 0, offset: 0x38C */
  } PIGEON_CTRL0;
  struct {                                         /* offset: 0x390 */
    __IO uint32_t RW;                                /**< Pigeon Mode Control Register 1, offset: 0x390 */
    __IO uint32_t SET;                               /**< Pigeon Mode Control Register 1, offset: 0x394 */
    __IO uint32_t CLR;                               /**< Pigeon Mode Control Register 1, offset: 0x398 */
    __IO uint32_t TOG;                               /**< Pigeon Mode Control Register 1, offset: 0x39C */
  } PIGEON_CTRL1;
       uint8_t RESERVED_22[32];
  struct {                                         /* offset: 0x3C0 */
    __IO uint32_t RW;                                /**< IRQ Mask Register - LUT 0~31, offset: 0x3C0 */
    __IO uint32_t SET;                               /**< IRQ Mask Register - LUT 0~31, offset: 0x3C4 */
    __IO uint32_t CLR;                               /**< IRQ Mask Register - LUT 0~31, offset: 0x3C8 */
    __IO uint32_t TOG;                               /**< IRQ Mask Register - LUT 0~31, offset: 0x3CC */
  } IRQ_MASK1;
  struct {                                         /* offset: 0x3D0 */
    __IO uint32_t RW;                                /**< IRQ Mask Register - LUT 32~63, offset: 0x3D0 */
    __IO uint32_t SET;                               /**< IRQ Mask Register - LUT 32~63, offset: 0x3D4 */
    __IO uint32_t CLR;                               /**< IRQ Mask Register - LUT 32~63, offset: 0x3D8 */
    __IO uint32_t TOG;                               /**< IRQ Mask Register - LUT 32~63, offset: 0x3DC */
  } IRQ_MASK2;
  struct {                                         /* offset: 0x3E0 */
    __IO uint32_t RW;                                /**< Interrupt Register - LUT 0~31, offset: 0x3E0 */
    __IO uint32_t SET;                               /**< Interrupt Register - LUT 0~31, offset: 0x3E4 */
    __IO uint32_t CLR;                               /**< Interrupt Register - LUT 0~31, offset: 0x3E8 */
    __IO uint32_t TOG;                               /**< Interrupt Register - LUT 0~31, offset: 0x3EC */
  } IRQ1;
  struct {                                         /* offset: 0x3F0 */
    __IO uint32_t RW;                                /**< Interrupt Register - LUT 32~63, offset: 0x3F0 */
    __IO uint32_t SET;                               /**< Interrupt Register - LUT 32~63, offset: 0x3F4 */
    __IO uint32_t CLR;                               /**< Interrupt Register - LUT 32~63, offset: 0x3F8 */
    __IO uint32_t TOG;                               /**< Interrupt Register - LUT 32~63, offset: 0x3FC */
  } IRQ2;
  struct {                                         /* offset: 0x400 */
    __IO uint32_t RW;                                /**< IRQ Mask Register, offset: 0x400 */
    __IO uint32_t SET;                               /**< IRQ Mask Register, offset: 0x404 */
    __IO uint32_t CLR;                               /**< IRQ Mask Register, offset: 0x408 */
    __IO uint32_t TOG;                               /**< IRQ Mask Register, offset: 0x40C */
  } IRQ_MASK;
       uint8_t RESERVED_23[16];
  struct {                                         /* offset: 0x420 */
    __IO uint32_t RW;                                /**< Interrupt Register, offset: 0x420 */
    __IO uint32_t SET;                               /**< Interrupt Register, offset: 0x424 */
    __IO uint32_t CLR;                               /**< Interrupt Register, offset: 0x428 */
    __IO uint32_t TOG;                               /**< Interrupt Register, offset: 0x42C */
  } IRQ;
       uint8_t RESERVED_24[16];
  struct {                                         /* offset: 0x440 */
    __I  uint32_t RW;                                /**< Status Register - LUTs, offset: 0x440 */
    __I  uint32_t SET;                               /**< Status Register - LUTs, offset: 0x444 */
    __I  uint32_t CLR;                               /**< Status Register - LUTs, offset: 0x448 */
    __I  uint32_t TOG;                               /**< Status Register - LUTs, offset: 0x44C */
  } STATUS_LUTS1;
  struct {                                         /* offset: 0x450 */
    __I  uint32_t RW;                                /**< Status Register - LUTs, offset: 0x450 */
    __I  uint32_t SET;                               /**< Status Register - LUTs, offset: 0x454 */
    __I  uint32_t CLR;                               /**< Status Register - LUTs, offset: 0x458 */
    __I  uint32_t TOG;                               /**< Status Register - LUTs, offset: 0x45C */
  } STATUS_LUTS2;
  __I  uint32_t STATUS_NEXTLUT;                    /**< Status Register - Next Available LUT, offset: 0x460 */
       uint8_t RESERVED_25[28];
  struct {                                         /* offset: 0x480 */
    __I  uint32_t RW;                                /**< LUT Collision Status, offset: 0x480 */
    __I  uint32_t SET;                               /**< LUT Collision Status, offset: 0x484 */
    __I  uint32_t CLR;                               /**< LUT Collision Status, offset: 0x488 */
    __I  uint32_t TOG;                               /**< LUT Collision Status, offset: 0x48C */
  } STATUS_COL1;
  struct {                                         /* offset: 0x490 */
    __I  uint32_t RW;                                /**< LUT Collision Status, offset: 0x490 */
    __I  uint32_t SET;                               /**< LUT Collision Status, offset: 0x494 */
    __I  uint32_t CLR;                               /**< LUT Collision Status, offset: 0x498 */
    __I  uint32_t TOG;                               /**< LUT Collision Status, offset: 0x49C */
  } STATUS_COL2;
  struct {                                         /* offset: 0x4A0 */
    __IO uint32_t RW;                                /**< General Status Register, offset: 0x4A0 */
    __IO uint32_t SET;                               /**< General Status Register, offset: 0x4A4 */
    __IO uint32_t CLR;                               /**< General Status Register, offset: 0x4A8 */
    __IO uint32_t TOG;                               /**< General Status Register, offset: 0x4AC */
  } STATUS;
       uint8_t RESERVED_26[16];
  __I  uint32_t UPD_COL_CORD;                      /**< Collision Region Co-ordinate, offset: 0x4C0 */
       uint8_t RESERVED_27[28];
  __I  uint32_t UPD_COL_SIZE;                      /**< Collision Region Size, offset: 0x4E0 */
       uint8_t RESERVED_28[284];
  __IO uint32_t HIST1_PARAM;                       /**< 1-level Histogram Parameter Register, offset: 0x600 */
       uint8_t RESERVED_29[12];
  __IO uint32_t HIST2_PARAM;                       /**< 2-level Histogram Parameter Register, offset: 0x610 */
       uint8_t RESERVED_30[12];
  __IO uint32_t HIST4_PARAM;                       /**< 4-level Histogram Parameter Register, offset: 0x620 */
       uint8_t RESERVED_31[12];
  __IO uint32_t HIST8_PARAM0;                      /**< 8-level Histogram Parameter 0 Register, offset: 0x630 */
       uint8_t RESERVED_32[12];
  __IO uint32_t HIST8_PARAM1;                      /**< 8-level Histogram Parameter 1 Register, offset: 0x640 */
       uint8_t RESERVED_33[12];
  __IO uint32_t HIST16_PARAM0;                     /**< 16-level Histogram Parameter 0 Register, offset: 0x650 */
       uint8_t RESERVED_34[12];
  __IO uint32_t HIST16_PARAM1;                     /**< 16-level Histogram Parameter Register, offset: 0x660 */
       uint8_t RESERVED_35[12];
  __IO uint32_t HIST16_PARAM2;                     /**< 16-level Histogram Parameter Register, offset: 0x670 */
       uint8_t RESERVED_36[12];
  __IO uint32_t HIST16_PARAM3;                     /**< 16-level Histogram Parameter Register, offset: 0x680 */
       uint8_t RESERVED_37[124];
  struct {                                         /* offset: 0x700 */
    __IO uint32_t RW;                                /**< General Purpose I/O Debug register, offset: 0x700 */
    __IO uint32_t SET;                               /**< General Purpose I/O Debug register, offset: 0x704 */
    __IO uint32_t CLR;                               /**< General Purpose I/O Debug register, offset: 0x708 */
    __IO uint32_t TOG;                               /**< General Purpose I/O Debug register, offset: 0x70C */
  } GPIO;
       uint8_t RESERVED_38[224];
  __I  uint32_t VERSION;                           /**< Version Register, offset: 0x7F0 */
       uint8_t RESERVED_39[12];
  struct {                                         /* offset: 0x800, array step: 0x40 */
    __IO uint32_t PIGEON_0;                          /**< Panel Interface Signal Generator Register 0_0..Panel Interface Signal Generator Register 16_0, array offset: 0x800, array step: 0x40 */
         uint8_t RESERVED_0[12];
    __IO uint32_t PIGEON_1;                          /**< Panel Interface Signal Generator Register 0_1..Panel Interface Signal Generator Register 16_1, array offset: 0x810, array step: 0x40 */
         uint8_t RESERVED_1[12];
    __IO uint32_t PIGEON_2;                          /**< Panel Interface Signal Generator Register 0_2..Panel Interface Signal Generator Register 16_2, array offset: 0x820, array step: 0x40 */
         uint8_t RESERVED_2[28];
  } PIGEON_X[EPDC_PIGEON_X_COUNT];
} EPDC_Type;

/* ----------------------------------------------------------------------------
   -- EPDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EPDC_Register_Masks EPDC Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define EPDC_CTRL_LUT_DATA_SWIZZLE_MASK          (0x30U)
#define EPDC_CTRL_LUT_DATA_SWIZZLE_SHIFT         (4U)
/*! LUT_DATA_SWIZZLE
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define EPDC_CTRL_LUT_DATA_SWIZZLE(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_LUT_DATA_SWIZZLE_SHIFT)) & EPDC_CTRL_LUT_DATA_SWIZZLE_MASK)

#define EPDC_CTRL_UPD_DATA_SWIZZLE_MASK          (0xC0U)
#define EPDC_CTRL_UPD_DATA_SWIZZLE_SHIFT         (6U)
/*! UPD_DATA_SWIZZLE
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define EPDC_CTRL_UPD_DATA_SWIZZLE(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_UPD_DATA_SWIZZLE_SHIFT)) & EPDC_CTRL_UPD_DATA_SWIZZLE_MASK)

#define EPDC_CTRL_LUT_STATE_SW_RESET_EN_MASK     (0x10000000U)
#define EPDC_CTRL_LUT_STATE_SW_RESET_EN_SHIFT    (28U)
#define EPDC_CTRL_LUT_STATE_SW_RESET_EN(x)       (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_LUT_STATE_SW_RESET_EN_SHIFT)) & EPDC_CTRL_LUT_STATE_SW_RESET_EN_MASK)

#define EPDC_CTRL_FRAME_CLEAR_EN_MASK            (0x20000000U)
#define EPDC_CTRL_FRAME_CLEAR_EN_SHIFT           (29U)
#define EPDC_CTRL_FRAME_CLEAR_EN(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_FRAME_CLEAR_EN_SHIFT)) & EPDC_CTRL_FRAME_CLEAR_EN_MASK)

#define EPDC_CTRL_CLKGATE_MASK                   (0x40000000U)
#define EPDC_CTRL_CLKGATE_SHIFT                  (30U)
#define EPDC_CTRL_CLKGATE(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_CLKGATE_SHIFT)) & EPDC_CTRL_CLKGATE_MASK)

#define EPDC_CTRL_SFTRST_MASK                    (0x80000000U)
#define EPDC_CTRL_SFTRST_SHIFT                   (31U)
#define EPDC_CTRL_SFTRST(x)                      (((uint32_t)(((uint32_t)(x)) << EPDC_CTRL_SFTRST_SHIFT)) & EPDC_CTRL_SFTRST_MASK)
/*! @} */

/*! @name WB_ADDR_TCE - Working Buffer Address for TCE */
/*! @{ */

#define EPDC_WB_ADDR_TCE_ADDR_MASK               (0xFFFFFFFFU)
#define EPDC_WB_ADDR_TCE_ADDR_SHIFT              (0U)
#define EPDC_WB_ADDR_TCE_ADDR(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_WB_ADDR_TCE_ADDR_SHIFT)) & EPDC_WB_ADDR_TCE_ADDR_MASK)
/*! @} */

/*! @name WVADDR - Waveform Address Pointer */
/*! @{ */

#define EPDC_WVADDR_ADDR_MASK                    (0xFFFFFFFFU)
#define EPDC_WVADDR_ADDR_SHIFT                   (0U)
#define EPDC_WVADDR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << EPDC_WVADDR_ADDR_SHIFT)) & EPDC_WVADDR_ADDR_MASK)
/*! @} */

/*! @name WB_ADDR - Working Buffer Address */
/*! @{ */

#define EPDC_WB_ADDR_ADDR_MASK                   (0xFFFFFFFFU)
#define EPDC_WB_ADDR_ADDR_SHIFT                  (0U)
#define EPDC_WB_ADDR_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_WB_ADDR_ADDR_SHIFT)) & EPDC_WB_ADDR_ADDR_MASK)
/*! @} */

/*! @name RES - Screen Resolution */
/*! @{ */

#define EPDC_RES_HORIZONTAL_MASK                 (0x1FFFU)
#define EPDC_RES_HORIZONTAL_SHIFT                (0U)
#define EPDC_RES_HORIZONTAL(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_RES_HORIZONTAL_SHIFT)) & EPDC_RES_HORIZONTAL_MASK)

#define EPDC_RES_VERTICAL_MASK                   (0x1FFF0000U)
#define EPDC_RES_VERTICAL_SHIFT                  (16U)
#define EPDC_RES_VERTICAL(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_RES_VERTICAL_SHIFT)) & EPDC_RES_VERTICAL_MASK)
/*! @} */

/*! @name FORMAT - Format Control Register */
/*! @{ */

#define EPDC_FORMAT_TFT_PIXEL_FORMAT_MASK        (0x3U)
#define EPDC_FORMAT_TFT_PIXEL_FORMAT_SHIFT       (0U)
/*! TFT_PIXEL_FORMAT
 *  0b00..2-bit
 *  0b01..2-bit and VCOM
 *  0b10..4-bit
 *  0b11..4-bit and VCOM
 */
#define EPDC_FORMAT_TFT_PIXEL_FORMAT(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_FORMAT_TFT_PIXEL_FORMAT_SHIFT)) & EPDC_FORMAT_TFT_PIXEL_FORMAT_MASK)

#define EPDC_FORMAT_WB_COMPRESS_MASK             (0x800U)
#define EPDC_FORMAT_WB_COMPRESS_SHIFT            (11U)
#define EPDC_FORMAT_WB_COMPRESS(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_FORMAT_WB_COMPRESS_SHIFT)) & EPDC_FORMAT_WB_COMPRESS_MASK)

#define EPDC_FORMAT_WB_TYPE_MASK                 (0x3000U)
#define EPDC_FORMAT_WB_TYPE_SHIFT                (12U)
/*! WB_TYPE
 *  0b00..internal Working Buffer written by EPDC itself
 *  0b01..working buffer is actually holding waveform
 *  0b10..16bit working buffer written by PXP or CPU
 *  0b11..32bit working buffer written by PXP or CPU
 */
#define EPDC_FORMAT_WB_TYPE(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_FORMAT_WB_TYPE_SHIFT)) & EPDC_FORMAT_WB_TYPE_MASK)

#define EPDC_FORMAT_DEFAULT_TFT_PIXEL_MASK       (0xFF0000U)
#define EPDC_FORMAT_DEFAULT_TFT_PIXEL_SHIFT      (16U)
#define EPDC_FORMAT_DEFAULT_TFT_PIXEL(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_FORMAT_DEFAULT_TFT_PIXEL_SHIFT)) & EPDC_FORMAT_DEFAULT_TFT_PIXEL_MASK)

#define EPDC_FORMAT_BUF_PIXEL_SCALE_MASK         (0x1000000U)
#define EPDC_FORMAT_BUF_PIXEL_SCALE_SHIFT        (24U)
/*! BUF_PIXEL_SCALE
 *  0b0..Use Truncate method (LSB)
 *  0b1..Use rounding method (with saturation)
 */
#define EPDC_FORMAT_BUF_PIXEL_SCALE(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_FORMAT_BUF_PIXEL_SCALE_SHIFT)) & EPDC_FORMAT_BUF_PIXEL_SCALE_MASK)
/*! @} */

/*! @name WB_FIELD0 - Working Buffer Field Setting */
/*! @{ */

#define EPDC_WB_FIELD0_LEN_MASK                  (0xFU)
#define EPDC_WB_FIELD0_LEN_SHIFT                 (0U)
#define EPDC_WB_FIELD0_LEN(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_LEN_SHIFT)) & EPDC_WB_FIELD0_LEN_MASK)

#define EPDC_WB_FIELD0_TO_MASK                   (0xF0U)
#define EPDC_WB_FIELD0_TO_SHIFT                  (4U)
#define EPDC_WB_FIELD0_TO(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_TO_SHIFT)) & EPDC_WB_FIELD0_TO_MASK)

#define EPDC_WB_FIELD0_FROM_MASK                 (0x1F00U)
#define EPDC_WB_FIELD0_FROM_SHIFT                (8U)
#define EPDC_WB_FIELD0_FROM(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_FROM_SHIFT)) & EPDC_WB_FIELD0_FROM_MASK)

#define EPDC_WB_FIELD0_USAGE_MASK                (0xE000U)
#define EPDC_WB_FIELD0_USAGE_SHIFT               (13U)
/*! USAGE
 *  0b000..NOT USED
 *  0b011..PARTIAL (won't contribute to lut lookup index)
 *  0b100..LUT
 *  0b101..CP
 *  0b110..NP
 *  0b111..PTS
 */
#define EPDC_WB_FIELD0_USAGE(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_USAGE_SHIFT)) & EPDC_WB_FIELD0_USAGE_MASK)

#define EPDC_WB_FIELD0_USE_FIXED_MASK            (0x30000U)
#define EPDC_WB_FIELD0_USE_FIXED_SHIFT           (16U)
/*! USE_FIXED
 *  0b00..not using FIXED field
 *  0b01..set this field to a FIXED value which specified by FIXED[31:24]
 *  0b10..mask off this pixel if this field is non equal to FIXED[31:24]
 *  0b11..mask off this pixel if this field is equal to FIXED[31:24]
 */
#define EPDC_WB_FIELD0_USE_FIXED(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_USE_FIXED_SHIFT)) & EPDC_WB_FIELD0_USE_FIXED_MASK)

#define EPDC_WB_FIELD0_FIXED_MASK                (0xFF000000U)
#define EPDC_WB_FIELD0_FIXED_SHIFT               (24U)
#define EPDC_WB_FIELD0_FIXED(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD0_FIXED_SHIFT)) & EPDC_WB_FIELD0_FIXED_MASK)
/*! @} */

/*! @name WB_FIELD1 - Working Buffer Field Setting */
/*! @{ */

#define EPDC_WB_FIELD1_LEN_MASK                  (0xFU)
#define EPDC_WB_FIELD1_LEN_SHIFT                 (0U)
#define EPDC_WB_FIELD1_LEN(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_LEN_SHIFT)) & EPDC_WB_FIELD1_LEN_MASK)

#define EPDC_WB_FIELD1_TO_MASK                   (0xF0U)
#define EPDC_WB_FIELD1_TO_SHIFT                  (4U)
#define EPDC_WB_FIELD1_TO(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_TO_SHIFT)) & EPDC_WB_FIELD1_TO_MASK)

#define EPDC_WB_FIELD1_FROM_MASK                 (0x1F00U)
#define EPDC_WB_FIELD1_FROM_SHIFT                (8U)
#define EPDC_WB_FIELD1_FROM(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_FROM_SHIFT)) & EPDC_WB_FIELD1_FROM_MASK)

#define EPDC_WB_FIELD1_USAGE_MASK                (0xE000U)
#define EPDC_WB_FIELD1_USAGE_SHIFT               (13U)
/*! USAGE
 *  0b000..NOT USED
 *  0b011..PARTIAL
 *  0b100..LUT
 *  0b101..CP
 *  0b110..NP
 *  0b111..PTS
 */
#define EPDC_WB_FIELD1_USAGE(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_USAGE_SHIFT)) & EPDC_WB_FIELD1_USAGE_MASK)

#define EPDC_WB_FIELD1_USE_FIXED_MASK            (0x30000U)
#define EPDC_WB_FIELD1_USE_FIXED_SHIFT           (16U)
/*! USE_FIXED
 *  0b00..not using FIXED field
 *  0b01..set this field to a FIXED value which specified by FIXED[31:24]
 *  0b10..mask off this pixel if this field is non equal to FIXED[31:24]
 *  0b11..mask off this pixel if this field is equal to FIXED[31:24]
 */
#define EPDC_WB_FIELD1_USE_FIXED(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_USE_FIXED_SHIFT)) & EPDC_WB_FIELD1_USE_FIXED_MASK)

#define EPDC_WB_FIELD1_FIXED_MASK                (0xFF000000U)
#define EPDC_WB_FIELD1_FIXED_SHIFT               (24U)
#define EPDC_WB_FIELD1_FIXED(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD1_FIXED_SHIFT)) & EPDC_WB_FIELD1_FIXED_MASK)
/*! @} */

/*! @name WB_FIELD2 - Working Buffer Field Setting */
/*! @{ */

#define EPDC_WB_FIELD2_LEN_MASK                  (0xFU)
#define EPDC_WB_FIELD2_LEN_SHIFT                 (0U)
#define EPDC_WB_FIELD2_LEN(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_LEN_SHIFT)) & EPDC_WB_FIELD2_LEN_MASK)

#define EPDC_WB_FIELD2_TO_MASK                   (0xF0U)
#define EPDC_WB_FIELD2_TO_SHIFT                  (4U)
#define EPDC_WB_FIELD2_TO(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_TO_SHIFT)) & EPDC_WB_FIELD2_TO_MASK)

#define EPDC_WB_FIELD2_FROM_MASK                 (0x1F00U)
#define EPDC_WB_FIELD2_FROM_SHIFT                (8U)
#define EPDC_WB_FIELD2_FROM(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_FROM_SHIFT)) & EPDC_WB_FIELD2_FROM_MASK)

#define EPDC_WB_FIELD2_USAGE_MASK                (0xE000U)
#define EPDC_WB_FIELD2_USAGE_SHIFT               (13U)
/*! USAGE
 *  0b000..NOT USED
 *  0b011..PARTIAL
 *  0b100..LUT
 *  0b101..CP
 *  0b110..NP
 *  0b111..PTS
 */
#define EPDC_WB_FIELD2_USAGE(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_USAGE_SHIFT)) & EPDC_WB_FIELD2_USAGE_MASK)

#define EPDC_WB_FIELD2_USE_FIXED_MASK            (0x30000U)
#define EPDC_WB_FIELD2_USE_FIXED_SHIFT           (16U)
/*! USE_FIXED
 *  0b00..not using FIXED field
 *  0b01..set this field to a FIXED value which specified by FIXED[31:24]
 *  0b10..mask off this pixel if this field is non equal to FIXED[31:24]
 *  0b11..mask off this pixel if this field is equal to FIXED[31:24]
 */
#define EPDC_WB_FIELD2_USE_FIXED(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_USE_FIXED_SHIFT)) & EPDC_WB_FIELD2_USE_FIXED_MASK)

#define EPDC_WB_FIELD2_FIXED_MASK                (0xFF000000U)
#define EPDC_WB_FIELD2_FIXED_SHIFT               (24U)
#define EPDC_WB_FIELD2_FIXED(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD2_FIXED_SHIFT)) & EPDC_WB_FIELD2_FIXED_MASK)
/*! @} */

/*! @name WB_FIELD3 - Working Buffer Field Setting */
/*! @{ */

#define EPDC_WB_FIELD3_LEN_MASK                  (0xFU)
#define EPDC_WB_FIELD3_LEN_SHIFT                 (0U)
#define EPDC_WB_FIELD3_LEN(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_LEN_SHIFT)) & EPDC_WB_FIELD3_LEN_MASK)

#define EPDC_WB_FIELD3_TO_MASK                   (0xF0U)
#define EPDC_WB_FIELD3_TO_SHIFT                  (4U)
#define EPDC_WB_FIELD3_TO(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_TO_SHIFT)) & EPDC_WB_FIELD3_TO_MASK)

#define EPDC_WB_FIELD3_FROM_MASK                 (0x1F00U)
#define EPDC_WB_FIELD3_FROM_SHIFT                (8U)
#define EPDC_WB_FIELD3_FROM(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_FROM_SHIFT)) & EPDC_WB_FIELD3_FROM_MASK)

#define EPDC_WB_FIELD3_USAGE_MASK                (0xE000U)
#define EPDC_WB_FIELD3_USAGE_SHIFT               (13U)
/*! USAGE
 *  0b000..NOT USED
 *  0b011..PARTIAL
 *  0b100..LUT
 *  0b101..CP
 *  0b110..NP
 *  0b111..PTS
 */
#define EPDC_WB_FIELD3_USAGE(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_USAGE_SHIFT)) & EPDC_WB_FIELD3_USAGE_MASK)

#define EPDC_WB_FIELD3_USE_FIXED_MASK            (0x30000U)
#define EPDC_WB_FIELD3_USE_FIXED_SHIFT           (16U)
/*! USE_FIXED
 *  0b00..not using FIXED field
 *  0b01..set this field to a FIXED value which specified by FIXED[31:24]
 *  0b10..mask off this pixel if this field is non equal to FIXED[31:24]
 *  0b11..mask off this pixel if this field is equal to FIXED[31:24]
 */
#define EPDC_WB_FIELD3_USE_FIXED(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_USE_FIXED_SHIFT)) & EPDC_WB_FIELD3_USE_FIXED_MASK)

#define EPDC_WB_FIELD3_FIXED_MASK                (0xFF000000U)
#define EPDC_WB_FIELD3_FIXED_SHIFT               (24U)
#define EPDC_WB_FIELD3_FIXED(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_WB_FIELD3_FIXED_SHIFT)) & EPDC_WB_FIELD3_FIXED_MASK)
/*! @} */

/*! @name FIFOCTRL - FIFO control register */
/*! @{ */

#define EPDC_FIFOCTRL_FIFO_L_LEVEL_MASK          (0x3FFU)
#define EPDC_FIFOCTRL_FIFO_L_LEVEL_SHIFT         (0U)
#define EPDC_FIFOCTRL_FIFO_L_LEVEL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_FIFOCTRL_FIFO_L_LEVEL_SHIFT)) & EPDC_FIFOCTRL_FIFO_L_LEVEL_MASK)

#define EPDC_FIFOCTRL_FIFO_H_LEVEL_MASK          (0xFFC00U)
#define EPDC_FIFOCTRL_FIFO_H_LEVEL_SHIFT         (10U)
#define EPDC_FIFOCTRL_FIFO_H_LEVEL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_FIFOCTRL_FIFO_H_LEVEL_SHIFT)) & EPDC_FIFOCTRL_FIFO_H_LEVEL_MASK)

#define EPDC_FIFOCTRL_FIFO_INIT_LEVEL_MASK       (0x3FF00000U)
#define EPDC_FIFOCTRL_FIFO_INIT_LEVEL_SHIFT      (20U)
#define EPDC_FIFOCTRL_FIFO_INIT_LEVEL(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_FIFOCTRL_FIFO_INIT_LEVEL_SHIFT)) & EPDC_FIFOCTRL_FIFO_INIT_LEVEL_MASK)

#define EPDC_FIFOCTRL_ENABLE_PRIORITY_MASK       (0x80000000U)
#define EPDC_FIFOCTRL_ENABLE_PRIORITY_SHIFT      (31U)
#define EPDC_FIFOCTRL_ENABLE_PRIORITY(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_FIFOCTRL_ENABLE_PRIORITY_SHIFT)) & EPDC_FIFOCTRL_ENABLE_PRIORITY_MASK)
/*! @} */

/*! @name UPD_ADDR - Update Region Address */
/*! @{ */

#define EPDC_UPD_ADDR_ADDR_MASK                  (0xFFFFFFFFU)
#define EPDC_UPD_ADDR_ADDR_SHIFT                 (0U)
#define EPDC_UPD_ADDR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_ADDR_ADDR_SHIFT)) & EPDC_UPD_ADDR_ADDR_MASK)
/*! @} */

/*! @name UPD_STRIDE - Update Region Stride */
/*! @{ */

#define EPDC_UPD_STRIDE_STRIDE_MASK              (0xFFFFFFFFU)
#define EPDC_UPD_STRIDE_STRIDE_SHIFT             (0U)
#define EPDC_UPD_STRIDE_STRIDE(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_STRIDE_STRIDE_SHIFT)) & EPDC_UPD_STRIDE_STRIDE_MASK)
/*! @} */

/*! @name UPD_CORD - Update Command Co-ordinate */
/*! @{ */

#define EPDC_UPD_CORD_XCORD_MASK                 (0x1FFFU)
#define EPDC_UPD_CORD_XCORD_SHIFT                (0U)
#define EPDC_UPD_CORD_XCORD(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CORD_XCORD_SHIFT)) & EPDC_UPD_CORD_XCORD_MASK)

#define EPDC_UPD_CORD_YCORD_MASK                 (0x1FFF0000U)
#define EPDC_UPD_CORD_YCORD_SHIFT                (16U)
#define EPDC_UPD_CORD_YCORD(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CORD_YCORD_SHIFT)) & EPDC_UPD_CORD_YCORD_MASK)
/*! @} */

/*! @name UPD_SIZE - Update Command Size */
/*! @{ */

#define EPDC_UPD_SIZE_WIDTH_MASK                 (0x1FFFU)
#define EPDC_UPD_SIZE_WIDTH_SHIFT                (0U)
#define EPDC_UPD_SIZE_WIDTH(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_SIZE_WIDTH_SHIFT)) & EPDC_UPD_SIZE_WIDTH_MASK)

#define EPDC_UPD_SIZE_HEIGHT_MASK                (0x1FFF0000U)
#define EPDC_UPD_SIZE_HEIGHT_SHIFT               (16U)
#define EPDC_UPD_SIZE_HEIGHT(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_SIZE_HEIGHT_SHIFT)) & EPDC_UPD_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name UPD_CTRL - Update Command Control */
/*! @{ */

#define EPDC_UPD_CTRL_UPDATE_MODE_MASK           (0x1U)
#define EPDC_UPD_CTRL_UPDATE_MODE_SHIFT          (0U)
/*! UPDATE_MODE
 *  0b0..Partial Update : only process changed pixels in region
 *  0b1..Full Update : process all pixels in region
 */
#define EPDC_UPD_CTRL_UPDATE_MODE(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_UPDATE_MODE_SHIFT)) & EPDC_UPD_CTRL_UPDATE_MODE_MASK)

#define EPDC_UPD_CTRL_DRY_RUN_MASK               (0x2U)
#define EPDC_UPD_CTRL_DRY_RUN_SHIFT              (1U)
#define EPDC_UPD_CTRL_DRY_RUN(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_DRY_RUN_SHIFT)) & EPDC_UPD_CTRL_DRY_RUN_MASK)

#define EPDC_UPD_CTRL_AUTOWV_MASK                (0x4U)
#define EPDC_UPD_CTRL_AUTOWV_SHIFT               (2U)
#define EPDC_UPD_CTRL_AUTOWV(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_AUTOWV_SHIFT)) & EPDC_UPD_CTRL_AUTOWV_MASK)

#define EPDC_UPD_CTRL_PAUSE_MASK                 (0x8U)
#define EPDC_UPD_CTRL_PAUSE_SHIFT                (3U)
/*! PAUSE
 *  0b0..will analyze update buffer, report histogram, then update waveform mode using the programmed mode mapping
 *       in AUTOWV_LUT and start LUT loading
 *  0b1..EPDC analyzes and updates buffer, reports histogram, then pauses and waits for the software to write
 *       again with selected waveform mode to start lut loading
 */
#define EPDC_UPD_CTRL_PAUSE(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_PAUSE_SHIFT)) & EPDC_UPD_CTRL_PAUSE_MASK)

#define EPDC_UPD_CTRL_NO_LUT_CANCEL_MASK         (0x10U)
#define EPDC_UPD_CTRL_NO_LUT_CANCEL_SHIFT        (4U)
#define EPDC_UPD_CTRL_NO_LUT_CANCEL(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_NO_LUT_CANCEL_SHIFT)) & EPDC_UPD_CTRL_NO_LUT_CANCEL_MASK)

#define EPDC_UPD_CTRL_STANDBY_MASK               (0x20U)
#define EPDC_UPD_CTRL_STANDBY_SHIFT              (5U)
#define EPDC_UPD_CTRL_STANDBY(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_STANDBY_SHIFT)) & EPDC_UPD_CTRL_STANDBY_MASK)

#define EPDC_UPD_CTRL_WAVEFORM_MODE_MASK         (0xFF00U)
#define EPDC_UPD_CTRL_WAVEFORM_MODE_SHIFT        (8U)
#define EPDC_UPD_CTRL_WAVEFORM_MODE(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_WAVEFORM_MODE_SHIFT)) & EPDC_UPD_CTRL_WAVEFORM_MODE_MASK)

#define EPDC_UPD_CTRL_LUT_SEL_MASK               (0x3F0000U)
#define EPDC_UPD_CTRL_LUT_SEL_SHIFT              (16U)
#define EPDC_UPD_CTRL_LUT_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_LUT_SEL_SHIFT)) & EPDC_UPD_CTRL_LUT_SEL_MASK)

#define EPDC_UPD_CTRL_USE_FIXED_MASK             (0x80000000U)
#define EPDC_UPD_CTRL_USE_FIXED_SHIFT            (31U)
#define EPDC_UPD_CTRL_USE_FIXED(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_CTRL_USE_FIXED_SHIFT)) & EPDC_UPD_CTRL_USE_FIXED_MASK)
/*! @} */

/*! @name UPD_FIXED - Update Fixed Pixel Control */
/*! @{ */

#define EPDC_UPD_FIXED_FIXCP_MASK                (0xFFU)
#define EPDC_UPD_FIXED_FIXCP_SHIFT               (0U)
#define EPDC_UPD_FIXED_FIXCP(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_FIXED_FIXCP_SHIFT)) & EPDC_UPD_FIXED_FIXCP_MASK)

#define EPDC_UPD_FIXED_FIXNP_MASK                (0xFF00U)
#define EPDC_UPD_FIXED_FIXNP_SHIFT               (8U)
#define EPDC_UPD_FIXED_FIXNP(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_FIXED_FIXNP_SHIFT)) & EPDC_UPD_FIXED_FIXNP_MASK)

#define EPDC_UPD_FIXED_FIXCP_EN_MASK             (0x40000000U)
#define EPDC_UPD_FIXED_FIXCP_EN_SHIFT            (30U)
#define EPDC_UPD_FIXED_FIXCP_EN(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_FIXED_FIXCP_EN_SHIFT)) & EPDC_UPD_FIXED_FIXCP_EN_MASK)

#define EPDC_UPD_FIXED_FIXNP_EN_MASK             (0x80000000U)
#define EPDC_UPD_FIXED_FIXNP_EN_SHIFT            (31U)
#define EPDC_UPD_FIXED_FIXNP_EN(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_FIXED_FIXNP_EN_SHIFT)) & EPDC_UPD_FIXED_FIXNP_EN_MASK)
/*! @} */

/*! @name TEMP - Temperature Register */
/*! @{ */

#define EPDC_TEMP_TEMPERATURE_MASK               (0xFFFFFFFFU)
#define EPDC_TEMP_TEMPERATURE_SHIFT              (0U)
#define EPDC_TEMP_TEMPERATURE(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_TEMP_TEMPERATURE_SHIFT)) & EPDC_TEMP_TEMPERATURE_MASK)
/*! @} */

/*! @name AUTOWV_LUT - Waveform Mode Lookup Table Control Register. */
/*! @{ */

#define EPDC_AUTOWV_LUT_ADDR_MASK                (0x7U)
#define EPDC_AUTOWV_LUT_ADDR_SHIFT               (0U)
#define EPDC_AUTOWV_LUT_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_AUTOWV_LUT_ADDR_SHIFT)) & EPDC_AUTOWV_LUT_ADDR_MASK)

#define EPDC_AUTOWV_LUT_DATA_MASK                (0xFF0000U)
#define EPDC_AUTOWV_LUT_DATA_SHIFT               (16U)
#define EPDC_AUTOWV_LUT_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_AUTOWV_LUT_DATA_SHIFT)) & EPDC_AUTOWV_LUT_DATA_MASK)
/*! @} */

/*! @name LUT_STANDBY1 - LUT Standby Register - LUT 31~0 */
/*! @{ */

#define EPDC_LUT_STANDBY1_LUTN_MASK              (0xFFFFFFFFU)
#define EPDC_LUT_STANDBY1_LUTN_SHIFT             (0U)
#define EPDC_LUT_STANDBY1_LUTN(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_LUT_STANDBY1_LUTN_SHIFT)) & EPDC_LUT_STANDBY1_LUTN_MASK)
/*! @} */

/*! @name LUT_STANDBY2 - LUT Standby Register - LUT 63~32 */
/*! @{ */

#define EPDC_LUT_STANDBY2_LUTN_MASK              (0xFFFFFFFFU)
#define EPDC_LUT_STANDBY2_LUTN_SHIFT             (0U)
#define EPDC_LUT_STANDBY2_LUTN(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_LUT_STANDBY2_LUTN_SHIFT)) & EPDC_LUT_STANDBY2_LUTN_MASK)
/*! @} */

/*! @name TCE_CTRL - Timing Control Engine Control Register */
/*! @{ */

#define EPDC_TCE_CTRL_PIXELS_PER_SDCLK_MASK      (0x3U)
#define EPDC_TCE_CTRL_PIXELS_PER_SDCLK_SHIFT     (0U)
/*! PIXELS_PER_SDCLK
 *  0b00..Reserved
 *  0b01..Two TFT-pixels per SDCLK
 *  0b10..Four TFT-pixels per SDCLK
 *  0b11..Eight TFT-pixels per SDCLK
 */
#define EPDC_TCE_CTRL_PIXELS_PER_SDCLK(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_PIXELS_PER_SDCLK_SHIFT)) & EPDC_TCE_CTRL_PIXELS_PER_SDCLK_MASK)

#define EPDC_TCE_CTRL_SDDO_WIDTH_MASK            (0x4U)
#define EPDC_TCE_CTRL_SDDO_WIDTH_SHIFT           (2U)
/*! SDDO_WIDTH
 *  0b0..Connect to 8-bit source driver
 *  0b1..Connct to 16-bit source driver
 */
#define EPDC_TCE_CTRL_SDDO_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_SDDO_WIDTH_SHIFT)) & EPDC_TCE_CTRL_SDDO_WIDTH_MASK)

#define EPDC_TCE_CTRL_DUAL_SCAN_MASK             (0x8U)
#define EPDC_TCE_CTRL_DUAL_SCAN_SHIFT            (3U)
#define EPDC_TCE_CTRL_DUAL_SCAN(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_DUAL_SCAN_SHIFT)) & EPDC_TCE_CTRL_DUAL_SCAN_MASK)

#define EPDC_TCE_CTRL_SCAN_DIR_0_MASK            (0x10U)
#define EPDC_TCE_CTRL_SCAN_DIR_0_SHIFT           (4U)
/*! SCAN_DIR_0
 *  0b0..Scan this region from top to bottom
 *  0b1..Scan this region from bottom to top
 */
#define EPDC_TCE_CTRL_SCAN_DIR_0(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_SCAN_DIR_0_SHIFT)) & EPDC_TCE_CTRL_SCAN_DIR_0_MASK)

#define EPDC_TCE_CTRL_SCAN_DIR_1_MASK            (0x20U)
#define EPDC_TCE_CTRL_SCAN_DIR_1_SHIFT           (5U)
/*! SCAN_DIR_1
 *  0b0..Scan this region from top to bottom
 *  0b1..Scan this region from bottom to top
 */
#define EPDC_TCE_CTRL_SCAN_DIR_1(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_SCAN_DIR_1_SHIFT)) & EPDC_TCE_CTRL_SCAN_DIR_1_MASK)

#define EPDC_TCE_CTRL_LVDS_MODE_MASK             (0x40U)
#define EPDC_TCE_CTRL_LVDS_MODE_SHIFT            (6U)
#define EPDC_TCE_CTRL_LVDS_MODE(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_LVDS_MODE_SHIFT)) & EPDC_TCE_CTRL_LVDS_MODE_MASK)

#define EPDC_TCE_CTRL_LVDS_MODE_CE_MASK          (0x80U)
#define EPDC_TCE_CTRL_LVDS_MODE_CE_SHIFT         (7U)
#define EPDC_TCE_CTRL_LVDS_MODE_CE(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_LVDS_MODE_CE_SHIFT)) & EPDC_TCE_CTRL_LVDS_MODE_CE_MASK)

#define EPDC_TCE_CTRL_DDR_MODE_MASK              (0x100U)
#define EPDC_TCE_CTRL_DDR_MODE_SHIFT             (8U)
#define EPDC_TCE_CTRL_DDR_MODE(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_DDR_MODE_SHIFT)) & EPDC_TCE_CTRL_DDR_MODE_MASK)

#define EPDC_TCE_CTRL_VCOM_MODE_MASK             (0x200U)
#define EPDC_TCE_CTRL_VCOM_MODE_SHIFT            (9U)
/*! VCOM_MODE
 *  0b0..VCOM Value is set manually using VCOM_VAL field
 *  0b1..VCOM Value is used from waveform
 */
#define EPDC_TCE_CTRL_VCOM_MODE(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_VCOM_MODE_SHIFT)) & EPDC_TCE_CTRL_VCOM_MODE_MASK)

#define EPDC_TCE_CTRL_VCOM_VAL_MASK              (0xC00U)
#define EPDC_TCE_CTRL_VCOM_VAL_SHIFT             (10U)
#define EPDC_TCE_CTRL_VCOM_VAL(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_VCOM_VAL_SHIFT)) & EPDC_TCE_CTRL_VCOM_VAL_MASK)

#define EPDC_TCE_CTRL_WB_EXTERNAL_RANGE_EN_MASK  (0x1000U)
#define EPDC_TCE_CTRL_WB_EXTERNAL_RANGE_EN_SHIFT (12U)
#define EPDC_TCE_CTRL_WB_EXTERNAL_RANGE_EN(x)    (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_WB_EXTERNAL_RANGE_EN_SHIFT)) & EPDC_TCE_CTRL_WB_EXTERNAL_RANGE_EN_MASK)

#define EPDC_TCE_CTRL_UNDERRUN_LOOKUP_MASK_EN_MASK (0x2000U)
#define EPDC_TCE_CTRL_UNDERRUN_LOOKUP_MASK_EN_SHIFT (13U)
#define EPDC_TCE_CTRL_UNDERRUN_LOOKUP_MASK_EN(x) (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_UNDERRUN_LOOKUP_MASK_EN_SHIFT)) & EPDC_TCE_CTRL_UNDERRUN_LOOKUP_MASK_EN_MASK)

#define EPDC_TCE_CTRL_VSCAN_HOLDOFF_MASK         (0x1FF0000U)
#define EPDC_TCE_CTRL_VSCAN_HOLDOFF_SHIFT        (16U)
#define EPDC_TCE_CTRL_VSCAN_HOLDOFF(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_CTRL_VSCAN_HOLDOFF_SHIFT)) & EPDC_TCE_CTRL_VSCAN_HOLDOFF_MASK)
/*! @} */

/*! @name TCE_SDCFG - Timing Control Engine Source-Driver Config Register */
/*! @{ */

#define EPDC_TCE_SDCFG_PIXELS_PER_CE_MASK        (0x1FFFU)
#define EPDC_TCE_SDCFG_PIXELS_PER_CE_SHIFT       (0U)
#define EPDC_TCE_SDCFG_PIXELS_PER_CE(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_PIXELS_PER_CE_SHIFT)) & EPDC_TCE_SDCFG_PIXELS_PER_CE_MASK)

#define EPDC_TCE_SDCFG_SDDO_INVERT_MASK          (0x2000U)
#define EPDC_TCE_SDCFG_SDDO_INVERT_SHIFT         (13U)
#define EPDC_TCE_SDCFG_SDDO_INVERT(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_SDDO_INVERT_SHIFT)) & EPDC_TCE_SDCFG_SDDO_INVERT_MASK)

#define EPDC_TCE_SDCFG_SDDO_REFORMAT_MASK        (0xC000U)
#define EPDC_TCE_SDCFG_SDDO_REFORMAT_SHIFT       (14U)
/*! SDDO_REFORMAT
 *  0b00..No change.
 *  0b01..Reverses the order of the pixels on SDDO. This register setting is sensitive to the TFT pixel width
 *        (TFT_PIXEL_FORMAT), e.g. for TFT_PIXEL_FORMAT=2B on an 8-bit bus P3,P2,P1,P0 becomes P0,P1,P2,P3, whereas
 *        with TFT_PIXEL_FORMAT=4B, on an 8-bit bus, P1,P0 becomes P0,P1
 */
#define EPDC_TCE_SDCFG_SDDO_REFORMAT(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_SDDO_REFORMAT_SHIFT)) & EPDC_TCE_SDCFG_SDDO_REFORMAT_MASK)

#define EPDC_TCE_SDCFG_NUM_CE_MASK               (0xF0000U)
#define EPDC_TCE_SDCFG_NUM_CE_SHIFT              (16U)
#define EPDC_TCE_SDCFG_NUM_CE(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_NUM_CE_SHIFT)) & EPDC_TCE_SDCFG_NUM_CE_MASK)

#define EPDC_TCE_SDCFG_SDSHR_MASK                (0x100000U)
#define EPDC_TCE_SDCFG_SDSHR_SHIFT               (20U)
#define EPDC_TCE_SDCFG_SDSHR(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_SDSHR_SHIFT)) & EPDC_TCE_SDCFG_SDSHR_MASK)

#define EPDC_TCE_SDCFG_SDCLK_HOLD_MASK           (0x200000U)
#define EPDC_TCE_SDCFG_SDCLK_HOLD_SHIFT          (21U)
#define EPDC_TCE_SDCFG_SDCLK_HOLD(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_SDCFG_SDCLK_HOLD_SHIFT)) & EPDC_TCE_SDCFG_SDCLK_HOLD_MASK)
/*! @} */

/*! @name TCE_GDCFG - Timing Control Engine Gate-Driver Config Register */
/*! @{ */

#define EPDC_TCE_GDCFG_GDSP_MODE_MASK            (0x1U)
#define EPDC_TCE_GDCFG_GDSP_MODE_SHIFT           (0U)
#define EPDC_TCE_GDCFG_GDSP_MODE(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_GDCFG_GDSP_MODE_SHIFT)) & EPDC_TCE_GDCFG_GDSP_MODE_MASK)

#define EPDC_TCE_GDCFG_GDOE_MODE_MASK            (0x2U)
#define EPDC_TCE_GDCFG_GDOE_MODE_SHIFT           (1U)
#define EPDC_TCE_GDCFG_GDOE_MODE(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_GDCFG_GDOE_MODE_SHIFT)) & EPDC_TCE_GDCFG_GDOE_MODE_MASK)

#define EPDC_TCE_GDCFG_GDRL_MASK                 (0x10U)
#define EPDC_TCE_GDCFG_GDRL_SHIFT                (4U)
#define EPDC_TCE_GDCFG_GDRL(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_GDCFG_GDRL_SHIFT)) & EPDC_TCE_GDCFG_GDRL_MASK)

#define EPDC_TCE_GDCFG_PERIOD_VSCAN_MASK         (0xFFFF0000U)
#define EPDC_TCE_GDCFG_PERIOD_VSCAN_SHIFT        (16U)
#define EPDC_TCE_GDCFG_PERIOD_VSCAN(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_GDCFG_PERIOD_VSCAN_SHIFT)) & EPDC_TCE_GDCFG_PERIOD_VSCAN_MASK)
/*! @} */

/*! @name TCE_HSCAN1 - Timing Control Engine Horizontal Timing Register 1 */
/*! @{ */

#define EPDC_TCE_HSCAN1_LINE_SYNC_MASK           (0xFFFU)
#define EPDC_TCE_HSCAN1_LINE_SYNC_SHIFT          (0U)
#define EPDC_TCE_HSCAN1_LINE_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_HSCAN1_LINE_SYNC_SHIFT)) & EPDC_TCE_HSCAN1_LINE_SYNC_MASK)

#define EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_MASK     (0xFFF0000U)
#define EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_SHIFT    (16U)
#define EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_SHIFT)) & EPDC_TCE_HSCAN1_LINE_SYNC_WIDTH_MASK)
/*! @} */

/*! @name TCE_HSCAN2 - Timing Control Engine Horizontal Timing Register 2 */
/*! @{ */

#define EPDC_TCE_HSCAN2_LINE_BEGIN_MASK          (0xFFFU)
#define EPDC_TCE_HSCAN2_LINE_BEGIN_SHIFT         (0U)
#define EPDC_TCE_HSCAN2_LINE_BEGIN(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_HSCAN2_LINE_BEGIN_SHIFT)) & EPDC_TCE_HSCAN2_LINE_BEGIN_MASK)

#define EPDC_TCE_HSCAN2_LINE_END_MASK            (0xFFF0000U)
#define EPDC_TCE_HSCAN2_LINE_END_SHIFT           (16U)
#define EPDC_TCE_HSCAN2_LINE_END(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_HSCAN2_LINE_END_SHIFT)) & EPDC_TCE_HSCAN2_LINE_END_MASK)
/*! @} */

/*! @name TCE_VSCAN - Timing Control Engine Vertical Timing Register */
/*! @{ */

#define EPDC_TCE_VSCAN_FRAME_SYNC_MASK           (0xFFU)
#define EPDC_TCE_VSCAN_FRAME_SYNC_SHIFT          (0U)
#define EPDC_TCE_VSCAN_FRAME_SYNC(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_VSCAN_FRAME_SYNC_SHIFT)) & EPDC_TCE_VSCAN_FRAME_SYNC_MASK)

#define EPDC_TCE_VSCAN_FRAME_BEGIN_MASK          (0xFF00U)
#define EPDC_TCE_VSCAN_FRAME_BEGIN_SHIFT         (8U)
#define EPDC_TCE_VSCAN_FRAME_BEGIN(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_VSCAN_FRAME_BEGIN_SHIFT)) & EPDC_TCE_VSCAN_FRAME_BEGIN_MASK)

#define EPDC_TCE_VSCAN_FRAME_END_MASK            (0xFF0000U)
#define EPDC_TCE_VSCAN_FRAME_END_SHIFT           (16U)
#define EPDC_TCE_VSCAN_FRAME_END(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_VSCAN_FRAME_END_SHIFT)) & EPDC_TCE_VSCAN_FRAME_END_MASK)
/*! @} */

/*! @name TCE_OE - Timing Control Engine OE timing control Register */
/*! @{ */

#define EPDC_TCE_OE_SDOEZ_DLY_MASK               (0xFFU)
#define EPDC_TCE_OE_SDOEZ_DLY_SHIFT              (0U)
#define EPDC_TCE_OE_SDOEZ_DLY(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_OE_SDOEZ_DLY_SHIFT)) & EPDC_TCE_OE_SDOEZ_DLY_MASK)

#define EPDC_TCE_OE_SDOEZ_WIDTH_MASK             (0xFF00U)
#define EPDC_TCE_OE_SDOEZ_WIDTH_SHIFT            (8U)
#define EPDC_TCE_OE_SDOEZ_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_OE_SDOEZ_WIDTH_SHIFT)) & EPDC_TCE_OE_SDOEZ_WIDTH_MASK)

#define EPDC_TCE_OE_SDOED_DLY_MASK               (0xFF0000U)
#define EPDC_TCE_OE_SDOED_DLY_SHIFT              (16U)
#define EPDC_TCE_OE_SDOED_DLY(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_OE_SDOED_DLY_SHIFT)) & EPDC_TCE_OE_SDOED_DLY_MASK)

#define EPDC_TCE_OE_SDOED_WIDTH_MASK             (0xFF000000U)
#define EPDC_TCE_OE_SDOED_WIDTH_SHIFT            (24U)
#define EPDC_TCE_OE_SDOED_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_OE_SDOED_WIDTH_SHIFT)) & EPDC_TCE_OE_SDOED_WIDTH_MASK)
/*! @} */

/*! @name TCE_POLARITY - Timing Control Engine Driver Polarity Register */
/*! @{ */

#define EPDC_TCE_POLARITY_SDCE_POL_MASK          (0x1U)
#define EPDC_TCE_POLARITY_SDCE_POL_SHIFT         (0U)
#define EPDC_TCE_POLARITY_SDCE_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_POLARITY_SDCE_POL_SHIFT)) & EPDC_TCE_POLARITY_SDCE_POL_MASK)

#define EPDC_TCE_POLARITY_SDLE_POL_MASK          (0x2U)
#define EPDC_TCE_POLARITY_SDLE_POL_SHIFT         (1U)
#define EPDC_TCE_POLARITY_SDLE_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_POLARITY_SDLE_POL_SHIFT)) & EPDC_TCE_POLARITY_SDLE_POL_MASK)

#define EPDC_TCE_POLARITY_SDOE_POL_MASK          (0x4U)
#define EPDC_TCE_POLARITY_SDOE_POL_SHIFT         (2U)
#define EPDC_TCE_POLARITY_SDOE_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_POLARITY_SDOE_POL_SHIFT)) & EPDC_TCE_POLARITY_SDOE_POL_MASK)

#define EPDC_TCE_POLARITY_GDOE_POL_MASK          (0x8U)
#define EPDC_TCE_POLARITY_GDOE_POL_SHIFT         (3U)
#define EPDC_TCE_POLARITY_GDOE_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_POLARITY_GDOE_POL_SHIFT)) & EPDC_TCE_POLARITY_GDOE_POL_MASK)

#define EPDC_TCE_POLARITY_GDSP_POL_MASK          (0x10U)
#define EPDC_TCE_POLARITY_GDSP_POL_SHIFT         (4U)
#define EPDC_TCE_POLARITY_GDSP_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_POLARITY_GDSP_POL_SHIFT)) & EPDC_TCE_POLARITY_GDSP_POL_MASK)
/*! @} */

/*! @name TCE_TIMING1 - Timing Control Engine Timing Register 1 */
/*! @{ */

#define EPDC_TCE_TIMING1_SDCLK_SHIFT_MASK        (0x3U)
#define EPDC_TCE_TIMING1_SDCLK_SHIFT_SHIFT       (0U)
/*! SDCLK_SHIFT
 *  0b00..No shift of SDCLK
 *  0b01..Shift SDCLK 1 pixclk cycle
 *  0b10..Shift SDCLK 2 pixclk cycles
 *  0b11..Shift SDCLK 3 pixclk cycles
 */
#define EPDC_TCE_TIMING1_SDCLK_SHIFT(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING1_SDCLK_SHIFT_SHIFT)) & EPDC_TCE_TIMING1_SDCLK_SHIFT_MASK)

#define EPDC_TCE_TIMING1_SDCLK_INVERT_MASK       (0x8U)
#define EPDC_TCE_TIMING1_SDCLK_INVERT_SHIFT      (3U)
#define EPDC_TCE_TIMING1_SDCLK_INVERT(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING1_SDCLK_INVERT_SHIFT)) & EPDC_TCE_TIMING1_SDCLK_INVERT_MASK)

#define EPDC_TCE_TIMING1_SDLE_SHIFT_MASK         (0x30U)
#define EPDC_TCE_TIMING1_SDLE_SHIFT_SHIFT        (4U)
/*! SDLE_SHIFT
 *  0b00..No shift of SDLE
 *  0b01..Shift SDLE 1 pixclk cycle
 *  0b10..Shift SDLE 2 pixclk cycles
 *  0b11..Shift SDLE 3 pixclk cycles
 */
#define EPDC_TCE_TIMING1_SDLE_SHIFT(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING1_SDLE_SHIFT_SHIFT)) & EPDC_TCE_TIMING1_SDLE_SHIFT_MASK)
/*! @} */

/*! @name TCE_TIMING2 - Timing Control Engine Timing Register 2 */
/*! @{ */

#define EPDC_TCE_TIMING2_GDSP_OFFSET_MASK        (0xFFFFU)
#define EPDC_TCE_TIMING2_GDSP_OFFSET_SHIFT       (0U)
#define EPDC_TCE_TIMING2_GDSP_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING2_GDSP_OFFSET_SHIFT)) & EPDC_TCE_TIMING2_GDSP_OFFSET_MASK)

#define EPDC_TCE_TIMING2_GDCLK_HP_MASK           (0xFFFF0000U)
#define EPDC_TCE_TIMING2_GDCLK_HP_SHIFT          (16U)
#define EPDC_TCE_TIMING2_GDCLK_HP(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING2_GDCLK_HP_SHIFT)) & EPDC_TCE_TIMING2_GDCLK_HP_MASK)
/*! @} */

/*! @name TCE_TIMING3 - Timing Control Engine Timing Register 3 */
/*! @{ */

#define EPDC_TCE_TIMING3_GDCLK_OFFSET_MASK       (0xFFFFU)
#define EPDC_TCE_TIMING3_GDCLK_OFFSET_SHIFT      (0U)
#define EPDC_TCE_TIMING3_GDCLK_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING3_GDCLK_OFFSET_SHIFT)) & EPDC_TCE_TIMING3_GDCLK_OFFSET_MASK)

#define EPDC_TCE_TIMING3_GDOE_OFFSET_MASK        (0xFFFF0000U)
#define EPDC_TCE_TIMING3_GDOE_OFFSET_SHIFT       (16U)
#define EPDC_TCE_TIMING3_GDOE_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_TCE_TIMING3_GDOE_OFFSET_SHIFT)) & EPDC_TCE_TIMING3_GDOE_OFFSET_MASK)
/*! @} */

/*! @name PIGEON_CTRL0 - Pigeon Mode Control Register 0 */
/*! @{ */

#define EPDC_PIGEON_CTRL0_FD_PERIOD_MASK         (0xFFFU)
#define EPDC_PIGEON_CTRL0_FD_PERIOD_SHIFT        (0U)
#define EPDC_PIGEON_CTRL0_FD_PERIOD(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_CTRL0_FD_PERIOD_SHIFT)) & EPDC_PIGEON_CTRL0_FD_PERIOD_MASK)

#define EPDC_PIGEON_CTRL0_LD_PERIOD_MASK         (0xFFF0000U)
#define EPDC_PIGEON_CTRL0_LD_PERIOD_SHIFT        (16U)
#define EPDC_PIGEON_CTRL0_LD_PERIOD(x)           (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_CTRL0_LD_PERIOD_SHIFT)) & EPDC_PIGEON_CTRL0_LD_PERIOD_MASK)
/*! @} */

/*! @name PIGEON_CTRL1 - Pigeon Mode Control Register 1 */
/*! @{ */

#define EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD_MASK  (0xFFFU)
#define EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD_SHIFT (0U)
#define EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD(x)    (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD_SHIFT)) & EPDC_PIGEON_CTRL1_FRAME_CNT_PERIOD_MASK)

#define EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES_MASK  (0xFFF0000U)
#define EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES_SHIFT (16U)
#define EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES(x)    (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES_SHIFT)) & EPDC_PIGEON_CTRL1_FRAME_CNT_CYCLES_MASK)
/*! @} */

/*! @name IRQ_MASK1 - IRQ Mask Register - LUT 0~31 */
/*! @{ */

#define EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN_MASK    (0xFFFFFFFFU)
#define EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN_SHIFT   (0U)
#define EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK1_LUTN_CMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name IRQ_MASK2 - IRQ Mask Register - LUT 32~63 */
/*! @{ */

#define EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN_MASK    (0xFFFFFFFFU)
#define EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN_SHIFT   (0U)
#define EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK2_LUTN_CMPLT_IRQ_EN_MASK)
/*! @} */

/*! @name IRQ1 - Interrupt Register - LUT 0~31 */
/*! @{ */

#define EPDC_IRQ1_LUTN_CMPLT_IRQ_MASK            (0xFFFFFFFFU)
#define EPDC_IRQ1_LUTN_CMPLT_IRQ_SHIFT           (0U)
#define EPDC_IRQ1_LUTN_CMPLT_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ1_LUTN_CMPLT_IRQ_SHIFT)) & EPDC_IRQ1_LUTN_CMPLT_IRQ_MASK)
/*! @} */

/*! @name IRQ2 - Interrupt Register - LUT 32~63 */
/*! @{ */

#define EPDC_IRQ2_LUTN_CMPLT_IRQ_MASK            (0xFFFFFFFFU)
#define EPDC_IRQ2_LUTN_CMPLT_IRQ_SHIFT           (0U)
#define EPDC_IRQ2_LUTN_CMPLT_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ2_LUTN_CMPLT_IRQ_SHIFT)) & EPDC_IRQ2_LUTN_CMPLT_IRQ_MASK)
/*! @} */

/*! @name IRQ_MASK - IRQ Mask Register */
/*! @{ */

#define EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN_MASK       (0x10000U)
#define EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN_SHIFT      (16U)
#define EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_WB_CMPLT_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_COL_IRQ_EN_MASK            (0x20000U)
#define EPDC_IRQ_MASK_COL_IRQ_EN_SHIFT           (17U)
#define EPDC_IRQ_MASK_COL_IRQ_EN(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_COL_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_COL_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN_MASK   (0x40000U)
#define EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN_SHIFT  (18U)
#define EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_TCE_UNDERRUN_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_FRAME_END_IRQ_EN_MASK      (0x80000U)
#define EPDC_IRQ_MASK_FRAME_END_IRQ_EN_SHIFT     (19U)
#define EPDC_IRQ_MASK_FRAME_END_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_FRAME_END_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_FRAME_END_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN_MASK      (0x100000U)
#define EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN_SHIFT     (20U)
#define EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_BUS_ERROR_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN_MASK       (0x200000U)
#define EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN_SHIFT      (21U)
#define EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_TCE_IDLE_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_UPD_DONE_IRQ_EN_MASK       (0x400000U)
#define EPDC_IRQ_MASK_UPD_DONE_IRQ_EN_SHIFT      (22U)
#define EPDC_IRQ_MASK_UPD_DONE_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_UPD_DONE_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_UPD_DONE_IRQ_EN_MASK)

#define EPDC_IRQ_MASK_PWR_IRQ_EN_MASK            (0x800000U)
#define EPDC_IRQ_MASK_PWR_IRQ_EN_SHIFT           (23U)
#define EPDC_IRQ_MASK_PWR_IRQ_EN(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_MASK_PWR_IRQ_EN_SHIFT)) & EPDC_IRQ_MASK_PWR_IRQ_EN_MASK)
/*! @} */

/*! @name IRQ - Interrupt Register */
/*! @{ */

#define EPDC_IRQ_WB_CMPLT_IRQ_MASK               (0x10000U)
#define EPDC_IRQ_WB_CMPLT_IRQ_SHIFT              (16U)
#define EPDC_IRQ_WB_CMPLT_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_WB_CMPLT_IRQ_SHIFT)) & EPDC_IRQ_WB_CMPLT_IRQ_MASK)

#define EPDC_IRQ_LUT_COL_IRQ_MASK                (0x20000U)
#define EPDC_IRQ_LUT_COL_IRQ_SHIFT               (17U)
#define EPDC_IRQ_LUT_COL_IRQ(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_LUT_COL_IRQ_SHIFT)) & EPDC_IRQ_LUT_COL_IRQ_MASK)

#define EPDC_IRQ_TCE_UNDERRUN_IRQ_MASK           (0x40000U)
#define EPDC_IRQ_TCE_UNDERRUN_IRQ_SHIFT          (18U)
#define EPDC_IRQ_TCE_UNDERRUN_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_TCE_UNDERRUN_IRQ_SHIFT)) & EPDC_IRQ_TCE_UNDERRUN_IRQ_MASK)

#define EPDC_IRQ_FRAME_END_IRQ_MASK              (0x80000U)
#define EPDC_IRQ_FRAME_END_IRQ_SHIFT             (19U)
#define EPDC_IRQ_FRAME_END_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_FRAME_END_IRQ_SHIFT)) & EPDC_IRQ_FRAME_END_IRQ_MASK)

#define EPDC_IRQ_BUS_ERROR_IRQ_MASK              (0x100000U)
#define EPDC_IRQ_BUS_ERROR_IRQ_SHIFT             (20U)
#define EPDC_IRQ_BUS_ERROR_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_BUS_ERROR_IRQ_SHIFT)) & EPDC_IRQ_BUS_ERROR_IRQ_MASK)

#define EPDC_IRQ_TCE_IDLE_IRQ_MASK               (0x200000U)
#define EPDC_IRQ_TCE_IDLE_IRQ_SHIFT              (21U)
#define EPDC_IRQ_TCE_IDLE_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_TCE_IDLE_IRQ_SHIFT)) & EPDC_IRQ_TCE_IDLE_IRQ_MASK)

#define EPDC_IRQ_UPD_DONE_IRQ_MASK               (0x400000U)
#define EPDC_IRQ_UPD_DONE_IRQ_SHIFT              (22U)
#define EPDC_IRQ_UPD_DONE_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_UPD_DONE_IRQ_SHIFT)) & EPDC_IRQ_UPD_DONE_IRQ_MASK)

#define EPDC_IRQ_PWR_IRQ_MASK                    (0x800000U)
#define EPDC_IRQ_PWR_IRQ_SHIFT                   (23U)
#define EPDC_IRQ_PWR_IRQ(x)                      (((uint32_t)(((uint32_t)(x)) << EPDC_IRQ_PWR_IRQ_SHIFT)) & EPDC_IRQ_PWR_IRQ_MASK)
/*! @} */

/*! @name STATUS_LUTS1 - Status Register - LUTs */
/*! @{ */

#define EPDC_STATUS_LUTS1_LUTN_STS_MASK          (0xFFFFFFFFU)
#define EPDC_STATUS_LUTS1_LUTN_STS_SHIFT         (0U)
#define EPDC_STATUS_LUTS1_LUTN_STS(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_LUTS1_LUTN_STS_SHIFT)) & EPDC_STATUS_LUTS1_LUTN_STS_MASK)
/*! @} */

/*! @name STATUS_LUTS2 - Status Register - LUTs */
/*! @{ */

#define EPDC_STATUS_LUTS2_LUTN_STS_MASK          (0xFFFFFFFFU)
#define EPDC_STATUS_LUTS2_LUTN_STS_SHIFT         (0U)
#define EPDC_STATUS_LUTS2_LUTN_STS(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_LUTS2_LUTN_STS_SHIFT)) & EPDC_STATUS_LUTS2_LUTN_STS_MASK)
/*! @} */

/*! @name STATUS_NEXTLUT - Status Register - Next Available LUT */
/*! @{ */

#define EPDC_STATUS_NEXTLUT_NEXT_LUT_MASK        (0x3FU)
#define EPDC_STATUS_NEXTLUT_NEXT_LUT_SHIFT       (0U)
#define EPDC_STATUS_NEXTLUT_NEXT_LUT(x)          (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_NEXTLUT_NEXT_LUT_SHIFT)) & EPDC_STATUS_NEXTLUT_NEXT_LUT_MASK)

#define EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID_MASK  (0x100U)
#define EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID_SHIFT (8U)
#define EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID(x)    (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID_SHIFT)) & EPDC_STATUS_NEXTLUT_NEXT_LUT_VALID_MASK)
/*! @} */

/*! @name STATUS_COL1 - LUT Collision Status */
/*! @{ */

#define EPDC_STATUS_COL1_LUTN_COL_STS_MASK       (0xFFFFFFFFU)
#define EPDC_STATUS_COL1_LUTN_COL_STS_SHIFT      (0U)
#define EPDC_STATUS_COL1_LUTN_COL_STS(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_COL1_LUTN_COL_STS_SHIFT)) & EPDC_STATUS_COL1_LUTN_COL_STS_MASK)
/*! @} */

/*! @name STATUS_COL2 - LUT Collision Status */
/*! @{ */

#define EPDC_STATUS_COL2_LUTN_COL_STS_MASK       (0xFFFFFFFFU)
#define EPDC_STATUS_COL2_LUTN_COL_STS_SHIFT      (0U)
#define EPDC_STATUS_COL2_LUTN_COL_STS(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_COL2_LUTN_COL_STS_SHIFT)) & EPDC_STATUS_COL2_LUTN_COL_STS_MASK)
/*! @} */

/*! @name STATUS - General Status Register */
/*! @{ */

#define EPDC_STATUS_WB_BUSY_MASK                 (0x1U)
#define EPDC_STATUS_WB_BUSY_SHIFT                (0U)
#define EPDC_STATUS_WB_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_WB_BUSY_SHIFT)) & EPDC_STATUS_WB_BUSY_MASK)

#define EPDC_STATUS_LUTS_BUSY_MASK               (0x2U)
#define EPDC_STATUS_LUTS_BUSY_SHIFT              (1U)
#define EPDC_STATUS_LUTS_BUSY(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_LUTS_BUSY_SHIFT)) & EPDC_STATUS_LUTS_BUSY_MASK)

#define EPDC_STATUS_LUTS_UNDERRUN_MASK           (0x4U)
#define EPDC_STATUS_LUTS_UNDERRUN_SHIFT          (2U)
#define EPDC_STATUS_LUTS_UNDERRUN(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_LUTS_UNDERRUN_SHIFT)) & EPDC_STATUS_LUTS_UNDERRUN_MASK)

#define EPDC_STATUS_UPD_VOID_MASK                (0x8U)
#define EPDC_STATUS_UPD_VOID_SHIFT               (3U)
#define EPDC_STATUS_UPD_VOID(x)                  (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_UPD_VOID_SHIFT)) & EPDC_STATUS_UPD_VOID_MASK)

#define EPDC_STATUS_HISTOGRAM_NP_MASK            (0x1F00U)
#define EPDC_STATUS_HISTOGRAM_NP_SHIFT           (8U)
#define EPDC_STATUS_HISTOGRAM_NP(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_HISTOGRAM_NP_SHIFT)) & EPDC_STATUS_HISTOGRAM_NP_MASK)

#define EPDC_STATUS_HISTOGRAM_CP_MASK            (0x1F0000U)
#define EPDC_STATUS_HISTOGRAM_CP_SHIFT           (16U)
#define EPDC_STATUS_HISTOGRAM_CP(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_STATUS_HISTOGRAM_CP_SHIFT)) & EPDC_STATUS_HISTOGRAM_CP_MASK)
/*! @} */

/*! @name UPD_COL_CORD - Collision Region Co-ordinate */
/*! @{ */

#define EPDC_UPD_COL_CORD_XCORD_MASK             (0x1FFFU)
#define EPDC_UPD_COL_CORD_XCORD_SHIFT            (0U)
#define EPDC_UPD_COL_CORD_XCORD(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_COL_CORD_XCORD_SHIFT)) & EPDC_UPD_COL_CORD_XCORD_MASK)

#define EPDC_UPD_COL_CORD_YCORD_MASK             (0x1FFF0000U)
#define EPDC_UPD_COL_CORD_YCORD_SHIFT            (16U)
#define EPDC_UPD_COL_CORD_YCORD(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_COL_CORD_YCORD_SHIFT)) & EPDC_UPD_COL_CORD_YCORD_MASK)
/*! @} */

/*! @name UPD_COL_SIZE - Collision Region Size */
/*! @{ */

#define EPDC_UPD_COL_SIZE_WIDTH_MASK             (0x1FFFU)
#define EPDC_UPD_COL_SIZE_WIDTH_SHIFT            (0U)
#define EPDC_UPD_COL_SIZE_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_COL_SIZE_WIDTH_SHIFT)) & EPDC_UPD_COL_SIZE_WIDTH_MASK)

#define EPDC_UPD_COL_SIZE_HEIGHT_MASK            (0x1FFF0000U)
#define EPDC_UPD_COL_SIZE_HEIGHT_SHIFT           (16U)
#define EPDC_UPD_COL_SIZE_HEIGHT(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_UPD_COL_SIZE_HEIGHT_SHIFT)) & EPDC_UPD_COL_SIZE_HEIGHT_MASK)
/*! @} */

/*! @name HIST1_PARAM - 1-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST1_PARAM_VALUE0_MASK             (0x1FU)
#define EPDC_HIST1_PARAM_VALUE0_SHIFT            (0U)
#define EPDC_HIST1_PARAM_VALUE0(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST1_PARAM_VALUE0_SHIFT)) & EPDC_HIST1_PARAM_VALUE0_MASK)

#define EPDC_HIST1_PARAM_RSVD_MASK               (0xFFFFFFE0U)
#define EPDC_HIST1_PARAM_RSVD_SHIFT              (5U)
#define EPDC_HIST1_PARAM_RSVD(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_HIST1_PARAM_RSVD_SHIFT)) & EPDC_HIST1_PARAM_RSVD_MASK)
/*! @} */

/*! @name HIST2_PARAM - 2-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST2_PARAM_VALUE0_MASK             (0x1FU)
#define EPDC_HIST2_PARAM_VALUE0_SHIFT            (0U)
#define EPDC_HIST2_PARAM_VALUE0(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST2_PARAM_VALUE0_SHIFT)) & EPDC_HIST2_PARAM_VALUE0_MASK)

#define EPDC_HIST2_PARAM_VALUE1_MASK             (0x1F00U)
#define EPDC_HIST2_PARAM_VALUE1_SHIFT            (8U)
#define EPDC_HIST2_PARAM_VALUE1(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST2_PARAM_VALUE1_SHIFT)) & EPDC_HIST2_PARAM_VALUE1_MASK)

#define EPDC_HIST2_PARAM_RSVD_MASK               (0xFFFF0000U)
#define EPDC_HIST2_PARAM_RSVD_SHIFT              (16U)
#define EPDC_HIST2_PARAM_RSVD(x)                 (((uint32_t)(((uint32_t)(x)) << EPDC_HIST2_PARAM_RSVD_SHIFT)) & EPDC_HIST2_PARAM_RSVD_MASK)
/*! @} */

/*! @name HIST4_PARAM - 4-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST4_PARAM_VALUE0_MASK             (0x1FU)
#define EPDC_HIST4_PARAM_VALUE0_SHIFT            (0U)
#define EPDC_HIST4_PARAM_VALUE0(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST4_PARAM_VALUE0_SHIFT)) & EPDC_HIST4_PARAM_VALUE0_MASK)

#define EPDC_HIST4_PARAM_VALUE1_MASK             (0x1F00U)
#define EPDC_HIST4_PARAM_VALUE1_SHIFT            (8U)
#define EPDC_HIST4_PARAM_VALUE1(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST4_PARAM_VALUE1_SHIFT)) & EPDC_HIST4_PARAM_VALUE1_MASK)

#define EPDC_HIST4_PARAM_VALUE2_MASK             (0x1F0000U)
#define EPDC_HIST4_PARAM_VALUE2_SHIFT            (16U)
#define EPDC_HIST4_PARAM_VALUE2(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST4_PARAM_VALUE2_SHIFT)) & EPDC_HIST4_PARAM_VALUE2_MASK)

#define EPDC_HIST4_PARAM_VALUE3_MASK             (0x1F000000U)
#define EPDC_HIST4_PARAM_VALUE3_SHIFT            (24U)
#define EPDC_HIST4_PARAM_VALUE3(x)               (((uint32_t)(((uint32_t)(x)) << EPDC_HIST4_PARAM_VALUE3_SHIFT)) & EPDC_HIST4_PARAM_VALUE3_MASK)
/*! @} */

/*! @name HIST8_PARAM0 - 8-level Histogram Parameter 0 Register */
/*! @{ */

#define EPDC_HIST8_PARAM0_VALUE0_MASK            (0x1FU)
#define EPDC_HIST8_PARAM0_VALUE0_SHIFT           (0U)
#define EPDC_HIST8_PARAM0_VALUE0(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM0_VALUE0_SHIFT)) & EPDC_HIST8_PARAM0_VALUE0_MASK)

#define EPDC_HIST8_PARAM0_VALUE1_MASK            (0x1F00U)
#define EPDC_HIST8_PARAM0_VALUE1_SHIFT           (8U)
#define EPDC_HIST8_PARAM0_VALUE1(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM0_VALUE1_SHIFT)) & EPDC_HIST8_PARAM0_VALUE1_MASK)

#define EPDC_HIST8_PARAM0_VALUE2_MASK            (0x1F0000U)
#define EPDC_HIST8_PARAM0_VALUE2_SHIFT           (16U)
#define EPDC_HIST8_PARAM0_VALUE2(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM0_VALUE2_SHIFT)) & EPDC_HIST8_PARAM0_VALUE2_MASK)

#define EPDC_HIST8_PARAM0_VALUE3_MASK            (0x1F000000U)
#define EPDC_HIST8_PARAM0_VALUE3_SHIFT           (24U)
#define EPDC_HIST8_PARAM0_VALUE3(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM0_VALUE3_SHIFT)) & EPDC_HIST8_PARAM0_VALUE3_MASK)
/*! @} */

/*! @name HIST8_PARAM1 - 8-level Histogram Parameter 1 Register */
/*! @{ */

#define EPDC_HIST8_PARAM1_VALUE4_MASK            (0x1FU)
#define EPDC_HIST8_PARAM1_VALUE4_SHIFT           (0U)
#define EPDC_HIST8_PARAM1_VALUE4(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM1_VALUE4_SHIFT)) & EPDC_HIST8_PARAM1_VALUE4_MASK)

#define EPDC_HIST8_PARAM1_VALUE5_MASK            (0x1F00U)
#define EPDC_HIST8_PARAM1_VALUE5_SHIFT           (8U)
#define EPDC_HIST8_PARAM1_VALUE5(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM1_VALUE5_SHIFT)) & EPDC_HIST8_PARAM1_VALUE5_MASK)

#define EPDC_HIST8_PARAM1_VALUE6_MASK            (0x1F0000U)
#define EPDC_HIST8_PARAM1_VALUE6_SHIFT           (16U)
#define EPDC_HIST8_PARAM1_VALUE6(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM1_VALUE6_SHIFT)) & EPDC_HIST8_PARAM1_VALUE6_MASK)

#define EPDC_HIST8_PARAM1_VALUE7_MASK            (0x1F000000U)
#define EPDC_HIST8_PARAM1_VALUE7_SHIFT           (24U)
#define EPDC_HIST8_PARAM1_VALUE7(x)              (((uint32_t)(((uint32_t)(x)) << EPDC_HIST8_PARAM1_VALUE7_SHIFT)) & EPDC_HIST8_PARAM1_VALUE7_MASK)
/*! @} */

/*! @name HIST16_PARAM0 - 16-level Histogram Parameter 0 Register */
/*! @{ */

#define EPDC_HIST16_PARAM0_VALUE0_MASK           (0x1FU)
#define EPDC_HIST16_PARAM0_VALUE0_SHIFT          (0U)
#define EPDC_HIST16_PARAM0_VALUE0(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM0_VALUE0_SHIFT)) & EPDC_HIST16_PARAM0_VALUE0_MASK)

#define EPDC_HIST16_PARAM0_VALUE1_MASK           (0x1F00U)
#define EPDC_HIST16_PARAM0_VALUE1_SHIFT          (8U)
#define EPDC_HIST16_PARAM0_VALUE1(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM0_VALUE1_SHIFT)) & EPDC_HIST16_PARAM0_VALUE1_MASK)

#define EPDC_HIST16_PARAM0_VALUE2_MASK           (0x1F0000U)
#define EPDC_HIST16_PARAM0_VALUE2_SHIFT          (16U)
#define EPDC_HIST16_PARAM0_VALUE2(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM0_VALUE2_SHIFT)) & EPDC_HIST16_PARAM0_VALUE2_MASK)

#define EPDC_HIST16_PARAM0_VALUE3_MASK           (0x1F000000U)
#define EPDC_HIST16_PARAM0_VALUE3_SHIFT          (24U)
#define EPDC_HIST16_PARAM0_VALUE3(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM0_VALUE3_SHIFT)) & EPDC_HIST16_PARAM0_VALUE3_MASK)
/*! @} */

/*! @name HIST16_PARAM1 - 16-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST16_PARAM1_VALUE4_MASK           (0x1FU)
#define EPDC_HIST16_PARAM1_VALUE4_SHIFT          (0U)
#define EPDC_HIST16_PARAM1_VALUE4(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM1_VALUE4_SHIFT)) & EPDC_HIST16_PARAM1_VALUE4_MASK)

#define EPDC_HIST16_PARAM1_VALUE5_MASK           (0x1F00U)
#define EPDC_HIST16_PARAM1_VALUE5_SHIFT          (8U)
#define EPDC_HIST16_PARAM1_VALUE5(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM1_VALUE5_SHIFT)) & EPDC_HIST16_PARAM1_VALUE5_MASK)

#define EPDC_HIST16_PARAM1_VALUE6_MASK           (0x1F0000U)
#define EPDC_HIST16_PARAM1_VALUE6_SHIFT          (16U)
#define EPDC_HIST16_PARAM1_VALUE6(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM1_VALUE6_SHIFT)) & EPDC_HIST16_PARAM1_VALUE6_MASK)

#define EPDC_HIST16_PARAM1_VALUE7_MASK           (0x1F000000U)
#define EPDC_HIST16_PARAM1_VALUE7_SHIFT          (24U)
#define EPDC_HIST16_PARAM1_VALUE7(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM1_VALUE7_SHIFT)) & EPDC_HIST16_PARAM1_VALUE7_MASK)
/*! @} */

/*! @name HIST16_PARAM2 - 16-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST16_PARAM2_VALUE8_MASK           (0x1FU)
#define EPDC_HIST16_PARAM2_VALUE8_SHIFT          (0U)
#define EPDC_HIST16_PARAM2_VALUE8(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM2_VALUE8_SHIFT)) & EPDC_HIST16_PARAM2_VALUE8_MASK)

#define EPDC_HIST16_PARAM2_VALUE9_MASK           (0x1F00U)
#define EPDC_HIST16_PARAM2_VALUE9_SHIFT          (8U)
#define EPDC_HIST16_PARAM2_VALUE9(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM2_VALUE9_SHIFT)) & EPDC_HIST16_PARAM2_VALUE9_MASK)

#define EPDC_HIST16_PARAM2_VALUE10_MASK          (0x1F0000U)
#define EPDC_HIST16_PARAM2_VALUE10_SHIFT         (16U)
#define EPDC_HIST16_PARAM2_VALUE10(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM2_VALUE10_SHIFT)) & EPDC_HIST16_PARAM2_VALUE10_MASK)

#define EPDC_HIST16_PARAM2_VALUE11_MASK          (0x1F000000U)
#define EPDC_HIST16_PARAM2_VALUE11_SHIFT         (24U)
#define EPDC_HIST16_PARAM2_VALUE11(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM2_VALUE11_SHIFT)) & EPDC_HIST16_PARAM2_VALUE11_MASK)
/*! @} */

/*! @name HIST16_PARAM3 - 16-level Histogram Parameter Register */
/*! @{ */

#define EPDC_HIST16_PARAM3_VALUE12_MASK          (0x1FU)
#define EPDC_HIST16_PARAM3_VALUE12_SHIFT         (0U)
#define EPDC_HIST16_PARAM3_VALUE12(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM3_VALUE12_SHIFT)) & EPDC_HIST16_PARAM3_VALUE12_MASK)

#define EPDC_HIST16_PARAM3_VALUE13_MASK          (0x1F00U)
#define EPDC_HIST16_PARAM3_VALUE13_SHIFT         (8U)
#define EPDC_HIST16_PARAM3_VALUE13(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM3_VALUE13_SHIFT)) & EPDC_HIST16_PARAM3_VALUE13_MASK)

#define EPDC_HIST16_PARAM3_VALUE14_MASK          (0x1F0000U)
#define EPDC_HIST16_PARAM3_VALUE14_SHIFT         (16U)
#define EPDC_HIST16_PARAM3_VALUE14(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM3_VALUE14_SHIFT)) & EPDC_HIST16_PARAM3_VALUE14_MASK)

#define EPDC_HIST16_PARAM3_VALUE15_MASK          (0x1F000000U)
#define EPDC_HIST16_PARAM3_VALUE15_SHIFT         (24U)
#define EPDC_HIST16_PARAM3_VALUE15(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_HIST16_PARAM3_VALUE15_SHIFT)) & EPDC_HIST16_PARAM3_VALUE15_MASK)
/*! @} */

/*! @name GPIO - General Purpose I/O Debug register */
/*! @{ */

#define EPDC_GPIO_BDR_MASK                       (0x3U)
#define EPDC_GPIO_BDR_SHIFT                      (0U)
#define EPDC_GPIO_BDR(x)                         (((uint32_t)(((uint32_t)(x)) << EPDC_GPIO_BDR_SHIFT)) & EPDC_GPIO_BDR_MASK)

#define EPDC_GPIO_PWRCTRL_MASK                   (0x3CU)
#define EPDC_GPIO_PWRCTRL_SHIFT                  (2U)
#define EPDC_GPIO_PWRCTRL(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_GPIO_PWRCTRL_SHIFT)) & EPDC_GPIO_PWRCTRL_MASK)

#define EPDC_GPIO_PWRCOM_MASK                    (0x40U)
#define EPDC_GPIO_PWRCOM_SHIFT                   (6U)
#define EPDC_GPIO_PWRCOM(x)                      (((uint32_t)(((uint32_t)(x)) << EPDC_GPIO_PWRCOM_SHIFT)) & EPDC_GPIO_PWRCOM_MASK)

#define EPDC_GPIO_PWRWAKE_MASK                   (0x80U)
#define EPDC_GPIO_PWRWAKE_SHIFT                  (7U)
#define EPDC_GPIO_PWRWAKE(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_GPIO_PWRWAKE_SHIFT)) & EPDC_GPIO_PWRWAKE_MASK)

#define EPDC_GPIO_PWRSTAT_MASK                   (0x100U)
#define EPDC_GPIO_PWRSTAT_SHIFT                  (8U)
#define EPDC_GPIO_PWRSTAT(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_GPIO_PWRSTAT_SHIFT)) & EPDC_GPIO_PWRSTAT_MASK)
/*! @} */

/*! @name VERSION - Version Register */
/*! @{ */

#define EPDC_VERSION_STEP_MASK                   (0xFFFFU)
#define EPDC_VERSION_STEP_SHIFT                  (0U)
#define EPDC_VERSION_STEP(x)                     (((uint32_t)(((uint32_t)(x)) << EPDC_VERSION_STEP_SHIFT)) & EPDC_VERSION_STEP_MASK)

#define EPDC_VERSION_MINOR_MASK                  (0xFF0000U)
#define EPDC_VERSION_MINOR_SHIFT                 (16U)
#define EPDC_VERSION_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_VERSION_MINOR_SHIFT)) & EPDC_VERSION_MINOR_MASK)

#define EPDC_VERSION_MAJOR_MASK                  (0xFF000000U)
#define EPDC_VERSION_MAJOR_SHIFT                 (24U)
#define EPDC_VERSION_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << EPDC_VERSION_MAJOR_SHIFT)) & EPDC_VERSION_MAJOR_MASK)
/*! @} */

/*! @name PIGEON_X_PIGEON_0 - Panel Interface Signal Generator Register 0_0..Panel Interface Signal Generator Register 16_0 */
/*! @{ */

#define EPDC_PIGEON_X_PIGEON_0_EN_MASK           (0x1U)
#define EPDC_PIGEON_X_PIGEON_0_EN_SHIFT          (0U)
#define EPDC_PIGEON_X_PIGEON_0_EN(x)             (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_EN_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_EN_MASK)

#define EPDC_PIGEON_X_PIGEON_0_POL_MASK          (0x2U)
#define EPDC_PIGEON_X_PIGEON_0_POL_SHIFT         (1U)
/*! POL
 *  0b0..normal signal (active high)
 *  0b1..inverted signal (active low)
 */
#define EPDC_PIGEON_X_PIGEON_0_POL(x)            (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_POL_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_POL_MASK)

#define EPDC_PIGEON_X_PIGEON_0_INC_SEL_MASK      (0xCU)
#define EPDC_PIGEON_X_PIGEON_0_INC_SEL_SHIFT     (2U)
/*! INC_SEL
 *  0b00..pclk
 *  0b01..line start pulse
 *  0b10..frame start pulse
 *  0b11..use another signal as tick event
 */
#define EPDC_PIGEON_X_PIGEON_0_INC_SEL(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_INC_SEL_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_INC_SEL_MASK)

#define EPDC_PIGEON_X_PIGEON_0_OFFSET_MASK       (0xF0U)
#define EPDC_PIGEON_X_PIGEON_0_OFFSET_SHIFT      (4U)
#define EPDC_PIGEON_X_PIGEON_0_OFFSET(x)         (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_OFFSET_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_OFFSET_MASK)

#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SEL_MASK (0xF00U)
#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SEL_SHIFT (8U)
/*! MASK_CNT_SEL
 *  0b0000..pclk counter within one hscan state
 *  0b0001..pclk cycle within one hscan state
 *  0b0010..line counter within one vscan state
 *  0b0011..line cycle within one vscan state
 *  0b0100..frame counter
 *  0b0101..frame cycle
 *  0b0110..horizontal counter (pclk counter within one line )
 *  0b0111..vertical counter (line counter within one frame)
 */
#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SEL(x)   (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SEL_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SEL_MASK)

#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT_MASK     (0xFFF000U)
#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SHIFT    (12U)
#define EPDC_PIGEON_X_PIGEON_0_MASK_CNT(x)       (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_MASK_CNT_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_MASK_CNT_MASK)

#define EPDC_PIGEON_X_PIGEON_0_STATE_MASK_MASK   (0xFF000000U)
#define EPDC_PIGEON_X_PIGEON_0_STATE_MASK_SHIFT  (24U)
/*! STATE_MASK
 *  0b00000001..FRAME SYNC
 *  0b00000010..FRAME BEGIN
 *  0b00000100..FRAME DATA
 *  0b00001000..FRAME END
 *  0b00010000..LINE SYNC
 *  0b00100000..LINE BEGIN
 *  0b01000000..LINE DATA
 *  0b10000000..LINE END
 */
#define EPDC_PIGEON_X_PIGEON_0_STATE_MASK(x)     (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_0_STATE_MASK_SHIFT)) & EPDC_PIGEON_X_PIGEON_0_STATE_MASK_MASK)
/*! @} */

/* The count of EPDC_PIGEON_X_PIGEON_0 */
#define EPDC_PIGEON_X_PIGEON_0_COUNT             (17U)

/*! @name PIGEON_X_PIGEON_1 - Panel Interface Signal Generator Register 0_1..Panel Interface Signal Generator Register 16_1 */
/*! @{ */

#define EPDC_PIGEON_X_PIGEON_1_SET_CNT_MASK      (0xFFFFU)
#define EPDC_PIGEON_X_PIGEON_1_SET_CNT_SHIFT     (0U)
/*! SET_CNT
 *  0b0000000000000000..start as active
 */
#define EPDC_PIGEON_X_PIGEON_1_SET_CNT(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_1_SET_CNT_SHIFT)) & EPDC_PIGEON_X_PIGEON_1_SET_CNT_MASK)

#define EPDC_PIGEON_X_PIGEON_1_CLR_CNT_MASK      (0xFFFF0000U)
#define EPDC_PIGEON_X_PIGEON_1_CLR_CNT_SHIFT     (16U)
/*! CLR_CNT
 *  0b0000000000000000..keep active until mask off
 */
#define EPDC_PIGEON_X_PIGEON_1_CLR_CNT(x)        (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_1_CLR_CNT_SHIFT)) & EPDC_PIGEON_X_PIGEON_1_CLR_CNT_MASK)
/*! @} */

/* The count of EPDC_PIGEON_X_PIGEON_1 */
#define EPDC_PIGEON_X_PIGEON_1_COUNT             (17U)

/*! @name PIGEON_X_PIGEON_2 - Panel Interface Signal Generator Register 0_2..Panel Interface Signal Generator Register 16_2 */
/*! @{ */

#define EPDC_PIGEON_X_PIGEON_2_SIG_LOGIC_MASK    (0xFU)
#define EPDC_PIGEON_X_PIGEON_2_SIG_LOGIC_SHIFT   (0U)
/*! SIG_LOGIC
 *  0b0000..no logic operation
 *  0b0001..sigout = sig_another AND this_sig
 *  0b0010..sigout = sig_another OR this_sig
 *  0b0011..mask = sig_another AND other_masks
 */
#define EPDC_PIGEON_X_PIGEON_2_SIG_LOGIC(x)      (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_2_SIG_LOGIC_SHIFT)) & EPDC_PIGEON_X_PIGEON_2_SIG_LOGIC_MASK)

#define EPDC_PIGEON_X_PIGEON_2_SIG_ANOTHER_MASK  (0x1F0U)
#define EPDC_PIGEON_X_PIGEON_2_SIG_ANOTHER_SHIFT (4U)
#define EPDC_PIGEON_X_PIGEON_2_SIG_ANOTHER(x)    (((uint32_t)(((uint32_t)(x)) << EPDC_PIGEON_X_PIGEON_2_SIG_ANOTHER_SHIFT)) & EPDC_PIGEON_X_PIGEON_2_SIG_ANOTHER_MASK)
/*! @} */

/* The count of EPDC_PIGEON_X_PIGEON_2 */
#define EPDC_PIGEON_X_PIGEON_2_COUNT             (17U)


/*!
 * @}
 */ /* end of group EPDC_Register_Masks */


/*!
 * @}
 */ /* end of group EPDC_Peripheral_Access_Layer */


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


#endif  /* PERI_EPDC_H_ */

