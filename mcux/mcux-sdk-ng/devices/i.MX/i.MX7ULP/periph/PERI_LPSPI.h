/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 7.0, 2018-11-05
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LPSPI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**
** ###################################################################
*/

/*!
 * @file LPSPI.h
 * @version 7.0
 * @date 2018-11-05
 * @brief CMSIS Peripheral Access Layer for LPSPI
 *
 * CMSIS Peripheral Access Layer for LPSPI
 */

#if !defined(LPSPI_H_)
#define LPSPI_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */

/** LPSPI - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t CR;                                /**< Control Register, offset: 0x10 */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x14 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t DER;                               /**< DMA Enable Register, offset: 0x1C */
  __IO uint32_t CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  __IO uint32_t CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       uint8_t RESERVED_1[8];
  __IO uint32_t DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  __IO uint32_t DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       uint8_t RESERVED_3[20];
  __IO uint32_t FCR;                               /**< FIFO Control Register, offset: 0x58 */
  __I  uint32_t FSR;                               /**< FIFO Status Register, offset: 0x5C */
  __IO uint32_t TCR;                               /**< Transmit Command Register, offset: 0x60 */
  __O  uint32_t TDR;                               /**< Transmit Data Register, offset: 0x64 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RSR;                               /**< Receive Status Register, offset: 0x70 */
  __I  uint32_t RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type;

/* ----------------------------------------------------------------------------
   -- LPSPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Register_Masks LPSPI Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define LPSPI_VERID_FEATURE_MASK                 (0xFFFFU)
#define LPSPI_VERID_FEATURE_SHIFT                (0U)
/*! FEATURE - Module Identification Number
 *  0b0000000000000100..Standard feature set supporting a 32-bit shift register.
 */
#define LPSPI_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_FEATURE_SHIFT)) & LPSPI_VERID_FEATURE_MASK)

#define LPSPI_VERID_MINOR_MASK                   (0xFF0000U)
#define LPSPI_VERID_MINOR_SHIFT                  (16U)
/*! MINOR - Minor Version Number */
#define LPSPI_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_MINOR_SHIFT)) & LPSPI_VERID_MINOR_MASK)

#define LPSPI_VERID_MAJOR_MASK                   (0xFF000000U)
#define LPSPI_VERID_MAJOR_SHIFT                  (24U)
/*! MAJOR - Major Version Number */
#define LPSPI_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_VERID_MAJOR_SHIFT)) & LPSPI_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LPSPI_PARAM_TXFIFO_MASK                  (0xFFU)
#define LPSPI_PARAM_TXFIFO_SHIFT                 (0U)
/*! TXFIFO - Transmit FIFO Size */
#define LPSPI_PARAM_TXFIFO(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_PARAM_TXFIFO_SHIFT)) & LPSPI_PARAM_TXFIFO_MASK)

#define LPSPI_PARAM_RXFIFO_MASK                  (0xFF00U)
#define LPSPI_PARAM_RXFIFO_SHIFT                 (8U)
/*! RXFIFO - Receive FIFO Size */
#define LPSPI_PARAM_RXFIFO(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_PARAM_RXFIFO_SHIFT)) & LPSPI_PARAM_RXFIFO_MASK)
/*! @} */

/*! @name CR - Control Register */
/*! @{ */

#define LPSPI_CR_MEN_MASK                        (0x1U)
#define LPSPI_CR_MEN_SHIFT                       (0U)
/*! MEN - Module Enable
 *  0b0..Module is disabled
 *  0b1..Module is enabled
 */
#define LPSPI_CR_MEN(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_MEN_SHIFT)) & LPSPI_CR_MEN_MASK)

#define LPSPI_CR_RST_MASK                        (0x2U)
#define LPSPI_CR_RST_SHIFT                       (1U)
/*! RST - Software Reset
 *  0b0..Module is not reset
 *  0b1..Module is reset
 */
#define LPSPI_CR_RST(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RST_SHIFT)) & LPSPI_CR_RST_MASK)

