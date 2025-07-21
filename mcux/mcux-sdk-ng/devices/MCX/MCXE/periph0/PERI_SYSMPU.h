/*
** ###################################################################
**     Processors:          MCXE247VLL
**                          MCXE247VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250417
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SYSMPU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_SYSMPU.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for SYSMPU
 *
 * CMSIS Peripheral Access Layer for SYSMPU
 */

#if !defined(PERI_SYSMPU_H_)
#define PERI_SYSMPU_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE247VLL) || defined(CPU_MCXE247VLQ))
#include "MCXE247_COMMON.h"
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
   -- SYSMPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSMPU_Peripheral_Access_Layer SYSMPU Peripheral Access Layer
 * @{
 */

/** SYSMPU - Size of Registers Arrays */
#define SYSMPU_SP_COUNT                           5u
#define SYSMPU_RGD_COUNT                          16u
#define SYSMPU_RGD_WORD_COUNT                     4u
#define SYSMPU_RGDAAC_COUNT                       16u

/** SYSMPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CESR;                              /**< Control/Error Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __I  uint32_t EAR;                               /**< Error Address Register, slave port 0..Error Address Register, slave port 4, array offset: 0x10, array step: 0x8 */
    __I  uint32_t EDR;                               /**< Error Detail Register, slave port 0..Error Detail Register, slave port 4, array offset: 0x14, array step: 0x8 */
  } SP[SYSMPU_SP_COUNT];
       uint8_t RESERVED_1[968];
  __IO uint32_t WORD[SYSMPU_RGD_COUNT][SYSMPU_RGD_WORD_COUNT]; /**< Region Descriptor 0, Word 0..Region Descriptor 15, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
       uint8_t RESERVED_2[768];
  __IO uint32_t RGDAAC[SYSMPU_RGDAAC_COUNT];       /**< Region Descriptor Alternate Access Control 0..Region Descriptor Alternate Access Control 15, array offset: 0x800, array step: 0x4 */
} SYSMPU_Type;

/* ----------------------------------------------------------------------------
   -- SYSMPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSMPU_Register_Masks SYSMPU Register Masks
 * @{
 */

/*! @name CESR - Control/Error Status Register */
/*! @{ */

#define SYSMPU_CESR_VLD_MASK                     (0x1U)
#define SYSMPU_CESR_VLD_SHIFT                    (0U)
/*! VLD - Valid
 *  0b0..MPU is disabled. All accesses from all bus masters are allowed.
 *  0b1..MPU is enabled
 */
#define SYSMPU_CESR_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_VLD_SHIFT)) & SYSMPU_CESR_VLD_MASK)

#define SYSMPU_CESR_NRGD_MASK                    (0xF00U)
#define SYSMPU_CESR_NRGD_SHIFT                   (8U)
/*! NRGD - Number Of Region Descriptors
 *  0b0000..8 region descriptors
 *  0b0001..12 region descriptors
 *  0b0010..16 region descriptors
 */
#define SYSMPU_CESR_NRGD(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_NRGD_SHIFT)) & SYSMPU_CESR_NRGD_MASK)

#define SYSMPU_CESR_NSP_MASK                     (0xF000U)
#define SYSMPU_CESR_NSP_SHIFT                    (12U)
/*! NSP - Number Of Slave Ports */
#define SYSMPU_CESR_NSP(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_NSP_SHIFT)) & SYSMPU_CESR_NSP_MASK)

#define SYSMPU_CESR_HRL_MASK                     (0xF0000U)
#define SYSMPU_CESR_HRL_SHIFT                    (16U)
/*! HRL - Hardware Revision Level */
#define SYSMPU_CESR_HRL(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_HRL_SHIFT)) & SYSMPU_CESR_HRL_MASK)

#define SYSMPU_CESR_SPERR4_MASK                  (0x8000000U)
#define SYSMPU_CESR_SPERR4_SHIFT                 (27U)
/*! SPERR4 - Slave Port 4 Error
 *  0b0..No error has occurred for slave port 4.
 *  0b1..An error has occurred for slave port 4.
 */
#define SYSMPU_CESR_SPERR4(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR4_SHIFT)) & SYSMPU_CESR_SPERR4_MASK)

#define SYSMPU_CESR_SPERR3_MASK                  (0x10000000U)
#define SYSMPU_CESR_SPERR3_SHIFT                 (28U)
/*! SPERR3 - Slave Port 3 Error
 *  0b0..No error has occurred for slave port 3.
 *  0b1..An error has occurred for slave port 3.
 */
