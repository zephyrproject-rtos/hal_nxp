/*
** ###################################################################
**     Processors:          MIMXRT1171AVM8A
**                          MIMXRT1171AVM8B
**                          MIMXRT1171CVM8A
**                          MIMXRT1171CVM8B
**                          MIMXRT1171DVMAA
**                          MIMXRT1171DVMAB
**                          MIMXRT1172AVM8A
**                          MIMXRT1172AVM8B
**                          MIMXRT1172CVM8A
**                          MIMXRT1172CVM8B
**                          MIMXRT1172DVMAA
**                          MIMXRT1172DVMAB
**                          MIMXRT1173CVM8A_cm4
**                          MIMXRT1173CVM8A_cm7
**                          MIMXRT1173CVM8B_cm4
**                          MIMXRT1173CVM8B_cm7
**                          MIMXRT1175AVM8A_cm4
**                          MIMXRT1175AVM8A_cm7
**                          MIMXRT1175AVM8B_cm4
**                          MIMXRT1175AVM8B_cm7
**                          MIMXRT1175CVM8A_cm4
**                          MIMXRT1175CVM8A_cm7
**                          MIMXRT1175CVM8B_cm4
**                          MIMXRT1175CVM8B_cm7
**                          MIMXRT1175DVMAA_cm4
**                          MIMXRT1175DVMAA_cm7
**                          MIMXRT1175DVMAB_cm4
**                          MIMXRT1175DVMAB_cm7
**                          MIMXRT1176AVM8A_cm4
**                          MIMXRT1176AVM8A_cm7
**                          MIMXRT1176AVM8B_cm4
**                          MIMXRT1176AVM8B_cm7
**                          MIMXRT1176CVM8A_cm4
**                          MIMXRT1176CVM8A_cm7
**                          MIMXRT1176CVM8B_cm4
**                          MIMXRT1176CVM8B_cm7
**                          MIMXRT1176DVMAA_cm4
**                          MIMXRT1176DVMAA_cm7
**                          MIMXRT1176DVMAB_cm4
**                          MIMXRT1176DVMAB_cm7
**                          MIMXRT117HAVM8A_cm4
**                          MIMXRT117HAVM8A_cm7
**                          MIMXRT117HAVM8B_cm4
**                          MIMXRT117HAVM8B_cm7
**                          MIMXRT117HCVM8A_cm4
**                          MIMXRT117HCVM8A_cm7
**                          MIMXRT117HCVM8B_cm4
**                          MIMXRT117HCVM8B_cm7
**                          MIMXRT117HDVMAA_cm4
**                          MIMXRT117HDVMAA_cm7
**                          MIMXRT117HDVMAB_cm4
**                          MIMXRT117HDVMAB_cm7
**
**     Version:             rev. 4.0, 2026-01-06
**     Build:               b260106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XRDC2
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2018-03-05)
**         Initial version.
**     - rev. 1.0 (2020-12-29)
**         Update header files to align with IMXRT1170RM Rev.0.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**     - rev. 3.0 (2025-11-13)
**         Consolidate asrc/xbar and enet macros into common header.
**     - rev. 4.0 (2026-01-06)
**         Update header files to align with IMXRT1170RM Rev.5.
**
** ###################################################################
*/

/*!
 * @file PERI_XRDC2.h
 * @version 4.0
 * @date 2026-01-06
 * @brief CMSIS Peripheral Access Layer for XRDC2
 *
 * CMSIS Peripheral Access Layer for XRDC2
 */