#define LPSPI_CR_DOZEN_MASK                      (0x4U)
#define LPSPI_CR_DOZEN_SHIFT                     (2U)
/*! DOZEN - Doze Mode Enable
 *  0b0..LPSPI module is enabled in Doze mode
 *  0b1..LPSPI module is disabled in Doze mode
 */
#define LPSPI_CR_DOZEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_DOZEN_SHIFT)) & LPSPI_CR_DOZEN_MASK)

#define LPSPI_CR_DBGEN_MASK                      (0x8U)
#define LPSPI_CR_DBGEN_SHIFT                     (3U)
/*! DBGEN - Debug Enable
 *  0b0..LPSPI module is disabled in debug mode
 *  0b1..LPSPI module is enabled in debug mode
 */
#define LPSPI_CR_DBGEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_DBGEN_SHIFT)) & LPSPI_CR_DBGEN_MASK)

#define LPSPI_CR_RTF_MASK                        (0x100U)
#define LPSPI_CR_RTF_SHIFT                       (8U)
/*! RTF - Reset Transmit FIFO
 *  0b0..No effect
 *  0b1..Transmit FIFO is reset
 */
#define LPSPI_CR_RTF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RTF_SHIFT)) & LPSPI_CR_RTF_MASK)

#define LPSPI_CR_RRF_MASK                        (0x200U)
#define LPSPI_CR_RRF_SHIFT                       (9U)
/*! RRF - Reset Receive FIFO
 *  0b0..No effect
 *  0b1..Receive FIFO is reset
 */
#define LPSPI_CR_RRF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_CR_RRF_SHIFT)) & LPSPI_CR_RRF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define LPSPI_SR_TDF_MASK                        (0x1U)
#define LPSPI_SR_TDF_SHIFT                       (0U)
/*! TDF - Transmit Data Flag
 *  0b0..Transmit data not requested
 *  0b1..Transmit data is requested
 */
#define LPSPI_SR_TDF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TDF_SHIFT)) & LPSPI_SR_TDF_MASK)

#define LPSPI_SR_RDF_MASK                        (0x2U)
#define LPSPI_SR_RDF_SHIFT                       (1U)
/*! RDF - Receive Data Flag
 *  0b0..Receive Data is not ready
 *  0b1..Receive data is ready
 */
#define LPSPI_SR_RDF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_RDF_SHIFT)) & LPSPI_SR_RDF_MASK)

#define LPSPI_SR_WCF_MASK                        (0x100U)
#define LPSPI_SR_WCF_SHIFT                       (8U)
/*! WCF - Word Complete Flag
 *  0b0..Transfer of a received word has not yet completed
 *  0b1..Transfer of a received word has completed
 */
#define LPSPI_SR_WCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_WCF_SHIFT)) & LPSPI_SR_WCF_MASK)

#define LPSPI_SR_FCF_MASK                        (0x200U)
#define LPSPI_SR_FCF_SHIFT                       (9U)
/*! FCF - Frame Complete Flag
 *  0b0..Frame transfer has not completed
 *  0b1..Frame transfer has completed
 */
#define LPSPI_SR_FCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_FCF_SHIFT)) & LPSPI_SR_FCF_MASK)

#define LPSPI_SR_TCF_MASK                        (0x400U)
#define LPSPI_SR_TCF_SHIFT                       (10U)
/*! TCF - Transfer Complete Flag
 *  0b0..All transfers have not completed
 *  0b1..All transfers have completed
 */
#define LPSPI_SR_TCF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TCF_SHIFT)) & LPSPI_SR_TCF_MASK)

#define LPSPI_SR_TEF_MASK                        (0x800U)
#define LPSPI_SR_TEF_SHIFT                       (11U)
/*! TEF - Transmit Error Flag
 *  0b0..Transmit FIFO underrun has not occurred
 *  0b1..Transmit FIFO underrun has occurred
 */
#define LPSPI_SR_TEF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_TEF_SHIFT)) & LPSPI_SR_TEF_MASK)

