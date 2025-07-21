/*
** ###################################################################
**     Processors:          MCXE315MLF
**                          MCXE315MPA
**                          MCXE316MLF
**                          MCXE316MPA
**
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DCM_GPR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DCM_GPR.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for DCM_GPR
 *
 * CMSIS Peripheral Access Layer for DCM_GPR
 */

#if !defined(PERI_DCM_GPR_H_)
#define PERI_DCM_GPR_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE315MLF) || defined(CPU_MCXE315MPA))
#include "MCXE315_COMMON.h"
#elif (defined(CPU_MCXE316MLF) || defined(CPU_MCXE316MPA))
#include "MCXE316_COMMON.h"
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
   -- DCM_GPR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_GPR_Peripheral_Access_Layer DCM_GPR Peripheral Access Layer
 * @{
 */

/** DCM_GPR - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t DCMROD1;                           /**< Read-Only GPR On Destructive Reset 1, offset: 0x200 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DCMROD3;                           /**< Read-Only GPR On Destructive Reset 3, offset: 0x208 */
  __IO uint32_t DCMROD4;                           /**< Read-Only GPR On Destructive Reset 4, offset: 0x20C */
  __IO uint32_t DCMROD5;                           /**< Read-Only GPR On Destructive Reset 5, offset: 0x210 */
       uint8_t RESERVED_2[236];
       uint32_t DCMROF1;                           /**< Read-Only GPR On Functional Reset 1, offset: 0x300 */
  __IO uint32_t DCMROF2;                           /**< Read-Only GPR On Functional Reset 2, offset: 0x304 */
  __IO uint32_t DCMROF3;                           /**< Read-Only GPR On Functional Reset 3, offset: 0x308 */
  __IO uint32_t DCMROF4;                           /**< Read-Only GPR On Functional Reset 4, offset: 0x30C */
  __IO uint32_t DCMROF5;                           /**< Read-Only GPR On Functional Reset 5, offset: 0x310 */
  __IO uint32_t DCMROF6;                           /**< Read-Only GPR On Functional Reset 6, offset: 0x314 */
  __IO uint32_t DCMROF7;                           /**< Read-Only GPR On Functional Reset 7, offset: 0x318 */
  __IO uint32_t DCMROF8;                           /**< Read-Only GPR On Functional Reset 8, offset: 0x31C */
  __IO uint32_t DCMROF9;                           /**< Read-Only GPR On Functional Reset 9, offset: 0x320 */
  __IO uint32_t DCMROF10;                          /**< Read-Only GPR On Functional Reset 10, offset: 0x324 */
  __IO uint32_t DCMROF11;                          /**< Read-Only GPR On Functional Reset 11, offset: 0x328 */
  __IO uint32_t DCMROF12;                          /**< Read-Only GPR On Functional Reset 12, offset: 0x32C */
  __IO uint32_t DCMROF13;                          /**< Read-Only GPR On Functional Reset 13, offset: 0x330 */
  __IO uint32_t DCMROF14;                          /**< Read-Only GPR On Functional Reset 14, offset: 0x334 */
  __IO uint32_t DCMROF15;                          /**< Read-Only GPR On Functional Reset 15, offset: 0x338 */
  __IO uint32_t DCMROF16;                          /**< Read-Only GPR On Functional Reset 16, offset: 0x33C */
  __IO uint32_t DCMROF17;                          /**< Read-Only GPR On Functional Reset 17, offset: 0x340 */
       uint8_t RESERVED_3[4];
  __I  uint32_t DCMROF19;                          /**< Read-Only GPR On Functional Reset 19, offset: 0x348 */
  __I  uint32_t DCMROF20;                          /**< Read-Only GPR On Functional Reset 20, offset: 0x34C */
  __I  uint32_t DCMROF21;                          /**< Read-Only GPR On Functional Reset 21, offset: 0x350 */
       uint8_t RESERVED_4[172];
  __IO uint32_t DCMRWP1;                           /**< Read Write GPR On POR 1, offset: 0x400 */
       uint8_t RESERVED_5[4];
  __IO uint32_t DCMRWP3;                           /**< Read Write GPR On POR 3, offset: 0x408 */
       uint8_t RESERVED_6[248];
  __IO uint32_t DCMRWD2;                           /**< Read Write GPR On Destructive Reset 2, offset: 0x504 */
  __IO uint32_t DCMRWD3;                           /**< Read Write GPR On Destructive Reset 3, offset: 0x508 */
  __IO uint32_t DCMRWD4;                           /**< Read Write GPR On Destructive Reset 4, offset: 0x50C */
  __IO uint32_t DCMRWD5;                           /**< Read Write GPR On Destructive Reset 5, offset: 0x510 */
  __IO uint32_t DCMRWD6;                           /**< Read Write GPR On Destructive Reset 6, offset: 0x514 */
       uint32_t DCMRWD7;                           /**< Read Write GPR On Destructive Reset 7, offset: 0x518 */
       uint32_t DCMRWD8;                           /**< Read Write GPR On Destructive Reset 8, offset: 0x51C */
       uint32_t DCMRWD9;                           /**< Read Write GPR On Destructive Reset 9, offset: 0x520 */
       uint8_t RESERVED_7[220];
  __IO uint32_t DCMRWF1;                           /**< Read Write GPR On Functional Reset 1, offset: 0x600 */
  __IO uint32_t DCMRWF2;                           /**< Read Write GPR On Functional Reset 2, offset: 0x604 */
       uint8_t RESERVED_8[4];
  __IO uint32_t DCMRWF4;                           /**< Read Write GPR On Functional Reset 4, offset: 0x60C */
  __IO uint32_t DCMRWF5;                           /**< Read Write GPR On Functional Reset 5, offset: 0x610 */
       uint8_t RESERVED_9[236];
  __IO uint32_t DCMROPP1;                          /**< Read-Only GPR On PMCPOR Reset 1, offset: 0x700 */
  __IO uint32_t DCMROPP2;                          /**< Read-Only GPR On PMCPOR Reset 2, offset: 0x704 */
  __IO uint32_t DCMROPP3;                          /**< Read-Only GPR On PMCPOR Reset 3, offset: 0x708 */
  __IO uint32_t DCMROPP4;                          /**< Read-Only GPR On PMCPOR Reset 4, offset: 0x70C */
} DCM_GPR_Type;

/* ----------------------------------------------------------------------------
   -- DCM_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_GPR_Register_Masks DCM_GPR Register Masks
 * @{
 */

/*! @name DCMROD1 - Read-Only GPR On Destructive Reset 1 */
/*! @{ */

#define DCM_GPR_DCMROD1_PCU_ISO_STATUS_MASK      (0x1U)
#define DCM_GPR_DCMROD1_PCU_ISO_STATUS_SHIFT     (0U)
/*! PCU_ISO_STATUS - PCU Input Isolation Status On Previous Standby Entry
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD1_PCU_ISO_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD1_PCU_ISO_STATUS_SHIFT)) & DCM_GPR_DCMROD1_PCU_ISO_STATUS_MASK)
/*! @} */

/*! @name DCMROD3 - Read-Only GPR On Destructive Reset 3 */
/*! @{ */