#if !defined(PERI_XRDC2_H_)
#define PERI_XRDC2_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1171AVM8A) || defined(CPU_MIMXRT1171AVM8B) || defined(CPU_MIMXRT1171CVM8A) || defined(CPU_MIMXRT1171CVM8B) || defined(CPU_MIMXRT1171DVMAA) || defined(CPU_MIMXRT1171DVMAB))
#include "MIMXRT1171_COMMON.h"
#elif (defined(CPU_MIMXRT1172AVM8A) || defined(CPU_MIMXRT1172AVM8B) || defined(CPU_MIMXRT1172CVM8A) || defined(CPU_MIMXRT1172CVM8B) || defined(CPU_MIMXRT1172DVMAA) || defined(CPU_MIMXRT1172DVMAB))
#include "MIMXRT1172_COMMON.h"
#elif (defined(CPU_MIMXRT1173CVM8A_cm4) || defined(CPU_MIMXRT1173CVM8B_cm4))
#include "MIMXRT1173_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1173CVM8A_cm7) || defined(CPU_MIMXRT1173CVM8B_cm7))
#include "MIMXRT1173_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1175AVM8A_cm4) || defined(CPU_MIMXRT1175AVM8B_cm4) || defined(CPU_MIMXRT1175CVM8A_cm4) || defined(CPU_MIMXRT1175CVM8B_cm4) || defined(CPU_MIMXRT1175DVMAA_cm4) || defined(CPU_MIMXRT1175DVMAB_cm4))
#include "MIMXRT1175_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1175AVM8A_cm7) || defined(CPU_MIMXRT1175AVM8B_cm7) || defined(CPU_MIMXRT1175CVM8A_cm7) || defined(CPU_MIMXRT1175CVM8B_cm7) || defined(CPU_MIMXRT1175DVMAA_cm7) || defined(CPU_MIMXRT1175DVMAB_cm7))
#include "MIMXRT1175_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1176AVM8A_cm4) || defined(CPU_MIMXRT1176AVM8B_cm4) || defined(CPU_MIMXRT1176CVM8A_cm4) || defined(CPU_MIMXRT1176CVM8B_cm4) || defined(CPU_MIMXRT1176DVMAA_cm4) || defined(CPU_MIMXRT1176DVMAB_cm4))
#include "MIMXRT1176_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT1176AVM8A_cm7) || defined(CPU_MIMXRT1176AVM8B_cm7) || defined(CPU_MIMXRT1176CVM8A_cm7) || defined(CPU_MIMXRT1176CVM8B_cm7) || defined(CPU_MIMXRT1176DVMAA_cm7) || defined(CPU_MIMXRT1176DVMAB_cm7))
#include "MIMXRT1176_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT117HAVM8A_cm4) || defined(CPU_MIMXRT117HAVM8B_cm4) || defined(CPU_MIMXRT117HCVM8A_cm4) || defined(CPU_MIMXRT117HCVM8B_cm4) || defined(CPU_MIMXRT117HDVMAA_cm4) || defined(CPU_MIMXRT117HDVMAB_cm4))
#include "MIMXRT117H_cm4_COMMON.h"
#elif (defined(CPU_MIMXRT117HAVM8A_cm7) || defined(CPU_MIMXRT117HAVM8B_cm7) || defined(CPU_MIMXRT117HCVM8A_cm7) || defined(CPU_MIMXRT117HCVM8B_cm7) || defined(CPU_MIMXRT117HDVMAA_cm7) || defined(CPU_MIMXRT117HDVMAB_cm7))
#include "MIMXRT117H_cm7_COMMON.h"
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
   -- XRDC2 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC2_Peripheral_Access_Layer XRDC2 Peripheral Access Layer
 * @{
 */

/** XRDC2 - Size of Registers Arrays */
#define XRDC2_MSCI_MSAC_WK_COUNT                  128u
#define XRDC2_MDACI_COUNT                         32u
#define XRDC2_MDACI_MDACI_MDAJ_COUNT              32u
#define XRDC2_PACI_COUNT                          8u
#define XRDC2_PACI_PACI_PDACJ_COUNT               256u
#define XRDC2_MRCI_COUNT                          32u
#define XRDC2_MRCI_MRCI_MRGDJ_COUNT               32u

/** XRDC2 - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x0 */
  __I  uint32_t SR;                                /**< Status Register, offset: 0x4 */
       uint8_t RESERVED_0[4088];
  struct {                                         /* offset: 0x1000, array step: 0x8 */
    __IO uint32_t MSC_MSAC_W0;                       /**< Memory Slot Access Control, array offset: 0x1000, array step: 0x8 */
    __IO uint32_t MSC_MSAC_W1;                       /**< Memory Slot Access Control, array offset: 0x1004, array step: 0x8 */
  } MSCI_MSAC_WK[XRDC2_MSCI_MSAC_WK_COUNT];
       uint8_t RESERVED_1[3072];
  struct {                                         /* offset: 0x2000, array step: index*0x100, index2*0x8 */
    __IO uint32_t MDAC_MDA_W0;                       /**< Master Domain Assignment, array offset: 0x2000, array step: index*0x100, index2*0x8 */
    __IO uint32_t MDAC_MDA_W1;                       /**< Master Domain Assignment, array offset: 0x2004, array step: index*0x100, index2*0x8 */
  } MDACI_MDAJ[XRDC2_MDACI_COUNT][XRDC2_MDACI_MDACI_MDAJ_COUNT];
  struct {                                         /* offset: 0x4000, array step: index*0x800, index2*0x8 */
    __IO uint32_t PAC_PDAC_W0;                       /**< Peripheral Domain Access Control, array offset: 0x4000, array step: index*0x800, index2*0x8 */
    __IO uint32_t PAC_PDAC_W1;                       /**< Peripheral Domain Access Control, array offset: 0x4004, array step: index*0x800, index2*0x8 */
  } PACI_PDACJ[XRDC2_PACI_COUNT][XRDC2_PACI_PACI_PDACJ_COUNT];
  struct {                                         /* offset: 0x8000, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W0;                       /**< Memory Region Descriptor, array offset: 0x8000, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W1;                       /**< Memory Region Descriptor, array offset: 0x8004, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W2;                       /**< Memory Region Descriptor, array offset: 0x8008, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W3;                       /**< Memory Region Descriptor, array offset: 0x800C, array step: index*0x400, index2*0x20 */
         uint8_t RESERVED_0[4];
    __IO uint32_t MRC_MRGD_W5;                       /**< Memory Region Descriptor, array offset: 0x8014, array step: index*0x400, index2*0x20 */
    __IO uint32_t MRC_MRGD_W6;                       /**< Memory Region Descriptor, array offset: 0x8018, array step: index*0x400, index2*0x20 */
         uint8_t RESERVED_1[4];
  } MRCI_MRGDJ[XRDC2_MRCI_COUNT][XRDC2_MRCI_MRCI_MRGDJ_COUNT];
} XRDC2_Type;