#define LPSPI_SR_REF_MASK                        (0x1000U)
#define LPSPI_SR_REF_SHIFT                       (12U)
/*! REF - Receive Error Flag
 *  0b0..Receive FIFO has not overflowed
 *  0b1..Receive FIFO has overflowed
 */
#define LPSPI_SR_REF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_REF_SHIFT)) & LPSPI_SR_REF_MASK)

#define LPSPI_SR_DMF_MASK                        (0x2000U)
#define LPSPI_SR_DMF_SHIFT                       (13U)
/*! DMF - Data Match Flag
 *  0b0..Have not received matching data
 *  0b1..Have received matching data
 */
#define LPSPI_SR_DMF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_DMF_SHIFT)) & LPSPI_SR_DMF_MASK)

#define LPSPI_SR_MBF_MASK                        (0x1000000U)
#define LPSPI_SR_MBF_SHIFT                       (24U)
/*! MBF - Module Busy Flag
 *  0b0..LPSPI is idle
 *  0b1..LPSPI is busy
 */
#define LPSPI_SR_MBF(x)                          (((uint32_t)(((uint32_t)(x)) << LPSPI_SR_MBF_SHIFT)) & LPSPI_SR_MBF_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define LPSPI_IER_TDIE_MASK                      (0x1U)
#define LPSPI_IER_TDIE_SHIFT                     (0U)
/*! TDIE - Transmit Data Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TDIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TDIE_SHIFT)) & LPSPI_IER_TDIE_MASK)

#define LPSPI_IER_RDIE_MASK                      (0x2U)
#define LPSPI_IER_RDIE_SHIFT                     (1U)
/*! RDIE - Receive Data Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_RDIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_RDIE_SHIFT)) & LPSPI_IER_RDIE_MASK)

#define LPSPI_IER_WCIE_MASK                      (0x100U)
#define LPSPI_IER_WCIE_SHIFT                     (8U)
/*! WCIE - Word Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_WCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_WCIE_SHIFT)) & LPSPI_IER_WCIE_MASK)

#define LPSPI_IER_FCIE_MASK                      (0x200U)
#define LPSPI_IER_FCIE_SHIFT                     (9U)
/*! FCIE - Frame Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_FCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_FCIE_SHIFT)) & LPSPI_IER_FCIE_MASK)

#define LPSPI_IER_TCIE_MASK                      (0x400U)
#define LPSPI_IER_TCIE_SHIFT                     (10U)
/*! TCIE - Transfer Complete Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TCIE_SHIFT)) & LPSPI_IER_TCIE_MASK)

#define LPSPI_IER_TEIE_MASK                      (0x800U)
#define LPSPI_IER_TEIE_SHIFT                     (11U)
/*! TEIE - Transmit Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_TEIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_TEIE_SHIFT)) & LPSPI_IER_TEIE_MASK)

#define LPSPI_IER_REIE_MASK                      (0x1000U)
#define LPSPI_IER_REIE_SHIFT                     (12U)
/*! REIE - Receive Error Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_REIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_REIE_SHIFT)) & LPSPI_IER_REIE_MASK)

#define LPSPI_IER_DMIE_MASK                      (0x2000U)
#define LPSPI_IER_DMIE_SHIFT                     (13U)
/*! DMIE - Data Match Interrupt Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LPSPI_IER_DMIE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_IER_DMIE_SHIFT)) & LPSPI_IER_DMIE_MASK)
/*! @} */

/*! @name DER - DMA Enable Register */
/*! @{ */

#define LPSPI_DER_TDDE_MASK                      (0x1U)
#define LPSPI_DER_TDDE_SHIFT                     (0U)
/*! TDDE - Transmit Data DMA Enable
 *  0b0..DMA request is disabled
 *  0b1..DMA request is enabled
 */
#define LPSPI_DER_TDDE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_DER_TDDE_SHIFT)) & LPSPI_DER_TDDE_MASK)

#define LPSPI_DER_RDDE_MASK                      (0x2U)
#define LPSPI_DER_RDDE_SHIFT                     (1U)
/*! RDDE - Receive Data DMA Enable
 *  0b0..DMA request is disabled
 *  0b1..DMA request is enabled
 */
