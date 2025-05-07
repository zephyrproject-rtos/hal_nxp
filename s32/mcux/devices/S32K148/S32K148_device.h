/*
 * Copyright 2023-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _S32K148_DEVICE_H_
#define _S32K148_DEVICE_H_

/* ----------------------------------------------------------------------------
   -- SYSMPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SYSMPU_Peripheral_Access_Layer SYSMPU Peripheral Access Layer
 * @{
 */

/** SYSMPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t CESR;                              /**< Control/Error Status Register, offset: 0x0 */
       uint8_t RESERVED_0[12];
  struct {                                         /* offset: 0x10, array step: 0x8 */
    __I  uint32_t EAR;                               /**< Error Address Register, slave port n, array offset: 0x10, array step: 0x8 */
    __I  uint32_t EDR;                               /**< Error Detail Register, slave port n, array offset: 0x14, array step: 0x8 */
  } SP[5];
       uint8_t RESERVED_1[968];
  __IO uint32_t WORD[16][4];                        /**< Region Descriptor n, Word 0..Region Descriptor n, Word 3, array offset: 0x400, array step: index*0x10, index2*0x4 */
       uint8_t RESERVED_2[768];
  __IO uint32_t RGDAAC[16];                         /**< Region Descriptor Alternate Access Control n, array offset: 0x800, array step: 0x4 */
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
/*! NSP - Number Of Slave Ports
 */
#define SYSMPU_CESR_NSP(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_CESR_NSP_SHIFT)) & SYSMPU_CESR_NSP_MASK)

#define SYSMPU_CESR_HRL_MASK                     (0xF0000U)
#define SYSMPU_CESR_HRL_SHIFT                    (16U)
/*! HRL - Hardware Revision Level
 */
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
/*! EADDR - Error Address
 */
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
/*! EMN - Error Master Number
 */
#define SYSMPU_EDR_EMN(x)                        (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EMN_SHIFT)) & SYSMPU_EDR_EMN_MASK)

#define SYSMPU_EDR_EPID_MASK                     (0xFF00U)
#define SYSMPU_EDR_EPID_SHIFT                    (8U)
/*! EPID - Error Process Identification
 */
#define SYSMPU_EDR_EPID(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EPID_SHIFT)) & SYSMPU_EDR_EPID_MASK)

#define SYSMPU_EDR_EACD_MASK                     (0xFFFF0000U)
#define SYSMPU_EDR_EACD_SHIFT                    (16U)
/*! EACD - Error Access Control Detail
 */
#define SYSMPU_EDR_EACD(x)                       (((uint32_t)(((uint32_t)(x)) << SYSMPU_EDR_EACD_SHIFT)) & SYSMPU_EDR_EACD_MASK)
/*! @} */

/* The count of SYSMPU_EDR */
#define SYSMPU_EDR_COUNT                         (2U)

/*! @name WORD - Region Descriptor n, Word 0..Region Descriptor n, Word 3 */
/*! @{ */

#define SYSMPU_WORD_M0UM_MASK                    (0x7U)
#define SYSMPU_WORD_M0UM_SHIFT                   (0U)
/*! M0UM - Bus Master 0 User Mode Access Control
 */
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
 */
#define SYSMPU_WORD_M0SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0SM_SHIFT)) & SYSMPU_WORD_M0SM_MASK)

#define SYSMPU_WORD_ENDADDR_MASK                 (0xFFFFFFE0U)
#define SYSMPU_WORD_ENDADDR_SHIFT                (5U)
/*! ENDADDR - End Address
 */
#define SYSMPU_WORD_ENDADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_ENDADDR_SHIFT)) & SYSMPU_WORD_ENDADDR_MASK)

#define SYSMPU_WORD_M0PE_MASK                    (0x20U)
#define SYSMPU_WORD_M0PE_SHIFT                   (5U)
/*! M0PE - Bus Master 0 Process Identifier enable
 */
#define SYSMPU_WORD_M0PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M0PE_SHIFT)) & SYSMPU_WORD_M0PE_MASK)

