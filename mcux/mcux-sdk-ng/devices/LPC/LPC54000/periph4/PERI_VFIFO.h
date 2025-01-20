/*
** ###################################################################
**     Processors:          LPC54101J256BD64
**                          LPC54101J256UK49
**                          LPC54101J512BD64
**                          LPC54101J512UK49
**                          LPC54102J256BD64_cm0plus
**                          LPC54102J256BD64_cm4
**                          LPC54102J256UK49_cm0plus
**                          LPC54102J256UK49_cm4
**                          LPC54102J512BD64_cm0plus
**                          LPC54102J512BD64_cm4
**                          LPC54102J512UK49_cm0plus
**                          LPC54102J512UK49_cm4
**
**     Version:             rev. 1.0, 2016-04-29
**     Build:               b240704
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VFIFO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-29)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file VFIFO.h
 * @version 1.0
 * @date 2016-04-29
 * @brief CMSIS Peripheral Access Layer for VFIFO
 *
 * CMSIS Peripheral Access Layer for VFIFO
 */

#if !defined(VFIFO_H_)
#define VFIFO_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54101J256BD64) || defined(CPU_LPC54101J256UK49) || defined(CPU_LPC54101J512BD64) || defined(CPU_LPC54101J512UK49))
#include "LPC54101_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm0plus) || defined(CPU_LPC54102J256UK49_cm0plus) || defined(CPU_LPC54102J512BD64_cm0plus) || defined(CPU_LPC54102J512UK49_cm0plus))
#include "LPC54102_cm0plus_COMMON.h"
#elif (defined(CPU_LPC54102J256BD64_cm4) || defined(CPU_LPC54102J256UK49_cm4) || defined(CPU_LPC54102J512BD64_cm4) || defined(CPU_LPC54102J512UK49_cm4))
#include "LPC54102_cm4_COMMON.h"
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
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- VFIFO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFIFO_Peripheral_Access_Layer VFIFO Peripheral Access Layer
 * @{
 */

/** VFIFO - Size of Registers Arrays */
#define VFIFO_FIFOCFGUSART_COUNT                  4u
#define VFIFO_FIFOCFGSPI_COUNT                    2u
#define VFIFO_USART_COUNT                         4u
#define VFIFO_SPI_COUNT                           2u

/** VFIFO - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  __IO uint32_t FIFOCTLUSART;                      /**< USART FIFO global control register. These registers are byte, halfword, and word addressable.The upper 16 bits of these registers provide information about the System FIFO configuration, and are specific to each device type., offset: 0x100 */
  __IO uint32_t FIFOUPDATEUSART;                   /**< USART FIFO global update register, offset: 0x104 */
       uint8_t RESERVED_1[8];
  __IO uint32_t FIFOCFGUSART[VFIFO_FIFOCFGUSART_COUNT]; /**< FIFO configuration register for USART0, array offset: 0x110, array step: 0x4 */
       uint8_t RESERVED_2[224];
  __IO uint32_t FIFOCTLSPI;                        /**< SPI FIFO global control register. These registers are byte, halfword, and word addressable. The upper 16 bits of these registers provide information about the System FIFO configuration, and are specific to each device type., offset: 0x200 */
  __IO uint32_t FIFOUPDATESPI;                     /**< SPI FIFO global update register, offset: 0x204 */
       uint8_t RESERVED_3[8];
  __IO uint32_t FIFOCFGSPI[VFIFO_FIFOCFGSPI_COUNT]; /**< FIFO configuration register for SPI0, array offset: 0x210, array step: 0x4 */
       uint8_t RESERVED_4[3560];
  struct {                                         /* offset: 0x1000, array step: 0x100 */
    __IO uint32_t CFGUSART;                          /**< USART0 configuration, array offset: 0x1000, array step: 0x100 */
    __IO uint32_t STATUSART;                         /**< USART0 status, array offset: 0x1004, array step: 0x100 */
    __IO uint32_t INTSTATUSART;                      /**< USART0 interrupt status, array offset: 0x1008, array step: 0x100 */
    __IO uint32_t CTLSETUSART;                       /**< USART0 control read and set register. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., array offset: 0x100C, array step: 0x100 */
    __IO uint32_t CTLCLRUSART;                       /**< USART0 control clear register. Writing a 1 to any implemented bit position causes the corresponding bit in the related CTLSET register to be cleared., array offset: 0x1010, array step: 0x100 */
    __IO uint32_t RXDATUSART;                        /**< USART0 received data, array offset: 0x1014, array step: 0x100 */
    __IO uint32_t RXDATSTATUSART;                    /**< USART0 received data with status, array offset: 0x1018, array step: 0x100 */
    __IO uint32_t TXDATUSART;                        /**< USART0 transmit data, array offset: 0x101C, array step: 0x100 */
         uint8_t RESERVED_0[224];
  } USART[VFIFO_USART_COUNT];
       uint8_t RESERVED_5[3072];
  struct {                                         /* offset: 0x2000, array step: 0x100 */
    __IO uint32_t CFGSPI;                            /**< SPI0 configuration, array offset: 0x2000, array step: 0x100 */
    __IO uint32_t STATSPI;                           /**< SPI0 status, array offset: 0x2004, array step: 0x100 */
    __IO uint32_t INTSTATSPI;                        /**< SPI0 interrupt status, array offset: 0x2008, array step: 0x100 */
    __IO uint32_t CTLSETSPI;                         /**< SPI0 control read and set register. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., array offset: 0x200C, array step: 0x100 */
    __IO uint32_t CTLCLRSPI;                         /**< SPI0 control clear register. Writing a 1 to any implemented bit position causes the corresponding bit in the related CTLSET register to be cleared., array offset: 0x2010, array step: 0x100 */
    __IO uint32_t RXDATSPI;                          /**< SPI0 received data. These registers are half word addressable., array offset: 0x2014, array step: 0x100 */
    __IO uint32_t TXDATSPI;                          /**< SPI0 transmit data. These registers are half word addressable., array offset: 0x2018, array step: 0x100 */
         uint8_t RESERVED_0[228];
  } SPI[VFIFO_SPI_COUNT];
} VFIFO_Type;

/* ----------------------------------------------------------------------------
   -- VFIFO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VFIFO_Register_Masks VFIFO Register Masks
 * @{
 */

/*! @name FIFOCTLUSART - USART FIFO global control register. These registers are byte, halfword, and word addressable.The upper 16 bits of these registers provide information about the System FIFO configuration, and are specific to each device type. */
/*! @{ */

#define VFIFO_FIFOCTLUSART_RXPAUSE_MASK          (0x1U)
#define VFIFO_FIFOCTLUSART_RXPAUSE_SHIFT         (0U)
/*! RXPAUSE - Pause all USARTs receive FIFO operations. This can be used to prepare the System FIFO
 *    to reconfigure FIFO allocations among the USART receivers.
 */
#define VFIFO_FIFOCTLUSART_RXPAUSE(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_RXPAUSE_SHIFT)) & VFIFO_FIFOCTLUSART_RXPAUSE_MASK)

#define VFIFO_FIFOCTLUSART_RXPAUSED_MASK         (0x2U)
#define VFIFO_FIFOCTLUSART_RXPAUSED_SHIFT        (1U)
/*! RXPAUSED - All USART receive FIFOs are paused. */
#define VFIFO_FIFOCTLUSART_RXPAUSED(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_RXPAUSED_SHIFT)) & VFIFO_FIFOCTLUSART_RXPAUSED_MASK)

#define VFIFO_FIFOCTLUSART_RXEMPTY_MASK          (0x4U)
#define VFIFO_FIFOCTLUSART_RXEMPTY_SHIFT         (2U)
/*! RXEMPTY - All USART receive FIFOs are empty. */
#define VFIFO_FIFOCTLUSART_RXEMPTY(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_RXEMPTY_SHIFT)) & VFIFO_FIFOCTLUSART_RXEMPTY_MASK)

#define VFIFO_FIFOCTLUSART_TXPAUSE_MASK          (0x100U)
#define VFIFO_FIFOCTLUSART_TXPAUSE_SHIFT         (8U)
/*! TXPAUSE - Pause all USARTs transmit FIFO operations. This can be used to prepare the System FIFO
 *    to reconfigure FIFO allocations among the USART transmitters.
 */
#define VFIFO_FIFOCTLUSART_TXPAUSE(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_TXPAUSE_SHIFT)) & VFIFO_FIFOCTLUSART_TXPAUSE_MASK)

#define VFIFO_FIFOCTLUSART_TXPAUSED_MASK         (0x200U)
#define VFIFO_FIFOCTLUSART_TXPAUSED_SHIFT        (9U)
/*! TXPAUSED - All USART transmit FIFOs are paused. */
#define VFIFO_FIFOCTLUSART_TXPAUSED(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_TXPAUSED_SHIFT)) & VFIFO_FIFOCTLUSART_TXPAUSED_MASK)

#define VFIFO_FIFOCTLUSART_TXEMPTY_MASK          (0x400U)
#define VFIFO_FIFOCTLUSART_TXEMPTY_SHIFT         (10U)
/*! TXEMPTY - All USART transmit FIFOs are empty. */
#define VFIFO_FIFOCTLUSART_TXEMPTY(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_TXEMPTY_SHIFT)) & VFIFO_FIFOCTLUSART_TXEMPTY_MASK)