#define DCM_GPR_DCMROD3_CM7_0_LOCKUP_MASK        (0x1U)
#define DCM_GPR_DCMROD3_CM7_0_LOCKUP_SHIFT       (0U)
/*! CM7_0_LOCKUP - Cortex-M7_0 Core Lockup Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_CM7_0_LOCKUP(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_LOCKUP_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_LOCKUP_MASK)

#define DCM_GPR_DCMROD3_HSE_LOCKUP_MASK          (0x4U)
#define DCM_GPR_DCMROD3_HSE_LOCKUP_SHIFT         (2U)
/*! HSE_LOCKUP - HSE_B Core Lockup Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_HSE_LOCKUP(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_HSE_LOCKUP_SHIFT)) & DCM_GPR_DCMROD3_HSE_LOCKUP_MASK)

#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM_MASK      (0x20U)
#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM_SHIFT     (5U)
/*! TCM_GSKT_ALARM - TCM IAHB Gasket Monitor Alarm Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_TCM_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_TCM_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM_MASK      (0x100U)
#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM_SHIFT     (8U)
/*! SYS_AXBS_ALARM - System AXBS Safety Alarm Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_SYS_AXBS_ALARM_SHIFT)) & DCM_GPR_DCMROD3_SYS_AXBS_ALARM_MASK)

#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM_MASK      (0x800U)
#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM_SHIFT     (11U)
/*! HSE_GSKT_ALARM - HSE IAHB Gasket Alarm Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_HSE_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_HSE_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_MASK    (0x2000U)
#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_SHIFT   (13U)
/*! AIPS1_GSKT_ALARM - AIPS1 IAHB Gasket Alarm Status. Read this bit to identify the reason for a fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by AIPS1 IAHB gasket.
 *  0b1..Alarm indicated by AIPS1 IAHB gasket.
 */
#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_ADDR_EDC_ERR_MASK        (0x8000U)
#define DCM_GPR_DCMROD3_ADDR_EDC_ERR_SHIFT       (15U)
/*! ADDR_EDC_ERR - Address EDC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_ADDR_EDC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_ADDR_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD3_ADDR_EDC_ERR_MASK)

#define DCM_GPR_DCMROD3_DATA_EDC_ERR_MASK        (0x10000U)
#define DCM_GPR_DCMROD3_DATA_EDC_ERR_SHIFT       (16U)
/*! DATA_EDC_ERR - Data EDC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_DATA_EDC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_DATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD3_DATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD3_LC_ERR_MASK              (0x400000U)
#define DCM_GPR_DCMROD3_LC_ERR_SHIFT             (22U)
/*! LC_ERR - Error In Life Cycle Scanning
 *  0b0..No error while lifecycle scanning.
 *  0b1..Error while lifecycle scanning
 */
#define DCM_GPR_DCMROD3_LC_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_LC_ERR_SHIFT)) & DCM_GPR_DCMROD3_LC_ERR_MASK)

#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR_MASK       (0x2000000U)
#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR_SHIFT      (25U)
/*! PRAM0_ECC_ERR - Multi-Bit ECC Error From PRAM0
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_PRAM0_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_PRAM0_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_MASK (0x4000000U)
#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_SHIFT (26U)
/*! CM7_0_DCDATA_ECC_ERR - Cortex-M7_0 D-cache Data Memory ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_MASK (0x10000000U)
#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_SHIFT (28U)
/*! CM7_0_DCTAG_ECC_ERR - Cortex-M7_0 D-cache Tag ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_MASK (0x40000000U)
#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_SHIFT (30U)
/*! CM7_0_ICDATA_ECC_ERR - Cortex-M7_0 I-cache Data ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_MASK)
/*! @} */

/*! @name DCMROD4 - Read-Only GPR On Destructive Reset 4 */
/*! @{ */

#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_MASK (0x1U)
#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_SHIFT (0U)
/*! CM7_0_ICTAG_ECC_ERR - Cortex-M7_0 I-cache Tag ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_MASK  (0x4U)
#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_SHIFT (2U)
/*! CM7_0_ITCM_ECC_ERR - Cortex-M7_0 ITCM ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_MASK (0x8U)
#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_SHIFT (3U)
/*! CM7_0_DTCM0_ECC_ERR - Cortex-M7_0 DTCM 0 ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_MASK (0x10U)
#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_SHIFT (4U)
/*! CM7_0_DTCM1_ECC_ERR - Cortex-M7_0 DTCM 1 ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_MASK (0x100U)
#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_SHIFT (8U)
/*! DMA_TCD_RAM_ECC_ERR - eDMA TCD RAM ECC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_MASK    (0x200U)
#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_SHIFT   (9U)
/*! PRAM0_FCCU_ALARM - PRAM0 FCCU Alarm Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_SHIFT)) & DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_MASK)

#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_MASK     (0x800U)
#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_SHIFT    (11U)
/*! HSE_RAM_ECC_ERR - HSE_B RAM Uncorrectable ECC Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_MASK    (0x1000U)
#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_SHIFT   (12U)
/*! PF0_CODE_ECC_ERR - Program Flash Memory 0 Code ECC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_MASK    (0x2000U)
#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_SHIFT   (13U)
/*! PF0_DATA_ECC_ERR - Program Flash Memory 0 Data ECC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_MASK    (0x4000U)
#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_SHIFT   (14U)
/*! PF1_CODE_ECC_ERR - Program Flash Memory 1 Code ECC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_MASK    (0x8000U)
#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_SHIFT   (15U)
/*! PF1_DATA_ECC_ERR - Program Flash Memory 1 Data ECC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_EDC_ERR_MASK       (0x40000U)
#define DCM_GPR_DCMROD4_FLASH_EDC_ERR_SHIFT      (18U)
/*! FLASH_EDC_ERR - Flash Memory EDC Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_FLASH_EDC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_EDC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_MASK  (0x80000U)
#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_SHIFT (19U)
/*! FLASH_ADDR_ENC_ERR - Flash Memory Address Encode Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_REF_ERR_MASK       (0x100000U)
#define DCM_GPR_DCMROD4_FLASH_REF_ERR_SHIFT      (20U)
/*! FLASH_REF_ERR - Flash Memory Reference Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_FLASH_REF_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_REF_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_REF_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_RST_ERR_MASK       (0x200000U)
#define DCM_GPR_DCMROD4_FLASH_RST_ERR_SHIFT      (21U)
/*! FLASH_RST_ERR - Flash Reset Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_FLASH_RST_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_RST_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_RST_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR_MASK      (0x400000U)
#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR_SHIFT     (22U)
/*! FLASH_SCAN_ERR - Flash Memory Scan Error Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_SCAN_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_SCAN_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_ECC_ERR_MASK       (0x2000000U)
#define DCM_GPR_DCMROD4_FLASH_ECC_ERR_SHIFT      (25U)
/*! FLASH_ECC_ERR - ECC Error From Flash Controller
 *  0b0..No ECC error from flash controller.
 *  0b1..ECC error from flash controller.
 */
#define DCM_GPR_DCMROD4_FLASH_ECC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_MASK      (0x4000000U)
#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_SHIFT     (26U)
/*! VDD1P1_GNG_ERR - Go/No-go Indicator For VDD1PD1
 *  0b0..Yes
 *  0b1..No
 */
#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_SHIFT)) & DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_MASK)

#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_MASK      (0x8000000U)
#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_SHIFT     (27U)
/*! VDD2P5_GNG_ERR - Go/No-go Indicator For VDD_HV_FLA
 *  0b0..Yes
 *  0b1..No
 */
#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_SHIFT)) & DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_MASK)

#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_MASK (0x20000000U)
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_SHIFT (29U)
/*! TEST_ACTIVATION_0_ERR - Accidental Partial Test Activation 0 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_SHIFT)) & DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_MASK)

#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_MASK (0x40000000U)
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_SHIFT (30U)
/*! TEST_ACTIVATION_1_ERR - Accidental Partial Test Activation 1 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_SHIFT)) & DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_MASK)
/*! @} */

/*! @name DCMROD5 - Read-Only GPR On Destructive Reset 5 */
/*! @{ */

