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
**         CMSIS Peripheral Access Layer for SMARTCARD
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
 * @file PERI_SMARTCARD.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SMARTCARD
 *
 * CMSIS Peripheral Access Layer for SMARTCARD
 */

#if !defined(PERI_SMARTCARD_H_)
#define PERI_SMARTCARD_H_                        /**< Symbol preventing repeated inclusion */

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
   -- SMARTCARD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTCARD_Peripheral_Access_Layer SMARTCARD Peripheral Access Layer
 * @{
 */

/** SMARTCARD - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    __IO uint32_t DLL;                               /**< Divisor Latch LSB, offset: 0x0 */
    __I  uint32_t RBR;                               /**< Receiver Buffer Register, offset: 0x0 */
    __O  uint32_t THR;                               /**< Transmit Holding Register, offset: 0x0 */
  };
  union {                                          /* offset: 0x4 */
    __IO uint32_t DLM;                               /**< Divisor Latch MSB, offset: 0x4 */
    __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x4 */
  };
  union {                                          /* offset: 0x8 */
    __O  uint32_t FCR;                               /**< FIFO Control Register, offset: 0x8 */
    __I  uint32_t IIR;                               /**< Interrupt ID Register, offset: 0x8 */
  };
  __IO uint32_t LCR;                               /**< Line Control Register, offset: 0xC */
       uint8_t RESERVED_0[4];
  __I  uint32_t LSR;                               /**< Line Status Register, offset: 0x14 */
       uint8_t RESERVED_1[4];
  __IO uint32_t SCR;                               /**< Scratch Pad Register, offset: 0x1C */
       uint8_t RESERVED_2[12];
  __IO uint32_t OSR;                               /**< Oversampling register, offset: 0x2C */
       uint8_t RESERVED_3[24];
  __IO uint32_t SCICTRL;                           /**< Smart Card Interface control register, offset: 0x48 */
} SMARTCARD_Type;

/* ----------------------------------------------------------------------------
   -- SMARTCARD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMARTCARD_Register_Masks SMARTCARD Register Masks
 * @{
 */

/*! @name DLL - Divisor Latch LSB */
/*! @{ */

#define SMARTCARD_DLL_DLLSB_MASK                 (0xFFU)
#define SMARTCARD_DLL_DLLSB_SHIFT                (0U)
/*! DLLSB - The SCIn Divisor Latch LSB Register, along with the SCInDLM register, determines the baud rate of the SCIn. */
#define SMARTCARD_DLL_DLLSB(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_DLL_DLLSB_SHIFT)) & SMARTCARD_DLL_DLLSB_MASK)
/*! @} */

/*! @name RBR - Receiver Buffer Register */
/*! @{ */

#define SMARTCARD_RBR_RBR_MASK                   (0xFFU)
#define SMARTCARD_RBR_RBR_SHIFT                  (0U)
/*! RBR - The SCIn Receiver Buffer Register contains the oldest received byte in the SCIn Rx FIFO. */
#define SMARTCARD_RBR_RBR(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_RBR_RBR_SHIFT)) & SMARTCARD_RBR_RBR_MASK)
/*! @} */

/*! @name THR - Transmit Holding Register */
/*! @{ */

#define SMARTCARD_THR_THR_MASK                   (0xFFU)
#define SMARTCARD_THR_THR_SHIFT                  (0U)
/*! THR - Writing to the SCIn Transmit Holding Register causes the data to be stored in the SCIn transmit FIFO. */
#define SMARTCARD_THR_THR(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_THR_THR_SHIFT)) & SMARTCARD_THR_THR_MASK)
/*! @} */

/*! @name DLM - Divisor Latch MSB */
/*! @{ */

#define SMARTCARD_DLM_DLMSB_MASK                 (0xFFU)
#define SMARTCARD_DLM_DLMSB_SHIFT                (0U)
/*! DLMSB - The SCIn Divisor Latch MSB Register, along with the DLL register, determines the baud rate of the SCIn. */
#define SMARTCARD_DLM_DLMSB(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_DLM_DLMSB_SHIFT)) & SMARTCARD_DLM_DLMSB_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define SMARTCARD_IER_RBRIE_MASK                 (0x1U)
#define SMARTCARD_IER_RBRIE_SHIFT                (0U)
/*! RBRIE - RBR Interrupt Enable. */
#define SMARTCARD_IER_RBRIE(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IER_RBRIE_SHIFT)) & SMARTCARD_IER_RBRIE_MASK)

