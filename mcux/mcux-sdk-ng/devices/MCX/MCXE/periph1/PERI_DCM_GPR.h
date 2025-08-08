/*
** ###################################################################
**     Processor:           MCXE31BMPB
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

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
  __IO uint32_t DCMROD1;                           /**< Read Only GPR On Destructive Reset Register, offset: 0x200 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DCMROD3;                           /**< Read Only GPR On Destructive Reset Register, offset: 0x208 */
  __IO uint32_t DCMROD4;                           /**< Read Only GPR On Destructive Reset Register, offset: 0x20C */
  __IO uint32_t DCMROD5;                           /**< Read Only GPR On Destructive Reset Register, offset: 0x210 */
       uint8_t RESERVED_2[236];
  __IO uint32_t DCMROF1;                           /**< Read Only GPR On Functional Reset Register, offset: 0x300 */
  __IO uint32_t DCMROF2;                           /**< Read Only GPR On Functional Reset Register, offset: 0x304 */
  __IO uint32_t DCMROF3;                           /**< Read Only GPR On Functional Reset Register, offset: 0x308 */
  __IO uint32_t DCMROF4;                           /**< Read Only GPR On Functional Reset Register, offset: 0x30C */
  __IO uint32_t DCMROF5;                           /**< Read Only GPR On Functional Reset Register, offset: 0x310 */
  __IO uint32_t DCMROF6;                           /**< Read Only GPR On Functional Reset Register, offset: 0x314 */
  __IO uint32_t DCMROF7;                           /**< Read Only GPR On Functional Reset Register, offset: 0x318 */
  __IO uint32_t DCMROF8;                           /**< Read Only GPR On Functional Reset Register, offset: 0x31C */
  __IO uint32_t DCMROF9;                           /**< Read Only GPR On Functional Reset Register, offset: 0x320 */
  __IO uint32_t DCMROF10;                          /**< Read Only GPR On Functional Reset Register, offset: 0x324 */
  __IO uint32_t DCMROF11;                          /**< Read Only GPR On Functional Reset Register, offset: 0x328 */
  __IO uint32_t DCMROF12;                          /**< Read Only GPR On Functional Reset Register, offset: 0x32C */
  __IO uint32_t DCMROF13;                          /**< Read Only GPR On Functional Reset Register, offset: 0x330 */
  __IO uint32_t DCMROF14;                          /**< Read Only GPR On Functional Reset Register, offset: 0x334 */
  __IO uint32_t DCMROF15;                          /**< Read Only GPR On Functional Reset Register, offset: 0x338 */
  __IO uint32_t DCMROF16;                          /**< Read Only GPR On Functional Reset Register, offset: 0x33C */
  __IO uint32_t DCMROF17;                          /**< Read Only GPR On Functional Reset Register, offset: 0x340 */
       uint8_t RESERVED_3[4];
  __I  uint32_t DCMROF19;                          /**< Read Only GPR On Functional Reset Register, offset: 0x348 */
  __I  uint32_t DCMROF20;                          /**< Read Only GPR On Functional Reset Register, offset: 0x34C */
  __I  uint32_t DCMROF21;                          /**< Read Only GPR On Functional Reset Register, offset: 0x350 */
       uint8_t RESERVED_4[172];
  __IO uint32_t DCMRWP1;                           /**< Read Write GPR On Power On Reset Register, offset: 0x400 */
       uint8_t RESERVED_5[4];
  __IO uint32_t DCMRWP3;                           /**< Read Write GPR On Power On Reset Register, offset: 0x408 */
       uint8_t RESERVED_6[248];
  __IO uint32_t DCMRWD2;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x504 */
  __IO uint32_t DCMRWD3;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x508 */
  __IO uint32_t DCMRWD4;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x50C */
  __IO uint32_t DCMRWD5;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x510 */
  __IO uint32_t DCMRWD6;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x514 */
       uint32_t DCMRWD7;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x518 */
       uint32_t DCMRWD8;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x51C */
       uint32_t DCMRWD9;                           /**< Read Write GPR On Destructive Reset Register, offset: 0x520 */
       uint8_t RESERVED_7[220];
  __IO uint32_t DCMRWF1;                           /**< Read Write GPR On Functional Reset Register, offset: 0x600 */
  __IO uint32_t DCMRWF2;                           /**< Read Write GPR On Functional Reset Register, offset: 0x604 */
       uint8_t RESERVED_8[4];
  __IO uint32_t DCMRWF4;                           /**< Read Write GPR On Functional Reset Register, offset: 0x60C */
  __IO uint32_t DCMRWF5;                           /**< Read Write GPR On Functional Reset Register, offset: 0x610 */
       uint8_t RESERVED_9[236];
  __IO uint32_t DCMROPP1;                          /**< Read Only GPR On PMCPOR Reset, offset: 0x700 */
  __IO uint32_t DCMROPP2;                          /**< Read Only GPR On PMCPOR Reset, offset: 0x704 */
  __IO uint32_t DCMROPP3;                          /**< Read Only GPR On PMCPOR Reset, offset: 0x708 */
  __IO uint32_t DCMROPP4;                          /**< Read Only GPR On PMCPOR Reset, offset: 0x70C */
} DCM_GPR_Type;

/* ----------------------------------------------------------------------------
   -- DCM_GPR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DCM_GPR_Register_Masks DCM_GPR Register Masks
 * @{
 */

/*! @name DCMROD1 - Read Only GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMROD1_PCU_ISO_STATUS_MASK      (0x1U)
#define DCM_GPR_DCMROD1_PCU_ISO_STATUS_SHIFT     (0U)
/*! PCU_ISO_STATUS - PCU Input Isolation status on previous standby entry
 *  0b0..Input isolation did not get enabled in the previous standby entry.
 *  0b1..Input isolation enabled in the previous standby entry.
 */
#define DCM_GPR_DCMROD1_PCU_ISO_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD1_PCU_ISO_STATUS_SHIFT)) & DCM_GPR_DCMROD1_PCU_ISO_STATUS_MASK)

#define DCM_GPR_DCMROD1_HSE_DCF_VIO_MASK         (0x2U)
#define DCM_GPR_DCMROD1_HSE_DCF_VIO_SHIFT        (1U)
/*! HSE_DCF_VIO - DCF violation from HSE
 *  0b0..No violation from HSE DCF records while decoding.
 *  0b1..Violation from HSE DCF records while decoding.
 */
#define DCM_GPR_DCMROD1_HSE_DCF_VIO(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD1_HSE_DCF_VIO_SHIFT)) & DCM_GPR_DCMROD1_HSE_DCF_VIO_MASK)

#define DCM_GPR_DCMROD1_KEY_RESP_READY_MASK      (0x4U)
#define DCM_GPR_DCMROD1_KEY_RESP_READY_SHIFT     (2U)
/*! KEY_RESP_READY - Key Response Ready
 *  0b0..Key response is not ready.
 *  0b1..Key response is ready.
 */
#define DCM_GPR_DCMROD1_KEY_RESP_READY(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD1_KEY_RESP_READY_SHIFT)) & DCM_GPR_DCMROD1_KEY_RESP_READY_MASK)
/*! @} */

/*! @name DCMROD3 - Read Only GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMROD3_CM7_0_LOCKUP_MASK        (0x1U)
#define DCM_GPR_DCMROD3_CM7_0_LOCKUP_SHIFT       (0U)
/*! CM7_0_LOCKUP - CM7_0 Core Lockup Status. Read this bit to identify the reason of fault in case of FCCU NCF 0.
 *  0b0..CM7_0 core not in lockup state.
 *  0b1..CM7_0 core in lockup state.
 */
#define DCM_GPR_DCMROD3_CM7_0_LOCKUP(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_LOCKUP_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_LOCKUP_MASK)

#define DCM_GPR_DCMROD3_HSE_LOCKUP_MASK          (0x4U)
#define DCM_GPR_DCMROD3_HSE_LOCKUP_SHIFT         (2U)
/*! HSE_LOCKUP - HSE Core Lockup Status. Read this bit to identify the reason of fault in case of FCCU NCF 0.
 *  0b0..HSE core not in lockup state.
 *  0b1..HSE core in lockup state.
 */
#define DCM_GPR_DCMROD3_HSE_LOCKUP(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_HSE_LOCKUP_SHIFT)) & DCM_GPR_DCMROD3_HSE_LOCKUP_MASK)

#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM_MASK      (0x20U)
#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM_SHIFT     (5U)
/*! TCM_GSKT_ALARM - TCM IAHB Gasket Monitor Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm reported from TCM IAHB gasket.
 *  0b1..Monitor alarm reported from TCM IAHB gasket.
 */
#define DCM_GPR_DCMROD3_TCM_GSKT_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_TCM_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_TCM_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_DMA_SYS_GSKT_ALARM_MASK  (0x40U)
#define DCM_GPR_DCMROD3_DMA_SYS_GSKT_ALARM_SHIFT (6U)
/*! DMA_SYS_GSKT_ALARM
 *  0b0..No safety alarm reported from DMA-system AXBS IAHB gasket.
 *  0b1..Safety alarm indicated by DMA-system AXBS IAHB gasket.
 */
#define DCM_GPR_DCMROD3_DMA_SYS_GSKT_ALARM(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_DMA_SYS_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_DMA_SYS_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_DMA_PERIPH_GSKT_ALARM_MASK (0x80U)
#define DCM_GPR_DCMROD3_DMA_PERIPH_GSKT_ALARM_SHIFT (7U)
/*! DMA_PERIPH_GSKT_ALARM
 *  0b0..No safety alarm reported from DMA-periph AXBS IAHB gasket.
 *  0b1..Safety alarm indicated by DMA-periph AXBS IAHB gasket.
 */
#define DCM_GPR_DCMROD3_DMA_PERIPH_GSKT_ALARM(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_DMA_PERIPH_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_DMA_PERIPH_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM_MASK      (0x100U)
#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM_SHIFT     (8U)
/*! SYS_AXBS_ALARM - System AXBS Safety Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No safety alarm indicated by system AXBS.
 *  0b1..Safety alarm indicated by system AXBS.
 */
#define DCM_GPR_DCMROD3_SYS_AXBS_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_SYS_AXBS_ALARM_SHIFT)) & DCM_GPR_DCMROD3_SYS_AXBS_ALARM_MASK)

#define DCM_GPR_DCMROD3_DMA_AXBS_ALARM_MASK      (0x200U)
#define DCM_GPR_DCMROD3_DMA_AXBS_ALARM_SHIFT     (9U)
/*! DMA_AXBS_ALARM - DMA AXBS_Lite Safety Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No safety alarm indicated by DMA AXBS_Lite.
 *  0b1..Safety alarm indicated by DMA AXBS_Lite.
 */
#define DCM_GPR_DCMROD3_DMA_AXBS_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_DMA_AXBS_ALARM_SHIFT)) & DCM_GPR_DCMROD3_DMA_AXBS_ALARM_MASK)

#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM_MASK      (0x800U)
#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM_SHIFT     (11U)
/*! HSE_GSKT_ALARM - HSE IAHB Gasket Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by HSE IAHB gasket.
 *  0b1..Alarm indicated by HSE IAHB gasket.
 */
#define DCM_GPR_DCMROD3_HSE_GSKT_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_HSE_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_HSE_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_QSPI_GSKT_ALARM_MASK     (0x1000U)
#define DCM_GPR_DCMROD3_QSPI_GSKT_ALARM_SHIFT    (12U)
/*! QSPI_GSKT_ALARM - QSPI IAHB Gasket Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by QSPI IAHB gasket.
 *  0b1..Alarm indicated by QSPI IAHB gasket.
 */
#define DCM_GPR_DCMROD3_QSPI_GSKT_ALARM(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_QSPI_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_QSPI_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_MASK    (0x2000U)
#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_SHIFT   (13U)
/*! AIPS1_GSKT_ALARM - AIPS1 IAHB Gasket Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by AIPS1 IAHB gasket.
 *  0b1..Alarm indicated by AIPS1 IAHB gasket.
 */
#define DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_AIPS1_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_AIPS2_GSKT_ALARM_MASK    (0x4000U)
#define DCM_GPR_DCMROD3_AIPS2_GSKT_ALARM_SHIFT   (14U)
/*! AIPS2_GSKT_ALARM - AIPS2 IAHB Gasket Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by AIPS2 IAHB gasket.
 *  0b1..Alarm indicated by AIPS2 IAHB gasket.
 */
#define DCM_GPR_DCMROD3_AIPS2_GSKT_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_AIPS2_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_AIPS2_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_ADDR_EDC_ERR_MASK        (0x8000U)
#define DCM_GPR_DCMROD3_ADDR_EDC_ERR_SHIFT       (15U)
/*! ADDR_EDC_ERR
 *  0b0..No integrity error on address.
 *  0b1..Address integrity error.
 */
#define DCM_GPR_DCMROD3_ADDR_EDC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_ADDR_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD3_ADDR_EDC_ERR_MASK)

#define DCM_GPR_DCMROD3_DATA_EDC_ERR_MASK        (0x10000U)
#define DCM_GPR_DCMROD3_DATA_EDC_ERR_SHIFT       (16U)
/*! DATA_EDC_ERR
 *  0b0..No integrity error on data.
 *  0b1..Data integrity error.
 */
#define DCM_GPR_DCMROD3_DATA_EDC_ERR(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_DATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD3_DATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD3_TCM_AXBS_ALARM_MASK      (0x20000U)
#define DCM_GPR_DCMROD3_TCM_AXBS_ALARM_SHIFT     (17U)
/*! TCM_AXBS_ALARM - TCM AHB Splitter Safety Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No safety alarm indicated by TCM AHB splitter.
 *  0b1..Safety alarm indicated by TCM AHB splitter.
 */