#define SYSMPU_CESR_SPERR3(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR3_SHIFT)) & SYSMPU_CESR_SPERR3_MASK)

#define SYSMPU_CESR_SPERR2_MASK                  (0x20000000U)
#define SYSMPU_CESR_SPERR2_SHIFT                 (29U)
/*! SPERR2 - Slave Port 2 Error
 *  0b0..No error has occurred for slave port 2.
 *  0b1..An error has occurred for slave port 2.
 */
#define SYSMPU_CESR_SPERR2(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR2_SHIFT)) & SYSMPU_CESR_SPERR2_MASK)

#define SYSMPU_CESR_SPERR1_MASK                  (0x40000000U)
#define SYSMPU_CESR_SPERR1_SHIFT                 (30U)
/*! SPERR1 - Slave Port 1 Error
 *  0b0..No error has occurred for slave port 1.
 *  0b1..An error has occurred for slave port 1.
 */
#define SYSMPU_CESR_SPERR1(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR1_SHIFT)) & SYSMPU_CESR_SPERR1_MASK)

#define SYSMPU_CESR_SPERR0_MASK                  (0x80000000U)
#define SYSMPU_CESR_SPERR0_SHIFT                 (31U)
/*! SPERR0 - Slave Port 0 Error
 *  0b0..No error has occurred for slave port 0.
 *  0b1..An error has occurred for slave port 0.
 */
#define SYSMPU_CESR_SPERR0(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR0_SHIFT)) & SYSMPU_CESR_SPERR0_MASK)
/*! @} */

/*! @name EAR - Error Address Register, slave port 0..Error Address Register, slave port 4 */
/*! @{ */

#define SYSMPU_EAR_EADDR_MASK                    (0xFFFFFFFFU)
#define SYSMPU_EAR_EADDR_SHIFT                   (0U)
/*! EADDR - Error Address */
#define SYSMPU_EAR_EADDR(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_EAR_EADDR_SHIFT)) & SYSMPU_EAR_EADDR_MASK)
/*! @} */

/* The count of SYSMPU_EAR */
#define SYSMPU_EAR_COUNT                         (5U)

/*! @name EDR - Error Detail Register, slave port 0..Error Detail Register, slave port 4 */
/*! @{ */

#define SYSMPU_EDR_ERW_MASK                      (0x1U)
#define SYSMPU_EDR_ERW_SHIFT                     (0U)
/*! ERW - Error Read/Write
 *  0b0..Read
 *  0b1..Write
 */
#define SYSMPU_EDR_ERW(x)                        (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_ERW_SHIFT)) & SYSMPU_EDR_ERW_MASK)

#define SYSMPU_EDR_EATTR_MASK                    (0xEU)
#define SYSMPU_EDR_EATTR_SHIFT                   (1U)
/*! EATTR - Error Attributes
 *  0b000..User mode, instruction access
 *  0b001..User mode, data access
 *  0b010..Supervisor mode, instruction access
 *  0b011..Supervisor mode, data access
 */
#define SYSMPU_EDR_EATTR(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EATTR_SHIFT)) & SYSMPU_EDR_EATTR_MASK)

#define SYSMPU_EDR_EMN_MASK                      (0xF0U)
#define SYSMPU_EDR_EMN_SHIFT                     (4U)
/*! EMN - Error Master Number */
#define SYSMPU_EDR_EMN(x)                        (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EMN_SHIFT)) & SYSMPU_EDR_EMN_MASK)

#define SYSMPU_EDR_EPID_MASK                     (0xFF00U)
#define SYSMPU_EDR_EPID_SHIFT                    (8U)
/*! EPID - Error Process Identification */
#define SYSMPU_EDR_EPID(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EPID_SHIFT)) & SYSMPU_EDR_EPID_MASK)

#define SYSMPU_EDR_EACD_MASK                     (0xFFFF0000U)
#define SYSMPU_EDR_EACD_SHIFT                    (16U)
/*! EACD - Error Access Control Detail */
#define SYSMPU_EDR_EACD(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EACD_SHIFT)) & SYSMPU_EDR_EACD_MASK)
/*! @} */

/* The count of SYSMPU_EDR */
#define SYSMPU_EDR_COUNT                         (5U)