#define LPSPI_DER_RDDE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_DER_RDDE_SHIFT)) & LPSPI_DER_RDDE_MASK)

#define LPSPI_DER_FCDE_MASK                      (0x200U)
#define LPSPI_DER_FCDE_SHIFT                     (9U)
/*! FCDE - Frame Complete DMA Enable
 *  0b0..DMA request is disabled
 *  0b1..DMA request is enabled
 */
#define LPSPI_DER_FCDE(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_DER_FCDE_SHIFT)) & LPSPI_DER_FCDE_MASK)
/*! @} */

/*! @name CFGR0 - Configuration Register 0 */
/*! @{ */

#define LPSPI_CFGR0_HREN_MASK                    (0x1U)
#define LPSPI_CFGR0_HREN_SHIFT                   (0U)
/*! HREN - Host Request Enable
 *  0b0..Host request is disabled
 *  0b1..Host request is enabled
 */
#define LPSPI_CFGR0_HREN(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HREN_SHIFT)) & LPSPI_CFGR0_HREN_MASK)

#define LPSPI_CFGR0_HRPOL_MASK                   (0x2U)
#define LPSPI_CFGR0_HRPOL_SHIFT                  (1U)
/*! HRPOL - Host Request Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define LPSPI_CFGR0_HRPOL(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HRPOL_SHIFT)) & LPSPI_CFGR0_HRPOL_MASK)

#define LPSPI_CFGR0_HRSEL_MASK                   (0x4U)
#define LPSPI_CFGR0_HRSEL_SHIFT                  (2U)
/*! HRSEL - Host Request Select
 *  0b0..Host request input is the LPSPI_HREQ pin
 *  0b1..Host request input is the input trigger
 */
#define LPSPI_CFGR0_HRSEL(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_HRSEL_SHIFT)) & LPSPI_CFGR0_HRSEL_MASK)

#define LPSPI_CFGR0_CIRFIFO_MASK                 (0x100U)
#define LPSPI_CFGR0_CIRFIFO_SHIFT                (8U)
/*! CIRFIFO - Circular FIFO Enable
 *  0b0..Circular FIFO is disabled
 *  0b1..Circular FIFO is enabled
 */
#define LPSPI_CFGR0_CIRFIFO(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_CIRFIFO_SHIFT)) & LPSPI_CFGR0_CIRFIFO_MASK)

#define LPSPI_CFGR0_RDMO_MASK                    (0x200U)
#define LPSPI_CFGR0_RDMO_SHIFT                   (9U)
/*! RDMO - Receive Data Match Only
 *  0b0..Received data is stored in the receive FIFO as in normal operations
 *  0b1..Received data is discarded unless the Data Match Flag (DMF) is set
 */
#define LPSPI_CFGR0_RDMO(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR0_RDMO_SHIFT)) & LPSPI_CFGR0_RDMO_MASK)
/*! @} */

/*! @name CFGR1 - Configuration Register 1 */
/*! @{ */

#define LPSPI_CFGR1_MASTER_MASK                  (0x1U)
#define LPSPI_CFGR1_MASTER_SHIFT                 (0U)
/*! MASTER - Master Mode
 *  0b0..Slave mode
 *  0b1..Master mode
 */
#define LPSPI_CFGR1_MASTER(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_MASTER_SHIFT)) & LPSPI_CFGR1_MASTER_MASK)

#define LPSPI_CFGR1_SAMPLE_MASK                  (0x2U)
#define LPSPI_CFGR1_SAMPLE_SHIFT                 (1U)
/*! SAMPLE - Sample Point
 *  0b0..Input data is sampled on SCK edge
 *  0b1..Input data is sampled on delayed SCK edge
 */
#define LPSPI_CFGR1_SAMPLE(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_SAMPLE_SHIFT)) & LPSPI_CFGR1_SAMPLE_MASK)

#define LPSPI_CFGR1_AUTOPCS_MASK                 (0x4U)
#define LPSPI_CFGR1_AUTOPCS_SHIFT                (2U)
/*! AUTOPCS - Automatic PCS
 *  0b0..Automatic PCS generation is disabled
 *  0b1..Automatic PCS generation is enabled
 */