#define DCM_GPR_DCMROD3_TCM_AXBS_ALARM(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_TCM_AXBS_ALARM_SHIFT)) & DCM_GPR_DCMROD3_TCM_AXBS_ALARM_MASK)

#define DCM_GPR_DCMROD3_EMAC_GSKT_ALARM_MASK     (0x40000U)
#define DCM_GPR_DCMROD3_EMAC_GSKT_ALARM_SHIFT    (18U)
/*! EMAC_GSKT_ALARM - EMAC IAHB Gasket Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No alarm indicated by EMAC IAHB gasket.
 *  0b1..Alarm indicated by EMAC IAHB gasket.
 */
#define DCM_GPR_DCMROD3_EMAC_GSKT_ALARM(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_EMAC_GSKT_ALARM_SHIFT)) & DCM_GPR_DCMROD3_EMAC_GSKT_ALARM_MASK)

#define DCM_GPR_DCMROD3_PERIPH_AXBS_ALARM_MASK   (0x80000U)
#define DCM_GPR_DCMROD3_PERIPH_AXBS_ALARM_SHIFT  (19U)
/*! PERIPH_AXBS_ALARM - PERIPH AXBS_Lite Safety Alarm Status. Read this bit to identify the reason of fault in case of FCCU NCF 1.
 *  0b0..No safety alarm indicated by Periph AXBS_Lite.
 *  0b1..Safety alarm indicated by Periph AXBS_Lite.
 */
#define DCM_GPR_DCMROD3_PERIPH_AXBS_ALARM(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_PERIPH_AXBS_ALARM_SHIFT)) & DCM_GPR_DCMROD3_PERIPH_AXBS_ALARM_MASK)

#define DCM_GPR_DCMROD3_LC_ERR_MASK              (0x400000U)
#define DCM_GPR_DCMROD3_LC_ERR_SHIFT             (22U)
/*! LC_ERR - Error in Lifecycle Scanning. Read this bit to identify the reason of fault in case of FCCU NCF 3.
 *  0b0..No error while lifecycle scanning.
 *  0b1..Error while lifecycle scanning.
 */
#define DCM_GPR_DCMROD3_LC_ERR(x)                (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_LC_ERR_SHIFT)) & DCM_GPR_DCMROD3_LC_ERR_MASK)

#define DCM_GPR_DCMROD3_PRAM1_ECC_ERR_MASK       (0x1000000U)
#define DCM_GPR_DCMROD3_PRAM1_ECC_ERR_SHIFT      (24U)
/*! PRAM1_ECC_ERR
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMROD3_PRAM1_ECC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_PRAM1_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_PRAM1_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR_MASK       (0x2000000U)
#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR_SHIFT      (25U)
/*! PRAM0_ECC_ERR
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMROD3_PRAM0_ECC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_PRAM0_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_PRAM0_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_MASK (0x4000000U)
#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_SHIFT (26U)
/*! CM7_0_DCDATA_ECC_ERR
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_DCDATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_MASK (0x10000000U)
#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_SHIFT (28U)
/*! CM7_0_DCTAG_ECC_ERR - Multi bit ECC error from CM7_0 DCache tag memory. Read this bit to identify the reason of fault in case of FCCU NCF 2.
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_DCTAG_ECC_ERR_MASK)

#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_MASK (0x40000000U)
#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_SHIFT (30U)
/*! CM7_0_ICDATA_ECC_ERR
 *  0b0..CM7_1 core not in lockup state.
 *  0b1..CM7_1 core in lockup state.
 */
#define DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD3_CM7_0_ICDATA_ECC_ERR_MASK)
/*! @} */

/*! @name DCMROD4 - Read Only GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_MASK (0x1U)
#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_SHIFT (0U)
/*! CM7_0_ICTAG_ECC_ERR
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_ICTAG_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_MASK  (0x4U)
#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_SHIFT (2U)
/*! CM7_0_ITCM_ECC_ERR
 *  0b0..No uncorrectable ECC error detected.
 *  0b1..Uncorrectable ECC error detected.
 */
#define DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_ITCM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_MASK (0x8U)
#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_SHIFT (3U)
/*! CM7_0_DTCM0_ECC_ERR
 *  0b0..No uncorrectable ECC error detected.
 *  0b1..Uncorrectable ECC error detected.
 */
#define DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_DTCM0_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_MASK (0x10U)
#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_SHIFT (4U)
/*! CM7_0_DTCM1_ECC_ERR
 *  0b0..No uncorrectable ECC error detected.
 *  0b1..Uncorrectable ECC error detected.
 */
#define DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_CM7_0_DTCM1_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_MASK (0x100U)
#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_SHIFT (8U)
/*! DMA_TCD_RAM_ECC_ERR
 *  0b0..No uncorrectable ECC error detected.
 *  0b1..Uncorrectable ECC error detected.
 */
#define DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_DMA_TCD_RAM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_MASK    (0x200U)
#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_SHIFT   (9U)
/*! PRAM0_FCCU_ALARM
 *  0b0..No safety alarm indicated by PRAM0.
 *  0b1..Safety alarm indicated by PRAM0.
 */
#define DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_SHIFT)) & DCM_GPR_DCMROD4_PRAM0_FCCU_ALARM_MASK)

#define DCM_GPR_DCMROD4_PRAM1_FCCU_ALARM_MASK    (0x400U)
#define DCM_GPR_DCMROD4_PRAM1_FCCU_ALARM_SHIFT   (10U)
/*! PRAM1_FCCU_ALARM
 *  0b0..No safety alarm indicated by PRAM1.
 *  0b1..Safety alarm indicated by PRAM1.
 */
#define DCM_GPR_DCMROD4_PRAM1_FCCU_ALARM(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PRAM1_FCCU_ALARM_SHIFT)) & DCM_GPR_DCMROD4_PRAM1_FCCU_ALARM_MASK)

#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_MASK     (0x800U)
#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_SHIFT    (11U)
/*! HSE_RAM_ECC_ERR - HSE RAM Uncorrectable ECC Status. Read this bit to identify the reason of fault in case of FCCU NCF 2.
 *  0b0..No uncorrectable ECC reported by HSE RAM.
 *  0b1..Uncorrectable ECC reported by HSE RAM.
 */
#define DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_HSE_RAM_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_MASK    (0x1000U)
#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_SHIFT   (12U)
/*! PF0_CODE_ECC_ERR - Flash0 Code ECC Uncorrectable Error
 *  0b0..No uncorrectable error reported in flash controller port 0 code memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 0 code memory by FMU.
 */
#define DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF0_CODE_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_MASK    (0x2000U)
#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_SHIFT   (13U)
/*! PF0_DATA_ECC_ERR - Flash0 Data ECC Uncorrectable Error
 *  0b0..No uncorrectable error reported in flash controller port 0 data memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 0 data memory by FMU.
 */
#define DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF0_DATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_MASK    (0x4000U)
#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_SHIFT   (14U)
/*! PF1_CODE_ECC_ERR - Flash1 Code ECC Uncorrectable Error
 *  0b0..No uncorrectable error reported in flash controller port 1 code memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 1 code memory by FMU.
 */
#define DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF1_CODE_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_MASK    (0x8000U)
#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_SHIFT   (15U)
/*! PF1_DATA_ECC_ERR - Flash1 Data ECC Uncorrectable Error
 *  0b0..No uncorrectable error reported in flash controller port 1 data memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 1 data memory by FMU.
 */
#define DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_SHIFT)) & DCM_GPR_DCMROD4_PF1_DATA_ECC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_EDC_ERR_MASK       (0x40000U)
#define DCM_GPR_DCMROD4_FLASH_EDC_ERR_SHIFT      (18U)
/*! FLASH_EDC_ERR
 *  0b0..No EDC after ECC error reported in flash.
 *  0b1..EDC after ECC error reported in flash.
 */
#define DCM_GPR_DCMROD4_FLASH_EDC_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_EDC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_MASK  (0x80000U)
#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_SHIFT (19U)
/*! FLASH_ADDR_ENC_ERR - Flash Address Encode Error
 *  0b0..No address encode error in flash.
 *  0b1..Address enocde error in flash.
 */
#define DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_ADDR_ENC_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_REF_ERR_MASK       (0x100000U)
#define DCM_GPR_DCMROD4_FLASH_REF_ERR_SHIFT      (20U)
/*! FLASH_REF_ERR
 *  0b0..No reference current loss or read voltage error while previous reads(s).
 *  0b1..Reference current loss or read voltage error while previous read(s).
 */
#define DCM_GPR_DCMROD4_FLASH_REF_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_REF_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_REF_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_RST_ERR_MASK       (0x200000U)
#define DCM_GPR_DCMROD4_FLASH_RST_ERR_SHIFT      (21U)
/*! FLASH_RST_ERR - Flash Reset Error Status
 *  0b0..No flash reset error indicated.
 *  0b1..Flash reset error indicated.
 */
#define DCM_GPR_DCMROD4_FLASH_RST_ERR(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_RST_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_RST_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR_MASK      (0x400000U)
#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR_SHIFT     (22U)
/*! FLASH_SCAN_ERR
 *  0b0..No error while DCM flash scanning.
 *  0b1..Error while DCM flash scanning.
 */
#define DCM_GPR_DCMROD4_FLASH_SCAN_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_SCAN_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_SCAN_ERR_MASK)

#define DCM_GPR_DCMROD4_FLASH_ACCESS_ERR_MASK    (0x1000000U)
#define DCM_GPR_DCMROD4_FLASH_ACCESS_ERR_SHIFT   (24U)
/*! FLASH_ACCESS_ERR - Transaction Monitor Mismatch Error From Flash Controller
 *  0b0..No transaction monitor mismatch error from flash controller.
 *  0b1..Transaction monitor mismatch error from flash controller.
 */
#define DCM_GPR_DCMROD4_FLASH_ACCESS_ERR(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_FLASH_ACCESS_ERR_SHIFT)) & DCM_GPR_DCMROD4_FLASH_ACCESS_ERR_MASK)

#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_MASK      (0x4000000U)
#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_SHIFT     (26U)
/*! VDD1P1_GNG_ERR
 *  0b0..Go indication referring to the supply being clean.
 *  0b1..No-go indication referring to the supply being unclean and a fault in double bond connection or its routing within the chip.
 */
#define DCM_GPR_DCMROD4_VDD1P1_GNG_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_SHIFT)) & DCM_GPR_DCMROD4_VDD1P1_GNG_ERR_MASK)

#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_MASK      (0x8000000U)
#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_SHIFT     (27U)
/*! VDD2P5_GNG_ERR
 *  0b0..Go indication referring to the supply being clean.
 *  0b1..No-go indication referring to the supply being unclean and a fault in double bond connection or its routing within the chip.
 */
#define DCM_GPR_DCMROD4_VDD2P5_GNG_ERR(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_SHIFT)) & DCM_GPR_DCMROD4_VDD2P5_GNG_ERR_MASK)

#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_MASK (0x20000000U)
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_SHIFT (29U)
/*! TEST_ACTIVATION_0_ERR - Accidental Partial Test Activation. Read this bit to identify the reason of fault in case of FCCU NCF 5.
 *  0b0..No partial test activated accidentally.
 *  0b1..Partial test activated accidentally.
 */
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_SHIFT)) & DCM_GPR_DCMROD4_TEST_ACTIVATION_0_ERR_MASK)

#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_MASK (0x40000000U)
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_SHIFT (30U)
/*! TEST_ACTIVATION_1_ERR - Accidental Partial Test Activation. Read this bit to identify the reason of fault in case of FCCU NCF 5.
 *  0b0..No partial test activated accidentally.
 *  0b1..Partial test activated accidentally.
 */
#define DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_SHIFT)) & DCM_GPR_DCMROD4_TEST_ACTIVATION_1_ERR_MASK)
/*! @} */

/*! @name DCMROD5 - Read Only GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMROD5_INTM_0_ERR_MASK          (0x2U)
#define DCM_GPR_DCMROD5_INTM_0_ERR_SHIFT         (1U)
/*! INTM_0_ERR
 *  0b0..No error reported by interrupt monitor 0.
 *  0b1..Error reported by interrupt monitor 0.
 */
#define DCM_GPR_DCMROD5_INTM_0_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_0_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_0_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_1_ERR_MASK          (0x4U)
#define DCM_GPR_DCMROD5_INTM_1_ERR_SHIFT         (2U)
/*! INTM_1_ERR
 *  0b0..No error reported by interrupt monitor 1.
 *  0b1..Error reported by interrupt monitor 1.
 */
#define DCM_GPR_DCMROD5_INTM_1_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_1_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_1_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_2_ERR_MASK          (0x8U)
#define DCM_GPR_DCMROD5_INTM_2_ERR_SHIFT         (3U)
/*! INTM_2_ERR
 *  0b0..No error reported by interrupt monitor 2.
 *  0b1..Error reported by interrupt monitor 2.
 */
#define DCM_GPR_DCMROD5_INTM_2_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_2_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_2_ERR_MASK)

#define DCM_GPR_DCMROD5_INTM_3_ERR_MASK          (0x10U)
#define DCM_GPR_DCMROD5_INTM_3_ERR_SHIFT         (4U)
/*! INTM_3_ERR
 *  0b0..No error reported by interrupt monitor 3.
 *  0b1..Error reported by interrupt monitor 3.
 */