/* ----------------------------------------------------------------------------
   -- XRDC2 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC2_Register_Masks XRDC2 Register Masks
 * @{
 */

/*! @name MCR - Module Control Register */
/*! @{ */

#define XRDC2_MCR_GVLDM_MASK                     (0x1U)
#define XRDC2_MCR_GVLDM_SHIFT                    (0U)
/*! GVLDM - Global Valid MDAC
 *  0b0..MDACs are disabled.
 *  0b1..MDACs are enabled.
 */
#define XRDC2_MCR_GVLDM(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GVLDM_SHIFT)) & XRDC2_MCR_GVLDM_MASK)

#define XRDC2_MCR_GVLDC_MASK                     (0x2U)
#define XRDC2_MCR_GVLDC_SHIFT                    (1U)
/*! GVLDC - Global Valid Access Control
 *  0b0..Access controls are disabled, XRDC2 allows all transactions.
 *  0b1..Access controls are enabled.
 */
#define XRDC2_MCR_GVLDC(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GVLDC_SHIFT)) & XRDC2_MCR_GVLDC_MASK)

#define XRDC2_MCR_GCL_MASK                       (0x30U)
#define XRDC2_MCR_GCL_SHIFT                      (4U)
/*! GCL - Global Configuration Lock
 *  0b00..Lock disabled, registers can be written by any domain.
 *  0b01..Lock disabled until the next reset, registers can be written by any domain.
 *  0b10..Lock enabled, only the global configuration lock owner (SR[GCLO]) can write to registers.
 *  0b11..Lock enabled, all registers are read only until the next reset.
 */
#define XRDC2_MCR_GCL(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC2_MCR_GCL_SHIFT)) & XRDC2_MCR_GCL_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define XRDC2_SR_DIN_MASK                        (0xFU)
#define XRDC2_SR_DIN_SHIFT                       (0U)
/*! DIN - Domain Identifier Number */
#define XRDC2_SR_DIN(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_DIN_SHIFT)) & XRDC2_SR_DIN_MASK)

#define XRDC2_SR_HRL_MASK                        (0xF0U)
#define XRDC2_SR_HRL_SHIFT                       (4U)
/*! HRL - Hardware Revision Level */
#define XRDC2_SR_HRL(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_HRL_SHIFT)) & XRDC2_SR_HRL_MASK)

#define XRDC2_SR_GCLO_MASK                       (0xF00U)
#define XRDC2_SR_GCLO_SHIFT                      (8U)
/*! GCLO - Global Configuration Lock Owner */
#define XRDC2_SR_GCLO(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC2_SR_GCLO_SHIFT)) & XRDC2_SR_GCLO_MASK)
/*! @} */

/*! @name MSC_MSAC_W0 - Memory Slot Access Control */
/*! @{ */