#define LPSPI_CFGR1_AUTOPCS(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_AUTOPCS_SHIFT)) & LPSPI_CFGR1_AUTOPCS_MASK)

#define LPSPI_CFGR1_NOSTALL_MASK                 (0x8U)
#define LPSPI_CFGR1_NOSTALL_SHIFT                (3U)
/*! NOSTALL - No Stall
 *  0b0..Transfers will stall when the transmit FIFO is empty or the receive FIFO is full
 *  0b1..Transfers will not stall, allowing transmit FIFO underruns or receive FIFO overruns to occur
 */
#define LPSPI_CFGR1_NOSTALL(x)                   (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_NOSTALL_SHIFT)) & LPSPI_CFGR1_NOSTALL_MASK)

#define LPSPI_CFGR1_PCSPOL_MASK                  (0xF00U)
#define LPSPI_CFGR1_PCSPOL_SHIFT                 (8U)
/*! PCSPOL - Peripheral Chip Select Polarity */
#define LPSPI_CFGR1_PCSPOL(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PCSPOL_SHIFT)) & LPSPI_CFGR1_PCSPOL_MASK)

#define LPSPI_CFGR1_MATCFG_MASK                  (0x70000U)
#define LPSPI_CFGR1_MATCFG_SHIFT                 (16U)
/*! MATCFG - Match Configuration
 *  0b000..Match is disabled
 *  0b001..Reserved
 *  0b010..010b - Match is enabled, if 1st data word equals MATCH0 OR MATCH1, i.e., (1st data word = MATCH0 + MATCH1)
 *  0b011..011b - Match is enabled, if any data word equals MATCH0 OR MATCH1, i.e., (any data word = MATCH0 + MATCH1)
 *  0b100..100b - Match is enabled, if 1st data word equals MATCH0 AND 2nd data word equals MATCH1, i.e., [(1st
 *         data word = MATCH0) * (2nd data word = MATCH1)]
 *  0b101..101b - Match is enabled, if any data word equals MATCH0 AND the next data word equals MATCH1, i.e.,
 *         [(any data word = MATCH0) * (next data word = MATCH1)]
 *  0b110..110b - Match is enabled, if (1st data word AND MATCH1) equals (MATCH0 AND MATCH1), i.e., [(1st data word * MATCH1) = (MATCH0 * MATCH1)]
 *  0b111..111b - Match is enabled, if (any data word AND MATCH1) equals (MATCH0 AND MATCH1), i.e., [(any data word * MATCH1) = (MATCH0 * MATCH1)]
 */
#define LPSPI_CFGR1_MATCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_MATCFG_SHIFT)) & LPSPI_CFGR1_MATCFG_MASK)

#define LPSPI_CFGR1_PINCFG_MASK                  (0x3000000U)
#define LPSPI_CFGR1_PINCFG_SHIFT                 (24U)
/*! PINCFG - Pin Configuration
 *  0b00..SIN is used for input data and SOUT is used for output data
 *  0b01..SIN is used for both input and output data
 *  0b10..SOUT is used for both input and output data
 *  0b11..SOUT is used for input data and SIN is used for output data
 */
#define LPSPI_CFGR1_PINCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PINCFG_SHIFT)) & LPSPI_CFGR1_PINCFG_MASK)

#define LPSPI_CFGR1_OUTCFG_MASK                  (0x4000000U)
#define LPSPI_CFGR1_OUTCFG_SHIFT                 (26U)
/*! OUTCFG - Output Configuration
 *  0b0..Output data retains last value when chip select is negated
 *  0b1..Output data is tristated when chip select is negated
 */
#define LPSPI_CFGR1_OUTCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_OUTCFG_SHIFT)) & LPSPI_CFGR1_OUTCFG_MASK)

