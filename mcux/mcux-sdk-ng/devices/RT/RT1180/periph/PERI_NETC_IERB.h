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
**         CMSIS Peripheral Access Layer for NETC_IERB
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
 * @file PERI_NETC_IERB.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for NETC_IERB
 *
 * CMSIS Peripheral Access Layer for NETC_IERB
 */

#if !defined(PERI_NETC_IERB_H_)
#define PERI_NETC_IERB_H_                        /**< Symbol preventing repeated inclusion */

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
#define NETC_IERB_CFG_ENETC_INST_COUNT            2u
#define NETC_IERB_CFG_VSI_INST_VSI_PF_BOOT_LOAD_COUNT 2u
#define NETC_IERB_CFG_VSI_INST_COUNT              1u

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
  struct {                                         /* offset: 0xC0, array step: 0x8 */
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
  struct {                                         /* offset: 0x200, array step: 0x10 */
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
  struct {                                         /* offset: 0x400, array step: 0x50 */
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
  __I  uint32_t L2IOCAPR;                          /**< Link 2 I/O capability register, offset: 0x1088 */
       uint8_t RESERVED_22[4];
  __IO uint32_t L2BCR;                             /**< Link 2 binding configuration register, offset: 0x1090 */
  __IO uint32_t L2TXBCCTR;                         /**< Link 2 transmit byte credit comfort threshold register, offset: 0x1094 */
       uint8_t RESERVED_23[8];
  __IO uint32_t L2E0MAR0;                          /**< Link 2 end 0 MAC address register 0, offset: 0x10A0 */
  __IO uint32_t L2E0MAR1;                          /**< Link 2 end 0 MAC address register 1, offset: 0x10A4 */
       uint8_t RESERVED_24[24];
  __I  uint32_t L3CAPR;                            /**< Link 3 capability register, offset: 0x10C0 */
  __I  uint32_t L3MCAPR;                           /**< Link 3 MAC capability register, offset: 0x10C4 */
  __I  uint32_t L3IOCAPR;                          /**< Link 3 I/O capability register, offset: 0x10C8 */
       uint8_t RESERVED_25[4];
  __IO uint32_t L3BCR;                             /**< Link 3 binding configuration register, offset: 0x10D0 */
  __IO uint32_t L3TXBCCTR;                         /**< Link 3 transmit byte credit comfort threshold register, offset: 0x10D4 */
       uint8_t RESERVED_26[8];
  __IO uint32_t L3E0MAR0;                          /**< Link 3 end 0 MAC address register 0, offset: 0x10E0 */
  __IO uint32_t L3E0MAR1;                          /**< Link 3 end 0 MAC address register 1, offset: 0x10E4 */
       uint8_t RESERVED_27[24];
  __I  uint32_t L4CAPR;                            /**< Link 4 capability register, offset: 0x1100 */
  __I  uint32_t L4MCAPR;                           /**< Link 4 MAC capability register, offset: 0x1104 */
  __I  uint32_t L4IOCAPR;                          /**< Link 4 I/O capability register, offset: 0x1108 */
       uint8_t RESERVED_28[4];
  __IO uint32_t L4BCR;                             /**< Link 4 binding configuration register, offset: 0x1110 */
  __IO uint32_t L4TXBCCTR;                         /**< Link 4 transmit byte credit comfort threshold register, offset: 0x1114 */
       uint8_t RESERVED_29[8];
  __IO uint32_t L4E0MAR0;                          /**< Link 4 end 0 MAC address register 0, offset: 0x1120 */
  __IO uint32_t L4E0MAR1;                          /**< Link 4 end 0 MAC address register 1, offset: 0x1124 */
       uint8_t RESERVED_30[24];
  __I  uint32_t L5CAPR;                            /**< Link 5 capability register, offset: 0x1140 */
  __I  uint32_t L5MCAPR;                           /**< Link 5 MAC capability register, offset: 0x1144 */
       uint8_t RESERVED_31[8];
  __I  uint32_t L5BCR;                             /**< Link 5 binding configuration register, offset: 0x1150 */
  __IO uint32_t L5TXBCCTR;                         /**< Link 5 transmit byte credit comfort threshold register, offset: 0x1154 */
       uint8_t RESERVED_32[8];
  __IO uint32_t L5E0MAR0;                          /**< Link 5 end 0 MAC address register 0, offset: 0x1160 */
  __IO uint32_t L5E0MAR1;                          /**< Link 5 end 0 MAC address register 1, offset: 0x1164 */
  __IO uint32_t L5E1MAR0;                          /**< Link 5 end 1 MAC address register 0, offset: 0x1168 */
  __IO uint32_t L5E1MAR1;                          /**< Link 5 end 1 MAC address register 1, offset: 0x116C */
       uint8_t RESERVED_33[3728];
  struct {                                         /* offset: 0x2000, array step: 0x21C */
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
       uint8_t RESERVED_34[3556];
  struct {                                         /* offset: 0x3000, array step: 0x100 */
    __I  uint32_t EBCR0;                             /**< ENETC 0 binding configuration register 0..ENETC 1 binding configuration register 0, array offset: 0x3000, array step: 0x100 */
    __I  uint32_t EBCR1;                             /**< ENETC 0 binding configuration register 1..ENETC 1 binding configuration register 1, array offset: 0x3004, array step: 0x100 */
    __I  uint32_t EBCR2;                             /**< ENETC 0 binding configuration register 2..ENETC 1 binding configuration register 2, array offset: 0x3008, array step: 0x100 */
         uint8_t RESERVED_0[4];
    __I  uint32_t EVBCR;                             /**< ENETC 0 VSI binding configuration register..ENETC 1 VSI binding configuration register, array offset: 0x3010, array step: 0x100 */
    __IO uint32_t EMCR;                              /**< ENETC 0 MSI-X configuration register..ENETC 1 MSI-X configuration register, array offset: 0x3014, array step: 0x100 */
         uint8_t RESERVED_1[8];
    __IO uint32_t E_CFH_DIDVID;                      /**< ENETC 0 config header device ID and vendor ID register..ENETC 1 config header device ID and vendor ID register, array offset: 0x3020, array step: 0x100 */
    __IO uint32_t E_CFH_SIDSVID;                     /**< ENETC 0 config header subsystem ID and subsystem vendor ID register..ENETC 1 config header subsystem ID and subsystem vendor ID register, array offset: 0x3024, array step: 0x100 */
    __IO uint32_t E_CFC_VFDID;                       /**< ENETC 0 config capability VF device ID register..ENETC 1 config capability VF device ID register, array offset: 0x3028, array step: 0x100 */
         uint8_t RESERVED_2[4];
    __IO uint32_t EBCAR;                             /**< ENETC 0 buffer cache attribute register 0..ENETC 1 buffer cache attribute register 0, array offset: 0x3030, array step: 0x100 */
    __IO uint32_t EMCAR;                             /**< ENETC 0 message cache attribute register..ENETC 1 message cache attribute register, array offset: 0x3034, array step: 0x100 */
    __IO uint32_t ECAR;                              /**< ENETC 0 command cache attribute register..ENETC 1 command cache attribute register, array offset: 0x3038, array step: 0x100 */
         uint8_t RESERVED_3[4];
    __IO uint32_t EAMQR;                             /**< ENETC 0 access management qualifier register..ENETC 1 access management qualifier register, array offset: 0x3040, array step: 0x100 */
         uint8_t RESERVED_4[4];
    __IO uint32_t EBLPR[NETC_IERB_CFG_ENETC_INST_ENETC_PF_BOOT_LOAD_COUNT];   /**< ENETC 0 boot loader parameter register 0..ENETC 1 boot loader parameter register 1, array offset: 0x3048, array step: index*0x100, index2*0x4 */
    __IO uint32_t ERXMBER;                           /**< ENETC 0 receive memory buffer entitlement register..ENETC 1 receive memory buffer entitlement register, array offset: 0x3050, array step: 0x100 */
    __IO uint32_t ERXMBLR;                           /**< ENETC 0 receive memory buffer limit register..ENETC 1 receive memory buffer limit register, array offset: 0x3054, array step: 0x100 */
         uint8_t RESERVED_5[24];
    __IO uint32_t ETXHPTBCR;                         /**< ENETC 0 transmit high priority tier byte credit register..ENETC 1 transmit high priority tier byte credit register, array offset: 0x3070, array step: 0x100 */
    __IO uint32_t ETXLPTBCR;                         /**< ENETC 0 transmit low priority tier byte credit register..ENETC 1 transmit low priority tier byte credit register, array offset: 0x3074, array step: 0x100 */
         uint8_t RESERVED_6[8];
    __IO uint32_t EHTMAR;                            /**< ENETC 0 hash table memory allotment register..ENETC 1 hash table memory allotment register, array offset: 0x3080, array step: 0x100 */
    __IO uint32_t EITMAR;                            /**< ENETC 0 index table memory allocation register..ENETC 1 index table memory allocation register, array offset: 0x3084, array step: 0x100 */
    __IO uint32_t EIPFTMAR;                          /**< ENETC 0 ingress port filter table memory allocation register..ENETC 1 ingress port filter table memory allocation register, array offset: 0x3088, array step: 0x100 */
         uint8_t RESERVED_7[20];
    __IO uint32_t ERPITMAR;                          /**< ENETC 0 rate policer index table memory allocation register..ENETC 1 rate policer index table memory allocation register, array offset: 0x30A0, array step: 0x100 */
    __IO uint32_t EISCITMAR;                         /**< ENETC 0 ingress stream counter index table memory allocation register..ENETC 1 ingress stream counter index table memory allocation register, array offset: 0x30A4, array step: 0x100 */
    __IO uint32_t EISITMAR;                          /**< ENETC 0 ingress stream index table memory allocation register..ENETC 1 ingress stream index table memory allocation register, array offset: 0x30A8, array step: 0x100 */
         uint8_t RESERVED_8[8];
    __IO uint32_t ESGIITMAR;                         /**< ENETC 0 stream gate instance index table memory allocation register..ENETC 1 stream gate instance index table memory allocation register, array offset: 0x30B4, array step: 0x100 */
    __IO uint32_t ESGCLITMAR;                        /**< ENETC 0 stream gate control list index table memory allocation register..ENETC 1 stream gate control list index table memory allocation register, array offset: 0x30B8, array step: 0x100 */
         uint8_t RESERVED_9[52];
    __IO uint32_t ETGSTAR;                           /**< ENETC 0 time gate scheduling table allocation register..ENETC 1 time gate scheduling table allocation register, array offset: 0x30F0, array step: 0x100 */
    __IO uint32_t ETGSLR;                            /**< ENETC 0 time gate scheduling lookahead register..ENETC 1 time gate scheduling lookahead register, array offset: 0x30F4, array step: 0x100 */
         uint8_t RESERVED_10[8];
  } CFG_ENETC_INST[NETC_IERB_CFG_ENETC_INST_COUNT];
       uint8_t RESERVED_35[3584];
  struct {                                         /* offset: 0x4000, array step: 0x18 */
    __IO uint32_t VAMQR;                             /**< VSI 0 access management qualifier register, array offset: 0x4000, array step: 0x18 */
         uint8_t RESERVED_0[4];
    __IO uint32_t VBLPR[NETC_IERB_CFG_VSI_INST_VSI_PF_BOOT_LOAD_COUNT];   /**< VSI 0 boot loader parameter register 0..VSI 0 boot loader parameter register 1, array offset: 0x4008, array step: index*0x18, index2*0x4 */
    __IO uint32_t VPMAR0;                            /**< VSI 0 primary MAC address register 0, array offset: 0x4010, array step: 0x18 */
    __IO uint32_t VPMAR1;                            /**< VSI 0 primary MAC address register 1, array offset: 0x4014, array step: 0x18 */
  } CFG_VSI_INST[NETC_IERB_CFG_VSI_INST_COUNT];
} NETC_IERB_Type;

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
#define NETC_IERB_CAPR0_NUM_RC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_RC_SHIFT)) & NETC_IERB_CAPR0_NUM_RC_MASK)

#define NETC_IERB_CAPR0_NUM_EMDIO_MASK           (0x10U)
#define NETC_IERB_CAPR0_NUM_EMDIO_SHIFT          (4U)
#define NETC_IERB_CAPR0_NUM_EMDIO(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_EMDIO_SHIFT)) & NETC_IERB_CAPR0_NUM_EMDIO_MASK)

#define NETC_IERB_CAPR0_NUM_TMR_MASK             (0xC0U)
#define NETC_IERB_CAPR0_NUM_TMR_SHIFT            (6U)
#define NETC_IERB_CAPR0_NUM_TMR(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_TMR_SHIFT)) & NETC_IERB_CAPR0_NUM_TMR_MASK)

#define NETC_IERB_CAPR0_NUM_LINKS_MASK           (0x1F00U)
#define NETC_IERB_CAPR0_NUM_LINKS_SHIFT          (8U)
#define NETC_IERB_CAPR0_NUM_LINKS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_LINKS_SHIFT)) & NETC_IERB_CAPR0_NUM_LINKS_MASK)

#define NETC_IERB_CAPR0_NUM_SW_MASK              (0x30000U)
#define NETC_IERB_CAPR0_NUM_SW_SHIFT             (16U)
#define NETC_IERB_CAPR0_NUM_SW(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_SW_SHIFT)) & NETC_IERB_CAPR0_NUM_SW_MASK)

#define NETC_IERB_CAPR0_NUM_ENETC_MASK           (0xF80000U)
#define NETC_IERB_CAPR0_NUM_ENETC_SHIFT          (19U)
#define NETC_IERB_CAPR0_NUM_ENETC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_ENETC_SHIFT)) & NETC_IERB_CAPR0_NUM_ENETC_MASK)

#define NETC_IERB_CAPR0_NUM_VSI_MASK             (0x7F000000U)
#define NETC_IERB_CAPR0_NUM_VSI_SHIFT            (24U)
#define NETC_IERB_CAPR0_NUM_VSI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR0_NUM_VSI_SHIFT)) & NETC_IERB_CAPR0_NUM_VSI_MASK)
/*! @} */

/*! @name CAPR1 - Capability register 1 */
/*! @{ */

#define NETC_IERB_CAPR1_NUM_RX_BDR_MASK          (0x3FFU)
#define NETC_IERB_CAPR1_NUM_RX_BDR_SHIFT         (0U)
#define NETC_IERB_CAPR1_NUM_RX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR1_NUM_RX_BDR_SHIFT)) & NETC_IERB_CAPR1_NUM_RX_BDR_MASK)

#define NETC_IERB_CAPR1_NUM_TX_BDR_MASK          (0x3FF0000U)
#define NETC_IERB_CAPR1_NUM_TX_BDR_SHIFT         (16U)
#define NETC_IERB_CAPR1_NUM_TX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR1_NUM_TX_BDR_SHIFT)) & NETC_IERB_CAPR1_NUM_TX_BDR_MASK)
/*! @} */

/*! @name CAPR2 - Capability register 2 */
/*! @{ */

#define NETC_IERB_CAPR2_NUM_MSIX_MASK            (0x7FFU)
#define NETC_IERB_CAPR2_NUM_MSIX_SHIFT           (0U)
#define NETC_IERB_CAPR2_NUM_MSIX(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR2_NUM_MSIX_SHIFT)) & NETC_IERB_CAPR2_NUM_MSIX_MASK)
/*! @} */

/*! @name CAPR3 - Capability register 3 */
/*! @{ */

#define NETC_IERB_CAPR3_NUM_MAC_AFTE_MASK        (0xFFFU)
#define NETC_IERB_CAPR3_NUM_MAC_AFTE_SHIFT       (0U)
#define NETC_IERB_CAPR3_NUM_MAC_AFTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR3_NUM_MAC_AFTE_SHIFT)) & NETC_IERB_CAPR3_NUM_MAC_AFTE_MASK)

#define NETC_IERB_CAPR3_NUM_VLAN_FTE_MASK        (0xFFF0000U)
#define NETC_IERB_CAPR3_NUM_VLAN_FTE_SHIFT       (16U)
#define NETC_IERB_CAPR3_NUM_VLAN_FTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CAPR3_NUM_VLAN_FTE_SHIFT)) & NETC_IERB_CAPR3_NUM_VLAN_FTE_MASK)
/*! @} */

/*! @name CMCAPR - Common memory capability register */
/*! @{ */

#define NETC_IERB_CMCAPR_NUM_WORDS_MASK          (0xFFFFFFU)
#define NETC_IERB_CMCAPR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_CMCAPR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_CMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_CMCAPR_WORD_SIZE_MASK          (0x30000000U)
#define NETC_IERB_CMCAPR_WORD_SIZE_SHIFT         (28U)
#define NETC_IERB_CMCAPR_WORD_SIZE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_CMCAPR_WORD_SIZE_SHIFT)) & NETC_IERB_CMCAPR_WORD_SIZE_MASK)
/*! @} */

/*! @name IPFTMCAPR - Ingress port filter ternary memory capability register */
/*! @{ */

#define NETC_IERB_IPFTMCAPR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_IPFTMCAPR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_IPFTMCAPR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_IPFTMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_IPFTMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_IPFTMCAPR_WORD_SIZE_MASK       (0x30000000U)
#define NETC_IERB_IPFTMCAPR_WORD_SIZE_SHIFT      (28U)
#define NETC_IERB_IPFTMCAPR_WORD_SIZE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_IPFTMCAPR_WORD_SIZE_SHIFT)) & NETC_IERB_IPFTMCAPR_WORD_SIZE_MASK)
/*! @} */

/*! @name TGSMCAPR - Time gate scheduling memory capability register */
/*! @{ */

#define NETC_IERB_TGSMCAPR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_TGSMCAPR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_TGSMCAPR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TGSMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_TGSMCAPR_NUM_WORDS_MASK)
/*! @} */

/*! @name SMDTR - Shared memory depletion threshold register */
/*! @{ */

#define NETC_IERB_SMDTR_THRESH_MASK              (0xFFFFFFU)
#define NETC_IERB_SMDTR_THRESH_SHIFT             (0U)
#define NETC_IERB_SMDTR_THRESH(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMDTR_THRESH_SHIFT)) & NETC_IERB_SMDTR_THRESH_MASK)
/*! @} */

/*! @name ERSMBAR - ENETC receive shared memory buffer allotment register */
/*! @{ */

#define NETC_IERB_ERSMBAR_THRESH_MASK            (0xFFFFFFU)
#define NETC_IERB_ERSMBAR_THRESH_SHIFT           (0U)
#define NETC_IERB_ERSMBAR_THRESH(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERSMBAR_THRESH_SHIFT)) & NETC_IERB_ERSMBAR_THRESH_MASK)
/*! @} */

/*! @name HTAHPCR - HTA 0 HP configuration register */
/*! @{ */

#define NETC_IERB_HTAHPCR_BLIMIT_MASK            (0xFFFFU)
#define NETC_IERB_HTAHPCR_BLIMIT_SHIFT           (0U)
#define NETC_IERB_HTAHPCR_BLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTAHPCR_BLIMIT_SHIFT)) & NETC_IERB_HTAHPCR_BLIMIT_MASK)

#define NETC_IERB_HTAHPCR_FLIMIT_MASK            (0xFF000000U)
#define NETC_IERB_HTAHPCR_FLIMIT_SHIFT           (24U)
#define NETC_IERB_HTAHPCR_FLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTAHPCR_FLIMIT_SHIFT)) & NETC_IERB_HTAHPCR_FLIMIT_MASK)
/*! @} */

/* The count of NETC_IERB_HTAHPCR */
#define NETC_IERB_HTAHPCR_COUNT                  (1U)

/*! @name HTALPCR - HTA 0 LP configuration register */
/*! @{ */

#define NETC_IERB_HTALPCR_BLIMIT_MASK            (0xFFFFU)
#define NETC_IERB_HTALPCR_BLIMIT_SHIFT           (0U)
#define NETC_IERB_HTALPCR_BLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTALPCR_BLIMIT_SHIFT)) & NETC_IERB_HTALPCR_BLIMIT_MASK)

#define NETC_IERB_HTALPCR_FLIMIT_MASK            (0xFF000000U)
#define NETC_IERB_HTALPCR_FLIMIT_SHIFT           (24U)
#define NETC_IERB_HTALPCR_FLIMIT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HTALPCR_FLIMIT_SHIFT)) & NETC_IERB_HTALPCR_FLIMIT_MASK)
/*! @} */

/* The count of NETC_IERB_HTALPCR */
#define NETC_IERB_HTALPCR_COUNT                  (1U)

/*! @name HBTMAR - Hash bucket table memory allocation register */
/*! @{ */

#define NETC_IERB_HBTMAR_NUM_WORDS_MASK          (0x3FFFU)
#define NETC_IERB_HBTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_HBTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_HBTMAR_NUM_WORDS_MASK)

#define NETC_IERB_HBTMAR_MIN_WORDS_MASK          (0xFF0000U)
#define NETC_IERB_HBTMAR_MIN_WORDS_SHIFT         (16U)
#define NETC_IERB_HBTMAR_MIN_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_MIN_WORDS_SHIFT)) & NETC_IERB_HBTMAR_MIN_WORDS_MASK)

#define NETC_IERB_HBTMAR_NEPW_MASK               (0x7000000U)
#define NETC_IERB_HBTMAR_NEPW_SHIFT              (24U)
#define NETC_IERB_HBTMAR_NEPW(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_NEPW_SHIFT)) & NETC_IERB_HBTMAR_NEPW_MASK)

#define NETC_IERB_HBTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_HBTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_HBTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTMAR_MLOC_SHIFT)) & NETC_IERB_HBTMAR_MLOC_MASK)
/*! @} */

/*! @name HBTCR - Hash bucket table configuration register */
/*! @{ */

#define NETC_IERB_HBTCR_MAX_COL_MASK             (0x7U)
#define NETC_IERB_HBTCR_MAX_COL_SHIFT            (0U)
#define NETC_IERB_HBTCR_MAX_COL(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTCR_MAX_COL_SHIFT)) & NETC_IERB_HBTCR_MAX_COL_MASK)

#define NETC_IERB_HBTCR_MAX_VISITS_MASK          (0xF0U)
#define NETC_IERB_HBTCR_MAX_VISITS_SHIFT         (4U)
#define NETC_IERB_HBTCR_MAX_VISITS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_HBTCR_MAX_VISITS_SHIFT)) & NETC_IERB_HBTCR_MAX_VISITS_MASK)
/*! @} */

/*! @name GHTEMCAPR - Guaranteed hash table entry memory capability register */
/*! @{ */

#define NETC_IERB_GHTEMCAPR_NUM_WORDS_MASK       (0x1FFU)
#define NETC_IERB_GHTEMCAPR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_GHTEMCAPR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_GHTEMCAPR_NUM_WORDS_SHIFT)) & NETC_IERB_GHTEMCAPR_NUM_WORDS_MASK)

#define NETC_IERB_GHTEMCAPR_MLOC_MASK            (0xC0000000U)
#define NETC_IERB_GHTEMCAPR_MLOC_SHIFT           (30U)
#define NETC_IERB_GHTEMCAPR_MLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_GHTEMCAPR_MLOC_SHIFT)) & NETC_IERB_GHTEMCAPR_MLOC_MASK)
/*! @} */

/*! @name NETCFLRCR - NETC FLR configuration register */
/*! @{ */

#define NETC_IERB_NETCFLRCR_VALUE_MASK           (0x1FFU)
#define NETC_IERB_NETCFLRCR_VALUE_SHIFT          (0U)
#define NETC_IERB_NETCFLRCR_VALUE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCFLRCR_VALUE_SHIFT)) & NETC_IERB_NETCFLRCR_VALUE_MASK)

#define NETC_IERB_NETCFLRCR_SCALE_MASK           (0xE00U)
#define NETC_IERB_NETCFLRCR_SCALE_SHIFT          (9U)
/*! SCALE - Scale */
#define NETC_IERB_NETCFLRCR_SCALE(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCFLRCR_SCALE_SHIFT)) & NETC_IERB_NETCFLRCR_SCALE_MASK)
/*! @} */

/*! @name NETCCLKFR - NETC clock period fractional register */
/*! @{ */

#define NETC_IERB_NETCCLKFR_FRAC_MASK            (0xFFFFFFFFU)
#define NETC_IERB_NETCCLKFR_FRAC_SHIFT           (0U)
#define NETC_IERB_NETCCLKFR_FRAC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKFR_FRAC_SHIFT)) & NETC_IERB_NETCCLKFR_FRAC_MASK)
/*! @} */

/*! @name NETCCLKCR - NETC clock configuration register */
/*! @{ */

#define NETC_IERB_NETCCLKCR_FREQ_MASK            (0x7FFU)
#define NETC_IERB_NETCCLKCR_FREQ_SHIFT           (0U)
/*! FREQ - Frequency */
#define NETC_IERB_NETCCLKCR_FREQ(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKCR_FREQ_SHIFT)) & NETC_IERB_NETCCLKCR_FREQ_MASK)

#define NETC_IERB_NETCCLKCR_PERIOD_MASK          (0x3FF0000U)
#define NETC_IERB_NETCCLKCR_PERIOD_SHIFT         (16U)
/*! PERIOD - Period */
#define NETC_IERB_NETCCLKCR_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_NETCCLKCR_PERIOD_SHIFT)) & NETC_IERB_NETCCLKCR_PERIOD_MASK)
/*! @} */

/*! @name SBCR - System bus configuration register */
/*! @{ */

#define NETC_IERB_SBCR_WBS_MASK                  (0x3U)
#define NETC_IERB_SBCR_WBS_SHIFT                 (0U)
#define NETC_IERB_SBCR_WBS(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_WBS_SHIFT)) & NETC_IERB_SBCR_WBS_MASK)

#define NETC_IERB_SBCR_RBS_MASK                  (0xCU)
#define NETC_IERB_SBCR_RBS_SHIFT                 (2U)
#define NETC_IERB_SBCR_RBS(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_RBS_SHIFT)) & NETC_IERB_SBCR_RBS_MASK)
/*! @} */

/*! @name SBOTCR - System bus outstanding transaction control register */
/*! @{ */

#define NETC_IERB_SBOTCR_OT_LIMIT_MASK           (0xFFFFFFFFU)
#define NETC_IERB_SBOTCR_OT_LIMIT_SHIFT          (0U)
#define NETC_IERB_SBOTCR_OT_LIMIT(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBOTCR_OT_LIMIT_SHIFT)) & NETC_IERB_SBOTCR_OT_LIMIT_MASK)
/*! @} */

/*! @name SGLTTR - Stream gating lag time for refresh register */
/*! @{ */

#define NETC_IERB_SGLTTR_LAG_TIME_MASK           (0x1FU)
#define NETC_IERB_SGLTTR_LAG_TIME_SHIFT          (0U)
#define NETC_IERB_SGLTTR_LAG_TIME(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SGLTTR_LAG_TIME_SHIFT)) & NETC_IERB_SGLTTR_LAG_TIME_MASK)
/*! @} */

/*! @name RBCR - Root complex 0 binding configuration register */
/*! @{ */

#define NETC_IERB_RBCR_TYPE_MASK                 (0x1U)
#define NETC_IERB_RBCR_TYPE_SHIFT                (0U)
#define NETC_IERB_RBCR_TYPE(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RBCR_TYPE_SHIFT)) & NETC_IERB_RBCR_TYPE_MASK)

#define NETC_IERB_RBCR_PORT_MASK                 (0xF0U)
#define NETC_IERB_RBCR_PORT_SHIFT                (4U)
#define NETC_IERB_RBCR_PORT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RBCR_PORT_SHIFT)) & NETC_IERB_RBCR_PORT_MASK)
/*! @} */

/* The count of NETC_IERB_RBCR */
#define NETC_IERB_RBCR_COUNT                     (1U)

/*! @name RCMSICAR - Root complex 0 MSI-X cache attribute register */
/*! @{ */

#define NETC_IERB_RCMSICAR_MSI_WRCACHE_MASK      (0xFU)
#define NETC_IERB_RCMSICAR_MSI_WRCACHE_SHIFT     (0U)
#define NETC_IERB_RCMSICAR_MSI_WRCACHE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRCACHE_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRCACHE_MASK)

#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN_MASK     (0x30U)
#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN_SHIFT    (4U)
#define NETC_IERB_RCMSICAR_MSI_WRDOMAIN(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRDOMAIN_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRDOMAIN_MASK)

#define NETC_IERB_RCMSICAR_MSI_WRSNP_MASK        (0x40U)
#define NETC_IERB_RCMSICAR_MSI_WRSNP_SHIFT       (6U)
#define NETC_IERB_RCMSICAR_MSI_WRSNP(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSICAR_MSI_WRSNP_SHIFT)) & NETC_IERB_RCMSICAR_MSI_WRSNP_MASK)
/*! @} */

/* The count of NETC_IERB_RCMSICAR */
#define NETC_IERB_RCMSICAR_COUNT                 (1U)

/*! @name RCMSIAMQR - Root complex 0 MSI access management qualifier register */
/*! @{ */

#define NETC_IERB_RCMSIAMQR_AWQOS_MASK           (0xF00000U)
#define NETC_IERB_RCMSIAMQR_AWQOS_SHIFT          (20U)
#define NETC_IERB_RCMSIAMQR_AWQOS(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSIAMQR_AWQOS_SHIFT)) & NETC_IERB_RCMSIAMQR_AWQOS_MASK)

#define NETC_IERB_RCMSIAMQR_BMT_MASK             (0x80000000U)
#define NETC_IERB_RCMSIAMQR_BMT_SHIFT            (31U)
#define NETC_IERB_RCMSIAMQR_BMT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_RCMSIAMQR_BMT_SHIFT)) & NETC_IERB_RCMSIAMQR_BMT_MASK)
/*! @} */

/* The count of NETC_IERB_RCMSIAMQR */
#define NETC_IERB_RCMSIAMQR_COUNT                (1U)

/*! @name EMDIOBCR - EMDIO binding configuration register */
/*! @{ */

#define NETC_IERB_EMDIOBCR_RC_INST_MASK          (0xFU)
#define NETC_IERB_EMDIOBCR_RC_INST_SHIFT         (0U)
#define NETC_IERB_EMDIOBCR_RC_INST(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_RC_INST_SHIFT)) & NETC_IERB_EMDIOBCR_RC_INST_MASK)

#define NETC_IERB_EMDIOBCR_FN_MASK               (0xF00U)
#define NETC_IERB_EMDIOBCR_FN_SHIFT              (8U)
#define NETC_IERB_EMDIOBCR_FN(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_FN_SHIFT)) & NETC_IERB_EMDIOBCR_FN_MASK)

#define NETC_IERB_EMDIOBCR_VALID_MASK            (0x80000000U)
#define NETC_IERB_EMDIOBCR_VALID_SHIFT           (31U)
#define NETC_IERB_EMDIOBCR_VALID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBCR_VALID_SHIFT)) & NETC_IERB_EMDIOBCR_VALID_MASK)
/*! @} */

/*! @name EMDIOMCR - EMDIO MSI-X configuration register */
/*! @{ */

#define NETC_IERB_EMDIOMCR_NUM_MSIX_MASK         (0x1U)
#define NETC_IERB_EMDIOMCR_NUM_MSIX_SHIFT        (0U)
#define NETC_IERB_EMDIOMCR_NUM_MSIX(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOMCR_NUM_MSIX_SHIFT)) & NETC_IERB_EMDIOMCR_NUM_MSIX_MASK)
/*! @} */

/*! @name EMDIO_CFH_DIDVID - EMDIO config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID(x)  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID(x)  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/*! @name EMDIO_CFH_SIDSVID - EMDIO config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_EMDIO_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/*! @name EMDIOBLPR - EMDIO boot loader parameter register 0..EMDIO boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_EMDIOBLPR_PARAM_VAL_MASK       (0xFFFFFFFFU)
#define NETC_IERB_EMDIOBLPR_PARAM_VAL_SHIFT      (0U)
#define NETC_IERB_EMDIOBLPR_PARAM_VAL(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIOBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_EMDIOBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of NETC_IERB_EMDIOBLPR */
#define NETC_IERB_EMDIOBLPR_COUNT                (2U)

/*! @name EMDIO_CFG - EMDIO configuration register */
/*! @{ */

#define NETC_IERB_EMDIO_CFG_MDIO_MODE_MASK       (0x10U)
#define NETC_IERB_EMDIO_CFG_MDIO_MODE_SHIFT      (4U)
#define NETC_IERB_EMDIO_CFG_MDIO_MODE(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFG_MDIO_MODE_SHIFT)) & NETC_IERB_EMDIO_CFG_MDIO_MODE_MASK)

#define NETC_IERB_EMDIO_CFG_MDC_MODE_MASK        (0x20U)
#define NETC_IERB_EMDIO_CFG_MDC_MODE_SHIFT       (5U)
#define NETC_IERB_EMDIO_CFG_MDC_MODE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMDIO_CFG_MDC_MODE_SHIFT)) & NETC_IERB_EMDIO_CFG_MDC_MODE_MASK)
/*! @} */

/*! @name TBCR - Timer 0 binding configuration register */
/*! @{ */

#define NETC_IERB_TBCR_RC_INST_MASK              (0xFU)
#define NETC_IERB_TBCR_RC_INST_SHIFT             (0U)
#define NETC_IERB_TBCR_RC_INST(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_RC_INST_SHIFT)) & NETC_IERB_TBCR_RC_INST_MASK)

#define NETC_IERB_TBCR_FN_MASK                   (0xF00U)
#define NETC_IERB_TBCR_FN_SHIFT                  (8U)
#define NETC_IERB_TBCR_FN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_FN_SHIFT)) & NETC_IERB_TBCR_FN_MASK)

#define NETC_IERB_TBCR_VALID_MASK                (0x80000000U)
#define NETC_IERB_TBCR_VALID_SHIFT               (31U)
#define NETC_IERB_TBCR_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBCR_VALID_SHIFT)) & NETC_IERB_TBCR_VALID_MASK)
/*! @} */

/* The count of NETC_IERB_TBCR */
#define NETC_IERB_TBCR_COUNT                     (1U)

/*! @name TMCR - Timer 0 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_TMCR_NUM_MSIX_MASK             (0x1U)
#define NETC_IERB_TMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_TMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TMCR_NUM_MSIX_SHIFT)) & NETC_IERB_TMCR_NUM_MSIX_MASK)
/*! @} */

/* The count of NETC_IERB_TMCR */
#define NETC_IERB_TMCR_COUNT                     (1U)

/*! @name T_CFH_DIDVID - Timer 0 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_T_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_T_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_T_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_T_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_T_CFH_DIDVID */
#define NETC_IERB_T_CFH_DIDVID_COUNT             (1U)

/*! @name T_CFH_SIDSVID - Timer 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_T_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_T_CFH_SIDSVID */
#define NETC_IERB_T_CFH_SIDSVID_COUNT            (1U)

/*! @name TBLPR - Timer 0 boot loader parameter register 0..Timer 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_TBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_TBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_TBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_TBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_TBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of NETC_IERB_TBLPR */
#define NETC_IERB_TBLPR_COUNT                    (1U)

/* The count of NETC_IERB_TBLPR */
#define NETC_IERB_TBLPR_COUNT2                   (2U)

/*! @name L0CAPR - Link 0 capability register */
/*! @{ */

#define NETC_IERB_L0CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L0CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L0CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L0CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L0CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L0CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L0CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_TC_SHIFT)) & NETC_IERB_L0CAPR_NUM_TC_MASK)

#define NETC_IERB_L0CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L0CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L0CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_Q_SHIFT)) & NETC_IERB_L0CAPR_NUM_Q_MASK)

#define NETC_IERB_L0CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L0CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L0CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_NUM_CG_SHIFT)) & NETC_IERB_L0CAPR_NUM_CG_MASK)

#define NETC_IERB_L0CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L0CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L0CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_TGS_SHIFT)) & NETC_IERB_L0CAPR_TGS_MASK)

#define NETC_IERB_L0CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L0CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L0CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0CAPR_CBS_SHIFT)) & NETC_IERB_L0CAPR_CBS_MASK)
/*! @} */

/*! @name L0MCAPR - Link 0 MAC capability register */
/*! @{ */

#define NETC_IERB_L0MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L0MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L0MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L0MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L0MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L0MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L0MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_EFPAD_SHIFT)) & NETC_IERB_L0MCAPR_EFPAD_MASK)

#define NETC_IERB_L0MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L0MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L0MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_PIPG_SHIFT)) & NETC_IERB_L0MCAPR_PIPG_MASK)

#define NETC_IERB_L0MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L0MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L0MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_HD_SHIFT)) & NETC_IERB_L0MCAPR_HD_MASK)

#define NETC_IERB_L0MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L0MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L0MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_FP_SHIFT)) & NETC_IERB_L0MCAPR_FP_MASK)

#define NETC_IERB_L0MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L0MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L0MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L0MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L0MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L0MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L0MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L0MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L0IOCAPR - Link 0 I/O capability register */
/*! @{ */

#define NETC_IERB_L0IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L0IOCAPR_PCS_PROT_SHIFT        (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_IERB_L0IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L0IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L0IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L0IOCAPR_IO_VAR_SHIFT          (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_IERB_L0IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L0IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L0IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L0IOCAPR_EMDIO_SHIFT           (28U)
/*! EMDIO - External MDIO supported. */
#define NETC_IERB_L0IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L0IOCAPR_EMDIO_MASK)

#define NETC_IERB_L0IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L0IOCAPR_REVMII_RATE_SHIFT     (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_IERB_L0IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L0IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L0IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L0IOCAPR_REVMII_SHIFT          (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_IERB_L0IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0IOCAPR_REVMII_SHIFT)) & NETC_IERB_L0IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L0BCR - Link 0 binding configuration register */
/*! @{ */

#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L0BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L0BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L0BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L0BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L0BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L0BCR_NETC_FUNC_MASK)

#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L0BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L0BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L0BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L0BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L0BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L0TXBCCTR - Link 0 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L0TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L0TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L0TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L0TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L0E0MAR0 - Link 0 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L0E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L0E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L0E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L0E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L0E0MAR1 - Link 0 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L0E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L0E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L0E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L0E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L0E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L1CAPR - Link 1 capability register */
/*! @{ */

#define NETC_IERB_L1CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L1CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L1CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L1CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L1CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L1CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L1CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_TC_SHIFT)) & NETC_IERB_L1CAPR_NUM_TC_MASK)

#define NETC_IERB_L1CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L1CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L1CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_Q_SHIFT)) & NETC_IERB_L1CAPR_NUM_Q_MASK)

#define NETC_IERB_L1CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L1CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L1CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_NUM_CG_SHIFT)) & NETC_IERB_L1CAPR_NUM_CG_MASK)

#define NETC_IERB_L1CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L1CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L1CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_TGS_SHIFT)) & NETC_IERB_L1CAPR_TGS_MASK)

#define NETC_IERB_L1CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L1CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L1CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1CAPR_CBS_SHIFT)) & NETC_IERB_L1CAPR_CBS_MASK)
/*! @} */

/*! @name L1MCAPR - Link 1 MAC capability register */
/*! @{ */

#define NETC_IERB_L1MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L1MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L1MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L1MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L1MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L1MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L1MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_EFPAD_SHIFT)) & NETC_IERB_L1MCAPR_EFPAD_MASK)

#define NETC_IERB_L1MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L1MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L1MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_PIPG_SHIFT)) & NETC_IERB_L1MCAPR_PIPG_MASK)

#define NETC_IERB_L1MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L1MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L1MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_HD_SHIFT)) & NETC_IERB_L1MCAPR_HD_MASK)

#define NETC_IERB_L1MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L1MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L1MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_FP_SHIFT)) & NETC_IERB_L1MCAPR_FP_MASK)

#define NETC_IERB_L1MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L1MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L1MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L1MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L1MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L1MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L1MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L1MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L1IOCAPR - Link 1 I/O capability register */
/*! @{ */

#define NETC_IERB_L1IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L1IOCAPR_PCS_PROT_SHIFT        (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_IERB_L1IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L1IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L1IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L1IOCAPR_IO_VAR_SHIFT          (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_IERB_L1IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L1IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L1IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L1IOCAPR_EMDIO_SHIFT           (28U)
/*! EMDIO - External MDIO supported. */
#define NETC_IERB_L1IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L1IOCAPR_EMDIO_MASK)

#define NETC_IERB_L1IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L1IOCAPR_REVMII_RATE_SHIFT     (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_IERB_L1IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L1IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L1IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L1IOCAPR_REVMII_SHIFT          (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_IERB_L1IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1IOCAPR_REVMII_SHIFT)) & NETC_IERB_L1IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L1BCR - Link 1 binding configuration register */
/*! @{ */

#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L1BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L1BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L1BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L1BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L1BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L1BCR_NETC_FUNC_MASK)

#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L1BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L1BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L1BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L1BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L1BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L1TXBCCTR - Link 1 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L1TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L1TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L1TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L1TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L1E0MAR0 - Link 1 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L1E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L1E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L1E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L1E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L1E0MAR1 - Link 1 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L1E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L1E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L1E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L1E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L1E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L2CAPR - Link 2 capability register */
/*! @{ */

#define NETC_IERB_L2CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L2CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L2CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L2CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L2CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L2CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L2CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_TC_SHIFT)) & NETC_IERB_L2CAPR_NUM_TC_MASK)

#define NETC_IERB_L2CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L2CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L2CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_Q_SHIFT)) & NETC_IERB_L2CAPR_NUM_Q_MASK)

#define NETC_IERB_L2CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L2CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L2CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_NUM_CG_SHIFT)) & NETC_IERB_L2CAPR_NUM_CG_MASK)

#define NETC_IERB_L2CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L2CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L2CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_TGS_SHIFT)) & NETC_IERB_L2CAPR_TGS_MASK)

#define NETC_IERB_L2CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L2CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L2CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2CAPR_CBS_SHIFT)) & NETC_IERB_L2CAPR_CBS_MASK)
/*! @} */

/*! @name L2MCAPR - Link 2 MAC capability register */
/*! @{ */

#define NETC_IERB_L2MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L2MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L2MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L2MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L2MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L2MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L2MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_EFPAD_SHIFT)) & NETC_IERB_L2MCAPR_EFPAD_MASK)

#define NETC_IERB_L2MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L2MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L2MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_PIPG_SHIFT)) & NETC_IERB_L2MCAPR_PIPG_MASK)

#define NETC_IERB_L2MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L2MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L2MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_HD_SHIFT)) & NETC_IERB_L2MCAPR_HD_MASK)

#define NETC_IERB_L2MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L2MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L2MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_FP_SHIFT)) & NETC_IERB_L2MCAPR_FP_MASK)

#define NETC_IERB_L2MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L2MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L2MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L2MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L2MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L2MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L2MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L2MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L2IOCAPR - Link 2 I/O capability register */
/*! @{ */

#define NETC_IERB_L2IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L2IOCAPR_PCS_PROT_SHIFT        (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_IERB_L2IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L2IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L2IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L2IOCAPR_IO_VAR_SHIFT          (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_IERB_L2IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L2IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L2IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L2IOCAPR_EMDIO_SHIFT           (28U)
/*! EMDIO - External MDIO supported. */
#define NETC_IERB_L2IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L2IOCAPR_EMDIO_MASK)

#define NETC_IERB_L2IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L2IOCAPR_REVMII_RATE_SHIFT     (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_IERB_L2IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L2IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L2IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L2IOCAPR_REVMII_SHIFT          (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_IERB_L2IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2IOCAPR_REVMII_SHIFT)) & NETC_IERB_L2IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L2BCR - Link 2 binding configuration register */
/*! @{ */

#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L2BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L2BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L2BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L2BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L2BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L2BCR_NETC_FUNC_MASK)

#define NETC_IERB_L2BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L2BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L2BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L2BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L2BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L2BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L2BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L2BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L2TXBCCTR - Link 2 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L2TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L2TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L2TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L2TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L2E0MAR0 - Link 2 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L2E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L2E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L2E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L2E0MAR1 - Link 2 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L2E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L2E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L2E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L2E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L2E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L3CAPR - Link 3 capability register */
/*! @{ */

#define NETC_IERB_L3CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L3CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L3CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L3CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L3CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L3CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L3CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_NUM_TC_SHIFT)) & NETC_IERB_L3CAPR_NUM_TC_MASK)

#define NETC_IERB_L3CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L3CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L3CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_NUM_Q_SHIFT)) & NETC_IERB_L3CAPR_NUM_Q_MASK)

#define NETC_IERB_L3CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L3CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L3CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_NUM_CG_SHIFT)) & NETC_IERB_L3CAPR_NUM_CG_MASK)

#define NETC_IERB_L3CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L3CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L3CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_TGS_SHIFT)) & NETC_IERB_L3CAPR_TGS_MASK)

#define NETC_IERB_L3CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L3CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L3CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3CAPR_CBS_SHIFT)) & NETC_IERB_L3CAPR_CBS_MASK)
/*! @} */

/*! @name L3MCAPR - Link 3 MAC capability register */
/*! @{ */

#define NETC_IERB_L3MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L3MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L3MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L3MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L3MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L3MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L3MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_EFPAD_SHIFT)) & NETC_IERB_L3MCAPR_EFPAD_MASK)

#define NETC_IERB_L3MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L3MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L3MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_PIPG_SHIFT)) & NETC_IERB_L3MCAPR_PIPG_MASK)

#define NETC_IERB_L3MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L3MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L3MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_HD_SHIFT)) & NETC_IERB_L3MCAPR_HD_MASK)

#define NETC_IERB_L3MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L3MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L3MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_FP_SHIFT)) & NETC_IERB_L3MCAPR_FP_MASK)

#define NETC_IERB_L3MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L3MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L3MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L3MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L3MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L3MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L3MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L3MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L3IOCAPR - Link 3 I/O capability register */
/*! @{ */

#define NETC_IERB_L3IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L3IOCAPR_PCS_PROT_SHIFT        (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_IERB_L3IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L3IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L3IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L3IOCAPR_IO_VAR_SHIFT          (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_IERB_L3IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L3IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L3IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L3IOCAPR_EMDIO_SHIFT           (28U)
/*! EMDIO - External MDIO supported. */
#define NETC_IERB_L3IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L3IOCAPR_EMDIO_MASK)

#define NETC_IERB_L3IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L3IOCAPR_REVMII_RATE_SHIFT     (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_IERB_L3IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L3IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L3IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L3IOCAPR_REVMII_SHIFT          (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_IERB_L3IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3IOCAPR_REVMII_SHIFT)) & NETC_IERB_L3IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L3BCR - Link 3 binding configuration register */
/*! @{ */

#define NETC_IERB_L3BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L3BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L3BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L3BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L3BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L3BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L3BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L3BCR_NETC_FUNC_MASK)

#define NETC_IERB_L3BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L3BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L3BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L3BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L3BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L3BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L3BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L3BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L3TXBCCTR - Link 3 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L3TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L3TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L3TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L3TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L3E0MAR0 - Link 3 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L3E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L3E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L3E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L3E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L3E0MAR1 - Link 3 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L3E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L3E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L3E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L3E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L3E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L4CAPR - Link 4 capability register */
/*! @{ */

#define NETC_IERB_L4CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L4CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L4CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L4CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L4CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L4CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L4CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_NUM_TC_SHIFT)) & NETC_IERB_L4CAPR_NUM_TC_MASK)

#define NETC_IERB_L4CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L4CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L4CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_NUM_Q_SHIFT)) & NETC_IERB_L4CAPR_NUM_Q_MASK)

#define NETC_IERB_L4CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L4CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L4CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_NUM_CG_SHIFT)) & NETC_IERB_L4CAPR_NUM_CG_MASK)

#define NETC_IERB_L4CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L4CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L4CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_TGS_SHIFT)) & NETC_IERB_L4CAPR_TGS_MASK)

#define NETC_IERB_L4CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L4CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L4CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4CAPR_CBS_SHIFT)) & NETC_IERB_L4CAPR_CBS_MASK)
/*! @} */

/*! @name L4MCAPR - Link 4 MAC capability register */
/*! @{ */

#define NETC_IERB_L4MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L4MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L4MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L4MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L4MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L4MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L4MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_EFPAD_SHIFT)) & NETC_IERB_L4MCAPR_EFPAD_MASK)

#define NETC_IERB_L4MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L4MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L4MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_PIPG_SHIFT)) & NETC_IERB_L4MCAPR_PIPG_MASK)

#define NETC_IERB_L4MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L4MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L4MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_HD_SHIFT)) & NETC_IERB_L4MCAPR_HD_MASK)

#define NETC_IERB_L4MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L4MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L4MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_FP_SHIFT)) & NETC_IERB_L4MCAPR_FP_MASK)

#define NETC_IERB_L4MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L4MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L4MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L4MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L4MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L4MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L4MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L4MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L4IOCAPR - Link 4 I/O capability register */
/*! @{ */

#define NETC_IERB_L4IOCAPR_PCS_PROT_MASK         (0xFFFFU)
#define NETC_IERB_L4IOCAPR_PCS_PROT_SHIFT        (0U)
/*! PCS_PROT - PCS protocols supported */
#define NETC_IERB_L4IOCAPR_PCS_PROT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4IOCAPR_PCS_PROT_SHIFT)) & NETC_IERB_L4IOCAPR_PCS_PROT_MASK)

#define NETC_IERB_L4IOCAPR_IO_VAR_MASK           (0xF000000U)
#define NETC_IERB_L4IOCAPR_IO_VAR_SHIFT          (24U)
/*! IO_VAR - IO Variants supported */
#define NETC_IERB_L4IOCAPR_IO_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4IOCAPR_IO_VAR_SHIFT)) & NETC_IERB_L4IOCAPR_IO_VAR_MASK)

#define NETC_IERB_L4IOCAPR_EMDIO_MASK            (0x10000000U)
#define NETC_IERB_L4IOCAPR_EMDIO_SHIFT           (28U)
/*! EMDIO - External MDIO supported. */
#define NETC_IERB_L4IOCAPR_EMDIO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4IOCAPR_EMDIO_SHIFT)) & NETC_IERB_L4IOCAPR_EMDIO_MASK)

#define NETC_IERB_L4IOCAPR_REVMII_RATE_MASK      (0x40000000U)
#define NETC_IERB_L4IOCAPR_REVMII_RATE_SHIFT     (30U)
/*! REVMII_RATE - RevMII MII rate */
#define NETC_IERB_L4IOCAPR_REVMII_RATE(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4IOCAPR_REVMII_RATE_SHIFT)) & NETC_IERB_L4IOCAPR_REVMII_RATE_MASK)

#define NETC_IERB_L4IOCAPR_REVMII_MASK           (0x80000000U)
#define NETC_IERB_L4IOCAPR_REVMII_SHIFT          (31U)
/*! REVMII - Reverse Mode Device Configuration */
#define NETC_IERB_L4IOCAPR_REVMII(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4IOCAPR_REVMII_SHIFT)) & NETC_IERB_L4IOCAPR_REVMII_MASK)
/*! @} */

/*! @name L4BCR - Link 4 binding configuration register */
/*! @{ */

#define NETC_IERB_L4BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L4BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L4BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L4BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L4BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L4BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L4BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L4BCR_NETC_FUNC_MASK)

#define NETC_IERB_L4BCR_MDIO_PHYAD_PRTAD_MASK    (0x1F00U)
#define NETC_IERB_L4BCR_MDIO_PHYAD_PRTAD_SHIFT   (8U)
#define NETC_IERB_L4BCR_MDIO_PHYAD_PRTAD(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4BCR_MDIO_PHYAD_PRTAD_SHIFT)) & NETC_IERB_L4BCR_MDIO_PHYAD_PRTAD_MASK)

#define NETC_IERB_L4BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L4BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L4BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L4BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L4TXBCCTR - Link 4 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L4TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L4TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L4TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L4TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L4E0MAR0 - Link 4 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L4E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L4E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L4E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L4E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L4E0MAR1 - Link 4 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L4E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L4E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L4E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L4E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L4E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L5CAPR - Link 5 capability register */
/*! @{ */

#define NETC_IERB_L5CAPR_LINK_TYPE_MASK          (0x10U)
#define NETC_IERB_L5CAPR_LINK_TYPE_SHIFT         (4U)
#define NETC_IERB_L5CAPR_LINK_TYPE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_LINK_TYPE_SHIFT)) & NETC_IERB_L5CAPR_LINK_TYPE_MASK)

#define NETC_IERB_L5CAPR_NUM_TC_MASK             (0xF000U)
#define NETC_IERB_L5CAPR_NUM_TC_SHIFT            (12U)
#define NETC_IERB_L5CAPR_NUM_TC(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_NUM_TC_SHIFT)) & NETC_IERB_L5CAPR_NUM_TC_MASK)

#define NETC_IERB_L5CAPR_NUM_Q_MASK              (0xF0000U)
#define NETC_IERB_L5CAPR_NUM_Q_SHIFT             (16U)
/*! NUM_Q - Number of Egress Traffic Management (ETM) class queues supported */
#define NETC_IERB_L5CAPR_NUM_Q(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_NUM_Q_SHIFT)) & NETC_IERB_L5CAPR_NUM_Q_MASK)

#define NETC_IERB_L5CAPR_NUM_CG_MASK             (0xF000000U)
#define NETC_IERB_L5CAPR_NUM_CG_SHIFT            (24U)
/*! NUM_CG - Number of congestion groups supported */
#define NETC_IERB_L5CAPR_NUM_CG(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_NUM_CG_SHIFT)) & NETC_IERB_L5CAPR_NUM_CG_MASK)

#define NETC_IERB_L5CAPR_TGS_MASK                (0x10000000U)
#define NETC_IERB_L5CAPR_TGS_SHIFT               (28U)
/*! TGS - Time Gate Scheduling */
#define NETC_IERB_L5CAPR_TGS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_TGS_SHIFT)) & NETC_IERB_L5CAPR_TGS_MASK)

#define NETC_IERB_L5CAPR_CBS_MASK                (0x20000000U)
#define NETC_IERB_L5CAPR_CBS_SHIFT               (29U)
/*! CBS - Credit Based Shaping */
#define NETC_IERB_L5CAPR_CBS(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5CAPR_CBS_SHIFT)) & NETC_IERB_L5CAPR_CBS_MASK)
/*! @} */

/*! @name L5MCAPR - Link 5 MAC capability register */
/*! @{ */

#define NETC_IERB_L5MCAPR_MAC_VAR_MASK           (0x7U)
#define NETC_IERB_L5MCAPR_MAC_VAR_SHIFT          (0U)
/*! MAC_VAR - MAC Variant */
#define NETC_IERB_L5MCAPR_MAC_VAR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_MAC_VAR_SHIFT)) & NETC_IERB_L5MCAPR_MAC_VAR_MASK)

#define NETC_IERB_L5MCAPR_EFPAD_MASK             (0x30U)
#define NETC_IERB_L5MCAPR_EFPAD_SHIFT            (4U)
/*! EFPAD - Egress frame padding capability */
#define NETC_IERB_L5MCAPR_EFPAD(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_EFPAD_SHIFT)) & NETC_IERB_L5MCAPR_EFPAD_MASK)

#define NETC_IERB_L5MCAPR_PIPG_MASK              (0x40U)
#define NETC_IERB_L5MCAPR_PIPG_SHIFT             (6U)
/*! PIPG - Configurable preamble/IPG capability */
#define NETC_IERB_L5MCAPR_PIPG(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_PIPG_SHIFT)) & NETC_IERB_L5MCAPR_PIPG_MASK)

#define NETC_IERB_L5MCAPR_HD_MASK                (0x100U)
#define NETC_IERB_L5MCAPR_HD_SHIFT               (8U)
/*! HD - Half Duplex capability */
#define NETC_IERB_L5MCAPR_HD(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_HD_SHIFT)) & NETC_IERB_L5MCAPR_HD_MASK)

#define NETC_IERB_L5MCAPR_FP_MASK                (0x600U)
#define NETC_IERB_L5MCAPR_FP_SHIFT               (9U)
/*! FP - Indicates if frame preemption is supported */
#define NETC_IERB_L5MCAPR_FP(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_FP_SHIFT)) & NETC_IERB_L5MCAPR_FP_MASK)

#define NETC_IERB_L5MCAPR_MIN_MPDU_MASK          (0x1000U)
#define NETC_IERB_L5MCAPR_MIN_MPDU_SHIFT         (12U)
/*! MIN_MPDU - Minimum MAC Protocol Data Unit (PDU) size check */
#define NETC_IERB_L5MCAPR_MIN_MPDU(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_MIN_MPDU_SHIFT)) & NETC_IERB_L5MCAPR_MIN_MPDU_MASK)

#define NETC_IERB_L5MCAPR_MII_PROT_MASK          (0xF000000U)
#define NETC_IERB_L5MCAPR_MII_PROT_SHIFT         (24U)
/*! MII_PROT - Indicates the MII protocol supported */
#define NETC_IERB_L5MCAPR_MII_PROT(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5MCAPR_MII_PROT_SHIFT)) & NETC_IERB_L5MCAPR_MII_PROT_MASK)
/*! @} */

/*! @name L5BCR - Link 5 binding configuration register */
/*! @{ */

#define NETC_IERB_L5BCR_SW_PORT_ENETC_INST_MASK  (0x1FU)
#define NETC_IERB_L5BCR_SW_PORT_ENETC_INST_SHIFT (0U)
#define NETC_IERB_L5BCR_SW_PORT_ENETC_INST(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5BCR_SW_PORT_ENETC_INST_SHIFT)) & NETC_IERB_L5BCR_SW_PORT_ENETC_INST_MASK)

#define NETC_IERB_L5BCR_NETC_FUNC_MASK           (0x40U)
#define NETC_IERB_L5BCR_NETC_FUNC_SHIFT          (6U)
#define NETC_IERB_L5BCR_NETC_FUNC(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5BCR_NETC_FUNC_SHIFT)) & NETC_IERB_L5BCR_NETC_FUNC_MASK)

#define NETC_IERB_L5BCR_SPL_SW_PORT_MASK         (0x1F0000U)
#define NETC_IERB_L5BCR_SPL_SW_PORT_SHIFT        (16U)
#define NETC_IERB_L5BCR_SPL_SW_PORT(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5BCR_SPL_SW_PORT_SHIFT)) & NETC_IERB_L5BCR_SPL_SW_PORT_MASK)
/*! @} */

/*! @name L5TXBCCTR - Link 5 transmit byte credit comfort threshold register */
/*! @{ */

#define NETC_IERB_L5TXBCCTR_THRESH_MASK          (0xFFFFU)
#define NETC_IERB_L5TXBCCTR_THRESH_SHIFT         (0U)
#define NETC_IERB_L5TXBCCTR_THRESH(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5TXBCCTR_THRESH_SHIFT)) & NETC_IERB_L5TXBCCTR_THRESH_MASK)
/*! @} */

/*! @name L5E0MAR0 - Link 5 end 0 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L5E0MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L5E0MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L5E0MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5E0MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L5E0MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L5E0MAR1 - Link 5 end 0 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L5E0MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L5E0MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L5E0MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5E0MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L5E0MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name L5E1MAR0 - Link 5 end 1 MAC address register 0 */
/*! @{ */

#define NETC_IERB_L5E1MAR0_MAC_ADDR_MASK         (0xFFFFFFFFU)
#define NETC_IERB_L5E1MAR0_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L5E1MAR0_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5E1MAR0_MAC_ADDR_SHIFT)) & NETC_IERB_L5E1MAR0_MAC_ADDR_MASK)
/*! @} */

/*! @name L5E1MAR1 - Link 5 end 1 MAC address register 1 */
/*! @{ */

#define NETC_IERB_L5E1MAR1_MAC_ADDR_MASK         (0xFFFFU)
#define NETC_IERB_L5E1MAR1_MAC_ADDR_SHIFT        (0U)
#define NETC_IERB_L5E1MAR1_MAC_ADDR(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_L5E1MAR1_MAC_ADDR_SHIFT)) & NETC_IERB_L5E1MAR1_MAC_ADDR_MASK)
/*! @} */

/*! @name SBCR - Switch 0 binding configuration register */
/*! @{ */

#define NETC_IERB_SBCR_RC_INST_MASK              (0xFU)
#define NETC_IERB_SBCR_RC_INST_SHIFT             (0U)
#define NETC_IERB_SBCR_RC_INST(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_RC_INST_SHIFT)) & NETC_IERB_SBCR_RC_INST_MASK)

#define NETC_IERB_SBCR_FN_MASK                   (0xF00U)
#define NETC_IERB_SBCR_FN_SHIFT                  (8U)
#define NETC_IERB_SBCR_FN(x)                     (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_FN_SHIFT)) & NETC_IERB_SBCR_FN_MASK)

#define NETC_IERB_SBCR_VALID_MASK                (0x80000000U)
#define NETC_IERB_SBCR_VALID_SHIFT               (31U)
#define NETC_IERB_SBCR_VALID(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBCR_VALID_SHIFT)) & NETC_IERB_SBCR_VALID_MASK)
/*! @} */

/* The count of NETC_IERB_SBCR */
#define NETC_IERB_SBCR_COUNT                     (1U)

/*! @name SMCR - Switch 0 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_SMCR_NUM_MSIX_MASK             (0xFU)
#define NETC_IERB_SMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_SMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMCR_NUM_MSIX_SHIFT)) & NETC_IERB_SMCR_NUM_MSIX_MASK)
/*! @} */

/* The count of NETC_IERB_SMCR */
#define NETC_IERB_SMCR_COUNT                     (1U)

/*! @name S_CFH_DIDVID - Switch 0 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_S_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_S_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_S_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_S_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_S_CFH_DIDVID */
#define NETC_IERB_S_CFH_DIDVID_COUNT             (1U)

/*! @name S_CFH_SIDSVID - Switch 0 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_S_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_S_CFH_SIDSVID */
#define NETC_IERB_S_CFH_SIDSVID_COUNT            (1U)

/*! @name SCCAR - Switch 0 command cache attribute register */
/*! @{ */

#define NETC_IERB_SCCAR_CBD_WRCACHE_MASK         (0xFU)
#define NETC_IERB_SCCAR_CBD_WRCACHE_SHIFT        (0U)
#define NETC_IERB_SCCAR_CBD_WRCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRCACHE_SHIFT)) & NETC_IERB_SCCAR_CBD_WRCACHE_MASK)

#define NETC_IERB_SCCAR_CBD_WRDOMAIN_MASK        (0x30U)
#define NETC_IERB_SCCAR_CBD_WRDOMAIN_SHIFT       (4U)
#define NETC_IERB_SCCAR_CBD_WRDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CBD_WRDOMAIN_MASK)

#define NETC_IERB_SCCAR_CBD_WRSNP_MASK           (0x40U)
#define NETC_IERB_SCCAR_CBD_WRSNP_SHIFT          (6U)
#define NETC_IERB_SCCAR_CBD_WRSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_WRSNP_SHIFT)) & NETC_IERB_SCCAR_CBD_WRSNP_MASK)

#define NETC_IERB_SCCAR_CWRCACHE_MASK            (0xF00U)
#define NETC_IERB_SCCAR_CWRCACHE_SHIFT           (8U)
#define NETC_IERB_SCCAR_CWRCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRCACHE_SHIFT)) & NETC_IERB_SCCAR_CWRCACHE_MASK)

#define NETC_IERB_SCCAR_CWRDOMAIN_MASK           (0x3000U)
#define NETC_IERB_SCCAR_CWRDOMAIN_SHIFT          (12U)
#define NETC_IERB_SCCAR_CWRDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CWRDOMAIN_MASK)

#define NETC_IERB_SCCAR_CWRSNP_MASK              (0x4000U)
#define NETC_IERB_SCCAR_CWRSNP_SHIFT             (14U)
#define NETC_IERB_SCCAR_CWRSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CWRSNP_SHIFT)) & NETC_IERB_SCCAR_CWRSNP_MASK)

#define NETC_IERB_SCCAR_CBD_RDCACHE_MASK         (0xF0000U)
#define NETC_IERB_SCCAR_CBD_RDCACHE_SHIFT        (16U)
#define NETC_IERB_SCCAR_CBD_RDCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDCACHE_SHIFT)) & NETC_IERB_SCCAR_CBD_RDCACHE_MASK)

#define NETC_IERB_SCCAR_CBD_RDDOMAIN_MASK        (0x300000U)
#define NETC_IERB_SCCAR_CBD_RDDOMAIN_SHIFT       (20U)
#define NETC_IERB_SCCAR_CBD_RDDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CBD_RDDOMAIN_MASK)

#define NETC_IERB_SCCAR_CBD_RDSNP_MASK           (0x400000U)
#define NETC_IERB_SCCAR_CBD_RDSNP_SHIFT          (22U)
#define NETC_IERB_SCCAR_CBD_RDSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CBD_RDSNP_SHIFT)) & NETC_IERB_SCCAR_CBD_RDSNP_MASK)

#define NETC_IERB_SCCAR_CRDCACHE_MASK            (0xF000000U)
#define NETC_IERB_SCCAR_CRDCACHE_SHIFT           (24U)
#define NETC_IERB_SCCAR_CRDCACHE(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDCACHE_SHIFT)) & NETC_IERB_SCCAR_CRDCACHE_MASK)

#define NETC_IERB_SCCAR_CRDDOMAIN_MASK           (0x30000000U)
#define NETC_IERB_SCCAR_CRDDOMAIN_SHIFT          (28U)
#define NETC_IERB_SCCAR_CRDDOMAIN(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDDOMAIN_SHIFT)) & NETC_IERB_SCCAR_CRDDOMAIN_MASK)

#define NETC_IERB_SCCAR_CRDSNP_MASK              (0x40000000U)
#define NETC_IERB_SCCAR_CRDSNP_SHIFT             (30U)
#define NETC_IERB_SCCAR_CRDSNP(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SCCAR_CRDSNP_SHIFT)) & NETC_IERB_SCCAR_CRDSNP_MASK)
/*! @} */

/* The count of NETC_IERB_SCCAR */
#define NETC_IERB_SCCAR_COUNT                    (1U)

/*! @name SAMQR - Switch 0 access management qualifier register */
/*! @{ */

#define NETC_IERB_SAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_SAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_SAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_ARQOS_SHIFT)) & NETC_IERB_SAMQR_ARQOS_MASK)

#define NETC_IERB_SAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_SAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_SAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_AWQOS_SHIFT)) & NETC_IERB_SAMQR_AWQOS_MASK)

#define NETC_IERB_SAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_SAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_SAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SAMQR_BMT_SHIFT)) & NETC_IERB_SAMQR_BMT_MASK)
/*! @} */

/* The count of NETC_IERB_SAMQR */
#define NETC_IERB_SAMQR_COUNT                    (1U)

/*! @name SBLPR - Switch 0 boot loader parameter register 0..Switch 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_SBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_SBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_SBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_SBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of NETC_IERB_SBLPR */
#define NETC_IERB_SBLPR_COUNT                    (1U)

/* The count of NETC_IERB_SBLPR */
#define NETC_IERB_SBLPR_COUNT2                   (2U)

/*! @name SSMBAR - Switch 0 shared memory buffer allotment register */
/*! @{ */

#define NETC_IERB_SSMBAR_ALLOC_MASK              (0xFFFFFFU)
#define NETC_IERB_SSMBAR_ALLOC_SHIFT             (0U)
#define NETC_IERB_SSMBAR_ALLOC(x)                (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSMBAR_ALLOC_SHIFT)) & NETC_IERB_SSMBAR_ALLOC_MASK)

#define NETC_IERB_SSMBAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SSMBAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SSMBAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSMBAR_MLOC_SHIFT)) & NETC_IERB_SSMBAR_MLOC_MASK)
/*! @} */

/* The count of NETC_IERB_SSMBAR */
#define NETC_IERB_SSMBAR_COUNT                   (1U)

/*! @name SHTMAR - Switch 0 hash table memory allotment register */
/*! @{ */

#define NETC_IERB_SHTMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_SHTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_SHTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SHTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SHTMAR_NUM_WORDS_MASK)

#define NETC_IERB_SHTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SHTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SHTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SHTMAR_MLOC_SHIFT)) & NETC_IERB_SHTMAR_MLOC_MASK)
/*! @} */

/* The count of NETC_IERB_SHTMAR */
#define NETC_IERB_SHTMAR_COUNT                   (1U)

/*! @name SITMAR - Switch 0 index table memory allocation register */
/*! @{ */

#define NETC_IERB_SITMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_SITMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_SITMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SITMAR_NUM_WORDS_MASK)

#define NETC_IERB_SITMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_SITMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_SITMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SITMAR_MLOC_SHIFT)) & NETC_IERB_SITMAR_MLOC_MASK)
/*! @} */

/* The count of NETC_IERB_SITMAR */
#define NETC_IERB_SITMAR_COUNT                   (1U)

/*! @name SIPFTMAR - Switch 0 ingress port filter table memory allocation register */
/*! @{ */

#define NETC_IERB_SIPFTMAR_ALLOC_MASK            (0xFFFFU)
#define NETC_IERB_SIPFTMAR_ALLOC_SHIFT           (0U)
#define NETC_IERB_SIPFTMAR_ALLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SIPFTMAR_ALLOC_SHIFT)) & NETC_IERB_SIPFTMAR_ALLOC_MASK)
/*! @} */

/* The count of NETC_IERB_SIPFTMAR */
#define NETC_IERB_SIPFTMAR_COUNT                 (1U)

/*! @name SRPITMAR - Switch 0 rate policer index table memory allocation register */
/*! @{ */

#define NETC_IERB_SRPITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_SRPITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SRPITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SRPITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SRPITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SRPITMAR */
#define NETC_IERB_SRPITMAR_COUNT                 (1U)

/*! @name SISCITMAR - Switch 0 ingress stream counter index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISCITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SISCITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SISCITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISCITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISCITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SISCITMAR */
#define NETC_IERB_SISCITMAR_COUNT                (1U)

/*! @name SISITMAR - Switch 0 ingress stream index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_SISITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SISITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SISITMAR */
#define NETC_IERB_SISITMAR_COUNT                 (1U)

/*! @name SISQGITMAR - Switch 0 ingress sequence generation index table memory allocation register */
/*! @{ */

#define NETC_IERB_SISQGITMAR_NUM_WORDS_MASK      (0x1FFFU)
#define NETC_IERB_SISQGITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_SISQGITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SISQGITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SISQGITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SISQGITMAR */
#define NETC_IERB_SISQGITMAR_COUNT               (1U)

/*! @name SSGIITMAR - Switch 0 stream gate instance index table memory allocation register */
/*! @{ */

#define NETC_IERB_SSGIITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SSGIITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SSGIITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSGIITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SSGIITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SSGIITMAR */
#define NETC_IERB_SSGIITMAR_COUNT                (1U)

/*! @name SSGCLITMAR - Switch 0 stream gate control list index table memory allocation register */
/*! @{ */

#define NETC_IERB_SSGCLITMAR_NUM_WORDS_MASK      (0xFFFFU)
#define NETC_IERB_SSGCLITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_SSGCLITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SSGCLITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SSGCLITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SSGCLITMAR */
#define NETC_IERB_SSGCLITMAR_COUNT               (1U)

/*! @name SFMITMAR - Switch 0 frame modification index table memory allocation register */
/*! @{ */

#define NETC_IERB_SFMITMAR_NUM_WORDS_MASK        (0x1FFFU)
#define NETC_IERB_SFMITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_SFMITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SFMITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SFMITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SFMITMAR */
#define NETC_IERB_SFMITMAR_COUNT                 (1U)

/*! @name SFMDITMAR - Switch 0 frame modification data index table memory allocation register */
/*! @{ */

#define NETC_IERB_SFMDITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_SFMDITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_SFMDITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SFMDITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_SFMDITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_SFMDITMAR */
#define NETC_IERB_SFMDITMAR_COUNT                (1U)

/*! @name STGSTAR - Switch 0 time gate scheduling table allocation register */
/*! @{ */

#define NETC_IERB_STGSTAR_NUM_WORDS_MASK         (0xFFFU)
#define NETC_IERB_STGSTAR_NUM_WORDS_SHIFT        (0U)
#define NETC_IERB_STGSTAR_NUM_WORDS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_STGSTAR_NUM_WORDS_SHIFT)) & NETC_IERB_STGSTAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_STGSTAR */
#define NETC_IERB_STGSTAR_COUNT                  (1U)

/*! @name STGSLR - Switch 0 time gate scheduling lookahead register */
/*! @{ */

#define NETC_IERB_STGSLR_MIN_LOOKAHEAD_MASK      (0xFFFFFU)
#define NETC_IERB_STGSLR_MIN_LOOKAHEAD_SHIFT     (0U)
#define NETC_IERB_STGSLR_MIN_LOOKAHEAD(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_STGSLR_MIN_LOOKAHEAD_SHIFT)) & NETC_IERB_STGSLR_MIN_LOOKAHEAD_MASK)
/*! @} */

/* The count of NETC_IERB_STGSLR */
#define NETC_IERB_STGSLR_COUNT                   (1U)

/*! @name SMPCR - Switch 0 management port configuration register */
/*! @{ */

#define NETC_IERB_SMPCR_PORT_MASK                (0x1FU)
#define NETC_IERB_SMPCR_PORT_SHIFT               (0U)
#define NETC_IERB_SMPCR_PORT(x)                  (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SMPCR_PORT_SHIFT)) & NETC_IERB_SMPCR_PORT_MASK)
/*! @} */

/* The count of NETC_IERB_SMPCR */
#define NETC_IERB_SMPCR_COUNT                    (1U)

/*! @name SVFHTDECR0 - Switch 0 VLAN Filter (hash) table default entry configuration registers 0 */
/*! @{ */

#define NETC_IERB_SVFHTDECR0_PORT0_MASK          (0x1U)
#define NETC_IERB_SVFHTDECR0_PORT0_SHIFT         (0U)
/*! PORT0 - Port n.
 *  0b0..Port n is not a member of this VLAN.
 *  0b1..Port n is a member of this VLAN.
 */
#define NETC_IERB_SVFHTDECR0_PORT0(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT0_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT0_MASK)

#define NETC_IERB_SVFHTDECR0_PORT1_MASK          (0x2U)
#define NETC_IERB_SVFHTDECR0_PORT1_SHIFT         (1U)
/*! PORT1 - Port n.
 *  0b0..Port n is not a member of this VLAN.
 *  0b1..Port n is a member of this VLAN.
 */
#define NETC_IERB_SVFHTDECR0_PORT1(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT1_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT1_MASK)

#define NETC_IERB_SVFHTDECR0_PORT2_MASK          (0x4U)
#define NETC_IERB_SVFHTDECR0_PORT2_SHIFT         (2U)
/*! PORT2 - Port n.
 *  0b0..Port n is not a member of this VLAN.
 *  0b1..Port n is a member of this VLAN.
 */
#define NETC_IERB_SVFHTDECR0_PORT2(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT2_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT2_MASK)

#define NETC_IERB_SVFHTDECR0_PORT3_MASK          (0x8U)
#define NETC_IERB_SVFHTDECR0_PORT3_SHIFT         (3U)
/*! PORT3 - Port n.
 *  0b0..Port n is not a member of this VLAN.
 *  0b1..Port n is a member of this VLAN.
 */
#define NETC_IERB_SVFHTDECR0_PORT3(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT3_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT3_MASK)

#define NETC_IERB_SVFHTDECR0_PORT4_MASK          (0x10U)
#define NETC_IERB_SVFHTDECR0_PORT4_SHIFT         (4U)
/*! PORT4 - Port n.
 *  0b0..Port n is not a member of this VLAN.
 *  0b1..Port n is a member of this VLAN.
 */
#define NETC_IERB_SVFHTDECR0_PORT4(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_PORT4_SHIFT)) & NETC_IERB_SVFHTDECR0_PORT4_MASK)

#define NETC_IERB_SVFHTDECR0_STG_ID_MASK         (0xF000000U)
#define NETC_IERB_SVFHTDECR0_STG_ID_SHIFT        (24U)
#define NETC_IERB_SVFHTDECR0_STG_ID(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_STG_ID_SHIFT)) & NETC_IERB_SVFHTDECR0_STG_ID_MASK)

#define NETC_IERB_SVFHTDECR0_IPMFE_MASK          (0x20000000U)
#define NETC_IERB_SVFHTDECR0_IPMFE_SHIFT         (29U)
/*! IPMFE
 *  0b0..No IP multicast filtering is performed.
 *  0b1..If the frame is identified as a multicast IP packet, then IP multicast filtering is performed. If the
 *       frame is not identified as an IP multicast packet, the IP multicast filtering is not performed.
 */
#define NETC_IERB_SVFHTDECR0_IPMFE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_IPMFE_SHIFT)) & NETC_IERB_SVFHTDECR0_IPMFE_MASK)

#define NETC_IERB_SVFHTDECR0_IPMFLE_MASK         (0x40000000U)
#define NETC_IERB_SVFHTDECR0_IPMFLE_SHIFT        (30U)
/*! IPMFLE
 *  0b0..IP Multicast Flooding disabled, the frame is discarded.
 *  0b1..IP Multicast Flooding enabled, the frame is flooded.
 */
#define NETC_IERB_SVFHTDECR0_IPMFLE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR0_IPMFLE_SHIFT)) & NETC_IERB_SVFHTDECR0_IPMFLE_MASK)
/*! @} */

/* The count of NETC_IERB_SVFHTDECR0 */
#define NETC_IERB_SVFHTDECR0_COUNT               (1U)

/*! @name SVFHTDECR1 - Switch 0 VLAN filter hash table default entry configuration registers 1 */
/*! @{ */

#define NETC_IERB_SVFHTDECR1_FID_MASK            (0xFFFU)
#define NETC_IERB_SVFHTDECR1_FID_SHIFT           (0U)
#define NETC_IERB_SVFHTDECR1_FID(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_FID_SHIFT)) & NETC_IERB_SVFHTDECR1_FID_MASK)

#define NETC_IERB_SVFHTDECR1_VL_MODE_MASK        (0x1000U)
#define NETC_IERB_SVFHTDECR1_VL_MODE_SHIFT       (12U)
#define NETC_IERB_SVFHTDECR1_VL_MODE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_VL_MODE_SHIFT)) & NETC_IERB_SVFHTDECR1_VL_MODE_MASK)

#define NETC_IERB_SVFHTDECR1_BASE_ETEID_MASK     (0xFFFF0000U)
#define NETC_IERB_SVFHTDECR1_BASE_ETEID_SHIFT    (16U)
#define NETC_IERB_SVFHTDECR1_BASE_ETEID(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR1_BASE_ETEID_SHIFT)) & NETC_IERB_SVFHTDECR1_BASE_ETEID_MASK)
/*! @} */

/* The count of NETC_IERB_SVFHTDECR1 */
#define NETC_IERB_SVFHTDECR1_COUNT               (1U)

/*! @name SVFHTDECR2 - Switch 0 VLAN filter hash table default entry configuration registers 2 */
/*! @{ */

#define NETC_IERB_SVFHTDECR2_ES_PORT0_MASK       (0x1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT0_SHIFT      (0U)
#define NETC_IERB_SVFHTDECR2_ES_PORT0(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT0_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT0_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT1_MASK       (0x2U)
#define NETC_IERB_SVFHTDECR2_ES_PORT1_SHIFT      (1U)
#define NETC_IERB_SVFHTDECR2_ES_PORT1(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT1_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT1_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT2_MASK       (0x4U)
#define NETC_IERB_SVFHTDECR2_ES_PORT2_SHIFT      (2U)
#define NETC_IERB_SVFHTDECR2_ES_PORT2(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT2_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT2_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT3_MASK       (0x8U)
#define NETC_IERB_SVFHTDECR2_ES_PORT3_SHIFT      (3U)
#define NETC_IERB_SVFHTDECR2_ES_PORT3(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT3_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT3_MASK)

#define NETC_IERB_SVFHTDECR2_ES_PORT4_MASK       (0x10U)
#define NETC_IERB_SVFHTDECR2_ES_PORT4_SHIFT      (4U)
#define NETC_IERB_SVFHTDECR2_ES_PORT4(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_ES_PORT4_SHIFT)) & NETC_IERB_SVFHTDECR2_ES_PORT4_MASK)

#define NETC_IERB_SVFHTDECR2_MLO_MASK            (0x7000000U)
#define NETC_IERB_SVFHTDECR2_MLO_SHIFT           (24U)
#define NETC_IERB_SVFHTDECR2_MLO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_MLO_SHIFT)) & NETC_IERB_SVFHTDECR2_MLO_MASK)

#define NETC_IERB_SVFHTDECR2_MFO_MASK            (0x18000000U)
#define NETC_IERB_SVFHTDECR2_MFO_SHIFT           (27U)
#define NETC_IERB_SVFHTDECR2_MFO(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_SVFHTDECR2_MFO_SHIFT)) & NETC_IERB_SVFHTDECR2_MFO_MASK)
/*! @} */

/* The count of NETC_IERB_SVFHTDECR2 */
#define NETC_IERB_SVFHTDECR2_COUNT               (1U)

/*! @name EBCR0 - ENETC 0 binding configuration register 0..ENETC 1 binding configuration register 0 */
/*! @{ */

#define NETC_IERB_EBCR0_RC_INST_MASK             (0xFU)
#define NETC_IERB_EBCR0_RC_INST_SHIFT            (0U)
#define NETC_IERB_EBCR0_RC_INST(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_RC_INST_SHIFT)) & NETC_IERB_EBCR0_RC_INST_MASK)

#define NETC_IERB_EBCR0_FN_MASK                  (0xF00U)
#define NETC_IERB_EBCR0_FN_SHIFT                 (8U)
#define NETC_IERB_EBCR0_FN(x)                    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_FN_SHIFT)) & NETC_IERB_EBCR0_FN_MASK)

#define NETC_IERB_EBCR0_VALID_MASK               (0x80000000U)
#define NETC_IERB_EBCR0_VALID_SHIFT              (31U)
#define NETC_IERB_EBCR0_VALID(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR0_VALID_SHIFT)) & NETC_IERB_EBCR0_VALID_MASK)
/*! @} */

/* The count of NETC_IERB_EBCR0 */
#define NETC_IERB_EBCR0_COUNT                    (2U)

/*! @name EBCR1 - ENETC 0 binding configuration register 1..ENETC 1 binding configuration register 1 */
/*! @{ */

#define NETC_IERB_EBCR1_NUM_RX_BDR_MASK          (0x3FFU)
#define NETC_IERB_EBCR1_NUM_RX_BDR_SHIFT         (0U)
#define NETC_IERB_EBCR1_NUM_RX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR1_NUM_RX_BDR_SHIFT)) & NETC_IERB_EBCR1_NUM_RX_BDR_MASK)

#define NETC_IERB_EBCR1_NUM_TX_BDR_MASK          (0x3FF0000U)
#define NETC_IERB_EBCR1_NUM_TX_BDR_SHIFT         (16U)
#define NETC_IERB_EBCR1_NUM_TX_BDR(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR1_NUM_TX_BDR_SHIFT)) & NETC_IERB_EBCR1_NUM_TX_BDR_MASK)
/*! @} */

/* The count of NETC_IERB_EBCR1 */
#define NETC_IERB_EBCR1_COUNT                    (2U)

/*! @name EBCR2 - ENETC 0 binding configuration register 2..ENETC 1 binding configuration register 2 */
/*! @{ */

#define NETC_IERB_EBCR2_NUM_MAC_AFTE_MASK        (0xFFFU)
#define NETC_IERB_EBCR2_NUM_MAC_AFTE_SHIFT       (0U)
#define NETC_IERB_EBCR2_NUM_MAC_AFTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR2_NUM_MAC_AFTE_SHIFT)) & NETC_IERB_EBCR2_NUM_MAC_AFTE_MASK)

#define NETC_IERB_EBCR2_NUM_VLAN_FTE_MASK        (0xFFF0000U)
#define NETC_IERB_EBCR2_NUM_VLAN_FTE_SHIFT       (16U)
#define NETC_IERB_EBCR2_NUM_VLAN_FTE(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCR2_NUM_VLAN_FTE_SHIFT)) & NETC_IERB_EBCR2_NUM_VLAN_FTE_MASK)
/*! @} */

/* The count of NETC_IERB_EBCR2 */
#define NETC_IERB_EBCR2_COUNT                    (2U)

/*! @name EVBCR - ENETC 0 VSI binding configuration register..ENETC 1 VSI binding configuration register */
/*! @{ */

#define NETC_IERB_EVBCR_NUM_VSI_MASK             (0xFU)
#define NETC_IERB_EVBCR_NUM_VSI_SHIFT            (0U)
#define NETC_IERB_EVBCR_NUM_VSI(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EVBCR_NUM_VSI_SHIFT)) & NETC_IERB_EVBCR_NUM_VSI_MASK)
/*! @} */

/* The count of NETC_IERB_EVBCR */
#define NETC_IERB_EVBCR_COUNT                    (2U)

/*! @name EMCR - ENETC 0 MSI-X configuration register..ENETC 1 MSI-X configuration register */
/*! @{ */

#define NETC_IERB_EMCR_NUM_MSIX_MASK             (0x7FFU)
#define NETC_IERB_EMCR_NUM_MSIX_SHIFT            (0U)
#define NETC_IERB_EMCR_NUM_MSIX(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCR_NUM_MSIX_SHIFT)) & NETC_IERB_EMCR_NUM_MSIX_MASK)
/*! @} */

/* The count of NETC_IERB_EMCR */
#define NETC_IERB_EMCR_COUNT                     (2U)

/*! @name E_CFH_DIDVID - ENETC 0 config header device ID and vendor ID register..ENETC 1 config header device ID and vendor ID register */
/*! @{ */

#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID_MASK    (0xFFFFU)
#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID_SHIFT   (0U)
#define NETC_IERB_E_CFH_DIDVID_VENDOR_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_DIDVID_VENDOR_ID_SHIFT)) & NETC_IERB_E_CFH_DIDVID_VENDOR_ID_MASK)

#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID_MASK    (0xFFFF0000U)
#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID_SHIFT   (16U)
#define NETC_IERB_E_CFH_DIDVID_DEVICE_ID(x)      (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_DIDVID_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFH_DIDVID_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_E_CFH_DIDVID */
#define NETC_IERB_E_CFH_DIDVID_COUNT             (2U)

/*! @name E_CFH_SIDSVID - ENETC 0 config header subsystem ID and subsystem vendor ID register..ENETC 1 config header subsystem ID and subsystem vendor ID register */
/*! @{ */

#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK (0xFFFFU)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT (0U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_SHIFT)) & NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_VENDOR_ID_MASK)

#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK (0xFFFF0000U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID(x) (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFH_SIDSVID_SUBSYSTEM_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_E_CFH_SIDSVID */
#define NETC_IERB_E_CFH_SIDSVID_COUNT            (2U)

/*! @name E_CFC_VFDID - ENETC 0 config capability VF device ID register..ENETC 1 config capability VF device ID register */
/*! @{ */

#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_MASK  (0xFFFF0000U)
#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_SHIFT (16U)
#define NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID(x)    (((uint32_t)(((uint32_t)(x)) << NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_SHIFT)) & NETC_IERB_E_CFC_VFDID_VF_DEVICE_ID_MASK)
/*! @} */

/* The count of NETC_IERB_E_CFC_VFDID */
#define NETC_IERB_E_CFC_VFDID_COUNT              (2U)

/*! @name EBCAR - ENETC 0 buffer cache attribute register 0..ENETC 1 buffer cache attribute register 0 */
/*! @{ */

#define NETC_IERB_EBCAR_BD_WRCACHE_MASK          (0xFU)
#define NETC_IERB_EBCAR_BD_WRCACHE_SHIFT         (0U)
#define NETC_IERB_EBCAR_BD_WRCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRCACHE_SHIFT)) & NETC_IERB_EBCAR_BD_WRCACHE_MASK)

#define NETC_IERB_EBCAR_BD_WRDOMAIN_MASK         (0x30U)
#define NETC_IERB_EBCAR_BD_WRDOMAIN_SHIFT        (4U)
#define NETC_IERB_EBCAR_BD_WRDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRDOMAIN_SHIFT)) & NETC_IERB_EBCAR_BD_WRDOMAIN_MASK)

#define NETC_IERB_EBCAR_BD_WRSNP_MASK            (0x40U)
#define NETC_IERB_EBCAR_BD_WRSNP_SHIFT           (6U)
#define NETC_IERB_EBCAR_BD_WRSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_WRSNP_SHIFT)) & NETC_IERB_EBCAR_BD_WRSNP_MASK)

#define NETC_IERB_EBCAR_WRCACHE_MASK             (0xF00U)
#define NETC_IERB_EBCAR_WRCACHE_SHIFT            (8U)
#define NETC_IERB_EBCAR_WRCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRCACHE_SHIFT)) & NETC_IERB_EBCAR_WRCACHE_MASK)

#define NETC_IERB_EBCAR_WRDOMAIN_MASK            (0x3000U)
#define NETC_IERB_EBCAR_WRDOMAIN_SHIFT           (12U)
#define NETC_IERB_EBCAR_WRDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRDOMAIN_SHIFT)) & NETC_IERB_EBCAR_WRDOMAIN_MASK)

#define NETC_IERB_EBCAR_WRSNP_MASK               (0x4000U)
#define NETC_IERB_EBCAR_WRSNP_SHIFT              (14U)
#define NETC_IERB_EBCAR_WRSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_WRSNP_SHIFT)) & NETC_IERB_EBCAR_WRSNP_MASK)

#define NETC_IERB_EBCAR_BD_RDCACHE_MASK          (0xF0000U)
#define NETC_IERB_EBCAR_BD_RDCACHE_SHIFT         (16U)
#define NETC_IERB_EBCAR_BD_RDCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDCACHE_SHIFT)) & NETC_IERB_EBCAR_BD_RDCACHE_MASK)

#define NETC_IERB_EBCAR_BD_RDDOMAIN_MASK         (0x300000U)
#define NETC_IERB_EBCAR_BD_RDDOMAIN_SHIFT        (20U)
#define NETC_IERB_EBCAR_BD_RDDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDDOMAIN_SHIFT)) & NETC_IERB_EBCAR_BD_RDDOMAIN_MASK)

#define NETC_IERB_EBCAR_BD_RDSNP_MASK            (0x400000U)
#define NETC_IERB_EBCAR_BD_RDSNP_SHIFT           (22U)
#define NETC_IERB_EBCAR_BD_RDSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_BD_RDSNP_SHIFT)) & NETC_IERB_EBCAR_BD_RDSNP_MASK)

#define NETC_IERB_EBCAR_RDCACHE_MASK             (0xF000000U)
#define NETC_IERB_EBCAR_RDCACHE_SHIFT            (24U)
#define NETC_IERB_EBCAR_RDCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDCACHE_SHIFT)) & NETC_IERB_EBCAR_RDCACHE_MASK)

#define NETC_IERB_EBCAR_RDDOMAIN_MASK            (0x30000000U)
#define NETC_IERB_EBCAR_RDDOMAIN_SHIFT           (28U)
#define NETC_IERB_EBCAR_RDDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDDOMAIN_SHIFT)) & NETC_IERB_EBCAR_RDDOMAIN_MASK)

#define NETC_IERB_EBCAR_RDSNP_MASK               (0x40000000U)
#define NETC_IERB_EBCAR_RDSNP_SHIFT              (30U)
#define NETC_IERB_EBCAR_RDSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBCAR_RDSNP_SHIFT)) & NETC_IERB_EBCAR_RDSNP_MASK)
/*! @} */

/* The count of NETC_IERB_EBCAR */
#define NETC_IERB_EBCAR_COUNT                    (2U)

/*! @name EMCAR - ENETC 0 message cache attribute register..ENETC 1 message cache attribute register */
/*! @{ */

#define NETC_IERB_EMCAR_MSG_WRCACHE_MASK         (0xFU)
#define NETC_IERB_EMCAR_MSG_WRCACHE_SHIFT        (0U)
#define NETC_IERB_EMCAR_MSG_WRCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRCACHE_SHIFT)) & NETC_IERB_EMCAR_MSG_WRCACHE_MASK)

#define NETC_IERB_EMCAR_MSG_WRDOMAIN_MASK        (0x30U)
#define NETC_IERB_EMCAR_MSG_WRDOMAIN_SHIFT       (4U)
#define NETC_IERB_EMCAR_MSG_WRDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRDOMAIN_SHIFT)) & NETC_IERB_EMCAR_MSG_WRDOMAIN_MASK)

#define NETC_IERB_EMCAR_MSG_WRSNP_MASK           (0x40U)
#define NETC_IERB_EMCAR_MSG_WRSNP_SHIFT          (6U)
#define NETC_IERB_EMCAR_MSG_WRSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_WRSNP_SHIFT)) & NETC_IERB_EMCAR_MSG_WRSNP_MASK)

#define NETC_IERB_EMCAR_MSG_RDCACHE_MASK         (0xF0000U)
#define NETC_IERB_EMCAR_MSG_RDCACHE_SHIFT        (16U)
#define NETC_IERB_EMCAR_MSG_RDCACHE(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDCACHE_SHIFT)) & NETC_IERB_EMCAR_MSG_RDCACHE_MASK)

#define NETC_IERB_EMCAR_MSG_RDDOMAIN_MASK        (0x300000U)
#define NETC_IERB_EMCAR_MSG_RDDOMAIN_SHIFT       (20U)
#define NETC_IERB_EMCAR_MSG_RDDOMAIN(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDDOMAIN_SHIFT)) & NETC_IERB_EMCAR_MSG_RDDOMAIN_MASK)

#define NETC_IERB_EMCAR_MSG_RDSNP_MASK           (0x400000U)
#define NETC_IERB_EMCAR_MSG_RDSNP_SHIFT          (22U)
#define NETC_IERB_EMCAR_MSG_RDSNP(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EMCAR_MSG_RDSNP_SHIFT)) & NETC_IERB_EMCAR_MSG_RDSNP_MASK)
/*! @} */

/* The count of NETC_IERB_EMCAR */
#define NETC_IERB_EMCAR_COUNT                    (2U)

/*! @name ECAR - ENETC 0 command cache attribute register..ENETC 1 command cache attribute register */
/*! @{ */

#define NETC_IERB_ECAR_CBD_WRCACHE_MASK          (0xFU)
#define NETC_IERB_ECAR_CBD_WRCACHE_SHIFT         (0U)
#define NETC_IERB_ECAR_CBD_WRCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRCACHE_SHIFT)) & NETC_IERB_ECAR_CBD_WRCACHE_MASK)

#define NETC_IERB_ECAR_CBD_WRDOMAIN_MASK         (0x30U)
#define NETC_IERB_ECAR_CBD_WRDOMAIN_SHIFT        (4U)
#define NETC_IERB_ECAR_CBD_WRDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRDOMAIN_SHIFT)) & NETC_IERB_ECAR_CBD_WRDOMAIN_MASK)

#define NETC_IERB_ECAR_CBD_WRSNP_MASK            (0x40U)
#define NETC_IERB_ECAR_CBD_WRSNP_SHIFT           (6U)
#define NETC_IERB_ECAR_CBD_WRSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_WRSNP_SHIFT)) & NETC_IERB_ECAR_CBD_WRSNP_MASK)

#define NETC_IERB_ECAR_CWRCACHE_MASK             (0xF00U)
#define NETC_IERB_ECAR_CWRCACHE_SHIFT            (8U)
#define NETC_IERB_ECAR_CWRCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRCACHE_SHIFT)) & NETC_IERB_ECAR_CWRCACHE_MASK)

#define NETC_IERB_ECAR_CWRDOMAIN_MASK            (0x3000U)
#define NETC_IERB_ECAR_CWRDOMAIN_SHIFT           (12U)
#define NETC_IERB_ECAR_CWRDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRDOMAIN_SHIFT)) & NETC_IERB_ECAR_CWRDOMAIN_MASK)

#define NETC_IERB_ECAR_CWRSNP_MASK               (0x4000U)
#define NETC_IERB_ECAR_CWRSNP_SHIFT              (14U)
#define NETC_IERB_ECAR_CWRSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CWRSNP_SHIFT)) & NETC_IERB_ECAR_CWRSNP_MASK)

#define NETC_IERB_ECAR_CBD_RDCACHE_MASK          (0xF0000U)
#define NETC_IERB_ECAR_CBD_RDCACHE_SHIFT         (16U)
#define NETC_IERB_ECAR_CBD_RDCACHE(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDCACHE_SHIFT)) & NETC_IERB_ECAR_CBD_RDCACHE_MASK)

#define NETC_IERB_ECAR_CBD_RDDOMAIN_MASK         (0x300000U)
#define NETC_IERB_ECAR_CBD_RDDOMAIN_SHIFT        (20U)
#define NETC_IERB_ECAR_CBD_RDDOMAIN(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDDOMAIN_SHIFT)) & NETC_IERB_ECAR_CBD_RDDOMAIN_MASK)

#define NETC_IERB_ECAR_CBD_RDSNP_MASK            (0x400000U)
#define NETC_IERB_ECAR_CBD_RDSNP_SHIFT           (22U)
#define NETC_IERB_ECAR_CBD_RDSNP(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CBD_RDSNP_SHIFT)) & NETC_IERB_ECAR_CBD_RDSNP_MASK)

#define NETC_IERB_ECAR_CRDCACHE_MASK             (0xF000000U)
#define NETC_IERB_ECAR_CRDCACHE_SHIFT            (24U)
#define NETC_IERB_ECAR_CRDCACHE(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDCACHE_SHIFT)) & NETC_IERB_ECAR_CRDCACHE_MASK)

#define NETC_IERB_ECAR_CRDDOMAIN_MASK            (0x30000000U)
#define NETC_IERB_ECAR_CRDDOMAIN_SHIFT           (28U)
#define NETC_IERB_ECAR_CRDDOMAIN(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDDOMAIN_SHIFT)) & NETC_IERB_ECAR_CRDDOMAIN_MASK)

#define NETC_IERB_ECAR_CRDSNP_MASK               (0x40000000U)
#define NETC_IERB_ECAR_CRDSNP_SHIFT              (30U)
#define NETC_IERB_ECAR_CRDSNP(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ECAR_CRDSNP_SHIFT)) & NETC_IERB_ECAR_CRDSNP_MASK)
/*! @} */

/* The count of NETC_IERB_ECAR */
#define NETC_IERB_ECAR_COUNT                     (2U)

/*! @name EAMQR - ENETC 0 access management qualifier register..ENETC 1 access management qualifier register */
/*! @{ */

#define NETC_IERB_EAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_EAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_EAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_ARQOS_SHIFT)) & NETC_IERB_EAMQR_ARQOS_MASK)

#define NETC_IERB_EAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_EAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_EAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_AWQOS_SHIFT)) & NETC_IERB_EAMQR_AWQOS_MASK)

#define NETC_IERB_EAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_EAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_EAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EAMQR_BMT_SHIFT)) & NETC_IERB_EAMQR_BMT_MASK)
/*! @} */

/* The count of NETC_IERB_EAMQR */
#define NETC_IERB_EAMQR_COUNT                    (2U)

/*! @name EBLPR - ENETC 0 boot loader parameter register 0..ENETC 1 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_EBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_EBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_EBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_EBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of NETC_IERB_EBLPR */
#define NETC_IERB_EBLPR_COUNT                    (2U)

/* The count of NETC_IERB_EBLPR */
#define NETC_IERB_EBLPR_COUNT2                   (2U)

/*! @name ERXMBER - ENETC 0 receive memory buffer entitlement register..ENETC 1 receive memory buffer entitlement register */
/*! @{ */

#define NETC_IERB_ERXMBER_AMOUNT_MASK            (0xFFFFFFU)
#define NETC_IERB_ERXMBER_AMOUNT_SHIFT           (0U)
#define NETC_IERB_ERXMBER_AMOUNT(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERXMBER_AMOUNT_SHIFT)) & NETC_IERB_ERXMBER_AMOUNT_MASK)
/*! @} */

/* The count of NETC_IERB_ERXMBER */
#define NETC_IERB_ERXMBER_COUNT                  (2U)

/*! @name ERXMBLR - ENETC 0 receive memory buffer limit register..ENETC 1 receive memory buffer limit register */
/*! @{ */

#define NETC_IERB_ERXMBLR_LIMIT_MASK             (0xFFFFFFU)
#define NETC_IERB_ERXMBLR_LIMIT_SHIFT            (0U)
#define NETC_IERB_ERXMBLR_LIMIT(x)               (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERXMBLR_LIMIT_SHIFT)) & NETC_IERB_ERXMBLR_LIMIT_MASK)
/*! @} */

/* The count of NETC_IERB_ERXMBLR */
#define NETC_IERB_ERXMBLR_COUNT                  (2U)

/*! @name ETXHPTBCR - ENETC 0 transmit high priority tier byte credit register..ENETC 1 transmit high priority tier byte credit register */
/*! @{ */

#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT_MASK     (0xFFFFU)
#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT_SHIFT    (0U)
#define NETC_IERB_ETXHPTBCR_BYTE_CREDIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETXHPTBCR_BYTE_CREDIT_SHIFT)) & NETC_IERB_ETXHPTBCR_BYTE_CREDIT_MASK)
/*! @} */

/* The count of NETC_IERB_ETXHPTBCR */
#define NETC_IERB_ETXHPTBCR_COUNT                (2U)

/*! @name ETXLPTBCR - ENETC 0 transmit low priority tier byte credit register..ENETC 1 transmit low priority tier byte credit register */
/*! @{ */

#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT_MASK     (0xFFFFU)
#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT_SHIFT    (0U)
#define NETC_IERB_ETXLPTBCR_BYTE_CREDIT(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETXLPTBCR_BYTE_CREDIT_SHIFT)) & NETC_IERB_ETXLPTBCR_BYTE_CREDIT_MASK)
/*! @} */

/* The count of NETC_IERB_ETXLPTBCR */
#define NETC_IERB_ETXLPTBCR_COUNT                (2U)

/*! @name EHTMAR - ENETC 0 hash table memory allotment register..ENETC 1 hash table memory allotment register */
/*! @{ */

#define NETC_IERB_EHTMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_EHTMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_EHTMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EHTMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EHTMAR_NUM_WORDS_MASK)

#define NETC_IERB_EHTMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_EHTMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_EHTMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EHTMAR_MLOC_SHIFT)) & NETC_IERB_EHTMAR_MLOC_MASK)
/*! @} */

/* The count of NETC_IERB_EHTMAR */
#define NETC_IERB_EHTMAR_COUNT                   (2U)

/*! @name EITMAR - ENETC 0 index table memory allocation register..ENETC 1 index table memory allocation register */
/*! @{ */

#define NETC_IERB_EITMAR_NUM_WORDS_MASK          (0xFFFFU)
#define NETC_IERB_EITMAR_NUM_WORDS_SHIFT         (0U)
#define NETC_IERB_EITMAR_NUM_WORDS(x)            (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EITMAR_NUM_WORDS_MASK)

#define NETC_IERB_EITMAR_MLOC_MASK               (0xC0000000U)
#define NETC_IERB_EITMAR_MLOC_SHIFT              (30U)
#define NETC_IERB_EITMAR_MLOC(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EITMAR_MLOC_SHIFT)) & NETC_IERB_EITMAR_MLOC_MASK)
/*! @} */

/* The count of NETC_IERB_EITMAR */
#define NETC_IERB_EITMAR_COUNT                   (2U)

/*! @name EIPFTMAR - ENETC 0 ingress port filter table memory allocation register..ENETC 1 ingress port filter table memory allocation register */
/*! @{ */

#define NETC_IERB_EIPFTMAR_ALLOC_MASK            (0xFFFFU)
#define NETC_IERB_EIPFTMAR_ALLOC_SHIFT           (0U)
#define NETC_IERB_EIPFTMAR_ALLOC(x)              (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EIPFTMAR_ALLOC_SHIFT)) & NETC_IERB_EIPFTMAR_ALLOC_MASK)
/*! @} */

/* The count of NETC_IERB_EIPFTMAR */
#define NETC_IERB_EIPFTMAR_COUNT                 (2U)

/*! @name ERPITMAR - ENETC 0 rate policer index table memory allocation register..ENETC 1 rate policer index table memory allocation register */
/*! @{ */

#define NETC_IERB_ERPITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_ERPITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_ERPITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ERPITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ERPITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_ERPITMAR */
#define NETC_IERB_ERPITMAR_COUNT                 (2U)

/*! @name EISCITMAR - ENETC 0 ingress stream counter index table memory allocation register..ENETC 1 ingress stream counter index table memory allocation register */
/*! @{ */

#define NETC_IERB_EISCITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_EISCITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_EISCITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EISCITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EISCITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_EISCITMAR */
#define NETC_IERB_EISCITMAR_COUNT                (2U)

/*! @name EISITMAR - ENETC 0 ingress stream index table memory allocation register..ENETC 1 ingress stream index table memory allocation register */
/*! @{ */

#define NETC_IERB_EISITMAR_NUM_WORDS_MASK        (0xFFFFU)
#define NETC_IERB_EISITMAR_NUM_WORDS_SHIFT       (0U)
#define NETC_IERB_EISITMAR_NUM_WORDS(x)          (((uint32_t)(((uint32_t)(x)) << NETC_IERB_EISITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_EISITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_EISITMAR */
#define NETC_IERB_EISITMAR_COUNT                 (2U)

/*! @name ESGIITMAR - ENETC 0 stream gate instance index table memory allocation register..ENETC 1 stream gate instance index table memory allocation register */
/*! @{ */

#define NETC_IERB_ESGIITMAR_NUM_WORDS_MASK       (0xFFFFU)
#define NETC_IERB_ESGIITMAR_NUM_WORDS_SHIFT      (0U)
#define NETC_IERB_ESGIITMAR_NUM_WORDS(x)         (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ESGIITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ESGIITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_ESGIITMAR */
#define NETC_IERB_ESGIITMAR_COUNT                (2U)

/*! @name ESGCLITMAR - ENETC 0 stream gate control list index table memory allocation register..ENETC 1 stream gate control list index table memory allocation register */
/*! @{ */

#define NETC_IERB_ESGCLITMAR_NUM_WORDS_MASK      (0xFFFFU)
#define NETC_IERB_ESGCLITMAR_NUM_WORDS_SHIFT     (0U)
#define NETC_IERB_ESGCLITMAR_NUM_WORDS(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ESGCLITMAR_NUM_WORDS_SHIFT)) & NETC_IERB_ESGCLITMAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_ESGCLITMAR */
#define NETC_IERB_ESGCLITMAR_COUNT               (2U)

/*! @name ETGSTAR - ENETC 0 time gate scheduling table allocation register..ENETC 1 time gate scheduling table allocation register */
/*! @{ */

#define NETC_IERB_ETGSTAR_NUM_WORDS_MASK         (0xFFFU)
#define NETC_IERB_ETGSTAR_NUM_WORDS_SHIFT        (0U)
#define NETC_IERB_ETGSTAR_NUM_WORDS(x)           (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSTAR_NUM_WORDS_SHIFT)) & NETC_IERB_ETGSTAR_NUM_WORDS_MASK)
/*! @} */

/* The count of NETC_IERB_ETGSTAR */
#define NETC_IERB_ETGSTAR_COUNT                  (2U)

/*! @name ETGSLR - ENETC 0 time gate scheduling lookahead register..ENETC 1 time gate scheduling lookahead register */
/*! @{ */

#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD_MASK      (0xFFFFFU)
#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD_SHIFT     (0U)
#define NETC_IERB_ETGSLR_MIN_LOOKAHEAD(x)        (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSLR_MIN_LOOKAHEAD_SHIFT)) & NETC_IERB_ETGSLR_MIN_LOOKAHEAD_MASK)

#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_MASK     (0x80000000U)
#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_SHIFT    (31U)
/*! ZERO_LOOKAHEAD - Zero Lookahead
 *  0b0..Use MIN_LOOKAHEAD value
 *  0b1..If a gate control list is configured or when time specific departure is enabled on any traffic class
 *       (PTCaTSDR[TSDE] set to 1, where a corresponds to the traffic class number), use MIN_LOOKAHEAD value, otherwise
 *       use value of zero
 */
#define NETC_IERB_ETGSLR_ZERO_LOOKAHEAD(x)       (((uint32_t)(((uint32_t)(x)) << NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_SHIFT)) & NETC_IERB_ETGSLR_ZERO_LOOKAHEAD_MASK)
/*! @} */

/* The count of NETC_IERB_ETGSLR */
#define NETC_IERB_ETGSLR_COUNT                   (2U)

/*! @name VAMQR - VSI 0 access management qualifier register */
/*! @{ */

#define NETC_IERB_VAMQR_ARQOS_MASK               (0xF0000U)
#define NETC_IERB_VAMQR_ARQOS_SHIFT              (16U)
#define NETC_IERB_VAMQR_ARQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_ARQOS_SHIFT)) & NETC_IERB_VAMQR_ARQOS_MASK)

#define NETC_IERB_VAMQR_AWQOS_MASK               (0xF00000U)
#define NETC_IERB_VAMQR_AWQOS_SHIFT              (20U)
#define NETC_IERB_VAMQR_AWQOS(x)                 (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_AWQOS_SHIFT)) & NETC_IERB_VAMQR_AWQOS_MASK)

#define NETC_IERB_VAMQR_BMT_MASK                 (0x80000000U)
#define NETC_IERB_VAMQR_BMT_SHIFT                (31U)
#define NETC_IERB_VAMQR_BMT(x)                   (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VAMQR_BMT_SHIFT)) & NETC_IERB_VAMQR_BMT_MASK)
/*! @} */

/* The count of NETC_IERB_VAMQR */
#define NETC_IERB_VAMQR_COUNT                    (1U)

/*! @name VBLPR - VSI 0 boot loader parameter register 0..VSI 0 boot loader parameter register 1 */
/*! @{ */

#define NETC_IERB_VBLPR_PARAM_VAL_MASK           (0xFFFFFFFFU)
#define NETC_IERB_VBLPR_PARAM_VAL_SHIFT          (0U)
#define NETC_IERB_VBLPR_PARAM_VAL(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VBLPR_PARAM_VAL_SHIFT)) & NETC_IERB_VBLPR_PARAM_VAL_MASK)
/*! @} */

/* The count of NETC_IERB_VBLPR */
#define NETC_IERB_VBLPR_COUNT                    (1U)

/* The count of NETC_IERB_VBLPR */
#define NETC_IERB_VBLPR_COUNT2                   (2U)

/*! @name VPMAR0 - VSI 0 primary MAC address register 0 */
/*! @{ */

#define NETC_IERB_VPMAR0_MAC_ADDR_MASK           (0xFFFFFFFFU)
#define NETC_IERB_VPMAR0_MAC_ADDR_SHIFT          (0U)
#define NETC_IERB_VPMAR0_MAC_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VPMAR0_MAC_ADDR_SHIFT)) & NETC_IERB_VPMAR0_MAC_ADDR_MASK)
/*! @} */

/* The count of NETC_IERB_VPMAR0 */
#define NETC_IERB_VPMAR0_COUNT                   (1U)

/*! @name VPMAR1 - VSI 0 primary MAC address register 1 */
/*! @{ */

#define NETC_IERB_VPMAR1_MAC_ADDR_MASK           (0xFFFFU)
#define NETC_IERB_VPMAR1_MAC_ADDR_SHIFT          (0U)
#define NETC_IERB_VPMAR1_MAC_ADDR(x)             (((uint32_t)(((uint32_t)(x)) << NETC_IERB_VPMAR1_MAC_ADDR_SHIFT)) & NETC_IERB_VPMAR1_MAC_ADDR_MASK)
/*! @} */

/* The count of NETC_IERB_VPMAR1 */
#define NETC_IERB_VPMAR1_COUNT                   (1U)


/*!
 * @}
 */ /* end of group NETC_IERB_Register_Masks */


/*!
 * @}
 */ /* end of group NETC_IERB_Peripheral_Access_Layer */


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


#endif  /* PERI_NETC_IERB_H_ */