#define SMARTCARD_IER_THREIE_MASK                (0x2U)
#define SMARTCARD_IER_THREIE_SHIFT               (1U)
/*! THREIE - THRE Interrupt Enable. */
#define SMARTCARD_IER_THREIE(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IER_THREIE_SHIFT)) & SMARTCARD_IER_THREIE_MASK)

#define SMARTCARD_IER_RXIE_MASK                  (0x4U)
#define SMARTCARD_IER_RXIE_SHIFT                 (2U)
/*! RXIE - RX Line Status Interrupt Enable. */
#define SMARTCARD_IER_RXIE(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IER_RXIE_SHIFT)) & SMARTCARD_IER_RXIE_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */

#define SMARTCARD_FCR_FIFOEN_MASK                (0x1U)
#define SMARTCARD_FCR_FIFOEN_SHIFT               (0U)
/*! FIFOEN - FIFO Enable. */
#define SMARTCARD_FCR_FIFOEN(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTCARD_FCR_FIFOEN_SHIFT)) & SMARTCARD_FCR_FIFOEN_MASK)

#define SMARTCARD_FCR_RXFIFORES_MASK             (0x2U)
#define SMARTCARD_FCR_RXFIFORES_SHIFT            (1U)
/*! RXFIFORES - RX FIFO Reset. */
#define SMARTCARD_FCR_RXFIFORES(x)               (((uint32_t)(((uint32_t)(x)) << SMARTCARD_FCR_RXFIFORES_SHIFT)) & SMARTCARD_FCR_RXFIFORES_MASK)

#define SMARTCARD_FCR_TXFIFORES_MASK             (0x4U)
#define SMARTCARD_FCR_TXFIFORES_SHIFT            (2U)
/*! TXFIFORES - TX FIFO Reset. */
#define SMARTCARD_FCR_TXFIFORES(x)               (((uint32_t)(((uint32_t)(x)) << SMARTCARD_FCR_TXFIFORES_SHIFT)) & SMARTCARD_FCR_TXFIFORES_MASK)

#define SMARTCARD_FCR_DMAMODE_MASK               (0x8U)
#define SMARTCARD_FCR_DMAMODE_SHIFT              (3U)
/*! DMAMODE - DMA Mode Select. */
#define SMARTCARD_FCR_DMAMODE(x)                 (((uint32_t)(((uint32_t)(x)) << SMARTCARD_FCR_DMAMODE_SHIFT)) & SMARTCARD_FCR_DMAMODE_MASK)

#define SMARTCARD_FCR_RXTRIGLVL_MASK             (0xC0U)
#define SMARTCARD_FCR_RXTRIGLVL_SHIFT            (6U)
/*! RXTRIGLVL - RX Trigger Level. */
#define SMARTCARD_FCR_RXTRIGLVL(x)               (((uint32_t)(((uint32_t)(x)) << SMARTCARD_FCR_RXTRIGLVL_SHIFT)) & SMARTCARD_FCR_RXTRIGLVL_MASK)
/*! @} */

/*! @name IIR - Interrupt ID Register */
/*! @{ */

#define SMARTCARD_IIR_INTSTATUS_MASK             (0x1U)
#define SMARTCARD_IIR_INTSTATUS_SHIFT            (0U)
/*! INTSTATUS - Interrupt status. */
#define SMARTCARD_IIR_INTSTATUS(x)               (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IIR_INTSTATUS_SHIFT)) & SMARTCARD_IIR_INTSTATUS_MASK)

#define SMARTCARD_IIR_INTID_MASK                 (0xEU)
#define SMARTCARD_IIR_INTID_SHIFT                (1U)
/*! INTID - Interrupt identification. */
#define SMARTCARD_IIR_INTID(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IIR_INTID_SHIFT)) & SMARTCARD_IIR_INTID_MASK)

#define SMARTCARD_IIR_FIFOENABLE_MASK            (0xC0U)
#define SMARTCARD_IIR_FIFOENABLE_SHIFT           (6U)
/*! FIFOENABLE - Copies of SCInFCR[0]. */
#define SMARTCARD_IIR_FIFOENABLE(x)              (((uint32_t)(((uint32_t)(x)) << SMARTCARD_IIR_FIFOENABLE_SHIFT)) & SMARTCARD_IIR_FIFOENABLE_MASK)
/*! @} */