#define VFIFO_FIFOCTLUSART_RXFIFOTOTAL_MASK      (0xFF0000U)
#define VFIFO_FIFOCTLUSART_RXFIFOTOTAL_SHIFT     (16U)
/*! RXFIFOTOTAL - Reports the receive FIFO space available for USARTs on this FIFO. The reset value is device specific. */
#define VFIFO_FIFOCTLUSART_RXFIFOTOTAL(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_RXFIFOTOTAL_SHIFT)) & VFIFO_FIFOCTLUSART_RXFIFOTOTAL_MASK)

#define VFIFO_FIFOCTLUSART_TXFIFOTOTAL_MASK      (0xFF000000U)
#define VFIFO_FIFOCTLUSART_TXFIFOTOTAL_SHIFT     (24U)
/*! TXFIFOTOTAL - Reports the transmit FIFO space available for USARTs on this FIFO. The reset value is device specific. */
#define VFIFO_FIFOCTLUSART_TXFIFOTOTAL(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLUSART_TXFIFOTOTAL_SHIFT)) & VFIFO_FIFOCTLUSART_TXFIFOTOTAL_MASK)
/*! @} */

/*! @name FIFOUPDATEUSART - USART FIFO global update register */
/*! @{ */

#define VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE_MASK (0x1U)
#define VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE_SHIFT (0U)
/*! USART0RXUPDATESIZE - Writing 1 updates USART0 Rx FIFO size to match the USART0 RXSIZE. Must be
 *    done for all USARTs when any USART RXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE_MASK (0x2U)
#define VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE_SHIFT (1U)
/*! USART1RXUPDATESIZE - Writing 1 updates USART1 Rx FIFO size to match the USART1 RXSIZE. Must be
 *    done for all USARTs when any USART RXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE_MASK (0x4U)
#define VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE_SHIFT (2U)
/*! USART2RXUPDATESIZE - Writing 1 updates USART2 Rx FIFO size to match the USART2 RXSIZE. Must be
 *    done for all USARTs when any USART RXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE_MASK (0x8U)
#define VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE_SHIFT (3U)
/*! USART3RXUPDATESIZE - Writing 1 updates USART3 Rx FIFO size to match the USART3 RXSIZE. Must be
 *    done for all USARTs when any USART RXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE_MASK (0x10000U)
#define VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE_SHIFT (16U)
/*! USART0TXUPDATESIZE - Writing 1 updates USART0 Tx FIFO size to match the USART0 TXSIZE. Must be
 *    done for all USARTs when any USART TXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE_MASK (0x20000U)
#define VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE_SHIFT (17U)
/*! USART1TXUPDATESIZE - Writing 1 updates USART1 Tx FIFO size to match the USART1 TXSIZE. Must be
 *    done for all USARTs when any USART TXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE_MASK (0x40000U)
#define VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE_SHIFT (18U)
/*! USART2TXUPDATESIZE - Writing 1 updates USART2 Tx FIFO size to match the USART2 TXSIZE. Must be
 *    done for all USARTs when any USART TXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE_MASK (0x80000U)
#define VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE_SHIFT (19U)
/*! USART3TXUPDATESIZE - Writing 1 updates USART3 Tx FIFO size to match the USART3 TXSIZE. Must be
 *    done for all USARTs when any USART TXSIZE is changed.
 */
#define VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE_MASK)
/*! @} */

/*! @name FIFOCFGUSART - FIFO configuration register for USART0 */
/*! @{ */

#define VFIFO_FIFOCFGUSART_RXSIZE_MASK           (0xFFU)
#define VFIFO_FIFOCFGUSART_RXSIZE_SHIFT          (0U)
/*! RXSIZE - Configures the USART receive FIFO size. A zero values provides no System FIFO service for the related USART receiver. */
#define VFIFO_FIFOCFGUSART_RXSIZE(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCFGUSART_RXSIZE_SHIFT)) & VFIFO_FIFOCFGUSART_RXSIZE_MASK)

#define VFIFO_FIFOCFGUSART_TXSIZE_MASK           (0xFF00U)
#define VFIFO_FIFOCFGUSART_TXSIZE_SHIFT          (8U)
/*! TXSIZE - Configures the USART transmit FIFO size. A zero values provides no System FIFO service
 *    for the related USART transmitter.
 */
#define VFIFO_FIFOCFGUSART_TXSIZE(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCFGUSART_TXSIZE_SHIFT)) & VFIFO_FIFOCFGUSART_TXSIZE_MASK)
/*! @} */

/*! @name FIFOCTLSPI - SPI FIFO global control register. These registers are byte, halfword, and word addressable. The upper 16 bits of these registers provide information about the System FIFO configuration, and are specific to each device type. */
/*! @{ */

#define VFIFO_FIFOCTLSPI_RXPAUSE_MASK            (0x1U)
#define VFIFO_FIFOCTLSPI_RXPAUSE_SHIFT           (0U)
/*! RXPAUSE - Pause all SPIs receive FIFO operations. This can be used to prepare the System FIFO to
 *    reconfigure FIFO allocations among the SPI receivers.
 */
#define VFIFO_FIFOCTLSPI_RXPAUSE(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_RXPAUSE_SHIFT)) & VFIFO_FIFOCTLSPI_RXPAUSE_MASK)

#define VFIFO_FIFOCTLSPI_RXPAUSED_MASK           (0x2U)
#define VFIFO_FIFOCTLSPI_RXPAUSED_SHIFT          (1U)
/*! RXPAUSED - All SPI receive FIFOs are paused. */
#define VFIFO_FIFOCTLSPI_RXPAUSED(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_RXPAUSED_SHIFT)) & VFIFO_FIFOCTLSPI_RXPAUSED_MASK)

#define VFIFO_FIFOCTLSPI_RXEMPTY_MASK            (0x4U)
#define VFIFO_FIFOCTLSPI_RXEMPTY_SHIFT           (2U)
/*! RXEMPTY - All SPI receive FIFOs are empty. */
#define VFIFO_FIFOCTLSPI_RXEMPTY(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_RXEMPTY_SHIFT)) & VFIFO_FIFOCTLSPI_RXEMPTY_MASK)

#define VFIFO_FIFOCTLSPI_TXPAUSE_MASK            (0x100U)
#define VFIFO_FIFOCTLSPI_TXPAUSE_SHIFT           (8U)
/*! TXPAUSE - Pause all SPIs transmit FIFO operations. This can be used to prepare the System FIFO
 *    to reconfigure FIFO allocations among the SPI transmitters.
 */
#define VFIFO_FIFOCTLSPI_TXPAUSE(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_TXPAUSE_SHIFT)) & VFIFO_FIFOCTLSPI_TXPAUSE_MASK)

#define VFIFO_FIFOCTLSPI_TXPAUSED_MASK           (0x200U)
#define VFIFO_FIFOCTLSPI_TXPAUSED_SHIFT          (9U)
/*! TXPAUSED - All SPI transmit FIFOs are paused. */
#define VFIFO_FIFOCTLSPI_TXPAUSED(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_TXPAUSED_SHIFT)) & VFIFO_FIFOCTLSPI_TXPAUSED_MASK)

#define VFIFO_FIFOCTLSPI_TXEMPTY_MASK            (0x400U)
#define VFIFO_FIFOCTLSPI_TXEMPTY_SHIFT           (10U)
/*! TXEMPTY - All SPI transmit FIFOs are empty. */
#define VFIFO_FIFOCTLSPI_TXEMPTY(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_TXEMPTY_SHIFT)) & VFIFO_FIFOCTLSPI_TXEMPTY_MASK)

#define VFIFO_FIFOCTLSPI_RXFIFOTOTAL_MASK        (0xFF0000U)
#define VFIFO_FIFOCTLSPI_RXFIFOTOTAL_SHIFT       (16U)
/*! RXFIFOTOTAL - Reports the receive FIFO space available for SPIs on the System FIFO. The reset value is device specific. */
#define VFIFO_FIFOCTLSPI_RXFIFOTOTAL(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_RXFIFOTOTAL_SHIFT)) & VFIFO_FIFOCTLSPI_RXFIFOTOTAL_MASK)

#define VFIFO_FIFOCTLSPI_TXFIFOTOTAL_MASK        (0xFF000000U)
#define VFIFO_FIFOCTLSPI_TXFIFOTOTAL_SHIFT       (24U)
/*! TXFIFOTOTAL - Reports the transmit FIFO space available for SPIs on the System FIFO. The reset value is device specific. */
#define VFIFO_FIFOCTLSPI_TXFIFOTOTAL(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCTLSPI_TXFIFOTOTAL_SHIFT)) & VFIFO_FIFOCTLSPI_TXFIFOTOTAL_MASK)
/*! @} */

/*! @name FIFOUPDATESPI - SPI FIFO global update register */
/*! @{ */

#define VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_MASK (0x1U)
#define VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_SHIFT (0U)
/*! SPI0RXUPDATESIZE - Writing 1 updates SPI0 Rx FIFO size to match the SPI0 RXSIZE. Must be done for all SPIs when any SPI RXSIZE is changed. */
#define VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE(x)  (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATESPI_SPI0RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_MASK (0x2U)
#define VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_SHIFT (1U)
/*! SPI1RXUPDATESIZE - Writing 1 updates SPI1 Rx FIFO size to match the SPI1 RXSIZE. Must be done for all SPIs when any SPI RXSIZE is changed. */
#define VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE(x)  (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATESPI_SPI1RXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_MASK (0x10000U)
#define VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_SHIFT (16U)
/*! SPI0TXUPDATESIZE - Writing 1 updates SPI0 Tx FIFO size to match the SPI0 TXSIZE. Must be done for all SPIs when any SPI TXSIZE is changed. */
#define VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE(x)  (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATESPI_SPI0TXUPDATESIZE_MASK)

