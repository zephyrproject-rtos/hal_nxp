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
**         CMSIS Peripheral Access Layer for PFLASH
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
 * @file PERI_PFLASH.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for PFLASH
 *
 * CMSIS Peripheral Access Layer for PFLASH
 */

#if !defined(PERI_PFLASH_H_)
#define PERI_PFLASH_H_                           /**< Symbol preventing repeated inclusion */

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
   -- PFLASH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PFLASH_Peripheral_Access_Layer PFLASH Peripheral Access Layer
 * @{
 */

/** PFLASH - Size of Registers Arrays */
#define PFLASH_PFCRI_COUNT                        3u
#define PFLASH_PFCBLKI_SPELOCK_COUNT              3u
#define PFLASH_U_PFCBLKI_SPELOCK_COUNT            1u
#define PFLASH_PFCBLKI_SSPELOCK_COUNT             2u
#define PFLASH_PFCBLKI_SETSLOCK_COUNT             3u
#define PFLASH_U_PFCBLKI_SETSLOCK_COUNT           1u
#define PFLASH_PFCBLKI_SSETSLOCK_COUNT            2u
#define PFLASH_PFCBLKI_LOCKMASTER_S_COUNT         3u
#define PFLASH_PFCBLKI_LOCKMASTER_S_PFCBLKI_LOCKMASTER_SJ_COUNT 8u
#define PFLASH_U_PFCBLKI_LOCKMASTER_S_COUNT       1u
#define PFLASH_PFCBLKI_LOCKMASTER_SS_PFCBLKI_LOCKMASTER_SSJ_COUNT 1u
#define PFLASH_PFCBLKI_LOCKMASTER_SS_COUNT        2u

/** PFLASH - Register Layout Typedef */
typedef struct {
  __IO uint32_t PFCR[PFLASH_PFCRI_COUNT];          /**< Platform Flash Memory Configuration 0..Platform Flash Memory Configuration 2, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[4];
  __IO uint32_t PFCR4;                             /**< Platform Flash Memory Configuration 4, offset: 0x10 */
  __IO uint32_t PFAPR;                             /**< Platform Flash Memory Access Protection, offset: 0x14 */
       uint8_t RESERVED_1[744];
  __IO uint32_t PFCPGM_PEADR_L;                    /**< Platform Flash Memory Program Erase Address Logical, offset: 0x300 */
  __I  uint32_t PFCPGM_PEADR_P;                    /**< Platform Flash Memory Program Erase Address Physical, offset: 0x304 */
  __IO uint32_t PFCPGM_XPEADR_L;                   /**< Platform Flash Memory Express Program Erase Address Logical, offset: 0x308 */
  __I  uint32_t PFCPGM_XPEADR_P;                   /**< Platform Flash Memory Express Program Erase Address Physical, offset: 0x30C */
       uint8_t RESERVED_2[48];
  __IO uint32_t PFCBLK_SPELOCK[PFLASH_PFCBLKI_SPELOCK_COUNT]; /**< Block n Sector Program Erase Lock, array offset: 0x340, array step: 0x4 */
       uint8_t RESERVED_3[12];
  __IO uint32_t PFCBLKU_SPELOCK[PFLASH_U_PFCBLKI_SPELOCK_COUNT]; /**< Block UTEST Sector Program Erase Lock, array offset: 0x358, array step: 0x4 */
  __IO uint32_t PFCBLK_SSPELOCK[PFLASH_PFCBLKI_SSPELOCK_COUNT]; /**< Block n Super Sector Program Erase Lock, array offset: 0x35C, array step: 0x4 */
       uint8_t RESERVED_4[28];
  __IO uint32_t PFCBLK_SETSLOCK[PFLASH_PFCBLKI_SETSLOCK_COUNT]; /**< Block n Set Sector Lock, array offset: 0x380, array step: 0x4 */
       uint8_t RESERVED_5[12];
  __IO uint32_t PFCBLKU_SETSLOCK[PFLASH_U_PFCBLKI_SETSLOCK_COUNT]; /**< Block UTEST Set Sector Lock, array offset: 0x398, array step: 0x4 */
  __IO uint32_t PFCBLK_SSETSLOCK[PFLASH_PFCBLKI_SSETSLOCK_COUNT]; /**< Block n Set Super Sector Lock, array offset: 0x39C, array step: 0x4 */
       uint8_t RESERVED_6[28];
  __I  uint32_t PFCBLK_LOCKMASTER_S[PFLASH_PFCBLKI_LOCKMASTER_S_COUNT][PFLASH_PFCBLKI_LOCKMASTER_S_PFCBLKI_LOCKMASTER_SJ_COUNT]; /**< Block a Lock Master Sector b, array offset: 0x3C0, array step: index*0x20, index2*0x4 */
       uint8_t RESERVED_7[96];
  __I  uint32_t PFCBLKU_LOCKMASTER_S[PFLASH_U_PFCBLKI_LOCKMASTER_S_COUNT]; /**< Block UTEST Lock Master Sector, array offset: 0x480, array step: 0x4 */
  struct {                                         /* offset: 0x484, array step: 0x10 */
    __I  uint32_t PFCBLK_LOCKMASTER_SS[PFLASH_PFCBLKI_LOCKMASTER_SS_PFCBLKI_LOCKMASTER_SSJ_COUNT];   /**< Block m Lock Master Super Sector n, array offset: 0x484, array step: index*0x10, index2*0x4 */
         uint8_t RESERVED_0[12];
  } PFCBLKI_LOCKMASTER_SS[PFLASH_PFCBLKI_LOCKMASTER_SS_COUNT];
} PFLASH_Type;

/* ----------------------------------------------------------------------------
   -- PFLASH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PFLASH_Register_Masks PFLASH Register Masks
 * @{
 */

/*! @name PFCR - Platform Flash Memory Configuration 0..Platform Flash Memory Configuration 2 */
/*! @{ */

#define PFLASH_PFCR_P0_CBFEN_MASK                (0x1U)
#define PFLASH_PFCR_P0_CBFEN_SHIFT               (0U)
/*! P0_CBFEN - Port0 PFLASH Line Read Code Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P0_CBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P0_CBFEN_SHIFT)) & PFLASH_PFCR_P0_CBFEN_MASK)

#define PFLASH_PFCR_P1_CBFEN_MASK                (0x1U)
#define PFLASH_PFCR_P1_CBFEN_SHIFT               (0U)
/*! P1_CBFEN - Port1 PFLASH Line Read Code Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P1_CBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P1_CBFEN_SHIFT)) & PFLASH_PFCR_P1_CBFEN_MASK)

#define PFLASH_PFCR_P2_CBFEN_MASK                (0x1U)
#define PFLASH_PFCR_P2_CBFEN_SHIFT               (0U)
/*! P2_CBFEN - Port2 PFLASH Line Read Code Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P2_CBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P2_CBFEN_SHIFT)) & PFLASH_PFCR_P2_CBFEN_MASK)

#define PFLASH_PFCR_P0_DBFEN_MASK                (0x2U)
#define PFLASH_PFCR_P0_DBFEN_SHIFT               (1U)
/*! P0_DBFEN - Port0 PFLASH Line Read Data Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P0_DBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P0_DBFEN_SHIFT)) & PFLASH_PFCR_P0_DBFEN_MASK)

#define PFLASH_PFCR_P1_DBFEN_MASK                (0x2U)
#define PFLASH_PFCR_P1_DBFEN_SHIFT               (1U)
/*! P1_DBFEN - Port1 PFLASH Line Read Data Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P1_DBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P1_DBFEN_SHIFT)) & PFLASH_PFCR_P1_DBFEN_MASK)

#define PFLASH_PFCR_P2_DBFEN_MASK                (0x2U)
#define PFLASH_PFCR_P2_DBFEN_SHIFT               (1U)
/*! P2_DBFEN - Port2 PFLASH Line Read Data Buffers Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P2_DBFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P2_DBFEN_SHIFT)) & PFLASH_PFCR_P2_DBFEN_MASK)

#define PFLASH_PFCR_P0_CPFEN_MASK                (0x10U)
#define PFLASH_PFCR_P0_CPFEN_SHIFT               (4U)
/*! P0_CPFEN - Port0 Code Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P0_CPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P0_CPFEN_SHIFT)) & PFLASH_PFCR_P0_CPFEN_MASK)

#define PFLASH_PFCR_P1_CPFEN_MASK                (0x10U)
#define PFLASH_PFCR_P1_CPFEN_SHIFT               (4U)
/*! P1_CPFEN - Port1 Code Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P1_CPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P1_CPFEN_SHIFT)) & PFLASH_PFCR_P1_CPFEN_MASK)

#define PFLASH_PFCR_P2_CPFEN_MASK                (0x10U)
#define PFLASH_PFCR_P2_CPFEN_SHIFT               (4U)
/*! P2_CPFEN - Port2 Code Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P2_CPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P2_CPFEN_SHIFT)) & PFLASH_PFCR_P2_CPFEN_MASK)

#define PFLASH_PFCR_P0_DPFEN_MASK                (0x20U)
#define PFLASH_PFCR_P0_DPFEN_SHIFT               (5U)
/*! P0_DPFEN - Port0 Data Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P0_DPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P0_DPFEN_SHIFT)) & PFLASH_PFCR_P0_DPFEN_MASK)

#define PFLASH_PFCR_P1_DPFEN_MASK                (0x20U)
#define PFLASH_PFCR_P1_DPFEN_SHIFT               (5U)
/*! P1_DPFEN - Port1 Data Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P1_DPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P1_DPFEN_SHIFT)) & PFLASH_PFCR_P1_DPFEN_MASK)

#define PFLASH_PFCR_P2_DPFEN_MASK                (0x20U)
#define PFLASH_PFCR_P2_DPFEN_SHIFT               (5U)
/*! P2_DPFEN - Port2 Data Prefetch Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PFLASH_PFCR_P2_DPFEN(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR_P2_DPFEN_SHIFT)) & PFLASH_PFCR_P2_DPFEN_MASK)
/*! @} */

/* The count of PFLASH_PFCR */
#define PFLASH_PFCR_COUNT                        (3U)

/*! @name PFCR4 - Platform Flash Memory Configuration 4 */
/*! @{ */

#define PFLASH_PFCR4_BLK4_PS_MASK                (0xEU)
#define PFLASH_PFCR4_BLK4_PS_SHIFT               (1U)
/*! BLK4_PS - Block 4 Pipe Select
 *  0b000..Block 4 access is always through pipe0
 *  0b001..Block 4 access is always through pipe1
 *  0b010..Block 4 access is always through pipe2
 *  0b011..Block 4 access is always through pipe3
 *  0b1xx..Block 4 access can be through any of the command pipes, based on which command pipe is available for block 4 access
 */
#define PFLASH_PFCR4_BLK4_PS(x)                  (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR4_BLK4_PS_SHIFT)) & PFLASH_PFCR4_BLK4_PS_MASK)

#define PFLASH_PFCR4_DMEEE_MASK                  (0x80U)
#define PFLASH_PFCR4_DMEEE_SHIFT                 (7U)
/*! DMEEE - Disable Multi-Bit ECC Error Exception
 *  0b0..Error response sent on system bus for multi-bit ECC error
 *  0b1..Error response not sent on system bus for multi-bit ECC error
 */
#define PFLASH_PFCR4_DMEEE(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCR4_DMEEE_SHIFT)) & PFLASH_PFCR4_DMEEE_MASK)
/*! @} */

/*! @name PFAPR - Platform Flash Memory Access Protection */
/*! @{ */

#define PFLASH_PFAPR_M15AP_MASK                  (0x3U)
#define PFLASH_PFAPR_M15AP_SHIFT                 (0U)
/*! M15AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M15AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M15AP_SHIFT)) & PFLASH_PFAPR_M15AP_MASK)

#define PFLASH_PFAPR_M14AP_MASK                  (0xCU)
#define PFLASH_PFAPR_M14AP_SHIFT                 (2U)
/*! M14AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M14AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M14AP_SHIFT)) & PFLASH_PFAPR_M14AP_MASK)

#define PFLASH_PFAPR_M13AP_MASK                  (0x30U)
#define PFLASH_PFAPR_M13AP_SHIFT                 (4U)
/*! M13AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M13AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M13AP_SHIFT)) & PFLASH_PFAPR_M13AP_MASK)

#define PFLASH_PFAPR_M12AP_MASK                  (0xC0U)
#define PFLASH_PFAPR_M12AP_SHIFT                 (6U)
/*! M12AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M12AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M12AP_SHIFT)) & PFLASH_PFAPR_M12AP_MASK)

#define PFLASH_PFAPR_M11AP_MASK                  (0x300U)
#define PFLASH_PFAPR_M11AP_SHIFT                 (8U)
/*! M11AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M11AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M11AP_SHIFT)) & PFLASH_PFAPR_M11AP_MASK)

#define PFLASH_PFAPR_M10AP_MASK                  (0xC00U)
#define PFLASH_PFAPR_M10AP_SHIFT                 (10U)
/*! M10AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M10AP(x)                    (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M10AP_SHIFT)) & PFLASH_PFAPR_M10AP_MASK)

#define PFLASH_PFAPR_M9AP_MASK                   (0x3000U)
#define PFLASH_PFAPR_M9AP_SHIFT                  (12U)
/*! M9AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M9AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M9AP_SHIFT)) & PFLASH_PFAPR_M9AP_MASK)

#define PFLASH_PFAPR_M8AP_MASK                   (0xC000U)
#define PFLASH_PFAPR_M8AP_SHIFT                  (14U)
/*! M8AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M8AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M8AP_SHIFT)) & PFLASH_PFAPR_M8AP_MASK)

#define PFLASH_PFAPR_M7AP_MASK                   (0x30000U)
#define PFLASH_PFAPR_M7AP_SHIFT                  (16U)
/*! M7AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M7AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M7AP_SHIFT)) & PFLASH_PFAPR_M7AP_MASK)

#define PFLASH_PFAPR_M6AP_MASK                   (0xC0000U)
#define PFLASH_PFAPR_M6AP_SHIFT                  (18U)
/*! M6AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M6AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M6AP_SHIFT)) & PFLASH_PFAPR_M6AP_MASK)

#define PFLASH_PFAPR_M5AP_MASK                   (0x300000U)
#define PFLASH_PFAPR_M5AP_SHIFT                  (20U)
/*! M5AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M5AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M5AP_SHIFT)) & PFLASH_PFAPR_M5AP_MASK)

#define PFLASH_PFAPR_M4AP_MASK                   (0xC00000U)
#define PFLASH_PFAPR_M4AP_SHIFT                  (22U)
/*! M4AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M4AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M4AP_SHIFT)) & PFLASH_PFAPR_M4AP_MASK)

#define PFLASH_PFAPR_M2AP_MASK                   (0xC000000U)
#define PFLASH_PFAPR_M2AP_SHIFT                  (26U)
/*! M2AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M2AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M2AP_SHIFT)) & PFLASH_PFAPR_M2AP_MASK)

#define PFLASH_PFAPR_M1AP_MASK                   (0x30000000U)
#define PFLASH_PFAPR_M1AP_SHIFT                  (28U)
/*! M1AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M1AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M1AP_SHIFT)) & PFLASH_PFAPR_M1AP_MASK)

#define PFLASH_PFAPR_M0AP_MASK                   (0xC0000000U)
#define PFLASH_PFAPR_M0AP_SHIFT                  (30U)
/*! M0AP - Master n Access Protection
 *  0bx0..This master cannot perform any read accesses
 *  0bx1..This master can perform read accesses
 */
#define PFLASH_PFAPR_M0AP(x)                     (((uint32_t)(((uint32_t)(x)) << PFLASH_PFAPR_M0AP_SHIFT)) & PFLASH_PFAPR_M0AP_MASK)
/*! @} */

/*! @name PFCPGM_PEADR_L - Platform Flash Memory Program Erase Address Logical */
/*! @{ */

#define PFLASH_PFCPGM_PEADR_L_PEADR_L_MASK       (0xFFFFFFFFU)
#define PFLASH_PFCPGM_PEADR_L_PEADR_L_SHIFT      (0U)
/*! PEADR_L - Program Erase Address Logical */
#define PFLASH_PFCPGM_PEADR_L_PEADR_L(x)         (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCPGM_PEADR_L_PEADR_L_SHIFT)) & PFLASH_PFCPGM_PEADR_L_PEADR_L_MASK)
/*! @} */

/*! @name PFCPGM_PEADR_P - Platform Flash Memory Program Erase Address Physical */
/*! @{ */

#define PFLASH_PFCPGM_PEADR_P_PEADR_P_MASK       (0xFFFFFFFFU)
#define PFLASH_PFCPGM_PEADR_P_PEADR_P_SHIFT      (0U)
/*! PEADR_P - Program Erase Address Physical */
#define PFLASH_PFCPGM_PEADR_P_PEADR_P(x)         (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCPGM_PEADR_P_PEADR_P_SHIFT)) & PFLASH_PFCPGM_PEADR_P_PEADR_P_MASK)
/*! @} */

/*! @name PFCPGM_XPEADR_L - Platform Flash Memory Express Program Erase Address Logical */
/*! @{ */

#define PFLASH_PFCPGM_XPEADR_L_XPEADR_L_MASK     (0xFFFFFFFFU)
#define PFLASH_PFCPGM_XPEADR_L_XPEADR_L_SHIFT    (0U)
/*! XPEADR_L - Express Program Erase Address Logical */
#define PFLASH_PFCPGM_XPEADR_L_XPEADR_L(x)       (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCPGM_XPEADR_L_XPEADR_L_SHIFT)) & PFLASH_PFCPGM_XPEADR_L_XPEADR_L_MASK)
/*! @} */

/*! @name PFCPGM_XPEADR_P - Platform Flash Memory Express Program Erase Address Physical */
/*! @{ */

#define PFLASH_PFCPGM_XPEADR_P_XPEADR_P_MASK     (0xFFFFFFFFU)
#define PFLASH_PFCPGM_XPEADR_P_XPEADR_P_SHIFT    (0U)
/*! XPEADR_P - Express Program Erase Address Physical */
#define PFLASH_PFCPGM_XPEADR_P_XPEADR_P(x)       (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCPGM_XPEADR_P_XPEADR_P_SHIFT)) & PFLASH_PFCPGM_XPEADR_P_XPEADR_P_MASK)
/*! @} */

/*! @name PFCBLK_SPELOCK - Block n Sector Program Erase Lock */
/*! @{ */

#define PFLASH_PFCBLK_SPELOCK_SLCK_MASK          (0xFFFFFFFFU)
#define PFLASH_PFCBLK_SPELOCK_SLCK_SHIFT         (0U)
/*! SLCK - Sector Lock */
#define PFLASH_PFCBLK_SPELOCK_SLCK(x)            (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_SPELOCK_SLCK_SHIFT)) & PFLASH_PFCBLK_SPELOCK_SLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_SPELOCK */
#define PFLASH_PFCBLK_SPELOCK_COUNT              (3U)

/*! @name PFCBLKU_SPELOCK - Block UTEST Sector Program Erase Lock */
/*! @{ */

#define PFLASH_PFCBLKU_SPELOCK_SLCK_MASK         (0x1U)
#define PFLASH_PFCBLKU_SPELOCK_SLCK_SHIFT        (0U)
/*! SLCK - Sector Lock */
#define PFLASH_PFCBLKU_SPELOCK_SLCK(x)           (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLKU_SPELOCK_SLCK_SHIFT)) & PFLASH_PFCBLKU_SPELOCK_SLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLKU_SPELOCK */
#define PFLASH_PFCBLKU_SPELOCK_COUNT             (1U)

/*! @name PFCBLK_SSPELOCK - Block n Super Sector Program Erase Lock */
/*! @{ */

#define PFLASH_PFCBLK_SSPELOCK_SSLCK_MASK        (0xFU)
#define PFLASH_PFCBLK_SSPELOCK_SSLCK_SHIFT       (0U)
/*! SSLCK - Super Sector Lock */
#define PFLASH_PFCBLK_SSPELOCK_SSLCK(x)          (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_SSPELOCK_SSLCK_SHIFT)) & PFLASH_PFCBLK_SSPELOCK_SSLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_SSPELOCK */
#define PFLASH_PFCBLK_SSPELOCK_COUNT             (2U)

/*! @name PFCBLK_SETSLOCK - Block n Set Sector Lock */
/*! @{ */

#define PFLASH_PFCBLK_SETSLOCK_SETSLCK_MASK      (0xFFFFFFFFU)
#define PFLASH_PFCBLK_SETSLOCK_SETSLCK_SHIFT     (0U)
#define PFLASH_PFCBLK_SETSLOCK_SETSLCK(x)        (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_SETSLOCK_SETSLCK_SHIFT)) & PFLASH_PFCBLK_SETSLOCK_SETSLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_SETSLOCK */
#define PFLASH_PFCBLK_SETSLOCK_COUNT             (3U)

/*! @name PFCBLKU_SETSLOCK - Block UTEST Set Sector Lock */
/*! @{ */

#define PFLASH_PFCBLKU_SETSLOCK_SETSLCK_MASK     (0x1U)
#define PFLASH_PFCBLKU_SETSLOCK_SETSLCK_SHIFT    (0U)
/*! SETSLCK - Set Sector Lock */
#define PFLASH_PFCBLKU_SETSLOCK_SETSLCK(x)       (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLKU_SETSLOCK_SETSLCK_SHIFT)) & PFLASH_PFCBLKU_SETSLOCK_SETSLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLKU_SETSLOCK */
#define PFLASH_PFCBLKU_SETSLOCK_COUNT            (1U)

/*! @name PFCBLK_SSETSLOCK - Block n Set Super Sector Lock */
/*! @{ */

#define PFLASH_PFCBLK_SSETSLOCK_SSETSLCK_MASK    (0xFU)
#define PFLASH_PFCBLK_SSETSLOCK_SSETSLCK_SHIFT   (0U)
/*! SSETSLCK - Set Super Sector Lock */
#define PFLASH_PFCBLK_SSETSLOCK_SSETSLCK(x)      (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_SSETSLOCK_SSETSLCK_SHIFT)) & PFLASH_PFCBLK_SSETSLOCK_SSETSLCK_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_SSETSLOCK */
#define PFLASH_PFCBLK_SSETSLOCK_COUNT            (2U)

/*! @name PFCBLK_LOCKMASTER_S - Block a Lock Master Sector b */
/*! @{ */

#define PFLASH_PFCBLK_LOCKMASTER_S_LOCKMASTER_S_MASK (0xFFFFFFFFU)
#define PFLASH_PFCBLK_LOCKMASTER_S_LOCKMASTER_S_SHIFT (0U)
/*! LOCKMASTER_S - Block a Lock Master Sector b */
#define PFLASH_PFCBLK_LOCKMASTER_S_LOCKMASTER_S(x) (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_LOCKMASTER_S_LOCKMASTER_S_SHIFT)) & PFLASH_PFCBLK_LOCKMASTER_S_LOCKMASTER_S_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_LOCKMASTER_S */
#define PFLASH_PFCBLK_LOCKMASTER_S_COUNT         (3U)

/* The count of PFLASH_PFCBLK_LOCKMASTER_S */
#define PFLASH_PFCBLK_LOCKMASTER_S_COUNT2        (8U)

/*! @name PFCBLKU_LOCKMASTER_S - Block UTEST Lock Master Sector */
/*! @{ */

#define PFLASH_PFCBLKU_LOCKMASTER_S_LOCKMASTER_S_MASK (0xFFU)
#define PFLASH_PFCBLKU_LOCKMASTER_S_LOCKMASTER_S_SHIFT (0U)
/*! LOCKMASTER_S - Lock Master Sector */
#define PFLASH_PFCBLKU_LOCKMASTER_S_LOCKMASTER_S(x) (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLKU_LOCKMASTER_S_LOCKMASTER_S_SHIFT)) & PFLASH_PFCBLKU_LOCKMASTER_S_LOCKMASTER_S_MASK)
/*! @} */

/* The count of PFLASH_PFCBLKU_LOCKMASTER_S */
#define PFLASH_PFCBLKU_LOCKMASTER_S_COUNT        (1U)

/*! @name PFCBLK_LOCKMASTER_SS - Block m Lock Master Super Sector n */
/*! @{ */

#define PFLASH_PFCBLK_LOCKMASTER_SS_LOCKMASTER_SS_MASK (0xFFFFFFFFU)
#define PFLASH_PFCBLK_LOCKMASTER_SS_LOCKMASTER_SS_SHIFT (0U)
/*! LOCKMASTER_SS - Block a Lock Master Super Sector b */
#define PFLASH_PFCBLK_LOCKMASTER_SS_LOCKMASTER_SS(x) (((uint32_t)(((uint32_t)(x)) << PFLASH_PFCBLK_LOCKMASTER_SS_LOCKMASTER_SS_SHIFT)) & PFLASH_PFCBLK_LOCKMASTER_SS_LOCKMASTER_SS_MASK)
/*! @} */

/* The count of PFLASH_PFCBLK_LOCKMASTER_SS */
#define PFLASH_PFCBLK_LOCKMASTER_SS_COUNT        (2U)

/* The count of PFLASH_PFCBLK_LOCKMASTER_SS */
#define PFLASH_PFCBLK_LOCKMASTER_SS_COUNT2       (1U)


/*!
 * @}
 */ /* end of group PFLASH_Register_Masks */


/*!
 * @}
 */ /* end of group PFLASH_Peripheral_Access_Layer */


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


#endif  /* PERI_PFLASH_H_ */

