/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for NETC_SW
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_NETC_SW.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NETC_SW
 *
 * CMSIS Peripheral Access Layer for NETC_SW
 */

#if !defined(PERI_NETC_SW_H_)
#define PERI_NETC_SW_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
   -- NETC_SW Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_SW_Peripheral_Access_Layer NETC_SW Peripheral Access Layer
 * @{
 */

/** NETC_SW - Size of Registers Arrays */
#define NETC_SW_NUM_CBDR_COUNT                    2u
#define NETC_SW_NUM_CBDR_INT_COUNT                2u
#define NETC_SW_MAP_PCP_MAP_IPV_COUNT             4u
#define NETC_SW_MAP_PCP_COUNT                     2u
#define NETC_SW_NUM_PCP2PCPMPR_COUNT              2u

/** NETC_SW - Register Layout Typedef */
typedef struct {
  __I  uint32_t SCAPR0;                            /**< Switch capability register 0, offset: 0x0 */
  __I  uint32_t SCAPR1;                            /**< Switch capability register 1, offset: 0x4 */
  __I  uint32_t BPCAPR;                            /**< Buffer pool capability register, offset: 0x8 */
       uint8_t RESERVED_0[12];
  __I  uint32_t FCAPR;                             /**< Forwarding capability register, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __I  uint32_t SMBCAPR;                           /**< Shared memory buffer capability register, offset: 0x40 */
  __I  uint32_t SMBOR0;                            /**< Shared memory buffer operational register 0, offset: 0x44 */
  __I  uint32_t SMBOR1;                            /**< Shared memory buffer operational register 1, offset: 0x48 */
       uint8_t RESERVED_2[52];
  __IO uint32_t CCAR;                              /**< Command cache attribute register, offset: 0x80 */
       uint8_t RESERVED_3[892];
  __I  uint32_t MPCR;                              /**< Management port configuration register, offset: 0x400 */
       uint8_t RESERVED_4[28];
  __IO uint32_t IMDCR0;                            /**< Ingress mirror destination configuration register 0, offset: 0x420 */
  __IO uint32_t IMDCR1;                            /**< Ingress mirror destination configuration register 1, offset: 0x424 */
       uint8_t RESERVED_5[24];
  __IO uint32_t CTFCR;                             /**< Cut-through forwarding count register, offset: 0x440 */
       uint8_t RESERVED_6[956];
  struct {                                         /* offset: 0x800, array step: 0x30 */
    __IO uint32_t CBDRMR;                            /**< Command BDR 0 mode register..Command BDR 1 mode register, array offset: 0x800, array step: 0x30 */
    __I  uint32_t CBDRSR;                            /**< Command BDR 0 status register..Command BDR 1 status register, array offset: 0x804, array step: 0x30 */
         uint8_t RESERVED_0[8];
    __IO uint32_t CBDRBAR0;                          /**< Command BDR base address register 0, array offset: 0x810, array step: 0x30 */
    __IO uint32_t CBDRBAR1;                          /**< Command BDR 0 base address register 1..Command BDR 1 base address register 1, array offset: 0x814, array step: 0x30 */
    __IO uint32_t CBDRPIR;                           /**< Command BDR 0 producer index register..Command BDR 1 producer index register, array offset: 0x818, array step: 0x30 */
    __IO uint32_t CBDRCIR;                           /**< Command BDR 0 consumer index register..Command BDR 1 consumer index register, array offset: 0x81C, array step: 0x30 */
    __IO uint32_t CBDRLENR;                          /**< Command BDR 0 length register..Command BDR 1 length register, array offset: 0x820, array step: 0x30 */
         uint8_t RESERVED_1[12];
  } NUM_CBDR[NETC_SW_NUM_CBDR_COUNT];
       uint8_t RESERVED_7[64];
  struct {                                         /* offset: 0x8A0, array step: 0x10 */
    __IO uint32_t CBDRIER;                           /**< Command BDR 0 interrupt enable register..Command BDR 1 interrupt enable register, array offset: 0x8A0, array step: 0x10 */
    __IO uint32_t CBDRIDR;                           /**< Command BDR 0 interrupt detect register..Command BDR 1 interrupt detect register, array offset: 0x8A4, array step: 0x10 */
    __IO uint32_t CBDRMSIVR;                         /**< Command BDR 0 MSI-X vector register..Command BDR 1 MSI-X vector register, array offset: 0x8A8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } NUM_CBDR_INT[NETC_SW_NUM_CBDR_INT_COUNT];
       uint8_t RESERVED_8[64];
  struct {                                         /* offset: 0x900, array step: 0x20 */
    __IO uint32_t QOSVLANMPR[NETC_SW_MAP_PCP_MAP_IPV_COUNT];   /**< QoS to VLAN mapping profile 0 register 0..QoS to VLAN mapping profile 1 register 3, array offset: 0x900, array step: index*0x20, index2*0x4 */
         uint8_t RESERVED_0[16];
  } MAP_PCP[NETC_SW_MAP_PCP_COUNT];
       uint8_t RESERVED_9[448];
  __IO uint32_t PCP2PCPMPR[NETC_SW_NUM_PCP2PCPMPR_COUNT]; /**< PCP to PCP mapping profile 0 register..PCP to PCP mapping profile 1 register, array offset: 0xB00, array step: 0x4 */
       uint8_t RESERVED_10[5368];
  __I  uint32_t BRCAPR;                            /**< Bridge capability register, offset: 0x2000 */
       uint8_t RESERVED_11[4];
  __I  uint32_t VFHTCAPR;                          /**< VLAN filter hash table capability register, offset: 0x2008 */
  __I  uint32_t VFHTOR;                            /**< VLAN filter hash table operational register, offset: 0x200C */
  __IO uint32_t VFHTDECR0;                         /**< VLAN Filter (hash) table default entry configuration registers 0, offset: 0x2010 */
  __IO uint32_t VFHTDECR1;                         /**< VLAN filter hash table default entry configuration registers 1, offset: 0x2014 */
  __IO uint32_t VFHTDECR2;                         /**< VLAN filter hash table default entry configuration registers 2, offset: 0x2018 */
       uint8_t RESERVED_12[4];
  __I  uint32_t FDBHTCAPR;                         /**< FDB hash table capability register, offset: 0x2020 */
  __IO uint32_t FDBHTMCR;                          /**< FDB hash table memory configuration register, offset: 0x2024 */
  __I  uint32_t FDBHTOR0;                          /**< FDB hash table operational register 0, offset: 0x2028 */
  __I  uint32_t FDBHTOR1;                          /**< FDB hash table operational register 1, offset: 0x202C */
       uint8_t RESERVED_13[16];
  __I  uint32_t IPMFHTCAPR;                        /**< IP multicast filter hash table capability register, offset: 0x2040 */
  __I  uint32_t IPV4MFHTOR;                        /**< IPv4 multicast filter hash table operation register, offset: 0x2044 */
} NETC_SW_Type;

/* ----------------------------------------------------------------------------
   -- NETC_SW Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_SW_Register_Masks NETC_SW Register Masks
 * @{
 */

/*! @name SCAPR0 - Switch capability register 0 */
/*! @{ */

#define NETC_SW_SCAPR0_NUM_PORT_MASK             (0x1FU)
#define NETC_SW_SCAPR0_NUM_PORT_SHIFT            (0U)
#define NETC_SW_SCAPR0_NUM_PORT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR0_NUM_PORT_SHIFT)) & NETC_SW_SCAPR0_NUM_PORT_MASK)

#define NETC_SW_SCAPR0_NUM_IPV_MASK              (0x100U)
#define NETC_SW_SCAPR0_NUM_IPV_SHIFT             (8U)
#define NETC_SW_SCAPR0_NUM_IPV(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR0_NUM_IPV_SHIFT)) & NETC_SW_SCAPR0_NUM_IPV_MASK)

#define NETC_SW_SCAPR0_NUM_MSIX_MASK             (0xF0000U)
#define NETC_SW_SCAPR0_NUM_MSIX_SHIFT            (16U)
#define NETC_SW_SCAPR0_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR0_NUM_MSIX_SHIFT)) & NETC_SW_SCAPR0_NUM_MSIX_MASK)

#define NETC_SW_SCAPR0_NUM_PCPMP_MASK            (0xF00000U)
#define NETC_SW_SCAPR0_NUM_PCPMP_SHIFT           (20U)
#define NETC_SW_SCAPR0_NUM_PCPMP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR0_NUM_PCPMP_SHIFT)) & NETC_SW_SCAPR0_NUM_PCPMP_MASK)

#define NETC_SW_SCAPR0_NUM_QVMP_MASK             (0xF000000U)
#define NETC_SW_SCAPR0_NUM_QVMP_SHIFT            (24U)
#define NETC_SW_SCAPR0_NUM_QVMP(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR0_NUM_QVMP_SHIFT)) & NETC_SW_SCAPR0_NUM_QVMP_MASK)
/*! @} */

/*! @name SCAPR1 - Switch capability register 1 */
/*! @{ */

#define NETC_SW_SCAPR1_FS_MASK                   (0x1U)
#define NETC_SW_SCAPR1_FS_SHIFT                  (0U)
/*! FS - Functional safety capability supported. */
#define NETC_SW_SCAPR1_FS(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR1_FS_SHIFT)) & NETC_SW_SCAPR1_FS_MASK)

#define NETC_SW_SCAPR1_CTF_MASK                  (0x4U)
#define NETC_SW_SCAPR1_CTF_SHIFT                 (2U)
#define NETC_SW_SCAPR1_CTF(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR1_CTF_SHIFT)) & NETC_SW_SCAPR1_CTF_MASK)

#define NETC_SW_SCAPR1_TIMCAP_MASK               (0x8U)
#define NETC_SW_SCAPR1_TIMCAP_SHIFT              (3U)
#define NETC_SW_SCAPR1_TIMCAP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR1_TIMCAP_SHIFT)) & NETC_SW_SCAPR1_TIMCAP_MASK)

#define NETC_SW_SCAPR1_IMIR_MASK                 (0x10U)
#define NETC_SW_SCAPR1_IMIR_SHIFT                (4U)
#define NETC_SW_SCAPR1_IMIR(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR1_IMIR_SHIFT)) & NETC_SW_SCAPR1_IMIR_MASK)

#define NETC_SW_SCAPR1_SQ_TAGS_MASK              (0x1F0000U)
#define NETC_SW_SCAPR1_SQ_TAGS_SHIFT             (16U)
#define NETC_SW_SCAPR1_SQ_TAGS(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_SCAPR1_SQ_TAGS_SHIFT)) & NETC_SW_SCAPR1_SQ_TAGS_MASK)
/*! @} */

/*! @name BPCAPR - Buffer pool capability register */
/*! @{ */

#define NETC_SW_BPCAPR_NUM_BP_MASK               (0xFFU)
#define NETC_SW_BPCAPR_NUM_BP_SHIFT              (0U)
#define NETC_SW_BPCAPR_NUM_BP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_BPCAPR_NUM_BP_SHIFT)) & NETC_SW_BPCAPR_NUM_BP_MASK)

#define NETC_SW_BPCAPR_NUM_SPB_MASK              (0x1F0000U)
#define NETC_SW_BPCAPR_NUM_SPB_SHIFT             (16U)
#define NETC_SW_BPCAPR_NUM_SPB(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BPCAPR_NUM_SPB_SHIFT)) & NETC_SW_BPCAPR_NUM_SPB_MASK)
/*! @} */

/*! @name FCAPR - Forwarding capability register */
/*! @{ */

#define NETC_SW_FCAPR_BR_MASK                    (0x1U)
#define NETC_SW_FCAPR_BR_SHIFT                   (0U)
/*! BR - 802.1Q bridge forwarding support.
 *  0b0..Not supported
 *  0b1..Supported
 */
#define NETC_SW_FCAPR_BR(x)                      (((uint32_t)(((uint32_t)(x)) << NETC_SW_FCAPR_BR_SHIFT)) & NETC_SW_FCAPR_BR_MASK)

#define NETC_SW_FCAPR_SF_MASK                    (0x2U)
#define NETC_SW_FCAPR_SF_SHIFT                   (1U)
/*! SF - Stream forwarding supported
 *  0b0..Not supported
 *  0b1..Supported
 */
#define NETC_SW_FCAPR_SF(x)                      (((uint32_t)(((uint32_t)(x)) << NETC_SW_FCAPR_SF_SHIFT)) & NETC_SW_FCAPR_SF_MASK)
/*! @} */

/*! @name SMBCAPR - Shared memory buffer capability register */
/*! @{ */

#define NETC_SW_SMBCAPR_NUM_WORDS_MASK           (0xFFFFFFU)
#define NETC_SW_SMBCAPR_NUM_WORDS_SHIFT          (0U)
#define NETC_SW_SMBCAPR_NUM_WORDS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_SMBCAPR_NUM_WORDS_SHIFT)) & NETC_SW_SMBCAPR_NUM_WORDS_MASK)

#define NETC_SW_SMBCAPR_WORD_SIZE_MASK           (0x30000000U)
#define NETC_SW_SMBCAPR_WORD_SIZE_SHIFT          (28U)
/*! WORD_SIZE
 *  0b00..24 bytes
 *  0b01-0b11..
 */
#define NETC_SW_SMBCAPR_WORD_SIZE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_SMBCAPR_WORD_SIZE_SHIFT)) & NETC_SW_SMBCAPR_WORD_SIZE_MASK)

#define NETC_SW_SMBCAPR_MLOC_MASK                (0xC0000000U)
#define NETC_SW_SMBCAPR_MLOC_SHIFT               (30U)
/*! MLOC - Indicates memory location
 *  0b00..Common memory
 *  0b01-0b11..
 */
#define NETC_SW_SMBCAPR_MLOC(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_SW_SMBCAPR_MLOC_SHIFT)) & NETC_SW_SMBCAPR_MLOC_MASK)
/*! @} */

/*! @name SMBOR0 - Shared memory buffer operational register 0 */
/*! @{ */

#define NETC_SW_SMBOR0_COUNT_MASK                (0xFFFFFFU)
#define NETC_SW_SMBOR0_COUNT_SHIFT               (0U)
#define NETC_SW_SMBOR0_COUNT(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_SW_SMBOR0_COUNT_SHIFT)) & NETC_SW_SMBOR0_COUNT_MASK)
/*! @} */

/*! @name SMBOR1 - Shared memory buffer operational register 1 */
/*! @{ */

#define NETC_SW_SMBOR1_WATERMARK_MASK            (0xFFFFFFU)
#define NETC_SW_SMBOR1_WATERMARK_SHIFT           (0U)
#define NETC_SW_SMBOR1_WATERMARK(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_SMBOR1_WATERMARK_SHIFT)) & NETC_SW_SMBOR1_WATERMARK_MASK)
/*! @} */

/*! @name CCAR - Command cache attribute register */
/*! @{ */

#define NETC_SW_CCAR_CBD_WRCACHE_MASK            (0xFU)
#define NETC_SW_CCAR_CBD_WRCACHE_SHIFT           (0U)
#define NETC_SW_CCAR_CBD_WRCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_WRCACHE_SHIFT)) & NETC_SW_CCAR_CBD_WRCACHE_MASK)

#define NETC_SW_CCAR_CBD_WRDOMAIN_MASK           (0x30U)
#define NETC_SW_CCAR_CBD_WRDOMAIN_SHIFT          (4U)
#define NETC_SW_CCAR_CBD_WRDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_WRDOMAIN_SHIFT)) & NETC_SW_CCAR_CBD_WRDOMAIN_MASK)

#define NETC_SW_CCAR_CBD_WRSNP_MASK              (0x40U)
#define NETC_SW_CCAR_CBD_WRSNP_SHIFT             (6U)
#define NETC_SW_CCAR_CBD_WRSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_WRSNP_SHIFT)) & NETC_SW_CCAR_CBD_WRSNP_MASK)

#define NETC_SW_CCAR_CWRCACHE_MASK               (0xF00U)
#define NETC_SW_CCAR_CWRCACHE_SHIFT              (8U)
#define NETC_SW_CCAR_CWRCACHE(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CWRCACHE_SHIFT)) & NETC_SW_CCAR_CWRCACHE_MASK)

#define NETC_SW_CCAR_CWRDOMAIN_MASK              (0x3000U)
#define NETC_SW_CCAR_CWRDOMAIN_SHIFT             (12U)
#define NETC_SW_CCAR_CWRDOMAIN(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CWRDOMAIN_SHIFT)) & NETC_SW_CCAR_CWRDOMAIN_MASK)

#define NETC_SW_CCAR_CWRSNP_MASK                 (0x4000U)
#define NETC_SW_CCAR_CWRSNP_SHIFT                (14U)
#define NETC_SW_CCAR_CWRSNP(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CWRSNP_SHIFT)) & NETC_SW_CCAR_CWRSNP_MASK)

#define NETC_SW_CCAR_CBD_RDCACHE_MASK            (0xF0000U)
#define NETC_SW_CCAR_CBD_RDCACHE_SHIFT           (16U)
#define NETC_SW_CCAR_CBD_RDCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_RDCACHE_SHIFT)) & NETC_SW_CCAR_CBD_RDCACHE_MASK)

#define NETC_SW_CCAR_CBD_RDDOMAIN_MASK           (0x300000U)
#define NETC_SW_CCAR_CBD_RDDOMAIN_SHIFT          (20U)
#define NETC_SW_CCAR_CBD_RDDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_RDDOMAIN_SHIFT)) & NETC_SW_CCAR_CBD_RDDOMAIN_MASK)

#define NETC_SW_CCAR_CBD_RDSNP_MASK              (0x400000U)
#define NETC_SW_CCAR_CBD_RDSNP_SHIFT             (22U)
#define NETC_SW_CCAR_CBD_RDSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CBD_RDSNP_SHIFT)) & NETC_SW_CCAR_CBD_RDSNP_MASK)

#define NETC_SW_CCAR_CRDCACHE_MASK               (0xF000000U)
#define NETC_SW_CCAR_CRDCACHE_SHIFT              (24U)
#define NETC_SW_CCAR_CRDCACHE(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CRDCACHE_SHIFT)) & NETC_SW_CCAR_CRDCACHE_MASK)

#define NETC_SW_CCAR_CRDDOMAIN_MASK              (0x30000000U)
#define NETC_SW_CCAR_CRDDOMAIN_SHIFT             (28U)
#define NETC_SW_CCAR_CRDDOMAIN(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CRDDOMAIN_SHIFT)) & NETC_SW_CCAR_CRDDOMAIN_MASK)

#define NETC_SW_CCAR_CRDSNP_MASK                 (0x40000000U)
#define NETC_SW_CCAR_CRDSNP_SHIFT                (30U)
#define NETC_SW_CCAR_CRDSNP(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_CCAR_CRDSNP_SHIFT)) & NETC_SW_CCAR_CRDSNP_MASK)
/*! @} */

/*! @name MPCR - Management port configuration register */
/*! @{ */

#define NETC_SW_MPCR_PORT_MASK                   (0x1FU)
#define NETC_SW_MPCR_PORT_SHIFT                  (0U)
/*! PORT - Switch Management Port */
#define NETC_SW_MPCR_PORT(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_SW_MPCR_PORT_SHIFT)) & NETC_SW_MPCR_PORT_MASK)
/*! @} */

/*! @name IMDCR0 - Ingress mirror destination configuration register 0 */
/*! @{ */

#define NETC_SW_IMDCR0_MIREN_MASK                (0x1U)
#define NETC_SW_IMDCR0_MIREN_SHIFT               (0U)
/*! MIREN - Mirror enable.
 *  0b0..Ingress mirroring disabled
 *  0b1..Ingress mirroring enabled
 */
#define NETC_SW_IMDCR0_MIREN(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR0_MIREN_SHIFT)) & NETC_SW_IMDCR0_MIREN_MASK)

#define NETC_SW_IMDCR0_MIRDEST_MASK              (0x2U)
#define NETC_SW_IMDCR0_MIRDEST_SHIFT             (1U)
/*! MIRDEST - Indicates the mirror destination */
#define NETC_SW_IMDCR0_MIRDEST(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR0_MIRDEST_SHIFT)) & NETC_SW_IMDCR0_MIRDEST_MASK)

#define NETC_SW_IMDCR0_IPV_MASK                  (0x1CU)
#define NETC_SW_IMDCR0_IPV_SHIFT                 (2U)
#define NETC_SW_IMDCR0_IPV(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR0_IPV_SHIFT)) & NETC_SW_IMDCR0_IPV_MASK)

#define NETC_SW_IMDCR0_DR_MASK                   (0xC0U)
#define NETC_SW_IMDCR0_DR_SHIFT                  (6U)
#define NETC_SW_IMDCR0_DR(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR0_DR_SHIFT)) & NETC_SW_IMDCR0_DR_MASK)

#define NETC_SW_IMDCR0_PORT_MASK                 (0x1F00U)
#define NETC_SW_IMDCR0_PORT_SHIFT                (8U)
#define NETC_SW_IMDCR0_PORT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR0_PORT_SHIFT)) & NETC_SW_IMDCR0_PORT_MASK)
/*! @} */

/*! @name IMDCR1 - Ingress mirror destination configuration register 1 */
/*! @{ */

#define NETC_SW_IMDCR1_EFMEID_MASK               (0xFFFFU)
#define NETC_SW_IMDCR1_EFMEID_SHIFT              (0U)
#define NETC_SW_IMDCR1_EFMEID(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR1_EFMEID_SHIFT)) & NETC_SW_IMDCR1_EFMEID_MASK)

#define NETC_SW_IMDCR1_EFM_LEN_CHANGE_MASK       (0x7F0000U)
#define NETC_SW_IMDCR1_EFM_LEN_CHANGE_SHIFT      (16U)
#define NETC_SW_IMDCR1_EFM_LEN_CHANGE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_IMDCR1_EFM_LEN_CHANGE_SHIFT)) & NETC_SW_IMDCR1_EFM_LEN_CHANGE_MASK)
/*! @} */

/*! @name CTFCR - Cut-through forwarding count register */
/*! @{ */

#define NETC_SW_CTFCR_COUNT_MASK                 (0xFFFFFFFFU)
#define NETC_SW_CTFCR_COUNT_SHIFT                (0U)
#define NETC_SW_CTFCR_COUNT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_CTFCR_COUNT_SHIFT)) & NETC_SW_CTFCR_COUNT_MASK)
/*! @} */

/*! @name CBDRMR - Command BDR 0 mode register..Command BDR 1 mode register */
/*! @{ */

#define NETC_SW_CBDRMR_EN_MASK                   (0x80000000U)
#define NETC_SW_CBDRMR_EN_SHIFT                  (31U)
/*! EN - Enable command buffer descriptor ring
 *  0b0..Disabled
 *  0b1..Enabled. When the ring is non-empty, command buffer descriptors will be processed
 */
#define NETC_SW_CBDRMR_EN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRMR_EN_SHIFT)) & NETC_SW_CBDRMR_EN_MASK)
/*! @} */

/* The count of NETC_SW_CBDRMR */
#define NETC_SW_CBDRMR_COUNT                     (2U)

/*! @name CBDRSR - Command BDR 0 status register..Command BDR 1 status register */
/*! @{ */

#define NETC_SW_CBDRSR_BUSY_MASK                 (0x1U)
#define NETC_SW_CBDRSR_BUSY_SHIFT                (0U)
/*! BUSY - Busy.
 *  0b0..Idle
 *  0b1..Busy
 */
#define NETC_SW_CBDRSR_BUSY(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRSR_BUSY_SHIFT)) & NETC_SW_CBDRSR_BUSY_MASK)
/*! @} */

/* The count of NETC_SW_CBDRSR */
#define NETC_SW_CBDRSR_COUNT                     (2U)

/*! @name CBDRBAR0 - Command BDR base address register 0 */
/*! @{ */

#define NETC_SW_CBDRBAR0_ADDRL_MASK              (0xFFFFFF80U)
#define NETC_SW_CBDRBAR0_ADDRL_SHIFT             (7U)
#define NETC_SW_CBDRBAR0_ADDRL(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRBAR0_ADDRL_SHIFT)) & NETC_SW_CBDRBAR0_ADDRL_MASK)
/*! @} */

/* The count of NETC_SW_CBDRBAR0 */
#define NETC_SW_CBDRBAR0_COUNT                   (2U)

/*! @name CBDRBAR1 - Command BDR 0 base address register 1..Command BDR 1 base address register 1 */
/*! @{ */

#define NETC_SW_CBDRBAR1_ADDRH_MASK              (0xFFFFFFFFU)
#define NETC_SW_CBDRBAR1_ADDRH_SHIFT             (0U)
#define NETC_SW_CBDRBAR1_ADDRH(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRBAR1_ADDRH_SHIFT)) & NETC_SW_CBDRBAR1_ADDRH_MASK)
/*! @} */

/* The count of NETC_SW_CBDRBAR1 */
#define NETC_SW_CBDRBAR1_COUNT                   (2U)

/*! @name CBDRPIR - Command BDR 0 producer index register..Command BDR 1 producer index register */
/*! @{ */

#define NETC_SW_CBDRPIR_BDR_INDEX_MASK           (0x3FFU)
#define NETC_SW_CBDRPIR_BDR_INDEX_SHIFT          (0U)
#define NETC_SW_CBDRPIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRPIR_BDR_INDEX_SHIFT)) & NETC_SW_CBDRPIR_BDR_INDEX_MASK)
/*! @} */

/* The count of NETC_SW_CBDRPIR */
#define NETC_SW_CBDRPIR_COUNT                    (2U)

/*! @name CBDRCIR - Command BDR 0 consumer index register..Command BDR 1 consumer index register */
/*! @{ */

#define NETC_SW_CBDRCIR_BDR_INDEX_MASK           (0x3FFU)
#define NETC_SW_CBDRCIR_BDR_INDEX_SHIFT          (0U)
#define NETC_SW_CBDRCIR_BDR_INDEX(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRCIR_BDR_INDEX_SHIFT)) & NETC_SW_CBDRCIR_BDR_INDEX_MASK)
/*! @} */

/* The count of NETC_SW_CBDRCIR */
#define NETC_SW_CBDRCIR_COUNT                    (2U)

/*! @name CBDRLENR - Command BDR 0 length register..Command BDR 1 length register */
/*! @{ */

#define NETC_SW_CBDRLENR_LENGTH_MASK             (0x7F8U)
#define NETC_SW_CBDRLENR_LENGTH_SHIFT            (3U)
#define NETC_SW_CBDRLENR_LENGTH(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRLENR_LENGTH_SHIFT)) & NETC_SW_CBDRLENR_LENGTH_MASK)
/*! @} */

/* The count of NETC_SW_CBDRLENR */
#define NETC_SW_CBDRLENR_COUNT                   (2U)

/*! @name CBDRIER - Command BDR 0 interrupt enable register..Command BDR 1 interrupt enable register */
/*! @{ */

#define NETC_SW_CBDRIER_CBDCIE_MASK              (0x1U)
#define NETC_SW_CBDRIER_CBDCIE_SHIFT             (0U)
#define NETC_SW_CBDRIER_CBDCIE(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRIER_CBDCIE_SHIFT)) & NETC_SW_CBDRIER_CBDCIE_MASK)
/*! @} */

/* The count of NETC_SW_CBDRIER */
#define NETC_SW_CBDRIER_COUNT                    (2U)

/*! @name CBDRIDR - Command BDR 0 interrupt detect register..Command BDR 1 interrupt detect register */
/*! @{ */

#define NETC_SW_CBDRIDR_CBDC_MASK                (0x1U)
#define NETC_SW_CBDRIDR_CBDC_SHIFT               (0U)
/*! CBDC
 *  0b0..No BD with CI=1 completed
 *  0b1..Processed BD with CI=1
 */
#define NETC_SW_CBDRIDR_CBDC(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRIDR_CBDC_SHIFT)) & NETC_SW_CBDRIDR_CBDC_MASK)
/*! @} */

/* The count of NETC_SW_CBDRIDR */
#define NETC_SW_CBDRIDR_COUNT                    (2U)

/*! @name CBDRMSIVR - Command BDR 0 MSI-X vector register..Command BDR 1 MSI-X vector register */
/*! @{ */

#define NETC_SW_CBDRMSIVR_VECTOR_MASK            (0xFU)
#define NETC_SW_CBDRMSIVR_VECTOR_SHIFT           (0U)
#define NETC_SW_CBDRMSIVR_VECTOR(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_CBDRMSIVR_VECTOR_SHIFT)) & NETC_SW_CBDRMSIVR_VECTOR_MASK)
/*! @} */

/* The count of NETC_SW_CBDRMSIVR */
#define NETC_SW_CBDRMSIVR_COUNT                  (2U)

/*! @name QOSVLANMPR - QoS to VLAN mapping profile 0 register 0..QoS to VLAN mapping profile 1 register 3 */
/*! @{ */

#define NETC_SW_QOSVLANMPR_IPV0_DR0_MASK         (0xFU)
#define NETC_SW_QOSVLANMPR_IPV0_DR0_SHIFT        (0U)
#define NETC_SW_QOSVLANMPR_IPV0_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV0_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV0_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV2_DR0_MASK         (0xFU)
#define NETC_SW_QOSVLANMPR_IPV2_DR0_SHIFT        (0U)
#define NETC_SW_QOSVLANMPR_IPV2_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV2_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV2_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV4_DR0_MASK         (0xFU)
#define NETC_SW_QOSVLANMPR_IPV4_DR0_SHIFT        (0U)
#define NETC_SW_QOSVLANMPR_IPV4_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV4_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV4_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV6_DR0_MASK         (0xFU)
#define NETC_SW_QOSVLANMPR_IPV6_DR0_SHIFT        (0U)
#define NETC_SW_QOSVLANMPR_IPV6_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV6_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV6_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV0_DR1_MASK         (0xF0U)
#define NETC_SW_QOSVLANMPR_IPV0_DR1_SHIFT        (4U)
#define NETC_SW_QOSVLANMPR_IPV0_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV0_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV0_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV2_DR1_MASK         (0xF0U)
#define NETC_SW_QOSVLANMPR_IPV2_DR1_SHIFT        (4U)
#define NETC_SW_QOSVLANMPR_IPV2_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV2_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV2_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV4_DR1_MASK         (0xF0U)
#define NETC_SW_QOSVLANMPR_IPV4_DR1_SHIFT        (4U)
#define NETC_SW_QOSVLANMPR_IPV4_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV4_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV4_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV6_DR1_MASK         (0xF0U)
#define NETC_SW_QOSVLANMPR_IPV6_DR1_SHIFT        (4U)
#define NETC_SW_QOSVLANMPR_IPV6_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV6_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV6_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV0_DR2_MASK         (0xF00U)
#define NETC_SW_QOSVLANMPR_IPV0_DR2_SHIFT        (8U)
#define NETC_SW_QOSVLANMPR_IPV0_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV0_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV0_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV2_DR2_MASK         (0xF00U)
#define NETC_SW_QOSVLANMPR_IPV2_DR2_SHIFT        (8U)
#define NETC_SW_QOSVLANMPR_IPV2_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV2_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV2_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV4_DR2_MASK         (0xF00U)
#define NETC_SW_QOSVLANMPR_IPV4_DR2_SHIFT        (8U)
#define NETC_SW_QOSVLANMPR_IPV4_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV4_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV4_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV6_DR2_MASK         (0xF00U)
#define NETC_SW_QOSVLANMPR_IPV6_DR2_SHIFT        (8U)
#define NETC_SW_QOSVLANMPR_IPV6_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV6_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV6_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV0_DR3_MASK         (0xF000U)
#define NETC_SW_QOSVLANMPR_IPV0_DR3_SHIFT        (12U)
#define NETC_SW_QOSVLANMPR_IPV0_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV0_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV0_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV2_DR3_MASK         (0xF000U)
#define NETC_SW_QOSVLANMPR_IPV2_DR3_SHIFT        (12U)
#define NETC_SW_QOSVLANMPR_IPV2_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV2_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV2_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV4_DR3_MASK         (0xF000U)
#define NETC_SW_QOSVLANMPR_IPV4_DR3_SHIFT        (12U)
#define NETC_SW_QOSVLANMPR_IPV4_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV4_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV4_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV6_DR3_MASK         (0xF000U)
#define NETC_SW_QOSVLANMPR_IPV6_DR3_SHIFT        (12U)
#define NETC_SW_QOSVLANMPR_IPV6_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV6_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV6_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV1_DR0_MASK         (0xF0000U)
#define NETC_SW_QOSVLANMPR_IPV1_DR0_SHIFT        (16U)
#define NETC_SW_QOSVLANMPR_IPV1_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV1_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV1_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV3_DR0_MASK         (0xF0000U)
#define NETC_SW_QOSVLANMPR_IPV3_DR0_SHIFT        (16U)
#define NETC_SW_QOSVLANMPR_IPV3_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV3_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV3_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV5_DR0_MASK         (0xF0000U)
#define NETC_SW_QOSVLANMPR_IPV5_DR0_SHIFT        (16U)
#define NETC_SW_QOSVLANMPR_IPV5_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV5_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV5_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV7_DR0_MASK         (0xF0000U)
#define NETC_SW_QOSVLANMPR_IPV7_DR0_SHIFT        (16U)
#define NETC_SW_QOSVLANMPR_IPV7_DR0(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV7_DR0_SHIFT)) & NETC_SW_QOSVLANMPR_IPV7_DR0_MASK)

#define NETC_SW_QOSVLANMPR_IPV1_DR1_MASK         (0xF00000U)
#define NETC_SW_QOSVLANMPR_IPV1_DR1_SHIFT        (20U)
#define NETC_SW_QOSVLANMPR_IPV1_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV1_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV1_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV3_DR1_MASK         (0xF00000U)
#define NETC_SW_QOSVLANMPR_IPV3_DR1_SHIFT        (20U)
#define NETC_SW_QOSVLANMPR_IPV3_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV3_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV3_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV5_DR1_MASK         (0xF00000U)
#define NETC_SW_QOSVLANMPR_IPV5_DR1_SHIFT        (20U)
#define NETC_SW_QOSVLANMPR_IPV5_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV5_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV5_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV7_DR1_MASK         (0xF00000U)
#define NETC_SW_QOSVLANMPR_IPV7_DR1_SHIFT        (20U)
#define NETC_SW_QOSVLANMPR_IPV7_DR1(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV7_DR1_SHIFT)) & NETC_SW_QOSVLANMPR_IPV7_DR1_MASK)

#define NETC_SW_QOSVLANMPR_IPV1_DR2_MASK         (0xF000000U)
#define NETC_SW_QOSVLANMPR_IPV1_DR2_SHIFT        (24U)
#define NETC_SW_QOSVLANMPR_IPV1_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV1_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV1_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV3_DR2_MASK         (0xF000000U)
#define NETC_SW_QOSVLANMPR_IPV3_DR2_SHIFT        (24U)
#define NETC_SW_QOSVLANMPR_IPV3_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV3_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV3_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV5_DR2_MASK         (0xF000000U)
#define NETC_SW_QOSVLANMPR_IPV5_DR2_SHIFT        (24U)
#define NETC_SW_QOSVLANMPR_IPV5_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV5_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV5_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV7_DR2_MASK         (0xF000000U)
#define NETC_SW_QOSVLANMPR_IPV7_DR2_SHIFT        (24U)
#define NETC_SW_QOSVLANMPR_IPV7_DR2(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV7_DR2_SHIFT)) & NETC_SW_QOSVLANMPR_IPV7_DR2_MASK)

#define NETC_SW_QOSVLANMPR_IPV1_DR3_MASK         (0xF0000000U)
#define NETC_SW_QOSVLANMPR_IPV1_DR3_SHIFT        (28U)
#define NETC_SW_QOSVLANMPR_IPV1_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV1_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV1_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV3_DR3_MASK         (0xF0000000U)
#define NETC_SW_QOSVLANMPR_IPV3_DR3_SHIFT        (28U)
#define NETC_SW_QOSVLANMPR_IPV3_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV3_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV3_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV5_DR3_MASK         (0xF0000000U)
#define NETC_SW_QOSVLANMPR_IPV5_DR3_SHIFT        (28U)
#define NETC_SW_QOSVLANMPR_IPV5_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV5_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV5_DR3_MASK)

#define NETC_SW_QOSVLANMPR_IPV7_DR3_MASK         (0xF0000000U)
#define NETC_SW_QOSVLANMPR_IPV7_DR3_SHIFT        (28U)
#define NETC_SW_QOSVLANMPR_IPV7_DR3(x)           (((uint32_t)(((uint32_t)(x)) << NETC_SW_QOSVLANMPR_IPV7_DR3_SHIFT)) & NETC_SW_QOSVLANMPR_IPV7_DR3_MASK)
/*! @} */

/* The count of NETC_SW_QOSVLANMPR */
#define NETC_SW_QOSVLANMPR_COUNT                 (2U)

/* The count of NETC_SW_QOSVLANMPR */
#define NETC_SW_QOSVLANMPR_COUNT2                (4U)

/*! @name PCP2PCPMPR - PCP to PCP mapping profile 0 register..PCP to PCP mapping profile 1 register */
/*! @{ */

#define NETC_SW_PCP2PCPMPR_PCP0_MASK             (0x7U)
#define NETC_SW_PCP2PCPMPR_PCP0_SHIFT            (0U)
#define NETC_SW_PCP2PCPMPR_PCP0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP0_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP0_MASK)

#define NETC_SW_PCP2PCPMPR_PCP1_MASK             (0x70U)
#define NETC_SW_PCP2PCPMPR_PCP1_SHIFT            (4U)
#define NETC_SW_PCP2PCPMPR_PCP1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP1_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP1_MASK)

#define NETC_SW_PCP2PCPMPR_PCP2_MASK             (0x700U)
#define NETC_SW_PCP2PCPMPR_PCP2_SHIFT            (8U)
#define NETC_SW_PCP2PCPMPR_PCP2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP2_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP2_MASK)

#define NETC_SW_PCP2PCPMPR_PCP3_MASK             (0x7000U)
#define NETC_SW_PCP2PCPMPR_PCP3_SHIFT            (12U)
#define NETC_SW_PCP2PCPMPR_PCP3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP3_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP3_MASK)

#define NETC_SW_PCP2PCPMPR_PCP4_MASK             (0x70000U)
#define NETC_SW_PCP2PCPMPR_PCP4_SHIFT            (16U)
#define NETC_SW_PCP2PCPMPR_PCP4(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP4_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP4_MASK)

#define NETC_SW_PCP2PCPMPR_PCP5_MASK             (0x700000U)
#define NETC_SW_PCP2PCPMPR_PCP5_SHIFT            (20U)
#define NETC_SW_PCP2PCPMPR_PCP5(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP5_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP5_MASK)

#define NETC_SW_PCP2PCPMPR_PCP6_MASK             (0x7000000U)
#define NETC_SW_PCP2PCPMPR_PCP6_SHIFT            (24U)
#define NETC_SW_PCP2PCPMPR_PCP6(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP6_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP6_MASK)

#define NETC_SW_PCP2PCPMPR_PCP7_MASK             (0x70000000U)
#define NETC_SW_PCP2PCPMPR_PCP7_SHIFT            (28U)
#define NETC_SW_PCP2PCPMPR_PCP7(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_PCP2PCPMPR_PCP7_SHIFT)) & NETC_SW_PCP2PCPMPR_PCP7_MASK)
/*! @} */

/* The count of NETC_SW_PCP2PCPMPR */
#define NETC_SW_PCP2PCPMPR_COUNT                 (2U)

/*! @name BRCAPR - Bridge capability register */
/*! @{ */

#define NETC_SW_BRCAPR_IPV4MFLT_MASK             (0x1U)
#define NETC_SW_BRCAPR_IPV4MFLT_SHIFT            (0U)
/*! IPV4MFLT - L2 IPv4 multicast filtering supported.
 *  0b0..Not supported
 *  0b1..Supported
 */
#define NETC_SW_BRCAPR_IPV4MFLT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_IPV4MFLT_SHIFT)) & NETC_SW_BRCAPR_IPV4MFLT_MASK)

#define NETC_SW_BRCAPR_STAMVD_MASK               (0x4U)
#define NETC_SW_BRCAPR_STAMVD_SHIFT              (2U)
/*! STAMVD - Station Move Disable supported
 *  0b0..Not supported
 *  0b1..Supported
 */
#define NETC_SW_BRCAPR_STAMVD(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_STAMVD_SHIFT)) & NETC_SW_BRCAPR_STAMVD_MASK)

#define NETC_SW_BRCAPR_STRMCTRL_MASK             (0x8U)
#define NETC_SW_BRCAPR_STRMCTRL_SHIFT            (3U)
/*! STRMCTRL - Storm Control supported.
 *  0b0..Not supported
 *  0b1..Supported
 */
#define NETC_SW_BRCAPR_STRMCTRL(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_STRMCTRL_SHIFT)) & NETC_SW_BRCAPR_STRMCTRL_MASK)

#define NETC_SW_BRCAPR_SRCPPRND_MASK             (0x10U)
#define NETC_SW_BRCAPR_SRCPPRND_SHIFT            (4U)
/*! SRCPPRND - Source port pruning disable supported
 *  0b0..Source port pruning disable not supported
 *  0b1..Source port pruning disable supported
 */
#define NETC_SW_BRCAPR_SRCPPRND(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_SRCPPRND_SHIFT)) & NETC_SW_BRCAPR_SRCPPRND_MASK)

#define NETC_SW_BRCAPR_EVLANXLATE_MASK           (0x20U)
#define NETC_SW_BRCAPR_EVLANXLATE_SHIFT          (5U)
/*! EVLANXLATE - Egress VLAN translation supported
 *  0b0..Egress VLAN translation not supported
 *  0b1..Egress VLAN translation supported
 */
#define NETC_SW_BRCAPR_EVLANXLATE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_EVLANXLATE_SHIFT)) & NETC_SW_BRCAPR_EVLANXLATE_MASK)

#define NETC_SW_BRCAPR_NUM_STG_MASK              (0x3000U)
#define NETC_SW_BRCAPR_NUM_STG_SHIFT             (12U)
#define NETC_SW_BRCAPR_NUM_STG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_SW_BRCAPR_NUM_STG_SHIFT)) & NETC_SW_BRCAPR_NUM_STG_MASK)
/*! @} */

/*! @name VFHTCAPR - VLAN filter hash table capability register */
/*! @{ */

#define NETC_SW_VFHTCAPR_ACCESS_METH_MASK        (0xF00000U)
#define NETC_SW_VFHTCAPR_ACCESS_METH_SHIFT       (20U)
#define NETC_SW_VFHTCAPR_ACCESS_METH(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTCAPR_ACCESS_METH_SHIFT)) & NETC_SW_VFHTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name VFHTOR - VLAN filter hash table operational register */
/*! @{ */

#define NETC_SW_VFHTOR_NUM_ENTRIES_MASK          (0xFFFU)
#define NETC_SW_VFHTOR_NUM_ENTRIES_SHIFT         (0U)
#define NETC_SW_VFHTOR_NUM_ENTRIES(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTOR_NUM_ENTRIES_SHIFT)) & NETC_SW_VFHTOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name VFHTDECR0 - VLAN Filter (hash) table default entry configuration registers 0 */
/*! @{ */

#define NETC_SW_VFHTDECR0_PORT0_MASK             (0x1U)
#define NETC_SW_VFHTDECR0_PORT0_SHIFT            (0U)
/*! PORT0 - Port n
 *  0b0..Port is not a member of this VLAN.
 *  0b1..Port is a member of this VLAN.
 */
#define NETC_SW_VFHTDECR0_PORT0(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_PORT0_SHIFT)) & NETC_SW_VFHTDECR0_PORT0_MASK)

#define NETC_SW_VFHTDECR0_PORT1_MASK             (0x2U)
#define NETC_SW_VFHTDECR0_PORT1_SHIFT            (1U)
/*! PORT1 - Port n
 *  0b0..Port is not a member of this VLAN.
 *  0b1..Port is a member of this VLAN.
 */
#define NETC_SW_VFHTDECR0_PORT1(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_PORT1_SHIFT)) & NETC_SW_VFHTDECR0_PORT1_MASK)

#define NETC_SW_VFHTDECR0_PORT2_MASK             (0x4U)
#define NETC_SW_VFHTDECR0_PORT2_SHIFT            (2U)
/*! PORT2 - Port n
 *  0b0..Port is not a member of this VLAN.
 *  0b1..Port is a member of this VLAN.
 */
#define NETC_SW_VFHTDECR0_PORT2(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_PORT2_SHIFT)) & NETC_SW_VFHTDECR0_PORT2_MASK)

#define NETC_SW_VFHTDECR0_PORT3_MASK             (0x8U)
#define NETC_SW_VFHTDECR0_PORT3_SHIFT            (3U)
/*! PORT3 - Port n
 *  0b0..Port is not a member of this VLAN.
 *  0b1..Port is a member of this VLAN.
 */
#define NETC_SW_VFHTDECR0_PORT3(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_PORT3_SHIFT)) & NETC_SW_VFHTDECR0_PORT3_MASK)

#define NETC_SW_VFHTDECR0_PORT4_MASK             (0x10U)
#define NETC_SW_VFHTDECR0_PORT4_SHIFT            (4U)
/*! PORT4 - Port n
 *  0b0..Port is not a member of this VLAN.
 *  0b1..Port is a member of this VLAN.
 */
#define NETC_SW_VFHTDECR0_PORT4(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_PORT4_SHIFT)) & NETC_SW_VFHTDECR0_PORT4_MASK)

#define NETC_SW_VFHTDECR0_STG_ID_MASK            (0xF000000U)
#define NETC_SW_VFHTDECR0_STG_ID_SHIFT           (24U)
#define NETC_SW_VFHTDECR0_STG_ID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_STG_ID_SHIFT)) & NETC_SW_VFHTDECR0_STG_ID_MASK)

#define NETC_SW_VFHTDECR0_IPMFE_MASK             (0x20000000U)
#define NETC_SW_VFHTDECR0_IPMFE_SHIFT            (29U)
/*! IPMFE - IP Multicast Filtering Enable
 *  0b0..No IP multicast filtering is performed.
 *  0b1..If the frame is identified as a multicast IP packet, then IP multicast filtering is performed. If the
 *       frame is not identified as an IP multicast packet, the IP multicast filtering is not performed.
 */
#define NETC_SW_VFHTDECR0_IPMFE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_IPMFE_SHIFT)) & NETC_SW_VFHTDECR0_IPMFE_MASK)

#define NETC_SW_VFHTDECR0_IPMFLE_MASK            (0x40000000U)
#define NETC_SW_VFHTDECR0_IPMFLE_SHIFT           (30U)
/*! IPMFLE - IP Multicast Flooding Enable
 *  0b0..IP Multicast Flooding disabled, the frame is discarded.
 *  0b1..IP Multicast Flooding enabled, the frame is flooded.
 */
#define NETC_SW_VFHTDECR0_IPMFLE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR0_IPMFLE_SHIFT)) & NETC_SW_VFHTDECR0_IPMFLE_MASK)
/*! @} */

/*! @name VFHTDECR1 - VLAN filter hash table default entry configuration registers 1 */
/*! @{ */

#define NETC_SW_VFHTDECR1_FID_MASK               (0xFFFU)
#define NETC_SW_VFHTDECR1_FID_SHIFT              (0U)
#define NETC_SW_VFHTDECR1_FID(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR1_FID_SHIFT)) & NETC_SW_VFHTDECR1_FID_MASK)

#define NETC_SW_VFHTDECR1_VL_MODE_MASK           (0x1000U)
#define NETC_SW_VFHTDECR1_VL_MODE_SHIFT          (12U)
#define NETC_SW_VFHTDECR1_VL_MODE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR1_VL_MODE_SHIFT)) & NETC_SW_VFHTDECR1_VL_MODE_MASK)

#define NETC_SW_VFHTDECR1_BASE_ETEID_MASK        (0xFFFF0000U)
#define NETC_SW_VFHTDECR1_BASE_ETEID_SHIFT       (16U)
#define NETC_SW_VFHTDECR1_BASE_ETEID(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR1_BASE_ETEID_SHIFT)) & NETC_SW_VFHTDECR1_BASE_ETEID_MASK)
/*! @} */

/*! @name VFHTDECR2 - VLAN filter hash table default entry configuration registers 2 */
/*! @{ */

#define NETC_SW_VFHTDECR2_ET_PORT0_MASK          (0x1U)
#define NETC_SW_VFHTDECR2_ET_PORT0_SHIFT         (0U)
/*! ET_PORT0 - Egress Treatment Applicability Port n.
 *  0b0..Port has no entry in the Egress Treatment table
 *  0b1..Port has an entry in the Egress Treatment table
 */
#define NETC_SW_VFHTDECR2_ET_PORT0(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_ET_PORT0_SHIFT)) & NETC_SW_VFHTDECR2_ET_PORT0_MASK)

#define NETC_SW_VFHTDECR2_ET_PORT1_MASK          (0x2U)
#define NETC_SW_VFHTDECR2_ET_PORT1_SHIFT         (1U)
/*! ET_PORT1 - Egress Treatment Applicability Port n.
 *  0b0..Port has no entry in the Egress Treatment table
 *  0b1..Port has an entry in the Egress Treatment table
 */
#define NETC_SW_VFHTDECR2_ET_PORT1(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_ET_PORT1_SHIFT)) & NETC_SW_VFHTDECR2_ET_PORT1_MASK)

#define NETC_SW_VFHTDECR2_ET_PORT2_MASK          (0x4U)
#define NETC_SW_VFHTDECR2_ET_PORT2_SHIFT         (2U)
/*! ET_PORT2 - Egress Treatment Applicability Port n.
 *  0b0..Port has no entry in the Egress Treatment table
 *  0b1..Port has an entry in the Egress Treatment table
 */
#define NETC_SW_VFHTDECR2_ET_PORT2(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_ET_PORT2_SHIFT)) & NETC_SW_VFHTDECR2_ET_PORT2_MASK)

#define NETC_SW_VFHTDECR2_ET_PORT3_MASK          (0x8U)
#define NETC_SW_VFHTDECR2_ET_PORT3_SHIFT         (3U)
/*! ET_PORT3 - Egress Treatment Applicability Port n.
 *  0b0..Port has no entry in the Egress Treatment table
 *  0b1..Port has an entry in the Egress Treatment table
 */
#define NETC_SW_VFHTDECR2_ET_PORT3(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_ET_PORT3_SHIFT)) & NETC_SW_VFHTDECR2_ET_PORT3_MASK)

#define NETC_SW_VFHTDECR2_ET_PORT4_MASK          (0x10U)
#define NETC_SW_VFHTDECR2_ET_PORT4_SHIFT         (4U)
/*! ET_PORT4 - Egress Treatment Applicability Port n.
 *  0b0..Port has no entry in the Egress Treatment table
 *  0b1..Port has an entry in the Egress Treatment table
 */
#define NETC_SW_VFHTDECR2_ET_PORT4(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_ET_PORT4_SHIFT)) & NETC_SW_VFHTDECR2_ET_PORT4_MASK)

#define NETC_SW_VFHTDECR2_MLO_MASK               (0x7000000U)
#define NETC_SW_VFHTDECR2_MLO_SHIFT              (24U)
#define NETC_SW_VFHTDECR2_MLO(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_MLO_SHIFT)) & NETC_SW_VFHTDECR2_MLO_MASK)

#define NETC_SW_VFHTDECR2_MFO_MASK               (0x18000000U)
#define NETC_SW_VFHTDECR2_MFO_SHIFT              (27U)
#define NETC_SW_VFHTDECR2_MFO(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_SW_VFHTDECR2_MFO_SHIFT)) & NETC_SW_VFHTDECR2_MFO_MASK)
/*! @} */

/*! @name FDBHTCAPR - FDB hash table capability register */
/*! @{ */

#define NETC_SW_FDBHTCAPR_NUM_GMAC_MASK          (0x1FFU)
#define NETC_SW_FDBHTCAPR_NUM_GMAC_SHIFT         (0U)
#define NETC_SW_FDBHTCAPR_NUM_GMAC(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTCAPR_NUM_GMAC_SHIFT)) & NETC_SW_FDBHTCAPR_NUM_GMAC_MASK)

#define NETC_SW_FDBHTCAPR_ACCESS_METH_MASK       (0xF00000U)
#define NETC_SW_FDBHTCAPR_ACCESS_METH_SHIFT      (20U)
#define NETC_SW_FDBHTCAPR_ACCESS_METH(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTCAPR_ACCESS_METH_SHIFT)) & NETC_SW_FDBHTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name FDBHTMCR - FDB hash table memory configuration register */
/*! @{ */

#define NETC_SW_FDBHTMCR_DYN_LIMIT_MASK          (0xFFFFU)
#define NETC_SW_FDBHTMCR_DYN_LIMIT_SHIFT         (0U)
#define NETC_SW_FDBHTMCR_DYN_LIMIT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTMCR_DYN_LIMIT_SHIFT)) & NETC_SW_FDBHTMCR_DYN_LIMIT_MASK)
/*! @} */

/*! @name FDBHTOR0 - FDB hash table operational register 0 */
/*! @{ */

#define NETC_SW_FDBHTOR0_STATIC_ENTRIES_MASK     (0xFFFFU)
#define NETC_SW_FDBHTOR0_STATIC_ENTRIES_SHIFT    (0U)
#define NETC_SW_FDBHTOR0_STATIC_ENTRIES(x)       (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTOR0_STATIC_ENTRIES_SHIFT)) & NETC_SW_FDBHTOR0_STATIC_ENTRIES_MASK)

#define NETC_SW_FDBHTOR0_NUM_GENTRIES_MASK       (0x1FF0000U)
#define NETC_SW_FDBHTOR0_NUM_GENTRIES_SHIFT      (16U)
#define NETC_SW_FDBHTOR0_NUM_GENTRIES(x)         (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTOR0_NUM_GENTRIES_SHIFT)) & NETC_SW_FDBHTOR0_NUM_GENTRIES_MASK)
/*! @} */

/*! @name FDBHTOR1 - FDB hash table operational register 1 */
/*! @{ */

#define NETC_SW_FDBHTOR1_DYN_ENTRIES_MASK        (0xFFFFU)
#define NETC_SW_FDBHTOR1_DYN_ENTRIES_SHIFT       (0U)
#define NETC_SW_FDBHTOR1_DYN_ENTRIES(x)          (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTOR1_DYN_ENTRIES_SHIFT)) & NETC_SW_FDBHTOR1_DYN_ENTRIES_MASK)

#define NETC_SW_FDBHTOR1_HWM_DYN_ENTRIES_MASK    (0xFFFF0000U)
#define NETC_SW_FDBHTOR1_HWM_DYN_ENTRIES_SHIFT   (16U)
#define NETC_SW_FDBHTOR1_HWM_DYN_ENTRIES(x)      (((uint32_t)(((uint32_t)(x)) << NETC_SW_FDBHTOR1_HWM_DYN_ENTRIES_SHIFT)) & NETC_SW_FDBHTOR1_HWM_DYN_ENTRIES_MASK)
/*! @} */

/*! @name IPMFHTCAPR - IP multicast filter hash table capability register */
/*! @{ */

#define NETC_SW_IPMFHTCAPR_ACCESS_METH_MASK      (0xF00000U)
#define NETC_SW_IPMFHTCAPR_ACCESS_METH_SHIFT     (20U)
#define NETC_SW_IPMFHTCAPR_ACCESS_METH(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_IPMFHTCAPR_ACCESS_METH_SHIFT)) & NETC_SW_IPMFHTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name IPV4MFHTOR - IPv4 multicast filter hash table operation register */
/*! @{ */

#define NETC_SW_IPV4MFHTOR_ASM_ENTRIES_MASK      (0xFFFFU)
#define NETC_SW_IPV4MFHTOR_ASM_ENTRIES_SHIFT     (0U)
#define NETC_SW_IPV4MFHTOR_ASM_ENTRIES(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_IPV4MFHTOR_ASM_ENTRIES_SHIFT)) & NETC_SW_IPV4MFHTOR_ASM_ENTRIES_MASK)

#define NETC_SW_IPV4MFHTOR_SSM_ENTRIES_MASK      (0xFFFF0000U)
#define NETC_SW_IPV4MFHTOR_SSM_ENTRIES_SHIFT     (16U)
#define NETC_SW_IPV4MFHTOR_SSM_ENTRIES(x)        (((uint32_t)(((uint32_t)(x)) << NETC_SW_IPV4MFHTOR_SSM_ENTRIES_SHIFT)) & NETC_SW_IPV4MFHTOR_SSM_ENTRIES_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group NETC_SW_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_SW_Peripheral_Access_Layer */


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


#endif  /* PERI_NETC_SW_H_ */