/*! @name WORD - Region Descriptor 0, Word 0..Region Descriptor 15, Word 3 */
/*! @{ */

#define SYSMPU_WORD_M0UM_MASK                    (0x7U)
#define SYSMPU_WORD_M0UM_SHIFT                   (0U)
/*! M0UM - Bus Master 0 User Mode Access Control */
#define SYSMPU_WORD_M0UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0UM_SHIFT)) & SYSMPU_WORD_M0UM_MASK)

#define SYSMPU_WORD_VLD_MASK                     (0x1U)
#define SYSMPU_WORD_VLD_SHIFT                    (0U)
/*! VLD - Valid
 *  0b0..Region descriptor is invalid
 *  0b1..Region descriptor is valid
 */
#define SYSMPU_WORD_VLD(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_VLD_SHIFT)) & SYSMPU_WORD_VLD_MASK)

#define SYSMPU_WORD_M0SM_MASK                    (0x18U)
#define SYSMPU_WORD_M0SM_SHIFT                   (3U)
/*! M0SM - Bus Master 0 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M0UM
 */
#define SYSMPU_WORD_M0SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0SM_SHIFT)) & SYSMPU_WORD_M0SM_MASK)

#define SYSMPU_WORD_ENDADDR_MASK                 (0xFFFFFFE0U)
#define SYSMPU_WORD_ENDADDR_SHIFT                (5U)
/*! ENDADDR - End Address */
#define SYSMPU_WORD_ENDADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_ENDADDR_SHIFT)) & SYSMPU_WORD_ENDADDR_MASK)

#define SYSMPU_WORD_M0PE_MASK                    (0x20U)
#define SYSMPU_WORD_M0PE_SHIFT                   (5U)
/*! M0PE - Bus Master 0 Process Identifier enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn.RGDAAC) in the region hit evaluation
 */
#define SYSMPU_WORD_M0PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0PE_SHIFT)) & SYSMPU_WORD_M0PE_MASK)

#define SYSMPU_WORD_SRTADDR_MASK                 (0xFFFFFFE0U)
#define SYSMPU_WORD_SRTADDR_SHIFT                (5U)
/*! SRTADDR - Start Address */
#define SYSMPU_WORD_SRTADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_SRTADDR_SHIFT)) & SYSMPU_WORD_SRTADDR_MASK)

#define SYSMPU_WORD_M1UM_MASK                    (0x1C0U)
#define SYSMPU_WORD_M1UM_SHIFT                   (6U)
/*! M1UM - Bus Master 1 User Mode Access Control */
#define SYSMPU_WORD_M1UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1UM_SHIFT)) & SYSMPU_WORD_M1UM_MASK)

#define SYSMPU_WORD_M1SM_MASK                    (0x600U)
#define SYSMPU_WORD_M1SM_SHIFT                   (9U)
/*! M1SM - Bus Master 1 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M1UM
 */
#define SYSMPU_WORD_M1SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1SM_SHIFT)) & SYSMPU_WORD_M1SM_MASK)

#define SYSMPU_WORD_M1PE_MASK                    (0x800U)
#define SYSMPU_WORD_M1PE_SHIFT                   (11U)
/*! M1PE - Bus Master 1 Process Identifier enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn.RGDAAC) in the region hit evaluation
 */
#define SYSMPU_WORD_M1PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1PE_SHIFT)) & SYSMPU_WORD_M1PE_MASK)

#define SYSMPU_WORD_M2UM_MASK                    (0x7000U)
#define SYSMPU_WORD_M2UM_SHIFT                   (12U)
/*! M2UM - Bus Master 2 User Mode Access control */
#define SYSMPU_WORD_M2UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2UM_SHIFT)) & SYSMPU_WORD_M2UM_MASK)

#define SYSMPU_WORD_M2SM_MASK                    (0x18000U)
#define SYSMPU_WORD_M2SM_SHIFT                   (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M2UM
 */
#define SYSMPU_WORD_M2SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2SM_SHIFT)) & SYSMPU_WORD_M2SM_MASK)

#define SYSMPU_WORD_PIDMASK_MASK                 (0xFF0000U)
#define SYSMPU_WORD_PIDMASK_SHIFT                (16U)
/*! PIDMASK - Process Identifier Mask */
#define SYSMPU_WORD_PIDMASK(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_PIDMASK_SHIFT)) & SYSMPU_WORD_PIDMASK_MASK)