#define LPSPI_CFGR1_PCSCFG_MASK                  (0x8000000U)
#define LPSPI_CFGR1_PCSCFG_SHIFT                 (27U)
/*! PCSCFG - Peripheral Chip Select Configuration
 *  0b0..PCS[3:2] are enabled
 *  0b1..PCS[3:2] are disabled
 */
#define LPSPI_CFGR1_PCSCFG(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_CFGR1_PCSCFG_SHIFT)) & LPSPI_CFGR1_PCSCFG_MASK)
/*! @} */

/*! @name DMR0 - Data Match Register 0 */
/*! @{ */

#define LPSPI_DMR0_MATCH0_MASK                   (0xFFFFFFFFU)
#define LPSPI_DMR0_MATCH0_SHIFT                  (0U)
/*! MATCH0 - Match 0 Value */
#define LPSPI_DMR0_MATCH0(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_DMR0_MATCH0_SHIFT)) & LPSPI_DMR0_MATCH0_MASK)
/*! @} */

/*! @name DMR1 - Data Match Register 1 */
/*! @{ */

#define LPSPI_DMR1_MATCH1_MASK                   (0xFFFFFFFFU)
#define LPSPI_DMR1_MATCH1_SHIFT                  (0U)
/*! MATCH1 - Match 1 Value */
#define LPSPI_DMR1_MATCH1(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_DMR1_MATCH1_SHIFT)) & LPSPI_DMR1_MATCH1_MASK)
/*! @} */

/*! @name CCR - Clock Configuration Register */
/*! @{ */

#define LPSPI_CCR_SCKDIV_MASK                    (0xFFU)
#define LPSPI_CCR_SCKDIV_SHIFT                   (0U)
/*! SCKDIV - SCK Divider */
#define LPSPI_CCR_SCKDIV(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_SCKDIV_SHIFT)) & LPSPI_CCR_SCKDIV_MASK)

#define LPSPI_CCR_DBT_MASK                       (0xFF00U)
#define LPSPI_CCR_DBT_SHIFT                      (8U)
/*! DBT - Delay Between Transfers */
#define LPSPI_CCR_DBT(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_DBT_SHIFT)) & LPSPI_CCR_DBT_MASK)

#define LPSPI_CCR_PCSSCK_MASK                    (0xFF0000U)
#define LPSPI_CCR_PCSSCK_SHIFT                   (16U)
/*! PCSSCK - PCS-to-SCK Delay */
#define LPSPI_CCR_PCSSCK(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_PCSSCK_SHIFT)) & LPSPI_CCR_PCSSCK_MASK)

#define LPSPI_CCR_SCKPCS_MASK                    (0xFF000000U)
#define LPSPI_CCR_SCKPCS_SHIFT                   (24U)
/*! SCKPCS - SCK-to-PCS Delay */
#define LPSPI_CCR_SCKPCS(x)                      (((uint32_t)(((uint32_t)(x)) << LPSPI_CCR_SCKPCS_SHIFT)) & LPSPI_CCR_SCKPCS_MASK)
/*! @} */

/*! @name FCR - FIFO Control Register */
/*! @{ */

#define LPSPI_FCR_TXWATER_MASK                   (0xFU)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define LPSPI_FCR_TXWATER_SHIFT                  (0U)
/*! TXWATER - Transmit FIFO Watermark */
#define LPSPI_FCR_TXWATER(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FCR_TXWATER_SHIFT)) & LPSPI_FCR_TXWATER_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */

#define LPSPI_FCR_RXWATER_MASK                   (0xF0000U)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
#define LPSPI_FCR_RXWATER_SHIFT                  (16U)
/*! RXWATER - Receive FIFO Watermark */
#define LPSPI_FCR_RXWATER(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FCR_RXWATER_SHIFT)) & LPSPI_FCR_RXWATER_MASK)  /* Merged from fields with different position or width, of widths (2, 4), largest definition used */
/*! @} */

/*! @name FSR - FIFO Status Register */
/*! @{ */