/*! @name LCR - Line Control Register */
/*! @{ */

#define SMARTCARD_LCR_WLS_MASK                   (0x3U)
#define SMARTCARD_LCR_WLS_SHIFT                  (0U)
/*! WLS - Word Length Select. */
#define SMARTCARD_LCR_WLS(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LCR_WLS_SHIFT)) & SMARTCARD_LCR_WLS_MASK)

#define SMARTCARD_LCR_SBS_MASK                   (0x4U)
#define SMARTCARD_LCR_SBS_SHIFT                  (2U)
/*! SBS - Stop Bit Select. */
#define SMARTCARD_LCR_SBS(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LCR_SBS_SHIFT)) & SMARTCARD_LCR_SBS_MASK)

#define SMARTCARD_LCR_PE_MASK                    (0x8U)
#define SMARTCARD_LCR_PE_SHIFT                   (3U)
/*! PE - Parity Enable. */
#define SMARTCARD_LCR_PE(x)                      (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LCR_PE_SHIFT)) & SMARTCARD_LCR_PE_MASK)

#define SMARTCARD_LCR_PS_MASK                    (0x30U)
#define SMARTCARD_LCR_PS_SHIFT                   (4U)
/*! PS - Parity Select. */
#define SMARTCARD_LCR_PS(x)                      (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LCR_PS_SHIFT)) & SMARTCARD_LCR_PS_MASK)

#define SMARTCARD_LCR_DLAB_MASK                  (0x80U)
#define SMARTCARD_LCR_DLAB_SHIFT                 (7U)
/*! DLAB - Divisor Latch Access Bit. */
#define SMARTCARD_LCR_DLAB(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LCR_DLAB_SHIFT)) & SMARTCARD_LCR_DLAB_MASK)
/*! @} */

/*! @name LSR - Line Status Register */
/*! @{ */

#define SMARTCARD_LSR_RDR_MASK                   (0x1U)
#define SMARTCARD_LSR_RDR_SHIFT                  (0U)
/*! RDR - Receiver Data Ready. */
#define SMARTCARD_LSR_RDR(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_RDR_SHIFT)) & SMARTCARD_LSR_RDR_MASK)

#define SMARTCARD_LSR_OE_MASK                    (0x2U)
#define SMARTCARD_LSR_OE_SHIFT                   (1U)
/*! OE - Overrun Error. */
#define SMARTCARD_LSR_OE(x)                      (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_OE_SHIFT)) & SMARTCARD_LSR_OE_MASK)

#define SMARTCARD_LSR_PE_MASK                    (0x4U)
#define SMARTCARD_LSR_PE_SHIFT                   (2U)
/*! PE - Parity Error. */
#define SMARTCARD_LSR_PE(x)                      (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_PE_SHIFT)) & SMARTCARD_LSR_PE_MASK)

#define SMARTCARD_LSR_FE_MASK                    (0x8U)
#define SMARTCARD_LSR_FE_SHIFT                   (3U)
/*! FE - Framing Error. */
#define SMARTCARD_LSR_FE(x)                      (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_FE_SHIFT)) & SMARTCARD_LSR_FE_MASK)

#define SMARTCARD_LSR_THRE_MASK                  (0x20U)
#define SMARTCARD_LSR_THRE_SHIFT                 (5U)
/*! THRE - Transmitter Holding Register Empty. */
#define SMARTCARD_LSR_THRE(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_THRE_SHIFT)) & SMARTCARD_LSR_THRE_MASK)

#define SMARTCARD_LSR_TEMT_MASK                  (0x40U)
#define SMARTCARD_LSR_TEMT_SHIFT                 (6U)
/*! TEMT - Transmitter Empty. */
#define SMARTCARD_LSR_TEMT(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_TEMT_SHIFT)) & SMARTCARD_LSR_TEMT_MASK)

#define SMARTCARD_LSR_RXFE_MASK                  (0x80U)
#define SMARTCARD_LSR_RXFE_SHIFT                 (7U)
/*! RXFE - Error in RX FIFO. */
#define SMARTCARD_LSR_RXFE(x)                    (((uint32_t)(((uint32_t)(x)) << SMARTCARD_LSR_RXFE_SHIFT)) & SMARTCARD_LSR_RXFE_MASK)
/*! @} */

/*! @name SCR - Scratch Pad Register */
/*! @{ */