#define SYSMPU_WORD_M3UM_MASK                    (0x1C0000U)
#define SYSMPU_WORD_M3UM_SHIFT                   (18U)
/*! M3UM - Bus Master 3 User Mode Access Control */
#define SYSMPU_WORD_M3UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M3UM_SHIFT)) & SYSMPU_WORD_M3UM_MASK)

#define SYSMPU_WORD_M3SM_MASK                    (0x600000U)
#define SYSMPU_WORD_M3SM_SHIFT                   (21U)
/*! M3SM - Bus Master 3 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M3UM
 */
#define SYSMPU_WORD_M3SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M3SM_SHIFT)) & SYSMPU_WORD_M3SM_MASK)

#define SYSMPU_WORD_M4WE_MASK                    (0x1000000U)
#define SYSMPU_WORD_M4WE_SHIFT                   (24U)
/*! M4WE - Bus Master 4 Write Enable
 *  0b0..Bus master 4 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 4 writes allowed
 */
#define SYSMPU_WORD_M4WE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M4WE_SHIFT)) & SYSMPU_WORD_M4WE_MASK)

#define SYSMPU_WORD_PID_MASK                     (0xFF000000U)
#define SYSMPU_WORD_PID_SHIFT                    (24U)
/*! PID - Process Identifier */
#define SYSMPU_WORD_PID(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_PID_SHIFT)) & SYSMPU_WORD_PID_MASK)

#define SYSMPU_WORD_M4RE_MASK                    (0x2000000U)
#define SYSMPU_WORD_M4RE_SHIFT                   (25U)
/*! M4RE - Bus Master 4 Read Enable
 *  0b0..Bus master 4 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 4 reads allowed
 */
#define SYSMPU_WORD_M4RE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M4RE_SHIFT)) & SYSMPU_WORD_M4RE_MASK)

#define SYSMPU_WORD_M5WE_MASK                    (0x4000000U)
#define SYSMPU_WORD_M5WE_SHIFT                   (26U)
/*! M5WE - Bus Master 5 Write Enable
 *  0b0..Bus master 5 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 5 writes allowed
 */
#define SYSMPU_WORD_M5WE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M5WE_SHIFT)) & SYSMPU_WORD_M5WE_MASK)

#define SYSMPU_WORD_M5RE_MASK                    (0x8000000U)
#define SYSMPU_WORD_M5RE_SHIFT                   (27U)
/*! M5RE - Bus Master 5 Read Enable
 *  0b0..Bus master 5 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 5 reads allowed
 */
#define SYSMPU_WORD_M5RE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M5RE_SHIFT)) & SYSMPU_WORD_M5RE_MASK)

#define SYSMPU_WORD_M6WE_MASK                    (0x10000000U)
#define SYSMPU_WORD_M6WE_SHIFT                   (28U)
/*! M6WE - Bus Master 6 Write Enable
 *  0b0..Bus master 6 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 6 writes allowed
 */
#define SYSMPU_WORD_M6WE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M6WE_SHIFT)) & SYSMPU_WORD_M6WE_MASK)

#define SYSMPU_WORD_M6RE_MASK                    (0x20000000U)
#define SYSMPU_WORD_M6RE_SHIFT                   (29U)
/*! M6RE - Bus Master 6 Read Enable
 *  0b0..Bus master 6 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 6 reads allowed
 */
#define SYSMPU_WORD_M6RE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M6RE_SHIFT)) & SYSMPU_WORD_M6RE_MASK)

#define SYSMPU_WORD_M7WE_MASK                    (0x40000000U)
#define SYSMPU_WORD_M7WE_SHIFT                   (30U)
/*! M7WE - Bus Master 7 Write Enable
 *  0b0..Bus master 7 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 7 writes allowed
 */
#define SYSMPU_WORD_M7WE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M7WE_SHIFT)) & SYSMPU_WORD_M7WE_MASK)

#define SYSMPU_WORD_M7RE_MASK                    (0x80000000U)
#define SYSMPU_WORD_M7RE_SHIFT                   (31U)
/*! M7RE - Bus Master 7 Read Enable
 *  0b0..Bus master 7 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 7 reads allowed
 */
#define SYSMPU_WORD_M7RE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M7RE_SHIFT)) & SYSMPU_WORD_M7RE_MASK)
/*! @} */