#define LPSPI_FSR_TXCOUNT_MASK                   (0x1FU)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define LPSPI_FSR_TXCOUNT_SHIFT                  (0U)
/*! TXCOUNT - Transmit FIFO Count */
#define LPSPI_FSR_TXCOUNT(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FSR_TXCOUNT_SHIFT)) & LPSPI_FSR_TXCOUNT_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */

#define LPSPI_FSR_RXCOUNT_MASK                   (0x1F0000U)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define LPSPI_FSR_RXCOUNT_SHIFT                  (16U)
/*! RXCOUNT - Receive FIFO Count */
#define LPSPI_FSR_RXCOUNT(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_FSR_RXCOUNT_SHIFT)) & LPSPI_FSR_RXCOUNT_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
/*! @} */

/*! @name TCR - Transmit Command Register */
/*! @{ */

#define LPSPI_TCR_FRAMESZ_MASK                   (0xFFFU)
#define LPSPI_TCR_FRAMESZ_SHIFT                  (0U)
/*! FRAMESZ - Frame Size */
#define LPSPI_TCR_FRAMESZ(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_FRAMESZ_SHIFT)) & LPSPI_TCR_FRAMESZ_MASK)

#define LPSPI_TCR_WIDTH_MASK                     (0x30000U)
#define LPSPI_TCR_WIDTH_SHIFT                    (16U)
/*! WIDTH - Transfer Width
 *  0b00..1 bit transfer
 *  0b01..2 bit transfer
 *  0b10..4 bit transfer
 *  0b11..Reserved
 */
#define LPSPI_TCR_WIDTH(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_WIDTH_SHIFT)) & LPSPI_TCR_WIDTH_MASK)

#define LPSPI_TCR_TXMSK_MASK                     (0x40000U)
#define LPSPI_TCR_TXMSK_SHIFT                    (18U)
/*! TXMSK - Transmit Data Mask
 *  0b0..Normal transfer
 *  0b1..Mask transmit data
 */
#define LPSPI_TCR_TXMSK(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_TXMSK_SHIFT)) & LPSPI_TCR_TXMSK_MASK)

#define LPSPI_TCR_RXMSK_MASK                     (0x80000U)
#define LPSPI_TCR_RXMSK_SHIFT                    (19U)
/*! RXMSK - Receive Data Mask
 *  0b0..Normal transfer
 *  0b1..Receive data is masked
 */
#define LPSPI_TCR_RXMSK(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_RXMSK_SHIFT)) & LPSPI_TCR_RXMSK_MASK)

#define LPSPI_TCR_CONTC_MASK                     (0x100000U)
#define LPSPI_TCR_CONTC_SHIFT                    (20U)
/*! CONTC - Continuing Command
 *  0b0..Command word for start of new transfer
 *  0b1..Command word for continuing transfer
 */
#define LPSPI_TCR_CONTC(x)                       (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CONTC_SHIFT)) & LPSPI_TCR_CONTC_MASK)

#define LPSPI_TCR_CONT_MASK                      (0x200000U)
#define LPSPI_TCR_CONT_SHIFT                     (21U)
/*! CONT - Continuous Transfer
 *  0b0..Continuous transfer is disabled
 *  0b1..Continuous transfer is enabled
 */
#define LPSPI_TCR_CONT(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CONT_SHIFT)) & LPSPI_TCR_CONT_MASK)

#define LPSPI_TCR_BYSW_MASK                      (0x400000U)
#define LPSPI_TCR_BYSW_SHIFT                     (22U)
/*! BYSW - Byte Swap
 *  0b0..Byte swap is disabled
 *  0b1..Byte swap is enabled
 */
#define LPSPI_TCR_BYSW(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_BYSW_SHIFT)) & LPSPI_TCR_BYSW_MASK)

#define LPSPI_TCR_LSBF_MASK                      (0x800000U)
#define LPSPI_TCR_LSBF_SHIFT                     (23U)
/*! LSBF - LSB First
 *  0b0..Data is transferred MSB first
 *  0b1..Data is transferred LSB first
 */
#define LPSPI_TCR_LSBF(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_LSBF_SHIFT)) & LPSPI_TCR_LSBF_MASK)

