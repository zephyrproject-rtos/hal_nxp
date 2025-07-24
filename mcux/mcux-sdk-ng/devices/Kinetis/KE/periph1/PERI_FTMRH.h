/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for FTMRH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_FTMRH.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for FTMRH
 *
 * CMSIS Peripheral Access Layer for FTMRH
 */

#if !defined(PERI_FTMRH_H_)
#define PERI_FTMRH_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
   -- FTMRH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Peripheral_Access_Layer FTMRH Peripheral Access Layer
 * @{
 */

/** FTMRH - Register Layout Typedef */
typedef struct {
  __IO uint8_t FCLKDIV;                            /**< Flash Clock Divider Register, offset: 0x0 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x1 */
  __IO uint8_t FCCOBIX;                            /**< Flash CCOB Index Register, offset: 0x2 */
       uint8_t RESERVED_0[1];
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x4 */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x5 */
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x6 */
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x7 */
  __IO uint8_t FPROT;                              /**< Flash Protection Register, offset: 0x8 */
  __IO uint8_t EEPROT;                             /**< EEPROM Protection Register, offset: 0x9 */
  __IO uint8_t FCCOBHI;                            /**< Flash Common Command Object Register:High, offset: 0xA */
  __IO uint8_t FCCOBLO;                            /**< Flash Common Command Object Register: Low, offset: 0xB */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0xC */
} FTMRH_Type;

/* ----------------------------------------------------------------------------
   -- FTMRH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Register_Masks FTMRH Register Masks
 * @{
 */

/*! @name FCLKDIV - Flash Clock Divider Register */
/*! @{ */

#define FTMRH_FCLKDIV_FDIV_MASK                  (0x3FU)
#define FTMRH_FCLKDIV_FDIV_SHIFT                 (0U)
/*! FDIV - Clock Divider Bits */
#define FTMRH_FCLKDIV_FDIV(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FCLKDIV_FDIV_SHIFT)) & FTMRH_FCLKDIV_FDIV_MASK)

#define FTMRH_FCLKDIV_FDIVLCK_MASK               (0x40U)
#define FTMRH_FCLKDIV_FDIVLCK_SHIFT              (6U)
/*! FDIVLCK - Clock Divider Locked
 *  0b0..FDIV field is open for writing.
 *  0b1..FDIV value is locked and cannot be changed. After the lock bit is set high, only reset can clear this bit
 *       and restore writability to the FDIV field in user mode.
 */
#define FTMRH_FCLKDIV_FDIVLCK(x)                 (((uint8_t)(((uint8_t)(x)) << FTMRH_FCLKDIV_FDIVLCK_SHIFT)) & FTMRH_FCLKDIV_FDIVLCK_MASK)

#define FTMRH_FCLKDIV_FDIVLD_MASK                (0x80U)
#define FTMRH_FCLKDIV_FDIVLD_SHIFT               (7U)
/*! FDIVLD - Clock Divider Loaded
 *  0b0..FCLKDIV register has not been written since the last reset.
 *  0b1..FCLKDIV register has been written since the last reset.
 */
#define FTMRH_FCLKDIV_FDIVLD(x)                  (((uint8_t)(((uint8_t)(x)) << FTMRH_FCLKDIV_FDIVLD_SHIFT)) & FTMRH_FCLKDIV_FDIVLD_MASK)
/*! @} */

/*! @name FSEC - Flash Security Register */
/*! @{ */

#define FTMRH_FSEC_SEC_MASK                      (0x3U)
#define FTMRH_FSEC_SEC_SHIFT                     (0U)
/*! SEC - Flash Security Bits
 *  0b00..Secured
 *  0b01..Secured
 *  0b10..Unsecured
 *  0b11..Secured
 */
#define FTMRH_FSEC_SEC(x)                        (((uint8_t)(((uint8_t)(x)) << FTMRH_FSEC_SEC_SHIFT)) & FTMRH_FSEC_SEC_MASK)

#define FTMRH_FSEC_KEYEN_MASK                    (0xC0U)
#define FTMRH_FSEC_KEYEN_SHIFT                   (6U)
/*! KEYEN - Backdoor Key Security Enable Bits
 *  0b00..Disabled
 *  0b01..Disabled
 *  0b10..Enabled
 *  0b11..Disabled
 */
#define FTMRH_FSEC_KEYEN(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FSEC_KEYEN_SHIFT)) & FTMRH_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FCCOBIX - Flash CCOB Index Register */
/*! @{ */

#define FTMRH_FCCOBIX_CCOBIX_MASK                (0x7U)
#define FTMRH_FCCOBIX_CCOBIX_SHIFT               (0U)
/*! CCOBIX - Common Command Register Index */
#define FTMRH_FCCOBIX_CCOBIX(x)                  (((uint8_t)(((uint8_t)(x)) << FTMRH_FCCOBIX_CCOBIX_SHIFT)) & FTMRH_FCCOBIX_CCOBIX_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTMRH_FCNFG_FSFD_MASK                    (0x1U)
#define FTMRH_FCNFG_FSFD_SHIFT                   (0U)
/*! FSFD - Force Single Bit Fault Detect
 *  0b0..Flash array read operations will set the SFDIF flag in the FERSTAT register only if a single bit fault is detected.
 *  0b1..Flash array read operation will force the SFDIF flag in the FERSTAT register to be set and an interrupt
 *       will be generated as long as FERCNFG[SFDIE] is set.
 */
#define FTMRH_FCNFG_FSFD(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FCNFG_FSFD_SHIFT)) & FTMRH_FCNFG_FSFD_MASK)

#define FTMRH_FCNFG_FDFD_MASK                    (0x2U)
#define FTMRH_FCNFG_FDFD_SHIFT                   (1U)
/*! FDFD - Force Double Bit Fault Detect
 *  0b0..Flash array read operations will set the FERSTAT[DFDIF] flag only if a double bit fault is detected.
 *  0b1..Any flash array read operation will force the FERSTAT[DFDIF] flag to be set and an interrupt will be
 *       generated as long as FERCNFG[DFDIE] is set.
 */
#define FTMRH_FCNFG_FDFD(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FCNFG_FDFD_SHIFT)) & FTMRH_FCNFG_FDFD_MASK)

#define FTMRH_FCNFG_IGNSF_MASK                   (0x10U)
#define FTMRH_FCNFG_IGNSF_SHIFT                  (4U)
/*! IGNSF - Ignore Single Bit Fault
 *  0b0..All single-bit faults detected during array reads are reported.
 *  0b1..Single-bit faults detected during array reads are not reported and the single bit fault interrupt will not be generated.
 */
#define FTMRH_FCNFG_IGNSF(x)                     (((uint8_t)(((uint8_t)(x)) << FTMRH_FCNFG_IGNSF_SHIFT)) & FTMRH_FCNFG_IGNSF_MASK)

#define FTMRH_FCNFG_CCIE_MASK                    (0x80U)
#define FTMRH_FCNFG_CCIE_SHIFT                   (7U)
/*! CCIE - Command Complete Interrupt Enable
 *  0b0..Command complete interrupt is disabled.
 *  0b1..An interrupt will be requested whenever the CCIF flag in the FSTAT register is set.
 */
#define FTMRH_FCNFG_CCIE(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FCNFG_CCIE_SHIFT)) & FTMRH_FCNFG_CCIE_MASK)
/*! @} */

/*! @name FERCNFG - Flash Error Configuration Register */
/*! @{ */

#define FTMRH_FERCNFG_SFDIE_MASK                 (0x1U)
#define FTMRH_FERCNFG_SFDIE_SHIFT                (0U)
/*! SFDIE - Single Bit Fault Detect Interrupt Enable
 *  0b0..SFDIF interrupt is disabled whenever the SFDIF flag is set.
 *  0b1..An interrupt will be requested whenever the SFDIF flag is set.
 */
#define FTMRH_FERCNFG_SFDIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTMRH_FERCNFG_SFDIE_SHIFT)) & FTMRH_FERCNFG_SFDIE_MASK)

#define FTMRH_FERCNFG_DFDIE_MASK                 (0x2U)
#define FTMRH_FERCNFG_DFDIE_SHIFT                (1U)
/*! DFDIE - Double Bit Fault Detect Interrupt Enable
 *  0b0..DFDIF interrupt is disabled.
 *  0b1..An interrupt will be requested whenever the DFDIF flag is set.
 */
#define FTMRH_FERCNFG_DFDIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTMRH_FERCNFG_DFDIE_SHIFT)) & FTMRH_FERCNFG_DFDIE_MASK)
/*! @} */

/*! @name FSTAT - Flash Status Register */
/*! @{ */

#define FTMRH_FSTAT_MGSTAT_MASK                  (0x3U)
#define FTMRH_FSTAT_MGSTAT_SHIFT                 (0U)
/*! MGSTAT - Memory Controller Command Completion Status Flag */
#define FTMRH_FSTAT_MGSTAT(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FSTAT_MGSTAT_SHIFT)) & FTMRH_FSTAT_MGSTAT_MASK)

#define FTMRH_FSTAT_MGBUSY_MASK                  (0x8U)
#define FTMRH_FSTAT_MGBUSY_SHIFT                 (3U)
/*! MGBUSY - Memory Controller Busy Flag
 *  0b0..Memory controller is idle.
 *  0b1..Memory controller is busy executing a flash command (CCIF = 0).
 */
#define FTMRH_FSTAT_MGBUSY(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FSTAT_MGBUSY_SHIFT)) & FTMRH_FSTAT_MGBUSY_MASK)

#define FTMRH_FSTAT_FPVIOL_MASK                  (0x10U)
#define FTMRH_FSTAT_FPVIOL_SHIFT                 (4U)
/*! FPVIOL - Flash Protection Violation Flag
 *  0b0..No protection violation is detected.
 *  0b1..Protection violation is detected.
 */
#define FTMRH_FSTAT_FPVIOL(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FSTAT_FPVIOL_SHIFT)) & FTMRH_FSTAT_FPVIOL_MASK)

#define FTMRH_FSTAT_ACCERR_MASK                  (0x20U)
#define FTMRH_FSTAT_ACCERR_SHIFT                 (5U)
/*! ACCERR - Flash Access Error Flag
 *  0b0..No access error is detected.
 *  0b1..Access error is detected.
 */
#define FTMRH_FSTAT_ACCERR(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FSTAT_ACCERR_SHIFT)) & FTMRH_FSTAT_ACCERR_MASK)

#define FTMRH_FSTAT_CCIF_MASK                    (0x80U)
#define FTMRH_FSTAT_CCIF_SHIFT                   (7U)
/*! CCIF - Command Complete Interrupt Flag
 *  0b0..Flash command is in progress.
 *  0b1..Flash command has completed.
 */
#define FTMRH_FSTAT_CCIF(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FSTAT_CCIF_SHIFT)) & FTMRH_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FERSTAT - Flash Error Status Register */
/*! @{ */

#define FTMRH_FERSTAT_SFDIF_MASK                 (0x1U)
#define FTMRH_FERSTAT_SFDIF_SHIFT                (0U)
/*! SFDIF - Single Bit Fault Detect Interrupt Flag
 *  0b0..No single bit fault detected.
 *  0b1..Single bit fault detected and corrected or a flash array read operation returning invalid data was attempted while command running.
 */
#define FTMRH_FERSTAT_SFDIF(x)                   (((uint8_t)(((uint8_t)(x)) << FTMRH_FERSTAT_SFDIF_SHIFT)) & FTMRH_FERSTAT_SFDIF_MASK)

#define FTMRH_FERSTAT_DFDIF_MASK                 (0x2U)
#define FTMRH_FERSTAT_DFDIF_SHIFT                (1U)
/*! DFDIF - Double Bit Fault Detect Interrupt Flag
 *  0b0..No double bit fault detected.
 *  0b1..Double bit fault detected or a flash array read operation returning invalid data was attempted while command running.
 */
#define FTMRH_FERSTAT_DFDIF(x)                   (((uint8_t)(((uint8_t)(x)) << FTMRH_FERSTAT_DFDIF_SHIFT)) & FTMRH_FERSTAT_DFDIF_MASK)
/*! @} */

/*! @name FPROT - Flash Protection Register */
/*! @{ */

#define FTMRH_FPROT_FPLS_MASK                    (0x3U)
#define FTMRH_FPROT_FPLS_SHIFT                   (0U)
/*! FPLS - Flash Protection Lower Address Size */
#define FTMRH_FPROT_FPLS(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_FPLS_SHIFT)) & FTMRH_FPROT_FPLS_MASK)

#define FTMRH_FPROT_FPLDIS_MASK                  (0x4U)
#define FTMRH_FPROT_FPLDIS_SHIFT                 (2U)
/*! FPLDIS - Flash Protection Lower Address Range Disable
 *  0b0..Protection/Unprotection enabled.
 *  0b1..Protection/Unprotection disabled.
 */
#define FTMRH_FPROT_FPLDIS(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_FPLDIS_SHIFT)) & FTMRH_FPROT_FPLDIS_MASK)

#define FTMRH_FPROT_FPHS_MASK                    (0x18U)
#define FTMRH_FPROT_FPHS_SHIFT                   (3U)
/*! FPHS - Flash Protection Higher Address Size */
#define FTMRH_FPROT_FPHS(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_FPHS_SHIFT)) & FTMRH_FPROT_FPHS_MASK)

#define FTMRH_FPROT_FPHDIS_MASK                  (0x20U)
#define FTMRH_FPROT_FPHDIS_SHIFT                 (5U)
/*! FPHDIS - Flash Protection Higher Address Range Disable
 *  0b0..Protection/Unprotection enabled.
 *  0b1..Protection/Unprotection disabled.
 */
#define FTMRH_FPROT_FPHDIS(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_FPHDIS_SHIFT)) & FTMRH_FPROT_FPHDIS_MASK)

#define FTMRH_FPROT_RNV6_MASK                    (0x40U)
#define FTMRH_FPROT_RNV6_SHIFT                   (6U)
/*! RNV6 - Reserved Nonvolatile Bit */
#define FTMRH_FPROT_RNV6(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_RNV6_SHIFT)) & FTMRH_FPROT_RNV6_MASK)

#define FTMRH_FPROT_FPOPEN_MASK                  (0x80U)
#define FTMRH_FPROT_FPOPEN_SHIFT                 (7U)
/*! FPOPEN - Flash Protection Operation Enable
 *  0b0..When FPOPEN is clear, the FPHDIS and FPLDIS fields define unprotected address ranges as specified by the corresponding FPHS and FPLS fields.
 *  0b1..When FPOPEN is set, the FPHDIS and FPLDIS fields enable protection for the address range specified by the
 *       corresponding FPHS and FPLS fields.
 */
#define FTMRH_FPROT_FPOPEN(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FPROT_FPOPEN_SHIFT)) & FTMRH_FPROT_FPOPEN_MASK)
/*! @} */

/*! @name EEPROT - EEPROM Protection Register */
/*! @{ */

#define FTMRH_EEPROT_DPS_MASK                    (0x7U)
#define FTMRH_EEPROT_DPS_SHIFT                   (0U)
/*! DPS - EEPROM Protection Size */
#define FTMRH_EEPROT_DPS(x)                      (((uint8_t)(((uint8_t)(x)) << FTMRH_EEPROT_DPS_SHIFT)) & FTMRH_EEPROT_DPS_MASK)

#define FTMRH_EEPROT_DPOPEN_MASK                 (0x80U)
#define FTMRH_EEPROT_DPOPEN_SHIFT                (7U)
/*! DPOPEN - EEPROM Protection Control
 *  0b0..Enables EEPROM memory protection from program and erase with protected address range defined by DPS bits.
 *  0b1..Disables EEPROM memory protection from program and erase.
 */
#define FTMRH_EEPROT_DPOPEN(x)                   (((uint8_t)(((uint8_t)(x)) << FTMRH_EEPROT_DPOPEN_SHIFT)) & FTMRH_EEPROT_DPOPEN_MASK)
/*! @} */

/*! @name FCCOBHI - Flash Common Command Object Register:High */
/*! @{ */

#define FTMRH_FCCOBHI_CCOB_MASK                  (0xFFU)
#define FTMRH_FCCOBHI_CCOB_SHIFT                 (0U)
/*! CCOB - Common Command Object Bit 15:8 */
#define FTMRH_FCCOBHI_CCOB(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FCCOBHI_CCOB_SHIFT)) & FTMRH_FCCOBHI_CCOB_MASK)
/*! @} */

/*! @name FCCOBLO - Flash Common Command Object Register: Low */
/*! @{ */

#define FTMRH_FCCOBLO_CCOB_MASK                  (0xFFU)
#define FTMRH_FCCOBLO_CCOB_SHIFT                 (0U)
/*! CCOB - Common Command Object Bit 7:0 */
#define FTMRH_FCCOBLO_CCOB(x)                    (((uint8_t)(((uint8_t)(x)) << FTMRH_FCCOBLO_CCOB_SHIFT)) & FTMRH_FCCOBLO_CCOB_MASK)
/*! @} */

/*! @name FOPT - Flash Option Register */
/*! @{ */

#define FTMRH_FOPT_NV_MASK                       (0xFFU)
#define FTMRH_FOPT_NV_SHIFT                      (0U)
/*! NV - Nonvolatile Bits */
#define FTMRH_FOPT_NV(x)                         (((uint8_t)(((uint8_t)(x)) << FTMRH_FOPT_NV_SHIFT)) & FTMRH_FOPT_NV_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group FTMRH_Register_Masks */


/*!
 * @}
 */ /* end of group FTMRH_Peripheral_Access_Layer */


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


#endif  /* PERI_FTMRH_H_ */

