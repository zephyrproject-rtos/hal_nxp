/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_NETC_F2_COMMON.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_NETC_F2_COMMON
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32Z2_NETC_F2_COMMON_H_)  /* Check if memory map has not been already included */
#define S32Z2_NETC_F2_COMMON_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_F2_COMMON Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F2_COMMON_Peripheral_Access_Layer NETC_F2_COMMON Peripheral Access Layer
 * @{
 */

/** NETC_F2_COMMON - Size of Registers Arrays */
#define NETC_F2_COMMON_NUM_PROFILE_COUNT          2u

/** NETC_F2_COMMON - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[4096];
  __I  uint32_t IPCAPR;                            /**< Ingress port capability register, offset: 0x1000 */
  __I  uint32_t EPCAPR;                            /**< Egress port capability register, offset: 0x1004 */
  uint8_t RESERVED_1[8];
  __I  uint32_t OSR;                               /**< Operational state register, offset: 0x1010 */
  uint8_t RESERVED_2[44];
  __IO uint32_t CMECR;                             /**< Correctable memory error configuration register, offset: 0x1040 */
  __IO uint32_t CMESR;                             /**< Correctable memory error status register, offset: 0x1044 */
  uint8_t RESERVED_3[4];
  __I  uint32_t CMECTR;                            /**< Correctable memory error count register, offset: 0x104C */
  uint8_t RESERVED_4[16];
  __IO uint32_t UNMACECR;                          /**< Uncorrectable non-fatal MAC error configuration register, offset: 0x1060 */
  __I  uint32_t UNMACESR;                          /**< Uncorrectable non-fatal MAC error status register, offset: 0x1064 */
  uint8_t RESERVED_5[8];
  __IO uint32_t UNSBECR;                           /**< Uncorrectable non-fatal system bus error configuration register, offset: 0x1070 */
  __IO uint32_t UNSBESR;                           /**< Uncorrectable non-fatal system bus error status register, offset: 0x1074 */
  uint8_t RESERVED_6[4];
  __I  uint32_t UNSBECTR;                          /**< Uncorrectable non-fatal system bus error count register, offset: 0x107C */
  __IO uint32_t UFSBECR;                           /**< Uncorrectable fatal system bus error configuration register, offset: 0x1080 */
  __IO uint32_t UFSBESR;                           /**< Uncorrectable fatal system bus error status register, offset: 0x1084 */
  uint8_t RESERVED_7[8];
  __IO uint32_t UNMECR;                            /**< Uncorrectable non-fatal memory error configuration register, offset: 0x1090 */
  __IO uint32_t UNMESR0;                           /**< Uncorrectable non-fatal memory error status register 0, offset: 0x1094 */
  __I  uint32_t UNMESR1;                           /**< Uncorrectable non-fatal memory error status register 1, offset: 0x1098 */
  __I  uint32_t UNMECTR;                           /**< Uncorrectable non-fatal memory error count register, offset: 0x109C */
  __IO uint32_t UFMECR;                            /**< Uncorrectable fatal memory error configuration register, offset: 0x10A0 */
  __IO uint32_t UFMESR0;                           /**< Uncorrectable fatal memory error status register 0, offset: 0x10A4 */
  __I  uint32_t UFMESR1;                           /**< Uncorrectable fatal memory error status register 1, offset: 0x10A8 */
  uint8_t RESERVED_8[4];
  __IO uint32_t UNIECR;                            /**< Uncorrectable non-fatal integrity error configuration register, offset: 0x10B0 */
  __IO uint32_t UNIESR;                            /**< Uncorrectable non-fatal integrity error status register, offset: 0x10B4 */
  uint8_t RESERVED_9[4];
  __I  uint32_t UNIECTR;                           /**< Uncorrectable non-fatal integrity error count register, offset: 0x10BC */
  __IO uint32_t UFIECR;                            /**< Uncorrectable fatal integrity error configuration register, offset: 0x10C0 */
  __IO uint32_t UFIESR;                            /**< Uncorrectable fatal integrity error status register, offset: 0x10C4 */
  uint8_t RESERVED_10[32];
  __I  uint32_t EMDIOIRR;                          /**< External MDIO interrupt reason register, offset: 0x10E8 */
  __IO uint32_t EMDIOMSIVR;                        /**< External MDIO MSI-X vector register, offset: 0x10EC */
  uint8_t RESERVED_11[16];
  __IO uint32_t TCCR;                              /**< Time capture configuration register, offset: 0x1100 */
  __IO uint32_t TCIER;                             /**< Time capture interrupt enable register, offset: 0x1104 */
  __IO uint32_t TCRPIDR;                           /**< Time capture receive port interrupt detect register, offset: 0x1108 */
  __I  uint32_t TCRPSR;                            /**< Time capture receive port status register, offset: 0x110C */
  uint8_t RESERVED_12[4];
  __I  uint32_t TCRPTSR;                           /**< Time capture receive port timestamp register, offset: 0x1114 */
  __IO uint32_t TCMSIVR;                           /**< Time capture MSI-X vector register, offset: 0x1118 */
  uint8_t RESERVED_13[228];
  __IO uint32_t CVLANR1;                           /**< Custom VLAN EtherType register 1, offset: 0x1200 */
  __IO uint32_t CVLANR2;                           /**< Custom VLAN EtherType register 2, offset: 0x1204 */
  __IO uint32_t PSRTAGETR;                         /**< Pre-Standard RTAG EtherType register, offset: 0x1208 */
  uint8_t RESERVED_14[20];
  __IO uint32_t DOSL2CR;                           /**< DoS L2 configuration register, offset: 0x1220 */
  uint8_t RESERVED_15[220];
  struct NETC_F2_COMMON_NUM_PROFILE {              /* offset: 0x1300, array step: 0x10 */
    __IO uint32_t VLANIPVMPR0;                       /**< VLAN to IPV mapping profile 0 register 0..VLAN to IPV mapping profile 1 register 0, array offset: 0x1300, array step: 0x10 */
    __IO uint32_t VLANIPVMPR1;                       /**< VLAN to IPV mapping profile 0 register 1..VLAN to IPV mapping profile 1 register 1, array offset: 0x1304, array step: 0x10 */
    __IO uint32_t VLANDRMPR;                         /**< VLAN to DR mapping profile 0 register..VLAN to DR mapping profile 1 register, array offset: 0x1308, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } NUM_PROFILE[NETC_F2_COMMON_NUM_PROFILE_COUNT];
  uint8_t RESERVED_16[800];
  __I  uint32_t IPFCAPR;                           /**< Ingress port filter capability register, offset: 0x1640 */
  __I  uint32_t IPFTCAPR;                          /**< Ingress port filter table capability register, offset: 0x1644 */
  __I  uint32_t IPFTMOR;                           /**< Ingress port filter table memory operational register, offset: 0x1648 */
  uint8_t RESERVED_17[436];
  __I  uint32_t ITMCAPR;                           /**< Index table memory capability register, offset: 0x1800 */
  uint8_t RESERVED_18[12];
  __I  uint32_t RPCAPR;                            /**< Rate policer capability register, offset: 0x1810 */
  __I  uint32_t RPITCAPR;                          /**< Rate policer index table capability register, offset: 0x1814 */
  __IO uint32_t RPITMAR;                           /**< Rate policer index table memory allocation register, offset: 0x1818 */
  __I  uint32_t RPITOR;                            /**< Rate policer index table operational register, offset: 0x181C */
  uint8_t RESERVED_19[4];
  __I  uint32_t ISCITCAPR;                         /**< Ingress stream counter index table capability register, offset: 0x1824 */
  __IO uint32_t ISCITMAR;                          /**< Ingress stream counter index table memory allocation register, offset: 0x1828 */
  __I  uint32_t ISCITOR;                           /**< Ingress stream counter index table operational register, offset: 0x182C */
  __I  uint32_t ISCAPR;                            /**< Ingress stream capability register, offset: 0x1830 */
  __I  uint32_t ISITCAPR;                          /**< Ingress stream index table capability register, offset: 0x1834 */
  __IO uint32_t ISITMAR;                           /**< Ingress stream index table memory allocation register, offset: 0x1838 */
  __I  uint32_t ISITOR;                            /**< Ingress stream index table operational register, offset: 0x183C */
  uint8_t RESERVED_20[4];
  __I  uint32_t ISQGITCAPR;                        /**< Ingress sequence generation index table capability register, offset: 0x1844 */
  __IO uint32_t ISQGITMAR;                         /**< Ingress sequence generation index table memory allocation register, offset: 0x1848 */
  __I  uint32_t ISQGITOR;                          /**< Ingress sequence generation index table operational register, offset: 0x184C */
  uint8_t RESERVED_21[16];
  __I  uint32_t SGCAPR;                            /**< Stream gate capability register, offset: 0x1860 */
  __I  uint32_t SGIITCAPR;                         /**< Stream gate instance index table capability register, offset: 0x1864 */
  __IO uint32_t SGIITMAR;                          /**< Stream gate instance index table memory allocation register, offset: 0x1868 */
  __I  uint32_t SGIITOR;                           /**< Stream gate instance index table operational register, offset: 0x186C */
  uint8_t RESERVED_22[4];
  __I  uint32_t SGCLITCAPR;                        /**< Stream gate control list index table capability register, offset: 0x1874 */
  __IO uint32_t SGCLITMAR;                         /**< Stream gate control list index table memory allocation register, offset: 0x1878 */
  __I  uint32_t SGCLTMOR;                          /**< Stream gate control list table memory operational register, offset: 0x187C */
  __I  uint32_t FMICAPR;                           /**< Frame modification ingress capability register, offset: 0x1880 */
  __I  uint32_t FMECAPR;                           /**< Frame modification egress capability register, offset: 0x1884 */
  __I  uint32_t FMITCAPR;                          /**< Frame modification index table capability register, offset: 0x1888 */
  __IO uint32_t FMITMAR;                           /**< Frame modification index table memory allocation register, offset: 0x188C */
  __I  uint32_t FMITOR;                            /**< Frame modification index table operational register, offset: 0x1890 */
  __I  uint32_t FMDITCAPR;                         /**< Frame modification data index table capability register, offset: 0x1894 */
  __IO uint32_t FMDITMAR;                          /**< Frame modification data index table memory allocation register, offset: 0x1898 */
  uint8_t RESERVED_23[36];
  __I  uint32_t ETCAPR;                            /**< Egress treatment capability register, offset: 0x18C0 */
  __I  uint32_t ETTCAPR;                           /**< Egress treatment table capability register, offset: 0x18C4 */
  uint8_t RESERVED_24[4];
  __I  uint32_t ETTOR;                             /**< Egress treatment table operational register, offset: 0x18CC */
  uint8_t RESERVED_25[4];
  __I  uint32_t TGSTCAPR;                          /**< Time gate scheduling table capability register, offset: 0x18D4 */
  uint8_t RESERVED_26[4];
  __I  uint32_t TGSTMOR;                           /**< Time gate scheduling table memory operation register, offset: 0x18DC */
  __I  uint32_t ESQRCAPR;                          /**< Egress sequence recovery capability register, offset: 0x18E0 */
  __I  uint32_t ESQRTCAPR;                         /**< Egress sequence recovery table capability register, offset: 0x18E4 */
  uint8_t RESERVED_27[4];
  __I  uint32_t ECTCAPR;                           /**< Egress counter table capability register, offset: 0x18EC */
  uint8_t RESERVED_28[16];
  __I  uint32_t HTMCAPR;                           /**< Hash table memory capability register, offset: 0x1900 */
  __I  uint32_t HTMOR;                             /**< Hash table memory operational register, offset: 0x1904 */
  uint8_t RESERVED_29[8];
  __I  uint32_t ISIDCAPR;                          /**< Ingress stream identification capability register, offset: 0x1910 */
  __I  uint32_t ISIDHTCAPR;                        /**< Ingress stream identification hash table capability register, offset: 0x1914 */
  uint8_t RESERVED_30[8];
  __I  uint32_t ISIDKC0OR;                         /**< Ingress stream identification key construction 0 operational register, offset: 0x1920 */
  __IO uint32_t ISIDKC0CR0;                        /**< Ingress stream identification key construction 0 configuration register 0, offset: 0x1924 */
  uint8_t RESERVED_31[8];
  __IO uint32_t ISIDKC0PF0CR;                      /**< Ingress stream identification key construction 0 payload field 0 configuration register, offset: 0x1930 */
  __IO uint32_t ISIDKC0PF1CR;                      /**< Ingress stream identification key construction 0 payload field 1 configuration register, offset: 0x1934 */
  __IO uint32_t ISIDKC0PF2CR;                      /**< Ingress stream identification key construction 0 payload field 2 configuration register, offset: 0x1938 */
  __IO uint32_t ISIDKC0PF3CR;                      /**< Ingress stream identification key construction 0 payload field 3 configuration register, offset: 0x193C */
  __I  uint32_t ISIDKC1OR;                         /**< Ingress stream identification key construction 1 operational register, offset: 0x1940 */
  __IO uint32_t ISIDKC1CR0;                        /**< Ingress stream identification key construction 1 configuration register 0, offset: 0x1944 */
  uint8_t RESERVED_32[8];
  __IO uint32_t ISIDKC1PF0CR;                      /**< Ingress stream identification key construction 1 payload field 0 configuration register, offset: 0x1950 */
  __IO uint32_t ISIDKC1PF1CR;                      /**< Ingress stream identification key construction 1 payload field 1 configuration register, offset: 0x1954 */
  __IO uint32_t ISIDKC1PF2CR;                      /**< Ingress stream identification key construction 1 payload field 2 configuration register, offset: 0x1958 */
  __IO uint32_t ISIDKC1PF3CR;                      /**< Ingress stream identification key construction 1 payload field 3 configuration register, offset: 0x195C */
  __I  uint32_t ISIDKC2OR;                         /**< Ingress stream identification key construction 2 operational register, offset: 0x1960 */
  __IO uint32_t ISIDKC2CR0;                        /**< Ingress stream identification key construction 2 configuration register 0, offset: 0x1964 */
  uint8_t RESERVED_33[8];
  __IO uint32_t ISIDKC2PF0CR;                      /**< Ingress stream identification key construction 2 payload field 0 configuration register, offset: 0x1970 */
  __IO uint32_t ISIDKC2PF1CR;                      /**< Ingress stream identification key construction 2 payload field 1 configuration register, offset: 0x1974 */
  __IO uint32_t ISIDKC2PF2CR;                      /**< Ingress stream identification key construction 2 payload field 2 configuration register, offset: 0x1978 */
  __IO uint32_t ISIDKC2PF3CR;                      /**< Ingress stream identification key construction 2 payload field 3 configuration register, offset: 0x197C */
  __I  uint32_t ISIDKC3OR;                         /**< Ingress stream identification key construction 3 operational register, offset: 0x1980 */
  __IO uint32_t ISIDKC3CR0;                        /**< Ingress stream identification key construction 3 configuration register 0, offset: 0x1984 */
  uint8_t RESERVED_34[8];
  __IO uint32_t ISIDKC3PF0CR;                      /**< Ingress stream identification key construction 3 payload field 0 configuration register, offset: 0x1990 */
  __IO uint32_t ISIDKC3PF1CR;                      /**< Ingress stream identification key construction 3 payload field 1 configuration register, offset: 0x1994 */
  __IO uint32_t ISIDKC3PF2CR;                      /**< Ingress stream identification key construction 3 payload field 2 configuration register, offset: 0x1998 */
  __IO uint32_t ISIDKC3PF3CR;                      /**< Ingress stream identification key construction 3 payload field 3 configuration register, offset: 0x199C */
  uint8_t RESERVED_35[96];
  __I  uint32_t ISFHTCAPR;                         /**< Ingress stream filter hash table capability register, offset: 0x1A00 */
  __I  uint32_t ISFHTOR;                           /**< Ingress stream filter hash table operational register, offset: 0x1A04 */
} NETC_F2_COMMON_Type, *NETC_F2_COMMON_MemMapPtr;

/** Number of instances of the NETC_F2_COMMON module. */
#define NETC_F2_COMMON_INSTANCE_COUNT            (1u)

/* NETC_F2_COMMON - Peripheral instance base addresses */
/** Peripheral NETC__SW0_COMMON base address */
#define IP_NETC__SW0_COMMON_BASE                 (0x74A00000u)
/** Peripheral NETC__SW0_COMMON base pointer */
#define IP_NETC__SW0_COMMON                      ((NETC_F2_COMMON_Type *)IP_NETC__SW0_COMMON_BASE)
/** Array initializer of NETC_F2_COMMON peripheral base addresses */
#define IP_NETC_F2_COMMON_BASE_ADDRS             { IP_NETC__SW0_COMMON_BASE }
/** Array initializer of NETC_F2_COMMON peripheral base pointers */
#define IP_NETC_F2_COMMON_BASE_PTRS              { IP_NETC__SW0_COMMON }

/* ----------------------------------------------------------------------------
   -- NETC_F2_COMMON Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_F2_COMMON_Register_Masks NETC_F2_COMMON Register Masks
 * @{
 */

/*! @name IPCAPR - Ingress port capability register */
/*! @{ */

#define NETC_F2_COMMON_IPCAPR_RP_MASK            (0x1U)
#define NETC_F2_COMMON_IPCAPR_RP_SHIFT           (0U)
#define NETC_F2_COMMON_IPCAPR_RP_WIDTH           (1U)
#define NETC_F2_COMMON_IPCAPR_RP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPCAPR_RP_SHIFT)) & NETC_F2_COMMON_IPCAPR_RP_MASK)

#define NETC_F2_COMMON_IPCAPR_IPFLT_MASK         (0x2U)
#define NETC_F2_COMMON_IPCAPR_IPFLT_SHIFT        (1U)
#define NETC_F2_COMMON_IPCAPR_IPFLT_WIDTH        (1U)
#define NETC_F2_COMMON_IPCAPR_IPFLT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPCAPR_IPFLT_SHIFT)) & NETC_F2_COMMON_IPCAPR_IPFLT_MASK)

#define NETC_F2_COMMON_IPCAPR_ISID_MASK          (0x4U)
#define NETC_F2_COMMON_IPCAPR_ISID_SHIFT         (2U)
#define NETC_F2_COMMON_IPCAPR_ISID_WIDTH         (1U)
#define NETC_F2_COMMON_IPCAPR_ISID(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPCAPR_ISID_SHIFT)) & NETC_F2_COMMON_IPCAPR_ISID_MASK)

#define NETC_F2_COMMON_IPCAPR_SDU_MASK           (0x1F00U)
#define NETC_F2_COMMON_IPCAPR_SDU_SHIFT          (8U)
#define NETC_F2_COMMON_IPCAPR_SDU_WIDTH          (5U)
#define NETC_F2_COMMON_IPCAPR_SDU(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPCAPR_SDU_SHIFT)) & NETC_F2_COMMON_IPCAPR_SDU_MASK)

#define NETC_F2_COMMON_IPCAPR_NUM_VQMP_MASK      (0xF0000U)
#define NETC_F2_COMMON_IPCAPR_NUM_VQMP_SHIFT     (16U)
#define NETC_F2_COMMON_IPCAPR_NUM_VQMP_WIDTH     (4U)
#define NETC_F2_COMMON_IPCAPR_NUM_VQMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPCAPR_NUM_VQMP_SHIFT)) & NETC_F2_COMMON_IPCAPR_NUM_VQMP_MASK)
/*! @} */

/*! @name EPCAPR - Egress port capability register */
/*! @{ */

#define NETC_F2_COMMON_EPCAPR_ET_MASK            (0x1U)
#define NETC_F2_COMMON_EPCAPR_ET_SHIFT           (0U)
#define NETC_F2_COMMON_EPCAPR_ET_WIDTH           (1U)
#define NETC_F2_COMMON_EPCAPR_ET(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EPCAPR_ET_SHIFT)) & NETC_F2_COMMON_EPCAPR_ET_MASK)

#define NETC_F2_COMMON_EPCAPR_SDU_MASK           (0x1F00U)
#define NETC_F2_COMMON_EPCAPR_SDU_SHIFT          (8U)
#define NETC_F2_COMMON_EPCAPR_SDU_WIDTH          (5U)
#define NETC_F2_COMMON_EPCAPR_SDU(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EPCAPR_SDU_SHIFT)) & NETC_F2_COMMON_EPCAPR_SDU_MASK)

#define NETC_F2_COMMON_EPCAPR_NUM_QVMP_MASK      (0xF0000U)
#define NETC_F2_COMMON_EPCAPR_NUM_QVMP_SHIFT     (16U)
#define NETC_F2_COMMON_EPCAPR_NUM_QVMP_WIDTH     (4U)
#define NETC_F2_COMMON_EPCAPR_NUM_QVMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EPCAPR_NUM_QVMP_SHIFT)) & NETC_F2_COMMON_EPCAPR_NUM_QVMP_MASK)
/*! @} */

/*! @name OSR - Operational state register */
/*! @{ */

#define NETC_F2_COMMON_OSR_STATE_MASK            (0x1U)
#define NETC_F2_COMMON_OSR_STATE_SHIFT           (0U)
#define NETC_F2_COMMON_OSR_STATE_WIDTH           (1U)
#define NETC_F2_COMMON_OSR_STATE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_OSR_STATE_SHIFT)) & NETC_F2_COMMON_OSR_STATE_MASK)

#define NETC_F2_COMMON_OSR_ITM_STATE_MASK        (0x2U)
#define NETC_F2_COMMON_OSR_ITM_STATE_SHIFT       (1U)
#define NETC_F2_COMMON_OSR_ITM_STATE_WIDTH       (1U)
#define NETC_F2_COMMON_OSR_ITM_STATE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_OSR_ITM_STATE_SHIFT)) & NETC_F2_COMMON_OSR_ITM_STATE_MASK)
/*! @} */

/*! @name CMECR - Correctable memory error configuration register */
/*! @{ */

#define NETC_F2_COMMON_CMECR_THRESHOLD_MASK      (0xFFU)
#define NETC_F2_COMMON_CMECR_THRESHOLD_SHIFT     (0U)
#define NETC_F2_COMMON_CMECR_THRESHOLD_WIDTH     (8U)
#define NETC_F2_COMMON_CMECR_THRESHOLD(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CMECR_THRESHOLD_SHIFT)) & NETC_F2_COMMON_CMECR_THRESHOLD_MASK)
/*! @} */

/*! @name CMESR - Correctable memory error status register */
/*! @{ */

#define NETC_F2_COMMON_CMESR_MEM_ID_MASK         (0x1F0000U)
#define NETC_F2_COMMON_CMESR_MEM_ID_SHIFT        (16U)
#define NETC_F2_COMMON_CMESR_MEM_ID_WIDTH        (5U)
#define NETC_F2_COMMON_CMESR_MEM_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CMESR_MEM_ID_SHIFT)) & NETC_F2_COMMON_CMESR_MEM_ID_MASK)

#define NETC_F2_COMMON_CMESR_SBEE_MASK           (0x80000000U)
#define NETC_F2_COMMON_CMESR_SBEE_SHIFT          (31U)
#define NETC_F2_COMMON_CMESR_SBEE_WIDTH          (1U)
#define NETC_F2_COMMON_CMESR_SBEE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CMESR_SBEE_SHIFT)) & NETC_F2_COMMON_CMESR_SBEE_MASK)
/*! @} */

/*! @name CMECTR - Correctable memory error count register */
/*! @{ */

#define NETC_F2_COMMON_CMECTR_COUNT_MASK         (0xFFU)
#define NETC_F2_COMMON_CMECTR_COUNT_SHIFT        (0U)
#define NETC_F2_COMMON_CMECTR_COUNT_WIDTH        (8U)
#define NETC_F2_COMMON_CMECTR_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CMECTR_COUNT_SHIFT)) & NETC_F2_COMMON_CMECTR_COUNT_MASK)
/*! @} */

/*! @name UNMACECR - Uncorrectable non-fatal MAC error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UNMACECR_PORT0_MASK       (0x1U)
#define NETC_F2_COMMON_UNMACECR_PORT0_SHIFT      (0U)
#define NETC_F2_COMMON_UNMACECR_PORT0_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACECR_PORT0(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACECR_PORT0_SHIFT)) & NETC_F2_COMMON_UNMACECR_PORT0_MASK)

#define NETC_F2_COMMON_UNMACECR_PORT1_MASK       (0x2U)
#define NETC_F2_COMMON_UNMACECR_PORT1_SHIFT      (1U)
#define NETC_F2_COMMON_UNMACECR_PORT1_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACECR_PORT1(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACECR_PORT1_SHIFT)) & NETC_F2_COMMON_UNMACECR_PORT1_MASK)

#define NETC_F2_COMMON_UNMACECR_PORT2_MASK       (0x4U)
#define NETC_F2_COMMON_UNMACECR_PORT2_SHIFT      (2U)
#define NETC_F2_COMMON_UNMACECR_PORT2_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACECR_PORT2(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACECR_PORT2_SHIFT)) & NETC_F2_COMMON_UNMACECR_PORT2_MASK)
/*! @} */

/*! @name UNMACESR - Uncorrectable non-fatal MAC error status register */
/*! @{ */

#define NETC_F2_COMMON_UNMACESR_PORT0_MASK       (0x1U)
#define NETC_F2_COMMON_UNMACESR_PORT0_SHIFT      (0U)
#define NETC_F2_COMMON_UNMACESR_PORT0_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACESR_PORT0(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACESR_PORT0_SHIFT)) & NETC_F2_COMMON_UNMACESR_PORT0_MASK)

#define NETC_F2_COMMON_UNMACESR_PORT1_MASK       (0x2U)
#define NETC_F2_COMMON_UNMACESR_PORT1_SHIFT      (1U)
#define NETC_F2_COMMON_UNMACESR_PORT1_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACESR_PORT1(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACESR_PORT1_SHIFT)) & NETC_F2_COMMON_UNMACESR_PORT1_MASK)

#define NETC_F2_COMMON_UNMACESR_PORT2_MASK       (0x4U)
#define NETC_F2_COMMON_UNMACESR_PORT2_SHIFT      (2U)
#define NETC_F2_COMMON_UNMACESR_PORT2_WIDTH      (1U)
#define NETC_F2_COMMON_UNMACESR_PORT2(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMACESR_PORT2_SHIFT)) & NETC_F2_COMMON_UNMACESR_PORT2_MASK)
/*! @} */

/*! @name UNSBECR - Uncorrectable non-fatal system bus error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UNSBECR_THRESHOLD_MASK    (0xFFU)
#define NETC_F2_COMMON_UNSBECR_THRESHOLD_SHIFT   (0U)
#define NETC_F2_COMMON_UNSBECR_THRESHOLD_WIDTH   (8U)
#define NETC_F2_COMMON_UNSBECR_THRESHOLD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNSBECR_THRESHOLD_SHIFT)) & NETC_F2_COMMON_UNSBECR_THRESHOLD_MASK)
/*! @} */

/*! @name UNSBESR - Uncorrectable non-fatal system bus error status register */
/*! @{ */

#define NETC_F2_COMMON_UNSBESR_SB_ID_MASK        (0xFU)
#define NETC_F2_COMMON_UNSBESR_SB_ID_SHIFT       (0U)
#define NETC_F2_COMMON_UNSBESR_SB_ID_WIDTH       (4U)
#define NETC_F2_COMMON_UNSBESR_SB_ID(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNSBESR_SB_ID_SHIFT)) & NETC_F2_COMMON_UNSBESR_SB_ID_MASK)

#define NETC_F2_COMMON_UNSBESR_SBE_MASK          (0x80000000U)
#define NETC_F2_COMMON_UNSBESR_SBE_SHIFT         (31U)
#define NETC_F2_COMMON_UNSBESR_SBE_WIDTH         (1U)
#define NETC_F2_COMMON_UNSBESR_SBE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNSBESR_SBE_SHIFT)) & NETC_F2_COMMON_UNSBESR_SBE_MASK)
/*! @} */

/*! @name UNSBECTR - Uncorrectable non-fatal system bus error count register */
/*! @{ */

#define NETC_F2_COMMON_UNSBECTR_COUNT_MASK       (0xFFU)
#define NETC_F2_COMMON_UNSBECTR_COUNT_SHIFT      (0U)
#define NETC_F2_COMMON_UNSBECTR_COUNT_WIDTH      (8U)
#define NETC_F2_COMMON_UNSBECTR_COUNT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNSBECTR_COUNT_SHIFT)) & NETC_F2_COMMON_UNSBECTR_COUNT_MASK)
/*! @} */

/*! @name UFSBECR - Uncorrectable fatal system bus error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UFSBECR_RD_MASK           (0x80000000U)
#define NETC_F2_COMMON_UFSBECR_RD_SHIFT          (31U)
#define NETC_F2_COMMON_UFSBECR_RD_WIDTH          (1U)
#define NETC_F2_COMMON_UFSBECR_RD(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFSBECR_RD_SHIFT)) & NETC_F2_COMMON_UFSBECR_RD_MASK)
/*! @} */

/*! @name UFSBESR - Uncorrectable fatal system bus error status register */
/*! @{ */

#define NETC_F2_COMMON_UFSBESR_SB_ID_MASK        (0xFU)
#define NETC_F2_COMMON_UFSBESR_SB_ID_SHIFT       (0U)
#define NETC_F2_COMMON_UFSBESR_SB_ID_WIDTH       (4U)
#define NETC_F2_COMMON_UFSBESR_SB_ID(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFSBESR_SB_ID_SHIFT)) & NETC_F2_COMMON_UFSBESR_SB_ID_MASK)

#define NETC_F2_COMMON_UFSBESR_M_MASK            (0x40000000U)
#define NETC_F2_COMMON_UFSBESR_M_SHIFT           (30U)
#define NETC_F2_COMMON_UFSBESR_M_WIDTH           (1U)
#define NETC_F2_COMMON_UFSBESR_M(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFSBESR_M_SHIFT)) & NETC_F2_COMMON_UFSBESR_M_MASK)

#define NETC_F2_COMMON_UFSBESR_SBE_MASK          (0x80000000U)
#define NETC_F2_COMMON_UFSBESR_SBE_SHIFT         (31U)
#define NETC_F2_COMMON_UFSBESR_SBE_WIDTH         (1U)
#define NETC_F2_COMMON_UFSBESR_SBE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFSBESR_SBE_SHIFT)) & NETC_F2_COMMON_UFSBESR_SBE_MASK)
/*! @} */

/*! @name UNMECR - Uncorrectable non-fatal memory error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UNMECR_THRESHOLD_MASK     (0xFFU)
#define NETC_F2_COMMON_UNMECR_THRESHOLD_SHIFT    (0U)
#define NETC_F2_COMMON_UNMECR_THRESHOLD_WIDTH    (8U)
#define NETC_F2_COMMON_UNMECR_THRESHOLD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMECR_THRESHOLD_SHIFT)) & NETC_F2_COMMON_UNMECR_THRESHOLD_MASK)

#define NETC_F2_COMMON_UNMECR_RD_MASK            (0x80000000U)
#define NETC_F2_COMMON_UNMECR_RD_SHIFT           (31U)
#define NETC_F2_COMMON_UNMECR_RD_WIDTH           (1U)
#define NETC_F2_COMMON_UNMECR_RD(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMECR_RD_SHIFT)) & NETC_F2_COMMON_UNMECR_RD_MASK)
/*! @} */

/*! @name UNMESR0 - Uncorrectable non-fatal memory error status register 0 */
/*! @{ */

#define NETC_F2_COMMON_UNMESR0_SYNDROME_MASK     (0x7FFU)
#define NETC_F2_COMMON_UNMESR0_SYNDROME_SHIFT    (0U)
#define NETC_F2_COMMON_UNMESR0_SYNDROME_WIDTH    (11U)
#define NETC_F2_COMMON_UNMESR0_SYNDROME(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMESR0_SYNDROME_SHIFT)) & NETC_F2_COMMON_UNMESR0_SYNDROME_MASK)

#define NETC_F2_COMMON_UNMESR0_MEM_ID_MASK       (0x1F0000U)
#define NETC_F2_COMMON_UNMESR0_MEM_ID_SHIFT      (16U)
#define NETC_F2_COMMON_UNMESR0_MEM_ID_WIDTH      (5U)
#define NETC_F2_COMMON_UNMESR0_MEM_ID(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMESR0_MEM_ID_SHIFT)) & NETC_F2_COMMON_UNMESR0_MEM_ID_MASK)

#define NETC_F2_COMMON_UNMESR0_MBEE_MASK         (0x80000000U)
#define NETC_F2_COMMON_UNMESR0_MBEE_SHIFT        (31U)
#define NETC_F2_COMMON_UNMESR0_MBEE_WIDTH        (1U)
#define NETC_F2_COMMON_UNMESR0_MBEE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMESR0_MBEE_SHIFT)) & NETC_F2_COMMON_UNMESR0_MBEE_MASK)
/*! @} */

/*! @name UNMESR1 - Uncorrectable non-fatal memory error status register 1 */
/*! @{ */

#define NETC_F2_COMMON_UNMESR1_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_F2_COMMON_UNMESR1_ADDR_SHIFT        (0U)
#define NETC_F2_COMMON_UNMESR1_ADDR_WIDTH        (32U)
#define NETC_F2_COMMON_UNMESR1_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMESR1_ADDR_SHIFT)) & NETC_F2_COMMON_UNMESR1_ADDR_MASK)
/*! @} */

/*! @name UNMECTR - Uncorrectable non-fatal memory error count register */
/*! @{ */

#define NETC_F2_COMMON_UNMECTR_COUNT_MASK        (0xFFU)
#define NETC_F2_COMMON_UNMECTR_COUNT_SHIFT       (0U)
#define NETC_F2_COMMON_UNMECTR_COUNT_WIDTH       (8U)
#define NETC_F2_COMMON_UNMECTR_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNMECTR_COUNT_SHIFT)) & NETC_F2_COMMON_UNMECTR_COUNT_MASK)
/*! @} */

/*! @name UFMECR - Uncorrectable fatal memory error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UFMECR_RD_MASK            (0x80000000U)
#define NETC_F2_COMMON_UFMECR_RD_SHIFT           (31U)
#define NETC_F2_COMMON_UFMECR_RD_WIDTH           (1U)
#define NETC_F2_COMMON_UFMECR_RD(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMECR_RD_SHIFT)) & NETC_F2_COMMON_UFMECR_RD_MASK)
/*! @} */

/*! @name UFMESR0 - Uncorrectable fatal memory error status register 0 */
/*! @{ */

#define NETC_F2_COMMON_UFMESR0_SYNDROME_MASK     (0x7FFU)
#define NETC_F2_COMMON_UFMESR0_SYNDROME_SHIFT    (0U)
#define NETC_F2_COMMON_UFMESR0_SYNDROME_WIDTH    (11U)
#define NETC_F2_COMMON_UFMESR0_SYNDROME(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMESR0_SYNDROME_SHIFT)) & NETC_F2_COMMON_UFMESR0_SYNDROME_MASK)

#define NETC_F2_COMMON_UFMESR0_MEM_ID_MASK       (0x1F0000U)
#define NETC_F2_COMMON_UFMESR0_MEM_ID_SHIFT      (16U)
#define NETC_F2_COMMON_UFMESR0_MEM_ID_WIDTH      (5U)
#define NETC_F2_COMMON_UFMESR0_MEM_ID(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMESR0_MEM_ID_SHIFT)) & NETC_F2_COMMON_UFMESR0_MEM_ID_MASK)

#define NETC_F2_COMMON_UFMESR0_M_MASK            (0x40000000U)
#define NETC_F2_COMMON_UFMESR0_M_SHIFT           (30U)
#define NETC_F2_COMMON_UFMESR0_M_WIDTH           (1U)
#define NETC_F2_COMMON_UFMESR0_M(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMESR0_M_SHIFT)) & NETC_F2_COMMON_UFMESR0_M_MASK)

#define NETC_F2_COMMON_UFMESR0_MBEE_MASK         (0x80000000U)
#define NETC_F2_COMMON_UFMESR0_MBEE_SHIFT        (31U)
#define NETC_F2_COMMON_UFMESR0_MBEE_WIDTH        (1U)
#define NETC_F2_COMMON_UFMESR0_MBEE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMESR0_MBEE_SHIFT)) & NETC_F2_COMMON_UFMESR0_MBEE_MASK)
/*! @} */

/*! @name UFMESR1 - Uncorrectable fatal memory error status register 1 */
/*! @{ */

#define NETC_F2_COMMON_UFMESR1_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_F2_COMMON_UFMESR1_ADDR_SHIFT        (0U)
#define NETC_F2_COMMON_UFMESR1_ADDR_WIDTH        (32U)
#define NETC_F2_COMMON_UFMESR1_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFMESR1_ADDR_SHIFT)) & NETC_F2_COMMON_UFMESR1_ADDR_MASK)
/*! @} */

/*! @name UNIECR - Uncorrectable non-fatal integrity error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UNIECR_THRESHOLD_MASK     (0xFFU)
#define NETC_F2_COMMON_UNIECR_THRESHOLD_SHIFT    (0U)
#define NETC_F2_COMMON_UNIECR_THRESHOLD_WIDTH    (8U)
#define NETC_F2_COMMON_UNIECR_THRESHOLD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIECR_THRESHOLD_SHIFT)) & NETC_F2_COMMON_UNIECR_THRESHOLD_MASK)

#define NETC_F2_COMMON_UNIECR_RD_MASK            (0x80000000U)
#define NETC_F2_COMMON_UNIECR_RD_SHIFT           (31U)
#define NETC_F2_COMMON_UNIECR_RD_WIDTH           (1U)
#define NETC_F2_COMMON_UNIECR_RD(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIECR_RD_SHIFT)) & NETC_F2_COMMON_UNIECR_RD_MASK)
/*! @} */

/*! @name UNIESR - Uncorrectable non-fatal integrity error status register */
/*! @{ */

#define NETC_F2_COMMON_UNIESR_LINK_SLICE_ID_MASK (0xFU)
#define NETC_F2_COMMON_UNIESR_LINK_SLICE_ID_SHIFT (0U)
#define NETC_F2_COMMON_UNIESR_LINK_SLICE_ID_WIDTH (4U)
#define NETC_F2_COMMON_UNIESR_LINK_SLICE_ID(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIESR_LINK_SLICE_ID_SHIFT)) & NETC_F2_COMMON_UNIESR_LINK_SLICE_ID_MASK)

#define NETC_F2_COMMON_UNIESR_BLOCK_ID_MASK      (0xF0U)
#define NETC_F2_COMMON_UNIESR_BLOCK_ID_SHIFT     (4U)
#define NETC_F2_COMMON_UNIESR_BLOCK_ID_WIDTH     (4U)
#define NETC_F2_COMMON_UNIESR_BLOCK_ID(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIESR_BLOCK_ID_SHIFT)) & NETC_F2_COMMON_UNIESR_BLOCK_ID_MASK)

#define NETC_F2_COMMON_UNIESR_SM_ID_MASK         (0x3F00U)
#define NETC_F2_COMMON_UNIESR_SM_ID_SHIFT        (8U)
#define NETC_F2_COMMON_UNIESR_SM_ID_WIDTH        (6U)
#define NETC_F2_COMMON_UNIESR_SM_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIESR_SM_ID_SHIFT)) & NETC_F2_COMMON_UNIESR_SM_ID_MASK)

#define NETC_F2_COMMON_UNIESR_ENGINE_ID_MASK     (0x10000U)
#define NETC_F2_COMMON_UNIESR_ENGINE_ID_SHIFT    (16U)
#define NETC_F2_COMMON_UNIESR_ENGINE_ID_WIDTH    (1U)
#define NETC_F2_COMMON_UNIESR_ENGINE_ID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIESR_ENGINE_ID_SHIFT)) & NETC_F2_COMMON_UNIESR_ENGINE_ID_MASK)

#define NETC_F2_COMMON_UNIESR_INTERR_MASK        (0x80000000U)
#define NETC_F2_COMMON_UNIESR_INTERR_SHIFT       (31U)
#define NETC_F2_COMMON_UNIESR_INTERR_WIDTH       (1U)
#define NETC_F2_COMMON_UNIESR_INTERR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIESR_INTERR_SHIFT)) & NETC_F2_COMMON_UNIESR_INTERR_MASK)
/*! @} */

/*! @name UNIECTR - Uncorrectable non-fatal integrity error count register */
/*! @{ */

#define NETC_F2_COMMON_UNIECTR_COUNT_MASK        (0xFFU)
#define NETC_F2_COMMON_UNIECTR_COUNT_SHIFT       (0U)
#define NETC_F2_COMMON_UNIECTR_COUNT_WIDTH       (8U)
#define NETC_F2_COMMON_UNIECTR_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UNIECTR_COUNT_SHIFT)) & NETC_F2_COMMON_UNIECTR_COUNT_MASK)
/*! @} */

/*! @name UFIECR - Uncorrectable fatal integrity error configuration register */
/*! @{ */

#define NETC_F2_COMMON_UFIECR_RD_MASK            (0x80000000U)
#define NETC_F2_COMMON_UFIECR_RD_SHIFT           (31U)
#define NETC_F2_COMMON_UFIECR_RD_WIDTH           (1U)
#define NETC_F2_COMMON_UFIECR_RD(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIECR_RD_SHIFT)) & NETC_F2_COMMON_UFIECR_RD_MASK)
/*! @} */

/*! @name UFIESR - Uncorrectable fatal integrity error status register */
/*! @{ */

#define NETC_F2_COMMON_UFIESR_LINK_SLICE_ID_MASK (0xFU)
#define NETC_F2_COMMON_UFIESR_LINK_SLICE_ID_SHIFT (0U)
#define NETC_F2_COMMON_UFIESR_LINK_SLICE_ID_WIDTH (4U)
#define NETC_F2_COMMON_UFIESR_LINK_SLICE_ID(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_LINK_SLICE_ID_SHIFT)) & NETC_F2_COMMON_UFIESR_LINK_SLICE_ID_MASK)

#define NETC_F2_COMMON_UFIESR_BLOCK_ID_MASK      (0xF0U)
#define NETC_F2_COMMON_UFIESR_BLOCK_ID_SHIFT     (4U)
#define NETC_F2_COMMON_UFIESR_BLOCK_ID_WIDTH     (4U)
#define NETC_F2_COMMON_UFIESR_BLOCK_ID(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_BLOCK_ID_SHIFT)) & NETC_F2_COMMON_UFIESR_BLOCK_ID_MASK)

#define NETC_F2_COMMON_UFIESR_SM_ID_MASK         (0x3F00U)
#define NETC_F2_COMMON_UFIESR_SM_ID_SHIFT        (8U)
#define NETC_F2_COMMON_UFIESR_SM_ID_WIDTH        (6U)
#define NETC_F2_COMMON_UFIESR_SM_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_SM_ID_SHIFT)) & NETC_F2_COMMON_UFIESR_SM_ID_MASK)

#define NETC_F2_COMMON_UFIESR_ENGINE_ID_MASK     (0x10000U)
#define NETC_F2_COMMON_UFIESR_ENGINE_ID_SHIFT    (16U)
#define NETC_F2_COMMON_UFIESR_ENGINE_ID_WIDTH    (1U)
#define NETC_F2_COMMON_UFIESR_ENGINE_ID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_ENGINE_ID_SHIFT)) & NETC_F2_COMMON_UFIESR_ENGINE_ID_MASK)

#define NETC_F2_COMMON_UFIESR_M_MASK             (0x40000000U)
#define NETC_F2_COMMON_UFIESR_M_SHIFT            (30U)
#define NETC_F2_COMMON_UFIESR_M_WIDTH            (1U)
#define NETC_F2_COMMON_UFIESR_M(x)               (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_M_SHIFT)) & NETC_F2_COMMON_UFIESR_M_MASK)

#define NETC_F2_COMMON_UFIESR_INTERR_MASK        (0x80000000U)
#define NETC_F2_COMMON_UFIESR_INTERR_SHIFT       (31U)
#define NETC_F2_COMMON_UFIESR_INTERR_WIDTH       (1U)
#define NETC_F2_COMMON_UFIESR_INTERR(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_UFIESR_INTERR_SHIFT)) & NETC_F2_COMMON_UFIESR_INTERR_MASK)
/*! @} */

/*! @name EMDIOIRR - External MDIO interrupt reason register */
/*! @{ */

#define NETC_F2_COMMON_EMDIOIRR_PORT0_MASK       (0x1U)
#define NETC_F2_COMMON_EMDIOIRR_PORT0_SHIFT      (0U)
#define NETC_F2_COMMON_EMDIOIRR_PORT0_WIDTH      (1U)
#define NETC_F2_COMMON_EMDIOIRR_PORT0(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EMDIOIRR_PORT0_SHIFT)) & NETC_F2_COMMON_EMDIOIRR_PORT0_MASK)

#define NETC_F2_COMMON_EMDIOIRR_PORT1_MASK       (0x2U)
#define NETC_F2_COMMON_EMDIOIRR_PORT1_SHIFT      (1U)
#define NETC_F2_COMMON_EMDIOIRR_PORT1_WIDTH      (1U)
#define NETC_F2_COMMON_EMDIOIRR_PORT1(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EMDIOIRR_PORT1_SHIFT)) & NETC_F2_COMMON_EMDIOIRR_PORT1_MASK)

#define NETC_F2_COMMON_EMDIOIRR_PORT2_MASK       (0x4U)
#define NETC_F2_COMMON_EMDIOIRR_PORT2_SHIFT      (2U)
#define NETC_F2_COMMON_EMDIOIRR_PORT2_WIDTH      (1U)
#define NETC_F2_COMMON_EMDIOIRR_PORT2(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EMDIOIRR_PORT2_SHIFT)) & NETC_F2_COMMON_EMDIOIRR_PORT2_MASK)
/*! @} */

/*! @name EMDIOMSIVR - External MDIO MSI-X vector register */
/*! @{ */

#define NETC_F2_COMMON_EMDIOMSIVR_VECTOR_MASK    (0xFU)
#define NETC_F2_COMMON_EMDIOMSIVR_VECTOR_SHIFT   (0U)
#define NETC_F2_COMMON_EMDIOMSIVR_VECTOR_WIDTH   (4U)
#define NETC_F2_COMMON_EMDIOMSIVR_VECTOR(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_EMDIOMSIVR_VECTOR_SHIFT)) & NETC_F2_COMMON_EMDIOMSIVR_VECTOR_MASK)
/*! @} */

/*! @name TCCR - Time capture configuration register */
/*! @{ */

#define NETC_F2_COMMON_TCCR_TIMEOUT_MASK         (0xFFFFFFU)
#define NETC_F2_COMMON_TCCR_TIMEOUT_SHIFT        (0U)
#define NETC_F2_COMMON_TCCR_TIMEOUT_WIDTH        (24U)
#define NETC_F2_COMMON_TCCR_TIMEOUT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCCR_TIMEOUT_SHIFT)) & NETC_F2_COMMON_TCCR_TIMEOUT_MASK)

#define NETC_F2_COMMON_TCCR_ARM_MASK             (0xC0000000U)
#define NETC_F2_COMMON_TCCR_ARM_SHIFT            (30U)
#define NETC_F2_COMMON_TCCR_ARM_WIDTH            (2U)
#define NETC_F2_COMMON_TCCR_ARM(x)               (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCCR_ARM_SHIFT)) & NETC_F2_COMMON_TCCR_ARM_MASK)
/*! @} */

/*! @name TCIER - Time capture interrupt enable register */
/*! @{ */

#define NETC_F2_COMMON_TCIER_TRANSMIT_MASK       (0x40000000U)
#define NETC_F2_COMMON_TCIER_TRANSMIT_SHIFT      (30U)
#define NETC_F2_COMMON_TCIER_TRANSMIT_WIDTH      (1U)
#define NETC_F2_COMMON_TCIER_TRANSMIT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCIER_TRANSMIT_SHIFT)) & NETC_F2_COMMON_TCIER_TRANSMIT_MASK)

#define NETC_F2_COMMON_TCIER_TIMEOUT_MASK        (0x80000000U)
#define NETC_F2_COMMON_TCIER_TIMEOUT_SHIFT       (31U)
#define NETC_F2_COMMON_TCIER_TIMEOUT_WIDTH       (1U)
#define NETC_F2_COMMON_TCIER_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCIER_TIMEOUT_SHIFT)) & NETC_F2_COMMON_TCIER_TIMEOUT_MASK)
/*! @} */

/*! @name TCRPIDR - Time capture receive port interrupt detect register */
/*! @{ */

#define NETC_F2_COMMON_TCRPIDR_TX_PORT0_MASK     (0x1U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT0_SHIFT    (0U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT0_WIDTH    (1U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT0(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPIDR_TX_PORT0_SHIFT)) & NETC_F2_COMMON_TCRPIDR_TX_PORT0_MASK)

#define NETC_F2_COMMON_TCRPIDR_TX_PORT1_MASK     (0x2U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT1_SHIFT    (1U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT1_WIDTH    (1U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT1(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPIDR_TX_PORT1_SHIFT)) & NETC_F2_COMMON_TCRPIDR_TX_PORT1_MASK)

#define NETC_F2_COMMON_TCRPIDR_TX_PORT2_MASK     (0x4U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT2_SHIFT    (2U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT2_WIDTH    (1U)
#define NETC_F2_COMMON_TCRPIDR_TX_PORT2(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPIDR_TX_PORT2_SHIFT)) & NETC_F2_COMMON_TCRPIDR_TX_PORT2_MASK)

#define NETC_F2_COMMON_TCRPIDR_TRANSMIT_MASK     (0x40000000U)
#define NETC_F2_COMMON_TCRPIDR_TRANSMIT_SHIFT    (30U)
#define NETC_F2_COMMON_TCRPIDR_TRANSMIT_WIDTH    (1U)
#define NETC_F2_COMMON_TCRPIDR_TRANSMIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPIDR_TRANSMIT_SHIFT)) & NETC_F2_COMMON_TCRPIDR_TRANSMIT_MASK)

#define NETC_F2_COMMON_TCRPIDR_TIMEOUT_MASK      (0x80000000U)
#define NETC_F2_COMMON_TCRPIDR_TIMEOUT_SHIFT     (31U)
#define NETC_F2_COMMON_TCRPIDR_TIMEOUT_WIDTH     (1U)
#define NETC_F2_COMMON_TCRPIDR_TIMEOUT(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPIDR_TIMEOUT_SHIFT)) & NETC_F2_COMMON_TCRPIDR_TIMEOUT_MASK)
/*! @} */

/*! @name TCRPSR - Time capture receive port status register */
/*! @{ */

#define NETC_F2_COMMON_TCRPSR_RX_PORT_MASK       (0x1FU)
#define NETC_F2_COMMON_TCRPSR_RX_PORT_SHIFT      (0U)
#define NETC_F2_COMMON_TCRPSR_RX_PORT_WIDTH      (5U)
#define NETC_F2_COMMON_TCRPSR_RX_PORT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPSR_RX_PORT_SHIFT)) & NETC_F2_COMMON_TCRPSR_RX_PORT_MASK)

#define NETC_F2_COMMON_TCRPSR_RX_CNT_MASK        (0x300U)
#define NETC_F2_COMMON_TCRPSR_RX_CNT_SHIFT       (8U)
#define NETC_F2_COMMON_TCRPSR_RX_CNT_WIDTH       (2U)
#define NETC_F2_COMMON_TCRPSR_RX_CNT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPSR_RX_CNT_SHIFT)) & NETC_F2_COMMON_TCRPSR_RX_CNT_MASK)
/*! @} */

/*! @name TCRPTSR - Time capture receive port timestamp register */
/*! @{ */

#define NETC_F2_COMMON_TCRPTSR_TIMESTAMP_MASK    (0xFFFFFFFFU)
#define NETC_F2_COMMON_TCRPTSR_TIMESTAMP_SHIFT   (0U)
#define NETC_F2_COMMON_TCRPTSR_TIMESTAMP_WIDTH   (32U)
#define NETC_F2_COMMON_TCRPTSR_TIMESTAMP(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCRPTSR_TIMESTAMP_SHIFT)) & NETC_F2_COMMON_TCRPTSR_TIMESTAMP_MASK)
/*! @} */

/*! @name TCMSIVR - Time capture MSI-X vector register */
/*! @{ */

#define NETC_F2_COMMON_TCMSIVR_VECTOR_MASK       (0xFU)
#define NETC_F2_COMMON_TCMSIVR_VECTOR_SHIFT      (0U)
#define NETC_F2_COMMON_TCMSIVR_VECTOR_WIDTH      (4U)
#define NETC_F2_COMMON_TCMSIVR_VECTOR(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TCMSIVR_VECTOR_SHIFT)) & NETC_F2_COMMON_TCMSIVR_VECTOR_MASK)
/*! @} */

/*! @name CVLANR1 - Custom VLAN EtherType register 1 */
/*! @{ */

#define NETC_F2_COMMON_CVLANR1_ETYPE_MASK        (0xFFFFU)
#define NETC_F2_COMMON_CVLANR1_ETYPE_SHIFT       (0U)
#define NETC_F2_COMMON_CVLANR1_ETYPE_WIDTH       (16U)
#define NETC_F2_COMMON_CVLANR1_ETYPE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CVLANR1_ETYPE_SHIFT)) & NETC_F2_COMMON_CVLANR1_ETYPE_MASK)

#define NETC_F2_COMMON_CVLANR1_V_MASK            (0x80000000U)
#define NETC_F2_COMMON_CVLANR1_V_SHIFT           (31U)
#define NETC_F2_COMMON_CVLANR1_V_WIDTH           (1U)
#define NETC_F2_COMMON_CVLANR1_V(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CVLANR1_V_SHIFT)) & NETC_F2_COMMON_CVLANR1_V_MASK)
/*! @} */

/*! @name CVLANR2 - Custom VLAN EtherType register 2 */
/*! @{ */

#define NETC_F2_COMMON_CVLANR2_ETYPE_MASK        (0xFFFFU)
#define NETC_F2_COMMON_CVLANR2_ETYPE_SHIFT       (0U)
#define NETC_F2_COMMON_CVLANR2_ETYPE_WIDTH       (16U)
#define NETC_F2_COMMON_CVLANR2_ETYPE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CVLANR2_ETYPE_SHIFT)) & NETC_F2_COMMON_CVLANR2_ETYPE_MASK)

#define NETC_F2_COMMON_CVLANR2_V_MASK            (0x80000000U)
#define NETC_F2_COMMON_CVLANR2_V_SHIFT           (31U)
#define NETC_F2_COMMON_CVLANR2_V_WIDTH           (1U)
#define NETC_F2_COMMON_CVLANR2_V(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_CVLANR2_V_SHIFT)) & NETC_F2_COMMON_CVLANR2_V_MASK)
/*! @} */

/*! @name PSRTAGETR - Pre-Standard RTAG EtherType register */
/*! @{ */

#define NETC_F2_COMMON_PSRTAGETR_ETHERTYPE_MASK  (0xFFFFU)
#define NETC_F2_COMMON_PSRTAGETR_ETHERTYPE_SHIFT (0U)
#define NETC_F2_COMMON_PSRTAGETR_ETHERTYPE_WIDTH (16U)
#define NETC_F2_COMMON_PSRTAGETR_ETHERTYPE(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_PSRTAGETR_ETHERTYPE_SHIFT)) & NETC_F2_COMMON_PSRTAGETR_ETHERTYPE_MASK)
/*! @} */

/*! @name DOSL2CR - DoS L2 configuration register */
/*! @{ */

#define NETC_F2_COMMON_DOSL2CR_SAMEADDR_MASK     (0x1U)
#define NETC_F2_COMMON_DOSL2CR_SAMEADDR_SHIFT    (0U)
#define NETC_F2_COMMON_DOSL2CR_SAMEADDR_WIDTH    (1U)
#define NETC_F2_COMMON_DOSL2CR_SAMEADDR(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_DOSL2CR_SAMEADDR_SHIFT)) & NETC_F2_COMMON_DOSL2CR_SAMEADDR_MASK)

#define NETC_F2_COMMON_DOSL2CR_MSAMCC_MASK       (0x2U)
#define NETC_F2_COMMON_DOSL2CR_MSAMCC_SHIFT      (1U)
#define NETC_F2_COMMON_DOSL2CR_MSAMCC_WIDTH      (1U)
#define NETC_F2_COMMON_DOSL2CR_MSAMCC(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_DOSL2CR_MSAMCC_SHIFT)) & NETC_F2_COMMON_DOSL2CR_MSAMCC_MASK)
/*! @} */

/*! @name VLANIPVMPR0 - VLAN to IPV mapping profile 0 register 0..VLAN to IPV mapping profile 1 register 0 */
/*! @{ */

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_MASK (0x7U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_SHIFT (0U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_0_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1_MASK (0x70U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1_SHIFT (4U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_1_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2_MASK (0x700U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2_SHIFT (8U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_2_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3_MASK (0x7000U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3_SHIFT (12U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_3_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4_MASK (0x70000U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4_SHIFT (16U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_4_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5_MASK (0x700000U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5_SHIFT (20U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_5_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6_MASK (0x7000000U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6_SHIFT (24U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_6_MASK)

#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7_MASK (0x70000000U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7_SHIFT (28U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR0_PCP_DEI_7_MASK)
/*! @} */

/*! @name VLANIPVMPR1 - VLAN to IPV mapping profile 0 register 1..VLAN to IPV mapping profile 1 register 1 */
/*! @{ */

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8_MASK (0x7U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8_SHIFT (0U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_8_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9_MASK (0x70U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9_SHIFT (4U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_9_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10_MASK (0x700U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10_SHIFT (8U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_10_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11_MASK (0x7000U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11_SHIFT (12U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_11_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12_MASK (0x70000U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12_SHIFT (16U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_12_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13_MASK (0x700000U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13_SHIFT (20U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_13_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14_MASK (0x7000000U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14_SHIFT (24U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_14_MASK)

#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15_MASK (0x70000000U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15_SHIFT (28U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15_WIDTH (3U)
#define NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15_SHIFT)) & NETC_F2_COMMON_VLANIPVMPR1_PCP_DEI_15_MASK)
/*! @} */

/*! @name VLANDRMPR - VLAN to DR mapping profile 0 register..VLAN to DR mapping profile 1 register */
/*! @{ */

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_MASK  (0x3U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_SHIFT (0U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_0_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1_MASK  (0xCU)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1_SHIFT (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_1_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2_MASK  (0x30U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2_SHIFT (4U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_2_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3_MASK  (0xC0U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3_SHIFT (6U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_3_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4_MASK  (0x300U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4_SHIFT (8U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_4_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5_MASK  (0xC00U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5_SHIFT (10U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_5_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6_MASK  (0x3000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6_SHIFT (12U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_6_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7_MASK  (0xC000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7_SHIFT (14U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_7_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8_MASK  (0x30000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8_SHIFT (16U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_8_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9_MASK  (0xC0000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9_SHIFT (18U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_9_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10_MASK (0x300000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10_SHIFT (20U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_10_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11_MASK (0xC00000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11_SHIFT (22U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_11_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12_MASK (0x3000000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12_SHIFT (24U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_12_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13_MASK (0xC000000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13_SHIFT (26U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_13_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14_MASK (0x30000000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14_SHIFT (28U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_14_MASK)

#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15_MASK (0xC0000000U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15_SHIFT (30U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15_WIDTH (2U)
#define NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15_SHIFT)) & NETC_F2_COMMON_VLANDRMPR_PCP_DEI_15_MASK)
/*! @} */

/*! @name IPFCAPR - Ingress port filter capability register */
/*! @{ */

#define NETC_F2_COMMON_IPFCAPR_RP_MASK           (0x1U)
#define NETC_F2_COMMON_IPFCAPR_RP_SHIFT          (0U)
#define NETC_F2_COMMON_IPFCAPR_RP_WIDTH          (1U)
#define NETC_F2_COMMON_IPFCAPR_RP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFCAPR_RP_SHIFT)) & NETC_F2_COMMON_IPFCAPR_RP_MASK)

#define NETC_F2_COMMON_IPFCAPR_ISID_MASK         (0x2U)
#define NETC_F2_COMMON_IPFCAPR_ISID_SHIFT        (1U)
#define NETC_F2_COMMON_IPFCAPR_ISID_WIDTH        (1U)
#define NETC_F2_COMMON_IPFCAPR_ISID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFCAPR_ISID_SHIFT)) & NETC_F2_COMMON_IPFCAPR_ISID_MASK)
/*! @} */

/*! @name IPFTCAPR - Ingress port filter table capability register */
/*! @{ */

#define NETC_F2_COMMON_IPFTCAPR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_IPFTCAPR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_IPFTCAPR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_IPFTCAPR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_IPFTCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_IPFTCAPR_MGMT_MASK        (0x10000U)
#define NETC_F2_COMMON_IPFTCAPR_MGMT_SHIFT       (16U)
#define NETC_F2_COMMON_IPFTCAPR_MGMT_WIDTH       (1U)
#define NETC_F2_COMMON_IPFTCAPR_MGMT(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTCAPR_MGMT_SHIFT)) & NETC_F2_COMMON_IPFTCAPR_MGMT_MASK)

#define NETC_F2_COMMON_IPFTCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_IPFTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_IPFTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_IPFTCAPR_ACCESS_METH(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_IPFTCAPR_ACCESS_METH_MASK)

#define NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS_MASK (0xF000000U)
#define NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS_SHIFT (24U)
#define NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS_WIDTH (4U)
#define NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS_SHIFT)) & NETC_F2_COMMON_IPFTCAPR_ENTRY_MAX_WORDS_MASK)

#define NETC_F2_COMMON_IPFTCAPR_WORD_SIZE_MASK   (0x30000000U)
#define NETC_F2_COMMON_IPFTCAPR_WORD_SIZE_SHIFT  (28U)
#define NETC_F2_COMMON_IPFTCAPR_WORD_SIZE_WIDTH  (2U)
#define NETC_F2_COMMON_IPFTCAPR_WORD_SIZE(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTCAPR_WORD_SIZE_SHIFT)) & NETC_F2_COMMON_IPFTCAPR_WORD_SIZE_MASK)
/*! @} */

/*! @name IPFTMOR - Ingress port filter table memory operational register */
/*! @{ */

#define NETC_F2_COMMON_IPFTMOR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_IPFTMOR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_IPFTMOR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_IPFTMOR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_IPFTMOR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_IPFTMOR_NUM_WORDS_MASK)
/*! @} */

/*! @name ITMCAPR - Index table memory capability register */
/*! @{ */

#define NETC_F2_COMMON_ITMCAPR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_ITMCAPR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_ITMCAPR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_ITMCAPR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ITMCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_ITMCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_ITMCAPR_WORD_SIZE_MASK    (0x30000000U)
#define NETC_F2_COMMON_ITMCAPR_WORD_SIZE_SHIFT   (28U)
#define NETC_F2_COMMON_ITMCAPR_WORD_SIZE_WIDTH   (2U)
#define NETC_F2_COMMON_ITMCAPR_WORD_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ITMCAPR_WORD_SIZE_SHIFT)) & NETC_F2_COMMON_ITMCAPR_WORD_SIZE_MASK)

#define NETC_F2_COMMON_ITMCAPR_MLOC_MASK         (0xC0000000U)
#define NETC_F2_COMMON_ITMCAPR_MLOC_SHIFT        (30U)
#define NETC_F2_COMMON_ITMCAPR_MLOC_WIDTH        (2U)
#define NETC_F2_COMMON_ITMCAPR_MLOC(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ITMCAPR_MLOC_SHIFT)) & NETC_F2_COMMON_ITMCAPR_MLOC_MASK)
/*! @} */

/*! @name RPCAPR - Rate policer capability register */
/*! @{ */

#define NETC_F2_COMMON_RPCAPR_TRTCM_MASK         (0x1U)
#define NETC_F2_COMMON_RPCAPR_TRTCM_SHIFT        (0U)
#define NETC_F2_COMMON_RPCAPR_TRTCM_WIDTH        (1U)
#define NETC_F2_COMMON_RPCAPR_TRTCM(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPCAPR_TRTCM_SHIFT)) & NETC_F2_COMMON_RPCAPR_TRTCM_MASK)

#define NETC_F2_COMMON_RPCAPR_CM_MASK            (0x2U)
#define NETC_F2_COMMON_RPCAPR_CM_SHIFT           (1U)
#define NETC_F2_COMMON_RPCAPR_CM_WIDTH           (1U)
#define NETC_F2_COMMON_RPCAPR_CM(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPCAPR_CM_SHIFT)) & NETC_F2_COMMON_RPCAPR_CM_MASK)
/*! @} */

/*! @name RPITCAPR - Rate policer index table capability register */
/*! @{ */

#define NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES_MASK (0x3FFFU)
#define NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES_WIDTH (14U)
#define NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_RPITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_RPITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_RPITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_RPITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_RPITCAPR_ACCESS_METH(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_RPITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name RPITMAR - Rate policer index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_RPITMAR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_RPITMAR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_RPITMAR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_RPITMAR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_RPITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name RPITOR - Rate policer index table operational register */
/*! @{ */

#define NETC_F2_COMMON_RPITOR_NUM_ENTRIES_MASK   (0x3FFFU)
#define NETC_F2_COMMON_RPITOR_NUM_ENTRIES_SHIFT  (0U)
#define NETC_F2_COMMON_RPITOR_NUM_ENTRIES_WIDTH  (14U)
#define NETC_F2_COMMON_RPITOR_NUM_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_RPITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_RPITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name ISCITCAPR - Ingress stream counter index table capability register */
/*! @{ */

#define NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISCITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISCITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ISCITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ISCITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ISCITCAPR_ACCESS_METH(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ISCITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ISCITMAR - Ingress stream counter index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_ISCITMAR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_ISCITMAR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_ISCITMAR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_ISCITMAR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_ISCITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ISCITOR - Ingress stream counter index table operational register */
/*! @{ */

#define NETC_F2_COMMON_ISCITOR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_COMMON_ISCITOR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISCITOR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISCITOR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISCITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name ISCAPR - Ingress stream capability register */
/*! @{ */

#define NETC_F2_COMMON_ISCAPR_ISQG_MASK          (0x2U)
#define NETC_F2_COMMON_ISCAPR_ISQG_SHIFT         (1U)
#define NETC_F2_COMMON_ISCAPR_ISQG_WIDTH         (1U)
#define NETC_F2_COMMON_ISCAPR_ISQG(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_ISQG_SHIFT)) & NETC_F2_COMMON_ISCAPR_ISQG_MASK)

#define NETC_F2_COMMON_ISCAPR_SG_MASK            (0x8U)
#define NETC_F2_COMMON_ISCAPR_SG_SHIFT           (3U)
#define NETC_F2_COMMON_ISCAPR_SG_WIDTH           (1U)
#define NETC_F2_COMMON_ISCAPR_SG(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_SG_SHIFT)) & NETC_F2_COMMON_ISCAPR_SG_MASK)

#define NETC_F2_COMMON_ISCAPR_RP_MASK            (0x10U)
#define NETC_F2_COMMON_ISCAPR_RP_SHIFT           (4U)
#define NETC_F2_COMMON_ISCAPR_RP_WIDTH           (1U)
#define NETC_F2_COMMON_ISCAPR_RP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_RP_SHIFT)) & NETC_F2_COMMON_ISCAPR_RP_MASK)

#define NETC_F2_COMMON_ISCAPR_MAXSDU_MASK        (0x20U)
#define NETC_F2_COMMON_ISCAPR_MAXSDU_SHIFT       (5U)
#define NETC_F2_COMMON_ISCAPR_MAXSDU_WIDTH       (1U)
#define NETC_F2_COMMON_ISCAPR_MAXSDU(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_MAXSDU_SHIFT)) & NETC_F2_COMMON_ISCAPR_MAXSDU_MASK)

#define NETC_F2_COMMON_ISCAPR_FWD_MASK           (0x200U)
#define NETC_F2_COMMON_ISCAPR_FWD_SHIFT          (9U)
#define NETC_F2_COMMON_ISCAPR_FWD_WIDTH          (1U)
#define NETC_F2_COMMON_ISCAPR_FWD(x)             (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_FWD_SHIFT)) & NETC_F2_COMMON_ISCAPR_FWD_MASK)

#define NETC_F2_COMMON_ISCAPR_ET_MASK            (0x400U)
#define NETC_F2_COMMON_ISCAPR_ET_SHIFT           (10U)
#define NETC_F2_COMMON_ISCAPR_ET_WIDTH           (1U)
#define NETC_F2_COMMON_ISCAPR_ET(x)              (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISCAPR_ET_SHIFT)) & NETC_F2_COMMON_ISCAPR_ET_MASK)
/*! @} */

/*! @name ISITCAPR - Ingress stream index table capability register */
/*! @{ */

#define NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ISITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ISITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ISITCAPR_ACCESS_METH(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ISITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ISITMAR - Ingress stream index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_ISITMAR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_ISITMAR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_ISITMAR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_ISITMAR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_ISITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ISITOR - Ingress stream index table operational register */
/*! @{ */

#define NETC_F2_COMMON_ISITOR_NUM_ENTRIES_MASK   (0xFFFFU)
#define NETC_F2_COMMON_ISITOR_NUM_ENTRIES_SHIFT  (0U)
#define NETC_F2_COMMON_ISITOR_NUM_ENTRIES_WIDTH  (16U)
#define NETC_F2_COMMON_ISITOR_NUM_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name ISQGITCAPR - Ingress sequence generation index table capability register */
/*! @{ */

#define NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISQGITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ISQGITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ISQGITMAR - Ingress sequence generation index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_ISQGITMAR_NUM_WORDS_MASK  (0x1FFFU)
#define NETC_F2_COMMON_ISQGITMAR_NUM_WORDS_SHIFT (0U)
#define NETC_F2_COMMON_ISQGITMAR_NUM_WORDS_WIDTH (13U)
#define NETC_F2_COMMON_ISQGITMAR_NUM_WORDS(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISQGITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_ISQGITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ISQGITOR - Ingress sequence generation index table operational register */
/*! @{ */

#define NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISQGITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name SGCAPR - Stream gate capability register */
/*! @{ */

#define NETC_F2_COMMON_SGCAPR_GLC_AO_MASK        (0x1U)
#define NETC_F2_COMMON_SGCAPR_GLC_AO_SHIFT       (0U)
#define NETC_F2_COMMON_SGCAPR_GLC_AO_WIDTH       (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_AO(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCAPR_GLC_AO_SHIFT)) & NETC_F2_COMMON_SGCAPR_GLC_AO_MASK)

#define NETC_F2_COMMON_SGCAPR_GLC_GC_MASK        (0x2U)
#define NETC_F2_COMMON_SGCAPR_GLC_GC_SHIFT       (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_GC_WIDTH       (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_GC(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCAPR_GLC_GC_SHIFT)) & NETC_F2_COMMON_SGCAPR_GLC_GC_MASK)

#define NETC_F2_COMMON_SGCAPR_GLC_IO_MASK        (0x4U)
#define NETC_F2_COMMON_SGCAPR_GLC_IO_SHIFT       (2U)
#define NETC_F2_COMMON_SGCAPR_GLC_IO_WIDTH       (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_IO(x)          (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCAPR_GLC_IO_SHIFT)) & NETC_F2_COMMON_SGCAPR_GLC_IO_MASK)

#define NETC_F2_COMMON_SGCAPR_GLC_IPV_MASK       (0x8U)
#define NETC_F2_COMMON_SGCAPR_GLC_IPV_SHIFT      (3U)
#define NETC_F2_COMMON_SGCAPR_GLC_IPV_WIDTH      (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_IPV(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCAPR_GLC_IPV_SHIFT)) & NETC_F2_COMMON_SGCAPR_GLC_IPV_MASK)

#define NETC_F2_COMMON_SGCAPR_GLC_CTD_MASK       (0x10U)
#define NETC_F2_COMMON_SGCAPR_GLC_CTD_SHIFT      (4U)
#define NETC_F2_COMMON_SGCAPR_GLC_CTD_WIDTH      (1U)
#define NETC_F2_COMMON_SGCAPR_GLC_CTD(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCAPR_GLC_CTD_SHIFT)) & NETC_F2_COMMON_SGCAPR_GLC_CTD_MASK)
/*! @} */

/*! @name SGIITCAPR - Stream gate instance index table capability register */
/*! @{ */

#define NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_SGIITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_SGIITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_SGIITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_SGIITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_SGIITCAPR_ACCESS_METH(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGIITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_SGIITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name SGIITMAR - Stream gate instance index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_SGIITMAR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_SGIITMAR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_SGIITMAR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_SGIITMAR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGIITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_SGIITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SGIITOR - Stream gate instance index table operational register */
/*! @{ */

#define NETC_F2_COMMON_SGIITOR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_COMMON_SGIITOR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_SGIITOR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_SGIITOR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGIITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_SGIITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name SGCLITCAPR - Stream gate control list index table capability register */
/*! @{ */

#define NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS_MASK (0xFFFFU)
#define NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS_SHIFT (0U)
#define NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS_WIDTH (16U)
#define NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_SGCLITCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_SGCLITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name SGCLITMAR - Stream gate control list index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_SGCLITMAR_NUM_WORDS_MASK  (0xFFFFU)
#define NETC_F2_COMMON_SGCLITMAR_NUM_WORDS_SHIFT (0U)
#define NETC_F2_COMMON_SGCLITMAR_NUM_WORDS_WIDTH (16U)
#define NETC_F2_COMMON_SGCLITMAR_NUM_WORDS(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCLITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_SGCLITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SGCLTMOR - Stream gate control list table memory operational register */
/*! @{ */

#define NETC_F2_COMMON_SGCLTMOR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_SGCLTMOR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_SGCLTMOR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_SGCLTMOR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_SGCLTMOR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_SGCLTMOR_NUM_WORDS_MASK)
/*! @} */

/*! @name FMICAPR - Frame modification ingress capability register */
/*! @{ */

#define NETC_F2_COMMON_FMICAPR_L2_ACT_MASK       (0xFFU)
#define NETC_F2_COMMON_FMICAPR_L2_ACT_SHIFT      (0U)
#define NETC_F2_COMMON_FMICAPR_L2_ACT_WIDTH      (8U)
#define NETC_F2_COMMON_FMICAPR_L2_ACT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMICAPR_L2_ACT_SHIFT)) & NETC_F2_COMMON_FMICAPR_L2_ACT_MASK)
/*! @} */

/*! @name FMECAPR - Frame modification egress capability register */
/*! @{ */

#define NETC_F2_COMMON_FMECAPR_L2_ACT_MASK       (0xFFU)
#define NETC_F2_COMMON_FMECAPR_L2_ACT_SHIFT      (0U)
#define NETC_F2_COMMON_FMECAPR_L2_ACT_WIDTH      (8U)
#define NETC_F2_COMMON_FMECAPR_L2_ACT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMECAPR_L2_ACT_SHIFT)) & NETC_F2_COMMON_FMECAPR_L2_ACT_MASK)

#define NETC_F2_COMMON_FMECAPR_L3_ACT_MASK       (0xFF0000U)
#define NETC_F2_COMMON_FMECAPR_L3_ACT_SHIFT      (16U)
#define NETC_F2_COMMON_FMECAPR_L3_ACT_WIDTH      (8U)
#define NETC_F2_COMMON_FMECAPR_L3_ACT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMECAPR_L3_ACT_SHIFT)) & NETC_F2_COMMON_FMECAPR_L3_ACT_MASK)
/*! @} */

/*! @name FMITCAPR - Frame modification index table capability register */
/*! @{ */

#define NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES_MASK (0x1FFFU)
#define NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES_WIDTH (13U)
#define NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_FMITCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_FMITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_FMITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_FMITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_FMITCAPR_ACCESS_METH(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_FMITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name FMITMAR - Frame modification index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_FMITMAR_NUM_WORDS_MASK    (0x1FFFU)
#define NETC_F2_COMMON_FMITMAR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_FMITMAR_NUM_WORDS_WIDTH   (13U)
#define NETC_F2_COMMON_FMITMAR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_FMITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name FMITOR - Frame modification index table operational register */
/*! @{ */

#define NETC_F2_COMMON_FMITOR_NUM_ENTRIES_MASK   (0x1FFFU)
#define NETC_F2_COMMON_FMITOR_NUM_ENTRIES_SHIFT  (0U)
#define NETC_F2_COMMON_FMITOR_NUM_ENTRIES_WIDTH  (13U)
#define NETC_F2_COMMON_FMITOR_NUM_ENTRIES(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMITOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_FMITOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name FMDITCAPR - Frame modification data index table capability register */
/*! @{ */

#define NETC_F2_COMMON_FMDITCAPR_NUM_WORDS_MASK  (0xFFFFU)
#define NETC_F2_COMMON_FMDITCAPR_NUM_WORDS_SHIFT (0U)
#define NETC_F2_COMMON_FMDITCAPR_NUM_WORDS_WIDTH (16U)
#define NETC_F2_COMMON_FMDITCAPR_NUM_WORDS(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMDITCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_FMDITCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_FMDITCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_FMDITCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_FMDITCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_FMDITCAPR_ACCESS_METH(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMDITCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_FMDITCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name FMDITMAR - Frame modification data index table memory allocation register */
/*! @{ */

#define NETC_F2_COMMON_FMDITMAR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_FMDITMAR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_FMDITMAR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_FMDITMAR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_FMDITMAR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_FMDITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ETCAPR - Egress treatment capability register */
/*! @{ */

#define NETC_F2_COMMON_ETCAPR_ESQR_MASK          (0x1U)
#define NETC_F2_COMMON_ETCAPR_ESQR_SHIFT         (0U)
#define NETC_F2_COMMON_ETCAPR_ESQR_WIDTH         (1U)
#define NETC_F2_COMMON_ETCAPR_ESQR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ETCAPR_ESQR_SHIFT)) & NETC_F2_COMMON_ETCAPR_ESQR_MASK)
/*! @} */

/*! @name ETTCAPR - Egress treatment table capability register */
/*! @{ */

#define NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ETTCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ETTCAPR_ACCESS_METH_MASK  (0xF00000U)
#define NETC_F2_COMMON_ETTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ETTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ETTCAPR_ACCESS_METH(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ETTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ETTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ETTOR - Egress treatment table operational register */
/*! @{ */

#define NETC_F2_COMMON_ETTOR_NUM_ENTRIES_MASK    (0xFFFFU)
#define NETC_F2_COMMON_ETTOR_NUM_ENTRIES_SHIFT   (0U)
#define NETC_F2_COMMON_ETTOR_NUM_ENTRIES_WIDTH   (16U)
#define NETC_F2_COMMON_ETTOR_NUM_ENTRIES(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ETTOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ETTOR_NUM_ENTRIES_MASK)
/*! @} */

/*! @name TGSTCAPR - Time gate scheduling table capability register */
/*! @{ */

#define NETC_F2_COMMON_TGSTCAPR_NUM_WORDS_MASK   (0xFFFFU)
#define NETC_F2_COMMON_TGSTCAPR_NUM_WORDS_SHIFT  (0U)
#define NETC_F2_COMMON_TGSTCAPR_NUM_WORDS_WIDTH  (16U)
#define NETC_F2_COMMON_TGSTCAPR_NUM_WORDS(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TGSTCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_TGSTCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_TGSTCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_TGSTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_TGSTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_TGSTCAPR_ACCESS_METH(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TGSTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_TGSTCAPR_ACCESS_METH_MASK)

#define NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN_MASK (0x3000000U)
#define NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN_SHIFT (24U)
#define NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN_WIDTH (2U)
#define NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN(x)   (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN_SHIFT)) & NETC_F2_COMMON_TGSTCAPR_MAX_GCL_LEN_MASK)
/*! @} */

/*! @name TGSTMOR - Time gate scheduling table memory operation register */
/*! @{ */

#define NETC_F2_COMMON_TGSTMOR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_TGSTMOR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_TGSTMOR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_TGSTMOR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_TGSTMOR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_TGSTMOR_NUM_WORDS_MASK)
/*! @} */

/*! @name ESQRCAPR - Egress sequence recovery capability register */
/*! @{ */

#define NETC_F2_COMMON_ESQRCAPR_SQR_TYPE_MASK    (0x3U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_TYPE_SHIFT   (0U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_TYPE_WIDTH   (2U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_TYPE(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ESQRCAPR_SQR_TYPE_SHIFT)) & NETC_F2_COMMON_ESQRCAPR_SQR_TYPE_MASK)

#define NETC_F2_COMMON_ESQRCAPR_SQR_ALG_MASK     (0xCU)
#define NETC_F2_COMMON_ESQRCAPR_SQR_ALG_SHIFT    (2U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_ALG_WIDTH    (2U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_ALG(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ESQRCAPR_SQR_ALG_SHIFT)) & NETC_F2_COMMON_ESQRCAPR_SQR_ALG_MASK)

#define NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL_MASK  (0x700U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL_SHIFT (8U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL_WIDTH (3U)
#define NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL_SHIFT)) & NETC_F2_COMMON_ESQRCAPR_SQR_MAX_HL_MASK)
/*! @} */

/*! @name ESQRTCAPR - Egress sequence recovery table capability register */
/*! @{ */

#define NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ESQRTCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ESQRTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ECTCAPR - Egress counter table capability register */
/*! @{ */

#define NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ECTCAPR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ECTCAPR_ACCESS_METH_MASK  (0xF00000U)
#define NETC_F2_COMMON_ECTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ECTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ECTCAPR_ACCESS_METH(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ECTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ECTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name HTMCAPR - Hash table memory capability register */
/*! @{ */

#define NETC_F2_COMMON_HTMCAPR_NUM_WORDS_MASK    (0xFFFFU)
#define NETC_F2_COMMON_HTMCAPR_NUM_WORDS_SHIFT   (0U)
#define NETC_F2_COMMON_HTMCAPR_NUM_WORDS_WIDTH   (16U)
#define NETC_F2_COMMON_HTMCAPR_NUM_WORDS(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_HTMCAPR_NUM_WORDS_SHIFT)) & NETC_F2_COMMON_HTMCAPR_NUM_WORDS_MASK)

#define NETC_F2_COMMON_HTMCAPR_WORD_SIZE_MASK    (0x30000000U)
#define NETC_F2_COMMON_HTMCAPR_WORD_SIZE_SHIFT   (28U)
#define NETC_F2_COMMON_HTMCAPR_WORD_SIZE_WIDTH   (2U)
#define NETC_F2_COMMON_HTMCAPR_WORD_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_HTMCAPR_WORD_SIZE_SHIFT)) & NETC_F2_COMMON_HTMCAPR_WORD_SIZE_MASK)

#define NETC_F2_COMMON_HTMCAPR_MLOC_MASK         (0xC0000000U)
#define NETC_F2_COMMON_HTMCAPR_MLOC_SHIFT        (30U)
#define NETC_F2_COMMON_HTMCAPR_MLOC_WIDTH        (2U)
#define NETC_F2_COMMON_HTMCAPR_MLOC(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_HTMCAPR_MLOC_SHIFT)) & NETC_F2_COMMON_HTMCAPR_MLOC_MASK)
/*! @} */

/*! @name HTMOR - Hash table memory operational register */
/*! @{ */

#define NETC_F2_COMMON_HTMOR_AMOUNT_MASK         (0xFFFFU)
#define NETC_F2_COMMON_HTMOR_AMOUNT_SHIFT        (0U)
#define NETC_F2_COMMON_HTMOR_AMOUNT_WIDTH        (16U)
#define NETC_F2_COMMON_HTMOR_AMOUNT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_HTMOR_AMOUNT_SHIFT)) & NETC_F2_COMMON_HTMOR_AMOUNT_MASK)

#define NETC_F2_COMMON_HTMOR_WATERMARK_MASK      (0xFFFF0000U)
#define NETC_F2_COMMON_HTMOR_WATERMARK_SHIFT     (16U)
#define NETC_F2_COMMON_HTMOR_WATERMARK_WIDTH     (16U)
#define NETC_F2_COMMON_HTMOR_WATERMARK(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_HTMOR_WATERMARK_SHIFT)) & NETC_F2_COMMON_HTMOR_WATERMARK_MASK)
/*! @} */

/*! @name ISIDCAPR - Ingress stream identification capability register */
/*! @{ */

#define NETC_F2_COMMON_ISIDCAPR_NUM_KC_MASK      (0x3U)
#define NETC_F2_COMMON_ISIDCAPR_NUM_KC_SHIFT     (0U)
#define NETC_F2_COMMON_ISIDCAPR_NUM_KC_WIDTH     (2U)
#define NETC_F2_COMMON_ISIDCAPR_NUM_KC(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDCAPR_NUM_KC_SHIFT)) & NETC_F2_COMMON_ISIDCAPR_NUM_KC_MASK)

#define NETC_F2_COMMON_ISIDCAPR_NUM_PF_MASK      (0x1CU)
#define NETC_F2_COMMON_ISIDCAPR_NUM_PF_SHIFT     (2U)
#define NETC_F2_COMMON_ISIDCAPR_NUM_PF_WIDTH     (3U)
#define NETC_F2_COMMON_ISIDCAPR_NUM_PF(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDCAPR_NUM_PF_SHIFT)) & NETC_F2_COMMON_ISIDCAPR_NUM_PF_MASK)

#define NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE_MASK   (0x1F00U)
#define NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE_SHIFT  (8U)
#define NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE_WIDTH  (5U)
#define NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE(x)     (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE_SHIFT)) & NETC_F2_COMMON_ISIDCAPR_MAX_KSIZE_MASK)

#define NETC_F2_COMMON_ISIDCAPR_UFT_MASK         (0x10000U)
#define NETC_F2_COMMON_ISIDCAPR_UFT_SHIFT        (16U)
#define NETC_F2_COMMON_ISIDCAPR_UFT_WIDTH        (1U)
#define NETC_F2_COMMON_ISIDCAPR_UFT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDCAPR_UFT_SHIFT)) & NETC_F2_COMMON_ISIDCAPR_UFT_MASK)

#define NETC_F2_COMMON_ISIDCAPR_ETHFT_MASK       (0x20000U)
#define NETC_F2_COMMON_ISIDCAPR_ETHFT_SHIFT      (17U)
#define NETC_F2_COMMON_ISIDCAPR_ETHFT_WIDTH      (1U)
#define NETC_F2_COMMON_ISIDCAPR_ETHFT(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDCAPR_ETHFT_SHIFT)) & NETC_F2_COMMON_ISIDCAPR_ETHFT_MASK)
/*! @} */

/*! @name ISIDHTCAPR - Ingress stream identification hash table capability register */
/*! @{ */

#define NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ISIDHTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ISIDKC0OR - Ingress stream identification key construction 0 operational register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISIDKC0OR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISIDKC0OR_EN_MASK         (0x80000000U)
#define NETC_F2_COMMON_ISIDKC0OR_EN_SHIFT        (31U)
#define NETC_F2_COMMON_ISIDKC0OR_EN_WIDTH        (1U)
#define NETC_F2_COMMON_ISIDKC0OR_EN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0OR_EN_SHIFT)) & NETC_F2_COMMON_ISIDKC0OR_EN_MASK)
/*! @} */

/*! @name ISIDKC0CR0 - Ingress stream identification key construction 0 configuration register 0 */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0CR0_VALID_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC0CR0_VALID_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC0CR0_VALID_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_VALID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_VALID_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_VALID_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_PORTP_MASK     (0x2U)
#define NETC_F2_COMMON_ISIDKC0CR0_PORTP_SHIFT    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_PORTP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_PORTP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_PORTP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_PORTP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_SPMP_MASK      (0x4U)
#define NETC_F2_COMMON_ISIDKC0CR0_SPMP_SHIFT     (2U)
#define NETC_F2_COMMON_ISIDKC0CR0_SPMP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_SPMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_SPMP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_SPMP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_DMACP_MASK     (0x8U)
#define NETC_F2_COMMON_ISIDKC0CR0_DMACP_SHIFT    (3U)
#define NETC_F2_COMMON_ISIDKC0CR0_DMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_DMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_DMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_DMACP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_SMACP_MASK     (0x10U)
#define NETC_F2_COMMON_ISIDKC0CR0_SMACP_SHIFT    (4U)
#define NETC_F2_COMMON_ISIDKC0CR0_SMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_SMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_SMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_SMACP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_OVIDP_MASK     (0x20U)
#define NETC_F2_COMMON_ISIDKC0CR0_OVIDP_SHIFT    (5U)
#define NETC_F2_COMMON_ISIDKC0CR0_OVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_OVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_OVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_OVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_OPCPP_MASK     (0x40U)
#define NETC_F2_COMMON_ISIDKC0CR0_OPCPP_SHIFT    (6U)
#define NETC_F2_COMMON_ISIDKC0CR0_OPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_OPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_OPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_OPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_IVIDP_MASK     (0x80U)
#define NETC_F2_COMMON_ISIDKC0CR0_IVIDP_SHIFT    (7U)
#define NETC_F2_COMMON_ISIDKC0CR0_IVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_IVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_IVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_IVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_IPCPP_MASK     (0x100U)
#define NETC_F2_COMMON_ISIDKC0CR0_IPCPP_SHIFT    (8U)
#define NETC_F2_COMMON_ISIDKC0CR0_IPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_IPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_IPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_IPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_SQTP_MASK      (0x200U)
#define NETC_F2_COMMON_ISIDKC0CR0_SQTP_SHIFT     (9U)
#define NETC_F2_COMMON_ISIDKC0CR0_SQTP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_SQTP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_SQTP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_SQTP_MASK)

#define NETC_F2_COMMON_ISIDKC0CR0_ETP_MASK       (0x400U)
#define NETC_F2_COMMON_ISIDKC0CR0_ETP_SHIFT      (10U)
#define NETC_F2_COMMON_ISIDKC0CR0_ETP_WIDTH      (1U)
#define NETC_F2_COMMON_ISIDKC0CR0_ETP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0CR0_ETP_SHIFT)) & NETC_F2_COMMON_ISIDKC0CR0_ETP_MASK)
/*! @} */

/*! @name ISIDKC0PF0CR - Ingress stream identification key construction 0 payload field 0 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0PF0CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF0CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF0CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF0CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF0CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF0CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF0CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC0PF1CR - Ingress stream identification key construction 0 payload field 1 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0PF1CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF1CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF1CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF1CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF1CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF1CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF1CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC0PF2CR - Ingress stream identification key construction 0 payload field 2 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0PF2CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF2CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF2CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF2CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF2CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF2CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF2CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC0PF3CR - Ingress stream identification key construction 0 payload field 3 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC0PF3CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF3CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF3CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF3CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF3CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF3CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC0PF3CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC1OR - Ingress stream identification key construction 1 operational register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISIDKC1OR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISIDKC1OR_EN_MASK         (0x80000000U)
#define NETC_F2_COMMON_ISIDKC1OR_EN_SHIFT        (31U)
#define NETC_F2_COMMON_ISIDKC1OR_EN_WIDTH        (1U)
#define NETC_F2_COMMON_ISIDKC1OR_EN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1OR_EN_SHIFT)) & NETC_F2_COMMON_ISIDKC1OR_EN_MASK)
/*! @} */

/*! @name ISIDKC1CR0 - Ingress stream identification key construction 1 configuration register 0 */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1CR0_VALID_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC1CR0_VALID_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC1CR0_VALID_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_VALID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_VALID_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_VALID_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_PORTP_MASK     (0x2U)
#define NETC_F2_COMMON_ISIDKC1CR0_PORTP_SHIFT    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_PORTP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_PORTP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_PORTP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_PORTP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_SPMP_MASK      (0x4U)
#define NETC_F2_COMMON_ISIDKC1CR0_SPMP_SHIFT     (2U)
#define NETC_F2_COMMON_ISIDKC1CR0_SPMP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_SPMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_SPMP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_SPMP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_DMACP_MASK     (0x8U)
#define NETC_F2_COMMON_ISIDKC1CR0_DMACP_SHIFT    (3U)
#define NETC_F2_COMMON_ISIDKC1CR0_DMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_DMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_DMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_DMACP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_SMACP_MASK     (0x10U)
#define NETC_F2_COMMON_ISIDKC1CR0_SMACP_SHIFT    (4U)
#define NETC_F2_COMMON_ISIDKC1CR0_SMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_SMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_SMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_SMACP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_OVIDP_MASK     (0x20U)
#define NETC_F2_COMMON_ISIDKC1CR0_OVIDP_SHIFT    (5U)
#define NETC_F2_COMMON_ISIDKC1CR0_OVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_OVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_OVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_OVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_OPCPP_MASK     (0x40U)
#define NETC_F2_COMMON_ISIDKC1CR0_OPCPP_SHIFT    (6U)
#define NETC_F2_COMMON_ISIDKC1CR0_OPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_OPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_OPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_OPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_IVIDP_MASK     (0x80U)
#define NETC_F2_COMMON_ISIDKC1CR0_IVIDP_SHIFT    (7U)
#define NETC_F2_COMMON_ISIDKC1CR0_IVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_IVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_IVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_IVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_IPCPP_MASK     (0x100U)
#define NETC_F2_COMMON_ISIDKC1CR0_IPCPP_SHIFT    (8U)
#define NETC_F2_COMMON_ISIDKC1CR0_IPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_IPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_IPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_IPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_SQTP_MASK      (0x200U)
#define NETC_F2_COMMON_ISIDKC1CR0_SQTP_SHIFT     (9U)
#define NETC_F2_COMMON_ISIDKC1CR0_SQTP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_SQTP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_SQTP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_SQTP_MASK)

#define NETC_F2_COMMON_ISIDKC1CR0_ETP_MASK       (0x400U)
#define NETC_F2_COMMON_ISIDKC1CR0_ETP_SHIFT      (10U)
#define NETC_F2_COMMON_ISIDKC1CR0_ETP_WIDTH      (1U)
#define NETC_F2_COMMON_ISIDKC1CR0_ETP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1CR0_ETP_SHIFT)) & NETC_F2_COMMON_ISIDKC1CR0_ETP_MASK)
/*! @} */

/*! @name ISIDKC1PF0CR - Ingress stream identification key construction 1 payload field 0 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1PF0CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF0CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF0CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF0CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF0CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF0CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF0CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC1PF1CR - Ingress stream identification key construction 1 payload field 1 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1PF1CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF1CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF1CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF1CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF1CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF1CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF1CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC1PF2CR - Ingress stream identification key construction 1 payload field 2 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1PF2CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF2CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF2CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF2CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF2CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF2CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF2CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC1PF3CR - Ingress stream identification key construction 1 payload field 3 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC1PF3CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF3CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF3CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF3CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF3CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF3CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC1PF3CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC2OR - Ingress stream identification key construction 2 operational register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISIDKC2OR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISIDKC2OR_EN_MASK         (0x80000000U)
#define NETC_F2_COMMON_ISIDKC2OR_EN_SHIFT        (31U)
#define NETC_F2_COMMON_ISIDKC2OR_EN_WIDTH        (1U)
#define NETC_F2_COMMON_ISIDKC2OR_EN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2OR_EN_SHIFT)) & NETC_F2_COMMON_ISIDKC2OR_EN_MASK)
/*! @} */

/*! @name ISIDKC2CR0 - Ingress stream identification key construction 2 configuration register 0 */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2CR0_VALID_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC2CR0_VALID_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC2CR0_VALID_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_VALID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_VALID_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_VALID_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_PORTP_MASK     (0x2U)
#define NETC_F2_COMMON_ISIDKC2CR0_PORTP_SHIFT    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_PORTP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_PORTP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_PORTP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_PORTP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_SPMP_MASK      (0x4U)
#define NETC_F2_COMMON_ISIDKC2CR0_SPMP_SHIFT     (2U)
#define NETC_F2_COMMON_ISIDKC2CR0_SPMP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_SPMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_SPMP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_SPMP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_DMACP_MASK     (0x8U)
#define NETC_F2_COMMON_ISIDKC2CR0_DMACP_SHIFT    (3U)
#define NETC_F2_COMMON_ISIDKC2CR0_DMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_DMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_DMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_DMACP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_SMACP_MASK     (0x10U)
#define NETC_F2_COMMON_ISIDKC2CR0_SMACP_SHIFT    (4U)
#define NETC_F2_COMMON_ISIDKC2CR0_SMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_SMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_SMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_SMACP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_OVIDP_MASK     (0x20U)
#define NETC_F2_COMMON_ISIDKC2CR0_OVIDP_SHIFT    (5U)
#define NETC_F2_COMMON_ISIDKC2CR0_OVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_OVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_OVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_OVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_OPCPP_MASK     (0x40U)
#define NETC_F2_COMMON_ISIDKC2CR0_OPCPP_SHIFT    (6U)
#define NETC_F2_COMMON_ISIDKC2CR0_OPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_OPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_OPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_OPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_IVIDP_MASK     (0x80U)
#define NETC_F2_COMMON_ISIDKC2CR0_IVIDP_SHIFT    (7U)
#define NETC_F2_COMMON_ISIDKC2CR0_IVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_IVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_IVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_IVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_IPCPP_MASK     (0x100U)
#define NETC_F2_COMMON_ISIDKC2CR0_IPCPP_SHIFT    (8U)
#define NETC_F2_COMMON_ISIDKC2CR0_IPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_IPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_IPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_IPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_SQTP_MASK      (0x200U)
#define NETC_F2_COMMON_ISIDKC2CR0_SQTP_SHIFT     (9U)
#define NETC_F2_COMMON_ISIDKC2CR0_SQTP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_SQTP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_SQTP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_SQTP_MASK)

#define NETC_F2_COMMON_ISIDKC2CR0_ETP_MASK       (0x400U)
#define NETC_F2_COMMON_ISIDKC2CR0_ETP_SHIFT      (10U)
#define NETC_F2_COMMON_ISIDKC2CR0_ETP_WIDTH      (1U)
#define NETC_F2_COMMON_ISIDKC2CR0_ETP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2CR0_ETP_SHIFT)) & NETC_F2_COMMON_ISIDKC2CR0_ETP_MASK)
/*! @} */

/*! @name ISIDKC2PF0CR - Ingress stream identification key construction 2 payload field 0 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2PF0CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF0CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF0CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF0CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF0CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF0CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF0CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC2PF1CR - Ingress stream identification key construction 2 payload field 1 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2PF1CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF1CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF1CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF1CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF1CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF1CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF1CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC2PF2CR - Ingress stream identification key construction 2 payload field 2 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2PF2CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF2CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF2CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF2CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF2CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF2CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF2CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC2PF3CR - Ingress stream identification key construction 2 payload field 3 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC2PF3CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF3CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF3CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF3CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF3CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF3CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC2PF3CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC3OR - Ingress stream identification key construction 3 operational register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES_MASK (0xFFFFU)
#define NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISIDKC3OR_NUM_ENTRIES_MASK)

#define NETC_F2_COMMON_ISIDKC3OR_EN_MASK         (0x80000000U)
#define NETC_F2_COMMON_ISIDKC3OR_EN_SHIFT        (31U)
#define NETC_F2_COMMON_ISIDKC3OR_EN_WIDTH        (1U)
#define NETC_F2_COMMON_ISIDKC3OR_EN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3OR_EN_SHIFT)) & NETC_F2_COMMON_ISIDKC3OR_EN_MASK)
/*! @} */

/*! @name ISIDKC3CR0 - Ingress stream identification key construction 3 configuration register 0 */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3CR0_VALID_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC3CR0_VALID_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC3CR0_VALID_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_VALID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_VALID_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_VALID_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_PORTP_MASK     (0x2U)
#define NETC_F2_COMMON_ISIDKC3CR0_PORTP_SHIFT    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_PORTP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_PORTP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_PORTP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_PORTP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_SPMP_MASK      (0x4U)
#define NETC_F2_COMMON_ISIDKC3CR0_SPMP_SHIFT     (2U)
#define NETC_F2_COMMON_ISIDKC3CR0_SPMP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_SPMP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_SPMP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_SPMP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_DMACP_MASK     (0x8U)
#define NETC_F2_COMMON_ISIDKC3CR0_DMACP_SHIFT    (3U)
#define NETC_F2_COMMON_ISIDKC3CR0_DMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_DMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_DMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_DMACP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_SMACP_MASK     (0x10U)
#define NETC_F2_COMMON_ISIDKC3CR0_SMACP_SHIFT    (4U)
#define NETC_F2_COMMON_ISIDKC3CR0_SMACP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_SMACP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_SMACP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_SMACP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_OVIDP_MASK     (0x20U)
#define NETC_F2_COMMON_ISIDKC3CR0_OVIDP_SHIFT    (5U)
#define NETC_F2_COMMON_ISIDKC3CR0_OVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_OVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_OVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_OVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_OPCPP_MASK     (0x40U)
#define NETC_F2_COMMON_ISIDKC3CR0_OPCPP_SHIFT    (6U)
#define NETC_F2_COMMON_ISIDKC3CR0_OPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_OPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_OPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_OPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_IVIDP_MASK     (0x80U)
#define NETC_F2_COMMON_ISIDKC3CR0_IVIDP_SHIFT    (7U)
#define NETC_F2_COMMON_ISIDKC3CR0_IVIDP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_IVIDP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_IVIDP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_IVIDP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_IPCPP_MASK     (0x100U)
#define NETC_F2_COMMON_ISIDKC3CR0_IPCPP_SHIFT    (8U)
#define NETC_F2_COMMON_ISIDKC3CR0_IPCPP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_IPCPP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_IPCPP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_IPCPP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_SQTP_MASK      (0x200U)
#define NETC_F2_COMMON_ISIDKC3CR0_SQTP_SHIFT     (9U)
#define NETC_F2_COMMON_ISIDKC3CR0_SQTP_WIDTH     (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_SQTP(x)        (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_SQTP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_SQTP_MASK)

#define NETC_F2_COMMON_ISIDKC3CR0_ETP_MASK       (0x400U)
#define NETC_F2_COMMON_ISIDKC3CR0_ETP_SHIFT      (10U)
#define NETC_F2_COMMON_ISIDKC3CR0_ETP_WIDTH      (1U)
#define NETC_F2_COMMON_ISIDKC3CR0_ETP(x)         (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3CR0_ETP_SHIFT)) & NETC_F2_COMMON_ISIDKC3CR0_ETP_MASK)
/*! @} */

/*! @name ISIDKC3PF0CR - Ingress stream identification key construction 3 payload field 0 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3PF0CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF0CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF0CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF0CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF0CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF0CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF0CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC3PF1CR - Ingress stream identification key construction 3 payload field 1 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3PF1CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF1CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF1CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF1CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF1CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF1CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF1CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC3PF2CR - Ingress stream identification key construction 3 payload field 2 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3PF2CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF2CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF2CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF2CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF2CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF2CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF2CR_LBMASK_MASK)
/*! @} */

/*! @name ISIDKC3PF3CR - Ingress stream identification key construction 3 payload field 3 configuration register */
/*! @{ */

#define NETC_F2_COMMON_ISIDKC3PF3CR_PFP_MASK     (0x1U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_PFP_SHIFT    (0U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_PFP_WIDTH    (1U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_PFP(x)       (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF3CR_PFP_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF3CR_PFP_MASK)

#define NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES_MASK (0x1EU)
#define NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES_SHIFT (1U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES_WIDTH (4U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF3CR_NUM_BYTES_MASK)

#define NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET_MASK (0x7F00U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET_SHIFT (8U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET_WIDTH (7U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET(x) (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF3CR_BYTE_OFFSET_MASK)

#define NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK_MASK  (0x70000U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK_SHIFT (16U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF3CR_FBMASK_MASK)

#define NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK_MASK  (0x700000U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK_SHIFT (20U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK_WIDTH (3U)
#define NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK_SHIFT)) & NETC_F2_COMMON_ISIDKC3PF3CR_LBMASK_MASK)
/*! @} */

/*! @name ISFHTCAPR - Ingress stream filter hash table capability register */
/*! @{ */

#define NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH_MASK (0xF00000U)
#define NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH_SHIFT (20U)
#define NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH_WIDTH (4U)
#define NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH(x)  (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH_SHIFT)) & NETC_F2_COMMON_ISFHTCAPR_ACCESS_METH_MASK)
/*! @} */

/*! @name ISFHTOR - Ingress stream filter hash table operational register */
/*! @{ */

#define NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES_MASK  (0xFFFFU)
#define NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES_SHIFT (0U)
#define NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES_WIDTH (16U)
#define NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES(x)    (((uint32_t)(((uint32_t)(x)) << NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES_SHIFT)) & NETC_F2_COMMON_ISFHTOR_NUM_ENTRIES_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_F2_COMMON_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_F2_COMMON_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_NETC_F2_COMMON_H_) */