#define DCM_GPR_DCMROD5_INTM_0_ERR_MASK          (0x2U)
#define DCM_GPR_DCMROD5_INTM_0_ERR_SHIFT         (1U)
/*! INTM_0_ERR - INTM_0 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_INTM_0_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_0_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_0_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_1_ERR_MASK          (0x4U)
#define DCM_GPR_DCMROD5_INTM_1_ERR_SHIFT         (2U)
/*! INTM_1_ERR - INTM_1 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_INTM_1_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_1_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_1_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_2_ERR_MASK          (0x8U)
#define DCM_GPR_DCMROD5_INTM_2_ERR_SHIFT         (3U)
/*! INTM_2_ERR - INTM_2 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_INTM_2_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_2_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_2_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_3_ERR_MASK          (0x10U)
#define DCM_GPR_DCMROD5_INTM_3_ERR_SHIFT         (4U)
/*! INTM_3_ERR - INTM_3 Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_INTM_3_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_3_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_3_ERR_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_0_MASK            (0x20U)
#define DCM_GPR_DCMROD5_SW_NCF_0_SHIFT           (5U)
/*! SW_NCF_0 - Software NCF 0 Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_SW_NCF_0(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_0_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_0_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_1_MASK            (0x40U)
#define DCM_GPR_DCMROD5_SW_NCF_1_SHIFT           (6U)
/*! SW_NCF_1 - Software NCF1 Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_SW_NCF_1(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_1_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_1_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_2_MASK            (0x80U)
#define DCM_GPR_DCMROD5_SW_NCF_2_SHIFT           (7U)
/*! SW_NCF_2 - Software NCF2 Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_SW_NCF_2(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_2_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_2_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_3_MASK            (0x100U)
#define DCM_GPR_DCMROD5_SW_NCF_3_SHIFT           (8U)
/*! SW_NCF_3 - Software NCF3 Status
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_SW_NCF_3(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_3_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_3_MASK)

#define DCM_GPR_DCMROD5_STCU_NCF_MASK            (0x200U)
#define DCM_GPR_DCMROD5_STCU_NCF_SHIFT           (9U)
/*! STCU_NCF - STCU2 NCF Result Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_STCU_NCF(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_STCU_NCF_SHIFT)) & DCM_GPR_DCMROD5_STCU_NCF_MASK)

#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_MASK (0x400U)
#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_SHIFT (10U)
/*! MBIST_ACTIVATION_ERR - MBIST Activation Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_SHIFT)) & DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_MASK)

#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF_MASK   (0x800U)
#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF_SHIFT  (11U)
/*! STCU_BIST_USER_CF - STCU2 BIST User Critical Fault (CF)
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_STCU_BIST_USER_CF_SHIFT)) & DCM_GPR_DCMROD5_STCU_BIST_USER_CF_MASK)

#define DCM_GPR_DCMROD5_MCT_BUS_ERR_MASK         (0x1000U)
#define DCM_GPR_DCMROD5_MCT_BUS_ERR_SHIFT        (12U)
/*! MCT_BUS_ERR - MCT Bus Error
 *  0b0..No transfer error indicated from MCT.
 *  0b1..Transfer error indicated from MCT.
 */
#define DCM_GPR_DCMROD5_MCT_BUS_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_MCT_BUS_ERR_SHIFT)) & DCM_GPR_DCMROD5_MCT_BUS_ERR_MASK)

#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_MASK (0x2000U)
#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_SHIFT (13U)
/*! DEBUG_ACTIVATION_ERR - Debug Activation Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_SHIFT)) & DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_MASK)

#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_MASK   (0x20000U)
#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_SHIFT  (17U)
/*! DMA_RDATA_EDC_ERR - eDMA Read Data EDC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_MASK (0x100000U)
#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_SHIFT (20U)
/*! CM7_0_AHBP_RDATA_EDC_ERR - Cortex-M7_0 AHBP Read Data EDC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_MASK (0x200000U)
#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_SHIFT (21U)
/*! CM7_0_AHBM_RDATA_EDC_ERR - Cortex-M7_0 AHBM Read Data EDC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_MASK   (0x400000U)
#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_SHIFT  (22U)
/*! HSE_RDATA_EDC_ERR - HSE_B Read Data EDC Error
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_MASK)
/*! @} */

/*! @name DCMROF2 - Read-Only GPR On Functional Reset 2 */
/*! @{ */

#define DCM_GPR_DCMROF2_DCF_SDID0_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF2_DCF_SDID0_SHIFT          (0U)
/*! DCF_SDID0 - DCF Client SDID 0 Configuration */
#define DCM_GPR_DCMROF2_DCF_SDID0(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF2_DCF_SDID0_SHIFT)) & DCM_GPR_DCMROF2_DCF_SDID0_MASK)
/*! @} */

/*! @name DCMROF3 - Read-Only GPR On Functional Reset 3 */
/*! @{ */

#define DCM_GPR_DCMROF3_DCF_SDID1_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF3_DCF_SDID1_SHIFT          (0U)
/*! DCF_SDID1 - DCF Client SDID 1 Configuration */
#define DCM_GPR_DCMROF3_DCF_SDID1(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF3_DCF_SDID1_SHIFT)) & DCM_GPR_DCMROF3_DCF_SDID1_MASK)
/*! @} */

/*! @name DCMROF4 - Read-Only GPR On Functional Reset 4 */
/*! @{ */

#define DCM_GPR_DCMROF4_DCF_SDID2_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF4_DCF_SDID2_SHIFT          (0U)
/*! DCF_SDID2 - DCF Client SDID 2 Configuration */
#define DCM_GPR_DCMROF4_DCF_SDID2(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF4_DCF_SDID2_SHIFT)) & DCM_GPR_DCMROF4_DCF_SDID2_MASK)
/*! @} */

/*! @name DCMROF5 - Read-Only GPR On Functional Reset 5 */
/*! @{ */

#define DCM_GPR_DCMROF5_DCF_SDID3_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF5_DCF_SDID3_SHIFT          (0U)
/*! DCF_SDID3 - DCF Client SDID 3 Configuration */
#define DCM_GPR_DCMROF5_DCF_SDID3(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF5_DCF_SDID3_SHIFT)) & DCM_GPR_DCMROF5_DCF_SDID3_MASK)
/*! @} */

/*! @name DCMROF6 - Read-Only GPR On Functional Reset 6 */
/*! @{ */

#define DCM_GPR_DCMROF6_DCF_SDID4_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF6_DCF_SDID4_SHIFT          (0U)
/*! DCF_SDID4 - DCF Client SDID 4 Configuration */
#define DCM_GPR_DCMROF6_DCF_SDID4(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF6_DCF_SDID4_SHIFT)) & DCM_GPR_DCMROF6_DCF_SDID4_MASK)
/*! @} */

/*! @name DCMROF7 - Read-Only GPR On Functional Reset 7 */
/*! @{ */

#define DCM_GPR_DCMROF7_DCF_SDID5_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF7_DCF_SDID5_SHIFT          (0U)
/*! DCF_SDID5 - DCF Client SDID 5 Configuration */
#define DCM_GPR_DCMROF7_DCF_SDID5(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF7_DCF_SDID5_SHIFT)) & DCM_GPR_DCMROF7_DCF_SDID5_MASK)
/*! @} */

/*! @name DCMROF8 - Read-Only GPR On Functional Reset 8 */
/*! @{ */

#define DCM_GPR_DCMROF8_DCF_SDID6_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF8_DCF_SDID6_SHIFT          (0U)
/*! DCF_SDID6 - DCF Client SDID 6 Configuration */
#define DCM_GPR_DCMROF8_DCF_SDID6(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF8_DCF_SDID6_SHIFT)) & DCM_GPR_DCMROF8_DCF_SDID6_MASK)
/*! @} */

/*! @name DCMROF9 - Read-Only GPR On Functional Reset 9 */
/*! @{ */

#define DCM_GPR_DCMROF9_DCF_SDID7_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF9_DCF_SDID7_SHIFT          (0U)
/*! DCF_SDID7 - DCF Client SDID 7 Configuration */
#define DCM_GPR_DCMROF9_DCF_SDID7(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF9_DCF_SDID7_SHIFT)) & DCM_GPR_DCMROF9_DCF_SDID7_MASK)
/*! @} */

/*! @name DCMROF10 - Read-Only GPR On Functional Reset 10 */
/*! @{ */

#define DCM_GPR_DCMROF10_DCF_SDID8_MASK          (0xFFFFFFFFU)
#define DCM_GPR_DCMROF10_DCF_SDID8_SHIFT         (0U)
/*! DCF_SDID8 - DCF Client SDID 8 Configuration */
#define DCM_GPR_DCMROF10_DCF_SDID8(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF10_DCF_SDID8_SHIFT)) & DCM_GPR_DCMROF10_DCF_SDID8_MASK)
/*! @} */