#define VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_MASK (0x20000U)
#define VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_SHIFT (17U)
/*! SPI1TXUPDATESIZE - Writing 1 updates SPI1 Tx FIFO size to match the SPI1 TXSIZE. Must be done for all SPIs when any SPI TXSIZE is changed. */
#define VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE(x)  (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_SHIFT)) & VFIFO_FIFOUPDATESPI_SPI1TXUPDATESIZE_MASK)
/*! @} */

/*! @name FIFOCFGSPI - FIFO configuration register for SPI0 */
/*! @{ */

#define VFIFO_FIFOCFGSPI_RXSIZE_MASK             (0xFFU)
#define VFIFO_FIFOCFGSPI_RXSIZE_SHIFT            (0U)
/*! RXSIZE - Configures the SPI receive FIFO size. A zero values provides no System FIFO service for the related SPI receiver. */
#define VFIFO_FIFOCFGSPI_RXSIZE(x)               (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCFGSPI_RXSIZE_SHIFT)) & VFIFO_FIFOCFGSPI_RXSIZE_MASK)

#define VFIFO_FIFOCFGSPI_TXSIZE_MASK             (0xFF00U)
#define VFIFO_FIFOCFGSPI_TXSIZE_SHIFT            (8U)
/*! TXSIZE - Configures the SPI transmit FIFO size. A zero values provides no System FIFO service for the related SPI transmitter. */
#define VFIFO_FIFOCFGSPI_TXSIZE(x)               (((uint32_t)(((uint32_t)(x)) << VFIFO_FIFOCFGSPI_TXSIZE_SHIFT)) & VFIFO_FIFOCFGSPI_TXSIZE_MASK)
/*! @} */

/*! @name USART_CFGUSART - USART0 configuration */
/*! @{ */

#define VFIFO_USART_CFGUSART_TIMEOUTCONTONWRITE_MASK (0x10U)
#define VFIFO_USART_CFGUSART_TIMEOUTCONTONWRITE_SHIFT (4U)
/*! TIMEOUTCONTONWRITE - Timeout Continue On Write. When 0, the timeout for the related peripheral
 *    is reset every time data is transferred from the peripheral into the receive FIFO. When 1, the
 *    timeout for the related peripheral is not reset every time data is transferred into the
 *    receive FIFO. This allows the timeout to be applied to accumulated data, perhaps related to the FIFO
 *    threshold.
 */
#define VFIFO_USART_CFGUSART_TIMEOUTCONTONWRITE(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_TIMEOUTCONTONWRITE_SHIFT)) & VFIFO_USART_CFGUSART_TIMEOUTCONTONWRITE_MASK)

#define VFIFO_USART_CFGUSART_TIMEOUTCONTONEMPTY_MASK (0x20U)
#define VFIFO_USART_CFGUSART_TIMEOUTCONTONEMPTY_SHIFT (5U)
/*! TIMEOUTCONTONEMPTY - Timeout Continue On Empty. When 0, the timeout for the related peripheral
 *    is reset when the receive FIFO becomes empty. When 1, the timeout for the related peripheral is
 *    not reset when the receive FIFO becomes empty. This allows the timeout to be used to flag
 *    idle peripherals, and could potentially be used to indicate the end of a transmission of
 *    indeterminate length.
 */
#define VFIFO_USART_CFGUSART_TIMEOUTCONTONEMPTY(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_TIMEOUTCONTONEMPTY_SHIFT)) & VFIFO_USART_CFGUSART_TIMEOUTCONTONEMPTY_MASK)

#define VFIFO_USART_CFGUSART_TIMEOUTBASE_MASK    (0xF00U)
#define VFIFO_USART_CFGUSART_TIMEOUTBASE_SHIFT   (8U)
/*! TIMEOUTBASE - Specifies the least significant timer bit to compare to TimeoutValue. See Section
 *    24.5.7.1 below. Value can be 0 through 15.
 */
#define VFIFO_USART_CFGUSART_TIMEOUTBASE(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_TIMEOUTBASE_SHIFT)) & VFIFO_USART_CFGUSART_TIMEOUTBASE_MASK)

#define VFIFO_USART_CFGUSART_TIMEOUTVALUE_MASK   (0xF000U)
#define VFIFO_USART_CFGUSART_TIMEOUTVALUE_SHIFT  (12U)
/*! TIMEOUTVALUE - Specifies the maximum time value for timeout at the timer position identified by
 *    TimeoutBase. Minimum time TimeoutValue - 1. is See Section 24.5.7.1 below. TimeoutValue should
 *    not be 0 or 1 when timeout is enabled.
 */
#define VFIFO_USART_CFGUSART_TIMEOUTVALUE(x)     (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_TIMEOUTVALUE_SHIFT)) & VFIFO_USART_CFGUSART_TIMEOUTVALUE_MASK)

#define VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK    (0xFF0000U)
#define VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT   (16U)
/*! RXTHRESHOLD - Receive FIFO Threshold. The System FIFO indicates that the threshold has been
 *    reached when the number of entries in the receive FIFO is greater than this value. For example,
 *    when RxThreshold = 0, the threshold is exceeded when there is at least one entry in the receive
 *    FIFO. An interrupt can be generated when the RxThreshold has been reached (see Section
 *    24.5.10), but has no effect on DMA requests, which are generated whenever the receiver FIFO is not
 *    empty.
 */
#define VFIFO_USART_CFGUSART_RXTHRESHOLD(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT)) & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK)

#define VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK    (0xFF000000U)
#define VFIFO_USART_CFGUSART_TXTHRESHOLD_SHIFT   (24U)
/*! TXTHRESHOLD - Transmit FIFO Threshold. The System FIFO indicates that the threshold has been
 *    reached when the number of free entries in the transmit FIFO is less than or equal to this value.
 *    For example, when TxThreshold = 0, the threshold is exceeded when there is at least one free
 *    entry in the transmit FIFO. An interrupt can be generated when the TxThreshold has been
 *    reached (see Section 24.5.10), but has no effect on DMA requests, which are generated whenever the
 *    transmit FIFO has any free entries.
 */
#define VFIFO_USART_CFGUSART_TXTHRESHOLD(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CFGUSART_TXTHRESHOLD_SHIFT)) & VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK)
/*! @} */

/* The count of VFIFO_USART_CFGUSART */
#define VFIFO_USART_CFGUSART_COUNT               (4U)

/*! @name USART_STATUSART - USART0 status */
/*! @{ */

#define VFIFO_USART_STATUSART_RXTH_MASK          (0x1U)
#define VFIFO_USART_STATUSART_RXTH_SHIFT         (0U)
/*! RXTH - Receive FIFO Threshold. When 1, the receive FIFO threshold has been reached. This is a read-only bit. */
#define VFIFO_USART_STATUSART_RXTH(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_RXTH_SHIFT)) & VFIFO_USART_STATUSART_RXTH_MASK)

#define VFIFO_USART_STATUSART_TXTH_MASK          (0x2U)
#define VFIFO_USART_STATUSART_TXTH_SHIFT         (1U)
/*! TXTH - Transmit FIFO Threshold. When 1, the transmit FIFO threshold has been reached. This is a read-only bit. */
#define VFIFO_USART_STATUSART_TXTH(x)            (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_TXTH_SHIFT)) & VFIFO_USART_STATUSART_TXTH_MASK)

#define VFIFO_USART_STATUSART_RXTIMEOUT_MASK     (0x10U)
#define VFIFO_USART_STATUSART_RXTIMEOUT_SHIFT    (4U)
/*! RXTIMEOUT - Receive FIFO Timeout. When 1, the receive FIFO has timed out, based on the timeout
 *    configuration in the CFGUSART register. The timeout condition can be cleared by writing a 1 to
 *    this bit, by enabling or disabling the timeout interrupt, or by writing a 1 to the timeout
 *    interrupt enable.
 */
#define VFIFO_USART_STATUSART_RXTIMEOUT(x)       (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_RXTIMEOUT_SHIFT)) & VFIFO_USART_STATUSART_RXTIMEOUT_MASK)

#define VFIFO_USART_STATUSART_BUSERR_MASK        (0x80U)
#define VFIFO_USART_STATUSART_BUSERR_SHIFT       (7U)
/*! BUSERR - Bus Error. When 1, a bus error has occurred while processing data for USARTn. The bus
 *    error flag can be cleared by writing a 1 to this bit.
 */
#define VFIFO_USART_STATUSART_BUSERR(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_BUSERR_SHIFT)) & VFIFO_USART_STATUSART_BUSERR_MASK)

#define VFIFO_USART_STATUSART_RXEMPTY_MASK       (0x100U)
#define VFIFO_USART_STATUSART_RXEMPTY_SHIFT      (8U)
/*! RXEMPTY - Receive FIFO Empty. When 1, the receive FIFO is currently empty. This is a read-only bit. */
#define VFIFO_USART_STATUSART_RXEMPTY(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_RXEMPTY_SHIFT)) & VFIFO_USART_STATUSART_RXEMPTY_MASK)