#define DCM_GPR_DCMROD5_INTM_3_ERR(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_INTM_3_ERR_SHIFT)) & DCM_GPR_DCMROD5_INTM_3_ERR_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_0_MASK            (0x20U)
#define DCM_GPR_DCMROD5_SW_NCF_0_SHIFT           (5U)
/*! SW_NCF_0 - Software NCF0 Status
 *  0b0..Software NCF0, DCMRWF1[FCCU_SW_NCF0] not enabled by software.
 *  0b1..Software NCF0, DCMRWF1[FCCU_SW_NCF0] enabled by software.
 */
#define DCM_GPR_DCMROD5_SW_NCF_0(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_0_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_0_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_1_MASK            (0x40U)
#define DCM_GPR_DCMROD5_SW_NCF_1_SHIFT           (6U)
/*! SW_NCF_1 - Software NCF1 Status
 *  0b0..Software NCF1, DCMRWF1[FCCU_SW_NCF1] not enabled by software.
 *  0b1..Software NCF1, DCMRWF1[FCCU_SW_NCF1] enabled by software.
 */
#define DCM_GPR_DCMROD5_SW_NCF_1(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_1_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_1_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_2_MASK            (0x80U)
#define DCM_GPR_DCMROD5_SW_NCF_2_SHIFT           (7U)
/*! SW_NCF_2 - Software NCF2 Status
 *  0b0..Software NCF2, DCMRWF1[FCCU_SW_NCF2] not enabled by software.
 *  0b1..Software NCF2, DCMRWF1[FCCU_SW_NCF2] enabled by software.
 */
#define DCM_GPR_DCMROD5_SW_NCF_2(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_2_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_2_MASK)

#define DCM_GPR_DCMROD5_SW_NCF_3_MASK            (0x100U)
#define DCM_GPR_DCMROD5_SW_NCF_3_SHIFT           (8U)
/*! SW_NCF_3 - Software NCF3 Status
 *  0b0..Software NCF3, DCMRWF1[FCCU_SW_NCF3] not enabled by software.
 *  0b1..Software NCF3, DCMRWF1[FCCU_SW_NCF3] enabled by software.
 */
#define DCM_GPR_DCMROD5_SW_NCF_3(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_SW_NCF_3_SHIFT)) & DCM_GPR_DCMROD5_SW_NCF_3_MASK)

#define DCM_GPR_DCMROD5_STCU_NCF_MASK            (0x200U)
#define DCM_GPR_DCMROD5_STCU_NCF_SHIFT           (9U)
/*! STCU_NCF
 *  0b0..STCU non-critical fault not reported.
 *  0b1..STCU non-critical fault reported.
 */
#define DCM_GPR_DCMROD5_STCU_NCF(x)              (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_STCU_NCF_SHIFT)) & DCM_GPR_DCMROD5_STCU_NCF_MASK)

#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_MASK (0x400U)
#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_SHIFT (10U)
/*! MBIST_ACTIVATION_ERR
 *  0b0..No accidental backdoor enabled on memories.
 *  0b1..Accidental backdoor enabled on memories.
 */
#define DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_SHIFT)) & DCM_GPR_DCMROD5_MBIST_ACTIVATION_ERR_MASK)

#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF_MASK   (0x800U)
#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF_SHIFT  (11U)
/*! STCU_BIST_USER_CF
 *  0b0..No accidental L/M BIST enabled.
 *  0b1..Accidental L/M BIST enabled.
 */
#define DCM_GPR_DCMROD5_STCU_BIST_USER_CF(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_STCU_BIST_USER_CF_SHIFT)) & DCM_GPR_DCMROD5_STCU_BIST_USER_CF_MASK)

#define DCM_GPR_DCMROD5_MTR_BUS_ERR_MASK         (0x1000U)
#define DCM_GPR_DCMROD5_MTR_BUS_ERR_SHIFT        (12U)
/*! MTR_BUS_ERR
 *  0b0..No transfer error indicated from MTR.
 *  0b1..Transfer error indicated from MTR.
 */
#define DCM_GPR_DCMROD5_MTR_BUS_ERR(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_MTR_BUS_ERR_SHIFT)) & DCM_GPR_DCMROD5_MTR_BUS_ERR_MASK)

#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_MASK (0x2000U)
#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_SHIFT (13U)
/*! DEBUG_ACTIVATION_ERR
 *  0b0..Unintended debug not activated.
 *  0b1..Unintended debug activated.
 */
#define DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_SHIFT)) & DCM_GPR_DCMROD5_DEBUG_ACTIVATION_ERR_MASK)

#define DCM_GPR_DCMROD5_TCM_RDATA_EDC_ERR_MASK   (0x4000U)
#define DCM_GPR_DCMROD5_TCM_RDATA_EDC_ERR_SHIFT  (14U)
/*! TCM_RDATA_EDC_ERR
 *  0b0..No integrity error reported on TCM read data.
 *  0b1..Integrity error reported on TCM read data.
 */
#define DCM_GPR_DCMROD5_TCM_RDATA_EDC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_TCM_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_TCM_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_EMAC_RDATA_EDC_ERR_MASK  (0x8000U)
#define DCM_GPR_DCMROD5_EMAC_RDATA_EDC_ERR_SHIFT (15U)
/*! EMAC_RDATA_EDC_ERR
 *  0b0..No integrity error reported on EMAC read data.
 *  0b1..Integrity error reported on EMAC read data.
 */
#define DCM_GPR_DCMROD5_EMAC_RDATA_EDC_ERR(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_EMAC_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_EMAC_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_MASK   (0x20000U)
#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_SHIFT  (17U)
/*! DMA_RDATA_EDC_ERR
 *  0b0..No integrity error reported on eDMA read data.
 *  0b1..Integrity error reported on eDMA read data.
 */
#define DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_DMA_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_MASK (0x100000U)
#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_SHIFT (20U)
/*! CM7_0_AHBP_RDATA_EDC_ERR
 *  0b0..No integrity error reported on CM7_0 peripheral read data.
 *  0b1..Integrity error reported on CM7_0 peripheral read data.
 */
#define DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_CM7_0_AHBP_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_MASK (0x200000U)
#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_SHIFT (21U)
/*! CM7_0_AHBM_RDATA_EDC_ERR
 *  0b0..No integrity error reported on CM7_0 main read data.
 *  0b1..Integrity error reported on CM7_0 main read data.
 */
#define DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_CM7_0_AHBM_RDATA_EDC_ERR_MASK)

#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_MASK   (0x400000U)
#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_SHIFT  (22U)
/*! HSE_RDATA_EDC_ERR
 *  0b0..No integrity error reported on HSE read data.
 *  0b1..Integrity error reported on HSE read data.
 */
#define DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_SHIFT)) & DCM_GPR_DCMROD5_HSE_RDATA_EDC_ERR_MASK)
/*! @} */

/*! @name DCMROF1 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_0_MASK     (0x1U)
#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_0_SHIFT    (0U)
/*! EMAC_MDC_CHID_0 - EMAC DMA Channel ID0 Status
 *  0b0..Channel ID0 is not the current transfer channel ID.
 *  0b1..Channel ID0 is the current transfer channel ID.
 */
#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_0(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF1_EMAC_MDC_CHID_0_SHIFT)) & DCM_GPR_DCMROF1_EMAC_MDC_CHID_0_MASK)

#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_1_MASK     (0x2U)
#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_1_SHIFT    (1U)
/*! EMAC_MDC_CHID_1 - EMAC DMA Channel ID1 Status
 *  0b0..Channel ID1 is not the current transfer channel ID.
 *  0b1..Channel ID1 is the current transfer channel ID.
 */
#define DCM_GPR_DCMROF1_EMAC_MDC_CHID_1(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF1_EMAC_MDC_CHID_1_SHIFT)) & DCM_GPR_DCMROF1_EMAC_MDC_CHID_1_MASK)
/*! @} */

/*! @name DCMROF2 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF2_DCF_SDID0_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF2_DCF_SDID0_SHIFT          (0U)
/*! DCF_SDID0 - Configuration bits of DCF client SDID 0. */
#define DCM_GPR_DCMROF2_DCF_SDID0(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF2_DCF_SDID0_SHIFT)) & DCM_GPR_DCMROF2_DCF_SDID0_MASK)
/*! @} */

/*! @name DCMROF3 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF3_DCF_SDID1_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF3_DCF_SDID1_SHIFT          (0U)
/*! DCF_SDID1 - Configuration bits of DCF client SDID 1. */
#define DCM_GPR_DCMROF3_DCF_SDID1(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF3_DCF_SDID1_SHIFT)) & DCM_GPR_DCMROF3_DCF_SDID1_MASK)
/*! @} */

/*! @name DCMROF4 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF4_DCF_SDID2_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF4_DCF_SDID2_SHIFT          (0U)
/*! DCF_SDID2 - Configuration bits of DCF client SDID 2. */
#define DCM_GPR_DCMROF4_DCF_SDID2(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF4_DCF_SDID2_SHIFT)) & DCM_GPR_DCMROF4_DCF_SDID2_MASK)
/*! @} */

/*! @name DCMROF5 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF5_DCF_SDID3_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF5_DCF_SDID3_SHIFT          (0U)
/*! DCF_SDID3 - Configuration bits of DCF client SDID 3. */
#define DCM_GPR_DCMROF5_DCF_SDID3(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF5_DCF_SDID3_SHIFT)) & DCM_GPR_DCMROF5_DCF_SDID3_MASK)
/*! @} */

/*! @name DCMROF6 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF6_DCF_SDID4_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF6_DCF_SDID4_SHIFT          (0U)
/*! DCF_SDID4 - Configuration bits of DCF client SDID 4. */
#define DCM_GPR_DCMROF6_DCF_SDID4(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF6_DCF_SDID4_SHIFT)) & DCM_GPR_DCMROF6_DCF_SDID4_MASK)
/*! @} */

/*! @name DCMROF7 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF7_DCF_SDID5_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF7_DCF_SDID5_SHIFT          (0U)
/*! DCF_SDID5 - Configuration bits of DCF client SDID 5. */
#define DCM_GPR_DCMROF7_DCF_SDID5(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF7_DCF_SDID5_SHIFT)) & DCM_GPR_DCMROF7_DCF_SDID5_MASK)
/*! @} */

/*! @name DCMROF8 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF8_DCF_SDID6_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF8_DCF_SDID6_SHIFT          (0U)
/*! DCF_SDID6 - Configuration bits of DCF client SDID 6. */
#define DCM_GPR_DCMROF8_DCF_SDID6(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF8_DCF_SDID6_SHIFT)) & DCM_GPR_DCMROF8_DCF_SDID6_MASK)
/*! @} */

/*! @name DCMROF9 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF9_DCF_SDID7_MASK           (0xFFFFFFFFU)
#define DCM_GPR_DCMROF9_DCF_SDID7_SHIFT          (0U)
/*! DCF_SDID7 - Configuration bits of DCF client SDID 7. */
#define DCM_GPR_DCMROF9_DCF_SDID7(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF9_DCF_SDID7_SHIFT)) & DCM_GPR_DCMROF9_DCF_SDID7_MASK)
/*! @} */

/*! @name DCMROF10 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF10_DCF_SDID8_MASK          (0xFFFFFFFFU)
#define DCM_GPR_DCMROF10_DCF_SDID8_SHIFT         (0U)
/*! DCF_SDID8 - Configuration bits of DCF client SDID 8. */
#define DCM_GPR_DCMROF10_DCF_SDID8(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF10_DCF_SDID8_SHIFT)) & DCM_GPR_DCMROF10_DCF_SDID8_MASK)
/*! @} */

/*! @name DCMROF11 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF11_DCF_SDID9_MASK          (0xFFFFFFFFU)
#define DCM_GPR_DCMROF11_DCF_SDID9_SHIFT         (0U)
/*! DCF_SDID9 - Configuration bits of DCF client SDID 9. */
#define DCM_GPR_DCMROF11_DCF_SDID9(x)            (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF11_DCF_SDID9_SHIFT)) & DCM_GPR_DCMROF11_DCF_SDID9_MASK)
/*! @} */

/*! @name DCMROF12 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF12_DCF_SDID10_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF12_DCF_SDID10_SHIFT        (0U)
/*! DCF_SDID10 - Configuration bits of DCF client SDID 10. */
#define DCM_GPR_DCMROF12_DCF_SDID10(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF12_DCF_SDID10_SHIFT)) & DCM_GPR_DCMROF12_DCF_SDID10_MASK)
/*! @} */

/*! @name DCMROF13 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF13_DCF_SDID11_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF13_DCF_SDID11_SHIFT        (0U)
/*! DCF_SDID11 - Configuration bits of DCF client SDID 11. */
#define DCM_GPR_DCMROF13_DCF_SDID11(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF13_DCF_SDID11_SHIFT)) & DCM_GPR_DCMROF13_DCF_SDID11_MASK)
/*! @} */

/*! @name DCMROF14 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF14_DCF_SDID12_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF14_DCF_SDID12_SHIFT        (0U)
/*! DCF_SDID12 - Configuration bits of DCF client SDID 12. */
#define DCM_GPR_DCMROF14_DCF_SDID12(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF14_DCF_SDID12_SHIFT)) & DCM_GPR_DCMROF14_DCF_SDID12_MASK)
/*! @} */