/* The count of SYSMPU_WORD */
#define SYSMPU_WORD_COUNT                        (16U)

/* The count of SYSMPU_WORD */
#define SYSMPU_WORD_COUNT2                       (4U)

/*! @name RGDAAC - Region Descriptor Alternate Access Control 0..Region Descriptor Alternate Access Control 15 */
/*! @{ */

#define SYSMPU_RGDAAC_M0UM_MASK                  (0x7U)
#define SYSMPU_RGDAAC_M0UM_SHIFT                 (0U)
/*! M0UM - Bus Master 0 User Mode Access Control */
#define SYSMPU_RGDAAC_M0UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0UM_SHIFT)) & SYSMPU_RGDAAC_M0UM_MASK)

#define SYSMPU_RGDAAC_M0SM_MASK                  (0x18U)
#define SYSMPU_RGDAAC_M0SM_SHIFT                 (3U)
/*! M0SM - Bus Master 0 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M0UM
 */
#define SYSMPU_RGDAAC_M0SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0SM_SHIFT)) & SYSMPU_RGDAAC_M0SM_MASK)

#define SYSMPU_RGDAAC_M0PE_MASK                  (0x20U)
#define SYSMPU_RGDAAC_M0PE_SHIFT                 (5U)
/*! M0PE - Bus Master 0 Process Identifier Enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn.RGDAAC) in the region hit evaluation
 */
#define SYSMPU_RGDAAC_M0PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0PE_SHIFT)) & SYSMPU_RGDAAC_M0PE_MASK)

#define SYSMPU_RGDAAC_M1UM_MASK                  (0x1C0U)
#define SYSMPU_RGDAAC_M1UM_SHIFT                 (6U)
/*! M1UM - Bus Master 1 User Mode Access Control */
#define SYSMPU_RGDAAC_M1UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1UM_SHIFT)) & SYSMPU_RGDAAC_M1UM_MASK)

#define SYSMPU_RGDAAC_M1SM_MASK                  (0x600U)
#define SYSMPU_RGDAAC_M1SM_SHIFT                 (9U)
/*! M1SM - Bus Master 1 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M1UM
 */
#define SYSMPU_RGDAAC_M1SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1SM_SHIFT)) & SYSMPU_RGDAAC_M1SM_MASK)

#define SYSMPU_RGDAAC_M1PE_MASK                  (0x800U)
#define SYSMPU_RGDAAC_M1PE_SHIFT                 (11U)
/*! M1PE - Bus Master 1 Process Identifier Enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn.RGDAAC) in the region hit evaluation
 */
#define SYSMPU_RGDAAC_M1PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1PE_SHIFT)) & SYSMPU_RGDAAC_M1PE_MASK)

#define SYSMPU_RGDAAC_M2UM_MASK                  (0x7000U)
#define SYSMPU_RGDAAC_M2UM_SHIFT                 (12U)
/*! M2UM - Bus Master 2 User Mode Access Control */
#define SYSMPU_RGDAAC_M2UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2UM_SHIFT)) & SYSMPU_RGDAAC_M2UM_MASK)

#define SYSMPU_RGDAAC_M2SM_MASK                  (0x18000U)
#define SYSMPU_RGDAAC_M2SM_SHIFT                 (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M2UM
 */
#define SYSMPU_RGDAAC_M2SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2SM_SHIFT)) & SYSMPU_RGDAAC_M2SM_MASK)

#define SYSMPU_RGDAAC_M3UM_MASK                  (0x1C0000U)
#define SYSMPU_RGDAAC_M3UM_SHIFT                 (18U)
/*! M3UM - Bus Master 3 User Mode Access Control */
#define SYSMPU_RGDAAC_M3UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M3UM_SHIFT)) & SYSMPU_RGDAAC_M3UM_MASK)

#define SYSMPU_RGDAAC_M3SM_MASK                  (0x600000U)
#define SYSMPU_RGDAAC_M3SM_SHIFT                 (21U)
/*! M3SM - Bus Master 3 Supervisor Mode Access Control
 *  0b00..r/w/x; read, write and execute allowed
 *  0b01..r/x; read and execute allowed, but no write
 *  0b10..r/w; read and write allowed, but no execute
 *  0b11..Same as User mode defined in M3UM
 */
#define SYSMPU_RGDAAC_M3SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M3SM_SHIFT)) & SYSMPU_RGDAAC_M3SM_MASK)