/*! @name DCMROF11 - Read-Only GPR On Functional Reset 11 */
/*! @{ */

#define DCM_GPR_DCMROF11_DCF_SDID9_MASK          (0xFFFFFFFFU)
#define DCM_GPR_DCMROF11_DCF_SDID9_SHIFT         (0U)
/*! DCF_SDID9 - DCF Client SDID 9 Configuration */
#define DCM_GPR_DCMROF11_DCF_SDID9(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF11_DCF_SDID9_SHIFT)) & DCM_GPR_DCMROF11_DCF_SDID9_MASK)
/*! @} */

/*! @name DCMROF12 - Read-Only GPR On Functional Reset 12 */
/*! @{ */

#define DCM_GPR_DCMROF12_DCF_SDID10_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF12_DCF_SDID10_SHIFT        (0U)
/*! DCF_SDID10 - DCF Client SDID 10 Configuration */
#define DCM_GPR_DCMROF12_DCF_SDID10(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF12_DCF_SDID10_SHIFT)) & DCM_GPR_DCMROF12_DCF_SDID10_MASK)
/*! @} */

/*! @name DCMROF13 - Read-Only GPR On Functional Reset 13 */
/*! @{ */

#define DCM_GPR_DCMROF13_DCF_SDID11_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF13_DCF_SDID11_SHIFT        (0U)
/*! DCF_SDID11 - DCF Client SDID 11 Configuration */
#define DCM_GPR_DCMROF13_DCF_SDID11(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF13_DCF_SDID11_SHIFT)) & DCM_GPR_DCMROF13_DCF_SDID11_MASK)
/*! @} */

/*! @name DCMROF14 - Read-Only GPR On Functional Reset 14 */
/*! @{ */

#define DCM_GPR_DCMROF14_DCF_SDID12_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF14_DCF_SDID12_SHIFT        (0U)
/*! DCF_SDID12 - DCF Client SDID 12 Configuration */
#define DCM_GPR_DCMROF14_DCF_SDID12(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF14_DCF_SDID12_SHIFT)) & DCM_GPR_DCMROF14_DCF_SDID12_MASK)
/*! @} */

/*! @name DCMROF15 - Read-Only GPR On Functional Reset 15 */
/*! @{ */

#define DCM_GPR_DCMROF15_DCF_SDID13_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF15_DCF_SDID13_SHIFT        (0U)
/*! DCF_SDID13 - DCF Client SDID 13 Configuration */
#define DCM_GPR_DCMROF15_DCF_SDID13(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF15_DCF_SDID13_SHIFT)) & DCM_GPR_DCMROF15_DCF_SDID13_MASK)
/*! @} */

/*! @name DCMROF16 - Read-Only GPR On Functional Reset 16 */
/*! @{ */

#define DCM_GPR_DCMROF16_DCF_SDID14_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF16_DCF_SDID14_SHIFT        (0U)
/*! DCF_SDID14 - DCF Client SDID 14 Configuration */
#define DCM_GPR_DCMROF16_DCF_SDID14(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF16_DCF_SDID14_SHIFT)) & DCM_GPR_DCMROF16_DCF_SDID14_MASK)
/*! @} */

/*! @name DCMROF17 - Read-Only GPR On Functional Reset 17 */
/*! @{ */

#define DCM_GPR_DCMROF17_DCF_SDID15_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF17_DCF_SDID15_SHIFT        (0U)
/*! DCF_SDID15 - DCF Client SDID 15 Configuration */
#define DCM_GPR_DCMROF17_DCF_SDID15(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF17_DCF_SDID15_SHIFT)) & DCM_GPR_DCMROF17_DCF_SDID15_MASK)
/*! @} */

/*! @name DCMROF19 - Read-Only GPR On Functional Reset 19 */
/*! @{ */

#define DCM_GPR_DCMROF19_DCM_DONE_MASK           (0x40000000U)
#define DCM_GPR_DCMROF19_DCM_DONE_SHIFT          (30U)
/*! DCM_DONE - Flash Memory Scanning Status
 *  0b0..Incomplete
 *  0b1..Complete
 */
#define DCM_GPR_DCMROF19_DCM_DONE(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF19_DCM_DONE_SHIFT)) & DCM_GPR_DCMROF19_DCM_DONE_MASK)

#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_MASK (0x80000000U)
#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_SHIFT (31U)
/*! FCCU_EOUT_DEDICATED - FCCU EOUT Status
 *  0b0..General purpose, supporting all functions
 *  0b1..Dedicated EOUT pins
 */
#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_SHIFT)) & DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_MASK)
/*! @} */

/*! @name DCMROF20 - Read-Only GPR On Functional Reset 20 */
/*! @{ */

#define DCM_GPR_DCMROF20_POR_WDG_EN_MASK         (0x1U)
#define DCM_GPR_DCMROF20_POR_WDG_EN_SHIFT        (0U)
/*! POR_WDG_EN - POR Watchdog (POR_WDG) Status
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMROF20_POR_WDG_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_POR_WDG_EN_SHIFT)) & DCM_GPR_DCMROF20_POR_WDG_EN_MASK)

#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP_MASK      (0x40U)
#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP_SHIFT     (6U)
/*! AIPS_IAHB_BYP
 *  0b0..Register wall enabled.
 *  0b1..Register wall bypassed.
 */
#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_AIPS_IAHB_BYP_SHIFT)) & DCM_GPR_DCMROF20_AIPS_IAHB_BYP_MASK)

#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_MASK   (0xFFFC0000U)
#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_SHIFT  (18U)
/*! DCF_DEST_RST_ESC - DCF Destructive Reset Escalation
 *  0b00000000000000..Disables
 *  0b00000000000001..Enables
 */
#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_SHIFT)) & DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_MASK)
/*! @} */

/*! @name DCMROF21 - Read-Only GPR On Functional Reset 21 */
/*! @{ */

#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_MASK   (0x3FFFFU)
#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_SHIFT  (0U)
/*! DCF_DEST_RST_ESC - DCF Destructive Reset Escalation
 *  0b000000000000000000..Disables
 *  0b000000000000000001..Enables
 */
#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_SHIFT)) & DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_MASK)

#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_MASK (0x180000U)
#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_SHIFT (19U)
/*! HSE_CLK_MODE_OPTION - HSE_B Clock Mode Option
 *  0b00..Option A
 *  0b01..Options C, D, E, E2, and F
 *  0b10..Option B
 *  0b11..Option B
 */
#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_SHIFT)) & DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_MASK)
/*! @} */

/*! @name DCMRWP1 - Read Write GPR On POR 1 */
/*! @{ */

#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY_MASK      (0x8U)
#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY_SHIFT     (3U)
/*! CLKOUT_STANDBY - Clockout Standby Expose Over Functional And Destructive Reset
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_CLKOUT_STANDBY_SHIFT)) & DCM_GPR_DCMRWP1_CLKOUT_STANDBY_MASK)

#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_MASK   (0x100U)
#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_SHIFT  (8U)
/*! STANBDY_PWDOG_DIS - Standby POR_WDG Disable
 *  0b0..Enables
 *  0b1..Disables
 */
#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_SHIFT)) & DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_MASK)

#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM_MASK       (0x600U)
#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM_SHIFT      (9U)
/*! POR_WDOG_TRIM - POR_WDG Trim
 *  0b00..POR_WDG timeout = 06.25 ms
 *  0b01..POR_WDG timeout = 12.50 ms
 *  0b10..POR_WDG timeout = 25.00 ms
 *  0b11..POR_WDG timeout = 50.00 ms
 */
#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_POR_WDOG_TRIM_SHIFT)) & DCM_GPR_DCMRWP1_POR_WDOG_TRIM_MASK)