#define SYSMPU_WORD_SRTADDR_MASK                 (0xFFFFFFE0U)
#define SYSMPU_WORD_SRTADDR_SHIFT                (5U)
/*! SRTADDR - Start Address
 */
#define SYSMPU_WORD_SRTADDR(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_SRTADDR_SHIFT)) & SYSMPU_WORD_SRTADDR_MASK)

#define SYSMPU_WORD_M1UM_MASK                    (0x1C0U)
#define SYSMPU_WORD_M1UM_SHIFT                   (6U)
/*! M1UM - Bus Master 1 User Mode Access Control
 */
#define SYSMPU_WORD_M1UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1UM_SHIFT)) & SYSMPU_WORD_M1UM_MASK)

#define SYSMPU_WORD_M1SM_MASK                    (0x600U)
#define SYSMPU_WORD_M1SM_SHIFT                   (9U)
/*! M1SM - Bus Master 1 Supervisor Mode Access Control
 */
#define SYSMPU_WORD_M1SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1SM_SHIFT)) & SYSMPU_WORD_M1SM_MASK)

#define SYSMPU_WORD_M1PE_MASK                    (0x800U)
#define SYSMPU_WORD_M1PE_SHIFT                   (11U)
/*! M1PE - Bus Master 1 Process Identifier enable
 */
#define SYSMPU_WORD_M1PE(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M1PE_SHIFT)) & SYSMPU_WORD_M1PE_MASK)

#define SYSMPU_WORD_M2UM_MASK                    (0x7000U)
#define SYSMPU_WORD_M2UM_SHIFT                   (12U)
/*! M2UM - Bus Master 2 User Mode Access control
 */
#define SYSMPU_WORD_M2UM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2UM_SHIFT)) & SYSMPU_WORD_M2UM_MASK)

#define SYSMPU_WORD_M2SM_MASK                    (0x18000U)
#define SYSMPU_WORD_M2SM_SHIFT                   (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control
 */
#define SYSMPU_WORD_M2SM(x)                      (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_M2SM_SHIFT)) & SYSMPU_WORD_M2SM_MASK)

#define SYSMPU_WORD_PIDMASK_MASK                 (0xFF0000U)
#define SYSMPU_WORD_PIDMASK_SHIFT                (16U)
/*! PIDMASK - Process Identifier Mask
 */
#define SYSMPU_WORD_PIDMASK(x)                   (((uint32_t)(((uint32_t)(x)) << SYSMPU_WORD_PIDMASK_SHIFT)) & SYSMPU_WORD_PIDMASK_MASK)

#define SYSMPU_WORD_M2PE_MASK                    (0x20000U)
#define SYSMPU_WORD_M2PE_SHIFT                   (17U)
/*! M2PE - Bus Master 2 Process Identifier Enable
 */
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
/*! PID - Process Identifier
 */
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
/*! M0UM - Bus Master 0 User Mode Access Control
 */
#define SYSMPU_RGDAAC_M0UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0UM_SHIFT)) & SYSMPU_RGDAAC_M0UM_MASK)

#define SYSMPU_RGDAAC_M0SM_MASK                  (0x18U)
#define SYSMPU_RGDAAC_M0SM_SHIFT                 (3U)
/*! M0SM - Bus Master 0 Supervisor Mode Access Control
 */
#define SYSMPU_RGDAAC_M0SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0SM_SHIFT)) & SYSMPU_RGDAAC_M0SM_MASK)

#define SYSMPU_RGDAAC_M0PE_MASK                  (0x20U)
#define SYSMPU_RGDAAC_M0PE_SHIFT                 (5U)
/*! M0PE - Bus Master 0 Process Identifier Enable
 */
#define SYSMPU_RGDAAC_M0PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M0PE_SHIFT)) & SYSMPU_RGDAAC_M0PE_MASK)

#define SYSMPU_RGDAAC_M1UM_MASK                  (0x1C0U)
#define SYSMPU_RGDAAC_M1UM_SHIFT                 (6U)
/*! M1UM - Bus Master 1 User Mode Access Control
 */