#define LPSPI_TCR_PCS_MASK                       (0x3000000U)
#define LPSPI_TCR_PCS_SHIFT                      (24U)
/*! PCS - Peripheral Chip Select
 *  0b00..Transfer using LPSPI_PCS[0]
 *  0b01..Transfer using LPSPI_PCS[1]
 *  0b10..Transfer using LPSPI_PCS[2]
 *  0b11..Transfer using LPSPI_PCS[3]
 */
#define LPSPI_TCR_PCS(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_PCS_SHIFT)) & LPSPI_TCR_PCS_MASK)

#define LPSPI_TCR_PRESCALE_MASK                  (0x38000000U)
#define LPSPI_TCR_PRESCALE_SHIFT                 (27U)
/*! PRESCALE - Prescaler Value
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 *  0b110..Divide by 64
 *  0b111..Divide by 128
 */
#define LPSPI_TCR_PRESCALE(x)                    (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_PRESCALE_SHIFT)) & LPSPI_TCR_PRESCALE_MASK)

#define LPSPI_TCR_CPHA_MASK                      (0x40000000U)
#define LPSPI_TCR_CPHA_SHIFT                     (30U)
/*! CPHA - Clock Phase
 *  0b0..Data is captured on the leading edge of SCK and changed on the following edge of SCK
 *  0b1..Data is changed on the leading edge of SCK and captured on the following edge of SCK
 */
#define LPSPI_TCR_CPHA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CPHA_SHIFT)) & LPSPI_TCR_CPHA_MASK)

#define LPSPI_TCR_CPOL_MASK                      (0x80000000U)
#define LPSPI_TCR_CPOL_SHIFT                     (31U)
/*! CPOL - Clock Polarity
 *  0b0..The inactive state value of SCK is low
 *  0b1..The inactive state value of SCK is high
 */
#define LPSPI_TCR_CPOL(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TCR_CPOL_SHIFT)) & LPSPI_TCR_CPOL_MASK)
/*! @} */

/*! @name TDR - Transmit Data Register */
/*! @{ */

#define LPSPI_TDR_DATA_MASK                      (0xFFFFFFFFU)
#define LPSPI_TDR_DATA_SHIFT                     (0U)
/*! DATA - Transmit Data */
#define LPSPI_TDR_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_TDR_DATA_SHIFT)) & LPSPI_TDR_DATA_MASK)
/*! @} */

/*! @name RSR - Receive Status Register */
/*! @{ */

#define LPSPI_RSR_SOF_MASK                       (0x1U)
#define LPSPI_RSR_SOF_SHIFT                      (0U)
/*! SOF - Start Of Frame
 *  0b0..Subsequent data word received after LPSPI_PCS assertion
 *  0b1..First data word received after LPSPI_PCS assertion
 */
#define LPSPI_RSR_SOF(x)                         (((uint32_t)(((uint32_t)(x)) << LPSPI_RSR_SOF_SHIFT)) & LPSPI_RSR_SOF_MASK)

#define LPSPI_RSR_RXEMPTY_MASK                   (0x2U)
#define LPSPI_RSR_RXEMPTY_SHIFT                  (1U)
/*! RXEMPTY - RX FIFO Empty
 *  0b0..RX FIFO is not empty
 *  0b1..RX FIFO is empty
 */
#define LPSPI_RSR_RXEMPTY(x)                     (((uint32_t)(((uint32_t)(x)) << LPSPI_RSR_RXEMPTY_SHIFT)) & LPSPI_RSR_RXEMPTY_MASK)
/*! @} */

/*! @name RDR - Receive Data Register */
/*! @{ */

#define LPSPI_RDR_DATA_MASK                      (0xFFFFFFFFU)
#define LPSPI_RDR_DATA_SHIFT                     (0U)
/*! DATA - Receive Data */
#define LPSPI_RDR_DATA(x)                        (((uint32_t)(((uint32_t)(x)) << LPSPI_RDR_DATA_SHIFT)) & LPSPI_RDR_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LPSPI_Register_Masks */


/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */


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


#endif  /* LPSPI_H_ */