#define DCM_GPR_DCMRWP1_DEST_RESET_COUNT_MASK    (0x7800U)
#define DCM_GPR_DCMRWP1_DEST_RESET_COUNT_SHIFT   (11U)
/*! DEST_RESET_COUNT - Destructive Reset Counts */
#define DCM_GPR_DCMRWP1_DEST_RESET_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_DEST_RESET_COUNT_SHIFT)) & DCM_GPR_DCMRWP1_DEST_RESET_COUNT_MASK)

#define DCM_GPR_DCMRWP1_SYS_REC_COUNTER_MASK     (0x1F0000U)
#define DCM_GPR_DCMRWP1_SYS_REC_COUNTER_SHIFT    (16U)
/*! SYS_REC_COUNTER - System Recovery Counter */
#define DCM_GPR_DCMRWP1_SYS_REC_COUNTER(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_SYS_REC_COUNTER_SHIFT)) & DCM_GPR_DCMRWP1_SYS_REC_COUNTER_MASK)

#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_FRST_MASK   (0x400000U)
#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_FRST_SHIFT  (22U)
/*! SBAF_REC_DIS_FRST - Disable Recovery Mode On Functional Reset */
#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_FRST(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_SBAF_REC_DIS_FRST_SHIFT)) & DCM_GPR_DCMRWP1_SBAF_REC_DIS_FRST_MASK)

#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_DRST_MASK   (0x800000U)
#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_DRST_SHIFT  (23U)
/*! SBAF_REC_DIS_DRST - Disable Recovery Mode On Destructive Reset */
#define DCM_GPR_DCMRWP1_SBAF_REC_DIS_DRST(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_SBAF_REC_DIS_DRST_SHIFT)) & DCM_GPR_DCMRWP1_SBAF_REC_DIS_DRST_MASK)
/*! @} */

/*! @name DCMRWP3 - Read Write GPR On POR 3 */
/*! @{ */

#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_MASK    (0x200U)
#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_SHIFT   (9U)
/*! DEST_RST9_AS_IPI - Destructive Reset 9
 *  0b0..Destructive reset
 *  0b1..PLL LOL interrupt
 */
#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_SHIFT)) & DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_MASK)
/*! @} */

/*! @name DCMRWD2 - Read Write GPR On Destructive Reset 2 */
/*! @{ */

#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_MASK (0x80U)
#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_SHIFT (7U)
/*! EOUT_STAT_DUR_STEST - Controls the EOUT state during self-test
 *  0b0..High impedance
 *  0b1..Fault state
 */
#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_SHIFT)) & DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_MASK)
/*! @} */

/*! @name DCMRWD3 - Read Write GPR On Destructive Reset 3 */
/*! @{ */

#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_MASK     (0x1U)
#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_SHIFT    (0U)
/*! CM7_0_LOCKUP_EN - Cortex-M7 Lockup Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_MASK)

#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_MASK   (0x20U)
#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_SHIFT  (5U)
/*! TCM_GSKT_ALARM_EN - TCM Gasket Alarm Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_MASK   (0x100U)
#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_SHIFT  (8U)
/*! SYS_AXBS_ALARM_EN - System AXBS Alarm Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_MASK   (0x800U)
#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_SHIFT  (11U)
/*! HSE_GSKT_ALARM_EN - HSE_B Gasket Alarm Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_SHIFT (13U)
/*! AIPS1_GSKT_ALARM_EN
 *  0b0..No alarm indicated by AIPS1 IAHB gasket.
 *  0b1..Alarm indicated by AIPS1 IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_MASK     (0x8000U)
#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_SHIFT    (15U)
/*! ADDR_EDC_ERR_EN - Address EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_MASK     (0x10000U)
#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_SHIFT    (16U)
/*! DATA_EDC_ERR_EN - Data EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_LC_ERR_EN_MASK           (0x400000U)
#define DCM_GPR_DCMRWD3_LC_ERR_EN_SHIFT          (22U)
/*! LC_ERR_EN - Life Cycle Scanning Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_LC_ERR_EN(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_LC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_LC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_MASK    (0x2000000U)
#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_SHIFT   (25U)
/*! PRAM0_ECC_ERR_EN - PRAM0 ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_MASK (0x4000000U)
#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_SHIFT (26U)
/*! CM7_0_DCDATA_ECC_ERR_EN - Cortex-M7_0 D-cache Data ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_MASK (0x10000000U)
#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_SHIFT (28U)
/*! CM7_0_DCTAG_ECC_ERR_EN - Cortex-M7_0 D-cache Tag ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_MASK (0x40000000U)
#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_SHIFT (30U)
/*! CM7_0_ICDATA_ECC_ERR_EN - Cortex-M7_0 I-cache ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD4 - Read Write GPR On Destructive Reset 4 */
/*! @{ */

#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_MASK (0x1U)
#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_SHIFT (0U)
/*! CM7_0_ICTAG_ECC_ERR_EN - Cortex-M7_0 I-cache Tag ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_MASK (0x4U)
#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_SHIFT (2U)
/*! CM7_0_ITCM_ECC_ERR_EN - Cortex-M7 ITCM ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_MASK (0x8U)
#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_SHIFT (3U)
/*! CM7_0_DTCM0_ECC_ERR_EN - Cortex-M7_0 DTCM 0 ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_MASK (0x10U)
#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_SHIFT (4U)
/*! CM7_0_DTCM1_ECC_ERR_EN - Cortex-M7_0 DTCM 1 ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_MASK (0x100U)
#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_SHIFT (8U)
/*! DMA_TCD_RAM_ECC_ERR_EN - eDMA TCD RAM ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_MASK (0x200U)
#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_SHIFT (9U)
/*! PRAM0_FCCU_ALARM_EN - PRAM0 FCCU Alarm Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_MASK (0x1000U)
#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_SHIFT (12U)
/*! PF0_CODE_ECC_ERR_EN - PF0 Code ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_SHIFT (13U)
/*! PF0_DATA_ECC_ERR_EN - PF0 Data ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_MASK (0x4000U)
#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_SHIFT (14U)
/*! PF1_CODE_ECC_ERR_EN - PF1 Code ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_MASK (0x8000U)
#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_SHIFT (15U)
/*! PF1_DATA_ECC_ERR_EN - PF1 Data ECC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_MASK    (0x40000U)
#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_SHIFT   (18U)
/*! FLASH_EDC_ERR_EN - Flash Memory EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_MASK (0x80000U)
#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_SHIFT (19U)
/*! FLASH_ADDR_ENC_ERR_EN - Flash Memory Address Encode Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_MASK    (0x100000U)
#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_SHIFT   (20U)
/*! FLASH_REF_ERR_EN - Flash Memory Reference Error Encode
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_MASK    (0x200000U)
#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_SHIFT   (21U)
/*! FLASH_RST_ERR_EN - Flash Memory Reset Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_MASK   (0x400000U)
#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_SHIFT  (22U)
/*! FLASH_SCAN_ERR_EN - Flash Memory Scanning Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_MASK (0x1000000U)
#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_SHIFT (24U)
/*! FLASH_ACCESS_ERR_EN - Flash Memory Access Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_MASK   (0x4000000U)
#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_SHIFT  (26U)
/*! VDD1P1_GNG_ERR_EN - VDD1PD1 Go/No-go Error Enable
 *  0b0..Clean
 *  0b1..Unclean
 */
#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_MASK   (0x8000000U)
#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_SHIFT  (27U)
/*! VDD2P5_GNG_ERR_EN - VDD2P5 Go/No-go Error Enable
 *  0b0..Clean
 *  0b1..Unclean
 */
#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_MASK (0x20000000U)
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_SHIFT (29U)
/*! TEST_ACTIVATION_0_ERR_EN - Test Activation 0 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_MASK (0x40000000U)
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_SHIFT (30U)
/*! TEST_ACTIVATION_1_ERR_EN - Test Activation 1 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD5 - Read Write GPR On Destructive Reset 5 */
/*! @{ */