#define SMARTCARD_SCR_PAD_MASK                   (0xFFU)
#define SMARTCARD_SCR_PAD_SHIFT                  (0U)
/*! PAD - A readable, writable byte. */
#define SMARTCARD_SCR_PAD(x)                     (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCR_PAD_SHIFT)) & SMARTCARD_SCR_PAD_MASK)
/*! @} */

/*! @name OSR - Oversampling register */
/*! @{ */

#define SMARTCARD_OSR_OSFRAC_MASK                (0xEU)
#define SMARTCARD_OSR_OSFRAC_SHIFT               (1U)
/*! OSFRAC - Fractional part of the oversampling ratio, in units of 1/8th of an input clock period. */
#define SMARTCARD_OSR_OSFRAC(x)                  (((uint32_t)(((uint32_t)(x)) << SMARTCARD_OSR_OSFRAC_SHIFT)) & SMARTCARD_OSR_OSFRAC_MASK)

#define SMARTCARD_OSR_OSINT_MASK                 (0xF0U)
#define SMARTCARD_OSR_OSINT_SHIFT                (4U)
/*! OSINT - Integer part of the oversampling ratio, minus 1. */
#define SMARTCARD_OSR_OSINT(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_OSR_OSINT_SHIFT)) & SMARTCARD_OSR_OSINT_MASK)

#define SMARTCARD_OSR_FDINT_MASK                 (0x7F00U)
#define SMARTCARD_OSR_FDINT_SHIFT                (8U)
/*! FDINT - These bits act as a more-significant extension of the OSint field, allowing an
 *    oversampling ratio up to 2048 as required by ISO7816-3.
 */
#define SMARTCARD_OSR_FDINT(x)                   (((uint32_t)(((uint32_t)(x)) << SMARTCARD_OSR_FDINT_SHIFT)) & SMARTCARD_OSR_FDINT_MASK)
/*! @} */

/*! @name SCICTRL - Smart Card Interface control register */
/*! @{ */

#define SMARTCARD_SCICTRL_SCIEN_MASK             (0x1U)
#define SMARTCARD_SCICTRL_SCIEN_SHIFT            (0U)
/*! SCIEN - Smart Card Interface Enable. */
#define SMARTCARD_SCICTRL_SCIEN(x)               (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCICTRL_SCIEN_SHIFT)) & SMARTCARD_SCICTRL_SCIEN_MASK)

#define SMARTCARD_SCICTRL_NACKDIS_MASK           (0x2U)
#define SMARTCARD_SCICTRL_NACKDIS_SHIFT          (1U)
/*! NACKDIS - NACK response disable. */
#define SMARTCARD_SCICTRL_NACKDIS(x)             (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCICTRL_NACKDIS_SHIFT)) & SMARTCARD_SCICTRL_NACKDIS_MASK)

#define SMARTCARD_SCICTRL_PROTSEL_MASK           (0x4U)
#define SMARTCARD_SCICTRL_PROTSEL_SHIFT          (2U)
/*! PROTSEL - Protocol selection as defined in the ISO7816-3 standard. */
#define SMARTCARD_SCICTRL_PROTSEL(x)             (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCICTRL_PROTSEL_SHIFT)) & SMARTCARD_SCICTRL_PROTSEL_MASK)

#define SMARTCARD_SCICTRL_TXRETRY_MASK           (0xE0U)
#define SMARTCARD_SCICTRL_TXRETRY_SHIFT          (5U)
/*! TXRETRY - Maximum number of retransmissions in case of a negative acknowledge (protocol T=0). */
#define SMARTCARD_SCICTRL_TXRETRY(x)             (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCICTRL_TXRETRY_SHIFT)) & SMARTCARD_SCICTRL_TXRETRY_MASK)

#define SMARTCARD_SCICTRL_GUARDTIME_MASK         (0xFF00U)
#define SMARTCARD_SCICTRL_GUARDTIME_SHIFT        (8U)
/*! GUARDTIME - Extra guard time. */
#define SMARTCARD_SCICTRL_GUARDTIME(x)           (((uint32_t)(((uint32_t)(x)) << SMARTCARD_SCICTRL_GUARDTIME_SHIFT)) & SMARTCARD_SCICTRL_GUARDTIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SMARTCARD_Register_Masks */


/*!
 * @}
 */ /* end of group SMARTCARD_Peripheral_Access_Layer */


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


#endif  /* PERI_SMARTCARD_H_ */

