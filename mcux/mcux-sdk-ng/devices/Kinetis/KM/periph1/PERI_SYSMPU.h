/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_SYSMPU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for SYSMPU
 *
 * CMSIS Peripheral Access Layer for SYSMPU
 */

#if !defined(PERI_SYSMPU_H_)
#define PERI_SYSMPU_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
   -- SYSMPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSMPU_Peripheral_Access_Layer SYSMPU Peripheral Access Layer
 * @{
 */

/** SYSMPU - Size of Registers Arrays */
#define SYSMPU_SP_COUNT                           2u
#define SYSMPU_RGD_COUNT                          8u
#define SYSMPU_RGD_WORD_COUNT                     4u
#define SYSMPU_RGDAAC_COUNT                       8u

/** SYSMPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CESR;                              /**< Control/Error Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __I  uint32_t EAR;                               /**< Error Address Register, slave port n, array offset: 0x10, array step: 0x8 */
    __I  uint32_t EDR;                               /**< Error Detail Register, slave port n, array offset: 0x14, array step: 0x8 */
  } SP[SYSMPU_SP_COUNT];
       uint8_t RESERVED_1[992];
  __IO uint32_t WORD[SYSMPU_RGD_COUNT][SYSMPU_RGD_WORD_COUNT]; /**< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
       uint8_t RESERVED_2[896];
  __IO uint32_t RGDAAC[SYSMPU_RGDAAC_COUNT];       /**< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
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

#define SYSMPU_CESR_SPERR_MASK                   (0xC0000000U)
#define SYSMPU_CESR_SPERR_SHIFT                  (30U)
/*! SPERR - Slave Port n Error
 *  0b00..No error has occurred for slave port n.
 *  0b01..An error has occurred for slave port n.
 */
#define SYSMPU_CESR_SPERR(x)                     (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_SPERR_SHIFT)) & SYSMPU_CESR_SPERR_MASK)
/*! @} */

/*! @name EAR - Error Address Register, slave port n */
/*! @{ */

#define SYSMPU_EAR_EADDR_MASK                    (0xFFFFFFFFU)
#define SYSMPU_EAR_EADDR_SHIFT                   (0U)
/*! EADDR - Error Address */
#define SYSMPU_EAR_EADDR(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_EAR_EADDR_SHIFT)) & SYSMPU_EAR_EADDR_MASK)
/*! @} */

/* The count of SYSMPU_EAR */
#define SYSMPU_EAR_COUNT                         (2U)

/*! @name EDR - Error Detail Register, slave port n */
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
#define SYSMPU_EDR_COUNT                         (2U)

/*! @name WORD - Region Descriptor n, Word 0..Region Descriptor n, Word 3 */
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
/*! M0SM - Bus Master 0 Supervisor Mode Access Control */
#define SYSMPU_WORD_M0SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0SM_SHIFT)) & SYSMPU_WORD_M0SM_MASK)

#define SYSMPU_WORD_ENDADDR_MASK                 (0xFFFFFFE0U)
#define SYSMPU_WORD_ENDADDR_SHIFT                (5U)
/*! ENDADDR - End Address */
#define SYSMPU_WORD_ENDADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_ENDADDR_SHIFT)) & SYSMPU_WORD_ENDADDR_MASK)

#define SYSMPU_WORD_M0PE_MASK                    (0x20U)
#define SYSMPU_WORD_M0PE_SHIFT                   (5U)
/*! M0PE - Bus Master 0 Process Identifier enable */
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
/*! M1SM - Bus Master 1 Supervisor Mode Access Control */
#define SYSMPU_WORD_M1SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1SM_SHIFT)) & SYSMPU_WORD_M1SM_MASK)

#define SYSMPU_WORD_M1PE_MASK                    (0x800U)
#define SYSMPU_WORD_M1PE_SHIFT                   (11U)
/*! M1PE - Bus Master 1 Process Identifier enable */
#define SYSMPU_WORD_M1PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1PE_SHIFT)) & SYSMPU_WORD_M1PE_MASK)

#define SYSMPU_WORD_M2UM_MASK                    (0x7000U)
#define SYSMPU_WORD_M2UM_SHIFT                   (12U)
/*! M2UM - Bus Master 2 User Mode Access control */
#define SYSMPU_WORD_M2UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2UM_SHIFT)) & SYSMPU_WORD_M2UM_MASK)

#define SYSMPU_WORD_M2SM_MASK                    (0x18000U)
#define SYSMPU_WORD_M2SM_SHIFT                   (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control */
#define SYSMPU_WORD_M2SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2SM_SHIFT)) & SYSMPU_WORD_M2SM_MASK)

#define SYSMPU_WORD_PIDMASK_MASK                 (0xFF0000U)
#define SYSMPU_WORD_PIDMASK_SHIFT                (16U)
/*! PIDMASK - Process Identifier Mask */
#define SYSMPU_WORD_PIDMASK(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_PIDMASK_SHIFT)) & SYSMPU_WORD_PIDMASK_MASK)

#define SYSMPU_WORD_M2PE_MASK                    (0x20000U)
#define SYSMPU_WORD_M2PE_SHIFT                   (17U)
/*! M2PE - Bus Master 2 Process Identifier Enable */
#define SYSMPU_WORD_M2PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2PE_SHIFT)) & SYSMPU_WORD_M2PE_MASK)