#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN_MASK       (0x2U)
#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN_SHIFT      (1U)
/*! INTM_0_ERR_EN - INTM 0 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_0_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_0_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN_MASK       (0x4U)
#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN_SHIFT      (2U)
/*! INTM_1_ERR_EN - INTM 1 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_1_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_1_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN_MASK       (0x8U)
#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN_SHIFT      (3U)
/*! INTM_2_ERR_EN - INTM 2 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_2_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_2_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN_MASK       (0x10U)
#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN_SHIFT      (4U)
/*! INTM_3_ERR_EN - INTM 3 Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_3_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_3_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_0_EN_MASK         (0x20U)
#define DCM_GPR_DCMRWD5_SW_NCF_0_EN_SHIFT        (5U)
/*! SW_NCF_0_EN - Software NCF 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWD5_SW_NCF_0_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_0_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_0_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_1_EN_MASK         (0x40U)
#define DCM_GPR_DCMRWD5_SW_NCF_1_EN_SHIFT        (6U)
/*! SW_NCF_1_EN - Software NCF 1 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWD5_SW_NCF_1_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_1_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_1_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_2_EN_MASK         (0x80U)
#define DCM_GPR_DCMRWD5_SW_NCF_2_EN_SHIFT        (7U)
/*! SW_NCF_2_EN - Software NCF 2 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWD5_SW_NCF_2_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_2_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_2_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_3_EN_MASK         (0x100U)
#define DCM_GPR_DCMRWD5_SW_NCF_3_EN_SHIFT        (8U)
/*! SW_NCF_3_EN - Software NCF 3 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWD5_SW_NCF_3_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_3_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_3_EN_MASK)

#define DCM_GPR_DCMRWD5_STCU_NCF_EN_MASK         (0x200U)
#define DCM_GPR_DCMRWD5_STCU_NCF_EN_SHIFT        (9U)
/*! STCU_NCF_EN - STCU2 NCF Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWD5_STCU_NCF_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_STCU_NCF_EN_SHIFT)) & DCM_GPR_DCMRWD5_STCU_NCF_EN_MASK)

#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_MASK (0x400U)
#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_SHIFT (10U)
/*! MBIST_ACTIVATION_ERR_EN - MBIST Activation Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_MASK (0x800U)
#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_SHIFT (11U)
/*! STCU_BIST_USER_CF_EN - STCU2 BIST User CF Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_SHIFT)) & DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_MASK)

#define DCM_GPR_DCMRWD5_MCT_BUS_ERR_EN_MASK      (0x1000U)
#define DCM_GPR_DCMRWD5_MCT_BUS_ERR_EN_SHIFT     (12U)
/*! MCT_BUS_ERR_EN - MCT Bus Error Enable
 *  0b0..No transfer error indicated from MCT.
 *  0b1..Transfer error indicated from MCT.
 */
#define DCM_GPR_DCMRWD5_MCT_BUS_ERR_EN(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_MCT_BUS_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_MCT_BUS_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_SHIFT (13U)
/*! DEBUG_ACTIVATION_ERR_EN - Debug Activation Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_MASK (0x20000U)
#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_SHIFT (17U)
/*! DMA_RDATA_EDC_ERR_EN - eDMA Read Data EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_MASK (0x100000U)
#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_SHIFT (20U)
/*! CM7_0_AHBP_RDATA_EDC_ERR_EN - Cortex-M7_0 AHBP Read Data EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_MASK (0x200000U)
#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_SHIFT (21U)
/*! CM7_0_AHBM_RDATA_EDC_ERR_EN - Cortex-M7_0 AHBM Read Data EDC Error Enable
 *  0b0..No
 *  0b1..Yes
 */
#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD6 - Read Write GPR On Destructive Reset 6 */
/*! @{ */

#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_MASK  (0x1U)
#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_SHIFT (0U)
/*! EDMA_DBG_DIS_CM7_0 - eDMA Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_MASK  (0x2U)
#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_SHIFT (1U)
/*! FCCU_DBG_DIS_CM7_0 - FCCU Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_MASK  (0x4U)
#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_SHIFT (2U)
/*! LCU0_DBG_DIS_CM7_0 - LCU_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_MASK  (0x8U)
#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_SHIFT (3U)
/*! LCU1_DBG_DIS_CM7_0 - LCU_1 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_MASK (0x10U)
#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_SHIFT (4U)
/*! EMIOS0_DBG_DIS_CM7_0 - eMIOS_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_MASK (0x20U)
#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_SHIFT (5U)
/*! EMIOS1_DBG_DIS_CM7_0
 *  0b0..eMIOS1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..eMIOS1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_MASK   (0x80U)
#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_SHIFT  (7U)
/*! RTC_DBG_DIS_CM7_0 - RTC Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_MASK  (0x100U)
#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_SHIFT (8U)
/*! SWT0_DBG_DIS_CM7_0 - SWT_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_MASK  (0x400U)
#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_SHIFT (10U)
/*! STM0_DBG_DIS_CM7_0 - STM_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_MASK  (0x1000U)
#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_SHIFT (12U)
/*! PIT0_DBG_DIS_CM7_0 - PIT_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_MASK  (0x2000U)
#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_SHIFT (13U)
/*! PIT1_DBG_DIS_CM7_0 - PIT_1 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_MASK (0x8000U)
#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_SHIFT (15U)
/*! LPSPI0_DBG_DIS_CM7_0 - LPSPI_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_MASK (0x10000U)
#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_SHIFT (16U)
/*! LPSPI1_DBG_DIS_CM7_0 - LPSPI_1 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_MASK (0x20000U)
#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_SHIFT (17U)
/*! LPSPI2_DBG_DIS_CM7_0 - LPSPI_2 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_MASK (0x40000U)
#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_SHIFT (18U)
/*! LPSPI3_DBG_DIS_CM7_0 - LPSPI_3 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_MASK (0x200000U)
#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_SHIFT (21U)
/*! LPI2C0_DBG_DIS_CM7_0 - LPI2C_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_MASK (0x400000U)
#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_SHIFT (22U)
/*! LPI2C1_DBG_DIS_CM7_0 - LPI2C_1 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_MASK (0x800000U)
#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_SHIFT (23U)
/*! FLEXIO_DBG_DIS_CM7_0 - FlexIO Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_MASK (0x1000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_SHIFT (24U)
/*! FLEXCAN0_DBG_DIS_CM7_0 - FlexCAN_0 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_MASK (0x2000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_SHIFT (25U)
/*! FLEXCAN1_DBG_DIS_CM7_0 - FlexCAN_1 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_MASK (0x4000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_SHIFT (26U)
/*! FLEXCAN2_DBG_DIS_CM7_0 - FlexCAN_2 Debug Disable Cortex-M7_0
 *  0b0..Enters Debug mode
 *  0b1..Remains functional and unimpacted
 */
#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_MASK)
/*! @} */