/*! @name DCMROF15 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF15_DCF_SDID13_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF15_DCF_SDID13_SHIFT        (0U)
/*! DCF_SDID13 - Configuration bits of DCF client SDID 13. */
#define DCM_GPR_DCMROF15_DCF_SDID13(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF15_DCF_SDID13_SHIFT)) & DCM_GPR_DCMROF15_DCF_SDID13_MASK)
/*! @} */

/*! @name DCMROF16 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF16_DCF_SDID14_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF16_DCF_SDID14_SHIFT        (0U)
/*! DCF_SDID14 - Configuration bits of DCF client SDID 14. */
#define DCM_GPR_DCMROF16_DCF_SDID14(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF16_DCF_SDID14_SHIFT)) & DCM_GPR_DCMROF16_DCF_SDID14_MASK)
/*! @} */

/*! @name DCMROF17 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF17_DCF_SDID15_MASK         (0xFFFFFFFFU)
#define DCM_GPR_DCMROF17_DCF_SDID15_SHIFT        (0U)
/*! DCF_SDID15 - Configuration bits of DCF client SDID 15. */
#define DCM_GPR_DCMROF17_DCF_SDID15(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF17_DCF_SDID15_SHIFT)) & DCM_GPR_DCMROF17_DCF_SDID15_MASK)
/*! @} */

/*! @name DCMROF19 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF19_DCM_DONE_MASK           (0x40000000U)
#define DCM_GPR_DCMROF19_DCM_DONE_SHIFT          (30U)
/*! DCM_DONE - DCM Done
 *  0b0..Flash scanning by DCM not complete.
 *  0b1..Flash scanning completed by DCM.
 */
#define DCM_GPR_DCMROF19_DCM_DONE(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF19_DCM_DONE_SHIFT)) & DCM_GPR_DCMROF19_DCM_DONE_MASK)

#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_MASK (0x80000000U)
#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_SHIFT (31U)
/*! FCCU_EOUT_DEDICATED - FCCU EOUT Dedicated
 *  0b0..FCCU_EOUT pins on GPIO2 and GPIO3 acts as general purpose pins supporting all functions.
 *  0b1..FCCU_EOUT pins on GPIO2 and GPIO3 acts as dedicated EOUT pins.
 */
#define DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_SHIFT)) & DCM_GPR_DCMROF19_FCCU_EOUT_DEDICATED_MASK)
/*! @} */

/*! @name DCMROF20 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF20_POR_WDG_EN_MASK         (0x1U)
#define DCM_GPR_DCMROF20_POR_WDG_EN_SHIFT        (0U)
/*! POR_WDG_EN
 *  0b0..POR Watchdog Disabled.
 *  0b1..POR Watchdog Enabled (default).
 */
#define DCM_GPR_DCMROF20_POR_WDG_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_POR_WDG_EN_SHIFT)) & DCM_GPR_DCMROF20_POR_WDG_EN_MASK)

#define DCM_GPR_DCMROF20_LMAUTO_DIS_MASK         (0x2U)
#define DCM_GPR_DCMROF20_LMAUTO_DIS_SHIFT        (1U)
/*! LMAUTO_DIS
 *  0b0..Last mile auto crossover feautre is supported for the chip.
 *  0b1..Last mile auto crossover feautre is not supported for the chip.
 */
#define DCM_GPR_DCMROF20_LMAUTO_DIS(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_LMAUTO_DIS_SHIFT)) & DCM_GPR_DCMROF20_LMAUTO_DIS_MASK)

#define DCM_GPR_DCMROF20_DMA_AXBS_IAHB_BYP_MASK  (0x8U)
#define DCM_GPR_DCMROF20_DMA_AXBS_IAHB_BYP_SHIFT (3U)
/*! DMA_AXBS_IAHB_BYP
 *  0b0..Register wall enabled.
 *  0b1..Register wall bypassed.
 */
#define DCM_GPR_DCMROF20_DMA_AXBS_IAHB_BYP(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_DMA_AXBS_IAHB_BYP_SHIFT)) & DCM_GPR_DCMROF20_DMA_AXBS_IAHB_BYP_MASK)

#define DCM_GPR_DCMROF20_QSPI_IAHB_BYP_MASK      (0x20U)
#define DCM_GPR_DCMROF20_QSPI_IAHB_BYP_SHIFT     (5U)
/*! QSPI_IAHB_BYP
 *  0b0..Register wall enabled.
 *  0b1..Register wall bypassed.
 */
#define DCM_GPR_DCMROF20_QSPI_IAHB_BYP(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_QSPI_IAHB_BYP_SHIFT)) & DCM_GPR_DCMROF20_QSPI_IAHB_BYP_MASK)

#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP_MASK      (0x40U)
#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP_SHIFT     (6U)
/*! AIPS_IAHB_BYP
 *  0b0..Register wall enabled.
 *  0b1..Register wall bypassed.
 */
#define DCM_GPR_DCMROF20_AIPS_IAHB_BYP(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_AIPS_IAHB_BYP_SHIFT)) & DCM_GPR_DCMROF20_AIPS_IAHB_BYP_MASK)

#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_MASK   (0xFFFC0000U)
#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_SHIFT  (18U)
/*! DCF_DEST_RST_ESC
 *  0b00000000000000..Destructive Reset Escalation disabled.
 *  0b00000000000001..Destructive Reset Escalation enabled.
 */
#define DCM_GPR_DCMROF20_DCF_DEST_RST_ESC(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_SHIFT)) & DCM_GPR_DCMROF20_DCF_DEST_RST_ESC_MASK)
/*! @} */

/*! @name DCMROF21 - Read Only GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_MASK   (0x3FFFFU)
#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_SHIFT  (0U)
/*! DCF_DEST_RST_ESC
 *  0b000000000000000000..Destructive Reset Escalation disabled.
 *  0b000000000000000001..Destructive Reset Escalation enabled.
 */
#define DCM_GPR_DCMROF21_DCF_DEST_RST_ESC(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_SHIFT)) & DCM_GPR_DCMROF21_DCF_DEST_RST_ESC_MASK)

#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_MASK (0x180000U)
#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_SHIFT (19U)
/*! HSE_CLK_MODE_OPTION - HSE Clock Mode Option
 *  0b00..Applicable for clocking option A. Ratio of 1:2 in between HSE IPS interface clock (AIPS_SLOW_CLK) and
 *        HSE module clock (HSE_CLK), HSE_IAHB gasket enabled.
 *  0b01..Applicable for clocking option C, D, E, E2, and F. Ratio of 1:2 in between HSE IPS interface clock
 *        (AIPS_SLOW_CLK) and HSE module clock (HSE_CLK), HSE_IAHB gasket bypass.
 *  0b10..10b and 11b both are applicable for clocking option B in same way. Ratio of 1:4 in between HSE IPS
 *        interface clock (AIPS_SLOW_CLK) and HSE module clock (HSE_CLK), HSE_IAHB gasket enabled.
 *  0b11..10b and 11b both are applicable for clocking option B in same way. Ratio of 1:4 in between HSE IPS
 *        interface clock (AIPS_SLOW_CLK) and HSE module clock (HSE_CLK), HSE_IAHB gasket enabled.
 */
#define DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_SHIFT)) & DCM_GPR_DCMROF21_HSE_CLK_MODE_OPTION_MASK)
/*! @} */

/*! @name DCMRWP1 - Read Write GPR On Power On Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY_MASK      (0x8U)
#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY_SHIFT     (3U)
/*! CLKOUT_STANDBY - Clockout standby expose over functional and destructive reset.
 *  0b0..The CLKOUT_STANDBY function is not available while functional or destructive reset on PTA12.
 *  0b1..The CLKOUT_STANDBY function is available while functional or destructive reset on PTA12.
 */
#define DCM_GPR_DCMRWP1_CLKOUT_STANDBY(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_CLKOUT_STANDBY_SHIFT)) & DCM_GPR_DCMRWP1_CLKOUT_STANDBY_MASK)

#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_MASK   (0x100U)
#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_SHIFT  (8U)
/*! STANBDY_PWDOG_DIS - Disables the standby entry and exit monitoring window of the POR WDOG.
 *  0b0..Enabled
 *  0b1..Disabled
 */
#define DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_SHIFT)) & DCM_GPR_DCMRWP1_STANBDY_PWDOG_DIS_MASK)

#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM_MASK       (0x600U)
#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM_SHIFT      (9U)
/*! POR_WDOG_TRIM - Trims for POR WDG timeout value. */
#define DCM_GPR_DCMRWP1_POR_WDOG_TRIM(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP1_POR_WDOG_TRIM_SHIFT)) & DCM_GPR_DCMRWP1_POR_WDOG_TRIM_MASK)
/*! @} */

/*! @name DCMRWP3 - Read Write GPR On Power On Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_MASK    (0x200U)
#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_SHIFT   (9U)
/*! DEST_RST9_AS_IPI - Configures a destructive reset to interrupt.
 *  0b0..Destructive reset.
 *  0b1..PLL LOL interrupt.
 */
#define DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_SHIFT)) & DCM_GPR_DCMRWP3_DEST_RST9_AS_IPI_MASK)
/*! @} */

/*! @name DCMRWD2 - Read Write GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_MASK (0x80U)
#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_SHIFT (7U)
/*! EOUT_STAT_DUR_STEST - Controls the EOUT state during selftest.
 *  0b0..EOUT state will change to high Z post selftest when device is under reset.
 *  0b1..EOUT state will remain in FAULT state until this bit is cleared.
 */
#define DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_SHIFT)) & DCM_GPR_DCMRWD2_EOUT_STAT_DUR_STEST_MASK)
/*! @} */

/*! @name DCMRWD3 - Read Write GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_MASK     (0x1U)
#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_SHIFT    (0U)
/*! CM7_0_LOCKUP_EN
 *  0b0..CM7_0 core not in lockup state.
 *  0b1..CM7_0 core in lockup state.
 */
#define DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_LOCKUP_EN_MASK)

#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_MASK   (0x20U)
#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_SHIFT  (5U)
/*! TCM_GSKT_ALARM_EN
 *  0b0..No alarm reported from TCM IAHB gasket.
 *  0b1..Monitor alarm reported from TCM IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_TCM_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_DMA_SYS_GSKT_ALARM_EN_MASK (0x40U)
#define DCM_GPR_DCMRWD3_DMA_SYS_GSKT_ALARM_EN_SHIFT (6U)
/*! DMA_SYS_GSKT_ALARM_EN
 *  0b0..No safety alarm reported from DMA-system AXBS IAHB gasket.
 *  0b1..Safety alarm indicated by DMA-system AXBS IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_DMA_SYS_GSKT_ALARM_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_DMA_SYS_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_DMA_SYS_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_DMA_PERIPH_GSKT_ALARM_EN_MASK (0x80U)
#define DCM_GPR_DCMRWD3_DMA_PERIPH_GSKT_ALARM_EN_SHIFT (7U)
/*! DMA_PERIPH_GSKT_ALARM_EN
 *  0b0..No safety alarm reported from DMA-periph AXBS IAHB gasket.
 *  0b1..Safety alarm indicated by DMA-periph AXBS IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_DMA_PERIPH_GSKT_ALARM_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_DMA_PERIPH_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_DMA_PERIPH_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_MASK   (0x100U)
#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_SHIFT  (8U)
/*! SYS_AXBS_ALARM_EN
 *  0b0..No safety alarm indicated by system AXBS.
 *  0b1..Safety alarm indicated by system AXBS.
 */
#define DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_SYS_AXBS_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_DMA_AXBS_ALARM_EN_MASK   (0x200U)
#define DCM_GPR_DCMRWD3_DMA_AXBS_ALARM_EN_SHIFT  (9U)
/*! DMA_AXBS_ALARM_EN
 *  0b0..No safety alarm indicated by DMA AXBS_Lite.
 *  0b1..Safety alarm indicated by DMA AXBS_Lite.
 */
#define DCM_GPR_DCMRWD3_DMA_AXBS_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_DMA_AXBS_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_DMA_AXBS_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_MASK   (0x800U)
#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_SHIFT  (11U)
/*! HSE_GSKT_ALARM_EN
 *  0b0..No alarm indicated by HSE IAHB gasket.
 *  0b1..Alarm indicated by HSE IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_HSE_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_QSPI_GSKT_ALARM_EN_MASK  (0x1000U)
#define DCM_GPR_DCMRWD3_QSPI_GSKT_ALARM_EN_SHIFT (12U)
/*! QSPI_GSKT_ALARM_EN
 *  0b0..No alarm indicated by QSPI IAHB gasket.
 *  0b1..Alarm indicated by QSPI IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_QSPI_GSKT_ALARM_EN(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_QSPI_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_QSPI_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_SHIFT (13U)
/*! AIPS1_GSKT_ALARM_EN
 *  0b0..No alarm indicated by AIPS1 IAHB gasket.
 *  0b1..Alarm indicated by AIPS1 IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_AIPS1_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_AIPS2_GSKT_ALARM_EN_MASK (0x4000U)
#define DCM_GPR_DCMRWD3_AIPS2_GSKT_ALARM_EN_SHIFT (14U)
/*! AIPS2_GSKT_ALARM_EN
 *  0b0..No alarm indicated by AIPS2 IAHB gasket.
 *  0b1..Alarm indicated by AIPS2 IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_AIPS2_GSKT_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_AIPS2_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_AIPS2_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_MASK     (0x8000U)
#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_SHIFT    (15U)
/*! ADDR_EDC_ERR_EN
 *  0b0..No integrity error on address.
 *  0b1..Address integrity error.
 */