#define XRDC2_MSC_MSAC_W0_D0ACP_MASK             (0x7U)
#define XRDC2_MSC_MSAC_W0_D0ACP_SHIFT            (0U)
/*! D0ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D0ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D0ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D1ACP_MASK             (0x38U)
#define XRDC2_MSC_MSAC_W0_D1ACP_SHIFT            (3U)
/*! D1ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D1ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D1ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D2ACP_MASK             (0x1C0U)
#define XRDC2_MSC_MSAC_W0_D2ACP_SHIFT            (6U)
/*! D2ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D2ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D2ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D3ACP_MASK             (0xE00U)
#define XRDC2_MSC_MSAC_W0_D3ACP_SHIFT            (9U)
/*! D3ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D3ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D3ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D4ACP_MASK             (0x7000U)
#define XRDC2_MSC_MSAC_W0_D4ACP_SHIFT            (12U)
/*! D4ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D4ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D4ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D5ACP_MASK             (0x38000U)
#define XRDC2_MSC_MSAC_W0_D5ACP_SHIFT            (15U)
/*! D5ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D5ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D5ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D6ACP_MASK             (0x1C0000U)
#define XRDC2_MSC_MSAC_W0_D6ACP_SHIFT            (18U)
/*! D6ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D6ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D6ACP_MASK)

#define XRDC2_MSC_MSAC_W0_D7ACP_MASK             (0xE00000U)
#define XRDC2_MSC_MSAC_W0_D7ACP_SHIFT            (21U)
/*! D7ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W0_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_D7ACP_SHIFT)) & XRDC2_MSC_MSAC_W0_D7ACP_MASK)

#define XRDC2_MSC_MSAC_W0_EALO_MASK              (0xF000000U)
#define XRDC2_MSC_MSAC_W0_EALO_SHIFT             (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XRDC2_MSC_MSAC_W0_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W0_EALO_SHIFT)) & XRDC2_MSC_MSAC_W0_EALO_MASK)
/*! @} */

/* The count of XRDC2_MSC_MSAC_W0 */
#define XRDC2_MSC_MSAC_W0_COUNT                  (128U)

/*! @name MSC_MSAC_W1 - Memory Slot Access Control */
/*! @{ */

#define XRDC2_MSC_MSAC_W1_D8ACP_MASK             (0x7U)
#define XRDC2_MSC_MSAC_W1_D8ACP_SHIFT            (0U)
/*! D8ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D8ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D8ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D9ACP_MASK             (0x38U)
#define XRDC2_MSC_MSAC_W1_D9ACP_SHIFT            (3U)
/*! D9ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D9ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D9ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D10ACP_MASK            (0x1C0U)
#define XRDC2_MSC_MSAC_W1_D10ACP_SHIFT           (6U)
/*! D10ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D10ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D10ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D11ACP_MASK            (0xE00U)
#define XRDC2_MSC_MSAC_W1_D11ACP_SHIFT           (9U)
/*! D11ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D11ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D11ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D12ACP_MASK            (0x7000U)
#define XRDC2_MSC_MSAC_W1_D12ACP_SHIFT           (12U)
/*! D12ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D12ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D12ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D13ACP_MASK            (0x38000U)
#define XRDC2_MSC_MSAC_W1_D13ACP_SHIFT           (15U)
/*! D13ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D13ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D13ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D14ACP_MASK            (0x1C0000U)
#define XRDC2_MSC_MSAC_W1_D14ACP_SHIFT           (18U)
/*! D14ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D14ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D14ACP_MASK)

#define XRDC2_MSC_MSAC_W1_D15ACP_MASK            (0xE00000U)
#define XRDC2_MSC_MSAC_W1_D15ACP_SHIFT           (21U)
/*! D15ACP - Domain "x" access control policy */
#define XRDC2_MSC_MSAC_W1_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_D15ACP_SHIFT)) & XRDC2_MSC_MSAC_W1_D15ACP_MASK)

#define XRDC2_MSC_MSAC_W1_EAL_MASK               (0x3000000U)
#define XRDC2_MSC_MSAC_W1_EAL_SHIFT              (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..Lock disabled.
 *  0b01..Lock disabled until next reset.
 *  0b10..Lock enabled, lock state = available.
 *  0b11..Lock enabled, lock state = not available.
 */
#define XRDC2_MSC_MSAC_W1_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_EAL_SHIFT)) & XRDC2_MSC_MSAC_W1_EAL_MASK)

#define XRDC2_MSC_MSAC_W1_DL2_MASK               (0x60000000U)
#define XRDC2_MSC_MSAC_W1_DL2_SHIFT              (29U)
/*! DL2 - Descriptor Lock
 *  0b00..Lock disabled, descriptor registers can be written.
 *  0b01..Lock disabled until the next reset, descriptor registers can be written.
 *  0b10..Lock enabled, only domain "x" can only update the DxACP field; no other fields can be written.
 *  0b11..Lock enabled, descriptor registers are read-only until the next reset.
 */
#define XRDC2_MSC_MSAC_W1_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_DL2_SHIFT)) & XRDC2_MSC_MSAC_W1_DL2_MASK)

#define XRDC2_MSC_MSAC_W1_VLD_MASK               (0x80000000U)
#define XRDC2_MSC_MSAC_W1_VLD_SHIFT              (31U)
/*! VLD - Valid
 *  0b0..The MSAC assignment is invalid.
 *  0b1..The MSAC assignment is valid.
 */
#define XRDC2_MSC_MSAC_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MSC_MSAC_W1_VLD_SHIFT)) & XRDC2_MSC_MSAC_W1_VLD_MASK)
/*! @} */

