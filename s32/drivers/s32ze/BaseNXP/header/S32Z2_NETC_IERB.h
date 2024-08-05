/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_NETC_IERB.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_NETC_IERB
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
#if !defined(S32Z2_NETC_IERB_H_)  /* Check if memory map has not been already included */
#define S32Z2_NETC_IERB_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- NETC_IERB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_IERB_Peripheral_Access_Layer NETC_IERB Peripheral Access Layer
 * @{
 */

/** NETC_IERB - Size of Registers Arrays */
#define NETC_IERB_HTA_NUM_COUNT                   1u
#define NETC_IERB_ARRAY_NUM_RC_COUNT              1u
#define NETC_IERB_EMDIO_PF_BOOT_LOAD_COUNT        2u
#define NETC_IERB_NUM_TMR_ARRAY_TMR_PF_BOOT_LOAD_COUNT 2u
#define NETC_IERB_NUM_TMR_ARRAY_COUNT             1u
#define NETC_IERB_CFG_SW_INST_SW_PF_BOOT_LOAD_COUNT 2u
#define NETC_IERB_CFG_SW_INST_COUNT               1u
#define NETC_IERB_CFG_ENETC_INST_ENETC_PF_BOOT_LOAD_COUNT 2u
#define NETC_IERB_CFG_ENETC_INST_COUNT            1u
#define NETC_IERB_CFG_VSI_INST_VSI_PF_BOOT_LOAD_COUNT 2u
#define NETC_IERB_CFG_VSI_INST_COUNT              7u

/** NETC_IERB - Register Layout Typedef */
typedef struct {
  __I  uint32_t CAPR0;                             /**< Capability register 0, offset: 0x0 */
  __I  uint32_t CAPR1;                             /**< Capability register 1, offset: 0x4 */
  __I  uint32_t CAPR2;                             /**< Capability register 2, offset: 0x8 */
  __I  uint32_t CAPR3;                             /**< Capability register 3, offset: 0xC */
  uint8_t RESERVED_0[16];
  __I  uint32_t CMCAPR;                            /**< Common memory capability register, offset: 0x20 */
  uint8_t RESERVED_1[12];
  __I  uint32_t IPFTMCAPR;                         /**< Ingress port filter ternary memory capability register, offset: 0x30 */
  uint8_t RESERVED_2[16];
  __I  uint32_t TGSMCAPR;                          /**< Time gate scheduling memory capability register, offset: 0x44 */
  uint8_t RESERVED_3[56];
  __IO uint32_t SMDTR;                             /**< Shared memory depletion threshold register, offset: 0x80 */
  __IO uint32_t ERSMBAR;                           /**< ENETC receive shared memory buffer allotment register, offset: 0x84 */
  uint8_t RESERVED_4[56];
  struct NETC_IERB_HTA_NUM {                       /* offset: 0xC0, array step: 0x8 */
    __IO uint32_t HTAHPCR;                           /**< HTA 0 HP configuration register, array offset: 0xC0, array step: 0x8 */
    __IO uint32_t HTALPCR;                           /**< HTA 0 LP configuration register, array offset: 0xC4, array step: 0x8 */
  } HTA_NUM[NETC_IERB_HTA_NUM_COUNT];
  uint8_t RESERVED_5[56];
  __IO uint32_t HBTMAR;                            /**< Hash bucket table memory allocation register, offset: 0x100 */
  __IO uint32_t HBTCR;                             /**< Hash bucket table configuration register, offset: 0x104 */
  __I  uint32_t GHTEMCAPR;                         /**< Guaranteed hash table entry memory capability register, offset: 0x108 */
  uint8_t RESERVED_6[100];
  __IO uint32_t NETCFLRCR;                         /**< NETC FLR configuration register, offset: 0x170 */
  uint8_t RESERVED_7[4];
  __IO uint32_t NETCCLKFR;                         /**< NETC clock period fractional register, offset: 0x178 */
  __IO uint32_t NETCCLKCR;                         /**< NETC clock configuration register, offset: 0x17C */
  __IO uint32_t SBCR;                              /**< System bus configuration register, offset: 0x180 */
  __IO uint32_t SBOTCR;                            /**< System bus outstanding transaction control register, offset: 0x184 */
  uint8_t RESERVED_8[8];
  __IO uint32_t SGLTTR;                            /**< Stream gating lag time for refresh register, offset: 0x190 */
  uint8_t RESERVED_9[108];
  struct NETC_IERB_ARRAY_NUM_RC {                  /* offset: 0x200, array step: 0x10 */
    __I  uint32_t RBCR;                              /**< Root complex 0 binding configuration register, array offset: 0x200, array step: 0x10 */
    uint8_t RESERVED_0[4];
    __IO uint32_t RCMSICAR;                          /**< Root complex 0 MSI-X cache attribute register, array offset: 0x208, array step: 0x10 */
    __IO uint32_t RCMSIAMQR;                         /**< Root complex 0 MSI access management qualifier register, array offset: 0x20C, array step: 0x10 */
  } ARRAY_NUM_RC[NETC_IERB_ARRAY_NUM_RC_COUNT];
  uint8_t RESERVED_10[240];
  __I  uint32_t EMDIOBCR;                          /**< EMDIO binding configuration register, offset: 0x300 */
  uint8_t RESERVED_11[16];
  __I  uint32_t EMDIOMCR;                          /**< EMDIO MSI-X configuration register, offset: 0x314 */
  uint8_t RESERVED_12[8];
  __IO uint32_t EMDIO_CFH_DIDVID;                  /**< EMDIO config header device ID and vendor ID register, offset: 0x320 */
  __IO uint32_t EMDIO_CFH_SIDSVID;                 /**< EMDIO config header subsystem ID and subsystem vendor ID register, offset: 0x324 */
  uint8_t RESERVED_13[32];
  __IO uint32_t EMDIOBLPR[NETC_IERB_EMDIO_PF_BOOT_LOAD_COUNT]; /**< EMDIO boot loader parameter register 0..EMDIO boot loader parameter register 1, array offset: 0x348, array step: 0x4 */
  __IO uint32_t EMDIO_CFG;                         /**< EMDIO configuration register, offset: 0x350 */
  uint8_t RESERVED_14[172];
  struct NETC_IERB_NUM_TMR_ARRAY {                 /* offset: 0x400, array step: 0x50 */
    __I  uint32_t TBCR;                              /**< Timer 0 binding configuration register, array offset: 0x400, array step: 0x50 */
    uint8_t RESERVED_0[16];
    __IO uint32_t TMCR;                              /**< Timer 0 MSI-X configuration register, array offset: 0x414, array step: 0x50 */
    uint8_t RESERVED_1[8];
    __IO uint32_t T_CFH_DIDVID;                      /**< Timer 0 config header device ID and vendor ID register, array offset: 0x420, array step: 0x50 */
    __IO uint32_t T_CFH_SIDSVID;                     /**< Timer 0 config header subsystem ID and subsystem vendor ID register, array offset: 0x424, array step: 0x50 */
    uint8_t RESERVED_2[32];
    __IO uint32_t TBLPR[NETC_IERB_NUM_TMR_ARRAY_TMR_PF_BOOT_LOAD_COUNT];   /**< Timer 0 boot loader parameter register 0..Timer 0 boot loader parameter register 1, array offset: 0x448, array step: index*0x50, index2*0x4 */
  } NUM_TMR_ARRAY[NETC_IERB_NUM_TMR_ARRAY_COUNT];
  uint8_t RESERVED_15[2992];
  __I  uint32_t L0CAPR;                            /**< Link 0 capability register, offset: 0x1000 */
  __I  uint32_t L0MCAPR;                           /**< Link 0 MAC capability register, offset: 0x1004 */
  __I  uint32_t L0IOCAPR;                          /**< Link 0 I/O capability register, offset: 0x1008 */
  uint8_t RESERVED_16[4];
  __IO uint32_t L0BCR;                             /**< Link 0 binding configuration register, offset: 0x1010 */
  __IO uint32_t L0TXBCCTR;                         /**< Link 0 transmit byte credit comfort threshold register, offset: 0x1014 */
  uint8_t RESERVED_17[8];
  __IO uint32_t L0E0MAR0;                          /**< Link 0 end 0 MAC address register 0, offset: 0x1020 */
  __IO uint32_t L0E0MAR1;                          /**< Link 0 end 0 MAC address register 1, offset: 0x1024 */
  uint8_t RESERVED_18[24];
  __I  uint32_t L1CAPR;                            /**< Link 1 capability register, offset: 0x1040 */
  __I  uint32_t L1MCAPR;                           /**< Link 1 MAC capability register, offset: 0x1044 */
  __I  uint32_t L1IOCAPR;                          /**< Link 1 I/O capability register, offset: 0x1048 */
  uint8_t RESERVED_19[4];
  __IO uint32_t L1BCR;                             /**< Link 1 binding configuration register, offset: 0x1050 */
  __IO uint32_t L1TXBCCTR;                         /**< Link 1 transmit byte credit comfort threshold register, offset: 0x1054 */
  uint8_t RESERVED_20[8];
  __IO uint32_t L1E0MAR0;                          /**< Link 1 end 0 MAC address register 0, offset: 0x1060 */
  __IO uint32_t L1E0MAR1;                          /**< Link 1 end 0 MAC address register 1, offset: 0x1064 */
  uint8_t RESERVED_21[24];
  __I  uint32_t L2CAPR;                            /**< Link 2 capability register, offset: 0x1080 */
  __I  uint32_t L2MCAPR;                           /**< Link 2 MAC capability register, offset: 0x1084 */
  uint8_t RESERVED_22[8];
  __I  uint32_t L2BCR;                             /**< Link 2 binding configuration register, offset: 0x1090 */
  __IO uint32_t L2TXBCCTR;                         /**< Link 2 transmit byte credit comfort threshold register, offset: 0x1094 */
  uint8_t RESERVED_23[8];
  __IO uint32_t L2E0MAR0;                          /**< Link 2 end 0 MAC address register 0, offset: 0x10A0 */
  __IO uint32_t L2E0MAR1;                          /**< Link 2 end 0 MAC address register 1, offset: 0x10A4 */
  __IO uint32_t L2E1MAR0;                          /**< Link 2 end 1 MAC address register 0, offset: 0x10A8 */
  __IO uint32_t L2E1MAR1;                          /**< Link 2 end 1 MAC address register 1, offset: 0x10AC */
  uint8_t RESERVED_24[3920];
  struct NETC_IERB_CFG_SW_INST {                   /* offset: 0x2000, array step: 0x21C */
    __I  uint32_t SBCR;                              /**< Switch 0 binding configuration register, array offset: 0x2000, array step: 0x21C */
    uint8_t RESERVED_0[16];
    __IO uint32_t SMCR;                              /**< Switch 0 MSI-X configuration register, array offset: 0x2014, array step: 0x21C */
    uint8_t RESERVED_1[8];
    __IO uint32_t S_CFH_DIDVID;                      /**< Switch 0 config header device ID and vendor ID register, array offset: 0x2020, array step: 0x21C */
    __IO uint32_t S_CFH_SIDSVID;                     /**< Switch 0 config header subsystem ID and subsystem vendor ID register, array offset: 0x2024, array step: 0x21C */
    uint8_t RESERVED_2[16];
    __IO uint32_t SCCAR;                             /**< Switch 0 command cache attribute register, array offset: 0x2038, array step: 0x21C */
    uint8_t RESERVED_3[4];
    __IO uint32_t SAMQR;                             /**< Switch 0 access management qualifier register, array offset: 0x2040, array step: 0x21C */
    uint8_t RESERVED_4[4];
    __IO uint32_t SBLPR[NETC_IERB_CFG_SW_INST_SW_PF_BOOT_LOAD_COUNT];   /**< Switch 0 boot loader parameter register 0..Switch 0 boot loader parameter register 1, array offset: 0x2048, array step: index*0x21C, index2*0x4 */
    uint8_t RESERVED_5[16];
    __IO uint32_t SSMBAR;                            /**< Switch 0 shared memory buffer allotment register, array offset: 0x2060, array step: 0x21C */
    uint8_t RESERVED_6[28];
    __IO uint32_t SHTMAR;                            /**< Switch 0 hash table memory allotment register, array offset: 0x2080, array step: 0x21C */
    __IO uint32_t SITMAR;                            /**< Switch 0 index table memory allocation register, array offset: 0x2084, array step: 0x21C */
    __IO uint32_t SIPFTMAR;                          /**< Switch 0 ingress port filter table memory allocation register, array offset: 0x2088, array step: 0x21C */
    uint8_t RESERVED_7[20];
    __IO uint32_t SRPITMAR;                          /**< Switch 0 rate policer index table memory allocation register, array offset: 0x20A0, array step: 0x21C */
    __IO uint32_t SISCITMAR;                         /**< Switch 0 ingress stream counter index table memory allocation register, array offset: 0x20A4, array step: 0x21C */
    __IO uint32_t SISITMAR;                          /**< Switch 0 ingress stream index table memory allocation register, array offset: 0x20A8, array step: 0x21C */
    __IO uint32_t SISQGITMAR;                        /**< Switch 0 ingress sequence generation index table memory allocation register, array offset: 0x20AC, array step: 0x21C */
    uint8_t RESERVED_8[4];
    __IO uint32_t SSGIITMAR;                         /**< Switch 0 stream gate instance index table memory allocation register, array offset: 0x20B4, array step: 0x21C */
    __IO uint32_t SSGCLITMAR;                        /**< Switch 0 stream gate control list index table memory allocation register, array offset: 0x20B8, array step: 0x21C */
    __IO uint32_t SFMITMAR;                          /**< Switch 0 frame modification index table memory allocation register, array offset: 0x20BC, array step: 0x21C */
    __IO uint32_t SFMDITMAR;                         /**< Switch 0 frame modification data index table memory allocation register, array offset: 0x20C0, array step: 0x21C */
    uint8_t RESERVED_9[44];
    __IO uint32_t STGSTAR;                           /**< Switch 0 time gate scheduling table allocation register, array offset: 0x20F0, array step: 0x21C */
    __IO uint32_t STGSLR;                            /**< Switch 0 time gate scheduling lookahead register, array offset: 0x20F4, array step: 0x21C */
    uint8_t RESERVED_10[268];
    __I  uint32_t SMPCR;                             /**< Switch 0 management port configuration register, array offset: 0x2204, array step: 0x21C */
    uint8_t RESERVED_11[8];
    __IO uint32_t SVFHTDECR0;                        /**< Switch 0 VLAN Filter (hash) table default entry configuration registers 0, array offset: 0x2210, array step: 0x21C */
    __IO uint32_t SVFHTDECR1;                        /**< Switch 0 VLAN filter hash table default entry configuration registers 1, array offset: 0x2214, array step: 0x21C */
    __IO uint32_t SVFHTDECR2;                        /**< Switch 0 VLAN filter hash table default entry configuration registers 2, array offset: 0x2218, array step: 0x21C */
  } CFG_SW_INST[NETC_IERB_CFG_SW_INST_COUNT];
  uint8_t RESERVED_25[3556];
  struct NETC_IERB_CFG_ENETC_INST {                /* offset: 0x3000, array step: 0xF8 */
    __I  uint32_t EBCR0;                             /**< ENETC 0 binding configuration register 0, array offset: 0x3000, array step: 0xF8 */
    __I  uint32_t EBCR1;                             /**< ENETC 0 binding configuration register 1, array offset: 0x3004, array step: 0xF8 */
    __I  uint32_t EBCR2;                             /**< ENETC 0 binding configuration register 2, array offset: 0x3008, array step: 0xF8 */
    uint8_t RESERVED_0[4];
    __I  uint32_t EVBCR;                             /**< ENETC 0 VSI binding configuration register, array offset: 0x3010, array step: 0xF8 */
    __IO uint32_t EMCR;                              /**< ENETC 0 MSI-X configuration register, array offset: 0x3014, array step: 0xF8 */
    uint8_t RESERVED_1[8];
    __IO uint32_t E_CFH_DIDVID;                      /**< ENETC 0 config header device ID and vendor ID register, array offset: 0x3020, array step: 0xF8 */
    __IO uint32_t E_CFH_SIDSVID;                     /**< ENETC 0 config header subsystem ID and subsystem vendor ID register, array offset: 0x3024, array step: 0xF8 */
    __IO uint32_t E_CFC_VFDID;                       /**< ENETC 0 config capability VF device ID register, array offset: 0x3028, array step: 0xF8 */
    uint8_t RESERVED_2[4];
    __IO uint32_t EBCAR;                             /**< ENETC 0 buffer cache attribute register 0, array offset: 0x3030, array step: 0xF8 */
    __IO uint32_t EMCAR;                             /**< ENETC 0 message cache attribute register, array offset: 0x3034, array step: 0xF8 */
    __IO uint32_t ECAR;                              /**< ENETC 0 command cache attribute register, array offset: 0x3038, array step: 0xF8 */
    uint8_t RESERVED_3[4];
    __IO uint32_t EAMQR;                             /**< ENETC 0 access management qualifier register, array offset: 0x3040, array step: 0xF8 */
    uint8_t RESERVED_4[4];
    __IO uint32_t EBLPR[NETC_IERB_CFG_ENETC_INST_ENETC_PF_BOOT_LOAD_COUNT];   /**< ENETC 0 boot loader parameter register 0..ENETC 0 boot loader parameter register 1, array offset: 0x3048, array step: index*0xF8, index2*0x4 */
    __IO uint32_t ERXMBER;                           /**< ENETC 0 receive memory buffer entitlement register, array offset: 0x3050, array step: 0xF8 */
    __IO uint32_t ERXMBLR;                           /**< ENETC 0 receive memory buffer limit register, array offset: 0x3054, array step: 0xF8 */
    uint8_t RESERVED_5[24];
    __IO uint32_t ETXHPTBCR;                         /**< ENETC 0 transmit high priority tier byte credit register, array offset: 0x3070, array step: 0xF8 */
    __IO uint32_t ETXLPTBCR;                         /**< ENETC 0 transmit low priority tier byte credit register, array offset: 0x3074, array step: 0xF8 */
    uint8_t RESERVED_6[8];
    __IO uint32_t EHTMAR;                            /**< ENETC 0 hash table memory allotment register, array offset: 0x3080, array step: 0xF8 */
    __IO uint32_t EITMAR;                            /**< ENETC 0 index table memory allocation register, array offset: 0x3084, array step: 0xF8 */
    __IO uint32_t EIPFTMAR;                          /**< ENETC 0 ingress port filter table memory allocation register, array offset: 0x3088, array step: 0xF8 */
    uint8_t RESERVED_7[4];
    __I  uint32_t ERTMAR;                            /**< ENETC 0 RFS ternary memory allocation register, array offset: 0x3090, array step: 0xF8 */
    uint8_t RESERVED_8[12];
    __IO uint32_t ERPITMAR;                          /**< ENETC 0 rate policer index table memory allocation register, array offset: 0x30A0, array step: 0xF8 */
    __IO uint32_t EISCITMAR;                         /**< ENETC 0 ingress stream counter index table memory allocation register, array offset: 0x30A4, array step: 0xF8 */
    __IO uint32_t EISITMAR;                          /**< ENETC 0 ingress stream index table memory allocation register, array offset: 0x30A8, array step: 0xF8 */
    uint8_t RESERVED_9[8];
    __IO uint32_t ESGIITMAR;                         /**< ENETC 0 stream gate instance index table memory allocation register, array offset: 0x30B4, array step: 0xF8 */
    __IO uint32_t ESGCLITMAR;                        /**< ENETC 0 stream gate control list index table memory allocation register, array offset: 0x30B8, array step: 0xF8 */
    uint8_t RESERVED_10[52];
    __IO uint32_t ETGSTAR;                           /**< ENETC 0 time gate scheduling table allocation register, array offset: 0x30F0, array step: 0xF8 */
    __IO uint32_t ETGSLR;                            /**< ENETC 0 time gate scheduling lookahead register, array offset: 0x30F4, array step: 0xF8 */
  } CFG_ENETC_INST[NETC_IERB_CFG_ENETC_INST_COUNT];
  uint8_t RESERVED_26[3848];
  struct NETC_IERB_CFG_VSI_INST {                  /* offset: 0x4000, array step: 0x40 */
    __IO uint32_t VAMQR;                             /**< VSI 0 access management qualifier register..VSI 6 access management qualifier register, array offset: 0x4000, array step: 0x40 */
    uint8_t RESERVED_0[4];
    __IO uint32_t VBLPR[NETC_IERB_CFG_VSI_INST_VSI_PF_BOOT_LOAD_COUNT];   /**< VSI 0 boot loader parameter register 0..VSI 6 boot loader parameter register 1, array offset: 0x4008, array step: index*0x40, index2*0x4 */
    __IO uint32_t VPMAR0;                            /**< VSI 0 primary MAC address register 0..VSI 6 primary MAC address register 0, array offset: 0x4010, array step: 0x40 */
    __IO uint32_t VPMAR1;                            /**< VSI 0 primary MAC address register 1..VSI 6 primary MAC address register 1, array offset: 0x4014, array step: 0x40 */
    uint8_t RESERVED_1[40];
  } CFG_VSI_INST[NETC_IERB_CFG_VSI_INST_COUNT];
} NETC_IERB_Type, *NETC_IERB_MemMapPtr;

/** Number of instances of the NETC_IERB module. */
#define NETC_IERB_INSTANCE_COUNT                 (1u)

/* NETC_IERB - Peripheral instance base addresses */
/** Peripheral NETC__NETC_IERB base address */
#define IP_NETC__NETC_IERB_BASE                  (0x74800000u)
/** Peripheral NETC__NETC_IERB base pointer */
#define IP_NETC__NETC_IERB                       ((NETC_IERB_Type *)IP_NETC__NETC_IERB_BASE)
/** Array initializer of NETC_IERB peripheral base addresses */
#define IP_NETC_IERB_BASE_ADDRS                  { IP_NETC__NETC_IERB_BASE }
/** Array initializer of NETC_IERB peripheral base pointers */
#define IP_NETC_IERB_BASE_PTRS                   { IP_NETC__NETC_IERB }

/* ----------------------------------------------------------------------------
   -- NETC_IERB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NETC_IERB_Register_Masks NETC_IERB Register Masks
 * @{
 */

/*! @name CAPR0 - Capability register 0 */
/*! @{ */

#define NETC_IERB_CAPR0_NUM_RC_MASK              (0xFU)
#define NETC_IERB_CAPR0_NUM_RC_SHIFT             (0U)
#define NETC_IERB_CAPR0_NUM_RC_WIDTH             (4U)
#define NETC_IERB_CAPR0_NUM_RC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_RC_SHIFT)) & NETC_IERB_CAPR0_NUM_RC_MASK)

#define NETC_IERB_CAPR0_NUM_EMDIO_MASK           (0x10U)
#define NETC_IERB_CAPR0_NUM_EMDIO_SHIFT          (4U)
#define NETC_IERB_CAPR0_NUM_EMDIO_WIDTH          (1U)
#define NETC_IERB_CAPR0_NUM_EMDIO(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_EMDIO_SHIFT)) & NETC_IERB_CAPR0_NUM_EMDIO_MASK)

#define NETC_IERB_CAPR0_NUM_TMR_MASK             (0xC0U)
#define NETC_IERB_CAPR0_NUM_TMR_SHIFT            (6U)
#define NETC_IERB_CAPR0_NUM_TMR_WIDTH            (2U)
#define NETC_IERB_CAPR0_NUM_TMR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_TMR_SHIFT)) & NETC_IERB_CAPR0_NUM_TMR_MASK)

#define NETC_IERB_CAPR0_NUM_LINKS_MASK           (0x1F00U)
#define NETC_IERB_CAPR0_NUM_LINKS_SHIFT          (8U)
#define NETC_IERB_CAPR0_NUM_LINKS_WIDTH          (5U)
#define NETC_IERB_CAPR0_NUM_LINKS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_LINKS_SHIFT)) & NETC_IERB_CAPR0_NUM_LINKS_MASK)

#define NETC_IERB_CAPR0_NUM_SW_MASK              (0x30000U)
#define NETC_IERB_CAPR0_NUM_SW_SHIFT             (16U)
#define NETC_IERB_CAPR0_NUM_SW_WIDTH             (2U)
#define NETC_IERB_CAPR0_NUM_SW(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_SW_SHIFT)) & NETC_IERB_CAPR0_NUM_SW_MASK)

#define NETC_IERB_CAPR0_NUM_ENETC_MASK           (0xF80000U)
#define NETC_IERB_CAPR0_NUM_ENETC_SHIFT          (19U)
#define NETC_IERB_CAPR0_NUM_ENETC_WIDTH          (5U)
#define NETC_IERB_CAPR0_NUM_ENETC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_ENETC_SHIFT)) & NETC_IERB_CAPR0_NUM_ENETC_MASK)

#define NETC_IERB_CAPR0_NUM_VSI_MASK             (0x7F000000U)
#define NETC_IERB_CAPR0_NUM_VSI_SHIFT            (24U)
#define NETC_IERB_CAPR0_NUM_VSI_WIDTH            (7U)
#define NETC_IERB_CAPR0_NUM_VSI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_VSI_SHIFT)) & NETC_IERB_CAPR0_NUM_VSI_MASK)
/*! @} */

/*! @name CAPR1 - Capability register 1 */
/*! @{ */

#define NETC_IERB_CAPR1_NUM_RX_BDR_MASK          (0x3FFU)
#define NETC_IERB_CAPR1_NUM_RX_BDR_SHIFT         (0U)
#define NETC_IERB_CAPR1_NUM_RX_BDR_WIDTH         (10U)
#define NETC_IERB_CAPR1_NUM_RX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR1_NUM_RX_BDR_SHIFT)) & NETC_IERB_CAPR1_NUM_RX_BDR_MASK)

#define NETC_IERB_CAPR1_NUM_TX_BDR_MASK          (0x3FF0000U)
#define NETC_IERB_CAPR1_NUM_TX_BDR_SHIFT         (16U)
#define NETC_IERB_CAPR1_NUM_TX_BDR_WIDTH         (10U)
#define NETC_IERB_CAPR1_NUM_TX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR1_NUM_TX_BDR_SHIFT)) & NETC_IERB_CAPR1_NUM_TX_BDR_MASK)
/*! @} */

/*! @name CAPR2 - Capability register 2 */
/*! @{ */

#define NETC_IERB_CAPR2_NUM_MSIX_MASK            (0x7FFU)
#define NETC_IERB_CAPR2_NUM_MSIX_SHIFT           (0U)
#define NETC_IERB_CAPR2_NUM_MSIX_WIDTH           (11U)
#define NETC_IERB_CAPR2_NUM_MSIX(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR2_NUM_MSIX_SHIFT)) & NETC_IERB_CAPR2_NUM_MSIX_MASK)
/*! @} */

/*! @name CAPR3 - Capability register 3 */
/*! @{ */

#define NETC_IERB_CAPR3_NUM_MAC_AFTE_MASK        (0xFFFU)
#define NETC_IERB_CAPR3_NUM_MAC_AFTE_SHIFT       (0U)
#define NETC_IERB_CAPR3_NUM_MAC_AFTE_WIDTH       (12U)
#define NETC_IERB_CAPR3_NUM_MAC_AFTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR3_NUM_MAC_AFTE_SHIFT)) & NETC_IERB_CAPR3_NUM_MAC_AFTE_MASK)

#define NETC_IERB_CAPR3_NUM_VLAN_FTE_MASK        (0xFFF0000U)
#define NETC_IERB_CAPR3_NUM_VLAN_FTE_SHIFT       (16U)
#define NETC_IERB_CAPR3_NUM_VLAN_FTE_WIDTH       (12U)
#define NETC_IERB_CAPR3_NUM_VLAN_FTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR3_NUM_VLAN_FTE_SHIFT)) & NETC_IERB_CAPR3_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name CMCAPR - Common memory capability register */
/*! @{ */

#define NETC_IERB_CMCAPR_NUM_WORDS_MASK          (0xFFFFFFU)
#define NETC_IERB_CMCAPR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_CMCAPR_NUM_WORDS_WIDTH         (24U)
#define NETC_IERB_CMCAPR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_CMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_CMCAPR_WORD_SIZE_MASK          (0x30000000U)
#define NETC_IERB_CMCAPR_WORD_SIZE_SHIFT         (28U)
#define NETC_IERB_CMCAPR_WORD_SIZE_WIDTH         (2U)
#define NETC_IERB_CMCAPR_WORD_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CMCAPR_WORD_SIZE_SHIFT)) & NETC_IERB_CMCAPR_WORD_SIZE_MASK)
/*! @} */

/*! @name IPFTMCAPR - Ingress port filter ternary memory capability register */
/*! @{ */

#define NETC_IERB_IPFTMCAPR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_IPFTMCAPR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_IPFTMCAPR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_IPFTMCAPR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_IPFTMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_IPFTMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_IPFTMCAPR_WORD_SIZE_MASK       (0x30000000U)
#define NETC_IERB_IPFTMCAPR_WORD_SIZE_SHIFT      (28U)
#define NETC_IERB_IPFTMCAPR_WORD_SIZE_WIDTH      (2U)
#define NETC_IERB_IPFTMCAPR_WORD_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_IPFTMCAPR_WORD_SIZE_SHIFT)) & NETC_IERB_IPFTMCAPR_WORD_SIZE_MASK)
/*! @} */

/*! @name TGSMCAPR - Time gate scheduling memory capability register */
/*! @{ */

#define NETC_IERB_TGSMCAPR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_TGSMCAPR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_TGSMCAPR_NUM_WORDS_WIDTH       (16U)
#define NETC_IERB_TGSMCAPR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TGSMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_TGSMCAPR_NUM_WORDS_MASK)
/*! @} */

/*! @name SMDTR - Shared memory depletion threshold register */
/*! @{ */

#define NETC_IERB_SMDTR_THRESH_MASK              (0xFFFFFFU)
#define NETC_IERB_SMDTR_THRESH_SHIFT             (0U)
#define NETC_IERB_SMDTR_THRESH_WIDTH             (24U)
#define NETC_IERB_SMDTR_THRESH(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMDTR_THRESH_SHIFT)) & NETC_IERB_SMDTR_THRESH_MASK)
/*! @} */

/*! @name ERSMBAR - ENETC receive shared memory buffer allotment register */
/*! @{ */

#define NETC_IERB_ERSMBAR_THRESH_MASK            (0xFFFFFFU)
#define NETC_IERB_ERSMBAR_THRESH_SHIFT           (0U)
#define NETC_IERB_ERSMBAR_THRESH_WIDTH           (24U)
#define NETC_IERB_ERSMBAR_THRESH(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERSMBAR_THRESH_SHIFT)) & NETC_IERB_ERSMBAR_THRESH_MASK)
/*! @} */

/*! @name HTAHPCR - HTA 0 HP configuration register */
/*! @{ */

#define NETC_IERB_HTAHPCR_BLIMIT_MASK            (0xFFFFU)
#define NETC_IERB_HTAHPCR_BLIMIT_SHIFT           (0U)
#define NETC_IERB_HTAHPCR_BLIMIT_WIDTH           (16U)
#define NETC_IERB_HTAHPCR_BLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTAHPCR_BLIMIT_SHIFT)) & NETC_IERB_HTAHPCR_BLIMIT_MASK)

#define NETC_IERB_HTAHPCR_FLIMIT_MASK            (0xFF000000U)
#define NETC_IERB_HTAHPCR_FLIMIT_SHIFT           (24U)
#define NETC_IERB_HTAHPCR_FLIMIT_WIDTH           (8U)
#define NETC_IERB_HTAHPCR_FLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTAHPCR_FLIMIT_SHIFT)) & NETC_IERB_HTAHPCR_FLIMIT_MASK)
/*! @} */

/*! @name HTALPCR - HTA 0 LP configuration register */
/*! @{ */

#define NETC_IERB_HTALPCR_BLIMIT_MASK            (0xFFFFU)
#define NETC_IERB_HTALPCR_BLIMIT_SHIFT           (0U)
#define NETC_IERB_HTALPCR_BLIMIT_WIDTH           (16U)
#define NETC_IERB_HTALPCR_BLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTALPCR_BLIMIT_SHIFT)) & NETC_IERB_HTALPCR_BLIMIT_MASK)

#define NETC_IERB_HTALPCR_FLIMIT_MASK            (0xFF000000U)
#define NETC_IERB_HTALPCR_FLIMIT_SHIFT           (24U)
#define NETC_IERB_HTALPCR_FLIMIT_WIDTH           (8U)
#define NETC_IERB_HTALPCR_FLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTALPCR_FLIMIT_SHIFT)) & NETC_IERB_HTALPCR_FLIMIT_MASK)
/*! @} */

/*! @name HBTMAR - Hash bucket table memory allocation register */
/*! @{ */

#define NETC_IERB_HBTMAR_NUM_WORDS_MASK          (0x3FFFU)
#define NETC_IERB_HBTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_HBTMAR_NUM_WORDS_WIDTH         (14U)
#define NETC_IERB_HBTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_HBTMAR_NUM_WORDS_MASK)

#define NETC_IERB_HBTMAR_MIN_WORDS_MASK          (0xFF0000U)
#define NETC_IERB_HBTMAR_MIN_WORDS_SHIFT         (16U)
#define NETC_IERB_HBTMAR_MIN_WORDS_WIDTH         (8U)
#define NETC_IERB_HBTMAR_MIN_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_MIN_WORDS_SHIFT)) & NETC_IERB_HBTMAR_MIN_WORDS_MASK)

#define NETC_IERB_HBTMAR_NEPW_MASK               (0x7000000U)
#define NETC_IERB_HBTMAR_NEPW_SHIFT              (24U)
#define NETC_IERB_HBTMAR_NEPW_WIDTH              (3U)
#define NETC_IERB_HBTMAR_NEPW(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_NEPW_SHIFT)) & NETC_IERB_HBTMAR_NEPW_MASK)

#define NETC_IERB_HBTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_HBTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_HBTMAR_MLOC_WIDTH              (2U)
#define NETC_IERB_HBTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_MLOC_SHIFT)) & NETC_IERB_HBTMAR_MLOC_MASK)
/*! @} */

/*! @name HBTCR - Hash bucket table configuration register */
/*! @{ */

#define NETC_IERB_HBTCR_MAX_COL_MASK             (0x7U)
#define NETC_IERB_HBTCR_MAX_COL_SHIFT            (0U)
#define NETC_IERB_HBTCR_MAX_COL_WIDTH            (3U)
#define NETC_IERB_HBTCR_MAX_COL(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTCR_MAX_COL_SHIFT)) & NETC_IERB_HBTCR_MAX_COL_MASK)

#define NETC_IERB_HBTCR_MAX_VISITS_MASK          (0xF0U)
#define NETC_IERB_HBTCR_MAX_VISITS_SHIFT         (4U)
#define NETC_IERB_HBTCR_MAX_VISITS_WIDTH         (4U)
#define NETC_IERB_HBTCR_MAX_VISITS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTCR_MAX_VISITS_SHIFT)) & NETC_IERB_HBTCR_MAX_VISITS_MASK)
/*! @} */

/*! @name GHTEMCAPR - Guaranteed hash table entry memory capability register */
/*! @{ */

#define NETC_IERB_GHTEMCAPR_NUM_WORDS_MASK       (0x1FFU)
#define NETC_IERB_GHTEMCAPR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_GHTEMCAPR_NUM_WORDS_WIDTH      (9U)
#define NETC_IERB_GHTEMCAPR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_GHTEMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_GHTEMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_GHTEMCAPR_MLOC_MASK            (0xC0000000U)
#define NETC_IERB_GHTEMCAPR_MLOC_SHIFT           (30U)
#define NETC_IERB_GHTEMCAPR_MLOC_WIDTH           (2U)
#define NETC_IERB_GHTEMCAPR_MLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_GHTEMCAPR_MLOC_SHIFT)) & NETC_IERB_GHTEMCAPR_MLOC_MASK)
/*! @} */

/*! @name NETCFLRCR - NETC FLR configuration register */
/*! @{ */

#define NETC_IERB_NETCFLRCR_VALUE_MASK           (0x1FFU)
#define NETC_IERB_NETCFLRCR_VALUE_SHIFT          (0U)
#define NETC_IERB_NETCFLRCR_VALUE_WIDTH          (9U)
#define NETC_IERB_NETCFLRCR_VALUE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCFLRCR_VALUE_SHIFT)) & NETC_IERB_NETCFLRCR_VALUE_MASK)

#define NETC_IERB_NETCFLRCR_SCALE_MASK           (0xE00U)
#define NETC_IERB_NETCFLRCR_SCALE_SHIFT          (9U)
#define NETC_IERB_NETCFLRCR_SCALE_WIDTH          (3U)
#define NETC_IERB_NETCFLRCR_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCFLRCR_SCALE_SHIFT)) & NETC_IERB_NETCFLRCR_SCALE_MASK)
/*! @} */

/*! @name NETCCLKFR - NETC clock period fractional register */
/*! @{ */

#define NETC_IERB_NETCCLKFR_FRAC_MASK            (0xFFFFFFFFU)
#define NETC_IERB_NETCCLKFR_FRAC_SHIFT           (0U)
#define NETC_IERB_NETCCLKFR_FRAC_WIDTH           (32U)
#define NETC_IERB_NETCCLKFR_FRAC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKFR_FRAC_SHIFT)) & NETC_IERB_NETCCLKFR_FRAC_MASK)
/*! @} */

/*! @name NETCCLKCR - NETC clock configuration register */
/*! @{ */

#define NETC_IERB_NETCCLKCR_FREQ_MASK            (0x7FFU)
#define NETC_IERB_NETCCLKCR_FREQ_SHIFT           (0U)
#define NETC_IERB_NETCCLKCR_FREQ_WIDTH           (11U)
#define NETC_IERB_NETCCLKCR_FREQ(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKCR_FREQ_SHIFT)) & NETC_IERB_NETCCLKCR_FREQ_MASK)

#define NETC_IERB_NETCCLKCR_PERIOD_MASK          (0x3FF0000U)
#define NETC_IERB_NETCCLKCR_PERIOD_SHIFT         (16U)
#define NETC_IERB_NETCCLKCR_PERIOD_WIDTH         (10U)
#define NETC_IERB_NETCCLKCR_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKCR_PERIOD_SHIFT)) & NETC_IERB_NETCCLKCR_PERIOD_MASK)
/*! @} */

/*! @name SBCR - System bus configuration register */
/*! @{ */

#define NETC_IERB_SBCR_WBS_MASK                  (0x3U)
#define NETC_IERB_SBCR_WBS_SHIFT                 (0U)
#define NETC_IERB_SBCR_WBS_WIDTH                 (2U)
#define NETC_IERB_SBCR_WBS(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_WBS_SHIFT)) & NETC_IERB_SBCR_WBS_MASK)

#define NETC_IERB_SBCR_RBS_MASK                  (0xCU)
#define NETC_IERB_SBCR_RBS_SHIFT                 (2U)
#define NETC_IERB_SBCR_RBS_WIDTH                 (2U)
#define NETC_IERB_SBCR_RBS(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_RBS_SHIFT)) & NETC_IERB_SBCR_RBS_MASK)
/*! @} */

/*! @name SBOTCR - System bus outstanding transaction control register */
/*! @{ */

#define NETC_IERB_SBOTCR_OT_LIMIT_MASK           (0xFFFFFFFFU)
#define NETC_IERB_SBOTCR_OT_LIMIT_SHIFT          (0U)
#define NETC_IERB_SBOTCR_OT_LIMIT_WIDTH          (32U)
#define NETC_IERB_SBOTCR_OT_LIMIT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBOTCR_OT_LIMIT_SHIFT)) & NETC_IERB_SBOTCR_OT_LIMIT_MASK)
/*! @} */

/*! @name SGLTTR - Stream gating lag time for refresh register */
/*! @{ */

#define NETC_IERB_SGLTTR_LAG_TIME_MASK           (0x1FU)
#define NETC_IERB_SGLTTR_LAG_TIME_SHIFT          (0U)
#define NETC_IERB_SGLTTR_LAG_TIME_WIDTH          (5U)
#define NETC_IERB_SGLTTR_LAG_TIME(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SGLTTR_LAG_TIME_SHIFT)) & NETC_IERB_SGLTTR_LAG_TIME_MASK)
/*! @} */

/*! @name RBCR - Root complex 0 binding configuration register */
/*! @{ */

#define NETC_IERB_RBCR_TYPE_MASK                 (0x1U)
#define NETC_IERB_RBCR_TYPE_SHIFT                (0U)
#define NETC_IERB_RBCR_TYPE_WIDTH                (1U)
#define NETC_IERB_RBCR_TYPE(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RBCR_TYPE_SHIFT)) & NETC_IERB_RBCR_TYPE_MASK)

#define NETC_IERB_RBCR_PORT_MASK                 (0xF0U)
#define NETC_IERB_RBCR_PORT_SHIFT                (4U)
#define NETC_IERB_RBCR_PORT_WIDTH                (4U)
#define NETC_IERB_RBCR_PORT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RBCR_PORT_SHIFT)) & NETC_IERB_RBCR_PORT_MASK)
/*! @} */

/*! @name RCMSICAR - Root complex 0 MSI-X cache attribute register */
/*! @{ */

#define NETC_IERB_RCMSICAR_MSI_WRCACHE_MASK      (0xFU)
#define NETC_IERB_RCMSICAR_MSI_WRCACHE_SHIFT     (0U)
#define NETC_IERB_RCMSICAR_MSI_WRCACHE_WIDTH     (4U)
#define NETC_IERB_RCMSICAR_MSI_WRCACHE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRCACHE_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRCACHE_MASK)

#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN_MASK     (0x30U)
#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN_SHIFT    (4U)
#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN_WIDTH    (2U)
#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRDOMAIN_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRDOMAIN_MASK)

#define NETC_IERB_RCMSICAR_MSI_WRSNP_MASK        (0x40U)
#define NETC_IERB_RCMSICAR_MSI_WRSNP_SHIFT       (6U)
#define NETC_IERB_RCMSICAR_MSI_WRSNP_WIDTH       (1U)
#define NETC_IERB_RCMSICAR_MSI_WRSNP(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRSNP_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRSNP_MASK)
/*! @} */

/*! @name RCMSIAMQR - Root complex 0 MSI access management qualifier register */
/*! @{ */

#define NETC_IERB_RCMSIAMQR_AWQOS_MASK           (0xF00000U)
#define NETC_IERB_RCMSIAMQR_AWQOS_SHIFT          (20U)
#define NETC_IERB_RCMSIAMQR_AWQOS_WIDTH          (4U)
#define NETC_IERB_RCMSIAMQR_AWQOS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSIAMQR_AWQOS_SHIFT)) & NETC_IERB_RCMSIAMQR_AWQOS_MASK)

#define NETC_IERB_RCMSIAMQR_BMT_MASK             (0x80000000U)
#define NETC_IERB_RCMSIAMQR_BMT_SHIFT            (31U)
#define NETC_IERB_RCMSIAMQR_BMT_WIDTH            (1U)
#define NETC_IERB_RCMSIAMQR_BMT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSIAMQR_BMT_SHIFT)) & NETC_IERB_RCMSIAMQR_BMT_MASK)
/*! @} */

/*! @name EMDIOBCR - EMDIO binding configuration register */
/*! @{ */

#define NETC_IERB_EMDIOBCR_RC_INST_MASK          (0xFU)
#define NETC_IERB_EMDIOBCR_RC_INST_SHIFT         (0U)
#define NETC_IERB_EMDIOBCR_RC_INST_WIDTH         (4U)
#define NETC_IERB_EMDIOBCR_RC_INST(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_RC_INST_SHIFT)) & NETC_IERB_EMDIOBCR_RC_INST_MASK)

#define NETC_IERB_EMDIOBCR_FN_MASK               (0xF00U)
#define NETC_IERB_EMDIOBCR_FN_SHIFT              (8U)
#define NETC_IERB_EMDIOBCR_FN_WIDTH              (4U)
#define NETC_IERB_EMDIOBCR_FN(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_FN_SHIFT)) & NETC_IERB_EMDIOBCR_FN_MASK)

#define NETC_IERB_EMDIOBCR_VALID_MASK            (0x80000000U)
#define NETC_IERB_EMDIOBCR_VALID_SHIFT           (31U)
#define NETC_IERB_EMDIOBCR_VALID_WIDTH           (1U)
#define NETC_IERB_EMDIOBCR_VALID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_VALID_SHIFT)) & NETC_IERB_EMDIOBCR_VALID_MASK)
/*! @} */

/*! @name EMDIOMCR - EMDIO MSI-X configuration register */
/*! @{ */

#define NETC_IERB_EMDIOMCR_NUM_MSIX_MASK         (0x1U)
#define NETC_IERB_EMDIOMCR_NUM_MSIX_SHIFT        (0U)
#define NETC_IERB_EMDIOMCR_NUM_MSIX_WIDTH        (1U)
#define NETC_IERB_EMDIOMCR_NUM_MSIX(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOMCR_NUM_MSIX_SHIFT)) & NETC_IERB_EMDIOMCR_NUM_MSIX_MASK)
/*! @} */

/*! @name EMDIO_CFH_DIDVID - EMDIO config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_WIDTH (16U)
#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID(x)  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID(x)  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name EMDIO_CFH_SIDSVID - EMDIO config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name EMDIOBLPR - EMDIO boot loader parameter register 0..EMDIO boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_EMDIOBLPR_PARAM_VAL_MASK       (0xFFFFFFFFU)
#define NETC_IERB_EMDIOBLPR_PARAM_VAL_SHIFT      (0U)
#define NETC_IERB_EMDIOBLPR_PARAM_VAL_WIDTH      (32U)
#define NETC_IERB_EMDIOBLPR_PARAM_VAL(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_EMDIOBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name EMDIO_CFG - EMDIO configuration register */
/*! @{ */

#define NETC_IERB_EMDIO_CFG_MDIO_MODE_MASK       (0x10U)
#define NETC_IERB_EMDIO_CFG_MDIO_MODE_SHIFT      (4U)
#define NETC_IERB_EMDIO_CFG_MDIO_MODE_WIDTH      (1U)
#define NETC_IERB_EMDIO_CFG_MDIO_MODE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFG_MDIO_MODE_SHIFT)) & NETC_IERB_EMDIO_CFG_MDIO_MODE_MASK)

#define NETC_IERB_EMDIO_CFG_MDC_MODE_MASK        (0x20U)
#define NETC_IERB_EMDIO_CFG_MDC_MODE_SHIFT       (5U)
#define NETC_IERB_EMDIO_CFG_MDC_MODE_WIDTH       (1U)
#define NETC_IERB_EMDIO_CFG_MDC_MODE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFG_MDC_MODE_SHIFT)) & NETC_IERB_EMDIO_CFG_MDC_MODE_MASK)
/*! @} */

/*! @name TBCR - Timer 0 binding configuration register */
/*! @{ */

#define NETC_IERB_TBCR_RC_INST_MASK              (0xFU)
#define NETC_IERB_TBCR_RC_INST_SHIFT             (0U)
#define NETC_IERB_TBCR_RC_INST_WIDTH             (4U)
#define NETC_IERB_TBCR_RC_INST(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_RC_INST_SHIFT)) & NETC_IERB_TBCR_RC_INST_MASK)

#define NETC_IERB_TBCR_FN_MASK                   (0xF00U)
#define NETC_IERB_TBCR_FN_SHIFT                  (8U)
#define NETC_IERB_TBCR_FN_WIDTH                  (4U)
#define NETC_IERB_TBCR_FN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_FN_SHIFT)) & NETC_IERB_TBCR_FN_MASK)

#define NETC_IERB_TBCR_VALID_MASK                (0x80000000U)
#define NETC_IERB_TBCR_VALID_SHIFT               (31U)
#define NETC_IERB_TBCR_VALID_WIDTH               (1U)
#define NETC_IERB_TBCR_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_VALID_SHIFT)) & NETC_IERB_TBCR_VALID_MASK)
/*! @} */

/*! @name TMCR - Timer 0 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_TMCR_NUM_MSIX_MASK             (0x1U)
#define NETC_IERB_TMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_TMCR_NUM_MSIX_WIDTH            (1U)
#define NETC_IERB_TMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TMCR_NUM_MSIX_SHIFT)) & NETC_IERB_TMCR_NUM_MSIX_MASK)
/*! @} */

/*! @name T_CFH_DIDVID - Timer 0 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID_WIDTH   (16U)
#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_T_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID_WIDTH   (16U)
#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_T_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name T_CFH_SIDSVID - Timer 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name TBLPR - Timer 0 boot loader parameter register 0..Timer 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_TBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_TBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_TBLPR_PARAM_VAL_WIDTH          (32U)
#define NETC_IERB_TBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_TBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name L0CAPR - Link 0 capability register */
/*! @{ */

#define NETC_IERB_L0CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L0CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L0CAPR_LINK_TYPE_WIDTH         (1U)
#define NETC_IERB_L0CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L0CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L0CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L0CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L0CAPR_NUM_TC_WIDTH            (4U)
#define NETC_IERB_L0CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_TC_SHIFT)) & NETC_IERB_L0CAPR_NUM_TC_MASK)

#define NETC_IERB_L0CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L0CAPR_NUM_Q_SHIFT             (16U)
#define NETC_IERB_L0CAPR_NUM_Q_WIDTH             (4U)
#define NETC_IERB_L0CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_Q_SHIFT)) & NETC_IERB_L0CAPR_NUM_Q_MASK)

#define NETC_IERB_L0CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L0CAPR_NUM_CG_SHIFT            (24U)
#define NETC_IERB_L0CAPR_NUM_CG_WIDTH            (4U)
#define NETC_IERB_L0CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_CG_SHIFT)) & NETC_IERB_L0CAPR_NUM_CG_MASK)

#define NETC_IERB_L0CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L0CAPR_TGS_SHIFT               (28U)
#define NETC_IERB_L0CAPR_TGS_WIDTH               (1U)
#define NETC_IERB_L0CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_TGS_SHIFT)) & NETC_IERB_L0CAPR_TGS_MASK)

#define NETC_IERB_L0CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L0CAPR_CBS_SHIFT               (29U)
#define NETC_IERB_L0CAPR_CBS_WIDTH               (1U)
#define NETC_IERB_L0CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_CBS_SHIFT)) & NETC_IERB_L0CAPR_CBS_MASK)
/*! @} */

/*! @name L0MCAPR - Link 0 MAC capability register */
/*! @{ */

#define NETC_IERB_L0MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L0MCAPR_MAC_VAR_SHIFT          (0U)
#define NETC_IERB_L0MCAPR_MAC_VAR_WIDTH          (3U)
#define NETC_IERB_L0MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L0MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L0MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L0MCAPR_EFPAD_SHIFT            (4U)
#define NETC_IERB_L0MCAPR_EFPAD_WIDTH            (2U)
#define NETC_IERB_L0MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_EFPAD_SHIFT)) & NETC_IERB_L0MCAPR_EFPAD_MASK)

#define NETC_IERB_L0MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L0MCAPR_HD_SHIFT               (8U)
#define NETC_IERB_L0MCAPR_HD_WIDTH               (1U)
#define NETC_IERB_L0MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_HD_SHIFT)) & NETC_IERB_L0MCAPR_HD_MASK)

#define NETC_IERB_L0MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L0MCAPR_FP_SHIFT               (9U)
#define NETC_IERB_L0MCAPR_FP_WIDTH               (2U)
#define NETC_IERB_L0MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_FP_SHIFT)) & NETC_IERB_L0MCAPR_FP_MASK)

#define NETC_IERB_L0MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L0MCAPR_MII_PROT_SHIFT         (24U)
#define NETC_IERB_L0MCAPR_MII_PROT_WIDTH         (4U)
#define NETC_IERB_L0MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L0MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L0IOCAPR - Link 0 I/O capability register */
/*! @{ */

#define NETC_IERB_L0IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L0IOCAPR_PCS_PROT_SHIFT        (0U)
#define NETC_IERB_L0IOCAPR_PCS_PROT_WIDTH        (16U)
#define NETC_IERB_L0IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L0IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L0IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L0IOCAPR_IO_VAR_SHIFT          (24U)
#define NETC_IERB_L0IOCAPR_IO_VAR_WIDTH          (4U)
#define NETC_IERB_L0IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L0IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L0IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L0IOCAPR_EMDIO_SHIFT           (28U)
#define NETC_IERB_L0IOCAPR_EMDIO_WIDTH           (1U)
#define NETC_IERB_L0IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L0IOCAPR_EMDIO_MASK)

#define NETC_IERB_L0IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L0IOCAPR_REVMII_RATE_SHIFT     (30U)
#define NETC_IERB_L0IOCAPR_REVMII_RATE_WIDTH     (1U)
#define NETC_IERB_L0IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L0IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L0IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L0IOCAPR_REVMII_SHIFT          (31U)
#define NETC_IERB_L0IOCAPR_REVMII_WIDTH          (1U)
#define NETC_IERB_L0IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_REVMII_SHIFT)) & NETC_IERB_L0IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L0BCR - Link 0 binding configuration register */
/*! @{ */

#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST_WIDTH (5U)
#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L0BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L0BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L0BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L0BCR_NETC_FUNC_WIDTH          (1U)
#define NETC_IERB_L0BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L0BCR_NETC_FUNC_MASK)

#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_WIDTH   (5U)
#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L0BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L0BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L0BCR_SPL_SW_PORT_WIDTH        (5U)
#define NETC_IERB_L0BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L0BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L0TXBCCTR - Link 0 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L0TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L0TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L0TXBCCTR_THRESH_WIDTH         (16U)
#define NETC_IERB_L0TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L0TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L0E0MAR0 - Link 0 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L0E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L0E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L0E0MAR0_MAC_ADDR_WIDTH        (32U)
#define NETC_IERB_L0E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L0E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L0E0MAR1 - Link 0 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L0E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L0E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L0E0MAR1_MAC_ADDR_WIDTH        (16U)
#define NETC_IERB_L0E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L0E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L1CAPR - Link 1 capability register */
/*! @{ */

#define NETC_IERB_L1CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L1CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L1CAPR_LINK_TYPE_WIDTH         (1U)
#define NETC_IERB_L1CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L1CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L1CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L1CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L1CAPR_NUM_TC_WIDTH            (4U)
#define NETC_IERB_L1CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_TC_SHIFT)) & NETC_IERB_L1CAPR_NUM_TC_MASK)

#define NETC_IERB_L1CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L1CAPR_NUM_Q_SHIFT             (16U)
#define NETC_IERB_L1CAPR_NUM_Q_WIDTH             (4U)
#define NETC_IERB_L1CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_Q_SHIFT)) & NETC_IERB_L1CAPR_NUM_Q_MASK)

#define NETC_IERB_L1CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L1CAPR_NUM_CG_SHIFT            (24U)
#define NETC_IERB_L1CAPR_NUM_CG_WIDTH            (4U)
#define NETC_IERB_L1CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_CG_SHIFT)) & NETC_IERB_L1CAPR_NUM_CG_MASK)

#define NETC_IERB_L1CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L1CAPR_TGS_SHIFT               (28U)
#define NETC_IERB_L1CAPR_TGS_WIDTH               (1U)
#define NETC_IERB_L1CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_TGS_SHIFT)) & NETC_IERB_L1CAPR_TGS_MASK)

#define NETC_IERB_L1CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L1CAPR_CBS_SHIFT               (29U)
#define NETC_IERB_L1CAPR_CBS_WIDTH               (1U)
#define NETC_IERB_L1CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_CBS_SHIFT)) & NETC_IERB_L1CAPR_CBS_MASK)
/*! @} */

/*! @name L1MCAPR - Link 1 MAC capability register */
/*! @{ */

#define NETC_IERB_L1MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L1MCAPR_MAC_VAR_SHIFT          (0U)
#define NETC_IERB_L1MCAPR_MAC_VAR_WIDTH          (3U)
#define NETC_IERB_L1MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L1MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L1MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L1MCAPR_EFPAD_SHIFT            (4U)
#define NETC_IERB_L1MCAPR_EFPAD_WIDTH            (2U)
#define NETC_IERB_L1MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_EFPAD_SHIFT)) & NETC_IERB_L1MCAPR_EFPAD_MASK)

#define NETC_IERB_L1MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L1MCAPR_HD_SHIFT               (8U)
#define NETC_IERB_L1MCAPR_HD_WIDTH               (1U)
#define NETC_IERB_L1MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_HD_SHIFT)) & NETC_IERB_L1MCAPR_HD_MASK)

#define NETC_IERB_L1MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L1MCAPR_FP_SHIFT               (9U)
#define NETC_IERB_L1MCAPR_FP_WIDTH               (2U)
#define NETC_IERB_L1MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_FP_SHIFT)) & NETC_IERB_L1MCAPR_FP_MASK)

#define NETC_IERB_L1MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L1MCAPR_MII_PROT_SHIFT         (24U)
#define NETC_IERB_L1MCAPR_MII_PROT_WIDTH         (4U)
#define NETC_IERB_L1MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L1MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L1IOCAPR - Link 1 I/O capability register */
/*! @{ */

#define NETC_IERB_L1IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L1IOCAPR_PCS_PROT_SHIFT        (0U)
#define NETC_IERB_L1IOCAPR_PCS_PROT_WIDTH        (16U)
#define NETC_IERB_L1IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L1IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L1IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L1IOCAPR_IO_VAR_SHIFT          (24U)
#define NETC_IERB_L1IOCAPR_IO_VAR_WIDTH          (4U)
#define NETC_IERB_L1IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L1IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L1IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L1IOCAPR_EMDIO_SHIFT           (28U)
#define NETC_IERB_L1IOCAPR_EMDIO_WIDTH           (1U)
#define NETC_IERB_L1IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L1IOCAPR_EMDIO_MASK)

#define NETC_IERB_L1IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L1IOCAPR_REVMII_RATE_SHIFT     (30U)
#define NETC_IERB_L1IOCAPR_REVMII_RATE_WIDTH     (1U)
#define NETC_IERB_L1IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L1IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L1IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L1IOCAPR_REVMII_SHIFT          (31U)
#define NETC_IERB_L1IOCAPR_REVMII_WIDTH          (1U)
#define NETC_IERB_L1IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_REVMII_SHIFT)) & NETC_IERB_L1IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L1BCR - Link 1 binding configuration register */
/*! @{ */

#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST_WIDTH (5U)
#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L1BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L1BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L1BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L1BCR_NETC_FUNC_WIDTH          (1U)
#define NETC_IERB_L1BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L1BCR_NETC_FUNC_MASK)

#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_WIDTH   (5U)
#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L1BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L1BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L1BCR_SPL_SW_PORT_WIDTH        (5U)
#define NETC_IERB_L1BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L1BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L1TXBCCTR - Link 1 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L1TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L1TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L1TXBCCTR_THRESH_WIDTH         (16U)
#define NETC_IERB_L1TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L1TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L1E0MAR0 - Link 1 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L1E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L1E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L1E0MAR0_MAC_ADDR_WIDTH        (32U)
#define NETC_IERB_L1E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L1E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L1E0MAR1 - Link 1 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L1E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L1E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L1E0MAR1_MAC_ADDR_WIDTH        (16U)
#define NETC_IERB_L1E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L1E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L2CAPR - Link 2 capability register */
/*! @{ */

#define NETC_IERB_L2CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L2CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L2CAPR_LINK_TYPE_WIDTH         (1U)
#define NETC_IERB_L2CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L2CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L2CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L2CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L2CAPR_NUM_TC_WIDTH            (4U)
#define NETC_IERB_L2CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_TC_SHIFT)) & NETC_IERB_L2CAPR_NUM_TC_MASK)

#define NETC_IERB_L2CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L2CAPR_NUM_Q_SHIFT             (16U)
#define NETC_IERB_L2CAPR_NUM_Q_WIDTH             (4U)
#define NETC_IERB_L2CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_Q_SHIFT)) & NETC_IERB_L2CAPR_NUM_Q_MASK)

#define NETC_IERB_L2CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L2CAPR_NUM_CG_SHIFT            (24U)
#define NETC_IERB_L2CAPR_NUM_CG_WIDTH            (4U)
#define NETC_IERB_L2CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_CG_SHIFT)) & NETC_IERB_L2CAPR_NUM_CG_MASK)

#define NETC_IERB_L2CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L2CAPR_TGS_SHIFT               (28U)
#define NETC_IERB_L2CAPR_TGS_WIDTH               (1U)
#define NETC_IERB_L2CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_TGS_SHIFT)) & NETC_IERB_L2CAPR_TGS_MASK)

#define NETC_IERB_L2CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L2CAPR_CBS_SHIFT               (29U)
#define NETC_IERB_L2CAPR_CBS_WIDTH               (1U)
#define NETC_IERB_L2CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_CBS_SHIFT)) & NETC_IERB_L2CAPR_CBS_MASK)
/*! @} */

/*! @name L2MCAPR - Link 2 MAC capability register */
/*! @{ */

#define NETC_IERB_L2MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L2MCAPR_MAC_VAR_SHIFT          (0U)
#define NETC_IERB_L2MCAPR_MAC_VAR_WIDTH          (3U)
#define NETC_IERB_L2MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L2MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L2MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L2MCAPR_EFPAD_SHIFT            (4U)
#define NETC_IERB_L2MCAPR_EFPAD_WIDTH            (2U)
#define NETC_IERB_L2MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_EFPAD_SHIFT)) & NETC_IERB_L2MCAPR_EFPAD_MASK)

#define NETC_IERB_L2MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L2MCAPR_HD_SHIFT               (8U)
#define NETC_IERB_L2MCAPR_HD_WIDTH               (1U)
#define NETC_IERB_L2MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_HD_SHIFT)) & NETC_IERB_L2MCAPR_HD_MASK)

#define NETC_IERB_L2MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L2MCAPR_FP_SHIFT               (9U)
#define NETC_IERB_L2MCAPR_FP_WIDTH               (2U)
#define NETC_IERB_L2MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_FP_SHIFT)) & NETC_IERB_L2MCAPR_FP_MASK)

#define NETC_IERB_L2MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L2MCAPR_MII_PROT_SHIFT         (24U)
#define NETC_IERB_L2MCAPR_MII_PROT_WIDTH         (4U)
#define NETC_IERB_L2MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L2MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L2BCR - Link 2 binding configuration register */
/*! @{ */

#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST_WIDTH (5U)
#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L2BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L2BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L2BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L2BCR_NETC_FUNC_WIDTH          (1U)
#define NETC_IERB_L2BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L2BCR_NETC_FUNC_MASK)

#define NETC_IERB_L2BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L2BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L2BCR_SPL_SW_PORT_WIDTH        (5U)
#define NETC_IERB_L2BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L2BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L2TXBCCTR - Link 2 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L2TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L2TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L2TXBCCTR_THRESH_WIDTH         (16U)
#define NETC_IERB_L2TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L2TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L2E0MAR0 - Link 2 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L2E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L2E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E0MAR0_MAC_ADDR_WIDTH        (32U)
#define NETC_IERB_L2E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L2E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L2E0MAR1 - Link 2 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L2E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L2E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E0MAR1_MAC_ADDR_WIDTH        (16U)
#define NETC_IERB_L2E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L2E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L2E1MAR0 - Link 2 end 1 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L2E1MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L2E1MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E1MAR0_MAC_ADDR_WIDTH        (32U)
#define NETC_IERB_L2E1MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E1MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L2E1MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L2E1MAR1 - Link 2 end 1 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L2E1MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L2E1MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E1MAR1_MAC_ADDR_WIDTH        (16U)
#define NETC_IERB_L2E1MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E1MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L2E1MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name SBCR - Switch 0 binding configuration register */
/*! @{ */

#define NETC_IERB_SBCR_RC_INST_MASK              (0xFU)
#define NETC_IERB_SBCR_RC_INST_SHIFT             (0U)
#define NETC_IERB_SBCR_RC_INST_WIDTH             (4U)
#define NETC_IERB_SBCR_RC_INST(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_RC_INST_SHIFT)) & NETC_IERB_SBCR_RC_INST_MASK)

#define NETC_IERB_SBCR_FN_MASK                   (0xF00U)
#define NETC_IERB_SBCR_FN_SHIFT                  (8U)
#define NETC_IERB_SBCR_FN_WIDTH                  (4U)
#define NETC_IERB_SBCR_FN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_FN_SHIFT)) & NETC_IERB_SBCR_FN_MASK)

#define NETC_IERB_SBCR_VALID_MASK                (0x80000000U)
#define NETC_IERB_SBCR_VALID_SHIFT               (31U)
#define NETC_IERB_SBCR_VALID_WIDTH               (1U)
#define NETC_IERB_SBCR_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_VALID_SHIFT)) & NETC_IERB_SBCR_VALID_MASK)
/*! @} */

/*! @name SMCR - Switch 0 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_SMCR_NUM_MSIX_MASK             (0xFU)
#define NETC_IERB_SMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_SMCR_NUM_MSIX_WIDTH            (4U)
#define NETC_IERB_SMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMCR_NUM_MSIX_SHIFT)) & NETC_IERB_SMCR_NUM_MSIX_MASK)
/*! @} */

/*! @name S_CFH_DIDVID - Switch 0 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID_WIDTH   (16U)
#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_S_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID_WIDTH   (16U)
#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_S_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name S_CFH_SIDSVID - Switch 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name SCCAR - Switch 0 command cache attribute register */
/*! @{ */

#define NETC_IERB_SCCAR_CBD_WRCACHE_MASK         (0xFU)
#define NETC_IERB_SCCAR_CBD_WRCACHE_SHIFT        (0U)
#define NETC_IERB_SCCAR_CBD_WRCACHE_WIDTH        (4U)
#define NETC_IERB_SCCAR_CBD_WRCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRCACHE_SHIFT)) & NETC_IERB_SCCAR_CBD_WRCACHE_MASK)

#define NETC_IERB_SCCAR_CBD_WRDOMAIN_MASK        (0x30U)
#define NETC_IERB_SCCAR_CBD_WRDOMAIN_SHIFT       (4U)
#define NETC_IERB_SCCAR_CBD_WRDOMAIN_WIDTH       (2U)
#define NETC_IERB_SCCAR_CBD_WRDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CBD_WRDOMAIN_MASK)

#define NETC_IERB_SCCAR_CBD_WRSNP_MASK           (0x40U)
#define NETC_IERB_SCCAR_CBD_WRSNP_SHIFT          (6U)
#define NETC_IERB_SCCAR_CBD_WRSNP_WIDTH          (1U)
#define NETC_IERB_SCCAR_CBD_WRSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRSNP_SHIFT)) & NETC_IERB_SCCAR_CBD_WRSNP_MASK)

#define NETC_IERB_SCCAR_CWRCACHE_MASK            (0xF00U)
#define NETC_IERB_SCCAR_CWRCACHE_SHIFT           (8U)
#define NETC_IERB_SCCAR_CWRCACHE_WIDTH           (4U)
#define NETC_IERB_SCCAR_CWRCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRCACHE_SHIFT)) & NETC_IERB_SCCAR_CWRCACHE_MASK)

#define NETC_IERB_SCCAR_CWRDOMAIN_MASK           (0x3000U)
#define NETC_IERB_SCCAR_CWRDOMAIN_SHIFT          (12U)
#define NETC_IERB_SCCAR_CWRDOMAIN_WIDTH          (2U)
#define NETC_IERB_SCCAR_CWRDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CWRDOMAIN_MASK)

#define NETC_IERB_SCCAR_CWRSNP_MASK              (0x4000U)
#define NETC_IERB_SCCAR_CWRSNP_SHIFT             (14U)
#define NETC_IERB_SCCAR_CWRSNP_WIDTH             (1U)
#define NETC_IERB_SCCAR_CWRSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRSNP_SHIFT)) & NETC_IERB_SCCAR_CWRSNP_MASK)

#define NETC_IERB_SCCAR_CBD_RDCACHE_MASK         (0xF0000U)
#define NETC_IERB_SCCAR_CBD_RDCACHE_SHIFT        (16U)
#define NETC_IERB_SCCAR_CBD_RDCACHE_WIDTH        (4U)
#define NETC_IERB_SCCAR_CBD_RDCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDCACHE_SHIFT)) & NETC_IERB_SCCAR_CBD_RDCACHE_MASK)

#define NETC_IERB_SCCAR_CBD_RDDOMAIN_MASK        (0x300000U)
#define NETC_IERB_SCCAR_CBD_RDDOMAIN_SHIFT       (20U)
#define NETC_IERB_SCCAR_CBD_RDDOMAIN_WIDTH       (2U)
#define NETC_IERB_SCCAR_CBD_RDDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CBD_RDDOMAIN_MASK)

#define NETC_IERB_SCCAR_CBD_RDSNP_MASK           (0x400000U)
#define NETC_IERB_SCCAR_CBD_RDSNP_SHIFT          (22U)
#define NETC_IERB_SCCAR_CBD_RDSNP_WIDTH          (1U)
#define NETC_IERB_SCCAR_CBD_RDSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDSNP_SHIFT)) & NETC_IERB_SCCAR_CBD_RDSNP_MASK)

#define NETC_IERB_SCCAR_CRDCACHE_MASK            (0xF000000U)
#define NETC_IERB_SCCAR_CRDCACHE_SHIFT           (24U)
#define NETC_IERB_SCCAR_CRDCACHE_WIDTH           (4U)
#define NETC_IERB_SCCAR_CRDCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDCACHE_SHIFT)) & NETC_IERB_SCCAR_CRDCACHE_MASK)

#define NETC_IERB_SCCAR_CRDDOMAIN_MASK           (0x30000000U)
#define NETC_IERB_SCCAR_CRDDOMAIN_SHIFT          (28U)
#define NETC_IERB_SCCAR_CRDDOMAIN_WIDTH          (2U)
#define NETC_IERB_SCCAR_CRDDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CRDDOMAIN_MASK)

#define NETC_IERB_SCCAR_CRDSNP_MASK              (0x40000000U)
#define NETC_IERB_SCCAR_CRDSNP_SHIFT             (30U)
#define NETC_IERB_SCCAR_CRDSNP_WIDTH             (1U)
#define NETC_IERB_SCCAR_CRDSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDSNP_SHIFT)) & NETC_IERB_SCCAR_CRDSNP_MASK)
/*! @} */

/*! @name SAMQR - Switch 0 access management qualifier register */
/*! @{ */

#define NETC_IERB_SAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_SAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_SAMQR_ARQOS_WIDTH              (4U)
#define NETC_IERB_SAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_ARQOS_SHIFT)) & NETC_IERB_SAMQR_ARQOS_MASK)

#define NETC_IERB_SAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_SAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_SAMQR_AWQOS_WIDTH              (4U)
#define NETC_IERB_SAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_AWQOS_SHIFT)) & NETC_IERB_SAMQR_AWQOS_MASK)

#define NETC_IERB_SAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_SAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_SAMQR_BMT_WIDTH                (1U)
#define NETC_IERB_SAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_BMT_SHIFT)) & NETC_IERB_SAMQR_BMT_MASK)
/*! @} */

/*! @name SBLPR - Switch 0 boot loader parameter register 0..Switch 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_SBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_SBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_SBLPR_PARAM_VAL_WIDTH          (32U)
#define NETC_IERB_SBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_SBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name SSMBAR - Switch 0 shared memory buffer allotment register */
/*! @{ */

#define NETC_IERB_SSMBAR_ALLOC_MASK              (0xFFFFFFU)
#define NETC_IERB_SSMBAR_ALLOC_SHIFT             (0U)
#define NETC_IERB_SSMBAR_ALLOC_WIDTH             (24U)
#define NETC_IERB_SSMBAR_ALLOC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSMBAR_ALLOC_SHIFT)) & NETC_IERB_SSMBAR_ALLOC_MASK)

#define NETC_IERB_SSMBAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SSMBAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SSMBAR_MLOC_WIDTH              (2U)
#define NETC_IERB_SSMBAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSMBAR_MLOC_SHIFT)) & NETC_IERB_SSMBAR_MLOC_MASK)
/*! @} */

/*! @name SHTMAR - Switch 0 hash table memory allotment register */
/*! @{ */

#define NETC_IERB_SHTMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_SHTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_SHTMAR_NUM_WORDS_WIDTH         (16U)
#define NETC_IERB_SHTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SHTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SHTMAR_NUM_WORDS_MASK)

#define NETC_IERB_SHTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SHTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SHTMAR_MLOC_WIDTH              (2U)
#define NETC_IERB_SHTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SHTMAR_MLOC_SHIFT)) & NETC_IERB_SHTMAR_MLOC_MASK)
/*! @} */

/*! @name SITMAR - Switch 0 index table memory allocation register */
/*! @{ */

#define NETC_IERB_SITMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_SITMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_SITMAR_NUM_WORDS_WIDTH         (16U)
#define NETC_IERB_SITMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SITMAR_NUM_WORDS_MASK)

#define NETC_IERB_SITMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SITMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SITMAR_MLOC_WIDTH              (2U)
#define NETC_IERB_SITMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SITMAR_MLOC_SHIFT)) & NETC_IERB_SITMAR_MLOC_MASK)
/*! @} */

/*! @name SIPFTMAR - Switch 0 ingress port filter table memory allocation register */
/*! @{ */

#define NETC_IERB_SIPFTMAR_ALLOC_MASK            (0xFFFFU)
#define NETC_IERB_SIPFTMAR_ALLOC_SHIFT           (0U)
#define NETC_IERB_SIPFTMAR_ALLOC_WIDTH           (16U)
#define NETC_IERB_SIPFTMAR_ALLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SIPFTMAR_ALLOC_SHIFT)) & NETC_IERB_SIPFTMAR_ALLOC_MASK)
/*! @} */

/*! @name SRPITMAR - Switch 0 rate policer index table memory allocation register */
/*! @{ */

#define NETC_IERB_SRPITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_SRPITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SRPITMAR_NUM_WORDS_WIDTH       (16U)
#define NETC_IERB_SRPITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SRPITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SRPITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SISCITMAR - Switch 0 ingress stream counter index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISCITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SISCITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SISCITMAR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_SISCITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISCITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISCITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SISITMAR - Switch 0 ingress stream index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_SISITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SISITMAR_NUM_WORDS_WIDTH       (16U)
#define NETC_IERB_SISITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SISQGITMAR - Switch 0 ingress sequence generation index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISQGITMAR_NUM_WORDS_MASK      (0x1FFFU)
#define NETC_IERB_SISQGITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_SISQGITMAR_NUM_WORDS_WIDTH     (13U)
#define NETC_IERB_SISQGITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISQGITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISQGITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SSGIITMAR - Switch 0 stream gate instance index table memory allocation register */
/*! @{ */

#define NETC_IERB_SSGIITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SSGIITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SSGIITMAR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_SSGIITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSGIITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SSGIITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SSGCLITMAR - Switch 0 stream gate control list index table memory allocation register */
/*! @{ */

#define NETC_IERB_SSGCLITMAR_NUM_WORDS_MASK      (0xFFFFU)
#define NETC_IERB_SSGCLITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_SSGCLITMAR_NUM_WORDS_WIDTH     (16U)
#define NETC_IERB_SSGCLITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSGCLITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SSGCLITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SFMITMAR - Switch 0 frame modification index table memory allocation register */
/*! @{ */

#define NETC_IERB_SFMITMAR_NUM_WORDS_MASK        (0x1FFFU)
#define NETC_IERB_SFMITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SFMITMAR_NUM_WORDS_WIDTH       (13U)
#define NETC_IERB_SFMITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SFMITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SFMITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name SFMDITMAR - Switch 0 frame modification data index table memory allocation register */
/*! @{ */

#define NETC_IERB_SFMDITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SFMDITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SFMDITMAR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_SFMDITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SFMDITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SFMDITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name STGSTAR - Switch 0 time gate scheduling table allocation register */
/*! @{ */

#define NETC_IERB_STGSTAR_NUM_WORDS_MASK         (0xFFFU)
#define NETC_IERB_STGSTAR_NUM_WORDS_SHIFT        (0U)
#define NETC_IERB_STGSTAR_NUM_WORDS_WIDTH        (12U)
#define NETC_IERB_STGSTAR_NUM_WORDS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_STGSTAR_NUM_WORDS_SHIFT)) & NETC_IERB_STGSTAR_NUM_WORDS_MASK)
/*! @} */

/*! @name STGSLR - Switch 0 time gate scheduling lookahead register */
/*! @{ */

#define NETC_IERB_STGSLR_MIN_LOOKAHEAD_MASK      (0xFFFFFU)
#define NETC_IERB_STGSLR_MIN_LOOKAHEAD_SHIFT     (0U)
#define NETC_IERB_STGSLR_MIN_LOOKAHEAD_WIDTH     (20U)
#define NETC_IERB_STGSLR_MIN_LOOKAHEAD(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_STGSLR_MIN_LOOKAHEAD_SHIFT)) & NETC_IERB_STGSLR_MIN_LOOKAHEAD_MASK)
/*! @} */

/*! @name SMPCR - Switch 0 management port configuration register */
/*! @{ */

#define NETC_IERB_SMPCR_PORT_MASK                (0x1FU)
#define NETC_IERB_SMPCR_PORT_SHIFT               (0U)
#define NETC_IERB_SMPCR_PORT_WIDTH               (5U)
#define NETC_IERB_SMPCR_PORT(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMPCR_PORT_SHIFT)) & NETC_IERB_SMPCR_PORT_MASK)
/*! @} */

/*! @name SVFHTDECR0 - Switch 0 VLAN Filter (hash) table default entry configuration registers 0 */
/*! @{ */

#define NETC_IERB_SVFHTDECR0_PORT0_MASK          (0x1U)
#define NETC_IERB_SVFHTDECR0_PORT0_SHIFT         (0U)
#define NETC_IERB_SVFHTDECR0_PORT0_WIDTH         (1U)
#define NETC_IERB_SVFHTDECR0_PORT0(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT0_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT0_MASK)

#define NETC_IERB_SVFHTDECR0_PORT1_MASK          (0x2U)
#define NETC_IERB_SVFHTDECR0_PORT1_SHIFT         (1U)
#define NETC_IERB_SVFHTDECR0_PORT1_WIDTH         (1U)
#define NETC_IERB_SVFHTDECR0_PORT1(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT1_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT1_MASK)

#define NETC_IERB_SVFHTDECR0_PORT2_MASK          (0x4U)
#define NETC_IERB_SVFHTDECR0_PORT2_SHIFT         (2U)
#define NETC_IERB_SVFHTDECR0_PORT2_WIDTH         (1U)
#define NETC_IERB_SVFHTDECR0_PORT2(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT2_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT2_MASK)

#define NETC_IERB_SVFHTDECR0_STG_ID_MASK         (0xF000000U)
#define NETC_IERB_SVFHTDECR0_STG_ID_SHIFT        (24U)
#define NETC_IERB_SVFHTDECR0_STG_ID_WIDTH        (4U)
#define NETC_IERB_SVFHTDECR0_STG_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_STG_ID_SHIFT)) & NETC_IERB_SVFHTDECR0_STG_ID_MASK)

#define NETC_IERB_SVFHTDECR0_IPMFE_MASK          (0x20000000U)
#define NETC_IERB_SVFHTDECR0_IPMFE_SHIFT         (29U)
#define NETC_IERB_SVFHTDECR0_IPMFE_WIDTH         (1U)
#define NETC_IERB_SVFHTDECR0_IPMFE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_IPMFE_SHIFT)) & NETC_IERB_SVFHTDECR0_IPMFE_MASK)

#define NETC_IERB_SVFHTDECR0_IPMFLE_MASK         (0x40000000U)
#define NETC_IERB_SVFHTDECR0_IPMFLE_SHIFT        (30U)
#define NETC_IERB_SVFHTDECR0_IPMFLE_WIDTH        (1U)
#define NETC_IERB_SVFHTDECR0_IPMFLE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_IPMFLE_SHIFT)) & NETC_IERB_SVFHTDECR0_IPMFLE_MASK)
/*! @} */

/*! @name SVFHTDECR1 - Switch 0 VLAN filter hash table default entry configuration registers 1 */
/*! @{ */

#define NETC_IERB_SVFHTDECR1_FID_MASK            (0xFFFU)
#define NETC_IERB_SVFHTDECR1_FID_SHIFT           (0U)
#define NETC_IERB_SVFHTDECR1_FID_WIDTH           (12U)
#define NETC_IERB_SVFHTDECR1_FID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_FID_SHIFT)) & NETC_IERB_SVFHTDECR1_FID_MASK)

#define NETC_IERB_SVFHTDECR1_VL_MODE_MASK        (0x1000U)
#define NETC_IERB_SVFHTDECR1_VL_MODE_SHIFT       (12U)
#define NETC_IERB_SVFHTDECR1_VL_MODE_WIDTH       (1U)
#define NETC_IERB_SVFHTDECR1_VL_MODE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_VL_MODE_SHIFT)) & NETC_IERB_SVFHTDECR1_VL_MODE_MASK)

#define NETC_IERB_SVFHTDECR1_BASE_ETEID_MASK     (0xFFFF0000U)
#define NETC_IERB_SVFHTDECR1_BASE_ETEID_SHIFT    (16U)
#define NETC_IERB_SVFHTDECR1_BASE_ETEID_WIDTH    (16U)
#define NETC_IERB_SVFHTDECR1_BASE_ETEID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_BASE_ETEID_SHIFT)) & NETC_IERB_SVFHTDECR1_BASE_ETEID_MASK)
/*! @} */

/*! @name SVFHTDECR2 - Switch 0 VLAN filter hash table default entry configuration registers 2 */
/*! @{ */

#define NETC_IERB_SVFHTDECR2_ES_PORT0_MASK       (0x1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT0_SHIFT      (0U)
#define NETC_IERB_SVFHTDECR2_ES_PORT0_WIDTH      (1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT0(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT0_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT0_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT1_MASK       (0x2U)
#define NETC_IERB_SVFHTDECR2_ES_PORT1_SHIFT      (1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT1_WIDTH      (1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT1(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT1_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT1_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT2_MASK       (0x4U)
#define NETC_IERB_SVFHTDECR2_ES_PORT2_SHIFT      (2U)
#define NETC_IERB_SVFHTDECR2_ES_PORT2_WIDTH      (1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT2(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT2_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT2_MASK)

#define NETC_IERB_SVFHTDECR2_MLO_MASK            (0x7000000U)
#define NETC_IERB_SVFHTDECR2_MLO_SHIFT           (24U)
#define NETC_IERB_SVFHTDECR2_MLO_WIDTH           (3U)
#define NETC_IERB_SVFHTDECR2_MLO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_MLO_SHIFT)) & NETC_IERB_SVFHTDECR2_MLO_MASK)

#define NETC_IERB_SVFHTDECR2_MFO_MASK            (0x18000000U)
#define NETC_IERB_SVFHTDECR2_MFO_SHIFT           (27U)
#define NETC_IERB_SVFHTDECR2_MFO_WIDTH           (2U)
#define NETC_IERB_SVFHTDECR2_MFO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_MFO_SHIFT)) & NETC_IERB_SVFHTDECR2_MFO_MASK)
/*! @} */

/*! @name EBCR0 - ENETC 0 binding configuration register 0 */
/*! @{ */

#define NETC_IERB_EBCR0_RC_INST_MASK             (0xFU)
#define NETC_IERB_EBCR0_RC_INST_SHIFT            (0U)
#define NETC_IERB_EBCR0_RC_INST_WIDTH            (4U)
#define NETC_IERB_EBCR0_RC_INST(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_RC_INST_SHIFT)) & NETC_IERB_EBCR0_RC_INST_MASK)

#define NETC_IERB_EBCR0_FN_MASK                  (0xF00U)
#define NETC_IERB_EBCR0_FN_SHIFT                 (8U)
#define NETC_IERB_EBCR0_FN_WIDTH                 (4U)
#define NETC_IERB_EBCR0_FN(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_FN_SHIFT)) & NETC_IERB_EBCR0_FN_MASK)

#define NETC_IERB_EBCR0_VALID_MASK               (0x80000000U)
#define NETC_IERB_EBCR0_VALID_SHIFT              (31U)
#define NETC_IERB_EBCR0_VALID_WIDTH              (1U)
#define NETC_IERB_EBCR0_VALID(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_VALID_SHIFT)) & NETC_IERB_EBCR0_VALID_MASK)
/*! @} */

/*! @name EBCR1 - ENETC 0 binding configuration register 1 */
/*! @{ */

#define NETC_IERB_EBCR1_NUM_RX_BDR_MASK          (0x3FFU)
#define NETC_IERB_EBCR1_NUM_RX_BDR_SHIFT         (0U)
#define NETC_IERB_EBCR1_NUM_RX_BDR_WIDTH         (10U)
#define NETC_IERB_EBCR1_NUM_RX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR1_NUM_RX_BDR_SHIFT)) & NETC_IERB_EBCR1_NUM_RX_BDR_MASK)

#define NETC_IERB_EBCR1_NUM_TX_BDR_MASK          (0x3FF0000U)
#define NETC_IERB_EBCR1_NUM_TX_BDR_SHIFT         (16U)
#define NETC_IERB_EBCR1_NUM_TX_BDR_WIDTH         (10U)
#define NETC_IERB_EBCR1_NUM_TX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR1_NUM_TX_BDR_SHIFT)) & NETC_IERB_EBCR1_NUM_TX_BDR_MASK)
/*! @} */

/*! @name EBCR2 - ENETC 0 binding configuration register 2 */
/*! @{ */

#define NETC_IERB_EBCR2_NUM_MAC_AFTE_MASK        (0xFFFU)
#define NETC_IERB_EBCR2_NUM_MAC_AFTE_SHIFT       (0U)
#define NETC_IERB_EBCR2_NUM_MAC_AFTE_WIDTH       (12U)
#define NETC_IERB_EBCR2_NUM_MAC_AFTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR2_NUM_MAC_AFTE_SHIFT)) & NETC_IERB_EBCR2_NUM_MAC_AFTE_MASK)

#define NETC_IERB_EBCR2_NUM_VLAN_FTE_MASK        (0xFFF0000U)
#define NETC_IERB_EBCR2_NUM_VLAN_FTE_SHIFT       (16U)
#define NETC_IERB_EBCR2_NUM_VLAN_FTE_WIDTH       (12U)
#define NETC_IERB_EBCR2_NUM_VLAN_FTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR2_NUM_VLAN_FTE_SHIFT)) & NETC_IERB_EBCR2_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name EVBCR - ENETC 0 VSI binding configuration register */
/*! @{ */

#define NETC_IERB_EVBCR_NUM_VSI_MASK             (0xFU)
#define NETC_IERB_EVBCR_NUM_VSI_SHIFT            (0U)
#define NETC_IERB_EVBCR_NUM_VSI_WIDTH            (4U)
#define NETC_IERB_EVBCR_NUM_VSI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EVBCR_NUM_VSI_SHIFT)) & NETC_IERB_EVBCR_NUM_VSI_MASK)
/*! @} */

/*! @name EMCR - ENETC 0 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_EMCR_NUM_MSIX_MASK             (0x7FFU)
#define NETC_IERB_EMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_EMCR_NUM_MSIX_WIDTH            (11U)
#define NETC_IERB_EMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCR_NUM_MSIX_SHIFT)) & NETC_IERB_EMCR_NUM_MSIX_MASK)
/*! @} */

/*! @name E_CFH_DIDVID - ENETC 0 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID_WIDTH   (16U)
#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_E_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID_WIDTH   (16U)
#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name E_CFH_SIDSVID - ENETC 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_WIDTH (16U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name E_CFC_VFDID - ENETC 0 config capability VF device ID register */
/*! @{ */

#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_MASK  (0xFFFF0000U)
#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_WIDTH (16U)
#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_MASK)
/*! @} */

/*! @name EBCAR - ENETC 0 buffer cache attribute register 0 */
/*! @{ */

#define NETC_IERB_EBCAR_BD_WRCACHE_MASK          (0xFU)
#define NETC_IERB_EBCAR_BD_WRCACHE_SHIFT         (0U)
#define NETC_IERB_EBCAR_BD_WRCACHE_WIDTH         (4U)
#define NETC_IERB_EBCAR_BD_WRCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRCACHE_SHIFT)) & NETC_IERB_EBCAR_BD_WRCACHE_MASK)

#define NETC_IERB_EBCAR_BD_WRDOMAIN_MASK         (0x30U)
#define NETC_IERB_EBCAR_BD_WRDOMAIN_SHIFT        (4U)
#define NETC_IERB_EBCAR_BD_WRDOMAIN_WIDTH        (2U)
#define NETC_IERB_EBCAR_BD_WRDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRDOMAIN_SHIFT)) & NETC_IERB_EBCAR_BD_WRDOMAIN_MASK)

#define NETC_IERB_EBCAR_BD_WRSNP_MASK            (0x40U)
#define NETC_IERB_EBCAR_BD_WRSNP_SHIFT           (6U)
#define NETC_IERB_EBCAR_BD_WRSNP_WIDTH           (1U)
#define NETC_IERB_EBCAR_BD_WRSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRSNP_SHIFT)) & NETC_IERB_EBCAR_BD_WRSNP_MASK)

#define NETC_IERB_EBCAR_WRCACHE_MASK             (0xF00U)
#define NETC_IERB_EBCAR_WRCACHE_SHIFT            (8U)
#define NETC_IERB_EBCAR_WRCACHE_WIDTH            (4U)
#define NETC_IERB_EBCAR_WRCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRCACHE_SHIFT)) & NETC_IERB_EBCAR_WRCACHE_MASK)

#define NETC_IERB_EBCAR_WRDOMAIN_MASK            (0x3000U)
#define NETC_IERB_EBCAR_WRDOMAIN_SHIFT           (12U)
#define NETC_IERB_EBCAR_WRDOMAIN_WIDTH           (2U)
#define NETC_IERB_EBCAR_WRDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRDOMAIN_SHIFT)) & NETC_IERB_EBCAR_WRDOMAIN_MASK)

#define NETC_IERB_EBCAR_WRSNP_MASK               (0x4000U)
#define NETC_IERB_EBCAR_WRSNP_SHIFT              (14U)
#define NETC_IERB_EBCAR_WRSNP_WIDTH              (1U)
#define NETC_IERB_EBCAR_WRSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRSNP_SHIFT)) & NETC_IERB_EBCAR_WRSNP_MASK)

#define NETC_IERB_EBCAR_BD_RDCACHE_MASK          (0xF0000U)
#define NETC_IERB_EBCAR_BD_RDCACHE_SHIFT         (16U)
#define NETC_IERB_EBCAR_BD_RDCACHE_WIDTH         (4U)
#define NETC_IERB_EBCAR_BD_RDCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDCACHE_SHIFT)) & NETC_IERB_EBCAR_BD_RDCACHE_MASK)

#define NETC_IERB_EBCAR_BD_RDDOMAIN_MASK         (0x300000U)
#define NETC_IERB_EBCAR_BD_RDDOMAIN_SHIFT        (20U)
#define NETC_IERB_EBCAR_BD_RDDOMAIN_WIDTH        (2U)
#define NETC_IERB_EBCAR_BD_RDDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDDOMAIN_SHIFT)) & NETC_IERB_EBCAR_BD_RDDOMAIN_MASK)

#define NETC_IERB_EBCAR_BD_RDSNP_MASK            (0x400000U)
#define NETC_IERB_EBCAR_BD_RDSNP_SHIFT           (22U)
#define NETC_IERB_EBCAR_BD_RDSNP_WIDTH           (1U)
#define NETC_IERB_EBCAR_BD_RDSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDSNP_SHIFT)) & NETC_IERB_EBCAR_BD_RDSNP_MASK)

#define NETC_IERB_EBCAR_RDCACHE_MASK             (0xF000000U)
#define NETC_IERB_EBCAR_RDCACHE_SHIFT            (24U)
#define NETC_IERB_EBCAR_RDCACHE_WIDTH            (4U)
#define NETC_IERB_EBCAR_RDCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDCACHE_SHIFT)) & NETC_IERB_EBCAR_RDCACHE_MASK)

#define NETC_IERB_EBCAR_RDDOMAIN_MASK            (0x30000000U)
#define NETC_IERB_EBCAR_RDDOMAIN_SHIFT           (28U)
#define NETC_IERB_EBCAR_RDDOMAIN_WIDTH           (2U)
#define NETC_IERB_EBCAR_RDDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDDOMAIN_SHIFT)) & NETC_IERB_EBCAR_RDDOMAIN_MASK)

#define NETC_IERB_EBCAR_RDSNP_MASK               (0x40000000U)
#define NETC_IERB_EBCAR_RDSNP_SHIFT              (30U)
#define NETC_IERB_EBCAR_RDSNP_WIDTH              (1U)
#define NETC_IERB_EBCAR_RDSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDSNP_SHIFT)) & NETC_IERB_EBCAR_RDSNP_MASK)
/*! @} */

/*! @name EMCAR - ENETC 0 message cache attribute register */
/*! @{ */

#define NETC_IERB_EMCAR_MSG_WRCACHE_MASK         (0xFU)
#define NETC_IERB_EMCAR_MSG_WRCACHE_SHIFT        (0U)
#define NETC_IERB_EMCAR_MSG_WRCACHE_WIDTH        (4U)
#define NETC_IERB_EMCAR_MSG_WRCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRCACHE_SHIFT)) & NETC_IERB_EMCAR_MSG_WRCACHE_MASK)

#define NETC_IERB_EMCAR_MSG_WRDOMAIN_MASK        (0x30U)
#define NETC_IERB_EMCAR_MSG_WRDOMAIN_SHIFT       (4U)
#define NETC_IERB_EMCAR_MSG_WRDOMAIN_WIDTH       (2U)
#define NETC_IERB_EMCAR_MSG_WRDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRDOMAIN_SHIFT)) & NETC_IERB_EMCAR_MSG_WRDOMAIN_MASK)

#define NETC_IERB_EMCAR_MSG_WRSNP_MASK           (0x40U)
#define NETC_IERB_EMCAR_MSG_WRSNP_SHIFT          (6U)
#define NETC_IERB_EMCAR_MSG_WRSNP_WIDTH          (1U)
#define NETC_IERB_EMCAR_MSG_WRSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRSNP_SHIFT)) & NETC_IERB_EMCAR_MSG_WRSNP_MASK)

#define NETC_IERB_EMCAR_MSG_RDCACHE_MASK         (0xF0000U)
#define NETC_IERB_EMCAR_MSG_RDCACHE_SHIFT        (16U)
#define NETC_IERB_EMCAR_MSG_RDCACHE_WIDTH        (4U)
#define NETC_IERB_EMCAR_MSG_RDCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDCACHE_SHIFT)) & NETC_IERB_EMCAR_MSG_RDCACHE_MASK)

#define NETC_IERB_EMCAR_MSG_RDDOMAIN_MASK        (0x300000U)
#define NETC_IERB_EMCAR_MSG_RDDOMAIN_SHIFT       (20U)
#define NETC_IERB_EMCAR_MSG_RDDOMAIN_WIDTH       (2U)
#define NETC_IERB_EMCAR_MSG_RDDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDDOMAIN_SHIFT)) & NETC_IERB_EMCAR_MSG_RDDOMAIN_MASK)

#define NETC_IERB_EMCAR_MSG_RDSNP_MASK           (0x400000U)
#define NETC_IERB_EMCAR_MSG_RDSNP_SHIFT          (22U)
#define NETC_IERB_EMCAR_MSG_RDSNP_WIDTH          (1U)
#define NETC_IERB_EMCAR_MSG_RDSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDSNP_SHIFT)) & NETC_IERB_EMCAR_MSG_RDSNP_MASK)
/*! @} */

/*! @name ECAR - ENETC 0 command cache attribute register */
/*! @{ */

#define NETC_IERB_ECAR_CBD_WRCACHE_MASK          (0xFU)
#define NETC_IERB_ECAR_CBD_WRCACHE_SHIFT         (0U)
#define NETC_IERB_ECAR_CBD_WRCACHE_WIDTH         (4U)
#define NETC_IERB_ECAR_CBD_WRCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRCACHE_SHIFT)) & NETC_IERB_ECAR_CBD_WRCACHE_MASK)

#define NETC_IERB_ECAR_CBD_WRDOMAIN_MASK         (0x30U)
#define NETC_IERB_ECAR_CBD_WRDOMAIN_SHIFT        (4U)
#define NETC_IERB_ECAR_CBD_WRDOMAIN_WIDTH        (2U)
#define NETC_IERB_ECAR_CBD_WRDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRDOMAIN_SHIFT)) & NETC_IERB_ECAR_CBD_WRDOMAIN_MASK)

#define NETC_IERB_ECAR_CBD_WRSNP_MASK            (0x40U)
#define NETC_IERB_ECAR_CBD_WRSNP_SHIFT           (6U)
#define NETC_IERB_ECAR_CBD_WRSNP_WIDTH           (1U)
#define NETC_IERB_ECAR_CBD_WRSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRSNP_SHIFT)) & NETC_IERB_ECAR_CBD_WRSNP_MASK)

#define NETC_IERB_ECAR_CWRCACHE_MASK             (0xF00U)
#define NETC_IERB_ECAR_CWRCACHE_SHIFT            (8U)
#define NETC_IERB_ECAR_CWRCACHE_WIDTH            (4U)
#define NETC_IERB_ECAR_CWRCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRCACHE_SHIFT)) & NETC_IERB_ECAR_CWRCACHE_MASK)

#define NETC_IERB_ECAR_CWRDOMAIN_MASK            (0x3000U)
#define NETC_IERB_ECAR_CWRDOMAIN_SHIFT           (12U)
#define NETC_IERB_ECAR_CWRDOMAIN_WIDTH           (2U)
#define NETC_IERB_ECAR_CWRDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRDOMAIN_SHIFT)) & NETC_IERB_ECAR_CWRDOMAIN_MASK)

#define NETC_IERB_ECAR_CWRSNP_MASK               (0x4000U)
#define NETC_IERB_ECAR_CWRSNP_SHIFT              (14U)
#define NETC_IERB_ECAR_CWRSNP_WIDTH              (1U)
#define NETC_IERB_ECAR_CWRSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRSNP_SHIFT)) & NETC_IERB_ECAR_CWRSNP_MASK)

#define NETC_IERB_ECAR_CBD_RDCACHE_MASK          (0xF0000U)
#define NETC_IERB_ECAR_CBD_RDCACHE_SHIFT         (16U)
#define NETC_IERB_ECAR_CBD_RDCACHE_WIDTH         (4U)
#define NETC_IERB_ECAR_CBD_RDCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDCACHE_SHIFT)) & NETC_IERB_ECAR_CBD_RDCACHE_MASK)

#define NETC_IERB_ECAR_CBD_RDDOMAIN_MASK         (0x300000U)
#define NETC_IERB_ECAR_CBD_RDDOMAIN_SHIFT        (20U)
#define NETC_IERB_ECAR_CBD_RDDOMAIN_WIDTH        (2U)
#define NETC_IERB_ECAR_CBD_RDDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDDOMAIN_SHIFT)) & NETC_IERB_ECAR_CBD_RDDOMAIN_MASK)

#define NETC_IERB_ECAR_CBD_RDSNP_MASK            (0x400000U)
#define NETC_IERB_ECAR_CBD_RDSNP_SHIFT           (22U)
#define NETC_IERB_ECAR_CBD_RDSNP_WIDTH           (1U)
#define NETC_IERB_ECAR_CBD_RDSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDSNP_SHIFT)) & NETC_IERB_ECAR_CBD_RDSNP_MASK)

#define NETC_IERB_ECAR_CRDCACHE_MASK             (0xF000000U)
#define NETC_IERB_ECAR_CRDCACHE_SHIFT            (24U)
#define NETC_IERB_ECAR_CRDCACHE_WIDTH            (4U)
#define NETC_IERB_ECAR_CRDCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDCACHE_SHIFT)) & NETC_IERB_ECAR_CRDCACHE_MASK)

#define NETC_IERB_ECAR_CRDDOMAIN_MASK            (0x30000000U)
#define NETC_IERB_ECAR_CRDDOMAIN_SHIFT           (28U)
#define NETC_IERB_ECAR_CRDDOMAIN_WIDTH           (2U)
#define NETC_IERB_ECAR_CRDDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDDOMAIN_SHIFT)) & NETC_IERB_ECAR_CRDDOMAIN_MASK)

#define NETC_IERB_ECAR_CRDSNP_MASK               (0x40000000U)
#define NETC_IERB_ECAR_CRDSNP_SHIFT              (30U)
#define NETC_IERB_ECAR_CRDSNP_WIDTH              (1U)
#define NETC_IERB_ECAR_CRDSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDSNP_SHIFT)) & NETC_IERB_ECAR_CRDSNP_MASK)
/*! @} */

/*! @name EAMQR - ENETC 0 access management qualifier register */
/*! @{ */

#define NETC_IERB_EAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_EAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_EAMQR_ARQOS_WIDTH              (4U)
#define NETC_IERB_EAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_ARQOS_SHIFT)) & NETC_IERB_EAMQR_ARQOS_MASK)

#define NETC_IERB_EAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_EAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_EAMQR_AWQOS_WIDTH              (4U)
#define NETC_IERB_EAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_AWQOS_SHIFT)) & NETC_IERB_EAMQR_AWQOS_MASK)

#define NETC_IERB_EAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_EAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_EAMQR_BMT_WIDTH                (1U)
#define NETC_IERB_EAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_BMT_SHIFT)) & NETC_IERB_EAMQR_BMT_MASK)
/*! @} */

/*! @name EBLPR - ENETC 0 boot loader parameter register 0..ENETC 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_EBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_EBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_EBLPR_PARAM_VAL_WIDTH          (32U)
#define NETC_IERB_EBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_EBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name ERXMBER - ENETC 0 receive memory buffer entitlement register */
/*! @{ */

#define NETC_IERB_ERXMBER_AMOUNT_MASK            (0xFFFFFFU)
#define NETC_IERB_ERXMBER_AMOUNT_SHIFT           (0U)
#define NETC_IERB_ERXMBER_AMOUNT_WIDTH           (24U)
#define NETC_IERB_ERXMBER_AMOUNT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERXMBER_AMOUNT_SHIFT)) & NETC_IERB_ERXMBER_AMOUNT_MASK)
/*! @} */

/*! @name ERXMBLR - ENETC 0 receive memory buffer limit register */
/*! @{ */

#define NETC_IERB_ERXMBLR_LIMIT_MASK             (0xFFFFFFU)
#define NETC_IERB_ERXMBLR_LIMIT_SHIFT            (0U)
#define NETC_IERB_ERXMBLR_LIMIT_WIDTH            (24U)
#define NETC_IERB_ERXMBLR_LIMIT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERXMBLR_LIMIT_SHIFT)) & NETC_IERB_ERXMBLR_LIMIT_MASK)
/*! @} */

/*! @name ETXHPTBCR - ENETC 0 transmit high priority tier byte credit register */
/*! @{ */

#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT_MASK     (0xFFFFU)
#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT_SHIFT    (0U)
#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT_WIDTH    (16U)
#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETXHPTBCR_BYTE_CREDIT_SHIFT)) & NETC_IERB_ETXHPTBCR_BYTE_CREDIT_MASK)
/*! @} */

/*! @name ETXLPTBCR - ENETC 0 transmit low priority tier byte credit register */
/*! @{ */

#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT_MASK     (0xFFFFU)
#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT_SHIFT    (0U)
#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT_WIDTH    (16U)
#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETXLPTBCR_BYTE_CREDIT_SHIFT)) & NETC_IERB_ETXLPTBCR_BYTE_CREDIT_MASK)
/*! @} */

/*! @name EHTMAR - ENETC 0 hash table memory allotment register */
/*! @{ */

#define NETC_IERB_EHTMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_EHTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_EHTMAR_NUM_WORDS_WIDTH         (16U)
#define NETC_IERB_EHTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EHTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EHTMAR_NUM_WORDS_MASK)

#define NETC_IERB_EHTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_EHTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_EHTMAR_MLOC_WIDTH              (2U)
#define NETC_IERB_EHTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EHTMAR_MLOC_SHIFT)) & NETC_IERB_EHTMAR_MLOC_MASK)
/*! @} */

/*! @name EITMAR - ENETC 0 index table memory allocation register */
/*! @{ */

#define NETC_IERB_EITMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_EITMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_EITMAR_NUM_WORDS_WIDTH         (16U)
#define NETC_IERB_EITMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EITMAR_NUM_WORDS_MASK)

#define NETC_IERB_EITMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_EITMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_EITMAR_MLOC_WIDTH              (2U)
#define NETC_IERB_EITMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EITMAR_MLOC_SHIFT)) & NETC_IERB_EITMAR_MLOC_MASK)
/*! @} */

/*! @name EIPFTMAR - ENETC 0 ingress port filter table memory allocation register */
/*! @{ */

#define NETC_IERB_EIPFTMAR_ALLOC_MASK            (0xFFFFU)
#define NETC_IERB_EIPFTMAR_ALLOC_SHIFT           (0U)
#define NETC_IERB_EIPFTMAR_ALLOC_WIDTH           (16U)
#define NETC_IERB_EIPFTMAR_ALLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EIPFTMAR_ALLOC_SHIFT)) & NETC_IERB_EIPFTMAR_ALLOC_MASK)
/*! @} */

/*! @name ERTMAR - ENETC 0 RFS ternary memory allocation register */
/*! @{ */

#define NETC_IERB_ERTMAR_ALLOC_MASK              (0xFFFFU)
#define NETC_IERB_ERTMAR_ALLOC_SHIFT             (0U)
#define NETC_IERB_ERTMAR_ALLOC_WIDTH             (16U)
#define NETC_IERB_ERTMAR_ALLOC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERTMAR_ALLOC_SHIFT)) & NETC_IERB_ERTMAR_ALLOC_MASK)
/*! @} */

/*! @name ERPITMAR - ENETC 0 rate policer index table memory allocation register */
/*! @{ */

#define NETC_IERB_ERPITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_ERPITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_ERPITMAR_NUM_WORDS_WIDTH       (16U)
#define NETC_IERB_ERPITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERPITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ERPITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name EISCITMAR - ENETC 0 ingress stream counter index table memory allocation register */
/*! @{ */

#define NETC_IERB_EISCITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_EISCITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_EISCITMAR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_EISCITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EISCITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EISCITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name EISITMAR - ENETC 0 ingress stream index table memory allocation register */
/*! @{ */

#define NETC_IERB_EISITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_EISITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_EISITMAR_NUM_WORDS_WIDTH       (16U)
#define NETC_IERB_EISITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EISITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EISITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ESGIITMAR - ENETC 0 stream gate instance index table memory allocation register */
/*! @{ */

#define NETC_IERB_ESGIITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_ESGIITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_ESGIITMAR_NUM_WORDS_WIDTH      (16U)
#define NETC_IERB_ESGIITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ESGIITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ESGIITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ESGCLITMAR - ENETC 0 stream gate control list index table memory allocation register */
/*! @{ */

#define NETC_IERB_ESGCLITMAR_NUM_WORDS_MASK      (0xFFFFU)
#define NETC_IERB_ESGCLITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_ESGCLITMAR_NUM_WORDS_WIDTH     (16U)
#define NETC_IERB_ESGCLITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ESGCLITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ESGCLITMAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ETGSTAR - ENETC 0 time gate scheduling table allocation register */
/*! @{ */

#define NETC_IERB_ETGSTAR_NUM_WORDS_MASK         (0xFFFU)
#define NETC_IERB_ETGSTAR_NUM_WORDS_SHIFT        (0U)
#define NETC_IERB_ETGSTAR_NUM_WORDS_WIDTH        (12U)
#define NETC_IERB_ETGSTAR_NUM_WORDS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSTAR_NUM_WORDS_SHIFT)) & NETC_IERB_ETGSTAR_NUM_WORDS_MASK)
/*! @} */

/*! @name ETGSLR - ENETC 0 time gate scheduling lookahead register */
/*! @{ */

#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD_MASK      (0xFFFFFU)
#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD_SHIFT     (0U)
#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD_WIDTH     (20U)
#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSLR_MIN_LOOKAHEAD_SHIFT)) & NETC_IERB_ETGSLR_MIN_LOOKAHEAD_MASK)

#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_MASK     (0x80000000U)
#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_SHIFT    (31U)
#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_WIDTH    (1U)
#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_SHIFT)) & NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_MASK)
/*! @} */

/*! @name VAMQR - VSI 0 access management qualifier register..VSI 6 access management qualifier register */
/*! @{ */

#define NETC_IERB_VAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_VAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_VAMQR_ARQOS_WIDTH              (4U)
#define NETC_IERB_VAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_ARQOS_SHIFT)) & NETC_IERB_VAMQR_ARQOS_MASK)

#define NETC_IERB_VAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_VAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_VAMQR_AWQOS_WIDTH              (4U)
#define NETC_IERB_VAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_AWQOS_SHIFT)) & NETC_IERB_VAMQR_AWQOS_MASK)

#define NETC_IERB_VAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_VAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_VAMQR_BMT_WIDTH                (1U)
#define NETC_IERB_VAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_BMT_SHIFT)) & NETC_IERB_VAMQR_BMT_MASK)
/*! @} */

/*! @name VBLPR - VSI 0 boot loader parameter register 0..VSI 6 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_VBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_VBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_VBLPR_PARAM_VAL_WIDTH          (32U)
#define NETC_IERB_VBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_VBLPR_PARAM_VAL_MASK)
/*! @} */

/*! @name VPMAR0 - VSI 0 primary MAC address register 0..VSI 6 primary MAC address register 0 */
/*! @{ */

#define NETC_IERB_VPMAR0_MAC_ADDR_MASK           (0xFFFFFFFFU)
#define NETC_IERB_VPMAR0_MAC_ADDR_SHIFT          (0U)
#define NETC_IERB_VPMAR0_MAC_ADDR_WIDTH          (32U)
#define NETC_IERB_VPMAR0_MAC_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VPMAR0_MAC_ADDR_SHIFT)) & NETC_IERB_VPMAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name VPMAR1 - VSI 0 primary MAC address register 1..VSI 6 primary MAC address register 1 */
/*! @{ */

#define NETC_IERB_VPMAR1_MAC_ADDR_MASK           (0xFFFFU)
#define NETC_IERB_VPMAR1_MAC_ADDR_SHIFT          (0U)
#define NETC_IERB_VPMAR1_MAC_ADDR_WIDTH          (16U)
#define NETC_IERB_VPMAR1_MAC_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VPMAR1_MAC_ADDR_SHIFT)) & NETC_IERB_VPMAR1_MAC_ADDR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group NETC_IERB_Register_Masks */

/*!
 * @}
 */ /* end of group NETC_IERB_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_NETC_IERB_H_) */