#define DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_ADDR_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_MASK     (0x10000U)
#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_SHIFT    (16U)
/*! DATA_EDC_ERR_EN
 *  0b0..No integrity error on data.
 *  0b1..Data integrity error..
 */
#define DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_DATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_TCM_AXBS_ALARM_EN_MASK   (0x20000U)
#define DCM_GPR_DCMRWD3_TCM_AXBS_ALARM_EN_SHIFT  (17U)
/*! TCM_AXBS_ALARM_EN
 *  0b0..No safety alarm indicated by TCM AHB splitter.
 *  0b1..Safety alarm indicated by TCM AHB splitter.
 */
#define DCM_GPR_DCMRWD3_TCM_AXBS_ALARM_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_TCM_AXBS_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_TCM_AXBS_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_EMAC_GSKT_ALARM_EN_MASK  (0x40000U)
#define DCM_GPR_DCMRWD3_EMAC_GSKT_ALARM_EN_SHIFT (18U)
/*! EMAC_GSKT_ALARM_EN
 *  0b0..No alarm indicated by EMAC IAHB gasket.
 *  0b1..Alarm indicated by EMAC IAHB gasket.
 */
#define DCM_GPR_DCMRWD3_EMAC_GSKT_ALARM_EN(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_EMAC_GSKT_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_EMAC_GSKT_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_PERIPH_AXBS_ALARM_EN_MASK (0x80000U)
#define DCM_GPR_DCMRWD3_PERIPH_AXBS_ALARM_EN_SHIFT (19U)
/*! PERIPH_AXBS_ALARM_EN
 *  0b0..No safety alarm indicated by Periph AXBS_Lite.
 *  0b1..Safety alarm indicated by Periph AXBS_Lite.
 */
#define DCM_GPR_DCMRWD3_PERIPH_AXBS_ALARM_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_PERIPH_AXBS_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD3_PERIPH_AXBS_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD3_LC_ERR_EN_MASK           (0x400000U)
#define DCM_GPR_DCMRWD3_LC_ERR_EN_SHIFT          (22U)
/*! LC_ERR_EN
 *  0b0..No error while lifecycle scanning.
 *  0b1..Error while lifecycle scanning.
 */
#define DCM_GPR_DCMRWD3_LC_ERR_EN(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_LC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_LC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_PRAM1_ECC_ERR_EN_MASK    (0x1000000U)
#define DCM_GPR_DCMRWD3_PRAM1_ECC_ERR_EN_SHIFT   (24U)
/*! PRAM1_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMRWD3_PRAM1_ECC_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_PRAM1_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_PRAM1_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_MASK    (0x2000000U)
#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_SHIFT   (25U)
/*! PRAM0_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_PRAM0_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_MASK (0x4000000U)
#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_SHIFT (26U)
/*! CM7_0_DCDATA_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_DCDATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_MASK (0x10000000U)
#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_SHIFT (28U)
/*! CM7_0_DCTAG_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_DCTAG_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_MASK (0x40000000U)
#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_SHIFT (30U)
/*! CM7_0_ICDATA_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error.
 */
#define DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD3_CM7_0_ICDATA_ECC_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD4 - Read Write GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_MASK (0x1U)
#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_SHIFT (0U)
/*! CM7_0_ICTAG_ECC_ERR_EN
 *  0b0..No multi-bit ECC error.
 *  0b1..Multi-bit ECC error
 */
#define DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_ICTAG_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_MASK (0x4U)
#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_SHIFT (2U)
/*! CM7_0_ITCM_ECC_ERR_EN
 *  0b0..Uncorrectable ECC error detection at FCCU not enabled.
 *  0b1..Uncorrectable ECC error detection enabled at FCCU.
 */
#define DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_ITCM_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_MASK (0x8U)
#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_SHIFT (3U)
/*! CM7_0_DTCM0_ECC_ERR_EN
 *  0b0..Uncorrectable ECC error detection at FCCU not enabled.
 *  0b1..Uncorrectable ECC error detection enabled at FCCU.
 */
#define DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_DTCM0_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_MASK (0x10U)
#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_SHIFT (4U)
/*! CM7_0_DTCM1_ECC_ERR_EN
 *  0b0..Uncorrectable ECC error detection at FCCU not enabled.
 *  0b1..Uncorrectable ECC error detection enabled at FCCU.
 */
#define DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_CM7_0_DTCM1_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_MASK (0x100U)
#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_SHIFT (8U)
/*! DMA_TCD_RAM_ECC_ERR_EN
 *  0b0..Uncorrectable ECC error detection at FCCU not enabled.
 *  0b1..Uncorrectable ECC error detection enabled at FCCU.
 */
#define DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_DMA_TCD_RAM_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_MASK (0x200U)
#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_SHIFT (9U)
/*! PRAM0_FCCU_ALARM_EN
 *  0b0..No safety alarm indicated by PRAM0.
 *  0b1..Safety alarm indicated by PRAM0.
 */
#define DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD4_PRAM0_FCCU_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD4_PRAM1_FCCU_ALARM_EN_MASK (0x400U)
#define DCM_GPR_DCMRWD4_PRAM1_FCCU_ALARM_EN_SHIFT (10U)
/*! PRAM1_FCCU_ALARM_EN
 *  0b0..No safety alarm indicated by PRAM1.
 *  0b1..Safety alarm indicated by PRAM1.
 */
#define DCM_GPR_DCMRWD4_PRAM1_FCCU_ALARM_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PRAM1_FCCU_ALARM_EN_SHIFT)) & DCM_GPR_DCMRWD4_PRAM1_FCCU_ALARM_EN_MASK)

#define DCM_GPR_DCMRWD4_HSE_RAM_ECC_ERR_EN_MASK  (0x800U)
#define DCM_GPR_DCMRWD4_HSE_RAM_ECC_ERR_EN_SHIFT (11U)
/*! HSE_RAM_ECC_ERR_EN
 *  0b0..No uncorrectable ECC reported by HSE RAM.
 *  0b1..Uncorrectable ECC reported by HSE RAM
 */
#define DCM_GPR_DCMRWD4_HSE_RAM_ECC_ERR_EN(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_HSE_RAM_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_HSE_RAM_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_MASK (0x1000U)
#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_SHIFT (12U)
/*! PF0_CODE_ECC_ERR_EN
 *  0b0..No uncorrectable error reported in flash controller port 0 code memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 0 code memory by FMU.
 */
#define DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF0_CODE_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_SHIFT (13U)
/*! PF0_DATA_ECC_ERR_EN
 *  0b0..No uncorrectable error reported in flash controller port 0 data memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 0 data memory by FMU.
 */
#define DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF0_DATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_MASK (0x4000U)
#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_SHIFT (14U)
/*! PF1_CODE_ECC_ERR_EN
 *  0b0..No uncorrectable error reported in flash controller port 1 code memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 1 code memory by FMU.
 */
#define DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF1_CODE_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_MASK (0x8000U)
#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_SHIFT (15U)
/*! PF1_DATA_ECC_ERR_EN
 *  0b0..No uncorrectable error reported in flash controller port 1 data memory by FMU.
 *  0b1..Uncorrectable error reported in flash controller port 1 data memory by FMU.
 */
#define DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_PF1_DATA_ECC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_MASK    (0x40000U)
#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_SHIFT   (18U)
/*! FLASH_EDC_ERR_EN
 *  0b0..No EDC after ECC error reported in flash.
 *  0b1..EDC after ECC error reported in flash.
 */
#define DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_MASK (0x80000U)
#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_SHIFT (19U)
/*! FLASH_ADDR_ENC_ERR_EN
 *  0b0..No address encode error in flash.
 *  0b1..Address encode error in flash.
 */
#define DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_ADDR_ENC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_MASK    (0x100000U)
#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_SHIFT   (20U)
/*! FLASH_REF_ERR_EN
 *  0b0..No reference current loss or read voltage error while previous reads(s).
 *  0b1..Reference current loss or read voltage error while previous read(s).
 */
#define DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_REF_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_MASK    (0x200000U)
#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_SHIFT   (21U)
/*! FLASH_RST_ERR_EN
 *  0b0..No flash reset error indicated.
 *  0b1..Flash reset error indicated.
 */
#define DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_RST_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_MASK   (0x400000U)
#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_SHIFT  (22U)
/*! FLASH_SCAN_ERR_EN
 *  0b0..No error while DCM flash scanning.
 *  0b1..Error while DCM flash scanning.
 */
#define DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_SCAN_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_MASK (0x1000000U)
#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_SHIFT (24U)
/*! FLASH_ACCESS_ERR_EN
 *  0b0..No transaction monitor mismatch error from flash controller.
 *  0b1..Transaction monitor mismatch error from flash controller.
 */
#define DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_FLASH_ACCESS_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_MASK   (0x4000000U)
#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_SHIFT  (26U)
/*! VDD1P1_GNG_ERR_EN
 *  0b0..Go indication referring to the supply being clean.
 *  0b1..No go indication referring to the supply being unclean and a fault in double bond connection or its routing within the chip.
 */
#define DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_VDD1P1_GNG_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_MASK   (0x8000000U)
#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_SHIFT  (27U)
/*! VDD2P5_GNG_ERR_EN
 *  0b0..Go indication referring to the supply being clean.
 *  0b1..No go indication referring to the supply being unclean and a fault in double bond connection or its routing within the chip.
 */
#define DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_VDD2P5_GNG_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_MASK (0x20000000U)
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_SHIFT (29U)
/*! TEST_ACTIVATION_0_ERR_EN
 *  0b0..No partial test activated accidentally.
 *  0b1..Partial test activated accidentally.
 */
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_TEST_ACTIVATION_0_ERR_EN_MASK)

#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_MASK (0x40000000U)
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_SHIFT (30U)
/*! TEST_ACTIVATION_1_ERR_EN
 *  0b0..No partial test activated accidentally.
 *  0b1..Partial test activated accidentally.
 */
#define DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD4_TEST_ACTIVATION_1_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD5 - Read Write GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN_MASK       (0x2U)
#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN_SHIFT      (1U)
/*! INTM_0_ERR_EN
 *  0b0..No error reported by interrupt monitor 0.
 *  0b1..Error reported by interrupt monitor 0.
 */
#define DCM_GPR_DCMRWD5_INTM_0_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_0_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_0_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN_MASK       (0x4U)
#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN_SHIFT      (2U)
/*! INTM_1_ERR_EN
 *  0b0..No error reported by interrupt monitor 1.
 *  0b1..Error reported by interrupt monitor 1.
 */
#define DCM_GPR_DCMRWD5_INTM_1_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_1_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_1_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN_MASK       (0x8U)
#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN_SHIFT      (3U)
/*! INTM_2_ERR_EN
 *  0b0..No error reported by interrupt monitor 2.
 *  0b1..Error reported by interrupt monitor 2.
 */
#define DCM_GPR_DCMRWD5_INTM_2_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_2_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_2_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN_MASK       (0x10U)
#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN_SHIFT      (4U)
/*! INTM_3_ERR_EN
 *  0b0..No error reported by interrupt monitor 3.
 *  0b1..Error reported by interrupt monitor 3.
 */
#define DCM_GPR_DCMRWD5_INTM_3_ERR_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_INTM_3_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_INTM_3_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_0_EN_MASK         (0x20U)
#define DCM_GPR_DCMRWD5_SW_NCF_0_EN_SHIFT        (5U)
/*! SW_NCF_0_EN
 *  0b0..Software NCF0, DCMRWF1[FCCU_SW_NCF0] not enabled by software.
 *  0b1..Software NCF0, DCMRWF1[FCCU_SW_NCF0] enabled by software.
 */
#define DCM_GPR_DCMRWD5_SW_NCF_0_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_0_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_0_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_1_EN_MASK         (0x40U)
#define DCM_GPR_DCMRWD5_SW_NCF_1_EN_SHIFT        (6U)
/*! SW_NCF_1_EN
 *  0b0..Software NCF1, DCMRWF1[FCCU_SW_NCF1] not enabled by software.
 *  0b1..Software NCF1, DCMRWF1[FCCU_SW_NCF1] enabled by software.
 */
#define DCM_GPR_DCMRWD5_SW_NCF_1_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_1_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_1_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_2_EN_MASK         (0x80U)
#define DCM_GPR_DCMRWD5_SW_NCF_2_EN_SHIFT        (7U)
/*! SW_NCF_2_EN
 *  0b0..Software NCF2, DCMRWF1[FCCU_SW_NCF2] not enabled by software.
 *  0b1..Software NCF2, DCMRWF1[FCCU_SW_NCF2] enabled by software.
 */
#define DCM_GPR_DCMRWD5_SW_NCF_2_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_2_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_2_EN_MASK)

#define DCM_GPR_DCMRWD5_SW_NCF_3_EN_MASK         (0x100U)
#define DCM_GPR_DCMRWD5_SW_NCF_3_EN_SHIFT        (8U)
/*! SW_NCF_3_EN
 *  0b0..Software NCF3, DCMRWF1[FCCU_SW_NCF3] not enabled by software.
 *  0b1..Software NCF3, DCMRWF1[FCCU_SW_NCF3] enabled by software.
 */
#define DCM_GPR_DCMRWD5_SW_NCF_3_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_SW_NCF_3_EN_SHIFT)) & DCM_GPR_DCMRWD5_SW_NCF_3_EN_MASK)

#define DCM_GPR_DCMRWD5_STCU_NCF_EN_MASK         (0x200U)
#define DCM_GPR_DCMRWD5_STCU_NCF_EN_SHIFT        (9U)
/*! STCU_NCF_EN
 *  0b0..STCU non-critical fault not reported.
 *  0b1..STCU non-critical fault reported.
 */