/* The count of XRDC2_MSC_MSAC_W1 */
#define XRDC2_MSC_MSAC_W1_COUNT                  (128U)

/*! @name MDAC_MDA_W0 - Master Domain Assignment */
/*! @{ */

#define XRDC2_MDAC_MDA_W0_MASK_MASK              (0xFFFFU)
#define XRDC2_MDAC_MDA_W0_MASK_SHIFT             (0U)
/*! MASK - Mask */
#define XRDC2_MDAC_MDA_W0_MASK(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W0_MASK_SHIFT)) & XRDC2_MDAC_MDA_W0_MASK_MASK)

#define XRDC2_MDAC_MDA_W0_MATCH_MASK             (0xFFFF0000U)
#define XRDC2_MDAC_MDA_W0_MATCH_SHIFT            (16U)
/*! MATCH - Match */
#define XRDC2_MDAC_MDA_W0_MATCH(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W0_MATCH_SHIFT)) & XRDC2_MDAC_MDA_W0_MATCH_MASK)
/*! @} */

/* The count of XRDC2_MDAC_MDA_W0 */
#define XRDC2_MDAC_MDA_W0_COUNT                  (32U)

/* The count of XRDC2_MDAC_MDA_W0 */
#define XRDC2_MDAC_MDA_W0_COUNT2                 (32U)

/*! @name MDAC_MDA_W1 - Master Domain Assignment */
/*! @{ */

#define XRDC2_MDAC_MDA_W1_DID_MASK               (0xF0000U)
#define XRDC2_MDAC_MDA_W1_DID_SHIFT              (16U)
/*! DID - Domain Identifier */
#define XRDC2_MDAC_MDA_W1_DID(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_DID_SHIFT)) & XRDC2_MDAC_MDA_W1_DID_MASK)

#define XRDC2_MDAC_MDA_W1_PA_MASK                (0x3000000U)
#define XRDC2_MDAC_MDA_W1_PA_SHIFT               (24U)
/*! PA - Privileged attribute
 *  0b00..Use the bus master's privileged/user attribute directly.
 *  0b01..Use the bus master's privileged/user attribute directly.
 *  0b10..Force the bus attribute for this master to user.
 *  0b11..Force the bus attribute for this master to privileged.
 */
#define XRDC2_MDAC_MDA_W1_PA(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_PA_SHIFT)) & XRDC2_MDAC_MDA_W1_PA_MASK)

#define XRDC2_MDAC_MDA_W1_SA_MASK                (0xC000000U)
#define XRDC2_MDAC_MDA_W1_SA_SHIFT               (26U)
/*! SA - Secure attribute
 *  0b00..Use the bus master's secure/nonsecure attribute directly.
 *  0b01..Use the bus master's secure/nonsecure attribute directly.
 *  0b10..Force the bus attribute for this master to secure.
 *  0b11..Force the bus attribute for this master to nonsecure.
 */
#define XRDC2_MDAC_MDA_W1_SA(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_SA_SHIFT)) & XRDC2_MDAC_MDA_W1_SA_MASK)

#define XRDC2_MDAC_MDA_W1_DL_MASK                (0x40000000U)
#define XRDC2_MDAC_MDA_W1_DL_SHIFT               (30U)
/*! DL - Descriptor Lock
 *  0b0..Lock disabled, registers can be written.
 *  0b1..Lock enabled, registers are read-only until the next reset.
 */
#define XRDC2_MDAC_MDA_W1_DL(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_DL_SHIFT)) & XRDC2_MDAC_MDA_W1_DL_MASK)

#define XRDC2_MDAC_MDA_W1_VLD_MASK               (0x80000000U)
#define XRDC2_MDAC_MDA_W1_VLD_SHIFT              (31U)
/*! VLD - Valid
 *  0b0..The MDA is invalid.
 *  0b1..The MDA is valid.
 */
#define XRDC2_MDAC_MDA_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MDAC_MDA_W1_VLD_SHIFT)) & XRDC2_MDAC_MDA_W1_VLD_MASK)
/*! @} */

/* The count of XRDC2_MDAC_MDA_W1 */
#define XRDC2_MDAC_MDA_W1_COUNT                  (32U)

/* The count of XRDC2_MDAC_MDA_W1 */
#define XRDC2_MDAC_MDA_W1_COUNT2                 (32U)

/*! @name PAC_PDAC_W0 - Peripheral Domain Access Control */
/*! @{ */