/*! @name DCMRWF1 - Read Write GPR On Functional Reset 1 */
/*! @{ */

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0_MASK        (0x4U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0_SHIFT       (2U)
/*! FCCU_SW_NCF0 - FCCU Software NCF 0
 *  0b0..Not generated
 *  0b1..Generated
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF0_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF0_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1_MASK        (0x8U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1_SHIFT       (3U)
/*! FCCU_SW_NCF1 - FCCU Software NCF 1
 *  0b0..Not generated
 *  0b1..Generated
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF1_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF1_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2_MASK        (0x10U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2_SHIFT       (4U)
/*! FCCU_SW_NCF2 - FCCU Software NCF 2
 *  0b0..Not generated
 *  0b1..Generated
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF2_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF2_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3_MASK        (0x20U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3_SHIFT       (5U)
/*! FCCU_SW_NCF3 - FCCU Software NCF 3
 *  0b0..Not generated
 *  0b1..Generated
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF3_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF3_MASK)

#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK   (0x10000U)
#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_SHIFT  (16U)
/*! STANDBY_IO_CONFIG - Standby I/O Configuration
 *  0b0..Must be written as 0 before IO configurations are done in standby entry sequence.
 *  0b1..Must be written as 1 after IO configurations are done on standby exit.
 */
#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_SHIFT)) & DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK)

#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK       (0x100000U)
#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN_SHIFT      (20U)
/*! SUPPLY_MON_EN - Supply Monitoring Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_SUPPLY_MON_EN_SHIFT)) & DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK)

#define DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_MASK      (0xE00000U)
#define DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_SHIFT     (21U)
/*! SUPPLY_MON_SEL - Supply Monitoring Select
 *  0b000..VDD_HV_A_DIV
 *  0b001..VDD_HV_B_DIV
 *  0b010..VDD_1.5_DIV
 *  0b011..VDD_2.5_OSC
 *  0b100..VDD1.1_PD1_HOT_POINT
 *  0b101..VDD1.1_PD1_COLD_POINT
 *  0b110..VDD1.1_PLL
 *  0b111..VDD1.1_PD0
 */
#define DCM_GPR_DCMRWF1_SUPPLY_MON_SEL(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_SHIFT)) & DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_MASK)

#define DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_MASK     (0x1000000U)
#define DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_SHIFT    (24U)
/*! VSS_LV_ANMUX_EN - VSS_LV Monitoring Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_SHIFT)) & DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_MASK)

#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK (0x2000000U)
#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_SHIFT (25U)
/*! VDD_HV_A_VLT_DVDR_EN - VDD_HV_A Voltage Divider Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_SHIFT)) & DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK)
/*! @} */

/*! @name DCMRWF2 - Read Write GPR On Functional Reset 2 */
/*! @{ */

#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK (0x8U)
#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_SHIFT (3U)
/*! DCM_SCAN_BYP_STDBY_EXT - DCM Scan Bypass Standby Exit
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK (0x10U)
#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_SHIFT (4U)
/*! FIRC_TRIM_BYP_STDBY_EXT - FIRC Trim Bypass Standby Exit
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_MASK (0x20U)
#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_SHIFT (5U)
/*! PMC_TRIM_RGM_DCF_BYP_STDBY_EXT - PMC Trim MC_RGM DCF Bypass Standby Exit
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_MASK     (0x10000U)
#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_SHIFT    (16U)
/*! HSE_GSKT_BYPASS - HSE_B Gasket Bypass
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_SHIFT)) & DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_MASK)
/*! @} */

/*! @name DCMRWF4 - Read Write GPR On Functional Reset 4 */
/*! @{ */

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S18_MASK (0x1U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S18_SHIFT (0U)
/*! MUX_MODE_EN_ADC1_S18 - Controls the selection of GPIOs to drive ADC1 standard channel 18th.
 *  0b0..Selects GPIO_70 as the ADC1_S18.
 *  0b1..Selects GPIO_6 as the ADC1_S18.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S18(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S18_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S18_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_MASK (0x2U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_SHIFT (1U)
/*! MUX_MODE_EN_ADC0_S8 - Mux Mode Enable ADC_0 Standard Channel 8
 *  0b0..GPIO_0
 *  0b1..GPIO_45
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_MASK (0x4U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_SHIFT (2U)
/*! MUX_MODE_EN_ADC0_S9 - Mux Mode Enable ADC_0 Standard Channel 9
 *  0b0..GPIO_1
 *  0b1..GPIO_46
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_MASK (0x8U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_SHIFT (3U)
/*! MUX_MODE_EN_ADC1_S14 - Mux Mode Enable ADC_1 Standard Channel 14
 *  0b0..GPIO_69
 *  0b1..GPIO_32
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_MASK (0x10U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_SHIFT (4U)
/*! MUX_MODE_EN_ADC1_S15 - Mux Mode Enable ADC_1 Standard Channel 15
 *  0b0..GPIO_4
 *  0b1..GPIO_33
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S12_MASK (0x80U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S12_SHIFT (7U)
/*! MUX_MODE_EN_ADC0_S12 - Mux Mode Enable ADC_0 Standard Channel 12
 *  0b0..GPIO_72
 *  0b1..GPIO_78
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S12(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S12_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S12_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S13_MASK (0x100U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S13_SHIFT (8U)
/*! MUX_MODE_EN_ADC0_S13 - Mux Mode Enable ADC_0 Standard Channel 13
 *  0b0..GPIO_73
 *  0b1..GPIO_79
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S13(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S13_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S13_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S14_MASK (0x800U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S14_SHIFT (11U)
/*! MUX_MODE_EN_ADC0_S14 - Mux Mode Enable ADC_0 Standard Channel 14
 *  0b0..GPIO_32
 *  0b1..GPIO_80
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S14(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S14_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S14_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S17_MASK (0x1000U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S17_SHIFT (12U)
/*! MUX_MODE_EN_ADC0_S17 - Mux Mode Enable ADC_0 Standard Channel 17
 *  0b0..GPIO_75
 *  0b1..GPIO_44
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S17(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S17_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S17_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_MASK (0x2000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_SHIFT (13U)
/*! GLITCH_FIL_TRG_IN0_BYP - Glitch Filter TRGMUX Input 0 Bypass
 *  0b0..Enables
 *  0b1..Bypasses
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_MASK (0x4000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_SHIFT (14U)
/*! GLITCH_FIL_TRG_IN1_BYP - Glitch Filter TRGMUX Input 1 Bypass
 *  0b0..Enables
 *  0b1..Bypasses
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_MASK (0x8000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_SHIFT (15U)
/*! GLITCH_FIL_TRG_IN2_BYP - Glitch Filter TRGMUX Input 2 Bypass
 *  0b0..Enables
 *  0b1..Bypasses
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_MASK (0x10000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_SHIFT (16U)
/*! GLITCH_FIL_TRG_IN3_BYP - Glitch Filter TRGMUX Input 3 Bypass
 *  0b0..Enables
 *  0b1..Bypasses
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_MASK)

#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_MASK       (0x20000U)
#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_SHIFT      (17U)
/*! CM7_0_CPUWAIT - Cortex-M7_0 CPU Wait
 *  0b0..Disables CPUWAIT
 *  0b1..Enables CPUWAIT
 */
#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_SHIFT)) & DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_P2_MASK (0x10000000U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_P2_SHIFT (28U)
/*! MUX_MODE_EN_ADC0_P2 - Mux Mode Enable ADC0 Precision Channel 2nd
 *  0b0..Selects GPIO_8 as the ADC0_P2.
 *  0b1..Selects GPIO_10 as the ADC0_P2.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_P2(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_P2_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_P2_MASK)
/*! @} */

/*! @name DCMRWF5 - Read Write GPR On Functional Reset 5 */
/*! @{ */

#define DCM_GPR_DCMRWF5_BOOT_MODE_MASK           (0x1U)
#define DCM_GPR_DCMRWF5_BOOT_MODE_SHIFT          (0U)
/*! BOOT_MODE - Boot Mode
 *  0b0..Normal
 *  0b1..Fast Standby
 */
#define DCM_GPR_DCMRWF5_BOOT_MODE(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF5_BOOT_MODE_SHIFT)) & DCM_GPR_DCMRWF5_BOOT_MODE_MASK)

#define DCM_GPR_DCMRWF5_BOOT_ADDRESS_MASK        (0xFFFFFFFEU)
#define DCM_GPR_DCMRWF5_BOOT_ADDRESS_SHIFT       (1U)
/*! BOOT_ADDRESS - Boot Address */
#define DCM_GPR_DCMRWF5_BOOT_ADDRESS(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF5_BOOT_ADDRESS_SHIFT)) & DCM_GPR_DCMRWF5_BOOT_ADDRESS_MASK)
/*! @} */

/*! @name DCMROPP1 - Read-Only GPR On PMCPOR Reset 1 */
/*! @{ */

#define DCM_GPR_DCMROPP1_POR_WDG_STAT0_MASK      (0x1U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT0_SHIFT     (0U)
/*! POR_WDG_STAT0 - POR_WDG Status 0
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT0(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT0_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT0_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT1_MASK      (0x2U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT1_SHIFT     (1U)
/*! POR_WDG_STAT1 - POR_WDG Status 1
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT1(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT1_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT1_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT2_MASK      (0x4U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT2_SHIFT     (2U)
/*! POR_WDG_STAT2 - POR_WDG Status 2
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT2(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT2_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT2_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT3_MASK      (0x8U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT3_SHIFT     (3U)
/*! POR_WDG_STAT3 - POR_WDG Status 3
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT3(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT3_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT3_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT4_MASK      (0x10U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT4_SHIFT     (4U)
/*! POR_WDG_STAT4 - POR_WDG Status 4
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT4(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT4_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT4_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT5_MASK      (0x20U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT5_SHIFT     (5U)
/*! POR_WDG_STAT5 - POR_WDG Status 5
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT5(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT5_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT5_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT6_MASK      (0x40U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT6_SHIFT     (6U)
/*! POR_WDG_STAT6 - POR_WDG Status 6
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT6(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT6_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT6_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT10_MASK     (0x400U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT10_SHIFT    (10U)
/*! POR_WDG_STAT10 - POR_WDG Status 10
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT10(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT10_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT10_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT11_MASK     (0x800U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT11_SHIFT    (11U)
/*! POR_WDG_STAT11 - POR_WDG Status 11
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT11(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT11_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT11_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT14_MASK     (0x4000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT14_SHIFT    (14U)
/*! POR_WDG_STAT14 - POR_WDG Status 14
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT14(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT14_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT14_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT17_MASK     (0x20000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT17_SHIFT    (17U)
/*! POR_WDG_STAT17 - POR_WDG Status 17
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT17(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT17_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT17_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT20_MASK     (0x100000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT20_SHIFT    (20U)
/*! POR_WDG_STAT20 - POR_WDG Status 20
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT20(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT20_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT20_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT29_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT29_SHIFT    (29U)
/*! POR_WDG_STAT29 - POR_WDG Status 29
 *  0b0..Active
 *  0b1..Inactive
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT29(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT29_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT29_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT30_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT30_SHIFT    (30U)
/*! POR_WDG_STAT30 - POR_WDG Status 30
 *  0b0..Not acknowledged
 *  0b1..Acknowledged
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT30(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT30_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT30_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT31_MASK     (0x80000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT31_SHIFT    (31U)
/*! POR_WDG_STAT31 - POR_WDG Status 31
 *  0b0..Not detected
 *  0b1..Detected
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT31(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT31_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT31_MASK)
/*! @} */

/*! @name DCMROPP2 - Read-Only GPR On PMCPOR Reset 2 */
/*! @{ */

#define DCM_GPR_DCMROPP2_POR_WDG_STAT32_MASK     (0x1U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT32_SHIFT    (0U)
/*! POR_WDG_STAT32 - POR_WDG Status 32
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT32(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT32_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT32_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT35_MASK     (0x8U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT35_SHIFT    (3U)
/*! POR_WDG_STAT35 - POR_WDG Status 35
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT35(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT35_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT35_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT36_MASK     (0x10U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT36_SHIFT    (4U)
/*! POR_WDG_STAT36 - POR_WDG Status 36
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT36(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT36_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT36_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT38_MASK     (0x40U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT38_SHIFT    (6U)
/*! POR_WDG_STAT38 - POR_WDG Status 38
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT38(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT38_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT38_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT39_MASK     (0x80U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT39_SHIFT    (7U)
/*! POR_WDG_STAT39 - POR_WDG Status 39
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT39(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT39_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT39_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT40_MASK     (0x100U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT40_SHIFT    (8U)
/*! POR_WDG_STAT40 - POR_WDG Status 40
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT40(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT40_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT40_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT41_MASK     (0x200U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT41_SHIFT    (9U)
/*! POR_WDG_STAT41 - POR_WDG Status 41
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT41(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT41_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT41_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT44_MASK     (0x1000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT44_SHIFT    (12U)
/*! POR_WDG_STAT44 - POR_WDG Status 44
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT44(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT44_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT44_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT48_MASK     (0x10000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT48_SHIFT    (16U)
/*! POR_WDG_STAT48 - POR_WDG Status 48
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT48(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT48_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT48_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT52_MASK     (0x100000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT52_SHIFT    (20U)
/*! POR_WDG_STAT52 - POR_WDG Status 52
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT52(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT52_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT52_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT61_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT61_SHIFT    (29U)
/*! POR_WDG_STAT61 - POR_WDG Status 61
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT61(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT61_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT61_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT62_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT62_SHIFT    (30U)
/*! POR_WDG_STAT62 - POR_WDG Status 62
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT62(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT62_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT62_MASK)
/*! @} */

/*! @name DCMROPP3 - Read-Only GPR On PMCPOR Reset 3 */
/*! @{ */

#define DCM_GPR_DCMROPP3_POR_WDG_STAT64_MASK     (0x1U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT64_SHIFT    (0U)
/*! POR_WDG_STAT64 - POR_WDG Status 64
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT64(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT64_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT64_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT67_MASK     (0x8U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT67_SHIFT    (3U)
/*! POR_WDG_STAT67 - POR_WDG Status 67
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT67(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT67_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT67_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT68_MASK     (0x10U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT68_SHIFT    (4U)
/*! POR_WDG_STAT68 - POR_WDG Status 68
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT68(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT68_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT68_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT70_MASK     (0x40U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT70_SHIFT    (6U)
/*! POR_WDG_STAT70 - POR_WDG Status 70
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT70(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT70_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT70_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT72_MASK     (0x100U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT72_SHIFT    (8U)
/*! POR_WDG_STAT72 - POR_WDG Status 72
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT72(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT72_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT72_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT73_MASK     (0x200U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT73_SHIFT    (9U)
/*! POR_WDG_STAT73 - POR_WDG Status 73
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT73(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT73_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT73_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT74_MASK     (0x400U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT74_SHIFT    (10U)
/*! POR_WDG_STAT74 - POR_WDG Status 74
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT74(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT74_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT74_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT76_MASK     (0x1000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT76_SHIFT    (12U)
/*! POR_WDG_STAT76 - POR_WDG Status 76
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT76(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT76_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT76_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT78_MASK     (0x4000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT78_SHIFT    (14U)
/*! POR_WDG_STAT78 - POR_WDG Status 78
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT78(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT78_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT78_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT79_MASK     (0x8000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT79_SHIFT    (15U)
/*! POR_WDG_STAT79 - POR_WDG Status 79
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT79(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT79_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT79_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT80_MASK     (0x10000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT80_SHIFT    (16U)
/*! POR_WDG_STAT80 - POR_WDG Status 80
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT80(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT80_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT80_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT81_MASK     (0x20000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT81_SHIFT    (17U)
/*! POR_WDG_STAT81 - POR_WDG Status 81
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT81(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT81_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT81_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT82_MASK     (0x40000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT82_SHIFT    (18U)
/*! POR_WDG_STAT82 - POR_WDG Status 82
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT82(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT82_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT82_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT93_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT93_SHIFT    (29U)
/*! POR_WDG_STAT93 - POR_WDG Status 93
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT93(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT93_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT93_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT94_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT94_SHIFT    (30U)
/*! POR_WDG_STAT94 - POR_WDG Status 94
 *  0b0..0
 *  0b1..1
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT94(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT94_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT94_MASK)
/*! @} */

/*! @name DCMROPP4 - Read-Only GPR On PMCPOR Reset 4 */
/*! @{ */

#define DCM_GPR_DCMROPP4_POR_WDG_STAT96_MASK     (0x1U)
#define DCM_GPR_DCMROPP4_POR_WDG_STAT96_SHIFT    (0U)
/*! POR_WDG_STAT96 - POR_WDG Status 96
 *  0b0..Inactive
 *  0b1..Active
 */
#define DCM_GPR_DCMROPP4_POR_WDG_STAT96(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP4_POR_WDG_STAT96_SHIFT)) & DCM_GPR_DCMROPP4_POR_WDG_STAT96_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DCM_GPR_Register_Masks */


/*!
 * @}
 */ /* end of group DCM_GPR_Peripheral_Access_Layer */


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


#endif  /* PERI_DCM_GPR_H_ */