#define DCM_GPR_DCMRWD5_STCU_NCF_EN(x)           (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_STCU_NCF_EN_SHIFT)) & DCM_GPR_DCMRWD5_STCU_NCF_EN_MASK)

#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_MASK (0x400U)
#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_SHIFT (10U)
/*! MBIST_ACTIVATION_ERR_EN
 *  0b0..No accidental backdoor enabled on memories.
 *  0b1..Accidental backdoor enabled on memories.
 */
#define DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_MBIST_ACTIVATION_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_MASK (0x800U)
#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_SHIFT (11U)
/*! STCU_BIST_USER_CF_EN
 *  0b0..No accidental L/M BIST enabled.
 *  0b1..Accidental L/M BIST enabled.
 */
#define DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_SHIFT)) & DCM_GPR_DCMRWD5_STCU_BIST_USER_CF_EN_MASK)

#define DCM_GPR_DCMRWD5_MTR_BUS_ERR_EN_MASK      (0x1000U)
#define DCM_GPR_DCMRWD5_MTR_BUS_ERR_EN_SHIFT     (12U)
/*! MTR_BUS_ERR_EN
 *  0b0..No transfer error indicated from MTR.
 *  0b1..Transfer error indicated from MTR.
 */
#define DCM_GPR_DCMRWD5_MTR_BUS_ERR_EN(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_MTR_BUS_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_MTR_BUS_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_MASK (0x2000U)
#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_SHIFT (13U)
/*! DEBUG_ACTIVATION_ERR_EN
 *  0b0..Unintended debug not activated.
 *  0b1..Unintended debug activated.
 */
#define DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_DEBUG_ACTIVATION_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_TCM_RDATA_EDC_ERR_EN_MASK (0x4000U)
#define DCM_GPR_DCMRWD5_TCM_RDATA_EDC_ERR_EN_SHIFT (14U)
/*! TCM_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on TCM read data.
 *  0b1..Integrity error reported on TCM read data
 */
#define DCM_GPR_DCMRWD5_TCM_RDATA_EDC_ERR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_TCM_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_TCM_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_EMAC_RDATA_EDC_ERR_EN_MASK (0x8000U)
#define DCM_GPR_DCMRWD5_EMAC_RDATA_EDC_ERR_EN_SHIFT (15U)
/*! EMAC_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on EMAC read data.
 *  0b1..Integrity error reported on EMAC read data.
 */
#define DCM_GPR_DCMRWD5_EMAC_RDATA_EDC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_EMAC_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_EMAC_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_MASK (0x20000U)
#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_SHIFT (17U)
/*! DMA_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on eDMA read data.
 *  0b1..Integrity error reported on eDMA read data.
 */
#define DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_DMA_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_MASK (0x100000U)
#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_SHIFT (20U)
/*! CM7_0_AHBP_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on CM7_0 peripheral read data.
 *  0b1..Integrity error reported on CM7_0 peripheral read data.
 */
#define DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_CM7_0_AHBP_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_MASK (0x200000U)
#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_SHIFT (21U)
/*! CM7_0_AHBM_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on CM7_0 main read data.
 *  0b1..Integrity error reported on CM7_0 main read data.
 */
#define DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_CM7_0_AHBM_RDATA_EDC_ERR_EN_MASK)

#define DCM_GPR_DCMRWD5_HSE_RDATA_EDC_ERR_EN_MASK (0x400000U)
#define DCM_GPR_DCMRWD5_HSE_RDATA_EDC_ERR_EN_SHIFT (22U)
/*! HSE_RDATA_EDC_ERR_EN
 *  0b0..No integrity error reported on HSE read data.
 *  0b1..Integrity error reported on HSE read data.
 */
#define DCM_GPR_DCMRWD5_HSE_RDATA_EDC_ERR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD5_HSE_RDATA_EDC_ERR_EN_SHIFT)) & DCM_GPR_DCMRWD5_HSE_RDATA_EDC_ERR_EN_MASK)
/*! @} */

/*! @name DCMRWD6 - Read Write GPR On Destructive Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_MASK  (0x1U)
#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_SHIFT (0U)
/*! EDMA_DBG_DIS_CM7_0
 *  0b0..EDMA enters debug mode when CM7_0 enters debug mode.
 *  0b1..EDMA remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EDMA_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_MASK  (0x2U)
#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_SHIFT (1U)
/*! FCCU_DBG_DIS_CM7_0
 *  0b0..FCCU enters debug mode when CM7_0 enters debug mode.
 *  0b1..FCCU remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FCCU_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_MASK  (0x4U)
#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_SHIFT (2U)
/*! LCU0_DBG_DIS_CM7_0
 *  0b0..LCU0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LCU0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LCU0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_MASK  (0x8U)
#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_SHIFT (3U)
/*! LCU1_DBG_DIS_CM7_0
 *  0b0..LCU1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LCU1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LCU1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_MASK (0x10U)
#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_SHIFT (4U)
/*! EMIOS0_DBG_DIS_CM7_0
 *  0b0..eMIOS0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..eMIOS0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EMIOS0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_MASK (0x20U)
#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_SHIFT (5U)
/*! EMIOS1_DBG_DIS_CM7_0
 *  0b0..eMIOS1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..eMIOS1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EMIOS1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0_MASK (0x40U)
#define DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0_SHIFT (6U)
/*! EMIOS2_DBG_DIS_CM7_0
 *  0b0..eMIOS2 enters debug mode when CM7_0 enters debug mode.
 *  0b1..eMIOS2 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_EMIOS2_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_MASK   (0x80U)
#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_SHIFT  (7U)
/*! RTC_DBG_DIS_CM7_0
 *  0b0..RTC enters debug mode when CM7_0 enters debug mode.
 *  0b1..RTC remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_RTC_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_MASK  (0x100U)
#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_SHIFT (8U)
/*! SWT0_DBG_DIS_CM7_0
 *  0b0..SWT0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..SWT0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_SWT0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0_MASK  (0x200U)
#define DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0_SHIFT (9U)
/*! SWT1_DBG_DIS_CM7_0
 *  0b0..SWT0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..SWT0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_SWT1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_MASK  (0x400U)
#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_SHIFT (10U)
/*! STM0_DBG_DIS_CM7_0
 *  0b0..STM0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..STM0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_STM0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0_MASK  (0x800U)
#define DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0_SHIFT (11U)
/*! STM1_DBG_DIS_CM7_0
 *  0b0..STM1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..STM1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_STM1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_MASK  (0x1000U)
#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_SHIFT (12U)
/*! PIT0_DBG_DIS_CM7_0
 *  0b0..PIT0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..PIT0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_PIT0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_MASK  (0x2000U)
#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_SHIFT (13U)
/*! PIT1_DBG_DIS_CM7_0
 *  0b0..PIT1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..PIT1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_PIT1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0_MASK  (0x4000U)
#define DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0_SHIFT (14U)
/*! PIT2_DBG_DIS_CM7_0
 *  0b0..PIT2 enters debug mode when CM7_0 enters debug mode.
 *  0b1..PIT2 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_PIT2_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_MASK (0x8000U)
#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_SHIFT (15U)
/*! LPSPI0_DBG_DIS_CM7_0
 *  0b0..LPSPI0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_MASK (0x10000U)
#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_SHIFT (16U)
/*! LPSPI1_DBG_DIS_CM7_0
 *  0b0..LPSPI1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_MASK (0x20000U)
#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_SHIFT (17U)
/*! LPSPI2_DBG_DIS_CM7_0
 *  0b0..LPSPI2 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI2 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI2_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_MASK (0x40000U)
#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_SHIFT (18U)
/*! LPSPI3_DBG_DIS_CM7_0
 *  0b0..LPSPI3 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI3 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI3_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0_MASK (0x80000U)
#define DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0_SHIFT (19U)
/*! LPSPI4_DBG_DIS_CM7_0
 *  0b0..LPSPI4 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI4 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI4_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0_MASK (0x100000U)
#define DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0_SHIFT (20U)
/*! LPSPI5_DBG_DIS_CM7_0
 *  0b0..LPSPI5 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPSPI5 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPSPI5_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_MASK (0x200000U)
#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_SHIFT (21U)
/*! LPI2C0_DBG_DIS_CM7_0
 *  0b0..LPI2C0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPI2C0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPI2C0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_MASK (0x400000U)
#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_SHIFT (22U)
/*! LPI2C1_DBG_DIS_CM7_0
 *  0b0..LPI2C1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..LPI2C1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_LPI2C1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_MASK (0x800000U)
#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_SHIFT (23U)
/*! FLEXIO_DBG_DIS_CM7_0
 *  0b0..FLEXIO enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXIO remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXIO_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_MASK (0x1000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_SHIFT (24U)
/*! FLEXCAN0_DBG_DIS_CM7_0
 *  0b0..FLEXCAN0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_MASK (0x2000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_SHIFT (25U)
/*! FLEXCAN1_DBG_DIS_CM7_0
 *  0b0..FLEXCAN1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN1_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_MASK (0x4000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_SHIFT (26U)
/*! FLEXCAN2_DBG_DIS_CM7_0
 *  0b0..FLEXCAN2 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN2 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN2_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0_MASK (0x8000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0_SHIFT (27U)
/*! FLEXCAN3_DBG_DIS_CM7_0
 *  0b0..FLEXCAN3 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN3 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN3_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0_MASK (0x10000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0_SHIFT (28U)
/*! FLEXCAN4_DBG_DIS_CM7_0
 *  0b0..FLEXCAN4 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN4 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN4_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0_MASK (0x20000000U)
#define DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0_SHIFT (29U)
/*! FLEXCAN5_DBG_DIS_CM7_0
 *  0b0..FLEXCAN5 enters debug mode when CM7_0 enters debug mode.
 *  0b1..FLEXCAN5 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_FLEXCAN5_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0_MASK  (0x40000000U)
#define DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0_SHIFT (30U)
/*! SAI0_DBG_DIS_CM7_0
 *  0b0..SAI0 enters debug mode when CM7_0 enters debug mode.
 *  0b1..SAI0 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_SAI0_DBG_DIS_CM7_0_MASK)

#define DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0_MASK  (0x80000000U)
#define DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0_SHIFT (31U)
/*! SAI1_DBG_DIS_CM7_0
 *  0b0..SAI1 enters debug mode when CM7_0 enters debug mode.
 *  0b1..SAI1 remains functional and is not impacted when CM7_0 enters debug mode.
 */
#define DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0(x)    (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0_SHIFT)) & DCM_GPR_DCMRWD6_SAI1_DBG_DIS_CM7_0_MASK)
/*! @} */

/*! @name DCMRWF1 - Read Write GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL_MASK   (0x1U)
#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL_SHIFT  (0U)
/*! CAN_TIMESTAMP_SEL - Select between EMAC and STM for CAN timestamping
 *  0b0..EMAC selected for CAN timestamping.
 *  0b1..STM0 selected for CAN timestamping.
 */
#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL_SHIFT)) & DCM_GPR_DCMRWF1_CAN_TIMESTAMP_SEL_MASK)

#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN_MASK    (0x2U)
#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN_SHIFT   (1U)
/*! CAN_TIMESTAMP_EN - Enables CAN timestamping feature for all flexcans.
 *  0b0..CAN timestamping is disabled.
 *  0b1..CAN timestamping is enabled.
 */
#define DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN(x)      (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN_SHIFT)) & DCM_GPR_DCMRWF1_CAN_TIMESTAMP_EN_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0_MASK        (0x4U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0_SHIFT       (2U)
/*! FCCU_SW_NCF0 - Control to initiate Software NCF to FCCU.
 *  0b0..NCF to FCCU will not be generated.
 *  0b1..NCF to FCCU will be generated. For exact slot of FCCU, please refer FCCU chapter.
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF0(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF0_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF0_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1_MASK        (0x8U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1_SHIFT       (3U)
/*! FCCU_SW_NCF1 - Control to initiate Software NCF to FCCU.
 *  0b0..NCF to FCCU will not be generated.
 *  0b1..NCF to FCCU will be generated. For exact slot of FCCU, please refer FCCU chapter.
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF1(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF1_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF1_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2_MASK        (0x10U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2_SHIFT       (4U)
/*! FCCU_SW_NCF2 - Control to initiate Software NCF to FCCU.
 *  0b0..NCF to FCCU will not be generated.
 *  0b1..NCF to FCCU will be generated. For exact slot of FCCU, please refer FCCU chapter.
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF2(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF2_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF2_MASK)

#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3_MASK        (0x20U)
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3_SHIFT       (5U)
/*! FCCU_SW_NCF3 - Control to initiate Software NCF to FCCU.
 *  0b0..NCF to FCCU will not be generated.
 *  0b1..NCF to FCCU will be generated. For exact slot of FCCU, please refer FCCU chapter.
 */
#define DCM_GPR_DCMRWF1_FCCU_SW_NCF3(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_FCCU_SW_NCF3_SHIFT)) & DCM_GPR_DCMRWF1_FCCU_SW_NCF3_MASK)

#define DCM_GPR_DCMRWF1_RMII_MII_SEL_MASK        (0x80U)
#define DCM_GPR_DCMRWF1_RMII_MII_SEL_SHIFT       (7U)
/*! RMII_MII_SEL - Selects between MII and RMII mode of ethernet.
 *  0b0..MII mode
 *  0b1..RMII mode
 */