#define XRDC2_PAC_PDAC_W0_D0ACP_MASK             (0x7U)
#define XRDC2_PAC_PDAC_W0_D0ACP_SHIFT            (0U)
/*! D0ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D0ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D0ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D1ACP_MASK             (0x38U)
#define XRDC2_PAC_PDAC_W0_D1ACP_SHIFT            (3U)
/*! D1ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D1ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D1ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D2ACP_MASK             (0x1C0U)
#define XRDC2_PAC_PDAC_W0_D2ACP_SHIFT            (6U)
/*! D2ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D2ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D2ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D3ACP_MASK             (0xE00U)
#define XRDC2_PAC_PDAC_W0_D3ACP_SHIFT            (9U)
/*! D3ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D3ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D3ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D4ACP_MASK             (0x7000U)
#define XRDC2_PAC_PDAC_W0_D4ACP_SHIFT            (12U)
/*! D4ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D4ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D4ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D5ACP_MASK             (0x38000U)
#define XRDC2_PAC_PDAC_W0_D5ACP_SHIFT            (15U)
/*! D5ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D5ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D5ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D6ACP_MASK             (0x1C0000U)
#define XRDC2_PAC_PDAC_W0_D6ACP_SHIFT            (18U)
/*! D6ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D6ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D6ACP_MASK)

#define XRDC2_PAC_PDAC_W0_D7ACP_MASK             (0xE00000U)
#define XRDC2_PAC_PDAC_W0_D7ACP_SHIFT            (21U)
/*! D7ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W0_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_D7ACP_SHIFT)) & XRDC2_PAC_PDAC_W0_D7ACP_MASK)

#define XRDC2_PAC_PDAC_W0_EALO_MASK              (0xF000000U)
#define XRDC2_PAC_PDAC_W0_EALO_SHIFT             (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XRDC2_PAC_PDAC_W0_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W0_EALO_SHIFT)) & XRDC2_PAC_PDAC_W0_EALO_MASK)
/*! @} */

/* The count of XRDC2_PAC_PDAC_W0 */
#define XRDC2_PAC_PDAC_W0_COUNT                  (8U)

/* The count of XRDC2_PAC_PDAC_W0 */
#define XRDC2_PAC_PDAC_W0_COUNT2                 (256U)

/*! @name PAC_PDAC_W1 - Peripheral Domain Access Control */
/*! @{ */

#define XRDC2_PAC_PDAC_W1_D8ACP_MASK             (0x7U)
#define XRDC2_PAC_PDAC_W1_D8ACP_SHIFT            (0U)
/*! D8ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D8ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D8ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D9ACP_MASK             (0x38U)
#define XRDC2_PAC_PDAC_W1_D9ACP_SHIFT            (3U)
/*! D9ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D9ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D9ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D10ACP_MASK            (0x1C0U)
#define XRDC2_PAC_PDAC_W1_D10ACP_SHIFT           (6U)
/*! D10ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D10ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D10ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D11ACP_MASK            (0xE00U)
#define XRDC2_PAC_PDAC_W1_D11ACP_SHIFT           (9U)
/*! D11ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D11ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D11ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D12ACP_MASK            (0x7000U)
#define XRDC2_PAC_PDAC_W1_D12ACP_SHIFT           (12U)
/*! D12ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D12ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D12ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D13ACP_MASK            (0x38000U)
#define XRDC2_PAC_PDAC_W1_D13ACP_SHIFT           (15U)
/*! D13ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D13ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D13ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D14ACP_MASK            (0x1C0000U)
#define XRDC2_PAC_PDAC_W1_D14ACP_SHIFT           (18U)
/*! D14ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D14ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D14ACP_MASK)

#define XRDC2_PAC_PDAC_W1_D15ACP_MASK            (0xE00000U)
#define XRDC2_PAC_PDAC_W1_D15ACP_SHIFT           (21U)
/*! D15ACP - Domain "x" access control policy */
#define XRDC2_PAC_PDAC_W1_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_D15ACP_SHIFT)) & XRDC2_PAC_PDAC_W1_D15ACP_MASK)

#define XRDC2_PAC_PDAC_W1_EAL_MASK               (0x3000000U)
#define XRDC2_PAC_PDAC_W1_EAL_SHIFT              (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..Lock disabled.
 *  0b01..Lock disabled until next reset.
 *  0b10..Lock enabled, lock state = available.
 *  0b11..Lock enabled, lock state = not available.
 */
#define XRDC2_PAC_PDAC_W1_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_EAL_SHIFT)) & XRDC2_PAC_PDAC_W1_EAL_MASK)

#define XRDC2_PAC_PDAC_W1_DL2_MASK               (0x60000000U)
#define XRDC2_PAC_PDAC_W1_DL2_SHIFT              (29U)
/*! DL2 - Descriptor Lock
 *  0b00..Lock disabled, descriptor registers can be written..
 *  0b01..Lock disabled until the next reset, descriptor registers can be written..
 *  0b10..Lock enabled, only domain "x" can only update the DxACP field; no other fields can be written..
 *  0b11..Lock enabled, descriptor registers are read-only until the next reset.
 */