#define SYSMPU_RGDAAC_M4WE_MASK                  (0x1000000U)
#define SYSMPU_RGDAAC_M4WE_SHIFT                 (24U)
/*! M4WE - Bus Master 4 Write Enable
 *  0b0..Bus master 4 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 4 writes allowed
 */
#define SYSMPU_RGDAAC_M4WE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M4WE_SHIFT)) & SYSMPU_RGDAAC_M4WE_MASK)

#define SYSMPU_RGDAAC_M4RE_MASK                  (0x2000000U)
#define SYSMPU_RGDAAC_M4RE_SHIFT                 (25U)
/*! M4RE - Bus Master 4 Read Enable
 *  0b0..Bus master 4 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 4 reads allowed
 */
#define SYSMPU_RGDAAC_M4RE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M4RE_SHIFT)) & SYSMPU_RGDAAC_M4RE_MASK)

#define SYSMPU_RGDAAC_M5WE_MASK                  (0x4000000U)
#define SYSMPU_RGDAAC_M5WE_SHIFT                 (26U)
/*! M5WE - Bus Master 5 Write Enable
 *  0b0..Bus master 5 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 5 writes allowed
 */
#define SYSMPU_RGDAAC_M5WE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M5WE_SHIFT)) & SYSMPU_RGDAAC_M5WE_MASK)

#define SYSMPU_RGDAAC_M5RE_MASK                  (0x8000000U)
#define SYSMPU_RGDAAC_M5RE_SHIFT                 (27U)
/*! M5RE - Bus Master 5 Read Enable
 *  0b0..Bus master 5 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 5 reads allowed
 */
#define SYSMPU_RGDAAC_M5RE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M5RE_SHIFT)) & SYSMPU_RGDAAC_M5RE_MASK)

#define SYSMPU_RGDAAC_M6WE_MASK                  (0x10000000U)
#define SYSMPU_RGDAAC_M6WE_SHIFT                 (28U)
/*! M6WE - Bus Master 6 Write Enable
 *  0b0..Bus master 6 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 6 writes allowed
 */
#define SYSMPU_RGDAAC_M6WE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M6WE_SHIFT)) & SYSMPU_RGDAAC_M6WE_MASK)

#define SYSMPU_RGDAAC_M6RE_MASK                  (0x20000000U)
#define SYSMPU_RGDAAC_M6RE_SHIFT                 (29U)
/*! M6RE - Bus Master 6 Read Enable
 *  0b0..Bus master 6 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 6 reads allowed
 */
#define SYSMPU_RGDAAC_M6RE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M6RE_SHIFT)) & SYSMPU_RGDAAC_M6RE_MASK)

#define SYSMPU_RGDAAC_M7WE_MASK                  (0x40000000U)
#define SYSMPU_RGDAAC_M7WE_SHIFT                 (30U)
/*! M7WE - Bus Master 7 Write Enable
 *  0b0..Bus master 7 writes terminate with an access error and the write is not performed
 *  0b1..Bus master 7 writes allowed
 */
#define SYSMPU_RGDAAC_M7WE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M7WE_SHIFT)) & SYSMPU_RGDAAC_M7WE_MASK)

#define SYSMPU_RGDAAC_M7RE_MASK                  (0x80000000U)
#define SYSMPU_RGDAAC_M7RE_SHIFT                 (31U)
/*! M7RE - Bus Master 7 Read Enable
 *  0b0..Bus master 7 reads terminate with an access error and the read is not performed
 *  0b1..Bus master 7 reads allowed
 */
#define SYSMPU_RGDAAC_M7RE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M7RE_SHIFT)) & SYSMPU_RGDAAC_M7RE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SYSMPU_Register_Masks */

/* Backward compatibility for SYSMPU */
#define SYSMPU_CESR_SPERR_MASK                   (0xF8000000U)
#define SYSMPU_CESR_SPERR_SHIFT                  SYSMPU_CESR_SPERR4_SHIFT
/*! SPERR - Slave Port n Error
 *  0b0000..No error has occurred for slave port n.
 *  0b0001..An error has occurred for slave port n.
 */
#define SYSMPU_CESR_SPERR(x)                     (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR_SHIFT)) & SYSMPU_CESR_SPERR_MASK)


/*!
 * @}
 */ /* end of group SYSMPU_Peripheral_Access_Layer */


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


#endif  /* PERI_SYSMPU_H_ */

