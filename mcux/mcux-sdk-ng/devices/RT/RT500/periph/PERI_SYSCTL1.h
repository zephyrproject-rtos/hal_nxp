/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 5.0, 2020-08-27
**     Build:               b240705
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSCTL1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**
** ###################################################################
*/

/*!
 * @file SYSCTL1.h
 * @version 5.0
 * @date 2020-08-27
 * @brief CMSIS Peripheral Access Layer for SYSCTL1
 *
 * CMSIS Peripheral Access Layer for SYSCTL1
 */

#if !defined(SYSCTL1_H_)
#define SYSCTL1_H_                               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- SYSCTL1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL1_Peripheral_Access_Layer SYSCTL1 Peripheral Access Layer
 * @{
 */

/** SYSCTL1 - Size of Registers Arrays */
#define SYSCTL1_FCNCTRLSEL_COUNT                  14u
#define SYSCTL1_SHAREDCTRLSETN_COUNT              2u

/** SYSCTL1 - Register Layout Typedef */
typedef struct {
  __IO uint32_t UPDATELCKOUT;                      /**< Update Clock Lockout, offset: 0x0 */
       uint8_t RESERVED_0[12];
  __IO uint32_t MCLKPINDIR;                        /**< MCLK direction control, offset: 0x10 */
       uint8_t RESERVED_1[28];
  __IO uint32_t DSPNMISRCSEL;                      /**< DSP NMI source selection, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t FCCTRLSEL[SYSCTL1_FCNCTRLSEL_COUNT]; /**< Flexcomm control selection, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t SHAREDCTRLSET[SYSCTL1_SHAREDCTRLSETN_COUNT]; /**< Shared control set, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_4[376];
  __O  uint32_t RXEVPULSEGEN;                      /**< RX Event Pulse Generator, offset: 0x200 */
} SYSCTL1_Type;

/* ----------------------------------------------------------------------------
   -- SYSCTL1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSCTL1_Register_Masks SYSCTL1 Register Masks
 * @{
 */

/*! @name UPDATELCKOUT - Update Clock Lockout */
/*! @{ */

#define SYSCTL1_UPDATELCKOUT_UPDATELCKOUT_MASK   (0x1U)
#define SYSCTL1_UPDATELCKOUT_UPDATELCKOUT_SHIFT  (0U)
/*! UPDATELCKOUT - Update Clock Lockout
 *  0b0..Normal Mode
 *  0b1..Protected Mode. Cannot be written to. Currently this register does not lock anything
 */
#define SYSCTL1_UPDATELCKOUT_UPDATELCKOUT(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL1_UPDATELCKOUT_UPDATELCKOUT_SHIFT)) & SYSCTL1_UPDATELCKOUT_UPDATELCKOUT_MASK)
/*! @} */

/*! @name MCLKPINDIR - MCLK direction control */
/*! @{ */

#define SYSCTL1_MCLKPINDIR_MCLKPINDIR_MASK       (0x1U)
#define SYSCTL1_MCLKPINDIR_MCLKPINDIR_SHIFT      (0U)
/*! MCLKPINDIR - MCLK direction control
 *  0b0..I2S MCLK is in input direction
 *  0b1..I2S MCLK is in the output direction
 */
#define SYSCTL1_MCLKPINDIR_MCLKPINDIR(x)         (((uint32_t)(((uint32_t)(x)) << SYSCTL1_MCLKPINDIR_MCLKPINDIR_SHIFT)) & SYSCTL1_MCLKPINDIR_MCLKPINDIR_MASK)
/*! @} */

/*! @name DSPNMISRCSEL - DSP NMI source selection */
/*! @{ */

#define SYSCTL1_DSPNMISRCSEL_NMISRCSEL_MASK      (0x1FU)
#define SYSCTL1_DSPNMISRCSEL_NMISRCSEL_SHIFT     (0U)
/*! NMISRCSEL - DSP NMI source selection */
#define SYSCTL1_DSPNMISRCSEL_NMISRCSEL(x)        (((uint32_t)(((uint32_t)(x)) << SYSCTL1_DSPNMISRCSEL_NMISRCSEL_SHIFT)) & SYSCTL1_DSPNMISRCSEL_NMISRCSEL_MASK)

#define SYSCTL1_DSPNMISRCSEL_NMIEN_MASK          (0x80000000U)
#define SYSCTL1_DSPNMISRCSEL_NMIEN_SHIFT         (31U)
/*! NMIEN - NMI Enable
 *  0b0..Disable NMI Interrupt
 *  0b1..Enable NMI Interrupt
 */
#define SYSCTL1_DSPNMISRCSEL_NMIEN(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL1_DSPNMISRCSEL_NMIEN_SHIFT)) & SYSCTL1_DSPNMISRCSEL_NMIEN_MASK)
/*! @} */

/*! @name FCCTRLSEL - Flexcomm control selection */
/*! @{ */

#define SYSCTL1_FCCTRLSEL_SCKINSEL_MASK          (0x3U)
#define SYSCTL1_FCCTRLSEL_SCKINSEL_SHIFT         (0U)
/*! SCKINSEL - SCK IN Select
 *  0b00..Original FLEXCOMM I2S signals
 *  0b01..Shared Set0 I2S signals
 *  0b10..Shared Set1 I2S signals
 *  0b11..Reserved
 */
#define SYSCTL1_FCCTRLSEL_SCKINSEL(x)            (((uint32_t)(((uint32_t)(x)) << SYSCTL1_FCCTRLSEL_SCKINSEL_SHIFT)) & SYSCTL1_FCCTRLSEL_SCKINSEL_MASK)

#define SYSCTL1_FCCTRLSEL_WSINSEL_MASK           (0x300U)
#define SYSCTL1_FCCTRLSEL_WSINSEL_SHIFT          (8U)
/*! WSINSEL - SCK IN Select
 *  0b00..Original FLEXCOMM I2S signals
 *  0b01..Shared Set0 I2S signals
 *  0b10..Shared Set1 I2S signals
 *  0b11..Reserved
 */
#define SYSCTL1_FCCTRLSEL_WSINSEL(x)             (((uint32_t)(((uint32_t)(x)) << SYSCTL1_FCCTRLSEL_WSINSEL_SHIFT)) & SYSCTL1_FCCTRLSEL_WSINSEL_MASK)

#define SYSCTL1_FCCTRLSEL_DATAINSEL_MASK         (0x30000U)
#define SYSCTL1_FCCTRLSEL_DATAINSEL_SHIFT        (16U)
/*! DATAINSEL - DATA IN Select
 *  0b00..Original FLEXCOMM I2S signals
 *  0b01..Shared Set0 I2S signals
 *  0b10..Shared Set1 I2S signals
 *  0b11..Reserved
 */
#define SYSCTL1_FCCTRLSEL_DATAINSEL(x)           (((uint32_t)(((uint32_t)(x)) << SYSCTL1_FCCTRLSEL_DATAINSEL_SHIFT)) & SYSCTL1_FCCTRLSEL_DATAINSEL_MASK)

#define SYSCTL1_FCCTRLSEL_DATAOUTSEL_MASK        (0x3000000U)
#define SYSCTL1_FCCTRLSEL_DATAOUTSEL_SHIFT       (24U)
/*! DATAOUTSEL - DATA OUT Select
 *  0b00..Original FLEXCOMM I2S signals
 *  0b01..Shared Set0 I2S signals
 *  0b10..Shared Set1 I2S signals
 *  0b11..Reserved
 */
#define SYSCTL1_FCCTRLSEL_DATAOUTSEL(x)          (((uint32_t)(((uint32_t)(x)) << SYSCTL1_FCCTRLSEL_DATAOUTSEL_SHIFT)) & SYSCTL1_FCCTRLSEL_DATAOUTSEL_MASK)
/*! @} */

/* The count of SYSCTL1_FCCTRLSEL */
#define SYSCTL1_FCCTRLSEL_COUNT                  (14U)

/*! @name SHAREDCTRLSET - Shared control set */
/*! @{ */

#define SYSCTL1_SHAREDCTRLSET_SHAREDSCKSEL_MASK  (0x7U)
#define SYSCTL1_SHAREDCTRLSET_SHAREDSCKSEL_SHIFT (0U)
/*! SHAREDSCKSEL - Shared SCK Select
 *  0b000..FLEXCOMM0
 *  0b001..FLEXCOMM1
 *  0b010..FLEXCOMM2
 *  0b011..FLEXCOMM3
 *  0b100..FLEXCOMM4
 *  0b101..FLEXCOMM5
 *  0b110..FLEXCOMM6
 *  0b111..FLEXCOMM7
 */
#define SYSCTL1_SHAREDCTRLSET_SHAREDSCKSEL(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_SHAREDSCKSEL_SHIFT)) & SYSCTL1_SHAREDCTRLSET_SHAREDSCKSEL_MASK)

#define SYSCTL1_SHAREDCTRLSET_SHAREDWSSEL_MASK   (0x70U)
#define SYSCTL1_SHAREDCTRLSET_SHAREDWSSEL_SHIFT  (4U)
/*! SHAREDWSSEL - Shared WS Select:
 *  0b000..FLEXCOMM0
 *  0b001..FLEXCOMM1
 *  0b010..FLEXCOMM2
 *  0b011..FLEXCOMM3
 *  0b100..FLEXCOMM4
 *  0b101..FLEXCOMM5
 *  0b110..FLEXCOMM6
 *  0b111..FLEXCOMM7
 */
#define SYSCTL1_SHAREDCTRLSET_SHAREDWSSEL(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_SHAREDWSSEL_SHIFT)) & SYSCTL1_SHAREDCTRLSET_SHAREDWSSEL_MASK)

#define SYSCTL1_SHAREDCTRLSET_SHAREDDATASEL_MASK (0x700U)
#define SYSCTL1_SHAREDCTRLSET_SHAREDDATASEL_SHIFT (8U)
/*! SHAREDDATASEL - Shared DATA Select:
 *  0b000..FLEXCOMM0
 *  0b001..FLEXCOMM1
 *  0b010..FLEXCOMM2
 *  0b011..FLEXCOMM3
 *  0b100..FLEXCOMM4
 *  0b101..FLEXCOMM5
 *  0b110..FLEXCOMM6
 *  0b111..FLEXCOMM7
 */
#define SYSCTL1_SHAREDCTRLSET_SHAREDDATASEL(x)   (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_SHAREDDATASEL_SHIFT)) & SYSCTL1_SHAREDCTRLSET_SHAREDDATASEL_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC0DATAOUTEN_MASK  (0x10000U)
#define SYSCTL1_SHAREDCTRLSET_FC0DATAOUTEN_SHIFT (16U)
/*! FC0DATAOUTEN - FLEXCOMM0 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC0DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC0DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC0DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC1DATAOUTEN_MASK  (0x20000U)
#define SYSCTL1_SHAREDCTRLSET_FC1DATAOUTEN_SHIFT (17U)
/*! FC1DATAOUTEN - FLEXCOMM1 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC1DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC1DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC1DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC2DATAOUTEN_MASK  (0x40000U)
#define SYSCTL1_SHAREDCTRLSET_FC2DATAOUTEN_SHIFT (18U)
/*! FC2DATAOUTEN - FLEXCOMM2 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC2DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC2DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC2DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC3DATAOUTEN_MASK  (0x80000U)
#define SYSCTL1_SHAREDCTRLSET_FC3DATAOUTEN_SHIFT (19U)
/*! FC3DATAOUTEN - FLEXCOMM3 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC3DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC3DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC3DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC4DATAOUTEN_MASK  (0x100000U)
#define SYSCTL1_SHAREDCTRLSET_FC4DATAOUTEN_SHIFT (20U)
/*! FC4DATAOUTEN - FLEXCOMM4 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC4DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC4DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC4DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC5DATAOUTEN_MASK  (0x200000U)
#define SYSCTL1_SHAREDCTRLSET_FC5DATAOUTEN_SHIFT (21U)
/*! FC5DATAOUTEN - FLEXCOMM5 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC5DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC5DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC5DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC6DATAOUTEN_MASK  (0x400000U)
#define SYSCTL1_SHAREDCTRLSET_FC6DATAOUTEN_SHIFT (22U)
/*! FC6DATAOUTEN - FLEXCOMM6 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC6DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC6DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC6DATAOUTEN_MASK)

#define SYSCTL1_SHAREDCTRLSET_FC7DATAOUTEN_MASK  (0x800000U)
#define SYSCTL1_SHAREDCTRLSET_FC7DATAOUTEN_SHIFT (23U)
/*! FC7DATAOUTEN - FLEXCOMM7 DATAOUT Output Enable:
 *  0b0..Input
 *  0b1..Output
 */
#define SYSCTL1_SHAREDCTRLSET_FC7DATAOUTEN(x)    (((uint32_t)(((uint32_t)(x)) << SYSCTL1_SHAREDCTRLSET_FC7DATAOUTEN_SHIFT)) & SYSCTL1_SHAREDCTRLSET_FC7DATAOUTEN_MASK)
/*! @} */

/* The count of SYSCTL1_SHAREDCTRLSET */
#define SYSCTL1_SHAREDCTRLSET_COUNT              (2U)

/*! @name RXEVPULSEGEN - RX Event Pulse Generator */
/*! @{ */

#define SYSCTL1_RXEVPULSEGEN_RXEVPULSEGEN_MASK   (0x1U)
#define SYSCTL1_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT  (0U)
/*! RXEVPULSEGEN - RX Event Pulse Generator
 *  0b0..No effect
 *  0b1..Pulse RXEV High for one PSCLK cycle
 */
#define SYSCTL1_RXEVPULSEGEN_RXEVPULSEGEN(x)     (((uint32_t)(((uint32_t)(x)) << SYSCTL1_RXEVPULSEGEN_RXEVPULSEGEN_SHIFT)) & SYSCTL1_RXEVPULSEGEN_RXEVPULSEGEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSCTL1_Register_Masks */


/*!
 * @}
 */ /* end of group SYSCTL1_Peripheral_Access_Layer */


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


#endif  /* SYSCTL1_H_ */