#define XRDC2_PAC_PDAC_W1_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_DL2_SHIFT)) & XRDC2_PAC_PDAC_W1_DL2_MASK)

#define XRDC2_PAC_PDAC_W1_VLD_MASK               (0x80000000U)
#define XRDC2_PAC_PDAC_W1_VLD_SHIFT              (31U)
/*! VLD - Valid
 *  0b0..The PDAC assignment is invalid.
 *  0b1..The PDAC assignment is valid.
 */
#define XRDC2_PAC_PDAC_W1_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_PAC_PDAC_W1_VLD_SHIFT)) & XRDC2_PAC_PDAC_W1_VLD_MASK)
/*! @} */

/* The count of XRDC2_PAC_PDAC_W1 */
#define XRDC2_PAC_PDAC_W1_COUNT                  (8U)

/* The count of XRDC2_PAC_PDAC_W1 */
#define XRDC2_PAC_PDAC_W1_COUNT2                 (256U)

/*! @name MRC_MRGD_W0 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W0_SRTADDR_MASK           (0xFFFFF000U)
#define XRDC2_MRC_MRGD_W0_SRTADDR_SHIFT          (12U)
/*! SRTADDR - Start Address */
#define XRDC2_MRC_MRGD_W0_SRTADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W0_SRTADDR_SHIFT)) & XRDC2_MRC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W0 */
#define XRDC2_MRC_MRGD_W0_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W0 */
#define XRDC2_MRC_MRGD_W0_COUNT2                 (32U)

/*! @name MRC_MRGD_W1 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W1_SRTADDR_MASK           (0xFU)
#define XRDC2_MRC_MRGD_W1_SRTADDR_SHIFT          (0U)
/*! SRTADDR - Start Address */
#define XRDC2_MRC_MRGD_W1_SRTADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W1_SRTADDR_SHIFT)) & XRDC2_MRC_MRGD_W1_SRTADDR_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W1 */
#define XRDC2_MRC_MRGD_W1_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W1 */
#define XRDC2_MRC_MRGD_W1_COUNT2                 (32U)

/*! @name MRC_MRGD_W2 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W2_ENDADDR_MASK           (0xFFFFF000U)
#define XRDC2_MRC_MRGD_W2_ENDADDR_SHIFT          (12U)
/*! ENDADDR - End Address */
#define XRDC2_MRC_MRGD_W2_ENDADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W2_ENDADDR_SHIFT)) & XRDC2_MRC_MRGD_W2_ENDADDR_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W2 */
#define XRDC2_MRC_MRGD_W2_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W2 */
#define XRDC2_MRC_MRGD_W2_COUNT2                 (32U)

/*! @name MRC_MRGD_W3 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W3_ENDADDR_MASK           (0xFU)
#define XRDC2_MRC_MRGD_W3_ENDADDR_SHIFT          (0U)
/*! ENDADDR - End Address */
#define XRDC2_MRC_MRGD_W3_ENDADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W3_ENDADDR_SHIFT)) & XRDC2_MRC_MRGD_W3_ENDADDR_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W3 */
#define XRDC2_MRC_MRGD_W3_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W3 */
#define XRDC2_MRC_MRGD_W3_COUNT2                 (32U)

/*! @name MRC_MRGD_W5 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W5_D0ACP_MASK             (0x7U)
#define XRDC2_MRC_MRGD_W5_D0ACP_SHIFT            (0U)
/*! D0ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D0ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D0ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D1ACP_MASK             (0x38U)
#define XRDC2_MRC_MRGD_W5_D1ACP_SHIFT            (3U)
/*! D1ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D1ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D1ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D2ACP_MASK             (0x1C0U)
#define XRDC2_MRC_MRGD_W5_D2ACP_SHIFT            (6U)
/*! D2ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D2ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D2ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D3ACP_MASK             (0xE00U)
#define XRDC2_MRC_MRGD_W5_D3ACP_SHIFT            (9U)
/*! D3ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D3ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D3ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D4ACP_MASK             (0x7000U)
#define XRDC2_MRC_MRGD_W5_D4ACP_SHIFT            (12U)
/*! D4ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D4ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D4ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D5ACP_MASK             (0x38000U)
#define XRDC2_MRC_MRGD_W5_D5ACP_SHIFT            (15U)
/*! D5ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D5ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D5ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D6ACP_MASK             (0x1C0000U)
#define XRDC2_MRC_MRGD_W5_D6ACP_SHIFT            (18U)
/*! D6ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D6ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D6ACP_MASK)

#define XRDC2_MRC_MRGD_W5_D7ACP_MASK             (0xE00000U)
#define XRDC2_MRC_MRGD_W5_D7ACP_SHIFT            (21U)
/*! D7ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W5_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_D7ACP_SHIFT)) & XRDC2_MRC_MRGD_W5_D7ACP_MASK)

#define XRDC2_MRC_MRGD_W5_EALO_MASK              (0xF000000U)
#define XRDC2_MRC_MRGD_W5_EALO_SHIFT             (24U)
/*! EALO - Exclusive Access Lock Owner */
#define XRDC2_MRC_MRGD_W5_EALO(x)                (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W5_EALO_SHIFT)) & XRDC2_MRC_MRGD_W5_EALO_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W5 */
#define XRDC2_MRC_MRGD_W5_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W5 */
#define XRDC2_MRC_MRGD_W5_COUNT2                 (32U)