#define VFIFO_USART_STATUSART_TXEMPTY_MASK       (0x200U)
#define VFIFO_USART_STATUSART_TXEMPTY_SHIFT      (9U)
/*! TXEMPTY - Transmit FIFO Empty. When 1, the transmit FIFO is currently empty. This is a read-only bit. */
#define VFIFO_USART_STATUSART_TXEMPTY(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_TXEMPTY_SHIFT)) & VFIFO_USART_STATUSART_TXEMPTY_MASK)

#define VFIFO_USART_STATUSART_RXCOUNT_MASK       (0xFF0000U)
#define VFIFO_USART_STATUSART_RXCOUNT_SHIFT      (16U)
/*! RXCOUNT - Receive FIFO Count. Indicates how many entries may be read from the receive FIFO. 0 =
 *    FIFO empty. This is a read-only field.
 */
#define VFIFO_USART_STATUSART_RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_RXCOUNT_SHIFT)) & VFIFO_USART_STATUSART_RXCOUNT_MASK)

#define VFIFO_USART_STATUSART_TXCOUNT_MASK       (0xFF000000U)
#define VFIFO_USART_STATUSART_TXCOUNT_SHIFT      (24U)
/*! TXCOUNT - Transmit FIFO Count. Indicates how many entries may be written to the transmit FIFO. 0
 *    = FIFO full. This is a read-only field that is valid only when the TxFIFO is fully configured
 *    and enabled.
 */
#define VFIFO_USART_STATUSART_TXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_STATUSART_TXCOUNT_SHIFT)) & VFIFO_USART_STATUSART_TXCOUNT_MASK)
/*! @} */

/* The count of VFIFO_USART_STATUSART */
#define VFIFO_USART_STATUSART_COUNT              (4U)

/*! @name USART_INTSTATUSART - USART0 interrupt status */
/*! @{ */

#define VFIFO_USART_INTSTATUSART_RXTH_MASK       (0x1U)
#define VFIFO_USART_INTSTATUSART_RXTH_SHIFT      (0U)
/*! RXTH - Receive FIFO Threshold. When 1, the receive FIFO threshold has been reached, and the related interrupt is enabled. */
#define VFIFO_USART_INTSTATUSART_RXTH(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_RXTH_SHIFT)) & VFIFO_USART_INTSTATUSART_RXTH_MASK)

#define VFIFO_USART_INTSTATUSART_TXTH_MASK       (0x2U)
#define VFIFO_USART_INTSTATUSART_TXTH_SHIFT      (1U)
/*! TXTH - Transmit FIFO Threshold. When 1, the transmit FIFO threshold has been reached, and the related interrupt is enabled. */
#define VFIFO_USART_INTSTATUSART_TXTH(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_TXTH_SHIFT)) & VFIFO_USART_INTSTATUSART_TXTH_MASK)

#define VFIFO_USART_INTSTATUSART_RXTIMEOUT_MASK  (0x10U)
#define VFIFO_USART_INTSTATUSART_RXTIMEOUT_SHIFT (4U)
/*! RXTIMEOUT - Receive Timeout. When 1, the receive FIFO has timed out, based on the timeout
 *    configuration in the CFGUSART register, and the related interrupt is enabled.
 */
#define VFIFO_USART_INTSTATUSART_RXTIMEOUT(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_RXTIMEOUT_SHIFT)) & VFIFO_USART_INTSTATUSART_RXTIMEOUT_MASK)

#define VFIFO_USART_INTSTATUSART_BUSERR_MASK     (0x80U)
#define VFIFO_USART_INTSTATUSART_BUSERR_SHIFT    (7U)
/*! BUSERR - Bus Error. This is simply a copy of the same bit in the STATUSART register. The bus error interrupt is always enabled. */
#define VFIFO_USART_INTSTATUSART_BUSERR(x)       (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_BUSERR_SHIFT)) & VFIFO_USART_INTSTATUSART_BUSERR_MASK)

#define VFIFO_USART_INTSTATUSART_RXEMPTY_MASK    (0x100U)
#define VFIFO_USART_INTSTATUSART_RXEMPTY_SHIFT   (8U)
/*! RXEMPTY - Receive FIFO Empty. This is simply a copy of the same bit in the STATUSART register. */
#define VFIFO_USART_INTSTATUSART_RXEMPTY(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_RXEMPTY_SHIFT)) & VFIFO_USART_INTSTATUSART_RXEMPTY_MASK)

#define VFIFO_USART_INTSTATUSART_TXEMPTY_MASK    (0x200U)
#define VFIFO_USART_INTSTATUSART_TXEMPTY_SHIFT   (9U)
/*! TXEMPTY - Transmit FIFO Empty. This is simply a copy of the same bit in the STATUSART register. */
#define VFIFO_USART_INTSTATUSART_TXEMPTY(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_TXEMPTY_SHIFT)) & VFIFO_USART_INTSTATUSART_TXEMPTY_MASK)

#define VFIFO_USART_INTSTATUSART_RXCOUNT_MASK    (0xFF0000U)
#define VFIFO_USART_INTSTATUSART_RXCOUNT_SHIFT   (16U)
/*! RXCOUNT - Receive FIFO Count. This is simply a copy of the same field in the STATUSART register,
 *    included here so an ISR can read all needed status information in one read.
 */
#define VFIFO_USART_INTSTATUSART_RXCOUNT(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_RXCOUNT_SHIFT)) & VFIFO_USART_INTSTATUSART_RXCOUNT_MASK)

#define VFIFO_USART_INTSTATUSART_TXCOUNT_MASK    (0xFF000000U)
#define VFIFO_USART_INTSTATUSART_TXCOUNT_SHIFT   (24U)
/*! TXCOUNT - Transmit FIFO Available. This is simply a copy of the same field in the STATUSART
 *    register, included here so an ISR can read all needed status information in one read.
 */
#define VFIFO_USART_INTSTATUSART_TXCOUNT(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_INTSTATUSART_TXCOUNT_SHIFT)) & VFIFO_USART_INTSTATUSART_TXCOUNT_MASK)
/*! @} */

/* The count of VFIFO_USART_INTSTATUSART */
#define VFIFO_USART_INTSTATUSART_COUNT           (4U)

/*! @name USART_CTLSETUSART - USART0 control read and set register. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set. */
/*! @{ */

#define VFIFO_USART_CTLSETUSART_RXTHINTEN_MASK   (0x1U)
#define VFIFO_USART_CTLSETUSART_RXTHINTEN_SHIFT  (0U)
/*! RXTHINTEN - Receive FIFO Threshold Interrupt Enable. */
#define VFIFO_USART_CTLSETUSART_RXTHINTEN(x)     (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLSETUSART_RXTHINTEN_SHIFT)) & VFIFO_USART_CTLSETUSART_RXTHINTEN_MASK)

#define VFIFO_USART_CTLSETUSART_TXTHINTEN_MASK   (0x2U)
#define VFIFO_USART_CTLSETUSART_TXTHINTEN_SHIFT  (1U)
/*! TXTHINTEN - Transmit FIFO Threshold Interrupt Enable. */
#define VFIFO_USART_CTLSETUSART_TXTHINTEN(x)     (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLSETUSART_TXTHINTEN_SHIFT)) & VFIFO_USART_CTLSETUSART_TXTHINTEN_MASK)

#define VFIFO_USART_CTLSETUSART_RXTIMEOUTINTEN_MASK (0x10U)
#define VFIFO_USART_CTLSETUSART_RXTIMEOUTINTEN_SHIFT (4U)
/*! RXTIMEOUTINTEN - Receive FIFO Timeout Interrupt Enable. When enabled, this also enables the
 *    timeout for this USART. Writing a 1 to this bit resets the USART timeout logic.
 */
#define VFIFO_USART_CTLSETUSART_RXTIMEOUTINTEN(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLSETUSART_RXTIMEOUTINTEN_SHIFT)) & VFIFO_USART_CTLSETUSART_RXTIMEOUTINTEN_MASK)

#define VFIFO_USART_CTLSETUSART_RXFLUSH_MASK     (0x100U)
#define VFIFO_USART_CTLSETUSART_RXFLUSH_SHIFT    (8U)
/*! RXFLUSH - Receive FIFO flush. Writing a 1 to this bit forces the receive FIFO to be empty. */
#define VFIFO_USART_CTLSETUSART_RXFLUSH(x)       (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLSETUSART_RXFLUSH_SHIFT)) & VFIFO_USART_CTLSETUSART_RXFLUSH_MASK)

#define VFIFO_USART_CTLSETUSART_TXFLUSH_MASK     (0x200U)
#define VFIFO_USART_CTLSETUSART_TXFLUSH_SHIFT    (9U)
/*! TXFLUSH - Transmit FIFO flush. Writing a 1 to this bit forces the transmit FIFO to be empty. */
#define VFIFO_USART_CTLSETUSART_TXFLUSH(x)       (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLSETUSART_TXFLUSH_SHIFT)) & VFIFO_USART_CTLSETUSART_TXFLUSH_MASK)
/*! @} */

/* The count of VFIFO_USART_CTLSETUSART */
#define VFIFO_USART_CTLSETUSART_COUNT            (4U)

/*! @name USART_CTLCLRUSART - USART0 control clear register. Writing a 1 to any implemented bit position causes the corresponding bit in the related CTLSET register to be cleared. */
/*! @{ */