#define DCM_GPR_DCMRWF1_RMII_MII_SEL(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_RMII_MII_SEL_SHIFT)) & DCM_GPR_DCMRWF1_RMII_MII_SEL_MASK)

#define DCM_GPR_DCMRWF1_VDD_HV_B_IO_CTRL_LATCH_MASK (0x8000U)
#define DCM_GPR_DCMRWF1_VDD_HV_B_IO_CTRL_LATCH_SHIFT (15U)
/*! VDD_HV_B_IO_CTRL_LATCH - Controls the IO controls latching in low frequency RUN mode to reduce power consumption on VDD_HV_B domain pins.
 *  0b0..VDD_HV_B domain pins function as normal.
 *  0b1..The IO controls of VDD_HV_B domain pins are latched.
 */
#define DCM_GPR_DCMRWF1_VDD_HV_B_IO_CTRL_LATCH(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VDD_HV_B_IO_CTRL_LATCH_SHIFT)) & DCM_GPR_DCMRWF1_VDD_HV_B_IO_CTRL_LATCH_MASK)

#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK   (0x10000U)
#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_SHIFT  (16U)
/*! STANDBY_IO_CONFIG - Controls the IO state in the standby mode.
 *  0b0..STANDBY IO configuration standby entry: Must be written as 0 before IO configurations are done in standby entry sequence.
 *  0b1..STANDBY IO configuration standby exit: Must be written as 1 after IO configurations are done on standby exit.
 */
#define DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG(x)     (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_SHIFT)) & DCM_GPR_DCMRWF1_STANDBY_IO_CONFIG_MASK)

#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK       (0x100000U)
#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN_SHIFT      (20U)
/*! SUPPLY_MON_EN - Enable the supply voltage monitoring by ADC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMRWF1_SUPPLY_MON_EN(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_SUPPLY_MON_EN_SHIFT)) & DCM_GPR_DCMRWF1_SUPPLY_MON_EN_MASK)

#define DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_MASK      (0xE00000U)
#define DCM_GPR_DCMRWF1_SUPPLY_MON_SEL_SHIFT     (21U)
/*! SUPPLY_MON_SEL
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
/*! VSS_LV_ANMUX_EN
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_SHIFT)) & DCM_GPR_DCMRWF1_VSS_LV_ANMUX_EN_MASK)

#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK (0x2000000U)
#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_SHIFT (25U)
/*! VDD_HV_A_VLT_DVDR_EN - Enable for VDD_HV_A 2:1 divider for voltage measurement using supply voltage monitoring by ADC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_SHIFT)) & DCM_GPR_DCMRWF1_VDD_HV_A_VLT_DVDR_EN_MASK)

#define DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_MASK (0x4000000U)
#define DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_SHIFT (26U)
/*! VDD_HV_B_VLT_DVDR_EN - Enable for VDD_HV_B 2:1 divider for voltage measurement using supply voltage monitoring by ADC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_SHIFT)) & DCM_GPR_DCMRWF1_VDD_HV_B_VLT_DVDR_EN_MASK)

#define DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_MASK (0x8000000U)
#define DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_SHIFT (27U)
/*! VDD_1_5_VLT_DVDR_EN - Enable for VDD1P5 2:1 divider for voltage measurement using supply voltage monitoring by ADC.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_SHIFT)) & DCM_GPR_DCMRWF1_VDD_1_5_VLT_DVDR_EN_MASK)
/*! @} */

/*! @name DCMRWF2 - Read Write GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK (0x8U)
#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_SHIFT (3U)
/*! DCM_SCAN_BYP_STDBY_EXT - Control to bypass the DCM scanning on standby exit.
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_DCM_SCAN_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK (0x10U)
#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_SHIFT (4U)
/*! FIRC_TRIM_BYP_STDBY_EXT - Control to bypass the FIRC trimming on standby exit.
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_MASK (0x20U)
#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_SHIFT (5U)
/*! PMC_TRIM_RGM_DCF__BYP_STDBY_EXT - Control to bypass the PMC trimming and RGM DCF loading on standby exit.
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK (0x40U)
#define DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_SHIFT (6U)
/*! SIRC_TRIM_BYP_STDBY_EXT - Control to bypass the SIRC trimming on standby exit.
 *  0b0..Not bypassed
 *  0b1..Bypassed
 */
#define DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_SHIFT)) & DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK)

#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_MASK     (0x10000U)
#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_SHIFT    (16U)
/*! HSE_GSKT_BYPASS - Control to enable the HSE IAHB gasket behavior out of standby mode.
 *  0b0..When configured as 0, HSE IAHB gasket bypass configuration is controlled by DCF client.
 *  0b1..When configured as 1, HSE IAHB gasket is bypassed out of standby.
 */
#define DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_SHIFT)) & DCM_GPR_DCMRWF2_HSE_GSKT_BYPASS_MASK)
/*! @} */

/*! @name DCMRWF4 - Read Write GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_MASK (0x2U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_SHIFT (1U)
/*! MUX_MODE_EN_ADC0_S8 - Selects the GPIO45 to drive ADC0 standard channel 8th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S8_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_MASK (0x4U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_SHIFT (2U)
/*! MUX_MODE_EN_ADC0_S9 - Selects the GPIO46 to drive ADC0 standard channel 9th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC0_S9_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_MASK (0x8U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_SHIFT (3U)
/*! MUX_MODE_EN_ADC1_S14 - Selects the GPIO32 to drive ADC1 standard channel 14th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S14_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_MASK (0x10U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_SHIFT (4U)
/*! MUX_MODE_EN_ADC1_S15 - Selects the GPIO33 to drive ADC1 standard channel 15th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S15_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S22_MASK (0x20U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S22_SHIFT (5U)
/*! MUX_MODE_EN_ADC1_S22 - Selects the GPIO114 to drive ADC1 standard channel 22nd.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S22(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S22_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S22_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S23_MASK (0x40U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S23_SHIFT (6U)
/*! MUX_MODE_EN_ADC1_S23 - Selects the GPIO115 to drive ADC1 standard channel 23rd.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S23(x)  (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S23_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC1_S23_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S8_MASK (0x200U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S8_SHIFT (9U)
/*! MUX_MODE_EN_ADC2_S8 - Selects the GPIO45 to drive adc2 standard channel 8th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S8(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S8_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S8_MASK)

#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S9_MASK (0x400U)
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S9_SHIFT (10U)
/*! MUX_MODE_EN_ADC2_S9 - Selects the GPIO46 to drive adc2 standard channel 9th.
 *  0b0..Selects the default PAD 1.
 *  0b1..Selects the PAD mentioned in description.
 */
#define DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S9(x)   (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S9_SHIFT)) & DCM_GPR_DCMRWF4_MUX_MODE_EN_ADC2_S9_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_MASK (0x2000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_SHIFT (13U)
/*! GLITCH_FIL_TRG_IN0_BYP - Selects whether to BYPASS or filter out the pulse.
 *  0b0..Glitch filter on TRGMUX input63 is enabled.
 *  0b1..Glitch filter on TRGMUX input63 is bypassed.
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN0_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_MASK (0x4000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_SHIFT (14U)
/*! GLITCH_FIL_TRG_IN1_BYP - Selects whether to BYPASS or filter out the pulse.
 *  0b0..Glitch filter on TRGMUX input62 is enabled.
 *  0b1..Glitch filter on TRGMUX input62 is bypassed.
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN1_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_MASK (0x8000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_SHIFT (15U)
/*! GLITCH_FIL_TRG_IN2_BYP - Selects whether to BYPASS or filter out the pulse.
 *  0b0..Glitch filter on TRGMUX input61 is enabled.
 *  0b1..Glitch filter on TRGMUX input61 is bypassed.
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN2_BYP_MASK)

#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_MASK (0x10000U)
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_SHIFT (16U)
/*! GLITCH_FIL_TRG_IN3_BYP - Selects whether to BYPASS or filter out the pulse.
 *  0b0..Glitch filter on TRGMUX input60 is enabled.
 *  0b1..Glitch filter on TRGMUX input60 is bypassed.
 */
#define DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP(x) (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_SHIFT)) & DCM_GPR_DCMRWF4_GLITCH_FIL_TRG_IN3_BYP_MASK)

#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_MASK       (0x20000U)
#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_SHIFT      (17U)
/*! CM7_0_CPUWAIT
 *  0b0..CPUWAIT for CM7_0 disabled.
 *  0b1..CM7_0 put into wait mode using CPUWAIT.
 */
#define DCM_GPR_DCMRWF4_CM7_0_CPUWAIT(x)         (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_SHIFT)) & DCM_GPR_DCMRWF4_CM7_0_CPUWAIT_MASK)
/*! @} */

/*! @name DCMRWF5 - Read Write GPR On Functional Reset Register */
/*! @{ */

#define DCM_GPR_DCMRWF5_BOOT_MODE_MASK           (0x1U)
#define DCM_GPR_DCMRWF5_BOOT_MODE_SHIFT          (0U)
/*! BOOT_MODE
 *  0b0..Normal
 *  0b1..Fast Standby
 */
#define DCM_GPR_DCMRWF5_BOOT_MODE(x)             (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF5_BOOT_MODE_SHIFT)) & DCM_GPR_DCMRWF5_BOOT_MODE_MASK)

#define DCM_GPR_DCMRWF5_BOOT_ADDRESS_MASK        (0xFFFFFFFEU)
#define DCM_GPR_DCMRWF5_BOOT_ADDRESS_SHIFT       (1U)
#define DCM_GPR_DCMRWF5_BOOT_ADDRESS(x)          (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMRWF5_BOOT_ADDRESS_SHIFT)) & DCM_GPR_DCMRWF5_BOOT_ADDRESS_MASK)
/*! @} */

/*! @name DCMROPP1 - Read Only GPR On PMCPOR Reset */
/*! @{ */

#define DCM_GPR_DCMROPP1_POR_WDG_STAT0_MASK      (0x1U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT0_SHIFT     (0U)
/*! POR_WDG_STAT0 - This bit captures the status of functional reset sequence process FUNC0 when POR_WDG overflows.
 *  0b0..FUNC0 is inactive when POR_WDG overflows.
 *  0b1..FUNC0 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT0(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT0_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT0_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT1_MASK      (0x2U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT1_SHIFT     (1U)
/*! POR_WDG_STAT1 - This bit captures the status of functional reset sequence process FUNC1 when POR_WDG overflows.
 *  0b0..FUNC1 is inactive when POR_WDG overflows.
 *  0b1..FUNC1 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT1(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT1_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT1_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT2_MASK      (0x4U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT2_SHIFT     (2U)
/*! POR_WDG_STAT2 - This bit captures the status of functional reset sequence process FUNC2 when POR_WDG overflows.
 *  0b0..FUNC2 is inactive when POR_WDG overflows.
 *  0b1..FUNC2 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT2(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT2_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT2_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT3_MASK      (0x8U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT3_SHIFT     (3U)
/*! POR_WDG_STAT3 - This bit captures the status of functional reset sequence process FUNC3 when POR_WDG overflows.
 *  0b0..FUNC3 is inactive when POR_WDG overflows.
 *  0b1..FUNC3 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT3(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT3_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT3_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT4_MASK      (0x10U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT4_SHIFT     (4U)
/*! POR_WDG_STAT4 - This bit captures the status of functional reset sequence process FUNC4 when POR_WDG overflows.
 *  0b0..FUNC4 is inactive when POR_WDG overflows.
 *  0b1..FUNC4 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT4(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT4_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT4_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT5_MASK      (0x20U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT5_SHIFT     (5U)
/*! POR_WDG_STAT5 - This bit captures the status of functional reset sequence process FUNC5 when POR_WDG overflows.
 *  0b0..FUNC5 is inactive when POR_WDG overflows.
 *  0b1..FUNC5 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT5(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT5_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT5_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT6_MASK      (0x40U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT6_SHIFT     (6U)
/*! POR_WDG_STAT6 - This bit captures the status of functional reset sequence process FUNC6 when POR_WDG overflows.
 *  0b0..FUNC6 is inactive when POR_WDG overflows.
 *  0b1..FUNC6 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT6(x)        (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT6_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT6_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT10_MASK     (0x400U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT10_SHIFT    (10U)
/*! POR_WDG_STAT10 - This bit captures the status of functional reset sequence process FUNC7 when POR_WDG overflows.
 *  0b0..FUNC7 is inactive when POR_WDG overflows.
 *  0b1..FUNC7 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT10(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT10_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT10_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT11_MASK     (0x800U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT11_SHIFT    (11U)
/*! POR_WDG_STAT11 - This bit captures the status of functional reset sequence process FUNC7 when POR_WDG overflows.
 *  0b0..FUNC8 is inactive when POR_WDG overflows.
 *  0b1..FUNC8 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT11(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT11_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT11_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT14_MASK     (0x4000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT14_SHIFT    (14U)
/*! POR_WDG_STAT14 - This bit captures the status of functional reset sequence process FUNC9 when POR_WDG overflows.
 *  0b0..FUNC9 is inactive when POR_WDG overflows.
 *  0b1..FUNC9 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT14(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT14_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT14_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT17_MASK     (0x20000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT17_SHIFT    (17U)
/*! POR_WDG_STAT17 - This bit captures the status of functional reset sequence process FUNC10 when POR_WDG overflows.
 *  0b0..FUNC10 is inactive when POR_WDG overflows.
 *  0b1..FUNC10 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT17(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT17_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT17_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT20_MASK     (0x100000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT20_SHIFT    (20U)
/*! POR_WDG_STAT20 - This bit captures the status of functional reset sequence process DEST0 when POR_WDG overflows.
 *  0b0..DEST0 is inactive when POR_WDG overflows.
 *  0b1..DEST0 is active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT20(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT20_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT20_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT29_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT29_SHIFT    (29U)
/*! POR_WDG_STAT29 - This bit captures the status of standby entry request initiated by MC_ME when POR_WDG overflows.
 *  0b0..MC_ME standby request is active when POR_WDG overflows.
 *  0b1..MC_ME standby request is not active when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT29(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT29_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT29_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT30_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT30_SHIFT    (30U)
/*! POR_WDG_STAT30 - This bit captures the status of standby exit acknowledgement by MC_PCU when POR_WDG overflows.
 *  0b0..MC_PCU has not acknowledged standby exit when POR_WDG overflows.
 *  0b1..MC_PCU has acknowledged standby exit when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT30(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT30_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT30_MASK)

#define DCM_GPR_DCMROPP1_POR_WDG_STAT31_MASK     (0x80000000U)
#define DCM_GPR_DCMROPP1_POR_WDG_STAT31_SHIFT    (31U)
/*! POR_WDG_STAT31 - This bit captures MC_RGM reset event (if occured) while the device is in STANDBY mode.
 *  0b0..MC_RGM reset event not detected or no reset event arrived in STANDBY mode when POR_WDG overflows.
 *  0b1..MC_RGM reset event is detected in STANDBY mode when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP1_POR_WDG_STAT31(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP1_POR_WDG_STAT31_SHIFT)) & DCM_GPR_DCMROPP1_POR_WDG_STAT31_MASK)
/*! @} */