#define SYSMPU_WORD_M3UM_MASK                    (0x1C0000U)
#define SYSMPU_WORD_M3UM_SHIFT                   (18U)
/*! M3UM - Bus Master 3 User Mode Access Control
 *  0b000..An attempted access of that mode may be terminated with an access error (if not allowed by another descriptor) and the access not performed.
 *  0b001..Allows the given access type to occur
 */
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

#define SYSMPU_WORD_M3PE_MASK                    (0x800000U)
#define SYSMPU_WORD_M3PE_SHIFT                   (23U)
/*! M3PE - Bus Master 3 Process Identifier Enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn_WORD3) in the region hit evaluation
 */
#define SYSMPU_WORD_M3PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M3PE_SHIFT)) & SYSMPU_WORD_M3PE_MASK)

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
#define SYSMPU_WORD_COUNT                        (8U)

/* The count of SYSMPU_WORD */
#define SYSMPU_WORD_COUNT2                       (4U)

/*! @name RGDAAC - Region Descriptor Alternate Access Control n */
/*! @{ */

#define SYSMPU_RGDAAC_M0UM_MASK                  (0x7U)
#define SYSMPU_RGDAAC_M0UM_SHIFT                 (0U)
/*! M0UM - Bus Master 0 User Mode Access Control */
#define SYSMPU_RGDAAC_M0UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0UM_SHIFT)) & SYSMPU_RGDAAC_M0UM_MASK)

#define SYSMPU_RGDAAC_M0SM_MASK                  (0x18U)
#define SYSMPU_RGDAAC_M0SM_SHIFT                 (3U)
/*! M0SM - Bus Master 0 Supervisor Mode Access Control */
#define SYSMPU_RGDAAC_M0SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0SM_SHIFT)) & SYSMPU_RGDAAC_M0SM_MASK)

#define SYSMPU_RGDAAC_M0PE_MASK                  (0x20U)
#define SYSMPU_RGDAAC_M0PE_SHIFT                 (5U)
/*! M0PE - Bus Master 0 Process Identifier Enable */
#define SYSMPU_RGDAAC_M0PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0PE_SHIFT)) & SYSMPU_RGDAAC_M0PE_MASK)

#define SYSMPU_RGDAAC_M1UM_MASK                  (0x1C0U)
#define SYSMPU_RGDAAC_M1UM_SHIFT                 (6U)
/*! M1UM - Bus Master 1 User Mode Access Control */
#define SYSMPU_RGDAAC_M1UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1UM_SHIFT)) & SYSMPU_RGDAAC_M1UM_MASK)

#define SYSMPU_RGDAAC_M1SM_MASK                  (0x600U)
#define SYSMPU_RGDAAC_M1SM_SHIFT                 (9U)
/*! M1SM - Bus Master 1 Supervisor Mode Access Control */
#define SYSMPU_RGDAAC_M1SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1SM_SHIFT)) & SYSMPU_RGDAAC_M1SM_MASK)

#define SYSMPU_RGDAAC_M1PE_MASK                  (0x800U)
#define SYSMPU_RGDAAC_M1PE_SHIFT                 (11U)
/*! M1PE - Bus Master 1 Process Identifier Enable */
#define SYSMPU_RGDAAC_M1PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1PE_SHIFT)) & SYSMPU_RGDAAC_M1PE_MASK)

#define SYSMPU_RGDAAC_M2UM_MASK                  (0x7000U)
#define SYSMPU_RGDAAC_M2UM_SHIFT                 (12U)
/*! M2UM - Bus Master 2 User Mode Access Control */
#define SYSMPU_RGDAAC_M2UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2UM_SHIFT)) & SYSMPU_RGDAAC_M2UM_MASK)

#define SYSMPU_RGDAAC_M2SM_MASK                  (0x18000U)
#define SYSMPU_RGDAAC_M2SM_SHIFT                 (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control */
#define SYSMPU_RGDAAC_M2SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2SM_SHIFT)) & SYSMPU_RGDAAC_M2SM_MASK)

#define SYSMPU_RGDAAC_M2PE_MASK                  (0x20000U)
#define SYSMPU_RGDAAC_M2PE_SHIFT                 (17U)
/*! M2PE - Bus Master 2 Process Identifier Enable */
#define SYSMPU_RGDAAC_M2PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2PE_SHIFT)) & SYSMPU_RGDAAC_M2PE_MASK)

#define SYSMPU_RGDAAC_M3UM_MASK                  (0x1C0000U)
#define SYSMPU_RGDAAC_M3UM_SHIFT                 (18U)
/*! M3UM - Bus Master 3 User Mode Access Control
 *  0b000..An attempted access of that mode may be terminated with an access error (if not allowed by another descriptor) and the access not performed.
 *  0b001..Allows the given access type to occur
 */
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

#define SYSMPU_RGDAAC_M3PE_MASK                  (0x800000U)
#define SYSMPU_RGDAAC_M3PE_SHIFT                 (23U)
/*! M3PE - Bus Master 3 Process Identifier Enable
 *  0b0..Do not include the process identifier in the evaluation
 *  0b1..Include the process identifier and mask (RGDn.RGDAAC) in the region hit evaluation
 */
#define SYSMPU_RGDAAC_M3PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M3PE_SHIFT)) & SYSMPU_RGDAAC_M3PE_MASK)

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


#endif  /* PERI_SYSMPU_H_ */