#define VFIFO_USART_CTLCLRUSART_RXTHINTCLR_MASK  (0x1U)
#define VFIFO_USART_CTLCLRUSART_RXTHINTCLR_SHIFT (0U)
/*! RXTHINTCLR - Receive FIFO Threshold Interrupt clear. */
#define VFIFO_USART_CTLCLRUSART_RXTHINTCLR(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLCLRUSART_RXTHINTCLR_SHIFT)) & VFIFO_USART_CTLCLRUSART_RXTHINTCLR_MASK)

#define VFIFO_USART_CTLCLRUSART_TXTHINTCLR_MASK  (0x2U)
#define VFIFO_USART_CTLCLRUSART_TXTHINTCLR_SHIFT (1U)
/*! TXTHINTCLR - Transmit FIFO Threshold Interrupt clear. */
#define VFIFO_USART_CTLCLRUSART_TXTHINTCLR(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLCLRUSART_TXTHINTCLR_SHIFT)) & VFIFO_USART_CTLCLRUSART_TXTHINTCLR_MASK)

#define VFIFO_USART_CTLCLRUSART_RXTIMEOUTINTCLR_MASK (0x10U)
#define VFIFO_USART_CTLCLRUSART_RXTIMEOUTINTCLR_SHIFT (4U)
/*! RXTIMEOUTINTCLR - Receive FIFO Time-out Interrupt clear. */
#define VFIFO_USART_CTLCLRUSART_RXTIMEOUTINTCLR(x) (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLCLRUSART_RXTIMEOUTINTCLR_SHIFT)) & VFIFO_USART_CTLCLRUSART_RXTIMEOUTINTCLR_MASK)

#define VFIFO_USART_CTLCLRUSART_RXFLUSHCLR_MASK  (0x100U)
#define VFIFO_USART_CTLCLRUSART_RXFLUSHCLR_SHIFT (8U)
/*! RXFLUSHCLR - Receive FIFO flush clear. */
#define VFIFO_USART_CTLCLRUSART_RXFLUSHCLR(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLCLRUSART_RXFLUSHCLR_SHIFT)) & VFIFO_USART_CTLCLRUSART_RXFLUSHCLR_MASK)

#define VFIFO_USART_CTLCLRUSART_TXFLUSHCLR_MASK  (0x200U)
#define VFIFO_USART_CTLCLRUSART_TXFLUSHCLR_SHIFT (9U)
/*! TXFLUSHCLR - Transmit FIFO flush clear. */
#define VFIFO_USART_CTLCLRUSART_TXFLUSHCLR(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_CTLCLRUSART_TXFLUSHCLR_SHIFT)) & VFIFO_USART_CTLCLRUSART_TXFLUSHCLR_MASK)
/*! @} */

/* The count of VFIFO_USART_CTLCLRUSART */
#define VFIFO_USART_CTLCLRUSART_COUNT            (4U)

/*! @name USART_RXDATUSART - USART0 received data */
/*! @{ */

#define VFIFO_USART_RXDATUSART_RXDAT_MASK        (0x1FFU)
#define VFIFO_USART_RXDATUSART_RXDAT_SHIFT       (0U)
/*! RXDAT - The UART Receiver Data register contains the next received character. The number of bits
 *    that are relevant depends on the UART configuration settings.
 */
#define VFIFO_USART_RXDATUSART_RXDAT(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_RXDATUSART_RXDAT_SHIFT)) & VFIFO_USART_RXDATUSART_RXDAT_MASK)
/*! @} */

/* The count of VFIFO_USART_RXDATUSART */
#define VFIFO_USART_RXDATUSART_COUNT             (4U)

/*! @name USART_RXDATSTATUSART - USART0 received data with status */
/*! @{ */

#define VFIFO_USART_RXDATSTATUSART_RXDAT_MASK    (0x1FFU)
#define VFIFO_USART_RXDATSTATUSART_RXDAT_SHIFT   (0U)
/*! RXDAT - The UART Receiver Data register contains the next received character. The number of bits
 *    that are relevant depends on the UART configuration settings.
 */
#define VFIFO_USART_RXDATSTATUSART_RXDAT(x)      (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_RXDATSTATUSART_RXDAT_SHIFT)) & VFIFO_USART_RXDATSTATUSART_RXDAT_MASK)

#define VFIFO_USART_RXDATSTATUSART_FRAMERR_MASK  (0x2000U)
#define VFIFO_USART_RXDATSTATUSART_FRAMERR_SHIFT (13U)
/*! FRAMERR - Framing Error status flag. This bit is valid when there is a character to be read in
 *    the RXDAT register and reflects the status of that character. This bit will set when the
 *    character in RXDAT was received with a missing stop bit at the expected location. This could be an
 *    indication of a baud rate or configuration mismatch with the transmitting source.
 */
#define VFIFO_USART_RXDATSTATUSART_FRAMERR(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_RXDATSTATUSART_FRAMERR_SHIFT)) & VFIFO_USART_RXDATSTATUSART_FRAMERR_MASK)

#define VFIFO_USART_RXDATSTATUSART_PARITYERR_MASK (0x4000U)
#define VFIFO_USART_RXDATSTATUSART_PARITYERR_SHIFT (14U)
/*! PARITYERR - Parity Error status flag. This bit is valid when there is a character to be read in
 *    the RXDAT register and reflects the status of that character. This bit will be set when a
 *    parity error is detected in a received character.
 */
#define VFIFO_USART_RXDATSTATUSART_PARITYERR(x)  (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_RXDATSTATUSART_PARITYERR_SHIFT)) & VFIFO_USART_RXDATSTATUSART_PARITYERR_MASK)

#define VFIFO_USART_RXDATSTATUSART_RXNOISE_MASK  (0x8000U)
#define VFIFO_USART_RXDATSTATUSART_RXNOISE_SHIFT (15U)
/*! RXNOISE - Received Noise flag. */
#define VFIFO_USART_RXDATSTATUSART_RXNOISE(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_RXDATSTATUSART_RXNOISE_SHIFT)) & VFIFO_USART_RXDATSTATUSART_RXNOISE_MASK)
/*! @} */

/* The count of VFIFO_USART_RXDATSTATUSART */
#define VFIFO_USART_RXDATSTATUSART_COUNT         (4U)

/*! @name USART_TXDATUSART - USART0 transmit data */
/*! @{ */

#define VFIFO_USART_TXDATUSART_TXDAT_MASK        (0x1FFU)
#define VFIFO_USART_TXDATUSART_TXDAT_SHIFT       (0U)
/*! TXDAT - Writing to the UART Transmit Data Register causes the data to be transmitted as soon as
 *    the transmit shift register is available and the condition for transmitting data is met: TXDIS
 *    bit = 0.
 */
#define VFIFO_USART_TXDATUSART_TXDAT(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_USART_TXDATUSART_TXDAT_SHIFT)) & VFIFO_USART_TXDATUSART_TXDAT_MASK)
/*! @} */

/* The count of VFIFO_USART_TXDATUSART */
#define VFIFO_USART_TXDATUSART_COUNT             (4U)

/*! @name SPI_CFGSPI - SPI0 configuration */
/*! @{ */

#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONWRITE_MASK (0x10U)
#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONWRITE_SHIFT (4U)
/*! TIMEOUTCONTONWRITE - Timeout Continue On Write. When 0, the timeout for the related peripheral
 *    is reset every time data is transferred from the peripheral into the receive FIFO. When 1, the
 *    timeout for the related peripheral is not reset every time data is transferred into the
 *    receive FIFO. This allows the timeout to be applied to accumulated data, perhaps related to the FIFO
 *    threshold.
 */
#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONWRITE(x)   (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_TIMEOUTCONTONWRITE_SHIFT)) & VFIFO_SPI_CFGSPI_TIMEOUTCONTONWRITE_MASK)

#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONEMPTY_MASK (0x20U)
#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONEMPTY_SHIFT (5U)
/*! TIMEOUTCONTONEMPTY - Timeout Continue On Empty. When 0, the timeout for the related peripheral
 *    is reset when the receive FIFO becomes empty. When 1, the timeout for the related peripheral is
 *    not reset when the receive FIFO becomes empty. This allows the timeout to be used to flag
 *    idle peripherals, and could potentially be used to indicate the end of a transmission of
 *    indeterminate length.
 */
#define VFIFO_SPI_CFGSPI_TIMEOUTCONTONEMPTY(x)   (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_TIMEOUTCONTONEMPTY_SHIFT)) & VFIFO_SPI_CFGSPI_TIMEOUTCONTONEMPTY_MASK)

#define VFIFO_SPI_CFGSPI_TIMEOUTBASE_MASK        (0xF00U)
#define VFIFO_SPI_CFGSPI_TIMEOUTBASE_SHIFT       (8U)
/*! TIMEOUTBASE - Specifies the least significant timer bit to compare to TimeoutValue. Value can be 0 through 15. */
#define VFIFO_SPI_CFGSPI_TIMEOUTBASE(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_TIMEOUTBASE_SHIFT)) & VFIFO_SPI_CFGSPI_TIMEOUTBASE_MASK)

#define VFIFO_SPI_CFGSPI_TIMEOUTVALUE_MASK       (0xF000U)
#define VFIFO_SPI_CFGSPI_TIMEOUTVALUE_SHIFT      (12U)
/*! TIMEOUTVALUE - Specifies the maximum time value for timeout at the timer position identified by
 *    TimeoutBase. Minimum time TimeoutValue - 1. TimeoutValue should not be 0 or 1 when timeout is
 *    enabled.
 */
#define VFIFO_SPI_CFGSPI_TIMEOUTVALUE(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_TIMEOUTVALUE_SHIFT)) & VFIFO_SPI_CFGSPI_TIMEOUTVALUE_MASK)