#define SYSMPU_RGDAAC_M1UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1UM_SHIFT)) & SYSMPU_RGDAAC_M1UM_MASK)

#define SYSMPU_RGDAAC_M1SM_MASK                  (0x600U)
#define SYSMPU_RGDAAC_M1SM_SHIFT                 (9U)
/*! M1SM - Bus Master 1 Supervisor Mode Access Control
 */
#define SYSMPU_RGDAAC_M1SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1SM_SHIFT)) & SYSMPU_RGDAAC_M1SM_MASK)

#define SYSMPU_RGDAAC_M1PE_MASK                  (0x800U)
#define SYSMPU_RGDAAC_M1PE_SHIFT                 (11U)
/*! M1PE - Bus Master 1 Process Identifier Enable
 */
#define SYSMPU_RGDAAC_M1PE(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M1PE_SHIFT)) & SYSMPU_RGDAAC_M1PE_MASK)

#define SYSMPU_RGDAAC_M2UM_MASK                  (0x7000U)
#define SYSMPU_RGDAAC_M2UM_SHIFT                 (12U)
/*! M2UM - Bus Master 2 User Mode Access Control
 */
#define SYSMPU_RGDAAC_M2UM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2UM_SHIFT)) & SYSMPU_RGDAAC_M2UM_MASK)

#define SYSMPU_RGDAAC_M2SM_MASK                  (0x18000U)
#define SYSMPU_RGDAAC_M2SM_SHIFT                 (15U)
/*! M2SM - Bus Master 2 Supervisor Mode Access Control
 */
#define SYSMPU_RGDAAC_M2SM(x)                    (((uint32_t)(((uint32_t)(x)) << SYSMPU_RGDAAC_M2SM_SHIFT)) & SYSMPU_RGDAAC_M2SM_MASK)

#define SYSMPU_RGDAAC_M2PE_MASK                  (0x20000U)
#define SYSMPU_RGDAAC_M2PE_SHIFT                 (17U)
/*! M2PE - Bus Master 2 Process Identifier Enable
 */
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

/* The count of SYSMPU_RGDAAC */
#define SYSMPU_RGDAAC_COUNT                      (8U)


/*!
 * @}
 */ /* end of group SYSMPU_Register_Masks */


/* SYSMPU - Peripheral instance base addresses */
/** Peripheral SYSMPU base address */
#define SYSMPU_BASE                              (0x4000D000u)
/** Peripheral SYSMPU base pointer */
#define SYSMPU                                   ((SYSMPU_Type *)SYSMPU_BASE)
/** Array initializer of SYSMPU peripheral base addresses */
#define SYSMPU_BASE_ADDRS                        { SYSMPU_BASE }
/** Array initializer of SYSMPU peripheral base pointers */
#define SYSMPU_BASE_PTRS                         { SYSMPU }

/*!
 * @}
 */ /* end of group SYSMPU_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define MSCM_BASE                                IP_MSCM_BASE
/** Peripheral MSCM base pointer */
#define MSCM                                     IP_MSCM
/** Array initializer of MSCM peripheral base addresses */
#define MSCM_BASE_ADDRS                          IP_MSCM_BASE_ADDRS
/** Array initializer of MSCM peripheral base pointers */
#define MSCM_BASE_PTRS                           IP_MSCM_BASE_PTRS