/*! @name MRC_MRGD_W6 - Memory Region Descriptor */
/*! @{ */

#define XRDC2_MRC_MRGD_W6_D8ACP_MASK             (0x7U)
#define XRDC2_MRC_MRGD_W6_D8ACP_SHIFT            (0U)
/*! D8ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D8ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D8ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D9ACP_MASK             (0x38U)
#define XRDC2_MRC_MRGD_W6_D9ACP_SHIFT            (3U)
/*! D9ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D9ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D9ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D10ACP_MASK            (0x1C0U)
#define XRDC2_MRC_MRGD_W6_D10ACP_SHIFT           (6U)
/*! D10ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D10ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D10ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D11ACP_MASK            (0xE00U)
#define XRDC2_MRC_MRGD_W6_D11ACP_SHIFT           (9U)
/*! D11ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D11ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D11ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D12ACP_MASK            (0x7000U)
#define XRDC2_MRC_MRGD_W6_D12ACP_SHIFT           (12U)
/*! D12ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D12ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D12ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D13ACP_MASK            (0x38000U)
#define XRDC2_MRC_MRGD_W6_D13ACP_SHIFT           (15U)
/*! D13ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D13ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D13ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D14ACP_MASK            (0x1C0000U)
#define XRDC2_MRC_MRGD_W6_D14ACP_SHIFT           (18U)
/*! D14ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D14ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D14ACP_MASK)

#define XRDC2_MRC_MRGD_W6_D15ACP_MASK            (0xE00000U)
#define XRDC2_MRC_MRGD_W6_D15ACP_SHIFT           (21U)
/*! D15ACP - Domain "x" access control policy */
#define XRDC2_MRC_MRGD_W6_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_D15ACP_SHIFT)) & XRDC2_MRC_MRGD_W6_D15ACP_MASK)

#define XRDC2_MRC_MRGD_W6_EAL_MASK               (0x3000000U)
#define XRDC2_MRC_MRGD_W6_EAL_SHIFT              (24U)
/*! EAL - Exclusive Access Lock
 *  0b00..Lock disabled.
 *  0b01..Lock disabled until next reset.
 *  0b10..Lock enabled, lock state = available.
 *  0b11..Lock enabled, lock state = not available.
 */
#define XRDC2_MRC_MRGD_W6_EAL(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_EAL_SHIFT)) & XRDC2_MRC_MRGD_W6_EAL_MASK)

#define XRDC2_MRC_MRGD_W6_DL2_MASK               (0x60000000U)
#define XRDC2_MRC_MRGD_W6_DL2_SHIFT              (29U)
/*! DL2 - Descriptor Lock
 *  0b00..Lock disabled, descriptor registers can be written.
 *  0b01..Lock disabled until the next reset, descriptor registers can be written.
 *  0b10..Lock enabled, only domain "x" can only update the DxACP field; no other fields can be written.
 *  0b11..Lock enabled, descriptor registers are read-only until the next reset.
 */
#define XRDC2_MRC_MRGD_W6_DL2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_DL2_SHIFT)) & XRDC2_MRC_MRGD_W6_DL2_MASK)

#define XRDC2_MRC_MRGD_W6_VLD_MASK               (0x80000000U)
#define XRDC2_MRC_MRGD_W6_VLD_SHIFT              (31U)
/*! VLD - Valid
 *  0b0..The MRGD is invalid.
 *  0b1..The MRGD is valid.
 */
#define XRDC2_MRC_MRGD_W6_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC2_MRC_MRGD_W6_VLD_SHIFT)) & XRDC2_MRC_MRGD_W6_VLD_MASK)
/*! @} */

/* The count of XRDC2_MRC_MRGD_W6 */
#define XRDC2_MRC_MRGD_W6_COUNT                  (32U)

/* The count of XRDC2_MRC_MRGD_W6 */
#define XRDC2_MRC_MRGD_W6_COUNT2                 (32U)


/*!
 * @}
 */ /* end of group XRDC2_Register_Masks */


/*!
 * @}
 */ /* end of group XRDC2_Peripheral_Access_Layer */


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


#endif  /* PERI_XRDC2_H_ */