#define VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK        (0xFF0000U)
#define VFIFO_SPI_CFGSPI_RXTHRESHOLD_SHIFT       (16U)
/*! RXTHRESHOLD - Receive FIFO Threshold. The System FIFO indicates that the threshold has been
 *    reached when the number of entries in the receive FIFO is greater than this value. For example,
 *    when RxThreshold = 0, the threshold is exceeded when there is at least one entry in the receive
 *    FIFO. An interrupt can be generated when the RxThreshold has been reached, but has no effect
 *    on DMA requests, which are generated whenever the receiver FIFO is not empty.
 */
#define VFIFO_SPI_CFGSPI_RXTHRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_RXTHRESHOLD_SHIFT)) & VFIFO_SPI_CFGSPI_RXTHRESHOLD_MASK)

#define VFIFO_SPI_CFGSPI_TXTHRESHOLD_MASK        (0xFF000000U)
#define VFIFO_SPI_CFGSPI_TXTHRESHOLD_SHIFT       (24U)
/*! TXTHRESHOLD - Transmit FIFO Threshold. The System FIFO indicates that the threshold has been
 *    reached when the number of free entries in the transmit FIFO is less than or equal to this value.
 *    For example, when TxThreshold = 0, the threshold is exceeded when there is at least one free
 *    entry in the transmit FIFO. An interrupt can be generated when the TxThreshold has been
 *    reached, but has no effect on DMA requests, which are generated whenever the transmit FIFO has any
 *    free entries.
 */
#define VFIFO_SPI_CFGSPI_TXTHRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CFGSPI_TXTHRESHOLD_SHIFT)) & VFIFO_SPI_CFGSPI_TXTHRESHOLD_MASK)
/*! @} */

/* The count of VFIFO_SPI_CFGSPI */
#define VFIFO_SPI_CFGSPI_COUNT                   (2U)

/*! @name SPI_STATSPI - SPI0 status */
/*! @{ */

#define VFIFO_SPI_STATSPI_RXTH_MASK              (0x1U)
#define VFIFO_SPI_STATSPI_RXTH_SHIFT             (0U)
/*! RXTH - Receive FIFO Threshold. When 1, the receive FIFO threshold has been reached. This is a read-only bit. */
#define VFIFO_SPI_STATSPI_RXTH(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_RXTH_SHIFT)) & VFIFO_SPI_STATSPI_RXTH_MASK)

#define VFIFO_SPI_STATSPI_TXTH_MASK              (0x2U)
#define VFIFO_SPI_STATSPI_TXTH_SHIFT             (1U)
/*! TXTH - Transmit FIFO Threshold. When 1, the transmit FIFO threshold has been reached. This is a read-only bit. */
#define VFIFO_SPI_STATSPI_TXTH(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_TXTH_SHIFT)) & VFIFO_SPI_STATSPI_TXTH_MASK)

#define VFIFO_SPI_STATSPI_RXTIMEOUT_MASK         (0x10U)
#define VFIFO_SPI_STATSPI_RXTIMEOUT_SHIFT        (4U)
/*! RXTIMEOUT - Receive FIFO Timeout. When 1, the receive FIFO has timed out, based on the timeout
 *    configuration in the CFGSPI register. The timeout condition can be cleared by writing a 1 to
 *    this bit, by enabling or disabling the timeout interrupt, or by writing a 1 to the timeout
 *    interrupt enable.
 */
#define VFIFO_SPI_STATSPI_RXTIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_RXTIMEOUT_SHIFT)) & VFIFO_SPI_STATSPI_RXTIMEOUT_MASK)

#define VFIFO_SPI_STATSPI_BUSERR_MASK            (0x80U)
#define VFIFO_SPI_STATSPI_BUSERR_SHIFT           (7U)
/*! BUSERR - Bus Error. When 1, a bus error has occurred while processing data for SPI. The bus
 *    error flag can be cleared by writing a 1 to this bit.
 */
#define VFIFO_SPI_STATSPI_BUSERR(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_BUSERR_SHIFT)) & VFIFO_SPI_STATSPI_BUSERR_MASK)

#define VFIFO_SPI_STATSPI_RXEMPTY_MASK           (0x100U)
#define VFIFO_SPI_STATSPI_RXEMPTY_SHIFT          (8U)
/*! RXEMPTY - Receive FIFO Empty. When 1, the receive FIFO is currently empty. This is a read-only bit. */
#define VFIFO_SPI_STATSPI_RXEMPTY(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_RXEMPTY_SHIFT)) & VFIFO_SPI_STATSPI_RXEMPTY_MASK)

#define VFIFO_SPI_STATSPI_TXEMPTY_MASK           (0x200U)
#define VFIFO_SPI_STATSPI_TXEMPTY_SHIFT          (9U)
/*! TXEMPTY - Transmit FIFO Empty. When 1, the transmit FIFO is currently empty. This is a read-only bit. */
#define VFIFO_SPI_STATSPI_TXEMPTY(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_TXEMPTY_SHIFT)) & VFIFO_SPI_STATSPI_TXEMPTY_MASK)

#define VFIFO_SPI_STATSPI_RXCOUNT_MASK           (0xFF0000U)
#define VFIFO_SPI_STATSPI_RXCOUNT_SHIFT          (16U)
/*! RXCOUNT - Receive FIFO Count. Indicates how many entries may be read from the receive FIFO. 0 =
 *    FIFO empty. This is a read-only field.
 */
#define VFIFO_SPI_STATSPI_RXCOUNT(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_RXCOUNT_SHIFT)) & VFIFO_SPI_STATSPI_RXCOUNT_MASK)

#define VFIFO_SPI_STATSPI_TXCOUNT_MASK           (0xFF000000U)
#define VFIFO_SPI_STATSPI_TXCOUNT_SHIFT          (24U)
/*! TXCOUNT - Transmit FIFO Count. Indicates how many entries may be written to the transmit FIFO. 0
 *    = FIFO full. This is a read-only field that is valid only when the TxFIFO is fully configured
 *    and enabled.
 */
#define VFIFO_SPI_STATSPI_TXCOUNT(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_STATSPI_TXCOUNT_SHIFT)) & VFIFO_SPI_STATSPI_TXCOUNT_MASK)
/*! @} */

/* The count of VFIFO_SPI_STATSPI */
#define VFIFO_SPI_STATSPI_COUNT                  (2U)

/*! @name SPI_INTSTATSPI - SPI0 interrupt status */
/*! @{ */

#define VFIFO_SPI_INTSTATSPI_RXTH_MASK           (0x1U)
#define VFIFO_SPI_INTSTATSPI_RXTH_SHIFT          (0U)
/*! RXTH - Receive FIFO Threshold. When 1, the receive FIFO threshold has been reached, and the related interrupt is enabled. */
#define VFIFO_SPI_INTSTATSPI_RXTH(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_RXTH_SHIFT)) & VFIFO_SPI_INTSTATSPI_RXTH_MASK)

#define VFIFO_SPI_INTSTATSPI_TXTH_MASK           (0x2U)
#define VFIFO_SPI_INTSTATSPI_TXTH_SHIFT          (1U)
/*! TXTH - Transmit FIFO Threshold. When 1, the transmit FIFO threshold has been reached, and the related interrupt is enabled. */
#define VFIFO_SPI_INTSTATSPI_TXTH(x)             (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_TXTH_SHIFT)) & VFIFO_SPI_INTSTATSPI_TXTH_MASK)

#define VFIFO_SPI_INTSTATSPI_RXTIMEOUT_MASK      (0x10U)
#define VFIFO_SPI_INTSTATSPI_RXTIMEOUT_SHIFT     (4U)
/*! RXTIMEOUT - Receive Timeout. When 1, the receive FIFO has timed out, based on the timeout
 *    configuration in the CFGSPI register, and the related interrupt is enabled.
 */
#define VFIFO_SPI_INTSTATSPI_RXTIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_RXTIMEOUT_SHIFT)) & VFIFO_SPI_INTSTATSPI_RXTIMEOUT_MASK)

#define VFIFO_SPI_INTSTATSPI_BUSERR_MASK         (0x80U)
#define VFIFO_SPI_INTSTATSPI_BUSERR_SHIFT        (7U)
/*! BUSERR - Bus Error. This is simply a copy of the same bit in the STATSPI register. The bus error interrupt is always enabled. */
#define VFIFO_SPI_INTSTATSPI_BUSERR(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_BUSERR_SHIFT)) & VFIFO_SPI_INTSTATSPI_BUSERR_MASK)

#define VFIFO_SPI_INTSTATSPI_RXEMPTY_MASK        (0x100U)
#define VFIFO_SPI_INTSTATSPI_RXEMPTY_SHIFT       (8U)
/*! RXEMPTY - Receive FIFO Empty. This is simply a copy of the same bit in the STATSPI register. */
#define VFIFO_SPI_INTSTATSPI_RXEMPTY(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_RXEMPTY_SHIFT)) & VFIFO_SPI_INTSTATSPI_RXEMPTY_MASK)

#define VFIFO_SPI_INTSTATSPI_TXEMPTY_MASK        (0x200U)
#define VFIFO_SPI_INTSTATSPI_TXEMPTY_SHIFT       (9U)
/*! TXEMPTY - Transmit FIFO Empty. This is simply a copy of the same bit in the STATSPI register. */
#define VFIFO_SPI_INTSTATSPI_TXEMPTY(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_TXEMPTY_SHIFT)) & VFIFO_SPI_INTSTATSPI_TXEMPTY_MASK)