/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPUART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPUART_Peripheral_Access_Layer LPUART Peripheral Access Layer
 * @{
 */

/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             IP_LPUART0_BASE
/** Peripheral LPUART0 base pointer */
#define LPUART0                                  IP_LPUART0
/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             IP_LPUART1_BASE
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  IP_LPUART1
/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             IP_LPUART2_BASE
/** Peripheral LPUART2 base pointer */
#define LPUART2                                  IP_LPUART2
/** Array initializer of LPUART peripheral base addresses */
#define LPUART_BASE_ADDRS                        IP_LPUART_BASE_ADDRS
/** Array initializer of LPUART peripheral base pointers */
#define LPUART_BASE_PTRS                         IP_LPUART_BASE_PTRS
/** Interrupt vectors for the LPUART peripheral type */
#define LPUART_RX_TX_IRQS                        { LPUART0_RxTx_IRQn, LPUART1_RxTx_IRQn, LPUART2_RxTx_IRQn }
#define LPUART_ERR_IRQS                          { LPUART0_RxTx_IRQn, LPUART1_RxTx_IRQn, LPUART2_RxTx_IRQn }

/*!
 * @}
 */ /* end of group LPUART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              IP_LPI2C0_BASE
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   IP_LPI2C0
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              IP_LPI2C1_BASE
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   IP_LPI2C1
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         IP_LPI2C_BASE_ADDRS
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          IP_LPI2C_BASE_PTRS
/** Interrupt vectors for the LPI2C peripheral type */
#define LPI2C_IRQS                               { LPI2C0_Master_IRQn, LPI2C1_Master_IRQn }

/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LPSPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPSPI_Peripheral_Access_Layer LPSPI Peripheral Access Layer
 * @{
 */

/* LPSPI - Peripheral instance base addresses */
/** Peripheral LPSPI0 base address */
#define LPSPI0_BASE                              IP_LPSPI0_BASE
/** Peripheral LPSPI0 base pointer */
#define LPSPI0                                   IP_LPSPI0
/** Peripheral LPSPI1 base address */
#define LPSPI1_BASE                              IP_LPSPI1_BASE
/** Peripheral LPSPI1 base pointer */
#define LPSPI1                                   IP_LPSPI1
/** Peripheral LPSPI2 base address */
#define LPSPI2_BASE                              IP_LPSPI2_BASE
/** Peripheral LPSPI2 base pointer */
#define LPSPI2                                   IP_LPSPI2
/** Array initializer of LPSPI peripheral base addresses */
#define LPSPI_BASE_ADDRS                         IP_LPSPI_BASE_ADDRS
/** Array initializer of LPSPI peripheral base pointers */
#define LPSPI_BASE_PTRS                          IP_LPSPI_BASE_PTRS
/** Interrupt vectors for the LPSPI peripheral type */
#define LPSPI_IRQS                               { LPSPI0_IRQn, LPSPI1_IRQn, LPSPI2_IRQn }

/*!
 * @}
 */ /* end of group LPSPI_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- LMEM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LMEM_Peripheral_Access_Layer LMEM Peripheral Access Layer
 * @{
 */

/*!
 * @addtogroup LMEM_Register_Masks LMEM Register Masks
 * @{
 */

/*! @name PCCCR - Cache control register */
/*! @{ */

/* ENWRBUF - Enable Write Buffer is not available on this SoC */
#define LMEM_PCCCR_ENWRBUF_MASK                  (0U)
#define LMEM_PCCCR_ENWRBUF_SHIFT                 (0U)
#define LMEM_PCCCR_ENWRBUF(x)                    (((uint32_t)(((uint32_t)(x)) << LMEM_PCCCR_ENWRBUF_SHIFT)) & LMEM_PCCCR_ENWRBUF_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LMEM_Register_Masks */

/* LMEM - Peripheral instance base addresses */
/** Peripheral LMEM base address */
#define LMEM_BASE                                IP_LMEM_BASE
/** Peripheral LMEM base pointer */
#define LMEM                                     IP_LMEM
/** Array initializer of LMEM peripheral base addresses */
#define LMEM_BASE_ADDRS                          IP_LMEM_BASE_ADDRS
/** Array initializer of LMEM peripheral base pointers */
#define LMEM_BASE_PTRS                           IP_LMEM_BASE_PTRS

/*!
 * @}
 */ /* end of group LMEM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */

/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                IP_FTM0_BASE
/** Peripheral FTM0 base pointer */
#define FTM0                                     IP_FTM0
/** Peripheral FTM1 base address */
#define FTM1_BASE                                IP_FTM1_BASE
/** Peripheral FTM1 base pointer */
#define FTM1                                     IP_FTM1
/** Peripheral FTM2 base address */
#define FTM2_BASE                                IP_FTM2_BASE
/** Peripheral FTM2 base pointer */
#define FTM2                                     IP_FTM2
/** Peripheral FTM3 base address */
#define FTM3_BASE                                IP_FTM3_BASE
/** Peripheral FTM3 base pointer */
#define FTM3                                     IP_FTM3
/** Peripheral FTM4 base address */
#define FTM4_BASE                                IP_FTM4_BASE
/** Peripheral FTM4 base pointer */
#define FTM4                                     IP_FTM4
/** Peripheral FTM5 base address */
#define FTM5_BASE                                IP_FTM5_BASE
/** Peripheral FTM5 base pointer */
#define FTM5                                     IP_FTM5
/** Peripheral FTM6 base address */
#define FTM6_BASE                                IP_FTM6_BASE
/** Peripheral FTM6 base pointer */
#define FTM6                                     IP_FTM6
/** Peripheral FTM7 base address */
#define FTM7_BASE                                IP_FTM7_BASE
/** Peripheral FTM7 base pointer */
#define FTM7                                     IP_FTM7
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           IP_FTM_BASE_ADDRS
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            IP_FTM_BASE_PTRS

/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/* CAN - Peripheral instance base addresses */
/** Peripheral CAN_0 base address */
#define CAN0_BASE                                IP_FLEXCAN0_BASE
/** Peripheral CAN_0 base pointer */
#define CAN0                                     IP_FLEXCAN0
/** Peripheral CAN_1 base address */
#define CAN1_BASE                                IP_FLEXCAN1_BASE
/** Peripheral CAN_1 base pointer */
#define CAN1                                     IP_FLEXCAN1
/** Peripheral CAN_2 base address */
#define CAN2_BASE                                IP_FLEXCAN2_BASE
/** Peripheral CAN_2 base pointer */
#define CAN2                                     IP_FLEXCAN2
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           IP_FLEXCAN_BASE_ADDRS
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            IP_FLEXCAN_BASE_PTRS
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_Wake_Up_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define CAN_Error_IRQS                           { CAN0_Error_IRQn, CAN1_Error_IRQn, CAN2_Error_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_ORed_Message_buffer_0_15_IRQS        { CAN0_ORed_0_15_MB_IRQn, CAN1_ORed_0_15_MB_IRQn, CAN2_ORed_0_15_MB_IRQn }
#define CAN_ORed_Message_buffer_16_31_IRQS       { CAN0_ORed_16_31_MB_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }

/*!
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

 /* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                IP_WDOG_BASE
/** Peripheral WDOG base pointer */
#define WDOG                                     IP_WDOG
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          IP_WDOG_BASE_ADDRS
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           IP_WDOG_BASE_PTRS
/** Interrupt vectors for the WDOG peripheral type */
#define WDOG_IRQS                                { WDOG_EWM_IRQn }
#define WDOG_UPDATE_KEY                          (0xD928C520U)
#define WDOG_REFRESH_KEY                         (0xB480A602U)

/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 IP_RTC_BASE
/** Peripheral RTC base pointer */
#define RTC                                      IP_RTC
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           IP_RTC_BASE_ADDRS
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            IP_RTC_BASE_PTRS
/** Interrupt vectors for the RTC peripheral type */
#define RTC_IRQS                                 { RTC_IRQn }
#define RTC_SECONDS_IRQS                         { RTC_Seconds_IRQn }

/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                IP_ADC0_BASE
/** Peripheral ADC0 base pointer */
#define ADC0                                     IP_ADC0
/** Peripheral ADC1 base address */
#define ADC1_BASE                                IP_ADC1_BASE
/** Peripheral ADC1 base pointer */
#define ADC1                                     IP_ADC1
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           IP_ADC_BASE_ADDRS
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            IP_ADC_BASE_PTRS
/** Interrupt vectors for the ADC peripheral type */
#define ADC_IRQS                                 { ADC0_IRQn, ADC1_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */

#endif /* _S32K148_DEVICE_H_ */