/*! @name DCMROPP2 - Read Only GPR On PMCPOR Reset */
/*! @{ */

#define DCM_GPR_DCMROPP2_POR_WDG_STAT32_MASK     (0x1U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT32_SHIFT    (0U)
/*! POR_WDG_STAT32 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[0] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[0] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT32(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT32_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT32_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT33_MASK     (0x2U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT33_SHIFT    (1U)
/*! POR_WDG_STAT33 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[1] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[1] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT33(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT33_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT33_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT34_MASK     (0x4U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT34_SHIFT    (2U)
/*! POR_WDG_STAT34 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[2] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[2] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT34(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT34_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT34_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT35_MASK     (0x8U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT35_SHIFT    (3U)
/*! POR_WDG_STAT35 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[3] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[3] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT35(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT35_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT35_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT36_MASK     (0x10U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT36_SHIFT    (4U)
/*! POR_WDG_STAT36 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[4] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[4] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT36(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT36_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT36_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT37_MASK     (0x20U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT37_SHIFT    (5U)
/*! POR_WDG_STAT37 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[5] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[5] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT37(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT37_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT37_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT38_MASK     (0x40U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT38_SHIFT    (6U)
/*! POR_WDG_STAT38 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[6] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[6] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT38(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT38_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT38_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT39_MASK     (0x80U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT39_SHIFT    (7U)
/*! POR_WDG_STAT39 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[7] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[7] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT39(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT39_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT39_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT40_MASK     (0x100U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT40_SHIFT    (8U)
/*! POR_WDG_STAT40 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[8] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[8] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT40(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT40_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT40_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT41_MASK     (0x200U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT41_SHIFT    (9U)
/*! POR_WDG_STAT41 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[9] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[9] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT41(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT41_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT41_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT42_MASK     (0x400U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT42_SHIFT    (10U)
/*! POR_WDG_STAT42 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[10] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[10] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT42(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT42_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT42_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT43_MASK     (0x800U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT43_SHIFT    (11U)
/*! POR_WDG_STAT43 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[11] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[11] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT43(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT43_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT43_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT44_MASK     (0x1000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT44_SHIFT    (12U)
/*! POR_WDG_STAT44 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[12] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[12] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT44(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT44_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT44_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT45_MASK     (0x2000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT45_SHIFT    (13U)
/*! POR_WDG_STAT45 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[13] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[13] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT45(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT45_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT45_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT46_MASK     (0x4000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT46_SHIFT    (14U)
/*! POR_WDG_STAT46 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[14] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[14] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT46(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT46_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT46_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT47_MASK     (0x8000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT47_SHIFT    (15U)
/*! POR_WDG_STAT47 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[15] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[15] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT47(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT47_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT47_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT48_MASK     (0x10000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT48_SHIFT    (16U)
/*! POR_WDG_STAT48 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[16] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[16] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT48(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT48_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT48_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT49_MASK     (0x20000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT49_SHIFT    (17U)
/*! POR_WDG_STAT49 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[17] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[17] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT49(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT49_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT49_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT50_MASK     (0x40000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT50_SHIFT    (18U)
/*! POR_WDG_STAT50 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[18] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[18] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT50(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT50_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT50_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT51_MASK     (0x80000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT51_SHIFT    (19U)
/*! POR_WDG_STAT51 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[19] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[19] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT51(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT51_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT51_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT52_MASK     (0x100000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT52_SHIFT    (20U)
/*! POR_WDG_STAT52 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[20] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[20] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT52(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT52_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT52_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT53_MASK     (0x200000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT53_SHIFT    (21U)
/*! POR_WDG_STAT53 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[21] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[21] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT53(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT53_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT53_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT54_MASK     (0x400000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT54_SHIFT    (22U)
/*! POR_WDG_STAT54 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[22] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[22] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT54(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT54_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT54_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT55_MASK     (0x800000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT55_SHIFT    (23U)
/*! POR_WDG_STAT55 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[23] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[23] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT55(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT55_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT55_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT56_MASK     (0x1000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT56_SHIFT    (24U)
/*! POR_WDG_STAT56 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[24] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[24] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT56(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT56_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT56_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT57_MASK     (0x2000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT57_SHIFT    (25U)
/*! POR_WDG_STAT57 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[25] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[25] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT57(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT57_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT57_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT58_MASK     (0x4000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT58_SHIFT    (26U)
/*! POR_WDG_STAT58 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[26] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[26] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT58(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT58_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT58_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT59_MASK     (0x8000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT59_SHIFT    (27U)
/*! POR_WDG_STAT59 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[27] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[27] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT59(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT59_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT59_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT60_MASK     (0x10000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT60_SHIFT    (28U)
/*! POR_WDG_STAT60 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[28] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[28] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT60(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT60_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT60_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT61_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT61_SHIFT    (29U)
/*! POR_WDG_STAT61 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[29] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[29] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT61(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT61_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT61_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT62_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT62_SHIFT    (30U)
/*! POR_WDG_STAT62 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[30] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[30] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT62(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT62_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT62_MASK)

#define DCM_GPR_DCMROPP2_POR_WDG_STAT63_MASK     (0x80000000U)
#define DCM_GPR_DCMROPP2_POR_WDG_STAT63_SHIFT    (31U)
/*! POR_WDG_STAT63 - This bit captures MC_RGM functional/external event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_FES[31] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_FES[31] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP2_POR_WDG_STAT63(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP2_POR_WDG_STAT63_SHIFT)) & DCM_GPR_DCMROPP2_POR_WDG_STAT63_MASK)
/*! @} */

/*! @name DCMROPP3 - Read Only GPR On PMCPOR Reset */
/*! @{ */

#define DCM_GPR_DCMROPP3_POR_WDG_STAT64_MASK     (0x1U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT64_SHIFT    (0U)
/*! POR_WDG_STAT64 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[0] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[0] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT64(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT64_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT64_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT65_MASK     (0x2U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT65_SHIFT    (1U)
/*! POR_WDG_STAT65 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[1] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[1] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT65(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT65_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT65_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT66_MASK     (0x4U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT66_SHIFT    (2U)
/*! POR_WDG_STAT66 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[2] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[2] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT66(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT66_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT66_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT67_MASK     (0x8U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT67_SHIFT    (3U)
/*! POR_WDG_STAT67 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[3] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[3] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT67(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT67_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT67_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT68_MASK     (0x10U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT68_SHIFT    (4U)
/*! POR_WDG_STAT68 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[4] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[4] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT68(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT68_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT68_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT69_MASK     (0x20U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT69_SHIFT    (5U)
/*! POR_WDG_STAT69 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[5] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[5] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT69(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT69_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT69_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT70_MASK     (0x40U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT70_SHIFT    (6U)
/*! POR_WDG_STAT70 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[6] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[6] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT70(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT70_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT70_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT71_MASK     (0x80U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT71_SHIFT    (7U)
/*! POR_WDG_STAT71 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[7] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[7] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT71(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT71_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT71_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT72_MASK     (0x100U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT72_SHIFT    (8U)
/*! POR_WDG_STAT72 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[8] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[8] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT72(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT72_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT72_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT73_MASK     (0x200U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT73_SHIFT    (9U)
/*! POR_WDG_STAT73 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[9] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[9] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT73(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT73_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT73_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT74_MASK     (0x400U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT74_SHIFT    (10U)
/*! POR_WDG_STAT74 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[10] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[10] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT74(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT74_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT74_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT75_MASK     (0x800U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT75_SHIFT    (11U)
/*! POR_WDG_STAT75 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[11] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[11] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT75(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT75_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT75_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT76_MASK     (0x1000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT76_SHIFT    (12U)
/*! POR_WDG_STAT76 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[12] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[12] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT76(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT76_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT76_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT77_MASK     (0x2000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT77_SHIFT    (13U)
/*! POR_WDG_STAT77 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[13] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[13] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT77(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT77_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT77_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT78_MASK     (0x4000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT78_SHIFT    (14U)
/*! POR_WDG_STAT78 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[14] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[14] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT78(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT78_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT78_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT79_MASK     (0x8000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT79_SHIFT    (15U)
/*! POR_WDG_STAT79 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[15] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[15] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT79(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT79_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT79_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT80_MASK     (0x10000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT80_SHIFT    (16U)
/*! POR_WDG_STAT80 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[16] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[16] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT80(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT80_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT80_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT81_MASK     (0x20000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT81_SHIFT    (17U)
/*! POR_WDG_STAT81 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[17] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[17] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT81(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT81_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT81_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT82_MASK     (0x40000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT82_SHIFT    (18U)
/*! POR_WDG_STAT82 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[18] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[18] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT82(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT82_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT82_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT83_MASK     (0x80000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT83_SHIFT    (19U)
/*! POR_WDG_STAT83 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[19] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[19] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT83(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT83_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT83_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT84_MASK     (0x100000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT84_SHIFT    (20U)
/*! POR_WDG_STAT84 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[20] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[20] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT84(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT84_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT84_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT85_MASK     (0x200000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT85_SHIFT    (21U)
/*! POR_WDG_STAT85 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[21] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[21] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT85(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT85_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT85_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT86_MASK     (0x400000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT86_SHIFT    (22U)
/*! POR_WDG_STAT86 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[22] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[22] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT86(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT86_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT86_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT87_MASK     (0x800000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT87_SHIFT    (23U)
/*! POR_WDG_STAT87 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[23] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[23] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT87(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT87_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT87_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT88_MASK     (0x1000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT88_SHIFT    (24U)
/*! POR_WDG_STAT88 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[24] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[24] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT88(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT88_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT88_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT89_MASK     (0x2000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT89_SHIFT    (25U)
/*! POR_WDG_STAT89 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[25] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[25] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT89(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT89_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT89_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT90_MASK     (0x4000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT90_SHIFT    (26U)
/*! POR_WDG_STAT90 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[26] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[26] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT90(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT90_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT90_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT91_MASK     (0x8000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT91_SHIFT    (27U)
/*! POR_WDG_STAT91 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[27] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[27] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT91(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT91_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT91_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT92_MASK     (0x10000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT92_SHIFT    (28U)
/*! POR_WDG_STAT92 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[28] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[28] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT92(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT92_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT92_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT93_MASK     (0x20000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT93_SHIFT    (29U)
/*! POR_WDG_STAT93 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[29] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[29] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT93(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT93_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT93_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT94_MASK     (0x40000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT94_SHIFT    (30U)
/*! POR_WDG_STAT94 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[30] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[30] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT94(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT94_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT94_MASK)

#define DCM_GPR_DCMROPP3_POR_WDG_STAT95_MASK     (0x80000000U)
#define DCM_GPR_DCMROPP3_POR_WDG_STAT95_SHIFT    (31U)
/*! POR_WDG_STAT95 - This bit captures MC_RGM destructive event status register when POR_WDG overflows.
 *  0b0..MC_RGM.RGM_DES[31] is 0 when POR_WDG overflows.
 *  0b1..MC_RGM.RGM_DES[31] is 1 when POR_WDG overflows.
 */
#define DCM_GPR_DCMROPP3_POR_WDG_STAT95(x)       (((uint32_t)(((uint32_t)(x)) << DCM_GPR_DCMROPP3_POR_WDG_STAT95_SHIFT)) & DCM_GPR_DCMROPP3_POR_WDG_STAT95_MASK)
/*! @} */

/*! @name DCMROPP4 - Read Only GPR On PMCPOR Reset */
/*! @{ */

#define DCM_GPR_DCMROPP4_POR_WDG_STAT96_MASK     (0x1U)
#define DCM_GPR_DCMROPP4_POR_WDG_STAT96_SHIFT    (0U)
/*! POR_WDG_STAT96 - This bit captures POR_WDG reset event if POR_WDG initiates a POR sequence.
 *  0b0..POR_WDG is inactive.
 *  0b1..POR_WDG has detected a stuck scenario and raised device POR event. Refer POR_WDG_STAT[95:0] for device status when POR_WDG overflows
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