#define VFIFO_SPI_INTSTATSPI_RXCOUNT_MASK        (0xFF0000U)
#define VFIFO_SPI_INTSTATSPI_RXCOUNT_SHIFT       (16U)
/*! RXCOUNT - Receive FIFO Count. This is simply a copy of the same field in the STATSPI register,
 *    included here so an ISR can read all needed status information in one read.
 */
#define VFIFO_SPI_INTSTATSPI_RXCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_RXCOUNT_SHIFT)) & VFIFO_SPI_INTSTATSPI_RXCOUNT_MASK)

#define VFIFO_SPI_INTSTATSPI_TXCOUNT_MASK        (0xFF000000U)
#define VFIFO_SPI_INTSTATSPI_TXCOUNT_SHIFT       (24U)
/*! TXCOUNT - Transmit FIFO Available. This is simply a copy of the same field in the STATSPI
 *    register, included here so an ISR can read all needed status information in one read.
 */
#define VFIFO_SPI_INTSTATSPI_TXCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_INTSTATSPI_TXCOUNT_SHIFT)) & VFIFO_SPI_INTSTATSPI_TXCOUNT_MASK)
/*! @} */

/* The count of VFIFO_SPI_INTSTATSPI */
#define VFIFO_SPI_INTSTATSPI_COUNT               (2U)

/*! @name SPI_CTLSETSPI - SPI0 control read and set register. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set. */
/*! @{ */

#define VFIFO_SPI_CTLSETSPI_RXTHINTEN_MASK       (0x1U)
#define VFIFO_SPI_CTLSETSPI_RXTHINTEN_SHIFT      (0U)
/*! RXTHINTEN - Receive FIFO Threshold Interrupt Enable. */
#define VFIFO_SPI_CTLSETSPI_RXTHINTEN(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLSETSPI_RXTHINTEN_SHIFT)) & VFIFO_SPI_CTLSETSPI_RXTHINTEN_MASK)

#define VFIFO_SPI_CTLSETSPI_TXTHINTEN_MASK       (0x2U)
#define VFIFO_SPI_CTLSETSPI_TXTHINTEN_SHIFT      (1U)
/*! TXTHINTEN - Transmit FIFO Threshold Interrupt Enable. */
#define VFIFO_SPI_CTLSETSPI_TXTHINTEN(x)         (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLSETSPI_TXTHINTEN_SHIFT)) & VFIFO_SPI_CTLSETSPI_TXTHINTEN_MASK)

#define VFIFO_SPI_CTLSETSPI_RXTIMEOUTINTEN_MASK  (0x10U)
#define VFIFO_SPI_CTLSETSPI_RXTIMEOUTINTEN_SHIFT (4U)
/*! RXTIMEOUTINTEN - Receive FIFO Timeout Interrupt Enable. When enabled, this also enables the
 *    timeout for this SPI. Writing a 1 to this bit resets the SPI timeout logic.
 */
#define VFIFO_SPI_CTLSETSPI_RXTIMEOUTINTEN(x)    (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLSETSPI_RXTIMEOUTINTEN_SHIFT)) & VFIFO_SPI_CTLSETSPI_RXTIMEOUTINTEN_MASK)

#define VFIFO_SPI_CTLSETSPI_RXFLUSH_MASK         (0x100U)
#define VFIFO_SPI_CTLSETSPI_RXFLUSH_SHIFT        (8U)
/*! RXFLUSH - Receive FIFO flush. Writing a 1 to this bit forces the receive FIFO to be empty. */
#define VFIFO_SPI_CTLSETSPI_RXFLUSH(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLSETSPI_RXFLUSH_SHIFT)) & VFIFO_SPI_CTLSETSPI_RXFLUSH_MASK)

#define VFIFO_SPI_CTLSETSPI_TXFLUSH_MASK         (0x200U)
#define VFIFO_SPI_CTLSETSPI_TXFLUSH_SHIFT        (9U)
/*! TXFLUSH - Transmit FIFO flush. Writing a 1 to this bit forces the transmit FIFO to be empty. */
#define VFIFO_SPI_CTLSETSPI_TXFLUSH(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLSETSPI_TXFLUSH_SHIFT)) & VFIFO_SPI_CTLSETSPI_TXFLUSH_MASK)
/*! @} */

/* The count of VFIFO_SPI_CTLSETSPI */
#define VFIFO_SPI_CTLSETSPI_COUNT                (2U)

/*! @name SPI_CTLCLRSPI - SPI0 control clear register. Writing a 1 to any implemented bit position causes the corresponding bit in the related CTLSET register to be cleared. */
/*! @{ */

#define VFIFO_SPI_CTLCLRSPI_RXTHINTCLR_MASK      (0x1U)
#define VFIFO_SPI_CTLCLRSPI_RXTHINTCLR_SHIFT     (0U)
/*! RXTHINTCLR - Receive FIFO Threshold Interrupt clear. */
#define VFIFO_SPI_CTLCLRSPI_RXTHINTCLR(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLCLRSPI_RXTHINTCLR_SHIFT)) & VFIFO_SPI_CTLCLRSPI_RXTHINTCLR_MASK)

#define VFIFO_SPI_CTLCLRSPI_TXTHINTCLR_MASK      (0x2U)
#define VFIFO_SPI_CTLCLRSPI_TXTHINTCLR_SHIFT     (1U)
/*! TXTHINTCLR - Transmit FIFO Threshold Interrupt clear. */
#define VFIFO_SPI_CTLCLRSPI_TXTHINTCLR(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLCLRSPI_TXTHINTCLR_SHIFT)) & VFIFO_SPI_CTLCLRSPI_TXTHINTCLR_MASK)

#define VFIFO_SPI_CTLCLRSPI_RXTIMEOUTINTCLR_MASK (0x10U)
#define VFIFO_SPI_CTLCLRSPI_RXTIMEOUTINTCLR_SHIFT (4U)
/*! RXTIMEOUTINTCLR - Receive FIFO Timeout Interrupt clear. */
#define VFIFO_SPI_CTLCLRSPI_RXTIMEOUTINTCLR(x)   (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLCLRSPI_RXTIMEOUTINTCLR_SHIFT)) & VFIFO_SPI_CTLCLRSPI_RXTIMEOUTINTCLR_MASK)

#define VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR_MASK      (0x100U)
#define VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR_SHIFT     (8U)
/*! RXFLUSHCLR - Receive FIFO flush clear. do the clear bits 8 and 9 do anything? */
#define VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR_SHIFT)) & VFIFO_SPI_CTLCLRSPI_RXFLUSHCLR_MASK)

#define VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR_MASK      (0x200U)
#define VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR_SHIFT     (9U)
/*! TXFLUSHCLR - Transmit FIFO flush clear. */
#define VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR(x)        (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR_SHIFT)) & VFIFO_SPI_CTLCLRSPI_TXFLUSHCLR_MASK)
/*! @} */

/* The count of VFIFO_SPI_CTLCLRSPI */
#define VFIFO_SPI_CTLCLRSPI_COUNT                (2U)

/*! @name SPI_RXDATSPI - SPI0 received data. These registers are half word addressable. */
/*! @{ */

#define VFIFO_SPI_RXDATSPI_RXDAT_MASK            (0xFFFFU)
#define VFIFO_SPI_RXDATSPI_RXDAT_SHIFT           (0U)
/*! RXDAT - Receiver Data. This contains the next piece of received data. The number of bits that
 *    are used depends on the LEN setting in TXCTL / TXDATCTL.
 */
#define VFIFO_SPI_RXDATSPI_RXDAT(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_RXDAT_SHIFT)) & VFIFO_SPI_RXDATSPI_RXDAT_MASK)

#define VFIFO_SPI_RXDATSPI_RXSSEL0_N_MASK        (0x10000U)
#define VFIFO_SPI_RXDATSPI_RXSSEL0_N_SHIFT       (16U)
/*! RXSSEL0_N - Slave Select for receive. This field allows the state of the SSEL0 pin to be saved
 *    along with received data. The value will reflect the SSEL0 pin for both master and slave
 *    operation. A zero indicates that a slave select is active. The actual polarity of each slave select
 *    pin is configured by the related SPOL bit in CFG.
 */
#define VFIFO_SPI_RXDATSPI_RXSSEL0_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_RXSSEL0_N_SHIFT)) & VFIFO_SPI_RXDATSPI_RXSSEL0_N_MASK)

#define VFIFO_SPI_RXDATSPI_RXSSEL1_N_MASK        (0x20000U)
#define VFIFO_SPI_RXDATSPI_RXSSEL1_N_SHIFT       (17U)
/*! RXSSEL1_N - Slave Select for receive. This field allows the state of the SSEL1 pin to be saved
 *    along with received data. The value will reflect the SSEL1 pin for both master and slave
 *    operation. A zero indicates that a slave select is active. The actual polarity of each slave select
 *    pin is configured by the related SPOL bit in CFG.
 */
#define VFIFO_SPI_RXDATSPI_RXSSEL1_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_RXSSEL1_N_SHIFT)) & VFIFO_SPI_RXDATSPI_RXSSEL1_N_MASK)

#define VFIFO_SPI_RXDATSPI_RXSSEL2_N_MASK        (0x40000U)
#define VFIFO_SPI_RXDATSPI_RXSSEL2_N_SHIFT       (18U)
/*! RXSSEL2_N - Slave Select for receive. This field allows the state of the SSEL2 pin to be saved
 *    along with received data. The value will reflect the SSEL2 pin for both master and slave
 *    operation. A zero indicates that a slave select is active. The actual polarity of each slave select
 *    pin is configured by the related SPOL bit in CFG.
 */
#define VFIFO_SPI_RXDATSPI_RXSSEL2_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_RXSSEL2_N_SHIFT)) & VFIFO_SPI_RXDATSPI_RXSSEL2_N_MASK)

#define VFIFO_SPI_RXDATSPI_RXSSEL3_N_MASK        (0x80000U)
#define VFIFO_SPI_RXDATSPI_RXSSEL3_N_SHIFT       (19U)
/*! RXSSEL3_N - Slave Select for receive. This field allows the state of the SSEL3 pin to be saved
 *    along with received data. The value will reflect the SSEL3 pin for both master and slave
 *    operation. A zero indicates that a slave select is active. The actual polarity of each slave select
 *    pin is configured by the related SPOL bit in CFG.
 */
#define VFIFO_SPI_RXDATSPI_RXSSEL3_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_RXSSEL3_N_SHIFT)) & VFIFO_SPI_RXDATSPI_RXSSEL3_N_MASK)

#define VFIFO_SPI_RXDATSPI_SOT_MASK              (0x100000U)
#define VFIFO_SPI_RXDATSPI_SOT_SHIFT             (20U)
/*! SOT - Start of Transfer flag. This flag will be 1 if this is the first data after the SSELs went
 *    from deasserted to asserted (i.e., any previous transfer has ended). This information can be
 *    used to identify the first piece of data in cases where the transfer length is greater than 16
 *    bit.
 */
#define VFIFO_SPI_RXDATSPI_SOT(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_RXDATSPI_SOT_SHIFT)) & VFIFO_SPI_RXDATSPI_SOT_MASK)
/*! @} */

/* The count of VFIFO_SPI_RXDATSPI */
#define VFIFO_SPI_RXDATSPI_COUNT                 (2U)

/*! @name SPI_TXDATSPI - SPI0 transmit data. These registers are half word addressable. */
/*! @{ */

#define VFIFO_SPI_TXDATSPI_TXDAT_MASK            (0xFFFFU)
#define VFIFO_SPI_TXDATSPI_TXDAT_SHIFT           (0U)
/*! TXDAT - Transmit Data. This field provides from 1 to 16 bits of data to be transmitted. */
#define VFIFO_SPI_TXDATSPI_TXDAT(x)              (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_TXDAT_SHIFT)) & VFIFO_SPI_TXDATSPI_TXDAT_MASK)

#define VFIFO_SPI_TXDATSPI_TXSSEL0_N_MASK        (0x10000U)
#define VFIFO_SPI_TXDATSPI_TXSSEL0_N_SHIFT       (16U)
/*! TXSSEL0_N - Transmit Slave Select. This field asserts SSEL0 in master mode. The output on the
 *    pin is active LOW by default. The active state of the SSEL0 pin is configured by bits in the CFG
 *    register.
 *  0b0..Asserted. SSEL0 asserted.
 *  0b1..Not asserted. SSEL0 not asserted.
 */
#define VFIFO_SPI_TXDATSPI_TXSSEL0_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_TXSSEL0_N_SHIFT)) & VFIFO_SPI_TXDATSPI_TXSSEL0_N_MASK)

#define VFIFO_SPI_TXDATSPI_TXSSEL1_N_MASK        (0x20000U)
#define VFIFO_SPI_TXDATSPI_TXSSEL1_N_SHIFT       (17U)
/*! TXSSEL1_N - Transmit Slave Select. This field asserts SSEL1 in master mode. The output on the
 *    pin is active LOW by default. The active state of the SSEL1 pin is configured by bits in the CFG
 *    register.
 *  0b0..Asserted. SSEL1 asserted.
 *  0b1..Not asserted. SSEL1 not asserted.
 */
#define VFIFO_SPI_TXDATSPI_TXSSEL1_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_TXSSEL1_N_SHIFT)) & VFIFO_SPI_TXDATSPI_TXSSEL1_N_MASK)

#define VFIFO_SPI_TXDATSPI_TXSSEL2_N_MASK        (0x40000U)
#define VFIFO_SPI_TXDATSPI_TXSSEL2_N_SHIFT       (18U)
/*! TXSSEL2_N - Transmit Slave Select. This field asserts SSEL2 in master mode. The output on the
 *    pin is active LOW by default. The active state of the SSEL2 pin is configured by bits in the CFG
 *    register.
 *  0b0..Asserted. SSEL2 asserted.
 *  0b1..Not asserted. SSEL2 not asserted.
 */
#define VFIFO_SPI_TXDATSPI_TXSSEL2_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_TXSSEL2_N_SHIFT)) & VFIFO_SPI_TXDATSPI_TXSSEL2_N_MASK)

#define VFIFO_SPI_TXDATSPI_TXSSEL3_N_MASK        (0x80000U)
#define VFIFO_SPI_TXDATSPI_TXSSEL3_N_SHIFT       (19U)
/*! TXSSEL3_N - Transmit Slave Select. This field asserts SSEL3 in master mode. The output on the
 *    pin is active LOW by default. The active state of the SSEL3 pin is configured by bits in the CFG
 *    register.
 *  0b0..Asserted. SSEL3 asserted.
 *  0b1..Not asserted. SSEL3 not asserted.
 */
#define VFIFO_SPI_TXDATSPI_TXSSEL3_N(x)          (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_TXSSEL3_N_SHIFT)) & VFIFO_SPI_TXDATSPI_TXSSEL3_N_MASK)

#define VFIFO_SPI_TXDATSPI_EOT_MASK              (0x100000U)
#define VFIFO_SPI_TXDATSPI_EOT_SHIFT             (20U)
/*! EOT - End of Transfer. The asserted SSEL will be deasserted at the end of a transfer, and remain
 *    so for at least the time specified by the Transfer_delay value in the DLY register.
 *  0b0..Not deasserted. SSEL not deasserted. This piece of data is not treated as the end of a transfer. SSEL
 *       will not be deasserted at the end of this data.
 *  0b1..Deasserted. SSEL deasserted. This piece of data is treated as the end of a transfer. SSEL will be
 *       deasserted at the end of this piece of data.
 */
#define VFIFO_SPI_TXDATSPI_EOT(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_EOT_SHIFT)) & VFIFO_SPI_TXDATSPI_EOT_MASK)

#define VFIFO_SPI_TXDATSPI_EOF_MASK              (0x200000U)
#define VFIFO_SPI_TXDATSPI_EOF_SHIFT             (21U)
/*! EOF - End of Frame. Between frames, a delay may be inserted, as defined by the FRAME_DELAY value
 *    in the DLY register. The end of a frame may not be particularly meaningful if the FRAME_DELAY
 *    value = 0. This control can be used as part of the support for frame lengths greater than 16
 *    bits.
 *  0b0..Data not EOF. This piece of data transmitted is not treated as the end of a frame.
 *  0b1..Data EOF. This piece of data is treated as the end of a frame, causing the FRAME_DELAY time to be
 *       inserted before subsequent data is transmitted.
 */
#define VFIFO_SPI_TXDATSPI_EOF(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_EOF_SHIFT)) & VFIFO_SPI_TXDATSPI_EOF_MASK)

#define VFIFO_SPI_TXDATSPI_RXIGNORE_MASK         (0x400000U)
#define VFIFO_SPI_TXDATSPI_RXIGNORE_SHIFT        (22U)
/*! RXIGNORE - Receive Ignore. This allows data to be transmitted using the SPI without the need to
 *    read unneeded data from the receiver to simplify the transmit process and can be used with the
 *    DMA.
 *  0b0..Read received data. Received data must be read in order to allow transmission to progress. In slave mode,
 *       an overrun error will occur if received data is not read before new data is received.
 *  0b1..Ignore received data. Received data is ignored, allowing transmission without reading unneeded received
 *       data. No receiver flags are generated.
 */
#define VFIFO_SPI_TXDATSPI_RXIGNORE(x)           (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_RXIGNORE_SHIFT)) & VFIFO_SPI_TXDATSPI_RXIGNORE_MASK)

#define VFIFO_SPI_TXDATSPI_LEN_MASK              (0xF000000U)
#define VFIFO_SPI_TXDATSPI_LEN_SHIFT             (24U)
/*! LEN - Data Length. Specifies the data length from 1 to 16 bits. Note that transfer lengths
 *    greater than 16 bits are supported by implementing multiple sequential data transmits. 0x0 = Data
 *    transfer is 1 bit in length. 0x1 = Data transfer is 2 bits in length. 0x2 = Data transfer is 3
 *    bits in length. ... 0xF = Data transfer is 16 bits in length.
 */
#define VFIFO_SPI_TXDATSPI_LEN(x)                (((uint32_t)(((uint32_t)(x)) << VFIFO_SPI_TXDATSPI_LEN_SHIFT)) & VFIFO_SPI_TXDATSPI_LEN_MASK)
/*! @} */

/* The count of VFIFO_SPI_TXDATSPI */
#define VFIFO_SPI_TXDATSPI_COUNT                 (2U)


/*!
 * @}
 */ /* end of group VFIFO_Register_Masks */


/*!
 * @}
 */ /* end of group VFIFO_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* VFIFO_H_ */

